/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020, 2022-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexio_qspi_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexio_qspi_edma"
#endif

/*<! Structure definition for spi_edma_private_handle_t. The structure is private. */
typedef struct _flexio_qspi_master_edma_private_handle
{
    FLEXIO_QSPI_Type *base;
    flexio_qspi_master_edma_handle_t *handle;
} flexio_qspi_master_edma_private_handle_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief EDMA callback function for FLEXIO SPI send transfer.
 *
 * @param handle EDMA handle pointer.
 * @param param Callback function parameter.
 */
static void FLEXIO_QSPI_TxEDMACallback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

/*!
 * @brief EDMA config for FLEXIO SPI transfer.
 *
 * @param base pointer to FLEXIO_QSPI_Type structure.
 * @param handle pointer to flexio_qspi_master_edma_handle_t structure to store the transfer state.
 * @param xfer Pointer to flexio spi transfer structure.
 * @retval kStatus_Success Successfully create the handle.
 * @retval kStatus_InvalidArgument The transfer size is not supported.
 */
static status_t FLEXIO_QSPI_EDMAConfig(FLEXIO_QSPI_Type *base,
                                      flexio_qspi_master_edma_handle_t *handle,
                                      flexio_qspi_transfer_t *xfer);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*< @brief user configurable flexio spi handle count. */
#define FLEXIO_QSPI_HANDLE_COUNT 2

AT_NONCACHEABLE_SECTION_ALIGN(
    static edma_tcd_t tcdMemoryPoolPtr[FLEXIO_QSPI_HANDLE_COUNT][FLEXIO_QSPI_BUF_MAX], sizeof(edma_tcd_t));

/*<! Private handle only used for internally. */
static flexio_qspi_master_edma_private_handle_t s_edmaPrivateHandle[FLEXIO_QSPI_HANDLE_COUNT];

/*******************************************************************************
 * Code
 ******************************************************************************/

static void FLEXIO_QSPI_TxEDMACallback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    tcds                                                      = tcds;
    flexio_qspi_master_edma_private_handle_t *spiPrivateHandle = (flexio_qspi_master_edma_private_handle_t *)param;

    /* Disable Tx DMA */
    if (transferDone)
    {
        EDMA_AbortTransfer(spiPrivateHandle->handle->txHandle);
        FLEXIO_QSPI_EnableDMA(spiPrivateHandle->base, (uint32_t)kFLEXIO_QSPI_TxDmaEnable, false);

        /* change the state */
        spiPrivateHandle->handle->txInProgress = false;

        /* All finished, call the callback */
        if (spiPrivateHandle->handle->txInProgress == false)
        {
            if (spiPrivateHandle->handle->callback != NULL)
            {
                (spiPrivateHandle->handle->callback)(spiPrivateHandle->base, spiPrivateHandle->handle, kStatus_Success,
                                                     spiPrivateHandle->handle->userData);
            }
        }
    }
}

static status_t FLEXIO_QSPI_EDMAConfig(FLEXIO_QSPI_Type *base,
                                      flexio_qspi_master_edma_handle_t *handle,
                                      flexio_qspi_transfer_t *xfer)
{
    edma_transfer_config_t xferConfig      = {0};
    
    for(uint32_t i = 0; i < FLEXIO_QSPI_BUF_MAX; i++)
    {
        handle->bufs[i] = xfer->bufs[i];
    }

    EDMA_AbortTransfer(handle->txHandle);
    /* Save total transfer size. */
    for(uint32_t i = 0; i < FLEXIO_QSPI_BUF_MAX; i++)
    {
        if(handle->bufs[i].txData == NULL)
        {
            break;
        }
        /* Configure tx transfer EDMA. */
        xferConfig.destAddr   =FLEXIO_GetShifterBufferAddress(base->flexioBase, kFLEXIO_ShifterBufferNibbleByteSwapped,
                                                                kFLEXIO_QSPI_SHIFTBUF0);
        xferConfig.destOffset = 0;
        xferConfig.srcTransferSize  = kEDMA_TransferSize4Bytes;
        xferConfig.destTransferSize = kEDMA_TransferSize4Bytes;
        xferConfig.minorLoopBytes   = 4U;
        xferConfig.srcOffset = 4U;
        xferConfig.srcAddr   = (uint32_t)(xfer->bufs[i].txData);
        xferConfig.majorLoopCounts = xfer->bufs[i].dataSize;

        (void)EDMA_SubmitTransfer(handle->txHandle, &xferConfig);
        /* Disable major interrupt */
        EDMA_TcdDisableInterrupts(&handle->txHandle->tcdPool[i], kEDMA_MajorInterruptEnable);
    }

    /* Disable major interrupt */
    if(handle->txHandle->tcdUsed != 1)
    {
        EDMA_DisableChannelInterrupts(handle->txHandle->base, handle->txHandle->channel, kEDMA_MajorInterruptEnable);
    }
    /* Enable major interrupt */
    EDMA_TcdEnableInterrupts(&handle->txHandle->tcdPool[handle->txHandle->tcdUsed - 1], kEDMA_MajorInterruptEnable);
    
    /* Always start tx transfer. */
    if (handle->txHandle != NULL)
    {
        handle->txInProgress = true;
        FLEXIO_QSPI_EnableDMA(base, (uint32_t)kFLEXIO_QSPI_TxDmaEnable, true);
        EDMA_StartTransfer(handle->txHandle);
    }

    return kStatus_Success;
}

