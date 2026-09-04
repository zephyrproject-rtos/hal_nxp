/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_OPAQUE_ASYMMETRIC_SIGNATURE_H
#define MCUX_PSA_ELE_HSEB_OPAQUE_ASYMMETRIC_SIGNATURE_H

/** \file mcux_psa_ele_hseb_opaque_asymmetric_signature.h
 *
 * This file contains the declaration of the entry points associated to the
 * asymmetric signature capability for opaque keys as described by the PSA
 * Cryptoprocessor Driver interface specification.
 */

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Sign a message using an opaque key resident in the HSE-B keystore.
 *
 * \param[in]  attributes       Attributes of the key to use.
 * \param[in]  key_buffer       Buffer holding the opaque key handle.
 * \param[in]  key_buffer_size  Size in bytes of \p key_buffer.
 * \param[in]  alg              Signature algorithm to use.
 * \param[in]  input            Message to sign.
 * \param[in]  input_length     Size in bytes of \p input.
 * \param[out] signature        Buffer to receive the signature.
 * \param[in]  signature_size   Size in bytes of \p signature.
 * \param[out] signature_length On success, set to the number of bytes written
 *                              into \p signature.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_sign_message(const psa_key_attributes_t *attributes,
                                          const uint8_t *key_buffer,
                                          size_t key_buffer_size,
                                          psa_algorithm_t alg,
                                          const uint8_t *input,
                                          size_t input_length,
                                          uint8_t *signature,
                                          size_t signature_size,
                                          size_t *signature_length);

/*!
 * \brief Verify a message signature using an opaque key resident in the
 *        HSE-B keystore.
 *
 * \param[in] attributes       Attributes of the key to use.
 * \param[in] key_buffer       Buffer holding the opaque key handle.
 * \param[in] key_buffer_size  Size in bytes of \p key_buffer.
 * \param[in] alg              Signature algorithm to use.
 * \param[in] input            Message whose signature is to be verified.
 * \param[in] input_length     Size in bytes of \p input.
 * \param[in] signature        Signature to verify.
 * \param[in] signature_length Size in bytes of \p signature.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_verify_message(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *input,
                                            size_t input_length,
                                            const uint8_t *signature,
                                            size_t signature_length);

/*!
 * \brief Sign a precomputed hash using an opaque key resident in the
 *        HSE-B keystore.
 *
 * \param[in]  attributes       Attributes of the key to use.
 * \param[in]  key_buffer       Buffer holding the opaque key handle.
 * \param[in]  key_buffer_size  Size in bytes of \p key_buffer.
 * \param[in]  alg              Signature algorithm to use.
 * \param[in]  hash             Precomputed hash to sign.
 * \param[in]  hash_length      Size in bytes of \p hash.
 * \param[out] signature        Buffer to receive the signature.
 * \param[in]  signature_size   Size in bytes of \p signature.
 * \param[out] signature_length On success, set to the number of bytes written
 *                              into \p signature.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_sign_hash(const psa_key_attributes_t *attributes,
                                       const uint8_t *key_buffer,
                                       size_t key_buffer_size,
                                       psa_algorithm_t alg,
                                       const uint8_t *hash,
                                       size_t hash_length,
                                       uint8_t *signature,
                                       size_t signature_size,
                                       size_t *signature_length);

/*!
 * \brief Verify a signature on a precomputed hash using an opaque key
 *        resident in the HSE-B keystore.
 *
 * \param[in] attributes       Attributes of the key to use.
 * \param[in] key_buffer       Buffer holding the opaque key handle.
 * \param[in] key_buffer_size  Size in bytes of \p key_buffer.
 * \param[in] alg              Signature algorithm to use.
 * \param[in] hash             Precomputed hash whose signature is verified.
 * \param[in] hash_length      Size in bytes of \p hash.
 * \param[in] signature        Signature to verify.
 * \param[in] signature_length Size in bytes of \p signature.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_opaque_verify_hash(const psa_key_attributes_t *attributes,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         psa_algorithm_t alg,
                                         const uint8_t *hash,
                                         size_t hash_length,
                                         const uint8_t *signature,
                                         size_t signature_length);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_OPAQUE_ASYMMETRIC_SIGNATURE_H */
