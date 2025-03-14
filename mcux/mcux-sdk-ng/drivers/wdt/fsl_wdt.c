/*
 * Copyright 2018-2019 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_wdt.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.wdt"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initializes the WDT configuration structure.
 *
 * This function initializes the WDT configuration structure to default values. The default
 * values are as follows.
 * code
 *   wdtConfig->timeoutValue = 0xFFFFU;
 *   wdtConfig->enableReset = true;
 *   wdtConfig->enableWdog = true;
 * endcode
 *
 * param config Pointer to the WDT configuration structure.
 * see wdt_config_t
 */
void WDT_GetDefaultConfig(wdt_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->timeoutCounter = 0xFFFFU;
    config->enableReset    = true;
    config->enableWdog     = true;
}

/*!
 * brief Initializes the WDT.
 *
 * This function initializes the WDT. When called, the WDT runs according to the configuration.
 *
 * This is an example.
 * code
 *   wdt_config_t config;
 *   WDT_GetDefaultConfig(&config);
 *   config.timeoutValue = 0x7ffU;
 *   WDT_Init(wdt_base,&config);
 * endcode
 *
 * param base   WDT peripheral base address
 * param config The configuration of WDT
 */
void WDT_Init(WDT_Type *base, const wdt_config_t *config)
{
    assert(NULL != config);

    uint32_t primask;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Wdt);
#endif

    primask = DisableGlobalIRQ();
    /* Set timeout value. */
    WDT_SetTimeoutCounter(base, config->timeoutCounter);
    /* Set WDT mode, reset mode: enableReset = true, enableWdog = true; interrupt mode: enableReset = false, enableWdog
     * = true; */
    base->WDMOD |= WDT_WDMOD_RESET(config->enableReset) | WDT_WDMOD_EN(config->enableWdog);
    /* Feed the WDT to start. */
    base->WDFEED = 0xAA;
    base->WDFEED = 0x55;
    EnableGlobalIRQ(primask);
}

/*!
 * brief Shuts down the WDT.
 *
 * This function shuts down the WDT.
 */
void WDT_Deinit(WDT_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_DisableClock(kCLOCK_Wdt);
#endif
}
