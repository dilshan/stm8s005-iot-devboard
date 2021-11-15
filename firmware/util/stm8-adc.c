//----------------------------------------------------------------------------
// STM8S Analog to digital conversion library.
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
// [24/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "../include/stm8.h"
#include "../include/stm8-adc.h"

void adcInit(unsigned char initChannel)
{
    adcSetChannel(initChannel);
    
    // Converted value is in right alignment mode.
    ADC_CR2 |= ADC1_CR2_ALIGN; 

    // Turn on ADC unit in highest available speed (Master Clock / 2 mode).
    ADC_CR1 = ADC1_CR1_ADON;       
}

unsigned short adcRead()
{
    unsigned char adcValHi, adcVallo;
    
    // Trigger the start of conversion.
    ADC_CR1 |= ADC1_CR1_ADON;  

    // Wait until the converion is finished.
    while (!(ADC_CSR & ADC1_CSR_EOC));

    // Extract 10-bit ADC value.
    adcVallo = ADC_DRL;
    adcValHi = ADC_DRH;

    // Reset end of conversion flag.
    ADC_CSR &= ~(ADC1_CSR_EOC);

    return (adcVallo | (adcValHi << 8));
}