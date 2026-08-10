/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2023, 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sctimer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.sctimer"
#endif
#if defined(SCT_RSTS_N) || defined(SCT_RSTS)
#define FSL_FEATURE_SCT_HAS_RESET
#endif


/*! @brief Typedef for interrupt handler. */
typedef void (*sctimer_isr_t)(SCT_Type *base);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address
 *
 * @param base SCTimer peripheral base address
 *
 * @return The SCTimer instance
 */
static uint32_t SCTIMER_GetInstance(SCT_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to SCT bases for each instance. */
static SCT_Type *const s_sctBases[] = SCT_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to SCT clocks for each instance. */
static const clock_ip_name_t s_sctClocks[] = SCT_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(FSL_FEATURE_SCT_HAS_RESET)
#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
#if defined(FSL_FEATURE_SCT_WRITE_ZERO_ASSERT_RESET) && FSL_FEATURE_SCT_WRITE_ZERO_ASSERT_RESET
/*! @brief Pointers to SCT resets for each instance, writing a zero asserts the reset */
static const reset_ip_name_t s_sctResets[] = SCT_RSTS_N;
#else
/*! @brief Pointers to SCT resets for each instance, writing a one asserts the reset */
static const reset_ip_name_t s_sctResets[] = SCT_RSTS;
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */
#endif /* FSL_FEATURE_SCT_HAS_RESET */

/*!< @brief SCTimer event Callback function. */
static sctimer_event_callback_t s_eventCallback[FSL_FEATURE_SCT_NUMBER_OF_EVENTS];

/*!< @brief Keep track of SCTimer event number */
static uint32_t s_currentEvent;

/*!< @brief Keep track of SCTimer state number */
static uint32_t s_currentState;

/*!< @brief Keep track of SCTimer unify 32-bit or low 16-bit match/capture register number. */
static uint32_t s_currentMatch;
/*!< @brief Keep track of SCTimer high 16-bit match/capture register number. */
static uint32_t s_currentMatchhigh;

/*! @brief Pointer to SCTimer IRQ handler */
static sctimer_isr_t s_sctimerIsr;

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t SCTIMER_GetInstance(SCT_Type *base)
{
    uint32_t instance;
    uint32_t sctArrayCount = (sizeof(s_sctBases) / sizeof(s_sctBases[0]));

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < sctArrayCount; instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_sctBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < sctArrayCount);

    return instance;
}

/*!
 * brief Ungates the SCTimer clock and configures the peripheral for basic operation.
 *
 * note This API should be called at the beginning of the application using the SCTimer driver.
 *
 * param base   SCTimer peripheral base address
 * param config Pointer to the user configuration structure.
 *
 * return kStatus_Success indicates success; Else indicates failure.
 */
