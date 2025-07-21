/*
 * Copyright 2022-2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_i3c_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.i3c_edma"
#endif

/*! @brief States for the state machine used by transactional APIs. */
enum _i3c_edma_transfer_states
{
    kIdleState = 0,
    kSlaveStartState,
    kIBIWonState,
    kBroadcastStartCtrlDoneState,
    kStartCtrlDoneState,
    kWaitRepeatedStartCompleteState,
    kWaitForCompletionState,
    kStopState,
    kStopCtrlDoneState,
};

/*! @brief Common sets of flags used by the driver. */
enum _i3c_edma_flag_constants
{
    /*! Necessary flags which are cleared by the driver upon starting a transfer. */
    kMasterClearFlags = kI3C_MasterControlDoneFlag | kI3C_MasterCompleteFlag | kI3C_MasterArbitrationWonFlag |
                        kI3C_MasterSlave2MasterFlag | kI3C_MasterErrorFlag,

    /*! IRQ sources enabled by initialization. */
    kMasterDMAIrqFlags = kI3C_MasterSlaveStartFlag | kI3C_MasterArbitrationWonFlag | kI3C_MasterErrorFlag |
                         kI3C_MasterSlave2MasterFlag | kI3C_MasterCompleteFlag | kI3C_MasterControlDoneFlag,

    /*! Errors to check for. */
    kMasterErrorFlags = kI3C_MasterErrorNackFlag | kI3C_MasterErrorWriteAbortFlag |
#if !defined(FSL_FEATURE_I3C_HAS_NO_MERRWARN_TERM) || (!FSL_FEATURE_I3C_HAS_NO_MERRWARN_TERM)
                        kI3C_MasterErrorTermFlag |
#endif
                        kI3C_MasterErrorParityFlag | kI3C_MasterErrorCrcFlag | kI3C_MasterErrorReadFlag |
                        kI3C_MasterErrorWriteFlag | kI3C_MasterErrorMsgFlag | kI3C_MasterErrorInvalidReqFlag |
                        kI3C_MasterErrorTimeoutFlag,
    /*! All flags which are cleared by the driver upon starting a transfer. */
    kSlaveClearFlags = kI3C_SlaveBusStartFlag | kI3C_SlaveMatchedFlag | kI3C_SlaveBusStopFlag,

    /*! IRQ sources enabled by the non-blocking transactional API. */
    kSlaveDMAIrqFlags = kI3C_SlaveBusStartFlag | kI3C_SlaveMatchedFlag |
                        kI3C_SlaveBusStopFlag | /*kI3C_SlaveRxReadyFlag |*/
                        kI3C_SlaveDynamicAddrChangedFlag | kI3C_SlaveReceivedCCCFlag | kI3C_SlaveErrorFlag |
                        kI3C_SlaveHDRCommandMatchFlag | kI3C_SlaveCCCHandledFlag | kI3C_SlaveEventSentFlag,

    /*! Errors to check for. */
    kSlaveErrorFlags = kI3C_SlaveErrorOverrunFlag | kI3C_SlaveErrorUnderrunFlag | kI3C_SlaveErrorUnderrunNakFlag |
                       kI3C_SlaveErrorTermFlag | kI3C_SlaveErrorInvalidStartFlag | kI3C_SlaveErrorSdrParityFlag |
                       kI3C_SlaveErrorHdrParityFlag | kI3C_SlaveErrorHdrCRCFlag | kI3C_SlaveErrorS0S1Flag |
                       kI3C_SlaveErrorOverreadFlag | kI3C_SlaveErrorOverwriteFlag,
};
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Array to map I3C instance number to base pointer. */
static I3C_Type *const kI3cBases[] = I3C_BASE_PTRS;

/*! @brief EDMA linked transfer descriptor. */
AT_NONCACHEABLE_SECTION_ALIGN(static edma_tcd_t s_edma_tcd[ARRAY_SIZE(kI3cBases)][3], 32);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void I3C_MasterPrepareEDMATransfer(I3C_Type *base, i3c_master_edma_handle_t *handle, i3c_direction_t direction);

/*******************************************************************************
 * Code
 ******************************************************************************/
static void I3C_MasterTransferEDMACallbackRx(edma_handle_t *dmaHandle, void *param, bool transferDone, uint32_t tcds)
{
    i3c_master_edma_handle_t *i3cHandle = (i3c_master_edma_handle_t *)param;

    if (transferDone)
    {
        /* Disable I3C Rx DMA. */
        i3cHandle->base->MDMACTRL &= ~I3C_MDMACTRL_DMAFB_MASK;

        /* If target send back the data logner as expect and controller can't get COMPLETE, stop the transfer here.
           If bus transfer is done normally, this function will do nothing. */
        if (i3cHandle->state != (uint8_t)kStopCtrlDoneState)
        {
            /* Terminate following data if present. */
            i3cHandle->base->MCTRL |= I3C_MCTRL_RDTERM(1U);
            i3cHandle->state = (uint8_t)kWaitForCompletionState;
            I3C_MasterTransferEDMAHandleIRQ(i3cHandle->base, i3cHandle);
        }
    }
}

static void I3C_MasterTransferEDMACallbackTx(edma_handle_t *dmaHandle, void *param, bool transferDone, uint32_t tcds)
{
    i3c_master_edma_handle_t *i3cHandle = (i3c_master_edma_handle_t *)param;

    if (transferDone)
    {
        /* Disable I3C Tx DMA. */
        i3cHandle->base->MDATACTRL &= ~I3C_MDMACTRL_DMATB_MASK;
    }
}

static void I3C_MasterEDMAEnable(I3C_Type *base, i3c_master_edma_handle_t *handle)
{
    bool isEnableTxDMA = false;
    bool isEnableRxDMA = false;

    if (handle->transfer.direction == kI3C_Write)
    {
        isEnableTxDMA = true;
    }
    else
    {
        if (handle->subaddressCount != 0U)
        {
            isEnableTxDMA = true;
        }
        isEnableRxDMA = true;
    }

    I3C_MasterEnableDMA(base, isEnableTxDMA, isEnableRxDMA, 1);
}

