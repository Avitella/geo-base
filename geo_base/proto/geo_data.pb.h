// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: geo_base/proto/geo_data.proto

#ifndef PROTOBUF_geo_5fbase_2fproto_2fgeo_5fdata_2eproto__INCLUDED
#define PROTOBUF_geo_5fbase_2fproto_2fgeo_5fdata_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace geo_base {
namespace proto {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_geo_5fbase_2fproto_2fgeo_5fdata_2eproto();
void protobuf_AssignDesc_geo_5fbase_2fproto_2fgeo_5fdata_2eproto();
void protobuf_ShutdownFile_geo_5fbase_2fproto_2fgeo_5fdata_2eproto();

class geo_data_t;

// ===================================================================

class geo_data_t : public ::google::protobuf::Message {
 public:
  geo_data_t();
  virtual ~geo_data_t();

  geo_data_t(const geo_data_t& from);

  inline geo_data_t& operator=(const geo_data_t& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const geo_data_t& default_instance();

  void Swap(geo_data_t* other);

  // implements Message ----------------------------------------------

  inline geo_data_t* New() const { return New(NULL); }

  geo_data_t* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const geo_data_t& from);
  void MergeFrom(const geo_data_t& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(geo_data_t* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint64 magic = 1;
  bool has_magic() const;
  void clear_magic();
  static const int kMagicFieldNumber = 1;
  ::google::protobuf::uint64 magic() const;
  void set_magic(::google::protobuf::uint64 value);

  // required uint64 version = 2;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 2;
  ::google::protobuf::uint64 version() const;
  void set_version(::google::protobuf::uint64 value);

  // optional uint64 points = 3;
  bool has_points() const;
  void clear_points();
  static const int kPointsFieldNumber = 3;
  ::google::protobuf::uint64 points() const;
  void set_points(::google::protobuf::uint64 value);

  // optional uint64 points_number = 4;
  bool has_points_number() const;
  void clear_points_number();
  static const int kPointsNumberFieldNumber = 4;
  ::google::protobuf::uint64 points_number() const;
  void set_points_number(::google::protobuf::uint64 value);

  // optional uint64 edges = 5;
  bool has_edges() const;
  void clear_edges();
  static const int kEdgesFieldNumber = 5;
  ::google::protobuf::uint64 edges() const;
  void set_edges(::google::protobuf::uint64 value);

  // optional uint64 edges_number = 6;
  bool has_edges_number() const;
  void clear_edges_number();
  static const int kEdgesNumberFieldNumber = 6;
  ::google::protobuf::uint64 edges_number() const;
  void set_edges_number(::google::protobuf::uint64 value);

  // optional uint64 edge_refs = 7;
  bool has_edge_refs() const;
  void clear_edge_refs();
  static const int kEdgeRefsFieldNumber = 7;
  ::google::protobuf::uint64 edge_refs() const;
  void set_edge_refs(::google::protobuf::uint64 value);

  // optional uint64 edge_refs_number = 8;
  bool has_edge_refs_number() const;
  void clear_edge_refs_number();
  static const int kEdgeRefsNumberFieldNumber = 8;
  ::google::protobuf::uint64 edge_refs_number() const;
  void set_edge_refs_number(::google::protobuf::uint64 value);

  // optional uint64 parts = 9;
  bool has_parts() const;
  void clear_parts();
  static const int kPartsFieldNumber = 9;
  ::google::protobuf::uint64 parts() const;
  void set_parts(::google::protobuf::uint64 value);

  // optional uint64 parts_number = 10;
  bool has_parts_number() const;
  void clear_parts_number();
  static const int kPartsNumberFieldNumber = 10;
  ::google::protobuf::uint64 parts_number() const;
  void set_parts_number(::google::protobuf::uint64 value);

  // optional uint64 polygons = 11;
  bool has_polygons() const;
  void clear_polygons();
  static const int kPolygonsFieldNumber = 11;
  ::google::protobuf::uint64 polygons() const;
  void set_polygons(::google::protobuf::uint64 value);

  // optional uint64 polygons_number = 12;
  bool has_polygons_number() const;
  void clear_polygons_number();
  static const int kPolygonsNumberFieldNumber = 12;
  ::google::protobuf::uint64 polygons_number() const;
  void set_polygons_number(::google::protobuf::uint64 value);

  // optional uint64 polygon_refs = 13;
  bool has_polygon_refs() const;
  void clear_polygon_refs();
  static const int kPolygonRefsFieldNumber = 13;
  ::google::protobuf::uint64 polygon_refs() const;
  void set_polygon_refs(::google::protobuf::uint64 value);

  // optional uint64 polygon_refs_number = 14;
  bool has_polygon_refs_number() const;
  void clear_polygon_refs_number();
  static const int kPolygonRefsNumberFieldNumber = 14;
  ::google::protobuf::uint64 polygon_refs_number() const;
  void set_polygon_refs_number(::google::protobuf::uint64 value);

  // optional uint64 boxes = 15;
  bool has_boxes() const;
  void clear_boxes();
  static const int kBoxesFieldNumber = 15;
  ::google::protobuf::uint64 boxes() const;
  void set_boxes(::google::protobuf::uint64 value);

  // optional uint64 boxes_number = 16;
  bool has_boxes_number() const;
  void clear_boxes_number();
  static const int kBoxesNumberFieldNumber = 16;
  ::google::protobuf::uint64 boxes_number() const;
  void set_boxes_number(::google::protobuf::uint64 value);

  // optional uint64 blobs = 17;
  bool has_blobs() const;
  void clear_blobs();
  static const int kBlobsFieldNumber = 17;
  ::google::protobuf::uint64 blobs() const;
  void set_blobs(::google::protobuf::uint64 value);

  // optional uint64 blobs_number = 18;
  bool has_blobs_number() const;
  void clear_blobs_number();
  static const int kBlobsNumberFieldNumber = 18;
  ::google::protobuf::uint64 blobs_number() const;
  void set_blobs_number(::google::protobuf::uint64 value);

  // optional uint64 kvs = 19;
  bool has_kvs() const;
  void clear_kvs();
  static const int kKvsFieldNumber = 19;
  ::google::protobuf::uint64 kvs() const;
  void set_kvs(::google::protobuf::uint64 value);

  // optional uint64 kvs_number = 20;
  bool has_kvs_number() const;
  void clear_kvs_number();
  static const int kKvsNumberFieldNumber = 20;
  ::google::protobuf::uint64 kvs_number() const;
  void set_kvs_number(::google::protobuf::uint64 value);

  // optional uint64 regions = 21;
  bool has_regions() const;
  void clear_regions();
  static const int kRegionsFieldNumber = 21;
  ::google::protobuf::uint64 regions() const;
  void set_regions(::google::protobuf::uint64 value);

  // optional uint64 regions_number = 22;
  bool has_regions_number() const;
  void clear_regions_number();
  static const int kRegionsNumberFieldNumber = 22;
  ::google::protobuf::uint64 regions_number() const;
  void set_regions_number(::google::protobuf::uint64 value);

  // optional uint64 raw_borders_number = 23;
  bool has_raw_borders_number() const;
  void clear_raw_borders_number();
  static const int kRawBordersNumberFieldNumber = 23;
  ::google::protobuf::uint64 raw_borders_number() const;
  void set_raw_borders_number(::google::protobuf::uint64 value);

  // optional uint64 raw_borders = 24;
  bool has_raw_borders() const;
  void clear_raw_borders();
  static const int kRawBordersFieldNumber = 24;
  ::google::protobuf::uint64 raw_borders() const;
  void set_raw_borders(::google::protobuf::uint64 value);

  // optional uint64 raw_edge_refs_number = 25;
  bool has_raw_edge_refs_number() const;
  void clear_raw_edge_refs_number();
  static const int kRawEdgeRefsNumberFieldNumber = 25;
  ::google::protobuf::uint64 raw_edge_refs_number() const;
  void set_raw_edge_refs_number(::google::protobuf::uint64 value);

  // optional uint64 raw_edge_refs = 26;
  bool has_raw_edge_refs() const;
  void clear_raw_edge_refs();
  static const int kRawEdgeRefsFieldNumber = 26;
  ::google::protobuf::uint64 raw_edge_refs() const;
  void set_raw_edge_refs(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:geo_base.proto.geo_data_t)
 private:
  inline void set_has_magic();
  inline void clear_has_magic();
  inline void set_has_version();
  inline void clear_has_version();
  inline void set_has_points();
  inline void clear_has_points();
  inline void set_has_points_number();
  inline void clear_has_points_number();
  inline void set_has_edges();
  inline void clear_has_edges();
  inline void set_has_edges_number();
  inline void clear_has_edges_number();
  inline void set_has_edge_refs();
  inline void clear_has_edge_refs();
  inline void set_has_edge_refs_number();
  inline void clear_has_edge_refs_number();
  inline void set_has_parts();
  inline void clear_has_parts();
  inline void set_has_parts_number();
  inline void clear_has_parts_number();
  inline void set_has_polygons();
  inline void clear_has_polygons();
  inline void set_has_polygons_number();
  inline void clear_has_polygons_number();
  inline void set_has_polygon_refs();
  inline void clear_has_polygon_refs();
  inline void set_has_polygon_refs_number();
  inline void clear_has_polygon_refs_number();
  inline void set_has_boxes();
  inline void clear_has_boxes();
  inline void set_has_boxes_number();
  inline void clear_has_boxes_number();
  inline void set_has_blobs();
  inline void clear_has_blobs();
  inline void set_has_blobs_number();
  inline void clear_has_blobs_number();
  inline void set_has_kvs();
  inline void clear_has_kvs();
  inline void set_has_kvs_number();
  inline void clear_has_kvs_number();
  inline void set_has_regions();
  inline void clear_has_regions();
  inline void set_has_regions_number();
  inline void clear_has_regions_number();
  inline void set_has_raw_borders_number();
  inline void clear_has_raw_borders_number();
  inline void set_has_raw_borders();
  inline void clear_has_raw_borders();
  inline void set_has_raw_edge_refs_number();
  inline void clear_has_raw_edge_refs_number();
  inline void set_has_raw_edge_refs();
  inline void clear_has_raw_edge_refs();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint64 magic_;
  ::google::protobuf::uint64 version_;
  ::google::protobuf::uint64 points_;
  ::google::protobuf::uint64 points_number_;
  ::google::protobuf::uint64 edges_;
  ::google::protobuf::uint64 edges_number_;
  ::google::protobuf::uint64 edge_refs_;
  ::google::protobuf::uint64 edge_refs_number_;
  ::google::protobuf::uint64 parts_;
  ::google::protobuf::uint64 parts_number_;
  ::google::protobuf::uint64 polygons_;
  ::google::protobuf::uint64 polygons_number_;
  ::google::protobuf::uint64 polygon_refs_;
  ::google::protobuf::uint64 polygon_refs_number_;
  ::google::protobuf::uint64 boxes_;
  ::google::protobuf::uint64 boxes_number_;
  ::google::protobuf::uint64 blobs_;
  ::google::protobuf::uint64 blobs_number_;
  ::google::protobuf::uint64 kvs_;
  ::google::protobuf::uint64 kvs_number_;
  ::google::protobuf::uint64 regions_;
  ::google::protobuf::uint64 regions_number_;
  ::google::protobuf::uint64 raw_borders_number_;
  ::google::protobuf::uint64 raw_borders_;
  ::google::protobuf::uint64 raw_edge_refs_number_;
  ::google::protobuf::uint64 raw_edge_refs_;
  friend void  protobuf_AddDesc_geo_5fbase_2fproto_2fgeo_5fdata_2eproto();
  friend void protobuf_AssignDesc_geo_5fbase_2fproto_2fgeo_5fdata_2eproto();
  friend void protobuf_ShutdownFile_geo_5fbase_2fproto_2fgeo_5fdata_2eproto();

  void InitAsDefaultInstance();
  static geo_data_t* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// geo_data_t

// required uint64 magic = 1;
inline bool geo_data_t::has_magic() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void geo_data_t::set_has_magic() {
  _has_bits_[0] |= 0x00000001u;
}
inline void geo_data_t::clear_has_magic() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void geo_data_t::clear_magic() {
  magic_ = GOOGLE_ULONGLONG(0);
  clear_has_magic();
}
inline ::google::protobuf::uint64 geo_data_t::magic() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.magic)
  return magic_;
}
inline void geo_data_t::set_magic(::google::protobuf::uint64 value) {
  set_has_magic();
  magic_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.magic)
}

// required uint64 version = 2;
inline bool geo_data_t::has_version() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void geo_data_t::set_has_version() {
  _has_bits_[0] |= 0x00000002u;
}
inline void geo_data_t::clear_has_version() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void geo_data_t::clear_version() {
  version_ = GOOGLE_ULONGLONG(0);
  clear_has_version();
}
inline ::google::protobuf::uint64 geo_data_t::version() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.version)
  return version_;
}
inline void geo_data_t::set_version(::google::protobuf::uint64 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.version)
}

