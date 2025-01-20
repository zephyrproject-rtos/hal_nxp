/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dryice_digital.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dryice_digital"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Enables the DryIce Digital module.
 *
 * This function enables the DryIce peripheral.
 */
void DRYICE_DIGITAL_Init(DRYICE_Type *base, const dryice_digital_config_t *config)
{
    assert(config);

    uint32_t wr_val;

    wr_val = DRYICE_DTOCR_DRYICE_EN_MASK | DRYICE_DTOCR_TEMP_HIGH_OFFSET(config->tempHighOffset) |
             DRYICE_DTOCR_TEMP_LOW_OFFSET(config->tempLowOffset);
    base->DTOCR = wr_val;

    wr_val = DRYICE_DTMR_TEMP_MON_TRIM(config->tempMonTrim) | DRYICE_DTMR_VOLT_MON_TRIM(config->voltMonTrim) |
             DRYICE_DTMR_BGR_TRIM(config->bgrTrim);
    base->DTMR = wr_val;

    base->DMCR |= DRYICE_DMCR_TEMP_DET_SEL(config->tempDetSel);
}

/*!
 * brief Disables the DryIce Digital module.
 *
 * This function disables the DryIce peripheral.
 */
void DRYICE_DIGITAL_Deinit(DRYICE_Type *base)
{
    base->DTOCR &= ~DRYICE_DTOCR_DRYICE_EN_MASK;
}

/*!
 * brief Gets default values for the DryIce Digital module.
 *
 * This function fills the given structure with default values for the DryIce module.
 * The default values are:
 * code
 *     defaultConfig->tempHighOffset = 0U;
 *     defaultConfig->tempLowOffset = 0U;
 *     defaultConfig->tempMonTrim = 0U;
 *     defaultConfig->voltMonTrim = 0U;
 *     defaultConfig->bgrTrim = 0U;
 *     defaultConfig->tempDetSel = kDRYICE_DIGITAL_Range_105C_125C;
 * endcode
 * param base DryIce Digital peripheral base address
 * param[out] defaultConfig Pointer to structure to be filled with default parameters
 */
void DRYICE_DIGITAL_GetDefaultConfig(DRYICE_Type *base, dryice_digital_config_t *config)
{
    assert(config);

    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->tempHighOffset = 0U;
    config->tempLowOffset  = 0U;
    config->tempMonTrim    = 0U;
    config->voltMonTrim    = 0U;
    config->bgrTrim        = 0U;
    config->tempDetSel     = kDRYICE_DIGITAL_Range_105C_125C;
}

/*!
 * brief Gets default values for tamper pin configuration.
 *
 * This function fills the give structure with default values for the tamper pin configuration.
 * The default values are:
 * code
 *     pinConfig->pinDirection = kDRYICE_TamperPinDirectionIn;
 *     pinConfig->ignoredWindowWidth = kDRYICE_DIGITAL_NoIgnoredWindow;
 *     pinConfig->ignoredWinClkSel = kDRYICE_DIGITAL_32768Hz;
 *     pinConfig->ignoredWinStartCycle = 0U;
 *     pinConfig->extTamperRoutingCtrl = kDRYICE_DIGITAL_PassiveInput;
 *     pinConfig->passiveTamperExpDat = kDRYICE_DIGITAL_ExpectedTamperHigh;
 *     pinConfig->pullEnable = false;
 *     pinConfig->pullContinuousEnable = false;
 *     pinConfig->pullSelect = kDRYICE_DIGITAL_PullDown;
 *     pinConfig->pullTransWidth = kDRYICE_DIGITAL_1CycleTransitionWidth;
 *     pinConfig->driveStrength = kDRYICE_DIGITAL_DriveStrenght1;
 *     pinConfig->hysteresisCtrl = kDRYICE_DIGITAL_Schmitt;
 *     pinConfig->outputKeepEnable = false;
 *     pinConfig->sampleClkSel = kDRYICE_DIGITAL_32768Hz;
 *     pinConfig->sampleFreqSel = kDRYICE_DIGITAL_Every8Cycles;
 *     pinConfig->sampleWidth = kDRYICE_DIGITAL_SamplingDisabled;
 * endcode
 *
 * param base DryIce Digital peripheral base address
 * param[out] pinConfig Pointer to structure to be filled with tamper pins default parameters
 */
void DRYICE_DIGITAL_PinGetDefaultConfig(DRYICE_Type *base, dryice_digital_pin_config_t *pinConfig)
{
    assert(pinConfig);

    /* Initializes the configure structure to zero. */
    memset(pinConfig, 0, sizeof(*pinConfig));

    pinConfig->ignoredWindowWidth   = kDRYICE_DIGITAL_NoIgnoredWindow;
    pinConfig->ignoredWinClkSel     = kDRYICE_DIGITAL_32768Hz;
    pinConfig->ignoredWinStartCycle = 0U;

    pinConfig->extTamperRoutingCtrl = kDRYICE_DIGITAL_PassiveInput;
    pinConfig->passiveTamperExpDat  = kDRYICE_DIGITAL_ExpectedTamperHigh;

    pinConfig->pullEnable           = false;
    pinConfig->pullContinuousEnable = false;
    pinConfig->pullSelect           = kDRYICE_DIGITAL_PullDown;
    pinConfig->pullTransWidth       = kDRYICE_DIGITAL_1CycleTransitionWidth;

    pinConfig->driveStrength = kDRYICE_DIGITAL_DriveStrenght1;

    pinConfig->hysteresisCtrl   = kDRYICE_DIGITAL_Schmitt;
    pinConfig->outputKeepEnable = false;

    pinConfig->sampleClkSel  = kDRYICE_DIGITAL_32768Hz;
    pinConfig->sampleFreqSel = kDRYICE_DIGITAL_Every8Cycles;
    pinConfig->sampleWidth   = kDRYICE_DIGITAL_SamplingDisabled;
}

