/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_cmu_fc.h"
#include <math.h> /* Using ceil() function to convert float variable to int. */
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.cmu_fc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Gets the instance from the base address
 *
 * @param base CMU_FC peripheral base address
 *
 * @return The CMU_FC instance
 */
static uint32_t CMU_FC_GetInstance(CMU_FC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to CMU_FC bases for each instance. */
static CMU_FC_Type *const s_cmufcBases[] = CMU_FC_BASE_PTRS;

/*! @brief Pointers real ISRs installed by drivers for each instance. */
static cmu_fc_callback_t s_cmufcCallback[ARRAY_SIZE(s_cmufcBases)] = {0};

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t CMU_FC_GetInstance(CMU_FC_Type *base)
{
    uint32_t instance;
    uint32_t cmufcArrayCount = ARRAY_SIZE(s_cmufcBases);

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < cmufcArrayCount; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_cmufcBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < cmufcArrayCount);

    return instance;
}

/*!
 * brief Initializes CMU_FC configure structure.
 *
 * This function initializes the CMU_FC configure structure to default value. The default
 * value are:
 * code
 *  config->refClockCount = CMU_FC_RCCR_REF_CNT_MASK;
 *  config->interruptEnable = kCMU_FC_LowerThanLowThrAsyncInterruptEnable | kCMU_FC_HigherThanHighThrAsyncInterruptEnable;
 * endcode
 *
 * param config Pointer to CMU_FC config structure.
 * see cmu_fc_config_t
 */
void CMU_FC_GetDefaultConfig(cmu_fc_config_t *config)
{
    (void)memset(config, 0, sizeof(*config));
    /* Set reference clock count cycles to max value */
    config->refClockCount = CMU_FC_RCCR_REF_CNT_MASK;
    /* Enable Frequency Higher than High Frequency Reference Threshold Asynchronous Interrupt
       and Frequency Lower than Low Frequency Reference Threshold Asynchronous Interrupt */
    config->interruptEnable = (uint32_t)kCMU_FC_LowerThanLowThrAsyncInterruptEnable | (uint32_t)kCMU_FC_HigherThanHighThrAsyncInterruptEnable;
}

/*!
 * brief Initializes the CMU_FC.
 *
 * This function configures the peripheral for basic operation.
 *
 * param base   CMU_FC peripheral base address
 * param config The configuration of CMU_FC
 * retval kStatus_Success Successfully initialize CMU_FC.
 * retval kStatus_Fail Initialize failed, because the module can not be initialized when GCR[FCE] = 1.
 */
status_t CMU_FC_Init(CMU_FC_Type *base, const cmu_fc_config_t *config)
{
    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /*Enable clock for CMU 0-5*/
    CLOCK_EnableClock(kCLOCK_Cmu05);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Writes to to RCCR, HTCR, LTCR, or IER are disabled after GCR[FCE] = 1, attempting a write
     * to any of them after GCR[FCE] = 1 generates a bus transfer error*/
    if (0U == (base->GCR & CMU_FC_GCR_FCE_MASK))
    {
        /* Set Reference Count Configuration Register*/
        CMU_FC_SetRefClkCnt(base, config->refClockCount);

        if (0U != config->interruptEnable)
        {
            /* Enable Frequency Check Interrupt*/
            CMU_FC_EnableInterrupts(base, config->interruptEnable);
        }
        else
        {
            /* Disable Frequency Check Interrupt*/
            CMU_FC_DisableInterrupts(
                base, CMU_FC_IER_FLLIE_MASK | CMU_FC_IER_FHHIE_MASK | CMU_FC_IER_FLLAIE_MASK | CMU_FC_IER_FHHAIE_MASK);
        }
        /* Set high reference value for the monitored clock frequency */
        CMU_FC_SetHighThresholdClkCnt(base, config->highThresholdCnt);
        
        /* Set low reference value for the monitored clock frequency */
        CMU_FC_SetLowThresholdClkCnt(base, config->lowThresholdCnt);

        return kStatus_Success;
    }
    else
    {
        return kStatus_Fail;
    }
}

