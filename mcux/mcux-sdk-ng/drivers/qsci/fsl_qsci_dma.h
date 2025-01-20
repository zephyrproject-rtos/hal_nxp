/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_QSCI_DMA_H_
#define FSL_QSCI_DMA_H_

#include "fsl_qsci.h"
#include "fsl_dma.h"

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup qsci_dma_driver QSCI_DMA: DMA based QSCI Driver
 * @details
 * The QSCI_DMA module provide a method for QSCI transfer operation based on DMA.
 *
 */

/*!
 * @addtogroup qsci_dma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief QSCI DMA driver version. */
#define FSL_QSCI_DMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*!
 * @brief Forward declaration of the qsci dma handle typedef.
 * @anchor qsci_dma_transfer_handle_t
 */
typedef struct _qsci_dma_transfer_handle qsci_dma_transfer_handle_t;
/*!
 * @brief QSCI dma transfer callback function definition
 *
 * Defines the interface of user callback function used in QSCI dma transfer using transactional APIs. The
 * callback function shall be defined and declared in application level by user. Before starting QSCI transmiting or
 * receiving by calling @ref QSCI_TransferSendDMA or @ref QSCI_TransferReceiveDMA, call
 * @ref QSCI_TransferCreateHandleDMA to install the user callback. When the transmiting or receiving ends, user
 * callback will be invoked by driver.
 *
 * @param psHandle Transfer handle that contains bus status, user data.
 */
typedef void (*qsci_dma_transfer_callback_t)(qsci_dma_transfer_handle_t *psHandle);

/*!
 * @brief QSCI dma transfer handle
 *
 * This struct address should be sizeof(dma_channel_tcd_t) aligned.
 *
 * @note If user wants to use the transactional API to transfer data in dma way, one QSCI instance should and can only
 * be allocated one handle.
 * @note The handle is maintained by QSCI driver internally, which means the transfer state is retained and user shall
 * not modify its state #u8TxState or #u8RxState in application level. If user only wish to use transactional APIs
 * without understanding its machanism, it is not necessary to understand these members.
 */
struct _qsci_dma_transfer_handle
{
    QSCI_Type *base;                         /*!< Pointer to the QSCI base that belongs to this handle. */
    qsci_dma_transfer_callback_t pfCallback; /*!< Callback function. */
    uint32_t u32RxDataSizeAll;               /*!< Size of the data to receive. */
    uint32_t u32TxDataSizeAll;               /*!< Size of the data to send out. */

    dma_handle_t sTxDmaHandle; /*!< The DMA TX channel used. */
    dma_handle_t sRxDmaHandle; /*!< The DMA RX channel used. */

    volatile uint8_t u8TxState; /*!< TX transfer state. */
    volatile uint8_t u8RxState; /*!< RX transfer state */

    status_t busStatus; /*!< QSCI bus status. */
    void *pUserData;    /*!< User configurable pointer to any data, function, structure etc that user wish to use in the
                        callback */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name DMA transactional
 * @{
 */

/*!
 * @brief Initializes the QSCI dma handle.
 *
 * This function initializes the QSCI dma handle which can be used for other QSCI transactional APIs. Usually, for a
 * specified QSCI instance, call this API once to get the initialized handle.
 *
 * @param base QSCI peripheral base address.
 * @param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 * @param pfCallback Callback function.
 * @param pUserData User data.
 * @param dmaBase DMA base address.
 * @param dmaTxChannel DMA channel for TX transfer.
 * @param dmaRxChannel DMA channel for RX transfer.
 */
void QSCI_TransferCreateHandleDMA(QSCI_Type *base,
                                  qsci_dma_transfer_handle_t *psHandle,
                                  qsci_dma_transfer_callback_t pfCallback,
                                  void *pUserData,
                                  DMA_Type *dmaBase,
                                  dma_channel_t dmaTxChannel,
                                  dma_channel_t dmaRxChannel);

/*!
 * @brief Initiate data transmit using DMA.
 *
 * This function initiates a data transmit process using DMA. This is a non-blocking function, which returns
 * right away. When all the data is sent, the send callback function is called.
 *
 * @param psHandle QSCI handle pointer.
 * @param psTransfer QSCI DMA transfer structure. See #qsci_transfer_t.
 * @retval #kStatus_Success if succeed, others failed.
 * @retval #kStatus_QSCI_TxBusy Previous transfer on going.
 * @retval #kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferSendDMA(qsci_dma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer);

/*!
 * @brief Initiate data receive using DMA.
 *
 * This function initiates a data receive process using DMA. This is a non-blocking function, which returns
 * right away. When all the data is received, the receive callback function is called.
 *
 * @param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 * @param psTransfer QSCI DMA transfer structure, see #qsci_transfer_t.
 * @retval #kStatus_Success if succeed, others fail.
 * @retval #kStatus_QSCI_RxBusy Previous transfer ongoing.
 * @retval #kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferReceiveDMA(qsci_dma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer);

/*!
 * @brief Aborts the data transmit process using DMA.
 *
 * @param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 */
void QSCI_TransferAbortSendDMA(qsci_dma_transfer_handle_t *psHandle);

/*!
 * @brief Aborts the data receive process using DMA.
 *
 * @param psHandle Pointer to qsci_dma_transfer_handle_t structure.
 */
void QSCI_TransferAbortReceiveDMA(qsci_dma_transfer_handle_t *psHandle);

/*!
 * @brief Gets the number of received bytes.
 *
 * This function gets the number of received bytes.
 *
 * @param psHandle QSCI handle pointer.
 * @param pu32Count Receive bytes count.
 * @retval #kStatus_NoTransferInProgress No receive in progress.
 * @retval #kStatus_Success Get successfully through the parameter \p count;
 */
status_t QSCI_TransferGetReceivedCountDMA(qsci_dma_transfer_handle_t *psHandle, uint32_t *pu32Count);

/*!
 * @brief Gets the number of bytes written to the QSCI TX register.
 *
 * This function gets the number of bytes written to the QSCI TX
 * register by DMA.
 *
 * @param psHandle QSCI handle pointer.
 * @param pu32Count Send bytes count.
 * @retval #kStatus_NoTransferInProgress No send in progress.
 * @retval #kStatus_Success Get successfully through the parameter \p count;
 */
status_t QSCI_TransferGetSendCountDMA(qsci_dma_transfer_handle_t *psHandle, uint32_t *pu32Count);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_QSCI_DMA_H_ */
