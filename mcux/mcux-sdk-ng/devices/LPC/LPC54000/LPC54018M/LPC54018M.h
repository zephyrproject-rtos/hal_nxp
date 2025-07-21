/*
** ###################################################################
**     Processors:          LPC54018J2MET180
**                          LPC54018J4MET180
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC54018JxM/LPC54S018JxM User manual Rev.1.0 20 September 2018
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC54018M
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC54018M.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPC54018M
 *
 * CMSIS Peripheral Access Layer for LPC54018M
 */

#if !defined(LPC54018M_H_)  /* Check if memory map has not been already included */
#define LPC54018M_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_ASYNC_SYSCON.h"
#include "PERI_CAN.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DMA.h"
#include "PERI_DMIC.h"
#include "PERI_EMC.h"
#include "PERI_ENET.h"
#include "PERI_FLEXCOMM.h"
#include "PERI_GINT.h"
#include "PERI_GPIO.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOCON.h"
#include "PERI_LCD.h"
#include "PERI_MRT.h"
#include "PERI_OTPC.h"
#include "PERI_PINT.h"
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

#endif  /* #if !defined(LPC54018M_H_) */
