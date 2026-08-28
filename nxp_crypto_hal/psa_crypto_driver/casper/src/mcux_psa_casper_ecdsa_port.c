/*
 *  Elliptic curve DSA
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/*
 * References:
 *
 * SEC1 https://www.secg.org/sec1-v2.pdf
 */

#define MBEDTLS_DECLARE_PRIVATE_IDENTIFIERS

#include "mcux_psa_casper_ecdsa_port.h"
#include "mcux_psa_casper_ecp_port.h"

#include "mbedtls/private_access.h"
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "mbedtls/private/ecdsa.h"
#include "mbedtls/private/ecp.h"
#else
#include "mbedtls/ecdsa.h"
#include "mbedtls/ecp.h"
#endif
#include "mbedtls/error.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "mbedtls/private/hmac_drbg.h"
#include "mbedtls/private/bignum.h"
#else
/* This is for backwards compatibility with MbedTLS 3.x */
#include "mbedtls/bignum.h"
#include "mbedtls/hmac_drbg.h"
#endif

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_ECP_C) && \
    (defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED))

/*
 * Derive a suitable integer for group grp from a buffer of length len
 * SEC1 4.1.3 step 5 aka SEC1 4.1.4 step 3
 */
static int derive_mpi(const mbedtls_ecp_group *grp, mbedtls_mpi *x,
                      const unsigned char *buf, size_t blen)
{
    int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    size_t n_size = (grp->nbits + 7) / 8;
    size_t use_size = blen > n_size ? n_size : blen;

    MBEDTLS_MPI_CHK(mbedtls_mpi_read_binary(x, buf, use_size));

    if (mcux_psa_mul_size_t_wrapcheck(use_size, 8U))
    {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }
    if (use_size * 8 > grp->nbits) {
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(x, use_size * 8 - grp->nbits));
    }

    /* While at it, reduce modulo N */
    if (mbedtls_mpi_cmp_mpi(x, &grp->N) >= 0) {
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(x, x, &grp->N));
    }

cleanup:
    return ret;
}


/*
 * Compute ECDSA signature of a hashed message (SEC1 4.1.3)
 * Obviously, compared to SEC1 4.1.3, we skip step 4 (hash message)
 */
static int casper_mbedtls_ecdsa_sign_internal(mbedtls_ecp_group *grp,
                                   mbedtls_mpi *r, mbedtls_mpi *s,
                                   const mbedtls_mpi *d, const unsigned char *buf, size_t blen,
                                   int (*f_rng)(void *, unsigned char *, size_t), void *p_rng,
                                   int (*f_rng_blind)(void *, unsigned char *, size_t),
                                   void *p_rng_blind)
{
    int ret, key_tries, sign_tries;
    int *p_sign_tries = &sign_tries, *p_key_tries = &key_tries;
    mbedtls_ecp_point R;
    mbedtls_mpi k, e, t;
    mbedtls_mpi *pk = &k, *pr = r;

    /* Fail cleanly on curves such as Curve25519 that can't be used for ECDSA */
    if (0 == mbedtls_ecdsa_can_do(grp->id) || grp->N.MBEDTLS_PRIVATE(p) == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    /* Make sure d is in range 1..n-1 */
    if (mbedtls_mpi_cmp_int(d, 1) < 0 || mbedtls_mpi_cmp_mpi(d, &grp->N) >= 0) {
        return MBEDTLS_ERR_ECP_INVALID_KEY;
    }

    mbedtls_ecp_point_init(&R);
    mbedtls_mpi_init(&k); mbedtls_mpi_init(&e); mbedtls_mpi_init(&t);

    *p_sign_tries = 0;
    do {
        if ((*p_sign_tries)++ > 10) {
            ret = MBEDTLS_ERR_ECP_RANDOM_FAILED;
            goto cleanup;
        }

        /*
         * Steps 1-3: generate a suitable ephemeral keypair
         * and set r = xR mod n
         */
        *p_key_tries = 0;
        do {
            if ((*p_key_tries)++ > 10) {
                ret = MBEDTLS_ERR_ECP_RANDOM_FAILED;
                goto cleanup;
            }

            MBEDTLS_MPI_CHK(mbedtls_ecp_gen_privkey(grp, pk, f_rng, p_rng));

            MBEDTLS_MPI_CHK(casper_mbedtls_ecp_mul(grp, &R, pk, &grp->G,
                                                        f_rng_blind,
                                                        p_rng_blind));
            MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(pr, &R.MBEDTLS_PRIVATE(X), &grp->N));
        } while (mbedtls_mpi_cmp_int(pr, 0) == 0);

        /*
         * Accounting for everything up to the end of the loop
         * (step 6, but checking now avoids saving e and t)
         */
        //  ECDSA_BUDGET(MBEDTLS_ECP_OPS_INV + 4);

        /*
         * Step 5: derive MPI from hashed message
         */
        MBEDTLS_MPI_CHK(derive_mpi(grp, &e, buf, blen));

        /*
         * Generate a random value to blind inv_mod in next step,
         * avoiding a potential timing leak.
         */
        MBEDTLS_MPI_CHK(mbedtls_ecp_gen_privkey(grp, &t, f_rng_blind,
                                                p_rng_blind));

        /*
         * Step 6: compute s = (e + r * d) / k = t (e + rd) / (kt) mod n
         */
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(s, pr, d));
        MBEDTLS_MPI_CHK(mbedtls_mpi_add_mpi(&e, &e, s));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&e, &e, &t));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(pk, pk, &t));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(pk, pk, &grp->N));
        MBEDTLS_MPI_CHK(mbedtls_mpi_inv_mod(s, pk, &grp->N));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(s, s, &e));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(s, s, &grp->N));
    } while (mbedtls_mpi_cmp_int(s, 0) == 0);

