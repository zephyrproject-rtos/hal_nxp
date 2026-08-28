/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_hashcrypt_common_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability (single-part only, multi-part (not supported in ele) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_hashcrypt_init.h"
#include "mcux_psa_hashcrypt_common_cipher.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"

psa_status_t hashcrypt_cipher_encrypt(const psa_key_attributes_t *attributes,
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
    psa_status_t status       = PSA_SUCCESS;
    status_t hashcrypt_status = kStatus_Fail;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = PSA_BITS_TO_BYTES(key_bits);

    hashcrypt_handle_t m_handle;
    m_handle.keyType = kHASHCRYPT_UserKey;

    switch (key_bits) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case 128:
            m_handle.keySize = kHASHCRYPT_Aes128;
            break;
        case 192:
            m_handle.keySize = kHASHCRYPT_Aes192;
            break;
        case 256:
            m_handle.keySize = kHASHCRYPT_Aes256;
            break;
#endif /* PSA_WANT_KEY_TYPE_AES */
        default:
            m_handle.keySize = kHASHCRYPT_InvalidKey;
            break;
    }

#if defined(PSA_WANT_ALG_CTR)
    uint8_t iv_temp[PSA_CIPHER_IV_MAX_SIZE];
#endif
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    uint8_t *_input      = NULL;
    size_t _input_length = 0u;
#endif

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
    if (false == PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg == PSA_ALG_ECB_NO_PADDING) && (input_length == 0u)) {
        /* PSA specification is not very clear on 0 input for ECB.
         * However software implementation and the tests return SUCCESS
         * for 0 input. So adding this check here.
         */
        *output_length = 0u;
        return PSA_SUCCESS;
    }

    /* If input length or input buffer NULL, it;s an error.
     * Special case for ECB where input = 0 may be allowed.
     * Taken care of in above code.
     */
    if (NULL == input || 0u == input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer has to be atleast Input buffer size */
    if (output_size < input_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Output buffer can't be NULL */
    if (NULL == output || NULL == output_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* IV buffer can't be NULL or size different to 16 */
    if ((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR) || (alg == PSA_ALG_CFB) ||
        (alg == PSA_ALG_OFB)) {
        if ((NULL == iv) || ((key_type == PSA_KEY_TYPE_AES) && (iv_length != PSA_CIPHER_IV_MAX_SIZE))) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* For CBC and ECB No padding, input length has to be multiple of cipher block length */
    if (((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_ECB_NO_PADDING)) &&
        (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type) != 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (alg == PSA_ALG_CBC_PKCS7) {
        _input_length =
            (input_length + PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)) &
            -PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type);
        if (output_size < _input_length) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
        _input = mbedtls_calloc(1, _input_length);
        if (_input == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
        (void)memcpy(_input, input, input_length);
        (void)memset(&_input[input_length], (int)(_input_length - input_length), _input_length - input_length);
    }
#endif

    /* Set key */
    status = HASHCRYPT_AES_SetKey(PSA_HASHCRYPT, &m_handle, key_buffer, key_buffer_size);
    if (status != kStatus_Success) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
        if (NULL != _input) {
            mbedtls_free(_input);
        }
#endif
        return hashcrypt_to_psa_status(status);
    }

    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
                    hashcrypt_status =
                        HASHCRYPT_AES_EncryptCbc(PSA_HASHCRYPT,
                                                 &m_handle,
                                                 _input,
                                                 output,
                                                 _input_length,
                                                 iv);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    hashcrypt_status =
                        HASHCRYPT_AES_EncryptCbc(PSA_HASHCRYPT,
                                                 &m_handle,
                                                 input,
                                                 output,
                                                 input_length,
                                                 iv);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    hashcrypt_status = HASHCRYPT_AES_EncryptEcb(PSA_HASHCRYPT,
                                                                &m_handle,
                                                                input,
                                                                output,
                                                                input_length);
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
#if defined(PSA_WANT_ALG_CTR)
                case PSA_ALG_CTR:
                {
                    (void)memcpy(iv_temp, iv, iv_length);
                    hashcrypt_status = HASHCRYPT_AES_CryptCtr(PSA_HASHCRYPT,
                                                              &m_handle,
                                                              input,
                                                              output,
                                                              input_length,
                                                              iv_temp,
                                                              NULL,
                                                              NULL);
                    break;
                }
#endif /* PSA_WANT_ALG_CTR */
#if defined(PSA_WANT_ALG_CFB)
                case PSA_ALG_CFB:
                {
                    hashcrypt_status = HASHCRYPT_AES_EncryptCfb(PSA_HASHCRYPT, &m_handle,
                                                                &input[iv_length], output,
                                                                input_length, input);
                    break;
                }
#endif /* PSA_WANT_ALG_CFB */
#if defined(PSA_WANT_ALG_OFB)
                case PSA_ALG_OFB:
                {
                    hashcrypt_status = HASHCRYPT_AES_CryptOfb(PSA_HASHCRYPT, &m_handle,
                                                              &input[iv_length], output,
                                                              input_length, input);
                    break;
                }
#endif /* PSA_WANT_ALG_OFB */
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
        mbedtls_free(_input);
    }
#endif

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS) {
        status = hashcrypt_to_psa_status(hashcrypt_status);
    }

    if (status == PSA_SUCCESS) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
        if (alg == PSA_ALG_CBC_PKCS7) {
            *output_length = _input_length;
        } else
#endif
        {
            *output_length = input_length;
        }
    }

    return status;
}

