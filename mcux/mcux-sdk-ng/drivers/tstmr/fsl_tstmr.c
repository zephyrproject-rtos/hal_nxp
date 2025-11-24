/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_tstmr.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tstmr"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#if defined(FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION) && FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION

/*!
 * @brief Get TSTMR instance index from base address.
 * @param base TSTMR peripheral base address.
 * @return Instance index.
 */
uint32_t TSTMR_GetInstance(TSTMR_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to Timer bases for each instance. */
static TSTMR_Type *const s_tstmrBases[FSL_FEATURE_SOC_TSTMR_COUNT] = TSTMR_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Clock mapping for each TSTMR instance. Use kCLOCK_NOGATE for instances without clocks */
static const clock_ip_name_t s_tstmrClockMap[FSL_FEATURE_SOC_TSTMR_COUNT] = TSTMR_CLOCKS;
#endif /* ! FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
uint32_t TSTMR_GetInstance(TSTMR_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < FSL_FEATURE_SOC_TSTMR_COUNT; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_tstmrBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < FSL_FEATURE_SOC_TSTMR_COUNT);

    return instance;
}

#endif /* FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION */

/*!
 * brief Init TSTMR.
 *
 * This function initializes the TSTMR module.
 *
 * param base TSTMR peripheral base address.
 */
void TSTMR_Init(TSTMR_Type *base)
{
#if defined(FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION) && FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_tstmrClockMap[TSTMR_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#endif /* FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION */
}

/*!
 * brief Deinit TSTMR.
 *
 * This function deinitializes the TSTMR module.
 *
 * param base TSTMR peripheral base address.
 */
void TSTMR_Deinit(TSTMR_Type *base)
{
#if defined(FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION) && FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_tstmrClockMap[TSTMR_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#endif /* FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION */
}

/*!
 * brief Delays for a specified number of microseconds.
 *
 * This function repeatedly reads the timestamp register and waits for the user-specified
 * delay value.
 *
 * param base      TSTMR peripheral base address.
 * param delayInUs Delay value in microseconds.
 */
void TSTMR_DelayUs(TSTMR_Type *base, uint64_t delayInUs)
{
#if defined(TSTMR_CLOCK_FREQUENCY_MHZ) || (defined(FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION) && \
                                           FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION)
#if defined(TSTMR_CLOCK_FREQUENCY_MHZ)
    uint64_t targetTicks = TSTMR_CLOCK_FREQUENCY_MHZ * delayInUs;
#elif defined(FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION) && \
    FSL_FEATURE_TSTMR_HAS_CLOCK_FREQUENCY_CONFIGURATION
    uint32_t instance = TSTMR_GetInstance(base);
    /* Get the TSTMR clock frequency in Hz */
    uint32_t clockFreqHz = CLOCK_GetTstmrFreq(instance);
    assert(clockFreqHz > 0U);
    uint64_t targetTicks = (uint64_t)clockFreqHz * delayInUs / 1000000U;
#endif
    /* 56-bit mask */
    const uint64_t TSTMR_MASK = 0x00FFFFFFFFFFFFFFULL;
    uint64_t startTime        = TSTMR_ReadTimeStamp(base);
    while (true)
    {
        uint64_t currentTime = TSTMR_ReadTimeStamp(base);
        uint64_t elapsed;
        if (currentTime >= startTime)
        {
            elapsed = currentTime - startTime;
        }
        else
        {
            /* Timer wrapped, handle wrap around for 56 bits */
            elapsed = (TSTMR_MASK - startTime + 1U) + currentTime;
        }
        if (elapsed >= targetTicks)
        {
            break;
        }
    }
#else
    assert(0);
#endif
}