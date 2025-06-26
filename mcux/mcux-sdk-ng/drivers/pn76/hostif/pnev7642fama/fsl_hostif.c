/*
 * Copyright 2021-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_hostif.h"
#include "PN76_UtilsHelper.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_hostif"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define HOSTIF_I2C_CONTROL_MASK (HOSTIF_I2C_CONTROL_I2C_ADDR_MASK         | \
                                 HOSTIF_I2C_CONTROL_I2C_HS_ENABLE_MASK    | \
                                 HOSTIF_I2C_CONTROL_I2C_RESET_ENABLE_MASK | \
                                 HOSTIF_I2C_CONTROL_I2C_DEVID_ENABLE_MASK | \
                                 HOSTIF_I2C_CONTROL_I2C_REV_ID_MASK)

#define HOSTIF_SPI_CONTROL_MASK (HOSTIF_SPI_CONTROL_SPI_CPOL_MASK | HOSTIF_SPI_CONTROL_SPI_CPHA_MASK)

#define HOSTIF_I3C_CONFIG_MASK (HOSTIF_I3C_CONFIG_SLVENA_MASK    | \
                                HOSTIF_I3C_CONFIG_NACK_MASK      | \
                                HOSTIF_I3C_CONFIG_DDROK_MASK     | \
                                HOSTIF_I3C_CONFIG_TSPOK_MASK     | \
                                HOSTIF_I3C_CONFIG_TSLOK_MASK     | \
                                HOSTIF_I3C_CONFIG_IDRAND_MASK    | \
                                HOSTIF_I3C_CONFIG_OFFLINE_MASK   | \
                                HOSTIF_I3C_CONFIG_OVF_NACK_MASK  | \
                                HOSTIF_I3C_CONFIG_SADDR_LSB_MASK | \
                                HOSTIF_I3C_CONFIG_SADDR_MSB_MASK)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Check the input memory block is in NS RAM regin.
 *
 * @param startAddr Start address of the memory block.
 * @param len Length of the memory block.
 * @return Return true if the memory block is in NS RAM region, otherwise return false.
 */
static bool HOSTIF_IsNsRamAddrValid(uint32_t startAddr, uint32_t len);

/*!
 * @brief Validate whether the memory block is OK for TX/RX buffer.
 *
 * @param startAddr Start address of the memory block.
 * @param len Length of the memory block.
 * @return Return true if the memory block is OK, otherwise false.
 */
static bool HOSTIF_IsMemValidBuffer(uint32_t startAddr, uint32_t len);

/*!
 * @brief Sets HOSTIF rx buffer config without parameter check.
 *
 * @param base HOSTIF base address.
 * @param startAddress Pointer to the Dword aligned buffer to which the data has to be saved.
 * @param maxSize Max Length of the data in bytes which can be received by the buffer.
 * @param bufferId Buffer ID of the register which should be configured.
 */
static void HOSTIF_SetRxBufferConfigNoCheck(HOSTIF_Type *base,
                                            uint8_t *startAddress,
                                            uint16_t maxSize,
                                            hostif_rx_buffer_id_t bufferId);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map HOSTIF instance number to base pointer. */
static HOSTIF_Type *const s_hostifBases[] = HOSTIF_BASE_PTRS;

/*! @brief Array to map HOSTIF instance number to IRQ number. */
static const IRQn_Type s_hostifIRQNumber[] = HOSTIF_IRQS;

/*! @brief Pointers to HOSTIF handles for each instance. */
static void *s_hostifHandle[ARRAY_SIZE(s_hostifBases)];

/*! @brief Start address of NS RAM. */
static uint32_t s_nsRamStartAddr = 0U;

/*! @brief Size of NS RAM. */
static uint32_t s_nsRamSize = 0U;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*
 * brief Check the input memory block is in NS RAM regin.
 *
 * param startAddr Start address of the memory block.
 * param len Length of the memory block.
 * return Return true if the memory block is in NS RAM region, otherwise return false.
 */
static bool HOSTIF_IsNsRamAddrValid(uint32_t startAddr, uint32_t len)
{
    bool ret;

    if ((startAddr >= s_nsRamStartAddr) && ((startAddr + len) <= (s_nsRamStartAddr + s_nsRamSize)))
    {
        ret = true;
    }
    else
    {
        ret = false;
    }

    return ret;
}

