#pragma once

#include "common.h"
#include "geo_base_alloc.h"
#include "geo_data.h"
#include "hash.h"
#include "unordered_map.h"
#include "unordered_set.h"
#include "vector.h"

namespace troll {

struct checkpoint_t {
	coordinate_t coordinate;
	ref_t cur_edge_ref;
	bool erase;
};

#define TROLL_DEF_VAR(var_t, var) \
	var_t var;

#define TROLL_DEF_PTR(ptr_t, ptr) \
	// undef

#define TROLL_DEF_ARR(arr_t, arr) \
	vector_t<arr_t> arr;

struct geo_data_ctx_t {
	TROLL_DEF_GEO_DATA

	ref_t push_point(point_t const &p)
	{
		if (saved.points.find(p) == saved.points.end()) {
			saved.points[p] = points.size();
			points.push_back(p);
		}
		return saved.points[p];
	}

	ref_t push_edge(edge_t const &e)
	{
		if (saved.edges.find(e) == saved.edges.end()) {
			saved.edges[e] = edges.size();
			edges.push_back(e);
		}
		return saved.edges[e];
	}

	offset_t push_blob(blob_t const &b)
	{
		if (saved.blobs.find(b) == saved.blobs.end()) {
			offset_t off = blobs.size();
			for (char c : b)
				blobs.push_back(c);
			blobs.push_back('\0');
			saved.blobs[b] = off;
		}
		return saved.blobs[b];
	}

	void fini(geo_base_alloc_t *base);

	double memory() const;

	struct {
		vector_t<checkpoint_t> checkpoints;
		vector_t<edge_t> edges;
		vector_t<edge_t> erase;
		vector_t<location_t> locations;
		vector_t<point_t> points;
	} buf;

	struct {
		unordered_map_t<edge_t, ref_t> edges;
		unordered_map_t<point_t, ref_t> points;
		unordered_map_t<blob_t, offset_t, blob_hash_t> blobs;
	} saved;

	unordered_set_t<uint64_t> processed;
};

#undef TROLL_DEF_VAR
#undef TROLL_DEF_PTR
#undef TROLL_DEF_ARR

class geo_base_generate_t {
public:
	geo_base_generate_t(char const *path)
		: base(path)
	{
	}

	void update(region_id_t region_id, vector_t<location_t> const &locations, vector_t<blob_t> const &blobs);

	void save();

	void show_base(output_t &out) const
	{
		base.show(out);
	}

	geo_data_ctx_t const &context() const
	{
		return ctx;
	}

private:
	void update(region_id_t region_id, vector_t<point_t> const &points, vector_t<blob_t> const &blobs);

	void create_boxes();

	geo_base_alloc_t base;
	geo_data_ctx_t ctx;
};

}