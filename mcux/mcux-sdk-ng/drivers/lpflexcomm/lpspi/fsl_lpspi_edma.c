/*
 * Copyright 2022, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpspi_edma.h"

/***********************************************************************************************************************
 * Definitions
 ***********************************************************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpflexcomm_lpspi_edma"
#endif

/*!
 * @brief Structure definition for lpspi_master_edma_private_handle_t. The structure is private.
 */
typedef struct _lpspi_master_edma_private_handle
{
    LPSPI_Type *base;                   /*!< LPSPI peripheral base address. */
    lpspi_master_edma_handle_t *handle; /*!< lpspi_master_edma_handle_t handle */
} lpspi_master_edma_private_handle_t;

/*!
 * @brief Structure definition for lpspi_slave_edma_private_handle_t. The structure is private.
 */
typedef struct _lpspi_slave_edma_private_handle
{
    LPSPI_Type *base;                  /*!< LPSPI peripheral base address. */
    lpspi_slave_edma_handle_t *handle; /*!< lpspi_slave_edma_handle_t handle */
} lpspi_slave_edma_private_handle_t;

/***********************************************************************************************************************
 * Prototypes
 ***********************************************************************************************************************/

/*!
 * @brief EDMA_LpspiMasterCallback after the LPSPI master transfer completed by using EDMA.
 * This is not a public API.
 */
static void EDMA_LpspiMasterCallback(edma_handle_t *edmaHandle,
                                     void *userData,
                                     bool transferDone,
                                     uint32_t tcds);

/*!
 * @brief EDMA_LpspiSlaveCallback after the LPSPI slave transfer completed by using EDMA.
 * This is not a public API.
 */
static void EDMA_LpspiSlaveCallback(edma_handle_t *edmaHandle,
                                    void *userData,
                                    bool transferDone,
                                    uint32_t tcds);

static edma_transfer_size_t getEdmaTransferSize(uint32_t bytesCount);

static uint32_t getRegAddrOffset(uint32_t bytesCount, bool isByteSwap);

/***********************************************************************************************************************
 * Variables
 ***********************************************************************************************************************/
/*! @brief Pointers to lpspi bases for each instance. */
static LPSPI_Type *const s_lpspiBases[] = LPSPI_BASE_PTRS;

/*! @brief Pointers to lpspi edma handles for each instance. */
static lpspi_master_edma_private_handle_t s_lpspiMasterEdmaPrivateHandle[ARRAY_SIZE(s_lpspiBases)];
static lpspi_slave_edma_private_handle_t s_lpspiSlaveEdmaPrivateHandle[ARRAY_SIZE(s_lpspiBases)];

/***********************************************************************************************************************
 * Code
 ***********************************************************************************************************************/

static edma_transfer_size_t getEdmaTransferSize(uint32_t bytesCount)
{
    edma_transfer_size_t ret = kEDMA_TransferSize1Bytes;
    switch (bytesCount)
    {
        case (1U):
            ret = kEDMA_TransferSize1Bytes;
            break;

        case (2U):
            ret = kEDMA_TransferSize2Bytes;
            break;

        case (4U):
            ret = kEDMA_TransferSize4Bytes;
            break;

        default:
            assert(false);
            break;
    }

    return ret;
}

static uint32_t getRegAddrOffset(uint32_t bytesCount, bool isByteSwap)
{
    uint32_t addrOffset = 0U;
    if (isByteSwap)
    {
        switch (bytesCount)
        {
            case (1U):
                addrOffset = 3U;
                break;

            case (2U):
                addrOffset = 2U;
                break;

            case (4U):
                addrOffset = 0U;
                break;

            default:
                assert(false);
                break;
        }
    }

    return addrOffset;
}

/*!
 * brief Initializes the LPSPI master eDMA handle.
 *
 * This function initializes the LPSPI eDMA handle which can be used for other LPSPI transactional APIs. Usually, for a
 * specified LPSPI instance, call this API once to get the initialized handle.
 *
 * Note that the LPSPI eDMA has a separated (Rx and Rx as two sources) or shared (Rx and Tx are the same source) DMA
 * request source.
 * (1) For a separated DMA request source, enable and set the Rx DMAMUX source for edmaRxRegToRxDataHandle and
 * Tx DMAMUX source for edmaIntermediaryToTxRegHandle.
 * (2) For a shared DMA request source, enable and set the Rx/Rx DMAMUX source for edmaRxRegToRxDataHandle.
 *
 * param base LPSPI peripheral base address.
 * param handle LPSPI handle pointer to lpspi_master_edma_handle_t.
 * param callback LPSPI callback.
 * param userData callback function parameter.
 * param edmaRxRegToRxDataHandle edmaRxRegToRxDataHandle pointer to edma_handle_t.
 * param edmaTxDataToTxRegHandle edmaTxDataToTxRegHandle pointer to edma_handle_t.
 */
void LPSPI_MasterTransferCreateHandleEDMA(LPSPI_Type *base,
                                          lpspi_master_edma_handle_t *handle,
                                          lpspi_master_edma_transfer_callback_t callback,
                                          void *userData,
                                          edma_handle_t *edmaRxRegToRxDataHandle,
                                          edma_handle_t *edmaTxDataToTxRegHandle)
{
    assert(handle != NULL);
    assert(edmaRxRegToRxDataHandle != NULL);
    assert(edmaTxDataToTxRegHandle != NULL);

    /* Zero the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    uint32_t instance = LPSPI_GetInstance(base);

    s_lpspiMasterEdmaPrivateHandle[instance].base   = base;
    s_lpspiMasterEdmaPrivateHandle[instance].handle = handle;

    handle->callback = callback;
    handle->userData = userData;

    handle->edmaRxRegToRxDataHandle = edmaRxRegToRxDataHandle;
    handle->edmaTxDataToTxRegHandle = edmaTxDataToTxRegHandle;
}

static void LPSPI_PrepareTransferEDMA(LPSPI_Type *base)
{
    /* Flush FIFO, clear status, disable all the inerrupts and DMA requests. */
    LPSPI_FlushFifo(base, true, true);
    LPSPI_ClearStatusFlags(base, (uint32_t)kLPSPI_AllStatusFlag);
    LPSPI_DisableInterrupts(base, (uint32_t)kLPSPI_AllInterruptEnable);
    LPSPI_DisableDMA(base, (uint32_t)kLPSPI_RxDmaEnable | (uint32_t)kLPSPI_TxDmaEnable);
}

