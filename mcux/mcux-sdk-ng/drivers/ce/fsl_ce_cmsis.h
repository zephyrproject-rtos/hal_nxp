/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CE_CMSIS_H
#define FSL_CE_CMSIS_H

#include <stdint.h>

/*!
 * @ingroup ce
 * @defgroup ce_cmsis CE CMSIS Functions
 * @brief Functional API definitions for CMSIS compatible functions
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief FFT/IFFT float32 */
typedef struct
{
    uint16_t fftLen;              /*!< Length of the FFT. */
    const float *pTwiddle;        /*!< Points to the twiddle factor table. */
    const uint16_t *pBitRevTable; /*!< Points to the bit reversal table. */
    uint16_t bitRevLength;        /*!< Length of the bit reversal table. */
} arm_cfft_instance_f32;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief CMSIS-compatible FFT implementation using ZV2117 backend.
 *
 * @details This API is designed to be compatible with the ARM CM33 FFT interface.
 * It delegates the FFT computation to the ZV2117 CE module.
 * Please refer to CM33 documentation for details.
 * 
 * @note This API only support float32 FFTs.
 */
void ce_arm_cfft_f32(const arm_cfft_instance_f32 *S,
                     float *p1, /* input pointer */
                     uint8_t ifftFlag,
                     uint8_t bitReverseFlag,
                     float *pOut,      /* output pointer */
                     float *pScratch); /* scratch pointer; size should be FFTsize*8 Bytes */

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_CMSIS_H*/
