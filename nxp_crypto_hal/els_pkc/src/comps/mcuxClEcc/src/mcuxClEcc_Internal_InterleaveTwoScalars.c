/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_InterleaveTwoScalars.c
 * @brief mcuxClEcc: implementation of ECC function mcuxClEcc_InterleaveTwoScalars
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClPkc.h>
#include <mcuxClMath.h>

#include <mcuxClEcc.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>


/**
 * This function prepares two scalars to be used in scalar multiplication.
 * Each scalar will be bit-wised interleaved, e.g.,
 * (L0, L1, L2, ..., H0, H1, H2, ...) --> (L0, H0, L1, H1, L2, H2, ...).
 *
 * Inputs:
 *   iScalar0_iScalar1: two indices of PKC operands, containing two scalars;
 *   scalarBitLength: scalar length in bits.
 *
 * Inputs in pOperands[] and PKC workarea:
 *   buffers iScalar0 and iScalar1 contain two scalars.
 *
 * Prerequisites: N/A.
 *
 * Result in PKC workarea:
 *   buffers iScalar0 and iScalar1 contain two interleaved scalars (always in-place).
 *
 * Other modifications:
 *   buffers T0 and T1 are modified (as temp);
 *   offsets pOperands[ECC_V0/ECC_V1/ECC_V3] are modified;
 *   ps2 LEN and MCLEN are modified.
 *
 * @attention The PKC calculation might be still on-going, call #mcuxClPkc_WaitForFinish before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_InterleaveTwoScalars)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_InterleaveTwoScalars(uint16_t iScalar0_iScalar1, uint32_t scalarBitLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_InterleaveTwoScalars);

    uint32_t ps1LenRegBackup = MCUXCLPKC_PS1_GETLENGTH_REG();
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("In ECC UPTRT is 32-bit aligned")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    uint8_t iScalar0 = (uint8_t) (iScalar0_iScalar1 >> 8);
    uint8_t iScalar1 = (uint8_t) (iScalar0_iScalar1 & 0xFFu);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("scalarBitLength is in the range of [1, MCUXCLPKC_RAM_SIZE * 8u], this is false positive. ")
    uint32_t bitLenHalfScalar = scalarBitLength - (scalarBitLength >> 1);  /* ceil(bitLen / 2) */
    uint32_t byteLenHalfScalar_PKCWord = ((bitLenHalfScalar + (MCUXCLPKC_WORDSIZE * 8u) - 1u) / (MCUXCLPKC_WORDSIZE * 8u)) * MCUXCLPKC_WORDSIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    uint32_t offsets_V1_V0 = /* ECC_V0 */ (uint32_t) pOperands[iScalar0]
                             /* ECC_V1 */ + (((uint32_t) pOperands[ECC_T0] + byteLenHalfScalar_PKCWord) << 16);

    MCUXCLPKC_WAITFORREADY();
    /* MISRA Ex. 9 to Rule 11.3 - pOperands32 is pointer to 16-bit offset table */
    MCUXCLECC_STORE_2OFFSETS(pOperands32, ECC_V0, ECC_V1, offsets_V1_V0);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("modular arithmetic.")
    pOperands[ECC_V3] = (uint16_t) ((0u - bitLenHalfScalar) & 0xFFFFu);  /* PKC will ignore higher bits of shifting amount. */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUXCLPKC_ENABLEGF2();
    MCUXCLPKC_PS1_SETLENGTH(0u, 2u * byteLenHalfScalar_PKCWord);
    MCUXCLPKC_PS2_SETLENGTH(byteLenHalfScalar_PKCWord, byteLenHalfScalar_PKCWord);

    /* Interleave scalar0. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Interleave, mcuxClEcc_FUP_Interleave_LEN);

    /* Interleave scalar1. */
    MCUXCLPKC_WAITFORREADY();
    pOperands[ECC_V0] = pOperands[iScalar1];
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Interleave, mcuxClEcc_FUP_Interleave_LEN);

    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_DISABLEGF2();
    MCUXCLPKC_PS1_SETLENGTH_REG(ps1LenRegBackup);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_InterleaveTwoScalars, MCUXCLECC_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );
}
