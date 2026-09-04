/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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
 * @file  mcuxCsslMemory_Internal_XOR.c
 */
#include <stddef.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxCsslMemory_Internal_XOR.h>

#define WORDSIZE  (sizeof(uint32_t))

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Int_XOR)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxCsslMemory_Int_XOR(
                                                        uint8_t *pTarget,
                                                        const uint8_t *pSource,
                                                        const uint8_t *pSource2,
                                                        uint32_t length
                                                      )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Int_XOR);
    uint32_t remainingLen = length;

    MCUX_CSSL_DI_RECORD(xorParams, 2u * length);
    MCUX_CSSL_FP_LOOP_DECL(mcuxCsslMemory_Int_XOR_loop);

    /* xor by word if aligned */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("casting pointer to integer to check alignment.")
    if ((remainingLen >= WORDSIZE) && (0u == ((uint32_t)pTarget & (WORDSIZE - 1u)))
                && (0u == ((uint32_t)pSource & (WORDSIZE - 1u)))
                && (0u == ((uint32_t)pSource2 & (WORDSIZE - 1u))))
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()
    {
        do
        {
            MCUX_CSSL_DI_DONOTOPTIMIZE(pSource);
            MCUX_CSSL_DI_DONOTOPTIMIZE(pSource2);
            MCUX_CSSL_DI_DONOTOPTIMIZE(pTarget);
            MCUX_CSSL_FP_LOOP_ITERATION(mcuxCsslMemory_Int_XOR_loop);
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pSource, pSource2 and pTarget are word aligned.")
            const uint32_t temp1 = *(const uint32_t *)pSource;
            const uint32_t temp2 = *(const uint32_t *)pSource2;
            *(uint32_t *)pTarget = temp1 ^ temp2;
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

            MCUX_CSSL_FP_LOOP_ITERATION(mcuxCsslMemory_Int_XOR_loop);
            pSource += WORDSIZE;
            pSource2 += WORDSIZE;
            pTarget += WORDSIZE;
            MCUX_CSSL_FP_LOOP_ITERATION(mcuxCsslMemory_Int_XOR_loop);
            remainingLen -= WORDSIZE;
            MCUX_CSSL_FP_LOOP_ITERATION(mcuxCsslMemory_Int_XOR_loop);
        } while (remainingLen >= WORDSIZE);
    }

    /* xor the remaining bytes */
    while (remainingLen > 0u)
    {
        MCUX_CSSL_DI_DONOTOPTIMIZE(pSource);
        MCUX_CSSL_DI_DONOTOPTIMIZE(pSource2);
        MCUX_CSSL_DI_DONOTOPTIMIZE(pTarget);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller should set length and bufLength properly to make sure not to overflow.")
        const uint8_t temp1 = *pSource++;
        const uint8_t temp2 = *pSource2++;
        *pTarget++ = temp1 ^ temp2;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        remainingLen--;
        MCUX_CSSL_FP_LOOP_ITERATION(mcuxCsslMemory_Int_XOR_loop);
    }

    MCUX_CSSL_DI_EXPUNGE(xorParams, pTarget);
    MCUX_CSSL_DI_EXPUNGE(xorParams, pSource);
    MCUX_CSSL_DI_EXPUNGE(xorParams, pSource2);
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxCsslMemory_Int_XOR,
                              MCUX_CSSL_FP_LOOP_ITERATIONS(mcuxCsslMemory_Int_XOR_loop, length));
}

