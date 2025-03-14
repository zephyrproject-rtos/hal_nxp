/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexcan_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_flexcan_edma"
#endif

/* FlexCAN EDMA transfer handle. */
enum _flexcan_edma_tansfer_state
{
    KFLEXCAN_RxFifoIdle = 0U, /* Rx Fifo idle. */
    KFLEXCAN_RxFifoBusy = 1U, /* Rx Fifo busy. */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*<! Private handle only used for internally. */
static flexcan_edma_handle_t s_sFlexcanEdmaHandles[FSL_FEATURE_SOC_FLEXCAN_COUNT];

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief FlexCAN EDMA receive finished callback function.
 *
 * This function is called when FlexCAN Rx FIFO EDMA receive finished.
 * It disables the FlexCAN Rx FIFO EDMA request and sends
 * @ref kStatus_FLEXCAN_RxFifoIdle to FlexCAN EDMA callback.
 *
 * @param psHandle The EDMA handle.
 * @param param Callback function parameter.
 */
static void FLEXCAN_ReceiveFifoEDMACallback(edma_handle_t *psHandle,
                                            void *param,
                                            bool bIsTransferDone,
                                            uint32_t u32Tcds);

/*******************************************************************************
 * Code
 ******************************************************************************/

static void FLEXCAN_ReceiveFifoEDMACallback(edma_handle_t *psHandle,
                                            void *param,
                                            bool bIsTransferDone,
                                            uint32_t u32Tcds)
{
    psHandle = psHandle;
    u32Tcds  = u32Tcds;

    flexcan_edma_handle_t *psFlexcanHandle = (flexcan_edma_handle_t *)param;

    if (bIsTransferDone)
    {
        /* Disable transfer. */
        FLEXCAN_TransferAbortReceiveFifoEDMA(psFlexcanHandle);

        if (NULL != psFlexcanHandle->pfCallback)
        {
            psFlexcanHandle->pfCallback(psFlexcanHandle, kStatus_FLEXCAN_RxFifoIdle, psFlexcanHandle->pUserData);
        }
    }
}

void FLEXCAN_TransferCreateHandleEDMA(CAN_Type *base,
                                      flexcan_edma_handle_t *psHandle,
                                      flexcan_edma_transfer_callback_t pfCallback,
                                      void *pUserData,
                                      DMA_Type *psEdmaBase,
                                      edma_channel_t eChannel)
{
    assert(NULL != psHandle);

    uint32_t instance               = FLEXCAN_GetInstance(base);
    s_sFlexcanEdmaHandles[instance] = psHandle;

    (void)memset(psHandle, 0, sizeof(flexcan_edma_handle_t));

    /* Store the base address */
    psHandle->base = base;

    /* Init the FIFO State */
    psHandle->u8RxFifoState = (uint8_t)KFLEXCAN_RxFifoIdle;

    /* Register Callback. */
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    /* Configure Rx FIFO DMA. */
    EDMA_TransferCreateHandle(psEdmaBase, eChannel, &psHandle->sTcd, 1, FLEXCAN_ReceiveFifoEDMACallback, psHandle);
}

void FLEXCAN_PrepareTransfConfiguration(flexcan_fifo_transfer_t *psFifoXfer, edma_transfer_config_t *pEdmaConfig)
{
    assert(NULL != psFifoXfer);
    assert(NULL != psFifoXfer->psFrame);
    assert(NULL != pEdmaConfig);

    flexcan_frame_t *fifoAddr = (flexcan_frame_t *)FLEXCAN_GetRxFifoHeadAddr(base);

#if (defined(FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER) && FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER)
    EDMA_PrepareTransfer(pEdmaConfig, (void *)fifoAddr, sizeof(flexcan_frame_t), (void *)psFifoXfer->psFrame,
                         sizeof(uint32_t), sizeof(flexcan_frame_t), sizeof(flexcan_frame_t), kEDMA_PeripheralToMemory);
#else
    /* The Data Size of FLEXCAN Legacy RX FIFO output port is 16 Bytes, but lots of chips not support 16Bytes width DMA
     * transfer. These chips always support 4Byte width memory transfer, so we need prepare Memory to Memory mode by 4
     * Bytes width mode.
     */
    EDMA_PrepareTransfer(pEdmaConfig, (void *)fifoAddr, 4U, (void *)psFifoXfer->psFrame, sizeof(uint32_t),
                         sizeof(flexcan_frame_t), sizeof(flexcan_frame_t), kEDMA_MemoryToMemory);
#endif
}

status_t FLEXCAN_StartTransferDatafromRxFIFO(flexcan_edma_handle_t *psHandle, edma_transfer_config_t *pEdmaConfig)
{
    assert(NULL != &psHandle->sRxFifoEdmaHandle);
    assert(NULL != pEdmaConfig);
    status_t status;
    CAN_Type *base = psHandle->base;

    /* If previous Rx FIFO receive not finished. */
    if ((uint8_t)KFLEXCAN_RxFifoBusy == psHandle->u8RxFifoState)
    {
        status = kStatus_FLEXCAN_RxFifoBusy;
    }
    else
    {
        psHandle->u8RxFifoState = (uint8_t)KFLEXCAN_RxFifoBusy;

        /* Enable FlexCAN Rx FIFO EDMA. */
        FLEXCAN_EnableRxFifoDMA(base, true);

        /* Submit configuration. */
        (void)EDMA_SubmitTransfer(&psHandle->sRxFifoEdmaHandle, (const edma_transfer_config_t *)pEdmaConfig);
        /* Start transfer. */
        EDMA_StartTransfer(&psHandle->sRxFifoEdmaHandle);

        status = kStatus_Success;
    }

    return status;
}

status_t FLEXCAN_TransferReceiveFifoEDMA(flexcan_edma_handle_t *psHandle, flexcan_fifo_transfer_t *psFifoXfer)
{
    assert(NULL != &psHandle->sRxFifoEdmaHandle);

    edma_transfer_config_t dmaXferConfig;
    status_t status;
    CAN_Type *base = psHandle->base;

    /* Prepare transfer. */
    FLEXCAN_PrepareTransfConfiguration(psFifoXfer, &dmaXferConfig);

    /* Submit configuration and start edma transfer. */
    status = FLEXCAN_StartTransferDatafromRxFIFO(psHandle, &dmaXferConfig);

    return status;
}

void FLEXCAN_TransferAbortReceiveFifoEDMA(flexcan_edma_handle_t *psHandle)
{
    assert(NULL != &psHandle->sRxFifoEdmaHandle);

    CAN_Type *base = psHandle->base;

    /* Stop transfer. */
    EDMA_AbortTransfer(&psHandle->sRxFifoEdmaHandle);

    psHandle->u8RxFifoState = (uint8_t)KFLEXCAN_RxFifoIdle;

    /* Disable FlexCAN Rx FIFO EDMA. */
    FLEXCAN_EnableRxFifoDMA(base, false);
}
