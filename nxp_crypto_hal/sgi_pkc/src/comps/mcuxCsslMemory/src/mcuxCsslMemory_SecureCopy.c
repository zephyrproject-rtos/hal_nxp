/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
 * @file  mcuxCsslMemory_SecureCopy.c
 */


#include <stdint.h>
#include <stddef.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslMemory_Constants.h>
#include <mcuxCsslMemory_Types.h>
#include <mcuxCsslMemory_SecureCopy.h>
#include <internal/mcuxCsslMemory_Internal_SecureCopy.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_SecureCopy)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_SecureCopy
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void const * pSrc,
    void * pDst,
    uint32_t dstLength,
    uint32_t length,
    uint32_t order
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_SecureCopy,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate)
    );

    /* Backup DI value */
    MCUX_CSSL_DI_INIT(diRefValue);
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_Int_SecCopy_params, pSrc);
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_Int_SecCopy_params, pDst);
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_Int_SecCopy_params, length);

    MCUX_CSSL_FP_FUNCTION_CALL(ret_paramIntegrity,
        MCUX_CSSL_PI_VALIDATE(chk, pSrc, pDst, dstLength, length, order));

    if (MCUXCSSLPARAMINTEGRITY_CHECK_VALID != ret_paramIntegrity)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_SecureCopy, MCUXCSSLMEMORY_STATUS_FAULT);
    }

    MCUX_CSSL_ANALYSIS_COVERITY_START_DEVIATE(MISRA_C_2012_Rule_11_6, "Typecast (void *) to uint for checking overlapping buffers.")
    const uint32_t pSrcTrail = (uint32_t) pSrc + length;
    const uint32_t pDstTrail = (uint32_t) pDst + length;

    if (   (NULL == pSrc) || (NULL == pDst) || (length > dstLength)
        || (((uint32_t) pSrc < pDstTrail) && ((uint32_t) pDst < pSrcTrail)) )  /* overlap */
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_DEVIATE(MISRA_C_2012_Rule_11_6)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_SecureCopy, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    mcuxCsslMemory_Status_t retval = MCUXCSSLMEMORY_STATUS_FAULT;

    if (MCUXCSSLMEMORY_KEEP_ORDER == order)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_SecCopy((uint8_t *) pDst, (const uint8_t *) pSrc, length));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()
        retval = MCUXCSSLMEMORY_STATUS_OK;
    }
    else if (MCUXCSSLMEMORY_REVERSE_ORDER == order)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_SecCopyRev((uint8_t *) pDst, (const uint8_t *) pSrc, length));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()
        retval = MCUXCSSLMEMORY_STATUS_OK;
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_SecureCopy, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    MCUX_CSSL_DI_CHECK_EXIT(mcuxCsslMemory_SecureCopy, diRefValue, MCUXCSSLMEMORY_STATUS_FAULT);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxCsslMemory_SecureCopy, retval, MCUXCSSLMEMORY_STATUS_FAULT,
        MCUX_CSSL_FP_CONDITIONAL(MCUXCSSLMEMORY_KEEP_ORDER == order, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecCopy)),
        MCUX_CSSL_FP_CONDITIONAL(MCUXCSSLMEMORY_REVERSE_ORDER == order, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecCopyRev))
        );
}