static status_t I3C_MasterEDMAPrepareStart(I3C_Type *base, i3c_master_edma_handle_t *handle)
{
    i3c_master_transfer_t *xfer = &handle->transfer;
    status_t result             = kStatus_Success;
    i3c_direction_t direction   = xfer->direction;

    if (xfer->busType != kI3C_TypeI3CDdr)
    {
        direction = (0UL != xfer->subaddressSize) ? kI3C_Write : xfer->direction;
    }

    /* Handle no start option. */
    if (0U != (xfer->flags & (uint32_t)kI3C_TransferNoStartFlag))
    {
        /* No need to send start flag, directly go to send command or data. */
        if (direction == kI3C_Write)
        {
            handle->state = (uint8_t)kWaitForCompletionState;
            I3C_MasterEDMAEnable(base, handle);
        }
        else
        {
            result = kStatus_InvalidArgument;
        }
    }
    else
    {
        /* If repeated start is requested, send repeated start. */
        if (0U !=
            (xfer->flags & ((uint32_t)kI3C_TransferRepeatedStartFlag | (uint32_t)kI3C_TransferStartWithBroadcastAddr)))
        {
            result = I3C_MasterRepeatedStart(base, xfer->busType, xfer->slaveAddress, direction);
        }
        else /* For normal transfer, send start. */
        {
            result = I3C_MasterStart(base, xfer->busType, xfer->slaveAddress, direction);
        }

        if (result == kStatus_Success)
        {
            handle->state = (uint8_t)kStartCtrlDoneState;
        }
    }

    return result;
}

/*!
 * brief Prepares the transfer state machine and fills in the command buffer.
 * param base  I3C base.
 * param handle  I3C master EDNA handle.
 */
static status_t I3C_MasterInitTransferStateMachineEDMA(I3C_Type *base, i3c_master_edma_handle_t *handle)
{
    i3c_master_transfer_t *xfer = &handle->transfer;
    status_t result             = kStatus_Success;

    /* Calculate command count and put into command buffer. */
    handle->subaddressCount = 0U;
    if (xfer->subaddressSize != 0U)
    {
        for (uint32_t i = xfer->subaddressSize; i > 0U; i--)
        {
            handle->subaddressBuffer[handle->subaddressCount++] = (uint8_t)((xfer->subaddress) >> (8U * (i - 1U)));
        }
    }

    /* Prepare the DMA Tx/Rx in advance. */
    I3C_MasterPrepareEDMATransfer(base, handle, handle->transfer.direction);

    if (0UL != (xfer->flags & (uint32_t)kI3C_TransferStartWithBroadcastAddr))
    {
        /* Issue 0x7E as start. */
        result = I3C_MasterStart(base, xfer->busType, 0x7E, kI3C_Write);
        if (result == kStatus_Success)
        {
            handle->state = (uint8_t)kBroadcastStartCtrlDoneState;
        }
    }
    else
    {
        result = I3C_MasterEDMAPrepareStart(base, handle);
    }

    return result;
}

static void I3C_SetEDMATcd(i3c_master_edma_handle_t *handle,
                           edma_transfer_config_t *xferConfig,
                           uint32_t tcdIdx,
                           bool isEndTcd)
{
    assert(tcdIdx < (sizeof(s_edma_tcd) / sizeof(edma_tcd_t) / ARRAY_SIZE(kI3cBases)));

    uint32_t instance   = I3C_GetInstance(handle->base);
    edma_tcd_t *edmaTcd = isEndTcd ? NULL : &s_edma_tcd[instance][tcdIdx + 1U];

#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
    EDMA_Type *edmaBase = handle->txDmaHandle->base;
    EDMA_TcdResetExt(edmaBase, &s_edma_tcd[instance][tcdIdx]);
#else
    EDMA_TcdReset(&s_edma_tcd[instance][tcdIdx]);
#endif

#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
    EDMA_TcdSetTransferConfigExt(edmaBase, &s_edma_tcd[instance][tcdIdx], xferConfig, edmaTcd);
#else
    EDMA_TcdSetTransferConfig(&s_edma_tcd[tcdIdx], xferConfig, edmaTcd);
#endif

    if (isEndTcd)
    {
#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
        EDMA_TcdEnableInterruptsExt(edmaBase, &s_edma_tcd[instance][tcdIdx], kEDMA_MajorInterruptEnable);
#else
        EDMA_TcdEnableInterrupts(&s_edma_tcd[instance][tcdIdx], kEDMA_MajorInterruptEnable);
#endif
    }
    else
    {
#if defined FSL_EDMA_DRIVER_EDMA4 && FSL_EDMA_DRIVER_EDMA4
        EDMA_TcdDisableInterruptsExt(edmaBase, &s_edma_tcd[instance][tcdIdx], kEDMA_MajorInterruptEnable);
#else
        EDMA_TcdDisableInterrupts(&s_edma_tcd[instance][tcdIdx], kEDMA_MajorInterruptEnable);
#endif
    }
}

