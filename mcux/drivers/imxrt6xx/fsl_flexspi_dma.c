/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexspi_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexspi_dma"
#endif

/*<! Structure definition for flexspi_dma_private_handle_t. The structure is private. */
typedef struct _flexspi_dma_private_handle
{
    FLEXSPI_Type *base;
    flexspi_dma_handle_t *handle;
} flexspi_dma_private_handle_t;

/* FLEXSPI DMA transfer handle. */
enum _flexspi_dma_tansfer_states
{
    kFLEXSPI_Idle, /* FLEXSPI Bus idle. */
    kFLEXSPI_Busy  /* FLEXSPI Bus busy. */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Pointers to flexspi bases for each instance. */
static FLEXSPI_Type *const s_flexspiBases[] = FLEXSPI_BASE_PTRS;

/*<! Private handle only used for internally. */
static flexspi_dma_private_handle_t s_dmaPrivateHandle[ARRAY_SIZE(s_flexspiBases)];

/*<! Private DMA descriptor array to support transfer size not multiple of watermark level byts.
The link array consumes 64 bytes consumption.*/
#if defined(__ICCARM__)
#pragma data_alignment = FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZE
static dma_descriptor_t s_flexspiDes[1];
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION)
__attribute__((aligned(FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZE))) static dma_descriptor_t s_flexspiDes[1];
#elif defined(__GNUC__)
__attribute__((aligned(FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZE))) static dma_descriptor_t s_flexspiDes[1];
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief FLEXSPI DMA transfer finished callback function.
 *
 * This function is called when FLEXSPI DMA transfer finished. It disables the FLEXSPI
 * TX/RX DMA request and sends status to FLEXSPI callback.
 *
 * @param handle The DMA handle.
 * @param param Callback function parameter.
 */
