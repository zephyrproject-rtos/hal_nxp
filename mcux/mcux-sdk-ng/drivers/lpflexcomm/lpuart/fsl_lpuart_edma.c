/*
 * Copyright 2022, 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpuart_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpflexcomm_lpuart_edma"
#endif

/*<! Structure definition for lpuart_edma_private_handle_t. The structure is private. */
typedef struct _lpuart_edma_private_handle
{
    LPUART_Type *base;
    lpuart_edma_handle_t *handle;
} lpuart_edma_private_handle_t;

/* LPUART EDMA transfer handle. */
enum
{
    kLPUART_TxIdle, /* TX idle. */
    kLPUART_TxBusy, /* TX busy. */
    kLPUART_RxIdle, /* RX idle. */
    kLPUART_RxBusy  /* RX busy. */
};

typedef union lpuart_to_lpflexcomm_edma
{
    lpuart_irq_handler_t lpuart_handler;
    lpflexcomm_irq_handler_t lpflexcomm_handler;
} lpuart_to_lpflexcomm_edma_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Array of LPUART peripheral base address. */
static LPUART_Type *const s_lpuartBases[] = LPUART_BASE_PTRS;

/*<! Private handle only used for internally. */
static lpuart_edma_private_handle_t s_lpuartEdmaPrivateHandle[ARRAY_SIZE(s_lpuartBases)];

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief LPUART EDMA send finished callback function.
 *
 * This function is called when LPUART EDMA send finished. It disables the LPUART
 * TX EDMA request and sends @ref kStatus_LPUART_TxIdle to LPUART callback.
 *
 * @param handle The EDMA handle.
 * @param param Callback function parameter.
 */
static void LPUART_SendEDMACallback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

/*!
 * @brief LPUART EDMA receive finished callback function.
 *
 * This function is called when LPUART EDMA receive finished. It disables the LPUART
 * RX EDMA request and sends @ref kStatus_LPUART_RxIdle to LPUART callback.
 *
 * @param handle The EDMA handle.
 * @param param Callback function parameter.
 */
static void LPUART_ReceiveEDMACallback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

/*******************************************************************************
 * Code
 ******************************************************************************/

static void LPUART_SendEDMACallback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    assert(NULL != param);

    lpuart_edma_private_handle_t *lpuartPrivateHandle = (lpuart_edma_private_handle_t *)param;

    /* Avoid the warning for unused variables. */
    handle = handle;
    tcds   = tcds;

    if (transferDone)
    {
        /* Disable LPUART TX EDMA. */
        LPUART_EnableTxDMA(lpuartPrivateHandle->base, false);

        /* Stop transfer. */
        EDMA_AbortTransfer(handle);

        if (lpuartPrivateHandle->handle->txCbMode == kLPUART_TxFifoEmpty)
        {
            /* Enable tx complete interrupt */
            LPUART_EnableInterrupts(lpuartPrivateHandle->base, (uint32_t)kLPUART_TransmissionCompleteInterruptEnable);
        }
        else
        {
            /* kLPUART_TxEdmaComplete */
            lpuartPrivateHandle->handle->txState = (uint8_t)kLPUART_TxIdle;

            if (NULL != lpuartPrivateHandle->handle->callback)
            {
                lpuartPrivateHandle->handle->callback(lpuartPrivateHandle->base, lpuartPrivateHandle->handle,
                                                      kStatus_LPUART_TxIdle, lpuartPrivateHandle->handle->userData);
            }
        }
    }
}

