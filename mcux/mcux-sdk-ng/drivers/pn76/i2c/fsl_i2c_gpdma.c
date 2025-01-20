/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_i2c_gpdma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_i2c_gpdma"
#endif

/*! @brief Structure definition for i2c_master_gpdma_private_handle_t. The structure is private. */
typedef struct _i2c_master_gpdma_private_handle
{
    I2C_Type *base;
    i2c_master_gpdma_handle_t *handle;
} i2c_master_gpdma_private_handle_t;

/*! @brief Structure definition for i2c_slave_gpdma_private_handle_t. The structure is private. */
typedef struct _i2c_slave_gpdma_private_handle
{
    I2C_Type *base;
    i2c_slave_gpdma_handle_t *handle;
} i2c_slave_gpdma_private_handle_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! Private handle only used internally. */
static i2c_master_gpdma_private_handle_t s_masterGpdmaPrivateHandle[FSL_FEATURE_SOC_I2C_COUNT];

/*! Private handle only used internally. */
static i2c_slave_gpdma_private_handle_t s_slaveGpdmaPrivateHandle[FSL_FEATURE_SOC_I2C_COUNT];
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief GPDMA callback for I2C master GPDMA driver.
 *
 * @param handle GPDMA handler for I2C master GPDMA driver
 * @param userData user param passed to the callback function
 */
static void I2C_MasterTransferCallbackGPDMA(gpdma_handle_t *handle, void *userData, uint32_t status);

/*!
 * @brief Set up master transfer, send slave address and sub address(if any), wait until the
 * wait until address sent status return.
 *
 * @param base I2C peripheral base address.
 * @param handle pointer to i2c_master_gpdma_handle_t structure which stores the transfer state.
 * @param xfer pointer to i2c_master_transfer_t structure.
 */
static status_t I2C_InitTransferStateMachineGPDMA(I2C_Type *base,
                                                  i2c_master_gpdma_handle_t *handle,
                                                  i2c_master_transfer_t *xfer);

static void I2C_RunGPDMATransfer(I2C_Type *base, i2c_master_gpdma_handle_t *handle);

/*!
 * @brief Execute states until the transfer is done.
 * @param handle Master nonblocking driver handle.
 * @param[out] isDone Set to true if the transfer has completed.
 * @retval #kStatus_Success
 * @retval #kStatus_I2C_ArbitrationLost
 * @retval #kStatus_I2C_Nak
 */
static status_t I2C_RunTransferStateMachineGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle, bool *isDone);

/*!
 * @brief Invoke event from I2C_SlaveTransferGPDMAHandleIRQ().
 *
 * Sets the event type to transfer structure and invokes the event callback, if it has been
 * enabled by eventMask.
 *
 * @param base The I2C peripheral base address.
 * @param handle The I2C slave handle for GPDMA APIs.
 * @param event The I2C slave event to invoke.
 */
static void I2C_SlaveInvokeEventGPDMA(I2C_Type *base,
                                      i2c_slave_gpdma_handle_t *handle,
                                      i2c_slave_transfer_event_t event);
/*!
 * @brief Handle slave address match event.
 *
 * Called by Slave interrupt routine to ACK or NACK the matched address.
 * It also determines master direction (read or write).
 *
 * @param base The I2C peripheral base address.
 * @return true if the matched address is ACK'ed
 * @return false if the matched address is NACK'ed
 */
static bool I2C_SlaveAddressIRQ(I2C_Type *base, i2c_slave_gpdma_handle_t *handle);
/*!
 * @brief GPDMA callback for I2C slave GPDMA driver.
 *
 * @param handle GPDMA handler for I2C slave GPDMA driver
 * @param userData user param passed to the callback function
 */
static void I2C_SlaveTransferCallbackGPDMA(gpdma_handle_t *handle, void *userData, uint32_t status);

/*******************************************************************************
 * Codes
 ******************************************************************************/
static status_t I2C_InitTransferStateMachineGPDMA(I2C_Type *base,
                                                  i2c_master_gpdma_handle_t *handle,
                                                  i2c_master_transfer_t *xfer)
{
    struct _i2c_master_transfer *transfer;

    handle->transfer = *xfer;
    transfer         = &(handle->transfer);

    handle->remainingBytesGPDMA = 0U;
    handle->buf                 = (uint8_t *)transfer->data;
    handle->remainingSubaddr    = 0U;

    if ((transfer->flags & (uint32_t)kI2C_TransferNoStartFlag) != 0U)
    {
        handle->checkAddrNack = false;
        /* Start condition shall not be ommited, switch directly to next phase */
        if (transfer->dataSize == 0U)
        {
            handle->state = (uint8_t)kStopState;
        }
        else if (handle->transfer.direction == kI2C_Write)
        {
            handle->state = (uint8_t)kTransmitDataState;
        }
        else if (handle->transfer.direction == kI2C_Read)
        {
            handle->state = (uint8_t)kReceiveDataState;
        }
        else
        {
            return kStatus_I2C_InvalidParameter;
        }
    }
    else
    {
        if (transfer->subaddressSize != 0U)
        {
            int i;
            uint32_t subaddress;

            if (transfer->subaddressSize > sizeof(handle->subaddrBuf))
            {
                return kStatus_I2C_InvalidParameter;
            }

            /* Prepare subaddress transmit buffer, most significant byte is stored at the lowest address */
            subaddress = xfer->subaddress;
            for (i = (int)xfer->subaddressSize - 1; i >= 0; i--)
            {
                handle->subaddrBuf[i] = (uint8_t)subaddress & 0xffU;
                subaddress >>= 8;
            }
            handle->remainingSubaddr = transfer->subaddressSize;
        }

        handle->state         = (uint8_t)kStartState;
        handle->checkAddrNack = true;
    }

    return kStatus_Success;
}

