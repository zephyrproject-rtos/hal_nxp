/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_common_rsa_encryption.c
 *
 * This file contains the implementation of the entry points associated to the
 * rsa encryption capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#include "mcux_psa_caam_init.h"
#include "mcux_psa_caam_common_asymmetric_encryption.h"
#include "mcux_psa_common_key_management.h"
#include "mcux_psa_caam_hash.h"
#include "mcux_psa_mbedtls_origin.h"
#include "mcux_psa_caam_utils.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

#include "psa/crypto.h"
#include "psa_crypto_rsa.h"
#include "psa/crypto_sizes.h"
#include "psa_crypto_core.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#include "mbedtls/psa_util.h"

psa_status_t caam_common_internal_rsa_encrypt(mcux_psa_caam_key_type_t caam_key_type,
                                              caam_rsa_format_type_t format,
                                              const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *input,
                                              size_t input_length,
                                              uint8_t *output,
                                              size_t output_size,
                                              size_t *output_length)
{
    psa_status_t err                = PSA_SUCCESS;
    psa_status_t err2               = PSA_SUCCESS;
    psa_status_t err3               = PSA_SUCCESS;
    psa_key_type_t key_type         = psa_get_key_type(attributes);
    status_t caam_status            = kStatus_Fail;
    struct mcux_rsa_keypair rsa_key = { 0 };
    size_t key_bits                 = psa_get_key_bits(attributes);
    uint32_t key_bytes              = PSA_BITS_TO_BYTES(key_bits);
    caam_handle_t caam_handle       = { .jobRing = kCAAM_JobRing0 };
    uint8_t rsa_exp[4];

    // No check on input as input can be NULL
    if (output == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (output_size < key_bytes) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Zero output length by default */
    *output_length = 0u;

    if ((key_bits % 1024u) != 0u) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        /* Parse input - We will use mbedtls_rsa_context to parse the context into*/
        err = mcux_key_buf_to_raw_rsa(key_type,
                                      key_buffer,
                                      key_buffer_size,
                                      key_bytes,
                                      true,
                                      &rsa_key,
                                      rsa_exp);
        if (err != PSA_SUCCESS) {
            return err;
        }
    } else {
        rsa_exp[0] = 0u;
        memcpy(&rsa_exp[1], &s_rsa_exponent, 3u);
        rsa_key.modulus     = (uint8_t *) key_buffer;
        rsa_key.modulus_len = key_bytes;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        err  = PSA_ERROR_SERVICE_FAILURE;
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        caam_status =
            CAAM_RSA_Encrypt(PSA_CAAM,
                             &caam_handle,
                             input,
                             input_length,
                             rsa_key.modulus,
                             rsa_key.modulus_len,
                             rsa_exp,
                             sizeof(rsa_exp),
                             kCAAM_Rsa_Encryption_Type_None,
                             format,
                             output);
        err = caam_to_psa_status(caam_status);
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        err3 = mcux_free_raw_rsa(&rsa_key);
    }

    if (err2 != PSA_SUCCESS) {
        return err2;
    }
    if (err3 != PSA_SUCCESS) {
        return err3;
    }

    /* ELE FW doesn't return the output size, we are assuming if things have gone right it will be equal to modulus
     * size. */
    if (err == PSA_SUCCESS) {
        *output_length = key_bytes;
    }

    return err;
}

