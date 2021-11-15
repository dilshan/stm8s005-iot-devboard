//----------------------------------------------------------------------------
// DHCP client for STM8 series MCUs.
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
// [28/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "dhcp.h"
#include "ethernet.h"
#include "ipstack.h"
#include "enc28j60/enc28j60.h"
#include "../net.h"
#include "../ethutil.h"

#include "../../include/stm8.h"
#include "../../include/stm8-systick.h"

#include <stdlib.h>
#include <string.h>

// RFC 2132 Section 3.3: The time value of 0xffffffff is reserved to represent "infinity".
#define DHCP_INFINITE_LEASE  0xffffffff     

// Timeouts im ms.
#define DHCP_REQUEST_TIMEOUT 10000

#define DHCP_BOOTREQUEST    1
#define DHCP_BOOTRESPONSE   2

// DHCP Message Type (option 53) (RFC 2132).
#define DHCP_DISCOVER 1
#define DHCP_OFFER 2
#define DHCP_REQUEST 3
#define DHCP_DECLINE 4
#define DHCP_ACK 5
#define DHCP_NAK 6
#define DHCP_RELEASE 7

// Options used (both send and receive).
#define DHCP_OPT_SUBNET_MASK            1
#define DHCP_OPT_ROUTERS                3
#define DHCP_OPT_DOMAIN_NAME_SERVERS    6
#define DHCP_OPT_HOSTNAME               12
#define DHCP_OPT_REQUESTED_ADDRESS      50
#define DHCP_OPT_LEASE_TIME             51
#define DHCP_OPT_MESSAGE_TYPE           53
#define DHCP_OPT_SERVER_IDENTIFIER      54
#define DHCP_OPT_PARAMETER_REQUEST_LIST 55
#define DHCP_OPT_RENEWAL_TIME           58
#define DHCP_OPT_CLIENT_IDENTIFIER      61
#define DHCP_OPT_END                    255

#define DHCP_HTYPE_ETHER 1
#define DHCP_HOSTNAME_MAX_LEN 32

#define DHCP_SERVER_PORT 67
#define DHCP_CLIENT_PORT 68

// Reference to eathernet data buffer.
#define gPB ethernet_buffer

enum 
{
    DHCP_STATE_INIT,
    DHCP_STATE_SELECTING,
    DHCP_STATE_REQUESTING,
    DHCP_STATE_BOUND,
    DHCP_STATE_RENEWING,
};

typedef struct 
{
    unsigned char op, htype, hlen, hops;
    unsigned long xid;
    unsigned short secs, flags;
    unsigned char ciaddr[IP_LEN], yiaddr[IP_LEN], siaddr[IP_LEN], giaddr[IP_LEN];
    unsigned char chaddr[16], sname[64], file[128];
} DHCPdata;

static char dhcp_hostname[DHCP_HOSTNAME_MAX_LEN] = "SriKIT-ECntrl-00";
static unsigned char dhcp_dhcpState = DHCP_STATE_INIT;
static unsigned long dhcp_leaseTime;
static unsigned long dhcp_leaseStart;
static unsigned long dhcp_stateTimer;
static unsigned long dhcp_currentXid;
static unsigned char* dhcp_bufPtr;

extern unsigned char tcpip_allOnes[];

static void addToBuf(unsigned char b) 
{
    *dhcp_bufPtr++ = b;
}

static void addBytes(unsigned char len, const unsigned char* data) 
{
    while (len-- > 0)
        addToBuf(*data++);
}

static void addOption(unsigned char opt, unsigned char len, const unsigned char* data) 
{
    addToBuf(opt);
    addToBuf(len);
    addBytes(len, data);
}

static char toAsciiHex(unsigned char b) 
{
    char c = b & 0x0f;
    c += (c <= 9) ? '0' : 'A'-10;
    return c;
}

