/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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

/**
 * @file  mcuxClDma_Utils.h
 * @brief Utils-layer of the mcuxClDma component.
 */

#ifndef MCUXCLDMA_UTILS_H_
#define MCUXCLDMA_UTILS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClDma_Drv.h>
#include <mcuxClDma_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClDma_Utils mcuxClDma_Utils
 * @brief Defines the Utils layer of the @ref mcuxClDma component.
 * @ingroup mcuxClDma
 * @{
 */


/**
 * @defgroup mcuxClDma_Utils_Functions mcuxClDma_Utils_Functions
 * @brief Functions of the Utils layer of the @ref mcuxClDma component
 * @ingroup mcuxClDma_Utils
 * @{
 */

/**
 * @brief Calculates the DMA TCD (source or destination) offset and size
 *        based on the alignment of the given address.
 *
 * The offset can be written to the DMA TCDn.SOFF or TCDn_DOFF register.
 * The size can be written to the TCDn_ATTR.SSIZE or TCDn_ATTR.DSIZE register field.
 *
 * @param[in]   pAddr    Source or destination address for the DMA channel.
 * @param[out]  pOffset  The calculated offset
 * @param[out]  pSize    The calculated size
 * @param       size     The total transfer size
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment)
MCUX_CSSL_FP_PROTECTED_TYPE(MCUX_CSSL_FP_PROTECTED_TYPE(void)) mcuxClDma_Utils_getTCDOffsetAndSizeFromAlignment(
  const uint8_t *pAddr,
  uint16_t *pOffset,
  uint16_t *pSize,
  uint32_t size);

#ifdef MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_COPY
/**
 * @brief Configures the given DMA channel for data transfer of arbitrary size.
 *
 * This function will configure the given DMA channel to copy @p length
 * bytes from @p pSrc to @p pDst.
 * The access sizes and offsets will be set based on the given address alignments,
 * i.e. if both addresses are word-aligned, word-wise access will be used (if the
 * requested data length allows it).
 *
 * @attention:
 * Address alignment of both addresses does not guarantee a word-wise transfer.
 * Byte-wise data transfer will be configured if the given length is not a multiple of the
 * word length.
 *
 * @param       channel  DMA channel that should be used
 * @param[in]   pSrc     Source address
 * @param[in]   pDst     Destination address
 * @param       length   Amount of bytes to copy from source to destination.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Utils_configureDataTransfer)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Utils_configureDataTransfer(
  mcuxClSession_Channel_t channel,
  const uint8_t *pSrc,
  uint8_t *pDst,
  uint32_t length);
#endif /* MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_COPY */

/**
 * @}
 */ /* mcuxClDma_Utils_Functions */

/**
 * @}
 */ /* mcuxClDma_Utils */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLDMA_UTILS_H_ */
