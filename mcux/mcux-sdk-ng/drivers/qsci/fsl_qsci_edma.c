/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qsci_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qsci_edma"
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
 * @brief QSCI EDMA send finished callback function.
 *
 * This function is called when QSCI EDMA send finished. It disables the QSCI
 * TX EDMA request and passes @ref kStatus_QSCI_TxIdle to QSCI callback.
 *
 * @param psHandle The EDMA handle.
 * @param pUserData Pointer to qsci_edma_transfer_handle_t.
 * @param bTransferDone True for transfer is done.
 * @param u32Tcds Next tcd descriptor.
 */
static void QSCI_TransferSendEDMACallback(edma_handle_t *psHandle,
                                          void *pUserData,
                                          bool bTransferDone,
                                          uint32_t u32Tcds);

/*!
 * @brief QSCI EDMA receive finished callback function.
 *
 * This function is called when QSCI EDMA receive finished. It disables the QSCI
 * RX EDMA request and passes @ref kStatus_QSCI_RxIdle to QSCI callback.
 *
 * @param psHandle The EDMA handle.
 * @param pUserData Pointer to qsci_edma_transfer_handle_t.
 * @param bTransferDone True for transfer is done.
 * @param u32Tcds Next tcd descriptor.
 */
static void QSCI_TransferReceiveEDMACallback(edma_handle_t *psHandle,
                                             void *pUserData,
                                             bool bTransferDone,
                                             uint32_t u32Tcds);
/*!
 * @brief QSCI DMA IRQ handle function.
 *
 * This function handles the QSCI transmit idle interrupt and invoke call back.
 *
 * @param handle QSCI handle pointer.
 */
void QSCI_TransferDMAHandleIRQ(void *handle);

/*******************************************************************************
 * Code
 ******************************************************************************/

static void QSCI_TransferSendEDMACallback(edma_handle_t *psHandle,
                                          void *pUserData,
                                          bool bTransferDone,
                                          uint32_t u32Tcds)
{
    assert(NULL != pUserData);

    qsci_edma_transfer_handle_t *psQsciEdmaHandle = (qsci_edma_transfer_handle_t *)pUserData;

    /* Avoid the warning for unused variables. */
    psHandle = psHandle;
    u32Tcds  = u32Tcds;

    if (bTransferDone)
    {
        /* Disable QSCI TX DMA. */
        QSCI_TransferAbortSendEDMA(psQsciEdmaHandle);

        /* Enable tx idle interrupt */
        QSCI_EnableInterrupts(psQsciEdmaHandle->base, (uint8_t)kQSCI_TxIdleInterruptEnable);
    }
}

/*!
 * brief QSCI DMA IRQ handle function.
 *
 * This function handles the QSCI transmit idle interrupt and invoke call back.
 *
 * param handle QSCI handle pointer.
 */
void QSCI_TransferDMAHandleIRQ(void *handle)
{
    /* Check arguments */
    assert(NULL != handle);

    qsci_edma_transfer_handle_t *psQsciEdmaHandle = (qsci_edma_transfer_handle_t *)handle;
    QSCI_Type *base                               = psQsciEdmaHandle->base;
    uint16_t status                               = QSCI_GetStatusFlags(base);

    if ((0U != ((uint16_t)kQSCI_TxIdleFlag & status)) && (0U != (base->CTRL1 & QSCI_CTRL1_TIIE_MASK)) &&
        (psQsciEdmaHandle->u8TxState == (uint8_t)kQSCI_TxIdle))
    {
        /* Disable transmission complete interrupt. */
        QSCI_DisableInterrupts(base, (uint8_t)kQSCI_TxIdleInterruptEnable);
        psQsciEdmaHandle->busStatus = kStatus_QSCI_TxIdle;
        /* Trigger callback. */
        if (NULL != psQsciEdmaHandle->pfCallback)
        {
            psQsciEdmaHandle->pfCallback(psQsciEdmaHandle);
        }
    }
}

