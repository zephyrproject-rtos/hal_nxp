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

/** @file  mcuxClAeadModes_Sgi_Multipart.c
 *  @brief implementation of the multipart functions of the mcuxClAeadModes component */

#include <mcuxClCore_Platform.h>

#include <internal/mcuxClAeadModes_Common.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClAeadModes_Common_Functions.h>
#include <internal/mcuxClAeadModes_Sgi_Cleanup.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClAeadModes_Sgi_Functions.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <mcuxClAes.h>
#include <mcuxClAead_Types.h>
#include <mcuxClAead_Constants.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <mcuxClCore_Macros.h>
#include <internal/mcuxClMemory_CompareDPASecure_Internal.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClAeadModes_MemoryConsumption.h>
#include <mcuxClMemory.h>
#include <mcuxClResource_Types.h>
#include <internal/mcuxClCrc_Internal_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_init_encrypt_decrypt)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_init_encrypt_decrypt(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  uint32_t inLength,
  uint32_t adataLength,
  uint32_t tagLength,
  uint32_t encDecMode
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_init_encrypt_decrypt);

  MCUX_CSSL_DI_RECORD(tagLen, tagLength); /* Will be balanced after usage in mode->algorithm->init() */

  /* Allocate workarea */
  uint32_t const cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClAeadModes_WorkArea_t));

  mcuxClAeadModes_Context_t * const pCtx = mcuxClAeadModes_castToAeadModesContext(pContext);

  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClAeadModes_WorkArea_t*, workArea, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  workArea->sgiWa.pKeyChecksums = &(pCtx->cipherCtx.keyContext.keyChecksums);

  MCUX_CSSL_DI_RECORD(MultipartInitEnc_copyKeyContext, (uint32_t)&pCtx->macCtx.keyContext);
  MCUX_CSSL_DI_RECORD(MultipartInitEnc_copyKeyContext, (uint32_t)&pCtx->cipherCtx.keyContext);
  MCUX_CSSL_DI_RECORD(MultipartInitEnc_copyKeyContext, sizeof(mcuxClAes_KeyContext_Sgi_t));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  /* Initialize the SGI. From this point onwards, returning after any functional error must be done after flushing the SGI. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load key to SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKey_Sgi(session, key, &(workArea->sgiWa), MCUXCLSGI_DRV_KEY0_OFFSET));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_storeKeyInCtx_Sgi(session,
                                                            key,
                                                            &(pCtx->cipherCtx.keyContext),
                                                            &(workArea->sgiWa)));

  /* Copy the key context to mac context as well */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(
    (uint8_t*)&pCtx->macCtx.keyContext,
    (uint8_t const*)&pCtx->cipherCtx.keyContext,
    sizeof(mcuxClAes_KeyContext_Sgi_t)));

  pCtx->macCtx.keyContext.sgiCtrlKey = workArea->sgiWa.sgiCtrlKey;
  pCtx->cipherCtx.keyContext.sgiCtrlKey = workArea->sgiWa.sgiCtrlKey;

  /* HkeyContext will be aptly set during mcuxClMacModes_initGMAC. */
  pCtx->macCtx.HkeyContext.sgiCtrlKey = MCUXCLSGI_DRV_CTRL_INVALID;

  pCtx->encDecMode = encDecMode;
  MCUX_CSSL_DI_EXPUNGE(encDecModeDi, encDecMode);
  pCtx->common.mode = mode;

  pCtx->process = mode->algorithm->processEncDec;
  pCtx->protectionToken_process = mode->algorithm->protectionToken_processEncDec;

  /* Clear mac context fields */
  pCtx->macCtx.blockBufferUsed = 0U;
  pCtx->macCtx.dataProcessed = MCUXCLMACMODES_FALSE;
  pCtx->macCtx.totalInput = 0U;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mode->algorithm->init(
    session,
    pCtx,
    workArea,
    pNonce,
    nonceLength,
    inLength,
    adataLength,
    tagLength)
  );

  /* Init context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_cleanupOnMultipartExit(session, pCtx, cpuWaSizeInWords));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_init_encrypt_decrypt,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_storeKeyInCtx_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
    mode->algorithm->protectionToken_init,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_cleanupOnMultipartExit)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_init_encrypt, mcuxClAead_init_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_init_encrypt(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  uint32_t inLength,
  uint32_t adataLength,
  uint32_t tagLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_init_encrypt);

  MCUX_CSSL_DI_RECORD(encDecModeDi, MCUXCLAEADMODES_ENCRYPTION); /* Will be balanced in mcuxClAeadModes_init_encrypt_decrypt */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_init_encrypt_decrypt(
    session,
    pContext,
    key, mode,
    pNonce,
    nonceLength,
    inLength,
    adataLength,
    tagLength,
    MCUXCLAEADMODES_ENCRYPTION));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_init_encrypt,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_init_encrypt_decrypt)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_init_decrypt, mcuxClAead_init_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_init_decrypt(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  uint32_t inLength,
  uint32_t adataLength,
  uint32_t tagLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_init_decrypt);

  MCUX_CSSL_DI_RECORD(encDecModeDi, MCUXCLAEADMODES_DECRYPTION); /* Will be balanced in mcuxClAeadModes_init_encrypt_decrypt */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_init_encrypt_decrypt(
    session,
    pContext,
    key,
    mode,
    pNonce,
    nonceLength,
    inLength,
    adataLength,
    tagLength,
    MCUXCLAEADMODES_DECRYPTION));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_init_decrypt,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_init_encrypt_decrypt)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_process, mcuxClAead_process_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_process(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_process);

  mcuxClAeadModes_Context_t * const pCtx = mcuxClAeadModes_castToAeadModesContext(pContext);

  /* Check if input size will not overflow - SREQI_AEAD_9*/
  if (pCtx->inSize >= (UINT32_MAX - inLength))
  {
    /* No need to clear the context since this is a functional error. */
    MCUXCLSESSION_ERROR(session, MCUXCLAEAD_STATUS_INVALID_PARAM);
  }

  /* Check context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pCtx, MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  /* Allocate workarea */
  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClAeadModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClAeadModes_WorkArea_t*, workArea, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  /* Initialize the SGI. From this point onwards, returning after any functional error must be done after flushing the SGI. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load the key */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(session,
                                                            &(pCtx->cipherCtx.keyContext),
                                                            &(workArea->sgiWa)));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->process(
    session,
    pCtx,
    workArea,
    pIn,
    inLength,
    pOut,
    pOutLength));

  /* Update context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_cleanupOnMultipartExit(session, pCtx, cpuWaSizeInWords));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_process,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
    pCtx->protectionToken_process,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_cleanupOnMultipartExit)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_process_adata, mcuxClAead_process_aad_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_process_adata(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_process_adata);

  mcuxClAeadModes_Context_t * const pCtx = mcuxClAeadModes_castToAeadModesContext(pContext);

  /* Check context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pCtx, MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  /* Allocate workarea */
  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClAeadModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClAeadModes_WorkArea_t*, workArea, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  /* Initialize the SGI. From this point onwards, returning after any functional error must be done after flushing the SGI. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load the key */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(session,
                                                            &(pCtx->cipherCtx.keyContext),
                                                            &(workArea->sgiWa)));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->common.mode->algorithm->processAad(
    session,
    pCtx,
    workArea,
    pAdata,
    adataLength));

  /* Update context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_cleanupOnMultipartExit(session, pCtx, cpuWaSizeInWords));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_process_adata,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
    pCtx->common.mode->algorithm->protectionToken_processAad,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_cleanupOnMultipartExit)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_finish, mcuxClAead_finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_finish(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  mcuxCl_Buffer_t pTag
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_finish);

  MCUX_CSSL_DI_RECORD(tag, pTag); /* Will be balanced after usage in mode->algorithm->finish() */

  mcuxClAeadModes_Context_t * const pCtx = mcuxClAeadModes_castToAeadModesContext(pContext);

  /* Check context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pCtx, MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  /* Allocate workarea */
  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClAeadModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClAeadModes_WorkArea_t*, workArea, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  /* Initialize the SGI. From this point onwards, returning after any functional error must be done after flushing the SGI. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load the key */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(session,
                                                            &(pCtx->cipherCtx.keyContext),
                                                            &(workArea->sgiWa)));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->common.mode->algorithm->finish(
    session,
    pCtx,
    workArea,
    pOut,
    pOutLength,
    pTag));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_cleanupOnMultipartExit(session, pCtx, cpuWaSizeInWords));

  /* Clear cipher key context.
   * Clear the context after the call to mcuxClAeadModes_cleanupOnMultipartExit to not loose the key information too soon. */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, &pCtx->cipherCtx.keyContext);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, sizeof(mcuxClAes_KeyContext_Sgi_t));
  MCUXCLMEMORY_CLEAR_INT((uint8_t *)&pCtx->cipherCtx.keyContext, sizeof(mcuxClAes_KeyContext_Sgi_t));

  /* Clear mac key context */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, &pCtx->macCtx.keyContext);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, sizeof(mcuxClAes_KeyContext_Sgi_t));
  MCUXCLMEMORY_CLEAR_INT((uint8_t *)&pCtx->macCtx.keyContext, sizeof(mcuxClAes_KeyContext_Sgi_t));

  /* Clear counter0 */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, pCtx->counter0);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, MCUXCLAES_BLOCK_SIZE);
  MCUXCLMEMORY_CLEAR_INT((uint8_t *)pCtx->counter0, MCUXCLAES_BLOCK_SIZE);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_finish,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
    pCtx->common.mode->algorithm->protectionToken_finish,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_cleanupOnMultipartExit),
    3U * MCUXCLMEMORY_CLEAR_INT_FP_EXPECT
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_verify, mcuxClAead_verify_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_verify(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pTag,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_verify);

  mcuxClAeadModes_Context_t * const pCtx = mcuxClAeadModes_castToAeadModesContext(pContext);

  MCUX_CSSL_DI_RECORD(tagSize, pCtx->tagSize); /* Will be balanced in mcuxClMemory_compare_dpasecure_int() */
  /* pTag will be protected after mcuxClBuffer_inputBufferToCPU() */

  /* Check context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pContext, MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  /* Allocate workarea */
  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClAeadModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClAeadModes_WorkArea_t*, workArea, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  uint8_t *pComputedTag = &workArea->cpuWa.tagBuffer[MCUXCLAEADMODES_TAGLEN_MAX];

  MCUXCLBUFFER_INIT(computedTagBuffer, NULL, pComputedTag, MCUXCLAEADMODES_TAGLEN_MAX);
  MCUX_CSSL_DI_RECORD(computedTag, pComputedTag); /* Will be balanced in mcuxClMemory_compare_dpasecure_int() */
  MCUX_CSSL_DI_RECORD(finishTagbuff, computedTagBuffer); /* Will be balanced after usage in mode->algorithm->finish() */

  /* Request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

  /* Initialize the SGI. From this point onwards, returning after any functional error must be done after flushing the SGI. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load the key */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(session,
                                                            &(pCtx->cipherCtx.keyContext),
                                                            &(workArea->sgiWa)));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->common.mode->algorithm->finish(
    session,
    pCtx,
    workArea,
    pOut,
    pOutLength,
    computedTagBuffer));

  /* Prepare the reference tag. For buffer-objects with DMA, this will import the tag to a CPU buffer before comparison. */
  const uint8_t *pReferenceTag;
  mcuxClBuffer_inputBufferToCPU(pTag, 0U, workArea->cpuWa.tagBuffer, &pReferenceTag, pCtx->tagSize);
  MCUX_CSSL_DI_RECORD(referenceTag, pReferenceTag); /* Will be balanced in mcuxClMemory_compare_dpasecure_int() */

  /* Compare authentication tags */
  MCUX_CSSL_FP_FUNCTION_CALL(compareStatus, mcuxClMemory_compare_dpasecure_int(session, pReferenceTag, pComputedTag, pCtx->tagSize));
  MCUX_CSSL_DI_RECORD(compareStatus, compareStatus);

  mcuxClAead_Status_t retCode = MCUXCLAEAD_STATUS_FAULT_ATTACK;

  if (MCUXCLMEMORY_STATUS_NOT_EQUAL == compareStatus)
  {
    // Tag is invalid
    MCUX_CSSL_DI_EXPUNGE(compareNotOk, MCUXCLAEADMODES_INTERNAL_COMP_NOT_OK);
    retCode = MCUXCLAEAD_STATUS_INVALID_TAG;
  }
  else if (MCUXCLMEMORY_STATUS_EQUAL == compareStatus)
  {
    MCUX_CSSL_DI_EXPUNGE(compareOk, MCUXCLAEADMODES_INTERNAL_COMP_OK);
    retCode = MCUXCLAEAD_STATUS_OK;
  }
  else
  {
    MCUXCLSESSION_FAULT(session, MCUXCLAEAD_STATUS_FAULT_ATTACK);
  }

  MCUX_CSSL_DI_RECORD(returnCode, retCode);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAeadModes_cleanupOnMultipartExit(session, pCtx, cpuWaSizeInWords));

  /* Clear cipher key context.
   * Clear the context after the call to mcuxClAeadModes_cleanupOnMultipartExit to not loose the key information too soon. */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, &pCtx->cipherCtx.keyContext);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, sizeof(mcuxClAes_KeyContext_Sgi_t));
  MCUXCLMEMORY_CLEAR_INT((uint8_t *)&pCtx->cipherCtx.keyContext, sizeof(mcuxClAes_KeyContext_Sgi_t));

  /* Clear mac key context */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, &pCtx->macCtx.keyContext);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, sizeof(mcuxClAes_KeyContext_Sgi_t));
  MCUXCLMEMORY_CLEAR_INT((uint8_t *)&pCtx->macCtx.keyContext, sizeof(mcuxClAes_KeyContext_Sgi_t));

  /* Clear counter0 */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, pCtx->counter0);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int, MCUXCLAES_BLOCK_SIZE);
  MCUXCLMEMORY_CLEAR_INT((uint8_t *)pCtx->counter0, MCUXCLAES_BLOCK_SIZE);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_verify, retCode,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
    pCtx->common.mode->algorithm->protectionToken_finish,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_compare_dpasecure_int),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_cleanupOnMultipartExit),
    3U * MCUXCLMEMORY_CLEAR_INT_FP_EXPECT
  );
}
