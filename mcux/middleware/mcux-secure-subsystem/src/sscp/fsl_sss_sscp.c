/*
 * Copyright 2018-2021, 2025-2026 NXP
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

#define SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_MASK     (0xFFUL)
#define SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_SHIFT    (24U)
#define SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_SET(l,i) (l) = (((l) & ~(SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_MASK << SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_SHIFT)) | (((i) & SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_MASK) << SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_SHIFT))

/**
 * @def ADD_OFFSET(addr)
 * Does shared memory address translation if running on NBU core.
 *
 * If the S200 is being used by the NBU core (cm33_core1) on the KW47 and MCXW72
 * devices, any data that is to be directly accessed by the S200 MUST be present
 * in S200-accessible memory. Such data would for example include input and
 * output buffers for plaintext and ciphertext.
 *
 * From NBU-side, the only accessible memory section for S200 is the shared
 * memory section, starting at address 0xB000_0000. Such addresses must be
 * translated into their SoC-side alias, which start at 0x489C_0000.
 *
 * @note The SSS drivers do not automatically move data into such a section.
 * Upon calling an SSS API, the data is expected to be at an S200-accessible
 * location. The driver only translates such an address to its correct alias.
 */
#if (defined(IS_RADIO_CORE) && IS_RADIO_CORE)
#define ADD_OFFSET(addr) ((((uintptr_t)(char *)(addr) & 0x0000FFFFu) + 0x489C0000u))
#else
#define ADD_OFFSET(addr) (addr)
#endif /* IS_RADIO_CORE */

#if defined(ELE_TRACK_SESSION_STATE)
typedef enum {
    sessionClosed,
    sessionOpen
} session_state_t;

static session_state_t session_state       = sessionClosed;
static sss_sscp_session_t session_internal = {0};
#endif

sss_status_t sss_sscp_open_session(sss_sscp_session_t *session,
                                   uint32_t sessionId,
                                   sss_type_t subsystem,
                                   sscp_context_t *sscpctx)

{
    SSCP_BUILD_ASSURE(sizeof(sss_session_t) >= sizeof(sss_sscp_session_t), _sss_sscp_session_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

#if defined(ELE_TRACK_SESSION_STATE)
    if (sessionOpen == session_state)
    {
        session_internal.subsystem = subsystem;
        session_internal.sscp      = sscpctx;
        (void)memcpy(session, &session_internal, sizeof(sss_sscp_session_t));
        return kStatus_SSS_Success;
    }
#endif

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

#if defined(ELE_TRACK_SESSION_STATE)
    (void)memcpy(&session_internal, session, sizeof(sss_sscp_session_t));
    session_state = sessionOpen;
#endif
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
#if defined(ELE_TRACK_SESSION_STATE)
    session_state = sessionClosed;
#endif
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

    if ((kAlgorithm_SSS_AES_CBC == context->algorithm || kAlgorithm_SSS_AES_ECB == context->algorithm) &&
        (dataLen % 16u != 0u))
    {
        return kStatus_SSS_InvalidArgument;
    }

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                      kSSCP_ParamType_MemrefInputNoSize, kSSCP_ParamType_MemrefInOut,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Symmetric;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)iv);
    op.params[1].memref.size   = ivLen;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)srcData);
    op.params[2].memref.size   = dataLen;
    op.params[3].memref.buffer = ADD_OFFSET((uint32_t)destData);
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

    /* Supported lengths
     * for GCM : tag length \in <12,16>
     * for CCM : tag length \in {0, 4, 6, 8, 10, 12, 14, 16} (0 valid for CCM*)
     */
    if (((kAlgorithm_SSS_AES_GCM == context->algorithm) && (16u < *tagLen || 12u > *tagLen)) ||
        ((kAlgorithm_SSS_AES_CCM == context->algorithm) &&
         (((0u < *tagLen) && (16u < *tagLen || 4u > *tagLen)) || (*tagLen % 2u != 0u))))
    {
        *tagLen = 0u;
        return kStatus_SSS_InvalidArgument;
    }

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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)srcData);
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)destData);
    op.params[3].value.a       = size;
    op.params[4].memref.buffer = ADD_OFFSET((uint32_t)nonce);
    op.params[4].memref.size   = nonceLen;
    op.params[5].memref.buffer = ADD_OFFSET((uint32_t)aad);
    op.params[5].memref.size   = aadLen;
    op.params[6].memref.buffer = ADD_OFFSET((uint32_t)tag);
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
#if defined(ELE_HAVE_SHA3)
        case kAlgorithm_SSS_SHA3_224:
