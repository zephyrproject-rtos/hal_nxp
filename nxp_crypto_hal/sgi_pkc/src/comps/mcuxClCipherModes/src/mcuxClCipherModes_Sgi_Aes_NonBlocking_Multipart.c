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


#include <internal/mcuxClCrc_Internal_Functions.h>

MCUX_CSSL_FP_COUNTER_STMT(
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven_balancingFP)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven_balancingFP(const mcuxClCipherModes_Context_Aes_Sgi_t * pCtx,
                                                                                               const mcuxClCipherModes_WorkArea_t *pWa,
                                                                                               const mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo,
                                                                                               const uint32_t inLength,
                                                                                               const uint32_t bytesToCopy_FP,
                                                                                               const uint32_t blockBufferUsed_FP,
                                                                                               const uint32_t blockBufferUsed_FP_2)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven_balancingFP);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven_balancingFP,
    MCUX_CSSL_FP_CONDITIONAL( (0U != blockBufferUsed_FP ||
                            (MCUXCLAES_BLOCK_SIZE  > (inLength + blockBufferUsed_FP))),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
      MCUX_CSSL_FP_CONDITIONAL( ((MCUXCLAES_BLOCK_SIZE == blockBufferUsed_FP_2) &&
                        ((inLength > bytesToCopy_FP) || !((MCUXCLSGI_DRV_CTRL_DEC == pCtx->direction) &&
                                                       (MCUXCLAES_BLOCK_SIZE == pAlgo->granularityDec) &&
                                                       (NULL != pAlgo->removePadding)))),
        pCtx->protectionToken_processEngine,
        MCUX_CSSL_FP_CONDITIONAL( ((NULL != pWa->pIV) && (inLength == bytesToCopy_FP)),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)))));
})

