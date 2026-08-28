/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/**
 * \file mcux_psa_casper_ecdsa_port.h
 *
 * \brief This file contains ECDSA definitions and functions using CASPER. 
 *
 * The Elliptic Curve Digital Signature Algorithm (ECDSA) is defined in
 * <em>Standards for Efficient Cryptography Group (SECG):
 * SEC1 Elliptic Curve Cryptography</em>.
 * The use of ECDSA for TLS is defined in <em>RFC-4492: Elliptic Curve
 * Cryptography (ECC) Cipher Suites for Transport Layer Security (TLS)</em>.
 *
 */

#ifndef MCUX_PSA_CASPER_ECDSA_PORT_H
#define MCUX_PSA_CASPER_ECDSA_PORT_H
#include "mbedtls/private_access.h"

#include "mbedtls/build_info.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "mbedtls/private/ecp.h"
#else
#include "mbedtls/ecp.h"
#endif
#include "mbedtls/md.h"

/**
 * \brief           Maximum ECDSA signature size for a given curve bit size
 *
 * \param bits      Curve size in bits
 * \return          Maximum signature size in bytes
 *
 * \note            This macro returns a compile-time constant if its argument
 *                  is one. It may evaluate its argument multiple times.
 */
/*
 *     Ecdsa-Sig-Value ::= SEQUENCE {
 *         r       INTEGER,
 *         s       INTEGER
 *     }
 *
 * For each of r and s, the value (V) may include an extra initial "0" bit.
 */
#define MBEDTLS_ECDSA_MAX_SIG_LEN(bits)                               \
     (/*T,L of SEQUENCE*/ ((bits) >= 61 * 8 ? 3 : 2) +              \
      /*T,L of r,s*/ 2 * (((bits) >= 127 * 8 ? 3 : 2) +     \
                          /*V of r,s*/ ((bits) + 8) / 8))

/** The maximal size of an ECDSA signature in Bytes. */
#define MBEDTLS_ECDSA_MAX_LEN  MBEDTLS_ECDSA_MAX_SIG_LEN(MBEDTLS_ECP_MAX_BITS)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief           This function computes the ECDSA signature of a
 *                  previously-hashed message. It uses CASPER to accelerate
 *                  the elliptic curve arithmetics.
 *
 * \note            The deterministic version implemented in
 *                  casper_mbedtls_ecdsa_sign_det_ext() is usually preferred.
 *
 * \note            If the bitlength of the message hash is larger than the
 *                  bitlength of the group order, then the hash is truncated
 *                  as defined in <em>Standards for Efficient Cryptography Group
 *                  (SECG): SEC1 Elliptic Curve Cryptography</em>, section
 *                  4.1.3, step 5.
 *
 * \see             ecp.h
 *
 * \param grp       The context for the elliptic curve to use.
 *                  This must be initialized and have group parameters
 *                  set, for example through mbedtls_ecp_group_load().
 * \param r         The MPI context in which to store the first part
 *                  the signature. This must be initialized.
 * \param s         The MPI context in which to store the second part
 *                  the signature. This must be initialized.
 * \param d         The private signing key. This must be initialized.
 * \param buf       The content to be signed. This is usually the hash of
 *                  the original data to be signed. This must be a readable
 *                  buffer of length \p blen Bytes. It may be \c NULL if
 *                  \p blen is zero.
 * \param blen      The length of \p buf in Bytes.
 * \param f_rng     The RNG function. This must not be \c NULL.
 * \param p_rng     The RNG context to be passed to \p f_rng. This may be
 *                  \c NULL if \p f_rng doesn't need a context parameter.
 *
 * \return          \c 0 on success.
 * \return          An \c MBEDTLS_ERR_ECP_XXX
 *                  or \c MBEDTLS_MPI_XXX error code on failure.
 */
int casper_mbedtls_ecdsa_sign(mbedtls_ecp_group *grp, mbedtls_mpi *r, mbedtls_mpi *s,
                        const mbedtls_mpi *d, const unsigned char *buf, size_t blen,
                        int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);

