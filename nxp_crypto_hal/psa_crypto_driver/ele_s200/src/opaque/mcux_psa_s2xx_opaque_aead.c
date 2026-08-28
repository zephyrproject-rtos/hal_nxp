/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_opaque_aead.c
 *
 * This file contains the implementation of the entry points associated to the
 * AEAD capability (single-part only, multi-part (not supported in ele) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */
#include "mcux_psa_s2xx_common_init.h"
#include "mcux_psa_s2xx_opaque_aead.h"
#include "mcux_psa_s2xx_key_locations.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

/* Number of valid tag lengths sizes both for CCM and GCM modes */
#define VALID_TAG_LENGTH_SIZE 7u

static psa_status_t translate_psa_aead_to_ele_aead(psa_algorithm_t alg, psa_key_type_t key_type, sss_algorithm_t *ele_alg)
{
    psa_status_t status                             = PSA_ERROR_NOT_SUPPORTED;
    /* coverity[misra_c_2012_rule_12_2_violation] */
    /* coverity[misra_c_2012_rule_10_1_violation] */
    /* coverity[misra_c_2012_rule_10_4_violation]: PSA macro contains shift/type issues */
    psa_algorithm_t default_alg                     = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);
    size_t tag_length                               = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);
    size_t valid_tag_lengths[VALID_TAG_LENGTH_SIZE] = {0u};

    /* Prevent having unused variables in case the PSA_WANTs are disabled */
    (void) default_alg;
    (void) tag_length;
    (void) valid_tag_lengths;

#if defined(PSA_WANT_KEY_TYPE_AES)
    if (PSA_KEY_TYPE_AES == key_type)
    {
        status = PSA_SUCCESS;
        switch (default_alg)
        {
#if defined(PSA_WANT_ALG_CCM)
            case PSA_ALG_CCM:
                valid_tag_lengths[0] = 4;
                valid_tag_lengths[1] = 6;
                valid_tag_lengths[2] = 8;
                valid_tag_lengths[3] = 10;
                valid_tag_lengths[4] = 12;
                valid_tag_lengths[5] = 14;
                valid_tag_lengths[6] = 16;
                *ele_alg             = kAlgorithm_SSS_AES_CCM;
                break;
#endif /* PSA_WANT_ALG_CCM */
#if defined(PSA_WANT_ALG_GCM)
            case PSA_ALG_GCM:
                valid_tag_lengths[0] = 4;
                valid_tag_lengths[1] = 8;
                valid_tag_lengths[2] = 12;
                valid_tag_lengths[3] = 13;
                valid_tag_lengths[4] = 14;
                valid_tag_lengths[5] = 15;
                valid_tag_lengths[6] = 16;
                *ele_alg             = kAlgorithm_SSS_AES_GCM;
                break;
#endif /* PSA_WANT_ALG_GCM */
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    }
#endif /* PSA_WANT_KEY_TYPE_AES */

    /* If we fail here, it means the key type or algorithm is unsupported.
     * Else we continue to also check tag lengths.
     */
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Cycle through all valid tag lengths for CCM or GCM */
    uint32_t i;
    for (i = 0u; i < VALID_TAG_LENGTH_SIZE; i++)
    {
        if (tag_length == valid_tag_lengths[i])
        {
            break;
        }
    }

    if (i == VALID_TAG_LENGTH_SIZE)
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
    }

    return status;
}

static status_t ele_s2xx_aead_arg_validation(const psa_key_attributes_t *attributes,
                                             const uint8_t *key_buffer, size_t key_buffer_size,
                                             const uint8_t *nonce, size_t nonce_length,
                                             psa_algorithm_t alg)
{
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_7_2_violation]: PSA macro contains unsigned literal 2147483648U without U suffix */
    /* Check permissions for EL2GO keys, as those checks were skipped in common layer */
    if (true == PSA_ALG_IS_VENDOR_DEFINED(psa_get_key_algorithm(attributes)))
    {
        if (ALG_NXP_ALL_AEAD != psa_get_key_algorithm(attributes))
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* Algorithm needs to be a AEAD algo */
    if (false == PSA_ALG_IS_AEAD(alg))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key buffer or size can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == nonce || 0u == nonce_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return PSA_SUCCESS;
}

/** \defgroup psa_aead_opaque PSA opaque key driver entry points for AEAD
 *
 *  Entry points for AEAD encryption and decryption as described by the PSA
 *  Cryptoprocessor Driver interface specification with the use of opaque keys
 *
 *  @{
 */
