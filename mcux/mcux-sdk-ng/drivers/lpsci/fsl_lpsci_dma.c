/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpsci_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpsci_dma"
#endif

/*<! Structure definition for lpsci_dma_handle_t. The structure is private. */
typedef struct _lpsci_dma_private_handle
{
    UART0_Type *base;
    lpsci_dma_handle_t *handle;
} lpsci_dma_private_handle_t;

/* LPSCI DMA transfer handle. */
enum _lpsci_dma_tansfer_states
{
    kLPSCI_TxIdle, /* TX idle. */
    kLPSCI_TxBusy, /* TX busy. */
    kLPSCI_RxIdle, /* RX idle. */
    kLPSCI_RxBusy  /* RX busy. */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*<! Private handle only used for internally. */
static lpsci_dma_private_handle_t s_dmaPrivateHandle[FSL_FEATURE_SOC_LPSCI_COUNT];

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief LPSCI DMA send finished callback function.
 *
 * This function is called when LPSCI DMA send finished. It disables the LPSCI
 * TX DMA request and sends @ref kStatus_LPSCI_TxIdle to LPSCI callback.
 *
 * @param handle The DMA handle.
 * @param param Callback function parameter.
 */
static void LPSCI_TransferSendDMACallback(dma_handle_t *handle, void *param);

/*!
 * @brief LPSCI DMA receive finished callback function.
 *
 * This function is called when LPSCI DMA receive finished. It disables the LPSCI
 * RX DMA request and sends @ref kStatus_LPSCI_RxIdle to LPSCI callback.
 *
 * @param handle The DMA handle.
 * @param param Callback function parameter.
 */
static void LPSCI_TransferReceiveDMACallback(dma_handle_t *handle, void *param);

/*!
 * @brief LPSCI DMA transfer IRQ handle function.
 *
 * This function handles the LPSCI tx complete IRQ request to invoke user callback.
 *
 * @param base LPSCI peripheral base address.
 * @param lpsciDmaHandle LPSCI handle pointer.
 */
static void LPSCI_TransferDMAHandleIRQ(UART0_Type *base, void *lpsciDmaHandle);

/*******************************************************************************
 * Code
 ******************************************************************************/
static void LPSCI_TransferSendDMACallback(dma_handle_t *handle, void *param)
{
    assert(handle != NULL);
    assert(param != NULL);

    lpsci_dma_private_handle_t *lpsciPrivateHandle = (lpsci_dma_private_handle_t *)param;

    /* Disable LPSCI TX DMA. */
    LPSCI_EnableTxDMA(lpsciPrivateHandle->base, false);

    /* Disable interrupt. */
    DMA_DisableInterrupts(handle->base, handle->channel);

    /* Enable tx complete interrupt */
    LPSCI_EnableInterrupts(lpsciPrivateHandle->base, (uint32_t)kLPSCI_TransmissionCompleteInterruptEnable);
}

static void LPSCI_TransferReceiveDMACallback(dma_handle_t *handle, void *param)
{
    assert(handle != NULL);
    assert(param != NULL);

    lpsci_dma_private_handle_t *lpsciPrivateHandle = (lpsci_dma_private_handle_t *)param;

    /* Disable LPSCI RX DMA. */
    LPSCI_EnableRxDMA(lpsciPrivateHandle->base, false);

    /* Disable interrupt. */
    DMA_DisableInterrupts(handle->base, handle->channel);

    lpsciPrivateHandle->handle->rxState = kLPSCI_RxIdle;

    if (lpsciPrivateHandle->handle->callback)
    {
        lpsciPrivateHandle->handle->callback(lpsciPrivateHandle->base, lpsciPrivateHandle->handle, kStatus_LPSCI_RxIdle,
                                             lpsciPrivateHandle->handle->userData);
    }
}

/*!
 * brief Initializes the LPSCI handle which is used in transactional functions.
 * param handle Pointer to lpsci_dma_handle_t structure
 * param base LPSCI peripheral base address
 * param rxDmaHandle User requested DMA handle for RX DMA transfer
 * param txDmaHandle User requested DMA handle for TX DMA transfer
 */
void LPSCI_TransferCreateHandleDMA(UART0_Type *base,
                                   lpsci_dma_handle_t *handle,
                                   lpsci_dma_transfer_callback_t callback,
                                   void *userData,
                                   dma_handle_t *txDmaHandle,
                                   dma_handle_t *rxDmaHandle)
{
    assert(handle != 0U);

    uint32_t instance = LPSCI_GetInstance(base);

    memset(handle, 0, sizeof(lpsci_dma_handle_t));

    s_dmaPrivateHandle[instance].base   = base;
    s_dmaPrivateHandle[instance].handle = handle;

    handle->rxState = kLPSCI_RxIdle;
    handle->txState = kLPSCI_TxIdle;

    handle->callback = callback;
    handle->userData = userData;

#if defined(FSL_FEATURE_LPSCI_HAS_FIFO) && FSL_FEATURE_LPSCI_HAS_FIFO
    /* Note:
       Take care of the RX FIFO, DMA request only assert when received bytes
       equal or more than RX water mark, there is potential issue if RX water
       mark larger than 1.
       For example, if RX FIFO water mark is 2, upper layer needs 5 bytes and
       5 bytes are received. the last byte will be saved in FIFO but not trigger
       DMA transfer because the water mark is 2.
     */
    if (rxDmaHandle)
    {
        base->RWFIFO = 1U;
    }
#endif

    handle->rxDmaHandle = rxDmaHandle;
    handle->txDmaHandle = txDmaHandle;

    /* Save the handle into static handle array */
    s_lpsciHandle[instance] = handle;
    /* Save IRQ handler into static ISR function pointer. */
    s_lpsciIsr = LPSCI_TransferDMAHandleIRQ;
    /* Disable internal IRQs and enable global IRQ. */
    LPSCI_DisableInterrupts(base, (uint32_t)kLPSCI_AllInterruptsEnable);
    (void)EnableIRQ(s_lpsciIRQ[instance]);

    /* Configure TX. */
    if (txDmaHandle)
    {
        DMA_SetCallback(txDmaHandle, LPSCI_TransferSendDMACallback, &s_dmaPrivateHandle[instance]);
    }

    /* Configure RX. */
    if (rxDmaHandle)
    {
        DMA_SetCallback(rxDmaHandle, LPSCI_TransferReceiveDMACallback, &s_dmaPrivateHandle[instance]);
    }
}

/*!
 * brief Sends data using DMA.
 *
 * This function sends data using DMA. This is a non-blocking function, which returns
 * immediately. When all data is sent, the send callback function is called.
 *
 * param handle LPSCI handle pointer.
 * param xfer LPSCI DMA transfer structure, see #lpsci_transfer_t.
 * retval kStatus_Success if successful, others failed.
 * retval kStatus_LPSCI_TxBusy Previous transfer on going.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPSCI_TransferSendDMA(UART0_Type *base, lpsci_dma_handle_t *handle, lpsci_transfer_t *xfer)
{
    assert(handle != NULL);
    assert(handle->txDmaHandle != NULL);
    assert(xfer != NULL);
    assert(xfer->data != NULL);
    assert(xfer->dataSize != 0U);

    dma_transfer_config_t xferConfig;
    status_t status;

    /* If previous TX not finished. */
    if (kLPSCI_TxBusy == handle->txState)
    {
        status = kStatus_LPSCI_TxBusy;
    }
    else
    {
        handle->txState       = kLPSCI_TxBusy;
        handle->txDataSizeAll = xfer->dataSize;

        /* Prepare transfer. */
        DMA_PrepareTransfer(&xferConfig, xfer->data, sizeof(uint8_t), (void *)LPSCI_GetDataRegisterAddress(base),
                            sizeof(uint8_t), xfer->dataSize, kDMA_MemoryToPeripheral);

        /* Submit transfer. */
        DMA_SubmitTransfer(handle->txDmaHandle, &xferConfig, kDMA_EnableInterrupt);
        DMA_StartTransfer(handle->txDmaHandle);

        /* Enable LPSCI TX DMA. */
        LPSCI_EnableTxDMA(base, true);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Receives data using DMA.
 *
 * This function receives data using DMA. This is a non-blocking function, which returns
 * immediately. When all data is received, the receive callback function is called.
 *
 * param handle Pointer to lpsci_dma_handle_t structure
 * param xfer LPSCI DMA transfer structure, see #lpsci_transfer_t.
 * retval kStatus_Success if successful, others failed.
 * retval kStatus_LPSCI_RxBusy Previous transfer on going.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPSCI_TransferReceiveDMA(UART0_Type *base, lpsci_dma_handle_t *handle, lpsci_transfer_t *xfer)
{
    assert(handle != NULL);
    assert(handle->rxDmaHandle != NULL);
    assert(xfer != NULL);
    assert(xfer->data != NULL);
    assert(xfer->dataSize != 0U);

    dma_transfer_config_t xferConfig;
    status_t status;

    /* If previous RX not finished. */
    if (kLPSCI_RxBusy == handle->rxState)
    {
        status = kStatus_LPSCI_RxBusy;
    }
    else
    {
        handle->rxState       = kLPSCI_RxBusy;
        handle->rxDataSizeAll = xfer->dataSize;

        /* Prepare transfer. */
        DMA_PrepareTransfer(&xferConfig, (void *)LPSCI_GetDataRegisterAddress(base), sizeof(uint8_t), xfer->data,
                            sizeof(uint8_t), xfer->dataSize, kDMA_PeripheralToMemory);

        /* Submit transfer. */
        DMA_SubmitTransfer(handle->rxDmaHandle, &xferConfig, kDMA_EnableInterrupt);
        DMA_StartTransfer(handle->rxDmaHandle);

        /* Enable LPSCI RX DMA. */
        LPSCI_EnableRxDMA(base, true);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the sent data using DMA.
 *
 * This function aborts the sent data using DMA.
 *
 * param handle Pointer to lpsci_dma_handle_t structure.
 */
void LPSCI_TransferAbortSendDMA(UART0_Type *base, lpsci_dma_handle_t *handle)
{
    assert(handle != NULL);
    assert(handle->txDmaHandle != NULL);

    /* Disable LPSCI TX DMA. */
    LPSCI_EnableTxDMA(base, false);

    /* Stop transfer. */
    DMA_AbortTransfer(handle->txDmaHandle);

    /* Write DMA->DSR[DONE] to abort transfer and clear status. */
    DMA_ClearChannelStatusFlags(handle->txDmaHandle->base, handle->txDmaHandle->channel, kDMA_TransactionsDoneFlag);

    handle->txState = kLPSCI_TxIdle;
}

/*!
 * brief Aborts the receive data using DMA.
 *
 * This function aborts the receive data using DMA.
 *
 * param handle Pointer to lpsci_dma_handle_t structure.
 */
void LPSCI_TransferAbortReceiveDMA(UART0_Type *base, lpsci_dma_handle_t *handle)
{
    assert(handle != NULL);
    assert(handle->rxDmaHandle != NULL);

    /* Disable LPSCI RX DMA. */
    LPSCI_EnableRxDMA(base, false);

    /* Stop transfer. */
    DMA_AbortTransfer(handle->rxDmaHandle);

    /* Write DMA->DSR[DONE] to abort transfer and clear status. */
    DMA_ClearChannelStatusFlags(handle->rxDmaHandle->base, handle->rxDmaHandle->channel, kDMA_TransactionsDoneFlag);

    handle->rxState = kLPSCI_RxIdle;
}

/*!
 * brief Gets the number of bytes written to the LPSCI TX register.
 *
 * This function gets the number of bytes that have been written to the LPSCI TX
 * register by DMA.
 *
 * param base LPSCI peripheral base address.
 * param handle LPSCI handle pointer.
 * param count Send bytes count.
 * retval kStatus_NoTransferInProgress No send in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPSCI_TransferGetSendCountDMA(UART0_Type *base, lpsci_dma_handle_t *handle, uint32_t *count)
{
    assert(handle != NULL);
    assert(handle->txDmaHandle != NULL);
    assert(count != NULL);

    if (kLPSCI_TxIdle == handle->txState)
    {
        return kStatus_NoTransferInProgress;
    }

    *count = handle->txDataSizeAll - DMA_GetRemainingBytes(handle->txDmaHandle->base, handle->txDmaHandle->channel);

    return kStatus_Success;
}

/*!
 * brief Gets the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * param base LPSCI peripheral base address.
 * param handle LPSCI handle pointer.
 * param count Receive bytes count.
 * retval kStatus_NoTransferInProgress No receive in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPSCI_TransferGetReceiveCountDMA(UART0_Type *base, lpsci_dma_handle_t *handle, uint32_t *count)
{
    assert(handle != NULL);
    assert(handle->rxDmaHandle != NULL);
    assert(count != NULL);

    if (kLPSCI_RxIdle == handle->rxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *count = handle->rxDataSizeAll - DMA_GetRemainingBytes(handle->rxDmaHandle->base, handle->rxDmaHandle->channel);

    return kStatus_Success;
}

static void LPSCI_TransferDMAHandleIRQ(UART0_Type *base, void *lpsciDmaHandle)
{
    assert(lpsciDmaHandle != NULL);
    lpsci_dma_handle_t *handle = (lpsci_dma_handle_t *)lpsciDmaHandle;

    /* Disable tx complete interrupt */
    LPSCI_DisableInterrupts(base, (uint32_t)kLPSCI_TransmissionCompleteInterruptEnable);
    handle->txState = kLPSCI_TxIdle;

    /* Invoke user callback */
    if (handle->callback)
    {
        handle->callback(base, handle, kStatus_LPSCI_TxIdle, handle->userData);
    }
}
