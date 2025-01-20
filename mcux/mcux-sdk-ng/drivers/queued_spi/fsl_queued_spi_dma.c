/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_queued_spi_dma.h"

/***********************************************************************************************************************
 * Definitions
 ***********************************************************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.queued_spi_dma"
#endif

/***********************************************************************************************************************
 * Prototypes
 ***********************************************************************************************************************/
/*!
 * @brief Toggle PCS signal.
 * This is not a public API.
 */
static void QSPI_TogglePCS(QSPI_Type *base);

/*!
 * @brief Prepare transfer channel configuration.
 * This is not a public API.
 */
static void QSPI_PrepareTransferDMA(QSPI_Type *base, qspi_master_dma_handle_t *psHandle, qspi_transfer_t *psXfer);

/*!
 * @brief Callback function of QUEUEDSPI master transmit using DMA.
 * This is not a public API.
 */
static void DMA_QSPIMasterTxCallback(dma_handle_t *psDmaHandle, void *pUserData);

/*!
 * @brief Callback function of QUEUEDSPI master receive using DMA.
 * This is not a public API.
 */
static void DMA_QSPIMasterRxCallback(dma_handle_t *psDmaHandle, void *pUserData);

/*!
 * @brief Master completes an DMA transfer.
 * This is not a public API.
 */
static void QSPI_MasterTransferCompleteDMA(QSPI_Type *base, qspi_master_dma_handle_t *psHandle);

/*!
 * @brief Callback function of QUEUEDSPI slave transmit using DMA.
 * This is not a public API.
 */
static void DMA_QSPISlaveTxCallback(dma_handle_t *psDmaHandle, void *pUserData);

/*!
 * @brief Callback function of QUEUEDSPI slave receive using DMA.
 * This is not a public API.
 */
static void DMA_QSPISlaveRxCallback(dma_handle_t *psDmaHandle, void *pUserData);

/***********************************************************************************************************************
 * Code
 ***********************************************************************************************************************/
static void QSPI_TogglePCS(QSPI_Type *base)
{
    if ((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) != 0U)
    {
        base->SPDSR &= ~QSPI_SPDSR_SSB_DATA_MASK;
    }
    else
    {
        base->SPDSR |= QSPI_SPDSR_SSB_DATA_MASK;
    }
}

void QSPI_MasterTransferCreateHandleDMA(QSPI_Type *base,
                                        qspi_master_dma_handle_t *psHandle,
                                        qspi_dma_transfer_callback_t pfCallback,
                                        void *pUserData,
                                        DMA_Type *psDmaBase,
                                        dma_channel_t eDmaTxChannel,
                                        dma_channel_t eDmaRxChannel)
{
    assert(psHandle != NULL);

    /* Zero the psHandle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    DMA_TransferChannelCreateHandle(psDmaBase, &psHandle->sTxHandle, eDmaTxChannel, DMA_QSPIMasterTxCallback, psHandle);
    DMA_TransferChannelCreateHandle(psDmaBase, &psHandle->sRxHandle, eDmaRxChannel, DMA_QSPIMasterRxCallback, psHandle);
}

status_t QSPI_MasterTransferDMA(qspi_master_dma_handle_t *psHandle, qspi_transfer_t *psXfer)
{
    assert(NULL != psXfer);
    QSPI_Type *base = psHandle->base;

    /* Check if the argument is legal. */
    if ((psXfer->pTxData == NULL) && (psXfer->pRxData == NULL) || (psXfer->u16DataSize == 0U))
    {
        return (status_t)kStatus_InvalidArgument;
    }
    /* Check that we're not busy. */
    if (psHandle->u8State == (uint8_t)kQSPI_Busy)
    {
        return kStatus_QSPI_Busy;
    }
    psHandle->u8State = (uint8_t)kQSPI_Busy;

    QSPI_Enable(base, true);

    /* Prepare transfer channel configuration. */
    QSPI_PrepareTransferDMA(base, psHandle, psXfer);

    /* Check transfer flags. */
    psHandle->bIsPcsActiveAfterTransfer = ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterActiveAfterTransfer) != 0U);
    if ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterPCSContinous) != 0U)
    {
        /* Before changing the SPDSR register, disable the module. */
        QSPI_Enable(base, false);

        uint16_t temp = base->SPDSR & ~(QSPI_SPDSR_SSB_STRB_MASK | QSPI_SPDSR_SSB_AUTO_MASK);

        bool PCSmanual = false;
        /* If currently the PCS is active or the PCS should stay active after current transfer, then the PCS signal must
         * be manully changed. */
        if (((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) ||
            ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterActiveAfterTransfer) != 0U))
        {
            PCSmanual = true;
        }

        temp |= (QSPI_SPDSR_SSB_STRB(0U) | QSPI_SPDSR_SSB_AUTO((uint16_t)!PCSmanual));

        base->SPDSR = temp;

        /* Re-enable the module to have the new value take effect. */
        QSPI_Enable(base, true);
    }

    /* If SSB_AUTO are not set, it means the PCS signal is in manual state. */
    /* Assert the PSC signal if PCS signal is current not in active state. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) != 0U))
    {
        QSPI_TogglePCS(base);
    }

    /* Enable QUEUEDSPI TX and RX DMA. */
    QSPI_EnableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);
    psHandle->bIsTxInProgress = true;
    psHandle->bIsRxInProgress = true;

    return kStatus_Success;
}