static void I2C_RunGPDMATransfer(I2C_Type *base, i2c_master_gpdma_handle_t *handle)
{
    uint32_t transfer_size;
    gpdma_transfer_config_t xferConfig;
    uint32_t address;
    address = (uint32_t)&base->MSTDAT;

    /* Check if there is anything to be transferred at all */
    if (handle->remainingBytesGPDMA == 0U)
    {
        /* No data to be transferrred, disable GPDMA */
        base->MSTCTL = 0;
        if (handle->transfer.direction == kI2C_Read)
        {
            /* No more data expected, issue NACK and STOP right away */
            if (handle->state == (uint8_t)kReceiveDataState)
            {
                handle->state = (uint8_t)kWaitForCompletionState;
                if (0U == (handle->transfer.flags & (uint32_t)kI2C_TransferNoStopFlag))
                {
                    base->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;
                }
            }
        }
        return;
    }

    /* Calculate transfer size */
    transfer_size = handle->remainingBytesGPDMA;
    if (transfer_size > (uint32_t)I2C_MAX_GPDMA_TRANSFER_COUNT)
    {
        transfer_size = (uint32_t)I2C_MAX_GPDMA_TRANSFER_COUNT;
    }

    switch (handle->transfer.direction)
    {
        case kI2C_Write:
            GPDMA_PrepareTransferConfig(&xferConfig, handle->buf, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                        (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                        transfer_size, kGPDMA_TransferM2PControllerDma, 0UL);
            break;

        case kI2C_Read:
            GPDMA_PrepareTransferConfig(&xferConfig, (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                        handle->buf, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes, transfer_size,
                                        kGPDMA_TransferP2MControllerDma, 0UL);
            break;

        default:
            /* This should never happen */
            assert(false);
            break;
    }

    (void)GPDMA_SubmitTransfer(handle->gpdmaHandle, &xferConfig);
    GPDMA_StartTransfer(handle->gpdmaHandle);

    handle->remainingBytesGPDMA -= transfer_size;
    handle->buf += transfer_size;
    handle->checkAddrNack = false;
}

static status_t I2C_RunTransferStateMachineGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle, bool *isDone)
{
    uint32_t status;
    uint32_t master_state;
    struct _i2c_master_transfer *transfer;
    gpdma_transfer_config_t xferConfig;
    status_t err;
    uint32_t start_flag = 0U;
    uint32_t address;
    address = (uint32_t)&base->MSTDAT;

    transfer = &(handle->transfer);

    *isDone = false;

    status = I2C_GetStatusFlags(base);

    if ((status & (uint32_t)I2C_STAT_MSTARBLOSS_MASK) != 0U)
    {
        I2C_MasterClearStatusFlags(base, I2C_STAT_MSTARBLOSS_MASK);
        GPDMA_AbortTransfer(handle->gpdmaHandle);
        base->MSTCTL = 0;
        return kStatus_I2C_ArbitrationLost;
    }

    if ((status & (uint32_t)I2C_STAT_MSTSTSTPERR_MASK) != 0U)
    {
        I2C_MasterClearStatusFlags(base, I2C_STAT_MSTSTSTPERR_MASK);
        GPDMA_AbortTransfer(handle->gpdmaHandle);
        base->MSTCTL = 0;
        return kStatus_I2C_StartStopError;
    }

#if (defined(FSL_FEATURE_I2C_MASTER_SUPPORT_EVENT_TIMEOUT) && FSL_FEATURE_I2C_MASTER_SUPPORT_EVENT_TIMEOUT)
    /* Event timeout happens when the time since last bus event has been longer than the time specified by TIMEOUT
       register. eg: Start signal fails to generate, no error status is set and transfer hangs if glitch on bus happens
       before, the timeout status can be used to avoid the transfer hangs indefinitely. */
    if ((status & (uint32_t)kI2C_EventTimeoutFlag) != 0U)
    {
        I2C_MasterClearStatusFlags(base, (uint32_t)kI2C_EventTimeoutFlag);
        GPDMA_AbortTransfer(handle->gpdmaHandle);
        base->MSTCTL = 0;
        return kStatus_I2C_EventTimeout;
    }
#endif

#if (defined(FSL_FEATURE_I2C_MASTER_SUPPORT_SCL_TIMEOUT) && FSL_FEATURE_I2C_MASTER_SUPPORT_SCL_TIMEOUT)
    /* SCL timeout happens when the slave is holding the SCL line low and the time has been longer than the time
       specified by TIMEOUT register. */
    if ((status & (uint32_t)kI2C_SclTimeoutFlag) != 0U)
    {
        I2C_MasterClearStatusFlags(base, (uint32_t)kI2C_SclTimeoutFlag);
        GPDMA_AbortTransfer(handle->gpdmaHandle);
        base->MSTCTL = 0;
        return kStatus_I2C_SclLowTimeout;
    }
#endif

    if ((status & (uint32_t)I2C_STAT_MSTPENDING_MASK) == 0U)
    {
        return kStatus_I2C_Busy;
    }

    /* Get the state of the I2C module */
    master_state = (status & (uint32_t)I2C_STAT_MSTSTATE_MASK) >> I2C_STAT_MSTSTATE_SHIFT;

    if ((master_state == (uint32_t)I2C_STAT_MSTCODE_NACKADR) || (master_state == (uint32_t)I2C_STAT_MSTCODE_NACKDAT))
    {
        /* Slave NACKed last byte, issue stop and return error */
        GPDMA_AbortTransfer(handle->gpdmaHandle);
        base->MSTCTL  = I2C_MSTCTL_MSTSTOP_MASK;
        handle->state = (uint8_t)kWaitForCompletionState;
        if ((master_state == (uint32_t)I2C_STAT_MSTCODE_NACKADR) || (handle->checkAddrNack == true))
        {
            return kStatus_I2C_Addr_Nak;
        }
        else
        {
            return kStatus_I2C_Nak;
        }
    }

    err = kStatus_Success;

    if (handle->state == (uint8_t)kStartState)
    {
        /* set start flag for later use */
        start_flag = I2C_MSTCTL_MSTSTART_MASK;

        if (handle->remainingSubaddr != 0U)
        {
            base->MSTDAT  = (uint32_t)transfer->slaveAddress << 1;
            handle->state = (uint8_t)kTransmitSubaddrState;
        }
        else if (transfer->direction == kI2C_Write)
        {
            base->MSTDAT = (uint32_t)transfer->slaveAddress << 1;
            if (transfer->dataSize == 0U)
            {
                /* No data to be transferred, initiate start and schedule stop */
                base->MSTCTL  = I2C_MSTCTL_MSTSTART_MASK;
                handle->state = (uint8_t)kStopState;
                return err;
            }
            handle->state = (uint8_t)kTransmitDataState;
        }
        else if ((transfer->direction == kI2C_Read) && (transfer->dataSize > 0U))
        {
            base->MSTDAT  = ((uint32_t)transfer->slaveAddress << 1) | 1u;
            handle->state = (uint8_t)kReceiveDataState;
        }
        else
        {
            handle->state = (uint8_t)kIdleState;
            err           = kStatus_I2C_UnexpectedState;
            return err;
        }
    }

    switch (handle->state)
    {
        case (uint8_t)kTransmitSubaddrState:
            if ((master_state != (uint32_t)I2C_STAT_MSTCODE_TXREADY) && (0U == start_flag))
            {
                return kStatus_I2C_UnexpectedState;
            }

            base->MSTCTL = start_flag | I2C_MSTCTL_MSTDMA_MASK;
            /* Prepare and submit GPDMA transfer. */
            GPDMA_PrepareTransferConfig(&xferConfig, handle->subaddrBuf, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                        (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                        handle->remainingSubaddr, kGPDMA_TransferM2PControllerDma, 0UL);

            (void)GPDMA_SubmitTransfer(handle->gpdmaHandle, &xferConfig);
            GPDMA_StartTransfer(handle->gpdmaHandle);

            handle->remainingSubaddr = 0;
            if (transfer->dataSize != 0U)
            {
                /* There is data to be transferred, if there is write to read turnaround it is necessary to perform
                 * repeated start */
                handle->state = (transfer->direction == kI2C_Read) ? (uint8_t)kStartState : (uint8_t)kTransmitDataState;
            }
            else
            {
                /* No more data, schedule stop condition */
                handle->state = (uint8_t)kStopState;
            }
            break;

        case (uint8_t)kTransmitDataState:
            if ((master_state != (uint32_t)I2C_STAT_MSTCODE_TXREADY) && (0U == start_flag))
            {
                return kStatus_I2C_UnexpectedState;
            }

            base->MSTCTL                = start_flag | I2C_MSTCTL_MSTDMA_MASK;
            handle->remainingBytesGPDMA = handle->transfer.dataSize;

            I2C_RunGPDMATransfer(base, handle);

            /* Schedule stop condition */
            handle->state         = (uint8_t)kStopState;
            handle->checkAddrNack = false;
            break;

        case (uint8_t)kReceiveDataState:
            if ((master_state != (uint32_t)I2C_STAT_MSTCODE_RXREADY) && (0U == start_flag))
            {
                if (0U == (transfer->flags & (uint32_t)kI2C_TransferNoStartFlag))
                {
                    return kStatus_I2C_UnexpectedState;
                }
            }
            base->MSTCTL                = start_flag | I2C_MSTCTL_MSTDMA_MASK;
            handle->remainingBytesGPDMA = (uint32_t)handle->transfer.dataSize;

            if ((transfer->flags & (uint32_t)kI2C_TransferNoStartFlag) != 0U)
            {
                /* Read the master data register to avoid the data be read again */
                (void)base->MSTDAT;
            }
            I2C_RunGPDMATransfer(base, handle);

            base->MSTCTL = start_flag | I2C_MSTCTL_MSTDMA_MASK;
            break;

        case (uint8_t)kStopState:
            if ((transfer->flags & (uint32_t)kI2C_TransferNoStopFlag) != 0U)
            {
                /* Stop condition is omitted, we are done */
                *isDone       = true;
                handle->state = (uint8_t)kIdleState;
                break;
            }
            /* Send stop condition */
            base->MSTCTL  = I2C_MSTCTL_MSTSTOP_MASK;
            handle->state = (uint8_t)kWaitForCompletionState;
            break;

        case (uint8_t)kWaitForCompletionState:
            *isDone       = true;
            handle->state = (uint8_t)kIdleState;
            break;

        case (uint8_t)kStartState:
        case (uint8_t)kIdleState:
        default:
            /* State machine shall not be invoked again once it enters the idle state */
            err = kStatus_I2C_UnexpectedState;
            break;
    }

    return err;
}

static void I2C_MasterTransferGPDMAHandleIRQ(I2C_Type *base, void *i2cHandle)
{
    assert(i2cHandle != NULL);
    bool isDone;
    status_t result;
    i2c_master_gpdma_handle_t *handle = (i2c_master_gpdma_handle_t *)i2cHandle;

    /* Don't do anything if we don't have a valid handle. */
    if (NULL == handle)
    {
        return;
    }

    result = I2C_RunTransferStateMachineGPDMA(base, handle, &isDone);

    if ((result != kStatus_Success) || isDone)
    {
        /* Restore handle to idle state. */
        handle->state = (uint8_t)kIdleState;

        /* Disable internal IRQ enables. */
        I2C_DisableInterrupts(base, I2C_INTSTAT_MSTPENDING_MASK | I2C_INTSTAT_MSTARBLOSS_MASK |
                                        I2C_INTSTAT_MSTSTSTPERR_MASK | I2C_INTSTAT_EVENTTIMEOUT_MASK);

        /* Invoke callback. */
        if (handle->completionCallback != NULL)
        {
            handle->completionCallback(base, handle, result, handle->userData);
        }
    }
}

static void I2C_MasterTransferCallbackGPDMA(gpdma_handle_t *handle, void *userData, uint32_t status)
{
    i2c_master_gpdma_private_handle_t *gpdmaPrivateHandle;

    /* Don't do anything if we don't have a valid handle. */
    if (NULL == handle)
    {
        return;
    }

    gpdmaPrivateHandle = (i2c_master_gpdma_private_handle_t *)userData;

    I2C_Type *base                             = gpdmaPrivateHandle->base;
    i2c_master_gpdma_handle_t *i2cMasterhandle = gpdmaPrivateHandle->handle;

    if (status == (uint32_t)kGPDMA_StatusInterruptError)
    {
        I2C_MasterTransferAbortGPDMA(base, i2cMasterhandle);
        /* Invoke callback. */
        if (i2cMasterhandle->completionCallback != NULL)
        {
            i2cMasterhandle->completionCallback(base, i2cMasterhandle, kStatus_I2C_DmaRequestFail,
                                                i2cMasterhandle->userData);
        }
    }
    else
    {
        I2C_RunGPDMATransfer(base, i2cMasterhandle);
    }
}

/*!
 * brief Init the I2C handle which is used in transactional functions
 *
 * param base I2C peripheral base address
 * param handle pointer to i2c_master_gpdma_handle_t structure
 * param callback pointer to user callback function
 * param userData user param passed to the callback function
 * param gpdmaHandle GPDMA handle pointer
 */
void I2C_MasterTransferCreateHandleGPDMA(I2C_Type *base,
                                         i2c_master_gpdma_handle_t *handle,
                                         i2c_master_gpdma_transfer_callback_t callback,
                                         void *userData,
                                         gpdma_handle_t *gpdmaHandle)
{
    assert(handle != NULL);
    assert(gpdmaHandle != NULL);

    uint32_t instance;

    /* Zero handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Look up instance number */
    instance = I2C_GetInstance(base);

    /* Set the user callback and userData. */
    handle->completionCallback = callback;
    handle->userData           = userData;

    /* Save the context in global variables to support the double weak mechanism. */
    s_i2cHandle[instance] = handle;

    /* Save master interrupt handler. */
    s_i2cMasterIsr = I2C_MasterTransferGPDMAHandleIRQ;

    /* Clear internal IRQ enables and enable NVIC IRQ. */
    I2C_DisableInterrupts(base, I2C_INTSTAT_MSTPENDING_MASK | I2C_INTSTAT_MSTARBLOSS_MASK |
                                    I2C_INTSTAT_MSTSTSTPERR_MASK | I2C_INTSTAT_EVENTTIMEOUT_MASK);
    (void)EnableIRQ(s_i2cIRQ[instance]);

    /* Set the handle for GPDMA. */
    handle->gpdmaHandle = gpdmaHandle;

    s_masterGpdmaPrivateHandle[instance].base   = base;
    s_masterGpdmaPrivateHandle[instance].handle = handle;

    GPDMA_SetCallback(gpdmaHandle, I2C_MasterTransferCallbackGPDMA, &s_masterGpdmaPrivateHandle[instance]);
}

/*!
 * brief Performs a master gpdma non-blocking transfer on the I2C bus
 *
 * param base I2C peripheral base address
 * param handle pointer to i2c_master_gpdma_handle_t structure
 * param xfer pointer to transfer structure of i2c_master_transfer_t
 * retval kStatus_Success Sucessully complete the data transmission.
 * retval kStatus_I2C_Busy Previous transmission still not finished.
 * retval kStatus_I2C_Timeout Transfer error, wait signal timeout.
 * retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * retval kStataus_I2C_Nak Transfer error, receive Nak during transfer.
 */
status_t I2C_MasterTransferGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle, i2c_master_transfer_t *xfer)
{
    status_t result;

    assert(handle != NULL);
    assert(xfer != NULL);
    assert(xfer->subaddressSize <= sizeof(xfer->subaddress));

    /* Return busy if another transaction is in progress. */
    if (handle->state != (uint8_t)kIdleState)
    {
        return kStatus_I2C_Busy;
    }

    /* Prepare transfer state machine. */
    result = I2C_InitTransferStateMachineGPDMA(base, handle, xfer);

    /* Clear error flags. */
    I2C_MasterClearStatusFlags(base, I2C_STAT_MSTARBLOSS_MASK | I2C_STAT_MSTSTSTPERR_MASK);

    /* Enable I2C internal IRQ sources */
    /* Enable arbitration lost interrupt, start/stop error interrupt and master pending interrupt.
       The master pending flag is not set during gpdma transfer. */
    I2C_EnableInterrupts(base, I2C_INTSTAT_MSTPENDING_MASK | I2C_INTSTAT_MSTARBLOSS_MASK |
                                   I2C_INTSTAT_MSTSTSTPERR_MASK | I2C_INTSTAT_EVENTTIMEOUT_MASK);

    return result;
}

/*!
 * brief Get master transfer status during a gpdma non-blocking transfer
 *
 * param base I2C peripheral base address
 * param handle pointer to i2c_master_gpdma_handle_t structure
 * param count Number of bytes transferred so far by the non-blocking transaction.
 */
status_t I2C_MasterTransferGetCountGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle, size_t *count)
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
    if (handle->state == (uint8_t)kReceiveDataState)
    {
        *count = handle->gpdmaHandle->base->DMACC[handle->gpdmaHandle->channel].DESTADDR -
                 (uint32_t)(uintptr_t)(uint8_t *)handle->transfer.data + 1U;
    }
    else if (handle->state == (uint8_t)kTransmitDataState)
    {
        *count = handle->gpdmaHandle->base->DMACC[handle->gpdmaHandle->channel].SRCADDR -
                 (uint32_t)(uintptr_t)(uint8_t *)handle->transfer.data + 1U;
    }
    else
    {
        *count = 0U;
    }

    return kStatus_Success;
}

