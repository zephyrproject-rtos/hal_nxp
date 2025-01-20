/*
 * Copyright  2018 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SPI_H_
#define FSL_SPI_H_

#include "fsl_common.h"

/*!
 * @addtogroup spi_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief SPI driver version 2.0.1. */
#define FSL_SPI_DRIVER_VERSION (MAKE_VERSION(2, 0, 3))
/*! @} */

#define TX_DUMMY_DATA 0x00

/*! @brief Macro for control transaction API, will help reduce code overhead when using polling mode only. */
#ifndef FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API
#define FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API 1
#endif

/*! @brief Macro for control baud rate auto generate, will help reduce code size when baud rate is fixed. */
#ifndef FSL_SDK_SPI_DRIVER_ENABLE_BAUDRATE_AUTO_GENERATE
#define FSL_SDK_SPI_DRIVER_ENABLE_BAUDRATE_AUTO_GENERATE 1
#endif

/*!
 *@brief  Macro for baud rate setting if baud rate auto generate function was disabled.
 *        Formula for baud rate : baudRate = SpiClockSource_Hz/ (CPSDVSR * (SCR +1)).
 * Common value for use:
 *    | SPI baud rate(Hz)  |  SPI clock frequency(Hz)  |    CPSDVSR     |     SCR     |
 *           1000000       |        8000000            |       2        |      3      |
 *           1000000       |        2000000            |       2        |      0      |
 *           500000        |        8000000            |       2        |      7      |
 *           500000        |        2000000            |       2        |      1      |
 *           100000        |        8000000            |       4        |      19     |
 *           100000        |        2000000            |       2        |      9      |
 *
 */
#if !(defined(FSL_SDK_SPI_DRIVER_ENABLE_BAUDRATE_AUTO_GENERATE) && (FSL_SDK_SPI_DRIVER_ENABLE_BAUDRATE_AUTO_GENERATE))
#ifndef FSL_SDK_SPI_SCR_VALUE
#define FSL_SDK_SPI_SCR_VALUE 7
#endif

#ifndef FSL_SDK_SPI_CPSDVSR_VALUE
#define FSL_SDK_SPI_CPSDVSR_VALUE 2
#endif
#endif

/*! @brief Retry times for waiting flag. */
#ifndef SPI_RETRY_TIMES
#define SPI_RETRY_TIMES 0U /* Define to zero means keep waiting until the flag is assert/deassert. */
#endif

/*! @brief SPI data size select options.*/
typedef enum _spi_frame_format_select
{
    kSPI_FrameFormatSPI       = 0U, /*!< Transfer frame format using SPI mode. */
    kSPI_FrameFormatTI        = 1U, /*!< Transfer frame format using TI mode. */
    kSPI_FrameFormatMicroWire = 2U, /*!< Transfer frame format using microwire mode. */
} spi_frame_format_select_t;

/*! @brief SPI clock polarity configuration.*/
typedef enum _spi_clock_polarity
{
    kSPI_ClockPolarityActiveHigh = 0x0U, /*!< Active-high SPI clock (idles low). */
    kSPI_ClockPolarityActiveLow  = 0x1U, /*!< Active-low SPI clock (idles high). */
} spi_clock_polarity_t;

/*! @brief SPI clock phase configuration.*/
typedef enum _spi_clock_phase
{
    kSPI_ClockPhaseFirstEdge =
        0x0U, /*!< SPI controller captures serial data on the first clock transition of the frame. */
    kSPI_ClockPhaseSecondEdge =
        0x1U, /*!< SPI controller captures serial data on the second clock transition of the frame. */
} spi_clock_phase_t;

/*! @brief SPI master user configure structure.*/
typedef struct _spi_master_config
{
    bool enableLoopback;                   /*!< Enable loopback for test purpose */
    bool enableMaster;                     /*!< Enable SPI at initialization time */
    uint32_t baudRate_Bps;                 /*!< Baud Rate for SPI in Hz */
    spi_clock_polarity_t clockPolarity;    /*!< Clock polarity */
    spi_clock_phase_t clockPhase;          /*!< Clock phase */
    spi_frame_format_select_t frameFormat; /*!< Frame format mode. */
    uint8_t dataWidth;                     /*!< Width of the data */
} spi_master_config_t;