#endif
            context->digestFullLen = 28u;
            break;
        case kAlgorithm_SSS_SHA256:
#if defined(ELE_HAVE_SHA3)
        case kAlgorithm_SSS_SHA3_256:
#endif
            context->digestFullLen = 32u;
            break;
        case kAlgorithm_SSS_SHA384:
#if defined(ELE_HAVE_SHA3)
        case kAlgorithm_SSS_SHA3_384:
#endif
            context->digestFullLen = 48u;
            break;
        case kAlgorithm_SSS_SHA512:
#if defined(ELE_HAVE_SHA3)
        case kAlgorithm_SSS_SHA3_512:
#endif
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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)message);
    op.params[1].memref.size   = messageLen;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)digest);
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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)message);
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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)digest);
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

#if defined(ELE_FEATURE_DIGEST_CLONE) && (ELE_FEATURE_DIGEST_CLONE == 1)
sss_status_t sss_sscp_digest_clone(sss_sscp_digest_t *context_src, sss_sscp_digest_t *context_dst)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context_src;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.params[1].context.ptr  = context_dst;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context_src->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestClone, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}
#endif /* ELE_FEATURE_DIGEST_CLONE */

#if defined(ELE_FEATURE_DIGEST_IMPORT) && (ELE_FEATURE_DIGEST_IMPORT == 1)
sss_status_t sss_sscp_digest_import(sss_sscp_digest_t *context_dst,
                                    uint8_t *digest_context_blob,
                                    size_t digest_context_blob_size)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context_dst;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)digest_context_blob);
    op.params[1].memref.size   = digest_context_blob_size;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context_dst->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestImport, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}
#endif /* ELE_FEATURE_DIGEST_IMPORT */

#if defined(ELE_FEATURE_DIGEST_EXPORT) && (ELE_FEATURE_DIGEST_EXPORT == 1)
sss_status_t sss_sscp_digest_export(sss_sscp_digest_t *context_src,
                                    uint8_t *digest_context_blob,
                                    size_t *digest_context_blob_size)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* Check digest_context_blob validity */
    if (digest_context_blob == NULL )
    {
        return kStatus_InvalidArgument;
    }

    /* if the caller gives NULL pointer to digest_context_blob_size, it is assumed that digest[] buffer is big enough to
     * hold full digest */
    size_t len =
        (digest_context_blob_size != NULL) ? *digest_context_blob_size : ELE_FEATURE_DIGEST_CONTEXT_BLOB_SIZE_IN_BYTES;

    /* if the *digest_context_blob_size cannot hold full digest (per algorithm spec) return error */
    if (len < ELE_FEATURE_DIGEST_CONTEXT_BLOB_SIZE_IN_BYTES)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context_src;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Digest;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)digest_context_blob);
    op.params[1].memref.size   = len;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)digest_context_blob_size;

    sscp_context_t *sscpCtx = context_src->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_DigestExport, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        if (digest_context_blob_size != NULL)
        {
            *digest_context_blob_size = 0u;
        }
        return kStatus_SSS_Fail;
    }

    /* the size member of kSSCP_ParamType_MemrefOutput param is updated with the actual byte length written to output
     * buffer
     */
    if (digest_context_blob_size != NULL)
    {
        *digest_context_blob_size = op.params[1].memref.size;
    }

    return (sss_status_t)ret;
}
#endif /* ELE_FEATURE_DIGEST_EXPORT */

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

    if (NULL == macLen)
    {
        return kStatus_SSS_InvalidArgument;
    }
    size_t macSize = *macLen;

    /* Clamp upper limit of CMAC MAC tag length to 16B to align S200 behavior
     * between devices.
     */
    if ((kAlgorithm_SSS_CMAC_AES == context->algorithm) && (16u < macSize))
    {
        macSize = 16u;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInOut,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)message);
    op.params[1].memref.size   = messageLen;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)mac);
    op.params[2].memref.size   = macSize;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)macLen;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacOneGo, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        *macLen = 0u; /* NULL check already done at start of the function */
        ret     = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

#if defined(ELE_FEATURE_MAC_MULTIPART)
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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)message);
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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)mac);
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
#endif /* ELE_FEATURE_MAC_MULTIPART */