/*!
 * brief Abort a master gpdma non-blocking transfer in a early time
 *
 * param base I2C peripheral base address
 * param handle pointer to i2c_master_gpdma_handle_t structure
 */
void I2C_MasterTransferAbortGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle)
{
    uint32_t status;
    uint32_t master_state;

    if (handle->state != (uint8_t)kIdleState)
    {
        GPDMA_AbortTransfer(handle->gpdmaHandle);

        /* Disable GPDMA */
        base->MSTCTL = 0;

        /* Disable internal IRQ enables. */
        I2C_DisableInterrupts(base, I2C_INTSTAT_MSTPENDING_MASK | I2C_INTSTAT_MSTARBLOSS_MASK |
                                        I2C_INTSTAT_MSTSTSTPERR_MASK | I2C_INTSTAT_EVENTTIMEOUT_MASK);

        /* Wait until module is ready */
        do
        {
            status = I2C_GetStatusFlags(base);
        } while ((status & (uint8_t)I2C_STAT_MSTPENDING_MASK) == 0U);

        /* Clear controller state. */
        I2C_MasterClearStatusFlags(base, I2C_STAT_MSTARBLOSS_MASK | I2C_STAT_MSTSTSTPERR_MASK);

        /* Get the state of the I2C module */
        master_state = (status & I2C_STAT_MSTSTATE_MASK) >> I2C_STAT_MSTSTATE_SHIFT;

        if (master_state != (uint32_t)I2C_STAT_MSTCODE_IDLE)
        {
            /* Send a stop command to finalize the transfer. */
            base->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;

            /* Wait until module is ready */
            do
            {
                status = I2C_GetStatusFlags(base);
            } while ((status & (uint32_t)I2C_STAT_MSTPENDING_MASK) == 0U);

            /* Clear controller state. */
            I2C_MasterClearStatusFlags(base, I2C_STAT_MSTARBLOSS_MASK | I2C_STAT_MSTSTSTPERR_MASK);
        }

        /* Reset the state to idle. */
        handle->state = (uint8_t)kIdleState;
    }
}

