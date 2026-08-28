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

#include <mcuxClToolchain.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClCore_Macros.h>
#include <mcuxClMac.h>
#include <mcuxClMacModes_MemoryConsumption.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Sgi_Cmac.h>
#include <internal/mcuxClMacModes_Sgi_Algorithms.h>

#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClAes.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Utils.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClDma_Resource.h>
#include <mcuxClBuffer.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

/* CMAC with DMA, non-blocking mode */
const mcuxClMacModes_AlgorithmDescriptor_t mcuxClMacModes_AlgorithmDescriptor_CMAC_NonBlocking =
{
  .compute = mcuxClMacModes_computeCMAC_nonBlocking,
  .protectionToken_compute =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_computeCMAC_nonBlocking),
  .handleLastBlock_oneshot = mcuxClMacModes_handleLastBlock_cmac_oneshot,
  .protectionToken_handleLastBlock_oneshot =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_handleLastBlock_cmac_oneshot),
  .init = NULL, /* no init needed */
  .update = mcuxClMacModes_updateCMAC_nonBlocking,
  .protectionToken_update =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_updateCMAC_nonBlocking),
  .finalize = mcuxClMacModes_finalizeCMAC, /* no special DMA handling needed for blocking finalize */
  .protectionToken_finalize =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_finalizeCMAC),
  .copyOut = mcuxClMacModes_CopyOutDma,
  .protectionToken_copyOut =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CopyOutDma),
  .addPadding = mcuxClPadding_addPadding_MAC_ISO9797_1_Method2,
  .protectionToken_addPadding =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2),
};

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()


/* Non-blocking CMAC compute engine */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_computeCMAC_nonBlocking, mcuxClMacModes_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_computeCMAC_nonBlocking(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * workArea,
  mcuxClMac_Mode_t mode UNUSED_PARAM,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_computeCMAC_nonBlocking);

  if(inLength > MCUXCLDMA_UTILS_SGI_AUTOMODE_MAX_INPUT_SIZE)
  {
    MCUXCLSESSION_ERROR(session, MCUXCLMAC_STATUS_INVALID_PARAM);
  }

  mcuxClMac_Status_t status = MCUXCLMAC_STATUS_ERROR;

  uint32_t lastBlockLength = (0U != inLength) ? ((inLength - 1U) % MCUXCLAES_BLOCK_SIZE + 1U) : 0U; /* length of the last block */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("inLength is at least lastBlockLength long")
  uint32_t fullBlocksLength = inLength - lastBlockLength; /* length of all full blocks, except the last one (if full) */
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  /* Load all-zero IV to DATOUT (needed by AUTO mode CMAC) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_loadZeroIV());

  uint32_t sgiCtrl = MCUXCLSGI_DRV_CTRL_ENC            |
                     workArea->sgiWa.sgiCtrlKey;

  uint32_t nrOfBlocks = fullBlocksLength /  MCUXCLAES_BLOCK_SIZE;
  *pProcessedBytes = nrOfBlocks * MCUXCLAES_BLOCK_SIZE;

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);

  if(1U == nrOfBlocks)
  {
    /* For only one block of data, SGI AUTO-mode is not needed. */

    /* Copy input to SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputChannel(session, MCUXCLSGI_DRV_DATIN0_OFFSET, MCUXCLBUFFER_GET(pIn)));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(inputChannel));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

    /* Perform crypt operation */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_END_UP                  |
                                                      MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT | /* IV stored in DATOUT, P0 ^ IV */
                                                      MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
                                                      sgiCtrl));

    mcuxClSgi_Drv_wait();

    status = MCUXCLMAC_STATUS_OK;
  }
  else if(nrOfBlocks > 1U)
  {
    /* For multiple blocks, use SGI AUTO mode with handshakes, non-blocking */

    /* Configure the DMA channels */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputWithHandshakes(
      session,
      MCUXCLSGI_DRV_DATIN0_OFFSET,
      MCUXCLBUFFER_GET(pIn)));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks(session, nrOfBlocks));

    /* Enable interrupts for the completion of the input channel, and for errors. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableChannelDoneInterrupts(inputChannel));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableErrorInterrupts(inputChannel));

    /* Enable SGI AUTO mode CBC */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureAutoMode(MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CMAC));

    /* Start the operation - this will start the SGI-DMA interaction in the background, CPU is not blocked */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_startAutoModeWithHandshakes(
      sgiCtrl | MCUXCLSGI_DRV_CTRL_NO_UP,
      MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_DISABLE));

    status = MCUXCLMAC_STATUS_JOB_STARTED;
  }
  else /* nrOfBlocks = 0 */
  {
    status = MCUXCLMAC_STATUS_OK;
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_computeCMAC_nonBlocking, status,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_loadZeroIV),
    MCUX_CSSL_FP_CONDITIONAL( (1U == nrOfBlocks),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputChannel),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)),
    MCUX_CSSL_FP_CONDITIONAL( (nrOfBlocks > 1U),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputWithHandshakes),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableChannelDoneInterrupts),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableErrorInterrupts),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureAutoMode),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_startAutoModeWithHandshakes))
  );
}

