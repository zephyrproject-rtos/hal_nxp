/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_queued_spi_edma.h"

/***********************************************************************************************************************
 * Definitions
 ***********************************************************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.queued_spi_edma"
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
static void QSPI_PrepareTransferEDMA(QSPI_Type *base, qspi_master_edma_handle_t *psHandle, qspi_transfer_t *psXfer);

/*!
 * @brief Callback function of QUEUEDSPI master transmit using EDMA.
 * This is not a public API.
 */
static void EDMA_QSPIMasterTxCallback(edma_handle_t *psEdmaHandle,
                                      void *pUserData,
                                      bool bIsTransferDone,
                                      uint32_t u32Tcds);

/*!
 * @brief Callback function of QUEUEDSPI master receive using EDMA.
 * This is not a public API.
 */
static void EDMA_QSPIMasterRxCallback(edma_handle_t *psEdmaHandle,
                                      void *pUserData,
                                      bool bIsTransferDone,
                                      uint32_t u32Tcds);

/*!
 * @brief Master completes an EDMA transfer.
 * This is not a public API.
 */
static void QSPI_MasterTransferCompleteEDMA(QSPI_Type *base, qspi_master_edma_handle_t *psHandle);

/*!
 * @brief Callback function of QUEUEDSPI slave transmit using EDMA.
 * This is not a public API.
 */
static void EDMA_QSPISlaveTxCallback(edma_handle_t *psEdmaHandle,
                                     void *pUserData,
                                     bool bIsTransferDone,
                                     uint32_t u32Tcds);

/*!
 * @brief Callback function of QUEUEDSPI slave receive using EDMA.
 * This is not a public API.
 */
static void EDMA_QSPISlaveRxCallback(edma_handle_t *psEdmaHandle,
                                     void *pUserData,
                                     bool bIsTransferDone,
                                     uint32_t u32Tcds);

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

