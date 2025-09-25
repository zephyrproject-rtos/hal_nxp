/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2020, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spi_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexcomm_spi_dma"
#endif

/*! @brief SPI transfer state, which is used for SPI transactiaonl APIs' internal state. */
enum _spi_dma_states_t
{
    kSPI_Idle = 0x0, /*!< SPI is idle state */
    kSPI_Busy        /*!< SPI is busy tranferring data. */
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief DMA callback function for SPI send transfer.
 *
 * @param handle DMA handle pointer.
 * @param userData User data for DMA callback function.
 */
static void SPI_TxDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode);

/*!
 * @brief DMA callback function for SPI receive transfer.
 *
 * @param handle DMA handle pointer.
 * @param userData User data for DMA callback function.
 */
static void SPI_RxDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode);

/*******************************************************************************
 * Variables
 ******************************************************************************/
SDK_ALIGN(static uint16_t s_rxDummy, 4);
SDK_ALIGN(static dma_descriptor_t s_spi_descriptor_table[FSL_FEATURE_SOC_SPI_COUNT], 16);

/*******************************************************************************
 * Code
 ******************************************************************************/
static void XferToFifoWR(spi_transfer_t *xfer, uint32_t *fifowr)
{
    *fifowr |= (xfer->configFlags & ((uint32_t)kSPI_FrameDelay | (uint32_t)kSPI_FrameAssert));
}

static void SpiConfigToFifoWR(const spi_config_t *config, uint32_t *fifowr)
{
    *fifowr |= ((uint32_t)SPI_DEASSERT_ALL & (~(uint32_t)SPI_DEASSERTNUM_SSEL((uint32_t)config->sselNum)));
    /* set width of data - range asserted at entry */
    *fifowr |= SPI_FIFOWR_LEN(config->dataWidth);
}

static void PrepareTxLastWord(spi_dma_handle_t *handle, spi_transfer_t *xfer, const spi_config_t *config)
{
    uint32_t txLastWord;

    if (NULL != xfer->txData)
    {
        if (config->dataWidth > kSPI_Data8Bits)
        {
            txLastWord = (((uint32_t)xfer->txData[xfer->dataSize - 1U] << 8U) | (xfer->txData[xfer->dataSize - 2U]));
        }
        else
        {
            txLastWord = xfer->txData[xfer->dataSize - 1U];
        }
    }
    else
    {
        txLastWord = s_dummyData[handle->instance];
        txLastWord |= (txLastWord << 8U);
    }

    XferToFifoWR(xfer, &txLastWord);
    SpiConfigToFifoWR(config, &txLastWord);

    handle->lastword = txLastWord;
}

/*!
 * brief Initialize the SPI master DMA handle.
 *
 * This function initializes the SPI master DMA handle which can be used for other SPI master transactional APIs.
 * Usually, for a specified SPI instance, user need only call this API once to get the initialized handle.
 *
 * param base SPI peripheral base address.
 * param handle SPI handle pointer.
 * param callback User callback function called at the end of a transfer.
 * param userData User data for callback.
 * param txHandle DMA handle pointer for SPI Tx, the handle shall be static allocated by users.
 * param rxHandle DMA handle pointer for SPI Rx, the handle shall be static allocated by users.
 */
status_t SPI_MasterTransferCreateHandleDMA(SPI_Type *base,
                                           spi_dma_handle_t *handle,
                                           spi_dma_callback_t callback,
                                           void *userData,
                                           dma_handle_t *txHandle,
                                           dma_handle_t *rxHandle)
{
    uint32_t instance;

    /* check 'base' */
    assert(!(NULL == base));
    if (NULL == base)
    {
        return kStatus_InvalidArgument;
    }
    /* check 'handle' */
    assert(!(NULL == handle));
    if (NULL == handle)
    {
        return kStatus_InvalidArgument;
    }

    instance = SPI_GetInstance(base);

    (void)memset(handle, 0, sizeof(*handle));
    /* Set spi base to handle */
    handle->base               = base;
    handle->txHandle           = txHandle;
    handle->rxHandle           = rxHandle;
    handle->callback           = callback;
    handle->userData           = userData;
    handle->instance           = instance;

    /* Set SPI state to idle */
    handle->state = (uint8_t)kSPI_Idle;

    /* Install callback for Tx dma channel */
    DMA_SetCallback(handle->txHandle, SPI_TxDMACallback, handle);
    DMA_SetCallback(handle->rxHandle, SPI_RxDMACallback, handle);

    return kStatus_Success;
}

