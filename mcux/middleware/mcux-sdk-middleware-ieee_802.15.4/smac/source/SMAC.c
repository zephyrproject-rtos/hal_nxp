/*! *********************************************************************************
* Copyright (c) 2014 - 2026, Freescale Semiconductor, Inc.
* Copyright 2016-2024,2026 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "SMAC.h"
#include "PhyInterface.h"
#include "AspInterface.h"
#include "EmbeddedTypes.h"

#include "SMAC_Config.h"
#ifndef __ZEPHYR__
#include "fsl_component_mem_manager.h"
#else /* __ZEPHYR__ */
#include <zephyr/kernel.h>

#define MSG_Alloc(x) k_malloc(x)
#define MSG_Free(x)  k_free(x)
#define MEM_BufferAlloc(x) k_malloc(x)
#define MEM_BufferAllocWithId(x,y) k_malloc(x)
#define MEM_BufferFree(x)          k_free(x)
#endif
#include "FunctionLib.h"
#include "fsl_os_abstraction.h"

#if (defined(FSL_FEATURE_SOC_LTC_COUNT) && (FSL_FEATURE_SOC_LTC_COUNT > 0))
#ifndef __ZEPHYR__
#include "fsl_ltc.h"
#endif
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#if gSmacUseSecurity_c
#define ENC_BLOCK_SIZE (16)
#endif


/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

#ifndef __ZEPHYR__
static const char* mSmacVersionString = (char*)gSmacVerString_c;

RegisterModuleInfo(SMAC, /* DO NOT MODIFY */
                   mSmacVersionString, /* DO NOT MODIFY */
                   gSmacModuleId_c, /* DO NOT MODIFY, EDIT in SMAC.h */
                   gSmacVerMajor_c, /* DO NOT MODIFY, EDIT in SMAC.h */
                   gSmacVerMinor_c, /* DO NOT MODIFY, EDIT in SMAC.h */
                   gSmacVerPatch_c, /* DO NOT MODIFY, EDIT in SMAC.h */
                   gSmacBuildNo_c); /* DO NOT MODIFY, EDIT in SMAC.h */
#endif /* __ZEPHYR__ */

static smacInternalAttrib_t maSmacAttributes;

static uint8_t mSmacInitialized;

#if gSmacUseSecurity_c

static const uint8_t TEST_KEY[ENC_BLOCK_SIZE] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};

static const uint8_t TEST_IV[ENC_BLOCK_SIZE]  = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

#if (defined(FSL_FEATURE_SOC_LTC_COUNT) && (FSL_FEATURE_SOC_LTC_COUNT > 0))

static const uint8_t TEST_DKEY[ENC_BLOCK_SIZE] = {
    0xd0, 0x14, 0xf9, 0xa8, 0xc9, 0xee, 0x25, 0x89,
    0xe1, 0x3f, 0x0c, 0xc8, 0xb6, 0x63, 0x0c, 0xa6
};

#endif /* FSL_FEATURE_SOC_LTC_COUNT */

#endif /* gSmacUseSecurity_c */

/* -------------------------------------------------------------------------- */
/*                               Public memory                                */
/* -------------------------------------------------------------------------- */

uint8_t gTotalChannels;

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

#if gSmacUseSecurity_c

static void SMAC_SetIVKey(uint8_t* KEY, uint8_t* IV)
{
    FLib_MemCpy(maSmacAttributes.secInit.KEY, KEY, ENC_BLOCK_SIZE);
    FLib_MemCpy(maSmacAttributes.secInit.IV, IV, ENC_BLOCK_SIZE);

#if (defined(FSL_FEATURE_SOC_LTC_COUNT) && (FSL_FEATURE_SOC_LTC_COUNT > 0))
    // This API is not working on K4W1 FPGA, see KFOURWONE-311 jira ticket
    //LTC_AES_GenerateDecryptKey(LTC0, maSmacAttributes.secInit.KEY, maSmacAttributes.secInit.DKEY, ENC_BLOCK_SIZE);
    FLib_MemCpy(maSmacAttributes.secInit.DKEY, (uint8_t*)TEST_DKEY, ENC_BLOCK_SIZE);
#endif
}

static void SMAC_Encrypt(uint8_t* pIn, uint8_t* pOut, uint8_t *len, smacMultiPanInstances_t panID)
{
    *len = AES_128_CBC_Encrypt_And_Pad(pIn, (uint32_t)(*len),
                                     maSmacAttributes.secInit.IV,
                                     maSmacAttributes.secInit.KEY,
                                     pOut);
}

static void SMAC_Decrypt(uint8_t* pIn, uint8_t* pOut, uint8_t *len, smacMultiPanInstances_t panID)
{
#if (defined(FSL_FEATURE_SOC_LTC_COUNT) && (FSL_FEATURE_SOC_LTC_COUNT > 0))
    *len = AES_128_CBC_Decrypt_And_Depad(pIn, (uint32_t)(*len),
                                       maSmacAttributes.secInit.IV,
                                       maSmacAttributes.secInit.DKEY,
                                       pOut);
#else
    *len = AES_128_CBC_Decrypt_And_Depad(pIn, (uint32_t)(*len),
                                       maSmacAttributes.secInit.IV,
                                       maSmacAttributes.secInit.KEY,
                                       pOut);
#endif
}

#endif /* gSmacUseSecurity_c */

