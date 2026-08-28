/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023, 2026 NXP                                            */
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
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxCsslMemory_Internal_Compare_arm_asm.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Compare)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Compare
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void const * pLhs,
    void const * pRhs,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Compare,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate)
    );

    /* Record mcuxCsslMemory_Compare_arm_asm call */
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_Compare_Params, pLhs);
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_Compare_Params, pRhs);
    MCUX_CSSL_DI_RECORD(mcuxCsslMemory_Compare_Params, length);

    MCUX_CSSL_FP_FUNCTION_CALL(ret_paramIntegrity,
        MCUX_CSSL_PI_VALIDATE(chk, pLhs, pRhs, length));

    if( (MCUXCSSLPARAMINTEGRITY_CHECK_VALID != ret_paramIntegrity)) 
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Compare, MCUXCSSLMEMORY_STATUS_FAULT);
    }
    
    if((pLhs == pRhs) || (NULL == pLhs) || (NULL == pRhs))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Compare, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    if((0U == length)) 
    {
        MCUX_CSSL_DI_EXPUNGE(mcuxCsslMemory_Compare_Params, pLhs);  // Balance the SC
        MCUX_CSSL_DI_EXPUNGE(mcuxCsslMemory_Compare_Params, pRhs);  // Balance the SC
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Compare, MCUXCSSLMEMORY_STATUS_ZERO_LENGTH);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(retval, mcuxCsslMemory_Compare_arm_asm(pLhs, pRhs, length));
    MCUX_CSSL_DI_EXPUNGE(mcuxCsslMemory_Compare_Status, retval);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(
      mcuxCsslMemory_Compare,
      retval,
      MCUXCSSLMEMORY_STATUS_FAULT,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare_arm_asm)
    );
}

