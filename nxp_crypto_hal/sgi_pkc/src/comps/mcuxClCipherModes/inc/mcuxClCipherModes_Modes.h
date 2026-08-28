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

/** @file  mcuxClCipherModes_Modes.h
 *  @brief Supported modes for the mcuxClCipher component
 */

#ifndef MCUXCLCIPHERMODES_MODES_H_
#define MCUXCLCIPHERMODES_MODES_H_

#include <mcuxClCipher_Types.h>

#include <mcuxCsslAnalysis.h>

#include <mcuxClConfig.h> // Exported features flags header

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClCipherModes_Modes mcuxClCipherModes_Modes
 * @brief Modes used by the Cipher operations.
 * @ingroup mcuxClCipherModes
 * @{
 */

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")

/**
 * @brief AES-ECB mode descriptor without padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding;

/**
 * @brief AES-ECB mode without padding.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding.
 * @implements{REQ_788210,REQ_788217}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_NoPadding =
  &mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding;

/**
 * @brief AES-ECB mode descriptor with ISO/IEC 9797-1 padding method 1
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1;

/**
 * @brief AES-ECB mode with ISO/IEC 9797-1 padding method 1.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1.
 *
 * @implements{REQ_788210,REQ_788217,REQ_788211}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_PaddingISO9797_1_Method1 =
  &mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1;

/**
 * @brief AES-ECB mode descriptor with ISO/IEC 9797-1 padding method 2
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2;

/**
 * @brief AES-ECB mode with ISO/IEC 9797-1 padding method 2.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2.
 *
 * @implements{REQ_788210,REQ_788217,REQ_788212}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_PaddingISO9797_1_Method2 =
  &mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2;

/**
 * @brief AES-ECB mode descriptor with PKCS#7 padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7;

/**
 * @brief AES-ECB mode with PKCS#7 padding.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7.
 *
 * @implements{REQ_788210,REQ_788217,REQ_788213}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_PaddingPKCS7 =
  &mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7;

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @brief AES-ECB mode descriptor without padding, non-blocking API, using the DMA for I/O operations.
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding_NonBlocking;

/**
 * @brief AES-ECB mode without padding, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550251}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_NoPadding_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding_NonBlocking;

/**
 * @brief AES-ECB mode descriptor with ISO/IEC 9797-1 padding method 1, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1_NonBlocking;

/**
 * @brief AES-ECB mode with ISO/IEC 9797-1 padding method 1, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550251,REQ_788211}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_PaddingISO9797_1_Method1_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1_NonBlocking;

/**
 * @brief AES-ECB mode descriptor with ISO/IEC 9797-1 padding method 2, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2_NonBlocking;

/**
 * @brief AES-ECB mode with ISO/IEC 9797-1 padding method 2, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550251,REQ_788212}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_PaddingISO9797_1_Method2_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2_NonBlocking;

/**
 * @brief AES-ECB mode descriptor with PKCS#7 padding, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7_NonBlocking;

/**
 * @brief AES-ECB mode with PKCS#7 padding, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550251,REQ_788213}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_PaddingPKCS7_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7_NonBlocking;

#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */
/**
 * @brief AES-CBC mode descriptor without padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding;

/**
 * @brief AES-CBC mode without padding.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding.
 *
 * @implements{REQ_788210,REQ_788219}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_NoPadding =
  &mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding;

/**
 * @brief AES-CBC mode descriptor with ISO/IEC 9797-1 padding method 1
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1;

/**
 * @brief AES-CBC mode with ISO/IEC 9797-1 padding method 1.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1.
 *
 * @implements{REQ_788210,REQ_788219,REQ_788211}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_PaddingISO9797_1_Method1 =
  &mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1;

/**
 * @brief AES-CBC mode descriptor with ISO/IEC 9797-1 padding method 2
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2;

/**
 * @brief AES-CBC mode with ISO/IEC 9797-1 padding method 2.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2.
 *
 * @implements{REQ_788210,REQ_788219,REQ_788212}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_PaddingISO9797_1_Method2 =
  &mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2;

/**
 * @brief AES-CBC mode descriptor with PKCS#7 padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7;

/**
 * @brief AES-CBC mode with PKCS#7 padding.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7.
 *
 * @implements{REQ_788210,REQ_788219,REQ_788213}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_PaddingPKCS7 =
  &mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7;

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @brief AES-CBC mode descriptor without padding, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding_NonBlocking;

/**
 * @brief AES-CBC mode without padding, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550252}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_NoPadding_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding_NonBlocking;

/**
 * @brief AES-CBC mode descriptor with ISO/IEC 9797-1 padding method 1, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1_NonBlocking;

/**
 * @brief AES-CBC mode with ISO/IEC 9797-1 padding method 1, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550252,REQ_788211}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_PaddingISO9797_1_Method1_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1_NonBlocking;

/**
 * @brief AES-CBC mode descriptor with ISO/IEC 9797-1 padding method 2, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2_NonBlocking;

/**
 * @brief AES-CBC mode with ISO/IEC 9797-1 padding method 2, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550252,REQ_788212}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_PaddingISO9797_1_Method2_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2_NonBlocking;

/**
 * @brief AES-CBC mode descriptor with PKCS#7 padding, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7_NonBlocking;

/**
 * @brief AES-CBC mode with PKCS#7 padding, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550252,REQ_788213}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_PaddingPKCS7_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7_NonBlocking;

#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */
/**
 * @brief AES-CTR mode descriptor
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CTR;

/**
 * @brief AES-CTR mode.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CTR.
 *
 * @implements{REQ_788210,REQ_788223}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CTR =
  &mcuxClCipher_ModeDescriptor_AES_CTR;

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @brief AES-CTR mode descriptor, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on both involved DMA channels with properly installed handlers.
 * If the non-blocking Cipher operation returns @ref MCUXCLCIPHER_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CTR_NonBlocking;

/**
 * @brief AES-CTR mode, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClCipher_ModeDescriptor_AES_CTR_NonBlocking.
 *
 * @implements{REQ_788210,REQ_1550253}
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CTR_NonBlocking =
  &mcuxClCipher_ModeDescriptor_AES_CTR_NonBlocking;

#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */



MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHERMODES_MODES_H_ */

