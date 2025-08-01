/*
** ###################################################################
**     Processors:          LPC822M101JDH20
**                          LPC822M101JHI33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC82x User manual Rev.1.2  5 October 2016
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC822
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-02-09)
**         Initial version.
**     - rev. 1.1 (2018-02-25)
**         Update some registers according to UM rev 1.2
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC822.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPC822
 *
 * CMSIS Peripheral Access Layer for LPC822
 */

#if !defined(LPC822_H_)  /* Check if memory map has not been already included */
#define LPC822_H_

/* IP Header Files List */
#include "PERI_ACOMP.h"
#include "PERI_ADC.h"
#include "PERI_CRC.h"
#include "PERI_DMA.h"
#include "PERI_FLASH_CTRL.h"
#include "PERI_GPIO.h"
#include "PERI_I2C.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOCON.h"
#include "PERI_MRT.h"
#include "PERI_MTB.h"
#include "PERI_PINT.h"
#include "PERI_PMU.h"
#include "PERI_SCT.h"
#include "PERI_SPI.h"
#include "PERI_SWM.h"
#include "PERI_SYSCON.h"
#include "PERI_USART.h"
#include "PERI_WKT.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(LPC822_H_) */
