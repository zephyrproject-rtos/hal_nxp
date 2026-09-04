/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_entropy.c
 *
 * This file contains the implementation of the entry points associated
 * to the entropy capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#include "mbedtls/build_info.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "psa/crypto_driver_random.h"
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

#include "mcux_psa_caam_entropy.h"
#include "mcux_psa_caam_init.h"

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator in a
 *  different (slower) clock domain
 *
 *  @{
 */
psa_status_t caam_get_entropy(uint32_t flags,
                              size_t *estimate_bits,
                              uint8_t *output,
                              size_t output_size)
{
    status_t result           = kStatus_Success;
    psa_status_t err          = PSA_ERROR_CORRUPTION_DETECTED;
    psa_status_t err2         = PSA_SUCCESS;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };

    if (output == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (estimate_bits == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    *estimate_bits = 0u;

    if (output_size == 0u) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        err  = PSA_ERROR_SERVICE_FAILURE;
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    result = CAAM_RNG_GetRandomData(PSA_CAAM,
                                    &caam_handle,
                                    kCAAM_RngStateHandle0,
                                    (uint8_t *) output,
                                    output_size,
                                    kCAAM_RngDataAny,
                                    NULL);
    err    = caam_to_psa_status(result);

    if ((err2 == PSA_SUCCESS) &&
        (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0)) {
        err2 = PSA_ERROR_SERVICE_FAILURE;
    }

    if (err2 != PSA_SUCCESS) {
        return err2;
    }

    if (err == PSA_SUCCESS) {
        *estimate_bits = output_size * 8;
    }

    return err;
}
/** @} */ // end of psa_entropy

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) && !defined(__ZEPHYR__)
int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return caam_get_entropy((uint32_t)flags, estimate_bits, output, output_size);
}
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

/*
 * FixMe: This function is required to integrate into Mbed TLS as the PSA
 * subsystem does not yet support entropy entry points. See the header
 * entropy_poll.h for details. This needs to be revised once Mbed TLS adds
 * support for entropy.
 */
int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
    size_t estimate_bits  = 0u;
    psa_status_t status = caam_get_entropy(0, &estimate_bits, output, len);

    *olen = estimate_bits / 8;

    return status;
}
