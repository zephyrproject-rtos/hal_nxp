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
 * @file  mcuxClEcc_Weier_Internal_PointMult.c
 * @brief Weierstrass curve internal point multiplication
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>


/**
 * This function implements (non-secure) point scalar multiplication, R = scalar * P.
 *
 * Inputs:
 *   iScalar: index of PKC buffer storing the scalar, which is
 *            in little-endian, non-zero and interleaved;
 *   scalarBitLength: bit length of scalar.
 *
 * Inputs in pOperands[] and PKC workarea:
 *   Prec1 = P,         in (X1,Y1, Z) Jacobian;
 *   Prec2 = PrecP,     in (X2,Y2, Z) Jacobian;
 *   Prec3 = P + PrecP, in (X3,Y3, Z) Jacobian.
 *
 * Prerequisites:
 *   **CAUTION** VT is the 5th temp buffer (different from T0/T1/T2/T3);
 *   ps1Len = (operandSize, operandSize);
 *   buffer VA contains curve coefficient a, Montgomery representation;
 *   curve order p in P, NDash of p in PFULL, shifted modulus of p in PS.
 *
 * Result in PKC workarea:
 *   buffers (XA,YA, ZA) contain result R, relative-z (w.r.t. Z).
 *
 * Other modifications:
 *   buffers VT, T0, T1, T2 and T3 are modified (as temp);
 *   offsets pOperands[VT2/VT3/VX0/VY0/VZ0/VZ/VX1/VY1/VX2/VY2/VZ2] are modified.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Int_PointMult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Int_PointMult(uint8_t iScalar, uint32_t scalarBitLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Int_PointMult);
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(scalarBitLength, 8u * MCUXCLECC_WEIERECC_MIN_SIZE_PRIVATEKEY, 8u * MCUXCLECC_WEIERECC_MAX_SIZE_PRIVATEKEY)

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 to Rule 11.3 - PKC word is CPU word aligned.")
    const uint32_t *pScalar = (const uint32_t *) MCUXCLPKC_OFFSET2PTR(pOperands[iScalar]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    uint32_t scalarWord;
    uint32_t scalarBits;
    uint32_t index = scalarBitLength;

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_InterleaveScalar(iScalar, scalarBitLength, 1u));

    /* Scan scalar and skip leading zero bits. */
    MCUX_CSSL_FP_LOOP_DECL(PointMult_Double);
    MCUXCLPKC_WAITFORFINISH(); /* Wait for scalar interleaving */
    do
    {
        MCUX_CSSL_FP_LOOP_ITERATION(PointMult_Double);  /* trivial double */
        /* Scalar is nonzero and even number */
        MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(index, 2u, scalarBitLength)
        index -= 2u;
        scalarWord = pScalar[index / 32u];
        scalarBits = (scalarWord >> (index & 31u)) & 0x3u;
    } while (0u == scalarBits);  /* assume scalar is non-zero. */

    /* Prepare offsets to coordinates of Prec_i. */
    uint32_t offsets_VY_VX = pOperands32[(WEIER_X1 / 2u) - 1u + scalarBits];
    /* Prepare offsets to coordinates of R. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting pOperands32 from 32-bit to 16-bit is allowed because pOperands32 was originally defined as uint16_t*.")
    uint32_t offsets_VYA_VXA = MCUXCLECC_LOAD_2OFFSETS(pOperands32, WEIER_XA, WEIER_YA);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Initialize z' = 1 in MR. */
    MCUXCLPKC_FP_CALC_OP1_NEG(WEIER_ZA, ECC_P);

    /* Select Prec_i by updating (VX2, VY2). */
