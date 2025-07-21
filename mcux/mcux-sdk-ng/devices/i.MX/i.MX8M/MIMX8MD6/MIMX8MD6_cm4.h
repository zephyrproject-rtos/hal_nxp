/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_cm4
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX8MDQLQRM, Rev. 0, Jan. 2018
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX8MD6_cm4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX8MD6_cm4.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMX8MD6_cm4
 *
 * CMSIS Peripheral Access Layer for MIMX8MD6_cm4
 */

#if !defined(MIMX8MD6_cm4_H_)  /* Check if memory map has not been already included */
#define MIMX8MD6_cm4_H_

/* IP Header Files List */
#include "PERI_AIPSTZ.h"
#include "PERI_APBH.h"
#include "PERI_BCH.h"
#include "PERI_BLK_CTL.h"
#include "PERI_CCM.h"
#include "PERI_CCM_ANALOG.h"
#include "PERI_CTX_LD.h"
#include "PERI_DDRC.h"
#include "PERI_DEC400D.h"
#include "PERI_DPR.h"
#include "PERI_DTG.h"
#include "PERI_DTRC.h"
#include "PERI_ECSPI.h"
#include "PERI_ENET.h"
#include "PERI_GPC.h"
#include "PERI_GPC_PGC.h"
#include "PERI_GPIO.h"
#include "PERI_GPMI.h"
#include "PERI_GPT.h"
#include "PERI_HDMI_TX.h"
#include "PERI_I2C.h"
#include "PERI_I2S.h"
#include "PERI_IOMUXC.h"
#include "PERI_IOMUXC_GPR.h"
#include "PERI_IRQ_STEER.h"
#include "PERI_LCDIF.h"
#include "PERI_LMEM.h"
#include "PERI_LUT_LD.h"
#include "PERI_MCM.h"
#include "PERI_MED_DC_SCALER.h"
#include "PERI_MED_HDR10.h"
#include "PERI_MIPI_CSI2RX.h"
#include "PERI_MIPI_DSI_HOST.h"
#include "PERI_MIPI_DSI_HOST_APB_PKT_IF.h"
#include "PERI_MIPI_DSI_HOST_DPI_INTFC.h"
#include "PERI_MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC.h"
#include "PERI_MU.h"
#include "PERI_OCOTP.h"
#include "PERI_PWM.h"
#include "PERI_QUADSPI.h"
#include "PERI_RDC.h"
#include "PERI_RDC_SEMAPHORE.h"
#include "PERI_RD_SRC.h"
#include "PERI_ROMC.h"
#include "PERI_SDMAARM.h"
#include "PERI_SEMA4.h"
#include "PERI_SNVS.h"
#include "PERI_SPBA.h"
#include "PERI_SPDIF.h"
#include "PERI_SRC.h"
#include "PERI_SUBSAM.h"
#include "PERI_TMU.h"
#include "PERI_UART.h"
#include "PERI_USDHC.h"
#include "PERI_WDOG.h"
#include "PERI_WR_SCL.h"
#include "PERI_XTALOSC.h"

#endif  /* #if !defined(MIMX8MD6_cm4_H_) */