/*!
 * @brief Setup the context for RX
 *
 * This function should be called once before starting the RX DMA transfer.
 *
 * @param handle SPI handle pointer.
 * @param xfer SPI transfer structure.
 */
static void SPI_TransferSetupRxContextDMA(spi_dma_handle_t *handle, spi_transfer_t *xfer)
{
    handle->rxNextData       = xfer->rxData;
    handle->rxRemainingBytes = xfer->dataSize;
}

/*!
 * @brief Submit the next RX chunk.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 */
static void SPI_TransferSubmitNextRxDMA(SPI_Type *base, spi_dma_handle_t *handle)
{
    size_t nextRxSize;
    dma_transfer_config_t dmaXferConfig;
    dma_transfer_type_t dmaXferType;
    uint8_t *nextRxData;

    uint8_t *address = (uint8_t *)(uintptr_t)&base->FIFORD;

    nextRxSize = MIN(DMA_MAX_TRANSFER_COUNT, handle->rxRemainingBytes);

    if (handle->rxNextData != NULL)
    {
        dmaXferType = kDMA_PeripheralToMemory;
        nextRxData  = handle->rxNextData;
        handle->rxNextData += nextRxSize;
    }
    else
    {
        dmaXferType = kDMA_StaticToStatic;
        nextRxData  = (uint8_t*)&s_rxDummy;
    }

    DMA_PrepareTransfer(&dmaXferConfig, address, nextRxData, handle->bytesPerFrame, nextRxSize, dmaXferType, NULL);
    (void)DMA_SubmitTransfer(handle->rxHandle, &dmaXferConfig);

    handle->rxRemainingBytes -= nextRxSize;
}

/*!
 * @brief Prepare for TX
 *
 * This function should be called once before starting the TX DMA transfer.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 * @param xfer SPI transfer structure.
 * @param spi_config_p SPI configuration structure.
 */
static void SPI_TransferSetupTxContextDMA(SPI_Type *base, spi_dma_handle_t *handle, spi_transfer_t *xfer, const spi_config_t *spi_config_p)
{
    uint8_t *address;

    handle->txNextData       = xfer->txData;
    handle->txRemainingBytes = xfer->dataSize;

    /*
     * If SSEL need be deasserted at last, then the EOT of the last data frame will
     * be different from previous data frame. Use a seperate DMA descriptor for it.
     */
    if ((xfer->configFlags & (uint32_t)kSPI_FrameAssert) != 0U)
    {
        handle->lastwordBytes     = handle->bytesPerFrame;
        handle->txRemainingBytes -= handle->bytesPerFrame;
    }
    else
    {
        handle->lastwordBytes = 0U;
    }

    /*
     * Set up the DMA descriptor for the last data frame.
     */
    if (0u != handle->lastwordBytes)
    {
        /* Create chained descriptor to transmit last word */
        dma_xfercfg_t tmp_xfercfg;
        tmp_xfercfg.valid         = true;
        tmp_xfercfg.swtrig        = true;
        tmp_xfercfg.intA          = true;
        tmp_xfercfg.byteWidth     = 4U;
        tmp_xfercfg.srcInc        = 0;
        tmp_xfercfg.dstInc        = 0;
        tmp_xfercfg.transferCount = 1U;
        tmp_xfercfg.reload        = false;
        tmp_xfercfg.clrtrig       = false;
        tmp_xfercfg.intB          = false;

        address = (uint8_t*)(uintptr_t)(&base->FIFOWR);

        DMA_CreateDescriptor(&s_spi_descriptor_table[handle->instance], &tmp_xfercfg, &handle->lastword, address, NULL);
    }

    /* Create 16-bit dummy data, used for 16-bit data width. */
    if (handle->txNextData == NULL)
    {
        handle->txDummy = s_dummyData[handle->instance];
        handle->txDummy |= (handle->txDummy << 8);
    }

    /* Setup the control info.
     * Halfword writes to just the control bits (offset 0xE22) doesn't push anything into the FIFO.
     * And the data access type of control bits must be uint16_t, byte writes or halfword writes to FIFOWR
     * will push the data and the current control bits into the FIFO.
     * Clear the SPI_FIFOWR_EOT_MASK bit when data is not the last.
     */
    uint32_t writeAddress = ((uintptr_t) & (base->FIFOWR)) + 2UL;
    *(volatile uint16_t *)writeAddress = (uint16_t)((handle->lastword & (~(uint32_t)kSPI_FrameAssert)) >> 16u);
}

