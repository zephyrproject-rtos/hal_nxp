/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_trgsync.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.trgsync"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Gets the instance index from the base address.
 *
 * @param base TRGSYNC peripheral base address.
 * @return Instance number.
 */
static uint32_t TRGSYNC_GetInstance(TRGSYNC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array of TRGSYNC peripheral base addresses */
static TRGSYNC_Type *const s_trgsyncBases[] = TRGSYNC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array of TRGSYNC clock names */
static const clock_ip_name_t s_trgsyncClocks[] = TRGSYNC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t TRGSYNC_GetInstance(TRGSYNC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings */
    for (instance = 0; instance < ARRAY_SIZE(s_trgsyncBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_trgsyncBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_trgsyncBases));
    
    return instance;
}

/*!
 * brief Initializes the TRGSYNC module.
 *
 * This function initializes the TRGSYNC module with the user configuration.
 *
 * param base TRGSYNC peripheral base address.
 */
void TRGSYNC_Init(TRGSYNC_Type *base)
{
    assert(base != NULL);
    
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint32_t instance = TRGSYNC_GetInstance(base);
    
    /* Enable module clock */
    CLOCK_EnableClock(s_trgsyncClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Deinitializes the TRGSYNC module.
 *
 * This function disables all TRGSYNC channels and gates the module clock.
 *
 * param base TRGSYNC peripheral base address.
 */
void TRGSYNC_Deinit(TRGSYNC_Type *base)
{
    assert(base != NULL);
    
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint32_t instance = TRGSYNC_GetInstance(base);
    
    /* Disable module clock */
    CLOCK_DisableClock(s_trgsyncClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration.
 *
 * This function fills the configuration structure with default settings.
 *
 * param config Pointer to the configuration structure.
 */
void TRGSYNC_GetDefaultConfig(trgsync_channel_config_t *config)
{
    config->enableChannel = false;
    config->enableFunctionalClock = false;
    config->polarity = kTRGSYNC_PolarityActiveHigh;
    config->stretchWidth = kTRGSYNC_StretchDisable;
    config->funcClockSource = kTRGSYNC_FuncClockBus;
}

/*!
 * brief Configures a single TRGSYNC channel.
 *
 * param base TRGSYNC peripheral base address.
 * param channel Channel number (0-7).
 * param config Pointer to the channel configuration structure.
 */
void TRGSYNC_ConfigureChannel(TRGSYNC_Type *base, uint8_t channel, const trgsync_channel_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);
    assert(channel < FSL_FEATURE_TRGSYNC_CHANNEL_COUNTn(base));

    uint32_t regValue = 0U;

    /* Build register value */
    if (config->enableChannel)
    {
        regValue |= TRGSYNC_CHANNEL_CH_ENA_MASK;
    }

    if (config->enableFunctionalClock)
    {
        regValue |= TRGSYNC_CHANNEL_FUNC_CK_ENA_MASK;
    }

    regValue |= TRGSYNC_CHANNEL_POL_SEL(config->polarity);
    regValue |= TRGSYNC_CHANNEL_STRETCH_WIDTH(config->stretchWidth);
    regValue |= TRGSYNC_CHANNEL_FUNC_CK_MUX(config->funcClockSource);

    /* Write to register */
    base->CHANNEL[channel] = regValue;
}