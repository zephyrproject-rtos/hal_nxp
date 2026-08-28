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

#include "mcux_psa_caam_utils.h"
#include "mcux_psa_caam_init.h"
#include "mbedtls/error.h"
#include "mcux_psa_caam_common_key_generation.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"
#include "psa_util_internal.h"
#include "mbedtls/platform.h"
#include "mbedtls/build_info.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "mbedtls/private/ecdsa.h"
#include "mbedtls/private/ecp.h"
#else
#include "mbedtls/ecdsa.h"
#include "mbedtls/ecp.h"
#endif
#include "mbedtls/psa_util.h"

mbedtls_ecp_group_id mbedtls_ecc_group_from_psa(psa_ecc_family_t family, size_t bits);

static inline psa_status_t caam_cesc_key_type(mcux_psa_caam_key_type_t caam_key_type,
                                              caam_desc_type_t *desc_key_type)
{
    switch (caam_key_type) {
        case MCUX_PSA_CAAM_KEY_TYPE_ECB:
        {
            *desc_key_type = kCAAM_Descriptor_Type_Ecb_Jkek;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_CCM:
        {
            *desc_key_type = kCAAM_Descriptor_Type_Ccm_Jkek;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}

psa_status_t caam_opaque_encapsulate_key(mcux_psa_caam_key_type_t caam_key_type,
                                         const uint8_t *key,
                                         size_t key_length,
                                         uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         size_t *key_buffer_length)
{
    status_t caam_status      = kStatus_Fail;
    psa_status_t err          = PSA_ERROR_NOT_SUPPORTED;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    caam_desc_type_t desc_key_type;

    if (mcux_psa_add_size_t_wrapcheck(key_length, 64U)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    if (CAAM_ENCAP_DATA_SIZE(key_length) > key_buffer_size) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }

    /* Generate key modifier */
    caam_status =
        CAAM_RNG_GetRandomData(PSA_CAAM,
                               &caam_handle,
                               kCAAM_RngStateHandle0,
                               key_buffer,
                               16,
                               kCAAM_RngDataAny,
                               NULL);
    err = caam_to_psa_status(caam_status);

    if (err == PSA_SUCCESS) {
#if 0
        if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
            caam_status =
                CAAM_RedBlob_Encapsule(PSA_CAAM,
                                       &caam_handle,
                                       key_buffer,
                                       16,
                                       key,
                                       key_length,
                                       &key_buffer[16]);
            err = caam_to_psa_status(caam_status);
        } else
#endif
        {
            err = caam_cesc_key_type(caam_key_type, &desc_key_type);

            if (err == PSA_SUCCESS) {
                caam_status = CAAM_BlackBlob_Encapsule(PSA_CAAM,
                                                       &caam_handle,
                                                       key_buffer,
                                                       16,
                                                       key,
                                                       key_length,
                                                       &key_buffer[16],
                                                       desc_key_type);
                err         = caam_to_psa_status(caam_status);
            }
        }
    }

    if (err == PSA_SUCCESS) {
        *key_buffer_length = CAAM_ENCAP_DATA_SIZE(key_length);
    }

    return err;
}

psa_status_t caam_opaque_decapsulate_key(mcux_psa_caam_key_type_t caam_key_type,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         uint8_t *key,
                                         size_t key_size)
{
    status_t caam_status      = kStatus_Fail;
    psa_status_t err          = PSA_ERROR_NOT_SUPPORTED;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    caam_desc_type_t desc_key_type;

    if (mcux_psa_add_size_t_wrapcheck(key_size, 64U)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    if (CAAM_ENCAP_DATA_SIZE(key_size) > key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

#if 0
    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        caam_status =
            CAAM_RedBlob_Decapsule(PSA_CAAM,
                                   &caam_handle,
                                   key_buffer,
                                   16,
                                   key,
                                   key_length,
                                   &key_buffer[16]);
        err = caam_to_psa_status(caam_status);
    } else
#endif
    {
        err = caam_cesc_key_type(caam_key_type, &desc_key_type);

        if (err == PSA_SUCCESS) {
            caam_status = CAAM_BlackBlob_Decapsule(PSA_CAAM,
                                                   &caam_handle,
                                                   key_buffer,
                                                   16,
                                                   &key_buffer[16],
                                                   key,
                                                   key_size,
                                                   desc_key_type);
            err         = caam_to_psa_status(caam_status);
        }
    }

    return err;
}

psa_status_t psa_to_caam_ecc_key_algo(psa_key_type_t key_type,
                                      size_t key_bits,
                                      caam_ecc_ecdsel_t *ecc_ecdsel,
                                      mbedtls_ecp_group_id *ecp_grou_id)
{
    psa_ecc_family_t family = (psa_ecc_family_t) PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);

    switch (family) {
        case PSA_ECC_FAMILY_SECP_R1:
        {
            switch (key_bits) {
                case 192:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_P_192;
                    break;
                }
                case 224:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_P_224;
                    break;
                }
                case 256:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_P_256;
                    break;
                }
                case 384:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_P_384;
                    break;
                }
                case 521:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_P_521;
                    break;
                }
                default:
                {
                    return PSA_ERROR_NOT_SUPPORTED;
                }
            }
            break;
        }
        case PSA_ECC_FAMILY_SECP_K1:
        {
            switch (key_bits) {
                case 192:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_secp192k1;
                    break;
                }
                case 224:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_secp224k1;
                    break;
                }
                case 256:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_secp256k1;
                    break;
                }
                default:
                {
                    return PSA_ERROR_NOT_SUPPORTED;
                }
            }
            break;
        }
        case PSA_ECC_FAMILY_BRAINPOOL_P_R1:
        {
            switch (key_bits) {
                case 256:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_brainpoolP256r1;
                    break;
                }
                case 384:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_brainpoolP384r1;
                    break;
                }
                case 512:
                {
                    *ecc_ecdsel = kCAAM_ECDSEL_brainpoolP512r1;
                    break;
                }
                default:
                {
                    return PSA_ERROR_NOT_SUPPORTED;
                }
            }
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }
    *ecp_grou_id = mbedtls_ecc_group_from_psa(family, key_bits);

    return PSA_SUCCESS;
}

int caam_mbedtls_rng(void *userData, unsigned char *output, size_t output_size)
{
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };
    status_t result           = kStatus_Success;

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return MBEDTLS_ERR_ERROR_GENERIC_ERROR;
    }

    result = CAAM_RNG_GetRandomData(PSA_CAAM,
                                    &caam_handle,
                                    kCAAM_RngStateHandle0,
                                    (uint8_t *) output,
                                    output_size,
                                    kCAAM_RngDataAny,
                                    NULL);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return MBEDTLS_ERR_ERROR_GENERIC_ERROR;
    }

    return result;
}
