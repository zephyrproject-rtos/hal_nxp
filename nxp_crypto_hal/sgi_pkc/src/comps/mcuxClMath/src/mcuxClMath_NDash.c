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
 * @file  mcuxClMath_NDash.c
 * @brief mcuxClMath: implementation of the function mcuxClMath_NDash
 */


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClMath_Internal_NDash.h>
#include <internal/mcuxClMath_NDash_FUP.h>
#include <internal/mcuxClMath_Internal_Functions.h>


/**
 * [Design]
 * This function calculates NDash = (-n)^(-1) mod 256^(MCUXCLPKC_WORDSIZE),
 * where n is an odd number, by using mathematical induction:
 *
 * Let x0 \equiv 1 (mod 2), and suppose xi \equiv (-n)^(-1) (mod 2^(2^i)).
 * Since 1 + xi * n \equiv 0 (mod 2^(2^i)), so
 * (1 + xi * n)^2 = 1 + (2*xi + xi^2 *n) * n \equiv 0 (mod 2^(2^(i+1))), and
 * x_{i+1} \equiv 2*xi + xi^2 * n = (xi * n + 2) * xi (mod 2^(2^(i+1))).
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_NDash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_NDash(mcuxClSession_Handle_t pSession, uint16_t iN_iT)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_NDash);

    /* Prepare local UPTRT. */
    uint32_t mathLocalUptrtWordOffset = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(NDASH_UPTRT_OFFSET * sizeof(uint16_t));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting 32-bit pointer to 16-bit pointer is 16-bit aligned")
    uint16_t * const pOperands = (uint16_t*)(pSession->pMathUptrt + mathLocalUptrtWordOffset);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    const uint16_t *pBackupPtrUptrt;
    /* mcuxClMath_InitLocalUptrt always returns _OK. */
    /* localPtrUptrt parameter of mcuxClMath_InitLocalUptrt starts at pOperands + NDASH_T. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMath_InitLocalUptrt((uint32_t) iN_iT, 0U, pOperands, 2u, &pBackupPtrUptrt));

    const uint16_t offsetN = pOperands[NDASH_N];
    /* ASSERT: operand N (length >= MCUXCLPKC_WORDSIZE) is within PKC workarea, and 1 PKC word is reserved before N. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(offsetN, MCUXCLPKC_RAM_OFFSET_MIN + MCUXCLPKC_WORDSIZE, MCUXCLPKC_RAM_OFFSET_MAX - MCUXCLPKC_WORDSIZE)

    /* WAITFORREADY in mcuxClMath_InitLocalUptrt(...). */
    pOperands[NDASH_NDASH] = (uint16_t) (offsetN - MCUXCLPKC_WORDSIZE);
    pOperands[NDASH_CONST2] = 2u;
    pOperands[NDASH_CONST0] = 0u;

    MCUXCLPKC_PS2_SETLENGTH(0, MCUXCLPKC_WORDSIZE);

    /* x1 \equiv 1 (mod 4), if n mod 4 = 3; */
    /*    \equiv 3 (mod 4), if n mod 4 = 1. */
    MCUXCLPKC_FP_CALC_OP2_NEG(NDASH_NDASH, NDASH_N);

    for (uint32_t bit = 2u; bit < (MCUXCLPKC_WORDSIZE * 8u); bit <<= 1)
    {
        MCUXCLPKC_FP_CALCFUP(mcuxClMath_NDash_Fup, mcuxClMath_NDash_Fup_LEN);
    }

    /* Restore pUptrt. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_SETUPTRT(pBackupPtrUptrt);

#if (16u == MCUXCLPKC_WORDSIZE)
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_NDash,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
        MCUXCLPKC_FP_CALLED_CALC_OP2_NEG,
        /* hard-coded (log2PkcWordsize + 3) - 1 = 5 iterations of the loop. */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x2 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x3 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x4 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x5 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x6 = ... (mod 2^(2^6)). */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)    /* calculate x7 = ... (mod 2^(2^7)). */
        );
#else
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_NDash,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
        MCUXCLPKC_FP_CALLED_CALC_OP2_NEG,
        /* hard-coded (log2PkcWordsize + 3) - 1 = 5 iterations of the loop. */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x2 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x3 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x4 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* calculate x5 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)    /* calculate x6 = ... (mod 2^(2^6)). */
        );
#endif


}