static void I3C_MasterSetTxEDMA(I3C_Type *base,
                                i3c_master_edma_handle_t *handle,
                                edma_transfer_config_t *txChannelConfig,
                                void *data,
                                size_t dataSize)
{
    if (handle->transfer.busType == kI3C_TypeI3CDdr)
    {
        EDMA_PrepareTransfer(txChannelConfig, data, sizeof(uint8_t), (uint32_t *)(uint32_t)&base->MWDATAB1,
                             sizeof(uint8_t), 1, dataSize, kEDMA_MemoryToPeripheral);
        I3C_SetEDMATcd(handle, txChannelConfig, 0, true);
    }
    else
    {
        if (dataSize == 1U)
        {
            EDMA_PrepareTransfer(txChannelConfig, data, sizeof(uint8_t), (uint32_t *)(uint32_t)&base->MWDATABE,
                                 sizeof(uint8_t), 1, dataSize, kEDMA_MemoryToPeripheral);
            I3C_SetEDMATcd(handle, txChannelConfig, 0, true);
        }
        else
        {
            EDMA_PrepareTransfer(txChannelConfig, data, sizeof(uint8_t), (uint32_t *)(uint32_t)&base->MWDATAB1,
                                 sizeof(uint8_t), 1, dataSize - 1U, kEDMA_MemoryToPeripheral);
            I3C_SetEDMATcd(handle, txChannelConfig, 0, false);
            EDMA_PrepareTransfer(txChannelConfig, (uint8_t *)data + dataSize - 1U, sizeof(uint8_t),
                                 (uint32_t *)(uint32_t)&base->MWDATABE, sizeof(uint8_t), 1, 1U,
                                 kEDMA_MemoryToPeripheral);
            I3C_SetEDMATcd(handle, txChannelConfig, 1, true);
        }
    }
}

static void I3C_MasterPrepareEDMATransfer(I3C_Type *base, i3c_master_edma_handle_t *handle, i3c_direction_t direction)
{
    void *data        = handle->transfer.data;
    size_t dataSize   = handle->transfer.dataSize;
    uint32_t instance = I3C_GetInstance(base);
    edma_transfer_config_t xferConfig;

    handle->transferCount = handle->transfer.dataSize;

    if (direction == kI3C_Write)
    {
        if ((handle->subaddressCount != 0U) && (dataSize != 0U))
        {
            EDMA_PrepareTransfer(&xferConfig, &handle->subaddressBuffer[0], sizeof(uint8_t),
                                 (uint32_t *)(uint32_t)&base->MWDATAB1, sizeof(uint8_t), 1, handle->subaddressCount,
                                 kEDMA_MemoryToPeripheral);
            I3C_SetEDMATcd(handle, &xferConfig, 0, false);

            if (dataSize == 1U)
            {
                EDMA_PrepareTransfer(&xferConfig, data, sizeof(uint8_t), (uint32_t *)(uint32_t)&base->MWDATABE,
                                     sizeof(uint8_t), 1, 1, kEDMA_MemoryToPeripheral);
                I3C_SetEDMATcd(handle, &xferConfig, 1, true);
            }
            else
            {
                EDMA_PrepareTransfer(&xferConfig, data, sizeof(uint8_t), (uint32_t *)(uint32_t)&base->MWDATAB1,
                                     sizeof(uint8_t), 1, dataSize - 1U, kEDMA_MemoryToPeripheral);
                I3C_SetEDMATcd(handle, &xferConfig, 1, false);
                EDMA_PrepareTransfer(&xferConfig, (uint8_t *)data + dataSize - 1U, sizeof(uint8_t),
                                     (uint32_t *)(uint32_t)&base->MWDATABE, sizeof(uint8_t), 1, 1U,
                                     kEDMA_MemoryToPeripheral);
                I3C_SetEDMATcd(handle, &xferConfig, 2, true);
            }
        }
        else
        {
            data     = (handle->subaddressCount != 0U) ? (&handle->subaddressBuffer[0]) : handle->transfer.data;
            dataSize = (handle->subaddressCount != 0U) ? handle->subaddressCount : handle->transfer.dataSize;

            I3C_MasterSetTxEDMA(base, handle, &xferConfig, data, dataSize);
        }

        EDMA_InstallTCD(handle->txDmaHandle->base, handle->txDmaHandle->channel, &s_edma_tcd[instance][0]);
        EDMA_StartTransfer(handle->txDmaHandle);
    }
    else
    {
        if (handle->subaddressCount != 0U)
        {
            I3C_MasterSetTxEDMA(base, handle, &xferConfig, &handle->subaddressBuffer[0], handle->subaddressCount);
            EDMA_InstallTCD(handle->txDmaHandle->base, handle->txDmaHandle->channel, &s_edma_tcd[instance][0]);
            EDMA_StartTransfer(handle->txDmaHandle);
        }

#if defined(FSL_FEATURE_I3C_HAS_ERRATA_052086) && (FSL_FEATURE_I3C_HAS_ERRATA_052086)
        /* ERRATA052086: Soc integration issue results in target misses the last DMA request to copy the
        last one byte from controler when transmission data size is > 1 byte. Resolution: Triggering DMA
        interrupt one byte in advance, then receive the last one byte data after DMA transmission finishes. */
        if (dataSize > 1U)
        {
            dataSize--;
        }
#endif
        EDMA_PrepareTransfer(&xferConfig, (uint32_t *)(uint32_t)&base->MRDATAB, sizeof(uint8_t), data, sizeof(uint8_t),
                             1, dataSize, kEDMA_PeripheralToMemory);
        (void)EDMA_SubmitTransfer(handle->rxDmaHandle, &xferConfig);
        EDMA_StartTransfer(handle->rxDmaHandle);
    }
}

