/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_common_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability (single-part only, multi-part (not supported in ele) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_caam_init.h"
#include "mcux_psa_caam_common_cipher.h"
#include "mcux_psa_caam_utils.h"
#include "mcux_psa_common_key_management.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"
#include "mbedtls/platform.h"
#include "fsl_caam.h"

static inline psa_status_t caam_cipher_key_type(mcux_psa_caam_key_type_t caam_key_type,
                                                caam_key_type_t *aes_key_type)
{
    switch (caam_key_type) {
        case MCUX_PSA_CAAM_KEY_TYPE_NONE:
        {
            *aes_key_type = kCAAM_Key_Type_None;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_ECB:
        {
            *aes_key_type = kCAAM_Key_Type_Ecb_Jkek;
            break;
        }
        case MCUX_PSA_CAAM_KEY_TYPE_CCM:
        {
            *aes_key_type = kCAAM_Key_Type_Ccm_Jkek;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}

static status_t W_CAAM_DES_EncryptEcb(CAAM_Type *base,
                                      caam_handle_t *handle,
                                      const uint8_t *plaintext,
                                      uint8_t *ciphertext,
                                      size_t size,
                                      const uint8_t iv[CAAM_DES_IV_SIZE],
                                      const uint8_t key[CAAM_DES_KEY_SIZE])
{
    return CAAM_DES_EncryptEcb(base, handle, plaintext, ciphertext, size, key);
}

static status_t W_CAAM_DES2_EncryptEcb(CAAM_Type *base,
                                       caam_handle_t *handle,
                                       const uint8_t *plaintext,
                                       uint8_t *ciphertext,
                                       size_t size,
                                       const uint8_t iv[CAAM_DES_IV_SIZE],
                                       const uint8_t key[CAAM_DES_KEY_SIZE],
                                       const uint8_t key2[CAAM_DES_KEY_SIZE])
{
    return CAAM_DES2_EncryptEcb(base, handle, plaintext, ciphertext, size, key, key2);
}

static status_t W_CAAM_DES3_EncryptEcb(CAAM_Type *base,
                                       caam_handle_t *handle,
                                       const uint8_t *plaintext,
                                       uint8_t *ciphertext,
                                       size_t size,
                                       const uint8_t iv[CAAM_DES_IV_SIZE],
                                       const uint8_t key[CAAM_DES_KEY_SIZE],
                                       const uint8_t key2[CAAM_DES_KEY_SIZE],
                                       const uint8_t key3[CAAM_DES_KEY_SIZE])
{
    return CAAM_DES3_EncryptEcb(base, handle, plaintext, ciphertext, size, key, key2, key3);
}

status_t W_CAAM_DES_DecryptEcb(CAAM_Type *base,
                               caam_handle_t *handle,
                               const uint8_t *ciphertext,
                               uint8_t *plaintext,
                               size_t size,
                               const uint8_t iv[CAAM_DES_IV_SIZE],
                               const uint8_t key[CAAM_DES_KEY_SIZE])
{
    return CAAM_DES_EncryptEcb(base, handle, ciphertext, plaintext, size, key);
}

status_t W_CAAM_DES2_DecryptEcb(CAAM_Type *base,
                                caam_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[CAAM_DES_IV_SIZE],
                                const uint8_t key[CAAM_DES_KEY_SIZE],
                                const uint8_t key2[CAAM_DES_KEY_SIZE])
{
    return CAAM_DES2_EncryptEcb(base, handle, ciphertext, plaintext, size, key, key2);
}

status_t W_CAAM_DES3_DecryptEcb(CAAM_Type *base,
                                caam_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[CAAM_DES_IV_SIZE],
                                const uint8_t key[CAAM_DES_KEY_SIZE],
                                const uint8_t key2[CAAM_DES_KEY_SIZE],
                                const uint8_t key3[CAAM_DES_KEY_SIZE])
{
    return CAAM_DES3_EncryptEcb(base, handle, ciphertext, plaintext, size, key, key2, key3);
}

typedef enum _caam_des_type {
    CAAM_DES_TYPE_ECB = 0,
    CAAM_DES_TYPE_CBC = 1,
    CAAM_DES_TYPE_CFB = 2,
    CAAM_DES_TYPE_OFB = 3
} caam_des_type_t;

typedef struct _caam_des_f {
    status_t (*des1)(CAAM_Type *base,
                     caam_handle_t *handle,
                     const uint8_t *data1,
                     uint8_t *data2,
                     size_t size,
                     const uint8_t iv[CAAM_DES_IV_SIZE],
                     const uint8_t key1[CAAM_DES_KEY_SIZE]);
    status_t (*des2)(CAAM_Type *base,
                     caam_handle_t *handle,
                     const uint8_t *data1,
                     uint8_t *data2,
                     size_t size,
                     const uint8_t iv[CAAM_DES_IV_SIZE],
                     const uint8_t key1[CAAM_DES_KEY_SIZE],
                     const uint8_t key2[CAAM_DES_KEY_SIZE]);
    status_t (*des3)(CAAM_Type *base,
                     caam_handle_t *handle,
                     const uint8_t *data1,
                     uint8_t *data2,
                     size_t size,
                     const uint8_t iv[CAAM_DES_IV_SIZE],
                     const uint8_t key1[CAAM_DES_KEY_SIZE],
                     const uint8_t key2[CAAM_DES_KEY_SIZE],
                     const uint8_t key3[CAAM_DES_KEY_SIZE]);
} caam_des_f_t[4];

struct _caam_des_modes {
    caam_des_f_t enc;
    caam_des_f_t dec;
} s_camm_des_types = {
    // Encryption function pointers for each cipher mode (ECB, CBC, CFB, OFB)
    .enc =
    {
        { W_CAAM_DES_EncryptEcb, W_CAAM_DES2_EncryptEcb, W_CAAM_DES3_EncryptEcb },   // ECB
        { CAAM_DES_EncryptCbc, CAAM_DES2_EncryptCbc, CAAM_DES3_EncryptCbc },         // CBC
        { CAAM_DES_EncryptCfb, CAAM_DES2_EncryptCfb, CAAM_DES3_EncryptCfb },         // CFB
        { CAAM_DES_EncryptOfb, CAAM_DES2_EncryptOfb, CAAM_DES3_EncryptOfb }          // OFB
    },
    // Decryption function pointers for each cipher mode (ECB, CBC, CFB, OFB)
    .dec = {
        { W_CAAM_DES_DecryptEcb, W_CAAM_DES2_DecryptEcb, W_CAAM_DES3_DecryptEcb }, // ECB
        { CAAM_DES_DecryptCbc, CAAM_DES2_DecryptCbc, CAAM_DES3_DecryptCbc },       // CBC
        { CAAM_DES_DecryptCfb, CAAM_DES2_DecryptCfb, CAAM_DES3_DecryptCfb },       // CFB
        { CAAM_DES_DecryptOfb, CAAM_DES2_DecryptOfb, CAAM_DES3_DecryptOfb }        // OFB
    }
};

#if defined(PSA_WANT_KEY_TYPE_DES)
static inline psa_status_t caam_des_x(caam_des_type_t desType,
                                      bool isEncrypt,
                                      size_t keySize,
                                      CAAM_Type *base,
                                      caam_handle_t *handle,
                                      const uint8_t *data1,
                                      uint8_t *data2,
                                      size_t size,
                                      const uint8_t *iv,
                                      const uint8_t *key)
{
    psa_status_t status          = PSA_SUCCESS;
    caam_des_f_t *camm_des_types = (isEncrypt) ? &s_camm_des_types.enc : &s_camm_des_types.dec;

    switch (keySize / 8) {
        case 1:
        {
            status = (*camm_des_types)[desType].des1(base, handle, data1, data2, size, iv, key);
            break;
        }
        case 2:
        {
            status = (*camm_des_types)[desType].des2(base,
                                                     handle,
                                                     data1,
                                                     data2,
                                                     size,
                                                     iv,
                                                     key,
                                                     &key[8]);
            break;
        }
        case 3:
        {
            status = (*camm_des_types)[desType].des3(base,
                                                     handle,
                                                     data1,
                                                     data2,
                                                     size,
                                                     iv,
                                                     key,
                                                     &key[8],
                                                     &key[16]);
            break;
        }
        default:
        {
            status = PSA_ERROR_INVALID_ARGUMENT;
            break;
        }
    }

    return status;
}
#endif /* PSA_WANT_KEY_TYPE_DES */

psa_status_t caam_internal_cipher_encrypt(mcux_psa_caam_key_type_t caam_key_type,
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
    psa_status_t status          = PSA_SUCCESS;
    status_t caam_status         = kStatus_Fail;
    psa_key_type_t key_type      = psa_get_key_type(attributes);
    size_t key_bits              = psa_get_key_bits(attributes);
    size_t key_bytes             = PSA_BITS_TO_BYTES(key_bits);
    caam_handle_t caamHandle     = { .jobRing = kCAAM_JobRing0 };
    caam_key_type_t aes_key_type = kCAAM_Key_Type_None;
#if defined(PSA_WANT_ALG_CTR)
    uint8_t iv_temp[PSA_CIPHER_IV_MAX_SIZE];
#endif
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    uint8_t *_input      = NULL;
    size_t _input_length = 0u;
#endif

    /* Key buffer or size can't be NULL */
    if ((key_buffer == NULL) || (key_buffer_size == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Key size should match the key_bits in attribute */
    if (key_buffer_size !=
        ((caam_key_type ==
          MCUX_PSA_CAAM_KEY_TYPE_NONE) ? key_bytes : CAAM_OPAQUE_ALIGN(key_bytes))) {
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

    /* If input length or input buffer NULL, it's an error.
     * Special case for ECB where input = 0 may be allowed.
     * Taken care of in above code.
     */
    if ((input_length == 0u) || (input == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer has to be atleast Input buffer size */
    if (output_size < input_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Output buffer can't be NULL */
    if ((output == NULL) || (output_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (key_type == PSA_KEY_TYPE_AES) {
        status = caam_cipher_key_type(caam_key_type, &aes_key_type);
        if (status != PSA_SUCCESS) {
            return status;
        }
    } else if (key_type == PSA_KEY_TYPE_DES) {
        if (((key_bytes % CAAM_DES_KEY_SIZE) != 0u) ||
            ((key_bytes / CAAM_DES_KEY_SIZE) > 3u)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* IV buffer can't be NULL or size different to 16 */
    if ((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR) || (alg == PSA_ALG_CFB) ||
        (alg == PSA_ALG_OFB)) {
        if ((iv == NULL) ||
            ((key_type == PSA_KEY_TYPE_AES) && (iv_length != PSA_CIPHER_IV_MAX_SIZE)) ||
            ((key_type == PSA_KEY_TYPE_DES) && (iv_length != CAAM_DES_IV_SIZE))) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* For CBC and ECB No padding, input length has to be multiple of cipher block length */
    if (((alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_ECB_NO_PADDING)) &&
        ((input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)) > 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
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
        _input = mbedtls_calloc(1u, _input_length);
        if (_input == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
        memcpy(_input, input, input_length);
        memset(&_input[input_length],
               (int) (_input_length - input_length),
               _input_length - input_length);
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
                    caam_status = CAAM_AES_EncryptCbcExtended(PSA_CAAM,
                                                              &caamHandle,
                                                              _input,
                                                              output,
                                                              _input_length,
                                                              iv,
                                                              key_buffer,
                                                              key_bytes,
                                                              aes_key_type);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    caam_status = CAAM_AES_EncryptCbcExtended(PSA_CAAM,
                                                              &caamHandle,
                                                              input,
                                                              output,
                                                              input_length,
                                                              iv,
                                                              key_buffer,
                                                              key_bytes,
                                                              aes_key_type);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    caam_status = CAAM_AES_EncryptEcbExtended(PSA_CAAM,
                                                              &caamHandle,
                                                              input,
                                                              output,
                                                              input_length,
                                                              key_buffer,
                                                              key_bytes,
                                                              aes_key_type);
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
#if defined(PSA_WANT_ALG_CTR)
                case PSA_ALG_CTR:
                {
                    memcpy(iv_temp, iv, iv_length);
                    caam_status = CAAM_AES_CryptCtrExtended(PSA_CAAM,
                                                            &caamHandle,
                                                            input,
                                                            output,
                                                            input_length,
                                                            iv_temp,
                                                            key_buffer,
                                                            key_bytes,
                                                            NULL,
                                                            NULL,
                                                            aes_key_type);
                    break;
                }
#endif /* PSA_WANT_ALG_CTR */
                default:
                {
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
                }
            } /* operation->alg */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_DES */
#if defined(PSA_WANT_KEY_TYPE_DES)
        case PSA_KEY_TYPE_DES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
                    caam_status = caam_des_x(CAAM_DES_TYPE_CBC,
                                             true,
                                             key_bytes,
                                             PSA_CAAM,
                                             &caamHandle,
                                             _input,
                                             output,
                                             _input_length,
                                             iv,
                                             key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    caam_status = caam_des_x(CAAM_DES_TYPE_CBC,
                                             true,
                                             key_bytes,
                                             PSA_CAAM,
                                             &caamHandle,
                                             input,
                                             output,
                                             input_length,
                                             iv,
                                             key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    caam_status = caam_des_x(CAAM_DES_TYPE_ECB,
                                             true,
                                             key_bytes,
                                             PSA_CAAM,
                                             &caamHandle,
                                             input,
                                             output,
                                             input_length,
                                             NULL,
                                             key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
#if defined(PSA_WANT_ALG_CFB)
                case PSA_ALG_CFB:
                {
                    caam_status = caam_des_x(CAAM_DES_TYPE_CFB,
                                             true,
                                             key_bytes,
                                             PSA_CAAM,
                                             &caamHandle,
                                             input,
                                             output,
                                             input_length,
                                             iv,
                                             key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_CFB */
#if defined(PSA_WANT_ALG_OFB)
                case PSA_ALG_OFB:
                {
                    caam_status = caam_des_x(CAAM_DES_TYPE_OFB,
                                             true,
                                             key_bytes,
                                             PSA_CAAM,
                                             &caamHandle,
                                             input,
                                             output,
                                             input_length,
                                             iv,
                                             key_buffer);
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
#endif /* PSA_WANT_KEY_TYPE_DES */
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

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS) {
        status = caam_to_psa_status(caam_status);
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

    (void)caamHandle;

    return status;
}

psa_status_t caam_internal_cipher_encrypt_blacken(mcux_psa_caam_key_type_t caam_key_type,
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
    psa_status_t err;
    size_t key_bits  = psa_get_key_bits(attributes);
    size_t key_bytes = CAAM_OPAQUE_ALIGN(PSA_BITS_TO_BYTES(key_bits));

#if defined(USE_MALLOC)
    uint8_t *key_decap = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (key_decap == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#else
    uint8_t key_decap[CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE)];
    if (CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE) < key_bytes) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    err = caam_opaque_decapsulate_key(caam_key_type,
                                      key_buffer,
                                      key_buffer_size,
                                      key_decap,
                                      PSA_BITS_TO_BYTES(key_bits));
    if (err == PSA_SUCCESS) {
        err = caam_internal_cipher_encrypt(caam_key_type,
                                           attributes,
                                           key_decap,
                                           key_bytes,
                                           alg,
                                           iv,
                                           iv_length,
                                           input,
                                           input_length,
                                           output,
                                           output_size,
                                           output_length);
    }

#if defined(USE_MALLOC)
    mbedtls_free(key_decap);
#endif

    return err;
}

psa_status_t caam_common_cipher_encrypt(mcux_psa_caam_key_type_t caam_key_type,
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
    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        return caam_internal_cipher_encrypt(caam_key_type,
                                            attributes,
                                            key_buffer,
                                            key_buffer_size,
                                            alg,
                                            iv,
                                            iv_length,
                                            input,
                                            input_length,
                                            output,
                                            output_size,
                                            output_length);
    } else {
        return caam_internal_cipher_encrypt_blacken(caam_key_type,
                                                    attributes,
                                                    key_buffer,
                                                    key_buffer_size,
                                                    alg,
                                                    iv,
                                                    iv_length,
                                                    input,
                                                    input_length,
                                                    output,
                                                    output_size,
                                                    output_length);
    }
}

psa_status_t caam_internal_cipher_decrypt(mcux_psa_caam_key_type_t caam_key_type,
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
    psa_status_t status          = PSA_SUCCESS;
    status_t caam_status         = kStatus_Fail;
    psa_key_type_t key_type      = psa_get_key_type(attributes);
    size_t key_bits              = psa_get_key_bits(attributes);
    size_t key_bytes             = PSA_BITS_TO_BYTES(key_bits);
    caam_handle_t caamHandle     = { .jobRing = kCAAM_JobRing0 };
    uint32_t iv_length           = 0;
    uint32_t expected_op_length  = 0;
    caam_key_type_t aes_key_type = kCAAM_Key_Type_None;;
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
#if defined(PSA_WANT_KEY_TYPE_DES)
        case PSA_WANT_KEY_TYPE_DES:
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
#if defined(PSA_WANT_ALG_CFB)
                case PSA_ALG_CFB:
                {
                    break;
                }
#endif /* PSA_WANT_ALG_CFB */
#if defined(PSA_WANT_ALG_OFB)
                case PSA_ALG_OFB:
                {
                    break;
                }
#endif /* PSA_WANT_ALG_OFB */
                default:
                {
                    return PSA_ERROR_NOT_SUPPORTED;
                }
            } /* operation->alg */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_DES */
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    if (key_buffer_size !=
        ((caam_key_type ==
          MCUX_PSA_CAAM_KEY_TYPE_NONE) ? key_bytes : CAAM_OPAQUE_ALIGN(key_bytes))) {
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
    if ((input_length == 0u) || (input == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer can't be NULL */
    if ((output == NULL) || (output_length == 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (key_type == PSA_KEY_TYPE_AES) {
        status = caam_cipher_key_type(caam_key_type, &aes_key_type);
        if (status != PSA_SUCCESS) {
            return status;
        }
    } else if (key_type == PSA_KEY_TYPE_DES) {
        if (((key_bytes % CAAM_DES_KEY_SIZE) != 0u) ||
            ((key_bytes / CAAM_DES_KEY_SIZE) > 3u)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* IV buffer can't be NULL or size different to 16 */
    if ((alg == PSA_ALG_CBC_PKCS7) || (alg == PSA_ALG_CBC_NO_PADDING) || (alg == PSA_ALG_CTR) ||
        (alg == PSA_ALG_CFB) ||
        (alg == PSA_ALG_OFB)) {
        if (key_type == PSA_KEY_TYPE_AES) {
            iv_length = PSA_CIPHER_IV_MAX_SIZE;
        } else if (key_type == PSA_KEY_TYPE_DES) {
            iv_length = CAAM_DES_IV_SIZE;
        }
    }

    /* Input buffer -> IV + INPUT.
     * So output length would be (input - iv_length)
     */
    expected_op_length = input_length - iv_length;

    /* Input length has to be multiple of block size for decrypt operation */
    if ((alg == PSA_ALG_CBC_NO_PADDING || alg == PSA_ALG_CBC_PKCS7 ||
         alg == PSA_ALG_ECB_NO_PADDING) &&
        ((expected_op_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)) > 0u)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((alg != PSA_ALG_CBC_PKCS7) && (output_size < expected_op_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (alg == PSA_ALG_CBC_PKCS7) {
        _output = mbedtls_calloc(1u, expected_op_length);
        if (_output == NULL) {
            return PSA_ERROR_INSUFFICIENT_MEMORY;
        }
    }
#endif

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
                    caam_status =
                        CAAM_AES_DecryptCbcExtended(PSA_CAAM,
                                                    &caamHandle,
                                                    &input[iv_length],
                                                    _output,
                                                    expected_op_length,
                                                    input,
                                                    key_buffer,
                                                    key_bytes,
                                                    aes_key_type);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    caam_status =
                        CAAM_AES_DecryptCbcExtended(PSA_CAAM,
                                                    &caamHandle,
                                                    &input[iv_length],
                                                    output,
                                                    expected_op_length,
                                                    input,
                                                    key_buffer,
                                                    key_bytes,
                                                    aes_key_type);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    caam_status = CAAM_AES_DecryptEcb(PSA_CAAM,
                                                      &caamHandle,
                                                      input,
                                                      output,
                                                      input_length,
                                                      key_buffer,
                                                      key_bytes);
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
#if defined(PSA_WANT_ALG_CTR)
                case PSA_ALG_CTR:
                {
                    memcpy(iv_temp, input, iv_length);
                    caam_status =
                        CAAM_AES_CryptCtrExtended(PSA_CAAM,
                                                  &caamHandle,
                                                  &input[iv_length],
                                                  output,
                                                  expected_op_length,
                                                  iv_temp,
                                                  key_buffer,
                                                  key_bytes,
                                                  NULL,
                                                  NULL,
                                                  aes_key_type);
                    break;
                }
#endif /* PSA_WANT_ALG_CTR */
                default:
                {
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
                }
            } /* operation->alg */
            break;
        }
#endif /* PSA_WANT_KEY_TYPE_AES */
#if defined(PSA_WANT_KEY_TYPE_DES)
        case PSA_WANT_KEY_TYPE_DES:
        {
            switch (alg) {
#if defined(PSA_WANT_ALG_CBC_PKCS7)
                case PSA_ALG_CBC_PKCS7:
                {
                    status = caam_des_x(CAAM_DES_TYPE_CBC,
                                        true,
                                        key_bytes,
                                        PSA_CAAM,
                                        &caamHandle,
                                        &input[iv_length],
                                        _output,
                                        expected_op_length,
                                        input,
                                        key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_PKCS7 */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
                case PSA_ALG_CBC_NO_PADDING:
                {
                    status = caam_des_x(CAAM_DES_TYPE_CBC,
                                        true,
                                        key_bytes,
                                        PSA_CAAM,
                                        &caamHandle,
                                        &input[iv_length],
                                        output,
                                        expected_op_length,
                                        input,
                                        key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_CBC_NO_PADDING */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
                case PSA_ALG_ECB_NO_PADDING:
                {
                    status = caam_des_x(CAAM_DES_TYPE_ECB,
                                        true,
                                        key_bytes,
                                        PSA_CAAM,
                                        &caamHandle,
                                        input,
                                        output,
                                        input_length,
                                        NULL,
                                        key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_ECB_NO_PADDING */
#if defined(PSA_WANT_ALG_CFB)
                case PSA_ALG_CFB:
                {
                    status = caam_des_x(CAAM_DES_TYPE_CFB,
                                        true,
                                        key_bytes,
                                        PSA_CAAM,
                                        &caamHandle,
                                        &input[iv_length],
                                        output,
                                        expected_op_length,
                                        input,
                                        key_buffer);
                    break;
                }
#endif /* PSA_WANT_ALG_CFB */
#if defined(PSA_WANT_ALG_OFB)
                case PSA_ALG_OFB:
                {
                    status = caam_des_x(CAAM_DES_TYPE_OFB,
                                        true,
                                        key_bytes,
                                        PSA_CAAM,
                                        &caamHandle,
                                        &input[iv_length],
                                        output,
                                        expected_op_length,
                                        input,
                                        key_buffer);
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
#endif /* PSA_WANT_KEY_TYPE_DES */
        default:
        {
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
        }
    }

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        status = PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS) {
        status = caam_to_psa_status(caam_status);
    }

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    if (alg == PSA_ALG_CBC_PKCS7) {
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
            mbedtls_free(_output);
        }
    } else
#endif
    {
        if (status == PSA_SUCCESS) {
            *output_length = expected_op_length;
        }
    }

    (void)caamHandle;

    return status;
}

psa_status_t caam_internal_cipher_decrypt_blacken(mcux_psa_caam_key_type_t caam_key_type,
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
    psa_status_t err;
    size_t key_bits  = psa_get_key_bits(attributes);
    size_t key_bytes = CAAM_OPAQUE_ALIGN(PSA_BITS_TO_BYTES(key_bits));

#if defined(USE_MALLOC)
    uint8_t *key_decap = (uint8_t *) mbedtls_calloc(1u, key_bytes);
    if (key_decap == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#else
    uint8_t key_decap[CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE)];
    if (CAAM_OPAQUE_ALIGN(MAX_AES_KEYSIZE) < key_bytes) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
#endif

    err = caam_opaque_decapsulate_key(caam_key_type,
                                      key_buffer,
                                      key_buffer_size,
                                      key_decap,
                                      PSA_BITS_TO_BYTES(key_bits));
    if (err == PSA_SUCCESS) {
        err = caam_internal_cipher_decrypt(caam_key_type,
                                           attributes,
                                           key_decap,
                                           key_bytes,
                                           alg,
                                           input,
                                           input_length,
                                           output,
                                           output_size,
                                           output_length);
    }

#if defined(USE_MALLOC)
    mbedtls_free(key_decap);
#endif

    return err;
}

psa_status_t caam_common_cipher_decrypt(mcux_psa_caam_key_type_t caam_key_type,
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
    if (caam_key_type == MCUX_PSA_CAAM_KEY_TYPE_NONE) {
        return caam_internal_cipher_decrypt(caam_key_type,
                                            attributes,
                                            key_buffer,
                                            key_buffer_size,
                                            alg,
                                            input,
                                            input_length,
                                            output,
                                            output_size,
                                            output_length);
    } else {
        return caam_internal_cipher_decrypt_blacken(caam_key_type,
                                                    attributes,
                                                    key_buffer,
                                                    key_buffer_size,
                                                    alg,
                                                    input,
                                                    input_length,
                                                    output,
                                                    output_size,
                                                    output_length);
    }
}
