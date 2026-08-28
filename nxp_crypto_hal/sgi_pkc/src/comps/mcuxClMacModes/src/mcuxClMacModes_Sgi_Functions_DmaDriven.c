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

#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

#include <internal/mcuxClResource_Internal_Types.h>

#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Utils.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Resource.h>

#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>

#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClBuffer.h>
#include <mcuxClAes.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClMacModes_MemoryConsumption.h>

#include <internal/mcuxClCrc_Internal_Functions.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMacModes_Common_Functions.h>
#include <internal/mcuxClMacModes_Common_Constants.h>
#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Cleanup.h>

#include <mcuxCsslDataIntegrity.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *pWa,
  mcuxClSession_HwInterruptHandler_t callbackFunction,
  uint32_t protectionToken_callbackFunction
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_request(
    session,
    mcuxClSession_getDmaInputChannel(session),
    callbackFunction,
    protectionToken_callbackFunction
  ));

  mcuxClSession_job_setClWorkarea(session, (void*) pWa);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_request)
  );
}


/* Mode functions and ISRs */


/* Non-blocking compute mode function */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_compute_dmaDriven, mcuxClMac_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_compute_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_compute_dmaDriven);

  mcuxClMacModes_Algorithm_t pAlgo = (mcuxClMacModes_Algorithm_t) mode->common.pAlgorithm;

  /* Allocate workarea */
  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClMacModes_WorkArea_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClMacModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  mcuxClKey_KeyChecksum_t keyChecksums;
  pWa->sgiWa.pKeyChecksums = &keyChecksums;

  /* Initialize/request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load key to SGI and Store configuration data in workarea*/
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKey_Sgi(session, key, &(pWa->sgiWa), MCUXCLSGI_DRV_KEY0_OFFSET));

  /* Request DMA channel */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext(
    session, pWa, mcuxClMacModes_ISR_completeNonBlocking_compute,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_ISR_completeNonBlocking_compute)));

  /* Configure fields in the workarea to be available after call to engine (for blocking and non-blocking case) */
  pWa->nonBlockingWa.pMode = mode;
  pWa->nonBlockingWa.inLength = inLength;
  pWa->nonBlockingWa.pIn = pIn;
  pWa->nonBlockingWa.inputOffset = 0U;
  pWa->nonBlockingWa.pMac.output = pMac;
  pWa->nonBlockingWa.pOutputLength = pMacLength;
  pWa->nonBlockingWa.macLength = mode->common.macByteSize;
  pWa->nonBlockingWa.processedBytes = 0U;

  /* Perform MAC operation */
  MCUX_CSSL_FP_FUNCTION_CALL(status, pAlgo->compute(
    session,
    pWa, mode,
    pIn,
    inLength,
    &pWa->nonBlockingWa.processedBytes));

  uint32_t processedBytes = pWa->nonBlockingWa.processedBytes;

  if(MCUXCLMAC_STATUS_JOB_STARTED == status)
  {
    /* Early return for non-blocking */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_compute_dmaDriven, MCUXCLMAC_STATUS_JOB_STARTED,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext),
          pAlgo->protectionToken_compute
    );
  }

  /* Continue operation in case no non-blocking operation was started*/
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(processedBytes, 0U, inLength, MCUXCLMAC_STATUS_ERROR)
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->handleLastBlock_oneshot(
    session, pWa, pAlgo,
    /* pIn, inOffset    */  pIn, processedBytes,
    /* totalInputLength */  inLength,
    /* remainingBytes   */  (inLength - processedBytes)));

  /* Output result of MAC operation to result buffer */
  uint32_t dataProcessed = (0U < inLength) ? MCUXCLMACMODES_TRUE : MCUXCLMACMODES_FALSE;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->copyOut(session, dataProcessed, pMac, pMacLength));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_cleanupOnExit_dmaDriven(session, NULL, key, cpuWaSizeInWords));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_compute_dmaDriven, MCUXCLMAC_STATUS_OK,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKey_Sgi),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext),
          pAlgo->protectionToken_compute,
          pAlgo->protectionToken_handleLastBlock_oneshot,
          pAlgo->protectionToken_copyOut,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_cleanupOnExit_dmaDriven)
    );
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_ISR_completeNonBlocking_compute, mcuxClSession_HwInterruptHandler_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_ISR_completeNonBlocking_compute(
  mcuxClSession_Handle_t session
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_ISR_completeNonBlocking_compute);

  mcuxClMacModes_WorkArea_t * pWa = (mcuxClMacModes_WorkArea_t *) session->jobContext.pClWorkarea;
  mcuxClMacModes_Algorithm_t pAlgo = (mcuxClMacModes_Algorithm_t) pWa->nonBlockingWa.pMode->common.pAlgorithm;

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);

  /* Wait for DONE (just in case) and check errors, and clear DONE flag */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

  /* SGI needs a manual stop once all data is processed (or on DMA channel error). Disable interrupts. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes(inputChannel));
  mcuxClDma_Drv_disableChannelDoneInterrupts(inputChannel);
  mcuxClDma_Drv_disableErrorInterrupts(inputChannel);

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClMacModes_WorkArea_t));

  /* Increase input pointer by already processed bytes */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Total inputOffset has an upper bound of inLength")
  pWa->nonBlockingWa.inputOffset += pWa->nonBlockingWa.processedBytes;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->handleLastBlock_oneshot(
    session, pWa, pAlgo,
    /* pIn, inOffset    */  pWa->nonBlockingWa.pIn, pWa->nonBlockingWa.inputOffset,
    /* totalInputLength */  pWa->nonBlockingWa.inLength,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pWa->nonBlockingWa.inLength >= pWa->nonBlockingWa.processedBytes, so does not wrap ")
    /* remainingBytes   */  (pWa->nonBlockingWa.inLength - pWa->nonBlockingWa.processedBytes)
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  ));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  /* Output result of MAC operation to result buffer */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->copyOut(session, MCUXCLMACMODES_TRUE, pWa->nonBlockingWa.pMac.output,
                                           pWa->nonBlockingWa.pOutputLength));

  /* Notify the user that the operation finished */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_cleanupOnExit_dmaDriven(
    session,
    NULL,
    NULL /* TODO CLNS-16946: store keys in nonBlocking WA and flush it here */,
    cpuWaSizeInWords));

  MCUX_CSSL_FP_FUNCTION_CALL(retSessionTriggerCallback, mcuxClSession_triggerUserCallback(session, MCUXCLMAC_STATUS_JOB_COMPLETED));
  if(MCUXCLSESSION_STATUS_OK != retSessionTriggerCallback)
  {
    MCUXCLSESSION_ERROR(session, retSessionTriggerCallback);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_ISR_completeNonBlocking_compute,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes),
            pAlgo->protectionToken_handleLastBlock_oneshot,
            pAlgo->protectionToken_copyOut,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_cleanupOnExit_dmaDriven),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_triggerUserCallback)
  );
}