static void FLEXSPI_TransferDMACallback(dma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

/*!
 * @brief Get the FLEXSPI instance from peripheral base address.
 *
 * @param base FLEXSPI peripheral base address.
 * @return FLEXSPI instance.
 */
extern uint32_t FLEXSPI_GetInstance(FLEXSPI_Type *base);

/*!
 * @brief Check and clear IP command execution errors.
 *
 * @param base FLEXSPI base pointer.
 * @param status interrupt status.
 */
extern status_t FLEXSPI_CheckAndClearError(FLEXSPI_Type *base, uint32_t status);
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint8_t FLEXSPI_CalculatePower(uint32_t value)
{
    uint8_t power = 0;
    while (value >> 1 != 0)
    {
        power++;
        value = value >> 1;
    }

    return power;
}

static void FLEXSPI_TransferDMACallback(dma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    flexspi_dma_private_handle_t *flexspiPrivateHandle = (flexspi_dma_private_handle_t *)param;

    /* Avoid warning for unused parameters. */
    handle = handle;
    tcds   = tcds;

    if (transferDone)
    {
        /* Wait for bus idle. */
        while (!FLEXSPI_GetBusIdleStatus(flexspiPrivateHandle->base))
        {
        }
        /* Disable transfer. */
        FLEXSPI_TransferAbortDMA(flexspiPrivateHandle->base, flexspiPrivateHandle->handle);

        if (flexspiPrivateHandle->handle->completionCallback)
        {
            flexspiPrivateHandle->handle->completionCallback(flexspiPrivateHandle->base, flexspiPrivateHandle->handle,
                                                             kStatus_Success, flexspiPrivateHandle->handle->userData);
        }
    }
}

/*!
 * brief Initializes the FLEXSPI handle for transfer which is used in transactional functions and set the callback.
 *
 * param base FLEXSPI peripheral base address
 * param handle Pointer to flexspi_dma_handle_t structure
 * param callback FLEXSPI callback, NULL means no callback.
 * param userData User callback function data.
 * param txDmaHandle User requested DMA handle for TX DMA transfer.
 * param rxDmaHandle User requested DMA handle for RX DMA transfer.
 */
void FLEXSPI_TransferCreateHandleDMA(FLEXSPI_Type *base,
                                     flexspi_dma_handle_t *handle,
                                     flexspi_dma_callback_t callback,
                                     void *userData,
                                     dma_handle_t *txDmaHandle,
                                     dma_handle_t *rxDmaHandle)
{
    assert(handle);

    uint32_t instance = FLEXSPI_GetInstance(base);

    s_dmaPrivateHandle[instance].base   = base;
    s_dmaPrivateHandle[instance].handle = handle;

    memset(handle, 0, sizeof(*handle));

    handle->state       = kFLEXSPI_Idle;
    handle->txDmaHandle = txDmaHandle;
    handle->rxDmaHandle = rxDmaHandle;
    handle->nsize       = kFLEXPSI_DMAnSize4Bytes;

    handle->completionCallback = callback;
    handle->userData           = userData;
}

/*!
 * brief Update FLEXSPI DMA transfer source data transfer size(SSIZE) and destination data transfer size(DSIZE).
 *
 * param base FLEXSPI peripheral base address
 * param handle Pointer to flexspi_dma_handle_t structure
 * param nsize FLEXSPI DMA transfer data transfer size(SSIZE/DSIZE), by default the size is
 * kFLEXPSI_DMAnSize1Bytes(one byte).
 * see flexspi_dma_transfer_nsize_t               .
 */
void FLEXSPI_TransferUpdateSizeDMA(FLEXSPI_Type *base, flexspi_dma_handle_t *handle, flexspi_dma_transfer_nsize_t nsize)
{
    handle->nsize = nsize;
}

/*!
 * brief Transfers FLEXSPI data using an dma non-blocking method.
 *
 * This function writes/receives data to/from the FLEXSPI transmit/receive FIFO. This function is non-blocking.
 * param base FLEXSPI peripheral base address.
 * param handle Pointer to flexspi_dma_handle_t structure
 * param xfer FLEXSPI transfer structure.
 * retval kStatus_FLEXSPI_Busy     FLEXSPI is busy transfer.
 * retval kStatus_InvalidArgument  The watermark configuration is invalid, the watermark should be power of
                                    2 to do successfully DMA transfer.
 * retval kStatus_Success          FLEXSPI successfully start dma transfer.
 */
status_t FLEXSPI_TransferDMA(FLEXSPI_Type *base, flexspi_dma_handle_t *handle, flexspi_transfer_t *xfer)
{
    uint32_t configValue = 0;
    status_t result      = kStatus_Success;
    uint32_t instance    = FLEXSPI_GetInstance(base);

    assert(handle);
    assert(xfer);

    /* Check if the FLEXSPI bus is idle - if not return busy status. */
    if (handle->state != kFLEXSPI_Idle)
    {
        result = kStatus_FLEXSPI_Busy;
    }
    else
    {
        handle->transferSize = xfer->dataSize;
        handle->state        = kFLEXSPI_Busy;

        /* Clear sequence pointer before sending data to external devices. */
        base->FLSHCR2[xfer->port] |= FLEXSPI_FLSHCR2_CLRINSTRPTR_MASK;

        /* Clear former pending status before start this transfer. */
        base->INTR |= FLEXSPI_INTR_AHBCMDERR_MASK | FLEXSPI_INTR_IPCMDERR_MASK | FLEXSPI_INTR_AHBCMDGE_MASK |
                      FLEXSPI_INTR_IPCMDGE_MASK;

        /* Configure base address. */
        base->IPCR0 = xfer->deviceAddress;

        /* Reset fifos. */
        base->IPTXFCR |= FLEXSPI_IPTXFCR_CLRIPTXF_MASK;
        base->IPRXFCR |= FLEXSPI_IPRXFCR_CLRIPRXF_MASK;

        /* Configure data size. */
        if ((xfer->cmdType == kFLEXSPI_Read) || (xfer->cmdType == kFLEXSPI_Write))
        {
            configValue = FLEXSPI_IPCR1_IDATSZ(xfer->dataSize);
        }

        /* Configure sequence ID. */
        configValue |= FLEXSPI_IPCR1_ISEQID(xfer->seqIndex) | FLEXSPI_IPCR1_ISEQNUM(xfer->SeqNumber - 1);
        base->IPCR1 = configValue;
    }

    if ((xfer->cmdType == kFLEXSPI_Write) || (xfer->cmdType == kFLEXSPI_Config))
    {
        handle->count = 8U * (((base->IPTXFCR & FLEXSPI_IPTXFCR_TXWMRK_MASK) >> FLEXSPI_IPTXFCR_TXWMRK_SHIFT) + 1U);

        /* Check the watermark is power of 2 */
        if ((handle->count & (handle->count - 1)) != 0U)
        {
            return kStatus_InvalidArgument;
        }

        dma_channel_trigger_t dmaTxTriggerConfig;
        dmaTxTriggerConfig.type = kDMA_RisingEdgeTrigger;
        uint8_t desCount;
        uint32_t bytesPerDes = xfer->dataSize;
        uint8_t remains      = 0;

        if (xfer->dataSize < handle->count)
        {
            handle->nsize           = kFLEXPSI_DMAnSize1Bytes;
            handle->nbytes          = xfer->dataSize / handle->nsize;
            dmaTxTriggerConfig.wrap = kDMA_NoWrap;
            /* Check the handle->nbytes is power of 2 */
            if (((handle->nbytes) & (handle->nbytes - 1U)) != 0U)
            {
                handle->nbytes = 2U * ((handle->nbytes) & (handle->nbytes - 1U));
            }
            desCount = 1U;
        }
        else
        {
            dmaTxTriggerConfig.wrap = kDMA_DstWrap;
            remains                 = xfer->dataSize % handle->count;
            if (remains == 0U)
            {
                desCount = 1U;
            }
            else
            {
                desCount    = 2U;
                bytesPerDes = xfer->dataSize - remains;
                if ((remains & 3U) == 0U)
                {
                    handle->nsize = kFLEXPSI_DMAnSize4Bytes;
                }
                else if ((remains & 1U) == 0U)
                {
                    handle->nsize = kFLEXPSI_DMAnSize2Bytes;
                }
                else
                {
                    handle->nsize = kFLEXPSI_DMAnSize1Bytes;
                }
            }
            /* Store the initially configured dma minor byte transfer count into the FLEXSPI handle */
            handle->nbytes = handle->count / handle->nsize;
        }

        /* Check xfer->dataSize exceeds the maximum transfer count supported by the driver. */
        if ((xfer->dataSize - handle->count + 1U) / ((uint32_t)handle->nsize) > 1024U)
        {
            return kStatus_InvalidArgument;
        }

        /* Check the xfer->data start address follows the alignment and xfer->dataSize needs to be larger than 1 due to
         * hardware limitation */
        if ((((uint32_t)xfer->data & (handle->nsize - 1U)) != 0U) || (xfer->dataSize / handle->nsize == 1U))
        {
            return kStatus_InvalidArgument;
        }

        void *txFifoBase = (void *)FLEXSPI_GetTxFifoAddress(base);
        void *nextDesc   = NULL;

        dmaTxTriggerConfig.burst = (dma_trigger_burst_t)(
            DMA_CHANNEL_CFG_TRIGBURST(1) | DMA_CHANNEL_CFG_BURSTPOWER(FLEXSPI_CalculatePower(handle->nbytes)));
        handle->transferSize = xfer->dataSize;
        dma_channel_config_t txChannelConfig;

        for (uint8_t i = desCount - 1U; i > 0; i--)
        {
            DMA_SetupDescriptor(
                &s_flexspiDes[i - 1U],
                DMA_CHANNEL_XFER((nextDesc == NULL) ? false : true, true, (nextDesc == NULL) ? true : false, false,
                                 handle->nsize, kDMA_AddressInterleave1xWidth, kDMA_AddressInterleave1xWidth, remains),
                (void *)((uint32_t)xfer->data + bytesPerDes), txFifoBase, nextDesc);
            nextDesc = &s_flexspiDes[i - 1U];
        }

        DMA_PrepareChannelTransfer(
            &txChannelConfig, (void *)xfer->data, txFifoBase,
            DMA_CHANNEL_XFER((nextDesc == NULL) ? false : true, true, (nextDesc == NULL) ? true : false, false,
                             handle->nsize, kDMA_AddressInterleave1xWidth, kDMA_AddressInterleave1xWidth, bytesPerDes),
            kDMA_MemoryToMemory, &dmaTxTriggerConfig, nextDesc);

        DMA_SubmitChannelTransfer(handle->txDmaHandle, &txChannelConfig);

        DMA_SetCallback(handle->txDmaHandle, FLEXSPI_TransferDMACallback,
                        &s_dmaPrivateHandle[FLEXSPI_GetInstance(base)]);
        DMA_StartTransfer(handle->txDmaHandle);

        /* Enable FLEXSPI TX DMA. */
        FLEXSPI_EnableTxDMA(base, true);

        /* Start Transfer. */
        base->IPCMD |= FLEXSPI_IPCMD_TRG_MASK;
    }
    else if (xfer->cmdType == kFLEXSPI_Read)
    {
        handle->count = 8U * (((base->IPRXFCR & FLEXSPI_IPRXFCR_RXWMRK_MASK) >> FLEXSPI_IPRXFCR_RXWMRK_SHIFT) + 1U);

        /* Check the watermark is power of 2U */
        if ((handle->count & (handle->count - 1U)) != 0U)
        {
            return kStatus_InvalidArgument;
        }

        dma_channel_trigger_t dmaRxTriggerConfig;
        dmaRxTriggerConfig.type = kDMA_RisingEdgeTrigger;
        uint8_t desCount;
        uint32_t bytesPerDes = xfer->dataSize;
        uint8_t remains      = 0;

        if (xfer->dataSize < handle->count)
        {
            handle->nsize           = kFLEXPSI_DMAnSize1Bytes;
            handle->nbytes          = xfer->dataSize / handle->nsize;
            dmaRxTriggerConfig.wrap = kDMA_NoWrap;
            /* Check the handle->nbytes is power of 2 */
            if (((handle->nbytes) & (handle->nbytes - 1)) != 0U)
            {
                handle->nbytes = 2U * ((handle->nbytes) & (handle->nbytes - 1U));
            }
            desCount = 1U;
        }
        else
        {
            dmaRxTriggerConfig.wrap = kDMA_SrcWrap;
            remains                 = xfer->dataSize % handle->count;
            if (remains == 0U)
            {
                desCount = 1U;
            }
            else
            {
                desCount    = 2U;
                bytesPerDes = xfer->dataSize - remains;
                if ((remains & 3U) == 0U)
                {
                    handle->nsize = kFLEXPSI_DMAnSize4Bytes;
                }
                else if ((remains & 1U) == 0U)
                {
                    handle->nsize = kFLEXPSI_DMAnSize2Bytes;
                }
                else
                {
                    handle->nsize = kFLEXPSI_DMAnSize1Bytes;
                }
            }
            /* Store the initially configured dma minor byte transfer count into the FLEXSPI handle */
            handle->nbytes = handle->count / handle->nsize;
        }

        /* Check xfer->dataSize exceeds the maximum transfer count supported by the driver. */
        if ((xfer->dataSize - handle->count + 1U) / ((uint32_t)handle->nsize) > 1024U)
        {
            return kStatus_InvalidArgument;
        }

        /* Check the xfer->data start address follows the alignment */
        if (((uint32_t)xfer->data & (handle->nsize - 1U)) != 0U)
        {
            return kStatus_InvalidArgument;
        }

        void *rxFifoBase         = (void *)FLEXSPI_GetRxFifoAddress(base);
        void *nextDesc           = NULL;
        dmaRxTriggerConfig.burst = (dma_trigger_burst_t)(
            DMA_CHANNEL_CFG_TRIGBURST(1U) | DMA_CHANNEL_CFG_BURSTPOWER(FLEXSPI_CalculatePower(handle->nbytes)));
        dma_channel_config_t rxChannelConfig;

        for (uint8_t i = desCount - 1U; i > 0; i--)
        {
            DMA_SetupDescriptor(
                &s_flexspiDes[i - 1U],
                DMA_CHANNEL_XFER((nextDesc == NULL) ? false : true, true, (nextDesc == NULL) ? true : false, false,
                                 handle->nsize, kDMA_AddressInterleave1xWidth, kDMA_AddressInterleave1xWidth, remains),
                rxFifoBase, (void *)((uint32_t)xfer->data + bytesPerDes), nextDesc);
            nextDesc = &s_flexspiDes[i - 1U];
        }

        DMA_PrepareChannelTransfer(
            &rxChannelConfig, rxFifoBase, (void *)xfer->data,
            DMA_CHANNEL_XFER((nextDesc == NULL) ? false : true, true, (nextDesc == NULL) ? true : false, false,
                             handle->nsize, kDMA_AddressInterleave1xWidth, kDMA_AddressInterleave1xWidth, bytesPerDes),
            kDMA_MemoryToMemory, &dmaRxTriggerConfig, nextDesc);

        DMA_SubmitChannelTransfer(handle->rxDmaHandle, &rxChannelConfig);

        DMA_SetCallback(handle->rxDmaHandle, FLEXSPI_TransferDMACallback, &s_dmaPrivateHandle[instance]);
        DMA_StartTransfer(handle->rxDmaHandle);

        /* Enable FLEXSPI RX DMA. */
        FLEXSPI_EnableRxDMA(base, true);

        /* Start Transfer. */
        base->IPCMD |= FLEXSPI_IPCMD_TRG_MASK;
    }
    else
    {
        /* Start Transfer. */
        base->IPCMD |= FLEXSPI_IPCMD_TRG_MASK;
        /* Wait for bus idle. */
        while (!FLEXSPI_GetBusIdleStatus(base))
        {
        }
        result = FLEXSPI_CheckAndClearError(base, base->INTR);

        handle->state = kFLEXSPI_Idle;

        if (handle->completionCallback)
        {
            handle->completionCallback(base, handle, result, handle->userData);
        }
    }

    return result;
}

/*!
 * brief Aborts the transfer data using dma.
 *
 * This function aborts the transfer data using dma.
 *
 * param base FLEXSPI peripheral base address.
 * param handle Pointer to flexspi_dma_handle_t structure
 */
void FLEXSPI_TransferAbortDMA(FLEXSPI_Type *base, flexspi_dma_handle_t *handle)
{
    assert(handle);

    if (base->IPTXFCR & FLEXSPI_IPTXFCR_TXDMAEN_MASK)
    {
        FLEXSPI_EnableTxDMA(base, false);
        DMA_AbortTransfer(handle->txDmaHandle);
    }

    if (base->IPRXFCR & FLEXSPI_IPRXFCR_RXDMAEN_MASK)
    {
        FLEXSPI_EnableRxDMA(base, false);
        DMA_AbortTransfer(handle->rxDmaHandle);
    }

    handle->state = kFLEXSPI_Idle;
}

status_t FLEXSPI_TransferGetTransferCountDMA(FLEXSPI_Type *base, flexspi_dma_handle_t *handle, size_t *count)
{
    assert(handle);
    assert(count);

    status_t result = kStatus_Success;

    if (handle->state != kFLEXSPI_Busy)
    {
        result = kStatus_NoTransferInProgress;
    }
    else
    {
        if (base->IPRXFCR & FLEXSPI_IPRXFCR_RXDMAEN_MASK)
        {
            *count =
                (handle->transferSize - DMA_GetRemainingBytes(handle->rxDmaHandle->base, handle->rxDmaHandle->channel));
        }
        else if (base->IPTXFCR & FLEXSPI_IPTXFCR_TXDMAEN_MASK)
        {
            *count =
                (handle->transferSize - DMA_GetRemainingBytes(handle->txDmaHandle->base, handle->txDmaHandle->channel));
        }
        else
        {
        }
    }

    return result;
}
