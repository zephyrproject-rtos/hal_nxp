/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

#include <mcuxClCore_Macros.h>

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClCipherModes_MemoryConsumption.h>
#include <mcuxClKey.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>

#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Cleanup.h>
#include <internal/mcuxClCipherModes_Sgi_Functions.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Resource.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_encrypt_Sgi_dmaDriven, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_encrypt_Sgi_dmaDriven(
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
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_encrypt_Sgi_dmaDriven);

  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = (mcuxClCipherModes_Algorithm_Aes_Sgi_t) mode->pAlgorithm;

  /* Return INVALID_INPUT if inLength doesn't meet the required granularity */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->checkIvLength(session, ivLength));

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  mcuxClKey_KeyChecksum_t keyChecksums;
  pWa->sgiWa.pKeyChecksums = &keyChecksums;

  /* Request the DMA channels and register callback function */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext(
    session, pWa, mcuxClCipherModes_ISR_completeNonBlocking_oneshot,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_ISR_completeNonBlocking_oneshot)));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load key to SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKey_Sgi(session, pKey, &pWa->sgiWa, MCUXCLSGI_DRV_KEY0_OFFSET));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->setupIVEncrypt(session, pWa, pIv)); /* Load IV if needed, do nothing otherwise */

  uint32_t outputBytesWritten = 0U;

  uint32_t inOffset = 0U;
  uint32_t outOffset = 0U;

  /* Process all full blocks */
  if(MCUXCLAES_BLOCK_SIZE <= inLength)
  {
    /* Update workarea with information for callback function */
    pWa->nonBlockingWa.totalInputLength = inLength;
    pWa->nonBlockingWa.pOutputLength = pOutLength;
    pWa->nonBlockingWa.pAlgo = (const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t *) pAlgo;
    pWa->nonBlockingWa.direction = MCUXCLCIPHERMODES_ENCRYPT;
    pWa->nonBlockingWa.pOut = pOut;
    pWa->nonBlockingWa.outOffset = 0U;
    pWa->nonBlockingWa.pIn = pIn;
    pWa->nonBlockingWa.inOffset = 0U;

    MCUX_CSSL_FP_FUNCTION_CALL(encStatus, pAlgo->encryptEngine(
      session,
      pWa,
      pIn,
      pOut,
      inLength,
      pWa->pIV,
      &outputBytesWritten));

    if(MCUXCLCIPHER_STATUS_JOB_STARTED == encStatus)
    {
      /* Early exit for non-blocking, without clean-ups */
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_encrypt_Sgi_dmaDriven, encStatus,
        pAlgo->protectionToken_checkIvLength,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
        pAlgo->protectionToken_setupIVEncrypt,
        pAlgo->protectionToken_encryptEngine);
    }

    /* Move input and output pointers, increase output length */
    inOffset += outputBytesWritten;
    outOffset += outputBytesWritten;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("outputBytesWritten has an upper bound of inLength")
    *pOutLength += outputBytesWritten;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  }

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_handleLastBlock_enc(
    session,
    pWa,
    pAlgo,
    pIn,
    inOffset,
    inLength,
    pOut,
    outOffset,
    pOutLength));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit_dmaDriven(session, NULL, pKey, cpuWaSizeInWords, MCUXCLCIPHERMODES_CLEANUP_HW_ALL));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_encrypt_Sgi_dmaDriven, MCUXCLCIPHER_STATUS_OK,
    pAlgo->protectionToken_checkIvLength,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
    pAlgo->protectionToken_setupIVEncrypt,
    MCUX_CSSL_FP_CONDITIONAL( (MCUXCLAES_BLOCK_SIZE <= inLength),
      pAlgo->protectionToken_encryptEngine),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleLastBlock_enc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit_dmaDriven)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_decrypt_Sgi_dmaDriven, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_decrypt_Sgi_dmaDriven(
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
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_decrypt_Sgi_dmaDriven);

  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = (mcuxClCipherModes_Algorithm_Aes_Sgi_t) mode->pAlgorithm;

  /* Return INVALID_INPUT if inLength is zero for block cipher decryption or doesn't meet the required granularity */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->checkIvLength(session, ivLength));
  if(((0U == inLength) && (1U != pAlgo->granularityDec)) ||
      (0U != inLength % pAlgo->granularityDec))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  mcuxClKey_KeyChecksum_t keyChecksums;
  pWa->sgiWa.pKeyChecksums = &keyChecksums;

  /* Request the DMA channels and register callback function */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext(
    session, pWa, mcuxClCipherModes_ISR_completeNonBlocking_oneshot,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_ISR_completeNonBlocking_oneshot)));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load key to SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKey_Sgi(session, pKey, &pWa->sgiWa, MCUXCLSGI_DRV_KEY0_OFFSET));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->setupIVDecrypt(session, pWa, pIv)); /* Load IV if needed, do nothing otherwise */

  uint32_t inOffset = 0U;
  uint32_t outOffset = 0U;
  uint32_t outputBytesWritten = 0U;

  uint32_t size;
  if((1U == pAlgo->granularityDec) || (NULL == pAlgo->removePadding))
  {
    /* In the case of stream ciphers or when padding is set to "none", all full blocks can be processed immediately */
    /* TODO CLNS-14107 : update decryptEngine to handle all blocks at once for CTR*/
    size = (inLength / MCUXCLAES_BLOCK_SIZE) * MCUXCLAES_BLOCK_SIZE;
  }
  else
  {
    /* Round down to block size, if the last block is full it will not be considered here to be able to remove the padding later. */
    size = (inLength - 1U) & ~(MCUXCLAES_BLOCK_SIZE - 1U);
  }

  /* Process the considered full blocks */
  if(size > 0U)
  {
    /* Update workarea with information for callback function */
    pWa->nonBlockingWa.totalInputLength = inLength;
    pWa->nonBlockingWa.pOutputLength = pOutLength;
    pWa->nonBlockingWa.pAlgo = (const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t *) pAlgo;
    pWa->nonBlockingWa.direction = MCUXCLCIPHERMODES_DECRYPT;
    pWa->nonBlockingWa.pOut = pOut;
    pWa->nonBlockingWa.outOffset = 0U;
    pWa->nonBlockingWa.pIn = pIn;
    pWa->nonBlockingWa.inOffset = 0U;

    MCUX_CSSL_FP_FUNCTION_CALL(status, pAlgo->decryptEngine(
      session,
      pWa,
      pIn,
      pOut,
      size,
      pWa->pIV,
      &outputBytesWritten));

    if(MCUXCLCIPHER_STATUS_JOB_STARTED == status)
    {
      /* Early exit for non-blocking, without clean-ups */
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_decrypt_Sgi_dmaDriven, status,
        pAlgo->protectionToken_checkIvLength,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
        pAlgo->protectionToken_setupIVDecrypt,
        pAlgo->protectionToken_decryptEngine
      );
    }

    /* Move input and output pointers, increase output length */
    inOffset += outputBytesWritten;
    outOffset += outputBytesWritten;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("*pOutLength was initialized to 0 by all callers, and the total additions to *pOutLength have an upper bound of inLength.")
    *pOutLength += outputBytesWritten;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  }

  /* For no padding, all data are already processed. */
  if(NULL != pAlgo->removePadding)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_handleLastBlock_dec(session, pWa, pAlgo, pIn, inOffset, inLength, pOut, outOffset, pOutLength));
  }

  /* STATUS_OK is protected */
  MCUX_CSSL_DI_RECORD(cipherDecryptRetCode, MCUXCLCIPHER_STATUS_OK);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit_dmaDriven(
    session, NULL, NULL /* TODO CLNS-16946: store keys in nonBlocking WA and flush it here */,
    cpuWaSizeInWords, MCUXCLCIPHERMODES_CLEANUP_HW_ALL));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_decrypt_Sgi_dmaDriven, MCUXCLCIPHER_STATUS_OK,
    pAlgo->protectionToken_checkIvLength,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
    pAlgo->protectionToken_setupIVDecrypt,
    MCUX_CSSL_FP_CONDITIONAL( (size > 0U),
        pAlgo->protectionToken_decryptEngine),
    MCUX_CSSL_FP_CONDITIONAL( (NULL != pAlgo->removePadding),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleLastBlock_dec)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit_dmaDriven)
  );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_ISR_completeNonBlocking_oneshot, mcuxClSession_HwInterruptHandler_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_ISR_completeNonBlocking_oneshot(
  mcuxClSession_Handle_t session
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_ISR_completeNonBlocking_oneshot);
  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  mcuxClSession_Channel_t outputChannel = mcuxClSession_getDmaOutputChannel(session);

  /* Wait for both channels, to be sure */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForHandshakeChannelsDone(session));

  /* SGI needs a manual stop once all data is processed (or on DMA channel error). Disable interrupts. */
  // TODO CLNS-17266: consider properly stopping the AUTO-mode an cleaning-up DMA channels in a public cleanUp API, see handling below
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes(inputChannel, outputChannel));

  mcuxClDma_Drv_disableChannelDoneInterrupts(inputChannel);
  mcuxClDma_Drv_disableChannelDoneInterrupts(outputChannel);
  mcuxClDma_Drv_disableErrorInterrupts(inputChannel);
  mcuxClDma_Drv_disableErrorInterrupts(outputChannel);

  /* Determine cpu workarea size */
  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));

  /*
   * AUTO mode finished as expected.
   * Continue with the operation - wrap-up AUTO mode and handle the last block
   */

  mcuxClCipherModes_WorkArea_t * pWa = (mcuxClCipherModes_WorkArea_t *) mcuxClSession_job_getClWorkarea(session) ;
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = (mcuxClCipherModes_Algorithm_Aes_Sgi_t) pWa->nonBlockingWa.pAlgo;

  /* Increase output length and pointer with bytes written by AUTO mode */
  MCUX_CSSL_FP_FUNCTION_CALL(uint16_t, blockWrittenWithDma, mcuxClDma_Drv_readMajorBeginningLoopCount(outputChannel));
  uint32_t bytesWritten = (uint32_t) blockWrittenWithDma * MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_FP_FUNCTION_CALL(uint16_t, blockReadWithDma, mcuxClDma_Drv_readMajorBeginningLoopCount(inputChannel));
  uint32_t bytesRead = (uint32_t) blockReadWithDma * MCUXCLAES_BLOCK_SIZE;

  /* Advance pointers and output size */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Total outOffset/inOffset and *pOutputLength have an upper bound of inLength")
  pWa->nonBlockingWa.inOffset += bytesRead;
  pWa->nonBlockingWa.outOffset += bytesWritten;
  *pWa->nonBlockingWa.pOutputLength += bytesWritten;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->completeAutoModeEngine(session, mcuxClSession_job_getClWorkarea(session)));

  /* Handle the last block as always */
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t direction_FP = pWa->nonBlockingWa.direction);
  if(MCUXCLCIPHERMODES_ENCRYPT == pWa->nonBlockingWa.direction)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_handleLastBlock_enc(session, pWa, pAlgo,
                                                  pWa->nonBlockingWa.pIn, pWa->nonBlockingWa.inOffset, pWa->nonBlockingWa.totalInputLength,
                                                  pWa->nonBlockingWa.pOut, pWa->nonBlockingWa.outOffset, pWa->nonBlockingWa.pOutputLength));
  }
  else /* MCUXCLCIPHERMODES_DECRYPT == pWa->nonBlockingWa.direction */
  {
    /* For no padding, all data are already processed. */
    if(NULL != pAlgo->removePadding)
    {
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_handleLastBlock_dec(session, pWa, pAlgo,
                                                  pWa->nonBlockingWa.pIn, pWa->nonBlockingWa.inOffset, pWa->nonBlockingWa.totalInputLength,
                                                  pWa->nonBlockingWa.pOut, pWa->nonBlockingWa.outOffset, pWa->nonBlockingWa.pOutputLength));
    }
  }

  /* Notify the user that the operation finished */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit_dmaDriven(session, NULL, NULL /* TODO CLNS-16946: store keys in nonBlocking WA and flush it here */, cpuWaSizeInWords, MCUXCLCIPHERMODES_CLEANUP_HW_ALL));

  MCUX_CSSL_FP_FUNCTION_CALL(retSessionTriggerCallback, mcuxClSession_triggerUserCallback(session, MCUXCLCIPHER_STATUS_JOB_COMPLETED));
  if(MCUXCLSESSION_STATUS_OK != retSessionTriggerCallback)
  {
    MCUXCLSESSION_ERROR(session, retSessionTriggerCallback);
  }
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_ISR_completeNonBlocking_oneshot,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForHandshakeChannelsDone),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes),
    2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_readMajorBeginningLoopCount),
    pAlgo->protectionToken_completeAutoModeEngine,
    MCUX_CSSL_FP_CONDITIONAL( (MCUXCLCIPHERMODES_ENCRYPT == direction_FP),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleLastBlock_enc)),
    MCUX_CSSL_FP_CONDITIONAL( ((MCUXCLCIPHERMODES_DECRYPT == direction_FP) &&
                                (NULL != pAlgo->removePadding)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleLastBlock_dec)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit_dmaDriven),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_triggerUserCallback)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_handleLastBlock_enc)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_handleLastBlock_enc(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t totalInputLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_handleLastBlock_enc);

  uint32_t lastBlockLength = totalInputLength % MCUXCLAES_BLOCK_SIZE;

  /* Check if padding needs to be applied, and if yes store the padded last block in the padding buffer */
  uint32_t paddingOutputSize = 0U;

