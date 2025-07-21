/*
** ###################################################################
**     Processors:          MIMXRT1051CVJ5B
**                          MIMXRT1051CVL5B
**                          MIMXRT1051DVJ6B
**                          MIMXRT1051DVL6B
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    IMXRT1050RM Rev.5, 07/2021 | IMXRT1050SRM Rev.2
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT1051
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-09-21)
**         Update interrupt vector table and dma request source.
**         Update register BEE_ADDR_OFFSET1's bitfield name to ADDR_OFFSET1.
**         Split GPIO_COMBINED_IRQS to GPIO_COMBINED_LOW_IRQS and GPIO_COMBINED_HIGH_IRQS.
**     - rev. 1.1 (2018-11-16)
**         Update header files to align with IMXRT1050RM Rev.1.
**     - rev. 1.2 (2018-11-27)
**         Update header files to align with IMXRT1050RM Rev.2.1.
**     - rev. 1.3 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.4 (2021-08-10)
**         Update header files to align with IMXRT1050RM Rev.5.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT1051.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT1051
 *
 * CMSIS Peripheral Access Layer for MIMXRT1051
 */

#if !defined(MIMXRT1051_H_)  /* Check if memory map has not been already included */
#define MIMXRT1051_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_ADC_ETC.h"
#include "PERI_AIPSTZ.h"
#include "PERI_AOI.h"
#include "PERI_BEE.h"
#include "PERI_CAN.h"
#include "PERI_CCM.h"
#include "PERI_CCM_ANALOG.h"
#include "PERI_CM7_MCM.h"
#include "PERI_CMP.h"
#include "PERI_CSU.h"
#include "PERI_DCDC.h"
#include "PERI_DCP.h"
#include "PERI_DMA.h"
#include "PERI_DMAMUX.h"
#include "PERI_ENC.h"
#include "PERI_ENET.h"
#include "PERI_EWM.h"
#include "PERI_FLEXIO.h"
#include "PERI_FLEXRAM.h"
#include "PERI_FLEXSPI.h"
#include "PERI_GPC.h"
#include "PERI_GPIO.h"
#include "PERI_GPT.h"
#include "PERI_I2S.h"
#include "PERI_IOMUXC.h"
#include "PERI_IOMUXC_GPR.h"
#include "PERI_IOMUXC_SNVS.h"
#include "PERI_IOMUXC_SNVS_GPR.h"
#include "PERI_KPP.h"
#include "PERI_LPI2C.h"
#include "PERI_LPSPI.h"
#include "PERI_LPUART.h"
#include "PERI_OCOTP.h"
#include "PERI_PGC.h"
#include "PERI_PIT.h"
#include "PERI_PMU.h"
#include "PERI_PWM.h"
#include "PERI_ROMC.h"
#include "PERI_RTWDOG.h"
#include "PERI_SEMC.h"
#include "PERI_SNVS.h"
#include "PERI_SPDIF.h"
#include "PERI_SRC.h"
#include "PERI_TEMPMON.h"
#include "PERI_TMR.h"
#include "PERI_TRNG.h"
#include "PERI_TSC.h"
#include "PERI_USB.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_USB_ANALOG.h"
#include "PERI_USDHC.h"
#include "PERI_WDOG.h"
#include "PERI_XBARA.h"
#include "PERI_XBARB.h"
#include "PERI_XTALOSC24M.h"

#endif  /* #if !defined(MIMXRT1051_H_) */
