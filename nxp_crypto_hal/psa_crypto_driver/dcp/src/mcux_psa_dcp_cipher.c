/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_dcp_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability (single-part only, multi-part (not supported in ele) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_dcp_cipher.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#include "fsl_os_abstraction.h"

psa_status_t dcp_cipher_encrypt(const psa_key_attributes_t *attributes,
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
    status_t dcp_status     = kStatus_Fail;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    uint8_t *_input = NULL;
    size_t _input_length = 0;
#endif
#if DCP_USE_DCACHE == 1u
    uint8_t *_input_cache = NULL;
    uint8_t *_output_cache = NULL;
#endif

    dcp_handle_t m_handle;
    m_handle.channel    = kDCP_Channel0;
    m_handle.swapConfig = kDCP_NoSwap;
    m_handle.keySlot    = kDCP_KeySlot0;

    /* Key buffer or size can't be NULL */
    if (!key_buffer || !key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute */
    if (PSA_BYTES_TO_BITS(key_buffer_size) != key_bits) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* DCP support only 128 bit keys */
    if (key_bits != 128u){
        return PSA_ERROR_NOT_SUPPORTED;
    }
    
    /* Algorithm needs to be a CIPHER algo */
    if (!PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg == PSA_ALG_ECB_NO_PADDING) && (input_length == 0)) {
        /* PSA specification is not very clear on 0 input for ECB.
         * However software implementation and the tests return SUCCESS
         * for 0 input. So adding this check here.
         */
        *output_length = 0;
        return PSA_SUCCESS;
    }

    /* If input length or input buffer NULL, it is an error.
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
    if (((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR)) &&
        (!iv || (iv_length != PSA_CIPHER_IV_MAX_SIZE))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* For CBC and ECB No padding, input length has to be multiple of cipher block length */
    if (((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_ECB_NO_PADDING)) &&
        (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Set key */
    status = DCP_AES_SetKey(PSA_DCP, &m_handle, key_buffer, key_buffer_size);
    if (status != kStatus_Success) {
        return dcp_to_psa_status(status);
    }

#if DCP_USE_DCACHE == 1u
    /* Allocate aligned buffers with sufficient traling memory for safe clean/invalidate */
    _input_cache = OSA_MemoryAllocateAlign(ALIGNED_SIZE(input_length), FSL_FEATURE_L1DCACHE_LINESIZE_BYTE);
    if (_input_cache == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
 
    _output_cache = OSA_MemoryAllocateAlign(ALIGNED_SIZE(output_size), FSL_FEATURE_L1DCACHE_LINESIZE_BYTE);
    if (_output_cache == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
    /* Copy and clean input data in working buffer */
    memcpy(_input_cache, input, input_length);
    SCB_CleanDCache_by_Addr(_input_cache, input_length);
#endif /* DCP_USE_DCACHE */

    
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    /* Apply PKCS7 padding -> Append bytes to fill block length
       with number containing amount of missing bytes. */
    if (alg == PSA_ALG_CBC_PKCS7) {
        _input_length =
            (input_length + PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)) &
            -PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type);
        if (output_size < _input_length) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
#if DCP_USE_DCACHE == 1u
        _input = OSA_MemoryAllocateAlign(ALIGNED_SIZE(_input_length), FSL_FEATURE_L1DCACHE_LINESIZE_BYTE);
#else
        _input = OSA_MemoryAllocate(_input_length);
#endif /* DCP_USE_DCACHE */
        if (_input == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
        memcpy(_input, input, input_length);
        memset(&_input[input_length], _input_length - input_length, _input_length - input_length);
#if DCP_USE_DCACHE == 1u
        SCB_CleanDCache_by_Addr(_input, ALIGNED_SIZE(_input_length));
#endif /* DCP_USE_DCACHE */
    }
#endif

    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
#if DCP_USE_DCACHE == 1u
                    dcp_status = DCP_AES_EncryptCbc(PSA_DCP,
                                                    &m_handle,
                                                    _input,
                                                    _output_cache,
                                                    _input_length,
                                                    iv);
#else
                    dcp_status = DCP_AES_EncryptCbc(PSA_DCP,
                                                    &m_handle,
                                                    _input,
                                                    output,
                                                    _input_length,
                                                    iv);                    
#endif /* DCP_USE_DCACHE */
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
#if DCP_USE_DCACHE == 1u
                    dcp_status = DCP_AES_EncryptCbc(PSA_DCP,
                                                    &m_handle,
                                                    _input_cache,
                                                    _output_cache,
                                                    input_length,
                                                    iv);
#else
                    dcp_status = DCP_AES_EncryptCbc(PSA_DCP,
                                                    &m_handle,
                                                    input,
                                                    output,
                                                    input_length,
                                                    iv);
#endif /* DCP_USE_DCACHE */
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
#if DCP_USE_DCACHE == 1u
                    dcp_status =
                        DCP_AES_EncryptEcb(PSA_DCP, &m_handle, _input_cache, _output_cache, input_length);
#else
                    dcp_status =
                        DCP_AES_EncryptEcb(PSA_DCP, &m_handle, input, output, input_length);
#endif /* DCP_USE_DCACHE */
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
                default:
                {
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
                }
            } /* operation->alg */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_AES */
        default:
        {
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
        }
    }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (_input != NULL) {
#if DCP_USE_DCACHE == 1u
        OSA_MemoryFreeAlign(_input);
#else
        OSA_MemoryFree(_input);
#endif
    }
#endif

#if DCP_USE_DCACHE == 1u
    /* Invalidate and copy result from working buffer */
    SCB_InvalidateDCache_by_Addr(_output_cache, output_size);
    memcpy(output, _output_cache, output_size);

    /* Clean-up the data */
    memset(_output_cache, 0xff, output_size);
    if (_output_cache != NULL) {
        OSA_MemoryFreeAlign(_output_cache);
    }
    memset(_input_cache, 0xff, input_length);
    if (_input_cache != NULL) {
        OSA_MemoryFreeAlign(_input_cache);
    }
#endif

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (status != PSA_SUCCESS) {
        return status;
    }

    status = dcp_to_psa_status(dcp_status);

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (alg == PSA_ALG_CBC_PKCS7) {
        *output_length = _input_length;
    } else
#endif
    {
        *output_length = input_length;
    }

    return status;
}

psa_status_t dcp_cipher_decrypt(const psa_key_attributes_t *attributes,
                                const uint8_t *key_buffer,
                                size_t key_buffer_size,
                                psa_algorithm_t alg,
                                const uint8_t *input,
                                size_t input_length,
                                uint8_t *output,
                                size_t output_size,
                                size_t *output_length)
{
    psa_status_t status         = PSA_ERROR_CORRUPTION_DETECTED;
    status_t dcp_status         = kStatus_Fail;
    psa_key_type_t key_type     = psa_get_key_type(attributes);
    size_t key_bits             = psa_get_key_bits(attributes);
    uint32_t iv_length          = 0;
    uint32_t expected_op_length = 0;
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    uint8_t *_output = NULL;
    uint8_t i;
#endif
#if DCP_USE_DCACHE == 1u
    uint8_t *_input_cache = NULL;
    uint8_t *_output_cache = NULL;
#endif
    
    dcp_handle_t m_handle;
    m_handle.channel    = kDCP_Channel0;
    m_handle.swapConfig = kDCP_NoSwap;
    m_handle.keySlot    = kDCP_KeySlot0;
    
    if (!PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check supported algorithm */
    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
                default:
                {
                    return PSA_ERROR_NOT_SUPPORTED;
                }
            } /* operation->alg */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_AES */
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    if (PSA_BYTES_TO_BITS(key_buffer_size) != key_bits) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* DCP support only 128 bit keys */
    if (key_bits != 128u){
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if ((alg == PSA_ALG_ECB_NO_PADDING) && (input_length == 0)) {
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
    if (((alg == PSA_ALG_CBC_PKCS7) || (alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR))) {
        iv_length = PSA_CIPHER_IV_MAX_SIZE;
    }

    /* Input buffer -> IV + INPUT.
     * So output length would be (input - iv_length)
     */
    if (mcux_psa_sub_size_t_wrapcheck(input_length, (size_t)iv_length)) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    expected_op_length = input_length - iv_length;

    /* Input length has to be multiple of block size for decrypt operation */
    if (((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CBC_PKCS7) ||
         (alg == PSA_ALG_ECB_NO_PADDING)) &&
        (expected_op_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (output_size < expected_op_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Set key */
    status = DCP_AES_SetKey(PSA_DCP, &m_handle, key_buffer, key_buffer_size);
    if (status != kStatus_Success) {
        return dcp_to_psa_status(status);
    }

#if DCP_USE_DCACHE == 1u
    /* Allocate aligned buffers with sufficient traling memory for safe clean/invalidate */
    _input_cache = OSA_MemoryAllocateAlign(ALIGNED_SIZE(input_length), FSL_FEATURE_L1DCACHE_LINESIZE_BYTE);
    if (_input_cache == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
 
    _output_cache = OSA_MemoryAllocateAlign(ALIGNED_SIZE(output_size), FSL_FEATURE_L1DCACHE_LINESIZE_BYTE);
    if (_output_cache == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
    /* Copy and clean input data in working buffer */
    memcpy(_input_cache, input, input_length);
    SCB_CleanDCache_by_Addr(_input_cache, input_length);
#endif

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (alg == PSA_ALG_CBC_PKCS7) {
#if DCP_USE_DCACHE == 1u
        _output = OSA_MemoryAllocateAlign(ALIGNED_SIZE(expected_op_length), FSL_FEATURE_L1DCACHE_LINESIZE_BYTE);
#else
        _output = OSA_MemoryAllocate(expected_op_length);
#endif
        if (_output == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
    }
#endif /* DCP_USE_DCACHE */
    
    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
                    dcp_status =
#if DCP_USE_DCACHE == 1u
                      DCP_AES_DecryptCbc(PSA_DCP,
                                           &m_handle,
                                           &_input_cache[iv_length],
                                           _output,
                                           expected_op_length,
                                           input);
#else
                      DCP_AES_DecryptCbc(PSA_DCP,
                                           &m_handle,
                                           &input[iv_length],
                                           _output,
                                           expected_op_length,
                                           input);
#endif /* DCP_USE_DCACHE */
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    dcp_status =
#if DCP_USE_DCACHE == 1u
                        DCP_AES_DecryptCbc(PSA_DCP,
                                           &m_handle,
                                           &_input_cache[iv_length],
                                           _output_cache,
                                           expected_op_length,
                                           input);
#else
                        DCP_AES_DecryptCbc(PSA_DCP,
                                           &m_handle,
                                           &input[iv_length],
                                           output,
                                           expected_op_length,
                                           input);
#endif /* DCP_USE_DCACHE */
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    dcp_status =
#if DCP_USE_DCACHE == 1u
                        DCP_AES_DecryptEcb(PSA_DCP, &m_handle, _input_cache, _output_cache, input_length);
#else
                        DCP_AES_DecryptEcb(PSA_DCP, &m_handle, input, output, input_length);
#endif /* DCP_USE_DCACHE */
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
                default:
                {
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
                }
            } /* operation->alg */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_AES */
        default:
        {
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
        }
    }

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        status = PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS) {
        status = dcp_to_psa_status(dcp_status);
    }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    /* Based on last byte, identify plaintext and copy to the final buffer. */
    if (alg == PSA_ALG_CBC_PKCS7) {
#if DCP_USE_DCACHE == 1u
       SCB_InvalidateDCache_by_Addr(_output, ALIGNED_SIZE(expected_op_length));
#endif /* DCP_USE_DCACHE */
       if (status == PSA_SUCCESS) {
            if (_output[expected_op_length - 1] > PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)) {
                status = PSA_ERROR_INVALID_PADDING;
            }
        }
        if (status == PSA_SUCCESS) {
            for (i = 0; i < _output[expected_op_length - 1]; i++) {
                if (_output[expected_op_length - i - 1] != _output[expected_op_length - 1]) {
                    status = PSA_ERROR_INVALID_PADDING;
                    break;
                }
            }
        }
        if (status == PSA_SUCCESS) {
            if (expected_op_length - _output[expected_op_length - 1] > output_size) {
                status = PSA_ERROR_BUFFER_TOO_SMALL;
            } else {
                *output_length = expected_op_length - _output[expected_op_length - 1];
                memcpy(output, _output, *output_length);
            }
        }
        if (_output != NULL) {
#if DCP_USE_DCACHE == 1u
            OSA_MemoryFreeAlign(_output);
#else
            OSA_MemoryFree(_output);
#endif
        }
    } else
#endif
    {
#if DCP_USE_DCACHE == 1u
        /* Invalidate and copy result from working buffer */
        SCB_InvalidateDCache_by_Addr(_output_cache, expected_op_length);
        memcpy(output, _output_cache, output_size);
#endif
        if (status == PSA_SUCCESS) {
            *output_length = expected_op_length;
        }
    }

#if DCP_USE_DCACHE == 1u
    /* Clean-up the data */
    memset(_output_cache, 0xff, output_size);
    if (_output_cache != NULL) {
        OSA_MemoryFreeAlign(_output_cache);
    }
    memset(_input_cache, 0xff, input_length);
    if (_input_cache != NULL) {
        OSA_MemoryFreeAlign(_input_cache);
    }
#endif /* DCP_USE_DCACHE */
    
    return status;
}
