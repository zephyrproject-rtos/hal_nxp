/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_tempsensor.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tempsensor_1"
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
 * brief This function is used to get predefined configurations for the tempsensor initialization.
 *
 * param config Pointer to the tempsensor configuration structure, please refer to @ref tmpsns_config_t for details.
 */
void TMPSNS_GetDefaultConfig(tmpsns_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableClockDivider = true;
    config->refClockDivider    = 0x05U;
    config->powerUpDealy       = 0x64U;
    config->resolutionMode     = kTMPSNS_ResolutionMode1;
    config->measurementMode    = kTMPSNS_SingleOneShotMode;
    config->measurementPeriod  = 0x00U;
}

/*!
 * brief This function is used to initialize the tempsensor.
 *
 * param base Tempsensor peripheral base address.
 * param config Pointer to the tempsensor configuration structure, please refer to @ref tmpsns_config_t for details.
 */
void TMPSNS_Init(TMPSNS_Type *base, const tmpsns_config_t *config)
{
    assert(config != NULL);

    /* Set divider to divide MODULE_CLK to generate CONV_CLK. */
    if (config->enableClockDivider)
    {
        base->REF_DIV = ((base->REF_DIV & (~TMPSNS_REF_DIV_DIV_MASK)) |
                         (TMPSNS_REF_DIV_DIV(config->refClockDivider) | TMPSNS_REF_DIV_DE_MASK));
    }

    /* Set the power-up delay. */
    base->PUD_ST_CTRL_CLR = TMPSNS_PUD_ST_CTRL_PUD_MASK;
    base->PUD_ST_CTRL_SET = TMPSNS_PUD_ST_CTRL_PUD(config->powerUpDealy);

    /* Set conversion time and measurement mode. */
    base->CTRL1_CLR = (TMPSNS_CTRL1_RESOLUTION_MASK | TMPSNS_CTRL1_MEAS_MODE_MASK);
    base->CTRL1_SET =
        (TMPSNS_CTRL1_RESOLUTION(config->resolutionMode) | TMPSNS_CTRL1_MEAS_MODE(config->measurementMode));

    /* Set the measurement period for periodic one-shot mode. */
    if (kTMPSNS_PeriodicOneShotMode == config->measurementMode)
    {
        base->PERIOD_CTRL_CLR = TMPSNS_PERIOD_CTRL_MEAS_FREQ_MASK;
        base->PERIOD_CTRL_SET = TMPSNS_PERIOD_CTRL_MEAS_FREQ(config->measurementPeriod);
    }
}

/*!
 * brief This function is used to de-initialize the tempsensor.
 *
 * param base Tempsensor peripheral base address.
 */
void TMPSNS_Deinit(TMPSNS_Type *base)
{
    TMPSNS_StopMeasurement(base);
    TMPSNS_DisableTmpsns(base);
}

/*!
 * brief This function is used to configure the thresholds.
 *
 * param base Tempsensor peripheral base address.
 * param config Pointer to the threshold configuration structure, please refer @ref tmpsns_threshold_config_t for
 * details.
 */