// optional uint64 points = 3;
inline bool geo_data_t::has_points() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void geo_data_t::set_has_points() {
  _has_bits_[0] |= 0x00000004u;
}
inline void geo_data_t::clear_has_points() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void geo_data_t::clear_points() {
  points_ = GOOGLE_ULONGLONG(0);
  clear_has_points();
}
inline ::google::protobuf::uint64 geo_data_t::points() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.points)
  return points_;
}
inline void geo_data_t::set_points(::google::protobuf::uint64 value) {
  set_has_points();
  points_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.points)
}

// optional uint64 points_number = 4;
inline bool geo_data_t::has_points_number() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void geo_data_t::set_has_points_number() {
  _has_bits_[0] |= 0x00000008u;
}
inline void geo_data_t::clear_has_points_number() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void geo_data_t::clear_points_number() {
  points_number_ = GOOGLE_ULONGLONG(0);
  clear_has_points_number();
}
inline ::google::protobuf::uint64 geo_data_t::points_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.points_number)
  return points_number_;
}
inline void geo_data_t::set_points_number(::google::protobuf::uint64 value) {
  set_has_points_number();
  points_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.points_number)
}

// optional uint64 edges = 5;
inline bool geo_data_t::has_edges() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void geo_data_t::set_has_edges() {
  _has_bits_[0] |= 0x00000010u;
}
inline void geo_data_t::clear_has_edges() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void geo_data_t::clear_edges() {
  edges_ = GOOGLE_ULONGLONG(0);
  clear_has_edges();
}
inline ::google::protobuf::uint64 geo_data_t::edges() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.edges)
  return edges_;
}
inline void geo_data_t::set_edges(::google::protobuf::uint64 value) {
  set_has_edges();
  edges_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.edges)
}