/*!
 * brief LPSPI master config transfer parameter using eDMA.
 *
 * This function is preparing to transfers data using eDMA.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_master_edma_handle_t structure which stores the transfer state.
 * param configFlags transfer configuration flags. ref _lpspi_transfer_config_flag_for_master.
 * return Indicates whether LPSPI master transfer was successful or not.
 * retval kStatus_Success          Execution successfully.
 * retval kStatus_LPSPI_Busy       The LPSPI device is busy.
 */
status_t LPSPI_MasterTransferPrepareEDMALite(LPSPI_Type *base, lpspi_master_edma_handle_t *handle, uint32_t configFlags)
{
    assert(handle != NULL);
    assert(LPSPI_GetRxFifoSize(base) >= 8U);

    /* Check that we're not busy. */
    if (handle->state == (uint8_t)kLPSPI_Busy)
    {
        return kStatus_LPSPI_Busy;
    }

    /* Disable module before configuration */
    LPSPI_Enable(base, false);

    LPSPI_PrepareTransferEDMA(base);

    bool isByteSwap      = ((configFlags & (uint32_t)kLPSPI_MasterByteSwap) != 0U);
    bool isPcsContinuous = ((configFlags & (uint32_t)kLPSPI_MasterPcsContinuous) != 0U);
    uint32_t instance    = LPSPI_GetInstance(base);
    uint8_t dummyData    = g_lpspiDummyData[instance];
    uint32_t whichPcs    = (configFlags & LPSPI_MASTER_PCS_MASK) >> LPSPI_MASTER_PCS_SHIFT;

    handle->txBuffIfNull =
        ((uint32_t)dummyData) | ((uint32_t)dummyData << 8) | ((uint32_t)dummyData << 16) | ((uint32_t)dummyData << 24);
    handle->isPcsContinuous = isPcsContinuous;
    handle->isByteSwap      = isByteSwap;

    /* Transfers will stall when transmit FIFO is empty or receive FIFO is full. */
    base->CFGR1 &= (~LPSPI_CFGR1_NOSTALL_MASK);

    /* Enable module for following configuration of TCR to take effect. */
    LPSPI_Enable(base, true);

    /* For DMA transfer, we'd better not masked the transmit data and receive data in TCR since the transfer flow is
     * hard to controlled by software. */
    base->TCR = (LPSPI_GetTcr(base) & ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK | LPSPI_TCR_BYSW_MASK | LPSPI_TCR_PCS_MASK)) |
                LPSPI_TCR_CONT(isPcsContinuous) | LPSPI_TCR_BYSW(isByteSwap) | LPSPI_TCR_PCS(whichPcs);

    return kStatus_Success;
}

/*!
 * brief LPSPI master transfer data using eDMA without configs.
 *
 * This function transfers data using eDMA. This is a non-blocking function, which returns right away. When all data
 * is transferred, the callback function is called.
 *
 * Note:
 * This API is only for transfer through DMA without configuration.
 * Before calling this API, you must call LPSPI_MasterTransferPrepareEDMALite to configure it once.
 * The transfer data size should be an integer multiple of bytesPerFrame if bytesPerFrame is less than or equal to 4.
 * For bytesPerFrame greater than 4:
 * The transfer data size should be equal to bytesPerFrame if the bytesPerFrame is not an integer multiple of 4.
 * Otherwise, the transfer data size can be an integer multiple of bytesPerFrame.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_master_edma_handle_t structure which stores the transfer state.
 * param transfer pointer to lpspi_transfer_t structure, config field is not working.
 * return Indicates whether LPSPI master transfer was successful or not.
 * retval kStatus_Success          Execution successfully.
 * retval kStatus_LPSPI_Busy       The LPSPI device is busy.
 * retval kStatus_InvalidArgument  The transfer structure is invalid.
 */
status_t LPSPI_MasterTransferEDMALite(LPSPI_Type *base, lpspi_master_edma_handle_t *handle, lpspi_transfer_t *transfer)
{
    assert(handle != NULL);
    assert(transfer != NULL);

    /* Check that we're not busy. */
    if (handle->state == (uint8_t)kLPSPI_Busy)
    {
        return kStatus_LPSPI_Busy;
    }

    /* Check arguments */
    if (!LPSPI_CheckTransferArgument(base, transfer, true))
    {
        return kStatus_InvalidArgument;
    }

    if (handle->isPcsContinuous)
    {
        base->TCR = (LPSPI_GetTcr(base) | LPSPI_TCR_CONT_MASK);
    }

    uint32_t instance      = LPSPI_GetInstance(base);
    uint32_t bytesPerFrame = ((LPSPI_GetTcr(base) & LPSPI_TCR_FRAMESZ_MASK) >> LPSPI_TCR_FRAMESZ_SHIFT) / 8U + 1U;
    /* Size of transferred data - how many bytes will be read/write from/to FIFO (RDR/TDR) at once */
    uint32_t blockSize  = MIN(bytesPerFrame, 4U);
    uint32_t addrOffset = getRegAddrOffset(blockSize, handle->isByteSwap);
    uint32_t rxAddr     = LPSPI_GetRxRegisterAddress(base) + addrOffset;
    uint32_t txAddr     = LPSPI_GetTxRegisterAddress(base) + addrOffset;

    edma_transfer_config_t transferConfigRx = {0};
    edma_transfer_config_t transferConfigTx = {0};
    edma_tcd_t *softwareTCD_oneFifoBlockRx  = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[1]) & (~0x1FU));
    edma_tcd_t *softwareTCD_oneFifoBlockTx  = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[2]) & (~0x1FU));
    edma_tcd_t *softwareTCD_lastBytesRx     = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[3]) & (~0x1FU));
    edma_tcd_t *softwareTCD_lastBytesTx     = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[4]) & (~0x1FU));
    edma_tcd_t *softwareTCD_pcsContinuous   = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[5]) & (~0x1FU));
    edma_tcd_t *nextTcd                     = NULL;

    handle->state = (uint8_t)kLPSPI_Busy;

    /* Used to compute transfered bytes - count of bytes transfered in each DMA request */
    handle->nbytes         = blockSize * 4U;
    handle->totalByteCount = transfer->dataSize;

    handle->oneFifoBlockRxWatermark = -1;
    handle->lastBytesRxWatermark    = -1;

    /* Configure EDMA transfer/s for read */
    EDMA_SetCallback(handle->edmaRxRegToRxDataHandle, EDMA_LpspiMasterCallback,
                     &s_lpspiMasterEdmaPrivateHandle[instance]);
    EDMA_ResetChannel(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel);

    /* Count of blocks aligned to 4 FIFO words */
    uint32_t fourFifoBlocks = (transfer->dataSize / blockSize) / 4U;
    /* Count of blocks aligned to 1 FIFO words */
    uint32_t oneFifoBlocks = (transfer->dataSize / blockSize) % 4U;
    /* Count of bytes in oneFifoBlocks */
    uint32_t oneFifoBlockBytes = oneFifoBlocks * blockSize;

    uint32_t lastBytes = 0U;
    if (bytesPerFrame > 4U)
    {
        lastBytes = transfer->dataSize - (fourFifoBlocks * 4U * blockSize) - oneFifoBlockBytes;
    }

    if (lastBytes > 0U)
    {
        /* Case when framesize is > 4 bytes and not aligned to 4 bytes - transfer config to handle unaligned part (1 or 2 bytes) */
        transferConfigRx.srcAddr   = (uint32_t)LPSPI_GetRxRegisterAddress(base) + getRegAddrOffset(lastBytes, handle->isByteSwap);
        transferConfigRx.srcOffset = 0;
        if (transfer->rxData != NULL)
        {
            transferConfigRx.destAddr   = (uint32_t)transfer->rxData + transfer->dataSize - lastBytes;
            transferConfigRx.destOffset = 1;
        }
        else
        {
            transferConfigRx.destAddr   = (uint32_t)&handle->rxBuffIfNull;
            transferConfigRx.destOffset = 0;
        }
        transferConfigRx.srcTransferSize  = getEdmaTransferSize(lastBytes);
        transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
        transferConfigRx.minorLoopBytes   = lastBytes;
        transferConfigRx.majorLoopCounts  = 1U;

#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
        EDMA_TcdResetExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_lastBytesRx);
        EDMA_TcdSetTransferConfigExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_lastBytesRx,
                                     &transferConfigRx, NULL);
        EDMA_TcdEnableInterruptsExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_lastBytesRx,
                                    (uint32_t)kEDMA_MajorInterruptEnable);
