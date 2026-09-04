/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_init_encrypt_Sgi, mcuxClCipher_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_init_encrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t pKey,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_init_encrypt_Sgi);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(pCtx->common.pMode->pAlgorithm);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->checkIvLength(session, ivLength));

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
  pWa->sgiWa.pKeyChecksums = &(pCtx->keyContext.keyChecksums);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  /* SGI is successfully requested before this call, so it is ok to unconditionally call cleanup (with SGI) later on. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_init_internal_Sgi(session, pWa, pCtx, pKey, pIv, ivLength));

  pCtx->setupIV = pAlgo->setupIVEncrypt;
  pCtx->protectionToken_setupIV = pAlgo->protectionToken_setupIVEncrypt;
  pCtx->processEngine = pAlgo->encryptEngine;
  pCtx->protectionToken_processEngine = pAlgo->protectionToken_encryptEngine;
  pCtx->finishSkeleton = mcuxClCipherModes_finish_encrypt_Sgi;
  pCtx->protectionToken_finishSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_finish_encrypt_Sgi);
  pCtx->direction = MCUXCLSGI_DRV_CTRL_ENC;

  /* Init context CRC - SREQI_BCIPHER_3 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords));
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_init_encrypt_Sgi,
    pAlgo->protectionToken_checkIvLength,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_init_internal_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_init_decrypt_Sgi, mcuxClCipher_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_init_decrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t pKey,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_init_decrypt_Sgi);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(pCtx->common.pMode->pAlgorithm);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->checkIvLength(session, ivLength));

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
  pWa->sgiWa.pKeyChecksums = &(pCtx->keyContext.keyChecksums);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  /* SGI is successfully requested before this call, so it is ok to unconditionally call cleanup (with SGI) later on. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_init_internal_Sgi(session, pWa, pCtx, pKey, pIv, ivLength));

  pCtx->setupIV = pAlgo->setupIVDecrypt;
  pCtx->protectionToken_setupIV = pAlgo->protectionToken_setupIVDecrypt;
  pCtx->processEngine = pAlgo->decryptEngine;
  pCtx->protectionToken_processEngine = pAlgo->protectionToken_decryptEngine;
  pCtx->finishSkeleton = mcuxClCipherModes_finish_decrypt_Sgi;
  pCtx->protectionToken_finishSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_finish_decrypt_Sgi);
  pCtx->direction = MCUXCLSGI_DRV_CTRL_DEC;

  /* Init context CRC - SREQI_BCIPHER_3 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords));
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_init_decrypt_Sgi,
    pAlgo->protectionToken_checkIvLength,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_init_internal_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit));
}


MCUX_CSSL_FP_COUNTER_STMT(
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_fillAndProcessBlockBuffer_balancingFP)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_fillAndProcessBlockBuffer_balancingFP(const mcuxClCipherModes_Context_Aes_Sgi_t * pCtx,
                                                                                               const mcuxClCipherModes_WorkArea_t *pWa,
                                                                                               const mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo,
                                                                                               const uint32_t inLength,
                                                                                               const uint32_t bytesToCopy_FP,
                                                                                               const uint32_t blockBufferUsed_FP,
                                                                                               const uint32_t blockBufferUsed_FP_2)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_fillAndProcessBlockBuffer_balancingFP);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer_balancingFP,
    MCUX_CSSL_FP_CONDITIONAL( (0U != blockBufferUsed_FP || (MCUXCLAES_BLOCK_SIZE > (inLength + blockBufferUsed_FP))),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLAES_BLOCK_SIZE == blockBufferUsed_FP_2),
          MCUX_CSSL_FP_CONDITIONAL(((inLength > bytesToCopy_FP) ||
                                  !((MCUXCLSGI_DRV_CTRL_DEC == pCtx->direction) &&
                                  (MCUXCLAES_BLOCK_SIZE == pAlgo->granularityDec) &&
                                  (NULL != pAlgo->removePadding))),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt),
              MCUX_CSSL_FP_CONDITIONAL( ((NULL != pWa->pIV) && (inLength == bytesToCopy_FP)),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int))))));
})


/**
 * @brief Function to fill and process block buffer if it is necesssary
 *
 *  Move data from inputBufer to blockBuffer if:
 *   1. blockBuffer is not empty. After that if blockBuffer is full and there is remaining data in inputBuffer, process blockBuffer.
 *   2. inputBuffer has too little data to fill entire block.
 *
 * @param      session      Handle for the current CL session.
 * @param[in]  pContext     Pointer to multipart context
 * @param      pWa          Handle for the workarea
 * @param[in]  pKeyChecksum Pointer to mcuxClKey_KeyChecksum_t
 * @param[in]  pIn          Pointer to the input buffer
 * @param[out] pOut         Pointer to the output buffer
 * @param[in]  inLength     Length of the input buffer
 * @param[out] pInOffset    Offset of the @p pIn buffer
 * @param[out] pOutOffset   Offset of the @p pOut buffer
 * @param[out] pOutLength   Pointer to write/update the amount of written output bytes
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_fillAndProcessBlockBuffer)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_fillAndProcessBlockBuffer(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClKey_KeyChecksum_t* pKeyChecksum,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t * pInOffset,
  uint32_t * pOutOffset,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_fillAndProcessBlockBuffer);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(pCtx->common.pMode->pAlgorithm);

  MCUX_CSSL_FP_COUNTER_STMT(uint32_t bytesToCopy_FP = MCUXCLCORE_MIN(MCUXCLAES_BLOCK_SIZE - pCtx->common.blockBufferUsed, inLength));
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t blockBufferUsed_FP_2 = 0U);
  /* Move data from inputBuffer to blockBuffer if:
   *   1. blockBuffer is not empty
   *   2. inputBuffer has too little data to fill an entire block
   */
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t blockBufferUsed_FP = pCtx->common.blockBufferUsed);
  if(0U != pCtx->common.blockBufferUsed || (MCUXCLAES_BLOCK_SIZE > (inLength + pCtx->common.blockBufferUsed)))
  {
    /* Store bytes in context */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pCtx->common.blockBufferUsed, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
    uint32_t bytesToCopy = MCUXCLCORE_MIN(MCUXCLAES_BLOCK_SIZE - pCtx->common.blockBufferUsed, inLength);

    MCUX_CSSL_DI_RECORD(bufferRead_smallInput_Process, (uint32_t)(pIn));
    MCUX_CSSL_DI_RECORD(bufferRead_smallInput_Process, (uint32_t)(&((uint8_t *)pCtx->blockBuffer)[pCtx->common.blockBufferUsed]));
    MCUX_CSSL_DI_RECORD(bufferRead_smallInput_Process, bytesToCopy);
    /* Non-secure read is sufficient to handle input. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(
      pIn,
      0U,
      &((uint8_t *)pCtx->blockBuffer)[pCtx->common.blockBufferUsed],
      bytesToCopy));

    *pInOffset = bytesToCopy;
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
        MCUXCLBUFFER_INIT(blockBuf, session, pCtx->blockBuffer, MCUXCLAES_BLOCK_SIZE);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
          session,
          pWa,
          blockBuf,
          pOut,
          MCUXCLAES_BLOCK_SIZE,
          pWa->pIV,
          pOutLength,
          pKeyChecksum,
          pCtx->processEngine,
          pCtx->protectionToken_processEngine));

        *pOutOffset = MCUXCLAES_BLOCK_SIZE;
        pCtx->common.blockBufferUsed = 0U;

        /*
         * This check ensures that mcuxClCipherModes_fillAndProcessBlockBuffer has processed exactly
         * one block. This is important due to the behaviour of the counter mode. When no block would have been
         * processed the IV value read from the SGI would be incorrect for the counter mode.
         */
        if((NULL != pWa->pIV) && (inLength == bytesToCopy))
        {
          MCUX_CSSL_DI_RECORD(copyOfIv, (uint32_t) pCtx->ivState + (uint32_t) pWa->pIV + MCUXCLAES_BLOCK_SIZE);
          // Update IV in the context - IV is located in pWa->pIV which points to SGI data register
          MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int((uint8_t*)pCtx->ivState, (const uint8_t*)pWa->pIV, MCUXCLAES_BLOCK_SIZE));
        }
      }
    }
  }

  /* balancing FP */
  MCUX_CSSL_FP_COUNTER_STMT(MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer_balancingFP(pCtx,
                                                                                                                 pWa,
                                                                                                                 pAlgo,
                                                                                                                 inLength,
                                                                                                                 bytesToCopy_FP,
                                                                                                                 blockBufferUsed_FP,
                                                                                                                 blockBufferUsed_FP_2)));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_fillAndProcessBlockBuffer_balancingFP));
}