/**
 * @brief Function to fill and process block buffer if it is necesssary
 *
 *  Move data from inputBufer to blockBuffer if:
 *   1. blockBuffer is not empty. After that if blockBuffer is full and there is remaining data in inputBuffer, process blockBuffer.
 *   2. inputBuffer has too little data to fill entire block.
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pContext   Pointer to multipart context
 * @param      pWa        Handle for the workarea
 * @param[in]  pIn        Pointer to the input buffer
 * @param[out] pOut       Pointer to the output buffer
 * @param[in]  inLength   Length of the input buffer
 * @param[out] pInOffset  Offset of the @p pIn buffer
 * @param[out] pOutOffset Offset of the @p pOut buffer
 * @param[out] pOutLength Pointer to write/update the amount of written output bytes
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t * pInOffset,
  uint32_t * pOutOffset,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(pCtx->common.pMode->pAlgorithm);

  MCUX_CSSL_FP_COUNTER_STMT(uint32_t bytesToCopy_FP = MCUXCLCORE_MIN(MCUXCLAES_BLOCK_SIZE - pCtx->common.blockBufferUsed, inLength));
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t blockBufferUsed_FP = pCtx->common.blockBufferUsed);
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t blockBufferUsed_FP_2 = 0U);
  /* Move data from inputBuffer to blockBuffer if:
   *   1. blockBuffer is not empty
   *   2. inputBuffer has too little data to fill an entire block
   */
  if(0U != pCtx->common.blockBufferUsed || (MCUXCLAES_BLOCK_SIZE  > (inLength + pCtx->common.blockBufferUsed)))
  {
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pCtx->common.blockBufferUsed, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
    /* Store bytes in context */
    uint32_t bytesToCopy = MCUXCLCORE_MIN(MCUXCLAES_BLOCK_SIZE - pCtx->common.blockBufferUsed, inLength);

    MCUX_CSSL_DI_RECORD(bufferRead_smallInput_ProcessDmaDriven, (uint32_t)(pIn) + *pInOffset);
    MCUX_CSSL_DI_RECORD(bufferRead_smallInput_ProcessDmaDriven, (uint32_t)(&((uint8_t *)pCtx->blockBuffer)[pCtx->common.blockBufferUsed]) + bytesToCopy);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(
      pIn,
      *pInOffset,
      &((uint8_t *)pCtx->blockBuffer)[pCtx->common.blockBufferUsed],
      bytesToCopy));

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pInOffset + bytesToCopy is always smaller than UINT32_MAX")
    *pInOffset += bytesToCopy;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("It can't wrap since blockBufferUsed and bytesTocopy are smaller than or equal to MCUXCLAES_BLOCK_SIZE.")
    pCtx->common.blockBufferUsed += bytesToCopy;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* If the block buffer is now full, the block can be immediately processed if
     *   - This is not the last block (there are still bytes left to process in the input buffer)
     *   - Encryption is executed
     *   - Decryption is executed for:
     *     - streamcipher-like mode of operation(granularityDec == 1)
     *     - padding is None (NULL == pAlgo->removePadding)
     *
     * Note: In case of decryption for blockcipher modes of operation(granularityDec == BLOCK_SIZE) with
     *       padding (pAlgo->removePadding!=NULL) immediate processing is not possible because padding removal
     *       needs to be performed on the last block during Cipher_finish. Do "lazy" processing and save
     *       the potential last block for later.
     */
    MCUX_CSSL_FP_COUNTER_STMT(blockBufferUsed_FP_2 = pCtx->common.blockBufferUsed);
    if(MCUXCLAES_BLOCK_SIZE == pCtx->common.blockBufferUsed)
    {
      bool isBlockCipherDecryptWithPadding = (MCUXCLSGI_DRV_CTRL_DEC == pCtx->direction) && (MCUXCLAES_BLOCK_SIZE == pAlgo->granularityDec) && (NULL != pAlgo->removePadding);

      if((inLength > bytesToCopy) || !isBlockCipherDecryptWithPadding)
      {
        MCUXCLBUFFER_INIT(blockBuff, session, pCtx->blockBuffer, MCUXCLAES_BLOCK_SIZE);
        MCUX_CSSL_FP_FUNCTION_CALL(status, pCtx->processEngine(session, pWa, blockBuff, pOut, MCUXCLAES_BLOCK_SIZE, pWa->pIV, pOutLength));
        (void) status; /* One-block processing is blocking -  processEngine only returns OK */

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pOutOffset cannot overflow as it is always initialized to 0, and is guaranteed to be increased by at max the 32-bit input size.")
        *pOutOffset += MCUXCLAES_BLOCK_SIZE;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        pCtx->common.blockBufferUsed = 0U;
        /*
         * This check ensures that mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven has processed exactly
         * one block. This is important due to the behaviour of the counter mode. When no block would have been
         * processed the IV value read from the SGI would be incorrect for the counter mode.
         */
        if((NULL != pWa->pIV) && (inLength == bytesToCopy))
        {
          //Update IV - IV is located in pIV which points to SGI data register
          MCUX_CSSL_DI_RECORD(copyIvToContext, (uint32_t)pCtx->ivState);
          MCUX_CSSL_DI_RECORD(copyIvToContext, (uint32_t)pWa->pIV + MCUXCLAES_BLOCK_SIZE);
          MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int((uint8_t*)pCtx->ivState, (const uint8_t*)pWa->pIV, MCUXCLAES_BLOCK_SIZE));
        }
      }
    }
  }

    /* balancing FP */
  MCUX_CSSL_FP_COUNTER_STMT(MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven_balancingFP(pCtx,
                                                                                                                           pWa,
                                                                                                                           pAlgo,
                                                                                                                           inLength,
                                                                                                                           bytesToCopy_FP,
                                                                                                                           blockBufferUsed_FP,
                                                                                                                           blockBufferUsed_FP_2)));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven,
           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven_balancingFP)
  );
}