#ifndef __ZEPHYR__
static void BackoffTimeElapsed(void* param)
{
    uint8_t u8PhyRes = MAC_PD_SapHandler(maSmacAttributes.gSmacDataMessage, maSmacAttributes.phy_context_id);
    if(u8PhyRes != gPhySuccess_c)
    {
        OSA_InterruptDisable();
        maSmacAttributes.smacState = mSmacStateIdle_c;
        OSA_InterruptEnable();

        MSG_Free(maSmacAttributes.gSmacDataMessage);
        maSmacAttributes.gSmacDataMessage = NULL;
    }
}
#else /* __ZEPHYR__ */
/* Zephyr k_timer used. k_timer expiry runs in INTERRUPT context, so SMAC work is deferred
 * to s_backoff_work. MAC_PD_SapHandler() and MSG_Free() must NOT run in ISR.
 * This path is DORMANT because SMAC_Config.h sets CCA_BEFORE_TX (FALSE). */
static struct k_work s_backoff_work;

static void backoff_work_handler(struct k_work *w)
{
    ARG_UNUSED(w);
    uint8_t u8PhyRes = MAC_PD_SapHandler(maSmacAttributes.gSmacDataMessage,
                                          maSmacAttributes.phy_context_id);
    if (u8PhyRes != gPhySuccess_c)
    {
        OSA_InterruptDisable();
        maSmacAttributes.smacState = mSmacStateIdle_c;
        OSA_InterruptEnable();

        MSG_Free(maSmacAttributes.gSmacDataMessage);
        maSmacAttributes.gSmacDataMessage = NULL;
    }
}

static void BackoffTimeElapsed(struct k_timer *timer)
{
    /* ISR context: defer the SMAC logic to the system work queue. */
    ARG_UNUSED(timer);
    (void)k_work_submit(&s_backoff_work);
}
#endif

static bool_t SMACPacketCheck(pdDataToMacMessage_t* pMsgFromPhy)
{
    //check if packet is of type Data
    if((pMsgFromPhy->msgData.dataInd.pPsdu[0] & 0x07) != 0x01)
    {
        return FALSE;
    }

    //check if PSDU length is at least of SMAC header size.
    if(pMsgFromPhy->msgData.dataInd.psduLength < gSmacHeaderBytes_c)
    {
        return FALSE;
    }

    //check if PSDU length is greater than the maximum configured SMAC packet size.
    if(pMsgFromPhy->msgData.dataInd.psduLength > (maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer->u8MaxDataLength + gSmacHeaderBytes_c))
    {
        return FALSE;
    }

    return TRUE;
}

static phyStatus_t PD_SMAC_SapHandler(void* pMsg, instanceId_t instance)
{
    pdDataToMacMessage_t*   pDataMsg = (pdDataToMacMessage_t*)pMsg;
    smacToAppDataMessage_t* pSmacMsg;

    /* This handler should only come from the Phy Context we explicitly linked with
     * this SMAC Context.
     */
    assert(maSmacAttributes.phy_context_id == instance);

    switch(pDataMsg->msgType)
    {
    case gPdDataCnf_c:
        if(NULL == maSmacAttributes.gSmacDataMessage)
        {
            /* TODO: this should never happen: receiving a confirm without having sent/queued
             * a packet; consider using an assert here.
             */
            break;
        }

        /* TODO: since we're only sending a packet at a time consider allocating a packet statically
         * and don't use dynamic allocation MSG_BufferAlloc() / MSG_Free() for gSmacDataMessage
         */
        MSG_Free(maSmacAttributes.gSmacDataMessage);
        maSmacAttributes.gSmacDataMessage = NULL;

        pSmacMsg = MEM_BufferAlloc(sizeof(smacToAppDataMessage_t));
        if(pSmacMsg == NULL)
        {
            break;
        }

        pSmacMsg->msgType = gMcpsDataCnf_c;
        pSmacMsg->appInstanceId = instance;
        pSmacMsg->msgData.dataCnf.status = gErrorNoError_c;
        maSmacAttributes.gSMAC_APP_MCPS_SapHandler(pSmacMsg, instance);

        OSA_InterruptDisable();
        maSmacAttributes.smacState = mSmacStateIdle_c;
        OSA_InterruptEnable();

        break;

    case gPdDataInd_c:
        if(FALSE == SMACPacketCheck(pDataMsg))
        { /* we have received a packet that is not SMAC specific */

            /* if RX started with a timeout it means the RX ended with the reception of this packet
             * and therefore we need to inform the application.
             */
            if(maSmacAttributes.mSmacTimeoutAsked)
            {
                pSmacMsg = MEM_BufferAlloc(sizeof(smacToAppDataMessage_t));
                if (pSmacMsg == NULL)
                {
                    break;
                }

                pSmacMsg->msgType = gMcpsDataInd_c;
                pSmacMsg->appInstanceId = instance;
                pSmacMsg->msgData.dataInd.pRxPacket = maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer;
                pSmacMsg->msgData.dataInd.pRxPacket->rxStatus = rxAbortedStatus_c;

                maSmacAttributes.gSMAC_APP_MCPS_SapHandler(pSmacMsg, instance);

                OSA_InterruptDisable();
                maSmacAttributes.smacState = mSmacStateIdle_c;
                OSA_InterruptEnable();
            }
        }
        else
        { /* we have received a packet that is SMAC specific: need to process it */

            maSmacAttributes.smacLastDataRxParams.linkQuality = pDataMsg->msgData.dataInd.ppduLinkQuality;
            maSmacAttributes.smacLastDataRxParams.timeStamp   = (phyTime_t)pDataMsg->msgData.dataInd.timeStamp;
            maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer->rxStatus = rxSuccessStatus_c;

#if gSmacUseSecurity_c
            uint8_t len = pDataMsg->msgData.dataInd.psduLength - gSmacHeaderBytes_c - gPhyFCSSize_c;
            SMAC_Decrypt(pDataMsg->msgData.dataInd.pPsdu + gSmacHeaderBytes_c, pDataMsg->msgData.dataInd.pPsdu + gSmacHeaderBytes_c,
                       &len,
                       (smacMultiPanInstances_t)instance);
            pDataMsg->msgData.dataInd.psduLength = len + gSmacHeaderBytes_c + gPhyFCSSize_c;
#endif

            // in case no timeout was asked we need to unset RXOnWhenIdle Pib.
            if(!maSmacAttributes.mSmacTimeoutAsked)
            {
                (void)MLMERXDisableRequest();
            }

            maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer->u8DataLength 
                = pDataMsg->msgData.dataInd.psduLength - gSmacHeaderBytes_c - gPhyFCSSize_c;

            FLib_MemCpy(&maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer->smacHeader,
                      ((smacHeader_t*)pDataMsg->msgData.dataInd.pPsdu),
                      gSmacHeaderBytes_c);
            FLib_MemCpy(&maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer->smacPdu,
                      ((smacPdu_t*)(pDataMsg->msgData.dataInd.pPsdu + gSmacHeaderBytes_c)),
                      maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer->u8DataLength);

            pSmacMsg = MEM_BufferAlloc(sizeof(smacToAppDataMessage_t));
            if(pSmacMsg == NULL)
            {
                break;
            }

            pSmacMsg->msgType = gMcpsDataInd_c;
            pSmacMsg->msgData.dataInd.pRxPacket = maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer;
            pSmacMsg->msgData.dataInd.u8LastRxRssi = ((pdDataToMacMessage_t *)pMsg)->msgData.dataInd.ppduRssi;
            maSmacAttributes.gSMAC_APP_MCPS_SapHandler(pSmacMsg, instance);

            OSA_InterruptDisable();
            maSmacAttributes.smacState = mSmacStateIdle_c;
            OSA_InterruptEnable();
        }
        break;

    default:
        break;
    }

    MSG_Free(pMsg);
    return gPhySuccess_c;
}

