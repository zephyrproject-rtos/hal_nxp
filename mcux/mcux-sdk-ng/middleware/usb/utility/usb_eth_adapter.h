/**
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __USB_ETH_ADAPTER_H__
#define __USB_ETH_ADAPTER_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* 54-27-8D is assigned by IEEE, and 45-54-48 is ANSCII code of string 'ETH'. */
#define ETH_ADAPTER_MAC_ADDRESS {0x54, 0x27, 0x8d, 0x45, 0x54, 0x48}

#define ETH_ADAPTER_PHY_FRAME_TX_BUFFER_LENGTH (8)
#define ETH_ADAPTER_PHY_RRAME_RX_BUFFER_LENGTH (8)

#ifdef USB_STACK_FREERTOS
#if defined(__GIC_PRIO_BITS)
#define ENET_INTERRUPT_PRIORITY (25U)
#elif defined(__NVIC_PRIO_BITS) && (__NVIC_PRIO_BITS >= 3)
#define ENET_INTERRUPT_PRIORITY (6U)
#else
#define ENET_INTERRUPT_PRIORITY (3U)
#endif
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
typedef enum _eth_adapter_err_enum
{
    ETH_ADAPTER_OK,
    ETH_ADAPTER_ERROR,
    ETH_ADAPTER_INVALID,
    ETH_ADAPTER_BUSY,
} eth_adapter_err_t;

typedef enum _eth_adapter_dst_frame_type_struct
{
    ETH_ADAPTER_DST_FRAME_UNICAST,
    ETH_ADAPTER_DST_FRAME_MULTICAST,
    ETH_ADAPTER_DST_FRAME_BOARDCAST,
} eth_adapter_dst_frame_type_t;

typedef struct _eth_adapter_frame_buf_struct
{
    uint8_t *payload;
    uint32_t len;
} eth_adapter_frame_buf_t;

typedef struct _eth_adapter_frame_queue_struct
{
    uint32_t idx;
    uint32_t total_len;
    uint32_t valid_len;
    eth_adapter_frame_buf_t *queue;
} eth_adapter_frame_queue_t;

typedef struct _eth_adapter_struct
{
    eth_adapter_frame_queue_t txFrameQueue;
    eth_adapter_frame_queue_t rxFrameQueue;
    bool txEvent;
    bool rxEvent;
    bool errEvent;
} eth_adapter_handle_t;

extern eth_adapter_handle_t ethAdapterHandle;

static inline eth_adapter_err_t ETH_ADAPTER_FrameQueueReset(eth_adapter_frame_queue_t *ethFrameQueue, uint8_t **buffer, uint32_t length, uint32_t bufferUnitLength)
{
    if (!ethFrameQueue || !buffer)
    {
        return ETH_ADAPTER_INVALID;
    }

    uint8_t *p = (uint8_t *)buffer;

    ethFrameQueue->idx = 0U;
    ethFrameQueue->valid_len = 0U;
    ethFrameQueue->total_len = length;
    ethFrameQueue->queue = malloc(sizeof(eth_adapter_frame_buf_t) * length);
    if (ethFrameQueue->queue)
    {
        for (uint32_t cnt = 0U; cnt < length; cnt++)
        {
            ethFrameQueue->queue[cnt].payload = &p[cnt * bufferUnitLength];
            ethFrameQueue->queue[cnt].len = 0U;
        }
    }
    else
    {
        return ETH_ADAPTER_ERROR;
    }

    return ETH_ADAPTER_OK;
}

static inline eth_adapter_err_t ETH_ADAPTER_FrameQueueDestroy(eth_adapter_frame_queue_t *ethFrameQueue)
{
    if (!ethFrameQueue)
    {
        return ETH_ADAPTER_INVALID;
    }

    free(ethFrameQueue->queue);

    return ETH_ADAPTER_OK;
}

static inline eth_adapter_err_t ETH_ADAPTER_FrameQueuePush(eth_adapter_frame_queue_t *ethFrameQueue, eth_adapter_frame_buf_t *buffer)
{
    if (!ethFrameQueue || !buffer)
    {
        return ETH_ADAPTER_INVALID;
    }

    if (ethFrameQueue->valid_len < ethFrameQueue->total_len)
    {
        uint32_t target_idx = (ethFrameQueue->idx + ethFrameQueue->valid_len) % ethFrameQueue->total_len;
        memcpy(ethFrameQueue->queue[target_idx].payload, buffer->payload, buffer->len);
        ethFrameQueue->queue[target_idx].len = buffer->len;
        ethFrameQueue->valid_len++;
    }
    else
    {
        return ETH_ADAPTER_INVALID;
    }

    return ETH_ADAPTER_OK;
}

static inline eth_adapter_err_t ETH_ADAPTER_FrameQueuePop(eth_adapter_frame_queue_t *ethFrameQueue, eth_adapter_frame_buf_t *buffer)
{
    if (!ethFrameQueue)
    {
        return ETH_ADAPTER_INVALID;
    }

    if (ethFrameQueue->valid_len)
    {
        if (buffer)
        {
            buffer->len = ethFrameQueue->queue[ethFrameQueue->idx].len;
            buffer->payload = ethFrameQueue->queue[ethFrameQueue->idx].payload;
        }

        ethFrameQueue->idx = (ethFrameQueue->idx + 1) % ethFrameQueue->total_len;
        ethFrameQueue->valid_len--;
    }
    else
    {
        return ETH_ADAPTER_ERROR;
    }

    return ETH_ADAPTER_OK;
}

static inline eth_adapter_err_t ETH_ADAPTER_FrameQueueClear(eth_adapter_frame_queue_t *ethFrameQueue)
{
    if (!ethFrameQueue)
    {
        return ETH_ADAPTER_INVALID;
    }

    ethFrameQueue->valid_len = 0U;

    return ETH_ADAPTER_OK;
}

eth_adapter_err_t ETH_ADAPTER_Init(void);

eth_adapter_err_t ETH_ADAPTER_GetMacAddress(uint8_t *address);

eth_adapter_err_t ETH_ADAPTER_GetLinkStatus(bool *status);

eth_adapter_err_t ETH_ADAPTER_GetLinkSpeed(uint32_t *speed);

eth_adapter_err_t ETH_ADAPTER_SendFrame(eth_adapter_frame_buf_t *buffer);

eth_adapter_err_t ETH_ADAPTER_RecvFrame(eth_adapter_frame_buf_t *buffer);

eth_adapter_err_t ETH_ADAPTER_SendFrameQueue(void);

eth_adapter_err_t ETH_ADAPTER_RecvFrameQueue(void);

eth_adapter_err_t ETH_ADAPTER_IdentifyDstFrameType(eth_adapter_frame_buf_t *buffer, eth_adapter_dst_frame_type_t *type);
#endif