// optional uint64 edges_number = 6;
inline bool geo_data_t::has_edges_number() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void geo_data_t::set_has_edges_number() {
  _has_bits_[0] |= 0x00000020u;
}
inline void geo_data_t::clear_has_edges_number() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void geo_data_t::clear_edges_number() {
  edges_number_ = GOOGLE_ULONGLONG(0);
  clear_has_edges_number();
}
inline ::google::protobuf::uint64 geo_data_t::edges_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.edges_number)
  return edges_number_;
}
inline void geo_data_t::set_edges_number(::google::protobuf::uint64 value) {
  set_has_edges_number();
  edges_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.edges_number)
}

// optional uint64 edge_refs = 7;
inline bool geo_data_t::has_edge_refs() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void geo_data_t::set_has_edge_refs() {
  _has_bits_[0] |= 0x00000040u;
}
inline void geo_data_t::clear_has_edge_refs() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void geo_data_t::clear_edge_refs() {
  edge_refs_ = GOOGLE_ULONGLONG(0);
  clear_has_edge_refs();
}
inline ::google::protobuf::uint64 geo_data_t::edge_refs() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.edge_refs)
  return edge_refs_;
}
inline void geo_data_t::set_edge_refs(::google::protobuf::uint64 value) {
  set_has_edge_refs();
  edge_refs_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.edge_refs)
}

