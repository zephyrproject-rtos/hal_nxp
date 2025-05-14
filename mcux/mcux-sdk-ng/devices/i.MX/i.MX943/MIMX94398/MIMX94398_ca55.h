/*
** ###################################################################
**     Processors:          MIMX94398AVKE_ca55
**                          MIMX94398AVKJ_ca55
**                          MIMX94398AVKM_ca55
**                          MIMX94398AVME_ca55
**                          MIMX94398AVMJ_ca55
**                          MIMX94398AVMM_ca55
**                          MIMX94398CVKE_ca55
**                          MIMX94398CVKJ_ca55
**                          MIMX94398CVKM_ca55
**                          MIMX94398CVME_ca55
**                          MIMX94398CVMJ_ca55
**                          MIMX94398CVMM_ca55
**                          MIMX94398DVKE_ca55
**                          MIMX94398DVKJ_ca55
**                          MIMX94398DVKM_ca55
**                          MIMX94398DVME_ca55
**                          MIMX94398DVMJ_ca55
**                          MIMX94398DVMM_ca55
**                          MIMX94398XVKE_ca55
**                          MIMX94398XVKJ_ca55
**                          MIMX94398XVKM_ca55
**                          MIMX94398XVME_ca55
**                          MIMX94398XVMJ_ca55
**                          MIMX94398XVMM_ca55
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX943RM rev1 draftK
**     Version:             rev. 1.0, 2023-11-01
**     Build:               b241210
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX94398_ca55
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-11-01)
**         Initial version.
**         core name and core alias name
**         +---------------------------------------------------------------------+
**         | core name  |                  core alias name                       |
**         +---------------------------------------------------------------------+
**         | cm33_core0 | m33, cm33                                              |
**         +---------------------------------------------------------------------+
**         | cm33_core1 | m33_2, cm33_2, cm33_sync, netcmix_cm33                 |
**         +---------------------------------------------------------------------+
**         | cm7_core0  | m7, cm7                                                |
**         +---------------------------------------------------------------------+
**         | cm7_core1  | m7_2, cm7_2                                            |
**         +---------------------------------------------------------------------+
**         | ca55_core0 | a55, ca55, a55_0, ca55_0                               |
**         +---------------------------------------------------------------------+
**         | ca55_core1 | a55, ca55, a55_1, ca55_1                               |
**         +---------------------------------------------------------------------+
**         | ca55_core2 | a55, ca55, a55_2, ca55_2                               |
**         +---------------------------------------------------------------------+
**         | ca55_core3 | a55, ca55, a55_3, ca55_3                               |
**         +---------------------------------------------------------------------+
**
** ###################################################################
*/

/*!
 * @file MIMX94398_ca55.h
 * @version 1.0
 * @date 2023-11-01
 * @brief CMSIS Peripheral Access Layer for MIMX94398_ca55
 *
 * CMSIS Peripheral Access Layer for MIMX94398_ca55
 */

