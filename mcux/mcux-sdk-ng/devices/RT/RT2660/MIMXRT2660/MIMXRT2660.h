/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    iMXRT2660RM Rev.1 DraftN, 08/2026
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT2660
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMXRT2660.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for MIMXRT2660
 *
 * CMSIS Peripheral Access Layer for MIMXRT2660
 */

#if !defined(MIMXRT2660_H_)  /* Check if memory map has not been already included */
#define MIMXRT2660_H_

/* IP Header Files List */
#include "PERI_ADC.h"
#include "PERI_AHB_SRAMC.h"
#include "PERI_ASRC.h"
#include "PERI_AUDIO_XCVR.h"
#include "PERI_AXBS.h"
#include "PERI_CAN.h"
#include "PERI_CCM.h"
#include "PERI_CGUANA.h"
#include "PERI_CMP.h"
#include "PERI_CRC.h"
#include "PERI_DCIF.h"
#include "PERI_DEBUGMAILBOX.h"
#include "PERI_DIGTMP.h"
#include "PERI_DMA.h"
#include "PERI_DMA5.h"
#include "PERI_ENET.h"
#include "PERI_ENET_QOS.h"
#include "PERI_EQDC.h"
#include "PERI_EVTG.h"
#include "PERI_EWM.h"
#include "PERI_FLEXIO.h"
#include "PERI_FLEXSPI_SLV.h"
#include "PERI_FREQME.h"
#include "PERI_FSB.h"
#include "PERI_GPIO.h"
#include "PERI_I2S.h"
#include "PERI_I3C.h"
#include "PERI_INPUTMUX.h"
#include "PERI_IOMUXC.h"
#include "PERI_ISI.h"
#include "PERI_JPEGDEC.h"
#include "PERI_JPGDECWRP.h"
#include "PERI_LLC.h"
#include "PERI_LPDAC.h"
#include "PERI_LPI2C.h"
#include "PERI_LPIT.h"
#include "PERI_LPSPI.h"
#include "PERI_LPTMR.h"
#include "PERI_LPUART.h"
#include "PERI_MCM.h"
#include "PERI_MEMCON_GLOBAL.h"
#include "PERI_MEMCON_SLICE.h"
#include "PERI_MMU.h"
#include "PERI_MODCON.h"
#include "PERI_NIC.h"
#include "PERI_PDCON.h"
#include "PERI_PDM.h"
#include "PERI_PMU.h"
#include "PERI_POWERCON_CMC_CTRL.h"
#include "PERI_POWERCON_GLOBAL.h"
#include "PERI_POWERCON_SOC_CTRL.h"
#include "PERI_POWERCON_SYS_SLEEP_CTRL.h"
#include "PERI_PWM.h"
#include "PERI_REFORMATTER.h"
#include "PERI_RESETCON.h"
#include "PERI_ROMCP.h"
#include "PERI_RTC.h"
#include "PERI_S3MU.h"
#include "PERI_SINC.h"
#include "PERI_SRAM.h"
#include "PERI_SRAMCTL.h"
#include "PERI_STM.h"
#include "PERI_SWT.h"
#include "PERI_TENBASET_PHY.h"
#include "PERI_TINGPU.h"
#include "PERI_TMR.h"
#include "PERI_TPM.h"
#include "PERI_TRDC.h"
#include "PERI_TRDC_CMPT.h"
#include "PERI_TRGSYNC.h"
#include "PERI_USB.h"
#include "PERI_USBHS.h"
#include "PERI_USBHSDCD.h"
#include "PERI_USBNC.h"
#include "PERI_USBPHY.h"
#include "PERI_USDHC.h"
#include "PERI_VBATCON.h"
#include "PERI_XBAR0.h"
#include "PERI_XBAR1.h"
#include "PERI_XBAR2.h"
#include "PERI_XBAR3.h"
#include "PERI_XBAR4.h"
#include "PERI_XSPI.h"

#endif  /* #if !defined(MIMXRT2660_H_) */
