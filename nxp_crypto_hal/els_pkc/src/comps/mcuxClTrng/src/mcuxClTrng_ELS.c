/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

/** @file  mcuxClTrng_ELS.c
 *  @brief Implementation of the Trng component which provides APIs for
 *  handling of Trng random number. This file implements the functions
 *  declared in mcuxClTrng_Internal_Functions.h. */

#include <mcuxClToolchain.h>
#include <mcuxClSession.h>
#include <mcuxClEls.h>
#include <mcuxCsslMemory.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClTrng_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClTrng_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClTrng_Status_t) mcuxClTrng_Init(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClTrng_Init);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_Init, MCUXCLTRNG_STATUS_OK);
}

/*
 * @brief Function returns requested number of random bytes rounded down to full words.
 * 
 * @param[out]      pEntropyInput        pointer to entropy buffer
 * @param[in]       entropyInputLength   number of entropy bytes requested
 * @return status
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClTrng_getEntropyInput_fullBlocks)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClTrng_Status_t) mcuxClTrng_getEntropyInput_fullBlocks(
    uint32_t *pEntropyInput,
    uint32_t entropyInputLength
)
{
    uint32_t requestSizeELSrawRequest       = MCUXCLTRNG_ELS_TRNG_OUTPUT_SIZE;
    uint32_t remainingNonFullELSblockBytes  = entropyInputLength % requestSizeELSrawRequest;
    uint32_t fullELSblocksBytes             = entropyInputLength - remainingNonFullELSblockBytes;
    uint32_t fullELSblocks                  = fullELSblocksBytes/requestSizeELSrawRequest;

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClTrng_getEntropyInput_fullBlocks);
    /* Request as many random bytes as possible with full 32 bytes size. */
    if (fullELSblocksBytes > 0u)
    {
        for(uint32_t i = 0; i < fullELSblocks; i++)
        {
            MCUX_CSSL_FP_FUNCTION_CALL(ret_DTRNG_GetTrng1, mcuxClEls_Rng_DrbgRequestRaw_Async((uint8_t *)&pEntropyInput[i*MCUXCLTRNG_ELS_TRNG_OUTPUT_SIZE/sizeof(uint32_t)]));
            if(MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT == ret_DTRNG_GetTrng1)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput_fullBlocks, MCUXCLTRNG_STATUS_ERROR,
                    (i+1u) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Rng_DrbgRequestRaw_Async),
                    i * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
            }
            else if (MCUXCLELS_STATUS_OK_WAIT != ret_DTRNG_GetTrng1)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput_fullBlocks, MCUXCLTRNG_STATUS_FAULT_ATTACK);
            }
            else
            {
                /* Intentionally left empty */
            }

            MCUX_CSSL_FP_FUNCTION_CALL(ret_DRBG_Wait1, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));
            if((MCUXCLELS_STATUS_HW_OPERATIONAL == ret_DRBG_Wait1) || (MCUXCLELS_STATUS_HW_ALGORITHM == ret_DRBG_Wait1) || (MCUXCLELS_STATUS_HW_BUS == ret_DRBG_Wait1))
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput_fullBlocks, MCUXCLTRNG_STATUS_ERROR,
                    (i+1u) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Rng_DrbgRequestRaw_Async),
                    (i+1u) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
            }
            else if (MCUXCLELS_STATUS_OK != ret_DRBG_Wait1)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput_fullBlocks, MCUXCLTRNG_STATUS_FAULT_ATTACK);
            }
            else
            {
                /* Intentionally left empty */
            }
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput_fullBlocks, MCUXCLTRNG_STATUS_OK,
        (entropyInputLength / MCUXCLTRNG_ELS_TRNG_OUTPUT_SIZE) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Rng_DrbgRequestRaw_Async),
        (entropyInputLength / MCUXCLTRNG_ELS_TRNG_OUTPUT_SIZE) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClTrng_getEntropyInput)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClTrng_Status_t) mcuxClTrng_getEntropyInput(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    uint32_t *pEntropyInput,
    uint32_t entropyInputLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClTrng_getEntropyInput);

    /**
     * ELS DTRNG output size must be 32 bytes.
     * We first request as much as possible directly, and then use a small buffer
     * to copy up to 32 remaining bytes.
     */

    /**
     * Note: writing to pEntropyInput could be unaligned.
     * This could be improved by: - requesting a 32 bytes
     *                            - copying as many bytes as needed to achieve alignment
     *                            - requesting the following 32 bytes to aligned addresses
     *                            - possibly requesting another 32 bytes to fill the remaining bytes
     */

    /* Check if entropyInputLength is word aligned and pEntropyInput is not NULL*/
    if((0u != (entropyInputLength % sizeof(uint32_t))) || (NULL == pEntropyInput))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_ERROR);
    }

    uint32_t requestSizeELSrawRequest       = MCUXCLTRNG_ELS_TRNG_OUTPUT_SIZE;
    uint32_t remainingNonFullELSblockBytes  = entropyInputLength % requestSizeELSrawRequest;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("does not wrap since remainingNonFullELSblockBytes is not larger than entropyInputLength due to modulo operation")
    uint32_t fullELSblocksBytes             = entropyInputLength - remainingNonFullELSblockBytes;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Request as many random bytes as possible with full 32 bytes size. */

    MCUX_CSSL_FP_FUNCTION_CALL(ret_fullBlocks, mcuxClTrng_getEntropyInput_fullBlocks(pEntropyInput, entropyInputLength));
    if (MCUXCLTRNG_STATUS_OK != ret_fullBlocks)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, ret_fullBlocks, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_getEntropyInput_fullBlocks));
    }

    /* If requested size is not a multiple of 32, request one (additional) 32 bytes and use it only partially. */
    if (remainingNonFullELSblockBytes > 0u)
    {
        uint8_t requestRemainingBuffer[MCUXCLTRNG_ELS_TRNG_OUTPUT_SIZE] = {0u};

        MCUX_CSSL_ANALYSIS_START_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
        MCUX_CSSL_FP_FUNCTION_CALL(ret_DTRNG_GetTrng2, mcuxClEls_Rng_DrbgRequestRaw_Async(requestRemainingBuffer));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
        if(MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT == ret_DTRNG_GetTrng2)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_ERROR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_getEntropyInput_fullBlocks),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Rng_DrbgRequestRaw_Async));
        }
        else if (MCUXCLELS_STATUS_OK_WAIT != ret_DTRNG_GetTrng2)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_FAULT_ATTACK);
        }
        else
        {
            /* Intentionally left empty */
        }

        MCUX_CSSL_FP_FUNCTION_CALL(ret_DRBG_Wait2, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));
        if((MCUXCLELS_STATUS_HW_OPERATIONAL == ret_DRBG_Wait2) || (MCUXCLELS_STATUS_HW_ALGORITHM == ret_DRBG_Wait2) || (MCUXCLELS_STATUS_HW_BUS == ret_DRBG_Wait2))
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_ERROR,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_getEntropyInput_fullBlocks),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Rng_DrbgRequestRaw_Async),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
        }
        else if (MCUXCLELS_STATUS_OK != ret_DRBG_Wait2)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_FAULT_ATTACK);
        }
        else
        {
            /* Intentionally left empty */
        }

        /* Copy the remaining bytes from the buffer to output. */
        MCUX_CSSL_FP_FUNCTION_CALL(copy_result, mcuxCsslMemory_Copy(
           mcuxCsslParamIntegrity_Protect(4u, requestRemainingBuffer, &pEntropyInput[fullELSblocksBytes/sizeof(uint32_t)], remainingNonFullELSblockBytes, remainingNonFullELSblockBytes),
               requestRemainingBuffer,
               &pEntropyInput[fullELSblocksBytes/sizeof(uint32_t)],
               remainingNonFullELSblockBytes,
               remainingNonFullELSblockBytes)
        );
        if(MCUXCSSLMEMORY_STATUS_OK != copy_result)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_FAULT_ATTACK);
        }
    }

    MCUX_CSSL_DI_RECORD(trngOutputSize, entropyInputLength);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_getEntropyInput_fullBlocks),
            MCUX_CSSL_FP_CONDITIONAL((remainingNonFullELSblockBytes > 0u),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Rng_DrbgRequestRaw_Async),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Copy)));
}
