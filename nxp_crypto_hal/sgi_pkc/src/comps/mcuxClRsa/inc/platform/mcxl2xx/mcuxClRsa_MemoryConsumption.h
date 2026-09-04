/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024, 2026 NXP                                            */
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
 * @file  mcuxClRsa_MemoryConsumption.h
 * @brief Defines the memory consumption for the mcuxClRsa component
 */

#ifndef MCUXCLRSA_MEMORYCONSUMPTION_H_
#define MCUXCLRSA_MEMORYCONSUMPTION_H_

#define MCUXCLRSA_SIGNATURE_PROTOCOLDESCRIPTOR_SIZE     (52u)
#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#define MCUXCLRSA_CIPHER_MODE_SIZE       (28u)
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

/**
 * @defgroup MCUXCLRSA_KEYGEN_MODE_SIZE MCUXCLRSA_KEYGEN_MODE_SIZE
 * @brief Definitions of RSA key generation mode descriptor sizes for the @ref mcuxClRsa_KeyGeneration_ModeConstructor function.
 * @ingroup mcuxClRsa_KeyGeneration_ModeDescriptor
 * @{
 */
#define MCUXCLRSA_KEYGEN_MODE_SIZE       (20u) ///< Definitions of RSA key generation mode descriptor size for the @ref mcuxClRsa_KeyGeneration_ModeConstructor function.
/** @} */

#ifdef MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT
/****************************************************************************/
/* Definitions of workarea sizes for the RSA encryption.                    */
/****************************************************************************/

/**
 * @defgroup MCUXCLRSA_ENCRYPT_WA MCUXCLRSA_ENCRYPT_WA
 * @brief Definitions of workarea sizes for the RSA encryption.
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_ENCRYPT_1024_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_encrypt function for 1024-bit keys.
#define MCUXCLRSA_ENCRYPT_2048_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_encrypt function for 2048-bit keys.
#define MCUXCLRSA_ENCRYPT_3072_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_encrypt function for 3072-bit keys.
#define MCUXCLRSA_ENCRYPT_4096_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_encrypt function for 4096-bit keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_ENCRYPT_6144_WACPU_SIZE    ($(mcuxClRsa_Util_Encrypt_6144_WaCPU)u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_encrypt function for 6144-bit keys.
#define MCUXCLRSA_ENCRYPT_8192_WACPU_SIZE    ($(mcuxClRsa_Util_Encrypt_8192_WaCPU)u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_encrypt function for 8192-bit keys.

#define MCUXCLRSA_ENCRYPT_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_2048_WACPU_SIZE : \
                                MCUXCLRSA_ENCRYPT_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size to be used with a non-standard key length.
#else
#define MCUXCLRSA_ENCRYPT_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_2048_WACPU_SIZE : \
                                MCUXCLRSA_ENCRYPT_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_ENCRYPT_1024_WAPKC_SIZE     (856u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_encrypt function for 1024-bit keys.
#define MCUXCLRSA_ENCRYPT_2048_WAPKC_SIZE     (1624u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_encrypt function for 2048-bit keys.
#define MCUXCLRSA_ENCRYPT_3072_WAPKC_SIZE     (2392u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_encrypt function for 3072-bit keys.
#define MCUXCLRSA_ENCRYPT_4096_WAPKC_SIZE     (3160u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_encrypt function for 4096-bit keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_ENCRYPT_6144_WAPKC_SIZE     ($(mcuxClRsa_Util_Encrypt_6144_WaPKC)u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_encrypt function for 6144-bit keys.
#define MCUXCLRSA_ENCRYPT_8192_WAPKC_SIZE     ($(mcuxClRsa_Util_Encrypt_8192_WaPKC)u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_encrypt function for 8192-bit keys.

#define MCUXCLRSA_ENCRYPT_WAPKC_SIZE(keyBitLength) \
        ((6144U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_8192_WAPKC_SIZE : \
        ((4096U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_6144_WAPKC_SIZE : \
        ((3072U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_4096_WAPKC_SIZE : \
        ((2048U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_3072_WAPKC_SIZE : \
        ((1024U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_2048_WAPKC_SIZE : \
                                    MCUXCLRSA_ENCRYPT_1024_WAPKC_SIZE)))))  ///< Macro to extract PKC workarea size to be used with a non-standard key length.
#else
#define MCUXCLRSA_ENCRYPT_WAPKC_SIZE(keyBitLength) \
        ((3072U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_4096_WAPKC_SIZE : \
        ((2048U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_3072_WAPKC_SIZE : \
        ((1024U < (keyBitLength)) ? MCUXCLRSA_ENCRYPT_2048_WAPKC_SIZE : \
                                    MCUXCLRSA_ENCRYPT_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/** @} */
