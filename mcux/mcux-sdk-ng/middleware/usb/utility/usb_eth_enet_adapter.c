/**
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_enet.h"
#include "fsl_phy.h"
#include "usb_eth_adapter.h"
#include "usb_misc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define ENET_RXBD_NUM (4)
#define ENET_TXBD_NUM (4)
#define ENET_RXBUFF_SIZE (ENET_FRAME_MAX_FRAMELEN)
#define ENET_TXBUFF_SIZE (ENET_FRAME_MAX_FRAMELEN)

#ifndef APP_ENET_BUFF_ALIGNMENT
#define APP_ENET_BUFF_ALIGNMENT (ENET_BUFF_ALIGNMENT)
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern ENET_Type *BOARD_GetExampleEnetBase(void);
extern const phy_operations_t *BOARD_GetPhyOps(void);
extern void *BOARD_GetPhyResource(void);
extern uint32_t BOARD_GetPhySysClock(void);
extern uint8_t BOARD_GetPhyAddress(void);

void ETH_Callback(ENET_Type *base, enet_handle_t *handle,
#if FSL_FEATURE_ENET_QUEUE > 1
                  uint32_t ringId,
#endif /* FSL_FEATURE_ENET_QUEUE > 1 */
                  enet_event_t event, enet_frame_info_t *frameInfo, void *userData);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief The MAC address for ENET device. */
static uint8_t macAddr[6] = ETH_ADAPTER_MAC_ADDRESS;

/*! @brief MAC transfer. */
static enet_handle_t enetHandle;

/*! @brief PHY status. */
static phy_handle_t phyHandle;

/*! @brief Buffer descriptors should be in non-cacheable region and should be align to "ENET_BUFF_ALIGNMENT". */
AT_NONCACHEABLE_SECTION_ALIGN(static enet_rx_bd_struct_t rxBuffDescrip[ENET_RXBD_NUM], ENET_BUFF_ALIGNMENT);
AT_NONCACHEABLE_SECTION_ALIGN(static enet_tx_bd_struct_t txBuffDescrip[ENET_TXBD_NUM], ENET_BUFF_ALIGNMENT);

/*! @brief The data buffers can be in cacheable region or in non-cacheable region.
 * If use cacheable region, the alignment size should be the maximum size of "CACHE LINE SIZE" and "ENET_BUFF_ALIGNMENT"
 * If use non-cache region, the alignment size is the "ENET_BUFF_ALIGNMENT".
 */
SDK_ALIGN(static uint8_t rxDataBuff[ENET_RXBD_NUM][SDK_SIZEALIGN(ENET_RXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT)], APP_ENET_BUFF_ALIGNMENT);
SDK_ALIGN(static uint8_t txDataBuff[ENET_TXBD_NUM][SDK_SIZEALIGN(ENET_TXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT)], APP_ENET_BUFF_ALIGNMENT);

USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
static uint8_t ethFrameTxBuffer[ETH_ADAPTER_PHY_FRAME_TX_BUFFER_LENGTH][ENET_FRAME_MAX_FRAMELEN];
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
static uint8_t ethFrameRxBuffer[ETH_ADAPTER_PHY_RRAME_RX_BUFFER_LENGTH][ENET_FRAME_MAX_FRAMELEN];

eth_adapter_handle_t ethAdapterHandle;

/*******************************************************************************
 * Code
 ******************************************************************************/
