/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Verify.c
 * @brief Weierstrass curve ECDSA signature verification API
 */


#include <stdint.h>
#include <stddef.h>

#include <mcuxClPkc.h>
#include <mcuxClMath.h>
#include <mcuxClSession.h>
#include <mcuxCsslMemory.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxClBuffer.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

/**
 * This function checks if an ECDSA signature (r,s) is in proper range, i.e. it satisfies 0 < r,s < n.
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK                 if the range check passed and the function executed successfully
 *  - MCUXCLECC_STATUS_INVALID_SIGNATURE  if the range check failed, i.e. the signature is invalid
 *
 * Prerequisites:
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_NFULL contains n'||n
 *  - The signature values r and s are stored in ECC_S3 and ECC_T1, respectively.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_SignatureRangeCheck)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Weier_SignatureRangeCheck(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_SignatureRangeCheck);

    /* If r < n, then ECC_T2 = r; otherwise ECC_T2 = r - n. */
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T2, ECC_S3, ECC_N, ECC_N);

    /* Check r != 0, r != n. */
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {   /* r = 0 or n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);
    }

    /* Check r < n. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S3, ECC_N);
    if (MCUXCLPKC_FLAG_CARRY != MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {   /* r > n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
    }

    /* If s < n, then ECC_T3 = s; otherwise ECC_T3 = s - n. */
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T3, ECC_T1, ECC_N, ECC_N);

    /* Check s != 0, s != n. */
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {   /* s = 0 or n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);
    }

    /* Check s < n. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T1, ECC_N);
    if (MCUXCLPKC_FLAG_CARRY != MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {   /* s > n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SignatureRangeCheck, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
}

/**
 * This function prepares message digest.
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK                 if the function executed successfully
 *
 * Prerequisites:
 *   ps1Len = (operandSize, operandSize);
 *   curve order n in N
 * Result in PKC workarea:
 * buffer S2 contains truncated message digest
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Verify_PrepareMessageDigest)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Verify_PrepareMessageDigest(
    const mcuxClEcc_Verify_Param_t * pParam,
    const uint32_t byteLenN
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Verify_PrepareMessageDigest);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    /* Import message hash (up to byteLenN bytes). */
    const uint32_t byteLenHash = (pParam->optLen & mcuxClEcc_Verify_Param_optLen_byteLenHash_mask) >> mcuxClEcc_Verify_Param_optLen_byteLenHash_offset;
    const uint32_t byteLenHashImport = MCUXCLCORE_MIN(byteLenHash, byteLenN);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Verify, ECC_S2, pParam->pHash, byteLenHashImport);

    /* Truncate message hash if its bit length is longer than that of n. */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(byteLenN, 1U, 1024U, MCUXCLECC_STATUS_FAULT_ATTACK)
    if (byteLenHash >= byteLenN)
    {
        /* Count leading zeros in MSByte of n. */
        const volatile uint8_t * ptrN = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
        uint8_t nMSByte = ptrN[byteLenN - 1u];
        uint32_t nMSByte_LeadZeros = (uint32_t) mcuxClMath_CountLeadingZerosWord((uint32_t) nMSByte) - (8u * ((sizeof(uint32_t)) - 1u));

        /* Only keep the first bitLenN bits of hash. */
        MCUXCLPKC_FP_CALC_OP1_SHR(ECC_S2, ECC_S2, (uint8_t) (nMSByte_LeadZeros & 0xFFu));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify_PrepareMessageDigest, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN), MCUXCLPKC_FP_CALLED_CALC_OP1_SHR));
}

/**
 * This function performs scalar multiplication with base point.
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK                 if the function executed successfully
 *  - MCUXCLECC_STATUS_INVALID_PARAMS     if the input point is invalid
 *  - MCUXCLECC_STATUS_FAULT_ATTACK       if fault attack (unexpected behavior) is detected
 *
 * Prerequisites:
 *    scalar in S0
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_PlainFixScalarMult)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Weier_PlainFixScalarMult(const mcuxClEcc_Verify_Param_t * pParam,
                                                                                                 const uint32_t byteLenP,
                                                                                                 const uint32_t byteLenN )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_PlainFixScalarMult);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint32_t *pOperands32 = MCUXCLPKC_GETUPTRT32();

    /* Import G to (X1,Y1). */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Weier_PlainFixScalarMult, WEIER_X1, pParam->curveParam.pG, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET(mcuxClEcc_Weier_PlainFixScalarMult, WEIER_Y1, pParam->curveParam.pG, byteLenP, byteLenP);
    /* Import PrecG to (X2, Y2). */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Weier_PlainFixScalarMult, WEIER_X2, pParam->pPrecG, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET(mcuxClEcc_Weier_PlainFixScalarMult, WEIER_Y2, pParam->pPrecG, byteLenP, byteLenP);

    /* Check G in (X1,Y1) affine NR. */
