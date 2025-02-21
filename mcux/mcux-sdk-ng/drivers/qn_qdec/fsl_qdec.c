/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @addtogroup QDEC
 * @{
 */
#include "fsl_qdec.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address to be used to gate or ungate the module clock
 *
 * @param base QDEC peripheral base address
 *
 * @return The QDEC instance
 */
static uint32_t QDEC_GetInstance(QDEC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to QDEC bases for each instance. */
static QDEC_Type *const s_qdecBases[] = QDEC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to QDEC clocks for each instance. */
static const clock_ip_name_t s_qdecClocks[] = QDEC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Pointers to QDEC resets for each instance. */
#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
static const reset_ip_name_t s_qdecResets[] = QDEC_RSTS;
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */
       /*******************************************************************************
        * Code
        ******************************************************************************/
static uint32_t QDEC_GetInstance(QDEC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < FSL_FEATURE_SOC_QDEC_COUNT; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_qdecBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < FSL_FEATURE_SOC_QDEC_COUNT);

    return instance;
}
/*!
 * brief Initializes the QDEC with configuration.
 *
 * This function configures the QDEC module with the user-defined settings.
 * param base QDEC peripheral base address.
 * param config  pointer to QDEC config structure
 */
void QDEC_Init(QDEC_Type *base, const qdec_config_t *config)
{
    uint32_t reg = 0;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_qdecClocks[QDEC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
    /* Reset the module. */
    RESET_PeripheralReset(s_qdecResets[QDEC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

    /* QDEC SAMP_CTL configuration */
    base->SAMP_CTRL = QDEC_SAMP_CTRL_DIVIDE(config->sampleClockDiv) | QDEC_SAMP_CTRL_PTS(config->samplePoint) |
                      QDEC_SAMP_CTRL_DB_SAMP_DIV(config->debounceFilterDiv);

    /* Debounce filter configure */
    if (config->debounceFilterDiv != kQDEC_DebounceFilterDivNone)
    {
        reg |= QDEC_CTRL_DB_FILTER_EN_MASK;
    }
    /* Single sample configure */
    if (config->samplePoint == kQDEC_SamplePoint1)
    {
        reg |= QDEC_CTRL_SINGLE_SAMPLE_SRST_EN_MASK;
    }

    if (config->autoClearEnable)
    {
        reg |= QDEC_CTRL_AUTO_CLR_EN_MASK;
    }
    /* Enable QDEC */
    reg |= QDEC_CTRL_QDEC_EN_MASK;

    /* QDEC QDEC_CTL configuration */
    base->CTRL = reg;
}
/*!
 * brief Disable the QDEC module
 *
 * This function disable the QDEC module.
 * param base QDEC peripheral base address.
 */
void QDEC_Deinit(QDEC_Type *base)
{
    /* Disable QDEC */
    base->CTRL &= ~QDEC_CTRL_QDEC_EN_MASK;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_qdecClocks[QDEC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
/*!
 * brief  Gets the default configuration structure.
 *
 * This function initializes the QDEC configuration structure to a default value. The default
 * values are:
 *  config->samplePoint = kQDEC_SamplePoint40;
 *  config->sampleClockDiv = kQDEC_SampleClockDivider1;
 *  config->debounceFilterDiv = kQDEC_DebounceFilterDivider1;
 *  config->autoClearEnable = true;
 * param config pointer to QDEC config structure
 */
void QDEC_GetDefaultConfig(qdec_config_t *config)
{
    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->samplePoint       = kQDEC_SamplePoint40;
    config->sampleClockDiv    = kQDEC_SampleClockDivider1;
    config->debounceFilterDiv = kQDEC_DebounceFilterDivider1;
    config->autoClearEnable   = true;
}
