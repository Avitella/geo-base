# Status
[![Build Status](https://travis-ci.org/Avitella/geo-base.png)](https://travis-ci.org/Avitella/geo-base)

# Reverse geocoding library

GeoBase is a immutable storage of geographical data (data generated by
GeoBaseGenerate and stored on disk in special format).
GeoBase uses memory mapping of data file for fast initialization and
optimal using of RAM. You do not pay for geographical polygons that are
not requested.

## Quick start

```c++
#include <exception>
#include <iostream>

#include <geo_base/geo_base.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "USAGE: quick-start <geodata.dat>";
    return -1;
  }

  geo_base::GeoBasePtr geo_base = NULL;
  try {
    geo_base = geo_base::GeoBasePtr(new geo_base::GeoBase(argv[1]));
  } catch (const std::exception& e) {
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
    return -1;
  }

  geo_base::Location location;
  while (std::cin >> location) {
    geo_base::RegionID region_id = geo_base->Lookup(location);
    if (region_id != geo_base::kUnknownRegionID) {
      std::cerr << region_id << std::endl;
    } else {
      std::cerr << -1 << std::endl;
    }
  }

  return 0;
}
```

## Benchmark

With touch memory before benchmark:

	99.29% <= 46µs
	99.98% <= 101µs
	99.99% <= 146µs
	100.00% <= 283µs

## License

	Copyright (c) 2015 Urtashev Arslan. All rights reserved.
	Contacts: <urtashev@gmail.com>
	
	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:
	
	  The above copyright notice and this permission notice shall be included
	  in all copies or substantial portions of the Software.
	          
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
	CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
	TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
