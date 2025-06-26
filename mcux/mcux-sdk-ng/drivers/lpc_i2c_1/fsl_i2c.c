/*
 * Copyright 2018-2019 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpc_i2c_1"
#endif

#define I2C_STANDARD_MODE 100000U

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
#define SUPRESS_FALL_THROUGHT_WARNING() __attribute__((fallthrough));
#else
#define SUPRESS_FALL_THROUGHT_WARNING()
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static status_t I2C_MasterRunTransferStateMachine(I2C0_Type *base, i2c_master_transfer_t *transfer, bool *isDone);
static void I2C_SlaveInvokeEvent(I2C0_Type *base, i2c_slave_handle_t *handle, i2c_slave_transfer_event_t event);
/*! @brief Typedef for interrupt handler. */
typedef void (*i2c_isr_t)(I2C0_Type *base, void *i2cHandle);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map i2c instance number to base address. */
static I2C0_Type *const s_i2cBases[] = I2C0_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to i2c clocks for each instance. */
static const clock_ip_name_t s_i2cClocks[] = I2C_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_I2C_HAS_NO_RESET) && FSL_FEATURE_I2C_HAS_NO_RESET)
static const reset_ip_name_t s_i2cResets[] = I2C_RSTS_N;
#endif

/*! @brief Pointers to i2c handles for each instance. */
void *s_i2cHandle[1] = {NULL};

/*! @brief IRQ name array */
const IRQn_Type s_i2cIRQ[] = {I2C0_IRQn};

/*! @brief Pointer to master IRQ handler for each instance. */
static i2c_isr_t s_i2cMasterIsr;

/*! @brief Pointer to slave IRQ handler for each instance. */
static i2c_isr_t s_i2cSlaveIsr;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * @param base The I2C peripheral base address.
 * @return I2C instance number starting from 0.
 */
/*!
 * brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * param base The I2C peripheral base address.
 * return I2C instance number starting from 0.
 */
uint32_t I2C_GetInstance(I2C0_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_i2cBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_i2cBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_i2cBases));

    return instance;
}

/*!
 * brief Provides a default configuration for the I2C master peripheral.
 *
 * This function provides the following default configuration for the I2C master peripheral:
 * code
 *  masterConfig->enableMaster            = true;
 *  masterConfig->baudRate_Bps            = 100000U;
 * endcode
 *
 * After calling this function, you can override any settings in order to customize the configuration,
 * prior to initializing the master driver with I2C_MasterInit().
 *
 * param[out] masterConfig User provided configuration structure for default values. Refer to #i2c_master_config_t.
 */
void I2C_MasterGetDefaultConfig(i2c_master_config_t *masterConfig)
{
    /* Initializes the configure structure to zero. */
    memset(masterConfig, 0, sizeof(*masterConfig));

    masterConfig->enableMaster = true;
    masterConfig->baudRate_Bps = 100000U;
}

/*!
 * brief Initializes the I2C master peripheral.
 *
 * This function enables the peripheral clock and initializes the I2C master peripheral as described by the user
 * provided configuration. A software reset is performed prior to configuration.
 *
 * param base The I2C peripheral base address.
 * param masterConfig User provided peripheral configuration. Use I2C_MasterGetDefaultConfig() to get a set of
 * defaults
 *      that you can override.
 * param srcClock_Hz Frequency in Hertz of the I2C functional clock. Used to calculate the baud rate divisors,
 *      filter widths, and timeout periods.
 */
void I2C_MasterInit(I2C0_Type *base, const i2c_master_config_t *masterConfig, uint32_t srcClock_Hz)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_i2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_I2C_HAS_NO_RESET) && FSL_FEATURE_I2C_HAS_NO_RESET)
    RESET_PeripheralReset(s_i2cResets[I2C_GetInstance(base)]);
#endif

    /* Reset STA, STO, SI */
    base->CONCLR = I2C0_CONCLR_SIC_MASK | I2C0_CONCLR_STAC_MASK | I2C0_CONCLR_AAC_MASK | I2C0_CONCLR_I2ENC_MASK;

    I2C_MasterSetBaudRate(base, masterConfig->baudRate_Bps, srcClock_Hz);

    I2C_MasterEnable(base, masterConfig->enableMaster);
}

/*!
 * brief Deinitializes the I2C master peripheral.
 *
 * This function disables the I2C master peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * param base The I2C peripheral base address.
 */
