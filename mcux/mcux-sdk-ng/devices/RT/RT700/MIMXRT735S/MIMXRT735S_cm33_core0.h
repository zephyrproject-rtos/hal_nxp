/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGFOA_cm33_core0
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    iMXRT700RM Rev.2 DraftA, 05/2024
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT735S_cm33_core0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT735S_cm33_core0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT735S_cm33_core0
 *
 * CMSIS Peripheral Access Layer for MIMXRT735S_cm33_core0
 */

#if !defined(MIMXRT735S_cm33_core0_H_)  /* Check if memory map has not been already included */
#define MIMXRT735S_cm33_core0_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AHBSC0.h"
#include "PERI_AHBSC3.h"
#include "PERI_AHBSC4.h"
#include "PERI_CACHE64_CTRL.h"
#include "PERI_CACHE64_POLSEL.h"
#include "PERI_CDOG.h"
#include "PERI_CLKCTL0.h"
#include "PERI_CLKCTL2.h"
#include "PERI_CLKCTL3.h"
#include "PERI_CLKCTL4.h"
#include "PERI_CMP.h"
#include "PERI_CRC.h"
#include "PERI_CTIMER.h"
#include "PERI_DEBUG_MAILBOX.h"
#include "PERI_DMA.h"
#include "PERI_ELS.h"
#include "PERI_FLEXIO.h"
#include "PERI_FREQME.h"
#include "PERI_FRO.h"
#include "PERI_GDET.h"
#include "PERI_GLIKEY.h"
#include "PERI_GPIO.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_INPUTMUX0.h"
#include "PERI_IOPCTL0.h"
#include "PERI_IOPCTL1.h"
#include "PERI_IOPCTL2.h"
#include "PERI_ITRC.h"
#include "PERI_JPGDECWRP.h"
#include "PERI_LPI2C.h"
#include "PERI_LPSPI.h"
#include "PERI_LPUART.h"
#include "PERI_LP_FLEXCOMM.h"
#include "PERI_MMU.h"
#include "PERI_MRT.h"
#include "PERI_MU.h"
#include "PERI_NIC.h"
#include "PERI_OCOTP.h"
#include "PERI_OSC32KNP.h"
#include "PERI_OSCCA.h"
#include "PERI_OSTIMER.h"
#include "PERI_PDM.h"
#include "PERI_PINT.h"
#include "PERI_PKC.h"
#include "PERI_PMC.h"
#include "PERI_PUF.h"
#include "PERI_PVTS.h"
#include "PERI_ROMCP.h"
#include "PERI_RSTCTL0.h"
#include "PERI_RSTCTL2.h"
#include "PERI_RSTCTL3.h"
#include "PERI_RSTCTL4.h"
#include "PERI_RTC.h"
#include "PERI_SCT.h"
#include "PERI_SDADC.h"
#include "PERI_SEMA42.h"
#include "PERI_SLEEPCON0.h"
#include "PERI_SYSCON0.h"
#include "PERI_SYSCON2.h"
#include "PERI_SYSCON3.h"
#include "PERI_SYSCON4.h"
#include "PERI_SYSPM.h"
#include "PERI_TRNG.h"
#include "PERI_USB.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_USDHC.h"
#include "PERI_UTICK.h"
#include "PERI_WWDT.h"
#include "PERI_XCACHE.h"
#include "PERI_XSPI.h"

#endif  /* #if !defined(MIMXRT735S_cm33_core0_H_) */