/*! @brief SPI slave user configure structure.*/
typedef struct _spi_slave_config
{
    bool enableSlave;                      /*!< Enable SPI at initialization time */
    bool enableOutput;                     /*!< Enable slave SPI output. */
    spi_clock_polarity_t clockPolarity;    /*!< Clock polarity */
    spi_clock_phase_t clockPhase;          /*!< Clock phase */
    spi_frame_format_select_t frameFormat; /*!< Frame format mode. */
    uint8_t dataWidth;                     /*!< Width of the data */
} spi_slave_config_t;

/*! @brief SPI transfer status.*/
enum _spi_status
{
    kStatus_SPI_Busy = MAKE_STATUS(kStatusGroup_LPC_SPI_SSP, 0), /*!< SPI bus is busy */
    kStatus_SPI_Idle = MAKE_STATUS(kStatusGroup_LPC_SPI_SSP, 1), /*!< SPI is idle */
    kStatus_SPI_ReceiveHardwareOverRun =
        MAKE_STATUS(kStatusGroup_LPC_SPI_SSP, 2),                   /*!< SPI receive hardware overrun occurred. */
    kStatus_SPI_Timeout = MAKE_STATUS(kStatusGroup_LPC_SPI_SSP, 3), /*!< SPI time-out occurred. */
    kStatus_SPI_BaudrateNotSupport =
        MAKE_STATUS(kStatusGroup_LPC_SPI_SSP, 4) /*!< Baudrate is not support in current clock source */
};

/*! @brief SPI interrupt sources.*/
enum _spi_interrupt_enable
{
    kSPI_RxOverRunInterruptEnable       = SPI0_IMSC_RORIM_MASK, /*!< Rx overrun interrupt */
    kSPI_RxTimeOutInterruptEnable       = SPI0_IMSC_RTIM_MASK,  /*!< Rx time-out interrupt */
    kSPI_RxFifoHalfFullInterruptEnable  = SPI0_IMSC_RXIM_MASK,  /*!< Rx FIFO half full interrupt */
    kSPI_TxFifoHalfEmptyInterruptEnable = SPI0_IMSC_TXIM_MASK,  /*!< Tx FIFO half Empty interrupt */
    kSPI_AllInterruptEnable = (SPI0_IMSC_RORIM_MASK | SPI0_IMSC_RTIM_MASK | SPI0_IMSC_RXIM_MASK | SPI0_IMSC_TXIM_MASK)
};

/*! @brief SPI status flags.*/
enum _spi_status_flags
{
    kSPI_TxFifoEmptyFlag     = SPI0_SR_TFE_MASK,           /*!< TX FIFO empty flag. */
    kSPI_TxFifoNotFullFlag   = SPI0_SR_TNF_MASK,           /*!< TX FIFO not full flag. */
    kSPI_RxFifoNotEmptyFlag  = SPI0_SR_RNE_MASK,           /*!< RX FIFO not empty flag. */
    kSPI_RxFifoFullFlag      = SPI0_SR_RFF_MASK,           /*!< RX FIFO full flag. */
    kSPI_BusyFlag            = SPI0_SR_BSY_MASK,           /*!< SPI busy flag. */
    kSPI_RxOverRunFlag       = SPI0_RIS_RORRIS_MASK << 8U, /*!< Rx overrun flag. */
    kSPI_RxTimeOutFlag       = SPI0_RIS_RTRIS_MASK << 8U,  /*!< Rx time-out flag. */
    kSPI_RxFifoHalfFullFlag  = SPI0_RIS_RXRIS_MASK << 8U,  /*!< RX FIFO at least half full flag. */
    kSPI_TxFifoHalfEmptyFlag = SPI0_RIS_TXRIS_MASK << 8U,  /*!< TX FIFO at least half empty flag. */
};

/*! @brief SPI status flags.*/
enum _spi_interrupt_status_flags
{
    kSPI_RxOverRunInterruptFlag       = SPI0_MIS_RORMIS_MASK, /*!< Rx overrun interrupt flag. */
    kSPI_RxTimeOutInterruptFlag       = SPI0_MIS_RTMIS_MASK,  /*!< Rx time-out interrupt flag. */
    kSPI_RxFifoHalfFullInterruptFlag  = SPI0_MIS_RXMIS_MASK,  /*!< RX FIFO at least half full interrupt flag. */
    kSPI_TxFifoHalfEmptyInterruptFlag = SPI0_MIS_TXMIS_MASK,  /*!< TX FIFO at least half empty interrupt flag. */
};