void I2C_MasterDeinit(I2C0_Type *base)
{
    I2C_MasterEnable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_i2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets the I2C bus frequency for master transactions.
 *
 * The I2C master is automatically disabled and re-enabled as necessary to configure the baud
 * rate. Do not call this function during a transfer, or the transfer is aborted.
 *
 * param base The I2C peripheral base address.
 * param srcClock_Hz I2C functional clock frequency in Hertz.
 * param baudRate_Bps Requested bus frequency in bits per second.
 */
void I2C_MasterSetBaudRate(I2C0_Type *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz)
{
    uint32_t sclLow;
    uint32_t sclHigh;
    uint32_t divider;

    divider = srcClock_Hz / baudRate_Bps;

    if (divider * baudRate_Bps < srcClock_Hz)
    {
        divider = divider + 1;
    }

    if (baudRate_Bps > I2C_STANDARD_MODE)
    {
        /* For fast mode, sclLow = 2*sclHigh*/
        sclHigh = divider / 3;
        sclLow  = 2 * sclHigh;
        if (3 * sclHigh < divider)
        {
            sclLow = sclLow + 1;
        }
    }
    else
    {
        /* For standard mode, sclLow = sclHigh*/
        sclHigh = divider / 2;
        sclLow  = sclHigh;
        if (2 * sclHigh < divider)
        {
            sclLow = sclLow + 1;
        }
    }
    base->SCLH = sclHigh;
    base->SCLL = sclLow;
}

static status_t I2C_PendingStatusWait(I2C0_Type *base)
{
#if I2C_RETRY_TIMES
    uint32_t waitTimes = I2C_RETRY_TIMES;
    /* Wait for SI flag assert. */
    while ((!(base->CONSET & kI2C_InterruptFlag)) && (0U != --waitTimes))
    {
    }
    if (0U == waitTimes)
    {
        return kStatus_I2C_Timeout;
    }
#else
    /* Wait for SI flag assert. */
    while (!(base->CONSET & kI2C_InterruptFlag))
    {
    }
#endif

    return kStatus_Success;
}

static uint32_t I2C_GetState(I2C0_Type *base)
{
    return base->STAT;
}

/*!
 * brief Sends a START on the I2C bus.
 *
 * This function is used to initiate a new master mode transfer by sending the START signal.
 * The slave address is sent following the I2C START signal.
 *
 * param base I2C peripheral base pointer
 * param address 7-bit slave device address.
 * param direction Master transfer directions(transmit/receive).
 * retval kStatus_Success Successfully send the start signal.
 * retval kStatus_I2C_Timeout Send start signal failed, timeout.
 */
status_t I2C_MasterStart(I2C0_Type *base, uint8_t address, i2c_direction_t direction)
{
    status_t result;

    /* Generate Start signal on the bus. */
    base->CONSET = kI2C_StartFlag;

    /* Wait for SI flag and start ready state. */
    result = I2C_PendingStatusWait(base);
    if (result != kStatus_Success)
    {
        return result;
    }

    if (I2C_GetState(base) != kI2C_Master_StartReady)
    {
        return kStatus_I2C_StateError;
    }

    /* Write Address and RW bit to data register */
    base->DAT = ((uint32_t)address << 1) | ((uint32_t)direction & 1u);

    /* Clear STA flag and SI flag */
    I2C_MasterClearStatusFlags(base, kI2C_StartFlag | kI2C_InterruptFlag);

    return kStatus_Success;
}

/*!
 * brief Sends a REPEATED START on the I2C bus.
 *
 * param base I2C peripheral base pointer
 * param address 7-bit slave device address.
 * param direction Master transfer directions(transmit/receive).
 * retval kStatus_Success Successfully send the start signal.
 * retval kStatus_I2C_Timeout Send repeated-start signal failed, timeout.
 */
status_t I2C_MasterRepeatedStart(I2C0_Type *base, uint8_t address, i2c_direction_t direction)
{
    status_t result;

    /* Clear SI flag if not cleared. */
    base->CONCLR = kI2C_InterruptFlag;
    /* Generate Start signal on the bus. */
    base->CONSET = kI2C_StartFlag;

    /* Wait for SI flag and repeated-start ready state. */
    result = I2C_PendingStatusWait(base);
    if (result != kStatus_Success)
    {
        return result;
    }

    if (I2C_GetState(base) != kI2C_Master_RestartReady)
    {
        return kStatus_I2C_StateError;
    }

    /* Write Address and RW bit to data register */
    base->DAT = ((uint32_t)address << 1) | ((uint32_t)direction & 1u);

    /* Clear STA flag and SI flag */
    I2C_MasterClearStatusFlags(base, kI2C_StartFlag | kI2C_InterruptFlag);

    return kStatus_Success;
}

/*!
 * brief Sends a STOP signal on the I2C bus.
 *
 * retval kStatus_Success Successfully send the stop signal.
 * retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterStop(I2C0_Type *base)
{
    /* Generate Stop signal in the bus. */
    base->CONSET = kI2C_StopFlag;
    base->CONCLR = kI2C_InterruptFlag;

/* Wait until STOP condition reset. */
#if I2C_RETRY_TIMES
    uint32_t waitTimes = I2C_RETRY_TIMES;
    /* Wait for stop flag de-assert. */
    while ((base->CONSET & kI2C_StopFlag) && (0U != --waitTimes))
    {
    }
    if (0U == waitTimes)
    {
        return kStatus_I2C_Timeout;
    }
#else
    /* Wait for stop flag de-assert. */
    while (base->CONSET & kI2C_StopFlag)
    {
    }
#endif

    return kStatus_Success;
}

/*!
 * brief Performs a polling send transfer on the I2C bus.
 *
 * Sends up to a txSize number of bytes to the previously addressed slave device. The slave may
 * reply with a NAK to any byte in order to terminate the transfer early. If this happens, this
 * function returns #kStatus_I2C_Nak.
 *
 * param base  The I2C peripheral base address.
 * param txBuff The pointer to the data to be transferred.
 * param txSize The length in bytes of the data to be transferred.
 * param flags Transfer control flag to control special behavior like suppressing start or stop, for normal transfers
 * use kI2C_TransferDefaultFlag
 * retval kStatus_Success Data was sent successfully.
 * retval #kStatus_I2C_Busy Another master is currently utilizing the bus.
 * retval #kStatus_I2C_Nak The slave device sent a NAK in response to a byte.
 * retval #kStatus_I2C_ArbitrationLost Arbitration lost error.
 */
