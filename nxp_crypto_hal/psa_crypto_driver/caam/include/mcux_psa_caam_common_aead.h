/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_CAAM_COMMON_AEAD_H
#define MCUX_CAAM_COMMON_AEAD_H

/** \file mcux_caam_common_aead.h
 *
 * This file contains the declaration of the entry points associated to the
 * generic_aead capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_caam_init.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Encrypt and authenticate with an AEAD algorithm in one-shot
 *
 * \param[in]  caam_key_type          CAAM key encryption type.
 * \param[in]  attributes             Attributes of the key to use
 * \param[in]  key_buffer             Key material buffer
 * \param[in]  key_buffer_size        Size in bytes of the key
 * \param[in]  alg                    Algorithm to use
 * \param[in]  nonce                  Nonce buffer
 * \param[in]  nonce_length           Size in bytes of the nonce
 * \param[in]  additional_data        Data to authenticate buffer
 * \param[in]  additional_data_length Size in bytes of additional_data
 * \param[in]  plaintext              Data to encrypt buffer
 * \param[in]  plaintext_length       Size in bytes of the data to encrypt
 * \param[out] ciphertext             Buffer to hold the encrypted data
 * \param[in]  ciphertext_size        Size in bytes of the ciphertext buffer
 * \param[out] ciphertext_length      Size in bytes of the encrypted data
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t caam_common_aead_encrypt(mcux_psa_caam_key_type_t caam_key_type,
                                      const psa_key_attributes_t *attributes,
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
 * \param[in]  caam_key_type          CAAM key encryption type.
 * \param[in]  attributes             Attributes of the key to use
 * \param[in]  key_buffer             Key material buffer
 * \param[in]  key_buffer_size        Size in bytes of the key
 * \param[in]  alg                    Algorithm to use
 * \param[in]  nonce                  Nonce buffer
 * \param[in]  nonce_length           Size in bytes of the nonce
 * \param[in]  additional_data        Data to authenticate buffer
 * \param[in]  additional_data_length Size in bytes of additional_data
 * \param[in]  ciphertext             Data to decrypt buffer
 * \param[in]  ciphertext_length      Size in bytes of the data to decrypt
 * \param[out] plaintext              Buffer to hold the decrypted data
 * \param[in]  plaintext_size         Size in bytes of the plaintext buffer
 * \param[out] plaintext_length       Size in bytes of the decrypted data
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t caam_common_aead_decrypt(mcux_psa_caam_key_type_t caam_key_type,
                                      const psa_key_attributes_t *attributes,
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
#endif /* MCUX_CAAM_COMMON_AEAD_H */