// optional uint64 edge_refs_number = 8;
inline bool geo_data_t::has_edge_refs_number() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void geo_data_t::set_has_edge_refs_number() {
  _has_bits_[0] |= 0x00000080u;
}
inline void geo_data_t::clear_has_edge_refs_number() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void geo_data_t::clear_edge_refs_number() {
  edge_refs_number_ = GOOGLE_ULONGLONG(0);
  clear_has_edge_refs_number();
}
inline ::google::protobuf::uint64 geo_data_t::edge_refs_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.edge_refs_number)
  return edge_refs_number_;
}
inline void geo_data_t::set_edge_refs_number(::google::protobuf::uint64 value) {
  set_has_edge_refs_number();
  edge_refs_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.edge_refs_number)
}

// optional uint64 parts = 9;
inline bool geo_data_t::has_parts() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void geo_data_t::set_has_parts() {
  _has_bits_[0] |= 0x00000100u;
}
inline void geo_data_t::clear_has_parts() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void geo_data_t::clear_parts() {
  parts_ = GOOGLE_ULONGLONG(0);
  clear_has_parts();
}
inline ::google::protobuf::uint64 geo_data_t::parts() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.parts)
  return parts_;
}
inline void geo_data_t::set_parts(::google::protobuf::uint64 value) {
  set_has_parts();
  parts_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.parts)
}

