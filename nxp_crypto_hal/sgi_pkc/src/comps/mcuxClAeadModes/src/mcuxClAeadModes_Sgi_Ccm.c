/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/** @file  mcuxClAeadModes_Sgi_Ccm.c
 *  @brief Implementation of the CCM functions of the mcuxClAeadModes component */

#include <mcuxClCore_Platform.h>

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClCipher.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClMacModes_Modes.h>

#include <internal/mcuxClAeadModes_Common.h>
#include <internal/mcuxClAeadModes_Sgi_Algorithms.h>
#include <internal/mcuxClAeadModes_Sgi_Types.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClCipherModes_Sgi_Algorithms.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClCipherModes_Sgi_Functions.h>
#include <internal/mcuxClCipherModes_Sgi_Types.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMacModes_Sgi_Algorithms.h>
#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <internal/mcuxClMacModes_Sgi_Cbcmac.h>
#include <internal/mcuxClAeadModes_Common_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_CCM_FormatFirstBlockAndCreatePreTag)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_CCM_FormatFirstBlockAndCreatePreTag(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceSize,
  uint32_t inSize,
  uint32_t adataSize,
  uint32_t tagSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_CCM_FormatFirstBlockAndCreatePreTag);

  MCUX_CSSL_DI_RECORD(CCM_clearB0, (uint32_t)workArea->cpuWa.CCM_B0);
  MCUX_CSSL_DI_RECORD(CCM_clearB0, MCUXCLAES_BLOCK_SIZE);

  const mcuxClAeadModes_AlgorithmDescriptor_t* alg = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);

  // Clear first blocks to guarantee zero padding
  MCUXCLMEMORY_CLEAR_INT(workArea->cpuWa.CCM_B0, MCUXCLAES_BLOCK_SIZE);

  // Assert that parameters aren't negative
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(tagSize, 4U, 15U, MCUXCLAEAD_STATUS_INVALID_PARAM);
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(nonceSize, 7U, 13U, MCUXCLAEAD_STATUS_INVALID_PARAM);

  // Get length of auth field from parameter
  uint8_t t = (uint8_t)((tagSize - 2U) / 2U);

  // Get q from parameter
  uint8_t q = (uint8_t)(15U - nonceSize);

  //Cast to uint8 to access bytes
  uint8_t *pB = workArea->cpuWa.CCM_B0;

  // Assemble the flags byte for B0
  // --------------------------------------------
  // |     7    |   6   |    5..3     |   2..0  |
  // | Reserved | Adata | [(t-2)/2]_3 | [q-1]_3 |
  // --------------------------------------------

  uint8_t isheaderLen = (adataSize > 0U) ? 1U : 0U;
  pB[0U] = (uint8_t)((uint8_t)((isheaderLen << 6U) | (t << 3U)) | (q - 1U));

  // Create B0
  // ----------------------------------
  // |   0   | 1 .. 15-q | 16-q .. 15 |
  // | Flags |     N     |      Q     |
  // ----------------------------------

  // Create Q - hex encoded value of inLength, reversed representation
  // Assume Q is 4 bytes long for easier byte-reverse; non-needed bytes (trailing zeros) are overwritting when copying the nonce N
  uint8_t *pInLength = (uint8_t*) &inSize;
  pB[15] = pInLength[0U];
  pB[14] = pInLength[1U];
  pB[13] = pInLength[2U];
  pB[12] = pInLength[3U];

  // Copy nonce N
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pNonce);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, &pB[1U]);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, nonceSize);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pNonce, 0U, &pB[1U], nonceSize));

  // Prepare masked pre-tag in macCtx
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_initMaskedPreTag(&pContext->macCtx));

  //Calculate tag over B0
  MCUXCLBUFFER_INIT_RO(waBuf, NULL, workArea->cpuWa.CCM_B0, MCUXCLAES_BLOCK_SIZE);

  mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("this null pointer is unused in this function")
  MCUX_CSSL_FP_FUNCTION_CALL(retMacUpdate, alg->macAlgo->update(
    session,
    macModesWorkArea,
    &pContext->macCtx,
    waBuf,
    MCUXCLAES_BLOCK_SIZE,
    NULL /* unused for now */));
  (void)retMacUpdate;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  // Formatting of the associated data
  // Encode a and concatenate with associated data

  uint32_t aadLen = adataSize;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("blockBuffer is word-aligned inside context struct")
  uint8_t* macBuf = (uint8_t*)pContext->macCtx.blockBuffer;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()

  // If 0 < a < 2^{16}-2^{8}, then a is encoded as [a]_16, i.e., two octets.
  if(0U != aadLen && aadLen < ((1UL << 16U) - (1UL << 8U)))
  {
    // a < 2^{16}-2^{8}
    macBuf[0] = (uint8_t)((aadLen & 0x0000FF00U) >> 8U);
    macBuf[1] = (uint8_t)((aadLen & 0x000000FFU) >> 0U);

    pContext->macCtx.blockBufferUsed = 2U;
  }
  // If 2^{16}-2^{8} <= a < 2^{32}, then a is encoded as 0xff || 0xfe || [a]_32, i.e., six octets.
  else if(0U != aadLen)
  {
    // a >= 2^{16}-2^{8}
    macBuf[0] = (uint8_t)0xFFU;
    macBuf[1] = (uint8_t)0xFEU;
    macBuf[2] = (uint8_t)((aadLen & 0xFF000000U) >> 24U);
    macBuf[3] = (uint8_t)((aadLen & 0x00FF0000U) >> 16U);
    macBuf[4] = (uint8_t)((aadLen & 0x0000FF00U) >> 8U);
    macBuf[5] = (uint8_t)((aadLen & 0x000000FFU) >> 0U);

    pContext->macCtx.blockBufferUsed = 6U;
  }
  else
  {
    // No action required
  }

  // If 2^{32} <= a < 2^{64}, then a is encoded as 0xff || 0xff || [a]_64, i.e., ten octets.
  // This case is not supported in CL and hence does not occur since inputLen is uint32_t
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_CCM_FormatFirstBlockAndCreatePreTag,
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_initMaskedPreTag),
    alg->macAlgo->protectionToken_update
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_CCM_GenerateCounterBlockV2)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_CCM_GenerateCounterBlockV2(
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceSize,
  uint8_t *pCtr)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_CCM_GenerateCounterBlockV2);

  // Clear counter first
  MCUX_CSSL_DI_RECORD(CCM_clearCtr, (uint32_t)pCtr);
  MCUX_CSSL_DI_RECORD(CCM_clearCtr, MCUXCLAES_BLOCK_SIZE);
  MCUXCLMEMORY_CLEAR_INT(pCtr, MCUXCLAES_BLOCK_SIZE);

  // Assert that parameters aren't negative
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(nonceSize, 7U, 13U, MCUXCLAEAD_STATUS_INVALID_PARAM);

  // Get q
  uint8_t q = (uint8_t)(15U - nonceSize);

  // Assemble the flags byte
  // ------------------------------------------
  // |     7    |     6    |  5..3  |   2..0  |
  // | Reserved | Reserved |   000  | [q-1]_3 |
  // ------------------------------------------
  pCtr[0U] = q - 1U;

  // Create CTR0
  // ----------------------------------
  // |   0   | 1 .. 15-q | 16-q .. 15 |
  // | Flags |     N     |      0     |
  // ----------------------------------

  // Copy nonce into counter block
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pNonce);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, &pCtr[1U]);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, nonceSize);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pNonce, 0U, &pCtr[1U], nonceSize));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_CCM_GenerateCounterBlockV2,
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
  );
}

