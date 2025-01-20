/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SPI_GPDMA_H_
#define FSL_SPI_GPDMA_H_

#include "fsl_gpdma.h"
#include "fsl_spi.h"

/*!
 * @addtogroup spi_gpdma_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief SPI GPDMA driver version 2.0.1. */
#define FSL_SPI_GPDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

typedef struct _spi_gpdma_handle spi_gpdma_handle_t;

/*! @brief SPI GPDMA callback called at the end of transfer. */
typedef void (*spi_gpdma_callback_t)(SPI_Type *base, spi_gpdma_handle_t *handle, status_t status, void *userData);

/*! @brief SPI GPDMA transfer handle, users should not touch the content of the handle.*/
struct _spi_gpdma_handle
{
    volatile bool txInProgress;    /*!< Send transfer finished */
    volatile bool rxInProgress;    /*!< Receive transfer finished */
    gpdma_handle_t *txHandle;      /*!< GPDMA handler for SPI send */
    gpdma_handle_t *rxHandle;      /*!< GPDMA handler for SPI receive */
    uint8_t bytesPerFrame;         /*!< Bytes in a frame for SPI transfer */
    spi_gpdma_callback_t callback; /*!< Callback for SPI GPDMA transfer */
    void *userData;                /*!< User Data for SPI GPDMA callback */
    uint32_t state;                /*!< Internal state of SPI GPDMA transfer */
    size_t transferSize;           /*!< Bytes need to be transfer */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name GPDMA Transactional
 * @{
 */

/*!
 * @brief Initialize the SPI master GPDMA handle.
 *
 * This function initializes the SPI master GPDMA handle which can be used for other SPI master transactional APIs.
 * Usually, for a specified SPI instance, user need only call this API once to get the initialized handle.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer.
 * @param callback User callback function called at the end of a transfer.
 * @param userData User data for callback.
 * @param txHandle GPDMA handle pointer for SPI Tx, the handle shall be static allocated by users.
 * @param rxHandle GPDMA handle pointer for SPI Rx, the handle shall be static allocated by users.
 */
status_t SPI_MasterTransferCreateHandleGPDMA(SPI_Type *base,
                                             spi_gpdma_handle_t *handle,
                                             spi_gpdma_callback_t callback,
                                             void *userData,
                                             gpdma_handle_t *txHandle,
                                             gpdma_handle_t *rxHandle);

/*!
 * @brief Perform a non-blocking SPI transfer using GPDMA.
 *
 * @note This interface returned immediately after transfer initiates, users should call
 * SPI_GetTransferStatus to poll the transfer status to check whether SPI transfer finished.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI GPDMA handle pointer.
 * @param xfer Pointer to gpdma transfer structure.
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_MasterTransferGPDMA(SPI_Type *base, spi_gpdma_handle_t *handle, spi_transfer_t *xfer);

/*!
 * @brief Abort a SPI transfer using GPDMA.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI GPDMA handle pointer.
 */
void SPI_MasterTransferAbortGPDMA(SPI_Type *base, spi_gpdma_handle_t *handle);
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_SPI_GPDMA_H_*/
