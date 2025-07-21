/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MIMXRT685 User manual Rev. 1.8 21 November 2024
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT633S
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT633S.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT633S
 *
 * CMSIS Peripheral Access Layer for MIMXRT633S
 */

#if !defined(MIMXRT633S_H_)  /* Check if memory map has not been already included */
#define MIMXRT633S_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AHB_SECURE_CTRL.h"
#include "PERI_CACHE64_CTRL.h"
#include "PERI_CACHE64_POLSEL.h"
#include "PERI_CASPER.h"
#include "PERI_CLKCTL0.h"
#include "PERI_CLKCTL1.h"
#include "PERI_CMP.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DMA.h"
#include "PERI_DMIC.h"
#include "PERI_ESPI.h"
#include "PERI_FLEXCOMM.h"
#include "PERI_FLEXSPI.h"
#include "PERI_FREQME.h"
#include "PERI_GPIO.h"
#include "PERI_HASHCRYPT.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOPCTL.h"
#include "PERI_MRT.h"
#include "PERI_MU.h"
#include "PERI_OCOTP.h"
#include "PERI_OSTIMER.h"
#include "PERI_OTFAD.h"
#include "PERI_PINT.h"
#include "PERI_PMC.h"
#include "PERI_POWERQUAD.h"
#include "PERI_PUF.h"
#include "PERI_RSTCTL0.h"
#include "PERI_RSTCTL1.h"
#include "PERI_RTC.h"
#include "PERI_SCT.h"
#include "PERI_SEMA42.h"
#include "PERI_SPI.h"
#include "PERI_SYSCTL0.h"
#include "PERI_SYSCTL1.h"
#include "PERI_TRNG.h"
#include "PERI_USART.h"
#include "PERI_USBHSD.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBHSH.h"
#include "PERI_USBPHY.h"
#include "PERI_USDHC.h"
#include "PERI_UTICK.h"
#include "PERI_WWDT.h"

#endif  /* #if !defined(MIMXRT633S_H_) */