/*!
 * brief Writes to the DryIce Digital TPCTRLn register.
 *
 * This function writes the given structure to the DryIce Digital TPCTRLn Register.
 * param base DryIce Digital peripheral base address
 * param config Pointer to structure with DryIce Digital peripheral configuration parameters
 * return kStatus_Fail when writing to DryIce Control Register is not allowed
 * return kStatus_Success when operation completes successfully
 */
status_t DRYICE_DIGITAL_SetPinConfig(DRYICE_Type *base,
                                     dryice_digital_tamper_pin_t pin,
                                     const dryice_digital_pin_config_t *pinConfig)
{
    assert(pinConfig);

    uint32_t wr_val = 0;

    wr_val |= DRYICE_TPCTRL_IGNWD(pinConfig->ignoredWindowWidth);
    wr_val |= DRYICE_TPCTRL_IGWCS(pinConfig->ignoredWinClkSel);
    wr_val |= DRYICE_TPCTRL_IGNWS(pinConfig->ignoredWinStartCycle);
    wr_val |= DRYICE_TPCTRL_TPEC(pinConfig->pullContinuousEnable);
    wr_val |= DRYICE_TPCTRL_ETRCTRL(pinConfig->extTamperRoutingCtrl);
    wr_val |= DRYICE_TPCTRL_PTED(pinConfig->passiveTamperExpDat);
    wr_val |= DRYICE_TPCTRL_TPS(pinConfig->pullSelect);
    wr_val |= DRYICE_TPCTRL_TPE(pinConfig->pullEnable);
    wr_val |= DRYICE_TPCTRL_HC(pinConfig->hysteresisCtrl);
    wr_val |= DRYICE_TPCTRL_OUTKEEPER_EN(pinConfig->outputKeepEnable);
    wr_val |= DRYICE_TPCTRL_DSC(pinConfig->driveStrength);
    wr_val |= DRYICE_TPCTRL_TSCS(pinConfig->sampleClkSel);
    wr_val |= DRYICE_TPCTRL_TPSF(pinConfig->sampleFreqSel);
    wr_val |= DRYICE_TPCTRL_TPSW(pinConfig->sampleWidth);
    wr_val |= DRYICE_TPCTRL_TPPTW(pinConfig->pullTransWidth);

    base->TPCTRL[pin] = wr_val;

    if (base->TPCTRL[pin] != wr_val)
    {
        return kStatus_Fail;
    }
    else
    {
        return kStatus_Success;
    }
}

/*!
 * brief Writes to the DryIce Digital Control Register.
 *
 * This function sets specified tamper enable bits in DryIce Digital Control Register.
 *
 * param base DryIce Digital peripheral base address
 * param mask Bit mask for the tamper enable bits to be set.
 */
void DRYICE_DIGITAL_EnableTampers(DRYICE_Type *base, uint32_t mask)
{
    uint32_t wr_val = 0;

    if (mask & kDRYICE_DIGITAL_ClockTamper)
    {
        wr_val |= DRYICE_DMCR_CLOCK_DET_EN_MASK;
    }
    if (mask & kDRYICE_DIGITAL_VoltageTamper)
    {
        wr_val |= DRYICE_DMCR_VOLT_DET_EN_MASK;
    }
    if (mask & kDRYICE_DIGITAL_TemperatureTamper)
    {
        wr_val |= DRYICE_DMCR_TEMP_DET_EN_MASK;
    }

    base->DMCR |= wr_val;
}

/*!
 * brief Writes to the DryIce Digital Control Register.
 *
 * This function clears specified tamper enable bits in DryIce Digital Control Register.
 *
 * param base DryIce Digital peripheral base address
 * param mask Bit mask for the tamper enable bits to be cleared.
 */
void DRYICE_DIGITAL_DisableTampers(DRYICE_Type *base, uint32_t mask)
{
    uint32_t wr_val = 0;

    if (mask & kDRYICE_DIGITAL_ClockTamper)
    {
        wr_val |= DRYICE_DMCR_CLOCK_DET_EN_MASK;
    }
    if (mask & kDRYICE_DIGITAL_VoltageTamper)
    {
        wr_val |= DRYICE_DMCR_VOLT_DET_EN_MASK;
    }
    if (mask & kDRYICE_DIGITAL_TemperatureTamper)
    {
        wr_val |= DRYICE_DMCR_TEMP_DET_EN_MASK;
    }

    base->DMCR &= ~wr_val;
}
