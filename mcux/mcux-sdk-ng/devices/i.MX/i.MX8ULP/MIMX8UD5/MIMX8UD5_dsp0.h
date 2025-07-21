/*
** ###################################################################
**     Processors:          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVP08_dsp0
**
**     Compiler:            Xtensa Compiler
**     Reference manual:    IMX8ULPRM, Rev. D, December. 2022
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         Peripheral Access Layer for MIMX8UD5_dsp0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX8UD5_dsp0.h
 * @version 6.0
 * @date 2024-10-29
 * @brief Peripheral Access Layer for MIMX8UD5_dsp0
 *
 * Peripheral Access Layer for MIMX8UD5_dsp0
 */

#if !defined(MIMX8UD5_dsp0_H_)  /* Check if memory map has not been already included */
#define MIMX8UD5_dsp0_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AHB_ADDR_REMAP.h"
#include "PERI_AXBS.h"
#include "PERI_BBNSM.h"
#include "PERI_CACHE64_CTRL.h"
#include "PERI_CAN.h"
#include "PERI_CASPER.h"
#include "PERI_CGC.h"
#include "PERI_CGC_AD.h"
#include "PERI_CGC_LPAV.h"
#include "PERI_CMC.h"
#include "PERI_CMC_AD.h"
#include "PERI_CMC_LPAC.h"
#include "PERI_CMP.h"
#include "PERI_DAC.h"
#include "PERI_DMA.h"
#include "PERI_DMA_AD.h"
#include "PERI_ENET.h"
#include "PERI_EWM.h"
#include "PERI_FLEXIO.h"
#include "PERI_FLEXSPI.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_IOMUXC0.h"
#include "PERI_IOMUXC1.h"
#include "PERI_ISI.h"
#include "PERI_LCDIF.h"
#include "PERI_LPDDR.h"
#include "PERI_LPI2C.h"
#include "PERI_LPIT.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MCM.h"
#include "PERI_MIPI_CSI2RX.h"
#include "PERI_MIPI_CSI_CSR.h"
#include "PERI_MIPI_DSI_HOST.h"
#include "PERI_MRT.h"
#include "PERI_MU.h"
#include "PERI_PCC0.h"
#include "PERI_PCC1.h"
#include "PERI_PCC2.h"
#include "PERI_PCC3.h"
#include "PERI_PCC4.h"
#include "PERI_PCC5.h"
#include "PERI_PDM.h"
#include "PERI_POWERQUAD.h"
#include "PERI_PXP.h"
#include "PERI_RGPIO.h"
#include "PERI_SEMA42.h"
#include "PERI_SIM.h"
#include "PERI_SIM_AD.h"
#include "PERI_SIM_LPAV.h"
#include "PERI_SIM_SEC.h"
#include "PERI_SPDIF.h"
#include "PERI_SYSPM.h"
#include "PERI_TPM.h"
#include "PERI_TRDC.h"
#include "PERI_TRGMUX.h"
#include "PERI_TSTMR.h"
#include "PERI_USB.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_USDHC.h"
#include "PERI_WDOG.h"
#include "PERI_WUU.h"
#include "PERI_XRDC.h"

#endif  /* #if !defined(MIMX8UD5_dsp0_H_) */
