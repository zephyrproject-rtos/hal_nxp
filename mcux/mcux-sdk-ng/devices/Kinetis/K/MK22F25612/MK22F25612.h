/*
** ###################################################################
**     Processors:          MK22FN128CAH12
**                          MK22FN256CAH12
**                          MK22FN256VDC12
**                          MK22FN256VLH12
**                          MK22FN256VLL12
**                          MK22FN256VMP12
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    K22P121M120SF8RM, Rev. 1, March 24, 2014
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MK22F25612
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2013-09-17)
**         Initial version.
**     - rev. 1.1 (2013-10-29)
**         Definition of BITBAND macros updated to support peripherals with 32-bit acces disabled.
**     - rev. 1.2 (2013-12-20)
**         Update according to reference manual rev. 0.6,
**     - rev. 1.3 (2014-02-06)
**         Update according to reference manual rev. 0.61,
**     - rev. 1.4 (2014-02-10)
**         The declaration of clock configurations has been moved to separate header file system_MK22F25612.h
**     - rev. 1.5 (2014-04-30)
**         Update of MCM and USB modules according to the RM rev. 1.
**         Update of system and startup files.
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**     - rev. 1.6 (2014-08-28)
**         Update of system files - default clock configuration changed.
**         Update of startup files - possibility to override DefaultISR added.
**     - rev. 1.7 (2014-10-14)
**         Interrupt INT_LPTimer renamed to INT_LPTMR0, interrupt INT_Watchdog renamed to INT_WDOG_EWM.
**     - rev. 1.8 (2015-02-19)
**         Renamed interrupt vector LLW to LLWU.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MK22F25612.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MK22F25612
 *
 * CMSIS Peripheral Access Layer for MK22F25612
 */

#if !defined(MK22F25612_H_)  /* Check if memory map has not been already included */
#define MK22F25612_H_

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
#include "PERI_RNG.h"
#include "PERI_RTC.h"
#include "PERI_SIM.h"
#include "PERI_SMC.h"
#include "PERI_SPI.h"
#include "PERI_UART.h"
#include "PERI_USB.h"
#include "PERI_VREF.h"
#include "PERI_WDOG.h"

#endif  /* #if !defined(MK22F25612_H_) */
