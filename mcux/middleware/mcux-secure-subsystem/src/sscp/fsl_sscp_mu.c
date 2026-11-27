/*
 * Copyright 2019-2021, 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdint.h>
#include <string.h>

#include "fsl_sscp_mu.h"
#include "fsl_sss_sscp.h"
#include "fsl_sss_mgmt.h"

#define SSCP_MU_Deinit   (void)
#define ELE_SUCCESS ((uint8_t)0x3C)
#define ELE_FAIL    ((uint8_t)0xC3)

/*
 * Optional thread-safety for the MU transport.
 *
 * When CONFIG_SSCP_MU_THREAD_SAFE is not set, the lock hooks compile to no-ops.
 */
#if defined(CONFIG_SSCP_MU_THREAD_SAFE) && (CONFIG_SSCP_MU_THREAD_SAFE > 0)
#include "fsl_os_abstraction.h"

static OSA_MUTEX_HANDLE_DEFINE(s_sscpMuMutex);
static volatile bool s_sscpMuMutexReady = false;

/* Create the mutex exactly once, even if sscp_mu_init() is called repeatedly
 * or concurrently from several contexts.
 */
static sscp_status_t SSCP_MU_MutexInitOnce(void)
{
    sscp_status_t status = kStatus_SSCP_Success;
    OSA_SR_ALLOC();

    OSA_ENTER_CRITICAL();
    if (!s_sscpMuMutexReady)
    {
        if (OSA_MutexCreate((osa_mutex_handle_t)s_sscpMuMutex) == KOSA_StatusSuccess)
        {
            s_sscpMuMutexReady = true;
        }
        else
        {
            status = kStatus_SSCP_Fail;
        }
    }
    OSA_EXIT_CRITICAL();

    return status;
}

static bool SSCP_MU_Lock(void)
{
    return (s_sscpMuMutexReady &&
            (OSA_MutexLock((osa_mutex_handle_t)s_sscpMuMutex, osaWaitForever_c) == KOSA_StatusSuccess));
}

static void SSCP_MU_Unlock(void)
{
    (void)OSA_MutexUnlock((osa_mutex_handle_t)s_sscpMuMutex);
}

#define SSCP_MU_MUTEX_INIT()   SSCP_MU_MutexInitOnce()
#define SSCP_MU_MUTEX_LOCK()   SSCP_MU_Lock()
#define SSCP_MU_MUTEX_UNLOCK() SSCP_MU_Unlock()
#else
#define SSCP_MU_MUTEX_INIT()   (kStatus_SSCP_Success)
#define SSCP_MU_MUTEX_LOCK()   (true)
#define SSCP_MU_MUTEX_UNLOCK() do { } while (false)
#endif /* CONFIG_SSCP_MU_THREAD_SAFE */

#if defined(ELE_TRACK_SESSION_STATE)
/*
 * Software emulation of an already-opened ELE session (used on devices that
 * do not natively support re-opening an existing session, e.g. KW45/MCXW71).
 * This state is read/written from within sscp_mu_invoke_command().
 */
typedef enum {
    sessionClosed,
    sessionOpen
} session_state_t;

static session_state_t session_state       = sessionClosed;
static sss_sscp_session_t session_internal = {0};
#endif /* ELE_TRACK_SESSION_STATE */


void SSCP_MU_Init(void)
{
    ELEMU_mu_init(ELEMUA);
}

sscp_status_t SSCP_MU_ReceiveMsg(ELEMU_Type *base, uint32_t msg[ELEMU_RR_COUNT], size_t wordNum)
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