#endif /* MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT */
#ifdef MCUXCL_FEATURE_CIPHER_RSA_DECRYPT
/****************************************************************************/
/* Definitions of workarea sizes for the RSA decryption.                    */
/****************************************************************************/

/**
 * @defgroup MCUXCLRSA_DECRYPT_WA MCUXCLRSA_DECRYPT_WA
 * @brief Definitions of workarea sizes for the RSA decryption.
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_DECRYPT_1024_WACPU_SIZE    (392u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_decrypt function for 1024-bit keys.
#define MCUXCLRSA_DECRYPT_2048_WACPU_SIZE    (520u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_decrypt function for 2048-bit keys.
#define MCUXCLRSA_DECRYPT_3072_WACPU_SIZE    (648u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_decrypt function for 3072-bit keys.
#define MCUXCLRSA_DECRYPT_4096_WACPU_SIZE    (776u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_decrypt function for 4096-bit keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_DECRYPT_6144_WACPU_SIZE    ($(mcuxClRsa_Util_Decrypt_6144_WaCPU)u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_decrypt function for 6144-bit keys.
#define MCUXCLRSA_DECRYPT_8192_WACPU_SIZE    ($(mcuxClRsa_Util_Decrypt_8192_WaCPU)u) ///< Definition of CPU workarea size for the mcuxClRsa_Util_decrypt function for 8192-bit keys.

#define MCUXCLRSA_DECRYPT_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_2048_WACPU_SIZE : \
                                MCUXCLRSA_DECRYPT_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size to be used with a non-standard key length.
#else
#define MCUXCLRSA_DECRYPT_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_2048_WACPU_SIZE : \
                                MCUXCLRSA_DECRYPT_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_DECRYPT_1024_WAPKC_SIZE     (1344u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_decrypt function for 1024-bit keys.
#define MCUXCLRSA_DECRYPT_2048_WAPKC_SIZE     (2496u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_decrypt function for 2048-bit keys.
#define MCUXCLRSA_DECRYPT_3072_WAPKC_SIZE     (3648u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_decrypt function for 3072-bit keys.
#define MCUXCLRSA_DECRYPT_4096_WAPKC_SIZE     (4800u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_decrypt function for 4096-bit keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_DECRYPT_6144_WAPKC_SIZE     ($(mcuxClRsa_Util_Decrypt_6144_WaPKC)u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_decrypt function for 6144-bit keys.
#define MCUXCLRSA_DECRYPT_8192_WAPKC_SIZE     ($(mcuxClRsa_Util_Decrypt_8192_WaPKC)u) ///< Definition of PKC workarea size for the mcuxClRsa_Util_decrypt function for 8192-bit keys.

#define MCUXCLRSA_DECRYPT_WAPKC_SIZE(keyBitLength) \
        ((6144U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_8192_WAPKC_SIZE : \
        ((4096U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_6144_WAPKC_SIZE : \
        ((3072U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_4096_WAPKC_SIZE : \
        ((2048U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_3072_WAPKC_SIZE : \
        ((1024U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_2048_WAPKC_SIZE : \
                                    MCUXCLRSA_DECRYPT_1024_WAPKC_SIZE)))))  ///< Macro to extract PKC workarea size to be used with a non-standard key length.
#else
#define MCUXCLRSA_DECRYPT_WAPKC_SIZE(keyBitLength) \
        ((3072U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_4096_WAPKC_SIZE : \
        ((2048U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_3072_WAPKC_SIZE : \
        ((1024U < (keyBitLength)) ? MCUXCLRSA_DECRYPT_2048_WAPKC_SIZE : \
                                    MCUXCLRSA_DECRYPT_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/** @} */
