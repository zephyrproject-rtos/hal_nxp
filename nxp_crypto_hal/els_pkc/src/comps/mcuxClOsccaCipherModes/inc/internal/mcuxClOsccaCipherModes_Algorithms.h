/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

/** @file  mcuxClOsccaCipherModes_Algorithms.h
 *  @brief Supported algorithms for the mcuxClOsccaCipherModes component
 */

#ifndef MCUXCLOSCCACIPHERMODES_ALGORITHMS_H_
#define MCUXCLOSCCACIPHERMODES_ALGORITHMS_H_

#include <internal/mcuxClOsccaCipherModes_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClOsccaCipherModes_Algorithms Cipher algorithm definitions
 * @brief Modes used by the Cipher operations.
 * @ingroup mcuxClOsccaCipherModes
 * @{
 */
#ifdef MCUXCL_FEATURE_CIPHERMODES_SM4

/**
 * @brief SM4 ECB Encryption algorithm descriptor without padding, using OSCCA SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_NoPadding;

/**
 * @brief SM4 ECB Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 1, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingISO9797_1_Method1;

/**
 * @brief SM4 ECB Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 2, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingISO9797_1_Method2;

/**
 * @brief SM4 ECB Encryption algorithm descriptor with PKCS7 padding method, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingPKCS7;

/**
 * @brief SM4 ECB Decryption algorithm descriptor, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Dec;

/**
 * @brief SM4 CBC Encryption algorithm descriptor without padding, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_NoPadding;

/**
 * @brief SM4 CBC Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 1, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingISO9797_1_Method1;

/**
 * @brief SM4 CBC Encryption algorithm descriptor with ISO/IEC 9797-1 padding method 2, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingISO9797_1_Method2;

/**
 * @brief SM4 CBC Encryption algorithm descriptor with PKCS7 padding method, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingPKCS7;

/**
 * @brief SM4 CBC Decryption algorithm descriptor, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Dec;

/**
 * @brief SM4 CTR Encryption algorithm descriptor without padding, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CTR_Enc;

/**
 * @brief SM4 CTR Decryption algorithm descriptor, using SM4
 */
extern const mcuxClCipherModes_AlgorithmDescriptor_SM4_t mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CTR_Dec;


#endif /* MCUXCL_FEATURE_CIPHERMODES_SM4 */
/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCACIPHERMODES_ALGORITHMS_H_ */
