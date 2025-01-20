/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_i2c_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_i2c_dma"
#endif

/*! @brief i2c master DMA transfer state. */
enum _i2c_master_dma_transfer_states
{
    kIdleState         = 0x0U, /*!< I2C bus idle. */
    kTransferDataState = 0x1U, /*!< 7-bit address check state. */
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief DMA callback for I2C master DMA driver.
 *
 * @param psHandle DMA handler for I2C master DMA driver
 * @param pUserData user param passed to the callback function
 */
static void I2C_MasterTransferCallbackDMA(dma_handle_t *psHandle, void *pUserData);

/*!
 * @brief Check and clear status operation.
 *
 * @param base I2C peripheral base address.
 * @param u32Status current i2c hardware status.
 * @retval kStatus_Success No error found.
 * @retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval kStatus_I2C_Nak Received Nak error.
 */
static status_t I2C_CheckAndClearError(I2C_Type *base, uint32_t u32Status);

/*!
 * @brief DMA config for I2C master driver.
 *
 * @param psHandle pointer to i2c_master_dma_transfer_handle_t structure which stores the transfer state
 */
static void I2C_MasterTransferDMAConfig(i2c_master_dma_transfer_handle_t *psHandle);

/*!
 * @brief Set up master transfer, send slave address and sub address(if any), wait until the
 * wait until address sent status return.
 *
 * @param psHandle pointer to i2c_master_dma_transfer_handle_t structure which stores the transfer state
 * @param psTransfer pointer to i2c_master_transfer_t structure
 */
static status_t I2C_InitTransferStateMachineDMA(i2c_master_dma_transfer_handle_t *psHandle,
                                                i2c_master_transfer_t *psTransfer);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Codes
 ******************************************************************************/

static void I2C_MasterTransferCallbackDMA(dma_handle_t *psHandle, void *pUserData)
{
    i2c_master_dma_transfer_handle_t *i2cTransferHandle = (i2c_master_dma_transfer_handle_t *)pUserData;
    I2C_Type *base                                      = i2cTransferHandle->base;
    status_t result                                     = kStatus_Success;
    uint8_t tmpReg;
    size_t tmpdataSize;

    /* Disable DMA. */
    I2C_EnableDMA(base, false);

    /* Send stop if kI2C_TransferNoStop flag is not asserted. */
    if (0U == (i2cTransferHandle->sTransfer.u8ControlFlagMask & (uint8_t)kI2C_TransferNoStopFlag))
    {
        if (i2cTransferHandle->sTransfer.eDirection == kI2C_MasterReceive)
        {
            /* Change to send NAK at the last byte. */
            I2C_SendAck(base, false);

            /* Wait the last data to be received. */
            while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
            {
            }

            /* Send stop signal. */
            result = I2C_MasterStop(base);

            /* Read the last data byte. */
            tmpReg                                                     = (uint8_t)base->D;
            tmpdataSize                                                = i2cTransferHandle->sTransfer.u16DataSize;
            *(i2cTransferHandle->sTransfer.pu8Data + tmpdataSize - 1U) = tmpReg;
        }
        else
        {
            /* Wait the last data to be sent. */
            while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
            {
            }

            /* Send stop signal. */
            result = I2C_MasterStop(base);
        }
    }
    else
    {
        if (i2cTransferHandle->sTransfer.eDirection == kI2C_MasterReceive)
        {
            /* Change to send NAK at the last byte. */
            I2C_SendAck(base, false);

            /* Wait the last data to be received. */
            while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
            {
            }

            /* Change direction to send. */
            I2C_SetTransferDirection(base, kI2C_Write);

            /* Read the last data byte. */
            tmpReg                                                     = (uint8_t)base->D;
            tmpdataSize                                                = i2cTransferHandle->sTransfer.u16DataSize;
            *(i2cTransferHandle->sTransfer.pu8Data + tmpdataSize - 1U) = tmpReg;
        }
    }

    i2cTransferHandle->u8State          = (uint8_t)kIdleState;
    i2cTransferHandle->completionStatus = result;
    if (NULL != i2cTransferHandle->pfCallback)
    {
        i2cTransferHandle->pfCallback(i2cTransferHandle);
    }
}

static status_t I2C_CheckAndClearError(I2C_Type *base, uint32_t u32Status)
{
    status_t result = kStatus_Success;

    /* Check arbitration lost. */
    if (0U != (u32Status & (uint32_t)kI2C_ArbitrationLostInterruptFlag))
    {
        /* Clear arbitration lost flag. */
        base->S = (uint8_t)kI2C_ArbitrationLostInterruptFlag;
        result  = kStatus_I2C_ArbitrationLost;
    }
    /* Check NAK */
    else if (0U != (u32Status & (uint32_t)kI2C_ReceiveNakFlag))
    {
        result = kStatus_I2C_Nak;
    }
    else
    {
        /* Add this to fix MISRA C2012 rule15.7 issue: Empty else without comment. */
    }

    return result;
}

static status_t I2C_InitTransferStateMachineDMA(i2c_master_dma_transfer_handle_t *psHandle,
                                                i2c_master_transfer_t *psTransfer)
{
    assert(NULL != psHandle);
    assert(NULL != psTransfer);

    status_t result = kStatus_Success;

    if (psHandle->u8State != (uint8_t)kIdleState)
    {
        return kStatus_I2C_Busy;
    }
    else
    {
        I2C_Type *base                             = psHandle->base;
        i2c_master_transfer_direction_t eDirection = psTransfer->eDirection;

        /* Init the handle member. */
        psHandle->sTransfer = *psTransfer;

        /* Save total transfer size. */
        psHandle->u16TransferSize = psTransfer->u16DataSize;

        psHandle->u8State = (uint8_t)kTransferDataState;

        /* Clear all status before transfer. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StatusAllFlags);

        /* Change to send write address when it's a read operation with command. */
        if ((psTransfer->u8CommandSize > 0U) && (psTransfer->eDirection == kI2C_MasterReceive))
        {
            eDirection = kI2C_MasterTransmit;
        }

        /* If repeated start is requested, send repeated start. */
        if (0U != (psHandle->sTransfer.u8ControlFlagMask & (uint8_t)kI2C_TransferRepeatedStartFlag))
        {
            result = I2C_MasterRepeatedStart(base, psHandle->sTransfer.u8SlaveAddress, eDirection);
        }
        else /* For normal transfer, send start. */
        {
            result = I2C_MasterStart(base, psHandle->sTransfer.u8SlaveAddress, eDirection);
        }

        if (kStatus_Success != result)
        {
            return result;
        }

#if I2C_RETRY_TIMES
        uint32_t u32WaitTimes = I2C_RETRY_TIMES;
        while ((0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag)) && (0U != --u32WaitTimes))
        {
        }
        if (u32WaitTimes == 0)
        {
            return kStatus_I2C_Timeout;
        }
#else
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif

        /* Check if there's transfer error. */
        result = I2C_CheckAndClearError(base, base->S);

        /* Return if error. */
        if (kStatus_Success != result)
        {
            if (result == kStatus_I2C_Nak)
            {
                result = kStatus_I2C_Addr_Nak;

                if (I2C_MasterStop(base) != kStatus_Success)
                {
                    result = kStatus_I2C_Timeout;
                }
                psHandle->completionStatus = result;
                if (NULL != psHandle->pfCallback)
                {
                    (psHandle->pfCallback)(psHandle);
                }
            }

            return result;
        }

        /* Send subaddress. */
        if (0U != psHandle->sTransfer.u8CommandSize)
        {
            do
            {
                /* Clear interrupt pending flag. */
                I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

                psHandle->sTransfer.u8CommandSize--;
                I2C_WriteByte(base, *psHandle->sTransfer.pu8Command++);

                /* Wait until data transfer complete. */
#if I2C_RETRY_TIMES
                u32WaitTimes = I2C_RETRY_TIMES;
                while ((0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag)) &&
                       (0U != --u32WaitTimes))
                {
                }
                if (u32WaitTimes == 0)
                {
                    return kStatus_I2C_Timeout;
                }
#else
                while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
                {
                }
#endif

                /* Check if there's transfer error. */
                result = I2C_CheckAndClearError(base, base->S);

                if (0 != result)
                {
                    return result;
                }

            } while (psHandle->sTransfer.u8CommandSize > 0U);

            if (psHandle->sTransfer.eDirection == kI2C_MasterReceive)
            {
                /* Clear pending flag. */
                I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

                /* Send repeated start and slave address. */
                result = I2C_MasterRepeatedStart(base, psHandle->sTransfer.u8SlaveAddress, kI2C_MasterReceive);

                if (0 != result)
                {
                    return result;
                }

                /* Wait until data transfer complete. */
#if I2C_RETRY_TIMES
                u32WaitTimes = I2C_RETRY_TIMES;
                while ((0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag)) &&
                       (0U != --u32WaitTimes))
                {
                }
                if (u32WaitTimes == 0)
                {
                    return kStatus_I2C_Timeout;
                }
#else
                while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
                {
                }
#endif

                /* Check if there's transfer error. */
                result = I2C_CheckAndClearError(base, base->S);

                if (0 != result)
                {
                    return result;
                }
            }
        }

        /* Clear pending flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);
    }

    return result;
}

static void I2C_MasterTransferDMAConfig(i2c_master_dma_transfer_handle_t *psHandle)
{
    I2C_Type *base                                = psHandle->base;
    dma_channel_transfer_config_t sTransferConfig = {0};

    if (psHandle->sTransfer.eDirection == kI2C_MasterReceive)
    {
        sTransferConfig.u32SrcAddr           = (uint32_t)I2C_GetDataRegAddr(base);
        sTransferConfig.u32DstAddr           = (uint32_t)psHandle->sTransfer.pu8Data;
        sTransferConfig.eEnableSrcIncrement  = kDMA_ChannelAddressFix;
        sTransferConfig.eEnableDestIncrement = kDMA_ChannelAddressIncrement;
    }
    else
    {
        sTransferConfig.u32SrcAddr           = (uint32_t)&psHandle->sTransfer.pu8Data[1];
        sTransferConfig.u32DstAddr           = (uint32_t)I2C_GetDataRegAddr(base);
        sTransferConfig.eEnableSrcIncrement  = kDMA_ChannelAddressIncrement;
        sTransferConfig.eEnableDestIncrement = kDMA_ChannelAddressFix;
    }

    sTransferConfig.u32TransferSize                 = (uint32_t)psHandle->sTransfer.u16DataSize - 1UL;
    sTransferConfig.eSrcWidthOfEachTransfer         = kDMA_ChannelTransferWidth8Bits;
    sTransferConfig.eDstWidthOfEachTransfer         = kDMA_ChannelTransferWidth8Bits;
    sTransferConfig.eSrcAddrModulo                  = kDMA_ChannelModuloDisable;
    sTransferConfig.eDstAddrModulo                  = kDMA_ChannelModuloDisable;
    sTransferConfig.bEnablAutoStopPeripheralRequest = true;
    sTransferConfig.bEnableAutoAlign                = false;
    sTransferConfig.bEnableCycleSteal               = true;
    sTransferConfig.bEnableInterrupt                = true;

    (void)DMA_TransferChannelSubmit(&psHandle->sDmaHandle, &sTransferConfig);
    DMA_TransferChannelStart(&psHandle->sDmaHandle, true);
}

/*!
 * brief Initializes the I2C handle which is used in transactional functions.
 *
 * param base I2C peripheral base address.
 * param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 * param pfCallback A pointer to the user callback function.
 * param pUserData A user parameter passed to the callback function.
 * param dmaBase DMA base address.
 * param eChannel DMA channel for master transfer.
 */