/*!
 * brief Initializes the FlexIO SPI master eDMA handle.
 *
 * This function initializes the FlexIO SPI master eDMA handle which can be used for other FlexIO SPI master
 * transactional
 * APIs.
 * For a specified FlexIO SPI instance, call this API once to get the initialized handle.
 *
 * param base Pointer to FLEXIO_QSPI_Type structure.
 * param handle Pointer to flexio_qspi_master_edma_handle_t structure to store the transfer state.
 * param callback SPI callback, NULL means no callback.
 * param userData callback function parameter.
 * param txHandle User requested eDMA handle for FlexIO SPI TX eDMA transfer.
 * retval kStatus_Success Successfully create the handle.
 * retval kStatus_OutOfRange The FlexIO SPI eDMA type/handle table out of range.
 */
status_t FLEXIO_QSPI_MasterTransferCreateHandleEDMA(FLEXIO_QSPI_Type *base,
                                                   flexio_qspi_master_edma_handle_t *handle,
                                                   flexio_qspi_master_edma_transfer_callback_t callback,
                                                   void *userData,
                                                   edma_handle_t *txHandle)
{
    assert(handle != NULL);

    uint8_t index = 0;

    /* Find the an empty handle pointer to store the handle. */
    for (index = 0U; index < (uint8_t)FLEXIO_QSPI_HANDLE_COUNT; index++)
    {
        if (s_edmaPrivateHandle[index].base == NULL)
        {
            s_edmaPrivateHandle[index].base   = base;
            s_edmaPrivateHandle[index].handle = handle;
            break;
        }
    }

    if (index == (uint16_t)FLEXIO_QSPI_HANDLE_COUNT)
    {
        return kStatus_OutOfRange;
    }

    /* Set spi base to handle. */
    handle->txHandle = txHandle;

    /* Register callback and userData. */
    handle->callback = callback;
    handle->userData = userData;

    /* Set SPI state to idle. */
    handle->txInProgress = false;

    /* Install TCD memory for using only one TCD queue. */
    EDMA_InstallTCDMemory(handle->txHandle, (edma_tcd_t *)&tcdMemoryPoolPtr[index], FLEXIO_QSPI_BUF_MAX);

    /* Install callback for Tx dma channel. */
    if (handle->txHandle != NULL)
    {
        EDMA_SetCallback(handle->txHandle, FLEXIO_QSPI_TxEDMACallback, &s_edmaPrivateHandle[index]);
    }

    return kStatus_Success;
}

/*!
 * brief Performs a non-blocking FlexIO SPI transfer using eDMA.
 *
 * note This interface returns immediately after transfer initiates. Call
 * FLEXIO_QSPI_MasterGetTransferCountEDMA to poll the transfer status and check
 * whether the FlexIO SPI transfer is finished.
 *
 * param base Pointer to FLEXIO_QSPI_Type structure.
 * param handle Pointer to flexio_qspi_master_edma_handle_t structure to store the transfer state.
 * param xfer Pointer to FlexIO SPI transfer structure.
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_FLEXIO_QSPI_Busy FlexIO SPI is not idle, is running another transfer.
 */
status_t FLEXIO_QSPI_MasterTransferEDMA(FLEXIO_QSPI_Type *base,
                                       flexio_qspi_master_edma_handle_t *handle,
                                       flexio_qspi_transfer_t *xfer)
{
    assert(handle != NULL);
    assert(xfer != NULL);

    /* Check if the device is busy. */
    if (handle->txInProgress)
    {
        return kStatus_FLEXIO_SPI_Busy;
    }

    /* Check if the argument is legal. */
    if (xfer->bufs[0].txData == NULL)
    {
        return kStatus_InvalidArgument;
    }

    for(uint32_t i = 0; i < FLEXIO_QSPI_BUF_MAX; i++)
    {
        if ((uint32_t)xfer->bufs[i].txData & 0x3U) {
            return kStatus_InvalidArgument;
        }
    }

    /* Timer1 controls the CS signal which enables/disables(asserts/deasserts) when timer0 enable/disable. Timer0
       enables when tx shifter is written and disables when timer compare. The timer compare event causes the
       transmit shift registers to load which generates a tx register empty event. Since when timer stop bit is
       disabled, a timer enable condition can be detected in the same cycle as a timer disable condition, so if
       software writes the tx register upon the detection of tx register empty event, the timer enable condition
       is triggered again, then the CS signal can remain low until software no longer writes the tx register. */
    if ((xfer->flags & (uint8_t)kFLEXIO_SPI_csContinuous) != 0U)
    {
        base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] =
            (base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] & ~FLEXIO_TIMCFG_TSTOP_MASK) |
            FLEXIO_TIMCFG_TSTOP(kFLEXIO_TimerStopBitDisabled);
    }
    else
    {
        base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] =
            (base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] & ~FLEXIO_TIMCFG_TSTOP_MASK) |
            FLEXIO_TIMCFG_TSTOP(kFLEXIO_TimerStopBitEnableOnTimerDisable);
    }

    return FLEXIO_QSPI_EDMAConfig(base, handle, xfer);
}