/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */


#define MBEDTLS_DECLARE_PRIVATE_IDENTIFIERS

#include "mbedtls/private_access.h"
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#include "fsl_casper.h"
#include "fsl_power.h"

#include "mcux_psa_casper_ecp_port.h"

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_ECP_C) && \
    (defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) || \
     defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED))

/* Initialize CASPER */
static volatile bool casper_init_is_done = false;
static void casper_mbedtls_init(void)
{
#if defined(MIMXRT685S_cm33_SERIES)
    /*Make sure casper ram buffer has power up*/
    POWER_DisablePD(kPDRUNCFG_APD_CASPER_SRAM);
    POWER_DisablePD(kPDRUNCFG_PPD_CASPER_SRAM);
    POWER_ApplyPD();
#endif

#if defined(MIMXRT595S_cm33_SERIES)
    /*Make sure casper ram buffer has power up*/
    POWER_DisablePD(kPDRUNCFG_PPD_CASPER_SRAM);
    POWER_ApplyPD();
#endif

    /* Initialize CASPER */
    CASPER_Init(CASPER);

    casper_init_is_done = true;
}

static void reverse_array(uint8_t *src, size_t src_len)
{
    int i;

    for (i = 0; i < src_len / 2; i++) {
        uint8_t tmp;

        tmp                  = src[i];
        src[i]               = src[src_len - 1 - i];
        src[src_len - 1 - i] = tmp;
    }
}

/******************************************************************************/
/*************************** ECP  *********************************************/
/******************************************************************************/

#include "mbedtls/threading.h"
#include "mbedtls/platform_util.h"

#include <string.h>

// #if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED) || defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
// #error "CASPER hw acceleration supports only SECP256R1, SECP384R1  and SECP521R1."
// #endif

/* CASPER driver allows usage of 256, 384 and 521 ECC */
#define CASPER_MAX_ECC_SIZE_BITS  (521)
#define CASPER_MAX_ECC_SIZE_BYTES (72) /* 32 for 256 bits, 48 for 384 bits and 72 for 521 bits*/

int casper_mbedtls_ecp_mul(mbedtls_ecp_group *grp,
                           mbedtls_ecp_point *R,       // result
                           const mbedtls_mpi *m,       // scalar
                           const mbedtls_ecp_point *P, // X & Y
                           int (*f_rng)(void *, unsigned char *, size_t),
                           void *p_rng) /* TBD: rs_ctx is not used MBEDTLS_ECP_RESTARTABLE is not supported */
{
    // TODO: validate inputs

    size_t size;

    if (casper_init_is_done == false) {
        casper_mbedtls_init();
    }

    size = mbedtls_mpi_size(&grp->P);

    uint32_t M[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)] = { 0 };
    uint32_t X[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)] = { 0 };
    uint32_t Y[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)] = { 0 };

    //* Write MbedTLS mpi coordinates into binary buffer */
    mbedtls_mpi_write_binary(&P->MBEDTLS_PRIVATE(X), (unsigned char *) &X[0], size);
    mbedtls_mpi_write_binary(&P->MBEDTLS_PRIVATE(Y), (unsigned char *) &Y[0], size);

    /* Reverse endianness for CASPER */
    reverse_array((uint8_t *) X, size);
    reverse_array((uint8_t *) Y, size);

    /* Init CASPER */
    if (size == 32) {
        CASPER_ecc_init(kCASPER_ECC_P256);
    }
    if (size == 48) {
        CASPER_ecc_init(kCASPER_ECC_P384);
    }
    if (size == 66) {
        CASPER_ecc_init(kCASPER_ECC_P521);
    }

    if (mbedtls_mpi_size(m) > sizeof(M)) {
        __BKPT(0);
        return MBEDTLS_ERR_ECP_BUFFER_TOO_SMALL;
    }
    mbedtls_mpi_write_binary(m, (void *) M, size);
    reverse_array((void *) M, size);

    if (size == 32) {
        CASPER_ECC_SECP256R1_Mul(CASPER, &X[0], &Y[0], &X[0], &Y[0], (void *) M);
    }

    if (size == 48) {
        CASPER_ECC_SECP384R1_Mul(CASPER, &X[0], &Y[0], &X[0], &Y[0], (void *) M);
    }
    if (size == 66) {
        CASPER_ECC_SECP521R1_Mul(CASPER, &X[0], &Y[0], &X[0], &Y[0], (void *) M);
    }
    /* Reverse results back to MbedTLS format */
    reverse_array((uint8_t *) X, size);
    reverse_array((uint8_t *) Y, size);

    /* Write results into R MPI */
    (void)mbedtls_mpi_read_binary(&R->MBEDTLS_PRIVATE(X), (void *) &X[0], size);
    (void)mbedtls_mpi_read_binary(&R->MBEDTLS_PRIVATE(Y), (void *) &Y[0], size);
    (void)mbedtls_mpi_lset(&R->MBEDTLS_PRIVATE(Z), 1);

    return 0;
}

/*
 * linear combination
 * NOT constant-time
 */
