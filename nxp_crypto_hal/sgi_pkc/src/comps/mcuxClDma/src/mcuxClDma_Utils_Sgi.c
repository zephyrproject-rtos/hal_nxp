/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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

#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Utils.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Sfr.h>
#include <mcuxClAes_Constants.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Sfr_RegBank.h>
#include <internal/mcuxClSession_Internal_Functions.h>



/******************************************************/
/* DMA static inline SGI helpers                      */
/******************************************************/

/** Write the destination address of a DMA channel TCD to point to an SGI DAT (DATIN or DATOUT) register. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_writeDstAddress_Sgi)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_writeDstAddress_Sgi(
  mcuxClSession_Channel_t channel,
  uint32_t sgiSfrDataRegOffset)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_writeDstAddress_Sgi);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstAddress(
    channel,
    (uint8_t *)mcuxClSgi_Drv_getAddr(sgiSfrDataRegOffset)));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_writeDstAddress_Sgi,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstAddress));
}


/******************************************************/
/* DMA utility functions for SHA2                     */
/******************************************************/

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_configureSgiSha2InputChannel)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_configureSgiSha2InputChannel(
  mcuxClSession_Handle_t session,
  const uint8_t *pSrc,
  uint32_t srcLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_configureSgiSha2InputChannel);
  /*
   * Write the TCD of the input channel
   */
  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  uint16_t srcOffset = 0u;
  uint16_t srcSize = 0u;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pSrc,
    &srcOffset,
    &srcSize,
    srcLength));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcAddress(inputChannel, pSrc));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcOffset(inputChannel, srcOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_writeDstAddress_Sgi(inputChannel, MCUXCLSGI_DRV_SHAFIFO_OFFSET));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstOffset(
    inputChannel, MCUXCLDMA_DRV_OFFSET_INCR_DIS)); /* Do not modify address of SGI_SHAFIFO */
  mcuxClDma_Sfr_writeTransferAttributes(inputChannel, MCUXCLDMA_DRV_SRC_ACCESS_SIZE(srcSize)
                                                | MCUXCLDMA_DRV_DST_ACCESS_SIZE_4_BYTE);
  /* Do not adjust the source address, such that this channel can be continued without re-configuring the TCD */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastSrcAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Do not adjust the destination address, it always point to SHA FIFO */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastDstAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  mcuxClDma_Sfr_writeTCDControlAndStatus(inputChannel, 0u);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeMajorLoopCounts(inputChannel, 1));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeTransferSize(inputChannel, srcLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_configureSgiSha2InputChannel,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_writeDstAddress_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastSrcAddrAdjustment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastDstAddrAdjustment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeMajorLoopCounts),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeTransferSize)
  );
}


/******************************************************/
/* DMA utility functions for AES and SGI-handshakes   */
/******************************************************/

#if defined(MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_SGI_COPY) || defined(MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_OUTPUT_HANDSHAKES)
/** Write the destination address of a DMA channel TCD to point to an SGI DAT (DATIN or DATOUT) register. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_writeSrcAddress_Sgi)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_writeSrcAddress_Sgi(
  mcuxClSession_Channel_t channel,
  uint32_t sgiSfrDataRegOffset)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_writeSrcAddress_Sgi);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcAddress(
    channel,
    (const uint8_t *)mcuxClSgi_Drv_getAddr(sgiSfrDataRegOffset)));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_writeSrcAddress_Sgi,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcAddress));
}
#endif /* defined(MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_SGI_COPY) || defined(MCUXCL_FEATURE_DMA_SGI_HANDSHAKE) */

