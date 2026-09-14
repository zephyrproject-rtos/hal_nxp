/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClOsccaCipherModes_SM4_Crypt.c
 *  @brief implementation of the Skeleton functions of the mcuxClOsccaCipherModes component */

#include <mcuxClMemory.h>
#include <mcuxClOscca_Memory.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <mcuxClKey.h>
#include <mcuxClPadding.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClOsccaCipherModes_Internal_Types.h>
#include <internal/mcuxClOsccaCipherModes_Internal_Functions.h>
#include <internal/mcuxClOsccaCipherModes_Algorithms.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaCipherModes_SkeletonSM4, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClOsccaCipherModes_SkeletonSM4(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t pKey,
  mcuxClCipher_Mode_t pMode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  uint32_t steps //!< steps is a bitmask with one bit reserved for each of the steps below
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaCipherModes_SkeletonSM4);

    /* Correct Context type for SM4 Skeleton */
    mcuxClOsccaCipherModes_Context_Sm4_t * pCtx = NULL;
    if(MCUXCLCIPHER_OPTION_ONESHOT == steps)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(oneShotResult, mcuxClOsccaCipherModes_SkeletonSM4_OneShot(session, pKey, pMode, pIv, ivLength, pIn, inLength, pOut, pOutLength));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaCipherModes_SkeletonSM4, oneShotResult,
                                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaCipherModes_SkeletonSM4_OneShot));
    }
    else
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for mcuxClOsccaCipherModes_Context_Sm4_t types")
        pCtx = (mcuxClOsccaCipherModes_Context_Sm4_t *) pContext;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    }

    if (MCUXCLCIPHER_OPTION_INIT == steps)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("pCtx has been casted to mcuxClOsccaCipherModes_Context_Sm4_t* type")
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOsccaCipherModes_SkeletonSM4_Pre(pCtx, pMode));
        MCUX_CSSL_FP_FUNCTION_CALL(initResult, mcuxClOsccaCipherModes_SkeletonSM4_Init(pCtx, pKey, pIv, ivLength));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaCipherModes_SkeletonSM4, initResult,
                                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaCipherModes_SkeletonSM4_Pre),
                                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaCipherModes_SkeletonSM4_Init));
    }

    if (MCUXCLCIPHER_OPTION_PROCESS == steps)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("pCtx has been casted to mcuxClOsccaCipherModes_Context_Sm4_t* type")
        MCUX_CSSL_FP_FUNCTION_CALL(processResult, mcuxClOsccaCipherModes_SkeletonSM4_Process(pCtx, pIn, inLength, pOut, pOutLength));
        if (MCUXCLCIPHER_STATUS_OK != processResult)
        {
            MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)pCtx, sizeof(mcuxClOsccaCipherModes_Context_Sm4_t));
        }
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaCipherModes_SkeletonSM4, processResult,
                                           MCUX_CSSL_FP_CONDITIONAL(MCUXCLCIPHER_STATUS_OK != processResult, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)),
                                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaCipherModes_SkeletonSM4_Process));
    }

    if (MCUXCLCIPHER_OPTION_FINISH == steps)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("pCtx has been casted to mcuxClOsccaCipherModes_Context_Sm4_t* type")
        MCUX_CSSL_FP_FUNCTION_CALL(finishResult, mcuxClOsccaCipherModes_SkeletonSM4_Finish(pCtx, pOut, pOutLength));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

        MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)pCtx, sizeof(mcuxClOsccaCipherModes_Context_Sm4_t));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaCipherModes_SkeletonSM4, finishResult,
                                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
                                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaCipherModes_SkeletonSM4_Finish));
    }

    /* Exit and balance the flow protection. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaCipherModes_SkeletonSM4, MCUXCLCIPHER_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_NoPadding = {
/* [Design]
    mcuxClPadding_addPadding_None
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_None,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_None),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_ECB,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingISO9797_1_Method1 = {
/* [Design]
    mcuxClPadding_addPadding_ISO9797_1_Method1
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_ISO9797_1_Method1,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method1),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_ECB,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingISO9797_1_Method2 = {
/* [Design]
    mcuxClPadding_addPadding_ISO9797_1_Method2
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_ISO9797_1_Method2,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_ECB,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};
const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingPKCS7 = {
/* [Design]
    mcuxClPadding_addPadding_PKCS7
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_PKCS7,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_PKCS7),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_ECB,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Dec = {
/* [Design]
    mcuxClPadding_addPadding_None
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_None,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_None),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_ECB,
    .direction = MCUXCLOSCCACIPHER_DECRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_NoPadding = {
/* [Design]
    mcuxClPadding_addPadding_None
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_None,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_None),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CBC,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingISO9797_1_Method1 = {
/* [Design]
    mcuxClPadding_addPadding_ISO9797_1_Method1
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_ISO9797_1_Method1,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method1),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CBC,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingISO9797_1_Method2 = {
/* [Design]
    mcuxClPadding_addPadding_ISO9797_1_Method2
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_ISO9797_1_Method2,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CBC,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingPKCS7= {
/* [Design]
    mcuxClPadding_addPadding_PKCS7
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_PKCS7,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_PKCS7),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CBC,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Dec = {
/* [Design]
    mcuxClPadding_addPadding_None
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_None,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_None),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CBC,
    .direction = MCUXCLOSCCACIPHER_DECRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CTR_Enc = {
/* [Design]
    mcuxClPadding_addPadding_Random
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_Random,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_Random),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CTR,
    .direction = MCUXCLOSCCACIPHER_ENCRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};

const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CTR_Dec = {
/* [Design]
    mcuxClPadding_addPadding_Random
    granularity = 16
*/
    .addPadding = mcuxClPadding_addPadding_Random,
    .protection_token_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_Random),
    .mode = MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CTR,
    .direction = MCUXCLOSCCACIPHER_DECRYPT,
    .blockLength = MCUXCLOSCCASM4_BLOCK_SIZE,
    .granularity = 16u
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

