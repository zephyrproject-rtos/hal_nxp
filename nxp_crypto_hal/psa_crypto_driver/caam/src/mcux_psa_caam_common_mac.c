/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_common_mac.c
 *
 * This file contains the implementation of the entry points associated to the
 * mac capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_caam_common_mac.h"
#include "mcux_psa_common_key_management.h"

#include "mcux_psa_caam_init.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"

psa_status_t psa_to_caam_mac_alg(psa_algorithm_t alg,
                                 psa_key_type_t key_type,
                                 caam_hash_algo_t *caam_alg)
{
    psa_status_t status = PSA_ERROR_NOT_SUPPORTED;

#if defined(PSA_WANT_ALG_CMAC)
    if (PSA_ALG_FULL_LENGTH_MAC(alg) == PSA_ALG_CMAC) {
        if (key_type == PSA_KEY_TYPE_AES) {
            *caam_alg = kCAAM_Cmac;
            status    = PSA_SUCCESS;
        }
    } else
#endif /* PSA_WANT_ALG_CMAC */
#if defined(PSA_WANT_ALG_HMAC)
    if (PSA_ALG_IS_HMAC(alg)) {
        if (key_type == PSA_KEY_TYPE_HMAC) {
            switch (PSA_ALG_HMAC_GET_HASH(alg)) {
                case PSA_ALG_SHA_1:
                {
                    *caam_alg = kCAAM_HmacSha1;
                    break;
                }
                case PSA_ALG_SHA_224:
                {
                    *caam_alg = kCAAM_HmacSha224;
                    break;
                }
                case PSA_ALG_SHA_256:
                {
                    *caam_alg = kCAAM_HmacSha256;
                    break;
                }
                case PSA_ALG_SHA_384:
                {
                    *caam_alg = kCAAM_HmacSha384;
                    break;
                }
                case PSA_ALG_SHA_512:
                {
                    *caam_alg = kCAAM_HmacSha512;
                    break;
                }
                default:
                {
                    return PSA_ERROR_NOT_SUPPORTED;
                }
            }
            status = PSA_SUCCESS;
        }
    } else
#endif /* PSA_WANT_ALG_HMAC */
    {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

psa_status_t caam_common_mac_compute(const psa_key_attributes_t *attributes,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     psa_algorithm_t alg,
                                     const uint8_t *input,
                                     size_t input_length,
                                     uint8_t *mac,
                                     size_t mac_size,
                                     size_t *mac_length)
{
    psa_status_t status     = PSA_ERROR_CORRUPTION_DETECTED;
    status_t caam_status    = kStatus_Fail;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    caam_hash_algo_t caam_alg;
    caam_hash_ctx_t ctx;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };

    /* Chec input*/
    if ((input == NULL) || (input_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check MAC buffer */
    if ((mac == NULL) || (mac_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check key type and get ele algorithm */
    status = psa_to_caam_mac_alg(alg, key_type, &caam_alg);
    if (status != PSA_SUCCESS) {
        return status;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    caam_status =
        CAAM_HMAC_Init(PSA_CAAM, &caam_handle, &ctx, caam_alg, key_buffer, key_buffer_size);
    if (caam_status == kStatus_Success) {
        caam_status = CAAM_HMAC(PSA_CAAM,
                                &caam_handle,
                                caam_alg,
                                input,
                                input_length,
                                key_buffer,
                                key_buffer_size,
                                mac,
                                mac_length);
    }
    status = caam_to_psa_status(caam_status);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

/** @} */ // end of psa_mac