static phyStatus_t PLME_SMAC_SapHandler(void* pMsg, instanceId_t instance)
{
    uint32_t backOffTime = 0;
    smacToAppMlmeMessage_t* pSmacToApp;
    smacToAppDataMessage_t* pSmacMsg;
    plmeToMacMessage_t* pPlmeMsg = (plmeToMacMessage_t*)pMsg;

    /* The request should never come from a phy that was not linked to this
     * SMAC context
     */
    assert (maSmacAttributes.phy_context_id == instance);

    /* TODO: check to see why we need to keep a pointer to the MLME message.
     * If it is because we have to de-allocate the pointer maybe consider using
     * static allocation.
     */
    if (maSmacAttributes.gSmacMlmeMessage)
    {
        MSG_Free(maSmacAttributes.gSmacMlmeMessage);
        maSmacAttributes.gSmacMlmeMessage = NULL;
    }

    switch(pPlmeMsg->msgType)
    {
    case gPlmeCcaCnf_c:
        if(pPlmeMsg->msgData.ccaCnf.status == gPhyChannelBusy_c && maSmacAttributes.smacState == mSmacStateTransmitting_c)
        {
            /* TODO: check the validity of this branch:
             * when we start a CCARequest() we always check that the SMAC is in IDLE mode and only then
             * switch to CCA mode. So there should be no situation when we started CCA but ended with
             * the confirm in TX mode.
             */
            if(maSmacAttributes.txConfigurator.ccaBeforeTx)
            {
                if(maSmacAttributes.txConfigurator.retryCountCCAFail > maSmacAttributes.u8CCARetryCounter)
                {
                    maSmacAttributes.u8CCARetryCounter++;
#ifndef __ZEPHYR__
                    HAL_RngGetData(&backOffTime, sizeof(backOffTime));
#else /* __ZEPHYR__ */
                    sys_rand_get(&backOffTime, sizeof(backOffTime));
#endif
#if !defined(RW610N_BT_CM3_SERIES)
                    /* TODO: MCRED-2 support timers on Redfinch */
#ifndef __ZEPHYR__
                    TM_Start(maSmacAttributes.u8BackoffTimerId, kTimerModeSingleShot, ((backOffTime & gMaxBackoffTime_c) + gMinBackoffTime_c));
#else /* __ZEPHYR__ */
                    /* 802.15.4 backoff unit is SYMBOL period (16 us), not ms.
                     * gMaxBackoffTime_c = 0x1F (31 symbols ~= 0.5 ms). */
                    k_timer_start(&maSmacAttributes.u8BackoffTimerId,
                                  K_USEC(((backOffTime & gMaxBackoffTime_c) + gMinBackoffTime_c) * 16U),
                                  K_NO_WAIT);
#endif
#endif
                }
                else
                {
                    MSG_Free(maSmacAttributes.gSmacDataMessage);
                    maSmacAttributes.gSmacDataMessage = NULL;

                    pSmacMsg = MEM_BufferAlloc(sizeof(smacToAppDataMessage_t));
                    if(pSmacMsg != NULL)
                    {
                        pSmacMsg->msgType                = gMcpsDataCnf_c;
                        pSmacMsg->appInstanceId          = instance;
                        pSmacMsg->msgData.dataCnf.status = gErrorChannelBusy_c;

                        (void)maSmacAttributes.gSMAC_APP_MCPS_SapHandler(pSmacMsg, instance);
                    }

                    OSA_InterruptDisable();
                    maSmacAttributes.smacState = mSmacStateIdle_c;
                    OSA_InterruptEnable();
                }
            }

            MSG_Free(pMsg);
            return gPhySuccess_c;
        }

        // if SMAC isn't in TX then definitely it is a CCA confirm allocate a message for the application
        pSmacToApp = MEM_BufferAlloc(sizeof(smacToAppMlmeMessage_t));
        if(pSmacToApp != NULL)
        {
            pSmacToApp->msgType       = gMlmeCcaCnf_c;
            pSmacToApp->appInstanceId = instance;

            //Channel status translated into SMAC messages: idle channel means no error.
            if(pPlmeMsg->msgData.ccaCnf.status == gPhyChannelIdle_c)
            {
                pSmacToApp->msgData.ccaCnf.status = gErrorNoError_c;
            }
            else
            {
                pSmacToApp->msgData.ccaCnf.status = gErrorChannelBusy_c;
            }
        }
        break;

    case gPlmeEdCnf_c:
        pSmacToApp = MEM_BufferAlloc(sizeof(smacToAppMlmeMessage_t));
        if(pSmacToApp != NULL)
        {
            pSmacToApp->msgType       = gMlmeEdCnf_c;
            pSmacToApp->appInstanceId = instance;
            if(pPlmeMsg->msgData.edCnf.status == gPhySuccess_c)
            {
                pSmacToApp->msgData.edCnf.status        = gErrorNoError_c;
                pSmacToApp->msgData.edCnf.energyLevel   = pPlmeMsg->msgData.edCnf.energyLevel;
                pSmacToApp->msgData.edCnf.energyLeveldB = pPlmeMsg->msgData.edCnf.energyLeveldB;
            }
            else
            {
                pSmacToApp->msgData.edCnf.status = gErrorBusy_c;
            }
        }
        break;

    case gPlmeTimeoutInd_c:
    case gPlmeAbortInd_c:
        if(maSmacAttributes.smacState == mSmacStateTransmitting_c)
        {
            if(maSmacAttributes.txConfigurator.autoAck)
            {
                //re-arm retries for channel busy at retransmission.
                maSmacAttributes.u8CCARetryCounter = 0;

                if(maSmacAttributes.txConfigurator.retryCountAckFail > maSmacAttributes.u8AckRetryCounter)
                {
                    maSmacAttributes.u8AckRetryCounter++;
#ifndef __ZEPHYR__
                    HAL_RngGetData(&backOffTime, sizeof(backOffTime));
#else /* __ZEPHYR__ */
                    sys_rand_get(&backOffTime, sizeof(backOffTime));
#endif
                    //start event timer. After time elapses, Data request will be fired.
#if !defined(RW610N_BT_CM3_SERIES)
                    /* TODO: MCRED-2 support timers on Redfinch */
#ifndef __ZEPHYR__
                    TM_Start(maSmacAttributes.u8BackoffTimerId, kTimerModeSingleShot, ((backOffTime & gMaxBackoffTime_c) + gMinBackoffTime_c));
#else /* __ZEPHYR__ */
                    /* 802.15.4 backoff unit is SYMBOL period (16 us), not ms.
                     * gMaxBackoffTime_c = 0x1F (31 symbols ~= 0.5 ms). */
                    k_timer_start(&maSmacAttributes.u8BackoffTimerId,
                                  K_USEC(((backOffTime & gMaxBackoffTime_c) + gMinBackoffTime_c) * 16U),
                                  K_NO_WAIT);
#endif
#endif
                }
                else
                {
                    (void)MSG_Free(maSmacAttributes.gSmacDataMessage);
                    maSmacAttributes.gSmacDataMessage = NULL;

                    //retries failed so create message for the application
                    pSmacMsg = MEM_BufferAlloc(sizeof(smacToAppDataMessage_t));
                    if(pSmacMsg != NULL)
                    {
                        pSmacMsg->msgType       = gMcpsDataCnf_c;
                        pSmacMsg->appInstanceId = instance;
                        pSmacMsg->msgData.dataCnf.status = gErrorNoAck_c;

                        maSmacAttributes.gSMAC_APP_MCPS_SapHandler(pSmacMsg, instance);
                    }

                    OSA_InterruptDisable();
                    maSmacAttributes.smacState = mSmacStateIdle_c;
                    OSA_InterruptEnable();
                }
            }

            MSG_Free(pMsg);
            return gPhySuccess_c;
        }

        //if no ack timeout was received then it is definitely a RX timeout
        pSmacToApp = MEM_BufferAlloc(sizeof(smacToAppMlmeMessage_t));
        if(pSmacToApp != NULL)
        {
            if(maSmacAttributes.smacState == mSmacStateReceiving_c)
            {
                maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer->rxStatus = rxTimeOutStatus_c;
            }
            pSmacToApp->msgType = gMlmeTimeoutInd_c;
        }
        break;

    case gPlme_UnexpectedRadioResetInd_c:
        pSmacToApp = MEM_BufferAlloc(sizeof(smacToAppMlmeMessage_t));
        if(pSmacToApp != NULL)
        {
            pSmacToApp->msgType = gMlme_UnexpectedRadioResetInd_c;
        }
        break;

    default:
        MSG_Free(pMsg);
        return gPhySuccess_c;
        break;
    }

    OSA_InterruptDisable();
    maSmacAttributes.smacState = mSmacStateIdle_c;
    OSA_InterruptEnable();

    if(pSmacToApp != NULL)
    {
        maSmacAttributes.gSMAC_APP_MLME_SapHandler(pSmacToApp, instance);
    }

    MSG_Free(pMsg);
    return gPhySuccess_c;
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void Smac_RegisterSapHandlers(SMAC_APP_MCPS_SapHandler_t pSMAC_APP_MCPS_SapHandler,
                              SMAC_APP_MLME_SapHandler_t pSMAC_APP_MLME_SapHandler,
                              instanceId_t smacInstanceId)
{
    maSmacAttributes.gSMAC_APP_MCPS_SapHandler = pSMAC_APP_MCPS_SapHandler;
    maSmacAttributes.gSMAC_APP_MLME_SapHandler = pSMAC_APP_MLME_SapHandler;
}

void InitSmac(instanceId_t phy_context_id)
{
    uint32_t u32RandomNo = 0;

#ifndef __ZEPHYR__
    HAL_RngInit();
#endif

#if gSmacUseSecurity_c
    SecLib_Init();
#endif

    gTotalChannels = 26;

#if(TRUE == smacInitializationValidation_d)
    mSmacInitialized = TRUE;
#endif

    maSmacAttributes.smacState = mSmacStateIdle_c;
    maSmacAttributes.phy_context_id = phy_context_id;
    maSmacAttributes.smacLastDataRxParams.linkQuality = 0;
    maSmacAttributes.smacLastDataRxParams.timeStamp = 0;

    /*clear defer tx flag*/
    macToPlmeMessage_t lMsg;
    lMsg.msgType = gPlmeSetReq_c;
    lMsg.ctx_id = phy_context_id;
    lMsg.msgData.setReq.PibAttribute = gPhyPibDeferTxIfRxBusy_c;
    lMsg.msgData.setReq.PibAttributeValue = (uint64_t)FALSE;
    (void)MAC_PLME_SapHandler(&lMsg, phy_context_id);

    maSmacAttributes.txConfigurator.autoAck = FALSE;
    maSmacAttributes.txConfigurator.enhAck = FALSE;
    maSmacAttributes.txConfigurator.ccaBeforeTx = FALSE;
    maSmacAttributes.txConfigurator.retryCountAckFail = 0;
    maSmacAttributes.txConfigurator.retryCountCCAFail = 0;

#if !defined(RW610N_BT_CM3_SERIES)
        /* TODO: MCRED-2 support timers on Redfinch */
#ifndef __ZEPHYR__
    (void)TM_Open(maSmacAttributes.u8BackoffTimerId);
    (void)TM_InstallCallback((timer_handle_t)maSmacAttributes.u8BackoffTimerId, BackoffTimeElapsed, NULL);
#else /* __ZEPHYR__ */
    k_timer_init(&maSmacAttributes.u8BackoffTimerId, BackoffTimeElapsed, NULL);
    k_work_init(&s_backoff_work, backoff_work_handler);
#endif
#endif

    (void)SMACSetShortSrcAddress(gNodeAddress_c);
    (void)SMACSetPanID(gDefaultPanID_c);
#ifndef __ZEPHYR__
    HAL_RngGetData(&u32RandomNo, sizeof(u32RandomNo));
#else /* __ZEPHYR__ */
    sys_rand_get(&u32RandomNo, sizeof(u32RandomNo));
#endif
    maSmacAttributes.u8SmacSeqNo = (uint8_t)u32RandomNo;

#if gSmacUseSecurity_c
    SMAC_SetIVKey((uint8_t*)TEST_KEY, (uint8_t*)TEST_IV);
#endif

    //Notify the PHY what function to call for communicating with SMAC
    Phy_RegisterSapHandlers((PD_MAC_SapHandler_t)PD_SMAC_SapHandler, (PLME_MAC_SapHandler_t)PLME_SMAC_SapHandler, phy_context_id);
}

smacErrors_t MCPSDataRequest (txPacket_t *psTxPacket)
{
    macToPdDataMessage_t *pMsg;

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif

#if(TRUE == smacParametersValidation_d)
    if((NULL == psTxPacket) || (gMaxSmacSDULength_c < psTxPacket->u8DataLength))
    {
        return gErrorOutOfRange_c;
    }
#endif

    if(mSmacStateIdle_c != maSmacAttributes.smacState)
    {
        return gErrorBusy_c;
    }

#if !gSmacUseSecurity_c
    pMsg = MSG_Alloc(sizeof(macToPdDataMessage_t) +
                         psTxPacket->u8DataLength + gSmacHeaderBytes_c);
#else
    pMsg = MSG_Alloc(sizeof(macToPdDataMessage_t) +
                         psTxPacket->u8DataLength + gSmacHeaderBytes_c + ENC_BLOCK_SIZE);
#endif

    if(pMsg == NULL )
    {
        return gErrorNoResourcesAvailable_c;
    }

    maSmacAttributes.u8SmacSeqNo++;
    maSmacAttributes.u8AckRetryCounter = 0;
    maSmacAttributes.u8CCARetryCounter = 0;

    /* Fill with Phy related data */
    pMsg->msgType = gPdDataReq_c;
    pMsg->ctx_id = maSmacAttributes.phy_context_id;
    pMsg->msgData.dataReq.startTime = gPhySeqStartAsap_c;

    if(maSmacAttributes.txConfigurator.autoAck &&
            psTxPacket->smacHeader.destAddr != 0xFFFF
#if !gEnhAckMode8
         && psTxPacket->smacHeader.panId != 0xFFFF
#endif
      )
    {
                                    //Turn@       +       phy payload(symbols)+ Turn@ + ACK
        pMsg->msgData.dataReq.txDuration = 12 + (gSmacHeaderBytes_c + psTxPacket->u8DataLength + 2)*2 + 12 + 42;

        if(maSmacAttributes.txConfigurator.ccaBeforeTx)
        {
            pMsg->msgData.dataReq.txDuration += 0x08; //CCA Duration: 8 symbols
        }

#if gSmacUseSecurity_c
        pMsg->msgData.dataReq.txDuration += (ENC_BLOCK_SIZE - ((psTxPacket->u8DataLength - gSmacHeaderBytes_c
                                                            + ENC_BLOCK_SIZE) & (ENC_BLOCK_SIZE - 1))) * 2;
#endif
    }
    else
    {
        pMsg->msgData.dataReq.txDuration = 0xFFFFFFFF;
    }

    pMsg->msgData.dataReq.psduLength = psTxPacket->u8DataLength + gSmacHeaderBytes_c + gPhyFCSSize_c; // include FCS bytes in data psdu length
    pMsg->msgData.dataReq.pPsdu = (uint8_t*)pMsg + sizeof(macToPdDataMessage_t);

    FLib_MemCpy(pMsg->msgData.dataReq.pPsdu, &(psTxPacket->smacHeader), gSmacHeaderBytes_c);
    FLib_MemCpy(pMsg->msgData.dataReq.pPsdu + gSmacHeaderBytes_c, &(psTxPacket->smacPdu), psTxPacket->u8DataLength);

    if(maSmacAttributes.txConfigurator.ccaBeforeTx)
    {
        pMsg->msgData.dataReq.CCABeforeTx = gPhyCCAMode1_c;
    }
    else
    {
        pMsg->msgData.dataReq.CCABeforeTx = gPhyNoCCABeforeTx_c;
    }

    if(maSmacAttributes.txConfigurator.autoAck &&
            psTxPacket->smacHeader.destAddr != 0xFFFF
#if !gEnhAckMode8
         && psTxPacket->smacHeader.panId != 0xFFFF
#endif
      )
    {
    //set frame control option: ACK.
        pMsg->msgData.dataReq.pPsdu[0] |=   gFrameCtrlAckReqMsk_c;
        pMsg->msgData.dataReq.ackRequired = gPhyRxAckRqd_c;

        if (maSmacAttributes.txConfigurator.enhAck) {
            // Set version 2
            pMsg->msgData.dataReq.pPsdu[1] |= (2 << 4);

#if gSmacUseExtendedAddr_c
#if !gEnhAckMode8
            // Set PAN ID compression to false
            pMsg->msgData.dataReq.pPsdu[0] &= 0xBF;
#endif
#endif
        }
    }
    else
    {
        pMsg->msgData.dataReq.ackRequired = gPhyNoAckRqd_c;
    }

#if gSmacUseSecurity_c
    uint8_t inputLen = pMsg->msgData.dataReq.psduLength - gSmacHeaderBytes_c - gPhyFCSSize_c;

    SMAC_Encrypt(pMsg->msgData.dataReq.pPsdu + gSmacHeaderBytes_c, pMsg->msgData.dataReq.pPsdu + gSmacHeaderBytes_c,
               &(inputLen),
               mSmacActivePan);
    pMsg->msgData.dataReq.psduLength = inputLen + gSmacHeaderBytes_c + gPhyFCSSize_c;
#endif

    pMsg->msgData.dataReq.pPsdu[2] = maSmacAttributes.u8SmacSeqNo;

    maSmacAttributes.gSmacDataMessage = pMsg;      //Store pointer for freeing later

    OSA_InterruptDisable();
    maSmacAttributes.smacState = mSmacStateTransmitting_c;
    OSA_InterruptEnable();

    if (MAC_PD_SapHandler(pMsg, maSmacAttributes.phy_context_id) == gPhySuccess_c)
    {
        return gErrorNoError_c;
    }

    MSG_Free(maSmacAttributes.gSmacDataMessage);
    maSmacAttributes.gSmacDataMessage = NULL;

    OSA_InterruptDisable();
    maSmacAttributes.smacState = mSmacStateIdle_c;
    OSA_InterruptEnable();

    return gErrorNoResourcesAvailable_c;
}

void MLMETXDisableRequest(void)
{
    macToPlmeMessage_t lMsg;

    lMsg.msgType     = gPlmeSetTRxStateReq_c;
    lMsg.ctx_id      = maSmacAttributes.phy_context_id;
    lMsg.msgData.setTRxStateReq.state = gPhyForceTRxOff_c;
    (void)MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);

    if(maSmacAttributes.gSmacDataMessage != NULL)
    {
        (void)MSG_Free(maSmacAttributes.gSmacDataMessage);
        maSmacAttributes.gSmacDataMessage = NULL;
    }

    OSA_InterruptDisable();
    maSmacAttributes.smacState = mSmacStateIdle_c;
    OSA_InterruptEnable();
}

