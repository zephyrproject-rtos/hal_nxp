/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_fmeas.h"

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.fmeas"
#endif

#if defined(FSL_FEATURE_FMEAS_ASYNC_SYSCON_FREQMECTRL) && (FSL_FEATURE_FMEAS_ASYNC_SYSCON_FREQMECTRL)
/*!
 * brief    Get the target clock counter value.
 *
 * param    base : Peripheral base address.
 * return   Target clock counter value.
 */
static inline uint32_t FMEAS_GetTargetClockCount(FMEAS_SYSCON_Type *base)
{
    return (uint32_t)(((((FMEAS_SYSCON_Type *)base)->FREQMECTRL & FMEAS_SYSCON_FREQMECTRL_CAPVAL_MASK) >>
                       FMEAS_SYSCON_FREQMECTRL_CAPVAL_SHIFT) + 1U);
}

/*!
 * brief    Get the reference clock counter value.
 *
 * return   Reference clock counter value.
 */
static inline uint32_t FMEAS_GetReferenceClockCount(void)
{
    return (uint32_t)((1U << FMEAS_INDEX) - 1U);
}

#elif defined(FSL_FEATURE_SOC_FREQME_COUNT) && (FSL_FEATURE_SOC_FREQME_COUNT)
/*!
 * brief    Get the target clock counter value.
 *
 * param    base : Peripheral base address.
 * return   Target clock counter value.
 */
static inline uint32_t FMEAS_GetTargetClockCount(FMEAS_SYSCON_Type *base)
{
    uint32_t capval = (uint32_t)(((FREQME_Type *)base)->FREQMECTRL_R & FREQME_FREQMECTRL_R_RESULT_MASK);

    /* INT30-C: Prevent unsigned integer underflow */
    assert(capval >= 2U);
    return capval - 2U;
}

/*!
 * brief    Get the reference clock counter value.
 *
 * return   Reference clock counter value.
 */
static inline uint32_t FMEAS_GetReferenceClockCount(void)
{
    return (uint32_t)(((uint32_t)1U) << 20U);
}

#else
/*!
 * brief    Get the target clock counter value.
 *
 * param    base : Peripheral base address.
 * return   Target clock counter value.
 */
static inline uint32_t FMEAS_GetTargetClockCount(FMEAS_SYSCON_Type *base)
{
    uint32_t capval = (uint32_t)((((SYSCON_Type *)base)->FREQMECTRL & SYSCON_FREQMECTRL_CAPVAL_MASK) >>
                                  SYSCON_FREQMECTRL_CAPVAL_SHIFT);
    /* INT30-C: Prevent unsigned integer underflow */
    assert(capval >= 2U);
    return capval - 2U;
}

/*!
 * brief    Get the reference clock counter value.
 *
 * return   Reference clock counter value.
 */
static inline uint32_t FMEAS_GetReferenceClockCount(void)
{
    return (uint32_t)((((uint32_t)SYSCON_FREQMECTRL_CAPVAL_MASK) >> (uint32_t)SYSCON_FREQMECTRL_CAPVAL_SHIFT) +
                        (uint32_t)1U);
}

#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief    Returns the computed value for a frequency measurement cycle
 *
 * param    base         : SYSCON peripheral base address.
 * param    refClockRate : Reference clock rate used during the frequency measurement cycle.
 *
 * return   Frequency in Hz.
 */
uint32_t FMEAS_GetFrequency(FMEAS_SYSCON_Type *base, uint32_t refClockRate)
{
    uint32_t targetClockCount = FMEAS_GetTargetClockCount(base);
    uint64_t clkrate          = 0;

    if (((int32_t)targetClockCount) > 0)
    {
        clkrate = (((uint64_t)targetClockCount) * (uint64_t)refClockRate) / FMEAS_GetReferenceClockCount();
    }

#if defined(SYSCON_CLOCK_CTRL_FRO1MHZ_FREQM_ENA_MASK) && defined(SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_MASK)
    /* Assume measurement complete - gate high freq clock FRO1M and XTAL32M to FMEAS */
    SYSCON->CLOCK_CTRL &= ~(SYSCON_CLOCK_CTRL_FRO1MHZ_FREQM_ENA_MASK | SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_MASK);
#endif

    return (uint32_t)(clkrate & 0xFFFFFFFFU);
}

#if defined(FSL_FEATURE_FMEAS_GET_COUNT_SCALE) && (FSL_FEATURE_FMEAS_GET_COUNT_SCALE)
void FMEAS_GetCountWithScale(FMEAS_SYSCON_Type *base,
                             uint8_t scale,
                             uint32_t *refClockCount,
                             uint32_t *targetClockCount)
{
    *targetClockCount = FMEAS_GetTargetClockCount(base);
    *refClockCount    = ((1UL << scale) - 1UL);

    /* Assume measurement complete - gate high freq clock FRO1M and XTAL32M to FMEAS */
    SYSCON->CLOCK_CTRL &= ~(SYSCON_CLOCK_CTRL_FRO1MHZ_FREQM_ENA_MASK | SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_MASK);
}
#endif /*FSL_FEATURE_FMEAS_GET_COUNT_SCALE*/
