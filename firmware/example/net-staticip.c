//----------------------------------------------------------------------------
// Example application to demonstrate establishing a static IP connection 
// using the STM8S005 IoT development board/firmware library.
//----------------------------------------------------------------------------

#include "include/stm8.h"
#include "include/stm8-uart.h"
#include "include/stm8-util.h"
#include "include/stm8-dbglog.h"
#include "include/stm8-systick.h"

#include "net/drivers/dhcp.h"
#include "net/drivers/ethernet.h"
#include "net/drivers/ipstack.h"
#include "net/ethutil.h"
#include "net/drivers/enc28j60/enc28j60.h"

// Used for stm8-systick libaray to drive time related functions.
void TIMER4_OVR_ISR() __interrupt(TIMER4_TRIGGET_IRQ);

void main()
{
    // Minimum buffer size: 300

    // Set mac address as 74:69:69:2d:30:31.
    static unsigned char mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

    // Set static IP address as 192.168.1.17.
    static unsigned char myip[] = { 192,168,1,17 };

    // Set subnet mask to 255.255.255.0.
    static unsigned char mask[] = { 255,255,255,0 };

    // Set gateway IP address as 192.168.1.1.
    static unsigned char gwip[] = { 192,168,1,1 };

    // Set server IP address as 74.125.79.99 (Google).
    static unsigned char hisip[] = { 74,125,79,99 };
    
    // Initialize UART as debug log terminal.
    uartInit();

    debugPrintLn("START ETH TEST");

    // Initialize ENC28J60 Ethernet interface.
    unsigned char status = networkInit(mymac);
    if(status == 0)
    {
        // Network initialization fail, is ENC28J60 is online?
        debugPrintLn("INIT FAIL");
        while(1);
    }

    debugPrintLn("SETUP IP");

    // Setup static IP.
    networkStaticSetup(myip, gwip, 0, mask);
    debugPrintLn("IP FINISH");

    // Try to find the gatway...
    netutilCopyIp(ethernet_hisip, hisip);
    while (networkClientWaitingGw())
    {
        networkPacketLoop(enc28j60PacketReceive());
    }

    debugPrintLn("Gateway found");

    // Service loop to process incoming network data packets.
    while(1)
    {
        networkPacketLoop(enc28j60PacketReceive());
    }
}