static void I3C_MasterRunTransferStateMachineEDMA(I3C_Type *base, i3c_master_edma_handle_t *handle, bool *isDone)
{
    bool state_complete = false;
    size_t rxCount      = 0;
    i3c_master_transfer_t *xfer;
    status_t result;
    uint32_t status;
    uint32_t errStatus;

    /* Set default isDone return value. */
    *isDone = false;

    /* Check for errors. */
    status = (uint32_t)I3C_MasterGetPendingInterrupts(base);
    I3C_MasterClearStatusFlags(base, status);

    i3c_master_state_t masterState = I3C_MasterGetState(base);
    errStatus                      = I3C_MasterGetErrorStatusFlags(base);
    result                         = I3C_MasterCheckAndClearError(base, errStatus);
    if (kStatus_Success != result)
    {
        handle->state  = (uint8_t)kStopState;
        handle->result = result;
    }
    else
    {
        if (0UL != (status & (uint32_t)kI3C_MasterSlave2MasterFlag))
        {
            if (handle->callback.slave2Master != NULL)
            {
                handle->callback.slave2Master(base, handle->userData);
            }
        }

        if ((0UL != (status & (uint32_t)kI3C_MasterSlaveStartFlag)) && (masterState == kI3C_MasterStateSlvReq))
        {
            handle->state = (uint8_t)kSlaveStartState;
        }

        if (handle->state == (uint8_t)kIdleState)
        {
            return;
        }
    }

    /* Get pointer to private data. */
    xfer = &handle->transfer;

    while (!state_complete)
    {
        /* Execute the state. */
        switch (handle->state)
        {
            case (uint8_t)kSlaveStartState:
                /* Emit start + 0x7E to ensure target always wins the arbrtration. */
                I3C_MasterEmitRequest(base, kI3C_RequestAutoIbi);
                handle->state  = (uint8_t)kIBIWonState;
                state_complete = true;
                break;

            case (uint8_t)kBroadcastStartCtrlDoneState:
                if (0UL != (status & (uint32_t)kI3C_MasterArbitrationWonFlag))
                {
                    handle->ibiFlag = true;
                }

                /* Check whether 0x7E START header succeeds or IBI wins. */
                if (0UL != (status & (uint32_t)kI3C_MasterControlDoneFlag))
                {
                    if (handle->ibiFlag)
                    {
                        handle->state   = (uint8_t)kIBIWonState;
                        handle->ibiFlag = false;
                    }
                    else
                    {
                        (void)I3C_MasterEDMAPrepareStart(base, handle);
                        state_complete = true;
                    }
                }
                else
                {
                    state_complete = true;
                }
                break;

            case (uint8_t)kStartCtrlDoneState:
                if (0UL != (status & (uint32_t)kI3C_MasterArbitrationWonFlag))
                {
                    handle->ibiFlag = true;
                }

                if (0UL != (status & (uint32_t)kI3C_MasterControlDoneFlag))
                {
                    if (handle->ibiFlag)
                    {
                        handle->state   = (uint8_t)kIBIWonState;
                        handle->ibiFlag = false;
                    }
                    else
                    {
                        /* For combination of write address and read data, need to do ReSTART after write. */
                        if ((xfer->subaddressSize != 0U) && (xfer->direction == kI3C_Read) &&
                            (xfer->busType != kI3C_TypeI3CDdr) && (0UL != xfer->dataSize))
                        {
                            handle->state = (uint8_t)kWaitRepeatedStartCompleteState;
                        }
                        else
                        {
                            handle->state = (uint8_t)kWaitForCompletionState;
                        }

                        I3C_MasterEDMAEnable(base, handle);
                        state_complete = true;
                    }
                }
                else
                {
                    state_complete = true;
                }
                break;

            case (uint8_t)kIBIWonState:
                if (masterState == kI3C_MasterStateIbiAck)
                {
                    handle->ibiType = I3C_GetIBIType(base);
                    if (handle->callback.ibiCallback != NULL)
                    {
                        handle->callback.ibiCallback(base, handle, handle->ibiType, kI3C_IbiAckNackPending);
                    }
                    else
                    {
                        I3C_MasterEmitIBIResponse(base, kI3C_IbiRespNack);
                    }
                }

                if (0UL != (status & (uint32_t)kI3C_MasterCompleteFlag))
                {
                    /* Make sure there is data in the Rx FIFO. */
                    rxCount = (base->MDATACTRL & I3C_MDATACTRL_RXCOUNT_MASK) >> I3C_MDATACTRL_RXCOUNT_SHIFT;
                    if (0UL != rxCount)
                    {
                        if ((handle->ibiBuff == NULL) && (handle->callback.ibiCallback != NULL))
                        {
                            handle->callback.ibiCallback(base, handle, kI3C_IbiNormal, kI3C_IbiDataBuffNeed);
                        }

                        do
                        {
                            uint8_t tempData = (uint8_t)base->MRDATAB;
                            if (handle->ibiBuff != NULL)
                            {
                                handle->ibiBuff[handle->ibiPayloadSize++] = tempData;
                            }
                        } while (--rxCount);
                    }

                    handle->ibiType    = I3C_GetIBIType(base);
                    handle->ibiAddress = I3C_GetIBIAddress(base);
                    handle->result     = kStatus_I3C_IBIWon;
                    handle->state      = (uint8_t)kStopState;
                }
                else
                {
                    state_complete = true;
                }
                break;

            case (uint8_t)kWaitRepeatedStartCompleteState:
                /* After Tx finishes, ReSTART receiving data. */
                if (0UL != (status & (uint32_t)kI3C_MasterCompleteFlag))
                {
                    (void)I3C_MasterRepeatedStart(base, xfer->busType, xfer->slaveAddress, kI3C_Read);
                    handle->state = (uint8_t)kWaitForCompletionState;
                }

                state_complete = true;
                break;

            case (uint8_t)kWaitForCompletionState:
                /* We stay in this state until the final part of data complete. */
                if (0UL != (status & (uint32_t)kI3C_MasterCompleteFlag))
                {
#if defined(FSL_FEATURE_I3C_HAS_ERRATA_052086) && (FSL_FEATURE_I3C_HAS_ERRATA_052086)
                    if (handle->transfer.direction == kI3C_Read)
                    {
                        if (handle->transfer.dataSize > 1U)
                        {
                            size_t rxCount;
                            uint32_t count;

                            /* If DMA finishes whole transfer or slave sends END in advance, break and read the last
                             * byte. */
                            do
                            {
                                count = EDMA_GetRemainingMajorLoopCount(handle->rxDmaHandle->base,
                                                                        handle->rxDmaHandle->channel);
                                I3C_MasterGetFifoCounts(handle->base, &rxCount, NULL);
                                if (0U == count)
                                {
                                    break;
                                }
                            } while (rxCount > 1U);

                            /* Read out the last byte data if there's non-handled byte in Rx FIFO. */
                            if (rxCount > 0U)
                            {
                                count = handle->transferCount - count;
                                *(uint8_t *)((uint32_t)(uint32_t *)handle->transfer.data + count - 1U) =
                                    (uint8_t)handle->base->MRDATAB;
                            }
                        }
                    }
#endif
                    handle->state = (uint8_t)kStopState;
                }
                else
                {
                    state_complete = true;
                }
                break;

            case (uint8_t)kStopState:
                /* Only issue a stop transition if the caller requested it. */
                if ((0UL == (xfer->flags & (uint32_t)kI3C_TransferNoStopFlag)) || (kStatus_Success != handle->result))
                {
                    /* Disable this interrupt in case there's slave request IBI interrupts the STOP finish event. */
                    I3C_MasterDisableInterrupts(base, (uint32_t)kI3C_MasterSlaveStartFlag);

                    if (masterState == kI3C_MasterStateDdr)
                    {
                        I3C_MasterEmitRequest(base, kI3C_RequestForceExit);
                    }
                    else
                    {
                        I3C_MasterEmitRequest(base, kI3C_RequestEmitStop);
                    }
                    handle->state = (uint8_t)kStopCtrlDoneState;
                }
                else
                {
                    *isDone = true;
                }
                state_complete = true;
                break;

            case (uint8_t)kStopCtrlDoneState:
                /* Waits for finial end event. */
                if (0UL != (status & (uint32_t)kI3C_MasterControlDoneFlag))
                {
                    I3C_MasterEnableInterrupts(base, (uint32_t)kI3C_MasterSlaveStartFlag);
                    *isDone = true;
                }
                state_complete = true;
                break;

            default:
                assert(false);
                break;
        }
    }
}

