/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Mont_Internal_MontDhX.c
 * @brief implementation of MontDhX functions
 */


#include <stdint.h>

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClMemory.h>
#include <mcuxClRandom.h>
#include <mcuxClSession.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClPrng_Internal_Functions.h>

#include <internal/mcuxClEcc_Mont_Internal.h>
#include <internal/mcuxClEcc_Mont_Internal_FUP.h>


/**
 * \brief This function decodes an encoded Curve25519 or Curve448 scalar kEnc.
 *
 * Data Integrity: Expunge(c + t)
 *
 * Input:
 *  - c: cofactor exponent (3 for Curve25519 and 2 for Curve448)
 *  - t: bit position of MSBit of decoded scalar (254 for Curve25519 and 447 for Curve448)
 *
 * Prerequisites:
 *  - the encoded secret scalar kEnc is contained in buffer ECC_S3;
 *  - ps1Len = (operandSize, operandSize).
 *
 * Result:
 *  - the cofactorless decoded secret scalar k'=k/h is contained in buffer ECC_S2
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_MontDH_DecodeScalar)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_DecodeScalar(
    uint16_t c,
    uint16_t t
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_MontDH_DecodeScalar);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

    /* Prepare random mask for scalar decode */
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T2]), operandSize));

    pOperands[MONT_V0] = c;                   /* c is smaller than 2^16 for Curve25519 and Curve448, Clear c LSbits by right shift */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA("The value is used for shifting with the PKC which actually shifts by (c-t) mod PKCWordBitLen, so the casting here doesn't cause any issues.")
    pOperands[MONT_V1] = (uint16_t) (c - t);  /* Clear bit t ~ MSbits by left shift. PKC will left shift (c - t mod PKCWordBitLen) bits */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA()

    /* MISRA Ex. 22, while(0) is allowed */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_MontDhDecodeScalar,
                        mcuxClEcc_FUP_MontDhDecodeScalar_LEN);

    /* SREQI_MONTDH_7 - DI protect shifting amounts for scalar decoding */
    MCUXCLPKC_WAITFORFINISH();
    uint16_t readBackC = (uint16_t)pOperands[MONT_V0];
    uint16_t readBackCT = (uint16_t)pOperands[MONT_V1];
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA("With the original values everything fits, in all other cases a failing DI check is expected")
    uint16_t readBackT = readBackC - readBackCT;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA()
    MCUX_CSSL_DI_EXPUNGE(shiftAmount, (uint32_t)readBackC);
    MCUX_CSSL_DI_EXPUNGE(shiftAmount, (uint32_t)readBackT);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_MontDH_DecodeScalar,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
}


/**
 * \brief This function imports, decodes and randomizes an encoded Curve25519 or Curve448
 * x-coordinate uEnc.
 *
 * Inputs:
 *  - pDomainParameters: pointer to domain parameter structure passed via API;
 *  - pCoordinateEnc: pointer to encoded x-coordinate.
 *
 * Prerequisite:
 *  - ps1Len = (operandSize, operandSize).
 *
 * Result:
 *  - MONT_Z0 is in range [1, (p+1)/2]
 *  - the decoded and randomized x-coordinate u is contained in buffer MONT_X0 in MR.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_MontDH_DecodeCoordinate)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_DecodeCoordinate(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    mcuxClEcc_MontDH_DomainParams_t *pDomainParameters,
    const uint8_t *pCoordinateEnc)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_MontDH_DecodeCoordinate);

    /* Generate a random Z in range [1, (p+1)/2] */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_GenerateRandomModModulus(pSession, ECC_P, MONT_Z0));

    /* Import encoded x-coordinate uEnc. */
    uint32_t byteLenP = (uint32_t) pDomainParameters->common.byteLenP;
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(ECC_T0, pCoordinateEnc, byteLenP, operandSize);

    /*
     * If leadingZerosP != 0 (X25519), mask MSByte according to rfc7748, Ch5.
     * Then randomize the x-coordinate with random Z
     */
    MCUX_CSSL_FP_FUNCTION_CALL(leadingZerosP, mcuxClMath_LeadingZeros(ECC_P));
    MCUX_CSSL_DI_RECORD(shiftAmount, leadingZerosP);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    pOperands[MONT_V0] = (uint16_t)(leadingZerosP & 0xFFFFu);
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_MontDhX_DecodeAndRandomizeX,
                        mcuxClEcc_FUP_MontDhX_DecodeAndRandomizeX_LEN);
    MCUX_CSSL_DI_EXPUNGE(shiftAmount, (uint32_t)pOperands[MONT_V0]);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_MontDH_DecodeCoordinate,
                                   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateRandomModModulus),
                                   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportLittleEndianToPkc),
                                   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
                                   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
}

