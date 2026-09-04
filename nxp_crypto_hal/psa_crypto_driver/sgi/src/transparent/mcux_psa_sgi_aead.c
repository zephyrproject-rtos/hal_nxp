/*
 * Copyright 2025 - 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_sgi_aead.c
 *
 * This file contains the implementations of the entry points associated to the
 * aead capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification.
 *
 */

#include "mcux_psa_sgi_init.h"
#include "mcux_psa_sgi_aead.h"
#include "mcux_psa_sgi_common_key_management.h"

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "tf-psa-crypto/build_info.h"
#else
/* This is for backwards compatibility with MbedTLS 3.x. Post-MbedTLS 3.x this
 * include would only work iff we forced MbedTLS to be built with TF PSA Crypto,
 * which is not a given, since PSA core (TF PSA Crypto) no longer has a hard
 * dependency on MbedTLS >= 4.
 */
#include "mbedtls/build_info.h"
#endif

#include <mcuxClAead.h>
#include <mcuxClAeadModes.h>

#include <internal/mcuxClAeadModes_Sgi_Types.h>

static inline psa_status_t check_tag_length(const psa_algorithm_t alg)
{
#if defined(PSA_WANT_ALG_CCM) || defined(PSA_WANT_ALG_GCM)
    uint32_t tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);
#endif /* PSA_WANT_ALG_CCM || PSA_WANT_ALG_GCM */

    /* Recover default algorithm (could be CCM with changed tag size) */
    psa_algorithm_t algDefault = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);

    psa_status_t status = PSA_SUCCESS;

    switch (algDefault) {
#if defined(PSA_WANT_ALG_CCM)
        case PSA_ALG_CCM:
            /* Add checks for valid CCM tag length, otherwise return error*/
            if ((tag_length < 4u) || (tag_length > 16u) || (tag_length % 2u != 0u)) {
                status = PSA_ERROR_INVALID_ARGUMENT;
            }
            break;
#endif /* PSA_WANT_ALG_CCM */

#if defined(PSA_WANT_ALG_GCM)
        case PSA_ALG_GCM:
            /* Add checks for valid GCM tag length, otherwise return error*/
            if ((4u != tag_length) && (8u != tag_length) &&
                ((tag_length < 12u) || (tag_length > 16u))) {
                status = PSA_ERROR_INVALID_ARGUMENT;
            }
            break;
#endif /* PSA_WANT_ALG_GCM */

        default:
            status = PSA_ERROR_INVALID_ARGUMENT;
            break;
    }

    return status;
}

static inline mcuxClAead_Mode_t get_aead_sgi_mode(psa_algorithm_t alg)
{
    psa_algorithm_t default_alg = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);

    const mcuxClAead_ModeDescriptor_t *mode = NULL;

    switch (default_alg) {
#if defined(PSA_WANT_ALG_CCM)
        case PSA_ALG_CCM:
            mode = mcuxClAead_Mode_CCM;
            break;
#endif /* PSA_WANT_ALG_CCM */
#if defined(PSA_WANT_ALG_GCM)
        case PSA_ALG_GCM:
            mode = mcuxClAead_Mode_GCM;
            break;
#endif /* PSA_WANT_ALG_GCM */
        default:
            mode = NULL;
            break;
    }

    return (mcuxClAead_Mode_t) mode;
}

