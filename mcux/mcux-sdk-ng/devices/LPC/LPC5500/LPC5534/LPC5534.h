/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC55S3x Reference Manual Rev. DraftG, 07/2021
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC5534
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC5534.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPC5534
 *
 * CMSIS Peripheral Access Layer for LPC5534
 */

#if !defined(LPC5534_H_)  /* Check if memory map has not been already included */
#define LPC5534_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_ANACTRL.h"
#include "PERI_AOI.h"
#include "PERI_CACHE64_CTRL.h"
#include "PERI_CACHE64_POLSEL.h"
#include "PERI_CAN.h"
#include "PERI_CDOG.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DEBUGGER_MAILBOX.h"
#include "PERI_DMA.h"
#include "PERI_DMIC.h"
#include "PERI_ENC.h"
#include "PERI_FLASH.h"
#include "PERI_FLEXCOMM.h"
#include "PERI_FLEXSPI.h"
#include "PERI_FREQME.h"
#include "PERI_GINT.h"
#include "PERI_GPIO.h"
#include "PERI_HSCMP.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOCON.h"
#include "PERI_LPDAC.h"
#include "PERI_MRT.h"
#include "PERI_OPAMP.h"
#include "PERI_OSTIMER.h"
#include "PERI_PINT.h"
#include "PERI_PMC.h"
#include "PERI_POWERQUAD.h"
#include "PERI_PWM.h"
#include "PERI_RTC.h"
#include "PERI_SCT.h"
#include "PERI_SPI.h"
#include "PERI_SYSCON.h"
#include "PERI_SYSCTL.h"
#include "PERI_USART.h"
#include "PERI_USB.h"
#include "PERI_USBFSH.h"
#include "PERI_UTICK.h"
#include "PERI_VREF.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(LPC5534_H_) */
