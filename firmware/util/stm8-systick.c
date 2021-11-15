//----------------------------------------------------------------------------
// STM8S System tick definitions to provide standard 
// library compliance (SysTick_Config).
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
// [02/11/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "../include/stm8.h"
#include "../include/stm8-systick.h"

#define SYSCLK_TIMER_PRESCALER			7	

volatile unsigned long systickovf_counter = 0;	

void TIMER4_OVR_ISR() __interrupt(TIMER4_TRIGGET_IRQ)
{
    TIM4_SR &= ~TIM4_SR1_UIF;
    systickovf_counter += 0x100;
}

void initSysTick()
{
    // Stop the timer and setup timer parameters.
    TIM4_CR1 = 0x80;

    // Set up the prescaler value.
    TIM4_PSCR = (SYSCLK_TIMER_PRESCALER & 0x07);

    // Reset the timer counter.
    TIM4_CNTR = 0;

    // Set auto reload register.
    TIM4_ARR = 0xFF;

    // Clear interrupt flag.
    TIM4_SR &= ~TIM4_SR1_UIF;

    // Enable overflow interrupt.
    TIM4_IER |= TIM4_IER_UIE;	

    // Restart the counter.
    TIM4_CR1 |= TIM4_CR1_CEN;
}

unsigned long sysClkTicks()
{
    unsigned long val1;
    unsigned char val2;

    do
    {
        val1 = systickovf_counter;
		val2 = TIM4_CNTR;	
	} 
    while (val1 != systickovf_counter);

	return (val1 | val2) << SYSCLK_TIMER_PRESCALER;    
}

void sysTickDelayMS(unsigned long ms)
{
    unsigned long startTime = sysClkTicks();
    ms *= (F_CPU / 1000);
    while (sysClkTicks() - startTime < ms) continue;	
}

void sysTickDelayUS(unsigned long us)
{
    unsigned long startTime = sysClkTicks();
    us *= (F_CPU / 1000000UL);	
    while (sysClkTicks() - startTime < us) continue;	
}