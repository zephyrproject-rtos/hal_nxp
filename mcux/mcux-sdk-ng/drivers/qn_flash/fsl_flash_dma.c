/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flash_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_flash_dma"
#endif

/*<! Structure definition for flash_dma_private_handle_t. The structure is private. */
typedef struct _flash_dma_private_handle
{
    flash_dma_handle_t *handle;
} flash_dma_private_handle_t;

/*! @brief FLASH transfer state, which is used for FLASH transactiaonl APIs' internal state. */
enum _flash_dma_states_t
{
    kFLASH_Idle = 0x0, /*!< FLASH is idle state */
    kFLASH_Busy        /*!< FLASH is busy tranferring data. */
};

/*<! Private handle only used for internally. */
static flash_dma_private_handle_t s_dmaPrivateHandle;
#define FLASH_256K (256 * 1024)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief DMA callback function for FLASH write.
 *
 * @param handle DMA handle pointer.
 * @param userData User data for DMA callback function.
 */
static void FLASH_WriteDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode);

/*!
 * @brief DMA callback function for FLASH read.
 *
 * @param handle DMA handle pointer.
 * @param userData User data for DMA callback function.
 */
static void FLASH_ReadDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static void FLASH_WriteDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode)
{
    flash_dma_private_handle_t *privHandle = (flash_dma_private_handle_t *)userData;
    flash_dma_handle_t *flashHandle        = privHandle->handle;

    /* change the state */
    flashHandle->writeInProgress = false;

    /* All finished, call the callback */
    if ((flashHandle->writeInProgress == false) && (flashHandle->readInProgress == false))
    {
        flashHandle->state = kFLASH_Idle;
        if (flashHandle->callback)
        {
            (flashHandle->callback)(flashHandle, kStatus_FLASH_WriteDmaIdle, flashHandle->userData);
        }
    }
}

static void FLASH_ReadDMACallback(dma_handle_t *handle, void *userData, bool transferDone, uint32_t intmode)
{
    flash_dma_private_handle_t *privHandle = (flash_dma_private_handle_t *)userData;
    flash_dma_handle_t *flashHandle        = privHandle->handle;

    /* change the state */
    flashHandle->readInProgress = false;

    /* All finished, call the callback */
    if ((flashHandle->writeInProgress == false) && (flashHandle->readInProgress == false))
    {
        flashHandle->state = kFLASH_Idle;
        if (flashHandle->callback)
        {
            (flashHandle->callback)(flashHandle, kStatus_FLASH_ReadDmaIdle, flashHandle->userData);
        }
    }
}

/*!
 * brief Initialize the FLASH DMA handle.
 *
 * This function initializes the FLASH DMA handle.
 *
 * param handle FLASH handle pointer.
 * param callback User callback function called at the end of a transfer.
 * param userData User data for callback.
 * param writeHandle DMA handle pointer for FLASH write, the handle shall be static allocated by users.
 * param readHandle DMA handle pointer for FLASH read, the handle shall be static allocated by users.
 * retval kStatus_InvalidArgument Input argument is invalid.
 */
status_t FLASH_CreateHandleDMA(flash_dma_handle_t *handle,
                               flash_dma_callback_t callback,
                               void *userData,
                               dma_handle_t *writeHandle,
                               dma_handle_t *readHandle)
{
    if (NULL == handle)
    {
        return kStatus_InvalidArgument;
    }

    /* Set flash base to handle */
    handle->writeHandle = writeHandle;
    handle->readHandle  = readHandle;
    handle->callback    = callback;
    handle->userData    = userData;

    /* Set FLASH state to idle */
    handle->state = kFLASH_Idle;

    /* Set handle to global state */
    s_dmaPrivateHandle.handle = handle;

    /* Install callback for Tx dma channel */
    DMA_SetCallback(handle->writeHandle, FLASH_WriteDMACallback, &s_dmaPrivateHandle);
    DMA_SetCallback(handle->readHandle, FLASH_ReadDMACallback, &s_dmaPrivateHandle);

    return kStatus_Success;
}

/*!
 * brief Perform a non-blocking FLASH write using DMA.
 *
 * note This interface returned immediately after transfer initiates
 *
 * param handle FLASH DMA handle pointer.
 * param config pointer to configuration structure
 * param addr  Specifies the start address of the FLASH to be written, the address should be aligned with 4 bytes
 * param  pBuf  Pointer of the write data buffer
 * param  lengthInWords  The size of data to be written
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_FLASH_Busy FLASH is not idle, is running another transfer.
 */
