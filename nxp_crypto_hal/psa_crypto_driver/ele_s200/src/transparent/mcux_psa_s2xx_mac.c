/*
 * Copyright 2024-2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_mac.c
 *
 * This file contains the implementation of the entry points associated to the
 * mac capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_s2xx_mac.h"
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_s2xx_common_key_management.h"

/*
 * Entry points for MAC computation and verification as described by the PSA
 *  Cryptoprocessor Driver interface specification
 */

/* Convert PSA Algorithm to ELE Algorithm, CMAC or HMAC */
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

/** \defgroup psa_mac PSA transparent key driver entry points for MAC
 *
 *  Entry points for MAC generation and verification as described by the PSA
 *  Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t ele_s2xx_transparent_mac_compute(const psa_key_attributes_t *attributes,
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
    sss_algorithm_t ele_alg  = 0u;
    sss_sscp_object_t sssKey = {0};
    size_t key_bits          = psa_get_key_bits(attributes);
    psa_key_type_t key_type  = psa_get_key_type(attributes);

    /* Get Algo for ELE */
    status = translate_psa_mac_to_ele_mac(alg, &ele_alg);
    if (status != PSA_SUCCESS)
    {
        return status;
    }

    /* coverity[misra_c_2012_rule_10_1_violation]: PSA macro performs bitwise ops on unsigned type as required */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    mac_size = PSA_MAC_LENGTH(key_type, key_bits, alg);

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }


    status = ele_s2xx_set_key(&sssKey, 0u, /* key id */
                              key_buffer, key_buffer_size, kSSS_KeyPart_Default,
                              kSSS_CipherType_MAC, kSSS_KeyProp_CryptoAlgo_MAC,
                              key_buffer_size, key_bits);
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