/* Non-blocking process mode function */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_process_dmaDriven, mcuxClMac_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_process_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_process_dmaDriven);

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClMacModes_WorkArea_t));

  mcuxClMacModes_Context_t * const pCtx = mcuxClMacModes_castToMacModesContext(pContext);

  /* Check context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(session, pContext, MCUXCLMACMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  if(0U == inLength)
  {
    /* Nothing to do */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_process_dmaDriven, MCUXCLMAC_STATUS_OK
            ,MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc)
    );
  }

  /* Allocate workarea - only nonBlocking WA needed */
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClMacModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords));

  mcuxClMacModes_Algorithm_t pAlgo = mcuxClMacModes_castToMacModesAlgorithm(pCtx->common.pMode->common.pAlgorithm);

  /* Initialize/request SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(session, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE, NULL, 0U));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


  /* Load key to SGI and Store configuration data in workarea*/
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(
    session,
    &(pCtx->keyContext),
    NULL));

  /* Request DMA channel */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext(session, pWa, mcuxClMacModes_ISR_completeNonBlocking_multipart,
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_ISR_completeNonBlocking_multipart)));

  /* Configure fields in the workarea/context to be available after call to engine (for blocking and non-blocking case) */
  pWa->nonBlockingWa.pMode = pCtx->common.pMode;
  pWa->nonBlockingWa.pContext = pCtx;
  pWa->nonBlockingWa.pIn = pIn;
  pWa->nonBlockingWa.inputOffset = 0U;
  pWa->nonBlockingWa.inLength = inLength;
  pWa->nonBlockingWa.processedBytes = 0U;

  /* Call update function */
  MCUX_CSSL_FP_FUNCTION_CALL(status, pAlgo->update(
    session,
    pWa,
    pCtx,
    pIn,
    inLength,
    &pWa->nonBlockingWa.processedBytes));

  uint32_t processedBytes = pWa->nonBlockingWa.processedBytes;

  if(MCUXCLMAC_STATUS_JOB_STARTED == status)
  {
    /* Early exit for non-blocking */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_process_dmaDriven, MCUXCLMAC_STATUS_JOB_STARTED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext),
            pAlgo->protectionToken_update);
  }


  /* Continue operation in case no non-blocking operation was started */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(processedBytes, 0U, inLength, MCUXCLMAC_STATUS_ERROR)
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_handleLastBlock_update(
    session,
    pCtx,
    /* pIn, inOffset    */ pIn,
    processedBytes,
    /* remainingBytes   */ (inLength - processedBytes)));

  /* Update context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, MCUXCLMACMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_cleanupOnExit_dmaDriven(session, pCtx, NULL /* key is in context */, cpuWaSizeInWords));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_process_dmaDriven, MCUXCLMAC_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext),
            pAlgo->protectionToken_update,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_handleLastBlock_update),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_cleanupOnExit_dmaDriven)
  );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_ISR_completeNonBlocking_multipart, mcuxClSession_HwInterruptHandler_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_ISR_completeNonBlocking_multipart(
  mcuxClSession_Handle_t session
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_ISR_completeNonBlocking_multipart);

  mcuxClMacModes_WorkArea_t * pWa = (mcuxClMacModes_WorkArea_t *) session->jobContext.pClWorkarea;
  mcuxClMacModes_Context_t * pContext = pWa->nonBlockingWa.pContext;

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);

    /* Wait for data copy to finish and check for errors */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

  /* SGI needs a manual stop once all data is processed (or on DMA channel error). Disable interrupts. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes(inputChannel));
  mcuxClDma_Drv_disableChannelDoneInterrupts(inputChannel);
  mcuxClDma_Drv_disableErrorInterrupts(inputChannel);

  const uint32_t cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClMacModes_WorkArea_t));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pWa->nonBlockingWa.inLength >= pWa->nonBlockingWa.processedBytes, so does not wrap ")
  const uint32_t remainingBytes = pWa->nonBlockingWa.inLength - pWa->nonBlockingWa.processedBytes;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  /* Increase input pointer by bytes written by AUTO mode */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Total inputOffset has an upper bound of inLength")
  pWa->nonBlockingWa.inputOffset += pWa->nonBlockingWa.processedBytes;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("The pWa->nonBlockingWa.inputOffset and remainingBytes values did not overflow (see above), so passing them here is safe")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_handleLastBlock_update(
    session,
    pContext,
    pWa->nonBlockingWa.pIn,
    pWa->nonBlockingWa.inputOffset,
    remainingBytes
  ));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  /* Update context CRC */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pWa->nonBlockingWa.pContext, MCUXCLMACMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_cleanupOnExit_dmaDriven(
    session,
    pContext,
    NULL /* Key is in context */,
    cpuWaSizeInWords
  ));

  /* Notify the user that the operation finished */
  MCUX_CSSL_FP_FUNCTION_CALL(retSessionTriggerCallback, mcuxClSession_triggerUserCallback(session, MCUXCLMAC_STATUS_JOB_COMPLETED));
  if(MCUXCLSESSION_STATUS_OK != retSessionTriggerCallback)
  {
    MCUXCLSESSION_ERROR(session, retSessionTriggerCallback);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_ISR_completeNonBlocking_multipart,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_handleLastBlock_update),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_cleanupOnExit_dmaDriven),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_triggerUserCallback)
  );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_handleLastBlock_update)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_handleLastBlock_update(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t session,
  mcuxClMacModes_Context_t * pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t remainingBytes
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_handleLastBlock_update);

  /* Store intermediate result (pre-tag) in context.
    Note that the preTag in the context is not considered I/O, so DMA transfer is not necessary. */
  const uint32_t *pSrc_sgiDatout = (const uint32_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET);
  uint32_t *pDst_maskedPreTag = pContext->maskedPreTag;
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t) pDst_maskedPreTag);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t) pSrc_sgiDatout);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, 16U);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copyBlockSfrMasked(
    pDst_maskedPreTag,
    pSrc_sgiDatout,
    pContext->keyContext.sfrSeed));

  /* Known bug in SGI AUTO mode: if AUTO_MODE.CMD is not reset to 0 here, subsequent SGI operations will not work.
     Workaround: wait for SGI and reset AUTO_MODE to 0. To be removed in CLNS-7392 once fixed in HW. */
  mcuxClSgi_Drv_wait(); /* Known limitation: wait for SGI busy flag to be de-asserted before overwriting AUTO mode CMD */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_resetAutoMode());

  /* Fill context buffer with remaining input bytes */
  if(remainingBytes > 0U)
  {
    mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
    MCUXCLBUFFER_DERIVE_RO(pInWithOffset, pIn, inOffset);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureDataTransfer(
      inputChannel,
      MCUXCLBUFFER_GET(pInWithOffset),
      &((uint8_t *)pContext->blockBuffer)[pContext->blockBufferUsed],
      remainingBytes));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_startChannel(inputChannel));

    /* Wait for data copy to finish and check for errors */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

    pContext->blockBufferUsed = remainingBytes;
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(
    mcuxClMacModes_handleLastBlock_update,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copyBlockSfrMasked),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_resetAutoMode),
    MCUX_CSSL_FP_CONDITIONAL(
      (remainingBytes > 0U),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureDataTransfer),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_startChannel),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone)
    ));
}

