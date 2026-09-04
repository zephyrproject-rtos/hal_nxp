/*
 * Copyright 2024-2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability (single-part only, multi-part (not supported in ele) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_s2xx_init.h"
#include "mcux_psa_s2xx_cipher.h"
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"

static psa_status_t translate_psa_cipher_to_ele_cipher(const psa_key_attributes_t *attributes,
                                                 psa_algorithm_t alg,
                                                 sss_algorithm_t *ele_algo)
{
    psa_status_t status     = PSA_ERROR_NOT_SUPPORTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);

    /* Prevent having unused variables in case the PSA_WANTs are disabled */
    (void) key_type;

#if defined(PSA_WANT_KEY_TYPE_AES)
    if (PSA_KEY_TYPE_AES == key_type)
    {
        status = PSA_SUCCESS;
        switch (alg)
        {
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
            case PSA_ALG_CBC_NO_PADDING:
                *ele_algo = kAlgorithm_SSS_AES_CBC;
                break;
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
            case PSA_ALG_ECB_NO_PADDING:
                *ele_algo = kAlgorithm_SSS_AES_ECB;
                break;
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
#if defined(PSA_WANT_ALG_CTR)
            case PSA_ALG_CTR:
                *ele_algo = kAlgorithm_SSS_AES_CTR;
                break;
#endif /* PSA_WANT_ALG_CTR */
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    }
#endif /* PSA_WANT_KEY_TYPE_AES */

    return status;
}

/** \defgroup psa_cipher PSA transparent key driver entry points for ciphers
 *
 *  Entry points for cipher operations as described by the PSA Cryptoprocessor
 *  Driver interface specification
 *
 *  @{
 */
psa_status_t ele_s2xx_transparent_cipher_encrypt(const psa_key_attributes_t *attributes,
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
    psa_status_t status     = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);

    sss_algorithm_t ele_algo = 0;
    sss_sscp_object_t sssKey = {0};

    /* Key buffer or size can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Wrapcheck for `PSA_BYTES_TO_BITS(key_buffer_size)` */
    if (true == mcux_psa_mul_size_t_wrapcheck(key_buffer_size, 8u))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute */
    if (PSA_BYTES_TO_BITS(key_buffer_size) != key_bits)
    {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm needs to be a CIPHER algo */
    if (false == PSA_ALG_IS_CIPHER(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* IV buffer can't be NULL or size 0 for these algorithms */
    if (PSA_ALG_CBC_NO_PADDING == alg ||
        PSA_ALG_CTR == alg)
    {
        if (NULL == iv || 0u == iv_length)
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* PSA specification is not very clear on 0 input for ECB.
     * However software implementation and the tests return SUCCESS
     * for 0 input. So adding this check here and returning early.
     */
    if (PSA_ALG_ECB_NO_PADDING == alg && 0u == input_length)
    {
        *output_length = 0u;
        return PSA_SUCCESS;
    }

    status = translate_psa_cipher_to_ele_cipher(attributes, alg, &ele_algo);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* If input length or input buffer NULL, it;s an error.
     * Special case for ECB where input = 0 may be allowed.
     * Taken care of in above code.
     */
    if (NULL == input || 0u == input_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer has to be atleast Input buffer size */
    if (output_size < input_length)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Output buffer can't be NULL */
    if (NULL == output || NULL == output_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* For CBC and ECB No padding, input length has to be multiple of cipher block length */
    /* coverity[misra_c_2012_rule_10_1_violation]: PSA macro performs bitwise ops on unsigned type as required */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_7_violation]: composite expression implicitly converted as required */
    if ((alg == PSA_ALG_CBC_NO_PADDING || alg == PSA_ALG_ECB_NO_PADDING) &&
        (0u != (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type))))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_set_key(&sssKey, 0u,  /* key id */
                              key_buffer, key_buffer_size, kSSS_KeyPart_Default,
                              kSSS_CipherType_AES, kSSS_KeyProp_CryptoAlgo_AES,
                              key_buffer_size, key_bits);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    status = ele_s2xx_common_cipher(&sssKey, iv, iv_length, input, output,
                                    input_length, ele_algo, kMode_SSS_Encrypt);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *output_length = input_length;

exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_transparent_cipher_decrypt(const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg,
                                                 const uint8_t *input,
                                                 size_t input_length,
                                                 uint8_t *output,
                                                 size_t output_size,
                                                 size_t *output_length)
{
    psa_status_t status     = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);

    sss_algorithm_t ele_algo = 0;
    sss_sscp_object_t sssKey = {0};

    uint32_t iv_length          = 0u;
    uint32_t expected_op_length = 0u;

    /* Wrapcheck for `PSA_BYTES_TO_BITS(key_buffer_size)` */
    if (true == mcux_psa_mul_size_t_wrapcheck(key_buffer_size, 8u))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (PSA_BYTES_TO_BITS(key_buffer_size) != key_bits)
    {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (false == PSA_ALG_IS_CIPHER(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* PSA specification is not very clear on 0 input for ECB.
     * However software implementation and the tests return SUCCESS
     * for 0 input. So adding this check here and returning early.
     */
    if (PSA_ALG_ECB_NO_PADDING == alg && 0u == input_length)
    {
        *output_length = 0u;
        return PSA_SUCCESS;
    }

    status = translate_psa_cipher_to_ele_cipher(attributes, alg, &ele_algo);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* If input length or input buffer NULL, it;s an error.
     * Special case for ECB where input = 0 may be allowed.
     * Taken care of in above code.
     */
    if (NULL == input || 0u == input_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer can't be NULL */
    if (NULL == output || NULL == output_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Input length has to be multiple of block size for decrypt operation */
    /* coverity[misra_c_2012_rule_10_1_violation]: PSA macro performs bitwise ops on unsigned type as required */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_7_violation]: composite expression implicitly converted as required */
    if ((alg == PSA_ALG_CBC_NO_PADDING || alg == PSA_ALG_ECB_NO_PADDING) &&
        (0u != (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type))))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Find the IV length for key type and algorithm */
    /* coverity[misra_c_2012_rule_10_1_violation]: PSA macro performs bitwise ops on unsigned type as required */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro operands have compatible essential types */
    /* coverity[misra_c_2012_rule_10_6_violation]: composite expression assigned to wider type as required */
    iv_length = PSA_CIPHER_IV_LENGTH(key_type, alg);

    /* Input buffer -> IV + INPUT.
     * So output length would be (input - iv_length)
     */
    expected_op_length = input_length - iv_length;

    if (output_size < expected_op_length)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_set_key(&sssKey, 0u,  /* key id */
                              key_buffer, key_buffer_size, kSSS_KeyPart_Default,
                              kSSS_CipherType_AES, kSSS_KeyProp_CryptoAlgo_AES,
                              key_buffer_size, key_bits);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    status = ele_s2xx_common_cipher(&sssKey, input, iv_length, (input + iv_length),
                                    output, input_length, ele_algo, kMode_SSS_Decrypt);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *output_length = expected_op_length;

exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
/** @} */ // end of psa_cipher
