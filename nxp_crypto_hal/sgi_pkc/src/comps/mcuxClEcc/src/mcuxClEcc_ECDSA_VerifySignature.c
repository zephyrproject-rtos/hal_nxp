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
 * @file  mcuxClEcc_ECDSA_VerifySignature.c
 * @brief Weierstrass curve ECDSA signature verification API
 */


#include <stdint.h>
#include <stddef.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxClBuffer.h>
#include <mcuxClEcc.h>
#include <mcuxClSignature.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_Compare_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>

#include <internal/mcuxClEcc_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClEcc_ECDSA_Internal.h>
#include <internal/mcuxClEcc_Internal_KeyHelper.h>

/* Define used to protect non zero hash branches in mcuxClEcc_ECDSA_VerifySignature */
#define MCUXCLECC_FLAG_HASHNONZERO                        0x171BA3A5u
/* Define used to protect zero hash branches in mcuxClEcc_ECDSA_VerifySignature */
#define MCUXCLECC_FLAG_HASHZERO                           0x171BA5A3u

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
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_SignatureRangeCheck)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_SignatureRangeCheck(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_SignatureRangeCheck);

    /* If r < n, then ECC_T2 = r; otherwise ECC_T2 = r - n. */
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T2, ECC_S3, ECC_N, ECC_N);

    /* Check r != 0, r != n. */
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {   /* r = 0 or n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);
    }

    /* Check r < n. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S3, ECC_N);
    if (MCUXCLPKC_FLAG_CARRY != MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {   /* r > n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
    }

    /* If s < n, then ECC_T3 = s; otherwise ECC_T3 = s - n. */
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T3, ECC_T1, ECC_N, ECC_N);

    /* Check s != 0, s != n. */
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {   /* s = 0 or n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);
    }

    /* Check s < n. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T1, ECC_N);
    if (MCUXCLPKC_FLAG_CARRY != MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {   /* s > n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_SignatureRangeCheck, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_SignatureRangeCheck, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
}

/**
 * This function imports r, s and message hash into PKC and verifies ranges.
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK                 if the range check passed and the function executed successfully
 *  - MCUXCLECC_STATUS_INVALID_SIGNATURE  if the range check failed, i.e. the signature is invalid
 *
 * Prerequisites:
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_NFULL contains n'||n
 *
 * @post
 *  - Data Integrity: Expunge(pIn + inSize).
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_VerifySignature_Import)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_VerifySignature_Import(mcuxClSession_Handle_t pSession, mcuxClEcc_CpuWa_t* pCpuWorkarea, mcuxCl_InputBuffer_t pIn, uint32_t inSize, mcuxCl_InputBuffer_t pSignature, uint32_t byteLenN, uint32_t operandSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_VerifySignature_Import);

    /* Import r to S3 and s to T1. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_S3, pSignature, byteLenN, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET_DI_BALANCED(ECC_T1, pSignature, byteLenN, byteLenN, operandSize);

    /* Verify that r and s are in range [1,n-1] */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_SignatureRangeCheck, mcuxClEcc_ECDSA_SignatureRangeCheck());
    if (MCUXCLECC_STATUS_OK != ret_SignatureRangeCheck)
    {
        MCUX_CSSL_DI_EXPUNGE(pInIntegrity, pIn);
        MCUX_CSSL_DI_EXPUNGE(inSizeIntegrity, inSize);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_Import, ret_SignatureRangeCheck,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_SignatureRangeCheck));
    }

    /**********************************************************/
    /* Import message hash, and truncate if longer than n     */
    /**********************************************************/
    /* Import message digest to buffer ECC_S2 and pad or truncate it */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_ECDSA_PrepareMessageDigest(
                                    pIn,
                                    inSize,
                                    byteLenN));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_Import, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_SignatureRangeCheck),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_PrepareMessageDigest));
}


