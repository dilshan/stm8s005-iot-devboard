//----------------------------------------------------------------------------
// Example application to test the onboard buzzer of the STM8S005 IoT 
// development board.
//----------------------------------------------------------------------------

#include "include/stm8.h"
#include "include/stm8-uart.h"
#include "include/stm8-util.h"
#include "include/stm8-dbglog.h"
#include "include/stm8-systick.h"
#include "include/stm8-bell.h"
#include "include/stm8-adc.h"

// Used for stm8-systick libaray to drive time related functions (optional).
void TIMER4_OVR_ISR() __interrupt(TIMER4_TRIGGET_IRQ);

void main()
{
    // Activate the interrupts.
    cli();
    sei();

    // Initialize SysTick related timer and variables.
    initSysTick();

    // Initialize UART as debug log terminal.
    uartInit();

    debugPrintLn("START BELL TEST");

    STM8_BELL_OFF;

    while (1)
    {
        // Turn on the bell and wait for 1 second.
        STM8_BELL_ON;
        delay_ms(1000);

        // Turn off the bell and wait for 1 second.
        STM8_BELL_OFF;
        delay_ms(1000);
    }    
}