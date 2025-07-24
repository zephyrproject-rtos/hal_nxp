/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_EDMA_SOC_H_
#define FSL_EDMA_SOC_H_

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
#define FSL_EDMA_SOC_IP_DMA4 (0)

/*!@brief DMA base table */
#define EDMA_BASE_PTRS \
    {                  \
        EDMA           \
    }

#if (FSL_FEATURE_EDMA_MODULE_CHANNEL == 32U)
#define EDMA_CHN_IRQS                                                                                             \
    {                                                                                                             \
        {DMATCD0_IRQn,  DMATCD1_IRQn,  DMATCD2_IRQn,  DMATCD3_IRQn,  DMATCD4_IRQn,  DMATCD5_IRQn,  DMATCD6_IRQn,  \
         DMATCD7_IRQn,  DMATCD8_IRQn,  DMATCD9_IRQn,  DMATCD10_IRQn, DMATCD11_IRQn, DMATCD12_IRQn, DMATCD13_IRQn, \
         DMATCD14_IRQn, DMATCD15_IRQn, DMATCD16_IRQn, DMATCD17_IRQn, DMATCD18_IRQn, DMATCD19_IRQn, DMATCD20_IRQn, \
         DMATCD21_IRQn, DMATCD22_IRQn, DMATCD23_IRQn, DMATCD24_IRQn, DMATCD25_IRQn, DMATCD26_IRQn, DMATCD27_IRQn, \
         DMATCD28_IRQn, DMATCD29_IRQn, DMATCD30_IRQn, DMATCD31_IRQn},                                             \
    }
#else /* 12 Channels */
#define EDMA_CHN_IRQS                                                                                             \
    {                                                                                                             \
        {DMATCD0_IRQn,  DMATCD1_IRQn,  DMATCD2_IRQn,  DMATCD3_IRQn,  DMATCD4_IRQn,  DMATCD5_IRQn,  DMATCD6_IRQn,  \
         DMATCD7_IRQn,  DMATCD8_IRQn,  DMATCD9_IRQn,  DMATCD10_IRQn, DMATCD11_IRQn},                              \
    }
#endif /* FSL_FEATURE_EDMA_MODULE_CHANNEL == 32U */

/*!@brief EDMA base address convert macro */
#define EDMA_CHANNEL_OFFSET 0x4000U
#define EDMA_CHANNEL_ARRAY_STEPn(base, channel) ((channel) > 11U ? (0x200000U + ((channel) - 12U) * 0x4000U) : ((channel) * 0x4000U))

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

#endif /* FSL_EDMA_SOC_H_ */
