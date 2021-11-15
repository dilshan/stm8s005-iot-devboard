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

#include "ethernet.h"
#include "enc28j60/enc28j60.h"
#include "ipstack.h"
#include "../net.h"
#include "../ethutil.h"

unsigned char ethernet_buffer[BUFFER_SIZE];
unsigned short ethernet_bufferSize;

unsigned char ethernet_mymac[ETH_LEN];          // Device MAC address.
unsigned char ethernet_myip[IP_LEN];            // IP address of the device.
unsigned char ethernet_netmask[IP_LEN];         // Subnet mask.
unsigned char ethernet_broadcastip[IP_LEN];     // Broadcast IP address.
unsigned char ethernet_gwip[IP_LEN];            // Gateway IP address.
unsigned char ethernet_dnsip[IP_LEN];           // DNS server IP address.
unsigned char ethernet_hisip[IP_LEN];           // IP address of the remote host.
unsigned char ethernet_dhcpip[IP_LEN];          // IP address of the DHCP server.

unsigned char network_using_dhcp = 0;
unsigned short network_delaycnt = 0;

unsigned char networkInit(const unsigned char* macaddr) 
{
    network_using_dhcp = 0;
    ethernet_bufferSize = BUFFER_SIZE;
    
    netutilCopyMac(ethernet_mymac, macaddr);
    return enc28j60Init(ethernet_mymac);
}

unsigned char networkStaticSetup(const unsigned char* my_ip, const unsigned char* gw_ip, const unsigned char* dns_ip, const unsigned char* mask)
{
    network_using_dhcp = 0;

    if (my_ip != 0)
        netutilCopyIp(ethernet_myip, my_ip);

    if (gw_ip != 0)
        networkSetGwIp(gw_ip);

    if (dns_ip != 0)
        netutilCopyIp(ethernet_dnsip, dns_ip);

    if(mask != 0)
        netutilCopyIp(ethernet_netmask, mask);

    networkUpdateBroadcastAddress();

    // Request gateway ARP lookup.
    network_delaycnt = 0; 
    return 1;
}