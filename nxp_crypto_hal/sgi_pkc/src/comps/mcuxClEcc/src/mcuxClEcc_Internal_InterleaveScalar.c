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
 * @file  mcuxClEcc_Internal_InterleaveOneScalar.c
 * @brief mcuxClEcc: implementation of ECC function mcuxClEcc_InterleaveScalar
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>


/**
 * This function prepares one scalar to be used in scalar multiplication.
 * The scalar will be bit-wised interleaved, e.g.,
 * (L0, L1, L2, ..., H0, H1, H2, ...) --> (L0, H0, L1, H1, L2, H2, ...).
 *
 * Inputs:
 *   iScalar index of PKC operand which contains the scalar;
 *   scalarBitLength: scalar length in bits.
 *   numberOfInterleavings: scalar will be numberOfInterleavings times interleaved
 *
 * Inputs in pOperands[] and PKC workarea:
 *   buffer iScalar which contains the scalar.
 *
 * Prerequisites: N/A.
 *
 * Result in PKC workarea:
 *   buffer iScalar which contain the interleaved scalar (always in-place).
 *
 * Other modifications:
 *   buffers T0 and T1 are modified (as temp);
 *   offsets pOperands[ECC_V0/ECC_V1/ECC_V3] are modified;
 *   ps2 LEN and MCLEN are modified.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_InterleaveScalar)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_InterleaveScalar(uint16_t iScalar, uint32_t scalarBitLength, uint32_t numberOfInterleavings)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_InterleaveScalar);

    uint32_t ps1LenRegBackup = MCUXCLPKC_PS1_GETLENGTH_REG();
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 to Rule 11.3 - UPTR table is 32-bit aligned in ECC component.");
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("scalarBitLength is in the range of [1, 640], this is false positive. ")
    uint32_t bitLenHalfScalar = scalarBitLength - (scalarBitLength >> 1);  /* ceil(bitLen / 2) */
    uint32_t byteLenHalfScalar_PKCWord = ((bitLenHalfScalar + (MCUXCLPKC_WORDSIZE * 8u) - 1u) / (MCUXCLPKC_WORDSIZE * 8u)) * MCUXCLPKC_WORDSIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    uint32_t offsets_V1_V0 = /* ECC_V0 */ (uint32_t) pOperands[iScalar]
                             /* ECC_V1 */ + (((uint32_t) pOperands[ECC_T0] + byteLenHalfScalar_PKCWord) << 16);

    MCUXCLPKC_WAITFORREADY();
    /* MISRA Ex. 9 to Rule 11.3 - pOperands32 is pointer to 16-bit offset table */
    MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, ECC_V0, offsets_V1_V0);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("modular arithmetic.")
    pOperands[ECC_V3] = (uint16_t) ((0u - bitLenHalfScalar) & 0xFFFFu);  /* PKC will ignore higher bits of shifting amount. */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUXCLPKC_ENABLEGF2();
    MCUXCLPKC_PS1_SETLENGTH(0u, 2u * byteLenHalfScalar_PKCWord);
    MCUXCLPKC_PS2_SETLENGTH(byteLenHalfScalar_PKCWord, byteLenHalfScalar_PKCWord);

    /* Interleave iScalar. */
    for(uint32_t i = numberOfInterleavings; i > 0u ; i--)
    {
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Interleave, mcuxClEcc_FUP_Interleave_LEN);
    }

    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_DISABLEGF2();
    MCUXCLPKC_PS1_SETLENGTH_REG(ps1LenRegBackup);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_InterleaveScalar,
        numberOfInterleavings * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
    );
}
