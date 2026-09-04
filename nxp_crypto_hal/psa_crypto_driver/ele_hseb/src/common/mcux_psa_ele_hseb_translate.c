/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_ele_hseb_translate.h"

psa_status_t ele_hseb_to_psa_status(hseSrvResponse_t ele_hseb_status)
{
    psa_status_t psa_status = PSA_ERROR_GENERIC_ERROR;

    switch (ele_hseb_status) {
        case HSE_SRV_RSP_OK:
            psa_status = PSA_SUCCESS;
            break;
        case HSE_SRV_RSP_VERIFY_FAILED:
            psa_status = PSA_ERROR_INVALID_SIGNATURE;
            break;
        case HSE_SRV_RSP_INVALID_PARAM:
            psa_status = PSA_ERROR_INVALID_ARGUMENT;
            break;
        case HSE_SRV_RSP_NOT_SUPPORTED:
            psa_status = PSA_ERROR_NOT_SUPPORTED;
            break;
        case HSE_SRV_RSP_NOT_ENOUGH_SPACE:
            psa_status = PSA_ERROR_INSUFFICIENT_MEMORY;
            break;
        case HSE_SRV_RSP_STREAMING_MODE_FAILURE:
            psa_status = PSA_ERROR_BAD_STATE;
            break;
        case HSE_SRV_RSP_MEMORY_FAILURE:
            psa_status = PSA_ERROR_HARDWARE_FAILURE;
            break;
        case HSE_SRV_RSP_GENERAL_ERROR:
            psa_status = PSA_ERROR_GENERIC_ERROR;
            break;
        default:
            psa_status = PSA_ERROR_GENERIC_ERROR;
            break;
    }

    return psa_status;
}

psa_status_t psa_to_ele_hseb_hash(psa_algorithm_t alg,
                                  hseHashAlgo_t *hseb_hash)
{
    psa_status_t status          = PSA_SUCCESS;
    psa_algorithm_t psa_hash_alg = PSA_ALG_GET_HASH(alg);

    switch (psa_hash_alg) {
        case PSA_ALG_SHA_1:
            *hseb_hash = HSE_HASH_ALGO_SHA_1;
            break;
        case PSA_ALG_SHA_224:
            *hseb_hash = HSE_HASH_ALGO_SHA2_224;
            break;
        case PSA_ALG_SHA_256:
            *hseb_hash = HSE_HASH_ALGO_SHA2_256;
            break;
        case PSA_ALG_SHA_384:
            *hseb_hash = HSE_HASH_ALGO_SHA2_384;
            break;
        case PSA_ALG_SHA_512:
            *hseb_hash = HSE_HASH_ALGO_SHA2_512;
            break;
        case PSA_ALG_SHA_512_224:
            *hseb_hash = HSE_HASH_ALGO_SHA2_512_224;
            break;
        case PSA_ALG_SHA_512_256:
            *hseb_hash = HSE_HASH_ALGO_SHA2_512_256;
            break;
        case PSA_ALG_SHA3_224:
            *hseb_hash = HSE_HASH_ALGO_SHA3_224;
            break;
        case PSA_ALG_SHA3_256:
            *hseb_hash = HSE_HASH_ALGO_SHA3_256;
            break;
        case PSA_ALG_SHA3_384:
            *hseb_hash = HSE_HASH_ALGO_SHA3_384;
            break;
        case PSA_ALG_SHA3_512:
            *hseb_hash = HSE_HASH_ALGO_SHA3_512;
            break;
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }

    return status;
}

psa_status_t ele_hseb_to_psa_hash(hseHashAlgo_t hseb_hash,
                                  psa_algorithm_t *alg)
{
    psa_status_t status = PSA_SUCCESS;

    switch (hseb_hash) {
        case HSE_HASH_ALGO_SHA_1:
            *alg = PSA_ALG_SHA_1;
            break;
        case HSE_HASH_ALGO_SHA2_224:
            *alg = PSA_ALG_SHA_224;
            break;
        case HSE_HASH_ALGO_SHA2_256:
            *alg = PSA_ALG_SHA_256;
            break;
        case HSE_HASH_ALGO_SHA2_384:
            *alg = PSA_ALG_SHA_384;
            break;
        case HSE_HASH_ALGO_SHA2_512:
            *alg = PSA_ALG_SHA_512;
            break;
        case HSE_HASH_ALGO_SHA2_512_224:
            *alg = PSA_ALG_SHA_512_224;
            break;
        case HSE_HASH_ALGO_SHA2_512_256:
            *alg = PSA_ALG_SHA_512_256;
            break;
        case HSE_HASH_ALGO_SHA3_224:
            *alg = PSA_ALG_SHA3_224;
            break;
        case HSE_HASH_ALGO_SHA3_256:
            *alg = PSA_ALG_SHA3_256;
            break;
        case HSE_HASH_ALGO_SHA3_384:
            *alg = PSA_ALG_SHA3_384;
            break;
        case HSE_HASH_ALGO_SHA3_512:
            *alg = PSA_ALG_SHA3_512;
            break;
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }

    return status;
}

