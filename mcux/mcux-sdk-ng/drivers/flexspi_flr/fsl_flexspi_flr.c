/*
 * Copyright 2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexspi_flr.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexspi_flr"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief Typedef for interrupt handler. */
typedef void (*flexspi_slv_isr_t)(FLEXSPI_SLV_Type *base, flexspi_slv_handle_t *handle);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void FLEXSPI_SLV_Memset(void *src, uint8_t value, size_t length);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to Flexspi Follower bases for each instance. */
static FLEXSPI_SLV_Type *const s_flexspiSlvBases[] = FLEXSPI_SLV_BASE_PTRS;

/*! @brief Pointers to Flexspi Follower IRQ number for each instance. */
static const IRQn_Type s_flexspiSlvIrqs[] = FLEXSPI_SLV_IRQS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Clock name array */
static const clock_ip_name_t s_flexspiSlvClock[] = FLEXSPI_SLV_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Pointers to Flexspi Follower handles for each instance. */
static flexspi_slv_handle_t *s_flexspiSlvHandle[ARRAY_SIZE(s_flexspiSlvBases)];

/*! @brief Pointer to Flexspi Follower IRQ handler. */
static flexspi_slv_isr_t s_flexspiSlvIsr;

/*******************************************************************************
 * Code
 ******************************************************************************/
/* To avoid compiler opitimizing this API into memset() in library. */
#if defined(__ICCARM__)
#pragma optimize = none
#endif /* defined(__ICCARM__) */

static void FLEXSPI_SLV_Memset(void *src, uint8_t value, size_t length)
{
    assert(src != NULL);
    uint8_t *p = src;

    for (uint32_t i = 0U; i < length; i++)
    {
        *p = value;
        p++;
    }
}

/*!
 * brief Gets the index of the FLEXSPI FOLLOWER in the array according to the base address.
 *
 * param base FLEXSPI FOLLOWER peripheral base address.
 */
uint32_t FLEXSPI_SLV_GetInstance(FLEXSPI_SLV_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_flexspiSlvBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_flexspiSlvBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_flexspiSlvBases));

    return instance;
}

/*!
 * brief Initializes the FLEXSPI FOLLOWER module and internal state.
 *
 * This function enables the clock for FLEXSPI FOLLOWER and also configures the FLEXSPI
 * FOLLOWER with the input configure parameters. Users should call this function before
 * any FLEXSPI FOLLOWER operations.
 *
 * param base FLEXSPI FOLLOWER peripheral base address.
 * param config FLEXSPI FOLLOWER configure structure.
 */
