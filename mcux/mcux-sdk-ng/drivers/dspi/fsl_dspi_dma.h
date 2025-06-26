/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_DSPI_DMA_H_
#define FSL_DSPI_DMA_H_

#include "fsl_dspi.h"
#include "fsl_dma.h"
/*!
 * @addtogroup dspi_dma_driver
 * @{
 */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief DSPI DMA driver version 2.2.5. */
#define FSL_DSPI_DMA_DRIVER_VERSION (MAKE_VERSION(2, 2, 5))
/*! @} */

/*!
 * @brief Forward declaration of the DSPI DMA master handle typedefs.
 */
typedef struct _dspi_master_dma_handle dspi_master_dma_handle_t;

/*!
 * @brief Forward declaration of the DSPI DMA slave handle typedefs.
 */
typedef struct _dspi_slave_dma_handle dspi_slave_dma_handle_t;

/*!
 * @brief Completion callback function pointer type.
 *
 * @param base DSPI peripheral base address.
 * @param handle Pointer to the handle for the DSPI master.
 * @param status Success or error code describing whether the transfer completed.
 * @param userData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*dspi_master_dma_transfer_callback_t)(SPI_Type *base,
                                                    dspi_master_dma_handle_t *handle,
                                                    status_t status,
                                                    void *userData);
/*!
 * @brief Completion callback function pointer type.
 *
 * @param base DSPI peripheral base address.
 * @param handle Pointer to the handle for the DSPI slave.
 * @param status Success or error code describing whether the transfer completed.
 * @param userData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*dspi_slave_dma_transfer_callback_t)(SPI_Type *base,
                                                   dspi_slave_dma_handle_t *handle,
                                                   status_t status,
                                                   void *userData);

/*! @brief DSPI master DMA transfer handle structure used for transactional API. */
struct _dspi_master_dma_handle
{
    uint32_t bitsPerFrame;         /*!< The desired number of bits per frame. */
    volatile uint32_t command;     /*!< The desired data command. */
    volatile uint32_t lastCommand; /*!< The desired last data command. */

    uint8_t fifoSize; /*!< FIFO dataSize. */

    volatile bool
        isPcsActiveAfterTransfer;   /*!< Indicates whether the PCS signal keeps active after the last frame transfer.*/
    volatile bool isThereExtraByte; /*!< Indicates whether there is an extra byte.*/

    const uint8_t *volatile txData; /*!< Send buffer. */
    uint8_t *volatile rxData;                  /*!< Receive buffer. */
    volatile size_t remainingSendByteCount;    /*!< A number of bytes remaining to send.*/
    volatile size_t remainingReceiveByteCount; /*!< A number of bytes remaining to receive.*/
    size_t totalByteCount;                     /*!< A number of transfer bytes*/

    uint32_t rxBuffIfNull; /*!< Used if there is not rxData for DMA purpose.*/
    uint32_t txBuffIfNull; /*!< Used if there is not txData for DMA purpose.*/

    volatile uint8_t state; /*!< DSPI transfer state, see @ref _dspi_transfer_state.*/

    dspi_master_dma_transfer_callback_t callback; /*!< Completion callback. */
    void *userData;                               /*!< Callback user data. */

    dma_handle_t *dmaRxRegToRxDataHandle;        /*!<dma_handle_t handle point used for RxReg to RxData buff*/
    dma_handle_t *dmaTxDataToIntermediaryHandle; /*!<dma_handle_t handle point used for TxData to Intermediary*/
    dma_handle_t *dmaIntermediaryToTxRegHandle;  /*!<dma_handle_t handle point used for Intermediary to TxReg*/
};

/*! @brief DSPI slave DMA transfer handle structure used for transactional API.*/
struct _dspi_slave_dma_handle
{
    uint32_t bitsPerFrame;          /*!< Desired number of bits per frame. */
    volatile bool isThereExtraByte; /*!< Indicates whether there is an extra byte.*/