psa_status_t psa_to_hseb_mac_scheme(psa_algorithm_t alg,
                                    hseMacScheme_t *hseb_mac_scheme)
{
    psa_status_t status      = PSA_SUCCESS;
    psa_algorithm_t alg_full = PSA_ALG_FULL_LENGTH_MAC(alg);

    /* SHA3 unsupported for HMAC */
    switch (alg_full) {
        case PSA_ALG_CMAC:
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_CMAC;
            hseb_mac_scheme->sch.cmac.cipherAlgo = HSE_CIPHER_ALGO_AES;
            break;
        case PSA_ALG_HMAC(PSA_ALG_SHA_1):
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_HMAC;
            hseb_mac_scheme->sch.hmac.hashAlgo = HSE_HASH_ALGO_SHA_1;
            break;
        case PSA_ALG_HMAC(PSA_ALG_SHA_224):
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_HMAC;
            hseb_mac_scheme->sch.hmac.hashAlgo = HSE_HASH_ALGO_SHA2_224;
            break;
        case PSA_ALG_HMAC(PSA_ALG_SHA_256):
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_HMAC;
            hseb_mac_scheme->sch.hmac.hashAlgo = HSE_HASH_ALGO_SHA2_256;
            break;
        case PSA_ALG_HMAC(PSA_ALG_SHA_384):
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_HMAC;
            hseb_mac_scheme->sch.hmac.hashAlgo = HSE_HASH_ALGO_SHA2_384;
            break;
        case PSA_ALG_HMAC(PSA_ALG_SHA_512):
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_HMAC;
            hseb_mac_scheme->sch.hmac.hashAlgo = HSE_HASH_ALGO_SHA2_512;
            break;
        case PSA_ALG_HMAC(PSA_ALG_SHA_512_224):
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_HMAC;
            hseb_mac_scheme->sch.hmac.hashAlgo = HSE_HASH_ALGO_SHA2_512_224;
            break;
        case PSA_ALG_HMAC(PSA_ALG_SHA_512_256):
            hseb_mac_scheme->macAlgo = HSE_MAC_ALGO_HMAC;
            hseb_mac_scheme->sch.hmac.hashAlgo = HSE_HASH_ALGO_SHA2_512_256;
            break;
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }

    return status;
}