#endif /* MCUXCL_FEATURE_CIPHER_RSA_DECRYPT */
/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa Sign                      */
/****************************************************************************/

/**
 * @defgroup MCUXCLRSA_SIGN_WA MCUXCLRSA_SIGN_WA
 * @brief Definitions of workarea sizes for the mcuxClRsa Sign
 * @ingroup mcuxClRsa_Macros
 * @{
 */


#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_1024_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function for 1024-bit private plain keys using PSS encoding.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_2048_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function for 2048-bit private plain keys using PSS encoding.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_3072_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function for 3072-bit private plain keys using PSS encoding.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_4096_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function for 4096-bit private plain keys using PSS encoding.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_6144_WACPU_SIZE    ($(mcuxClRsa_Sign_Plain_PssEncode_6144_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function for 6144-bit private plain keys using PSS encoding.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_8192_WACPU_SIZE    ($(mcuxClRsa_Sign_Plain_PssEncode_8192_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function for 8192-bit private plain keys using PSS encoding.

#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_PLAIN_PSSENCODE_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private plain key.
#else
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_PLAIN_PSSENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private plain key.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_1024_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function for 1024-bit private plain keys using PKCS#1v1.5 encoding.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_2048_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function for 2048-bit private plain keys using PKCS#1v1.5 encoding.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_3072_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function for 3072-bit private plain keys using PKCS#1v1.5 encoding.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_4096_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function for 4096-bit private plain keys using PKCS#1v1.5 encoding.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_6144_WACPU_SIZE    ($(mcuxClRsa_Sign_Plain_Pkcs1v15Encode_6144_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function for 6144-bit private plain keys using PKCS#1v1.5 encoding.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_8192_WACPU_SIZE    ($(mcuxClRsa_Sign_Plain_Pkcs1v15Encode_8192_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function for 8192-bit private plain keys using PKCS#1v1.5 encoding.

#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private plain key.
#else
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private plain key.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_SIGN_PLAIN_1024_WAPKC_SIZE     (1344u) ///< Definition of PKC workarea size for the RSA Sign function for 1024-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_2048_WAPKC_SIZE     (2496u) ///< Definition of PKC workarea size for the RSA Sign function for 2048-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_3072_WAPKC_SIZE     (3648u) ///< Definition of PKC workarea size for the RSA Sign function for 3072-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_4096_WAPKC_SIZE     (4800u) ///< Definition of PKC workarea size for the RSA Sign function for 4096-bit private plain keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_SIGN_PLAIN_6144_WAPKC_SIZE     ($(mcuxClRsa_Sign_Plain_6144_WaPKC)u) ///< Definition of PKC workarea size for the RSA Sign function for 6144-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_8192_WAPKC_SIZE     ($(mcuxClRsa_Sign_Plain_8192_WaPKC)u) ///< Definition of PKC workarea size for the RSA Sign function for 8192-bit private plain keys.

#define MCUXCLRSA_SIGN_PLAIN_WAPKC_SIZE(keyBitLength) \
        ((6144U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_8192_WAPKC_SIZE : \
        ((4096U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_6144_WAPKC_SIZE : \
        ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_4096_WAPKC_SIZE : \
        ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_3072_WAPKC_SIZE : \
        ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_2048_WAPKC_SIZE : \
                                    MCUXCLRSA_SIGN_PLAIN_1024_WAPKC_SIZE)))))  ///< Macro to extract PKC workarea size to be used with a non-standard key length, with a private plain key.