    const uint8_t *volatile txData;            /*!< A send buffer. */
    uint8_t *volatile rxData;                  /*!< A receive buffer. */
    volatile size_t remainingSendByteCount;    /*!< A number of bytes remaining to send.*/
    volatile size_t remainingReceiveByteCount; /*!< A number of bytes remaining to receive.*/
    size_t totalByteCount;                     /*!< A number of transfer bytes*/

    uint32_t rxBuffIfNull; /*!< Used if there is not rxData for DMA purpose.*/
    uint32_t txBuffIfNull; /*!< Used if there is not txData for DMA purpose.*/
    uint32_t txLastData;   /*!< Used if there is an extra byte when 16 bits per frame for DMA purpose.*/

    volatile uint8_t state; /*!< DSPI transfer state.*/

    uint32_t errorCount; /*!< Error count for the slave transfer.*/

    dspi_slave_dma_transfer_callback_t callback; /*!< Completion callback. */
    void *userData;                              /*!< Callback user data. */

    dma_handle_t *dmaRxRegToRxDataHandle; /*!<dma_handle_t handle point used for RxReg to RxData buff*/
    dma_handle_t *dmaTxDataToTxRegHandle; /*!<dma_handle_t handle point used for TxData to TxReg*/
};

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

/*! @name Transactional APIs*/

/*!
 * @brief Initializes the DSPI master DMA handle.
 *
 * This function initializes the DSPI DMA handle which can be used for other DSPI transactional APIs.  Usually, for a
 * specified DSPI instance, call this API once to get the initialized handle.
 *
 * @note DSPI DMA has a separated (Rx and Tx as two sources) or shared (Rx  and Tx is the same source) DMA request
 * source.
 * - For a separated DMA request source, enable and set the Rx DMAMUX source for dmaRxRegToRxDataHandle and
 *   Tx DMAMUX source for dmaIntermediaryToTxRegHandle.
 * - For a shared DMA request source, enable and set the Rx/Rx DMAMUX source for dmaRxRegToRxDataHandle.
 *
 * @param base DSPI peripheral base address.
 * @param handle DSPI handle pointer to @ref _dspi_master_dma_handle.
 * @param callback DSPI callback.
 * @param userData A callback function parameter.
 * @param dmaRxRegToRxDataHandle dmaRxRegToRxDataHandle pointer to dma_handle_t.
 * @param dmaTxDataToIntermediaryHandle dmaTxDataToIntermediaryHandle pointer to dma_handle_t.
 * @param dmaIntermediaryToTxRegHandle dmaIntermediaryToTxRegHandle pointer to dma_handle_t.
 */
void DSPI_MasterTransferCreateHandleDMA(SPI_Type *base,
                                        dspi_master_dma_handle_t *handle,
                                        dspi_master_dma_transfer_callback_t callback,
                                        void *userData,
                                        dma_handle_t *dmaRxRegToRxDataHandle,
                                        dma_handle_t *dmaTxDataToIntermediaryHandle,
                                        dma_handle_t *dmaIntermediaryToTxRegHandle);

/*!
 * @brief DSPI master transfers data using DMA.
 *
 * This function transfers data using DMA. This is a non-blocking function, which returns right away. When all data
 * is transferred, the callback function is called.
 *
 * @note The master DMA transfer does not support the transfer_size of 1 when the bitsPerFrame is greater
 * than 8.
 *
 * @param base DSPI peripheral base address.
 * @param handle A pointer to the @ref _dspi_master_dma_handle structure which stores the transfer state.
 * @param transfer A pointer to the @ref dspi_transfer_t structure.
 * @return status of status_t.
 */
status_t DSPI_MasterTransferDMA(SPI_Type *base, dspi_master_dma_handle_t *handle, dspi_transfer_t *transfer);

/*!
 * @brief DSPI master aborts a transfer which is using DMA.
 *
 * This function aborts a transfer which is using DMA.
 *
 * @param base DSPI peripheral base address.
 * @param handle A pointer to the @ref _dspi_master_dma_handle structure which stores the transfer state.
 */
