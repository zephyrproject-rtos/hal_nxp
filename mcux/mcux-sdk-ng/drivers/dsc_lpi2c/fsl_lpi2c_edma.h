/*
 * Copyright 2020,2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_LPI2C_EDMA_H_
#define FSL_LPI2C_EDMA_H_

#include "fsl_lpi2c.h"
#include "fsl_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup lpi2c_edma_driver LPI2C_EDMA: EDMA based LPI2C Driver
 * @details
 * The LPI2C_EDMA module provide a method for LPI2C transfer operation based on EDMA.
 *
 */

/*!
 * @addtogroup lpi2c_edma_driver
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief LPI2C EDMA driver version. */
#define FSL_LPI2C_EDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*! @} */

/* Forward declaration of the transfer descriptor and handle typedefs. */
typedef struct _lpi2c_master_edma_transfer_handle lpi2c_master_edma_transfer_handle_t;

/*!
 * @brief Master DMA completion callback function pointer type.
 *
 * This callback is used only for the non-blocking master transfer API. Specify the callback you wish to use
 * in the call to LPI2C_MasterCreateEDMAHandle().
 *
 * @param psHandle Handle associated with the completed transfer.
 */
typedef void (*lpi2c_master_edma_transfer_callback_t)(lpi2c_master_edma_transfer_handle_t *psHandle);

/*!
 * @brief Driver handle for master DMA APIs.
 * @note The contents of this structure are private and subject to change.
 * This struct address should be sizeof(edma_channel_tcd_t) aligned.
 */
struct _lpi2c_master_edma_transfer_handle
{
    edma_channel_tcd_t sRxTcd[1];                     /*!< TCD for RX EDMA transfer. */
    edma_channel_tcd_t sTxTcd[3];                     /*!< TCD for TX EDMA transfer. */
    LPI2C_Type *base;                                 /*!< LPI2C base pointer. */
    bool bIsBusy;                                     /*!< Transfer state machine current state. */
    uint8_t u8Nbytes;                                 /*!< eDMA minor byte transfer count initially configured. */
    uint16_t u16CommandBuffer[7];                     /*!< LPI2C command sequence. */
    lpi2c_master_transfer_t sTransfer;                /*!< Copy of the current transfer info. */
    lpi2c_master_edma_transfer_callback_t pfCallback; /*!< Callback function pointer. */
    status_t completionStatus;  /*!< Either #kStatus_Success or an error code describing how the transfer completed. */
    void *pUserData;            /*!< Application data passed to callback. */
    edma_handle_t sRxDmaHandle; /*!< Handle for receive DMA channel. */
    edma_handle_t sTxDmaHandle; /*!< Handle for transmit DMA channel. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*! @name Master DMA */
/*! @{ */

/*!
 * @brief Create a new handle for the LPI2C master DMA APIs.
 *
 * The creation of a handle is for use with the DMA APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the LPI2C_MasterTransferAbortEDMA() API shall be called.
 *
 * For devices where the LPI2C send and receive DMA requests are OR'd together, the @a txDmaHandle
 * parameter is ignored and may be set to NULL.
 *
 * @param base The LPI2C peripheral base address.
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @param pfcallback User provided pointer to the asynchronous callback function.
 * @param pUserData User provided pointer to the application callback data.
 * @param edmaBase Edma base address.
 * @param eEdmaTxChannel eDMA channel for master transfer Tx request.
 * @param eEdmaRxChannel eDMA channel for master transfer Rx request.
 */
void LPI2C_MasterCreateEDMAHandle(LPI2C_Type *base,
                                  lpi2c_master_edma_transfer_handle_t *psHandle,
                                  lpi2c_master_edma_transfer_callback_t pfcallback,
                                  void *pUserData,
                                  DMA_Type *edmaBase,
                                  edma_channel_t eEdmaTxChannel,
                                  edma_channel_t eEdmaRxChannel);

/*!
 * @brief Performs a non-blocking DMA-based transaction on the I2C bus.
 *
 * The callback specified when the @a handle was created is invoked when the transaction has
 * completed.
 *
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @param psTransfer The pointer to the transfer descriptor.
 * @retval #kStatus_Success The transaction was started successfully.
 * @retval #kStatus_LPI2C_Busy Either another master is currently utilizing the bus, or another DMA
 *      transaction is already in progress.
 */
status_t LPI2C_MasterTransferEDMA(lpi2c_master_edma_transfer_handle_t *psHandle, lpi2c_master_transfer_t *psTransfer);

/*!
 * @brief Returns number of bytes transferred so far.
 *
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @param pu16Count Number of bytes transferred so far by the non-blocking transaction.
 * @retval #kStatus_Success
 * @retval #kStatus_NoTransferInProgress There is not a DMA transaction currently in progress.
 */
status_t LPI2C_MasterTransferGetCountEDMA(lpi2c_master_edma_transfer_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Terminates a non-blocking LPI2C master transmission early.
 *
 * @note It is not safe to call this function from an IRQ handler that has a higher priority than the
 *      eDMA peripheral's IRQ priority.
 *
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @retval #kStatus_Success A transaction was successfully aborted.
 * @retval #kStatus_LPI2C_Idle There is not a DMA transaction currently in progress.
 */
status_t LPI2C_MasterTransferAbortEDMA(lpi2c_master_edma_transfer_handle_t *psHandle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_LPI2C_EDMA_H_ */
