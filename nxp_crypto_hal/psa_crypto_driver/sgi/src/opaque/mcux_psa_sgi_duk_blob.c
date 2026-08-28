/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  mcux_psa_sgi_duk_blob.c
 * @brief DUK-anchored AES-CCM blob seal / unseal and SSRK derivation.
 *
 * SSRK derivation (conditional on MCUXCL_FEATURE_KEY_DERIVATION)
 * On platforms without KDF support, DUK is used directly as wrapping key.
 *
 * Blob format (28 bytes overhead + key_data_len):
 *   nonce[8] | AES-CCM( metadata[12] | key_data[N] ) | tag[8]
 *
 * Metadata (12 bytes):
 *   [0..3]   key_alg   (psa_algorithm_t)
 *   [4..7]   key_usage (psa_key_usage_t)
 *   [8..9]   key_type  (psa_key_type_t)
 *   [10..11] key_bits  (uint16_t)
 */

#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxClKey_Functions.h>
#include <mcuxClKey_Types.h>
#include <mcuxClAead.h>
#include <mcuxClAead_Functions.h>
#include <mcuxClAeadModes.h>
#include <mcuxClAeadModes_Modes.h>
#include <mcuxClAes.h>
#if defined(MCUXCL_FEATURE_KEY_DERIVATION)
#include <mcuxClKdfModes.h>
#include <mcuxClKdfModes_Algorithms_NIST_SP800_108.h>
#include <mcuxClMacModes.h>
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */
#include <mcuxClMemory_Clear.h>
#include <mcuxClExample_Session_Helper.h>
#include <mcuxClExample_RNG_Helper.h>

/* PSA headers */
#include "psa/crypto.h"

/* Driver-local headers */
#include "mcux_psa_sgi_duk_blob.h"
#include "mcux_psa_sgi_entropy.h"     /* sgi_get_entropy() */
#include "mcux_psa_sgi_common_init.h" /* sgi_hwcrypto_mutex */

/* =========================================================================
 * Module-private state
 * ========================================================================= */

#if defined(MCUXCL_FEATURE_KEY_DERIVATION)
static uint8_t s_ssrk[32u];
static bool    s_ssrk_valid = false;

static const uint8_t k_ssrk_label[] = "NXP_SGI_SSRK";
#define K_SSRK_LABEL_LEN  (sizeof(k_ssrk_label))

static const uint8_t k_ssrk_context[16u] = { 0u };
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */

/* =========================================================================
 * Internal: blob metadata encode
 * ========================================================================= */
/* Encode metadata into structure used by DUK blob
 * metadata[12] = (key_alg | key_usage_flags | key_type |key_bits) */

static void encode_metadata(const psa_key_attributes_t *attributes,
                            uint8_t metadata[SGI_DUK_BLOB_METADATA_SIZE])
{
    psa_algorithm_t key_alg         = psa_get_key_algorithm(attributes);
    psa_key_usage_t key_usage_flags = psa_get_key_usage_flags(attributes);
    psa_key_type_t  key_type        = psa_get_key_type(attributes);
    psa_key_bits_t  key_bits        = (psa_key_bits_t) psa_get_key_bits(attributes);

    metadata[0]  = (uint8_t) (key_alg >> 24u);
    metadata[1]  = (uint8_t) (key_alg >> 16u);
    metadata[2]  = (uint8_t) (key_alg >>  8u);
    metadata[3]  = (uint8_t) (key_alg);
    metadata[4]  = (uint8_t) (key_usage_flags >> 24u);
    metadata[5]  = (uint8_t) (key_usage_flags >> 16u);
    metadata[6]  = (uint8_t) (key_usage_flags >>  8u);
    metadata[7]  = (uint8_t) (key_usage_flags);
    metadata[8]  = (uint8_t) (key_type >> 8u);
    metadata[9]  = (uint8_t) (key_type);
    metadata[10] = (uint8_t) (key_bits >> 8u);
    metadata[11] = (uint8_t) (key_bits);
}

