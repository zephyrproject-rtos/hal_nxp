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

/*
 * Crypt Modes using the ELS
 */
/**
 * @brief AES ECB Encryption mode descriptor without padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_NoPadding;

/**
 * @brief AES ECB Encryption mode without padding
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_Enc_NoPadding =
  &mcuxClCipher_ModeDescriptor_AES_ECB_Enc_NoPadding;

/**
 * @brief AES ECB Encryption mode descriptor with ISO/IEC 9797-1 padding method 1
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method1;

/**
 * @brief AES ECB Encryption mode with ISO/IEC 9797-1 padding method 1
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_Enc_PaddingISO9797_1_Method1 =
  &mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method1;

/**
 * @brief AES ECB Encryption mode descriptor with ISO/IEC 9797-1 padding method 2
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method2;

/**
 * @brief AES ECB Encryption mode with ISO/IEC 9797-1 padding method 2
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_Enc_PaddingISO9797_1_Method2 =
  &mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method2;

/**
 * @brief AES ECB Encryption mode descriptor with PKCS7 padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingPKCS7;

/**
 * @brief AES ECB Encryption mode with PKCS7 padding
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_Enc_PaddingPKCS7 =
  &mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingPKCS7;

/**
 * @brief AES ECB Decryption mode descriptor
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Dec;

/**
 * @brief AES ECB Decryption mode
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_ECB_Dec_NoPadding =
  &mcuxClCipher_ModeDescriptor_AES_ECB_Dec;

/**
 * @brief AES CBC Encryption mode descriptor without padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_NoPadding;

/**
 * @brief AES CBC Encryption mode without padding
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_Enc_NoPadding =
  &mcuxClCipher_ModeDescriptor_AES_CBC_Enc_NoPadding;

/**
 * @brief AES CBC Encryption mode descriptor with ISO/IEC 9797-1 padding method 1
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method1;

/**
 * @brief AES CBC Encryption mode with ISO/IEC 9797-1 padding method 1
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_Enc_PaddingISO9797_1_Method1 =
  &mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method1;

/**
 * @brief AES CBC Encryption mode descriptor with ISO/IEC 9797-1 padding method 2
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method2;

/**
 * @brief AES CBC Encryption mode with ISO/IEC 9797-1 padding method 2
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_Enc_PaddingISO9797_1_Method2 =
  &mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method2;

/**
 * @brief AES CBC Encryption mode descriptor with PKCS7 padding
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingPKCS7;

/**
 * @brief AES CBC Encryption mode with PKCS7 padding
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_Enc_PKCS7 =
  &mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingPKCS7;

/**
 * @brief AES CBC Decryption mode descriptor
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Dec;

/**
 * @brief AES CBC Decryption mode
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CBC_Dec_NoPadding =
  &mcuxClCipher_ModeDescriptor_AES_CBC_Dec;

/**
 * @brief CTR Encryption/Decryption mode descriptor
 */
extern const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CTR;

/**
 * @brief CTR Encryption/Decryption mode
 */
static mcuxClCipher_Mode_t mcuxClCipher_Mode_AES_CTR =
  &mcuxClCipher_ModeDescriptor_AES_CTR;



MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHERMODES_MODES_H_ */