#else
        EDMA_TcdReset(softwareTCD_lastBytesRx);
        EDMA_TcdSetTransferConfig(softwareTCD_lastBytesRx, &transferConfigRx, NULL);
        EDMA_TcdEnableInterrupts(softwareTCD_lastBytesRx, (uint32_t)kEDMA_MajorInterruptEnable);
#endif
        nextTcd = softwareTCD_lastBytesRx;
        handle->lastBytesRxWatermark = 0;
    }

    if (oneFifoBlocks > 0U)
    {
        /* Transfer config for remaining FIFO words (1-3) */
        transferConfigRx.srcAddr   = (uint32_t)rxAddr;
        transferConfigRx.srcOffset = 0;
        if (transfer->rxData != NULL)
        {
            transferConfigRx.destAddr   = (uint32_t)transfer->rxData + transfer->dataSize - oneFifoBlockBytes - lastBytes;
            transferConfigRx.destOffset = 1;
        }
        else
        {
            transferConfigRx.destAddr   = (uint32_t)&handle->rxBuffIfNull;
            transferConfigRx.destOffset = 0;
        }
        transferConfigRx.srcTransferSize  = getEdmaTransferSize(blockSize);
        transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
        transferConfigRx.minorLoopBytes   = oneFifoBlockBytes;
        transferConfigRx.majorLoopCounts  = 1U;

        if (fourFifoBlocks > 0U)
        {
#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
            EDMA_TcdResetExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_oneFifoBlockRx);
            EDMA_TcdSetTransferConfigExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_oneFifoBlockRx,
                                         &transferConfigRx, nextTcd);
            EDMA_TcdEnableInterruptsExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_oneFifoBlockRx,
                                        (uint32_t)kEDMA_MajorInterruptEnable);
#else
            EDMA_TcdReset(softwareTCD_oneFifoBlockRx);
            EDMA_TcdSetTransferConfig(softwareTCD_oneFifoBlockRx, &transferConfigRx, nextTcd);
            EDMA_TcdEnableInterrupts(softwareTCD_oneFifoBlockRx, (uint32_t)kEDMA_MajorInterruptEnable);
#endif
            nextTcd = softwareTCD_oneFifoBlockRx;
        }
        else
        {
            EDMA_SetTransferConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                   &transferConfigRx, nextTcd);

            /* Enable edma interrupt to finish transfer */
            EDMA_EnableChannelInterrupts(handle->edmaRxRegToRxDataHandle->base,
                                         handle->edmaRxRegToRxDataHandle->channel,
                                         (uint32_t)kEDMA_MajorInterruptEnable);

            LPSPI_SetFifoWatermarks(base, 4U, (oneFifoBlocks - 1U));
            handle->nbytes = oneFifoBlockBytes;
        }
    }

    if (fourFifoBlocks > 0U)
    {
        /* Transfer config for part of data aligned to 4 FIFO entry */
        transferConfigRx.srcAddr   = (uint32_t)rxAddr;
        transferConfigRx.srcOffset = 0;
        if (transfer->rxData != NULL)
        {
            transferConfigRx.destAddr   = (uint32_t)transfer->rxData;
            transferConfigRx.destOffset = 1;
        }
        else
        {
            transferConfigRx.destAddr   = (uint32_t) & (handle->rxBuffIfNull);
            transferConfigRx.destOffset = 0;
        }
        transferConfigRx.srcTransferSize  = getEdmaTransferSize(blockSize);
        transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
        transferConfigRx.minorLoopBytes   = blockSize * 4U;
        transferConfigRx.majorLoopCounts  = fourFifoBlocks;

        if (oneFifoBlockBytes > 0U)
        {
            /* Set value for FIFO rx watermark for next part of data, used in EDMA_LpspiMasterCallback() */
            handle->oneFifoBlockRxWatermark = (int8_t)(oneFifoBlocks - 1U);
        }

        EDMA_SetTransferConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                               &transferConfigRx, nextTcd);

        /* Enable edma interrupt to finish transfer or change FIFO rx watermark */
        EDMA_EnableChannelInterrupts(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                     (uint32_t)kEDMA_MajorInterruptEnable);

        /* Configure FIFO watermarks to be possible write/read 4 FIFO entry per each DMA request */
        LPSPI_SetFifoWatermarks(base, 4U, 3U);
    }


    /* Configure EDMA transfer/s for write */
    EDMA_ResetChannel(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel);

    nextTcd = NULL;

    if (handle->isPcsContinuous)
    {
        /* Transfer config to update TCR to deassert CS - softwareTCD_pcsContinuous */
        handle->transmitCommand = LPSPI_GetTcr(base) & ~(LPSPI_TCR_CONTC_MASK | LPSPI_TCR_CONT_MASK);

        transferConfigTx.srcAddr          = (uint32_t)&handle->transmitCommand;
        transferConfigTx.srcOffset        = 0;
        transferConfigTx.destAddr         = (uint32_t)&base->TCR;
        transferConfigTx.destOffset       = 0;
        transferConfigTx.srcTransferSize  = kEDMA_TransferSize4Bytes;
        transferConfigTx.destTransferSize = kEDMA_TransferSize4Bytes;
        transferConfigTx.minorLoopBytes   = 4U;
        transferConfigTx.majorLoopCounts  = 1U;

#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
        EDMA_TcdResetExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_pcsContinuous);
        EDMA_TcdSetTransferConfigExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_pcsContinuous,
                                     &transferConfigTx, NULL);
