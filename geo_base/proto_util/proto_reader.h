// Copyright (c) 2016 Urtashev Arslan. All rights reserved.
// Contacts: <urtashev@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in all copies or
//   substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <arpa/inet.h>
#include <geo_base/proto/region.pb.h>
#include <geo_base/typedef.h>
#include <geo_base/util/allocator.h>
#include <geo_base/util/mem_file.h>
#include <unordered_map>

namespace geo_base {

class proto_reader_t {
public:
	proto_reader_t(char const *path)
		: mem_file_()
		, index_()
	{
		mem_file_.read_open(path);
	}

	template<typename callback_t>
	void each_region(callback_t callback)
	{
		each_with_ptr([&] (char const *, proto::region_t const &region) {
			callback(region);
		});
	}

	template<typename callback_t>
	void each_polygon(callback_t callback)
	{
		each_region([&] (proto::region_t const &region) {
			for (proto::polygon_t const &polygon : region.polygons())
				callback(polygon);
		});
	}

	template<typename callback_t>
	bool each_polygon(geo_id_t geo_id, callback_t callback)
	{
		bool const ret = call(geo_id, [&] (proto::region_t const &region) {
			for (proto::polygon_t const &polygon : region.polygons())
				callback(polygon);
		});
		return ret;
	}

	template<typename callback_t>
	bool call(geo_id_t geo_id, callback_t callback)
	{
		if (index_.empty())
			generate_index();

		if (index_.find(geo_id)	== index_.end())
			return false;

		char const *ptr = index_[geo_id];
		size_t const byte_size = ntohl(*((uint32_t *) ptr));

		proto::region_t region;
		if (!region.ParseFromArray(ptr + sizeof(byte_size), byte_size))
			throw exception_t("Unable parse region from array");

		callback(region);
	}

private:
	void generate_index();

	template<typename callback_t>
	void each_with_ptr(callback_t callback)
	{
		char const *begin = (char const *) mem_file_.data();
		char const *end = begin + mem_file_.size();

		char const *ptr = begin;
		proto::region_t region;

		while (ptr < end) {
			uint32_t const byte_size = ntohl(*((uint32_t *) ptr));
			if (!region.ParseFromArray(ptr + sizeof(byte_size), byte_size))
				throw exception_t("Unable parse region from array");
			callback(ptr, (proto::region_t const &) region);
			ptr += byte_size + sizeof(byte_size);
		}
	}

	mem_file_t mem_file_;
	std::unordered_map<geo_id_t, char const *> index_;
};

} // namespace geo_base