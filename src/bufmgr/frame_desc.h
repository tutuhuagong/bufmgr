#ifndef _FRAME_DESC_H_
#define _FRAME_DESC_H_

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
 * This file contains abstraction for frame entry of hash table.
 */
 
#include "common/sys_defs.h"

class frame_desc
{
public:
    frame_desc();
    ~frame_desc();
public:
    PageId page_id_;
    int prev_frame_no_;
    int next_frame_no_;
};

#endif
