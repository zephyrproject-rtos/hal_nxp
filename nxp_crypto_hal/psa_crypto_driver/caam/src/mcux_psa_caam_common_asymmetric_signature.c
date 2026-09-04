/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_common_asymmetric_signature.c
 *
 * This file contains the implementation of the entry points associated to the
 * ecc signature capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */
#include "mcux_psa_caam_common_asymmetric_signature.h"
#include "mcux_psa_common_key_management.h"
#include "mcux_psa_caam_init.h"
#include "mcux_psa_caam_hash.h"
#include "mcux_psa_mbedtls_origin.h"
#include "mcux_psa_caam_common_asymmetric_encryption.h"
#include "mcux_psa_caam_utils.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

#include "psa/crypto.h"
#include "psa_crypto_rsa.h"

#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#include "mbedtls/error.h"
#include "mbedtls/psa_util.h"

/** \defgroup psa_asym_sign PSA driver entry points for rsa sign/verify
 *
 *  Entry points for rsa message signing and signature verification as
 *  described by the PSA Cryptoprocessor Driver interface specification
 *
 *  @{
 */

extern psa_status_t caam_common_internal_rsa_encrypt(mcux_psa_caam_key_type_t caam_key_type,
                                                     caam_rsa_format_type_t format,
                                                     const psa_key_attributes_t *attributes,
                                                     const uint8_t *key_buffer,
                                                     size_t key_buffer_size,
                                                     psa_algorithm_t alg,
                                                     const uint8_t *input,
                                                     size_t input_length,
                                                     uint8_t *output,
                                                     size_t output_size,
                                                     size_t *output_length);

extern psa_status_t caam_common_internal_rsa_decrypt(mcux_psa_caam_key_type_t caam_key_type,
                                                     caam_rsa_format_type_t format,
                                                     const psa_key_attributes_t *attributes,
                                                     const uint8_t *key_buffer,
                                                     size_t key_buffer_size,
                                                     psa_algorithm_t alg,
                                                     const uint8_t *input,
                                                     size_t input_length,
                                                     uint8_t *output,
                                                     size_t output_size,
                                                     size_t *output_length);

typedef psa_status_t (sign_t)(mcux_psa_caam_key_type_t caam_key_type,
                              const psa_key_attributes_t *attributes,
                              const uint8_t *key,
                              size_t key_length,
                              psa_algorithm_t alg,
                              const uint8_t *input,
                              size_t input_length,
                              uint8_t *signature,
                              size_t signature_size,
                              size_t *signature_length);

typedef psa_status_t (verify_t)(mcux_psa_caam_key_type_t caam_key_type,
                                const psa_key_attributes_t *attributes,
                                const uint8_t *key,
                                size_t key_length,
                                psa_algorithm_t alg,
                                const uint8_t *input,
                                size_t input_length,
                                const uint8_t *signature,
                                size_t signature_length);

