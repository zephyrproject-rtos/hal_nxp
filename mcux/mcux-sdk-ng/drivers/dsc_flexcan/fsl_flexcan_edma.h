/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_FLEXCAN_EDMA_H_
#define FSL_FLEXCAN_EDMA_H_

#include "fsl_flexcan.h"
#include "fsl_edma.h"

/*!
 * @addtogroup flexcan_edma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief FlexCAN EDMA driver version 2.5.1. */
#define FSL_FLEXCAN_EDMA_DRIVER_VERSION (MAKE_VERSION(2, 5, 1))
/*! @} */

/* Forward declaration of the handle typedef. */
typedef struct _flexcan_edma_handle flexcan_edma_handle_t;

/*! @brief FlexCAN transfer callback function. */
typedef void (*flexcan_edma_transfer_callback_t)(flexcan_edma_handle_t *psHandle, status_t status, void *pUserData);

/*!
 * @brief FlexCAN eDMA handle
 */
struct _flexcan_edma_handle
{
    flexcan_edma_transfer_callback_t pfCallback; /*!< Callback function. */
    void *pUserData;                             /*!< FlexCAN callback function parameter.*/
    volatile uint8_t u8RxFifoState;              /*!< Rx FIFO transfer state. */
    edma_handle_t sRxFifoEdmaHandle;             /*!< EDMA Rx FIFO Handle */
    edma_channel_tcd_t sTcd;                     /*!< EDMA Channel TCD needed for EDMA functionality */
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
 * @brief Initializes the FlexCAN handle, which is used in transactional functions.
 *
 * @param base FlexCAN peripheral base address.
 * @param psHandle Pointer to flexcan_edma_handle_t structure.
 * @param pfCallback The callback function.
 * @param pUserData The parameter of the callback function.
 * @param eChannel User-requested DMA handle for Rx FIFO DMA transfer.
 */
void FLEXCAN_TransferCreateHandleEDMA(CAN_Type *base,
                                      flexcan_edma_handle_t *psHandle,
                                      flexcan_edma_transfer_callback_t pfCallback,
                                      void *pUserData,
                                      DMA_Type *psEdmaBase,
                                      edma_channel_t eChannel);

/*!
 * @brief Receives the CAN Message from the Rx FIFO using eDMA.
 *
 * This function receives the CAN Message using eDMA. This is a non-blocking function, which returns
 * right away. After the CAN Message is received, the receive callback function is called.
 *
 * @param psHandle Pointer to flexcan_edma_handle_t structure.
 * @param psFifoXfer FlexCAN Rx FIFO EDMA transfer structure, see #flexcan_fifo_transfer_t.
 * @retval kStatus_Success if succeed, others failed.
 * @retval kStatus_FLEXCAN_RxFifoBusy Previous transfer ongoing.
 */
status_t FLEXCAN_TransferReceiveFifoEDMA(flexcan_edma_handle_t *psHandle, flexcan_fifo_transfer_t *psFifoXfer);

/*!
 * @brief Aborts the receive process which used eDMA.
 *
 * This function aborts the receive process which used eDMA.
 *
 * @param psHandle Pointer to flexcan_edma_handle_t structure.
 */
void FLEXCAN_TransferAbortReceiveFifoEDMA(flexcan_edma_handle_t *psHandle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_FLEXCAN_EDMA_H_ */
