/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
 * @file  mcuxCsslMemory_Internal_Set.c
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslMemory.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>

#include <internal/mcuxCsslMemory_Internal_Set.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Int_Set)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxCsslMemory_Int_Set
(
    uint8_t * pDst,
    uint8_t val,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Int_Set);

    uint32_t wordVal = ((uint32_t)val << 24) | ((uint32_t)val << 16) | ((uint32_t)val << 8) | (uint32_t)val;

    /* DI protect val and wordVal */
    MCUX_CSSL_DI_RECORD(memSetVal, 2U * wordVal);

    uint32_t currentLen = 0u;
    const uint32_t cpuWordSize = sizeof(uint32_t);
    uint8_t *p8Dst = pDst;

    const uint8_t *p8End = &(((const uint8_t *) pDst)[length]);

    MCUX_CSSL_FP_LOOP_DECL(FirstByteLoop);
    MCUX_CSSL_FP_LOOP_DECL(SecondByteLoop);
    MCUX_CSSL_FP_LOOP_DECL(WordLoop);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Typecast pointer to integer to check address for alignment")
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_NOT_ELEMENTS_OF_THE_SAME_OBJECT("p8Dst and p8End must point into the same object")
    while ((0u != ((uint32_t) p8Dst & (cpuWordSize - 1u))) && (currentLen < length) && (p8Dst < p8End))
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NOT_ELEMENTS_OF_THE_SAME_OBJECT()
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()
    {
        MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "p8Dst will be in the valid range pDst[0 ~ length].")
        *p8Dst = val;
        MCUX_CSSL_DI_DONOTOPTIMIZE(p8Dst);
        MCUX_CSSL_FP_LOOP_ITERATION(FirstByteLoop);
        *p8Dst = val;
        p8Dst++;
        currentLen++;
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("p8Dst is CPU word-aligned after the previous loop")
    uint32_t *p32Dst = (uint32_t *) p8Dst;  /* p8Dst is CPU word-aligned after the previous loop. */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    if(cpuWordSize <= length)
    {
        while ((currentLen <= (length - cpuWordSize)) && ((uint32_t)p32Dst < (uint32_t)p8End))
        {          
            MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "p32Dst will be in the valid range pDst[0 ~ length].")
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("p8Dst is CPU word-aligned after the previous loop")
            *p32Dst = wordVal;
            MCUX_CSSL_DI_DONOTOPTIMIZE(p32Dst);
            MCUX_CSSL_FP_LOOP_ITERATION(WordLoop);
            *p32Dst = wordVal;
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
            p32Dst++;
            currentLen += cpuWordSize;
            MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
        }
    }

    p8Dst = (uint8_t *) p32Dst;
    while ((currentLen < length) && ((uint32_t)p8Dst < (uint32_t)p8End))
    {
        MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "p8Dst will be in the valid range pDst[0 ~ length].")
        *p8Dst = val;
        MCUX_CSSL_DI_DONOTOPTIMIZE(p8Dst);
        MCUX_CSSL_FP_LOOP_ITERATION(SecondByteLoop);
        *p8Dst = val;
        p8Dst++;
        currentLen++;
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    }

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t noOfBytesToAlignment = ((0u - ((uint32_t) pDst)) & (cpuWordSize - 1u)));
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t firstByteIteration = (length > noOfBytesToAlignment)
                             ? noOfBytesToAlignment
                             : length);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t wordIteration = (length > firstByteIteration)
                             ? ((length - firstByteIteration) / cpuWordSize)
                             : 0u);

    /* Expunge the protected input parameters: p8Dst is equal to pDst + length */
    MCUX_CSSL_DI_EXPUNGE(memorySetParam, p8Dst);

    /* Expunge 2 * wordVal */
    MCUX_CSSL_DI_EXPUNGE(memSetVal, wordVal);
    MCUX_CSSL_DI_EXPUNGE(memSetVal, ((uint32_t)val << 24) | ((uint32_t)val << 16) | ((uint32_t)val << 8) | (uint32_t)val);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxCsslMemory_Int_Set,
        MCUX_CSSL_FP_LOOP_ITERATIONS(FirstByteLoop, firstByteIteration),
        MCUX_CSSL_FP_LOOP_ITERATIONS(WordLoop, wordIteration),
        MCUX_CSSL_FP_LOOP_ITERATIONS(SecondByteLoop, length - (wordIteration * cpuWordSize) - firstByteIteration));
}
