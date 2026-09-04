/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_KeyValidation.c
 * @brief mcuxClEcc: implementation of ECC related key validation functions
 */


#include <mcuxClKey.h>

#include <mcuxClEcc.h>
#include <internal/mcuxClEcc_Weier_Internal.h>

#include <internal/mcuxClEcc_Internal_KeyHelper.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Resource.h>

#include <internal/mcuxClSession_Internal.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_WeierECC_PublicKeyValidation, mcuxClKey_ValidationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClEcc_WeierECC_PublicKeyValidation(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t key)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_WeierECC_PublicKeyValidation);

    /**********************************************************/
    /* Check if key type is a Short Weierstrass public key.   */
    /**********************************************************/
    const mcuxClKey_AlgorithmId_t algorithmId = mcuxClKey_getAlgorithm(key);
    if( ( (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP != algorithmId)
                && (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM != algorithmId)
                && (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM != algorithmId) )
            || MCUXCLKEY_ALGO_ID_PUBLIC_KEY != mcuxClKey_getKeyUsage(key))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams = (mcuxClEcc_Weier_DomainParams_t *) mcuxClKey_getTypeInfo(key);

    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                    pEccWeierDomainParams,
                                    ECC_WEIERECC_PUBLICKEYVALIDATION_NO_OF_BUFFERS) );

    /**********************************************************/
    /* Check if x and y coordinates are smaller than p.       */
    /**********************************************************/

    uint16_t * pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pPublicKeyXCoordDest = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S0]);
    uint8_t *pPublicKeyYCoordDest = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T0]);

    mcuxClEcc_Weier_DomainParams_t *pDomainParams = (mcuxClEcc_Weier_DomainParams_t *) mcuxClKey_getTypeInfo(key);
    const uint32_t byteLenP = pDomainParams->common.byteLenP;

    /* Clear bytes on top of private key */
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(operandSize, byteLenP, UINT32_MAX, MCUXCLKEY_STATUS_FAULT_ATTACK);
    const uint32_t bytesToClear = operandSize - byteLenP;

    MCUX_CSSL_DI_RECORD(sumOfMemClearParamsX, &pPublicKeyXCoordDest[byteLenP]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParamsX, bytesToClear);
    MCUXCLMEMORY_CLEAR_INT(&pPublicKeyXCoordDest[byteLenP], bytesToClear);

    MCUX_CSSL_DI_RECORD(sumOfMemClearParamsY, &pPublicKeyYCoordDest[byteLenP]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParamsY, bytesToClear);
    MCUXCLMEMORY_CLEAR_INT(&pPublicKeyYCoordDest[byteLenP], bytesToClear);

    /* Import public key coordinates x and y into buffers ECC_S0 and ECC_T0. */
    MCUXCLKEY_LOAD_FP(pSession, key, &pPublicKeyXCoordDest, NULL, MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);

    /* Copy the y-coordinate to ECC_S1 to avoid that it gets overwritten by later point on curve checks */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_S1, ECC_T0, 0u);

    /* Check if x coordinate is smaller than p. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S0, ECC_P);
    if (MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLKEY_LOAD_FP_CALLED(key),
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /* Check if y coordinate is smaller than p. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S1, ECC_P);
    if (MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLKEY_LOAD_FP_CALLED(key),
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP * 2u,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /**********************************************************/
    /* Check if point is on curve.                            */
    /**********************************************************/

    /* Prepare UPTRT pointers for point check function */
    pOperands[WEIER_VX0] = pOperands[ECC_S0];
    pOperands[WEIER_VY0] = pOperands[ECC_S1];

    /* Check if point is on curve */
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckBasePointStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckBasePointStatus)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLKEY_LOAD_FP_CALLED(key),
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP * 2u,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
    else if (MCUXCLECC_STATUS_OK != pointCheckBasePointStatus)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing */
    }

    /* If none of the checks failed, return VALID. */
    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_PASSED,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUXCLKEY_LOAD_FP_CALLED(key),
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP * 2u,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_WeierECC_PrivateKeyValidation, mcuxClKey_ValidationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClEcc_WeierECC_PrivateKeyValidation(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t key)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_WeierECC_PrivateKeyValidation);

    /**********************************************************/
    /* Check if key type is a Short Weierstrass private key.  */
    /**********************************************************/
    const mcuxClKey_AlgorithmId_t algorithmId = mcuxClKey_getAlgorithm(key);
    if( ( (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP != algorithmId)
                && (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM != algorithmId)
                && (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM != algorithmId) )
        || (MCUXCLKEY_ALGO_ID_PRIVATE_KEY != mcuxClKey_getKeyUsage(key)))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /**********************************************************/
    /* Check the length of the private key                    */
    /**********************************************************/
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams = (mcuxClEcc_Weier_DomainParams_t *) mcuxClKey_getTypeInfo(key);
    const uint32_t privateKeyLen = mcuxClKey_getSize(key);
    const uint32_t basePointOrderLen = (uint32_t) pEccWeierDomainParams->common.byteLenN;
    if((privateKeyLen == 0u) || (basePointOrderLen < privateKeyLen))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PrivateKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED);
    }

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/
    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                    pEccWeierDomainParams,
                                    ECC_WEIERECC_PRIVATEKEYVALIDATION_NO_OF_BUFFERS));

    /**********************************************************/
    /* Check if the private key is nonzero and smaller than n */
    /**********************************************************/

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pPrivateKeyDest = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S0]);

    /* Clear bytes on top of private key */
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(operandSize, basePointOrderLen, UINT32_MAX, MCUXCLKEY_STATUS_FAULT_ATTACK);
    const uint32_t bytesToClear = operandSize - basePointOrderLen;
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, &pPrivateKeyDest[basePointOrderLen]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, bytesToClear);
    MCUXCLMEMORY_CLEAR_INT(&pPrivateKeyDest[basePointOrderLen], bytesToClear);

    /* Secure import private key */
    MCUXCLKEY_LOAD_FP(pSession, key, &pPrivateKeyDest, NULL, MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE);

    /* Check if the private key is nonzero */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_T0, ECC_S0, 0u);
    if(MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PrivateKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLKEY_LOAD_FP_CALLED(key),
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /* Check it the private key is smaller than n */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S0, ECC_N);
    if(MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PrivateKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
            MCUXCLKEY_LOAD_FP_CALLED(key),
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PrivateKeyValidation, MCUXCLKEY_STATUS_VALIDATION_PASSED,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUXCLKEY_LOAD_FP_CALLED(key),
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_ValidationDescriptor_t mcuxClKey_ValidationDesc_WeierECC_PublicKey = {
  .validateFct = mcuxClEcc_WeierECC_PublicKeyValidation,
  .validateFct_FP_FuncId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_PublicKeyValidation)
};

const mcuxClKey_ValidationDescriptor_t mcuxClKey_ValidationDesc_WeierECC_PrivateKey = {
  .validateFct = mcuxClEcc_WeierECC_PrivateKeyValidation,
  .validateFct_FP_FuncId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_PrivateKeyValidation)
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