/**
 * @brief Function to handle remaining input
 *
 * This function processes full blocks of remaining bytes and
 * save the last block to pCtx->blockBuffer.
 *
 * @param      session        Handle for the current CL session.
 * @param[in]  pContext       Pointer to multipart context
 * @param      pWa            Handle for the workarea
 * @param[in]  pIn            Pointer to the input buffer
 * @param[out] pOut           Pointer to the output buffer
 * @param[in]  pKeyChecksum   Pointer to mcuxClKey_KeyChecksum_t
 * @param[out] pOutLength     Pointer to write/update the amount of written output bytes
 * @param[in]  remainingBytes Number of remaining bytes to process. Must be greater than 0.

 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_handleRemainingInput)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_handleRemainingInput(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  mcuxClKey_KeyChecksum_t* pKeyChecksum,
  uint32_t * const pOutLength,
  uint32_t remainingBytes)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_handleRemainingInput);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(pCtx->common.pMode->pAlgorithm);

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(remainingBytes, 1U, UINT32_MAX, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  uint32_t lastBlockRemainingBytes = 0U;
  if((MCUXCLSGI_DRV_CTRL_ENC == pCtx->direction)
    || (((1U == pAlgo->granularityDec) || (NULL == pAlgo->removePadding)) && (MCUXCLSGI_DRV_CTRL_DEC == pCtx->direction)))
  {
    /* In case of encryption or streamcipher-like decryption(granularityDec == 1) or no padding, we can process all full blocks immediately. */
    lastBlockRemainingBytes = remainingBytes % MCUXCLAES_BLOCK_SIZE;
  }
  else
  {
    /* Process remaining full blocks (excluding last block!) from input buffer */
    lastBlockRemainingBytes = (remainingBytes - 1U) % MCUXCLAES_BLOCK_SIZE + 1U;  /* "lazy" processing */
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockRemainingBytes, 0U, remainingBytes, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  uint32_t fullBlocksRemainingBytes = remainingBytes - lastBlockRemainingBytes;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
    session,
    pWa,
    pIn,
    pOut,
    fullBlocksRemainingBytes,
    pWa->pIV,
    pOutLength,
    pKeyChecksum,
    pCtx->processEngine,
    pCtx->protectionToken_processEngine));

  if(NULL != pWa->pIV)
  {
    // Update IV in the context - IV is located in pWa->pIV which points to SGI data register
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int((uint8_t*)pCtx->ivState, (const uint8_t*)pWa->pIV, MCUXCLAES_BLOCK_SIZE));
  }

  /* Store remaining bytes which might form up to a full block in context */
  MCUXCLBUFFER_UPDATE(pIn, fullBlocksRemainingBytes);
  MCUX_CSSL_DI_RECORD(bufferRead_Process, (uint32_t)(pIn));
  MCUX_CSSL_DI_RECORD(bufferRead_Process, (uint32_t)(&((uint8_t *)pCtx->blockBuffer)[0U]));
  MCUX_CSSL_DI_RECORD(bufferRead_Process, lastBlockRemainingBytes);
  /* Non-secure read is sufficient to handle input. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(
    pIn,
    0U,
    &((uint8_t *)pCtx->blockBuffer)[0U],
    lastBlockRemainingBytes));

  pCtx->common.blockBufferUsed = lastBlockRemainingBytes;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_handleRemainingInput,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt),
      MCUX_CSSL_FP_CONDITIONAL( (NULL != pWa->pIV),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_process_Sgi, mcuxClCipher_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_process_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_process_Sgi);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);

  /* Validate the input size is in a meaningful range to also cover the bytes from the context */
  if(pCtx->common.totalInputLength > (UINT32_MAX - inLength))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

  /* Check context CRC - SREQI_BCIPHER_3 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pContext, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  if(0U == inLength)
  {
    /* Nothing to do */
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_process_Sgi, MCUXCLCIPHER_STATUS_OK
        ,MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc)
        );
  }

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  mcuxClKey_KeyChecksum_t* pKeyChecksum = NULL;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_loadKeyAndIvtoSgi(
    session,
    (mcuxClCipherModes_Context_Aes_Sgi_t *) pCtx,
    pWa,
    inLength,
    &pKeyChecksum));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

  uint32_t remainingBytes = inLength;
  uint32_t inOffset = 0U;
  uint32_t outOffset = 0U;

  MCUXCLBUFFER_DERIVE_RO(pInCur, pIn, inOffset);
  MCUXCLBUFFER_DERIVE_RW(pOutCur, pOut, outOffset);

  /* Move data from inputBufer to blockBuffer if:
   *   1. blockBuffer is not empty. After that if blockBuffer is full and there is remaining data in inputBuffer, process blockBuffer.
   *   2. inputBuffer has too little data to fill entire block.
   */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_fillAndProcessBlockBuffer(
    session,
    pContext,
    pWa,
    pKeyChecksum,
    pInCur,
    pOutCur,
    inLength,
    &inOffset,
    &outOffset,
    pOutLength));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

  MCUXCLBUFFER_UPDATE(pInCur, inOffset);
  MCUXCLBUFFER_UPDATE(pOutCur, outOffset);

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inOffset, 0U, remainingBytes, MCUXCLCIPHER_STATUS_FAULT_ATTACK)
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("We have at least one block of data to process, therefore remainingBytes is greater than inOffset")
  remainingBytes -= inOffset;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  if (remainingBytes > 0U)
  {
    /* Balance the call to mcuxClMemory_copy_int for the copy of the IV to the context in the call to mcuxClCipherModes_handleRemainingInput.
     * Recording here already is fine, the pWa->pIV pointer will not be changed anymore after calling pCtx->setupIV. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
    if(NULL != pWa->pIV)
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    {
      MCUX_CSSL_DI_RECORD(copyOfIv, (uint32_t) pCtx->ivState + (uint32_t) pWa->pIV + MCUXCLAES_BLOCK_SIZE);
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_handleRemainingInput(
      session,
      pContext,
      pWa,
      pInCur,
      pOutCur,
      pKeyChecksum,
      pOutLength,
      remainingBytes));
  }

  /* Update total number of bytes that were encrypted */
  pCtx->common.totalInputLength += inLength;

  /* Update context CRC - SREQI_BCIPHER_3 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_process_Sgi, MCUXCLCIPHER_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_loadKeyAndIvtoSgi),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_fillAndProcessBlockBuffer),
        MCUX_CSSL_FP_CONDITIONAL( (remainingBytes > 0U),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_handleRemainingInput)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit));
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_finish_Sgi, mcuxClCipher_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_finish_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_finish_Sgi);

  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  MCUX_CSSL_DI_RECORD(cipherModesFinish_clearCtxOk, (uint8_t*)pCtx);
  MCUX_CSSL_DI_RECORD(cipherModesFinish_clearCtxOk, sizeof(mcuxClCipherModes_Context_Aes_Sgi_t));

  /* Check context CRC - SREQI_BCIPHER_3 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pContext, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClCipherModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pWa has compatible type and cast was valid")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(session,
                                                            &(pCtx->keyContext),
                                                            &pWa->sgiWa));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t finishToken_FP = pCtx->protectionToken_finishSkeleton);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->finishSkeleton(
    session,
    pWa,
    pContext,
    pOut,
    pOutLength));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_cleanupOnExit(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords));

  /* Invalidate context - SREQI_BCIPHER_15 */
  MCUXCLMEMORY_CLEAR_INT((uint8_t*)pCtx, sizeof(mcuxClCipherModes_Context_Aes_Sgi_t));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_finish_Sgi,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
      finishToken_FP,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_cleanupOnExit),
      MCUXCLMEMORY_CLEAR_INT_FP_EXPECT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_init_internal_Sgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_init_internal_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxClCipherModes_Context_Aes_Sgi_t * const pCtx,
  mcuxClKey_Handle_t pKey,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_init_internal_Sgi);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  pCtx->common.blockBufferUsed = 0U;
  /* Total number of bytes that were encrypted is initialized with zero */
  pCtx->common.totalInputLength = 0U;

  if (0U != ivLength)
  {
    MCUX_CSSL_DI_RECORD(bufferRead_Init, (uint32_t)(pIv));
    MCUX_CSSL_DI_RECORD(bufferRead_Init, (uint32_t)(pCtx->ivState));
    MCUX_CSSL_DI_RECORD(bufferRead_Init, ivLength);
    /* Non-secure read is sufficient to handle IV. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(
      pIv,
      0U,
      (uint8_t *)pCtx->ivState,
      ivLength));
  }

  /* Load key to SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKey_Sgi(session, pKey, &pWa->sgiWa, MCUXCLSGI_DRV_KEY0_OFFSET));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_storeKeyInCtx_Sgi(
    session,
    pKey,
    &(pCtx->keyContext),
    &pWa->sgiWa
  ));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_init_internal_Sgi,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
      MCUX_CSSL_FP_CONDITIONAL( (0U != ivLength),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_storeKeyInCtx_Sgi));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_finish_encrypt_Sgi, mcuxClCipherModes_FinishFunc_AesSgi_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_finish_encrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_finish_encrypt_Sgi);

  mcuxClCipherModes_Context_Aes_Sgi_t * const pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(pCtx->common.pMode->pAlgorithm);
  mcuxClKey_KeyChecksum_t* pKeyChecksum = &pCtx->keyContext.keyChecksums;

  /* Return INVALID_INPUT if totalInputLength doesn't meet the required granularity */
  if(0U != (pCtx->common.totalInputLength % pAlgo->granularityEnc))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
  /* The SGI AUTO-mode might still be running if no input was processed so far
   * (can be the case, e.g., for CTR-NonBlocking mode, as it is started during the
   * pAlgo->setupIV step for this mode). We need to stop AUTO-mode here to bring the
   * SGI in non-busy state, because the PRNG (during certain padding modes) uses the SGI.
   * If AUTO-mode is not running anymore, stopping it will do no harm. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopAndDisableAutoMode());
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */

  /* Check if padding needs to be applied, and if yes store the padded last block in the padding buffer */
  uint32_t paddingOutputSize = 0U;

  /* Create padding input buffer for input to addPadding function */
  MCUXCLBUFFER_INIT_RO(paddingInputBuffer, session, pCtx->blockBuffer, pCtx->common.blockBufferUsed);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->addPadding(
    session,
    MCUXCLAES_BLOCK_SIZE,
    paddingInputBuffer,
    0U,
    pCtx->common.blockBufferUsed,
    pCtx->common.totalInputLength,
    pWa->sgiWa.paddingBuff,
    &paddingOutputSize));

  /* if engine was not yet called, setup the IV */
  MCUXCLBUFFER_INIT_RO(ivBuff, session, pCtx->ivState, MCUXCLAES_BLOCK_SIZE_IN_WORDS);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->setupIV(session, pWa, ivBuff));

  MCUXCLBUFFER_INIT(paddingBuf, session, pWa->sgiWa.paddingBuff, paddingOutputSize);
  MCUXCLBUFFER_DERIVE_RW(pOutBuf, pOut, 0U);
  uint32_t outputBytesWritten = 0U;
  /* Process last (padded) block and store the result in the padding buffer */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
    session,
    pWa,
    paddingBuf,
    pOutBuf,
    paddingOutputSize,
    NULL,
    &outputBytesWritten,
    pKeyChecksum,
    pAlgo->encryptEngine,
    pAlgo->protectionToken_encryptEngine));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("outputBytesWritten does not cause overflow as it depends on blockBufferUsed verified at the function entry")
  /* Update the output length and clean-up the session */
  *pOutLength += outputBytesWritten;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_finish_encrypt_Sgi,