/*
 * brief Validate whether the memory block is OK for TX/RX buffer.
 *
 * param startAddr Start address of the memory block.
 * param len Length of the memory block.
 * return Return true if the memory block is OK, otherwise false.
 */
static bool HOSTIF_IsMemValidBuffer(uint32_t startAddr, uint32_t len)
{
    bool valid;

    /*
     * 1. The startAddress must be in NSRAM.
     * 2. startAddress must be 4 bytes aligned.
     * 3. Size need not be aligned to 4 bytes.
     * 4. Size can be anything apart from 0.
     * 5. maxSize is different it should <= 2047.
     */
    if (HOSTIF_IsNsRamAddrValid(startAddr, len) && /* Memory in NSRAM */
        ((startAddr & 0x03U) == 0U) &&             /* Address 4 bytes aligned. */
        (len > 0U) &&                              /* Length is not 0. */
        (len <= 2047U))                            /* Length <= 2047. */
    {
        valid = true;
    }
    else
    {
        valid = false;
    }

    return valid;
}

/*!
 * brief Get the HOSTIF instance from peripheral base address.
 *
 * param base HOSTIF peripheral base address.
 * return HOSTIF instance.
 */
static uint32_t HOSTIF_GetInstance(HOSTIF_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0U; instance < ARRAY_SIZE(s_hostifBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_hostifBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_hostifBases));

    return instance;
}

/*!
 * brief HOSTIF initialization
 *
 * param base HOSTIF base address.
 * param config Pointer to the HOSTIF configuration structure, see @ref _hostif_config for detail.
 */
status_t HOSTIF_Init(HOSTIF_Type *base, const hostif_config_t *config)
{
    assert(config != NULL);

    if (PN76_STATUS_SUCCESS != PN76_Get_NSRam_Addr_Len(&s_nsRamStartAddr, &s_nsRamSize))
    {
        return kStatus_Fail;
    }

    CLOCK_EnableClock(kCLOCK_Hostif);

    /* Disable all the interrupts */
    base->INT_CLR_ENABLE = 0xFFFFU;

    /* Clear the Status of the interrupt */
    base->INT_CLR_STATUS = 0xFFFFU;

    /* Disable HOSTIF. Also Disable CRC, Fifo Mode, RX UPD. Deassert Ext IRQ line */
    base->CONTROL = 0U;

    /* Avoid any Previous Setting for I2C, SPI and HSU interfaces */
    base->I2C_CONTROL = 0U;
    base->SPI_CONTROL = 0U;
    base->HSU_CONTROL = 0U;
    base->I3C_CONFIG  = 0U;

    /* Reset and disable all the Buffers*/
    base->BUFFER_RX0_CFG = HOSTIF_BUFFER_RX0_CFG_RX0_BUFFER_DISABLE_MASK;
    base->BUFFER_RX1_CFG = HOSTIF_BUFFER_RX1_CFG_RX1_BUFFER_DISABLE_MASK;
    base->BUFFER_RX2_CFG = HOSTIF_BUFFER_RX2_CFG_RX2_BUFFER_DISABLE_MASK;
    base->BUFFER_RX3_CFG = HOSTIF_BUFFER_RX3_CFG_RX3_BUFFER_DISABLE_MASK;

    /* Clear the data ready register */
    base->CLR_DATA_READY =
        (HOSTIF_CLR_DATA_READY_CLR_RX0_DATA_READY_MASK | HOSTIF_CLR_DATA_READY_CLR_RX1_DATA_READY_MASK |
         HOSTIF_CLR_DATA_READY_CLR_RX2_DATA_READY_MASK | HOSTIF_CLR_DATA_READY_CLR_RX3_DATA_READY_MASK |
         HOSTIF_CLR_DATA_READY_CLR_TX_DATA_READY_MASK);

    if (config->interface == kHOSTIF_SelectI2c)
    {
        base->I2C_CONTROL = (config->interfaceConfig.u32Config & HOSTIF_I2C_CONTROL_MASK);
    }
    else if (config->interface == kHOSTIF_SelectSpi)
    {
        base->SPI_CONTROL = (config->interfaceConfig.u32Config & HOSTIF_SPI_CONTROL_MASK);
    }
    else if (config->interface == kHOSTIF_SelectI3c)
    {
        base->I3C_CONFIG = (config->interfaceConfig.u32Config & HOSTIF_I3C_CONFIG_MASK);
    }
    else
    {
        /* Empty for MISRA. */
    }

    /* Select the corresponding Host Interface */
    PN76_Sys_PCRM_HifSelect((PN76_PCRM_HifSelect_t)config->interface);

    /* enable RX Length updated during reception */
    base->CONTROL |= (HOSTIF_CONTROL_RX0_UPD_ENABLE_MASK | HOSTIF_CONTROL_RX1_UPD_ENABLE_MASK |
                      HOSTIF_CONTROL_RX2_UPD_ENABLE_MASK | HOSTIF_CONTROL_RX3_UPD_ENABLE_MASK);

    /* Configure Inter-character timeout */
    base->TIC_TIMEOUT = config->timeOut;

    /* Configure Water Level */
    base->WATERLEVEL = config->waterMarkLevel;

    /* If requested, enable CRC */
    if (config->enableCrc)
    {
        base->CONTROL |= HOSTIF_CONTROL_CRC_ENABLE_MASK;
    }

    /* IRQ pin can be used for signalling Data ready to the Host.
     * Configure if IRQ pin will be controlled directly by HOSTIF HAL or higher layers */
    if (config->enableExtIrqCtrl)
    {
        base->CONTROL |= HOSTIF_CONTROL_EXT_IRQ_CTRL_ENABLE_MASK;
    }
    else
    {
        base->CONTROL &= ~HOSTIF_CONTROL_EXT_IRQ_CTRL_ENABLE_MASK;
    }

    /* Enable the HOSTIF after doing all the configurations */
    base->CONTROL |= HOSTIF_CONTROL_HIF_ENABLE_MASK;

    return kStatus_Success;
}

