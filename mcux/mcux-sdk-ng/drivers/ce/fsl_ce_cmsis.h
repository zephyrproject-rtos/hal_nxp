/*
 * Copyright 2024 NXP
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
 * @brief Functional API definitions CMSIS compatible functions
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief FFT/IFFT float32 */
typedef struct
{
    uint16_t fftLen;              /**< length of the FFT. */
    const float *pTwiddle;        /**< points to the Twiddle factor table. */
    const uint16_t *pBitRevTable; /**< points to the bit reversal table. */
    uint16_t bitRevLength;        /**< bit reversal table length. */
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
