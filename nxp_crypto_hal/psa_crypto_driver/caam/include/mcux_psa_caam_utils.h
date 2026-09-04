/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_CAAM_UTILS_H
#define MCUX_PSA_CAAM_UTILS_H

/** \file mcux_psa_caam_utils.h
 *
 * This file contains the declaration of the functions used as utilities
 * to solve minor part of application inside more files.
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_caam_init.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief This function encapsulate key.
 *
 * \param[in]  caam_key_type     CAAM key encryption type.
 * \param[in]  key               Private key to encapsulate
 * \param[in]  key_length        Private key length to encapuslate
 * \param[out] key_buffer        Output buffer for encapsulated key
 * \param[in]  key_buffer_size   Output buffer size
 * \param[out] key_buffer_length Size of output written to the buffer
 *
 * @return psa_status_t
 */
psa_status_t caam_opaque_encapsulate_key(mcux_psa_caam_key_type_t caam_key_type,
                                         const uint8_t *key,
                                         size_t key_length,
                                         uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         size_t *key_buffer_length);

/**
 * @brief This function decapsulate private key.
 *
 * \param[in]  caam_key_type     CAAM key encryption type.
 * \param[in]  key_buffer        Buffer holding encapsulated key.
 * \param[in]  key_buffer_size   Buffer size.
 * \param[out] key               Output buffer for decapsulated key.
 * \param[in] key_size           Expected key size.
 *
 * @return psa_status_t
 */
psa_status_t caam_opaque_decapsulate_key(mcux_psa_caam_key_type_t caam_key_type,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         uint8_t *key,
                                         size_t key_size);

/**
 * @brief This function identifies ecc type based on PSA key values.
 *
 * \param[in]  key_type    PSA key type
 * \param[in]  key_bits    Bit size for key
 * \param[out] ecc_ecdsel  Caam ecc curve type
 * \param[out] ecp_grou_id Mbedtls curve type
 *
 * @return psa_status_t
 */
psa_status_t psa_to_caam_ecc_key_algo(psa_key_type_t key_type,
                                      size_t key_bits,
                                      caam_ecc_ecdsel_t *ecc_ecdsel,
                                      mbedtls_ecp_group_id *ecp_grou_id);

/**
 * @brief This function can be used in mbedtls api to generate random numbers.
 *
 * \param[in]      userData  User data for rng function
 * \param[out]     output    Generated output.
 * \param[in]      size      Amount of requested random numbers.
 * @return int
 */
int caam_mbedtls_rng(void *userData, unsigned char *output, size_t output_size);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_CAAM_UTILS_H */
