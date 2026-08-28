/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_SGI_DUK_BLOB_H
#define MCUX_PSA_SGI_DUK_BLOB_H

/**
 * @file  mcux_psa_sgi_duk_blob.h
 * @brief DUK-anchored AEAD blob format definitions and helper API used by the
 *        SGI opaque driver for PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE.
 *
 *   Blob format (28 bytes overhead + key_data_len):
 *   nonce[8] | AES-CCM( metadata[12] | key_data[N] ) | tag[8]
 *
 *   nonce     - 8 random bytes generated fresh for every seal operation.
 *   ciphertext - AES-CCM encryption of (metadata || plaintext key material).
 *   tag        - 8-byte AES-CCM authentication tag.
 *
 * Metadata layout (12 bytes):
 *
 *   offset  0 : uint32_t  key_alg    (psa_algorithm_t)
 *   offset  4 : uint32_t  key_usage  (psa_key_usage_t)
 *   offset  8 : uint16_t  key_type   (psa_key_type_t)
 *   offset 10 : uint16_t  key_bits   (key length in bits)
 *
 * Wrapping key:
 *   On platforms with MCUXCL_FEATURE_KEY_DERIVATION defined:
 *     A 256-bit Secure Storage Root Key (SSRK) is derived once per boot from
 *     the hardware DUK (SGI slots 6/7) using SP800-108 Counter-Mode CMAC.
 *
 *     CKDF input:
 *       label   = "NXP_SGI_SSRK"  (null-terminated, 13 bytes)
 *       context = device-specific constant (see mcux_psa_sgi_duk_blob.c)
 *       length  = 256 bits
 *
 *   On platforms without KDF support (MCUXCL_FEATURE_KEY_DERIVATION not defined):
 *     The DUK key in SGI slot 6/7 is used directly as the AES-CCM wrapping key.
 *     No derivation step is performed; sgi_ssrk_derive_if_needed() is a no-op.
 */

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Blob sizing constants
 * ------------------------------------------------------------------------- */

/** Maximum plaintext key material size (bytes) supported by seal/unseal.
 *  Covers AES-256 (32B), HMAC (up to 64B), ECC secp521r1 (66B), and
 *  leaves room for larger RAW_DATA. */
#define SGI_DUK_BLOB_MAX_KEY_SIZE     (256U)

/** Size of the randomly generated nonce prepended to every blob. */
#define SGI_DUK_BLOB_NONCE_SIZE       (8U)

/** Size of the AES-CCM authentication tag appended to every blob. */
#define SGI_DUK_BLOB_TAG_SIZE         (8U)

/** Size of the key-attribute metadata prepended to the plaintext before
 *  encryption (see field layout above). */
#define SGI_DUK_BLOB_METADATA_SIZE    (12U)

/**
 * Total overhead added by the blob format on top of raw key material:
 *   nonce(8) + metadata(12) + tag(8) = 28 bytes.
 */
#define SGI_DUK_BLOB_OVERHEAD \
        (SGI_DUK_BLOB_NONCE_SIZE + SGI_DUK_BLOB_METADATA_SIZE + SGI_DUK_BLOB_TAG_SIZE)

/** Compute the blob storage size needed for a key of @p key_data_len bytes. */
#define SGI_DUK_BLOB_SIZE(key_data_len) \
        ((key_data_len) + (size_t) SGI_DUK_BLOB_OVERHEAD)

/* -------------------------------------------------------------------------
 * Metadata field layout within the plaintext (before encryption)
 * ------------------------------------------------------------------------- */

/** Byte offsets within the 12-byte metadata block. */
#define SGI_DUK_META_OFFSET_ALG       (0U)   /**< uint32_t psa_algorithm_t   */
#define SGI_DUK_META_OFFSET_USAGE     (4U)   /**< uint32_t psa_key_usage_t   */
#define SGI_DUK_META_OFFSET_TYPE      (8U)   /**< uint16_t psa_key_type_t    */
#define SGI_DUK_META_OFFSET_BITS      (10U)  /**< uint16_t key length (bits) */

