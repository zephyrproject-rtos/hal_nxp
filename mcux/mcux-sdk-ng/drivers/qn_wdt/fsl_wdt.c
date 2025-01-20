/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
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
#define FSL_COMPONENT_ID "platform.drivers.qn_wdt"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Initializes the WDT with configuration.
 *
 * This function initializes the WDT.
 *
 * param base WDT peripheral base address.
 * param config pointer to configuration structure
 */
void WDT_Init(WDT_Type *base, const wdt_config_t *config)
{
    assert(NULL != config);

    uint32_t primask;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Wdt);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_WDT_HAS_NO_RESET) && FSL_FEATURE_WDT_HAS_NO_RESET)
    /* Reset the WDT module */
    RESET_PeripheralReset(kWDT_RST_SHIFT_RSTn);
#endif

    primask = DisableGlobalIRQ();
    WDT_Unlock(base);
    base->LOAD = config->loadValue;
    if (config->enableWdtReset)
    {
        base->CTRL = WDT_CTRL_RESEN_MASK | WDT_CTRL_INTEN_MASK;
    }
    else
    {
        base->CTRL = WDT_CTRL_INTEN_MASK;
    }
    WDT_Lock(base);
    EnableGlobalIRQ(primask);
}

/*!
 * brief Disable the WDT peripheral.
 *
 * This function shuts down the WDT.
 *
 * param base WDT peripheral base address.
 */
void WDT_Deinit(WDT_Type *base)
{
    uint32_t primask;

    primask = DisableGlobalIRQ();
    WDT_Unlock(base);
    base->CTRL = 0;
    WDT_Lock(base);
    EnableGlobalIRQ(primask);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(kCLOCK_Wdt);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Initializes WDT configure structure
 *
 * This function initializes the WDT configure structure to default value. The default
 * value are:
 * code
 *   config->enableWdtReset = true;
 *   config->loadValue = 0xffffffff;
 * endcode
 * param config pointer to WDT config structure
 */
void WDT_GetDefaultConfig(wdt_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableWdtReset = true;
    config->loadValue      = 0xffffffffU;
}
