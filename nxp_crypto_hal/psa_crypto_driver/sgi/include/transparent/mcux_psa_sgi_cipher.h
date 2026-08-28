/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_SGI_CIPHER_H
#define MCUX_PSA_SGI_CIPHER_H

/** \file mcux_psa_sgi_psa_cipher.h
 *
 * This file contains the declaration of the entry points associated to the
 * cipher capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_sgi_common_init.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Perform a one-shot encryption operation
 *
 * \param[in]  attributes      Key attributes
 * \param[in]  key_buffer      Buffer holding key material
 * \param[in]  key_buffer_size Size in bytes of the key
 * \param[in]  alg             Algorithm to be used for which
 *                             PSA_ALG_IS_CIPHER(alg) is true
 * \param[in]  iv              Buffer containing the initialisation vector
 * \param[in]  iv_length       Size in bytes of the iv buffer
 * \param[in]  input           Buffer holding the plaintext
 * \param[in]  input_length    Size in bytes of the plaintext
 * \param[out] output          Buffer holding the ciphertext
 * \param[in]  output_size     Size in bytes of the output buffer
 * \param[out] output_length   Size in bytes of the encrypted data
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_encrypt(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *iv,
                                            size_t iv_length,
                                            const uint8_t *input,
                                            size_t input_length,
                                            uint8_t *output,
                                            size_t output_size,
                                            size_t *output_length);
/*!
 * \brief Perform a one-shot decryption operation
 *
 * \param[in]  attributes      Key attributes
 * \param[in]  key_buffer      Buffer holding key material
 * \param[in]  key_buffer_size Size in bytes of the key
 * \param[in]  alg             Algorithm to be used for which
 *                             PSA_ALG_IS_CIPHER(alg) is true
 * \param[in]  input           Buffer holding the ciphertext
 * \param[in]  input_length    Size in bytes of the ciphertext
 * \param[out] output          Buffer holding the ciphertext
 * \param[in]  output_size     Size in bytes of the output buffer
 * \param[out] output_length   Size in bytes of the decrypted data
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_decrypt(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *input,
                                            size_t input_length,
                                            uint8_t *output,
                                            size_t output_size,
                                            size_t *output_length);

/*!
 * \brief Perform the setup step for a multipart cipher encrypt operation
 *
 * \param[in,out] operation       Multipart operation context
 * \param[in]     attributes      Key attributes
 * \param[in]     key_buffer      Buffer holding key material
 * \param[in]     key_buffer_size Size in bytes of the key
 * \param[in]     alg             Algorithm to be used for which
 *                                PSA_ALG_IS_CIPHER(alg) is true
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_encrypt_setup(
    sgi_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg);

/*!
 * \brief Perform the setup step for a multipart cipher decrypt operation
 *
 * \param[in,out] operation       Multipart operation context
 * \param[in]     attributes      Key attributes
 * \param[in]     key_buffer      Buffer holding key material
 * \param[in]     key_buffer_size Size in bytes of the key
 * \param[in]     alg             Algorithm to be used for which
 *                                PSA_ALG_IS_CIPHER(alg) is true
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_decrypt_setup(
    sgi_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg);

/*!
 * \brief Set the initialization vector (IV) for a symmetric cipher operation
 *
 * \param[in,out] operation Multipart operation context
 * \param[in]     iv        Buffer holding the initialization vector
 * \param[in]     iv_length Size in bytes of the initialization vector
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_set_iv(sgi_cipher_operation_t *operation,
                                           const uint8_t *iv,
                                           size_t iv_length);

/*!
 * \brief Encrypt or decrypt a message fragment in an active cipher operation
 *
 * \param[in,out] operation     Multipart operation context
 * \param[in]     input         Buffer holding the plaintext
 * \param[in]     input_length  Size in bytes of the plaintext
 * \param[out]    output        Buffer holding the ciphertext
 * \param[in]     output_size   Size in bytes of the output buffer
 * \param[out]    output_length Size in bytes of the encrypted data
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_update(sgi_cipher_operation_t *operation,
                                           const uint8_t *input,
                                           size_t input_length,
                                           uint8_t *output,
                                           size_t output_size,
                                           size_t *output_length);

/*!
 * \brief Finish encrypting or decrypting a message in a cipher operation
 *
 * \param[in,out] operation     Multipart operation context
 * \param[out]    output        Buffer holding the ciphertext
 * \param[in]     output_size   Size in bytes of the output buffer
 * \param[out]    output_length Size in bytes of the encrypted data
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_finish(sgi_cipher_operation_t *operation,
                                           uint8_t *output,
                                           size_t output_size,
                                           size_t *output_length);

/*!
 * \brief Abort a cipher operation
 *
 * \param[in,out] operation Multipart operation context
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t sgi_transparent_cipher_abort(sgi_cipher_operation_t *operation);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_SGI_CIPHER_H */