#if !defined(MIMX94398_ca55_H_)  /* Check if memory map has not been already included */
#define MIMX94398_ca55_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_ANALOG_AGDET.h"
#include "PERI_ANALOG_CMU.h"
#include "PERI_ANALOG_PMRO.h"
#include "PERI_ANALOG_SFA.h"
#include "PERI_ANALOG_TCU.h"
#include "PERI_ANALOG_VDET.h"
#include "PERI_AOI.h"
#include "PERI_AON_CMU.h"
#include "PERI_AON_CRC.h"
#include "PERI_AON_CSTCU.h"
#include "PERI_AON_EIM.h"
#include "PERI_AON_FCCU.h"
#include "PERI_AON_INTM.h"
#include "PERI_AON_LSTCU.h"
#include "PERI_AON_MCM.h"
#include "PERI_AON_SYSPM.h"
#include "PERI_AON_TCU.h"
#include "PERI_AON_TRDC_MGR.h"
#include "PERI_ARDB.h"
#include "PERI_ATU_USB2.h"
#include "PERI_AXBS.h"
#include "PERI_BBNSM.h"
#include "PERI_BBSM_BLK_CTRL_BBSMMIX.h"
#include "PERI_BBSM_TCU.h"
#include "PERI_BISS.h"
#include "PERI_BLK_CTRL_NETCMIX.h"
#include "PERI_BLK_CTRL_NS_AONMIX.h"
#include "PERI_BLK_CTRL_S_AONMIX.h"
#include "PERI_BLK_CTRL_WAKEUPMIX.h"
#include "PERI_CACHE_ECC_MCM.h"
#include "PERI_CAMERA_ATU.h"
#include "PERI_CAMIX_BLK_CTRL.h"
#include "PERI_CAN.h"
#include "PERI_CCM.h"
#include "PERI_CCMSRCGPC_TCU.h"
#include "PERI_CORTEXA_TCU.h"
#include "PERI_DCIF.h"
#include "PERI_DDR_BLK_CTRL_DDRMIX.h"
#include "PERI_DDR_CMU.h"
#include "PERI_DDR_DDRC.h"
#include "PERI_DDR_LSTCU.h"
#include "PERI_DDR_TCU.h"
#include "PERI_DISPLAY_BLK_CTRL_DISPLAYMIX.h"
#include "PERI_DISPLAY_BLK_CTRL_LVDS.h"
#include "PERI_DISPLAY_TCU.h"
#include "PERI_DISPLAY_TRDC_MGR.h"
#include "PERI_DMA.h"
#include "PERI_DMA5.h"
#include "PERI_DWC_USB3.h"
#include "PERI_ECAT.h"
#include "PERI_ENDAT2P2.h"
#include "PERI_ENDAT3.h"
#include "PERI_ENETC_COMMON.h"
#include "PERI_ENETC_GLOBAL.h"
#include "PERI_ENETC_PCI_TYPE0.h"
#include "PERI_ENETC_PF_EMDIO.h"
#include "PERI_ENETC_PF_TMR.h"
#include "PERI_ENETC_PORT.h"
#include "PERI_ENETC_SI.h"
#include "PERI_ENETC_VF_PCI_TYPE0.h"
#include "PERI_ENET_PHY_CTRL_EX.h"
#include "PERI_ENET_PHY_MAC_ADAPTER.h"
#include "PERI_EQDC.h"
#include "PERI_EWM.h"
#include "PERI_FLEXIO.h"
#include "PERI_FRO.h"
#include "PERI_GLITCHFILTER.h"
#include "PERI_GPC_CPU_CTRL.h"
#include "PERI_GPC_GLOBAL.h"
#include "PERI_GPT.h"
#include "PERI_HIPERFACE.h"
#include "PERI_HSIO_BLK_CTRL_HSIOMIX.h"
#include "PERI_HSIO_TCU.h"
#include "PERI_HSIO_TRDC_MGR.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_IEPRC_IERB.h"
#include "PERI_IEPRC_PCI.h"
#include "PERI_IEPRC_PRB.h"
#include "PERI_IOMUXC.h"
#include "PERI_IOMUXC_GPR.h"
#include "PERI_IRQSTEER.h"
#include "PERI_IRQSTEERA55.h"
#include "PERI_LPI2C.h"
#include "PERI_LPIT.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_M7_A7_APB_MCM.h"
#include "PERI_M7_CMU.h"
#include "PERI_M7_EIM.h"
#include "PERI_M7_ERM.h"
#include "PERI_M7_LSTCU.h"
#include "PERI_M7_TCU.h"
#include "PERI_MSGINTR.h"
#include "PERI_MU.h"
#include "PERI_M_E_3_WR_I_MAIN_TRANSTATFILT.h"
#include "PERI_M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER.h"
#include "PERI_NECTMIX_CM33_AIPS.h"
#include "PERI_NETC_CMU.h"
#include "PERI_NETC_EIM.h"
#include "PERI_NETC_ENETC.h"
#include "PERI_NETC_ERM.h"
#include "PERI_NETC_ETH_LINK.h"
#include "PERI_NETC_IERB.h"
#include "PERI_NETC_LSTCU.h"
#include "PERI_NETC_MAX_CORE.h"
#include "PERI_NETC_OCSRAM_MCM.h"
#include "PERI_NETC_PORT.h"
#include "PERI_NETC_PRIV.h"
#include "PERI_NETC_PSEUDO_LINK.h"
#include "PERI_NETC_SW.h"
#include "PERI_NETC_SW_ENETC.h"
#include "PERI_NETC_TCU.h"
#include "PERI_NETC_TCU_CM33.h"
#include "PERI_NETC_TMR_BASE.h"
#include "PERI_NETC_TRDC_MGR.h"
#include "PERI_NETC_TRDC_MGR_CM33.h"
#include "PERI_NEUTRON.h"
#include "PERI_NEUTRONS.h"
#include "PERI_NOC_ALWAYS_ON_MAIN_RESFAULTCNTR.h"
#include "PERI_NOC_BLK_CTRL_NOCMIX.h"
#include "PERI_NOC_CMU.h"
#include "PERI_NOC_EIM.h"
#include "PERI_NOC_GICA.h"
#include "PERI_NOC_GICD.h"
#include "PERI_NOC_GICDA.h"
#include "PERI_NOC_GICP.h"
#include "PERI_NOC_GICRLPI0.h"
#include "PERI_NOC_GICRLPI1.h"
#include "PERI_NOC_GICRLPI2.h"
#include "PERI_NOC_GICRLPI3.h"
#include "PERI_NOC_GICRSGI0.h"
#include "PERI_NOC_GICRSGI2.h"
#include "PERI_NOC_GICRSGI3.h"
#include "PERI_NOC_GICRSGIL.h"
#include "PERI_NOC_GICT.h"
#include "PERI_NOC_GITS0.h"
#include "PERI_NOC_GITS0TRANSLATER.h"
#include "PERI_NOC_I_LCDIF_RD_I_MAIN_QOSG.h"
#include "PERI_NOC_I_LCDIF_RD_I_MAIN_TRANSTATFLTR.h"
#include "PERI_NOC_I_PXP_RD_I_MAIN_QOSG.h"
#include "PERI_NOC_I_PXP_RD_I_MAIN_TRANSTATFLTR.h"
#include "PERI_NOC_I_PXP_WR_I_MAIN_QOSG.h"
#include "PERI_NOC_I_PXP_WR_I_MAIN_TRANSTATFLTR.h"
#include "PERI_NOC_LSTCU.h"
#include "PERI_NOC_M_E_0_RD_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_M_E_0_RD_I_M_QOSGEN.h"
#include "PERI_NOC_M_E_0_WR_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_0_WR_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_M_E_1A_RD_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_1A_WR_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_1B_RD_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_1B_WR_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_3_RD_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_3_RD_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_M_E_3_WR_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_6_RD_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_6_RD_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_M_E_6_WR_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_6_WR_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_M_E_7_RD_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_7_RD_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_M_E_7_WR_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_7_WR_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_M_E_9_RD_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_9_WR_I_MAIN_QOSGEN.h"
#include "PERI_NOC_M_E_9_WR_I_MAIN_TRANSTATFILT.h"
#include "PERI_NOC_PROBE_LCDIF_RD_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_LCDIF_RD_MAIN_TRSTPROF.h"
#include "PERI_NOC_PROBE_M_E_0_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_M_E_0_MAIN_TRANSTATPROF.h"
#include "PERI_NOC_PROBE_M_E_3_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_M_E_3_MAIN_TRANSTATPROF.h"
#include "PERI_NOC_PROBE_M_E_6_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_M_E_6_MAIN_TRANSTATPROF.h"
#include "PERI_NOC_PROBE_M_E_7_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_M_E_7_MAIN_TRANSTATPROF.h"
#include "PERI_NOC_PROBE_M_E_9_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_M_E_9_MAIN_TRANSTATPROF.h"
#include "PERI_NOC_PROBE_PXP_RD_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_PXP_RD_MAIN_TRSTPROF.h"
#include "PERI_NOC_PROBE_PXP_WR_MAIN_PROBE.h"
#include "PERI_NOC_PROBE_PXP_WR_MAIN_TRSTPROF.h"
#include "PERI_NOC_TCU.h"
#include "PERI_NOC_TRDC_MGR.h"
#include "PERI_NPU_EIM.h"
#include "PERI_NPU_LSTCU.h"
#include "PERI_NPU_TCU.h"
#include "PERI_PCIE_DMA_IATU.h"
#include "PERI_PCIE_EP.h"
#include "PERI_PCIE_RC.h"
#include "PERI_PCIE_SHADOW_EP.h"
#include "PERI_PDM.h"
#include "PERI_PLL.h"
#include "PERI_PWM.h"
#include "PERI_PXP.h"
#include "PERI_RGPIO.h"
#include "PERI_S3MU.h"
#include "PERI_SEMA42.h"
#include "PERI_SERDES_SS.h"
#include "PERI_SINC.h"
#include "PERI_SRAMCTL.h"
#include "PERI_SRC_GEN.h"
#include "PERI_SRC_MEM.h"
#include "PERI_SRC_XSPR.h"
#include "PERI_SW_GLOBAL.h"
#include "PERI_SW_PORT.h"
#include "PERI_SW_PSEUDO_MAC_PORT.h"
#include "PERI_SYS_CTR_COMPARE.h"
#include "PERI_SYS_CTR_CONTROL.h"
#include "PERI_SYS_CTR_READ.h"
#include "PERI_TCM_ECC_MCM.h"
#include "PERI_TMPSNS.h"
#include "PERI_TMR.h"
#include "PERI_TMR_GLOBAL.h"
#include "PERI_TMR_PCI_HDR_TYPE0.h"
#include "PERI_TPM.h"
#include "PERI_TRDC_MGR_WKUP1.h"
#include "PERI_TRDC_MGR_WKUP2.h"
#include "PERI_TSTMR.h"
#include "PERI_USB.h"
#include "PERI_USB3_GLUE.h"
#include "PERI_USB3_PHY_TCA.h"
#include "PERI_USBNC.h"
#include "PERI_WAKEUP_ATU.h"
#include "PERI_WAKEUP_CMU.h"
#include "PERI_WAKEUP_DMA_CRC.h"
#include "PERI_WAKEUP_EIM.h"
#include "PERI_WAKEUP_ERM.h"
#include "PERI_WAKEUP_GPT.h"
#include "PERI_WAKEUP_SAI.h"
#include "PERI_WAKEUP_TCW.h"
#include "PERI_WAKEUP_TRDC_MGR_MEGA.h"
#include "PERI_WAKEUP_USDHC.h"
#include "PERI_WAKEUP_XSPI_RESPONDER.h"
#include "PERI_WDOG.h"
#include "PERI_XBAR1.h"
#include "PERI_XBAR2.h"
#include "PERI_XBAR3.h"
#include "PERI_XSPI.h"

#endif  /* #if !defined(MIMX94398_ca55_H_) */
