/**
 * @file 
 * @author Ryan Tu <tutuhuagong@gmail.com>
 * @date 2013/09/24
 * @version v0.1
 *
 * @section LICESE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or（at your option）any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * eneral Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "virtual_disk.h"

virtual_disk::virtual_disk(const char* disk_name, size_t num_pages)
    : num_pages_( num_pages ), disk_name_( const_cast<char*>(disk_name) )
{
    fd_ = ::open(disk_name_, O_RDWR | O_CREAT | O_EXCL | O_LARGEFILE, 0644);
    //TODO: log stream
    assert(fd_ >= 0);

    off64_t cur_pos = ::lseek64( fd_, (off64_t)num_pages * (off64_t)PAGESIZE - 1, SEEK_SET );
    assert( cur_pos == (off64_t)num_pages * (off64_t)PAGESIZE - 1 );

    char zero = 0;
    ssize_t size = writeall( fd_, &zero, sizeof(char) );
    if (1 != size) {
      //TODO: log
    }
    assert( size == 1 );
}

virtual_disk::~virtual_disk()
{
    disk_name_ = NULL;
    num_pages_ = 0;
    ::close( fd_ );
    fd_ = -1;
}

bool virtual_disk::read_page(PageId page_id, Page* page_ptr)
{
    off64_t offset = (off64_t)page_id * (off64_t)PAGESIZE;
    off64_t cur_pos = ::lseek64( fd_, offset, SEEK_SET);
    assert( cur_pos == offset );

    ssize_t size = readall( fd_, page_ptr, PAGESIZE);
    assert( size == PAGESIZE );

    return true;
}

bool virtual_disk::write_page(PageId page_id, Page* page_ptr)
{
    off64_t offset = (off64_t)page_id * (off64_t)PAGESIZE;
    off64_t cur_pos = ::lseek64( fd_, offset, SEEK_SET);
    assert( cur_pos == offset );

    ssize_t size = writeall( fd_, page_ptr, PAGESIZE);
    assert( size == PAGESIZE );

    return true;
}
