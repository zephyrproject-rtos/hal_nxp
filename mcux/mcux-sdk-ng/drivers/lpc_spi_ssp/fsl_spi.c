/*
 * Copyright  2018 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpc_spi_ssp"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if defined(FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API) && (FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API)
/*! @brief SPI internal handle pointer array */
static spi_master_handle_t *s_spiHandle;

/*! @brief Typedef for spi master interrupt handler. spi master and slave handle is the same. */
typedef void (*spi_isr_t)(SPI0_Type *base, spi_master_handle_t *spiHandle);
/*! @brief Pointer to master IRQ handler for each instance. */
static spi_isr_t s_spiIsr;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/

#if defined(FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API) && (FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API)
/*!
 * @brief Send data for SPI.
 *
 * This function will check if TX FIFO is available, if not will write the data into it.
 * At the same time, this function updates the values in master handle structure.
 *
 * @param base SPI base pointer
 * @param handle Pointer to SPI master handle structure.
 */
static void SPI_SendTransfer(SPI0_Type *base, spi_master_handle_t *handle)
{
    uint16_t tmp = 0U;

    /* Check the status flag to wirte data. */
    while ((SPI_GetStatusFlags(base) &
            ((base->CR1 & SPI0_CR1_MS_MASK) ? kSPI_TxFifoHalfEmptyFlag : kSPI_TxFifoEmptyFlag)) &&
           (0U != handle->txRemainingBytes))
    {
        if (NULL == handle->txData)
        {
            handle->txRemainingBytes--;
            if (handle->dataWidth > 7)
            {
                handle->txRemainingBytes--;
            }
            base->DR = TX_DUMMY_DATA;
        }
        else
        {
            tmp = *(handle->txData++);
            handle->txRemainingBytes--;
            if (handle->dataWidth > 7)
            {
                tmp |= ((uint16_t) * (handle->txData++) << 8);
                handle->txRemainingBytes--;
            }
            base->DR = tmp;
        }
    }
}

/*!
 * @brief Receive a piece of data for SPI.
 *
 * This function will check if RX data is ready, and write the data to destination address.
 * At the same time, this function updates the values in master handle structure.
 *
 * @param base SPI base pointer
 * @param handle Pointer to SPI master handle structure.
 */
static void SPI_ReceiveTransfer(SPI0_Type *base, spi_master_handle_t *handle)
{
    uint16_t tmp = 0U;

    /* Read data from RD register if FIFO is not empty. */
    while ((kSPI_RxFifoNotEmptyFlag & SPI_GetStatusFlags(base)) && handle->rxRemainingBytes)
    {
        if (NULL == handle->rxData)
        {
            handle->rxRemainingBytes--;
            if (handle->dataWidth > 7U)
            {
                handle->rxRemainingBytes--;
            }

            (void)base->DR;
        }
        else
        {
            tmp                 = base->DR;
            *(handle->rxData++) = tmp;
            handle->rxRemainingBytes--;
            if (handle->dataWidth > 7U)
            {
                *(handle->rxData++) = (tmp >> 8U);
                handle->rxRemainingBytes--;
            }
        }
    }
}
#endif

/*!
 * brief  Sets the SPI master configuration structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for use in SPI_MasterInit().
 * User may use the initialized structure unchanged in SPI_MasterInit(), or modify
 * some fields of the structure before calling SPI_MasterInit(). After calling this API,
 * the master is ready to transfer.
 * Example:
   code
   spi_master_config_t config;
   SPI_MasterGetDefaultConfig(&config);
   endcode
 *
 * param config pointer to master config structure
 */
void SPI_MasterGetDefaultConfig(spi_master_config_t *config)
{
    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->baudRate_Bps   = 500000U;
    config->clockPhase     = kSPI_ClockPhaseFirstEdge;
    config->clockPolarity  = kSPI_ClockPolarityActiveHigh;
    config->dataWidth      = 8U;
    config->enableLoopback = false;
    config->enableMaster   = true;
    config->frameFormat    = kSPI_FrameFormatSPI;
}

