/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_SecurePointMult_CoZMontLadder.c
 * @brief Weierstrass curve internal secure point multiplication
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>

#include <internal/mcuxClEcc_Internal_Random.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClPrng_Internal_Functions.h>
#include <internal/mcuxClPrng_Internal.h>


/** This function implements secure point scalar multiplication, R = scalar * P, based on Co-Z Montgomery ladder.
 *
 * Inputs:
 *   iScalar: index of PKC buffer storing the scalar, which is non-zero and in little-endian;
 *   scalarBitLength: bit length of scalar.
 *
 * Inputs in pOperands[] and PKC workarea:
 *   P in (X0,Y0, Z) Jacobian.
 *
 * Prerequisites:
 *   buffer VA contains curve coefficient a, Montgomery representation;
 *   ps1Len = (operandSize, operandSize);
 *   curve order p in P, NDash of p in PFULL, shifted modulus of p in PS.
 *
 * Result in PKC workarea:
 *   buffers (X0,Y0, Z) contain result R, Jacobian.
 *
 * Other modifications:
 *   buffers T0, T1, T2 and T3 are modified (as temp);
 *   buffers ZA, X1 and Y1 are modified;
 *   offsets pOperands[VX0/VY0/VZ0/VZ/VX1/VY1/VX2/VY2/VZ2/VT] are modified;
 *   pOperands[X0/Y0/X1/Y1] and location of corresponding buffers are randomized.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 * @attention This function uses PRNG which has to be initialized prior to calling the function.
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_SecurePointMult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_SecurePointMult(uint8_t iScalar,
                                                          uint32_t scalarBitLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_SecurePointMult,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,
        MCUXCLECC_FP_CALLED_CALCFUP_ONE_DOUBLE,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(scalarBitLength, 8u * MCUXCLECC_WEIERECC_MIN_SIZE_PRIVATEKEY, 8u * MCUXCLECC_WEIERECC_MAX_SIZE_PRIVATEKEY)

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 to Rule 11.3 - PKC word is CPU word aligned.")
    const uint32_t *pScalar = (const uint32_t *) MCUXCLPKC_OFFSET2PTR(pOperands[iScalar]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /**
     * Step 1: Randomize input point P coordinates (X0, Y0, Z)
     */

    /* Generate a randomized relative Z-coordinate in ZA */
    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_ZA]), operandSize));

    /* Reduce ZA modulo p, update the Z-coordinate and update the coordinates of P0 to the new Z-coordinate */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1,
                        mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN1      /* PrepareZ */
                        + mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN2);  /* UpdateZ and P0 */


    /**
     * Step 2: Skip leading scalar zeros and read and XOR-mask first non-zero scalar word
     */

    /* Initialize scalar word shares variables and generate XOR-mask for the first non-zero scalar word */
    uint32_t scalarBitIndex = scalarBitLength - 1u;
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
    uint32_t scalarWord0 = pScalar[scalarBitIndex / 32u];
    uint32_t scalarWord1;
    MCUX_CSSL_FP_FUNCTION_CALL(prngGenerateWordRet1, mcuxClPrng_generate_word());
    scalarWord1 = prngGenerateWordRet1;

    /* Scan scalar and skip leading zero bits. */
    while (0u == scalarWord0)
    {
        /* Scalar is nonzero */
        MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(scalarBitIndex, 32u, scalarBitLength - 1u)
        scalarBitIndex -= 32u;
        scalarWord0 = pScalar[scalarBitIndex / 32u];
    }
    uint32_t scalarWord0leadingZeros = mcuxClMath_CountLeadingZerosWord(scalarWord0);  /* bit position of most significant non-zero bit */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(scalarWord0leadingZeros, 0u, 31u)
    scalarBitIndex = (scalarBitIndex | 31u) - scalarWord0leadingZeros;
    scalarWord0 ^= scalarWord1;


    /**
     * Step 3: Prepare accumulated ladder points R0 (X0, Y0, Z) and R1 (X1, Y1, Z) and ensure that their
     *         X- and Y-coordinates are in range [0,p-1], a prerequisite for each ladder step.
     */

    /* Initialize z' = 1 in MR. */
    MCUXCLPKC_FP_CALC_OP1_NEG(WEIER_ZA, ECC_P);

    /* Calculate R1 = P + P = 2*R0                               */
    /* Input:  R0 in (X0,Y0, ZA=1) relative-Z (w.r.t. ZRef in Z) */
    /* Output: R1 in (X1,Y1, ZA)   relative-Z                    */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X1);  /* R1 */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VZ0, WEIER_ZA);  /* R1.z and ZRef */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_X0);  /* R0 */
    pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];  /* R0.z */
    pOperands[WEIER_VT]  = pOperands[ECC_T3];    /* 5th temp */
    MCUXCLECC_FP_CALCFUP_ONE_DOUBLE();

    /* Ensure that X1 and Y1 are in range [0,p-1] as a prerequisite for the scalar multiplication loop.
     * Also ensure ZA < p as a prerequisite for the upcoming coordinate update*/
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_SecurePointMult_Reduce_X1_Y1_ZA_ModP, mcuxClEcc_FUP_Weier_SecurePointMult_Reduce_X1_Y1_ZA_ModP_LEN);

    /* Update z = z * z', so R1: (X1,Y1, ZA) relative-z -> (X1,Y1, Z) Jacobian.
     * Update Jacobian coordinates in MR of R0 (X0,Y0, Z).
     *
     * NOTE: Since ZA < p before the FUP program, the same holds for X0 and Y0 after the FUP program
     *       which is a prerequisite for the scalar multiplication loop */
    MCUXCLPKC_FP_CALCFUP_OFFSET(mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1,
                               mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN1,   /* Skip the first part (PrepareZA) */
                               mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN2);  /* Only UpdateZ and P0 */


    /**
     * Step 4: Execute Montgomery ladder to process the remaining scalar words and compute the result
     *
     * NOTES:
     *   - It is ensured that before and after every ladder step the X- and Y-coordinates of the accumulated points are in range [0,p-1].
     *     This shall help to avoid side-channel leakage.
     *   - For every new scalar word, the coordinates of the accumulated points are re-randomized with a fresh random Z-coordinate and
     *     also buffers are shuffled
     */

    /* FP balance here, to avoid keeping another copy of scalarBitIndex. */
    MCUX_CSSL_FP_LOOP_DECL(MainLoop);
    MCUX_CSSL_FP_LOOP_DECL(RandomizeInMainLoop);  /* This needs to be declared outside the loop. */
    MCUX_CSSL_FP_COUNTER_STMT(const volatile uint32_t scalarBitIndexBeforeLoop = scalarBitIndex); /* volatile to prevent compiler from re-reading scalarBitIndex */

    /* The remaining iteration(s) of Montgomery ladder. */
    while (0u != scalarBitIndex)
    {
        MCUX_CSSL_FP_LOOP_ITERATION(MainLoop,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointSelectML),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));

        scalarBitIndex -= 1u;
        uint32_t bitOffset = scalarBitIndex & 0x1Fu;
        if (0x1Fu == bitOffset)
        {
            MCUX_CSSL_FP_LOOP_ITERATION(RandomizeInMainLoop,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ReRandomizeUPTRT),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );

            /* Re-randomize coordinate buffers used within secure scalar multiplication (X0/Y0/X1/Y1). */
            /* (pkcwa order is changed accordingly)            */
            MCUXCLPKC_WAITFORFINISH();
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_ReRandomizeUPTRT(&pOperands[WEIER_X0],
                                                                (uint16_t) (operandSize & 0xFFFFu),
                                                                (WEIER_Y1 - WEIER_X0 + 1u)) );

            /* After rerandomization, pointer pZA (used in mcuxClPrng_generate_Internal call)         */
            /* and pOperands[WEIER_VZ] (used by double-and-add FUP program) need to be updated. */
            pOperands[WEIER_VZ]  = pOperands[WEIER_Z];
            /* Rerandomize R0 (X0,Y0, Z) and R1 (X1,Y1, Z) and ensure that the X- and Y-coordinates are in range [0,p-1]. */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal( MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_ZA]), operandSize));

            MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1,
                                mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN);

            /* Read next CPU word of scalar. */
            MCUX_CSSL_FP_FUNCTION_CALL(prngGenerateWordRet2, mcuxClPrng_generate_word());
            scalarWord1 = prngGenerateWordRet2;

            MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
            scalarWord0 = pScalar[scalarBitIndex / 32u] ^ scalarWord1;
        }

        /* When bit of scalar = 0, the function returns:   */
        /*   pOperands[WEIER_VX0] = pOperands[WEIER_X0],     */
        /*   pOperands[WEIER_VY0] = pOperands[WEIER_Y0],     */
        /*   pOperands[WEIER_VX1] = pOperands[WEIER_X1],     */
        /*   pOperands[WEIER_VY1] = pOperands[WEIER_Y1];     */
        /* when bit = 1,                                   */
        /*   pOperands[WEIER_VX0] = pOperands[WEIER_X1],     */
        /*   pOperands[WEIER_VY0] = pOperands[WEIER_Y1],     */
        /*   pOperands[WEIER_VX1] = pOperands[WEIER_X0],     */
        /*   pOperands[WEIER_VY1] = pOperands[WEIER_Y0].     */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_SecurePointSelectML(scalarWord0, scalarWord1, bitOffset, WEIER_X0, WEIER_VX0));

        /* Perform double-and-add step.
         *
         * NOTE: Since X0, Y0, X1, Y1 < p before the double-and-add step, the same holds for those coordinates afterwards. */
        MCUXCLPKC_FP_CALCFUP_OFFSET(mcuxClEcc_FUP_Weier_CoZPointAddSub,
                                   mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN1,
                                   mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN2);
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_CoZPointAddSub, mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN);
    }

    /* Read into non-volatile variable to avoid compile error "undefined behavior: the order of volatile accesses is undefined" */
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t scalarBitIndexBeforeLoopFP = scalarBitIndexBeforeLoop);
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_SecurePointMult,
        MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop, scalarBitIndexBeforeLoopFP),
        MCUX_CSSL_FP_LOOP_ITERATIONS(RandomizeInMainLoop, scalarBitIndexBeforeLoopFP/32u)
    );
}
