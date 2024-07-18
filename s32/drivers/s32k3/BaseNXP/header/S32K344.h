/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K344.h
 * @version 1.9
 * @date 2021-10-27
 * @brief Peripheral Access Layer for S32K344
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K344_H_)  /* Check if memory map has not been already included */
#define S32K344_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K344_ADC.h"
#include "S32K344_AXBS_LITE.h"
#include "S32K344_BCTU.h"
#include "S32K344_CMU_FC.h"
#include "S32K344_CMU_FM.h"
#include "S32K344_CONFIGURATION_GPR.h"
#include "S32K344_CRC.h"
#include "S32K344_DCM.h"
#include "S32K344_DCM_GPR.h"
#include "S32K344_DMA.h"
#include "S32K344_DMAMUX.h"
#include "S32K344_DMA_TCD.h"
#include "S32K344_EIM.h"
#include "S32K344_EMAC.h"
#include "S32K344_EMIOS.h"
#include "S32K344_ERM.h"
#include "S32K344_FCCU.h"
#include "S32K344_FIRC.h"
#include "S32K344_FLASH.h"
#include "S32K344_FLEXCAN.h"
#include "S32K344_FLEXIO.h"
#include "S32K344_FXOSC.h"
#include "S32K344_INTM.h"
#include "S32K344_JDC.h"
#include "S32K344_LCU.h"
#include "S32K344_LPCMP.h"
#include "S32K344_LPI2C.h"
#include "S32K344_LPSPI.h"
#include "S32K344_LPUART.h"
#include "S32K344_MCM_CM7.h"
#include "S32K344_MC_CGM.h"
#include "S32K344_MDM_AP.h"
#include "S32K344_MSCM.h"
#include "S32K344_MU.h"
#include "S32K344_PFLASH.h"
#include "S32K344_PIT.h"
#include "S32K344_PLL.h"
#include "S32K344_PRAMC.h"
#include "S32K344_QUADSPI.h"
#include "S32K344_QUADSPI_ARDB.h"
#include "S32K344_RTC.h"
#include "S32K344_SAI.h"
#include "S32K344_SDA_AP.h"
#include "S32K344_SELFTEST_GPR.h"
#include "S32K344_SEMA42.h"
#include "S32K344_SIRC.h"
#include "S32K344_STCU.h"
#include "S32K344_SXOSC.h"
#include "S32K344_TEMPSENSE.h"
#include "S32K344_TRGMUX.h"
#include "S32K344_TSPC.h"
#include "S32K344_VIRT_WRAPPER.h"
#include "S32K344_XBIC.h"
#include "S32K344_XRDC.h"
#include "S32K344_NVIC.h"
#include "S32K344_SCB.h"
#include "S32K344_SYSTICK.h"
#include "S32K344_MPU.h"

#endif  /* #if !defined(S32K344_H_) */
