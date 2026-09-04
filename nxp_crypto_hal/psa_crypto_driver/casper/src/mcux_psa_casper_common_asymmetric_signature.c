/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_casper_common_asymmetric_signature.c
 *
 * This file contains the implementation of the entry points associated to the
 * ecc signature capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#define MBEDTLS_DECLARE_PRIVATE_IDENTIFIERS

#include "mcux_psa_casper_ecdsa_port.h"
#include "mcux_psa_casper_ecp_port.h"
#include "mcux_psa_casper_common_asymmetric_signature.h"
#include "mcux_psa_common_key_management.h"
#include "mcux_psa_casper_init.h"

#include <psa/crypto.h>
#include "psa_crypto_core.h"
#include "psa_crypto_ecp.h"
#include "mbedtls/psa_util.h"

#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#include "mbedtls/error.h"

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "mbedtls/private/crypto_builtin_composites.h"
#else
/* This is for backwards compatibility with MbedTLS 3.x */
#include "psa/crypto_builtin_composites.h"
#endif /* (MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

/** \defgroup psa_asym_sign PSA driver entry points for rsa sign/verify
 *
 *  Entry points for rsa message signing and signature verification as
 *  described by the PSA Cryptoprocessor Driver interface specification
 *
 *  @{
 */

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
static psa_status_t casper_common_internal_ecc_sign(const psa_key_attributes_t *attributes,
                                                    const uint8_t *key,
                                                    size_t key_length,
                                                    psa_algorithm_t alg,
                                                    const uint8_t *input,
                                                    size_t input_length,
                                                    uint8_t *signature,
                                                    size_t signature_size,
                                                    size_t *signature_length)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    int sign_status          = 0;
    int write_status         = 0;
    mbedtls_ecp_keypair *ecp = NULL;
    psa_key_type_t key_type  = psa_get_key_type(attributes);
    size_t key_bits          = psa_get_key_bits(attributes);
    mbedtls_mpi r, s;

    status = mbedtls_psa_ecp_load_representation(key_type, key_bits, key, key_length, &ecp);
    if (status != PSA_SUCCESS) {
        return status;
    }

    size_t key_bytes = PSA_BITS_TO_BYTES(key_bits);
    mbedtls_mpi_init(&r);
    mbedtls_mpi_init(&s);

    /* In case that input buffer size is larger than algorithm size 
     * (e.g. SHA512 (64B) vs P384 (48B)), leftmost bits truncation
     * happens in derive_mpi() function later
     */

    if ((status == PSA_SUCCESS) && (signature_size < 2u * key_bytes)) {
        status = PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Lock mutex */
    if ((status == PSA_SUCCESS) && (mcux_mutex_lock(&casper_hwcrypto_mutex) != 0)) {
        status = PSA_ERROR_SERVICE_FAILURE;
    }

    /* Sign hash */
    if (status == PSA_SUCCESS) {
        if (PSA_ALG_IS_RANDOMIZED_ECDSA(alg)) {
            sign_status = casper_mbedtls_ecdsa_sign(&ecp->MBEDTLS_PRIVATE(grp),
                                                    &r,
                                                    &s,
                                                    &ecp->MBEDTLS_PRIVATE(d),
                                                    input,
                                                    input_length,
                                                    mbedtls_psa_get_random,
                                                    MBEDTLS_PSA_RANDOM_STATE);
        } else if (PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            psa_algorithm_t hash_alg = PSA_ALG_SIGN_GET_HASH(alg);
            mbedtls_md_type_t md_alg = mbedtls_md_type_from_psa_alg(hash_alg);
            sign_status              = casper_mbedtls_ecdsa_sign_det_ext(&ecp->MBEDTLS_PRIVATE(grp),
                                                                         &r,
                                                                         &s,
                                                                         &ecp->MBEDTLS_PRIVATE(d),
                                                                         input,
                                                                         input_length,
                                                                         md_alg,
                                                                         mbedtls_psa_get_random,
                                                                         MBEDTLS_PSA_RANDOM_STATE);
        } else {
            sign_status = MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
        }
    }

    /* Unlock mutex */
    if ((status == PSA_SUCCESS) && (mcux_mutex_unlock(&casper_hwcrypto_mutex) != 0)) {
        status = PSA_ERROR_SERVICE_FAILURE;
    }

    /* Check verification status */
    if ((status == PSA_SUCCESS) && (sign_status != 0)) {
        // casper sign failed
        status = mbedtls_to_psa_error(sign_status);
    }

    /* Write R and S */
    if ((status == PSA_SUCCESS) && (sign_status == 0)) {
        // casper sign succeded
        write_status = mbedtls_mpi_write_binary(&r, signature, key_bytes);

        if (write_status == 0) {
            write_status = mbedtls_mpi_write_binary(&s, signature + key_bytes, key_bytes);
        }

        status = mbedtls_to_psa_error(write_status);
    }

    if (status == PSA_SUCCESS) {
        *signature_length = 2u * key_bytes;
    }

    // cleanup
    mbedtls_mpi_free(&r);
    mbedtls_mpi_free(&s);
    if (ecp != NULL) {
        mbedtls_ecp_keypair_free(ecp);
        mbedtls_free(ecp);
    }

    return status;
}
#endif /* defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY) */

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
static psa_status_t casper_common_internal_ecc_verify(const psa_key_attributes_t *attributes,
                                                      const uint8_t *key,
                                                      size_t key_length,
                                                      psa_algorithm_t alg,
                                                      const uint8_t *input,
                                                      size_t input_length,
                                                      const uint8_t *signature,
                                                      size_t signature_length)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    int verify_status        = 0;
    int read_status          = 0;
    mbedtls_ecp_keypair *ecp = NULL;
    psa_key_type_t key_type  = psa_get_key_type(attributes);
    size_t key_bits          = psa_get_key_bits(attributes);
    mbedtls_mpi r, s;

    status = mbedtls_psa_ecp_load_representation(key_type, key_bits, key, key_length, &ecp);
    if (status != PSA_SUCCESS) {
        return status;
    }

    size_t key_bytes = PSA_BITS_TO_BYTES(key_bits);
    mbedtls_mpi_init(&r);
    mbedtls_mpi_init(&s);

    /* Check for input buffer size in case it is hash it should match the algorithm size */
    if ((status == PSA_SUCCESS) && (input_length > key_bytes)) {
        status = PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((status == PSA_SUCCESS) && (signature_length < 2u * key_bytes)) {
        status = PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Read R and S */
    if (status == PSA_SUCCESS) {
        read_status = mbedtls_mpi_read_binary(&r, signature, key_bytes);

        if (read_status == 0) {
            (void)mbedtls_mpi_read_binary(&s, signature + key_bytes, key_bytes);
        }
    }

    /* Lock mutex */
    if ((status == PSA_SUCCESS) && (mcux_mutex_lock(&casper_hwcrypto_mutex) != 0)) {
        status = PSA_ERROR_SERVICE_FAILURE;
    }

    /* Verify signature */
    if (status == PSA_SUCCESS) {
        /* Check whether the public part is loaded. If not, load it. */
        if (mbedtls_ecp_is_zero(&ecp->MBEDTLS_PRIVATE(Q)) != 0) {
            verify_status =
                (casper_mbedtls_ecp_mul(&ecp->MBEDTLS_PRIVATE(grp), &ecp->MBEDTLS_PRIVATE(Q),
                                        &ecp->MBEDTLS_PRIVATE(d),
                                        &ecp->MBEDTLS_PRIVATE(
                                            grp).G,
                                        mbedtls_psa_get_random,
                                        MBEDTLS_PSA_RANDOM_STATE));
        }

        if (verify_status == 0) {
            verify_status = casper_mbedtls_ecdsa_verify(&ecp->MBEDTLS_PRIVATE(grp),
                                                        input,
                                                        input_length,
                                                        &ecp->MBEDTLS_PRIVATE(Q),
                                                        &r,
                                                        &s);
        }
    }

    /* Unlock mutex */
    if ((status == PSA_SUCCESS) && (mcux_mutex_unlock(&casper_hwcrypto_mutex) != 0)) {
        status = PSA_ERROR_SERVICE_FAILURE;
    }

    /* Check verification status */
    if ((status == PSA_SUCCESS) && (verify_status != 0)) {
        // casper sign failed
        status = mbedtls_to_psa_error(verify_status);
    }

    // cleanup
    mbedtls_mpi_free(&r);
    mbedtls_mpi_free(&s);
    if (ecp != NULL) {
        mbedtls_ecp_keypair_free(ecp);
        mbedtls_free(ecp);
    }

    return status;
}
#endif /* defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY) */

psa_status_t casper_common_asymmetric_sign_hash(const psa_key_attributes_t *attributes,
                                                const uint8_t *key,
                                                size_t key_length,
                                                psa_algorithm_t alg,
                                                const uint8_t *input,
                                                size_t input_length,
                                                uint8_t *signature,
                                                size_t signature_size,
                                                size_t *signature_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

    *signature_length = 0u;

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
    if ((PSA_ALG_IS_RANDOMIZED_ECDSA(alg) || PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) &&
        PSA_KEY_TYPE_IS_ECC(key_type)) {
        status = casper_common_internal_ecc_sign(attributes,
                                                 key,
                                                 key_length,
                                                 alg,
                                                 input,
                                                 input_length,
                                                 signature,
                                                 signature_size,
                                                 signature_length);
    } else
#endif /* PSA_WANT_ALG_ECDSA */
    {
        (void)key_type;
    }

    return status;
}

psa_status_t casper_common_asymmetric_verify_hash(const psa_key_attributes_t *attributes,
                                                  const uint8_t *key,
                                                  size_t key_length,
                                                  psa_algorithm_t alg,
                                                  const uint8_t *hash,
                                                  size_t hash_length,
                                                  const uint8_t *signature,
                                                  size_t signature_length)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

#if defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_ECDSA_ANY)
    if ((PSA_ALG_IS_RANDOMIZED_ECDSA(alg) || PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) &&
        PSA_KEY_TYPE_IS_ECC(key_type)) {
        status = casper_common_internal_ecc_verify(attributes,
                                                   key,
                                                   key_length,
                                                   alg,
                                                   hash,
                                                   hash_length,
                                                   signature,
                                                   signature_length);
    } else
#endif /* PSA_WANT_ALG_ECDSA */
    {
        (void)key_type;
    }

    return status;
}

/** @} */ // end of psa_asym_sign