static void QSCI_TransferReceiveEDMACallback(edma_handle_t *psHandle,
                                             void *pUserData,
                                             bool bTransferDone,
                                             uint32_t u32Tcds)
{
    assert(NULL != pUserData);

    qsci_edma_transfer_handle_t *psQsciEdmaHandle = (qsci_edma_transfer_handle_t *)pUserData;

    /* Avoid warning for unused pUserDataeters. */
    psHandle = psHandle;
    u32Tcds  = u32Tcds;

    if (bTransferDone)
    {
        /* Disable transfer. */
        QSCI_TransferAbortReceiveEDMA(psQsciEdmaHandle);

        psQsciEdmaHandle->busStatus = kStatus_QSCI_RxIdle;
        if (NULL != psQsciEdmaHandle->pfCallback)
        {
            psQsciEdmaHandle->pfCallback(psQsciEdmaHandle);
        }
    }
}

/*!
 * brief Initializes the QSCI edma handle.
 *
 * This function initializes the QSCI edma handle which can be used for other QSCI transactional APIs. Usually, for a
 * specified QSCI instance, call this API once to get the initialized handle.
 *
 * param base QSCI peripheral base address.
 * param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 * param pfCallback Callback function.
 * param pUserData User data.
 * param edmaBase Edma base address.
 * param eEdmaTxChannel eDMA channel for TX transfer.
 * param eEdmaRxChannel eDMA channel for RX transfer.
 */
void QSCI_TransferCreateHandleEDMA(QSCI_Type *base,
                                   qsci_edma_transfer_handle_t *psHandle,
                                   qsci_edma_transfer_callback_t pfCallback,
                                   void *pUserData,
                                   DMA_Type *edmaBase,
                                   edma_channel_t eEdmaTxChannel,
                                   edma_channel_t eEdmaRxChannel)
{
    assert(NULL != psHandle);

    uint16_t instance = QSCI_GetInstance(base);

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
    EDMA_TransferCreateHandle(edmaBase, &psHandle->sTxEdmaHandle, eEdmaTxChannel, &psHandle->sTxTcd, 1,
                              QSCI_TransferSendEDMACallback, psHandle);
    /* Configure RX. */
    EDMA_TransferCreateHandle(edmaBase, &psHandle->sRxEdmaHandle, eEdmaRxChannel, &psHandle->sRxTcd, 1,
                              QSCI_TransferReceiveEDMACallback, psHandle);

    /* Set QSCI_TransferDMAHandleIRQ as QSCI IRQ handler */
    s_pfQsciIsr               = QSCI_TransferDMAHandleIRQ;
    s_psQsciHandles[instance] = (void *)psHandle;

    /* Enable TXIDLE IRQ. */
    (void)EnableIRQ(s_eQsciTXIdleIRQs[instance]);
}

/*!
 * brief Initiate data transmit using EDMA.
 *
 * This function initiates a data transmit process using eDMA. This is a non-blocking function, which returns
 * right away. When all the data is sent, the send callback function is called.
 *
 * param psHandle QSCI handle pointer.
 * param psTransfer QSCI eDMA transfer structure. See #qsci_transfer_t.
 * retval kStatus_Success if succeed, others failed.
 * retval kStatus_QSCI_TxBusy Previous transfer on going.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferSendEDMA(qsci_edma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer)
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

        edma_channel_transfer_config_t sTransmitConfig;
        uint32_t u32SrcByteAddr  = (uint32_t)(uint8_t *)(psTransfer->pu8Data);
        uint32_t u32DestByteAddr = QSCI_GetDataRegisterAddress(psHandle->base);

        EDMA_GetChannelDefaultTransferConfig(&sTransmitConfig, u32SrcByteAddr, u32DestByteAddr, 1U,
                                             psTransfer->u32DataSize, kEDMA_ChannelTransferWidth8Bits,
                                             kEDMA_ChannelTransferMemoryToPeripheral);
        sTransmitConfig.u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;

        status = EDMA_TransferSubmitSingleTransfer(&psHandle->sTxEdmaHandle, &sTransmitConfig);

        if (kStatus_Success == status)
        {
            EDMA_TransferStart(&psHandle->sTxEdmaHandle);

            /* Enable QSCI TX EDMA. */
            QSCI_EnableTx(psHandle->base, true);
            QSCI_EnableTxDMA(psHandle->base, true);
        }
    }

    return status;
}