void I2C_MasterCreateDMAHandle(I2C_Type *base,
                               i2c_master_dma_transfer_handle_t *psHandle,
                               i2c_master_dma_transfer_callback_t pfCallback,
                               void *pUserData,
                               DMA_Type *dmaBase,
                               dma_channel_t eChannel)
{
    assert(NULL != psHandle);

    /* Zero handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Set the user callback and pUserData. */
    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;
    psHandle->u8State    = (uint8_t)kIdleState;

    /* Configure TX. */
    DMA_TransferChannelCreateHandle(dmaBase, &psHandle->sDmaHandle, eChannel, I2C_MasterTransferCallbackDMA, psHandle);
}

/*!
 * brief Performs a master DMA non-blocking transfer on the I2C bus.
 *
 * param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 * param psTransfer A pointer to the transfer structure of i2c_master_transfer_t.
 * retval kStatus_Success Successfully completed the data transmission.
 * retval kStatus_I2C_Busy A previous transmission is still not finished.
 * retval kStatus_I2C_Timeout Transfer error, waits for a signal timeout.
 * retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * retval kStataus_I2C_Nak Transfer error, receive NAK during transfer.
 */
status_t I2C_MasterTransferDMA(i2c_master_dma_transfer_handle_t *psHandle, i2c_master_transfer_t *psTransfer)
{
    assert(NULL != psHandle);
    assert(NULL != psTransfer);

    status_t result;
    uint8_t tmpReg;
    I2C_Type *base = psHandle->base;

    /* Disable dma. */
    I2C_EnableDMA(base, false);
    /* Enable module. */
    I2C_Enable(base, true);

    /* Send address and command buffer(if there is), until send data phase or receive data phase. */
    result = I2C_InitTransferStateMachineDMA(psHandle, psTransfer);

    if (result != kStatus_Success)
    {
        /* Send stop if received Nak. */
        if (result == kStatus_I2C_Nak)
        {
            if (I2C_MasterStop(base) != kStatus_Success)
            {
                result = kStatus_I2C_Timeout;
            }
        }

        /* Reset the state to idle state. */
        psHandle->u8State = (uint8_t)kIdleState;

        return result;
    }

    /* Configure dma transfer. */
    /* For i2c send, need to send 1 byte first to trigger the dma, for i2c read,
    need to send stop before reading the last byte, so the dma transfer size should
    be (xSize - 1). */
    if (psHandle->sTransfer.u16DataSize > 1U)
    {
        I2C_MasterTransferDMAConfig(psHandle);
        if (psHandle->sTransfer.eDirection == kI2C_MasterReceive)
        {
            /* Change direction for receive. */
            I2C_SetTransferDirection(base, kI2C_Read);

            /* Read dummy to release the bus. */
            (void)base->D;

            /* Enabe dma transfer. */
            I2C_EnableDMA(base, true);
        }
        else
        {
            /* Enable dma transfer. */
            I2C_EnableDMA(base, true);

            /* Send the first data. */
            I2C_WriteByte(base, *psHandle->sTransfer.pu8Data);
        }
    }
    else /* If transfer size is 1, use polling method. */
    {
        if (psHandle->sTransfer.eDirection == kI2C_MasterReceive)
        {
            tmpReg = (uint8_t)base->C1;

            /* Change direction to Rx. */
            tmpReg &= ~(uint8_t)I2C_C1_TX_MASK;

            /* Configure send NAK */
            tmpReg |= I2C_C1_TXAK_MASK;

            base->C1 = tmpReg;

            /* Read dummy to release the bus. */
            (void)base->D;
        }
        else
        {
            base->D = *psHandle->sTransfer.pu8Data;
        }

        /* Wait until data transfer complete. */
#if I2C_RETRY_TIMES
        uint32_t u32WaitTimes = I2C_RETRY_TIMES;
        while ((0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag)) && (0U != --u32WaitTimes))
        {
        }
        if (u32WaitTimes == 0)
        {
            return kStatus_I2C_Timeout;
        }
#else
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif

        /* Clear pending flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);
        /* Send stop if kI2C_TransferNoStop flag is not asserted. */
        if (0U == (psHandle->sTransfer.u8ControlFlagMask & (uint8_t)kI2C_TransferNoStopFlag))
        {
            result = I2C_MasterStop(base);
        }
        else
        {
            /* Change direction to send. */
            I2C_SetTransferDirection(base, kI2C_Write);
        }

        /* Read the last byte of data. */
        if (psHandle->sTransfer.eDirection == kI2C_MasterReceive)
        {
            tmpReg                       = (uint8_t)base->D;
            *psHandle->sTransfer.pu8Data = tmpReg;
        }

        /* Reset the state to idle. */
        psHandle->u8State = (uint8_t)kIdleState;
    }

    return result;
}

