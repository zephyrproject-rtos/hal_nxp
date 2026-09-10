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
 * @file  mcuxClEcc_KeyValidation.c
 * @brief mcuxClEcc: implementation of ECC related key validation functions
 */


#include <mcuxClKey.h>

#include <mcuxClEcc.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_WeierEcc_KeyValidate_Internal.h>

#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>
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
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams = (mcuxClEcc_Weier_DomainParams_t *) mcuxClKey_getTypeInfo(key);

    mcuxClEcc_CpuWa_t * const pCpuWorkarea = mcuxClEcc_castToEccCpuWorkarea(mcuxClSession_getCpuWaBuffer(pSession));

    MCUX_CSSL_FP_FUNCTION_CALL(ret_SetupEnvironment,
        mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                           pEccWeierDomainParams,
                                           ECC_WEIERECC_PUBLICKEYVALIDATION_NO_OF_BUFFERS) );
    if (MCUXCLECC_STATUS_OK != ret_SetupEnvironment)
    {
        MCUXCLECC_HANDLE_HW_UNAVAILABLE(ret_SetupEnvironment, mcuxClEcc_WeierECC_PublicKeyValidation);

        /* Session has been cleaned, PKC has been deinitialized in SetupEnvironment. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_INVALID_INPUT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment) );
    }

    /**********************************************************/
    /* Check if x and y coordinates are smaller than p.       */
    /**********************************************************/
    uint32_t byteLenP = pEccWeierDomainParams->common.byteLenP;
    uint8_t * pPublicKey = mcuxClKey_getKeyData(key);

    /* Import and check if x coordinate is smaller than p. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC(ECC_S0, pPublicKey, byteLenP);
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S0, ECC_P);
    if (MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /* Import and check if y coordinate is smaller than p. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC(ECC_S1, pPublicKey + byteLenP, byteLenP);
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S1, ECC_P);
    if (MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc) * 2u,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP * 2u,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /**********************************************************/
    /* Check if point is on curve.                            */
    /**********************************************************/

    /* Prepare UPTRT pointers for point check function */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    pOperands[WEIER_VX0] = pOperands[ECC_S0];
    pOperands[WEIER_VY0] = pOperands[ECC_S1];

    /* Check if point is on curve */
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckBasePointStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckBasePointStatus)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_FAILED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc) * 2u,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP * 2u,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
    else if (MCUXCLECC_STATUS_OK != pointCheckBasePointStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PrivateKeyValidation, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing */
    }

    /* If none of the checks failed, return VALID. */
    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
        mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLECC_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_PublicKeyValidation, MCUXCLKEY_STATUS_VALIDATION_PASSED,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc) * 2u,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP * 2u,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()



