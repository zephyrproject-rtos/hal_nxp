/*
 * Copyright 2025-2026 NXP
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

static audmix_mix_clock_source_t AUDMIX_GetConfiguredMixClockSource(AUDMIX_Type *base);
static bool AUDMIX_IsAttenuationEnabled(AUDMIX_Type *base, uint8_t tdmChannel);
static bool AUDMIX_IsValidOutputSource(audmix_output_source_t source);
static bool AUDMIX_IsValidMixClockSource(audmix_mix_clock_source_t source);
static bool AUDMIX_IsValidOutputWidth(audmix_output_width_t width);
static bool AUDMIX_IsValidOutputClockPolarity(audmix_output_clock_polarity_t polarity);
static bool AUDMIX_IsValidAttenuationDirection(audmix_attenuation_direction_t direction);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

static audmix_mix_clock_source_t AUDMIX_GetConfiguredMixClockSource(AUDMIX_Type *base)
{
    assert(base != NULL);

    return (audmix_mix_clock_source_t)((base->CTR & AUDMIX_CTR_MIXCLK_MASK) >> AUDMIX_CTR_MIXCLK_SHIFT);
}

static bool AUDMIX_IsAttenuationEnabled(AUDMIX_Type *base, uint8_t tdmChannel)
{
    assert(base != NULL);
    assert(tdmChannel <= 1U);

    return (tdmChannel == 0U) ? ((base->ATCR0 & AUDMIX_ATCR0_AT_EN_MASK) != 0U) :
                                ((base->ATCR1 & AUDMIX_ATCR1_AT_EN_MASK) != 0U);
}

static bool AUDMIX_IsValidOutputSource(audmix_output_source_t source)
{
    return ((source == kAUDMIX_OutputDisabled) || (source == kAUDMIX_OutputFromTDM1) ||
            (source == kAUDMIX_OutputFromTDM2) || (source == kAUDMIX_OutputMixed));
}

static bool AUDMIX_IsValidMixClockSource(audmix_mix_clock_source_t source)
{
    return ((source == kAUDMIX_MixClockFromTDM1) || (source == kAUDMIX_MixClockFromTDM2));
}

static bool AUDMIX_IsValidOutputWidth(audmix_output_width_t width)
{
    return ((width == kAUDMIX_OutputWidth16Bit) || (width == kAUDMIX_OutputWidth18Bit) ||
            (width == kAUDMIX_OutputWidth20Bit) || (width == kAUDMIX_OutputWidth24Bit) ||
            (width == kAUDMIX_OutputWidth32Bit));
}

static bool AUDMIX_IsValidOutputClockPolarity(audmix_output_clock_polarity_t polarity)
{
    return ((polarity == kAUDMIX_OutputClockPolarityPositiveEdge) ||
            (polarity == kAUDMIX_OutputClockPolarityNegativeEdge));
}

static bool AUDMIX_IsValidAttenuationDirection(audmix_attenuation_direction_t direction)
{
    return ((direction == kAUDMIX_AttenuationDirectionDown) || (direction == kAUDMIX_AttenuationDirectionUp));
}

/*!
 * @brief Initializes the AUDMIX peripheral.
 *
 * This API gates the AUDMIX clock. The AUDMIX module can't operate unless AUDMIX_Init is called to enable the clock.
 *
 * @param base AUDMIX base pointer.
 */
