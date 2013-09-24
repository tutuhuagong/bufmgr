#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

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
 * 
 */
 
#include "bufmgr/frame_desc.h"

class hash_table {
public:
  hash_table ();
  virtual ~hash_table ();

  int hash(PageId page_id);
  int lookup(PageId page_id);
  int insert(

private:
  std::vector<frame_desc> ht_;
  std::size_t ht_size_; // 2*hash_size_ by default
  std::size_t hash_size_;
};


#endif
