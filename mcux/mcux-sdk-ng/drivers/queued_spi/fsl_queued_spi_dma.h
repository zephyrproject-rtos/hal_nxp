/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_QSPI_DMA_H_
#define FSL_QSPI_DMA_H_

#include "fsl_queued_spi.h"
#include "fsl_dma.h"

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup qspi_dma_driver QSPI_DMA: DMA based QSPI Driver
 * @details
 * The QSPI_DMA module provide a method for QSPI transfer operation based on DMA.
 *
 */

/*!
 * @addtogroup qspi_dma_driver
 * @{
 */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief QSPI DMA driver version. */
#define FSL_QSPI_DMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief Forward declaration of the _qspi_master_dma_handle typedefs.
 */
typedef struct _qspi_master_dma_handle qspi_master_dma_handle_t;

/*!
 * @brief Forward declaration of the _qspi_master_dma_handle typedefs.
 */
typedef struct _qspi_master_dma_handle qspi_slave_dma_handle_t;

/*!
 * @brief Completion callback function pointer type.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psHandle Pointer to the handle for the QUEUEDSPI master.
 * @param eCompletionStatus Success or error code describing whether the transfer completed.
 * @param pUserData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*qspi_dma_transfer_callback_t)(qspi_master_dma_handle_t *psHandle,
                                             status_t eCompletionStatus,
                                             void *pUserData);

/*! @brief QUEUEDSPI master DMA transfer handle structure used for transactional API. */
struct _qspi_master_dma_handle
{
    QSPI_Type *base;              /*!< Base address of the QSPI Peripheral */
    volatile uint8_t u8State;     /*!< QUEUEDSPI transfer state , defined in _qspi_transfer_state. */
    uint16_t u16TotalByteCount;   /*!< A number of transfer bytes. */
    qspi_data_width_t eDataWidth; /*!< The desired number of bits per frame. */

    uint16_t u16TxDummyData; /*!< Used if txData is NULL. */
    uint16_t u16RxDummyData; /*!< Used if rxData is NULL. */

    dma_handle_t sTxHandle; /*!< dma_handle_t handle point used for transmitting data. */
    dma_handle_t sRxHandle; /*!< dma_handle_t handle point used for receiving data. */

    bool bIsTxInProgress; /*!< Indicates whether the transmit is in progress. */
    bool bIsRxInProgress; /*!< Indicates whether the receive is in progress. */

    qspi_dma_transfer_callback_t pfCallback; /*!< Completion callback. */

    void *pUserData; /*!< Callback user data. */

    volatile bool bIsPcsActiveAfterTransfer; /*!< Indicates whether the PCS signal is active after the last frame
                                               transfer, This is not used in slave transfer.*/
};

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

/*Transactional APIs*/

/*!
 * @brief Initialize the QUEUEDSPI master DMA handle.
 *
 * This function initializes the QUEUEDSPI DMA master handle which can be used for QUEUEDSPI DMA master transactional
 * APIs. Usually, for a specified QUEUEDSPI instance, call this API once to get the initialized handle.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psHandle QUEUEDSPI handle pointer to qspi_master_dma_handle_t.
 * @param pfCallback QUEUEDSPI callback.
 * @param pUserData callback function parameter.
 * @param psDmaBase base address for the DMA
 * @param eDmaTxChannel Channel of the DMA used for QSPI Tx
 * @param eDmaRxChannel Channel of the DMA used for QSPI Rx
 */
void QSPI_MasterTransferCreateHandleDMA(QSPI_Type *base,
                                        qspi_master_dma_handle_t *psHandle,
                                        qspi_dma_transfer_callback_t pfCallback,
                                        void *pUserData,
                                        DMA_Type *psDmaBase,
                                        dma_channel_t eDmaTxChannel,
                                        dma_channel_t eDmaRxChannel);

/*!
 * @brief DMA method of QUEUEDSPI master transfer.
 *
 * This function transfers data using DMA. This is a non-blocking function, which returns right away. When all data
 * is transferred, the callback function is called.
 *
 * @note:
 * The transfer data size should be even, if the transfer data width is larger than 8.
 *
 * @param psHandle pointer to qspi_master_dma_handle_t structure which stores the transfer state.
 * @param psXfer pointer to qspi_transfer_t structure.
 * @return status of status_t.
 */
status_t QSPI_MasterTransferDMA(qspi_master_dma_handle_t *psHandle, qspi_transfer_t *psXfer);

/*!
 * @brief Get the master DMA transfer count.
 *
 * @param psHandle Pointer to the qspi_master_dma_handle_t structure which stores the transfer state.
 * @param pu16Count The number of bytes transferred by using the DMA transaction.
 * @return status of status_t.
 */
status_t QSPI_MasterTransferGetCountDMA(qspi_master_dma_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Abort a transfer that uses DMA for master.
 *
 * @param psHandle Pointer to the qspi_master_dma_handle_t structure which stores the transfer state.
 */
void QSPI_MasterTransferAbortDMA(qspi_master_dma_handle_t *psHandle);

/*!
 * @brief Initialize the QUEUEDSPI slave DMA handle.
 *
 * This function initializes the QUEUEDSPI DMA handle which can be used for other QUEUEDSPI transactional APIs.
 * Usually, for a specified QUEUEDSPI instance, call this API once to get the initialized handle.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psHandle QUEUEDSPI handle pointer to qspi_slave_dma_handle_t.
 * @param pfCallback QUEUEDSPI callback.
 * @param pUserData callback function parameter.
 * @param psDmaBase base address for the DMA
 * @param eDmaTxChannel Channel of the DMA used for QSPI Tx
 * @param eDmaRxChannel Channel of the DMA used for QSPI Rx
 */
void QSPI_SlaveTransferCreateHandleDMA(QSPI_Type *base,
                                       qspi_slave_dma_handle_t *psHandle,
                                       qspi_dma_transfer_callback_t pfCallback,
                                       void *pUserData,
                                       DMA_Type *psDmaBase,
                                       dma_channel_t eDmaTxChannel,
                                       dma_channel_t eDmaRxChannel);

/*!
 * @brief DMA method of QUEUEDSPI slave transfer.
 *
 * This function transfers data using DMA. This is a non-blocking function, which returns right away. When all data
 * is transferred, the callback function is called.
 *
 * @note:
 * The transfer data size should be even if the transfer data width is larger than 8.
 *
 * @param psHandle pointer to qspi_slave_dma_handle_t structure which stores the transfer state.
 * @param psXfer pointer to qspi_transfer_t structure.
 * @return status of status_t.
 */
status_t QSPI_SlaveTransferDMA(qspi_slave_dma_handle_t *psHandle, qspi_transfer_t *psXfer);

/*!
 * @brief Get the slave DMA transfer count.
 *
 * @param psHandle Pointer to the qspi_slave_dma_handle_t structure which stores the transfer state.
 * @param pu16Count The number of bytes transferred by using the DMA transaction.
 * @return status of status_t.
 */
status_t QSPI_SlaveTransferGetCountDMA(qspi_slave_dma_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Abort a transfer that uses DMA for slave.
 *
 * @param psHandle Pointer to the qspi_slave_dma_handle_t structure which stores the transfer state.
 */
void QSPI_SlaveTransferAbortDMA(qspi_slave_dma_handle_t *psHandle);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /*FSL_QSPI_DMA_H_*/
