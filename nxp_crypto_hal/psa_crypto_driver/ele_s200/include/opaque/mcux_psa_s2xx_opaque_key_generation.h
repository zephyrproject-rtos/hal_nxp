/*
 * Copyright 2023, 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef MCUX_PSA_S2XX_OPAQUE_KEY_GENERATION_H
#define MCUX_PSA_S2XX_OPAQUE_KEY_GENERATION_H

/** \file mcux_psa_s2xx_opaque_key_generation.h
 *
 * This file contains the declaration of the entry points associated to the
 * key generation (i.e. random generation and extraction of public keys) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Import a key
 *
 * \param[in]     attributes        Attributes of the key to use
 * \param[in]     data              Buffer to hold the key data
 * \param[in]     data_length       Size in bytes of the input key data
 * \param[out]    key_buffer        Buffer to hold the imported key
 * \param[in]     key_buffer_size   Size in bytes of the key buffer
 * \param[out]    key_buffer_length Size in bytes of the imported key
 * \param[in,out] bits              Size in bits of the imported key
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ele_s2xx_opaque_import_key(const psa_key_attributes_t *attributes,
                                        const uint8_t *data,
                                        size_t data_length,
                                        uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        size_t *key_buffer_length,
                                        size_t *bits);

/*!
 * \brief Export the key from a private key.
 *
 * \param[in]  attributes      Attributes of the key to use
 * \param[in]  key_buffer      Buffer to hold the generated key
 * \param[in]  key_buffer_size Size in bytes of the key_buffer buffer
 * \param[out] data            Buffer to hold the extracted public key
 * \param[in]  data_size       Size in bytes of the data buffer
 * \param[out] data_length     Size in bytes of the extracted public key
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ele_s2xx_opaque_export_key(const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        uint8_t *data,
                                        size_t data_size,
                                        size_t *data_length);

/*!
 * \brief Export the public key from a private key.
 *
 * \param[in]  attributes      Attributes of the key to use
 * \param[in]  key_buffer      Buffer to hold the generated key
 * \param[in]  key_buffer_size Size in bytes of the key_buffer buffer
 * \param[out] data            Buffer to hold the extracted public key
 * \param[in]  data_size       Size in bytes of the data buffer
 * \param[out] data_length     Size in bytes of the extracted public key
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ele_s2xx_opaque_export_public_key(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               uint8_t *data,
                                               size_t data_size,
                                               size_t *data_length);

/*!
 * \brief Destroy a random key
 *
 * \param[in]  attributes        Attributes of the key to destroy
 * \param[out] key_buffer        Buffer for the key
 * \param[in]  key_buffer_size   Size in bytes of the key_buffer buffer

 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ele_s2xx_opaque_destroy_key(const psa_key_attributes_t *attributes,
                                         uint8_t *key_buffer,
                                         size_t key_buffer_size);

/*!
 * \brief Return the buffer size required by driver for storing key.
 *
 * \param[in] attributes defines the attributes associated with the input buffer
 * \param[in] data includes the input buffer as passed to the psa import function
 * \retval key_buffer_length is the required number of bytes required as
 *         key_buffer. size_t on success. 0 on failure
 */
size_t ele_s2xx_opaque_size_function(const psa_key_attributes_t *attributes,
                                     const uint8_t *data, size_t data_length);

/*!
 * \brief Return the buffer size required by driver for storing key.
 *
 * \param[in] attributes Attributes of the key
 * \retval The number of bytes required for storing the opaque key on success,
 *         0 on failure
 */
size_t ele_s2xx_opaque_get_key_buffer_size(const psa_key_attributes_t *attributes);

/*!
 * \brief Perform a key agreement and return the raw shared secret.
 *
 * \warning The raw result of a key agreement algorithm such as finite-field
 * Diffie-Hellman or elliptic curve Diffie-Hellman has biases and should
 * not be used directly as key material. It should instead be passed as
 * input to a key derivation algorithm. To chain a key agreement with
 * a key derivation, use psa_key_derivation_key_agreement() and other
 * functions from the key derivation interface.
 *
 * \param[in] attributes      Attributes of the key to use
 * \param[in] key_buffer      Buffer to hold the generated key
 * \param[in] key_buffer_size Size in bytes of the key_buffer buffer
 * \param[in] alg             The key agreement algorithm to compute
 *                            (\c PSA_ALG_XXX value such that
 *                            #PSA_ALG_IS_RAW_KEY_AGREEMENT(\p alg)
 *                            is true).
 * \param[in] peer_key              Public key of the peer. It must be
 *                                  in the same format that psa_import_key()
 *                                  accepts. The standard formats for public
 *                                  keys are documented in the documentation
 *                                  of psa_export_public_key().
 * \param[in]  peer_key_length      Size of \p peer_key in bytes.
 * \param[out] shared_secret        Buffer where the decrypted message is to
 *                                  be written.
 * \param[in]  shared_secret_size   Size of the \c output buffer in bytes.
 * \param[out] shared_secret_length On success, the number of bytes
 *                                  that make up the returned output.
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ele_s2xx_opaque_key_agreement(const psa_key_attributes_t *attributes,
                                           const uint8_t *key_buffer,
                                           size_t key_buffer_size,
                                           psa_algorithm_t alg,
                                           const uint8_t *peer_key,
                                           size_t peer_key_length,
                                           uint8_t *shared_secret,
                                           size_t shared_secret_size,
                                           size_t *shared_secret_length);

/*!
 * \brief Generate an opaque key
 *
 * The resulting key is an S200 die-unique key blob. After generating the key,
 * it is left cached in the S200.
 *
 * \param[in]  attributes        Attributes of the key to use
 * \param[in]  key_buffer        Buffer to hold the generated key
 * \param[in]  key_buffer_size   Size in bytes of the key_buffer buffer
 * \param[out] key_buffer_length Length in bytes of the generated opaque key
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_s2xx_opaque_generate_key(const psa_key_attributes_t *attributes,
                                          uint8_t *key_buffer,
                                          size_t key_buffer_size,
                                          size_t *key_buffer_length);

/*!
 * \brief Create a copy of an opaque key
 *
 * \note The PSA Core layer does not yet support location changes via the
 *       psa_copy_key() API. Until the PSA Core mechanisms for copying keys
 *       are finalized, this driver wrapper is provided only for making key
 *       copies within the same opaque key location - this operation is
 *       therefore a 1:1 copy of the opaque blob to a new buffer.
 *
 * \param[in]  attributes               Attributes of the new key
 * \param[in]  source_key               Buffer with the source key
 * \param[in]  source_key_length        Length in bytes of the source key
 * \param[out] target_key_buffer        Buffer to hold the copied key
 * \param[in]  target_key_buffer_size   Size on bytes of the taget key buffer
 * \param[out] target_key_buffer_length Length in bytes of the copied key
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_s2xx_opaque_copy_key(psa_key_attributes_t *attributes,
                                      const uint8_t *source_key,
                                      size_t source_key_length,
                                      uint8_t *target_key_buffer,
                                      size_t target_key_buffer_size,
                                      size_t *target_key_buffer_length);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_S2XX_OPAQUE_KEY_GENERATION_H */