/** \defgroup psa_aead PSA driver entry points for AEAD
 *
 *  Entry points for AEAD encryption and decryption as described by the PSA
 *  Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t sgi_aead_encrypt(const psa_key_attributes_t *attributes,
                              const uint8_t *key_buffer,
                              size_t key_buffer_size,
                              psa_algorithm_t alg,
                              const uint8_t *nonce,
                              size_t nonce_length,
                              const uint8_t *additional_data,
                              size_t additional_data_length,
                              const uint8_t *plaintext,
                              size_t plaintext_length,
                              uint8_t *ciphertext,
                              size_t ciphertext_size,
                              size_t *ciphertext_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t key_bits = psa_get_key_bits(attributes);
    size_t tag_length = 0;
    uint8_t *tag = NULL;

    /* Algorithm needs to be a AEAD algo */
    if (!PSA_ALG_IS_AEAD(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Validate tag length */
    if (check_tag_length(alg) != PSA_SUCCESS) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Get the correct AEAD mode based on the given algorithm. */
    mcuxClAead_Mode_t mode = get_aead_sgi_mode(alg);
    if (NULL == mode) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Get the TAG length encoded in the algorithm */
    tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);

    /* Key buffer or size can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute. */
    if (key_buffer_size != PSA_BITS_TO_BYTES(key_bits)) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Nonce can't be NULL */
    if (NULL == nonce || 0u == nonce_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* No check for input and additional data as 0 value for these is allowed */

    /* Output buffer has to be atleast Input buffer size  -> Check for encrypt */
    if (ciphertext_size < (plaintext_length + tag_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Output buffer can't be NULL */
    if (NULL == ciphertext || NULL == ciphertext_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, MCUXCLAEAD_WA_SIZE_MAX, 0U);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    mcuxClKey_Descriptor_t keyDesc;

    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    uint32_t ciphertext_length_tmp = 0u;

    tag = (uint8_t *) (ciphertext + plaintext_length);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(e_status, e_token,
                                     mcuxClAead_encrypt(session,
                                                        (mcuxClKey_Handle_t) &keyDesc,
                                                        mode,
                                                        nonce,
                                                        nonce_length,
                                                        plaintext,
                                                        plaintext_length,
                                                        additional_data,
                                                        additional_data_length,
                                                        ciphertext,
                                                        &ciphertext_length_tmp,
                                                        tag,
                                                        tag_length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_encrypt) != e_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLAEAD_STATUS_OK != e_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Update ciphertext_length by tag size, as they are in the same buffer */
    *ciphertext_length = (size_t) ciphertext_length_tmp;
    *ciphertext_length += tag_length;

    status = PSA_SUCCESS;

cleanup:
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_aead_decrypt(const psa_key_attributes_t *attributes,
                              const uint8_t *key_buffer,
                              size_t key_buffer_size,
                              psa_algorithm_t alg,
                              const uint8_t *nonce,
                              size_t nonce_length,
                              const uint8_t *additional_data,
                              size_t additional_data_length,
                              const uint8_t *ciphertext,
                              size_t ciphertext_length,
                              uint8_t *plaintext,
                              size_t plaintext_size,
                              size_t *plaintext_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t key_bits = psa_get_key_bits(attributes);
    size_t tag_length = 0;
    size_t cipher_length = 0;

    /* Algorithm needs to be a AEAD algo */
    if (!PSA_ALG_IS_AEAD(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Validate given sizes */
    uint32_t needed_output_size = PSA_AEAD_DECRYPT_OUTPUT_SIZE(psa_get_key_type(attributes),
                                                               alg,
                                                               ciphertext_length);
    if (plaintext_size < needed_output_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Validate tag length */
    if (check_tag_length(alg) != PSA_SUCCESS) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Get the correct AEAD mode based on the given algorithm. */
    mcuxClAead_Mode_t mode = get_aead_sgi_mode(alg);
    if (NULL == mode) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Get the correct tag length based on the given algorithm, and validate the given ciphertext_length (that contains the tag_length) */
    tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);
    if (ciphertext_length < tag_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key buffer or size can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute */
    if (PSA_BYTES_TO_BITS(key_buffer_size) != key_bits) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Input Buffer or size can't be NULL */
    if (NULL == ciphertext || 0u == ciphertext_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == nonce || 0u == nonce_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer has to be atleast Input buffer size  -> Check for encrypt */

    if (plaintext_size < cipher_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Input buffer i.e plaintext or AAD is allowed to be 0 in encrypt
     * Operation. Hence output of a decrypt can be of size 0. Hence no
     * check involving plaintext buffer.
     */

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, MCUXCLAEAD_WA_SIZE_MAX, 0U);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    mcuxClKey_Descriptor_t keyDesc;

    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    uint32_t plaintext_length_tmp = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(d_status, d_token,
                                     mcuxClAead_decrypt(session,
                                                        (mcuxClKey_Handle_t) &keyDesc,
                                                        mode,
                                                        nonce,
                                                        nonce_length,
                                                        ciphertext,
                                                        ciphertext_length - tag_length,
                                                        additional_data,
                                                        additional_data_length,
                                                        (uint8_t *) &ciphertext[ciphertext_length -
                                                                                tag_length],
                                                        tag_length,
                                                        plaintext,
                                                        &plaintext_length_tmp));

    *plaintext_length = (size_t) plaintext_length_tmp;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_decrypt) != d_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLAEAD_STATUS_OK == d_status) {
        status = PSA_SUCCESS;
    } else if (MCUXCLAEAD_STATUS_INVALID_TAG == d_status) {
        status = PSA_ERROR_INVALID_SIGNATURE;
    } else {
        status = PSA_ERROR_HARDWARE_FAILURE;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_END();

cleanup:
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

static psa_status_t sgi_aead_multipart_common_setup(sgi_aead_operation_t *operation,
                                                    const psa_key_attributes_t *attributes,
                                                    const uint8_t *key_buffer,
                                                    size_t key_buffer_size,
                                                    psa_algorithm_t alg)
{
    /* Initialize the operation */
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    operation->alg = alg;
    operation->key_type = psa_get_key_type(attributes);
    operation->ad_remaining = 0u;
    operation->body_remaining = 0u;
    operation->lengths_set = 0u;

    if (PSA_SUCCESS != check_tag_length(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Get the correct tag length based on the given algorithm, and store it.
       Later operation->alg is restored to base_algo value in psa_crypto.c, hence by the time,
       we want to set in sgi_aead_set_nonce() it could be incorrect tag length as
       operation->alg is already reset to psa_base_alg_value */
    operation->tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(operation->alg);

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLAEAD_WA_SIZE_MAX,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Create the key descriptor */
    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size,
                                       (mcuxClKey_Descriptor_t *) &operation->keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_aead_encrypt_setup(sgi_aead_operation_t *operation,
                                    const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size,
                                    psa_algorithm_t alg)
{
    /* Validate given key */
    if ((PSA_KEY_USAGE_ENCRYPT != (PSA_KEY_USAGE_ENCRYPT & psa_get_key_usage_flags(attributes)))
        || !(PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(psa_get_key_algorithm(attributes)) ==
             PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg))) {
        return PSA_ERROR_NOT_PERMITTED;
    }

    /* Initialize the operation */
    operation->is_encrypt = 1u;
    /* Rest of operation is initialized in sgi_aead_multipart_common_setup() */
    return sgi_aead_multipart_common_setup(operation, attributes, key_buffer, key_buffer_size, alg);

}

psa_status_t sgi_aead_decrypt_setup(sgi_aead_operation_t *operation,
                                    const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size,
                                    psa_algorithm_t alg)
{
    /* Validate given key */
    if ((PSA_KEY_USAGE_DECRYPT != (PSA_KEY_USAGE_DECRYPT & psa_get_key_usage_flags(attributes)))
        || !(PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(psa_get_key_algorithm(attributes)) ==
             PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg))) {
        return PSA_ERROR_NOT_PERMITTED;
    }

    /* Validate state
     *   - operation must not be active */
    if (0u != operation->body_started) {
        return PSA_ERROR_BAD_STATE;
    }

    operation->is_encrypt = 0u;
    /* Rest of operation is initialized in sgi_aead_multipart_common_setup() */
    return sgi_aead_multipart_common_setup(operation, attributes, key_buffer, key_buffer_size, alg);
}

psa_status_t sgi_aead_set_nonce(sgi_aead_operation_t *operation,
                                const uint8_t *nonce,
                                size_t nonce_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Add checks for valid tag length, otherwise return error*/
    status = check_tag_length(operation->alg);
    if (PSA_SUCCESS != status) {
        return status;
    }

    /* Get the correct AEAD mode based on the given algorithm. */
    mcuxClAead_Mode_t mode = get_aead_sgi_mode(operation->alg);
    if (NULL == mode) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if ((PSA_ALG_CCM == PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(operation->alg)) &&
        (0u == operation->lengths_set)) {
        return PSA_ERROR_BAD_STATE;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLAEAD_WA_SIZE_MAX,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Initialize AEAD multi-part */

    mcuxClAead_Context_t * const ctx = (mcuxClAead_Context_t *) operation->ctx;

    if (1u == operation->is_encrypt) {

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ei_status, ei_token,
                                         mcuxClAead_init_encrypt(session,
                                                                 ctx,
                                                                 (mcuxClKey_Handle_t) &operation->
                                                                 keyDesc,
                                                                 mode,
                                                                 nonce,
                                                                 nonce_length,
                                                                 operation->body_remaining,
                                                                 operation->ad_remaining,
                                                                 operation->tag_length));

        if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_init_encrypt) != ei_token) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
            goto cleanup;
        }

        if (MCUXCLAEAD_STATUS_OK != ei_status) {
            status = PSA_ERROR_HARDWARE_FAILURE;
            goto cleanup;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
    } else {
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(di_status, di_token,
                                         mcuxClAead_init_decrypt(session,
                                                                 ctx,
                                                                 (mcuxClKey_Handle_t) &operation->
                                                                 keyDesc,
                                                                 mode,
                                                                 nonce,
                                                                 nonce_length,
                                                                 operation->body_remaining,
                                                                 operation->ad_remaining,
                                                                 operation->tag_length));

        if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_init_decrypt) != di_token) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
            goto cleanup;
        }

        if (MCUXCLAEAD_STATUS_OK != di_status) {
            status = PSA_ERROR_HARDWARE_FAILURE;
            goto cleanup;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
    }

    /* Update the operation's status */
    operation->nonce_set = 1u;

    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_aead_set_lengths(sgi_aead_operation_t *operation,
                                  size_t ad_length,
                                  size_t plaintext_length)
{
    /* Validate state
     *   - operation must be active
     *   - no nonce must have been set yet */
    if (1u == operation->nonce_set) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Update the operation's status */
    operation->ad_remaining = ad_length;
    operation->body_remaining = plaintext_length;
    operation->lengths_set = 1u;

    return PSA_SUCCESS;
}

psa_status_t sgi_aead_update_ad(sgi_aead_operation_t *operation,
                                const uint8_t *input,
                                size_t input_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Validate state
     *   - operation must be active
     *   - setup must be finished, i.e. nonce must have been set
     *   - aead_update/finish functions must not have been called yet */

    if ((1u != operation->nonce_set) || (0u != operation->body_started)) {
        return PSA_ERROR_BAD_STATE;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLAEAD_WA_SIZE_MAX,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(epa1_status, epa1_token,
                                     mcuxClAead_process_adata(session,
                                                              (mcuxClAead_Context_t *) &operation->
                                                              ctx,
                                                              input,
                                                              input_length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_process_adata) != epa1_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLAEAD_STATUS_OK != epa1_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_aead_update(sgi_aead_operation_t *operation,
                             const uint8_t *input,
                             size_t input_length,
                             uint8_t *output,
                             size_t output_size,
                             size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Validate state
     *   - operation must be active
     *   - setup must be finished, i.e. nonce must have been set */

    if (1u != operation->nonce_set) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Validate given length: can be skipped as this is performed by psa_aead_update(...) */

    /* Validate the given buffer size */
    if (output_size < input_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLAEAD_WA_SIZE_MAX,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Call Process AEAD */
    uint32_t output_length_tmp = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ep1_status, ep1_token,
                                     mcuxClAead_process(session,
                                                        (mcuxClAead_Context_t *) &operation->ctx,
                                                        input, input_length,
                                                        output, &output_length_tmp));

    *output_length = (size_t) output_length_tmp;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_process) != ep1_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLAEAD_STATUS_OK != ep1_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    operation->body_started = 1u;

    /* Track plaintext already emitted so the remaining count reflects only the
       bytes still to be produced. sgi_aead_verify() uses body_remaining to size
       its output buffer, and in a multipart flow update() may have already
       emitted part or all of the plaintext. */
    if ((size_t) output_length_tmp <= operation->body_remaining) {
        operation->body_remaining -= (size_t) output_length_tmp;
    } else {
        operation->body_remaining = 0u;
    }

    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_aead_finish(sgi_aead_operation_t *operation,
                             uint8_t *ciphertext,
                             size_t ciphertext_size,
                             size_t *ciphertext_length,
                             uint8_t *tag,
                             size_t tag_size,
                             size_t *tag_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Validate state
     *   - must be active encryption operation
     *   - setup must be finished, i.e. nonce must have been set */

    if ((1u != operation->is_encrypt) || (1u != operation->nonce_set)) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Validate the given buffer sizes */
    uint32_t needed_tag_size = operation->tag_length;
    if (tag_size < needed_tag_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLAEAD_WA_SIZE_MAX,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Call Finish AEAD */

    uint32_t ciphertext_length_tmp = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ef_status, ef_token,
                                     mcuxClAead_finish(session,
                                                       (mcuxClAead_Context_t *) &operation->ctx,
                                                       ciphertext, &ciphertext_length_tmp, tag));

    *ciphertext_length = (size_t) ciphertext_length_tmp;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_finish) != ef_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLAEAD_STATUS_OK != ef_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Set the tag_length */
    *tag_length = needed_tag_size;

    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_aead_verify(sgi_aead_operation_t *operation,
                             uint8_t *plaintext,
                             size_t plaintext_size,
                             size_t *plaintext_length,
                             const uint8_t *tag,
                             size_t tag_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Validate state
     *   - must be active decryption operation
     *   - setup must be finished, i.e. nonce must have been set */

    if ((0u != operation->is_encrypt) || (1u != operation->nonce_set)) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Validate the given buffer sizes */
    /* Used stored tag length from pContext instead of determining it at run time,
       as operation->alg has been overwritten to base_algo value*/
    if (tag_length < operation->tag_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Validate the given output buffer size. */
    if (plaintext_size < operation->body_remaining) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLAEAD_WA_SIZE_MAX,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Call Verify AEAD */
    uint32_t output_length_tmp = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(dv_status, dv_token, mcuxClAead_verify(
                                         /* mcuxClSession_Handle_t session         */ session,
                                         /* mcuxClAead_Context_t * const pContext  */ (
                                             mcuxClAead_Context_t *) &operation->ctx,
                                         /* mcuxCl_InputBuffer_t pTag              */ tag,
                                         /* mcuxCl_Buffer_t pOut                   */ plaintext,
                                         /* uint32_t * const pOutSize             */ &
                                         output_length_tmp)
                                     );

    *plaintext_length = (size_t) output_length_tmp;

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAead_verify) != dv_token) ||
        (MCUXCLAEAD_STATUS_OK != dv_status)) {
        status = PSA_ERROR_INVALID_SIGNATURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_aead_abort(sgi_aead_operation_t *operation)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(tokenClear,
                                          mcuxClMemory_clear((uint8_t *) operation,
                                                             sizeof(sgi_aead_operation_t),
                                                             sizeof(sgi_aead_operation_t)));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != tokenClear) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    status = PSA_SUCCESS;

cleanup:
    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

/** @} */ // end of psa_aead