sscp_status_t SSCP_MU_SendMsg(ELEMU_Type *base, uint32_t msg[ELEMU_TR_COUNT], size_t wordNum)
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

    if (SSCP_MU_MUTEX_INIT() != kStatus_SSCP_Success)
    {
        return kStatus_SSCP_Fail;
    }
    if (!SSCP_MU_MUTEX_LOCK())
    {
        return kStatus_SSCP_ResourceBusy;
    }

    muContext->base = base;
    SSCP_MU_Init();

    /* assign MU implementation of ::sscp_invoke_command() */
    muContext->invoke = &sscp_mu_invoke_command;

    SSCP_MU_MUTEX_UNLOCK();

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
    bool done              = false;
    uint32_t wrIdx         = MU_MSG_HEADER_SIZE;
    sscp_status_t ret      = kStatus_SSCP_Fail;
    sscp_status_t tmpRet   = kStatus_SSCP_Success;
    uint32_t i             = 0u;
    uint32_t aggregate_cnt = 0u;
    while ((!done) && (i < SSCP_OPERATION_PARAM_COUNT))
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
                i++;
                break;

            case kSSCP_ParamType_Aggregate:
                op = op->params[i].aggregate.op;
                i  = 0u;
                aggregate_cnt++;
                break;
            case kSSCP_ParamType_MemrefInput:
            case kSSCP_ParamType_MemrefInOut:
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.buffer);
                msg[wrIdx++] = op->params[i].memref.size;
                i++;
                break;
            case kSSCP_ParamType_MemrefOutputNoSize:
            case kSSCP_ParamType_MemrefInputNoSize:
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.buffer);
                i++;
                break;
            case kSSCP_ParamType_MemrefOutput:
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.buffer);
                msg[wrIdx++] = (uint32_t)(op->params[i].memref.size);
                i++;
                break;
            case kSSCP_ParamType_ValueInputTuple:
                msg[wrIdx++] = op->params[i].value.a;
                msg[wrIdx++] = op->params[i].value.b;
                i++;
                break;
            case kSSCP_ParamType_ValueInputSingle:
                msg[wrIdx++] = op->params[i].value.a;
                i++;
                break;
            case kSSCP_ParamType_None:
                done = true; /* break the for loop */
                ret  = kStatus_SSCP_Success;
                i++;
                break;
            default:
                tmpRet = kStatus_SSCP_Fail;
                i++;
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
        /* Max aggregate count reached, so we end to prevent infinite loops. */
        if (aggregate_cnt > SSCP_MAX_AGGREGATE_COUNT)
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
    uint32_t msg[ELEMU_TR_COUNT] = {0u};
    uint32_t wrIdx               = 0u;
    uint32_t muMsgHeaderSizeTmp  = 0u;
    sscp_status_t ret2           = kStatus_SSCP_Fail;
    sscp_status_t tmpRet         = kStatus_SSCP_Success;
    *ret                         = kStatus_SSS_Fail;
    mu_hdr_t muMsgHeader;

    if (!SSCP_MU_MUTEX_LOCK())
    {
        return kStatus_SSCP_ResourceBusy;
    }

#if defined(ELE_TRACK_SESSION_STATE)
    /* Emulate re-opening an already-open session entirely in software,
     * without a real MU transaction.
     */
    if ((commandId == kSSCP_CMD_SSS_OpenSession) && (sessionOpen == session_state))
    {
        sss_sscp_session_t *outSession = (sss_sscp_session_t *)(op->result[0].context.ptr);

        session_internal.subsystem = (sss_type_t)op->params[0].value.a;
        session_internal.sscp      = context;
        (void)memcpy(outSession, &session_internal, sizeof(sss_sscp_session_t));

        *ret = kStatus_SSS_Success;

        SSCP_MU_MUTEX_UNLOCK();
        return kStatus_SSCP_Success;
    }
#endif /* ELE_TRACK_SESSION_STATE */

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

        /* check if we can safely cast to narrower type */
        muMsgHeaderSizeTmp = (wrIdx - MU_MSG_HEADER_SIZE);
        if (muMsgHeaderSizeTmp > ((uint32_t)UINT8_MAX))
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }
        muMsgHeader.size = (uint8_t)muMsgHeaderSizeTmp;

        /* NBOOT MISRA Ex. 1 - Rule 11.3 - Casting between pointers of different types is not allowed */
        msg[0] = (uint32_t)(*((uint32_t *)(uintptr_t)(&muMsgHeader)));
        if (SSCP_MU_SendMsg(muContext->base, msg, wrIdx) != kStatus_SSCP_Success)
        {
            ret2 = kStatus_SSCP_Fail;
            break;
        }

        /* poll for response */
        if (SSCP_MU_ReceiveMsg(muContext->base, msg, ELEMU_RR_COUNT) != kStatus_SSCP_Success)
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

#if defined(ELE_TRACK_SESSION_STATE)
    if (ret2 == kStatus_SSCP_Success)
    {
        if (commandId == kSSCP_CMD_SSS_OpenSession)
        {
            sss_sscp_session_t *outSession = (sss_sscp_session_t *)(op->result[0].context.ptr);

            (void)memcpy(&session_internal, outSession, sizeof(sss_sscp_session_t));
            session_state = sessionOpen;
        }
        else if (commandId == kSSCP_CMD_SSS_CloseSession)
        {
            session_state = sessionClosed;
        }
        else
        {
            /* No session state change for other commands */
        }
    }
#endif /* ELE_TRACK_SESSION_STATE */

    SSCP_MU_MUTEX_UNLOCK();

    return ret2;
}