smacErrors_t MLMERXEnableRequest(rxPacket_t *gsRxPacket, smacTime_t stTimeout)
{
    macToPlmeMessage_t lMsg;

#if(TRUE == smacParametersValidation_d)
#if gSmacUseSecurity_c
    if((NULL == gsRxPacket) || (gMaxSmacSDULength_c + 16 < gsRxPacket->u8MaxDataLength))
#else
    if((NULL == gsRxPacket) || (gMaxSmacSDULength_c < gsRxPacket->u8MaxDataLength))
#endif
    {
        return gErrorOutOfRange_c;
    }
#endif

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif

    if(mSmacStateIdle_c != maSmacAttributes.smacState)
    {
        return gErrorBusy_c;
    }

    lMsg.ctx_id = maSmacAttributes.phy_context_id;
    if(stTimeout)
    {
        lMsg.msgType = gPlmeSetTRxStateReq_c;
        lMsg.msgData.setTRxStateReq.startTime = gPhySeqStartAsap_c;
        lMsg.msgData.setTRxStateReq.state = gPhySetRxOn_c;
        lMsg.msgData.setTRxStateReq.rxDuration = stTimeout;
    }
    else
    {
        lMsg.msgType = gPlmeSetReq_c;
        lMsg.msgData.setReq.PibAttribute = gPhyPibRxOnWhenIdle;
        lMsg.msgData.setReq.PibAttributeValue = (uint64_t)1;
    }

    maSmacAttributes.mSmacTimeoutAsked = (stTimeout > 0);

    gsRxPacket->rxStatus = rxProcessingReceptionStatus_c;
    maSmacAttributes.smacProccesPacketPtr.smacRxPacketPointer = gsRxPacket;

    OSA_InterruptDisable();
    maSmacAttributes.smacState = mSmacStateReceiving_c;
    OSA_InterruptEnable();

    if (MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id) == gPhySuccess_c)
    {
        return gErrorNoError_c;
    }

    OSA_InterruptDisable();
    maSmacAttributes.smacState = mSmacStateIdle_c;
    OSA_InterruptEnable();

    return gErrorNoResourcesAvailable_c;
}

