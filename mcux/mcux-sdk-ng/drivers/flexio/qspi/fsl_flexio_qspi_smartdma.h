/*
 * Copyright 2019, 2021, 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_FLEXIO_QSPI_SMARTDMA_H_
#define _FSL_FLEXIO_QSPI_SMARTDMA_H_

#include "fsl_smartdma.h"
#include "fsl_flexio_qspi.h"

/*!
 * @addtogroup flexio_smartdma_qspi
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*@{*/
/*! @brief FlexIO QSPI SMARTDMA driver version. */
#define FSL_FLEXIO_QSPI_SMARTDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*@}*/

/*! @brief  typedef for flexio_qspi_smartdma_handle_t in advance. */
typedef struct _flexio_qspi_smartdma_handle flexio_qspi_smartdma_handle_t;

/*! @brief FlexIO QSPI master callback for transfer complete.
 *
 * When transfer finished, the callback function is called and returns the
 * @p status as kStatus_FLEXIO_SPI_Idle.
 */
typedef void (*flexio_qspi_smartdma_transfer_callback_t)(FLEXIO_QSPI_Type *base,
                                                           flexio_qspi_smartdma_handle_t *handle,
                                                           status_t status,
                                                           void *userData);

/*! @brief FlexIO QSPI SMARTDMA transfer handle, users should not touch the
 * content of the handle.*/
struct _flexio_qspi_smartdma_handle
{
    FLEXIO_QSPI_Type *base;
    flexio_qspi_buf_t bufs[FLEXIO_QSPI_BUF_MAX];
    volatile uint32_t current_buffer;
    volatile size_t txRemainingBytes;               /*!< Send data remaining in bytes. */
    volatile uint32_t state;                        /*!< FlexIO SPI internal state. */
    uint8_t bytePerFrame;                           /*!< SPI mode, 2bytes or 1byte in a frame */
    flexio_spi_shift_direction_t direction;         /*!< Shift direction. */
    flexio_qspi_smartdma_transfer_callback_t callback; /*!< FlexIO SPI callback. */
    void *userData;                                 /*!< Callback parameter. */
    smartdma_flexio_qspi_api_t smartdmaApi;         /*!< The SMARTDMA API used during transfer. */                /*!< User Data for MCULCD SMARTDMA callback */
    smartdma_flexio_qspi_param_t smartdmaParam;  
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name SMARTDMA Transactional
 * @{
 */

/*!
 * @brief Initializes the FLEXO QSPI master SMARTDMA handle.
 *
 * This function initializes the FLEXO QSPI master SMARTDMA handle which can be
 * used for other FLEXO QSPI transactional APIs. For a specified FLEXO QSPI
 * instance, call this API once to get the initialized handle.
 *
 * @param base Pointer to FLEXIO_QSPI_Type structure.
 * @param handle Pointer to flexio_qspi_smartdma_handle_t structure to store the
 * transfer state.
 * @param config Pointer to the configuration.
 * @param callback QSPI transfer complete callback, NULL means no callback.
 * @param userData callback function parameter.
 * @retval kStatus_Success Successfully create the handle.
 */
status_t FLEXIO_QSPI_TransferCreateHandleSMARTDMA(FLEXIO_QSPI_Type *base,
                                                    flexio_qspi_smartdma_handle_t *handle,
                                                    flexio_qspi_smartdma_transfer_callback_t callback,
                                                    void *userData);

/*!
 * @brief Performs a non-blocking FlexIO QSPI transfer using SMARTDMA.
 *
 * This function returns immediately after transfer initiates. Use the callback
 * function to check whether the transfer is completed.
 *
 * @param base pointer to FLEXIO_QSPI_Type structure.
 * @param handle pointer to flexio_qspi_smartdma_handle_t structure to store the
 * transfer state.
 * @param xfer Pointer to FlexIO QSPI transfer structure.
 * @retval kStatus_Success Successfully start a transfer.
 * @retval kStatus_InvalidArgument Input argument is invalid.
 * @retval kStatus_FLEXIO_SPI_Busy FlexIO QSPI is not idle, it is running another
 * transfer.
 */
status_t FLEXIO_QSPI_TransferSMARTDMA(FLEXIO_QSPI_Type *base,
                                        flexio_qspi_smartdma_handle_t *handle,
                                        flexio_qspi_transfer_t *xfer);

/*!
 * @brief Aborts a FlexIO QSPI transfer using SMARTDMA.
 *
 * @param base pointer to FLEXIO_QSPI_Type structure.
 * @param handle FlexIO QSPI SMARTDMA handle pointer.
 */
void FLEXIO_QSPI_TransferAbortSMARTDMA(FLEXIO_QSPI_Type *base, flexio_qspi_smartdma_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _FSL_FLEXIO_QSPI_SMARTDMA_H_ */
