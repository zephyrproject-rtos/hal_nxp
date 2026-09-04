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

/** @file  mcuxClAeadModes_Sgi_Gcm.c
 *  @brief Implementation of the GCM mode for the mcuxClAeadModes component */

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Toolchain.h>

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClCipher.h>
#include <mcuxClMacModes.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <mcuxClToolchain.h>

#include <internal/mcuxClAeadModes_Common.h>
#include <internal/mcuxClAeadModes_Sgi_Algorithms.h>
#include <internal/mcuxClAeadModes_Sgi_Types.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClCipherModes_Sgi_Algorithms.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClCipherModes_Sgi_Functions.h>
#include <internal/mcuxClCipherModes_Sgi_Types.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMacModes_Sgi_Algorithms.h>
#include <internal/mcuxClMacModes_Common_Types.h>
#include <internal/mcuxClMacModes_Sgi_Gmac.h>
#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClAeadModes_Common_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_castToMacCustomMode)
static mcuxClMac_CustomMode_t mcuxClAeadModes_castToMacCustomMode(uint32_t* pMode)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClMac_CustomMode_t) pMode;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

/**
 * @brief Function to prepare initial state for the GCM
 *
 * Data Integrity: Expunge(tagSize)
 *
 * @param      session          Handle for the current CL session.
 * @param      pContext         Pointer to multipart context
 * @param[in]  workArea         Pointer to work area
 * @param[in]  pNonce           Pointer to nonce
 * @param[in]  nonceSize        Size of nonce
 * @param[in]  inSize           Input size not use for the GCM
 * @param[in]  adataSize        Adata size
 * @param[in]  tagSize          Tag size
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_GCM_init, mcuxClAeadModes_alg_init_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_GCM_init(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t* const pContext,
  mcuxClAeadModes_WorkArea_t* workArea,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceSize,
  uint32_t inSize UNUSED_PARAM,
  uint32_t adataSize UNUSED_PARAM,
  uint32_t tagSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_GCM_init);

  MCUX_CSSL_DI_RECORD(GCMinit_clearIv, (uint32_t)pContext->cipherCtx.ivState);
  MCUX_CSSL_DI_RECORD(GCMinit_clearIv, MCUXCLAES_BLOCK_SIZE);

  MCUX_CSSL_DI_RECORD(GCMinit_copyIv, (uint32_t)pContext->cipherCtx.ivState);
  MCUX_CSSL_DI_RECORD(GCMinit_copyIv, (uint32_t)pContext->macCtx.counter0);
  MCUX_CSSL_DI_RECORD(GCMinit_copyIv, MCUXCLAES_BLOCK_SIZE);

  const mcuxClAeadModes_AlgorithmDescriptor_t *alg = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);

  /* Clear The IV state in the cipher context */
  MCUXCLMEMORY_CLEAR_INT((uint8_t *)pContext->cipherCtx.ivState, MCUXCLAES_BLOCK_SIZE);

  /* Set some AEAD context fields to initialize them properly (even if unused) */
  pContext->adataSize = 0U; // unused for GCM
  pContext->adataCumulativeSize = 0U; // unused for GCM
  pContext->inSize = 0U; // unused for GCM
  pContext->cipherCtx.common.blockBufferUsed = 0U;
  pContext->tagSize = tagSize;

  /* Construct the GMAC mode */
  mcuxClMac_CustomMode_t gmacMode = mcuxClAeadModes_castToMacCustomMode(workArea->gmacModeDescBuf);

  MCUX_CSSL_FP_FUNCTION_CALL(retMacCreateGmacMode, mcuxClMacModes_createGmacMode(gmacMode, pNonce, nonceSize));
  (void)retMacCreateGmacMode;

  pContext->macCtx.common.pMode = gmacMode;

  /* Prepare masked pre-tag in macCtx */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_initMaskedPreTag(&pContext->macCtx));

  /* Init mac, internally computes J0 and setups up Hkey internally in the mac ctx */
  mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(alg->macAlgo->init(session, macModesWorkArea, &pContext->macCtx));

  /* Copy counterInput, we need it for en/decrypting */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int((uint8_t *)pContext->cipherCtx.ivState, (const uint8_t*)pContext->macCtx.counter0, MCUXCLAES_BLOCK_SIZE));

  if(12U == nonceSize)
  {
    pContext->cipherCtx.ivState[3] = (pContext->cipherCtx.ivState[3] & 0x00ffffffU) | ((uint32_t)0x02U << 24U);
  }
  else
  {
    uint32_t *pCounter = &pContext->cipherCtx.ivState[3];
    /* UINT32_MAX == swap(UINT32_MAX) */
    if (UINT32_MAX == *pCounter)
    {
      MCUXCLSESSION_ERROR(session, MCUXCLAEAD_STATUS_INVALID_PARAM);
    }
    *pCounter = mcuxCl_Core_Swap32(mcuxCl_Core_Swap32(*pCounter) + 1U);
  }

  MCUX_CSSL_DI_EXPUNGE(tagSize, pContext->tagSize);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_GCM_init,
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_createGmacMode),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_initMaskedPreTag),
    alg->macAlgo->protectionToken_init,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_GCM_process_aad, mcuxClAeadModes_alg_process_aad_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_GCM_process_aad(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t* const pContext,
  mcuxClAeadModes_WorkArea_t* workArea UNUSED_PARAM,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_GCM_process_aad);

  const mcuxClAeadModes_AlgorithmDescriptor_t *alg = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);

  mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);
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

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_GCM_process_aad,
    alg->macAlgo->protectionToken_update
  );
}
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_Gcm_process, mcuxClAeadModes_alg_process_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_Gcm_process(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_Gcm_process);

  /* Check if some remaining data is left in the Mac blockBuffer while the Cipher blockBuffer is empty -
   * this indicates that it is the first call to Aead_process, and that the handling of the remaining adata bytes
   * (if any in the blockBuffer) needs to be done first. */
  MCUX_CSSL_FP_COUNTER_STMT(const volatile uint32_t blockBufferUsedRef = pContext->macCtx.blockBufferUsed);
  if(0U != pContext->macCtx.blockBufferUsed)
  {
    mcuxClMacModes_WorkArea_t* macModesWorkArea = mcuxClAeadModes_castToMacModesWorkArea(workArea);

    /* Load the H-key */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadMaskedSubKeyFromCtx_Sgi(session,
                                                                     &(pContext->macCtx.HkeyContext)));

    /* Process remaining adata and create pretag */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_finalizeDataGMAC(session, macModesWorkArea, &pContext->macCtx));

    /* finalizeAadGMAC sets macCtx.blockBufferUsed to 0 */
  }

  /* Process the input */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_CcmGcm_process(session, pContext, workArea, pIn, inSize, pOut, pOutSize));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_Gcm_process,
    MCUX_CSSL_FP_CONDITIONAL((0U != blockBufferUsedRef),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadMaskedSubKeyFromCtx_Sgi),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_finalizeDataGMAC)
    ),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CcmGcm_process)
  );
}