/*!
 * brief Gets a master transfer status during the DMA non-blocking transfer.
 *
 * param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 * param pu16Count A number of bytes transferred by the non-blocking transaction.
 */
status_t I2C_MasterTransferGetCountDMA(i2c_master_dma_transfer_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(NULL != psHandle);

    if (NULL == pu16Count)
    {
        return kStatus_InvalidArgument;
    }

    if ((uint8_t)kIdleState != psHandle->u8State)
    {
        *pu16Count = (psHandle->u16TransferSize - (uint16_t)DMA_GetChannelRemainingBytes(
                                                      psHandle->sDmaHandle.psBase, psHandle->sDmaHandle.eChannel));
    }
    else
    {
        *pu16Count = psHandle->u16TransferSize;
    }

    return kStatus_Success;
}

/*!
 * brief Aborts a master DMA non-blocking transfer early.
 *
 * param psHandle A pointer to the i2c_master_dma_transfer_handle_t structure.
 */
void I2C_MasterTransferAbortDMA(i2c_master_dma_transfer_handle_t *psHandle)
{
    /* Stop transfer. */
    DMA_TransferChannelAbort(&psHandle->sDmaHandle);

    /* Disable dma transfer. */
    I2C_EnableDMA(psHandle->base, false);

    /* Reset the state to idle. */
    psHandle->u8State = (uint8_t)kIdleState;
}
