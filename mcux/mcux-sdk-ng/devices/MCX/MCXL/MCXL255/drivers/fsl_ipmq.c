/*
 * Copyright 2024 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_ipmq.h"
#include "fsl_mu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.ipmq"
#endif

/*!
 * @brief The structure represents the context of the IPMQ communication module,
 * storing various states and configuration parameters for managing message transmission and reception.
 *
 */
typedef struct _ipmq_context
{
    uint8_t txIdx;                   /*!< The transmit index used to manage message queueing or sending sequence. */
    uint8_t rxIdx;                   /*!< receive index used to manage incoming message processing. */
    bool initialized;                /*!< Indicate if the IPMQ_Init() function has been successfully invoked. */
    bool receiveByPolling;           /*!< Indicate if use the polling method to receive message. */
    bool errorIntEnabled;            /*!< Indicate if error interrupt is enabled. */
    bool newResponseReceived;        /*!< The flag of new message arrived, set as true in MU ISR. */
    ipmq_msg_opcode_t currentOpcode; /*!< Current used opcode of message. */
    ipmq_interrupt_cb_t *ptrCb;      /*!< Pointer to callback functions. */
} ipmq_context_t;

/*!
 * @brief Formated message header.
 */
typedef struct _ipmq_msg_header
{
    uint32_t sync : 8U;        /*!< Use for verifying message alignment. */
    uint32_t payloadSize : 8U; /*!< Size of message payload. */
    uint32_t userData : 6U;    /*!< User data send with the message, return with the ACK/NACK feedback, can be used by
                               application to match feedback to the message. */
    uint32_t type : 2U;        /*!< Type of message, in type of @ref ipmq_msg_type_t. */
    uint32_t opcode : 8U;      /*!< Message opcode, in type of @ref ipmq_msg_opcode_t. */
} ipmq_msg_header_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void IPMQ_SendSingleMsg(uint32_t msg);
static uint32_t IPMQ_ReceiveSingleMsg(void);
static ipmq_msg_header_t IPMQ_ComposeMessageHeader(ipmq_msg_opcode_t opcode, uint8_t userData, uint8_t size);
static void IPMQ_CommonIRQHandler(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* IPMQ interrupt callback structure. */
ipmq_interrupt_cb_t g_ipmCabllbacks;

static volatile ipmq_context_t ipmqCtx;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Compose an message header.
 */
static ipmq_msg_header_t IPMQ_ComposeMessageHeader(ipmq_msg_opcode_t opcode, uint8_t userData, uint8_t size)
{
    /* User data take 6 bits. */
    assert(userData < 64U);

    ipmq_msg_header_t header;

    header.sync        = IPMQ_MSG_HEADER_SYNC_CODE;
    header.payloadSize = size;
    header.userData    = userData;
    header.type        = (uint32_t)kIPMQ_MsgType_Message;
    header.opcode      = opcode;

    return header;
}

/*!
 * @brief Command function to handle MU general purpose interrupt.
 */
static void IPMQ_CommonIRQHandler(void)
{
    uint32_t flags = 0UL;

    flags = MU_GetGeneralPurposeStatusFlags(MUA);
    MU_ClearGeneralPurposeStatusFlags(MUA, flags);

    if ((flags & kMU_GeneralPurposeInterrupt1) != 0UL)
    {
        /* AON report an error. */
        ipmqCtx.ptrCb->error();
        return;
    }

    if ((flags & kMU_GeneralPurposeInterrupt0) != 0UL)
    {
        /* AON send response to MAIN domain. */
        ipmqCtx.newResponseReceived = true;
    }
}

/*!
 * @brief Send a message over the Message Unit (MU) channel in a queue-based fashion.
 *
 */
static void IPMQ_SendSingleMsg(uint32_t msg)
{
    MU_SendMsg(MUA, ipmqCtx.txIdx++, msg);

    if (ipmqCtx.txIdx == IPMQ_MSG_PHY_CHANNEL_COUNT)
    {
        ipmqCtx.txIdx = 0U;
    }
}

/*!
 * @brief Receive a message over the Message Unit (MU) channel in a queue-based fashion.
 */
static uint32_t IPMQ_ReceiveSingleMsg(void)
{
    uint32_t u32Tmp = 0UL;

    u32Tmp = MU_ReceiveMsg(MUA, ipmqCtx.rxIdx++);

    if (ipmqCtx.rxIdx == IPMQ_MSG_PHY_CHANNEL_COUNT)
    {
        ipmqCtx.rxIdx = 0U;
    }

    return u32Tmp;
}

/*!
 * @brief Initialize inter-processor message queue.
 *
 * @note Once initalized, please do not invoke this API repeatedly.
 * @note If \b recoveryQueueBeforeInit is set as \b true, this function execution might involve a considerable duration
 * due to the presence of an inlined delay function.
 *
 * @param[in] ptrConfig Pointer to @ref ipmq_config_t, used to set basic configuration of Message queue.
 *
 */
void IPMQ_Init(const ipmq_config_t *ptrConfig)
{
    assert(ipmqCtx.initialized != true);

    if (ptrConfig->recoveryQueueBeforeInit)
    {
        IPMQ_RecoveryQueue(ptrConfig->coreClock_Hz);
    }

    MU_Init(MUA);

    ipmqCtx.txIdx            = 0U;
    ipmqCtx.rxIdx            = 0U;
    ipmqCtx.receiveByPolling = ptrConfig->receiveByPolling;
    ipmqCtx.errorIntEnabled  = ptrConfig->enableErrorInterrupt;

    if (ptrConfig->receiveByPolling == false)
    {
        /* Enable message receive interrupt. */
        MU_EnableGeneralPurposeInterrupts(MUA, kMU_GeneralPurposeInterrupt0);
    }

    if (ptrConfig->enableErrorInterrupt)
    {
        /* Enable Error  */
        MU_EnableGeneralPurposeInterrupts(MUA, kMU_GeneralPurposeInterrupt1);
    }

    ipmqCtx.initialized         = true;
    ipmqCtx.newResponseReceived = false;
    ipmqCtx.ptrCb               = ptrConfig->ptrCb;

    if ((ptrConfig->receiveByPolling == false) || (ptrConfig->enableErrorInterrupt))
    {
        /* Enable NVIC MU interrupt. */
        EnableIRQ(MU_A_INT_IRQn);
    }
}

/*!
 * @brief De-initialize inter-processor message queue.
 *
 * @note This function should be invoked only after the IPMQ has been successfully initialized.
 */
void IPMQ_Deinit()
{
    assert(ipmqCtx.initialized);

    MU_Deinit(MUA);
    DisableIRQ(MU_A_INT_IRQn);

    ipmqCtx.initialized = false;
    ipmqCtx.txIdx       = 0U;
    ipmqCtx.rxIdx       = 0U;
    ipmqCtx.ptrCb       = NULL;
}

/*!
 * @brief Establish synchronization between the CM33 and AON domains through the recovery message queue mechanism.
 *
 * @details Used when an executable file is loaded directly into RAM,in which case the RAM executable resets local
 * pointers while the AON ROM remains unaware
 *
 * @note Please note that this function execution might involve a considerable duration due to the presence of
 * an inlined delay function.
 *
 * @param[in] coreClock_Hz The core clock frequency to delay servial micro seconds.
 */
void IPMQ_RecoveryQueue(uint32_t coreClock_Hz)
{
    union
    {
        uint32_t u32Msg;
        ipmq_msg_header_t formatMsg;
    } deInitHeader;

    union
    {
        uint32_t u32Msg;
        ipmq_msg_header_t formatMsg;
    } pingHeader;
    uint8_t i      = 0U;
    uint32_t flags = 0UL;

    deInitHeader.formatMsg = IPMQ_ComposeMessageHeader(kIPMQ_MsgOpcode_ApiDeinit, 0U, 0U);
    pingHeader.formatMsg   = IPMQ_ComposeMessageHeader(kIPMQ_MsgOpcode_Ping, 0U, 0U);

    MU_DisableGeneralPurposeInterrupts(MUA, kIPMQ_MsgGpi_NewMsg);
    DisableIRQ(MU_A_INT_IRQn);

    for (i = 0U; i < IPMQ_MSG_PHY_CHANNEL_COUNT; i++)
    {
        MU_SendMsgNonBlocking(MUA, i, deInitHeader.u32Msg);
        /* Delay 100000 us. */
        SDK_DelayAtLeastUs(100000UL, coreClock_Hz);
    }

    MU_TriggerGeneralPurposeInterrupts(MUA, kIPMQ_MsgGpi_NewMsg);
    /* delay 100000 us to give time to the AOn to process, now AON queue point to address 0. */
    SDK_DelayAtLeastUs(100000UL, coreClock_Hz);

    for (i = 0U; i < IPMQ_MSG_PHY_CHANNEL_COUNT; i++)
    {
        (void)MU_ReceiveMsgNonBlocking(MUA, i);
        SDK_DelayAtLeastUs(100000UL, coreClock_Hz);
    }

    for (i = 0U; i < IPMQ_MSG_PHY_CHANNEL_COUNT; i++)
    {
        MU_SendMsgNonBlocking(MUA, i, pingHeader.u32Msg);
        /* Delay 100000 us. */
        SDK_DelayAtLeastUs(100000UL, coreClock_Hz);
    }

    SDK_DelayAtLeastUs(100000UL, coreClock_Hz);

    for (i = 0U; i < IPMQ_MSG_PHY_CHANNEL_COUNT; i++)
    {
        MU_TriggerGeneralPurposeInterrupts(MUA, kIPMQ_MsgGpi_NewMsg);
        SDK_DelayAtLeastUs(100000UL, coreClock_Hz);
    }

    for (i = 0U; i < IPMQ_MSG_PHY_CHANNEL_COUNT; i++)
    {
        (void)MU_ReceiveMsgNonBlocking(MUA, i);
        SDK_DelayAtLeastUs(100000UL, coreClock_Hz);
    }

    ipmqCtx.txIdx = 0U;
    ipmqCtx.rxIdx = 0U;

    flags = MU_GetGeneralPurposeStatusFlags(MUA);
    MU_ClearGeneralPurposeStatusFlags(MUA, flags);
}

/*!
 * @brief Enable message general purpose interrupt.
 *
 * @param[in] mask The mask of interrupts to enable, should be the OR'ed
 *          value of @ref ipmq_msg_general_purpose_interrupt_t.
 */
void IPMQ_EnableMsgGeneralPurposeInterrupts(uint32_t mask)
{
    MU_EnableGeneralPurposeInterrupts(MUA, mask);
}

/*!
 * @brief Disable message general purpose interrupt.
 *
 * @param[in] mask The mask of interrupts to disable, should be the OR'ed
 *          value of @ref ipmq_msg_general_purpose_interrupt_t.
 */
void IPMQ_DisableMsgGeneralPurposeInterrupts(uint32_t mask)
{
    MU_DisableGeneralPurposeInterrupts(MUA, mask);
}

/*!
 * @brief Send message to AON with payload from single memory location.
 *
 * @param[in] opcode Message opcode, please refer to @ref ipmq_msg_opcode_t.
 * @param[in] userData User data send with the message, return with the ACK/NACK feedback, can be used by application
 *                       to match feedback to the message.
 * @param[in] payloadSize Size of payload to send.
 * @param[in] ptrPayload Pointer to the buffer of payload to send.
 */
void IPMQ_SendMessage(ipmq_msg_opcode_t opcode, uint8_t userData, uint8_t payloadSize, uint32_t *ptrPayload)
{
    assert(ipmqCtx.initialized);

    union
    {
        uint32_t u32MsgHeader;
        ipmq_msg_header_t formatMsgHeader;
    } msgHeader;

    msgHeader.formatMsgHeader = IPMQ_ComposeMessageHeader(opcode, userData, payloadSize);

    ipmqCtx.currentOpcode = opcode;
    /* blocks until all TX registers are empty. */
    while ((MU_GetStatusFlags(MUA) & kMU_TxEmptyPendingFlag) != 0UL)
    {
    }

    /* block sending msg header firstly and request "new message sent" interrupt to inform AON message arrived. */
    IPMQ_SendSingleMsg(msgHeader.u32MsgHeader);
    MU_TriggerGeneralPurposeInterrupts(MUA, kIPMQ_MsgGpi_NewMsg);

    /* block sending left payload one by one */
    if ((payloadSize != 0U) && (ptrPayload != NULL))
    {
        for (uint8_t i = 0U; i < payloadSize; i++)
        {
            IPMQ_SendSingleMsg(ptrPayload[i]);
        }
    }
}

/*!
 * @brief Send message to AON with two different payload from different memory location, for example the first payload
 * may from RAM, and the second payload may from flash.
 *
 * @param[in] opcode Message opcode, please refer to @ref ipmq_msg_opcode_t.
 * @param[in] userData User data send with the message, return with the ACK/NACK feedback, can be used by application
 *                       to match feedback to the message.
 * @param[in] payload1Size Size of first payload to send.
 * @param[in] ptr1stPayload Pointer to the buffer of the first payload to send.
 * @param[in] payload2Size Size of second payload to send.
 * @param[in] ptr2ndPayload Pointer to the buffer of the second payload to send.
 */
void IPMQ_SendMessage2Payload(ipmq_msg_opcode_t opcode,
                              uint8_t userData,
                              uint8_t payload1Size,
                              uint32_t *ptr1stPayload,
                              uint8_t payload2Size,
                              uint32_t *ptr2ndPayload)
{
    assert(ipmqCtx.initialized);

    union
    {
        uint32_t u32MsgHeader;
        ipmq_msg_header_t formatMsgHeader;
    } msgHeader;

    /* @todo Need to check if size if correct. */
    msgHeader.formatMsgHeader = IPMQ_ComposeMessageHeader(opcode, userData, payload1Size);

    ipmqCtx.currentOpcode = opcode;

    /* blocks until all TX registers are empty. */
    while ((MU_GetStatusFlags(MUA) & kMU_TxEmptyPendingFlag) != 0UL)
    {
    }

    /* block sending msg header firstly and request "new message sent" interrupt to inform AON message arrived. */
    IPMQ_SendSingleMsg(msgHeader.u32MsgHeader);
    MU_TriggerGeneralPurposeInterrupts(MUA, kIPMQ_MsgGpi_NewMsg);

    /* send first payload from input memory location. */
    if ((payload1Size != 0U) && (ptr1stPayload != NULL))
    {
        for (uint8_t i = 0U; i < payload1Size; i++)
        {
            IPMQ_SendSingleMsg(ptr1stPayload[i]);
        }
    }

    /* send second payload from input memory location. */
    if ((payload2Size != 0U) && (ptr2ndPayload != NULL))
    {
        for (uint8_t i = 0U; i < payload2Size; i++)
        {
            IPMQ_SendSingleMsg(ptr2ndPayload[i]);
        }
    }
}

/*!
 * @brief Block receiving message until error detected or message finished.
 *
 * @note In case the return value of this function is anything other than #kIPMQ_Ret_ReceiveAck,
 * it is recommended for the user to examine the sent message according to the reported error and
 * resend the message accordingly
 *
 * @param[in] opcode Message opcode, please refer to @ref ipmq_msg_opcode_t.
 * @param[in] userData User data send with the message, return with the ACK/NACK feedback, can be used by application
 *                       to match feedback to the message.
 * @param[out] ptrResponsePayload Pointer to the buffer to store response message's payload.
 * @param[out] ptrResponsePayloadSize Pointer to the variable to store the size of response message's payload.
 *
 * @retval kIPMQ_Ret_ReceiveUnkownMsg  An unknown message was received
 * @retval kIPMQ_Ret_ReceiveOpcodeMismatch The received message does not match the expected message header
 * @retval kIPMQ_Ret_ReceiveUserDataMismatch The received user data does not match the input value.
 * @retval kIPMQ_Ret_ReceiveAck The message was received successfully and an acknowledgment (ACK) is returned
 * @retval kIPMQ_Ret_ReceiveNACK The message was received but there was a failure,
 *          a negative acknowledgment (NACK) is returned, and the NACK reason may contain in payload.
 */
ipmq_ret_value_t IPMQ_ReceiveMessage(ipmq_msg_opcode_t opcode,
                                     uint8_t userData,
                                     uint32_t *ptrResponsePayload,
                                     uint8_t *ptrResponsePayloadSize)
{
    assert(ipmqCtx.initialized);

    union
    {
        uint32_t u32Header;
        ipmq_msg_header_t formatHeader;
    } revHeader;
    uint8_t payLoadSize  = 0U;
    ipmq_ret_value_t ret = kIPMQ_Ret_Error;

    if (ipmqCtx.receiveByPolling == true)
    {
        while ((MU_GetGeneralPurposeStatusFlags(MUA) & kMU_GeneralPurposeInterrupt0) == 0UL)
        {
        }
    }
    else
    {
        while (ipmqCtx.newResponseReceived != true)
        {
        }
        ipmqCtx.newResponseReceived = false;
    }

    revHeader.u32Header = IPMQ_ReceiveSingleMsg();
    payLoadSize         = revHeader.formatHeader.payloadSize;

    if ((revHeader.formatHeader.sync != IPMQ_MSG_HEADER_SYNC_CODE) ||
        (revHeader.formatHeader.type == kIPMQ_MsgType_Message))
    {
        ret = kIPMQ_Ret_ReceiveUnkownMsg;
    }

    if (revHeader.formatHeader.opcode != opcode)
    {
        /* opcode mismatch. */
        ret = kIPMQ_Ret_ReceiveOpcodeMismatch;
    }

    if (revHeader.formatHeader.userData != userData)
    {
        /* userdata mismatch. */
        ret = kIPMQ_Ret_ReceiveUserDataMismatch;
    }

    if ((ptrResponsePayload != NULL) && (ptrResponsePayloadSize != NULL))
    {
        /* store response size, and contents. */
        *ptrResponsePayloadSize = payLoadSize;
        if (payLoadSize == 0U)
        {
            *ptrResponsePayload = IPMQ_USELESS_VALUE;
        }
        else
        {
            for (uint8_t i = 0U; i < payLoadSize; i++)
            {
                ptrResponsePayload[i] = IPMQ_ReceiveSingleMsg();
            }
        }
    }

    if (revHeader.formatHeader.type == kIPMQ_MsgType_ACK)
    {
        ret = kIPMQ_Ret_ReceiveAck;
    }
    else if (revHeader.formatHeader.type == kIPMQ_MsgType_NACK)
    {
        ret = kIPMQ_Ret_ReceiveNACK;
    }
    else
    {
        /* Reserved for future use. */
    }

    return ret;
}

void MU_A_INT_DriverIRQHandler(void);
void MU_A_INT_DriverIRQHandler(void)
{
    IPMQ_CommonIRQHandler();
}