/*!
 * brief Initializes the SPI with master configuration.
 *
 * The configuration structure can be filled by user from scratch, or be set with default
 * values by SPI_MasterGetDefaultConfig(). After calling this API, the slave is ready to transfer.
 * Please note that: Current transfer APIs are for SPI format mode, for TI and Micro Wire mode, please
 * use low level API to adapt the real application.
 * Example
   code
   spi_master_config_t config = {
   .baudRate_Bps = 500000,
   ...
   };
   SPI_MasterInit(SPI0, &config);
   endcode
 *
 * param base SPI base pointer
 * param config pointer to master configuration structure
 * param srcClock_Hz Source clock frequency.
 */
status_t SPI_MasterInit(SPI0_Type *base, const spi_master_config_t *config, uint32_t srcClock_Hz)
{
    assert(config != NULL);
    assert(base != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Spissp);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
    /* Reset the module. */
    RESET_PeripheralReset(kSSP_RST_N_SHIFT_RSTn);
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

    /* Config the CRO register to setup the data size, frame format, clock polarity, clock phase. */
    base->CR0 = SPI0_CR0_DSS(config->dataWidth - 1) | SPI0_CR0_FRF(config->frameFormat) |
                SPI0_CR0_CPOL(config->clockPolarity) | SPI0_CR0_CPHA(config->clockPhase);

#if defined(FSL_SDK_SPI_DRIVER_ENABLE_BAUDRATE_AUTO_GENERATE) && (FSL_SDK_SPI_DRIVER_ENABLE_BAUDRATE_AUTO_GENERATE)
    int32_t result = 0;
    /* Set the baud rate for SPI master. */
    result = SPI_MasterSetBaudRate(base, config->baudRate_Bps, srcClock_Hz);
    if (kStatus_Success != result)
    {
        return result;
    }
#else
    base->CR0 |= (base->CR0 & ~SPI0_CR0_SCR_MASK) | SPI0_CR0_SCR(FSL_SDK_SPI_SCR_VALUE);
    base->CPSR = SPI0_CPSR_CPSDVSR(FSL_SDK_SPI_CPSDVSR_VALUE);
#endif

    /* Config the CR1 register. */
    base->CR1 = SPI0_CR1_LBM(config->enableLoopback);
    /* Enable master mode for SPI. */
    base->CR1 &= ~SPI0_CR1_MS_MASK;
    /* Enable SPI for transfer. */
    SPI_Enable(base, config->enableMaster);

    return kStatus_Success;
}

/*!
 * brief  Sets the SPI slave configuration structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for use in SPI_SlaveInit().
 * Modify some fields of the structure before calling SPI_SlaveInit().
 * Example:
   code
   spi_slave_config_t config;
   SPI_SlaveGetDefaultConfig(&config);
   endcode
 *
 * param config pointer to slave configuration structure
 */
void SPI_SlaveGetDefaultConfig(spi_slave_config_t *config)
{
    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->clockPhase    = kSPI_ClockPhaseFirstEdge;
    config->clockPolarity = kSPI_ClockPolarityActiveHigh;
    config->dataWidth     = 8U;
    config->enableSlave   = true;
    config->enableOutput  = false;
    config->frameFormat   = kSPI_FrameFormatSPI;
}

/*!
 * brief Initializes the SPI with slave configuration.
 *
 * The configuration structure can be filled by user from scratch or be set with
 * default values by SPI_SlaveGetDefaultConfig().
 * After calling this API, the slave is ready to transfer.
 * Example
   code
    spi_slave_config_t config = {
    .polarity = kSPI_ClockPolarityActiveHigh;
    .phase = kSPI_ClockPhaseFirstEdge;
    ...
    };
    SPI_SlaveInit(SPI0, &config);
   endcode
 *
 * param base SPI base pointer
 * param config pointer to slave configuration structure
 */