/**
 * \brief           This function verifies the ECDSA signature of a
 *                  previously-hashed message. It uses CASPER to accelerate
 *                  the elliptic curve arithmetics.
 *
 * \note            If the bitlength of the message hash is larger than the
 *                  bitlength of the group order, then the hash is truncated as
 *                  defined in <em>Standards for Efficient Cryptography Group
 *                  (SECG): SEC1 Elliptic Curve Cryptography</em>, section
 *                  4.1.4, step 3.
 *
 * \see             ecp.h
 *
 * \param grp       The ECP group to use.
 *                  This must be initialized and have group parameters
 *                  set, for example through mbedtls_ecp_group_load().
 * \param buf       The hashed content that was signed. This must be a readable
 *                  buffer of length \p blen Bytes. It may be \c NULL if
 *                  \p blen is zero.
 * \param blen      The length of \p buf in Bytes.
 * \param Q         The public key to use for verification. This must be
 *                  initialized and setup.
 * \param r         The first integer of the signature.
 *                  This must be initialized.
 * \param s         The second integer of the signature.
 *                  This must be initialized.
 *
 * \return          \c 0 on success.
 * \return          An \c MBEDTLS_ERR_ECP_XXX or \c MBEDTLS_MPI_XXX
 *                  error code on failure.
 */
int casper_mbedtls_ecdsa_verify(mbedtls_ecp_group *grp,
                          const unsigned char *buf, size_t blen,
                          const mbedtls_ecp_point *Q, const mbedtls_mpi *r,
                          const mbedtls_mpi *s);


/**
 * \brief           This function computes the ECDSA signature of a
 *                  previously-hashed message, deterministic version.
 *
 *                  For more information, see <em>RFC-6979: Deterministic
 *                  Usage of the Digital Signature Algorithm (DSA) and Elliptic
 *                  Curve Digital Signature Algorithm (ECDSA)</em>.
 *
 * \note            If the bitlength of the message hash is larger than the
 *                  bitlength of the group order, then the hash is truncated as
 *                  defined in <em>Standards for Efficient Cryptography Group
 *                  (SECG): SEC1 Elliptic Curve Cryptography</em>, section
 *                  4.1.3, step 5.
 *
 * \see             ecp.h
 *
 * \param grp           The context for the elliptic curve to use.
 *                      This must be initialized and have group parameters
 *                      set, for example through mbedtls_ecp_group_load().
 * \param r             The MPI context in which to store the first part
 *                      the signature. This must be initialized.
 * \param s             The MPI context in which to store the second part
 *                      the signature. This must be initialized.
 * \param d             The private signing key. This must be initialized
 *                      and setup, for example through mbedtls_ecp_gen_privkey().
 * \param buf           The hashed content to be signed. This must be a readable
 *                      buffer of length \p blen Bytes. It may be \c NULL if
 *                      \p blen is zero.
 * \param blen          The length of \p buf in Bytes.
 * \param md_alg        The hash algorithm used to hash the original data.
 * \param f_rng_blind   The RNG function used for blinding. This must not be
 *                      \c NULL.
 * \param p_rng_blind   The RNG context to be passed to \p f_rng_blind. This
 *                      may be \c NULL if \p f_rng_blind doesn't need a context
 *                      parameter.
 *
 * \return          \c 0 on success.
 * \return          An \c MBEDTLS_ERR_ECP_XXX or \c MBEDTLS_MPI_XXX
 *                  error code on failure.
 */
int casper_mbedtls_ecdsa_sign_det_ext(mbedtls_ecp_group *grp, mbedtls_mpi *r,
                               mbedtls_mpi *s, const mbedtls_mpi *d,
                               const unsigned char *buf, size_t blen,
                               mbedtls_md_type_t md_alg,
                               int (*f_rng_blind)(void *, unsigned char *, size_t),
                               void *p_rng_blind);


#ifdef __cplusplus
}
#endif

#endif /* ecdsa.h */
