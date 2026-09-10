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

/** @file  mcuxClRsa_Sign.c
 *  @brief mcuxClRsa: implementation of RSA Sign function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClHash.h>
#include <mcuxClPkc.h>
#include <mcuxClMath.h>
#include <mcuxClMemory.h>
#include <mcuxClBuffer.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClKey_Internal.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>

/**
 * @brief This function calculates the key length in bits and the total size of the pkc workspace
 *
 * \param[in/out]   pkcWaTotalSize  Pointer to total size of the pkc work area
 * \param[in/out]  pKeyBitLength   Pointer to return key bit lenght
 *
 * @return statusCode
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_sign_Key_To_WorkAreaSize)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_sign_Key_To_WorkAreaSize(
    const mcuxClRsa_Key * const      pKey,
    uint32_t *                      pkcWaTotalSize,
    uint32_t *                      pKeyBitLength
  )
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_sign_Key_To_WorkAreaSize);

  if(MCUXCLRSA_KEY_PRIVATEPLAIN == pKey->keytype)
  {
    *pKeyBitLength = 8u * (pKey->pMod1->keyEntryLength);
    *pkcWaTotalSize = MCUXCLRSA_SIGN_PLAIN_WAPKC_SIZE(*pKeyBitLength);
  }
  else if((MCUXCLRSA_KEY_PRIVATECRT == pKey->keytype) || (MCUXCLRSA_KEY_PRIVATECRT_DFA == pKey->keytype))
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_Calc_Modlen_From_CRTkey(pKey, pKeyBitLength));
    *pkcWaTotalSize = MCUXCLRSA_SIGN_CRT_WAPKC_SIZE(*pKeyBitLength);
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign_Key_To_WorkAreaSize, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign_Key_To_WorkAreaSize, MCUXCLRSA_STATUS_SIGN_OK,
                              MCUX_CSSL_FP_CONDITIONAL(((MCUXCLRSA_KEY_PRIVATECRT == pKey->keytype) || (MCUXCLRSA_KEY_PRIVATECRT_DFA == pKey->keytype)),
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Calc_Modlen_From_CRTkey)));
}

/**
 * @brief This function perform RSA private operation
 *
 * \param[in]       pSession            Pointer to #mcuxClSession_Descriptor
 * \param[in]       pKey                Pointer to key structure of type @ref mcuxClRsa_Key
 * \param[in]       pPaddedMessage      Pointer to padded message
 * \param[in/out]   pSignature          Pointer to signature
 *
 * @return statusCode
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_sign_RSA_private)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_sign_RSA_private(
  mcuxClSession_Handle_t           pSession,
  const mcuxClRsa_Key * const      pKey,
  uint8_t *                       pPaddedMessage,
  mcuxCl_Buffer_t                  pSignature
  )
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_sign_RSA_private);
  /*****************************************************/
  /* Perform RSA private operation                     */
  /*****************************************************/
  uint32_t retVal_RsaPrivate = MCUXCLRSA_STATUS_ERROR;

  if(MCUXCLRSA_KEY_PRIVATEPLAIN == pKey->keytype)
  {
    MCUX_CSSL_FP_FUNCTION_CALL(retVal_RsaPrivatePlain, mcuxClRsa_privatePlain(pSession, pKey, pPaddedMessage, pSignature));
    retVal_RsaPrivate = retVal_RsaPrivatePlain;
  }
  else if((MCUXCLRSA_KEY_PRIVATECRT == pKey->keytype) || (MCUXCLRSA_KEY_PRIVATECRT_DFA == pKey->keytype))
  {
    MCUX_CSSL_FP_FUNCTION_CALL(retVal_RsaPrivateCrt, mcuxClRsa_privateCRT(pSession, pKey, pPaddedMessage, pSignature));
    retVal_RsaPrivate = retVal_RsaPrivateCrt;
  }
  else /* Key type has already been tested: any other type here is a fault */
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign_RSA_private, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign_RSA_private, retVal_RsaPrivate,
                  MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_KEY_PRIVATEPLAIN == pKey->keytype),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_privatePlain)),
                  MCUX_CSSL_FP_CONDITIONAL(((MCUXCLRSA_KEY_PRIVATECRT == pKey->keytype) || (MCUXCLRSA_KEY_PRIVATECRT_DFA == pKey->keytype)),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_privateCRT))
                  );

}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_sign)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_sign(
  mcuxClSession_Handle_t           pSession,
  const mcuxClRsa_Key * const      pKey,
  mcuxCl_InputBuffer_t             pMessageOrDigest,
  const uint32_t                  messageLength,
  const mcuxClRsa_SignVerifyMode   pPaddingMode,
  const uint32_t                  saltLength,
  const uint32_t                  options,
  mcuxCl_Buffer_t                  pSignature
  )
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_sign);

  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Initialize PKC */
  uint32_t cpuWaUsedWord = sizeof(mcuxClPkc_State_t) / sizeof(uint32_t);
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  mcuxClPkc_State_t * pkcStateBackup = (mcuxClPkc_State_t *) mcuxClSession_allocateWords_cpuWa(pSession, cpuWaUsedWord);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
  if (NULL == pkcStateBackup)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, pkcStateBackup, mcuxClRsa_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);

  uint32_t pkcWaTotalSize = 0u;
  uint32_t keyBitLength = 0u;

  MCUX_CSSL_FP_FUNCTION_CALL(retVal_Key_To_WorkAreaSize, mcuxClRsa_sign_Key_To_WorkAreaSize(
                            /* const mcuxClRsa_Key * const    pKey,           */ pKey,
                            /* uint32_t *                    pkcWaTotalSize  */ &pkcWaTotalSize,
                            /* uint32_t *                    keyBitLength,   */ &keyBitLength
  ));

  if (MCUXCLRSA_STATUS_SIGN_OK != retVal_Key_To_WorkAreaSize)
  {
    /* De-initialize PKC */
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup, mcuxClRsa_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);
    mcuxClSession_freeWords_cpuWa(pSession, cpuWaUsedWord);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, retVal_Key_To_WorkAreaSize,
                              MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_sign_Key_To_WorkAreaSize),
                              MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
  }


  /* Locate paddedMessage buffer at beginning of PKC WA and update session info */
  uint32_t keyByteLength = keyBitLength / 8u;
  uint32_t pkcWaUsedByte = (MCUXCLRSA_KEY_PRIVATEPLAIN == pKey->keytype) ? MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength) : MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength);
  uint8_t * const pPkcWorakarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, pkcWaUsedByte / (sizeof(uint32_t)));
  if (NULL == pPkcWorakarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /*****************************************************/
  /* Perform padding operation                         */
  /*****************************************************/
  uint8_t * pPaddedMessage = pPkcWorakarea;

  MCUXCLBUFFER_INIT(pPaddedMessageBuf, NULL, pPaddedMessage, pkcWaUsedByte);
  /* Call the padding function */
  MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("pPaddingMode->pPaddingFunction is never NULL")
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_PaddingOperation, pPaddingMode->pPaddingFunction(
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
                              /* mcuxClSession_Handle_t       pSession,           */ pSession,
                              /* mcuxCl_InputBuffer_t         pInput,             */ pMessageOrDigest,
                              /* const uint32_t              inputLength,        */ messageLength,
                              /* mcuxCl_Buffer_t              pVerificationInput, */ NULL,
                              /* mcuxClHash_Algo_t            pHashAlgo,          */ pPaddingMode->pHashAlgo1,

                              /* const uint8_t *             pLabel,             */ NULL,
                              /* const uint32_t              saltlabelLength,    */ saltLength,
                              /* const uint32_t              keyBitLength,       */ keyBitLength,
                              /* const uint32_t              options,            */ options,
                              /* mcuxCl_Buffer_t              pOutput             */ pPaddedMessageBuf,
                              /* uint32_t * const            pOutLength          */ NULL
  ));
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

  if(MCUXCLRSA_STATUS_INVALID_INPUT == retVal_PaddingOperation)
  {
    /* De-initialize PKC */
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaUsedByte / (sizeof(uint32_t)));
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup, mcuxClRsa_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaUsedWord);

    /* Clear pkcWa */
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pPkcWorakarea,pkcWaTotalSize);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, MCUXCLRSA_STATUS_INVALID_INPUT,
                              MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_sign_Key_To_WorkAreaSize),
                              pPaddingMode->EncodeVerify_FunId,
                              MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE,
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
  }
  else if(MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK != retVal_PaddingOperation)
  {
    /* De-initialize PKC */
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaUsedByte / (sizeof(uint32_t)));
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup, mcuxClRsa_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaUsedWord);

    /* Clear pkcWa */
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pPkcWorakarea,pkcWaTotalSize);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, MCUXCLRSA_STATUS_ERROR);
  }
  else
  {
    if (pkcWaUsedByte > keyByteLength)
    {
      /* Clear PKC workarea after the input */
      MCUXCLMEMORY_FP_MEMORY_CLEAR(pPaddedMessage + keyByteLength, pkcWaUsedByte - keyByteLength);
    }

    /*****************************************************/
    /* Perform RSA private operation                     */
    /*****************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL(retVal_RsaPrivate, mcuxClRsa_sign_RSA_private(
                                /* mcuxClSession_Handle_t         pSession,       */ pSession,
                                /* const mcuxClRsa_Key * const    pKey,           */ pKey,
                                /* uint8_t *                     pPaddedMessage, */ pPaddedMessage,
                                /* mcuxCl_Buffer_t                pSignature,     */ pSignature
    ));

    /*****************************************************/
    /* Exit                                              */
    /*****************************************************/

    /* De-initialize PKC */
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaUsedByte / (sizeof(uint32_t)));
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup, mcuxClRsa_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaUsedWord);

    /* Clear pkcWa */
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pPkcWorakarea,pkcWaTotalSize);

   /* Check return value */
    if(MCUXCLRSA_STATUS_INVALID_INPUT == retVal_RsaPrivate)
    {
       MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, MCUXCLRSA_STATUS_INVALID_INPUT,
                                MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_sign_Key_To_WorkAreaSize),
                                pPaddingMode->EncodeVerify_FunId,
                                MCUX_CSSL_FP_CONDITIONAL((pkcWaUsedByte > keyByteLength),
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)),
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_sign_RSA_private),
                                MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE,
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
    }
    else if(MCUXCLRSA_STATUS_INTERNAL_KEYOP_OK != retVal_RsaPrivate)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, MCUXCLRSA_STATUS_ERROR);
    }
    else
    {
      MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRsa_sign, MCUXCLRSA_STATUS_SIGN_OK,
                      MCUXCLRSA_STATUS_FAULT_ATTACK,
                      MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
                      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_sign_Key_To_WorkAreaSize),
                      pPaddingMode->EncodeVerify_FunId,
                      MCUX_CSSL_FP_CONDITIONAL((pkcWaUsedByte > keyByteLength),
                      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)),
                      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_sign_RSA_private),
                      MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE,
                      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
    }
  }
}