status_t FLASH_StartWriteDMA(
    flash_dma_handle_t *handle, flash_config_t *config, uint32_t addr, const uint32_t *pBuf, uint32_t lengthInWords)
{
    dma_transfer_config_t dma_config = {0};

    if ((NULL == handle) || (NULL == config) || (NULL == pBuf) || (0 == lengthInWords))
    {
        return kStatus_InvalidArgument;
    }

    if ((addr < config->blockBase) ||
        ((addr + lengthInWords * sizeof(uint32_t)) > (config->blockBase + config->totalSize)))
    {
        return kStatus_FLASH_AddressError;
    }

    /* Check if the device is busy */
    if (handle->state == kFLASH_Busy)
    {
        return kStatus_FLASH_Busy;
    }
    else
    {
        handle->state = kFLASH_Busy;
        if (config->totalSize != FLASH_256K)
        {
            FLASH->SMART_CTRL = ((config->smartWriteEnable ?
                                      (FLASH_SMART_CTRL_SMART_WRITEH_EN_MASK | FLASH_SMART_CTRL_SMART_WRITEL_EN_MASK) :
                                      0U) |
                                 FLASH_SMART_CTRL_PRGMH_EN_MASK | FLASH_SMART_CTRL_PRGML_EN_MASK);
        }
        else
        {
            FLASH->SMART_CTRL = ((config->smartWriteEnable ? (FLASH_SMART_CTRL_SMART_WRITEH_EN_MASK) : 0U) |
                                 FLASH_SMART_CTRL_PRGMH_EN_MASK);
        }
        DMA_PrepareTransfer(&dma_config, (void *)pBuf, (void *)addr, sizeof(uint32_t), lengthInWords * sizeof(uint32_t),
                            kDMA_MemoryToMemory, NULL);
        /* Submit transfer. */
        DMA_SubmitTransfer(handle->writeHandle, &dma_config);

        handle->writeInProgress = true;
        DMA_StartTransfer(handle->writeHandle);
    }
    return kStatus_Success;
}

/*!
 * brief Perform a non-blocking FLASH read using DMA.
 *
 * note This interface returned immediately after transfer initiates
 *
 * param handle FLASH DMA handle pointer.
 * param config pointer to configuration structure
 * param addr  Specifies the start address of the FLASH to be written, the address should be aligned with 4 bytes
 * param  pBuf  Pointer of the read data buffer
 * param  lengthInWords  The size of data to be written
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_FLASH_Busy FLASH is not idle, is running another transfer.
 */
status_t FLASH_StartReadDMA(
    flash_dma_handle_t *handle, flash_config_t *config, uint32_t addr, const uint32_t *pBuf, uint32_t lengthInWords)
{
    dma_transfer_config_t dma_config = {0};

    if ((NULL == handle) || (NULL == config) || (NULL == pBuf) || (0 == lengthInWords))
    {
        return kStatus_InvalidArgument;
    }

    if ((addr < config->blockBase) ||
        ((addr + lengthInWords * sizeof(uint32_t)) > (config->blockBase + config->totalSize)))
    {
        return kStatus_FLASH_AddressError;
    }

    /* Check if the device is busy */
    if (handle->state == kFLASH_Busy)
    {
        return kStatus_FLASH_Busy;
    }
    else
    {
        handle->state = kFLASH_Busy;

        DMA_PrepareTransfer(&dma_config, (void *)addr, (void *)pBuf, sizeof(uint32_t), lengthInWords * sizeof(uint32_t),
                            kDMA_MemoryToMemory, NULL);
        /* Submit transfer. */
        DMA_SubmitTransfer(handle->readHandle, &dma_config);
        handle->readInProgress = true;
        DMA_StartTransfer(handle->readHandle);
    }
    return kStatus_Success;
}
/*!
 * brief Abort a FLASH transfer using DMA.
 *
 * param base FLASH peripheral base address.
 * param handle FLASH DMA handle pointer.
 */
void FLASH_AbortDMA(flash_dma_handle_t *handle)
{
    assert(NULL != handle);

    /* Stop tx transfer first */
    DMA_AbortTransfer(handle->writeHandle);
    /* Then rx transfer */
    DMA_AbortTransfer(handle->readHandle);

    /* Set the handle state */
    handle->writeInProgress = false;
    handle->readInProgress  = false;
    handle->state           = kFLASH_Idle;
}
