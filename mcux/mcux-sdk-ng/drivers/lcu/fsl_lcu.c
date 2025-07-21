/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lcu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lcu"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get instance number for LCU.
 *
 * @param base LCU peripheral base address.
 */
static uint32_t LCU_GetInstance(LCU_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map LCU instance number to base pointer. */
static LCU_Type *const s_lcuBases[] = LCU_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map LCU instance number to clock name. */
static const clock_ip_name_t s_lcuClock[] = LCU_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t LCU_GetInstance(LCU_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_lcuBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_lcuBases[instance]) == MSDK_REG_SECURE_ADDR(base))   
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_lcuBases));

    return instance;
}

/*!
 * brief Initializes the LCU peripheral.
 *
 * This function ungates the LCU clock.
 * 
 * param base LCU peripheral base address.
 */
void LCU_Init(LCU_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the LCU clock */
    (void)CLOCK_EnableClock(s_lcuClock[LCU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Deinitializes the LCU peripheral.
 *
 * This function gates the LCU clock.
 *
 * param base LCU peripheral base address.
 */
void LCU_Deinit(LCU_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_lcuClock[LCU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration for LCU force input.
 *
 * This function initializes the LCU force input configuration structure to a default value. The default
 * values are as follows.
 * code
 *   config->CombinationEnable = kLCU_SoftwareOverride0;
 *   config->polarity = kLCU_ForceInputPolarityNoInverted;
 *   config->filter = false;
 * endcode
 * param config Pointer to the configuration structure.
 */
void LCU_GetForceInputDefaultConfig(lcu_force_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->CombinationEnable = kLCU_SoftwareOverride0;
    config->polarity = kLCU_ForceInputPolarityNoInverted;
    config->filter = false;
}

/*!
 * brief Gets the default configuration for LCU output.
 *
 * This function initializes the LCU output configuration structure to a default value. The default
 * values are as follows.
 * code
 *   config->outputEnable = false;
 *   config->softwareOverrideEnable = false;
 *   config->softwareOverridevalue = kLCU_SoftwareOverride0;
 *   config->softwareSyncSelect = kLCU_SyncInput0;
 *   config->SyncMode = kLCU_SoftwareImmediateSync;
 *   config->syncSelect = kLCU_SyncInput0;
 *   config->forceClearMode = kLCU_ClearWithDeassertion;
 *   config->outputPolarity = kLCU_OutputPolarityNotInverted;
 *   config->forceInputSentivity = 0U;
 *   config->riseFilter = 0U;
 *   config->fallFilter = 0U;
 *   config->lutValue = 0xFFFFU;
 * endcode
 * param config Pointer to the configuration structure.
 */
void LCU_GetOutputDefaultConfig(lcu_output_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->outputEnable = false;
    config->softwareOverrideEnable = false;
    config->softwareOverridevalue = kLCU_SoftwareOverride0;
    config->softwareSyncSelect = kLCU_SyncInput0;
    config->SyncMode = kLCU_SoftwareImmediateSync;
    config->syncSelect = kLCU_SyncInput0;
    config->forceClearMode = kLCU_ClearWithDeassertion;
    config->outputPolarity = kLCU_OutputPolarityNotInverted;
    config->forceInputSentivity = 0U;
    config->riseFilter = 0U;
    config->fallFilter = 0U;
    config->lutValue = 0xFFFFU;
}

/*!
 * brief Initializes force input.
 *
 * This function initializes force input.
 *
 * param base LCU peripheral base address.
 * param forceInput LCU force input number.
 * param forceInputConfig Pointer to the LCU force input configuration structure.
 */
void LCU_ForceInit(LCU_Type *base, lcu_force_inputs_t forceInput, const lcu_force_config_t *forceInputConfig)
{
    uint32_t tmpreg;
    uint32_t cell = FSL_LCU_GET_LC_VALUE(forceInput);
    uint32_t inputBit = FSL_LCU_GET_LC_IO_VALUE(forceInput);

    tmpreg = base->LC[cell].FFILT;
    tmpreg &= ~(LCU_FFILT_FORCE_FILT_MASK | LCU_FFILT_FORCE_POL_MASK | LCU_FFILT_COMB_EN_MASK);
    tmpreg |= (LCU_FFILT_FORCE_FILT(forceInputConfig->filter)                  |\
               LCU_FFILT_FORCE_POL((forceInputConfig->polarity << inputBit))     |\
               LCU_FFILT_COMB_EN((forceInputConfig->CombinationEnable << inputBit)));
    base->LC[cell].FFILT = tmpreg;
}

/*!
 * brief Initializes the LCU output.
 *
 * This function initializes the LCU output.
 *
 * param base LCU peripheral base address.
 * param output LCU output number.
 * param outputConfig Pointer to the LCU configuration structure.
 */
void LCU_OutputInit(LCU_Type *base, lcu_outputs_t output, const lcu_output_config_t *outputConfig)
{
    uint32_t outputMask = 1 << output;

    /* Init LCU output. */
    LCU_SetLutValue(base, output, outputConfig->lutValue);
    LCU_SetRiseFilter(base, output, outputConfig->riseFilter);
    LCU_SetFallFilter(base, output, outputConfig->fallFilter);
    LCU_SetOutputPolarity(base, output, outputConfig->outputPolarity);
    LCU_SyncSelect(base, output, outputConfig->syncSelect);
    LCU_SetForceClearMode(base, output, outputConfig->forceClearMode);
    LCU_ForceInputSensitivity(base, output, outputConfig->forceInputSentivity);
    LCU_SetSoftwareSyncMode(base, output, outputConfig->SyncMode);
    LCU_SoftwareSyncSelect(base, output, outputConfig->softwareSyncSelect);
    LCU_EnableSoftwareOverride(base, outputMask, outputConfig->softwareOverrideEnable);
    LCU_SetSoftwareOverrideValue(base, outputMask, outputConfig->softwareOverridevalue);
    LCU_EnableOutput(base, outputMask, outputConfig->outputEnable);
}