static void LPUART_ReceiveEDMACallback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    assert(NULL != param);

    lpuart_edma_private_handle_t *lpuartPrivateHandle = (lpuart_edma_private_handle_t *)param;

    /* Avoid warning for unused parameters. */
    handle = handle;
    tcds   = tcds;

    if (lpuartPrivateHandle->handle->oneFifoBlockRxWatermark > -1)
    {
        LPUART_SetRxFifoWatermark(lpuartPrivateHandle->base, (uint8_t)lpuartPrivateHandle->handle->oneFifoBlockRxWatermark);
        lpuartPrivateHandle->handle->oneFifoBlockRxWatermark = -1;
        return;
    }

    if (transferDone)
    {
        /* Disable transfer. */
        LPUART_TransferAbortReceiveEDMA(lpuartPrivateHandle->base, lpuartPrivateHandle->handle);

        if (NULL != lpuartPrivateHandle->handle->callback)
        {
            lpuartPrivateHandle->handle->callback(lpuartPrivateHandle->base, lpuartPrivateHandle->handle,
                                                  kStatus_LPUART_RxIdle, lpuartPrivateHandle->handle->userData);
        }
    }
}

/*!
 * brief Initializes the LPUART handle which is used in transactional functions.
 *
 * note This function disables all LPUART interrupts.
 *
 * param base LPUART peripheral base address.
 * param handle Pointer to lpuart_edma_handle_t structure.
 * param callback Callback function.
 * param userData User data.
 * param txEdmaHandle User requested DMA handle for TX DMA transfer.
 * param rxEdmaHandle User requested DMA handle for RX DMA transfer.
 */
void LPUART_TransferCreateHandleEDMA(LPUART_Type *base,
                                     lpuart_edma_handle_t *handle,
                                     lpuart_edma_transfer_callback_t callback,
                                     void *userData,
                                     edma_handle_t *txEdmaHandle,
                                     edma_handle_t *rxEdmaHandle)
{
    LPUART_TransferCreateHandleEDMAExt(base, handle, callback, userData, txEdmaHandle, rxEdmaHandle, kLPUART_TxFifoEmpty);
}

void LPUART_TransferCreateHandleEDMAExt(LPUART_Type *base,
                                     lpuart_edma_handle_t *handle,
                                     lpuart_edma_transfer_callback_t callback,
                                     void *userData,
                                     edma_handle_t *txEdmaHandle,
                                     edma_handle_t *rxEdmaHandle,
                                     lpuart_tx_callback_mode_t txCbMode)
{
    assert(NULL != handle);

    uint32_t instance = LPUART_GetInstance(base);
    lpuart_to_lpflexcomm_edma_t handler;

    s_lpuartEdmaPrivateHandle[instance].base   = base;
    s_lpuartEdmaPrivateHandle[instance].handle = handle;

    (void)memset(handle, 0, sizeof(*handle));

    handle->rxState = (uint8_t)kLPUART_RxIdle;
    handle->txState = (uint8_t)kLPUART_TxIdle;

    handle->rxEdmaHandle = rxEdmaHandle;
    handle->txEdmaHandle = txEdmaHandle;

    handle->callback = callback;
    handle->userData = userData;

    handle->txCbMode = txCbMode;

    if (handle->txCbMode == kLPUART_TxFifoEmpty)
    {
        handler.lpuart_handler = LPUART_TransferEdmaHandleIRQ;
        /* Save the handle in global variables to support the double weak mechanism. */
        LP_FLEXCOMM_SetIRQHandler(instance, handler.lpflexcomm_handler, handle, LP_FLEXCOMM_PERIPH_LPUART);
        /* Disable all LPUART internal interrupts */
        LPUART_DisableInterrupts(base, (uint32_t)kLPUART_AllInterruptEnable);
        /* Enable interrupt in NVIC. */
#if defined(FSL_FEATURE_LPUART_HAS_SEPARATE_RX_TX_IRQ) && FSL_FEATURE_LPUART_HAS_SEPARATE_RX_TX_IRQ
        (void)EnableIRQ(s_lpuartTxIRQ[instance]);
#else
        (void)EnableIRQ(s_lpuartIRQ[instance]);
#endif
    }

    /* Configure TX. */
    if (NULL != txEdmaHandle)
    {
        EDMA_SetCallback(handle->txEdmaHandle, LPUART_SendEDMACallback, &s_lpuartEdmaPrivateHandle[instance]);
    }

    /* Configure RX. */
    if (NULL != rxEdmaHandle)
    {
        EDMA_SetCallback(handle->rxEdmaHandle, LPUART_ReceiveEDMACallback, &s_lpuartEdmaPrivateHandle[instance]);
    }
}

