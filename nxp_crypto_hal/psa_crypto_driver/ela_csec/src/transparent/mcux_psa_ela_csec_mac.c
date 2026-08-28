/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ela_csec_mac.c
 *
 * This file contains the implementation of the entry points associated to the
 * mac capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_ela_csec_init.h"
#include "mcux_psa_ela_csec_mac.h"

psa_status_t ela_csec_transparent_mac_compute(const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *input,
                                              size_t input_length,
                                              uint8_t *mac,
                                              size_t mac_size,
                                              size_t *mac_length)
{
    psa_status_t status              = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type          = psa_get_key_type(attributes);
    size_t key_bits                  = psa_get_key_bits(attributes);
    uint8_t zeros[ELA_CSEC_KEY_SIZE] = {0u};

    /* Key buffer or size or mac buffer or mac length can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size ||
        NULL == mac        || NULL == mac_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm must be a MAC algorithm */
    if (false == PSA_ALG_IS_MAC(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Support for AES CMAC with 128bit keys */
    if ((PSA_KEY_TYPE_AES != key_type)
        || (128u != key_bits)
        || (PSA_ALG_CMAC != alg))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Check MAC output buffer size */
    if (mac_size < PSA_MAC_LENGTH(key_type, key_bits, alg))
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ela_csec_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Load the transparent key */
    if (CSEC_DRV_LoadPlainKey(key_buffer) != kStatus_Success)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit;
    }

    /* Generate MAC */
    if (CSEC_DRV_GenerateMAC(CSEC_RAM_KEY, input, PSA_BYTES_TO_BITS(input_length), mac, ELA_CSEC_CALL_TIMEOUT) != kStatus_Success)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit;
    }

    /* All went well, set retvals */
    *mac_length = PSA_MAC_LENGTH(key_type, key_bits, alg);
    status      = PSA_SUCCESS;

exit:
    /* Explicitly zeroize and load into CSEc.
     * Best effort step, not checking retval. */
    memset(zeros, 0, sizeof(zeros));
    (void)CSEC_DRV_LoadPlainKey(zeros);

    if (mcux_mutex_unlock(&ela_csec_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
