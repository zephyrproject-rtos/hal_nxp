/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for CE wrapper/driver FFT functions on ARM
==========================================================================*/

#include "fsl_ce_transform.h"
#include "fsl_ce_cmd.h"

/*!
 * brief Computes the FFT of complex-valued 16-bit floating point data.
 *
 * details Performs an N-point Fast Fourier Transform (FFT) on
 * a complex-valued float16 input stream. The FFT size N must be a power of 2,
 * with valid range: 16 ≤ N ≤ 16384.
 *
 * param [out] pY       Pointer to the FFT output buffer (complex-valued float16 data).
 * param [in]  pX       Pointer to the FFT input buffer (complex-valued float16 data).
 * param [in]  pScratch Pointer to a scratch buffer (at least N × 4 bytes).
 * param [in]  log2N    Base-2 logarithm of the FFT size N.
 *
 * return Command execution status.
 *
 * note
 * - Data precision and format follow the argument types.
 * - `float*` is used to represent float16 pointers.
 * - The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformCFFT_F16(float *pY, float *pX, float *pScratch, int32_t log2N)
{
    int32_t status;

    if (log2N < 5 || log2N > 15)
    {
        status = FFT_ERROR_SZOUTSIDERANGE;
        return status;
    }

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_CFFT_F16, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

/*!
 * brief Computes the FFT of complex-valued 32-bit floating point data.
 *
 * details Performs an N-point Fast Fourier Transform (FFT) on
 * a complex-valued float32 input stream. The FFT size N must be a power of 2,
 * with valid range: 32 ≤ N ≤ 16384.
 *
 * param [out] pY       Pointer to the FFT output buffer (complex-valued float32).
 * param [in]  pX       Pointer to the FFT input buffer (complex-valued float32).
 * param [in]  pScratch Pointer to a scratch buffer (at least N × 8 bytes).
 * param [in]  log2N    Base-2 logarithm of the FFT size N.
 *
 * return Command execution status.
 *
 * note The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformCFFT_F32(float *pY, float *pX, float *pScratch, int32_t log2N)
{
    int32_t status;

    if (log2N < 4 || log2N > 15)
    {
        status = FFT_ERROR_SZOUTSIDERANGE;
        return status;
    }

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_CFFT_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

/*!
 * brief Computes the IFFT of complex-valued 16-bit floating point data.
 *
 * details Performs an N-point Inverse Fast Fourier Transform (IFFT) on
 * a complex-valued float16 input stream. The IFFT size N must be a power of 2,
 * with valid range: 16 ≤ N ≤ 16384.
 * 
 * param [out] pY       Pointer to the IFFT output buffer (complex-valued float16).
 * param [in]  pX       Pointer to the IFFT input buffer (complex-valued float16).
 * param [in]  pScratch Pointer to a scratch buffer (at least N × 4 bytes).
 * param [in]  log2N    Base-2 logarithm of the IFFT size N.
 *
 * return Command execution status.
 *
 * note
 * - Data precision and format follow the argument types.
 * - `float*` is used to represent float16 pointers.
 * - The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformIFFT_F16(float *pY, float *pX, float *pScratch, int32_t log2N)
{
    int32_t status;

    if (log2N < 5 || log2N > 15)
    {
        status = FFT_ERROR_SZOUTSIDERANGE;
        return status;
    }

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_IFFT_F16, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

/*!
 * brief Computes the IFFT of complex-valued 32-bit floating point data.
 *
 * 
 * details Performs an N-point Inverse Fast Fourier Transform (IFFT) on
 * a complex-valued float32 input stream. The IFFT size N must be a power of 2,
 * with valid range: 32 ≤ N ≤ 16384.
 *
 * param [out] pY       Pointer to the IFFT output buffer (complex-valued float32).
 * param [in]  pX       Pointer to the IFFT input buffer (complex-valued float32).
 * param [in]  pScratch Pointer to a scratch buffer (at least N × 8 bytes).
 * param [in]  log2N    Base-2 logarithm of the IFFT size N.
 *
 * return Command execution status.
 *
 * note The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_TransformIFFT_F32(float *pY, float *pX, float *pScratch, int32_t log2N)
{
    int32_t status;

    if (log2N < 4 || log2N > 15)
    {
        status = FFT_ERROR_SZOUTSIDERANGE;
        return status;
    }

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_IFFT_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}
