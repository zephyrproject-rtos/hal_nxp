/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_opaque_asymmetric_signature.c
 *
 * This file contains the implementation of the entry points associated to the
 * asymmetric signature capability for opaque keys as described by the PSA
 * Cryptoprocessor Driver interface specification.
 *
 * For opaque keys the HSE key handle is read directly from the key buffer;
 * no key loading or slot allocation is performed by these entry points.
 */

#include "mcux_psa_ele_hseb_init.h"
#include "mcux_psa_ele_hseb_opaque_asymmetric_signature.h"
#include "mcux_psa_ele_hseb_common_asymmetric_signature.h"
#include "mcux_psa_ele_hseb_utils.h"
#include "psa/crypto_values.h"

psa_status_t ele_hseb_opaque_sign_message(const psa_key_attributes_t *attributes,
                                          const uint8_t *key_buffer,
                                          size_t key_buffer_size,
                                          psa_algorithm_t alg,
                                          const uint8_t *input,
                                          size_t input_length,
                                          uint8_t *signature,
                                          size_t signature_size,
                                          size_t *signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    size_t output_size        = 0u;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PKCS1V15_SIGN_RAW variant may
     * only be used with psa_sign_hash() and psa_verify_hash() functions.
     */
    if (false == PSA_ALG_IS_SIGN_MESSAGE(alg) ||
        PSA_ALG_RSA_PKCS1V15_SIGN_RAW == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == input || 0u == input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || NULL == signature_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    output_size = PSA_SIGN_OUTPUT_SIZE(key_type, key_bits, alg);
    if (output_size > signature_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* For opaque keys the handle is already stored in the key buffer */
    if (sizeof(hseKeyHandle_t) != key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    ele_hseb_read_key_handle_from_buffer(key_buffer, &key_handle);

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = ele_hseb_common_ecdsa_sign(key_handle, alg,
                                                input, input_length,
                                                signature, signature_size,
                                                signature_length, false);
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg) ||
                   PSA_ALG_PURE_EDDSA == alg) {
            /* EdDSA / PureEdDSA not yet supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        if (true == PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) ||
            true == PSA_ALG_IS_RSA_PSS(alg)) {
            status = ele_hseb_common_rsa_sign(key_handle, attributes, alg,
                                              input, input_length,
                                              signature, signature_size,
                                              signature_length, false);
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    if (PSA_SUCCESS != status) {
        *signature_length = 0u;
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_opaque_verify_message(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *input,
                                            size_t input_length,
                                            const uint8_t *signature,
                                            size_t signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PKCS1V15_SIGN_RAW variant may
     * only be used with psa_sign_hash() and psa_verify_hash() functions.
     */
    if (false == PSA_ALG_IS_SIGN_MESSAGE(alg) ||
        PSA_ALG_RSA_PKCS1V15_SIGN_RAW == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == input || 0u == input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || 0u == signature_length) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* For opaque keys the handle is already stored in the key buffer */
    if (sizeof(hseKeyHandle_t) != key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    ele_hseb_read_key_handle_from_buffer(key_buffer, &key_handle);

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = ele_hseb_common_ecdsa_verify(key_handle, attributes,
                                                  alg, input, input_length,
                                                  signature, signature_length,
                                                  false);
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg) ||
                   PSA_ALG_PURE_EDDSA == alg) {
            /* EdDSA / PureEdDSA not yet supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        if (true == PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) ||
            true == PSA_ALG_IS_RSA_PSS(alg)) {
            status = ele_hseb_common_rsa_verify(key_handle, attributes, alg,
                                                input, input_length,
                                                signature, signature_length,
                                                false);
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_opaque_sign_hash(const psa_key_attributes_t *attributes,
                                       const uint8_t *key_buffer,
                                       size_t key_buffer_size,
                                       psa_algorithm_t alg,
                                       const uint8_t *hash,
                                       size_t hash_length,
                                       uint8_t *signature,
                                       size_t signature_size,
                                       size_t *signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    size_t output_size        = 0u;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PURE_EDDSA variant may
     * only be used with psa_sign_message() and psa_verify_message() functions.
     */
    if (false == PSA_ALG_IS_SIGN_HASH(alg) ||
        PSA_ALG_PURE_EDDSA == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == hash || 0u == hash_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || NULL == signature_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    output_size = PSA_SIGN_OUTPUT_SIZE(key_type, key_bits, alg);
    if (output_size > signature_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* For opaque keys the handle is already stored in the key buffer */
    if (sizeof(hseKeyHandle_t) != key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    ele_hseb_read_key_handle_from_buffer(key_buffer, &key_handle);

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = ele_hseb_common_ecdsa_sign(key_handle, alg,
                                                hash, hash_length,
                                                signature, signature_size,
                                                signature_length, true);
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg)) {
            /* EdDSA not yet supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        /* ELE_HSEB RSA hash sign/ver API does not align with the PSA API spec.
         * Per HSE API reference:
         *    "For RSA schemes, this [the input length] must be the length
         *     of the original (not pre-hashed) input."
         * This condition is not met by the PSA API, as we only receive hashlen.
         */
        status = PSA_ERROR_NOT_SUPPORTED;
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    if (PSA_SUCCESS != status) {
        *signature_length = 0u;
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_opaque_verify_hash(const psa_key_attributes_t *attributes,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         psa_algorithm_t alg,
                                         const uint8_t *hash,
                                         size_t hash_length,
                                         const uint8_t *signature,
                                         size_t signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PURE_EDDSA variant may
     * only be used with psa_sign_message() and psa_verify_message() functions.
     */
    if (false == PSA_ALG_IS_SIGN_HASH(alg) ||
        PSA_ALG_PURE_EDDSA == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == hash || 0u == hash_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || 0u == signature_length) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* For opaque keys the handle is already stored in the key buffer */
    if (sizeof(hseKeyHandle_t) != key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    ele_hseb_read_key_handle_from_buffer(key_buffer, &key_handle);

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = ele_hseb_common_ecdsa_verify(key_handle, attributes,
                                                  alg, hash, hash_length,
                                                  signature, signature_length,
                                                  true);
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg)) {
            /* EdDSA not yet supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        /* ELE_HSEB RSA hash sign/ver API does not align with the PSA API spec.
         * Per HSE API reference:
         *    "For RSA schemes, this [the input length] must be the length
         *     of the original (not pre-hashed) input."
         * This condition is not met by the PSA API, as we only receive hashlen.
         */
        status = PSA_ERROR_NOT_SUPPORTED;
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
