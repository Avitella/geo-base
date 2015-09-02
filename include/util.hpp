#pragma once

#include "common.hpp"
#include "exception.hpp"
#include "io.hpp"
#include "location.hpp"
#include "log.hpp"
#include "stop_watch.hpp"

#include "proto/geo_data.pb.h"

#include <sstream>
#include <string>
#include <functional>
#include <vector>
#include <mutex>

#include <arpa/inet.h>
#include <math.h>

namespace geo_base {

class proto_parser_t {
public:
	explicit proto_parser_t(int fd)
		: fd(fd)
	{
	}

	template<typename callback_t>
	void operator () (callback_t callback)
	{
		proto::geo_data_t geo_data;
		std::vector<char> buffer;

		uint32_t count = 0;
		while (gb_read(fd, (char *) &count, sizeof(count)) != 0) {
			count = ntohl(count);

			buffer.resize(count);
			if (!gb_read(fd, buffer.data(), buffer.size()))
				throw exception_t("%s", "Can't read data");

			if (!geo_data.ParseFromArray(buffer.data(), buffer.size()))
				throw exception_t("%s", "Can't parse geo_data");

			callback(geo_data);
		}
	}

private:
	int fd;
};

class proto_writer_t {
public:
	explicit proto_writer_t(int fd)
		: fd(fd)
	{
	}

	void write(proto::geo_data_t const &geo_data, std::string &buffer)
	{
		buffer.clear();
		geo_data.SerializeToString(&buffer);

		uint32_t count = htonl(static_cast<uint32_t>(buffer.size()));

		std::lock_guard<std::mutex> lock(mutex);

		gb_write(fd, (char const *) &count, sizeof(count));
		gb_write(fd, buffer.data(), buffer.size());
	}

private:
	int fd;
	std::mutex mutex;
};

class polygon_processor_t {
public:
	template<typename callback_t>
	void operator () (std::vector<location_t> const &raw_locations, callback_t callback)
	{
		locations.clear();
		for (location_t const &l : raw_locations) {
			if (locations.empty() || locations.back() != l)
				locations.push_back(l);

			if (locations.size() > 3 && locations.front() == locations.back()) {
				locations.pop_back();
				callback(locations);
				locations.clear();
			}
		}

		if (locations.size() > 2)
			callback(locations);
	}

private:
	std::vector<location_t> locations;
};

}
