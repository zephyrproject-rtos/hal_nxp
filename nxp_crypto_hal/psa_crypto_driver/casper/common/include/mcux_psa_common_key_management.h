/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_COMMON_KEY_MANAGEMENT_H
#define MCUX_PSA_COMMON_KEY_MANAGEMENT_H

/** \file mcux_psa_common_key_management.h
 *
 * This file contains the declaration of the entry points associated to the
 * key generation (i.e. random generation and extraction of public keys) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "psa/crypto.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ECC_KEYSIZE (576 / 8)
#define MAX_AES_KEYSIZE (256 / 8)

#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE)
#define MAX_KEYSIZE MAX_ECC_KEYSIZE
#endif

#define USE_MALLOC

#define ECC_PUBLIC_KEY_SIZE(bytes) (bytes * 2 + 1)

#if defined(USE_MALLOC)
struct ecc_keypair
{
    size_t private_key_len;
    size_t public_key_len;
    uint8_t *private_key;
    uint8_t *public_key;
};
#else
struct ecc_keypair
{
    size_t private_key_len;
    size_t public_key_len;
    uint8_t private_key[MAX_ECC_KEYSIZE];
    uint8_t public_key[ECC_PUBLIC_KEY_SIZE(MAX_ECC_KEYSIZE)];
};
#endif

typedef enum _mcux_key_type
{
    MCUX_KEY_TYPE_PUBLIC  = 1,
    MCUX_KEY_TYPE_PRIVATE = 2,
    MCUX_KEY_TYPE_KEYPAIR = 3,
} mcux_key_type_t;

psa_status_t psa_to_ecc_group_id(psa_key_type_t key_type, psa_algorithm_t key_algo, mbedtls_ecp_group_id *ecp_grou_id);

/* Convert the content of key buffer to struct ecc_priv -> RAW binary format */
psa_status_t mcux_key_buf_to_raw_ecc(psa_key_type_t key_type,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     mcux_key_type_t is_public,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     struct ecc_keypair *ecc_key);

/* Convert struct ECC raw binary format to key buffer content
 *  For now to keep things simple, we are assuming key buffer is in ASN1 format.
 */
psa_status_t mcux_raw_ecc_to_key_buf(psa_key_type_t key_type,
                                     bool only_public,
                                     struct ecc_keypair *ecc_key,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length);

psa_status_t mcux_alloc_raw_ecc(struct ecc_keypair *ecc_key, size_t key_bytes, mcux_key_type_t key_type);
psa_status_t mcux_free_raw_ecc(struct ecc_keypair *ecc_key);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_COMMON_KEY_MANAGEMENT_H */
