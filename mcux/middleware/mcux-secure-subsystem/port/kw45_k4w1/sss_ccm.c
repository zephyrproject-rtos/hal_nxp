/*! *********************************************************************************
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * \file
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */

#include "fsl_device_registers.h"
#include "fsl_sss_sscp.h"
#include "fsl_sss_api.h"
#include "sss_crypto.h"

/******************************************************************************
*******************************************************************************
* Private Prototypes
*******************************************************************************
******************************************************************************/

static status_t sss_ccm_auth_crypt(sss_ccm_context_t *ctx,
                                   sss_mode_t sssMode,
                                   size_t length,
                                   const unsigned char *iv,
                                   size_t iv_len,
                                   const unsigned char *add,
                                   size_t add_len,
                                   const unsigned char *input,
                                   unsigned char *output,
                                   unsigned char *tag,
                                   size_t tag_len);

/*! *********************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
********************************************************************************** */
status_t SSS_ccm_setkey(sss_ccm_context_t *ctx, const unsigned char *key, unsigned int keybits)
{
    status_t status;
    assert(keybits == 128u || keybits == 192u || keybits == 256u);
    do
    {
        uint8_t ramKey[32];
        uint32_t key_bytes = keybits >> 3u;
        (void)memcpy(ramKey, key, key_bytes);
        if ((status = CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }
        if ((sss_sscp_key_object_init(&ctx->key, &g_keyStore)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }
        if ((SSS_KEY_ALLOCATE_HANDLE(&ctx->key, 1u, kSSS_KeyPart_Default, kSSS_CipherType_AES, key_bytes,
                                     SSS_KEYPROP_OPERATION_AEAD)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }

        if ((SSS_KEY_STORE_SET_KEY(&ctx->key, ramKey, key_bytes, keybits, kSSS_KeyPart_Default)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }

    } while (false);

    return status;
}

/*
 * Free context
 */
void SSS_ccm_free(sss_ccm_context_t *ctx)
{
    do
    {
        if (ctx == NULL)
        {
            break;
        }
        if (CRYPTO_InitHardware() != kStatus_Success)
        {
            break;
        }
        if (SSS_KEY_OBJ_FREE(&ctx->key) != kStatus_SSS_Success)
        {
            break;
        }
        (void)memset(ctx, 0, sizeof(sss_ccm_context_t));
    } while (false);
}

/*
 * Authenticated encryption
 */

status_t SSS_ccm_encrypt_and_tag(sss_ccm_context_t *ctx,
                                 size_t length,
                                 const unsigned char *iv,
                                 size_t iv_len,
                                 const unsigned char *add,
                                 size_t add_len,
                                 const unsigned char *input,
                                 unsigned char *output,
                                 unsigned char *tag,
                                 size_t tag_len)
{
    status_t status;
    do
    {
#ifdef DEBUG
        if (ctx == NULL)
            RAISE_ERROR(status, kStatus_InvalidArgument);

        if (iv == NULL)
            RAISE_ERROR(status, kStatus_InvalidArgument);

        if ((add_len != 0u) && (add == NULL))
            RAISE_ERROR(status, kStatus_InvalidArgument);

        if ((length != 0u) && ((input == NULL) || (output == NULL)))
            RAISE_ERROR(status, kStatus_InvalidArgument);

        if ((tag_len != 0u) && (tag == NULL))
            RAISE_ERROR(status, kStatus_InvalidArgument);
#endif
        status = sss_ccm_auth_crypt(ctx, kMode_SSS_Encrypt, length, iv, iv_len, add, add_len, input, output,
                                    (unsigned char *)(uintptr_t)tag, tag_len);
    } while (false);

    return status;
}

/*
 * Authenticated decryption
 */
status_t SSS_ccm_auth_decrypt(sss_ccm_context_t *ctx,
                              size_t length,
                              const unsigned char *iv,
                              size_t iv_len,
                              const unsigned char *add,
                              size_t add_len,
                              const unsigned char *input,
                              unsigned char *output,
                              const unsigned char *tag,
                              size_t tag_len)
{
    status_t status;
    do
    {
#ifdef DEBUG
        if (ctx == NULL)
        {
            RAISE_ERROR(status, kStatus_InvalidArgument);
        }

        if (iv == NULL)
        {
            RAISE_ERROR(status, kStatus_InvalidArgument);
        }

        if ((add_len != 0u) && (add == NULL))
        {
            RAISE_ERROR(status, kStatus_InvalidArgument);
        }

        if ((length != 0u) && ((input == NULL) || (output == NULL)))
        {
            RAISE_ERROR(status, kStatus_InvalidArgument);
        }

        if (tag_len != 0u)
        {
            if (tag == NULL)
            {
                RAISE_ERROR(status, kStatus_InvalidArgument);
            }
        }
        else
        {
            RAISE_ERROR(status, kStatus_InvalidArgument);
        }
#endif
        status = sss_ccm_auth_crypt(ctx, kMode_SSS_Decrypt, length, iv, iv_len, add, add_len, input, output,
                                    (unsigned char *)(uintptr_t)tag, tag_len);
    } while (false);

    return status;
}

/*! *********************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
********************************************************************************** */

static status_t sss_ccm_auth_crypt(sss_ccm_context_t *ctx,
                                   sss_mode_t sssMode,
                                   size_t length,
                                   const unsigned char *iv,
                                   size_t iv_len,
                                   const unsigned char *add,
                                   size_t add_len,
                                   const unsigned char *input,
                                   unsigned char *output,
                                   unsigned char *tag,
                                   size_t tag_len)
{
    status_t status;

    size_t tlen = tag_len;

    do
    {
        if ((status = CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }

        /* AEAD OPERATION INIT */
        if ((sss_sscp_aead_context_init(&ctx->aead_ctx, &g_sssSession, &ctx->key, kAlgorithm_SSS_AES_CCM, sssMode)) !=
            kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }
        /* RUN AEAD */
        if ((sss_sscp_aead_one_go(&ctx->aead_ctx, input, output, length, (uint8_t *)(uintptr_t)iv, iv_len, add, add_len,
                                  tag, &tlen)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
        }
        else
        {
            status = kStatus_Success;
        }

        /* FREE AEAD CONTEXT anyhow but keep status */
        if ((sss_sscp_aead_context_free(&ctx->aead_ctx)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }

    } while (false);

    return status;
}