void TMPSNS_NonSecure_DoThresholdConfig(TMPSNS_Type *base, const tmpsns_threshold_config_t *config)
{
    assert(config != NULL);
    assert(config->thresholdIndex <= kTMPSNS_ThresholdCmp2);

    bool negativeFlag    = false;
    uint8_t temp         = 0U;
    uint16_t integerPart = 0U;
    uint16_t actualValue = 0U;
    float fractionalPart = 0.0F;
    float thresholdVal   = 0.0F;

    volatile uint32_t *THRCTRL_CLR[2U] = {&(base->THR_CTRL01_CLR), &(base->THR_CTRL23_CLR)};
    volatile uint32_t *THRCTRL_SET[2U] = {&(base->THR_CTRL01_SET), &(base->THR_CTRL23_SET)};

    TMPSNS_NonSecure_ClearFilterCount(
        base, ((uint32_t)kTMPSNS_NonSecure_Filter0CountClear << (uint32_t)config->thresholdIndex));

    /* Set temperature threshold comparator mode. */
    base->CTRL0_CLR = TMPSNS_CTRL_THR_MODE_MASK(config->thresholdIndex);
    base->CTRL0_SET = TMPSNS_CTRL_THR_MODE(config->thresholdIndex, config->thresholdCmpMode);

    if ((config->thresholdVal >= -0.000001F) &&
        (config->thresholdVal <= 0.000001F)) /* When the input temperature threshold value is 0, write it directly. */
    {
        *(THRCTRL_CLR[(uint32_t)config->thresholdIndex / 2U]) =
            TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_MASK(config->thresholdIndex);
    }
    else /* Convert the input temperature threshold value (celsius degree) to binary value. */
    {
        thresholdVal = config->thresholdVal;

        if (thresholdVal < 0.0F) /* Negative temperature. */
        {
            negativeFlag = true;
            thresholdVal = 0.0F - thresholdVal;
        }

        integerPart    = (uint16_t)thresholdVal;            /* Temperature integer part. */
        actualValue    = integerPart;
        fractionalPart = thresholdVal - (float)integerPart; /* Temperature fraction part. */

        for (uint8_t index = 0U; index < 6U; ++index)
        {
            temp = 0U;

            if ((fractionalPart * 2.0F) >= 1.0F)
            {
                fractionalPart = (fractionalPart * 2.0F - 1.0F);
                temp           = 1U;
            }
            else
            {
                fractionalPart = fractionalPart * 2.0F;
            }

            actualValue = ((actualValue << 1U) | temp);
        }

        /* Set temperature threshold comparator value. */
        *(THRCTRL_CLR[(uint32_t)config->thresholdIndex / 2U]) =
            TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_MASK(config->thresholdIndex);
        *(THRCTRL_SET[(uint32_t)config->thresholdIndex / 2U]) = TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD(
            config->thresholdIndex, (negativeFlag ? (~((uint32_t)actualValue) + 1U) : actualValue));
    }
}

/*!
 * brief This function is used to configure the thresholds.
 *
 * param base Tempsensor peripheral base address.
 * param config Pointer to the threshold configuration structure, please refer @ref tmpsns_threshold_config_t for
 * details.
 */
void TMPSNS_Secure_DoThresholdConfig(TMPSNS_Type *base, const tmpsns_threshold_config_t *config)
{
    assert(config != NULL);
    assert((config->thresholdIndex >= kTMPSNS_ThresholdCmp4) && (config->thresholdIndex <= kTMPSNS_ThresholdCmp5));

    bool negativeFlag    = false;
    uint8_t temp         = 0U;
    uint16_t integerPart = 0U;
    uint16_t actualValue = 0U;
    float fractionalPart = 0.0F;
    float thresholdVal   = 0.0F;

    TMPSNS_NonSecure_ClearFilterCount(
        base, (uint32_t)((uint32_t)kTMPSNS_Secure_Filter4CountClear << (uint32_t)config->thresholdIndex));

    /* Set temperature threshold comparator mode. */
    base->CTRL1_CLR = TMPSNS_CTRL_THR_MODE_MASK(config->thresholdIndex);
    base->CTRL1_SET = TMPSNS_CTRL_THR_MODE(config->thresholdIndex, config->thresholdCmpMode);

    if ((config->thresholdVal >= -0.000001F) &&
        (config->thresholdVal <= 0.000001F)) /* When the input temperature threshold value is 0, write it directly. */
    {
        base->THR_CTRL45_CLR = TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_MASK(config->thresholdIndex);
    }
    else /* Convert the input temperature threshold value (celsius degree) to binary value. */
    {
        thresholdVal = config->thresholdVal;

        if (thresholdVal < 0.0F) /* Negative temperature. */
        {
            negativeFlag = true;
            thresholdVal = 0.0F - thresholdVal;
        }

        integerPart    = (uint16_t)thresholdVal;            /* Temperature integer part. */
        actualValue    = integerPart;
        fractionalPart = thresholdVal - (float)integerPart; /* Temperature fraction part. */

        for (uint8_t index = 0U; index < 6U; ++index)
        {
            temp = 0U;

            if ((fractionalPart * 2.0F) >= 1.0F)
            {
                fractionalPart = (fractionalPart * 2.0F - 1.0F);
                temp           = 1U;
            }
            else
            {
                fractionalPart = fractionalPart * 2.0F;
            }

            actualValue = ((actualValue << 1U) | temp);
        }

        /* Set temperature threshold comparator value. */
        base->THR_CTRL45_CLR = TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_MASK(config->thresholdIndex);
        base->THR_CTRL45_SET = TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD(
            config->thresholdIndex, (negativeFlag ? (~((uint32_t)actualValue) + 1U) : actualValue));
    }
}

