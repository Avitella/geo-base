// Copyright (c) 2015 Urtashev Arslan. All rights reserved.
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

#include <geo_base/generator/generator.h>
#include <geo_base/generator/locations_converter.h>

namespace geo_base {
namespace generator {

void generator_t::update(geo_id_t, geo_id_t,
	dynarray_t<point_t> const &, bool)
{
}

static bool is_inner(proto::polygon_t const &p)
{
	return p.type() == proto::polygon_t::TYPE_INNER;
}

void generator_t::update(geo_id_t region_id, proto::polygon_t const &polygon)
{
	locations_converter_t converter(allocator_);
	converter.each(polygon.locations(), [&] (dynarray_t<location_t> const &locations) {
		dynarray_t<point_t> points(locations.size(), allocator_);
		for (location_t const &l : locations)
			points.push_back(point_t(l));
		update(region_id, polygon.polygon_id(), points, is_inner(polygon));
	});
}

void generator_t::update(proto::region_t const &region)
{
	for (proto::polygon_t const &polygon : region.polygons())
		update(region.region_id(), polygon);
}

} // namespace generator
} // namespace geo_base