static void I2C_SlaveInvokeEventGPDMA(I2C_Type *base,
                                      i2c_slave_gpdma_handle_t *handle,
                                      i2c_slave_transfer_event_t event)
{
    handle->transfer.event = event;
    uint32_t eventMask     = handle->transfer.eventMask;
    if ((handle->callback != NULL) && ((eventMask & (uint32_t)event) != 0U))
    {
        handle->callback(base, &handle->transfer, handle->userData);

        size_t txSize = handle->transfer.txSize;
        size_t rxSize = handle->transfer.rxSize;
        /* if after event callback we have data buffer (callback func has added new data), keep transfer busy */
        if (false == handle->isBusy)
        {
            if (((handle->transfer.txData != NULL) && (txSize != 0U)) ||
                ((handle->transfer.rxData != NULL) && (rxSize != 0U)))
            {
                handle->isBusy = true;
            }
        }
    }
}

static bool I2C_SlaveAddressIRQ(I2C_Type *base, i2c_slave_gpdma_handle_t *handle)
{
    uint8_t addressByte0;
    addressByte0 = (uint8_t)base->SLVDAT;
    size_t txSize;
    size_t rxSize;

    /* store the matched address */
    handle->transfer.receivedAddress = addressByte0;

    /* In case the master issues restart and the previius data transfer is not complete.
       eg: Slave configured to transfer n bytes however the master transferred less than
       n bytes before issues restart. */
    GPDMA_AbortTransfer(handle->gpdmaHandle);

    /* Ack the address before enabling the slave dma, otherwise in master read operation the slave begin transmit at the
     * second data. */
    base->SLVCTL |= (I2C_SLVCTL_SLVCONTINUE_MASK);

    /* R/nW */
    if ((addressByte0 & 1U) != 0U)
    {
        txSize = handle->transfer.txSize;
        /* if we have no data in this transfer, call callback to get new */
        if ((handle->transfer.txData == NULL) || (txSize == 0U))
        {
            I2C_SlaveInvokeEventGPDMA(base, handle, kI2C_SlaveTransmitEvent);
        }

        txSize = handle->transfer.txSize;
        /* NACK if we have no data in this transfer. */
        if ((handle->transfer.txData != NULL) && (txSize != 0U))
        {
            handle->dmaXferConfig.srcAddr      = (uint32_t)(uintptr_t)handle->transfer.txData;
            handle->dmaXferConfig.destAddr     = (uint32_t)&base->SLVDAT;
            handle->dmaXferConfig.totalBytes   = txSize;
            handle->dmaXferConfig.transferType = kGPDMA_TransferM2PControllerDma;
            (void)GPDMA_SubmitTransfer(handle->gpdmaHandle, &(handle->dmaXferConfig));
            GPDMA_StartTransfer(handle->gpdmaHandle);
            base->SLVCTL |= I2C_SLVCTL_SLVDMA_MASK;
        }
        else
        {
            base->SLVCTL |= I2C_SLVCTL_SLVNACK_MASK;
            return false;
        }

        /* master wants to read, so slave transmit is next state */
        handle->slaveFsm = kI2C_SlaveFsmTransmit;
    }
    else
    {
        rxSize = handle->transfer.rxSize;
        /* if we have no receive buffer in this transfer, call callback to get new */
        if ((handle->transfer.rxData == NULL) || (rxSize == 0U))
        {
            I2C_SlaveInvokeEventGPDMA(base, handle, kI2C_SlaveReceiveEvent);
        }

        rxSize = handle->transfer.rxSize;
        /* NACK if we have no data in this transfer */
        if ((handle->transfer.rxData != NULL) && (rxSize != 0U))
        {
            handle->dmaXferConfig.destAddr     = (uint32_t)(uintptr_t)handle->transfer.rxData;
            handle->dmaXferConfig.srcAddr      = (uint32_t)&base->SLVDAT;
            handle->dmaXferConfig.totalBytes   = rxSize;
            handle->dmaXferConfig.transferType = kGPDMA_TransferP2MControllerDma;
            (void)GPDMA_SubmitTransfer(handle->gpdmaHandle, &(handle->dmaXferConfig));
            GPDMA_StartTransfer(handle->gpdmaHandle);
            base->SLVCTL |= I2C_SLVCTL_SLVDMA_MASK;
        }
        else
        {
            base->SLVCTL |= I2C_SLVCTL_SLVNACK_MASK;
            return false;
        }

        /* master wants write, so slave receive is next state */
        handle->slaveFsm = kI2C_SlaveFsmReceive;
    }

    return true;
}

