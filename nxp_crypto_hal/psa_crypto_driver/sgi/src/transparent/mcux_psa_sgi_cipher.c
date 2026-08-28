/*
 * Copyright 2025 - 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_sgi_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability (single-part only, multi-part (not supported in ele) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_sgi_init.h"
#include "mcux_psa_sgi_cipher.h"
#include "mcux_psa_sgi_common_key_management.h"

#include "mbedtls/platform.h"

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

#include <mcuxClKey.h>
#include <mcuxClCipher.h>
#include <mcuxClCipherModes.h>
#include <internal/mcuxClCipherModes_Sgi_Types.h>

#include <mcuxClMemory_Clear.h>

static inline void psa_cipher_to_sgi_alg(const psa_algorithm_t alg,
                                         const mcuxClCipher_ModeDescriptor_t **mode)
{
    switch (alg) {
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
        case PSA_ALG_CBC_NO_PADDING:
            *mode = mcuxClCipher_Mode_AES_CBC_NoPadding;
            break;
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_CTR)
        case PSA_ALG_CTR:
            *mode = mcuxClCipher_Mode_AES_CTR;
            break;
#endif /* PSA_WANT_ALG_CTR */
#if defined(PSA_WANT_ALG_CBC_PKCS7)
        case PSA_ALG_CBC_PKCS7:
            *mode = mcuxClCipher_Mode_AES_CBC_PaddingPKCS7;
            break;
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
        case PSA_ALG_ECB_NO_PADDING:
            *mode = mcuxClCipher_Mode_AES_ECB_NoPadding;
            break;
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
        default:
            *mode = NULL;
            break;
    }
}

/**
 * \def CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE
 *
 * Enable double encryption/decryption with CMAC verification.
 * When enabled, cipher operations are performed twice and verified
 * using AES-128-CMAC to detect potential faults.
 *
 */

#ifdef CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE

#include <mcuxClRandom.h>
#include <mcuxClMac.h>
#include <mcuxClMacModes.h>
#include <mcuxClKey.h>
#include <mcuxClMemory.h>
#include <mcuxCsslMemory_Constants.h>
#include <mcuxCsslMemory_SecureCompare.h>

#define CMAC_KEY_SIZE_BYTES     16u
#define CMAC_OUTPUT_SIZE_BYTES  16u

/**
 * @brief Overwrite buffer with random data
 *
 * @param session   Session handle
 * @param buffer    Buffer to overwrite
 * @param length    Length of buffer
 * @return psa_status_t PSA status code
 */
static psa_status_t overwrite_with_random(mcuxClSession_Handle_t session,
                                          uint8_t *buffer,
                                          size_t length)
{
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(rng_status, rng_token,
                                     mcuxClRandom_generate(session, buffer, length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate) != rng_token) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }

    if (MCUXCLRANDOM_STATUS_OK != rng_status) {
        return PSA_ERROR_HARDWARE_FAILURE;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return PSA_SUCCESS;
}

#endif /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */

