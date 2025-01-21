/*
** ###################################################################
**     Processors:          MIMX9332AVTXM_cm33
**                          MIMX9332CVVXM_cm33
**                          MIMX9332DVVXM_cm33
**                          MIMX9332XVVXM_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX93RM, Internal, November. 2021
**     Version:             rev. 1.0, 2021-11-16
**     Build:               b240814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX9332_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX9332_cm33.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX9332_cm33
 *
 * CMSIS Peripheral Access Layer for MIMX9332_cm33
 */

#if !defined(MIMX9332_cm33_H_)  /* Check if memory map has not been already included */
#define MIMX9332_cm33_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_ANA_OSC.h"
#include "PERI_AXBS.h"
#include "PERI_BBNSM.h"
#include "PERI_BLK_CTRL_MLMIX.h"
#include "PERI_BLK_CTRL_NICMIX.h"
#include "PERI_BLK_CTRL_NS_AONMIX.h"
#include "PERI_BLK_CTRL_S_AONMIX.h"
#include "PERI_BLK_CTRL_WAKEUPMIX.h"
#include "PERI_CACHE_ECC_MCM.h"
#include "PERI_CAN.h"
#include "PERI_CCM.h"
#include "PERI_DDRC.h"
#include "PERI_DDRMIX_BLK_CTRL.h"
#include "PERI_DMA.h"
#include "PERI_DMA4.h"
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
#include "PERI_IPC.h"
#include "PERI_ISI.h"
#include "PERI_LCDIF.h"
#include "PERI_LPI2C.h"
#include "PERI_LPIT.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MCM.h"
#include "PERI_MEDIAMIX_BLK_CTRL.h"
#include "PERI_MIPI_CSI.h"
#include "PERI_MIPI_DSI.h"
#include "PERI_MU.h"
#include "PERI_NPU.h"
#include "PERI_OCRAM_MECC.h"
#include "PERI_OTFAD.h"
#include "PERI_PDM.h"
#include "PERI_PLL.h"
#include "PERI_PXP.h"
#include "PERI_RGPIO.h"
#include "PERI_S3MU.h"
#include "PERI_SEMA42.h"
#include "PERI_SPDIF.h"
#include "PERI_SRC_GENERAL_REG.h"
#include "PERI_SRC_MEM_SLICE.h"
#include "PERI_SRC_MIX_SLICE.h"
#include "PERI_SYSPM.h"
#include "PERI_SYS_CTR_COMPARE.h"
#include "PERI_SYS_CTR_CONTROL.h"
#include "PERI_SYS_CTR_READ.h"
#include "PERI_TCM_ECC_MCM.h"
#include "PERI_TMU.h"
#include "PERI_TPM.h"
#include "PERI_TRDC_MBC0.h"
#include "PERI_TRDC_MBC2.h"
#include "PERI_TRDC_MBC4.h"
#include "PERI_TRGMUX.h"
#include "PERI_TSTMR.h"
#include "PERI_USB.h"
#include "PERI_USBNC.h"
#include "PERI_USDHC.h"
#include "PERI_WAKEUP_AHBRM.h"
#include "PERI_WDOG.h"
#include "PERI_XCACHE.h"

#endif  /* #if !defined(MIMX9332_cm33_H_) */
