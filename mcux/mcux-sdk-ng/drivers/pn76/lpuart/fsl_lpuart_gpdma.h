/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_LPUART_GPDMA_H_
#define FSL_LPUART_GPDMA_H_

#include "fsl_lpuart.h"
#include "fsl_gpdma.h"

/*!
 * @addtogroup lpuart_gpdma
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief LPUART GPDMA driver version. */
#define FSL_LPUART_GPDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/* Forward declaration of the handle typedef. */
typedef struct _lpuart_gpdma_handle lpuart_gpdma_handle_t;

/*! @brief LPUART transfer callback function. */
typedef void (*lpuart_gpdma_transfer_callback_t)(LPUART_Type *base,
                                                 lpuart_gpdma_handle_t *handle,
                                                 status_t status,
                                                 void *userData);

/*!
 * @brief LPUART GPDMA handle
 */
struct _lpuart_gpdma_handle
{
    lpuart_gpdma_transfer_callback_t callback; /*!< Callback function. */
    void *userData;                            /*!< LPUART callback function parameter.*/
    size_t rxDataSizeAll;                      /*!< Size of the data to receive. */
    size_t txDataSizeAll;                      /*!< Size of the data to send out. */

    gpdma_handle_t *txDmaHandle; /*!< The GPDMA TX channel used. */
    gpdma_handle_t *rxDmaHandle; /*!< The GPDMA RX channel used. */

    volatile uint8_t txState; /*!< TX transfer state. */
    volatile uint8_t rxState; /*!< RX transfer state */
};

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name GPDMA transactional
 * @{
 */

/*!
 * @brief Initializes the LPUART handle which is used in transactional functions.
 *
 * @note This function disables all LPUART interrupts.
 *
 * @param base LPUART peripheral base address.
 * @param handle Pointer to lpuart_gpdma_handle_t structure.
 * @param callback Callback function.
 * @param userData User data.
 * @param txDmaHandle User-requested GPDMA handle for TX GPDMA transfer.
 * @param rxDmaHandle User-requested GPDMA handle for RX GPDMA transfer.
 */
void LPUART_TransferCreateHandleGPDMA(LPUART_Type *base,
                                      lpuart_gpdma_handle_t *handle,
                                      lpuart_gpdma_transfer_callback_t callback,
                                      void *userData,
                                      gpdma_handle_t *txDmaHandle,
                                      gpdma_handle_t *rxDmaHandle);

/*!
 * @brief Sends data using GPDMA.
 *
 * This function sends data using GPDMA. This is a non-blocking function, which returns
 * right away. When all data is sent, the send callback function is called.
 *
 * @param base LPUART peripheral base address.
 * @param handle LPUART handle pointer.
 * @param xfer LPUART GPDMA transfer structure.
 * @retval kStatus_Success if succeed, others failed.
 * @retval kStatus_LPUART_TxBusy Previous transfer on going.
 * @retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPUART_TransferSendGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle, lpuart_data_t *xfer);

/*!
 * @brief Receives data using GPDMA.
 *
 * This function receives data using GPDMA. This is a non-blocking function, which returns
 * right away. When all data is received, the receive callback function is called.
 *
 * @param base LPUART peripheral base address.
 * @param handle Pointer to lpuart_gpdma_handle_t structure.
 * @param xfer LPUART GPDMA transfer structure.
 * @retval kStatus_Success if succeed, others failed.
 * @retval kStatus_LPUART_RxBusy Previous transfer on going.
 * @retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPUART_TransferReceiveGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle, lpuart_data_t *xfer);

/*!
 * @brief Aborts the sent data using GPDMA.
 *
 * This function aborts send data using GPDMA.
 *
 * @param base LPUART peripheral base address
 * @param handle Pointer to lpuart_gpdma_handle_t structure
 */
void LPUART_TransferAbortSendGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle);

/*!
 * @brief Aborts the received data using GPDMA.
 *
 * This function aborts the received data using GPDMA.
 *
 * @param base LPUART peripheral base address
 * @param handle Pointer to lpuart_gpdma_handle_t structure
 */
void LPUART_TransferAbortReceiveGPDMA(LPUART_Type *base, lpuart_gpdma_handle_t *handle);
/*! @}*/
#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_LPUART_H_ */
