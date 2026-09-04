/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#define MBEDTLS_DECLARE_PRIVATE_IDENTIFIERS
   
#include "psa/crypto.h"
#include "psa_crypto_ecp.h"

#include "mbedtls/asn1write.h"
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
#include "mcux_psa_util_wrapcheck_static_inline.h"
#include <string.h>

/* Forward declarations for PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY-gated functions.
 * mbedtls_ecp_group_id is available from mbedtls/ecp.h above. */
psa_ecc_family_t mbedtls_ecc_group_to_psa(mbedtls_ecp_group_id grpid, size_t *bits);

#include "mcux_psa_common_key_management.h"

psa_status_t psa_to_ecc_group_id(psa_key_type_t key_type, psa_algorithm_t key_algo, mbedtls_ecp_group_id *ecp_grou_id)
{
    psa_status_t status = PSA_SUCCESS;
    uint32_t family     = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
    uint32_t algo       = PSA_ALG_GET_HASH(key_algo);

    switch (family)
    {
        case PSA_ECC_FAMILY_SECP_K1:
        {
            switch (algo)
            {
                case PSA_ALG_SHA_256:
                {
                    *ecp_grou_id = MBEDTLS_ECP_DP_SECP256K1;
                    break;
                }
                default:
                {
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
                }
            }
            break;
        }
        case PSA_ECC_FAMILY_BRAINPOOL_P_R1:
        {
            switch (algo)
            {
                case PSA_ALG_SHA_256:
                {
                    *ecp_grou_id = MBEDTLS_ECP_DP_BP256R1;
                    break;
                }
                case PSA_ALG_SHA_384:
                {
                    *ecp_grou_id = MBEDTLS_ECP_DP_BP384R1;
                    break;
                }
                case PSA_ALG_SHA_512:
                {
                    *ecp_grou_id = MBEDTLS_ECP_DP_BP512R1;
                    break;
                }
                default:
                {
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
                }
            }
            break;
        }
        default:
        {
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
        }
    }

    return status;
}

// Functions
psa_status_t mcux_key_buf_to_raw_ecc(psa_key_type_t key_type,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     mcux_key_type_t req_key_type,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     struct ecc_keypair *ecc_key)
{
    psa_status_t status;
    mbedtls_ecdsa_context *ecc;
    int ret;
    size_t olen;
    size_t key_bits;

    (void)mbedtls_ecc_group_to_psa(ecp_grou_id, &key_bits);

    /* Parse input - We will use mbedtls_ecdsa_context to parse the context into */
    status = mbedtls_psa_ecp_load_representation(key_type, key_bits, key_buffer, key_buffer_size, &ecc);
    if (status != PSA_SUCCESS)
    {
        return status;
    }

    if (status == PSA_SUCCESS)
    {
        /* Alocate MPI structure for public key */
        status = mcux_alloc_raw_ecc(ecc_key, PSA_BITS_TO_BYTES(key_bits), req_key_type);
    }

    if ((req_key_type == MCUX_KEY_TYPE_KEYPAIR) || (req_key_type == MCUX_KEY_TYPE_PUBLIC))
    {
        /* Check whether the public part is loaded. If not, load it. */
        if (mbedtls_ecp_is_zero(&ecc->MBEDTLS_PRIVATE(Q)))
        {
            ret = mbedtls_ecp_mul(&ecc->MBEDTLS_PRIVATE(grp), &ecc->MBEDTLS_PRIVATE(Q), &ecc->MBEDTLS_PRIVATE(d),
                                  &ecc->MBEDTLS_PRIVATE(grp).G, mbedtls_psa_get_random, MBEDTLS_PSA_RANDOM_STATE);
            if (ret < 0)
            {
                status = PSA_ERROR_BAD_STATE;
            }
        }

        if (status == PSA_SUCCESS)
        {
            /* Read modulus data from MPI ctx structure */
            ret = mbedtls_ecp_point_write_binary(&ecc->MBEDTLS_PRIVATE(grp), &ecc->MBEDTLS_PRIVATE(Q),
                                                 MBEDTLS_ECP_PF_UNCOMPRESSED, &olen,
                                                 (unsigned char *)ecc_key->public_key, ecc_key->public_key_len);
            if (ret < 0)
            {
                status = PSA_ERROR_BAD_STATE;
            }
        }
    }

    if (status == PSA_SUCCESS)
    {
        if ((req_key_type == MCUX_KEY_TYPE_KEYPAIR) || (req_key_type == MCUX_KEY_TYPE_PRIVATE))
        {
            /* Read private exponent data from MPI ctx structure */
            ret = mbedtls_mpi_write_binary(&ecc->MBEDTLS_PRIVATE(d), (unsigned char *)ecc_key->private_key,
                                           ecc_key->private_key_len);
            if (ret < 0)
            {
                status = PSA_ERROR_BAD_STATE;
            }
        }
    }

    if (status != PSA_SUCCESS)
    {
        mcux_free_raw_ecc(ecc_key);
    }
    mbedtls_ecdsa_free(ecc);
    mbedtls_free(ecc);

    return status;
}

