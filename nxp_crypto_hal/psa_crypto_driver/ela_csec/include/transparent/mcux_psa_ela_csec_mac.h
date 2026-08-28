/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELA_CSEC_MAC_H
#define MCUX_PSA_ELA_CSEC_MAC_H

/** \file mcux_psa_ela_csec_mac.h
 *
 * This file contains the declaration of the entry points associated to the
 * mac capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Perform a MAC operation in a single step
 *
 * \param[in]  attributes      Attributes for the key to be set
 * \param[in]  key_buffer      Buffer holding key material
 * \param[in]  key_buffer_size Size in bytes of the key
 * \param[in]  alg             Algorithm to be used
 * \param[in]  input           Buffer containing input data to produce the MAC
 * \param[in]  input_length    Size in bytes of the input buffer
 * \param[out] mac             Buffer holding the produced MAC value
 * \param[in]  mac_size        Size in bytes of the mac buffer
 * \param[out] mac_length      Size in bytes of the produced MAC value
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t ela_csec_transparent_mac_compute(const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *input,
                                              size_t input_length,
                                              uint8_t *mac,
                                              size_t mac_size,
                                              size_t *mac_length);


#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_ELA_CSEC_MAC_H */