#else
#define MCUXCLRSA_SIGN_PLAIN_WAPKC_SIZE(keyBitLength) \
        ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_4096_WAPKC_SIZE : \
        ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_3072_WAPKC_SIZE : \
        ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_2048_WAPKC_SIZE : \
                                    MCUXCLRSA_SIGN_PLAIN_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length, with a private plain key.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */


#define MCUXCLRSA_SIGN_CRT_PSSENCODE_1024_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function using PSS encoding for 1024-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_2048_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function using PSS encoding for 2048-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_3072_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function using PSS encoding for 3072-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_4096_WACPU_SIZE    (264u) ///< Definition of CPU workarea size for the RSA Sign function using PSS encoding for 4096-bit private CRT keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_6144_WACPU_SIZE    ($(mcuxClRsa_Sign_CRT_PssEncode_6144_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function using PSS encoding for 6144-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_8192_WACPU_SIZE    ($(mcuxClRsa_Sign_CRT_PssEncode_8192_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function using PSS encoding for 8192-bit private CRT keys.

#define MCUXCLRSA_SIGN_CRT_PSSENCODE_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_CRT_PSSENCODE_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private CRT key.
#else
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_CRT_PSSENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private CRT key.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_1024_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function using PKCS#1v1.5 encoding, for 1024-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_2048_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function using PKCS#1v1.5 encoding, for 2048-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_3072_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function using PKCS#1v1.5 encoding, for 3072-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_4096_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Sign function using PKCS#1v1.5 encoding, for 4096-bit private CRT keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_6144_WACPU_SIZE    ($(mcuxClRsa_Sign_CRT_Pkcs1v15Encode_6144_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function using PKCS#1v1.5 encoding, for 6144-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_8192_WACPU_SIZE    ($(mcuxClRsa_Sign_CRT_Pkcs1v15Encode_8192_WaCPU)u) ///< Definition of CPU workarea size for the RSA Sign function using PKCS#1v1.5 encoding, for 8192-bit private CRT keys.

#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private CRT key.
#else
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a private CRT key.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_SIGN_CRT_1024_WAPKC_SIZE     (1128u) ///< Definition of PKC workarea size for the RSA Sign function for 1024-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_2048_WAPKC_SIZE     (2152u) ///< Definition of PKC workarea size for the RSA Sign function for 2048-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_3072_WAPKC_SIZE     (3176u) ///< Definition of PKC workarea size for the RSA Sign function for 3072-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_4096_WAPKC_SIZE     (4200u) ///< Definition of PKC workarea size for the RSA Sign function for 4096-bit private CRT keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_SIGN_CRT_6144_WAPKC_SIZE     ($(mcuxClRsa_Sign_CRT_6144_WaPKC)u) ///< Definition of PKC workarea size for the RSA Sign function for 6144-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_8192_WAPKC_SIZE     ($(mcuxClRsa_Sign_CRT_8192_WaPKC)u) ///< Definition of PKC workarea size for the RSA Sign function for 8192-bit private CRT keys.

#define MCUXCLRSA_SIGN_CRT_WAPKC_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_8192_WAPKC_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_6144_WAPKC_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_2048_WAPKC_SIZE : \
                                MCUXCLRSA_SIGN_CRT_1024_WAPKC_SIZE)))))  ///< Macro to extract PKC workarea size to be used with a non-standard key length, with a private CRT key.
#else
#define MCUXCLRSA_SIGN_CRT_WAPKC_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_2048_WAPKC_SIZE : \
                                MCUXCLRSA_SIGN_CRT_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length, with a private CRT key.

