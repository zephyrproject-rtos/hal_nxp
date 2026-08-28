/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslMemory.h>
#include <internal/mcuxCsslMemory_Internal_Set.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Clear)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Clear
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void * pDst,
    uint32_t dstLength,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Clear);

    /* Backup DI value */
    MCUX_CSSL_DI_INIT(diRefValue);
    MCUX_CSSL_DI_RECORD(memorySetParam, pDst);
    MCUX_CSSL_DI_RECORD(memorySetParam, length);

    MCUX_CSSL_FP_FUNCTION_CALL(retCode_paramIntegrityValidate, MCUX_CSSL_PI_VALIDATE(chk, pDst, dstLength, length));
    if ((retCode_paramIntegrityValidate != MCUXCSSLPARAMINTEGRITY_CHECK_VALID))
    {
        MCUX_CSSL_DI_EXPUNGE(memorySetParam, pDst);
        MCUX_CSSL_DI_EXPUNGE(memorySetParam, length);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Clear, MCUXCSSLMEMORY_STATUS_FAULT,
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate));
    }

    if(length > dstLength || NULL == pDst)
    {
        MCUX_CSSL_DI_EXPUNGE(memorySetParam, pDst);
        MCUX_CSSL_DI_EXPUNGE(memorySetParam, length);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Clear, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER,
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate));
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    uint8_t *p8Dst = (uint8_t *) pDst;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_Set(p8Dst, 0U, length));

    MCUX_CSSL_DI_CHECK_EXIT(mcuxCsslMemory_Clear, diRefValue, MCUXCSSLMEMORY_STATUS_FAULT);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxCsslMemory_Clear, MCUXCSSLMEMORY_STATUS_OK, MCUXCSSLMEMORY_STATUS_FAULT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_Set));
}
