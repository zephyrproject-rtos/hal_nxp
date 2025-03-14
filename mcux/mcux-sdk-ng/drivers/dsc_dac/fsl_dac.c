/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dac.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_dac"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * brief Gets the instance from the base address.
 *
 * param base DAC peripheral base address
 *
 * return The DAC instance
 */
static uint32_t DAC_GetInstance(DAC_Type *base);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static DAC_Type *const s_dacBases[] = DAC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * brief Pointer to DAC clocks for each instance.
 */
static const clock_ip_name_t s_dacClocks[] = DAC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
/*******************************************************************************
 * Code
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
static uint32_t DAC_GetInstance(DAC_Type *base)
{
    uint32_t u32Instance;

    /* Find the instance index from base address mappings. */
    for (u32Instance = 0U; u32Instance < ARRAY_SIZE(s_dacBases); u32Instance++)
    {
        if (s_dacBases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_dacBases));

    return u32Instance;
}
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*!
 * brief Initializes the DAC resource, including data format, SYNC signal, operation mode, etc.
 *
 * param base DAC peripheral base address.
 * param psConfig The pointer to dac_config_t.
 */
void DAC_Init(DAC_Type *base, const dac_config_t *psConfig)
{
    assert(psConfig != NULL);

    uint16_t u16Tmp = 0U;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enables the clock. */
    (void)CLOCK_EnableClock(s_dacClocks[DAC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    if (psConfig->bEnableAnalogPortion)
    {
        base->CTRL0 &= ~DAC_CTRL0_PDN_MASK;
        /* The analog block requires 12 us to recover from the power-down state before proper operation is guaranteed.
         */
        SDK_DelayAtLeastUs(12, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    }
    else
    {
        base->CTRL0 |= DAC_CTRL0_PDN_MASK;
    }

    u16Tmp = base->CTRL0;
#if (defined(FSL_FEATURE_DAC_HAS_SYNC_EDGE) && FSL_FEATURE_DAC_HAS_SYNC_EDGE)
    u16Tmp &= ~(DAC_CTRL0_FORMAT_MASK | DAC_CTRL0_HSLS_MASK | DAC_CTRL0_FILT_EN_MASK | DAC_CTRL0_SYNC_EN_MASK |
                DAC_CTRL0_SYNCEDGE_MASK | DAC_CTRL0_AUTO_MASK | DAC_CTRL0_DOWN_MASK | DAC_CTRL0_UP_MASK);
#else
    u16Tmp &= ~(DAC_CTRL0_FORMAT_MASK | DAC_CTRL0_HSLS_MASK | DAC_CTRL0_FILT_EN_MASK | DAC_CTRL0_SYNC_EN_MASK |
                DAC_CTRL0_AUTO_MASK | DAC_CTRL0_DOWN_MASK | DAC_CTRL0_UP_MASK);
#endif
#if (defined(FSL_FEATURE_DAC_HAS_SYNC_EDGE) && FSL_FEATURE_DAC_HAS_SYNC_EDGE)
    u16Tmp |= DAC_CTRL0_FORMAT(psConfig->eDataFormat) | DAC_CTRL0_HSLS(psConfig->eSpeedMode) |
              DAC_CTRL0_FILT_EN(psConfig->bEnableGlitchFilter) | DAC_CTRL0_SYNCEDGE(psConfig->eSyncInputEdge);
#else
    u16Tmp |= DAC_CTRL0_FORMAT(psConfig->eDataFormat) | DAC_CTRL0_HSLS(psConfig->eSpeedMode) |
              DAC_CTRL0_FILT_EN(psConfig->bEnableGlitchFilter);
#endif
    base->CTRL0 = u16Tmp;

    base->CTRL1 = DAC_CTRL1_FILT_CNT(psConfig->u8GlitchFilterCount);

    if (psConfig->eOperationMode == kDAC_NormalOperationMode)
    {
        u16Tmp = base->CTRL0;
        u16Tmp &= ~(DAC_CTRL0_SYNC_EN_MASK);
        u16Tmp |= DAC_CTRL0_SYNC_EN(psConfig->eSyncSignal);
        if (psConfig->uOperationConfig.sNormalModeConfig.bEnableDMA)
        {
            u16Tmp |= DAC_CTRL0_DMA_EN_MASK;
            u16Tmp &= ~DAC_CTRL0_WTMK_LVL_MASK;
            u16Tmp |= DAC_CTRL0_WTMK_LVL(psConfig->uOperationConfig.sNormalModeConfig.eWatermarkLevel);
        }
        else
        {
            u16Tmp &= ~DAC_CTRL0_DMA_EN_MASK;
        }
        base->CTRL0 = u16Tmp;
        DAC_WriteDataFIFO(base, psConfig->uOperationConfig.sNormalModeConfig.u16DataFIFO);
    }
    else
    {
        u16Tmp = base->CTRL0;
#if (defined(FSL_FEATURE_DAC_HAS_ONE_SHOT) && FSL_FEATURE_DAC_HAS_ONE_SHOT)
        u16Tmp &= ~(DAC_CTRL0_ONESHOT_MASK | DAC_CTRL0_SYNC_EN_MASK);
#else
        u16Tmp &= ~DAC_CTRL0_SYNC_EN_MASK;
#endif
        u16Tmp |= DAC_CTRL0_SYNC_EN(psConfig->eSyncSignal);

        /* Set the starting value firstly. */
        DAC_WriteDataFIFO(base, psConfig->uOperationConfig.sAutomaticModeConfig.u16StartValue);
#if (defined(FSL_FEATURE_DAC_HAS_COMPARE_VAL) && FSL_FEATURE_DAC_HAS_COMPARE_VAL)
        base->COMPARE = DAC_COMPARE_COMPARE(psConfig->uOperationConfig.sAutomaticModeConfig.u16CompareValue);
#endif

        DAC_WriteStepSize(base, psConfig->uOperationConfig.sAutomaticModeConfig.u16StepSize);
        DAC_WriteMinValue(base, psConfig->uOperationConfig.sAutomaticModeConfig.u16MinValue);
        DAC_WriteMaxValue(base, psConfig->uOperationConfig.sAutomaticModeConfig.u16MaxValue);
#if (defined(FSL_FEATURE_DAC_HAS_ONE_SHOT) && FSL_FEATURE_DAC_HAS_ONE_SHOT)
        if (psConfig->uOperationConfig.sAutomaticModeConfig.eWaveformType >= kDAC_OneShotSawtoothWaveform0)
        {
            u16Tmp |= DAC_CTRL0_ONESHOT_MASK;
        }
#endif
        switch (psConfig->uOperationConfig.sAutomaticModeConfig.eWaveformType)
        {
            case kDAC_RepeatSawtoothWaveform0:
            case kDAC_OneShotSawtoothWaveform0:
            {
                u16Tmp |= DAC_CTRL0_UP_MASK | DAC_CTRL0_AUTO_MASK;
                base->CTRL0 = u16Tmp;
                break;
            }

            case kDAC_RepeatSawtoothWaveform1:
            case kDAC_OneShotSawtoothWaveform1:
            {
                u16Tmp |= DAC_CTRL0_DOWN_MASK | DAC_CTRL0_AUTO_MASK;
                base->CTRL0 = u16Tmp;
                break;
            }
            case kDAC_RepeatTriangleWaveform0:
            {
                /* Initial up then down. */
                u16Tmp |= DAC_CTRL0_DOWN_MASK | DAC_CTRL0_AUTO_MASK;
                base->CTRL0 = u16Tmp;
                base->CTRL0 |= DAC_CTRL0_UP_MASK;
                break;
            }
            case kDAC_RepeatTriangleWaveform1:
            {
                /* Initial down then up. */
                u16Tmp |= DAC_CTRL0_UP_MASK | DAC_CTRL0_AUTO_MASK;
                base->CTRL0 = u16Tmp;
                base->CTRL0 |= DAC_CTRL0_DOWN_MASK;
                break;
            }
            default:
            {
                /* This branch will never be hit. */
                break;
            }
        }
    }
}

/*!
 * brief De-initializes the DAC resource, the clock and power will be gated off.
 *
 * Invoke this function to power down the analog portion of DAC and disable the DAC clock.
 *
 * param base DAC peripheral base address.
 */
void DAC_Deinit(DAC_Type *base)
{
    /* Powers down the analog portion of the DAC when the DAC is not in use. */
    DAC_EnableAnalogPortion(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disables the clock. */
    (void)CLOCK_DisableClock(s_dacClocks[DAC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default DAC configs, such as operation mode, watermark level, SYNC signal, etc.
 *
 * code
        psConfig->eOperationMode = kDAC_NormalOperationMode;
        psConfig->uOperationConfig.sNormalModeConfig.bEnableDMA      = false;
        psConfig->uOperationConfig.sNormalModeConfig.eWatermarkLevel = kDAC_WatermarkValue2;
        psConfig->eWatermarkLevel = kDAC_WatermarkValue2;
        psConfig->eSyncInputEdge                                   = kDAC_RisingEdge;
        psConfig->eSpeedMode                                       = kDAC_HighSpeedMode;
        psConfig->eDataFormat                                      = kDAC_DataWordRightJustified;
        psConfig->eSyncSignal                                       = kDAC_InternalClockSignal;
        psConfig->bEnableAnalogPortion                              = false;
        psConfig->bEnableGlitchFilter                              = true;
        psConfig->u8GlitchFilterCount                              = 29U;
    endcode
 *
 * param psConfig The pointer to ref dac_config_t.
 */
void DAC_GetDefaultConfig(dac_config_t *psConfig)
{
    assert(psConfig != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(dac_config_t));

    psConfig->eOperationMode                                     = kDAC_NormalOperationMode;
    psConfig->uOperationConfig.sNormalModeConfig.u16DataFIFO     = 0U;
    psConfig->uOperationConfig.sNormalModeConfig.bEnableDMA      = false;
    psConfig->uOperationConfig.sNormalModeConfig.eWatermarkLevel = kDAC_WatermarkValue2;
#if (defined(FSL_FEATURE_DAC_HAS_SYNC_EDGE) && FSL_FEATURE_DAC_HAS_SYNC_EDGE)
    psConfig->eSyncInputEdge = kDAC_RisingEdge;
#endif
    psConfig->eSpeedMode           = kDAC_HighSpeedMode;
    psConfig->eDataFormat          = kDAC_DataWordRightJustified;
    psConfig->eSyncSignal          = kDAC_InternalClockSignal;
    psConfig->bEnableAnalogPortion = false;
    psConfig->bEnableGlitchFilter  = true;
    psConfig->u8GlitchFilterCount  = 29U;
}
