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

#include <geo_base/library/base_allocator.h>
#include <geo_base/library/memory.h>

#include <errno.h>

namespace geo_base {

base_allocator_t::base_allocator_t(char const *path)
{
    read_write_open(path);
    setup(data(), size());
}

void *base_allocator_t::allocate(size_t count)
{
    if (ftruncate(fd(), total_allocated_size() + allocate_size(count)) < 0)
        throw exception_t("Unable ftrancate: %s", strerror(errno));
    return block_allocator_t::allocate(count);
}

void base_allocator_t::deallocate(void *ptr, size_t count)
{
    block_allocator_t::deallocate(ptr, count);
    if (ftruncate(fd(), total_allocated_size()) < 0)
        throw exception_t("Unable ftrancate: %s", strerror(errno));
}

} // namespace geo_base
