/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "MacInterface.h"
#include "PhyInterface.h"
#include "fsl_adapter_rpmsg.h"
#ifdef __ZEPHYR__
#include <zephyr/kernel.h>

#define MSG_Alloc(x) k_malloc(x)
#define MSG_Free(x)  k_free(x)
#define MEM_BufferAllocWithId(x,y) k_malloc(x)
#define MEM_BufferFree(x)          k_free(x)

#else	/* __ZEPHYR__ */
#include "fsl_component_mem_manager.h"
#include "fsl_component_messaging.h"

#endif	/* __ZEPHYR__ */
#include "fwk_platform.h"
#include "fsl_os_abstraction.h"


#undef MAC_NO
#define MAC_NO 1

#define MAC_GET_ID_CNT 10

#define MAC_INTF_CB_QUEUE_SIZE 10
#define MAC_INTF_CB_TASK_PRIORITY 4
#define MAC_INTF_CB_TASK_STACK_SIZE 2048


static struct mac_local
{
    instanceId_t nwk_id;

    MCPS_NWK_SapHandler_t MCPS_NWK_SapHandler;
    MLME_NWK_SapHandler_t MLME_NWK_SapHandler;

    uint8_t phy_id;
} mac[MAC_NO];


static RPMSG_HANDLE_DEFINE(mac_rpmsg_handle);
static hal_rpmsg_config_t mac_rpmsg_config = {
    .local_addr  = 12,
    .remote_addr = 22
};


static uint8_t wait_mac_rsp = FALSE;
static uint8_t wait_proxy_rsp = FALSE;
static uint8_t wait_plat_rsp = FALSE;

static mlmeGetCnf_t mac_get_pib_rsp;
static plmeGetReq_t phy_get_rsp;
static macPlatMessage_t *plat_get_rsp;

static OSA_EVENT_HANDLE_DEFINE(get_event);

static OSA_MUTEX_HANDLE_DEFINE(mac_intf_mutex);
static OSA_MSGQ_HANDLE_DEFINE(mac_intf_cb_queue, MAC_INTF_CB_QUEUE_SIZE, sizeof(macMsgHeader_t *));

static void mac_intf_cb_task_func();
static OSA_TASK_HANDLE_DEFINE(mac_intf_cb_task);
static OSA_TASK_DEFINE(mac_intf_cb_task_func, MAC_INTF_CB_TASK_PRIORITY, 1, MAC_INTF_CB_TASK_STACK_SIZE, FALSE);

static bool_t mac_intf_init_done = FALSE;
static bool_t mac_intf_init_ongoing = FALSE;
extern const uint8_t gUseRtos_c;


uint16_t mlmeGetSizeOfPIB(pibId_t pib);

static void mac_msg_free(nwkMessage_t *msg)
{
    if ((msg->msgType == gMlmeScanCnf_c) && (msg->msgData.scanCnf.scanType == gScanModeED_c))
    {
        MEM_BufferFree(msg->msgData.scanCnf.resList.pEnergyDetectList);
    }
    MSG_Free(msg);
}