/*!
 * brief HOSTIF De-initialization
 *
 * param base HOSTIF base address.
 */
void HOSTIF_Deinit(HOSTIF_Type *base)
{
    uint32_t instance = HOSTIF_GetInstance(base);

    base->BUFFER_RX0_CFG |= HOSTIF_BUFFER_RX0_CFG_RX0_BUFFER_DISABLE_MASK;
    base->BUFFER_RX1_CFG |= HOSTIF_BUFFER_RX1_CFG_RX1_BUFFER_DISABLE_MASK;
    base->BUFFER_RX2_CFG |= HOSTIF_BUFFER_RX2_CFG_RX2_BUFFER_DISABLE_MASK;
    base->BUFFER_RX3_CFG |= HOSTIF_BUFFER_RX3_CFG_RX3_BUFFER_DISABLE_MASK;

    /* A delay of 2 Micro Second are need to complete the diabled */
    PN76_Common_Wait(2);

    /* Clear the data ready bit for the selected RX Buffer */
    base->CLR_DATA_READY =
        (HOSTIF_SET_DATA_READY_SET_RX0_DATA_READY_MASK | HOSTIF_SET_DATA_READY_SET_RX1_DATA_READY_MASK |
         HOSTIF_SET_DATA_READY_SET_RX2_DATA_READY_MASK | HOSTIF_SET_DATA_READY_SET_RX3_DATA_READY_MASK);

    /* Clear the TX data ready */
    base->CLR_DATA_READY = HOSTIF_CLR_DATA_READY_CLR_TX_DATA_READY_MASK;

    /* Clear the TX count */
    base->BUFFER_TX_LEN &= ~HOSTIF_BUFFER_TX_LEN_TX_LENGTH_MASK;

    /* Disable all the interrupts */
    base->INT_CLR_ENABLE = 0xFFFFU;

    /* Reset the Status of the interrupt */
    base->INT_CLR_STATUS = 0xFFFFU;

    /* De-Select the HOSTIF interface */
    PN76_Sys_PCRM_HifSelect((PN76_PCRM_HifSelect_t)kHOSTIF_SelectNone);

    /* Disable HOSTIF */
    base->CONTROL = 0U;
    CLOCK_DisableClock(kCLOCK_Hostif);

    /* Disable interrupt */
    (void)NVIC_ClearPendingIRQ(s_hostifIRQNumber[instance]);
    (void)DisableIRQ(s_hostifIRQNumber[instance]);
}

