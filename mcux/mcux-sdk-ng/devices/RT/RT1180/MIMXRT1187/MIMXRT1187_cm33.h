/*
** ###################################################################
**     Processors:          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8C_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    IMXRT1180RM, Rev 5, 01/2024
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT1187_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT1187_cm33.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT1187_cm33
 *
 * CMSIS Peripheral Access Layer for MIMXRT1187_cm33
 */

#if !defined(MIMXRT1187_cm33_H_)  /* Check if memory map has not been already included */
#define MIMXRT1187_cm33_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_ANADIG.h"
#include "PERI_ANADIG_LDO_BBSM.h"
#include "PERI_ANADIG_MISC.h"
#include "PERI_ANADIG_OSC.h"
#include "PERI_ANADIG_PLL.h"
#include "PERI_ANADIG_PMU.h"
#include "PERI_ANADIG_TEMPSENSOR.h"
#include "PERI_AOI.h"
#include "PERI_ASRC.h"
#include "PERI_AXBS.h"
#include "PERI_BBNSM.h"
#include "PERI_BLK_CTRL_BBSMMIX.h"
#include "PERI_BLK_CTRL_NS_AONMIX.h"
#include "PERI_BLK_CTRL_S_AONMIX.h"
#include "PERI_BLK_CTRL_WAKEUPMIX.h"
#include "PERI_CACHE_ECC_MCM.h"
#include "PERI_CAN.h"
#include "PERI_CCM.h"
#include "PERI_CMP.h"
#include "PERI_DAC.h"
#include "PERI_DCDC.h"
#include "PERI_DMA.h"
#include "PERI_DMA4.h"
#include "PERI_EIM.h"
#include "PERI_ENETC_GLOBAL.h"
#include "PERI_ENETC_PCI_TYPE0.h"
#include "PERI_ENETC_PF_EMDIO.h"
#include "PERI_ENETC_PF_TMR.h"
#include "PERI_ENETC_SI.h"
#include "PERI_ENETC_VF_PCI_TYPE0.h"
#include "PERI_EQDC.h"
#include "PERI_ERM.h"
#include "PERI_EWM.h"
#include "PERI_FLEXIO.h"
#include "PERI_FLEXSPI.h"
#include "PERI_FLEXSPI_SLV.h"
#include "PERI_GPC_CPU_CTRL.h"
#include "PERI_GPC_GLOBAL.h"
#include "PERI_GPC_SYS_SLEEP_CTRL.h"
#include "PERI_GPT.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_IEE.h"
#include "PERI_IEE_APC.h"
#include "PERI_IERC_IERB.h"
#include "PERI_IERC_PCI.h"
#include "PERI_IOMUXC.h"
#include "PERI_IOMUXC_AON.h"
#include "PERI_KPP.h"
#include "PERI_LPI2C.h"
#include "PERI_LPIT.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MECC.h"
#include "PERI_MSGINTR.h"
#include "PERI_MU.h"
#include "PERI_NETC_ENETC.h"
#include "PERI_NETC_ETH_LINK.h"
#include "PERI_NETC_IERB.h"
#include "PERI_NETC_PORT.h"
#include "PERI_NETC_PRIV.h"
#include "PERI_NETC_PSEUDO_LINK.h"
#include "PERI_NETC_SW.h"
#include "PERI_NETC_SW_ENETC.h"
#include "PERI_OCOTP_FSB.h"
#include "PERI_OSC_RC_400M.h"
#include "PERI_OTFAD.h"
#include "PERI_PDM.h"
#include "PERI_PHY_LDO.h"
#include "PERI_PLL.h"
#include "PERI_PWM.h"
#include "PERI_RGPIO.h"
#include "PERI_RTWDOG.h"
#include "PERI_S3MU.h"
#include "PERI_SEMA42.h"
#include "PERI_SEMC.h"
#include "PERI_SINC.h"
#include "PERI_SPDIF.h"
#include "PERI_SRC_GENERAL.h"
#include "PERI_SRC_MIF_LN28FDSOI_SPLLRAM.h"
#include "PERI_SRC_MIF_S28SPREGH.h"
#include "PERI_SRC_MIF_S28SPREGH_PSWA.h"
#include "PERI_SRC_MIX_SLICE.h"
#include "PERI_SYSPM.h"
#include "PERI_SYS_CTR_COMPARE.h"
#include "PERI_SYS_CTR_CONTROL.h"
#include "PERI_SYS_CTR_READ.h"
#include "PERI_TCM_ECC_MCM.h"
#include "PERI_TMPSNS.h"
#include "PERI_TMR.h"
#include "PERI_TPM.h"
#include "PERI_TRDC.h"
#include "PERI_TSTMR.h"
#include "PERI_USB.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_USDHC.h"
#include "PERI_VMBANDGAP.h"
#include "PERI_VREF.h"
#include "PERI_XBAR_NUM_OUT221.h"
#include "PERI_XBAR_NUM_OUT32.h"
#include "PERI_XCACHE.h"

#endif  /* #if !defined(MIMXRT1187_cm33_H_) */
