/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
 *  Constant-time functions
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/** \file mcux_psa_s2xx_common_compute.c
 *
 * This file contains the implementation of the entry points for the
 * driver-specific functions for crypto operations
 *
 */

#include <limits.h>
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_s2xx_key_locations.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

/*  AEAD  */

psa_status_t ele_s2xx_common_aead(const uint8_t *nonce, size_t nonce_length,
                                  const uint8_t *additional_data, size_t additional_data_length,
                                  const uint8_t *input, size_t input_size,
                                  uint8_t *output,
                                  uint8_t *tag, size_t *tag_length,
                                  sss_mode_t mode, sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg)
{
    sss_sscp_aead_t ctx = {0};

    if ((sss_sscp_aead_context_init(&ctx, &g_ele_ctx.sssSession, sssKey, ele_alg, mode)) !=
        kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* RUN AEAD */
    /* coverity[misra_c_2012_rule_11_8_violation]: nonce parameter is const but third-party API requires non-const */
    if ((sss_sscp_aead_one_go(&ctx, input, output, input_size, (uint8_t *)nonce, nonce_length,
                              additional_data, additional_data_length, tag, tag_length)) !=
        kStatus_SSS_Success)
    {
        (void)sss_sscp_aead_context_free(&ctx);
        if (kMode_SSS_Decrypt == mode)
        {
            /* If AEAD decrypt failed in this case we cannot differentiate between root cause
             * It may be due to some sanity check, but most likely due to tag mismatch between actual and expected value
             * So treat all fails in this case as signature mismatch
             */
            return PSA_ERROR_INVALID_SIGNATURE;
        }
        return PSA_ERROR_GENERIC_ERROR;
    };

    /* Free contexts */
    if (sss_sscp_aead_context_free(&ctx) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

/*  MAC  */

psa_status_t ele_s2xx_common_mac(const uint8_t *input, size_t input_length,
                                 uint8_t *mac, size_t mac_size, size_t *mac_length,
                                 sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg)
{
    sss_sscp_mac_t ctx = {0};

    /* Init context for MAC*/
    if ((sss_sscp_mac_context_init(&ctx, &g_ele_ctx.sssSession, sssKey, ele_alg, kMode_SSS_Mac)) !=
        kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }
    /* Call MAC one go*/
    if ((sss_sscp_mac_one_go(&ctx, (const uint8_t *)input, input_length, (uint8_t *)mac, &mac_size)) !=
        kStatus_SSS_Success)
    {
        (void)sss_sscp_mac_context_free(&ctx);
        return PSA_ERROR_GENERIC_ERROR;
    }

    *mac_length = mac_size;

    /* Free context */
    if (sss_sscp_mac_context_free(&ctx) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

/*  CIPHER  */

psa_status_t ele_s2xx_common_cipher(sss_sscp_object_t *sssKey,
                                    const uint8_t *iv, size_t iv_length,
                                    const uint8_t *input, uint8_t *output,
                                    size_t input_length,
                                    sss_algorithm_t ele_algo, sss_mode_t mode)
{
    sss_sscp_symmetric_t ctx = {0};

    /* Init symmetric context */
    if (sss_sscp_symmetric_context_init(&ctx, &g_ele_ctx.sssSession,
                                        sssKey, ele_algo,
                                        mode) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Run encryption */
    /* coverity[misra_c_2012_rule_11_8_violation]: iv parameter is const but third-party API requires non-const */
    if (sss_sscp_cipher_one_go(&ctx, (uint8_t *)iv,
                               iv_length, input,
                               output, input_length) != kStatus_SSS_Success)
    {
        (void)sss_sscp_symmetric_context_free(&ctx);
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Clean up */
    if (sss_sscp_symmetric_context_free(&ctx) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

/*  ASYMMETRIC  */

psa_status_t ele_s2xx_common_sign_digest(uint8_t *digest, size_t digest_len,
                                         uint8_t *signature, size_t *signature_len,
                                         sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg)
{
    sss_sscp_asymmetric_t ctx = {0u};

    /* Initialize asymmetric context for signing */
    if (sss_sscp_asymmetric_context_init(&ctx,  &g_ele_ctx.sssSession,
                                         sssKey, ele_alg, kMode_SSS_Sign) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Sign message digest */
    if (sss_sscp_asymmetric_sign_digest(&ctx, digest, digest_len,
                                        signature, signature_len) != kStatus_SSS_Success)
    {
        (void)sss_sscp_asymmetric_context_free(&ctx);
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Clean up */
    if (sss_sscp_asymmetric_context_free(&ctx) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

psa_status_t ele_s2xx_common_verify_digest(uint8_t *digest, size_t digest_len,
                                           uint8_t *signature, size_t signature_len,
                                           sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg)
{
    sss_sscp_asymmetric_t ctx = {0u};

    /* Initialize asymmetric context for signing */
    if (sss_sscp_asymmetric_context_init(&ctx,  &g_ele_ctx.sssSession,
                                         sssKey, ele_alg, kMode_SSS_Verify) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Verify message digest */
    if (sss_sscp_asymmetric_verify_digest(&ctx, digest, digest_len,
                                          signature, signature_len) != kStatus_SSS_Success)
    {
        (void)sss_sscp_asymmetric_context_free(&ctx);

        /* We do not have return code granularity for differentiating
         * generic errors vs signature verification errors.
         * We will assume the more likely situation of a failure at this point,
         * which is signature verification failure.
         */
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Clean up */
    if (sss_sscp_asymmetric_context_free(&ctx) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

/*  KEY AGREEMENT  */

psa_status_t ele_s2xx_common_key_agreement(sss_sscp_object_t *sssKey,
                                           sss_sscp_object_t *sssKey_peer,
                                           sss_sscp_object_t *sssKey_shared,
                                           uint8_t *shared_secret,
                                           size_t shared_secret_size,
                                           size_t *shared_secret_length,
                                           sss_algorithm_t ele_alg)
{
    sss_sscp_derive_key_t ctx   = {0};
    size_t shared_secret_bitlen = 0u;

    if (sss_sscp_derive_key_context_init(&ctx,  &g_ele_ctx.sssSession, sssKey,
                                         ele_alg, kMode_SSS_ComputeSharedSecret) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    if (sss_sscp_asymmetric_dh_derive_key(&ctx, sssKey_peer, sssKey_shared) != kStatus_SSS_Success)
    {
        (void)sss_sscp_derive_key_context_free(&ctx);
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Use the length parameter as an in/out argument and retrieve the key */
    *shared_secret_length = shared_secret_size;
    if (sss_sscp_key_store_get_key(&g_ele_ctx.keyStore, sssKey_shared,
                                   shared_secret, shared_secret_length,
                                   &shared_secret_bitlen, kSSS_KeyPart_Default) != kStatus_SSS_Success)
    {
        (void)sss_sscp_derive_key_context_free(&ctx);
        return PSA_ERROR_GENERIC_ERROR;
    }

    if (sss_sscp_derive_key_context_free(&ctx) != kStatus_SSS_Success)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

/* UTILITIES */


static psa_status_t get_ele_fw_version(uint8_t *ele_fw_version)
{
    sss_mgmt_t mgmtContext  = {0u};
    psa_status_t psa_status = PSA_ERROR_INVALID_ARGUMENT;

    size_t datalen = 8u;

    /* PropertyId of Edgelock Firmware version */
    uint32_t propertyId = 0x51u;

    do
    {
        if (sss_mgmt_context_init(&mgmtContext, &g_ele_ctx.sssSession) != kStatus_SSS_Success)
        {
            break;
        }

        /* READ FUSE */
        if (sss_mgmt_get_property(&mgmtContext, propertyId, ele_fw_version, &datalen) != kStatus_SSS_Success)
        {
            break;
        }

        /* If all steps before passes without break, then consider it as success*/
        psa_status = PSA_SUCCESS;

    } while (false);

    /* FREE MGMT CONTEXT */
    (void)sss_mgmt_context_free(&mgmtContext);

    return psa_status;
}

psa_status_t is_fw_loaded(void)
{
    uint32_t ele_version[2] = { 0u };

    /* ELE will respond with the FW version equal to this iff no FW is loaded */
    static const uint32_t no_fw_loaded[2] = { 0xffffffffu, 0xffffffffu };

    if (get_ele_fw_version((uint8_t *)ele_version) != PSA_SUCCESS )
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    if (memcmp(no_fw_loaded, ele_version, sizeof(no_fw_loaded)) == 0)
    {
        /* No FW loaded. We only support S200 baseline ROM functionality */
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Some FW is loaded */
    return PSA_SUCCESS;
}

/**
 * Taken from the mbedtls library/constant_time.c implementation file and
 * modified to not depend on any MBEDTLS preprocessor macros.
 */
int ele_s2xx_util_ct_memcmp(const void *a,
                            const void *b,
                            size_t n)
{
    size_t i = 0;
    /*
     * `A` and `B` are cast to volatile to ensure that the compiler
     * generates code that always fully reads both buffers.
     * Otherwise it could generate a test to exit early if `diff` has all
     * bits set early in the loop.
     */
    volatile const unsigned char *A = (volatile const unsigned char *) a;
    volatile const unsigned char *B = (volatile const unsigned char *) b;
    uint32_t diff = 0;

    for (; i < n; i++) {
        /* Read volatile data in order before computing diff.
         * This avoids IAR compiler warning:
         * 'the order of volatile accesses is undefined ..' */
        unsigned char x = A[i], y = B[i];
        diff |= (uint32_t)x ^ (uint32_t)y;
    }

#if (INT_MAX < INT32_MAX)
    /* We don't support int smaller than 32-bits, but if someone tried to build
     * with this configuration, there is a risk that, for differing data, the
     * only bits set in diff are in the top 16-bits, and would be lost by a
     * simple cast from uint32 to int.
     * This would have significant security implications, so protect against it. */
#error "ele_s2xx_util_ct_memcmp() requires minimum 32-bit ints"
#else
    /* The bit-twiddling ensures that when we cast uint32_t to int, we are casting
     * a value that is in the range 0..INT_MAX - a value larger than this would
     * result in implementation defined behaviour.
     *
     * This ensures that the value returned by the function is non-zero iff
     * diff is non-zero.
     */
    uint32_t result = (diff & 0xffffU) | (diff >> 16U);
    /* coverity[misra_c_2012_rule_10_8_violation]: intentional cast of unsigned result to signed int return type */
    return (int)result;
#endif
}

size_t ele_s2xx_get_ecc_private_key_size(size_t key_bits)
{
    /* CERT INT30-C: guard addition before computing byte length */
    if (true == mcux_psa_add_size_t_wrapcheck(key_bits, 7u))
    {
        return 0u;
    }
    return (key_bits + 7u) >> 3u;
}

size_t ele_s2xx_get_ecc_public_key_size(size_t key_bits)
{
    /* CERT INT30-C: guard addition and subsequent left-shift (x2) */
    if (true == mcux_psa_add_size_t_wrapcheck(key_bits, 7u))
    {
        return 0u;
    }
    size_t bytes = (key_bits + 7u) >> 3u;
    if (true == mcux_psa_add_size_t_wrapcheck(bytes, bytes))
    {
        return 0u;
    }
    return bytes << 1u;
}

size_t ele_s2xx_get_ecc_keypair_size(size_t key_bits)
{
    const size_t key_length_private = ele_s2xx_get_ecc_private_key_size(key_bits);
    const size_t key_length_public  = ele_s2xx_get_ecc_public_key_size(key_bits);
    /* CERT INT30-C: guard addition of private and public key lengths */
    if (true == mcux_psa_add_size_t_wrapcheck(key_length_private, key_length_public))
    {
        return 0u;
    }
    return key_length_private + key_length_public;
}

psa_status_t translate_psa_ecc_family_to_ele_cipher_type(const psa_key_attributes_t *attributes,
                                                         sss_cipher_type_t *cipher_type)
{
    psa_status_t status = PSA_SUCCESS;
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA macro uses signed literal 0xff with unsigned type */
    psa_ecc_family_t ecc_family = PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes));

    switch (ecc_family)
    {
        case PSA_ECC_FAMILY_SECP_R1:
            *cipher_type = kSSS_CipherType_EC_NIST_P;
            break;
        case PSA_ECC_FAMILY_TWISTED_EDWARDS:
            *cipher_type = kSSS_CipherType_EC_TWISTED_ED;
            break;
        case PSA_ECC_FAMILY_MONTGOMERY:
            *cipher_type = kSSS_CipherType_EC_MONTGOMERY;
            break;
#if defined(ELE200_EXTENDED_FEATURES)
        case PSA_ECC_FAMILY_BRAINPOOL_P_R1:
            *cipher_type = kSSS_CipherType_EC_BRAINPOOL_R1;
            break;
#endif /* ELE200_EXTENDED_FEATURES */
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }
    return status;
}

psa_status_t translate_psa_algorithm_to_ele_key_property(psa_algorithm_t alg,
                                                         sss_sscp_key_property_t *prop)
{
    psa_status_t status = PSA_SUCCESS;

    /* Translation and coarse validation to support all feature sets between
     * S200 devices + FWs. Support for specific PSA_ALG_XXX is to be checked
     * on key usage (per device and key location, as support may differ) during
     * crypto operations.
     */
    if (true == PSA_ALG_IS_ECDSA(alg) || PSA_ALG_PURE_EDDSA == alg ||
        PSA_ALG_ED25519PH == alg)
    {
        *prop |= kSSS_KeyProp_CryptoAlgo_AsymSignVerify;
    }
    else if (PSA_ALG_ECB_NO_PADDING == alg || PSA_ALG_CBC_NO_PADDING == alg ||
             PSA_ALG_CTR == alg || ALG_NXP_ALL_CIPHER == alg)
    {
        *prop |= kSSS_KeyProp_CryptoAlgo_AES;
    }
    /* coverity[misra_c_2012_rule_12_2_violation] */
    /* coverity[misra_c_2012_rule_10_1_violation] */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macros contain signed/unsigned type mismatches and shift issues */
    else if (PSA_ALG_CCM == PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg) || PSA_ALG_GCM == PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg) ||
             ALG_NXP_ALL_AEAD == alg)
    {
        *prop |= kSSS_KeyProp_CryptoAlgo_AEAD;
    }
    else if (true == PSA_ALG_IS_HMAC(alg) || PSA_ALG_CMAC == alg)
    {
        *prop |= kSSS_KeyProp_CryptoAlgo_MAC;
    }
    /* coverity[misra_c_2012_rule_7_2_violation]: PSA macro contains unsigned literal without U suffix */
    else if (true == PSA_ALG_IS_ANY_HKDF(alg) || true == PSA_ALG_IS_ECDH(alg) ||
             ALG_S200_ECBKDF_OR_CKDF == alg || ALG_S200_ECDH_CKDF == alg)
    {
        *prop |= kSSS_KeyProp_CryptoAlgo_KDF;
    }
    else
    {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

psa_status_t ele_s2xx_get_algo_keyprop(const psa_key_attributes_t *attributes,
                                       sss_sscp_key_property_t *s2xx_algo_prop,
                                       sss_key_part_t *s2xx_key_part,
                                       sss_cipher_type_t *s2xx_cipher_type,
                                       size_t *allocation_size)
{
    psa_status_t status         = PSA_SUCCESS;
    psa_key_type_t key_type     = psa_get_key_type(attributes);
    size_t key_bits             = psa_get_key_bits(attributes);
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

    /* Wrapcheck for PSA_BITS_TO_BYTES(key_bits) */
    if (true == mcux_psa_add_size_t_wrapcheck(key_bits, 7u))
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    /* Deal with the key part */
    if (true == PSA_KEY_TYPE_IS_ASYMMETRIC(key_type))
    {
        if (true == PSA_KEY_TYPE_IS_PUBLIC_KEY(key_type))
        {
            *s2xx_key_part   = kSSS_KeyPart_Public;
            *allocation_size = PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(key_bits);
        }
        else if (true == PSA_KEY_TYPE_IS_KEY_PAIR(key_type))
        {
            *s2xx_key_part   = kSSS_KeyPart_Pair;
            *allocation_size = (PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(key_bits) + PSA_BITS_TO_BYTES(key_bits));
        }
        else
        {
            status = PSA_ERROR_INVALID_ARGUMENT;
            goto exit;
        }

        status = translate_psa_ecc_family_to_ele_cipher_type(attributes,
                                                             s2xx_cipher_type);
        if (PSA_SUCCESS != status)
        {
            goto exit;
        }
    }
    else
    {
        /* Symmetric is simple */
        *s2xx_key_part    = kSSS_KeyPart_Default;
        *s2xx_cipher_type = kSSS_CipherType_SYMMETRIC;
        *allocation_size  = PSA_BITS_TO_BYTES(key_bits);
    }

    /* Translate and validate actual algorithm that is to be used.
     * Add check for PSA_ALG_NONE, since it is ok for some EL2GO blobs.
     */
    status = translate_psa_algorithm_to_ele_key_property(psa_get_key_algorithm(attributes),
                                                         s2xx_algo_prop);
    if (PSA_ERROR_NOT_SUPPORTED == status &&
        PSA_ALG_NONE == psa_get_key_algorithm(attributes) &&
        true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
    {
        status = PSA_SUCCESS;
    }

exit:
    return status;
}
