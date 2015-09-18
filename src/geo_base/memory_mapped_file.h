// Copyright (c) 2015 Urtashev Arslan. All rights reserved.
// Contacts: <urtashev@gmail.com>
//   
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//           
//   The above copyright notice and this permission notice shall be included
//   in all copies or substantial portions of the Software.
//              
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef GEO_BASE_MEMORY_MAPPED_FILE_H_
#define GEO_BASE_MEMORY_MAPPED_FILE_H_

#include "crc32.h"
#include "file.h"
#include "mmap_guard.h"

namespace geo_base {

// MemoryMappedFile is a handler of file memory. Can PROT_READ and 
// PROT_READ|PROT_WRITE shared memory mapping of file. Needed for 
// correct map/unmap memory mapped data using RAII.
class MemoryMappedFile : public File {
 protected:
  static const size_t kDefaultMemorySize = 8LU * (1LU << 30); // 8 GB

  // Open file for reading and map file data with PROT_READ and MAP_SHARED
  // options.
  void ReadOnlyOpen(const char* path);

  // Open file for writing and map file data with PROTO_READ|PROT_WRITE and
  // MAP_SHARED options.
  void ReadWriteOpen(const char* path, size_t memory_size = kDefaultMemorySize);

 public:
  uint32_t GetCRC32() const {
    return geo_base::GetCRC32(addr(), SizeOfOpenFile());
  }

  uint8_t GetSimpleChecksum() const;

  void *addr() const {
    return mmap_guard_.addr;
  }

  size_t length() const {
    return mmap_guard_.length;
  }

 private:
  MMapGuard mmap_guard_;
};

} // namespace geo_base

#endif // GEO_BASE_MEMORY_MAPPED_FILE_H_
