/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K311.h
 * @version 1.2
 * @date 2023-01-10
 * @brief Peripheral Access Layer for S32K311
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K311_H_)  /* Check if memory map has not been already included */
#define S32K311_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K311_ADC.h"
#include "S32K311_BCTU.h"
#include "S32K311_CMU_FC.h"
#include "S32K311_CMU_FM.h"
#include "S32K311_CONFIGURATION_GPR.h"
#include "S32K311_CRC.h"
#include "S32K311_DCM.h"
#include "S32K311_DCM_GPR.h"
#include "S32K311_DMAMUX.h"
#include "S32K311_DMA_TCD.h"
#include "S32K311_EDMA.h"
#include "S32K311_EIM.h"
#include "S32K311_EMIOS.h"
#include "S32K311_ERM.h"
#include "S32K311_FCCU.h"
#include "S32K311_FIRC.h"
#include "S32K311_FLASH.h"
#include "S32K311_FLEXCAN.h"
#include "S32K311_FLEXIO.h"
#include "S32K311_FXOSC.h"
#include "S32K311_INTM.h"
#include "S32K311_JDC.h"
#include "S32K311_LCU.h"
#include "S32K311_LPCMP.h"
#include "S32K311_LPI2C.h"
#include "S32K311_LPSPI.h"
#include "S32K311_LPUART.h"
#include "S32K311_MCM_CM7.h"
#include "S32K311_MC_CGM.h"
#include "S32K311_MC_ME.h"
#include "S32K311_MC_RGM.h"
#include "S32K311_MDM_AP.h"
#include "S32K311_MSCM.h"
#include "S32K311_MU.h"
#include "S32K311_PFLASH.h"
#include "S32K311_PIT.h"
#include "S32K311_PLL.h"
#include "S32K311_PMC.h"
#include "S32K311_PRAMC.h"
#include "S32K311_RTC.h"
#include "S32K311_SDA_AP.h"
#include "S32K311_SIRC.h"
#include "S32K311_SIUL2.h"
#include "S32K311_STCU.h"
#include "S32K311_STM.h"
#include "S32K311_SWT.h"
#include "S32K311_TEMPSENSE.h"
#include "S32K311_TRGMUX.h"
#include "S32K311_TSPC.h"
#include "S32K311_VIRT_WRAPPER.h"
#include "S32K311_WKPU.h"
#include "S32K311_XBIC.h"
#include "S32K311_XRDC.h"
#include "S32K311_NVIC.h"
#include "S32K311_SCB.h"
#include "S32K311_SYSTICK.h"
#include "S32K311_MPU.h"

#endif  /* #if !defined(S32K311_H_) */
