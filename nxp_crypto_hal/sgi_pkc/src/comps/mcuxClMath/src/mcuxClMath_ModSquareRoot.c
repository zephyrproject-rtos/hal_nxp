/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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
 * @file  mcuxClMath_ModSquareRoot.c
 * @brief mcuxClMath: Implementation of the Tonelli-Shanks algorithm for computing
 *        square root modulo a prime number. Implementation of the Legendre symbol.
 */


#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>

#include <internal/mcuxClMath_Internal_ModSquareRoot.h>
#include <internal/mcuxClMath_Internal_Functions.h>


/**
 * [DESIGN]
 * This function serves as a higher level API for computing square roots modulo
 * a prime number p.
 * If p = 3 (mod 4) : Computing a square root modulo p is done via a single exponentiation.
 * If p = 1 (mod 4) : Computing a square root modulo p is done via the Tonelli-Shanks algorithm.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_ModSquareRoot)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ModSquareRoot(mcuxClSession_Handle_t pSession, uint32_t iR_iA_iP_iQ, uint32_t iT0_iT1_iT2_iT3, uint32_t byteLengthP)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_ModSquareRoot);

    const uint32_t iR  = (iR_iA_iP_iQ >> 24u) & 0xFFu;
    const uint32_t iA  = (iR_iA_iP_iQ >> 16u) & 0xFFu;
    const uint32_t iP  = (iR_iA_iP_iQ >>  8u) & 0xFFu;
    const uint32_t iQ  = iR_iA_iP_iQ & 0xFFu;

    const uint32_t iT0  = (iT0_iT1_iT2_iT3 >> 24u) & 0xFFu;
    const uint32_t iT1  = (iT0_iT1_iT2_iT3 >> 16u) & 0xFFu;
    const uint32_t iT2  = (iT0_iT1_iT2_iT3 >>  8u) & 0xFFu;
    const uint32_t iT3  = iT0_iT1_iT2_iT3 & 0xFFu;

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND(); /* avoid CPU accessing PKC workarea when PKC is busy */
    uint8_t *pP = MCUXCLPKC_OFFSET2PTR(pOperands[iP]);

    // TODO: CLNS-10594 investigate potential optimizations of the code
    // to make the square root calculation faster in case p = 5 (mod 8).
    /* Easy case: p = 3 (mod 4). In this case computing a square root beta of alpha modulo p */
    /* reduces to performing a single modular exponentiation (i.e. beta = alpha^((p+1)/4)) (mod p). */
    if (3u == (pP[0u] & 3u))
    {
        /* DI protect the byte length of the exponent. Will be balanced in the call to mcuxClMath_ModExp_SqrMultL2R(). */
        MCUX_CSSL_DI_RECORD(ModSquareRoot_ModExp, byteLengthP);

        uint32_t *pExponent = MCUXCLPKC_OFFSET2PTRWORD(pOperands[iT1]);

        /* Compute the exponent (p+1)/4. */
        MCUXCLPKC_FP_CALC_OP1_ADD_CONST(iT1, iP, 1u);
        MCUXCLPKC_FP_CALC_OP1_SHR(iT1, iT1, 2u);

        MCUXCLPKC_WAITFORFINISH();
        MCUXCLPKC_FP_SWITCHENDIANNESS(pExponent, byteLengthP);

        /* DI protect pExp param for call to MCUXCLMATH_FP_MODEXP_SQRMULTL2R */
        MCUX_CSSL_DI_RECORD(protectExpPointer, pExponent);

        /* Calculate beta = alpha^((p+1)/4) (mod p). */
        MCUXCLMATH_FP_MODEXP_SQRMULTL2R((uint8_t *)pExponent, byteLengthP, iR /* beta */, iA /* alpha */, iP /* mod */, iT0 /* tmp */);

        MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_ModSquareRoot,
            MCUXCLPKC_FP_CALLED_CALC_OP1_ADD_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SwitchEndianness),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModExp_SqrMultL2R));
    }
    /* If p = 1 (mod 4) then call Tonelli-Shanks algorithm for computing the square root. */
    else
    {
        MCUXCLMATH_FP_MODSQUAREROOT_TONELLISHANKS(pSession, iR /* beta */, iA /* alpha */, iP /* mod */, iQ /* Mont Q */,  iT0 /* tmp */, iT1 /* tmp */, iT2 /* tmp */, iT3 /* tmp */, byteLengthP);
        MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_ModSquareRoot, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModSquareRoot_TonelliShanks));
    }
}

