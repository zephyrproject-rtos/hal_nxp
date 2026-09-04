/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_asymmetric_signature.c
 *
 * This file contains the implementation of the entry points associated to the
 * asymmetric signature capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#include "mcux_psa_s2xx_init.h"
#include "mcux_psa_s2xx_asymmetric_signature.h"
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

/* For exporting public keys, we will directly use the internal export wrapper,
 * so that we don't call the public psa_export_public_key() API.
 */
/* coverity[misra_c_2012_rule_8_5_violation]: external declaration required to access internal PSA function */
extern psa_status_t psa_export_public_key_internal(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    uint8_t *data,
    size_t data_size,
    size_t *data_length);

/* Public key is double length of private key + 1byte for leading byte (0x04) which is indicating uncompressed format.
 * Support for 521 means we might need two additional bytes per ECC coordinate, hence 132 Bytes in total. */
#define MAX_PUB_KEY_SIZE_IN_BYTES  (132u + 1u)
#define MAX_PAIR_KEY_SIZE_IN_BYTES (MAX_PUB_KEY_SIZE_IN_BYTES + 66u)

#define NISTP521_BITLEN (521u)

static psa_status_t translate_psa_asym_to_ele_asym(const psa_key_attributes_t *attributes,
                                                   psa_algorithm_t alg,
                                                   sss_algorithm_t *ele_alg)
{
    psa_status_t status           = PSA_SUCCESS;
    psa_algorithm_t sign_hash_alg = PSA_ALG_ANY_HASH;

    if (PSA_ALG_PURE_EDDSA == alg)
    {
        *ele_alg = kAlgorithm_SSS_EdDSA_Ed25519;
        status   = PSA_SUCCESS;
    }
    else if (true == PSA_ALG_IS_ECDSA(alg))
    {
        /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
        sign_hash_alg = PSA_ALG_SIGN_GET_HASH(alg);
        status        = PSA_SUCCESS;

        switch (sign_hash_alg)
        {
#if defined(PSA_WANT_ALG_SHA_224)
            case PSA_ALG_SHA_224:
                *ele_alg = kAlgorithm_SSS_ECDSA_SHA224;
                break;
#endif /* PSA_WANT_ALG_SHA_224 */
#if defined(PSA_WANT_ALG_SHA_256)
            case PSA_ALG_SHA_256:
                *ele_alg = kAlgorithm_SSS_ECDSA_SHA256;
                break;
#endif /* PSA_WANT_ALG_SHA_256 */
#if defined(PSA_WANT_ALG_SHA_384)
            case PSA_ALG_SHA_384:
                *ele_alg = kAlgorithm_SSS_ECDSA_SHA384;
                break;
#endif /* PSA_WANT_ALG_SHA_384 */
#if defined(PSA_WANT_ALG_SHA_512)
            case PSA_ALG_SHA_512:
                *ele_alg = kAlgorithm_SSS_ECDSA_SHA512;
                break;
#endif /* PSA_WANT_ALG_SHA_512 */
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    }
    else
    {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

static psa_status_t validate_key_bitlen_for_hash_sign(const psa_key_attributes_t *attributes,
                                                      psa_algorithm_t alg,
                                                      size_t hash_length)
{
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_6_violation]: composite expression assigned to wider type as required */
    size_t hash_alg_bitlen   = PSA_BYTES_TO_BITS(PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg)));
    size_t hash_input_bitlen = 0u;
    size_t key_bitlen        = psa_get_key_bits(attributes);

    /* Wrapcheck for `PSA_BYTES_TO_BITS(hash_length)` */
    if (true == mcux_psa_mul_size_t_wrapcheck(hash_length, 8u))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    hash_input_bitlen = PSA_BYTES_TO_BITS(hash_length);

    /* NIST-P 521 can used for signing 512-bit hashes,
     * so we just update the bitlen for the comparison
     */
    if (NISTP521_BITLEN == key_bitlen)
    {
        /* coverity[misra_c_2012_rule_14_3_violation]: condition depends on compile-time constant intentionally */
        key_bitlen = PSA_BYTES_TO_BITS(PSA_HASH_LENGTH(PSA_ALG_SHA_512));
    }

    /* The digest bitlen must be equal or larger than the key bitlen.
     * Limitation of the S200 HW.
     */
    if (key_bitlen > hash_alg_bitlen ||
        key_bitlen > hash_input_bitlen)
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_SUCCESS;
}