/*! @brief SPI transfer structure */
typedef struct _spi_transfer
{
    const uint8_t *txData; /*!< Send buffer */
    uint8_t *rxData; /*!< Receive buffer */
    size_t dataSize; /*!< Transfer bytes */
} spi_transfer_t;

/*! @brief  Master handle type */
typedef struct _spi_master_handle spi_master_handle_t;

/*! @brief  Slave handle type */
typedef spi_master_handle_t spi_slave_handle_t;

/*! @brief SPI master callback for finished transmit */
typedef void (*spi_master_callback_t)(SPI0_Type *base, spi_master_handle_t *handle, status_t status, void *userData);

/*! @brief SPI slave callback for finished transmit */
typedef void (*spi_slave_callback_t)(SPI0_Type *base, spi_slave_handle_t *handle, status_t status, void *userData);

/*! @brief SPI transfer handle structure */
struct _spi_master_handle
{
    const uint8_t *volatile txData;   /*!< Transfer buffer */
    uint8_t *volatile rxData;         /*!< Receive buffer */
    volatile size_t txRemainingBytes; /*!< Number of data to be transmitted [in bytes] */
    volatile size_t rxRemainingBytes; /*!< Number of data to be received [in bytes] */
    size_t totalByteCount;            /*!< A number of transfer bytes */
    volatile uint32_t state;          /*!< SPI internal state */
    spi_master_callback_t callback;   /*!< SPI callback */
    void *userData;                   /*!< Callback parameter */
    uint8_t dataWidth;                /*!< SPI data width. */
};

