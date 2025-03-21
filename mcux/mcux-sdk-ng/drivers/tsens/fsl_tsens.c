/*
 * Copyright 2018, NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_tsens.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tsens"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for TSENS module.
 *
 * @param base TSENS peripheral base address
 */
static uint32_t TSENS_GetInstance(TSENS_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to TSENS bases for each instance. */
static TSENS_Type *const s_tsensBases[] = TSENS_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to TSENS clocks for each instance. */
static const clock_ip_name_t s_tsensClocks[] = TSEN_CLOCKS;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t TSENS_GetInstance(TSENS_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_tsensBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_tsensBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_tsensBases));

    return instance;
}

/*!
 * brief Enable the access to TSENS registers and initialize TSENS module.
 *
 * param base TSENS peripheral base address.
 * param config Pointer to configuration structure. Refer to "tsens_config_t" structure.
 */
void TSENS_Init(TSENS_Type *base, const tsens_config_t *config)
{
    assert(NULL != base);
    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable TSENS clock. */
    CLOCK_EnableClock(s_tsensClocks[TSENS_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL. */
    POWER_DisablePD(kPDRUNCFG_PD_TSEN);

    /* Ensure a measurement always start. */
    base->CR = ~TSENS_CR_START_MASK;

    /* Disable TSENS interrupt. */
    TSENS_DisableInterrupt(base, kTSENS_AllInterruptEnable);

    /* Configure TSENS output mode, resolution mode and voltage calibration to defalut condition. */
    base->SP0 = (TSENS_SP0_TOUTMODE(config->outputMode) | TSENS_SP0_TRESMODE(config->resolutionMode) |
                 TSENS_SP0_TVCALEN(config->enableVolatgeCalibration));

    /* Set defalut temperature threshold to defalut. */
    TSENS_SetLowTemperatureThreshold(base, 0x0000U);
    TSENS_SetHighTemperatureThreshold(base, 0x7FFFU);
}

/*!
 * brief De-initialize TSENS module.
 *
 * param base TSENS peripheral base address.
 */
void TSENS_Deinit(TSENS_Type *base)
{
    /* Disable TSENS interrupt. */
    TSENS_DisableInterrupt(base, kTSENS_AllInterruptEnable);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable TSENS clock. */
    CLOCK_DisableClock(s_tsensClocks[TSENS_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL. */
    POWER_EnablePD(kPDRUNCFG_PD_TSEN);
}

/*!
 * brief Gets the default configuration for TSENS.
 *
 * This function initializes the user configuration structure to default value. The default value are:
 * param config Pointer to TSENS configuration structure. Refer to "tsens_config_t" structure.
 */
void TSENS_GetDefaultConfig(tsens_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->outputMode               = kTSENS_OutputCalibratedData;
    config->resolutionMode           = kTSENS_Resolution12bit;
    config->enableVolatgeCalibration = false;
}

/*!
 * brief Get the default calibration config.
 *
 * param base TSENS peripheral base address.
 * param caliConfig Pointer to TSENS calibration configuration structure. Refer to "tsens_calibration_config_t"
 * structure.
 */
void TSENS_GetDefaultCalibrationConfig(TSENS_Type *base, tsens_calibration_config_t *caliConfig)
{
    assert(NULL != caliConfig);

    /* Initializes the configure structure to zero. */
    memset(caliConfig, 0, sizeof(*caliConfig));

    caliConfig->parameterA     = (base->SP1 & TSENS_SP1_A_MASK);
    caliConfig->parameterB     = (base->SP2 & TSENS_SP2_B_MASK);
    caliConfig->parameterAlpha = (base->SP3 & TSENS_SP3_ALPHA_MASK);
}

/*!
 * brief Config calibration parameters,
 *
 * param base TSENS peripheral base address.
 * param caliConfig Pointer to TSENS calibration configuration structure. Refer to "tsens_calibration_config_t"
 * structure.
 */
void TSENS_SetCalibrationConfig(TSENS_Type *base, const tsens_calibration_config_t *caliConfig)
{
    assert(NULL != caliConfig);

    base->SP1 = (caliConfig->parameterA & TSENS_SP1_A_MASK);
    base->SP2 = (caliConfig->parameterB & TSENS_SP2_B_MASK);
    base->SP3 = (caliConfig->parameterAlpha & TSENS_SP3_ALPHA_MASK);
}