#ifdef MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_SGI_COPY
/** Configure the given DMA channel to load data to an SGI DATIN register. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_configureSgiInputChannel)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_configureSgiInputChannel(
  mcuxClSession_Handle_t session,
  uint32_t sgiSfrDataRegOffset,
  const uint8_t *pSrc)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_configureSgiInputChannel);
  /*
   * Write the TCD of the input channel
   */
  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  uint16_t srcOffset = 0u;
  uint16_t srcSize = 0u;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pSrc,
    &srcOffset,
    &srcSize,
    MCUXCLAES_BLOCK_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcAddress(inputChannel, pSrc));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcOffset(inputChannel, srcOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_writeDstAddress_Sgi(inputChannel, sgiSfrDataRegOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstOffset(
    inputChannel, MCUXCLDMA_DRV_OFFSET_INCR_DIS)); /* Do not modify address of SGI_DATINx */
  mcuxClDma_Sfr_writeTransferAttributes(inputChannel, MCUXCLDMA_DRV_SRC_ACCESS_SIZE(srcSize)
                                                | MCUXCLDMA_DRV_DST_ACCESS_SIZE_16_BYTE);
  /* Do not adjust the source address, such that this channel can be continued without re-configuring the TCD */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastSrcAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Do not adjust the destination address, it always point to SGI_DATINx */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastDstAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  mcuxClDma_Sfr_writeTCDControlAndStatus(inputChannel, 0u);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_configureSgiInputChannel,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_writeDstAddress_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastSrcAddrAdjustment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastDstAddrAdjustment)
  );
}

/** Configure the given DMA channel to store data from the SGI DATOUT register */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_configureSgiOutputChannel)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_configureSgiOutputChannel(
  mcuxClSession_Handle_t session,
  uint32_t sgiSfrDataRegOffset,
  uint8_t *pDst)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_configureSgiOutputChannel);
  /*
   * Write the TCD of the output channel
   */
  mcuxClSession_Channel_t outputChannel = mcuxClSession_getDmaOutputChannel(session);
  uint16_t dstOffset = 0u;
  uint16_t dstSize = 0u;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pDst,
    &dstOffset,
    &dstSize,
    MCUXCLAES_BLOCK_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_writeSrcAddress_Sgi(outputChannel, sgiSfrDataRegOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcOffset(
    outputChannel, MCUXCLDMA_DRV_OFFSET_INCR_DIS)); /* Do not modify address of SGI_DATOUT */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstAddress(outputChannel, pDst));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstOffset(outputChannel, dstOffset));
  mcuxClDma_Sfr_writeTransferAttributes(outputChannel, MCUXCLDMA_DRV_SRC_ACCESS_SIZE_16_BYTE
                                                | MCUXCLDMA_DRV_DST_ACCESS_SIZE(dstSize));
  /* Do not adjust the src address, it always point to SGI_DATOUT */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastSrcAddrAdjustment(outputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Do not adjust the destination address, such that this channel can be continued without re-configuring the TCD */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastDstAddrAdjustment(outputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  mcuxClDma_Sfr_writeTCDControlAndStatus(outputChannel, 0u);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_configureSgiOutputChannel,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_writeSrcAddress_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastSrcAddrAdjustment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastDstAddrAdjustment)
  );
}

/** Continue/Start the data transfer for an already configured channel.
    If functions mcuxClDma_Utils_configureSgiInputChannel/mcuxClDma_Utils_configureSgiOutputChannel
    were used to configure the channel, the SGI DATIN/DATOUT registers in the channel are correctly
    re-adjusted in the channel TCD. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_startTransferOneBlock)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_startTransferOneBlock(
  mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_startTransferOneBlock);
  /* Transfer one block of data */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeMajorLoopCounts(channel, 1u));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeTransferSize(channel, MCUXCLAES_BLOCK_SIZE));

  /* Start the channel */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_startChannel(channel));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_startTransferOneBlock,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeMajorLoopCounts),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeTransferSize),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_startChannel)
  );
}
#endif /* MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_SGI_COPY */

