/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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
 * @file  mcuxClEcc_ECDSA_Internal_PrepareMessageDigest.c
 * @brief Function to import and pad or truncate the ECDSA message digest
 */


#include <mcuxCsslAnalysis.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMath_Internal_Utils.h>

#include <internal/mcuxClEcc_ECDSA_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>




/**
 * This function imports a message digest to PKC and prepares it for usage within ECDSA
 * by truncating it or padding it with zeros as specified in FIPS 186-5.
 *
 * Input:
 *  - pIn          Pointer to message digest
 *  - inSize       Byte length of message digest
 *  - byteLenN     Byte length of base point order n
 *
 * Prerequisites:
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_NFULL contains n'||n
 *
 * Result:
 *  - If no errors are encountered, the prepared message digest is stored in ECC_S2.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 *
 * @post
 *  - Data Integrity: Expunge(pIn + inSize).
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_PrepareMessageDigest)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_ECDSA_PrepareMessageDigest(
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    uint32_t byteLenN
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_PrepareMessageDigest);

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(
        byteLenN,
        MCUXCLECC_WEIERECC_MIN_SIZE_BASEPOINTORDER,
        MCUXCLECC_WEIERECC_MAX_SIZE_BASEPOINTORDER);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();

    /* Import message hash (up to byteLenN bytes). */
    uint32_t byteLenHashImport = MCUXCLCORE_MIN(inSize, byteLenN);
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_S2, pIn, byteLenHashImport, operandSize);

    MCUX_CSSL_DI_EXPUNGE(pInIntegrity, pIn);
    /* Truncate message hash if its bit length is longer than that of n. */
    if (inSize >= byteLenN)
    {
        /* Count leading zeros in MSByte of n. */
        const volatile uint8_t * ptrN = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
        uint8_t nMSByte = ptrN[byteLenN - 1u];
        uint32_t nMSByte_LeadZeros = (uint32_t) mcuxClMath_CountLeadingZerosWord((uint32_t) nMSByte) - (8u * ((sizeof(uint32_t)) - 1u));

        /* Only keep the first bitLenN bits of hash, ECC_T2 used as temp buffer to avoid in-place operation. */
        MCUXCLPKC_FP_CALC_OP1_SHR(ECC_T2, ECC_S2, (uint8_t) (nMSByte_LeadZeros & 0x07u));
        MCUXCLPKC_FP_CALC_OP1_ADD_CONST(ECC_S2, ECC_T2, 0u);
    }
    MCUX_CSSL_DI_EXPUNGE(pInIntegrity, inSize);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_ECDSA_PrepareMessageDigest,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUX_CSSL_FP_CONDITIONAL((inSize >= byteLenN),
            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
            MCUXCLPKC_FP_CALLED_CALC_OP1_ADD_CONST));
}
