/*
 * Copyright 2023 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_S4XX_KEY_AGREEMENT_H
#define MCUX_PSA_S4XX_KEY_AGREEMENT_H

/** \file ele_psa_key_agreement.h
 *
 * This file contains the declaration of the entry points associated to the
 * key agreement (i.e. key agreement via ECDH) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  Perform a key agreement and return the raw shared secret, using
    ELE key agreement functions.
 *
 *
 * \param[in]  attributes           The attributes of the key to use for the
 *                                  operation.
 * \param[in]  key_buffer           The buffer containing the private key
 *                                  context.
 * \param[in]  key_buffer_size      Size of the \p key_buffer buffer in
 *                                  bytes.
 * \param[in]  alg                  A key agreement algorithm that is
 *                                  compatible with the type of the key.
 * \param[in]  peer_key             The buffer containing the key context
 *                                  of the peer's public key.
 * \param[in]  peer_key_size        Size of the \p peer_key buffer in
 *                                  bytes.
 * \param[out] shared_secret        The buffer to which the shared secret
 *                                  is to be written.
 * \param[in]  shared_secret_size   Size of the \p shared_secret buffer in
 *                                  bytes.
 * \param[out] shared_secret_length On success, the number of bytes that make
 *                                  up the returned shared secret.
 * \retval #PSA_SUCCESS
 *         Success. Shared secret successfully calculated.
 * \retval #PSA_ERROR_INVALID_HANDLE \emptydescription
 * \retval #PSA_ERROR_NOT_PERMITTED \emptydescription
 * \retval #PSA_ERROR_INVALID_ARGUMENT
 *         \p alg is not a key agreement algorithm, or
 *         \p private_key is not compatible with \p alg,
 *         or \p peer_key is not valid for \p alg or not compatible with
 *         \p private_key.
 * \retval #PSA_ERROR_BUFFER_TOO_SMALL
 *         \p shared_secret_size is too small
 * \retval #PSA_ERROR_NOT_SUPPORTED
 *         \p alg is not a supported key agreement algorithm.
 * \retval #PSA_ERROR_INSUFFICIENT_MEMORY \emptydescription
 * \retval #PSA_ERROR_COMMUNICATION_FAILURE \emptydescription
 * \retval #PSA_ERROR_HARDWARE_FAILURE \emptydescription
 * \retval #PSA_ERROR_CORRUPTION_DETECTED \emptydescription
 * \retval #PSA_ERROR_STORAGE_FAILURE \emptydescription
 * \retval #PSA_ERROR_BAD_STATE \emptydescription
 */
psa_status_t ele_s4xx_transparent_key_agreement(const psa_key_attributes_t *attributes,
        										const uint8_t *key_buffer,
												size_t key_buffer_size,
												psa_algorithm_t alg,
												const uint8_t *peer_key,
												size_t peer_key_size,
												uint8_t *shared_secret,
												size_t shared_secret_size,
												size_t *shared_secret_length);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_S4XX_KEY_AGREEMENT_H */
