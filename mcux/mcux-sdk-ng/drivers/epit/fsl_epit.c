/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_epit.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.epit"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address to be used to gate or ungate the module clock
 *
 * @param base EPIT peripheral base address
 *
 * @return The EPIT instance
 */
static uint32_t EPIT_GetInstance(EPIT_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to EPIT bases for each instance. */
static EPIT_Type *const s_epitBases[] = EPIT_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to EPIT clocks for each instance. */
static const clock_ip_name_t s_epitClocks[] = EPIT_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t EPIT_GetInstance(EPIT_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_epitBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_epitBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_epitBases));

    return instance;
}

/*!
 * brief Ungates the EPIT clock and configures the peripheral for a basic operation.
 *
 * This function issues a software reset to reset all the registers to their reset values,
 * except for the EN, ENMOD, STOPEN, WAITEN and DBGEN bits in Control register.
 *
 * note This API should be called at the beginning of the application using the EPIT driver.
 *
 * param base EPIT peripheral base address.
 * param config Pointer to the user configuration structure.
 */
void EPIT_Init(EPIT_Type *base, const epit_config_t *config)
{
    assert(config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate the EPIT clock*/
    CLOCK_EnableClock(s_epitClocks[EPIT_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    base->CR = 0U;

    EPIT_SoftwareReset(base);

    base->CR =
        (config->enableRunInStop ? EPIT_CR_STOPEN_MASK : 0U) | (config->enableRunInWait ? EPIT_CR_WAITEN_MASK : 0U) |
        (config->enableRunInDbg ? EPIT_CR_DBGEN_MASK : 0U) | (config->enableCounterOverwrite ? EPIT_CR_IOVW_MASK : 0U) |
        (config->enableFreeRun ? 0U : EPIT_CR_RLD_MASK) | (config->enableResetMode ? EPIT_CR_ENMOD_MASK : 0U);

    EPIT_SetClockSource(base, config->clockSource);
    EPIT_SetClockDivider(base, config->divider);
}

/*!
 * brief Disables the module and gates the EPIT clock.
 *
 * param base EPIT peripheral base address.
 */
void EPIT_Deinit(EPIT_Type *base)
{
    /* Disable EPIT timers */
    base->CR = 0U;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the EPIT clock*/
    CLOCK_DisableClock(s_epitClocks[EPIT_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Fills in the EPIT configuration structure with default settings.
 *
 * The default values are:
 * code
 *    config->clockSource = kEPIT_ClockSource_Periph;
 *    config->divider = 1U;
 *    config->enableRunInStop = true;
 *    config->enableRunInWait = true;
 *    config->enableRunInDbg = false;
 *    config->enableCounterOverwrite = false;
 *    config->enableFreeRun = false;
 *    config->enableResetMode = true;
 * endcode
 * param config Pointer to the user configuration structure.
 */
void EPIT_GetDefaultConfig(epit_config_t *config)
{
    assert(config);

    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->clockSource            = kEPIT_ClockSource_Periph;
    config->divider                = 1U;
    config->enableRunInStop        = true;
    config->enableRunInWait        = true;
    config->enableRunInDbg         = false;
    config->enableCounterOverwrite = false;
    config->enableFreeRun          = false;
    config->enableResetMode        = true;
}
