/*
** ###################################################################
**     Processors:          LPC5506JBD64
**                          LPC5506JHI48
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC55S0x/LPC550x User manual Rev.0.3  14 August 2020
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC5506
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-04-09)
**         Initial version based on Niobe4mini
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC5506.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPC5506
 *
 * CMSIS Peripheral Access Layer for LPC5506
 */

#if !defined(LPC5506_H_)  /* Check if memory map has not been already included */
#define LPC5506_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AHB_SECURE_CTRL.h"
#include "PERI_ANACTRL.h"
#include "PERI_CAN.h"
#include "PERI_CDOG.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DBGMAILBOX.h"
#include "PERI_DMA.h"
#include "PERI_FLASH.h"
#include "PERI_FLASH_CFPA.h"
#include "PERI_FLASH_CMPA.h"
#include "PERI_FLASH_KEY_STORE.h"
#include "PERI_FLASH_NMPA.h"
#include "PERI_FLASH_ROMPATCH.h"
#include "PERI_FLEXCOMM.h"
#include "PERI_GINT.h"
#include "PERI_GPIO.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOCON.h"
#include "PERI_MRT.h"
#include "PERI_OSTIMER.h"
#include "PERI_PINT.h"
#include "PERI_PLU.h"
#include "PERI_PMC.h"
#include "PERI_RNG.h"
#include "PERI_RTC.h"
#include "PERI_SCT.h"
#include "PERI_SPI.h"
#include "PERI_SYSCON.h"
#include "PERI_SYSCTL.h"
#include "PERI_USART.h"
#include "PERI_UTICK.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(LPC5506_H_) */