void I3C_MasterTransferCreateHandleEDMA(I3C_Type *base,
                                        i3c_master_edma_handle_t *handle,
                                        const i3c_master_edma_callback_t *callback,
                                        void *userData,
                                        edma_handle_t *rxDmaHandle,
                                        edma_handle_t *txDmaHandle)
{
    uint32_t instance;

    assert(NULL != handle);

    /* Clear out the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Look up instance number */
    instance = I3C_GetInstance(base);

    handle->base        = base;
    handle->txDmaHandle = txDmaHandle;
    handle->rxDmaHandle = rxDmaHandle;
    handle->callback    = *callback;
    handle->userData    = userData;

    /* Save this handle for IRQ use. */
    s_i3cMasterHandle[instance] = handle;

    /* Set irq handler. */
    s_i3cMasterIsr = I3C_MasterTransferEDMAHandleIRQ;

    EDMA_SetCallback(handle->rxDmaHandle, I3C_MasterTransferEDMACallbackRx, handle);
    EDMA_SetCallback(handle->txDmaHandle, I3C_MasterTransferEDMACallbackTx, handle);

    /* Clear all flags. */
    I3C_MasterClearErrorStatusFlags(base, (uint32_t)kMasterErrorFlags);
    I3C_MasterClearStatusFlags(base, (uint32_t)kI3C_MasterClearFlags);
    /* Reset fifos. These flags clear automatically. */
    base->MDATACTRL |= I3C_MDATACTRL_FLUSHTB_MASK | I3C_MDATACTRL_FLUSHFB_MASK;

    /* Enable NVIC IRQ, this only enables the IRQ directly connected to the NVIC.
     In some cases the I3C IRQ is configured through INTMUX, user needs to enable
     INTMUX IRQ in application code. */
    (void)EnableIRQ(kI3cIrqs[instance]);

    /* Clear internal IRQ enables and enable NVIC IRQ. */
    I3C_MasterEnableInterrupts(base, (uint32_t)kMasterDMAIrqFlags);
}

/*!
 * brief Performs a non-blocking DMA transaction on the I2C/I3C bus.
 *
 * param base The I3C peripheral base address.
 * param handle Pointer to the I3C master driver handle.
 * param transfer The pointer to the transfer descriptor.
 * retval #kStatus_Success The transaction was started successfully.
 * retval #kStatus_I3C_Busy Either another master is currently utilizing the bus, or a non-blocking
 *      transaction is already in progress.
 */
status_t I3C_MasterTransferEDMA(I3C_Type *base, i3c_master_edma_handle_t *handle, i3c_master_transfer_t *transfer)
{
    assert(NULL != handle);
    assert(NULL != transfer);
    assert(transfer->subaddressSize <= sizeof(transfer->subaddress));
    assert(!((0UL != (transfer->flags & (uint32_t)kI3C_TransferStartWithBroadcastAddr)) &&
             (0UL != (transfer->flags & (uint32_t)kI3C_TransferNoStartFlag))));
    assert(!((0UL != (transfer->flags & (uint32_t)kI3C_TransferStartWithBroadcastAddr)) &&
             (0UL != (transfer->flags & (uint32_t)kI3C_TransferRepeatedStartFlag))));

    i3c_master_state_t masterState = I3C_MasterGetState(base);
    bool checkDdrState             = false;
    status_t result;

    /* Check bus available in first. */
    checkDdrState = (transfer->busType == kI3C_TypeI3CDdr) ? (masterState != kI3C_MasterStateDdr) : true;
    if ((masterState != kI3C_MasterStateIdle) && (masterState != kI3C_MasterStateNormAct) && checkDdrState)
    {
        return kStatus_I3C_Busy;
    }

    I3C_MasterDisableInterrupts(base, (uint32_t)kMasterDMAIrqFlags);

    /* Return busy if another transaction is in progress. */
    if (handle->state != (uint8_t)kIdleState)
    {
        I3C_MasterEnableInterrupts(base, (uint32_t)kMasterDMAIrqFlags);
        return kStatus_I3C_Busy;
    }

    /* Save transfer into handle. */
    handle->transfer = *transfer;

    /* Configure IBI response type. */
    base->MCTRL &= ~I3C_MCTRL_IBIRESP_MASK;
    base->MCTRL |= I3C_MCTRL_IBIRESP(transfer->ibiResponse);

    /* Clear all flags. */
    I3C_MasterClearErrorStatusFlags(base, (uint32_t)kMasterErrorFlags);
    I3C_MasterClearStatusFlags(base, (uint32_t)kMasterClearFlags);

    /* Reset fifos. These flags clear automatically. */
    base->MDATACTRL |= I3C_MDATACTRL_FLUSHTB_MASK | I3C_MDATACTRL_FLUSHFB_MASK;

    /* Generate commands to send. */
    result = I3C_MasterInitTransferStateMachineEDMA(base, handle);

    I3C_MasterEnableInterrupts(base, (uint32_t)kMasterDMAIrqFlags);

    return result;
}