void QSPI_MasterTransferCreateHandleEDMA(QSPI_Type *base,
                                         qspi_master_edma_handle_t *psHandle,
                                         qspi_edma_transfer_callback_t pfCallback,
                                         void *pUserData,
                                         DMA_Type *psEdmaBase,
                                         edma_channel_t eEdmaTxChannel,
                                         edma_channel_t eEdmaRxChannel)
{
    assert(psHandle != NULL);
    assert(0U == (((uint32_t)(uint8_t *)psHandle) & (sizeof(edma_channel_tcd_t) - 1U)));

    /* Zero the psHandle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    EDMA_TransferCreateHandle(psEdmaBase, &psHandle->sTxHandle, eEdmaTxChannel, &psHandle->sTxTcd, 1,
                              EDMA_QSPIMasterTxCallback, psHandle);
    EDMA_TransferCreateHandle(psEdmaBase, &psHandle->sRxHandle, eEdmaRxChannel, &psHandle->sRxTcd, 1,
                              EDMA_QSPIMasterRxCallback, psHandle);
}

status_t QSPI_MasterTransferEDMA(qspi_master_edma_handle_t *psHandle, qspi_transfer_t *psXfer)
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
    QSPI_PrepareTransferEDMA(base, psHandle, psXfer);

    /* Check transfer flags. */
    psHandle->bIsPcsActiveAfterTransfer = ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterActiveAfterTransfer) != 0U);
    if ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterPCSContinous) != 0U)
    {
        /* Before changing the SPDSR register, disable the module. */
        QSPI_Enable(base, false);

        uint16_t temp = base->SPDSR & (~(QSPI_SPDSR_SSB_STRB_MASK | QSPI_SPDSR_SSB_AUTO_MASK));

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

static void QSPI_PrepareTransferEDMA(QSPI_Type *base, qspi_master_edma_handle_t *psHandle, qspi_transfer_t *psXfer)
{
    /* QSPI */
    uint16_t data_width          = (base->SPDSR & QSPI_SPDSR_DS_MASK) >> QSPI_SPDSR_DS_SHIFT;
    qspi_data_width_t eDataWidth = (qspi_data_width_t)data_width;
    uint8_t dummyData            = QSPI_GetDummyData(base);

    /* EDMA */
    edma_handle_t *psEdmaTxHandle = &psHandle->sTxHandle;
    edma_handle_t *psEdmaRxHandle = &psHandle->sRxHandle;
    edma_channel_transfer_config_t sEdmaTxXfer, sEdmaRxXfer;

    uint32_t u32SrcByteAddr;
    uint32_t u32DstByteAddr;
    uint16_t u16Bytes = (eDataWidth > kQSPI_Data8Bits) ? 2U : 1U;
    edma_channel_transfer_width_t eEdmaXferWidth =
        (eDataWidth > kQSPI_Data8Bits) ? kEDMA_ChannelTransferWidth16Bits : kEDMA_ChannelTransferWidth8Bits;
    edma_channel_transfer_type_t eType;

    /* Disable all interrupts in EDMA method. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);
    /* Disable dma before configuring. */
    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);
    /* Read out any possible data in the RX FIFO. */
    QSPI_EmptyRxFifo(base);
    /* Disable TX and RX FIFO. */
    QSPI_EnableFifo(base, false);

    /* Set psHandle dummy data. */
    psHandle->u16TxDummyData = (uint16_t)dummyData | (((uint16_t)dummyData) << 8U);
    /* Set PCS active state after transfer. */
    psHandle->u16TotalByteCount = psXfer->u16DataSize;

    /* Configure for the Rx Transfer */
    u32SrcByteAddr = QSPI_GetRxRegisterAddress(base);
    u32DstByteAddr = (psXfer->pRxData == NULL) ? (uint32_t)(uint8_t *)&(psHandle->u16RxDummyData) :
                                                 (uint32_t)(uint8_t *)psXfer->pRxData;
    eType = (psXfer->pRxData == NULL) ? kEDMA_ChannelTransferPeripheralToPeripheral :
                                        kEDMA_ChannelTransferPeripheralToMemory;
    EDMA_GetChannelDefaultTransferConfig(&sEdmaRxXfer, u32SrcByteAddr, u32DstByteAddr, u16Bytes, psXfer->u16DataSize,
                                         eEdmaXferWidth, eType);
    sEdmaRxXfer.u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;
    (void)EDMA_TransferSubmitSingleTransfer(psEdmaRxHandle, &sEdmaRxXfer);

    /* Configure for the Tx Transfer */
    u32SrcByteAddr = (psXfer->pTxData == NULL) ? (uint32_t)(uint8_t *)&(psHandle->u16TxDummyData) :
                                                 (uint32_t)(uint8_t *)psXfer->pTxData;
    u32DstByteAddr = QSPI_GetTxRegisterAddress(base);
    eType          = (psXfer->pTxData == NULL) ? kEDMA_ChannelTransferPeripheralToPeripheral :
                                        kEDMA_ChannelTransferMemoryToPeripheral;
    EDMA_GetChannelDefaultTransferConfig(&sEdmaTxXfer, u32SrcByteAddr, u32DstByteAddr, u16Bytes, psXfer->u16DataSize,
                                         eEdmaXferWidth, eType);
    sEdmaTxXfer.u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;
    (void)EDMA_TransferSubmitSingleTransfer(psEdmaTxHandle, &sEdmaTxXfer);

    EDMA_TransferStart(psEdmaRxHandle);
    EDMA_TransferStart(psEdmaTxHandle);
}

static void EDMA_QSPIMasterTxCallback(edma_handle_t *psEdmaHandle,
                                      void *pUserData,
                                      bool bIsTransferDone,
                                      uint32_t u32Tcds)
{
    assert(psEdmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_edma_handle_t *psHandle = (qspi_master_edma_handle_t *)pUserData;
    QSPI_Type *base                     = psHandle->base;

    /* Change TX transfer state. */
    psHandle->bIsTxInProgress = false;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaTx);

    /* All finished, call the callback. */
    if ((psHandle->bIsTxInProgress == false) && (psHandle->bIsRxInProgress == false))
    {
        QSPI_MasterTransferCompleteEDMA(base, psHandle);
    }
}

static void EDMA_QSPIMasterRxCallback(edma_handle_t *psEdmaHandle,
                                      void *pUserData,
                                      bool bIsTransferDone,
                                      uint32_t u32Tcds)
{
    assert(psEdmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_edma_handle_t *psHandle = (qspi_master_edma_handle_t *)pUserData;
    QSPI_Type *base                     = psHandle->base;

    /* Change RX transfer state. */
    psHandle->bIsRxInProgress = false;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx);

    /* All finished, call the callback. */
    if ((psHandle->bIsTxInProgress == false) && (psHandle->bIsRxInProgress == false))
    {
        QSPI_MasterTransferCompleteEDMA(base, psHandle);
    }
}

static void QSPI_MasterTransferCompleteEDMA(QSPI_Type *base, qspi_master_edma_handle_t *psHandle)
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

