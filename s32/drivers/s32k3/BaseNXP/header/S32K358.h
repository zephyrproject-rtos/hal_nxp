/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K358.h
 * @version 1.1
 * @date 2022-10-01
 * @brief Peripheral Access Layer for S32K358
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K358_H_)  /* Check if memory map has not been already included */
#define S32K358_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K358_ADC.h"
#include "S32K358_AXBS_LITE.h"
#include "S32K358_BCTU.h"
#include "S32K358_CMU_FC.h"
#include "S32K358_CMU_FM.h"
#include "S32K358_CONFIGURATION_GPR.h"
#include "S32K358_CRC.h"
#include "S32K358_DCM.h"
#include "S32K358_DCM_GPR.h"
#include "S32K358_DMAMUX.h"
#include "S32K358_DMA_TCD.h"
#include "S32K358_EDMA.h"
#include "S32K358_EIM.h"
#include "S32K358_EMIOS.h"
#include "S32K358_ERM.h"
#include "S32K358_FCCU.h"
#include "S32K358_FIRC.h"
#include "S32K358_FLASH.h"
#include "S32K358_FLEXCAN.h"
#include "S32K358_FLEXIO.h"
#include "S32K358_FXOSC.h"
#include "S32K358_GMAC.h"
#include "S32K358_INTM.h"
#include "S32K358_JDC.h"
#include "S32K358_LCU.h"
#include "S32K358_LPCMP.h"
#include "S32K358_LPI2C.h"
#include "S32K358_LPSPI.h"
#include "S32K358_LPUART.h"
#include "S32K358_MCM_CM7.h"
#include "S32K358_MC_CGM.h"
#include "S32K358_MC_ME.h"
#include "S32K358_MC_RGM.h"
#include "S32K358_MDM_AP.h"
#include "S32K358_MSCM.h"
#include "S32K358_MU.h"
#include "S32K358_PFLASH.h"
#include "S32K358_PIT.h"
#include "S32K358_PLL.h"
#include "S32K358_PMC.h"
#include "S32K358_PRAMC.h"
#include "S32K358_QUADSPI.h"
#include "S32K358_QUADSPI_ARDB.h"
#include "S32K358_RTC.h"
#include "S32K358_SAI.h"
#include "S32K358_SDA_AP.h"
#include "S32K358_SELFTEST_GPR.h"
#include "S32K358_SEMA42.h"
#include "S32K358_SIRC.h"
#include "S32K358_SIUL2.h"
#include "S32K358_STCU.h"
#include "S32K358_STM.h"
#include "S32K358_SWT.h"
#include "S32K358_SXOSC.h"
#include "S32K358_TEMPSENSE.h"
#include "S32K358_TRGMUX.h"
#include "S32K358_TSPC.h"
#include "S32K358_USDHC.h"
#include "S32K358_VIRT_WRAPPER.h"
#include "S32K358_WKPU.h"
#include "S32K358_XBIC.h"
#include "S32K358_XRDC.h"
#include "S32K358_NVIC.h"
#include "S32K358_SCB.h"
#include "S32K358_SYSTICK.h"
#include "S32K358_MPU.h"
#endif  /* #if !defined(S32K358_H_) */