status_t I2C_MasterWriteBlocking(I2C0_Type *base, const void *txBuff, size_t txSize, uint32_t flags)
{
    uint32_t master_state;
    status_t result;

    const uint8_t *buf = (const uint8_t *)(uintptr_t)txBuff;

    assert(txBuff != NULL);

    result = kStatus_Success;
    while (txSize)
    {
        result = I2C_PendingStatusWait(base);

        if (result != kStatus_Success)
        {
            return result;
        }

        master_state = base->STAT;

        switch (master_state)
        {
            case kI2C_Master_TxAckAddress:
            case kI2C_Master_TxAckData:
                base->DAT = *buf++;
                txSize--;
                break;

            case kI2C_Master_TxNackAddress:
                result = kStatus_I2C_Addr_Nak;
                break;

            case kI2C_Master_TxNackData:
                result = kStatus_I2C_Nak;
                break;

            case kI2C_Master_ArbitrationLost:
                result = kStatus_I2C_ArbitrationLost;
                break;

            /* Bus Error */
            case I2C_COMMONCODE_ERROR:
                result       = kStatus_I2C_BusError;
                base->CONSET = kI2C_StopFlag;
                break;

            default:
                assert(false);
                break;
        }

        if ((result == kStatus_I2C_Addr_Nak) || (result == kStatus_I2C_Nak))
        {
            I2C_MasterStop(base);
        }
        else
        {
            /* Continue state machine by clearing the interrupt flag. */
            base->CONCLR = kI2C_InterruptFlag;
        }

        if (result != kStatus_Success)
        {
            return result;
        }
    }

    result = I2C_PendingStatusWait(base);

    if (result != kStatus_Success)
    {
        return result;
    }

    if (!(flags & kI2C_TransferNoStopFlag))
    {
        result = I2C_MasterStop(base);
    }

    return result;
}

/*!
 * brief Performs a polling receive transfer on the I2C bus.
 *
 * param base  The I2C peripheral base address.
 * param rxBuff The pointer to the data to be transferred.
 * param rxSize The length in bytes of the data to be transferred.
 * param flags Transfer control flag to control special behavior like suppressing start or stop, for normal transfers
 * use kI2C_TransferDefaultFlag
 * retval kStatus_Success Data was received successfully.
 * retval #kStatus_I2C_Busy Another master is currently utilizing the bus.
 * retval #kStatus_I2C_Nak The slave device sent a NAK in response to a byte.
 * retval #kStatus_I2C_ArbitrationLost Arbitration lost error.
 */
status_t I2C_MasterReadBlocking(I2C0_Type *base, void *rxBuff, size_t rxSize, uint32_t flags)
{
    uint32_t master_state;
    status_t result;

    uint8_t *buf = (uint8_t *)(rxBuff);

    assert(rxBuff != NULL);

    while (rxSize)
    {
        result = I2C_PendingStatusWait(base);
        if (result != kStatus_Success)
        {
            return result;
        }

        master_state = base->STAT;

        switch (master_state)
        {
            case kI2C_Master_RxAckaddress:
                /* More than one byte to receive, send ACK for the remaining byte. */
                if (rxSize > 1)
                {
                    base->CONSET = kI2C_AssertACKFlag;
                }
                break;

            case kI2C_Master_RxAckData:
                *(buf++) = base->DAT;
                rxSize--;
                /* Only left one byte to receive, send NACK for the remaining byte. */
                if (rxSize == 1)
                {
                    base->CONCLR = kI2C_AssertACKFlag;
                }
                break;

            case kI2C_Master_RxNackaddress:
                result = kStatus_I2C_Addr_Nak;
                break;

            case kI2C_Master_RxNackData:
                *(buf++) = base->DAT;
                rxSize--;
                if (!(flags & kI2C_TransferNoStopFlag))
                {
                    base->CONSET = kI2C_StopFlag;
                }
                break;

            case kI2C_Master_ArbitrationLost:
                result = kStatus_I2C_ArbitrationLost;
                break;

            /* Bus Error */
            case I2C_COMMONCODE_ERROR:
                result       = kStatus_I2C_BusError;
                base->CONSET = kI2C_StopFlag;
                break;

            default:
                assert(false);
                break;
        }

        if (result == kStatus_I2C_Addr_Nak)
        {
            I2C_MasterStop(base);
        }
        else
        {
            /* Continue state machine by clearing the interrupt flag. */
            base->CONCLR = kI2C_InterruptFlag;
        }

        if (result != kStatus_Success)
        {
            return result;
        }
    }

    if (!(flags & kI2C_TransferNoStopFlag))
    {
        result = I2C_MasterStop(base);
    }

    return result;
}

/*!
 * brief Performs a master polling transfer on the I2C bus.
 *
 * note The API does not return until the transfer succeeds or fails due
 * to arbitration lost or receiving a NAK.
 *
 * param base I2C peripheral base address.
 * param xfer Pointer to the transfer structure.
 * retval kStatus_Success Successfully complete the data transmission.
 * retval kStatus_I2C_Busy Previous transmission still not finished.
 * retval kStatus_I2C_Timeout Transfer error, wait signal timeout.
 * retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * retval kStataus_I2C_Nak Transfer error, receive NAK during transfer.
 */
status_t I2C_MasterTransferBlocking(I2C0_Type *base, i2c_master_transfer_t *xfer)
{
    status_t result = kStatus_Success;
    bool isDone     = false;

    assert(xfer != NULL);

    /* Send start signal if required. */
    if (!(xfer->flags & kI2C_TransferNoStartFlag))
    {
        base->CONSET = kI2C_StartFlag;
    }

    while ((result == kStatus_Success) && (isDone == false))
    {
        result = I2C_PendingStatusWait(base);
        if (result != kStatus_Success)
        {
            return result;
        }

        result = I2C_MasterRunTransferStateMachine(base, xfer, &isDone);
    }

    return result;
}

/*!
 * brief Creates a new handle for the I2C master non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the I2C_MasterTransferAbort() API shall be called.
 *
 * param base The I2C peripheral base address.
 * param[out] handle Pointer to the I2C master driver handle.
 * param callback User provided pointer to the asynchronous callback function.
 * param userData User provided pointer to the application callback data.
 */