/*!
 * brief Gets HOSTIF default config
 *
 * param config Pointer to the HOSTIF configuration structure, see @ref _hostif_config for detail.
 */
void HOSTIF_GetDefaultConfig(hostif_config_t *config)
{
    assert(config != NULL);

    (void)memset(config, 0, sizeof(hostif_config_t));

    config->interface        = kHOSTIF_SelectI2c;
    config->timeOut          = 0U;
    config->waterMarkLevel   = 0U;
    config->enableCrc        = false;
    config->enableExtIrqCtrl = false;
}

/*!
 * brief Sets HOSTIF tx buffer config
 *
 * param base HOSTIF base address.
 * param startAddress Pointer to double word (4 byte) aligned memory.
 * param bufferLength Length of the buffer to be transmitted Maximum 1024 in for fixed format and 256 for free format.
 */
status_t HOSTIF_SetTxBufferConfig(HOSTIF_Type *base, uint8_t *startAddress, uint16_t bufferLength)
{
    status_t status;

    if (HOSTIF_IsMemValidBuffer((uint32_t)startAddress, bufferLength))
    {
        HOSTIF_SET_MASK((uint32_t)&base->BUFFER_TX_CFG, HOSTIF_BUFFER_TX_CFG_TX_START_ADDR_MASK,
                        (uint32_t)startAddress);
        HOSTIF_SET_MASK((uint32_t)&base->BUFFER_TX_LEN, HOSTIF_BUFFER_TX_LEN_TX_LENGTH_MASK, bufferLength);

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_InvalidArgument;
    }

    return status;
}

/*
 * brief Sets HOSTIF rx buffer config without parameter check.
 *
 * param base HOSTIF base address.
 * param startAddress Pointer to the Dword aligned buffer to which the data has to be saved.
 * param maxSize Max Length of the data in bytes which can be received by the buffer.
 * param bufferId Buffer ID of the register which should be configured.
 */
static void HOSTIF_SetRxBufferConfigNoCheck(HOSTIF_Type *base,
                                            uint8_t *startAddress,
                                            uint16_t maxSize,
                                            hostif_rx_buffer_id_t bufferId)
{
    uint32_t regValue = HOSTIF_BUFFER_RX0_CFG_RX0_BUFFER_DISABLE_MASK;

    regValue |=
        (HOSTIF_BUFFER_RX0_CFG_RX0_MAX_SIZE_MASK & ((uint32_t)maxSize << HOSTIF_BUFFER_RX0_CFG_RX0_MAX_SIZE_SHIFT));

    regValue |= (HOSTIF_BUFFER_RX0_CFG_RX0_START_ADDR_MASK & (uint32_t)startAddress);

    HOSTIF_SET_FIELD(((uint32_t)&base->BUFFER_RX0_CFG + (uint32_t)bufferId * 4U), regValue);

    HOSTIF_CLEAR_REG(((uint32_t)&base->BUFFER_RX0_CFG + ((uint32_t)bufferId * 4U)),
                     HOSTIF_BUFFER_RX0_CFG_RX0_BUFFER_DISABLE_SHIFT);
}

/*!
 * brief Sets HOSTIF rx buffer config
 *
 * param base HOSTIF base address.
 * param startAddress Pointer to the Dword aligned buffer to which the data has to be saved.
 * param maxSize Max Length of the data in bytes which can be received by the buffer.
 * param bufferId Buffer ID of the register which should be configured.
 */
status_t HOSTIF_SetRxBufferConfig(HOSTIF_Type *base,
                                  uint8_t *startAddress,
                                  uint16_t maxSize,
                                  hostif_rx_buffer_id_t bufferId)
{
    status_t status;

    if (HOSTIF_IsMemValidBuffer((uint32_t)startAddress, maxSize))
    {
        HOSTIF_SetRxBufferConfigNoCheck(base, startAddress, maxSize, bufferId);

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_InvalidArgument;
    }

    return status;
}

/*!
 * brief This API sends a buffer of length over the previously selected.
 *
 * param handle HOSTIF handle pointer.
 * param transfer Tx transfer pointer, see @ref hostif_transfer for detail.
 * return status Status of the HOSTIF send success or failure.
 */
