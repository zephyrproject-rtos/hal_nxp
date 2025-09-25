/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpacmp.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpacmp"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to LPACMP bases for each instance. */
static LPACMP_Type *const s_LpacmpBases[] = LPACMP_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to LPACMP clocks for each instance. */
static const clock_ip_name_t s_LpacmpClocks[] = LPACMP_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(LPACMP_RSTS)
static const SYSCON_RSTn_t s_lpacmpResets[] = LPACMP_RSTS;
#endif /* LPACMP_RSTS */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t LPACMP_GetInstance(LPACMP_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    /*
     * $Branch Coverage Justification$
     * (instance >= ARRAY_SIZE(s_LpacmpBases)) not covered. The peripheral base
     * address is always valid and checked by assert.
     */
    for (instance = 0; instance < ARRAY_SIZE(s_LpacmpBases); instance++)
    {
        /*
         * $Branch Coverage Justification$
         * (s_LpacmpBases[instance] != base) not covered. The peripheral base
         * address is always valid and checked by assert.
         */
        if (MSDK_REG_SECURE_ADDR(s_LpacmpBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_LpacmpBases));

    return instance;
}

/*!
 * brief Gets an available pre-defined settings for LPACMP configuration.
 *
 * param config Pointer to the LPACMP configuration structure, please refer to @ref lpacmp_config_t for details.
 */
void LPACMP_GetDefaultConfig(lpacmp_config_t *config)
{
    assert(config != NULL);
 
    (void)memset(config, 0U, sizeof(*config));
 
    config->mode            = kLPACMP_Continuous_Mode;
    config->channelConfig   = NULL;
    config->channelCount    = 0U;
    config->intervalTime    = 0U;
}

/*!
 * brief Initialize the LPACMP module
 *
 * param base LPACMP peripheral base address
 * param config Pointer to the LPACMP configuration structure, please refer to @ref lpacmp_config_t for details.
 */
void LPACMP_Init(LPACMP_Type *base, const lpacmp_config_t *config)
{
    assert(config != NULL);
    assert(config->channelConfig->channelIndex < LPACMP_EXT_TRIG_COUNT);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    (void)CLOCK_EnableClock(s_LpacmpClocks[LPACMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(LPACMP_RSTS)
    RESET_ReleasePeripheralReset(s_lpacmpResets[LPACMP_GetInstance(base)]);
#endif /* LPACMP_RSTS */

    /* Disable block before configuration */
    LPACMP_EnableComparator(base, false);

    /* Set operation mode and delay */
    LPACMP_SetComparatorMode(base, config->mode);
    LPACMP_SetIntervalTime(base, config->intervalTime);

    /* Channels configuration. */
    lpacmp_channel_config_t *chanConf = config->channelConfig;

    for (uint8_t index = 0U; index < config->channelCount; ++index)
    {
        LPACMP_EnableWakeupToSmm(base, chanConf->channelIndex, chanConf->enableWakeupToSmm);
        LPACMP_EnableTriggerOutput(base, chanConf->channelIndex, chanConf->enableTriggerOutput);
        LPACMP_EnableInterrupt(base, chanConf->channelIndex, chanConf->enableInterrupt);        
        LPACMP_EnableChannel(base, chanConf->channelIndex, true);
        LPACMP_SetTriggerOutputWidth(base, chanConf->channelIndex, chanConf->triggerOutputWidth);
        LPACMP_SetDelayValue(base, chanConf->channelIndex, chanConf->delay);
        
        LPACMP_SetComparePolarity(base, chanConf->channelIndex, chanConf->comparePolarityHigher);
        LPACMP_ChannelInputSelection(base, chanConf->channelIndex, chanConf->positiveInput, chanConf->negativeInput);

        chanConf += 1U;
    }
}

/*!
 * brief De-initializes the LPACMP module
 *
 * param base LPACMP peripheral base address
 */
void LPACMP_Deinit(LPACMP_Type *base)
{
    LPACMP_EnableComparator(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    (void)CLOCK_DisableClock(s_LpacmpClocks[LPACMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    
#if defined(LPACMP_RSTS)
    RESET_SetPeripheralReset(s_lpacmpResets[LPACMP_GetInstance(base)]);
#endif /* LPACMP_RSTS */
}
