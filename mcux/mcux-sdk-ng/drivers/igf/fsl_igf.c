/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_igf.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.igf"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to igf bases for each instance. */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
static IGF_Type *const s_igfBases[] = IGF_BASE_PTRS;

/*! @brief Pointers to igf clocks for each instance. */
static const clock_ip_name_t s_igfClocks[] = IGF_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for IGF module.
 *
 * @param base IGF peripheral base address
 *
 * @return The IGF instance
 */
static uint32_t IGF_GetInstance(IGF_Type *base);
/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t IGF_GetInstance(IGF_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_igfBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_igfBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_igfBases));

    return instance;
}
#endif

/*!
 * brief Initializes the IGF module with the specified configuration.
 *
 * This function un-gates the IGF clock and config IGF module.
 *
 * param base IGF peripheral address.
 */
void IGF_Init(IGF_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock gate from clock manager */
    CLOCK_EnableClock(s_igfClocks[IGF_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Deinitializes an IGF instance for operation.
 *
 * This function shutdowns IGF module.
 *
 * param base IGF peripheral address.
 */
void IGF_Deinit(IGF_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock gate from clock manager */
    CLOCK_DisableClock(s_igfClocks[IGF_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration for IGF.
 *
 * This function provides the default configuration for the IGF module.
 *
 * param config Pointer to configuration structure.
 */
void IGF_GetDefaultConfig(igf_config_t *config)
{
    config->enableFilter = true;
    config->invertOutput = false;
    config->immediatePropagation = false;
    config->useExternalPrescaler = false;
    config->prescaler = 0;
    config->risingEdgeFilter = kIGF_FilterBypass;
    config->fallingEdgeFilter = kIGF_FilterBypass;
    config->risingThreshold = 4;
    config->fallingThreshold = 4;
}

/*!
 * brief Set the IGF module with the specified configuration.
 *
 * This function config IGF module.
 *
 * param base IGF peripheral address.
 * param channel IGF corresponding pin channel value.
 * param config Pointer to configuration structure.
 */
void IGF_SetIgfConfig(IGF_Type *base, uint32_t channel, const igf_config_t *config)
{
    assert(NULL != config);

    /* Disable filter before configuration */
    base->MCR[channel].MCR &= ~IGF_MCR_FGEN_MASK;

    /* Configure MCR register */
    base->MCR[channel].MCR = IGF_MCR_POL(config->invertOutput) |
                         IGF_MCR_IMM(config->immediatePropagation) |
                         IGF_MCR_PSSEL(config->useExternalPrescaler) |
                         IGF_MCR_RFM(config->risingEdgeFilter) |
                         IGF_MCR_FFM(config->fallingEdgeFilter);

    /* Configure prescaler and thresholds */
    base->MCR[channel].PRESR = IGF_PRESR_FPRE(config->prescaler);
    base->MCR[channel].RTHR = IGF_RTHR_RTH(config->risingThreshold);
    base->MCR[channel].FTHR = IGF_FTHR_FTH(config->fallingThreshold);

    /* Enable filter if requested */
    if (config->enableFilter)
    {
        base->MCR[channel].MCR |= IGF_MCR_FGEN_MASK;
    }
}

/*!
 * brief Enables or disables the IGF filter.
 *
 * This function enables or disables the IGF filter.
 *
 * param base IGF peripheral address.
 * param channel IGF corresponding pin channel value.
 * param enable True to enable, false to disable.
 */
void IGF_Enable(IGF_Type *base, uint32_t channel, bool enable)
{
    if (enable)
    {
        base->MCR[channel].MCR |= IGF_MCR_FGEN_MASK;
    }
    else
    {
        base->MCR[channel].MCR &= ~IGF_MCR_FGEN_MASK;
    }
}

/*!
 * brief Gets the status flags from IGF module.
 *
 * This function returns the Boolean evaluation associated.
 *
 * param base IGF peripheral address.
 * param channel IGF corresponding pin channel value.
 */
uint32_t IGF_GetStatusFlags(IGF_Type *base, uint32_t channel)
{
    return base->MCR[channel].MSR;
}

/*!
 * brief Clears the specified status flags.
 *
 * This function clears the IGF status flags.
 *
 * param base IGF peripheral address.
 * param channel IGF corresponding pin channel value.
 * param mask Mask of status flags to clear.
 */
void IGF_ClearStatusFlags(IGF_Type *base, uint32_t channel, uint32_t mask)
{
    base->MCR[channel].MSR = mask;
}
