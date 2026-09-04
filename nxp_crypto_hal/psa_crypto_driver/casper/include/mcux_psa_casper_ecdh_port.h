/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/**
 * \file mcux_psa_casper_ecdh_port.h
 *
 * \brief This file contains the declaration of the ECDH key agreement entry
 *        point using CASPER hardware acceleration.
 *
 * The Elliptic Curve Diffie-Hellman (ECDH) key agreement is defined in
 * <em>Standards for Efficient Cryptography Group (SECG):
 * SEC1 Elliptic Curve Cryptography</em>.
 */

#ifndef MCUX_PSA_CASPER_ECDH_PORT_H
#define MCUX_PSA_CASPER_ECDH_PORT_H

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_ECP_C) && \
    (defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED))

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief           Perform an ECDH key agreement using CASPER hardware
 *                  acceleration.
 *
 *                  The scalar multiplication (our private key * peer public key)
 *                  is offloaded to the CASPER accelerator via
 *                  casper_mbedtls_ecp_mul().
 *
 * \param[in]  attributes            Attributes of the private key to use.
 * \param[in]  key_buffer            Buffer containing the private key material.
 * \param[in]  key_buffer_size       Size in bytes of \p key_buffer.
 * \param[in]  alg                   The ECDH algorithm identifier
 *                                   (must satisfy PSA_ALG_IS_ECDH()).
 * \param[in]  peer_key              Buffer containing the peer's public key
 *                                   in PSA export format.
 * \param[in]  peer_key_length       Size in bytes of \p peer_key.
 * \param[out] shared_secret         Buffer to receive the shared secret
 *                                   (the X coordinate of the result point).
 * \param[in]  shared_secret_size    Size in bytes of \p shared_secret.
 * \param[out] shared_secret_length  On success, the number of bytes written
 *                                   to \p shared_secret.
 *
 * \retval #PSA_SUCCESS
 *         Success.
 * \retval #PSA_ERROR_INVALID_ARGUMENT
 *         The key type is not an ECC key pair, or \p alg is not an ECDH
 *         algorithm.
 * \retval #PSA_ERROR_BUFFER_TOO_SMALL
 *         \p shared_secret_size is too small.
 * \retval #PSA_ERROR_NOT_SUPPORTED
 *         The curve is not supported by this driver.
 * \retval #PSA_ERROR_CORRUPTION_DETECTED
 *         An internal error occurred.
 */
psa_status_t casper_psa_key_agreement_ecdh(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *peer_key, size_t peer_key_length,
    uint8_t *shared_secret, size_t shared_secret_size,
    size_t *shared_secret_length);

#ifdef __cplusplus
}
#endif

#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ECP_C && (SECP256R1 || SECP384R1 || SECP521R1) */

#endif /* MCUX_PSA_CASPER_ECDH_PORT_H */
