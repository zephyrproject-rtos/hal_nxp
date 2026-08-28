/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_PKC_UTILS_H
#define MCUX_PSA_PKC_UTILS_H

/** \file mcux_psa_pkc_utils.h
 *
 * This file contains the declaration of the entry points associated
 * with common utility functions utilized by the PKC PSA port driver.
 *
 *
 */

#include "pkc.h"
#include <mcuxClEcc.h>
#include <mcuxClKey.h>
#include <mcuxClRsa.h>

#include <internal/mcuxClKey_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Map PSA key attributes to PKC private key type
 *
 * Converts PSA ECC curve family and key size to the corresponding
 * PKC private key type identifier.
 *
 * @param[in]  attributes  PSA key attributes
 * @param[out] pkc_alg     PKC private key type
 *
 * @return PSA_SUCCESS on success
 * @return PSA_ERROR_NOT_SUPPORTED if curve is not supported
 */
psa_status_t psa_to_pkc_asym_alg_priv(const psa_key_attributes_t *attributes,
                                      mcuxClKey_Type_t *pkc_alg);

/**
 * @brief Map PSA key attributes to PKC public key type
 *
 * Converts PSA ECC curve family and key size to the corresponding
 * PKC public key type identifier.
 *
 * @param[in]  attributes  PSA key attributes
 * @param[out] pkc_alg     PKC public key type
 *
 * @return PSA_SUCCESS on success
 * @return PSA_ERROR_NOT_SUPPORTED if curve is not supported
 * @return PSA_ERROR_INVALID_ARGUMENT if parameters are NULL
 */
psa_status_t psa_to_pkc_asym_alg_pub(const psa_key_attributes_t *attributes,
                                     mcuxClKey_Type_t *pkc_alg);
/**
 * @brief Get ECC key sizes based on PSA key attributes
 *
 * Retrieves the private and public key sizes in bytes for the
 * specified ECC curve.
 *
 * @param[in]  attributes     PSA key attributes
 * @param[out] priv_key_size  Private key size in bytes
 * @param[out] pub_key_size   Public key size in bytes
 *
 * @return PSA_SUCCESS on success
 * @return PSA_ERROR_NOT_SUPPORTED if curve is not supported
 * @return PSA_ERROR_INVALID_ARGUMENT if parameters are NULL
 */
psa_status_t get_ecc_key_sizes(const psa_key_attributes_t *attributes,
                               size_t *priv_key_size,
                               size_t *pub_key_size);

/**
 * @brief Get the shared secret size based on key attributes
 *
 * @param[in]  attributes  PSA key attributes containing curve family and key bits
 * @param[out] secret_size Pointer to store the shared secret size in bytes
 *
 * @return PSA_SUCCESS on success, PSA_ERROR_NOT_SUPPORTED if curve is not supported
 */
psa_status_t psa_to_pkc_asym_shared_secret_size(const psa_key_attributes_t *attributes,
                                                size_t *secret_size);


#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_PKC_UTILS_H */
