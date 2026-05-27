/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_freqme.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_freqme"
#endif

#if defined(FREQME_RSTS_N)
#define FREQME_RESETS_ARRAY FREQME_RSTS_N
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint32_t FREQME_GetInstance(FREQME_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Array to map freqme instance number to base address. */
static FREQME_Type *const s_freqmeBases[] = FREQME_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to FREQME clocks for each instance. */
static const clock_ip_name_t s_freqmeClocks[] = FREQME_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(FREQME_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_freqmeResets[] = FREQME_RESETS_ARRAY;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t FREQME_GetInstance(FREQME_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0U; instance < ARRAY_SIZE(s_freqmeBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_freqmeBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_freqmeBases));

    return instance;
}

/*!
 * @brief Initialize freqme module, set operate mode, operate mode attribute and initialize measurement cycle.
 *
 * @param base FREQME peripheral base address.
 * @param config The pointer to module basic configuration, please refer to @ref freq_measure_config_t.
 */
void FREQME_Init(FREQME_Type *base, const freq_measure_config_t *config)
{
    assert(config);

    uint32_t tmp32 = 0UL;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable FREQME clock. */
    CLOCK_EnableClock(s_freqmeClocks[FREQME_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(FREQME_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_freqmeResets[FREQME_GetInstance(base)]);
#endif

    if (config->startMeasurement)
    {
        tmp32 |= FREQME_CTRL_W_MEASURE_IN_PROGRESS_MASK;
    }

    tmp32 |= (config->enableContinuousMode ? FREQME_CTRL_W_CONTINUOUS_MODE_EN_MASK : 0U);
    tmp32 |= FREQME_CTRL_W_PULSE_MODE(config->operateMode);

    if (config->operateMode == kFREQME_FreqMeasurementMode)
    {
        tmp32 |= FREQME_CTRL_W_REF_SCALE(config->operateModeAttribute.refClkScaleFactor);
    }
    else
    {
        tmp32 |= FREQME_CTRL_W_PULSE_POL(config->operateModeAttribute.pulsePolarity);
    }

    base->CTRL_W = tmp32;
}

/*!
 * @brief Get default configuration.
 *
 * @code
 *      config->operateMode = kFREQME_FreqMeasurementMode;
 *      config->operateModeAttribute.refClkScaleFactor = 0U;
 *      config->enableContinuousMode                   = false;
 *      config->startMeasurement                       = false;
 * @endcode
 *
 * @param config The pointer to module basic configuration, please refer to @ref freq_measure_config_t.
 */
void FREQME_GetDefaultConfig(freq_measure_config_t *config)
{
    assert(config);

    (void)memset(config, 0, sizeof(*config));

    config->operateMode                            = kFREQME_FreqMeasurementMode;
    config->operateModeAttribute.refClkScaleFactor = 0U;
    config->enableContinuousMode                   = false;
    config->startMeasurement                       = false;
}