static void QSPI_PrepareTransferDMA(QSPI_Type *base, qspi_master_dma_handle_t *psHandle, qspi_transfer_t *psXfer)
{
    /* QSPI */
    uint16_t data_width          = (base->SPDSR & QSPI_SPDSR_DS_MASK) >> QSPI_SPDSR_DS_SHIFT;
    qspi_data_width_t eDataWidth = (qspi_data_width_t)data_width;
    uint8_t dummyData            = QSPI_GetDummyData(base);

    /* DMA */
    dma_handle_t *psDmaTxHandle = &psHandle->sTxHandle;
    dma_handle_t *psDmaRxHandle = &psHandle->sRxHandle;
    dma_channel_transfer_config_t sDmaTxXfer, sDmaRxXfer;

    uint32_t u32SrcByteAddr;
    uint32_t u32DstByteAddr;
    dma_channel_transfer_width_t eDmaXferWidth =
        (eDataWidth > kQSPI_Data8Bits) ? kDMA_ChannelTransferWidth16Bits : kDMA_ChannelTransferWidth8Bits;

    /* Disable all interrupts in DMA method. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);
    /* Disable dma before configuring. */
    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);
    /* Read out any possible data in the RX FIFO. */
    QSPI_EmptyRxFifo(base);
    /* Disable TX and RX FIFO. */
    QSPI_EnableFifo(base, false);

    /* Set psHandle dummy data. */
    psHandle->u16TxDummyData = (uint16_t)dummyData | ((uint16_t)dummyData << 8U);
    /* Set PCS active state after transfer. */
    psHandle->u16TotalByteCount = psXfer->u16DataSize;

    /* Configure for the Rx Transfer */
    u32SrcByteAddr = QSPI_GetRxRegisterAddress(base);
    u32DstByteAddr = (psXfer->pRxData == NULL) ? (uint32_t)(uint8_t *)&(psHandle->u16RxDummyData) :
                                                 (uint32_t)(uint8_t *)psXfer->pRxData;
    DMA_GetChannelDefaultTransferConfig(&sDmaRxXfer, u32SrcByteAddr, u32DstByteAddr, psXfer->u16DataSize, eDmaXferWidth,
                                        kDMA_ChannelTransferPeripheralToMemory);
    sDmaRxXfer.bEnablAutoStopPeripheralRequest = true;
    sDmaRxXfer.bEnableCycleSteal               = true;
    (void)DMA_TransferChannelSubmit(psDmaRxHandle, &sDmaRxXfer);

    /* Configure for the Tx Transfer */
    u32SrcByteAddr = (psXfer->pTxData == NULL) ? (uint32_t)(uint8_t *)&(psHandle->u16TxDummyData) :
                                                 (uint32_t)(uint8_t *)psXfer->pTxData;
    u32DstByteAddr = QSPI_GetTxRegisterAddress(base);
    DMA_GetChannelDefaultTransferConfig(&sDmaTxXfer, u32SrcByteAddr, u32DstByteAddr, psXfer->u16DataSize, eDmaXferWidth,
                                        kDMA_ChannelTransferMemoryToPeripheral);
    sDmaTxXfer.bEnablAutoStopPeripheralRequest = true;
    sDmaTxXfer.bEnableCycleSteal               = true;
    (void)DMA_TransferChannelSubmit(psDmaTxHandle, &sDmaTxXfer);

    DMA_TransferChannelStart(psDmaRxHandle, true);
    DMA_TransferChannelStart(psDmaTxHandle, true);
}

