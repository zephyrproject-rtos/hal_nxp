/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020, 2022-2023, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_FLEXIO_QSPI_H_
#define _FSL_FLEXIO_QSPI_H_

#include "fsl_common.h"
#include "fsl_flexio.h"
#include "fsl_flexio_spi.h"

/*!
 * @addtogroup flexio_spi
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief FlexIO SPI driver version. */
#define FSL_FLEXIO_QSPI_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*@}*/

#define FLEXIO_QSPI_BUF_MAX 3

/*! @brief FLEXIO QSPI transfer state, which is used for QSPI transactiaonl APIs' internal state. */
enum _flexio_qspi_transfer_states
{
    kFLEXIO_QSPI_Idle = 0x0U, /*!< Nothing in the transmitter/receiver's queue. */
    kFLEXIO_QSPI_Busy,        /*!< Transmiter/Receive's queue is not finished. */
};

enum _flexio_qspi_shiftbuf
{
    kFLEXIO_QSPI_SHIFTBUF0 = 0
};

enum _flexio_qspi_timer
{
    kFLEXIO_QSPI_TIMER0 = 0,
    kFLEXIO_QSPI_TIMER1
};

/*! @brief Define FlexIO QSPI DMA mask. */
enum _flexio_qspi_dma_enable
{
    kFLEXIO_QSPI_TxDmaEnable  = 0x1U, /*!< Tx DMA request source */
    kFLEXIO_QSPI_RxDmaEnable  = 0x2U, /*!< Rx DMA request source */
    kFLEXIO_QSPI_DmaAllEnable = 0x3U, /*!< All DMA request source*/
};

/*! @brief Define FlexIO SPI access structure typedef. */
typedef struct _flexio_qspi_type
{
    FLEXIO_Type *flexioBase; /*!< FlexIO base pointer. */
    uint8_t SDOPinIndex;     /*!< Pin select for data output. To set SDO pin in Hi-Z state, user needs to mux the pin as
                                GPIO input and disable all pull up/down in application. */
    uint8_t SCKPinIndex;     /*!< Pin select for clock. */
    uint8_t CSnPinIndex;     /*!< Pin select for enable. */
} FLEXIO_QSPI_Type;

/*! @brief Define FlexIO SPI transfer structure. */
typedef struct _flexio_qspi_buf
{
    uint8_t *txData; /*!< Send buffer. */
    size_t dataSize; /*!< Transfer bytes. */
} flexio_qspi_buf_t;

/*! @brief Define FlexIO SPI transfer structure. */
typedef struct _flexio_qspi_transfer
{
    flexio_qspi_buf_t bufs[FLEXIO_QSPI_BUF_MAX];
    uint8_t flags;   /*!< FlexIO SPI control flag, MSB first  or LSB first. */
} flexio_qspi_transfer_t;

/*! @brief  typedef for flexio_qspi_master_handle_t in advance. */
typedef struct _flexio_qspi_master_handle flexio_qspi_master_handle_t;

/*! @brief FlexIO SPI master callback for finished transmit */
typedef void (*flexio_qspi_master_transfer_callback_t)(FLEXIO_QSPI_Type *base,
                                                      flexio_qspi_master_handle_t *handle,
                                                      status_t status,
                                                      void *userData);

