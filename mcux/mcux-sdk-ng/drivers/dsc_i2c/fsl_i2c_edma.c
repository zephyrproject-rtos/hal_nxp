/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_i2c_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_i2c_edma"
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
 * @brief EDMA callback for I2C master EDMA driver.
 *
 * @param psHandle EDMA handler for I2C master EDMA driver
 * @param pUserData user param passed to the callback function
 * @param bTransferDone True for transfer is done.
 * @param u32Tcds Next tcd descriptor.
 */
static void I2C_MasterTransferCallbackEDMA(edma_handle_t *psHandle,
                                           void *pUserData,
                                           bool bTransferDone,
                                           uint32_t u32Tcds);

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
 * @brief EDMA config for I2C master driver.
 *
 * @param base I2C peripheral base address.
 * @param psHandle pointer to i2c_master_edma_transfer_handle_t structure which stores the transfer state
 */
static void I2C_MasterTransferEDMAConfig(i2c_master_edma_transfer_handle_t *psHandle);

/*!
 * @brief Set up master transfer, send slave address and sub address(if any), wait until the
 * wait until address sent status return.
 *
 * @param psHandle pointer to i2c_master_edma_transfer_handle_t structure which stores the transfer state
 * @param psTransfer pointer to i2c_master_transfer_t structure
 */
static status_t I2C_InitTransferStateMachineEDMA(i2c_master_edma_transfer_handle_t *psHandle,
                                                 i2c_master_transfer_t *psTransfer);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Codes
 ******************************************************************************/

