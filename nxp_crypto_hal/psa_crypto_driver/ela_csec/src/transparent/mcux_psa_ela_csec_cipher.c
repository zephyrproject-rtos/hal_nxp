/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ela_csec_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_ela_csec_init.h"
#include "mcux_psa_ela_csec_cipher.h"

psa_status_t ela_csec_transparent_cipher_encrypt(const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg,
                                                 const uint8_t *iv,
                                                 size_t iv_length,
                                                 const uint8_t *input,
                                                 size_t input_length,
                                                 uint8_t *output,
                                                 size_t output_size,
                                                 size_t *output_length)
{
    psa_status_t status              = PSA_ERROR_CORRUPTION_DETECTED;
    status_t csec_status             = kStatus_Fail;
    psa_key_type_t key_type          = psa_get_key_type(attributes);
    size_t key_bits                  = psa_get_key_bits(attributes);
    uint8_t zeros[ELA_CSEC_KEY_SIZE] = {0u};

    /* Key buffer or size or output buffer or output length can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size ||
        NULL == output     || NULL == output_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm must be a CIPHER algorithm */
    if (false == PSA_ALG_IS_CIPHER(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Support for AES with 128bit keys */
    if ((PSA_KEY_TYPE_AES != key_type) || (128u != key_bits))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Nopad CBC and ECB supported */
    if ((PSA_ALG_CBC_NO_PADDING != alg) && (PSA_ALG_ECB_NO_PADDING != alg))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* For CBC we check for IV length, else we don't care */
    if ((PSA_ALG_CBC_NO_PADDING == alg) && (PSA_CIPHER_IV_LENGTH(key_type, alg) != iv_length))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* CSEc does not pad internally, so the input must be a multiple
     * of an AES block length
     */
    if (0u != (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check output buffer size */
    if (output_size < PSA_CIPHER_ENCRYPT_OUTPUT_SIZE(key_type, alg, input_length))
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

    /* Do the encryption */
    csec_status = kStatus_Success;
    status      = PSA_SUCCESS;
    switch (alg)
    {
        case PSA_ALG_ECB_NO_PADDING:
            csec_status = CSEC_DRV_EncryptECB(CSEC_RAM_KEY, input, input_length,
                                              output, ELA_CSEC_CALL_TIMEOUT);
            break;
        case PSA_ALG_CBC_NO_PADDING:
            csec_status = CSEC_DRV_EncryptCBC(CSEC_RAM_KEY, input, input_length,
                                              iv, output, ELA_CSEC_CALL_TIMEOUT);
            break;
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }
    if (kStatus_Success != csec_status)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit;
    }

    /* Only those algorithms are supported,
     * for which input and output lengths are equal
     */
    *output_length = input_length;

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

psa_status_t ela_csec_transparent_cipher_decrypt(const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg,
                                                 const uint8_t *input,
                                                 size_t input_length,
                                                 uint8_t *output,
                                                 size_t output_size,
                                                 size_t *output_length)
{
    psa_status_t status              = PSA_ERROR_CORRUPTION_DETECTED;
    status_t csec_status             = kStatus_Fail;
    psa_key_type_t key_type          = psa_get_key_type(attributes);
    size_t key_bits                  = psa_get_key_bits(attributes);
    size_t iv_length                 = PSA_CIPHER_IV_LENGTH(key_type, alg);
    const uint8_t *iv                = input;
    size_t ipnut_length_no_iv        = input_length - iv_length;
    uint8_t zeros[ELA_CSEC_KEY_SIZE] = {0u};

    /* Key buffer or size or output buffer or output length can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size ||
        NULL == output     || NULL == output_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm must be a CIPHER algorithm */
    if (false == PSA_ALG_IS_CIPHER(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Support for AES with 128bit keys */
    if ((PSA_KEY_TYPE_AES != key_type) || (128u != key_bits))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Nopad CBC and ECB supported */
    if ((PSA_ALG_CBC_NO_PADDING != alg) && (PSA_ALG_ECB_NO_PADDING != alg))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* CSEc does not pad internally, so the input must be a multiple
     * of an AES block length
     */
    if (0u != (ipnut_length_no_iv % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check output buffer size */
    if (output_size < PSA_CIPHER_DECRYPT_OUTPUT_SIZE(key_type, alg, ipnut_length_no_iv))
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

    /* Do the decryption */
    csec_status = kStatus_Success;
    status      = PSA_SUCCESS;
    switch (alg)
    {
        case PSA_ALG_ECB_NO_PADDING:
            csec_status = CSEC_DRV_DecryptECB(CSEC_RAM_KEY, input, ipnut_length_no_iv,
                                              output, ELA_CSEC_CALL_TIMEOUT);
            break;
        case PSA_ALG_CBC_NO_PADDING:
            csec_status = CSEC_DRV_DecryptCBC(CSEC_RAM_KEY, input + iv_length,
                                              ipnut_length_no_iv, iv, output,
                                              ELA_CSEC_CALL_TIMEOUT);
            break;
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }
    if (kStatus_Success != csec_status)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit;
    }

    *output_length = PSA_CIPHER_DECRYPT_OUTPUT_SIZE(key_type, alg, ipnut_length_no_iv);

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