#else
        EDMA_TcdReset(softwareTCD_pcsContinuous);
        EDMA_TcdSetTransferConfig(softwareTCD_pcsContinuous, &transferConfigTx, NULL);
#endif
        nextTcd = softwareTCD_pcsContinuous;
    }

    if (lastBytes > 0U)
    {
        /* Case when framesize is > 4 bytes and not aligned to 4 bytes - transfer config to handle unaligned part (1 or 2 bytes) */
        if (transfer->txData != NULL)
        {
            transferConfigTx.srcAddr   = (uint32_t)transfer->txData + transfer->dataSize - lastBytes;
            transferConfigTx.srcOffset = 1;
        }
        else
        {
            transferConfigTx.srcAddr   = (uint32_t)&handle->txBuffIfNull;
            transferConfigTx.srcOffset = 0;
        }
        transferConfigTx.destAddr         = (uint32_t)LPSPI_GetTxRegisterAddress(base) + getRegAddrOffset(lastBytes, handle->isByteSwap);
        transferConfigTx.destOffset       = 0;
        transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
        transferConfigTx.destTransferSize = getEdmaTransferSize(lastBytes);
        transferConfigTx.minorLoopBytes   = lastBytes;
        transferConfigTx.majorLoopCounts  = 1U;

#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
        EDMA_TcdResetExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_lastBytesTx);
        EDMA_TcdSetTransferConfigExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_lastBytesTx,
                                     &transferConfigTx, nextTcd);
#else
        EDMA_TcdReset(softwareTCD_lastBytesTx);
        EDMA_TcdSetTransferConfig(softwareTCD_lastBytesTx, &transferConfigTx, nextTcd);
#endif
        nextTcd = softwareTCD_lastBytesTx;
    }

    if (oneFifoBlocks > 0U)
    {
        /* Transfer config for remaining FIFO words (1-3) */
        if (transfer->txData != NULL)
        {
            transferConfigTx.srcAddr   = (uint32_t)transfer->txData + transfer->dataSize - oneFifoBlockBytes - lastBytes;
            transferConfigTx.srcOffset = 1;
        }
        else
        {
            transferConfigTx.srcAddr   = (uint32_t)&handle->txBuffIfNull;
            transferConfigTx.srcOffset = 0;
        }

        transferConfigTx.destAddr         = (uint32_t)txAddr;
        transferConfigTx.destOffset       = 0;
        transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
        transferConfigTx.destTransferSize = getEdmaTransferSize(blockSize);
        transferConfigTx.minorLoopBytes   = oneFifoBlockBytes;
        transferConfigTx.majorLoopCounts  = 1U;

        if (fourFifoBlocks > 0U)
        {
#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
            EDMA_TcdResetExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_oneFifoBlockTx);
            EDMA_TcdSetTransferConfigExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_oneFifoBlockTx,
                                         &transferConfigTx, nextTcd);
#else
            EDMA_TcdReset(softwareTCD_oneFifoBlockTx);
            EDMA_TcdSetTransferConfig(softwareTCD_oneFifoBlockTx, &transferConfigTx, nextTcd);
#endif
            nextTcd = softwareTCD_oneFifoBlockTx;
        }
        else
        {
            EDMA_SetTransferConfig(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel,
                                   &transferConfigTx, nextTcd);
        }
    }

    if (fourFifoBlocks > 0U)
    {
        /* Transfer config for part of data aligned to 4 FIFO entry */
        if (transfer->txData != NULL)
        {
            transferConfigTx.srcAddr   = (uint32_t)transfer->txData;
            transferConfigTx.srcOffset = 1;
        }
        else
        {
            transferConfigTx.srcAddr   = (uint32_t)&handle->txBuffIfNull;
            transferConfigTx.srcOffset = 0;
        }
        transferConfigTx.destAddr         = (uint32_t)txAddr;
        transferConfigTx.destOffset       = 0;
        transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
        transferConfigTx.destTransferSize = getEdmaTransferSize(blockSize);
        transferConfigTx.minorLoopBytes   = blockSize * 4U;
        transferConfigTx.majorLoopCounts  = fourFifoBlocks;

        EDMA_SetTransferConfig(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel,
                               &transferConfigTx, nextTcd);
    }

    EDMA_StartTransfer(handle->edmaRxRegToRxDataHandle);
    EDMA_StartTransfer(handle->edmaTxDataToTxRegHandle);
    LPSPI_EnableDMA(base, (uint32_t)kLPSPI_RxDmaEnable | (uint32_t)kLPSPI_TxDmaEnable);

    return kStatus_Success;
}

/*!
 * brief LPSPI master transfer data using eDMA.
 *
 * This function transfers data using eDMA. This is a non-blocking function, which returns right away. When all data
 * is transferred, the callback function is called.
 *
 * Note:
 * The transfer data size should be an integer multiple of bytesPerFrame if bytesPerFrame is less than or equal to 4.
 * For bytesPerFrame greater than 4:
 * The transfer data size should be equal to bytesPerFrame if the bytesPerFrame is not an integer multiple of 4.
 * Otherwise, the transfer data size can be an integer multiple of bytesPerFrame.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_master_edma_handle_t structure which stores the transfer state.
 * param transfer pointer to lpspi_transfer_t structure.
 * return status of status_t.
 */
