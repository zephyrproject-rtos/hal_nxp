/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal_VarScalarMult.c
 * @brief Scalar multiplication with a variable point P on a twisted Edwards curve
 */

#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClPkc.h>
#include <mcuxClMath.h>

#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Macros.h>

#include <mcuxClEcc.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>

/**
 * This function performs a scalar multiplication of a scalar lambda in range [0,...,n-1] and a variable twisted Edwards curve point P 
 * in the base point order group, i.e. a point of odd prime order or the neutral point. 
 * The input point is assumed to be a valid point on the curve.
 *
 * Input:
 *   - pSession             Current session of the CL
 *   - pDomainParams        Pointer to common ECC domain parameters
 *   - iScalar              Table index of the PKC buffer holding the scalar lambda
 *   - scalarBitLength      Bit length of the scalar
 *   - options              Options parameter of the function. The following options must be set, otherwise FAULT_ATTACK will be returned:
 *                              - OPTION_AFFINE_OUTPUT or OPTION_PROJECTIVE_OUTPUT if the output point shall be in affine (i.e. with Z = 1)
 *                              or projective coordinates (i.e. with Z != 1)
 *   - ptrSelectFct         Pointer selection function.
 *   - ptrSelectFctFPId     Pointer selection function FP token.
 * 
 * Prerequisites:
 *   -  Buffer buf(iScalar) contains the secret scalar lambda of bit length scalarBitLength
 *   -  Buffers TWED_X, TWED_Y and TWED_Z contain the homogeneous coordinates (X:Y:Z) of P in MR
 *   -  Buffer ECC_CP1 contains d in MR
 *   -  ps1Len = (operandSize, operandSize)
 *   -  Buffer ECC_PFULL contains p'||p
 *   -  Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *   - If MCUXCLECC_STATUS_OK is returned, buffers TWED_X, TWED_Y and TWED_Z contain Xres, Yres and Zres in MR, even if the input point 
 *     (and the result) is the neutral point.
 * 
 * Returns:
 *   - MCUXCLECC_STATUS_OK               if the function executed successfully
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_VarScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_TwEd_VarScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_CommonDomainParams_t *pDomainParams,
    uint8_t iScalar,
    uint32_t scalarBitLength,
    uint32_t options,
    mcuxClEcc_TwEd_PtrSelectFunction_t ptrSelectFct,
    uint32_t ptrSelectFctFPId
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_VarScalarMult);

    /* Determine pointer table pointer */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy - TODO CLNS-6410: check if this is necessary
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 to Rule 11.3 - PKC word is CPU word aligned.")
    const uint32_t *pScalar = (const uint32_t *) MCUXCLPKC_OFFSET2PTR(pOperands[iScalar]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Step 1: Check if the passed input point is the neutral point and if so, simply skip the upcoming Montgomery ladder
     * algorithm because this can only properly handle points of odd prime order.
     *
     * NOTE: Since the input point is assumed to be a point of odd order on the twisted Edwards curve, it is sufficient to check if
     *       the X-coordinate is zero mod p, for the only two points with X = 0 are the neutral point (0:Z:Z) and the point of order 2 (0:-Z:Z),
     *       which is an invalid input for this function.
     */
    MCUXCLPKC_FP_CALC_MC1_MR(ECC_T0, TWED_X, ECC_P);
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T0, ECC_T0, ECC_P, ECC_P);

    MCUX_CSSL_FP_BRANCH_DECL(scalarZeroBranch);
    uint32_t scalarZeroPkcCheck = MCUXCLPKC_WAITFORFINISH_GETZERO();
    if (MCUXCLPKC_FLAG_NONZERO == scalarZeroPkcCheck)
    {
        /* Step 2: Initialize the accumulated points in YZ-coordinates */
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(TWED_ML_Y1, TWED_Z, 0u);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(TWED_ML_Z1, TWED_Z, 0u);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(TWED_ML_Y2, TWED_Y, 0u);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(TWED_ML_Z2, TWED_Z, 0u);

        /* Step 3: Import ladder constant (a/d mod p), convert it to MR modulo p, and store it in buffer ECC_CP0. */
        MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
        uint32_t byteLenP = (uint32_t) pDomainParams->byteLenP;
        MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC(ECC_T0, pDomainParams->pLadderConst, byteLenP);
        MCUXCLPKC_FP_CALC_MC1_MM(ECC_CP0, ECC_T0, ECC_PQSQR, ECC_P);

        MCUX_CSSL_ANALYSIS_START_PATTERN_HYPERLINK_IN_COMMENTS()
        /* Step 4: Perform ladder loop to calculate YZ-coordinates for the resulting point according to Algorithms 4 and 5 in https://ieeexplore.ieee.org/document/6550581
        * For the pointer selection, the function specified by ptrSelectFct is used.
        */
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_HYPERLINK_IN_COMMENTS()
        uint32_t i = scalarBitLength;
        uint32_t currentScalarWord = 0u;
        MCUX_CSSL_FP_LOOP_DECL(whileLoop);
        MCUX_CSSL_FP_BRANCH_DECL(ifInWhile);
        while(0u < i)
        {
            /* Update loop counter, deviation from the design to let iterate over unsigned value */
            --i;

            /* Select pointers pOperands[TWED_VY1],...,pOperands[TWED_VZ2] according to the bit to be processed */
            uint32_t currentScalarBitInWord = i % 32u;
            if((i == (scalarBitLength - 1u)) || ((i % 32u) == 31u))
            {
                MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
                uint32_t currentScalarWordIndex = i / 32u;
                currentScalarWord = pScalar[currentScalarWordIndex];
                MCUX_CSSL_FP_BRANCH_POSITIVE(ifInWhile);
            }
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(ptrSelectFct(pSession, currentScalarWord, (uint8_t)currentScalarBitInWord));

            /* Perform the ladder step to calculate (VY2:VZ2) = (VY1:VZ1) + (VY2:VZ2) and (VY1:VZ1) = 2*(VY1:VZ1) */
            MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep, mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep_LEN);

            /* FP balancing for the loop iteration */
            MCUX_CSSL_FP_LOOP_ITERATION(whileLoop,
                MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(ifInWhile, (i == (scalarBitLength - 1u)) || ((i % 32u) == 31u)),
                ptrSelectFctFPId,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
                );
        }

        /* Step 5: Import curve parameter a, convert it to MR modulo p, and store it in buffer ECC_CP0. */
        MCUXCLPKC_WAITFORFINISH();
        MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC(ECC_T0, pDomainParams->pCurveParam1, byteLenP);
        MCUXCLPKC_FP_CALC_MC1_MM(ECC_CP0, ECC_T0, ECC_PQSQR, ECC_P);

        /* Step 6: Recover the missing X-coordinate */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate, mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate_LEN);

        MCUX_CSSL_FP_BRANCH_POSITIVE(scalarZeroBranch,
            4u * MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportLittleEndianToPkc),
            MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
            MCUX_CSSL_FP_LOOP_ITERATIONS(whileLoop, scalarBitLength),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportLittleEndianToPkc),
            MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
    }

    /* Step 7: If requested, convert the result to affine coordinates */
    if(MCUXCLECC_SCALARMULT_OPTION_AFFINE_OUTPUT == (MCUXCLECC_SCALARMULT_OPTION_OUTPUT_MASK & options))
    {
        MCUXCLMATH_FP_MODINV(ECC_T0, TWED_Z, ECC_P, ECC_T1);         /* T0 = Z^(-1)*R^(-1) mod p */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_ConvertHomToAffine, mcuxClEcc_FUP_ConvertHomToAffine_LEN);
    }
    else if(MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_OUTPUT != (MCUXCLECC_SCALARMULT_OPTION_OUTPUT_MASK & options))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_TwEd_VarScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing */
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_TwEd_VarScalarMult, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarZeroBranch, MCUXCLPKC_FLAG_NONZERO == scalarZeroPkcCheck),
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLECC_SCALARMULT_OPTION_AFFINE_OUTPUT == (MCUXCLECC_SCALARMULT_OPTION_OUTPUT_MASK & options)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) )
        );
}