static psa_status_t decode_metadata(
    psa_key_attributes_t *attributes,
    const uint8_t metadata[SGI_DUK_BLOB_METADATA_SIZE])
{
    /* Parse metadata from blob - blob is the source of truth */
    psa_algorithm_t key_alg = ((uint32_t) metadata[0] << 24) |
                              ((uint32_t) metadata[1] << 16) |
                              ((uint32_t) metadata[2] << 8) |
                              ((uint32_t) metadata[3]);

    psa_key_usage_t key_usage_flags = ((uint32_t) metadata[4] << 24) |
                                      ((uint32_t) metadata[5] << 16) |
                                      ((uint32_t) metadata[6] << 8) |
                                      ((uint32_t) metadata[7]);

    psa_key_type_t key_type = ((uint16_t) metadata[8] << 8) |
                              ((uint16_t) metadata[9]);

    psa_key_bits_t key_bits = ((uint16_t) metadata[10] << 8) |
                              ((uint16_t) metadata[11]);

    /* Basic validity check, key_type and key_bits must be non-zero */
    if (key_type == 0u || key_bits == 0u) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Set the attributes from blob metadata so caller can use the key */
    psa_set_key_algorithm(attributes, key_alg);
    psa_set_key_usage_flags(attributes, key_usage_flags);
    psa_set_key_type(attributes, key_type);
    psa_set_key_bits(attributes, (size_t) key_bits);

    return PSA_SUCCESS;
}

/* =========================================================================
 * Prepare keyhandle which could be used to do operations with DUK which is loaded by ROM into key slot 6 & 7
 * ========================================================================= */

static psa_status_t sgi_load_duk_key(mcuxClSession_Handle_t session,
                                     mcuxClKey_Handle_t     DukKey)
{
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(kiKwk_status,
                                     kiKwk_token,
                                     mcuxClKey_init(
                                         /* mcuxClSession_Handle_t session:        */ session,
                                         /* mcuxClKey_Handle_t key:                */ DukKey,
                                         /* mcuxClKey_Type_t type:                 */
                                         mcuxClKey_Type_Aes256,
                                         /* uint8_t * pKeyData:                   */ (uint8_t *)
                                         NULL,
                                         /* not needed, key is already loaded */
                                         /* uint32_t keyDataLength:               */ 0u /* not needed, key is already loaded */)
                                     );

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != kiKwk_token) ||
        (MCUXCLKEY_STATUS_OK != kiKwk_status)) {
        return PSA_ERROR_HARDWARE_FAILURE;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(klKwk_status, klKwk_token, mcuxClKey_loadCopro(
                                         /* mcuxClSession_Handle_t session:      */ session,
                                         /* mcuxClKey_Handle_t key:              */ DukKey,
                                         /* uint32_t loadOptions:               */
                                         MCUXCLKEY_LOADOPTION_SLOT_SGI_KEY_6
                                         | MCUXCLKEY_LOADOPTION_ALREADYLOADED)
                                     );

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_loadCopro) != klKwk_token) ||
        (MCUXCLKEY_STATUS_OK != klKwk_status)) {
        return PSA_ERROR_HARDWARE_FAILURE;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();


    return PSA_SUCCESS;

}

#if defined(MCUXCL_FEATURE_KEY_DERIVATION)
/* =========================================================================
 * Internal: load SSRK as AES-256 into a key handle for AEAD use
 * ========================================================================= */

static psa_status_t load_ssrk_key(mcuxClSession_Handle_t session,
                                  mcuxClKey_Handle_t     ssrkKey)
{
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ki_status, ki_token,
                                     mcuxClKey_init(session, ssrkKey, mcuxClKey_Type_Aes256,
                                                    s_ssrk, sizeof(s_ssrk)));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != ki_token) ||
        (MCUXCLKEY_STATUS_OK != ki_status)) {
        return PSA_ERROR_HARDWARE_FAILURE;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return PSA_SUCCESS;
}
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */

/* =========================================================================
 * Internal: load the blob wrapping key for AEAD seal/unseal
 * ========================================================================= */

static psa_status_t load_blob_wrapping_key(mcuxClSession_Handle_t session,
                                           mcuxClKey_Handle_t     wrappingKey)
{
#if defined(MCUXCL_FEATURE_KEY_DERIVATION)
    return load_ssrk_key(session, wrappingKey);
#else
    return sgi_load_duk_key(session, wrappingKey);
#endif
}

/* =========================================================================
 * sgi_ssrk_derive_if_needed
 * ========================================================================= */

