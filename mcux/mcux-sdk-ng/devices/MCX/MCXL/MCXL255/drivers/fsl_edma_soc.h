/*
 * Copyright 2022 NXP
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
/*! @brief Driver version 1.0.0. */
#define FSL_EDMA_SOC_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/

/*!@brief DMA IP version */
#define FSL_EDMA_SOC_IP_DMA3 (1)
#define FSL_EDMA_SOC_IP_DMA4 (0)

/*!@brief DMA base table */
#define EDMA_BASE_PTRS \
    {                  \
        DMA0, DMA1           \
    }

#define EDMA_CHN_IRQS     \
    {                     \
        {                 \
            DMA0_CH0_IRQn, \
            DMA0_CH1_IRQn, \
            DMA0_CH2_IRQn, \
            DMA0_CH3_IRQn, \
        },                \
        {                 \
            DMA1_CH0_IRQn, \
            DMA1_CH1_IRQn, \
            DMA1_CH2_IRQn, \
            DMA1_CH3_IRQn, \
        },                \
    }

#define FSL_FEATURE_EDMA_HAS_GLOBAL_MASTER_ID_REPLICATION    (1)
#define FSL_FEATURE_EDMA_HAS_CONTINUOUS_LINK_MODE            (0)
#define FSL_FEATURE_EDMA_MODULE_COUNT                        (2)
#define FSL_FEATURE_EDMA_HAS_CHANNEL_CONFIG                  (1)
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SWAP_SIZE               (0)
#define FSL_FEATURE_EDMA_HAS_CHANNEL_ACCESS_TYPE             (0)
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MEMRORY_ATTRIBUTE       (0)
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SIGN_EXTENSION          (0)
#define FSL_FEATURE_EDMA_MODULE_SUPPORT_MATTR(base)          (0U)
#define FSL_FEATURE_EDMA_MODULE_SUPPORT_SIGN_EXTENSION(base) (0U)
#define FSL_FEATURE_EDMA_MODULE_SUPPORT_SWAP(base)           (0U)
#define FSL_FEATURE_EDMA_MODULE_SUPPORT_INSTR(base)          (0U)

/*!@brief EDMA base address convert macro */
#define EDMA_CHANNEL_OFFSET           0x1000U
#define EDMA_CHANNEL_ARRAY_STEP(base) (0x1000U)

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
