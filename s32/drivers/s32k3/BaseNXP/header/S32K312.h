/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K312.h
 * @version 1.4
 * @date 2022-06-20
 * @brief Peripheral Access Layer for S32K312
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K312_H_)  /* Check if memory map has not been already included */
#define S32K312_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K312_ADC.h"
#include "S32K312_BCTU.h"
#include "S32K312_CMU_FC.h"
#include "S32K312_CMU_FM.h"
#include "S32K312_CONFIGURATION_GPR.h"
#include "S32K312_CRC.h"
#include "S32K312_DCM.h"
#include "S32K312_DCM_GPR.h"
#include "S32K312_DMA.h"
#include "S32K312_DMAMUX.h"
#include "S32K312_DMA_TCD.h"
#include "S32K312_EIM.h"
#include "S32K312_EMIOS.h"
#include "S32K312_ERM.h"
#include "S32K312_FCCU.h"
#include "S32K312_FIRC.h"
#include "S32K312_FLASH.h"
#include "S32K312_FLEXCAN.h"
#include "S32K312_FLEXIO.h"
#include "S32K312_FXOSC.h"
#include "S32K312_INTM.h"
#include "S32K312_JDC.h"
#include "S32K312_LCU.h"
#include "S32K312_LPCMP.h"
#include "S32K312_LPI2C.h"
#include "S32K312_LPSPI.h"
#include "S32K312_LPUART.h"
#include "S32K312_MCM_CM7.h"
#include "S32K312_MC_CGM.h"
#include "S32K312_MC_ME.h"
#include "S32K312_MC_RGM.h"
#include "S32K312_MDM_AP.h"
#include "S32K312_MSCM.h"
#include "S32K312_MU.h"
#include "S32K312_PFLASH.h"
#include "S32K312_PIT.h"
#include "S32K312_PLL.h"
#include "S32K312_PMC.h"
#include "S32K312_PRAMC.h"
#include "S32K312_RTC.h"
#include "S32K312_SDA_AP.h"
#include "S32K312_SIRC.h"
#include "S32K312_SIUL2.h"
#include "S32K312_STCU.h"
#include "S32K312_STM.h"
#include "S32K312_SWT.h"
#include "S32K312_SXOSC.h"
#include "S32K312_TEMPSENSE.h"
#include "S32K312_TRGMUX.h"
#include "S32K312_TSPC.h"
#include "S32K312_VIRT_WRAPPER.h"
#include "S32K312_WKPU.h"
#include "S32K312_XBIC.h"
#include "S32K312_XRDC.h"
#include "S32K312_NVIC.h"
#include "S32K312_SCB.h"
#include "S32K312_SYSTICK.h"
#include "S32K312_MPU.h"

#endif  /* #if !defined(S32K312_H_) */