#if defined(ELE_FEATURE_MAC_IMPORT) && (ELE_FEATURE_MAC_IMPORT == 1)
sss_status_t sss_sscp_mac_import(sss_sscp_mac_t *context_dst, uint8_t *mac_context_blob, size_t mac_context_blob_size)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context_dst;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)mac_context_blob);
    op.params[1].memref.size   = mac_context_blob_size;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = context_dst->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacImport, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}
#endif /* ELE_FEATURE_MAC_IMPORT */

#if defined(ELE_FEATURE_MAC_EXPORT) && (ELE_FEATURE_MAC_EXPORT == 1)
sss_status_t sss_sscp_mac_export(sss_sscp_mac_t *context_src, uint8_t *mac_context_blob, size_t *mac_context_blob_size)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    /* Check mac_context_blob validity */
    if (mac_context_blob == NULL )
    {
        return kStatus_InvalidArgument;
    }

    /* if the caller gives NULL pointer to mac_context_blob_size, it is assumed that digest[] buffer is big enough to
     * hold full digest */
    size_t len = (mac_context_blob_size != NULL) ? *mac_context_blob_size : ELE_FEATURE_MAC_CONTEXT_BLOB_SIZE_IN_BYTES;

    /* if the *mac_context_blob_size cannot hold full digest (per algorithm spec) return error */
    if (len < ELE_FEATURE_MAC_CONTEXT_BLOB_SIZE_IN_BYTES)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context_src;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mac;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)mac_context_blob);
    op.params[1].memref.size   = len;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)mac_context_blob_size;

    sscp_context_t *sscpCtx = context_src->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MacExport, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        if (mac_context_blob_size != NULL)
        {
            *mac_context_blob_size = 0u;
        }
        return kStatus_SSS_Fail;
    }

    /* the size member of kSSCP_ParamType_MemrefOutput param is updated with the actual byte length written to output
     * buffer
     */
    if (mac_context_blob_size != NULL)
    {
        *mac_context_blob_size = op.params[1].memref.size;
    }

    return (sss_status_t)ret;
}
#endif /* ELE_FEATURE_MAC_EXPORT */

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

sss_status_t sss_sscp_asymmetric_sign_digest(
    sss_sscp_asymmetric_t *context, uint8_t *digest, size_t digestLen, uint8_t *signature, size_t *signatureLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_asymmetric_t) >= sizeof(sss_sscp_asymmetric_t), _sss_sscp_asymmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)digest);
    op.params[1].memref.size   = digestLen;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)signature);
    op.params[2].memref.size   = *signatureLen;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = ADD_OFFSET((uint32_t)signatureLen);

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricSignDigest, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        ret = kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_sign_pqc(
    sss_sscp_asymmetric_t *context, uint8_t *input, size_t inputLen,
    uint8_t *signature, size_t *signatureLen, uint8_t *userCtx, size_t userCtxLen,
    sss_algorithm_t preHashAlg, uint8_t *workArea, size_t workAreaLen)
{
    SSCP_BUILD_ASSURE(sizeof(sss_asymmetric_t) >= sizeof(sss_sscp_asymmetric_t), _sss_sscp_asymmetric_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    if (NULL != workArea)
    {
        if (((uint32_t)workArea % sizeof(uint32_t)) != 0u)
        {
            return kStatus_SSS_Fail;
        }
    }

    if (NULL == signatureLen)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput,

                          kSSCP_ParamType_MemrefInput, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)input);
    op.params[1].memref.size   = inputLen;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)signature);
    op.params[2].memref.size   = *signatureLen;
    op.params[3].memref.buffer = ADD_OFFSET((uint32_t)userCtx);
    op.params[3].memref.size   = userCtxLen;
    op.params[4].value.a       = (uint32_t)preHashAlg;
    op.params[5].memref.buffer = ADD_OFFSET((uint32_t)workArea);
    op.params[5].memref.size   = workAreaLen;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = ADD_OFFSET((uint32_t)signatureLen);

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
    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)digest);
    op.params[1].memref.size   = digestLen;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)signature);
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

 sss_status_t sss_sscp_asymmetric_verify_pqc(
    sss_sscp_asymmetric_t *context, uint8_t *input, size_t inputLen,
    uint8_t *signature, size_t signatureLen, uint8_t *userCtx,
    size_t userCtxLen, sss_algorithm_t preHashAlg)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput,
                          kSSCP_ParamType_MemrefInput, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Asymmetric;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)input);
    op.params[1].memref.size   = inputLen;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)signature);
    op.params[2].memref.size   = signatureLen;
    op.params[3].memref.buffer = ADD_OFFSET((uint32_t)userCtx);
    op.params[3].memref.size   = userCtxLen;
    op.params[4].value.a       = (uint32_t)preHashAlg;

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
        if(context->tunnelType == kSSS_tunnel_type_EL2GO_Data)
        {
            op.paramTypes              = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                                           kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefOutput, kSSCP_ParamType_None,
                                                           kSSCP_ParamType_None, kSSCP_ParamType_None);
            /* Note that due to the way tunnelling is designed, the EL2GO tunnel
             * context itself must be in S200-accessible memory if loading an
             * EL2GO key from the NBU core.
             */
            op.params[3].memref.buffer = ADD_OFFSET((uint32_t)&context->bufferSize);
            op.params[3].memref.size   = sizeof(context->bufferSize);
        }
        else
        {
            op.paramTypes              = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                                           kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                                           kSSCP_ParamType_None, kSSCP_ParamType_None);
        }
        op.params[2].memref.buffer = ADD_OFFSET((uint32_t)context->buffer);
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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)data);
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
                                 sss_sscp_object_t *derivedKeyObject,
                                 size_t derivedKeyBitLength)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    (void)derivedKeyBitLength;