void I2C_MasterTransferCreateHandle(I2C0_Type *base,
                                    i2c_master_handle_t *handle,
                                    i2c_master_transfer_callback_t callback,
                                    void *userData)
{
    uint32_t instance;

    assert(handle != NULL);

    /* Clear out the handle. */
    memset(handle, 0, sizeof(*handle));

    /* Look up instance number */
    instance = I2C_GetInstance(base);

    /* Save base and instance. */
    handle->completionCallback = callback;
    handle->userData           = userData;

    /* Save the context in global variables to support the double weak mechanism. */
    s_i2cHandle[instance] = handle;

    /* Save master interrupt handler. */
    s_i2cMasterIsr = I2C_MasterTransferHandleIRQ;
}

/*!
 * brief Performs a non-blocking transaction on the I2C bus.
 *
 * param base The I2C peripheral base address.
 * param handle Pointer to the I2C master driver handle.
 * param xfer The pointer to the transfer descriptor.
 * retval kStatus_Success The transaction was started successfully.
 * retval #kStatus_I2C_Busy Either another master is currently utilizing the bus, or a non-blocking
 *      transaction is already in progress.
 */
status_t I2C_MasterTransferNonBlocking(I2C0_Type *base, i2c_master_handle_t *handle, i2c_master_transfer_t *xfer)
{
    assert(handle != NULL);
    assert(xfer != NULL);
    assert(xfer->subaddressSize <= sizeof(xfer->subaddress));
    uint32_t instance = I2C_GetInstance(base);

    /* Return busy if another transaction is in progress. */
    if (handle->state != kIdleState)
    {
        return kStatus_I2C_Busy;
    }

    /* Send start signal if required. */
    if (!(xfer->flags & kI2C_TransferNoStartFlag))
    {
        base->CONSET = kI2C_StartFlag;
    }

    handle->transfer     = *xfer;
    handle->state        = kBusyState;
    handle->transferSize = xfer->dataSize;

    /* Enable NVIC IRQ. */
    EnableIRQ(s_i2cIRQ[instance]);

    return kStatus_Success;
}

/*!
 * brief Returns number of bytes transferred so far.
 * param base The I2C peripheral base address.
 * param handle Pointer to the I2C master driver handle.
 * param[out] count Number of bytes transferred so far by the non-blocking transaction.
 * retval kStatus_Success
 * retval #kStatus_I2C_Busy
 */