// optional uint64 parts_number = 10;
inline bool geo_data_t::has_parts_number() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void geo_data_t::set_has_parts_number() {
  _has_bits_[0] |= 0x00000200u;
}
inline void geo_data_t::clear_has_parts_number() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void geo_data_t::clear_parts_number() {
  parts_number_ = GOOGLE_ULONGLONG(0);
  clear_has_parts_number();
}
inline ::google::protobuf::uint64 geo_data_t::parts_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.parts_number)
  return parts_number_;
}
inline void geo_data_t::set_parts_number(::google::protobuf::uint64 value) {
  set_has_parts_number();
  parts_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.parts_number)
}

// optional uint64 polygons = 11;
inline bool geo_data_t::has_polygons() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void geo_data_t::set_has_polygons() {
  _has_bits_[0] |= 0x00000400u;
}
inline void geo_data_t::clear_has_polygons() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void geo_data_t::clear_polygons() {
  polygons_ = GOOGLE_ULONGLONG(0);
  clear_has_polygons();
}
inline ::google::protobuf::uint64 geo_data_t::polygons() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.polygons)
  return polygons_;
}
inline void geo_data_t::set_polygons(::google::protobuf::uint64 value) {
  set_has_polygons();
  polygons_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.polygons)
}

// optional uint64 polygons_number = 12;
inline bool geo_data_t::has_polygons_number() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void geo_data_t::set_has_polygons_number() {
  _has_bits_[0] |= 0x00000800u;
}
inline void geo_data_t::clear_has_polygons_number() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void geo_data_t::clear_polygons_number() {
  polygons_number_ = GOOGLE_ULONGLONG(0);
  clear_has_polygons_number();
}
inline ::google::protobuf::uint64 geo_data_t::polygons_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.polygons_number)
  return polygons_number_;
}
inline void geo_data_t::set_polygons_number(::google::protobuf::uint64 value) {
  set_has_polygons_number();
  polygons_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.polygons_number)
}

