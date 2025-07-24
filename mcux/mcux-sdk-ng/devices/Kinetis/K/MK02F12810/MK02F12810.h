/*
** ###################################################################
**     Processors:          MK02FN128VFM10
**                          MK02FN128VLF10
**                          MK02FN128VLH10
**                          MK02FN64VFM10
**                          MK02FN64VLF10
**                          MK02FN64VLH10
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    K02P64M100SFARM, Rev. 0, February 14, 2014
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MK02F12810
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2014-02-24)
**         Initial version
**     - rev. 0.2 (2014-07-15)
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         Update of system and startup files.
**     - rev. 0.3 (2014-08-28)
**         Update of system files - default clock configuration changed.
**         Update of startup files - possibility to override DefaultISR added.
**     - rev. 0.4 (2014-10-14)
**         Interrupt INT_LPTimer renamed to INT_LPTMR0, interrupt INT_Watchdog renamed to INT_WDOG_EWM.
**     - rev. 0.5 (2015-02-19)
**         Renamed interrupt vector LLW to LLWU.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MK02F12810.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MK02F12810
 *
 * CMSIS Peripheral Access Layer for MK02F12810
 */

#if !defined(MK02F12810_H_)  /* Check if memory map has not been already included */
#define MK02F12810_H_

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
#include "PERI_LLWU.h"
#include "PERI_LPTMR.h"
#include "PERI_MCG.h"
#include "PERI_MCM.h"
#include "PERI_NV.h"
#include "PERI_OSC.h"
#include "PERI_PDB.h"
#include "PERI_PIT.h"
#include "PERI_PMC.h"
#include "PERI_PORT.h"
#include "PERI_RCM.h"
#include "PERI_SIM.h"
#include "PERI_SMC.h"
#include "PERI_SPI.h"
#include "PERI_UART.h"
#include "PERI_VREF.h"
#include "PERI_WDOG.h"

#endif  /* #if !defined(MK02F12810_H_) */