#if defined(ELE_FEATURE_MAC_KDF)
    if (kAlgorithm_SSS_CKDF == context->algorithm || kAlgorithm_SSS_HKDF_SHA1_EXTRACT == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA224_EXTRACT == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA256_EXTRACT == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA384_EXTRACT == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA512_EXTRACT == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA1_EXPAND == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA224_EXPAND == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA256_EXPAND == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA384_EXPAND == context->algorithm ||
        kAlgorithm_SSS_HKDF_SHA512_EXPAND == context->algorithm ||
        kAlgorithm_SSS_AES_MP_KDF == context->algorithm ||
        kAlgorithm_SSS_CKDF_SCP03 == context->algorithm)
    {
        /* For CKDF and HKDF use command format 2 */
        op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                          kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

        op.params[3].value.a = derivedKeyBitLength;
    }
    else
#endif /* ELE_FEATURE_MAC_KDF */
    {
        op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                          kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                          kSSCP_ParamType_None, kSSCP_ParamType_None);
    }

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)saltData);
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

sss_status_t sss_sscp_derive_key_multi(sss_sscp_derive_key_t *context,
                                       const uint8_t *saltData,
                                       size_t saltLen,
                                       sss_sscp_object_t *derivedKeyObject1,
                                       sss_sscp_object_t *derivedKeyObject2,
                                       sss_sscp_object_t *derivedKeyObject3,
                                       sss_sscp_object_t *derivedKeyObject4,
                                       sss_sscp_object_t *derivedKeyObject5,
                                       sss_sscp_object_t *derivedKeyObject6,
                                       size_t derivedKeyBitLength,
                                       uint32_t keyCount)
{
    sscp_operation_t op     = {0};
    sscp_operation_t opAgg  = {0};
    sscp_status_t status    = kStatus_SSCP_Fail;
    uint32_t options        = 0u;
    uint32_t ret            = 0u;

    if ((kAlgorithm_SSS_HKDF_SHA1_EXPAND != context->algorithm) &&
        (kAlgorithm_SSS_HKDF_SHA224_EXPAND != context->algorithm) &&
        (kAlgorithm_SSS_HKDF_SHA256_EXPAND != context->algorithm) &&
        (kAlgorithm_SSS_HKDF_SHA384_EXPAND != context->algorithm) &&
        (kAlgorithm_SSS_HKDF_SHA512_EXPAND != context->algorithm))
    {
        /* Only HKDF EXPAND supported */
        return kStatus_SSS_Fail;
    }

    /* Maximal keyBitlen is 0xFFFFFFu, expected values are 128bit and 256bit */
    if (derivedKeyBitLength > 0xFFFFFFu)
    {
        return kStatus_SSS_Fail;
    }

    /* Key count can be between 1 and 6 */
    if ((keyCount > 0x6u) || (keyCount < 0x1u))
    {
        return kStatus_SSS_Fail;
    }

    options = derivedKeyBitLength;
    SSS_SSCP_DERIVE_KEY_HKDF_KEY_COUNT_SET(options, keyCount);

    /* HKDF multi command format */
    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                      kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference, kSSCP_ParamType_Aggregate);
    opAgg.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                         kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                         kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)saltData);
    op.params[1].memref.size   = saltLen;

    op.params[2].context.ptr  = derivedKeyObject1;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[3].value.a = options;

    op.params[4].context.ptr  = derivedKeyObject2;
    op.params[4].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[5].context.ptr  = derivedKeyObject3;
    op.params[5].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[6].aggregate.op = &opAgg;

    /* Command doesn't fit, so use an aggregate */
    opAgg.params[0].context.ptr  = derivedKeyObject4;
    opAgg.params[0].context.type = kSSCP_ParamContextType_SSS_Object;

    opAgg.params[1].context.ptr  = derivedKeyObject5;
    opAgg.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    opAgg.params[2].context.ptr  = derivedKeyObject6;
    opAgg.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

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

