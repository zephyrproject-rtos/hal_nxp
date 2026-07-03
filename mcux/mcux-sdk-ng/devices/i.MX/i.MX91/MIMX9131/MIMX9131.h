/*
** ###################################################################
**     Processors:          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX91RM Rev.1
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX9131
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX9131.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for MIMX9131
 *
 * CMSIS Peripheral Access Layer for MIMX9131
 */

#if !defined(MIMX9131_H_)  /* Check if memory map has not been already included */
#define MIMX9131_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_ANA_OSC.h"
#include "PERI_AXBS.h"
#include "PERI_BBNSM.h"
#include "PERI_BLK_CTRL_DDRMIX.h"
#include "PERI_BLK_CTRL_MEDIAMIX.h"
#include "PERI_BLK_CTRL_NIC_WRAPPER.h"
#include "PERI_BLK_CTRL_NS_AONMIX.h"
#include "PERI_BLK_CTRL_S_AONMIX.h"
#include "PERI_BLK_CTRL_WAKEUPMIX.h"
#include "PERI_CAN.h"
#include "PERI_CCM_CTRL.h"
#include "PERI_DDRC.h"
#include "PERI_DMA.h"
#include "PERI_DMA4.h"
#include "PERI_DMA4_TCD.h"
#include "PERI_ENET.h"
#include "PERI_ENET_QOS.h"
#include "PERI_FLEXIO.h"
#include "PERI_FLEXSPI.h"
#include "PERI_FSB.h"
#include "PERI_GPC_CPU_CTRL.h"
#include "PERI_GPC_GLOBAL.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_IOMUXC1.h"
#include "PERI_IOMUXC_GPR.h"
#include "PERI_ISI.h"
#include "PERI_LCDIF.h"
#include "PERI_LPI2C.h"
#include "PERI_LPIT.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MU.h"
#include "PERI_OCRAM_CTRL.h"
#include "PERI_PDM.h"
#include "PERI_PLL.h"
#include "PERI_RGPIO.h"
#include "PERI_SEMA42.h"
#include "PERI_SPDIF.h"
#include "PERI_SRC_GENERAL_REG.h"
#include "PERI_SRC_MEM_SLICE.h"
#include "PERI_SRC_MIX_SLICE.h"
#include "PERI_SYS_CTR_COMPARE.h"
#include "PERI_SYS_CTR_CONTROL.h"
#include "PERI_SYS_CTR_READ.h"
#include "PERI_TCD.h"
#include "PERI_TEMPSENSE.h"
#include "PERI_TPM.h"
#include "PERI_TRDC_MBC0.h"
#include "PERI_TRDC_MBC2.h"
#include "PERI_TRDC_MBC4.h"
#include "PERI_TRGMUX.h"
#include "PERI_TSTMR.h"
#include "PERI_USB.h"
#include "PERI_USBNC.h"
#include "PERI_USDHC.h"
#include "PERI_WDOG.h"

#endif  /* #if !defined(MIMX9131_H_) */