/**
 * [DESIGN]
 * This function given alpha and p computes beta such that beta^2 = alpha (mod p).
 * For this it assumes that the given number alpha is a quadratic residue mod p and
 * p is a prime. It also assumes that both alpha and p are of the same size, PS1 OPLEN.
 * The function implements the Tonelli-Shanks algorithm for computing square roots
 * modulo a prime number.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_ModSquareRoot_TonelliShanks)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ModSquareRoot_TonelliShanks(mcuxClSession_Handle_t pSession, uint32_t iR_iA_iP_iQ, uint32_t iT0_iT1_iT2_iT3, uint32_t byteLengthP)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_ModSquareRoot_TonelliShanks);

    /* ASSERT: operand P (length = PS1 OPLEN >= byteLengthP) fits in PKC workarea. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(byteLengthP, 1u, MCUXCLPKC_RAM_SIZE)

    /**************************************************************************/
    /* Preparation                                                            */
    /**************************************************************************/

    uint32_t backupPs1LenReg = MCUXCLPKC_PS1_GETLENGTH_REG();

    /* Create local UPTR table. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Create 16-bit UPTR table at CPU word (32-bit) aligned address.")
    uint32_t * const pOperands32 = pSession->pMathUptrt;
    uint16_t * const pOperands = (uint16_t*) pOperands32;
    const uint16_t *pBackupPtrUptrt;
    /* mcuxClMath_InitLocalUptrt always returns _OK. */
    /* Mapping to internal indices:       iR -> Y, iA -> A, iP -> P, iQ -> Q, iT0 -> T, iT1 -> B, iT2 -> M, iT3 -> S */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMath_InitLocalUptrt(iR_iA_iP_iQ, iT0_iT1_iT2_iT3, pOperands, MODSQRT_SIZE, &pBackupPtrUptrt));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()

    /**************************************************************************/
    /* Find a generator m of the 2-Sylow subgroup of (Z/pZ)* (two steps).     */
    /* Step 1: Find m such that m is not a quadratic residue (mod p).         */
    /**************************************************************************/
    /* i.e. find m with Legendre sumbol (m/p) = -1. Under the */
    /* Generalised Riemann Hypothesis there should exist such */
    /* a value m with m <= (logp)^2. */
    /* Note: The smallest value m with (m/p) = -1 will be a prime. */

    /* Set s = p-1. */
    MCUXCLPKC_FP_CALC_OP1_SUB_CONST(MODSQRT_S, MODSQRT_P, 1u);

    // TODO: CLNS-10594 this search can become faster by distingushing
    // between p = 5 (mod 8) and p = 1 (mod 8).
    MCUXCLPKC_FP_CALC_OP1_SUB(MODSQRT_M, MODSQRT_P, MODSQRT_S);
    uint32_t m = 1u;
    uint32_t isQuadraticResidue = 1u;
    MCUX_CSSL_FP_LOOP_DECL(findQuadraticNonResidueLoop);
    do
    {
        /* Advance to the next value of m to be checked. */
        m++;
        MCUXCLPKC_FP_CALC_OP1_ADD_CONST(MODSQRT_M, MODSQRT_M, 1u);

        /* Compute the Legendre symbol (m/p). */
        MCUX_CSSL_FP_FUNCTION_CALL(result_legendre,
            MCUXCLMATH_LEGENDRESYMBOL(pSession,
                                     MODSQRT_M /* A */,
                                     MODSQRT_T /* T1 */,
                                     MODSQRT_Y /* T2 */,
                                     MODSQRT_B /* T3 */,
                                     MODSQRT_P /* P */) );
        isQuadraticResidue = (uint32_t) result_legendre;

        MCUX_CSSL_FP_LOOP_ITERATION(findQuadraticNonResidueLoop,
            MCUXCLPKC_FP_CALLED_CALC_OP1_ADD_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LegendreSymbol));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("For byteLengthP < 8192 the 64u*byteLengthP*byteLengthP won't wrap.")
    } while ((isQuadraticResidue != 0xFFFFFFFFu) && (m < 64u*byteLengthP*byteLengthP));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Convert m to Montgomery representation and store it in T. */
    MCUXCLPKC_FP_CALC_MC1_MM(MODSQRT_T, MODSQRT_M, MODSQRT_Q, MODSQRT_P);

    /**************************************************************************/
    /* Step 2a: Factor p-1 as p-1 = (2^r)*s with s odd.                       */
    /**************************************************************************/

    /* Compute maximum r such that 2^r divides p-1 and make s odd (i.e. p-1 = (2^r)*s). */
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL(noOfTrailingZeroBits, mcuxClMath_TrailingZeros(MODSQRT_S));
    uint32_t noOfTrailingZeroPkcWords = noOfTrailingZeroBits / (8u * MCUXCLPKC_WORDSIZE);

    /* If number of trailing zero bits exceeds a PKC word, shift pointer in UPTR table. */
    uint32_t noOfShiftBytes = noOfTrailingZeroPkcWords * MCUXCLPKC_WORDSIZE;
    /* ASSERT: given p > 1, number of trailing zeros of (p-1) does not exceed length of p. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(noOfShiftBytes, 0u, byteLengthP - 1u)

    uint32_t byteLenStmp = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLengthP - noOfShiftBytes);
    uint16_t backupS = pOperands[MODSQRT_S];
    /* ASSERT: operand S (length = byteLengthP) is within PKC workarea. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(backupS, MCUXCLPKC_RAM_OFFSET_MIN, MCUXCLPKC_RAM_OFFSET_MAX - byteLengthP)
    pOperands[MODSQRT_S] = (uint16_t) (backupS + noOfShiftBytes);

    /* Shift number of bits, which are less than one PKC word. */
    uint32_t noOfShiftBits = noOfTrailingZeroBits % (8u * MCUXCLPKC_WORDSIZE);
    MCUXCLPKC_PS1_SETLENGTH(byteLenStmp, byteLenStmp);  /* TODO: CLNS-11895, using PS2 to avoid backup/modify/restore PS1 lengths. */
    MCUXCLPKC_FP_CALC_OP1_SHR(MODSQRT_S, MODSQRT_S, noOfShiftBits);

    /* If number of leading zero bits after shift exceeds a PKC word, reduce length of S. */
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL(leadingZeroBits, mcuxClMath_LeadingZeros((uint8_t)MODSQRT_S));

    if((8u * MCUXCLPKC_WORDSIZE) <= leadingZeroBits)
    {
        /* ASSERT: when there is 1 or more PKC words of leading zeros in S, */
        /*         length of the nonzero S is >= 2 * MCUXCLPKC_WORDSIZE.     */
        MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(byteLenStmp, 2u * MCUXCLPKC_WORDSIZE, MCUXCLPKC_RAM_SIZE)
        byteLenStmp -= MCUXCLPKC_WORDSIZE;
    }

    /* Restore length of PS1. */
    MCUXCLPKC_PS1_SETLENGTH_REG(backupPs1LenReg);

    /**************************************************************************/
    /* Step 2b: Compute m^s (mod p) as the generator m.                       */
    /**************************************************************************/

    /* DI protect the byte length of the exponent. Will be balanced in the calls to mcuxClMath_ModExp_SqrMultL2R(). */
    MCUX_CSSL_DI_RECORD(ModSquareRoot_ModExp, 2u * byteLenStmp);

    uint32_t *pS = MCUXCLPKC_OFFSET2PTRWORD(pOperands[MODSQRT_S]);
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(byteLenStmp, 0u, UINT32_MAX - 1u)
    MCUXCLPKC_FP_SWITCHENDIANNESS(pS, byteLenStmp);
    /* DI protect pExp param for call to MCUXCLMATH_FP_MODEXP_SQRMULTL2R */
    MCUX_CSSL_DI_RECORD(protectExpPointer, pS);
    MCUXCLMATH_FP_MODEXP_SQRMULTL2R((uint8_t *)pS, byteLenStmp, MODSQRT_M, MODSQRT_T, MODSQRT_P, MODSQRT_B);

    /**********************************************************************************/
    /* Step 3:                                                                        */
    /* Reduce the square root problem from (Z/pZ) to the 2-Sylow subgroup of (Z/pZ)*. */
    /**********************************************************************************/

    /* Restore endianess of s. */
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("PKC buffer is CPU word aligned.")
    MCUXCLPKC_FP_SWITCHENDIANNESS(pS, byteLenStmp);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Compute exponent s' = (s-1)/2 (s is odd by step 2a). */
    MCUXCLPKC_PS2_SETLENGTH(byteLenStmp, byteLenStmp);
    MCUXCLPKC_FP_CALC_OP2_SHR(MODSQRT_S, MODSQRT_S, 1u);

    /* Compute b = a^(s') (mod p). */
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("PKC buffer is CPU word aligned.")
    MCUXCLPKC_FP_SWITCHENDIANNESS(pS, byteLenStmp);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    /* DI protect pExp param for call to MCUXCLMATH_FP_MODEXP_SQRMULTL2R */
    MCUX_CSSL_DI_RECORD(protectExpPointer, pS);
    MCUXCLMATH_FP_MODEXP_SQRMULTL2R((uint8_t *)pS, byteLenStmp, MODSQRT_B, MODSQRT_A, MODSQRT_P, MODSQRT_Y);

    /* Restore s buffer address. */
    pOperands[MODSQRT_S] = backupS;

    /* Compute y = b*a = a^((s+1)/2) (mod p). */
    MCUXCLPKC_FP_CALC_MC1_MM(MODSQRT_Y, MODSQRT_B, MODSQRT_A, MODSQRT_P);

    /* Compute t = b*y = a^((s+1)/2) * a^((s-1)/2) = a^s (mod p). */
    MCUXCLPKC_FP_CALC_MC1_MM(MODSQRT_T, MODSQRT_B, MODSQRT_Y, MODSQRT_P);

    /**************************************************************************/
    /* Step 4:                                                                */
    /* Solve the square root problem in the 2-Sylow subgroup of (Z/pZ)*.      */
    /**************************************************************************/

    /* If z is such that z^2 = t (mod p), then ( y*z^(-1) )^2 = a (mod p).            */
    /* We have already computed y, so it suffices to find z^(-1).                     */
    /* The value of z^(-1) (mod p) can be computed as a product of terms m^(2^k)      */
    /* for some values of k. Thus the final result y*z^(-1) is computed step by step  */
    /* in the following loop by accumulating the proper factors m^(2^k) in y.         */
    MCUX_CSSL_FP_LOOP_DECL(searchPow2OrderSubgroupLoop);
    for (uint32_t i = noOfTrailingZeroBits; i > 1u; i--)
    {
        /* Set b = t. */
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(MODSQRT_B, MODSQRT_T, 0u);

        /* Compute b = t^(2^(i-2)) (mod p). */
        MCUX_CSSL_FP_LOOP_DECL(exponentiationLoop);
        for (uint32_t j = 1u; j < i - 1u; j++)
        {
            /* Set b = b * b (mod p). */
            MCUXCLPKC_FP_CALC_MC1_MM(MODSQRT_S, MODSQRT_B, MODSQRT_B, MODSQRT_P);
            MCUXCLPKC_FP_CALC_OP1_OR_CONST(MODSQRT_B, MODSQRT_S, 0u);
            MCUX_CSSL_FP_LOOP_ITERATION(exponentiationLoop,
                MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
                MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST);
        }

        /* Check if b == 1. */
        MCUXCLPKC_FP_CALC_MC1_MR(MODSQRT_S, MODSQRT_B, MODSQRT_P);
        MCUXCLPKC_FP_CALC_OP1_SUB_CONST(MODSQRT_S, MODSQRT_S, 1u);
        uint32_t zeroFlag = MCUXCLPKC_WAITFORFINISH_GETZERO();

        /* Update y if b neq 1 (i.e. ord_p(t) = 2^(i-1)). */
        if (MCUXCLPKC_FLAG_ZERO != zeroFlag)
        {
            /* Set y = y * m (mod p). */
            MCUXCLPKC_FP_CALC_MC1_MM(MODSQRT_S, MODSQRT_Y, MODSQRT_M, MODSQRT_P);
            MCUXCLPKC_FP_CALC_OP1_OR_CONST(MODSQRT_Y, MODSQRT_S, 0u);
        }

        /* Set m = m * m (mod p). */
        MCUXCLPKC_FP_CALC_MC1_MM(MODSQRT_S, MODSQRT_M, MODSQRT_M, MODSQRT_P);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(MODSQRT_M, MODSQRT_S, 0u);

        /* Update t if b neq 1 (i.e. ord_p(t) = 2^(i-1)). */
        if (MCUXCLPKC_FLAG_ZERO != zeroFlag)
        {
            /* Set t = t * m (mod p). */
            MCUXCLPKC_FP_CALC_MC1_MM(MODSQRT_S, MODSQRT_T, MODSQRT_M, MODSQRT_P);
            MCUXCLPKC_FP_CALC_OP1_OR_CONST(MODSQRT_T, MODSQRT_S, 0u);
        }

        MCUX_CSSL_FP_LOOP_ITERATION(searchPow2OrderSubgroupLoop,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUX_CSSL_FP_LOOP_ITERATIONS(exponentiationLoop, i-2u),
            MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST,
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLPKC_FLAG_ZERO != zeroFlag),
                MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
                MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST),
            MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLPKC_FLAG_ZERO != zeroFlag),
                MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
                MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST));
    }

    /* Restore pUptrt. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_SETUPTRT(pBackupPtrUptrt);
    //MCUXCLPKC_PS1_SETLENGTH_REG(backupPs1LenReg);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_ModSquareRoot_TonelliShanks,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
        /* Step 1 */
        MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_SUB,
        MCUX_CSSL_FP_LOOP_ITERATIONS(findQuadraticNonResidueLoop, m - 1u),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        /* Step 2a */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_TrailingZeros),
        MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
        /* Step 2b */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SwitchEndianness),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModExp_SqrMultL2R),
        /* Step 3 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SwitchEndianness),
        MCUXCLPKC_FP_CALLED_CALC_OP2_SHR,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SwitchEndianness),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModExp_SqrMultL2R),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        /* Step 4 */
        MCUX_CSSL_FP_LOOP_ITERATIONS(searchPow2OrderSubgroupLoop, noOfTrailingZeroBits - 1u));

}