cleanup:
    mbedtls_ecp_point_free(&R);
    mbedtls_mpi_free(&k); mbedtls_mpi_free(&e); mbedtls_mpi_free(&t);

    return ret;
}

/*
 * Compute ECDSA signature of a hashed message
 */
int casper_mbedtls_ecdsa_sign(mbedtls_ecp_group *grp, mbedtls_mpi *r, mbedtls_mpi *s,
                       const mbedtls_mpi *d, const unsigned char *buf, size_t blen,
                       int (*f_rng)(void *, unsigned char *, size_t), void *p_rng)
{
    /* Use the same RNG for both blinding and ephemeral key generation */
    return casper_mbedtls_ecdsa_sign_internal(grp, r, s, d, buf, blen,
                                          f_rng, p_rng, f_rng, p_rng);
}

/*
 * Deterministic signature wrapper
 *
 * note:    The f_rng_blind parameter must not be NULL.
 *
 */
static int casper_mbedtls_ecdsa_sign_det_internal(mbedtls_ecp_group *grp,
                                      mbedtls_mpi *r, mbedtls_mpi *s,
                                      const mbedtls_mpi *d, const unsigned char *buf, size_t blen,
                                      mbedtls_md_type_t md_alg,
                                      int (*f_rng_blind)(void *, unsigned char *, size_t),
                                      void *p_rng_blind)
{
   int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
   mbedtls_hmac_drbg_context rng_ctx;
   mbedtls_hmac_drbg_context *p_rng = &rng_ctx;
   unsigned char data[2 * MBEDTLS_ECP_MAX_BYTES];
   size_t grp_len = (grp->nbits + 7) / 8;
   const mbedtls_md_info_t *md_info;
   mbedtls_mpi h;

   if ((md_info = mbedtls_md_info_from_type(md_alg)) == NULL) {
       return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
   }

   mbedtls_mpi_init(&h);
   mbedtls_hmac_drbg_init(&rng_ctx);

   /* Use private key and message hash (reduced) to initialize HMAC_DRBG */
   MBEDTLS_MPI_CHK(mbedtls_mpi_write_binary(d, data, grp_len));
   MBEDTLS_MPI_CHK(derive_mpi(grp, &h, buf, blen));
   MBEDTLS_MPI_CHK(mbedtls_mpi_write_binary(&h, data + grp_len, grp_len));
   MBEDTLS_MPI_CHK(mbedtls_hmac_drbg_seed_buf(p_rng, md_info, data, 2 * grp_len));

   ret = casper_mbedtls_ecdsa_sign_internal(grp, r, s, d, buf, blen,
                                        mbedtls_hmac_drbg_random, p_rng,
                                        f_rng_blind, p_rng_blind);

cleanup:
   mbedtls_hmac_drbg_free(&rng_ctx);
   mbedtls_mpi_free(&h);

   return ret;
}

/*
 * Deterministic signature wrapper
 */
