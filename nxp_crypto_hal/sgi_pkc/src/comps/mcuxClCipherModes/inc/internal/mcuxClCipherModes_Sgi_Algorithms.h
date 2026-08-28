/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

/** @file  mcuxClCipherModes_Sgi_Algorithms.h
 *  @brief Supported algorithms for the mcuxClCipherModes component
 */

#ifndef MCUXCLCIPHERMODES_SGI_ALGORITHMS_H_
#define MCUXCLCIPHERMODES_SGI_ALGORITHMS_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <internal/mcuxClCipherModes_Sgi_Types.h>
#include <internal/mcuxClCipherModes_Common_Constants.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup clCipherModesAlgorithms Cipher algorithm definitions
 * @brief Modes used by the Cipher operations.
 * @ingroup mcuxClCipherModes
 * @{
 */

/**
 * @brief ECB algorithm descriptor without padding, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_NoPadding_Sgi;

/**
 * @brief ECB algorithm descriptor with ISO/IEC 9797-1 padding method 1, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method1_Sgi;

/**
 * @brief ECB algorithm descriptor with ISO/IEC 9797-1 padding method 2, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method2_Sgi;

/**
 * @brief ECB algorithm descriptor with PKCS#7 padding, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingPKCS7_Sgi;


#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @brief Blocking ECB algorithm descriptor for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_NoPadding_Sgi_NonBlocking;

/**
 * @brief Blocking ECB algorithm descriptor with ISO/IEC 9797-1 padding method 1 for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method1_Sgi_NonBlocking;

/**
 * @brief Blocking ECB algorithm descriptor with ISO/IEC 9797-1 padding method 2 for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method2_Sgi_NonBlocking;

/**
 * @brief Blocking ECB algorithm descriptor with PKCS#7 padding for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingPKCS7_Sgi_NonBlocking;

#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/**
 * @brief CBC algorithm descriptor without padding, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_NoPadding_Sgi;

/**
 * @brief CBC algorithm descriptor with ISO/IEC 9797-1 padding method 1, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method1_Sgi;

/**
 * @brief CBC algorithm descriptor with ISO/IEC 9797-1 padding method 2, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method2_Sgi;

/**
 * @brief CBC algorithm descriptor with PKCS#7 padding, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingPKCS7_Sgi;


#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @brief Non blocking CBC algorithm descriptor for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_NoPadding_Sgi_NonBlocking;

/**
 * @brief Non blocking CBC algorithm descriptor with ISO/IEC 9797-1 padding method 1 for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method1_Sgi_NonBlocking;

/**
 * @brief Non blocking CBC algorithm descriptor with ISO/IEC 9797-1 padding method 2 for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method2_Sgi_NonBlocking;

/**
 * @brief Non blocking CBC algorithm descriptor with PKCS#7 padding for non-blocking operations, using SGI, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingPKCS7_Sgi_NonBlocking;

#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/**
 * @brief CTR algorithm descriptor, using SGI
 *
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CTR_Sgi;

#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
/**
 * @brief CTR algorithm descriptor, using SGI, for non-blocking operations, performing I/O operations with the DMA
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CTR_Sgi_NonBlocking;

#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */





/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHERMODES_SGI_ALGORITHMS_H_ */
