/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_psa_opaque_mac.c
 *
 * This file contains the definition of the entry points associated to the
 * mac capability (single-part only, multi-part (not supported in ele)) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_s2xx_common_init.h"
#include "mcux_psa_s2xx_opaque_mac.h"
#include "mcux_psa_s2xx_key_locations.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_s2xx_common_compute.h"

/* Convert PSA Algorithm to ELE Algorithm, CMAC or HMAC with SHA256 */
static psa_status_t translate_psa_mac_to_ele_mac(psa_algorithm_t alg, sss_algorithm_t *ele_alg)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (PSA_MAC_TRUNCATED_LENGTH(alg) != 0u)
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

#if defined(PSA_WANT_ALG_CMAC)
    if (PSA_ALG_FULL_LENGTH_MAC(alg) == PSA_ALG_CMAC)
    {
        *ele_alg = kAlgorithm_SSS_CMAC_AES;
        status   = PSA_SUCCESS;
    }
    else
#endif /* PSA_WANT_ALG_CMAC */
#if defined(PSA_WANT_ALG_HMAC)
        if (true == PSA_ALG_IS_HMAC(alg))
    {
        status = PSA_SUCCESS;
        switch (PSA_ALG_HMAC_GET_HASH(alg))
        {
#if defined(PSA_WANT_ALG_SHA_256)
            case PSA_ALG_SHA_256:
                *ele_alg = kAlgorithm_SSS_HMAC_SHA256;
                break;
#endif /* PSA_WANT_ALG_SHA_256 */
#if defined(ELE_FEATURE_EXTENDED_HMAC)
#if defined(PSA_WANT_ALG_SHA_1)
            case PSA_ALG_SHA_1:
                *ele_alg = kAlgorithm_SSS_HMAC_SHA1;
                break;
#endif /* PSA_WANT_ALG_SHA_1 */
#if defined(PSA_WANT_ALG_SHA_224)
            case PSA_ALG_SHA_224:
                *ele_alg = kAlgorithm_SSS_HMAC_SHA224;
                break;
#endif /* PSA_WANT_ALG_SHA_224 */
#if defined(PSA_WANT_ALG_SHA_384)
            case PSA_ALG_SHA_384:
                *ele_alg = kAlgorithm_SSS_HMAC_SHA384;
                break;
#endif /* PSA_WANT_ALG_SHA_384 */
#if defined(PSA_WANT_ALG_SHA_512)
            case PSA_ALG_SHA_512:
                *ele_alg = kAlgorithm_SSS_HMAC_SHA512;
                break;
#endif /* PSA_WANT_ALG_SHA_512 */
#endif /* ELE_FEATURE_EXTENDED_HMAC */
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    }
    else
#endif /* PSA_WANT_ALG_HMAC */
    {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

/** \defgroup psa_mac_opaque PSA opaque key driver entry points for MAC
 *
 *  Entry points for MAC generation and verification as described by the PSA
 *  Cryptoprocessor Driver interface specification with the use of opaque keys
 *
 *  @{
 */
psa_status_t ele_s2xx_opaque_mac_compute(const psa_key_attributes_t *attributes,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         psa_algorithm_t alg,
                                         const uint8_t *input,
                                         size_t input_length,
                                         uint8_t *mac,
                                         size_t mac_size,
                                         size_t *mac_length)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    sss_algorithm_t ele_alg  = 0;
    sss_sscp_object_t sssKey = {0};

    /* Get Algo for ELE */
    status = translate_psa_mac_to_ele_mac(alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Validations */
    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == mac_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* coverity[misra_c_2012_rule_10_1_violation] */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA_MAC_LENGTH macro contains shift/type issues */
    mac_size = PSA_MAC_LENGTH(psa_get_key_type(attributes), psa_get_key_bits(attributes), alg);

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    status = ele_s2xx_common_mac(input, input_length, mac, mac_size, mac_length, &sssKey, ele_alg);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

/** @} */ // end of psa_mac_opaque