sss_status_t sss_sscp_asymmetric_mlkem_derive_key(sss_sscp_derive_key_t *context,
                                                  uint8_t *cipherText,
                                                  size_t *cipherTextLen,
                                                  sss_sscp_object_t *sharedSecret,
                                                  sss_mode_t mode)
{
    SSCP_BUILD_ASSURE(sizeof(sss_derive_key_t) >= sizeof(sss_sscp_derive_key_t), _sss_sscp_derive_key_size);
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    if(NULL == cipherTextLen)
    {
        return kStatus_SSS_Fail;
    }

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput,
                                      kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)cipherText);
    op.params[1].memref.size   = *cipherTextLen;

    op.params[2].context.ptr  = sharedSecret;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[3].value.a = mode;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = ADD_OFFSET((uint32_t)cipherTextLen);

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricMlkemDeriveKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        *cipherTextLen = 0u; /* NULL check already done at start of the function */
        ret     = kStatus_SSS_Fail;
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
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricDhDeriveKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

#if defined(ELE_FEATURE_SPAKE2PLUS)
sss_status_t sss_sscp_asymmetric_spake2plus_derive_key(sss_sscp_derive_key_t *context,
                                                       sss_sscp_object_t *pA,
                                                       sss_sscp_object_t *w0,
                                                       sss_sscp_object_t *L,
                                                       uint8_t *contextData,
                                                       size_t contextDataLength,
                                                       sss_sscp_object_t *pB,
                                                       sss_sscp_object_t *cA,
                                                       sss_sscp_object_t *cB,
                                                       sss_sscp_object_t *Ke)
{
    SSCP_BUILD_ASSURE(sizeof(sss_derive_key_t) >= sizeof(sss_sscp_derive_key_t), _sss_sscp_derive_key_size);
    sscp_operation_t op    = {0};
    sscp_operation_t opAgg = {0};
    sscp_status_t status   = kStatus_SSCP_Fail;
    uint32_t ret           = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                          kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                          kSSCP_ParamType_MemrefInput, kSSCP_ParamType_ContextReference, kSSCP_ParamType_Aggregate);
    opAgg.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                         kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                         kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.params[1].context.ptr  = pA;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].context.ptr  = w0;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[3].context.ptr  = L;
    op.params[3].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[4].memref.buffer = ADD_OFFSET((uint32_t)contextData);
    op.params[4].memref.size   = contextDataLength;

    op.params[5].context.ptr  = pB;
    op.params[5].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[6].aggregate.op = &opAgg;

    /* Command doesn't fit, so use an aggregate */
    opAgg.params[0].context.ptr  = cA;
    opAgg.params[0].context.type = kSSCP_ParamContextType_SSS_Object;

    opAgg.params[1].context.ptr  = cB;
    opAgg.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    opAgg.params[2].context.ptr  = Ke;
    opAgg.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricSpake2PlusDeriveKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}

