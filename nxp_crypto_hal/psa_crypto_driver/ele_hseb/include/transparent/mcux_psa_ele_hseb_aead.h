/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_AEAD_H
#define MCUX_PSA_ELE_HSEB_AEAD_H

/** \file mcux_psa_ele_hseb_aead.h
 *
 * This file contains the declaration of the entry points associated to the
 * aead capability (single-part) as described by the PSA Cryptoprocessor
 * Driver interface specification.
 */

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Encrypt and authenticate with an AEAD algorithm in one-shot
 *
 * Supported algorithms: PSA_ALG_GCM, PSA_ALG_CCM (with AES key).
 * The authentication tag is appended to the ciphertext in the output buffer.
 *
 * \param[in]  attributes             Attributes of the key to use
 * \param[in]  key_buffer             Buffer holding key material
 * \param[in]  key_buffer_size        Size in bytes of the key
 * \param[in]  alg                    AEAD algorithm to use
 * \param[in]  nonce                  Nonce/IV buffer
 * \param[in]  nonce_length           Size in bytes of the nonce
 * \param[in]  additional_data        Additional data to authenticate
 * \param[in]  additional_data_length Size in bytes of additional_data
 * \param[in]  plaintext              Data to encrypt
 * \param[in]  plaintext_length       Size in bytes of the plaintext
 * \param[out] ciphertext             Buffer to hold ciphertext followed by tag
 * \param[in]  ciphertext_size        Size in bytes of the ciphertext buffer
 * \param[out] ciphertext_length      Size in bytes written to ciphertext
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ele_hseb_transparent_aead_encrypt(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               psa_algorithm_t alg,
                                               const uint8_t *nonce,
                                               size_t nonce_length,
                                               const uint8_t *additional_data,
                                               size_t additional_data_length,
                                               const uint8_t *plaintext,
                                               size_t plaintext_length,
                                               uint8_t *ciphertext,
                                               size_t ciphertext_size,
                                               size_t *ciphertext_length);

/*!
 * \brief Decrypt and verify tag with an AEAD algorithm in one-shot
 *
 * Supported algorithms: PSA_ALG_GCM, PSA_ALG_CCM (with AES key).
 * The authentication tag is expected to be appended to the ciphertext input.
 *
 * \param[in]  attributes             Attributes of the key to use
 * \param[in]  key_buffer             Buffer holding key material
 * \param[in]  key_buffer_size        Size in bytes of the key
 * \param[in]  alg                    AEAD algorithm to use
 * \param[in]  nonce                  Nonce/IV buffer
 * \param[in]  nonce_length           Size in bytes of the nonce
 * \param[in]  additional_data        Additional data to authenticate
 * \param[in]  additional_data_length Size in bytes of additional_data
 * \param[in]  ciphertext             Buffer holding ciphertext followed by tag
 * \param[in]  ciphertext_length      Size in bytes of the ciphertext (including tag)
 * \param[out] plaintext              Buffer to hold the decrypted data
 * \param[in]  plaintext_size         Size in bytes of the plaintext buffer
 * \param[out] plaintext_length       Size in bytes written to plaintext
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ele_hseb_transparent_aead_decrypt(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               psa_algorithm_t alg,
                                               const uint8_t *nonce,
                                               size_t nonce_length,
                                               const uint8_t *additional_data,
                                               size_t additional_data_length,
                                               const uint8_t *ciphertext,
                                               size_t ciphertext_length,
                                               uint8_t *plaintext,
                                               size_t plaintext_size,
                                               size_t *plaintext_length);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_AEAD_H */
