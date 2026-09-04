/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

#ifndef MCUX_PSA_CASPER_ECP_PORT_H
#define MCUX_PSA_CASPER_ECP_PORT_H

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_ECP_C) && \
    defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || \
    defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) || \
    defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)

#include "mbedtls/private_access.h"

#include "mbedtls/build_info.h"

#include "fsl_casper.h"
#include "mbedtls/build_info.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "mbedtls/private/ecp.h"
#else
#include "mbedtls/ecp.h"
#endif

#include "mbedtls/threading.h"
#include "mbedtls/platform_util.h"

#include <string.h>

/* CASPER driver allows usage of 256, 384 and 521 ECC */
#define CASPER_MAX_ECC_SIZE_BITS  (521)
#define CASPER_MAX_ECC_SIZE_BYTES (72) /* 32 for 256 bits, 48 for 384 bits and 72 for 521 bits*/

int casper_mbedtls_ecp_mul(mbedtls_ecp_group *grp,
                           mbedtls_ecp_point *R,       // result
                           const mbedtls_mpi *m,       // scalar
                           const mbedtls_ecp_point *P, // X & Y
                           int (*f_rng)(void *, unsigned char *, size_t),
                           void *p_rng);

/*
 * Linear combination
 * NOT constant-time
 */
int casper_mbedtls_ecp_muladd(mbedtls_ecp_group *grp,
                              mbedtls_ecp_point *R,
                              const mbedtls_mpi *m,
                              const mbedtls_ecp_point *P,
                              const mbedtls_mpi *n,
                              const mbedtls_ecp_point *Q);

#endif /* MBEDTLS_ECP_C && MBEDTLS_BIGNUM_C */

#endif // MCUX_PSA_CASPER_ECP_PORT_H
