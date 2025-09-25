/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CE_TRANSFORM_H
#define FSL_CE_TRANSFORM_H

#include <stdint.h>

// define FFT Error Codes
#define FFT_ERROR_SZOUTSIDERANGE 0xE00B

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
 * @brief Computes the FFT of complex-valued 16-bit floating point data.
 *
 * @details Performs an N-point Fast Fourier Transform (FFT) on
 * a complex-valued float16 input stream. The FFT size N must be a power of 2,
 * with valid range: 16 ≤ N ≤ 16384.
 *
 * @param [out] pY       Pointer to the FFT output buffer (complex-valued float16 data).
 * @param [in]  pX       Pointer to the FFT input buffer (complex-valued float16 data).
 * @param [in]  pScratch Pointer to a scratch buffer (at least N × 4 bytes).
 * @param [in]  log2N    Base-2 logarithm of the FFT size N.
 *
 * @return Command execution status.
 *
 * @note
 * - Data precision and format follow the argument types.
 * - `float*` is used to represent float16 pointers.
 * - The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformCFFT_F16(float *pY, float *pX, float *pScratch, int32_t log2N);

/*!
 * @brief Computes the FFT of complex-valued 32-bit floating point data.
 *
 * @details Performs an N-point Fast Fourier Transform (FFT) on
 * a complex-valued float32 input stream. The FFT size N must be a power of 2,
 * with valid range: 32 ≤ N ≤ 16384.
 *
 * @param [out] pY       Pointer to the FFT output buffer (complex-valued float32).
 * @param [in]  pX       Pointer to the FFT input buffer (complex-valued float32).
 * @param [in]  pScratch Pointer to a scratch buffer (at least N × 8 bytes).
 * @param [in]  log2N    Base-2 logarithm of the FFT size N.
 *
 * @return Command execution status.
 *
 * @note The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformCFFT_F32(float *pY, float *pX, float *pScratch, int32_t log2N);

/*!
 * @brief Computes the IFFT of complex-valued 16-bit floating point data.
 *
 * @details Performs an N-point Inverse Fast Fourier Transform (IFFT) on
 * a complex-valued float16 input stream. The IFFT size N must be a power of 2,
 * with valid range: 16 ≤ N ≤ 16384.
 * 
 * @param [out] pY       Pointer to the IFFT output buffer (complex-valued float16).
 * @param [in]  pX       Pointer to the IFFT input buffer (complex-valued float16).
 * @param [in]  pScratch Pointer to a scratch buffer (at least N × 4 bytes).
 * @param [in]  log2N    Base-2 logarithm of the IFFT size N.
 *
 * @return Command execution status.
 *
 * @note
 * - Data precision and format follow the argument types.
 * - `float*` is used to represent float16 pointers.
 * - The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformIFFT_F16(float *pY, float *pX, float *pScratch, int32_t log2N);

/*!
 * @brief Computes the IFFT of complex-valued 32-bit floating point data.
 *
 * 
 * @details Performs an N-point Inverse Fast Fourier Transform (IFFT) on
 * a complex-valued float32 input stream. The IFFT size N must be a power of 2,
 * with valid range: 32 ≤ N ≤ 16384.
 *
 * @param [out] pY       Pointer to the IFFT output buffer (complex-valued float32).
 * @param [in]  pX       Pointer to the IFFT input buffer (complex-valued float32).
 * @param [in]  pScratch Pointer to a scratch buffer (at least N × 8 bytes).
 * @param [in]  log2N    Base-2 logarithm of the IFFT size N.
 *
 * @return Command execution status.
 *
 * @note The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformIFFT_F32(float *pY, float *pX, float *pScratch, int32_t log2N);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_TRANSFORM_H*/
