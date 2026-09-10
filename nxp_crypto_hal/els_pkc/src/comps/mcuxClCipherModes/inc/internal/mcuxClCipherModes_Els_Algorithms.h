/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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

/** @file  mcuxClCipherModes_Els_Algorithms.h
 *  @brief Supported algorithms for the mcuxClCipherModes component
 */

#ifndef MCUXCLCIPHERMODES_ELS_ALGORITHMS_H_
#define MCUXCLCIPHERMODES_ELS_ALGORITHMS_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <internal/mcuxClCipherModes_Els_Types.h>

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
 * @brief AES ECB Encryption algorithm descriptor without padding, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_NoPadding_Els;

/**
 * @brief AES ECB Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 1, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method1_Els;

/**
 * @brief AES ECB Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 2, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method2_Els;


/**
 * @brief AES ECB Encryption algorithm descriptor with PKCS7 padding, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_PaddingPKCS7_Els;


/**
 * @brief AES ECB Decryption algorithm descriptor, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Dec_Els;


/**
 * @brief AES CBC Encryption algorithm descriptor without padding, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_NoPadding_Els;

/**
 * @brief AES CBC Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 1, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method1_Els;

/**
 * @brief AES CBC Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 2, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method2_Els;


/**
 * @brief AES CBC Encryption algorithm descriptor with PKCS7 padding, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_PaddingPKCS7_Els;


/**
 * @brief AES CBC Decryption algorithm descriptor, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Dec_Els;


/**
 * @brief CTR Encryption/Decryption algorithm descriptor, using ELS
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t mcuxClCipherModes_AlgorithmDescriptor_AES_CTR_Els;


/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHERMODES_ELS_ALGORITHMS_H_ */
