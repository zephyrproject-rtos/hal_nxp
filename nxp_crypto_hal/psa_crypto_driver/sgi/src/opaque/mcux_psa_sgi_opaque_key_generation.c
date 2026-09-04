/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  mcux_psa_sgi_opaque_key_generation.c
 * @brief PSA opaque-driver key-management entry points for
 *        multiple key locations.
 *
 * Architecture note:
 *   The crypto service runs within TF-M (SPE). Keys are stored in plaintext
 *   in Internal Trusted Storage (ITS) at runtime. Blob seal/unseal is only
 *   performed at the import/export boundary:
 *
 *   - Import: caller may provide plaintext or an encrypted blob.
 *     If blob: unseal to recover plaintext. Store plaintext in ITS.
 *   - Export: read plaintext from ITS, seal into DUK blob, return blob.
 *   - Generate: generate random key, store plaintext in ITS.
 *   - Crypto operations: key_buffer already contains plaintext.
 *
 * Dispatch model:
 *   Public entry points (sgi_opaque_import_key, sgi_opaque_export_key,
 *   sgi_opaque_generate_key, ...) are thin dispatchers that resolve the key
 *   location and delegate to the matching location-specific handler.
 *
 * Supported key types (initial set; extend as required):
 *   PSA_KEY_TYPE_AES          (128, 192, 256 bit)
 *   PSA_KEY_TYPE_HMAC         (any PSA-legal size)
 *   PSA_KEY_TYPE_RAW_DATA     (used by BLE IRK, arbitrary length)
 *   PSA_KEY_TYPE_ECC_KEY_PAIR (secp256r1 / secp384r1)
 */

#include <string.h>
#include "psa/crypto.h"

/* sgi_pkc headers */
#include <mcuxClRandom.h>
#include <mcuxClMemory_Clear.h>

/* Driver-local headers */
#include "mcux_psa_sgi_opaque_key_generation.h"
#include "mcux_psa_sgi_opaque_key_locations.h"
#include "mcux_psa_sgi_duk_blob.h"
#include "mcux_psa_sgi_common_init.h"
#include "mcux_psa_sgi_common_key_management.h" /* sgi_ecc_derive_public_key() */
#include "mcux_psa_sgi_entropy.h"     /* sgi_get_entropy() */

#include <mcuxClEcc.h>

/* SEC1 uncompressed point format tag (0x04 || X || Y). */
#define ECC_POINT_FORMAT_UNCOMPRESSED 0x04u

/* Workarea sizing for the on-chip public-key derivation (secured scalar
 * multiplication Q = d * G) used by sgi_opaque_export_public_key. */
#define SGI_OPAQUE_EXPORT_PUB_WACPU_SIZE                                      \
    (MCUXCLECC_ARITHMETICOPERATION_SECURESCALARMULT_WACPU_SIZE)
#define SGI_OPAQUE_EXPORT_PUB_WAPKC_SIZE                                      \
    (MCUXCLECC_ARITHMETICOPERATION_SECURESCALARMULT_WAPKC_SIZE_640)

/* Raw derived public key is X||Y, each coordinate up to
 * MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP bytes (the largest supported prime field).
 * The 0x04 SEC1 tag is prepended separately into the caller's output buffer. */
#define SGI_OPAQUE_EXPORT_MAX_RAW_POINT_SIZE (2u * MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP)

/* PSA internal - used for public key export from private key */
extern psa_status_t psa_export_public_key_internal(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    uint8_t *data, size_t data_size, size_t *data_length);
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * @brief Return the plaintext key size in bytes for supported key types.
 *
 * Converts the bit-length stored in @p attributes to bytes for unstructured
 * key types (AES, HMAC, RAW_DATA) and ECC key pairs.
 *
 * @param[in] attributes  PSA key attributes containing the key type and bit-length.
 *
 * @return Plaintext key size in bytes, or 0 if the key type is not supported.
 */
static size_t get_plain_key_size(const psa_key_attributes_t *attributes);

/**
 * @brief Extract the key location from PSA key attributes.
 *
 * Retrieves the key lifetime from @p attributes and extracts the
 * location component used to dispatch to the appropriate location-specific handler.
 *
 * @param[in] attributes  PSA key attributes containing the key lifetime.
 *
 * @return The key location identifier (psa_key_location_t).
 */
static inline psa_key_location_t get_location(const psa_key_attributes_t *attributes);
/* =========================================================================
 * Internal helpers
 * ========================================================================= */

