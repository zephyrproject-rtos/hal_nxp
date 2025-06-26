/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_QSCI_EDMA_H_
#define FSL_QSCI_EDMA_H_

#include "fsl_qsci.h"
#include "fsl_edma.h"

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup qsci_edma_driver QSCI_EDMA: EDMA based QSCI Driver
 * @details
 * The QSCI_EDMA module provide a method for QSCI transfer operation based on EDMA.
 *
 */

/*!
 * @addtogroup qsci_edma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief QSCI EDMA driver version. */
#define FSL_QSCI_EDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*!
 * @brief Forward declaration of the qsci edma handle typedef.
 * @anchor qsci_edma_transfer_handle_t
 */
typedef struct _qsci_edma_transfer_handle qsci_edma_transfer_handle_t;

/*!
 * @brief QSCI edma transfer callback function definition
 *
 * Defines the interface of user callback function used in QSCI edma transfer using transactional APIs. The
 * callback function shall be defined and declared in application level by user. Before starting QSCI transmiting or
 * receiving by calling @ref QSCI_TransferSendEDMA or @ref QSCI_TransferReceiveEDMA, call
 * @ref QSCI_TransferCreateHandleEDMA to install the user callback. When the transmiting or receiving ends, user
 * callback will be invoked by driver.
 *
 * @param psHandle Transfer handle that contains bus status, user data.
 */
typedef void (*qsci_edma_transfer_callback_t)(qsci_edma_transfer_handle_t *psHandle);

/*!
 * @brief QSCI edma transfer handle
 *
 * This struct address should be sizeof(edma_channel_tcd_t) aligned.
 *
 * @note If user wants to use the transactional API to transfer data in edma way, one QSCI instance should and can only
 * be allocated one handle.
 * @note The handle is maintained by QSCI driver internally, which means the transfer state is retained and user shall
 * not modify its state #u8TxState or #u8RxState in application level. If user only wish to use transactional APIs
 * without understanding its machanism, it is not necessary to understand these members.
 */
struct _qsci_edma_transfer_handle
{
    edma_channel_tcd_t sTxTcd;                /*!< TCD for EDMA TX transfer. */
    edma_channel_tcd_t sRxTcd;                /*!< TCD for EDMA RX transfer. */
    QSCI_Type *base;                          /*!< Pointer to the QSCI base that belongs to this handle. */
    qsci_edma_transfer_callback_t pfCallback; /*!< Callback function. */
    uint32_t u32RxDataSizeAll;                /*!< Size of the data to receive. */
    uint32_t u32TxDataSizeAll;                /*!< Size of the data to send out. */

    edma_handle_t sTxEdmaHandle; /*!< The eDMA TX channel used. */
    edma_handle_t sRxEdmaHandle; /*!< The eDMA RX channel used. */

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
 * @name eDMA transactional
 * @{
 */

/*!
 * @brief Initializes the QSCI edma handle.
 *
 * This function initializes the QSCI edma handle which can be used for other QSCI transactional APIs. Usually, for a
 * specified QSCI instance, call this API once to get the initialized handle.
 *
 * @param base QSCI peripheral base address.
 * @param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 * @param pfCallback Callback function.
 * @param pUserData User data.
 * @param edmaBase Edma base address.
 * @param eEdmaTxChannel eDMA channel for TX transfer.
 * @param eEdmaRxChannel eDMA channel for RX transfer.
 */
void QSCI_TransferCreateHandleEDMA(QSCI_Type *base,
                                   qsci_edma_transfer_handle_t *psHandle,
                                   qsci_edma_transfer_callback_t pfCallback,
                                   void *pUserData,
                                   DMA_Type *edmaBase,
                                   edma_channel_t eEdmaTxChannel,
                                   edma_channel_t eEdmaRxChannel);

/*!
 * @brief Initiate data transmit using EDMA.
 *
 * This function initiates a data transmit process using eDMA. This is a non-blocking function, which returns
 * right away. When all the data is sent, the send callback function is called.
 *
 * @param psHandle QSCI handle pointer.
 * @param psTransfer QSCI eDMA transfer structure. See #qsci_transfer_t.
 * @retval #kStatus_Success if succeed, others failed.
 * @retval #kStatus_QSCI_TxBusy Previous transfer on going.
 * @retval #kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferSendEDMA(qsci_edma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer);

/*!
 * @brief Initiate data receive using EDMA.
 *
 * This function initiates a data receive process using eDMA. This is a non-blocking function, which returns
 * right away. When all the data is received, the receive callback function is called.
 *
 * @param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 * @param psTransfer QSCI eDMA transfer structure, see #qsci_transfer_t.
 * @retval #kStatus_Success if succeed, others fail.
 * @retval #kStatus_QSCI_RxBusy Previous transfer ongoing.
 * @retval #kStatus_InvalidArgument Invalid argument.
 */
status_t QSCI_TransferReceiveEDMA(qsci_edma_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer);

/*!
 * @brief Aborts the data transmit process using EDMA.
 *
 * @param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 */
void QSCI_TransferAbortSendEDMA(qsci_edma_transfer_handle_t *psHandle);

/*!
 * @brief Aborts the data receive process using EDMA.
 *
 * @param psHandle Pointer to qsci_edma_transfer_handle_t structure.
 */
void QSCI_TransferAbortReceiveEDMA(qsci_edma_transfer_handle_t *psHandle);

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
status_t QSCI_TransferGetReceivedCountEDMA(qsci_edma_transfer_handle_t *psHandle, uint32_t *pu32Count);

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
status_t QSCI_TransferGetSendCountEDMA(qsci_edma_transfer_handle_t *psHandle, uint32_t *pu32Count);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_QSCI_EDMA_H_ */