static void I2C_SlaveTransferCallbackGPDMA(gpdma_handle_t *handle, void *userData, uint32_t status)
{
    /* Don't do anything if we don't have a valid handle. */
    if (NULL == handle)
    {
        return;
    }

    i2c_slave_gpdma_private_handle_t *gpdmaPrivateHandle = (i2c_slave_gpdma_private_handle_t *)userData;
    i2c_slave_gpdma_handle_t *i2cSlavehandle             = gpdmaPrivateHandle->handle;

    i2cSlavehandle->isBusy = false;

    if (status == (uint32_t)kGPDMA_StatusInterruptError)
    {
        I2C_SlaveTransferAbortGPDMA(gpdmaPrivateHandle->base, i2cSlavehandle);
        I2C_SlaveInvokeEventGPDMA(gpdmaPrivateHandle->base, i2cSlavehandle, kI2C_SlaveGpdmaErrorEvent);
    }
    else
    {
        if (i2cSlavehandle->slaveFsm == kI2C_SlaveFsmReceive)
        {
            /* Slave receive complete, nack the last byte. */
            gpdmaPrivateHandle->base->SLVCTL |= I2C_SLVCTL_SLVNACK_MASK;
            /* Disable and re-enable the slave function otherwise it will stall the bus. */
            gpdmaPrivateHandle->base->CFG &= ~I2C_CFG_SLVEN_MASK;
            gpdmaPrivateHandle->base->CFG |= I2C_CFG_SLVEN_MASK;
            /* Clear the nack bit, otherwise the next transfer will be nacked automatically. */
            gpdmaPrivateHandle->base->SLVCTL &= ~I2C_SLVCTL_SLVNACK_MASK;
        }
        I2C_SlaveInvokeEventGPDMA(gpdmaPrivateHandle->base, i2cSlavehandle, kI2C_SlaveCompletionEvent);
    }
}