#ifdef MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_HANDSHAKES
/** Configure the given DMA input channel to write blocks to SGI by using SGI input handshake signals. */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_configureSgiInputWithHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_configureSgiInputWithHandshakes(
  mcuxClSession_Handle_t session,
  uint32_t sgiSfrDatInOffset,
  const uint8_t *pSrc)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_configureSgiInputWithHandshakes);
  /*
   * Configure the transaction details (TCD) of the input channel.
   */
  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  uint16_t srcOffset = 0u;
  uint16_t srcSize = 0u;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pSrc,
    &srcOffset,
    &srcSize,
    MCUXCLAES_BLOCK_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeTransferSize(
    inputChannel, MCUXCLAES_BLOCK_SIZE)); /* Tranfer one block per SGI request (i.e., per major loop iteration) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcAddress(inputChannel, pSrc));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcOffset(inputChannel, srcOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_writeDstAddress_Sgi(inputChannel, sgiSfrDatInOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstOffset(
    inputChannel, MCUXCLDMA_DRV_OFFSET_INCR_DIS)); /* Do not modify address of SGI_DATIN */
  mcuxClDma_Sfr_writeTransferAttributes(inputChannel, MCUXCLDMA_DRV_SRC_ACCESS_SIZE(srcSize)
                                                     | MCUXCLDMA_DRV_DST_ACCESS_SIZE_16_BYTE);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastSrcAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Do not adjust the dst address, it always point to SGI_DATIN */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastDstAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Turn-off hardware requests once the channel is done - will prevent channel restart from too many SGI request signals */
  mcuxClDma_Sfr_writeTCDControlAndStatus(inputChannel, MCUXCLDMA_SFR_TCD_CSR_DREQ_EN);

  /*
   * Enable the channel's hardware requests,
   * and link the requests to the SGI handshake (SGI_IN)
   */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_linkWithSgiInputHandshakes(session));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableHardwareRequests(
    inputChannel));  /* inputChannel is started by SGI_IN hardware request */

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_configureSgiInputWithHandshakes,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeTransferSize),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_writeDstAddress_Sgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastSrcAddrAdjustment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastDstAddrAdjustment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_linkWithSgiInputHandshakes),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableHardwareRequests)
  );
}

/** Set the number of blocks for the handshake communication with SGI AUTO mode. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks(
  mcuxClSession_Handle_t session,
  uint32_t inputBlocks
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks);

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeMajorLoopCounts(
    inputChannel, (uint16_t)(inputBlocks & 0xffffu))); /* One major loop iteration per SGI request (i.e., per block) */

  /* Re-enable hardware requests in the channel, will be disabled automatically whenever the channels are done */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableHardwareRequests(inputChannel));  /* inputChannel is started by SGI_IN hardware request */

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_SgiInputHandshakes_writeNumberOfBlocks,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeMajorLoopCounts),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableHardwareRequests)
  );
}
#endif /* MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_HANDSHAKES */

