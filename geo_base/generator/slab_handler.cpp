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

#include <geo_base/generator/slab_handler.h>
#include <geo_base/generator/gen_geo_data.h>
#include <geo_base/generator/locations_converter.h>
#include <geo_base/generator/common.h>
#include <geo_base/library/stop_watch.h>
#include <geo_base/library/log.h>

namespace geo_base {
namespace generator {

struct check_point_t {
    coordinate_t x;
    number_t idx;
    bool is_start;
};

static dynarray_t<check_point_t> make_check_points(dynarray_t<edge_t> const &e,
    gen_geo_data_t *geo_data, allocator_t *allocator)
{
    dynarray_t<check_point_t> check_points(e.size() * 2, allocator);
    point_t const *p = geo_data->points();

    for (number_t i = 0; i < e.size(); ++i) {
        check_points.push_back(check_point_t{p[e[i].beg].x, i, true});
        check_points.push_back(check_point_t{p[e[i].end].x, i, false});
    }

    std::stable_sort(check_points.begin(), check_points.end(),
        [&] (check_point_t const &a, check_point_t const &b) {
            return a.x < b.x;
        }
    );

    return check_points;
}

void slab_handler_t::update(geo_id_t region_id, geo_id_t polygon_id, dynarray_t<point_t> const &points,
    polygon_t::type_t type)
{
    if (points.size() <= 2) {
        log_warning("Polygon %lu too small (region %lu)", polygon_id, region_id);
        return;
    }

    polygon_t polygon;
    memset(&polygon, 0, sizeof(polygon));

    polygon.region_id = region_id;
    polygon.polygon_id = polygon_id;
    polygon.square = get_square(points);
    polygon.type = type;
    polygon.bbox = bbox_t(points.data(), points.size());
    polygon.points_number = points.size();

    polygon.parts_offset = geo_data_->parts_number();

    dynarray_t<edge_t> const edges = make_edges(points, geo_data_, allocator_);
    dynarray_t<check_point_t> const check_points = make_check_points(edges, geo_data_, allocator_);

    for (number_t l = 0, r = 0; l < check_points.size(); l = r) {
        r = l + 1;
        while (r < check_points.size() && check_points[l].x == check_points[r].x)
            ++r;

        dynarray_t<edge_t> erase(r - l, allocator_);
        for (number_t i = l; i < r; ++i)
            if (!check_points[i].is_start)
                erase.push_back(edges[check_points[i].idx]);

        std::stable_sort(erase.begin(), erase.end());

        part_t part;
        part.edge_refs_offset = geo_data_->edge_refs_number();
        part.coordinate = check_points[l].x;

        if (l > 0) {
            part_t const &prev = *(geo_data_->parts() + geo_data_->parts_number() - 1);
            for (number_t i = prev.edge_refs_offset; i < part.edge_refs_offset; ++i) {
                edge_t const &e = geo_data_->edges()[geo_data_->edge_refs()[i]];
                if (!std::binary_search(erase.begin(), erase.end(), e))
                    geo_data_->edge_refs_append(geo_data_->edge_refs()[i]);
            }
        }

        for (number_t i = l; i < r; ++i)
            if (check_points[i].is_start)
                if (!std::binary_search(erase.begin(), erase.end(), edges[check_points[i].idx]))
                    geo_data_->edge_refs_append(geo_data_->insert(edges[check_points[i].idx]));

        ref_t *mut_edge_refs = geo_data_->mut_edge_refs() + part.edge_refs_offset;
        ref_t *mut_edge_refs_end = geo_data_->mut_edge_refs() + geo_data_->edge_refs_number();

        std::stable_sort(mut_edge_refs, mut_edge_refs_end, [&] (ref_t const &a, ref_t const &b) {
            edge_t const &e1 = geo_data_->edges()[a];
            edge_t const &e2 = geo_data_->edges()[b];
            return e1.lower(e2, geo_data_->points());
        });

        geo_data_->parts_append(part);
    }

    polygon.parts_number = geo_data_->parts_number() - polygon.parts_offset;
    geo_data_->polygons_append(polygon);
}

void slab_handler_t::init()
{
    log_info("Generate polygons...");

    stop_watch_.run();
}

static void sort_polygons(gen_geo_data_t *g)
{
    polygon_t *begin = g->mut_polygons();
    polygon_t *end = begin + g->polygons_number();

    std::stable_sort(begin, end, [] (polygon_t const &a, polygon_t const &b) {
        return a.bbox.x2 < b.bbox.x2;
    });
}

void slab_handler_t::generate_area_boxes()
{
    log_info("Generate area boxes...");

    stop_watch_t stop_watch;
    stop_watch.run();

    sort_polygons(geo_data_);

    std::vector<std::vector<ref_t>> area_boxes(area_box::number);

    std::vector<bbox_t> bboxes;
    bboxes.reserve(area_box::number);

    for (coordinate_t x0 = area_box::lower_x; x0 < area_box::upper_x; x0 += area_box::delta_x)
        for (coordinate_t y0 = area_box::lower_y; y0 < area_box::upper_y; y0 += area_box::delta_y)
            bboxes.emplace_back(x0, y0, x0 + area_box::delta_x, y0 + area_box::delta_y);

    number_t const polygons_number = geo_data_->polygons_number();
    polygon_t const *polygons = geo_data_->polygons();

    for (number_t i = 0; i < polygons_number; ++i) {
        coordinate_t const x1 = polygons[i].bbox.x1;
        coordinate_t const y1 = polygons[i].bbox.y1;
        coordinate_t const x2 = polygons[i].bbox.x2;
        coordinate_t const y2 = polygons[i].bbox.y2;
        for (coordinate_t x0 = x1; x0 <= x2 + area_box::delta_x; x0 += area_box::delta_x) {
            for (coordinate_t y0 = y1; y0 <= y2 + area_box::delta_y; y0 += area_box::delta_y) {
                ref_t const box = lookup_area_box(point_t(x0, y0));
                if (box >= bboxes.size() || box >= area_boxes.size())
                    continue;
                if (polygons[i].bbox.has_intersection(bboxes[box]))
                    area_boxes[box].push_back(i);
            }
        }
    }

    ref_t area_box_ref = 0;
    for (coordinate_t x0 = area_box::lower_x; x0 < area_box::upper_x; x0 += area_box::delta_x) {
        for (coordinate_t y0 = area_box::lower_y; y0 < area_box::upper_y; y0 += area_box::delta_y) {
            area_box_t box;
            box.polygon_refs_offset = geo_data_->polygon_refs_number();

            for (ref_t const i : area_boxes[area_box_ref])
                geo_data_->polygon_refs_append(i);

            box.polygon_refs_number = geo_data_->polygon_refs_number() - box.polygon_refs_offset;

            ref_t *mut_polygon_refs = geo_data_->mut_polygon_refs() + box.polygon_refs_offset;
            ref_t *mut_polygon_refs_end = geo_data_->mut_polygon_refs() + geo_data_->polygon_refs_number();

            std::stable_sort(mut_polygon_refs, mut_polygon_refs_end, [&] (ref_t const &a, ref_t const &b) {
                return polygons[a].region_id < polygons[b].region_id
                    || (polygons[a].region_id == polygons[b].region_id && polygons[a].square < polygons[b].square);
            });

            geo_data_->boxes_append(box);

            ++area_box_ref;
        }
    }

    log_info("Area boxes generated in %.3f seconds", stop_watch.get());
}

// Create fake part for right edge_refs_number calculation.
static void create_fake_part(gen_geo_data_t *geo_data)
{
    part_t fake_part;
    fake_part.coordinate = 0;
    fake_part.edge_refs_offset = geo_data->edge_refs_number();
    geo_data->parts_append(fake_part);
}

void slab_handler_t::fini()
{
    log_info("Polygons generated in %.3f seconds", stop_watch_.get());

    generate_area_boxes();
    create_fake_part(geo_data_);

    geo_data_->set_version(GEO_DATA_CURRENT_VERSION);
}

void slab_handler_t::update(geo_id_t region_id, proto::polygon_t const &polygon)
{
    locations_converter_t converter(allocator_);
    converter.each(polygon.locations(), [&] (dynarray_t<location_t> const &locations) {
        dynarray_t<point_t> points(locations.size(), allocator_);
        for (location_t const &l : locations)
            points.push_back(point_t(l));
        update(region_id, polygon.polygon_id(), points, (polygon_t::type_t) polygon.type());
    });
}

void slab_handler_t::update(proto::region_t const &proto_region)
{
    for (proto::polygon_t const &polygon : proto_region.polygons())
        update(proto_region.region_id(), polygon);
}

} // namespace generator
} // namespace geo_base
