/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_MAC_H
#define MCUX_PSA_ELE_HSEB_MAC_H

/** \file mcux_psa_ele_hseb_mac.h
 *
 * This file contains the declaration of the entry points associated to the
 * mac capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "psa/crypto.h"
#include "ele_hseb_crypto_composites.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Perform a MAC operation in a single step
 *
 * \param[in]  attributes      Attributes for the key
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
psa_status_t ele_hseb_transparent_mac_compute(const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *input,
                                              size_t input_length,
                                              uint8_t *mac,
                                              size_t mac_size,
                                              size_t *mac_length);

/*!
 * \brief Setup a MAC signing operation
 *
 * \param[in,out] operation       MAC operation context
 * \param[in]     attributes      Attributes for the key
 * \param[in]     key_buffer      Buffer holding key material
 * \param[in]     key_buffer_size Size in bytes of the key
 * \param[in]     alg             Algorithm to be used
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_transparent_mac_sign_setup(ele_hseb_transparent_mac_operation_t *operation,
                                                 const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg);

/*!
 * \brief Setup a MAC verification operation
 *
 * \param[in,out] operation       MAC operation context
 * \param[in]     attributes      Attributes for the key
 * \param[in]     key_buffer      Buffer holding key material
 * \param[in]     key_buffer_size Size in bytes of the key
 * \param[in]     alg             Algorithm to be used
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_transparent_mac_verify_setup(ele_hseb_transparent_mac_operation_t *operation,
                                                   const psa_key_attributes_t *attributes,
                                                   const uint8_t *key_buffer,
                                                   size_t key_buffer_size,
                                                   psa_algorithm_t alg);

/*!
 * \brief Add data to a MAC operation
 *
 * \param[in,out] operation    MAC operation context
 * \param[in]     input        Buffer containing input data to add to the MAC
 * \param[in]     input_length Size in bytes of the input buffer
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_transparent_mac_update(ele_hseb_transparent_mac_operation_t *operation,
                                             const uint8_t *input,
                                             size_t input_length);

/*!
 * \brief Finish a MAC signing operation
 *
 * \param[in,out] operation  MAC operation context
 * \param[out]    mac        Buffer holding the produced MAC value
 * \param[in]     mac_size   Size in bytes of the mac buffer
 * \param[out]    mac_length Size in bytes of the produced MAC value
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_transparent_mac_sign_finish(ele_hseb_transparent_mac_operation_t *operation,
                                                  uint8_t *mac,
                                                  size_t mac_size,
                                                  size_t *mac_length);

/*!
 * \brief Finish a MAC verification operation
 *
 * \param[in,out] operation  MAC operation context
 * \param[in]     mac        Buffer holding the MAC value to verify
 * \param[in]     mac_length Size in bytes of the MAC to verify
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_transparent_mac_verify_finish(ele_hseb_transparent_mac_operation_t *operation,
                                                    const uint8_t *mac,
                                                    size_t mac_length);

/*!
 * \brief Abort a MAC operation
 *
 * \param[in,out] operation  MAC operation context
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_transparent_mac_abort(ele_hseb_transparent_mac_operation_t *operation);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_MAC_H */
