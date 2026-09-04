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
 * @file  mcuxClEcc_MontDH_KeyAgreement.c
 * @brief mcuxClEcc: implementation of MontDH key agreement function acc to rfc 7748
 */


#include <stdint.h>

#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>
#include <mcuxClEcc_MemoryConsumption.h>
#include <mcuxCsslParamIntegrity.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClEcc_Internal_KeyHelper.h>
#include <internal/mcuxClEcc_Mont_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClKey_Functions_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_MontDH_KeyAgreement, mcuxClKey_AgreementFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_KeyAgreement(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Agreement_t agreement UNUSED_PARAM,
    mcuxClKey_Handle_t key,
    mcuxClKey_Handle_t otherKey,
    mcuxClKey_Agreement_AdditionalInput_t additionalInputs[] UNUSED_PARAM,
    uint32_t numberOfInputs UNUSED_PARAM,
    uint8_t * pOut,
    uint32_t * const pOutLength )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_MontDH_KeyAgreement);

    mcuxClKey_Descriptor_t * pKey = (mcuxClKey_Descriptor_t *)key;
    mcuxClKey_Descriptor_t * pOtherKey = (mcuxClKey_Descriptor_t *)otherKey;

    if(((MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PRIVATE_KEY) != mcuxClKey_getAlgoId(pKey)) || (MCUXCLKEY_SIZE_NOTUSED == mcuxClKey_getSize(pKey)) ||
       ((MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PUBLIC_KEY) != mcuxClKey_getAlgoId(pOtherKey) || (MCUXCLKEY_SIZE_NOTUSED == mcuxClKey_getSize(pOtherKey))) )
    {
       MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    /* Set up the environment */
    mcuxClEcc_MontDH_DomainParams_t *pDomainParameters = (mcuxClEcc_MontDH_DomainParams_t *)mcuxClKey_getTypeInfo(pKey);
    mcuxClEcc_CommonDomainParams_t *pCommonDomainParameters = &(pDomainParameters->common);

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

    /* Securely import private key d to PKC buffer ECC_S3 */
    const uint16_t * pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pPrivateKeyDest = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();
    MCUXCLKEY_LOAD_FP(
      pSession,
      key,
      &pPrivateKeyDest,
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
      NULL,
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
      MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE);

    /* Call mcuxClEcc_MontDH_X to calculate the public key q=MontDH_X(d,Gx) and store it in buffer MONT_X0. If the function returns NEUTRAL_POINT, return MCUXCLECC_STATUS_FAULT_ATTACK */
    uint8_t *pPublicKeyData = NULL;
    MCUXCLKEY_LOAD_FP(
      pSession,
      pOtherKey,
      &pPublicKeyData,
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
      NULL,
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
      MCUXCLKEY_ENCODING_SPEC_ACTION_PTR);

    MCUX_CSSL_FP_FUNCTION_CALL(retCode_MontDHx, mcuxClEcc_MontDH_X(pSession, pDomainParameters, (const uint8_t*)pPublicKeyData));
#if defined(MCUXCL_FEATURE_ECC_CURVE448)
    if(MCUXCLECC_INTSTATUS_SCALAR_ZERO == retCode_MontDHx)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_SCALAR_ZERO);
    } else if(MCUXCLECC_STATUS_NEUTRAL_POINT == retCode_MontDHx)
#else
    if(MCUXCLECC_STATUS_NEUTRAL_POINT == retCode_MontDHx)
#endif /* defined(MCUXCL_FEATURE_ECC_CURVE448) */
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_SMALL_SUBGROUP_ATTACK);
    }
    else if(MCUXCLECC_STATUS_OK != retCode_MontDHx)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Securely export shared secret from MONT_X0 */
        MCUXCLPKC_FP_SECUREEXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pOut, MONT_X0, keyLen);

        *pOutLength = keyLen;

        /* Import prime p and order n again, and check (compare with) existing one. */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(
            mcuxClEcc_IntegrityCheckPN(pSession, (mcuxClEcc_CommonDomainParams_t *) &pDomainParameters->common));

        /* Return OK and exit */
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_MontDH_KeyAgreement,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_X),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureExportLittleEndianFromPkc),
            MCUXCLKEY_LOAD_FP_CALLED(key),
            MCUXCLKEY_LOAD_FP_CALLED(pOtherKey),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
}

const mcuxClKey_AgreementDescriptor_t mcuxClKey_AgreementDescriptor_MontDH =
{
    .pAgreementFct = mcuxClEcc_MontDH_KeyAgreement,
    .protectionTokenAgreementFct = MCUX_CSSL_FP_FUNCID_mcuxClEcc_MontDH_KeyAgreement,
    .pProtocolDescriptor = NULL
};
