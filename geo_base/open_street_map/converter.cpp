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

#include <geo_base/core/polygon.h>
#include <geo_base/core/region.h>
#include <geo_base/library/pool_allocator.h>
#include <geo_base/library/safe_stream.h>
#include <geo_base/open_street_map/converter.h>
#include <geo_base/proto/region.pb.h>
#include <geo_base/proto_library/writer.h>

#include <unordered_map>
#include <unordered_set>

namespace geo_base {
namespace open_street_map {

typedef std::vector<geo_id_t> way_list_t;
typedef std::unordered_map<geo_id_t, std::vector<geo_id_t>> graph_t;
typedef std::unordered_set<geo_id_t> used_t;

static bool eq(char const *a, char const *b)
{
    return !strcmp(a, b);
}

// TODO: Make matching with bor here.
#define OP(ev) \
    if (eq(ev, kv.v)) \
        return true;

static bool check_region_options(kvs_t const &kvs)
{
    for (kv_t const &kv : kvs) {
        if (eq(kv.k, "boundary")) {
            OP("administrative");
            OP("maritime");
            OP("national_park");
            OP("political");
            OP("protected_area");
        }
        if (eq(kv.k, "place")) {
            OP("allotments");
            OP("borough");
            OP("city");
            OP("city_block");
            OP("continent");
            OP("county");
            OP("district");
            OP("farm");
            OP("hamlet");
            OP("island");
            OP("locality");
            OP("municipality");
            OP("neighbourhood");
            OP("plot");
            OP("province");
            OP("quarter");
            OP("region");
            OP("state");
            OP("suburb");
            OP("town");
            OP("village");
        }
        if (eq(kv.k, "type")) {
            OP("multipolygon");
        }
        if (eq(kv.k, "building")) {
            return true;
        }
        if (eq(kv.k, "landuse")) {
            return true;
        }
        if (eq(kv.k, "area")) {
            OP("yes");
        }
    }
    return false;
}

#undef OP

static polygon_t::type_t get_polygon_type(char const *role)
{
    if (!role)
        return polygon_t::TYPE_OUTER;
    if (eq(role, "outer"))
        return polygon_t::TYPE_OUTER;
    if (eq(role, "inner"))
        return polygon_t::TYPE_INNER;
    return polygon_t::TYPE_UNKNOWN;
}

static bool is_boundary(kvs_t const &kvs)
{
    if (!check_region_options(kvs))
        return false;
    for (kv_t const &kv : kvs)
        if (strstr(kv.k, "name") == kv.k)
            return true;
    return false;
}

static bool is_boundary_way(kvs_t const &kvs, geo_ids_t const &nodes)
{
    return is_boundary(kvs) && nodes.front() == nodes.back();
}

static bool check_role(char const *role)
{
    polygon_t::type_t const type = get_polygon_type(role);
    return type == polygon_t::TYPE_INNER || type == polygon_t::TYPE_OUTER;
}

static bool is_way_reference(reference_t const &r)
{
    return r.type == reference_t::TYPE_WAY && check_role(r.role);
}

void grep_boundary_ways_t::process_way(geo_id_t geo_id, kvs_t const &kvs, geo_ids_t const &refs)
{
    if (is_boundary_way(kvs, refs))
        ways_.insert(geo_id);
}

void grep_boundary_ways_t::process_relation(geo_id_t, kvs_t const &kvs, references_t const &refs)
{
    if (is_boundary(kvs))
        for (reference_t const &ref : refs)
            if (is_way_reference(ref))
                ways_.insert(ref.geo_id);
}

void grep_boundary_node_ids_t::process_way(geo_id_t geo_id, kvs_t const &,
    geo_ids_t const &node_ids)
{
    if (need_ways_->find(geo_id) != need_ways_->end()) {
        for (geo_id_t const &node_id : node_ids) {
            nodes_.insert(node_id);
            ways_[geo_id].push_back(node_id);
        }
    }
}

static void location_append(nodes_map_t const &nodes, ::geo_base::proto::polygon_t *poly,
    geo_id_t node_id)
{
    location_t const &node = nodes.at(node_id);
    ::geo_base::proto::location_t *location = poly->add_locations();
    location->set_lat(node.lat);
    location->set_lon(node.lon);
}

static void kvs_append(kv_t const &kv, ::geo_base::proto::region_t *region)
{
    ::geo_base::proto::kv_t *x = region->add_kvs();
    x->set_k(kv.k);
    x->set_v(kv.v);
}

static geo_id_t generate_polygon_id()
{
    // TODO: Make good polygon_id generation.
    return 0;
}

void converter_t::process_way(geo_id_t geo_id, kvs_t const &kvs, geo_ids_t const &refs)
{
    if (!is_boundary_way(kvs, refs))
        return;

    ::geo_base::proto::region_t region;
    region.set_region_id(geo_id);

    ::geo_base::proto::polygon_t *polygon = region.add_polygons();
    polygon->set_polygon_id(generate_polygon_id());
    polygon->set_type(::geo_base::proto::polygon_t::TYPE_OUTER);

    for (geo_id_t const &id : refs)
        location_append(*nodes_, polygon, id);

    for (kv_t const &kv : kvs)
        kvs_append(kv, &region);

    writer_->write(region, allocator_);
    ++regions_number_;
}

static void save_locations(graph_t const &graph, nodes_map_t const &nodes, geo_id_t geo_id,
    ::geo_base::proto::polygon_t *polygon, used_t *used, allocator_t *allocator)
{
    dynarray_t<geo_id_t> stack(2 * graph.size(), allocator);
    stack.push_back(geo_id);

    while (!stack.empty()) {
        geo_id_t geo_id = stack.back();
        stack.pop_back();

        used->insert(geo_id);
        location_append(nodes, polygon, geo_id);

        if (graph.find(geo_id) != graph.end())
            for (geo_id_t const &node_id : graph.at(geo_id))
                if (used->find(node_id) == used->end())
                    stack.push_back(node_id);
    }
}

void converter_t::process_relation(geo_id_t geo_id, kvs_t const &kvs, references_t const &refs)
{
    if (!is_boundary(kvs))
        return;

    bool all_ways_found = true;
    for (reference_t const &r : refs)
        if (is_way_reference(r) && ways_->find(r.geo_id) == ways_->end())
            all_ways_found = false;

    if (!all_ways_found) {
        log_warning("Not found all ways for %s (%lu)", find_name(kvs), geo_id);
        return;
    }

    graph_t graph;

    for (reference_t const &r : refs) {
        if (!is_way_reference(r))
            continue;

        way_list_t const &w = ways_->at(r.geo_id);
        for (number_t i = 0; i + 1 < w.size(); ++i) {
            if (graph[w[i]].size() < 2 && graph[w[i + 1]].size() < 2) {
                graph[w[i]].push_back(w[i + 1]);
                graph[w[i + 1]].push_back(w[i]);
            }
        }
    }

    ::geo_base::proto::region_t region;
    region.set_region_id(geo_id);

    used_t used;

    for (reference_t const &r : refs) {
        if (!is_way_reference(r))
            continue;

        way_list_t const &w = ways_->at(r.geo_id);
        for (number_t i = 0; i < w.size(); ++i) {
            if (used.find(w[i]) != used.end())
                continue;

            ::geo_base::proto::polygon_t *polygon = region.add_polygons();
            polygon->set_polygon_id(generate_polygon_id());
            polygon->set_type((::geo_base::proto::polygon_t::type_t) get_polygon_type(r.role));

            save_locations(graph, *nodes_, w[i], polygon, &used, allocator_);
        }
    }

    if (region.polygons_size() > 0) {
        for (kv_t const &kv : kvs)
            kvs_append(kv, &region);

        writer_->write(region, allocator_);
        ++regions_number_;
    }
}

void run_pool_convert(char const *input_path, char const *output_path, size_t threads_number)
{
    log_info("Run pool convert (%lu threads)", threads_number);

    stop_watch_t stop_watch;
    stop_watch.run();

    std::vector<pool_allocator_t> allocators;
    for (size_t i = 0; i < threads_number; ++i)
        allocators.emplace_back(256_mb);

    geo_ids_set_t way_ids;

    {
        log_info("Grep boundary ways...");

        std::vector<grep_boundary_ways_t> greps;
        for (size_t i = 0; i < threads_number; ++i)
            greps.emplace_back(&allocators[i]);
        
        pool_parser_t parser;
        parser.parse(input_path, greps);

        for (size_t i = 0; i < greps.size(); ++i) {
            way_ids.insert(greps[i].ways().begin(), greps[i].ways().end());
            greps[i].clear();
        }

        log_info("Grep boundary ways done, way_ids = %lu", way_ids.size());
    }

    geo_ids_set_t node_ids;
    ways_map_t ways;

    {
        log_info("Grep boundary node ids...");

        std::vector<grep_boundary_node_ids_t> greps;
        for (size_t i = 0; i < threads_number; ++i)
            greps.emplace_back(way_ids, &allocators[i]);

        pool_parser_t parser;
        parser.parse(input_path, greps);

        for (size_t i = 0; i < greps.size(); ++i) {
            node_ids.insert(greps[i].nodes().begin(), greps[i].nodes().end());
            ways.insert(greps[i].ways().begin(), greps[i].ways().end());
            greps[i].clear();
        }

        log_info("Grep boundary node ids done, node_ids = %lu, ways = %lu",
            node_ids.size(), ways.size());
    }

    nodes_map_t nodes;

    {
        log_info("Grep boundary nodes...");

        std::vector<grep_boundary_nodes_t> greps;
        for (size_t i = 0; i < threads_number; ++i)
            greps.emplace_back(node_ids, &allocators[i]);

        pool_parser_t parser;
        parser.parse(input_path, greps);

        for (size_t i = 0; i < greps.size(); ++i) {
            nodes.insert(greps[i].nodes().begin(), greps[i].nodes().end());
            greps[i].clear();
        }

        log_info("Grep boundary nodes done, nodes = %lu", nodes.size());
    }

    {
        log_info("Convert...");

        ::geo_base::proto::writer_t proto_writer(output_path);

        std::vector<converter_t> converters;
        for (size_t i = 0; i < threads_number; ++i)
            converters.emplace_back(nodes, ways, &proto_writer, &allocators[i]);

        pool_parser_t parser;
        parser.parse(input_path, converters);

        size_t regions_number = 0;
        for (size_t i = 0; i < threads_number; ++i)
            regions_number += converters[i].regions_number();

        log_info("Convert done, number of regions = %lu", regions_number);
    }

    float const seconds = stop_watch.get();
    log_info("Run pool parse done in %.3f seconds (%.3f minutes)", seconds, seconds / 60.0);
}

} // namespace open_street_map
} // namespace geo_base