static inline psa_status_t caam_ecc_key_type(mcux_psa_caam_key_type_t caam_key_type,
                                             caam_ecc_encryption_type_t *ecc_key_type)
{
    switch (caam_key_type) {
        case MCUX_PSA_CAAM_KEY_TYPE_NONE:
        {
            *ecc_key_type = kCAAM_Ecc_Encryption_Type_None;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_ECB:
        {
            *ecc_key_type = kCAAM_Ecc_Encryption_Type_Ecb_Jkek;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_CCM:
        {
            *ecc_key_type = kCAAM_Ecc_Encryption_Type_Ccm_Jkek;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
static psa_status_t caam_common_internal_ecc_sign(mcux_psa_caam_key_type_t caam_key_type,
                                                  const psa_key_attributes_t *attributes,
                                                  const uint8_t *key,
                                                  size_t key_length,
                                                  psa_algorithm_t alg,
                                                  const uint8_t *input,
                                                  size_t input_length,
                                                  uint8_t *signature,
                                                  size_t signature_size,
                                                  size_t *signature_length)
{
    psa_status_t err;
    psa_status_t err2       = PSA_SUCCESS;
    psa_status_t err3       = PSA_SUCCESS;
    status_t caam_status    = kStatus_Fail;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);
    uint32_t key_bytes      = PSA_BITS_TO_BYTES(key_bits);
    caam_ecc_ecdsel_t ecc_ecdsel;
    mbedtls_ecp_group_id ecp_grou_id;
    struct mcux_ecc_keypair ecc_key;
    caam_ecc_encryption_type_t ecc_key_type;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };

    err = psa_to_caam_ecc_key_algo(key_type, key_bits, &ecc_ecdsel, &ecp_grou_id);
    if (err != PSA_SUCCESS) {
        return err;
    }

    err = caam_ecc_key_type(caam_key_type, &ecc_key_type);
    if (err != PSA_SUCCESS) {
        return err;
    }

    /* Check for input buffer size in case it is hash it should match the algorithm size */
    if (input_length > key_bytes) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Guard multiplication against unsigned wrap */
    if (mcux_psa_mul_size_t_wrapcheck(key_bytes, 2)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    if (signature_size < 2U * key_bytes) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        /* Parse input - We will use mbedtls_ecsda_context to parse the context into*/
        err = mcux_key_buf_to_raw_ecc(key_type,
                                      key,
                                      key_length,
                                      MCUX_KEY_TYPE_PRIVATE,
                                      ecp_grou_id,
                                      &ecc_key);
    } else {
        err = mcux_alloc_raw_ecc(&ecc_key, key_bytes, MCUX_KEY_TYPE_PRIVATE, true);
        if (err == PSA_SUCCESS) {
            err = caam_opaque_decapsulate_key(caam_key_type,
                                              &key[CAAM_ECC_PUBLIC_KEY_LENGTH(ecc_ecdsel)+1u],
                                              key_length -
                                              (CAAM_ECC_PUBLIC_KEY_LENGTH(ecc_ecdsel)+1u),
                                              ecc_key.private_key,
                                              key_bytes);
        }
    }

    if ((err == PSA_SUCCESS) && (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0)) {
        err  = PSA_ERROR_SERVICE_FAILURE;
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        caam_status = CAAM_ECC_Sign(PSA_CAAM,
                                    &caam_handle,
                                    ecc_key.private_key,
                                    input,
                                    input_length,
                                    ecc_ecdsel,
                                    ecc_key_type,
                                    signature,
                                    &signature[key_bytes]);
        err         = caam_to_psa_status(caam_status);
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    err3 = mcux_free_raw_ecc(&ecc_key);

    if (err2 != PSA_SUCCESS) {
        return err2;
    }
    if (err3 != PSA_SUCCESS) {
        return err3;
    }

    if (err == PSA_SUCCESS) {
        *signature_length = 2 * key_bytes;
    }

    return err;
}

static psa_status_t caam_common_internal_ecc_verify(mcux_psa_caam_key_type_t caam_key_type,
                                                    const psa_key_attributes_t *attributes,
                                                    const uint8_t *key,
                                                    size_t key_length,
                                                    psa_algorithm_t alg,
                                                    const uint8_t *input,
                                                    size_t input_length,
                                                    const uint8_t *signature,
                                                    size_t signature_length)
{
    psa_status_t err        = PSA_ERROR_NOT_SUPPORTED;
    psa_status_t err2       = PSA_SUCCESS;
    psa_status_t err3       = PSA_SUCCESS;
    status_t caam_status    = kStatus_Fail;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);
    uint32_t key_bytes      = PSA_BITS_TO_BYTES(key_bits);
    caam_ecc_ecdsel_t ecc_ecdsel;
    mbedtls_ecp_group_id ecp_grou_id;
    struct mcux_ecc_keypair ecc_key;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
#if defined(USE_MALLOC)
    uint8_t *tmp;
#else
    uint8_t tmp[150];
#endif

    err = psa_to_caam_ecc_key_algo(key_type, key_bits, &ecc_ecdsel, &ecp_grou_id);
    if (err != PSA_SUCCESS) {
        return err;
    }

    /* Check for input buffer size in case it is hash it should match the algorithm size */
    if (input_length > key_bytes) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (signature_length < 2 * key_bytes) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        /* Parse input - We will use mbedtls_ecsda_context to parse the context into*/
        err = mcux_key_buf_to_raw_ecc(key_type,
                                      key,
                                      key_length,
                                      MCUX_KEY_TYPE_PUBLIC,
                                      ecp_grou_id,
                                      &ecc_key);
        if (err != PSA_SUCCESS) {
            return err;
        }
    } else {
        ecc_key.public_key     = (uint8_t *) key;
        ecc_key.public_key_len = CAAM_ECC_PUBLIC_KEY_LENGTH(ecc_ecdsel)+1u;
    }

#if defined(USE_MALLOC)
    if (err == PSA_SUCCESS) {
        tmp = (uint8_t *) mbedtls_calloc(1u, key_bytes * 2u);
        if (tmp == NULL) {
            err = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
    }
#endif

    if (err == PSA_SUCCESS) {
        if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
            err  = PSA_ERROR_SERVICE_FAILURE;
            err2 = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    if (err == PSA_SUCCESS) {
        caam_status = CAAM_ECC_VerifyPublicKey(PSA_CAAM,
                                               &caam_handle,
                                               &ecc_key.public_key[1],
                                               input,
                                               input_length,
                                               signature,
                                               &signature[key_bytes],
                                               ecc_ecdsel,
                                               tmp);
        err         = caam_to_psa_status(caam_status);
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

#if defined(USE_MALLOC)
    if (tmp != NULL) {
        mbedtls_free(tmp);
    }
#endif

    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        err3 = mcux_free_raw_ecc(&ecc_key);
    }

    if (err2 != PSA_SUCCESS) {
        return err2;
    }
    if (err3 != PSA_SUCCESS) {
        return err3;
    }

    return err;
}
#endif /* PSA_WANT_ALG_ECDSA || PSA_WANT_ALG_ECDSA_ANY */

#if defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN) || defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW)
static psa_status_t caam_common_internal_rsa_pkcs1_5_sign(mcux_psa_caam_key_type_t caam_key_type,
                                                          const psa_key_attributes_t *attributes,
                                                          const uint8_t *key,
                                                          size_t key_length,
                                                          psa_algorithm_t alg,
                                                          const uint8_t *input,
                                                          size_t input_length,
                                                          uint8_t *signature,
                                                          size_t signature_size,
                                                          size_t *signature_length)
{
    int mbedtls_err;
    psa_status_t err        = PSA_SUCCESS;
    size_t key_bits         = psa_get_key_bits(attributes);
    uint32_t key_bytes      = PSA_BITS_TO_BYTES(key_bits);
    uint8_t hash_size       = PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg));
#if defined(USE_MALLOC)
    uint8_t *_input = NULL;
#else
    uint8_t _input[MAX_RSA_KEYSIZE];
    if (key_bytes < MAX_RSA_KEYSIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    /* If user sends a buffer with 0 size, return error */
    if (signature == NULL) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (signature_size < key_bytes) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if ((key_bytes < 11u) || (input_length > (key_bytes - 11u))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((hash_size > 0u) && (hash_size != input_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

#if defined(USE_MALLOC)
    _input = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (_input == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    mbedtls_err = rsa_rsassa_pkcs1_v15_encode(mbedtls_md_type_from_psa_alg(alg),
                                              input_length,
                                              input,
                                              key_bytes,
                                              _input);
    if (mbedtls_err != 0) {
        err = PSA_ERROR_BAD_STATE;
    }

    if (err == PSA_SUCCESS) {
        err = caam_common_internal_rsa_decrypt(caam_key_type,
                                               kCAAM_Rsa_Format_Type_None,
                                               attributes,
                                               key,
                                               key_length,
                                               alg,
                                               _input,
                                               key_bytes,
                                               signature,
                                               signature_size,
                                               signature_length);
    }

#if defined(USE_MALLOC)
    if (_input != NULL) {
        mbedtls_free(_input);
    }
#endif

    return err;
}

static psa_status_t caam_common_internal_rsa_pkcs1_5_verify(mcux_psa_caam_key_type_t caam_key_type,
                                                            const psa_key_attributes_t *attributes,
                                                            const uint8_t *key,
                                                            size_t key_length,
                                                            psa_algorithm_t alg,
                                                            const uint8_t *input,
                                                            size_t input_length,
                                                            const uint8_t *signature,
                                                            size_t signature_length)
{
    int mbedtls_err;
    psa_status_t err        = PSA_SUCCESS;
    size_t key_bits         = psa_get_key_bits(attributes);
    uint32_t key_bytes      = PSA_BITS_TO_BYTES(key_bits);
    uint8_t hash_size       = PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg));
    size_t output_length;
#if defined(USE_MALLOC)
    uint8_t *output = NULL;
    uint8_t *_input = NULL;
#else
    uint8_t output[MAX_RSA_KEYSIZE];
    if (key_bytes < MAX_RSA_KEYSIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
    uint8_t _input[MAX_RSA_KEYSIZE];
    if (key_bytes < MAX_RSA_KEYSIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    // No check on input as input can be NULL
    if (signature == NULL) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (signature_length != key_bytes) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Check for  input message length . For PKCS#1.5 padding is 11 bytes */
    if ((key_bytes < 11u) || (input_length > (key_bytes - 11u))) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if ((hash_size > 0u) && (hash_size != input_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

#if defined(USE_MALLOC)
    output = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (output == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
    _input = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (_input == NULL) {
        err = PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    if (err == PSA_SUCCESS) {
        err = caam_common_internal_rsa_encrypt(caam_key_type,
                                               kCAAM_Rsa_Format_Type_None,
                                               attributes,
                                               key,
                                               key_length,
                                               alg,
                                               signature,
                                               signature_length,
                                               output,
                                               key_bytes,
                                               &output_length);
    }

    if (err == PSA_SUCCESS) {
        mbedtls_err = rsa_rsassa_pkcs1_v15_encode(mbedtls_md_type_from_psa_alg(alg),
                                                  input_length,
                                                  input,
                                                  key_bytes,
                                                  _input);
        if (mbedtls_err != 0) {
            err = PSA_ERROR_BAD_STATE;
        }
    }

    if (err == PSA_SUCCESS) {
        if (memcmp(_input, output, key_bytes) != 0) {
            err = PSA_ERROR_INVALID_SIGNATURE;
        }
    }

#if defined(USE_MALLOC)
    if (output != NULL) {
        mbedtls_free(output);
    }
    if (_input != NULL) {
        mbedtls_free(_input);
    }
#endif

    return err;
}
#endif /* PSA_WANT_ALG_RSA_PKCS1V15_SIGN || PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW */

#if defined(PSA_WANT_ALG_RSA_PSS)
static psa_status_t caam_common_internal_rsa_pss_sign(mcux_psa_caam_key_type_t caam_key_type,
                                                      const psa_key_attributes_t *attributes,
                                                      const uint8_t *key,
                                                      size_t key_length,
                                                      psa_algorithm_t alg,
                                                      const uint8_t *input,
                                                      size_t input_length,
                                                      uint8_t *signature,
                                                      size_t signature_size,
                                                      size_t *signature_length)
{
    int mbedtls_err;
    psa_status_t err        = PSA_SUCCESS;
    size_t key_bits         = psa_get_key_bits(attributes);
    uint32_t key_bytes      = PSA_BITS_TO_BYTES(key_bits);
    uint8_t hash_size       = PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg));
#if defined(USE_MALLOC)
    uint8_t *_input = NULL;
#else
    uint8_t _input[MAX_RSA_KEYSIZE];
    if (key_bytes < MAX_RSA_KEYSIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    /* If user sends a buffer with 0 size, return error */
    if (signature == NULL) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if ((hash_size > 0u) && (hash_size != input_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

#if defined(USE_MALLOC)
    _input = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (_input == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    mbedtls_err = rsa_rsassa_pss_sign_encode(mbedtls_psa_get_random,
                                             MBEDTLS_PSA_RANDOM_STATE,
                                             mbedtls_md_type_from_psa_alg(alg),
                                             key_bytes,
                                             input_length,
                                             input,
                                             PSA_ALG_IS_RSA_PSS_STANDARD_SALT(alg) ? hash_size : -1,
                                             _input,
                                             key_bytes);
    if (mbedtls_err != 0) {
        err = PSA_ERROR_BAD_STATE;
    }

    if (err == PSA_SUCCESS) {
        err = caam_common_internal_rsa_decrypt(caam_key_type,
                                               kCAAM_Rsa_Format_Type_None,
                                               attributes,
                                               key,
                                               key_length,
                                               alg,
                                               _input,
                                               key_bytes,
                                               signature,
                                               signature_size,
                                               signature_length);
    }

#if defined(USE_MALLOC)
    if (_input != NULL) {
        mbedtls_free(_input);
    }
#endif

    return err;
}

static psa_status_t caam_common_internal_rsa_pss_verify(mcux_psa_caam_key_type_t caam_key_type,
                                                        const psa_key_attributes_t *attributes,
                                                        const uint8_t *key,
                                                        size_t key_length,
                                                        psa_algorithm_t alg,
                                                        const uint8_t *input,
                                                        size_t input_length,
                                                        const uint8_t *signature,
                                                        size_t signature_length)
{
    int mbedtls_err;
    psa_status_t err        = PSA_SUCCESS;
    size_t key_bits         = psa_get_key_bits(attributes);
    uint32_t key_bytes      = PSA_BITS_TO_BYTES(key_bits);
    uint8_t hash_size       = PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg));
    size_t output_length;
#if defined(USE_MALLOC)
    uint8_t *output = NULL;
#else
    uint8_t output[MAX_RSA_KEYSIZE];
    if (key_bytes < MAX_RSA_KEYSIZE) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    // No check on input as input can be NULL
    if (signature == NULL) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (signature_length != key_bytes) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if ((hash_size > 0u) && (hash_size != input_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

#if defined(USE_MALLOC)
    output = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (output == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    if (err == PSA_SUCCESS) {
        err = caam_common_internal_rsa_encrypt(caam_key_type,
                                               kCAAM_Rsa_Format_Type_None,
                                               attributes,
                                               key,
                                               key_length,
                                               alg,
                                               signature,
                                               signature_length,
                                               output,
                                               key_bytes,
                                               &output_length);
    }

    if (err == PSA_SUCCESS) {
        mbedtls_err = mbedtls_rsa_rsassa_pss_verify_check(
            mbedtls_md_type_from_psa_alg(alg),
            key_bytes,
            input_length,
            input,
            PSA_ALG_IS_RSA_PSS_STANDARD_SALT(alg) ? hash_size : -1,
            output);
        if (mbedtls_err != 0) {
            err = PSA_ERROR_BAD_STATE;
        }
    }

#if defined(USE_MALLOC)
    if (output != NULL) {
        mbedtls_free(output);
    }
#endif

    return err;
}
#endif /* PSA_WANT_ALG_RSA_PSS */

#if defined(PSA_WANT_ALG_ECDSA) || \
    defined(PSA_WANT_ALG_ECDSA_ANY) || \
    defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN) || \
    defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW) || \
    defined(PSA_WANT_ALG_RSA_PSS)
static psa_status_t caam_common_internal_sign_msg(mcux_psa_caam_key_type_t caam_key_type,
                                                  const psa_key_attributes_t *attributes,
                                                  const uint8_t *key,
                                                  size_t key_length,
                                                  psa_algorithm_t alg,
                                                  const uint8_t *input,
                                                  size_t input_length,
                                                  uint8_t *signature,
                                                  size_t signature_size,
                                                  size_t *signature_length,
                                                  sign_t sign_func)
{
    psa_status_t err        = PSA_ERROR_NOT_SUPPORTED;
    uint8_t hash_size       = PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg));
    size_t output_hash_size = 0;

#if defined(USE_MALLOC)
    uint8_t *hash = (uint8_t *) mbedtls_calloc(1u, hash_size);
    if (hash == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#else
    uint8_t hash[72];
#endif

    err = caam_hash_compute(alg, input, input_length, hash, hash_size, &output_hash_size);

    if (err == PSA_SUCCESS) {
        if (hash_size != output_hash_size) {
            return PSA_ERROR_BAD_STATE;
        }

        err = sign_func(caam_key_type,
                        attributes,
                        key,
                        key_length,
                        alg,
                        hash,
                        output_hash_size,
                        signature,
                        signature_size,
                        signature_length);
    }

#if defined(USE_MALLOC)
    mbedtls_free(hash);
#endif

    return err;
}

static psa_status_t caam_common_internal_verify_msg(mcux_psa_caam_key_type_t caam_key_type,
                                                    const psa_key_attributes_t *attributes,
                                                    const uint8_t *key,
                                                    size_t key_length,
                                                    psa_algorithm_t alg,
                                                    const uint8_t *input,
                                                    size_t input_length,
                                                    const uint8_t *signature,
                                                    size_t signature_length,
                                                    verify_t verify_func)
{
    psa_status_t err        = PSA_ERROR_NOT_SUPPORTED;
    uint8_t hash_size       = PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg));
    size_t output_hash_size = 0;

#if defined(USE_MALLOC)
    uint8_t *hash = (uint8_t *) mbedtls_calloc(1u, hash_size);
    if (hash == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#else
    uint8_t hash[72];
#endif

    err = caam_hash_compute(alg, input, input_length, hash, hash_size, &output_hash_size);

    if (err == PSA_SUCCESS) {
        if (hash_size != output_hash_size) {
            return PSA_ERROR_BAD_STATE;
        }

        err = verify_func(caam_key_type,
                          attributes,
                          key,
                          key_length,
                          alg,
                          hash,
                          hash_size,
                          signature,
                          signature_length);
    }

#if defined(USE_MALLOC)
    mbedtls_free(hash);
#endif

    return err;
}
#endif /* PSA_WANT_ALG_ECDSA || PSA_WANT_ALG_ECDSA_ANY) || PSA_WANT_ALG_RSA_PKCS1V15_SIGN || PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW || PSA_WANT_ALG_RSA_PSS */

psa_status_t caam_common_asymmetric_sign_hash(mcux_psa_caam_key_type_t caam_key_type,
                                              const psa_key_attributes_t *attributes,
                                              const uint8_t *key,
                                              size_t key_length,
                                              psa_algorithm_t alg,
                                              const uint8_t *input,
                                              size_t input_length,
                                              uint8_t *signature,
                                              size_t signature_size,
                                              size_t *signature_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

    *signature_length = 0;

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
    if (PSA_ALG_IS_RANDOMIZED_ECDSA(alg) && PSA_KEY_TYPE_IS_ECC(key_type)) {
        status = caam_common_internal_ecc_sign(caam_key_type,
                                               attributes,
                                               key,
                                               key_length,
                                               alg,
                                               input,
                                               input_length,
                                               signature,
                                               signature_size,
                                               signature_length);
    } else
#endif /* PSA_WANT_ALG_ECDSA */
#if defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN) || defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW)
    if (PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_rsa_pkcs1_5_sign(caam_key_type,
                                                       attributes,
                                                       key,
                                                       key_length,
                                                       alg,
                                                       input,
                                                       input_length,
                                                       signature,
                                                       signature_size,
                                                       signature_length);
    } else
#endif /* PSA_WANT_ALG_RSA_PKCS1V15_SIGN */
#if defined(PSA_WANT_ALG_RSA_PSS)
    if (PSA_ALG_IS_RSA_PSS(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_rsa_pss_sign(caam_key_type,
                                                   attributes,
                                                   key,
                                                   key_length,
                                                   alg,
                                                   input,
                                                   input_length,
                                                   signature,
                                                   signature_size,
                                                   signature_length);
    } else
#endif /* PSA_WANT_ALG_RSA_PSS */
    {
    }

    (void)key_type;

    return status;
}

psa_status_t caam_common_asymmetric_verify_hash(mcux_psa_caam_key_type_t caam_key_type,
                                                const psa_key_attributes_t *attributes,
                                                const uint8_t *key,
                                                size_t key_length,
                                                psa_algorithm_t alg,
                                                const uint8_t *hash,
                                                size_t hash_length,
                                                const uint8_t *signature,
                                                size_t signature_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
    if (PSA_ALG_IS_RANDOMIZED_ECDSA(alg) && PSA_KEY_TYPE_IS_ECC(key_type)) {
        status = caam_common_internal_ecc_verify(caam_key_type,
                                                 attributes,
                                                 key,
                                                 key_length,
                                                 alg,
                                                 hash,
                                                 hash_length,
                                                 signature,
                                                 signature_length);
    } else
#endif /* PSA_WANT_ALG_ECDSA */
#if defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN) || defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW)
    if (PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_rsa_pkcs1_5_verify(caam_key_type,
                                                         attributes,
                                                         key,
                                                         key_length,
                                                         alg,
                                                         hash,
                                                         hash_length,
                                                         signature,
                                                         signature_length);
    } else
#endif /* PSA_WANT_ALG_RSA_PKCS1V15_SIGN */
#if defined(PSA_WANT_ALG_RSA_PSS)
    if (PSA_ALG_IS_RSA_PSS(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_rsa_pss_verify(caam_key_type,
                                                     attributes,
                                                     key,
                                                     key_length,
                                                     alg,
                                                     hash,
                                                     hash_length,
                                                     signature,
                                                     signature_length);
    } else
#endif /* PSA_WANT_ALG_RSA_PSS */
    {
    }

    (void)key_type;

    return status;
}

psa_status_t caam_common_asymmetric_sign_message(mcux_psa_caam_key_type_t caam_key_type,
                                                 const psa_key_attributes_t *attributes,
                                                 const uint8_t *key,
                                                 size_t key_length,
                                                 psa_algorithm_t alg,
                                                 const uint8_t *input,
                                                 size_t input_length,
                                                 uint8_t *signature,
                                                 size_t signature_size,
                                                 size_t *signature_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

    *signature_length = 0;

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
    if (PSA_ALG_IS_RANDOMIZED_ECDSA(alg) && PSA_KEY_TYPE_IS_ECC(key_type)) {
        status =
            caam_common_internal_sign_msg(caam_key_type,
                                          attributes,
                                          key,
                                          key_length,
                                          alg,
                                          input,
                                          input_length,
                                          signature,
                                          signature_size,
                                          signature_length,
                                          caam_common_internal_ecc_sign);
    } else
#endif /* PSA_WANT_ALG_ECDSA */
#if defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN) || defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW)
    if (PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_sign_msg(caam_key_type,
                                               attributes,
                                               key,
                                               key_length,
                                               alg,
                                               input,
                                               input_length,
                                               signature,
                                               signature_size,
                                               signature_length,
                                               caam_common_internal_rsa_pkcs1_5_sign);
    } else
#endif /* PSA_WANT_ALG_RSA */
#if defined(PSA_WANT_ALG_RSA_PSS)
    if (PSA_ALG_IS_RSA_PSS(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_sign_msg(caam_key_type,
                                               attributes,
                                               key,
                                               key_length,
                                               alg,
                                               input,
                                               input_length,
                                               signature,
                                               signature_size,
                                               signature_length,
                                               caam_common_internal_rsa_pss_sign);
    } else
#endif /* PSA_WANT_ALG_RSA_PSS */
    {
    }

    (void)key_type;

    return status;
}

psa_status_t caam_common_asymmetric_verify_message(mcux_psa_caam_key_type_t caam_key_type,
                                                   const psa_key_attributes_t *attributes,
                                                   const uint8_t *key,
                                                   size_t key_length,
                                                   psa_algorithm_t alg,
                                                   const uint8_t *input,
                                                   size_t input_length,
                                                   const uint8_t *signature,
                                                   size_t signature_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
    if (PSA_ALG_IS_RANDOMIZED_ECDSA(alg) && PSA_KEY_TYPE_IS_ECC(key_type)) {
        status = caam_common_internal_verify_msg(caam_key_type,
                                                 attributes,
                                                 key,
                                                 key_length,
                                                 alg,
                                                 input,
                                                 input_length,
                                                 signature,
                                                 signature_length,
                                                 caam_common_internal_ecc_verify);
    } else
#endif /* PSA_WANT_ALG_ECDSA */
#if defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN) || defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW)
    if (PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_verify_msg(caam_key_type,
                                                 attributes,
                                                 key,
                                                 key_length,
                                                 alg,
                                                 input,
                                                 input_length,
                                                 signature,
                                                 signature_length,
                                                 caam_common_internal_rsa_pkcs1_5_verify);
    } else
#endif /* PSA_WANT_ALG_RSA */
#if defined(PSA_WANT_ALG_RSA_PSS)
    if (PSA_ALG_IS_RSA_PSS(alg) && PSA_KEY_TYPE_IS_RSA(key_type)) {
        status = caam_common_internal_verify_msg(caam_key_type,
                                                 attributes,
                                                 key,
                                                 key_length,
                                                 alg,
                                                 input,
                                                 input_length,
                                                 signature,
                                                 signature_length,
                                                 caam_common_internal_rsa_pss_verify);
    } else
#endif /* PSA_WANT_ALG_RSA_PSS */
    {
    }

    (void)key_type;

    return status;
}
/** @} */ // end of psa_asym_sign
