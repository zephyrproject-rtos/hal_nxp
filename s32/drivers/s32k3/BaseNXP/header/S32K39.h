/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K39_H_)  /* Check if memory map has not been already included */
#define S32K39_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K39_ADC.h"
#include "S32K39_ADC_BIST.h"
#include "S32K39_ADC_BIST_FIR.h"
#include "S32K39_AXBS_LITE.h"
#include "S32K39_BCTU.h"
#include "S32K39_CMU_FC.h"
#include "S32K39_CMU_FM.h"
#include "S32K39_CONFIGURATION_GPR.h"
#include "S32K39_CRC.h"
#include "S32K39_DCM.h"
#include "S32K39_DCM_GPR.h"
#include "S32K39_DIGRF_TOP.h"
#include "S32K39_DMAMUX.h"
#include "S32K39_DMA_TCD_0.h"
#include "S32K39_DMA_TCD_1.h"
#include "S32K39_DSPI_MSC.h"
#include "S32K39_DSPSS.h"
#include "S32K39_D_IP_SWG_SYN.h"
#include "S32K39_EDMA.h"
#include "S32K39_EIM.h"
#include "S32K39_EIM_1.h"
#include "S32K39_EIM_2.h"
#include "S32K39_EMAC.h"
#include "S32K39_EMIOS.h"
#include "S32K39_ERM.h"
#include "S32K39_ETPU.h"
#include "S32K39_FCCU.h"
#include "S32K39_FIRC.h"
#include "S32K39_FLASH.h"
#include "S32K39_FLEXCAN.h"
#include "S32K39_FLEXIO.h"
#include "S32K39_FLEXPWM.h"
#include "S32K39_FXOSC.h"
#include "S32K39_IGF.h"
#include "S32K39_INTM.h"
#include "S32K39_JDC.h"
#include "S32K39_LCU.h"
#include "S32K39_LPCMP.h"
#include "S32K39_LPI2C.h"
#include "S32K39_LPSPI.h"
#include "S32K39_LPUART.h"
#include "S32K39_MCM_CM7.h"
#include "S32K39_MC_CGM.h"
#include "S32K39_MC_ME.h"
#include "S32K39_MC_RGM.h"
#include "S32K39_MDM_AP.h"
#include "S32K39_MSCM.h"
#include "S32K39_MU.h"
#include "S32K39_OMU_CM7.h"
#include "S32K39_PFLASH.h"
#include "S32K39_PIT.h"
#include "S32K39_PLL.h"
#include "S32K39_PMC.h"
#include "S32K39_PRAMC.h"
#include "S32K39_QUADSPI.h"
#include "S32K39_QUADSPI_ARDB.h"
#include "S32K39_RTC.h"
#include "S32K39_SDADC.h"
#include "S32K39_SDA_AP.h"
#include "S32K39_SELFTEST_GPR.h"
#include "S32K39_SEMA42.h"
#include "S32K39_SIPI1.h"
#include "S32K39_SIRC.h"
#include "S32K39_SIUL2.h"
#include "S32K39_STCU.h"
#include "S32K39_STM.h"
#include "S32K39_SWT.h"
#include "S32K39_TEMPSENSE.h"
#include "S32K39_TRGMUX_APP.h"
#include "S32K39_TRGMUX_MSC.h"
#include "S32K39_VIRT_WRAPPER.h"
#include "S32K39_WKPU.h"
#include "S32K39_XBIC.h"
#include "S32K39_XRDC.h"
#include "S32K39_NVIC.h"
#include "S32K39_SCB.h"
#include "S32K39_SYSTICK.h"
#include "S32K39_MPU.h"

#endif  /* #if !defined(S32K39_H_) */