psa_status_t mcux_raw_ecc_to_key_buf(psa_key_type_t key_type,
                                     bool only_public,
                                     struct ecc_keypair *ecc_key,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length)
{
    mbedtls_ecdsa_context ecc;
    psa_status_t status = PSA_SUCCESS;
    int ret;

    mbedtls_ecdsa_init(&ecc);

    mbedtls_ecp_group_init(&ecc.MBEDTLS_PRIVATE(grp));

    ret = mbedtls_ecp_group_load(&ecc.MBEDTLS_PRIVATE(grp), ecp_grou_id);

    if (ret == 0)
    {
        mbedtls_ecp_point_init(&ecc.MBEDTLS_PRIVATE(Q));

        ret = mbedtls_ecp_point_read_binary(&ecc.MBEDTLS_PRIVATE(grp), &ecc.MBEDTLS_PRIVATE(Q), ecc_key->public_key,
                                            ecc_key->public_key_len);
    }
    /* ADD ECC curve */

    if (ret == 0)
    {
        if (only_public)
        {
            key_type = PSA_KEY_TYPE_CATEGORY_PUBLIC_KEY;
        }
        else
        {
            mbedtls_mpi_init(&ecc.MBEDTLS_PRIVATE(d));

            /* Read private exponent in MPI */
            ret = mbedtls_mpi_read_binary(&ecc.MBEDTLS_PRIVATE(d), (const unsigned char *)ecc_key->private_key,
                                          ecc_key->private_key_len);
        }
    }

    if (ret < 0)
    {
        status = PSA_ERROR_BAD_STATE;
    }

    if (status == PSA_SUCCESS)
    {
        status = mbedtls_psa_ecp_export_key(key_type, &ecc, (uint8_t *)key_buffer, key_buffer_size, key_buffer_length);
    }

    mbedtls_ecdsa_free(&ecc);

    return status;
}

psa_status_t mcux_alloc_raw_ecc(struct ecc_keypair *ecc_key, size_t key_bytes, mcux_key_type_t key_type)
{
    psa_status_t err = PSA_SUCCESS;

#if defined(USE_MALLOC)
    ecc_key->private_key = NULL;
    ecc_key->public_key  = NULL;
#endif
    ecc_key->private_key_len = 0;
    ecc_key->public_key_len  = 0;

    if ((key_type == MCUX_KEY_TYPE_PRIVATE) || (key_type == MCUX_KEY_TYPE_KEYPAIR))
    {
#if defined(USE_MALLOC)
        ecc_key->private_key = malloc(key_bytes);
        if (ecc_key->private_key == NULL)
        {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#else
        if (key_bytes > sizeof(ecc_key->private_key))
        {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#endif
        ecc_key->private_key_len = key_bytes;
    }

    if ((key_type == MCUX_KEY_TYPE_PUBLIC) || (key_type == MCUX_KEY_TYPE_KEYPAIR))
    {
        if (key_bytes > MAX_ECC_KEYSIZE)
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
        if (mcux_psa_mul_size_t_wrapcheck(key_bytes, 2U) ||
            mcux_psa_add_size_t_wrapcheck(key_bytes * 2U, 1U))
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
#if defined(USE_MALLOC)
        /* Alocate MPI structure for Private exponent */
        ecc_key->public_key = malloc(ECC_PUBLIC_KEY_SIZE(key_bytes));
        if (ecc_key->public_key == NULL)
        {
            if (ecc_key->private_key_len > 0)
            {
                free(ecc_key->private_key);
            }
            err = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#else
        if (ECC_PUBLIC_KEY_SIZE(key_bytes) > sizeof(ecc_key->public_key))
        {
            err = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#endif
        if (err == PSA_SUCCESS)
        {
            ecc_key->public_key_len = ECC_PUBLIC_KEY_SIZE(key_bytes);
        }
        else
        {
            ecc_key->private_key_len = 0;
        }
    }

    return err;
}

psa_status_t mcux_free_raw_ecc(struct ecc_keypair *ecc_key)
{
#if defined(USE_MALLOC)
    if (ecc_key->private_key_len && ecc_key->private_key)
    {
        free(ecc_key->private_key);
    }

    if (ecc_key->public_key_len && ecc_key->public_key)
    {
        free(ecc_key->public_key);
    }
#endif

    memset(ecc_key, 0, sizeof(*ecc_key));

    return PSA_SUCCESS;
}

/** @} */ // end of psa_key_generation
