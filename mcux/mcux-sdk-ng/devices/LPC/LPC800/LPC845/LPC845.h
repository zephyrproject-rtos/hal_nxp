/*
** ###################################################################
**     Processors:          LPC845M301JBD48
**                          LPC845M301JBD64
**                          LPC845M301JHI33
**                          LPC845M301JHI48
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC84x User manual Rev.1.6  8 Dec 2017
**     Version:             rev. 1.2, 2017-06-08
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC845
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**
** ###################################################################
*/

/*!
 * @file LPC845.h
 * @version 1.2
 * @date 2017-06-08
 * @brief CMSIS Peripheral Access Layer for LPC845
 *
 * CMSIS Peripheral Access Layer for LPC845
 */

#if !defined(LPC845_H_)  /* Check if memory map has not been already included */
#define LPC845_H_

/* IP Header Files List */
#include "PERI_ACOMP.h"
#include "PERI_ADC.h"
#include "PERI_CAPT.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DAC.h"
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

#endif  /* #if !defined(LPC845_H_) */