static eth_adapter_err_t ETH_ADAPTER_HW_Init(void)
{
    enet_config_t config;
    phy_config_t phyConfig = {0};

    /* Prepare the buffer configuration. */
    enet_buffer_config_t buffConfig[] = {{
        ENET_RXBD_NUM,
        ENET_TXBD_NUM,
        SDK_SIZEALIGN(ENET_RXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT),
        SDK_SIZEALIGN(ENET_TXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT),
        &rxBuffDescrip[0],
        &txBuffDescrip[0],
        &rxDataBuff[0][0],
        &txDataBuff[0][0],
        true,
        true,
        NULL,
    }};

    /* Get default configuration. */
    /*
     * config.miiMode = kENET_RmiiMode;
     * config.miiSpeed = kENET_MiiSpeed100M;
     * config.miiDuplex = kENET_MiiFullDuplex;
     * config.rxMaxFrameLen = ENET_FRAME_MAX_FRAMELEN;
     */
    ENET_GetDefaultConfig(&config);

    /* The miiMode should be set according to the different PHY interfaces. */
#ifdef EXAMPLE_PHY_INTERFACE_RGMII
    config.miiMode = kENET_RgmiiMode;
#else
    config.miiMode = kENET_RmiiMode;
#endif
    config.miiSpeed = kENET_MiiSpeed100M;
    config.miiDuplex = kENET_MiiFullDuplex;

    /* Mount callback to ENET for getting interrupt event. */
    config.interrupt = ENET_TX_INTERRUPT | ENET_RX_INTERRUPT | ENET_ERR_INTERRUPT;
    config.callback = ETH_Callback;

    phyConfig.phyAddr = BOARD_GetPhyAddress();
    phyConfig.autoNeg = false;
    phyConfig.ops = BOARD_GetPhyOps();
    phyConfig.resource = BOARD_GetPhyResource();

    /* Initialize PHY and wait auto-negotiation over. */
    while (PHY_Init(&phyHandle, &phyConfig) != kStatus_Success)
    {
        (void)usb_echo("PHY_Init failed.\r\n");

        return ETH_ADAPTER_ERROR;
    }

    /* set PHY link speed/duplex. */
    PHY_SetLinkSpeedDuplex(&phyHandle, (phy_speed_t)config.miiSpeed, (phy_duplex_t)config.miiDuplex);

    /* Wait a moment for PHY status to be stable. */
    SDK_DelayAtLeastUs(100000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

#ifdef USB_STACK_FREERTOS
    ENET_Type *const enetBases[] = ENET_BASE_PTRS;
    const IRQn_Type enetTxIrqId[] = ENET_Transmit_IRQS;
    const IRQn_Type enetRxIrqId[] = ENET_Receive_IRQS;
    const IRQn_Type enetErrIrqId[] = ENET_Error_IRQS;

    for (uint32_t instance = 0; instance < ARRAY_SIZE(enetBases); instance++)
    {
        if (enetBases[instance] == BOARD_GetExampleEnetBase())
        {
            NVIC_SetPriority(enetTxIrqId[instance], ENET_INTERRUPT_PRIORITY);
            NVIC_SetPriority(enetRxIrqId[instance], ENET_INTERRUPT_PRIORITY);
            NVIC_SetPriority(enetErrIrqId[instance], ENET_INTERRUPT_PRIORITY);
        }
    }
#endif

    /* Init the ENET. */
    if (ENET_Init(BOARD_GetExampleEnetBase(), &enetHandle, &config, &buffConfig[0], &macAddr[0], BOARD_GetPhySysClock()) != kStatus_Success)
    {
        (void)usb_echo("ENET_Init failed.\r\n");

        return ETH_ADAPTER_ERROR;
    }

    ENET_ActiveRead(BOARD_GetExampleEnetBase());

    return ETH_ADAPTER_OK;
}

eth_adapter_err_t ETH_ADAPTER_Init(void)
{
    if (ETH_ADAPTER_FrameQueueReset(&ethAdapterHandle.txFrameQueue, (uint8_t **)ethFrameTxBuffer, ETH_ADAPTER_PHY_FRAME_TX_BUFFER_LENGTH, ENET_FRAME_MAX_FRAMELEN) != ETH_ADAPTER_OK)
    {
        return ETH_ADAPTER_ERROR;
    }

    if (ETH_ADAPTER_FrameQueueReset(&ethAdapterHandle.rxFrameQueue, (uint8_t **)ethFrameRxBuffer, ETH_ADAPTER_PHY_RRAME_RX_BUFFER_LENGTH, ENET_FRAME_MAX_FRAMELEN) != ETH_ADAPTER_OK)
    {
        return ETH_ADAPTER_ERROR;
    }

    ethAdapterHandle.rxEvent = false;
    ethAdapterHandle.txEvent = false;

    return ETH_ADAPTER_HW_Init();
}

eth_adapter_err_t ETH_ADAPTER_GetMacAddress(uint8_t *address)
{
    ENET_GetMacAddr(BOARD_GetExampleEnetBase(), address);

    for (uint32_t idx = 0U; idx < 6; idx++)
    {
        if (address[idx] != macAddr[idx])
        {
            return ETH_ADAPTER_ERROR;
        }
    }

    return ETH_ADAPTER_OK;
}

eth_adapter_err_t ETH_ADAPTER_GetLinkStatus(bool *status)
{
    if (PHY_GetLinkStatus(&phyHandle, status) == kStatus_Success)
    {
        return ETH_ADAPTER_OK;
    }

    return ETH_ADAPTER_ERROR;
}

eth_adapter_err_t ETH_ADAPTER_GetLinkSpeed(uint32_t *speed)
{
    phy_speed_t spd;

    if (PHY_GetLinkSpeedDuplex(&phyHandle, &spd, NULL) != kStatus_Success)
    {
        return ETH_ADAPTER_ERROR;
    }

    switch (spd)
    {
        case kPHY_Speed10M:
            *speed = 10U * 1e6;
            break;

        case kPHY_Speed100M:
            *speed = 100U * 1e6;
            break;

        case kPHY_Speed1000M:
            *speed = 1000U * 1e6;
            break;

        default:
            return ETH_ADAPTER_ERROR;
    }

    return ETH_ADAPTER_OK;
}

eth_adapter_err_t ETH_ADAPTER_SendFrame(eth_adapter_frame_buf_t *buffer)
{
    status_t status = ENET_SendFrame(BOARD_GetExampleEnetBase(), &enetHandle, buffer->payload, buffer->len, 0, false, NULL);

    if (status != kStatus_Success)
    {
        if (status == kStatus_ENET_TxFrameBusy)
        {
            return ETH_ADAPTER_BUSY;
        }

        return ETH_ADAPTER_ERROR;
    }

    return ETH_ADAPTER_OK;
}

eth_adapter_err_t ETH_ADAPTER_RecvFrame(eth_adapter_frame_buf_t *buffer)
{
    uint32_t length = 0U;

    if (!buffer)
    {
        (void)ENET_ReadFrame(ENET, &enetHandle, NULL, 0, 0, NULL);

        return ETH_ADAPTER_OK;
    }

    buffer->len = 0U;

    /* Get the received frame size firstly. */
    status_t status = ENET_GetRxFrameSize(&enetHandle, &length, 0);

    if (length != 0)
    {
        /* Allocate memory here with the size of "length" */
        uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t) * length);
        if (!data)
        {
            (void)ENET_ReadFrame(ENET, &enetHandle, NULL, 0, 0, NULL);

            /* Add the console warning log. */

            return ETH_ADAPTER_ERROR;
        }
        else
        {
            eth_adapter_frame_buf_t temp_buf;
            temp_buf.payload = data;
            temp_buf.len = length;

            if (ENET_ReadFrame(ENET, &enetHandle, temp_buf.payload, temp_buf.len, 0, NULL) != kStatus_Success)
            {
                free(data);

                return ETH_ADAPTER_ERROR;
            }

            if (ETH_ADAPTER_FrameQueuePush(&ethAdapterHandle.rxFrameQueue, &temp_buf) != ETH_ADAPTER_OK)
            {
                free(data);

                return ETH_ADAPTER_ERROR;
            }

            free(data);

            eth_adapter_frame_buf_t *p = &ethAdapterHandle.rxFrameQueue.queue[(ethAdapterHandle.rxFrameQueue.idx + ethAdapterHandle.rxFrameQueue.valid_len - 1) % ethAdapterHandle.rxFrameQueue.total_len];

            buffer->payload = p->payload;
            buffer->len = p->len;

            /* Call stack input API to deliver the data to stack */
        }
    }
    else if (status == kStatus_ENET_RxFrameError)
    {
        /* Update the received buffer when a error frame is received. */
        (void)ENET_ReadFrame(ENET, &enetHandle, NULL, 0, 0, NULL);

        return ETH_ADAPTER_ERROR;
    }

    return ETH_ADAPTER_OK;
}