// optional uint64 polygon_refs = 13;
inline bool geo_data_t::has_polygon_refs() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void geo_data_t::set_has_polygon_refs() {
  _has_bits_[0] |= 0x00001000u;
}
inline void geo_data_t::clear_has_polygon_refs() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void geo_data_t::clear_polygon_refs() {
  polygon_refs_ = GOOGLE_ULONGLONG(0);
  clear_has_polygon_refs();
}
inline ::google::protobuf::uint64 geo_data_t::polygon_refs() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.polygon_refs)
  return polygon_refs_;
}
inline void geo_data_t::set_polygon_refs(::google::protobuf::uint64 value) {
  set_has_polygon_refs();
  polygon_refs_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.polygon_refs)
}

// optional uint64 polygon_refs_number = 14;
inline bool geo_data_t::has_polygon_refs_number() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void geo_data_t::set_has_polygon_refs_number() {
  _has_bits_[0] |= 0x00002000u;
}
inline void geo_data_t::clear_has_polygon_refs_number() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void geo_data_t::clear_polygon_refs_number() {
  polygon_refs_number_ = GOOGLE_ULONGLONG(0);
  clear_has_polygon_refs_number();
}
inline ::google::protobuf::uint64 geo_data_t::polygon_refs_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.polygon_refs_number)
  return polygon_refs_number_;
}
inline void geo_data_t::set_polygon_refs_number(::google::protobuf::uint64 value) {
  set_has_polygon_refs_number();
  polygon_refs_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.polygon_refs_number)
}

// optional uint64 boxes = 15;
inline bool geo_data_t::has_boxes() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void geo_data_t::set_has_boxes() {
  _has_bits_[0] |= 0x00004000u;
}
inline void geo_data_t::clear_has_boxes() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void geo_data_t::clear_boxes() {
  boxes_ = GOOGLE_ULONGLONG(0);
  clear_has_boxes();
}
inline ::google::protobuf::uint64 geo_data_t::boxes() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.boxes)
  return boxes_;
}
inline void geo_data_t::set_boxes(::google::protobuf::uint64 value) {
  set_has_boxes();
  boxes_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.boxes)
}

// optional uint64 boxes_number = 16;
inline bool geo_data_t::has_boxes_number() const {
  return (_has_bits_[0] & 0x00008000u) != 0;
}
inline void geo_data_t::set_has_boxes_number() {
  _has_bits_[0] |= 0x00008000u;
}
inline void geo_data_t::clear_has_boxes_number() {
  _has_bits_[0] &= ~0x00008000u;
}
inline void geo_data_t::clear_boxes_number() {
  boxes_number_ = GOOGLE_ULONGLONG(0);
  clear_has_boxes_number();
}
inline ::google::protobuf::uint64 geo_data_t::boxes_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.boxes_number)
  return boxes_number_;
}
inline void geo_data_t::set_boxes_number(::google::protobuf::uint64 value) {
  set_has_boxes_number();
  boxes_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.boxes_number)
}

// optional uint64 blobs = 17;
inline bool geo_data_t::has_blobs() const {
  return (_has_bits_[0] & 0x00010000u) != 0;
}
inline void geo_data_t::set_has_blobs() {
  _has_bits_[0] |= 0x00010000u;
}
inline void geo_data_t::clear_has_blobs() {
  _has_bits_[0] &= ~0x00010000u;
}
inline void geo_data_t::clear_blobs() {
  blobs_ = GOOGLE_ULONGLONG(0);
  clear_has_blobs();
}
inline ::google::protobuf::uint64 geo_data_t::blobs() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.blobs)
  return blobs_;
}
inline void geo_data_t::set_blobs(::google::protobuf::uint64 value) {
  set_has_blobs();
  blobs_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.blobs)
}

