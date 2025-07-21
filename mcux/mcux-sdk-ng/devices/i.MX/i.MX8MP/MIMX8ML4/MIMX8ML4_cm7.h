/*
** ###################################################################
**     Processors:          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_cm7
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX8MPRM, Rev.D, 12/2020
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX8ML4_cm7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX8ML4_cm7.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMX8ML4_cm7
 *
 * CMSIS Peripheral Access Layer for MIMX8ML4_cm7
 */

#if !defined(MIMX8ML4_cm7_H_)  /* Check if memory map has not been already included */
#define MIMX8ML4_cm7_H_

/* IP Header Files List */
#include "PERI_AIPSTZ.h"
#include "PERI_APBH.h"
#include "PERI_ASRC.h"
#include "PERI_AUDIOMIX.h"
#include "PERI_AUDIOPACKETIZER.h"
#include "PERI_AUDIOSAMPLEGP.h"
#include "PERI_BCH.h"
#include "PERI_CAN.h"
#include "PERI_CCM.h"
#include "PERI_CCM_ANALOG.h"
#include "PERI_CEC.h"
#include "PERI_COLORSPACECONVERTER.h"
#include "PERI_DDRC.h"
#include "PERI_DDR_BLK_CTL.h"
#include "PERI_DMA.h"
#include "PERI_DWC_DDRPHYA_ANIB.h"
#include "PERI_DWC_DDRPHYA_APBONLY.h"
#include "PERI_DWC_DDRPHYA_DBYTE.h"
#include "PERI_DWC_DDRPHYA_DRTUB.h"
#include "PERI_DWC_DDRPHYA_INITENG.h"
#include "PERI_DWC_DDRPHYA_MASTER.h"
#include "PERI_EARC.h"
#include "PERI_ECSPI.h"
#include "PERI_EDDC.h"
#include "PERI_ENET.h"
#include "PERI_ENET_QOS.h"
#include "PERI_FLEXSPI.h"
#include "PERI_FRAMECOMPOSER.h"
#include "PERI_GLUE_USB.h"
#include "PERI_GPC.h"
#include "PERI_GPC_PGC.h"
#include "PERI_GPIO.h"
#include "PERI_GPMI.h"
#include "PERI_GPT.h"
#include "PERI_HDCP.h"
#include "PERI_HDCP22.h"
#include "PERI_HDMI_TRNG.h"
#include "PERI_HDMI_TX_BLK_CTL.h"
#include "PERI_HSIO_BLK_CTRL.h"
#include "PERI_HTX_PAI.h"
#include "PERI_HTX_PVI.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_IDENTIFICATION.h"
#include "PERI_INTERRUPT.h"
#include "PERI_IOMUXC.h"
#include "PERI_IOMUXC_GPR.h"
#include "PERI_IRQSTEER.h"
#include "PERI_ISI.h"
#include "PERI_LCDIF.h"
#include "PERI_MAINCONTROLLER.h"
#include "PERI_MEDIA_BLK_CTRL.h"
#include "PERI_MIPI_CSI.h"
#include "PERI_MIPI_DSI.h"
#include "PERI_MU.h"
#include "PERI_NPU.h"
#include "PERI_OCOTP.h"
#include "PERI_PCIE.h"
#include "PERI_PCIE_PHY.h"
#include "PERI_PDM.h"
#include "PERI_PHYCONFIGURATION.h"
#include "PERI_PWM.h"
#include "PERI_RDC.h"
#include "PERI_RDC_SEMAPHORE.h"
#include "PERI_SDMAARM.h"
#include "PERI_SEMA4.h"
#include "PERI_SNVS.h"
#include "PERI_SPBA.h"
#include "PERI_SRC.h"
#include "PERI_SYS_CTR_COMPARE.h"
#include "PERI_SYS_CTR_CONTROL.h"
#include "PERI_SYS_CTR_READ.h"
#include "PERI_TMU.h"
#include "PERI_UART.h"
#include "PERI_USB.h"
#include "PERI_USDHC.h"
#include "PERI_VIDEOPACKETIZER.h"
#include "PERI_VIDEOSAMPLER.h"
#include "PERI_VPU_BLK_CTL.h"
#include "PERI_VPU_G1.h"
#include "PERI_VPU_G1_H264.h"
#include "PERI_VPU_G1_VP7_VP8.h"
#include "PERI_VPU_G1_VP8.h"
#include "PERI_VPU_G2.h"
#include "PERI_VPU_H264.h"
#include "PERI_VPU_HEVC.h"
#include "PERI_WDOG.h"
#include "PERI_XTALOSC.h"

#endif  /* #if !defined(MIMX8ML4_cm7_H_) */