status_t QSPI_MasterTransferGetCountEDMA(qspi_master_edma_handle_t *psHandle, uint16_t *pu16Count)
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

    uint32_t remainingByte =
        EDMA_GetChannelRemainingMajorLoopCount(psHandle->sRxHandle.psBase, psHandle->sRxHandle.eChannel);

    if (psHandle->eDataWidth > kQSPI_Data8Bits)
    {
        remainingByte *= 2U;
    }

    *pu16Count = psHandle->u16TotalByteCount - (uint16_t)remainingByte;

    return kStatus_Success;
}

void QSPI_MasterTransferAbortEDMA(qspi_master_edma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    QSPI_Type *base = psHandle->base;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);

    EDMA_TransferAbort(&psHandle->sRxHandle);
    EDMA_TransferAbort(&psHandle->sTxHandle);

    /* De-assert the PSC signal if PCS signal is current in active state and the PCS signal is in manual mode. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U))
    {
        QSPI_TogglePCS(base);
    }

    psHandle->bIsTxInProgress = false;
    psHandle->bIsRxInProgress = false;

    psHandle->u8State = (uint8_t)kQSPI_Idle;
}

void QSPI_SlaveTransferCreateHandleEDMA(QSPI_Type *base,
                                        qspi_slave_edma_handle_t *psHandle,
                                        qspi_edma_transfer_callback_t pfCallback,
                                        void *pUserData,
                                        DMA_Type *psEdmaBase,
                                        edma_channel_t eEdmaTxChannel,
                                        edma_channel_t eEdmaRxChannel)
{
    assert(psHandle != NULL);
    assert(0U == (((uint32_t)(uint8_t *)psHandle) & (sizeof(edma_channel_tcd_t) - 1U)));

    /* Zero the psHandle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    /* Initialize the EDMA stuff */
    EDMA_TransferCreateHandle(psEdmaBase, &psHandle->sTxHandle, eEdmaTxChannel, &psHandle->sTxTcd, 1,
                              EDMA_QSPISlaveTxCallback, psHandle);
    EDMA_TransferCreateHandle(psEdmaBase, &psHandle->sRxHandle, eEdmaRxChannel, &psHandle->sRxTcd, 1,
                              EDMA_QSPISlaveRxCallback, psHandle);
}

status_t QSPI_SlaveTransferEDMA(qspi_slave_edma_handle_t *psHandle, qspi_transfer_t *psXfer)
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
    QSPI_PrepareTransferEDMA(base, psHandle, psXfer);

    /* Enable QUEUEDSPI TX and RX DMA. */
    QSPI_EnableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);
    psHandle->bIsTxInProgress = true;
    psHandle->bIsRxInProgress = true;

    return kStatus_Success;
}

static void EDMA_QSPISlaveTxCallback(edma_handle_t *psEdmaHandle,
                                     void *pUserData,
                                     bool bIsTransferDone,
                                     uint32_t u32Tcds)
{
    assert(psEdmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_edma_handle_t *psHandle = (qspi_master_edma_handle_t *)pUserData;
    QSPI_Type *base                     = psHandle->base;

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

static void EDMA_QSPISlaveRxCallback(edma_handle_t *psEdmaHandle,
                                     void *pUserData,
                                     bool bIsTransferDone,
                                     uint32_t u32Tcds)
{
    assert(psEdmaHandle != NULL);
    assert(pUserData != NULL);

    qspi_master_edma_handle_t *psHandle = (qspi_master_edma_handle_t *)pUserData;
    QSPI_Type *base                     = psHandle->base;

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
 * brief Get the slave EDMA transfer count.
 *
 * param psHandle Pointer to the qspi_slave_edma_handle_t structure which stores the transfer state.
 * param pu16Count The number of bytes transferred by using the EDMA transaction.
 * return status of status_t.
 */
status_t QSPI_SlaveTransferGetCountEDMA(qspi_slave_edma_handle_t *psHandle, uint16_t *pu16Count)
{
    return QSPI_MasterTransferGetCountEDMA(psHandle, pu16Count);
}

/*!
 * brief Abort a transfer that uses EDMA for slave.
 *
 * param psHandle Pointer to the qspi_slave_edma_handle_t structure which stores the transfer state.
 */
void QSPI_SlaveTransferAbortEDMA(qspi_slave_edma_handle_t *psHandle)
{
    assert(psHandle);

    QSPI_Type *base = psHandle->base;

    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaRx | (uint8_t)kQSPI_DmaTx);

    EDMA_TransferAbort(&psHandle->sRxHandle);
    EDMA_TransferAbort(&psHandle->sTxHandle);

    psHandle->bIsTxInProgress = false;
    psHandle->bIsRxInProgress = false;

    psHandle->u8State = (uint8_t)kQSPI_Idle;
}