status_t LPSPI_MasterTransferEDMA(LPSPI_Type *base, lpspi_master_edma_handle_t *handle, lpspi_transfer_t *transfer)
{
    status_t status = kStatus_Fail;
    status          = LPSPI_MasterTransferPrepareEDMALite(base, handle, transfer->configFlags);
    if (kStatus_Success != status)
    {
        return status;
    }
    return LPSPI_MasterTransferEDMALite(base, handle, transfer);
}

static void EDMA_LpspiMasterCallback(edma_handle_t *edmaHandle, void *userData, bool transferDone, uint32_t tcds)
{
    assert(edmaHandle != NULL);
    assert(userData != NULL);

    lpspi_master_edma_private_handle_t *lpspiEdmaPrivateHandle = (lpspi_master_edma_private_handle_t *)userData;
    if (lpspiEdmaPrivateHandle->handle->oneFifoBlockRxWatermark > -1)
    {
        LPSPI_SetFifoWatermarks(lpspiEdmaPrivateHandle->base, 4U, lpspiEdmaPrivateHandle->handle->oneFifoBlockRxWatermark);
        lpspiEdmaPrivateHandle->handle->oneFifoBlockRxWatermark = -1;
        return;
    }

    if (lpspiEdmaPrivateHandle->handle->lastBytesRxWatermark > -1)
    {
        lpspiEdmaPrivateHandle->handle->lastBytesRxWatermark = -1;
        LPSPI_SetFifoWatermarks(lpspiEdmaPrivateHandle->base, 4U, lpspiEdmaPrivateHandle->handle->lastBytesRxWatermark);
        return;
    }

    LPSPI_DisableDMA(lpspiEdmaPrivateHandle->base, (uint32_t)kLPSPI_TxDmaEnable | (uint32_t)kLPSPI_RxDmaEnable);

    lpspiEdmaPrivateHandle->handle->state = (uint8_t)kLPSPI_Idle;

    if (lpspiEdmaPrivateHandle->handle->callback != NULL)
    {
        lpspiEdmaPrivateHandle->handle->callback(lpspiEdmaPrivateHandle->base, lpspiEdmaPrivateHandle->handle,
                                                 kStatus_Success, lpspiEdmaPrivateHandle->handle->userData);
    }
}

/*!
 * brief LPSPI master aborts a transfer which is using eDMA.
 *
 * This function aborts a transfer which is using eDMA.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_master_edma_handle_t structure which stores the transfer state.
 */
void LPSPI_MasterTransferAbortEDMA(LPSPI_Type *base, lpspi_master_edma_handle_t *handle)
{
    assert(handle != NULL);

    LPSPI_DisableDMA(base, (uint32_t)kLPSPI_RxDmaEnable | (uint32_t)kLPSPI_TxDmaEnable);

    EDMA_AbortTransfer(handle->edmaRxRegToRxDataHandle);
    EDMA_AbortTransfer(handle->edmaTxDataToTxRegHandle);

    handle->state = (uint8_t)kLPSPI_Idle;
}

/*!
 * brief Gets the master eDMA transfer remaining bytes.
 *
 * This function gets the master eDMA transfer remaining bytes.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_master_edma_handle_t structure which stores the transfer state.
 * param count Number of bytes transferred so far by the EDMA transaction.
 * return status of status_t.
 */