eth_adapter_err_t ETH_ADAPTER_SendFrameQueue(void)
{
    eth_adapter_err_t status = ETH_ADAPTER_OK;

    while (ethAdapterHandle.txFrameQueue.valid_len)
    {
        status = ETH_ADAPTER_SendFrame(&ethAdapterHandle.txFrameQueue.queue[ethAdapterHandle.txFrameQueue.idx]);
        if (status != ETH_ADAPTER_OK)
        {
            if (status == ETH_ADAPTER_BUSY)
            {
                break;
            }

            return status;
        }
        else
        {
            if (ETH_ADAPTER_FrameQueuePop(&ethAdapterHandle.txFrameQueue, NULL) != ETH_ADAPTER_OK)
            {
                status = ETH_ADAPTER_ERROR;
                break;
            }
        }
    }

    return status;
}

eth_adapter_err_t ETH_ADAPTER_RecvFrameQueue(void)
{
    eth_adapter_frame_buf_t data;

    while (ethAdapterHandle.rxFrameQueue.valid_len < ethAdapterHandle.rxFrameQueue.total_len)
    {
        if (ETH_ADAPTER_RecvFrame(&data) != ETH_ADAPTER_OK)
        {
            return ETH_ADAPTER_ERROR;
        }
        else
        {
            if (!data.len)
            {
                break;
            }
        }
    }

    return ETH_ADAPTER_OK;
}