// optional uint64 blobs_number = 18;
inline bool geo_data_t::has_blobs_number() const {
  return (_has_bits_[0] & 0x00020000u) != 0;
}
inline void geo_data_t::set_has_blobs_number() {
  _has_bits_[0] |= 0x00020000u;
}
inline void geo_data_t::clear_has_blobs_number() {
  _has_bits_[0] &= ~0x00020000u;
}
inline void geo_data_t::clear_blobs_number() {
  blobs_number_ = GOOGLE_ULONGLONG(0);
  clear_has_blobs_number();
}
inline ::google::protobuf::uint64 geo_data_t::blobs_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.blobs_number)
  return blobs_number_;
}
inline void geo_data_t::set_blobs_number(::google::protobuf::uint64 value) {
  set_has_blobs_number();
  blobs_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.blobs_number)
}

// optional uint64 kvs = 19;
inline bool geo_data_t::has_kvs() const {
  return (_has_bits_[0] & 0x00040000u) != 0;
}
inline void geo_data_t::set_has_kvs() {
  _has_bits_[0] |= 0x00040000u;
}
inline void geo_data_t::clear_has_kvs() {
  _has_bits_[0] &= ~0x00040000u;
}
inline void geo_data_t::clear_kvs() {
  kvs_ = GOOGLE_ULONGLONG(0);
  clear_has_kvs();
}
inline ::google::protobuf::uint64 geo_data_t::kvs() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.kvs)
  return kvs_;
}
inline void geo_data_t::set_kvs(::google::protobuf::uint64 value) {
  set_has_kvs();
  kvs_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.kvs)
}

// optional uint64 kvs_number = 20;
inline bool geo_data_t::has_kvs_number() const {
  return (_has_bits_[0] & 0x00080000u) != 0;
}
inline void geo_data_t::set_has_kvs_number() {
  _has_bits_[0] |= 0x00080000u;
}
inline void geo_data_t::clear_has_kvs_number() {
  _has_bits_[0] &= ~0x00080000u;
}
inline void geo_data_t::clear_kvs_number() {
  kvs_number_ = GOOGLE_ULONGLONG(0);
  clear_has_kvs_number();
}
inline ::google::protobuf::uint64 geo_data_t::kvs_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.kvs_number)
  return kvs_number_;
}
inline void geo_data_t::set_kvs_number(::google::protobuf::uint64 value) {
  set_has_kvs_number();
  kvs_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.kvs_number)
}

// optional uint64 regions = 21;
inline bool geo_data_t::has_regions() const {
  return (_has_bits_[0] & 0x00100000u) != 0;
}
inline void geo_data_t::set_has_regions() {
  _has_bits_[0] |= 0x00100000u;
}
inline void geo_data_t::clear_has_regions() {
  _has_bits_[0] &= ~0x00100000u;
}
inline void geo_data_t::clear_regions() {
  regions_ = GOOGLE_ULONGLONG(0);
  clear_has_regions();
}
inline ::google::protobuf::uint64 geo_data_t::regions() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.regions)
  return regions_;
}
inline void geo_data_t::set_regions(::google::protobuf::uint64 value) {
  set_has_regions();
  regions_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.regions)
}

// optional uint64 regions_number = 22;
inline bool geo_data_t::has_regions_number() const {
  return (_has_bits_[0] & 0x00200000u) != 0;
}
inline void geo_data_t::set_has_regions_number() {
  _has_bits_[0] |= 0x00200000u;
}
inline void geo_data_t::clear_has_regions_number() {
  _has_bits_[0] &= ~0x00200000u;
}
inline void geo_data_t::clear_regions_number() {
  regions_number_ = GOOGLE_ULONGLONG(0);
  clear_has_regions_number();
}
inline ::google::protobuf::uint64 geo_data_t::regions_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.regions_number)
  return regions_number_;
}
inline void geo_data_t::set_regions_number(::google::protobuf::uint64 value) {
  set_has_regions_number();
  regions_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.regions_number)
}