#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
  /* The SGI AUTO-mode might still be running if no input was processed so far
   * (can be the case, e.g., for CTR-NonBlocking mode, as it is started during the
   * pAlgo->setupIV step for this mode). We need to stop AUTO-mode here to bring the
   * SGI in non-busy state, because the PRNG (during certain padding modes) uses the SGI.
   * If AUTO-mode is not running anymore, stopping it will do no harm. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopAndDisableAutoMode());
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->addPadding(
    session,
    MCUXCLAES_BLOCK_SIZE,
    pIn,
    inOffset,
    lastBlockLength,
    totalInputLength,
    pWa->sgiWa.paddingBuff,
    &paddingOutputSize));

  if(0U == paddingOutputSize)
  {
    /* Nothing to do - exit */
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_handleLastBlock_enc,
#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopAndDisableAutoMode),
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */
      pAlgo->protectionToken_addPadding);
  }

  uint32_t outputBytesWritten = 0U;
  /* Move input and output pointers */
  MCUXCLBUFFER_DERIVE_RW(pOutCur, pOut, outOffset);
  MCUXCLBUFFER_INIT(paddingBuf, session, pWa->sgiWa.paddingBuff, paddingOutputSize);
  /* Process last (padded) block and store the result in the padding buffer */
  MCUX_CSSL_FP_FUNCTION_CALL(status, pAlgo->encryptEngine(
    session,
    pWa,
    paddingBuf,
    pOutCur,
    paddingOutputSize,
    NULL,
    &outputBytesWritten));
  (void) status; /* One-block processing is blocking -  encryptEngine only returns OK */

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("*pOutLength has an upper bound of totalInputLength")
  *pOutLength += outputBytesWritten;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_handleLastBlock_enc,
