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
 * @file  mcuxClEcc_EdDSA_Internal_EncodePoint.c
 * @brief Function to encode a point
 */


#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClEcc_EdDSA_Internal.h>


/**
 * @brief Perform EdDSA encoding of a twisted Edwards curve point
 *
 * @param[in] encodedLen Length of encoded point
 *
 * @pre
 *  - ECC_COORD00 and ECC_COORD01 must contain the affine coordinates of the point to encode
 *  - @p encodedLen must be the length of the buffer at ECC_COORD02
 *  - PS2 (OP)LEN must be set to encodedLenPkc
 *
 * @post
 *  - buffer at ECC_COORD02 contains the encoded data
 *
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_EncodePoint)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_EncodePoint(
    const uint32_t encodedLen
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_EncodePoint);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUXCLPKC_FP_CALC_OP2_CONST(ECC_COORD02, 0u);                   /* Clear encodedLenPkc bytes of result buffer */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_COORD02, ECC_COORD01, 0u);   /* Copy operandSize < encodedLenPkc bytes of the y-coordinate from ECC_COORD01 to ECC_COORD02 */
    uint32_t *pX = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_COORD00]);
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(encodedLen, 1u, 57u)
    uint8_t *pEncLsbXByte = &MCUXCLPKC_OFFSET2PTR(pOperands[ECC_COORD02])[encodedLen - 1u];
    MCUXCLPKC_WAITFORFINISH();
    uint32_t lsbX = (*pX) & (uint32_t)0x01u;    /* Loading a word is usually cheaper than loading a byte */
    *pEncLsbXByte |= ((uint8_t)lsbX << 7u);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_EncodePoint,
        MCUXCLPKC_FP_CALLED_CALC_OP2_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST);
}