psa_status_t ele_s2xx_opaque_aead_encrypt(const psa_key_attributes_t *attributes,
                                          const uint8_t *key_buffer, size_t key_buffer_size,
                                          psa_algorithm_t alg,
                                          const uint8_t *nonce, size_t nonce_length,
                                          const uint8_t *additional_data, size_t additional_data_length,
                                          const uint8_t *plaintext, size_t plaintext_length,
                                          uint8_t *ciphertext, size_t ciphertext_size,
                                          size_t *ciphertext_length)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type  = psa_get_key_type(attributes);
    sss_algorithm_t ele_alg  = 0;
    sss_sscp_object_t sssKey = {0};
    uint8_t *tag             = NULL;
    size_t tag_length        = 0u;

    /* Validate the algorithm first */
    status = translate_psa_aead_to_ele_aead(alg, key_type, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Validate inputs */
    status = ele_s2xx_aead_arg_validation(attributes, key_buffer, key_buffer_size, nonce, nonce_length, alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

#if !defined(ELE200_EXTENDED_FEATURES)
    /* KW45 S200 doesn't support plaintext length 0 CCM */
    if ((0u == plaintext_length) &&
        (PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg) == PSA_ALG_CCM))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }
#endif

    /* Get the TAG length encoded in the algorithm */
    tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);

    /* No check for input and additional data as 0 value for these is allowed */

    /* Wrapcheck for `plaintext_length + tag_length` */
    if (true == mcux_psa_add_size_t_wrapcheck(plaintext_length, tag_length))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer has to be atleast Input buffer size  -> Check for encrypt */
    if (ciphertext_size < (plaintext_length + tag_length))
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Output buffer can't be NULL */
    if (NULL == ciphertext || NULL == ciphertext_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    *ciphertext_length = 0u;

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* Do AEAD */
    tag    = (uint8_t *)(ciphertext + plaintext_length);
    status = ele_s2xx_common_aead(nonce, nonce_length,
                                  additional_data, additional_data_length,
                                  plaintext, plaintext_length, ciphertext,
                                  tag, &tag_length,
                                  kMode_SSS_Encrypt, &sssKey, ele_alg);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *ciphertext_length = plaintext_length + tag_length;

exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_opaque_aead_decrypt(const psa_key_attributes_t *attributes,
                                          const uint8_t *key_buffer, size_t key_buffer_size,
                                          psa_algorithm_t alg,
                                          const uint8_t *nonce, size_t nonce_length,
                                          const uint8_t *additional_data, size_t additional_data_length,
                                          const uint8_t *ciphertext, size_t ciphertext_length,
                                          uint8_t *plaintext, size_t plaintext_size,
                                          size_t *plaintext_length)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type  = psa_get_key_type(attributes);
    sss_algorithm_t ele_alg  = 0;
    sss_sscp_object_t sssKey = {0};
    size_t tag_length        = 0;
    uint8_t *tag             = NULL;
    size_t cipher_length     = 0;

    /* Validate the algorithm first */
    status = translate_psa_aead_to_ele_aead(alg, key_type, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Validate inputs */
    status = ele_s2xx_aead_arg_validation(attributes, key_buffer, key_buffer_size, nonce, nonce_length, alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Get the TAG length encoded in the algorithm */
    tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);

    /* Input Buffer or size can't be NULL */
    if (NULL == ciphertext || 0u == ciphertext_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* ciphertext has cipher + tag */
    cipher_length = ciphertext_length - tag_length;

#if !defined(ELE200_EXTENDED_FEATURES)
    /* KW45 S200 doesn't support cipher length 0 CCM */
    if ((0u == cipher_length) &&
        (PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg) == PSA_ALG_CCM))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }
#endif

    if (plaintext_size < cipher_length)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Input buffer i.e plaintext or AAD is allowed to be 0 in encrypt
     * Operation. Hence output of a decrypt can be of size 0. Hence no
     * check involving plaintext buffer.
     */

    *plaintext_length = 0;

    /* Tag is at the end of ciphertext */
    /* coverity[misra_c_2012_rule_11_8_violation]: ciphertext is const but tag buffer at end requires non-const pointer */
    tag = (uint8_t *)(ciphertext + cipher_length);

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* Do AEAD */
    status = ele_s2xx_common_aead(nonce, nonce_length,
                                  additional_data, additional_data_length,
                                  ciphertext, cipher_length, plaintext,
                                  tag, &tag_length,
                                  kMode_SSS_Decrypt, &sssKey, ele_alg);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *plaintext_length = cipher_length;

exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

/** @} */ // end of psa_aead_opaque