/**
 * @brief Function to handle remaining input
 *
 * This function processes full blocks of remaining bytes and
 * calls mcuxClCipherModes_handleLastBlock_process for the last block.
 *
 * @param      session        Handle for the current CL session.
 * @param[in]  pContext       Pointer to multipart context
 * @param      pWa            Handle for the workarea
 * @param[in]  pIn            Pointer to the input buffer
 * @param[out] pOut           Pointer to the output buffer
 * @param[out] pOutLength     Pointer to write/update the amount of written output bytes
 * @param[in]  remainingBytes Number of remaining bytes to process
 * @param[in]  inOffset       Offset of the @p pIn buffer
 * @param[in]  outOffset      Offset of the @p pOut buffer

 *
 * @return mcuxClCipher_Status_t
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_handleRemainingInput_dmaDriven)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_handleRemainingInput_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  uint32_t remainingBytes,
  uint32_t inOffset,
  uint32_t outOffset)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_handleRemainingInput_dmaDriven);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = (mcuxClCipherModes_Algorithm_Aes_Sgi_t) pCtx->common.pMode->pAlgorithm;

  uint32_t lastBlockRemainingBytes = 0U;
  if((pCtx->direction == MCUXCLSGI_DRV_CTRL_ENC)
    || (((pAlgo->granularityDec == 1U) || (NULL == pAlgo->removePadding)) && (pCtx->direction == MCUXCLSGI_DRV_CTRL_DEC)))
  {
    /* In case of encryption / streamcipher-like decryption(granularityDec == 1) or no padding, we can process all full blocks immediately. */
    lastBlockRemainingBytes = remainingBytes % MCUXCLAES_BLOCK_SIZE;
  }
  else
  {
    /* Process remaining full blocks (excluding last block!) from input buffer */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("remainingBytes can't be less than 1U")
    lastBlockRemainingBytes = (remainingBytes - 1U) % MCUXCLAES_BLOCK_SIZE + 1U; /* "lazy" processing */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockRemainingBytes, 0U, remainingBytes, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  uint32_t fullBlocksRemainingBytes = remainingBytes - lastBlockRemainingBytes;

  /* Update workarea with information for callback function */
  pWa->nonBlockingWa.pAlgo = (const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t *) pAlgo;
  pWa->nonBlockingWa.pContext = pCtx;
  pWa->nonBlockingWa.lastBlockRemainingBytes = lastBlockRemainingBytes;
  pWa->nonBlockingWa.pOutputLength = pOutLength;
  pWa->nonBlockingWa.pOut = pOut;
  pWa->nonBlockingWa.outOffset = outOffset;
  pWa->nonBlockingWa.pIn = pIn;
  pWa->nonBlockingWa.inOffset = inOffset;
  if((uint32_t) pAlgo->decryptEngine == (uint32_t) pCtx->processEngine)
  {
    pWa->nonBlockingWa.direction = MCUXCLCIPHERMODES_DECRYPT;
  }
  else
  {
    pWa->nonBlockingWa.direction = MCUXCLCIPHERMODES_ENCRYPT;
  }

  if (0U != fullBlocksRemainingBytes)
  {
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("inOffset has an upper bound of inLength")
    MCUXCLBUFFER_DERIVE_RO(pInCur, pIn, inOffset);
    MCUXCLBUFFER_DERIVE_RW(pOutCur, pOut, outOffset);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    MCUX_CSSL_FP_FUNCTION_CALL(status, pCtx->processEngine(
      session,
      pWa,
      pInCur,
      pOutCur,
      fullBlocksRemainingBytes,
      pWa->pIV,
      pOutLength));

    if(MCUXCLCIPHER_STATUS_JOB_STARTED == status)
    {
      /* Early exit for non-blocking, without clean-ups */
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_OVERFLOWED_TRUNCATED_STATUS_CODE()
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_handleRemainingInput_dmaDriven, status,
                  pCtx->protectionToken_processEngine);
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OVERFLOWED_TRUNCATED_STATUS_CODE()
    }

      /* Update input offset after call to processEngine */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(fullBlocksRemainingBytes, 0U, UINT32_MAX - inOffset, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
    inOffset += fullBlocksRemainingBytes;
  }

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("inOffset has an upper bound of inLength")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_handleLastBlock_process(
    session,
    pWa,
    pCtx,
    pAlgo,
    pIn,
    inOffset,
    lastBlockRemainingBytes));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_handleRemainingInput_dmaDriven, MCUXCLCIPHER_STATUS_OK,
    MCUX_CSSL_FP_CONDITIONAL( (0U != fullBlocksRemainingBytes),
      pCtx->protectionToken_processEngine),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleLastBlock_process)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_process_Sgi_dmaDriven, mcuxClCipher_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_process_Sgi_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_process_Sgi_dmaDriven);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);

  /* Check context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pContext, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  if(0U == inLength)
  {
    /* Nothing to do */
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_process_Sgi_dmaDriven, MCUXCLCIPHER_STATUS_OK
        ,MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc)
        );
  }

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  /* Request the DMA channels and register callback function */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext(
    session, pWa, mcuxClCipherModes_ISR_completeNonBlocking_multipart,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_ISR_completeNonBlocking_multipart)));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Update total number of bytes that were sent to process */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pCtx->common.totalInputLength has an upper bound of inLength")
  pCtx->common.totalInputLength += inLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_loadKeyAndIvtoSgi(
    session,
    (mcuxClCipherModes_Context_Aes_Sgi_t *) pCtx,
    pWa,
    inLength,
    NULL));

  uint32_t remainingBytes = inLength;
  uint32_t inOffset = 0U;
  uint32_t outOffset = 0U;

  /* Move data from inputBufer to blockBuffer if:
   *   1. blockBuffer is not empty. After that if blockBuffer is full and there is remaining data in inputBuffer, process blockBuffer.
   *   2. inputBuffer has too little data to fill entire block.
   */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven(
    session,
    pContext,
    pWa,
    pIn,
    pOut,
    inLength,
    &inOffset,
    &outOffset,
    pOutLength));

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inOffset, 0U, remainingBytes, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("We have at least one block of data to process, therefore remainingBytes is greater than inOffset")
  remainingBytes -= inOffset;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  if (remainingBytes > 0U)
  {
    MCUX_CSSL_FP_FUNCTION_CALL(handleStatus, mcuxClCipherModes_handleRemainingInput_dmaDriven(
      session,
      pContext,
      pWa,
      pIn,
      pOut,
      pOutLength,
      remainingBytes,
      inOffset,
      outOffset));

    if (MCUXCLCIPHER_STATUS_JOB_STARTED == handleStatus)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_process_Sgi_dmaDriven, handleStatus,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_loadKeyAndIvtoSgi),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven),
      MCUX_CSSL_FP_CONDITIONAL( (remainingBytes > 0U),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleRemainingInput_dmaDriven)));
    }
  }

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit_dmaDriven(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords, MCUXCLCIPHERMODES_CLEANUP_HW_ALL));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_process_Sgi_dmaDriven, MCUXCLCIPHER_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_loadKeyAndIvtoSgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_fillAndProcessBlockBuffer_dmaDriven),
    MCUX_CSSL_FP_CONDITIONAL( (remainingBytes > 0U),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleRemainingInput_dmaDriven)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit_dmaDriven)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_finish_Sgi_dmaDriven, mcuxClCipher_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_finish_Sgi_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_finish_Sgi_dmaDriven);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  MCUX_CSSL_DI_RECORD(cipherModesFinishDma_clearCtxOk, (uint8_t*)pCtx);
  MCUX_CSSL_DI_RECORD(cipherModesFinishDma_clearCtxOk, sizeof(mcuxClCipherModes_Context_Aes_Sgi_t));

  /* Check context CRC - SREQI_BCIPHER_3 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pContext, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  /* Request the DMA channels and register callback function */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext(session, pWa, NULL, 0U));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(
    session,
    &(pCtx->keyContext),
    &pWa->sgiWa));

  MCUX_CSSL_FP_COUNTER_STMT(uint32_t finishToken_FP = pCtx->protectionToken_finishSkeleton);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->finishSkeleton(session, pWa, pContext, pOut, pOutLength));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit_dmaDriven(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords, MCUXCLCIPHERMODES_CLEANUP_HW_ALL));

  /* Invalidate context - SREQI_BCIPHER_15 */
  MCUXCLMEMORY_CLEAR_INT((uint8_t*)pCtx, sizeof(mcuxClCipherModes_Context_Aes_Sgi_t));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_finish_Sgi_dmaDriven,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
    finishToken_FP,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit_dmaDriven),
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_ISR_completeNonBlocking_multipart, mcuxClSession_HwInterruptHandler_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_ISR_completeNonBlocking_multipart(
  mcuxClSession_Handle_t session
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_ISR_completeNonBlocking_multipart);

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  mcuxClSession_Channel_t outputChannel = mcuxClSession_getDmaOutputChannel(session);

  /* Wait for both channels, to be sure */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForHandshakeChannelsDone(session));

  /* SGI needs a manual stop once all data is processed (or on DMA channel error). Disable interrupts. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes(inputChannel, outputChannel));

  mcuxClDma_Drv_disableChannelDoneInterrupts(inputChannel);
  mcuxClDma_Drv_disableChannelDoneInterrupts(outputChannel);
  mcuxClDma_Drv_disableErrorInterrupts(inputChannel);
  mcuxClDma_Drv_disableErrorInterrupts(outputChannel);

  /* Determine cpu workarea size and workarea */
  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  mcuxClCipherModes_WorkArea_t * pWa = (mcuxClCipherModes_WorkArea_t *) mcuxClSession_job_getClWorkarea(session);
  /* Read multipart context from workarea */
  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = pWa->nonBlockingWa.pContext;

  /*
   * AUTO mode finished as expected.
   * Continue with the operation - wrap-up AUTO mode and handle the remaining bytes
   */

  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = (mcuxClCipherModes_Algorithm_Aes_Sgi_t) pWa->nonBlockingWa.pAlgo;

  uint32_t lastBlockRemainingBytes = pWa->nonBlockingWa.lastBlockRemainingBytes;

  /* Increase output length and pointer with bytes written by AUTO mode */
  MCUX_CSSL_FP_FUNCTION_CALL(uint16_t, blockWrittenWithDma, mcuxClDma_Drv_readMajorBeginningLoopCount(outputChannel));
  uint32_t bytesWritten = (uint32_t)  blockWrittenWithDma * MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_FP_FUNCTION_CALL(uint16_t, blockReadWithDma, mcuxClDma_Drv_readMajorBeginningLoopCount(inputChannel));
  uint32_t bytesRead = (uint32_t) blockReadWithDma * MCUXCLAES_BLOCK_SIZE;

  /* Advance pointers and output size */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Total outOffset/inOffset and *pOutputLength have an upper bound of inLength")
  pWa->nonBlockingWa.inOffset += bytesRead;
  pWa->nonBlockingWa.outOffset += bytesWritten;
  *pWa->nonBlockingWa.pOutputLength += bytesWritten;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->completeAutoModeEngine(session, mcuxClSession_job_getClWorkarea(session)));

  /* Update ctx for further process calls */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_handleLastBlock_process(
    session,
    pWa,
    pCtx,
    pAlgo,
    pWa->nonBlockingWa.pIn,
    pWa->nonBlockingWa.inOffset,
    lastBlockRemainingBytes));

  /* Notify the user that the operation finished */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit_dmaDriven(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords, MCUXCLCIPHERMODES_CLEANUP_HW_ALL));

  MCUX_CSSL_FP_FUNCTION_CALL(retSessionTriggerCallback, mcuxClSession_triggerUserCallback(session, MCUXCLCIPHER_STATUS_JOB_COMPLETED));
  if(MCUXCLSESSION_STATUS_OK != retSessionTriggerCallback)
  {
    MCUXCLSESSION_ERROR(session, retSessionTriggerCallback);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_ISR_completeNonBlocking_multipart,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForHandshakeChannelsDone),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_readMajorBeginningLoopCount),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_readMajorBeginningLoopCount),
    pAlgo->protectionToken_completeAutoModeEngine,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleLastBlock_process),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit_dmaDriven),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_triggerUserCallback));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_handleLastBlock_process)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_handleLastBlock_process(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClCipherModes_Context_Aes_Sgi_t *pCtx,
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo UNUSED_PARAM,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t lastBlockRemainingBytes
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_handleLastBlock_process);

  if(NULL != pWa->pIV)
  {
    //Update IV - IV is located in pIV which points to SGI data register
    MCUX_CSSL_DI_RECORD(copyIvToContext, (uint32_t)pCtx->ivState);
    MCUX_CSSL_DI_RECORD(copyIvToContext, (uint32_t)pWa->pIV + MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int((uint8_t*)pCtx->ivState, (const uint8_t*)pWa->pIV, MCUXCLAES_BLOCK_SIZE));
  }

  /* Store remaining bytes, which might form up to a full block, in context */
  MCUX_CSSL_DI_RECORD(bufferRead_handleLastBlockProcess, (uint32_t)(pIn) + inOffset);
  MCUX_CSSL_DI_RECORD(bufferRead_handleLastBlockProcess, (uint32_t)(pCtx->blockBuffer) + lastBlockRemainingBytes);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, inOffset, pCtx->blockBuffer, lastBlockRemainingBytes));
  pCtx->common.blockBufferUsed = lastBlockRemainingBytes;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_handleLastBlock_process,
    MCUX_CSSL_FP_CONDITIONAL( (NULL != pWa->pIV),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)),
  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}
