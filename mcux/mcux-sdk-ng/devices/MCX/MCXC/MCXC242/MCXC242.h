/*
** ###################################################################
**     Processors:          MCXC242VFM
**                          MCXC242VLH
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXC242RM, Rev.1, Mar 2024
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXC242
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-05-12)
**         Initial version.
**     - rev. 1.1 (2014-07-10)
**         UART0 - UART0 module renamed to UART2.
**     - rev. 1.2 (2014-08-12)
**         CRC - CRC register renamed to DATA.
**     - rev. 1.3 (2014-09-02)
**         USB - USB0_CTL0 was renamed to USB0_OTGCTL register.
**         USB - USB0_CTL1 was renamed to USB0_CTL register.
**         USB - Two new bitfields (STOP_ACK_DLY_EN, AHB_DLY_EN) was added to the USB0_KEEP_ALIVE_CTRL register.
**     - rev. 1.4 (2014-09-22)
**         FLEXIO - Offsets of the SHIFTBUFBIS registers were interchanged with offsets of the SHIFTBUFBBS registers.
**         SIM - Changed bitfield value MCGIRCLK to LIRC_CLK of bitfield CLKOUTSEL in SOPT2 register.
**         SIM - Removed bitfield DIEID in SDID register.
**         UART2 - Removed ED register.
**         UART2 - Removed MODEM register.
**         UART2 - Removed IR register.
**         UART2 - Removed PFIFO register.
**         UART2 - Removed CFIFO register.
**         UART2 - Removed SFIFO register.
**         UART2 - Removed TWFIFO register.
**         UART2 - Removed TCFIFO register.
**         UART2 - Removed RWFIFO register.
**         UART2 - Removed RCFIFO register.
**         USB - Removed bitfield REG_EN in CLK_RECOVER_IRC_EN register.
**         USB - Renamed USBEN bitfield of USB0_CTL was renamed to USBENSOFEN.
**     - rev. 1.5 (2016-02-02)
**         FGPIO - Add FGPIO registers.
**     - rev. 1.6 (2016-06-24)
**         USB - OTGCTL register was removed.
**         USB - Bit RESUME was added in CTL register.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MCXC242.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCXC242
 *
 * CMSIS Peripheral Access Layer for MCXC242
 */

#if !defined(MCXC242_H_)  /* Check if memory map has not been already included */
#define MCXC242_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_CMP.h"
#include "PERI_CRC.h"
#include "PERI_DMA.h"
#include "PERI_DMAMUX.h"
#include "PERI_FGPIO.h"
#include "PERI_FLEXIO.h"
#include "PERI_FTFA.h"
#include "PERI_GPIO.h"
#include "PERI_I2C.h"
#include "PERI_LLWU.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MCG.h"
#include "PERI_MCM.h"
#include "PERI_MTB.h"
#include "PERI_MTBDWT.h"
#include "PERI_NV.h"
#include "PERI_OSC.h"
#include "PERI_PIT.h"
#include "PERI_PMC.h"
#include "PERI_PORT.h"
#include "PERI_RCM.h"
#include "PERI_RFSYS.h"
#include "PERI_ROM.h"
#include "PERI_RTC.h"
#include "PERI_SIM.h"
#include "PERI_SMC.h"
#include "PERI_SPI.h"
#include "PERI_TPM.h"
#include "PERI_UART.h"
#include "PERI_USB.h"
#include "PERI_VREF.h"

#endif  /* #if !defined(MCXC242_H_) */