void I3C_MasterTransferEDMAHandleIRQ(I3C_Type *base, void *i3cHandle)
{
    i3c_master_edma_handle_t *handle = (i3c_master_edma_handle_t *)i3cHandle;
    bool isDone;

    /* Don't do anything if we don't have a valid handle. */
    if (NULL == handle)
    {
        return;
    }

    I3C_MasterRunTransferStateMachineEDMA(base, handle, &isDone);

    if (isDone)
    {
        I3C_MasterEnableDMA(base, false, false, 1);
        EDMA_AbortTransfer(handle->txDmaHandle);
        EDMA_AbortTransfer(handle->rxDmaHandle);
        base->MDATACTRL |= I3C_MDATACTRL_FLUSHTB_MASK | I3C_MDATACTRL_FLUSHFB_MASK;

        handle->state = (uint8_t)kIdleState;

        /* Invoke IBI user callback. */
        if ((handle->result == kStatus_I3C_IBIWon) && (handle->callback.ibiCallback != NULL))
        {
            handle->callback.ibiCallback(base, handle, handle->ibiType, kI3C_IbiReady);
            handle->ibiPayloadSize = 0;
        }

        /* Invoke bus transfer complete callback. */
        if (NULL != handle->callback.transferComplete)
        {
            handle->callback.transferComplete(base, handle, handle->result, handle->userData);
        }
        handle->result = kStatus_Success;
    }
}

/*!
 * brief Get master transfer status during a dma non-blocking transfer
 *
 * param base I3C peripheral base address
 * param handle pointer to i2c_master_edma_handle_t structure
 * param count Number of bytes transferred so far by the non-blocking transaction.
 */
