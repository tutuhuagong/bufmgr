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
 * test virtual disk.
 */
 
#include <iostream>

#include "sys_defs.h"
#include "page.h"
#include "virtual_disk.h"

int test_virtual_disk()
{
    virtual_disk vd("test", 1024);
    Page page;
    for (int i = 0; i < PAGESIZE; i++) {
      page.data[i] = i % 26 + 'a';
    }
    vd.write_page(0, &page);

    Page outpage;
    vd.read_page(0, &outpage);
    for (int i = 0; i < PAGESIZE; i++) {
      if (outpage.data[i] != i % 26 + 'a') {
          std::cout<<"error reading"<<std::endl;
      } 
    }

    return 0;
}


