//----------------------------------------------------------------------------
// Base Ethernet controller for STM8 series MCUs.
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
// [23/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8_ETH_DRV_H
#define STM8_ETH_DRV_H

#include "../net.h"

// Ethernet data buffer size.
#define BUFFER_SIZE 700

// Enable ICMP to provide automatic reply to pings.
#define ETHLIB_ICMP 1

// Enable DHCP.
#define ETHLIB_DHCP 1

// Eathernet data buffer.
extern unsigned char ethernet_buffer[BUFFER_SIZE];

// Size of the Eathernet data buffer (this is equal to BUFFER_SIZE).
extern unsigned short ethernet_bufferSize;

// Device MAC address.
extern unsigned char ethernet_mymac[ETH_LEN];

// IP address of the device.
extern unsigned char ethernet_myip[IP_LEN];

// Subnet mask.
extern unsigned char ethernet_netmask[IP_LEN];

// Broadcast IP address.
extern unsigned char ethernet_broadcastip[IP_LEN];

// Gateway IP address.
extern unsigned char ethernet_gwip[IP_LEN];

// DNS server IP address.
extern unsigned char ethernet_dnsip[IP_LEN];

// IP address of the remote host.
extern unsigned char ethernet_hisip[IP_LEN];

// IP address of the DHCP server.
extern unsigned char ethernet_dhcpip[IP_LEN];

extern unsigned char network_using_dhcp;
extern unsigned short network_delaycnt;

unsigned char networkInit(const unsigned char* macaddr);
unsigned char networkStaticSetup(const unsigned char* my_ip, const unsigned char* gw_ip, const unsigned char* dns_ip, const unsigned char* mask);

#endif /* STM8_ETH_DRV_H */