psa_status_t hashcrypt_cipher_decrypt(const psa_key_attributes_t *attributes,
                                      const uint8_t *key_buffer,
                                      size_t key_buffer_size,
                                      psa_algorithm_t alg,
                                      const uint8_t *input,
                                      size_t input_length,
                                      uint8_t *output,
                                      size_t output_size,
                                      size_t *output_length)
{
    psa_status_t status       = PSA_SUCCESS;
    status_t hashcrypt_status = kStatus_Fail;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    size_t key_bytes          = PSA_BITS_TO_BYTES(key_bits);

    hashcrypt_handle_t m_handle;
    m_handle.keyType = kHASHCRYPT_UserKey;

    switch (key_bits) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case 128:
            m_handle.keySize = kHASHCRYPT_Aes128;
            break;
        case 192:
            m_handle.keySize = kHASHCRYPT_Aes192;
            break;
        case 256:
            m_handle.keySize = kHASHCRYPT_Aes256;
            break;
#endif /* PSA_WANT_KEY_TYPE_AES */
        default:
            m_handle.keySize = kHASHCRYPT_InvalidKey;
            break;
    }

    uint32_t iv_length          = 0u;
    uint32_t expected_op_length = 0u;

#if defined(PSA_WANT_ALG_CTR)
    uint8_t iv_temp[PSA_CIPHER_IV_MAX_SIZE];
#endif
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    uint8_t *_output = NULL;
    uint8_t i;
#endif

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
#if defined(PSA_WANT_ALG_CTR)
                case PSA_ALG_CTR:
                {
                    break;
                }