#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa Verify                    */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_VERIFY_WA MCUXCLRSA_VERIFY_WA
 * @brief Definitions of workarea sizes for the mcuxClRsa Verify
 * @ingroup mcuxClRsa_Macros
 * @{
 */


#define MCUXCLRSA_VERIFY_PSSVERIFY_WACPU_SIZE         (264u) ///< Definition of CPU workarea size for the RSA Verify function using PSS encoding.
#define MCUXCLRSA_VERIFY_PKCS1V15VERIFY_WACPU_SIZE    (128u) ///< Definition of CPU workarea size for the RSA Verify function using PKCS#1v1.5 encoding.

#define MCUXCLRSA_VERIFY_1024_WAPKC_SIZE     (728u) ///< Definition of PKC workarea size for the RSA Verify function for 1024-bit keys.
#define MCUXCLRSA_VERIFY_2048_WAPKC_SIZE     (1368u) ///< Definition of PKC workarea size for the RSA Verify function for 2048-bit keys.
#define MCUXCLRSA_VERIFY_3072_WAPKC_SIZE     (2008u) ///< Definition of PKC workarea size for the RSA Verify function for 3072-bit keys.
#define MCUXCLRSA_VERIFY_4096_WAPKC_SIZE     (2648u) ///< Definition of PKC workarea size for the RSA Verify function for 4096-bit keys.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_VERIFY_6144_WAPKC_SIZE     ($(mcuxClRsa_Verify_6144_WaPKC)u) ///< Definition of PKC workarea size for the RSA Verify function for 6144-bit keys.
#define MCUXCLRSA_VERIFY_8192_WAPKC_SIZE     ($(mcuxClRsa_Verify_8192_WaPKC)u) ///< Definition of PKC workarea size for the RSA Verify function for 8192-bit keys.

#define MCUXCLRSA_VERIFY_WAPKC_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_VERIFY_8192_WAPKC_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_VERIFY_6144_WAPKC_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_VERIFY_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_VERIFY_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_VERIFY_2048_WAPKC_SIZE : \
                                MCUXCLRSA_VERIFY_1024_WAPKC_SIZE)))))  ///< Macro to extract PKC workarea size to be used with a non-standard key length.
#else
#define MCUXCLRSA_VERIFY_WAPKC_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_VERIFY_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_VERIFY_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_VERIFY_2048_WAPKC_SIZE : \
                                MCUXCLRSA_VERIFY_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */



/** @} */


/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa Key Generation            */
/****************************************************************************/

/**
 * @defgroup MCUXCLRSA_KEYGENERATION_CRT_WA MCUXCLRSA_KEYGENERATION_CRT_WA
 * @brief Definitions of workarea sizes for the mcuxClKey_generate_keypair function required to generate RSA key in CRT form.
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_KEYGENERATION_CRT_1024_WACPU_SIZE    (640u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 1024-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_2048_WACPU_SIZE    (768u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 2048-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_3072_WACPU_SIZE    (896u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 3072-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_4096_WACPU_SIZE    (1024u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 4096-bit RSA keys in CRT form
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_CRT_6144_WACPU_SIZE    ($(mcuxClRsa_KeyGeneration_Crt_6144_WaCPU)u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 6144-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_8192_WACPU_SIZE    ($(mcuxClRsa_KeyGeneration_Crt_8192_WaCPU)u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 8192-bit RSA keys in CRT form

#define MCUXCLRSA_KEYGENERATION_CRT_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_2048_WACPU_SIZE : \
                                MCUXCLRSA_KEYGENERATION_CRT_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size (in bytes) for the given key length.

#else
#define MCUXCLRSA_KEYGENERATION_CRT_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_2048_WACPU_SIZE : \
                                MCUXCLRSA_KEYGENERATION_CRT_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size (in bytes) for the given key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_KEYGENERATION_CRT_1024_WAPKC_SIZE    (1048u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 1024-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_2048_WAPKC_SIZE    (1896u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 2048-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_3072_WAPKC_SIZE    (2792u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 3072-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_4096_WAPKC_SIZE    (3688u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 4096-bit RSA keys in CRT form
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_CRT_6144_WAPKC_SIZE    ($(mcuxClRsa_KeyGeneration_Crt_6144_WaPKC)u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 6144-bit RSA keys in CRT form
#define MCUXCLRSA_KEYGENERATION_CRT_8192_WAPKC_SIZE    ($(mcuxClRsa_KeyGeneration_Crt_8192_WaPKC)u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 8192-bit RSA keys in CRT form

#define MCUXCLRSA_KEYGENERATION_CRT_WAPKC_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_8192_WAPKC_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_6144_WAPKC_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_2048_WAPKC_SIZE : \
                                MCUXCLRSA_KEYGENERATION_CRT_1024_WAPKC_SIZE)))))  ///< Macro to extract PKC workarea size (in bytes) for the given key length.
#else
#define MCUXCLRSA_KEYGENERATION_CRT_WAPKC_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_2048_WAPKC_SIZE : \
                                MCUXCLRSA_KEYGENERATION_CRT_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size (in bytes) for the given key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/** @} */