#if defined(ELE_FEATURE_MAC_MULTIPART)
static psa_status_t mac_common_setup(ele_s2xx_transparent_mac_operation_t *operation,
                                     const psa_key_attributes_t *attributes,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     psa_algorithm_t alg)
{
    psa_status_t status    = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_mac_t mac_ctx = {0};
    size_t key_size_bits   = psa_get_key_bits(attributes);
    size_t blob_size       = ELE_S2XX_MULTIPART_MAC_BLOB_SIZE;

    /* Workaround : we need 1 Byte allocated for 0-bit HMAC key support */
    size_t key_handle_alloc_size = (0u != key_size_bits)
                                        ? PSA_BITS_TO_BYTES(key_size_bits)
                                        : 1u;

    if (false == PSA_ALG_IS_MAC(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = translate_psa_mac_to_ele_mac(alg, &operation->algorithm);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* This key object is to be freed during mac_*_finish() or mac_abort() */
    if (sss_sscp_key_object_init(&operation->key_object,
                                 &g_ele_ctx.keyStore) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_key_object_allocate_handle(&operation->key_object,
                                            0u, /* Let S200 choose key ID */
                                            kSSS_KeyPart_Default,
                                            kSSS_CipherType_MAC,
                                            key_handle_alloc_size,
                                            kSSS_KeyProp_CryptoAlgo_MAC) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    /* For S200 0-keysize HMAC support, we need to allocate a dummy
     * handle (step above), and NOT set a key.
     */
    if (0u != key_size_bits)
    {
        if (sss_sscp_key_store_set_key(&g_ele_ctx.keyStore,
                                       &operation->key_object,
                                       key_buffer,
                                       key_buffer_size,
                                       key_size_bits,
                                       kSSS_KeyPart_Default) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
    }

    if (sss_sscp_mac_context_init(&mac_ctx,
                                  &g_ele_ctx.sssSession,
                                  &operation->key_object,
                                  operation->algorithm,
                                  kMode_SSS_Mac) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_init(&mac_ctx) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_export(&mac_ctx,
                            operation->context_blob,
                            &blob_size) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

exit:
    /* Clean the temporary MAC context, but not the key object, even on failure.
     * PSA calls mac_abort() on failure, so deferring the key object
     * cleanup to the mac_abort() call.
     */
    (void)sss_sscp_mac_context_free(&mac_ctx);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_transparent_mac_sign_setup(ele_s2xx_transparent_mac_operation_t *operation,
                                                 const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg)
{
    /* On S200 MAC sign and verify setup is identical */
    return mac_common_setup(operation,
                            attributes,
                            key_buffer,
                            key_buffer_size,
                            alg);
}

psa_status_t ele_s2xx_transparent_mac_verify_setup(ele_s2xx_transparent_mac_operation_t *operation,
                                                   const psa_key_attributes_t *attributes,
                                                   const uint8_t *key_buffer,
                                                   size_t key_buffer_size,
                                                   psa_algorithm_t alg)
{
    /* On S200 MAC sign and verify setup is identical */
    return mac_common_setup(operation,
                            attributes,
                            key_buffer,
                            key_buffer_size,
                            alg);
}

psa_status_t ele_s2xx_transparent_mac_update(ele_s2xx_transparent_mac_operation_t *operation,
                                             const uint8_t *input,
                                             size_t input_length)
{
    psa_status_t status    = PSA_SUCCESS;
    sss_sscp_mac_t mac_ctx = {0};
    size_t blob_size       = ELE_S2XX_MULTIPART_MAC_BLOB_SIZE;

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (sss_sscp_mac_context_init(&mac_ctx,
                                  &g_ele_ctx.sssSession,
                                  &operation->key_object,
                                  operation->algorithm,
                                  kMode_SSS_Mac) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_import(&mac_ctx,
                            operation->context_blob,
                            blob_size) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_update(&mac_ctx,
                            input,
                            input_length) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_export(&mac_ctx,
                            operation->context_blob,
                            &blob_size) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

exit:
    /* Clean the temporary MAC context, but not the key object, even on failure.
     * PSA calls mac_abort() on failure, so deferring the key object
     * cleanup to the mac_abort() call.
     */
    (void)sss_sscp_mac_context_free(&mac_ctx);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_transparent_mac_sign_finish(ele_s2xx_transparent_mac_operation_t *operation,
                                                  uint8_t *mac,
                                                  size_t mac_size,
                                                  size_t *mac_length)
{
    psa_status_t status        = PSA_SUCCESS;
    sss_sscp_mac_t mac_ctx     = {0};
    size_t mac_length_internal = mac_size;

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (sss_sscp_mac_context_init(&mac_ctx,
                                  &g_ele_ctx.sssSession,
                                  &operation->key_object,
                                  operation->algorithm,
                                  kMode_SSS_Mac) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_import(&mac_ctx,
                            operation->context_blob,
                            ELE_S2XX_MULTIPART_MAC_BLOB_SIZE) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_finish(&mac_ctx,
                            mac,
                            &mac_length_internal) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_context_free(&mac_ctx) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

exit:
    /* Clean the temporary MAC context, but not the key object, even on failure.
     * PSA calls mac_abort() on failure, so deferring the key object
     * cleanup to the mac_abort() call.
     */
    (void)sss_sscp_mac_context_free(&mac_ctx);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (PSA_SUCCESS == status)
    {
        *mac_length = mac_length_internal;
    }

    return status;
}

psa_status_t ele_s2xx_transparent_mac_verify_finish(ele_s2xx_transparent_mac_operation_t *operation,
                                                    const uint8_t *mac,
                                                    size_t mac_length)
{
    psa_status_t status                    = PSA_SUCCESS;
    sss_sscp_mac_t mac_ctx                 = {0};
    uint8_t mac_finished[PSA_MAC_MAX_SIZE] = {0u};
    size_t mac_length_internal             = sizeof(mac_finished);

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (sss_sscp_mac_context_init(&mac_ctx,
                                  &g_ele_ctx.sssSession,
                                  &operation->key_object,
                                  operation->algorithm,
                                  kMode_SSS_Mac) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_import(&mac_ctx,
                            operation->context_blob,
                            ELE_S2XX_MULTIPART_MAC_BLOB_SIZE) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_mac_finish(&mac_ctx,
                            mac_finished,
                            &mac_length_internal) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

exit:
    /* Clean the temporary MAC context, but not the key object, even on failure.
     * PSA calls mac_abort() on failure, so deferring the key object
     * cleanup to the mac_abort() call.
     */
    (void)sss_sscp_mac_context_free(&mac_ctx);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Verify the MAC */
    if (PSA_SUCCESS == status)
    {
        if (ele_s2xx_util_ct_memcmp(mac, mac_finished, mac_length) != 0)
        {
            status = PSA_ERROR_INVALID_SIGNATURE;
        }
    }

    return status;
}

psa_status_t ele_s2xx_transparent_mac_abort(ele_s2xx_transparent_mac_operation_t *operation)
{
    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* We have no S200 error code granularity, so we go by best effort and
     * assume success when cleaning up the S200 key object. Failure here would
     * mean that no such key can be free'd in S200, so
     *  - the key object is already free'd,
     *  - the key object has never been created (failure during key creation),
     *  - operation->key_object attribute has been corrupted.
     */
    (void)ele_s2xx_delete_key(&operation->key_object);

    /* Clean up the SW-side context */
    (void)memset(operation, 0, sizeof(ele_s2xx_transparent_mac_operation_t));

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return PSA_SUCCESS;
}
#else /* ELE_FEATURE_MAC_MULTIPART */
psa_status_t ele_s2xx_transparent_mac_sign_setup(ele_s2xx_transparent_mac_operation_t *operation,
                                                 const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg)
{
    (void)operation;
    (void)attributes;
    (void)key_buffer;
    (void)key_buffer_size;
    (void)alg;
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t ele_s2xx_transparent_mac_verify_setup(ele_s2xx_transparent_mac_operation_t *operation,
                                                   const psa_key_attributes_t *attributes,
                                                   const uint8_t *key_buffer,
                                                   size_t key_buffer_size,
                                                   psa_algorithm_t alg)
{
    (void)operation;
    (void)attributes;
    (void)key_buffer;
    (void)key_buffer_size;
    (void)alg;
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t ele_s2xx_transparent_mac_update(ele_s2xx_transparent_mac_operation_t *operation,
                                             const uint8_t *input,
                                             size_t input_length)
{
    (void)operation;
    (void)input;
    (void)input_length;
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t ele_s2xx_transparent_mac_sign_finish(ele_s2xx_transparent_mac_operation_t *operation,
                                                  uint8_t *mac,
                                                  size_t mac_size,
                                                  size_t *mac_length)
{
    (void)operation;
    (void)mac;
    (void)mac_size;
    (void)mac_length;
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t ele_s2xx_transparent_mac_verify_finish(ele_s2xx_transparent_mac_operation_t *operation,
                                                    const uint8_t *mac,
                                                    size_t mac_length)
{
    (void)operation;
    (void)mac;
    (void)mac_length;
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t ele_s2xx_transparent_mac_abort(ele_s2xx_transparent_mac_operation_t *operation)
{
    (void)operation;
    return PSA_ERROR_NOT_SUPPORTED;
}
#endif /* ELE_FEATURE_MAC_MULTIPART */

/** @} */ // end of psa_mac
