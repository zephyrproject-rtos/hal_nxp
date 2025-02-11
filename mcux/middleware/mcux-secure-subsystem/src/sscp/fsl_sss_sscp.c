/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_sss_sscp.h"
#include <string.h>
#include "fsl_sss_api.h"
#include "fsl_sscp.h"
#include "fsl_sscp_commands.h"

#define NUMBER_OF_BITS_IN_BYTE                  (8u)
#define MAX_SUPPORTED_COORDINATE_LENGTH_IN_BITS (1024u)
#define NUMBER_OF_COORDINATES_PER_EC_KEY_SLOT   (3u)
#define SSS_SSCP_TUNNEL_HAVE_BUFFER_MASK        (0x80000000u)

sss_status_t sss_sscp_open_session(sss_sscp_session_t *session,
                                   uint32_t sessionId,
                                   sss_type_t subsystem,
                                   sscp_context_t *sscpctx)

{
    SSCP_BUILD_ASSURE(sizeof(sss_session_t) >= sizeof(sss_sscp_session_t), _sss_sscp_session_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    session->subsystem = subsystem;
    session->sscp      = sscpctx;
    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].value.a = (uint32_t)subsystem;
    op.params[0].value.b = sessionId;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = session;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Session;

    status = sscpctx->invoke(sscpctx, kSSCP_CMD_SSS_OpenSession, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_close_session(sss_sscp_session_t *session)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_CloseSession, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

/*******************************SYMETRIC***************************************/
sss_status_t sss_sscp_symmetric_context_init(sss_sscp_symmetric_t *context,
                                             sss_sscp_session_t *session,
                                             sss_sscp_object_t *keyObject,
                                             sss_algorithm_t algorithm,
                                             sss_mode_t mode)
{
    SSCP_BUILD_ASSURE(sizeof(sss_symmetric_t) >= sizeof(sss_sscp_symmetric_t), _sss_sscp_symmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    context->session   = session;
    context->keyObject = keyObject;
    context->algorithm = algorithm;
    context->mode      = mode;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].value.a = (uint32_t)algorithm;
    op.params[2].value.b = (uint32_t)mode;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Symmetric;

    sscp_context_t *sscpCtx = session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_SymmetricContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_cipher_one_go(
    sss_sscp_symmetric_t *context, uint8_t *iv, size_t ivLen, const uint8_t *srcData, uint8_t *destData, size_t dataLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_symmetric_t) >= sizeof(sss_sscp_symmetric_t), _sss_sscp_symmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                      kSSCP_ParamType_MemrefInputNoSize, kSSCP_ParamType_MemrefInOut,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Symmetric;

    op.params[1].memref.buffer = (uintptr_t)iv;
    op.params[1].memref.size   = ivLen;
    op.params[2].memref.buffer = (uintptr_t)srcData;
    op.params[2].memref.size   = dataLen;
    op.params[3].memref.buffer = (uintptr_t)destData;
    op.params[3].memref.size   = dataLen;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_SymmetricCipherOneGo, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_cipher_init(sss_sscp_symmetric_t *context, uint8_t *iv, size_t ivLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr   = context;
    op.params[0].context.type  = (uint32_t)kSSCP_ParamContextType_SSS_Symmetric;
    op.params[1].memref.buffer = (uintptr_t)iv;
    op.params[1].memref.size   = ivLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_SymmetricCipherInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_cipher_update(
    sss_sscp_symmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    size_t len = (destLen != NULL) ? *destLen : srcLen;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr   = context;
    op.params[0].context.type  = (uint32_t)kSSCP_ParamContextType_SSS_Symmetric;
    op.params[1].memref.buffer = (uintptr_t)srcData;
    op.params[1].memref.size   = srcLen;
    op.params[2].memref.buffer = (uintptr_t)destData;
    op.params[2].memref.size   = len;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_SymmetricCipherUpdate, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        if (destLen != NULL)
        {
            *destLen = 0u;
        }
        return kStatus_SSS_Fail;
    }

    /* update the size member of kSSCP_ParamType_MemrefOutput param with the actual byte length written to output buffer
     */
    if (destLen != NULL)
    {
        *destLen = op.params[2].memref.size;
    }
    return kStatus_SSS_Success;
}

sss_status_t sss_sscp_cipher_finish(
    sss_sscp_symmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    size_t len = (destLen != NULL) ? *destLen : srcLen;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr   = context;
    op.params[0].context.type  = (uint32_t)kSSCP_ParamContextType_SSS_Symmetric;
    op.params[1].memref.buffer = (uintptr_t)srcData;
    op.params[1].memref.size   = srcLen;
    op.params[2].memref.buffer = (uintptr_t)destData;
    op.params[2].memref.size   = len;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_SymmetricCipherFinish, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        if (destLen != NULL)
        {
            *destLen = 0u;
        }
        return kStatus_SSS_Fail;
    }

    /* update the size member of kSSCP_ParamType_MemrefOutput param with the actual byte length written to output buffer
     */
    if (destLen != NULL)
    {
        *destLen = op.params[2].memref.size;
    }
    return kStatus_SSS_Success;
}

sss_status_t sss_sscp_cipher_crypt_ctr(sss_sscp_symmetric_t *context,
                                       const uint8_t *srcData,
                                       uint8_t *destData,
                                       size_t size,
                                       uint8_t *initialCounter,
                                       uint8_t *lastEncryptedCounter,
                                       size_t *szLeft)
{
    SSCP_BUILD_ASSURE(sizeof(sss_symmetric_t) >= sizeof(sss_sscp_symmetric_t), _sss_sscp_symmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* this func specific for AES CTR */
    /* don't consider DES at the moment for the CTR mode */
    if (context->algorithm != kAlgorithm_SSS_AES_CTR)
    {
        return kStatus_SSS_InvalidArgument;
    }

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                      kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_MemrefInOut,
                                      kSSCP_ParamType_MemrefInOut, kSSCP_ParamType_MemrefInOut, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Symmetric;

    op.params[1].memref.buffer = (uintptr_t)srcData;
    op.params[1].memref.size   = size;
    op.params[2].memref.buffer = (uintptr_t)destData;
    op.params[2].memref.size   = size;
    op.params[3].memref.buffer = (uintptr_t)initialCounter;
    op.params[3].memref.size   = SSS_AES_BLOCK_SIZE;
    op.params[4].memref.buffer = (uintptr_t)lastEncryptedCounter;
    op.params[4].memref.size   = SSS_AES_BLOCK_SIZE;
    op.params[5].memref.buffer = (uintptr_t)szLeft;
    op.params[5].memref.size   = sizeof(*szLeft);

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_SymmetricCryptCtr, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}
sss_status_t sss_sscp_symmetric_context_free(sss_sscp_symmetric_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Symmetric;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_ContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}
/**********************************AEAD****************************************/

sss_status_t sss_sscp_aead_context_init(sss_sscp_aead_t *context,
                                        sss_sscp_session_t *session,
                                        sss_sscp_object_t *keyObject,
                                        sss_algorithm_t algorithm,
                                        sss_mode_t mode)
{
    SSCP_BUILD_ASSURE(sizeof(sss_aead_t) >= sizeof(sss_sscp_aead_t), _sss_sscp_aead_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    context->session   = session;
    context->keyObject = keyObject;
    context->algorithm = algorithm;
    context->mode      = mode;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].value.a = (uint32_t)algorithm;
    op.params[2].value.b = (uint32_t)mode;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Aead;

    sscp_context_t *sscpCtx = session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AeadContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_aead_one_go(sss_sscp_aead_t *context,
                                  const uint8_t *srcData,
                                  uint8_t *destData,
                                  size_t size,
                                  uint8_t *nonce,
                                  size_t nonceLen,
                                  const uint8_t *aad,
                                  size_t aadLen,
                                  uint8_t *tag,
                                  size_t *tagLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_aead_t) >= sizeof(sss_sscp_aead_t), _sss_sscp_aead_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* set paramTypes for the tag[] buffer according to mode
     * for encrypt (and authenticate) mode, the tag[] is output, written by invoked function,
     * for decrypt (and verify) mode, the tag[] is input, to be verified by invoked function
     */
    if (context->mode == kMode_SSS_Encrypt)
    {
        op.paramTypes =
            SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInputNoSize,
                              kSSCP_ParamType_MemrefOutputNoSize, kSSCP_ParamType_ValueInputSingle,
                              kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput);
    }
    else
    {
        op.paramTypes =
            SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInputNoSize,
                              kSSCP_ParamType_MemrefOutputNoSize, kSSCP_ParamType_ValueInputSingle,
                              kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput);
    }

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Aead;

    op.params[1].memref.buffer = (uintptr_t)srcData;
    op.params[2].memref.buffer = (uintptr_t)destData;
    op.params[3].value.a       = size;
    op.params[4].memref.buffer = (uintptr_t)nonce;
    op.params[4].memref.size   = nonceLen;
    op.params[5].memref.buffer = (uintptr_t)aad;
    op.params[5].memref.size   = aadLen;
    op.params[6].memref.buffer = (uintptr_t)tag;
    op.params[6].memref.size   = *tagLen;
    op.resultTypes             = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount             = 1u;
    op.result[0].value.a       = (uint32_t)tagLen;
    sscp_context_t *sscpCtx    = context->session->sscp;
    status                     = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AeadOneGo, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_aead_context_free(sss_sscp_aead_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Aead;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_ContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_aead_init(
    sss_sscp_aead_t *context, uint8_t *nonce, size_t nonceLen, size_t tagLen, size_t aadLen, size_t payloadLen)
{
    return kStatus_SSS_Fail;
}

sss_status_t sss_sscp_aead_update_aad(sss_sscp_aead_t *context, const uint8_t *aadData, size_t aadDataLen)
{
    return kStatus_SSS_Fail;
}

sss_status_t sss_sscp_aead_update(
    sss_sscp_aead_t *context, const uint8_t *srcData, size_t srcLen, uint8_t destData, size_t *destLen)
{
    return kStatus_SSS_Fail;
}

sss_status_t sss_sscp_aead_finish(sss_sscp_aead_t *context,
                                  const uint8_t *srcData,
                                  size_t srcLen,
                                  uint8_t destData,
                                  size_t *destLen,
                                  uint8_t *tag,
                                  size_t *tagLen)
{
    return kStatus_SSS_Fail;
}

/********************************DIGEST****************************************/
sss_status_t sss_sscp_digest_context_init(sss_sscp_digest_t *context,
                                          sss_sscp_session_t *session,
                                          sss_algorithm_t algorithm,
                                          sss_mode_t mode)
{
    SSCP_BUILD_ASSURE(sizeof(sss_digest_t) >= sizeof(sss_sscp_digest_t), _sss_sscp_digest_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;
    sss_status_t tmpStat = kStatus_SSS_Success;

    context->algorithm = algorithm;
    context->mode      = mode;
    context->session   = session;
    switch (algorithm)
    {
        case kAlgorithm_SSS_SHA1:
            context->digestFullLen = 20u;
            break;
        case kAlgorithm_SSS_SHA224:
            context->digestFullLen = 28u;
            break;
        case kAlgorithm_SSS_SHA256:
            context->digestFullLen = 32u;
            break;
        case kAlgorithm_SSS_SHA384:
            context->digestFullLen = 48u;
            break;
        case kAlgorithm_SSS_SHA512:
            context->digestFullLen = 64u;
            break;
        default:
            tmpStat = kStatus_SSS_Fail;
            break;
    }

    if (tmpStat == kStatus_SSS_Fail)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].value.a = (uint32_t)algorithm;
    op.params[1].value.b = (uint32_t)mode;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    sscp_context_t *sscpCtx = session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestContextInit, &op, &ret);

    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_digest_one_go(
    sss_sscp_digest_t *context, const uint8_t *message, size_t messageLen, uint8_t *digest, size_t *digestLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_digest_t) >= sizeof(sss_sscp_digest_t), _sss_sscp_digest_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* if the caller gives NULL pointer to digestLen, it is assumed that digest[] buffer is big enough to hold full
     * digest */
    size_t len = (digestLen != NULL) ? *digestLen : context->digestFullLen;

    /* if the *digestLen cannot hold full digest (per algorithm spec) return error */
    if (len < context->digestFullLen)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.params[1].memref.buffer = (uintptr_t)message;
    op.params[1].memref.size   = messageLen;
    op.params[2].memref.buffer = (uintptr_t)digest;
    op.params[2].memref.size   = len;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)digestLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestOneGo, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_digest_init(sss_sscp_digest_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_digest_update(sss_sscp_digest_t *context, uint8_t *message, size_t messageLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.params[1].memref.buffer = (uintptr_t)message;
    op.params[1].memref.size   = messageLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestUpdate, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_digest_finish(sss_sscp_digest_t *context, uint8_t *digest, size_t *digestLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* if the caller gives NULL pointer to digestLen, it is assumed that digest[] buffer is big enough to hold full
     * digest */
    size_t len = (digestLen != NULL) ? *digestLen : context->digestFullLen;

    /* if the *digestLen cannot hold full digest (per algorithm spec) return error */
    if (len < context->digestFullLen)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.params[1].memref.buffer = (uintptr_t)digest;
    op.params[1].memref.size   = len;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)digestLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestFinish, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        if (digestLen != NULL)
        {
            *digestLen = 0u;
        }
        return kStatus_SSS_Fail;
    }

    /* the size member of kSSCP_ParamType_MemrefOutput param is updated with the actual byte length written to output
     * buffer
     */
    if (digestLen != NULL)
    {
        *digestLen = op.params[1].memref.size;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_digest_context_free(sss_sscp_digest_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_ContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

/***********************************MAC****************************************/
sss_status_t sss_sscp_mac_context_init(sss_sscp_mac_t *context,
                                       sss_sscp_session_t *session,
                                       sss_sscp_object_t *keyObject,
                                       sss_algorithm_t algorithm,
                                       sss_mode_t mode)
{
    SSCP_BUILD_ASSURE(sizeof(sss_mac_t) >= sizeof(sss_sscp_mac_t), _sss_sscp_mac_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    context->algorithm = algorithm;
    context->mode      = mode;
    context->session   = session;
    context->keyObject = keyObject;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].value.a = (uint32_t)algorithm;
    op.params[2].value.b = (uint32_t)mode;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    sscp_context_t *sscpCtx = session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_mac_one_go(
    sss_sscp_mac_t *context, const uint8_t *message, size_t messageLen, uint8_t *mac, size_t *macLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_mac_t) >= sizeof(sss_sscp_mac_t), _sss_sscp_mac_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;
    size_t macSize       = (macLen != NULL) ? *macLen : 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInOut,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    op.params[1].memref.buffer = (uintptr_t)message;
    op.params[1].memref.size   = messageLen;
    op.params[2].memref.buffer = (uintptr_t)mac;
    op.params[2].memref.size   = macSize;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)macLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacOneGo, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        if (macLen != NULL)
        {
            *macLen = 0u;
        }
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_mac_init(sss_sscp_mac_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_mac_update(sss_sscp_mac_t *context, const uint8_t *message, size_t messageLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    op.params[1].memref.buffer = (uintptr_t)message;
    op.params[1].memref.size   = messageLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacUpdate, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_mac_finish(sss_sscp_mac_t *context, uint8_t *mac, size_t *macLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;
    size_t macSize       = (macLen != NULL) ? *macLen : 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    op.params[1].memref.buffer = (uintptr_t)mac;
    op.params[1].memref.size   = macSize;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)macLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacFinish, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        if (macLen != NULL)
        {
            *macLen = 0u;
        }
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_mac_context_free(sss_sscp_mac_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_ContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

/*******************************ASYMETRIC**************************************/
sss_status_t sss_sscp_asymmetric_context_init(sss_sscp_asymmetric_t *context,
                                              sss_sscp_session_t *session,
                                              sss_sscp_object_t *keyObject,
                                              sss_algorithm_t algorithm,
                                              sss_mode_t mode)
{
    SSCP_BUILD_ASSURE(sizeof(sss_digest_t) >= sizeof(sss_sscp_digest_t), _sss_sscp_digest_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    context->session   = session;
    context->keyObject = keyObject;
    context->mode      = mode;
    context->algorithm = algorithm;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].value.a = (uint32_t)algorithm;
    op.params[2].value.b = (uint32_t)mode;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    sscp_context_t *sscpCtx = session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymetricContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_encrypt(
    sss_sscp_asymmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_asymmetric_t) >= sizeof(sss_sscp_asymmetric_t), _sss_sscp_asymmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* if the caller gives NULL pointer to signatureLen, it is assumed that signature[] buffer is big enough to hold
     * full
     * signature */
    size_t len = (destLen != NULL) ? *destLen : 0u;

    /* if the *signatureLen cannot hold full signature (per algorithm spec) return error */
    if (len < context->signatureFullLen)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    op.params[1].memref.buffer = (uintptr_t)srcData;
    op.params[1].memref.size   = srcLen;
    op.params[2].memref.buffer = (uintptr_t)destData;
    op.params[2].memref.size   = len;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricEncrypt, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    /* the size member of kSSCP_ParamType_MemrefOutput param is updated with the actual byte length written to output
     * buffer
     */
    if (destLen != NULL)
    {
        *destLen = op.params[2].memref.size;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_decrypt(
    sss_sscp_asymmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_asymmetric_t) >= sizeof(sss_sscp_asymmetric_t), _sss_sscp_asymmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* if the caller gives NULL pointer to signatureLen, it is assumed that signature[] buffer is big enough to hold
     * full
     * signature */
    size_t len = (destLen != NULL) ? *destLen : 0u;

    /* if the *signatureLen cannot hold full signature (per algorithm spec) return error */
    if (len < context->signatureFullLen)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    op.params[1].memref.buffer = (uintptr_t)srcData;
    op.params[1].memref.size   = srcLen;
    op.params[2].memref.buffer = (uintptr_t)destData;
    op.params[2].memref.size   = len;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricDecrypt, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    /* the size member of kSSCP_ParamType_MemrefOutput param is updated with the actual byte length written to output
     * buffer
     */
    if (destLen != NULL)
    {
        *destLen = op.params[2].memref.size;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_sign_digest(
    sss_sscp_asymmetric_t *context, uint8_t *digest, size_t digestLen, uint8_t *signature, size_t *signatureLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_asymmetric_t) >= sizeof(sss_sscp_asymmetric_t), _sss_sscp_asymmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* if the caller gives NULL pointer to signatureLen, it is assumed that signature[] buffer is big enough to hold
     * full
     * signature */
    /*size_t len = (signatureLen != NULL) ? *signatureLen : context->signatureFullLen;*/

    /* if the *signatureLen cannot hold full signature (per algorithm spec) return error */
    /*if (len < context->signatureFullLen)
    {
        return kStatus_SSS_Fail;
    }*/

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    op.params[1].memref.buffer = (uintptr_t)digest;
    op.params[1].memref.size   = digestLen;
    op.params[2].memref.buffer = (uintptr_t)signature;
    op.params[2].memref.size   = *signatureLen;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)signatureLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricSignDigest, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_verify_digest(
    sss_sscp_asymmetric_t *context, uint8_t *digest, size_t digestLen, uint8_t *signature, size_t signatureLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    /* common function parameters */
    op.params[1].memref.buffer = (uintptr_t)digest;
    op.params[1].memref.size   = digestLen;
    op.params[2].memref.buffer = (uintptr_t)signature;
    op.params[2].memref.size   = signatureLen;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricVerifyDigest, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_context_free(sss_sscp_asymmetric_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_ContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

/********************************TUNNEL****************************************/
sss_status_t sss_sscp_tunnel_context_init(sss_sscp_tunnel_t *context, sss_sscp_session_t *session, uint32_t tunnelType)
{
    SSCP_BUILD_ASSURE(sizeof(sss_tunnel_t) >= sizeof(sss_sscp_tunnel_t), _sss_sscp_tunnel_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    context->session    = session;
    context->tunnelType = tunnelType;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].value.a = tunnelType;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Tunnel;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_TunnelContextInit, &op, &ret);

    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_tunnel(sss_sscp_tunnel_t *context, uint8_t *data, size_t dataLen, uint32_t *resultState)
{
    SSCP_BUILD_ASSURE(sizeof(sss_tunnel_t) >= sizeof(sss_sscp_tunnel_t), _sss_sscp_tunnel_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    if ((context->tunnelType & SSS_SSCP_TUNNEL_HAVE_BUFFER_MASK) == SSS_SSCP_TUNNEL_HAVE_BUFFER_MASK)
    {
        op.paramTypes              = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                                       kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                                       kSSCP_ParamType_None, kSSCP_ParamType_None);
        op.params[2].memref.buffer = (uintptr_t)context->buffer;
        op.params[2].memref.size   = context->bufferSize;
    }
    else
    {
        op.paramTypes =
            SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                              kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);
    }

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Tunnel;

    op.params[1].memref.buffer = (uintptr_t)data;
    op.params[1].memref.size   = dataLen;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)resultState;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_Tunnel, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_tunnel_context_free(sss_sscp_tunnel_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Tunnel;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_ContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

/*******************************DERIVEKEY**************************************/
sss_status_t sss_sscp_derive_key_context_init(sss_sscp_derive_key_t *context,
                                              sss_sscp_session_t *session,
                                              sss_sscp_object_t *keyObject,
                                              sss_algorithm_t algorithm,
                                              sss_mode_t mode)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    context->algorithm = algorithm;
    context->mode      = mode;
    context->session   = session;
    context->keyObject = keyObject;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].value.a = (uint32_t)algorithm;
    op.params[2].value.b = (uint32_t)mode;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DeriveKeyContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_derive_key(sss_sscp_derive_key_t *context,
                                 const uint8_t *saltData,
                                 size_t saltLen,
                                 sss_sscp_object_t *derivedKeyObject)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                      kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.params[1].memref.buffer = (uintptr_t)saltData;
    op.params[1].memref.size   = saltLen;

    op.params[2].context.ptr  = derivedKeyObject;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 1u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DeriveKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_dh_derive_key(sss_sscp_derive_key_t *context,
                                               sss_sscp_object_t *otherPartyKeyObject,
                                               sss_sscp_object_t *derivedKeyObject)
{
    SSCP_BUILD_ASSURE(sizeof(sss_derive_key_t) >= sizeof(sss_sscp_derive_key_t), _sss_sscp_derive_key_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.params[1].context.ptr  = otherPartyKeyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].context.ptr  = derivedKeyObject;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 1u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricDeriveKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_derive_key_context_free(sss_sscp_derive_key_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_ContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

/*******************************KEYSTORE***************************************/
sss_status_t sss_sscp_key_store_init(sss_sscp_key_store_t *keyStore, sss_sscp_session_t *session)
{
    SSCP_BUILD_ASSURE(sizeof(sss_key_store_t) >= sizeof(sss_sscp_key_store_t), _sss_sscp_key_store_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    keyStore->session    = session;
    keyStore->keyStoreId = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.params[1].value.a = keyStore->keyStoreId;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = keyStore;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_set_key(sss_sscp_key_store_t *keyStore,
                                        sss_sscp_object_t *keyObject,
                                        const uint8_t *data,
                                        size_t dataLen,
                                        uint32_t keyBitLen,
                                        sss_key_part_t keyPart)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_MemrefInput, kSSCP_ParamType_ValueInputTuple,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].memref.buffer = (uintptr_t)data;
    op.params[2].memref.size   = dataLen;

    op.params[3].value.a = keyBitLen;
    op.params[3].value.b = keyPart;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreSetKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_get_key(sss_sscp_key_store_t *keyStore,
                                        sss_sscp_object_t *keyObject,
                                        uint8_t *data,
                                        size_t *dataLen,
                                        size_t *pKeyBitLen,
                                        sss_key_part_t keyPart)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_MemrefOutputNoSize,
                                      kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].memref.buffer = (uintptr_t)data;
    op.params[2].memref.size   = *dataLen;

    op.params[3].memref.buffer = (uintptr_t)pKeyBitLen;

    op.params[4].value.a = keyPart;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)dataLen;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreGetKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_import_key(sss_sscp_key_store_t *keyStore,
                                           sss_sscp_object_t *keyObject,
                                           const uint8_t *data,
                                           size_t dataLen,
                                           uint32_t keyBitLen,
                                           sss_sscp_blob_type_t blobType)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_MemrefInput, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].memref.buffer = (uintptr_t)data;
    op.params[2].memref.size   = dataLen;

    op.params[3].value.a = blobType;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreImportKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_export_key(sss_sscp_key_store_t *keyStore,
                                           sss_sscp_object_t *keyObject,
                                           uint8_t *data,
                                           size_t *dataLen,
                                           sss_sscp_blob_type_t blobType)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].memref.buffer = (uintptr_t)data;
    op.params[2].memref.size   = *dataLen;

    op.params[3].value.a = blobType;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)dataLen;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreExportKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_open_key(sss_sscp_key_store_t *keyStore, sss_sscp_object_t *keyObject)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreOpenKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_open_internal_key(sss_sscp_key_store_t *keyStore, sss_internal_keyID_t keyID)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].value.a = keyID;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreOpenKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_generate_key(sss_sscp_key_store_t *keyStore,
                                             sss_sscp_object_t *keyObject,
                                             size_t keyBitLen,
                                             void *options)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].value.a = keyBitLen;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreGenerateKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_erase_key(sss_sscp_key_store_t *keyStore, sss_sscp_object_t *keyObject)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObject;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreEraseKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_erase_all(sss_sscp_key_store_t *keyStore)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreEraseAll, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_free(sss_sscp_key_store_t *keyStore)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_store_get_property(sss_sscp_key_store_t *keyStore,
                                             sss_sscp_key_store_property_t propertyId,
                                             uint32_t *property)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].value.a = propertyId;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)property;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    if ((sscpCtx == NULL) || (sscpCtx->invoke == NULL))
    {
        return kStatus_SSS_Fail;
    }
    status = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyStoreGetProperty, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}
/*********************************RNG******************************************/
sss_status_t sss_sscp_rng_context_init(sss_sscp_session_t *session, sss_sscp_rng_t *context, uint32_t rngTypeSpecifier)
{
    context->session          = session;
    context->rngTypeSpecifier = rngTypeSpecifier;
    return kStatus_SSS_Success;
}

sss_status_t sss_sscp_rng_get_random(sss_sscp_rng_t *context, uint8_t *random_data, size_t dataLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInOut, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Rng;

    op.params[1].memref.buffer = (uintptr_t)random_data;
    op.params[1].memref.size   = dataLen;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, KSSCP_CMD_SSS_RngGet, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_rng_free(sss_sscp_rng_t *context)
{
    /* clean the rng context */
    (void)memset(context, 0, sizeof(sss_sscp_rng_t));
    return kStatus_SSS_Success;
}

/******************************KEYOBJECT***************************************/
sss_status_t sss_sscp_key_object_init_internal(sss_sscp_object_t *keyObject, sss_sscp_key_store_t *keyStore)
{
    SSCP_BUILD_ASSURE(sizeof(sss_object_t) >= sizeof(sss_sscp_object_t), _sss_sscp_key_object_size);
    keyObject->keyStore   = keyStore;
    keyObject->objectType = 0u; /* object type: key */

    return kStatus_SSS_Success;
}

sss_status_t sss_sscp_key_object_init(sss_sscp_object_t *keyObject, sss_sscp_key_store_t *keyStore)
{
    SSCP_BUILD_ASSURE(sizeof(sss_object_t) >= sizeof(sss_sscp_object_t), _sss_sscp_key_object_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    keyObject->keyStore   = keyStore;
    keyObject->objectType = 0u; /* object type: key */

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = keyObject;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Object;

    sscp_context_t *sscpCtx = keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyObjectContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_object_allocate_handle(sss_sscp_object_t *keyObject,
                                                 uint32_t keyId,
                                                 sss_key_part_t keyPart,
                                                 sss_cipher_type_t cipherType,
                                                 uint32_t keyByteLenMax,
                                                 uint32_t options)
{
    SSCP_BUILD_ASSURE(sizeof(sss_object_t) >= sizeof(sss_sscp_object_t), _sss_sscp_object_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    keyObject->objectType      = keyPart;
    keyObject->objectKeyCipher = cipherType;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputTuple,
                                      kSSCP_ParamType_ValueInputTuple, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyObject;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[1].value.a = keyId;
    op.params[1].value.b = keyPart;

    op.params[2].value.a = cipherType;
    op.params[2].value.b = keyByteLenMax;

    op.params[3].value.a = options;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyObject->keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyObjectAllocateHandle, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_object_get_handle(sss_sscp_object_t *keyObject, uint32_t keyId)
{
    SSCP_BUILD_ASSURE(sizeof(sss_object_t) >= sizeof(sss_sscp_object_t), _sss_sscp_object_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].value.a = keyId;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = keyObject;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Object;

    sscp_context_t *sscpCtx = keyObject->keyStore->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyObjectGetHandle, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_object_set_eccgfp_group(sss_sscp_object_t *keyObject, sss_eccgfp_group_t *group)
{
    keyObject->eccgfpGroup = group;
    return kStatus_SSS_Success;
}

sss_status_t sss_sscp_key_object_set_properties(sss_sscp_object_t *keyObject, uint32_t options)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyObject;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[1].value.a = options;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyObject->keyStore->session->sscp;
    if ((sscpCtx == NULL) || (sscpCtx->invoke == NULL))
    {
        return kStatus_SSS_Fail;
    }
    status = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyObjectSetProperties, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_object_get_properties(sss_sscp_object_t *keyObject, uint32_t *options)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyObject;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Object;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)options;

    sscp_context_t *sscpCtx = keyObject->keyStore->session->sscp;
    if ((sscpCtx == NULL) || (sscpCtx->invoke == NULL))
    {
        return kStatus_SSS_Fail;
    }
    status = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyObjectGetProperties, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_key_object_free(sss_sscp_object_t *keyObject, uint32_t options)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyObject;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[1].value.a = options;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = keyObject->keyStore->session->sscp;
    if ((sscpCtx == NULL) || (sscpCtx->invoke == NULL))
    {
        return kStatus_SSS_Fail;
    }
    status = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_KeyObjectContextFree, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}