static void mac_intf_cb_task_func()
{
    nwkMessage_t *msg;
    bool_t msg_free;

    while (1)
    {
        if (OSA_MsgQGet(mac_intf_cb_queue, &msg, osaWaitForever_c) == KOSA_StatusSuccess)
        {
            msg_free = TRUE;

            switch (msg->msgType)
            {
                case gMcpsDataInd_c:
                    if (mac[msg->mac_id].MCPS_NWK_SapHandler)
                    {
                        msg_free = FALSE;
                        ((mcpsToNwkMessage_t *)msg)->msgData.dataInd.pMsdu = (uint8_t *)msg + sizeof(mcpsToNwkMessage_t);

                        mac[msg->mac_id].MCPS_NWK_SapHandler((mcpsToNwkMessage_t *)msg, mac[msg->mac_id].nwk_id);
                    }
                    break;

                case gMcpsPromInd_c:
                    if (mac[msg->mac_id].MCPS_NWK_SapHandler)
                    {
                        msg_free = FALSE;
                        ((mcpsToNwkMessage_t *)msg)->msgData.promInd.pMsdu = (uint8_t *)msg + sizeof(mcpsToNwkMessage_t);

                        mac[msg->mac_id].MCPS_NWK_SapHandler((mcpsToNwkMessage_t *)msg, mac[msg->mac_id].nwk_id);
                    }
                    break;

                case gMcpsDataCnf_c:
                case gMcpsPurgeCnf_c:
                case gMcpsPurgeIndQueueCnf_c:
                    if (mac[msg->mac_id].MCPS_NWK_SapHandler)
                    {
                        msg_free = FALSE;
                        mac[msg->mac_id].MCPS_NWK_SapHandler((mcpsToNwkMessage_t *)msg, mac[msg->mac_id].nwk_id);
                    }
                    break;

                case gMlmeBeaconNotifyInd_c:
                    msg->msgData.beaconNotifyInd.pPanDescriptor = (panDescriptor_t *)((uint8_t *)msg + sizeof(nwkMessage_t));
                    msg->msgData.beaconNotifyInd.pSdu = (uint8_t *)msg + sizeof(nwkMessage_t) + sizeof(panDescriptor_t);

                default:
                    if (mac[msg->mac_id].MLME_NWK_SapHandler)
                    {
                        msg_free = FALSE;
                        mac[msg->mac_id].MLME_NWK_SapHandler(msg, mac[msg->mac_id].nwk_id);
                    }
                    break;
            }

            if (msg_free)
            {
                mac_msg_free(msg);
            }

        }

        if (!gUseRtos_c)
        {
            break;
        }
    }
}

static void wait_response()
{
    osa_event_flags_t flags;
    uint32_t dt = osaWaitForever_c;

    if (!OSA_TaskGetCurrentHandle())
    {
        /* Current task is valid in OSA_ProcessTasks().
           There is no check in OSA_EventWait() that current task is valid.
           For osaWaitNone_c, current task is not used */
        dt = osaWaitNone_c;
    }

    /* Wait until NBU delivers result over RPMSG */
    while (OSA_EventWait(get_event, 1, 1, dt, &flags) != KOSA_StatusSuccess)
    {}

    /* Clear event as auto clear is not enabled */
    OSA_EventClear(get_event, 1);
}

static hal_rpmsg_return_status_t mac_proxy_callback(void *param, uint8_t *data, uint32_t len)
{
    (void)param;

    macToPlmeMessage_t *msg = (macToPlmeMessage_t *)data;

    if (wait_proxy_rsp && (msg->msgType == gPlmeGetReq_c))
    {
        phy_get_rsp = msg->msgData.getReq;

        OSA_EventSet(get_event, 1);
    }

    return kStatus_HAL_RL_RELEASE;
}

static hal_rpmsg_return_status_t mac_plat_callback(void *param, uint8_t *data, uint32_t len)
{
    (void)param;

    macPlatMessage_t *msg = (macPlatMessage_t *)data;

    if (wait_plat_rsp && msg->is_get)
    {
        plat_get_rsp = (macPlatMessage_t *)MSG_Alloc(len);

        if (plat_get_rsp)
        {
            memcpy(plat_get_rsp, data, len);
        }

        OSA_EventSet(get_event, 1);
    }

    return kStatus_HAL_RL_RELEASE;
}