/*! @brief Define FlexIO SPI handle structure. */
struct _flexio_qspi_master_handle
{
    flexio_qspi_buf_t bufs[FLEXIO_QSPI_BUF_MAX];
    volatile uint32_t current_buffer;
    uint8_t *txData;                                /*!< Transfer buffer. */
    size_t transferSize;                            /*!< Total bytes to be transferred. */
    volatile size_t txRemainingBytes;               /*!< Send data remaining in bytes. */
    volatile uint32_t state;                        /*!< FlexIO SPI internal state. */
    flexio_qspi_master_transfer_callback_t callback; /*!< FlexIO SPI callback. */
    void *userData;                                 /*!< Callback parameter. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

/*!
 * @name FlexIO SPI Configuration
 * @{
 */

/*!
 * @brief Ungates the FlexIO clock, resets the FlexIO module, configures the FlexIO SPI master hardware,
 * and configures the FlexIO SPI with FlexIO SPI master configuration. The
 * configuration structure can be filled by the user, or be set with default values
 * by the FLEXIO_QSPI_MasterGetDefaultConfig().
 *
 * @note 1.FlexIO SPI master only support CPOL = 0, which means clock inactive low.
 *      2.For FlexIO SPI master, the input valid time is 1.5 clock cycles, for slave the output valid time
 *        is 2.5 clock cycles. So if FlexIO SPI master communicates with other spi IPs, the maximum baud
 *        rate is FlexIO clock frequency divided by 2*2=4. If FlexIO SPI master communicates with FlexIO
 *        SPI slave, the maximum baud rate is FlexIO clock frequency divided by (1.5+2.5)*2=8.
 *
 * Example
   @code
   FLEXIO_QSPI_Type spiDev = {
   .flexioBase = FLEXIO,
   .SDOPinIndex = 0,
   .SDIPinIndex = 1,
   .SCKPinIndex = 2,
   .CSnPinIndex = 3,
   };
   flexio_spi_master_config_t config = {
   .enableMaster = true,
   .enableInDoze = false,
   .enableInDebug = true,
   .enableFastAccess = false,
   .baudRate_Bps = 500000,
   .phase = kFLEXIO_SPI_ClockPhaseFirstEdge,
   .dataMode = kFLEXIO_SPI_8BitMode
   };
   FLEXIO_QSPI_MasterInit(&spiDev, &config, srcClock_Hz);
   @endcode
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param masterConfig Pointer to the flexio_spi_master_config_t structure.
 * @param srcClock_Hz FlexIO source clock in Hz.
*/
void FLEXIO_QSPI_MasterInit(FLEXIO_QSPI_Type *base, flexio_spi_master_config_t *masterConfig, uint32_t srcClock_Hz);

/*!
 * @brief Gets the default configuration to configure the FlexIO SPI master. The configuration
 * can be used directly by calling the FLEXIO_QSPI_MasterConfigure().
 * Example:
   @code
   flexio_spi_master_config_t masterConfig;
   FLEXIO_QSPI_MasterGetDefaultConfig(&masterConfig);
   @endcode
 * @param masterConfig Pointer to the flexio_spi_master_config_t structure.
*/
void FLEXIO_QSPI_MasterGetDefaultConfig(flexio_spi_master_config_t *masterConfig);


/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets FlexIO SPI status flags.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @return status flag; Use the status flag to AND the following flag mask and get the status.
 *          @arg kFLEXIO_SPI_TxEmptyFlag
 *          @arg kFLEXIO_SPI_RxEmptyFlag
 */

uint32_t FLEXIO_QSPI_GetStatusFlags(FLEXIO_QSPI_Type *base);

/*!
 * @brief Clears FlexIO SPI status flags.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param mask status flag
 *      The parameter can be any combination of the following values:
 *          @arg kFLEXIO_SPI_TxEmptyFlag
 *          @arg kFLEXIO_SPI_RxEmptyFlag
 */

void FLEXIO_QSPI_ClearStatusFlags(FLEXIO_QSPI_Type *base, uint32_t mask);

/*@}*/

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables the FlexIO SPI interrupt.
 *
 * This function enables the FlexIO SPI interrupt.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param mask interrupt source. The parameter can be any combination of the following values:
 *        @arg kFLEXIO_SPI_RxFullInterruptEnable
 *        @arg kFLEXIO_SPI_TxEmptyInterruptEnable
 */
void FLEXIO_QSPI_EnableInterrupts(FLEXIO_QSPI_Type *base, uint32_t mask);

/*!
 * @brief Disables the FlexIO SPI interrupt.
 *
 * This function disables the FlexIO SPI interrupt.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param mask interrupt source The parameter can be any combination of the following values:
 *        @arg kFLEXIO_SPI_RxFullInterruptEnable
 *        @arg kFLEXIO_SPI_TxEmptyInterruptEnable
 */
void FLEXIO_QSPI_DisableInterrupts(FLEXIO_QSPI_Type *base, uint32_t mask);

/*@}*/

/*!
 * @name Bus Operations
 * @{
 */

/*!
 * @brief Enables/disables the FlexIO SPI module operation.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type.
 * @param enable True to enable, false does not have any effect.
 */
static inline void FLEXIO_QSPI_Enable(FLEXIO_QSPI_Type *base, bool enable)
{
    if (enable)
    {
        base->flexioBase->CTRL |= FLEXIO_CTRL_FLEXEN_MASK;
    }
}

static inline uint32_t FLEXIO_QSPI_GetInstance(FLEXIO_QSPI_Type *base)
{
    return FLEXIO_GetInstance(base->flexioBase);
}

/*!
 * @brief Sets baud rate for the FlexIO SPI transfer, which is only used for the master.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param baudRate_Bps Baud Rate needed in Hz.
 * @param srcClockHz SPI source clock frequency in Hz.
 */
void FLEXIO_QSPI_MasterSetBaudRate(FLEXIO_QSPI_Type *base, uint32_t baudRate_Bps, uint32_t srcClockHz);

/*!
 * @brief Writes one byte of data, which is sent using the MSB method.
 *
 * @note This is a non-blocking API, which returns directly after the data is put into the
 * data register but the data transfer is not finished on the bus. Ensure that
 * the TxEmptyFlag is asserted before calling this API.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param data 8/16/32 bit data.
 */
static inline void FLEXIO_QSPI_WriteData(FLEXIO_QSPI_Type *base, uint32_t data)
{
    base->flexioBase->SHIFTBUFNBS[kFLEXIO_QSPI_SHIFTBUF0] = data;
}

/*!
 * @brief Flush tx/rx shifters.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 */
void FLEXIO_QSPI_FlushShifters(FLEXIO_QSPI_Type *base);
/*@}*/

/*Transactional APIs*/

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Initializes the FlexIO SPI Master handle, which is used in transactional functions.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param handle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 * @param callback The callback function.
 * @param userData The parameter of the callback function.
 * @retval kStatus_Success Successfully create the handle.
 * @retval kStatus_OutOfRange The FlexIO type/handle/ISR table out of range.
 */
status_t FLEXIO_QSPI_MasterTransferCreateHandle(FLEXIO_QSPI_Type *base,
                                               flexio_qspi_master_handle_t *handle,
                                               flexio_qspi_master_transfer_callback_t callback,
                                               void *userData);

/*!
 * @brief Master transfer data using IRQ.
 *
 * This function sends data using IRQ. This is a non-blocking function, which returns
 * right away. When all data is sent out/received, the callback function is called.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param handle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 * @param xfer FlexIO SPI transfer structure. See #flexio_qspi_transfer_t.
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_FLEXIO_QSPI_Busy SPI is not idle, is running another transfer.
 */
status_t FLEXIO_QSPI_MasterTransferNonBlocking(FLEXIO_QSPI_Type *base,
                                              flexio_qspi_master_handle_t *handle,
                                              flexio_qspi_transfer_t *xfer);

/*!
 * @brief Aborts the master data transfer, which used IRQ.
 *
 * @param base Pointer to the FLEXIO_QSPI_Type structure.
 * @param handle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 */
void FLEXIO_QSPI_MasterTransferAbort(FLEXIO_QSPI_Type *base, flexio_qspi_master_handle_t *handle);

/*!
 * @brief FlexIO SPI master IRQ handler function.
 *
 * @param spiType Pointer to the FLEXIO_QSPI_Type structure.
 * @param spiHandle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 */
void FLEXIO_QSPI_MasterTransferHandleIRQ(void *spiType, void *spiHandle);

/*!
 * @brief Enables/disables the FlexIO QSPI transmit DMA. This function enables/disables the FlexIOQ SPI Tx DMA,
 * which means that asserting the kFLEXIO_SPI_TxEmptyFlag does/doesn't trigger the DMA request.
 *
 * @param base Pointer to the FLEXIO_SPI_Type structure.
 * @param mask SPI DMA source.
 * @param enable True means enable DMA, false means disable DMA.
 */
void FLEXIO_QSPI_EnableDMA(FLEXIO_QSPI_Type *base, uint32_t mask, bool enable);

/*@}*/

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/*@}*/

#endif /*_FSL_FLEXIO_QSPI_H_*/