status_t I3C_MasterTransferGetCountEDMA(I3C_Type *base, i3c_master_edma_handle_t *handle, size_t *count)
{
    assert(handle != NULL);

    if (NULL == count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (handle->state == (uint8_t)kIdleState)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    /* There is no necessity to disable interrupts as we read a single integer value */
    i3c_direction_t dir = handle->transfer.direction;

    if (dir == kI3C_Read)
    {
        *count = handle->transferCount -
                 1U * EDMA_GetRemainingMajorLoopCount(handle->rxDmaHandle->base, handle->rxDmaHandle->channel);
    }
    else
    {
        *count = handle->transferCount -
                 1U * EDMA_GetRemainingMajorLoopCount(handle->txDmaHandle->base, handle->txDmaHandle->channel);
    }

    return kStatus_Success;
}

/*!
 * brief Abort a master edma non-blocking transfer in a early time
 *
 * param base I3C peripheral base address
 * param handle pointer to i2c_master_edma_handle_t structure
 */
void I3C_MasterTransferAbortEDMA(I3C_Type *base, i3c_master_edma_handle_t *handle)
{
    if (handle->state != (uint8_t)kIdleState)
    {
        I3C_MasterEnableDMA(base, false, false, 1);
        EDMA_AbortTransfer(handle->txDmaHandle);
        EDMA_AbortTransfer(handle->rxDmaHandle);

        /* Reset fifos. These flags clear automatically. */
        base->MDATACTRL |= I3C_MDATACTRL_FLUSHTB_MASK | I3C_MDATACTRL_FLUSHFB_MASK;

        /* Send a stop command to finalize the transfer. */
        (void)I3C_MasterStop(base);

        /* Reset handle. */
        handle->state = (uint8_t)kIdleState;
    }
}

static void I3C_SlaveTransferEDMACallback(edma_handle_t *dmaHandle, void *param, bool transferDone, uint32_t tcds)
{
    i3c_slave_edma_handle_t *i3cHandle = (i3c_slave_edma_handle_t *)param;

    if (transferDone)
    {
        /* Simply disable dma enablement */
        if (i3cHandle->txDmaHandle == dmaHandle)
        {
            i3cHandle->base->SDMACTRL &= ~I3C_SDMACTRL_DMATB_MASK;

            if (i3cHandle->transfer.txDataSize > 1U)
            {
                /* Ensure there's space in the Tx FIFO. */
                while ((i3cHandle->base->SDATACTRL & I3C_SDATACTRL_TXFULL_MASK) != 0U)
                {
                }
                /* Send the last byte. */
                i3cHandle->base->SWDATABE =
                    *(uint8_t *)((uintptr_t)i3cHandle->transfer.txData + i3cHandle->transfer.txDataSize - 1U);
            }
        }
        else
        {
            i3cHandle->base->SDMACTRL &= ~I3C_SDMACTRL_DMAFB_MASK;
        }
    }
}

/*!
 * brief Create a new handle for the I3C slave DMA APIs.
 *
 * The creation of a handle is for use with the DMA APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the I3C_SlaveTransferAbortDMA() API shall be called.
 *
 * For devices where the I3C send and receive DMA requests are OR'd together, the @a txDmaHandle
 * parameter is ignored and may be set to NULL.
 *
 * param base The I3C peripheral base address.
 * param handle Pointer to the I3C slave driver handle.
 * param callback User provided pointer to the asynchronous callback function.
 * param userData User provided pointer to the application callback data.
 * param rxDmaHandle Handle for the DMA receive channel. Created by the user prior to calling this function.
 * param txDmaHandle Handle for the DMA transmit channel. Created by the user prior to calling this function.
 */
void I3C_SlaveTransferCreateHandleEDMA(I3C_Type *base,
                                       i3c_slave_edma_handle_t *handle,
                                       i3c_slave_edma_callback_t callback,
                                       void *userData,
                                       edma_handle_t *rxDmaHandle,
                                       edma_handle_t *txDmaHandle)
{
    uint32_t instance;

    assert(NULL != handle);

    /* Clear out the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Look up instance number */
    instance = I3C_GetInstance(base);

    handle->base        = base;
    handle->txDmaHandle = txDmaHandle;
    handle->rxDmaHandle = rxDmaHandle;
    handle->callback    = callback;
    handle->userData    = userData;

    /* Save this handle for IRQ use. */
    s_i3cSlaveHandle[instance] = handle;

    /* Set irq handler. */
    s_i3cSlaveIsr = I3C_SlaveTransferEDMAHandleIRQ;

    EDMA_SetCallback(handle->rxDmaHandle, I3C_SlaveTransferEDMACallback, handle);
    EDMA_SetCallback(handle->txDmaHandle, I3C_SlaveTransferEDMACallback, handle);

    /* Clear internal IRQ enables and enable NVIC IRQ. */
    I3C_SlaveDisableInterrupts(base, (uint32_t)kSlaveDMAIrqFlags);

    /* Enable NVIC IRQ, this only enables the IRQ directly connected to the NVIC.
     In some cases the I3C IRQ is configured through INTMUX, user needs to enable
     INTMUX IRQ in application code. */
    (void)EnableIRQ(kI3cIrqs[instance]);

    /* Enable IRQ. */
    I3C_SlaveEnableInterrupts(base, (uint32_t)kSlaveDMAIrqFlags);
}

static void I3C_SlavePrepareTxEDMA(I3C_Type *base, i3c_slave_edma_handle_t *handle)
{
    edma_transfer_config_t txConfig;
    uint32_t *txFifoBase;
    i3c_slave_edma_transfer_t *xfer = &handle->transfer;

    if (xfer->txDataSize == 1U)
    {
        txFifoBase = (uint32_t *)(uintptr_t)&base->SWDATABE;
        EDMA_PrepareTransfer(&txConfig, xfer->txData, 1, (void *)txFifoBase, 1, 1, xfer->txDataSize,
                             kEDMA_MemoryToPeripheral);
    }
    else
    {
        txFifoBase = (uint32_t *)(uintptr_t)&base->SWDATAB1;
        EDMA_PrepareTransfer(&txConfig, xfer->txData, 1, (void *)txFifoBase, 1, 1, xfer->txDataSize - 1U,
                             kEDMA_MemoryToPeripheral);
    }

    (void)EDMA_SubmitTransfer(handle->txDmaHandle, &txConfig);
    EDMA_StartTransfer(handle->txDmaHandle);
}

static void I3C_SlavePrepareRxEDMA(I3C_Type *base, i3c_slave_edma_handle_t *handle)
{
    uint32_t *rxFifoBase            = (uint32_t *)(uintptr_t)&base->SRDATAB;
    i3c_slave_edma_transfer_t *xfer = &handle->transfer;
    size_t dataSize                 = xfer->rxDataSize;
    edma_transfer_config_t rxConfig;

#if defined(FSL_FEATURE_I3C_HAS_ERRATA_052086) && (FSL_FEATURE_I3C_HAS_ERRATA_052086)
    /* ERRATA052086: Soc integration issue results in target misses the last DMA request to copy the
    last one byte from controler when transmission data size is > 1 byte. Resolution: Triggering DMA
    interrupt one byte in advance, then receive the last one byte data after DMA transmission finishes. */
    if (dataSize > 1U)
    {
        dataSize--;
    }
#endif

    EDMA_PrepareTransfer(&rxConfig, (void *)rxFifoBase, 1, xfer->rxData, 1, 1, dataSize, kEDMA_PeripheralToMemory);
    (void)EDMA_SubmitTransfer(handle->rxDmaHandle, &rxConfig);
    EDMA_StartTransfer(handle->rxDmaHandle);
}

/*!
 * brief Prepares for a non-blocking DMA-based transaction on the I3C bus.
 *
 * The API will do DMA configuration according to the input transfer descriptor, and the data will be transferred when
 * there's bus master requesting transfer from/to this slave. So the timing of call to this API need be aligned
 * with master application to ensure the transfer is executed as expected.
 * Callback specified when the @a handle was created is invoked when the transaction has completed.
 *
 * param base The I3C peripheral base address.
 * param handle Pointer to the I3C slave driver handle.
 * param transfer The pointer to the transfer descriptor.
 * param eventMask Bit mask formed by OR'ing together #i3c_slave_transfer_event_t enumerators to specify
 *      which events to send to the callback. The transmit and receive events is not allowed to be enabled.
 * retval kStatus_Success The transaction was started successfully.
 * retval #kStatus_I3C_Busy Either another master is currently utilizing the bus, or another DMA
 *      transaction is already in progress.
 * retval #kStatus_Fail The transaction can't be set.
 */
status_t I3C_SlaveTransferEDMA(I3C_Type *base,
                               i3c_slave_edma_handle_t *handle,
                               i3c_slave_edma_transfer_t *transfer,
                               uint32_t eventMask)
{
    assert(NULL != handle);
    assert(NULL != transfer);

    bool txDmaEn = false, rxDmaEn = false;

    if (handle->isBusy)
    {
        return kStatus_I3C_Busy;
    }
    /* Clear all flags. */
    I3C_SlaveClearErrorStatusFlags(base, (uint32_t)kSlaveErrorFlags);
    I3C_SlaveClearStatusFlags(base, (uint32_t)kSlaveClearFlags);
    /* Reset fifos. These flags clear automatically. */
    base->SDATACTRL |= I3C_SDATACTRL_FLUSHTB_MASK | I3C_SDATACTRL_FLUSHFB_MASK;

    handle->transfer = *transfer;

    /* Set up event mask. */
    handle->eventMask = eventMask;

    if ((transfer->txData != NULL) && (transfer->txDataSize != 0U))
    {
        I3C_SlavePrepareTxEDMA(base, handle);
        txDmaEn = true;
    }

    if ((transfer->rxData != NULL) && (transfer->rxDataSize != 0U))
    {
        I3C_SlavePrepareRxEDMA(base, handle);
        rxDmaEn = true;
    }

    if (txDmaEn || rxDmaEn)
    {
        I3C_SlaveEnableDMA(base, txDmaEn, rxDmaEn, 1);
        return kStatus_Success;
    }
    else
    {
        return kStatus_Fail;
    }
}

void I3C_SlaveTransferEDMAHandleIRQ(I3C_Type *base, void *i3cHandle)
{
    uint32_t flags;
    uint32_t errFlags;
    i3c_slave_edma_transfer_t *xfer;

    i3c_slave_edma_handle_t *handle = (i3c_slave_edma_handle_t *)i3cHandle;
    /* Check for a valid handle in case of a spurious interrupt. */
    if (NULL == handle)
    {
        return;
    }

    xfer = &handle->transfer;

    /* Get status flags. */
    flags    = I3C_SlaveGetStatusFlags(base);
    errFlags = I3C_SlaveGetErrorStatusFlags(base);

    /* Clear status flags. */
    I3C_SlaveClearStatusFlags(base, flags);

    if (0UL != (errFlags & (uint32_t)kSlaveErrorFlags))
    {
        xfer->event            = (uint32_t)kI3C_SlaveCompletionEvent;
        xfer->completionStatus = I3C_SlaveCheckAndClearError(base, errFlags);

        if ((0UL != (handle->eventMask & (uint32_t)kI3C_SlaveCompletionEvent)) && (NULL != handle->callback))
        {
            handle->callback(base, xfer, handle->userData);
        }
        return;
    }

    if (0UL != (flags & (uint32_t)kI3C_SlaveEventSentFlag))
    {
        xfer->event = (uint32_t)kI3C_SlaveRequestSentEvent;
        if ((0UL != (handle->eventMask & xfer->event)) && (NULL != handle->callback))
        {
            handle->callback(base, xfer, handle->userData);
        }
    }

    if (0UL != (flags & (uint32_t)kI3C_SlaveReceivedCCCFlag))
    {
        handle->isBusy = true;
        xfer->event    = (uint32_t)kI3C_SlaveReceivedCCCEvent;
        if ((0UL != (handle->eventMask & xfer->event)) && (NULL != handle->callback))
        {
            handle->callback(base, xfer, handle->userData);
        }
    }

    if (0UL != (flags & (uint32_t)kI3C_SlaveBusStopFlag))
    {
        if (handle->isBusy)
        {
#if defined(FSL_FEATURE_I3C_HAS_ERRATA_052086) && (FSL_FEATURE_I3C_HAS_ERRATA_052086)
            if (handle->transfer.rxDataSize > 1U)
            {
                size_t leftCount = handle->isDdrMode ? 2U : 1U;
                size_t rxCount;
                size_t count;
                do
                {
                    count = EDMA_GetRemainingMajorLoopCount(handle->rxDmaHandle->base, handle->rxDmaHandle->channel);
                    I3C_SlaveGetFifoCounts(handle->base, &rxCount, NULL);
                    if (0U == count)
                    {
                        break;
                    }
                } while (rxCount > leftCount);

                if (rxCount > 0U)
                {
                    count                                                         = handle->transfer.rxDataSize - count;
                    *(uint8_t *)((uintptr_t)handle->transfer.rxData + count - 1U) = (uint8_t)handle->base->SRDATAB;
                }
            }
            handle->isDdrMode = false;
#endif
            I3C_SlaveTransferAbortEDMA(base, handle);
            xfer->event            = (uint32_t)kI3C_SlaveCompletionEvent;
            xfer->completionStatus = kStatus_Success;
            handle->isBusy         = false;

            if ((0UL != (handle->eventMask & xfer->event)) && (NULL != handle->callback))
            {
                handle->callback(base, xfer, handle->userData);
            }
        }
        else
        {
            return;
        }
    }

    if (0UL != (flags & (uint32_t)kI3C_SlaveMatchedFlag))
    {
        xfer->event    = (uint32_t)kI3C_SlaveAddressMatchEvent;
        handle->isBusy = true;
        if ((0UL != (handle->eventMask & (uint32_t)kI3C_SlaveAddressMatchEvent)) && (NULL != handle->callback))
        {
            handle->callback(base, xfer, handle->userData);
        }
    }

    if (0UL != (flags & (uint32_t)kI3C_SlaveBusHDRModeFlag))
    {
        handle->isBusy = true;
#if defined(FSL_FEATURE_I3C_HAS_ERRATA_052086) && (FSL_FEATURE_I3C_HAS_ERRATA_052086)
        handle->isDdrMode = true;
#endif
    }
}

/*!
 * brief Abort a slave dma non-blocking transfer in a early time
 *
 * param base I3C peripheral base address
 * param handle pointer to i3c_slave_edma_handle_t structure
 */
void I3C_SlaveTransferAbortEDMA(I3C_Type *base, i3c_slave_edma_handle_t *handle)
{
    if (handle->isBusy)
    {
        EDMA_AbortTransfer(handle->txDmaHandle);
        EDMA_AbortTransfer(handle->rxDmaHandle);

        I3C_SlaveEnableDMA(base, false, false, 0);

        /* Reset fifos. These flags clear automatically. */
        base->SDATACTRL |= I3C_SDATACTRL_FLUSHTB_MASK | I3C_SDATACTRL_FLUSHFB_MASK;
    }
}
