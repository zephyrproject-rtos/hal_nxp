/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_COMMON_ASYMMETRIC_SIGNATURE_H
#define MCUX_PSA_ELE_HSEB_COMMON_ASYMMETRIC_SIGNATURE_H

/** \file mcux_psa_ele_hseb_common_asymmetric_signature.h
 *
 * This file contains the declaration of internal helper functions shared by
 * the transparent and opaque asymmetric signature drivers. These functions
 * operate on a pre-resolved HSE key handle and contain no key loading or
 * key deletion logic; that is the responsibility of each driver layer.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "psa/crypto.h"
#include "hse_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Perform an ECDSA sign operation using a pre-resolved key handle.
 *
 * \param[in]  key_handle       HSE key handle of the signing key.
 * \param[in]  alg              ECDSA algorithm to use.
 * \param[in]  input            Message or hash to sign.
 * \param[in]  input_length     Length in bytes of \p input.
 * \param[out] signature        Buffer to receive the signature (r || s).
 * \param[in]  signature_size   Size in bytes of \p signature.
 * \param[out] signature_length On success, set to the number of bytes written.
 * \param[in]  is_input_hashed  True if \p input is a precomputed hash.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_common_ecdsa_sign(hseKeyHandle_t key_handle,
                                        psa_algorithm_t alg,
                                        const uint8_t *input,
                                        size_t input_length,
                                        uint8_t *signature,
                                        size_t signature_size,
                                        size_t *signature_length,
                                        bool is_input_hashed);

/**
 * \brief Perform an ECDSA verify operation using a pre-resolved key handle.
 *
 * \param[in] key_handle       HSE key handle of the verification key.
 * \param[in] attributes       Key attributes (used for key size validation).
 * \param[in] alg              ECDSA algorithm to use.
 * \param[in] input            Message or hash to verify.
 * \param[in] input_length     Length in bytes of \p input.
 * \param[in] signature        Signature to verify (r || s).
 * \param[in] signature_length Length in bytes of \p signature.
 * \param[in] is_input_hashed  True if \p input is a precomputed hash.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_common_ecdsa_verify(hseKeyHandle_t key_handle,
                                          const psa_key_attributes_t *attributes,
                                          psa_algorithm_t alg,
                                          const uint8_t *input,
                                          size_t input_length,
                                          const uint8_t *signature,
                                          size_t signature_length,
                                          bool is_input_hashed);

/**
 * \brief Perform an RSA sign operation using a pre-resolved key handle.
 *
 * Supports RSA PKCS#1 v1.5 and RSA-PSS algorithms. RSA PKCS1V15_SIGN_RAW
 * is not supported.
 *
 * \param[in]  key_handle       HSE key handle of the signing key.
 * \param[in]  attributes       Key attributes (used for salt length).
 * \param[in]  alg              RSA signature algorithm to use.
 * \param[in]  input            Message or hash to sign.
 * \param[in]  input_length     Length in bytes of \p input.
 * \param[out] signature        Buffer to receive the signature.
 * \param[in]  signature_size   Size in bytes of \p signature.
 * \param[out] signature_length On success, set to the number of bytes written.
 * \param[in]  is_input_hashed  True if \p input is a precomputed hash.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_common_rsa_sign(hseKeyHandle_t key_handle,
                                      const psa_key_attributes_t *attributes,
                                      psa_algorithm_t alg,
                                      const uint8_t *input,
                                      size_t input_length,
                                      uint8_t *signature,
                                      size_t signature_size,
                                      size_t *signature_length,
                                      bool is_input_hashed);

/**
 * \brief Perform an RSA verify operation using a pre-resolved key handle.
 *
 * Supports RSA PKCS#1 v1.5 and RSA-PSS algorithms. RSA PKCS1V15_SIGN_RAW
 * is not supported.
 *
 * \param[in] key_handle       HSE key handle of the verification key.
 * \param[in] attributes       Key attributes (used for salt length and size
 *                             validation).
 * \param[in] alg              RSA signature algorithm to use.
 * \param[in] input            Message or hash to verify.
 * \param[in] input_length     Length in bytes of \p input.
 * \param[in] signature        Signature to verify.
 * \param[in] signature_length Length in bytes of \p signature.
 * \param[in] is_input_hashed  True if \p input is a precomputed hash.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t ele_hseb_common_rsa_verify(hseKeyHandle_t key_handle,
                                        const psa_key_attributes_t *attributes,
                                        psa_algorithm_t alg,
                                        const uint8_t *input,
                                        size_t input_length,
                                        const uint8_t *signature,
                                        size_t signature_length,
                                        bool is_input_hashed);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_COMMON_ASYMMETRIC_SIGNATURE_H */
