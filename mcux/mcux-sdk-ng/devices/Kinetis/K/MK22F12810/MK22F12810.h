/*
** ###################################################################
**     Processors:          MK22FN128VDC10
**                          MK22FN128VLH10
**                          MK22FN128VLL10
**                          MK22FN128VMP10
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    K22P121M100SF9RM, Rev. 1, April 25, 2014
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MK22F12810
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2013-11-01)
**         Initial version.
**     - rev. 1.1 (2013-12-20)
**         Update according to reference manual rev. 0.1,
**     - rev. 1.2 (2014-02-10)
**         The declaration of clock configurations has been moved to separate header file system_MK22F12810.h
**     - rev. 1.3 (2014-05-06)
**         Update according to reference manual rev. 1.0,
**         Update of system and startup files.
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**     - rev. 1.4 (2014-08-28)
**         Update of system files - default clock configuration changed.
**         Update of startup files - possibility to override DefaultISR added.
**     - rev. 1.5 (2014-10-14)
**         Interrupt INT_LPTimer renamed to INT_LPTMR0, interrupt INT_Watchdog renamed to INT_WDOG_EWM.
**     - rev. 1.6 (2015-02-19)
**         Renamed interrupt vector LLW to LLWU.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MK22F12810.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MK22F12810
 *
 * CMSIS Peripheral Access Layer for MK22F12810
 */

#if !defined(MK22F12810_H_)  /* Check if memory map has not been already included */
#define MK22F12810_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_CMP.h"
#include "PERI_CRC.h"
#include "PERI_DAC.h"
#include "PERI_DMA.h"
#include "PERI_DMAMUX.h"
#include "PERI_EWM.h"
#include "PERI_FMC.h"
#include "PERI_FTFA.h"
#include "PERI_FTM.h"
#include "PERI_GPIO.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_LLWU.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MCG.h"
#include "PERI_MCM.h"
#include "PERI_NV.h"
#include "PERI_OSC.h"
#include "PERI_PDB.h"
#include "PERI_PIT.h"
#include "PERI_PMC.h"
#include "PERI_PORT.h"
#include "PERI_RCM.h"
#include "PERI_RFSYS.h"
#include "PERI_RFVBAT.h"
#include "PERI_RTC.h"
#include "PERI_SIM.h"
#include "PERI_SMC.h"
#include "PERI_SPI.h"
#include "PERI_UART.h"
#include "PERI_USB.h"
#include "PERI_VREF.h"
#include "PERI_WDOG.h"

#endif  /* #if !defined(MK22F12810_H_) */
