/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_OPAQUE_KEY_GENERATION_H
#define MCUX_PSA_ELE_HSEB_OPAQUE_KEY_GENERATION_H

/** \file mcux_psa_ele_hseb_opaque_key_generation.h
 *
 * This file contains the declaration of the entry points associated to the
 * key generation as described by the PSA Cryptoprocessor Driver interface
 * specification.
 */

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Generate an opaque key inside the HSE-B keystore.
 *
 * The key is generated entirely inside HSE-B and never leaves the hardware
 * in plaintext. On success, \p key_buffer receives the HSE key handle that
 * identifies the generated key slot. Supported key types are AES, HMAC,
 * ECC key pairs, and RSA key pairs (NVM location only for RSA).
 *
 * \param[in]  attributes        Attributes of the key to generate.
 * \param[out] key_buffer        Buffer to receive the opaque key handle.
 * \param[in]  key_buffer_size   Size in bytes of \p key_buffer.
 * \param[out] key_buffer_length On success, set to the number of bytes
 *                               written into \p key_buffer.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_generate_key(const psa_key_attributes_t *attributes,
                                          uint8_t *key_buffer,
                                          size_t key_buffer_size,
                                          size_t *key_buffer_length);

/**
 * \brief Return the buffer size required to store an HSE-B opaque key,
 *        taking the input key data into account.
 *
 * This is the size-function variant that receives the raw key data buffer
 * (as passed to the PSA import path). For HSE-B cached locations the result
 * is independent of \p data and \p data_length and equals
 * \c sizeof(hseKeyHandle_t).
 *
 * \param[in] attributes  Attributes of the key whose buffer size is queried.
 * \param[in] data        Input key data buffer.
 * \param[in] data_length Length in bytes of \p data.
 *
 * \retval The number of bytes required to store the opaque key on success,
 *         0 on failure.
 */
size_t ele_hseb_opaque_size_function(const psa_key_attributes_t *attributes,
                                     const uint8_t *data,
                                     size_t data_length);

/**
 * \brief Return the buffer size required to store an HSE-B opaque key.
 *
 * The opaque key buffer for HSE-B holds an \c hseKeyHandle_t value. This
 * function returns the appropriate size for that handle, derived from the
 * key attributes, so that the PSA core can allocate a correctly sized buffer
 * before calling \ref ele_hseb_opaque_generate_key or the import entry point.
 *
 * \param[in] attributes Attributes of the key whose buffer size is queried.
 *
 * \retval The number of bytes required to store the opaque key handle on
 *         success, 0 on failure.
 */
size_t ele_hseb_opaque_get_key_buffer_size(const psa_key_attributes_t *attributes);

/**
 * \brief Import key material into the HSE-B keystore.
 *
 * At this time, the function takes raw key material and transforms it
 * into an opaque key. No other flow is currently available.
 *
 * Allocates a key slot inside HSE-B and loads the caller-supplied plaintext
 * key material into it. On success, \p key_buffer receives the HSE key handle
 * that identifies the imported key slot. Supported key types are AES, HMAC,
 * and ECC.
 *
 * \param[in]  attributes        Attributes of the key to import.
 * \param[in]  data              Buffer containing the key material to import.
 * \param[in]  data_length       Length in bytes of \p data.
 * \param[out] key_buffer        Buffer to receive output key material.
 * \param[in]  key_buffer_size   Size in bytes of \p key_buffer.
 * \param[out] key_buffer_length On success, set to the number of bytes
 *                               written into \p key_buffer.
 * \param[out] bits              On success, set to the key size in bits as
 *                               determined from \p data.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_import_key(const psa_key_attributes_t *attributes,
                                        const uint8_t *data,
                                        size_t data_length,
                                        uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        size_t *key_buffer_length,
                                        size_t *bits);

/**
 * \brief Export the public part of an HSE-B opaque asymmetric key.
 *
 * Export the public key associated with the opaque key identified by
 * \p key_buffer and writes it to \p data.
 *
 * \param[in]  attributes      Attributes of the key to export.
 * \param[in]  key_buffer      Buffer holding the opaque key material.
 * \param[in]  key_buffer_size Size in bytes of \p key_buffer.
 * \param[out] data            Buffer to receive the exported public key.
 * \param[in]  data_size       Size in bytes of \p data.
 * \param[out] data_length     On success, set to the number of bytes written
 *                             into \p data.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_export_public_key(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               uint8_t *data,
                                               size_t data_size,
                                               size_t *data_length);

/**
 * \brief Destroy an opaque key held in the HSE-B keystore.
 *
 * If applicable, erases the HSE-B key slot identified by the handle stored
 * in \p key_buffer and releases the slot back to the allocator.
 * On success, \p key_buffer is zeroed.
 *
 * \param[in]     attributes      Attributes of the key to destroy.
 * \param[in,out] key_buffer      Buffer holding the opaque key material.
 * \param[in]     key_buffer_size Size in bytes of \p key_buffer.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_destroy_key(const psa_key_attributes_t *attributes,
                                         uint8_t *key_buffer,
                                         size_t key_buffer_size);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_OPAQUE_KEY_GENERATION_H */
