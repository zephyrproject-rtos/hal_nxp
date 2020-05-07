/*
 * Copyright (c) 2014 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "fsl_tsi_v2.h"

void TSI_Init(TSI_Type *base, const tsi_config_t *config)
{
    assert(config != NULL);

    bool is_module_enabled = false;
    bool is_int_enabled = false;

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

void TSI_Deinit(TSI_Type *base)
{
    base->GENCS = 0U;
    base->SCANC = 0U;
    base->PEN = 0U;
    base->THRESHOLD = 0U;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(kCLOCK_Tsi0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void TSI_GetNormalModeDefaultConfig(tsi_config_t *userConfig)
{
    userConfig->thresh = 0U;
    userConfig->thresl = 0U;
    userConfig->lpclks = kTSI_LowPowerClockSource_LPOCLK;
    userConfig->lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig->amclks = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig->ampsc = kTSI_ActiveModePrescaler_8div;
    userConfig->ps = kTSI_ElecOscPrescaler_2div;
    userConfig->extchrg = kTSI_ExtOscChargeCurrent_10uA;
    userConfig->refchrg = kTSI_RefOscChargeCurrent_10uA;
    userConfig->nscn = kTSI_ConsecutiveScansNumber_8time;
}

void TSI_GetLowPowerModeDefaultConfig(tsi_config_t *userConfig)
{
    userConfig->thresh = 15000U;
    userConfig->thresl = 1000U;
    userConfig->lpclks = kTSI_LowPowerClockSource_LPOCLK;
    userConfig->lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig->amclks = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig->ampsc = kTSI_ActiveModePrescaler_64div;
    userConfig->ps = kTSI_ElecOscPrescaler_1div;
    userConfig->extchrg = kTSI_ExtOscChargeCurrent_2uA;
    userConfig->refchrg = kTSI_RefOscChargeCurrent_32uA;
    userConfig->nscn = kTSI_ConsecutiveScansNumber_26time;
}

void TSI_Calibrate(TSI_Type *base, tsi_calibration_data_t *calBuff)
{
    assert(calBuff != NULL);

    uint8_t i = 0U;
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

    base->GENCS = regValue;     /* write value to register */
}

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

    base->GENCS = regValue;     /* write value to register */
}

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

    base->GENCS = regValue;     /* write value to register */
}