/**
 * @defgroup MCUXCLRSA_KEYGENERATION_PLAIN_WA MCUXCLRSA_KEYGENERATION_PLAIN_WA
 * @brief Definitions of workarea sizes for the mcuxClKey_generate_keypair function required to generate RSA key in plain form.
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_KEYGENERATION_PLAIN_1024_WACPU_SIZE    (592u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 1024-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_2048_WACPU_SIZE    (720u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 2048-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_3072_WACPU_SIZE    (848u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 3072-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_4096_WACPU_SIZE    (976u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 4096-bit RSA keys in plain form
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_PLAIN_6144_WACPU_SIZE    ($(mcuxClRsa_KeyGeneration_Plain_6144_WaCPU)u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 6144-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_8192_WACPU_SIZE    ($(mcuxClRsa_KeyGeneration_Plain_8192_WaCPU)u) ///< Definition of CPU workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 8192-bit RSA keys in plain form

#define MCUXCLRSA_KEYGENERATION_PLAIN_WACPU_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_8192_WACPU_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_6144_WACPU_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_2048_WACPU_SIZE : \
                                MCUXCLRSA_KEYGENERATION_PLAIN_1024_WACPU_SIZE)))))  ///< Macro to extract CPU workarea size for the given key length.
#else
#define MCUXCLRSA_KEYGENERATION_PLAIN_WACPU_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_4096_WACPU_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_3072_WACPU_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_2048_WACPU_SIZE : \
                                MCUXCLRSA_KEYGENERATION_PLAIN_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size for the given key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_KEYGENERATION_PLAIN_1024_WAPKC_SIZE    (1200u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 1024-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_2048_WAPKC_SIZE    (2224u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 2048-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_3072_WAPKC_SIZE    (3248u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 3072-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_4096_WAPKC_SIZE    (4272u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 4096-bit RSA keys in plain form
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_PLAIN_6144_WAPKC_SIZE    ($(mcuxClRsa_KeyGeneration_Plain_6144_WaPKC)u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 6144-bit RSA keys in plain form
#define MCUXCLRSA_KEYGENERATION_PLAIN_8192_WAPKC_SIZE    ($(mcuxClRsa_KeyGeneration_Plain_8192_WaPKC)u) ///< Definition of PKC workarea size (in bytes) for the mcuxClKey_generate_keypair function required to generate 8192-bit RSA keys in plain form

#define MCUXCLRSA_KEYGENERATION_PLAIN_WAPKC_SIZE(keyBitLength) \
    ((6144U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_8192_WAPKC_SIZE : \
    ((4096U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_6144_WAPKC_SIZE : \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_2048_WAPKC_SIZE : \
                                MCUXCLRSA_KEYGENERATION_PLAIN_1024_WAPKC_SIZE)))))  ///< Macro to extract PKC workarea size for the given key length.
#else
#define MCUXCLRSA_KEYGENERATION_PLAIN_WAPKC_SIZE(keyBitLength) \
    ((3072U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_4096_WAPKC_SIZE : \
    ((2048U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_3072_WAPKC_SIZE : \
    ((1024U < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_2048_WAPKC_SIZE : \
                                MCUXCLRSA_KEYGENERATION_PLAIN_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size for the given key length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/** @} */

