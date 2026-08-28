/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#define MBEDTLS_DECLARE_PRIVATE_IDENTIFIERS

#include "psa/crypto.h"
#include "psa_crypto_rsa.h"
#include "psa_crypto_ecp.h"
#include "psa_util_internal.h"

#include "mbedtls/private_access.h"
#include "mbedtls/asn1write.h"
#include "mbedtls/platform.h"
#include "mbedtls/build_info.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "mbedtls/private/ecdsa.h"
#include "mbedtls/private/ecp.h"
#else
#include "mbedtls/ecdsa.h"
#include "mbedtls/ecp.h"
#endif
#include "mbedtls/psa_util.h"
#include "ctr_drbg.h"
#include <string.h>

/* Forward declarations for PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY-gated functions.
 * mbedtls_ecp_group_id is available from mbedtls/ecp.h above. */
psa_ecc_family_t mbedtls_ecc_group_to_psa(mbedtls_ecp_group_id grpid, size_t *bits);

#include "mcux_psa_common_key_management.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

const uint32_t s_rsa_exponent = RSA_EXPONENT;

// Functions
psa_status_t mcux_key_buf_to_raw_ecc(psa_key_type_t key_type,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     mcux_key_type_t req_key_type,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     struct mcux_ecc_keypair *ecc_key)
{
    psa_status_t status;
    mbedtls_ecdsa_context *ecc = NULL;
    int ret;
    size_t olen;
    size_t key_bits;

    (void) mbedtls_ecc_group_to_psa(ecp_grou_id, &key_bits);

    /* Parse input - We will use mbedtls_ecdsa_context to parse the context info */
    status = mbedtls_psa_ecp_load_representation(key_type,
                                                 key_bits,
                                                 key_buffer,
                                                 key_buffer_size,
                                                 &ecc);

    if (status == PSA_SUCCESS) {
        /* Alocate MPI structure for public key */
        status = mcux_alloc_raw_ecc(ecc_key, PSA_BITS_TO_BYTES(key_bits), req_key_type, false);
    } else {
        ecc_key->private_key_len = 0u;
        ecc_key->public_key_len  = 0u;
    }

    if (status == PSA_SUCCESS) {
        if ((req_key_type == MCUX_KEY_TYPE_KEYPAIR) || (req_key_type == MCUX_KEY_TYPE_PUBLIC)) {
            /* Check whether the public part is loaded. If not, load it. */
            if (mbedtls_ecp_is_zero(&ecc->MBEDTLS_PRIVATE(Q))) {
                ret = mbedtls_ecp_mul(&ecc->MBEDTLS_PRIVATE(grp),
                                      &ecc->MBEDTLS_PRIVATE(Q),
                                      &ecc->MBEDTLS_PRIVATE(d),
                                      &ecc->MBEDTLS_PRIVATE(grp).G,
                                      mbedtls_psa_get_random,
                                      MBEDTLS_PSA_RANDOM_STATE);
                if (ret < 0) {
                    status = PSA_ERROR_BAD_STATE;
                }
            }

            if (status == PSA_SUCCESS) {
                /* Read modulus data from MPI ctx structure */
                ret = mbedtls_ecp_point_write_binary(&ecc->MBEDTLS_PRIVATE(grp),
                                                     &ecc->MBEDTLS_PRIVATE(Q),
                                                     MBEDTLS_ECP_PF_UNCOMPRESSED,
                                                     &olen,
                                                     (unsigned char *) ecc_key->public_key,
                                                     ecc_key->public_key_len);
                if (ret < 0) {
                    status = PSA_ERROR_BAD_STATE;
                }
            }
        }
    }

    if (status == PSA_SUCCESS) {
        if ((req_key_type == MCUX_KEY_TYPE_KEYPAIR) || (req_key_type == MCUX_KEY_TYPE_PRIVATE)) {
            /* Read private exponent data from MPI ctx structure */
            ret = mbedtls_mpi_write_binary(&ecc->MBEDTLS_PRIVATE(d),
                                           (unsigned char *) ecc_key->private_key,
                                           ecc_key->private_key_len);
            if (ret < 0) {
                status = PSA_ERROR_BAD_STATE;
            }
        }
    }

    if (status != PSA_SUCCESS) {
        mcux_free_raw_ecc(ecc_key);
    }

    if (ecc != NULL) {
        mbedtls_ecdsa_free(ecc);
        mbedtls_free(ecc);
    }

    return status;
}

