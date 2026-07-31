/*! *********************************************************************************
 * Copyright 2022, 2025 NXP
 * All rights reserved.
 *
 * \file
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */

#include "sss_crypto.h"

/*
LTK ciphering stuff
sss_sscp_key_store_open_key_id(&g_keyStore, ELKE_PKB__NBU_DKEY_SK)
sss_sscp_key_object_init(&keyObj__bleLTK, &g_keyStore)
sss_sscp_key_object_allocate_handle(&keyObj__bleLTK,
                                        NBU_BLE_LTK,
                                        kSSS_KeyPart_Default,
                                        kSSS_CipherType_AES,
                                        16u,
                                        SSS_KEY_STORE_GET_PLAIN_KEY_ALLOW_MASK_NONE)
*/

status_t SSS_set_aes_key(aes_context_t *ctx, const unsigned char *key, const size_t key_byte_len)
{
    status_t ret = kStatus_Fail;
    uint8_t ramKey[32];
    do
    {
        if (key_byte_len != 16u && key_byte_len != 24u && key_byte_len != 32u)
        {
            RAISE_ERROR(ret, kStatus_InvalidArgument);
        }
        (void)memcpy(ramKey, key, key_byte_len);

        if ((sss_sscp_key_object_init(&ctx->sssKey, &g_keyStore)) != kStatus_SSS_Success)
        {
            ret = kStatus_Fail;
            break;
        }

        if ((SSS_KEY_ALLOCATE_HANDLE(&ctx->sssKey, 1u, /* key id */
                                     kSSS_KeyPart_Default, kSSS_CipherType_AES, key_byte_len,
                                     SSS_KEYPROP_OPERATION_AES)) != kStatus_SSS_Success)
        {
            ret = kStatus_Fail;
            break;
        }
        if ((SSS_KEY_STORE_SET_KEY(&ctx->sssKey, ramKey, key_byte_len, (key_byte_len << 3), kSSS_KeyPart_Default)) !=
            kStatus_SSS_Success)
        {
            (void)SSS_KEY_OBJ_FREE(&ctx->sssKey);
            ret = kStatus_Fail;
            break;
        }
        ret = kStatus_Success;
    } while (false);
    return ret;
}

status_t SSS_aes_init(aes_context_t *ctx, const unsigned char *key, size_t keybits)
{
    status_t ret = kStatus_Fail;
    do
    {
        if ((CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }
        ret = SSS_set_aes_key(ctx, key, keybits >> 3);

    } while (false);
    return ret;
}

status_t SSS_aes_operation(aes_context_t *ctx,
                           const unsigned char *input,
                           size_t inputLen,
                           unsigned char *iv,
                           const unsigned char *key,
                           size_t key_bitlen,
                           unsigned char *output,
                           bool encrypt_nDecrypt,
                           sss_algorithm_t algo)
{
    status_t ret;
    size_t iv_len;
    sss_sscp_symmetric_t *symmetric_context_ptr = NULL;

    if ((ret = SSS_aes_init(ctx, key, key_bitlen)) == kStatus_Success)
    {
        do
        {
            sss_mode_t mode;
            mode = encrypt_nDecrypt ? kMode_SSS_Encrypt : kMode_SSS_Decrypt;
            if ((sss_sscp_symmetric_context_init(&ctx->cipher_ctx, &g_sssSession, &ctx->sssKey, algo, mode)) !=
                kStatus_SSS_Success)
            {
                ret = kStatus_Fail;
                break;
            }
            symmetric_context_ptr = &ctx->cipher_ctx;
            iv_len                = (iv == NULL) ? 0u : 16u;
            if ((sss_sscp_cipher_one_go(&ctx->cipher_ctx, iv, iv_len, input, output, inputLen)) != kStatus_SSS_Success)
            {
                ret = kStatus_Fail;
                break;
            }

        } while (false);

        if (symmetric_context_ptr != NULL)
        {
            if ((sss_sscp_symmetric_context_free(symmetric_context_ptr)) != kStatus_SSS_Success)
            {
                ret = kStatus_Fail;
            }
        }
        (void)SSS_KEY_OBJ_FREE(&ctx->sssKey);
    }
    return ret;
}

status_t SSS_aes128_CTR_operation(aes_context_t *ctx,
                                  const unsigned char *input,
                                  size_t inputLen,
                                  unsigned char *initialCounter,
                                  const unsigned char *key,
                                  unsigned char *output,
                                  bool encrypt_nDecrypt)
{
    status_t ret;
    sss_sscp_symmetric_t *symmetric_context_ptr = NULL;
    if ((ret = SSS_aes_init(ctx, key, 128u)) == kStatus_Success)
    {
        do
        {
            sss_mode_t mode;
            mode = encrypt_nDecrypt ? kMode_SSS_Encrypt : kMode_SSS_Decrypt;
            if ((sss_sscp_symmetric_context_init(&ctx->cipher_ctx, &g_sssSession, &ctx->sssKey, kAlgorithm_SSS_AES_CTR,
                                                 mode)) != kStatus_SSS_Success)
            {
                ret = kStatus_Fail;
                break;
            }
            symmetric_context_ptr = &ctx->cipher_ctx;
            if ((sss_sscp_cipher_one_go(&ctx->cipher_ctx, initialCounter, 16u, input, output, inputLen)) !=
                kStatus_SSS_Success)
            {
                ret = kStatus_Fail;
                break;
            }
        } while (false);

        if (symmetric_context_ptr != NULL)
        {
            if ((sss_sscp_symmetric_context_free(symmetric_context_ptr)) != kStatus_SSS_Success)
            {
                ret = kStatus_Fail;
            }
        }
        (void)SSS_KEY_OBJ_FREE(&ctx->sssKey);
    }
    return ret;
}
