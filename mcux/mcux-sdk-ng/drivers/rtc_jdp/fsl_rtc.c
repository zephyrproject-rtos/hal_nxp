/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_rtc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.rtc_jdp"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
static rtc_callback_t s_RtcCallback;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Ungates the RTC clock and configures the peripheral for basic operation.
 *
 * note This API should be called at the beginning of the application using the RTC driver.
 *
 * param base   RTC peripheral base address
 * param config Pointer to the user defined RTC configuration structure.
 *
 */
void RTC_Init(RTC_Type *base, const rtc_config_t *config)
{
    assert(config);
    uint32_t reg = 0;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(kCLOCK_Rtc);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    reg |= RTC_RTCC_CLKSEL(config->clockSource);

    reg |= (uint32_t)(config->clockDivide);

    if (config->freezeCounterInDebugMode)
    {
        reg |= (uint32_t)RTC_RTCC_FRZEN_MASK;
    }

    if (config->enableAnalogComparatorTrigger)
    {
        reg |= (uint32_t)RTC_RTCC_TRIG_EN_MASK;
    }

    base->RTCC = reg;

    if (config->registerAcessibleInSupervisorOnly)
    {
        base->RTCSUPV |= (uint32_t)RTC_RTCSUPV_SUPV_MASK;
    }
    else
    {
        base->RTCSUPV &= ~((uint32_t)RTC_RTCSUPV_SUPV_MASK);
    }
}

/*!
 * Deinit RTC. Diable the RTC counter and all interrupts.
 *
 * param base RTC peripheral base address
 */
void RTC_Deinit(RTC_Type *base)
{
    /* Disable RTC and API */
    base->RTCC &= ~((uint32_t)RTC_RTCC_CNTEN_MASK);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the module clock */
    CLOCK_DisableClock(kCLOCK_Rtc);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Fills in the RTC config struct with the default settings.
 *
 * The default values are as follows.
 * code
 *     config->clockSource                       = (rtc_clock_source_t)0U;
 *     config->clockDivide                       = kRTC_ClockDivide1;
 *     config->registerAcessibleInSupervisorOnly = false;
 *     config->freezeCounterInDebugMode          = true;
 *     config->enableAnalogComparatorTrigger     = false;
 * endcode
 * param config Pointer to the user's RTC configuration structure.
 */
void RTC_GetDefaultConfig(rtc_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->clockSource                       = (rtc_clock_source_t)0U;
    config->clockDivide                       = kRTC_ClockDivide1;
    config->registerAcessibleInSupervisorOnly = false;
    config->freezeCounterInDebugMode          = true;
    config->enableAnalogComparatorTrigger     = false;
}

/*!
 * brief Get the RTC Divide value.
 *
 * param base RTC peripheral base address
 * return The Divider value
 */
uint32_t RTC_GetDivideValue(RTC_Type *base)
{
    uint32_t divide = 1;

    if ((base->RTCC & (uint32_t)RTC_RTCC_DIV512EN_MASK) != 0U)
    {
        divide *= 512U;
    }
    if ((base->RTCC & (uint32_t)RTC_RTCC_DIV32EN_MASK) != 0U)
    {
        divide *= 32U;
    }

    return divide;
}

/*!
 * brief Register callback.
 *
 * param cb_func   callback function
 */
void RTC_RegisterCallBack(rtc_callback_t cb_func)
{
    s_RtcCallback = cb_func;
}

void RTC_DriverIRQHandler(void);
void RTC_DriverIRQHandler(void)
{
    uint32_t interrupt_flags             = 0U;
    volatile rtc_callback_type_t cb_type = (rtc_callback_type_t)0UL;

    /* Get and clear interrupt flags and get interrupt type. */
    interrupt_flags = RTC_GetInterruptFlags(RTC);

    if ((interrupt_flags & (uint32_t)kRTC_APIInterruptFlag) != 0U)
    {
        cb_type = kRTC_APICallback;
    }
    if ((interrupt_flags & (uint32_t)kRTC_CounterRollOverInterruptFlag) != 0U)
    {
        cb_type = kRTC_CounterRollOverCallback;
    }
    if ((interrupt_flags & (uint32_t)kRTC_RTCInterruptFlag) != 0U)
    {
        cb_type = kRTC_RTCCallback;
    }

    RTC_ClearInterruptFlags(RTC, interrupt_flags);

    if (s_RtcCallback != NULL)
    {
        s_RtcCallback(cb_type);
    }

    SDK_ISR_EXIT_BARRIER;
}