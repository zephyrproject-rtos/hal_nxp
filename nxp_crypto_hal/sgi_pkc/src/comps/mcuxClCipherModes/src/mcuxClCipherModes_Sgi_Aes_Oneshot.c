/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClCipherModes_MemoryConsumption.h>
#include <mcuxClKey.h>
#include <mcuxClMemory_Copy.h>
#include <mcuxClSession.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Cleanup.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>


#include <internal/mcuxClCrc_Internal_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_encrypt_Sgi, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_encrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t pKey,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_encrypt_Sgi);

  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(mode->pAlgorithm);

  /* Return INVALID_INPUT if inLength doesn't meet the required granularity */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->checkIvLength(session, ivLength));
  if(0U != (inLength % pAlgo->granularityEnc))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

  /* Return INVALID_INPUT if inLength is too large to apply the needed padding */
  if((pAlgo->addPadding != mcuxClPadding_addPadding_None) &&
    (MCUXCLCORE_ALIGN_TO_WORDSIZE(MCUXCLAES_BLOCK_SIZE, inLength) > (UINT32_MAX - MCUXCLAES_BLOCK_SIZE)))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  mcuxClKey_KeyChecksum_t keyChecksums;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
  pWa->sgiWa.pKeyChecksums = &keyChecksums;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

  /* Initialize/request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load key to SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKey_Sgi(session, pKey, &pWa->sgiWa, MCUXCLSGI_DRV_KEY0_OFFSET));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->setupIVEncrypt(session, pWa, pIv)); /* Load IV if needed, do nothing otherwise */

  MCUXCLBUFFER_DERIVE_RO(pInCur, pIn, 0U);
  MCUXCLBUFFER_DERIVE_RW(pOutCur, pOut, 0U);
  uint32_t outputBytesWritten = 0U;

  uint32_t remainingBytes = inLength;

  /* Process all full blocks */
  if(MCUXCLAES_BLOCK_SIZE <= remainingBytes)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
      session,
      pWa,
      pInCur,
      pOutCur,
      inLength,
      pWa->pIV,
      &outputBytesWritten,
      pWa->sgiWa.pKeyChecksums,
      pAlgo->encryptEngine,
      pAlgo->protectionToken_encryptEngine));

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(outputBytesWritten, 0U, remainingBytes, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
    /* Move input and output pointers */
    MCUXCLBUFFER_UPDATE(pInCur, outputBytesWritten);
    MCUXCLBUFFER_UPDATE(pOutCur, outputBytesWritten);

    remainingBytes -= outputBytesWritten;
  }

  /* Check if padding needs to be applied, and if yes store the padded last block in the padding buffer */
  uint32_t paddingOutputSize = 0U;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_ARRAY_OUT_OF_BOUNDS("The remainingBytes is always less than 16, and hence access to the paddingBuff does not overrun")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->addPadding(
    session,
    MCUXCLAES_BLOCK_SIZE,
    pInCur,
    0U,
    remainingBytes,
    inLength,
    pWa->sgiWa.paddingBuff,
    &paddingOutputSize));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_ARRAY_OUT_OF_BOUNDS()

  MCUXCLBUFFER_INIT(paddingBuf, session, pWa->sgiWa.paddingBuff, paddingOutputSize);
  /* Process last (padded) block and store the result in the padding buffer */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
    session,
    pWa,
    paddingBuf,
    pOutCur,
    paddingOutputSize,
    NULL,
    &outputBytesWritten,
    pWa->sgiWa.pKeyChecksums,
    pAlgo->encryptEngine,
    pAlgo->protectionToken_encryptEngine));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("outputBytesWritten does not cause overflow as it depends on inLength verified at the function entry")
  /* Update the output length and clean-up the session */
  *pOutLength += outputBytesWritten;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit(session, NULL, pKey, cpuWaSizeInWords));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_encrypt_Sgi, MCUXCLCIPHER_STATUS_OK,
                            pAlgo->protectionToken_checkIvLength,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
                            pAlgo->protectionToken_setupIVEncrypt,
                            MCUX_CSSL_FP_CONDITIONAL(MCUXCLAES_BLOCK_SIZE <= inLength,
                                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt)),
                            pAlgo->protectionToken_addPadding,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit)
                            );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_decrypt_Sgi_CheckInputs)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_decrypt_Sgi_CheckInputs(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo,
  const uint32_t ivLength,
  const uint32_t inLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_decrypt_Sgi_CheckInputs);

  /* Return INVALID_INPUT if inLength is zero for block cipher decryption or doesn't meet the required granularity */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->checkIvLength(session, ivLength));
  if(((0U == inLength) && (1U != pAlgo->granularityDec)) ||
     (0U != inLength % pAlgo->granularityDec))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_decrypt_Sgi_CheckInputs,
                                 pAlgo->protectionToken_checkIvLength);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_decrypt_Sgi, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_decrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t pKey,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_decrypt_Sgi);

  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(mode->pAlgorithm);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_decrypt_Sgi_CheckInputs(session, pAlgo, ivLength, inLength));

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  mcuxClKey_KeyChecksum_t keyChecksums;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
  pWa->sgiWa.pKeyChecksums = &keyChecksums;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load key to SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKey_Sgi(session, pKey, &pWa->sgiWa, MCUXCLSGI_DRV_KEY0_OFFSET));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->setupIVDecrypt(session, pWa, pIv)); /* Load IV if needed, do nothing otherwise */

  MCUXCLBUFFER_DERIVE_RO(pInCur, pIn, 0U);
  MCUXCLBUFFER_DERIVE_RW(pOutCur, pOut, 0U);
  uint32_t outputBytesWritten = 0U;

  uint32_t remainingBytes = inLength;

  uint32_t size;
  if((pAlgo->granularityDec == 1U) || (NULL == pAlgo->removePadding))
  {
    /* In the case of stream ciphers or when padding is set to "none", all full blocks can be processed immediately */
    size = (inLength / MCUXCLAES_BLOCK_SIZE) * MCUXCLAES_BLOCK_SIZE;
  }
  else
  {
    /* Round down to block size, if the last block is full it will not be considered here to be able to remove the padding later. */
    size = (inLength - 1U) & ~(MCUXCLAES_BLOCK_SIZE - 1U);
  }

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
    session,
    pWa,
    pInCur,
    pOutCur,
    size,
    pWa->pIV,
    &outputBytesWritten,
    pWa->sgiWa.pKeyChecksums,
    pAlgo->decryptEngine,
    pAlgo->protectionToken_decryptEngine));

  /* Move input and output pointers */
  MCUXCLBUFFER_UPDATE(pInCur, outputBytesWritten);
  MCUXCLBUFFER_UPDATE(pOutCur, outputBytesWritten);

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(outputBytesWritten, 0U, remainingBytes, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
  remainingBytes -= outputBytesWritten;
  /* Update the output length */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*pOutLength, 0U, UINT32_MAX - inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  *pOutLength += outputBytesWritten;

  /* Process remaining bytes and remove the padding, if needed */
  if(remainingBytes > 0U)
  {
    uint32_t paddingOutputSize = 0U;

    MCUXCLBUFFER_INIT_RW(paddingBuf, session, pWa->sgiWa.paddingBuff, remainingBytes);

    /* Process the last block and store the result in the padding buffer */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("this null pointer is unused in this function ")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
      session,
      pWa,
      pInCur,
      paddingBuf,
      remainingBytes,
      NULL,
      &outputBytesWritten,
      pWa->sgiWa.pKeyChecksums,
      pAlgo->decryptEngine,
      pAlgo->protectionToken_decryptEngine));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

    /* Remove the padding and copy the decrypted last block to the output buffer */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("pAlgo->removePadding will never be NULL if remainingBytes > 0U")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->removePadding(
      session,
      MCUXCLAES_BLOCK_SIZE,
      pWa->sgiWa.paddingBuff,
      remainingBytes,
      pOutCur,
      0U,
      &paddingOutputSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

    /* outputBytesWritten is bounded by inLength */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(paddingOutputSize, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*pOutLength, 0U, UINT32_MAX - inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)

    /* Update the output length and clean-up the session */
    *pOutLength += paddingOutputSize;
  }

  /* Protect STATUS_OK - will be balanced by caller */
  MCUX_CSSL_DI_RECORD(cipherDecryptRetCode, MCUXCLCIPHER_STATUS_OK);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit(session, NULL, pKey, cpuWaSizeInWords));


  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_decrypt_Sgi, MCUXCLCIPHER_STATUS_OK,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_decrypt_Sgi_CheckInputs),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
                            pAlgo->protectionToken_setupIVDecrypt,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt),
                            MCUX_CSSL_FP_CONDITIONAL( (remainingBytes > 0U),
                                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt),
                                                    pAlgo->protectionToken_removePadding),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit)
                          );
}
