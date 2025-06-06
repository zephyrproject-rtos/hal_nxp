/*! *********************************************************************************
* Copyright 2021-2025 NXP
* All rights reserved.
*
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#include "EmbeddedTypes.h"
#include "PhyInterface.h"
#include "Phy.h"

#include "fsl_adapter_rpmsg.h"
#include "fsl_os_abstraction.h"
#include "fwk_platform.h"
#if defined(HDI_MODE) && (HDI_MODE == 1)
#include "hdi.h"
#endif
#if (defined(HWINIT_DEBUG_DTEST) && (HWINIT_DEBUG_DTEST == 1L))
#include "dtest.h"
#endif

#ifdef MEM_USE_ZEPHYR
#include <zephyr/kernel.h>

#define PHY_MSG_Alloc(x) k_malloc(x)
#define PHY_MSG_Free(x) k_free(x)

#else	/* MEM_USE_ZEPHYR */
#include "fsl_component_messaging.h"

#define PHY_MSG_Alloc(x) MSG_Alloc(x)
#define PHY_MSG_Free(x) MSG_Free(x)
#endif	/* MEM_USE_ZEPHYR */

#undef CTX_NO
#define CTX_NO 2

#define PHY_GET_CTX_CNT 10

#define PHY_INTF_CB_QUEUE_SIZE 10
#define PHY_INTF_CB_TASK_PRIORITY 4
#define PHY_INTF_CB_TASK_STACK_SIZE 1024

static struct phy_local
{
    uint32_t id;

    PD_MAC_SapHandler_t         PD_MAC_SapHandler;
    PLME_MAC_SapHandler_t       PLME_MAC_SapHandler;
} phyLocal[CTX_NO];

static RPMSG_HANDLE_DEFINE(phyRpmsgHandle);
static hal_rpmsg_config_t phyRpmsgConfig = {
    .local_addr  = 10,
    .remote_addr = 20,
#if defined(RW610_SERIES)
    .imuLink     = kIMU_LinkCpu2Cpu3
#endif
};

static uint8_t wait_phy_rsp = FALSE;
static plmeGetReq_t phy_get_rsp;

static OSA_EVENT_HANDLE_DEFINE(get_event);

static OSA_MUTEX_HANDLE_DEFINE(phy_intf_mutex);
static OSA_MSGQ_HANDLE_DEFINE(phy_intf_cb_queue, PHY_INTF_CB_QUEUE_SIZE, sizeof(phyMessageHeader_t *));

static void phy_intf_cb_task_func();
static OSA_TASK_HANDLE_DEFINE(phy_intf_cb_task);
static OSA_TASK_DEFINE(phy_intf_cb_task_func, PHY_INTF_CB_TASK_PRIORITY, 1, PHY_INTF_CB_TASK_STACK_SIZE, FALSE);

static bool_t phy_intf_init_done = FALSE;
static bool_t phy_intf_init_ongoing = FALSE;
extern const uint8_t gUseRtos_c;


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

static void phy_intf_cb_task_func()
{
    phyMessageHeader_t *msg;
    bool_t msg_free;

    while (1)
    {
        if (OSA_MsgQGet(phy_intf_cb_queue, &msg, osaWaitForever_c) == KOSA_StatusSuccess)
        {
            msg_free = TRUE;

            switch (msg->msgType)
            {
                case gPdDataInd_c:
                    if (phyLocal[msg->ctx_id].PD_MAC_SapHandler)
                    {
                        msg_free = FALSE;
                        ((pdDataToMacMessage_t *)msg)->msgData.dataInd.pPsdu = (uint8_t *)msg + sizeof(pdDataToMacMessage_t);

                        phyLocal[msg->ctx_id].PD_MAC_SapHandler((pdDataToMacMessage_t *)msg, msg->ctx_id);
                    }
                    break;

                case gPdDataCnf_c:
                    if (phyLocal[msg->ctx_id].PD_MAC_SapHandler)
                    {
                        msg_free = FALSE;
                        ((pdDataToMacMessage_t *)msg)->msgData.dataCnf.ackData = (uint8_t *)msg + sizeof(pdDataToMacMessage_t);

                        phyLocal[msg->ctx_id].PD_MAC_SapHandler((pdDataToMacMessage_t *)msg, msg->ctx_id);
                    }
                    break;

                case gPlmeCcaCnf_c:
                case gPlmeEdCnf_c:
                case gPlmeSetCnf_c:
                case gPlmeTimeoutInd_c:
                case gPlmeAbortInd_c:
                    if (phyLocal[msg->ctx_id].PLME_MAC_SapHandler)
                    {
                        msg_free = FALSE;
                        phyLocal[msg->ctx_id].PLME_MAC_SapHandler((plmeToMacMessage_t *)msg, msg->ctx_id);
                    }
                    break;
            }

            if (msg_free)
            {
                PHY_MSG_Free(msg);
            }
        }

        if (!gUseRtos_c)
        {
            break;
        }
    }
}