/*!
 * @brief Submit the next TX chunk.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 */
static status_t SPI_TransferSubmitNextTxDMA(SPI_Type *base, spi_dma_handle_t *handle)
{
    uint8_t * address;
    void *nextDesc;
    bool txIntFlag;
    dma_transfer_config_t xferConfig;
    dma_transfer_type_t dmaXferType;
    const uint8_t *txNextData;

    size_t nextTxSize = MIN(DMA_MAX_TRANSFER_COUNT, handle->txRemainingBytes);
    handle->txRemainingBytes -= nextTxSize;

    /*
     * If this is the last part, check whether the last word is needed.
     * if yes, connect the DMA descriptor.
     */
    if ((0u == handle->txRemainingBytes) && (0u != handle->lastwordBytes))
    {
        txIntFlag = false;
        nextDesc  = &s_spi_descriptor_table[handle->instance];
    }
    else
    {
        txIntFlag = true;
        nextDesc  = NULL;
    }

    if (handle->txNextData != NULL)
    {
        dmaXferType = kDMA_MemoryToPeripheral;
        txNextData = handle->txNextData;
        handle->txNextData += nextTxSize;
    }
    else
    {
        dmaXferType = kDMA_StaticToStatic;
        txNextData  = (uint8_t*)&handle->txDummy;
    }

    address = (uint8_t*)(uintptr_t)&base->FIFOWR;
    DMA_PrepareTransfer(&xferConfig, (uint8_t *)(uintptr_t)txNextData, address, handle->bytesPerFrame, nextTxSize, dmaXferType, nextDesc);

    xferConfig.xfercfg.intA = txIntFlag;
    return DMA_SubmitTransfer(handle->txHandle, &xferConfig);
}

/*!
 * brief Perform a non-blocking SPI transfer using DMA.
 *
 * note This interface returned immediately after transfer initiates, users should call
 * SPI_GetTransferStatus to poll the transfer status to check whether SPI transfer finished.
 *
 * param base SPI peripheral base address.
 * param handle SPI DMA handle pointer.
 * param xfer Pointer to dma transfer structure.
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_MasterTransferDMA(SPI_Type *base, spi_dma_handle_t *handle, spi_transfer_t *xfer)
{
    assert(!((NULL == handle) || (NULL == xfer)));

    status_t result = kStatus_Success;
    spi_config_t *spi_config_p;

    if ((NULL == handle) || (NULL == xfer))
    {
        return kStatus_InvalidArgument;
    }

    if (xfer->dataSize < handle->bytesPerFrame)
    {
        return kStatus_InvalidArgument;
    }

    /* Check if the device is busy */
    if (handle->state == (uint8_t)kSPI_Busy)
    {
        return kStatus_SPI_Busy;
    }

    /* Clear FIFOs before transfer. */
    base->FIFOCFG  |= (SPI_FIFOCFG_EMPTYTX_MASK | SPI_FIFOCFG_EMPTYRX_MASK);
    base->FIFOSTAT |= (SPI_FIFOSTAT_TXERR_MASK  | SPI_FIFOSTAT_RXERR_MASK);

    handle->state         = (uint8_t)kSPI_Busy;
    spi_config_p          = (spi_config_t *)SPI_GetConfig(base);
    handle->bytesPerFrame =
        (uint8_t)((spi_config_p->dataWidth > kSPI_Data8Bits) ? (sizeof(uint16_t)) : (sizeof(uint8_t)));

    /* receive */
    SPI_TransferSetupRxContextDMA(handle, xfer);
    SPI_EnableRxDMA(base, true);
    SPI_TransferSubmitNextRxDMA(base, handle);
    handle->rxInProgress = true;
    DMA_StartTransfer(handle->rxHandle);

    /* transmit */
    PrepareTxLastWord(handle, xfer, spi_config_p);

    if (xfer->dataSize == handle->bytesPerFrame)
    {
        /* Only one time send, write the TX register directly. */
        base->FIFOWR = handle->lastword;
        handle->txInProgress = false;
        return kStatus_Success;
    }

    SPI_TransferSetupTxContextDMA(base, handle, xfer, spi_config_p);
    SPI_EnableTxDMA(base, true);

    result = SPI_TransferSubmitNextTxDMA(base, handle);
    if (result != kStatus_Success)
    {
        return result;
    }

    handle->txInProgress  = true;
    DMA_StartTransfer(handle->txHandle);

    return result;
}