MCUX_CSSL_FP_COUNTER_STMT(
/* balancing the FP for non-blocking CMAC update engine */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_updateCMAC_nonBlocking_balancingFP)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_updateCMAC_nonBlocking_balancingFP(uint32_t blockBufferUsed_FP,
                                                                                         uint32_t blockBufferUsed_FP_2,
                                                                                         uint32_t remainingInputBytes_FP,
                                                                                         uint32_t nrOfBlocks)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_updateCMAC_nonBlocking_balancingFP);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_updateCMAC_nonBlocking_balancingFP,
      MCUX_CSSL_FP_CONDITIONAL( ((blockBufferUsed_FP > 0U) && (MCUXCLAES_BLOCK_SIZE != blockBufferUsed_FP)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureDataTransfer),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_startChannel),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copyBlockSfrMasked),
      MCUX_CSSL_FP_CONDITIONAL( ((MCUXCLAES_BLOCK_SIZE == blockBufferUsed_FP_2) &&
                        (remainingInputBytes_FP > 0U)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)),
      MCUX_CSSL_FP_CONDITIONAL((1U == nrOfBlocks),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputChannel),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)),
      MCUX_CSSL_FP_CONDITIONAL((nrOfBlocks > 1U),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputWithHandshakes),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableChannelDoneInterrupts),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableErrorInterrupts),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureAutoMode),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_startAutoModeWithHandshakes))
            );
})

