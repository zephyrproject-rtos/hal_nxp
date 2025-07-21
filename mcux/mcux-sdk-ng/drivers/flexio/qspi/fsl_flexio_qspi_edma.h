/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020, 2022-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_FLEXIO_QSPI_EDMA_H_
#define _FSL_FLEXIO_QSPI_EDMA_H_

#include "fsl_flexio_qspi.h"
#include "fsl_edma.h"

/*!
 * @addtogroup flexio_edma_spi
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief FlexIO SPI EDMA driver version. */
#define FSL_FLEXIO_QSPI_EDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*! @brief  typedef for flexio_qspi_master_edma_handle_t in advance. */
typedef struct _flexio_qspi_master_edma_handle flexio_qspi_master_edma_handle_t;

/*! @brief  Slave handle is the same with master handle. */
typedef flexio_qspi_master_edma_handle_t flexio_qspi_slave_edma_handle_t;

/*! @brief FlexIO SPI master callback for finished transmit */
typedef void (*flexio_qspi_master_edma_transfer_callback_t)(FLEXIO_QSPI_Type *base,
                                                           flexio_qspi_master_edma_handle_t *handle,
                                                           status_t status,
                                                           void *userData);

/*! @brief FlexIO SPI slave callback for finished transmit */
typedef void (*flexio_qspi_slave_edma_transfer_callback_t)(FLEXIO_QSPI_Type *base,
                                                          flexio_qspi_slave_edma_handle_t *handle,
                                                          status_t status,
                                                          void *userData);

/*! @brief FlexIO SPI eDMA transfer handle, users should not touch the content of the handle.*/
struct _flexio_qspi_master_edma_handle
{
    flexio_qspi_buf_t bufs[FLEXIO_QSPI_BUF_MAX];
    bool txInProgress;                                   /*!< Send transfer in progress */
    edma_handle_t *txHandle;                             /*!< DMA handler for SPI send */
    flexio_qspi_master_edma_transfer_callback_t callback; /*!< Callback for SPI DMA transfer */
    void *userData;                                      /*!< User Data for SPI DMA callback */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name eDMA Transactional
 * @{
 */

/*!
 * @brief Initializes the FlexIO SPI master eDMA handle.
 *
 * This function initializes the FlexIO SPI master eDMA handle which can be used for other FlexIO SPI master
 * transactional
 * APIs.
 * For a specified FlexIO SPI instance, call this API once to get the initialized handle.
 *
 * @param base Pointer to FLEXIO_QSPI_Type structure.
 * @param handle Pointer to flexio_qspi_master_edma_handle_t structure to store the transfer state.
 * @param callback SPI callback, NULL means no callback.
 * @param userData callback function parameter.
 * @param txHandle User requested eDMA handle for FlexIO SPI TX eDMA transfer.
 * @retval kStatus_Success Successfully create the handle.
 * @retval kStatus_OutOfRange The FlexIO SPI eDMA type/handle table out of range.
 */
status_t FLEXIO_QSPI_MasterTransferCreateHandleEDMA(FLEXIO_QSPI_Type *base,
                                                   flexio_qspi_master_edma_handle_t *handle,
                                                   flexio_qspi_master_edma_transfer_callback_t callback,
                                                   void *userData,
                                                   edma_handle_t *txHandle);

/*!
 * @brief Performs a non-blocking FlexIO SPI transfer using eDMA.
 *
 * @note This interface returns immediately after transfer initiates. Call
 * FLEXIO_QSPI_MasterGetTransferCountEDMA to poll the transfer status and check
 * whether the FlexIO SPI transfer is finished.
 *
 * @param base Pointer to FLEXIO_QSPI_Type structure.
 * @param handle Pointer to flexio_qspi_master_edma_handle_t structure to store the transfer state.
 * @param xfer Pointer to FlexIO SPI transfer structure.
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_FLEXIO_QSPI_Busy FlexIO SPI is not idle, is running another transfer.
 */
status_t FLEXIO_QSPI_MasterTransferEDMA(FLEXIO_QSPI_Type *base,
                                       flexio_qspi_master_edma_handle_t *handle,
                                       flexio_qspi_transfer_t *xfer);

/*!
 * @brief Aborts a FlexIO SPI transfer using eDMA.
 *
 * @param base Pointer to FLEXIO_QSPI_Type structure.
 * @param handle FlexIO SPI eDMA handle pointer.
 */
void FLEXIO_QSPI_MasterTransferAbortEDMA(FLEXIO_QSPI_Type *base, flexio_qspi_master_edma_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif
