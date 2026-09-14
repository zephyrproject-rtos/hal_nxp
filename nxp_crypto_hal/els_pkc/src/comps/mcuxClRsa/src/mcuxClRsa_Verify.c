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

/** @file  mcuxClRsa_Verify.c
 *  @brief mcuxClRsa: implementation of RSA Verify function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClPkc.h>
#include <mcuxClRsa.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_verify)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_verify(
  mcuxClSession_Handle_t           pSession,
  const mcuxClRsa_Key * const      pKey,
  mcuxCl_InputBuffer_t             pMessageOrDigest,
  const uint32_t                  messageLength,
  mcuxCl_Buffer_t                  pSignature,
  const mcuxClRsa_SignVerifyMode   pVerifyMode,
  const uint32_t                  saltLength,
  const uint32_t                  options,
  mcuxCl_Buffer_t                  pOutput
  )
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_verify);

  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Locate paddedMessage buffer at beginning of PKC WA and update session info */
  const uint32_t modulusByteLength = pKey->pMod1->keyEntryLength;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(modulusByteLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t pkcWaSizeWord = MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(modulusByteLength) / (sizeof(uint32_t));

  uint8_t * pPaddedMessage = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord);
  if (NULL == pPaddedMessage)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_verify, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /* Initialize PKC */
  const uint32_t cpuWaSizeWord = (sizeof(mcuxClPkc_State_t)) / (sizeof(uint32_t));
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  mcuxClPkc_State_t * pkcStateBackup = (mcuxClPkc_State_t *) mcuxClSession_allocateWords_cpuWa(pSession, cpuWaSizeWord);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
  if (NULL == pkcStateBackup)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_verify, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, pkcStateBackup, mcuxClRsa_verify, MCUXCLRSA_STATUS_FAULT_ATTACK);

  /*****************************************************/
  /* Perform RSA_public                                */
  /*****************************************************/

  MCUX_CSSL_FP_FUNCTION_CALL(retVal_RsaPublic, mcuxClRsa_public(pSession, pKey, pSignature, pPaddedMessage));

  if(MCUXCLRSA_STATUS_INVALID_INPUT == retVal_RsaPublic)
  {
    /* De-initialize PKC */
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup, mcuxClRsa_verify, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_verify, MCUXCLRSA_STATUS_INVALID_INPUT,
                              MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_public),
                              MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
  }
  else if(MCUXCLRSA_STATUS_INTERNAL_KEYOP_OK != retVal_RsaPublic)
  {

    /* De-initialize PKC */
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup, mcuxClRsa_verify, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_verify, MCUXCLRSA_STATUS_ERROR);
  }
  else
  {

    /*****************************************************/
    /* Perform padding operation                         */
    /*****************************************************/

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(modulusByteLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
    const uint32_t keyBitLength = 8u * modulusByteLength;

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL(retVal_PaddingOperation, pVerifyMode->pPaddingFunction(pSession,
                                                                                     pMessageOrDigest,
                                                                                     messageLength,
                                                                                     pPaddedMessage,
                                                                                     pVerifyMode->pHashAlgo1,
                                                                                     NULL,
                                                                                     saltLength,
                                                                                     keyBitLength,
                                                                                     options,
                                                                                     pOutput,
                                                                                     NULL));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    /*****************************************************/
    /* Exit                                              */
    /*****************************************************/

    /* De-initialize PKC */
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup, mcuxClRsa_verify, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRsa_verify, retVal_PaddingOperation,
                    MCUXCLRSA_STATUS_FAULT_ATTACK,
                    MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_public),
                    pVerifyMode->EncodeVerify_FunId,
                    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
  }
}
