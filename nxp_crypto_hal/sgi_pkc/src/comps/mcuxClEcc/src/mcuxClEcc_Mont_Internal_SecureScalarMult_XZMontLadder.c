/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Mont_Internal_SecureScalarMult_XZMontLadder.c
 * @brief mcuxClEcc: implementation of ECC internal secure scalar multiplication function montgomery ladder based
 */


#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Mont_Internal.h>
#include <internal/mcuxClEcc_Mont_Internal_FUP.h>
#include <internal/mcuxClPrng_Internal.h>


/**
 * This function implements secure point scalar multiplication, R = scalar * P, based on XZ coordinates Montgomery ladder.
 *
 * Inputs:
 *   iScalar: index of PKC buffer storing the scalar, which is non-zero and in little-endian;
 *   scalarBitLength: bit length of scalar.
 *   optionAffineOrProjective: unused.
 *
 *
 * Prerequisites:
 *   Buffers MONT_X0 and MONT_Z0 contain X and Z in MR
 *   buffer buf(iScalar) contains the secret scalar lambda of bit length scalarBitLength
 *   buffer ECC_CP0 contains the ladder constant A24=(A+2)/4 mod p in MR
 *   ps1Len = (operandSize, operandSize)
 *   Buffer ECC_PFULL contains p'||p
 *   Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result in PKC workarea:
 *   buffers MONT_X0 and MONT_Z0 contain Xres and Zres in MR
 *   pOperands[X1/Z1/X2/Z2] and location of corresponding buffers are randomized.
 *
 * Other modifications:
 *   buffers ECC_T0, ECC_T1, ECC_T2, ECC_T3, MONT_X1, MONT_X2, MONT_Z1, MONT_Z2 modified
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Mont_SecureScalarMult_XZMontLadder(mcuxClSession_Handle_t pSession, uint8_t iScalar, uint32_t scalarBitLength, uint32_t optionAffineOrProjective UNUSED_PARAM)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder);

    /* Determine pointer table pointer */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy - TODO CLNS-6410: check if this is necessary
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 to Rule 11.3 - PKC word is CPU word aligned.")
    const uint32_t *pScalar = (const uint32_t *) MCUXCLPKC_OFFSET2PTR(pOperands[iScalar]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Initialize accumulated coordinate buffers MONT_X1/MONT_Z1/MONT_X2/MONT_Z2 for the ladder iteration
     */
    MCUXCLPKC_FP_CALC_OP1_NEG(MONT_X1, ECC_P); /* 1 in MR */
    MCUXCLPKC_FP_CALC_OP1_CONST(MONT_Z1, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(MONT_X2, MONT_X0, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(MONT_Z2, MONT_Z0, 0u);

    /* Generate a random in [1,p-1] in ECC_T0 and use it to randomize accumulated point coordinates MONT_X1/MONT_Z1/MONT_X2/MONT_Z2 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_GenerateRandomModModulus(pSession, ECC_P, ECC_T0));

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords,
                        mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords_LEN);

    /* Perform ladder iteration to calculate (X_res:Z_res) */
    uint32_t i = scalarBitLength;
    uint32_t maskedCurrentScalarWord = 0u;
    MCUX_CSSL_FP_LOOP_DECL(whileLoop);
    MCUX_CSSL_FP_BRANCH_DECL(ifInWhile);
    MCUX_CSSL_FP_BRANCH_DECL(ifInWhile2);

    uint32_t currentScalarWordMask = MCUXCLECC_RANDOM_WORD;

    while(0u < i)
    {

        /* Update loop counter, deviation from the design to let iterate over unsigned value */
        --i;
        if((i % MCUXCLECC_MONTDH_RERANDOMIZED_ITERATION_INTERVAL) == 0u)
        {
            /* Randomize buffers MONT_X1/MONT_Z1/MONT_X2/MONT_Z2. */
            /* (pkcwa order is changed accordingly)            */
            MCUXCLPKC_WAITFORFINISH();
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_ReRandomizeUPTRT(&pOperands[MONT_X1],
                                                              (uint16_t) operandSize,
                                                              (MONT_Z2 - MONT_X1 + 1u)) );

            /* Generate a random in [1,p-1] in ECC_T0 and use it to randomize accumulated point coordinates MONT_X1/MONT_Z1/MONT_X2/MONT_Z2 */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_GenerateRandomModModulus(pSession, ECC_P, ECC_T0));

            MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords,
                                mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords_LEN);

            MCUX_CSSL_FP_BRANCH_POSITIVE(ifInWhile2, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ReRandomizeUPTRT),
                                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateRandomModModulus),
                                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
        }

        /* Set pointers pOperands(MONT_VX1),...,pOperands(MONT_VZ2) according to the bit to be processed */
        MCUXCLPKC_WAITFORFINISH();
        uint32_t currentScalarBitInWord = i % 32u;

        if((i == (scalarBitLength - 1u)) || ((i % 32u) == 31u))
        {
            MCUX_CSSL_FP_FUNCTION_CALL(prngGenerateWordRet, mcuxClPrng_generate_word());
            MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy

            currentScalarWordMask = prngGenerateWordRet;
            uint32_t currentScalarWordIndex = i / 32u;
            maskedCurrentScalarWord = pScalar[currentScalarWordIndex] ^ currentScalarWordMask;
            MCUX_CSSL_FP_BRANCH_POSITIVE(ifInWhile, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word));
        }

        /* When bit of scalar = 0, the function returns:   */
        /*   pOperands[MONT_VX1] = pOperands[MONT_X1],     */
        /*   pOperands[MONT_VZ1] = pOperands[MONT_Z1],     */
        /*   pOperands[MONT_VX2] = pOperands[MONT_X2],     */
        /*   pOperands[MONT_VZ2] = pOperands[MONT_Z2];     */
        /* when bit = 1,                                   */
        /*   pOperands[MONT_VX1] = pOperands[MONT_X2],     */
        /*   pOperands[MONT_VZ1] = pOperands[MONT_Z2],     */
        /*   pOperands[MONT_VX2] = pOperands[MONT_X1],     */
        /*   pOperands[MONT_VZ2] = pOperands[MONT_Z1].     */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_SecurePointSelectML(maskedCurrentScalarWord, currentScalarWordMask, currentScalarBitInWord, MONT_X1, MONT_VX1));

        /* Perform the ladder step to calculate (MONT_VX1,MONT_VZ1) = 2 * (MONT_VX1,MONT_VZ1) and (MONT_VX2, MONT_VZ2) = (MONT_VX1,MONT_VZ1) + (MONT_VX2,MONT_VZ2)*/

        /* FP balancing at the end of loop iteration end as both cases are calling same function */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep,
                            mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep_Projective_LEN);

        MCUX_CSSL_FP_LOOP_ITERATION(whileLoop,
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(ifInWhile2, ((i % MCUXCLECC_MONTDH_RERANDOMIZED_ITERATION_INTERVAL) == 0u)),
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(ifInWhile, (i == (scalarBitLength - 1u)) || ((i % 32u) == 31u)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointSelectML),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
            );
    }

    /* Copy resulting coordinates to buffers MONT_X0 and MONT_Z0 */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(MONT_X0, MONT_X1, 0u);           /* MONT_X0 = MONT_X1 */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(MONT_Z0, MONT_Z1, 0u);           /* MONT_Z0 = MONT_Z1 */

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder,
                    MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,
                    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
                    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateRandomModModulus),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
                    MCUX_CSSL_FP_LOOP_ITERATIONS(whileLoop, scalarBitLength),
                    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
                    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST
                    );
}