#if defined(__cplusplus)
extern "C" {
#endif
/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief  Sets the SPI master configuration structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for use in SPI_MasterInit().
 * User may use the initialized structure unchanged in SPI_MasterInit(), or modify
 * some fields of the structure before calling SPI_MasterInit(). After calling this API,
 * the master is ready to transfer.
 * Example:
   @code
   spi_master_config_t config;
   SPI_MasterGetDefaultConfig(&config);
   @endcode
 *
 * @param config pointer to master config structure
 */
void SPI_MasterGetDefaultConfig(spi_master_config_t *config);

/*!
 * @brief Initializes the SPI with master configuration.
 *
 * The configuration structure can be filled by user from scratch, or be set with default
 * values by SPI_MasterGetDefaultConfig(). After calling this API, the slave is ready to transfer.
 * Please note that: Current transfer APIs are for SPI format mode, for TI and Micro Wire mode, please
 * use low level API to adapt the real application.
 * Example
   @code
   spi_master_config_t config = {
   .baudRate_Bps = 500000,
   ...
   };
   SPI_MasterInit(SPI0, &config);
   @endcode
 *
 * @param base SPI base pointer
 * @param config pointer to master configuration structure
 * @param srcClock_Hz Source clock frequency.
 */
status_t SPI_MasterInit(SPI0_Type *base, const spi_master_config_t *config, uint32_t srcClock_Hz);

/*!
 * @brief  Sets the SPI slave configuration structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for use in SPI_SlaveInit().
 * Modify some fields of the structure before calling SPI_SlaveInit().
 * Example:
   @code
   spi_slave_config_t config;
   SPI_SlaveGetDefaultConfig(&config);
   @endcode
 *
 * @param config pointer to slave configuration structure
 */
void SPI_SlaveGetDefaultConfig(spi_slave_config_t *config);

/*!
 * @brief Initializes the SPI with slave configuration.
 *
 * The configuration structure can be filled by user from scratch or be set with
 * default values by SPI_SlaveGetDefaultConfig().
 * After calling this API, the slave is ready to transfer.
 * Example
   @code
    spi_slave_config_t config = {
    .polarity = kSPI_ClockPolarityActiveHigh;
    .phase = kSPI_ClockPhaseFirstEdge;
    ...
    };
    SPI_SlaveInit(SPI0, &config);
   @endcode
 *
 * @param base SPI base pointer
 * @param config pointer to slave configuration structure
 */
status_t SPI_SlaveInit(SPI0_Type *base, const spi_slave_config_t *config);

/*!
 * @brief De-initializes the SPI.
 *
 * Calling this API resets the SPI module, gates the SPI clock.
 *
 * The SPI module can't work unless calling the SPI_MasterInit/SPI_SlaveInit to initialize module.
 *
 * @param base SPI base pointer
 */
void SPI_Deinit(SPI0_Type *base);

/*!

 * @brief Enable or disable the SPI Master or Slave
 * @param base SPI base pointer
 * @param enable or disable ( true = enable, false = disable)
 */
static inline void SPI_Enable(SPI0_Type *base, bool enable)
{
    base->CR1 &= ~SPI0_CR1_SSE_MASK;
    base->CR1 |= SPI0_CR1_SSE(enable);
}

/*! @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the status flag.
 *
 * @param base SPI base pointer
 * @return SPI Status, use status flag to AND @ref _spi_status_flags could get the related status.
 */
static inline uint32_t SPI_GetStatusFlags(SPI0_Type *base)
{
    return ((base->RIS << 8U) | (base->SR));
}

/*!
 * @brief Gets the interrupt status flag.
 *
 * When an SPI interrupt occurs, the interrupt service routine should read this register
 * to determine the cause or causes of the interrupt.
 *
 * @param base SPI base pointer
 * @return SPI Status, use status flag to AND @ref _spi_interrupt_status_flags could get the related status.
 */
static inline uint32_t SPI_GetInterruptStatusFlags(SPI0_Type *base)
{
    return (base->MIS);
}

/*!
 * @brief Clear the interrupt status flag.
 *
 * Clear the interrupt status flags setting by hardware.Please note that: only RORIC and RTIC can
 * be cleared by software.
 *
 * @param base SPI base pointer
 * @param mask use status flag to AND @ref _spi_interrupt_status_flags could get the related status.
 */
static inline void SPI_ClearInterruptStatusFlags(SPI0_Type *base, uint32_t mask)
{
    base->ICR |= mask;
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables the interrupt for the SPI.
 *
 * @param base SPI base pointer
 * @param irqs SPI interrupt source. The parameter can be any combination of the following values:
 *        @arg kSPI_RxFifoHalfFullInterruptEnable
 *        @arg kSPI_TxFifoHalfEmptyInterruptEnable
 */
static inline void SPI_EnableInterrupts(SPI0_Type *base, uint32_t irqs)
{
    base->IMSC |= irqs;
}

/*!
 * @brief Disables the interrupt for the SPI.
 *
 * @param base SPI base pointer
 * @param irqs SPI interrupt source. The parameter can be any combination of the following values:
 *        @arg kSPI_RxFifoHalfFullInterruptEnable
 *        @arg kSPI_TxFifoHalfEmptyInterruptEnable
 */
static inline void SPI_DisableInterrupts(SPI0_Type *base, uint32_t irqs)
{
    base->ICR = (irqs & 0x00000003);
    base->IMSC &= ~(irqs & 0x0000000C);
}
/*! @} */

/*!
 * @name Bus Operations
 * @{
 */

/*!
 * @brief Sets the baud rate for SPI transfer. This is only used in master.
 *
 * @param base SPI base pointer
 * @param baudrate_Bps baud rate needed in Hz.
 * @param srcClock_Hz SPI source clock frequency in Hz.
 */
status_t SPI_MasterSetBaudRate(SPI0_Type *base, uint32_t baudrate_Bps, uint32_t srcClock_Hz);

/*!
 * @brief Writes a data into the SPI data register directly.
 *
 * @param base SPI base pointer
 * @param data needs to be write.
 */
static inline void SPI_WriteData(SPI0_Type *base, uint16_t data)
{
    base->DR = data;
}

/*!
 * @brief Gets a data from the SPI data register.
 *
 * @param base SPI base pointer
 * @return Data in the register.
 */
static inline uint16_t SPI_ReadData(SPI0_Type *base)
{
    return (base->DR);
}

/*!
 * @brief Transfers a block of data using a polling method.
 *
 * @param base SPI base pointer
 * @param xfer pointer to spi_xfer_config_t structure
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_SPI_Timeout The transfer timed out and was aborted.
 */
status_t SPI_MasterTransferBlocking(SPI0_Type *base, spi_transfer_t *xfer);
/*! @} */

#if defined(FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API) && (FSL_SDK_SPI_DRIVER_ENABLE_TRANSACTIONAL_API)
/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Initializes the SPI master handle.
 *
 * This function initializes the SPI master handle which can be used for other SPI master transactional APIs. Usually,
 * for a specified SPI instance, call this API once to get the initialized handle.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 * @param callback Callback function.
 * @param userData User data.
 */
status_t SPI_MasterTransferCreateHandle(SPI0_Type *base,
                                        spi_master_handle_t *handle,
                                        spi_master_callback_t callback,
                                        void *userData);

/*!
 * @brief Performs a non-blocking SPI interrupt transfer.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to spi_master_handle_t structure which stores the transfer state
 * @param xfer pointer to spi_xfer_config_t structure
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_MasterTransferNonBlocking(SPI0_Type *base, spi_master_handle_t *handle, spi_transfer_t *xfer);

/*!
 * @brief Gets the master transfer count.
 *
 * This function gets the master transfer count.
 *
 * @param base SPI peripheral base address.
 * @param handle Pointer to the spi_master_handle_t structure which stores the transfer state.
 * @param count The number of bytes transferred by using the non-blocking transaction.
 * @return status of status_t.
 */
status_t SPI_MasterTransferGetCount(SPI0_Type *base, spi_master_handle_t *handle, size_t *count);

/*!
 * @brief SPI master aborts a transfer using an interrupt.
 *
 * This function aborts a transfer using an interrupt.
 *
 * @param base SPI peripheral base address.
 * @param handle Pointer to the spi_master_handle_t structure which stores the transfer state.
 */
void SPI_MasterTransferAbort(SPI0_Type *base, spi_master_handle_t *handle);

/*!
 * @brief Initializes the SPI slave handle.
 *
 * This function initializes the SPI slave handle which can be used for other SPI slave transactional APIs. Usually,
 * for a specified SPI instance, call this API once to get the initialized handle.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 * @param callback Callback function.
 * @param userData User data.
 */
status_t SPI_SlaveTransferCreateHandle(SPI0_Type *base,
                                       spi_slave_handle_t *handle,
                                       spi_slave_callback_t callback,
                                       void *userData);

/*!
 * @brief Performs a non-blocking SPI slave interrupt transfer.
 *
 * @note The API returns immediately after the transfer initialization is finished.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to spi_master_handle_t structure which stores the transfer state
 * @param xfer pointer to spi_xfer_config_t structure
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_SlaveTransferNonBlocking(SPI0_Type *base, spi_slave_handle_t *handle, spi_transfer_t *xfer);

/*!
 * @brief Gets the slave transfer count.
 *
 * This function gets the slave transfer count.
 *
 * @param base SPI peripheral base address.
 * @param handle Pointer to the spi_master_handle_t structure which stores the transfer state.
 * @param count The number of bytes transferred by using the non-blocking transaction.
 * @return status of status_t.
 */
static inline status_t SPI_SlaveTransferGetCount(SPI0_Type *base, spi_slave_handle_t *handle, size_t *count)
{
    return SPI_MasterTransferGetCount(base, (spi_master_handle_t *)handle, count);
}

/*!
 * @brief SPI slave aborts a transfer using an interrupt.
 *
 * This function aborts a transfer using an interrupt.
 *
 * @param base SPI peripheral base address.
 * @param handle Pointer to the spi_slave_handle_t structure which stores the transfer state.
 */
static inline void SPI_SlaveTransferAbort(SPI0_Type *base, spi_slave_handle_t *handle)
{
    SPI_MasterTransferAbort(base, (spi_master_handle_t *)handle);
}

/*!
 * @brief Interrupts a handler for the SPI slave.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to spi_slave_handle_t structure which stores the transfer state
 */
void SPI_TransferHandleIRQ(SPI0_Type *base, spi_slave_handle_t *handle);
#endif
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_SPI_H_*/
