/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2024 NXP                                       */
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
 * @file  mcuxClEcc_Weier_Internal_PointArithmetic.c
 * @brief Weierstrass curve internal point arithmetic
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>


/**
 * This function implements repeated point doubling, R = 2^(iteration) * P.
 *
 * Input:
 *   iteration: the number of iterations of doublings, it has to be >= 2.
 *
 * Inputs in pOperands[] and PKC workarea:
 *   buffers (VX2,VY2, VZ2) contain input P, relative-z;
 *   buffer VZ contains z coordinate.
 *
 * Prerequisites:
 *   **CAUTION** VT is the 5th temp buffer (different from T0/T1/T2/T3);
 *   ps1Len = (operandSize, operandSize);
 *   buffer WEIER_A contains curve coefficient a, Montgomery representation;
 *   curve order p in P, NDash of p in PFULL, shifted modulus of p in PS.
 *
 * Result in PKC workarea:
 *   buffers (VX0,VY0, VZ0) contain result R, relative-z (w.r.t. z).
 *
 * Other modifications:
 *   buffers VT, T0, T1, T2 and T3 are modified (as temp);
 *   offsets pOperands[VX2/VY2/VZ2] are modified.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_RepeatPointDouble)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_RepeatPointDouble(uint32_t iteration)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_RepeatPointDouble);

    /* The 1st iteration: init/double/update. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_RepeatDouble,
                        mcuxClEcc_FUP_Weier_RepeatDouble_LEN);

    /* Switch to in-place. */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_VX0);
    pOperands[WEIER_VZ2] = pOperands[WEIER_VZ0];

    uint32_t remIter = iteration - 1u;
    MCUX_CSSL_FP_LOOP_DECL(Doublings);
    while(remIter > 1u)
    {
        MCUX_CSSL_FP_LOOP_ITERATION(Doublings,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );

        /* Iterations in between: double/update. */
        MCUXCLPKC_FP_CALCFUP_OFFSET(mcuxClEcc_FUP_Weier_RepeatDouble, mcuxClEcc_FUP_Weier_RepeatDouble_LEN1,
                                   mcuxClEcc_FUP_Weier_RepeatDouble_LEN2 + mcuxClEcc_FUP_Weier_RepeatDouble_LEN3);
        remIter--;
    }

    /* The last iteration: only double. */
    /* MISRA Ex. 22, while(0) is allowed */
    MCUXCLPKC_FP_CALCFUP_OFFSET(mcuxClEcc_FUP_Weier_RepeatDouble, mcuxClEcc_FUP_Weier_RepeatDouble_LEN1,
                               mcuxClEcc_FUP_Weier_RepeatDouble_LEN2);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_RepeatPointDouble,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_LOOP_ITERATIONS(Doublings, iteration - 2u),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );
}


/** This function calculates point addition, ...
 * @retval #MCUXCLECC_STATUS_OK                        if the result is not the neutral point;
 * @retval #MCUXCLECC_STATUS_NEUTRAL_POINT             if the result is the neutral point.
 *
 * Inputs in pOperands[] and PKC workarea:
 *   buffers (VX2,VY2, VZ2) contain P0, relative-z;
 *   buffers (VX1,VY1, VZ) contain P1, Jacobian.
 *
 * Prerequisites:
 *   **CAUTION** VT is the 5th temp buffer (different from T0/T1/T2/T3);
 *   ps1Len = (operandSize, operandSize);
 *   buffer VA contains curve coefficient a, Montgomery representation;
 *   curve order p in P, NDash of p in PFULL, shifted modulus of p in PS.
 *
 * Result in PKC workarea:
 *   buffers (VX0,VY0, VZ0) contain result P0+P1, relative-z, if the result is not the neutral point.
 *
 * Other modifications:
 *   buffers VT, T0, T1, T2 and T3 are modified (as temp);
 *   offsets pOperands[VT2/VT3/VX2/VY2] are modified.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_PointFullAdd)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_PointFullAdd(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_PointFullAdd,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS );

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();

    MCUXCLPKC_WAITFORREADY();

    /* Convert P1: (VX1,VY1, VZ) Jacobian -> P2: (T2,T3, VZ0) relative-z. */
    pOperands[WEIER_VT2] = pOperands[ECC_T2];
    pOperands[WEIER_VT3] = pOperands[ECC_T3];
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_DoubleAdd, mcuxClEcc_FUP_Weier_DoubleAdd_LEN1);

    /* Check if P0.x != P2.x. */
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T1, WEIER_VX2, WEIER_VT2, ECC_PS);  // t1 = P0.x - P2.x
    MCUXCLPKC_FP_CALC_MC1_MR(ECC_T0, ECC_T1,  ECC_P);            // t0 = P0.x - P2.x in NR in range [0, p]
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T0, ECC_T0,  ECC_P,   ECC_P);   // t0 in range [0, p-1]
    if (MCUXCLPKC_FLAG_ZERO != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {   /* Addition */

        /* Calculate P1 + P2 in (VX0,VY0, VZ0) relative-z. */
        /* MISRA Ex. 22, while(0) is allowed */
        MCUXCLPKC_FP_CALCFUP_OFFSET(mcuxClEcc_FUP_Weier_DoubleAdd, mcuxClEcc_FUP_Weier_DoubleAdd_LEN1,
                                   mcuxClEcc_FUP_Weier_DoubleAdd_LEN2);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_PointFullAdd, MCUXCLECC_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );
    }

    /* Check if P0.y == - P2.y. */
    MCUXCLPKC_FP_CALC_MC1_MA(ECC_T1, WEIER_VY2, WEIER_VT3, ECC_PS);  // t1 = P0.x + P2.x
    MCUXCLPKC_FP_CALC_MC1_MR(ECC_T0, ECC_T1, ECC_P);                 // t0 = P0.x + P2.x in NR in range [0,p]
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T0, ECC_T0, ECC_P, ECC_P);          // t0 in range [0, p-1]
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {   /* Neutral point */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_PointFullAdd, MCUXCLECC_STATUS_NEUTRAL_POINT,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MA,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS );
    }

    /* Calculate 2*P0 in (VX0,VY0, VZ0) relative-z. */
    MCUXCLECC_FP_CALCFUP_ONE_DOUBLE();

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_PointFullAdd, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MA,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUXCLECC_FP_CALLED_CALCFUP_ONE_DOUBLE );
}