smacErrors_t MLMERXDisableRequest(void)
{
    macToPlmeMessage_t lMsg;

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif

    if((mSmacStateReceiving_c != maSmacAttributes.smacState) && (mSmacStateIdle_c != maSmacAttributes.smacState))
    {
        return gErrorNoValidCondition_c;
    }

    lMsg.ctx_id = maSmacAttributes.phy_context_id;

    OSA_InterruptDisable();
    smacStates_t lState = maSmacAttributes.smacState;
    maSmacAttributes.smacState = mSmacStateIdle_c;
    OSA_InterruptEnable();

    if(!maSmacAttributes.mSmacTimeoutAsked)
    {
        lMsg.msgType                          = gPlmeSetReq_c;
        lMsg.msgData.setReq.PibAttribute      = gPhyPibRxOnWhenIdle;
        lMsg.msgData.setReq.PibAttributeValue = (uint64_t)0;

        if (MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id) != gPhySuccess_c)
        {
            OSA_InterruptDisable();
            maSmacAttributes.smacState = lState;
            OSA_InterruptEnable();

            return gErrorBusy_c;
        }
    }
    else
    {
        maSmacAttributes.mSmacTimeoutAsked = FALSE;

        lMsg.msgType = gPlmeSetTRxStateReq_c;
        lMsg.msgData.setTRxStateReq.state = gPhyForceTRxOff_c;
        (void)MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);
    }

    return gErrorNoError_c;
}