//      MCUXCLPKC_WAITFORREADY();  <== there is WaitForFinish in import function.
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X1, WEIER_Y1);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckBasePointStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckBasePointStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_PlainFixScalarMult, MCUXCLECC_STATUS_INVALID_PARAMS,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));
    }
    else if (MCUXCLECC_STATUS_OK != pointCheckBasePointStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_PlainFixScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    /* Check PrecG in (X2,Y2) affine NR. */
//      MCUXCLPKC_WAITFORREADY();  <== there is WaitForFinish in _PointCheckAffineNR.
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X2, WEIER_Y2);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckPrecPointStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckPrecPointStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_PlainFixScalarMult, MCUXCLECC_STATUS_INVALID_PARAMS,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));
    }
    else if (MCUXCLECC_STATUS_OK != pointCheckPrecPointStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_PlainFixScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    /* Convert coordinates of G and PrecG to MR.   */
    /* G:     (X1,Y1) affine NR -> (XA,YA, 1) Jacobian;     */
    /* PrecG: (X2,X2) affine NR -> (X3,Y3, Z=1) relative-z. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR,
                        mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR_LEN);

    /* Prepare 3 pre-computed points for G, with the same z coordinate. */
    /* The relative z-coordinate, z' is stored in Z, instead of ZA.     */
    /* Input: G     in (XA,YA, 1) Jacobian;                      */
    /*        PrecG in (X3,Y3, Z=1) relative-z.  (ps, not in ZA) */
    /* Output: Prec1 = G (unchanged)   in (XA,YA, 1) Jacobian;   */
    /*         Prec2 = PrecG (updated) in (X2,Y2, Z) relative-z; */
    /*         Prec3 = G + PrecG       in (X3,Y3, Z) relative-z. */
//      MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VT2/VT3/VX0/VY0/VZ0/VX1/VY1 are not used in the FUP program before.
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VT2, WEIER_VT3, WEIER_X2, WEIER_Y2);  /* output: Prec2 */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X3, WEIER_Y3);  /* input: PrecG; output: Prec3 */
    pOperands[WEIER_VZ0] = pOperands[WEIER_Z];                                      /* input: z';    output: z' */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX1, WEIER_VY1, WEIER_XA, WEIER_YA);  /* input: G */
    MCUXCLECC_FP_CALCFUP_ADD_ONLY();
    /* Hint: since z' (@ Z) = 1, the initial part of double-add FUP program (4 mul) can be skipped, */
    /*       by manually copying G in (XA,YA) to (X2,Y2), which needs extra code size.              */

    /* Update z = z * z' = z' (skipped because z=1, and z' has been stored in Z). */
    /* Update Prec1: (XA,YA, 1) -> (X1,Y1, Z) Jacobian. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_Update_G_to_Prec1,
                        mcuxClEcc_Fup_Verify_Update_G_to_Prec1_LEN);

    /* Calculate P1 = u1 * G. */
    /* Input: 3 Prec_i, in (Xi,Yi, Z) Jacobian.        */
    /* Output: P1 in (XA,YA, ZA) relative-z, w.r.t. Z. */
//      MCUXCLPKC_WAITFORREADY();  <==unnecessary, because VT is not used in the FUP program before.
    pOperands[WEIER_VT] = pOperands[ECC_S2];  /* Use S2 as 5th temp. */

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Int_PointMult(ECC_S0, byteLenN * 8u));

    /* Update z = z * z', so P1: (XA,YA, ZA) relative-z -> (XA,YA, Z) Jacobian. */
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_T0, WEIER_Z, WEIER_ZA, ECC_P);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_Z, ECC_T0, 0u);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_PlainFixScalarMult, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_PointMult),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST);
}

