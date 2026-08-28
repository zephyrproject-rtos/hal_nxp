/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_common_aead.c
 *
 * This file contains the implementations of the entry points associated to the
 * aead capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification.
 *
 */

#include "mcux_psa_caam_init.h"
#include "mcux_psa_caam_common_aead.h"
#include "mcux_psa_caam_utils.h"
#include "mcux_psa_common_key_management.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"

static inline psa_status_t caam_cipher_key_type(mcux_psa_caam_key_type_t caam_key_type,
                                                caam_key_type_t *aes_key_type)
{
    switch (caam_key_type) {
        case MCUX_PSA_CAAM_KEY_TYPE_NONE:
        {
            *aes_key_type = kCAAM_Key_Type_None;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_ECB:
        {
            *aes_key_type = kCAAM_Key_Type_Ecb_Jkek;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_CCM:
        {
            *aes_key_type = kCAAM_Key_Type_Ccm_Jkek;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}

static psa_status_t check_aead_alg(psa_algorithm_t alg, psa_key_type_t key_type, size_t *tag_length)
{
    uint32_t _tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);

    /* Algorithm needs to be a AEAD algo */
    if (!PSA_ALG_IS_AEAD(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

#if defined(PSA_WANT_KEY_TYPE_AES)
    if (key_type != PSA_KEY_TYPE_AES)
#endif
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    switch (PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg)) {
#if defined(PSA_WANT_ALG_CCM)
        case PSA_ALG_CCM:
        {
            if ((_tag_length > 0x10u) || ((_tag_length & 0x1Eu) != _tag_length) ||
                (_tag_length < 4u)) {
                return PSA_ERROR_INVALID_ARGUMENT;
            }
            break;
        }
#endif /* PSA_WANT_ALG_CCM */
#if defined(PSA_WANT_ALG_GCM)
        case PSA_ALG_GCM:
        {
            if ((_tag_length > 0x10u) ||
                ((_tag_length < 12u) && (_tag_length != 4u) && (_tag_length != 8u))) {
                return PSA_ERROR_INVALID_ARGUMENT;
            }
            break;
        }
#endif /* PSA_WANT_ALG_GCM */
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    *tag_length = _tag_length;

    return PSA_SUCCESS;
}

/** \defgroup psa_aead PSA driver entry points for AEAD
 *
 *  Entry points for AEAD encryption and decryption as described by the PSA
 *  Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t caam_internal_aead_encrypt(mcux_psa_caam_key_type_t caam_key_type,
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
                                        size_t *ciphertext_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    status_t caam_status      = kStatus_Fail;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = PSA_BITS_TO_BYTES(key_bits);
    size_t tag_length         = 0u;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    caam_key_type_t aes_key_type;

    if (caam_key_type != MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        key_bytes = CAAM_OPAQUE_ALIGN(key_bytes);
    }

    /* Validate the algorithm first */
    status = check_aead_alg(alg, key_type, &tag_length);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Key buffer or size can't be NULL */
    if ((key_buffer == NULL) || (key_buffer_size == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute */
    if (key_buffer_size != key_bytes) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Nonce can't be NULL */
    if ((nonce == NULL) || (nonce_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* No check for input and additional data as 0 value for these is allowed */

    /* Output buffer has to be atleast Input buffer size  -> Check for encrypt */
    if (mcux_psa_add_size_t_wrapcheck(plaintext_length, tag_length)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    if (ciphertext_size < (plaintext_length + tag_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Output buffer can't be NULL */
    if ((ciphertext == NULL)  || (ciphertext_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = caam_cipher_key_type(caam_key_type, &aes_key_type);
    if (status != PSA_SUCCESS) {
        return status;
    }

    *ciphertext_length = 0u;

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    switch (PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg)) {
#if defined(PSA_WANT_ALG_CCM)
        case PSA_ALG_CCM:
        {
            caam_status = CAAM_AES_EncryptTagCcmExtended(
                PSA_CAAM,
                &caam_handle,
                plaintext,
                ciphertext,
                plaintext_length,
                nonce,
                nonce_length,
                additional_data,
                additional_data_length,
                key_buffer,
                PSA_BITS_TO_BYTES(key_bits),
                ciphertext + plaintext_length,
                tag_length,
                aes_key_type);
            break;
        }
#endif /* PSA_WANT_ALG_CCM */
#if defined(PSA_WANT_ALG_GCM)
        case PSA_ALG_GCM:
        {
            caam_status = CAAM_AES_EncryptTagGcmExtended(
                PSA_CAAM,
                &caam_handle,
                plaintext,
                ciphertext,
                plaintext_length,
                nonce,
                nonce_length,
                additional_data,
                additional_data_length,
                key_buffer,
                PSA_BITS_TO_BYTES(key_bits),
                ciphertext + plaintext_length,
                tag_length,
                aes_key_type);
            break;
        }
#endif /* PSA_WANT_ALG_GCM */
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }
    status = caam_to_psa_status(caam_status);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS) {
        *ciphertext_length = plaintext_length + tag_length;
    }

    (void)caam_handle;

    return status;
}

psa_status_t caam_internal_aead_encrypt_blacken(mcux_psa_caam_key_type_t caam_key_type,
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
                                                size_t *ciphertext_length)
{
    psa_status_t err;
    size_t key_bits  = psa_get_key_bits(attributes);
    size_t key_bytes = CAAM_OPAQUE_ALIGN(PSA_BITS_TO_BYTES(key_bits));

#if defined(USE_MALLOC)
    uint8_t *key_decap = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (key_decap == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#else
    uint8_t key_decap[CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE)];
    if (CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE) < key_bytes) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    err = caam_opaque_decapsulate_key(caam_key_type,
                                      key_buffer,
                                      key_buffer_size,
                                      key_decap,
                                      PSA_BITS_TO_BYTES(key_bits));
    if (err == PSA_SUCCESS) {
        err = caam_internal_aead_encrypt(caam_key_type,
                                         attributes,
                                         key_decap,
                                         key_bytes,
                                         alg,
                                         nonce,
                                         nonce_length,
                                         additional_data,
                                         additional_data_length,
                                         plaintext,
                                         plaintext_length,
                                         ciphertext,
                                         ciphertext_size,
                                         ciphertext_length);
    }

#if defined(USE_MALLOC)
    mbedtls_free(key_decap);
#endif

    return err;
}

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
                                      size_t *ciphertext_length)
{
    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        return caam_internal_aead_encrypt(caam_key_type,
                                          attributes,
                                          key_buffer,
                                          key_buffer_size,
                                          alg,
                                          nonce,
                                          nonce_length,
                                          additional_data,
                                          additional_data_length,
                                          plaintext,
                                          plaintext_length,
                                          ciphertext,
                                          ciphertext_size,
                                          ciphertext_length);
    } else {
        return caam_internal_aead_encrypt_blacken(caam_key_type,
                                                  attributes,
                                                  key_buffer,
                                                  key_buffer_size,
                                                  alg,
                                                  nonce,
                                                  nonce_length,
                                                  additional_data,
                                                  additional_data_length,
                                                  plaintext,
                                                  plaintext_length,
                                                  ciphertext,
                                                  ciphertext_size,
                                                  ciphertext_length);
    }
}

psa_status_t caam_internal_aead_decrypt(mcux_psa_caam_key_type_t caam_key_type,
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
                                        size_t *plaintext_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    status_t caam_status      = kStatus_Fail;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = PSA_BITS_TO_BYTES(key_bits);
    size_t tag_length         = 0u;
    uint8_t *tag              = NULL;
    size_t cipher_length      = 0u;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    caam_key_type_t aes_key_type;

    if (caam_key_type != MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        key_bytes = CAAM_OPAQUE_ALIGN(key_bytes);
    }

    /* Validate the algorithm first */
    status = check_aead_alg(alg, key_type, &tag_length);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Key buffer or size can't be NULL */
    if ((key_buffer == NULL) || (key_buffer_size == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute */
    if (key_buffer_size != key_bytes) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Input Buffer or size can't be NULL */
    if ((ciphertext == NULL)  || (ciphertext_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((nonce == NULL) || (nonce_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = caam_cipher_key_type(caam_key_type, &aes_key_type);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* ciphertext has cipher + tag */
    cipher_length = ciphertext_length - tag_length;

    /* Output buffer has to be atleast Input buffer size  -> Check for encrypt */
    if (plaintext_size < cipher_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Input buffer i.e plaintext or AAD is allowed to be 0 in encrypt
     * Operation. Hence output of a decrypt can be of size 0. Hence no
     * check involving plaintext buffer.
     */

    *plaintext_length = 0u;

    /* Tag is at the end of ciphertext */
    tag = (uint8_t *) (ciphertext + cipher_length);

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    switch (PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg)) {
#if defined(PSA_WANT_ALG_CCM)
        case PSA_ALG_CCM:
        {
            caam_status = CAAM_AES_DecryptTagCcmExtended(
                PSA_CAAM,
                &caam_handle,
                ciphertext,
                plaintext,
                cipher_length,
                nonce,
                nonce_length,
                additional_data,
                additional_data_length,
                key_buffer,
                PSA_BITS_TO_BYTES(key_bits),
                tag,
                tag_length,
                aes_key_type);
            break;
        }
#endif /* PSA_WANT_ALG_CCM */
#if defined(PSA_WANT_ALG_GCM)
        case PSA_ALG_GCM:
        {
            caam_status = CAAM_AES_DecryptTagGcmExtended(
                PSA_CAAM,
                &caam_handle,
                ciphertext,
                plaintext,
                cipher_length,
                nonce,
                nonce_length,
                additional_data,
                additional_data_length,
                key_buffer,
                PSA_BITS_TO_BYTES(key_bits),
                tag,
                tag_length,
                aes_key_type);
            break;
        }
#endif /* PSA_WANT_ALG_GCM */
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }
    status = caam_to_psa_status(caam_status);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS) {
        *plaintext_length = cipher_length;
    } else {
        /*
         * ELE doesn't return a specific error in case the signature is invalid,
         * which is required by PSA specification. As a workaround parameter checks
         * have ben done before calling the ELE_GenericAEAD function. Expectation
         * is that the only case where ELE would return error would be when there
         * is invalid signature. This may not always hold good. This is a
         * workaround for now.
         */
        status = PSA_ERROR_INVALID_SIGNATURE;
    }

    (void)caam_handle;

    return status;
}

psa_status_t caam_internal_aead_decrypt_blacken(mcux_psa_caam_key_type_t caam_key_type,
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
                                                size_t *plaintext_length)
{
    psa_status_t err;
    size_t key_bits  = psa_get_key_bits(attributes);
    size_t key_bytes = CAAM_OPAQUE_ALIGN(PSA_BITS_TO_BYTES(key_bits));

#if defined(USE_MALLOC)
    uint8_t *key_decap = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (key_decap == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#else
    uint8_t key_decap[CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE)];
    if (CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE) < key_bytes) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    err = caam_opaque_decapsulate_key(caam_key_type,
                                      key_buffer,
                                      key_buffer_size,
                                      key_decap,
                                      PSA_BITS_TO_BYTES(key_bits));
    if (err == PSA_SUCCESS) {
        err = caam_internal_aead_decrypt(caam_key_type,
                                         attributes,
                                         key_decap,
                                         key_bytes,
                                         alg,
                                         nonce,
                                         nonce_length,
                                         additional_data,
                                         additional_data_length,
                                         ciphertext,
                                         ciphertext_length,
                                         plaintext,
                                         plaintext_size,
                                         plaintext_length);
    }

#if defined(USE_MALLOC)
    mbedtls_free(key_decap);
#endif

    return err;
}

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
                                      size_t *plaintext_length)
{
    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        return caam_internal_aead_decrypt(caam_key_type,
                                          attributes,
                                          key_buffer,
                                          key_buffer_size,
                                          alg,
                                          nonce,
                                          nonce_length,
                                          additional_data,
                                          additional_data_length,
                                          ciphertext,
                                          ciphertext_length,
                                          plaintext,
                                          plaintext_size,
                                          plaintext_length);
    } else {
        return caam_internal_aead_decrypt_blacken(caam_key_type,
                                                  attributes,
                                                  key_buffer,
                                                  key_buffer_size,
                                                  alg,
                                                  nonce,
                                                  nonce_length,
                                                  additional_data,
                                                  additional_data_length,
                                                  ciphertext,
                                                  ciphertext_length,
                                                  plaintext,
                                                  plaintext_size,
                                                  plaintext_length);
    }
}
/** @} */ // end of psa_aead