status_t HOSTIF_SendNonBlocking(hostif_handle_t *handle, hostif_transfer_t *transfer)
{
    assert(handle != NULL);

    status_t status          = kStatus_Success;
    uint32_t enableInterrupt = HOSTIF_INT_SET_ENABLE_EOT_SET_ENABLE_MASK;

    if (PN76_Sys_PCRM_GetHifSelect() == E_PN76_PCRM_HIF_SEL_I3C)
    {
        // If Bit 0 is set, will request an event.
        handle->base->I3C_CTRL = HOSTIF_I3C_CTRL_EVENT_REQ(1U);
    }
    /* The SW status interprets the HW Status of Buffer Lock as Tx Going*/
    if (((HOSTIF_GetControlllerStatus(handle->base) &
          ((uint32_t)kHOSTIF_TxBufferLocked | (uint32_t)kHOSTIF_TxBufferPrefetchOk)) != 0U) ||
        ((HOSTIF_GetDataReadyStatus(handle->base) & (1UL << HOSTIF_DATA_READY_STATUS_TX_DATA_READY_SHIFT)) != 0U))
    {
        status = kHOSTIF_TxBufferBusy;
    }
    else
    {
        /* Configure TX Buffer Start Address and Length */
        status = HOSTIF_SetTxBufferConfig(handle->base, transfer->startAddress, transfer->bufferLength);

        if (kStatus_Success == status)
        {
            /* Clear the EOT Interrupt Status */
            HOSTIF_ClearInterruptsStatus(handle->base, HOSTIF_INT_CLR_STATUS_EOT_CLR_STATUS_MASK);

            /* Enable the send interrupt */
            if (handle->base->WATERLEVEL != 0U)
            {
                enableInterrupt |= (uint32_t)kHOSTIF_WaterLevelReachedStatus;
            }
            /* Enable the EOT interrupt */
            HOSTIF_EnableInterrupts(handle->base, enableInterrupt);

            /* Enable Tx buffer such that Transmission starts */
            HOSTIF_ClearDataReadyStatus(handle->base, HOSTIF_SET_DATA_READY_SET_TX_DATA_READY_MASK);

            /* set TX data ready */
            HOSTIF_SetDataReady(handle->base, (uint32_t)kHOSTIF_TxDataReady);

            /* A delay of 2.4 Micro Second are need to complete the prefetch */
            PN76_Common_Wait(3);

            /* Check whether the TX buffer prefetch completed to make sure the data are copied into the alloted buffer
             */
            if (((HOSTIF_GetControlllerStatus(handle->base) & (uint32_t)kHOSTIF_TxBufferPrefetchOk)) == 0U)
            {
                status = kHOSTIF_TxPrefetchFailed;
            }
        }
    }

    return status;
}

/*!
 * brief This API will allocate and enable RX buffers for reception from host.
 *
 * param handle HOSTIF handle pointer.
 * param transfer Rx transfer pointer, see @ref hostif_transfer for detail.
 * param count Count of the buffer, transfer should be the first address of the array pointer.
 */