status_t SPI_SlaveInit(SPI0_Type *base, const spi_slave_config_t *config)
{
    assert(config != NULL);
    assert(base != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Spissp);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
    /* Reset the module. */
    RESET_PeripheralReset(kSSP_RST_N_SHIFT_RSTn);
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

    /* Config the CRO register to setup the data size, frame format, clock polarity, clock phase. */
    base->CR0 = SPI0_CR0_DSS(config->dataWidth - 1) | SPI0_CR0_FRF(config->frameFormat) |
                SPI0_CR0_CPOL(config->clockPolarity) | SPI0_CR0_CPHA(config->clockPhase);
    /* Config the CR1 register to enable slave mode. */
    base->CR1 |= SPI0_CR1_MS_MASK;
    /* Enable SPI for transfer. */
    SPI_Enable(base, config->enableSlave);

    return kStatus_Success;
}

/*!
 * brief De-initializes the SPI.
 *
 * Calling this API resets the SPI module, gates the SPI clock.
 *
 * The SPI module can't work unless calling the SPI_MasterInit/SPI_SlaveInit to initialize module.
 *
 * param base SPI base pointer
 */
void SPI_Deinit(SPI0_Type *base)
{
    assert(base != NULL);

    /* Waiting for the SPI become IDLE. */
    while (SPI0_SR_BSY_MASK == SPI_GetStatusFlags(base))
    {
    }
    /* Disable SPI mode. */
    SPI_Enable(base, false);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Spissp);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets the baud rate for SPI transfer. This is only used in master.
 *
 * param base SPI base pointer
 * param baudrate_Bps baud rate needed in Hz.
 * param srcClock_Hz SPI source clock frequency in Hz.
 */
