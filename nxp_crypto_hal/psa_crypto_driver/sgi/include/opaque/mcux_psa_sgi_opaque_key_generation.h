/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_SGI_OPAQUE_KEY_GENERATION_H
#define MCUX_PSA_SGI_OPAQUE_KEY_GENERATION_H

/**
 * @file  mcux_psa_sgi_opaque_key_generation.h
 * @brief PSA opaque-driver entry points for key management operations at
 *        PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE.
 *
 * In the TF-M architecture, keys at this location are stored as plaintext
 * in ITS at runtime.  DUK blob seal/unseal is performed only at the
 * import/export boundaries:
 *
 *   - import_key     : accepts plaintext or DUK blob; stores plaintext in ITS.
 *   - generate_key   : generates random key; stores plaintext in ITS.
 *   - export_key     : seals plaintext into a DUK blob and returns the blob.
 *   - destroy_key    : zeroizes the in-memory plaintext key buffer.
 *   - get_key_buffer_size / size_function : return plaintext key size for ITS.
 *
 */

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Import a key into PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE.
 *
 * Accepts either plaintext key material or a previously exported DUK blob.
 * If the input is a blob (detected by size = plaintext + 28 bytes overhead),
 * it is unsealed first.  The resulting plaintext is stored in @p key_buffer
 * for ITS persistence.
 *
 * @param[in]     attributes        Key attributes (type, bits, usage, algorithm).
 * @param[in]     data              Plaintext key material or DUK blob.
 * @param[in]     data_length       Length of @p data in bytes.
 * @param[out]    key_buffer        Buffer to hold the plaintext key for ITS.
 * @param[in]     key_buffer_size   Size of @p key_buffer.
 * @param[out]    key_buffer_length Actual bytes written to @p key_buffer.
 * @param[out]    bits              Key size in bits (updated if not already set).
 *
 * @retval PSA_SUCCESS on success.
 * @retval PSA_ERROR_INVALID_ARGUMENT  Input data size does not match key type.
 * @retval PSA_ERROR_INVALID_SIGNATURE DUK blob authentication failed (if blob).
 */
psa_status_t sgi_opaque_import_key(const psa_key_attributes_t *attributes,
                                   const uint8_t *data,
                                   size_t data_length,
                                   uint8_t *key_buffer,
                                   size_t key_buffer_size,
                                   size_t *key_buffer_length,
                                   size_t *bits);

/**
 * @brief Export a key from PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE.
 *
 * Seals the plaintext key (from ITS) into a DUK blob using AES-CCM with
 * the device-unique SSRK and returns the blob.  The caller is responsible
 * for persisting the blob externally and re-importing it when needed.
 *
 * @param[in]  attributes       Key attributes.
 * @param[in]  key_buffer       Plaintext key material (from ITS).
 * @param[in]  key_buffer_size  Size of @p key_buffer.
 * @param[out] data             Buffer to receive the exported DUK blob.
 * @param[in]  data_size        Size of @p data.
 * @param[out] data_length      Actual bytes written to @p data.
 *
 * @retval PSA_SUCCESS on success.
 * @retval PSA_ERROR_NOT_PERMITTED if PSA_KEY_USAGE_EXPORT is not set.
 * @retval PSA_ERROR_BUFFER_TOO_SMALL if @p data_size < plaintext + 28.
 */
psa_status_t sgi_opaque_export_key(const psa_key_attributes_t *attributes,
                                   const uint8_t *key_buffer,
                                   size_t key_buffer_size,
                                   uint8_t *data,
                                   size_t data_size,
                                   size_t *data_length);

/**
 * @brief Export the public key component from an opaque asymmetric key.
 *
 * The key_buffer contains the plaintext private key (stored in ITS).
 * Derives the public key via PKC and returns it in uncompressed format
 * (0x04 || X || Y for ECC curves).
 *
 * @param[in]  attributes       Key attributes.
 * @param[in]  key_buffer       Plaintext private key material (from ITS).
 * @param[in]  key_buffer_size  Size of @p key_buffer.
 * @param[out] data             Buffer to receive the public key.
 * @param[in]  data_size        Size of @p data.
 * @param[out] data_length      Actual bytes written to @p data.
 *
 * @retval PSA_SUCCESS on success.
 * @retval PSA_ERROR_NOT_SUPPORTED for non-asymmetric key types.
 */
psa_status_t sgi_opaque_export_public_key(const psa_key_attributes_t *attributes,
                                          const uint8_t *key_buffer,
                                          size_t key_buffer_size,
                                          uint8_t *data,
                                          size_t data_size,
                                          size_t *data_length);

/**
 * @brief Generate a random key into PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE.
 *
 * Uses psa_generate_random() (backed by the SGI TRNG) to obtain key bytes.
 * The plaintext key is stored directly in @p key_buffer for ITS persistence.
 * No blob sealing is performed at generation time.
 *
 * @param[in]  attributes        Key attributes (type, bits, usage, algorithm).
 * @param[out] key_buffer        Buffer to hold the generated plaintext key.
 * @param[in]  key_buffer_size   Size of @p key_buffer.
 * @param[out] key_buffer_length Actual bytes written to @p key_buffer.
 *
 * @retval PSA_SUCCESS on success.
 * @retval PSA_ERROR_NOT_SUPPORTED for unsupported key types.
 */
psa_status_t sgi_opaque_generate_key(const psa_key_attributes_t *attributes,
                                     uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length);

/**
 * @brief Return the required @p key_buffer size for an import operation.
 *
 * Called by the PSA core before allocating key storage for import.
 * Returns the plaintext key size (ITS stores plaintext at runtime).
 *
 * @param[in] attributes   Key attributes.
 * @param[in] data         Input key material (plaintext or blob).
 * @param[in] data_length  Length of @p data.
 *
 * @return Required key_buffer size in bytes (plaintext size), or 0 on error.
 */
size_t sgi_opaque_size_function(const psa_key_attributes_t *attributes,
                                const uint8_t *data,
                                size_t data_length);

/**
 * @brief Return the required @p key_buffer size for a generate/derive operation.
 *
 * Called by the PSA core before allocating key storage for key generation.
 * Returns the plaintext key size (ITS stores plaintext at runtime).
 *
 * @param[in] attributes  Key attributes.
 *
 * @return Required key_buffer size in bytes (plaintext size), or 0 on unsupported type/size.
 */
size_t sgi_opaque_get_key_buffer_size(const psa_key_attributes_t *attributes);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_SGI_OPAQUE_KEY_GENERATION_H */
