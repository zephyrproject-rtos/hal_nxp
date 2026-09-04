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

#if defined(PSA_CRYPTO_DRIVER_CAAM)
#include "mcux_psa_caam_common_key_generation.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_RSA_KEYSIZE (4096u / 8u)
#define MAX_ECC_KEYSIZE (576u / 8u)
#define MAX_AES_KEYSIZE (256u / 8u)

#ifndef RSA_ALIGN_PRIVATE_EXPONENT_SIZE
#define RSA_ALIGN_PRIVATE_EXPONENT_SIZE(x) (x)
#endif

#ifndef ECC_ALIGN_PRIVATE_KEY_SIZE
#define ECC_ALIGN_PRIVATE_KEY_SIZE(x) (x)
#endif

#define USE_MALLOC

#ifndef RSA_EXPONENT
#define RSA_EXPONENT 65537u
#endif /* RSA_EXPONENT */

#define ECC_PUBLIC_KEY_SIZE(bytes) ((bytes) * 2u + 1u)

#if defined(USE_MALLOC)
struct mcux_rsa_primes {
    size_t len;
    uint8_t *p;
    uint8_t *q;
};

struct mcux_rsa_keypair {
    size_t modulus_len;
    size_t priv_exp_len;
    uint8_t *modulus;
    uint8_t *priv_exp;
};

struct mcux_ecc_keypair {
    size_t private_key_len;
    size_t public_key_len;
    uint8_t *private_key;
    uint8_t *public_key;
};
#else
struct mcux_rsa_primes {
    size_t len;
    uint8_t p[MAX_RSA_KEYSIZE / 2u];
    uint8_t q[MAX_RSA_KEYSIZE / 2u];
};

struct mcux_rsa_keypair {
    size_t modulus_len;
    size_t priv_exp_len;
    uint8_t modulus[MAX_RSA_KEYSIZE];
    uint8_t priv_exp[RSA_ALIGN_PRIVATE_EXPONENT_SIZE(MAX_RSA_KEYSIZE)];
};

struct mcux_ecc_keypair {
    size_t private_key_len;
    size_t public_key_len;
    uint8_t private_key[ECC_ALIGN_PRIVATE_KEY_SIZE(MAX_ECC_KEYSIZE)];
    uint8_t public_key[ECC_PUBLIC_KEY_SIZE(MAX_ECC_KEYSIZE)];
};
#endif

typedef enum _mcux_key_type {
    MCUX_KEY_TYPE_PUBLIC  = 1,
    MCUX_KEY_TYPE_PRIVATE = 2,
    MCUX_KEY_TYPE_KEYPAIR = 3,
} mcux_key_type_t;

/* In mbedTLS 3.6 they have removed the domain parameter concept so hardcode exponent to 65537 */
extern const uint32_t s_rsa_exponent;

/*!
 * @brief Convert the content of key buffer to struct ecc_priv -> RAW binary format
 *
 * \param[in]  key_type        ECC PSA key type.
 * \param[in]  key_buffer      Key buffer holding the key.
 * \param[in]  key_buffer_size Key buffer size.
 * \param[in]  req_key_type    Requested output key type.
 * \param[in]  ecp_grou_id     ECC curve type.
 * \param[out] ecc_key         Output where the requested key is written.
 *
 * @return psa_status_t
 */
psa_status_t mcux_key_buf_to_raw_ecc(psa_key_type_t key_type,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     mcux_key_type_t req_key_type,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     struct mcux_ecc_keypair *ecc_key);

/*!
 * @brief Convert struct ECC raw binary format to key buffer content
 *
 * For now to keep things simple, we are assuming key buffer is in ASN1 format.
 *
 * \param[in]  key_type          ECC PSA key type.
 * \param[in]  only_public       If true only public key is exported, otherwise both.
 * \param[in]  ecc_key           Structure holding raw ecc keys
 * \param[in]  ecp_grou_id       ECC curve type.
 * \param[out] key_buffer        Output key buffer where formated data are written.
 * \param[in]  key_buffer_size   Size of output key buffer.
 * \param[out] key_buffer_length Size of bytes written into buffer,
 *
 * @return psa_status_t
 */
