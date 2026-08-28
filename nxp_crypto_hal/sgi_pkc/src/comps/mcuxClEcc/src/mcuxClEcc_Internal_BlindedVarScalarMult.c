/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_BlindedVarScalarMult.c
 * @brief Generic ECC implementation of multiplicatively blinded scalar multiplication with variable input point
 */


#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>
#include <internal/mcuxClMemory_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_Random.h>
#include <internal/mcuxClEcc_Internal_UPTRT_access.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>

#include <internal/mcuxClSession_Internal_EntryExit.h>

/**
 * This function implements the scalar multiplication k*P for a secret scalar k in {0,...,n-1}
 * and a variable input point of order n on the given curve. If the scalar k is zero, the function
 * returns MCUXCLECC_INTSTATUS_SCALAR_ZERO. If it is not zero, the function generates a blinded
 * multiplicative splitting of the scalar k and performs two secure scalar multiplications,
 * the first with the blinded scalar and the second with the blinding.
 *
 * Input:
 *  - pSession          Handle for the current CL session
 *  - pDomainParameters Pointer to common domain parameters
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK              if the function executed successfully
 *  - MCUXCLECC_INTSTATUS_SCALAR_ZERO  if the scalar is zero
 *
 * Prerequisites:
 *  - The secret scalar k is contained in buffer ECC_S2
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers ECC_CP0 and ECC_CP1 contain the curve parameters a and d in MR
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_NFULL contains n'||n
 *  - Buffers ECC_PS and ECC_NS contain the shifted moduli associated to p and n
 *
 * Result:
 *  - If MCUXCLECC_STATUS_OK is returned, the result k*G is stored in curve dependent coordinates in buffers ECC_COORD04, ECC_COORD05,....
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_BlindedVarScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_BlindedVarScalarMult(mcuxClSession_Handle_t pSession,
                                                                            mcuxClEcc_CommonDomainParams_t *pCommonDomainParams)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_BlindedVarScalarMult);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint32_t byteLenN = pCommonDomainParams->byteLenN;
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;

    /**********************************************************/
    /* Generate multiplicative scalar splitting               */
    /* d = d0 * d1 mod n, where d0 is a 64-bit odd number.    */
    /**********************************************************/

    /* Generate 64-bit random number d0 in buffer S0 of size = operandSize. */
    MCUXCLPKC_FP_CALC_OP1_CONST(ECC_S0, 0u);
    MCUXCLPKC_FP_CALC_OP1_CONST(ECC_S3, 0u);
    {
        uint8_t * const ptrS0 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S0]);
        MCUXCLBUFFER_INIT(buffS0, NULL, ptrS0, 8u);
        MCUXCLPKC_WAITFORFINISH();
        MCUX_CSSL_FP_FUNCTION_CALL(ret_PRNG_randWord1, mcuxClRandom_ncGenerate(pSession, buffS0, 8u));
        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret_PRNG_randWord1);
    }  /* buffS0 scope. */

    /* Set MSBit of d0 (to ensure d0 != 0) using the PKC
     *
     * NOTE: PKC PS1 can be used, because operandSize >= 64.*/
    uint32_t *ptr32S3 = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S3]);
    ptr32S3[0u] = 0x00000000u;
    ptr32S3[1u] = 0x80000000u;
    MCUXCLPKC_FP_CALC_OP1_OR(ECC_S0, ECC_S0, ECC_S3);

    /* Prepare NQSQR for upcoming FUP program*/
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA("the result of operandSize + bufferSize is in range of uint16")
    MCUXCLMATH_FP_QDASH(pSession, ECC_NQSQR, ECC_NS, ECC_N, ECC_T0, (uint16_t) (operandSize + bufferSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA()

    /* T0 = ModInv(d0), with temp T1. */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_S1, ECC_S0, 0u);
    MCUXCLECC_FP_MODINV(pSession, ECC_T0, ECC_S1, ECC_N, ECC_T1, ECC_S3);

    /* Generate buffer size random number d' in buffer S3. */
    {
        uint8_t * const ptrS3 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);
        MCUXCLBUFFER_INIT(buffS3, NULL, ptrS3, bufferSize);
        MCUXCLPKC_WAITFORFINISH();
        MCUX_CSSL_FP_FUNCTION_CALL(ret_PRNG_GetRandom, mcuxClRandom_ncGenerate(pSession, buffS3, bufferSize));
        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret_PRNG_GetRandom);
    }  /* buffS3 scope. */

    /* Clear PKC word on top of the secret scalar, i.e. the most significant PKC word of buffer ECC_S2,
     * to clear garbage before below additive blinding. */
    uint8_t * const ptrS2 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, (uint32_t) &ptrS2[operandSize] + MCUXCLPKC_WORDSIZE);
    MCUXCLMEMORY_CLEAR_INT(&ptrS2[operandSize], MCUXCLPKC_WORDSIZE);

    /* Set PS1 lengths for upcoming computation of d'' which consider operands of size bufferSize. */
    MCUXCLPKC_PS1_SETLENGTH(0u, bufferSize);

    /* Set d' = d' >> 1 to avoid a carry in the following addition operation */
    MCUXCLPKC_FP_CALC_OP1_SHR(ECC_S1, ECC_S3, 1u);

    /* S3 = d" = d + d' */
    MCUXCLPKC_FP_CALC_OP1_ADD(ECC_S3, ECC_S2, ECC_S1);

    /* Prepare PS1 and PS2 lengths for upcoming FUP program (this restores PS1 lengths to default) */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);
    MCUXCLPKC_PS2_SETLENGTH(bufferSize, operandSize);

    /* Split scalar d = d0 * d1, and convert coordinates of P to Montgomery representation. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_PointMult_SplitScalar_ConvertPoint2MR,
                        mcuxClEcc_FUP_Weier_PointMult_SplitScalar_ConvertPoint2MR_LEN);

    /* Check if d is zero. */
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_BlindedVarScalarMult, MCUXCLECC_INTSTATUS_SCALAR_ZERO,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QDash),
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
            MCUXCLPKC_FP_CALLED_CALC_OP1_ADD,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
    }


    /**********************************************************/
    /* Calculate scalar multiplications Q = d1 * (d0 * P)     */
    /**********************************************************/

    /* P has been converted to MR, and Z has been initialized to 1 (in MR). */
    /* P will be randomized (projective coordinate randomization) in SecurePointMult. */

    /* Calculate Q0 = d0 * P. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_SecurePointMult(ECC_S0, 64u));

    /* In case d1 is even, perform scalar multiplication d1 * Q0 by computing (n-d1) * (-Q0) as this avoids the exceptional case d1 = n-1 */
    MCUX_CSSL_FP_BRANCH_DECL(scalarEvenBranch);
    MCUXCLPKC_FP_CALC_OP1_LSB0s(ECC_S1);
    uint32_t d1NoOfTrailingZeros = MCUXCLPKC_WAITFORFINISH_GETZERO();
    if(MCUXCLPKC_FLAG_NONZERO == d1NoOfTrailingZeros)
    {
        MCUXCLPKC_FP_CALC_OP1_SUB(ECC_S1, ECC_N, ECC_S1);
        MCUXCLPKC_FP_CALC_MC1_MS(WEIER_Y0, ECC_PS, WEIER_Y0, ECC_PS);

        MCUX_CSSL_FP_BRANCH_POSITIVE(scalarEvenBranch,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS );
    }

    /* Calculate Q = d1 * Q0. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_SecurePointMult(ECC_S1, byteLenN * 8u));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_BlindedVarScalarMult, MCUXCLECC_STATUS_OK,
        MCUXCLECC_FP_BLINDEDVARSCALARMULT_FINAL,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarEvenBranch, (MCUXCLPKC_FLAG_NONZERO == d1NoOfTrailingZeros)));
}