#ifdef MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_OUTPUT_HANDSHAKES
/** Configure the given DMA channels to read/write blocks to/from SGI by using SGI handshake signals. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_configureSgiTransferWithHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_configureSgiTransferWithHandshakes(
  mcuxClSession_Handle_t session,
  uint32_t sgiSfrDatInOffset,
  const uint8_t *pSrc,
  uint8_t *pDst)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_configureSgiTransferWithHandshakes);
  /*
   * Configure the transaction details (TCD) for both channels
   */

  /*
   * Write the TCD of the input channel
   */
  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  uint16_t srcOffset = 0u;
  uint16_t srcSize = 0u;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pSrc,
    &srcOffset,
    &srcSize,
    MCUXCLAES_BLOCK_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeTransferSize(
    inputChannel, MCUXCLAES_BLOCK_SIZE)); /* Tranfer one block per SGI request (i.e., per major loop iteration) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcAddress(inputChannel, pSrc));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcOffset(inputChannel, srcOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_writeDstAddress_Sgi(inputChannel, sgiSfrDatInOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstOffset(
    inputChannel, MCUXCLDMA_DRV_OFFSET_INCR_DIS)); /* Do not modify address of SGI_DATIN */
  mcuxClDma_Sfr_writeTransferAttributes(inputChannel, MCUXCLDMA_DRV_SRC_ACCESS_SIZE(srcSize)
                                                     | MCUXCLDMA_DRV_DST_ACCESS_SIZE_16_BYTE);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastSrcAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Do not adjust the dst address, it always point to SGI_DATIN */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastDstAddrAdjustment(inputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Turn-off hardware requests once the channel is done - will prevent channel restart from too many SGI request signals */
  mcuxClDma_Sfr_writeTCDControlAndStatus(inputChannel, MCUXCLDMA_SFR_TCD_CSR_DREQ_EN);

  /*
   * Write the TCD of the output channel
   */
  mcuxClSession_Channel_t outputChannel = mcuxClSession_getDmaOutputChannel(session);
  uint16_t dstOffset = 0u;
  uint16_t dstSize = 0u;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pDst,
    &dstOffset,
    &dstSize,
    MCUXCLAES_BLOCK_SIZE));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeTransferSize(
    outputChannel, MCUXCLAES_BLOCK_SIZE)); /* Tranfer one block per SGI request (i.e., per major loop iteration) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_writeSrcAddress_Sgi(outputChannel, MCUXCLSGI_DRV_DATOUT_OFFSET));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcOffset(
    outputChannel, MCUXCLDMA_DRV_OFFSET_INCR_DIS)); /* Do not modify address of SGI_DATOUT */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstAddress(outputChannel, pDst));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstOffset(outputChannel, dstOffset));
  mcuxClDma_Sfr_writeTransferAttributes(outputChannel, MCUXCLDMA_DRV_SRC_ACCESS_SIZE_16_BYTE
                                                      | MCUXCLDMA_DRV_DST_ACCESS_SIZE(dstSize));
  /* Do not adjust the dst address, it always point to SGI_DATOUT */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastSrcAddrAdjustment(outputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastDstAddrAdjustment(outputChannel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS));
  /* Turn-off hardware requests once the channel is done - will prevent channel restart from too many SGI request signals */
  mcuxClDma_Sfr_writeTCDControlAndStatus(outputChannel, MCUXCLDMA_SFR_TCD_CSR_DREQ_EN);

  /*
   * Link the SGI handshake signals with the DMA channels (SGI_IN and SGI_OUT)
   */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_linkWithSgiHandshakes(session));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_configureSgiTransferWithHandshakes,
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment)),
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeTransferSize)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_writeSrcAddress_Sgi),
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcOffset)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_writeDstAddress_Sgi),
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstOffset)),
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastSrcAddrAdjustment)),
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastDstAddrAdjustment)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_linkWithSgiHandshakes)
  );
}

/** Set the number of in and out blocks for the handshake communication with SGI AUTO mode. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_SgiHandshakes_writeNumberOfBlocks)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_SgiHandshakes_writeNumberOfBlocks(
  mcuxClSession_Handle_t session,
  uint32_t inputBlocks,
  uint32_t outputBlocks
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_SgiHandshakes_writeNumberOfBlocks);

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  mcuxClSession_Channel_t outputChannel = mcuxClSession_getDmaOutputChannel(session);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeMajorLoopCounts(
    inputChannel, (uint16_t)(inputBlocks & 0xffffu))); /* One major loop iteration per SGI request (i.e., per input block) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeMajorLoopCounts(
    outputChannel, (uint16_t)(outputBlocks & 0xffffu))); /* One major loop iteration per SGI request (i.e., per output block) */

  /* Enable hardware requests in the channels, will be disabled automatically whenever the channel is done */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableHardwareRequests(
    inputChannel));  /* inputChannel is started by SGI_IN hardware request */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableHardwareRequests(
    outputChannel)); /* outputChannel is started by SGI_OUT hardware request */

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_SgiHandshakes_writeNumberOfBlocks,
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeMajorLoopCounts)),
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableHardwareRequests))
  );
}
#endif /* MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_OUTPUT_HANDSHAKES */
