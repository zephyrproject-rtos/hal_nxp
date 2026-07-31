/*! *********************************************************************************
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * \file
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "sss_crypto.h"

/*! *********************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
********************************************************************************** */

void SSS_md_hmac_sha256_init(sss_hmac_sha256_context_t *ctx)
{
    (void)memset(ctx, 0, sizeof(sss_hmac_sha256_context_t));
}

status_t SSS_md_hmac_sha256_clone(sss_hmac_sha256_context_t *dst, const sss_hmac_sha256_context_t *src)
{
    status_t status;

    if (dst == NULL || src == NULL)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        SSS_sha256_clone(&dst->md_ctx, &src->md_ctx);
        status = kStatus_Success;
    }

    return status;
}

void SSS_md_hmac_sha256_free(sss_hmac_sha256_context_t *ctx)
{
    (void)memset(ctx, 0, sizeof(sss_hmac_sha256_context_t));
}

status_t SSS_md_hmac_sha256_starts(sss_hmac_sha256_context_t *ctx, const unsigned char *key, size_t keylen)
{
    status_t ret                           = kStatus_Fail;
    unsigned char sum[MD_HMAC_SHA256_SIZE] = {0};
    unsigned char *ipad, *opad;
    size_t i;

    do
    {
        if (ctx == NULL)
            RAISE_ERROR(ret, kStatus_InvalidArgument);

        if (keylen > (size_t)MD_HMAC_SHA256_BLOCK_SIZE)
        {
            if ((SSS_sha256_ret(key, keylen, sum, false)) != kStatus_Success)
            {
                break;
            }
            keylen = MD_HMAC_SHA256_SIZE;
            key    = sum;
        }

        ipad = (unsigned char *)ctx->hmac_ctx.ipad;
        opad = (unsigned char *)ctx->hmac_ctx.opad;

        (void)memset(ipad, 0x36, MD_HMAC_SHA256_BLOCK_SIZE);
        (void)memset(opad, 0x5C, MD_HMAC_SHA256_BLOCK_SIZE);

        for (i = 0; i < keylen; i++)
        {
            unsigned char keybyte = key[i];
            ipad[i] ^= keybyte;
            opad[i] ^= keybyte;
        }
        if ((SSS_sha256_starts_ret(&ctx->md_ctx, false)) != kStatus_Success)
        {
            break;
        }

        if ((SSS_sha256_update_ret(&ctx->md_ctx, ipad, MD_HMAC_SHA256_BLOCK_SIZE)) != kStatus_Success)
        {
            break;
        }
        ret = kStatus_Success;
    } while (false);

    /* Cleanup the stacked sum array before leaving :
     * has been used  only if key was larger than block size */
    (void)memset(sum, 0, sizeof(sum));

    return (ret);
}

status_t SSS_md_hmac_sha256_update(sss_hmac_sha256_context_t *ctx, const unsigned char *input, size_t ilen)
{
    status_t ret = kStatus_InvalidArgument;

    if (ctx != NULL)
    {
        ret = SSS_sha256_update_ret(&ctx->md_ctx, input, ilen);
    }
    return ret;
}

status_t SSS_md_hmac_sha256_finish(sss_hmac_sha256_context_t *ctx, unsigned char *output)
{
    status_t ret       = kStatus_Fail;
    unsigned char *tmp = &ctx->hmac_ctx.tmp[0];
    unsigned char *opad;
    do
    {
        if (ctx == NULL)
        {
            RAISE_ERROR(ret, kStatus_InvalidArgument);
        }

        opad = (unsigned char *)&ctx->hmac_ctx.opad[0];

        if ((ret = SSS_sha256_finish_ret(&ctx->md_ctx, tmp)) != kStatus_Success)
        {
            break;
        }
        if ((ret = SSS_sha256_starts_ret(&ctx->md_ctx, false)) != kStatus_Success)
        {
            break;
        }
        if ((ret = SSS_sha256_update_ret(&ctx->md_ctx, opad, MD_HMAC_SHA256_BLOCK_SIZE)) != kStatus_Success)
        {
            break;
        }
        if ((ret = SSS_sha256_update_ret(&ctx->md_ctx, tmp, MD_HMAC_SHA256_SIZE)) != kStatus_Success)
        {
            break;
        }
        ret = SSS_sha256_finish_ret(&ctx->md_ctx, output);
    } while (false);

    return ret;
}

status_t SSS_md_hmac_sha256_reset(sss_hmac_sha256_context_t *ctx)
{
    status_t status = kStatus_Fail;

    do
    {
        unsigned char *ipad;

        if (ctx == NULL)
            RAISE_ERROR(status, kStatus_InvalidArgument);

        ipad = (unsigned char *)ctx->hmac_ctx.ipad;

        if ((status = SSS_sha256_starts_ret(&ctx->md_ctx, false)) != kStatus_Success)
        {
            break;
        }
        status = SSS_sha256_update_ret(&ctx->md_ctx, ipad, MD_HMAC_SHA256_BLOCK_SIZE);
    } while (false);
    return status;
}

status_t SSS_md_hmac_sha256(sss_hmac_sha256_context_t *pCtx,
                            const unsigned char *key,
                            size_t keylen,
                            const unsigned char *input,
                            size_t ilen,
                            unsigned char *output)
{
    /* Relatively big context on the stack */
    status_t status = kStatus_Fail;

    SSS_md_hmac_sha256_init(pCtx);
    do
    {
        if ((status = SSS_md_hmac_sha256_starts(pCtx, key, keylen)) != kStatus_Success)
        {
            break;
        }

        if ((status = SSS_md_hmac_sha256_update(pCtx, input, ilen)) != kStatus_Success)
        {
            break;
        }

        if ((status = SSS_md_hmac_sha256_finish(pCtx, output)) != kStatus_Success)
        {
            break;
        }
    } while (false);

    SSS_md_hmac_sha256_free(pCtx);

    return status;
}
