/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023, 2025 NXP                                            */
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
#include <internal/mcuxCsslMemory_Internal_Copy_arm_asm.h>
#include <internal/mcuxCsslMemory_Internal_Compare_arm_asm.h>
#include <mcuxCsslDataIntegrity.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Copy)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Copy
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void const * pSrc,
    void * pDst,
    uint32_t dstLength,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Copy,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate)
    );

    MCUX_CSSL_FP_FUNCTION_CALL(crcResult, MCUX_CSSL_PI_VALIDATE(chk, pSrc, pDst, dstLength, length));

    if(crcResult != MCUXCSSLPARAMINTEGRITY_CHECK_VALID) {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Copy, MCUXCSSLMEMORY_STATUS_FAULT);
    }

    if((NULL == pSrc) || (NULL == pDst) || (length > dstLength)) {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Copy, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    /* Record mcuxCsslMemory_Internal_Copy_arm_asm call */
    MCUX_CSSL_DI_RECORD(copyParams, (uint32_t)pSrc);
    MCUX_CSSL_DI_RECORD(copyParams, (uint32_t)pDst);
    MCUX_CSSL_DI_RECORD(copyParams, length);

    uint32_t retval = (uint32_t) MCUXCSSLMEMORY_STATUS_FAULT;

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_Copy_arm_asm(pDst, pSrc, length));

    /*
     * Compare copied data to ensure copy operation performed properly
     */
    MCUX_CSSL_DI_RECORD(compareParams, pDst);
    MCUX_CSSL_DI_RECORD(compareParams, pSrc);
    MCUX_CSSL_DI_RECORD(compareParams, length);
    MCUX_CSSL_FP_FUNCTION_CALL(clRetval, mcuxCsslMemory_FastCompare_arm_asm(pDst, pSrc, length));
    MCUX_CSSL_DI_EXPUNGE(compareParamsStatus, clRetval);
    if(MCUXCSSLMEMORY_STATUS_EQUAL != clRetval)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Copy, MCUXCSSLMEMORY_STATUS_FAULT);
    }
    else
    {
        retval = MCUXCSSLMEMORY_STATUS_OK;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxCsslMemory_Copy, retval, MCUXCSSLMEMORY_STATUS_FAULT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_Copy_arm_asm),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_FastCompare_arm_asm)
    );
}
