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
#define FSL_EDMA_SOC_IP_DMA5 (1)

/*!@brief DMA base table */
#define EDMA_BASE_PTRS  \
    {                   \
        IP_EDMA5        \
    }

#if defined(CONFIG_CPU_CORTEX_M7)
#define EDMA_CHN_IRQS                                                                                                           \
    {                                                                                                                           \
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
            R52_eDMA5_TCD0_2_INT_IRQn, R52_eDMA5_TCD2_3_INT_IRQn, R52_eDMA5_TCD4_5_INT_IRQn, R52_eDMA5_TCD6_7_INT_IRQn,         \
            R52_eDMA5_TCD8_9_INT_IRQn, R52_eDMA5_TCD10_11_INT_IRQn, R52_eDMA5_TCD12_13_INT_IRQn, R52_eDMA5_TCD14_15_INT_IRQn,   \
            R52_eDMA5_TCD16_17_INT_IRQn, R52_eDMA5_TCD18_19_INT_IRQn, R52_eDMA5_TCD20_21_INT_IRQn, R52_eDMA5_TCD22_23_INT_IRQn, \
            R52_eDMA5_TCD24_25_INT_IRQn, R52_eDMA5_TCD26_27_INT_IRQn, R52_eDMA5_TCD28_29_INT_IRQn, R52_eDMA5_TCD30_31_INT_IRQn  \
        }                                                                                                                       \
    }
#endif

/*!@brief EDMA base address convert macro */
#define EDMA_CHANNEL_OFFSET           0x4000U

#define EDMA_CHANNEL_ARRAY_STEPn(base, ch)                                           \
    (                                                                                \
        /* Base offset per channel pair */                                           \
        ((uint32_t)(ch) >> 1) * (2U * EDMA_CHANNEL_OFFSET)                           \
        /* Odd channel offset within the pair */                                     \
        + (((uint32_t)(ch) & 1U) * (EDMA_CHANNEL_OFFSET / 2U))                       \
        /* Jump to next block */                                                     \
        + (((uint32_t)(ch) >= 16U) * (0x60C000U - 8U * (2U * EDMA_CHANNEL_OFFSET)))  \
    )

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
