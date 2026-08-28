/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClMac.h>
#include <internal/mcuxClMacModes_Common_Constants.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <internal/mcuxClMacModes_Sgi_Cleanup.h>

#include <internal/mcuxClSgi_Drv.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Utils.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClMemory_Compare_Internal.h>
#include <internal/mcuxClMemory_CompareDPASecure_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClPrng_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_loadZeroIV)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_loadZeroIV(void)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_loadZeroIV);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 0U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 4U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 8U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 12U, 0U));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_loadZeroIV,
    (4U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_loadWord))
  );
}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_CopyOutNormal, mcuxClMacModes_CopyOutputFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_CopyOutNormal(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  uint32_t dataProcessed UNUSED_PARAM,
  mcuxCl_Buffer_t pMac,
  uint32_t *const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_CopyOutNormal);

  MCUX_CSSL_DI_RECORD(sgiStoreBuffer, (uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET));
  MCUX_CSSL_DI_RECORD(sgiStoreBuffer, (uint32_t)pMac);
  MCUX_CSSL_DI_RECORD(sgiStoreBuffer, 16U);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pMac));

 *pOutLength = MCUXCLAES_BLOCK_SIZE;

 MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_CopyOutNormal,
   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)
 );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_CopyOutDma, mcuxClMacModes_CopyOutputFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_CopyOutDma(
  mcuxClSession_Handle_t session,
  uint32_t dataProcessed UNUSED_PARAM,
  mcuxCl_Buffer_t pMac,
  uint32_t *const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_CopyOutDma);

  /* Copy the MAC result out with the DMA */
  mcuxClSession_Channel_t channel = mcuxClSession_getDmaOutputChannel(session);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiOutputChannel(session, MCUXCLSGI_DRV_DATOUT_OFFSET, MCUXCLBUFFER_GET(pMac)));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(channel));

  /* Wait for data copy to finish */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, channel));

  *pOutLength = MCUXCLAES_BLOCK_SIZE;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_CopyOutDma,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiOutputChannel),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone)
  );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_initMaskedPreTag)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_initMaskedPreTag(
  mcuxClMacModes_Context_t * pContext)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_initMaskedPreTag);
  /* Copy all-zero pre-tag to SGI DATIN0 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN0_OFFSET + 0U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN0_OFFSET + 4U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN0_OFFSET + 8U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN0_OFFSET + 12U, 0U));

  /* Store the masked initial pre-tag in the context */
  const uint32_t *pSrc_sgiDatin0 = (const uint32_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATIN0_OFFSET);
  uint32_t *pDst_maskedPreTag = pContext->maskedPreTag;
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t) pDst_maskedPreTag);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t) pSrc_sgiDatin0);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, 16U);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copyBlockSfrMasked(
    pDst_maskedPreTag,
    pSrc_sgiDatin0,
    /* Use already generated SFR seed from key context to mask the pretag */
    pContext->keyContext.sfrSeed));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_initMaskedPreTag,
    (4U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_loadWord)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copyBlockSfrMasked)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_process_preTag_calculation)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_process_preTag_calculation(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *pWa,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pInput,
  uint32_t inputLength,
  uint32_t operation)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_process_preTag_calculation);

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inputLength, 0U, UINT32_MAX - MCUXCLAES_BLOCK_SIZE, MCUXCLMAC_STATUS_INVALID_PARAM)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->blockBufferUsed, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLMAC_STATUS_INVALID_PARAM)

  uint32_t totalInputSize = (pContext->blockBufferUsed + inputLength);
  uint32_t numFullRemainingInputBlocks = 0U;
  uint32_t numRemainingInputBytes = 0U;

  if (totalInputSize >= MCUXCLAES_BLOCK_SIZE)
  {
    uint32_t inputOffset = 0U;
    uint32_t remainingInputLength = inputLength;

    /* use bytes in blockBuffer and fill it up with input */
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, pInput);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, inputOffset);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, &((uint8_t *)pContext->blockBuffer)[pContext->blockBufferUsed]);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, MCUXCLAES_BLOCK_SIZE - pContext->blockBufferUsed);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_secure(
      pInput,
      inputOffset,
      &((uint8_t *)pContext->blockBuffer)[pContext->blockBufferUsed],
      MCUXCLAES_BLOCK_SIZE - pContext->blockBufferUsed));

    /* adapt the input offset */
    inputOffset += MCUXCLAES_BLOCK_SIZE - pContext->blockBufferUsed;
    remainingInputLength -= (MCUXCLAES_BLOCK_SIZE - pContext->blockBufferUsed);

    const uint32_t *pSrc_maskedPreTag = (const uint32_t *)pContext->maskedPreTag;
    uint32_t *pDst_sgiDatout = (uint32_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, pDst_sgiDatout);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t)pSrc_maskedPreTag);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, 16U);
    /* Load pSrc_maskedPreTag to DATOUT. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copyBlockSfrMasked(
      pDst_sgiDatout,
      pSrc_maskedPreTag,
      pContext->keyContext.sfrSeed));

    MCUXCLBUFFER_INIT_RO(paddingBuf, NULL, (uint8_t *)pContext->blockBuffer, MCUXCLAES_BLOCK_SIZE);
    /* After call, result preTag is in pWa->sgiWa.secParamWa.outBuff */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_engine(
      session,
      pWa,
      pContext,
      paddingBuf,
      0U,
      MCUXCLAES_BLOCK_SIZE,
      pContext->keyContext.sfrSeed,
      operation,
      mcuxClMacModes_updateEngine,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_updateEngine)));

    pContext->blockBufferUsed = 0U;

    numFullRemainingInputBlocks = remainingInputLength;
    if (numFullRemainingInputBlocks >= MCUXCLAES_BLOCK_SIZE)
    {
      /* still some input bytes left - process full block */
      uint32_t dataBlocks = remainingInputLength / MCUXCLAES_BLOCK_SIZE;

      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_engine(
        session,
        pWa,
        pContext,
        pInput,
        inputOffset,
        dataBlocks * MCUXCLAES_BLOCK_SIZE,
        pContext->keyContext.sfrSeed,
        operation,
        mcuxClMacModes_updateEngine,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_updateEngine)));

      /* adapt the input offset */
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("offsets within valid pInput buffer")
      inputOffset += dataBlocks * MCUXCLAES_BLOCK_SIZE;
      remainingInputLength -= dataBlocks * MCUXCLAES_BLOCK_SIZE;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }

    /* Save the output to pContext->maskedPreTag for next updateEngine call */
    const uint32_t *pSrc_sgiDatout = (const uint32_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET);
    uint32_t *pDst_maskedPreTag = pContext->maskedPreTag;
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t)pDst_maskedPreTag);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t)pSrc_sgiDatout);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copyBlockSfrMasked(
      pDst_maskedPreTag,
      pSrc_sgiDatout,
      pContext->keyContext.sfrSeed));

    numRemainingInputBytes = remainingInputLength;
    if(0U != numRemainingInputBytes)
    {
      /* copy remaining data into blockBuffer */
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, pInput);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, inputOffset);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, &((uint8_t *)pContext->blockBuffer)[0]);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, remainingInputLength);
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_secure(
        pInput,
        inputOffset,
        &((uint8_t *)pContext->blockBuffer)[0],
        remainingInputLength));

      pContext->blockBufferUsed = remainingInputLength;
    }
  }
  else
  {
    /* bytes in buffer and new data is less than blockSize - save data into blockBuffer */
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, pInput);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, &((uint8_t *)pContext->blockBuffer)[pContext->blockBufferUsed]);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, inputLength);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_secure(
      pInput,
      0U,
      &((uint8_t *)pContext->blockBuffer)[pContext->blockBufferUsed],
      inputLength));

    pContext->blockBufferUsed += inputLength;
  }
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_process_preTag_calculation,
    MCUX_CSSL_FP_CONDITIONAL((totalInputSize >= MCUXCLAES_BLOCK_SIZE),
      MCUX_CSSL_FP_CONDITIONAL((numFullRemainingInputBlocks >= MCUXCLAES_BLOCK_SIZE),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_engine)
      ), /* numFullRemainingInputBlocks >= MCUXCLAES_BLOCK_SIZE */
      MCUX_CSSL_FP_CONDITIONAL((numRemainingInputBytes != 0U),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_secure)
      ), /* 0U != numRemainingInputBytes */
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_secure),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copyBlockSfrMasked),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_engine),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copyBlockSfrMasked)
    ), /* totalInputSize >= MCUXCLAES_BLOCK_SIZE */

    MCUX_CSSL_FP_CONDITIONAL((totalInputSize < MCUXCLAES_BLOCK_SIZE),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_secure)
    ) /* totalInputSize < MCUXCLAES_BLOCK_SIZE */
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_engine)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_engine(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *pWa,
  mcuxClMacModes_Context_t * pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t inLength,
  uint32_t sfrSeed,
  uint32_t operation,
  mcuxClMacModes_ComputePreTagFunc_t macEngine,
  uint32_t protectionToken_macEngine)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_engine);

  mcuxClKey_KeyChecksum_t* pKeyChecksum = NULL;
  if(pContext != NULL)
  {
    pKeyChecksum = &pContext->keyContext.keyChecksums;
  }
  else
  {
    pKeyChecksum = pWa->sgiWa.pKeyChecksums;
  }

  /* For normal mac operation, don't need copy result outside */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(macEngine(pIn, inOffset, inLength, operation));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("pKeyChecksum is assigned to a valid non-null value as part of this function")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pKeyChecksum->VerifyFunc(
    NULL,
    pKeyChecksum,
    (uint8_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_KEY0_OFFSET)));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_engine,
    protectionToken_macEngine,
    pKeyChecksum->protectionToken_VerifyFunc
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_finalizeEngine, mcuxClMacModes_ComputePreTagFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_finalizeEngine(
  mcuxCl_InputBuffer_t pIn UNUSED_PARAM,
  uint32_t inOffset UNUSED_PARAM,
  uint32_t inLength UNUSED_PARAM,
  uint32_t operation)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_finalizeEngine);

  /* Record sgi processing blocks */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount, mcuxClSgi_Drv_getCount());
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("1U + mcuxClSgi_Drv_getCount() doesn't wrap")
  const uint32_t sgiCount = 1U + currCount;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  const uint32_t sgiCountOverflow = sgiCount & 0xFFFF0000U; // since SGI_COUNT is 16-bit register, save the possibly overflowed value and use it in DI_EXPUNGE at the end
  MCUX_CSSL_DI_RECORD(sgiCount, sgiCount);

  operation |= MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT;
  /* encrypt last block */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(operation));
  //wait for finish
  mcuxClSgi_Drv_wait();

  /* Expunge the current value of the SGI COUNT plus the possibly overflowed value for DI protection.
     The sum is equal to the SGI COUNT in the beginning plus one. */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount2, mcuxClSgi_Drv_getCount());

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("value used for SC balancing which supports unsigned overflow behaviour")
  uint32_t endCount = sgiCountOverflow + currCount2;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_DI_EXPUNGE(sgiCount, endCount);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_finalizeEngine,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_updateEngine, mcuxClMacModes_ComputePreTagFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_updateEngine(
  mcuxCl_InputBuffer_t pInput,
  uint32_t inOffset,
  uint32_t inLength,
  uint32_t operation)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_updateEngine);

  uint32_t numFullBlocks = inLength / MCUXCLAES_BLOCK_SIZE;

  /* Record the number of blocks plus the SGI COUNT for DI protection. */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount, mcuxClSgi_Drv_getCount());
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("numFullBlocks + mcuxClSgi_Drv_getCount() doesn't wrap");
  const uint32_t sgiCount = numFullBlocks + currCount;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  // since SGI_COUNT is 16-bit register, save the possibly overflowed value and use it in DI_EXPUNGE at the end
  const uint32_t sgiCountOverflow = sgiCount & 0xFFFF0000U;
  MCUX_CSSL_DI_RECORD(sgiCount, sgiCount);

  /* Record load buffer */
  // sumOfOffsets = MCUXCLAES_BLOCK_SIZE * (0 + 1 + 2 + .. + (numFullBlocks-1)) + inputOffset * numFullBlocks
  //              = MCUXCLAES_BLOCK_SIZE * ((numFullBlocks-1) * numFullBlocks) / 2 + inputOffset * numFullBlocks
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("value used for SC balancing which supports unsigned overflow behaviour")
  uint32_t sumOfOffsets = (MCUXCLAES_BLOCK_SIZE / 2U) * (numFullBlocks - 1U) * numFullBlocks + inOffset * numFullBlocks;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, sumOfOffsets);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, (numFullBlocks) * (uint32_t)pInput);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, (numFullBlocks) * (uint32_t)MCUXCLAES_BLOCK_SIZE);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, (numFullBlocks) * (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET)); // iterations in the loop load to DATIN0

  /* Load first plain block to the DATIN0 */
  /* the preTag is already loaded in the DATIN0 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pInput + inOffset));

  /* Keep track of the input bytes that are already copied */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("offset within valid pIn buffer")
  inOffset += MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  operation |= MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT;
  // start calc
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(operation));

  for(uint32_t i = 1U; i < numFullBlocks; ++i)
  {
    // Copy input to SGI
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("inOffset within valid pIn buffer")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pInput + inOffset));

    /* Keep track of the input bytes that are already copied */
    inOffset += MCUXCLAES_BLOCK_SIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    //wait for finish
    mcuxClSgi_Drv_wait();

    //start_up
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(operation));
  }

  // wait for finish
  mcuxClSgi_Drv_wait();

  /* Expunge the current value of the SGI COUNT plus the possibly overflowed value for DI protection.
     The sum is equal to the SGI COUNT in the beginning plus the number of full blocks. */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount2, mcuxClSgi_Drv_getCount());

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("value used for SC balancing which supports unsigned overflow behaviour")
  uint32_t endCount = sgiCountOverflow + currCount2;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_DI_EXPUNGE(sgiCount, endCount);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_updateEngine,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    (numFullBlocks - 1U) * (
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock) +
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
    ),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount)
  );
}