static size_t get_plain_key_size(const psa_key_attributes_t *attributes)
{
    psa_key_type_t type = psa_get_key_type(attributes);
    size_t bits         = psa_get_key_bits(attributes);

    if (PSA_KEY_TYPE_IS_UNSTRUCTURED(type) || PSA_KEY_TYPE_IS_ECC_KEY_PAIR(type)) {
        return PSA_BITS_TO_BYTES(bits);
    }

    return 0u;
}

static inline psa_key_location_t get_location(const psa_key_attributes_t *attributes)
{
    return PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
}

/* =========================================================================
 * DUK blob location - import
 *   - If data is a DUK blob (matches blob size): unseal to plaintext, store.
 * ========================================================================= */

static psa_status_t sgi_opaque_duk_import_key(const psa_key_attributes_t *attributes,
                                              const uint8_t *data,
                                              size_t data_length,
                                              uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              size_t *key_buffer_length,
                                              size_t *bits)
{
    size_t expected_plain = get_plain_key_size(attributes);
    if (expected_plain == 0u) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Reject keys whose bit-length exceeds the PSA key-size ceiling. The PSA
     * core enforces "bits > PSA_MAX_KEY_BITS" from the value the driver import
     * entry reports */
    if (expected_plain > PSA_BITS_TO_BYTES(PSA_MAX_KEY_BITS)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (data_length == SGI_DUK_BLOB_SIZE(expected_plain)) {
        if (key_buffer_size < expected_plain) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }

        /* Unseal the blob to recover plaintext key, store plaintext in ITS */
        psa_status_t status;
        psa_key_attributes_t blob_attrs = PSA_KEY_ATTRIBUTES_INIT;

        status = sgi_duk_blob_unseal(&blob_attrs,
                                     data, data_length,
                                     key_buffer, key_buffer_size,
                                     key_buffer_length);
        if (PSA_SUCCESS != status) {
            return status;
        }

        if (bits != NULL) {
            *bits = psa_get_key_bits(attributes);
        }
        return PSA_SUCCESS;
    }

    /* Input size doesn't match any known format */
    return PSA_ERROR_INVALID_ARGUMENT;
}

/* =========================================================================
 * DUK blob location - export
 *
 * Seal the plaintext key (from ITS) into a DUK blob and return.
 * ========================================================================= */

static psa_status_t sgi_opaque_duk_export_key(const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              uint8_t *data,
                                              size_t data_size,
                                              size_t *data_length)
{
    /* key_buffer contains plaintext key. Seal it into a DUK blob for export. */
    return sgi_duk_blob_seal(attributes,
                             key_buffer, key_buffer_size,
                             data, data_size,
                             data_length);
}

/* =========================================================================
 * DUK blob location - generate
 *
 * Generate random key material, store plaintext in ITS.
 * ========================================================================= */

static psa_status_t sgi_opaque_duk_generate_key(const psa_key_attributes_t *attributes,
                                                uint8_t *key_buffer,
                                                size_t key_buffer_size,
                                                size_t *key_buffer_length)
{
    size_t plain_key_len = get_plain_key_size(attributes);
    if (plain_key_len == 0u) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (key_buffer_size < plain_key_len) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Generate random key directly into key_buffer (stored as plaintext in ITS) */
    size_t estimate_bits = 0u;
    psa_status_t status = sgi_get_entropy(0u, &estimate_bits, key_buffer, plain_key_len);
    if (PSA_SUCCESS != status) {
        return PSA_ERROR_INSUFFICIENT_ENTROPY;
    }

    *key_buffer_length = plain_key_len;
    return PSA_SUCCESS;
}

/* =========================================================================
 * sgi_opaque_import_key - thin dispatch layer
 * ========================================================================= */

psa_status_t sgi_opaque_import_key(const psa_key_attributes_t *attributes,
                                   const uint8_t *data,
                                   size_t data_length,
                                   uint8_t *key_buffer,
                                   size_t key_buffer_size,
                                   size_t *key_buffer_length,
                                   size_t *bits)
{
    psa_key_location_t location = get_location(attributes);

    if (MCUX_PSA_SGI_IS_DUK_BLOB_LOCATION(location)) {
        return sgi_opaque_duk_import_key(attributes, data, data_length,
                                         key_buffer, key_buffer_size,
                                         key_buffer_length, bits);
    }

    return PSA_ERROR_NOT_SUPPORTED;
}

/* =========================================================================
 * sgi_opaque_export_key - thin dispatch layer
 * ========================================================================= */