status_t I2C_MasterTransferGetCount(I2C0_Type *base, i2c_master_handle_t *handle, size_t *count)
{
    assert(handle != NULL);

    if (!count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (handle->state == kIdleState)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    /* There is no necessity to disable interrupts as we read a single integer value */
    *count = handle->transferSize - handle->transfer.dataSize;
    return kStatus_Success;
}

/*!
 * brief Terminates a non-blocking I2C master transmission early.
 *
 * note It is not safe to call this function from an IRQ handler that has a higher priority than the
 *      I2C peripheral's IRQ priority.
 *
 * param base The I2C peripheral base address.
 * param handle Pointer to the I2C master driver handle.
 * retval kStatus_Success A transaction was successfully aborted.
 * retval #kStatus_I2C_Timeout Abort failure due to flags polling timeout.
 */
status_t I2C_MasterTransferAbort(I2C0_Type *base, i2c_master_handle_t *handle)
{
    status_t result;
    uint32_t master_state;
    uint32_t instance = I2C_GetInstance(base);

    if (handle->state != kIdleState)
    {
        /* Disable NVIC IRQ. */
        DisableIRQ(s_i2cIRQ[instance]);

        /* Wait until module is ready */
        result = I2C_PendingStatusWait(base);

        if (result != kStatus_Success)
        {
            return result;
        }

        master_state = base->STAT;

        if ((master_state == kI2C_Master_RxAckaddress) || (master_state == kI2C_Master_RxAckData))
        {
            *handle->transfer.data++ = base->DAT;
            handle->transfer.dataSize--;

            /* Wait until module is ready */
            result = I2C_PendingStatusWait(base);

            if (result != kStatus_Success)
            {
                return result;
            }
        }

        result = I2C_MasterStop(base);
        if (result != kStatus_Success)
        {
            return result;
        }

        /* Get the state of the I2C module */
        master_state = base->STAT;

        /* Reset handle. */
        handle->state = kIdleState;
    }

    return kStatus_Success;
}

/* Master transfer state change handler handler */
static status_t I2C_MasterRunTransferStateMachine(I2C0_Type *base, i2c_master_transfer_t *transfer, bool *isDone)
{
    uint32_t flags        = kI2C_AllFlags;
    status_t result       = kStatus_Success;
    uint32_t master_state = base->STAT;
    i2c_direction_t direction;

    *isDone = false;
    switch (master_state)
    {
        case kI2C_Master_StartReady:   /* Start condition on bus */
        case kI2C_Master_RestartReady: /* Repeated start condition */
            if (transfer->subaddressSize)
            {
                direction = kI2C_Write;
            }
            else
            {
                direction = transfer->direction;
            }
            base->DAT = (uint32_t)((transfer->slaveAddress << 1) | ((uint32_t)direction & 1u));
            break;

        /* Tx handling */
        case kI2C_Master_TxAckAddress: /* SLA+W sent and ACK received */
        case kI2C_Master_TxAckData:    /* DATA sent and ACK received */
            if ((transfer->subaddressSize == 0) && (transfer->direction == kI2C_Read))
            {
                flags &= ~kI2C_StartFlag;
            }
            else if (transfer->subaddressSize)
            {
                transfer->subaddressSize--;
                base->DAT = ((transfer->subaddress) >> (8 * transfer->subaddressSize));
            }
            else if (transfer->dataSize)
            {
                base->DAT = *transfer->data++;
                transfer->dataSize--;
            }
            else if (transfer->dataSize == 0)
            {
                if (!(transfer->flags & kI2C_TransferNoStopFlag))
                {
                    flags &= ~kI2C_StopFlag;
                }
                *isDone = true;
            }
            else
            {
            }
            break;

        /* Rx handling */
        case kI2C_Master_RxNackData: /* Data Received and NACK sent */
            if ((!(transfer->flags & kI2C_TransferNoStopFlag)))
            {
                flags &= ~kI2C_StopFlag;
            }
            *isDone = true;
            SUPRESS_FALL_THROUGHT_WARNING();
        case kI2C_Master_RxAckData: /* Data Received and ACK sent */
            *transfer->data++ = (uint8_t)base->DAT;
            transfer->dataSize--;
            SUPRESS_FALL_THROUGHT_WARNING();
        case kI2C_Master_RxAckaddress: /* SLA+R sent and ACK received */
            if (transfer->dataSize > 1)
            {
                flags &= ~kI2C_AssertACKFlag;
            }
            break;

        /* NAK Handling */
        case kI2C_Master_TxNackData: /* DATA sent NAK received */
            transfer->data--;
            transfer->dataSize++;
            result  = kStatus_I2C_Nak;
            *isDone = true;
            flags &= ~kI2C_StopFlag;
            break;

        case kI2C_Master_TxNackAddress: /* SLA+W sent NAK received */
        case kI2C_Master_RxNackaddress: /* SLA+R sent NAK received */
            result  = kStatus_I2C_Addr_Nak;
            *isDone = true;
            flags &= ~kI2C_StopFlag;
            break;

        case kI2C_Master_ArbitrationLost: /* Arbitration lost */
            result  = kStatus_I2C_ArbitrationLost;
            *isDone = true;
            break;

        /* Bus Error */
        case I2C_COMMONCODE_ERROR:
            result  = kStatus_I2C_BusError;
            *isDone = true;
            flags &= ~kI2C_StopFlag;
            break;
    }

    /* Set clear control flags */
    base->CONSET = flags ^ kI2C_AllFlags;
    base->CONCLR = flags;

    return result;
}

/*!
 * brief Reusable routine to handle master interrupts.
 * note This function does not need to be called unless you are reimplementing the
 *  nonblocking API's interrupt handler routines to add special functionality.
 * param base The I2C peripheral base address.
 * param handle Pointer to the I2C master driver handle i2c_master_handle_t.
 */
void I2C_MasterTransferHandleIRQ(I2C0_Type *base, void *i2cHandle)
{
    assert(i2cHandle != NULL);

    i2c_master_handle_t *handle = (i2c_master_handle_t *)i2cHandle;
    bool isDone;
    status_t result;

    result = I2C_MasterRunTransferStateMachine(base, &(handle->transfer), &isDone);

    if (isDone || (result != kStatus_Success))
    {
        /* Restore handle to idle state. */
        handle->state = kIdleState;

        /* Invoke callback. */
        if (handle->completionCallback)
        {
            handle->completionCallback(base, handle, result, handle->userData);
        }
    }
}

/*!
 * @brief Invoke event from I2C_SlaveRunTransferStateMachine.
 *
 * Sets the event type to transfer structure and invokes the event callback, if it has been
 * enabled by eventMask.
 *
 * @param base The I2C peripheral base address.
 * @param handle The I2C slave handle for non-blocking APIs.
 * @param event The I2C slave event to invoke.
 */
static void I2C_SlaveInvokeEvent(I2C0_Type *base, i2c_slave_handle_t *handle, i2c_slave_transfer_event_t event)
{
    handle->transfer.event = event;
    if ((handle->callback) && (handle->transfer.eventMask & event))
    {
        handle->callback(base, &handle->transfer, handle->userData);

        /* if after event callback we have data buffer (callback func has added new data), keep transfer busy */
        if (false == handle->isBusy)
        {
            if (((handle->transfer.txData) && (handle->transfer.txSize)) ||
                ((handle->transfer.rxData) && (handle->transfer.rxSize)))
            {
                handle->isBusy = true;
            }
        }

        /* Clear the transferred count now that we have a new buffer. */
        if ((event == kI2C_SlaveReceiveEvent) || (event == kI2C_SlaveTransmitEvent))
        {
            handle->transfer.transferredCount = 0;
        }
    }
}

/* Slave state machine handler */
static void I2C_SlaveRunTransferStateMachine(I2C0_Type *base, i2c_slave_handle_t *handle)
{
    uint32_t flags                          = kI2C_AllFlags;
    uint32_t slave_state                    = base->STAT;
    volatile i2c_slave_transfer_t *transfer = &(handle->transfer);

    switch (slave_state)
    {
        case kI2C_Slave_AddressRxAckData:     /* SLA: Data received + ACK sent */
        case kI2C_Slave_GeneralCallRxAckData: /* GC: Data received + ACK sent */
            *transfer->rxData++ = (uint8_t)base->DAT;
            transfer->rxSize--;
            transfer->transferredCount++;
            if (transfer->rxSize > 1)
            {
                flags &= ~kI2C_AssertACKFlag;
            }
            break;

        case kI2C_Slave_AddressWriteAck:                      /* Own SLA+W received */
        case kI2C_Slave_MasterArbitrationLostAddressWriteAck: /* Own SLA+W received after losing arbitration */
        case kI2C_Slave_GeneralCallAck:                       /* GC+W received */
        case kI2C_Slave_MasterArbitrationLostGeneralCallAck:  /* GC+W received after losing arbitration */
            /* if we have no data in this transfer, call callback to get new */
            if ((handle->transfer.rxData == NULL) || (handle->transfer.rxSize == 0))
            {
                I2C_SlaveInvokeEvent(base, handle, kI2C_SlaveReceiveEvent);
            }
            transfer->receivedAddress = (uint8_t)base->DAT;
            if (transfer->rxSize > 1)
            {
                flags &= ~kI2C_AssertACKFlag;
            }
            break;

        case kI2C_Slave_AddressReadAck:                      /* SLA+R received */
        case kI2C_Slave_MasterArbitrationLostAddressReadAck: /* SLA+R received after losing arbitration */
            transfer->receivedAddress = (uint8_t)base->DAT;
            /* if we have no data in this transfer, call callback to get new */
            if ((handle->transfer.txData == NULL) || (handle->transfer.txSize == 0))
            {
                I2C_SlaveInvokeEvent(base, handle, kI2C_SlaveTransmitEvent);
            }
            SUPRESS_FALL_THROUGHT_WARNING();
        case kI2C_Slave_TxAckData: /* DATA sent and ACK received */
            base->DAT = *transfer->txData++;
            transfer->txSize--;
            transfer->transferredCount++;
            if (transfer->txSize > 0)
            {
                flags &= ~kI2C_AssertACKFlag;
            }
            break;

        case kI2C_Slave_AddressRxNackData:     /* SLA: Data received + NAK sent */
        case kI2C_Slave_GeneralCallRxNackData: /* GC: Data received + NAK sent */
            *transfer->rxData++ = (uint8_t)base->DAT;
            transfer->rxSize--;
            transfer->transferredCount++;
            if (0 == handle->transfer.rxSize)
            {
                handle->isBusy = false;
                I2C_SlaveInvokeEvent(base, handle, kI2C_SlaveCompletionEvent);
            }
            flags &= ~kI2C_AssertACKFlag;
            break;

        case kI2C_Slave_TxNackData:    /* Data transmitted and NAK received */
        case kI2C_Slave_TxAckLastData: /* Last data transmitted and ACK received */
            if (0 == handle->transfer.txSize)
            {
                handle->isBusy = false;
                I2C_SlaveInvokeEvent(base, handle, kI2C_SlaveCompletionEvent);
            }
            flags &= ~kI2C_AssertACKFlag;
            break;

        case kI2C_Slave_RxRestartStop: /* STOP/Repeated START condition received */
            /* is this last transaction for this transfer, allow next transaction */
            flags &= ~kI2C_AssertACKFlag;
            break;
    }

    /* Set clear control flags */
    base->CONSET = flags ^ kI2C_AllFlags;
    base->CONCLR = flags;
}

/*!
 * brief Provides a default configuration for the I2C slave peripheral.
 *
 * This function provides the following default configuration for the I2C slave peripheral:
 * code
 * slaveConfig->address0 = 0x0U;
 * slaveConfig->address1 = 0x0U;
 * slaveConfig->address2 = 0x0U;
 * slaveConfig->address3 = 0x0U;
 * slaveConfig->enableGeneralCall = false;
 * slaveConfig->enableSlave = true;
 * endcode
 *
 * After calling this function, override any settings  to customize the configuration,
 * prior to initializing the master driver with I2C_SlaveInit(). Be sure to override at least the a
 * address0.address member of the configuration structure with the desired slave address.
 *
 * param[out] slaveConfig User provided configuration structure that is set to default values. Refer to
 *      #i2c_slave_config_t.
 */
void I2C_SlaveGetDefaultConfig(i2c_slave_config_t *slaveConfig)
{
    assert(slaveConfig != NULL);

    /* Initializes the configure structure to zero. */
    memset(slaveConfig, 0, sizeof(*slaveConfig));

    slaveConfig->address0.address           = 0x0U;
    slaveConfig->address0.addressMask       = 0x0U;
    slaveConfig->address0.enableGeneralCall = false;
    slaveConfig->address1.address           = 0x0U;
    slaveConfig->address1.addressMask       = 0x0U;
    slaveConfig->address1.enableGeneralCall = false;
    slaveConfig->address2.address           = 0x0U;
    slaveConfig->address2.addressMask       = 0x0U;
    slaveConfig->address2.enableGeneralCall = false;
    slaveConfig->address3.address           = 0x0U;
    slaveConfig->address3.addressMask       = 0x0U;
    slaveConfig->address3.enableGeneralCall = false;
    slaveConfig->enableSlave                = true;
}

/*!
 * brief Configures Slave Address n register.
 *
 * This function writes new value to Slave Address register.
 *
 * param base The I2C peripheral base address.
 * param addressRegister The module supports multiple address registers. The parameter determines which one shall be
 * changed.
 * param addressConfig The slave address configuration.
 */
void I2C_SlaveSetAddress(I2C0_Type *base,
                         i2c_slave_address_register_t addressRegister,
                         i2c_slave_address_t *addressConfig)
{
    switch (addressRegister)
    {
        case kI2C_SlaveAddressRegister0:
            base->ADR0  = ((addressConfig->address << 1) | ((addressConfig->enableGeneralCall) & (0x1u)));
            base->MASK0 = addressConfig->addressMask;
            break;
        case kI2C_SlaveAddressRegister1:
            base->ADR1  = ((addressConfig->address << 1) | ((addressConfig->enableGeneralCall) & (0x1u)));
            base->MASK1 = addressConfig->addressMask;
            break;
        case kI2C_SlaveAddressRegister2:
            base->ADR2  = ((addressConfig->address << 1) | ((addressConfig->enableGeneralCall) & (0x1u)));
            base->MASK2 = addressConfig->addressMask;
            break;
        case kI2C_SlaveAddressRegister3:
            base->ADR3  = ((addressConfig->address << 1) | ((addressConfig->enableGeneralCall) & (0x1u)));
            base->MASK3 = addressConfig->addressMask;
            break;
    }
}

/*!
 * brief Initializes the I2C slave peripheral.
 *
 * This function enables the peripheral clock and initializes the I2C slave peripheral as described by the user
 * provided configuration.
 *
 * param base The I2C peripheral base address.
 * param slaveConfig User provided peripheral configuration. Use I2C_SlaveGetDefaultConfig() to get a set of defaults
 *      that you can override.
 * param srcClock_Hz Frequency in Hertz of the I2C functional clock. Used to calculate CLKDIV value to provide
 * enough data setup time for master when slave stretches the clock.
 */
status_t I2C_SlaveInit(I2C0_Type *base, const i2c_slave_config_t *slaveConfig)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_i2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_I2C_HAS_NO_RESET) && FSL_FEATURE_I2C_HAS_NO_RESET)
    RESET_PeripheralReset(s_i2cResets[I2C_GetInstance(base)]);
