#include "location.h"
#include "log.h"
#include "util.h"

#include <iomanip>
#include <iostream>
#include <unordered_set>

using namespace geo_base;

static output_t &operator << (output_t &out, std::vector<location_t> const &l)
{
	out << '[';
	for (size_t i = 0; i < l.size(); ++i)
		out << '(' << l[i].lat << ' ' << l[i].lon << ')' << (i + 1 == l.size() ? "" : ", ");
	out << ']';
	return out;
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(6);

	if (argc < 2) {
		log_error("geo-txt-grep") << "geo-txt-grep <region_id>";
		return -1;
	}

	std::unordered_set<region_id_t> grep;
	for (int i = 1; i < argc; ++i)
		grep.insert(atoll(argv[i]));

	try {
		std::vector<location_t> locations;
		std::vector<location_t> polygon;

		geo_read_txt(std::cin, [&] (region_id_t region_id, std::vector<location_t> const &raw_locations, std::vector<std::string> const &) {
			if (grep.find(region_id) != grep.end()) {
				process_locations(raw_locations, locations, [&] (std::vector<location_t> const &locations) {
					if (grep.size() != 1)
						std::cout << region_id << " = ";
					std::cout << locations << std::endl;
				});
			}
		});

	} catch (std::exception const &e) {
		log_error("geo-txt-grep", "EXCEPTION") << e.what();
	}

	return 0;
}
