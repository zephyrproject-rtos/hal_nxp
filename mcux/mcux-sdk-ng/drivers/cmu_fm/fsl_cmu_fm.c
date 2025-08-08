/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_cmu_fm.h"
#include <math.h> /* Using ceil() function to convert float variable to int. */
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.cmu_fm"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Gets the instance from the base address
 *
 * @param base CMU_FM peripheral base address
 *
 * @return The CMU_FM instance
 */
static uint32_t CMU_FM_GetInstance(CMU_FM_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to CMU_FM bases for each instance. */
static CMU_FM_Type *const s_cmufmBases[] = CMU_FM_BASE_PTRS;

/*! @brief Pointers real ISRs installed by drivers for each instance. */
static cmu_fm_callback_t s_cmufmCallback[ARRAY_SIZE(s_cmufmBases)] = {0};

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t CMU_FM_GetInstance(CMU_FM_Type *base)
{
    uint32_t instance;
    uint32_t cmufmArrayCount = ARRAY_SIZE(s_cmufmBases);

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < cmufmArrayCount; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_cmufmBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < cmufmArrayCount);

    return instance;
}

/*!
 * brief Initializes CMU_FM configure structure.
 *
 * This function initializes the CMU_FM configure structure to default value. The default
 * value are:
 * code
 *  config->refClockCount = CMU_FM_RCCR_REF_CNT_MASK;
 *  config->enableInterrupt = true;
 * endcode
 *
 * param config Pointer to CMU_FM config structure.
 * see cmu_fm_config_t
 */
void CMU_FM_GetDefaultConfig(cmu_fm_config_t *config)
{
    (void)memset(config, 0, sizeof(*config));
    /* Set reference clock count cycles to max value */
    config->refClockCount = CMU_FM_RCCR_REF_CNT_MASK;
    /* Enable interrupt */
    config->enableInterrupt = true;
}

/*!
 * brief Initializes the CMU_FM.
 *
 * This function configures the peripheral for basic operation.
 *
 * param base   CMU_FM peripheral base address
 * param config The configuration of CMU_FM
 * retval kStatus_Success Successfully initialize CMU_FM.
 * retval kStatus_Fail Initialize failed, because the module can not be initialized when GCR[FME] = 1.
 */
status_t CMU_FM_Init(CMU_FM_Type *base, const cmu_fm_config_t *config)
{
    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /*Enable clock for CMU 0-5*/
    CLOCK_EnableClock(kCLOCK_Cmu05);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Writes to RCCR and IER are disabled after GCR[FME] = 1, attempting a write
     * to any of them after GCR[FME] = 1 generates a bus transfer error*/
    if (0U == (base->GCR & CMU_FM_GCR_FME_MASK))
    {
        /* Set Reference Count Configuration Register*/
        CMU_FM_SetRefClkCnt(base, config->refClockCount);

        if (config->enableInterrupt)
        {
            /* Enable Frequency Meter Complete Interrupt*/
            CMU_FM_EnableInterrupts(base);
        }
        else
        {
            /* Disable Frequency Meter Complete Interrupt*/
            CMU_FM_DisableInterrupts(base);
        }

        return kStatus_Success;
    }
    else
    {
        return kStatus_Fail;
    }
}

/*!
 * brief Shuts down the CMU_FM.
 *
 * param base CMU_FM peripheral base address
 */
void CMU_FM_Deinit(CMU_FM_Type *base)
{
    /* Stop ongoing frequency metering */
    if ((uint32_t)kCMU_FM_Running == (base->SR & CMU_FM_SR_RS_MASK))
    {
        CMU_FM_StopFreqMetering(base);
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
* param bus_clk CMU_FM bus clock
* param monitored_clk The expected frequency of monitored clock
* return Minimum reference count
*/
uint32_t CMU_FM_CalcMinRefClkCnt(uint32_t ref_clk, uint32_t bus_clk, uint32_t monitored_clk)
{
    float value1    = 3.0f * ((float)ref_clk / (float)bus_clk);
    float value2    = 8.0f + 5.0f * ((float)ref_clk / (float)monitored_clk);
    float max_value = (value1 > value2) ? value1 : value2;

    return (uint32_t)(ceil((double)max_value));
}

/*!
 * brief Register callback.
 *
 * param base      CMU_FM peripheral base address
 * param cb_func   callback function
 */
void CMU_FM_RegisterCallBack(CMU_FM_Type *base, cmu_fm_callback_t cb_func)
{
    uint32_t index         = CMU_FM_GetInstance(base);
    s_cmufmCallback[index] = cb_func;
}

/* IRQ handler functions overloading weak symbols in the startup */
void CMU_FM_DriverIRQHandler(uint32_t idx)
{
    if (idx > ARRAY_SIZE(s_cmufmBases))
    {
        return;
    }
    /* Clear status*/
    uint32_t statusFlags = CMU_FM_GetStatusFlags(s_cmufmBases[idx]);
    CMU_FM_ClearStatusFlags(s_cmufmBases[idx], statusFlags);

    /* handle user interrupt callback*/
    if (s_cmufmCallback[idx] != NULL)
    {
        s_cmufmCallback[idx](statusFlags);
    }

    SDK_ISR_EXIT_BARRIER;
}