/*!
 * brief Transfers a block of data using a DMA method.
 *
 * This function using polling way to do the first half transimission and using DMA way to
 * do the srcond half transimission, the transfer mechanism is half-duplex.
 * When do the second half transimission, code will return right away. When all data is transferred,
 * the callback function is called.
 *
 * param base SPI base pointer
 * param handle A pointer to the spi_master_dma_handle_t structure which stores the transfer state.
 * param transfer A pointer to the spi_half_duplex_transfer_t structure.
 * return status of status_t.
 */
status_t SPI_MasterHalfDuplexTransferDMA(SPI_Type *base, spi_dma_handle_t *handle, spi_half_duplex_transfer_t *xfer)
{
    assert((xfer != NULL) && (handle != NULL));
    spi_transfer_t tempXfer = {0};
    status_t status;

    if (xfer->isTransmitFirst)
    {
        tempXfer.txData   = xfer->txData;
        tempXfer.rxData   = NULL;
        tempXfer.dataSize = xfer->txDataSize;
    }
    else
    {
        tempXfer.txData   = NULL;
        tempXfer.rxData   = xfer->rxData;
        tempXfer.dataSize = xfer->rxDataSize;
    }
    /* If the pcs pin keep assert between transmit and receive. */
    if (xfer->isPcsAssertInTransfer)
    {
        tempXfer.configFlags = (xfer->configFlags) & (~(uint32_t)kSPI_FrameAssert);
    }
    else
    {
        tempXfer.configFlags = (xfer->configFlags) | (uint32_t)kSPI_FrameAssert;
    }

    status = SPI_MasterTransferBlocking(base, &tempXfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (xfer->isTransmitFirst)
    {
        tempXfer.txData   = NULL;
        tempXfer.rxData   = xfer->rxData;
        tempXfer.dataSize = xfer->rxDataSize;
    }
    else
    {
        tempXfer.txData   = xfer->txData;
        tempXfer.rxData   = NULL;
        tempXfer.dataSize = xfer->txDataSize;
    }
    tempXfer.configFlags = xfer->configFlags;

    status = SPI_MasterTransferDMA(base, handle, &tempXfer);

    return status;
}

/*!
 * @brief Handle the RX DMA IRQ.
 */
static void SPI_TransferRxHandlerDMA(SPI_Type *base, spi_dma_handle_t *spiHandle)
{
    if (spiHandle->rxRemainingBytes <= 0u)
    {
        spiHandle->rxInProgress = false;
    }
    else
    {
        SPI_TransferSubmitNextRxDMA(base, spiHandle);
        DMA_StartTransfer(spiHandle->rxHandle);
    }
}

/*!
 * @brief Handle the TX DMA IRQ.
 */
static void SPI_TransferTxHandlerDMA(SPI_Type *base, spi_dma_handle_t *spiHandle)
{
    if (spiHandle->txRemainingBytes <= 0u)
    {
        spiHandle->txInProgress = false;
    }
    else
    {
        (void)SPI_TransferSubmitNextTxDMA(base, spiHandle);
        DMA_StartTransfer(spiHandle->txHandle);
    }
}

/*!
 * @brief Check if the transfer is done, if so, disable DMA and call the callback function.
 */
static void SPI_TransferCheckTransferDoneDMA(SPI_Type *base, spi_dma_handle_t *spiHandle)
{
    if ((spiHandle->rxInProgress == false) && (spiHandle->txInProgress == false))
    {
        SPI_EnableTxDMA(base, false);
        SPI_EnableRxDMA(base, false);
        spiHandle->state = (uint8_t)kSPI_Idle;
        if (spiHandle->callback != NULL)
        {
            (spiHandle->callback)(base, spiHandle, kStatus_Success, spiHandle->userData);
        }
    }
}

/*!
 * @brief RX DMA callback.
 */
static void SPI_RxDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode)
{
    spi_dma_handle_t *spiHandle          = (spi_dma_handle_t *)userData;
    SPI_Type *base                       = spiHandle->base;

    SPI_TransferRxHandlerDMA(base, spiHandle);

    /*
     * The TX is handled differently for master and slave.
     * 
     * According to the SPI protocol, the data flow between master and slave is as follows:
     * 1. Before master sending the data frame, slave should fill (prepare) a data frame (or dummy) to SPI TX register.
     * 2. Master writes data frame to SPI TX register.
     * 3. Master written data frame is sent to the SPI bus with clock by SPI IP.
     * 4. Based on SPI clock, slave will receive the data frame, and save it to SPI RX register.
     *    At the same time, the data frame in SPI slave TX register will be sent to SPI bus, and received by master.
     * 5. Master saves the received data frame to SPI RX register.
     *
     * From the above, if master TX is setup before master RX DMA ready, then master RX will overflow.
     * So, for master, the driver doesn't submit the TX DMA until RX DMA is ready.
     */
    if (!spiHandle->isSlave)
    {
        SPI_TransferTxHandlerDMA(base, spiHandle);
    }

    SPI_TransferCheckTransferDoneDMA(base, spiHandle);
}