smacErrors_t MLMESetChannelRequest(channels_t newChannel)
{
    uint8_t errorVal;
    macToPlmeMessage_t lMsg;

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif

    if(mSmacStateIdle_c != maSmacAttributes.smacState)
    {
        return gErrorBusy_c;
    }

    lMsg.msgType = gPlmeSetReq_c;
    lMsg.ctx_id = maSmacAttributes.phy_context_id;
    lMsg.msgData.setReq.PibAttribute = gPhyPibCurrentChannel_c;
    lMsg.msgData.setReq.PibAttributeValue = (uint64_t) newChannel;

    errorVal = MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);
    switch (errorVal)
    {
    case gPhyBusy_c:
        return gErrorBusy_c;
        break;

    case gPhyInvalidParameter_c:
        return gErrorOutOfRange_c;
        break;

    case gPhySuccess_c:
        return gErrorNoError_c;
        break;

    default:
        return gErrorOutOfRange_c;
        break;
    }
}

channels_t MLMEGetChannelRequest(void)
{
    macToPlmeMessage_t lMsg;

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gChannelInvalid_c;
    }
#endif

    lMsg.msgType = gPlmeGetReq_c;
    lMsg.ctx_id = maSmacAttributes.phy_context_id;
    lMsg.msgData.getReq.PibAttribute = gPhyPibCurrentChannel_c;

    (void)MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);

    return (channels_t)lMsg.msgData.getReq.PibAttributeValue;
}