/*!
 * brief Shuts down the CMU_FC.
 *
 * param base CMU_FC peripheral base address
 */
void CMU_FC_Deinit(CMU_FC_Type *base)
{
    /* Stop ongoing frequency checking */
    if ((uint32_t)kCMU_FC_Running == (base->SR & CMU_FC_SR_RS_MASK))
    {
        CMU_FC_StopFreqChecking(base);
    }
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable clock for CMU 0-5 */
    CLOCK_DisableClock(kCLOCK_Cmu05);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Calculate minimum reference clock count cycle.
 *
 * Note: Higher values of reference count results in longer metering window, leading to better
          accuracy in metered clock measurement.
 * param ref_clk Reference clock frequency
 * param bus_clk CMU_FC bus clock
 * param monitored_clk The expected frequency of monitored clock
 * return Minimum reference count
 */
uint32_t CMU_FC_CalcMinRefClkCnt(uint32_t ref_clk, uint32_t bus_clk, uint32_t monitored_clk)
{
    float value1    = 3.0f * ((float)ref_clk / (float)bus_clk);
    float value2    = 8.0f + 5.0f * ((float)ref_clk / (float)monitored_clk);
    float max_value = (value1 > value2) ? value1 : value2;

    return (uint32_t)(ceil((double)max_value));
}

/*!
 * brief Calculate optimum high frequency reference threshold and low frequency reference threshold
 *
 * param config Pointer to a CMU_FC configuration structure
 * param monitored_clk The expected frequency of monitored clock
 * param monitored_clk_deviation The deviation of monitored clock
 * param ref_clk Reference clock frequency
 * param ref_clk_deviation The deviation of reference clock
 */
void CMU_FC_CalcOptimumThreshold(cmu_fc_config_t *config,
                                 uint32_t monitored_clk,
                                 float monitored_clk_deviation,
                                 uint32_t ref_clk,
                                 float ref_clk_deviation)
{
    assert(0U != config->refClockCount);
    float f_m_clk_max = (float)monitored_clk * (1.0f + monitored_clk_deviation);
    float f_m_clk_min = (float)monitored_clk * (1.0f - monitored_clk_deviation);

    float f_ref_clk_max = (float)ref_clk * (1.0f + ref_clk_deviation);
    float f_ref_clk_min = (float)ref_clk * (1.0f - ref_clk_deviation);

    config->highThresholdCnt =
        (uint32_t)(ceil((double)((f_m_clk_max / f_ref_clk_min) * (float)config->refClockCount + 3.0f)));
    config->lowThresholdCnt =
        (uint32_t)(ceil((double)((f_m_clk_min / f_ref_clk_max) * (float)config->refClockCount - 3.0f)));
}

/*!
 * brief Register callback.
 *
 * param base      CMU_FC peripheral base address
 * param cb_func   callback function
 */
void CMU_FC_RegisterCallBack(CMU_FC_Type *base, cmu_fc_callback_t cb_func)
{
    uint32_t index         = CMU_FC_GetInstance(base);
    s_cmufcCallback[index] = cb_func;
}

/* IRQ handler functions overloading weak symbols in the startup */
void CMU_FC_DriverIRQHandler(uint32_t idx)
{
    if (idx > ARRAY_SIZE(s_cmufcBases))
    {
        return;
    }
    /* Clear status*/
    uint32_t statusFlags = CMU_FC_GetStatusFlags(s_cmufcBases[idx]);
    CMU_FC_ClearStatusFlags(s_cmufcBases[idx], statusFlags);

    /* handle user interrupt callback*/
    if (s_cmufcCallback[idx] != NULL)
    {
        s_cmufcCallback[idx](statusFlags);
    }

    SDK_ISR_EXIT_BARRIER;
}