psa_status_t sgi_ssrk_derive_if_needed(void)
{
#if defined(MCUXCL_FEATURE_KEY_DERIVATION)
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (s_ssrk_valid) {
        status = PSA_SUCCESS;
        goto exit_unlock;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t     session = &sessionDesc;

    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLKEY_DERIVATION_CPU_WA_SIZE,
                                                  0U);
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    uint32_t dukKeyDescWords[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = { 0u };
    mcuxClKey_Handle_t dukKey = (mcuxClKey_Handle_t) dukKeyDescWords;

    status = sgi_load_duk_key(session, dukKey);
    if (PSA_SUCCESS != status) {
        goto exit_unlock;
    }

    uint32_t derivedKeyDescWords[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = { 0u };
    mcuxClKey_Handle_t derivedKey = (mcuxClKey_Handle_t) derivedKeyDescWords;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ki2_status, ki2_token,
                                     mcuxClKey_init(session, derivedKey, mcuxClKey_Type_Aes256,
                                                    s_ssrk, sizeof(s_ssrk)));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != ki2_token) ||
        (MCUXCLKEY_STATUS_OK != ki2_status)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit_unlock;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    mcuxClKey_DerivationInput_t inputs[2u];
    inputs[0u].input       = k_ssrk_label;
    inputs[0u].size = (uint32_t) K_SSRK_LABEL_LEN;
    inputs[1u].input       = k_ssrk_context;
    inputs[1u].size = (uint32_t) sizeof(k_ssrk_context);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(kdf_status, kdf_token,
                                     mcuxClKey_derivation(session, mcuxClKdfModes_SP800_108_CM_CMAC,
                                                          dukKey, inputs, 2u, derivedKey));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivation) != kdf_token) ||
        (MCUXCLKEY_STATUS_OK != kdf_status)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit_unlock;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    s_ssrk_valid = true;
    status       = PSA_SUCCESS;

exit_unlock:
    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }
    return status;
#else
    /* No KDF available - DUK is used directly as the wrapping key. */
    return PSA_SUCCESS;
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */
}

void sgi_ssrk_zeroize(void)
{
#if defined(MCUXCL_FEATURE_KEY_DERIVATION)
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(clear_token,
                                          mcuxClMemory_clear(s_ssrk, sizeof(s_ssrk),
                                                             sizeof(s_ssrk)));
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != clear_token) {
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    s_ssrk_valid = false;
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */
}

/* =========================================================================
 * sgi_duk_blob_seal
 * ========================================================================= */