/**
 * This function imports public point and checks if it lays on curve y^2 == x^3 + a*x + b (mod p).
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK                 if the function executed successfully
 *  - MCUXCLECC_STATUS_INVALID_PARAMS     if the input point is invalid
 *  - MCUXCLECC_STATUS_FAULT_ATTACK       if fault attack (unexpected behavior) is detected
 * 
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey(
                                                        const mcuxClEcc_Verify_Param_t * pParam,
                                                        const uint32_t byteLenP,
                                                        const uint32_t byteLenN,
                                                        const uint32_t checkHashZero)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey);

    uint32_t *pOperands32 = MCUXCLPKC_GETUPTRT32();

    /* Reset z' = 1 in MR (or initialize z' if u1 == 0). */
    MCUXCLPKC_FP_CALC_OP1_NEG(WEIER_ZA, ECC_P);

    /* Import public key Q to (X1,Y1) affine NR. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC(WEIER_X1, pParam->pPublicKey, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC(WEIER_Y1, pParam->pPublicKey + byteLenP, byteLenP);

    /* Check Q in (X1,Y1) affine NR. */
    //  MCUXCLPKC_WAITFORREADY();  <== there is WaitForFinish in import function.
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X1, WEIER_Y1);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckPubKeyStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckPubKeyStatus)
    {

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey, MCUXCLECC_STATUS_INVALID_PARAMS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));
    }
    else if (MCUXCLECC_STATUS_OK != pointCheckPubKeyStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));
}

/**
 * This function calculates R = P1 + u2 * Q where P1 = u1 * G computed in previous step.
 * This calculation is a last step needed to recover signature component r which can be derived
 * from x coordinate of calculated R.
 * 
 * Return values:
 *  - MCUXCLECC_STATUS_OK                 if the function executed successfully
 *  - MCUXCLECC_STATUS_INVALID_PARAMS     if the input point is invalid
 *  - MCUXCLECC_STATUS_FAULT_ATTACK       if fault attack (unexpected behavior) is detected
 *
 * Prerequisites:
 * Public point Q in (X0,Y0)
 * Calculated P1 in (XA,YA)
 * Calculated u2 in S1
 * 
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_VerifySignature_PointAddMult)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_VerifySignature_PointAddMult(
                                                        const mcuxClEcc_Verify_Param_t * pParam,
                                                        const uint32_t byteLenN,
                                                        const uint32_t checkHashZero)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_VerifySignature_PointAddMult);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint32_t *pOperands32 = MCUXCLPKC_GETUPTRT32();

    /* Convert Q: (X1,Y1) affine NR -> (X0,Y0, Z) Jacobian. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR,
                        mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR_LEN);

    /* Calculate PrecQ = (2^(byteLenN *4)) * Q. */
    /* Input: Q in (X0,Y0, ZA=1) relative-z.    */
    /* Output: PrecQ in (X3,Y3, ZA) relative-z. */
    //  MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VX0/VY0/VZ0/VZ/VX2/VY2/VZ2 are not used in the FUP program before.
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X3, WEIER_Y3);  /* output: PrecQ */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VZ0, WEIER_VZ,  WEIER_ZA, WEIER_Z);   /* input: z, z'; output z' */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX2, WEIER_VY2, WEIER_X0, WEIER_Y0);  /* input: Q */
    pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];
    pOperands[WEIER_VT] = pOperands[ECC_S2];  /* Use S2 as 5th temp. */

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_RepeatPointDouble((byteLenN * 8u) / 2u));

    /* Prepare 3 pre-computed points for Q, with the same z coordinate. */
    /* Input: Q     in (X0, Y0, Z) Jacobian;                       */
    /*        PrecQ in (X3, Y3, ZA) relative-z.                    */
    /* Output: Prec1 = Q (unchanged)   in (X0, Y0, Z) Jacobian;    */
    /*         Prec2 = PrecQ (updated) in (X2, Y2, ZA) relative-z; */
    /*         Prec3 = Q + PrecQ       in (X3, Y3, ZA) relative-z. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VT2, WEIER_VT3, WEIER_X2, WEIER_Y2);  /* output: Prec2 */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X3, WEIER_Y3);  /* input: PrecQ; output: Prec3 */
    pOperands[WEIER_VZ0] = pOperands[WEIER_ZA];                                     /* input/output: z' */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX1, WEIER_VY1, WEIER_X0, WEIER_Y0);  /* input: Q */
    MCUXCLECC_FP_CALCFUP_ADD_ONLY();

    /* Update Q:  (X0,Y0, old Z) -> (X1,Y1, new Z) Jacobian; */
    /*        P1: (XA,YA, old Z) -> (X0,Y0, new Z) Jacobian. */
    /* Update z = z * z'. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_Update_pubkeyQ_P1_z,
                        mcuxClEcc_Fup_Verify_Update_pubkeyQ_P1_z_LEN);

    /* Calculate P2 = u2 * Q. */
    /* Input: 3 Prec_i, in (Xi,Yi, Z) Jacobian.        */
    /* Output: P2 in (XA,YA, ZA) relative-z, w.r.t. Z. */
    //  pOperands[WEIER_VT] = pOperands[ECC_S2];  <== the 5th temp WEIER_VT has been set before calling _RepeatPointDouble.

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Int_PointMult(ECC_S1, byteLenN * 8u));

    /**********************************************************/
    /* Calculate (x1, y1) = P1 + P2, and check the result     */
    /**********************************************************/

    /* Calculate P2 += P1, if u1 != 0. */
    if (MCUXCLPKC_FLAG_ZERO != checkHashZero)
    {
        /* Input: P1 in (X0,Y0, Z) Jacobian;          */
        /*        P2 in (XA,YA, ZA) relative-z.       */
        /* Output: P1 + P2 in (XA,YA, ZA) relative-z. */
        MCUXCLPKC_WAITFORREADY();
        MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_XA, WEIER_YA);  /* input: P2; output P1 + P2 */
        MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VZ0, WEIER_VZ, WEIER_ZA, WEIER_Z);    /* input: z' and z; output z' */
        MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX1, WEIER_VY1, WEIER_X0, WEIER_Y0);  /* input: P1 */
        MCUX_CSSL_FP_FUNCTION_CALL(statusPointFullAdd, mcuxClEcc_PointFullAdd());
        if (MCUXCLECC_STATUS_NEUTRAL_POINT == statusPointFullAdd)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_PointAddMult, MCUXCLECC_STATUS_INVALID_SIGNATURE,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_RepeatPointDouble),
                MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_PointMult),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd));
        }
    }

    /* Convert P1 + P2 (or P2 if u1 == 0) to (X0,Y0), affine NR. */
    /* Calculate R = x mod n, in X1. */
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_T0, WEIER_Z, WEIER_ZA, ECC_P);  // t0 = z*z' * 256^LEN         = z*z' in MR
    MCUXCLMATH_FP_MODINV(ECC_T1, ECC_T0, ECC_P, ECC_T2);     // t1 = (z*z')^(-1) * 256^(-LEN), use T2 as temp
    /* MISRA Ex. 22, while(0) is allowed */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR,
                        mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR_LEN);

    /* Check if P1 + P2 is valid. */
    //  MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VX0/VY0 are not used in the FUP program before.
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X0, WEIER_Y0);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_STATUS_OK != pointCheckStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_PointAddMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_PointAddMult, MCUXCLECC_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_RepeatPointDouble),
        MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_PointMult),
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLPKC_FLAG_ZERO != checkHashZero),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd)),

        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));
}


