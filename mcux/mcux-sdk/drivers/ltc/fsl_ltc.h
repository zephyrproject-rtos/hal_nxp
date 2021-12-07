/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_LTC_H_
#define _FSL_LTC_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*!
 * @addtogroup ltc
 * @{
 */
/*! @name Driver version */
/*@{*/
/*! @brief LTC driver version. Version 2.0.15.
 *
 * Current version: 2.0.14
 *
 * Change log:
 * - Version 2.0.1
 *   - fixed warning during g++ compilation
 *
 * - Version 2.0.2
 *   - fixed [KPSDK-10932][LTC][SHA] LTC_HASH() blocks indefinitely when message size exceeds 4080 bytes
 *
 * - Version 2.0.3
 *   - fixed LTC_PKHA_CompareBigNum() in case an integer argument is an array of all zeroes
 *
 * - Version 2.0.4
 *   - constant LTC_PKHA_CompareBigNum() processing time
 *
 * - Version 2.0.5
 *   - Fix MISRA issues
 *
 * - Version 2.0.6
 *   - fixed [KPSDK-23603][LTC] AES Decrypt in ECB and CBC modes fail when ciphertext size > 0xff0 bytes
 *
 * - Version 2.0.7
 *   - Fix MISRA-2012 issues
 *
 * - Version 2.0.8
 *   - Fix Coverity issues
 *
 * - Version 2.0.9
 *   - Fix sign-compare warning in ltc_set_context and in ltc_get_context
 *
 * - Version 2.0.10
 *   - Fix MISRA-2012 issues
 *
 * - Version 2.0.11
 *   - Fix MISRA-2012 issues
 *
 * - Version 2.0.12
 *   - Fix AES Decrypt in CBC modes fail when used kLTC_DecryptKey.
 *
 * - Version 2.0.13
 *   - Add feature macro FSL_FEATURE_LTC_HAS_NO_CLOCK_CONTROL_BIT into LTC_Init function.
 *
 * - Version 2.0.14
 *   - Add feature macro FSL_FEATURE_LTC_HAS_NO_CLOCK_CONTROL_BIT into LTC_Deinit function.
 *
 * - Version 2.0.15
 *   - Fix MISRA-2012 issues
 */
#define FSL_LTC_DRIVER_VERSION (MAKE_VERSION(2, 0, 15))
/*@}*/
/*! @} */

/*******************************************************************************
 * AES Definitions
 *******************************************************************************/
/*!
 * @addtogroup ltc_driver_aes
 * @{
 */
/*! AES block size in bytes */
#define LTC_AES_BLOCK_SIZE 16U
/*! AES Input Vector size in bytes */
#define LTC_AES_IV_SIZE 16

/*! @brief Type of AES key for ECB and CBC decrypt operations. */
typedef enum _ltc_aes_key_t
{
    kLTC_EncryptKey = 0U, /*!< Input key is an encrypt key */
    kLTC_DecryptKey = 1U, /*!< Input key is a decrypt key */
} ltc_aes_key_t;

/*!
 *@}
 */

/*******************************************************************************
 * DES Definitions
 *******************************************************************************/
/*!
 * @addtogroup ltc_driver_des
 * @{
 */

/*! @brief LTC DES key size - 64 bits. */
#define LTC_DES_KEY_SIZE 8

/*! @brief LTC DES IV size - 8 bytes */
#define LTC_DES_IV_SIZE 8

/*!
 *@}
 */

/*******************************************************************************
 * HASH Definitions
 ******************************************************************************/
/*!
 * @addtogroup ltc_driver_hash
 * @{
 */
/*! Supported cryptographic block cipher functions for HASH creation */
typedef enum _ltc_hash_algo_t
{
    kLTC_XcbcMac = 0, /*!< XCBC-MAC (AES engine) */
    kLTC_Cmac,        /*!< CMAC (AES engine) */
#if defined(FSL_FEATURE_LTC_HAS_SHA) && FSL_FEATURE_LTC_HAS_SHA
    kLTC_Sha1,   /*!< SHA_1   (MDHA engine)  */
    kLTC_Sha224, /*!< SHA_224 (MDHA engine)  */
    kLTC_Sha256, /*!< SHA_256 (MDHA engine)  */
#endif           /* FSL_FEATURE_LTC_HAS_SHA */
} ltc_hash_algo_t;

/*! @brief LTC HASH Context size. */
#if defined(FSL_FEATURE_LTC_HAS_SHA) && FSL_FEATURE_LTC_HAS_SHA
#define LTC_HASH_CTX_SIZE 41
#else
#define LTC_HASH_CTX_SIZE 29
#endif /* FSL_FEATURE_LTC_HAS_SHA */

/*! @brief Storage type used to save hash context. */
typedef struct _ltc_hash_ctx_t
{
    uint32_t x[LTC_HASH_CTX_SIZE];
} ltc_hash_ctx_t;

/*!
 *@}
 */
/*******************************************************************************
 * PKHA Definitions
 ******************************************************************************/
/*!
 * @addtogroup ltc_driver_pkha
 * @{
 */
/*! PKHA ECC point structure */
typedef struct _ltc_pkha_ecc_point_t
{
    uint8_t *X; /*!< X coordinate (affine) */
    uint8_t *Y; /*!< Y coordinate (affine) */
} ltc_pkha_ecc_point_t;

/*! @brief Use of timing equalized version of a PKHA function. */
typedef enum _ltc_pkha_timing_t
{
    kLTC_PKHA_NoTimingEqualized = 0U, /*!< Normal version of a PKHA operation */
    kLTC_PKHA_TimingEqualized   = 1U  /*!< Timing-equalized version of a PKHA operation  */
} ltc_pkha_timing_t;

/*! @brief Integer vs binary polynomial arithmetic selection. */
typedef enum _ltc_pkha_f2m_t
{
    kLTC_PKHA_IntegerArith = 0U, /*!< Use integer arithmetic */
    kLTC_PKHA_F2mArith     = 1U  /*!< Use binary polynomial arithmetic */
} ltc_pkha_f2m_t;

/*! @brief Montgomery or normal PKHA input format. */
typedef enum _ltc_pkha_montgomery_form_t
{
    kLTC_PKHA_NormalValue      = 0U, /*!< PKHA number is normal integer */
    kLTC_PKHA_MontgomeryFormat = 1U  /*!< PKHA number is in montgomery format */
} ltc_pkha_montgomery_form_t;

/*!
 *@}
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @addtogroup ltc
 * @{
 */

/*!
 * @brief Initializes the LTC driver.
 * This function initializes the LTC driver.
 * @param base LTC peripheral base address
 */
void LTC_Init(LTC_Type *base);

/*!
 * @brief Deinitializes the LTC driver.
 * This function deinitializes the LTC driver.
 * @param base LTC peripheral base address
 */
void LTC_Deinit(LTC_Type *base);

#if defined(FSL_FEATURE_LTC_HAS_DPAMS) && FSL_FEATURE_LTC_HAS_DPAMS
/*!
 * @brief Sets the DPA Mask Seed register.
 *
 * The DPA Mask Seed register reseeds the mask that provides resistance against DPA (differential power analysis)
 * attacks on AES or DES keys.
 *
 * Differential Power Analysis Mask (DPA) resistance uses a randomly changing mask that introduces
 * "noise" into the power consumed by the AES or DES. This reduces the signal-to-noise ratio that differential
 * power analysis attacks use to "guess" bits of the key. This randomly changing mask should be
 * seeded at POR, and continues to provide DPA resistance from that point on. However, to provide even more
 * DPA protection it is recommended that the DPA mask be reseeded after every 50,000 blocks have
 * been processed. At that time, software can opt to write a new seed (preferably obtained from an RNG)
 * into the DPA Mask Seed register (DPAMS), or software can opt to provide the new seed earlier or
 * later, or not at all. DPA resistance continues even if the DPA mask is never reseeded.
 *
 * @param base LTC peripheral base address
 * @param mask The DPA mask seed.
 */
void LTC_SetDpaMaskSeed(LTC_Type *base, uint32_t mask);
#endif /* FSL_FEATURE_LTC_HAS_DPAMS */

/*!
 *@}
 */

/*******************************************************************************
 * AES API
 ******************************************************************************/

/*!
 * @addtogroup ltc_driver_aes
 * @{
 */

/*!
 * @brief Transforms an AES encrypt key (forward AES) into the decrypt key (inverse AES).
 *
 * Transforms the AES encrypt key (forward AES) into the decrypt key (inverse AES).
 * The key derived by this function can be used as a direct load decrypt key
 * for AES ECB and CBC decryption operations (keyType argument).
 *
 * @param base LTC peripheral base address
 * @param encryptKey Input key for decrypt key transformation
 * @param[out] decryptKey Output key, the decrypt form of the AES key.
 * @param keySize Size of the input key and output key in bytes. Must be 16, 24, or 32.
 * @return Status from key generation operation
 */
status_t LTC_AES_GenerateDecryptKey(LTC_Type *base, const uint8_t *encryptKey, uint8_t *decryptKey, uint32_t keySize);

/*!
 * @brief Encrypts AES using the ECB block mode.
 *
 * Encrypts AES using the ECB block mode.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plain text to encrypt
 * @param[out] ciphertext Output cipher text
 * @param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * @param key Input key to use for encryption
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @return Status from encrypt operation
 */
status_t LTC_AES_EncryptEcb(
    LTC_Type *base, const uint8_t *plaintext, uint8_t *ciphertext, uint32_t size, const uint8_t *key, uint32_t keySize);

/*!
 * @brief Decrypts AES using ECB block mode.
 *
 * Decrypts AES using ECB block mode.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input cipher text to decrypt
 * @param[out] plaintext Output plain text
 * @param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * @param key Input key.
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @param keyType Input type of the key (allows to directly load decrypt key for AES ECB decrypt operation.)
 * @return Status from decrypt operation
 */
status_t LTC_AES_DecryptEcb(LTC_Type *base,
                            const uint8_t *ciphertext,
                            uint8_t *plaintext,
                            uint32_t size,
                            const uint8_t *key,
                            uint32_t keySize,
                            ltc_aes_key_t keyType);

/*!
 * @brief Encrypts AES using CBC block mode.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plain text to encrypt
 * @param[out] ciphertext Output cipher text
 * @param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * @param iv Input initial vector to combine with the first input block.
 * @param key Input key to use for encryption
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @return Status from encrypt operation
 */
status_t LTC_AES_EncryptCbc(LTC_Type *base,
                            const uint8_t *plaintext,
                            uint8_t *ciphertext,
                            uint32_t size,
                            const uint8_t iv[LTC_AES_IV_SIZE],
                            const uint8_t *key,
                            uint32_t keySize);

/*!
 * @brief Decrypts AES using CBC block mode.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input cipher text to decrypt
 * @param[out] plaintext Output plain text
 * @param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * @param iv Input initial vector to combine with the first input block.
 * @param key Input key to use for decryption
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @param keyType Input type of the key (allows to directly load decrypt key for AES CBC decrypt operation.)
 * @return Status from decrypt operation
 */
status_t LTC_AES_DecryptCbc(LTC_Type *base,
                            const uint8_t *ciphertext,
                            uint8_t *plaintext,
                            uint32_t size,
                            const uint8_t iv[LTC_AES_IV_SIZE],
                            const uint8_t *key,
                            uint32_t keySize,
                            ltc_aes_key_t keyType);

/*!
 * @brief Encrypts or decrypts AES using CTR block mode.
 *
 * Encrypts or decrypts AES using CTR block mode.
 * AES CTR mode uses only forward AES cipher and same algorithm for encryption and decryption.
 * The only difference between encryption and decryption is that, for encryption, the input argument
 * is plain text and the output argument is cipher text. For decryption, the input argument is cipher text
 * and the output argument is plain text.
 *
 * @param base LTC peripheral base address
 * @param input Input data for CTR block mode
 * @param[out] output Output data for CTR block mode
 * @param size Size of input and output data in bytes
 * @param[in,out] counter Input counter (updates on return)
 * @param key Input key to use for forward AES cipher
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @param[out] counterlast Output cipher of last counter, for chained CTR calls. NULL can be passed if chained calls are
 * not used.
 * @param[out] szLeft Output number of bytes in left unused in counterlast block. NULL can be passed if chained calls
 * are not used.
 * @return Status from encrypt operation
 */
status_t LTC_AES_CryptCtr(LTC_Type *base,
                          const uint8_t *input,
                          uint8_t *output,
                          uint32_t size,
                          uint8_t counter[LTC_AES_BLOCK_SIZE],
                          const uint8_t *key,
                          uint32_t keySize,
                          uint8_t counterlast[LTC_AES_BLOCK_SIZE],
                          uint32_t *szLeft);

/*! AES CTR decrypt is mapped to the AES CTR generic operation */
#define LTC_AES_DecryptCtr(base, input, output, size, counter, key, keySize, counterlast, szLeft) \
    LTC_AES_CryptCtr(base, input, output, size, counter, key, keySize, counterlast, szLeft)

/*! AES CTR encrypt is mapped to the AES CTR generic operation */
#define LTC_AES_EncryptCtr(base, input, output, size, counter, key, keySize, counterlast, szLeft) \
    LTC_AES_CryptCtr(base, input, output, size, counter, key, keySize, counterlast, szLeft)

#if defined(FSL_FEATURE_LTC_HAS_GCM) && FSL_FEATURE_LTC_HAS_GCM
/*!
 * @brief Encrypts AES and tags using GCM block mode.
 *
 * Encrypts AES and optionally tags using GCM block mode. If plaintext is NULL, only the GHASH is calculated and output
 * in the 'tag' field.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plain text to encrypt
 * @param[out] ciphertext Output cipher text.
 * @param size Size of input and output data in bytes
 * @param iv Input initial vector
 * @param ivSize Size of the IV
 * @param aad Input additional authentication data
 * @param aadSize Input size in bytes of AAD
 * @param key Input key to use for encryption
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @param[out] tag Output hash tag. Set to NULL to skip tag processing.
 * @param tagSize Input size of the tag to generate, in bytes. Must be 4,8,12,13,14,15 or 16.
 * @return Status from encrypt operation
 */
status_t LTC_AES_EncryptTagGcm(LTC_Type *base,
                               const uint8_t *plaintext,
                               uint8_t *ciphertext,
                               uint32_t size,
                               const uint8_t *iv,
                               uint32_t ivSize,
                               const uint8_t *aad,
                               uint32_t aadSize,
                               const uint8_t *key,
                               uint32_t keySize,
                               uint8_t *tag,
                               uint32_t tagSize);

/*!
 * @brief Decrypts AES and authenticates using GCM block mode.
 *
 * Decrypts AES and optionally authenticates using GCM block mode. If ciphertext is NULL, only the GHASH is calculated
 * and compared with the received GHASH in 'tag' field.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input cipher text to decrypt
 * @param[out] plaintext Output plain text.
 * @param size Size of input and output data in bytes
 * @param iv Input initial vector
 * @param ivSize Size of the IV
 * @param aad Input additional authentication data
 * @param aadSize Input size in bytes of AAD
 * @param key Input key to use for encryption
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @param tag Input hash tag to compare. Set to NULL to skip tag processing.
 * @param tagSize Input size of the tag, in bytes. Must be 4, 8, 12, 13, 14, 15, or 16.
 * @return Status from decrypt operation
 */
status_t LTC_AES_DecryptTagGcm(LTC_Type *base,
                               const uint8_t *ciphertext,
                               uint8_t *plaintext,
                               uint32_t size,
                               const uint8_t *iv,
                               uint32_t ivSize,
                               const uint8_t *aad,
                               uint32_t aadSize,
                               const uint8_t *key,
                               uint32_t keySize,
                               const uint8_t *tag,
                               uint32_t tagSize);
#endif /* FSL_FEATURE_LTC_HAS_GCM */

/*!
 * @brief Encrypts AES and tags using CCM block mode.
 *
 * Encrypts AES and optionally tags using CCM block mode.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plain text to encrypt
 * @param[out] ciphertext Output cipher text.
 * @param size Size of input and output data in bytes. Zero means authentication only.
 * @param iv Nonce
 * @param ivSize Length of the Nonce in bytes. Must be 7, 8, 9, 10, 11, 12, or 13.
 * @param aad Input additional authentication data. Can be NULL if aadSize is zero.
 * @param aadSize Input size in bytes of AAD. Zero means data mode only (authentication skipped).
 * @param key Input key to use for encryption
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @param[out] tag Generated output tag. Set to NULL to skip tag processing.
 * @param tagSize Input size of the tag to generate, in bytes. Must be 4, 6, 8, 10, 12, 14, or 16.
 * @return Status from encrypt operation
 */
status_t LTC_AES_EncryptTagCcm(LTC_Type *base,
                               const uint8_t *plaintext,
                               uint8_t *ciphertext,
                               uint32_t size,
                               const uint8_t *iv,
                               uint32_t ivSize,
                               const uint8_t *aad,
                               uint32_t aadSize,
                               const uint8_t *key,
                               uint32_t keySize,
                               uint8_t *tag,
                               uint32_t tagSize);

/*!
 * @brief Decrypts AES and authenticates using CCM block mode.
 *
 * Decrypts AES and optionally authenticates using CCM block mode.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input cipher text to decrypt
 * @param[out] plaintext Output plain text.
 * @param size Size of input and output data in bytes. Zero means authentication only.
 * @param iv Nonce
 * @param ivSize Length of the Nonce in bytes. Must be 7, 8, 9, 10, 11, 12, or 13.
 * @param aad Input additional authentication data. Can be NULL if aadSize is zero.
 * @param aadSize Input size in bytes of AAD. Zero means data mode only (authentication skipped).
 * @param key Input key to use for decryption
 * @param keySize Size of the input key, in bytes. Must be 16, 24, or 32.
 * @param tag Received tag. Set to NULL to skip tag processing.
 * @param tagSize Input size of the received tag to compare with the computed tag, in bytes. Must be 4, 6, 8, 10, 12,
 * 14, or 16.
 * @return Status from decrypt operation
 */
status_t LTC_AES_DecryptTagCcm(LTC_Type *base,
                               const uint8_t *ciphertext,
                               uint8_t *plaintext,
                               uint32_t size,
                               const uint8_t *iv,
                               uint32_t ivSize,
                               const uint8_t *aad,
                               uint32_t aadSize,
                               const uint8_t *key,
                               uint32_t keySize,
                               const uint8_t *tag,
                               uint32_t tagSize);

/*!
 *@}
 */

#if defined(FSL_FEATURE_LTC_HAS_DES) && FSL_FEATURE_LTC_HAS_DES
/*******************************************************************************
 * DES API
 ******************************************************************************/
/*!
 * @addtogroup ltc_driver_des
 * @{
 */
/*!
 * @brief Encrypts DES using ECB block mode.
 *
 * Encrypts DES using ECB block mode.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * @param key Input key to use for encryption
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptEcb(
    LTC_Type *base, const uint8_t *plaintext, uint8_t *ciphertext, uint32_t size, const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts DES using ECB block mode.
 *
 * Decrypts DES using ECB block mode.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * @param key Input key to use for decryption
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptEcb(
    LTC_Type *base, const uint8_t *ciphertext, uint8_t *plaintext, uint32_t size, const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts DES using CBC block mode.
 *
 * Encrypts DES using CBC block mode.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Ouput ciphertext
 * @param size Size of input and output data in bytes
 * @param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * @param key Input key to use for encryption
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptCbc(LTC_Type *base,
                            const uint8_t *plaintext,
                            uint8_t *ciphertext,
                            uint32_t size,
                            const uint8_t iv[LTC_DES_IV_SIZE],
                            const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts DES using CBC block mode.
 *
 * Decrypts DES using CBC block mode.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input data in bytes
 * @param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * @param key Input key to use for decryption
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptCbc(LTC_Type *base,
                            const uint8_t *ciphertext,
                            uint8_t *plaintext,
                            uint32_t size,
                            const uint8_t iv[LTC_DES_IV_SIZE],
                            const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts DES using CFB block mode.
 *
 * Encrypts DES using CFB block mode.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param size Size of input data in bytes
 * @param iv Input initial block.
 * @param key Input key to use for encryption
 * @param[out] ciphertext Output ciphertext
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptCfb(LTC_Type *base,
                            const uint8_t *plaintext,
                            uint8_t *ciphertext,
                            uint32_t size,
                            const uint8_t iv[LTC_DES_IV_SIZE],
                            const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts DES using CFB block mode.
 *
 * Decrypts DES using CFB block mode.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes
 * @param iv Input initial block.
 * @param key Input key to use for decryption
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptCfb(LTC_Type *base,
                            const uint8_t *ciphertext,
                            uint8_t *plaintext,
                            uint32_t size,
                            const uint8_t iv[LTC_DES_IV_SIZE],
                            const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts DES using OFB block mode.
 *
 * Encrypts DES using OFB block mode.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes
 * @param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * @param key Input key to use for encryption
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptOfb(LTC_Type *base,
                            const uint8_t *plaintext,
                            uint8_t *ciphertext,
                            uint32_t size,
                            const uint8_t iv[LTC_DES_IV_SIZE],
                            const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts DES using OFB block mode.
 *
 * Decrypts DES using OFB block mode.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * @param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * @param key Input key to use for decryption
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptOfb(LTC_Type *base,
                            const uint8_t *ciphertext,
                            uint8_t *plaintext,
                            uint32_t size,
                            const uint8_t iv[LTC_DES_IV_SIZE],
                            const uint8_t key[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using ECB block mode with two keys.
 *
 * Encrypts triple DES using ECB block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptEcb(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using ECB block mode with two keys.
 *
 * Decrypts triple DES using ECB block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptEcb(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using CBC block mode with two keys.
 *
 * Encrypts triple DES using CBC block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes
 * @param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptCbc(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using CBC block mode with two keys.
 *
 * Decrypts triple DES using CBC block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes
 * @param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptCbc(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using CFB block mode with two keys.
 *
 * Encrypts triple DES using CFB block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes
 * @param iv Input initial block.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptCfb(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using CFB block mode with two keys.
 *
 * Decrypts triple DES using CFB block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes
 * @param iv Input initial block.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptCfb(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using OFB block mode with two keys.
 *
 * Encrypts triple DES using OFB block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes
 * @param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptOfb(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using OFB block mode with two keys.
 *
 * Decrypts triple DES using OFB block mode with two keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes
 * @param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptOfb(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using ECB block mode with three keys.
 *
 * Encrypts triple DES using ECB block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptEcb(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using ECB block mode with three keys.
 *
 * Decrypts triple DES using ECB block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptEcb(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using CBC block mode with three keys.
 *
 * Encrypts triple DES using CBC block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input data in bytes
 * @param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptCbc(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using CBC block mode with three keys.
 *
 * Decrypts triple DES using CBC block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes
 * @param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptCbc(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using CFB block mode with three keys.
 *
 * Encrypts triple DES using CFB block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and ouput data in bytes
 * @param iv Input initial block.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptCfb(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using CFB block mode with three keys.
 *
 * Decrypts triple DES using CFB block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input data in bytes
 * @param iv Input initial block.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptCfb(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);

/*!
 * @brief Encrypts triple DES using OFB block mode with three keys.
 *
 * Encrypts triple DES using OFB block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param plaintext Input plaintext to encrypt
 * @param[out] ciphertext Output ciphertext
 * @param size Size of input and output data in bytes
 * @param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptOfb(LTC_Type *base,
                             const uint8_t *plaintext,
                             uint8_t *ciphertext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);

/*!
 * @brief Decrypts triple DES using OFB block mode with three keys.
 *
 * Decrypts triple DES using OFB block mode with three keys.
 *
 * @param base LTC peripheral base address
 * @param ciphertext Input ciphertext to decrypt
 * @param[out] plaintext Output plaintext
 * @param size Size of input and output data in bytes
 * @param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * @param key1 First input key for key bundle
 * @param key2 Second input key for key bundle
 * @param key3 Third input key for key bundle
 * @return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptOfb(LTC_Type *base,
                             const uint8_t *ciphertext,
                             uint8_t *plaintext,
                             uint32_t size,
                             const uint8_t iv[LTC_DES_IV_SIZE],
                             const uint8_t key1[LTC_DES_KEY_SIZE],
                             const uint8_t key2[LTC_DES_KEY_SIZE],
                             const uint8_t key3[LTC_DES_KEY_SIZE]);
#endif /* FSL_FEATURE_LTC_HAS_DES */

/*!
 *@}
 */

/*******************************************************************************
 * HASH API
 ******************************************************************************/

/*!
 * @addtogroup ltc_driver_hash
 * @{
 */
/*!
 * @brief Initialize HASH context
 *
 * This function initialize the HASH.
 * Key shall be supplied if the underlaying algoritm is AES XCBC-MAC or CMAC.
 * Key shall be NULL if the underlaying algoritm is SHA.
 *
 * For XCBC-MAC, the key length must be 16. For CMAC, the key length can be
 * the AES key lengths supported by AES engine. For MDHA the key length argument
 * is ignored.
 *
 * @param base LTC peripheral base address
 * @param[out] ctx Output hash context
 * @param algo Underlaying algorithm to use for hash computation.
 * @param key Input key (NULL if underlaying algorithm is SHA)
 * @param keySize Size of input key in bytes
 * @return Status of initialization
 */
status_t LTC_HASH_Init(LTC_Type *base, ltc_hash_ctx_t *ctx, ltc_hash_algo_t algo, const uint8_t *key, uint32_t keySize);

/*!
 * @brief Add data to current HASH
 *
 * Add data to current HASH. This can be called repeatedly with an arbitrary amount of data to be
 * hashed.
 *
 * @param[in,out] ctx HASH context
 * @param input Input data
 * @param inputSize Size of input data in bytes
 * @return Status of the hash update operation
 */
status_t LTC_HASH_Update(ltc_hash_ctx_t *ctx, const uint8_t *input, uint32_t inputSize);

/*!
 * @brief Finalize hashing
 *
 * Outputs the final hash and erases the context.
 *
 * @param[in,out] ctx Input hash context
 * @param[out] output Output hash data
 * @param[out] outputSize Output parameter storing the size of the output hash in bytes
 * @return Status of the hash finish operation
 */
status_t LTC_HASH_Finish(ltc_hash_ctx_t *ctx, uint8_t *output, uint32_t *outputSize);

/*!
 * @brief Create HASH on given data
 *
 * Perform the full keyed HASH in one function call.
 *
 * @param base LTC peripheral base address
 * @param algo Block cipher algorithm to use for CMAC creation
 * @param input Input data
 * @param inputSize Size of input data in bytes
 * @param key Input key
 * @param keySize Size of input key in bytes
 * @param[out] output Output hash data
 * @param[out] outputSize Output parameter storing the size of the output hash in bytes
 * @return Status of the one call hash operation.
 */
status_t LTC_HASH(LTC_Type *base,
                  ltc_hash_algo_t algo,
                  const uint8_t *input,
                  uint32_t inputSize,
                  const uint8_t *key,
                  uint32_t keySize,
                  uint8_t *output,
                  uint32_t *outputSize);
/*!
 *@}
 */

#if defined(FSL_FEATURE_LTC_HAS_PKHA) && FSL_FEATURE_LTC_HAS_PKHA
/*******************************************************************************
 * PKHA API
 ******************************************************************************/
/*!
 * @addtogroup ltc_driver_pkha
 * @{
 */

/*!
 * @brief Compare two PKHA big numbers.
 *
 * Compare two PKHA big numbers. Return 1 for a > b, -1 for a < b and 0 if they are same.
 * PKHA big number is lsbyte first. Thus the comparison starts at msbyte which is the last member of tested arrays.
 *
 * @param a First integer represented as an array of bytes, lsbyte first.
 * @param sizeA Size in bytes of the first integer.
 * @param b Second integer represented as an array of bytes, lsbyte first.
 * @param sizeB Size in bytes of the second integer.
 * @return 1 if a > b.
 * @return -1 if a < b.
 * @return 0 if a = b.
 */
int LTC_PKHA_CompareBigNum(const uint8_t *a, size_t sizeA, const uint8_t *b, size_t sizeB);

/*!
 * @brief Converts from integer to Montgomery format.
 *
 * This function computes R2 mod N and optionally converts A or B into Montgomery format of A or B.
 *
 * @param base LTC peripheral base address
 * @param N modulus
 * @param sizeN size of N in bytes
 * @param[in,out] A The first input in non-Montgomery format. Output Montgomery format of the first input.
 * @param[in,out] sizeA pointer to size variable. On input it holds size of input A in bytes. On output it holds size of
 *                Montgomery format of A in bytes.
 * @param[in,out] B Second input in non-Montgomery format. Output Montgomery format of the second input.
 * @param[in,out] sizeB pointer to size variable. On input it holds size of input B in bytes. On output it holds size of
 *                Montgomery format of B in bytes.
 * @param[out] R2 Output Montgomery factor R2 mod N.
 * @param[out] sizeR2 pointer to size variable. On output it holds size of Montgomery factor R2 mod N in bytes.
 * @param equalTime Run the function time equalized or no timing equalization.
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @return Operation status.
 */
status_t LTC_PKHA_NormalToMontgomery(LTC_Type *base,
                                     const uint8_t *N,
                                     uint16_t sizeN,
                                     uint8_t *A,
                                     uint16_t *sizeA,
                                     uint8_t *B,
                                     uint16_t *sizeB,
                                     uint8_t *R2,
                                     uint16_t *sizeR2,
                                     ltc_pkha_timing_t equalTime,
                                     ltc_pkha_f2m_t arithType);

/*!
 * @brief Converts from Montgomery format to int.
 *
 * This function converts Montgomery format of A or B into int A or B.
 *
 * @param base LTC peripheral base address
 * @param N modulus.
 * @param sizeN size of N modulus in bytes.
 * @param[in,out] A Input first number in Montgomery format. Output is non-Montgomery format.
 * @param[in,out] sizeA pointer to size variable. On input it holds size of the input A in bytes. On output it holds
 * size of non-Montgomery A in bytes.
 * @param[in,out] B Input first number in Montgomery format. Output is non-Montgomery format.
 * @param[in,out] sizeB pointer to size variable. On input it holds size of the input B in bytes. On output it holds
 * size of non-Montgomery B in bytes.
 * @param equalTime Run the function time equalized or no timing equalization.
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @return Operation status.
 */
status_t LTC_PKHA_MontgomeryToNormal(LTC_Type *base,
                                     const uint8_t *N,
                                     uint16_t sizeN,
                                     uint8_t *A,
                                     uint16_t *sizeA,
                                     uint8_t *B,
                                     uint16_t *sizeB,
                                     ltc_pkha_timing_t equalTime,
                                     ltc_pkha_f2m_t arithType);

/*!
 * @brief Performs modular addition - (A + B) mod N.
 *
 * This function performs modular addition of (A + B) mod N, with either
 * integer or binary polynomial (F2m) inputs.  In the F2m form, this function is
 * equivalent to a bitwise XOR and it is functionally the same as subtraction.
 *
 * @param base LTC peripheral base address
 * @param A first addend (integer or binary polynomial)
 * @param sizeA Size of A in bytes
 * @param B second addend (integer or binary polynomial)
 * @param sizeB Size of B in bytes
 * @param N modulus. For F2m operation this can be NULL, as N is ignored during F2m polynomial addition.
 * @param sizeN Size of N in bytes. This must be given for both integer and F2m polynomial additions.
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @return Operation status.
 */
status_t LTC_PKHA_ModAdd(LTC_Type *base,
                         const uint8_t *A,
                         uint16_t sizeA,
                         const uint8_t *B,
                         uint16_t sizeB,
                         const uint8_t *N,
                         uint16_t sizeN,
                         uint8_t *result,
                         uint16_t *resultSize,
                         ltc_pkha_f2m_t arithType);

/*!
 * @brief Performs modular subtraction - (A - B) mod N.
 *
 * This function performs modular subtraction of (A - B) mod N with
 * integer inputs.
 *
 * @param base LTC peripheral base address
 * @param A first addend (integer or binary polynomial)
 * @param sizeA Size of A in bytes
 * @param B second addend (integer or binary polynomial)
 * @param sizeB Size of B in bytes
 * @param N modulus
 * @param sizeN Size of N in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @return Operation status.
 */
status_t LTC_PKHA_ModSub1(LTC_Type *base,
                          const uint8_t *A,
                          uint16_t sizeA,
                          const uint8_t *B,
                          uint16_t sizeB,
                          const uint8_t *N,
                          uint16_t sizeN,
                          uint8_t *result,
                          uint16_t *resultSize);

/*!
 * @brief Performs modular subtraction - (B - A) mod N.
 *
 * This function performs modular subtraction of (B - A) mod N,
 * with integer inputs.
 *
 * @param base LTC peripheral base address
 * @param A first addend (integer or binary polynomial)
 * @param sizeA Size of A in bytes
 * @param B second addend (integer or binary polynomial)
 * @param sizeB Size of B in bytes
 * @param N modulus
 * @param sizeN Size of N in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @return Operation status.
 */
status_t LTC_PKHA_ModSub2(LTC_Type *base,
                          const uint8_t *A,
                          uint16_t sizeA,
                          const uint8_t *B,
                          uint16_t sizeB,
                          const uint8_t *N,
                          uint16_t sizeN,
                          uint8_t *result,
                          uint16_t *resultSize);

/*!
 * @brief Performs modular multiplication - (A x B) mod N.
 *
 * This function performs modular multiplication with either integer or
 * binary polynomial (F2m) inputs.  It can optionally specify whether inputs
 * and/or outputs will be in Montgomery form or not.
 *
 * @param base LTC peripheral base address
 * @param A first addend (integer or binary polynomial)
 * @param sizeA Size of A in bytes
 * @param B second addend (integer or binary polynomial)
 * @param sizeB Size of B in bytes
 * @param N modulus.
 * @param sizeN Size of N in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @param montIn Format of inputs
 * @param montOut Format of output
 * @param equalTime Run the function time equalized or no timing equalization. This argument is ignored for F2m modular
 * multiplication.
 * @return Operation status.
 */
status_t LTC_PKHA_ModMul(LTC_Type *base,
                         const uint8_t *A,
                         uint16_t sizeA,
                         const uint8_t *B,
                         uint16_t sizeB,
                         const uint8_t *N,
                         uint16_t sizeN,
                         uint8_t *result,
                         uint16_t *resultSize,
                         ltc_pkha_f2m_t arithType,
                         ltc_pkha_montgomery_form_t montIn,
                         ltc_pkha_montgomery_form_t montOut,
                         ltc_pkha_timing_t equalTime);

/*!
 * @brief Performs modular exponentiation - (A^E) mod N.
 *
 * This function performs modular exponentiation with either integer or
 * binary polynomial (F2m) inputs.
 *
 * @param base LTC peripheral base address
 * @param A first addend (integer or binary polynomial)
 * @param sizeA Size of A in bytes
 * @param N modulus
 * @param sizeN Size of N in bytes
 * @param E exponent
 * @param sizeE Size of E in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @param montIn Format of A input (normal or Montgomery)
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @param equalTime Run the function time equalized or no timing equalization.
 * @return Operation status.
 */
status_t LTC_PKHA_ModExp(LTC_Type *base,
                         const uint8_t *A,
                         uint16_t sizeA,
                         const uint8_t *N,
                         uint16_t sizeN,
                         const uint8_t *E,
                         uint16_t sizeE,
                         uint8_t *result,
                         uint16_t *resultSize,
                         ltc_pkha_f2m_t arithType,
                         ltc_pkha_montgomery_form_t montIn,
                         ltc_pkha_timing_t equalTime);

/*!
 * @brief Performs modular reduction - (A) mod N.
 *
 * This function performs modular reduction with either integer or
 * binary polynomial (F2m) inputs.
 *
 * @param base LTC peripheral base address
 * @param A first addend (integer or binary polynomial)
 * @param sizeA Size of A in bytes
 * @param N modulus
 * @param sizeN Size of N in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @return Operation status.
 */
status_t LTC_PKHA_ModRed(LTC_Type *base,
                         const uint8_t *A,
                         uint16_t sizeA,
                         const uint8_t *N,
                         uint16_t sizeN,
                         uint8_t *result,
                         uint16_t *resultSize,
                         ltc_pkha_f2m_t arithType);

/*!
 * @brief Performs modular inversion - (A^-1) mod N.
 *
 * This function performs modular inversion with either integer or
 * binary polynomial (F2m) inputs.
 *
 * @param base LTC peripheral base address
 * @param A first addend (integer or binary polynomial)
 * @param sizeA Size of A in bytes
 * @param N modulus
 * @param sizeN Size of N in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @return Operation status.
 */
status_t LTC_PKHA_ModInv(LTC_Type *base,
                         const uint8_t *A,
                         uint16_t sizeA,
                         const uint8_t *N,
                         uint16_t sizeN,
                         uint8_t *result,
                         uint16_t *resultSize,
                         ltc_pkha_f2m_t arithType);

/*!
 * @brief Computes integer Montgomery factor R^2 mod N.
 *
 * This function computes a constant to assist in converting operands
 * into the Montgomery residue system representation.
 *
 * @param base LTC peripheral base address
 * @param N modulus
 * @param sizeN Size of N in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @return Operation status.
 */
status_t LTC_PKHA_ModR2(
    LTC_Type *base, const uint8_t *N, uint16_t sizeN, uint8_t *result, uint16_t *resultSize, ltc_pkha_f2m_t arithType);

/*!
 * @brief Calculates the greatest common divisor - GCD (A, N).
 *
 * This function calculates the greatest common divisor of two inputs with
 * either integer or binary polynomial (F2m) inputs.
 *
 * @param base LTC peripheral base address
 * @param A first value (must be smaller than or equal to N)
 * @param sizeA Size of A in bytes
 * @param N second value (must be non-zero)
 * @param sizeN Size of N in bytes
 * @param[out] result Output array to store result of operation
 * @param[out] resultSize Output size of operation in bytes
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @return Operation status.
 */
status_t LTC_PKHA_GCD(LTC_Type *base,
                      const uint8_t *A,
                      uint16_t sizeA,
                      const uint8_t *N,
                      uint16_t sizeN,
                      uint8_t *result,
                      uint16_t *resultSize,
                      ltc_pkha_f2m_t arithType);

/*!
 * @brief Executes Miller-Rabin primality test.
 *
 * This function calculates whether or not a candidate prime number is likely
 * to be a prime.
 *
 * @param base LTC peripheral base address
 * @param A initial random seed
 * @param sizeA Size of A in bytes
 * @param B number of trial runs
 * @param sizeB Size of B in bytes
 * @param N candidate prime integer
 * @param sizeN Size of N in bytes
 * @param[out] res True if the value is likely prime or false otherwise
 * @return Operation status.
 */
status_t LTC_PKHA_PrimalityTest(LTC_Type *base,
                                const uint8_t *A,
                                uint16_t sizeA,
                                const uint8_t *B,
                                uint16_t sizeB,
                                const uint8_t *N,
                                uint16_t sizeN,
                                bool *res);

/*!
 * @brief Adds elliptic curve points - A + B.
 *
 * This function performs ECC point addition over a prime field (Fp) or binary field (F2m) using
 * affine coordinates.
 *
 * @param base LTC peripheral base address
 * @param A Left-hand point
 * @param B Right-hand point
 * @param N Prime modulus of the field
 * @param R2modN NULL (the function computes R2modN internally) or pointer to pre-computed R2modN (obtained from
 *               LTC_PKHA_ModR2() function).
 * @param aCurveParam A parameter from curve equation
 * @param bCurveParam B parameter from curve equation (constant)
 * @param size Size in bytes of curve points and parameters
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @param[out] result Result point
 * @return Operation status.
 */
status_t LTC_PKHA_ECC_PointAdd(LTC_Type *base,
                               const ltc_pkha_ecc_point_t *A,
                               const ltc_pkha_ecc_point_t *B,
                               const uint8_t *N,
                               const uint8_t *R2modN,
                               const uint8_t *aCurveParam,
                               const uint8_t *bCurveParam,
                               uint8_t size,
                               ltc_pkha_f2m_t arithType,
                               ltc_pkha_ecc_point_t *result);

/*!
 * @brief Doubles elliptic curve points - B + B.
 *
 * This function performs ECC point doubling over a prime field (Fp) or binary field (F2m) using
 * affine coordinates.
 *
 * @param base LTC peripheral base address
 * @param B Point to double
 * @param N Prime modulus of the field
 * @param aCurveParam A parameter from curve equation
 * @param bCurveParam B parameter from curve equation (constant)
 * @param size Size in bytes of curve points and parameters
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @param[out] result Result point
 * @return Operation status.
 */
status_t LTC_PKHA_ECC_PointDouble(LTC_Type *base,
                                  const ltc_pkha_ecc_point_t *B,
                                  const uint8_t *N,
                                  const uint8_t *aCurveParam,
                                  const uint8_t *bCurveParam,
                                  uint8_t size,
                                  ltc_pkha_f2m_t arithType,
                                  ltc_pkha_ecc_point_t *result);

/*!
 * @brief Multiplies an elliptic curve point by a scalar - E x (A0, A1).
 *
 * This function performs ECC point multiplication to multiply an ECC point by
 * a scalar integer multiplier over a prime field (Fp) or a binary field (F2m).
 *
 * @param base LTC peripheral base address
 * @param A Point as multiplicand
 * @param E Scalar multiple
 * @param sizeE The size of E, in bytes
 * @param N Modulus, a prime number for the Fp field or Irreducible polynomial for F2m field.
 * @param R2modN NULL (the function computes R2modN internally) or pointer to pre-computed R2modN (obtained from
 *        LTC_PKHA_ModR2() function).
 * @param aCurveParam A parameter from curve equation
 * @param bCurveParam B parameter from curve equation (C parameter for operation over F2m).
 * @param size Size in bytes of curve points and parameters
 * @param equalTime Run the function time equalized or no timing equalization.
 * @param arithType Type of arithmetic to perform (integer or F2m)
 * @param[out] result Result point
 * @param[out] infinity Output true if the result is point of infinity, and false otherwise. Writing of this output will
 * be ignored if the argument is NULL.
 * @return Operation status.
 */
status_t LTC_PKHA_ECC_PointMul(LTC_Type *base,
                               const ltc_pkha_ecc_point_t *A,
                               const uint8_t *E,
                               uint8_t sizeE,
                               const uint8_t *N,
                               const uint8_t *R2modN,
                               const uint8_t *aCurveParam,
                               const uint8_t *bCurveParam,
                               uint8_t size,
                               ltc_pkha_timing_t equalTime,
                               ltc_pkha_f2m_t arithType,
                               ltc_pkha_ecc_point_t *result,
                               bool *infinity);
#endif /* FSL_FEATURE_LTC_HAS_PKHA */

/*!
 *@}
 */

/*******************************************************************************
 * Private - only used internally to share code between fsl_ltc_edma.c and fsl_ltc.c
 ******************************************************************************/
/*!
 * @internal
 * @{
 */

#define LTC_MD_ALG_AES        (0x10U) /*!< Bit field value for LTC_MD_ALG: AES */
#define LTC_MD_ALG_DES        (0x20U) /*!< Bit field value for LTC_MD_ALG: DES */
#define LTC_MD_ALG_TRIPLE_DES (0x21U) /*!< Bit field value for LTC_MD_ALG: 3DES */
#define LTC_MD_ALG_SHA1       (0x41U) /*!< Bit field value for LTC_MD_ALG: SHA-1 */
#define LTC_MD_ALG_SHA224     (0x42U) /*!< Bit field value for LTC_MD_ALG: SHA-224 */
#define LTC_MD_ALG_SHA256     (0x43U) /*!< Bit field value for LTC_MD_ALG: SHA-256 */
#define LTC_MDPK_ALG_PKHA     (0x80U) /*!< Bit field value for LTC_MDPK_ALG: PKHA */
#define LTC_MD_ENC_DECRYPT    (0U)    /*!< Bit field value for LTC_MD_ENC: Decrypt. */
#define LTC_MD_ENC_ENCRYPT    (0x1U)  /*!< Bit field value for LTC_MD_ENC: Encrypt. */
#define LTC_MD_AS_UPDATE      (0U)    /*!< Bit field value for LTC_MD_AS: Update */
#define LTC_MD_AS_INITIALIZE  (0x1U)  /*!< Bit field value for LTC_MD_AS: Initialize */
#define LTC_MD_AS_FINALIZE    (0x2U)  /*!< Bit field value for LTC_MD_AS: Finalize */
#define LTC_MD_AS_INIT_FINAL  (0x3U)  /*!< Bit field value for LTC_MD_AS: Initialize/Finalize */

/*! Full word representing the actual bit values for the LTC mode register. */
typedef uint32_t ltc_mode_t;

typedef enum _ltc_algorithm
{
#if defined(FSL_FEATURE_LTC_HAS_PKHA) && FSL_FEATURE_LTC_HAS_PKHA
    kLTC_AlgorithmPKHA = LTC_MDPK_ALG_PKHA << LTC_MD_ALG_SHIFT,
#endif /* FSL_FEATURE_LTC_HAS_PKHA */
    kLTC_AlgorithmAES = LTC_MD_ALG_AES << LTC_MD_ALG_SHIFT,
#if defined(FSL_FEATURE_LTC_HAS_DES) && FSL_FEATURE_LTC_HAS_DES
    kLTC_AlgorithmDES  = LTC_MD_ALG_DES << LTC_MD_ALG_SHIFT,
    kLTC_Algorithm3DES = LTC_MD_ALG_TRIPLE_DES << LTC_MD_ALG_SHIFT,
#endif /* FSL_FEATURE_LTC_HAS_DES */
#if defined(FSL_FEATURE_LTC_HAS_SHA) && FSL_FEATURE_LTC_HAS_SHA
    kLTC_AlgorithmSHA1   = LTC_MD_ALG_SHA1 << LTC_MD_ALG_SHIFT,
    kLTC_AlgorithmSHA224 = LTC_MD_ALG_SHA224 << LTC_MD_ALG_SHIFT,
    kLTC_AlgorithmSHA256 = LTC_MD_ALG_SHA256 << LTC_MD_ALG_SHIFT,
#endif /* FSL_FEATURE_LTC_HAS_SHA */
} ltc_algorithm_t;

typedef enum _ltc_mode_symmetric_alg
{
    kLTC_ModeCTR     = 0x00U << LTC_MD_AAI_SHIFT,
    kLTC_ModeCBC     = 0x10U << LTC_MD_AAI_SHIFT,
    kLTC_ModeECB     = 0x20U << LTC_MD_AAI_SHIFT,
    kLTC_ModeCFB     = 0x30U << LTC_MD_AAI_SHIFT,
    kLTC_ModeOFB     = 0x40U << LTC_MD_AAI_SHIFT,
    kLTC_ModeCMAC    = 0x60U << LTC_MD_AAI_SHIFT,
    kLTC_ModeXCBCMAC = 0x70U << LTC_MD_AAI_SHIFT,
    kLTC_ModeCCM     = 0x80U << LTC_MD_AAI_SHIFT,
    kLTC_ModeGCM     = 0x90U << LTC_MD_AAI_SHIFT,
} ltc_mode_symmetric_alg_t;

typedef enum _ltc_mode_encrypt
{
    kLTC_ModeDecrypt = LTC_MD_ENC_DECRYPT << LTC_MD_ENC_SHIFT,
    kLTC_ModeEncrypt = LTC_MD_ENC_ENCRYPT << LTC_MD_ENC_SHIFT,
} ltc_mode_encrypt_t;

typedef enum _ltc_mode_algorithm_state
{
    kLTC_ModeUpdate    = LTC_MD_AS_UPDATE << LTC_MD_AS_SHIFT,
    kLTC_ModeInit      = LTC_MD_AS_INITIALIZE << LTC_MD_AS_SHIFT,
    kLTC_ModeFinalize  = LTC_MD_AS_FINALIZE << LTC_MD_AS_SHIFT,
    kLTC_ModeInitFinal = LTC_MD_AS_INIT_FINAL << LTC_MD_AS_SHIFT
} ltc_mode_algorithm_state_t;

extern status_t ltc_get_context(LTC_Type *base, uint8_t *dest, uint8_t dataSize, uint8_t startIndex);
extern status_t ltc_set_context(LTC_Type *base, const uint8_t *data, uint8_t dataSize, uint8_t startIndex);
extern status_t ltc_symmetric_update(LTC_Type *base,
                                     const uint8_t *key,
                                     uint8_t keySize,
                                     ltc_algorithm_t alg,
                                     ltc_mode_symmetric_alg_t mode,
                                     ltc_mode_encrypt_t enc);
extern void ltc_memcpy(void *dst, const void *src, size_t size);
extern bool ltc_check_key_size(const uint32_t keySize);
extern status_t ltc_wait(LTC_Type *base);
extern void ltc_clear_all(LTC_Type *base, bool addPKHA);
#if defined(FSL_FEATURE_LTC_HAS_DES) && FSL_FEATURE_LTC_HAS_DES
extern status_t ltc_3des_check_input_args(ltc_mode_symmetric_alg_t modeAs,
                                          uint32_t size,
                                          const uint8_t *key1,
                                          const uint8_t *key2);
#endif /* FSL_FEATURE_LTC_HAS_DES */
extern void ltc_symmetric_process(LTC_Type *base, uint32_t inSize, const uint8_t **inData, uint8_t **outData);
extern status_t ltc_symmetric_process_data(LTC_Type *base, const uint8_t *inData, uint32_t inSize, uint8_t *outData);
/*!
 *@}
 */

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* _FSL_LTC_H_ */