#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopAndDisableAutoMode),
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */
        pAlgo->protectionToken_addPadding,
        pCtx->protectionToken_setupIV,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_finish_decrypt_Sgi, mcuxClCipherModes_FinishFunc_AesSgi_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_finish_decrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_finish_decrypt_Sgi);

  mcuxClCipherModes_Context_Aes_Sgi_t * const pCtx = mcuxClCipherModes_castToCipherModesContextAesSgi(pContext);
  mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo = mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(pCtx->common.pMode->pAlgorithm);
  mcuxClKey_KeyChecksum_t* pKeyChecksum = &pCtx->keyContext.keyChecksums;

  /* Return INVALID_INPUT if totalInputLength is zero for block cipher decryption or doesn't meet the required granularity */
  if(((0U == pCtx->common.totalInputLength) && (1U != pAlgo->granularityDec)) ||
     (0U != (pCtx->common.totalInputLength % pAlgo->granularityDec)))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

  /* For no padding, all data are already processed. */
  if(NULL == pAlgo->removePadding)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_finish_decrypt_Sgi);
  }

  /* if engine was not yet called, setup the IV */
  MCUXCLBUFFER_INIT_RO(ivBuff, session, pCtx->ivState, MCUXCLAES_BLOCK_SIZE_IN_WORDS);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->setupIV(session, pWa, ivBuff));

  uint32_t outputBytesWritten = 0U;
  MCUXCLBUFFER_INIT(blockBuf, session, pCtx->blockBuffer, pCtx->common.blockBufferUsed);
  MCUXCLBUFFER_INIT_RW(paddingBuf, session, pWa->sgiWa.paddingBuff, pCtx->common.blockBufferUsed);
  /* Process the last (padded) block and store the result in the padding buffer */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
    session,
    pWa,
    blockBuf,
    paddingBuf,
    pCtx->common.blockBufferUsed,
    NULL,
    &outputBytesWritten,
    pKeyChecksum,
    pAlgo->decryptEngine,
    pAlgo->protectionToken_decryptEngine));

  uint32_t paddingOutputSize = 0U;
  /* Remove the padding and copy the decrypted data of the last block to the output buffer */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->removePadding(
    session,
    MCUXCLAES_BLOCK_SIZE,
    pWa->sgiWa.paddingBuff,
    pCtx->common.blockBufferUsed,
    pOut,
    0U,
    &paddingOutputSize));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("paddingOutputSize does not cause overflow as it depends on blockBufferUsed verified at the function entry")
  /* Update the output length and clean-up the session */
  *pOutLength += paddingOutputSize;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_finish_decrypt_Sgi,
        pCtx->protectionToken_setupIV,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt),
        pAlgo->protectionToken_removePadding);
}