#endif

    base->ADR0  = ((slaveConfig->address0.address << 1) | ((slaveConfig->address0.enableGeneralCall) & (0x1u)));
    base->MASK0 = slaveConfig->address0.addressMask;

    base->ADR1  = ((slaveConfig->address1.address << 1) | ((slaveConfig->address1.enableGeneralCall) & (0x1u)));
    base->MASK1 = slaveConfig->address1.addressMask;

    base->ADR2  = ((slaveConfig->address2.address << 1) | ((slaveConfig->address2.enableGeneralCall) & (0x1u)));
    base->MASK2 = slaveConfig->address2.addressMask;

    base->ADR3  = ((slaveConfig->address3.address << 1) | ((slaveConfig->address3.enableGeneralCall) & (0x1u)));
    base->MASK3 = slaveConfig->address3.addressMask;

    /* Reset STA, STO, SI */
    base->CONCLR = I2C0_CONCLR_SIC_MASK | I2C0_CONCLR_STAC_MASK | I2C0_CONCLR_AAC_MASK;

    I2C_SlaveEnable(base, slaveConfig->enableSlave);

    return kStatus_Success;
}

/*!
 * brief Deinitializes the I2C slave peripheral.
 *
 * This function disables the I2C slave peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * param base The I2C peripheral base address.
 */
