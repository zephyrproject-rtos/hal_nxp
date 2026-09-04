/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_dcp_entropy.c
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

#include "mcux_psa_dcp_entropy.h"
#include "fsl_trng.h"

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "psa/crypto_driver_random.h"
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

static mcux_mutex_t *s_mutex = NULL;

psa_status_t mcux_psa_dcp_entropy_init(mcux_mutex_t *mutex)
{
    trng_config_t config;

    (void)TRNG_GetDefaultConfig(&config);
    config.sampleMode = kTRNG_SampleModeVonNeumann;

    if (kStatus_Success != TRNG_Init(TRNG, (void *)&config))
    {
        return PSA_ERROR_HARDWARE_FAILURE;
    }

    s_mutex = mutex;

    return PSA_SUCCESS;
}

void mcux_psa_dcp_entropy_deinit(void)
{
    TRNG_Deinit(TRNG);

    s_mutex = NULL;
}

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator in a
 *  different (slower) clock domain
 *
 *  @{
 */
psa_status_t mcux_psa_dcp_entropy_get(uint32_t flags,
                                      size_t *estimate_bits,
                                      uint8_t *output,
                                      size_t output_size)
{
    (void)flags; /* Unused */

    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if ((NULL == output) || (NULL == estimate_bits) || (0u == output_size))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    *estimate_bits = 0u;

    if (mcux_mutex_lock(s_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (kStatus_Success != TRNG_GetRandomData(TRNG, output, output_size))
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
    }
    else
    {
        status = PSA_SUCCESS;
    }

    if (mcux_mutex_unlock(s_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (PSA_SUCCESS == status)
    {
        *estimate_bits = output_size * 8u;
    }

    return status;
}
/** @} */ // end of psa_entropy

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) && !defined(__ZEPHYR__) 
int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return mcux_psa_dcp_entropy_get((uint32_t)flags, estimate_bits, output, output_size);
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
    size_t estimate_bits = 0u;
    psa_status_t status  = mcux_psa_dcp_entropy_get(0u, &estimate_bits, output, len);

    *olen = estimate_bits / 8u;

    return status;
}