/* Non-blocking CMAC update engine */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_updateCMAC_nonBlocking, mcuxClMacModes_UpdateFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_updateCMAC_nonBlocking(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea UNUSED_PARAM,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_updateCMAC_nonBlocking);

  if(inLength > MCUXCLDMA_UTILS_SGI_AUTOMODE_MAX_INPUT_SIZE)
  {
    MCUXCLSESSION_ERROR(session, MCUXCLMAC_STATUS_INVALID_PARAM);
  }

  if(pContext->totalInput > (UINT32_MAX - inLength))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLMAC_STATUS_INVALID_PARAM);
  }

  pContext->totalInput += inLength;

  /* Local input buffer */
  MCUXCLBUFFER_DERIVE_RO(pInLocal, pIn, 0U);

  /* Setup the general SGI configuration */
  uint32_t sgiCtrl = MCUXCLSGI_DRV_CTRL_ENC            |
                     pContext->keyContext.sgiCtrlKey;

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);

  /* If context buffer has bytes, fill the rest of the context buffer with input data; copy as many bytes as possible */
  uint32_t bytesToCopy = 0U;
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t blockBufferUsed_FP = pContext->blockBufferUsed );
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t blockBufferUsed_FP_2 = 0U );
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t remainingInputBytes_FP = 0U );
  if((pContext->blockBufferUsed > 0U) && (MCUXCLAES_BLOCK_SIZE != pContext->blockBufferUsed))
  {
    bytesToCopy = ((MCUXCLAES_BLOCK_SIZE - pContext->blockBufferUsed) > inLength)
                    ? inLength
                    : (MCUXCLAES_BLOCK_SIZE - pContext->blockBufferUsed);


    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureDataTransfer(
      inputChannel,
      MCUXCLBUFFER_GET(pInLocal),
      ((uint8_t *)pContext->blockBuffer + pContext->blockBufferUsed),
      bytesToCopy));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_startChannel(inputChannel));

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("blockBufferUsed has an upper bound of MCUXCLAES_BLOCK_SIZE")
    pContext->blockBufferUsed += bytesToCopy;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    MCUXCLBUFFER_UPDATE(pInLocal, bytesToCopy);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Total *pProcessedBytes has an upper bound of inLength")
    *pProcessedBytes += bytesToCopy; /* keep track of bytes processed so far */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Wait for data copy to finish and check for errors */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));
  }

  /* Calculate sizes for the remaining input data */
  uint32_t remainingInputBytes = inLength - bytesToCopy;
  uint32_t lastBlockLength = (0U != remainingInputBytes) ? ((remainingInputBytes - 1U) % MCUXCLAES_BLOCK_SIZE + 1U) : 0U; /* length of the last block */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("remainingInputBytes is at least lastBlockLength long")
  uint32_t fullBlocksLength = remainingInputBytes - lastBlockLength; /* length of all remaining full blocks, except the last one (if full) */
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  /* Load the pre-tag to DATOUT */
  const uint32_t *pSrc_maskedPreTag = (const uint32_t *)pContext->maskedPreTag;
  uint32_t *pDst_sgiDatout = mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t) pDst_sgiDatout);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t) pSrc_maskedPreTag);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, 16U);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copyBlockSfrMasked(
    pDst_sgiDatout,
    pSrc_maskedPreTag,
    pContext->keyContext.sfrSeed));

   /* Process the data in the context buffer, if possible */
  MCUX_CSSL_FP_COUNTER_STMT(blockBufferUsed_FP_2 = pContext->blockBufferUsed);
  MCUX_CSSL_FP_COUNTER_STMT(remainingInputBytes_FP = remainingInputBytes);
  if((MCUXCLAES_BLOCK_SIZE == pContext->blockBufferUsed) &&
      (remainingInputBytes > 0U) /* if block buffer is filled with the last block, leave it there to be handled during Finalize */ )
  {
    /* For only one block of data, SGI AUTO-mode is not needed. */

    /* Load the input block to DATIN0 - DMA transfer not needed because this is not a direct I/O operation.
       The block buffer is always filled with the DMA. */
    MCUX_CSSL_DI_RECORD(sgiLoad, ((uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET)) + ((uint32_t)pContext->blockBuffer) + 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, (uint8_t *)pContext->blockBuffer));

    /* Perform encryption */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
      sgiCtrl                                   |
      MCUXCLSGI_DRV_CTRL_END_UP                  |
      MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT | /* pre-tag stored in DATOUT, pre-tag ^ input */
      MCUXCLSGI_DRV_CTRL_OUTSEL_RES));
    mcuxClSgi_Drv_wait();

    pContext->blockBufferUsed = 0U;
  }

  mcuxClMac_Status_t status = MCUXCLMAC_STATUS_ERROR;

  /* Process the remaining full blocks */
  uint32_t nrOfBlocks = fullBlocksLength /  MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Total *pProcessedBytes has an upper bound of inLength")
  *pProcessedBytes += fullBlocksLength; /* keep track of bytes that will be processed in this function */
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  if(1U == nrOfBlocks)
  {
    /* For only one block of data, SGI AUTO-mode is not needed. */

    /* Copy input to SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputChannel(session, MCUXCLSGI_DRV_DATIN0_OFFSET, MCUXCLBUFFER_GET(pInLocal)));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(inputChannel));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

    /* Perform encryption */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
      sgiCtrl                                   |
      MCUXCLSGI_DRV_CTRL_END_UP                  |
      MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT | /* pre-tag stored in DATOUT, pre-tag ^ input */
      MCUXCLSGI_DRV_CTRL_OUTSEL_RES));
    mcuxClSgi_Drv_wait();

    status = MCUXCLMAC_STATUS_OK;
  }
  else if(nrOfBlocks > 1U)
  {
    /* For multiple blocks, use SGI AUTO mode with handshakes. */

    /* Configure the DMA channel */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputWithHandshakes(
      session,
      MCUXCLSGI_DRV_DATIN0_OFFSET,
      MCUXCLBUFFER_GET(pInLocal)));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks(session, nrOfBlocks));

    /* Enable interrupts for the completion of the input channel, and for errors. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableChannelDoneInterrupts(inputChannel));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableErrorInterrupts(inputChannel));

    /* Enable SGI AUTO mode CBC */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureAutoMode(MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CMAC));

    /* Start the operation - this will start the SGI-DMA interaction in the background, CPU is not blocked */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_startAutoModeWithHandshakes(
      sgiCtrl | MCUXCLSGI_DRV_CTRL_NO_UP,
      MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_DISABLE));

    status = MCUXCLMAC_STATUS_JOB_STARTED;
  }
  else /* nrOfBlock = 0 */
  {
    status = MCUXCLMAC_STATUS_OK;
  }

  MCUX_CSSL_FP_COUNTER_STMT(MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_updateCMAC_nonBlocking_balancingFP(blockBufferUsed_FP,
                                                                                                           blockBufferUsed_FP_2,
                                                                                                           remainingInputBytes_FP,
                                                                                                           nrOfBlocks)));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_updateCMAC_nonBlocking, status,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_updateCMAC_nonBlocking_balancingFP));
}

