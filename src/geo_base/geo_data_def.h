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

#pragma once

#include <geo_base/area_box.h>
#include <geo_base/edge.h>
#include <geo_base/kv.h>
#include <geo_base/part.h>
#include <geo_base/point.h>
#include <geo_base/polygon.h>
#include <geo_base/region.h>
#include <geo_base/typedef.h>
#include <geo_base/util/system.h>

namespace geo_base {

// Geographical data definition. This define need for reflection in map/unmap, show, etc.
#define GEO_BASE_DEF_GEO_DATA \
	GEO_BASE_DEF_VAR(version_t, version); \
	GEO_BASE_DEF_ARR(point_t, points); \
	GEO_BASE_DEF_ARR(edge_t, edges); \
	GEO_BASE_DEF_ARR(ref_t, edge_refs); \
	GEO_BASE_DEF_ARR(part_t, parts); \
	GEO_BASE_DEF_ARR(polygon_t, polygons); \
	GEO_BASE_DEF_ARR(ref_t, polygon_refs); \
	GEO_BASE_DEF_ARR(area_box_t, boxes); \
	GEO_BASE_DEF_ARR(byte_t, blobs); \
	GEO_BASE_DEF_ARR(kv_t, kvs); \
	GEO_BASE_DEF_ARR(region_t, regions);

} // namespace geo_base
