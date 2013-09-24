#ifndef _VIRTUAL_DISK_H_
#define _VIRTUAL_DISK_H_

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
 * @section DESCRIPTION
 *
 * This file contains definitions of virutal disk.
 * The virtual disk is an abstraction of a real file spilt into blocks/pages.
 */

#include <cstdlib>
#include <cstring>

#include <sys/stat.h>
#include <fcntl.h>

#include "common/sys_defs.h"
#include "io_wrapper.h"
#include "page.h"

class virtual_disk
{
public:
    virtual_disk(const char* disk_name, size_t num_pages);
    ~virtual_disk();

    bool read_page(PageId page_id, Page* page_ptr);
    bool write_page(PageId page_id, Page* page_ptr);

private:
    int fd_;
    size_t num_pages_;
    char* disk_name_;
};

#endif