static void send_dhcp_message(unsigned char *requestip) 
{
    memset(gPB, 0, UDP_DATA_P + sizeof(DHCPdata));

    networkUdpPrepare(DHCP_CLIENT_PORT, (dhcp_dhcpState == DHCP_STATE_BOUND ? ethernet_dhcpip : tcpip_allOnes), DHCP_SERVER_PORT);
    netutilCopyMac(gPB + ETH_DST_MAC, tcpip_allOnes);

    // Build DHCP Packet from buffer.
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);
    dhcpPtr->op = DHCP_BOOTREQUEST;
    dhcpPtr->htype = 1;
    dhcpPtr->hlen = 6;
    dhcpPtr->xid = dhcp_currentXid;

    if (dhcp_dhcpState == DHCP_STATE_BOUND) 
    {
        netutilCopyIp(dhcpPtr->ciaddr, ethernet_myip);
    }

    netutilCopyMac(dhcpPtr->chaddr, ethernet_mymac);

    dhcp_bufPtr = gPB + UDP_DATA_P + sizeof( DHCPdata );

    static const unsigned char cookie[] = { 0x63,0x82,0x53,0x63 };
    for (unsigned char i = 0; i < sizeof(cookie); i++)
        addToBuf(cookie[i]);

    addToBuf(DHCP_OPT_MESSAGE_TYPE); 
    addToBuf(1);
    addToBuf(dhcp_dhcpState == DHCP_STATE_INIT ? DHCP_DISCOVER : DHCP_REQUEST);

    addToBuf(DHCP_OPT_CLIENT_IDENTIFIER);
    addToBuf(1 + ETH_LEN);
    addToBuf(DHCP_HTYPE_ETHER);
    addBytes(ETH_LEN, ethernet_mymac);

    if (dhcp_hostname[0]) 
    {
        addOption(DHCP_OPT_HOSTNAME, strlen(dhcp_hostname), (unsigned char*) dhcp_hostname);
    }

    if (requestip != NULL) 
    {
        addOption(DHCP_OPT_REQUESTED_ADDRESS, IP_LEN, requestip);
        addOption(DHCP_OPT_SERVER_IDENTIFIER, IP_LEN, ethernet_dhcpip);
    }

    addToBuf(DHCP_OPT_PARAMETER_REQUEST_LIST);
    // Length (count) of the requested DHCP options.
    addToBuf(3);
    addToBuf(DHCP_OPT_SUBNET_MASK);
    addToBuf(DHCP_OPT_ROUTERS);
    addToBuf(DHCP_OPT_DOMAIN_NAME_SERVERS);
    addToBuf(DHCP_OPT_END);

    // Packet size will be under 300 bytes.
    networkUdpTransmit((dhcp_bufPtr - gPB) - UDP_DATA_P);
}

static void process_dhcp_ack(unsigned short len) 
{
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);

    netutilCopyIp(ethernet_myip, dhcpPtr->yiaddr);

    unsigned char *ptr = (unsigned char*) (dhcpPtr + 1) + 4;
    unsigned char done = 0;

    do 
    {
        unsigned char option = *ptr++;
        unsigned char optionLen = *ptr++;

        switch (option) 
        {
        case DHCP_OPT_SUBNET_MASK:
            netutilCopyIp(ethernet_netmask, ptr);
            break;
        case DHCP_OPT_ROUTERS:
            netutilCopyIp(ethernet_gwip, ptr);
            break;
        case DHCP_OPT_DOMAIN_NAME_SERVERS:
            netutilCopyIp(ethernet_dnsip, ptr);
            break;
        case DHCP_OPT_LEASE_TIME:
        case DHCP_OPT_RENEWAL_TIME:
            dhcp_leaseTime = 0;
            for (unsigned char i = 0; i<4; i++)
                dhcp_leaseTime = (dhcp_leaseTime << 8) + ptr[i];

            if (dhcp_leaseTime != DHCP_INFINITE_LEASE) 
            {
                dhcp_leaseTime *= 1000;
            }
            break;
        case DHCP_OPT_END:
            done = 1;
            break;           
        }

        ptr += optionLen;
    }
    while (!done && ptr < gPB + len);
}

static void process_dhcp_offer(unsigned short len, unsigned char *offeredip) 
{
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);

    netutilCopyIp(offeredip, dhcpPtr->yiaddr);

    unsigned char *ptr = (unsigned char*)(dhcpPtr + 1) + 4;
    do 
    {
        unsigned char option = *ptr++;
        unsigned char optionLen = *ptr++;

        if (option == DHCP_OPT_SERVER_IDENTIFIER) 
        {
            netutilCopyIp(ethernet_dhcpip, ptr);
            break;
        }

        ptr += optionLen;
    } 
    while (ptr < gPB + len);
}