status_t HOSTIF_ReceiveNonBlocking(hostif_handle_t *handle, hostif_transfer_t transfer[], uint8_t count)
{
    assert(handle != NULL);
    assert(count <= (uint32_t)FSL_FEATURE_HOSTIF_RX_BUFFER_COUNT);

    status_t status = kStatus_Success;
    uint32_t i, startIndex = 0U;

    /* Validate the memory. */
    for (i = 0U; i < count; i++)
    {
        if (!HOSTIF_IsMemValidBuffer((uint32_t)transfer[i].startAddress, transfer[i].bufferLength))
        {
            return kStatus_InvalidArgument;
        }

        if ((HOSTIF_IsRxBufferEnabled(handle->base, (hostif_rx_buffer_id_t)i) == true) ||
            ((HOSTIF_GetControlllerStatus(handle->base) & ((uint32_t)kHOSTIF_Rx0BufferLocked << i)) != 0U))
        {
            return kHOSTIF_RxBufferBusy;
        }
    }

    for (i = 0; i < count; i++)
    {
        /* Save the information in handle. */
        handle->rxCallback[i]      = transfer[i].rxCallback;
        handle->rxCallbackParam[i] = transfer[i].rxCallbackParam;

        /* Configure the Rx Configuration, parameter already checked at the begining of this function. */
        HOSTIF_SetRxBufferConfigNoCheck(handle->base, transfer[startIndex].startAddress,
                                        transfer[startIndex].bufferLength, (hostif_rx_buffer_id_t)i);

        /* Clear any previous RX Buffer EOR and Buffer over flow Interrupt Status */
        HOSTIF_ClearInterruptsStatus(
            handle->base, (1UL << (HOSTIF_INT_CLR_STATUS_RX0_EOR_CLR_STATUS_SHIFT + (uint32_t)i * 4U)) |
                              (1UL << (HOSTIF_INT_CLR_STATUS_RX0_BUFFER_OVERFLOW_CLR_STATUS_SHIFT + (uint32_t)i * 4U)));

        /* Enable the interrupts meant for this Rx Buffer */
        HOSTIF_EnableInterrupts(handle->base, (uint32_t)kHOSTIF_Rx0EorStatus << i);

        /* Clear the data ready bit for the selected RX Buffer */
        HOSTIF_ClearDataReadyStatus(handle->base, (1UL << (HOSTIF_CLR_DATA_READY_CLR_RX0_DATA_READY_SHIFT + i)));

        /* Enable the buffer after configuring it */
        HOSTIF_EnableRxBuffer(handle->base, (hostif_rx_buffer_id_t)i);

        startIndex++;
    }

    if (handle->base->WATERLEVEL != 0U)
    {
        HOSTIF_EnableInterrupts(handle->base, (uint32_t)kHOSTIF_WaterLevelReachedStatus);
    }

    return status;
}

/*!
 * brief Aborts HOSTIF receive
 *
 * param handle HOSTIF handle pointer.
 */
status_t HOSTIF_AbortReceive(hostif_handle_t *handle)
{
    uint16_t i;
    uint32_t regValue;
    status_t status = kStatus_Success;

    for (i = 0U; i < (uint32_t)FSL_FEATURE_HOSTIF_RX_BUFFER_COUNT; i++)
    {
        /* If the RX is not locked. */
        if ((HOSTIF_GetControlllerStatus(handle->base) & ((uint32_t)kHOSTIF_Rx0BufferLocked << i)) == 0U)
        {
            /* Disable the buffer before configuring the parameters to avoid buffer configuration change error*/
            HOSTIF_DisableRxBuffer(handle->base, (hostif_rx_buffer_id_t)i);

            /* Wait till the buffer is disabled - Ideally it will get disabled only when the buffer is unlocked */
            PN76_Common_Wait(2);

            /* Clear RX Buffer EOR and Buffer over flow Interrupt Status for the selected Rx Buffer*/
            regValue = (1UL << (HOSTIF_INT_CLR_STATUS_RX0_EOR_CLR_STATUS_SHIFT + (uint16_t)i * 4U));
            regValue |= (1UL << (HOSTIF_INT_CLR_STATUS_RX0_BUFFER_OVERFLOW_CLR_STATUS_SHIFT + (uint16_t)i * 4U));
            HOSTIF_ClearInterruptsStatus(handle->base, regValue);

            /* Disable the interrupts meant for this Rx Buffer */
            HOSTIF_DisableInterrupts(handle->base, regValue);
        }
        else
        {
            status = kStatus_Busy;
            break;
        }
    }

    return status;
}

/*!
 * brief Creates the HOSTIF handle.
 *
 * param base HOSTIF base address.
 * param handle HOSTIF handle pointer. The HOSTIF handle stores Callback function and parameters.
 * param callback HOSTIF callback function pointer.
 * param userData Parameter for callback function. If it is not needed, just set to NULL.
 *
 */
void HOSTIF_CreateHandle(HOSTIF_Type *base,
                         hostif_handle_t *handle,
                         hostif_transfer_callback_t callback,
                         void *userData)
{
    assert(handle != NULL);
    uint32_t instance;

    /* Zero the handle */
    (void)memset(handle, 0, sizeof(hostif_handle_t));

    handle->base     = base;
    handle->callback = callback;
    handle->userData = userData;

    instance = HOSTIF_GetInstance(base);

    s_hostifHandle[instance] = handle;

    /* Enable interrupt */
    (void)NVIC_ClearPendingIRQ(s_hostifIRQNumber[instance]);
    (void)EnableIRQ(s_hostifIRQNumber[instance]);
}

