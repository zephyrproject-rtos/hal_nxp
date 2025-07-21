/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_tempsense.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tempsense"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to tempsense bases for each instance. */
static TEMPSENSE_Type *s_tempsenseBases[] = TEMPSENSE_BASE_PTRS;

/*! @brief Pointers to tempsense clocks for each instance. */
static const clock_ip_name_t s_tempsenseClocks[] = TEMPSENSOR_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * brief This function is used to get the tempsense instance.
 *
 * param base Tempsense peripheral base address.
 *
 * return Tempsense instance.
 */
static uint32_t TEMPSENSE_GetInstance(TEMPSENSE_Type *base)
{
    uint32_t instance           = 0U;
    uint8_t tempsenseBaseSize   = ARRAY_SIZE(s_tempsenseBases);

    /* Find the instance index from base address mappings. */
    for (; instance < tempsenseBaseSize; ++instance)
    {
        if (MSDK_REG_SECURE_ADDR(s_tempsenseBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < tempsenseBaseSize);

    return instance;
}
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*!
 * brief This function is used to get predefined configurations for the tempsense initialization.
 *
 * param config Pointer to the tempsense configuration structure, please refer to @ref tempsense_config_t for details.
 */
void TEMPSENSE_GetDefaultConfig(tempsense_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->exposeGround = false;
}

/*!
 * brief This function is used to initialize the tempsense.
 *
 * param base Tempsense peripheral base address.
 * param config Pointer to the tempsense configuration structure, please refer to @ref tempsense_config_t for details.
 */
void TEMPSENSE_Init(TEMPSENSE_Type *base, const tempsense_config_t *config)
{
    assert(config != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Open clock gate. */
    CLOCK_EnableClock(s_tempsenseClocks[TEMPSENSE_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    TEMPSENSE_ExposeGround(base, config->exposeGround);
}

/*!
 * brief This function is used to de-initialize the tempsense.
 *
 * param base Tempsense peripheral base address.
 */
void TEMPSENSE_Deinit(TEMPSENSE_Type *base)
{
    TEMPSENSE_EnableTempsense(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable clock gate. */
    CLOCK_DisableClock(s_tempsenseClocks[TEMPSENSE_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Get current temperature
 *
 * param base Tempsense base pointer
 * param adcRef The ADC VREF which used to calculate the real temperature.
 * param adcRes The ADC resolution.
 *
 * return current temperature with degrees Celsius.
 */
float TEMPSENSE_GetCurrentTemperature(TEMPSENSE_Type *base,
                                      uint16_t adcResult,
                                      float adcRef,
                                      uint8_t adcRes)
{
    uint16_t tcaRaw[3U] = {0U};
    float tca[3U] = {0.0F};
    float vets = 0.0F;

    for(uint8_t index = 0U; index < 3U; ++index)
    {
        tcaRaw[index] = (uint16_t)(uint32_t)(((*(((volatile uint32_t *)(&(base->TCA0))) + index))
                        & TEMPSENSE_TCA0_TCA0_MASK) >> TEMPSENSE_TCA0_TCA0_SHIFT);

        tca[index] = ((float)(tcaRaw[index] & 0x7FFFU)) / 16.0F;

        if((tcaRaw[index] & 0x8000U) == 0x8000U)
        {
            tca[index] = -tca[index];
        }
    }

    vets = (float)(adcResult * adcRef / ((1U << adcRes) - 1U));

    return tca[0U] + tca[1U] * vets + tca[2U] * vets * vets;
}