#endif /* PSA_WANT_ALG_CTR */
                default:
                {
                    return PSA_ERROR_NOT_SUPPORTED;
                    break;
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

    if (key_buffer_size != key_bytes) {
        /* The attributes don't match the buffer given as input */
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (false == PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg == PSA_ALG_ECB_NO_PADDING) && (input_length == 0u)) {
        /* PSA specification is not very clear on 0 input for ECB.
         * However software implementation and the tests return SUCCESS
         * for 0 input. So adding this check here.
         */
        *output_length = 0u;
        return PSA_SUCCESS;
    }

    /* If input length or input buffer NULL, it;s an error.
     * Special case for ECB where input = 0 may be allowed.
     * Taken care of in above code.
     */
    if (NULL == input || 0u == input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer can't be NULL */
    if (NULL == output || NULL == output_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* IV buffer can't be NULL or size different to 16 */
    if ((alg == PSA_ALG_CBC_PKCS7) || (alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR) ||
        (alg == PSA_ALG_CFB) ||
        (alg == PSA_ALG_OFB)) {
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
        (expected_op_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type) != 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg != PSA_ALG_CBC_PKCS7) && (output_size < expected_op_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (alg == PSA_ALG_CBC_PKCS7) {
        _output = mbedtls_calloc(1, expected_op_length);
        if (_output == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
    }
#endif

    if (mcux_mutex_lock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Set key */
    status = HASHCRYPT_AES_SetKey(PSA_HASHCRYPT, &m_handle, key_buffer, key_buffer_size);
    if (status != kStatus_Success) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
        if (NULL != _output) {
            mbedtls_free(_output);
        }
#endif
        return hashcrypt_to_psa_status(status);
    }

    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
                    hashcrypt_status = HASHCRYPT_AES_DecryptCbc(PSA_HASHCRYPT, &m_handle,
                                                                &input[iv_length], _output,
                                                                expected_op_length, input);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    hashcrypt_status = HASHCRYPT_AES_DecryptCbc(PSA_HASHCRYPT, &m_handle,
                                                                &input[iv_length], output,
                                                                expected_op_length, input);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    hashcrypt_status = HASHCRYPT_AES_DecryptEcb(PSA_HASHCRYPT,
                                                                &m_handle,
                                                                input,
                                                                output,
                                                                input_length);
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
#if defined(PSA_WANT_ALG_CTR)
                case PSA_ALG_CTR:
                {
                    (void)memcpy(iv_temp, input, iv_length);
                    hashcrypt_status = HASHCRYPT_AES_CryptCtr(PSA_HASHCRYPT,
                                                              &m_handle,
                                                              &input[iv_length],
                                                              output,
                                                              expected_op_length,
                                                              iv_temp,
                                                              NULL,
                                                              NULL);
                    break;
                }
#endif /* PSA_WANT_ALG_CTR */
#if defined(PSA_WANT_ALG_CFB)
                case PSA_ALG_CFB:
                {
                    hashcrypt_status = HASHCRYPT_AES_DecryptCfb(PSA_HASHCRYPT, &m_handle,
                                                                &input[iv_length], output,
                                                                expected_op_length, input);
                    break;
                }
#endif /* PSA_WANT_ALG_CFB */
#if defined(PSA_WANT_ALG_OFB)
                case PSA_ALG_OFB:
                {
                    hashcrypt_status = HASHCRYPT_AES_CryptOfb(PSA_HASHCRYPT, &m_handle,
                                                              &input[iv_length], output,
                                                              expected_op_length, input);
                    break;
                }
#endif /* PSA_WANT_ALG_OFB */
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

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        status = PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS) {
        status = hashcrypt_to_psa_status(hashcrypt_status);
    }

    if (status == PSA_SUCCESS) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
        if (alg == PSA_ALG_CBC_PKCS7) {
            if (status == PSA_SUCCESS) {
                if (_output[expected_op_length - 1u] > PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)) {
                    status = PSA_ERROR_INVALID_PADDING;
                }
            }
            if (status == PSA_SUCCESS) {
                for (i = 0; i < _output[expected_op_length - 1u]; i++) {
                    if (_output[expected_op_length - i - 1u] != _output[expected_op_length - 1u]) {
                        status = PSA_ERROR_INVALID_PADDING;
                        break;
                    }
                }
            }
            if (status == PSA_SUCCESS) {
                if (expected_op_length - _output[expected_op_length - 1u] > output_size) {
                    status = PSA_ERROR_BUFFER_TOO_SMALL;
                } else {
                    *output_length = expected_op_length - _output[expected_op_length - 1u];
                    (void)memcpy(output, _output, *output_length);
                }
            }
        } else
#endif
        {
            *output_length = expected_op_length;
        }
    }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (NULL != _output) {
        mbedtls_free(_output);
    }
#endif

    return status;
}
