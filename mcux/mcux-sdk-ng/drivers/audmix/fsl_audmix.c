/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_audmix.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.audmix"
#endif

/* Maximum values for AUDMIX parameters to prevent overflow */
#define AUDMIX_MAX_STEP_DIVIDER   0xFFFU
#define AUDMIX_MAX_INITIAL_VALUE  0x3FFFFU
#define AUDMIX_MAX_STEP_FACTOR    0x3FFFFU
#define AUDMIX_MAX_STEP_TARGET    0x3FFFFU

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
 * @brief Initializes the AUDMIX peripheral.
 *
 * This API gates the AUDMIX clock. The AUDMIX module can't operate unless AUDMIX_Init is called to enable the clock.
 *
 * @param base AUDMIX base pointer.
 */
void AUDMIX_Init(WAKEUP_AUDMIX_Type *base)
{
    /* Prevent compiler warning about unused parameter */
    (void)base;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Audmix);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * @brief De-initializes the AUDMIX peripheral.
 *
 * This API gates the AUDMIX clock. The AUDMIX module can't operate unless AUDMIX_Init
 * is called to enable the clock.
 *
 * @param base AUDMIX base pointer.
 */
void AUDMIX_Deinit(WAKEUP_AUDMIX_Type *base)
{
    /* Prevent compiler warning about unused parameter */
    (void)base;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(kCLOCK_Audmix);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the AUDMIX configuration structure to default values.
 *
 * @param config Pointer to the configuration structure.
 * @return Status of the operation
 */
status_t AUDMIX_GetDefaultConfig(audmix_config_t *config)
{
    if (config == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    /* Initialize the config structure with default values */
    config->outputSource = kAUDMIX_OutputDisabled;
    config->mixClockSource = kAUDMIX_MixClockFromTDM1;
    config->outputWidth = kAUDMIX_OutputWidth16Bit;
    config->outputClockPolarity = kAUDMIX_OutputClockPolarityPositiveEdge;
    config->maskFrameRateDiffError = false;
    config->maskClockFrequencyDiffError = false;
    config->syncModeEnable = false;
    config->syncModeClockSource = kAUDMIX_MixClockFromTDM1;

    return kStatus_Success;
}

/*!
 * @brief Sets the AUDMIX configuration.
 *
 * @param base AUDMIX base pointer.
 * @param config Pointer to the configuration structure.
 * @return Status of the operation
 */
status_t AUDMIX_SetConfig(WAKEUP_AUDMIX_Type *base, const audmix_config_t *config)
{
    if (base == NULL || config == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = 0U;
    uint32_t mixClockSource = (uint32_t)config->mixClockSource & 0x1U;
    uint32_t outputSource = (uint32_t)config->outputSource & 0x3U;
    uint32_t outputWidth = (uint32_t)config->outputWidth & 0x7U;
    uint32_t outputClockPolarity = (uint32_t)config->outputClockPolarity & 0x1U;
    uint32_t syncModeClockSource = (uint32_t)config->syncModeClockSource & 0x1U;

    /* Configure CTR register */
    reg = WAKEUP_AUDMIX_CTR_MIXCLK(mixClockSource) |
          WAKEUP_AUDMIX_CTR_OUTSRC(outputSource) |
          WAKEUP_AUDMIX_CTR_OUTWIDTH(outputWidth) |
          WAKEUP_AUDMIX_CTR_OUTCKPOL(outputClockPolarity);

    if (config->maskFrameRateDiffError)
    {
        reg |= WAKEUP_AUDMIX_CTR_MASKRTDF_MASK;
    }

    if (config->maskClockFrequencyDiffError)
    {
        reg |= WAKEUP_AUDMIX_CTR_MASKCKDF_MASK;
    }

    if (config->syncModeEnable)
    {
        reg |= WAKEUP_AUDMIX_CTR_SYNCMODE_MASK;
    }

    reg |= WAKEUP_AUDMIX_CTR_SYNCSRC(syncModeClockSource);

    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Gets the default attenuation configuration structure.
 *
 * This function initializes the AUDMIX attenuation configuration structure to default values.
 *
 * @param config Pointer to the attenuation configuration structure.
 * @return Status of the operation
 */
status_t AUDMIX_GetDefaultAttenuationConfig(audmix_attenuation_config_t *config)
{
    if (config == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    /* Initialize the attenuation config structure with default values */
    config->attenuationEnable = false;
    config->attenuationDirection = kAUDMIX_AttenuationDirectionDown;
    config->stepDivider = 0U;
    config->initialValue = 0x3FFFFU;    /* Default initial value (0.999996185) */
    config->stepUpFactor = 0x2AAAAU;    /* Default step up factor (0.666664124) */
    config->stepDownFactor = 0x30000U;   /* Default step down factor (0.75) */
    config->stepTarget = 16U;           /* Default step target */

    return kStatus_Success;
}

/*!
 * @brief Sets the attenuation configuration for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param config Pointer to the attenuation configuration structure.
 * @return Status of the operation
 */
/* Improve integer handling in AUDMIX_SetAttenuationConfig */
status_t AUDMIX_SetAttenuationConfig(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, const audmix_attenuation_config_t *config)
{
    if (base == NULL || config == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    /* More explicit bounds checking */
    if (tdmChannel != 0U && tdmChannel != 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t atcr = 0U;
    /* Safe type conversion with explicit masking */
    uint32_t attenuationDirection = ((uint32_t)config->attenuationDirection) & 0x1U;

    /* Safe integer handling with explicit bounds checking */
    uint32_t stepDivider = (config->stepDivider <= AUDMIX_MAX_STEP_DIVIDER) ?
                           (uint32_t)config->stepDivider : AUDMIX_MAX_STEP_DIVIDER;

    uint32_t initialValue = (config->initialValue <= AUDMIX_MAX_INITIAL_VALUE) ?
                           config->initialValue : AUDMIX_MAX_INITIAL_VALUE;

    uint32_t stepUpFactor = (config->stepUpFactor <= AUDMIX_MAX_STEP_FACTOR) ?
                           config->stepUpFactor : AUDMIX_MAX_STEP_FACTOR;

    uint32_t stepDownFactor = (config->stepDownFactor <= AUDMIX_MAX_STEP_FACTOR) ?
                             config->stepDownFactor : AUDMIX_MAX_STEP_FACTOR;

    uint32_t stepTarget = (config->stepTarget <= AUDMIX_MAX_STEP_TARGET) ?
                         config->stepTarget : AUDMIX_MAX_STEP_TARGET;

    /* Configure attenuation control register with safe operations */
    atcr = WAKEUP_AUDMIX_ATCR0_AT_EN(config->attenuationEnable ? 1U : 0U) |
           WAKEUP_AUDMIX_ATCR0_AT_UPDN(attenuationDirection) |
           WAKEUP_AUDMIX_ATCR0_ATSTPDIV(stepDivider);

    /* Set the attenuation registers based on the TDM channel */
    if (tdmChannel == 0U)
    {
        base->ATCR0 = atcr;
        base->ATIVAL0 = initialValue & WAKEUP_AUDMIX_ATIVAL0_ATINTVAL_MASK;
        base->ATSTPUP0 = stepUpFactor & WAKEUP_AUDMIX_ATSTPUP0_ATSTEPUP_MASK;
        base->ATSTPDN0 = stepDownFactor & WAKEUP_AUDMIX_ATSTPDN0_ATSTEPDN_MASK;
        base->ATSTPTGT0 = stepTarget & WAKEUP_AUDMIX_ATSTPTGT0_ATSTPTG_MASK;
    }
    else /* tdmChannel == 1U (already validated) */
    {
        base->ATCR1 = atcr;
        base->ATIVAL1 = initialValue & WAKEUP_AUDMIX_ATIVAL1_ATINTVAL_MASK;
        base->ATSTPUP1 = stepUpFactor & WAKEUP_AUDMIX_ATSTPUP1_ATSTEPUP_MASK;
        base->ATSTPDN1 = stepDownFactor & WAKEUP_AUDMIX_ATSTPDN1_ATSTEPDN_MASK;
        base->ATSTPTGT1 = stepTarget & WAKEUP_AUDMIX_ATSTPTGT1_ATSTPTG_MASK;
    }

    return kStatus_Success;
}


/*!
 * @brief Enables or disables attenuation for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param enable true to enable, false to disable.
 * @return Status of the operation
 */
status_t AUDMIX_EnableAttenuation(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, bool enable)
{
    if (base == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (tdmChannel == 0U)
    {
        if (enable)
        {
            base->ATCR0 |= WAKEUP_AUDMIX_ATCR0_AT_EN_MASK;
        }
        else
        {
            base->ATCR0 &= ~WAKEUP_AUDMIX_ATCR0_AT_EN_MASK;
        }
    }
    else
    {
        if (enable)
        {
            base->ATCR1 |= WAKEUP_AUDMIX_ATCR1_AT_EN_MASK;
        }
        else
        {
            base->ATCR1 &= ~WAKEUP_AUDMIX_ATCR1_AT_EN_MASK;
        }
    }

    return kStatus_Success;
}

/*!
 * @brief Sets the attenuation direction for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param direction Attenuation direction (up or down).
 * @return Status of the operation
 */
status_t AUDMIX_SetAttenuationDirection(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, audmix_attenuation_direction_t direction)
{
    if (base == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t directionValue = (uint32_t)direction & 0x1U;

    if (tdmChannel == 0U)
    {
        uint32_t reg = base->ATCR0;
        reg &= ~WAKEUP_AUDMIX_ATCR0_AT_UPDN_MASK;
        reg |= WAKEUP_AUDMIX_ATCR0_AT_UPDN(directionValue);
        base->ATCR0 = reg;
    }
    else
    {
        uint32_t reg = base->ATCR1;
        reg &= ~WAKEUP_AUDMIX_ATCR1_AT_UPDN_MASK;
        reg |= WAKEUP_AUDMIX_ATCR1_AT_UPDN(directionValue);
        base->ATCR1 = reg;
    }

    return kStatus_Success;
}

/*!
 * @brief Checks if the frame rates of TDM1 and TDM2 are matched.
 *
 * @param base AUDMIX base pointer.
 * @return true if frame rates match, false if they don't match.
 */
bool AUDMIX_IsFrameRateMatched(WAKEUP_AUDMIX_Type *base)
{
    if (base == NULL)
    {
        return false;
    }

    return ((base->STR & WAKEUP_AUDMIX_STR_RATEDIFF_MASK) == 0U);
}

/*!
 * @brief Checks if the clock frequencies of TDM1 and TDM2 are matched.
 *
 * @param base AUDMIX base pointer.
 * @return true if clock frequencies match, false if they don't match.
 */
bool AUDMIX_IsClockFrequencyMatched(WAKEUP_AUDMIX_Type *base)
{
    if (base == NULL)
    {
        return false;
    }

    return ((base->STR & WAKEUP_AUDMIX_STR_CLKDIFF_MASK) == 0U);
}

/*!
 * @brief Gets the current mixer state.
 *
 * @param base AUDMIX base pointer.
 * @return Current mixer state (disabled, TDM1, TDM2, or mixed).
 */
audmix_output_source_t AUDMIX_GetMixerState(WAKEUP_AUDMIX_Type *base)
{
    if (base == NULL)
    {
        return kAUDMIX_OutputDisabled;
    }

    uint32_t status = (base->STR & WAKEUP_AUDMIX_STR_MIXSTAT_MASK) >> WAKEUP_AUDMIX_STR_MIXSTAT_SHIFT;
    return (audmix_output_source_t)status;
}

/*!
 * @brief Sets the output source for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param source Output source (disabled, TDM1, TDM2, or mixed).
 * @return Status of the operation
 */
status_t AUDMIX_SetOutputSource(WAKEUP_AUDMIX_Type *base, audmix_output_source_t source)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;
    reg &= ~WAKEUP_AUDMIX_CTR_OUTSRC_MASK;
    reg |= WAKEUP_AUDMIX_CTR_OUTSRC((uint32_t)source & 0x3U);
    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Sets the mixing clock source for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param source Mixing clock source (TDM1 or TDM2).
 * @return Status of the operation
 */
status_t AUDMIX_SetMixClockSource(WAKEUP_AUDMIX_Type *base, audmix_mix_clock_source_t source)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;
    reg &= ~WAKEUP_AUDMIX_CTR_MIXCLK_MASK;
    reg |= WAKEUP_AUDMIX_CTR_MIXCLK((uint32_t)source & 0x1U);
    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Gets the current attenuation value for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param value Pointer to store the attenuation value.
 * @return Status of the operation
 */
status_t AUDMIX_GetAttenuationValue(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, uint32_t *value)
{
    if (base == NULL || value == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (tdmChannel == 0U)
    {
        *value = (base->ATTNVAL0 & WAKEUP_AUDMIX_ATTNVAL0_ATCURVAL_MASK) >> WAKEUP_AUDMIX_ATTNVAL0_ATCURVAL_SHIFT;
    }
    else
    {
        *value = (base->ATTNVAL1 & WAKEUP_AUDMIX_ATTNVAL1_ATCURVAL_MASK) >> WAKEUP_AUDMIX_ATTNVAL1_ATCURVAL_SHIFT;
    }

    return kStatus_Success;
}

/*!
 * @brief Gets the current attenuation step counter for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param counter Pointer to store the step counter value.
 * @return Status of the operation
 */
status_t AUDMIX_GetAttenuationStepCounter(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, uint32_t *counter)
{
    if (base == NULL || counter == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (tdmChannel == 0U)
    {
        *counter = (base->ATSTP0 & WAKEUP_AUDMIX_ATSTP0_STPCTR_MASK) >> WAKEUP_AUDMIX_ATSTP0_STPCTR_SHIFT;
    }
    else
    {
        *counter = (base->ATSTP1 & WAKEUP_AUDMIX_ATSTP1_STPCTR_MASK) >> WAKEUP_AUDMIX_ATSTP1_STPCTR_SHIFT;
    }

    return kStatus_Success;
}

/*!
 * @brief Sets the output width for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param width Output width (16-bit, 18-bit, 20-bit, or 24-bit).
 * @return Status of the operation
 */
status_t AUDMIX_SetOutputWidth(WAKEUP_AUDMIX_Type *base, audmix_output_width_t width)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;
    reg &= ~WAKEUP_AUDMIX_CTR_OUTWIDTH_MASK;
    reg |= WAKEUP_AUDMIX_CTR_OUTWIDTH((uint32_t)width & 0x7U);
    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Sets the output clock polarity for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param polarity Output clock polarity (positive or negative edge).
 * @return Status of the operation
 */
status_t AUDMIX_SetOutputClockPolarity(WAKEUP_AUDMIX_Type *base, audmix_output_clock_polarity_t polarity)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;
    reg &= ~WAKEUP_AUDMIX_CTR_OUTCKPOL_MASK;
    reg |= WAKEUP_AUDMIX_CTR_OUTCKPOL((uint32_t)polarity & 0x1U);
    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Enables or disables the frame rate difference error masking.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable masking, false to disable masking.
 * @return Status of the operation
 */
status_t AUDMIX_EnableFrameRateDiffErrorMasking(WAKEUP_AUDMIX_Type *base, bool enable)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;

    if (enable)
    {
        reg |= WAKEUP_AUDMIX_CTR_MASKRTDF_MASK;
    }
    else
    {
        reg &= ~WAKEUP_AUDMIX_CTR_MASKRTDF_MASK;
    }

    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Enables or disables the clock frequency difference error masking.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable masking, false to disable masking.
 * @return Status of the operation
 */
status_t AUDMIX_EnableClockFrequencyDiffErrorMasking(WAKEUP_AUDMIX_Type *base, bool enable)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;

    if (enable)
    {
        reg |= WAKEUP_AUDMIX_CTR_MASKCKDF_MASK;
    }
    else
    {
        reg &= ~WAKEUP_AUDMIX_CTR_MASKCKDF_MASK;
    }

    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Enables or disables the sync mode.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable sync mode, false to disable sync mode.
 * @return Status of the operation
 */
status_t AUDMIX_EnableSyncMode(WAKEUP_AUDMIX_Type *base, bool enable)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;

    if (enable)
    {
        reg |= WAKEUP_AUDMIX_CTR_SYNCMODE_MASK;
    }
    else
    {
        reg &= ~WAKEUP_AUDMIX_CTR_SYNCMODE_MASK;
    }

    base->CTR = reg;

    return kStatus_Success;
}

/*!
 * @brief Sets the sync mode clock source.
 *
 * @param base AUDMIX base pointer.
 * @param source Sync mode clock source (TDM1 or TDM2).
 * @return Status of the operation
 */
status_t AUDMIX_SetSyncModeClockSource(WAKEUP_AUDMIX_Type *base, audmix_mix_clock_source_t source)
{
    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    uint32_t reg = base->CTR;
    reg &= ~WAKEUP_AUDMIX_CTR_SYNCSRC_MASK;
    reg |= WAKEUP_AUDMIX_CTR_SYNCSRC((uint32_t)source & 0x1U);
    base->CTR = reg;

    return kStatus_Success;
}

