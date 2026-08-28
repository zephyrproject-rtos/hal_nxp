/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_KEY_MANAGEMENT_H
#define MCUX_PSA_ELE_HSEB_KEY_MANAGEMENT_H

/** \file mcux_psa_ele_hseb_key_management.h
 *
 * This file contains the declaration of the entry points associated to the
 * key management capability as described by the PSA
 * Cryptoprocessor Driver interface specification and to internal key managent
 * functions.
 *
 */

#include "psa/crypto.h"
#include "hse_interface.h"
#include "hse_host_import_key.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Wrapper for key deletion from HSEB and from the mirrorred key slot
 *
 * ELE HSEB keeps a software-based metadata mirror of the internal key store
 * usage. The internal keystore and the mirror are managed via two separate
 * API calls. This wrapper unites these two operations.
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *         failure
 */
psa_status_t ele_hseb_delete_key(hseKeyHandle_t *keyHandle,
                                 hseEraseKeyOptions_t eraseKeyOptions);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_KEY_MANAGEMENT_H */
