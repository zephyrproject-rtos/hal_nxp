/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spi_filter.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.spi_filter"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to SPI Filter bases for each instance. */
static SPI_FILTER_Type *const s_spiFilterBases[] = SPI_FILTER_BASE_PTRS;

/*! @brief Pointers to SPI Filter handles for each instance. */
static spi_filter_handle_t *s_spiFilterHandle[ARRAY_SIZE(s_spiFilterBases)];

/*! @brief Pointers to SPI Filter IRQ number for each instance. */
static const IRQn_Type s_spiFilterIRQ[] = {SPI_FILTER_IRQn};

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to SPI Filter clocks for each instance. */
static const clock_ip_name_t s_spiFilterClocks[] = SPIFILTER_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(SPIFILTER_RSTS)
/*! @brief Reset array */
static const reset_ip_name_t s_spiFilterResets[] = SPIFILTER_RSTS;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t SPI_FILTER_GetInstance(SPI_FILTER_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_spiFilterBases); instance++)
    {
        if (s_spiFilterBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_spiFilterBases));

    return instance;
}

static void SPI_FILTER_ConfigPort(SPI_FILTER_Type *base,
                                  spi_filter_port_t port,
                                  const spi_filter_port_config_t *portCfg)
{
    /* Select per-port CR mask aliases to reduce duplicated code. */
    const uint32_t CR_SINGLE_FLASH_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_SINGLE_FLASH_MASK : SPI_FILTER_CR_P1_SINGLE_FLASH_MASK;
    const uint32_t CR_SINGLE_FLASH_CHIP_SELECT_MASK = (port == kSPI_FilterPort0) ?
                                                          SPI_FILTER_CR_P0_SINGLE_FLASH_CHIP_SELECT_MASK :
                                                          SPI_FILTER_CR_P1_SINGLE_FLASH_CHIP_SELECT_MASK;
    const uint32_t CR_SINGLE_FLASH_ALLOW_WRITE_MASK = (port == kSPI_FilterPort0) ?
                                                          SPI_FILTER_CR_P0_SINGLE_FLASH_ALLOW_WRITE_MASK :
                                                          SPI_FILTER_CR_P1_SINGLE_FLASH_ALLOW_WRITE_MASK;
    const uint32_t CR_ACT_SEL_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_ACT_SEL_MASK : SPI_FILTER_CR_P1_ACT_SEL_MASK;
    const uint32_t CR_WE_BYTE_MD_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_WE_BYTE_MD_MASK : SPI_FILTER_CR_P1_WE_BYTE_MD_MASK;
    const uint32_t CR_PERM_BYTE_MD_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_PERM_BYTE_MD_MASK : SPI_FILTER_CR_P1_PERM_BYTE_MD_MASK;
    const uint32_t CR_FLT_EN_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_FLT_EN_MASK : SPI_FILTER_CR_P1_FLT_EN_MASK;
    const uint32_t CR_BYTE_MD_RST_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_BYTE_MD_RST_MASK : SPI_FILTER_CR_P1_BYTE_MD_RST_MASK;
    const uint32_t CR_BYTE_SEL_MD_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_BYTE_SEL_MD_MASK : SPI_FILTER_CR_P1_BYTE_SEL_MD_MASK;
    const uint32_t CR_BYTE_SEL_MASK =
        (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_BYTE_SEL_MASK : SPI_FILTER_CR_P1_BYTE_SEL_MASK;
    uint32_t value = base->CR;

    /* Clear all port-specific bits first. */
    value &= ~(CR_SINGLE_FLASH_MASK | CR_SINGLE_FLASH_CHIP_SELECT_MASK | CR_SINGLE_FLASH_ALLOW_WRITE_MASK |
               CR_ACT_SEL_MASK | CR_WE_BYTE_MD_MASK | CR_PERM_BYTE_MD_MASK | CR_FLT_EN_MASK | CR_BYTE_MD_RST_MASK |
               CR_BYTE_SEL_MD_MASK | CR_BYTE_SEL_MASK);

    if (portCfg->flashMode == kSPI_FilterDualFlashCS1Active)
    {
        value |= CR_ACT_SEL_MASK;
    }
    else if (portCfg->flashMode == kSPI_FilterSingleFlashCS0)
    {
        value |= CR_SINGLE_FLASH_MASK;
    }
    else if (portCfg->flashMode == kSPI_FilterSingleFlashCS1)
    {
        value |= (CR_SINGLE_FLASH_MASK | CR_SINGLE_FLASH_CHIP_SELECT_MASK);
    }
    else
    {
        /* Intentional empty */
    }

    value |= (portCfg->writeEnableAddrMode ? CR_WE_BYTE_MD_MASK : 0U) |
             (portCfg->lockAddrMode ? CR_PERM_BYTE_MD_MASK : 0U) | (portCfg->enableFilter ? CR_FLT_EN_MASK : 0U) |
             ((portCfg->addrMode == kSPI_Filter4ByteAddrMode) ? CR_BYTE_MD_RST_MASK : 0U) |
             (portCfg->singleFlashAllowWrite ? CR_SINGLE_FLASH_ALLOW_WRITE_MASK : 0U);

    if (portCfg->fixedAddrMode)
    {
        value |= CR_BYTE_SEL_MD_MASK;
        if (portCfg->addrMode == kSPI_Filter4ByteAddrMode)
        {
            value |= CR_BYTE_SEL_MASK;
        }
    }

    base->CR = value;
}

/*!
 * brief Initializes the SPI Filter peripheral.
 *
 * This function enables the SPI Filter clock and configures all filter ports
 * using the per-port configuration entries in `config->portConfig[]`.
 *
 * param base SPI Filter peripheral base address.
 * param config Pointer to the configuration structure.
 */
void SPI_FILTER_Init(SPI_FILTER_Type *base, const spi_filter_config_t *config)
{
    assert(config != NULL);

    uint32_t instance = SPI_FILTER_GetInstance(base);
    (void)instance;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_spiFilterClocks[instance]);
#endif

#if defined(SPIFILTER_RSTS)
    /* Reset the SPI Filter peripheral. */
    RESET_PeripheralReset(s_spiFilterResets[instance]);
#endif

    const spi_filter_port_config_t *portConfig;

    /* Configure each port from the per-port configuration structure. */
    for (uint32_t i = 0U; i < FSL_SPI_FILTER_PORT_COUNT; i++)
    {
        portConfig = &config->portConfig[i];

        SPI_FILTER_ConfigPort(base, (spi_filter_port_t)i, portConfig);
        SPI_FILTER_SetManufacturerID(base, (spi_filter_port_t)i, portConfig->manufacturer);
        SPI_FILTER_SetBypassMode(base, (spi_filter_port_t)i, portConfig->bypassMode);
        SPI_FILTER_SetMaxFlashSize(base, (spi_filter_port_t)i, portConfig->maxFlashSize);
    }
}

