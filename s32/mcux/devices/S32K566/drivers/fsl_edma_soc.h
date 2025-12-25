/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_EDMA_SOC_H_
#define _FSL_EDMA_SOC_H_

#include "fsl_common.h"

/*!
 * @addtogroup edma_soc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief Driver version 2.0.0. */
#define FSL_EDMA_SOC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!@brief DMA IP version */
#define FSL_EDMA_SOC_IP_DMA3 (1)
#define FSL_EDMA_SOC_IP_DMA5 (1)

/*!@brief DMA base table */
#define EDMA_BASE_PTRS \
    {                  \
        IP_LPE_EDMA3, IP_EDMA5   \
    }

#if defined(CONFIG_CPU_CORTEX_M7)
#define EDMA_CHN_IRQS                                                                                                           \
    {                                                                                                                           \
        {                                                                                                                       \
            CM7_LPE_eDMA3_TCD0_1_INT_IRQn, CM7_LPE_eDMA3_TCD2_3_INT_IRQn, CM7_LPE_eDMA3_TCD4_5_INT_IRQn,                        \
            CM7_LPE_eDMA3_TCD6_7_INT_IRQn, CM7_LPE_eDMA3_TCD8_9_INT_IRQn, CM7_LPE_eDMA3_TCD10_11_INT_IRQn                       \
        },                                                                                                                      \
        {                                                                                                                       \
            CM7_eDMA5_TCD0_2_INT_IRQn, CM7_eDMA5_TCD2_3_INT_IRQn, CM7_eDMA5_TCD4_5_INT_IRQn, CM7_eDMA5_TCD6_7_INT_IRQn,         \
            CM7_eDMA5_TCD8_9_INT_IRQn, CM7_eDMA5_TCD10_11_INT_IRQn, CM7_eDMA5_TCD12_13_INT_IRQn, CM7_eDMA5_TCD14_15_INT_IRQn,   \
            CM7_eDMA5_TCD16_17_INT_IRQn, CM7_eDMA5_TCD18_19_INT_IRQn, CM7_eDMA5_TCD20_21_INT_IRQn, CM7_eDMA5_TCD22_23_INT_IRQn, \
            CM7_eDMA5_TCD24_25_INT_IRQn, CM7_eDMA5_TCD26_27_INT_IRQn, CM7_eDMA5_TCD28_29_INT_IRQn, CM7_eDMA5_TCD30_31_INT_IRQn  \
        }                                                                                                                       \
    }
#else
#define EDMA_CHN_IRQS                                                                                                           \
    {                                                                                                                           \
        {                                                                                                                       \
            R52_LPE_eDMA3_TCD0_1_INT_IRQn, R52_LPE_eDMA3_TCD2_3_INT_IRQn, R52_LPE_eDMA3_TCD4_5_INT_IRQn,                        \
            R52_LPE_eDMA3_TCD6_7_INT_IRQn, R52_LPE_eDMA3_TCD8_9_INT_IRQn, R52_LPE_eDMA3_TCD10_11_INT_IRQn                       \
        },                                                                                                                      \
        {                                                                                                                       \
            R52_eDMA5_TCD0_2_INT_IRQn, R52_eDMA5_TCD2_3_INT_IRQn, R52_eDMA5_TCD4_5_INT_IRQn, R52_eDMA5_TCD6_7_INT_IRQn,         \
            R52_eDMA5_TCD8_9_INT_IRQn, R52_eDMA5_TCD10_11_INT_IRQn, R52_eDMA5_TCD12_13_INT_IRQn, R52_eDMA5_TCD14_15_INT_IRQn,   \
            R52_eDMA5_TCD16_17_INT_IRQn, R52_eDMA5_TCD18_19_INT_IRQn, R52_eDMA5_TCD20_21_INT_IRQn, R52_eDMA5_TCD22_23_INT_IRQn, \
            R52_eDMA5_TCD24_25_INT_IRQn, R52_eDMA5_TCD26_27_INT_IRQn, R52_eDMA5_TCD28_29_INT_IRQn, R52_eDMA5_TCD30_31_INT_IRQn  \
        }                                                                                                                       \
    }
#endif

/*!@brief EDMA base address convert macro */
#define EDMA_CHANNEL_OFFSET           0x4000U

#define __EDMA_STEP_BY_CH(ch)                                                          \
    ( ((unsigned)(ch) < 16u)                                                           \
        ? ( ((unsigned)(ch) >> 2) * 0x10000u +                                         \
            ( ((unsigned)(ch) & 3u) == 0u ? 0x0000u :                                  \
              ((unsigned)(ch) & 3u) == 1u ? 0x2000u :                                  \
              ((unsigned)(ch) & 3u) == 2u ? 0x8000u : 0xA000u ) )                      \
        : ( 0x600000u +                                                                \
            ((((unsigned)(ch) - 16u) & ~1u) << 14)                                      \
          + ((((unsigned)(ch) - 16u) & 1u)  << 13)                                      \
          + 0x0C000u ) )

#define EDMA_CHANNEL_ARRAY_STEPn(base, channel) (__EDMA_STEP_BY_CH(channel))

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* _FSL_EDMA_SOC_H_ */
