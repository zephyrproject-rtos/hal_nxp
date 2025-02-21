/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qspi_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qspi_dma"
#endif

/*<! Structure definition for qspi_dma_private_handle_t. The structure is private. */
typedef struct _qspi_dma_private_handle
{
    QuadSPI_Type *base;
    qspi_dma_handle_t *handle;
} qspi_dma_private_handle_t;

/* QSPI DMA transfer handle. */
enum _qspi_dma_tansfer_states
{
    kQSPI_Idle,   /* TX idle. */
    kQSPI_BusBusy /* RX busy. */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*<! Private handle only used for internally. */
static qspi_dma_private_handle_t s_dmaPrivateHandle[FSL_FEATURE_SOC_QuadSPI_COUNT];

/*<! Private DMA descriptor array used for internally to fix QSPI+DMA ERRATA.
QSPI.1: Using QSPI register interface, TX buffer fill / RX buffer drain by DMA
with a single DMA descriptor cannot be performed. The link array consumes about
1K RAM consumption support QSPI TX watermark starting from 8 bytes.*/
#if defined(__ICCARM__)
#pragma data_alignment                = FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZE
static dma_descriptor_t s_qspiDes[63] = {0};
#elif defined(__CC_ARM)
__attribute__((aligned(FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZE))) static dma_descriptor_t s_qspiDes[63] = {0};
#elif defined(__GNUC__)
__attribute__((aligned(FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZE))) static dma_descriptor_t s_qspiDes[63] = {0};
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief QSPI DMA send finished callback function.
 *
 * This function is called when QSPI DMA send finished. It disables the QSPI
 * TX DMA request and sends @ref kStatus_QSPI_TxIdle to QSPI callback.
 *
 * @param handle The DMA handle.
 * @param param Callback function parameter.
 */
static void QSPI_SendDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode);

/*******************************************************************************
 * Code
 ******************************************************************************/

static void QSPI_SendDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode)
{
    qspi_dma_private_handle_t *qspiPrivateHandle = (qspi_dma_private_handle_t *)userData;

    /* Avoid the warning for unused variables. */
    handle = handle;

    if (transferDone)
    {
        QSPI_TransferAbortSendDMA(qspiPrivateHandle->base, qspiPrivateHandle->handle);

        if (qspiPrivateHandle->handle->callback)
        {
            qspiPrivateHandle->handle->callback(qspiPrivateHandle->base, qspiPrivateHandle->handle, kStatus_QSPI_Idle,
                                                qspiPrivateHandle->handle->userData);
        }
    }
}

/*!
 * brief Initializes the QSPI handle for send which is used in transactional functions and set the callback.
 *
 * param base QSPI peripheral base address
 * param handle Pointer to qspi_dma_handle_t structure
 * param callback QSPI callback, NULL means no callback.
 * param userData User callback function data.
 * param rxDmaHandle User requested DMA handle for DMA transfer
 */
void QSPI_TransferTxCreateHandleDMA(QuadSPI_Type *base,
                                    qspi_dma_handle_t *handle,
                                    qspi_dma_callback_t callback,
                                    void *userData,
                                    dma_handle_t *dmaHandle)
{
    assert(handle);

    uint32_t instance                        = QSPI_GetInstance(base);
    dma_channel_trigger_t dmaTxTriggerConfig = {
        .burst = kDMA_SingleTransfer, .type = kDMA_RisingEdgeTrigger, .wrap = kDMA_NoWrap};
    uint8_t watermark = base->TBCT + 1;

    s_dmaPrivateHandle[instance].base   = base;
    s_dmaPrivateHandle[instance].handle = handle;

    memset(handle, 0, sizeof(*handle));

    handle->state     = kQSPI_Idle;
    handle->dmaHandle = dmaHandle;

    handle->callback = callback;
    handle->userData = userData;

    /* Only support watermark 2, 4, 8,16. Other watermarks are not supported. */
    switch (watermark)
    {
        case 2:
            dmaTxTriggerConfig.burst = kDMA_EdgeBurstTransfer2;
            break;
        case 4:
            dmaTxTriggerConfig.burst = kDMA_EdgeBurstTransfer4;
            break;
        case 8:
            dmaTxTriggerConfig.burst = kDMA_EdgeBurstTransfer8;
            break;
        case 16:
            dmaTxTriggerConfig.burst = kDMA_EdgeBurstTransfer16;
            break;
        default:
            assert(false);
            break;
    }

    DMA_ConfigureChannelTrigger(handle->dmaHandle->base, handle->dmaHandle->channel, &dmaTxTriggerConfig);

    /* Configure TX dma callback */
    DMA_SetCallback(handle->dmaHandle, QSPI_SendDMACallback, &s_dmaPrivateHandle[instance]);
}