/*!
 * brief Creates a new handle for the I2C slave GPDMA APIs.
 *
 * The creation of a handle is for use with the GPDMA APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the I2C_SlaveTransferAbort() API shall be called.
 *
 * param base The I2C peripheral base address.
 * param[out] handle Pointer to the I2C slave driver handle.
 * param callback User provided pointer to the asynchronous callback function.
 * param userData User provided pointer to the application callback data.
 * param gpdmaHandle GPDMA handle pointer
 */
void I2C_SlaveTransferCreateHandleGPDMA(I2C_Type *base,
                                        i2c_slave_gpdma_handle_t *handle,
                                        i2c_slave_transfer_callback_t callback,
                                        void *userData,
                                        gpdma_handle_t *gpdmaHandle)
{
    uint32_t instance;

    assert(handle != NULL);

    /* Clear out the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Look up instance number */
    instance = I2C_GetInstance(base);

    /* Save base and instance. */
    handle->callback = callback;
    handle->userData = userData;

    /* initialize fsm */
    handle->slaveFsm = kI2C_SlaveFsmAddressMatch;

    /* store pointer to handle into transfer struct */
    handle->transfer.handle = handle;

    /* Set the DMA transfer configuration. */
    handle->dmaXferConfig.srcBurstSize      = kGPDMA_BurstSize1;
    handle->dmaXferConfig.destBurstSize     = kGPDMA_BurstSize1;
    handle->dmaXferConfig.srcTransferWidth  = kGPDMA_TransferWidth1Bytes;
    handle->dmaXferConfig.destTransferWidth = kGPDMA_TransferWidth1Bytes;
    handle->dmaXferConfig.linkListItem      = 0UL;

    /* Save the context in global variables to support the double weak mechanism. */
    s_i2cHandle[instance] = handle;

    /* Save slave interrupt handler. */
    s_i2cSlaveIsr = I2C_SlaveTransferGPDMAHandleIRQ;

    /* Set the handle for GPDMA. */
    handle->gpdmaHandle = gpdmaHandle;

    /* Set the internal handle and GPDMA callback. */
    s_slaveGpdmaPrivateHandle[instance].base   = base;
    s_slaveGpdmaPrivateHandle[instance].handle = handle;

    GPDMA_SetCallback(gpdmaHandle, I2C_SlaveTransferCallbackGPDMA, &s_slaveGpdmaPrivateHandle[instance]);

    /* Clear internal IRQ enables and enable NVIC IRQ. */
    I2C_DisableInterrupts(base, (uint32_t)I2C_INTSTAT_SLVPENDING_MASK | (uint32_t)I2C_INTSTAT_SLVDESEL_MASK);
    (void)EnableIRQ(s_i2cIRQ[instance]);
}