static void DMA_QSPIMasterTxCallback(dma_handle_t *psDmaHandle, void *pUserData)
{
    assert(psDmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_dma_handle_t *psHandle = (qspi_master_dma_handle_t *)pUserData;
    QSPI_Type *base                    = psHandle->base;

    /* Change TX transfer state. */
    psHandle->bIsTxInProgress = false;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaTx);

    /* All finished, call the callback. */
    if ((psHandle->bIsTxInProgress == false) && (psHandle->bIsRxInProgress == false))
    {
        QSPI_MasterTransferCompleteDMA(base, psHandle);
    }
}

static void DMA_QSPIMasterRxCallback(dma_handle_t *psDmaHandle, void *pUserData)
{
    assert(psDmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_dma_handle_t *psHandle = (qspi_master_dma_handle_t *)pUserData;
    QSPI_Type *base                    = psHandle->base;

    /* Change RX transfer state. */
    psHandle->bIsRxInProgress = false;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx);

    /* All finished, call the callback. */
    if ((psHandle->bIsTxInProgress == false) && (psHandle->bIsRxInProgress == false))
    {
        QSPI_MasterTransferCompleteDMA(base, psHandle);
    }
}

static void QSPI_MasterTransferCompleteDMA(QSPI_Type *base, qspi_master_dma_handle_t *psHandle)
{
    assert(NULL != psHandle);

    psHandle->u8State = (uint8_t)kQSPI_Idle;

    /* If SSB_AUTO are not set, it means the PCS signal is in manual state. */
    /* De-assert the PSC signal if PCS signal is current in active state and the PCS should not stay active after
     * transfer. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) &&
        (!psHandle->bIsPcsActiveAfterTransfer))
    {
        QSPI_TogglePCS(base);
    }

    if (psHandle->pfCallback != NULL)
    {
        psHandle->pfCallback(psHandle, kStatus_Success, psHandle->pUserData);
    }
}

status_t QSPI_MasterTransferGetCountDMA(qspi_master_dma_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(psHandle != NULL);

    if (NULL == pu16Count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (psHandle->u8State != (uint8_t)kQSPI_Busy)
    {
        *pu16Count = 0;
        return kStatus_NoTransferInProgress;
    }

    size_t remainingByte =
        (size_t)DMA_GetChannelRemainingBytes(psHandle->sRxHandle.psBase, psHandle->sRxHandle.eChannel);

    if (psHandle->eDataWidth > kQSPI_Data8Bits)
    {
        remainingByte *= 2U;
    }

    *pu16Count = psHandle->u16TotalByteCount - remainingByte;

    return kStatus_Success;
}

void QSPI_MasterTransferAbortDMA(qspi_master_dma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    QSPI_Type *base = psHandle->base;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);

    DMA_TransferChannelAbort(&psHandle->sRxHandle);
    DMA_TransferChannelAbort(&psHandle->sTxHandle);

    /* De-assert the PSC signal if PCS signal is current in active state and the PCS signal is in manual mode. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U))
    {
        QSPI_TogglePCS(base);
    }

    psHandle->bIsTxInProgress = false;
    psHandle->bIsRxInProgress = false;

    psHandle->u8State = (uint8_t)kQSPI_Idle;
}

void QSPI_SlaveTransferCreateHandleDMA(QSPI_Type *base,
                                       qspi_slave_dma_handle_t *psHandle,
                                       qspi_dma_transfer_callback_t pfCallback,
                                       void *pUserData,
                                       DMA_Type *psDmaBase,
                                       dma_channel_t eDmaTxChannel,
                                       dma_channel_t eDmaRxChannel)
{
    assert(psHandle != NULL);

    /* Zero the psHandle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    /* Initialize the DMA stuff */
    DMA_TransferChannelCreateHandle(psDmaBase, &psHandle->sTxHandle, eDmaTxChannel, DMA_QSPISlaveTxCallback, psHandle);
    DMA_TransferChannelCreateHandle(psDmaBase, &psHandle->sRxHandle, eDmaRxChannel, DMA_QSPISlaveRxCallback, psHandle);
}

