/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

#include "MacInterface.h"
#include "PlatInterface.h"
#ifdef __ZEPHYR__
#include <zephyr/kernel.h>

#define MSG_Alloc(x) k_malloc(x)
#define MSG_Free(x)  k_free(x)
#define MEM_BufferAllocWithId(x,y) k_malloc(x)
#define MEM_BufferFree(x)          k_free(x)

#else  /* __ZEPHYR__ */
#include "fsl_component_mem_manager.h"
#include "fsl_component_messaging.h"
#endif /* __ZEPHYR__ */
#include "fwk_platform.h"
#include "fwk_platform_zb.h"
#include "fsl_os_abstraction.h"

#if gFsciIncluded_c && gFSCI_IncludeMacCommands_c
#include "FsciInterface.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#undef MAC_NO
#define MAC_NO 1

#define ACK_TIMEOUT_MS 2000
#define ACK_INVALID 0xFF

// those values to be added in resultType_t (MacTypes)
#define ERROR_RPMSG_FAILURE 0xFE
#define ERROR_CMD_TIMEOUT   0xFD
#define ERROR_MEM_ALLOC     0xFC
#define ERROR_FAILED        0xFF

#define NWK_CB_TASK_PRIORITY 4
#define NWK_CB_TASK_STACK_SIZE 1024
#define NWK_CB_TASK_QUEUE_SIZE 10

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

static struct mac_local
{
    instanceId_t nwk_id;

    MCPS_NWK_SapHandler_t MCPS_NWK_SapHandler;
    MLME_NWK_SapHandler_t MLME_NWK_SapHandler;

    uint8_t phy_id;
} mac[MAC_NO];

typedef enum
{
    mcpsNwk_c,
    mlmeNwk_c
} nwk_cb_type_t;

typedef struct
{
    nwk_cb_type_t type;
    void* msg;
} nwk_cb_msg_t;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

uint16_t mlmeGetSizeOfPIB(pibId_t pib);

static void mac_rx_callback(uint8_t *data, uint16_t len, void *param);

static void NWK_CB_Task(void *param);

static resultType_t NWK_SapHandler(nwk_cb_type_t type, void* pMsg);
static resultType_t MCPS_NWK_SapHandler(uint8_t mac_id, mcpsToNwkMessage_t* pMsg, instanceId_t upperInstanceId);
static resultType_t MLME_NWK_SapHandler(uint8_t mac_id, nwkMessage_t* pMsg, instanceId_t upperInstanceId);

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static mlmeGetCnf_t mac_get_pib_rsp;
static plmeGetReq_t phy_get_rsp;
static macPlatMessage_t *plat_get_rsp;

static macAckMessage_t awaitedAck;
static resultType_t cmdErrorCode = gSuccess_c;

// mutex used to prevent race condition in case of multithread access
static OSA_MUTEX_HANDLE_DEFINE(mMultiThreadMutex);
static OSA_EVENT_HANDLE_DEFINE(get_event);
static OSA_TASK_HANDLE_DEFINE(nwkCbTaskHandle);
static OSA_MSGQ_HANDLE_DEFINE(nwkCbQueue, NWK_CB_TASK_QUEUE_SIZE, sizeof(nwk_cb_msg_t));
static OSA_TASK_DEFINE(NWK_CB_Task, NWK_CB_TASK_PRIORITY, 1, NWK_CB_TASK_STACK_SIZE, false);

