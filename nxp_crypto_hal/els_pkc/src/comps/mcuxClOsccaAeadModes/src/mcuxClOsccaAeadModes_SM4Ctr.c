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

/** @file  mcuxClOsccaAeadModes_SM4Ctr.c
 *  @brief implementation of the AES CTR functions of the mcuxClOsccaAeadModes component */

#include <mcuxClAead.h>
#include <mcuxClMemory.h>
#include <mcuxClOscca_Memory.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <internal/mcuxClOsccaAeadModes_Internal_Functions.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaAeadModes_SM4_Crypt_IncCounter)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaAeadModes_SM4_Crypt_IncCounter(uint8_t *pCounter)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaAeadModes_SM4_Crypt_IncCounter);
    uint8_t *pCounterByte = pCounter;
    for(uint32_t i = MCUXCLOSCCASM4_BLOCK_SIZE; i > 0u; --i)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The integer wrap is intentional")
        pCounterByte[i-1u]++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        if(0u != pCounterByte[i-1u])
        {
          break;
        }
    }
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClOsccaAeadModes_SM4_Crypt_IncCounter);
}

/*
 * This function is only used by OSCCA AEAD which always calls it with block aligned input length.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr(
    uint32_t* roundKeys, mcuxCl_InputBuffer_t pIn, uint32_t inputLen, uint8_t* pIV, mcuxCl_Buffer_t pOut)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr);
    if(NULL == pOut)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr, MCUXCLAEAD_STATUS_ERROR);
    }
    // Initialize buffer allocations
    const uint32_t ctr = 0U;
    const uint32_t in  = 1U;
    const uint32_t out = 2U;
    uint8_t blocks[3u][MCUXCLOSCCASM4_BLOCK_SIZE];
    MCUXCLMEMORY_FP_MEMORY_CLEAR(blocks[0u], 3u * MCUXCLOSCCASM4_BLOCK_SIZE);
    MCUXCLMEMORY_FP_MEMORY_COPY(blocks[ctr], pIV, MCUXCLOSCCASM4_BLOCK_SIZE);

    // Main processing loop
    uint32_t position = 0U;
    uint32_t loopTimes = 0u;
    while(inputLen >= MCUXCLOSCCASM4_BLOCK_SIZE)
    {
        // Process input
        MCUX_CSSL_FP_FUNCTION_CALL(engineRet, mcuxClOsccaSm4_Engine(roundKeys, blocks[ctr], blocks[out], MCUXCLOSCCASM4_ENCRYPT));
        if(engineRet != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr, MCUXCLAEAD_STATUS_ERROR);
        }
        // Get input data
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferRead, mcuxClBuffer_read(pIn, position, blocks[in], MCUXCLOSCCASM4_BLOCK_SIZE));
        (void)statusBufferRead; // No need to check it because the function only returns OK.

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(blocks[out], blocks[out], blocks[in], MCUXCLOSCCASM4_BLOCK_SIZE));
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferWrite, mcuxClBuffer_write(pOut, position, blocks[out], MCUXCLOSCCASM4_BLOCK_SIZE));
        (void)statusBufferWrite; // No need to check it because the function only returns OK.

        // update counters
        inputLen -= MCUXCLOSCCASM4_BLOCK_SIZE;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP(" position can't be larger than max(uint32_t) ")
        position += MCUXCLOSCCASM4_BLOCK_SIZE;
        loopTimes++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOsccaAeadModes_SM4_Crypt_IncCounter(blocks[ctr]));
    }

    MCUXCLMEMORY_FP_MEMORY_COPY(pIV, blocks[ctr], MCUXCLOSCCASM4_BLOCK_SIZE);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr, MCUXCLAEAD_STATUS_OK,
                    loopTimes * (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine)
                                + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
                                + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor)
                                + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write)
                                + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaAeadModes_SM4_Crypt_IncCounter)),
                    2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
}
