/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
#include <internal/mcuxCsslMemory_Internal_Compare_asm.h>

#define CLS_NORMAL      0x2E00u
#define CLS_MISMATCH    0x8900u
#define LSB_NOT_EQUAL   0xB8u

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslMemory_Compare)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Compare
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void const * pLhs,
    void const * pRhs,
    size_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslMemory_Compare,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslParamIntegrity_Validate)
    );

    MCUX_CSSL_FP_FUNCTION_CALL(result, mcuxCsslParamIntegrity_Validate(chk, 3u, pLhs, pRhs, length));

    if( (result != MCUXCSSLPARAMINTEGRITY_CHECK_VALID)) {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Compare, MCUXCSSLMEMORY_STATUS_FAULT);
    }

   if((NULL == pLhs) || (NULL == pRhs)) {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Compare, MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER);
    }

    uint32_t nwords = 0u;
    uint32_t retval = 0u;
    MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_VOID()
    uint8_t const * cur_lhs = (uint8_t const *)pLhs;
    uint8_t const * cur_rhs = (uint8_t const *)pRhs;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_VOID()
    uint32_t const notValid = ~(MCUXCSSLPARAMINTEGRITY_CHECK_VALID);
    uint32_t const errCode = (uint32_t)MCUXCSSLMEMORY_STATUS_NOT_EQUAL;

    /* Pre-calculate end pointers */
    uint8_t const * end_lhs = &cur_lhs[length];
    uint8_t const * end_rhs = &cur_rhs[length];

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("Exception 9: re-interpreting the memory for word access")
    MCUXCSSLMEMORY_COMPARE_ASM_COMPARISON(retval, cur_lhs, cur_rhs, nwords, length, notValid, result);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()

    MCUXCSSLMEMORY_COMPARE_ASM_CALC_RETVAL(retval, errCode);
    retval &= 0x000000FFu;  /* Isolate the byte value that we are interested in */
    retval |= MCUXCSSLMEMORY_COMPONENT_MASK | CLS_MISMATCH;  /* Defines the value to what is expected */
    retval ^= (CLS_MISMATCH ^ CLS_NORMAL) & ((retval ^ LSB_NOT_EQUAL) << 8);  /* If equal, then change the class to match the equal case */

    /* Check that the pointers reached the end */
    if((end_lhs != cur_lhs) || (end_rhs != cur_rhs)) {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Compare, MCUXCSSLMEMORY_STATUS_FAULT);
    }

    MCUX_CSSL_SC_ADD(nwords); // -> should be 0

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslMemory_Compare, retval);
}