static hal_rpmsg_return_status_t PhyRpmsgRxCallback(void *param, uint8_t *data, uint32_t len)
{
    (void)param;
    phyMessageHeader_t *pMsg = (phyMessageHeader_t *)data;

    if (pMsg->msgType == gPlmeGetReq_c)
    {
        if (wait_phy_rsp)
        {
            phy_get_rsp = ((macToPlmeMessage_t *)pMsg)->msgData.getReq;

            OSA_EventSet(get_event, 1);
        }
        return kStatus_HAL_RL_RELEASE;
    }

    pMsg = (phyMessageHeader_t *)PHY_MSG_Alloc(len);
    if (!pMsg)
    {
        return kStatus_HAL_RL_RELEASE;
    }
    memcpy(pMsg, data, len);

    if (pMsg->ctx_id >= CTX_NO)
    {
        pMsg->ctx_id = 0;
    }

    if (OSA_MsgQPut(phy_intf_cb_queue, &pMsg) != KOSA_StatusSuccess)
    {
        PHY_MSG_Free(pMsg);
    }

    return kStatus_HAL_RL_RELEASE;
}

void Phy_Init(void)
{
    OSA_InterruptDisable();

    if (phy_intf_init_done || phy_intf_init_ongoing)
    {
        OSA_InterruptEnable();
        return;
    }

    phy_intf_init_ongoing = TRUE;

    OSA_InterruptEnable();

#ifndef MEM_USE_ZEPHYR
    /* prepare to send RNG seed to NBU */
    int PLATFORM_FwkSrvInit();
    PLATFORM_FwkSrvInit();

    int RNG_Init();
    RNG_Init();
#endif /* MEM_USE_ZEPHYR */

    if (HAL_RpmsgInit((hal_rpmsg_handle_t)phyRpmsgHandle, &phyRpmsgConfig) != kStatus_HAL_RpmsgSuccess)
    {
        assert(0);
        return;
    }

    if (HAL_RpmsgInstallRxCallback((hal_rpmsg_handle_t)phyRpmsgHandle, PhyRpmsgRxCallback, NULL) != kStatus_HAL_RpmsgSuccess)
    {
        assert(0);
        return;
    }

    /* plmeEventHandle with 0 auto clear to allow the task to run after flags have been set */
    OSA_EventCreate((osa_event_handle_t)get_event, 0);

    OSA_MutexCreate((osa_mutex_handle_t)phy_intf_mutex);

    OSA_MsgQCreate((osa_msgq_handle_t)phy_intf_cb_queue, PHY_INTF_CB_QUEUE_SIZE, sizeof(phyMessageHeader_t *));
    OSA_TaskCreate((osa_task_handle_t)phy_intf_cb_task, OSA_TASK(phy_intf_cb_task_func), NULL);

    /* Configure DTEST signals for debug */
#if (defined(HWINIT_DEBUG_DTEST) && (HWINIT_DEBUG_DTEST == 1L))
    dtest_init(DTEST0 | DTEST1 | DTEST2 | DTEST3 | DTEST4 | DTEST5 | DTEST6 | DTEST7 | DTEST8 | DTEST9 | DTEST10 | DTEST11 | DTEST12 | DTEST13 );
    dtest_select(0x00); /* Place selftest waveform onto DTEST ports */
#endif

    phy_intf_init_done = TRUE;
}

/*! *********************************************************************************
* \brief  This function registers the MAC PD and PLME SAP handlers
*
* \param[in]  pPD_MAC_SapHandler   Pointer to the MAC PD handler function
* \param[in]  pPLME_MAC_SapHandler Pointer to the MAC PLME handler function
* \param[in]  instanceId           The instance of the PHY
*
* \return  The status of the operation.
*
********************************************************************************** */
void Phy_RegisterSapHandlers(PD_MAC_SapHandler_t pPD_MAC_SapHandler,
                             PLME_MAC_SapHandler_t pPLME_MAC_SapHandler,
                             instanceId_t instanceId)
{
    if (!phy_intf_init_done)
    {
        return;
    }

    if (instanceId >= CTX_NO)
    {
        instanceId = 0;
    }

    phyLocal[instanceId].PD_MAC_SapHandler = pPD_MAC_SapHandler;
    phyLocal[instanceId].PLME_MAC_SapHandler = pPLME_MAC_SapHandler;
}