sss_status_t sss_sscp_asymmetric_spake2plus_derive_key_ccc(sss_sscp_derive_key_t *context,
                                                           sss_sscp_object_t *pA,
                                                           sss_sscp_object_t *w0,
                                                           sss_sscp_object_t *L,
                                                           uint8_t *contextData,
                                                           size_t contextDataLength,
                                                           sss_sscp_object_t *pB,
                                                           sss_sscp_object_t *cA,
                                                           sss_sscp_object_t *cB,
                                                           sss_sscp_object_t *Ke,
                                                           sss_sscp_object_t *k1,
                                                           sss_sscp_object_t *k2,
                                                           sss_sscp_object_t *k3,
                                                           sss_sscp_object_t *k4,
                                                           sss_sscp_object_t *k5,
                                                           sss_sscp_object_t *k6)
{
    SSCP_BUILD_ASSURE(sizeof(sss_derive_key_t) >= sizeof(sss_sscp_derive_key_t), _sss_sscp_derive_key_size);
    sscp_operation_t op    = {0};
    sscp_operation_t opAgg = {0};
    sscp_status_t status   = kStatus_SSCP_Fail;
    uint32_t ret           = 0u;

    /** NOTE: On NBU core, please make sure that stack is placed in shared
     *  memory, so that ELE can access it.
     */
    uint32_t keyArray[6] = {0u};
    keyArray[0]          = k1->ctx;
    keyArray[1]          = k2->ctx;
    keyArray[2]          = k3->ctx;
    keyArray[3]          = k4->ctx;
    keyArray[4]          = k5->ctx;
    keyArray[5]          = k6->ctx;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                          kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                          kSSCP_ParamType_MemrefInput, kSSCP_ParamType_ContextReference, kSSCP_ParamType_Aggregate);
    opAgg.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                         kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                                         kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_DeriveKey;

    op.params[1].context.ptr  = pA;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].context.ptr  = w0;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[3].context.ptr  = L;
    op.params[3].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[4].memref.buffer = ADD_OFFSET((uint32_t)contextData);
    op.params[4].memref.size   = contextDataLength;

    op.params[5].context.ptr  = pB;
    op.params[5].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[6].aggregate.op = &opAgg;

    /* Command doesn't fit, so use an aggregate */
    opAgg.params[0].context.ptr  = cA;
    opAgg.params[0].context.type = kSSCP_ParamContextType_SSS_Object;

    opAgg.params[1].context.ptr  = cB;
    opAgg.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    opAgg.params[2].context.ptr  = Ke;
    opAgg.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

    /* Due to the large number of keys used, we will pass key objects k1...k6
     * as an array of pointers.
     */
    opAgg.params[3].memref.buffer = ADD_OFFSET((uint32_t)keyArray);
    opAgg.params[3].memref.size   = sizeof(keyArray);

    sscp_context_t *sscpCtx = context->session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricSpake2PlusDeriveKey, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }

    return (sss_status_t)ret;
}
#endif /* ELE_FEATURE_SPAKE2PLUS */


sss_status_t sss_sscp_asymmetric_ec_point_operate(sss_sscp_session_t *session,
                                                  sss_sscp_object_t *pIn1,
                                                  sss_sscp_object_t *pIn2,
                                                  sss_sscp_object_t *pOut,
                                                  sss_sscp_ecPointOp_t operation)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                          kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;
    op.params[1].context.ptr  = pIn1;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;
    op.params[2].context.ptr  = pIn2;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;
    op.params[3].context.ptr  = pOut;
    op.params[3].context.type = kSSCP_ParamContextType_SSS_Object;
    op.params[4].value.a      = (uint32_t)operation;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = session->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_AsymmetricEcPointOperation, &op, &ret);
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
    keyStore->keyStoreId = 1u; /* Only one store supported, so use a value that
                                * can be used repeatedly. With 0, this command
                                * would fail on repeated calls.
                                */

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

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)data);
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

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)data);
    op.params[2].memref.size   = *dataLen;

    op.params[3].memref.buffer = ADD_OFFSET((uint32_t)pKeyBitLen);

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

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)data);
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

sss_status_t sss_sscp_key_store_import_key_ext(sss_sscp_key_store_t *keyStore,
                                               sss_sscp_object_t *keyObjectOut,
                                               const uint8_t *data,
                                               size_t dataLen,
                                               uint32_t keyBitLen,
                                               sss_sscp_blob_type_t blobType,
                                               sss_sscp_object_t *keyObjectIn)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ContextReference,
                                      kSSCP_ParamType_MemrefInput, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].context.ptr  = keyObjectOut;
    op.params[1].context.type = kSSCP_ParamContextType_SSS_Object;

    op.params[2].memref.buffer = (uintptr_t)data;
    op.params[2].memref.size   = dataLen;

    op.params[3].value.a = blobType;

    op.params[4].context.ptr  = keyObjectIn;
    op.params[4].context.type = kSSCP_ParamContextType_SSS_Object;

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

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)data);
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

sss_status_t sss_sscp_key_store_open_key(sss_sscp_key_store_t *keyStore,
                                         sss_internal_keyID_t keyID,
                                         sss_sscp_object_t *keyObject)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = keyStore;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_KeyStore;

    op.params[1].value.a = keyID;

    op.params[2].context.ptr  = keyObject;
    op.params[2].context.type = kSSCP_ParamContextType_SSS_Object;

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

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)random_data);
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