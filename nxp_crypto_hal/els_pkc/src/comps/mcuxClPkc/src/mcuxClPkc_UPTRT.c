/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2024 NXP                                       */
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

/**
 * @file  mcuxClPkc_UPTRT.c
 * @brief PKC UPTRT (Universal pointer FUP table) generation function
 */


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>

#include <mcuxClRandom.h>
#include <mcuxClPkc_Types.h>
#include <mcuxClPkc_Functions.h>
#include <internal/mcuxClPkc_Macros.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_GenerateUPTRT)
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("It is indeed defined.")
MCUX_CSSL_ANALYSIS_START_PATTERN_SYMBOL_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_GenerateUPTRT(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_SYMBOL_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()
    uint16_t *pUPTRT,
    const uint8_t *pBaseBuffer,
    uint16_t bufferLength,
    uint8_t noOfBuffer)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_GenerateUPTRT);

    uint32_t offset = MCUXCLPKC_PTR2OFFSET(pBaseBuffer);

    for (uint32_t idx = 0; idx < (uint32_t) noOfBuffer; idx++)
    {
        pUPTRT[idx] = (uint16_t) (offset & 0xFFFFu);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Offset can't wrap since both offset and bufferLength are indeed uint16.")
        offset += bufferLength;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_GenerateUPTRT);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_RandomizeUPTRT)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPkc_Status_t) mcuxClPkc_RandomizeUPTRT(
    mcuxClSession_Handle_t pSession,
    uint16_t *pUPTRT,
    uint8_t noOfBuffer)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_RandomizeUPTRT);

    MCUX_CSSL_FP_LOOP_DECL(Loop);
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_LOOP_ITERATIONS(Loop, ((uint32_t)noOfBuffer - 1U)));

    /* Allocate one word on stack for random numbers */
    uint32_t random32;
    MCUXCLBUFFER_INIT(pBuffRandom32, NULL, (uint8_t *) &random32, sizeof(uint32_t));

    /* Randomize entries in UPTRT by Knuth shuffle. */
    for (uint32_t idx = noOfBuffer; idx > 1u; idx--)
    {
        MCUX_CSSL_FP_LOOP_ITERATION(Loop,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate));

        /* Generate a random number in the range [0, idx-1], where idx <= noOfBuffer <= 255. */
        MCUX_CSSL_FP_FUNCTION_CALL(ret_Random_ncGenerate, mcuxClRandom_ncGenerate(pSession, pBuffRandom32, sizeof(uint32_t)));
        if (MCUXCLRANDOM_STATUS_OK != ret_Random_ncGenerate)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPkc_RandomizeUPTRT, MCUXCLPKC_STATUS_NOK);
        }
        uint32_t random8 = random32 >> 8;
        random8 *= idx;
        random8 >>= 24;

        /* Swap. */
        uint16_t temp0 = pUPTRT[idx - 1u];
        uint16_t temp1 = pUPTRT[random8];
        pUPTRT[random8] = temp0;
        pUPTRT[idx - 1u] = temp1;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPkc_RandomizeUPTRT, MCUXCLPKC_STATUS_OK);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_ReRandomizeUPTRT)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPkc_Status_t) mcuxClPkc_ReRandomizeUPTRT(
    mcuxClSession_Handle_t pSession,
    uint16_t *pUPTRT,
    uint16_t bufferLength,
    uint8_t noOfBuffer)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_ReRandomizeUPTRT);

    MCUX_CSSL_FP_LOOP_DECL(Loop);
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_LOOP_ITERATIONS(Loop, ((uint32_t)noOfBuffer - 1U)));

    /* Allocate one word on stack for random numbers */
    uint32_t random32;
    MCUXCLBUFFER_INIT(pBuffRandom32, NULL, (uint8_t *) &random32, sizeof(uint32_t));

    /* Randomize entries in UPTRT by Knuth shuffle. */
    for (uint32_t idx = noOfBuffer; idx > 1u; idx--)
    {
        MCUX_CSSL_FP_LOOP_ITERATION(Loop,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate));
        /* Generate a random number in the range [0, idx-1], where idx <= noOfBuffer <= 255. */
        MCUX_CSSL_FP_FUNCTION_CALL(ret_Random_ncGenerate, mcuxClRandom_ncGenerate(pSession, pBuffRandom32, sizeof(uint32_t)));
        if (MCUXCLRANDOM_STATUS_OK != ret_Random_ncGenerate)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPkc_ReRandomizeUPTRT, MCUXCLPKC_STATUS_NOK);
        }
        uint32_t random8 = random32 >> 8u;
        random8 *= idx;
        random8 >>= 24u;

        /* Swap. */
        uint16_t offset0 = pUPTRT[idx - 1u];
        uint16_t offset1 = pUPTRT[random8];
        pUPTRT[random8] = offset0;
        pUPTRT[idx - 1u] = offset1;

        /* Caller shall provide UPTR table with all offsets being exactly a multiple of MCUXCLPKC_WORDSIZE. */
        uint32_t *ptr0 = MCUXCLPKC_OFFSET2PTRWORD(offset0);
        uint32_t *ptr1 = MCUXCLPKC_OFFSET2PTRWORD(offset1);

        /* Swap contents of the two buffers, of which the size is a multiple of CPU word. */
        for (uint32_t i = 0u; i < ((uint32_t) bufferLength / 4u); i++)
        {
            uint32_t temp0 = ptr0[i];
            uint32_t temp1 = ptr1[i];
            ptr1[i] = temp0;
            ptr0[i] = temp1;
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPkc_ReRandomizeUPTRT, MCUXCLPKC_STATUS_OK);
}