/**
 * This function calculates (x1, y1) = P1 + P2 and verify if signature is valid.
 *
 * Return values:
 *  - MCUXCLECC_STATUS_NEUTRAL_POINT            if the P1+P2 results in a neutral point
 *  - MCUXCLECC_STATUS_INVALID_SIGNATURE        if the calculated 'R' doesn't match the imported signature
 *
 * @post
 * Data Integrity: This function EXPUNGE MCUXCLECC_FLAG_HASHZERO or MCUXCLECC_FLAG_HASHNONZERO for DI protection. The corresponding RECORD must be done in the caller.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_VerifySignature_Calculate)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_VerifySignature_Calculate(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_CpuWa_t *pCpuWorkarea,
    uint32_t          checkHashZero,
    volatile uint32_t* pZeroFlagValidityCheckByPKC)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_VerifySignature_Calculate);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Calculate P2 += P1, if u1 != 0. */
    if (MCUXCLPKC_FLAG_NONZERO == checkHashZero)
    {
        /* Calculate P2 = P2 + P1 twice and compare results. Early-exit with FA in case the results differ. */
        MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ECDSA_VerifySignature_hash_zero_flag, MCUXCLECC_FLAG_HASHNONZERO);
        /* Input: P1 in (X0,Y0, Z) Jacobian;          */
        /*        P2 in (XA,YA, ZA) relative-z.       */
        /* Output: P1 + P2 in (XA,YA, ZA) relative-z. */
        /* First calculation of P2 = P2 + P1 */
        MCUXCLPKC_WAITFORREADY();
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_XA);   /* input: P2 */
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, WEIER_X0);   /* input: P1 */
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X2);   /* output: P1 + P2 */
        pOperands[WEIER_VZ] = pOperands[WEIER_Z];                                /* input: z */
        pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];                              /* input: z' */
        pOperands[WEIER_VZ0] = pOperands[WEIER_X3];                              /* output: z' */
        MCUX_CSSL_FP_FUNCTION_CALL(statusPointFullAdd, mcuxClEcc_PointFullAdd());

        if (MCUXCLECC_STATUS_NEUTRAL_POINT == statusPointFullAdd)
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("insufficient workarea (pCpuWorkarea = NULL) will be checked in SetupEnvironment")
            mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
            MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

            mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

            /* If P1+P2 == Neutral point, exit with MCUXCLECC_STATUS_NEUTRAL_POINT ; FP is balanced by the caller outside this function */
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_Calculate, MCUXCLECC_STATUS_NEUTRAL_POINT,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd),
                MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE
            );
        }

        /* Second calculation of P2 = P2 + P1 */
        MCUXCLPKC_WAITFORREADY();
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_XA);   /* input: P2 */
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VZ0, WEIER_ZA);   /* input: z' and z;  */
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, WEIER_X0);   /* input: P1 */
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_XA);   /* output P1 + P2 */
        pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];                              /* output z' */
        MCUX_CSSL_FP_FUNCTION_CALL(statusPointFullAdd2, mcuxClEcc_PointFullAdd());
        if (MCUXCLECC_STATUS_NEUTRAL_POINT == statusPointFullAdd2)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
        }

        /* Compare result of first (X2,Y2, X3) and second (XA,YA, ZA) computation. If they're not the same, early-exit with FA. */
        MCUXCLPKC_FP_CALC_OP1_SUB(ECC_T0, WEIER_X2, WEIER_XA);
        MCUXCLPKC_FP_CALC_OP1_SUB(ECC_T1, WEIER_Y2, WEIER_YA);
        MCUXCLPKC_FP_CALC_OP1_SUB(ECC_T2, WEIER_X3, WEIER_ZA);
        MCUXCLPKC_FP_CALC_OP1_OR(ECC_T3, ECC_T0, ECC_T1);
        MCUXCLPKC_FP_CALC_OP1_OR(ECC_T0, ECC_T3, ECC_T2);
        if (MCUXCLPKC_FLAG_ZERO != MCUXCLPKC_WAITFORFINISH_GETZERO())
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
        }
    }
    else if (MCUXCLPKC_FLAG_ZERO == checkHashZero)
    {
        /* Move P2 to (X2,Y2, X3) in case of a null hash */
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_X2, WEIER_XA, 0u);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_Y2, WEIER_YA, 0u);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_X3, WEIER_ZA, 0u);
        MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ECDSA_VerifySignature_hash_zero_flag, MCUXCLECC_FLAG_HASHZERO);
    }
    else
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Convert P1 + P2 (or P2 if u1 == 0) to (X0,Y0), affine NR. */
    /* Calculate R = x mod n, in X1. */
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_T0, WEIER_Z, WEIER_ZA, ECC_P);  // t0 = z*z' * 256^LEN         = z*z' in MR
    MCUXCLECC_FP_MODINV(pSession, ECC_T1, ECC_T0, ECC_P, ECC_T2, ECC_T3);     // t1 = (z*z')^(-1) * 256^(-LEN), use T2, T3 as temp
    /* MISRA Ex. 22, while(0) is allowed */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR,
                        mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR_LEN);

    /* Check if P1 + P2 is valid. */
    //  MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VX0/VY0 are not used in the FUP program before.
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X0);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_STATUS_OK != pointCheckStatus)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /**********************************************************/
    /* Check r = (x mod n) robustly, and check p and n        */
    /**********************************************************/

    /* Check if imported signature R is equal to the calculated R. */
    MCUXCLPKC_FP_CALC_OP1_CMP(WEIER_X1, ECC_S3);
    *pZeroFlagValidityCheckByPKC = MCUXCLPKC_WAITFORFINISH_GETZERO();

    /* Check signature R again by CPU. */
    mcuxClMemory_Status_t cmpR_byCpu = MCUXCLMEMORY_STATUS_NOT_EQUAL;
        uint8_t *pImportR = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);
        uint8_t *pCalcR = MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_X1]);
        const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

        MCUX_CSSL_DI_RECORD(sigValiditycheckCPU, (uint32_t)pImportR + (uint32_t)pCalcR + operandSize);
        MCUXCLMEMORY_COMPARE_INT(cmpR_byCpu, pImportR, pCalcR, operandSize);
    MCUX_CSSL_DI_RECORD(sigValiditycheckCPU, (uint32_t)cmpR_byCpu);

    if ((MCUXCLPKC_FLAG_ZERO != *pZeroFlagValidityCheckByPKC)
        || (MCUXCLMEMORY_STATUS_EQUAL != cmpR_byCpu)
    )
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("insufficient workarea (pCpuWorkarea = NULL) will be checked in SetupEnvironment")
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_DI_EXPUNGE(sigValiditycheckCPU, (uint32_t)cmpR_byCpu);
        /* If imported signature is not equal to the calculated R, exit with Invalid Signature ; FP is balanced by the caller outside this function */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_Calculate, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_P1_ADD_P2,
                MCUXCLMEMORY_COMPARE_INT_FP_EXPECT,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE
        );
    }

    MCUX_CSSL_DI_EXPUNGE(sigValiditycheckCPU, MCUXCLMEMORY_STATUS_EQUAL);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature_Calculate, MCUXCLECC_STATUS_OK,
            MCUXCLMEMORY_COMPARE_INT_FP_EXPECT,
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_P1_ADD_P2
    );
}