/*!
 * brief HOSTIF IRQ handle
 *
 * param base HOSTIF base address.
 */
void HOSTIF_HandleIRQ(hostif_handle_t *handle)
{
    uint32_t intStatus, transferredLength = 0U;
    uint16_t i;
    bool enableRxBuffer;
    status_t status = kHOSTIF_UnknownInterrupt;
    /* Read the interrupt Status register and Mask out the interrupts not enbaled */
    intStatus = ((handle->base->INT_STATUS) & (handle->base->INT_ENABLE));

    if ((intStatus & ~(HOSTIF_INT_STATUS_RX0_EOR_STATUS_MASK | HOSTIF_INT_STATUS_RX1_EOR_STATUS_MASK |
                       HOSTIF_INT_STATUS_RX2_EOR_STATUS_MASK | HOSTIF_INT_STATUS_RX3_EOR_STATUS_MASK |
                       HOSTIF_INT_STATUS_EOT_STATUS_MASK | HOSTIF_INT_STATUS_WATERLEVEL_REACHED_STATUS_MASK)) != 0U)
    {
        status = kHOSTIF_TransferError;
    }
    /* if the transmission is completed */
    else if ((intStatus & HOSTIF_INT_STATUS_EOT_STATUS_MASK) != 0UL)
    {
        status            = kHOSTIF_EndOfTransmit;
        transferredLength = handle->base->BUFFER_TX_LEN;
        /* clear ready bit */
        HOSTIF_ClearDataReadyStatus(handle->base, (uint32_t)kHOSTIF_TxDataReady);
        /* Disable the TX interrupt as it will be enabled again when TX starts */
        HOSTIF_DisableInterrupts(handle->base, HOSTIF_INT_CLR_ENABLE_EOT_CLR_ENABLE_MASK);
    }
    else if ((intStatus & HOSTIF_INT_STATUS_WATERLEVEL_REACHED_STATUS_MASK) != 0UL)
    {
        status            = kHOSTIF_ReachedWaterLevel;
        transferredLength = handle->base->WATERLEVEL;
    }
    else if ((intStatus & (HOSTIF_INT_STATUS_RX0_EOR_STATUS_MASK | HOSTIF_INT_STATUS_RX1_EOR_STATUS_MASK |
                           HOSTIF_INT_STATUS_RX2_EOR_STATUS_MASK | HOSTIF_INT_STATUS_RX3_EOR_STATUS_MASK)) != 0UL)
    {
        status = kHOSTIF_EndOfReception;

        /* if there is EOR on any of the RX buffer */
        for (i = 0U; i < (uint32_t)FSL_FEATURE_HOSTIF_RX_BUFFER_COUNT; i++)
        {
            enableRxBuffer = HOSTIF_IsRxBufferEnabled(handle->base, (hostif_rx_buffer_id_t)i);

            if (((intStatus & ((uint32_t)HOSTIF_INT_STATUS_RX0_EOR_STATUS_MASK << i)) != 0UL) &&
                (enableRxBuffer == true))
            {
                HOSTIF_DisableRxBuffer(handle->base, (hostif_rx_buffer_id_t)i);
                transferredLength = HOSTIF_GetRxBufferLength(handle->base, (hostif_rx_buffer_id_t)i);

                if (handle->rxCallback[i] != NULL)
                {
                    handle->rxCallback[i](handle, handle->rxCallbackParam[i], transferredLength, status,
                                          (hostif_rx_buffer_id_t)i);

                    /* RX finished, clear the callback. */
                    handle->rxCallback[i]      = NULL;
                    handle->rxCallbackParam[i] = NULL;
                }
            }
        }
    }
    else
    {
        /* Intentional empty */
    }

    if (kHOSTIF_EndOfReception != status)
    {
        handle->callback(handle, handle->userData, transferredLength, status);
    }

    /* Clear the status of the interrupts which are set */
    handle->base->INT_CLR_STATUS = intStatus;
}

void HOSTIF_DriverIRQHandler(void);
void HOSTIF_DriverIRQHandler(void)
{
    HOSTIF_HandleIRQ(s_hostifHandle[0]);
    SDK_ISR_EXIT_BARRIER;
}