/*! *********************************************************************************
* \brief  This is the PLME SAP message handler
*
* \param[in]  pMsg Pointer to the PLME request message
* \param[in]  instanceId The instance of the PHY
*
* \return  phyStatus_t The status of the operation.
*
********************************************************************************** */
phyStatus_t MAC_PLME_SapHandler(macToPlmeMessage_t *pMsg, instanceId_t phyInstance)
{
    phyStatus_t ret = gPhySuccess_c;
    osa_event_flags_t flags;

    if (!phy_intf_init_done)
    {
        return gPhyInvalidParameter_c;
    }

    OSA_MutexLock(phy_intf_mutex, osaWaitForever_c);
    PLATFORM_RemoteActiveReq();

    do
    {
        if (phyInstance >= CTX_NO)
        {
            phyInstance = 0;
        }

        pMsg->ctx_id = phyInstance;

        /* Bind Event with current task (main_task usually) in case RPMSG response is faster than
         * OSA_EventWait in the loop below.
         */
        if (pMsg->msgType == gPlmeGetReq_c)
        {
            phy_get_rsp.PibAttributeValue = 0;

            OSA_EventWait(get_event, 1, 1, osaWaitNone_c, &flags);
            wait_phy_rsp = TRUE;
        }

#if defined(HDI_MODE) && (HDI_MODE == 1)
        if ((pMsg->msgType == gPlmeSetReq_c) && (pMsg->msgData.setReq.PibAttribute == gPhyPibCurrentChannel_c))
        {
            if (pMsg->msgData.setReq.PibAttribute == gPhyPibCurrentChannel_c)
            {
                HDI_SendChannelSwitchCmd((uint32_t)pMsg->msgData.setReq.PibAttributeValue);
            }
        }
#endif

        if (HAL_RpmsgSend((hal_rpmsg_handle_t)phyRpmsgHandle, (uint8_t *)pMsg, sizeof(macToPlmeMessage_t)) != kStatus_HAL_RpmsgSuccess)
        {
            ret = gPhyBusy_c;
            break;
        }

        if (pMsg->msgType == gPlmeGetReq_c)
        {
            wait_response();
            wait_phy_rsp = FALSE;

            pMsg->msgData.getReq.PibAttributeValue = phy_get_rsp.PibAttributeValue;
        }
    } while(0);

    wait_phy_rsp = FALSE;
    PLATFORM_RemoteActiveRel();
    OSA_MutexUnlock(phy_intf_mutex);

    return ret;
}

/*! *********************************************************************************
* \brief  This is the PD SAP message handler
*
* \param[in]  pMsg Pointer to the PD request message
* \param[in]  instanceId The instance of the PHY
*
* \return  The status of the operation.
*
********************************************************************************** */
phyStatus_t MAC_PD_SapHandler(macToPdDataMessage_t *pMsg, instanceId_t phyInstance)
{
    uint32_t len = sizeof(macToPdDataMessage_t);
    phyStatus_t ret = gPhySuccess_c;

    if (!phy_intf_init_done)
    {
        return gPhyInvalidParameter_c;
    }

    OSA_MutexLock(phy_intf_mutex, osaWaitForever_c);
    PLATFORM_RemoteActiveReq();

    do
    {
        if (phyInstance >= CTX_NO)
        {
            phyInstance = 0;
        }

        pMsg->ctx_id = phyInstance;

        if (pMsg->msgType == gPdDataReq_c)
        {
            len += pMsg->msgData.dataReq.psduLength;
        }

        if (HAL_RpmsgSend((hal_rpmsg_handle_t)phyRpmsgHandle, (uint8_t *)pMsg, len) != kStatus_HAL_RpmsgSuccess)
        {
             ret = gPhyBusy_c;
             break;
        }
    } while (0);

    PLATFORM_RemoteActiveRel();
    OSA_MutexUnlock(phy_intf_mutex);

    return ret;
}

uint8_t PHY_get_ctx()
{
    uint8_t cnt = PHY_GET_CTX_CNT;
    phyStatus_t ret;
    macToPlmeMessage_t msg;

    msg.msgType = gPlmeGetReq_c;
    msg.msgData.getReq.PibAttribute = gPhyGetCtxId;
    msg.msgData.getReq.PibAttributeValue = (uint64_t)(-1);

    /* wait for NBU to be ready */
    do
    {
        ret = MAC_PLME_SapHandler(&msg, 0);
    } while ((ret != gPhySuccess_c) && (cnt--));

    assert(ret == gPhySuccess_c);

#ifndef MEM_USE_ZEPHYR
    /* send RNG seed to NBU */
    int RNG_SetSeed(void);
    RNG_SetSeed();
#endif /* MEM_USE_ZEPHYR */

    return (uint8_t)msg.msgData.getReq.PibAttributeValue;
}

/*! *********************************************************************************
* \brief  This function returns the RSSI for the last received packet
*
* \return  uint8_t  RSSI value
*
********************************************************************************** */
uint8_t PhyGetLastRxRssiValue(void)
{
    int32_t lqi_to_rssi = 0;

    return (uint8_t)lqi_to_rssi;
}

int8_t PhyConvertLQIToRSSI(uint8_t lqi)
{
    int32_t rssi = (36 * lqi - 9836) / 109;

    return (int8_t)rssi;
}