static void I2C_MasterTransferCallbackEDMA(edma_handle_t *psHandle,
                                           void *pUserData,
                                           bool bTransferDone,
                                           uint32_t u32Tcds)
{
    i2c_master_edma_transfer_handle_t *i2cTransferHandle = (i2c_master_edma_transfer_handle_t *)pUserData;
    I2C_Type *base                                       = i2cTransferHandle->base;
    status_t result                                      = kStatus_Success;
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
            tmpReg                                                 = (uint8_t)base->D;
            tmpdataSize                                            = i2cTransferHandle->sTransfer.u16DataSize;
            i2cTransferHandle->sTransfer.pu8Data[tmpdataSize - 1U] = tmpReg;
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
            tmpReg                                                 = (uint8_t)base->D;
            tmpdataSize                                            = i2cTransferHandle->sTransfer.u16DataSize;
            i2cTransferHandle->sTransfer.pu8Data[tmpdataSize - 1U] = tmpReg;
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

static status_t I2C_InitTransferStateMachineEDMA(i2c_master_edma_transfer_handle_t *psHandle,
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

static void I2C_MasterTransferEDMAConfig(i2c_master_edma_transfer_handle_t *psHandle)
{
    edma_channel_transfer_config_t sTransferConfig;
    I2C_Type *base = psHandle->base;
    uint32_t u32SrcByteAddr;
    uint32_t u32DestByteAddr;
    edma_channel_transfer_type_t eTransferType;

    if (psHandle->sTransfer.eDirection == kI2C_MasterReceive)
    {
        u32SrcByteAddr  = I2C_GetDataRegAddr(base);
        u32DestByteAddr = (uint32_t)(uint8_t *)psHandle->sTransfer.pu8Data;
        eTransferType   = kEDMA_ChannelTransferPeripheralToMemory;
    }
    else
    {
        u32SrcByteAddr  = (uint32_t)(uint8_t *)&psHandle->sTransfer.pu8Data[1];
        u32DestByteAddr = I2C_GetDataRegAddr(base);
        eTransferType   = kEDMA_ChannelTransferMemoryToPeripheral;
    }

    EDMA_GetChannelDefaultTransferConfig(&sTransferConfig, u32SrcByteAddr, u32DestByteAddr, 1U,
                                         ((uint32_t)psHandle->sTransfer.u16DataSize - 1UL),
                                         kEDMA_ChannelTransferWidth8Bits, eTransferType);
    sTransferConfig.u16EnabledInterruptMask = (uint16_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable;
    (void)EDMA_TransferSubmitSingleTransfer(&psHandle->sEdmaHandle, &sTransferConfig);
    EDMA_TransferStart(&psHandle->sEdmaHandle);
}

/*!
 * brief Initializes the I2C handle which is used in transactional functions.
 *
 * param base I2C peripheral base address.
 * param psHandle A pointer to the i2c_master_edma_transfer_handle_t structure.
 * param pfCallback A pointer to the user callback function.
 * param pUserData A user parameter passed to the callback function.
 * param edmaBase Edma base address.
 * param eEdmaChannel eDMA channel for master transfer.
 */
void I2C_MasterCreateEDMAHandle(I2C_Type *base,
                                i2c_master_edma_transfer_handle_t *psHandle,
                                i2c_master_edma_transfer_callback_t pfCallback,
                                void *pUserData,
                                DMA_Type *edmaBase,
                                edma_channel_t eEdmaChannel)
{
    assert(NULL != psHandle);
    assert(0U == (((uint32_t)(uint8_t *)psHandle) & (sizeof(edma_channel_tcd_t) - 1U)));

    /* Zero handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Set the user callback and pUserData. */
    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;
    psHandle->u8State    = (uint8_t)kIdleState;

    /* Configure TX. */
    EDMA_TransferCreateHandle(edmaBase, &psHandle->sEdmaHandle, eEdmaChannel, &psHandle->sTcd, 1,
                              I2C_MasterTransferCallbackEDMA, psHandle);
}

/*!
 * brief Performs a master eDMA non-blocking transfer on the I2C bus.
 *
 * param psHandle A pointer to the i2c_master_edma_transfer_handle_t structure.
 * param psTransfer A pointer to the transfer structure of i2c_master_transfer_t.
 * retval kStatus_Success Successfully completed the data transmission.
 * retval kStatus_I2C_Busy A previous transmission is still not finished.
 * retval kStatus_I2C_Timeout Transfer error, waits for a signal timeout.
 * retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * retval kStataus_I2C_Nak Transfer error, receive NAK during transfer.
 */
status_t I2C_MasterTransferEDMA(i2c_master_edma_transfer_handle_t *psHandle, i2c_master_transfer_t *psTransfer)
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
    result = I2C_InitTransferStateMachineEDMA(psHandle, psTransfer);

    if (0 != result)
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
        I2C_MasterTransferEDMAConfig(psHandle);
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
 * brief Gets a master transfer status during the eDMA non-blocking transfer.
 *
 * param psHandle A pointer to the i2c_master_edma_transfer_handle_t structure.
 * param pu16Count A number of bytes transferred by the non-blocking transaction.
 */
status_t I2C_MasterTransferGetCountEDMA(i2c_master_edma_transfer_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(NULL != psHandle);

    if (NULL == pu16Count)
    {
        return kStatus_InvalidArgument;
    }

    if ((uint8_t)kIdleState != psHandle->u8State)
    {
        *pu16Count = (psHandle->u16TransferSize - (uint16_t)EDMA_GetChannelRemainingMajorLoopCount(
                                                      psHandle->sEdmaHandle.psBase, psHandle->sEdmaHandle.eChannel));
    }
    else
    {
        *pu16Count = psHandle->u16TransferSize;
    }

    return kStatus_Success;
}

/*!
 * brief Aborts a master eDMA non-blocking transfer early.
 *
 * param psHandle A pointer to the i2c_master_edma_transfer_handle_t structure.
 */
void I2C_MasterTransferAbortEDMA(i2c_master_edma_transfer_handle_t *psHandle)
{
    /* Disable dma transfer. */
    I2C_EnableDMA(psHandle->base, false);
    /* Stop transfer. */
    EDMA_TransferAbort(&psHandle->sEdmaHandle);
    /* Reset the state to idle. */
    psHandle->u8State = (uint8_t)kIdleState;
}