psa_status_t sgi_transparent_cipher_encrypt(const psa_key_attributes_t *attributes,
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
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits = psa_get_key_bits(attributes);
    size_t key_bytes = PSA_BITS_TO_BYTES(key_bits);

    /* Key buffer or size can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute */
    if (key_buffer_size != key_bytes) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm needs to be a CIPHER algo */
    if (!PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg == PSA_ALG_ECB_NO_PADDING) && (input_length == 0u)) {
        /* PSA specification is not very clear on 0 input for ECB.
         * However software implementation and the tests return SUCCESS
         * for 0 input. So adding this check here.
         */
        *output_length = 0;
        return PSA_SUCCESS;
    }

    /* If input length or input buffer NULL, it;s an error.
     * Special case for ECB where input = 0 may be allowed.
     * Taken care of in above code.
     */
    if (!input_length || !input) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer has to be atleast Input buffer size */
    if (output_size < input_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Output buffer can't be NULL */
    if (!output || !output_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* IV buffer can't be NULL or size different to 16 */
    if ((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR)) {
        if (!iv || ((key_type == PSA_KEY_TYPE_AES) && (iv_length != PSA_CIPHER_IV_MAX_SIZE))) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* For CBC and ECB No padding, input length has to be multiple of cipher block length */
    if (((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_ECB_NO_PADDING)) &&
        (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    mcuxClKey_Descriptor_t keyDesc = { 0 };

#if defined(CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE)
    /* Allocate larger work area for CMAC and RANDOM operations */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLRANDOMMODES_MAX_CPU_WA_BUFFER_SIZE,
                                                  0u);
#else /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */
    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE,
                                                  0u);
#endif /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    /* Initializing the output length with zero */
    uint32_t output_length_tmp = 0u;

    /* Variable for the AES mode. */
    const mcuxClCipher_ModeDescriptor_t *mode = NULL;
    psa_cipher_to_sgi_alg(alg, &mode);
    if (NULL == mode) {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto cleanup;
    }

#if defined(CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE)
    /* Buffers for CMAC verification */
    uint8_t cmac_key[CMAC_KEY_SIZE_BYTES];
    uint8_t cmac_output_1[CMAC_OUTPUT_SIZE_BYTES];
    uint8_t cmac_output_2[CMAC_OUTPUT_SIZE_BYTES];


    /* Generate random CMAC key */
    /* Initialize the RNG context  */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_RNG(session,
                                              MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE,
                                              mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(retRandGen, tokenRandGen, mcuxClRandom_generate(session,
                                                                                     cmac_key,
                                                                                     CMAC_KEY_SIZE_BYTES));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate) != tokenRandGen) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLRANDOM_STATUS_OK != retRandGen) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Initialize CMAC key descriptor */
    mcuxClKey_Descriptor_t cmacKeyDesc;
    psa_key_attributes_t cmac_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_set_key_type(&cmac_attributes, PSA_KEY_TYPE_AES);
    psa_set_key_bits(&cmac_attributes, 128u);

    status = sgi_create_key_descriptor(&cmac_attributes, cmac_key, CMAC_KEY_SIZE_BYTES,
                                       &cmacKeyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    /* First encryption */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(e_status, e_token,
                                     mcuxClCipher_encrypt(session,
                                                          (mcuxClKey_Handle_t) &keyDesc,
                                                          mode,
                                                          iv,
                                                          iv_length,
                                                          input,
                                                          input_length,
                                                          output,
                                                          &output_length_tmp));

    *output_length = (size_t) output_length_tmp;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_encrypt) != e_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLCIPHER_STATUS_OK != e_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Compute CMAC of first encryption output */
    uint32_t cmac1_length = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mac_status, mac_token,
                                     mcuxClMac_compute(session,
                                                       (mcuxClKey_Handle_t) &cmacKeyDesc,
                                                       mcuxClMac_Mode_CMAC,
                                                       output,
                                                       *output_length,
                                                       cmac_output_1,
                                                       &cmac1_length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute) != mac_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if ((MCUXCLMAC_STATUS_OK != mac_status) || (cmac1_length != CMAC_OUTPUT_SIZE_BYTES)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Second encryption */
    output_length_tmp = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(e2_status, e2_token,
                                     mcuxClCipher_encrypt(session,
                                                          (mcuxClKey_Handle_t) &keyDesc,
                                                          mode,
                                                          iv,
                                                          iv_length,
                                                          input,
                                                          input_length,
                                                          output,
                                                          &output_length_tmp));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_encrypt) != e2_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLCIPHER_STATUS_OK != e2_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Verify output length is consistent */
    if (*output_length != (size_t) output_length_tmp) {
        /* Length mismatch - overwrite output with random data and fail */
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }

    /* Compute CMAC of second encryption output using same key */
    uint32_t cmac2_length = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mac2_status, mac2_token,
                                     mcuxClMac_compute(session,
                                                       (mcuxClKey_Handle_t) &cmacKeyDesc,
                                                       mcuxClMac_Mode_CMAC,
                                                       output,
                                                       *output_length,
                                                       cmac_output_2,
                                                       &cmac2_length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute) != mac2_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if ((MCUXCLMAC_STATUS_OK != mac2_status) || (cmac2_length != CMAC_OUTPUT_SIZE_BYTES)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Compare CMAC results */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(secureCompareResult, secureCompareToken,
                                     mcuxCsslMemory_SecureCompare(
                                         /* mcuxCsslParamIntegrity_Checksum_t chk */
                                         MCUX_CSSL_PI_PROTECT(cmac_output_1,
                                                              cmac_output_2,
                                                              CMAC_OUTPUT_SIZE_BYTES),
                                         /* void const * lhs                      */ cmac_output_1,
                                         /* void const * rhs                      */ cmac_output_2,
                                         /* uint32_t length                       */
                                         CMAC_OUTPUT_SIZE_BYTES
                                         ));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_SecureCompare) != secureCompareToken) ||
        (MCUXCSSLMEMORY_STATUS_EQUAL != secureCompareResult)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();


    /* Clear sensitive data from stack */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(clear_token,
                                          mcuxClMemory_clear(cmac_key, CMAC_KEY_SIZE_BYTES,
                                                             CMAC_KEY_SIZE_BYTES));
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != clear_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

