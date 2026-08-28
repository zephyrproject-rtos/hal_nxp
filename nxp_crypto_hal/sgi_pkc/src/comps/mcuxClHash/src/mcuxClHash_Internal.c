/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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

#include <mcuxClHash.h>
#include <internal/mcuxClHash_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHash_processedLength_add)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHash_processedLength_add(uint64_t *pLen128, uint64_t addLen)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHash_processedLength_add);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Integer wrap is intentional, carry is handled in the next line")
    pLen128[0] += addLen;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    pLen128[1] += (pLen128[0] < addLen) ? 1U : 0U;

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHash_processedLength_add);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHash_processedLength_cmp)
MCUX_CSSL_FP_PROTECTED_TYPE (int) mcuxClHash_processedLength_cmp(uint64_t *pLen128, uint64_t cmpLenLow64)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHash_processedLength_cmp);

    int result = (pLen128[1] != 0U) ? 1 :
                 (pLen128[0] > cmpLenLow64)   ? 1 :
                 (pLen128[0] == cmpLenLow64) ? 0 : -1;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHash_processedLength_cmp, result);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHash_processedLength_toBits)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHash_processedLength_toBits(uint64_t *pLen128)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHash_processedLength_toBits);

    pLen128[1] = (pLen128[1] << 3U) | (pLen128[0] >> 61U);
    pLen128[0] = pLen128[0] << 3U;

     MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHash_processedLength_toBits);
}