//  MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VX2 and VY2 are not used in previous computation.
    MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, offsets_VY_VX);

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t NoOfAdd = 0u);

    MCUX_CSSL_FP_LOOP_DECL(PointMult_Add);
    if (0u == index)
    {
        MCUX_CSSL_FP_LOOP_ITERATION(PointMult_Add,  /* trivial add */
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST );
        MCUX_CSSL_FP_COUNTER_STMT(NoOfAdd += 1u);

        /* Copy, R = Prec_i. */
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_XA, WEIER_VX2, 0u);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_YA, WEIER_VY2, 0u);
    }
    else
    {
        MCUX_CSSL_FP_LOOP_ITERATION(PointMult_Double,
            MCUXCLECC_FP_CALLED_CALCFUP_ONE_DOUBLE );

        /* Set offsets to buffers for FUPs: RepeatDouble and DoubleAdd. */
        pOperands[WEIER_VT2] = pOperands[ECC_T2]; /* temp for FUP DoubleAdd */
        pOperands[WEIER_VT3] = pOperands[ECC_T3]; /* temp for FUP DoubleAdd */
        MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, offsets_VYA_VXA);  /* result for both FUPs */
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VZ0, WEIER_ZA);  /* input(DoubleAdd)/output(both FUPs): z' in ZA; input(RepeatDouble): zRef in Z */
        pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];  /* input: z' in ZA, for FUP RepeatDouble */

        /* Double, R = 2 * Prec_i, where Prec_i is selected by (VX2, VY2). */
        MCUXCLECC_FP_CALCFUP_ONE_DOUBLE();
        /* Scalar is nonzero, even number and 0u != index */
        MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(index, 2u, scalarBitLength)
        index -= 2u;
        MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
        scalarWord = pScalar[index / 32u];
        scalarBits = (scalarWord >> (index & 31u)) & 0x3u;

        /* Set VX2/VY2 to calculate R = 2 * R in the remaining iterations. */
        MCUXCLPKC_WAITFORREADY();
        MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, offsets_VYA_VXA);

        /* Point addition (optional) */
        if (0u != scalarBits)
        {
            MCUX_CSSL_FP_LOOP_ITERATION(PointMult_Add,
                MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY );
            MCUX_CSSL_FP_COUNTER_STMT(NoOfAdd += 1u);

            /* Select Prec_i by updating (VX1, VY1) according to scalarBits. */
            offsets_VY_VX = pOperands32[(WEIER_X1 / 2u) - 1u + scalarBits];
            MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, offsets_VY_VX);

            /* Add, R = R + Prec_i. */
            MCUXCLECC_FP_CALCFUP_ADD_ONLY();
        }
    }

    /* Point double and addition (not always) of the remaining iteration(s). */
    while (0u != index)
    {
        /* Scalar is nonzero, even number and 0u != index */
        MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(index, 2u, scalarBitLength)
        index -= 2u;
        if (0x1Eu == (index & 0x1Fu))
        {
            MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
            scalarWord = pScalar[index / 32u];
        }
        scalarBits = (scalarWord >> (index & 0x1Fu)) & 0x3u;

        if (0u == scalarBits)
        {   /* Double only */
            MCUX_CSSL_FP_LOOP_ITERATION(PointMult_Double,
                MCUXCLECC_FP_CALLED_CALCFUP_ONE_DOUBLE );

            /* Calculate: R = 2R. */
            MCUXCLECC_FP_CALCFUP_ONE_DOUBLE();
        }
        else
        {   /* Double and Add */
            MCUX_CSSL_FP_LOOP_ITERATION(PointMult_Double);
            MCUX_CSSL_FP_LOOP_ITERATION(PointMult_Add,
                MCUXCLECC_FP_CALLED_CALCFUP_DOUBLE_ADD );
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Number of Add dont overflow")
            MCUX_CSSL_FP_COUNTER_STMT(NoOfAdd += 1u);
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

            /* Select Prec_i by updating (VX1, VY1) according to scalarBits. */
            offsets_VY_VX = pOperands32[(WEIER_X1 / 2u) - 1u + scalarBits];
            MCUXCLPKC_WAITFORREADY();
            MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, offsets_VY_VX);

            /* Calculate: R = 2R + Prec_i. */
            MCUXCLECC_FP_CALCFUP_DOUBLE_ADD();
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_Int_PointMult,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_InterleaveScalar),
        MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,
        MCUX_CSSL_FP_LOOP_ITERATIONS(PointMult_Double, scalarBitLength / 2u),
        MCUX_CSSL_FP_LOOP_ITERATIONS(PointMult_Add, NoOfAdd) );
}