void FLEXSPI_SLV_Init(FLEXSPI_SLV_Type *base, const flexspi_slv_config_t *config)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the flexspi follower clock */
    (void)CLOCK_EnableClock(s_flexspiSlvClock[FLEXSPI_SLV_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Reset peripheral before configuring it. */
    FLEXSPI_SLV_SoftwareReset(base);

    /* Set IO mode. */
    FLEXSPI_SLV_SetIOMode(base, config->ioMode);

    /* Set RW base address and range */
    FLEXSPI_SLV_SetRWCmdBaseAddr(base, (config->baseAddr1 >> 16U), (config->baseAddr2 >> 16U));
    FLEXSPI_SLV_UpdateRWCmdBaseRange(base);

    FLEXSPI_SLV_SetAddrRange(base, 0x0, config->addrRange1);
    FLEXSPI_SLV_SetAddrRange(base, 0x1, config->addrRange2);
    FLEXSPI_SLV_UpdateRWCmdBaseRange(base);

    /* Set read water mark level */
    FLEXSPI_SLV_SetReadWatermark(base, config->rxWatermark, true);
    FLEXSPI_SLV_SetReadFetchSize(base, config->rxFetchSize);

    /* Set write water mark level */
    FLEXSPI_SLV_SetWriteWatermark(base, config->txWatermark);

    /* Clear CS mask. */
    FLEXSPI_SLV_MaskChipSelect(base, 0);

    /* Set the commands. */
    FLEXSPI_SLV_SetReadRegCommand(base, config->readRegCmd, config->readRegDummyCycle);
    FLEXSPI_SLV_SetWriteRegCommand(base, config->writeRegCmd);
    FLEXSPI_SLV_SetReadMemCommand(base, 0, config->readMemCmd1, config->readMemDummyCycle1);
    FLEXSPI_SLV_SetReadMemCommand(base, 1, config->readMemCmd2, config->readMemDummyCycle2);
    FLEXSPI_SLV_SetWriteMemCommand(base, 0, config->writeMemCmd1);
    FLEXSPI_SLV_SetWriteMemCommand(base, 1, config->writeMemCmd2);
}

/*!
 * brief Gets default settings for FLEXSPI FOLLOWER.
 *
 * param config FLEXSPI FOLLOWER configuration structure.
 */
void FLEXSPI_SLV_GetDefaultConfig(flexspi_slv_config_t *config)
{
    /* Initializes the configure structure to zero. */
    FLEXSPI_SLV_Memset(config, 0, sizeof(*config));

    config->baseAddr1   = 0;
    config->baseAddr2   = 0x1000;
    config->addrRange1  = 0;
    config->addrRange2  = 0;
    config->ioMode      = kFLEXSPI_SLV_IOMODE_SDRx4;
    config->rxFetchSize = kFLEXSPI_SLV_Read_Fetch_256Bytes;
    config->rxWatermark = 0;
    config->txWatermark = kFLEXSPI_SLV_Write_Watermark_128Bytes;
}

/*!
 * brief Deinitializes the FLEXSPI FOLLOWER module.
 *
 * Clears the FLEXSPI FOLLOWER state and FLEXSPI FOLLOWER module registers.
 *
 * param base FLEXSPI FOLLOWER peripheral base address.
 */
void FLEXSPI_SLV_Deinit(FLEXSPI_SLV_Type *base)
{
    /* Reset peripheral. */
    FLEXSPI_SLV_SoftwareReset(base);
}

/*!
 * brief Initializes the FLEXSPI FOLLOWER handle which is used in transactional functions.
 *
 * param base FLEXSPI FOLLOWER peripheral base address.
 * param handle Pointer to flexspi_slv_handle_t structure to store the interrupt state.
 * param callback Pointer to user callback function. Can be NULL.
 * param interruptMask Interrupt mask to enable during handle creation. Use enumeration values ORed.
 */
void FLEXSPI_SLV_InterruptCreateHandle(FLEXSPI_SLV_Type *base,
                                       flexspi_slv_handle_t *handle,
                                       flexspi_slv_callback_t callback,
                                       uint32_t interruptMask)
{
    assert(NULL != handle);

    uint32_t instance = FLEXSPI_SLV_GetInstance(base);

    (void)memset(handle, 0, sizeof(*handle));

    /* Set callback. */
    handle->callback = callback;

    /* Save the context in global variables to support the double weak mechanism. */
    s_flexspiSlvHandle[instance] = handle;
    s_flexspiSlvIsr              = FLEXSPI_SLV_HandleIRQ;

    /* Enable NVIC interrupt. */
    (void)EnableIRQ(s_flexspiSlvIrqs[instance]);

    FLEXSPI_SLV_EnableInterrupts(base, interruptMask);
    FLEXSPI_SLV_EnableMailInterrupt(base, true);
}

/*!
 * brief Master interrupt handler.
 *
 * param base FLEXSPI FOLLOWER peripheral base address.
 * param handle Pointer to flexspi_slv_handle_t structure.
 */
void FLEXSPI_SLV_HandleIRQ(FLEXSPI_SLV_Type *base, flexspi_slv_handle_t *handle)
{
    uint32_t status          = FLEXSPI_SLV_GetInterruptStatusFlags(base);
    uint32_t intEnableStatus = FLEXSPI_SLV_GetEnabledInterrupts(base);

    status &= intEnableStatus;
    if (0U != status)
    {
        FLEXSPI_SLV_ClearInterruptStatusFlags(base, status);
    }
    else if (FLEXSPI_SLV_GetEnabledMailInterrupt(base))
    {
        status |= (uint32_t)kFLEXSPI_SLV_MailInterruptFlag;
        FLEXSPI_SLV_ClearMailInterruptFlag(base);
    }
    else
    {
        /* Intentional empty. */
    }

    handle->intrMask = status;

    /* Check if interrupt is enabled and status is alerted. */
    if (handle->callback != NULL)
    {
        handle->callback(base, handle);
    }
}

void FLEXSPI_SLV_DriverIRQHandler(void);
void FLEXSPI_SLV_DriverIRQHandler(void)
{
    s_flexspiSlvIsr(s_flexspiSlvBases[0], s_flexspiSlvHandle[0]);
    SDK_ISR_EXIT_BARRIER;
}
