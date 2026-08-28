/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_key_generation.c
 *
 * This file contains the implementation of the entry points associated to the
 * key generation capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_s2xx_init.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_s2xx_key_generation.h"

psa_status_t ele_s2xx_transparent_generate_key(const psa_key_attributes_t *attributes,
                                               uint8_t *key_buffer, size_t key_buffer_size,
                                               size_t *key_buffer_length)
{
    psa_status_t status           = PSA_SUCCESS;
    psa_key_type_t type           = psa_get_key_type(attributes);
    size_t bits                   = psa_get_key_bits(attributes);
    sss_sscp_object_t sssKey      = {0u};
    sss_cipher_type_t cipher_type = {0u};
    size_t allocation_size        = 0u;

    /* NOTE: Transparent drivers are limited to generating asymmetric keys,
     * as per PSA spec. This wrapper will never be called by PSA wrapper
     * dispatch for symmetric keys.
     */

    /* We can't allow public key generation */
    if (true == PSA_KEY_TYPE_IS_PUBLIC_KEY(type))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (false == PSA_KEY_TYPE_IS_ECC(type))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    status = translate_psa_ecc_family_to_ele_cipher_type(attributes,
                                                         &cipher_type);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if ((sss_sscp_key_object_init(&sssKey, &g_ele_ctx.keyStore)) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    /* Key pair size + a bit more to be safe in case of some 521bit keys */
    allocation_size = (key_buffer_size * 3u) + 6u;

    if ((sss_sscp_key_object_allocate_handle(&sssKey, 0u, /* key id */
                                             kSSS_KeyPart_Pair, cipher_type, allocation_size,
                                             kSSS_KeyProp_CryptoAlgo_AsymSignVerify)) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    /* This is the transparent driver (i.e. for PSA_KEY_LOCATION_LOCAL_STORAGE),
     * so we just generate the key, grab the private part, and delete the entire
     * key from S200.
     */
    if (sss_sscp_key_store_generate_key(&g_ele_ctx.keyStore, &sssKey, bits, NULL) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    *key_buffer_length = key_buffer_size;
    if ((sss_sscp_key_store_get_key(&g_ele_ctx.keyStore, &sssKey, key_buffer, key_buffer_length,
                                    &bits, kSSS_KeyPart_Private)) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
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

psa_status_t ele_s2xx_transparent_export_public_key(const psa_key_attributes_t *attributes,
                                                    const uint8_t *key_buffer,
                                                    size_t key_buffer_size,
                                                    uint8_t *data,
                                                    size_t data_size,
                                                    size_t *data_length)
{
#if defined(ELE200_EXTENDED_FEATURES)
    psa_status_t status           = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t type           = psa_get_key_type(attributes);
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA macro result cast to wider essential type as needed */
    psa_ecc_family_t family       = PSA_KEY_TYPE_ECC_GET_FAMILY(type);
    size_t bits                   = psa_get_key_bits(attributes);
    sss_cipher_type_t cipher_type = {0};
    sss_sscp_object_t sssKey      = {0};

    /* We can't accelerate if the key is not an ECC keypair */
    if (false == PSA_KEY_TYPE_IS_KEY_PAIR(type) ||
        false == PSA_KEY_TYPE_IS_ECC(type))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* We can accelerate the export of Brainpool-R1 and SECP-R1 public keys */
    if (PSA_ECC_FAMILY_SECP_R1 != family &&
        PSA_ECC_FAMILY_BRAINPOOL_P_R1 != family)
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    status = translate_psa_ecc_family_to_ele_cipher_type(attributes, &cipher_type);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Make sure PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(bits) does not wrap */
    if (bits > 521u)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(bits) > data_size)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* If no FW is loaded, then we have no accelerated S200 API to leverage */
    if (is_fw_loaded() != PSA_SUCCESS)
    {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }

    status = ele_s2xx_set_key(&sssKey, 0u, key_buffer, key_buffer_size,
                              kSSS_KeyPart_Private, cipher_type,
                              (sss_sscp_key_property_t)0, key_buffer_size, bits);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* PSA expects ECC public keys to be in uncompressed format,
     * so we shift the data buffer and its size by 1 and manually
     * add the leading 0x04 byte on success.
     */
    status = ele_s2xx_get_ecc_public_key_from_private(&sssKey, (data + 1),
                                                      (data_size - 1u),
                                                      data_length, NULL);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }
    data[0]      = 0x04u;
    *data_length += 1u;

exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
#else
    /* Accelerated public key export not available on KW45 (and siblings) */
    (void)attributes;
    (void)key_buffer;
    (void)key_buffer_size;
    (void)data;
    (void)data_size;
    (void)data_length;
    return PSA_ERROR_NOT_SUPPORTED;
#endif /* ELE200_EXTENDED_FEATURES */
}

psa_status_t ele_s2xx_transparent_key_agreement(const psa_key_attributes_t *attributes,
                                                const uint8_t *key_buffer,
                                                size_t key_buffer_size,
                                                psa_algorithm_t alg,
                                                const uint8_t *peer_key,
                                                size_t peer_key_length,
                                                uint8_t *shared_secret,
                                                size_t shared_secret_size,
                                                size_t *shared_secret_length)
{
    psa_status_t status             = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t type             = psa_get_key_type(attributes);
    size_t bits                     = psa_get_key_bits(attributes);
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA macro result cast to wider essential type as needed */
    psa_ecc_family_t family         = PSA_KEY_TYPE_ECC_GET_FAMILY(type);
    sss_sscp_object_t sssKey        = {0u};
    sss_sscp_object_t sssKey_peer   = {0u};
    sss_sscp_object_t sssKey_shared = {0u};
    sss_algorithm_t ele_alg         = {0u};
    sss_cipher_type_t cipher_type   = {0u};
    sss_sscp_key_property_t props   = {0u};

    if (false == PSA_KEY_TYPE_IS_ECC_KEY_PAIR(type) ||
        false == PSA_ALG_IS_ECDH(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Do our best to preemptively check whether the peer key is valid for
     * the given private key. If we don't catch it here, the S200 key agreement
     * call will correctly fail, but in that case we may return a different
     * error code.
     */
    if (PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(bits) != peer_key_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* We support X25519, SECP, or Brainpool ECDH */
    if (PSA_ECC_FAMILY_MONTGOMERY == family)
    {
        if (255u != bits)
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
        ele_alg     = kAlgorithm_MONTDH;
        cipher_type = kSSS_CipherType_EC_MONTGOMERY;
    }
    else if (PSA_ECC_FAMILY_SECP_R1 == family)
    {
        if ((224u != bits) && (256u != bits) &&
            (384u != bits) && (521u != bits))
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
        ele_alg     = kAlgorithm_SSS_ECDH;
        cipher_type = kSSS_CipherType_EC_NIST_P;
    }
#if defined(ELE200_EXTENDED_FEATURES)
    else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == family)
    {
        if ((192u != bits) && (224u != bits) && (256u != bits) &&
            (320u != bits) && (384u != bits) && (512u != bits))
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
        ele_alg     = kAlgorithm_SSS_ECDH;
        cipher_type = kSSS_CipherType_EC_BRAINPOOL_R1;
    }
#endif /* ELE200_EXTENDED_FEATURES */
    else
    {
        (void)attributes;
        (void)key_buffer;
        (void)key_buffer_size;
        (void)alg;
        (void)peer_key;
        (void)peer_key_length;
        (void)shared_secret;
        (void)shared_secret_size;
        (void)shared_secret_length;
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize the shared secret key object */
    if (sss_sscp_key_object_init(&sssKey_shared, &g_ele_ctx.keyStore) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    props = kSSS_KeyProp_NoImportExport | kSSS_KeyProp_NoPlainWrite |
            kSSS_KeyProp_NoVerify       | kSSS_KeyProp_NoSign;
    if (sss_sscp_key_object_allocate_handle(&sssKey_shared, 0u,
                                            kSSS_KeyPart_Default, kSSS_CipherType_SYMMETRIC,
                                            PSA_BITS_TO_BYTES(bits),
                                            props) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    /* Load our private key(pair). We will only load the private part,
     * as the public part is not needed for ECDH. This way we do not need to
     * do a public key export operation beforehand.
     */
    status = ele_s2xx_set_key(&sssKey, 0u, key_buffer, key_buffer_size, kSSS_KeyPart_Private,
                              cipher_type, kSSS_KeyProp_CryptoAlgo_KDF,
                              key_buffer_size, bits);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* Load the peer key - peer key buffer and size shifted by 1 element,
     * since S200 expects no leading 0x04 Byte.
     */
    status = ele_s2xx_set_key(&sssKey_peer, 0u, (peer_key + 1), (peer_key_length - 1u), kSSS_KeyPart_Public,
                              cipher_type, kSSS_KeyProp_CryptoAlgo_KDF,
                              PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(bits),
                              bits);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* Do the key agreement, get the shared secret and set the output size */
    status = ele_s2xx_common_key_agreement(&sssKey, &sssKey_peer, &sssKey_shared,
                                           shared_secret, shared_secret_size, shared_secret_length,
                                           ele_alg);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

exit:
    (void)ele_s2xx_delete_key(&sssKey_peer);
    (void)ele_s2xx_delete_key(&sssKey_shared);
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