/**
 * @brief Function to prepare initial state for the CCM
 *
 * Data Integrity: Expunge(tagSize)
 *
 * @param      session          Handle for the current CL session.
 * @param      pContext         Pointer to multipart context
 * @param[in]  workArea         Pointer to work area
 * @param[in]  pNonce           Pointer to nonce
 * @param[in]  nonceSize        Size of nonce
 * @param[in]  inSize           Input size
 * @param[in]  adataSize        Adata size
 * @param[in]  tagSize          Tag size
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_Ccm_init, mcuxClAeadModes_alg_init_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_Ccm_init(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t* const pContext,
  mcuxClAeadModes_WorkArea_t* workArea,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceSize,
  uint32_t inSize,
  uint32_t adataSize,
  uint32_t tagSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_Ccm_init);

  // DI_RECORD for mcuxClMemory_copy_int call below
  MCUX_CSSL_DI_RECORD(CCMinit_copyIv, (uint32_t)pContext->cipherCtx.ivState);
  MCUX_CSSL_DI_RECORD(CCMinit_copyIv, (uint32_t)pContext->counter0);
  MCUX_CSSL_DI_RECORD(CCMinit_copyIv, MCUXCLAES_BLOCK_SIZE);

  MCUX_CSSL_DI_RECORD(CCMinit_clearBlockBuffer, (uint32_t)pContext->cipherCtx.blockBuffer);
  MCUX_CSSL_DI_RECORD(CCMinit_clearBlockBuffer, MCUXCLAES_BLOCK_SIZE);
  MCUXCLMEMORY_CLEAR_INT((uint8_t*)pContext->cipherCtx.blockBuffer, MCUXCLAES_BLOCK_SIZE);

  pContext->adataSize = adataSize;
  pContext->adataCumulativeSize = 0U;
  pContext->inSize = inSize;
  pContext->tagSize = tagSize;
  pContext->cipherCtx.common.blockBufferUsed = 0U;

  /* Set CBC mac mode such that we can use zero-padding (only required after the AAD) */
  pContext->macCtx.common.pMode = &mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_CCM_FormatFirstBlockAndCreatePreTag(
    session,
    pContext,
    workArea,
    pNonce,
    nonceSize,
    inSize,
    adataSize,
    tagSize));

  // Generate the counter for CTR mode encryption
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_CCM_GenerateCounterBlockV2(
    pNonce,
    nonceSize,
    pContext->counter0));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int((uint8_t *)pContext->cipherCtx.ivState, pContext->counter0, MCUXCLAES_BLOCK_SIZE));

  // Last X bytes of pCtxCcm->ivState are always equal zero, set last byte to one for the next computation
  pContext->cipherCtx.ivState[3] = (pContext->cipherCtx.ivState[3] & 0x00ffffffU) | ((uint32_t)0x01U << 24U);

  MCUX_CSSL_DI_EXPUNGE(tagSize, pContext->tagSize);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_Ccm_init,
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CCM_FormatFirstBlockAndCreatePreTag),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CCM_GenerateCounterBlockV2),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)
  );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_Ccm_process_aad, mcuxClAeadModes_alg_process_aad_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_Ccm_process_aad(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t* const pContext,
  mcuxClAeadModes_WorkArea_t* workArea,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_Ccm_process_aad);

  const mcuxClAeadModes_AlgorithmDescriptor_t* alg = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);
  mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);

  if (pContext->adataCumulativeSize >= (UINT32_MAX - adataSize))
  {
    /* No need to clear the context since this is a functional error. */
    MCUXCLSESSION_ERROR(session, MCUXCLAEAD_STATUS_INVALID_PARAM);
  }

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("this null pointer is unused in this function")

  MCUX_CSSL_FP_FUNCTION_CALL(retMacUpdate, alg->macAlgo->update(
    session,
    macModesWorkArea,
    &pContext->macCtx,
    pAdata,
    adataSize,
    NULL /* unused for now */));
  (void)retMacUpdate;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  /* Update cumulative adata size in ctx. */
  pContext->adataCumulativeSize += adataSize;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_Ccm_process_aad,
    alg->macAlgo->protectionToken_update
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_Ccm_process, mcuxClAeadModes_alg_process_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_Ccm_process(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_Ccm_process);

  const mcuxClAeadModes_AlgorithmDescriptor_t* alg = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);

  MCUX_CSSL_FP_COUNTER_STMT(uint32_t adataCumulativeSizeRef = pContext->adataCumulativeSize);
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t blockBufferUsedRef = pContext->macCtx.blockBufferUsed);

  /* Compare the adataCumulativeSize against the expected adata size to see if this is the first call to Aead_process.
   * If yes, and if any bytes are left in the blockBuffer, pad and process this last aad block. */
  if((pContext->adataCumulativeSize == pContext->adataSize) && (0U != pContext->macCtx.blockBufferUsed))
  {
    /* Apply padding and process remaining adata and create pretag */
    mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);

    uint32_t padLen = 0U;
    MCUXCLBUFFER_INIT_RO(paddingInputBuffer, session, (uint8_t*)pContext->macCtx.blockBuffer, pContext->macCtx.blockBufferUsed);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(alg->macAlgo->addPadding(
      session,
      MCUXCLAES_BLOCK_SIZE,
      paddingInputBuffer,
      0U,
      pContext->macCtx.blockBufferUsed,
      pContext->macCtx.blockBufferUsed,
      workArea->sgiWa.paddingBuff,
      &padLen));

    /* The remaining (padded) data is already in paddedBuf, make sure it doesn't get processed twice */
    pContext->macCtx.blockBufferUsed = 0U;

    MCUXCLBUFFER_INIT_RO(paddedBuf, NULL, workArea->sgiWa.paddingBuff, MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("this null pointer is unused in this function")

    MCUX_CSSL_FP_FUNCTION_CALL(retMacUpdate, alg->macAlgo->update(
      session,
      macModesWorkArea,
      &pContext->macCtx,
      paddedBuf,
      padLen,
      NULL /* unused for now */));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
    (void)retMacUpdate;

    /* Set the cumulative adata size to 0 to not enter this branch again in the next call to Aead_process */
    pContext->adataCumulativeSize = 0U;

    /* pContext->macCtx.blockBufferUsed is still zero */
  }

  /* Process the input */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_CcmGcm_process(
    session,
    pContext,
    workArea,
    pIn,
    inSize,
    pOut,
    pOutSize));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_Ccm_process,
    MCUX_CSSL_FP_CONDITIONAL(((adataCumulativeSizeRef == pContext->adataSize) && (0U != blockBufferUsedRef)),
      alg->macAlgo->protectionToken_addPadding,
      alg->macAlgo->protectionToken_update
    ),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CcmGcm_process)
  );
}