/*!
 * brief This function is used to get the current temperature.
 *
 * param base TMPSNS base pointer
 * return Current temperature with Celsius degree.
 */
float TMPSNS_NonSecure_GetCurrentTemperature(TMPSNS_Type *base)
{
    uint16_t measureTempVal = 0U;
    uint16_t integerPart    = 0U;
    float fractionalPart    = 0.0F;
    float actualTempVal     = 0.0F;

    measureTempVal = (uint16_t)((base->DATA0 & TMPSNS_DATA0_DATA_VAL_MASK) >> TMPSNS_DATA0_DATA_VAL_SHIFT);

    if (0U == ((measureTempVal & 0x8000U) >> 15U)) /* Positive temperature. */
    {
        integerPart = (uint16_t)((measureTempVal >> 6U) & 0x3FFU);

        for (uint8_t index = 0U; index < 6U; ++index)
        {
            if (0U != (measureTempVal & ((uint16_t)0x01U << index)))
            {
                fractionalPart += (float)(1.0F / (float)(uint32_t)((uint32_t)0x01U << (6U - index)));
            }
        }

        actualTempVal = (float)integerPart + fractionalPart;
    }
    else /* Negative temperature. */
    {
        measureTempVal = (uint16_t)(0x10000U - ((uint32_t)measureTempVal & 0xFFFFU));

        integerPart = (uint16_t)((measureTempVal >> 6U) & 0x3FFU);

        for (uint8_t index = 0U; index < 6U; ++index)
        {
            if (0U != (measureTempVal & ((uint16_t)0x01U << index)))
            {
                fractionalPart += (float)(1.0F / (float)(uint32_t)((uint32_t)0x01U << (6U - index)));
            }
        }

        actualTempVal = (-1.0F) * ((float)integerPart + fractionalPart);
    }

    return actualTempVal;
}

/*!
 * brief This function is used to get the current temperature.
 *
 * param base TMPSNS base pointer
 * return Current temperature with Celsius degree.
 */
float TMPSNS_Secure_GetCurrentTemperature(TMPSNS_Type *base)
{
    uint16_t measureTempVal = 0U;
    uint16_t integerPart    = 0U;
    float fractionalPart    = 0.0F;
    float actualTempVal     = 0.0F;

    /* Read to raw data. */
    measureTempVal = (uint16_t)((base->DATA1 & TMPSNS_DATA1_DATA_VAL_MASK) >> TMPSNS_DATA1_DATA_VAL_SHIFT);

    if (0U == ((measureTempVal & 0x8000U) >> 15U)) /* Positive temperature. */
    {
        integerPart = (uint16_t)((measureTempVal >> 6U) & 0x3FFU);

        for (uint8_t index = 0U; index < 6U; ++index)
        {
            if (0U != (measureTempVal & ((uint16_t)0x01U << index)))
            {
                fractionalPart += (float)(1.0F / (float)(uint32_t)((uint32_t)0x01U << (6U - index)));
            }
        }

        actualTempVal = (float)integerPart + fractionalPart;
    }
    else /* Negative temperature. */
    {
        measureTempVal = (uint16_t)(0x10000U - ((uint32_t)measureTempVal & 0xFFFFU));

        integerPart = (uint16_t)((measureTempVal >> 6U) & 0x3FFU);

        for (uint8_t index = 0U; index < 6U; ++index)
        {
            if (0U != (measureTempVal & ((uint16_t)0x01U << index)))
            {
                fractionalPart += (float)(1.0F / (float)(uint32_t)((uint32_t)0x01U << (6U - index)));
            }
        }

        actualTempVal = (-1.0F) * ((float)integerPart + fractionalPart);
    }

    return actualTempVal;
}