/**
 * [DESIGN]
 * This function given alpha and p computes the Legendre symbol (alpha/p). It assumes
 * that the given numbers alpha and p are of the same size, PS1 OPLEN.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_LegendreSymbol)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClMath_LegendreSymbol(mcuxClSession_Handle_t pSession, uint8_t iA, uint32_t iT1_iT2_iT3_iP)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_LegendreSymbol);

    const uint32_t iU = (iT1_iT2_iT3_iP >> 24u) & 0xFFu;  /* T1 */
    const uint32_t iV = (iT1_iT2_iT3_iP >> 16u) & 0xFFu;  /* T2 */
    const uint32_t iT = (iT1_iT2_iT3_iP >>  8u) & 0xFFu;  /* T3 */
    const uint32_t iP = iT1_iT2_iT3_iP & 0xFFu;

    /* Set t = a*R^(-1) (mod p) */
    /* where t is in range [0,v-1] and R is the Montgomery constant. */
    MCUXCLPKC_WAITFORFINISH();
    MCUXCLPKC_FP_CALC_MC1_MR(iT, iA, iP);
    MCUXCLPKC_FP_CALC_MC1_MS(iT, iT, iP, iP);

    /* In case t = 0 (mod p) return 0. */
    uint32_t zeroFlag = MCUXCLPKC_WAITFORFINISH_GETZERO();
    if (MCUXCLPKC_FLAG_ZERO == zeroFlag)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_LegendreSymbol, 0u,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);
    }

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint8_t *pU = MCUXCLPKC_OFFSET2PTR(pOperands[iU]);

    uint16_t offsetV = pOperands[iV];
    /* ASSERT: operand V (length = operandSize + MCUXCLPKC_WORDSIZE) is within PKC workarea. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(offsetV, MCUXCLPKC_RAM_OFFSET_MIN, MCUXCLPKC_RAM_OFFSET_MAX - (2u*MCUXCLPKC_WORDSIZE))

    /* Shift operand V to reserve 1 PKC word for NDash. */
    offsetV += MCUXCLPKC_WORDSIZE;
    pOperands[iV] = offsetV;
    const uint8_t *pV = MCUXCLPKC_OFFSET2PTR(offsetV);

    uint32_t isQuadraticResidue = 0u;

    /* Copy p to v. */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(iV, iP, 0u);

    /* Compute the Legendre symbol in the style of the Euclidean algorithm. */
    /* According to theory this loop won't exceed O(ln(A+P)) iterations. */
    MCUX_CSSL_FP_LOOP_DECL(quadraticResLoop);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t loopIterations = 0u);
    do
    {
        MCUX_CSSL_FP_COUNTER_STMT(loopIterations++);

        /* Copy v to u. */
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(iU, iV, 0u);

        /* Count trailing zeros of t. */
        MCUXCLPKC_WAITFORFINISH();
        MCUX_CSSL_FP_FUNCTION_CALL(result_trailingZeros, mcuxClMath_TrailingZeros((uint8_t)iT));
        uint32_t noOfTrailingZeroBits = result_trailingZeros;

        /* If number of trailing zero bits exceeds a PKC word (very rare scenario), shift iteratively. */
        while (63u < noOfTrailingZeroBits)
        {
            MCUXCLPKC_FP_CALC_OP1_SHR(iT, iT, 63u);
            noOfTrailingZeroBits -= 63u;
        }
        /* Shift t by the remaining number of zeros to make it odd. */
        MCUXCLPKC_FP_CALC_OP1_SHR(iV, iT, noOfTrailingZeroBits);

        /* Add the contribution of the quadratic reciprocity law for this step to the result. */
        /* That is (result_trailingZeros*(u^2-1)/8 + (u-1)*(v-1)/4) (mod 2). */
        MCUXCLPKC_WAITFORFINISH();
        isQuadraticResidue ^= ((((uint32_t)pU[0u] >> 1u) & 1u) & (((uint32_t)pV[0u] >> 1u) & 1u));
        isQuadraticResidue ^= ((((((uint32_t)pU[0u] >> 2u) & 1u) ^ (((uint32_t)pU[0u] >> 1u) & 1u))) & (result_trailingZeros & 1u));

        /* Set t = u*R^(-1) (mod v) */
        /* where t is in range [0,v-1] and R is the Montgomery constant. */
        MCUXCLMATH_FP_NDASH(pSession, iV, iT);
        MCUXCLPKC_FP_CALC_MC1_MR(iT, iU, iV);
        MCUXCLPKC_FP_CALC_MC1_MS(iT, iT, iV, iV);

        /* Check if t = 0. */
        zeroFlag = MCUXCLPKC_WAITFORFINISH_GETZERO();

        MCUX_CSSL_FP_LOOP_ITERATION(quadraticResLoop,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_TrailingZeros),
            MCUX_CSSL_FP_CONDITIONAL((63u < result_trailingZeros), (result_trailingZeros / 63u - 1u) * MCUXCLPKC_FP_CALLED_CALC_OP1_SHR),
            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash),
            MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);

    } while (MCUXCLPKC_FLAG_ZERO != zeroFlag);

    /* Map the result from the set {0,1} to the standard {-1,+1}. */
    /* (-1 is interpreted as 0xFFFFFFFFu) */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("isQuadraticResidue is either 0,1 so result won't wrap")
    uint32_t result = ((0xFFFFFFFEu) * isQuadraticResidue) ^ 1u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Restore V buffer address */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pOperands[iV] won't wrap as it was incremented by MCUXCLPKC_WORDSIZE in the beginning of this function.")
    pOperands[iV] -= MCUXCLPKC_WORDSIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_LegendreSymbol, result,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUX_CSSL_FP_LOOP_ITERATIONS(quadraticResLoop, loopIterations));
}
