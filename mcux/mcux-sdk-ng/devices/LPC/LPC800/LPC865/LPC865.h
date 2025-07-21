/*
** ###################################################################
**     Processors:          LPC865M201JBD64
**                          LPC865M201JHI33
**                          LPC865M201JHI48
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC86x User manual Rev.1  March 2022
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC865
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.0 (2021-07-15)
**         Initial version.
**     - rev. 1.0 (2022-03-15)
**         Revesion of Rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC865.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPC865
 *
 * CMSIS Peripheral Access Layer for LPC865
 */

#if !defined(LPC865_H_)  /* Check if memory map has not been already included */
#define LPC865_H_

/* IP Header Files List */
#include "PERI_ACOMP.h"
#include "PERI_ADC.h"
#include "PERI_CRC.h"
#include "PERI_DMA.h"
#include "PERI_FLASH_CTRL.h"
#include "PERI_FTM.h"
#include "PERI_GPIO.h"
#include "PERI_I2C.h"
#include "PERI_I3C.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOCON.h"
#include "PERI_MRT.h"
#include "PERI_PINT.h"
#include "PERI_PMU.h"
#include "PERI_SPI.h"
#include "PERI_SWM.h"
#include "PERI_SYSCON.h"
#include "PERI_USART.h"
#include "PERI_WKT.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(LPC865_H_) */