psa_status_t sgi_opaque_export_key(const psa_key_attributes_t *attributes,
                                   const uint8_t *key_buffer,
                                   size_t key_buffer_size,
                                   uint8_t *data,
                                   size_t data_size,
                                   size_t *data_length)
{
    psa_key_location_t location = get_location(attributes);

    if (MCUX_PSA_SGI_IS_DUK_BLOB_LOCATION(location)) {
        return sgi_opaque_duk_export_key(attributes, key_buffer, key_buffer_size,
                                         data, data_size, data_length);
    }

    return PSA_ERROR_NOT_SUPPORTED;
}

/* =========================================================================
 * sgi_opaque_export_public_key
 *
 * Key is already plaintext in ITS. Derive the public key directly.
 * ========================================================================= */

psa_status_t sgi_opaque_export_public_key(const psa_key_attributes_t *attributes,
                                          const uint8_t *key_buffer,
                                          size_t key_buffer_size,
                                          uint8_t *data,
                                          size_t data_size,
                                          size_t *data_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if ((NULL == attributes) || (NULL == key_buffer) || (0u == key_buffer_size) ||
        (NULL == data) || (0u == data_size) || (NULL == data_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_key_type_t key_type = psa_get_key_type(attributes);

    if (!PSA_KEY_TYPE_IS_ECC(key_type)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* An already-public key is stored in the PSA-standard SEC1 encoding
     * (0x04 || X || Y for Weierstrass). Copy it out unchanged. */
    if (true == PSA_KEY_TYPE_IS_PUBLIC_KEY(key_type)) {
        if (data_size < key_buffer_size) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
        (void) memcpy(data, key_buffer, key_buffer_size);
        *data_length = key_buffer_size;
        return PSA_SUCCESS;
    }

    if (!PSA_KEY_TYPE_IS_KEY_PAIR(key_type)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* key_buffer is the plaintext private scalar d (stored in ITS). Derive
     * the public key Q = d * G on-chip via a secured scalar multiplication. */
    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  SGI_OPAQUE_EXPORT_PUB_WACPU_SIZE,
                                                  SGI_OPAQUE_EXPORT_PUB_WAPKC_SIZE);

    /* The secured scalar multiplication requires an initialized PRNG. */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    uint8_t raw_point[SGI_OPAQUE_EXPORT_MAX_RAW_POINT_SIZE] = { 0u };
    size_t raw_point_length = 0u;

    status = sgi_ecc_derive_public_key(session,
                                       attributes,
                                       key_buffer,
                                       key_buffer_size,
                                       raw_point,
                                       sizeof(raw_point),
                                       &raw_point_length);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    if (0u == raw_point_length) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    /* PSA exports Weierstrass public keys in SEC1 uncompressed form
     * 0x04 || X || Y. Prepend the tag to the derived raw X||Y. */
    if (data_size < (raw_point_length + 1u)) {
        status = PSA_ERROR_BUFFER_TOO_SMALL;
        goto exit;
    }

    data[0] = ECC_POINT_FORMAT_UNCOMPRESSED;
    (void) memcpy(&data[1], raw_point, raw_point_length);
    *data_length = raw_point_length + 1u;
    status = PSA_SUCCESS;

exit:
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) ||
        (MCUXCLSESSION_STATUS_OK != result)) {
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

/* =========================================================================
 * sgi_opaque_generate_key - thin dispatch layer
 * ========================================================================= */

psa_status_t sgi_opaque_generate_key(const psa_key_attributes_t *attributes,
                                     uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length)
{
    psa_key_location_t location = get_location(attributes);

    if (MCUX_PSA_SGI_IS_DUK_BLOB_LOCATION(location)) {
        return sgi_opaque_duk_generate_key(attributes, key_buffer, key_buffer_size,
                                           key_buffer_length);
    }

    return PSA_ERROR_NOT_SUPPORTED;
}

/* =========================================================================
 * sgi_opaque_size_function  (called by PSA core for import buffer allocation)
 *
 * Returns the key-slot buffer size needed to store the key after import.
 * Since we store plaintext in ITS, return plaintext size regardless of
 * whether the input is plaintext or a blob.
 * ========================================================================= */

size_t sgi_opaque_size_function(const psa_key_attributes_t *attributes,
                                const uint8_t *data,
                                size_t data_length)
{
    size_t plain_key_len = get_plain_key_size(attributes);
    (void) data;
    (void) data_length;

    /* Key slot stores plaintext */
    return plain_key_len;
}

/* =========================================================================
 * sgi_opaque_get_key_buffer_size  (called by PSA core for generate/derive)
 *
 * Returns the key-slot buffer size needed to store a generated key.
 * Since we store plaintext in ITS, return plaintext size.
 * ========================================================================= */

size_t sgi_opaque_get_key_buffer_size(const psa_key_attributes_t *attributes)
{
    return get_plain_key_size(attributes);
}