psa_status_t sgi_duk_blob_seal(const psa_key_attributes_t *attributes,
                               const uint8_t *key_data,
                               size_t key_data_len,
                               uint8_t *blob,
                               size_t blob_size,
                               size_t *blob_length)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;
    size_t  pt_size = SGI_DUK_BLOB_METADATA_SIZE + key_data_len;
    uint8_t plaintext[SGI_DUK_BLOB_METADATA_SIZE + SGI_DUK_BLOB_MAX_KEY_SIZE] = { 0u };
    uint8_t nonce[SGI_DUK_BLOB_NONCE_SIZE] = { 0u };
    uint8_t encrypted_data[sizeof(plaintext)] = { 0u };
    uint8_t tag[SGI_DUK_BLOB_TAG_SIZE] = { 0u };
    uint32_t encrypted_size = 0u;
    uint32_t wrapKeyDescWords[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = { 0u };
    mcuxClKey_Handle_t wrapKey = (mcuxClKey_Handle_t) wrapKeyDescWords;

    if (blob_size < SGI_DUK_BLOB_SIZE(key_data_len)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (pt_size > sizeof(plaintext)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    status = sgi_ssrk_derive_if_needed();
    if (PSA_SUCCESS != status) {
        return status;
    }

    /* Generate 8-byte nonce via SGI entropy */
    size_t estimate_bits = 0u;
    status = sgi_get_entropy(0u, &estimate_bits, nonce, sizeof(nonce));
    if (PSA_SUCCESS != status) {
        return PSA_ERROR_HARDWARE_FAILURE;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t     session = &sessionDesc;

    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, MCUXCLAEAD_WA_SIZE_MAX, 0U);

    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Encode metadata and assemble plaintext */
    uint8_t metadata[SGI_DUK_BLOB_METADATA_SIZE];
    encode_metadata(attributes, metadata);
    (void) memcpy(plaintext, metadata, SGI_DUK_BLOB_METADATA_SIZE);

    (void) memcpy(plaintext + SGI_DUK_BLOB_METADATA_SIZE, key_data, key_data_len);

    /* Load wrapping key (SSRK if KDF available, else DUK directly) */
    status = load_blob_wrapping_key(session, wrapKey);
    if (PSA_SUCCESS != status) {
        goto cleanup_plaintext;
    }

    /* AES-CCM encrypt */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(e_status, e_token,
                                     mcuxClAead_encrypt(
                                         session, wrapKey, mcuxClAead_Mode_CCM,
                                         (mcuxCl_InputBuffer_t) nonce,     (uint32_t) sizeof(nonce),
                                         (mcuxCl_InputBuffer_t) plaintext, (uint32_t) pt_size,
                                         NULL, 0u,
                                         (mcuxCl_Buffer_t) encrypted_data, &encrypted_size,
                                         (mcuxCl_Buffer_t) tag,            (uint32_t) sizeof(tag)));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_encrypt) != e_token) ||
        (MCUXCLAEAD_STATUS_OK != e_status)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup_plaintext;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Create blob: NONCE || encrypted_data || TAG */
    (void) memcpy(blob, nonce, sizeof(nonce));
    (void) memcpy(blob + sizeof(nonce), encrypted_data, encrypted_size);
    (void) memcpy(blob + sizeof(nonce) + encrypted_size, tag, sizeof(tag));

    *blob_length = sizeof(nonce) + (size_t) encrypted_size + sizeof(tag);
    status = PSA_SUCCESS;

cleanup_plaintext:
    /* Clear sensitive plaintext from stack */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(clear_token,
                                          mcuxClMemory_clear(plaintext, pt_size, pt_size));
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != clear_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

/* =========================================================================
 * sgi_duk_blob_unseal
 * ========================================================================= */

psa_status_t sgi_duk_blob_unseal(psa_key_attributes_t *attributes,
                                 const uint8_t *blob,
                                 size_t blob_len,
                                 uint8_t *key_data,
                                 size_t key_data_size,
                                 size_t *key_data_len)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;

    uint8_t  decrypted_data[SGI_DUK_BLOB_METADATA_SIZE + SGI_DUK_BLOB_MAX_KEY_SIZE];
    uint32_t decrypted_size = 0u;
    bool     decrypted_valid = false;
    uint32_t wrapKeyDescWords[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = { 0u };
    mcuxClKey_Handle_t wrapKey = (mcuxClKey_Handle_t) wrapKeyDescWords;

    if (blob_len < (size_t) SGI_DUK_BLOB_OVERHEAD) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    const uint8_t *nonce          = blob;
    size_t         encrypted_size = blob_len - SGI_DUK_BLOB_NONCE_SIZE
                                    - SGI_DUK_BLOB_TAG_SIZE;
    const uint8_t *encrypted_data = blob + SGI_DUK_BLOB_NONCE_SIZE;
    const uint8_t *tag            = blob + SGI_DUK_BLOB_NONCE_SIZE + encrypted_size;

    if (encrypted_size < (size_t) SGI_DUK_BLOB_METADATA_SIZE) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    size_t recovered_key_len = encrypted_size - SGI_DUK_BLOB_METADATA_SIZE;
    if (key_data_size < recovered_key_len) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (encrypted_size > sizeof(decrypted_data)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    status = sgi_ssrk_derive_if_needed();
    if (PSA_SUCCESS != status) {
        return status;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t     session = &sessionDesc;


    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, MCUXCLAEAD_WA_SIZE_MAX, 0U);

    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Load wrapping key */
    status = load_blob_wrapping_key(session, wrapKey);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    /* AES-CCM decrypt */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(d_status, d_token,
                                     mcuxClAead_decrypt(
                                         session,
                                         wrapKey,
                                         mcuxClAead_Mode_CCM,
                                         (mcuxCl_InputBuffer_t) nonce,
                                         (uint32_t) SGI_DUK_BLOB_NONCE_SIZE,
                                         (mcuxCl_InputBuffer_t) encrypted_data,
                                         (uint32_t) encrypted_size,
                                         NULL,
                                         0u,
                                         (mcuxCl_InputBuffer_t) tag,
                                         (uint32_t) SGI_DUK_BLOB_TAG_SIZE,
                                         (mcuxCl_Buffer_t) decrypted_data,
                                         &decrypted_size));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_decrypt) != d_token) ||
        (MCUXCLAEAD_STATUS_OK != d_status)) {
        status = PSA_ERROR_INVALID_SIGNATURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Mark that decrypted_data contains sensitive material */
    decrypted_valid = true;

    /* Sanity check decrypted size */
    if (decrypted_size < (uint32_t) SGI_DUK_BLOB_METADATA_SIZE) {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto cleanup;
    }

    /* Set attributes from blob metadata - blob is the source of truth */
    if (attributes != NULL) {
        status = decode_metadata(attributes, decrypted_data);
        if (PSA_SUCCESS != status) {
            goto cleanup;
        }
    }

    /* Extract key data */
    {
        size_t extracted_len = (size_t) decrypted_size - SGI_DUK_BLOB_METADATA_SIZE;
        if (key_data_size < extracted_len) {
            status = PSA_ERROR_BUFFER_TOO_SMALL;
            goto cleanup;
        }

        (void) memcpy(key_data,
                      decrypted_data + SGI_DUK_BLOB_METADATA_SIZE,
                      extracted_len);
        *key_data_len = extracted_len;
    }

    status = PSA_SUCCESS;

cleanup:
    /* Clear sensitive decrypted data from stack */
    if (decrypted_valid) {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(clear_token,
                                              mcuxClMemory_clear(decrypted_data,
                                                                 (size_t) decrypted_size,
                                                                 (size_t) decrypted_size));
        if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != clear_token) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();
    }

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}