void I2C_SlaveDeinit(I2C0_Type *base)
{
    I2C_SlaveEnable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_i2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Performs a polling send transfer on the I2C bus.
 *
 * The function executes blocking address phase and blocking data phase.
 *
 * param base  The I2C peripheral base address.
 * param txBuff The pointer to the data to be transferred.
 * param txSize The length in bytes of the data to be transferred.
 * return kStatus_Success Data has been sent.
 * return kStatus_Fail Unexpected slave state (master data write while master read from slave is expected).
 */
status_t I2C_SlaveWriteBlocking(I2C0_Type *base, const uint8_t *txBuff, size_t txSize)
{
    uint32_t flags  = kI2C_AllFlags;
    status_t result = kStatus_Success;

    const uint8_t *buf = (const uint8_t *)(uintptr_t)txBuff;

    assert(txBuff != NULL);

    while (result == kStatus_Success)
    {
        result = I2C_PendingStatusWait(base);
        if (result != kStatus_Success)
        {
            break;
        }

        switch (I2C_GetState(base))
        {
            case kI2C_Slave_AddressReadAck:                      /* SLA+R received */
            case kI2C_Slave_MasterArbitrationLostAddressReadAck: /* SLA+R received after losing arbitration */
                break;

            case kI2C_Slave_TxAckData: /* DATA sent and ACK received */
                base->DAT = *buf++;
                txSize--;
                if (txSize > 0)
                {
                    flags &= ~kI2C_AssertACKFlag;
                }
                break;

            case kI2C_Slave_TxNackData:    /* Data transmitted and NAK received */
            case kI2C_Slave_TxAckLastData: /* Last data transmitted and ACK received */
            case kI2C_Slave_RxRestartStop: /* STOP/Repeated START condition received */
                if (txSize != 0)
                {
                    result = kStatus_I2C_Nak;
                }
                flags &= ~kI2C_AssertACKFlag;
                break;
        }

        /* Set clear control flags */
        base->CONSET = flags ^ kI2C_AllFlags;
        base->CONCLR = flags;
    }

    return result;
}

/*!
 * brief Performs a polling receive transfer on the I2C bus.
 *
 * The function executes blocking address phase and blocking data phase.
 *
 * param base  The I2C peripheral base address.
 * param rxBuff The pointer to the data to be transferred.
 * param rxSize The length in bytes of the data to be transferred.
 * return kStatus_Success Data has been received.
 * return kStatus_Fail Unexpected slave state (master data read while master write to slave is expected).
 */
status_t I2C_SlaveReadBlocking(I2C0_Type *base, uint8_t *rxBuff, size_t rxSize)
{
    uint32_t flags  = kI2C_AllFlags;
    status_t result = kStatus_Success;
    bool isDone     = false;

    uint8_t *buf = (uint8_t *)(rxBuff);

    assert(rxBuff != NULL);

    while ((result == kStatus_Success) && (isDone == false))
    {
        result = I2C_PendingStatusWait(base);
        if (result != kStatus_Success)
        {
            break;
        }

        switch (I2C_GetState(base))
        {
            case kI2C_Slave_AddressRxAckData:     /* SLA: Data received + ACK sent */
            case kI2C_Slave_GeneralCallRxAckData: /* GC: Data received + ACK sent */
                *buf++ = (uint8_t)base->DAT;
                rxSize--;
                if (rxSize > 1)
                {
                    flags &= ~kI2C_AssertACKFlag;
                }
                break;

            case kI2C_Slave_AddressWriteAck:                      /* Own SLA+W received */
            case kI2C_Slave_MasterArbitrationLostAddressWriteAck: /* Own SLA+W received after losing arbitration */
            case kI2C_Slave_GeneralCallAck:                       /* GC+W received */
            case kI2C_Slave_MasterArbitrationLostGeneralCallAck:  /* GC+W received after losing arbitration */
                if (rxSize > 1)
                {
                    flags &= ~kI2C_AssertACKFlag;
                }
                break;

            case kI2C_Slave_AddressRxNackData:     /* SLA: Data received + NAK sent */
            case kI2C_Slave_GeneralCallRxNackData: /* GC: Data received + NAK sent */
                *buf++ = (uint8_t)base->DAT;
                rxSize--;
                SUPRESS_FALL_THROUGHT_WARNING();
            case kI2C_Slave_RxRestartStop: /* STOP/Repeated START condition received */
                isDone = true;
                if (rxSize != 0)
                {
                    result = kStatus_I2C_Nak;
                }
                flags &= ~kI2C_AssertACKFlag;
                break;
        }

        /* Set clear control flags */
        base->CONSET = flags ^ kI2C_AllFlags;
        base->CONCLR = flags;
    }

    return result;
}

/*!
 * brief Creates a new handle for the I2C slave non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the I2C_SlaveTransferAbort() API shall be called.
 *
 * param base The I2C peripheral base address.
 * param[out] handle Pointer to the I2C slave driver handle.
 * param callback User provided pointer to the asynchronous callback function.
 * param userData User provided pointer to the application callback data.
 */
void I2C_SlaveTransferCreateHandle(I2C0_Type *base,
                                   i2c_slave_handle_t *handle,
                                   i2c_slave_transfer_callback_t callback,
                                   void *userData)
{
    uint32_t instance;

    assert(handle != NULL);

    /* Clear out the handle. */
    memset(handle, 0, sizeof(*handle));

    /* Look up instance number */
    instance = I2C_GetInstance(base);

    /* Save base and instance. */
    handle->callback = callback;
    handle->userData = userData;

    /* Save the context in global variables to support the double weak mechanism. */
    s_i2cHandle[instance] = handle;

    /* Save slave interrupt handler. */
    s_i2cSlaveIsr = I2C_SlaveTransferHandleIRQ;
}

/*!
 * brief Starts accepting slave transfers.
 *
 * Call this API after calling I2C_SlaveInit() and I2C_SlaveTransferCreateHandle() to start processing
 * transactions driven by an I2C master. The slave monitors the I2C bus and pass events to the
 * callback that was passed into the call to I2C_SlaveTransferCreateHandle(). The callback is always invoked
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
 * param handle Pointer to i2c_slave_handle_t structure which stores the transfer state.
 * param eventMask Bit mask formed by OR'ing together #i2c_slave_transfer_event_t enumerators to specify
 *      which events to send to the callback. Other accepted values are 0 to get a default set of
 *      only the transmit and receive events, and #kI2C_SlaveAllEvents to enable all events.
 *
 * retval kStatus_Success Slave transfers were successfully started.
 * retval #kStatus_I2C_Busy Slave transfers have already been started on this handle.
 */
status_t I2C_SlaveTransferNonBlocking(I2C0_Type *base, i2c_slave_handle_t *handle, uint32_t eventMask)
{
    status_t result;

    assert(handle != NULL);

    uint32_t instance = I2C_GetInstance(base);

    result = kStatus_Success;

    /* Return busy if another transaction is in progress. */
    if (handle->isBusy)
    {
        result = kStatus_I2C_Busy;
    }

    handle->transfer.eventMask = eventMask | kI2C_SlaveTransmitEvent | kI2C_SlaveReceiveEvent;
    handle->isBusy             = true;

    EnableIRQ(s_i2cIRQ[instance]);

    return result;
}

/*!
 * brief Gets the slave transfer remaining bytes during a interrupt non-blocking transfer.
 *
 * param base I2C base pointer.
 * param handle pointer to i2c_slave_handle_t structure.
 * param count Number of bytes transferred so far by the non-blocking transaction.
 * retval kStatus_InvalidArgument count is Invalid.
 * retval kStatus_Success Successfully return the count.
 */
status_t I2C_SlaveTransferGetCount(I2C0_Type *base, i2c_slave_handle_t *handle, size_t *count)
{
    assert(handle != NULL);

    if (!count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (!handle->isBusy)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    /* For an active transfer, just return the count from the handle. */
    *count = handle->transfer.transferredCount;

    return kStatus_Success;
}

/*!
 * brief Aborts the slave non-blocking transfers.
 * note This API could be called at any time to stop slave for handling the bus events.
 * param base The I2C peripheral base address.
 * param handle Pointer to i2c_slave_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferAbort(I2C0_Type *base, i2c_slave_handle_t *handle)
{
    uint32_t instance = I2C_GetInstance(base);
    DisableIRQ(s_i2cIRQ[instance]);

    handle->isBusy          = false;
    handle->transfer.txSize = 0;
    handle->transfer.rxSize = 0;
}

/*!
 * brief Reusable routine to handle slave interrupts.
 * note This function does not need to be called unless you are reimplementing the
 *  non blocking API's interrupt handler routines to add special functionality.
 * param base The I2C peripheral base address.
 * param handle Pointer to i2c_slave_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferHandleIRQ(I2C0_Type *base, void *i2cHandle)
{
    assert(i2cHandle != NULL);

    I2C_SlaveRunTransferStateMachine(base, (i2c_slave_handle_t *)i2cHandle);
}

static void I2C_TransferCommonIRQHandler(I2C0_Type *base, void *handle)
{
    /* Check if master interrupt. */
    if (I2C_GetState(base) < kI2C_Slave_AddressWriteAck)
    {
        s_i2cMasterIsr(base, handle);
    }
    else
    {
        s_i2cSlaveIsr(base, handle);
    }
    SDK_ISR_EXIT_BARRIER;
}

#if defined(I2C0)
void I2C0_DriverIRQHandler(void);
void I2C0_DriverIRQHandler(void)
{
    /* Check if the active state belongs to master mode*/
    I2C_TransferCommonIRQHandler(I2C0, s_i2cHandle[0]);
}
#endif
