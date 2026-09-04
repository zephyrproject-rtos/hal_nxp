/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_BlindedFixScalarMult.c
 * @brief Generic ECC implementation of multiplicatively blinded scalar multiplication with fixed base point
 */


#include <mcuxClSession.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_UPTRT_access.h>

#include <internal/mcuxClSession_Internal_EntryExit.h>


/**
 * This function implements the scalar multiplication k*G for a secret scalar k in {0,...,n-1}
 * and the base point G of order n on the given curve. If the scalar k is zero, the function
 * returns MCUXCLECC_INTSTATUS_SCALAR_ZERO. If it is not zero, the function generates a blinded
 * multiplicative splitting (phi,sigma) of the scalar k with a 64 bit blinding with MSBit set to 1
 * and sigma = k*phi^(-1) mod n, and performs two secure scalar multiplications,
 * the first with the blinded scalar sigma and the second with the blinding phi.
 *
 * Input:
 *  - pSession          Handle for the current CL session
 *  - pDomainParameters Pointer to common domain parameters
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK              if the function executed successfully
 *  - MCUXCLECC_INTSTATUS_SCALAR_ZERO  if the scalar is zero
 *  - MCUXCLECC_STATUS_FAULT_ATTACK    fault attack (unexpected behavior) is detected
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
 *  If MCUXCLECC_STATUS_OK is returned:
 *  - the result k*G is stored in curve dependent coordinates in buffers ECC_COORD00, ECC_COORD01,....
 *  - the blinding phi concatenated with the blinded scalar sigma in buffer ECC_S0 (considering buffer size operandSize + MCUXCLPKC_WORDSIZE)
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_BlindedFixScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_BlindedFixScalarMult(mcuxClSession_Handle_t pSession,
                                                                         mcuxClEcc_CommonDomainParams_t *pCommonDomainParams, uint32_t scalarLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_BlindedFixScalarMult);

    /*
     * Step 1: Securely generate a multiplicative decomposition (sigma,phi) of k with a 64 bit random phi
     *         with MSBit and LSBit set to 1 stored in ECC_S0 and sigma = phi^(-1)*k mod n stored in ECC_S1
     *         by calling function mcuxClEcc_GenerateMultiplicativeBlinding.
     */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_GenMulBlind,
        mcuxClEcc_GenerateMultiplicativeBlinding(pSession, scalarLength));
    if (MCUXCLECC_STATUS_OK != ret_GenMulBlind)
    {
        /* GenerateMultiplicativeBlinding is returning only OK or SCALAR_ZERO */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_BlindedFixScalarMult, ret_GenMulBlind,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateMultiplicativeBlinding));
    }

    /*
     * Step 2: Call pDomainParameters->pSecFixScalarMultFct to securely calculate the scalar multiplication sigma*G
     *         and store the result P' in curve dependent coordinates in MR in buffers ECC_COORD00, ECC_COORD01,....
     */
    /* Copy of blinded scalar sigma = phi^-1*k to ECC_V0, which points to &pS0[MCUXCLPKC_WORDSIZE]*/
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_V0, ECC_S1, 0u);

    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();
    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUX_CSSL_FP_FUNCTION_CALL(leadingZerosN, mcuxClMath_LeadingZeros(ECC_N));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The result does not wrap. The leadingZerosN is less than operandSize * 8u.")
    uint32_t bitLenN = (operandSize * 8u) - leadingZerosN;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_DI_RECORD(secureFixScalarMult, MCUXCLECC_SCALARMULT_OPTION_SECURE * bitLenN);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        pCommonDomainParams->pScalarMultFunctions->secFixScalarMultFct(
            pSession,
            pCommonDomainParams,
            ECC_S1,
            bitLenN,
            MCUXCLECC_SCALARMULT_OPTION_AFFINE_INPUT |
            MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_OUTPUT |
            MCUXCLECC_SCALARMULT_OPTION_NO_OUTPUT_VALIDATION));

    /*
     * Step 3: Call pDomainParameters->pSecVarScalarMultFct to securely calculate the scalar multiplication phi*P',
     *         store the result P in curve dependent coordinates in MR in buffers ECC_COORD00, ECC_COORD01,...,
     *         and verify that the point lies on the curve.
     */
    MCUX_CSSL_DI_RECORD(secureVarScalarMult, MCUXCLECC_SCALARMULT_OPTION_SECURE * MCUXCLECC_SCALARBLINDING_BITSIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        pCommonDomainParams->pScalarMultFunctions->secVarScalarMultFct(
            pSession,
            pCommonDomainParams,
            ECC_S0,
            MCUXCLECC_SCALARBLINDING_BITSIZE,
            MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_INPUT |
            MCUXCLECC_SCALARMULT_OPTION_AFFINE_OUTPUT |
            MCUXCLECC_SCALARMULT_OPTION_OUTPUT_VALIDATION));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_BlindedFixScalarMult, MCUXCLECC_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateMultiplicativeBlinding),
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
        pCommonDomainParams->pScalarMultFunctions->secFixScalarMultFctFPId,
        pCommonDomainParams->pScalarMultFunctions->secVarScalarMultFctFPId);
}