/*!
 * brief Starts accepting slave transfers.
 *
 * Call this API after calling I2C_SlaveInit() and I2C_SlaveTransferCreateHandleGPDMA() to start processing
 * transactions driven by an I2C master. The slave monitors the I2C bus and pass events to the
 * callback that was passed into the call to I2C_SlaveTransferCreateHandleGPDMA(). The callback is always invoked
 * from the interrupt context.
 *
 * If no slave Tx transfer is busy, a master read from slave request invokes #kI2C_SlaveTransmitEvent callback.
 * If no slave Rx transfer is busy, a master write to slave request invokes #kI2C_SlaveReceiveEvent callback.
 *
 * The set of events received by the callback is customizable. To do so, set the a eventMask parameter to
 * the OR'd combination of #i2c_slave_transfer_event_t enumerators for the events you wish to receive.
 * The #kI2C_SlaveTransmitEvent and #kI2C_SlaveReceiveEvent events are always enabled and do not need
 * to be included in the mask. Alternatively, you can pass 0 to get a default set of only the transmit and
 * receive events that are always enabled. In addition, the #kI2C_SlaveAllEvents constant is provided as
 * a convenient way to enable all events.
 *
 * param base The I2C peripheral base address.
 * param handle Pointer to i2c_slave_gpdma_handle_t structure which stores the transfer state.
 * param eventMask Bit mask formed by OR'ing together #i2c_slave_transfer_event_t enumerators to specify
 *      which events to send to the callback. Other accepted values are 0 to get a default set of
 *      only the transmit and receive events, and #kI2C_SlaveAllEvents to enable all events.
 *
 * retval kStatus_Success Slave transfers were successfully started.
 * retval #kStatus_I2C_Busy Slave transfers have already been started on this handle.
 */