int casper_mbedtls_ecdsa_sign_det_ext(mbedtls_ecp_group *grp, mbedtls_mpi *r,
                              mbedtls_mpi *s, const mbedtls_mpi *d,
                              const unsigned char *buf, size_t blen,
                              mbedtls_md_type_t md_alg,
                              int (*f_rng_blind)(void *, unsigned char *,
                                                 size_t),
                              void *p_rng_blind)
{
   return casper_mbedtls_ecdsa_sign_det_internal(grp, r, s, d, buf, blen, md_alg,
                                             f_rng_blind, p_rng_blind);
}



/*
 * Verify ECDSA signature of hashed message (SEC1 4.1.4)
 * Obviously, compared to SEC1 4.1.3, we skip step 2 (hash message)
 */
static int casper_mbedtls_ecdsa_verify_internal(mbedtls_ecp_group *grp,
                                     const unsigned char *buf, size_t blen,
                                     const mbedtls_ecp_point *Q,
                                     const mbedtls_mpi *r,
                                     const mbedtls_mpi *s)
{
    int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    mbedtls_mpi e, s_inv, u1, u2;
    mbedtls_ecp_point R;
    mbedtls_mpi *pu1 = &u1, *pu2 = &u2;

    mbedtls_ecp_point_init(&R);
    mbedtls_mpi_init(&e); mbedtls_mpi_init(&s_inv);
    mbedtls_mpi_init(&u1); mbedtls_mpi_init(&u2);

    /* Fail cleanly on curves such as Curve25519 that can't be used for ECDSA */
    if (0 == mbedtls_ecdsa_can_do(grp->id) || grp->N.MBEDTLS_PRIVATE(p) == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    /*
     * Step 1: make sure r and s are in range 1..n-1
     */
    if (mbedtls_mpi_cmp_int(r, 1) < 0 || mbedtls_mpi_cmp_mpi(r, &grp->N) >= 0 ||
        mbedtls_mpi_cmp_int(s, 1) < 0 || mbedtls_mpi_cmp_mpi(s, &grp->N) >= 0) {
        ret = MBEDTLS_ERR_ECP_VERIFY_FAILED;
        goto cleanup;
    }

    /*
     * Step 3: derive MPI from hashed message
     */
    MBEDTLS_MPI_CHK(derive_mpi(grp, &e, buf, blen));

    /*
     * Step 4: u1 = e / s mod n, u2 = r / s mod n
     */
    //  ECDSA_BUDGET(MBEDTLS_ECP_OPS_CHK + MBEDTLS_ECP_OPS_INV + 2);

    MBEDTLS_MPI_CHK(mbedtls_mpi_inv_mod(&s_inv, s, &grp->N));

    MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(pu1, &e, &s_inv));
    MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(pu1, pu1, &grp->N));

    MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(pu2, r, &s_inv));
    MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(pu2, pu2, &grp->N));

    /*
     * Step 5: R = u1 G + u2 Q
     */
    MBEDTLS_MPI_CHK(casper_mbedtls_ecp_muladd(grp,
                                                   &R, pu1, &grp->G, pu2, Q));

    if (mbedtls_ecp_is_zero(&R)) {
        ret = MBEDTLS_ERR_ECP_VERIFY_FAILED;
        goto cleanup;
    }

    /*
     * Step 6: convert xR to an integer (no-op)
     * Step 7: reduce xR mod n (gives v)
     */
    MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&R.MBEDTLS_PRIVATE(X), &R.MBEDTLS_PRIVATE(X), &grp->N));

    /*
     * Step 8: check if v (that is, R.X) is equal to r
     */
    if (mbedtls_mpi_cmp_mpi(&R.MBEDTLS_PRIVATE(X), r) != 0) {
        ret = MBEDTLS_ERR_ECP_VERIFY_FAILED;
        goto cleanup;
    }

cleanup:
    mbedtls_ecp_point_free(&R);
    mbedtls_mpi_free(&e); mbedtls_mpi_free(&s_inv);
    mbedtls_mpi_free(&u1); mbedtls_mpi_free(&u2);

    return ret;
}

/*
 * Verify ECDSA signature of hashed message
 */
int casper_mbedtls_ecdsa_verify(mbedtls_ecp_group *grp,
                         const unsigned char *buf, size_t blen,
                         const mbedtls_ecp_point *Q,
                         const mbedtls_mpi *r,
                         const mbedtls_mpi *s)
{
    return casper_mbedtls_ecdsa_verify_internal(grp, buf, blen, Q, r, s);
}

#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ECP_C && (SECP256R1 || SECP384R1 || SECP521R1) */
