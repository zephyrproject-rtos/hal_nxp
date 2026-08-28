/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

/** @file  mcuxClHashModes_Algorithms.h
 *  @brief Algorithm/mode definitions for the mcuxClHashModes component
 */

#ifndef MCUXCLHASHMODES_ALGORITHMS_H_
#define MCUXCLHASHMODES_ALGORITHMS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClHash_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup mcuxClHashModes_Algorithms mcuxClHashModes_Algorithms
* @brief Hashing algorithms of the @ref mcuxClHashModes component
* @ingroup mcuxClHashModes
* @{
*/

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()









/**
 * @brief Sha-224 algorithm descriptor
 *        Sha-224 hash calculation using the Hash functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha224;

/**
 * @brief Sha-224 algorithm descriptor
 *        Sha-224 hash calculation using the Hash functionality SGI.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten.
 * \implements{REQ_788287}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha224 = &mcuxClHash_AlgorithmDescriptor_Sgi_Sha224;

/**
 * @brief Sha-224 algorithm descriptor
 *        Sha-224 hash calculation using the Hash non-blocking functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha224_Dma_NonBlocking;

/**
 * @brief Sha-224 algorithm descriptor
 *        Sha-224 hash calculation using the Hash non-blocking functionality SGI.
 * @note Interrupts must be enabled on the DMA input channel with a properly installed handler.
 * If the non-blocking Hash operation returns @ref MCUXCLHASH_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten.
 *
 * \implements{REQ_1550262}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha224_Dma_NonBlocking = &mcuxClHash_AlgorithmDescriptor_Sgi_Sha224_Dma_NonBlocking;


/**
 * @brief Sha-256 algorithm descriptor
 *        Sha-256 hash calculation using the Hash functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha256;

/**
 * @brief Sha-256 algorithm descriptor
 *        Sha-256 hash calculation using the Hash functionality SGI.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten
 * \implements{REQ_788287}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha256 = &mcuxClHash_AlgorithmDescriptor_Sgi_Sha256;
/**
 * @brief Sha-256 algorithm descriptor
 *        Sha-256 hash calculation using the Hash non-blocking functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha256_Dma_NonBlocking;

/**
 * @brief Sha-256 algorithm descriptor
 *        Sha-256 hash calculation using the Hash non-blocking functionality SGI.
 * @note Interrupts must be enabled on the DMA input channel with a properly installed handler.
 * If the non-blocking Hash operation returns @ref MCUXCLHASH_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten
 *
 * \implements{REQ_1550262}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha256_Dma_NonBlocking = &mcuxClHash_AlgorithmDescriptor_Sgi_Sha256_Dma_NonBlocking;

/**
 * @brief Sha-384 algorithm descriptor
 *        Sha-384 hash calculation using the Hash functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha384;

/**
 * @brief Sha-384 algorithm descriptor
 *        Sha-384 hash calculation using the Hash functionality SGI.
 * @note Interrupts must be enabled on the DMA input channel with a properly installed handler.
 * If the non-blocking Hash operation returns @ref MCUXCLHASH_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten
 *
 * \implements{REQ_788288}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha384 = &mcuxClHash_AlgorithmDescriptor_Sgi_Sha384;
/**
 * @brief Sha-384 algorithm descriptor
 *        Sha-384 hash calculation using the Hash non-blocking functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha384_Dma_NonBlocking;

/**
 * @brief Sha-384 algorithm descriptor
 *        Sha-384 hash calculation using the Hash non-blocking functionality SGI.
 * @note Interrupts must be enabled on the DMA input channel with a properly installed handler.
 * If the non-blocking Hash operation returns @ref MCUXCLHASH_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten
 *
 * \implements{REQ_1550264}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha384_Dma_NonBlocking = &mcuxClHash_AlgorithmDescriptor_Sgi_Sha384_Dma_NonBlocking;

/**
 * @brief Sha-512 algorithm descriptor
 *        Sha-512 hash calculation using the Hash functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha512;

/**
 * @brief Sha-512 algorithm descriptor
 *        Sha-512 hash calculation using the Hash functionality SGI.
 * @note Interrupts must be enabled on the DMA input channel with a properly installed handler.
 * If the non-blocking Hash operation returns @ref MCUXCLHASH_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten
 *
 * \implements{REQ_788288}
 */
#define mcuxClHash_Algorithm_Sha512 (&mcuxClHash_AlgorithmDescriptor_Sgi_Sha512)
/**
 * @brief Sha-512 algorithm descriptor
 *        Sha-512 hash calculation using the Hash non-blocking functionality SGI.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sgi_Sha512_Dma_NonBlocking;

/**
 * @brief Sha-512 algorithm descriptor
 *        Sha-512 hash calculation using the Hash non-blocking functionality SGI.
 * @note Interrupts must be enabled on the DMA input channel with a properly installed handler.
 * If the non-blocking Hash operation returns @ref MCUXCLHASH_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 * @attention This mode uses the SGI_SHA_FIFO which overwrites the contents of key registers SGI KEY0-KEY3.
 *            Any preloaded key data in these slots will potentially be overwritten
 *
 * \implements{REQ_1550264}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha512_Dma_NonBlocking = &mcuxClHash_AlgorithmDescriptor_Sgi_Sha512_Dma_NonBlocking;




#ifdef MCUXCL_FEATURE_HASH_C_SHA3
/**
 * @brief Sha3-224 algorithm descriptor
 *        Sha3-224 hash calculation using an underlying software implementation of Keccak.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_C_Sha3_224;

/**
 * @brief Sha3-224 algorithm descriptor
 *        Sha3-224 hash calculation using an underlying software implementation of Keccak.
 * \implements{REQ_788290}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha3_224 = &mcuxClHash_AlgorithmDescriptor_C_Sha3_224;

/**
 * @brief Sha3-256 algorithm descriptor
 *        Sha3-256 hash calculation using an underlying software implementation of Keccak.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_C_Sha3_256;

/**
 * @brief Sha3-256 algorithm descriptor
 *        Sha3-256 hash calculation using an underlying software implementation of Keccak.
 * \implements{REQ_788290}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha3_256 = &mcuxClHash_AlgorithmDescriptor_C_Sha3_256;

/**
 * @brief Sha3-384 algorithm descriptor
 *        Sha3-384 hash calculation using an underlying software implementation of Keccak.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_C_Sha3_384;

/**
 * @brief Sha3-384 algorithm descriptor
 *        Sha3-384 hash calculation using an underlying software implementation of Keccak.
 * \implements{REQ_788290}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha3_384 = &mcuxClHash_AlgorithmDescriptor_C_Sha3_384;

/**
 * @brief Sha3-512 algorithm descriptor
 *        Sha3-512 hash calculation using an underlying software implementation of Keccak.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_C_Sha3_512;

/**
 * @brief Sha3-512 algorithm descriptor
 *        Sha3-512 hash calculation using an underlying software implementation of Keccak.
 * \implements{REQ_788290}
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha3_512 = &mcuxClHash_AlgorithmDescriptor_C_Sha3_512;
#endif /* MCUXCL_FEATURE_HASH_C_SHA3 */











MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**@}*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_ALGORITHMS_H_ */
