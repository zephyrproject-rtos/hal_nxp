/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpuart_gpdma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_lpuart_gpdma"
#endif

/*<! Structure definition for lpuart_gpdma_handle_t. The structure is private. */
typedef struct _lpuart_gpdma_private_handle
{
    LPUART_Type *base;
    lpuart_gpdma_handle_t *handle;
} lpuart_gpdma_private_handle_t;

/* LPUART GPDMA transfer handle. */
enum
{
    kLPUART_TxIdle, /* TX idle. */
    kLPUART_TxBusy, /* TX busy. */
    kLPUART_RxIdle, /* RX idle. */
    kLPUART_RxBusy  /* RX busy. */
};

#define LPUART_TX_ERR_INT ((uint32_t)kLPUART_TxFifoOverflowInterruptEnable)
#define LPUART_RX_ERR_INT ((uint32_t)kLPUART_RxOverrunInterruptEnable | \
    (uint32_t)kLPUART_NoiseErrorInterruptEnable | \
    (uint32_t)kLPUART_FramingErrorInterruptEnable | \
    (uint32_t)kLPUART_ParityErrorInterruptEnable  | \
    (uint32_t)kLPUART_RxFifoUnderflowInterruptEnable)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief LPUART GPDMA send finished callback function.
 *
 * This function is called when LPUART GPDMA send finished. It disables the LPUART
 * TX GPDMA request and sends @ref kStatus_LPUART_TxIdle to LPUART callback.
 *
 * @param handle The GPDMA handle.
 * @param param Callback function parameter.
 */
static void LPUART_TransferSendGPDMACallback(gpdma_handle_t *handle, void *param, uint32_t status);

/*!
 * @brief LPUART GPDMA receive finished callback function.
 *
 * This function is called when LPUART GPDMA receive finished. It disables the LPUART
 * RX GPDMA request and sends @ref kStatus_LPUART_RxIdle to LPUART callback.
 *
 * @param handle The GPDMA handle.
 * @param param Callback function parameter.
 */
static void LPUART_TransferReceiveGPDMACallback(gpdma_handle_t *handle, void *param, uint32_t status);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*<! Private handle only used for internally. */
static lpuart_gpdma_private_handle_t s_gpdmaPrivateHandle;

/*******************************************************************************
 * Code
 ******************************************************************************/

static void LPUART_TransferSendGPDMACallback(gpdma_handle_t *handle, void *param, uint32_t status)
{
    assert(handle != NULL);
    assert(param != NULL);

    lpuart_gpdma_private_handle_t *lpuartPrivateHandle = (lpuart_gpdma_private_handle_t *)param;

    /* Disable LPUART TX GPDMA. */
    LPUART_EnableTxGPDMA(lpuartPrivateHandle->base, false);

    /* Disable the error interrupts. */
    LPUART_DisableInterrupts(lpuartPrivateHandle->base, LPUART_TX_ERR_INT);

    /* Disable interrupt. */
    GPDMA_DisableChannelInterrupts(lpuartPrivateHandle->handle->txDmaHandle->base,
                                   lpuartPrivateHandle->handle->txDmaHandle->channel);

    lpuartPrivateHandle->handle->txState = (uint8_t)kLPUART_TxIdle;

    if (lpuartPrivateHandle->handle->callback != NULL)
    {
        lpuartPrivateHandle->handle->callback(lpuartPrivateHandle->base, lpuartPrivateHandle->handle,
                                              kStatus_LPUART_TxIdle, lpuartPrivateHandle->handle->userData);
    }
}

static void LPUART_TransferReceiveGPDMACallback(gpdma_handle_t *handle, void *param, uint32_t status)
{
    assert(handle != NULL);
    assert(param != NULL);

    lpuart_gpdma_private_handle_t *lpuartPrivateHandle = (lpuart_gpdma_private_handle_t *)param;

    /* Disable LPUART RX GPDMA. */
    LPUART_EnableRxGPDMA(lpuartPrivateHandle->base, false);

    /* Disable the error interrupts. */
    LPUART_DisableInterrupts(lpuartPrivateHandle->base, LPUART_RX_ERR_INT);

    /* Disable interrupt. */
    GPDMA_DisableChannelInterrupts(lpuartPrivateHandle->handle->rxDmaHandle->base,
                                   lpuartPrivateHandle->handle->rxDmaHandle->channel);

    lpuartPrivateHandle->handle->rxState = (uint8_t)kLPUART_RxIdle;

    if (lpuartPrivateHandle->handle->callback != NULL)
    {
        lpuartPrivateHandle->handle->callback(lpuartPrivateHandle->base, lpuartPrivateHandle->handle,
                                              kStatus_LPUART_RxIdle, lpuartPrivateHandle->handle->userData);
    }
}