// optional uint64 raw_borders_number = 23;
inline bool geo_data_t::has_raw_borders_number() const {
  return (_has_bits_[0] & 0x00400000u) != 0;
}
inline void geo_data_t::set_has_raw_borders_number() {
  _has_bits_[0] |= 0x00400000u;
}
inline void geo_data_t::clear_has_raw_borders_number() {
  _has_bits_[0] &= ~0x00400000u;
}
inline void geo_data_t::clear_raw_borders_number() {
  raw_borders_number_ = GOOGLE_ULONGLONG(0);
  clear_has_raw_borders_number();
}
inline ::google::protobuf::uint64 geo_data_t::raw_borders_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.raw_borders_number)
  return raw_borders_number_;
}
inline void geo_data_t::set_raw_borders_number(::google::protobuf::uint64 value) {
  set_has_raw_borders_number();
  raw_borders_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.raw_borders_number)
}

// optional uint64 raw_borders = 24;
inline bool geo_data_t::has_raw_borders() const {
  return (_has_bits_[0] & 0x00800000u) != 0;
}
inline void geo_data_t::set_has_raw_borders() {
  _has_bits_[0] |= 0x00800000u;
}
inline void geo_data_t::clear_has_raw_borders() {
  _has_bits_[0] &= ~0x00800000u;
}
inline void geo_data_t::clear_raw_borders() {
  raw_borders_ = GOOGLE_ULONGLONG(0);
  clear_has_raw_borders();
}
inline ::google::protobuf::uint64 geo_data_t::raw_borders() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.raw_borders)
  return raw_borders_;
}
inline void geo_data_t::set_raw_borders(::google::protobuf::uint64 value) {
  set_has_raw_borders();
  raw_borders_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.raw_borders)
}

// optional uint64 raw_edge_refs_number = 25;
inline bool geo_data_t::has_raw_edge_refs_number() const {
  return (_has_bits_[0] & 0x01000000u) != 0;
}
inline void geo_data_t::set_has_raw_edge_refs_number() {
  _has_bits_[0] |= 0x01000000u;
}
inline void geo_data_t::clear_has_raw_edge_refs_number() {
  _has_bits_[0] &= ~0x01000000u;
}
inline void geo_data_t::clear_raw_edge_refs_number() {
  raw_edge_refs_number_ = GOOGLE_ULONGLONG(0);
  clear_has_raw_edge_refs_number();
}
inline ::google::protobuf::uint64 geo_data_t::raw_edge_refs_number() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.raw_edge_refs_number)
  return raw_edge_refs_number_;
}
inline void geo_data_t::set_raw_edge_refs_number(::google::protobuf::uint64 value) {
  set_has_raw_edge_refs_number();
  raw_edge_refs_number_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.raw_edge_refs_number)
}

// optional uint64 raw_edge_refs = 26;
inline bool geo_data_t::has_raw_edge_refs() const {
  return (_has_bits_[0] & 0x02000000u) != 0;
}
inline void geo_data_t::set_has_raw_edge_refs() {
  _has_bits_[0] |= 0x02000000u;
}
inline void geo_data_t::clear_has_raw_edge_refs() {
  _has_bits_[0] &= ~0x02000000u;
}
inline void geo_data_t::clear_raw_edge_refs() {
  raw_edge_refs_ = GOOGLE_ULONGLONG(0);
  clear_has_raw_edge_refs();
}
inline ::google::protobuf::uint64 geo_data_t::raw_edge_refs() const {
  // @@protoc_insertion_point(field_get:geo_base.proto.geo_data_t.raw_edge_refs)
  return raw_edge_refs_;
}
inline void geo_data_t::set_raw_edge_refs(::google::protobuf::uint64 value) {
  set_has_raw_edge_refs();
  raw_edge_refs_ = value;
  // @@protoc_insertion_point(field_set:geo_base.proto.geo_data_t.raw_edge_refs)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace geo_base

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_geo_5fbase_2fproto_2fgeo_5fdata_2eproto__INCLUDED