psa_status_t mcux_raw_ecc_to_key_buf(psa_key_type_t key_type,
                                     bool only_public,
                                     struct mcux_ecc_keypair *ecc_key,
                                     mbedtls_ecp_group_id ecp_grou_id,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length)
{
    mbedtls_ecdsa_context ecc;
    psa_status_t status = PSA_SUCCESS;
    int ret;

    mbedtls_ecdsa_init(&ecc);

    mbedtls_ecp_group_init(&ecc.MBEDTLS_PRIVATE(grp));

    ret = mbedtls_ecp_group_load(&ecc.MBEDTLS_PRIVATE(grp), ecp_grou_id);

    if (ret == 0) {
        mbedtls_ecp_point_init(&ecc.MBEDTLS_PRIVATE(Q));

        ret = mbedtls_ecp_point_read_binary(&ecc.MBEDTLS_PRIVATE(grp),
                                            &ecc.MBEDTLS_PRIVATE(Q),
                                            ecc_key->public_key,
                                            ecc_key->public_key_len);
    }
    /* ADD ECC curve */

    if (ret == 0) {
        if (only_public) {
            key_type = PSA_KEY_TYPE_CATEGORY_PUBLIC_KEY;
        } else {
            mbedtls_mpi_init(&ecc.MBEDTLS_PRIVATE(d));

            /* Read private exponent in MPI */
            ret = mbedtls_mpi_read_binary(&ecc.MBEDTLS_PRIVATE(d),
                                          (const unsigned char *) ecc_key->private_key,
                                          ecc_key->private_key_len);
        }
    }

    if (ret < 0) {
        status = PSA_ERROR_BAD_STATE;
    }

    if (status == PSA_SUCCESS) {
        status = mbedtls_psa_ecp_export_key(key_type,
                                            &ecc,
                                            (uint8_t *) key_buffer,
                                            key_buffer_size,
                                            key_buffer_length);
    }

    mbedtls_ecdsa_free(&ecc);

    return status;
}