void AUDMIX_Init(AUDMIX_Type *base)
{
    /* Prevent compiler warning about unused parameter */
    (void)base;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_audmix);
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
void AUDMIX_Deinit(AUDMIX_Type *base)
{
    /* Prevent compiler warning about unused parameter */
    (void)base;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(kCLOCK_audmix);
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
status_t AUDMIX_SetConfig(AUDMIX_Type *base, const audmix_config_t *config)
{
    uint32_t reg = 0U;
    uint32_t mixClockSource;
    uint32_t outputSource;
    uint32_t outputWidth;
    uint32_t outputClockPolarity;
    uint32_t syncModeClockSource;

    if (base == NULL || config == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidMixClockSource(config->mixClockSource) || !AUDMIX_IsValidOutputSource(config->outputSource) ||
        !AUDMIX_IsValidOutputWidth(config->outputWidth) ||
        !AUDMIX_IsValidOutputClockPolarity(config->outputClockPolarity) ||
        !AUDMIX_IsValidMixClockSource(config->syncModeClockSource))
    {
        return kStatus_AUDMIX_Error;
    }

    mixClockSource = (uint32_t)config->mixClockSource;
    outputSource = (uint32_t)config->outputSource;
    outputWidth = (uint32_t)config->outputWidth;
    outputClockPolarity = (uint32_t)config->outputClockPolarity;
    syncModeClockSource = (uint32_t)config->syncModeClockSource;

    /* Configure CTR register */
    reg = AUDMIX_CTR_MIXCLK(mixClockSource) |
          AUDMIX_CTR_OUTSRC(outputSource) |
          AUDMIX_CTR_OUTWIDTH(outputWidth) |
          AUDMIX_CTR_OUTCKPOL(outputClockPolarity);

    if (config->maskFrameRateDiffError)
    {
        reg |= AUDMIX_CTR_MASKRTDF_MASK;
    }

    if (config->maskClockFrequencyDiffError)
    {
        reg |= AUDMIX_CTR_MASKCKDF_MASK;
    }

    if (config->syncModeEnable)
    {
        reg |= AUDMIX_CTR_SYNCMODE_MASK;
    }

    reg |= AUDMIX_CTR_SYNCSRC(syncModeClockSource);

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
    config->stepDownFactor = 0x30000U;  /* Default step down factor (0.75) */
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
status_t AUDMIX_SetAttenuationConfig(AUDMIX_Type *base, uint8_t tdmChannel, const audmix_attenuation_config_t *config)
{
    uint32_t atcr;
    uint32_t attenuationDirection;
    uint32_t stepDivider;
    uint32_t initialValue;
    uint32_t stepUpFactor;
    uint32_t stepDownFactor;
    uint32_t stepTarget;

    if (base == NULL || config == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    /* More explicit bounds checking */
    if (tdmChannel != 0U && tdmChannel != 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidAttenuationDirection(config->attenuationDirection))
    {
        return kStatus_AUDMIX_Error;
    }

    /* Profile parameters must not be changed while attenuation is enabled. */
    if (AUDMIX_IsAttenuationEnabled(base, tdmChannel))
    {
        return kStatus_AUDMIX_Busy;
    }

    atcr = 0U;
    attenuationDirection = ((uint32_t)config->attenuationDirection) & 0x1U;
    stepDivider = (config->stepDivider <= AUDMIX_MAX_STEP_DIVIDER) ? (uint32_t)config->stepDivider :
                                                                      AUDMIX_MAX_STEP_DIVIDER;
    initialValue = (config->initialValue <= AUDMIX_MAX_INITIAL_VALUE) ? config->initialValue : AUDMIX_MAX_INITIAL_VALUE;
    stepUpFactor = (config->stepUpFactor <= AUDMIX_MAX_STEP_FACTOR) ? config->stepUpFactor : AUDMIX_MAX_STEP_FACTOR;
    stepDownFactor = (config->stepDownFactor <= AUDMIX_MAX_STEP_FACTOR) ? config->stepDownFactor : AUDMIX_MAX_STEP_FACTOR;
    stepTarget = (config->stepTarget <= AUDMIX_MAX_STEP_TARGET) ? config->stepTarget : AUDMIX_MAX_STEP_TARGET;

    /* Configure attenuation control register with safe operations */
    atcr = AUDMIX_ATCR0_AT_EN(config->attenuationEnable ? 1U : 0U) |
           AUDMIX_ATCR0_AT_UPDN(attenuationDirection) |
           AUDMIX_ATCR0_ATSTPDIV(stepDivider);

    /* Set the attenuation registers based on the TDM channel */
    if (tdmChannel == 0U)
    {
        base->ATCR0 = atcr;
        base->ATIVAL0 = initialValue & AUDMIX_ATIVAL0_ATINTVAL_MASK;
        base->ATSTPUP0 = stepUpFactor & AUDMIX_ATSTPUP0_ATSTEPUP_MASK;
        base->ATSTPDN0 = stepDownFactor & AUDMIX_ATSTPDN0_ATSTEPDN_MASK;
        base->ATSTPTGT0 = stepTarget & AUDMIX_ATSTPTGT0_ATSTPTG_MASK;
    }
    else /* tdmChannel == 1U (already validated) */
    {
        base->ATCR1 = atcr;
        base->ATIVAL1 = initialValue & AUDMIX_ATIVAL1_ATINTVAL_MASK;
        base->ATSTPUP1 = stepUpFactor & AUDMIX_ATSTPUP1_ATSTEPUP_MASK;
        base->ATSTPDN1 = stepDownFactor & AUDMIX_ATSTPDN1_ATSTEPDN_MASK;
        base->ATSTPTGT1 = stepTarget & AUDMIX_ATSTPTGT1_ATSTPTG_MASK;
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
status_t AUDMIX_EnableAttenuation(AUDMIX_Type *base, uint8_t tdmChannel, bool enable)
{
    if (base == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (tdmChannel == 0U)
    {
        if (enable)
        {
            base->ATCR0 |= AUDMIX_ATCR0_AT_EN_MASK;
        }
        else
        {
            base->ATCR0 &= ~AUDMIX_ATCR0_AT_EN_MASK;
        }
    }
    else
    {
        if (enable)
        {
            base->ATCR1 |= AUDMIX_ATCR1_AT_EN_MASK;
        }
        else
        {
            base->ATCR1 &= ~AUDMIX_ATCR1_AT_EN_MASK;
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
status_t AUDMIX_SetAttenuationDirection(AUDMIX_Type *base, uint8_t tdmChannel, audmix_attenuation_direction_t direction)
{
    uint32_t directionValue;
    uint32_t reg;

    if (base == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidAttenuationDirection(direction))
    {
        return kStatus_AUDMIX_Error;
    }

    directionValue = (uint32_t)direction;

    if (tdmChannel == 0U)
    {
        reg = base->ATCR0;
        reg &= ~AUDMIX_ATCR0_AT_UPDN_MASK;
        reg |= AUDMIX_ATCR0_AT_UPDN(directionValue);
        base->ATCR0 = reg;
    }
    else
    {
        reg = base->ATCR1;
        reg &= ~AUDMIX_ATCR1_AT_UPDN_MASK;
        reg |= AUDMIX_ATCR1_AT_UPDN(directionValue);
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
bool AUDMIX_IsFrameRateMatched(AUDMIX_Type *base)
{
    if (base == NULL)
    {
        return false;
    }

    return ((AUDMIX_GetStatusFlags(base) & AUDMIX_STR_RATEDIFF_MASK) == 0U);
}

/*!
 * @brief Checks if the clock frequencies of TDM1 and TDM2 are matched.
 *
 * @param base AUDMIX base pointer.
 * @return true if clock frequencies match, false if they don't match.
 */
bool AUDMIX_IsClockFrequencyMatched(AUDMIX_Type *base)
{
    if (base == NULL)
    {
        return false;
    }

    return ((AUDMIX_GetStatusFlags(base) & AUDMIX_STR_CLKDIFF_MASK) == 0U);
}

/*!
 * @brief Gets the current mixer state.
 *
 * @param base AUDMIX base pointer.
 * @return Current mixer state (disabled, TDM1, TDM2, or mixed).
 */
audmix_output_source_t AUDMIX_GetMixerState(AUDMIX_Type *base)
{
    uint32_t status;

    if (base == NULL)
    {
        return kAUDMIX_OutputDisabled;
    }

    status = (base->STR & AUDMIX_STR_MIXSTAT_MASK) >> AUDMIX_STR_MIXSTAT_SHIFT;
    return (audmix_output_source_t)status;
}

/*!
 * @brief Sets the output source for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param source Output source (disabled, TDM1, TDM2, or mixed).
 * @return Status of the operation
 */
status_t AUDMIX_SetOutputSource(AUDMIX_Type *base, audmix_output_source_t source)
{
    uint32_t regValue;
    audmix_mix_clock_source_t requiredMixClockSource;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidOutputSource(source))
    {
        return kStatus_AUDMIX_Error;
    }

    if ((source == kAUDMIX_OutputFromTDM1) || (source == kAUDMIX_OutputFromTDM2))
    {
        requiredMixClockSource = (source == kAUDMIX_OutputFromTDM1) ? kAUDMIX_MixClockFromTDM1 : kAUDMIX_MixClockFromTDM2;
        if (AUDMIX_GetConfiguredMixClockSource(base) != requiredMixClockSource)
        {
            return kStatus_AUDMIX_Error;
        }
    }

    regValue = base->CTR;
    regValue &= ~AUDMIX_CTR_OUTSRC_MASK;
    regValue |= AUDMIX_CTR_OUTSRC((uint32_t)source);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;

    return kStatus_Success;
}

/*!
 * @brief Sets the mixing clock source for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param source Mixing clock source (TDM1 or TDM2).
 * @return Status of the operation
 */
status_t AUDMIX_SetMixClockSource(AUDMIX_Type *base, audmix_mix_clock_source_t source)
{
    uint32_t regValue;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidMixClockSource(source))
    {
        return kStatus_AUDMIX_Error;
    }

    /* RM forbids runtime switching of MIXCLK while entering/staying in mixed mode. */
    if (AUDMIX_GetMixerState(base) == kAUDMIX_OutputMixed)
    {
        return kStatus_AUDMIX_Busy;
    }

    regValue = (base->CTR & ~AUDMIX_CTR_MIXCLK_MASK) | AUDMIX_CTR_MIXCLK((uint32_t)source);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;
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
status_t AUDMIX_GetAttenuationValue(AUDMIX_Type *base, uint8_t tdmChannel, uint32_t *value)
{
    if (base == NULL || value == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (tdmChannel == 0U)
    {
        *value = (base->ATTNVAL0 & AUDMIX_ATTNVAL0_ATCURVAL_MASK) >> AUDMIX_ATTNVAL0_ATCURVAL_SHIFT;
    }
    else
    {
        *value = (base->ATTNVAL1 & AUDMIX_ATTNVAL1_ATCURVAL_MASK) >> AUDMIX_ATTNVAL1_ATCURVAL_SHIFT;
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
status_t AUDMIX_GetAttenuationStepCounter(AUDMIX_Type *base, uint8_t tdmChannel, uint32_t *counter)
{
    if (base == NULL || counter == NULL || tdmChannel > 1U)
    {
        return kStatus_AUDMIX_Error;
    }

    if (tdmChannel == 0U)
    {
        *counter = (base->ATSTP0 & AUDMIX_ATSTP0_STPCTR_MASK) >> AUDMIX_ATSTP0_STPCTR_SHIFT;
    }
    else
    {
        *counter = (base->ATSTP1 & AUDMIX_ATSTP1_STPCTR_MASK) >> AUDMIX_ATSTP1_STPCTR_SHIFT;
    }

    return kStatus_Success;
}

/*!
 * @brief Sets the output width for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param width Output width (16-bit, 18-bit, 20-bit, 24-bit, or 32-bit).
 * @return Status of the operation
 */
status_t AUDMIX_SetOutputWidth(AUDMIX_Type *base, audmix_output_width_t width)
{
    uint32_t regValue;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidOutputWidth(width))
    {
        return kStatus_AUDMIX_Error;
    }

    regValue = (base->CTR & ~AUDMIX_CTR_OUTWIDTH_MASK) | AUDMIX_CTR_OUTWIDTH((uint32_t)width);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;
    return kStatus_Success;
}

/*!
 * @brief Sets the output clock polarity for the AUDMIX.
 *
 * @param base AUDMIX base pointer.
 * @param polarity Output clock polarity (positive or negative edge).
 * @return Status of the operation
 */
status_t AUDMIX_SetOutputClockPolarity(AUDMIX_Type *base, audmix_output_clock_polarity_t polarity)
{
    uint32_t regValue;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidOutputClockPolarity(polarity))
    {
        return kStatus_AUDMIX_Error;
    }

    regValue = (base->CTR & ~AUDMIX_CTR_OUTCKPOL_MASK) | AUDMIX_CTR_OUTCKPOL((uint32_t)polarity);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;
    return kStatus_Success;
}

/*!
 * @brief Enables or disables the frame rate difference error masking.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable masking, false to disable masking.
 * @return Status of the operation
 */
status_t AUDMIX_EnableFrameRateDiffErrorMasking(AUDMIX_Type *base, bool enable)
{
    uint32_t regValue;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    regValue = enable ? (base->CTR | AUDMIX_CTR_MASKRTDF_MASK) : (base->CTR & ~AUDMIX_CTR_MASKRTDF_MASK);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;
    return kStatus_Success;
}

/*!
 * @brief Enables or disables the clock frequency difference error masking.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable masking, false to disable masking.
 * @return Status of the operation
 */
status_t AUDMIX_EnableClockFrequencyDiffErrorMasking(AUDMIX_Type *base, bool enable)
{
    uint32_t regValue;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    regValue = enable ? (base->CTR | AUDMIX_CTR_MASKCKDF_MASK) : (base->CTR & ~AUDMIX_CTR_MASKCKDF_MASK);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;
    return kStatus_Success;
}

/*!
 * @brief Enables or disables the sync mode.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable sync mode, false to disable sync mode.
 * @return Status of the operation
 */
status_t AUDMIX_EnableSyncMode(AUDMIX_Type *base, bool enable)
{
    uint32_t regValue;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    regValue = enable ? (base->CTR | AUDMIX_CTR_SYNCMODE_MASK) : (base->CTR & ~AUDMIX_CTR_SYNCMODE_MASK);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;
    return kStatus_Success;
}

/*!
 * @brief Sets the sync mode clock source.
 *
 * @param base AUDMIX base pointer.
 * @param source Sync mode clock source (TDM1 or TDM2).
 * @return Status of the operation
 */
status_t AUDMIX_SetSyncModeClockSource(AUDMIX_Type *base, audmix_mix_clock_source_t source)
{
    uint32_t regValue;

    if (base == NULL)
    {
        return kStatus_AUDMIX_Error;
    }

    if (!AUDMIX_IsValidMixClockSource(source))
    {
        return kStatus_AUDMIX_Error;
    }

    regValue = (base->CTR & ~AUDMIX_CTR_SYNCSRC_MASK) | AUDMIX_CTR_SYNCSRC((uint32_t)source);

    if (regValue == base->CTR)
    {
        return kStatus_Success;
    }

    base->CTR = regValue;
    return kStatus_Success;
}