smacErrors_t SMACSetShortSrcAddress(address_size_t nwShortAddress)
{
    macToPlmeMessage_t lMsg;

    lMsg.msgType = gPlmeSetReq_c;
    lMsg.ctx_id = maSmacAttributes.phy_context_id;
    lMsg.msgData.setReq.PibAttribute = gPhyPibShortAddress_c;
    lMsg.msgData.setReq.PibAttributeValue = (uint64_t)nwShortAddress;

    phyStatus_t u8PhyRes = MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);
    if(u8PhyRes == gPhyBusy_c || u8PhyRes == gPhyBusyTx_c || u8PhyRes == gPhyBusyRx_c)
    {
        return gErrorBusy_c;
    }

    if(u8PhyRes != gPhySuccess_c)
    {
        return gErrorNoResourcesAvailable_c;
    }

    maSmacAttributes.u16ShortSrcAddress = nwShortAddress;
    return gErrorNoError_c;
}

smacErrors_t SMACSetExtendedSrcAddress(uint64_t nwExtendedAddress)
{
    macToPlmeMessage_t lMsg;

    lMsg.msgType = gPlmeSetReq_c;
    lMsg.ctx_id = maSmacAttributes.phy_context_id;
    lMsg.msgData.setReq.PibAttribute = gPhyPibLongAddress_c;
    lMsg.msgData.setReq.PibAttributeValue = nwExtendedAddress;

    phyStatus_t u8PhyRes = MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);
    if(u8PhyRes == gPhyBusy_c || u8PhyRes == gPhyBusyTx_c || u8PhyRes == gPhyBusyRx_c)
    {
        return gErrorBusy_c;
    }

    if(u8PhyRes != gPhySuccess_c)
    {
        return gErrorNoResourcesAvailable_c;
    }

    maSmacAttributes.u64ExtendedSrcAddress = nwExtendedAddress;
    return gErrorNoError_c;
}

smacErrors_t SMACSetPanID(address_size_t nwShortPanID)
{
    macToPlmeMessage_t lMsg;

    lMsg.msgType = gPlmeSetReq_c;
    lMsg.ctx_id = maSmacAttributes.phy_context_id;
    lMsg.msgData.setReq.PibAttribute = gPhyPibPanId_c;
    lMsg.msgData.setReq.PibAttributeValue = (uint64_t)nwShortPanID;

    phyStatus_t u8PhyRes = MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);
    if(u8PhyRes == gPhyBusy_c || u8PhyRes == gPhyBusyTx_c || u8PhyRes == gPhyBusyRx_c)
    {
        return gErrorBusy_c;
    }

    if(u8PhyRes != gPhySuccess_c)
    {
        return gErrorNoResourcesAvailable_c;
    }

    maSmacAttributes.u16PanID = nwShortPanID;
    return gErrorNoError_c;
}