psa_status_t psa_to_hseb_curve(psa_key_type_t key_type,
                               psa_ecc_family_t ecc_family,
                               size_t key_bits,
                               hseEccCurveId_t *curve_id)
{
    psa_status_t status = PSA_SUCCESS;
    *curve_id           = HSE_EC_CURVE_NONE;

    if (PSA_ECC_FAMILY_SECP_R1 == ecc_family) {
        switch (key_bits) {
            case 256:
                *curve_id = HSE_EC_SEC_SECP256R1;
                break;
            case 384:
                *curve_id = HSE_EC_SEC_SECP384R1;
                break;
            case 521:
                *curve_id = HSE_EC_SEC_SECP521R1;
                break;
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    } else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == ecc_family) {
        switch (key_bits) {
            case 256:
                *curve_id = HSE_EC_BRAINPOOL_BRAINPOOLP256R1;
                break;
            case 320:
                *curve_id = HSE_EC_BRAINPOOL_BRAINPOOLP320R1;
                break;
            case 384:
                *curve_id = HSE_EC_BRAINPOOL_BRAINPOOLP384R1;
                break;
            case 512:
                *curve_id = HSE_EC_BRAINPOOL_BRAINPOOLP512R1;
                break;
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    } else if (PSA_ECC_FAMILY_TWISTED_EDWARDS == ecc_family) {
        if (255 == key_bits) {
            *curve_id = HSE_EC_25519_ED25519;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (PSA_ECC_FAMILY_MONTGOMERY == ecc_family) {
        if (255 == key_bits) {
            *curve_id = HSE_EC_25519_CURVE25519;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

void psa_to_hseb_key_usage(psa_key_usage_t key_usage,
                           hseKeyFlags_t *hseb_key_flags)
{
    if ((key_usage & PSA_KEY_USAGE_EXPORT) != 0u) {
        *hseb_key_flags |= HSE_KF_ACCESS_EXPORTABLE;
    }
    if ((key_usage & PSA_KEY_USAGE_ENCRYPT) != 0u) {
        *hseb_key_flags |= HSE_KF_USAGE_ENCRYPT;
    }
    if ((key_usage & PSA_KEY_USAGE_DECRYPT) != 0u) {
        *hseb_key_flags |= HSE_KF_USAGE_DECRYPT;
    }
    if (((key_usage & PSA_KEY_USAGE_SIGN_MESSAGE) != 0u) ||
        ((key_usage & PSA_KEY_USAGE_SIGN_HASH) != 0u)) {
        *hseb_key_flags |= HSE_KF_USAGE_SIGN;
    }
    if (((key_usage & PSA_KEY_USAGE_VERIFY_MESSAGE) != 0u) ||
        ((key_usage & PSA_KEY_USAGE_VERIFY_HASH) != 0u)) {
        *hseb_key_flags |= HSE_KF_USAGE_VERIFY;
    }
    if ((key_usage & PSA_KEY_USAGE_DERIVE) != 0u) {
        *hseb_key_flags |= HSE_KF_USAGE_DERIVE;
        *hseb_key_flags |= HSE_KF_USAGE_EXCHANGE;
    }
    if ((key_usage & PSA_KEY_USAGE_VERIFY_DERIVATION) != 0u) {
        *hseb_key_flags |= HSE_KF_USAGE_DERIVE;
    }
}

hseCipherBlockMode_t psa_to_hseb_cipher_mode(psa_algorithm_t alg)
{
    hseCipherBlockMode_t cipher_mode = HSE_CIPHER_BLOCK_MODE_NULL;
    switch (alg) {
        case PSA_ALG_ECB_NO_PADDING:
            cipher_mode = HSE_CIPHER_BLOCK_MODE_ECB;
            break;
        case PSA_ALG_CBC_NO_PADDING:
            cipher_mode = HSE_CIPHER_BLOCK_MODE_CBC;
            break;
        case PSA_ALG_CTR:
            cipher_mode = HSE_CIPHER_BLOCK_MODE_CTR;
            break;
        case PSA_ALG_CFB:
            cipher_mode = HSE_CIPHER_BLOCK_MODE_CFB;
            break;
        case PSA_ALG_OFB:
            cipher_mode = HSE_CIPHER_BLOCK_MODE_OFB;
            break;
        case PSA_ALG_CCM:
            cipher_mode = HSE_AUTH_CIPHER_MODE_CCM;
            break;
        case PSA_ALG_GCM:
            cipher_mode = HSE_AUTH_CIPHER_MODE_GCM;
            break;
        default:
            cipher_mode = HSE_CIPHER_BLOCK_MODE_NULL;
            break;
    }
    return cipher_mode;
}

hseAesBlockModeMask_t cipher_mode_to_cipher_mask(hseCipherBlockMode_t hse_cipher_mode)
{
    hseAesBlockModeMask_t mask = { 0 };
    /* PSA supports only one permitted cipher alg, so no need to OR them */
    switch (hse_cipher_mode) {
        case HSE_CIPHER_BLOCK_MODE_CTR:
            mask = HSE_KU_AES_BLOCK_MODE_CTR;
            break;
        case HSE_CIPHER_BLOCK_MODE_CBC:
            mask = HSE_KU_AES_BLOCK_MODE_CBC;
            break;
        case HSE_CIPHER_BLOCK_MODE_ECB:
            mask = HSE_KU_AES_BLOCK_MODE_ECB;
            break;
        case HSE_CIPHER_BLOCK_MODE_CFB:
            mask = HSE_KU_AES_BLOCK_MODE_CFB;
            break;
        case HSE_CIPHER_BLOCK_MODE_OFB:
            mask = HSE_KU_AES_BLOCK_MODE_OFB;
            break;
        case HSE_AUTH_CIPHER_MODE_CCM:
            mask = HSE_KU_AES_BLOCK_MODE_CCM;
            break;
        case HSE_AUTH_CIPHER_MODE_GCM:
            mask = HSE_KU_AES_BLOCK_MODE_GCM;
            break;
        default:
            mask = HSE_KU_AES_BLOCK_MODE_ANY;
            break;
    }
    return mask;
}

psa_status_t psa_to_ele_hseb_ecdsa(psa_algorithm_t alg,
                                   hseSignScheme_t *sign_scheme)
{
    psa_status_t status = psa_to_ele_hseb_hash(alg,
                                               &sign_scheme->sch.ecdsa.hashAlgo);
    sign_scheme->signSch = HSE_SIGN_ECDSA;
    return status;
}