/**
 * \brief This function implements the X25519 and X448 functions specified
 * in rfc7748, depending on the used curve, which basically performs
 * a secure x-only scalar multiplication of an encoded scalar kEnc and
 * an encoded x-coordinate uEnc and returns the encoded resulting x-coordinate
 * as MontDhX(kEnc, uEnc). Here, the encoding of scalars and x-coordinates
 * are following the specification in rfc7748.
 *
 * Data Integrity: Expunge(c + t), due to the call to mcuxClEcc_MontDH_DecodeScalar
 *
 * Inputs:
 *  - pSession: pointer to mcuxClSession_Descriptor.
 *  - pDomainParameters: pointer to domain parameter structure passed via API;
 *  - pCoordinateUEnc: pointer to encoded x-coordinate uEnc.
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK: if the function executed successfully;
 *  - MCUXCLECC_STATUS_NEUTRAL_POINT: if the resulting point is zero;
 *  - MCUXCLECC_INTSTATUS_SCALAR_ZERO: if the scalar is zero.
 *
 * Prerequisite:
 *  - the encoded secret scalar kEnc is contained in buffer ECC_S3.
 *
 * Result:
 *  - if MCUXCLECC_STATUS_OK is returned, then the result MontDhX(kEnc, uEnc)
 *    is stored in buffer MONT_X0 (in NR, in the range [0, p-1]);
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_MontDH_X)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_MontDH_X(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_MontDH_DomainParams_t *pDomainParameters,
    const uint8_t *pCoordinateUEnc)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_MontDH_X);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_RandomizeUPTRT(&pOperands[MONT_X1],
                                                        (MONT_Z2 - MONT_X1 + 1u)) );

    /* Decode the scalar kEnc and obtain ECC_S2 = k' = k/h. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_MontDH_DecodeScalar(pDomainParameters->c, pDomainParameters->t));

    /* Generate multiplicative scalar splitting k' = phi*sigma mod n and store (phi, sigma) in (ECC_S1, ECC_S0). */
    MCUX_CSSL_FP_FUNCTION_CALL(retGenMulBlind,
        mcuxClEcc_GenerateMultiplicativeBlinding(pSession, pDomainParameters->common.byteLenN));
    if (MCUXCLECC_STATUS_OK != retGenMulBlind)
    {
        /* GenerateMultiplicativeBlinding is returning only OK or SCALAR_ZERO */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_MontDH_X, retGenMulBlind,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_DecodeScalar),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateMultiplicativeBlinding));

    }

    /* Generate a random Z-coordinate Z0, and decode and randomize the x-coordinate uEnc to obtain X0 = u * Z0 in MR. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_MontDH_DecodeCoordinate(pSession, pDomainParameters, pCoordinateUEnc));

    /* Securely calculate, R' = sigma * (u, 1), stored result in buffers (X0, Z0). */
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
    MCUX_CSSL_FP_FUNCTION_CALL(leadingZerosN, mcuxClMath_LeadingZeros(ECC_N));
    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The result does not wrap. The leadingZerosN is less than operandSize * 8u.")
    uint32_t bitLenN = (operandSize * 8u) - leadingZerosN;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder(
      pSession,
      ECC_S1,
      bitLenN,
      MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_INPUT
    ));

    /* Securely calculate, R'' = phi * R', stored result in buffers (X0, Z0). */
    /* Secure multiplication is not needed here, but we do not have non secure one */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder(
      pSession,
      ECC_S0,
      MCUXCLECC_SCALARBLINDING_BITSIZE,
      MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_INPUT
    ));

    /* Copy cofactor to the buffer ECC_S0 overwriting phi */
    MCUXCLPKC_FP_CALC_OP1_CONST(ECC_S0, 0u);
    uint8_t *pS0 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S0]);
    MCUXCLPKC_WAITFORFINISH();
    *(pS0) = (uint8_t)((1u << pDomainParameters->c) & 0xFFu);
    /* Securely calculate, R = cofactor * R'', stored result in buffers (X0, Z0). */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder(
      pSession,
      ECC_S0,
      (uint32_t)(pDomainParameters->c) + 1u,
      MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_INPUT
    ));

    MCUXCLPKC_FP_CALC_MC1_MR(ECC_T0, MONT_Z0, ECC_P);        /* T0 = Z in NR, in range [0, p] */
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T0, ECC_T0, ECC_P, ECC_P);  /* T0 = Z in NR, in range [0, p-1] */

    /* Check against NEUTRAL_POINT. */
    uint32_t zeroFlag = MCUXCLPKC_WAITFORFINISH_GETZERO();
    if (MCUXCLPKC_FLAG_ZERO == zeroFlag)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_MontDH_X, MCUXCLECC_STATUS_NEUTRAL_POINT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_DecodeScalar),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateMultiplicativeBlinding),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_DecodeCoordinate),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder),
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder),
            MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS );
    }

    /* Calculate T1 = Z^(-1) in NR. */
    MCUXCLECC_FP_MODINV(pSession, ECC_T1, ECC_T0, ECC_P, MONT_Z0, ECC_T2);
    /* Clear bytes using on top of buffer ECC_T2 which is used below to store a random additive blinding rnd */
    uint8_t *pT2 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T2]);
    uint32_t pByteLen = pDomainParameters->common.byteLenP;
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, &pT2[pByteLen]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, operandSize - pByteLen);
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The result does not wrap. The pByteLen(byte length of prime p) is less than operandSize.")
    MCUXCLMEMORY_CLEAR_INT(&pT2[pByteLen], operandSize - pByteLen);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    /* Generate additive random blinding rnd of size lenP bytes in buffer ECC_T2. rnd is assumed to be generated directly in MR */
    MCUXCLBUFFER_INIT(buffT2, NULL, pT2, pByteLen);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_PRNG_GetRandom_rnd, mcuxClRandom_ncGenerate(pSession, buffT2, pByteLen));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret_PRNG_GetRandom_rnd);

    /* Calculate X0 = X * Z^(-1) in NR. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_MontDhX_CalcAffineX,
                        mcuxClEcc_FUP_MontDhX_CalcAffineX_LEN);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_MontDH_X, MCUXCLECC_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_DecodeScalar),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateMultiplicativeBlinding),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_DecodeCoordinate),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder),
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup) );
}