/**
 * @brief Calculate P1 = u1 * G, if u1 != 0
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_Calculate_P1)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_ECDSA_Calculate_P1(
  uint32_t                      checkHashZero,
  mcuxClEcc_Weier_DomainParams_t *pDomainParams,
  mcuxClSession_Handle_t         pSession
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_Calculate_P1);

    /* Calculate P1 = u1 * G, if u1 != 0 */
    MCUX_CSSL_FP_BRANCH_DECL(checkHashZeroBranch);
    if (MCUXCLPKC_FLAG_NONZERO == checkHashZero)
    {
        MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ECDSA_VerifySignature_hash_zero_flag, MCUXCLECC_FLAG_HASHNONZERO);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(
            pDomainParams->common.pScalarMultFunctions->plainFixScalarMultFct(
                pSession,
                (mcuxClEcc_CommonDomainParams_t *)&pDomainParams->common,
                ECC_S0,
                pDomainParams->common.byteLenN * 8u,
                MCUXCLECC_SCALARMULT_OPTION_AFFINE_INPUT |
                MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_OUTPUT |
                MCUXCLECC_SCALARMULT_OPTION_NO_OUTPUT_VALIDATION)); // TODO (CLNS-13627): Move mcuxClEcc_PointCheckAffineNR into the function

        MCUX_CSSL_FP_BRANCH_POSITIVE(checkHashZeroBranch,
            pDomainParams->common.pScalarMultFunctions->plainFixScalarMultFctFPId);
    }
    else if (MCUXCLPKC_FLAG_ZERO == checkHashZero)
    {
        MCUX_CSSL_FP_BRANCH_NEGATIVE(checkHashZeroBranch);
        MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ECDSA_VerifySignature_hash_zero_flag, MCUXCLECC_FLAG_HASHZERO);
    }
    else
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Reset z' = 1 in MR (or initialize z' if u1 == 0). */
    MCUXCLPKC_FP_CALC_OP1_NEG(WEIER_ZA, ECC_P);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_ECDSA_Calculate_P1,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(checkHashZeroBranch, MCUXCLPKC_FLAG_NONZERO == checkHashZero),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(checkHashZeroBranch, MCUXCLPKC_FLAG_NONZERO != checkHashZero),
        MCUXCLPKC_FP_CALLED_CALC_OP1_NEG);
}