/*!
 * brief Deinitializes the SPI Filter peripheral.
 *
 * This function disables the SPI Filter peripheral and gates the SPI Filter clock.
 *
 * param base SPI Filter peripheral base address.
 */
void SPI_FILTER_Deinit(SPI_FILTER_Type *base)
{
    /* Disable SPI Filter for both ports. */
    SPI_FILTER_Enable(base, kSPI_FilterPort0, false);
    SPI_FILTER_Enable(base, kSPI_FilterPort1, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the SPI Filter clock. */
    uint32_t instance = SPI_FILTER_GetInstance(base);
    CLOCK_DisableClock(s_spiFilterClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the SPI Filter configuration structure to default values.
 *
 * param config Pointer to the configuration structure.
 */
void SPI_FILTER_GetDefaultConfig(spi_filter_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));
    for (uint32_t i = 0U; i < FSL_SPI_FILTER_PORT_COUNT; i++)
    {
        config->portConfig[i].enableFilter          = false;
        config->portConfig[i].flashMode             = kSPI_FilterDualFlashCS0Active;
        config->portConfig[i].addrMode              = kSPI_Filter3ByteAddrMode;
        config->portConfig[i].fixedAddrMode         = false;
        config->portConfig[i].lockAddrMode          = false;
        config->portConfig[i].bypassMode            = kSPI_FilterBypassNone;
        config->portConfig[i].manufacturer          = kSPI_FilterMacronix;
        config->portConfig[i].singleFlashAllowWrite = false;
        config->portConfig[i].writeEnableAddrMode   = false;
    }
}

/*!
 * brief Enables or disables the SPI filter.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 * param enable True to enable, false to disable.
 */
void SPI_FILTER_Enable(SPI_FILTER_Type *base, spi_filter_port_t port, bool enable)
{
    uint32_t enableMask = (port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_FLT_EN_MASK : SPI_FILTER_CR_P1_FLT_EN_MASK;

    if (enable)
    {
        base->CR |= enableMask;
    }
    else
    {
        base->CR &= ~enableMask;
    }
}

/*!
 * brief Sets the flash manufacturer ID for a specific port.
 *
 * This function configures the manufacturer ID which is used by the filter logic
 * to distinguish between opcodes that are common between manufacturers but have
 * different functions and therefore require different actions by the filter.
 *
 * Supported manufacturers:
 * - Macronix (kSPI_FilterMacronix)
 * - Winbond (kSPI_FilterWinbond)
 * - Micron (kSPI_FilterMicron)
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port (kSPI_FilterPort0 or kSPI_FilterPort1).
 * param manufacturerID Flash manufacturer ID. See @ref spi_filter_manufacturer_t.
 */
void SPI_FILTER_SetManufacturerID(SPI_FILTER_Type *base,
                                  spi_filter_port_t port,
                                  spi_filter_manufacturer_t manufacturerID)
{
    uint32_t shift    = (port == kSPI_FilterPort0) ? SPI_FILTER_TR_P0_MFG_ID_SHIFT : SPI_FILTER_TR_P1_MFG_ID_SHIFT;
    uint32_t mask     = (port == kSPI_FilterPort0) ? SPI_FILTER_TR_P0_MFG_ID_MASK : SPI_FILTER_TR_P1_MFG_ID_MASK;
    uint32_t regValue = base->TR;

    regValue &= ~mask;
    regValue |= ((uint32_t)manufacturerID << shift);
    base->TR = regValue;
}

/*!
 * brief Gets the current address byte mode.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 * return Current address mode.
 */
spi_filter_addr_mode_t SPI_FILTER_GetAddressMode(SPI_FILTER_Type *base, spi_filter_port_t port)
{
    uint32_t flag = (port == kSPI_FilterPort0) ? SPI_FILTER_SR_P0_BYTE_MODE_MASK : SPI_FILTER_SR_P1_BYTE_MODE_MASK;

    return ((base->SR & flag) != 0U) ? kSPI_Filter4ByteAddrMode : kSPI_Filter3ByteAddrMode;
}

/*!
 * brief Gets the flash dirty state.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 * return Flash dirty state.
 */
bool SPI_FILTER_GetFlashDirtyState(SPI_FILTER_Type *base, spi_filter_port_t port)
{
    uint32_t dirtyMask = ((port == kSPI_FilterPort0) ? SPI_FILTER_SR_P0_DIRTY_MASK : SPI_FILTER_SR_P1_DIRTY_MASK);

    return ((base->SR & dirtyMask) != 0U) ? true : false;
}

/*!
 * brief Clears the flash dirty state.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 */
void SPI_FILTER_ClearFlashDirtyState(SPI_FILTER_Type *base, spi_filter_port_t port)
{
    base->CR |= ((port == kSPI_FilterPort0) ? SPI_FILTER_CR_P0_DIRTY_CLR_MASK : SPI_FILTER_CR_P1_DIRTY_CLR_MASK);
}

/*!
 * brief Sets the bypass mode.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 * param mode Bypass mode to set.
 */
void SPI_FILTER_SetBypassMode(SPI_FILTER_Type *base, spi_filter_port_t port, spi_filter_bypass_mode_t mode)
{
    uint32_t enableBit = (port == kSPI_FilterPort0) ? SPI_FILTER_TR_P0_BYP_EN_MASK : SPI_FILTER_TR_P1_BYP_EN_MASK;
    uint32_t selectBit = (port == kSPI_FilterPort0) ? SPI_FILTER_TR_P0_BYP_SEL_MASK : SPI_FILTER_TR_P1_BYP_SEL_MASK;
    uint32_t regValue  = base->TR;

    regValue &= ~(enableBit | selectBit);

    switch (mode)
    {
        case kSPI_FilterBypassNone:
            break;

        case kSPI_FilterBypassCS0:
            regValue |= enableBit;
            break;

        case kSPI_FilterBypassCS1:
            regValue |= (enableBit | selectBit);
            break;

        default:
            assert(false);
            break;
    }

    base->TR = regValue;
}

/*!
 * brief Sets a filter read/write region.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 * param region Region number.
 * param config Pointer to region configuration.
 * retval kStatus_Success Region configured successfully.
 * retval kStatus_InvalidArgument Invalid region number or misaligned address.
 */
status_t SPI_FILTER_SetRegion(SPI_FILTER_Type *base,
                              spi_filter_port_t port,
                              uint8_t region,
                              const spi_filter_region_t *config)
{
    assert((region > 0U) && (region <= FSL_SPI_FILTER_FEATURE_ADDR_REGION_COUNT));
    assert(config != NULL);
    assert(((config->startAddr | config->endAddr) & 0xFFFFU) == 0U);

    volatile uint32_t *reg;
    uint32_t startAddr;
    uint32_t endAddr;

    reg = (port == kSPI_FilterPort0) ? &base->P0FAR1 : &base->P1FAR1;

    startAddr = (uint32_t)((config->startAddr >> 16U) & 0xFFFFU);
    endAddr   = (uint32_t)((config->endAddr >> 16U) & 0xFFFFU);

    reg[region - 1U] = (endAddr << SPI_FILTER_P0FAR1_ADDRESS_UPPER_LSBS_SHIFT) | startAddr;

    return kStatus_Success;
}

/*!
 * brief Clears all filter read/write regions.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 */
void SPI_FILTER_ClearAllRegions(SPI_FILTER_Type *base, spi_filter_port_t port)
{
    volatile uint32_t *reg = (port == kSPI_FilterPort0) ? &base->P0FAR1 : &base->P1FAR1;

    for (uint32_t i = 0U; i < FSL_SPI_FILTER_FEATURE_ADDR_REGION_COUNT; i++)
    {
        reg[i] = 0U;
    }
}

/*!
 * brief Configures a programmable opcode.
 *
 * param base SPI Filter peripheral base address.
 * param idx Opcode index.
 * param config Pointer to opcode configuration.
 * retval kStatus_Success Opcode configured successfully.
 * retval kStatus_InvalidArgument Invalid opcode index.
 */
status_t SPI_FILTER_ConfigureOpcode(SPI_FILTER_Type *base, uint8_t idx, const spi_filter_opcode_t *config)
{
    assert(config != NULL);

    volatile uint32_t *reg = &base->POPCODE0;
    uint32_t regValue;

    /* Validate parameters. */
    if ((idx >= FSL_SPI_FILTER_FEATURE_OPCODE_COUNT) || (config->state > 31U))
    {
        return kStatus_InvalidArgument;
    }

    regValue = SPI_FILTER_POPCODE0_PRG_OPCODE0(config->opcode) | SPI_FILTER_POPCODE0_FILTER_STATE0(config->state) |
               (config->filter8thBit ? SPI_FILTER_POPCODE0_FILTER_BIT0_MASK : 0U);

    reg[idx] = regValue;

    return kStatus_Success;
}

/*!
 * brief Gets the blocked opcode for a port.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 * return Last blocked opcode value.
 */
uint32_t SPI_FILTER_GetBlockedOpcode(SPI_FILTER_Type *base, spi_filter_port_t port)
{
    uint32_t value = (port == kSPI_FilterPort0) ? base->P0BOC : base->P1BOC;

    return ((value & SPI_FILTER_P0BOC_P0BOC_MASK) >> SPI_FILTER_P0BOC_P0BOC_SHIFT);
}

/*!
 * brief Sets the maximum flash size for address filtering.
 *
 * This function configures the maximum addressable flash size for the specified port.
 * Addresses beyond this size will be filtered/blocked by the SPI filter.
 * Set to 0 to disable the maximum flash size check.
 *
 * param base SPI Filter peripheral base address.
 * param port SPI Filter port.
 * param size Maximum flash size in bytes. Set to 0 to disable.
 */
void SPI_FILTER_SetMaxFlashSize(SPI_FILTER_Type *base, spi_filter_port_t port, uint32_t size)
{
    uint32_t mask;

    mask = (size == 0U) ? 0x0000U : (((size - 1U) >> 16U) & 0xFFFFU);

    /* Write to hardware register */
    if (port == kSPI_FilterPort0)
    {
        base->P0MAM = SPI_FILTER_P0MAM_P0MAML(mask & 0xFFU) | SPI_FILTER_P0MAM_P0MAMM((mask >> 8U) & 0xFFU);
    }
    else
    {
        base->P1MAM = SPI_FILTER_P1MAM_P1MAML(mask & 0xFFU) | SPI_FILTER_P1MAM_P1MAMM((mask >> 8U) & 0xFFU);
    }
}

/*!
 * brief Initializes the SPI Filter handle.
 *
 * param base SPI Filter peripheral base address.
 * param handle Pointer to the SPI Filter handle.
 * param port SPI Filter port.
 * param callback Callback function.
 * param userData User data.
 */
void SPI_FILTER_TransferCreateHandle(SPI_FILTER_Type *base,
                                     spi_filter_handle_t *handle,
                                     spi_filter_port_t port,
                                     spi_filter_callback_t callback,
                                     void *userData)
{
    assert(handle != NULL);

    uint32_t instance = SPI_FILTER_GetInstance(base);

    /* Zero the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Set callback and userData. */
    handle->callback = callback;
    handle->userData = userData;

    /* Save the context in global variables to support the double weak mechanism. */
    s_spiFilterHandle[instance] = handle;

    /* Enable interrupt in NVIC. */
    (void)EnableIRQ(s_spiFilterIRQ[instance]);
}

/*!
 * brief SPI Filter IRQ handle function.
 *
 * This function handles the SPI Filter IRQ request.
 *
 * param base SPI Filter peripheral base address.
 * param handle Pointer to the SPI Filter handle.
 */
void SPI_FILTER_HandleIRQ(SPI_FILTER_Type *base, spi_filter_handle_t *handle)
{
    assert(handle != NULL);

    uint32_t status = SPI_FILTER_GetInterruptStatus(base);

    if (((status & kSPI_FilterPort0F8InterruptFlag) != 0U) || ((status & kSPI_FilterPort0DirtyInterruptFlag) != 0U) ||
        ((status & kSPI_FilterPort0BlockInterruptFlag) != 0U) ||
        ((status & kSPI_FilterPort0ByteModeInterruptFlag) != 0U))
    {
        if (handle->callback != NULL)
        {
            handle->callback(base, kSPI_FilterPort0, status, handle->userData);
        }
    }

    if (((status & kSPI_FilterPort1F8InterruptFlag) != 0U) || ((status & kSPI_FilterPort1DirtyInterruptFlag) != 0U) ||
        ((status & kSPI_FilterPort1BlockInterruptFlag) != 0U) ||
        ((status & kSPI_FilterPort1ByteModeInterruptFlag) != 0U))
    {
        if (handle->callback != NULL)
        {
            handle->callback(base, kSPI_FilterPort1, status, handle->userData);
        }
    }
}

void SPI_FILTER_DriverIRQHandler(uint32_t instance);
void SPI_FILTER_DriverIRQHandler(uint32_t instance)
{
    if (instance > ARRAY_SIZE(s_spiFilterBases))
    {
        return;
    }

    SPI_FILTER_Type *base = s_spiFilterBases[instance];
    spi_filter_handle_t *handle = s_spiFilterHandle[instance];

    SPI_FILTER_HandleIRQ(base, handle);
    SDK_ISR_EXIT_BARRIER;
}
