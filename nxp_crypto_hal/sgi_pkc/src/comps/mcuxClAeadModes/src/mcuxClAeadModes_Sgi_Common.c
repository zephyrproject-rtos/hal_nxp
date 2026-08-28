/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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

/** @file  mcuxClAeadModes_Sgi_Common.c
 *  @brief implementation of the common functions of the mcuxClAeadModes component */

#include <mcuxClCore_Platform.h>

#include <internal/mcuxClAeadModes_Common.h>

#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClSgi_Drv.h>
#include <mcuxClAes.h>
#include <mcuxClCipher.h>
#include <mcuxClAead_Constants.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClMacModes_Sgi_Gmac.h>
#include <internal/mcuxClSgi_Utils.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClCipherModes_Sgi_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_CheckInputs)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_CheckInputs(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  uint32_t inSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_CheckInputs);

  /* zero inSize means we will do nothing */
  if(0U == inSize)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_CheckInputs);
  }

  // Assert that pContext->cipherCtx.common.blockBufferUsed + inSize will not overflow
  if(inSize > (UINT32_MAX - pContext->cipherCtx.common.blockBufferUsed))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLAEAD_STATUS_INVALID_PARAM);
  }

  /* Assert that pContext->inSize will not overflow */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->inSize, 0U, (UINT32_MAX - inSize), MCUXCLAEAD_STATUS_INVALID_PARAM);
  pContext->inSize += inSize;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_CheckInputs);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_updateMac)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_updateMac(mcuxClSession_Handle_t session,
                                                                       mcuxClAeadModes_Context_t *const pContext,
                                                                       mcuxClAeadModes_WorkArea_t *workArea,
                                                                       mcuxCl_InputBuffer_t pIn,
                                                                       const uint32_t macInSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_updateMac);


  const mcuxClAeadModes_AlgorithmDescriptor_t *pAlgo = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);
  mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("this null pointer is unused in this function")
  MCUX_CSSL_FP_FUNCTION_CALL(retMacUpdate, pAlgo->macAlgo->update(
    session,
    macModesWorkArea,
    &pContext->macCtx,
    pIn,
    macInSize,
    NULL /* unused for now */));
  (void)retMacUpdate;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()


  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_updateMac,
    pAlgo->macAlgo->protectionToken_update
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_CcmGcm_process)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_CcmGcm_process(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_CcmGcm_process);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_CheckInputs(session, pContext, inSize));

  uint32_t offsetInput = 0U;
  uint32_t offsetOutput = 0U;

  /* Assert that blockBufferUsed does not exceed MCUXCLAES_BLOCK_SIZE */
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(pContext->cipherCtx.common.blockBufferUsed, 0U, MCUXCLAES_BLOCK_SIZE)
  /* Assert that pContext->cipherCtx.common.blockBufferUsed + inSize cannot overflow, checked in mcuxClAeadModes_CheckInputs() before */
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(inSize, 0U, (UINT32_MAX - pContext->cipherCtx.common.blockBufferUsed))

  /* check if we need to process less than one block */
  if(MCUXCLAES_BLOCK_SIZE > (pContext->cipherCtx.common.blockBufferUsed + inSize))
  {
    /* copy to internal buffer and return */
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pIn);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, offsetInput);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, &pContext->cipherCtx.blockBuffer[pContext->cipherCtx.common.blockBufferUsed]);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, inSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(
      pIn,
      offsetInput,
      &pContext->cipherCtx
            .blockBuffer[pContext->cipherCtx.common.blockBufferUsed],
      inSize));

    pContext->cipherCtx.common.blockBufferUsed += inSize;

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_CcmGcm_process,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CheckInputs),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
    );
  }

  MCUX_CSSL_FP_COUNTER_STMT(const volatile uint32_t blockBufferUsedRef = pContext->cipherCtx.common.blockBufferUsed);
  if(0U != pContext->cipherCtx.common.blockBufferUsed)
  {
    /* process one block consisting of remainder and input */
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pIn);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, offsetInput);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, &pContext->cipherCtx.blockBuffer[pContext->cipherCtx.common.blockBufferUsed]);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, MCUXCLAES_BLOCK_SIZE - pContext->cipherCtx.common.blockBufferUsed);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(
      pIn,
      offsetInput,
      &pContext->cipherCtx.blockBuffer[pContext->cipherCtx.common.blockBufferUsed],
      MCUXCLAES_BLOCK_SIZE - pContext->cipherCtx.common.blockBufferUsed));

    MCUXCLBUFFER_INIT_RO(blockBuffer, NULL, pContext->cipherCtx.blockBuffer, MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pContext->common.mode->algorithm->processFullBlocks(
      session,
      pContext,
      workArea,
      blockBuffer,
      pOut,
      MCUXCLAES_BLOCK_SIZE));

    offsetInput += MCUXCLAES_BLOCK_SIZE - pContext->cipherCtx.common.blockBufferUsed;
    offsetOutput += MCUXCLAES_BLOCK_SIZE;
    inSize -= MCUXCLAES_BLOCK_SIZE - pContext->cipherCtx.common.blockBufferUsed;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("*pOutSize is initialized to ZERO before the calling")
    *pOutSize += MCUXCLAES_BLOCK_SIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    pContext->cipherCtx.common.blockBufferUsed = 0U;
  }

  /* process the remaining (full) blocks, if any */
  MCUX_CSSL_FP_COUNTER_STMT(const volatile uint32_t inSizeRemBlocksRef = inSize);
  if(inSize >= MCUXCLAES_BLOCK_SIZE)
  {
    uint32_t inputBlocks = inSize / MCUXCLAES_BLOCK_SIZE;

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(offsetInput,
                                       0U,
                                       UINT32_MAX - inputBlocks * (uint32_t)MCUXCLAES_BLOCK_SIZE);

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(*pOutSize,
                                       0U,
                                       UINT32_MAX - inputBlocks * (uint32_t)MCUXCLAES_BLOCK_SIZE);

    MCUXCLBUFFER_DERIVE_RW(pOutWithOffset, pOut, offsetOutput);
    MCUXCLBUFFER_DERIVE_RO(pInWithOffset, pIn, offsetInput);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pContext->common.mode->algorithm->processFullBlocks(
      session,
      pContext,
      workArea,
      pInWithOffset,
      pOutWithOffset,
      inputBlocks * MCUXCLAES_BLOCK_SIZE));

    offsetInput += inputBlocks * MCUXCLAES_BLOCK_SIZE;
    inSize &= (MCUXCLAES_BLOCK_SIZE - 1U);
    *pOutSize += inputBlocks * MCUXCLAES_BLOCK_SIZE;
    pContext->cipherCtx.common.blockBufferUsed = 0U;
  }

  /* If there is any data remaining, copy it into the internal Cipher blockBuffer.
   * This is only needed for the Cipher context, as the Mac blockBuffer was already filled similarly during Mac internals. */
  if(0U != inSize)
  {
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pIn);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, offsetInput);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pContext->cipherCtx.blockBuffer);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, inSize);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, offsetInput, pContext->cipherCtx.blockBuffer, inSize));

    pContext->cipherCtx.common.blockBufferUsed = inSize;
  }

  /* Read the inSizeRemBlocksRef to non-volatile parameter before passing to MCUX_CSSL_FP_FUNCTION_EXIT_VOID for FP balancing */
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t inSizeRemBlocksRefFP = inSizeRemBlocksRef);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_CcmGcm_process,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CheckInputs),
    MCUX_CSSL_FP_CONDITIONAL((0U != blockBufferUsedRef),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
      pContext->common.mode->algorithm->protectionToken_processFullBlocks
    ),
    MCUX_CSSL_FP_CONDITIONAL((inSizeRemBlocksRefFP >= MCUXCLAES_BLOCK_SIZE),
      pContext->common.mode->algorithm->protectionToken_processFullBlocks
    ),
    MCUX_CSSL_FP_CONDITIONAL((0U != inSize),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
    )
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_CcmGcm_finish, mcuxClAeadModes_alg_finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_CcmGcm_finish(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutSize,
  mcuxCl_Buffer_t pTag)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_CcmGcm_finish);

  const mcuxClAeadModes_AlgorithmDescriptor_t* pAlgo = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);
  mcuxClCipherModes_WorkArea_t* cipherWa = mcuxClAeadModes_castToCipherModesWorkArea(workArea);
  mcuxClKey_KeyChecksum_t* pKeyChecksum = &pContext->cipherCtx.keyContext.keyChecksums;

  /* Assert that blockBufferUsed + *pOutSize will not overflow.
   * For both Oneshot and Multipart API,*pOutSize is overwritten to 0 in mcuxClAead.c,
   * so no input to the finish stage can possibly trigger this. */
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(*pOutSize, 0U, 0U);

  MCUX_CSSL_FP_COUNTER_STMT(const volatile uint32_t blockBufferUsedRef = pContext->cipherCtx.common.blockBufferUsed);
  if(0U != pContext->cipherCtx.common.blockBufferUsed)
  {
    // pad -> EtM/MtE core (but don't mac the padding) -> remove padding
    MCUXCLBUFFER_INIT_RO(blockBuffer, NULL, pContext->cipherCtx.blockBuffer, MCUXCLAES_BLOCK_SIZE);
    MCUXCLBUFFER_INIT(padBuf, NULL, workArea->sgiWa.paddingBuff, MCUXCLAES_BLOCK_SIZE);

    /* Create padding input buffer for input to addPadding function */
    uint32_t outLen = 0U;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->cipherAlgo->addPadding(
      session,
      MCUXCLAES_BLOCK_SIZE,
      blockBuffer,
      0U,
      pContext->cipherCtx.common.blockBufferUsed,
      pContext->inSize,
      workArea->sgiWa.paddingBuff,
      &outLen));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->processFullBlocks(
      session,
      pContext,
      workArea,
      (mcuxCl_InputBuffer_t)padBuf,
      pOut,
      pContext->cipherCtx.common.blockBufferUsed));

    *pOutSize += pContext->cipherCtx.common.blockBufferUsed;
  }

  if (MCUXCLAEADMODES_CCM == pAlgo->mode)
  {
    mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->macAlgo->finalize(session, macModesWorkArea, &pContext->macCtx));


    /* copy tag from SGI DATOUT, re-use padding buff */
    MCUXCLBUFFER_INIT(tagBuf, NULL, workArea->sgiWa.paddingBuff, MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_DI_RECORD(sgiStoreBuffer, ((uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET)) + ((uint32_t)tagBuf) + 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, tagBuf));

    // Encrypt pretag with counter0 to get tag
    uint32_t outLen = 0U;
    MCUXCLBUFFER_INIT_RO(counter0Buf, NULL, pContext->counter0, MCUXCLAES_BLOCK_SIZE);
    MCUXCLBUFFER_INIT(blockBuf, NULL, pContext->cipherCtx.blockBuffer, MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->cipherAlgo->setupIVEncrypt(session, cipherWa, counter0Buf));

    /* Multiple software computations for cipher processing is required only for encryption */
    if (MCUXCLAEADMODES_DECRYPTION == pContext->encDecMode)
    {
      cipherWa->sgiWa.copyOutFunction = mcuxClCipherModes_copyOut_toPtr;
      cipherWa->sgiWa.protectionToken_copyOutFunction = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_copyOut_toPtr);
      MCUX_CSSL_FP_FUNCTION_CALL(retCipherEncrypt, pAlgo->cipherAlgo->encryptEngine(
        session,
        cipherWa,
        tagBuf,
        blockBuf, /* reuse blockBuffer for the encryption result, since we don't need it anymore */
        MCUXCLAES_BLOCK_SIZE,
        pContext->cipherCtx.ivState,
        &outLen));
      (void)retCipherEncrypt;

      MCUX_CSSL_FP_FUNCTION_CALL_VOID(pKeyChecksum->VerifyFunc(
        session,
        pKeyChecksum,
        (uint8_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_KEY0_OFFSET)));
    }
    else
    {
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCipherModes_crypt(
        session,
        cipherWa,
        tagBuf,
        blockBuf, /* reuse blockBuffer for the encryption result, since we don't need it anymore */
        MCUXCLAES_BLOCK_SIZE,
        pContext->cipherCtx.ivState,
        &outLen,
        pKeyChecksum,
        pAlgo->cipherAlgo->encryptEngine,
        pAlgo->cipherAlgo->protectionToken_encryptEngine));
    }
  }
  else
  { /* GCM */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadMaskedSubKeyFromCtx_Sgi(session,
                                                                     &(pContext->macCtx.HkeyContext)));


    /* Pad and process remaining ciphertext */
    mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_finalizeDataGMAC(session, macModesWorkArea, &pContext->macCtx));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_finalizeSizesGMAC(session, macModesWorkArea, &pContext->macCtx, pContext->inSize));

    /* encrypted tag is in SGI DATOUT, copy to pTag */
    MCUX_CSSL_DI_RECORD(sgiStore, ((uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET)) + ((uint32_t)pContext->cipherCtx.blockBuffer) + 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pContext->cipherCtx.blockBuffer));
  }

  /* RECORD of pTag not needed. Will be EXPUNGEd in Buffer_write, and balanced by the caller */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pContext->cipherCtx.blockBuffer);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pContext->tagSize);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pTag, 0U, (const uint8_t*)pContext->cipherCtx.blockBuffer, pContext->tagSize));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_CcmGcm_finish,
    MCUX_CSSL_FP_CONDITIONAL((0U != blockBufferUsedRef),
      pAlgo->cipherAlgo->protectionToken_addPadding,
      pAlgo->protectionToken_processFullBlocks
    ),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLAEADMODES_CCM == pAlgo->mode),
      pAlgo->macAlgo->protectionToken_finalize,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
      pAlgo->cipherAlgo->protectionToken_setupIVEncrypt,
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLAEADMODES_DECRYPTION == pContext->encDecMode),
        pAlgo->cipherAlgo->protectionToken_encryptEngine,
        pKeyChecksum->protectionToken_VerifyFunc
      ),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLAEADMODES_DECRYPTION != pContext->encDecMode),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt)
      )
    ),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLAEADMODES_GCM == pAlgo->mode),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadMaskedSubKeyFromCtx_Sgi),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_finalizeDataGMAC),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_finalizeSizesGMAC),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)
    ),
  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write)
  );
}
