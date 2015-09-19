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

#include "file.h"

#include "exception.h"

#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

namespace geo_base {

void File::OpenReadOnly(const char* path) {
  int fd = open(path, O_RDONLY | O_CLOEXEC); // | O_NOATIME);
  if (fd < 0)
    throw Exception("%s", strerror(errno));
  file_guard_ = FileGuard(fd);
}

void File::OpenReadWrite(const char* path) {
  int fd = open(path, O_RDWR | O_CREAT | O_CLOEXEC | O_TRUNC,
      S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
  if (fd < 0)
    throw Exception("%s", strerror(errno));
  file_guard_ = FileGuard(fd);
}

size_t File::BytesCount() const {
  struct stat st;
  if (fstat(fd(), &st) < 0)
    throw Exception("%s", strerror(errno));
  return st.st_size;
}
 
} // namespace geo_base