#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopAndDisableAutoMode),
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */
      pAlgo->protectionToken_addPadding,
      pAlgo->protectionToken_encryptEngine);

}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_handleLastBlock_dec)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_handleLastBlock_dec(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t totalInputLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_handleLastBlock_dec);

  uint32_t lastBlockLength;

  if(pAlgo->granularityDec == 1U)
  {
    /* In case of stream ciphers or no padding, all full blocks have already been processed. Handle remaining bytes. */
    lastBlockLength = totalInputLength % MCUXCLAES_BLOCK_SIZE;
    if(0U == lastBlockLength)
    {
      /* Nothing to do - exit */
      MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_handleLastBlock_dec);
    }
  }
  else
  {
    /* For modes with the need for padding removal, a full block might still be left to process. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pCtx->common.totalInputLength has an upper bound of inLength")
    lastBlockLength = ((totalInputLength + (MCUXCLAES_BLOCK_SIZE - 1U)) % MCUXCLAES_BLOCK_SIZE) +  1U;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  }

  uint32_t outputBytesWritten = 0U;
  /* Move input and output pointers */
  MCUXCLBUFFER_DERIVE_RO(pInCur, pIn, inOffset);
  MCUXCLBUFFER_INIT_RW(ptempBuf, session, pWa->sgiWa.paddingBuff, lastBlockLength);

  /* Process the last block and store the result in the padding buffer */
  MCUX_CSSL_FP_FUNCTION_CALL(status, pAlgo->decryptEngine(
    session,
    pWa,
    pInCur,
    ptempBuf,
    lastBlockLength,
    NULL,
    &outputBytesWritten));
  (void) status; /* One-block processing is blocking -  decryptEngine only returns OK */

  uint32_t paddingOutputSize = 0U;
  /* Remove the padding and copy the decrypted last block to the output buffer */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("pAlgo->removePadding will never be NULL when mcuxClCipherModes_handleLastBlock_dec is called")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->removePadding(
    session,
    MCUXCLAES_BLOCK_SIZE,
    pWa->sgiWa.paddingBuff,
    lastBlockLength,
    pOut,
    outOffset,
    &paddingOutputSize));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  /* Update the output length */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("paddingOutputSize does not cause overflow as it depends on inLength verified in higher level caller")
  *pOutLength += paddingOutputSize;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_OVERFLOWED_TRUNCATED_STATUS_CODE()
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_handleLastBlock_dec,
    pAlgo->protectionToken_decryptEngine,
    pAlgo->protectionToken_removePadding);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OVERFLOWED_TRUNCATED_STATUS_CODE()
}
