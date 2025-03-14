/*
 * Copyright (c) 2014 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_tsi_v2.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tsi_v2"
#endif

/*!
 * brief Initializes hardware.
 *
 * details Initializes the peripheral to the targeted state specified by the parameter configuration,
 *          such as initialize and set prescalers, number of scans, clocks, delta voltage
 *          capacitance trimmer, reference, and electrode charge current and threshold.
 *
 * param   base    TSI peripheral base address.
 * param   config  Pointer to the TSI peripheral configuration structure.
 * return none
 */
void TSI_Init(TSI_Type *base, const tsi_config_t *config)
{
    assert(config != NULL);

    bool is_module_enabled = false;
    bool is_int_enabled    = false;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(kCLOCK_Tsi0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    if (base->GENCS & TSI_GENCS_TSIEN_MASK)
    {
        is_module_enabled = true;
        TSI_EnableModule(base, false); /* Disable module */
    }
    if (base->GENCS & TSI_GENCS_TSIIE_MASK)
    {
        is_int_enabled = true;
        TSI_DisableInterrupts(base, kTSI_GlobalInterruptEnable);
    }

    TSI_SetHighThreshold(base, config->thresh);
    TSI_SetLowThreshold(base, config->thresl);
    TSI_SetLowPowerClock(base, config->lpclks);
    TSI_SetLowPowerScanInterval(base, config->lpscnitv);
    TSI_SetActiveModeSource(base, config->amclks);
    TSI_SetActiveModePrescaler(base, config->ampsc);
    TSI_SetElectrodeOSCPrescaler(base, config->ps);
    TSI_SetElectrodeChargeCurrent(base, config->extchrg);
    TSI_SetReferenceChargeCurrent(base, config->refchrg);
    TSI_SetNumberOfScans(base, config->nscn);

    if (is_module_enabled)
    {
        TSI_EnableModule(base, true);
    }
    if (is_int_enabled)
    {
        TSI_EnableInterrupts(base, kTSI_GlobalInterruptEnable);
    }
}

/*!
 * brief De-initializes hardware.
 *
 * details De-initializes the peripheral to default state.
 *
 * param  base  TSI peripheral base address.
 * return none
 */
void TSI_Deinit(TSI_Type *base)
{
    base->GENCS     = 0U;
    base->SCANC     = 0U;
    base->PEN       = 0U;
    base->THRESHOLD = 0U;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(kCLOCK_Tsi0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets TSI normal mode user configuration structure.
 * This interface sets the userConfig structure to a default value. The configuration structure only
 * includes the settings for the whole TSI.
 * The user configure is set to these values:
 * code
    userConfig.lpclks = kTSI_LowPowerClockSource_LPOCLK;
    userConfig.lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig.amclks = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig.ampsc = kTSI_ActiveModePrescaler_8div;
    userConfig.ps = kTSI_ElecOscPrescaler_2div;
    userConfig.extchrg = kTSI_ExtOscChargeCurrent_10uA;
    userConfig.refchrg = kTSI_RefOscChargeCurrent_10uA;
    userConfig.nscn = kTSI_ConsecutiveScansNumber_8time;
    userConfig.thresh = 0U;
    userConfig.thresl = 0U;
   endcode
 *
 * param userConfig Pointer to the TSI user configuration structure.
 */
void TSI_GetNormalModeDefaultConfig(tsi_config_t *userConfig)
{
    /* Initializes the configure structure to zero. */
    memset(userConfig, 0, sizeof(*userConfig));

    userConfig->thresh   = 0U;
    userConfig->thresl   = 0U;
    userConfig->lpclks   = kTSI_LowPowerClockSource_LPOCLK;
    userConfig->lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig->amclks   = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig->ampsc    = kTSI_ActiveModePrescaler_8div;
    userConfig->ps       = kTSI_ElecOscPrescaler_2div;
    userConfig->extchrg  = kTSI_ExtOscChargeCurrent_10uA;
    userConfig->refchrg  = kTSI_RefOscChargeCurrent_10uA;
    userConfig->nscn     = kTSI_ConsecutiveScansNumber_8time;
}

/*!
 * brief Gets the TSI low power mode default user configuration structure.
 * This interface sets userConfig structure to a default value. The configuration structure only
 * includes the settings for the whole TSI.
 * The user configure is set to these values:
 * code
    userConfig.lpclks = kTSI_LowPowerClockSource_LPOCLK;
    userConfig.lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig.amclks = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig.ampsc = kTSI_ActiveModePrescaler_64div;
    userConfig.ps = kTSI_ElecOscPrescaler_1div;
    userConfig.extchrg = kTSI_ExtOscChargeCurrent_2uA;
    userConfig.refchrg = kTSI_RefOscChargeCurrent_32uA;
    userConfig.nscn = kTSI_ConsecutiveScansNumber_26time;
    userConfig.thresh = 15000U;
    userConfig.thresl = 1000U;
   endcode
 *
 * param userConfig Pointer to the TSI user configuration structure.
 */
void TSI_GetLowPowerModeDefaultConfig(tsi_config_t *userConfig)
{
    /* Initializes the configure structure to zero. */
    memset(userConfig, 0, sizeof(*userConfig));

    userConfig->thresh   = 15000U;
    userConfig->thresl   = 1000U;
    userConfig->lpclks   = kTSI_LowPowerClockSource_LPOCLK;
    userConfig->lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig->amclks   = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig->ampsc    = kTSI_ActiveModePrescaler_64div;
    userConfig->ps       = kTSI_ElecOscPrescaler_1div;
    userConfig->extchrg  = kTSI_ExtOscChargeCurrent_2uA;
    userConfig->refchrg  = kTSI_RefOscChargeCurrent_32uA;
    userConfig->nscn     = kTSI_ConsecutiveScansNumber_26time;
}

/*!
 * brief Hardware calibration.
 *
 * details Calibrates the peripheral to fetch the initial counter value of the enabled electrodes.
 *          This API is mostly used at the initial application setup. Call this function after the \ref TSI_Init API
 *          and use the calibrated counter values to set up applications
 *          (such as to determine under which counter value a touch event occurs).
 *
 * note    This API is called in normal power modes.
 * note    For K60 series, the calibrated baseline counter value CANNOT be used in low power modes. To obtain
 *          the calibrated counter values in low power modes, see K60 Mask Set Errata for Mask 5N22D.
 * param   base   TSI peripheral base address.
 * param   calBuff Data buffer that store the calibrated counter value.
 * return  none
 *
 */
void TSI_Calibrate(TSI_Type *base, tsi_calibration_data_t *calBuff)
{
    assert(calBuff != NULL);

    uint8_t i           = 0U;
    bool is_int_enabled = false;

    if (base->GENCS & TSI_GENCS_TSIIE_MASK)
    {
        is_int_enabled = true;
        TSI_DisableInterrupts(base, kTSI_GlobalInterruptEnable);
    }

    TSI_EnableChannels(base, 0xFFFFU, true);
    TSI_StartSoftwareTrigger(base);
    while (!(TSI_GetStatusFlags(base) & kTSI_EndOfScanFlag))
    {
    }

    for (i = 0U; i < FSL_FEATURE_TSI_CHANNEL_COUNT; i++)
    {
        calBuff->calibratedData[i] = TSI_GetNormalModeCounter(base, i);
    }
    TSI_ClearStatusFlags(base, kTSI_EndOfScanFlag);
    TSI_EnableChannels(base, 0xFFFFU, false);

    if (is_int_enabled)
    {
        TSI_EnableInterrupts(base, kTSI_GlobalInterruptEnable);
    }
}

/*!
 * brief Enables the TSI interrupt requests.
 * param base TSI peripheral base address.
 * param mask interrupt source
 *     The parameter can be a combination of the following source if defined:
 *     arg kTSI_GlobalInterruptEnable
 *     arg kTSI_EndOfScanInterruptEnable
 *     arg kTSI_OutOfRangeInterruptEnable
 *     arg kTSI_ErrorInterrruptEnable
 */
void TSI_EnableInterrupts(TSI_Type *base, uint32_t mask)
{
    uint32_t regValue = base->GENCS & (~ALL_FLAGS_MASK);

    if (mask & kTSI_GlobalInterruptEnable)
    {
        regValue |= TSI_GENCS_TSIIE_MASK;
    }
    if (mask & kTSI_OutOfRangeInterruptEnable)
    {
        regValue &= (~TSI_GENCS_ESOR_MASK);
    }
    if (mask & kTSI_EndOfScanInterruptEnable)
    {
        regValue |= TSI_GENCS_ESOR_MASK;
    }
    if (mask & kTSI_ErrorInterrruptEnable)
    {
        regValue |= TSI_GENCS_ERIE_MASK;
    }

    base->GENCS = regValue; /* write value to register */
}

/*!
 * brief Disables the TSI interrupt requests.
 * param base TSI peripheral base address.
 * param mask interrupt source
 *     The parameter can be a combination of the following source if defined:
 *     arg kTSI_GlobalInterruptEnable
 *     arg kTSI_EndOfScanInterruptEnable
 *     arg kTSI_OutOfRangeInterruptEnable
 *     arg kTSI_ErrorInterrruptEnable
 */
void TSI_DisableInterrupts(TSI_Type *base, uint32_t mask)
{
    uint32_t regValue = base->GENCS & (~ALL_FLAGS_MASK);

    if (mask & kTSI_GlobalInterruptEnable)
    {
        regValue &= (~TSI_GENCS_TSIIE_MASK);
    }
    if (mask & kTSI_OutOfRangeInterruptEnable)
    {
        regValue |= TSI_GENCS_ESOR_MASK;
    }
    if (mask & kTSI_EndOfScanInterruptEnable)
    {
        regValue &= (~TSI_GENCS_ESOR_MASK);
    }
    if (mask & kTSI_ErrorInterrruptEnable)
    {
        regValue &= (~TSI_GENCS_ERIE_MASK);
    }

    base->GENCS = regValue; /* write value to register */
}

/*!
 * brief Clears the interrupt flags.
 *
 * This function clears the TSI interrupt flags.
 * note The automatically cleared flags can't be cleared by this function.
 *
 * param base TSI peripheral base address.
 * param mask the status flags to clear.
 */
void TSI_ClearStatusFlags(TSI_Type *base, uint32_t mask)
{
    uint32_t regValue = base->GENCS & (~ALL_FLAGS_MASK);

    if (mask & kTSI_EndOfScanFlag)
    {
        regValue |= TSI_GENCS_EOSF_MASK;
    }
    if (mask & kTSI_OutOfRangeFlag)
    {
        regValue |= TSI_GENCS_OUTRGF_MASK;
    }
    if (mask & kTSI_ExternalElectrodeErrorFlag)
    {
        regValue |= TSI_GENCS_EXTERF_MASK;
    }
    if (mask & kTSI_OverrunErrorFlag)
    {
        regValue |= TSI_GENCS_OVRF_MASK;
    }

    base->GENCS = regValue; /* write value to register */
}
