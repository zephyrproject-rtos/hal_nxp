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
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClSgi_Types.h>
#include <mcuxClAes.h>

#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClCipherModes_Sgi_Aes_Iv.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Utils_Sgi.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode, mcuxClCipherModes_completeAutoModeFunc_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode);

  mcuxClSession_Channel_t outputChannel = mcuxClSession_getDmaOutputChannel(session);

  /* Copy last output block from SGI */
  mcuxCl_Buffer_t pOutput = pWa->nonBlockingWa.pOut;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiOutputChannel(
    session, MCUXCLSGI_DRV_DATOUT_OFFSET, MCUXCLBUFFER_GET(pOutput) + pWa->nonBlockingWa.outOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(outputChannel));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, outputChannel));

  /* Increase output length if copy of last block was successful, and advance the output pointer */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Total outOffset/inOffset and *pOutputLength have an upper bound of inLength")
  *pWa->nonBlockingWa.pOutputLength += MCUXCLAES_BLOCK_SIZE;
  pWa->nonBlockingWa.outOffset += MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  mcuxClSgi_Drv_wait();

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiOutputChannel),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_Ecb_NonBlocking)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_Ecb_NonBlocking(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t* pIvOut UNUSED_PARAM,
  uint32_t* const pOutLength,
  uint32_t direction)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_Ecb_NonBlocking);

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*pOutLength, 0U, UINT32_MAX - inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inLength, 1U, UINT32_MAX - *pOutLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)

  if(inLength > MCUXCLDMA_UTILS_SGI_AUTOMODE_MAX_INPUT_SIZE)
  {
    MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
  }

  uint8_t *pOutPtr = (uint8_t *) MCUXCLBUFFER_GET(pOut);

  uint32_t nrOfBlocks = inLength / MCUXCLAES_BLOCK_SIZE;
  /* Caller ensures inLength is a non-zero multiple of MCUXCLAES_BLOCK_SIZE. */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(nrOfBlocks, 1U, UINT32_MAX, MCUXCLCIPHER_STATUS_INVALID_INPUT)

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  mcuxClSession_Channel_t outputChannel = mcuxClSession_getDmaOutputChannel(session);

  uint32_t sgiCtrl = direction                       |
                     pWa->sgiWa.sgiCtrlKey;

  mcuxClCipher_Status_t status;

  if(1U == nrOfBlocks)
  {
    /* For only one block of data, SGI AUTO-mode is not needed. */

    /* Copy input to SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputChannel(session, MCUXCLSGI_DRV_DATIN1_OFFSET, MCUXCLBUFFER_GET(pIn)));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(inputChannel));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

    /* Perform crypt operation */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
      MCUXCLSGI_DRV_CTRL_END_UP                  |
      MCUXCLSGI_DRV_CTRL_INSEL_DATIN1            |
      MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
      sgiCtrl));
    mcuxClSgi_Drv_wait();

    /* Copy output block from SGI. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiOutputChannel(session, MCUXCLSGI_DRV_DATOUT_OFFSET, pOutPtr));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(outputChannel));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, outputChannel));

    status = MCUXCLCIPHER_STATUS_OK;
    /* Increase output length if copy of last block was successful */
    *pOutLength += MCUXCLAES_BLOCK_SIZE;
  }
  else /* nrOfBlocks > 1U */
  {
    /* For multiple blocks, use SGI AUTO mode with handshakes, non-blocking */

    /* Configure the DMA channels */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiTransferWithHandshakes(
      session,
      MCUXCLSGI_DRV_DATIN0_OFFSET,
      MCUXCLBUFFER_GET(pIn),
      pOutPtr));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_SgiHandshakes_writeNumberOfBlocks(
      session,
      nrOfBlocks,
      (nrOfBlocks - 1U) /* for ECB, the last output block needs to be copied seperately after SGI is stopped */));

    /* Enable interrupts for the completion of the input channel, and for errors.
       As the output channel finishes first, there is not need to additionally enable DONE interrupts for it.
    */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableErrorInterrupts(inputChannel));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableErrorInterrupts(outputChannel));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableChannelDoneInterrupts(inputChannel));

    /* Enable SGI AUTO mode ECB */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureAutoMode(MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_ECB));

    /* Start the operation - this will start the SGI-DMA interaction in the background, CPU is not blocked */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_startAutoModeWithHandshakes(sgiCtrl | MCUXCLSGI_DRV_CTRL_NO_UP | MCUXCLSGI_DRV_CTRL_AES_NO_KL, MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_ENABLE));

    status = MCUXCLCIPHER_STATUS_JOB_STARTED;
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_Ecb_NonBlocking, status,
    MCUX_CSSL_FP_CONDITIONAL( (1U == nrOfBlocks),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputChannel),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiOutputChannel),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone)
      ),
    MCUX_CSSL_FP_CONDITIONAL( (1U != nrOfBlocks),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiTransferWithHandshakes),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_SgiHandshakes_writeNumberOfBlocks),
          2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableErrorInterrupts),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableChannelDoneInterrupts),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureAutoMode),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_startAutoModeWithHandshakes)
      )
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_Ecb_NonBlocking_Enc, mcuxClCipherModes_EngineFunc_AesSgi_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_Ecb_NonBlocking_Enc(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t* pIvOut,
  uint32_t* const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_Ecb_NonBlocking_Enc);

  MCUX_CSSL_FP_FUNCTION_CALL(ecbStatus, mcuxClCipherModes_Ecb_NonBlocking(session, pWa, pIn, pOut, inLength, pIvOut, pOutLength, MCUXCLSGI_DRV_CTRL_ENC));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_Ecb_NonBlocking_Enc, ecbStatus,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_Ecb_NonBlocking_Dec, mcuxClCipherModes_EngineFunc_AesSgi_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_Ecb_NonBlocking_Dec(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t* pIvOut,
  uint32_t* const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_Ecb_NonBlocking_Dec);

  MCUX_CSSL_FP_FUNCTION_CALL(ecbStatus, mcuxClCipherModes_Ecb_NonBlocking(session, pWa, pIn, pOut, inLength, pIvOut, pOutLength, MCUXCLSGI_DRV_CTRL_DEC));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_Ecb_NonBlocking_Dec, ecbStatus,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking));
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_NoPadding_Sgi_NonBlocking =
{
  .encryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Dec),
  .completeAutoModeEngine                        = mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode,
  .protectionToken_completeAutoModeEngine        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode),
  .setupIVEncrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVEncrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .setupIVDecrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVDecrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .checkIvLength                                 = mcuxClCipherModes_checkIvLen_noIv,
  .protectionToken_checkIvLength                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_checkIvLen_noIv),
  .addPadding                                    = mcuxClPadding_addPadding_None,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_None),
  .removePadding                                 = NULL,
  .protectionToken_removePadding                 = 0U,
  .granularityEnc                                = MCUXCLAES_BLOCK_SIZE,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};

