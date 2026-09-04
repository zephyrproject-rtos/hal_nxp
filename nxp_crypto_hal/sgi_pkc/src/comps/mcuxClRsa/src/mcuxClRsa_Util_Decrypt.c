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

/** @file  mcuxClRsa_Util_Decrypt.c
 *  @brief mcuxClRsa: implementation of RSA Decryption function
 */

#include <stdint.h>
#include <stdbool.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslDataIntegrity.h>

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
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <mcuxCsslAnalysis.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_Util_decrypt, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClRsa_Util_decrypt(
    mcuxClSession_Handle_t           pSession,
    mcuxClKey_Handle_t               key,
    mcuxClCipher_Mode_t              mode,
    mcuxCl_InputBuffer_t             pLabel,
    uint32_t                        labelLength,
    mcuxCl_InputBuffer_t             pIn,
    uint32_t                        inLength UNUSED_PARAM,
    mcuxCl_Buffer_t                  pOut,
    uint32_t * const                pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_Util_decrypt);

  MCUX_CSSL_DI_RECORD(verifyIn, (uint32_t) pIn);
  /* DI protect the Key parameters.
   * SREQI_RSA_0: algoId will be balanced in the call to mcuxClRsa_privatePlain() or mcuxClRsa_privateCrt() */
  MCUX_CSSL_DI_RECORD(verifyKey, mcuxClKey_getAlgoId(key) + mcuxClKey_getSize(key));

  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Initialize PKC */
  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, mcuxClRsa_Util_decrypt);

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
  /* Import the input                                  */
  /*****************************************************/

  const uint32_t keyBitLength = mcuxClKey_getSize(key);
  const uint32_t keyByteLength = keyBitLength / 8U;

  /* Allocate input buffer in PKC WA */
  uint32_t inputSizeWord  = MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(keyByteLength, mcuxClKey_getAlgoId(key)) / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pInput, mcuxClSession_allocateWords_pkcWa(pSession, inputSizeWord));

  /* Import the input to PKC RAM in little endian. DI for pInput will be balanced after the last usage of pInput. */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_reverse, pIn);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_reverse, keyByteLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_reverse(pIn, 0U, pInput, keyByteLength));
  MCUX_CSSL_DI_EXPUNGE(verifyIn, (uint32_t) pIn);

  /*****************************************************/
  /* Perform RSA private operation                     */
  /*****************************************************/

  /* Allocate encodedMessage buffer in CPU WA */
  const uint32_t cpuWaUsedWord = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(keyByteLength);
  const uint32_t encodedMessageSizeBytes = cpuWaUsedWord * sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pEncodedMessage, mcuxClSession_allocateWords_cpuWa(pSession, cpuWaUsedWord));

  /* Call the appropriate private key operation, based on the key type */
  MCUXCLBUFFER_INIT(pEncodedMessageBuf, NULL, pEncodedMessage, keyByteLength);
  mcuxClKey_AlgorithmId_t keyAlgoId = mcuxClKey_getAlgoId(key);
  if(MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN == keyAlgoId)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_privatePlain(pSession, key, (uint8_t *)pInput, pEncodedMessageBuf));
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_privateCRT(pSession, key, (uint8_t *)pInput, pEncodedMessageBuf));
  }

  /* DI: record pInput after usage */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_reverse, pInput);

  /* Recover pkc workarea */
  mcuxClSession_freeWords_pkcWa(pSession, inputSizeWord);

  /*****************************************************/
  /* Perform padding operation                         */
  /*****************************************************/

  /* Get the algorithm descriptor */
  mcuxClRsa_Cipher_AlgorithmDescriptor_t * pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) mode->pAlgorithm;

  /* Call the padding function */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_PaddingOperation, pAlgorithmDescriptor->pDecryptMode(
                              /* mcuxClSession_Handle_t       pSession,           */ pSession,
                              /* mcuxCl_InputBuffer_t         pInput,             */ pEncodedMessageBuf,
                              /* const uint32_t              inputLength,        */ keyByteLength,
                              /* mcuxCl_Buffer_t              pVerificationInput, */ NULL, /* unused */
                              /* mcuxClHash_Algo_t            pHashAlgo,          */ pAlgorithmDescriptor->pHashAlgo,
                              /* mcuxCl_InputBuffer_t         pLabel,             */ pLabel,
                              /* const uint32_t              saltlabelLength,    */ labelLength,
                              /* const uint32_t              keyBitLength,       */ keyBitLength,
                              /* const uint32_t              options,            */ 0U, /* unused */
                              /* mcuxCl_Buffer_t              pOutput             */ pOut,
                              /* uint32_t * const            pOutLength          */ pOutLength
  ));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
  MCUX_CSSL_DI_EXPUNGE(verifyKey, keyBitLength);

  /* Clear buffer pEncodedMessage */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pEncodedMessage, encodedMessageSizeBytes));

  if(MCUXCLRSA_STATUS_INVALID_INPUT == retVal_PaddingOperation)
  {
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaUsedWord);

    MCUXCLSESSION_ERROR(pSession, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }
  else if(MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK != retVal_PaddingOperation)
  {
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaUsedWord);

    MCUXCLSESSION_ERROR(pSession, MCUXCLCIPHER_STATUS_ERROR);
  }
  else
  {
    /* Left empty intentionally */
  }


  /*****************************************************/
  /* Clean up and exit                                 */
  /*****************************************************/

  /* Free Math UPTRT allocated WA */
  mcuxClSession_freeWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t));

  MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

  mcuxClSession_freeWords_cpuWa(pSession, cpuWaUsedWord);

  MCUX_CSSL_DI_RECORD(cipherDecryptRetCode , MCUXCLCIPHER_STATUS_OK);
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Util_decrypt, MCUXCLCIPHER_STATUS_OK,
    MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_reverse),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN == mcuxClKey_getAlgoId(key)),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_privatePlain)),
    MCUX_CSSL_FP_CONDITIONAL(((MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT == mcuxClKey_getAlgoId(key))
                      || (MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA == mcuxClKey_getAlgoId(key))),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_privateCRT)),
    pAlgorithmDescriptor->decrypt_FunId,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}