/**
 * This function checks if imported signature R is equal to the calculated R.
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK                 if the function executed successfully and signature
 *                                       compontents R match
 *  - MCUXCLECC_STATUS_INVALID_SIGNATURE  if calculated R is not equal to imported R
 *  - MCUXCLECC_STATUS_FAULT_ATTACK       if fault attack (unexpected behavior) is detected
 *
 * Prerequisites:
 *    R in S3
 *    calculated R in WEIER_X1
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_VerifySignature_CheckR)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_VerifySignature_CheckR(const mcuxClEcc_Verify_Param_t * pParam,
                                                        const uint32_t byteLenP,
                                                        const uint32_t byteLenN,
                                                        const uint32_t checkHashZero)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_VerifySignature_CheckR);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

    /* Check if imported signature R is equal to the calculated R. */
    MCUXCLPKC_FP_CALC_OP1_CMP(WEIER_X1, ECC_S3);
    if (MCUXCLPKC_FLAG_ZERO != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_CheckR, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
    }

    /* Import prime p and order n again, and check (compare with) existing one. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_ECDSA_VerifySignature_CheckR, ECC_T0, pParam->curveParam.pP, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_ECDSA_VerifySignature_CheckR, ECC_T1, pParam->curveParam.pN, byteLenN);

    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T0, ECC_P);
    uint32_t zeroFlag_checkP = MCUXCLPKC_WAITFORFINISH_GETZERO();

    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T1, ECC_N);
    uint32_t zeroFlag_checkN = MCUXCLPKC_WAITFORFINISH_GETZERO();

    /* Check signature R again by CPU. */
    uint8_t *pImportR = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);
    uint8_t *pCalcR   = MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_X1]);
    mcuxCsslParamIntegrity_Checksum_t compareR_paramChkSum = mcuxCsslParamIntegrity_Protect(3u, pImportR, pCalcR, operandSize);
    MCUX_CSSL_FP_FUNCTION_CALL(cmpareR_result, mcuxCsslMemory_Compare(compareR_paramChkSum, pImportR, pCalcR, operandSize));

    if (   (MCUXCSSLMEMORY_STATUS_EQUAL == cmpareR_result)
        && (zeroFlag_checkP == MCUXCLPKC_FLAG_ZERO)
        && (zeroFlag_checkN == MCUXCLPKC_FLAG_ZERO) )
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_CheckR, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare)
            );
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_CheckR, MCUXCLECC_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Verify)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Verify(
        mcuxClSession_Handle_t pSession,
        const mcuxClEcc_Verify_Param_t * pParam)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Verify);

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/
    /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
    mcuxClEcc_CpuWa_t * const pCpuWorkarea = mcuxClEcc_castToEccCpuWorkarea(mcuxClSession_getCpuWaBuffer(pSession));

    MCUX_CSSL_FP_FUNCTION_CALL(ret_SetupEnvironment,
        mcuxClEcc_Weier_SetupEnvironment(pSession,
                                        & pParam->curveParam,
                                        ECC_VERIFY_NO_OF_BUFFERS) );
    if (MCUXCLECC_STATUS_OK != ret_SetupEnvironment)
    {
        if (MCUXCLECC_STATUS_INVALID_PARAMS == ret_SetupEnvironment)
        {
            /* Session has been cleaned, PKC has been deinitialized in SetupEnvironment. */
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, ret_SetupEnvironment,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SetupEnvironment) );
        }

        MCUXCLECC_HANDLE_HW_UNAVAILABLE(ret_SetupEnvironment, mcuxClEcc_Verify);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    const uint32_t byteLenP = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenP_mask) >> mcuxClEcc_DomainParam_misc_byteLenP_offset;
    const uint32_t byteLenN = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenN_mask) >> mcuxClEcc_DomainParam_misc_byteLenN_offset;

    /**********************************************************/
    /* Import signature r and s, and                          */
    /* check both r,s are in range [1, n-1]                   */
    /**********************************************************/

    /* Import r to S3 and s to T1. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Verify, ECC_S3, pParam->pSignature, byteLenN);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET(mcuxClEcc_Verify, ECC_T1, pParam->pSignature, byteLenN, byteLenN);

    /* If r < n, then t2 = r; otherwise t2 = r - n. */
    /* Verify that r and s are in range [1,n-1] */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_SignatureRangeCheck, mcuxClEcc_Weier_SignatureRangeCheck());
    if (MCUXCLECC_STATUS_INVALID_SIGNATURE == ret_SignatureRangeCheck)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);

        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, ret_SignatureRangeCheck,
            MCUXCLECC_FP_VERIFY_INIT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SignatureRangeCheck),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /**********************************************************/
    /* Import message hash, and truncate if longer than n     */
    /**********************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL(ret_PrepareMessageDigest, mcuxClEcc_Verify_PrepareMessageDigest(pParam, byteLenN) );
    if (MCUXCLECC_STATUS_OK != ret_PrepareMessageDigest)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Check if hash is 0 modulo n (one subtraction is enough, because bit length of hash <= bit length of n). */
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_S2, ECC_S2, ECC_N, ECC_N);
    uint32_t checkHashZero = MCUXCLPKC_WAITFORFINISH_GETZERO();

    /**********************************************************/
    /* Calculate s^(-1), and                                  */
    /* u1 = hash * s^(-1) mod n and u2 = r * s^(-1) mod n     */
    /**********************************************************/

    /* Calculate s^(-1) * 256^LEN mod n. */
    MCUXCLPKC_FP_CALC_MC1_MR(ECC_T2, ECC_T1, ECC_N);      // t2 = s * (256^LEN)^(-1)
    MCUXCLMATH_FP_MODINV(ECC_T1, ECC_T2, ECC_N, ECC_T3);  // t1 = t2^(-1) = s^(-1) * 256^LEN, using T3 as temp

    /* Initialize z coordinate, z = 1 in MR, in Z. */
    /* Calculate u1 and u2, store result in S0 and S1. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_InitZ_CalcU1U2,
                        mcuxClEcc_Fup_Verify_InitZ_CalcU1U2_LEN);
    /* Check if u1 is zero. */
    if (checkHashZero != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /**********************************************************/
    /* Calculate P1 = u1 * G                                  */
    /**********************************************************/

    /* Interleave u1 in S0 and u2 in S1. */
    MCUXCLECC_FP_INTERLEAVETWOSCALARS(MCUXCLPKC_PACKARGS2(ECC_S0, ECC_S1), byteLenN * 8u);

    /* Calculate P1 = u1 * G, if u1 != 0 */
    if (MCUXCLPKC_FLAG_ZERO != checkHashZero)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(ret_plainFixScalarMult,
            mcuxClEcc_Weier_PlainFixScalarMult(pParam, byteLenP, byteLenN));

        if (MCUXCLECC_STATUS_INVALID_PARAMS == ret_plainFixScalarMult)
        {
            mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
            MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
                mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);

            mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, ret_plainFixScalarMult,
                MCUXCLECC_FP_VERIFY_INIT,
                MCUXCLECC_FP_VERIFY_PREPARE_AND_CHECK,
                MCUXCLECC_FP_VERIFY_CALC_P1,
                MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
        }
        else if (MCUXCLECC_STATUS_OK != ret_plainFixScalarMult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
        else
        {
            /* Do nothing. */
        }
    }

    MCUX_CSSL_FP_FUNCTION_CALL(ret_ImportAndCheckPublicPoint, mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey(pParam, byteLenP, byteLenN, checkHashZero));

    if (MCUXCLECC_STATUS_INVALID_PARAMS == ret_ImportAndCheckPublicPoint)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

         MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, ret_ImportAndCheckPublicPoint,
            MCUXCLECC_FP_VERIFY_INIT,
            MCUXCLECC_FP_VERIFY_PREPARE_AND_CHECK,
            MCUXCLECC_FP_VERIFY_CALC_P1,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
    else if (MCUXCLECC_STATUS_OK != ret_ImportAndCheckPublicPoint)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    /**********************************************************/
    /* Calculate P1 + u2 * Q, and update P1 accordingly       */
    /**********************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL(ret_Weier_Calc_P2, mcuxClEcc_ECDSA_VerifySignature_PointAddMult(pParam, byteLenN, checkHashZero));

    if (MCUXCLECC_STATUS_INVALID_SIGNATURE == ret_Weier_Calc_P2)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

         MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, ret_Weier_Calc_P2,
            MCUXCLECC_FP_VERIFY_INIT,
            MCUXCLECC_FP_VERIFY_PREPARE_AND_CHECK,
            MCUXCLECC_FP_VERIFY_CALC_P1,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_PointAddMult),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
    else if (MCUXCLECC_STATUS_OK != ret_Weier_Calc_P2)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    /**********************************************************/
    /* Check r = (x mod n) robustly, and check p and n        */
    /**********************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL(checkRStatus, mcuxClEcc_ECDSA_VerifySignature_CheckR(pParam, byteLenP, byteLenN, checkHashZero));
    if (MCUXCLECC_STATUS_OK == checkRStatus)
    {
        /**********************************************************/
        /* Clean up and exit                                      */
        /**********************************************************/

        /* Export the calculated r. */
        MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER(mcuxClEcc_Verify, pParam->pOutputR, WEIER_X1, byteLenN);

        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClEcc_Verify, checkRStatus, MCUXCLECC_STATUS_FAULT_ATTACK,
            MCUXCLECC_FP_VERIFY_INIT,
            MCUXCLECC_FP_VERIFY_PREPARE_AND_CHECK,
            MCUXCLECC_FP_VERIFY_CALC_P1,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_PointAddMult),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_CheckR),
            MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
    else if (MCUXCLECC_STATUS_INVALID_SIGNATURE == checkRStatus)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClEcc_Verify, checkRStatus, MCUXCLECC_STATUS_FAULT_ATTACK,
            MCUXCLECC_FP_VERIFY_INIT,
            MCUXCLECC_FP_VERIFY_PREPARE_AND_CHECK,
            MCUXCLECC_FP_VERIFY_CALC_P1,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_ImportAndCheckPublicKey),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_PointAddMult),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_CheckR),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
    else
    {
        /* Do nothing. */
    }

    /* Results of checking R are inconsistent, or p or n got modified. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Verify, MCUXCLECC_STATUS_FAULT_ATTACK);
}