psa_status_t mcux_raw_ecc_to_key_buf(psa_key_type_t key_type,
                                     bool only_public,
                                     struct mcux_ecc_keypair *ecc_key,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length);

/*!
 * @brief This function initialize structure hodling raw ecc keys.
 *
 * \param[out] ecc_key   Structure to hold ecc raw keys.
 * \param[in]  key_bytes Ecc key byte size.
 * \param[in]  key_type  Define which key initialize.
 * \param[in]  useAlign  Defines if keys lengths should count with extra space.
 *
 * @return psa_status_t
 */
psa_status_t mcux_alloc_raw_ecc(struct mcux_ecc_keypair *ecc_key,
                                size_t key_bytes,
                                mcux_key_type_t key_type,
                                bool useAlign);

/*!
 * @brief This function free structure holding ecc keys.
 *
 * \param[in] ecc_key Structure holding ecc keys.
 *
 * @return psa_status_t
 */
psa_status_t mcux_free_raw_ecc(struct mcux_ecc_keypair *ecc_key);

/*!
 * @brief Convert the content of key buffer to struct rsa_priv -> RAW binary format
 *
 * \param[in] key_type        RSA PSA key type.
 * \param[in] key_buffer      Key buffer holding the key.
 * \param[in] key_buffer_size Key buffer size.
 * \param[in] key_bytes       Size of rsa key in bytes.
 * \param[in] is_public       If true, only public key is written, otherwise both.
 * \param[out] rsa_key        Structure for rsa raw keys.
 * \param[out] rsa_exp        Buffer for rsa exponent
 *
 * @return psa_status_t
 */
psa_status_t mcux_key_buf_to_raw_rsa(psa_key_type_t key_type,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     uint32_t key_bytes,
                                     bool is_public,
                                     struct mcux_rsa_keypair *rsa_key,
                                     uint8_t rsa_exp[4]);

/*!
 * @brief Convert struct RSA raw binary format to key buffer content
 *
 * For now to keep things simple, we are assuming key buffer is in ASN1 format.
 *
 * \param[in] key_type           RSA PSA key type.
 * \param[in] only_public        If true only public key is exported, otherwise both.
 * \param[in] rsa_key            Structure holding raw rsa keys
 * \param[out] key_buffer        Output key buffer where formatted data are written.
 * \param[in] key_buffer_size    Size of output key buffer.
 * \param[out] key_buffer_length Size of bytes written into buffer,
 *
 * @return psa_status_t
 */
psa_status_t mcux_raw_rsa_to_key_buf(psa_key_type_t key_type,
                                     bool only_public,
                                     const struct mcux_rsa_keypair *rsa_key,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length);

/*!
 * @brief This function initialize structure hodling raw rsa keys.
 *
 * \param[out] rsa_key   Structure to hold rsa raw keys.
 * \param[in]  key_bytes Rsa key byte size.
 * \param[in]  key_type  Define which key initialize.
 * \param[in]  useAlign  Defines if keys lengths should count with extra space.
 *
 * @return psa_status_t
 */
psa_status_t mcux_alloc_raw_rsa(struct mcux_rsa_keypair *rsa_key,
                                size_t key_bytes,
                                mcux_key_type_t key_type,
                                bool useAlign);

/*!
 * @brief This function free structure holding rsa keys.
 *
 * \param[in] rsa_key Structure holding rsa keys.
 *
 * @return psa_status_t
 */
psa_status_t mcux_free_raw_rsa(struct mcux_rsa_keypair *rsa_key);

/*!
 * @brief Function to generate rsa prime numbers.
 *
 * \param[in]  bit_size Rsa key bit size.
 * \param[out] primes   structure holding rsa prime numbers.
 *
 * @return psa_status_t
 */
psa_status_t mcux_rsa_generate_primes(size_t bit_size, struct mcux_rsa_primes *primes);

/*!
 * @brief Free structure holding rsa prime numbers
 *
 * \param[in] primes Structure holding prime numbers.
 *
 * @return psa_status_t
 */
psa_status_t mcux_rsa_free_primes(struct mcux_rsa_primes *primes);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_COMMON_KEY_MANAGEMENT_H */
