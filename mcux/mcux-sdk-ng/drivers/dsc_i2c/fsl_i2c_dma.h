/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_I2C_DMA_H_
#define FSL_I2C_DMA_H_

#include "fsl_i2c.h"
#include "fsl_dma.h"

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup i2c_dma_driver I2C_DMA: DMA based I2C Driver
 * @details
 * The I2C_DMA module provide a method for I2C transfer operation based on DMA.
 *
 */

/*!
 * @addtogroup i2c_dma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief I2C DMA driver version. */
#define FSL_I2C_DMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief Retry times for waiting flag. */
#ifndef I2C_RETRY_TIMES
#define I2C_RETRY_TIMES 0U /* Define to zero means keep waiting until the flag is assert/deassert. */
#endif

/*! @brief I2C master DMA handle typedef. */
typedef struct _i2c_master_dma_transfer_handle i2c_master_dma_transfer_handle_t;

/*! @brief I2C master DMA transfer callback typedef. */
typedef void (*i2c_master_dma_transfer_callback_t)(i2c_master_dma_transfer_handle_t *handle);

/*! @brief I2C master DMA transfer structure. */
struct _i2c_master_dma_transfer_handle
{
    I2C_Type *base;                  /*!< I2C base pointer to the I2C instance that assigned to this handle. */
    i2c_master_transfer_t sTransfer; /*!< I2C master transfer structure. */
    uint16_t u16TransferSize;        /*!< Total bytes to be transferred. */
    uint8_t u8State;                 /*!< I2C master transfer status. */
    dma_handle_t sDmaHandle;         /*!< The DMA handler used. */
    status_t completionStatus;       /*!< I2C master transfer complete status, indicating how the transfer ends. */
    i2c_master_dma_transfer_callback_t
        pfCallback;  /*!< A callback function called after the DMA transfer is finished. */
    void *pUserData; /*!< User configurable pointer to any data, function, structure etc that user wish to use in the
                callback */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus. */

/*!
 * @name I2C Block DMA Transfer Operation
 * @{
 */

/*!
 * @brief Initializes the I2C handle which is used in transactional functions.
 *
 * @param base I2C peripheral base address.
 * @param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 * @param pfCallback A pointer to the user callback function.
 * @param pUserData A user parameter passed to the callback function.
 * @param dmaBase DMA base address.
 * @param eChannel DMA channel for master transfer.
 */
void I2C_MasterCreateDMAHandle(I2C_Type *base,
                               i2c_master_dma_transfer_handle_t *psHandle,
                               i2c_master_dma_transfer_callback_t pfCallback,
                               void *pUserData,
                               DMA_Type *dmaBase,
                               dma_channel_t eChannel);

/*!
 * @brief Performs a master DMA non-blocking transfer on the I2C bus.
 *
 * @param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 * @param psTransfer A pointer to the transfer structure of i2c_master_transfer_t.
 * @retval kStatus_Success Successfully completed the data transmission.
 * @retval kStatus_I2C_Busy A previous transmission is still not finished.
 * @retval kStatus_I2C_Timeout Transfer error, waits for a signal timeout.
 * @retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval kStataus_I2C_Nak Transfer error, receive NAK during transfer.
 */
status_t I2C_MasterTransferDMA(i2c_master_dma_transfer_handle_t *psHandle, i2c_master_transfer_t *psTransfer);

/*!
 * @brief Gets a master transfer status during the DMA non-blocking transfer.
 *
 * @param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 * @param pu16Count A number of bytes transferred by the non-blocking transaction.
 */
status_t I2C_MasterTransferGetCountDMA(i2c_master_dma_transfer_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Aborts a master DMA non-blocking transfer early.
 *
 * @param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 */
void I2C_MasterTransferAbortDMA(i2c_master_dma_transfer_handle_t *psHandle);

/*! @} */
#if defined(__cplusplus)
}
#endif /*_cplusplus. */

/*! @}*/

#endif /*FSL_I2C_DMA_H_*/