/**
 * @defgroup MCUXCLRSA_KEYGENERATION_KEY_DATA_SIZE MCUXCLRSA_KEYGENERATION_KEY_DATA_SIZE
 * @brief Definitions of buffer sizes for generated RSA key data using mcuxClKey_generate_keypair function.
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_1024_SIZE     (272u)  ///< Definition of buffer size (in bytes) for the RSA private plain key data for 1024-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_2048_SIZE     (528u)  ///< Definition of buffer size (in bytes) for the RSA private plain key data for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_3072_SIZE     (784u)  ///< Definition of buffer size (in bytes) for the RSA private plain key data for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_4096_SIZE     (1040u)  ///< Definition of buffer size (in bytes) for the RSA private plain key data for 4096-bit keys
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_6144_SIZE     ($(mcuxClRsa_KeyGeneration_Plain_Key_Data_6144)u)  ///< Definition of buffer size (in bytes) for the RSA private plain key data for 6144-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_8192_SIZE     ($(mcuxClRsa_KeyGeneration_Plain_Key_Data_8192)u)  ///< Definition of buffer size (in bytes) for the RSA private plain key data for 8192-bit keys
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_1024_SIZE       (368u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 1024-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_2048_SIZE       (688u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_3072_SIZE       (1008u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_4096_SIZE       (1328u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 4096-bit keys
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_6144_SIZE       ($(mcuxClRsa_KeyGeneration_Crt_Key_Data_6144)u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 6144-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_8192_SIZE       ($(mcuxClRsa_KeyGeneration_Crt_Key_Data_8192)u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 8192-bit keys
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_KEYGENERATION_CRTDFA_KEY_DATA_1024_SIZE    (496u)  ///< Definition of buffer size (in bytes) for the RSA private CRT DFA key data for 1024-bit keys
#define MCUXCLRSA_KEYGENERATION_CRTDFA_KEY_DATA_2048_SIZE    (944u)  ///< Definition of buffer size (in bytes) for the RSA private CRT DFA key data for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_CRTDFA_KEY_DATA_3072_SIZE    (1392u)  ///< Definition of buffer size (in bytes) for the RSA private CRT DFA key data for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_CRTDFA_KEY_DATA_4096_SIZE    (1840u)  ///< Definition of buffer size (in bytes) for the RSA private CRT DFA key data for 4096-bit keys
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_CRTDFA_KEY_DATA_6144_SIZE    ($(mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_6144)u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 6144-bit keys
#define MCUXCLRSA_KEYGENERATION_CRTDFA_KEY_DATA_8192_SIZE    ($(mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_8192)u)  ///< Definition of buffer size (in bytes) for the RSA private CRT key data for 8192-bit keys
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_SIZE(keyByteLen, expByteLen) \
                                                            (16u + (keyByteLen) + (expByteLen))  ///< Definition of buffer size (in bytes) for the RSA public key data for given key and public exponent size (in bytes)
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_1024_SIZE    (272u)  ///< Definition of buffer size (in bytes) for the RSA public key data for 1024-bit keys
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_2048_SIZE    (528u)  ///< Definition of buffer size (in bytes) for the RSA public key data for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_3072_SIZE    (784u)  ///< Definition of buffer size (in bytes) for the RSA public key data for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_4096_SIZE    (1040u)  ///< Definition of buffer size (in bytes) for the RSA public key data for 4096-bit keys
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_6144_SIZE    ($(mcuxClRsa_KeyGeneration_Public_Key_Data_6144)u)  ///< Definition of buffer size (in bytes) for the RSA public key data for 6144-bit keys
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_8192_SIZE    ($(mcuxClRsa_KeyGeneration_Public_Key_Data_8192)u)  ///< Definition of buffer size (in bytes) for the RSA public key data for 8192-bit keys
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/** @} */


#endif /* MCUXCLRSA_MEMORYCONSUMPTION_H_ */
