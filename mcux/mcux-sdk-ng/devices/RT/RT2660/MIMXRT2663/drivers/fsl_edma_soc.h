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
         MAIN__EDMA3, MAIN__EDMA5, AUDIO__EDMA3, WAKE__EDMA3  \
    }


#define EDMA_CHN_IRQS                                                                                               \
    {                                                                                                               \
        {                                                                                                           \
            MAIN_EDMA3_CH0_IRQn, MAIN_EDMA3_CH1_IRQn, MAIN_EDMA3_CH2_IRQn, MAIN_EDMA3_CH3_IRQn, MAIN_EDMA3_CH4_IRQn, MAIN_EDMA3_CH5_IRQn, MAIN_EDMA3_CH6_IRQn, MAIN_EDMA3_CH7_IRQn, \
                MAIN_EDMA3_CH8_IRQn, MAIN_EDMA3_CH9_IRQn, MAIN_EDMA3_CH10_IRQn, MAIN_EDMA3_CH11_IRQn, MAIN_EDMA3_CH12_IRQn, MAIN_EDMA3_CH13_IRQn, MAIN_EDMA3_CH14_IRQn, MAIN_EDMA3_CH15_IRQn, \
                MAIN_EDMA3_CH16_IRQn, MAIN_EDMA3_CH17_IRQn, MAIN_EDMA3_CH18_IRQn, MAIN_EDMA3_CH19_IRQn, MAIN_EDMA3_CH20_IRQn, MAIN_EDMA3_CH21_IRQn, MAIN_EDMA3_CH22_IRQn, MAIN_EDMA3_CH23_IRQn, \
                MAIN_EDMA3_CH24_IRQn, MAIN_EDMA3_CH25_IRQn, MAIN_EDMA3_CH26_IRQn, MAIN_EDMA3_CH27_IRQn, MAIN_EDMA3_CH28_IRQn, MAIN_EDMA3_CH29_IRQn, MAIN_EDMA3_CH30_IRQn, MAIN_EDMA3_CH31_IRQn, \
        },                                                                                                           \
        {                                                                                                             \
            MAIN_EDMA5_CH0_IRQn, MAIN_EDMA5_CH1_IRQn, MAIN_EDMA5_CH2_IRQn, MAIN_EDMA5_CH3_IRQn, MAIN_EDMA5_CH4_IRQn, MAIN_EDMA5_CH5_IRQn, MAIN_EDMA5_CH6_IRQn, MAIN_EDMA5_CH7_IRQn,     \
                MAIN_EDMA5_CH8_IRQn, MAIN_EDMA5_CH9_IRQn, MAIN_EDMA5_CH10_IRQn, MAIN_EDMA5_CH11_IRQn, MAIN_EDMA5_CH12_IRQn, MAIN_EDMA5_CH13_IRQn, MAIN_EDMA5_CH14_IRQn, MAIN_EDMA5_CH15_IRQn,   \
        },                                                                                                             \
        {                                                                                                             \
            AUDIO_EDMA3_CH0_IRQn, AUDIO_EDMA3_CH1_IRQn, AUDIO_EDMA3_CH2_IRQn, AUDIO_EDMA3_CH3_IRQn, AUDIO_EDMA3_CH4_IRQn, AUDIO_EDMA3_CH5_IRQn, AUDIO_EDMA3_CH6_IRQn, AUDIO_EDMA3_CH7_IRQn, \
        },                                                                                                            \
        { \
            WAKE_EDMA3_CH0_IRQn, WAKE_EDMA3_CH1_IRQn, WAKE_EDMA3_CH2_IRQn, WAKE_EDMA3_CH3_IRQn, WAKE_EDMA3_CH4_IRQn, WAKE_EDMA3_CH5_IRQn, WAKE_EDMA3_CH6_IRQn, WAKE_EDMA3_CH7_IRQn, \
        } \
    }

/*!@brief EDMA base address convert macro */
#define EDMA_CHANNEL_OFFSET           0x10000U
#define EDMA_CHANNEL_ARRAY_STEP(base) 0x10000U

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