status_t SCTIMER_Init(SCT_Type *base, const sctimer_config_t *config)
{
    assert(NULL != config);

    uint32_t i;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the SCTimer clock*/
    CLOCK_EnableClock(s_sctClocks[SCTIMER_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(FSL_FEATURE_SCT_HAS_RESET)
#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
    /* Reset the module. */
    RESET_PeripheralReset(s_sctResets[SCTIMER_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */
#endif /* FSL_FEATURE_SCT_HAS_RESET */

    /* Setup the counter operation. For Current Driver interface SCTIMER_Init don't know detail
     * frequency of input clock, but User know it. So the INSYNC have to set by user level. */
    base->CONFIG = SCT_CONFIG_CKSEL(config->clockSelect) | SCT_CONFIG_CLKMODE(config->clockMode) |
                   SCT_CONFIG_UNIFY(config->enableCounterUnify ? 1U : 0U) | SCT_CONFIG_INSYNC(config->inputsync);

    /* Write to the control register, keep the counters halted. */
    base->CTRL =
        SCT_CTRL_BIDIR_L(config->enableBidirection_l ? 1U : 0U) | SCT_CTRL_PRE_L(config->prescale_l) | SCT_CTRL_HALT_L_MASK;
    /* Clear the counter after changing the PRE value. */
    base->CTRL |= SCT_CTRL_CLRCTR_L_MASK;

    if (!(config->enableCounterUnify))
    {
        base->CTRL |=
            SCT_CTRL_BIDIR_H(config->enableBidirection_h ? 1U : 0U) | SCT_CTRL_PRE_H(config->prescale_h) | SCT_CTRL_HALT_H_MASK;
        base->CTRL |= SCT_CTRL_CLRCTR_H_MASK;
    }

    /* Initial state of channel output */
    base->OUTPUT = config->outInitState;

    /* Clear the global variables */
    s_currentEvent     = 0U;
    s_currentState     = 0U;
    s_currentMatch     = 0U;
    s_currentMatchhigh = 0U;

    /* Clear the callback array */
    for (i = 0; i < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS; i++)
    {
        s_eventCallback[i] = NULL;
    }

    /* Save interrupt handler */
    s_sctimerIsr = &SCTIMER_EventHandleIRQ;

    return kStatus_Success;
}

/*!
 * brief Gates the SCTimer clock.
 *
 * param base SCTimer peripheral base address
 */
void SCTIMER_Deinit(SCT_Type *base)
{
    /* Halt the counters */
    base->CTRL |= (SCT_CTRL_HALT_L_MASK | SCT_CTRL_HALT_H_MASK);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the SCTimer clock*/
    CLOCK_DisableClock(s_sctClocks[SCTIMER_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief  Fills in the SCTimer configuration structure with the default settings.
 *
 * The default values are:
 * code
 *  config->enableCounterUnify = true;
 *  config->clockMode = kSCTIMER_System_ClockMode;
 *  config->clockSelect = kSCTIMER_Clock_On_Rise_Input_0;
 *  config->enableBidirection_l = false;
 *  config->enableBidirection_h = false;
 *  config->prescale_l = 0U;
 *  config->prescale_h = 0U;
 *  config->outInitState = 0U;
 *  config->inputsync  = 0xFU;
 * endcode
 * param config Pointer to the user configuration structure.
 */
void SCTIMER_GetDefaultConfig(sctimer_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* SCT operates as a unified 32-bit counter */
    config->enableCounterUnify = true;
    /* System clock clocks the entire SCT module */
    config->clockMode = kSCTIMER_System_ClockMode;
    /* This is used only by certain clock modes */
    config->clockSelect = kSCTIMER_Clock_On_Rise_Input_0;
    /* Up count mode only for the unified counter */
    config->enableBidirection_l = false;
    /* Up count mode only for Counte_H */
    config->enableBidirection_h = false;
    /* Prescale factor of 1 */
    config->prescale_l = 0U;
    /* Prescale factor of 1 for Counter_H*/
    config->prescale_h = 0U;
    /* Clear outputs */
    config->outInitState = 0U;
    /* Default value is 0xFU, it can be clear as 0 when speical conditions met.
     * Condition can be clear as 0: (for all Clock Modes):
     * (1) The corresponding input is already synchronous to the SCTimer/PWM clock.
     * (2) The SCTimer/PWM clock frequency does not exceed 100 MHz.
     * Note: The SCTimer/PWM clock is the bus/system clock for CKMODE 0-2 or asynchronous input
     * clock for CKMODE3.
     * Another condition can be clear as 0: (for CKMODE2 only)
     * (1) The corresponding input is synchronous to the designated CKMODE2 input clock.
     * (2) The CKMODE2 input clock frequency is less than one-third the frequency of the bus/system clock.
     * Default value set as 0U, input0~input3 are set as bypasses. */
    config->inputsync = 0xFU;
}

/*!
 * brief Configures the PWM signal parameters.
 *
 * Call this function to configure the PWM signal period, mode, duty cycle, and edge. This
 * function will create 2 events; one of the events will trigger on match with the pulse value
 * and the other will trigger when the counter matches the PWM period. The PWM period event is
 * also used as a limit event to reset the counter or change direction. Both events are enabled
 * for the same state. The state number can be retrieved by calling the function
 * SCTIMER_GetCurrentStateNumber().
 * The counter is set to operate as one 32-bit counter (unify bit is set to 1).
 * The counter operates in bi-directional mode when generating a center-aligned PWM.
 *
 * note When setting PWM output from multiple output pins, they all should use the same PWM mode
 * i.e all PWM's should be either edge-aligned or center-aligned.
 * When using this API, the PWM signal frequency of all the initialized channels must be the same.
 * Otherwise all the initialized channels' PWM signal frequency is equal to the last call to the
 * API's pwmFreq_Hz.
 *
 * param base        SCTimer peripheral base address
 * param pwmParams   PWM parameters to configure the output
 * param mode        PWM operation mode, options available in enumeration ::sctimer_pwm_mode_t
 * param pwmFreq_Hz  PWM signal frequency in Hz
 * param srcClock_Hz SCTimer counter clock in Hz
 * param event       Pointer to a variable where the PWM period event number is stored
 *
 * return kStatus_Success on success
 *         kStatus_Fail If we have hit the limit in terms of number of events created or if
 *                      an incorrect PWM dutycylce is passed in.
 */
status_t SCTIMER_SetupPwm(SCT_Type *base,
                          const sctimer_pwm_signal_param_t *pwmParams,
                          sctimer_pwm_mode_t mode,
                          uint32_t pwmFreq_Hz,
                          uint32_t srcClock_Hz,
                          uint32_t *event)
{
    status_t status = kStatus_Fail;
    status_t status2;
    uint32_t period, pulsePeriod = 0;
    uint32_t sctClock    = srcClock_Hz / (((base->CTRL & SCT_CTRL_PRE_L_MASK) >> SCT_CTRL_PRE_L_SHIFT) + 1U);
    uint32_t periodEvent = 0, pulseEvent = 0;
    uint32_t reg;
    /* Ensure the parameters are valid */
    if (NULL == pwmParams || 0U == srcClock_Hz || 0U == pwmFreq_Hz ||
        (uint32_t)pwmParams->output >= (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS ||
        1U != ((base->CONFIG & SCT_CONFIG_UNIFY_MASK) >> SCT_CONFIG_UNIFY_SHIFT))
    {
        return kStatus_InvalidArgument;
    }

    /* If we do not have enough events available (this function will create two events),
     * the function will return fail.
     */
    if (s_currentEvent > (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS - 2U)
    {
        return kStatus_OutOfRange;
    }

    /* Use bi-directional mode for center-aligned PWM */
    if (mode == kSCTIMER_CenterAlignedPwm)
    {
        base->CTRL |= SCT_CTRL_BIDIR_L_MASK;
    }

    /* Calculate PWM period match value */
    if (mode == kSCTIMER_EdgeAlignedPwm)
    {
        assert(sctClock >= pwmFreq_Hz);
        period = (sctClock / pwmFreq_Hz) - 1U;
    }
    else
    {
        period = sctClock / (pwmFreq_Hz * 2U);
    }

    /* For 100% dutycyle, make pulse period greater than period so the event will never occur */
    if (pwmParams->dutyCyclePercent >= 100U)
    {
        assert(period <= (0xFFFFFFFFU - 2U));
        pulsePeriod = period + 2U;
    }
    else
    {
        pulsePeriod = (uint32_t)((((uint64_t)period * pwmParams->dutyCyclePercent) / 100U) & 0xFFFFFFFFU);
    }

    /* Schedule an event when we reach the PWM period */
    status =
        SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, period, 0, kSCTIMER_Counter_U, &periodEvent);

    /* Schedule an event when we reach the pulse width */
    status2 = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, pulsePeriod, 0, kSCTIMER_Counter_U,
                                                &pulseEvent);

    if ((kStatus_Success == status) && (kStatus_Success == status2))
    {
        /* Reset the counter when we reach the PWM period */
        SCTIMER_SetupCounterLimitAction(base, kSCTIMER_Counter_U, periodEvent);

        /* Return the period event to the user */
        *event = periodEvent;

        /* For high-true level */
        if ((uint32_t)pwmParams->level == (uint32_t)kSCTIMER_HighTrue)
        {
            if (mode == kSCTIMER_EdgeAlignedPwm)
            {
                /* Set the initial output level to low which is the inactive state */
                base->OUTPUT &= ~(1UL << (uint32_t)pwmParams->output);
                /* Set the output when we reach the PWM period */
                SCTIMER_SetupOutputSetAction(base, (uint32_t)pwmParams->output, periodEvent);
                /* Clear the output when we reach the PWM pulse value */
                SCTIMER_SetupOutputClearAction(base, (uint32_t)pwmParams->output, pulseEvent);
            }
            else
            {
                /* Set the initial output level to high which is the active state */
                base->OUTPUT |= (1UL << (uint32_t)pwmParams->output);
                /* Clear the output when we reach the PWM pulse event */
                SCTIMER_SetupOutputClearAction(base, (uint32_t)pwmParams->output, pulseEvent);
                /* Reverse output when down counting */
                reg = base->OUTPUTDIRCTRL;
                reg &= ~((uint32_t)SCT_OUTPUTDIRCTRL_SETCLR0_MASK << (2U * (uint32_t)pwmParams->output));
                reg |= (1UL << (2U * (uint32_t)pwmParams->output));
                base->OUTPUTDIRCTRL = reg;
            }
        }
        /* For low-true level */
        else
        {
            if (mode == kSCTIMER_EdgeAlignedPwm)
            {
                /* Set the initial output level to high which is the inactive state */
                base->OUTPUT |= (1UL << (uint32_t)pwmParams->output);
                /* Clear the output when we reach the PWM period */
                SCTIMER_SetupOutputClearAction(base, (uint32_t)pwmParams->output, periodEvent);
                /* Set the output when we reach the PWM pulse value */
                SCTIMER_SetupOutputSetAction(base, (uint32_t)pwmParams->output, pulseEvent);
            }
            else
            {
                /* Set the initial output level to low which is the active state */
                base->OUTPUT &= ~(1UL << (uint32_t)pwmParams->output);
                /* Set the output when we reach the PWM pulse event */
                SCTIMER_SetupOutputSetAction(base, (uint32_t)pwmParams->output, pulseEvent);
                /* Reverse output when down counting */
                reg = base->OUTPUTDIRCTRL;
                reg &= ~((uint32_t)SCT_OUTPUTDIRCTRL_SETCLR0_MASK << (2U * (uint32_t)pwmParams->output));
                reg |= (1UL << (2U * (uint32_t)pwmParams->output));
                base->OUTPUTDIRCTRL = reg;
            }
        }
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Updates the duty cycle of an active PWM signal.
 *
 * Before calling  this function, the counter is set to operate as one 32-bit counter (unify bit is set to 1).
 *
 * param base              SCTimer peripheral base address
 * param output            The output to configure
 * param dutyCyclePercent  New PWM pulse width; the value should be between 0 to 100
 * param event             Event number associated with this PWM signal. This was returned to the user by the
 *                          function SCTIMER_SetupPwm().
 */
void SCTIMER_UpdatePwmDutycycle(SCT_Type *base, sctimer_out_t output, uint8_t dutyCyclePercent, uint32_t event)

{
    assert(dutyCyclePercent <= 100U);
    assert((uint32_t)output < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS);
    assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));

    uint32_t periodMatchReg, pulseMatchReg;
    uint32_t pulsePeriod = 0, period;
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS - 1U);
    bool isHighTrue      = (0U != (base->OUT[output].CLR & (1UL << (event + 1U))));

    /* Retrieve the match register number for the PWM period */
    periodMatchReg = base->EV[event].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;

    /* Retrieve the match register number for the PWM pulse period */
    pulseMatchReg = base->EV[event + 1U].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;

    assert((periodMatchReg < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE) &&
        (pulseMatchReg < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE));

    period = base->MATCH[periodMatchReg];

    /* Stop the counter before updating match register */
    SCTIMER_StopTimer(base, (uint32_t)kSCTIMER_Counter_U);

    /* For 100% dutycyle, make pulse period greater than period so the event will never occur */
    if (dutyCyclePercent >= 100U)
    {
        assert(period <= 0xFFFFFFFFU - 2U);
        pulsePeriod = period + 2U;

        /* Set the initial output level base on output mode */
        if (isHighTrue)
        {
            base->OUTPUT |= (1UL << (uint32_t)output);
        }
        else
        {
            base->OUTPUT &= ~(1UL << (uint32_t)output);
        }
    }
    else
    {
        pulsePeriod = (uint32_t)((((uint64_t)period * dutyCyclePercent) / 100U) & 0xFFFFFFFFU);
    }

    /* Update dutycycle */
    base->MATCH[pulseMatchReg]    = pulsePeriod;
    base->MATCHREL[pulseMatchReg] = pulsePeriod;

    /* Restart the counter */
    SCTIMER_StartTimer(base, (uint32_t)kSCTIMER_Counter_U);
}

/*!
 * brief Reverse one output's set/clear actions while the counter is counting down.
 *
 * Used by the center-aligned PWM paths so that a match drives opposite output transitions on the up-count
 * and down-count, producing a single centered pulse.
 */
static void SCTIMER_ReverseOutputOnDownCount(SCT_Type *base, uint32_t output)
{
    assert(output < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS);

    uint32_t reg = base->OUTPUTDIRCTRL;
    reg &= ~((uint32_t)SCT_OUTPUTDIRCTRL_SETCLR0_MASK << (2U * output));
    reg |= (1UL << (2U * output));
    base->OUTPUTDIRCTRL = reg;
}

/*!
 * brief Apply the output set/clear/direction actions for one PWM channel.
 *
 * Shared by SCTIMER_SetupSharedPeriodPwm() for each channel; mirrors the per-channel output handling of
 * SCTIMER_SetupPwm(). The period event drives the edge-aligned period-boundary action; the pulse event
 * drives the duty action.
 */
static void SCTIMER_ConfigurePwmChannelOutput(SCT_Type *base,
                                               const sctimer_pwm_signal_param_t *param,
                                               sctimer_pwm_mode_t mode,
                                               uint32_t periodEvent,
                                               uint32_t pulseEvent)
{
    uint32_t output = (uint32_t)param->output;

    if ((uint32_t)param->level == (uint32_t)kSCTIMER_HighTrue)
    {
        if (mode == kSCTIMER_EdgeAlignedPwm)
        {
            /* Inactive (low) at start; set at period boundary, clear at pulse. */
            base->OUTPUT &= ~(1UL << output);
            SCTIMER_SetupOutputSetAction(base, output, periodEvent);
            SCTIMER_SetupOutputClearAction(base, output, pulseEvent);
        }
        else
        {
            /* Active (high) at start; clear at pulse, reverse on down-count. */
            base->OUTPUT |= (1UL << output);
            SCTIMER_SetupOutputClearAction(base, output, pulseEvent);
            SCTIMER_ReverseOutputOnDownCount(base, output);
        }
    }
    else
    {
        if (mode == kSCTIMER_EdgeAlignedPwm)
        {
            /* Inactive (high) at start; clear at period boundary, set at pulse. */
            base->OUTPUT |= (1UL << output);
            SCTIMER_SetupOutputClearAction(base, output, periodEvent);
            SCTIMER_SetupOutputSetAction(base, output, pulseEvent);
        }
        else
        {
            base->OUTPUT &= ~(1UL << output);
            SCTIMER_SetupOutputSetAction(base, output, pulseEvent);
            SCTIMER_ReverseOutputOnDownCount(base, output);
        }
    }
}

/*!
 * brief Find an existing unified-counter period/limit event that a same-frequency channel can share.
 *
 * Scans the unified-counter limit mask (LIMIT[LIMMSK_L]) for the lowest-numbered limit event (the only
 * limits created by SCTIMER_SetupSharedPeriodPwm() / SCTIMER_SetupComplementaryPwm() / SCTIMER_SetupPwm()).
 *
 * @return kStatus_Success with *found = true and *periodEvent set when a reusable event exists (same
 *         period MATCH value and same alignment); kStatus_Success with *found = false when none exists
 *         (the caller should create one); kStatus_InvalidArgument when one exists but with a different
 *         period or alignment (a unified counter has a single limit, so the two cannot coexist).
 *
 * Note: a second independent limit event at the same period value is not harmless — multiple limit events
 * perturb the counter turn-around (observed as asymmetric edge timing near the counter peak), so callers
 * reuse the one shared event instead of adding their own.
 */
static status_t SCTIMER_FindSharedPeriodEvent(SCT_Type *base, uint32_t period, bool requestCenter,
                                              uint32_t *periodEvent, bool *found)
{
    uint32_t limitMask = base->LIMIT & SCT_LIMIT_LIMMSK_L_MASK;

    *found = false;
    if (0U != limitMask)
    {
        uint32_t ev = 0U;
        uint32_t matchReg;
        bool existingCenter;

        while ((0U == (limitMask & 0x1U)) && (ev < ((uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS - 1U)))
        {
            limitMask >>= 1U;
            ev++;
        }
        matchReg       = base->EV[ev].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;
        existingCenter = (0U != (base->CTRL & SCT_CTRL_BIDIR_L_MASK));

        if ((base->MATCH[matchReg] == period) && (existingCenter == requestCenter))
        {
            *periodEvent = ev;
            *found       = true;
            return kStatus_Success;
        }
        /* A unified counter has a single limit; a different period/alignment cannot share it. */
        return kStatus_InvalidArgument;
    }

    return kStatus_Success;
}

/*!
 * brief Configures one PWM channel that shares an auto-detected period event across calls.
 *
 * Unlike SCTIMER_SetupPwm() (which spends two events per channel and recreates a period event each
 * call), this function configures a single channel and reuses **one** shared period/limit event for all
 * same-frequency channels. On each call it inspects the unified-counter limit mask
 * (LIMIT[LIMMSK_L]) for an existing period/limit event:
 *  - none present  -> it creates the shared period/limit event (1 period + 1 pulse event), or
 *  - one present whose period (its MATCH value) and alignment (CTRL[BIDIR_L] set <=> center-aligned)
 *    match the requested pwmFreq_Hz/mode -> it reuses that event and only creates this channel's pulse
 *    event (1 pulse event), or
 *  - one present whose period or alignment differs -> it returns kStatus_InvalidArgument without
 *    creating or modifying anything (two periods cannot share one unified counter).
 *
 * So K same-frequency channels built by K calls consume K + 1 events / K + 1 match registers instead of
 * 2 * K. A period/limit event left by a prior SCTIMER_SetupPwm() at the same period/alignment is also
 * reusable. The counter must already be configured as one unified 32-bit counter (CONFIG[UNIFY] = 1).
 *
 * note Period detection assumes the shared PWM period/limit is the lowest-numbered unified-counter
 * limit event (the only limit events created by this function and SCTIMER_SetupPwm()). If the application
 * created other unified-counter limit events before calling this function, detection may match the wrong
 * event; in that case create the PWM channels before any unrelated limit events.
 *
 * note Each call configures exactly one channel and is atomic for that channel only (on failure it
 * creates nothing). Building a multi-channel group is a sequence of independent calls; this API does NOT
 * roll the whole group back if a later call fails.
 *
 * note The channel is enabled in the current state only. In a multi-state design the caller must
 * re-enable the returned periodEvent and each channel's pulseEvent in every state that should run the
 * group (via SCTIMER_ScheduleEvent()). Because the period event is shared, failing to re-schedule it in a
 * state disrupts ALL channels in that state, not just one.
 *
 * param base         SCTimer peripheral base address
 * param pwmParam     Pointer to this channel's PWM parameters (output, level, duty)
 * param mode         PWM operation mode (all sharing channels must use the same mode), see ::sctimer_pwm_mode_t
 * param pwmFreq_Hz   Common PWM signal frequency in Hz (all sharing channels must use the same frequency)
 * param srcClock_Hz  SCTimer counter clock in Hz
 * param periodEvent  Pointer to a variable where the shared period event number (new or reused) is stored
 * param pulseEvent   Pointer to a variable where this channel's pulse event number is stored
 *
 * return kStatus_Success on success
 *         kStatus_InvalidArgument if arguments are invalid, the counter is not in unified mode, or an
 *                                 existing shared period event has a different frequency/alignment
 *         kStatus_OutOfRange if the event or match-register budget would be exceeded
 */
status_t SCTIMER_SetupSharedPeriodPwm(SCT_Type *base,
                                      const sctimer_pwm_signal_param_t *pwmParam,
                                      sctimer_pwm_mode_t mode,
                                      uint32_t pwmFreq_Hz,
                                      uint32_t srcClock_Hz,
                                      uint32_t *periodEvent,
                                      uint32_t *pulseEvent)
{
    status_t status;
    uint32_t period, pulsePeriod;
    uint32_t sctClock = srcClock_Hz / (((base->CTRL & SCT_CTRL_PRE_L_MASK) >> SCT_CTRL_PRE_L_SHIFT) + 1U);
    uint32_t periodEv = 0U, pulseEv = 0U;
    bool reusePeriod = false;
    bool requestCenter;

    /* Validate arguments; the counter must operate as one unified 32-bit counter. */
    if ((NULL == pwmParam) || (NULL == periodEvent) || (NULL == pulseEvent) || (0U == srcClock_Hz) ||
        (0U == pwmFreq_Hz) || ((uint32_t)pwmParam->output >= (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS) ||
        (pwmParam->dutyCyclePercent > 100U) ||
        (1U != ((base->CONFIG & SCT_CONFIG_UNIFY_MASK) >> SCT_CONFIG_UNIFY_SHIFT)))
    {
        return kStatus_InvalidArgument;
    }

    requestCenter = (mode == kSCTIMER_CenterAlignedPwm);

    /* Compute the requested period as a pure calculation (no register mutation yet). */
    if (requestCenter)
    {
        period = sctClock / (pwmFreq_Hz * 2U);
    }
    else
    {
        if (sctClock <= pwmFreq_Hz)
        {
            return kStatus_InvalidArgument;
        }
        period = (sctClock / pwmFreq_Hz) - 1U;
    }

    /* Reject a frequency too high for the clock to represent (period would be 0). */
    if (0U == period)
    {
        return kStatus_InvalidArgument;
    }

    /* Reuse an existing same-frequency period/limit event across calls, or create a new one below. */
    status = SCTIMER_FindSharedPeriodEvent(base, period, requestCenter, &periodEv, &reusePeriod);
    if (kStatus_Success != status)
    {
        return status;
    }

    /* Pre-flight the budget so a failure leaves no half-configured channel: a new shared period costs
     * 2 slots (period + pulse); reusing an existing period costs only the 1 pulse slot. */
    {
        uint32_t needed = reusePeriod ? 1U : 2U;
        if ((((uint64_t)s_currentEvent + needed) > (uint64_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS) ||
            (((uint64_t)s_currentMatch + needed) > (uint64_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE))
        {
            return kStatus_OutOfRange;
        }
    }

    if (!reusePeriod)
    {
        /* Center-aligned PWM uses bi-directional mode; set it only on the new-period path. */
        if (requestCenter)
        {
            base->CTRL |= SCT_CTRL_BIDIR_L_MASK;
        }

        /* Create the shared period/limit event for this counter. */
        status =
            SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, period, 0U, kSCTIMER_Counter_U, &periodEv);
        if (kStatus_Success != status)
        {
            return status;
        }
        SCTIMER_SetupCounterLimitAction(base, kSCTIMER_Counter_U, periodEv);
    }
    *periodEvent = periodEv;

    /* Create this channel's pulse (duty) event. */
    if (pwmParam->dutyCyclePercent >= 100U)
    {
        assert(period <= (0xFFFFFFFFU - 2U));
        /* Make the pulse match unreachable so the duty event never fires (100%). */
        pulsePeriod = period + 2U;
    }
    else
    {
        pulsePeriod = (uint32_t)((((uint64_t)period * pwmParam->dutyCyclePercent) / 100U) & 0xFFFFFFFFU);
    }

    status = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, pulsePeriod, 0U, kSCTIMER_Counter_U,
                                            &pulseEv);
    if (kStatus_Success != status)
    {
        return status; /* should not happen: pre-flight reserved the budget */
    }
    *pulseEvent = pulseEv;

    SCTIMER_ConfigurePwmChannelOutput(base, pwmParam, mode, periodEv, pulseEv);

    return kStatus_Success;
}

/*!
 * brief Updates the duty cycle of a PWM signal using explicit period and pulse events.
 *
 * Unlike SCTIMER_UpdatePwmDutycycle(), this function does not assume the pulse event is periodEvent + 1,
 * so it works for channels created by SCTIMER_SetupSharedPeriodPwm() where the pulse events are not
 * adjacent to the shared period event. The counter must be in unified 32-bit mode.
 *
 * param base              SCTimer peripheral base address
 * param output            The output to configure
 * param dutyCyclePercent  New PWM pulse width; the value should be between 0 and 100
 * param periodEvent       The shared period event (as returned by SCTIMER_SetupSharedPeriodPwm())
 * param pulseEvent        The channel's pulse event (as returned by SCTIMER_SetupSharedPeriodPwm())
 * param updateMode        When the new duty cycle takes effect, see ::sctimer_pwm_update_mode_t
 */
void SCTIMER_UpdatePwmDutycycleByEvent(SCT_Type *base,
                                       sctimer_out_t output,
                                       uint8_t dutyCyclePercent,
                                       uint32_t periodEvent,
                                       uint32_t pulseEvent,
                                       sctimer_pwm_update_mode_t updateMode)
{
    assert(dutyCyclePercent <= 100U);
    assert((uint32_t)output < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS);
    assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
    assert(periodEvent < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);
    assert(pulseEvent < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);

    uint32_t periodMatchReg, pulseMatchReg;
    uint32_t pulsePeriod, period;
    /* High-true channels clear the output on the pulse event (see SCTIMER_ConfigurePwmChannelOutput). */
    bool isHighTrue = (0U != (base->OUT[output].CLR & (1UL << pulseEvent)));

    periodMatchReg = base->EV[periodEvent].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;
    pulseMatchReg  = base->EV[pulseEvent].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;
    assert((periodMatchReg < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE) &&
           (pulseMatchReg < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE));

    period = base->MATCH[periodMatchReg];

    if (dutyCyclePercent >= 100U)
    {
        assert(period <= (0xFFFFFFFFU - 2U));
        pulsePeriod = period + 2U;
    }
    else
    {
        pulsePeriod = (uint32_t)((((uint64_t)period * dutyCyclePercent) / 100U) & 0xFFFFFFFFU);
    }

    if (updateMode == kSCTIMER_UpdateImmediately)
    {
        /* Writing the active MATCH register requires the counter halted. */
        SCTIMER_StopTimer(base, (uint32_t)kSCTIMER_Counter_U);

        if (dutyCyclePercent >= 100U)
        {
            /* Drive the output to its active level for a constant 100% signal. */
            if (isHighTrue)
            {
                base->OUTPUT |= (1UL << (uint32_t)output);
            }
            else
            {
                base->OUTPUT &= ~(1UL << (uint32_t)output);
            }
        }

        base->MATCH[pulseMatchReg]    = pulsePeriod;
        base->MATCHREL[pulseMatchReg] = pulsePeriod;

        SCTIMER_StartTimer(base, (uint32_t)kSCTIMER_Counter_U);
    }
    else
    {
        /* Glitchless: write only the reload register; the new duty loads at the next counter cycle. */
        base->MATCHREL[pulseMatchReg] = pulsePeriod;
    }
}

/*!
 * brief Configures a complementary PWM output pair with programmable dead time.
 *
 * Builds a high-side/low-side complementary pair on the unified 32-bit counter from one duty value plus a
 * dead time expressed in SCT counter clock ticks. Dead time is inserted by delaying each output's turn-on
 * by deadTimeTicks while keeping turn-off immediate, which guarantees a non-overlap (dead-time) gap at
 * both switching edges so the two outputs are never simultaneously active (no shoot-through).
 *
 * The shared period event also limits (resets) the counter. The returned handle is used to update the
 * pair's duty cycle later with SCTIMER_UpdateComplementaryPwmDutycycle().
 *
 * note Dead time is inserted by delaying the relevant turn-on edge - the high side in edge-aligned mode,
 * the low side in center-aligned mode - so that output's active width shrinks by deadTimeTicks (the usual
 * cost of dead time).
 *
 * note For a switching duty the valid range is 0 < duty < 100 (needs deadTimeTicks < duty and
 * duty + deadTimeTicks < period); deadTimeTicks = 0 is allowed (strict complementary). 0 % and 100 % are
 * accepted as constant complementary levels (high-side fully off / fully on): the pair is driven to static
 * opposite levels with no switching and no dead-time window. A both-off fault state is not expressible as a
 * duty - use a separate output force/disable path for that.
 *
 * note Call this function once per complementary pair. To drive several pairs on the same SCTimer (for
 * example the three half-bridges of a 3-phase inverter), call it once for each pair — but all pairs MUST
 * use the same pwmFreq_Hz and the same mode, because they share one unified counter (a single count
 * direction and period). Mixing frequencies or alignments across pairs creates conflicting limit events
 * on the counter and produces an incorrect waveform.
 *
 * param base             SCTimer peripheral base address
 * param outHigh          High-side output pin
 * param outLow           Low-side output pin (complement of outHigh)
 * param dutyCyclePercent High-side duty cycle, value should be between 0 and 100
 * param deadTimeTicks    Dead time in SCT counter clock ticks, inserted at both edges; 0 = no dead time
 *                         (strict complementary)
 * param mode             PWM operation mode, see ::sctimer_pwm_mode_t
 * param pwmFreq_Hz       PWM signal frequency in Hz
 * param srcClock_Hz      SCTimer counter clock in Hz
 * param handle           Pointer to a handle that receives the pair's event numbers and parameters
 *
 * return kStatus_Success on success
 *         kStatus_InvalidArgument if arguments are invalid, the counter is not unified, or the dead time
 *                                 does not fit the requested duty/period without causing overlap
 *         kStatus_OutOfRange if the event or match-register budget would be exceeded
 */
status_t SCTIMER_SetupComplementaryPwm(SCT_Type *base,
                                       sctimer_out_t outHigh,
                                       sctimer_out_t outLow,
                                       uint8_t dutyCyclePercent,
                                       uint32_t deadTimeTicks,
                                       sctimer_pwm_mode_t mode,
                                       uint32_t pwmFreq_Hz,
                                       uint32_t srcClock_Hz,
                                       sctimer_complementary_pwm_handle_t *handle)
{
    status_t status;
    uint32_t sctClock = srcClock_Hz / (((base->CTRL & SCT_CTRL_PRE_L_MASK) >> SCT_CTRL_PRE_L_SHIFT) + 1U);
    uint32_t period, duty;
    uint32_t evPeriod = 0U, evHighRise = 0U, evHighFall = 0U, evLowRise = 0U;
    bool requestCenter = (mode == kSCTIMER_CenterAlignedPwm);
    bool reusePeriod   = false;
    /* 0% / 100% are constant complementary levels, not a switching duty. */
    bool constLevel    = ((0U == dutyCyclePercent) || (100U == dutyCyclePercent));

    if ((NULL == handle) || (0U == srcClock_Hz) || (0U == pwmFreq_Hz) || (dutyCyclePercent > 100U) ||
        ((uint32_t)outHigh >= (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS) ||
        ((uint32_t)outLow >= (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS) ||
        (1U != ((base->CONFIG & SCT_CONFIG_UNIFY_MASK) >> SCT_CONFIG_UNIFY_SHIFT)))
    {
        return kStatus_InvalidArgument;
    }

    /* Compute the period match as a pure calculation; do not mutate any register until all checks pass. */
    if (requestCenter)
    {
        period = sctClock / (pwmFreq_Hz * 2U);
    }
    else
    {
        if (sctClock <= pwmFreq_Hz) 
        { 
            return kStatus_InvalidArgument; 
        }
        period = (sctClock / pwmFreq_Hz) - 1U;
    }

    duty = (uint32_t)((((uint64_t)period * dutyCyclePercent) / 100U) & 0xFFFFFFFFU);

    if (deadTimeTicks > (UINT32_MAX - duty))
    {
        return kStatus_InvalidArgument;
    }
    uint32_t lowRiseMatch = duty + deadTimeTicks;

    /* Guard the dead-time window so the two outputs cannot overlap (REQ-005 shoot-through protection).
     * Only a real switching duty must satisfy it; 0%/100% are constant levels with no switching edge. */
    if ((0U == period) || (!constLevel && ((deadTimeTicks >= duty) || (lowRiseMatch >= period))))
    {
        return kStatus_InvalidArgument;
    }

    /* Reuse the shared period/limit event when one already exists at the same frequency/alignment (e.g. a
     * 3-phase inverter calls this once per pair). A second independent limit event on the unified counter
     * perturbs the turn-around (asymmetric dead time near the counter peak), so sharing the one period
     * event is required for correctness, not merely an optimization. */
    status = SCTIMER_FindSharedPeriodEvent(base, period, requestCenter, &evPeriod, &reusePeriod);
    if (kStatus_Success != status)
    {
        return status;
    }

    /* Center needs one event per output; edge needs high rise/fall + low rise. A new shared period adds
     * one more event/match; reusing an existing one adds none. */
    {
        uint32_t needed = requestCenter ? 2U : 3U;
        needed += reusePeriod ? 0U : 1U;

        if ((((uint64_t)s_currentEvent + needed) > (uint64_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS) ||
            (((uint64_t)s_currentMatch + needed) > (uint64_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE))
        {
            return kStatus_OutOfRange;
        }
    }

    if (!reusePeriod)
    {
        /* Center-aligned PWM counts up/down (bi-directional); set BIDIR only when creating the period. */
        if (requestCenter)
        {
            base->CTRL |= SCT_CTRL_BIDIR_L_MASK;
        }

        /* Shared period/limit event: flips the count direction (center) or clears the counter (edge). */
        status =
            SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, period, 0U, kSCTIMER_Counter_U, &evPeriod);
        if (kStatus_Success != status)
        {
            return status;
        }
        SCTIMER_SetupCounterLimitAction(base, kSCTIMER_Counter_U, evPeriod);
    }

    if (requestCenter)
    {
        /* Center-aligned: one match per output plus counting-direction reversal makes a single
         * trough-centered pulse on each output. The high side is active while COUNT < duty; the low-side
         * output is active while COUNT > duty + deadTimeTicks. Because each match is crossed once per
         * count direction, a deadTimeTicks gap appears at both switching edges (symmetric dead time, no
         * overlap), and each output produces exactly one pulse per PWM period. */
        status = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, duty, 0U, kSCTIMER_Counter_U,
                                                &evHighFall);
        if (kStatus_Success != status)
        {
            return status;
        }
        status = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, lowRiseMatch, 0U,
                                                kSCTIMER_Counter_U, &evLowRise);
        if (kStatus_Success != status)
        {
            return status;
        }

        /* High side starts active (high), low side starts inactive (low). Single write so the two legs
         * settle together, with no both-on/both-off transient. */
        {
            uint32_t out = base->OUTPUT;
            out |= (1UL << (uint32_t)outHigh);
            out &= ~(1UL << (uint32_t)outLow);
            base->OUTPUT = out;
        }
        SCTIMER_SetupOutputClearAction(base, (uint32_t)outHigh, evHighFall); /* high off above duty        */
        SCTIMER_SetupOutputSetAction(base, (uint32_t)outLow, evLowRise);     /* low-side on above duty + td */

        /* Reverse the set/clear actions on the down-count so each output produces one centered pulse. */
        SCTIMER_ReverseOutputOnDownCount(base, (uint32_t)outHigh);
        SCTIMER_ReverseOutputOnDownCount(base, (uint32_t)outLow);

        evHighRise = evPeriod; /* not used to drive an output in center mode */
    }
    else
    {
        /* Edge-aligned: dead time by delaying each turn-on. High side ON [td, duty]; low side ON
         * [duty + td, period] — a deadTimeTicks gap at both switching edges. */
        status = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, deadTimeTicks, 0U,
                                                kSCTIMER_Counter_U, &evHighRise);
        if (kStatus_Success != status)
        {
            return status;
        }
        status =
            SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, duty, 0U, kSCTIMER_Counter_U, &evHighFall);
        if (kStatus_Success != status)
        {
            return status;
        }
        status = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, lowRiseMatch, 0U,
                                                kSCTIMER_Counter_U, &evLowRise);
        if (kStatus_Success != status)
        {
            return status;
        }

        /* Both outputs inactive (low) at start. */
        base->OUTPUT &= ~((1UL << (uint32_t)outHigh) | (1UL << (uint32_t)outLow));
        SCTIMER_SetupOutputSetAction(base, (uint32_t)outHigh, evHighRise);
        SCTIMER_SetupOutputClearAction(base, (uint32_t)outHigh, evHighFall);
        SCTIMER_SetupOutputSetAction(base, (uint32_t)outLow, evLowRise);
        SCTIMER_SetupOutputClearAction(base, (uint32_t)outLow, evPeriod);
    }

    handle->periodEvent   = evPeriod;
    handle->highRiseEvent = evHighRise;
    handle->highFallEvent = evHighFall;
    handle->lowRiseEvent  = evLowRise;
    handle->deadTimeTicks = deadTimeTicks;
    handle->outHigh       = outHigh;
    handle->outLow        = outLow;

    if (constLevel)
    {
        /* The events above keep the handle valid for a later switching-duty update, but at 0%/100% the
         * pair must sit at constant opposite levels. Detach both pins from every event so nothing toggles
         * them, then force the levels: 100% => high active / low inactive, 0% => high inactive / low active. */
        base->OUT[(uint32_t)outHigh].SET = 0U;
        base->OUT[(uint32_t)outHigh].CLR = 0U;
        base->OUT[(uint32_t)outLow].SET  = 0U;
        base->OUT[(uint32_t)outLow].CLR  = 0U;

        {
            uint32_t out = base->OUTPUT;
            if (100U == dutyCyclePercent)
            {
                out |= (1UL << (uint32_t)outHigh);
                out &= ~(1UL << (uint32_t)outLow);
            }
            else
            {
                out &= ~(1UL << (uint32_t)outHigh);
                out |= (1UL << (uint32_t)outLow);
            }
            /* Single write: both legs change together, with no both-on/both-off transient. */
            base->OUTPUT = out;
        }
    }

    return kStatus_Success;
}

/*!
 * brief Re-bind a complementary pair's output set/clear actions for normal (switching) operation.
 *
 * Used by SCTIMER_UpdateComplementaryPwmDutycycle() when a pair returns from a 0%/100% constant-level state,
 * where both outputs were detached from their events. The alignment is inferred from the handle:
 * highRiseEvent == periodEvent means center-aligned. The down-count direction control (OUTPUTDIRCTRL) set at
 * setup is left intact, so it does not need to be re-issued here.
 */
static void SCTIMER_RebindComplementaryOutputs(SCT_Type *base, const sctimer_complementary_pwm_handle_t *handle)
{
    uint32_t outHigh = (uint32_t)handle->outHigh;
    uint32_t outLow  = (uint32_t)handle->outLow;

    /* Resume both legs from the inactive (off) level; the match events re-establish the complementary
     * state on the next period. Starting both-off (rather than high-on for center) means the brief counter
     * run after the rebind restart can never leave a leg frozen on and overlap the other. */
    base->OUTPUT &= ~((1UL << outHigh) | (1UL << outLow));

    if (handle->highRiseEvent == handle->periodEvent)
    {
        /* Center-aligned: one moving edge per output. */
        SCTIMER_SetupOutputClearAction(base, outHigh, handle->highFallEvent);
        SCTIMER_SetupOutputSetAction(base, outLow, handle->lowRiseEvent);
    }
    else
    {
        /* Edge-aligned: delayed turn-on plus period-boundary turn-off. */
        SCTIMER_SetupOutputSetAction(base, outHigh, handle->highRiseEvent);
        SCTIMER_SetupOutputClearAction(base, outHigh, handle->highFallEvent);
        SCTIMER_SetupOutputSetAction(base, outLow, handle->lowRiseEvent);
        SCTIMER_SetupOutputClearAction(base, outLow, handle->periodEvent);
    }
}

/*!
 * brief Updates the duty cycle of a complementary PWM pair, preserving dead time.
 *
 * Recomputes both moving switching edges (high-side turn-off and low-side turn-on) from the new duty
 * cycle while keeping the dead-time offset, and writes them so the no-overlap guarantee holds across the
 * update. In kSCTIMER_UpdateOnNextPeriod mode both edges reload together at the next counter cycle, so
 * the dead-time relationship is updated atomically and glitchlessly.
 *
 * note A switching duty must keep the dead time inside the period (deadTimeTicks < duty and
 * duty + deadTimeTicks < period). 0 % and 100 % are accepted as constant complementary levels: the pair is
 * driven to static opposite levels (no switching, no dead time). Switching between a constant level and a
 * switching duty briefly halts the counter to re-bind the outputs. A both-off fault state is not a duty -
 * use a separate output force/disable path.
 *
 * note updateMode is honored only for a switching duty (0 < duty < 100). A 0 % or 100 % update is always
 * applied immediately (counter briefly halted), regardless of updateMode, because a constant level cannot
 * be loaded through the glitchless reload-register (MATCHREL) path: it requires detaching the events and
 * forcing the output levels, which needs a halt. kSCTIMER_UpdateOnNextPeriod therefore does not defer a
 * 0 %/100 % change to the next period boundary.
 *
 * param base             SCTimer peripheral base address
 * param handle           Handle returned by SCTIMER_SetupComplementaryPwm()
 * param dutyCyclePercent New high-side duty cycle, value should be between 0 and 100
 * param updateMode       When the new duty cycle takes effect, see ::sctimer_pwm_update_mode_t. Ignored for
 *                        a 0 %/100 % update, which is always immediate; see the note above.
 *
 * return kStatus_Success on success
 *         kStatus_InvalidArgument if the dead time does not fit the requested duty/period
 */
status_t SCTIMER_UpdateComplementaryPwmDutycycle(SCT_Type *base,
                                                 const sctimer_complementary_pwm_handle_t *handle,
                                                 uint8_t dutyCyclePercent,
                                                 sctimer_pwm_update_mode_t updateMode)
{
    assert(NULL != handle);
    assert(dutyCyclePercent <= 100U);

    uint32_t periodMatchReg, highFallMatchReg, lowRiseMatchReg;
    uint32_t period, duty, lowRise;

    periodMatchReg   = base->EV[handle->periodEvent].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;
    highFallMatchReg = base->EV[handle->highFallEvent].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;
    lowRiseMatchReg  = base->EV[handle->lowRiseEvent].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;

    period  = base->MATCH[periodMatchReg];
    duty    = (uint32_t)((((uint64_t)period * dutyCyclePercent) / 100U) & 0xFFFFFFFFU);

    if (handle->deadTimeTicks > (UINT32_MAX - duty))
    {
        return kStatus_InvalidArgument;
    }
    lowRise = duty + handle->deadTimeTicks;

    if ((0U == dutyCyclePercent) || (100U == dutyCyclePercent))
    {
        /* Constant complementary levels: detach both pins from their events and force the levels.
         * 100% => high active / low inactive, 0% => high inactive / low active. Applied immediately. */
        SCTIMER_StopTimer(base, (uint32_t)kSCTIMER_Counter_U);

        base->OUT[(uint32_t)handle->outHigh].SET = 0U;
        base->OUT[(uint32_t)handle->outHigh].CLR = 0U;
        base->OUT[(uint32_t)handle->outLow].SET  = 0U;
        base->OUT[(uint32_t)handle->outLow].CLR  = 0U;

        {
            uint32_t out = base->OUTPUT;
            if (100U == dutyCyclePercent)
            {
                out |= (1UL << (uint32_t)handle->outHigh);
                out &= ~(1UL << (uint32_t)handle->outLow);
            }
            else
            {
                out &= ~(1UL << (uint32_t)handle->outHigh);
                out |= (1UL << (uint32_t)handle->outLow);
            }
            /* Single write: both legs change together, with no both-on/both-off transient. */
            base->OUTPUT = out;
        }

        SCTIMER_StartTimer(base, (uint32_t)kSCTIMER_Counter_U);
        return kStatus_Success;
    }

    /* Returning from a 0%/100% constant state: the outputs were detached, so re-bind them before
     * recomputing the switching edges. A normal switching handle always has at least one action bit set. */
    if (0U == (base->OUT[(uint32_t)handle->outHigh].SET | base->OUT[(uint32_t)handle->outHigh].CLR |
               base->OUT[(uint32_t)handle->outLow].SET | base->OUT[(uint32_t)handle->outLow].CLR))
    {
        SCTIMER_StopTimer(base, (uint32_t)kSCTIMER_Counter_U);
        SCTIMER_RebindComplementaryOutputs(base, handle);
        SCTIMER_StartTimer(base, (uint32_t)kSCTIMER_Counter_U);
    }

    /* Re-apply the dead-time / shoot-through guard for the new duty (REQ-005). */
    if ((handle->deadTimeTicks >= duty) || (lowRise >= period))
    {
        return kStatus_InvalidArgument;
    }

    if (updateMode == kSCTIMER_UpdateImmediately)
    {
        SCTIMER_StopTimer(base, (uint32_t)kSCTIMER_Counter_U);
        /* Immediate mode halts the counter mid-period; on restart the frozen output levels can be wrong
         * for the resumed count and, in center-aligned mode, leave both legs high for up to half a period.
         * Drive both legs to the inactive level while halted so the restart can never show a both-high
         * overlap; the match events re-establish the correct complementary state. 
         */
        base->OUTPUT &= ~((1UL << (uint32_t)handle->outHigh) | (1UL << (uint32_t)handle->outLow));
        base->MATCH[highFallMatchReg]    = duty;
        base->MATCHREL[highFallMatchReg] = duty;
        base->MATCH[lowRiseMatchReg]     = lowRise;
        base->MATCHREL[lowRiseMatchReg]  = lowRise;
        SCTIMER_StartTimer(base, (uint32_t)kSCTIMER_Counter_U);
    }
    else
    {
        /* Both edges reload together at the next cycle boundary: dead time stays consistent. */
        base->MATCHREL[highFallMatchReg] = duty;
        base->MATCHREL[lowRiseMatchReg]  = lowRise;
    }

    return kStatus_Success;
}

/*!
 * brief Create an event that is triggered on a match or IO and schedule in current state.
 *
 * This function will configure an event using the options provided by the user. If the event type uses
 * the counter match, then the function will set the user provided match value into a match register
 * and put this match register number into the event control register.
 * The event is enabled for the current state and the event number is increased by one at the end.
 * The function returns the event number; this event number can be used to configure actions to be
 * done when this event is triggered.
 *
 * param base         SCTimer peripheral base address
 * param howToMonitor Event type; options are available in the enumeration ::sctimer_event_t
 * param matchValue   The match value that will be programmed to a match register
 * param whichIO      The input or output that will be involved in event triggering. This field
 *                     is ignored if the event type is "match only"
 * param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                     In 32-bit mode, we can select Counter_U.
 * param event        Pointer to a variable where the new event number is stored
 *
 * return kStatus_Success on success
 *         kStatus_Error if we have hit the limit in terms of number of events created or
                         if we have reached the limit in terms of number of match registers
 */
status_t SCTIMER_CreateAndScheduleEvent(SCT_Type *base,
                                        sctimer_event_t howToMonitor,
                                        uint32_t matchValue,
                                        uint32_t whichIO,
                                        sctimer_counter_t whichCounter,
                                        uint32_t *event)
{
    uint32_t combMode       = (((uint32_t)howToMonitor & SCT_EV_CTRL_COMBMODE_MASK) >> SCT_EV_CTRL_COMBMODE_SHIFT);
    uint32_t currentCtrlVal = (uint32_t)howToMonitor;
    status_t status         = kStatus_Success;
    uint32_t temp           = 0;

    if (((kSCTIMER_Counter_H == whichCounter) || (kSCTIMER_Counter_L == whichCounter)) && (matchValue > 0xFFFFU))
    {
        return kStatus_InvalidArgument;
    }

    if ((kSCTIMER_Counter_H == whichCounter) && (0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK)))
    {
        /* Use Counter_H bits if user wants to setup the High counter */
        currentCtrlVal |= SCT_EV_CTRL_HEVENT(1U);
    }

    if (s_currentEvent < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS)
    {
        if (2U == combMode)
        {
            base->EV[s_currentEvent].CTRL = currentCtrlVal | SCT_EV_CTRL_IOSEL(whichIO);
        }
        else
        {
            if ((0U == combMode) || (3U == combMode))
            {
                currentCtrlVal |= SCT_EV_CTRL_IOSEL(whichIO);
            }

            if ((kSCTIMER_Counter_L == whichCounter) && (0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK)))
            {
                if (s_currentMatch < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE)
                {
                    currentCtrlVal |= SCT_EV_CTRL_MATCHSEL(s_currentMatch);
                    /* Use Counter_L bits if user wants to setup the Low counter */
                    base->MATCH_ACCESS16BIT[s_currentMatch].MATCHL       = (uint16_t)matchValue;
                    base->MATCHREL_ACCESS16BIT[s_currentMatch].MATCHRELL = (uint16_t)matchValue;
                    base->EV[s_currentEvent].CTRL                        = currentCtrlVal;

                    /* Increment the match register number */
                    s_currentMatch++;
                }
                else
                {
                    /* An error would occur if we have hit the limit in terms of number of match registers */
                    status = kStatus_Fail;
                }
            }
            else if ((kSCTIMER_Counter_H == whichCounter) && (0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK)))
            {
                if (s_currentMatchhigh < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE)
                {
                    currentCtrlVal |= SCT_EV_CTRL_MATCHSEL(s_currentMatchhigh);
                    temp                               = base->MATCH_ACCESS16BIT[s_currentMatchhigh].MATCHL;
                    base->MATCH[s_currentMatchhigh]    = temp | (matchValue << 16U);
                    temp                               = base->MATCHREL_ACCESS16BIT[s_currentMatchhigh].MATCHRELL;
                    base->MATCHREL[s_currentMatchhigh] = temp | (matchValue << 16U);

                    base->EV[s_currentEvent].CTRL = currentCtrlVal;
                    /* Increment the match register number */
                    s_currentMatchhigh++;
                }
                else
                {
                    /* An error would occur if we have hit the limit in terms of number of match registers */
                    status = kStatus_Fail;
                }
            }
            else if ((kSCTIMER_Counter_U == whichCounter) && (0U != (base->CONFIG & SCT_CONFIG_UNIFY_MASK)))
            {
                if (s_currentMatch < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE)
                {
                    /* Use Counter_L bits if counter is operating in 32-bit mode */
                    currentCtrlVal |= SCT_EV_CTRL_MATCHSEL(s_currentMatch);

                    base->MATCH[s_currentMatch]    = matchValue;
                    base->MATCHREL[s_currentMatch] = matchValue;
                    base->EV[s_currentEvent].CTRL  = currentCtrlVal;

                    /* Increment the match register number */
                    s_currentMatch++;
                }
                else
                {
                    /* An error would occur if we have hit the limit in terms of number of match registers */
                    status = kStatus_Fail;
                }
            }
            else
            {
                /* The used counter must match the CONFIG[UNIFY] bit selection */
                status = kStatus_Fail;
            }
        }

        if (kStatus_Success == status)
        {
            /* Enable the event in the current state */
            base->EV[s_currentEvent].STATE = (1UL << s_currentState);

            /* Return the event number */
            *event = s_currentEvent;

            /* Increment the event number */
            s_currentEvent++;
        }
    }
    else
    {
        /* An error would occur if we have hit the limit in terms of number of events created */
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Enable an event in the current state.
 *
 * This function will allow the event passed in to trigger in the current state. The event must
 * be created earlier by either calling the function SCTIMER_SetupPwm() or function
 * SCTIMER_CreateAndScheduleEvent() .
 *
 * param base  SCTimer peripheral base address
 * param event Event number to enable in the current state
 *
 */
void SCTIMER_ScheduleEvent(SCT_Type *base, uint32_t event)
{
    /* Enable event in the current state */
    base->EV[event].STATE |= (1UL << s_currentState);
}

/*!
 * brief Increase the state by 1
 *
 * All future events created by calling the function SCTIMER_ScheduleEvent() will be enabled in this new
 * state.
 *
 * param base  SCTimer peripheral base address
 *
 * return kStatus_Success on success
 *         kStatus_Error if we have hit the limit in terms of states used

 */
status_t SCTIMER_IncreaseState(SCT_Type *base)
{
    status_t status = kStatus_Success;

    /* Return an error if we have hit the limit in terms of states used */
    if (s_currentState >= (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_STATES)
    {
        status = kStatus_Fail;
    }
    else
    {
        s_currentState++;
    }

    return status;
}

/*!
 * brief Provides the current state
 *
 * User can use this to set the next state by calling the function SCTIMER_SetupNextStateAction().
 *
 * param base SCTimer peripheral base address
 *
 * return The current state
 */
uint32_t SCTIMER_GetCurrentState(SCT_Type *base)
{
    return s_currentState;
}

/*!
 * brief Toggle the output level.
 *
 * This change in the output level is triggered by the event number that is passed in by the user.
 *
 * param base    SCTimer peripheral base address
 * param whichIO The output to toggle
 * param event   Event number that will trigger the output change
 */
void SCTIMER_SetupOutputToggleAction(SCT_Type *base, uint32_t whichIO, uint32_t event)
{
    assert(whichIO < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS);

    uint32_t reg;

    /* Set the same event to set and clear the output */
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);
    base->OUT[whichIO].CLR |= (1UL << event);
    base->OUT[whichIO].SET |= (1UL << event);

    /* Set the conflict resolution to toggle output */
    reg = base->RES;
    reg &= ~(((uint32_t)SCT_RES_O0RES_MASK) << (2U * whichIO));
    reg |= ((uint32_t)(kSCTIMER_ResolveToggle)) << (2U * whichIO);
    base->RES = reg;
}

/*!
 * brief Setup capture of the counter value on trigger of a selected event
 *
 * param base            SCTimer peripheral base address
 * param whichCounter    SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                        In 32-bit mode, we can select Counter_U.
 * param captureRegister Pointer to a variable where the capture register number will be returned. User
 *                        can read the captured value from this register when the specified event is triggered.
 * param event           Event number that will trigger the capture
 *
 * return kStatus_Success on success
 *         kStatus_Error if we have hit the limit in terms of number of match/capture registers available
 */
status_t SCTIMER_SetupCaptureAction(SCT_Type *base,
                                    sctimer_counter_t whichCounter,
                                    uint32_t *captureRegister,
                                    uint32_t event)
{
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);

    status_t status;
    uint32_t temp = 0;

    if ((kSCTIMER_Counter_L == whichCounter) || (kSCTIMER_Counter_U == whichCounter))
    {
        if (s_currentMatch < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE)
        {
            /* Set the bit to enable event */
            base->CAPCTRL_ACCESS16BIT[s_currentMatch].CAPCTRLL |= SCT_CAPCTRLL_CAPCTRLL((1UL << event) & 0xFFFFU);

            /* Set this resource to be a capture rather than match */
            base->REGMODE_ACCESS16BIT.REGMODEL |= SCT_REGMODEL_REGMODEL((1UL << s_currentMatch) & 0xFFFFU);

            /* Return the match register number */
            *captureRegister = s_currentMatch;

            /* Increase the match register number */
            s_currentMatch++;

            status = kStatus_Success;
        }
        else
        {
            /* Return an error if we have hit the limit in terms of number of capture/match registers used */
            status = kStatus_Fail;
        }
    }
    else
    {
        if (s_currentMatchhigh < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE)
        {
            /* Set bit to enable event */
            temp                              = base->CAPCTRL_ACCESS16BIT[s_currentMatchhigh].CAPCTRLL;
            base->CAPCTRL[s_currentMatchhigh] = temp | ((uint32_t)((uint32_t)(1UL << event) << 16U) & 0xFFFF0000U);
            /* Set this resource to be a capture rather than match */
            temp          = base->REGMODE_ACCESS16BIT.REGMODEL;
            base->REGMODE = temp | ((uint32_t)((uint32_t)(1UL << s_currentMatchhigh) << 16U) & 0xFFFF0000U);

            /* Return the match register number */
            *captureRegister = s_currentMatchhigh;

            /* Increase the match register number */
            s_currentMatchhigh++;

            status = kStatus_Success;
        }
        else
        {
            /* Return an error if we have hit the limit in terms of number of capture/match registers used */
            status = kStatus_Fail;
        }
    }

    return status;
}

/*!
 * brief Receive noticification when the event trigger an interrupt.
 *
 * If the interrupt for the event is enabled by the user, then a callback can be registered
 * which will be invoked when the event is triggered
 *
 * param base     SCTimer peripheral base address
 * param event    Event number that will trigger the interrupt
 * param callback Function to invoke when the event is triggered
 */

void SCTIMER_SetCallback(SCT_Type *base, sctimer_event_callback_t callback, uint32_t event)
{
    s_eventCallback[event] = callback;
}

/*!
 * brief SCTimer interrupt handler.
 *
 * param base SCTimer peripheral base address.
 */
void SCTIMER_EventHandleIRQ(SCT_Type *base)
{
    uint32_t eventFlag = base->EVFLAG;
    /* Only clear the flags whose interrupt field is enabled */
    uint32_t clearFlag = (eventFlag & base->EVEN);
    uint32_t mask      = eventFlag;
    uint32_t i;

    /* Invoke the callback for certain events */
    for (i = 0; i < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS; i++)
    {
        if ((mask & 0x1U) != 0U)
        {
            if (s_eventCallback[i] != NULL)
            {
                s_eventCallback[i]();
            }
        }
        mask >>= 1UL;

        if (0U == mask)
        {
            /* All events have been handled. */
            break;
        }
    }

    /* Clear event interrupt flag */
    base->EVFLAG = clearFlag;
}

void SCTIMER_DriverIRQHandler(uint32_t instance)
{
    if (instance < ARRAY_SIZE(s_sctBases))
    {
        s_sctimerIsr(s_sctBases[instance]);
    }
    SDK_ISR_EXIT_BARRIER;
}

#if defined(SCT0)
void SCT0_DriverIRQHandler(void);
void SCT0_DriverIRQHandler(void)
{
    s_sctimerIsr(SCT0);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(SCT)
void SCT_DriverIRQHandler(void);
void SCT_DriverIRQHandler(void)
{
    s_sctimerIsr(SCT);
    SDK_ISR_EXIT_BARRIER;
}
#endif
