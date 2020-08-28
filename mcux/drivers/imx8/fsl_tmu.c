/*
 * Copyright 2018, NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_tmu.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tmu_1"
#endif

/*! @brief TEMPMON calibration data mask. */
#define TMU_ROOMTEMPMASK 0xFFU
#define TMU_ROOMTEMPSHIFT 0x00U
#define TMU_HOTTEMPMASK 0xFF00U
#define TMU_HOTTEMPSHIFT 0x08U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for TMU module.
 *
 * @param base TMU peripheral base address
 */
static uint32_t TMU_GetInstance(TMU_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint32_t s_roomTemp; /*!< The value of fuse at room temperature .*/

/*! @brief Pointers to TMU bases for each instance. */
static TMU_Type *const s_tmuBases[] = TMU_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to TMU clocks for each instance. */
static const clock_ip_name_t s_tmuClocks[] = TMU_CLOCKS;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t TMU_GetInstance(TMU_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_tmuBases); instance++)
    {
        if (s_tmuBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_tmuBases));

    return instance;
}

void TMU_Init(TMU_Type *base, const tmu_config_t *config)
{
    assert(NULL != base);
    assert(NULL != config);
    uint32_t calibrationData;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable TMU clock. */
    CLOCK_EnableClock(s_tmuClocks[TMU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL. */

    /* Disable TMU monitor mode. */
    TMU_Enable(base, false);

    /* Clear interrupt relevant register. */
    TMU_ClearInterruptStatusFlags(base, kTMU_ImmediateTemperatureStatusFlags | kTMU_AverageTemperatureStatusFlags |
                                            kTMU_AverageTemperatureCriticalStatusFlags);

    /* Update TCALIV with the room value from FUSE. */
    /* calibrationData = (*(uint32_t *)0x303504F0) & 0xFF;*/
    calibrationData = 0x2EU;
    s_roomTemp      = (uint32_t)(calibrationData & TMU_ROOMTEMPMASK) >> TMU_ROOMTEMPSHIFT;
    base->TCALIV |= TMU_TCALIV_SNSR25C(s_roomTemp);

    /* Configure TER register. */
    base->TER = TMU_TER_ALPF(config->averageLPF);

    /* Configure TASR register. */
    base->TASR = TMU_TASR_BUF_SLOP_SEL(config->amplifierGain) | TMU_TASR_BUF_VERF_SEL(config->amplifierVref);
}

void TMU_Deinit(TMU_Type *base)
{
    /* Disable TMU monitor mode.. */
    TMU_Enable(base, false);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable TMU clock. */
    CLOCK_DisableClock(s_tmuClocks[TMU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL. */
}

void TMU_GetDefaultConfig(tmu_config_t *config)
{
    assert(NULL != config);

    config->amplifierGain = kTMU_AmplifierGain8_08;
    config->amplifierVref = kTMU_AmplifierReferenceVoltage652_5;
    config->averageLPF    = kTMU_AverageLowPassFilter0_5;
}

void TMU_GetInterruptStatusFlags(TMU_Type *base, tmu_interrupt_status_t *status)
{
    assert(NULL != status);

    status->interruptDetectMask = base->TIDR;
}

void TMU_ClearInterruptStatusFlags(TMU_Type *base, uint32_t mask)
{
    /* For immediate temperature threshold interrupt. */
    if (0U != (kTMU_ImmediateTemperatureStatusFlags & mask))
    {
        base->TIER = TMU_TIER_ITTEIE_MASK; /* Clear interrupt detect register. */
    }
    /* For average temperature threshold interrupt. */
    if (0U != (kTMU_AverageTemperatureStatusFlags & mask))
    {
        base->TIER = TMU_TIER_ATTEIE_MASK; /* Clear interrupt detect register. */
    }
    /* For Average temperature critical threshold interrupt. */
    if (0U != (kTMU_AverageTemperatureCriticalStatusFlags & mask))
    {
        base->TIER = TMU_TIER_ATCTEIE_MASK; /* Clear interrupt detect register. */
    }
}

status_t TMU_GetImmediateTemperature(TMU_Type *base, uint32_t *temperature)
{
    assert(NULL != temperature);

    if (0U == (TMU_TRITSR_V_MASK & base->TRITSR))
    {
        return kStatus_Fail;
    }
    else
    {
        *temperature = (TMU_TRITSR_TEMP_MASK & base->TRITSR) >> TMU_TRITSR_TEMP_SHIFT;
        return kStatus_Success;
    }
}

status_t TMU_GetAverageTemperature(TMU_Type *base, uint32_t *temperature)
{
    assert(NULL != temperature);

    if (0U == (TMU_TRATSR_V_MASK & base->TRATSR))
    {
        return kStatus_Fail;
    }
    else
    {
        *temperature = (TMU_TRATSR_TEMP_MASK & base->TRATSR) >> TMU_TRATSR_TEMP_SHIFT;
        return kStatus_Success;
    }
}

void TMU_SetHighTemperatureThresold(TMU_Type *base, const tmu_thresold_config_t *config)
{
    assert(NULL != config);

    /* Configure the high temperature immediate threshold. */
    if (config->immediateThresoldEnable)
    {
        base->TMHTITR = TMU_TMHTITR_EN_MASK | TMU_TMHTITR_TEMP(config->immediateThresoldValue);
    }
    else
    {
        base->TMHTITR = 0U;
    }
    /* Configure the high temperature average threshold. */
    if (config->AverageThresoldEnable)
    {
        base->TMHTATR = TMU_TMHTATR_EN_MASK | TMU_TMHTATR_TEMP(config->averageThresoldValue);
    }
    else
    {
        base->TMHTATR = 0U;
    }
    /* Configure the high temperature average critical threshold. */
    if (config->AverageCriticalThresoldEnable)
    {
        base->TMHTACTR = TMU_TMHTACTR_EN_MASK | TMU_TMHTACTR_TEMP(config->averageCriticalThresoldValue);
    }
    else
    {
        base->TMHTACTR = 0U;
    }
}
