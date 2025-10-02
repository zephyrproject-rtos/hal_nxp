/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for ARM API compatible FFT functions on CE
==========================================================================*/

#include "fsl_ce_cmsis.h"
#include "fsl_ce_cmd.h"
#include "fsl_ce_transform.h"

/*!
 * brief CMSIS-compatible FFT implementation using ZV2117 backend.
 *
 * details This API is designed to be compatible with the ARM CM33 FFT interface.
 * It delegates the FFT computation to the ZV2117 CE module.
 * Please refer to CM33 documentation for details.
 *
 * return Command execution status.
 * 
 * note This API only support float32 FFTs.
 */
void ce_arm_cfft_f32(
    const arm_cfft_instance_f32 *S, float *p1, uint8_t ifftFlag, uint8_t bitReverseFlag, float *pOut, float *pScratch)
{
    int32_t l2N = 0;
    uint16_t temp = S->fftLen;

    if (temp > 0U)
    {
        while ((temp & 0x1U) != 1U)
        {
            temp = temp >> 1U;
            l2N++;
        }
    }

    if (ifftFlag == 0U)
    {
        (void)CE_TransformCFFT_F32(pOut, p1, pScratch, l2N);
    }
    else
    {
        (void)CE_TransformIFFT_F32(pOut, p1, pScratch, l2N);
    }
}
