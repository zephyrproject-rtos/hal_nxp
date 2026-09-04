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

/** @file  mcuxClRsa_Util_Encrypt.c
 *  @brief mcuxClRsa: implementation of RSA Encryption function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <mcuxClCipher_Constants.h>
#include <mcuxClCipher_Types.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClHash.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClPrng_Internal_Functions.h>
#include <internal/mcuxClMath_Internal.h>

#include <mcuxClRsa.h>

#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_Util_encrypt, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClRsa_Util_encrypt(
    mcuxClSession_Handle_t           pSession,
    mcuxClKey_Handle_t               key,
    mcuxClCipher_Mode_t              mode,
    mcuxCl_InputBuffer_t             pLabel,
    uint32_t                        labelLength,
    mcuxCl_InputBuffer_t             pIn,
    uint32_t                        inLength,
    mcuxCl_Buffer_t                  pOut,
    uint32_t * const                pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_Util_encrypt);

  /*****************************************************/
  /* Verification of the key                           */
  /*****************************************************/

  /* Check key size */ //TODO CLNS-9134: It should be clarified whether the check is needed - then it would also apply to private keys
  uint32_t keyBitLength = mcuxClKey_getSize(key);
  const uint32_t keyByteLength = keyBitLength / 8U;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicitly reinterpreting opaque types of workarea-like buffer objects. Key data should be word-aligned.")
  mcuxClRsa_KeyData_Plain_t * pRsaKeyData = (mcuxClRsa_KeyData_Plain_t *) mcuxClKey_getKeyData(key);
  if(keyByteLength != pRsaKeyData->modulus.keyEntryLength)
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Initialize PKC */
  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, mcuxClRsa_Util_encrypt);

  /* The CPU WA layout is:
  * +-------------+------------------------+
  * | Math UPTRT  | RSA Allocated Memory   |
  * +-------------+------------------------+
  */
  /* Setup mcuxClMath UPTRT buffer at beginning of PKC/CPU depending on MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM and update session info */
  MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pMathUptrt, mcuxClSession_allocateWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t)));
  /* Update session info for pMathUptrt location in PKC WA */
  pSession->pMathUptrt = pMathUptrt;

  /*****************************************************/
  /* Perform padding operation                         */
  /*****************************************************/

  /* Get the algorithm descriptor */
  mcuxClRsa_Cipher_AlgorithmDescriptor_t * pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) mode->pAlgorithm;

  /* Allocate paddedMessage buffer in PKC WA */
  const uint32_t paddedMessageSize = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength);
  uint32_t pkcWaUsedWord = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPaddedMessage, mcuxClSession_allocateWords_pkcWa(pSession, pkcWaUsedWord));

  /* Call the padding function */
  MCUXCLBUFFER_INIT(pPaddedMessageBuf, NULL, pPaddedMessage, keyByteLength);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_PaddingOperation, pAlgorithmDescriptor->pEncryptMode(
                              /* mcuxClSession_Handle_t       pSession,           */ pSession,
                              /* mcuxCl_InputBuffer_t         pInput,             */ pIn,
                              /* const uint32_t              inputLength,        */ inLength,
                              /* mcuxCl_Buffer_t              pVerificationInput, */ NULL, /* unused */
                              /* mcuxClHash_Algo_t            pHashAlgo,          */ pAlgorithmDescriptor->pHashAlgo,
                              /* mcuxCl_InputBuffer_t         pLabel,             */ pLabel,
                              /* const uint32_t              saltlabelLength,    */ labelLength,
                              /* const uint32_t              keyBitLength,       */ keyBitLength,
                              /* const uint32_t              options,            */ 0U, /* unused */
                              /* mcuxCl_Buffer_t              pOutput             */ pPaddedMessageBuf,
                              /* uint32_t * const            pOutLength          */ NULL /* unused */
  ));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()

  if(MCUXCLRSA_STATUS_INVALID_INPUT == retVal_PaddingOperation)
  {
    /* Clear buffer pPaddedMessage */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pPaddedMessage, paddedMessageSize));
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaUsedWord);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);
    MCUXCLSESSION_ERROR(pSession, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }
  else if(MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK != retVal_PaddingOperation)
  {
    /* Clear buffer pPaddedMessage */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pPaddedMessage, paddedMessageSize));
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaUsedWord);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    MCUXCLSESSION_ERROR(pSession, MCUXCLCIPHER_STATUS_ERROR);
  }
  else
  {
    /* Left empty intentionally */
  }

  /*****************************************************/
  /* Perform RSA public operation                     */
  /*****************************************************/

  /* Allocate output buffer in PKC WA */
  const uint32_t outSizeWord = MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_OUTPUT_BUFF_WAPKC_SIZE_IN_WORDS(keyByteLength);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pOutPublic, mcuxClSession_allocateWords_pkcWa(pSession, outSizeWord));

  pkcWaUsedWord += outSizeWord;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_public(pSession, key, pPaddedMessageBuf, pOutPublic));

  /* Clear buffer pPaddedMessage */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pPaddedMessage, paddedMessageSize));


  /*****************************************************/
  /* Export the encrypted data.                        */
  /*****************************************************/

  /* Export the output, which is located in PKC workarea in little endian. */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_reverse, pOut);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_reverse, pOutPublic);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_reverse, keyByteLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write_reverse(pOut, 0U, pOutPublic, keyByteLength));

  /* Clean up */
  mcuxClSession_freeWords_pkcWa(pSession, pkcWaUsedWord);
  MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

  /* Free Math UPTRT allocated WA */
  mcuxClSession_freeWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t));

  /* Set the number of bytes of encrypted data that have been written to the pOut */
  *pOutLength = keyByteLength;

  /*****************************************************/
  /* Exit                                              */
  /*****************************************************/

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Util_encrypt, MCUXCLCIPHER_STATUS_OK,
    MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    pAlgorithmDescriptor->encrypt_FunId,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_public),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write_reverse),
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}