static psa_status_t asymmetric_sign_setkey(const psa_key_attributes_t *attributes,
                                           sss_sscp_object_t *sssKey,
                                           const uint8_t *key_buffer,
                                           size_t key_buffer_size,
                                           size_t key_bits)
{
    psa_status_t status           = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type       = psa_get_key_type(attributes);
    sss_key_part_t key_part       = kSSS_KeyPart_NONE;
    sss_cipher_type_t cipher_type = (sss_cipher_type_t) 0;
    size_t allocation_size        = 0u;
    uint8_t *key_data             = NULL;
    size_t key_data_size          = 0u;

    /* Unused */
    (void)key_buffer_size;

    /* Wrapcheck for PSA_BITS_TO_BYTES(key_bits) */
    if (true == mcux_psa_add_size_t_wrapcheck(key_bits, 7u))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    allocation_size = PSA_BITS_TO_BYTES(key_bits);

    /* Check if we support ECC family */
    status = PSA_SUCCESS;
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA macro result cast to wider essential type as needed */
    switch (PSA_KEY_TYPE_ECC_GET_FAMILY(key_type))
    {
        case PSA_ECC_FAMILY_SECP_R1:
            cipher_type = kSSS_CipherType_EC_NIST_P;
            break;
#if defined(ELE200_EXTENDED_FEATURES)
        case PSA_ECC_FAMILY_BRAINPOOL_P_R1:
            cipher_type = kSSS_CipherType_EC_BRAINPOOL_R1;
            break;
#endif /* ELE200_EXTENDED_FEATURES */
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (true == PSA_KEY_TYPE_IS_KEY_PAIR(key_type))
    {

        /* PSA ECC keypair is only the private part. So we import only the
         * private part to the S200 and we'll worry about the public part later,
         * if at all needed (e.g. signature verification with a keypair).
         */
        key_part      = kSSS_KeyPart_Private;
        /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally to pass to SSS API */
        key_data      = (uint8_t *)key_buffer;
        key_data_size = PSA_BITS_TO_BYTES(key_bits);
    }
    else
    {
        /* Set required S2XX flags and skip the first Byte of the ECC public key */
        key_part        = kSSS_KeyPart_Public;
        allocation_size = allocation_size * 2u;

        /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally to pass to SSS API */
        key_data      = (uint8_t *)key_buffer + 1;
        key_data_size = PSA_BITS_TO_BYTES(key_bits) * 2u;
    }

    /* Preemptively inflate the allocation size, due to possible additional
     * Bytes required for 521bit public/keypair keys
     */
    allocation_size = allocation_size + 6u;
    status = ele_s2xx_set_key(sssKey, 0u, /* key id */
                              key_data, key_data_size, key_part, cipher_type,
                              kSSS_KeyProp_CryptoAlgo_AsymSignVerify,
                              allocation_size, key_bits);
    return status;
}

/** \defgroup psa_asym_sign PSA transparent key driver entry points for asymmetric signatures
 *
 *  Entry points for asymmetric signatures as described by the PSA
 *  Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t ele_s2xx_transparent_sign_hash(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *hash,
                                            size_t hash_length,
                                            uint8_t *signature,
                                            size_t signature_size,
                                            size_t *signature_length)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey = {0};
    sss_algorithm_t ele_alg  = {0};
    size_t output_size       = 0;

    /* Convert PSA_ALG_* to ELE value and validate supported alg */
    status = translate_psa_asym_to_ele_asym(attributes, alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Hash sign/verify only with randomized ECDSA on S200 */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    if (false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* The given hash length and algorithm must match the ECDSA key length */
    status = validate_key_bitlen_for_hash_sign(attributes, alg, hash_length);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == hash || 0u == hash_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || NULL == signature_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    output_size = PSA_SIGN_OUTPUT_SIZE(psa_get_key_type(attributes), psa_get_key_bits(attributes), alg);
    if (output_size > signature_size)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = asymmetric_sign_setkey(attributes, &sssKey, key_buffer, key_buffer_size, psa_get_key_bits(attributes));
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *signature_length = signature_size;
    /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally to pass to SSS API */
    status = ele_s2xx_common_sign_digest((uint8_t *)hash, hash_length, signature, signature_length, &sssKey, ele_alg);
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

psa_status_t ele_s2xx_transparent_verify_hash(const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *hash,
                                              size_t hash_length,
                                              const uint8_t *signature,
                                              size_t signature_length)
{
    psa_status_t status                      = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey                 = {0};
    sss_sscp_object_t sssKey_public_exported = {0};
    sss_algorithm_t ele_alg                  = {0};
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA macro result cast to wider essential type as needed */
    psa_ecc_family_t family                  = PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes));

    /* For exporting the public part of the key in case of ECC keypair */
    uint8_t public_key_data[MAX_PAIR_KEY_SIZE_IN_BYTES] = {0u};
    size_t public_key_data_size                         = sizeof(public_key_data);
    size_t public_key_data_length                       = 0u;

    /* Convert PSA_ALG_* to ELE value and validate supported alg */
    status = translate_psa_asym_to_ele_asym(attributes, alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Hash sign/verify only with randomized ECDSA on S200 */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    if (false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* The given hash length and algorithm must match the ECDSA key length */
    status = validate_key_bitlen_for_hash_sign(attributes, alg, hash_length);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == hash || 0u == hash_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || 0u == signature_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = asymmetric_sign_setkey(attributes, &sssKey, key_buffer,
                                    key_buffer_size, psa_get_key_bits(attributes));
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    if (true == PSA_KEY_TYPE_IS_KEY_PAIR(psa_get_key_type(attributes)))
    {
        /* The previous setkey call imported only private part. We are doing
         * verification, so we need the public part. We export it and set it
         * separately.
         */

#if defined(ELE200_EXTENDED_FEATURES)
        if (is_fw_loaded() == PSA_SUCCESS)
        {
            /* FW is loaded, so we have the accelerated pubkey export API */
            status = ele_s2xx_get_ecc_public_key_from_private(&sssKey,
                                                              (public_key_data + 1),
                                                              (public_key_data_size - 1u),
                                                              &public_key_data_length,
                                                              NULL);
            if (PSA_SUCCESS != status)
            {
                goto exit;
            }
            public_key_data[0]     = 0x04u;
            public_key_data_length += 1u;
        }
        else
#endif
        {
            if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
            {
                return PSA_ERROR_SERVICE_FAILURE;
            }
            /* FW is not loaded, so we defer back to the SW implementation */
            status = psa_export_public_key_internal(attributes,
                                                    key_buffer,
                                                    key_buffer_size,
                                                    public_key_data,
                                                    public_key_data_size,
                                                    &public_key_data_length);
            if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
            {
                return PSA_ERROR_SERVICE_FAILURE;
            }

            if (PSA_SUCCESS != status)
            {
                goto exit;
            }
        }

        /* Set up the public-only key attributes and import into S200 */
        psa_key_attributes_t attributes_public = *attributes;
        psa_set_key_type(&attributes_public, PSA_KEY_TYPE_ECC_PUBLIC_KEY(family));

        status = asymmetric_sign_setkey(&attributes_public,
                                        &sssKey_public_exported,
                                        public_key_data,
                                        public_key_data_size,
                                        psa_get_key_bits(&attributes_public));
        if (PSA_SUCCESS != status)
        {
            goto exit;
        }

        /* Finally, verify with the exported public key */
        /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally to pass to SSS API */
        status = ele_s2xx_common_verify_digest((uint8_t *)hash, hash_length,
                                               /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally */
                                               (uint8_t *)signature, signature_length,
                                               &sssKey_public_exported, ele_alg);
    }
    else
    {
        /* We already have the public key, we can use it directly */
        /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally to pass to SSS API */
        status = ele_s2xx_common_verify_digest((uint8_t *)hash, hash_length,
                                               /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally */
                                               (uint8_t *)signature, signature_length,
                                               &sssKey, ele_alg);
    }

exit:
    (void)ele_s2xx_delete_key(&sssKey);
    (void)ele_s2xx_delete_key(&sssKey_public_exported);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

/** @} */ // end of psa_asym_sign
