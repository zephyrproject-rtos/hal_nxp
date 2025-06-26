/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_LPSCI_DMA_H_
#define FSL_LPSCI_DMA_H_

#include "fsl_lpsci.h"
#include "fsl_dma.h"

/*!
 * @addtogroup lpsci_dma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief LPSCI DMA driver version. */
#define FSL_LPSCI_DMA_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @{ */

/* Forward declaration of the handle typedef. */
typedef struct _lpsci_dma_handle lpsci_dma_handle_t;

/*! @brief LPSCI transfer callback function. */
typedef void (*lpsci_dma_transfer_callback_t)(UART0_Type *base,
                                              lpsci_dma_handle_t *handle,
                                              status_t status,
                                              void *userData);

/*!
 * @brief LPSCI DMA handle
 */
struct _lpsci_dma_handle
{
    UART0_Type *base; /*!< LPSCI peripheral base address. */

    lpsci_dma_transfer_callback_t callback; /*!< Callback function. */
    void *userData;                         /*!< UART callback function parameter.*/
    size_t rxDataSizeAll;                   /*!< Size of the data to receive. */
    size_t txDataSizeAll;                   /*!< Size of the data to send out. */

    dma_handle_t *txDmaHandle; /*!< The DMA TX channel used. */
    dma_handle_t *rxDmaHandle; /*!< The DMA RX channel used. */

    volatile uint8_t txState; /*!< TX transfer state. */
    volatile uint8_t rxState; /*!< RX transfer state */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name eDMA transactional
 * @{
 */

/*!
 * @brief Initializes the LPSCI handle which is used in transactional functions.
 * @param handle Pointer to lpsci_dma_handle_t structure
 * @param base LPSCI peripheral base address
 * @param rxDmaHandle User requested DMA handle for RX DMA transfer
 * @param txDmaHandle User requested DMA handle for TX DMA transfer
 */
void LPSCI_TransferCreateHandleDMA(UART0_Type *base,
                                   lpsci_dma_handle_t *handle,
                                   lpsci_dma_transfer_callback_t callback,
                                   void *userData,
                                   dma_handle_t *txDmaHandle,
                                   dma_handle_t *rxDmaHandle);

/*!
 * @brief Sends data using DMA.
 *
 * This function sends data using DMA. This is a non-blocking function, which returns
 * immediately. When all data is sent, the send callback function is called.
 *
 * @param handle LPSCI handle pointer.
 * @param xfer LPSCI DMA transfer structure, see #lpsci_transfer_t.
 * @retval kStatus_Success if successful, others failed.
 * @retval kStatus_LPSCI_TxBusy Previous transfer on going.
 * @retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPSCI_TransferSendDMA(UART0_Type *base, lpsci_dma_handle_t *handle, lpsci_transfer_t *xfer);

/*!
 * @brief Receives data using DMA.
 *
 * This function receives data using DMA. This is a non-blocking function, which returns
 * immediately. When all data is received, the receive callback function is called.
 *
 * @param handle Pointer to lpsci_dma_handle_t structure
 * @param xfer LPSCI DMA transfer structure, see #lpsci_transfer_t.
 * @retval kStatus_Success if successful, others failed.
 * @retval kStatus_LPSCI_RxBusy Previous transfer on going.
 * @retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPSCI_TransferReceiveDMA(UART0_Type *base, lpsci_dma_handle_t *handle, lpsci_transfer_t *xfer);

/*!
 * @brief Aborts the sent data using DMA.
 *
 * This function aborts the sent data using DMA.
 *
 * @param handle Pointer to lpsci_dma_handle_t structure.
 */
void LPSCI_TransferAbortSendDMA(UART0_Type *base, lpsci_dma_handle_t *handle);

/*!
 * @brief Aborts the receive data using DMA.
 *
 * This function aborts the receive data using DMA.
 *
 * @param handle Pointer to lpsci_dma_handle_t structure.
 */
void LPSCI_TransferAbortReceiveDMA(UART0_Type *base, lpsci_dma_handle_t *handle);

/*!
 * @brief Gets the number of bytes written to the LPSCI TX register.
 *
 * This function gets the number of bytes that have been written to the LPSCI TX
 * register by DMA.
 *
 * @param base LPSCI peripheral base address.
 * @param handle LPSCI handle pointer.
 * @param count Send bytes count.
 * @retval kStatus_NoTransferInProgress No send in progress.
 * @retval kStatus_InvalidArgument Parameter is invalid.
 * @retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPSCI_TransferGetSendCountDMA(UART0_Type *base, lpsci_dma_handle_t *handle, uint32_t *count);

/*!
 * @brief Gets the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * @param base LPSCI peripheral base address.
 * @param handle LPSCI handle pointer.
 * @param count Receive bytes count.
 * @retval kStatus_NoTransferInProgress No receive in progress.
 * @retval kStatus_InvalidArgument Parameter is invalid.
 * @retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPSCI_TransferGetReceiveCountDMA(UART0_Type *base, lpsci_dma_handle_t *handle, uint32_t *count);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_LPSCI_DMA_H_ */