/*!
 * brief Initializes the LPUART handle which is used in transactional functions.
 *
 * note This function disables all LPUART interrupts.
 *
 * param base LPUART peripheral base address.
 * param handle Pointer to lpuart_gpdma_handle_t structure.
 * param callback Callback function.
 * param userData User data.
 * param txDmaHandle User-requested GPDMA handle for TX GPDMA transfer.
 * param rxDmaHandle User-requested GPDMA handle for RX GPDMA transfer.
 */
void LPUART_TransferCreateHandleGPDMA(LPUART_Type *base,
                                      lpuart_gpdma_handle_t *handle,
                                      lpuart_gpdma_transfer_callback_t callback,
                                      void *userData,
                                      gpdma_handle_t *txDmaHandle,
                                      gpdma_handle_t *rxDmaHandle)
{
    assert(handle != NULL);

    (void)memset(handle, 0, sizeof(lpuart_gpdma_handle_t));

    s_gpdmaPrivateHandle.base   = base;
    s_gpdmaPrivateHandle.handle = handle;

    handle->rxState = (uint8_t)kLPUART_RxIdle;
    handle->txState = (uint8_t)kLPUART_TxIdle;

    handle->callback = callback;
    handle->userData = userData;

#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
    /* Note:
       Take care of the RX FIFO, GPDMA request only assert when received bytes
       equal or more than RX water mark, there is potential issue if RX water
       mark larger than 1.
       For example, if RX FIFO water mark is 2, upper layer needs 5 bytes and
       5 bytes are received. the last byte will be saved in FIFO but not trigger
       GPDMA transfer because the water mark is 2.
     */
    if (rxDmaHandle != NULL)
    {
        base->WATER &= (~LPUART_WATER_RXWATER_MASK);
    }
#endif

    handle->rxDmaHandle = rxDmaHandle;
    handle->txDmaHandle = txDmaHandle;

    /* Disable all LPUART internal interrupts */
    LPUART_DisableInterrupts(base, (uint32_t)kLPUART_AllInterruptEnable);

    /* Configure TX. */
    if (txDmaHandle != NULL)
    {
        GPDMA_SetCallback(txDmaHandle, LPUART_TransferSendGPDMACallback, &s_gpdmaPrivateHandle);
    }

    /* Configure RX. */
    if (rxDmaHandle != NULL)
    {
        GPDMA_SetCallback(rxDmaHandle, LPUART_TransferReceiveGPDMACallback, &s_gpdmaPrivateHandle);
    }
}

