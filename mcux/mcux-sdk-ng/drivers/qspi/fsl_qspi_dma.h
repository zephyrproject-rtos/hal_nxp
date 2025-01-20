/*
 * Copyright 2018 - 2020, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_QSPI_DMA_H_
#define FSL_QSPI_DMA_H_

#include "fsl_qspi.h"
#include "fsl_dma.h"

/*!
 * @addtogroup qspi_dma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief QSPI DMA driver version 2.2.2. */
#define FSL_QSPI_DMA_DRIVER_VERSION (MAKE_VERSION(2, 2, 2))
/*! @} */

typedef struct _qspi_dma_handle qspi_dma_handle_t;

/*! @brief QSPI DMA transfer callback function for finish and error */
typedef void (*qspi_dma_callback_t)(QuadSPI_Type *base, qspi_dma_handle_t *handle, status_t status, void *userData);

/*! @brief QSPI DMA transfer handle, users should not touch the content of the handle.*/
struct _qspi_dma_handle
{
    dma_handle_t *dmaHandle;      /*!< DMA handler start pointer for QSPI send */
    size_t transferSize;          /*!< Bytes need to transfer. */
    uint32_t state;               /*!< Internal state for QSPI DMA transfer */
    qspi_dma_callback_t callback; /*!< Callback for users while transfer finish or error occurred */
    void *userData;               /*!< User callback parameter */
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
 * @brief Initializes the QSPI handle for send which is used in transactional functions and set the callback.
 *
 * @param base QSPI peripheral base address
 * @param handle Pointer to qspi_dma_handle_t structure
 * @param callback QSPI callback, NULL means no callback.
 * @param userData User callback function data.
 * @param dmaHandle User requested DMA handle start pointer for DMA transfer
 */
void QSPI_TransferTxCreateHandleDMA(QuadSPI_Type *base,
                                    qspi_dma_handle_t *handle,
                                    qspi_dma_callback_t callback,
                                    void *userData,
                                    dma_handle_t *dmaHandle);

/*!
 * @brief Transfers QSPI data using an DMA non-blocking method.
 *
 * This function writes data to the QSPI transmit FIFO. This function is non-blocking.
 * @param base Pointer to QuadSPI Type.
 * @param handle Pointer to qspi_dma_handle_t structure
 * @param xfer QSPI transfer structure.
 */
status_t QSPI_TransferSendDMA(QuadSPI_Type *base, qspi_dma_handle_t *handle, qspi_transfer_t *xfer);

/*!
 * @brief Aborts the sent data using DMA.
 *
 * This function aborts the sent data using DMA.
 *
 * @param base QSPI peripheral base address.
 * @param handle Pointer to qspi_dma_handle_t structure
 */
void QSPI_TransferAbortSendDMA(QuadSPI_Type *base, qspi_dma_handle_t *handle);

/*!
 * @brief Gets the transferred counts of send.
 *
 * @param base Pointer to QuadSPI Type.
 * @param handle Pointer to qspi_dma_handle_t structure.
 * @param count Bytes sent.
 * @retval kStatus_Success Succeed get the transfer count.
 * @retval kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t QSPI_TransferGetSendCountDMA(QuadSPI_Type *base, qspi_dma_handle_t *handle, size_t *count);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_QSPI_DMA_H_ */
