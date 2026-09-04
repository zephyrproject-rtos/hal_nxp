/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_TRANSLATE_H
#define MCUX_PSA_ELE_HSEB_TRANSLATE_H

/** \file mcux_psa_ele_hseb_translate.h
 *
 * This file contains the declaration of the entry points associated
 * with common value translation functions utilized by the ELE HSEB PSA port
 * driver.
 *
 * \note This header should not be included by ele_hseb.h, as it is internal
 *       only.
 */

#include "psa/crypto.h"
#include "hse_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief  Translate ELE_HSEB service status to PSA status
 *
 * \retval PSA_SUCCESS on success. Error code from psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_to_psa_status(hseSrvResponse_t ele_hseb_status);

/**
 * \brief Translate ELE_HSEB hash algorithm to PSA algorithm
 *
 * \param[in]  hseb_hash ELE HSEB hash algorithm to be translated
 * \param[out] alg       Translated PSA alg value
 *
 * \retval PSA_SUCCESS on success or PSA_ERROR_NOT_SUPPORTED in case
 *         no translation can be made
 */
psa_status_t ele_hseb_to_psa_hash(hseHashAlgo_t hseb_hash,
                                  psa_algorithm_t *alg);

/**
 * \brief Translate PSA algorithm to ELE_HSEB hash algorithm
 *
 * \param[in]  alg       PSA alg algorithm to be translated
 * \param[out] hseb_hash Translated ELE HSEB hash algorithm
 *
 * \retval PSA_SUCCESS on success or PSA_ERROR_NOT_SUPPORTED in case
 *         no translation can be made
 */
psa_status_t psa_to_ele_hseb_hash(psa_algorithm_t alg,
                                  hseHashAlgo_t *hseb_hash);

/**
 * \brief Translate PSA MAC algorithm to ELE_HSEB MAC scheme
 *
 * If a truncated MAC algorithm is provided, the truncation flags and length are
 * ignored and the algorithm is translated as if it were a full length MAC.
 *
 * \param[in]  alg             PSA algorithm to be translated
 * \param[out] hseb_mac_scheme Translated ELE HSEB MAC scheme
 *
 * \retval PSA_SUCCESS on success or PSA_ERROR_NOT_SUPPORTED in case
 *         no translation can be made
 */
psa_status_t psa_to_hseb_mac_scheme(psa_algorithm_t alg,
                                    hseMacScheme_t *hseb_mac_scheme);

/**
 * \brief Translate PSA key attributes to an HSE-B ECC curve identifier.
 *
 * Derives the ECC curve from the provided PSA values and maps it to the
 * corresponding \c hseEccCurveId_t value understood by HSE-B.
 *
 * \param[in]  key_type   The key type.
 * \param[in]  ecc_family The ECC family.
 * \param[in]  key_bits   The key bits.
 * \param[out] curve_id   Translated HSE-B ECC curve identifier.
 *
 * \retval PSA_SUCCESS on success or PSA_ERROR_NOT_SUPPORTED if the curve
 *         is not supported by HSE-B.
 */
psa_status_t psa_to_hseb_curve(psa_key_type_t key_type,
                               psa_ecc_family_t ecc_family,
                               size_t key_bits,
                               hseEccCurveId_t *curve_id);

/**
 * \brief Translate PSA key usage flags to HSE-B key flags.
 *
 * Maps one or more \c PSA_KEY_USAGE_* bits to the corresponding
 * \c hseKeyFlags_t permission bits accepted by HSE-B key services.
 * Flags that have no HSE-B equivalent are ignored.
 *
 * \param[in]     key_usage       PSA key usage flags to translate.
 * \param[in,out] hseb_key_flags  HSE-B key flags to which the translated
 *                                permission bits are OR-ed in.
 */
void psa_to_hseb_key_usage(psa_key_usage_t key_usage,
                           hseKeyFlags_t *hseb_key_flags);

/**
 * \brief Translate a PSA cipher algorithm to an HSE-B cipher block mode.
 *
 * Extracts the block-mode component from a PSA symmetric cipher or AEAD
 * algorithm identifier and returns the matching \c hseCipherBlockMode_t
 * value. Returns \c HSE_CIPHER_BLOCK_MODE_NULL for unrecognised algorithms.
 *
 * \param[in] alg PSA algorithm identifier to translate.
 *
 * \retval The corresponding \c hseCipherBlockMode_t value, or
 *         \c HSE_CIPHER_BLOCK_MODE_NULL if the algorithm is not supported.
 */
hseCipherBlockMode_t psa_to_hseb_cipher_mode(psa_algorithm_t alg);

/**
 * \brief Convert an HSE-B cipher block mode to an AES block mode mask.
 *
 * Converts a single \c hseCipherBlockMode_t value to the corresponding
 * single-bit \c hseAesBlockModeMask_t mask used in \c hseKeyInfo_t to
 * express which AES modes a key is permitted to be used with. Returns
 * \c HSE_KU_AES_BLOCK_MODE_ANY if the mode is not recognised.
 *
 * \param[in] hse_cipher_mode HSE-B cipher block mode to convert.
 *
 * \retval The corresponding \c hseAesBlockModeMask_t bit, or
 *         \c HSE_KU_AES_BLOCK_MODE_ANY if the mode is not recognised.
 */
hseAesBlockModeMask_t cipher_mode_to_cipher_mask(hseCipherBlockMode_t hse_cipher_mode);

/**
 * \brief Map a PSA ECDSA algorithm to an HSE sign scheme.
 *
 * The caller must have already verified that \p alg is a non-deterministic
 * ECDSA algorithm before calling this function.
 *
 * \param[in]  alg         PSA ECDSA algorithm.
 * \param[out] sign_scheme HSE sign scheme to populate.
 *
 * \retval PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *         failure.
 */
psa_status_t psa_to_ele_hseb_ecdsa(psa_algorithm_t alg,
                                   hseSignScheme_t *sign_scheme);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_TRANSLATE_H */
