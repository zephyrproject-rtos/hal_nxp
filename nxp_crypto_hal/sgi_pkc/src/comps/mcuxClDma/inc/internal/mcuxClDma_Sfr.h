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
 * @file  mcuxClDma_Sfr.h
 * @brief SFR-layer of the mcuxClDma component
 */

#ifndef MCUXCLDMA_SFR_H_
#define MCUXCLDMA_SFR_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <stdbool.h>
#include <platform_specific_headers.h>
#include <internal/mcuxClDma_SfrAccess.h>
#include <mcuxClSession.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClDma_Sfr mcuxClDma_Sfr
 * @brief Defines the SFR layer of the @ref mcuxClDma component
 * @ingroup mcuxClDma
 * @{
 */

/**
 * @defgroup mcuxClDma_Sfr_Defines mcuxClDma_Sfr_Defines
 * @brief Defines for the SFR layer of the @ref mcuxClDma component
 * @ingroup mcuxClDma_Sfr
 * @{
 */

/**
 * Defines/Macros for the MP_ES (MP Error Status) register fields.
 */
#define MCUXCLDMA_SFR_MP_ES_DBE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, DBE) ///< Destination bus error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_SBE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, SBE) ///< Source bus error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_SGE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, SGE) ///< Scatter-Gather configuration error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_NCE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, NCE) ///< NBYTES/CITER configuration error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_DOE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, DOE) ///< Destination offset error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_DAE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, DAE) ///< Destination address error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_SOE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, SOE) ///< Source offset error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_SAE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, SAE) ///< Source address error in one of the channels
#define MCUXCLDMA_SFR_MP_ES_ECX(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, ECX) ///< Transfer Canceled for one of the channels
#define MCUXCLDMA_SFR_MP_ES_UCE(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, UCE) ///< Uncorrectable TCD error during channel execution
#define MCUXCLDMA_SFR_MP_ES_ERRCHN(value)  MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, ERRCHN) ///< Error in a channel
#define MCUXCLDMA_SFR_MP_ES_VLD(value)     MCUXCLDMA_MP_FIELD_TO_VALUE32(value, ES, VLD) ///< Valid. Indicates whether a valid error exists in one of the channels that software has not cleared


/**
 * Defines/Macros for the CH_CSR (Channel Control and Status) register fields.
 */
#define MCUXCLDMA_SFR_CH_CSR_ACTIVE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, CSR, ACTIVE) ///< Channel active
#define MCUXCLDMA_SFR_CH_CSR_DONE(value)    MCUXCLDMA_CH_FIELD_TO_VALUE32(value, CSR, DONE) ///< Channel done

#define MCUXCLDMA_SFR_CH_CSR_DONE_EN        ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(CSR, DONE)) ///< Set the channel done field - write 1 to clear
#define MCUXCLDMA_SFR_CH_CSR_EBW_EN         ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(CSR, EBW)) ///< Enable buffered writes
#define MCUXCLDMA_SFR_CH_CSR_EEI_EN         ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(CSR, EEI)) ///< Enable error interrupt
#define MCUXCLDMA_SFR_CH_CSR_EARQ_EN        ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(CSR, EARQ)) ///< Enable asynchronous DMA request
#define MCUXCLDMA_SFR_CH_CSR_ERQ_EN         ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(CSR, ERQ)) ///< Enable DMA request (hardware service request)

/** Enable a single-bit field of the CH_CSR register of a DMA channel. */
#define MCUXCLDMA_SFR_CH_CSR_ENABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_CH_SFR_BITFIELD_SET(channel, CSR, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Disable a single-bit field of the CH_CSR register of a DMA channel. */
#define MCUXCLDMA_SFR_CH_CSR_DISABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_CH_SFR_BITFIELD_CLEAR(channel, CSR, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)


/**
 * Defines/Macros for the CH_ES (Channel Error Status) register fields.
 */
#define MCUXCLDMA_SFR_CH_ES_ERR(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, ERR) ///< Error in channel
#define MCUXCLDMA_SFR_CH_ES_SAE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, SAE) ///< Source address error
#define MCUXCLDMA_SFR_CH_ES_SOE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, SOE) ///< Source offset error
#define MCUXCLDMA_SFR_CH_ES_DAE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, DAE) ///< Destination address error
#define MCUXCLDMA_SFR_CH_ES_DOE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, DOE) ///< Destination offset error
#define MCUXCLDMA_SFR_CH_ES_NCE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, NCE) ///< NBYTES/CITER configuration error
#define MCUXCLDMA_SFR_CH_ES_SGE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, SGE) ///< Scatter-Gather configuration error
#define MCUXCLDMA_SFR_CH_ES_SBE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, SBE) ///< Source bus error
#define MCUXCLDMA_SFR_CH_ES_DBE(value)  MCUXCLDMA_CH_FIELD_TO_VALUE32(value, ES, DBE) ///< Destination bus error
#define MCUXCLDMA_SFR_CH_ES_CLEAR       ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(ES, ERR)) ///< Write to ERR, clear the whole channel error status


/**
 * Defines/Macros for the CH_SBR (Channel System Bus) register fields.
 */
#define MCUXCLDMA_SFR_CH_SBR_ATTR(attr)    (MCUXCLDMA_CH_VALUE32_TO_FIELD(attr, SBR, ATTR)) ///< Set AHB system bus attribute output value
#define MCUXCLDMA_SFR_CH_SBR_ATTR_SET_ALL  (MCUXCLDMA_CH_SFR_BITMSK(SBR, ATTR)) ///< Enable all bits of the AHB system bus attribute output value
#define MCUXCLDMA_SFR_CH_SBR_EMI_EN        ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(SBR, EMI)) ///< Enable master ID replication
#define MCUXCLDMA_SFR_CH_SBR_PAL_EN        ((uint32_t) 1u << MCUXCLDMA_CH_SFR_BITPOS(SBR, PAL)) ///< Enable privileged access/protection level for DMA transfers
#define MCUXCLDMA_SFR_CH_SBR_MASTERID(id)  (MCUXCLDMA_CH_VALUE32_TO_FIELD(id, SBR, MID)) ///< Set the master ID on the system bus when the channel is active

/** Enable a single-bit field of the CH_SBR register of a DMA channel. */
#define MCUXCLDMA_SFR_CH_SBR_ENABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_CH_SFR_BITFIELD_SET(channel, SBR, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Disable a single-bit field of the CH_SBR register of a DMA channel. */
#define MCUXCLDMA_SFR_CH_SBR_DISABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_CH_SFR_BITFIELD_CLEAR(channel, SBR, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the CH_SBR register of a DMA channel. */
#define MCUXCLDMA_SFR_CH_SBR_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_CH_SFR32_BITFIELD_WRITE(channel, SBR, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/**
 *  Defines/Macros for the CH_MUX (Channel Multiplexor) register fields.
 */
#define MCUXCLDMA_SFR_HWREQ_SRC_DISABLED       ((uint32_t)DMA_REQ_SRC_DISABLED)    ///< DMA handshake source for disabling handshakes
#define MCUXCLDMA_SFR_HWREQ_SRC_SGI_IN         ((uint32_t)DMA_REQ_SRC_SGI_IN)      ///< DMA handshake source for SGI DATIN
#define MCUXCLDMA_SFR_HWREQ_SRC_SGI_OUT        ((uint32_t)DMA_REQ_SRC_SGI_OUT)     ///< DMA handshake source for SGI DATOUT

/**
 * Defines/Macros for the TCDn_ATTR register fields
 */
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_1_BYTE    ((uint16_t) 0u) ///< 1-byte source/destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_2_BYTE    ((uint16_t) 1u) ///< 2-byte source/destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_4_BYTE    ((uint16_t) 2u) ///< 4-byte source/destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_8_BYTE    ((uint16_t) 3u) ///< 8-byte source/destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_16_BYTE   ((uint16_t) 4u) ///< 16-byte source/destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_32_BYTE   ((uint16_t) 5u) ///< 32-byte source/destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE_DSIZE_64_BYTE   ((uint16_t) 6u) ///< 64-byte source/destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SSIZE(size)           (MCUXCLDMA_TCD_VALUE16_TO_FIELD(size, ATTR, SSIZE)) ///< Source data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_DSIZE(size)           (MCUXCLDMA_TCD_VALUE16_TO_FIELD(size, ATTR, DSIZE)) ///< Destination data transfer size
#define MCUXCLDMA_SFR_TCD_ATTR_SMOD(mod)             (MCUXCLDMA_TCD_VALUE16_TO_FIELD(mod, ATTR, SMOD)) ///< Source address modulu
#define MCUXCLDMA_SFR_TCD_ATTR_DMOD(mod)             (MCUXCLDMA_TCD_VALUE16_TO_FIELD(mod, ATTR, DMOD)) ///< Destination address modulu

/** Write to a multi-bit field of the TCDn_ATTR register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_ATTR_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR16_BITFIELD_WRITE(channel, ATTR, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)


/**
 * Defines for the TCDn_SOFF and TCDn_DOFF registers
 */

#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_0_BYTE       ((uint16_t)  0u)  ///< No offset adjustment of source/destination address, always access the same address
#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_1_BYTE  ((uint16_t)  1u)  ///< Offset if source/destination address is byte-aligned
#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_2_BYTE  ((uint16_t)  2u)  ///< Offset if source/destination address is halfword-aligned
#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_4_BYTE  ((uint16_t)  4u)  ///< Offset if source/destination address is word-aligned
#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_8_BYTE  ((uint16_t)  8u)  ///< Offset if source/destination address is double word-aligned
#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_16_BYTE ((uint16_t) 16u)  ///< Offset if source/destination address is quadword-aligned
#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_32_BYTE ((uint16_t) 32u)  ///< Offset if source/destination address is 32bytes-aligned
#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_INCR_64_BYTE ((uint16_t) 64u)  ///< Offset if source/destination address is 64bytes-aligned

#define MCUXCLDMA_SFR_TCD_SOFF_DOFF_DECR_1_BYTE  ((uint16_t) -1)  ///< Offset if source/destination address is are set to reverse order
/**
 * Defines for the TCDn_SLAST_SDA and TCDn_DLAST_SGA registers
 */
#define MCUXCLDMA_SFR_TCD_SLAST_DLAST_0_BYTE        ((uint32_t) 0) ///< Do not adjust the last source/destination address after major loop completion
#define MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_1_BYTE   ((uint32_t) -1) ///< Decrement the last source/destination address after major loop completion by 1 byte
#define MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_2_BYTE   ((uint32_t) -2) ///< Decrement the last source/destination address after major loop completion by 2 bytes
#define MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_4_BYTE   ((uint32_t) -4) ///< Decrement the last source/destination address after major loop completion by 4 bytes
#define MCUXCLDMA_SFR_TCD_SLAST_DLAST_DECR_16_BYTE  ((uint32_t) -16) ///< Decrement the last source/destination address after major loop completion by 16 bytes


/**
 * Defines/Macros for the TCDn_CITER_ELINK register fields
 */
#define MCUXCLDMA_SFR_TCD_CITER_ELINKYES_ELINK_EN         ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CITER_ELINKYES, ELINK)) ///< Enable channel-to-channel linking
#define MCUXCLDMA_SFR_TCD_CITER_ELINKYES_LINKCH(channel)  (MCUXCLDMA_TCD_VALUE16_TO_FIELD(channel, CITER_ELINKYES, LINKCH)) ///< Set the link channel number
#define MCUXCLDMA_SFR_TCD_CITER_ELINKYES_CITER(count)     (MCUXCLDMA_TCD_VALUE16_TO_FIELD(count, CITER_ELINKYES, CITER)) ///< Set the current major iteration count with channel-to-channel linking enabled
#define MCUXCLDMA_SFR_TCD_CITER_ELINKNO_CITER(count)      (MCUXCLDMA_TCD_VALUE16_TO_FIELD(count, CITER_ELINKNO, CITER)) ///< Set the current major iteration count with channel-to-channel linking disabled

/** Enable a single-bit field of the TCDn_CITER_ELINKYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_CITER_ELINKYES_ENABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR_BITFIELD_SET(channel, CITER_ELINKYES, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Disable a single-bit field of the TCDn_CITER_ELINKYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_CITER_ELINKYES_DISABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR_BITFIELD_CLEAR(channel, CITER_ELINKYES, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the TCDn_CITER_ELINKYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_CITER_ELINKYES_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR16_BITFIELD_WRITE(channel, CITER_ELINKYES, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the TCDn_CITER_ELINKNO register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_CITER_ELINKNO_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR16_BITFIELD_WRITE(channel, CITER_ELINKNO, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)


/**
 * Defines/Macros for the TCDn_BITER_ELINK register fields
 */
#define MCUXCLDMA_SFR_TCD_BITER_ELINKYES_ELINK_EN         ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(BITER_ELINKYES, ELINK)) ///< Enable channel-to-channel linking
#define MCUXCLDMA_SFR_TCD_BITER_ELINKYES_LINKCH(channel)  (MCUXCLDMA_TCD_VALUE16_TO_FIELD(channel, BITER_ELINKYES, LINKCH)) ///< Set the link channel number
#define MCUXCLDMA_SFR_TCD_BITER_ELINKYES_BITER(count)     (MCUXCLDMA_TCD_VALUE16_TO_FIELD(count, BITER_ELINKYES, BITER)) ///< Set the beginning major iteration count with channel-to-channel linking enabled
#define MCUXCLDMA_SFR_TCD_BITER_ELINKNO_BITER(count)      (MCUXCLDMA_TCD_VALUE16_TO_FIELD(count, BITER_ELINKNO, BITER)) ///< Set the beginning major iteration count with channel-to-channel linking disabled

/** Enable a single-bit field of the TCDn_BITER_ELINKYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_BITER_ELINKYES_ENABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR_BITFIELD_SET(channel, BITER_ELINKYES, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Disable a single-bit field of the TCDn_BITER_ELINKYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_BITER_ELINKYES_DISABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR_BITFIELD_CLEAR(channel, BITER_ELINKYES, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the TCDn_BITER_ELINKYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_BITER_ELINKYES_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR16_BITFIELD_WRITE(channel, BITER_ELINKYES, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the TCDn_BITER_ELINKNO register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_BITER_ELINKNO_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR16_BITFIELD_WRITE(channel, BITER_ELINKNO, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Read from a multi-bit field of the TCDn_BITER_ELINKNO register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_BITER_ELINKNO_READ_FIELD(channel, field) \
  MCUXCLDMA_TCD_SFR_BITFIELD_READ(channel, BITER_ELINKNO, field)

/**
 * Defines/Macros for the TCDn_NYBTES_MLOFF register fields
 */
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_SMLOE_EN       ((uint32_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(NBYTES_MLOFFYES, SMLOE)) ///< Enable source minor loop offset
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_DMLOE_EN       ((uint32_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(NBYTES_MLOFFYES, DMLOE)) ///< Enable destination minor loop offset
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_MLOFF(offset)  (MCUXCLDMA_TCD_VALUE32_TO_FIELD(offset, NBYTES_MLOFFYES, MLOFF)) ///< Set the minor loop offset
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_NBYTES(size)   (MCUXCLDMA_TCD_VALUE32_TO_FIELD(size, NBYTES_MLOFFYES, NBYTES)) ///< Set the transfer size with minor loop offsets enabled
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFNO_NBYTES(size)    (MCUXCLDMA_TCD_VALUE32_TO_FIELD(size, NBYTES_MLOFFNO, NBYTES)) ///< Set the transfer size with minor loop offsets disabled

/** Enable a single-bit field of the TCDn_NBYTES_MLOFFYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_ENABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR_BITFIELD_SET(channel, NBYTES_MLOFFYES, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Disable a single-bit field of the TCDn_NBYTES_MLOFFYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_DISABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR_BITFIELD_CLEAR(channel, NBYTES_MLOFFYES, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the TCDn_NBYTES_MLOFFYES register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFYES_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR32_BITFIELD_WRITE(channel, NBYTES_MLOFFYES, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the TCDn_NBYTES_MLOFFNO register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_NBYTES_MLOFFNO_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR32_BITFIELD_WRITE(channel, NBYTES_MLOFFNO, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)


/**
 * Defines/Macros for the TCD TCDn_CSR (Control Status Register) register fields
 */
#define MCUXCLDMA_SFR_TCD_CSR_BWC_NO_ENGINE_STALLS       ((uint16_t) 0u) ///< No DMA engine stalls
#define MCUXCLDMA_SFR_TCD_CSR_BWC_4_CYCLE_ENGINE_STALLS  ((uint16_t) 2u) ///< DMA engine stalls for 4 cycles after each R/W
#define MCUXCLDMA_SFR_TCD_CSR_BWC_8_CYCLE_ENGINE_STALLS  ((uint16_t) 3u) ///< DMA engine stalls for 8 cycles after each R/W
#define MCUXCLDMA_SFR_TCD_CSR_BWC(stalls)                (MCUXCLDMA_TCD_VALUE16_TO_FIELD(stalls, CSR, BWC)) ///< Set engine stalls for BWC
#define MCUXCLDMA_SFR_TCD_CSR_ESDA_EN                    ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, ESDA)) ///< Enable store destination address
#define MCUXCLDMA_SFR_TCD_CSR_EEOP_EN                    ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, EEOP)) ///< Enable end-of-packet processing
#define MCUXCLDMA_SFR_TCD_CSR_MAJORELINK_EN              ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, MAJORELINK)) ///< Enable link when major loop complete (channel-to-channel linking)
#define MCUXCLDMA_SFR_TCD_CSR_MAJORLINK_CHANNEL(ch)      (MCUXCLDMA_TCD_VALUE16_TO_FIELD(ch, CSR, MAJORLINKCH)) ///< Set the major loop link channel number
#define MCUXCLDMA_SFR_TCD_CSR_ESG_EN                     ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, ESG)) ///< Enable scatter-gather processing
#define MCUXCLDMA_SFR_TCD_CSR_DREQ_EN                    ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, DREQ)) ///< Enable clearing of ERQ-bit when major iteration count reaches 0
#define MCUXCLDMA_SFR_TCD_CSR_INTHALF_EN                 ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, INTHALF)) ///< Enable interrupt if major counter half-complete
#define MCUXCLDMA_SFR_TCD_CSR_INTMAJOR_EN                ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, INTMAJOR)) ///< Enable interrupt if major counter complete
#define MCUXCLDMA_SFR_TCD_CSR_START_EN                   ((uint16_t) 1u << MCUXCLDMA_TCD_SFR_BITPOS(CSR, START)) ///< Explicitely start a channel

/** Enable a single-bit field of the TCDn_CSR (control and Status) register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_CSR_ENABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUXCLDMA_TCD_SFR_BITFIELD_SET(channel, CSR, field); \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Disable a single-bit field of the TCDn_CSR (control and Status) register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_CSR_DISABLE_FIELD(channel, field) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_SIGNED_TO_UNSIGNED_MAY_RESULT_TO_MISINTERPRETED_DATA("False positive") \
      MCUXCLDMA_TCD_SFR16_BITFIELD_CLEAR(channel, CSR, field); \
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_SIGNED_TO_UNSIGNED_MAY_RESULT_TO_MISINTERPRETED_DATA() \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

/** Write to a multi-bit field of the TCDn_CSR (control and Status) register of a DMA channel TCD. */
#define MCUXCLDMA_SFR_TCD_CSR_WRITE_FIELD(channel, field, value) \
  do{ MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS() \
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_SIGNED_TO_UNSIGNED_MAY_RESULT_TO_MISINTERPRETED_DATA("False positive") \
      MCUXCLDMA_TCD_SFR16_BITFIELD_WRITE(channel, CSR, field, value); \
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_SIGNED_TO_UNSIGNED_MAY_RESULT_TO_MISINTERPRETED_DATA() \
      MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS() \
  } while(false)

 /**
 * @}
 */ /* mcuxClDma_Sfr_Defines */


/**
 * @defgroup mcuxClDma_Sfr_Functions mcuxClDma_Sfr_Functions
 * @brief Functions of the SFR layer of the @ref mcuxClDma component
 * @ingroup mcuxClDma_Sfr
 * @{
 */


/*************************************************************/
/* Functions to read/write the DMA Management Page (MP) SFRs */
/*************************************************************/

/**
 * @brief Write the MP_CSR (Management Page Control) register of the DMA Managament Page.
 *
 * @param value  Value to write to the SFR
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeControlAndStatus)
static inline void mcuxClDma_Sfr_writeControlAndStatus(uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_MP_SFR_WRITE(CSR, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the MP_CSR (Management Page Control) register of the DMA Managament Page.
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readControlAndStatus)
static inline uint32_t mcuxClDma_Sfr_readControlAndStatus(void)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_MP_SFR_READ(CSR);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Read the MP_ES (Management Page Error Status) register of the DMA Managament Page.
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readErrorStatus)
static inline uint32_t mcuxClDma_Sfr_readErrorStatus(void)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_MP_SFR_READ(ES);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the MP_INT (Management Page Interrupt Request Status) register of the DMA Managament Page.
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readInterruptRequestStatus)
static inline uint32_t mcuxClDma_Sfr_readInterruptRequestStatus(void)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_MP_SFR_READ(INT);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Read the MP_HRS (Management Page Hardware Request Status) register of the DMA Managament Page.
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readHardwareRequestStatus)
static inline uint32_t mcuxClDma_Sfr_readHardwareRequestStatus(void)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_MP_SFR_READ(HRS);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the CHn_GRPRI (Channel Arbitration Group) register of the DMA Managament Page.
 *
 * @param channel  DMA channel for which the arbitration group shall be set
 * @param group    Arbitration group
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeChannelArbitrationGroup)
static inline void mcuxClDma_Sfr_writeChannelArbitrationGroup(mcuxClSession_Channel_t channel, uint32_t group)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_MP_CH_SFR_WRITE(channel, CH_GRPRI, group);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the CHn_GRPRI (Channel Arbitration Group) register of the DMA Managament Page.
 *
 * @param channel  DMA channel for which the arbitration group shall be read
 *
 * @return Arbitration group of requested channel
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readChannelArbitrationGroup)
static inline uint32_t mcuxClDma_Sfr_readChannelArbitrationGroup(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_MP_CH_SFR_READ(channel, CH_GRPRI);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/*************************************************************/
/* Functions to read/write the DMA Channel-specific SFRs     */
/*************************************************************/


/**
 * @brief Write the CH_CSR (Channel Control and Status) register of a DMA channel.
 *
 * @param channel  DMA channel
 * @param value    Value to write to the SFR
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeChannelControlAndStatus)
static inline void mcuxClDma_Sfr_writeChannelControlAndStatus(mcuxClSession_Channel_t channel, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_CH_SFR_WRITE(channel, CSR, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the CH_CSR (Channel Control and Status) register of a DMA channel.
 *
 * @param channel  DMA channel
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readChannelControlAndStatus)
static inline uint32_t mcuxClDma_Sfr_readChannelControlAndStatus(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_CH_SFR_READ(channel, CSR);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the CH_ES (Channel Error Status) register of a DMA channel.
 *
 * Writing to this register will clear its contents.
 *
 * @param channel  DMA channel
 * @param value    Value to write to the SFR
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeChannelErrorStatus)
static inline void mcuxClDma_Sfr_writeChannelErrorStatus(mcuxClSession_Channel_t channel, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_CH_SFR_WRITE(channel, ES, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the CH_ES (Channel Error Status) register of a DMA channel.
 *
 * @param channel  DMA channel
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readChannelErrorStatus)
static inline uint32_t mcuxClDma_Sfr_readChannelErrorStatus(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_CH_SFR_READ(channel, ES);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Write the CH_INT (Channel Interrupt Status) register of a DMA channel.
 *
 * @param channel  DMA channel
 * @param value    Value to write to the SFR
 *
 * @post
 *  -  Writing to this register will clear its contents.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeChannelInterruptStatus)
static inline void mcuxClDma_Sfr_writeChannelInterruptStatus(mcuxClSession_Channel_t channel, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_CH_SFR_WRITE(channel, INT, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the CH_INT (Channel Interrupt Status) register of a DMA channel.
 *
 * @param channel  DMA channel
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readChannelInterruptStatus)
static inline uint32_t mcuxClDma_Sfr_readChannelInterruptStatus(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_CH_SFR_READ(channel, INT);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Write the CH_PRI (Channel Priority) register of a DMA channel.
 *
 * @param channel  DMA channel
 * @param value    Value to write to the SFR
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeChannelPriority)
static inline void mcuxClDma_Sfr_writeChannelPriority(mcuxClSession_Channel_t channel, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_CH_SFR_WRITE(channel, PRI, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the CH_PRI (Channel Priority) register of a DMA channel.
 *
 * @param channel  DMA channel
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readChannelPriority)
static inline uint32_t mcuxClDma_Sfr_readChannelPriority(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_CH_SFR_READ(channel, PRI);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/*************************************************************/
/* Functions to read/write the DMA channel TCD SFRs          */
/*************************************************************/

/**
 * @brief Write the CSR (control and Status) register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 * @param value    Value to set the control and status register
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeTCDControlAndStatus)
static inline void mcuxClDma_Sfr_writeTCDControlAndStatus(mcuxClSession_Channel_t channel, uint16_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, CSR, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the CSR (Control and Status) register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readTCDControlAndStatus)
static inline uint16_t mcuxClDma_Sfr_readTCDControlAndStatus(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_TCD_SFR_READ(channel, CSR);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_SADDR (Source Address) register of a DMA channel TCD.
 *
 * @param     channel  DMA channel
 * @param[in] pSrc     Source address
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeSrcAddress)
static inline void mcuxClDma_Sfr_writeSrcAddress(mcuxClSession_Channel_t channel, const uint8_t *pSrc)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, SADDR, (uint32_t)pSrc);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Read the TCDn_SADDR (Source Address) register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 *
 * @return Source address
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readSrcAddress)
static inline uint32_t mcuxClDma_Sfr_readSrcAddress(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_TCD_SFR_READ(channel, SADDR);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_DADDR (Destination Address) register of a DMA channel TCD.
 *
 * @param     channel  DMA channel
 * @param[in] pDst     Destination address
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeDstAddress)
static inline void mcuxClDma_Sfr_writeDstAddress(mcuxClSession_Channel_t channel, uint8_t *pDst)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, DADDR, (uint32_t)pDst);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Read the TCDn_DADDR (Destination Address) register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 *
 * @return Destination address
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readDstAddress)
static inline uint32_t mcuxClDma_Sfr_readDstAddress(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_TCD_SFR_READ(channel, DADDR);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_SOFF (signed Source address Offset) register of a DMA channel TCD.
 *        This offset will be added to the source address after every read transaction.
 *
 * @param channel    DMA channel
 * @param srcOffset  Source address offset
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeSrcOffset)
static inline void mcuxClDma_Sfr_writeSrcOffset(mcuxClSession_Channel_t channel, uint16_t srcOffset)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, SOFF, srcOffset);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_DOFF (signed Destination address Offset) register of a DMA channel TCD.
 *        This offset will be added to the destination address after every write transaction.
 *
 * @param channel    DMA channel
 * @param dstOffset  Destination address offset
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeDstOffset)
static inline void mcuxClDma_Sfr_writeDstOffset(mcuxClSession_Channel_t channel, uint16_t dstOffset)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, DOFF, dstOffset);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_ATTR (transfer Attributes) register of a DMA channel TCD.
 *
 * @param channel     DMA channel
 * @param attributes  Transfer attributes
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeTransferAttributes)
static inline void mcuxClDma_Sfr_writeTransferAttributes(mcuxClSession_Channel_t channel, uint16_t attributes)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, ATTR, attributes);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Read the TCDn_ATTR (transfer Attributes) register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 *
 * @return SFR content
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_readTransferAttributes)
static inline uint16_t mcuxClDma_Sfr_readTransferAttributes(mcuxClSession_Channel_t channel)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return MCUXCLDMA_TCD_SFR_READ(channel, ATTR);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_NBYTES_MLOFF register of DMA channel TCD.
 *
 * @param channel  DMA channel
 * @param value    Value to write to the SFR
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeTransferSizeMinorLoopOffset)
static inline void mcuxClDma_Sfr_writeTransferSizeMinorLoopOffset(mcuxClSession_Channel_t channel, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, NBYTES_MLOFFYES, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_SLAST_SDA (Last Source address adjustment/the "Store final Destination Address") register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 * @param value    Last source address adjustment / System address to store the final destination address at
 *
 * @pre
 *  - Purpose of this register depends on the CSR.ESDA (Enable Store Destination Address) setting.
 *  - ESDA = 0: Write last source address adjustment
 *  - ESDA = 1: Write memory location to store the final destination address after transfer completion.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeSrcLast_writeStoreDstAddr)
static inline void mcuxClDma_Sfr_writeSrcLast_writeStoreDstAddr(mcuxClSession_Channel_t channel, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, SLAST_SDA, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_DLAST_SGA (Last Destination address adjustment/the "Scatter-Gather Address") register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 * @param value    Last destination address adjustment / Next scatter-gather address
 *
 * @pre
 *  - Purpose of this register depends on the ESG (enable scatter-gather processing) setting.
 *  - ESG = 0: Write last destination address adjustment
 *  - ESG = 1: Write next scatter-gather address.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeDstLast_writeScatterGatherAddr)
static inline void mcuxClDma_Sfr_writeDstLast_writeScatterGatherAddr(mcuxClSession_Channel_t channel, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, DLAST_SGA, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_CITER_ELINK (Current major loop Iteration count with linking) register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 * @param value    Value to write to the SFR
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeCurrentMajorLoopCountElink)
static inline void mcuxClDma_Sfr_writeCurrentMajorLoopCountElink(mcuxClSession_Channel_t channel, uint16_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, CITER_ELINKYES, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}


/**
 * @brief Write the TCDn_BITER_ELINK (Beginning major loop Iteration count with linking) register of a DMA channel TCD.
 *
 * @param channel  DMA channel
 * @param value    Value to write to the SFR
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_writeBeginningMajorLoopCountElink)
static inline void mcuxClDma_Sfr_writeBeginningMajorLoopCountElink(mcuxClSession_Channel_t channel, uint16_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_TCD_SFR_WRITE(channel, BITER_ELINKYES, value);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @brief Enable hardware requests for the given DMA channel
 *
 * @param channel  DMA channel
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_enableHardwareRequest)
static inline void mcuxClDma_Sfr_enableHardwareRequest(mcuxClSession_Channel_t channel)
{
  MCUXCLDMA_SFR_CH_CSR_ENABLE_FIELD(channel, ERQ);
}

/**
 * @brief Set the hardware request source select of the given DMA channel
 *
 * @param channel  DMA channel
 * @param src      Source for the given DMA channel. Can be any of
 *                 #DMA_REQ_SRC_SGI_IN
 *                 #DMA_REQ_SRC_SGI_OUT
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_Sfr_setSrcSelect)
static inline void mcuxClDma_Sfr_setSrcSelect(mcuxClSession_Channel_t channel, uint32_t src)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  MCUXCLDMA_CH_SFR32_BITFIELD_WRITE(channel, MUX, SRC, src);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
}

/**
 * @}
 */ /* mcuxClDma_Sfr_Functions */

/**
 * @}
 */ /* mcuxClDma_Sfr */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLDMA_SFR_H_ */