/* -------------------------------------------------------------------------
 * Public API: blob seal / unseal
 *
 * Both functions rely on the SSRK being already derived and cached in the
 * module-internal RAM slot (sgi_ssrk_derive_if_needed()).
 * ------------------------------------------------------------------------- */

/**
 * @brief Seal (encrypt + authenticate) plaintext key material into a DUK blob.
 *
 * @param[in]  attributes      PSA key attributes - encoded into the blob metadata.
 * @param[in]  key_data        Plaintext key material to protect.
 * @param[in]  key_data_len    Length of @p key_data in bytes.
 * @param[out] blob            Output buffer for the sealed blob.
 * @param[in]  blob_size       Size of @p blob in bytes; must be >=
 *                             SGI_DUK_BLOB_SIZE(key_data_len).
 * @param[out] blob_length     Set to the actual number of bytes written to @p blob.
 *
 * @retval PSA_SUCCESS                   Blob sealed successfully.
 * @retval PSA_ERROR_BUFFER_TOO_SMALL    @p blob_size is too small.
 * @retval PSA_ERROR_HARDWARE_FAILURE    SGI/AEAD operation failed.
 * @retval PSA_ERROR_INSUFFICIENT_ENTROPY RNG failed while generating nonce.
 */
psa_status_t sgi_duk_blob_seal(const psa_key_attributes_t *attributes,
                               const uint8_t *key_data,
                               size_t key_data_len,
                               uint8_t *blob,
                               size_t blob_size,
                               size_t *blob_length);

/**
 * @brief Unseal (authenticate + decrypt) a DUK blob into plaintext key material.
 *
 * On success the key attributes (algorithm, usage, type, bits) are populated
 * from the blob metadata into @p attributes. The blob is the source of truth
 * for key properties - this allows the caller to fully recreate the key from
 * the blob without needing to know the original attributes beforehand.
 *
 * @param[out] attributes      PSA key attributes set from blob metadata on success.
 *                             May be NULL if caller does not need them.
 * @param[in]  blob            The sealed blob as produced by sgi_duk_blob_seal().
 * @param[in]  blob_len        Length of @p blob in bytes.
 * @param[out] key_data        Output buffer for the recovered plaintext key.
 * @param[in]  key_data_size   Size of @p key_data in bytes.
 * @param[out] key_data_len    Set to the number of plaintext key bytes written.
 *
 * @retval PSA_SUCCESS                Blob unsealed and attributes populated.
 * @retval PSA_ERROR_INVALID_ARGUMENT @p blob too small or corrupted metadata.
 * @retval PSA_ERROR_INVALID_SIGNATURE AES-CCM tag verification failed (tampered blob).
 * @retval PSA_ERROR_BUFFER_TOO_SMALL @p key_data_size too small.
 * @retval PSA_ERROR_HARDWARE_FAILURE SGI/AEAD operation failed.
 */
psa_status_t sgi_duk_blob_unseal(psa_key_attributes_t *attributes,
                                 const uint8_t *blob,
                                 size_t blob_len,
                                 uint8_t *key_data,
                                 size_t key_data_size,
                                 size_t *key_data_len);

/* -------------------------------------------------------------------------
 * SSRK management
 * ------------------------------------------------------------------------- */

/**
 * @brief Derive (once per boot) and cache the 256-bit Secure Storage Root Key.
 *
 * Uses CKDF-CMAC on the DUK (SGI slots 6/7) with a fixed label/context.
 * Idempotent - safe to call multiple times; derivation is performed only on
 * the first invocation after reset.
 *
 * Must be called before sgi_duk_blob_seal() or sgi_duk_blob_unseal().
 *
 * @retval PSA_SUCCESS             SSRK is ready.
 * @retval PSA_ERROR_HARDWARE_FAILURE  CKDF or key-load operation failed.
 */
psa_status_t sgi_ssrk_derive_if_needed(void);

/**
 * @brief Zeroize the cached SSRK (e.g., on psa_crypto_deinit()).
 */
void sgi_ssrk_zeroize(void);


#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_SGI_DUK_BLOB_H */
