/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CE_TRANSFORM_H
#define FSL_CE_TRANSFORM_H

#include <stdint.h>

/*!
 * @ingroup ce
 * @defgroup ce_transform CE Transform Functions
 * @brief Functional API definitions for CE FFT functions.
 * @{
 */

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
 * @brief Calculates N point FFT of a Nx1 vector
 *
 * Calculates Y = fft(X) where X is a Nx1 complex vector
 *
 * Data precision and format is as defined by the argument type (except
 * *float* is used for float16 data type as well to denote the pointer value)
 *
 * @param pY Pointer to buffer for FFT output
 * @param pX Pointer to buffer for FFT input
 * @param pScratch Pointer to scratch buffer. Must be equal to or greater than size of the output buffer
 * @param log2N log2(N), where N is the FFT size
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_TransformCFFT_F16(float *pY, float *pX, float *pScratch, int log2N);

/*!
 * @copydoc CE_TransformCFFT_F16
 */
int CE_TransformCFFT_F32(float *pY, float *pX, float *pScratch, int log2N);

/*!
 * @brief Calculates N point IFFT of a Nx1 vector
 *
 * Calculates Y = ifft(X) where X is a Nx1 complex vector
 *
 * Data precision and format is as defined by the argument type (except
 * *float* is used for float16 data type as well to denote the pointer value)
 *
 * @param pY Pointer to buffer for IFFT output
 * @param pX Pointer to buffer for IFFT input
 * @param pScratch Pointer to scratch buffer. Must be equal to or greater than size of the output buffer
 * @param log2N log2(N), where N is the IFFT size
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_TransformIFFT_F16(float *pY, float *pX, float *pScratch, int log2N);

/*!
 * @copydoc CE_TransformIFFT_F16
 */
int CE_TransformIFFT_F32(float *pY, float *pX, float *pScratch, int log2N);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_TRANSFORM_H*/
