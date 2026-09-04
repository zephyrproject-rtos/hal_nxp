/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_CAAM_COMMON_KEY_GENERATION_H
#define MCUX_PSA_CAAM_COMMON_KEY_GENERATION_H

/** \file mcux_psa_caam_common_key_generation.h
 *
 * This file contains the declaration of the entry points associated to the
 * key generation (i.e. random generation and extraction of public keys) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_caam_init.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(PSA_CRYPTO_DRIVER_CAAM)
#if (PSA_CRYPTO_DRIVER_CAAM_OPAQUE == PSA_CRYPTO_DRIVER_CAAM_OPAQUE_ECB)
#define CAAM_OPAQUE_ALIGN               CAAM_BLACKEN_ECB_SIZE
#elif (PSA_CRYPTO_DRIVER_CAAM_OPAQUE == PSA_CRYPTO_DRIVER_CAAM_OPAQUE_CCM)
#define CAAM_OPAQUE_ALIGN               CAAM_BLACKEN_CCM_SIZE
#else
#error Unknown OPAQUE type
#endif
#define RSA_ALIGN_PRIVATE_EXPONENT_SIZE(x) (CAAM_OPAQUE_ALIGN(x))
#define ECC_ALIGN_PRIVATE_KEY_SIZE(x)      (CAAM_OPAQUE_ALIGN(x))
#endif

#define CAAM_ENCAP_DATA_SIZE(x) ((x) + 32u + 16u + 16u) // xbyte blob key + 32 bytes of data + 16bytes of MAC + 16 RNG

/*!
 * \brief Generate a random key
 *
 * \param[in]  caam_key_type     CAAM key encryption type.
 * \param[in]  attributes        Attributes of the key to use
 * \param[out] key_buffer        Buffer to hold the generated key
 * \param[in]  key_buffer_size   Size in bytes of the key_buffer buffer
 * \param[out] key_buffer_length Size in bytes of the generated key
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t caam_common_generate_key(mcux_psa_caam_key_type_t caam_key_type,
                                      const psa_key_attributes_t *attributes,
                                      uint8_t *key_buffer,
                                      size_t key_buffer_size,
                                      size_t *key_buffer_length);

/*!
 * \brief Destroy a random key
 *
 * \param[in]  attributes        Attributes of the key to destroy
 * \param[out] key_buffer        Buffer for the key
 * \param[in]  key_buffer_size   Size in bytes of the key_buffer buffer

 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t caam_common_destroy_key(const psa_key_attributes_t *attributes,
                                     uint8_t *key_buffer,
                                     size_t key_buffer_size);

/*!
 * \brief Export the public key from a private key.
 *
 * \param[in]  attributes      Attributes of the key to use
 * \param[in]  key_buffer      Buffer to hold the generated key
 * \param[in]  key_buffer_size Size in bytes of the key_buffer buffer
 * \param[out] data            Buffer to hold the extracted public key
 * \param[in]  data_size       Size in bytes of the data buffer
 * \param[out] data_length     Size in bytes of the extracted public key
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t caam_common_export_public_key(const psa_key_attributes_t *attributes,
                                           const uint8_t *key_buffer,
                                           size_t key_buffer_size,
                                           uint8_t *data,
                                           size_t data_size,
                                           size_t *data_length);

/*!
 * \brief Return the buffer size required by driver for storing key.
 *
 * \param[in] key_type Type of key
 * \param[in] key_bits Size in bits of the key to be stored
 *
 * \retval  size_t on success. 0 on
 *          failure
 */
size_t caam_common_size_function(psa_key_type_t key_type, size_t key_bits);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_CAAM_COMMON_KEY_GENERATION_H */
