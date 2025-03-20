/*
** ###################################################################
**     Processors:          LPC54S005JBD100
**                          LPC54S005JET100
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC540xx/LPC54S0xx User manual Rev.0.8 5 June 2018
**     Version:             rev. 1.2, 2017-06-08
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC54S005
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
 * @file LPC54S005.h
 * @version 1.2
 * @date 2017-06-08
 * @brief CMSIS Peripheral Access Layer for LPC54S005
 *
 * CMSIS Peripheral Access Layer for LPC54S005
 */

#if !defined(LPC54S005_H_)  /* Check if memory map has not been already included */
#define LPC54S005_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AES.h"
#include "PERI_ASYNC_SYSCON.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DMA.h"
#include "PERI_DMIC.h"
#include "PERI_EMC.h"
#include "PERI_FLEXCOMM.h"
#include "PERI_GINT.h"
#include "PERI_GPIO.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOCON.h"
#include "PERI_MRT.h"
#include "PERI_OTPC.h"
#include "PERI_PINT.h"
#include "PERI_PUF.h"
#include "PERI_RIT.h"
#include "PERI_RTC.h"
#include "PERI_SCT.h"
#include "PERI_SDIF.h"
#include "PERI_SHA.h"
#include "PERI_SMARTCARD.h"
#include "PERI_SPI.h"
#include "PERI_SPIFI.h"
#include "PERI_SYSCON.h"
#include "PERI_USART.h"
#include "PERI_USB.h"
#include "PERI_USBFSH.h"
#include "PERI_USBHSD.h"
#include "PERI_USBHSH.h"
#include "PERI_UTICK.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(LPC54S005_H_) */