/*!
 * brief Transfers QSPI data using an DMA non-blocking method.
 *
 * This function writes data to the QSPI transmit FIFO. This function is non-blocking.
 * param base Pointer to QuadSPI Type.
 * param handle Pointer to qspi_dma_handle_t structure
 * param xfer QSPI transfer structure.
 */
status_t QSPI_TransferSendDMA(QuadSPI_Type *base, qspi_dma_handle_t *handle, qspi_transfer_t *xfer)
{
    assert(handle && (handle->dmaHandle));

    status_t status;

    /* If previous TX not finished. */
    if (kQSPI_BusBusy == handle->state)
    {
        status = kStatus_QSPI_Busy;
    }
    else
    {
        handle->state        = kQSPI_BusBusy;
        handle->transferSize = xfer->dataSize;
        void *txFifoBase     = (void *)QSPI_GetTxDataRegisterAddress(base);
        void *nextDesc       = NULL;
        dma_transfer_config_t xferConfig;
        uint8_t bytesPerDes = (base->TBCT + 1) * 4;

        /* Configure linked descriptors to start QSPI Tx DMA transfer to provide software workaround for
        ERRATA QSPI.1: Using QSPI register interface, TX buffer fill / RX buffer drain by DMA with a
        single DMA descriptor cannot be performed. */
        for (uint8_t i = (xfer->dataSize / bytesPerDes) - 1; i > 0; i--)
        {
            /* Prepare transfer. */
            DMA_PrepareTransfer(&xferConfig,
                                (void *)((uint32_t)xfer->data + i * bytesPerDes), /* DMA transfer source address. */
                                txFifoBase,              /* DMA transfer destination address. */
                                sizeof(uint32_t),        /* DMA transfer destination address width(bytes). */
                                bytesPerDes,             /* DMA transfer bytes to be transferred. */
                                kDMA_MemoryToPeripheral, /* DMA transfer type. */
                                nextDesc                 /* nextDesc Chain custom descriptor to transfer. */
            );

            xferConfig.xfercfg.intA = (nextDesc == NULL) ? true : false;
            xferConfig.isPeriph     = false;
            DMA_CreateDescriptor(&s_qspiDes[i - 1], &xferConfig.xfercfg, xferConfig.srcAddr, xferConfig.dstAddr,
                                 xferConfig.nextDesc);
            nextDesc = &s_qspiDes[i - 1];
        }

        /* Prepare transfer. */
        DMA_PrepareTransfer(&xferConfig, (void *)(uint32_t)xfer->data, /* DMA transfer source address. */
                            txFifoBase,                                /* DMA transfer destination address. */
                            sizeof(uint32_t),        /* DMA transfer destination address width(bytes). */
                            bytesPerDes,             /* DMA transfer bytes to be transferred. */
                            kDMA_MemoryToPeripheral, /* DMA transfer type. */
                            nextDesc                 /* nextDesc Chain custom descriptor to transfer. */
        );

        /* Set channel XFERCFG register according first channel descriptor. */
        xferConfig.isPeriph     = false;
        xferConfig.xfercfg.intA = false;
        DMA_SubmitTransfer(handle->dmaHandle, &xferConfig);
        DMA_StartTransfer(handle->dmaHandle);

        if (QSPI_GetStatusFlags(base) & kQSPI_TxWatermark)
        {
            handle->dmaHandle->base->CHANNEL[handle->dmaHandle->channel].XFERCFG |= DMA_CHANNEL_XFERCFG_SWTRIG_MASK;
        }

        /* Enable QSPI TX DMA. */
        QSPI_EnableDMA(base, kQSPI_TxBufferFillDMAEnable, true);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the sent data using DMA.
 *
 * This function aborts the sent data using DMA.
 *
 * param base QSPI peripheral base address.
 * param handle Pointer to qspi_dma_handle_t structure
 */
void QSPI_TransferAbortSendDMA(QuadSPI_Type *base, qspi_dma_handle_t *handle)
{
    assert(handle && (handle->dmaHandle));

    /* Disable QSPI TX DMA. */
    QSPI_EnableDMA(base, kQSPI_TxBufferFillDMAEnable, false);

    /* Stop transfer. */
    DMA_AbortTransfer(handle->dmaHandle);

    handle->state = kQSPI_Idle;
}

/*!
 * brief Gets the transferred counts of send.
 *
 * param base Pointer to QuadSPI Type.
 * param handle Pointer to qspi_dma_handle_t structure.
 * param count Bytes sent.
 * retval kStatus_Success Succeed get the transfer count.
 * retval kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t QSPI_TransferGetSendCountDMA(QuadSPI_Type *base, qspi_dma_handle_t *handle, size_t *count)
{
    assert(handle);

    status_t status = kStatus_Success;

    if (handle->state != kQSPI_BusBusy)
    {
        status = kStatus_NoTransferInProgress;
    }
    else
    {
        *count = handle->transferSize - DMA_GetRemainingBytes(handle->dmaHandle->base, handle->dmaHandle->channel);
    }

    return status;
}