/*!
 * brief Sends data using eDMA.
 *
 * This function sends data using eDMA. This is a non-blocking function, which returns
 * right away. When all data is sent, the send callback function is called.
 *
 * param base LPUART peripheral base address.
 * param handle LPUART handle pointer.
 * param xfer LPUART eDMA transfer structure. See #lpuart_transfer_t.
 * retval kStatus_Success if succeed, others failed.
 * retval kStatus_LPUART_TxBusy Previous transfer on going.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPUART_SendEDMA(LPUART_Type *base, lpuart_edma_handle_t *handle, lpuart_transfer_t *xfer)
{
    assert(NULL != handle);
    assert(NULL != handle->txEdmaHandle);
    assert(NULL != xfer);
    assert(NULL != xfer->data);
    assert(0U != xfer->dataSize);
    assert(FSL_FEATURE_LPUART_FIFO_SIZEn(base) >= 8);

    edma_transfer_config_t transferConfigTx = {0};
    status_t status;

    /* If previous TX not finished. */
    if ((uint8_t)kLPUART_TxBusy == handle->txState)
    {
        status = kStatus_LPUART_TxBusy;
    }
    else
    {
        handle->txState       = (uint8_t)kLPUART_TxBusy;
        handle->txDataSizeAll = xfer->dataSize;
        handle->txData        = xfer->txData;

        uint32_t txAddr = LPUART_GetDataRegisterAddress(base);

        edma_tcd_t *softwareTCD_oneFifoBlockTx = (edma_tcd_t *)((uint32_t)(&handle->edmaTcd[1]) & ~(EDMA_TCD_ALIGN_SIZE - 1U));
        edma_tcd_t *nextTcd = NULL;

        /* Count of blocks aligned to 4 FIFO words */
        uint32_t fourFifoBlocks = xfer->dataSize / 4U;
        assert(fourFifoBlocks <= (DMA_CITER_ELINKNO_CITER_MASK >> DMA_CITER_ELINKNO_CITER_SHIFT));

        /* Count of blocks aligned to 1 FIFO words */
        uint32_t oneFifoBlocks = xfer->dataSize % 4U;

        LPUART_SetTxFifoWatermark(base, 4U);

        EDMA_ResetChannel(handle->txEdmaHandle->base, handle->txEdmaHandle->channel);

        if (oneFifoBlocks > 0U)
        {
            /* Transfer config for remaining FIFO words (1-3) */
            transferConfigTx.srcAddr   = (uint32_t)xfer->txData + xfer->dataSize - oneFifoBlocks;
            transferConfigTx.srcOffset = 1;

            transferConfigTx.destAddr         = (uint32_t)txAddr;
            transferConfigTx.destOffset       = 0;
            transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
            transferConfigTx.destTransferSize = kEDMA_TransferSize1Bytes;
            transferConfigTx.minorLoopBytes   = oneFifoBlocks;
            transferConfigTx.majorLoopCounts  = 1U;

            if (fourFifoBlocks > 0U)
            {
                EDMA_TcdResetExt(handle->txEdmaHandle->base, softwareTCD_oneFifoBlockTx);
                EDMA_TcdSetTransferConfigExt(handle->txEdmaHandle->base, softwareTCD_oneFifoBlockTx,
                                            &transferConfigTx, nextTcd);
                EDMA_TcdEnableInterruptsExt(handle->txEdmaHandle->base, softwareTCD_oneFifoBlockTx,
                                            (uint32_t)kEDMA_MajorInterruptEnable);

                nextTcd = softwareTCD_oneFifoBlockTx;
            }
            else
            {
                EDMA_SetTransferConfig(handle->txEdmaHandle->base, handle->txEdmaHandle->channel,
                                    &transferConfigTx, nextTcd);

                /* Enable eDMA interrupt to finish transfer */
                EDMA_EnableChannelInterrupts(handle->txEdmaHandle->base,
                                            handle->txEdmaHandle->channel,
                                            (uint32_t)kEDMA_MajorInterruptEnable);
            }
        }

        if (fourFifoBlocks > 0U)
        {
            /* Transfer config for part of data aligned to 4 FIFO entry */
            transferConfigTx.srcAddr   = (uint32_t)xfer->txData;
            transferConfigTx.srcOffset = 1;

            transferConfigTx.destAddr         = (uint32_t)txAddr;
            transferConfigTx.destOffset       = 0;
            transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
            transferConfigTx.destTransferSize = kEDMA_TransferSize1Bytes;
            transferConfigTx.minorLoopBytes   = 4U;
            transferConfigTx.majorLoopCounts  = fourFifoBlocks;

            EDMA_SetTransferConfig(handle->txEdmaHandle->base, handle->txEdmaHandle->channel,
                                &transferConfigTx, nextTcd);

            if (oneFifoBlocks == 0U)
            {
                /* Enable eDMA interrupt to finish transfer */
                EDMA_EnableChannelInterrupts(handle->txEdmaHandle->base,
                                            handle->txEdmaHandle->channel,
                                            (uint32_t)kEDMA_MajorInterruptEnable);
            }
        }

        EDMA_StartTransfer(handle->txEdmaHandle);

        /* Enable LPUART TX EDMA. */
        LPUART_EnableTxDMA(base, true);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Receives data using eDMA.
 *
 * This function receives data using eDMA. This is non-blocking function, which returns
 * right away. When all data is received, the receive callback function is called.
 *
 * param base LPUART peripheral base address.
 * param handle Pointer to lpuart_edma_handle_t structure.
 * param xfer LPUART eDMA transfer structure, see #lpuart_transfer_t.
 * retval kStatus_Success if succeed, others fail.
 * retval kStatus_LPUART_RxBusy Previous transfer ongoing.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPUART_ReceiveEDMA(LPUART_Type *base, lpuart_edma_handle_t *handle, lpuart_transfer_t *xfer)
{
    assert(NULL != handle);
    assert(NULL != handle->rxEdmaHandle);
    assert(NULL != xfer);
    assert(NULL != xfer->data);
    assert(0U != xfer->dataSize);

    edma_transfer_config_t transferConfigRx = {0};
    status_t status;

    /* If previous RX not finished. */
    if ((uint8_t)kLPUART_RxBusy == handle->rxState)
    {
        status = kStatus_LPUART_RxBusy;
    }
    else
    {
        handle->rxState       = (uint8_t)kLPUART_RxBusy;
        handle->rxDataSizeAll = xfer->dataSize;
        handle->rxData        = xfer->rxData;

        handle->oneFifoBlockRxWatermark = -1;

        uint32_t rxAddr = LPUART_GetDataRegisterAddress(base);

        edma_tcd_t *softwareTCD_oneFifoBlockRx  = (edma_tcd_t *)((uint32_t)(&handle->edmaTcd[2]) & ~(EDMA_TCD_ALIGN_SIZE - 1U));
        edma_tcd_t *nextTcd                     = NULL;

        /* Count of blocks aligned to 4 FIFO words */
        uint32_t fourFifoBlocks = xfer->dataSize / 4U;
        assert(fourFifoBlocks <= (DMA_CITER_ELINKNO_CITER_MASK >> DMA_CITER_ELINKNO_CITER_SHIFT));

        /* Count of blocks aligned to 1 FIFO words */
        uint32_t oneFifoBlocks = xfer->dataSize % 4U;

        EDMA_ResetChannel(handle->rxEdmaHandle->base, handle->rxEdmaHandle->channel);

        if (oneFifoBlocks > 0U)
        {
            /* Transfer config for remaining FIFO words (1-3) */
            transferConfigRx.srcAddr   = rxAddr;
            transferConfigRx.srcOffset = 0;

            transferConfigRx.destAddr   = (uint32_t)xfer->rxData + xfer->dataSize - oneFifoBlocks;
            transferConfigRx.destOffset = 1;

            transferConfigRx.srcTransferSize  = kEDMA_TransferSize1Bytes;
            transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
            transferConfigRx.minorLoopBytes   = oneFifoBlocks;
            transferConfigRx.majorLoopCounts  = 1U;

            if (fourFifoBlocks > 0U)
            {
                EDMA_TcdResetExt(handle->rxEdmaHandle->base, softwareTCD_oneFifoBlockRx);
                EDMA_TcdSetTransferConfigExt(handle->rxEdmaHandle->base, softwareTCD_oneFifoBlockRx,
                                            &transferConfigRx, nextTcd);
                EDMA_TcdEnableInterruptsExt(handle->rxEdmaHandle->base, softwareTCD_oneFifoBlockRx,
                                            (uint32_t)kEDMA_MajorInterruptEnable);

                nextTcd = softwareTCD_oneFifoBlockRx;
            }
            else
            {
                EDMA_SetTransferConfig(handle->rxEdmaHandle->base, handle->rxEdmaHandle->channel,
                                    &transferConfigRx, nextTcd);

                /* Enable edma interrupt to finish transfer */
                EDMA_EnableChannelInterrupts(handle->rxEdmaHandle->base,
                                            handle->rxEdmaHandle->channel,
                                            (uint32_t)kEDMA_MajorInterruptEnable);

                LPUART_SetRxFifoWatermark(base, (uint8_t)oneFifoBlocks - 1U);
            }
        }

        if (fourFifoBlocks > 0U)
        {
            /* Transfer config for part of data aligned to 4 FIFO entry */
            transferConfigRx.srcAddr   = (uint32_t)rxAddr;
            transferConfigRx.srcOffset = 0;

            transferConfigRx.destAddr   = (uint32_t)xfer->rxData;
            transferConfigRx.destOffset = 1;

            transferConfigRx.srcTransferSize  = kEDMA_TransferSize1Bytes;
            transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
            transferConfigRx.minorLoopBytes   = 4U;
            transferConfigRx.majorLoopCounts  = fourFifoBlocks;

            if (oneFifoBlocks > 0U)
            {
                /* Set value of RX FIFO watermark for next part of data, used in LPUART_ReceiveEDMACallback() */
                handle->oneFifoBlockRxWatermark = (int8_t)oneFifoBlocks - 1;
            }

            EDMA_SetTransferConfig(handle->rxEdmaHandle->base, handle->rxEdmaHandle->channel,
                                &transferConfigRx, nextTcd);

            /* Enable eDMA interrupt to finish transfer or change RX FIFO watermark */
            EDMA_EnableChannelInterrupts(handle->rxEdmaHandle->base, handle->rxEdmaHandle->channel,
                                        (uint32_t)kEDMA_MajorInterruptEnable);

            /* Configure RX FIFO watermark to be possible read 4 FIFO entry per each DMA request */
            LPUART_SetRxFifoWatermark(base, 3U);
        }

        EDMA_StartTransfer(handle->rxEdmaHandle);

        /* Enable LPUART RX EDMA. */
        LPUART_EnableRxDMA(base, true);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the sent data using eDMA.
 *
 * This function aborts the sent data using eDMA.
 *
 * param base LPUART peripheral base address.
 * param handle Pointer to lpuart_edma_handle_t structure.
 */
void LPUART_TransferAbortSendEDMA(LPUART_Type *base, lpuart_edma_handle_t *handle)
{
    assert(NULL != handle);
    assert(NULL != handle->txEdmaHandle);

    /* Disable LPUART TX EDMA. */
    LPUART_EnableTxDMA(base, false);

    /* Stop transfer. */
    EDMA_AbortTransfer(handle->txEdmaHandle);

    handle->txState = (uint8_t)kLPUART_TxIdle;
}

/*!
 * brief Aborts the received data using eDMA.
 *
 * This function aborts the received data using eDMA.
 *
 * param base LPUART peripheral base address.
 * param handle Pointer to lpuart_edma_handle_t structure.
 */
void LPUART_TransferAbortReceiveEDMA(LPUART_Type *base, lpuart_edma_handle_t *handle)
{
    assert(NULL != handle);
    assert(NULL != handle->rxEdmaHandle);

    /* Disable LPUART RX EDMA. */
    LPUART_EnableRxDMA(base, false);

    /* Stop transfer. */
    EDMA_AbortTransfer(handle->rxEdmaHandle);

    handle->rxState = (uint8_t)kLPUART_RxIdle;
}

/*!
 * brief Gets the number of received bytes.
 *
 * This function gets the number of received bytes.
 *
 * param base LPUART peripheral base address.
 * param handle LPUART handle pointer.
 * param count Receive bytes count.
 * retval kStatus_NoTransferInProgress No receive in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPUART_TransferGetReceiveCountEDMA(LPUART_Type *base, lpuart_edma_handle_t *handle, uint32_t *count)
{
    assert(NULL != handle);
    assert(NULL != handle->rxEdmaHandle);
    assert(NULL != count);

    if ((uint8_t)kLPUART_RxIdle == handle->rxState)
    {
        return kStatus_NoTransferInProgress;
    }

    uint32_t tcdDaddr = EDMA_TCD_DADDR(handle->rxEdmaHandle->tcdBase, EDMA_TCD_TYPE(handle->rxEdmaHandle->base));
    *count = tcdDaddr - (uint32_t)handle->rxData;

    return kStatus_Success;
}

/*!
 * brief Gets the number of bytes written to the LPUART TX register.
 *
 * This function gets the number of bytes written to the LPUART TX
 * register by DMA.
 *
 * param base LPUART peripheral base address.
 * param handle LPUART handle pointer.
 * param count Send bytes count.
 * retval kStatus_NoTransferInProgress No send in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPUART_TransferGetSendCountEDMA(LPUART_Type *base, lpuart_edma_handle_t *handle, uint32_t *count)
{
    assert(NULL != handle);
    assert(NULL != handle->txEdmaHandle);
    assert(NULL != count);

    if ((uint8_t)kLPUART_TxIdle == handle->txState)
    {
        return kStatus_NoTransferInProgress;
    }

    /* eDMA transfer can be done, but data can be in TX FIFO and shift register */
    if (DMA_GET_DONE_STATUS(handle->txEdmaHandle->base, handle->txEdmaHandle->channel) != 0U)
    {
        return kStatus_NoTransferInProgress;
    }
    else
    {
        uint32_t tcdSaddr = EDMA_TCD_SADDR(handle->txEdmaHandle->tcdBase, EDMA_TCD_TYPE(handle->txEdmaHandle->base));
        *count = tcdSaddr - (uint32_t)handle->txData;
    }

    return kStatus_Success;
}

/*!
 * brief LPUART eDMA IRQ handle function.
 *
 * This function handles the LPUART tx complete IRQ request and invoke user callback.
 * It is not set to static so that it can be used in user application.
 * note This function is used as default IRQ handler by double weak mechanism.
 * If user's specific IRQ handler is implemented, make sure this function is invoked in the handler.
 *
 * param instance LPUART peripheral index.
 * param lpuartEdmaHandle LPUART handle pointer.
 */
void LPUART_TransferEdmaHandleIRQ(uint32_t instance, void *lpuartEdmaHandle)
{
    assert(lpuartEdmaHandle != NULL);
    assert(instance < ARRAY_SIZE(s_lpuartBases));
    LPUART_Type *base = s_lpuartBases[instance];

    if (((uint32_t)kLPUART_TransmissionCompleteFlag & LPUART_GetStatusFlags(base)) != 0U)
    {
        lpuart_edma_handle_t *handle = (lpuart_edma_handle_t *)lpuartEdmaHandle;

        /* Disable tx complete interrupt */
        LPUART_DisableInterrupts(base, (uint32_t)kLPUART_TransmissionCompleteInterruptEnable);

        handle->txState = (uint8_t)kLPUART_TxIdle;

        if (handle->callback != NULL)
        {
            handle->callback(base, handle, kStatus_LPUART_TxIdle, handle->userData);
        }
    }
}