static unsigned char dhcp_received_message_type(unsigned short len, unsigned char msgType) 
{
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);

    if (len >= 70 && gPB[UDP_SRC_PORT_L_P] == DHCP_SERVER_PORT && dhcpPtr->xid == dhcp_currentXid) 
    {
        unsigned char *ptr = (unsigned char*) (dhcpPtr + 1) + 4;
        do 
        {
            unsigned char option = *ptr++;
            unsigned char optionLen = *ptr++;
            if(option == DHCP_OPT_MESSAGE_TYPE && *ptr == msgType ) 
            {
                return 1;
            }

            ptr += optionLen;
        } 
        while (ptr < gPB + len);
    }

    return 0;
}

void ethernetDhcpStateMachine(unsigned short len)
{
    switch (dhcp_dhcpState) 
    {

    case DHCP_STATE_BOUND:
        // DHCP renewal may not larger than 49 days.
        if (dhcp_leaseTime != DHCP_INFINITE_LEASE && millis() - dhcp_leaseStart >= dhcp_leaseTime) 
        {
            send_dhcp_message(ethernet_myip);
            dhcp_dhcpState = DHCP_STATE_RENEWING;
            dhcp_stateTimer = millis();
        }
        break;

    case DHCP_STATE_INIT:
        dhcp_currentXid = millis();
        memset(ethernet_myip,0,IP_LEN);
        send_dhcp_message(NULL);
        enc28j60EnableBroadcast(1);
        dhcp_dhcpState = DHCP_STATE_SELECTING;
        dhcp_stateTimer = millis();
        break;

    case DHCP_STATE_SELECTING:
        if (dhcp_received_message_type(len, DHCP_OFFER)) 
        {
            unsigned char offeredip[IP_LEN];
            process_dhcp_offer(len, offeredip);
            send_dhcp_message(offeredip);
            dhcp_dhcpState = DHCP_STATE_REQUESTING;
            dhcp_stateTimer = millis();
        } 
        else 
        {
            if (millis() - dhcp_stateTimer > DHCP_REQUEST_TIMEOUT) 
            {
                dhcp_dhcpState = DHCP_STATE_INIT;
            }
        }
        break;

    case DHCP_STATE_REQUESTING:
    case DHCP_STATE_RENEWING:
        if (dhcp_received_message_type(len, DHCP_ACK)) 
        {
            enc28j60DisableBroadcast(1);
            process_dhcp_ack(len);
            dhcp_leaseStart = millis();
            if (ethernet_gwip[0] != 0) networkSetGwIp(ethernet_gwip); 
            dhcp_dhcpState = DHCP_STATE_BOUND;
        } 
        else 
        {
            if (millis() - dhcp_stateTimer > DHCP_REQUEST_TIMEOUT) 
            {
                dhcp_dhcpState = DHCP_STATE_INIT;
            }
        }
        break;

    }
}

unsigned char networkDhcpSetup(const unsigned char *hname) 
{
    network_using_dhcp = 1;

    if(hname != NULL) 
    {
        strncpy(dhcp_hostname, hname, DHCP_HOSTNAME_MAX_LEN);
    }
    else 
    {
        dhcp_hostname[strlen(dhcp_hostname) - 2] = toAsciiHex(ethernet_mymac[5] >> 4);  
        dhcp_hostname[strlen(dhcp_hostname) - 1] = toAsciiHex(ethernet_mymac[5]);
    }

    dhcp_dhcpState = DHCP_STATE_INIT;
    unsigned short start = millis();

    while ((dhcp_dhcpState != DHCP_STATE_BOUND) && ((unsigned short)(millis()) - start < 60000)) 
    {
        if (enc28j60IsLinkUp()) ethernetDhcpStateMachine(enc28j60PacketReceive());
    }

    networkUpdateBroadcastAddress();
    network_delaycnt = 0;
    return dhcp_dhcpState == DHCP_STATE_BOUND;
}