#if defined(PSA_WANT_ALG_RSA_PKCS1V15_CRYPT)
static psa_status_t caam_common_internal_rsa_encrypt_pkcs1_5(mcux_psa_caam_key_type_t caam_key_type,
                                                             const psa_key_attributes_t *attributes,
                                                             const uint8_t *key_buffer,
                                                             size_t key_buffer_size,
                                                             psa_algorithm_t alg,
                                                             const uint8_t *input,
                                                             size_t input_length,
                                                             uint8_t *output,
                                                             size_t output_size,
                                                             size_t *output_length)
{
    size_t key_bits    = psa_get_key_bits(attributes);
    uint32_t key_bytes = PSA_BITS_TO_BYTES(key_bits);

    /* Check for  input message length . For PKCS#1.5 padding is 11 bytes */
    if ((key_bytes < 11u) || (input_length > (key_bytes - 11u))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return caam_common_internal_rsa_encrypt(caam_key_type,
                                            kCAAM_Rsa_Format_Type_PKCS1,
                                            attributes,
                                            key_buffer,
                                            key_buffer_size,
                                            alg,
                                            input,
                                            input_length,
                                            output,
                                            output_size,
                                            output_length);
}
#endif

#if defined(PSA_WANT_ALG_RSA_OAEP)
static psa_status_t caam_common_internal_rsa_encrypt_oaep(mcux_psa_caam_key_type_t caam_key_type,
                                                          const psa_key_attributes_t *attributes,
                                                          const uint8_t *key_buffer,
                                                          size_t key_buffer_size,
                                                          psa_algorithm_t alg,
                                                          const uint8_t *input,
                                                          size_t input_length,
                                                          const uint8_t *label,
                                                          size_t label_len,
                                                          uint8_t *output,
                                                          size_t output_size,
                                                          size_t *output_length)
{
    int mbedtls_err;
    psa_status_t err          = PSA_SUCCESS;
    psa_status_t err2         = PSA_SUCCESS;
    status_t caam_status      = kStatus_Fail;
    uint8_t hash_size         = PSA_HASH_LENGTH(PSA_ALG_RSA_OAEP_GET_HASH(alg));
    size_t key_bits           = psa_get_key_bits(attributes);
    uint32_t key_bytes        = PSA_BITS_TO_BYTES(key_bits);
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    size_t tmp;
#if defined(USE_MALLOC)
    uint8_t *_input = NULL;
#else
    uint8_t _input[MAX_RSA_KEYSIZE];
    if (key_bytes < MAX_RSA_KEYSIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    if (hash_size == 0u) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Guard additions before comparison to avoid unsigned wrap */
    if (mcux_psa_add_size_t_wrapcheck(2U * hash_size, 2U)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    if (mcux_psa_add_size_t_wrapcheck(input_length, 2U * hash_size + 2U)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    /* first comparison checks for overflow */
    if (key_bytes < (input_length + (2u * hash_size) + 2u)) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

#if defined(USE_MALLOC)
    if (err == PSA_SUCCESS) {
        _input = (uint8_t *) mbedtls_calloc(1u, key_bytes);
        if (_input == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
    }
#endif

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        err  = PSA_ERROR_SERVICE_FAILURE;
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        caam_status =
            CAAM_RNG_GetRandomData(PSA_CAAM,
                                   &caam_handle,
                                   kCAAM_RngStateHandle0,
                                   &_input[1u],
                                   hash_size,
                                   kCAAM_RngDataAny,
                                   NULL);
        err         = caam_to_psa_status(caam_status);
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        err = caam_hash_compute(alg, label, label_len, &_input[1u + hash_size], hash_size, &tmp);
    }

    if (err == PSA_SUCCESS) {
        _input[key_bytes - input_length - 1] = 1;
        memcpy(&_input[key_bytes - input_length], input, input_length);
        /* maskedDB: Apply dbMask to DB */
        mbedtls_err = mgf_mask(_input + hash_size + 1u,
                               key_bytes - hash_size - 1u,
                               _input + 1u,
                               hash_size,
                               mbedtls_md_type_from_psa_alg(alg));
        err         = mbedtls_to_psa_error(mbedtls_err);
    }

    if (err == PSA_SUCCESS) {
        mbedtls_err = mgf_mask(_input + 1u,
                               hash_size,
                               _input + hash_size + 1u,
                               key_bytes - hash_size - 1u,
                               mbedtls_md_type_from_psa_alg(alg));
        err         = mbedtls_to_psa_error(mbedtls_err);
    }

    if (err == PSA_SUCCESS) {
        err = caam_common_internal_rsa_encrypt(caam_key_type,
                                               kCAAM_Rsa_Format_Type_None,
                                               attributes,
                                               key_buffer,
                                               key_buffer_size,
                                               alg,
                                               _input,
                                               key_bytes,
                                               output,
                                               output_size,
                                               output_length);
    }

#if defined(USE_MALLOC)
    if (_input != NULL) {
        mbedtls_free(_input);
    }
#endif

    if (err2 != PSA_SUCCESS) {
        return err2;
    }

    return err;
}
#endif

static inline psa_status_t caam_rsa_key_type(mcux_psa_caam_key_type_t caam_key_type,
                                             caam_rsa_encryption_type_t *rsa_key_type)
{
    switch (caam_key_type) {
        case MCUX_PSA_CAAM_KEY_TYPE_NONE:
        {
            *rsa_key_type = kCAAM_Rsa_Encryption_Type_None;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_ECB:
        {
            *rsa_key_type = kCAAM_Rsa_Encryption_Type_Ecb_Jkek;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_CCM:
        {
            *rsa_key_type = kCAAM_Rsa_Encryption_Type_Ccm_Jkek;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}

psa_status_t caam_common_internal_rsa_decrypt(mcux_psa_caam_key_type_t caam_key_type,
                                              caam_rsa_format_type_t format,
                                              const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *input,
                                              size_t input_length,
                                              uint8_t *output,
                                              size_t output_size,
                                              size_t *output_length)
{
    psa_status_t err                = PSA_SUCCESS;
    psa_status_t err2               = PSA_SUCCESS;
    psa_status_t err3               = PSA_SUCCESS;
    psa_key_type_t key_type         = psa_get_key_type(attributes);
    status_t caam_status            = kStatus_Fail;
    struct mcux_rsa_keypair rsa_key = { 0 };
    size_t key_bits                 = psa_get_key_bits(attributes);
    uint32_t key_bytes              = PSA_BITS_TO_BYTES(key_bits);
    caam_handle_t caam_handle       = { .jobRing = kCAAM_JobRing0 };
    caam_rsa_encryption_type_t rsa_key_type;
    uint8_t rsa_exp[4];
    size_t _output_length;
#if defined(USE_MALLOC)
    uint8_t *_output = NULL;
#else
    uint8_t _output[MAX_RSA_KEYSIZE];
    if (key_bytes < MAX_RSA_KEYSIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    /* If user sends a buffer with 0 size, return error */
    if ((output == NULL) || (output_size == 0u)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if ((input == NULL) || (input_length != key_bytes)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Zero output length by default */
    *output_length = 0u;

    if ((key_bits % 1024u) != 0u) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    err = caam_rsa_key_type(caam_key_type, &rsa_key_type);
    if (err != PSA_SUCCESS) {
        return err;
    }

#if defined(USE_MALLOC)
    _output = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (_output == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        /* Parse input - We will use mbedtls_rsa_context to parse the context into*/
        err = mcux_key_buf_to_raw_rsa(key_type,
                                      key_buffer,
                                      key_buffer_size,
                                      key_bytes,
                                      false,
                                      &rsa_key,
                                      rsa_exp);
    } else {
        err = mcux_alloc_raw_rsa(&rsa_key, key_bytes, MCUX_KEY_TYPE_KEYPAIR, true);
        if (err == PSA_SUCCESS) {
            memcpy((uint8_t *) &rsa_key.priv_exp_len, &key_buffer[key_bytes], sizeof(size_t));
            if (key_buffer_size < (key_bytes + sizeof(size_t))) {
                err = PSA_ERROR_INVALID_ARGUMENT;
            }
        }
        if (err == PSA_SUCCESS) {
            err = caam_opaque_decapsulate_key(caam_key_type,
                                              &key_buffer[key_bytes+sizeof(size_t)],
                                              key_buffer_size - key_bytes - sizeof(size_t),
                                              rsa_key.priv_exp,
                                              rsa_key.priv_exp_len);
        }
        if (err == PSA_SUCCESS) {
            memcpy(rsa_key.modulus, key_buffer, key_bytes);
        }
    }

    if (err == PSA_SUCCESS) {
        if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
            err  = PSA_ERROR_SERVICE_FAILURE;
            err2 = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    if (err == PSA_SUCCESS) {
        caam_status = CAAM_RSA_Decrypt(PSA_CAAM,
                                       &caam_handle,
                                       input,
                                       rsa_key.modulus,
                                       rsa_key.modulus_len,
                                       rsa_key.priv_exp,
                                       rsa_key.priv_exp_len,
                                       rsa_key_type,
                                       kCAAM_Rsa_Encryption_Type_None,
                                       format,
                                       _output,
                                       &_output_length);
        err         = caam_to_psa_status(caam_status);
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        if (_output_length > output_size) {
            err = PSA_ERROR_BUFFER_TOO_SMALL;
        }
    }

    if (err == PSA_SUCCESS) {
        memcpy(output, _output, _output_length);
        *output_length = _output_length;
    }

#if defined(USE_MALLOC)
    if (_output != NULL) {
        mbedtls_free(_output);
    }
#endif

    err3 = mcux_free_raw_rsa(&rsa_key);
    if (err2 != PSA_SUCCESS) {
        return err2;
    }
    if (err3 != PSA_SUCCESS) {
        return err3;
    }

    return err;
}

#if defined(PSA_WANT_ALG_RSA_PKCS1V15_CRYPT)
static psa_status_t caam_common_internal_rsa_decrypt_pkcs1_5(mcux_psa_caam_key_type_t caam_key_type,
                                                             const psa_key_attributes_t *attributes,
                                                             const uint8_t *key_buffer,
                                                             size_t key_buffer_size,
                                                             psa_algorithm_t alg,
                                                             const uint8_t *input,
                                                             size_t input_length,
                                                             uint8_t *output,
                                                             size_t output_size,
                                                             size_t *output_length)
{
    return caam_common_internal_rsa_decrypt(caam_key_type,
                                            kCAAM_Rsa_Format_Type_PKCS1,
                                            attributes,
                                            key_buffer,
                                            key_buffer_size,
                                            alg,
                                            input,
                                            input_length,
                                            output,
                                            output_size,
                                            output_length);
}
#endif


#if defined(PSA_WANT_ALG_RSA_OAEP)
static psa_status_t caam_common_internal_rsa_decrypt_oaep(mcux_psa_caam_key_type_t caam_key_type,
                                                          const psa_key_attributes_t *attributes,
                                                          const uint8_t *key_buffer,
                                                          size_t key_buffer_size,
                                                          psa_algorithm_t alg,
                                                          const uint8_t *input,
                                                          size_t input_length,
                                                          const uint8_t *label,
                                                          size_t label_len,
                                                          uint8_t *output,
                                                          size_t output_size,
                                                          size_t *output_length)
{
    int mbedtls_err;
    psa_status_t err          = PSA_SUCCESS;
    uint8_t hash_size         = PSA_HASH_LENGTH(PSA_ALG_RSA_OAEP_GET_HASH(alg));
    size_t key_bits           = psa_get_key_bits(attributes);
    uint32_t key_bytes        = PSA_BITS_TO_BYTES(key_bits);
    size_t output_len, pad_len, i;
    const mbedtls_md_info_t *md_info;
#if defined(USE_MALLOC)
    uint8_t *hash = NULL;
#else
    uint8_t hash[MBEDTLS_MD_MAX_SIZE];
    if (key_bytes < MBEDTLS_MD_MAX_SIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    *output_length = 0u;

    if (hash_size == 0u) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (((2u * hash_size) + 2u) > input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (((input_length - (2u * hash_size)) - 2u) > output_size) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }

    err = caam_common_internal_rsa_decrypt(caam_key_type,
                                           kCAAM_Rsa_Format_Type_None,
                                           attributes,
                                           key_buffer,
                                           key_buffer_size,
                                           alg,
                                           input,
                                           input_length,
                                           output,
                                           output_size,
                                           &output_len);
    if (err != PSA_SUCCESS) {
        return err;
    }

    if (output_len != key_bytes) {
        return PSA_ERROR_BAD_STATE;
    }

    mbedtls_err =
        mgf_mask(output + 1u, hash_size, output + hash_size + 1u, (input_length - hash_size) - 1u,
                 mbedtls_md_type_from_psa_alg(alg));
    err = mbedtls_to_psa_error(mbedtls_err);
    if (err != PSA_SUCCESS) {
        return err;
    }

    mbedtls_err =
        mgf_mask(output + hash_size + 1u, (input_length - hash_size) - 1u, output + 1u, hash_size,
                 mbedtls_md_type_from_psa_alg(alg));
    err = mbedtls_to_psa_error(mbedtls_err);
    if (err != PSA_SUCCESS) {
        return err;
    }

    if (output[0] != 0u) {
        return PSA_ERROR_BAD_STATE;
    }

#if defined(USE_MALLOC)
    hash = (uint8_t *) mbedtls_calloc(1u, hash_size * 2u);
    if (hash == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    /* Generate lHash */
    md_info = mbedtls_md_info_from_type(mbedtls_md_type_from_psa_alg(alg));
    if (md_info == NULL) {
        err = PSA_ERROR_BAD_STATE;
    }
    if (err == PSA_SUCCESS) {
        mbedtls_err = mbedtls_md(md_info, label, label_len, hash);
        err         = mbedtls_to_psa_error(mbedtls_err);
    }

    if (err == PSA_SUCCESS) {
        if (memcmp(hash, &output[hash_size + 1u], hash_size) != 0u) {
            err = PSA_ERROR_BAD_STATE;
        }
    }

#if defined(USE_MALLOC)
    if (hash != NULL) {
        mbedtls_free(hash);
    }
#endif

    if (err != PSA_SUCCESS) {
        return err;
    }

    pad_len = 0u;
    for (i = 0u; i < input_length - (2u * hash_size) - 2u; i++) {
        if (output[(2u * hash_size) + 1u + i] == 0u) {
            pad_len += 1;
        } else {
            break;
        }
    }

    if (output[(2 * hash_size) + 1u + pad_len] != 1u) {
        return PSA_ERROR_BAD_STATE;
    }

    *output_length = key_bytes - ((2u * hash_size) + 2u + pad_len);
    memcpy(output, &output[key_bytes - *output_length], *output_length);
    memset(&output[*output_length], 0u, key_bytes - *output_length);

    return PSA_SUCCESS;
}
#endif

/** \defgroup psa_asym_encrypt PSA driver entry points for rsa cipher
 *
 *  Entry points for rsa cipher encryption and decryption as described
 *  by the PSA Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t caam_common_asymmetric_encrypt(mcux_psa_caam_key_type_t caam_key_type,
                                            const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *input,
                                            size_t input_length,
                                            const uint8_t *salt,
                                            size_t salt_length,
                                            uint8_t *output,
                                            size_t output_size,
                                            size_t *output_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

    *output_length = 0u;

#if defined(PSA_WANT_ALG_RSA_PKCS1V15_CRYPT)
    if ((alg == PSA_ALG_RSA_PKCS1V15_CRYPT) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_rsa_encrypt_pkcs1_5(caam_key_type,
                                                          attributes,
                                                          key_buffer,
                                                          key_buffer_size,
                                                          alg,
                                                          input,
                                                          input_length,
                                                          output,
                                                          output_size,
                                                          output_length);
    } else
#endif /* PSA_WANT_ALG_RSA_PKCS1V15_CRYPT */
#if defined(PSA_WANT_ALG_RSA_OAEP)
    if (PSA_ALG_RSA_OAEP(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status =
            caam_common_internal_rsa_encrypt_oaep(caam_key_type,
                                                  attributes,
                                                  key_buffer,
                                                  key_buffer_size,
                                                  alg,
                                                  input,
                                                  input_length,
                                                  salt,
                                                  salt_length,
                                                  output,
                                                  output_size,
                                                  output_length);
    } else
#endif /* PSA_WANT_ALG_RSA_OAEP */
    {
    }

    (void)key_type;

    return status;
}

psa_status_t caam_common_asymmetric_decrypt(mcux_psa_caam_key_type_t caam_key_type,
                                            const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *input,
                                            size_t input_length,
                                            const uint8_t *salt,
                                            size_t salt_length,
                                            uint8_t *output,
                                            size_t output_size,
                                            size_t *output_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

    *output_length = 0u;

#if defined(PSA_WANT_ALG_RSA_PKCS1V15_CRYPT)
    if ((alg == PSA_ALG_RSA_PKCS1V15_CRYPT) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_rsa_decrypt_pkcs1_5(caam_key_type,
                                                          attributes,
                                                          key_buffer,
                                                          key_buffer_size,
                                                          alg,
                                                          input,
                                                          input_length,
                                                          output,
                                                          output_size,
                                                          output_length);
    } else
#endif /* PSA_WANT_ALG_RSA_PKCS1V15_CRYPT */
#if defined(PSA_WANT_ALG_RSA_OAEP)
    if (PSA_ALG_RSA_OAEP(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status =
            caam_common_internal_rsa_decrypt_oaep(caam_key_type,
                                                  attributes,
                                                  key_buffer,
                                                  key_buffer_size,
                                                  alg,
                                                  input,
                                                  input_length,
                                                  salt,
                                                  salt_length,
                                                  output,
                                                  output_size,
                                                  output_length);
    } else
#endif /* PSA_WANT_ALG_RSA_OAEP */
    {
    }

    (void)key_type;

    return status;
}
/** @} */ // end of psa_asym_encrypt
