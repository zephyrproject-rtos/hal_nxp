/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qsci_dma.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qsci_dma"
#endif

/* QSCI transfer state. */
enum
{
    kQSCI_TxIdle, /* TX idle. */
    kQSCI_TxBusy, /* TX busy. */
    kQSCI_RxIdle, /* RX idle. */
    kQSCI_RxBusy  /* RX busy. */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief QSCI DMA send finished callback function.
 *
 * This function is called when QSCI DMA send finished. It disables the QSCI
 * TX DMA request and passes @ref kStatus_QSCI_TxIdle to QSCI callback.
 *
 * @param psHandle  The DMA handle.
 * @param pUserData Pointer to qsci_dma_transfer_handle_t.
 */
static void QSCI_TransferSendDMACallback(dma_handle_t *psHandle, void *pUserData);

/*!
 * @brief QSCI DMA receive finished callback function.
 *
 * This function is called when QSCI DMA receive finished. It disables the QSCI
 * RX DMA request and passes @ref kStatus_QSCI_RxIdle to QSCI callback.
 *
 * @param psHandle The DMA handle.
 * @param pUserData Pointer to qsci_dma_transfer_handle_t.
 */
static void QSCI_TransferReceiveDMACallback(dma_handle_t *psHandle, void *pUserData);

/*******************************************************************************
 * Code
 ******************************************************************************/

static void QSCI_TransferSendDMACallback(dma_handle_t *psHandle, void *pUserData)
{
    assert(NULL != pUserData);

    qsci_dma_transfer_handle_t *psQsciDmaHandle = (qsci_dma_transfer_handle_t *)pUserData;

    /* Avoid the warning for unused variables. */
    psHandle = psHandle;

    QSCI_TransferAbortSendDMA(psQsciDmaHandle);

    /* Ensure all the data in the transmit buffer are sent out to bus. */
    while (0U == (QSCI_GetStatusFlags(psQsciDmaHandle->base) & (uint16_t)kQSCI_TxIdleFlag))
    {
    }

    psQsciDmaHandle->busStatus = kStatus_QSCI_TxIdle;
    if (NULL != psQsciDmaHandle->pfCallback)
    {
        psQsciDmaHandle->pfCallback(psQsciDmaHandle);
    }
}

static void QSCI_TransferReceiveDMACallback(dma_handle_t *psHandle, void *pUserData)
{
    assert(NULL != pUserData);

    qsci_dma_transfer_handle_t *psQsciDmaHandle = (qsci_dma_transfer_handle_t *)pUserData;

    /* Avoid warning for unused pUserDataeters. */
    psHandle = psHandle;

    /* Disable transfer. */
    QSCI_TransferAbortReceiveDMA(psQsciDmaHandle);

    psQsciDmaHandle->busStatus = kStatus_QSCI_RxIdle;
    if (NULL != psQsciDmaHandle->pfCallback)
    {
        psQsciDmaHandle->pfCallback(psQsciDmaHandle);
    }
}

/*!
 * brief Initializes the QSCI dma handle.
 *
 * This function initializes the QSCI dma handle which can be used for other QSCI transactional APIs. Usually, for a
 * specified QSCI instance, call this API once to get the initialized handle.
 *
 * param base QSCI peripheral base address.
 * param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 * param pfCallback Callback function.
 * param pUserData User data.
 * param dmaBase DMA base address.
 * param dmaTxChannel DMA channel for TX transfer.
 * param dmaRxChannel DMA channel for RX transfer.
 */
void QSCI_TransferCreateHandleDMA(QSCI_Type *base,
                                  qsci_dma_transfer_handle_t *psHandle,
                                  qsci_dma_transfer_callback_t pfCallback,
                                  void *pUserData,
                                  DMA_Type *dmaBase,
                                  dma_channel_t dmaTxChannel,
                                  dma_channel_t dmaRxChannel)
{
    assert(NULL != psHandle);
    /* Zero the handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    psHandle->base      = base;
    psHandle->u8RxState = (uint8_t)kQSCI_RxIdle;
    psHandle->u8TxState = (uint8_t)kQSCI_TxIdle;

    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    /* Disable fifo */
    base->CTRL2 &= ~QSCI_CTRL2_FIFO_EN_MASK;

    /* Configure TX. */
    DMA_TransferChannelCreateHandle(dmaBase, &psHandle->sTxDmaHandle, dmaTxChannel, QSCI_TransferSendDMACallback,
                                    psHandle);
    /* Configure RX. */
    DMA_TransferChannelCreateHandle(dmaBase, &psHandle->sRxDmaHandle, dmaRxChannel, QSCI_TransferReceiveDMACallback,
                                    psHandle);
}

/*!
 * brief Initiate data transmit using DMA.
 *
 * This function initiates a data transmit process using DMA. This is a non-blocking function, which returns
 * right away. When all the data is sent, the send callback function is called.
 *
 * param psHandle QSCI handle pointer.
 * param psTransfer QSCI DMA transfer structure. See #qsci_transfer_t.
 * retval kStatus_Success if succeed, others failed.
 * retval kStatus_QSCI_TxBusy Previous transfer on going.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferSendDMA(qsci_dma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer)
{
    assert(NULL != psHandle);
    assert(NULL != psTransfer);
    assert(NULL != psTransfer->pu8Data);
    assert(0U != psTransfer->u32DataSize);

    status_t status;

    /* If previous TX not finished. */
    if ((uint8_t)kQSCI_TxBusy == psHandle->u8TxState)
    {
        status = kStatus_QSCI_TxBusy;
    }
    else
    {
        psHandle->u8TxState        = (uint8_t)kQSCI_TxBusy;
        psHandle->u32TxDataSizeAll = psTransfer->u32DataSize;

        dma_channel_transfer_config_t sTransmitConfig;
        uint32_t u32SrcByteAddr  = (uint32_t)(uint8_t *)(psTransfer->pu8Data);
        uint32_t u32DestByteAddr = QSCI_GetDataRegisterAddress(psHandle->base);

        DMA_GetChannelDefaultTransferConfig(&sTransmitConfig, u32SrcByteAddr, u32DestByteAddr, psTransfer->u32DataSize,
                                            kDMA_ChannelTransferWidth8Bits, kDMA_ChannelTransferMemoryToPeripheral);
        sTransmitConfig.bEnableCycleSteal = true;
        (void)DMA_TransferChannelSubmit(&psHandle->sTxDmaHandle, &sTransmitConfig);
        (void)DMA_TransferChannelStart(&psHandle->sTxDmaHandle, true);
        /* Enable QSCI TX DMA. */
        QSCI_EnableTx(psHandle->base, true);
        QSCI_EnableTxDMA(psHandle->base, true);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Initiates data receive using DMA.
 *
 * This function initiates a data receive process using DMA. This is a non-blocking function, which returns
 * right away. When all the data is received, the receive callback function is called.
 *
 * param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 * param psTransfer QSCI DMA transfer structure, see #qsci_transfer_t.
 * retval kStatus_Success if succeed, others fail.
 * retval kStatus_QSCI_RxBusy Previous transfer ongoing.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferReceiveDMA(qsci_dma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer)
{
    assert(NULL != psHandle);
    assert(NULL != psTransfer);
    assert(NULL != psTransfer->pu8Data);
    assert(0U != psTransfer->u32DataSize);

    status_t status;

    /* If previous RX not finished. */
    if ((uint8_t)kQSCI_RxBusy == psHandle->u8RxState)
    {
        status = kStatus_QSCI_RxBusy;
    }
    else
    {
        psHandle->u8RxState        = (uint8_t)kQSCI_RxBusy;
        psHandle->u32RxDataSizeAll = psTransfer->u32DataSize;

        /* Configure the RX DMA channel. */
        dma_channel_transfer_config_t sReceiveConfig;
        uint32_t u32SrcByteAddr  = QSCI_GetDataRegisterAddress(psHandle->base);
        uint32_t u32DestByteAddr = (uint32_t)(uint8_t *)(psTransfer->pu8Data);

        DMA_GetChannelDefaultTransferConfig(&sReceiveConfig, u32SrcByteAddr, u32DestByteAddr, psTransfer->u32DataSize,
                                            kDMA_ChannelTransferWidth8Bits, kDMA_ChannelTransferPeripheralToMemory);

        sReceiveConfig.bEnableCycleSteal = true;
        (void)DMA_TransferChannelSubmit(&psHandle->sRxDmaHandle, &sReceiveConfig);
        (void)DMA_TransferChannelStart(&psHandle->sRxDmaHandle, true);

        /* Enable QSCI RX DMA. */
        QSCI_EnableRx(psHandle->base, true);
        QSCI_EnableRxDMA(psHandle->base, true);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the data transmit process using DMA.
 *
 * param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 */
void QSCI_TransferAbortSendDMA(qsci_dma_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    /* Disable QSCI TX DMA. */
    QSCI_EnableTxDMA(psHandle->base, false);

    /* Stop transfer. */
    DMA_TransferChannelAbort(&psHandle->sTxDmaHandle);

    psHandle->u8TxState = (uint8_t)kQSCI_TxIdle;
}

/*!
 * brief Aborts the data receive process using DMA.
 *
 * param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 */
void QSCI_TransferAbortReceiveDMA(qsci_dma_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    /* Disable QSCI RX DMA. */
    QSCI_EnableRxDMA(psHandle->base, false);

    /* Stop transfer. */
    DMA_TransferChannelAbort(&psHandle->sRxDmaHandle);

    psHandle->u8RxState = (uint8_t)kQSCI_RxIdle;
}

/*!
 * brief Gets the number of received bytes.
 *
 * This function gets the number of received bytes.
 *
 * param psHandle QSCI handle pointer.
 * param pu32Count Receive bytes count.
 * retval kStatus_NoTransferInProgress No receive in progress.
 * retval kStatus_Success Get successfully through the pUserDataeter \p count;
 */
status_t QSCI_TransferGetReceivedCountDMA(qsci_dma_transfer_handle_t *psHandle, uint32_t *pu32Count)
{
    assert(NULL != psHandle);
    assert(NULL != pu32Count);

    if ((uint8_t)kQSCI_RxIdle == psHandle->u8RxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *pu32Count = psHandle->u32RxDataSizeAll -
                 DMA_GetChannelRemainingBytes(psHandle->sRxDmaHandle.psBase, psHandle->sRxDmaHandle.eChannel);

    return kStatus_Success;
}

/*!
 * brief Gets the number of bytes written to the QSCI TX register.
 *
 * This function gets the number of bytes written to the QSCI TX
 * register by DMA.
 *
 * param psHandle QSCI handle pointer.
 * param pu32Count Send bytes count.
 * retval kStatus_NoTransferInProgress No send in progress.
 * retval kStatus_Success Get successfully through the pUserDataeter \p count;
 */
status_t QSCI_TransferGetSendCountDMA(qsci_dma_transfer_handle_t *psHandle, uint32_t *pu32Count)
{
    assert(NULL != psHandle);
    assert(NULL != pu32Count);

    if ((uint8_t)kQSCI_TxIdle == psHandle->u8TxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *pu32Count = psHandle->u32TxDataSizeAll -
                 DMA_GetChannelRemainingBytes(psHandle->sTxDmaHandle.psBase, psHandle->sTxDmaHandle.eChannel);

    return kStatus_Success;
}
