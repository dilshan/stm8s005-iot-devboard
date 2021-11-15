//----------------------------------------------------------------------------
// STM8S001J3 ADC definitions for SDCC.
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
// [01/11/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S001_ADC1_DEF_H
#define STM8S001_ADC1_DEF_H

#define  ADC1_CSR_RESET_VALUE       ((unsigned char)0x00)   // CSR reset value.
#define  ADC1_CR1_RESET_VALUE       ((unsigned char)0x00)   // CR1 reset value.
#define  ADC1_CR2_RESET_VALUE       ((unsigned char)0x00)   // CR2 reset value.
#define  ADC1_CR3_RESET_VALUE       ((unsigned char)0x00)   // CR3 reset value.
#define  ADC1_TDRL_RESET_VALUE      ((unsigned char)0x00)   // TDRL reset value.
#define  ADC1_TDRH_RESET_VALUE      ((unsigned char)0x00)   // TDRH reset value.
#define  ADC1_HTRL_RESET_VALUE      ((unsigned char)0x03)   // HTRL reset value.
#define  ADC1_HTRH_RESET_VALUE      ((unsigned char)0xFF)   // HTRH reset value.
#define  ADC1_LTRH_RESET_VALUE      ((unsigned char)0x00)   // LTRH reset value.
#define  ADC1_LTRL_RESET_VALUE      ((unsigned char)0x00)   // LTRL reset value.
#define  ADC1_AWCRH_RESET_VALUE     ((unsigned char)0x00)   // AWCRH reset value.
#define  ADC1_AWCRL_RESET_VALUE     ((unsigned char)0x00)   // AWCRL reset value.

#define ADC1_CSR_EOC        ((unsigned char)0x80)   // End of Conversion mask.
#define ADC1_CSR_AWD        ((unsigned char)0x40)   // Analog Watch Dog Status mask.
#define ADC1_CSR_EOCIE      ((unsigned char)0x20)   // Interrupt Enable for EOC mask.
#define ADC1_CSR_AWDIE      ((unsigned char)0x10)   // Analog Watchdog interrupt enable mask.
#define ADC1_CSR_CH         ((unsigned char)0x0F)   // Channel selection bits mask.

#define ADC1_CR1_SPSEL      ((unsigned char)0x70)   // Prescaler selection mask.
#define ADC1_CR1_CONT       ((unsigned char)0x02)   // Continuous conversion mask.
#define ADC1_CR1_ADON       ((unsigned char)0x01)   // A/D Converter on/off mask.
 
#define ADC1_CR2_EXTTRIG    ((unsigned char)0x40)   // External trigger enable mask.
#define ADC1_CR2_EXTSEL     ((unsigned char)0x30)   // External event selection mask.
#define ADC1_CR2_ALIGN      ((unsigned char)0x08)   // Data Alignment mask.
#define ADC1_CR2_SCAN       ((unsigned char)0x02)   // Scan mode mask.
 
#define ADC1_CR3_DBUF       ((unsigned char)0x80)   // Data Buffer Enable mask.
#define ADC1_CR3_OVR        ((unsigned char)0x40)   // Overrun Status Flag mask.

#endif /* STM8S001_ADC1_DEF_H */