eth_adapter_err_t ETH_ADAPTER_IdentifyDstFrameType(eth_adapter_frame_buf_t *buffer, eth_adapter_dst_frame_type_t *type)
{
    if (!type)
    {
        return ETH_ADAPTER_INVALID;
    }

    bool isBoardcast = true;
    for (uint32_t cnt = 0U; cnt < 6U; cnt++)
    {
        if (buffer->payload[cnt] != 0xFFU)
        {
            isBoardcast = false;
            break;
        }
    }
    if (isBoardcast)
    {
        *type = ETH_ADAPTER_DST_FRAME_BOARDCAST;
        return ETH_ADAPTER_OK;
    }

    bool isUnicast = true;
    if (buffer->payload[0] & 0x01)
    {
        isUnicast = false;
    }
    if (isUnicast)
    {
        *type = ETH_ADAPTER_DST_FRAME_UNICAST;
        return ETH_ADAPTER_OK;
    }

    bool isMulticast = true;
    if (!(buffer->payload[0] & 0x01))
    {
        isMulticast = false;
    }
    if (isMulticast)
    {
        *type = ETH_ADAPTER_DST_FRAME_MULTICAST;
        return ETH_ADAPTER_OK;
    }

    return ETH_ADAPTER_ERROR;
}

void ETH_Callback(ENET_Type *base, enet_handle_t *handle,
#if FSL_FEATURE_ENET_QUEUE > 1
                  uint32_t ringId,
#endif /* FSL_FEATURE_ENET_QUEUE > 1 */
                  enet_event_t event, enet_frame_info_t *frameInfo, void *userData)
{
    switch (event)
    {
        case kENET_TxEvent:
            ethAdapterHandle.txEvent = true;
            break;

        case kENET_RxEvent:
            ethAdapterHandle.rxEvent = true;
            break;

        case kENET_ErrEvent:
            ethAdapterHandle.errEvent = true;
            break;

        default:
            break;
    }
}
