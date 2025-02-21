/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_FLASH_DMA_H_
#define FSL_FLASH_DMA_H_

#include "fsl_flash.h"
#include "fsl_dma.h"

/*!
 * @addtogroup qn_flash_dma
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief FLASH DMA driver version 2.0.0. */
#define FSL_FLASH_DMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

typedef struct _flash_dma_handle flash_dma_handle_t;

/*! @brief FLASH DMA callback called at the end of transfer. */
typedef void (*flash_dma_callback_t)(flash_dma_handle_t *handle, status_t status, void *userData);

/*! @brief FLASH DMA handle, users should not touch the content of the handle.*/
struct _flash_dma_handle
{
    bool writeInProgress;          /*!< write finished */
    bool readInProgress;           /*!< read finished */
    dma_handle_t *writeHandle;     /*!< DMA handler for FLASH write */
    dma_handle_t *readHandle;      /*!< DMA handler for FLASH read */
    flash_dma_callback_t callback; /*!< Callback for FLASH DMA transfer */
    void *userData;                /*!< User Data for FLASH DMA callback */
    uint32_t state;                /*!< Internal state of FLASH DMA transfer */
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
 * @brief Initialize the FLASH DMA handle.
 *
 * This function initializes the FLASH DMA handle.
 *
 * @param handle FLASH handle pointer.
 * @param callback User callback function called at the end of a transfer.
 * @param userData User data for callback.
 * @param writeHandle DMA handle pointer for FLASH write, the handle shall be static allocated by users.
 * @param readHandle DMA handle pointer for FLASH read, the handle shall be static allocated by users.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 */
status_t FLASH_CreateHandleDMA(flash_dma_handle_t *handle,
                               flash_dma_callback_t callback,
                               void *userData,
                               dma_handle_t *writeHandle,
                               dma_handle_t *readHandle);

/*!
 * @brief Perform a non-blocking FLASH read using DMA.
 *
 * @note This interface returned immediately after transfer initiates
 *
 * @param handle FLASH DMA handle pointer.
 * @param config pointer to configuration structure
 * @param addr  Specifies the start address of the FLASH to be written, the address should be aligned with 4 bytes
 * @param  pBuf  Pointer of the read data buffer
 * @param  lengthInWords  The size of data to be written
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_FLASH_Busy FLASH is not idle, is running another transfer.
 */
status_t FLASH_StartReadDMA(
    flash_dma_handle_t *handle, flash_config_t *config, uint32_t addr, const uint32_t *pBuf, uint32_t lengthInWords);

/*!
 * @brief Perform a non-blocking FLASH write using DMA.
 *
 * @note This interface returned immediately after transfer initiates
 *
 * @param handle FLASH DMA handle pointer.
 * @param config pointer to configuration structure
 * @param addr  Specifies the start address of the FLASH to be written, the address should be aligned with 4 bytes
 * @param  pBuf  Pointer of the write data buffer
 * @param  lengthInWords  The size of data to be written
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_FLASH_Busy FLASH is not idle, is running another transfer.
 */
status_t FLASH_StartWriteDMA(
    flash_dma_handle_t *handle, flash_config_t *config, uint32_t addr, const uint32_t *pBuf, uint32_t lengthInWords);

/*!
 * @brief Abort a FLASH transfer using DMA.
 *
 * @param base FLASH peripheral base address.
 * @param handle FLASH DMA handle pointer.
 */
void FLASH_AbortDMA(flash_dma_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* FSL_FLASH_DMA_H_*/