/*!
 * brief Sends data using GPDMA.
 *
 * This function sends data using GPDMA. This is a non-blocking function, which returns
 * right away. When all data is sent, the send callback function is called.
 *
 * param base LPUART peripheral base address.
 * param handle LPUART handle pointer.
 * param xfer LPUART GPDMA transfer structure.
 * retval kStatus_Success if succeed, others failed.
 * retval kStatus_LPUART_TxBusy Previous transfer on going.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPUART_TransferSendGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle, lpuart_data_t *xfer)
{
    assert(handle != NULL);
    assert(handle->txDmaHandle != NULL);
    assert(xfer != NULL);
    assert(xfer->data != NULL);
    assert(xfer->bufferSize != 0U);

    status_t status;
    gpdma_transfer_config_t xferConfig;

    /* If previous TX not finished. */
    if ((uint8_t)kLPUART_TxBusy == handle->txState)
    {
        status = kStatus_LPUART_TxBusy;
    }
    else
    {
        handle->txState       = (uint8_t)kLPUART_TxBusy;
        handle->txDataSizeAll = xfer->bufferSize;

        /* Prepare transfer. */
        uint32_t address = LPUART_GetDataRegisterAddress(base);
        GPDMA_PrepareTransferConfig(&xferConfig, xfer->data, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                    (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                    xfer->bufferSize, kGPDMA_TransferM2PControllerDma, 0UL);
        /* Submit transfer. */
        (void)GPDMA_SubmitTransfer(handle->txDmaHandle, &xferConfig);

        LPUART_EnableTxGPDMA(base, true);
        LPUART_EnableTx(base, true);

        /* Enable the error interrupts. */
        LPUART_EnableInterrupts(base, LPUART_TX_ERR_INT);

        GPDMA_StartTransfer(handle->txDmaHandle);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Receives data using GPDMA.
 *
 * This function receives data using GPDMA. This is a non-blocking function, which returns
 * right away. When all data is received, the receive callback function is called.
 *
 * param base LPUART peripheral base address.
 * param handle Pointer to lpuart_gpdma_handle_t structure.
 * param xfer LPUART GPDMA transfer structure.
 * retval kStatus_Success if succeed, others failed.
 * retval kStatus_LPUART_RxBusy Previous transfer on going.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPUART_TransferReceiveGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle, lpuart_data_t *xfer)
{
    assert(handle != NULL);
    assert(handle->rxDmaHandle != NULL);
    assert(xfer != NULL);
    assert(xfer->data != NULL);
    assert(xfer->bufferSize != 0U);

    status_t status;
    gpdma_transfer_config_t xferConfig;

    /* If previous RX not finished. */
    if ((uint8_t)kLPUART_RxBusy == handle->rxState)
    {
        status = kStatus_LPUART_RxBusy;
    }
    else
    {
        handle->rxState       = (uint8_t)kLPUART_RxBusy;
        handle->rxDataSizeAll = xfer->bufferSize;

        /* Prepare transfer. */
        uint32_t address = LPUART_GetDataRegisterAddress(base);
        GPDMA_PrepareTransferConfig(&xferConfig, (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                    xfer->data, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes, xfer->bufferSize,
                                    kGPDMA_TransferP2MControllerDma, 0UL);
        /* Submit transfer. */
        (void)GPDMA_SubmitTransfer(handle->rxDmaHandle, &xferConfig);

        LPUART_EnableRxGPDMA(base, true);
        LPUART_EnableRx(base, true);

        /* Enable the error interrupts. */
        LPUART_EnableInterrupts(base, LPUART_RX_ERR_INT);

        GPDMA_StartTransfer(handle->rxDmaHandle);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the sent data using GPDMA.
 *
 * This function aborts send data using GPDMA.
 *
 * param base LPUART peripheral base address
 * param handle Pointer to lpuart_gpdma_handle_t structure
 */
void LPUART_TransferAbortSendGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle)
{
    assert(handle != NULL);
    assert(handle->txDmaHandle != NULL);

    /* Disable LPUART TX GPDMA. */
    LPUART_EnableTxGPDMA(base, false);

    /* Disable the error interrupts. */
    LPUART_DisableInterrupts(base, LPUART_TX_ERR_INT);

    /* Stop transfer. */
    GPDMA_AbortTransfer(handle->txDmaHandle);

    /* Write GPDMA->DSR[DONE] to abort transfer and clear status. */
    GPDMA_ClearChannelStatus(handle->txDmaHandle->base, handle->txDmaHandle->channel,
                             kGPDMA_StatusClearInterruptTerminalCountRequest);

    handle->txState = (uint8_t)kLPUART_TxIdle;
}

/*!
 * brief Aborts the received data using GPDMA.
 *
 * This function aborts the received data using GPDMA.
 *
 * param base LPUART peripheral base address
 * param handle Pointer to lpuart_gpdma_handle_t structure
 */
void LPUART_TransferAbortReceiveGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle)
{
    assert(handle != NULL);
    assert(handle->rxDmaHandle != NULL);

    /* Disable LPUART RX GPDMA. */
    LPUART_EnableRxGPDMA(base, false);

    /* Disable the error interrupts. */
    LPUART_DisableInterrupts(base, LPUART_RX_ERR_INT);

    /* Stop transfer. */
    GPDMA_AbortTransfer(handle->rxDmaHandle);

    /* Write GPDMA->DSR[DONE] to abort transfer and clear status. */
    GPDMA_ClearChannelStatus(handle->rxDmaHandle->base, handle->rxDmaHandle->channel,
                             kGPDMA_StatusClearInterruptTerminalCountRequest);

    handle->rxState = (uint8_t)kLPUART_RxIdle;
}
