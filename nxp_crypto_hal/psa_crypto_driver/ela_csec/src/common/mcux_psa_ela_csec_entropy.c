/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ela_csec_entropy.c
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

#include "mcux_psa_ela_csec_entropy.h"

#define ELA_CSEC_RANDOM_SIZE (16u)

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification.
 *
 *  @{
 */
psa_status_t ela_csec_get_entropy(uint32_t flags, size_t *estimate_bits, uint8_t *output, size_t output_size)
{
    status_t result                       = kStatus_Success;
    psa_status_t status                   = PSA_ERROR_CORRUPTION_DETECTED;
    uint8_t rnd_buf[ELA_CSEC_RANDOM_SIZE] = {0u};
    size_t full_iterations                = 0u;
    size_t remainder                      = 0u;

    if ((NULL == output) || (NULL == estimate_bits) || (0u == output_size))
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    if (mcux_mutex_lock(&ela_csec_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* CSEc can do 128bit blocks of random data per call. Do the max number
     * of full 128bit iterations + one last incomplete block, if needed.
     */
    full_iterations = output_size / ELA_CSEC_RANDOM_SIZE;
    remainder       = output_size % ELA_CSEC_RANDOM_SIZE;

    for (size_t i = 0u; i < full_iterations; i++)
    {
        result = CSEC_DRV_GenerateRND(rnd_buf);
        if (kStatus_Success != result)
        {
            status = ela_csec_to_psa_status(result);
            goto exit;
        }

        (void)memcpy(output + (i * ELA_CSEC_RANDOM_SIZE), rnd_buf, ELA_CSEC_RANDOM_SIZE);
    }

    if (0u != remainder)
    {
        /* Handle last, incomplete, block */
        result = CSEC_DRV_GenerateRND(rnd_buf);

        (void)memcpy(output + (full_iterations * ELA_CSEC_RANDOM_SIZE), rnd_buf, remainder);
    }

    if (mcux_mutex_unlock(&ela_csec_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ela_csec_to_psa_status(result);

    if (status == PSA_SUCCESS)
    {
        *estimate_bits = output_size * 8u;
        status         = PSA_SUCCESS;
    }

exit:
    return status;
}
/** @} */ // end of psa_entropy

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return ela_csec_get_entropy((uint32_t)flags, estimate_bits, output, output_size);
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
    (void)data; /* Unused */

    size_t estimate_bits = 0u;
    int status           = ela_csec_get_entropy(0u, &estimate_bits, output, len);

    *olen = estimate_bits / 8u;

    return status;
}
