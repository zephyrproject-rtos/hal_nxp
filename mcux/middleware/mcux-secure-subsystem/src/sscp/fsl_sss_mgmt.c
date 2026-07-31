/*
 * Copyright 2018-2021, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_sss_mgmt.h"
#include "fsl_sscp_commands.h"
#include "fsl_sss_sscp.h"

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

sss_status_t sss_mgmt_context_init(sss_mgmt_t *context, sss_sscp_session_t *session)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    context->session = session;
    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = session;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Session;

    op.resultTypes            = SSCP_OP_SET_RESULT(kSSCP_ParamType_ContextReference);
    op.resultCount            = 1u;
    op.result[0].context.ptr  = context;
    op.result[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_ContextInit, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_get_property(sss_mgmt_t *context, uint32_t propertyId, uint8_t *destData, size_t *dataLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    size_t len = (dataLen != NULL) ? *dataLen : 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_MemrefInOut, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.params[1].value.a       = propertyId;
    op.params[1].value.b       = 0u;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)destData);
    op.params[2].memref.size   = len;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)dataLen;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_PropertyGet, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_set_property(sss_mgmt_t *context, uint32_t propertyId, const uint8_t *srcData, size_t dataLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.params[1].value.a       = propertyId;
    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)srcData);
    op.params[2].memref.size   = dataLen;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_PropertySet, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_fuse_read(sss_mgmt_t *context,
                                uint32_t fuseId,
                                uint32_t *destData,
                                size_t *destDataLen,
                                uintptr_t options,
                                size_t *optionsLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;
    size_t optLen        = (optionsLen != NULL) ? *optionsLen : 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_MemrefOutputNoSize, kSSCP_ParamType_MemrefOutputNoSize,
                                      kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.params[1].value.a = fuseId;

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)destData);

    op.params[3].memref.buffer = ADD_OFFSET((uint32_t)destDataLen);

    op.params[4].memref.buffer = ADD_OFFSET((uint32_t)options);
    op.params[4].memref.size   = optLen;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_FuseRead, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_fuse_program(
    sss_mgmt_t *context, uint32_t fuseId, uint32_t *srcData, size_t *srcDataLen, uintptr_t options, size_t *optionsLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;
    size_t optLen        = (optionsLen != NULL) ? *optionsLen : 0u;
    size_t fuseLen       = (srcDataLen != NULL) ? *srcDataLen : 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.params[1].value.a = fuseId;

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)srcData);
    op.params[2].memref.size   = fuseLen;

    op.params[3].memref.buffer = ADD_OFFSET((uint32_t)options);
    op.params[3].memref.size   = optLen;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_FuseProgram, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_get_lifecycle(sss_mgmt_t *context, uint32_t *lifecycleData)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 1u;
    op.result[0].value.a = (uint32_t)lifecycleData;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_LifeCycleGet, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_advance_lifecycle(sss_mgmt_t *context,
                                        uint32_t *lifecycleData,
                                        uintptr_t options,
                                        size_t *optionsLen)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    uint32_t data = (lifecycleData != NULL) ? *lifecycleData : 0u;
    size_t len    = (optionsLen != NULL) ? *optionsLen : 0u;

    op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_ValueInputSingle,
                                      kSSCP_ParamType_MemrefInput, kSSCP_ParamType_None, kSSCP_ParamType_None,
                                      kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.params[1].value.a = data;

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)options);
    op.params[2].memref.size   = len;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_AdvanceLifecycle, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_set_return_fa(sss_mgmt_t *context,
                                    const uint8_t *request,
                                    size_t requestSize,
                                    uintptr_t options,
                                    size_t *optionsLen,
                                    uint32_t *resultState)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    size_t len = (optionsLen != NULL) ? *optionsLen : 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_MemrefInput, kSSCP_ParamType_MemrefInput,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.params[1].memref.buffer = ADD_OFFSET((uint32_t)request);
    op.params[1].memref.size   = requestSize;

    op.params[2].memref.buffer = ADD_OFFSET((uint32_t)options);
    op.params[2].memref.size   = len;

    op.resultTypes       = SSCP_OP_SET_RESULT(kSSCP_ParamType_ValueOutputSingle);
    op.resultCount       = 0u;
    op.result[0].value.a = (uint32_t)resultState;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_ReturnFaSet, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_set_host_access_permission(sss_mgmt_t *context, const sss_mgmt_security_level_t secLvl)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ValueInputSingle, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].value.a = secLvl;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_HostAccessPermissionSet, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_ping(sss_mgmt_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_Ping, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}
sss_status_t sss_mgmt_clear_all_keys(sss_mgmt_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

    op.resultTypes = SSCP_OP_SET_RESULT(kSSCP_ParamType_None);
    op.resultCount = 0u;

    sscp_context_t *sscpCtx = ((sss_sscp_session_t *)context->session)->sscp;
    status                  = sscpCtx->invoke(sscpCtx, kSSCP_CMD_SSS_MGMT_ClearAllKeys, &op, &ret);
    if (status != kStatus_SSCP_Success)
    {
        return kStatus_SSS_Fail;
    }
    return (sss_status_t)ret;
}

sss_status_t sss_mgmt_context_free(sss_mgmt_t *context)
{
    sscp_operation_t op  = {0};
    sscp_status_t status = kStatus_SSCP_Fail;
    uint32_t ret         = 0u;

    op.paramTypes =
        SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference, kSSCP_ParamType_None, kSSCP_ParamType_None,
                          kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None, kSSCP_ParamType_None);

    op.params[0].context.ptr  = context;
    op.params[0].context.type = kSSCP_ParamContextType_SSS_Mgmt;

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