void DSPI_MasterTransferAbortDMA(SPI_Type *base, dspi_master_dma_handle_t *handle);

/*!
 * @brief Gets the master DMA transfer remaining bytes.
 *
 * This function gets the master DMA transfer remaining bytes.
 *
 * @param base DSPI peripheral base address.
 * @param handle A pointer to the @ref _dspi_master_dma_handle structure which stores the transfer state.
 * @param count A number of bytes transferred by the non-blocking transaction.
 * @return status of status_t.
 */
status_t DSPI_MasterTransferGetCountDMA(SPI_Type *base, dspi_master_dma_handle_t *handle, size_t *count);

/*!
 * @brief Initializes the DSPI slave DMA handle.
 *
 * This function initializes the DSPI DMA handle which can be used for other DSPI transactional APIs.  Usually, for a
 * specified DSPI instance, call this API once to get the initialized handle.
 *
 * @note DSPI DMA has a separated (Rx and Tx as two sources) or shared (Rx  and Tx is the same source) DMA request
 * source.
 * - For a separated DMA request source, enable and set the Rx DMAMUX source for dmaRxRegToRxDataHandle and
 *   Tx DMAMUX source for dmaTxDataToTxRegHandle.
 * - For a shared DMA request source, enable and set the Rx/Rx DMAMUX source for dmaRxRegToRxDataHandle.
 *
 * @param base DSPI peripheral base address.
 * @param handle DSPI handle pointer to @ref _dspi_slave_dma_handle.
 * @param callback DSPI callback.
 * @param userData A callback function parameter.
 * @param dmaRxRegToRxDataHandle dmaRxRegToRxDataHandle pointer to dma_handle_t.
 * @param dmaTxDataToTxRegHandle dmaTxDataToTxRegHandle pointer to dma_handle_t.
 */
void DSPI_SlaveTransferCreateHandleDMA(SPI_Type *base,
                                       dspi_slave_dma_handle_t *handle,
                                       dspi_slave_dma_transfer_callback_t callback,
                                       void *userData,
                                       dma_handle_t *dmaRxRegToRxDataHandle,
                                       dma_handle_t *dmaTxDataToTxRegHandle);

/*!
 * @brief DSPI slave transfers data using DMA.
 *
 * This function transfers data using DMA. This is a non-blocking function, which returns right away. When all data
 * is transferred, the callback function is called.
 *
 * @note The slave DMA transfer does not support the transfer_size of 1 when the bitsPerFrame is greater
 * than eight.

 * @param base DSPI peripheral base address.
 * @param handle A pointer to the @ref _dspi_slave_dma_handle structure which stores the transfer state.
 * @param transfer A pointer to the @ref dspi_transfer_t structure.
 * @return status of status_t.
 */
status_t DSPI_SlaveTransferDMA(SPI_Type *base, dspi_slave_dma_handle_t *handle, dspi_transfer_t *transfer);

/*!
 * @brief DSPI slave aborts a transfer which is using DMA.
 *
 * This function aborts a transfer which is using DMA.
 *
 * @param base DSPI peripheral base address.
 * @param handle A pointer to the @ref _dspi_slave_dma_handle structure which stores the transfer state.
 */
void DSPI_SlaveTransferAbortDMA(SPI_Type *base, dspi_slave_dma_handle_t *handle);

/*!
 * @brief Gets the slave DMA transfer remaining bytes.
 *
 * This function gets the slave DMA transfer remaining bytes.
 *
 * @param base DSPI peripheral base address.
 * @param handle A pointer to the @ref _dspi_slave_dma_handle structure which stores the transfer state.
 * @param count A number of bytes transferred by the non-blocking transaction.
 * @return status of status_t.
 */
status_t DSPI_SlaveTransferGetCountDMA(SPI_Type *base, dspi_slave_dma_handle_t *handle, size_t *count);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/*!
 *@}
 */

#endif /*FSL_DSPI_DMA_H_*/