/*!
 * brief Initiates data receive using EDMA.
 *
 * This function initiates a data receive process using eDMA. This is a non-blocking function, which returns
 * right away. When all the data is received, the receive callback function is called.
 *
 * param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 * param psTransfer QSCI eDMA transfer structure, see #qsci_transfer_t.
 * retval kStatus_Success if succeed, others fail.
 * retval kStatus_QSCI_RxBusy Previous transfer ongoing.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferReceiveEDMA(qsci_edma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer)
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

        /* Configure the RX EDMA channel. */
        edma_channel_transfer_config_t sReceiveConfig;
        uint32_t u32SrcByteAddr  = QSCI_GetDataRegisterAddress(psHandle->base);
        uint32_t u32DestByteAddr = (uint32_t)(uint8_t *)(psTransfer->pu8Data);

        EDMA_GetChannelDefaultTransferConfig(&sReceiveConfig, u32SrcByteAddr, u32DestByteAddr, 1U,
                                             psTransfer->u32DataSize, kEDMA_ChannelTransferWidth8Bits,
                                             kEDMA_ChannelTransferPeripheralToMemory);
        sReceiveConfig.u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;

        status = EDMA_TransferSubmitSingleTransfer(&psHandle->sRxEdmaHandle, &sReceiveConfig);

        if (kStatus_Success == status)
        {
            EDMA_TransferStart(&psHandle->sRxEdmaHandle);

            /* Enable QSCI RX EDMA. */
            QSCI_EnableRx(psHandle->base, true);
            QSCI_EnableRxDMA(psHandle->base, true);
        }
    }

    return status;
}

/*!
 * brief Aborts the data transmit process using EDMA.
 *
 * param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 */
void QSCI_TransferAbortSendEDMA(qsci_edma_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    /* Disable QSCI TX EDMA. */
    QSCI_EnableTxDMA(psHandle->base, false);

    /* Stop transfer. */
    EDMA_TransferAbort(&psHandle->sTxEdmaHandle);

    psHandle->u8TxState = (uint8_t)kQSCI_TxIdle;
}

/*!
 * brief Aborts the data receive process using EDMA.
 *
 * param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 */
void QSCI_TransferAbortReceiveEDMA(qsci_edma_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    /* Disable QSCI RX EDMA. */
    QSCI_EnableRxDMA(psHandle->base, false);

    /* Stop transfer. */
    EDMA_TransferAbort(&psHandle->sRxEdmaHandle);

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
status_t QSCI_TransferGetReceivedCountEDMA(qsci_edma_transfer_handle_t *psHandle, uint32_t *pu32Count)
{
    assert(NULL != psHandle);
    assert(NULL != pu32Count);

    if ((uint8_t)kQSCI_RxIdle == psHandle->u8RxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *pu32Count = psHandle->u32RxDataSizeAll - EDMA_GetChannelRemainingMajorLoopCount(psHandle->sRxEdmaHandle.psBase,
                                                                                     psHandle->sRxEdmaHandle.eChannel);

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
status_t QSCI_TransferGetSendCountEDMA(qsci_edma_transfer_handle_t *psHandle, uint32_t *pu32Count)
{
    assert(NULL != psHandle);
    assert(NULL != pu32Count);

    if ((uint8_t)kQSCI_TxIdle == psHandle->u8TxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *pu32Count = psHandle->u32TxDataSizeAll - EDMA_GetChannelRemainingMajorLoopCount(psHandle->sTxEdmaHandle.psBase,
                                                                                     psHandle->sTxEdmaHandle.eChannel);

    return kStatus_Success;
}
