/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClDma_Drv.h
 * @brief Driver-layer of the mcuxClDma component
 */

#ifndef MCUXCLDMA_DRV_H_
#define MCUXCLDMA_DRV_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_FeatureConfig.h>
#include <internal/mcuxClDma_Sfr.h>
#include <mcuxClSession.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClDma_Drv mcuxClDma_Drv
 * @brief Defines the Driver layer of the @ref mcuxClDma component
 * @ingroup mcuxClDma
 * @{
 */

/**
 * @defgroup mcuxClDma_Drv_Defines mcuxClDma_Drv_Defines
 * @brief Defines of the Driver layer of the @ref mcuxClDma component
 * @ingroup mcuxClDma_Drv
 * @{
 */

/**
 * Defines for the source and destination offsets
 * These offsets will be applied to the address after each read/write access
 */
#define MCUXCLDMA_DRV_OFFSET_INCR_DIS     (MCUXCLDMA_SFR_TCD_SOFF_DOFF_0_BYTE)       ///< Do not adjust the source/destination address, always access the same address
#define MCUXCLDMA_DRV_OFFSET_INCR_1_BYTE  (MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_1_BYTE)  ///< Offset if source/destination address is byte-aligned
#define MCUXCLDMA_DRV_OFFSET_INCR_2_BYTE  (MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_2_BYTE)  ///< Offset if source/destination address is halfword-aligned
#define MCUXCLDMA_DRV_OFFSET_INCR_4_BYTE  (MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_4_BYTE)  ///< Offset if source/destination address is word-aligned
#define MCUXCLDMA_DRV_OFFSET_INCR_8_BYTE  (MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_8_BYTE)  ///< Offset if source/destination address is double word-aligned
#define MCUXCLDMA_DRV_OFFSET_INCR_16_BYTE (MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_16_BYTE) ///< Offset if source/destination address is 16-bytes-aligned
#define MCUXCLDMA_DRV_OFFSET_INCR_32_BYTE (MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_32_BYTE) ///< Offset if source/destination address is 32-bytes-aligned
#define MCUXCLDMA_DRV_OFFSET_INCR_64_BYTE (MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_64_BYTE) ///< Offset if source/destination address is 64-bytes-aligned

#define MCUXCLDMA_DRV_OFFSET_DECR_1_BYTE  (MCUXCLDMA_SFR_TCD_SOFF_DOFF_DECR_1_BYTE) ///< Offset if source/destination address is are set to reverse order

/**
 * Defines for the source and destination transfer size
 */
#define MCUXCLDMA_DRV_SRC_ACCESS_SIZE(size)    (MCUXCLDMA_SFR_TCD_ATTR_SSIZE(size))                                     ///< Set the source data transfer/access size
#define MCUXCLDMA_DRV_SRC_ACCESS_SIZE_1_BYTE   MCUXCLDMA_DRV_SRC_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_1_BYTE)  ///<  1-byte source data transfer/access size
#define MCUXCLDMA_DRV_SRC_ACCESS_SIZE_2_BYTE   MCUXCLDMA_DRV_SRC_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_2_BYTE)  ///<  2-byte source data transfer/access size
#define MCUXCLDMA_DRV_SRC_ACCESS_SIZE_4_BYTE   MCUXCLDMA_DRV_SRC_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_4_BYTE)  ///<  4-byte source data transfer/access size
#define MCUXCLDMA_DRV_SRC_ACCESS_SIZE_16_BYTE  MCUXCLDMA_DRV_SRC_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_16_BYTE) ///< 16-byte source data transfer/access size
#define MCUXCLDMA_DRV_DST_ACCESS_SIZE(size)    (MCUXCLDMA_SFR_TCD_ATTR_DSIZE(size))                                     ///< Set the destination data transfer/access size
#define MCUXCLDMA_DRV_DST_ACCESS_SIZE_1_BYTE   MCUXCLDMA_DRV_DST_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_1_BYTE)  ///<  1-byte destination data transfer/access size
#define MCUXCLDMA_DRV_DST_ACCESS_SIZE_2_BYTE   MCUXCLDMA_DRV_DST_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_2_BYTE)  ///<  2-byte destination data transfer/access size
#define MCUXCLDMA_DRV_DST_ACCESS_SIZE_4_BYTE   MCUXCLDMA_DRV_DST_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_4_BYTE)  ///<  4-byte destination data transfer/access size
#define MCUXCLDMA_DRV_DST_ACCESS_SIZE_8_BYTE   MCUXCLDMA_DRV_DST_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_8_BYTE)  ///<  8-byte destination data transfer/access size
#define MCUXCLDMA_DRV_DST_ACCESS_SIZE_16_BYTE  MCUXCLDMA_DRV_DST_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_16_BYTE) ///< 16-byte destination data transfer/access size
#define MCUXCLDMA_DRV_DST_ACCESS_SIZE_32_BYTE  MCUXCLDMA_DRV_DST_ACCESS_SIZE(MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_32_BYTE) ///< 32-byte destination data transfer/access size
/**
 * Defines for the source and destination minor loop offets
 * These offsets will be applied to the address after each service request, if enabled
 */
#define MCUXCLDMA_DRV_MINOR_OFFSET(offset)       (MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_MLOFF(offset))  ///< Set the source/destination address offset after each service request
#define MCUXCLDMA_DRV_MINOR_OFFSET_DECR_1_BYTE   MCUXCLDMA_DRV_MINOR_OFFSET(-1)   ///< Decrement the source/destination address after each service request by 1 byte
#define MCUXCLDMA_DRV_MINOR_OFFSET_DECR_2_BYTE   MCUXCLDMA_DRV_MINOR_OFFSET(-2)   ///< Decrement the source/destination address after each service request by 2 bytes
#define MCUXCLDMA_DRV_MINOR_OFFSET_DECR_4_BYTE   MCUXCLDMA_DRV_MINOR_OFFSET(-4)   ///< Decrement the source/destination address after each service request by 4 bytes
#define MCUXCLDMA_DRV_MINOR_OFFSET_DECR_16_BYTE  MCUXCLDMA_DRV_MINOR_OFFSET(-16)  ///< Decrement the source/destination address after each service request by 16 bytes
#define MCUXCLDMA_DRV_MINOR_OFFSET_SRC_EN        (MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_SMLOE_EN) ///< Apply the offset after each service request to the source address
#define MCUXCLDMA_DRV_MINOR_OFFSET_DST_EN        (MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_DMLOE_EN) ///< Apply the offset after each service request to the destination address

/**
 * Defines for the number of bytes to transfer per service request
 */
#define MCUXCLDMA_DRV_TRANSFER_PER_REQUEST(nbytes)   (MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_NBYTES(nbytes))  ///< Set the transfer size

/**
 * Defines for the source and destination major loop offsets
 * These offsets will be applied to the address after the channel is done, if enabled
 */
#define MCUXCLDMA_DRV_FINAL_OFFSET_DIS           (MCUXCLDMA_SFR_TCD_SLAST_DLAST_0_BYTE)       ///< Do not adjust the final source/destination address
#define MCUXCLDMA_DRV_FINAL_OFFSET_DECR_1_BYTE   (MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_1_BYTE)  ///< Decrement the final source/destination address by 1 byte
#define MCUXCLDMA_DRV_FINAL_OFFSET_DECR_2_BYTE   (MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_2_BYTE)  ///< Decrement the final source/destination address by 2 bytes
#define MCUXCLDMA_DRV_FINAL_OFFSET_DECR_4_BYTE   (MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_4_BYTE)  ///< Decrement the final source/destination address by 4 bytes
#define MCUXCLDMA_DRV_FINAL_OFFSET_DECR_16_BYTE  (MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_16_BYTE) ///< Decrement the final source/destination address by 16 bytes

/**
 *  Defines/Macros for the CH_MUX (Channel Multiplexor) register fields.
 */
#define MCUXCLDMA_DRV_HWREQ_SRC_DISABLED         (MCUXCLDMA_SFR_HWREQ_SRC_DISABLED)  ///< DMA handshake source for disabling handshakes
#define MCUXCLDMA_DRV_HWREQ_SRC_SGI_IN           (MCUXCLDMA_SFR_HWREQ_SRC_SGI_IN)    ///< DMA handshake source for SGI DATIN
#define MCUXCLDMA_DRV_HWREQ_SRC_SGI_OUT          (MCUXCLDMA_SFR_HWREQ_SRC_SGI_OUT)   ///< DMA handshake source for SGI DATOUT

/**
 * @}
 */ /* mcuxClDma_Drv_Defines */
/**
 * @brief Enable hardware requests for a specific DMA channel.
 *
 * @param channel  DMA channel
 *
 * @attention For certain hardware request signals to be routed to the DMA channel,
 *            the DMA channel multiplex needs to be configured as well, see
 *            @ref mcuxClDma_Sfr_setSrcSelect.
 *
 * @post
 * - If hardware requests for a channel are enabled, channel execution requests
 *   can be triggered by handshake signals from another co-processor (SGI).
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_enableHardwareRequests)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_enableHardwareRequests(mcuxClSession_Channel_t channel);

#ifdef MCUXCLDMA_FEATURE_INTERNAL_INTERRUPT_HANDLING
/**
 * @brief Enable error interrupts for a specific DMA channel.
 *        An interrupt will be triggered on every error in this channel.
 *
 * @param channel DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_enableErrorInterrupts)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_enableErrorInterrupts(mcuxClSession_Channel_t channel);

/**
 * @brief Disable error interrupts for a specific DMA channel.
 *
 * @param channel  DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_disableErrorInterrupts)
void mcuxClDma_Drv_disableErrorInterrupts(mcuxClSession_Channel_t channel);

/**
 * @brief Enable major loop interrupts for a specific DMA channel.
 *        An interrupt will be triggered as soon as the DMA channel is fully completed.
 *
 * @param channel  DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_enableChannelDoneInterrupts)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_enableChannelDoneInterrupts(mcuxClSession_Channel_t channel);

/**
 * @brief Disable major loop interrupts for a specific DMA channel.
 *
 * @param channel  DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_disableChannelDoneInterrupts)
void mcuxClDma_Drv_disableChannelDoneInterrupts(mcuxClSession_Channel_t channel);
#endif /* MCUXCLDMA_FEATURE_INTERNAL_INTERRUPT_HANDLING */

#if 0
/**
 * @brief Clear the interrupt request status of the given channel.
 *
 * This function must be called in the interrupt handler of the respective channel,
 * otherwise interrupt requests keep getting routed to the interrupt controller.
 *
 * @param channel  DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_clearInterruptRequestStatus)
void mcuxClDma_Drv_clearInterruptRequestStatus(mcuxClSession_Channel_t channel);
#endif

#if 0
/**
 * @brief Write the source transfer size.
 *
 * This function sets the transfer/access size of the source address in the channel,
 * i.e., it specifies the width of a read access.
 *
 * @param channel     DMA channel
 * @param accessSize  Source access/transfer size setting.
 *                    Use @ref MCUXCLDMA_DRV_SRC_ACCESS_SIZE() to construct the wanted value.
 *
 * @pre
 *  - This size must fit the alignment of the address, otherwise a configuration
 *    error is triggered on channel start.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeSrcAccessSize)
void mcuxClDma_Drv_writeSrcAccessSize(mcuxClSession_Channel_t channel, uint16_t accessSize);
#endif

#if 0
/**
 * @brief Write the destination transfer size.
 *
 * This function sets the transfer/access size of the destination address in the channel,
 * i.e., it specifies the width of a write access.
 *
 * @param channel     DMA channel
 * @param accessSize  Destination access/transfer size setting.
 *                    Use @ref MCUXCLDMA_DRV_DST_ACCESS_SIZE() to construct the wanted value.
 *
 * @pre
 *  - This size must fit the alignment of the address, otherwise a configuration
 *    error is triggered on channel start.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeDstAccessSize)
void mcuxClDma_Drv_writeDstAccessSize(mcuxClSession_Channel_t channel, uint16_t accessSize);
#endif

/**
 * @brief Write the source address offset of a DMA channel TCD.
 *
 * @param channel    DMA channel
 * @param srcOffset  Source address offset
 *
 * @pre
 *  - This offset must fit the configured access size, otherwise a configuration
 *    error is triggered on channel start. See also @ref mcuxClDma_Drv_writeSrcAccessSize.
 *
 * @post
 *  - This offset will be added to the source address after every read access.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeSrcOffset)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeSrcOffset(mcuxClSession_Channel_t channel, uint16_t srcOffset);

/**
 * @brief Write the destination address offset of a DMA channel TCD.
 *
 * @param channel    DMA channel
 * @param dstOffset  Destination address offset
 *
 * @pre
 *  - This offset must fit the configured access size, otherwise a configuration
 *    error is triggered on channel start. See also @ref mcuxClDma_Drv_writeDstAccessSize.
 *
 * @post
 *  - This offset will be added to the destination address after every write access.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeDstOffset)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeDstOffset(mcuxClSession_Channel_t channel, uint16_t dstOffset);

/**
 * @brief Write the source address of a DMA channel TCD.
 *
 * @param     channel  DMA channel
 * @param[in] pSrc     Source address
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeSrcAddress)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeSrcAddress(mcuxClSession_Channel_t channel, const uint8_t *pSrc);

#if 0
/**
 * @brief Read the source address of a DMA channel TCD.
 *
 * @param channel  DMA channel
 *
 * @return pSrcAddr
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_readSrcAddress)
uint8_t* mcuxClDma_Drv_readSrcAddress(mcuxClSession_Channel_t channel);
#endif

/**
 * @brief Write the destination address of a DMA channel TCD.
 *
 * @param     channel  DMA channel
 * @param[in] pDst     Destination address
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeDstAddress)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeDstAddress(mcuxClSession_Channel_t channel, uint8_t *pDst);

#if 0
/**
 * @brief Read the destination address of a DMA channel TCD.
 *
 * @param channel  DMA channel
 *
 * @return pDstAddr
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_readDstAddress)
uint8_t* mcuxClDma_Drv_readDstAddress(mcuxClSession_Channel_t channel);
#endif

/**
 * @brief Start a DMA channel explicitly by software.
 *
 * This function asserts the START bit of the channel
 *
 * @param channel  DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_startChannel)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_startChannel(mcuxClSession_Channel_t channel);

#ifdef MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_COPY
/**
 * @brief Wait for DMA channel DONE flag.
 *
 * This function reads the channel status until DONE is asserted.
 * While waiting, the error flags are checked.
 *
 * @param session  Session handle
 * @param channel  DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_waitForChannelDone)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_waitForChannelDone(mcuxClSession_Handle_t session, mcuxClSession_Channel_t channel);
#endif /* MCUXCLDMA_FEATURE_INTERNAL_HARDCODED_COPY */

#ifdef MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_OUTPUT_HANDSHAKES
/**
 * @brief Wait for DMA SGI-handshake channels DONE.
 *
 * This function reads the channel status of both channels associated to the session until DONE is asserted.
 * While waiting, the error flags are checked.
 *
 * @param session        Session handle
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_waitForHandshakeChannelsDone)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_waitForHandshakeChannelsDone(mcuxClSession_Handle_t session);

/**
 * @brief Link the DMA channels' hardware requests to the SGI I/O handshake signals.
 *
 * This function enables hardware requests in the input/output channels associated
 * to the session, and links the hardware requests to the SGI input and output
 * handshake signals.
 *
 * @param session   Session handle
 *
 * @post
 *  - With this setting, the DMA input channel will be started/notified once
 *    new SGI input can be written, and the DMA output channel will be notified/started once
 *    new SGI output is ready.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_linkWithSgiHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_linkWithSgiHandshakes(mcuxClSession_Handle_t session);
#endif /* MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_OUTPUT_HANDSHAKES */

#ifdef MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_HANDSHAKES
/**
 * @brief Link the DMA channel's hardware requests to the SGI input handshake signals.
 *
 * This function enables hardware requests in the DMA input channel associated to the session,
 * and links the hardware requests to the SGI input handshake signals.
 *
 * @param session   Session handle
 *
 * @post
 *  - With this setting, the DMA input channel will be started/notified once
 *    new SGI input can be written.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_linkWithSgiInputHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_linkWithSgiInputHandshakes(mcuxClSession_Handle_t session);
#endif /* MCUXCLDMA_FEATURE_INTERNAL_SGI_INPUT_HANDSHAKES */

/**
 * @brief Write the last source address adjustment to the DMA channel TCD.
 *
 * This function sets TCDn_CSR.ESDA (store destination address option) to 0.
 * @attention If ESDA shall be enabled instead, use @ref mcuxClDma_Drv_writeStoreFinalDstAddr.
 *
 * @param channel  DMA channel
 * @param offset   Last source address adjustment
 *
 * @post The given offset will be added to the source address upon major loop completion,
 *       i.e., once the channel is done.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeLastSrcAddrAdjustment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeLastSrcAddrAdjustment(mcuxClSession_Channel_t channel, uint32_t offset);

#if 0
/**
 * @brief Write the address for storing the final destination address to the DMA channel TCD
 *
 * This function sets TCDn_CSR.ESDA (store destination address option) to 1.
 * @attention If ESDA shall be disabled instead, use
 *            @ref mcuxClDma_Drv_writeLastSrcAddrAdjustment.
 *
 * @param channel  DMA channel
 * @param address  Memory address to store the final destination address at. Must be 32-bit aligned.
 *
 * @post
 *  - The given address in memory will be used to store the final destination address upon
 *    major loop completion, i.e., once the channel is done.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeStoreFinalDstAddr)
void mcuxClDma_Drv_writeStoreFinalDstAddr(mcuxClSession_Channel_t channel, uint32_t address);
#endif

/**
 * @brief Write the current/beginning major loop counts to the DMA channel TCD.
 *
 * This function writes the TCDn_CITER.CITER and TCDn_BITER.BITER fields to set
 * the current and beginning major loop counts, and sets TCDn_CITER.ELINK
 * and TCDn_BITER.ELINK to 0 (this disables channel-to-channel linking).
 *
 * If the DMA is started by software to do a copy operation, the @p count should
 * be set to 1. Setting the @p count to any other value is only needed when dealing
 * with hardware handshakes (SGI). Then, @p count shall be the amount of
 * requests that are expected from the hardware.
 *
 * @attention If ELINK (channel-to-channel linking) shall be enabled instead, use
 *            @ref mcuxClDma_Drv_writeMajorLoopCounts_withChannelLinking.
 *
 * @param channel  DMA channel
 * @param count    Major loop count
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeMajorLoopCounts)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeMajorLoopCounts(mcuxClSession_Channel_t channel, uint16_t count);

#ifdef MCUXCLDMA_FEATURE_INTERNAL_READ_CITER
/**
 * @brief Read the beginning major loop count of the DMA channel TCD.
 *
 * This functions reads the TCDn_BITER.BITER field (beginning major loop count) from the
 * channel.
 *
 * This function can be used to read-back the major loop count, even after the channel
 * is completed already. It gives information about the numbers of service requests
 * that were processed (i.e., when hardware requests are used, or for
 * channel-to-channel linking).
 *
 * @param channel  DMA channel
 *
 * @return Beginning major loop count
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_readMajorBeginningLoopCount)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClDma_Drv_readMajorBeginningLoopCount(mcuxClSession_Channel_t channel);
#endif /* MCUXCLDMA_FEATURE_INTERNAL_READ_CITER */

#if 0
/**
 * @brief Write the current/beginning major loop counts to the DMA channel TCD,
 *        and configure channel-to-channel linking.
 *
 * This functions writes the TCDn_CITER and TCDn_BITER fields to set the current and
 * beginning major loop counts, and sets TCDn_CITER.ELINK (channel-to-channel linking)
 * and TCDn_BITER.ELINK to 1. Hence, this enables channel-to-channel linking.
 *
 * If the DMA is started by software to do a copy operation, the @p count should
 * be set to 1. Setting the @p count to any other value is only needed when dealing
 * with hardware handshakes (SGI). Then, @p count shall be the amount of
 * requests that are expected from the hardware.
 *
 * @param channel        DMA channel
 * @param count          Current major loop count
 * @param linkingConfig  Channel-to-channel linking configuration
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeMajorLoopCounts_withChannelLinking)
void mcuxClDma_Drv_writeMajorLoopCounts_withChannelLinking(mcuxClSession_Channel_t channel, uint16_t count, uint16_t linkingConfig);
#endif

/**
 * @brief Write the transfer size (without minor loop offsets) to the DMA channel TCD.
 *
 * Write the total number of bytes to be transfered. Minor loop offsets will be disabled.
 *
 * @param channel                DMA channel
 * @param size                   Transfer size in bytes
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeTransferSize)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeTransferSize(mcuxClSession_Channel_t channel, uint32_t size);

#if 0
/**
 * @brief Write the transfer size with minor loop offsets to the DMA channel TCD.
 *
 * Write the total number of bytes to be transfered, and the minor loop offset configuration.
 * If enabled, the minor loop offset is added to the source and/or destination address upon minor loop completion.
 *
 * @param channel                DMA channel
 * @param size                   Transfer size in bytes
 * @param minorLoopOffsetConfig  Minor loop offset configuration
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeTransferSizeWithMinorLoopOffsets)
void mcuxClDma_Drv_writeTransferSizeWithMinorLoopOffsets(mcuxClSession_Channel_t channel, uint32_t size, uint32_t minorLoopOffsetConfig);
#endif

/**
 * @brief Write the last destination address adjustment to the DMA channel TCD, and set TCDn_CSR.ESG to 0.
 *
 * The given offset is added to the destination address upon major loop completion,
 * and disable the TCDn_CSR.ESG (enable scatter-gather) bit.
 *
 * @param channel  DMA channel
 * @param offset   Last destination address adjustment
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeLastDstAddrAdjustment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_Drv_writeLastDstAddrAdjustment(mcuxClSession_Channel_t channel, uint32_t offset);

#if 0
/**
 * @brief Write the scatter-gather address to the DMA channel TCD, and set TCDn_CSR.ESG to 1.
 *
 * Write the scatter-gather address, and enable the TCDn_CSR.ESG (enable store destination address) bit.
 *
 * @param channel  DMA channel
 * @param address  Scatter-gather address
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_writeScatterGatherAddr)
void mcuxClDma_Drv_writeScatterGatherAddr(mcuxClSession_Channel_t channel, uint32_t address);
#endif

#if 0
/**
 * @brief Read the MP_ES SFR for which DMA channel triggered an error. The channel number is returned.
 *
 * @param void
 *
 * @return mcuxClSession_Channel_t
 * @retval Number of the DMA channel that triggered an error
 * @retval MCUXCLSESSION_DMACHANNEL_INVALID if no channel triggered any error
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_Drv_getChannelFromErrorStatus)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Channel_t) mcuxClDma_Drv_getChannelFromErrorStatus(void);
#endif

/**
 * @}
 */ /* mcuxClDma_Drv_Functions */

/**
 * @}
 */ /* mcuxClDma_Drv */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLDMA_DRV_H_ */
