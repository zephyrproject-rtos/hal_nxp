/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

#include <mcuxCsslMemory.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClMemory_Copy.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Copy)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Copy
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void const * pSrc,
    void * pDst,
    size_t dstLength,
    size_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Copy);

    if((NULL == pSrc) || (NULL == pDst) || (length > dstLength))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Copy, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    mcuxCsslParamIntegrity_Checksum_t cmpChk = mcuxCsslParamIntegrity_Protect(3u, pSrc, pDst, length);

    MCUX_CSSL_FP_FUNCTION_CALL(integrityResult, mcuxCsslParamIntegrity_Validate(chk, 4u, pSrc, pDst, dstLength, length));

    if(MCUXCSSLPARAMINTEGRITY_CHECK_VALID != integrityResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Copy, MCUXCSSLMEMORY_STATUS_FAULT);
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy(pDst, pSrc, length, dstLength));

    MCUX_CSSL_FP_FUNCTION_CALL(compareResult, mcuxCsslMemory_Compare(cmpChk, pSrc, pDst, length));

    if((MCUXCSSLMEMORY_STATUS_EQUAL == compareResult))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Copy, MCUXCSSLMEMORY_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate));
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Copy, MCUXCSSLMEMORY_STATUS_FAULT);
    }
}
