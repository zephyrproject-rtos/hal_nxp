/*
** ###################################################################
**     Processors:          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX7ULPRM, Rev. 0, Nov. 2018
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCIMX7U5_cm4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MCIMX7U5_cm4.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCIMX7U5_cm4
 *
 * CMSIS Peripheral Access Layer for MCIMX7U5_cm4
 */

#if !defined(MCIMX7U5_cm4_H_)  /* Check if memory map has not been already included */
#define MCIMX7U5_cm4_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_CMP.h"
#include "PERI_CRC.h"
#include "PERI_DAC.h"
#include "PERI_DMA.h"
#include "PERI_DMAMUX.h"
#include "PERI_EWM.h"
#include "PERI_FB.h"
#include "PERI_FGPIO.h"
#include "PERI_FLEXIO.h"
#include "PERI_GPIO.h"
#include "PERI_I2S.h"
#include "PERI_IOMUXC0.h"
#include "PERI_IOMUXC1.h"
#include "PERI_IOMUXC1_DDR.h"
#include "PERI_LCDIF.h"
#include "PERI_LLWU.h"
#include "PERI_LMEM.h"
#include "PERI_LPI2C.h"
#include "PERI_LPIT.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_LTC.h"
#include "PERI_MCM.h"
#include "PERI_MIPI_DSI_HOST.h"
#include "PERI_MIPI_DSI_HOST_APB_PKT_IF.h"
#include "PERI_MIPI_DSI_HOST_DPI_INTFC.h"
#include "PERI_MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC.h"
#include "PERI_MMCAU.h"
#include "PERI_MMDC.h"
#include "PERI_MU.h"
#include "PERI_OCOTP_CTRL.h"
#include "PERI_OTFAD.h"
#include "PERI_PCC0.h"
#include "PERI_PCC1.h"
#include "PERI_PCC2.h"
#include "PERI_PCC3.h"
#include "PERI_PMC0.h"
#include "PERI_PMC1.h"
#include "PERI_PORT.h"
#include "PERI_QUADSPI.h"
#include "PERI_ROMC.h"
#include "PERI_SCG.h"
#include "PERI_SEMA42.h"
#include "PERI_SIM.h"
#include "PERI_SMC.h"
#include "PERI_SNVS.h"
#include "PERI_TPM.h"
#include "PERI_TRGMUX.h"
#include "PERI_TRNG.h"
#include "PERI_TSTMR.h"
#include "PERI_USB.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_USDHC.h"
#include "PERI_VIU.h"
#include "PERI_WDOG.h"
#include "PERI_XRDC.h"

#endif  /* #if !defined(MCIMX7U5_cm4_H_) */