status_t I2C_SlaveTransferGPDMA(I2C_Type *base, i2c_slave_gpdma_handle_t *handle, uint32_t eventMask)
{
    status_t status;

    assert(handle != NULL);

    status = kStatus_Success;

    /* Disable I2C IRQ sources while we configure stuff. */
    I2C_DisableInterrupts(base, (uint32_t)I2C_INTSTAT_SLVPENDING_MASK | (uint32_t)I2C_INTSTAT_SLVDESEL_MASK);

    /* Return busy if another transaction is in progress. */
    if (handle->isBusy)
    {
        status = kStatus_I2C_Busy;
    }

    /* Save transfer into handle. */
    handle->transfer.txData    = NULL;
    handle->transfer.txSize    = 0U;
    handle->transfer.rxData    = NULL;
    handle->transfer.rxSize    = 0U;
    handle->transfer.eventMask = eventMask | (uint32_t)kI2C_SlaveTransmitEvent | (uint32_t)kI2C_SlaveReceiveEvent;
    handle->isBusy             = true;

    /* Set the SLVEN bit to 1 in the CFG register. */
    I2C_SlaveEnable(base, true);

    /* Clear w1c flags. */
    base->STAT |= 0U;

    /* Have to enable high speed capable otherwise the DMA cannot work. TODO */
    base->CFG |= I2C_CFG_HSCAPABLE_MASK;

    I2C_EnableInterrupts(base, (uint32_t)I2C_INTSTAT_SLVPENDING_MASK | (uint32_t)I2C_INTSTAT_SLVDESEL_MASK);

    return status;
}

/*!
 * brief Gets the count of how many bytes have been transfered.
 *
 * param base I2C base pointer.
 * param handle pointer to i2c_slave_gpdma_handle_t structure.
 * param count Number of bytes transferred so far by the GPDMA transaction.
 * retval kStatus_InvalidArgument count is Invalid.
 * retval kStatus_Success Successfully return the count.
 */
status_t I2C_SlaveTransferGetCountGPDMA(I2C_Type *base, i2c_slave_gpdma_handle_t *handle, size_t *count)
{
    assert(handle != NULL);

    if (count == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (!handle->isBusy)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    if (handle->slaveFsm == kI2C_SlaveFsmReceive)
    {
        *count = handle->gpdmaHandle->base->DMACC[handle->gpdmaHandle->channel].DESTADDR -
                 (uint32_t)(uintptr_t)handle->transfer.rxData + 1U;
    }
    else
    {
        *count = handle->gpdmaHandle->base->DMACC[handle->gpdmaHandle->channel].SRCADDR -
                 (uint32_t)(uintptr_t)handle->transfer.txData + 1U;
    }

    return kStatus_Success;
}

/*!
 * brief Aborts the slave GPDMA transfers.
 * note This API could be called at any time to stop slave for handling the bus events.
 * param base The I2C peripheral base address.
 * param handle Pointer to i2c_slave_gpdma_handle_t structure which stores the transfer state.
 * retval kStatus_Success
 * retval #kStatus_I2C_Idle
 */
void I2C_SlaveTransferAbortGPDMA(I2C_Type *base, i2c_slave_gpdma_handle_t *handle)
{
    /* Abort GPDMA transfer. */
    GPDMA_AbortTransfer(handle->gpdmaHandle);

    /* Disable I2C IRQ sources while we configure stuff. */
    I2C_DisableInterrupts(base, (uint32_t)I2C_INTSTAT_SLVPENDING_MASK | (uint32_t)I2C_INTSTAT_SLVDESEL_MASK);

    if (handle->slaveFsm == kI2C_SlaveFsmReceive)
    {
        /* Nack the master if receiving. */
        base->SLVCTL |= I2C_SLVCTL_SLVNACK_MASK;
        /* Clear the nack bit, otherwise the next transfer will be nacked automatically. */
        base->SLVCTL &= ~I2C_SLVCTL_SLVNACK_MASK;
    }

    /* Set the SLVEN bit to 0 in the CFG register. */
    I2C_SlaveEnable(base, false);

    handle->isBusy          = false;
    handle->transfer.txSize = 0;
    handle->transfer.rxSize = 0;
}

/*!
 * brief Reusable routine to handle slave interrupts.
 * note This function does not need to be called unless you are reimplementing the
 *  GPDMA API's interrupt handler routines to add special functionality.
 * param base The I2C peripheral base address.
 * param handle Pointer to i2c_slave_gpdma_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferGPDMAHandleIRQ(I2C_Type *base, void *i2cHandle)
{
    assert(i2cHandle != NULL);

    i2c_slave_gpdma_handle_t *handle = (i2c_slave_gpdma_handle_t *)i2cHandle;
    uint32_t i2cStatus               = base->STAT;

    if ((i2cStatus & I2C_STAT_SLVDESEL_MASK) != 0U)
    {
        GPDMA_AbortTransfer(handle->gpdmaHandle);
        I2C_SlaveInvokeEventGPDMA(base, handle, kI2C_SlaveDeselectedEvent);
        I2C_SlaveClearStatusFlags(base, I2C_STAT_SLVDESEL_MASK);
    }

    /* SLVPENDING flag is cleared by writing I2C_SLVCTL_SLVCONTINUE_MASK to SLVCTL register */
    if ((i2cStatus & I2C_STAT_SLVPENDING_MASK) != 0U)
    {
        bool slaveAddress =
            (((i2cStatus & I2C_STAT_SLVSTATE_MASK) >> I2C_STAT_SLVSTATE_SHIFT) == (uint32_t)I2C_STAT_SLVST_ADDR);

        if (slaveAddress)
        {
            I2C_SlaveInvokeEventGPDMA(base, handle, kI2C_SlaveAddressMatchEvent);
            (void)I2C_SlaveAddressIRQ(base, handle);
        }
    }
}
