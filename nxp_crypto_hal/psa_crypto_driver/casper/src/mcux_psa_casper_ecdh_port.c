/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/**
 * \file mcux_psa_casper_ecdh_port.c
 *
 * \brief ECDH key agreement using CASPER hardware acceleration.
 *
 *        This is a port of mbedtls_psa_key_agreement_ecdh() from
 *        psa_crypto_ecp.c.  The only functional difference is that the
 *        scalar multiplication is delegated to casper_mbedtls_ecp_mul()
 *        instead of the software mbedtls_ecp_mul().
 */

#define MBEDTLS_DECLARE_PRIVATE_IDENTIFIERS


#include <psa/crypto.h>
#include "psa_crypto_core.h"
#include "psa_crypto_ecp.h"

#include "mbedtls/private_access.h"
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#include "mbedtls/error.h"
#include "mbedtls/psa_util.h"
#include "psa_util_internal.h"

#include "mcux_psa_casper_ecp_port.h"
#include "mcux_psa_casper_ecdh_port.h"

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_ECP_C) && \
    (defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED))

/**
 * \brief  Serialise the X coordinate of \p secret into \p shared_secret.
 *
 *         Weierstrass curves → big-endian (RFC 5480 / SEC 1).
 *         Montgomery curves  → little-endian (RFC 7748).
 */
static psa_status_t casper_ecdh_write_secret(const mbedtls_ecp_group *grp,
                                             const mbedtls_ecp_point *secret,
                                             uint8_t *shared_secret,
                                             size_t shared_secret_size,
                                             size_t *shared_secret_length)
{
    *shared_secret_length = PSA_BITS_TO_BYTES(grp->pbits);
    if (shared_secret_size < *shared_secret_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    return mbedtls_to_psa_error(
        mbedtls_ecp_get_type(grp) == MBEDTLS_ECP_TYPE_MONTGOMERY
            ? mbedtls_mpi_write_binary_le(&secret->MBEDTLS_PRIVATE(X),
                                          shared_secret, *shared_secret_length)
            : mbedtls_mpi_write_binary(&secret->MBEDTLS_PRIVATE(X),
                                       shared_secret, *shared_secret_length));
}

/**
 * \brief  ECDH key agreement accelerated by the CASPER hardware unit.
 *
 *         Drop-in replacement for mbedtls_psa_key_agreement_ecdh().
 *         The scalar multiplication
 *
 *             secret = our_private_key * peer_public_key
 *
 *         is offloaded to casper_mbedtls_ecp_mul() instead of the
 *         software mbedtls_ecp_mul().
 *
 *         Montgomery curves (X25519 / X448) are not supported by CASPER
 *         and will return PSA_ERROR_NOT_SUPPORTED so the PSA core can
 *         fall back to the software driver.
 */
psa_status_t casper_psa_key_agreement_ecdh(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *peer_key, size_t peer_key_length,
    uint8_t *shared_secret, size_t shared_secret_size,
    size_t *shared_secret_length)
{
    psa_status_t status;
    mbedtls_ecp_keypair *our_key   = NULL;
    mbedtls_ecp_keypair *their_key = NULL;
    mbedtls_ecp_point    secret;

    mbedtls_ecp_point_init(&secret);

    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t         key_bits = psa_get_key_bits(attributes);

    /* Basic argument validation */
    if (!PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type) || !PSA_ALG_IS_ECDH(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Load our private key */
    status = mbedtls_psa_ecp_load_representation(key_type, key_bits,
                                                 key_buffer, key_buffer_size,
                                                 &our_key);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Reject curves that CASPER does not accelerate (Montgomery curves) */
    if (mbedtls_ecp_get_type(&our_key->MBEDTLS_PRIVATE(grp)) ==
        MBEDTLS_ECP_TYPE_MONTGOMERY) {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }

    /* Derive PSA curve family + bit-size from the loaded group */
    size_t bits = 0;
    psa_ecc_family_t curve =
        mbedtls_ecc_group_to_psa(our_key->MBEDTLS_PRIVATE(grp).id, &bits);

    /* Load the peer's public key */
    status = mbedtls_psa_ecp_load_representation(
        PSA_KEY_TYPE_ECC_PUBLIC_KEY(curve), bits,
        peer_key, peer_key_length,
        &their_key);
    if (status != PSA_SUCCESS) {
        goto exit;
    }

    /*
     * Scalar multiplication via CASPER:
     *   secret = our_key->d  *  their_key->Q
     *
     * This is the only difference vs the reference mbedtls implementation
     * which calls mbedtls_ecp_mul() here.
     */
    status = mbedtls_to_psa_error(
        casper_mbedtls_ecp_mul(&our_key->MBEDTLS_PRIVATE(grp),
                               &secret,
                               &our_key->MBEDTLS_PRIVATE(d),
                               &their_key->MBEDTLS_PRIVATE(Q),
                               mbedtls_psa_get_random,
                               MBEDTLS_PSA_RANDOM_STATE));
    if (status != PSA_SUCCESS) {
        goto exit;
    }

    /* Serialise the X coordinate of the shared point into the output buffer */
    status = casper_ecdh_write_secret(&our_key->MBEDTLS_PRIVATE(grp), &secret,
                                      shared_secret, shared_secret_size,
                                      shared_secret_length);

exit:
    if (status != PSA_SUCCESS) {
        mbedtls_platform_zeroize(shared_secret, shared_secret_size);
    }
    mbedtls_ecp_point_free(&secret);
    mbedtls_ecp_keypair_free(their_key);
    mbedtls_free(their_key);
    mbedtls_ecp_keypair_free(our_key);
    mbedtls_free(our_key);

    return status;
}

#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ECP_C && (SECP256R1 || SECP384R1 || SECP521R1) */