int PLATFORM_InitOT()
{
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static resultType_t wait_response()
{
    osa_event_flags_t flags;
    osa_status_t osaStatus;
    resultType_t eResult = gSuccess_c;
    uint32_t timeoutMs = ACK_TIMEOUT_MS;

    osaStatus = OSA_EventWait(get_event, 1, 1, timeoutMs, &flags);

    if(osaStatus != KOSA_StatusSuccess)
    {
        // TODO set an appropriate value
        // do not find the matching code in enum
        eResult = ERROR_CMD_TIMEOUT;
    }
    else
    {
        // update the error code with the value returned in the ack
        // note that this function is also used for get function,
        // in that case, it return success
        eResult = cmdErrorCode;
        cmdErrorCode = gSuccess_c;

        /* Clear event as auto clear is not enabled */
        OSA_EventClear(get_event, 1);
    }

    return eResult;
}

void prepareWaitForAck(macMsgHeader_t* pMsg)
{
    awaitedAck.msgType = pMsg->msgType;
    awaitedAck.mac_id = pMsg->mac_id & MAC_ID_MASK; // when the value is check it has already been cleared from the MAC_CMD field
    awaitedAck.identifier = pMsg->mac_id;
}

static void  mac_ack_callback(void *param, uint8_t *data, uint32_t len)
{
    (void)param;

    // handle the ack
    macAckMessage_t* pAck = (macAckMessage_t*)data;
    if((pAck->msgType == awaitedAck.msgType) &&
       (pAck->mac_id == awaitedAck.mac_id) &&
       (pAck->identifier == awaitedAck.identifier))
    {
        awaitedAck.msgType = ACK_INVALID;
        awaitedAck.identifier = ACK_INVALID;

        // report the error code
        cmdErrorCode = pAck->ret;

        if(pAck->payload_len != 0)
        {
            uint8_t* pPayload = (uint8_t *)data + sizeof(macAckMessage_t);
            mac_rx_callback(pPayload, pAck->payload_len, NULL);
        }

        OSA_EventSet(get_event, 1);
    }
    return;
}

static void  mac_proxy_callback(void *param, uint8_t *data, uint32_t len)
{
    (void)param;

    macToPlmeMessage_t *msg = (macToPlmeMessage_t *)data;

    if (msg->msgType == gPlmeGetReq_c)
    {
        memcpy(&phy_get_rsp, &msg->msgData.getReq, sizeof(plmeGetReq_t));
    }

    return;
}

static void mac_plat_callback(void *param, uint8_t *data, uint32_t len)
{
    (void)param;

    macPlatMessage_t *msg = (macPlatMessage_t *)data;

    if (msg->is_get)
    {
        plat_get_rsp = (macPlatMessage_t *)MSG_Alloc(len);
        if (plat_get_rsp)
        {
            memcpy(plat_get_rsp, data, len);
        }
    }

    return;
}

static void mac_rx_callback(uint8_t *data, uint16_t len, void *param)
{
    (void)param;

    nwkMessage_t *msg = (nwkMessage_t *)data;

    uint8_t msg_type = (msg->mac_id >> MAC_ID_SIZE) & MAC_CMD_MASK;

    msg->mac_id &= MAC_ID_MASK;

    if (msg->mac_id >= MAC_NO)
    {
        msg->mac_id = 0;
    }

    if(msg_type == MAC_ACK)
    {
        return mac_ack_callback(param, data, len);
    }

    if (msg_type == MAC_PROXY_CMD)
    {
        return mac_proxy_callback(param, data, len);
    }

    if (msg_type == MAC_PLAT_CMD)
    {
        return mac_plat_callback(param, data, len);
    }

    if (msg_type != MAC_CMD)
    {
        return;
    }

    if (msg->msgType == gMlmeGetCnf_c)
    {
        uint8_t *pAttributeValue = NULL;
        if (msg->msgData.getCnf.pibAttributeLength)
        {
            pAttributeValue = (uint8_t *)msg + sizeof(nwkMessage_t);
            mac_get_pib_rsp.pibAttributeLength = msg->msgData.getCnf.pibAttributeLength;
            mac_get_pib_rsp.pibAttributeValue = MEM_BufferAllocWithId(mac_get_pib_rsp.pibAttributeLength, gMacPoolId_d);
        }
        else
        {
            mac_get_pib_rsp.pibAttributeLength = 0;
            mac_get_pib_rsp.pibAttributeValue = NULL;
        }

        if(pAttributeValue)
        {
            memcpy(mac_get_pib_rsp.pibAttributeValue, pAttributeValue, mac_get_pib_rsp.pibAttributeLength);
        }
        else
        {
            mac_get_pib_rsp.pibAttributeLength = 0;
        }
        return;
    }
    else if ((msg->msgType == gMlmeScanCnf_c) && (msg->msgData.scanCnf.scanType == gScanModeED_c))
    {
        nwkMessage_t *pNwkMsg = (nwkMessage_t *)data;

        if (sizeof(nwkMessage_t) + pNwkMsg->msgData.scanCnf.resultListSize != len)
        {
            return;
        }

        msg = (nwkMessage_t *)MSG_Alloc(len - pNwkMsg->msgData.scanCnf.resultListSize);

        if (!msg)
        {
            return;
        }

        memcpy(msg, pNwkMsg, len - pNwkMsg->msgData.scanCnf.resultListSize);

        msg->msgData.scanCnf.resList.pEnergyDetectList = (uint8_t *)MEM_BufferAllocWithId(msg->msgData.scanCnf.resultListSize, gMacPoolId_d);

        if (!msg->msgData.scanCnf.resList.pEnergyDetectList)
        {
            MSG_Free(msg);

            return;
        }

        memcpy(msg->msgData.scanCnf.resList.pEnergyDetectList, pNwkMsg->msgData.scanCnf.resList.pEnergyDetectList, msg->msgData.scanCnf.resultListSize);
    }
    else if ((msg->msgType == gMlmeScanCnf_c) && (msg->msgData.scanCnf.scanType == gScanModeActive_c))
    {
        panDescriptorBlock_t** ppPanDescriptorBlock;
        uint16_t remainLen = len;
        uint8_t* pRead = (uint8_t *)data;

        // copy nwk message
        msg = (nwkMessage_t *)MSG_Alloc(sizeof(nwkMessage_t));
        if (!msg)
        {
            return;
        }
        memcpy(msg, pRead, sizeof(nwkMessage_t));
        remainLen -= sizeof(nwkMessage_t);
        pRead += sizeof(nwkMessage_t);

        ppPanDescriptorBlock = &(msg->msgData.scanCnf.resList.pPanDescriptorBlockList);

        // by default no pan descriptor blocks
        *ppPanDescriptorBlock = NULL;

        // copy pan descriptor block if any
        while( remainLen >= sizeof(panDescriptorBlock_t))
        {
            // allocate and copy pan descriptor
            *ppPanDescriptorBlock = (panDescriptorBlock_t*)MSG_Alloc(sizeof(panDescriptorBlock_t));
            if (!*ppPanDescriptorBlock)
            {
                // in case of error, release msg
                panDescriptorBlock_t *pCurBlock = msg->msgData.scanCnf.resList.pPanDescriptorBlockList;
                panDescriptorBlock_t *pNextBlock = NULL;

                MSG_Free(msg);

                while(pCurBlock != NULL)
                {
                    pNextBlock = pCurBlock->pNext;
                    MSG_Free(pCurBlock);
                    pCurBlock = pNextBlock;
                }
                return;
            }

            memcpy(*ppPanDescriptorBlock, pRead, sizeof(panDescriptorBlock_t));
            remainLen -= sizeof(panDescriptorBlock_t);
            pRead += sizeof(panDescriptorBlock_t);

            // update chain
            ppPanDescriptorBlock = &((*ppPanDescriptorBlock)->pNext);
            *ppPanDescriptorBlock = NULL;
        }
    }
    else
    {
        msg = (nwkMessage_t *)MSG_Alloc(len);

        if (!msg)
        {
            return;
        }

        memcpy(msg, data, len);
    }

    switch (msg->msgType)
    {
        case gMcpsDataInd_c:
            ((mcpsToNwkMessage_t *)msg)->msgData.dataInd.pMsdu = (uint8_t *)msg + sizeof(mcpsToNwkMessage_t);
            MCPS_NWK_SapHandler(msg->mac_id, (mcpsToNwkMessage_t *)msg, mac[msg->mac_id].nwk_id);
            break;

        case gMcpsPromInd_c:
            ((mcpsToNwkMessage_t *)msg)->msgData.promInd.pMsdu = (uint8_t *)msg + sizeof(mcpsToNwkMessage_t);
            MCPS_NWK_SapHandler(msg->mac_id, (mcpsToNwkMessage_t *)msg, mac[msg->mac_id].nwk_id);
            break;

        case gMcpsDataCnf_c:
        case gMcpsPurgeCnf_c:
        case gMcpsPurgeIndQueueCnf_c:
            MCPS_NWK_SapHandler(msg->mac_id, (mcpsToNwkMessage_t *)msg, mac[msg->mac_id].nwk_id);
            break;

        case gMlmeBeaconNotifyInd_c:
            msg->msgData.beaconNotifyInd.pPanDescriptor = (panDescriptor_t *)((uint8_t *)msg + sizeof(nwkMessage_t));
            msg->msgData.beaconNotifyInd.pSdu = (uint8_t *)msg + sizeof(nwkMessage_t) + sizeof(panDescriptor_t);
        default:
            MLME_NWK_SapHandler(msg->mac_id, msg, mac[msg->mac_id].nwk_id);
            break;
    }
}

static void NWK_CB_Task(void *param)
{
    osa_status_t status;

    while(true)
    {
        nwk_cb_msg_t nwkCbMsg;

        status = OSA_MsgQGet((osa_msgq_handle_t)nwkCbQueue, &nwkCbMsg, osaWaitForever_c);
        if (status != KOSA_StatusSuccess)
        {
            continue;
        }

        switch(nwkCbMsg.type)
        {
            case mcpsNwk_c:
            {
                mcpsToNwkMessage_t* mcpsNwkMsg = (mcpsToNwkMessage_t*)nwkCbMsg.msg;
                if (mac[mcpsNwkMsg->mac_id].MCPS_NWK_SapHandler != NULL)
                {
                    (void)mac[mcpsNwkMsg->mac_id].MCPS_NWK_SapHandler(mcpsNwkMsg, mac[mcpsNwkMsg->mac_id].nwk_id);
                }
                else
                {
                    MSG_Free(mcpsNwkMsg);
                }
            }
            break;

            case mlmeNwk_c:
            {
                nwkMessage_t* mlmeNwkMsg = (nwkMessage_t*)nwkCbMsg.msg;
                if (mac[mlmeNwkMsg->mac_id].MLME_NWK_SapHandler != NULL)
                {
                    (void)mac[mlmeNwkMsg->mac_id].MLME_NWK_SapHandler(mlmeNwkMsg, mac[mlmeNwkMsg->mac_id].nwk_id);
                }
                else
                {
                    if(mlmeNwkMsg->msgType == gMlmeScanCnf_c)
                    {
                        if(mlmeNwkMsg->msgData.scanCnf.scanType == gScanModeED_c)
                        {
                            MEM_BufferFree((uint8_t *)mlmeNwkMsg->msgData.scanCnf.resList.pEnergyDetectList);
                        }
                        else if(mlmeNwkMsg->msgData.scanCnf.resList.pPanDescriptorBlockList)
                        {
                            panDescriptorBlock_t* pPanDescriptorBlock = mlmeNwkMsg->msgData.scanCnf.resList.pPanDescriptorBlockList;
                            panDescriptorBlock_t* pPanDescriptorBlockNext;

                            while(pPanDescriptorBlock != NULL)
                            {
                                pPanDescriptorBlockNext = pPanDescriptorBlock->pNext;
                                MSG_Free(pPanDescriptorBlock);
                                pPanDescriptorBlock = pPanDescriptorBlockNext;
                            }
                        }
                    }
                    MSG_Free(mlmeNwkMsg);
                }
            }
            break;

            default:
        }
    }
}

static resultType_t NWK_SapHandler(nwk_cb_type_t type, void* pMsg)
{
    resultType_t eError = gSuccess_c;
    nwk_cb_msg_t nwkCbMsg;

    nwkCbMsg.type = type;
    nwkCbMsg.msg = pMsg;

    if (OSA_MsgQPut((osa_msgq_handle_t)nwkCbQueue, &nwkCbMsg) != KOSA_StatusSuccess)
    {
        MSG_Free(pMsg);
        eError = ERROR_FAILED;
    }

    return eError;
}

static resultType_t MCPS_NWK_SapHandler(uint8_t mac_id, mcpsToNwkMessage_t* pMsg, instanceId_t upperInstanceId)
{
    return NWK_SapHandler(mcpsNwk_c, (void*)pMsg);
}

static resultType_t MLME_NWK_SapHandler(uint8_t mac_id, nwkMessage_t* pMsg, instanceId_t upperInstanceId)
{
    return NWK_SapHandler(mlmeNwk_c, (void*)pMsg);
}

void Mac_RegisterSapHandlers(MCPS_NWK_SapHandler_t pMCPS_NWK_SapHandler,
                             MLME_NWK_SapHandler_t pMLME_NWK_SapHandler,
                             instanceId_t macInstanceId)
{
    if (macInstanceId >= MAC_NO)
    {
        macInstanceId = 0;
    }

    mac[macInstanceId].MCPS_NWK_SapHandler = pMCPS_NWK_SapHandler;
    mac[macInstanceId].MLME_NWK_SapHandler = pMLME_NWK_SapHandler;
}

resultType_t NWK_MLME_SapHandler(mlmeMessage_t* req, nwkMessage_t *cnf, instanceId_t macInstanceId)
{
    uint8_t *msg = (uint8_t *)req;
    uint32_t len = sizeof(mlmeMessage_t);
    osa_event_flags_t flags;
    resultType_t eResult = gSuccess_c;

    OSA_MutexLock(mMultiThreadMutex, osaWaitForever_c);

    do
    {
        if (macInstanceId >= MAC_NO)
        {
            macInstanceId = 0;
        }

#if gFsciIncluded_c && gFSCI_IncludeMacCommands_c
        MAC_Monitor(gFSCI_MlmeSapId_c, req, (void*)gSuccess_c, macInstanceId);
#endif

        req->mac_id = macInstanceId;

        /* Bind Event with current task (main_task usually) in case RPMSG response is faster than
        * OSA_EventWait in the loop below.
        */
        OSA_EventWait(get_event, 1, 1, osaWaitNone_c, &flags);

        if (req->msgType == gMlmeGetReq_c)
        {
            mac_get_pib_rsp.pibAttributeLength = 0;
            mac_get_pib_rsp.pibAttributeValue = NULL;
        }

        if (req->msgType == gMlmeSetReq_c)
        {
            uint32_t attr_len = mlmeGetSizeOfPIB(req->msgData.setReq.pibAttribute);

            msg = MSG_Alloc(len + attr_len);

            if (!msg)
            {
                eResult = gInvalidParameter_c;
                break;
            }

            memcpy(msg, req, len);
            memcpy(msg + len, req->msgData.setReq.pibAttributeValue, attr_len);

            len += attr_len;
        }

        // indicate the type response expected
        prepareWaitForAck((macMsgHeader_t*)msg);

        if (PLATFORM_SendZbMacMessage(msg, len) < 0)
        {
            eResult = ERROR_RPMSG_FAILURE;
            break;
        }

        eResult = wait_response();
        if (eResult != gSuccess_c)
        {
            break;
        }

        switch (req->msgType)
        {
            case gMlmeGetReq_c:
                cnf->msgType = gMlmeGetCnf_c;
                cnf->msgData.getCnf.pibAttribute = req->msgData.getReq.pibAttribute;
                cnf->msgData.getCnf.pibAttributeIndex = req->msgData.getReq.pibAttributeIndex;
                cnf->msgData.getCnf.pibAttributeLength = mac_get_pib_rsp.pibAttributeLength;
                cnf->msgData.getCnf.pibAttributeValue = mac_get_pib_rsp.pibAttributeValue;

                mac_get_pib_rsp.pibAttributeLength = 0;
                mac_get_pib_rsp.pibAttributeValue = NULL;
                break;

            case gMlmeResetReq_c:
                cnf->msgType = gMlmeResetCnf_c;
                break;

            case gMlmeSetReq_c:
                cnf->msgType = gMlmeSetCnf_c;
                cnf->msgData.setCnf.pibAttribute 	 = req->msgData.setReq.pibAttribute;
                cnf->msgData.setCnf.pibAttributeIndex = req->msgData.setReq.pibAttributeIndex;
                break;

            default:
                break;
        }

#if gFsciIncluded_c && gFSCI_IncludeMacCommands_c
        /* Monitor the Cnf for the Sync Requests */
        MAC_Monitor( gFSCI_MlmeSapId_c, cnf, (void*)gSuccess_c, macInstanceId );
#endif

    } while (false);

    if ((req->msgType == gMlmeSetReq_c) && (msg != NULL))
    {
        /* in case of gMlmeSetReq_c, msg points to a new allocated buffer, we must always release it.
         * This is valid only when this new allocation was successful, meaning msg != NULL */
        MSG_Free(msg);
    }

    if (eResult == gSuccess_c)
    {
        /* free only on success because the message is freed by caller on failure */
        MSG_Free(req);
    }

    OSA_MutexUnlock(mMultiThreadMutex);

    return eResult;
}

resultType_t NWK_MCPS_SapHandler(nwkToMcpsMessage_t* pMsg, instanceId_t macInstanceId)
{
    uint32_t len = sizeof(nwkToMcpsMessage_t);
    osa_event_flags_t flags;
    resultType_t eResult = gSuccess_c;

    OSA_MutexLock(mMultiThreadMutex, osaWaitForever_c);

    do
    {
        if (macInstanceId >= MAC_NO)
        {
            macInstanceId = 0;
        }

        pMsg->mac_id = macInstanceId;

        if (pMsg->msgType == gMcpsDataReq_c)
        {
            len += pMsg->msgData.dataReq.msduLength;

            // check the payload follows the message
            if((uint8_t*)pMsg->msgData.dataReq.pMsdu != (uint8_t*)pMsg + sizeof(nwkToMcpsMessage_t))
            {
                assert(0);
                eResult = ERROR_MEM_ALLOC;
                break;
            }
        }

        // indicate the type response expected
        prepareWaitForAck((macMsgHeader_t*)pMsg);

        /* Bind Event with current task (main_task usually) in case RPMSG response is faster than
        * OSA_EventWait in the loop below.
        */
        OSA_EventWait(get_event, 1, 1, osaWaitNone_c, &flags);

#if gFsciIncluded_c && gFSCI_IncludeMacCommands_c
        MAC_Monitor(gFSCI_McpsSapId_c, pMsg, gSuccess_c, macInstanceId);
#endif

        if(PLATFORM_SendZbMacMessage((uint8_t*)pMsg, len) != 0)
        {
            // TODO set an appropriate value
            // do not find the matching code in enum
            eResult = ERROR_RPMSG_FAILURE;
            break;
        }

        eResult = wait_response();
    } while(false);

    if (eResult == gSuccess_c)
    {
        /* free only on success because the message is freed by caller on failure*/
        MSG_Free(pMsg);
    }

    OSA_MutexUnlock(mMultiThreadMutex);

    return eResult;
}

uint8_t MAC_get_PHY_ctx(instanceId_t macInstanceId)
{
    mlmeMessage_t *msg;
    nwkMessage_t cnf;
    uint8_t phy_id;

    if (macInstanceId >= MAC_NO)
    {
        macInstanceId = 0;
    }

    msg = MSG_Alloc(sizeof(mlmeMessage_t));

    if (!msg)
    {
        return (uint8_t)gInvalidInstanceId_c;
    }

    msg->msgType = gMlmeGetReq_c;
    msg->msgData.getReq.pibAttribute = gMacGetPhyId;
    msg->msgData.getReq.pibAttributeIndex = 0;

    NWK_MLME_SapHandler(msg, &cnf, macInstanceId);

    if (!cnf.msgData.getCnf.pibAttributeValue)
    {
        return (uint8_t)gInvalidInstanceId_c;
    }

    phy_id = *((uint8_t *)cnf.msgData.getCnf.pibAttributeValue);

    MEM_BufferFree(cnf.msgData.getCnf.pibAttributeValue);

    mac[macInstanceId].phy_id = phy_id;

    return phy_id;
}

instanceId_t BindToMAC(instanceId_t nwkId)
{
    mlmeMessage_t *msg;
    nwkMessage_t cnf;
    uint8_t mac_id;

    msg = MSG_Alloc(sizeof(mlmeMessage_t));

    if (!msg)
    {
        return gInvalidInstanceId_c;
    }

    msg->msgType = gMlmeGetReq_c;
    msg->msgData.getReq.pibAttribute = gMacGetId;
    msg->msgData.getReq.pibAttributeIndex = (uint8_t)nwkId;

    NWK_MLME_SapHandler(msg, &cnf, 0);

    if (!cnf.msgData.getCnf.pibAttributeValue)
    {
        return gInvalidInstanceId_c;
    }

    mac_id = *((uint8_t *)cnf.msgData.getCnf.pibAttributeValue);

    MEM_BufferFree(cnf.msgData.getCnf.pibAttributeValue);

    if (mac_id >= MAC_NO)
    {
        return gInvalidInstanceId_c;
    }

    mac[mac_id].nwk_id = nwkId;
    mac[mac_id].MCPS_NWK_SapHandler = NULL;
    mac[mac_id].MLME_NWK_SapHandler = NULL;

    return mac_id;
}

resultType_t MAC_Proxy_PLME_SapHandler(macToPlmeMessage_t * pMsg, instanceId_t macInstanceId)
{
    resultType_t eResult = gSuccess_c;
    osa_event_flags_t flags;

    OSA_MutexLock(mMultiThreadMutex, osaWaitForever_c);

    do
    {
        if (macInstanceId >= MAC_NO)
        {
            macInstanceId = 0;
        }

        pMsg->ctx_id = (macInstanceId & MAC_ID_MASK) | (MAC_PROXY_CMD << MAC_ID_SIZE);

        if (pMsg->msgType == gPlmeGetReq_c)
        {
            phy_get_rsp.PibAttributeValue = 0;

            OSA_EventWait(get_event, 1, 1, osaWaitNone_c, &flags);
        }

        // indicate the type response expected
        prepareWaitForAck((macMsgHeader_t*)pMsg);

        if(PLATFORM_SendZbMacMessage((uint8_t*)pMsg, sizeof(macToPlmeMessage_t)) != 0)
        {
            eResult = ERROR_RPMSG_FAILURE;
            break;
        }

        eResult = wait_response();

        if ((eResult == gSuccess_c) && (pMsg->msgType == gPlmeGetReq_c))
        {
            pMsg->msgData.getReq.PibAttributeValue = phy_get_rsp.PibAttributeValue;
            phy_get_rsp.PibAttributeValue = 0;
        }
    } while (false);

    OSA_MutexUnlock(mMultiThreadMutex);

    return eResult;
}

phyStatus_t MAC_PLME_SapHandler(macToPlmeMessage_t *pMsg, instanceId_t phyInstance)
{
    for (uint32_t cnt = 0; cnt < MAC_NO; cnt++)
    {
        if (mac[cnt].phy_id == phyInstance)
        {
            return MAC_Proxy_PLME_SapHandler(pMsg, cnt);
        }
    }
    return gPhyInvalidParameter_c;
}

resultType_t MAC_Plat_Cmd(macPlatMessage_t *pMsg, instanceId_t macInstanceId)
{
    osa_event_flags_t flags;
    resultType_t eResult = gSuccess_c;

    OSA_MutexLock(mMultiThreadMutex, osaWaitForever_c);

    do
    {
        if (macInstanceId >= MAC_NO)
        {
            macInstanceId = 0;
        }

        pMsg->mac_id = (macInstanceId & MAC_ID_MASK) | (MAC_PLAT_CMD << MAC_ID_SIZE);

        if (pMsg->is_get)
        {
            plat_get_rsp = NULL;

            OSA_EventWait(get_event, 1, 1, osaWaitNone_c, &flags);
        }

        // indicate the type response expected
        prepareWaitForAck((macMsgHeader_t*)pMsg);

        if(PLATFORM_SendZbMacMessage((uint8_t*)pMsg, sizeof(macPlatMessage_t) + pMsg->data_len) != 0)
        {
            eResult = gInvalidParameter_c;
            break;
        }

        eResult = wait_response();

        if ((eResult == gSuccess_c) &&
            (pMsg->is_get))
        {
            if (plat_get_rsp)
            {
                if (pMsg->data_len >= plat_get_rsp->data_len)
                {
                    memcpy((uint8_t *)pMsg + sizeof(macPlatMessage_t), (uint8_t *)plat_get_rsp + sizeof(macPlatMessage_t), plat_get_rsp->data_len);
                    pMsg->data_len = plat_get_rsp->data_len;
                }
            }
        }

        if (plat_get_rsp)
        {
            MSG_Free(plat_get_rsp);
            plat_get_rsp = NULL;
        }
    } while (false);

    OSA_MutexUnlock(mMultiThreadMutex);

    return eResult;
}

void MAC_Init()
{
    static bool_t init = FALSE;

    OSA_InterruptDisable();

    if (init)
    {
        OSA_InterruptEnable();

        return;
    }

    init = TRUE;

    OSA_MutexCreate((osa_mutex_handle_t)mMultiThreadMutex);
    OSA_MsgQCreate((osa_msgq_handle_t)nwkCbQueue, NWK_CB_TASK_QUEUE_SIZE, sizeof(nwk_cb_msg_t));

    /* This task is used to avoid calling MCPS and MLME NWK callbacks from the RX context
     * This interface is using a ACK mechanism, so we can't TX in the RX context because the ACK wouldn't be processed
     * Instead, we queue the callback message and process it in a separated task. */
    OSA_TaskCreate((osa_task_handle_t)nwkCbTaskHandle, OSA_TASK(NWK_CB_Task), NULL);

    OSA_InterruptEnable();

    if(PLATFORM_InitZbMacInterface(mac_rx_callback, NULL) != 0)
    {
        assert(0);
        return;
    }

    /* get_event with 0 auto clear to allow the task to run after flags have been set */
    OSA_EventCreate((osa_event_handle_t)get_event, 0);
}

void MAC_PLATFORM_GetIeee802_15_4Addr(uint8_t *eui64_address)
{
    resultType_t eResult;
    instanceId_t macInstanceId = 0;

    do
    {
        macPlatMessage_t *pMsg = NULL;
        platformExtAddress_t* pData = NULL;

        pMsg = (macPlatMessage_t *)MSG_Alloc(sizeof(macPlatMessage_t) + sizeof(platformExtAddress_t));
        pData = (platformExtAddress_t*)((uint8_t*)pMsg + sizeof(macPlatMessage_t));

        pMsg->mac_id = 0;
        pMsg->msgType = gIeee64Get_c;
        pMsg->data_len = sizeof(platformExtAddress_t);
        pMsg->is_get = true;

        eResult = MAC_Plat_Cmd(pMsg, macInstanceId);

        if(eResult != gSuccess_c)
        {
            /* pMsg is not released in case of error */
            MSG_Free(pMsg);
            assert(0);
            break;
        }

        memcpy((void *)eui64_address, (const void *)pData->m8, EXT_ADDRESS_SIZE);

        MSG_Free(pMsg);
    } while(false);

    return;
}

int8_t PhyConvertLQIToRSSI(uint8_t lqi)
{
    int32_t rssi = (36 * lqi - 9836) / 109;

    return (int8_t)rssi;
}