const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method1_Sgi_NonBlocking =
{
  .encryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Dec),
  .completeAutoModeEngine                        = mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode,
  .protectionToken_completeAutoModeEngine        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode),
  .setupIVEncrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVEncrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .setupIVDecrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVDecrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .checkIvLength                                 = mcuxClCipherModes_checkIvLen_noIv,
  .protectionToken_checkIvLength                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_checkIvLen_noIv),
  .addPadding                                    = mcuxClPadding_addPadding_ISO9797_1_Method1,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method1),
  .removePadding                                 = mcuxClPadding_removePadding_ISO9797_1_Method1,
  .protectionToken_removePadding                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_ISO9797_1_Method1),
  .granularityEnc                                = 1U,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};

const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method2_Sgi_NonBlocking =
{
  .encryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Dec),
  .completeAutoModeEngine                        = mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode,
  .protectionToken_completeAutoModeEngine        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode),
  .setupIVEncrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVEncrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .setupIVDecrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVDecrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .checkIvLength                                 = mcuxClCipherModes_checkIvLen_noIv,
  .protectionToken_checkIvLength                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_checkIvLen_noIv),
  .addPadding                                    = mcuxClPadding_addPadding_ISO9797_1_Method2,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2),
  .removePadding                                 = mcuxClPadding_removePadding_ISO9797_1_Method2,
  .protectionToken_removePadding                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_ISO9797_1_Method2),
  .granularityEnc                                = 1U,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};

const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingPKCS7_Sgi_NonBlocking =
{
  .encryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Ecb_NonBlocking_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_Dec),
  .completeAutoModeEngine                        = mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode,
  .protectionToken_completeAutoModeEngine        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ecb_NonBlocking_CompleteAutoMode),
  .setupIVEncrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVEncrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .setupIVDecrypt                                = mcuxClCipherModes_No_IV,
  .protectionToken_setupIVDecrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_No_IV),
  .checkIvLength                                 = mcuxClCipherModes_checkIvLen_noIv,
  .protectionToken_checkIvLength                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_checkIvLen_noIv),
  .addPadding                                    = mcuxClPadding_addPadding_PKCS7,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_PKCS7),
  .removePadding                                 = mcuxClPadding_removePadding_PKCS7,
  .protectionToken_removePadding                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_PKCS7),
  .granularityEnc                                = 1U,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