status_t LPSPI_MasterTransferGetCountEDMA(LPSPI_Type *base, lpspi_master_edma_handle_t *handle, size_t *count)
{
    assert(handle != NULL);

    if (NULL == count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (handle->state != (uint8_t)kLPSPI_Busy)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    size_t remainingByte;

    remainingByte =
        (uint32_t)handle->nbytes * EDMA_GetRemainingMajorLoopCount(handle->edmaRxRegToRxDataHandle->base,
                                                                   handle->edmaRxRegToRxDataHandle->channel);

    *count = handle->totalByteCount - remainingByte;

    return kStatus_Success;
}

/*!
 * brief Initializes the LPSPI slave eDMA handle.
 *
 * This function initializes the LPSPI eDMA handle which can be used for other LPSPI transactional APIs.  Usually, for a
 * specified LPSPI instance, call this API once to get the initialized handle.
 *
 * Note that LPSPI eDMA has a separated (Rx and Tx as two sources) or shared (Rx  and Tx as the same source) DMA request
 * source.
 *
 * (1) For a separated DMA request source, enable and set the Rx DMAMUX source for edmaRxRegToRxDataHandle and
 * Tx DMAMUX source for edmaTxDataToTxRegHandle.
 * (2) For a shared DMA request source, enable and set the Rx/Rx DMAMUX source for edmaRxRegToRxDataHandle .
 *
 * param base LPSPI peripheral base address.
 * param handle LPSPI handle pointer to lpspi_slave_edma_handle_t.
 * param callback LPSPI callback.
 * param userData callback function parameter.
 * param edmaRxRegToRxDataHandle edmaRxRegToRxDataHandle pointer to edma_handle_t.
 * param edmaTxDataToTxRegHandle edmaTxDataToTxRegHandle pointer to edma_handle_t.
 */
void LPSPI_SlaveTransferCreateHandleEDMA(LPSPI_Type *base,
                                         lpspi_slave_edma_handle_t *handle,
                                         lpspi_slave_edma_transfer_callback_t callback,
                                         void *userData,
                                         edma_handle_t *edmaRxRegToRxDataHandle,
                                         edma_handle_t *edmaTxDataToTxRegHandle)
{
    assert(handle != NULL);
    assert(edmaRxRegToRxDataHandle != NULL);
    assert(edmaTxDataToTxRegHandle != NULL);

    /* Zero the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    uint32_t instance = LPSPI_GetInstance(base);

    s_lpspiSlaveEdmaPrivateHandle[instance].base   = base;
    s_lpspiSlaveEdmaPrivateHandle[instance].handle = handle;

    handle->callback = callback;
    handle->userData = userData;

    handle->edmaRxRegToRxDataHandle = edmaRxRegToRxDataHandle;
    handle->edmaTxDataToTxRegHandle = edmaTxDataToTxRegHandle;
}

/*!
 * brief LPSPI slave transfers data using eDMA.
 *
 * This function transfers data using eDMA. This is a non-blocking function, which return right away. When all data
 * is transferred, the callback function is called.
 *
 * Note:
 * The transfer data size should be an integer multiple of bytesPerFrame if bytesPerFrame is less than or equal to 4.
 * For bytesPerFrame greater than 4:
 * The transfer data size should be equal to bytesPerFrame if the bytesPerFrame is not an integer multiple of 4.
 * Otherwise, the transfer data size can be an integer multiple of bytesPerFrame.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_slave_edma_handle_t structure which stores the transfer state.
 * param transfer pointer to lpspi_transfer_t structure.
 * return status of status_t.
 */
status_t LPSPI_SlaveTransferEDMA(LPSPI_Type *base, lpspi_slave_edma_handle_t *handle, lpspi_transfer_t *transfer)
{
    assert(handle != NULL);
    assert(transfer != NULL);
    assert(LPSPI_GetRxFifoSize(base) >= 8U);

    /* Check that we're not busy. */
    if (handle->state == (uint8_t)kLPSPI_Busy)
    {
        return kStatus_LPSPI_Busy;
    }

    /* Check arguments */
    if (!LPSPI_CheckTransferArgument(base, transfer, true))
    {
        return kStatus_InvalidArgument;
    }

    /* Disable module before configuration. */
    LPSPI_Enable(base, false);

    LPSPI_PrepareTransferEDMA(base);

    bool isByteSwap        = ((transfer->configFlags & (uint32_t)kLPSPI_SlaveByteSwap) != 0U);
    uint32_t instance      = LPSPI_GetInstance(base);
    uint8_t dummyData      = g_lpspiDummyData[instance];
    uint32_t whichPcs      = (transfer->configFlags & LPSPI_SLAVE_PCS_MASK) >> LPSPI_SLAVE_PCS_SHIFT;
    uint32_t bytesPerFrame = ((LPSPI_GetTcr(base) & LPSPI_TCR_FRAMESZ_MASK) >> LPSPI_TCR_FRAMESZ_SHIFT) / 8U + 1U;
    /* Size of transferred data - how many bytes will be read/write from/to FIFO (RDR/TDR) at once */
    uint32_t blockSize  = MIN(bytesPerFrame, 4U);
    uint32_t addrOffset = getRegAddrOffset(blockSize, isByteSwap);
    uint32_t rxAddr     = LPSPI_GetRxRegisterAddress(base) + addrOffset;
    uint32_t txAddr     = LPSPI_GetTxRegisterAddress(base) + addrOffset;

    edma_transfer_config_t transferConfigRx = {0};
    edma_transfer_config_t transferConfigTx = {0};
    edma_tcd_t *softwareTCD_oneFifoBlockRx  = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[1]) & (~0x1FU));
    edma_tcd_t *softwareTCD_oneFifoBlockTx  = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[2]) & (~0x1FU));
    edma_tcd_t *softwareTCD_lastBytesRx     = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[3]) & (~0x1FU));
    edma_tcd_t *softwareTCD_lastBytesTx     = (edma_tcd_t *)((uint32_t)(&handle->lpspiSoftwareTCD[4]) & (~0x1FU));
    edma_tcd_t *nextTcd                     = NULL;

    handle->state = (uint8_t)kLPSPI_Busy;

    /* Used to compute transfered bytes - count of bytes transfered in each DMA request */
    handle->nbytes         = blockSize * 4U;
    handle->totalByteCount = transfer->dataSize;

    handle->oneFifoBlockRxWatermark = -1;
    handle->lastBytesRxWatermark    = -1;

    handle->txBuffIfNull =
        ((uint32_t)dummyData) | ((uint32_t)dummyData << 8) | ((uint32_t)dummyData << 16) | ((uint32_t)dummyData << 24);

    /* Enable module for following configuration of TCR to take effect. */
    LPSPI_Enable(base, true);

    /* For DMA transfer, mask the transmit data if the tx data is null, for rx the receive data should not be masked at
       any time since we use rx dma transfer finish cllback to indicate transfer finish. */
    base->TCR =
        (LPSPI_GetTcr(base) & ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK | LPSPI_TCR_BYSW_MASK | LPSPI_TCR_TXMSK_MASK)) |
        LPSPI_TCR_TXMSK(transfer->txData == NULL) | LPSPI_TCR_BYSW(isByteSwap) | LPSPI_TCR_PCS(whichPcs);


    /* Configure EDMA transfer/s for read */
    EDMA_SetCallback(handle->edmaRxRegToRxDataHandle, EDMA_LpspiSlaveCallback,
                     &s_lpspiSlaveEdmaPrivateHandle[instance]);
    EDMA_ResetChannel(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel);

    /* Count of blocks aligned to 4 FIFO words */
    uint32_t fourFifoBlocks = (transfer->dataSize / blockSize) / 4U;
    /* Count of blocks aligned to 1 FIFO words */
    uint32_t oneFifoBlocks = (transfer->dataSize / blockSize) % 4U;
    /* Count of bytes in oneFifoBlocks */
    uint32_t oneFifoBlockBytes = oneFifoBlocks * blockSize;

    uint32_t lastBytes = 0U;
    if (bytesPerFrame > 4U)
    {
        lastBytes = transfer->dataSize - (fourFifoBlocks * 4U * blockSize) - oneFifoBlockBytes;
    }

    if (lastBytes > 0U)
    {
        /* Case when framesize is > 4 bytes and not aligned to 4 bytes - transfer config to handle unaligned part (1 or 2 bytes) */
        transferConfigRx.srcAddr   = (uint32_t)LPSPI_GetRxRegisterAddress(base) + getRegAddrOffset(lastBytes, isByteSwap);
        transferConfigRx.srcOffset = 0;
        if (transfer->rxData != NULL)
        {
            transferConfigRx.destAddr   = (uint32_t)transfer->rxData + transfer->dataSize - oneFifoBlockBytes - lastBytes;
            transferConfigRx.destOffset = 1;
        }
        else
        {
            transferConfigRx.destAddr   = (uint32_t)&handle->rxBuffIfNull;
            transferConfigRx.destOffset = 0;
        }
        transferConfigRx.srcTransferSize  = getEdmaTransferSize(lastBytes);
        transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
        transferConfigRx.minorLoopBytes   = lastBytes;
        transferConfigRx.majorLoopCounts  = 1U;

#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
        EDMA_TcdResetExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_lastBytesRx);
        EDMA_TcdSetTransferConfigExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_lastBytesRx,
                                     &transferConfigRx, NULL);
        EDMA_TcdEnableInterruptsExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_lastBytesRx,
                                    (uint32_t)kEDMA_MajorInterruptEnable);
