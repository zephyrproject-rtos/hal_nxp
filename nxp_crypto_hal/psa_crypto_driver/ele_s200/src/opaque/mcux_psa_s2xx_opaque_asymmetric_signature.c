/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_opaque_asymmetric_signature.c
 *
 * This file contains the implementation of the entry points associated to the
 * asymmetric signature capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */
#include "mcux_psa_s2xx_common_init.h"
#include "mcux_psa_s2xx_opaque_asymmetric_signature.h"
#include "mcux_psa_s2xx_key_locations.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_s2xx_hash.h"
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

#define NISTP521_BITLEN (521u)

static psa_status_t translate_psa_asym_to_ele_asym(psa_algorithm_t alg,
                                                   sss_algorithm_t *ele_alg)
{
    psa_status_t status           = PSA_SUCCESS;
    psa_algorithm_t sign_hash_alg = PSA_ALG_ANY_HASH;

    if (PSA_ALG_PURE_EDDSA == alg || PSA_ALG_ED25519PH == alg)
    {
        *ele_alg = kAlgorithm_SSS_EdDSA_Ed25519;
        status   = PSA_SUCCESS;
    }
    else if (true == PSA_ALG_IS_ECDSA(alg))
    {
        /* coverity[misra_c_2012_rule_10_4_violation] */
        /* coverity[misra_c_2012_rule_10_6_violation]: PSA_ALG_SIGN_GET_HASH macro contains signed/unsigned type issues */
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
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_6_violation]: PSA_ALG_SIGN_GET_HASH macro contains signed/unsigned type issues */
    size_t hash_alg_bitlen   = PSA_BYTES_TO_BITS(PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg)));
    size_t hash_input_bitlen = 0u;
    size_t key_bitlen        = psa_get_key_bits(attributes);

    /* Wrapcheck for `PSA_BYTES_TO_BITS(hash_length)` */
    if (true == mcux_psa_mul_size_t_wrapcheck(hash_length, 8u))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    hash_input_bitlen = PSA_BYTES_TO_BITS(hash_length);

    if (true == PSA_ALG_IS_ECDSA(alg))
    {
        /* NIST-P 521 can used for signing 512-bit hashes,
         * so we just update the bitlen for the comparison.
         */
        if (NISTP521_BITLEN == key_bitlen)
        {
            key_bitlen = 512u;
        }

        /* The digest bitlen must be equal or larger than the key bitlen.
         * Limitation of the S200 HW.
         */
        if (key_bitlen > hash_alg_bitlen ||
            key_bitlen > hash_input_bitlen)
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }
    else if (PSA_ALG_ED25519PH == alg)
    {
        if (false == IS_VALID_ED25519_BITLENGTH(key_bitlen))
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }
    else
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_SUCCESS;
}

