/*
 * Copyright 2019-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdint.h>

#include "fsl_sscp_mu.h"
#include "fsl_sss_sscp.h"
#include "fsl_sss_mgmt.h"

#define MU_Deinit   (void)
#define ELE_SUCCESS ((uint8_t)0x3C)
#define ELE_FAIL    ((uint8_t)0xC3)

void MU_Init(void)
{
    ELEMU_mu_init(ELEMUA);
}

sscp_status_t MU_ReceiveMsg(ELEMU_Type *base, uint32_t msg[ELEMU_RR_COUNT], size_t wordNum)
{
    sscp_status_t ret = kStatus_SSCP_Fail;
    /* NBOOT MISRA Ex. 1 - Rule 11.3 - Casting between pointers of different types is not allowed */
    if (ELEMU_mu_get_response((ELEMU_Type *)(uintptr_t)base, msg, wordNum) != kStatus_Success)
    {
    }
#if (defined(FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER) && FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER)
    else if (ELEMU_mu_release_ownership((ELEMU_Type *)base) != kStatus_Success)
    {
    }
#endif /* FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER */
    else
    {
        ret = kStatus_SSCP_Success;
    }
    return ret;
}

sscp_status_t MU_SendMsg(ELEMU_Type *base, uint32_t msg[ELEMU_TR_COUNT], size_t wordNum)
{
    sscp_status_t ret = kStatus_SSCP_Fail;
#if (defined(FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER) && FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER)
    /* NBOOT MISRA Ex. 1 - Rule 11.3 - Casting between pointers of different types is not allowed */
    if (ELEMU_mu_get_ownership((ELEMU_Type *)base) != kStatus_Success)
    {
        ret = kStatus_SSCP_ResourceBusy;
    }
    else
#endif /* FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER */
        if (ELEMU_mu_send_message((ELEMU_Type *)(uintptr_t)base, msg, wordNum) != kStatus_Success)
        {
        }
        else
        {
            ret = kStatus_SSCP_Success;
        }
    return ret;
}

sscp_status_t sscp_mu_init(sscp_context_t *context, ELEMU_Type *base)
{
    sscp_mu_context_t *muContext = (sscp_mu_context_t *)(uintptr_t)context;

    muContext->base = base;
    MU_Init();

    /* assign MU implementation of ::sscp_invoke_command() */
    muContext->invoke = sscp_mu_invoke_command;
    return kStatus_SSCP_Success;
}

void sscp_mu_deinit(sscp_context_t *context)
{
    /*sscp_mu_context_t *muContext = (sscp_mu_context_t *)(uintptr_t)context;

    MU_Deinit(muContext->base);*/
}

sscp_status_t prepareMessage(sscp_operation_t *op, uint32_t msg[ELEMU_TR_COUNT], uint32_t *wrId);

/* NBOOT HIS metric Ex. 1 - HIS_CCM - Cyclomatic complexity */
sscp_status_t prepareMessage(sscp_operation_t *op, uint32_t msg[ELEMU_TR_COUNT], uint32_t *wrId)
{
    bool done            = false;
    uint32_t wrIdx       = MU_MSG_HEADER_SIZE;
    sscp_status_t ret    = kStatus_SSCP_Fail;
    sscp_status_t tmpRet = kStatus_SSCP_Success;
    uint32_t i;
    for (i = 0u; (!done) && (i < SSCP_OPERATION_PARAM_COUNT); i++)
    {
        switch (SSCP_OP_GET_PARAM(i, op->paramTypes))
        {
            case kSSCP_ParamType_ContextReference:
                switch (op->params[i].context.type)
                {
                    case kSSCP_ParamContextType_SSS_Session:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_session_t *)(op->params[i].context.ptr))->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Symmetric:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_symmetric_t *)(op->params[i].context.ptr))->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Aead:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_aead_t *)(op->params[i].context.ptr))->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Digest:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_digest_t *)op->params[i].context.ptr)->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Asymmetric:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_asymmetric_t *)op->params[i].context.ptr)->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Object:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_object_t *)op->params[i].context.ptr)->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_KeyStore:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_key_store_t *)op->params[i].context.ptr)->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_DeriveKey:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_derive_key_t *)op->params[i].context.ptr)->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Mgmt:
                        msg[wrIdx++] = (uint32_t)((sss_mgmt_t *)op->params[i].context.ptr)->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Rng:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_rng_t *)op->params[i].context.ptr)->rngTypeSpecifier;
                        break;
                    case kSSCP_ParamContextType_SSS_Mac:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_mac_t *)op->params[i].context.ptr)->ctx;
                        break;
                    case kSSCP_ParamContextType_SSS_Tunnel:
                        msg[wrIdx++] = (uint32_t)((sss_sscp_tunnel_t *)op->params[i].context.ptr)->ctx;
                        break;
                    default:
                        tmpRet = kStatus_SSCP_Fail;
                        break;
                }
                break;

            case kSSCP_ParamType_Aggregate:
                break;
            case kSSCP_ParamType_MemrefInput:
            case kSSCP_ParamType_MemrefInOut:
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.buffer);
                msg[wrIdx++] = op->params[i].memref.size;
                break;
            case kSSCP_ParamType_MemrefOutputNoSize:
            case kSSCP_ParamType_MemrefInputNoSize:
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.buffer);
                break;
            case kSSCP_ParamType_MemrefOutput:
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.buffer);
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.size);
                break;
            case kSSCP_ParamType_ValueInputTuple:
                msg[wrIdx++] = op->params[i].value.a;
                msg[wrIdx++] = op->params[i].value.b;
                break;
            case kSSCP_ParamType_ValueInputSingle:
                msg[wrIdx++] = op->params[i].value.a;
                break;
            case kSSCP_ParamType_None:
                done = true; /* break the for loop */
                ret  = kStatus_SSCP_Success;
                break;
            default:
                tmpRet = kStatus_SSCP_Fail;
                break;
        }
        if (tmpRet == kStatus_SSCP_Fail)
        {
            ret = kStatus_SSCP_Fail;
            break;
        }
        /* Buffer overoload, end with error. */
        if (wrIdx > ELEMU_TR_COUNT - 1u)
        {
            ret = kStatus_SSCP_Fail;
            break;
        }
    }
    if (i == SSCP_OPERATION_PARAM_COUNT)
    {
        ret = kStatus_SSCP_Success;
    }
    *wrId = wrIdx;
    return ret;
}

