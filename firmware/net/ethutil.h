//----------------------------------------------------------------------------
// Support utilities for network related functions.
// Copyright (C) 2021 Dilshan Jayakody.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//----------------------------------------------------------------------------
// Update log:
// [27/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8_NETWORK_UTIL_H
#define STM8_NETWORK_UTIL_H

void netutilCopyMac(unsigned char *dst, const unsigned char *src);
void netutilCopyIp(unsigned char *dst, const unsigned char *src);
unsigned char netNibbleToHexChar(unsigned char nibble);

#endif /* STM8_NETWORK_UTIL_H */