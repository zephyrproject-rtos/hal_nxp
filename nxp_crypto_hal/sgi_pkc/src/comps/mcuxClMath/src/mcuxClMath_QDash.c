/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024, 2026 NXP                                            */
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
 * @file  mcuxClMath_QDash.c
 * @brief mcuxClMath: implementation of the functions mcuxClMath_QDash and mcuxClMathQSquared
 */


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClMath_QDash_FUP.h>
#include <internal/mcuxClMath_Internal_QDash.h>
#include <internal/mcuxClMath_Internal_Utils.h>
#include <internal/mcuxClMath_Internal_Functions.h>

/**
 * [DESIGN]
 * This function calculates QDash = Q * Q' mod n, where Q = 256^(PS1 OPLEN) mod n,
 * and Q' = 256^length mod n, in the following steps:
 * (1) calculate (Q mod n), which is the Montgomery representation of 1 modulo n.
 *     it is equivalent to NEG(n) = Q - n, the two's complement representation;
 * (2) calculate the Montgomery representation of 2 by using modular addition:
 *     MA(NEG(n), NEG(n), ns) \equiv (NEG(n) + NEG(n) mod n), where ns = ShiftModulus(n);
 * (3) calculate QDash, which is the Montgomery representation of Q', by using
 *     binary left-to-right exponentiation. Since the base number is 2, the modular
 *     multiplication with 2 in exponentiation is implemented as modular addition.
 *
 * ps, if there are many leading zeros in n, NEG(n) will be much bigger than n.
 *     Calculating MA in step (2) and (3) with shifted modulus ns can avoid
 *     too many iterations of subtraction loop.
 */

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("It is indeed defined.")
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEFINED_MORE_THAN_ONCE("It defined only once.")
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_QDash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_QDash(mcuxClSession_Handle_t pSession, uint32_t iQDash_iNShifted_iN_iT, uint16_t length)
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_QDash);

    uint32_t mathLocalUptrtWordOffset = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(QDASH_UPTRT_OFFSET * sizeof(uint16_t));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting 32-bit pointer to 16-bit pointer is 16-bit aligned")
    uint16_t * const pOperands = (uint16_t*)(pSession->pMathUptrt + mathLocalUptrtWordOffset);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    const uint16_t *pBackupPtrUptrt;
    /* mcuxClMath_InitLocalUptrt always returns _OK. */
    /* localPtrUptrt parameter of mcuxClMath_InitLocalUptrt starts at pOperands + QDASH_T. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMath_InitLocalUptrt(iQDash_iNShifted_iN_iT, 0U, pOperands, 4u, &pBackupPtrUptrt));
    /* WAITFORREADY in mcuxClMath_InitLocalUptrt(...). */
    pOperands[QDASH_CONST0] = 0u;

    /* Prepare 2Q mod n, which is the Montgomery representation of 2. */
    MCUXCLPKC_FP_CALCFUP(mcuxClMath_QDash_Fup_Init, mcuxClMath_QDash_Fup_Init_LEN);

    /* Prepare exponent for calculating (2^8)^(length) = 2^(8 * length). */
    uint32_t exponent = (uint32_t) length << 3;

    /* Scan exponent from MSbit (bit 15 + 3), and skip leading zeros plus one more bit (leading 1). */
    uint32_t bitMask = (uint32_t) 1u << ((8u * (sizeof(uint16_t))) - 1u + 3u);
    uint32_t bit;
    do
    {
        bit = exponent & bitMask;
        bitMask >>= 1;
    } while(0u == bit);  /* Assume exponent != 0, otherwise, this is an endless loop. */

    MCUX_CSSL_FP_LOOP_DECL(QDash_SquareMultiply);
    do
    {
        MCUX_CSSL_FP_LOOP_ITERATION(QDash_SquareMultiply,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );

        if (0u == (exponent & bitMask))
        {
            /* Squaring only. */
            MCUXCLPKC_FP_CALCFUP(mcuxClMath_QDash_Fup_Loop0, mcuxClMath_QDash_Fup_Loop0_LEN);
        }
        else
        {
            /* Squaring and multiplication. */
            MCUXCLPKC_FP_CALCFUP(mcuxClMath_QDash_Fup_Loop1, mcuxClMath_QDash_Fup_Loop1_LEN);
        }

        bitMask >>= 1;
    } while(0u != bitMask);  /* Assume exponent != 0, there are at least 3 squarings. */

    /* Restore pUptrt. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_SETUPTRT(pBackupPtrUptrt);

    MCUX_CSSL_FP_COUNTER_STMT(
        const uint32_t leadingZeroLength = mcuxClMath_CountLeadingZerosWord((uint32_t) length);     \
        /* ASSERT: number of leading zeros of nonzero length (u16 casted to u32) is in range [16,31]. */  \
        MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(leadingZeroExponent, 16u, 31u)                          \
        const uint32_t leadingZeroExponent = leadingZeroLength - 3u;  /* exponent = length * 8. */        \
        /* "-1" to skip the first nonzero bit. */                                                         \
        const uint32_t lterationsSquareMultiply = ((sizeof(uint32_t)) * 8u) - leadingZeroExponent - 1u; )

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_QDash,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_LOOP_ITERATIONS(QDash_SquareMultiply, lterationsSquareMultiply) );
}


/**
 * [DESIGN]
 * This function calculates QSquared = Q^2 mod n, where Q = 256^(PS1 OPLEN) mod n,
 * by calling the above mcuxClMath_QDash.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_QSquared)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_QSquared(mcuxClSession_Handle_t pSession, uint32_t iQSqr_iNShifted_iN_iT)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_QSquared,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QDash));

    uint16_t len = MCUXCLPKC_PS1_GETOPLEN();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMath_QDash(pSession, iQSqr_iNShifted_iN_iT, len));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_QSquared);
}