static hal_rpmsg_return_status_t mac_rpmsg_rx_callback(void *param, uint8_t *data, uint32_t len)
{
    (void)param;

    nwkMessage_t *msg = (nwkMessage_t *)data;

    uint8_t msg_type = (msg->mac_id >> MAC_ID_SIZE) & MAC_CMD_MASK;

    msg->mac_id &= MAC_ID_MASK;

    if (msg->mac_id >= MAC_NO)
    {
        msg->mac_id = 0;
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
        return kStatus_HAL_RL_RELEASE;
    }

    if (msg->msgType == gMlmeGetCnf_c)
    {
        if (wait_mac_rsp)
        {
            if (msg->msgData.getCnf.pibAttributeLength)
            {
                msg->msgData.getCnf.pibAttributeValue = (uint8_t *)msg + sizeof(nwkMessage_t);

                mac_get_pib_rsp.pibAttributeLength = msg->msgData.getCnf.pibAttributeLength;
                mac_get_pib_rsp.pibAttributeValue = MEM_BufferAllocWithId(mac_get_pib_rsp.pibAttributeLength, gMacPoolId_d);
            }
            else
            {
                mac_get_pib_rsp.pibAttributeLength = 0;
                mac_get_pib_rsp.pibAttributeValue = NULL;
            }

            if (mac_get_pib_rsp.pibAttributeValue)
            {
                memcpy(mac_get_pib_rsp.pibAttributeValue, msg->msgData.getCnf.pibAttributeValue, mac_get_pib_rsp.pibAttributeLength);
            }
            else
            {
                mac_get_pib_rsp.pibAttributeLength = 0;
            }

            OSA_EventSet(get_event, 1);
        }

        return kStatus_HAL_RL_RELEASE;
    }
    else if ((msg->msgType == gMlmeScanCnf_c) && (msg->msgData.scanCnf.scanType == gScanModeED_c))
    {
        nwkMessage_t *tmp = (nwkMessage_t *)data;

        if (sizeof(nwkMessage_t) + tmp->msgData.scanCnf.resultListSize != len)
        {
            return kStatus_HAL_RL_RELEASE;
        }

        msg = (nwkMessage_t *)MSG_Alloc(len - tmp->msgData.scanCnf.resultListSize);

        if (!msg)
        {
            return kStatus_HAL_RL_RELEASE;
        }

        memcpy(msg, tmp, len - tmp->msgData.scanCnf.resultListSize);

        msg->msgData.scanCnf.resList.pEnergyDetectList = (uint8_t *)MEM_BufferAllocWithId(msg->msgData.scanCnf.resultListSize, gMacPoolId_d);

        if (!msg->msgData.scanCnf.resList.pEnergyDetectList)
        {
            MSG_Free(msg);

            return kStatus_HAL_RL_RELEASE;
        }

        memcpy(msg->msgData.scanCnf.resList.pEnergyDetectList, tmp->msgData.scanCnf.resList.pEnergyDetectList, msg->msgData.scanCnf.resultListSize);
    }
    else
    {
        msg = (nwkMessage_t *)MSG_Alloc(len);

        if (!msg)
        {
            return kStatus_HAL_RL_RELEASE;
        }

        memcpy(msg, data, len);
    }

    if (OSA_MsgQPut(mac_intf_cb_queue, &msg) != KOSA_StatusSuccess)
    {
        mac_msg_free(msg);
    }

    return kStatus_HAL_RL_RELEASE;
}