#else
        EDMA_TcdReset(softwareTCD_lastBytesRx);
        EDMA_TcdSetTransferConfig(softwareTCD_lastBytesRx, &transferConfigRx, NULL);
        EDMA_TcdEnableInterrupts(softwareTCD_lastBytesRx, (uint32_t)kEDMA_MajorInterruptEnable);
#endif
        nextTcd = softwareTCD_lastBytesRx;
        handle->lastBytesRxWatermark = 0;
    }

    if (oneFifoBlocks > 0U)
    {
        /* Transfer config for remaining FIFO words (1-3) */
        transferConfigRx.srcAddr   = (uint32_t)rxAddr;
        transferConfigRx.srcOffset = 0;
        if (transfer->rxData != NULL)
        {
            transferConfigRx.destAddr   = (uint32_t)transfer->rxData + transfer->dataSize - oneFifoBlockBytes;
            transferConfigRx.destOffset = 1;
        }
        else
        {
            transferConfigRx.destAddr   = (uint32_t)&handle->rxBuffIfNull;
            transferConfigRx.destOffset = 0;
        }
        transferConfigRx.srcTransferSize  = getEdmaTransferSize(blockSize);
        transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
        transferConfigRx.minorLoopBytes   = oneFifoBlockBytes;
        transferConfigRx.majorLoopCounts  = 1U;

        if (fourFifoBlocks > 0U)
        {
#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
            EDMA_TcdResetExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_oneFifoBlockRx);
            EDMA_TcdSetTransferConfigExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_oneFifoBlockRx,
                                         &transferConfigRx, nextTcd);
            EDMA_TcdEnableInterruptsExt(handle->edmaRxRegToRxDataHandle->base, softwareTCD_oneFifoBlockRx,
                                        (uint32_t)kEDMA_MajorInterruptEnable);
#else
            EDMA_TcdReset(softwareTCD_oneFifoBlockRx);
            EDMA_TcdSetTransferConfig(softwareTCD_oneFifoBlockRx, &transferConfigRx, nextTcd);
            EDMA_TcdEnableInterrupts(softwareTCD_oneFifoBlockRx, (uint32_t)kEDMA_MajorInterruptEnable);
#endif
            nextTcd = softwareTCD_oneFifoBlockRx;
        }
        else
        {
            EDMA_SetTransferConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                   &transferConfigRx, nextTcd);

            /* Enable edma interrupt to finish transfer */
            EDMA_EnableChannelInterrupts(handle->edmaRxRegToRxDataHandle->base,
                                         handle->edmaRxRegToRxDataHandle->channel,
                                         (uint32_t)kEDMA_MajorInterruptEnable);

            LPSPI_SetFifoWatermarks(base, 4U, (oneFifoBlocks - 1U));
            handle->nbytes = oneFifoBlockBytes;
        }
    }

    if (fourFifoBlocks > 0U)
    {
        /* Transfer config for part of data aligned to 4 FIFO entry */
        transferConfigRx.srcAddr   = (uint32_t)rxAddr;
        transferConfigRx.srcOffset = 0;
        if (transfer->rxData != NULL)
        {
            transferConfigRx.destAddr   = (uint32_t)transfer->rxData;
            transferConfigRx.destOffset = 1;
        }
        else
        {
            transferConfigRx.destAddr   = (uint32_t) & (handle->rxBuffIfNull);
            transferConfigRx.destOffset = 0;
        }
        transferConfigRx.srcTransferSize  = getEdmaTransferSize(blockSize);
        transferConfigRx.destTransferSize = kEDMA_TransferSize1Bytes;
        transferConfigRx.minorLoopBytes   = blockSize * 4U;
        transferConfigRx.majorLoopCounts  = fourFifoBlocks;

        if (oneFifoBlockBytes > 0U)
        {
            /* Set value for FIFO rx watermark for next part of data, used in EDMA_LpspiSlaveCallback() */
            handle->oneFifoBlockRxWatermark = (int8_t)(oneFifoBlocks - 1U);
        }

        EDMA_SetTransferConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                               &transferConfigRx, nextTcd);

        /* Enable edma interrupt to finish transfer or change FIFO rx watermark */
        EDMA_EnableChannelInterrupts(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                     (uint32_t)kEDMA_MajorInterruptEnable);

        /* Configure FIFO watermarks to be possible write/read 4 FIFO entry per each DMA request */
        LPSPI_SetFifoWatermarks(base, 4U, 3U);
    }

    EDMA_StartTransfer(handle->edmaRxRegToRxDataHandle);

    if (transfer->txData == NULL)
    {
        LPSPI_EnableDMA(base, (uint32_t)kLPSPI_RxDmaEnable);
        return kStatus_Success;
    }


    /* Configure EDMA transfer/s for write */
    EDMA_ResetChannel(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel);

    nextTcd = NULL;

    if (lastBytes > 0U)
    {
        /* Case when framesize is > 4 bytes and not aligned to 4 bytes - transfer config to handle unaligned part (1 or 2 bytes) */
        if (transfer->txData != NULL)
        {
            transferConfigTx.srcAddr   = (uint32_t)transfer->txData + transfer->dataSize - lastBytes;
            transferConfigTx.srcOffset = 1;
        }
        else
        {
            transferConfigTx.srcAddr   = (uint32_t)&handle->txBuffIfNull;
            transferConfigTx.srcOffset = 0;
        }
        transferConfigTx.destAddr         = (uint32_t)LPSPI_GetTxRegisterAddress(base) + getRegAddrOffset(lastBytes, isByteSwap);
        transferConfigTx.destOffset       = 0;
        transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
        transferConfigTx.destTransferSize = getEdmaTransferSize(lastBytes);
        transferConfigTx.minorLoopBytes   = lastBytes;
        transferConfigTx.majorLoopCounts  = 1U;

#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
        EDMA_TcdResetExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_lastBytesTx);
        EDMA_TcdSetTransferConfigExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_lastBytesTx,
                                     &transferConfigTx, nextTcd);
#else
        EDMA_TcdReset(softwareTCD_lastBytesTx);
        EDMA_TcdSetTransferConfig(softwareTCD_lastBytesTx, &transferConfigTx, nextTcd);