smacErrors_t MLMEPAOutputAdjust(uint8_t u8PaValue)
{
    AppToAspMessage_t   msg;

    /* To silence IAR/GCC wrongly complaining about unused var */
    NOT_USED(msg);

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif /* TRUE == smacInitializationValidation_d */

    if(mSmacStateIdle_c != maSmacAttributes.smacState)
    {
        return gErrorBusy_c;
    }

    msg.msgType                                = aspMsgTypeSetPowerLevel_c;
    msg.msgData.aspSetPowerLevelReq.powerLevel = u8PaValue;

    if (APP_ASP_SapHandler(&msg, maSmacAttributes.phy_context_id) == gAspSuccess_c)
    {
        return gErrorNoError_c;
    }

    return gErrorOutOfRange_c;
}

uint8_t MLMELinkQuality(void)
{
#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return 0;
    }
#endif

  return maSmacAttributes.smacLastDataRxParams.linkQuality;
}

smacErrors_t MLMEPhySoftReset(void)
{
    macToPlmeMessage_t lMsg;

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif

    lMsg.msgType                      = gPlmeSetTRxStateReq_c;
    lMsg.ctx_id                       = maSmacAttributes.phy_context_id;
    lMsg.msgData.setTRxStateReq.state = gPhyForceTRxOff_c;
    (void)MAC_PLME_SapHandler(&lMsg, maSmacAttributes.phy_context_id);

    OSA_InterruptDisable();
    maSmacAttributes.smacState= mSmacStateIdle_c;
    OSA_InterruptEnable();

    if(maSmacAttributes.gSmacDataMessage != NULL)
    {
        MSG_Free(maSmacAttributes.gSmacDataMessage);
        maSmacAttributes.gSmacDataMessage = NULL;
    }

    if(maSmacAttributes.gSmacMlmeMessage != NULL)
    {
        MSG_Free(maSmacAttributes.gSmacMlmeMessage);
        maSmacAttributes.gSmacMlmeMessage = NULL;
    }

    return gErrorNoError_c;
}

smacErrors_t MLMEScanRequest(channels_t u8ChannelToScan)
{
    smacErrors_t err = gErrorNoError_c;
    phyStatus_t u8PhyRes;

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif

    if(mSmacStateIdle_c != maSmacAttributes.smacState)
    {
        return gErrorBusy_c;
    }

    if(u8ChannelToScan != MLMEGetChannelRequest())
    {
        err = MLMESetChannelRequest(u8ChannelToScan);

        if(err != gErrorNoError_c)
        {
            return err;
        }
    }

    macToPlmeMessage_t* pMsg = (macToPlmeMessage_t*)MSG_Alloc(sizeof(macToPlmeMessage_t));

    pMsg->msgType = gPlmeEdReq_c;
    pMsg->ctx_id  = maSmacAttributes.phy_context_id;
    pMsg->msgData.edReq.startTime = gPhySeqStartAsap_c;

    OSA_InterruptDisable();
    maSmacAttributes.gSmacMlmeMessage = pMsg;
    maSmacAttributes.smacState        = mSmacStateScanningChannels_c;
    OSA_InterruptEnable();

    u8PhyRes = MAC_PLME_SapHandler(pMsg, maSmacAttributes.phy_context_id);
    if(u8PhyRes != gPhySuccess_c)
    {
        OSA_InterruptDisable();
        maSmacAttributes.smacState = mSmacStateIdle_c;
        OSA_InterruptEnable();

        MSG_Free(maSmacAttributes.gSmacMlmeMessage);
        maSmacAttributes.gSmacMlmeMessage = NULL;

        return gErrorBusy_c;
    }

    return gErrorNoError_c;
}

smacErrors_t MLMECcaRequest()
{
    macToPlmeMessage_t* pMsg;

#if(TRUE == smacInitializationValidation_d)
    if(FALSE == mSmacInitialized)
    {
        return gErrorNoValidCondition_c;
    }
#endif

    if(mSmacStateIdle_c != maSmacAttributes.smacState)
    {
        return gErrorBusy_c;
    }

    pMsg = (macToPlmeMessage_t*)MSG_Alloc(sizeof(macToPlmeMessage_t));

    pMsg->msgType = gPlmeCcaReq_c;
    pMsg->ctx_id = maSmacAttributes.phy_context_id;
    pMsg->msgData.ccaReq.ccaType = gPhyCCAMode1_c;
    pMsg->msgData.ccaReq.contCcaMode = gPhyContCcaDisabled;

    OSA_InterruptDisable();
    maSmacAttributes.gSmacMlmeMessage = pMsg;
    maSmacAttributes.smacState = mSmacStatePerformingCca_c;
    OSA_InterruptEnable();

    if (MAC_PLME_SapHandler(pMsg, maSmacAttributes.phy_context_id) != gPhySuccess_c)
    {
        OSA_InterruptDisable();
        maSmacAttributes.smacState = mSmacStateIdle_c;
        OSA_InterruptEnable();

        MSG_Free(maSmacAttributes.gSmacMlmeMessage);
        maSmacAttributes.gSmacMlmeMessage = NULL;

        return gErrorBusy_c;
    }

    return gErrorNoError_c;
}

void SMACSetTxAutoAck(bool_t enable)
{
    maSmacAttributes.txConfigurator.autoAck = enable;
}

void SMACSetTxEnhAck(bool_t enable)
{
    maSmacAttributes.txConfigurator.enhAck = enable;
}

void SMACFillHeader(smacHeader_t* pSmacHeader, address_size_t destAddr)
{
    pSmacHeader->frameControl = gSmacDefaultFrameCtrl_c;

#if !gEnhAckMode8
    pSmacHeader->panId        = maSmacAttributes.u16PanID;
#endif
    pSmacHeader->seqNo        = gSmacDefaultSeqNo_c;
    pSmacHeader->srcAddr      = maSmacAttributes.u16ShortSrcAddress;
    pSmacHeader->destAddr     = destAddr;
}
