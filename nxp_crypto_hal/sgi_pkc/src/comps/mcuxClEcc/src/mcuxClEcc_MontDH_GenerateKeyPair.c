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
 * @file  mcuxClEcc_MontDH_GenerateKeyPair.c
 * @brief mcuxClEcc: implementation of MontDH key generation function
 */


#include <stdint.h>

#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>
#include <mcuxClEcc_MemoryConsumption.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslDataIntegrity.h>

#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Internal_Random.h>
#include <internal/mcuxClEcc_Mont_Internal.h>


#define MCUXCLECC_FP_MONTDH_GENKEYPAIR_SECSTRENGTH  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_checkSecurityStrength)


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_MontDH_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation UNUSED_PARAM,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_MontDH_GenerateKeyPair);

    if(((MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PRIVATE_KEY) != mcuxClKey_getAlgoId(privKey)) || (MCUXCLKEY_SIZE_NOTUSED == mcuxClKey_getSize(privKey)) ||
       ((MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PUBLIC_KEY) != mcuxClKey_getAlgoId(pubKey)) || (MCUXCLKEY_SIZE_NOTUSED == mcuxClKey_getSize(pubKey)) ||
         mcuxClKey_getTypeInfo(privKey) != mcuxClKey_getTypeInfo(pubKey))
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    /* Set up the environment */
    mcuxClEcc_MontDH_DomainParams_t *pDomainParameters = (mcuxClEcc_MontDH_DomainParams_t *)mcuxClKey_getTypeInfo(privKey);
    mcuxClEcc_CommonDomainParams_t *pCommonDomainParameters = (mcuxClEcc_CommonDomainParams_t *)&(pDomainParameters->common);

    /* SREQI_MONTDH_7 - DI protect shifting amounts for scalar decoding */
    /* Compensates EXPUNGES in mcuxClEcc_MontDH_DecodeScalar function    */
    MCUX_CSSL_DI_RECORD(shiftAmount, (uint32_t)pDomainParameters->c);
    MCUX_CSSL_DI_RECORD(shiftAmount, (uint32_t)pDomainParameters->t);

    /* For Curve25519 and Curve448, private and public keys have the same length as the prime p */
    uint16_t keyLen = pCommonDomainParameters->byteLenP;

    /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClEcc_MontDH_SetupEnvironment(pSession, pDomainParameters, ECC_MONTDH_NO_OF_BUFFERS)
    );

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();

    /* Prepare PKC buffer ECC_S3 for private key d: Initialize it with PRNG data */
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
    uint8_t * ptrS3 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(ptrS3, keyLen));

    /* Derive the security strength required for the RNG from bitLenN/2 and check whether it can be provided. */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_checkSecurityStrength, mcuxClRandom_checkSecurityStrength(pSession, ((uint32_t) pCommonDomainParameters->byteLenN * 8u) / 2u));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret_checkSecurityStrength);

    /* Generate a M byte random private key d using the DRBG and store it in PKC buffer ECC_S3, M equals to dp->nLen */
    MCUXCLECC_FP_RANDOM_HQRNG(mcuxClEcc_MontDH_GenerateKeyPair, pSession, ptrS3, keyLen, ((uint32_t*)NULL));

    /* Call mcuxClEcc_MontDH_X to calculate the public key q=MontDH_X(d,Gx) and store it in buffer MONT_X0. If the function returns
       SCALAR_ZERO or NEUTRAL_POINT, return MCUXCLKEY_STATUS_FAULT_ATTACK */
    MCUX_CSSL_FP_FUNCTION_CALL(retCode_MontDHx, mcuxClEcc_MontDH_X(pSession, pDomainParameters, pDomainParameters->common.pGx));
#if defined(MCUXCL_FEATURE_ECC_CURVE448)
    if(MCUXCLECC_INTSTATUS_SCALAR_ZERO == retCode_MontDHx)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_SCALAR_ZERO);
    } else if(MCUXCLECC_STATUS_OK != retCode_MontDHx)
#else
    if(MCUXCLECC_STATUS_OK != retCode_MontDHx)
#endif /* MCUXCL_FEATURE_ECC_CURVE448 */
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Store private key into key handle */
        uint8_t *pPrivKeySrc = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);
        MCUXCLPKC_WAITFORFINISH();
        MCUXCLKEY_STORE_FP(
          pSession,
          privKey,
          pPrivKeySrc,
          MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE);

        /* Store public key into key handle */
        uint8_t *pPubKeySrc = MCUXCLPKC_OFFSET2PTR(pOperands[MONT_X0]);
        MCUXCLKEY_STORE_FP(
          pSession,
          pubKey,
          pPubKeySrc,
          MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);

        /* Create link between private and public key handles */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_linkKeyPair(pSession, privKey, pubKey));

        /* Import prime p and order n again, and check (compare with) existing one. */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(
            mcuxClEcc_IntegrityCheckPN(pSession, (mcuxClEcc_CommonDomainParams_t *) &pDomainParameters->common));

        /* Return OK and exit */
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_MontDH_GenerateKeyPair,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
            MCUXCLECC_FP_MONTDH_GENKEYPAIR_SECSTRENGTH,
            MCUXCLECC_FP_CALLED_RANDOM_HQRNG_PKCWA,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_X),
            MCUXCLKEY_STORE_FP_CALLED(privKey),
            MCUXCLKEY_STORE_FP_CALLED(pubKey),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_linkKeyPair),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_MontDH =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .pKeyGenFct = mcuxClEcc_MontDH_GenerateKeyPair,
    .protectionTokenKeyGenFct = MCUX_CSSL_FP_FUNCID_mcuxClEcc_MontDH_GenerateKeyPair,
    .pProtocolDescriptor = NULL
};
