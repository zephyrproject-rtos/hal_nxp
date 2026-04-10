/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K342.h
 * @version 1.4
 * @date 2021-12-10
 * @brief Peripheral Access Layer for S32K342
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K342_H_)  /* Check if memory map has not been already included */
#define S32K342_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K342_ADC.h"
#include "S32K342_AXBS_LITE.h"
#include "S32K342_BCTU.h"
#include "S32K342_CMU_FC.h"
#include "S32K342_CMU_FM.h"
#include "S32K342_CONFIGURATION_GPR.h"
#include "S32K342_CRC.h"
#include "S32K342_DCM.h"
#include "S32K342_DCM_GPR.h"
#include "S32K342_DMA.h"
#include "S32K342_DMAMUX.h"
#include "S32K342_DMA_TCD.h"
#include "S32K342_EIM.h"
#include "S32K342_EMAC.h"
#include "S32K342_EMIOS.h"
#include "S32K342_ERM.h"
#include "S32K342_FCCU.h"
#include "S32K342_FIRC.h"
#include "S32K342_FLASH.h"
#include "S32K342_FLEXCAN.h"
#include "S32K342_FLEXIO.h"
#include "S32K342_FXOSC.h"
#include "S32K342_INTM.h"
#include "S32K342_JDC.h"
#include "S32K342_LCU.h"
#include "S32K342_LPCMP.h"
#include "S32K342_LPI2C.h"
#include "S32K342_LPSPI.h"
#include "S32K342_LPUART.h"
#include "S32K342_MCM_CM7.h"
#include "S32K342_MC_CGM.h"
#include "S32K342_MC_ME.h"
#include "S32K342_MC_RGM.h"
#include "S32K342_MDM_AP.h"
#include "S32K342_MSCM.h"
#include "S32K342_MU.h"
#include "S32K342_PFLASH.h"
#include "S32K342_PIT.h"
#include "S32K342_PLL.h"
#include "S32K342_PMC.h"
#include "S32K342_PRAMC.h"
#include "S32K342_QUADSPI.h"
#include "S32K342_QUADSPI_ARDB.h"
#include "S32K342_RTC.h"
#include "S32K342_SAI.h"
#include "S32K342_SDA_AP.h"
#include "S32K342_SEMA42.h"
#include "S32K342_SIRC.h"
#include "S32K342_SIUL2.h"
#include "S32K342_STCU.h"
#include "S32K342_STM.h"
#include "S32K342_SWT.h"
#include "S32K342_SXOSC.h"
#include "S32K342_TEMPSENSE.h"
#include "S32K342_TRGMUX.h"
#include "S32K342_TSPC.h"
#include "S32K342_VIRT_WRAPPER.h"
#include "S32K342_WKPU.h"
#include "S32K342_XBIC.h"
#include "S32K342_XRDC.h"
#include "S32K342_NVIC.h"
#include "S32K342_SCB.h"
#include "S32K342_SYSTICK.h"
#include "S32K342_MPU.h"
#endif  /* #if !defined(S32K342_H_) */
