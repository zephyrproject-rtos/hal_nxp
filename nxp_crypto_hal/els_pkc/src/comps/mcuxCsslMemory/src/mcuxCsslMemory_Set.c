/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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
 * @file  mcuxCsslMemory_Set.c
 * @brief mcuxCsslMemory: implementation of memory set function
 */


#include <stddef.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslMemory.h>
#include <mcuxCsslAnalysis.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Set)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Set
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void * pDst,
    uint8_t val,
    size_t length,
    size_t bufLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Set,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate));

    MCUX_CSSL_FP_FUNCTION_CALL(retCode_paramIntegrityValidate, mcuxCsslParamIntegrity_Validate(chk, 4u, pDst, val, length, bufLength));

    if (MCUXCSSLPARAMINTEGRITY_CHECK_VALID != retCode_paramIntegrityValidate)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Set, MCUXCSSLMEMORY_STATUS_FAULT);
    }

    if (NULL == pDst)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Set, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    size_t copyLen = bufLength < length ? bufLength : length;
    uint32_t remainLength = (uint32_t) copyLen;
    uint32_t wordVal = ((uint32_t)val << 24) | ((uint32_t)val << 16) | ((uint32_t)val << 8) | (uint32_t)val;
    const uint32_t cpuWordSize = sizeof(uint32_t);

    MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_VOID()
    volatile uint8_t *p8Dst = (volatile uint8_t *) pDst; // needs to be aligned
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_VOID()


    MCUX_CSSL_ANALYSIS_START_PATTERN_SC_CAST_POINTERS()
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "pDst will be in the valid range pDst[0 ~ copyLen].")
    MCUX_CSSL_SC_ADD((uint32_t) pDst + copyLen);
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_SC_CAST_POINTERS()

    MCUX_CSSL_FP_LOOP_DECL(FirstByteLoop);
    MCUX_CSSL_FP_LOOP_DECL(SecondByteLoop);
    MCUX_CSSL_FP_LOOP_DECL(WordLoop);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Typecast pointer to integer to check address for alignment")
    while ((0u != ((uint32_t) p8Dst & (cpuWordSize - 1u))) && (0u != remainLength))
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()
    {
        MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "p8Dst will be in the valid range pDst[0 ~ copyLen].")
        MCUX_CSSL_FP_LOOP_ITERATION(FirstByteLoop);
        *p8Dst = val;
        p8Dst++;
        remainLength--;
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    }


    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("p8Dst is CPU word-aligned after the previous loop")
    volatile uint32_t *p32Dst = (volatile uint32_t *) p8Dst;  /* p8Dst is CPU word-aligned after the previous loop. */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    while (cpuWordSize <= remainLength)
    {
        MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "p32Dst will be in the valid range pDst[0 ~ copyLen].")
        MCUX_CSSL_FP_LOOP_ITERATION(WordLoop);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("p8Dst is CPU word-aligned after the previous loop")
        *p32Dst = wordVal;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
        p32Dst++;
        remainLength -= cpuWordSize;
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    }

    p8Dst = (volatile uint8_t *) p32Dst;
    while (0u != remainLength)
    {
        MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "p8Dst will be in the valid range pDst[0 ~ copyLen].")
        MCUX_CSSL_FP_LOOP_ITERATION(SecondByteLoop);
        *p8Dst = val;
        p8Dst++;
        remainLength--;
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    }

    MCUX_CSSL_ANALYSIS_START_PATTERN_SC_CAST_POINTERS()
    MCUX_CSSL_SC_SUB((uint32_t) p8Dst);
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "modular arithmetic, mod 4")
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t noOfBytesToAlignment = ((0u - ((uint32_t) pDst)) % cpuWordSize));
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_SC_CAST_POINTERS()

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t firstByteIteration = (copyLen > noOfBytesToAlignment)
                             ? noOfBytesToAlignment
                             : copyLen);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t wordIteration = (copyLen > firstByteIteration)
                             ? ((copyLen - firstByteIteration) / cpuWordSize)
                             : 0u);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Set, MCUXCSSLMEMORY_STATUS_OK,
        MCUX_CSSL_FP_LOOP_ITERATIONS(FirstByteLoop, firstByteIteration),
        MCUX_CSSL_FP_LOOP_ITERATIONS(WordLoop, wordIteration),
        MCUX_CSSL_FP_LOOP_ITERATIONS(SecondByteLoop, copyLen - (wordIteration * cpuWordSize) - firstByteIteration));
}