#else
    /* Standard single encryption */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(e_status, e_token,
                                     mcuxClCipher_encrypt(session,
                                                          (mcuxClKey_Handle_t) &keyDesc,
                                                          mode,
                                                          iv,
                                                          iv_length,
                                                          input,
                                                          input_length,
                                                          output,
                                                          &output_length_tmp));

    *output_length = (size_t) output_length_tmp;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_encrypt) != e_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLCIPHER_STATUS_OK != e_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();
#endif /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */

    status = PSA_SUCCESS;

cleanup:

#if defined(CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE)
    if (status != PSA_SUCCESS) {
        if (overwrite_with_random(session, output, output_size) != 0) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
    }
#endif /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */

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

psa_status_t sgi_transparent_cipher_decrypt(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *input,
                                            size_t input_length,
                                            uint8_t *output,
                                            size_t output_size,
                                            size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits = psa_get_key_bits(attributes);
    size_t key_bytes = PSA_BITS_TO_BYTES(key_bits);

    uint32_t iv_length = 0;
    uint32_t expected_op_length = 0;

    if (key_buffer_size != key_bytes) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (!PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg == PSA_ALG_ECB_NO_PADDING) && (input_length == 0u)) {
        /* PSA specification is not very clear on 0 input for ECB.
         * However software implementation and the tests return SUCCESS
         * for 0 input. So adding this check here.
         */
        *output_length = 0;
        return PSA_SUCCESS;
    }

    /* If input length or input buffer NULL, it;s an error.
     * Special case for ECB where input = 0 may be allowed.
     * Taken care of in above code.
     */
    if (!input_length || !input) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer can't be NULL */
    if (!output || !output_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* IV buffer can't be NULL or size different to 16 */
    if ((alg == PSA_ALG_CBC_PKCS7) || (alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR)) {
        if (key_type == PSA_KEY_TYPE_AES) {
            iv_length = PSA_CIPHER_IV_MAX_SIZE;
        }
    }

    /* Input buffer -> IV + INPUT.
     * So output length would be (input - iv_length)
     */
    expected_op_length = input_length - iv_length;

    /* Input length has to be multiple of block size for decrypt operation */
    if ((alg == PSA_ALG_CBC_NO_PADDING || alg == PSA_ALG_CBC_PKCS7 ||
         alg == PSA_ALG_ECB_NO_PADDING) &&
        (expected_op_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg != PSA_ALG_CBC_PKCS7) && (output_size < expected_op_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    mcuxClKey_Descriptor_t keyDesc = { 0 };

#if defined(CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE)
    /* Allocate larger work area for CMAC and RANDOM operations */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLRANDOMMODES_MAX_CPU_WA_BUFFER_SIZE,
                                                  0u);
#else /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */
    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE,
                                                  0u);
#endif /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    /* Variable for the AES mode. */
    const mcuxClCipher_ModeDescriptor_t *mode = NULL;
    psa_cipher_to_sgi_alg(alg, &mode);
    if (NULL == mode) {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto cleanup;
    }

#if defined(CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE)
    /* Buffers for CMAC verification */
    uint8_t cmac_key[CMAC_KEY_SIZE_BYTES];
    uint8_t cmac_output_1[CMAC_OUTPUT_SIZE_BYTES];
    uint8_t cmac_output_2[CMAC_OUTPUT_SIZE_BYTES];


    /* Generate random CMAC key */
    /* Initialize the RNG context  */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_RNG(session,
                                              MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE,
                                              mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(retRandGen, tokenRandGen, mcuxClRandom_generate(session,
                                                                                     cmac_key,
                                                                                     CMAC_KEY_SIZE_BYTES));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate) != tokenRandGen) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLRANDOM_STATUS_OK != retRandGen) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Initialize CMAC key descriptor */
    mcuxClKey_Descriptor_t cmacKeyDesc;
    psa_key_attributes_t cmac_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_set_key_type(&cmac_attributes, PSA_KEY_TYPE_AES);
    psa_set_key_bits(&cmac_attributes, 128u);

    status = sgi_create_key_descriptor(&cmac_attributes, cmac_key, CMAC_KEY_SIZE_BYTES,
                                       &cmacKeyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(d_status, d_token,
                                     mcuxClCipher_decrypt(session,
                                                          (mcuxClKey_Handle_t) &keyDesc,
                                                          mode,
                                                          input,
                                                          iv_length,
                                                          (mcuxCl_Buffer_t) (input + iv_length),
                                                          input_length - iv_length,
                                                          output,
                                                          &expected_op_length));

    *output_length = (size_t) expected_op_length;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_decrypt) != d_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLCIPHER_STATUS_OK == d_status) {
        /* Assign PSA_SUCCESS at end of function before cleanup */
    } else if (MCUXCLPADDING_STATUS_ERROR == d_status) {
        status = PSA_ERROR_INVALID_PADDING;
        goto cleanup;
    } else {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Compute CMAC of first decryption output */
    uint32_t cmac1_length = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mac_status, mac_token,
                                     mcuxClMac_compute(session,
                                                       (mcuxClKey_Handle_t) &cmacKeyDesc,
                                                       mcuxClMac_Mode_CMAC,
                                                       output,
                                                       *output_length,
                                                       cmac_output_1,
                                                       &cmac1_length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute) != mac_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if ((MCUXCLMAC_STATUS_OK != mac_status) || (cmac1_length != CMAC_OUTPUT_SIZE_BYTES)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Second decryption */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(d2_status, d2_token,
                                     mcuxClCipher_decrypt(session,
                                                          (mcuxClKey_Handle_t) &keyDesc,
                                                          mode,
                                                          input,
                                                          iv_length,
                                                          (mcuxCl_Buffer_t) (input + iv_length),
                                                          input_length - iv_length,
                                                          output,
                                                          &expected_op_length));

    *output_length = (size_t) expected_op_length;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_decrypt) != d2_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLCIPHER_STATUS_OK == d2_status) {
        /* Assign PSA_SUCCESS at end of function before cleanup */
    } else if (MCUXCLPADDING_STATUS_ERROR == d2_status) {
        status = PSA_ERROR_INVALID_PADDING;
        goto cleanup;
    } else {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Compute CMAC of second decryption output using same key */
    uint32_t cmac2_length = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mac2_status, mac2_token,
                                     mcuxClMac_compute(session,
                                                       (mcuxClKey_Handle_t) &cmacKeyDesc,
                                                       mcuxClMac_Mode_CMAC,
                                                       output,
                                                       *output_length,
                                                       cmac_output_2,
                                                       &cmac2_length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute) != mac2_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if ((MCUXCLMAC_STATUS_OK != mac2_status) || (cmac2_length != CMAC_OUTPUT_SIZE_BYTES)) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Compare CMAC results */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(secureCompareResult, secureCompareToken,
                                     mcuxCsslMemory_SecureCompare(
                                         /* mcuxCsslParamIntegrity_Checksum_t chk */
                                         MCUX_CSSL_PI_PROTECT(cmac_output_1,
                                                              cmac_output_2,
                                                              CMAC_OUTPUT_SIZE_BYTES),
                                         /* void const * lhs                      */ cmac_output_1,
                                         /* void const * rhs                      */ cmac_output_2,
                                         /* uint32_t length                       */
                                         CMAC_OUTPUT_SIZE_BYTES
                                         ));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_SecureCompare) != secureCompareToken) ||
        (MCUXCSSLMEMORY_STATUS_EQUAL != secureCompareResult)) {
        /* Mismatch detected or flow protection error */
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();


    /* Clear sensitive data from stack */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(clear_token,
                                          mcuxClMemory_clear(cmac_key, CMAC_KEY_SIZE_BYTES,
                                                             CMAC_KEY_SIZE_BYTES));
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != clear_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

#else
    /* Standard single decryption */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(d_status, d_token,
                                     mcuxClCipher_decrypt(session,
                                                          (mcuxClKey_Handle_t) &keyDesc,
                                                          mode,
                                                          input,
                                                          iv_length,
                                                          (mcuxCl_Buffer_t) (input + iv_length),
                                                          input_length - iv_length,
                                                          output,
                                                          &expected_op_length));

    *output_length = (size_t) expected_op_length;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_decrypt) != d_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLCIPHER_STATUS_OK == d_status) {
        /* Assign PSA_SUCCESS at end of function before cleanup */
    } else if (MCUXCLPADDING_STATUS_ERROR == d_status) {
        status = PSA_ERROR_INVALID_PADDING;
        goto cleanup;
    } else {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_END();
#endif /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */

    status = PSA_SUCCESS;

cleanup:

#if defined(CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE)
    if (status != PSA_SUCCESS) {
        if (overwrite_with_random(session, output, output_size) != 0) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
    }
#endif /* CONFIG_MCUX_PSA_SGI_DOUBLE_CIPHER_ENABLE  */

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


static psa_status_t cipher_common_setup(sgi_cipher_operation_t *operation,
                                        const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        psa_algorithm_t alg,
                                        psa_encrypt_or_decrypt_t cipher_direction)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);


    /* Here we only set up the internal cipher driver context.
     * Actual init of operation will happen in sgi_transparent_cipher_set_iv().
     */

    if (PSA_KEY_TYPE_AES != key_type) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (32u < key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    operation->cipher_direction = cipher_direction;
    operation->alg = alg;
    operation->key_type = key_type;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

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

psa_status_t sgi_transparent_cipher_encrypt_setup(
    sgi_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg)
{
    return cipher_common_setup(operation, attributes, key_buffer,
                               key_buffer_size, alg, PSA_CRYPTO_DRIVER_ENCRYPT);
}

psa_status_t sgi_transparent_cipher_decrypt_setup(
    sgi_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg)
{
    return cipher_common_setup(operation, attributes, key_buffer,
                               key_buffer_size, alg, PSA_CRYPTO_DRIVER_DECRYPT);
}

psa_status_t sgi_transparent_cipher_set_iv(sgi_cipher_operation_t *operation,
                                           const uint8_t *iv,
                                           size_t iv_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* If alg takes IV, then it must by equal to MCUXCLAES_BLOCK_SIZE */
    if (PSA_ALG_ECB_NO_PADDING != operation->alg &&
        MCUXCLAES_BLOCK_SIZE != iv_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    mcuxClCipher_Context_t * const ctx = (mcuxClCipher_Context_t *) operation->ctx;

    /* Variable for the AES mode. */
    const mcuxClCipher_ModeDescriptor_t *mode = NULL;
    psa_cipher_to_sgi_alg(operation->alg, &mode);
    if (NULL == mode) {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto cleanup;
    }

    if (PSA_CRYPTO_DRIVER_ENCRYPT == operation->cipher_direction) {

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ei_status, ei_token,
                                         mcuxClCipher_init_encrypt(session,
                                                                   ctx,
                                                                   (mcuxClKey_Handle_t) &operation->
                                                                   keyDesc,
                                                                   mode,
                                                                   iv,
                                                                   iv_length));

        if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_init_encrypt) != ei_token) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
            goto cleanup;
        }

        if (MCUXCLCIPHER_STATUS_OK != ei_status) {
            status = PSA_ERROR_HARDWARE_FAILURE;
            goto cleanup;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

    } else {

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(di_status, di_token,
                                         mcuxClCipher_init_decrypt(session,
                                                                   ctx,
                                                                   (mcuxClKey_Handle_t) &operation->
                                                                   keyDesc,
                                                                   mode,
                                                                   iv,
                                                                   iv_length));

        if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_init_decrypt) != di_token) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
            goto cleanup;
        }

        if (MCUXCLCIPHER_STATUS_OK != di_status) {
            status = PSA_ERROR_HARDWARE_FAILURE;
            goto cleanup;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
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

psa_status_t sgi_transparent_cipher_update(sgi_cipher_operation_t *operation,
                                           const uint8_t *input,
                                           size_t input_length,
                                           uint8_t *output,
                                           size_t output_size,
                                           size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t expected_output_size;

    expected_output_size = output_size == 0u ? output_size : input_length;

    /* Potential check for small output buffer size*/
    if (output_size < expected_output_size) {
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
                                                  MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    mcuxClCipher_Context_t * const ctx = (mcuxClCipher_Context_t *) operation->ctx;

    uint32_t output_length_tmp = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ep1_status, ep1_token,
                                     mcuxClCipher_process(session, ctx, input, input_length,
                                                          output, &output_length_tmp));

    *output_length = (size_t) output_length_tmp;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_process) != ep1_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLCIPHER_STATUS_OK != ep1_status) {
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

psa_status_t sgi_transparent_cipher_finish(sgi_cipher_operation_t *operation,
                                           uint8_t *output,
                                           size_t output_size,
                                           size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;
    uint32_t output_length_tmp = 0u;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* check for invalid input based upon following rule
       inLength needs to be a multiple of the granularity, if this is not the case, return an error. */
    mcuxClCipher_Context_t * const ctx = (mcuxClCipher_Context_t *) operation->ctx;
    mcuxClCipherModes_Context_Aes_Sgi_t * const pCtx = (mcuxClCipherModes_Context_Aes_Sgi_t *) ctx;
    mcuxClCipherModes_Algorithm_Aes_Sgi_t pAlgo =
        (mcuxClCipherModes_Algorithm_Aes_Sgi_t) (pCtx->common.pMode->pAlgorithm);

    /* Return INVALID_INPUT if totalInputLength doesn't meet the required granularity */
    if (0u != (pCtx->common.totalInputLength % pAlgo->granularityEnc)) {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    /* Check if output buffer is sufficient */
    if (PSA_CIPHER_FINISH_OUTPUT_SIZE((operation->key_type), (operation->alg)) > output_size) {
        status = PSA_ERROR_BUFFER_TOO_SMALL;
        goto exit;
    }

    /* Initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE,
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(df_status, df_token, mcuxClCipher_finish(
                                         /* mcuxClSession_Handle_t session:         */ session,
                                         /* mcuxClCipher_Context_t * const pContext:*/ ctx,
                                         /* mcuxCl_Buffer_t pOut:                   */ output,
                                         /* uint32_t * const outLength:            */ &
                                         output_length_tmp)
                                     );

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_finish) != df_token) ||
        (MCUXCLCIPHER_STATUS_OK != df_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    *output_length = (size_t) output_length_tmp;
    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) ||
        (MCUXCLSESSION_STATUS_OK != result)) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

exit:
    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t sgi_transparent_cipher_abort(sgi_cipher_operation_t *operation)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Clear cipher ctx */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(token,
                                          mcuxClMemory_clear((uint8_t *) operation,
                                                             sizeof(sgi_cipher_operation_t),
                                                             sizeof(sgi_cipher_operation_t)));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != token) {
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
