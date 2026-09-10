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

/**
 * @file  mcuxCsslMemory_Clear.c
 * @brief mcuxCsslMemory: implementation of memory clear function
 */


#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslMemory.h>
#include <mcuxCsslMemory_Clear.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Clear)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Clear
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void * pDst,
    size_t dstLength,
    size_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Clear,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate) );

    MCUX_CSSL_FP_FUNCTION_CALL(retCode_paramIntegrityValidate, mcuxCsslParamIntegrity_Validate(chk, 3u, pDst, dstLength, length));
    if ((retCode_paramIntegrityValidate != MCUXCSSLPARAMINTEGRITY_CHECK_VALID))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Clear, MCUXCSSLMEMORY_STATUS_FAULT);
    }

    if (length > dstLength)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Clear, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(retCode_memSet, mcuxCsslMemory_Set(mcuxCsslParamIntegrity_Protect(4u, pDst, 0u, length, dstLength), pDst, 0u, length, dstLength) );

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Clear, retCode_memSet,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Set ));
}