psa_status_t mcux_alloc_raw_ecc(struct mcux_ecc_keypair *ecc_key,
                                size_t key_bytes,
                                mcux_key_type_t key_type,
                                bool useAlign)
{
    psa_status_t err  = PSA_SUCCESS;
    size_t pubKeyLen  = ECC_PUBLIC_KEY_SIZE(key_bytes);
    size_t privKeyLen = key_bytes;

    if (useAlign) {
        /* Align to should not wrap */
        if (mcux_psa_add_size_t_wrapcheck(privKeyLen, 19U)) {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }
        privKeyLen = ECC_ALIGN_PRIVATE_KEY_SIZE(privKeyLen);
    }

#if defined(USE_MALLOC)
    ecc_key->private_key = NULL;
    ecc_key->public_key  = NULL;
#endif
    ecc_key->private_key_len = 0u;
    ecc_key->public_key_len  = 0u;

    if ((key_type == MCUX_KEY_TYPE_PRIVATE) || (key_type == MCUX_KEY_TYPE_KEYPAIR)) {
#if defined(USE_MALLOC)
        ecc_key->private_key = (uint8_t *) mbedtls_calloc(1u, privKeyLen);
        if (ecc_key->private_key == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#else
        if (privKeyLen > sizeof(ecc_key->private_key)) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#endif
        ecc_key->private_key_len = privKeyLen;
    }

    if ((key_type == MCUX_KEY_TYPE_PUBLIC) || (key_type == MCUX_KEY_TYPE_KEYPAIR)) {
#if defined(USE_MALLOC)
        /* Alocate MPI structure for Private exponent */
        ecc_key->public_key = (uint8_t *) mbedtls_calloc(1u, pubKeyLen);
        if (ecc_key->public_key == NULL) {
            if (ecc_key->private_key_len > 0u) {
                mbedtls_free(ecc_key->private_key);
            }
            err = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#else
        if (pubKeyLen > sizeof(ecc_key->public_key)) {
            err = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#endif
        if (err == PSA_SUCCESS) {
            ecc_key->public_key_len = pubKeyLen;
        } else {
            ecc_key->private_key_len = 0u;
        }
    }

    return err;
}

psa_status_t mcux_free_raw_ecc(struct mcux_ecc_keypair *ecc_key)
{
#if defined(USE_MALLOC)
    if ((ecc_key->private_key_len > 0u) && (ecc_key->private_key != NULL)) {
        mbedtls_free(ecc_key->private_key);
    }

    if ((ecc_key->public_key_len > 0u) && (ecc_key->public_key != NULL)) {
        mbedtls_free(ecc_key->public_key);
    }
#endif

    memset(ecc_key, 0, sizeof(*ecc_key));

    return PSA_SUCCESS;
}

psa_status_t mcux_key_buf_to_raw_rsa(psa_key_type_t key_type,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     uint32_t key_bytes,
                                     bool is_public,
                                     struct mcux_rsa_keypair *rsa_key,
                                     uint8_t rsa_exp[4])
{
    psa_status_t status;
    mbedtls_rsa_context *rsa = NULL;
    int ret;

    /* Parse input - We will use mbedtls_rsa_context to parse the context into*/
    status = mbedtls_psa_rsa_load_representation(key_type, key_buffer, key_buffer_size, &rsa);

    /* Alocate MPI structure for Public modulus */
    if (status == PSA_SUCCESS) {
        status =
            mcux_alloc_raw_rsa(rsa_key,
                               key_bytes,
                               (is_public) ? MCUX_KEY_TYPE_PUBLIC : MCUX_KEY_TYPE_KEYPAIR,
                               false);
    } else {
        rsa_key->modulus_len  = 0u;
        rsa_key->priv_exp_len = 0u;
    }
    if (status == PSA_SUCCESS) {
        if (is_public) {
            ret = mbedtls_mpi_write_binary(&rsa->MBEDTLS_PRIVATE(E), rsa_exp, 4);
            if (ret < 0) {
                status = PSA_ERROR_BAD_STATE;
            }
        } else {
            /* Read private exponent data from MPI ctx structure */
            ret = mbedtls_mpi_write_binary(&rsa->MBEDTLS_PRIVATE(D),
                                           (unsigned char *) rsa_key->priv_exp,
                                           rsa_key->priv_exp_len);
            if (ret < 0) {
                status = PSA_ERROR_BAD_STATE;
            }
        }
    }

    if (status == PSA_SUCCESS) {
        /* Read modulus data from MPI ctx structure */
        ret = mbedtls_mpi_write_binary(&rsa->MBEDTLS_PRIVATE(N),
                                       (unsigned char *) rsa_key->modulus,
                                       key_bytes);

        if (ret < 0) {
            status = PSA_ERROR_BAD_STATE;
        }
    }

    if (status != PSA_SUCCESS) {
        mcux_free_raw_rsa(rsa_key);
    }

    if (rsa != NULL) {
        mbedtls_rsa_free(rsa);
        mbedtls_free(rsa);
    }

    return status;
}

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER < 0x04000000)
psa_status_t mcux_raw_rsa_to_key_buf(psa_key_type_t key_type,
                                     bool only_public,
                                     const struct mcux_rsa_keypair *rsa_key,
                                     const uint8_t *key_buffer,
                                     size_t key_buffer_size,
                                     size_t *key_buffer_length)
{
    mbedtls_rsa_context rsa;
    psa_status_t status = PSA_SUCCESS;
    int ret;

    mbedtls_rsa_init(&rsa);

    mbedtls_mpi_init(&rsa.MBEDTLS_PRIVATE(N));

    /* Read modulo in MPI */
    ret =
        mbedtls_mpi_read_binary(&rsa.MBEDTLS_PRIVATE(N),
                                (const unsigned char *) rsa_key->modulus,
                                rsa_key->modulus_len);
    if (ret == 0) {
        ret = mbedtls_mpi_lset(&rsa.MBEDTLS_PRIVATE(E), (mbedtls_mpi_sint) s_rsa_exponent);
    }

    if (ret == 0) {
        /* Set Ctx length */
        rsa.MBEDTLS_PRIVATE(len) = mbedtls_mpi_size(&rsa.MBEDTLS_PRIVATE(N));

        if (only_public) {
            key_type = PSA_KEY_TYPE_CATEGORY_PUBLIC_KEY;
        } else {
            mbedtls_mpi_init(&rsa.MBEDTLS_PRIVATE(D));

            /* Read private exponent in MPI */
            ret = mbedtls_mpi_read_binary(&rsa.MBEDTLS_PRIVATE(D),
                                          (const unsigned char *) rsa_key->priv_exp,
                                          rsa_key->priv_exp_len);

            if (ret == 0) {
                /* Compute P and Q in CTX. */
                /* Needed as key buffer needs to be in PKCS1 format*/
                ret = mbedtls_rsa_complete(&rsa);
            }
        }
    }

    if (ret < 0) {
        status = PSA_ERROR_BAD_STATE;
    }

    if (status == PSA_SUCCESS) {
        status = mbedtls_psa_rsa_export_key(key_type,
                                            &rsa,
                                            (uint8_t *) key_buffer,
                                            key_buffer_size,
                                            key_buffer_length);
    }

    mbedtls_rsa_free(&rsa);

    return status;
}
#endif /* MBEDTLS_VERSION_NUMBER < 0x04000000 */

psa_status_t mcux_alloc_raw_rsa(struct mcux_rsa_keypair *rsa_key,
                                size_t key_bytes,
                                mcux_key_type_t key_type,
                                bool useAlign)
{
    psa_status_t err  = PSA_SUCCESS;
    size_t modulusLen = key_bytes;
    size_t privExpLen = key_bytes;

    if (useAlign) {
        /* Align should not wrap */
        if (mcux_psa_add_size_t_wrapcheck(privExpLen, 19U)) {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }
        privExpLen = RSA_ALIGN_PRIVATE_EXPONENT_SIZE(privExpLen);
    }

#if defined(USE_MALLOC)
    rsa_key->modulus  = NULL;
    rsa_key->priv_exp = NULL;
#endif
    rsa_key->modulus_len  = 0u;
    rsa_key->priv_exp_len = 0u;

    if ((key_type == MCUX_KEY_TYPE_PUBLIC) || (key_type == MCUX_KEY_TYPE_KEYPAIR)) {
#if defined(USE_MALLOC)
        rsa_key->modulus = (uint8_t *) mbedtls_calloc(1u, modulusLen);
        if (rsa_key->modulus == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#else
        if (modulusLen > sizeof(rsa_key->modulus)) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#endif
        rsa_key->modulus_len = modulusLen;
    }

    if ((key_type == MCUX_KEY_TYPE_PRIVATE) || (key_type == MCUX_KEY_TYPE_KEYPAIR)) {
#if defined(USE_MALLOC)
        /* Alocate MPI structure for Private exponent */
        rsa_key->priv_exp = (uint8_t *) mbedtls_calloc(1u, privExpLen);
        if (rsa_key->priv_exp == NULL) {
            if (rsa_key->modulus > 0u) {
                mbedtls_free(rsa_key->modulus);
            }
            err = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#else
        if (privExpLen > sizeof(rsa_key->priv_exp)) {
            err = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#endif
        if (err == PSA_SUCCESS) {
            rsa_key->priv_exp_len = privExpLen;
        } else {
            rsa_key->modulus_len = 0u;
        }
    }
    return err;
}

psa_status_t mcux_free_raw_rsa(struct mcux_rsa_keypair *rsa_key)
{
#if defined(USE_MALLOC)
    if ((rsa_key->modulus_len > 0u) && (rsa_key->modulus != NULL)) {
        mbedtls_free(rsa_key->modulus);
    }

    if ((rsa_key->priv_exp_len > 0u) && (rsa_key->priv_exp != NULL)) {
        mbedtls_free(rsa_key->priv_exp);
    }
#endif

    memset(rsa_key, 0, sizeof(*rsa_key));

    return PSA_SUCCESS;
}

psa_status_t mcux_rsa_generate_primes(size_t bit_size, struct mcux_rsa_primes *primes)
{
    int status = 0;
    mbedtls_mpi P, Q, H;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_entropy_context entropy;
    const char *pers = "rsa_primes";
    int prime_quality = 0;
    if (bit_size > 1024) {
        prime_quality = MBEDTLS_MPI_GEN_PRIME_FLAG_LOW_ERR;
    }

#if defined(USE_MALLOC)
    primes->p = NULL;
    primes->q = NULL;
#endif

    primes->len = (bit_size >> 1) / 8;

    mbedtls_mpi_init(&P);
    mbedtls_mpi_init(&Q);
    mbedtls_mpi_init(&H);
    mbedtls_ctr_drbg_init(&ctr_drbg);
    mbedtls_entropy_init(&entropy);

    status =
        mbedtls_ctr_drbg_seed(&ctr_drbg,
                              mbedtls_entropy_func,
                              &entropy,
                              (const unsigned char *) pers,
                              strlen(pers));

    // Generate two prime numbers for RSA
    do {
            status =
                mbedtls_mpi_gen_prime(&P,
                                      bit_size >> 1,
                                      prime_quality,
                                      mbedtls_psa_get_random,
                                      MBEDTLS_PSA_RANDOM_STATE);

        if (status == 0) {
            status =
                mbedtls_mpi_gen_prime(&Q,
                                      bit_size >> 1,
                                      prime_quality,
                                      mbedtls_psa_get_random,
                                      MBEDTLS_PSA_RANDOM_STATE);
        }

        if (status == 0) {
            status = mbedtls_mpi_sub_mpi(&H, &P, &Q);
        }
        if (status == 0) {
            /* make sure the difference between p and q is not too small (FIPS 186-4 §B.3.3 step 5.4) */
            if (mbedtls_mpi_bitlen(&H) <= ((bit_size >= 200u) ? ((bit_size >> 1) - 99u) : 0u)) {
                continue;
            }

            /* not required by any standards, but some users rely on the fact that P > Q */
            if (H.MBEDTLS_PRIVATE(s) < 0) {
                mbedtls_mpi_swap(&P, &Q);
            }
            break;
        }
    } while (status == 0);

    if (status == 0) {
#if defined(USE_MALLOC)
        primes->p = (uint8_t *) mbedtls_calloc(1u, primes->len);
        primes->q = (uint8_t *) mbedtls_calloc(1u, primes->len);
        if ((primes->p == NULL) || (primes->q == NULL)) {
            status = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#else
        if ((sizeof(primes->p) < prime->len) || (sizeof(primes->q) < prime->len)) {
            status = PSA_ERROR_INSUFFICIENT_MEMORY;
        }
#endif
    }

    if (status == 0) {
        status = mbedtls_mpi_write_binary(&P, (unsigned char *) primes->p, primes->len);
    }
    if (status == 0) {
        status = mbedtls_mpi_write_binary(&Q, (unsigned char *) primes->q, primes->len);
    }

    // Cleanup
    mbedtls_mpi_free(&P);
    mbedtls_mpi_free(&Q);
    mbedtls_mpi_free(&H);

    if (status == 0) {
        return PSA_SUCCESS;
    } else {
        mcux_rsa_free_primes(primes);
        return PSA_ERROR_BAD_STATE;
    }
}

psa_status_t mcux_rsa_free_primes(struct mcux_rsa_primes *primes)
{
#if defined(USE_MALLOC)
    if (primes->p != NULL) {
        mbedtls_free(primes->p);
    }
    if (primes->q != NULL) {
        mbedtls_free(primes->q);
    }
    primes->len = 0u;
#else
    memset(primes, 0, sizeof(*primes));
#endif

    return PSA_SUCCESS;
}

/** @} */ // end of psa_key_generation