// TODO: Add sanity checks on the key CLNS-7854
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_VerifySignature, mcuxClSignature_VerifyFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClEcc_ECDSA_VerifySignature(
    mcuxClSession_Handle_t   pSession,
    mcuxClKey_Handle_t       key,
    mcuxClSignature_Mode_t   mode,
    mcuxCl_InputBuffer_t     pIn,
    uint32_t                inSize,
    mcuxCl_InputBuffer_t     pSignature,
    uint32_t                signatureSize
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_VerifySignature);

    /* Record the parameters expunged in VerifySignature_Import() */
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pParamProtect, mcuxClSession_allocateWords_cpuWa(pSession, 1U));
    MCUX_CSSL_DI_RECORD(parameterProtection, *pParamProtect);
    MCUX_CSSL_DI_EXPUNGE(parameterProtection, mode); /* Unused so expunge immediatelly */
    mcuxClSession_freeWords_cpuWa(pSession, 1U);

    /* Assume invalid signature and expunge in case it is OK */
    MCUX_CSSL_DI_RECORD(mcuxClEcc_ECDSA_VerifySignature_return, MCUXCLSIGNATURE_STATUS_NOT_OK);

    /**********************************************************/
    /* Step 1: Initialization                                 */
    /**********************************************************/
    /* TODO: Do sanity check for the input parameters. Ticket CLNS-7854 */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    mcuxClEcc_Weier_DomainParams_t *pDomainParams = (mcuxClEcc_Weier_DomainParams_t *) mcuxClKey_getTypeInfo(key);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()
    const uint32_t byteLenN = pDomainParams->common.byteLenN;

    if (signatureSize != byteLenN * 2u)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLSIGNATURE_STATUS_INVALID_PARAMS);
    }

    /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                 pDomainParams,
                        ECC_VERIFYSIGNATURE_NO_OF_BUFFERS));

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

    /**********************************************************/
    /* Step 2: Import signature r and s twice, and            */
    /* check both r,s are in range [1, n-1] twice             */
    /**********************************************************/

    /* First import */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_VerifySignature_Import_1,
        mcuxClEcc_ECDSA_VerifySignature_Import(pSession, pCpuWorkarea, pIn, inSize, pSignature, byteLenN, operandSize));
    if(MCUXCLECC_STATUS_OK != ret_VerifySignature_Import_1)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("insufficient workarea (pCpuWorkarea = NULL) will be checked in SetupEnvironment")
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        /* No need to record as RECORD(pIn + pSize) is done via Signature_Import */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature, MCUXCLSIGNATURE_STATUS_NOT_OK,
            /* Step 1 */
            MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_INIT,
            /* Step 2 */
            MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_IMPORT1,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /* Check if hash is 0 modulo n (one subtraction is enough, because bit length of hash <= bit length of n). ECC_T2 used as temp buffer to avoid in-place operation. */
    MCUXCLPKC_FP_CALC_OP1_ADD_CONST(ECC_T2, ECC_S2, 0u);
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_S2, ECC_T2, ECC_N, ECC_N);
    uint32_t checkHashZero = MCUXCLPKC_WAITFORFINISH_GETZERO();
    /* save S2 to T0 for double checking */
    MCUXCLPKC_FP_CALC_OP1_ADD_CONST(ECC_T0, ECC_S2, 0u);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_VerifySignature_Import_2,
        mcuxClEcc_ECDSA_VerifySignature_Import(pSession, pCpuWorkarea, pIn, inSize, pSignature, byteLenN, operandSize));
    if(MCUXCLECC_STATUS_OK != ret_VerifySignature_Import_2)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
    }
    MCUXCLPKC_FP_CALC_OP1_ADD_CONST(ECC_T2, ECC_S2, 0u);
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_S2, ECC_T2, ECC_N, ECC_N);
    /* check consistency on hash input */
    if (checkHashZero != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
    }
    MCUX_CSSL_DI_RECORD(mcuxClEcc_ECDSA_VerifySignature_hash_zero_flag, (checkHashZero * MCUXCLECC_FLAG_HASHZERO + (1U - checkHashZero) * MCUXCLECC_FLAG_HASHNONZERO));
    MCUX_CSSL_DI_RECORD(mcuxClEcc_ECDSA_VerifySignature_hash_zero_flag, (checkHashZero * MCUXCLECC_FLAG_HASHZERO + (1U - checkHashZero) * MCUXCLECC_FLAG_HASHNONZERO));
    /* check S2 corrupted or not */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T0, ECC_S2);
    if (MCUXCLPKC_FLAG_ZERO != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
    }

    /**********************************************************/
    /* Step 3: Calculate s^(-1), and                          */
    /* u1 = hash * s^(-1) mod n and u2 = r * s^(-1) mod n     */
    /**********************************************************/

    /* Calculate s^(-1) * 256^LEN mod n. */
    MCUXCLPKC_FP_CALC_MC1_MR(ECC_T2, ECC_T1, ECC_N);      // t2 = s * (256^LEN)^(-1)
    MCUXCLECC_FP_MODINV(pSession, ECC_T1, ECC_T2, ECC_N, ECC_T3, ECC_T0);  // t1 = t2^(-1) = s^(-1) * 256^LEN, using T3, T0 as temp

    /* Initialize z coordinate, z = 1 in MR, in Z. */
    /* Calculate u1 and u2, store result in S0 and S1. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_InitZ_CalcU1U2,
                        mcuxClEcc_Fup_Verify_InitZ_CalcU1U2_LEN);
    /* Check if u1 is zero. */
    if (checkHashZero != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
    }


    /**********************************************************/
    /* Step 4: Calculate P1 = u1 * G                          */
    /**********************************************************/
    /* Calculate P1 = u1 * G, if u1 != 0 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_ECDSA_Calculate_P1(checkHashZero, pDomainParams, pSession));


    /**********************************************************/
    /* Step 5: Calculate P2 = u2*Q, and update P1 accordingly */
    /**********************************************************/

    /* Load affine coordinates of public key Q to buffers (X1,Y1) in affine NR and clear any potential garbage
     * in these buffers as a preparation for the following point validation. */
    uint8_t *pPubKeyX = MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_X1]);
    uint8_t *pPubKeyY = MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_Y1]);
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
    const uint32_t byteLenP = pDomainParams->common.byteLenP;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("operandSize is by definition not smaller than byteLenP.")
    const uint32_t bytesToClear = operandSize - byteLenP;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    MCUX_CSSL_DI_RECORD(sumOfMemClearParamsX, (uint32_t)&pPubKeyX[byteLenP] + bytesToClear);
    MCUXCLMEMORY_CLEAR_INT(&pPubKeyX[byteLenP], bytesToClear);

    MCUX_CSSL_DI_RECORD(sumOfMemClearParamsY, (uint32_t)&pPubKeyY[byteLenP] + bytesToClear);
    MCUXCLMEMORY_CLEAR_INT(&pPubKeyY[byteLenP], bytesToClear);

    MCUXCLKEY_LOAD_FP(
      pSession,
      key,
      &pPubKeyX,
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
      NULL,
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
      MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);


    /* Check Q in (X1,Y1) affine NR. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X1);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckPubKeyStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckPubKeyStatus)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLSIGNATURE_STATUS_INVALID_PARAMS);
    }

    /* Convert Q: (X1,Y1) affine NR -> (X0,Y0, Z) Jacobian. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR,
                        mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR_LEN);

    /* Calculate PrecQ = (2^(byteLenN *4)) * Q. */
    /* Input: Q in (X0,Y0, ZA=1) relative-z.    */
    /* Output: PrecQ in (X3,Y3, ZA) relative-z. */
