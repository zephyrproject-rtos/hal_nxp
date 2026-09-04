/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_common_rsa_key_generation.c
 *
 * This file contains the implementation of the entry points associated to the
 * key generation (i.e. random generation and extraction of public keys) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_caam_common_key_generation.h"
#include "mcux_psa_common_key_management.h"
#include "mcux_psa_caam_init.h"
#include "mcux_psa_caam_utils.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"
#include "psa_crypto_storage.h"
#include "mbedtls/psa_util.h"
#include "mbedtls/platform.h"

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

#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE)
static psa_status_t caam_internal_ecc_generate_key(mcux_psa_caam_key_type_t caam_key_type,
                                                   const psa_key_attributes_t *attributes,
                                                   uint8_t *key_buffer,
                                                   size_t key_buffer_size,
                                                   size_t *key_buffer_length)
{
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = PSA_BITS_TO_BYTES(key_bits);
    psa_status_t err          = PSA_ERROR_NOT_SUPPORTED;
    psa_status_t err2         = PSA_SUCCESS;
    psa_status_t err3         = PSA_SUCCESS;
    status_t caam_status      = kStatus_Fail;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    caam_ecc_encryption_type_t ecc_key_type;
    caam_ecc_ecdsel_t ecc_ecdsel;
    mbedtls_ecp_group_id ecp_grou_id;

    struct mcux_ecc_keypair ecc_key;

    err = psa_to_caam_ecc_key_algo(key_type, key_bits, &ecc_ecdsel, &ecp_grou_id);
    if (err != PSA_SUCCESS) {
        return err;
    }

    err = caam_ecc_key_type(caam_key_type, &ecc_key_type);
    if (err != PSA_SUCCESS) {
        return err;
    }

    err =
        mcux_alloc_raw_ecc(&ecc_key, key_bytes, MCUX_KEY_TYPE_KEYPAIR,
                           (caam_key_type != MCUX_PSA_CAAM_KEY_TYPE_NONE));
    if (err != PSA_SUCCESS) {
        return err;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        err  = PSA_ERROR_SERVICE_FAILURE;
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        caam_status = CAAM_ECC_KeyPair(PSA_CAAM,
                                       &caam_handle,
                                       ecc_ecdsel,
                                       ecc_key_type,
                                       ecc_key.private_key,
                                       &ecc_key.public_key[1]);
        err         = caam_to_psa_status(caam_status);
    }

    if (err == PSA_SUCCESS) {
        ecc_key.public_key[0] = 0x4;
        if (ecc_key_type != kCAAM_Ecc_Encryption_Type_None) {
            err = caam_opaque_encapsulate_key(caam_key_type,
                                              ecc_key.private_key,
                                              key_bytes,
                                              &key_buffer[ecc_key.public_key_len],
                                              key_buffer_size - ecc_key.public_key_len,
                                              key_buffer_length);
            if (err == PSA_SUCCESS) {
                memcpy(key_buffer, ecc_key.public_key, ecc_key.public_key_len);
                *key_buffer_length += ecc_key.public_key_len;
            }
        }
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        if (ecc_key_type == kCAAM_Ecc_Encryption_Type_None) {
            /* The Key needs to be now converted to ASN1 structure */
            err = mcux_raw_ecc_to_key_buf(key_type,
                                          false,
                                          &ecc_key,
                                          ecp_grou_id,
                                          key_buffer,
                                          key_buffer_size,
                                          key_buffer_length);
        }
    }

    err3 = mcux_free_raw_ecc(&ecc_key);
    if (err2 != PSA_SUCCESS) {
        return err2;
    }
    if (err3 != PSA_SUCCESS) {
        return err3;
    }

    return err;
}
#endif /* PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE */

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER < 0x04000000)
static inline psa_status_t psa_to_caam_rsa_key_type(mcux_psa_caam_key_type_t caam_key_type,
                                                    caam_rsa_key_type_t *rsa_key_type)
{
    switch (caam_key_type) {
        case MCUX_PSA_CAAM_KEY_TYPE_NONE:
        {
            *rsa_key_type = kCAAM_Rsa_Key_Type_None;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_ECB:
        {
            *rsa_key_type = kCAAM_Rsa_Key_Type_Ecb_Jkek;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_CCM:
        {
            *rsa_key_type = kCAAM_Rsa_Key_Type_Ccm_Jkek;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}
#endif

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER < 0x04000000)
static psa_status_t caam_internal_rsa_generate_key(mcux_psa_caam_key_type_t caam_key_type,
                                                   const psa_key_attributes_t *attributes,
                                                   uint8_t *key_buffer,
                                                   size_t key_buffer_size,
                                                   size_t *key_buffer_length)
{
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = PSA_BITS_TO_BYTES(key_bits);
    psa_status_t err          = PSA_ERROR_NOT_SUPPORTED;
    psa_status_t err2         = PSA_SUCCESS;
    psa_status_t err3         = PSA_SUCCESS;
    psa_status_t err4         = PSA_SUCCESS;
    status_t caam_status      = kStatus_Fail;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    caam_rsa_key_type_t rsa_key_type;
    uint8_t rsa_exp[4]; // Needed to make it working for cache
    rsa_exp[0] = 0u;
    memcpy(&rsa_exp[1], &s_rsa_exponent, 3u);

    struct mcux_rsa_keypair rsa_key;
    struct mcux_rsa_primes primes;

    if ((key_bits % 1024u) != 0u) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    err = psa_to_caam_rsa_key_type(caam_key_type, &rsa_key_type);
    if (err != PSA_SUCCESS) {
        return err;
    }

    err =
        mcux_alloc_raw_rsa(&rsa_key, key_bytes, MCUX_KEY_TYPE_KEYPAIR,
                           (caam_key_type != MCUX_PSA_CAAM_KEY_TYPE_NONE));
    if (err != PSA_SUCCESS) {
        return err;
    }

    err = mcux_rsa_generate_primes(key_bits, &primes);
    if (err != PSA_SUCCESS) {
        return err;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        err  = PSA_ERROR_SERVICE_FAILURE;
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        caam_status = CAAM_RSA_KeyPair(PSA_CAAM,
                                       &caam_handle,
                                       primes.p,
                                       primes.q,
                                       primes.len,
                                       rsa_exp,
                                       sizeof(rsa_exp),
                                       rsa_key_type,
                                       rsa_key.modulus,
                                       rsa_key.modulus_len,
                                       rsa_key.priv_exp,
                                       &rsa_key.priv_exp_len);
        err         = caam_to_psa_status(caam_status);
    }

    if (err == PSA_SUCCESS) {
        if (rsa_key_type != kCAAM_Rsa_Key_Type_None) {
            err = caam_opaque_encapsulate_key(caam_key_type,
                                              rsa_key.priv_exp,
                                              rsa_key.priv_exp_len,
                                              &key_buffer[rsa_key.modulus_len + sizeof(size_t)],
                                              key_buffer_size - rsa_key.modulus_len- sizeof(size_t),
                                              key_buffer_length);
            if (err == PSA_SUCCESS) {
                memcpy(key_buffer, rsa_key.modulus, rsa_key.modulus_len);
                *key_buffer_length += rsa_key.modulus_len;
                memcpy(&key_buffer[rsa_key.modulus_len], (uint8_t *) &rsa_key.priv_exp_len,
                       sizeof(size_t));
                *key_buffer_length += sizeof(size_t);
            }
        }
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if ((err == PSA_SUCCESS) && (err2 == PSA_SUCCESS)) {
        if (rsa_key_type == kCAAM_Rsa_Key_Type_None) {
            /* The Key needs to be now converted to ASN1 structure */
            err = mcux_raw_rsa_to_key_buf(key_type,
                                          false,
                                          &rsa_key,
                                          key_buffer,
                                          key_buffer_size,
                                          key_buffer_length);
        }
    }

    err3 = mcux_free_raw_rsa(&rsa_key);
    err4 = mcux_rsa_free_primes(&primes);
    if (err2 != PSA_SUCCESS) {
        return err2;
    }
    if (err3 != PSA_SUCCESS) {
        return err3;
    }
    if (err4 != PSA_SUCCESS) {
        return err4;
    }

    return err;
}
#endif

static inline psa_status_t caam_fifost_key_type(mcux_psa_caam_key_type_t caam_key_type,
                                                caam_fifost_type_t *fifost_key_type)
{
    switch (caam_key_type) {
        case MCUX_PSA_CAAM_KEY_TYPE_ECB:
        {
            *fifost_key_type = kCAAM_FIFOST_Type_Ecb_Jkek;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_CCM:
        {
            *fifost_key_type = kCAAM_FIFOST_Type_Ccm_Jkek;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}

#if defined(PSA_WANT_KEY_TYPE_AES)
static psa_status_t caam_internal_aes_generate_key_transparent(
    const psa_key_attributes_t *attributes,
    uint8_t *key_buffer,
    size_t key_buffer_size,
    size_t *key_buffer_length)
{
    psa_status_t err          = PSA_SUCCESS;
    psa_status_t err2         = PSA_SUCCESS;
    status_t caam_status      = kStatus_Fail;
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = PSA_BITS_TO_BYTES(key_bits);
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };

    if (key_bytes < key_buffer_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        err  = PSA_ERROR_SERVICE_FAILURE;
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        caam_status = CAAM_RNG_GetRandomData(PSA_CAAM,
                                             &caam_handle,
                                             kCAAM_RngStateHandle0,
                                             key_buffer,
                                             key_bytes,
                                             kCAAM_RngDataAny,
                                             NULL);
        err         = caam_to_psa_status(caam_status);
    }

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }
    if (err2 != PSA_SUCCESS) {
        return err2;
    }

    if (err == PSA_SUCCESS) {
        *key_buffer_length = key_buffer_size;
    }

    return err;
}

static psa_status_t caam_internal_aes_generate_key_blacken(mcux_psa_caam_key_type_t caam_key_type,
                                                           const psa_key_attributes_t *attributes,
                                                           uint8_t *key_buffer,
                                                           size_t key_buffer_size,
                                                           size_t *key_buffer_length)
{
    psa_status_t err          = PSA_SUCCESS;
    psa_status_t err2         = PSA_SUCCESS;
    status_t caam_status      = kStatus_Fail;
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = CAAM_OPAQUE_ALIGN(PSA_BITS_TO_BYTES(key_bits));
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    caam_fifost_type_t fifost_key_type;
    size_t transparent_key_size = 0u;
#if defined(USE_MALLOC)
    uint8_t *blacken_key = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (blacken_key == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#else
    uint8_t blacken_key[CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE)];
    if (CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE) < key_bytes) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    /* Guard against unsigned wrap before computing CAAM_ENCAP_DATA_SIZE */
    if (mcux_psa_add_size_t_wrapcheck(key_bytes, 64U)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }

    if (CAAM_ENCAP_DATA_SIZE(key_bytes) > key_buffer_size) {
        err = PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (err == PSA_SUCCESS) {
        if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
            err = PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    if (err == PSA_SUCCESS) {
        err = caam_fifost_key_type(caam_key_type, &fifost_key_type);
    }

    if (err == PSA_SUCCESS) {
        err =
            caam_internal_aes_generate_key_transparent(attributes,
                                                       key_buffer,
                                                       PSA_BITS_TO_BYTES(key_bits),
                                                       &transparent_key_size);
    }

    if (err == PSA_SUCCESS) {
        if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
            err  = PSA_ERROR_SERVICE_FAILURE;
            err2 = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    if (err == PSA_SUCCESS) {
        caam_status = CAAM_BLACK_GetKeyBlacken(PSA_CAAM,
                                               &caam_handle,
                                               key_buffer,
                                               transparent_key_size,
                                               fifost_key_type,
                                               blacken_key);
        err         = caam_to_psa_status(caam_status);
    }

    if (err == PSA_SUCCESS) {
        err = caam_opaque_encapsulate_key(caam_key_type,
                                          blacken_key,
                                          transparent_key_size,
                                          key_buffer,
                                          key_buffer_size,
                                          key_buffer_length);
    }

#if defined(USE_MALLOC)
    if (blacken_key != NULL) {
        mbedtls_free(blacken_key);
    }
#else
    memset(blacken_key, 0, sizeof(blacken_key));
#endif

    if ((err2 == PSA_SUCCESS) && (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }
    if (err2 != PSA_SUCCESS) {
        return err2;
    }

    return err;
}
#endif /* PSA_WANT_KEY_TYPE_AES */

psa_status_t caam_common_generate_key(mcux_psa_caam_key_type_t caam_key_type,
                                      const psa_key_attributes_t *attributes,
                                      uint8_t *key_buffer,
                                      size_t key_buffer_size,
                                      size_t *key_buffer_length)
{
    psa_status_t err         = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type  = psa_get_key_type(attributes);
    psa_algorithm_t key_algo = psa_get_key_algorithm(attributes);

    *key_buffer_length = 0;

    /* These checks are mainly to check WANT_KEY_TYPE */
    if (PSA_KEY_TYPE_IS_KEY_PAIR(key_type)) {
#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE)
        if (PSA_KEY_TYPE_IS_ECC(key_type) && PSA_ALG_IS_RANDOMIZED_ECDSA(key_algo)) {
            err = caam_internal_ecc_generate_key(caam_key_type,
                                                 attributes,
                                                 key_buffer,
                                                 key_buffer_size,
                                                 key_buffer_length);
        } else
#endif /* PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE */
#if defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE)
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER < 0x04000000)
        if (PSA_KEY_TYPE_IS_RSA(key_type)) {
            err = caam_internal_rsa_generate_key(caam_key_type,
                                                 attributes,
                                                 key_buffer,
                                                 key_buffer_size,
                                                 key_buffer_length);
        } else
#endif /* MBEDTLS_VERSION_NUMBER < 0x04000000 */
#endif /* PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE */
        {
        }
    } else if (PSA_KEY_TYPE_IS_UNSTRUCTURED(key_type)) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        if (key_type == PSA_KEY_TYPE_AES) {
            if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
                err = caam_internal_aes_generate_key_transparent(attributes,
                                                                 key_buffer,
                                                                 key_buffer_size,
                                                                 key_buffer_length);
            } else {
                err = caam_internal_aes_generate_key_blacken(caam_key_type,
                                                             attributes,
                                                             key_buffer,
                                                             key_buffer_size,
                                                             key_buffer_length);
            }
        } else if (key_type == PSA_KEY_TYPE_HMAC) {
            if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
                err = caam_internal_aes_generate_key_transparent(attributes,
                                                                 key_buffer,
                                                                 key_buffer_size,
                                                                 key_buffer_length);
            } else {
                err = caam_internal_aes_generate_key_blacken(caam_key_type,
                                                             attributes,
                                                             key_buffer,
                                                             key_buffer_size,
                                                             key_buffer_length);
            }
        } else
#endif /*  PSA_WANT_KEY_TYPE_AES */
        {
        }
    }

    (void)key_algo;
    (void)key_type;

    return err;
}

psa_status_t caam_common_destroy_key(const psa_key_attributes_t *attributes,
                                     uint8_t *key_buffer,
                                     size_t key_buffer_size)
{
    return PSA_SUCCESS;
}

psa_status_t caam_common_export_public_key(const psa_key_attributes_t *attributes,
                                           const uint8_t *key_buffer,
                                           size_t key_buffer_size,
                                           uint8_t *data,
                                           size_t data_size,
                                           size_t *data_length)
{
    psa_status_t err        = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);
#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE)
    mbedtls_ecp_group_id ecp_grou_id;
    caam_ecc_ecdsel_t ecc_ecdsel;
#endif /* PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE */
#if defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE)
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER < 0x04000000)
    size_t key_bytes = PSA_BITS_TO_BYTES(key_bits);
    struct mcux_rsa_keypair rsa_key;
#endif
#endif /* PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE */

#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE)
    if (PSA_KEY_TYPE_IS_ECC(key_type)) {
        err = psa_to_caam_ecc_key_algo(key_type, key_bits, &ecc_ecdsel, &ecp_grou_id);
        if (err == PSA_SUCCESS) {
            *data_length = CAAM_ECC_PUBLIC_KEY_LENGTH(ecc_ecdsel) + 1u;
            if (data_size < *data_length) {
                err = PSA_ERROR_BUFFER_TOO_SMALL;
            } else {
                (void) memcpy(data, key_buffer, *data_length);
            }
        }
    } else
#endif /* PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE */
#if defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE)
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER < 0x04000000)
    if (PSA_KEY_TYPE_IS_RSA(key_type)) {
        rsa_key.modulus     = (uint8_t *) key_buffer;
        rsa_key.modulus_len = key_bytes;
        err                 = mcux_raw_rsa_to_key_buf(key_type,
                                                      true,
                                                      &rsa_key,
                                                      data,
                                                      data_size,
                                                      data_length);
    } else
#endif /* MBEDTLS_VERSION_NUMBER < 0x04000000 */
#endif /* PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE */
    {
    }
    if (err != PSA_SUCCESS)
    {
        *data_length = 0;
    }

    (void)key_type;
    (void)key_bits;
    return err;
}

size_t caam_common_size_function(psa_key_type_t key_type, size_t key_bits)
{
    size_t ret = 0;
    size_t key_bytes;
    if (mcux_psa_add_size_t_wrapcheck(key_bits, 7U)) {
        return 0u;
    }
    key_bytes = PSA_BITS_TO_BYTES(key_bits);
    if (mcux_psa_add_size_t_wrapcheck(key_bytes, 64U + 19U)) {
        return 0u;
    }
#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE)
    mbedtls_ecp_group_id ecp_grou_id;
    caam_ecc_ecdsel_t ecc_ecdsel;
    status_t err;
#endif /* PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE */

    if (PSA_KEY_TYPE_IS_KEY_PAIR(key_type)) {
        size_t public_size, private_size;
#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE)
        if (PSA_KEY_TYPE_IS_ECC(key_type)) {
            err = psa_to_caam_ecc_key_algo(key_type, key_bits, &ecc_ecdsel, &ecp_grou_id);
            if (err == PSA_SUCCESS) {
                public_size  = CAAM_ECC_PUBLIC_KEY_LENGTH(ecc_ecdsel);
                private_size = CAAM_ENCAP_DATA_SIZE(ECC_ALIGN_PRIVATE_KEY_SIZE(key_bytes));
                if (mcux_psa_add_size_t_wrapcheck(public_size + 1U, private_size)) {
                    return 0u;
                }
                ret = public_size + 1U + private_size;
            }
        } else
#endif /* PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE */
#if defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE)
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER < 0x04000000)
        if (PSA_KEY_TYPE_IS_RSA(key_type)) {
            ret = key_bytes + CAAM_ENCAP_DATA_SIZE(RSA_ALIGN_PRIVATE_EXPONENT_SIZE(key_bytes))+
                  sizeof(size_t);
        } else
#endif /* MBEDTLS_VERSION_NUMBER < 0x04000000 */
#endif /* PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE */
        {
        }
    } else if (PSA_KEY_TYPE_IS_UNSTRUCTURED(key_type)) {
#if defined(PSA_WANT_KEY_TYPE_AES) || defined(PSA_WANT_KEY_TYPE_HMAC)
        ret = CAAM_ENCAP_DATA_SIZE(CAAM_OPAQUE_ALIGN(key_bytes));
#endif /*  PSA_WANT_KEY_TYPE_AES */
    }

    (void)key_bytes;

    return ret;
}