/*!
 * @brief TX DMA callback.
 */
static void SPI_TxDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode)
{
    spi_dma_handle_t *spiHandle          = (spi_dma_handle_t *)userData;
    SPI_Type *base                       = spiHandle->base;

    if (spiHandle->isSlave)
    {
        SPI_TransferTxHandlerDMA(base, spiHandle);
        SPI_TransferCheckTransferDoneDMA(base, spiHandle);
    }
}

/*!
 * brief Abort a SPI transfer using DMA.
 *
 * param base SPI peripheral base address.
 * param handle SPI DMA handle pointer.
 */
void SPI_MasterTransferAbortDMA(SPI_Type *base, spi_dma_handle_t *handle)
{
    assert(NULL != handle);

    /* Stop tx transfer first */
    DMA_AbortTransfer(handle->txHandle);
    /* Then rx transfer */
    DMA_AbortTransfer(handle->rxHandle);

    /* Set the handle state */
    handle->txInProgress = false;
    handle->rxInProgress = false;
    handle->state        = (uint8_t)kSPI_Idle;
}

/*!
 * brief Gets the master DMA transfered bytes.
 *
 * This function gets the master DMA transfered bytes.
 *
 * param base SPI peripheral base address.
 * param handle A pointer to the spi_dma_handle_t structure which stores the transfer state.
 * param count A number of bytes transferred by the non-blocking transaction.
 * return status of status_t.
 */
status_t SPI_MasterTransferGetCountDMA(SPI_Type *base, spi_dma_handle_t *handle, size_t *count)
{
    assert(handle != NULL);

    if (NULL == count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (handle->state != (uint8_t)kSPI_Busy)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    size_t bytes;

    bytes = DMA_GetRemainingBytes(handle->rxHandle->base, handle->rxHandle->channel);

    *count = handle->transferSize - handle->rxRemainingBytes - bytes;

    return kStatus_Success;
}