status_t QSPI_SlaveTransferDMA(qspi_slave_dma_handle_t *psHandle, qspi_transfer_t *psXfer)
{
    assert(NULL != psXfer);

    QSPI_Type *base = psHandle->base;

    /* Check if the argument is legal. */
    if ((psXfer->pTxData == NULL) && (psXfer->pRxData == NULL) || (psXfer->u16DataSize == 0U))
    {
        return (status_t)kStatus_InvalidArgument;
    }
    /* Check that we're not busy.*/
    if (psHandle->u8State == (uint8_t)kQSPI_Busy)
    {
        return kStatus_QSPI_Busy;
    }
    psHandle->u8State = (uint8_t)kQSPI_Busy;

    /* Enable the SPI Module */
    QSPI_Enable(base, true);

    /* Prepare transfer channel configuration. */
    QSPI_PrepareTransferDMA(base, psHandle, psXfer);

    /* Enable QUEUEDSPI TX and RX DMA. */
    QSPI_EnableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);
    psHandle->bIsTxInProgress = true;
    psHandle->bIsRxInProgress = true;

    return kStatus_Success;
}

static void DMA_QSPISlaveTxCallback(dma_handle_t *psDmaHandle, void *pUserData)
{
    assert(psDmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_dma_handle_t *psHandle = (qspi_master_dma_handle_t *)pUserData;
    QSPI_Type *base                    = psHandle->base;

    /* Change TX transfer state. */
    psHandle->bIsTxInProgress = false;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaTx);

    /* All finished, call the callback. */
    if ((psHandle->bIsTxInProgress == false) && (psHandle->bIsRxInProgress == false))
    {
        psHandle->u8State = (uint8_t)kQSPI_Idle;

        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle, kStatus_Success, psHandle->pUserData);
        }
    }
}

static void DMA_QSPISlaveRxCallback(dma_handle_t *psDmaHandle, void *pUserData)
{
    assert(psDmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_dma_handle_t *psHandle = (qspi_master_dma_handle_t *)pUserData;
    QSPI_Type *base                    = psHandle->base;

    /* Change RX transfer state. */
    psHandle->bIsRxInProgress = false;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx);

    /* All finished, call the callback. */
    if ((psHandle->bIsTxInProgress == false) && (psHandle->bIsRxInProgress == false))
    {
        psHandle->u8State = (uint8_t)kQSPI_Idle;

        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle, kStatus_Success, psHandle->pUserData);
        }
    }
}

/*!
 * brief Get the slave DMA transfer count.
 *
 * param psHandle Pointer to the qspi_slave_dma_handle_t structure which stores the transfer state.
 * param pu16Count The number of bytes transferred by using the DMA transaction.
 * return status of status_t.
 */
status_t QSPI_SlaveTransferGetCountDMA(qspi_slave_dma_handle_t *psHandle, uint16_t *pu16Count)
{
    return QSPI_MasterTransferGetCountDMA(psHandle, pu16Count);
}

/*!
 * brief Abort a transfer that uses DMA for slave.
 *
 * param psHandle Pointer to the qspi_slave_dma_handle_t structure which stores the transfer state.
 */
void QSPI_SlaveTransferAbortDMA(qspi_slave_dma_handle_t *psHandle)
{
    assert(psHandle);

    QSPI_Type *base = psHandle->base;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);

    DMA_TransferChannelAbort(&psHandle->sRxHandle);
    DMA_TransferChannelAbort(&psHandle->sTxHandle);

    psHandle->bIsTxInProgress = false;
    psHandle->bIsRxInProgress = false;

    psHandle->u8State = (uint8_t)kQSPI_Idle;
}
