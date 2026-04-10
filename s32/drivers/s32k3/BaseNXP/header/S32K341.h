/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K341.h
 * @version 1.1
 * @date 2023-02-02
 * @brief Peripheral Access Layer for S32K341
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K341_H_)  /* Check if memory map has not been already included */
#define S32K341_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K341_ADC.h"
#include "S32K341_AXBS_LITE.h"
#include "S32K341_BCTU.h"
#include "S32K341_CMU_FC.h"
#include "S32K341_CMU_FM.h"
#include "S32K341_CONFIGURATION_GPR.h"
#include "S32K341_CRC.h"
#include "S32K341_DCM.h"
#include "S32K341_DCM_GPR.h"
#include "S32K341_DMA.h"
#include "S32K341_DMAMUX.h"
#include "S32K341_DMA_TCD.h"
#include "S32K341_EIM.h"
#include "S32K341_EMAC.h"
#include "S32K341_EMIOS.h"
#include "S32K341_ERM.h"
#include "S32K341_FCCU.h"
#include "S32K341_FIRC.h"
#include "S32K341_FLASH.h"
#include "S32K341_FLEXCAN.h"
#include "S32K341_FLEXIO.h"
#include "S32K341_FXOSC.h"
#include "S32K341_INTM.h"
#include "S32K341_JDC.h"
#include "S32K341_LCU.h"
#include "S32K341_LPCMP.h"
#include "S32K341_LPI2C.h"
#include "S32K341_LPSPI.h"
#include "S32K341_LPUART.h"
#include "S32K341_MCM_CM7.h"
#include "S32K341_MC_CGM.h"
#include "S32K341_MC_ME.h"
#include "S32K341_MC_RGM.h"
#include "S32K341_MDM_AP.h"
#include "S32K341_MSCM.h"
#include "S32K341_MU.h"
#include "S32K341_PFLASH.h"
#include "S32K341_PIT.h"
#include "S32K341_PLL.h"
#include "S32K341_PMC.h"
#include "S32K341_PRAMC.h"
#include "S32K341_QUADSPI.h"
#include "S32K341_QUADSPI_ARDB.h"
#include "S32K341_RTC.h"
#include "S32K341_SAI.h"
#include "S32K341_SDA_AP.h"
#include "S32K341_SEMA42.h"
#include "S32K341_SIRC.h"
#include "S32K341_SIUL2.h"
#include "S32K341_STCU.h"
#include "S32K341_STM.h"
#include "S32K341_SWT.h"
#include "S32K341_SXOSC.h"
#include "S32K341_TEMPSENSE.h"
#include "S32K341_TRGMUX.h"
#include "S32K341_TSPC.h"
#include "S32K341_VIRT_WRAPPER.h"
#include "S32K341_WKPU.h"
#include "S32K341_XBIC.h"
#include "S32K341_XRDC.h"
#include "S32K341_NVIC.h"
#include "S32K341_SCB.h"
#include "S32K341_SYSTICK.h"
#include "S32K341_MPU.h"
#endif  /* #if !defined(S32K342_H_) */