status_t SPI_MasterSetBaudRate(SPI0_Type *base, uint32_t baudrate_Bps, uint32_t srcClock_Hz)
{
    assert(0U != baudrate_Bps);
    assert(0U != srcClock_Hz);

    uint16_t scrValue      = 0U;
    uint16_t preScaleValue = 2U;
    uint32_t tmp           = (srcClock_Hz / baudrate_Bps);

    /* Can not generate supported baud rate. */
    if (((tmp >> 8U) > 0xFE) || (tmp < 2))
    {
        return kStatus_SPI_BaudrateNotSupport;
    }

    for (preScaleValue = 2U; preScaleValue < 255; preScaleValue += 2)
    {
        scrValue = (tmp / preScaleValue) - 1;

        if (scrValue > 0xFF)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    /* If value caculated is not precise, please set the clock source or set baud rate manually. */
    if (tmp % preScaleValue)
    {
        return kStatus_SPI_BaudrateNotSupport;
    }

    base->CR0  = (base->CR0 & ~SPI0_CR0_SCR_MASK) | SPI0_CR0_SCR(scrValue);
    base->CPSR = preScaleValue;

    return kStatus_Success;
}

/*!
 * brief Transfers a block of data using a polling method.
 *
 * param base SPI base pointer
 * param xfer pointer to spi_xfer_config_t structure
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Timeout The transfer timed out and was aborted.
 */
status_t SPI_MasterTransferBlocking(SPI0_Type *base, spi_transfer_t *xfer)
{
    uint32_t txRemainingBytes = 0U, rxRemainingBytes = 0U;
    uint8_t dataWidth = 0U;
    uint16_t tmp      = 0U;
#if SPI_RETRY_TIMES
    uint32_t waitTimes = SPI_RETRY_TIMES;
#endif

    if ((xfer->dataSize == 0U) || ((xfer->rxData == NULL) && (xfer->txData == NULL)))
    {
        return kStatus_InvalidArgument;
    }
    txRemainingBytes = xfer->dataSize;
    if (xfer->rxData != NULL)
    {
        rxRemainingBytes = xfer->dataSize;
    }
    /* Get the data width from configuration. */
    dataWidth = (uint8_t)((base->CR0 & SPI0_CR0_DSS_MASK) >> SPI0_CR0_DSS_SHIFT);

    while (txRemainingBytes || rxRemainingBytes)
    {
#if SPI_RETRY_TIMES
        if (--waitTimes == 0U)
        {
            return kStatus_SPI_Timeout;
        }
#endif
        /* Writing data to the FIFO. */
        if ((kSPI_TxFifoNotFullFlag & SPI_GetStatusFlags(base)) && txRemainingBytes)
        {
            if (NULL == xfer->txData)
            {
                txRemainingBytes--;
                if (dataWidth > 7)
                {
                    txRemainingBytes--;
                }
                base->DR = TX_DUMMY_DATA;
            }
            else
            {
                tmp = *(xfer->txData++);
                txRemainingBytes--;
                if (dataWidth > 7)
                {
                    tmp |= ((uint16_t) * (xfer->txData++) << 8);
                    txRemainingBytes--;
                }
                base->DR = tmp;
            }
        }

        /* Read data from DR register if FIFO is not empty. */
        if ((kSPI_RxFifoNotEmptyFlag & SPI_GetStatusFlags(base)) && rxRemainingBytes)
        {
            tmp               = base->DR;
            *(xfer->rxData++) = tmp;
            rxRemainingBytes--;
            if (dataWidth > 7U)
            {
                *(xfer->rxData++) = (tmp >> 8U);
                rxRemainingBytes--;
            }
        }
    }

    /* Waiting for the SPI become IDLE, no data to be sent or received. */
#if SPI_RETRY_TIMES
    waitTimes = SPI_RETRY_TIMES;
    while ((kSPI_BusyFlag & SPI_GetStatusFlags(base)) && (--waitTimes != 0U))
#else
    while (kSPI_BusyFlag & SPI_GetStatusFlags(base))
#endif
    {
    }

#if SPI_RETRY_TIMES
    if (waitTimes == 0U)
    {
        return kStatus_SPI_Timeout;
    }
#endif

    /* If the xfer->rxData is NULL, need to clear rx FIFO before ending transfer. */
    if (NULL == xfer->rxData)
    {
#if SPI_RETRY_TIMES
        waitTimes = SPI_RETRY_TIMES;
        while ((kSPI_RxFifoNotEmptyFlag & SPI_GetStatusFlags(base)) && (--waitTimes != 0U))
#else
        while (kSPI_RxFifoNotEmptyFlag & SPI_GetStatusFlags(base))
#endif
        {
            (void)base->DR;
        }

#if SPI_RETRY_TIMES
        if (waitTimes == 0U)
        {
            return kStatus_SPI_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

#if defined(FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API) && (FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API)

/*!
 * brief Initializes the SPI master handle.
 *
 * This function initializes the SPI master handle which can be used for other SPI master transactional APIs. Usually,
 * for a specified SPI instance, call this API once to get the initialized handle.
 *
 * param base SPI peripheral base address.
 * param handle SPI handle pointer.
 * param callback Callback function.
 * param userData User data.
 */
status_t SPI_MasterTransferCreateHandle(SPI0_Type *base,
                                        spi_master_handle_t *handle,
                                        spi_master_callback_t callback,
                                        void *userData)
{
    assert(NULL != base);
    assert(NULL != handle);

    memset(handle, 0, sizeof(*handle));
    handle->callback  = callback;
    handle->userData  = userData;
    handle->dataWidth = (base->CR0 & SPI0_CR0_DSS_MASK) >> SPI0_CR0_DSS_SHIFT;
    s_spiHandle       = handle;

    s_spiIsr = SPI_TransferHandleIRQ;

    /* Enable the NVIC for SPI module. */
    EnableIRQ(SSP0_IRQn);

    return kStatus_Success;
}

/*!
 * brief Initializes the SPI slave handle.
 *
 * This function initializes the SPI slave handle which can be used for other SPI slave transactional APIs. Usually,
 * for a specified SPI instance, call this API once to get the initialized handle.
 *
 * param base SPI peripheral base address.
 * param handle SPI handle pointer.
 * param callback Callback function.
 * param userData User data.
 */
status_t SPI_SlaveTransferCreateHandle(SPI0_Type *base,
                                       spi_slave_handle_t *handle,
                                       spi_slave_callback_t callback,
                                       void *userData)
{
    SPI_MasterTransferCreateHandle(base, handle, callback, userData);
    return kStatus_Success;
}

/*!
 * brief Performs a non-blocking SPI interrupt transfer.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_master_handle_t structure which stores the transfer state
 * param xfer pointer to spi_xfer_config_t structure
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_MasterTransferNonBlocking(SPI0_Type *base, spi_master_handle_t *handle, spi_transfer_t *xfer)
{
    assert((base != NULL) && (handle != NULL) && (xfer != NULL) && (xfer->dataSize != 0U));

    /* Data size should be aligned with transfer size. */
    if ((handle->dataWidth > 7U) && (xfer->dataSize & 0x1U))
    {
        return kStatus_InvalidArgument;
    }

    /* Check if SPI is in IDLE status. */
    if (handle->state == kStatus_SPI_Busy)
    {
        return kStatus_SPI_Busy;
    }

    handle->txData = xfer->txData;
    handle->rxData = xfer->rxData;

    handle->totalByteCount   = xfer->dataSize;
    handle->rxRemainingBytes = xfer->dataSize;
    handle->txRemainingBytes = xfer->dataSize;

    handle->state = kStatus_SPI_Busy;

    SPI_EnableInterrupts(base, kSPI_TxFifoHalfEmptyInterruptEnable);

    /* Enable SPI module. */
    SPI_Enable(base, true);

    return kStatus_Success;
}

/*!
 * brief Performs a non-blocking SPI slave interrupt transfer.
 *
 * note The API returns immediately after the transfer initialization is finished.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_master_handle_t structure which stores the transfer state
 * param xfer pointer to spi_xfer_config_t structure
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_SlaveTransferNonBlocking(SPI0_Type *base, spi_slave_handle_t *handle, spi_transfer_t *xfer)
{
    status_t status = 0U;

    status = SPI_MasterTransferNonBlocking(base, handle, xfer);

    if (kStatus_Success != status)
    {
        return status;
    }

    return kStatus_Success;
}

/*!
 * brief Gets the master transfer count.
 *
 * This function gets the master transfer count.
 *
 * param base SPI peripheral base address.
 * param handle Pointer to the spi_master_handle_t structure which stores the transfer state.
 * param count The number of bytes transferred by using the non-blocking transaction.
 * return status of status_t.
 */
status_t SPI_MasterTransferGetCount(SPI0_Type *base, spi_master_handle_t *handle, size_t *count)
{
    assert((base != NULL) && (handle != NULL) && (count != NULL));

    if (handle->state != kStatus_SPI_Busy)
    {
        *count = 0U;
        return kStatus_NoTransferInProgress;
    }

    *count = handle->totalByteCount - handle->rxRemainingBytes;

    return kStatus_Success;
}

/*!
 * brief SPI master aborts a transfer using an interrupt.
 *
 * This function aborts a transfer using an interrupt.
 *
 * param base SPI peripheral base address.
 * param handle Pointer to the spi_master_handle_t structure which stores the transfer state.
 */
void SPI_MasterTransferAbort(SPI0_Type *base, spi_master_handle_t *handle)
{
    assert((base != NULL) && (handle != NULL));

    SPI_DisableInterrupts(base, kSPI_TxFifoHalfEmptyInterruptEnable);

    handle->state            = kStatus_SPI_Idle;
    handle->txRemainingBytes = 0U;
    handle->rxRemainingBytes = 0U;
}

/*!
 * brief Interrupts a handler for the SPI slave.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_slave_handle_t structure which stores the transfer state
 */
void SPI_TransferHandleIRQ(SPI0_Type *base, spi_master_handle_t *handle)
{
    assert((NULL != base) && (NULL != handle));

    /* Data to send or read or expected to receive */
    if (handle->rxRemainingBytes)
    {
        SPI_ReceiveTransfer(base, handle);
    }
    if (handle->txRemainingBytes)
    {
        SPI_SendTransfer(base, handle);
    }

    if ((0U == handle->txRemainingBytes) && (0U == handle->rxRemainingBytes))
    {
        /* Disable interrupt. */
        SPI_DisableInterrupts(base, kSPI_TxFifoHalfEmptyInterruptEnable);

        /* Set transfer state to idle. */
        handle->state = kStatus_SPI_Idle;
        /* If callback is not NULL, call this function. */
        if (handle->callback)
        {
            (handle->callback)(base, handle, handle->state, handle->userData);
        }
    }
}

#if defined(SPI0)
void SSP0_DriverIRQHandler(void);
void SSP0_DriverIRQHandler(void)
{
    s_spiIsr(SPI0, s_spiHandle);
}
#endif
#endif
