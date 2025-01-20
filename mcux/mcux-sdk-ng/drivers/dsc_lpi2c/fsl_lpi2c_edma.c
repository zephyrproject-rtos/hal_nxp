/*
 * Copyright 2020,2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpi2c_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_lpi2c_edma"
#endif

/* ! @brief LPI2C master fifo commands. */
enum
{
    kTxDataCmd = LPI2C_MTDR_CMD(0x0U), /*!< Transmit DATA[7:0] */
    kRxDataCmd = LPI2C_MTDR_CMD(0X1U), /*!< Receive (DATA[7:0] + 1) bytes */
    kStopCmd   = LPI2C_MTDR_CMD(0x2U), /*!< Generate STOP condition */
    kStartCmd  = LPI2C_MTDR_CMD(0x4U), /*!< Generate(repeated) START and transmit address in DATA[[7:0] */
};

/*! @brief States for the state machine used by transactional APIs. */
enum
{
    kIdleState = 0,
    kSendCommandState,
    kIssueReadCommandState,
    kTransferDataState,
    kStopState,
    kWaitForCompletionState,
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static uint8_t LPI2C_GenerateCommands(lpi2c_master_edma_transfer_handle_t *psHandle);

static void LPI2C_MasterEDMACallback(edma_handle_t *psDmaHandle,
                                     void *pUserData,
                                     bool bIsTransferDone,
                                     uint32_t u32Tcds);

/*******************************************************************************
 * Variables
 ******************************************************************************/

static uint16_t s_u16Lpi2cEdmaRecSetting = 0x02;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Create a new handle for the LPI2C master DMA APIs.
 *
 * The creation of a handle is for use with the DMA APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the LPI2C_MasterTransferAbortEDMA() API shall be called.
 *
 * For devices where the LPI2C send and receive DMA requests are OR'd together, the a txDmaHandle
 * parameter is ignored and may be set to NULL.
 *
 * param base The LPI2C peripheral base address.
 * param psHandle Pointer to the LPI2C master driver handle.
 * param pfcallback User provided pointer to the asynchronous callback function.
 * param pUserData User provided pointer to the application callback data.
 * param edmaBase Edma base address.
 * param eEdmaTxChannel eDMA channel for master transfer Tx request.
 * param eEdmaRxChannel eDMA channel for master transfer Rx request.
 */
void LPI2C_MasterCreateEDMAHandle(LPI2C_Type *base,
                                  lpi2c_master_edma_transfer_handle_t *psHandle,
                                  lpi2c_master_edma_transfer_callback_t pfcallback,
                                  void *pUserData,
                                  DMA_Type *edmaBase,
                                  edma_channel_t eEdmaTxChannel,
                                  edma_channel_t eEdmaRxChannel)
{
    assert(psHandle);

    /* Clear out the handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Set up the handle. For combined rx/tx DMA requests, the tx channel handle is set to the rx handle */
    /* in order to make the transfer API code simpler. */
    psHandle->base       = base;
    psHandle->pfCallback = pfcallback;
    psHandle->pUserData  = pUserData;

    /* Set DMA channel completion callbacks. */
    EDMA_TransferCreateHandle(edmaBase, &psHandle->sRxDmaHandle, eEdmaRxChannel, psHandle->sRxTcd, 1,
                              LPI2C_MasterEDMACallback, psHandle);
    EDMA_TransferCreateHandle(edmaBase, &psHandle->sTxDmaHandle, eEdmaTxChannel, psHandle->sTxTcd, 3,
                              LPI2C_MasterEDMACallback, psHandle);
}

/*!
 * @brief Prepares the command buffer with the sequence of commands needed to send the requested transaction.
 * @param psHandle Master DMA driver handle.
 * @return Number of command words.
 */
static uint8_t LPI2C_GenerateCommands(lpi2c_master_edma_transfer_handle_t *psHandle)
{
    lpi2c_master_transfer_t *psXfer = &psHandle->sTransfer;
    uint16_t *pu16Cmd               = (uint16_t *)&psHandle->u16CommandBuffer;
    uint8_t u8CmdCount              = 0;

    /* Handle no start option. */
    if ((psXfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStartFlag) != 0U)
    {
        if (psXfer->eDirection == kLPI2C_Read)
        {
            /* Need to issue read command first. */
            pu16Cmd[u8CmdCount++] = (uint16_t)kRxDataCmd | (uint16_t)LPI2C_MTDR_DATA(psXfer->u16DataSize - 1U);
        }
    }
    else
    {
        /*
         * Initial direction depends on whether a subaddress was provided, and of course the actual
         * data transfer direction.
         */
        lpi2c_data_direction_t eDirection = (psXfer->u8CommandSize != 0U) ? kLPI2C_Write : psXfer->eDirection;

        /* Start command. */
        pu16Cmd[u8CmdCount++] =
            (uint16_t)kStartCmd | ((uint16_t)((uint16_t)psXfer->u8SlaveAddress << 1U) | (uint16_t)eDirection);

        /* Subaddress, MSB first. */
        if (psXfer->u8CommandSize != 0U)
        {
            uint8_t u8CommandRemaining = psXfer->u8CommandSize;
            uint8_t *pu8Command        = psXfer->pu8Command;
            while (0U != u8CommandRemaining--)
            {
                uint8_t u8CommandByte = *pu8Command;
                pu16Cmd[u8CmdCount++] = u8CommandByte;
                pu8Command++;
            }
        }

        /* Reads need special handling because we have to issue a read command and maybe a repeated start. */
        if ((psXfer->u16DataSize != 0U) && (psXfer->eDirection == kLPI2C_Read))
        {
            /* Need to send repeated start if switching directions to read. */
            if (eDirection == kLPI2C_Write)
            {
                pu16Cmd[u8CmdCount++] =
                    (uint16_t)kStartCmd |
                    (uint16_t)((uint16_t)((uint16_t)psXfer->u8SlaveAddress << 1U) | (uint16_t)kLPI2C_Read);
            }

            /* Read command. */
            pu16Cmd[u8CmdCount++] = (uint16_t)kRxDataCmd | (uint16_t)LPI2C_MTDR_DATA(psXfer->u16DataSize - 1U);
        }
    }

    return u8CmdCount;
}

/*!
 * brief Performs a non-blocking DMA-based transaction on the I2C bus.
 *
 * The callback specified when the a handle was created is invoked when the transaction has
 * completed.
 *
 * param psHandle Pointer to the LPI2C master driver handle.
 * param psTransfer The pointer to the transfer descriptor.
 * retval #kStatus_Success The transaction was started successfully.
 * retval #kStatus_LPI2C_Busy Either another master is currently utilizing the bus, or another DMA
 *      transaction is already in progress.
 */
status_t LPI2C_MasterTransferEDMA(lpi2c_master_edma_transfer_handle_t *psHandle, lpi2c_master_transfer_t *psTransfer)
{
    status_t result;

    assert(psHandle);
    assert(psTransfer);
    assert(psTransfer->u8CommandSize <= (sizeof(psHandle->u16CommandBuffer) - 2U));

    /* Return busy if another transaction is in progress. */
    if (psHandle->bIsBusy)
    {
        return kStatus_LPI2C_Busy;
    }

    /* Return an error if the bus is already in use not by us. */
    result = LPI2C_MasterCheckForBusyBus(psHandle->base);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* We're now busy. */
    psHandle->bIsBusy = true;

    /* Disable LPI2C IRQ and DMA sources while we configure stuff. */
    LPI2C_MasterDisableInterrupts(psHandle->base, (uint16_t)kLPI2C_MasterIrqFlags);
    LPI2C_MasterEnableDMA(psHandle->base, false, false);

    /* Clear all flags. */
    LPI2C_MasterClearStatusFlags(psHandle->base, (uint16_t)kLPI2C_MasterClearInterruptFlags);

    /* Save transfer into handle. */
    psHandle->sTransfer = *psTransfer;

    /* Generate commands to send. */
    uint8_t u8CommandCount = LPI2C_GenerateCommands(psHandle);

    /* If the user is transmitting no data with no start or stop, then just go ahead and invoke the callback. */
    if ((0U == u8CommandCount) && (psTransfer->u16DataSize == 0U))
    {
        if (psHandle->pfCallback != NULL)
        {
            psHandle->completionStatus = kStatus_Success;
            psHandle->pfCallback(psHandle);
        }
        return kStatus_Success;
    }

    bool hasSendData    = (psTransfer->eDirection == kLPI2C_Write) && (psTransfer->u16DataSize != 0U);
    bool hasReceiveData = (psTransfer->eDirection == kLPI2C_Read) && (psTransfer->u16DataSize != 0U);

    edma_channel_transfer_config_t sTransferConfig[3] = {0};

    /* Set up data transmit. */
    if (hasSendData)
    {
        uint32_t u32SrcByteAddr = (uint32_t)(uint8_t *)(psTransfer->pData);
        uint32_t u32DstByteAddr = LPI2C_MasterGetTxFifoAddress(psHandle->base);

        if (u8CommandCount != 0U)
        {
            EDMA_GetChannelDefaultTransferConfig(&sTransferConfig[1], u32SrcByteAddr, u32DstByteAddr, 1,
                                                 psTransfer->u16DataSize, kEDMA_ChannelTransferWidth8Bits,
                                                 kEDMA_ChannelTransferMemoryToPeripheral);
            sTransferConfig[1].u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;

            /* Store the initially configured eDMA minor byte transfer count into the LPI2C handle */
            psHandle->u8Nbytes = (uint8_t)sTransferConfig[1].u32BytesEachMinorLoop;
        }
        else
        {
            EDMA_GetChannelDefaultTransferConfig(&sTransferConfig[0], u32SrcByteAddr, u32DstByteAddr, 1,
                                                 psTransfer->u16DataSize, kEDMA_ChannelTransferWidth8Bits,
                                                 kEDMA_ChannelTransferMemoryToPeripheral);
            sTransferConfig[0].u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;
            (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sTxDmaHandle, &sTransferConfig[0]);
            /* Store the initially configured eDMA minor byte transfer count into the LPI2C handle */
            psHandle->u8Nbytes = (uint8_t)sTransferConfig[0].u32BytesEachMinorLoop;
        }
    }
    else if (hasReceiveData)
    {
        uint32_t u32SrcByteAddr = LPI2C_MasterGetRxFifoAddress(psHandle->base);
        uint32_t u32DstByteAddr = (uint32_t)(uint8_t *)(psTransfer->pData);

        if ((FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(base) != 0) || (0U == u8CommandCount))
        {
            EDMA_GetChannelDefaultTransferConfig(&sTransferConfig[0], u32SrcByteAddr, u32DstByteAddr, 1,
                                                 psTransfer->u16DataSize, kEDMA_ChannelTransferWidth8Bits,
                                                 kEDMA_ChannelTransferPeripheralToMemory);
            sTransferConfig[0].u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;
            /* We can put this receive transfer on its own DMA channel. */
            (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sRxDmaHandle, &sTransferConfig[0]);
            /* Store the initially configured eDMA minor byte transfer count into the LPI2C handle */
            psHandle->u8Nbytes = (uint8_t)sTransferConfig[0].u32BytesEachMinorLoop;
        }
        else
        {
            /* For shared rx/tx DMA requests, when there are commands, create a software TCD of
               enabling rx dma and disabling tx dma, which will be chained onto the commands transfer,
               and create another software TCD of transfering data and chain it onto the last TCD.
               Notice that in this situation assume tx/rx uses same channel */

            /* Mask Tx DMA request then receive data */
            EDMA_GetChannelDefaultTransferConfig(&sTransferConfig[2], u32SrcByteAddr, u32DstByteAddr, 1,
                                                 psTransfer->u16DataSize, kEDMA_ChannelTransferWidth8Bits,
                                                 kEDMA_ChannelTransferPeripheralToMemory);
            sTransferConfig[2].u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;

            /* Store the initially configured eDMA minor byte transfer count into the LPI2C handle */
            psHandle->u8Nbytes = (uint8_t)sTransferConfig[2].u32BytesEachMinorLoop;

            u32SrcByteAddr = (uint32_t)(uint8_t *)&s_u16Lpi2cEdmaRecSetting;
            u32DstByteAddr = SDK_GET_REGISTER_BYTE_ADDR(LPI2C_Type, psHandle->base, MDER);
            EDMA_GetChannelDefaultTransferConfig(&sTransferConfig[1], u32SrcByteAddr, u32DstByteAddr, 1, 1,
                                                 kEDMA_ChannelTransferWidth8Bits,
                                                 kEDMA_ChannelTransferMemoryToPeripheral);
        }
    }
    else
    {
        /* No data to send */
    }

    /* Set up commands transfer. */
    if (u8CommandCount != 0U)
    {
        uint32_t u32SrcByteAddr = (uint32_t)(uint8_t *)psHandle->u16CommandBuffer;
        uint32_t u32DstByteAddr = LPI2C_MasterGetTxFifoAddress(psHandle->base);

        EDMA_GetChannelDefaultTransferConfig(&sTransferConfig[0], u32SrcByteAddr, u32DstByteAddr, 2U,
                                             (uint32_t)u8CommandCount * 2U, kEDMA_ChannelTransferWidth16Bits,
                                             kEDMA_ChannelTransferMemoryToPeripheral);

        if (hasSendData)
        {
            (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sTxDmaHandle, &sTransferConfig[0]);
            (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sTxDmaHandle, &sTransferConfig[1]);
        }
        else if (hasReceiveData)
        {
            (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sTxDmaHandle, &sTransferConfig[0]);
            /* Only shared rx/rx dma request needs extra descriptor to use DMA to enable rx request and disable tx
             * request after command is sent. */
            if (0 == FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(base))
            {
                (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sTxDmaHandle, &sTransferConfig[1]);
                (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sTxDmaHandle, &sTransferConfig[2]);
            }
        }
        else
        {
            sTransferConfig[0].u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;
            (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sTxDmaHandle, &sTransferConfig[0]);
        }
    }

    /* Start Rx DMA transfer if it's receiving only transfer or Tx/Rx DMA requests is in different channels. */
    if (hasReceiveData && ((FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(base) != 0) || (0U == u8CommandCount)))
    {
        EDMA_TransferStart(&psHandle->sRxDmaHandle);
    }
    /* Start Tx DMA transfer if it's data sending or command sending(with data receiving or not). */
    if (hasSendData || (u8CommandCount != 0U))
    {
        EDMA_TransferStart(&psHandle->sTxDmaHandle);
    }

    /* Enable DMA in both directions. This actually kicks of the transfer. */
    LPI2C_MasterEnableDMA(psHandle->base, true, true);

    return result;
}

/*!
 * brief Returns number of bytes transferred so far.
 *
 * param psHandle Pointer to the LPI2C master driver handle.
 * param pu16Count Number of bytes transferred so far by the non-blocking transaction.
 * retval #kStatus_Success
 * retval #kStatus_NoTransferInProgress There is not a DMA transaction currently in progress.
 */
status_t LPI2C_MasterTransferGetCountEDMA(lpi2c_master_edma_transfer_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(psHandle);

    if (NULL == pu16Count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (!psHandle->bIsBusy)
    {
        *pu16Count = 0;
        return kStatus_NoTransferInProgress;
    }

    uint16_t remaining = psHandle->sTransfer.u16DataSize;

    /* If the DMA is still on a commands transfer that chains to the actual data transfer, */
    /* we do nothing and return the number of transferred bytes as zero. */
    if ((uint32_t)(psHandle->sTxDmaHandle.psBase->TCD[(uint8_t)psHandle->sTxDmaHandle.eChannel].DLAST_SGA) == 0U)
    {
        if (psHandle->sTransfer.eDirection == kLPI2C_Write)
        {
            remaining =
                (uint16_t)psHandle->u8Nbytes * (uint16_t)EDMA_GetChannelRemainingMajorLoopCount(
                                                   psHandle->sTxDmaHandle.psBase, psHandle->sTxDmaHandle.eChannel);
        }
        else
        {
            remaining =
                (uint16_t)psHandle->u8Nbytes * (uint16_t)EDMA_GetChannelRemainingMajorLoopCount(
                                                   psHandle->sRxDmaHandle.psBase, psHandle->sRxDmaHandle.eChannel);
        }
    }

    *pu16Count = psHandle->sTransfer.u16DataSize - remaining;

    return kStatus_Success;
}

/*!
 * brief Terminates a non-blocking LPI2C master transmission early.
 *
 * note It is not safe to call this function from an IRQ handler that has a higher priority than the
 *      eDMA peripheral's IRQ priority.
 *
 * param psHandle Pointer to the LPI2C master driver handle.
 * retval #kStatus_Success A transaction was successfully aborted.
 * retval #kStatus_LPI2C_Idle There is not a DMA transaction currently in progress.
 */
status_t LPI2C_MasterTransferAbortEDMA(lpi2c_master_edma_transfer_handle_t *psHandle)
{
    /* Catch when there is not an active transfer. */
    if (!psHandle->bIsBusy)
    {
        return kStatus_LPI2C_Idle;
    }

    /* Terminate DMA transfers. */
    EDMA_TransferAbort(&psHandle->sRxDmaHandle);
    EDMA_TransferAbort(&psHandle->sTxDmaHandle);

    /* Reset fifos. */
    psHandle->base->MCR |= LPI2C_MCR_RRF_MASK | LPI2C_MCR_RTF_MASK;

    /* Send a stop command to finalize the transfer. */
    psHandle->base->MTDR = (uint16_t)kStopCmd;

    /* Reset handle. */
    psHandle->bIsBusy = false;

    return kStatus_Success;
}

/*!
 * @brief DMA completion callback.
 * @param psDmaHandle DMA channel handle for the channel that completed.
 * @param pUserData User data associated with the channel handle. For this callback, the user data is the
 *      LPI2C DMA driver handle.
 * @param bIsTransferDone Whether the DMA transfer has completed.
 * @param u32Tcds Number of TCDs that completed.
 */
static void LPI2C_MasterEDMACallback(edma_handle_t *psDmaHandle,
                                     void *pUserData,
                                     bool bIsTransferDone,
                                     uint32_t u32Tcds)
{
    lpi2c_master_edma_transfer_handle_t *psHandle = (lpi2c_master_edma_transfer_handle_t *)pUserData;

    if ((NULL == psHandle) || (false == bIsTransferDone))
    {
        return;
    }

    /* Check for errors. */
    status_t result = LPI2C_MasterCheckAndClearError(psHandle->base, LPI2C_MasterGetStatusFlags(psHandle->base));

    /* Done with this transaction. */
    psHandle->bIsBusy = false;

    if (0U == (psHandle->sTransfer.u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStopFlag))
    {
        /* Send a stop command to finalize the transfer. */
        psHandle->base->MTDR = (uint16_t)kStopCmd;
    }

    /* Invoke callback. */
    if (psHandle->pfCallback != NULL)
    {
        psHandle->completionStatus = result;
        psHandle->pfCallback(psHandle);
    }
}
