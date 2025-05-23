/*
 * Copyright 2017-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SPI_DMA_H_
#define FSL_SPI_DMA_H_

#include "fsl_dma.h"
#include "fsl_spi.h"

/*!
 * @addtogroup spi_dma_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief SPI DMA driver version 2.0.3. */
#define FSL_SPI_DMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 3))
/*! @} */

typedef struct _spi_dma_handle spi_dma_handle_t;

/*! @brief SPI DMA callback called at the end of transfer. */
typedef void (*spi_dma_callback_t)(SPI_Type *base, spi_dma_handle_t *handle, status_t status, void *userData);

/*! @brief SPI DMA transfer handle, users should not touch the content of the handle.*/
struct _spi_dma_handle
{
    volatile bool txInProgress;  /*!< Send transfer finished */
    volatile bool rxInProgress;  /*!< Receive transfer finished */
    dma_handle_t *txHandle;      /*!< DMA handler for SPI send */
    dma_handle_t *rxHandle;      /*!< DMA handler for SPI receive */
    uint8_t bytesPerFrame;       /*!< Bytes in a frame for SPI transfer */
    spi_dma_callback_t callback; /*!< Callback for SPI DMA transfer */
    void *userData;              /*!< User Data for SPI DMA callback */
    uint32_t state;              /*!< Internal state of SPI DMA transfer */
    size_t transferSize;         /*!< Bytes need to be transfer */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name DMA Transactional
 * @{
 */

/*!
 * @brief Initialize the SPI master DMA handle.
 *
 * This function initializes the SPI master DMA handle which can be used for other SPI master transactional APIs.
 * Usually, for a specified SPI instance, user need only call this API once to get the initialized handle.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 * @param callback User callback function called at the end of a transfer.
 * @param userData User data for callback.
 * @param txHandle DMA handle pointer for SPI Tx, the handle shall be static allocated by users.
 * @param rxHandle DMA handle pointer for SPI Rx, the handle shall be static allocated by users.
 */
status_t SPI_MasterTransferCreateHandleDMA(SPI_Type *base,
                                           spi_dma_handle_t *handle,
                                           spi_dma_callback_t callback,
                                           void *userData,
                                           dma_handle_t *txHandle,
                                           dma_handle_t *rxHandle);

/*!
 * @brief Perform a non-blocking SPI transfer using DMA.
 *
 * @note This interface returned immediately after transfer initiates, users should call
 * SPI_GetTransferStatus to poll the transfer status to check whether SPI transfer finished.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI DMA handle pointer.
 * @param xfer Pointer to dma transfer structure.
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_MasterTransferDMA(SPI_Type *base, spi_dma_handle_t *handle, spi_transfer_t *xfer);

/*!
 * @brief Transfers a block of data using a DMA method.
 *
 * This function using polling way to do the first half transimission and using DMA way to
 * do the srcond half transimission, the transfer mechanism is half-duplex.
 * When do the second half transimission, code will return right away. When all data is transferred,
 * the callback function is called.
 *
 * @param base SPI base pointer
 * @param handle A pointer to the spi_master_dma_handle_t structure which stores the transfer state.
 * @param transfer A pointer to the spi_half_duplex_transfer_t structure.
 * @return status of status_t.
 */
status_t SPI_MasterHalfDuplexTransferDMA(SPI_Type *base, spi_dma_handle_t *handle, spi_half_duplex_transfer_t *xfer);

/*!
 * @brief Initialize the SPI slave DMA handle.
 *
 * This function initializes the SPI slave DMA handle which can be used for other SPI master transactional APIs.
 * Usually, for a specified SPI instance, user need only call this API once to get the initialized handle.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 * @param callback User callback function called at the end of a transfer.
 * @param userData User data for callback.
 * @param txHandle DMA handle pointer for SPI Tx, the handle shall be static allocated by users.
 * @param rxHandle DMA handle pointer for SPI Rx, the handle shall be static allocated by users.
 */
static inline status_t SPI_SlaveTransferCreateHandleDMA(SPI_Type *base,
                                                        spi_dma_handle_t *handle,
                                                        spi_dma_callback_t callback,
                                                        void *userData,
                                                        dma_handle_t *txHandle,
                                                        dma_handle_t *rxHandle)
{
    return SPI_MasterTransferCreateHandleDMA(base, handle, callback, userData, txHandle, rxHandle);
}

/*!
 * @brief Perform a non-blocking SPI transfer using DMA.
 *
 * @note This interface returned immediately after transfer initiates, users should call
 * SPI_GetTransferStatus to poll the transfer status to check whether SPI transfer finished.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI DMA handle pointer.
 * @param xfer Pointer to dma transfer structure.
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
static inline status_t SPI_SlaveTransferDMA(SPI_Type *base, spi_dma_handle_t *handle, spi_transfer_t *xfer)
{
    return SPI_MasterTransferDMA(base, handle, xfer);
}

/*!
 * @brief Abort a SPI transfer using DMA.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI DMA handle pointer.
 */
void SPI_MasterTransferAbortDMA(SPI_Type *base, spi_dma_handle_t *handle);

/*!
 * @brief Gets the master DMA transfer remaining bytes.
 *
 * This function gets the master DMA transfer remaining bytes.
 *
 * @param base SPI peripheral base address.
 * @param handle A pointer to the spi_dma_handle_t structure which stores the transfer state.
 * @param count A number of bytes transferred by the non-blocking transaction.
 * @return status of status_t.
 */
status_t SPI_MasterTransferGetCountDMA(SPI_Type *base, spi_dma_handle_t *handle, size_t *count);

/*!
 * @brief Abort a SPI transfer using DMA.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI DMA handle pointer.
 */
static inline void SPI_SlaveTransferAbortDMA(SPI_Type *base, spi_dma_handle_t *handle)
{
    SPI_MasterTransferAbortDMA(base, handle);
}

/*!
 * @brief Gets the slave DMA transfer remaining bytes.
 *
 * This function gets the slave DMA transfer remaining bytes.
 *
 * @param base SPI peripheral base address.
 * @param handle A pointer to the spi_dma_handle_t structure which stores the transfer state.
 * @param count A number of bytes transferred by the non-blocking transaction.
 * @return status of status_t.
 */
static inline status_t SPI_SlaveTransferGetCountDMA(SPI_Type *base, spi_dma_handle_t *handle, size_t *count)
{
    return SPI_MasterTransferGetCountDMA(base, handle, count);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_SPI_DMA_H_*/