void Mac_RegisterSapHandlers(MCPS_NWK_SapHandler_t pMCPS_NWK_SapHandler,
                             MLME_NWK_SapHandler_t pMLME_NWK_SapHandler,
                             instanceId_t macInstanceId)
{
    if (!mac_intf_init_done)
    {
        return;
    }

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
    resultType_t ret = gSuccess_c;

    if (!mac_intf_init_done)
    {
        return gInvalidParameter_c;
    }

    OSA_MutexLock(mac_intf_mutex, osaWaitForever_c);
    PLATFORM_RemoteActiveReq();

    do
    {
        if (macInstanceId >= MAC_NO)
        {
            macInstanceId = 0;
        }

        req->mac_id = macInstanceId;

        /* Bind Event with current task (main_task usually) in case RPMSG response is faster than
         * OSA_EventWait in the loop below.
         */
        if (req->msgType == gMlmeGetReq_c)
        {
            mac_get_pib_rsp.pibAttributeLength = 0;
            mac_get_pib_rsp.pibAttributeValue = NULL;

            OSA_EventWait(get_event, 1, 1, osaWaitNone_c, &flags);
            wait_mac_rsp = TRUE;
        }
        else if (req->msgType == gMlmeSetReq_c)
        {
            uint32_t attr_len = mlmeGetSizeOfPIB(req->msgData.setReq.pibAttribute);

            msg = MSG_Alloc(len + attr_len);
            if (!msg)
            {
                ret = gInvalidParameter_c;
                break;
            }

            memcpy(msg, req, len);
            memcpy(msg + len, req->msgData.setReq.pibAttributeValue, attr_len);

            len += attr_len;
        }

        if (HAL_RpmsgSend((hal_rpmsg_handle_t)mac_rpmsg_handle, msg, len) != kStatus_HAL_RpmsgSuccess)
        {
            ret = gInvalidParameter_c;
            break;
        }

        if (req->msgType == gMlmeGetReq_c)
        {
            wait_response();
            wait_mac_rsp = FALSE;

            cnf->msgData.getCnf.pibAttributeLength = mac_get_pib_rsp.pibAttributeLength;
            cnf->msgData.getCnf.pibAttributeValue = mac_get_pib_rsp.pibAttributeValue;
        }
    } while (0);

    wait_mac_rsp = FALSE;
    PLATFORM_RemoteActiveRel();
    OSA_MutexUnlock(mac_intf_mutex);

    if ((req->msgType == gMlmeSetReq_c) && msg)
    {
        MSG_Free(msg);
    }

    if (ret == gSuccess_c)
    {
        MSG_Free(req);
    }
    return ret;
}

resultType_t NWK_MCPS_SapHandler(nwkToMcpsMessage_t* pMsg, instanceId_t macInstanceId)
{
    uint32_t len = sizeof(nwkToMcpsMessage_t);
    resultType_t ret = gSuccess_c;

    if (!mac_intf_init_done)
    {
        return gInvalidParameter_c;
    }

    OSA_MutexLock(mac_intf_mutex, osaWaitForever_c);
    PLATFORM_RemoteActiveReq();

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
        }

        if (HAL_RpmsgSend((hal_rpmsg_handle_t)mac_rpmsg_handle, (uint8_t *)pMsg, len) != kStatus_HAL_RpmsgSuccess)
        {
            ret = gInvalidParameter_c;
            break;
        }
    } while (0);

    PLATFORM_RemoteActiveRel();
    OSA_MutexUnlock(mac_intf_mutex);

    if (ret == gSuccess_c)
    {
        MSG_Free(pMsg);
    }
    return ret;
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

    cnf.msgData.getCnf.pibAttributeValue = NULL;

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
    uint8_t cnt = MAC_GET_ID_CNT;
    resultType_t ret;
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

    cnf.msgData.getCnf.pibAttributeValue = NULL;

    /* wait for NBU to be ready */
    do
    {
        ret = NWK_MLME_SapHandler(msg, &cnf, 0);
    } while ((ret != gSuccess_c) && (cnt--));

    assert(ret == gSuccess_c);

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

    /* send RNG seed to NBU */
    int RNG_SetSeed(void);
    RNG_SetSeed();

    return mac_id;
}

resultType_t MAC_Proxy_PLME_SapHandler(macToPlmeMessage_t * pMsg, instanceId_t macInstanceId)
{
    osa_event_flags_t flags;
    resultType_t ret = gSuccess_c;

    if (!mac_intf_init_done)
    {
        return gInvalidParameter_c;
    }

    OSA_MutexLock(mac_intf_mutex, osaWaitForever_c);
    PLATFORM_RemoteActiveReq();

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
            wait_proxy_rsp = TRUE;
        }

        if (HAL_RpmsgSend((hal_rpmsg_handle_t)mac_rpmsg_handle, (uint8_t *)pMsg, sizeof(macToPlmeMessage_t)) != kStatus_HAL_RpmsgSuccess)
        {
            ret = gInvalidParameter_c;
            break;
        }

        if (pMsg->msgType == gPlmeGetReq_c)
        {
            wait_response();
            wait_proxy_rsp = FALSE;

            pMsg->msgData.getReq.PibAttributeValue = phy_get_rsp.PibAttributeValue;
        }
    } while (0);

    wait_proxy_rsp = FALSE;
    PLATFORM_RemoteActiveRel();
    OSA_MutexUnlock(mac_intf_mutex);

    return ret;
}