static int casper_mbedtls_ecp_muladd_internal(mbedtls_ecp_group *grp,
                                              mbedtls_ecp_point *R,
                                              const mbedtls_mpi *m,
                                              const mbedtls_ecp_point *P,
                                              const mbedtls_mpi *n,
                                              const mbedtls_ecp_point *Q) /* TBD restartable is not implemented */
{
    uint32_t X1[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)] = { 0 };
    uint32_t Y1[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)] = { 0 };
    uint32_t X2[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)] = { 0 };
    uint32_t Y2[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)] = { 0 };
    uint32_t M[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)]  = { 0 };
    uint32_t N[CASPER_MAX_ECC_SIZE_BYTES / sizeof(uint32_t)]  = { 0 };

    size_t size;

    if (casper_init_is_done == false) {
        casper_mbedtls_init();
    }

    /* shortcut for (m == 1) && (n == 1). this case is point addition. */
    /* this shortcut follows original mbedtls_ecp_muladd() implementation */
    /* and is required for ecjpake_ecp_add3(). */
    // if ((mbedtls_mpi_cmp_int(m, 1) == 0) && (mbedtls_mpi_cmp_int(n, 1) == 0))
    // {
    //     return ecp_add(grp, R, P, Q);
    // }

    /* Write MbedTLS mpi coordinates into binary buffer */
    size = mbedtls_mpi_size(&grp->P);

    mbedtls_mpi_write_binary(&P->MBEDTLS_PRIVATE(X), (unsigned char *) &X1[0], size);
    mbedtls_mpi_write_binary(&P->MBEDTLS_PRIVATE(Y), (unsigned char *) &Y1[0], size);

    reverse_array((uint8_t *) X1, size);
    reverse_array((uint8_t *) Y1, size);

    /* Init CASPER */
    if (size == 32) {
        CASPER_ecc_init(kCASPER_ECC_P256);
    } else if (size == 48) {
        CASPER_ecc_init(kCASPER_ECC_P384);
    } else if (size == 66) {
        CASPER_ecc_init(kCASPER_ECC_P521);
    }
    // TBD assert
    if (mbedtls_mpi_size(m) > sizeof(M)) {
        __BKPT(0);
        return MBEDTLS_ERR_ECP_BUFFER_TOO_SMALL;
    }
    mbedtls_mpi_write_binary(m, (void *) M, size);
    reverse_array((void *) M, size);

    /* Write MbedTLS mpi coordinates into binary bufer */
    mbedtls_mpi_write_binary(&Q->MBEDTLS_PRIVATE(X), (unsigned char *) &X2[0], size);
    mbedtls_mpi_write_binary(&Q->MBEDTLS_PRIVATE(Y), (unsigned char *) &Y2[0], size);

    reverse_array((uint8_t *) X2, size);
    reverse_array((uint8_t *) Y2, size);

    if (mbedtls_mpi_size(n) > sizeof(N)) {
        __BKPT(0);
        return MBEDTLS_ERR_ECP_BUFFER_TOO_SMALL;
    }
    mbedtls_mpi_write_binary(n, (void *) N, size);
    reverse_array((void *) N, size);

    if (size == 32) {
        CASPER_ECC_SECP256R1_MulAdd(CASPER, &X1[0], &Y1[0], &X1[0], &Y1[0], (void *) M, &X2[0],
                                    &Y2[0], (void *) N);
    } else if (size == 48) {
        CASPER_ECC_SECP384R1_MulAdd(CASPER, &X1[0], &Y1[0], &X1[0], &Y1[0], (void *) M, &X2[0],
                                    &Y2[0], (void *) N);
    } else if (size == 66) {
        CASPER_ECC_SECP521R1_MulAdd(CASPER, &X1[0], &Y1[0], &X1[0], &Y1[0], (void *) M, &X2[0],
                                    &Y2[0], (void *) N);
    }
    // TBD assert

    /* Reverse results back to MbedTLS format */
    reverse_array((uint8_t *) X1, size);
    reverse_array((uint8_t *) Y1, size);

    /* Write results into R MPI */
    (void)mbedtls_mpi_read_binary(&R->MBEDTLS_PRIVATE(X), (void *) &X1[0], size);
    (void)mbedtls_mpi_read_binary(&R->MBEDTLS_PRIVATE(Y), (void *) &Y1[0], size);
    (void)mbedtls_mpi_lset(&R->MBEDTLS_PRIVATE(Z), 1);

    return 0;
}

/*
 * Linear combination
 * NOT constant-time
 */
int casper_mbedtls_ecp_muladd(mbedtls_ecp_group *grp,
                              mbedtls_ecp_point *R,
                              const mbedtls_mpi *m,
                              const mbedtls_ecp_point *P,
                              const mbedtls_mpi *n,
                              const mbedtls_ecp_point *Q)
{
    if (grp == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    if (R == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    if (m == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    if (P == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    if (n == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    if (Q == NULL) {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    return casper_mbedtls_ecp_muladd_internal(grp, R, m, P, n, Q);
}

#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ECP_C && (SECP256R1 || SECP384R1 || SECP521R1) */