/* NBOOT HIS metric Ex. 1 - HIS_CCM - Cyclomatic complexity */
sscp_status_t sscp_mu_invoke_command(sscp_context_t *context,
                                     sscp_command_t commandId,
                                     sscp_operation_t *op,
                                     uint32_t *ret)
{
    /* NBOOT MISRA Ex. 1 - Rule 11.3 - Casting between pointers of different types is not allowed */
    sscp_mu_context_t *muContext = (sscp_mu_context_t *)(uintptr_t)context;
    /* parse the operation to create message */
    uint32_t msg[ELEMU_TR_COUNT] = {0};
    uint32_t wrIdx               = 0;
    sscp_status_t ret2           = kStatus_SSCP_Fail;
    sscp_status_t tmpRet         = kStatus_SSCP_Success;
    *ret                         = kStatus_SSS_Fail;
    mu_hdr_t muMsgHeader;

    do
    {
        if (prepareMessage(op, msg, &wrIdx) != kStatus_SSCP_Success)
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }
        muMsgHeader.check_bits = STATIC_CHECK_BITS;
        muMsgHeader.tag_sts    = MESSAGING_TAG_COMMAND;
        muMsgHeader.command    = commandId;
        muMsgHeader.size       = (uint8_t)(wrIdx - MU_MSG_HEADER_SIZE);
        /* NBOOT MISRA Ex. 1 - Rule 11.3 - Casting between pointers of different types is not allowed */
        msg[0] = (uint32_t)(*((uint32_t *)(uintptr_t)(&muMsgHeader)));
        if (MU_SendMsg(muContext->base, msg, wrIdx) != kStatus_SSCP_Success)
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }

        /* poll for response */
        if (MU_ReceiveMsg(muContext->base, msg, ELEMU_RR_COUNT) != kStatus_SSCP_Success)
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }
        /* NBOOT MISRA Ex. 1 - Rule 11.3 - Casting between pointers of different types is not allowed */
        mu_hdr_t *muReplyHeader = (mu_hdr_t *)(uintptr_t)&msg[0];
        if (muReplyHeader->size != op->resultCount)
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }
        if (muReplyHeader->command != commandId)
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }
        for (uint32_t i = 1u; i <= op->resultCount; i++)
        {
            uint32_t k = i - 1u;
            switch (SSCP_OP_GET_PARAM(k, op->resultTypes))
            {
                case kSSCP_ParamType_ContextReference:
                    switch (op->result[k].context.type)
                    {
                        case kSSCP_ParamContextType_SSS_Session:
                            ((sss_sscp_session_t *)(op->result[k].context.ptr))->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Symmetric:
                            ((sss_sscp_symmetric_t *)(op->result[k].context.ptr))->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Aead:
                            ((sss_sscp_aead_t *)(op->result[k].context.ptr))->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Digest:
                            ((sss_sscp_digest_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Asymmetric:
                            ((sss_sscp_asymmetric_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Object:
                            ((sss_sscp_object_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        /*case kSSCP_ParamContextType_SSS_KeyStoreCtx:
                            ((sss_sscp_key_store_t *)op->result[k].context.ptr)->keyStoreCtx = msg[i];
                            break;*/
                        case kSSCP_ParamContextType_SSS_KeyStore:
                            ((sss_sscp_key_store_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_DeriveKey:
                            ((sss_sscp_derive_key_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Mgmt:
                            ((sss_mgmt_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Mac:
                            ((sss_sscp_mac_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        case kSSCP_ParamContextType_SSS_Tunnel:
                            ((sss_sscp_tunnel_t *)op->result[k].context.ptr)->ctx = msg[i];
                            break;
                        default:
                            tmpRet = kStatus_SSCP_Fail;
                            break;
                    }
                    break;
                case kSSCP_ParamType_ValueOutputSingle:
                    *((uint32_t *)(op->result[k].value.a)) = msg[i];
                    break;
                case kSSCP_ParamType_None:
                    break;
                default:
                    tmpRet = kStatus_SSCP_Fail;
                    break;
            }
        }
        if (tmpRet == kStatus_SSCP_Fail)
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }
        if (muReplyHeader->tag_sts == ELE_SUCCESS)
        {
            *ret = kStatus_SSS_Success;
            ret2 = kStatus_SSCP_Success;
        }
        else
        {
            ret2 = kStatus_SSCP_Fail;
        }
    } while (false);

    return ret2;
}
