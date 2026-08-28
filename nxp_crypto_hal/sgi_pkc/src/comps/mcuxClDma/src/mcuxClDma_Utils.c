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

#include <mcuxClToolchain.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Sfr.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Utils.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
  const uint8_t *pAddr,
  uint16_t *pOffset,
  uint16_t *pSize,
  uint32_t size)
{
  /* Check alignment of address to configure the DMA offset that is used after each R/W access:
       If quad word aligned, set offset and size to values corresponding to 16-byte access,
       If double word aligned, set offset and size to values corresponding to 8-byte access,
       If word aligned, set offset and size to values corresponding to 4-byte access,
       if half-word aligned, set offset and size to values corresponding to 2-byte access,
       if byte aligned, set offset and size to values corresponding to 1-byte access.
  */
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment);

  if((0uL == ((uint32_t)pAddr & 0x0Fu)) && (0u == (size & 0xFu)))
  {
    /* address is quad word aligned */
    *pOffset = MCUXCLDMA_DRV_OFFSET_INCR_16_BYTE;
    *pSize = MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_16_BYTE;
  }
  else if((0uL == ((uint32_t)pAddr & 0x07u)) && (0u == (size & 0x7u)))
  {
    /* address is double word aligned */
    *pOffset = MCUXCLDMA_DRV_OFFSET_INCR_8_BYTE;
    *pSize = MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_8_BYTE;
  }
  else if(0uL == ((uint32_t)pAddr & 0x03u) && (0u == (size & 0x3u)))
  {
    /* address is word aligned */
    *pOffset = MCUXCLDMA_DRV_OFFSET_INCR_4_BYTE;
    *pSize = MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_4_BYTE;
  }
  else if(0uL == ((uint32_t)pAddr & 0x01u) && (0u == (size & 0x1u)))
  {
    /* address is half-word aligned */
    *pOffset = MCUXCLDMA_DRV_OFFSET_INCR_2_BYTE;
    *pSize = MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_2_BYTE;
  }
  else
  {
    /* address is byte aligned */
    *pOffset = MCUXCLDMA_DRV_OFFSET_INCR_1_BYTE;
    *pSize = MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_1_BYTE;
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment);
}

#ifdef MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_COPY
/** Configure the given DMA channel to transfer a specific amount of data from pSrc to pDst */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Utils_configureDataTransfer)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_configureDataTransfer(
  mcuxClSession_Channel_t channel,
  const uint8_t *pSrc,
  uint8_t *pDst,
  uint32_t length)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_Utils_configureDataTransfer);

  /* If the requested length is not a multiple of the word size - perform byte-wise access/transfer */
  uint16_t srcOffset = 0u;
  uint16_t dstOffset = 0u;
  uint16_t srcSize = 0u;
  uint16_t dstSize = 0u;

  /* get most performant access sizes based on address alignments and total transfer size */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pSrc,
    &srcOffset,
    &srcSize,
    length));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
    pDst,
    &dstOffset,
    &dstSize,
    length));

  /*
   * Write the TCD of the channel
   */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeMajorLoopCounts(
    channel, 1u)); /* Transfer all bytes in single iteration, default setting */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeTransferSize(channel, length));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcAddress(channel, pSrc));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeSrcOffset(channel, srcOffset));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstAddress(channel, pDst));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeDstOffset(channel, dstOffset));
  mcuxClDma_Sfr_writeTransferAttributes(channel, MCUXCLDMA_DRV_SRC_ACCESS_SIZE(srcSize)
                                                | MCUXCLDMA_DRV_DST_ACCESS_SIZE(dstSize));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastSrcAddrAdjustment(
    channel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS)); /* Do not adjust src address in TCD after transfer completion, default setting */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_writeLastDstAddrAdjustment(
    channel, MCUXCLDMA_DRV_FINAL_OFFSET_DIS)); /* Do not adjust dst address in TCD after transfer completion, default setting */
  mcuxClDma_Sfr_writeTCDControlAndStatus(channel, 0u);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_Utils_configureDataTransfer,
    (2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeMajorLoopCounts),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeTransferSize),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeSrcOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstAddress),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeDstOffset),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastSrcAddrAdjustment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_writeLastDstAddrAdjustment)
  );
}
#endif /* MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_COPY */
