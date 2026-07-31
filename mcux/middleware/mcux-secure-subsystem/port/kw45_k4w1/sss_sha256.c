/*! *********************************************************************************
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * \file
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */
/*
 *  FIPS-180-2 compliant SHA-256 implementation
 *
 *  The SHA-256 Secure Hash Standard was published by NIST in 2002.
 *
 *  csrc.nist.gov/publications/fips/fips180-2/fips180-2.pdf
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sss_crypto.h"

void SSS_sha256_init(sss_sha256_context_t *p_ctx)
{
    assert(p_ctx != NULL);

    (void)memset(p_ctx, 0, sizeof(sss_sha256_context_t));
}

void SSS_sha256_free(sss_sha256_context_t *p_ctx)
{
    if (p_ctx != NULL)
    {
        (void)memset(p_ctx, 0, sizeof(sss_sha256_context_t));
    }
}

void SSS_sha256_clone(sss_sha256_context_t *dst, const sss_sha256_context_t *src)
{
    assert(dst != NULL);
    assert(src != NULL);

    *dst = *src;
}

/*
 * SHA-256 context setup
 */
status_t SSS_sha256_starts_ret(sss_sha256_context_t *ctx, bool is_sha224)
{
    status_t status;
    sss_algorithm_t alg = is_sha224 ? kAlgorithm_SSS_SHA224 : kAlgorithm_SSS_SHA256;
    do
    {
        if (ctx == NULL)
        {
            RAISE_ERROR(status, kStatus_InvalidArgument);
        }
        if ((status = CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }

        if ((sss_sscp_digest_context_init(&ctx->ctx, &g_sssSession, alg, kMode_SSS_Digest)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }
        if ((sss_sscp_digest_init(&ctx->ctx)) != kStatus_SSS_Success)
        {
            (void)sss_sscp_digest_context_free(&ctx->ctx);
            status = kStatus_Fail;
            break;
        }

    } while (false);
    return status;
}

/*
 * SHA-256 process buffer
 */
status_t SSS_sha256_update_ret(sss_sha256_context_t *ctx, const unsigned char *input, size_t ilen)
{
    status_t status;
    do
    {
        if ((status = CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }
        if ((sss_sscp_digest_update(&ctx->ctx, (uint8_t *)(uintptr_t)input, ilen)) != kStatus_SSS_Success)
        {
            (void)sss_sscp_digest_context_free(&ctx->ctx);
            status = kStatus_Fail;
            break;
        }
    } while (false);
    return status;
}

/*
 * SHA-256 final digest
 */
status_t SSS_sha256_finish_ret(sss_sha256_context_t *ctx, unsigned char output[32])
{
    status_t status;
    size_t len = ctx->ctx.digestFullLen;
    do
    {
        if ((status = CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }
        if ((sss_sscp_digest_finish(&ctx->ctx, output, &len)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
        }
        else
        {
            status = kStatus_Success;
        }

        (void)sss_sscp_digest_context_free(&ctx->ctx);
    } while (false);
    return status;
}

/*
 * output = SHA-256( input buffer )
 */
status_t SSS_sha256_ret(const unsigned char *input, size_t ilen, unsigned char output[32], bool is_sha224)
{
    status_t status;
    sss_sscp_digest_t dctx;
    sss_algorithm_t alg = is_sha224 ? kAlgorithm_SSS_SHA224 : kAlgorithm_SSS_SHA256;

    size_t size = 32u;
    do
    {
        if ((status = CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }
        if ((sss_sscp_digest_context_init(&dctx, &g_sssSession, alg, kMode_SSS_Digest)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }

        if ((sss_sscp_digest_one_go(&dctx, input, ilen, output, &size)) != kStatus_SSS_Success)
        {
            status = kStatus_Fail;
            break;
        }

        (void)sss_sscp_digest_context_free(&dctx);
    } while (false);
    return status;
}