static psa_status_t validate_key_bitlen_for_message_sign(const psa_key_attributes_t *attributes,
                                                         psa_algorithm_t alg)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    const size_t bits   = psa_get_key_bits(attributes);

    if (true == PSA_ALG_IS_ECDSA(alg) || PSA_ALG_ED25519PH == alg)
    {
        /* We will be pre-hashing the message for ECDSA and Ed25519ph,
         * so we know that the hash length is
         * PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg)).
         */
        /* coverity[misra_c_2012_rule_10_4_violation] */
        /* coverity[misra_c_2012_rule_10_6_violation]: PSA_ALG_SIGN_GET_HASH macro contains signed/unsigned type issues */
        status = validate_key_bitlen_for_hash_sign(attributes, alg, PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg)));
    }
    else if (PSA_ALG_PURE_EDDSA == alg)
    {
        /* S200 supports Ed25519 from the EdDSA suite */
        status = (true == IS_VALID_ED25519_BITLENGTH(bits)) ? PSA_SUCCESS : PSA_ERROR_NOT_SUPPORTED;
    }
    else
    {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

/** \defgroup psa_asym_sign_opaque PSA opaque key driver entry points for asymmetric signatures
 *
 *  Entry points for asymmetric signatures as described by the PSA
 *  Cryptoprocessor Driver interface specification with the use of opaque keys
 *
 *  @{
 */
psa_status_t ele_s2xx_opaque_sign_hash(const psa_key_attributes_t *attributes,
                                       const uint8_t *key_buffer, size_t key_buffer_size,
                                       psa_algorithm_t alg,
                                       const uint8_t *hash, size_t hash_length,
                                       uint8_t *signature, size_t signature_size,
                                       size_t *signature_length)
{
    psa_status_t status           = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey      = {0};
    sss_algorithm_t ele_alg       = {0};
    size_t output_size            = 0u;
    psa_key_location_t location   = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
    sss_cipher_type_t cipher_type = {0u};
    psa_key_type_t type           = psa_get_key_type(attributes);
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA_KEY_TYPE_ECC_GET_FAMILY uses signed 0xff mask */
    psa_ecc_family_t ecc_family   = PSA_KEY_TYPE_ECC_GET_FAMILY(type);

    status = translate_psa_asym_to_ele_asym(alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = translate_psa_ecc_family_to_ele_cipher_type(attributes, &cipher_type);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
    {
        /* EL2GO is a special case and it supports only SECP ECDSA for
         * sign/verify hash.
         */
        /* coverity[misra_c_2012_rule_10_4_violation]: PSA_ALG_IS_RANDOMIZED_ECDSA uses 0x100UL bitmask */
        if (ecc_family != PSA_ECC_FAMILY_SECP_R1 || false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg))
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    /* Hash sign/verify only with randomized ECDSA or Ed25519ph on S200 */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA_ALG_IS_RANDOMIZED_ECDSA uses 0x100UL bitmask */
    if (false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg) && alg != PSA_ALG_ED25519PH)
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* The given hash length and algorithm must be valid */
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

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *signature_length = signature_size;
    /* coverity[misra_c_2012_rule_11_8_violation]: hash is const but sign API requires non-const digest buffer */
    status = ele_s2xx_common_sign_digest((uint8_t *)hash,
                                         hash_length,
                                         signature,
                                         signature_length,
                                         &sssKey,
                                         ele_alg);
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

psa_status_t ele_s2xx_opaque_verify_hash(const psa_key_attributes_t *attributes,
                                         const uint8_t *key_buffer, size_t key_buffer_size,
                                         psa_algorithm_t alg,
                                         const uint8_t *hash, size_t hash_length,
                                         const uint8_t *signature, size_t signature_length)
{
    psa_status_t status           = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey      = {0};
    sss_algorithm_t ele_alg       = {0};
    psa_key_location_t location   = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
    sss_cipher_type_t cipher_type = {0u};
    psa_key_type_t type           = psa_get_key_type(attributes);
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA_KEY_TYPE_ECC_GET_FAMILY uses signed 0xff mask */
    psa_ecc_family_t ecc_family   = PSA_KEY_TYPE_ECC_GET_FAMILY(type);

    status = translate_psa_asym_to_ele_asym(alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = translate_psa_ecc_family_to_ele_cipher_type(attributes, &cipher_type);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
    {
        /* EL2GO is a special case and it supports only SECP ECDSA for
         * sign/verify hash.
         */
        /* coverity[misra_c_2012_rule_10_4_violation]: PSA_ALG_IS_RANDOMIZED_ECDSA uses 0x100UL bitmask */
        if (ecc_family != PSA_ECC_FAMILY_SECP_R1 || false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg))
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    /* Hash sign/verify only with randomized ECDSA or Ed25519ph on S200 */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA_ALG_IS_RANDOMIZED_ECDSA uses 0x100UL bitmask */
    if (false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg) && alg != PSA_ALG_ED25519PH)
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* The given hash length and algorithm must be valid */
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

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* coverity[misra_c_2012_rule_11_8_violation]: hash/signature are const but verify API requires non-const buffers */
    status = ele_s2xx_common_verify_digest((uint8_t *)hash,
                                           hash_length,
                                           (uint8_t *)signature,
                                           signature_length,
                                           &sssKey,
                                           ele_alg);
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

psa_status_t ele_s2xx_opaque_sign_message(const psa_key_attributes_t *attributes,
                                          const uint8_t *key_buffer, size_t key_buffer_size,
                                          psa_algorithm_t alg,
                                          const uint8_t *input, size_t input_length,
                                          uint8_t *signature, size_t signature_size,
                                          size_t *signature_length)
{
    psa_status_t status                            = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey                       = {0};
    sss_algorithm_t ele_alg                        = {0};
    uint8_t hash[PSA_HASH_LENGTH(PSA_ALG_SHA_512)] = {0u};
    size_t hash_length                             = 0u;
    sss_cipher_type_t cipher_type                  = {0u};
    const uint8_t *input_internal                  = input;
    size_t input_length_internal                   = input_length;
    psa_key_type_t type                            = psa_get_key_type(attributes);
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA_KEY_TYPE_ECC_GET_FAMILY uses signed 0xff mask */
    psa_ecc_family_t ecc_family                    = PSA_KEY_TYPE_ECC_GET_FAMILY(type);
    psa_key_location_t location                    = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

    status = translate_psa_asym_to_ele_asym(alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = translate_psa_ecc_family_to_ele_cipher_type(attributes, &cipher_type);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = validate_key_bitlen_for_message_sign(attributes, alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
    {
        /* EL2GO is a special case and it supports only SECP ECDSA and
         * PURE_EDDSA for sign/verify message.
         */
        if ((ecc_family != PSA_ECC_FAMILY_SECP_R1) &&
            (ecc_family != PSA_ECC_FAMILY_TWISTED_EDWARDS))
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
        if (ecc_family == PSA_ECC_FAMILY_SECP_R1 && false == PSA_ALG_IS_ECDSA(alg))
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
        if (ecc_family == PSA_ECC_FAMILY_TWISTED_EDWARDS && PSA_ALG_PURE_EDDSA != alg)
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    /* Message sign/verify only with randomized ECDSA, Ed25519, or Ed25519ph */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA_ALG_IS_RANDOMIZED_ECDSA uses 0x100UL bitmask */
    if ((false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg)) &&
        (PSA_ALG_PURE_EDDSA != alg) &&
        (PSA_ALG_ED25519PH != alg))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == input_internal || 0u == input_length_internal)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || NULL == signature_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Pre-hash for hash-and-sign algorithms */
    if (true == PSA_ALG_IS_ECDSA(alg) || PSA_ALG_ED25519PH == alg)
    {
        /* coverity[misra_c_2012_rule_10_4_violation] */
        /* coverity[misra_c_2012_rule_10_6_violation]: PSA_ALG_SIGN_GET_HASH macro contains signed/unsigned type issues */
        status = ele_s2xx_transparent_hash_compute(PSA_ALG_SIGN_GET_HASH(alg),
                                                   input_internal,
                                                   input_length_internal,
                                                   hash, sizeof(hash),
                                                   &hash_length);
        if (PSA_SUCCESS != status)
        {
            return status;
        }

        /* Update the inputs for the call to sign */
        input_internal        = hash;
        input_length_internal = hash_length;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *signature_length = signature_size;
    /* coverity[misra_c_2012_rule_11_8_violation]: input_internal is const but sign API requires non-const digest buffer */
    status = ele_s2xx_common_sign_digest((uint8_t *)input_internal,
                                         input_length_internal,
                                         signature,
                                         signature_length,
                                         &sssKey,
                                         ele_alg);
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

psa_status_t ele_s2xx_opaque_verify_message(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer, size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *input, size_t input_length,
                                            const uint8_t *signature, size_t signature_length)
{
    psa_status_t status                            = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey                       = {0};
    sss_algorithm_t ele_alg                        = {0};
    uint8_t hash[PSA_HASH_LENGTH(PSA_ALG_SHA_512)] = {0u};
    size_t hash_length                             = 0u;
    sss_cipher_type_t cipher_type                  = {0u};
    const uint8_t *input_internal                  = input;
    size_t input_length_internal                   = input_length;
    psa_key_type_t type                            = psa_get_key_type(attributes);
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA_KEY_TYPE_ECC_GET_FAMILY uses signed 0xff mask */
    psa_ecc_family_t ecc_family                    = PSA_KEY_TYPE_ECC_GET_FAMILY(type);
    psa_key_location_t location                    = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

    status = translate_psa_asym_to_ele_asym(alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = translate_psa_ecc_family_to_ele_cipher_type(attributes, &cipher_type);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = validate_key_bitlen_for_message_sign(attributes, alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
    {
        /* EL2GO is a special case and it supports only SECP ECDSA and
         * PURE_EDDSA for sign/verify message.
         */
        if ((ecc_family != PSA_ECC_FAMILY_SECP_R1) &&
            (ecc_family != PSA_ECC_FAMILY_TWISTED_EDWARDS))
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
        if (ecc_family == PSA_ECC_FAMILY_SECP_R1 && false == PSA_ALG_IS_ECDSA(alg))
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
        if (ecc_family == PSA_ECC_FAMILY_TWISTED_EDWARDS && PSA_ALG_PURE_EDDSA != alg)
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    /* Message sign/verify only with randomized ECDSA, Ed25519, or Ed25519ph */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA_ALG_IS_RANDOMIZED_ECDSA uses 0x100UL bitmask */
    if ((false == PSA_ALG_IS_RANDOMIZED_ECDSA(alg)) &&
        (PSA_ALG_PURE_EDDSA != alg) &&
        (PSA_ALG_ED25519PH != alg))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == input_internal || 0u == input_length_internal)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || 0u == signature_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Pre-hash for hash-and-sign algorithms */
    if (true == PSA_ALG_IS_ECDSA(alg) || PSA_ALG_ED25519PH == alg)
    {
        /* coverity[misra_c_2012_rule_10_4_violation] */
        /* coverity[misra_c_2012_rule_10_6_violation]: PSA_ALG_SIGN_GET_HASH macro contains signed/unsigned type issues */
        status = ele_s2xx_transparent_hash_compute(PSA_ALG_SIGN_GET_HASH(alg),
                                                   input_internal,
                                                   input_length_internal,
                                                   hash, sizeof(hash),
                                                   &hash_length);
        if (PSA_SUCCESS != status)
        {
            return status;
        }

        /* Update the inputs for the call to verify */
        input_internal        = hash;
        input_length_internal = hash_length;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* coverity[misra_c_2012_rule_11_8_violation]: input_internal/signature are const but verify API requires non-const */
    status = ele_s2xx_common_verify_digest((uint8_t *)input_internal,
                                           input_length_internal,
                                           (uint8_t *)signature,
                                           signature_length,
                                           &sssKey,
                                           ele_alg);
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

/** @} */ // end of psa_asym_sign_opaque
