#ifndef _IO_WRAPPER_H_
#define _IO_WAPPER_H_

/**
 * @file io_wrapper.h
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
 * This file contains wrappers for unix syscall.
 */

#include <errno.h>
#include <unistd.h>

extern ssize_t readall(int fd, void* buf, size_t nbyte);
extern ssize_t  writeall(int fd, void* buf, size_t nbyte);

#endif //_IO_WRAPPER_H_