resultType_t MAC_Plat_Cmd(macPlatMessage_t *pMsg, instanceId_t macInstanceId)
{
    osa_event_flags_t flags;
    resultType_t ret = gSuccess_c;

    if (!mac_intf_init_done)
    {
        return gInvalidParameter_c;
    }

    OSA_MutexLock(mac_intf_mutex, osaWaitForever_c);
    PLATFORM_RemoteActiveReq();

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
            wait_plat_rsp = TRUE;
        }

        if (HAL_RpmsgSend((hal_rpmsg_handle_t)mac_rpmsg_handle, (uint8_t *)pMsg, sizeof(macPlatMessage_t) + pMsg->data_len) != kStatus_HAL_RpmsgSuccess)
        {
            ret = gInvalidParameter_c;
            break;
        }

        if (pMsg->is_get)
        {
            wait_response();
            wait_plat_rsp = FALSE;

            pMsg->data_len = 0;
            if (plat_get_rsp)
            {
                if (pMsg->data_len > plat_get_rsp->data_len)
                {
                    pMsg->data_len = plat_get_rsp->data_len;
                }
                memcpy((uint8_t *)pMsg + sizeof(macPlatMessage_t), (uint8_t *)plat_get_rsp + sizeof(macPlatMessage_t), pMsg->data_len);

                MSG_Free(plat_get_rsp);
            }
        }
    } while (0);

    wait_plat_rsp = FALSE;
    PLATFORM_RemoteActiveRel();
    OSA_MutexUnlock(mac_intf_mutex);

    return ret;
}

void MAC_Init()
{
    OSA_InterruptDisable();

    if (mac_intf_init_done || mac_intf_init_ongoing)
    {
        OSA_InterruptEnable();
        return;
    }

    mac_intf_init_ongoing = TRUE;

    OSA_InterruptEnable();

    /* Phy link must be initialized as ZB can make direct calls to the Phy */
    Phy_Init();

    if (HAL_RpmsgInit((hal_rpmsg_handle_t)mac_rpmsg_handle, &mac_rpmsg_config) != kStatus_HAL_RpmsgSuccess)
    {
        assert(0);
        return;
    }

    if (HAL_RpmsgInstallRxCallback((hal_rpmsg_handle_t)mac_rpmsg_handle, mac_rpmsg_rx_callback, NULL) != kStatus_HAL_RpmsgSuccess)
    {
        assert(0);
        return;
    }

    /* get_pib_rsp_event with 0 auto clear to allow the task to run after flags have been set */
    OSA_EventCreate((osa_event_handle_t)get_event, 0);

    OSA_MutexCreate((osa_mutex_handle_t)mac_intf_mutex);

    OSA_MsgQCreate((osa_msgq_handle_t)mac_intf_cb_queue, MAC_INTF_CB_QUEUE_SIZE, sizeof(macMsgHeader_t *));
    OSA_TaskCreate((osa_task_handle_t)mac_intf_cb_task, OSA_TASK(mac_intf_cb_task_func), NULL);

    mac_intf_init_done = TRUE;
}

/* reference implementation of MAC_PLME_SapHandler() using MAC API.
   Not used for k32w1 since it's implemented in Phy.c
phyStatus_t demo_MAC_PLME_SapHandler(macToPlmeMessage_t *pMsg, instanceId_t phyInstance)
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
*/