/* Mac-then-Encrypt/Encrypt-then-Mac core for CCM mode*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_Ccm_processFullBlocks, mcuxClAeadModes_ProcessFullBlocks_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_Ccm_processFullBlocks(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  const uint32_t inSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_Ccm_processFullBlocks);

  const mcuxClAeadModes_AlgorithmDescriptor_t *pAlgo = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);

  mcuxClCipherModes_WorkArea_t *cipherWa = mcuxClAeadModes_castToCipherModesWorkArea(workArea);
  mcuxClKey_KeyChecksum_t* pKeyChecksum = &pContext->cipherCtx.keyContext.keyChecksums;

  if(MCUXCLAEADMODES_ENCRYPTION == pContext->encDecMode)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_updateMac(
      session,
      pContext,
      workArea,
      pIn,
      inSize));
  }

  MCUXCLBUFFER_INIT_RO(counterInputBuf, NULL, (uint8_t *)pContext->cipherCtx.ivState, MCUXCLAES_BLOCK_SIZE);
  uint32_t outLen = 0U;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->cipherAlgo->setupIVEncrypt(
    session,
    cipherWa,
    counterInputBuf));

  /* Multiple software computations for CCM decryption is not necessary */
  if (MCUXCLAEADMODES_DECRYPTION == pContext->encDecMode)
  {
    cipherWa->sgiWa.copyOutFunction = mcuxClCipherModes_copyOut_toPtr;
    cipherWa->sgiWa.protectionToken_copyOutFunction = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_copyOut_toPtr);
    MCUX_CSSL_FP_FUNCTION_CALL(retCipherEncrypt, pAlgo->cipherAlgo->encryptEngine(
      session,
      cipherWa,
      pIn,
      pOut,
      inSize,
      pContext->cipherCtx.ivState,
      &outLen)
    );
    (void)retCipherEncrypt;

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pKeyChecksum->VerifyFunc(session, pKeyChecksum, (uint8_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_KEY0_OFFSET)));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_updateMac(session, pContext, workArea, pOut, inSize));
  }
  else if (MCUXCLAEADMODES_ENCRYPTION == pContext->encDecMode)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
      session,
      cipherWa,
      pIn,
      pOut,
      inSize,
      pContext->cipherCtx.ivState,
      &outLen,
      pKeyChecksum,
      pAlgo->cipherAlgo->encryptEngine,
      pAlgo->cipherAlgo->protectionToken_encryptEngine)
    );
  }
  else
  {
    /* The pContext->encDecMode could be only ENCRYPTION or DECRYPTION */
    MCUXCLSESSION_FAULT(session, MCUXCLAEAD_STATUS_FAULT_ATTACK);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_Ccm_processFullBlocks,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_updateMac), /* mcuxClAeadModes_updateMac called once, for both ENCRYPTION and DECRYPTION */
    pAlgo->cipherAlgo->protectionToken_setupIVEncrypt,
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLAEADMODES_DECRYPTION == pContext->encDecMode),
      pAlgo->cipherAlgo->protectionToken_encryptEngine,
      pKeyChecksum->protectionToken_VerifyFunc
    ),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLAEADMODES_ENCRYPTION == pContext->encDecMode),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt)
    )
  );
}

const mcuxClAeadModes_AlgorithmDescriptor_t mcuxClAeadModes_AlgorithmDescriptor_Ccm =
{
  .init                               = mcuxClAeadModes_Ccm_init,
  .protectionToken_init               = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_Ccm_init),
  .processAad                         = mcuxClAeadModes_Ccm_process_aad,
  .protectionToken_processAad         = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_Ccm_process_aad),
  .processEncDec                      = mcuxClAeadModes_Ccm_process,
  .protectionToken_processEncDec      = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_Ccm_process),
  .processFullBlocks                  = mcuxClAeadModes_Ccm_processFullBlocks,
  .protectionToken_processFullBlocks  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_Ccm_processFullBlocks),
  .finish                             = mcuxClAeadModes_CcmGcm_finish,
  .protectionToken_finish             = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CcmGcm_finish),
  .mode = MCUXCLAEADMODES_CCM,

  /* we need zero-padded blocks */
  .macAlgo = &mcuxClMacModes_AlgorithmDescriptor_CBCMAC_PaddingISO9797_1_Method1,
  .cipherAlgo = &mcuxClCipherModes_AlgorithmDescriptor_CTR_Sgi
};