//  MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VX0/VY0/VZ0/VZ/VX2/VY2/VZ2 are not used in the FUP program before.
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X3);  /* output: PrecQ */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VZ0, WEIER_ZA);   /* input: z, z'; output z' */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_X0);  /* input: Q */
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
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VT2, WEIER_X2);  /* output: Prec2 */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X3);  /* input: PrecQ; output: Prec3 */
    pOperands[WEIER_VZ0] = pOperands[WEIER_ZA];                        /* input/output: z' */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, WEIER_X0);  /* input: Q */
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
    /* Step 6: Calculate (x1,y1) = P1+P2,and check the result */
    /**********************************************************/

    volatile uint32_t zeroFlagValidityCheckByPKC = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL(ret_VerifySignature_Calculate,
        mcuxClEcc_ECDSA_VerifySignature_Calculate(pSession, pCpuWorkarea, checkHashZero, &zeroFlagValidityCheckByPKC)
    );

    if(MCUXCLECC_STATUS_OK != ret_VerifySignature_Calculate)
    {
        /* 2x EXPUNGE(pIn + pSize) done via Signature_Import so do one RECORD to get correct expectations */
        MCUX_CSSL_DI_RECORD(pInIntegrity, pIn);
        MCUX_CSSL_DI_RECORD(inSizeIntegrity, inSize);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_VerifySignature, MCUXCLSIGNATURE_STATUS_NOT_OK,
            MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_PREPARE_AND_CHECK
        );
    }

    /**********************************************************/
    /* Step 7: Clean up and exit                              */
    /**********************************************************/

    /* Export the calculated r. */
    uint8_t computedRForComparison[MCUXCLECC_WEIERECC_MAX_SIZE_BASEPOINTORDER];
    MCUXCLBUFFER_INIT(buffComputedR, NULL, computedRForComparison, byteLenN);
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER_DI_BALANCED(buffComputedR, WEIER_X1, byteLenN);

    /* Import prime p and order n again, and check (compare with) existing one. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        mcuxClEcc_IntegrityCheckPN(pSession, (mcuxClEcc_CommonDomainParams_t *) &pDomainParams->common));

    /* Save the CRC of the computed R value in the session (if the security option is enabled) */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSession_computeAndSetCrcForExternalVerification(pSession, computedRForComparison, byteLenN));

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("insufficient workarea (pCpuWorkarea = NULL) will be checked in SetupEnvironment")
    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    /* Record MCUXCLSIGNATURE_STATUS_OK, as zeroFlagValidityCheckByPKC should equal MCUXCLPKC_FLAG_ZERO */
    MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ECDSA_VerifySignature_return, MCUXCLSIGNATURE_STATUS_NOT_OK);
    MCUX_CSSL_DI_RECORD(mcuxClEcc_ECDSA_VerifySignature_return, MCUXCLSIGNATURE_STATUS_OK);
    /* 2x EXPUNGE(pIn + pSize) done via Signature_Import so do one RECORD to get correct expectations */
    MCUX_CSSL_DI_RECORD(pInIntegrity, pIn);
    MCUX_CSSL_DI_RECORD(inSizeIntegrity, inSize);

    uint32_t retCode = (MCUXCLSIGNATURE_STATUS_OK ^ MCUXCLPKC_FLAG_ZERO) ^ zeroFlagValidityCheckByPKC;
    MCUX_CSSL_FP_FUNCTION_EXIT(
      mcuxClEcc_ECDSA_VerifySignature,
      retCode,
      MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_PREPARE_AND_CHECK,
      /* Clean up and exit */
      MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_FINAL
      );
}

