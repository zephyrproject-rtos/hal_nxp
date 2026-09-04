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
 * @file  mcuxCsslMemory_SecureSet.c
 * @brief mcuxCsslMemory: implementation of secure memory set function
 */


#include <stddef.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslMemory_Constants.h>
#include <mcuxCsslMemory_Types.h>
#include <internal/mcuxCsslMemory_Internal_SecureSet.h>
#include <mcuxCsslMemory_SecureSet.h>
#include <internal/mcuxClPrng_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_SecureSet)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_SecureSet
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void * pDst,
    uint8_t val,
    uint32_t length,
    uint32_t bufLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_SecureSet,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate)
    );

    uint32_t setLen = bufLength < length ? bufLength : length;

    /* Backup DI value */
    MCUX_CSSL_DI_INIT(diRefValue);
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_SecureSet_params, pDst);
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_SecureSet_params, setLen);

    MCUX_CSSL_FP_FUNCTION_CALL(ret_paramIntegrity,
        MCUX_CSSL_PI_VALIDATE(chk, pDst, val, length, bufLength));

    if (MCUXCSSLPARAMINTEGRITY_CHECK_VALID != ret_paramIntegrity)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_SecureSet, MCUXCSSLMEMORY_STATUS_FAULT);
    }

    if (NULL == pDst)
    {
        MCUX_CSSL_DI_EXPUNGE(mcuxCsslMemory_SecureSet_params, pDst);
        MCUX_CSSL_DI_EXPUNGE(mcuxCsslMemory_SecureSet_params, setLen);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_SecureSet, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    uint8_t *p8Dst = (uint8_t *) pDst; // needs to be aligned
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_SecSet(p8Dst, val, setLen));

    MCUX_CSSL_DI_CHECK_EXIT(mcuxCsslMemory_SecureSet, diRefValue, MCUXCSSLMEMORY_STATUS_FAULT);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxCsslMemory_SecureSet, MCUXCSSLMEMORY_STATUS_OK, MCUXCSSLMEMORY_STATUS_FAULT,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecSet));
}