#endif
        nextTcd = softwareTCD_lastBytesTx;
    }

    if (oneFifoBlocks > 0U)
    {
        /* Transfer config for remaining FIFO words (1-3) */
        if (transfer->txData != NULL)
        {
            transferConfigTx.srcAddr   = (uint32_t)transfer->txData + transfer->dataSize - oneFifoBlockBytes - lastBytes;
            transferConfigTx.srcOffset = 1;
        }
        else
        {
            transferConfigTx.srcAddr   = (uint32_t)&handle->txBuffIfNull;
            transferConfigTx.srcOffset = 0;
        }

        transferConfigTx.destAddr         = (uint32_t)txAddr;
        transferConfigTx.destOffset       = 0;
        transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
        transferConfigTx.destTransferSize = getEdmaTransferSize(blockSize);
        transferConfigTx.minorLoopBytes   = oneFifoBlockBytes;
        transferConfigTx.majorLoopCounts  = 1U;

        if (fourFifoBlocks > 0U)
        {
#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
            EDMA_TcdResetExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_oneFifoBlockTx);
            EDMA_TcdSetTransferConfigExt(handle->edmaTxDataToTxRegHandle->base, softwareTCD_oneFifoBlockTx,
                                         &transferConfigTx, nextTcd);
#else
            EDMA_TcdReset(softwareTCD_oneFifoBlockTx);
            EDMA_TcdSetTransferConfig(softwareTCD_oneFifoBlockTx, &transferConfigTx, nextTcd);
#endif
            nextTcd = softwareTCD_oneFifoBlockTx;
        }
        else
        {
            EDMA_SetTransferConfig(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel,
                                   &transferConfigTx, nextTcd);
        }
    }

    if (fourFifoBlocks > 0U)
    {
        /* Transfer config for part of data aligned to 4 FIFO entry */
        if (transfer->txData != NULL)
        {
            transferConfigTx.srcAddr   = (uint32_t)transfer->txData;
            transferConfigTx.srcOffset = 1;
        }
        else
        {
            transferConfigTx.srcAddr   = (uint32_t)&handle->txBuffIfNull;
            transferConfigTx.srcOffset = 0;
        }
        transferConfigTx.destAddr         = (uint32_t)txAddr;
        transferConfigTx.destOffset       = 0;
        transferConfigTx.srcTransferSize  = kEDMA_TransferSize1Bytes;
        transferConfigTx.destTransferSize = getEdmaTransferSize(blockSize);
        transferConfigTx.minorLoopBytes   = blockSize * 4U;
        transferConfigTx.majorLoopCounts  = fourFifoBlocks;

        EDMA_SetTransferConfig(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel,
                               &transferConfigTx, nextTcd);
    }

    EDMA_StartTransfer(handle->edmaTxDataToTxRegHandle);
    LPSPI_EnableDMA(base, (uint32_t)kLPSPI_RxDmaEnable | (uint32_t)kLPSPI_TxDmaEnable);

    return kStatus_Success;
}

static void EDMA_LpspiSlaveCallback(edma_handle_t *edmaHandle, void *userData, bool transferDone, uint32_t tcds)
{
    assert(edmaHandle != NULL);
    assert(userData != NULL);

    lpspi_slave_edma_private_handle_t *lpspiEdmaPrivateHandle = (lpspi_slave_edma_private_handle_t *)userData;
    if (lpspiEdmaPrivateHandle->handle->oneFifoBlockRxWatermark > -1)
    {
        LPSPI_SetFifoWatermarks(lpspiEdmaPrivateHandle->base, 4U, lpspiEdmaPrivateHandle->handle->oneFifoBlockRxWatermark);
        lpspiEdmaPrivateHandle->handle->oneFifoBlockRxWatermark = -1;
        return;
    }

    if (lpspiEdmaPrivateHandle->handle->lastBytesRxWatermark > -1)
    {
        lpspiEdmaPrivateHandle->handle->lastBytesRxWatermark = -1;
        LPSPI_SetFifoWatermarks(lpspiEdmaPrivateHandle->base, 4U, lpspiEdmaPrivateHandle->handle->lastBytesRxWatermark);
        return;
    }

    LPSPI_DisableDMA(lpspiEdmaPrivateHandle->base, (uint32_t)kLPSPI_TxDmaEnable | (uint32_t)kLPSPI_RxDmaEnable);

    lpspiEdmaPrivateHandle->handle->state = (uint8_t)kLPSPI_Idle;

    if (lpspiEdmaPrivateHandle->handle->callback != NULL)
    {
        lpspiEdmaPrivateHandle->handle->callback(lpspiEdmaPrivateHandle->base, lpspiEdmaPrivateHandle->handle,
                                                 kStatus_Success, lpspiEdmaPrivateHandle->handle->userData);
    }
}

/*!
 * brief LPSPI slave aborts a transfer which is using eDMA.
 *
 * This function aborts a transfer which is using eDMA.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_slave_edma_handle_t structure which stores the transfer state.
 */
void LPSPI_SlaveTransferAbortEDMA(LPSPI_Type *base, lpspi_slave_edma_handle_t *handle)
{
    assert(handle != NULL);

    LPSPI_DisableDMA(base, (uint32_t)kLPSPI_RxDmaEnable | (uint32_t)kLPSPI_TxDmaEnable);

    EDMA_AbortTransfer(handle->edmaRxRegToRxDataHandle);
    EDMA_AbortTransfer(handle->edmaTxDataToTxRegHandle);

    handle->state = (uint8_t)kLPSPI_Idle;
}

/*!
 * brief Gets the slave eDMA transfer remaining bytes.
 *
 * This function gets the slave eDMA transfer remaining bytes.
 *
 * param base LPSPI peripheral base address.
 * param handle pointer to lpspi_slave_edma_handle_t structure which stores the transfer state.
 * param count Number of bytes transferred so far by the eDMA transaction.
 * return status of status_t.
 */
status_t LPSPI_SlaveTransferGetCountEDMA(LPSPI_Type *base, lpspi_slave_edma_handle_t *handle, size_t *count)
{
    assert(handle != NULL);

    if (NULL == count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (handle->state != (uint8_t)kLPSPI_Busy)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    size_t remainingByte;

    remainingByte =
        (uint32_t)handle->nbytes * EDMA_GetRemainingMajorLoopCount(handle->edmaRxRegToRxDataHandle->base,
                                                                   handle->edmaRxRegToRxDataHandle->channel);

    *count = handle->totalByteCount - remainingByte;

    return kStatus_Success;
}