/* Mac-then-Encrypt/Encrypt-then-Mac core for GCM mode*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_Gcm_processFullBlocks, mcuxClAeadModes_ProcessFullBlocks_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_Gcm_processFullBlocks(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  const uint32_t inSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_Gcm_processFullBlocks);

  const mcuxClAeadModes_AlgorithmDescriptor_t *pAlgo = mcuxClAeadModes_castToAeadModesAlgorithmDescriptor(pContext->common.mode->algorithm);

  mcuxClCipherModes_WorkArea_t *cipherWa = mcuxClAeadModes_castToCipherModesWorkArea(workArea);
  mcuxClKey_KeyChecksum_t* pKeyChecksum = &pContext->cipherCtx.keyContext.keyChecksums;

  if(MCUXCLAEADMODES_DECRYPTION == pContext->encDecMode)
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

  cipherWa->ctrSize = MCUXCLAEADMODES_GCM_CTR_SIZE;

  /* Multiple software computations for CCM decryption is not necessary */
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
    pAlgo->cipherAlgo->protectionToken_encryptEngine));

  if(MCUXCLAEADMODES_ENCRYPTION == pContext->encDecMode)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_updateMac(
      session,
      pContext,
      workArea,
      pOut,
      inSize));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_Gcm_processFullBlocks,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_updateMac), /* mcuxClAeadModes_updateMac called once, for both ENCRYPTION and DECRYPTION */
    pAlgo->cipherAlgo->protectionToken_setupIVEncrypt,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_crypt)
  );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClAeadModes_AlgorithmDescriptor_t mcuxClAeadModes_AlgorithmDescriptor_Gcm =
{
  .init                               = mcuxClAeadModes_GCM_init,
  .protectionToken_init               = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_GCM_init),
  .processAad                         = mcuxClAeadModes_GCM_process_aad,
  .protectionToken_processAad         = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_GCM_process_aad),
  .processEncDec                      = mcuxClAeadModes_Gcm_process,
  .protectionToken_processEncDec      = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_Gcm_process),
  .processFullBlocks                  = mcuxClAeadModes_Gcm_processFullBlocks,
  .protectionToken_processFullBlocks  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_Gcm_processFullBlocks),
  .finish                             = mcuxClAeadModes_CcmGcm_finish,
  .protectionToken_finish             = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_CcmGcm_finish),
  .mode = MCUXCLAEADMODES_GCM,

  .macAlgo = &mcuxClMacModes_AlgorithmDescriptor_GMAC,
  .cipherAlgo = &mcuxClCipherModes_AlgorithmDescriptor_CTR_Sgi
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
