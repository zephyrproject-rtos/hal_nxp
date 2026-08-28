/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_GenerateKeyPair.c
 * @brief ECC Weierstrass key pair generation function
 */


#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClPkc_Macros.h>

#include <mcuxClEcc.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_ECDSA =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .pKeyGenFct = mcuxClEcc_WeierECC_GenerateKeyPair,
    .protectionTokenKeyGenFct = MCUX_CSSL_FP_FUNCID_mcuxClEcc_WeierECC_GenerateKeyPair,
    .pProtocolDescriptor = NULL
};

const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_ECDH =
{
    .pKeyGenFct = mcuxClEcc_WeierECC_GenerateKeyPair,
    .protectionTokenKeyGenFct = MCUX_CSSL_FP_FUNCID_mcuxClEcc_WeierECC_GenerateKeyPair,
    .pProtocolDescriptor = NULL
};

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_WeierECC_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_WeierECC_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_WeierECC_GenerateKeyPair);

    /* Verify that the key handles are correctly initialized for the ECC use case */
    const mcuxClKey_AlgorithmId_t algorithmId_privKey = mcuxClKey_getAlgorithm(privKey);

    if( ( (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP != algorithmId_privKey)
                && (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM != algorithmId_privKey)
                && (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM != algorithmId_privKey) )
            || algorithmId_privKey != mcuxClKey_getAlgorithm(pubKey)
            || mcuxClKey_getTypeInfo(privKey) != mcuxClKey_getTypeInfo(pubKey)
            || MCUXCLKEY_ALGO_ID_PRIVATE_KEY != mcuxClKey_getKeyUsage(privKey)
            || MCUXCLKEY_ALGO_ID_PUBLIC_KEY != mcuxClKey_getKeyUsage(pubKey)
            )
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_FAILURE);
    }
    else
    {
        /* Unused input parameters */
        (void) generation;

        /**********************************************************/
        /* Initialization                                         */
        /**********************************************************/
        mcuxClEcc_Weier_DomainParams_t *pDomainParams = (mcuxClEcc_Weier_DomainParams_t *) mcuxClKey_getTypeInfo(privKey);

        /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("MISRA Ex. 9 to Rule 11.3 - mcuxClEcc_CpuWa_t is 32 bit aligned")
        MCUX_CSSL_FP_FUNCTION_CALL(mcuxClEcc_CpuWa_t*, pCpuWorkarea, mcuxClSession_allocateWords_cpuWa(pSession, 0u));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()
        MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, 0u));

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                        pDomainParams,
                                        ECC_GENERATEKEYPAIR_NO_OF_BUFFERS));

        /* Randomize coordinate buffers used within secure scalar multiplication (X0/Y0/X1/Y1). */
        uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_RandomizeUPTRT(&pOperands[WEIER_X0],
                                                            (WEIER_Y1 - WEIER_X0 + 1u)) );

        MCUXCLMATH_FP_QSQUARED(pSession, ECC_NQSQR, ECC_NS, ECC_N, ECC_T0);

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
        uint32_t *pOperands32 = (uint32_t *) pOperands;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
        const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

        const uint32_t byteLenP = pDomainParams->common.byteLenP;
        const uint32_t byteLenN = pDomainParams->common.byteLenN;

        /**********************************************************/
        /* Import and check base point G                          */
        /**********************************************************/

        /* Import G to (X1,Y1). */
        MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(WEIER_X1, pDomainParams->common.pGx, byteLenP, operandSize);
        MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(WEIER_Y1, pDomainParams->common.pGy, byteLenP, operandSize);

        /* Check G in (X1,Y1) affine NR. */
    //  MCUXCLPKC_WAITFORREADY();  <== there is WaitForFinish in import function.
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X1);
        MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus, mcuxClEcc_PointCheckAffineNR(pSession));
        if (MCUXCLECC_STATUS_OK != pointCheckStatus)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }


        /**********************************************************/
        /* Generate multiplicative split private key d0 and d1,   */
        /* d = d0 * d1 mod n, where d0 is a 64-bit odd number.    */
        /**********************************************************/

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Int_CoreKeyGen(pSession, byteLenN));

        /**********************************************************/
        /* Derive the plain private key d = d0 * d1 mod n < n.    */
        /**********************************************************/

        /* Compute d in S2 using a blinded multiplication utilizing the random still stored in S3 after mcuxClEcc_Int_CoreKeyGen. */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_KeyGen_DerivePlainPrivKey,
                            mcuxClEcc_FUP_Weier_KeyGen_DerivePlainPrivKey_LEN);

        /**********************************************************/
        /* Calculate public key Q = d1 * (d0 * G)                 */
        /**********************************************************/

        /* Convert coordinates of G to Montgomery representation. */
        MCUXCLPKC_FP_CALC_MC1_MM(WEIER_X0, WEIER_X1, ECC_PQSQR, ECC_P);
        MCUXCLPKC_FP_CALC_MC1_MM(WEIER_Y0, WEIER_Y1, ECC_PQSQR, ECC_P);
        MCUXCLPKC_FP_CALC_OP1_NEG(WEIER_Z, ECC_P);  /* 1 in MR */
        /* G will be randomized (projective coordinate randomization) in SecurePointMult. */

        /* Calculate Q0 = d0 * G. */
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


        /**********************************************************/
        /* Convert public key to affine coordinates and check     */
        /**********************************************************/

        /* T0 = ModInv(Z), where Z = (z * 256^LEN) \equiv z in MR. */
        MCUXCLECC_FP_MODINV(pSession, ECC_T0, WEIER_Z, ECC_P, ECC_T1, ECC_T3);
        /* T0 = z^(-1) * 256^(-LEN) \equiv z^(-1) * 256^(-2LEN) in MR. */

        /* Convert Q to affine coordinates. */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine,
                            mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine_LEN);

        /* Check Q in (XA,YA) affine NR. */
        MCUXCLPKC_WAITFORREADY();
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_XA);
        MCUX_CSSL_FP_FUNCTION_CALL(pointCheckQStatus, mcuxClEcc_PointCheckAffineNR(pSession));
        if (MCUXCLECC_STATUS_OK != pointCheckQStatus)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }


        /**********************************************************/
        /* Check n and p and export private and public key.       */
        /**********************************************************/

        /* Import prime p and order n again, and check (compare with) existing one. */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(
            mcuxClEcc_IntegrityCheckPN(pSession, (mcuxClEcc_CommonDomainParams_t *) &pDomainParams->common));

        /* Store private key into key handle */
        uint8_t *pPrivKeySrc = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]);
        MCUXCLKEY_STORE_FP(
            pSession,
            privKey,
            pPrivKeySrc,
            0u);

        /* Store public key into key handle */
        uint8_t *pPubKeyXSrc = MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_XA]);
        MCUXCLKEY_STORE_FP(
            pSession,
            pubKey,
            pPubKeyXSrc,
            0u);

        /* Create link between private and public key handles */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_linkKeyPair(pSession, privKey, pubKey));

        /* Clear PKC workarea. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pCpuWorkarea->wordNumPkcWa * sizeof(uint32_t) won't wrap because pkcWaSize < MAX_PKCRAM_SIZE < UINT32_MAX")
        MCUXCLPKC_PS1_SETLENGTH(0u, pCpuWorkarea->wordNumPkcWa * sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        pOperands[ECC_P] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea);
        MCUXCLPKC_FP_CALC_OP1_CONST(ECC_P, 0u);

        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_WeierECC_GenerateKeyPair,
            MCUXCLECC_FP_GENERATEKEYPAIR_FINAL(privKey, pubKey),
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarEvenBranch, MCUXCLPKC_FLAG_NONZERO == d1NoOfTrailingZeros));
    }
}
