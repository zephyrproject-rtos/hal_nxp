/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_opaque_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability (single-part only, multi-part (not supported in ele) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_s2xx_common_init.h"
#include "mcux_psa_s2xx_opaque_cipher.h"
#include "mcux_psa_s2xx_key_locations.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_s2xx_common_compute.h"

static psa_status_t psa_to_s200_alg(psa_key_type_t key_type, psa_algorithm_t alg, sss_algorithm_t *ele_algo)
{
    psa_status_t status = PSA_ERROR_NOT_SUPPORTED;

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

static psa_status_t ele_s2xx_cipher_arg_validation(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *iv,
    size_t iv_length,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length,
    sss_mode_t mode)
{
    /* Key buffer or size can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm needs to be a CIPHER algo */
    if (false == PSA_ALG_IS_CIPHER(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_7_2_violation]: PSA_ALG_IS_VENDOR_DEFINED uses 2147483648U literal without U suffix */
    /* Check permissions for EL2GO keys, as those checks were skipped in common layer */
    if (true == PSA_ALG_IS_VENDOR_DEFINED(psa_get_key_algorithm(attributes)))
    {
        if (ALG_NXP_ALL_CIPHER != psa_get_key_algorithm(attributes))
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* Special validation cases for encryption */
    if (kMode_SSS_Encrypt == mode)
    {
        /* Output buffer has to be atleast Input buffer size */
        if (output_size < input_length)
        {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }

        /* IV buffer can't be NULL or size 0 */
        if ((PSA_ALG_CBC_NO_PADDING == alg) || (PSA_ALG_CTR == alg))
        {
            if (NULL == iv || 0u == iv_length)
            {
                return PSA_ERROR_INVALID_ARGUMENT;
            }
        }
    }

    /* If input length or input buffer NULL, it's an error.
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

    /* For CBC and ECB No padding, input length has to be multiple of cipher block length */
    /* coverity[misra_c_2012_rule_10_1_violation] */
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_7_violation]: PSA_BLOCK_CIPHER_BLOCK_LENGTH macro contains shift/type issues */
    if ((alg == PSA_ALG_CBC_NO_PADDING || alg == PSA_ALG_ECB_NO_PADDING) &&
        (0u != (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(psa_get_key_type(attributes)))))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return PSA_SUCCESS;
}

/** \defgroup psa_cipher_opaque PSA opaque key driver entry points for ciphers
 *
 *  Entry points for cipher operations as described by the PSA Cryptoprocessor
 *  Driver interface specification with the use of opaque keys
 *
 *  @{
 */
psa_status_t ele_s2xx_opaque_cipher_encrypt(
    const psa_key_attributes_t *attributes,
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
    psa_key_type_t key_type = psa_get_key_type(attributes);
    psa_status_t status     = PSA_ERROR_CORRUPTION_DETECTED;

    sss_algorithm_t ele_algo = 0;
    sss_sscp_object_t sssKey = {0};

    status = psa_to_s200_alg(key_type, alg, &ele_algo);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = ele_s2xx_cipher_arg_validation(attributes, key_buffer,
                                            key_buffer_size, alg, iv, iv_length,
                                            input, input_length, output,
                                            output_size, output_length,
                                            kMode_SSS_Encrypt);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* PSA specification is not very clear on 0 input for ECB.
     * However software implementation and the tests return SUCCESS
     * for 0 input. So adding this check here.
     */
    if ((PSA_ALG_ECB_NO_PADDING == alg) && (0u == input_length))
    {
        *output_length = 0;
        return PSA_SUCCESS;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
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

psa_status_t ele_s2xx_opaque_cipher_decrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length)
{
    psa_key_type_t key_type = psa_get_key_type(attributes);
    psa_status_t status     = PSA_ERROR_CORRUPTION_DETECTED;

    sss_algorithm_t ele_algo = 0;
    sss_sscp_object_t sssKey = {0};

    uint32_t iv_length          = 0;
    uint32_t expected_op_length = 0;

    status = psa_to_s200_alg(key_type, alg, &ele_algo);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    status = ele_s2xx_cipher_arg_validation(attributes, key_buffer,
                                            key_buffer_size, alg, NULL, 0,
                                            input, input_length, output,
                                            output_size, output_length,
                                            kMode_SSS_Decrypt);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* PSA specification is not very clear on 0 input for ECB.
     * However software implementation and the tests return SUCCESS
     * for 0 input. So adding this check here.
     */
    if ((PSA_ALG_ECB_NO_PADDING == alg) && (0u == input_length))
    {
        *output_length = 0u;
        return PSA_SUCCESS;
    }

    /* Find the IV length for key type and algorithm */
    /* coverity[misra_c_2012_rule_10_1_violation] */
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_6_violation]: PSA_CIPHER_IV_LENGTH macro contains shift/type issues */
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

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
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

/** @} */ // end of psa_cipher_opaque
