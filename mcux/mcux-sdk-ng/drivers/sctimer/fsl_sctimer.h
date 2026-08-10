/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2023, 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SCTIMER_H_
#define FSL_SCTIMER_H_

#include "fsl_common.h"

/*!
 * @addtogroup sctimer
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_SCTIMER_DRIVER_VERSION (MAKE_VERSION(2, 6, 0)) /*!< Version */
/*! @} */

#ifndef SCT_EV_STATE_STATEMSKn
#define SCT_EV_STATE_STATEMSKn(x) ((uint32_t)(x) & (uint32_t)(((uint64_t)1ULL << FSL_FEATURE_SCT_NUMBER_OF_STATES) - 1ULL))
#endif

/*! @brief SCTimer PWM operation modes */
typedef enum _sctimer_pwm_mode
{
    kSCTIMER_EdgeAlignedPwm = 0U, /*!< Edge-aligned PWM */
    kSCTIMER_CenterAlignedPwm     /*!< Center-aligned PWM */
} sctimer_pwm_mode_t;

/*! @brief SCTimer counters type. */
typedef enum _sctimer_counter
{
    kSCTIMER_Counter_L = (1U << 0), /*!< 16-bit Low counter. */
    kSCTIMER_Counter_H = (1U << 1), /*!< 16-bit High counter. */
    kSCTIMER_Counter_U = (1U << 2), /*!< 32-bit Unified counter. */
} sctimer_counter_t;

/*! @brief List of SCTimer input pins */
typedef enum _sctimer_input
{
    kSCTIMER_Input_0 = 0U, /*!< SCTIMER input 0 */
    kSCTIMER_Input_1,      /*!< SCTIMER input 1 */
    kSCTIMER_Input_2,      /*!< SCTIMER input 2 */
    kSCTIMER_Input_3,      /*!< SCTIMER input 3 */
    kSCTIMER_Input_4,      /*!< SCTIMER input 4 */
    kSCTIMER_Input_5,      /*!< SCTIMER input 5 */
    kSCTIMER_Input_6,      /*!< SCTIMER input 6 */
    kSCTIMER_Input_7       /*!< SCTIMER input 7 */
} sctimer_input_t;

/*! @brief List of SCTimer output pins */
typedef enum _sctimer_out
{
    kSCTIMER_Out_0 = 0U, /*!< SCTIMER output 0*/
    kSCTIMER_Out_1,      /*!< SCTIMER output 1 */
    kSCTIMER_Out_2,      /*!< SCTIMER output 2 */
    kSCTIMER_Out_3,      /*!< SCTIMER output 3 */
    kSCTIMER_Out_4,      /*!< SCTIMER output 4 */
    kSCTIMER_Out_5,      /*!< SCTIMER output 5 */
    kSCTIMER_Out_6,      /*!< SCTIMER output 6 */
    kSCTIMER_Out_7,      /*!< SCTIMER output 7 */
    kSCTIMER_Out_8,      /*!< SCTIMER output 8 */
    kSCTIMER_Out_9       /*!< SCTIMER output 9 */
} sctimer_out_t;

/*! @brief SCTimer PWM output pulse mode: high-true, low-true or no output */
typedef enum _sctimer_pwm_level_select
{
    kSCTIMER_LowTrue = 0U, /*!< Low true pulses */
    kSCTIMER_HighTrue      /*!< High true pulses */
} sctimer_pwm_level_select_t;

/*! @brief Options to configure a SCTimer PWM signal */
typedef struct _sctimer_pwm_signal_param
{
    sctimer_out_t output;             /*!< The output pin to use to generate the PWM signal */
    sctimer_pwm_level_select_t level; /*!< PWM output active level select. */
    uint8_t dutyCyclePercent;         /*!< PWM pulse width, value should be between 0 to 100
                                           0 = always inactive signal (0% duty cycle)
                                           100 = always active signal (100% duty cycle).*/
} sctimer_pwm_signal_param_t;

/*!
 * @brief Handle for a complementary PWM output pair created by SCTIMER_SetupComplementaryPwm().
 *
 * The handle stores the event numbers and parameters needed to update the pair's duty cycle later
 * with SCTIMER_UpdateComplementaryPwmDutycycle(). Dead time is inserted by delaying the relevant turn-on
 * edge (the high side in edge-aligned mode, the low side in center-aligned mode) by deadTimeTicks, which
 * guarantees a non-overlap gap at both switching edges.
 */
typedef struct _sctimer_complementary_pwm_handle
{
    uint32_t periodEvent;   /*!< Shared period/limit event; match = period. Set by frequency, constant
                                 across duty updates. */
    uint32_t highRiseEvent; /*!< Edge-aligned mode: the high-side turn-on event, match = deadTimeTicks
                                 (constant across duty updates). Center-aligned mode: there is no separate
                                 rise event, so this field is set equal to periodEvent and drives no
                                 output - do not treat it as a distinct event in that mode. */
    uint32_t highFallEvent; /*!< High-side turn-off event; match = pulse (= period * duty / 100).
                                 Rewritten on each duty update. */
    uint32_t lowRiseEvent;  /*!< Low-side turn-on event; match = pulse + deadTimeTicks. Rewritten on each
                                 duty update. */
    uint32_t deadTimeTicks; /*!< Dead time in SCT counter clock ticks. */
    sctimer_out_t outHigh;  /*!< High-side output pin. */
    sctimer_out_t outLow;   /*!< Low-side output pin. */
} sctimer_complementary_pwm_handle_t;

/*! @brief When an updated PWM duty cycle takes effect. */
typedef enum _sctimer_pwm_update_mode
{
    kSCTIMER_UpdateImmediately = 0U, /*!< Halt the counter, write the active MATCH register (and its
                                          reload), then restart: the new duty cycle takes effect at once.
                                          Writing the active MATCH register requires the counter halted. */
    kSCTIMER_UpdateOnNextPeriod      /*!< Write only the MATCH reload register while the counter keeps
                                          running: the new duty cycle takes effect at the next counter
                                          cycle (glitchless, no counter stall). Requires CONFIG[NORELOAD]
                                          clear for the affected counter. */
} sctimer_pwm_update_mode_t;

/*! @brief SCTimer clock mode options */
typedef enum _sctimer_clock_mode
{
    kSCTIMER_System_ClockMode = 0U, /*!< System Clock Mode */
    kSCTIMER_Sampled_ClockMode,     /*!< Sampled System Clock Mode */
    kSCTIMER_Input_ClockMode,       /*!< SCT Input Clock Mode */
    kSCTIMER_Asynchronous_ClockMode /*!< Asynchronous Mode */
} sctimer_clock_mode_t;

/*! @brief SCTimer clock select options */
typedef enum _sctimer_clock_select
{
    kSCTIMER_Clock_On_Rise_Input_0 = 0U, /*!< Rising edges on input 0 */
    kSCTIMER_Clock_On_Fall_Input_0,      /*!< Falling edges on input 0 */
    kSCTIMER_Clock_On_Rise_Input_1,      /*!< Rising edges on input 1 */
    kSCTIMER_Clock_On_Fall_Input_1,      /*!< Falling edges on input 1 */
    kSCTIMER_Clock_On_Rise_Input_2,      /*!< Rising edges on input 2 */
    kSCTIMER_Clock_On_Fall_Input_2,      /*!< Falling edges on input 2 */
    kSCTIMER_Clock_On_Rise_Input_3,      /*!< Rising edges on input 3 */
    kSCTIMER_Clock_On_Fall_Input_3,      /*!< Falling edges on input 3 */
    kSCTIMER_Clock_On_Rise_Input_4,      /*!< Rising edges on input 4 */
    kSCTIMER_Clock_On_Fall_Input_4,      /*!< Falling edges on input 4 */
    kSCTIMER_Clock_On_Rise_Input_5,      /*!< Rising edges on input 5 */
    kSCTIMER_Clock_On_Fall_Input_5,      /*!< Falling edges on input 5 */
    kSCTIMER_Clock_On_Rise_Input_6,      /*!< Rising edges on input 6 */
    kSCTIMER_Clock_On_Fall_Input_6,      /*!< Falling edges on input 6 */
    kSCTIMER_Clock_On_Rise_Input_7,      /*!< Rising edges on input 7 */
    kSCTIMER_Clock_On_Fall_Input_7       /*!< Falling edges on input 7 */
} sctimer_clock_select_t;

/*!
 * @brief SCTimer output conflict resolution options.
 *
 * Specifies what action should be taken if multiple events dictate that a given output should be
 * both set and cleared at the same time
 */
typedef enum _sctimer_conflict_resolution
{
    kSCTIMER_ResolveNone = 0U, /*!< No change */
    kSCTIMER_ResolveSet,       /*!< Set output */
    kSCTIMER_ResolveClear,     /*!< Clear output */
    kSCTIMER_ResolveToggle     /*!< Toggle output */
} sctimer_conflict_resolution_t;

/*! @brief List of SCTimer event generation active direction when the counters are operating in BIDIR mode. */
typedef enum _sctimer_event_active_direction
{
    kSCTIMER_ActiveIndependent = 0U, /*!< This event is triggered regardless of the count direction. */
    kSCTIMER_ActiveInCountUp,        /*!< This event is triggered only during up-counting when BIDIR = 1. */
    kSCTIMER_ActiveInCountDown       /*!<  This event is triggered only during down-counting when BIDIR = 1. */
} sctimer_event_active_direction_t;

/*! @brief List of SCTimer event types */
typedef enum _sctimer_event
{
    kSCTIMER_InputLowOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (0 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputRiseOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (1 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputFallOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (2 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputHighOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (3 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),

    kSCTIMER_MatchEventOnly =
        (1 << SCT_EV_CTRL_COMBMODE_SHIFT) + (0 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),

    kSCTIMER_InputLowEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (0 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputRiseEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (1 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputFallEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (2 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputHighEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (3 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),

    kSCTIMER_InputLowAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (0 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputRiseAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (1 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputFallAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (2 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_InputHighAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (3 << SCT_EV_CTRL_IOCOND_SHIFT) + (0 << SCT_EV_CTRL_OUTSEL_SHIFT),

    kSCTIMER_OutputLowOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (0 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputRiseOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (1 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputFallOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (2 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputHighOrMatchEvent =
        (0 << SCT_EV_CTRL_COMBMODE_SHIFT) + (3 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),

    kSCTIMER_OutputLowEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (0 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputRiseEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (1 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputFallEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (2 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputHighEvent =
        (2 << SCT_EV_CTRL_COMBMODE_SHIFT) + (3 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),

    kSCTIMER_OutputLowAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (0 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputRiseAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (1 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputFallAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (2 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT),
    kSCTIMER_OutputHighAndMatchEvent =
        (3 << SCT_EV_CTRL_COMBMODE_SHIFT) + (3 << SCT_EV_CTRL_IOCOND_SHIFT) + (1 << SCT_EV_CTRL_OUTSEL_SHIFT)
} sctimer_event_t;

/*! @brief SCTimer callback typedef. */
typedef void (*sctimer_event_callback_t)(void);

/*! @brief List of SCTimer interrupts */
typedef enum _sctimer_interrupt_enable
{
    kSCTIMER_Event0InterruptEnable  = (1U << 0),  /*!< Event 0 interrupt */
    kSCTIMER_Event1InterruptEnable  = (1U << 1),  /*!< Event 1 interrupt */
    kSCTIMER_Event2InterruptEnable  = (1U << 2),  /*!< Event 2 interrupt */
    kSCTIMER_Event3InterruptEnable  = (1U << 3),  /*!< Event 3 interrupt */
    kSCTIMER_Event4InterruptEnable  = (1U << 4),  /*!< Event 4 interrupt */
    kSCTIMER_Event5InterruptEnable  = (1U << 5),  /*!< Event 5 interrupt */
    kSCTIMER_Event6InterruptEnable  = (1U << 6),  /*!< Event 6 interrupt */
    kSCTIMER_Event7InterruptEnable  = (1U << 7),  /*!< Event 7 interrupt */
    kSCTIMER_Event8InterruptEnable  = (1U << 8),  /*!< Event 8 interrupt */
    kSCTIMER_Event9InterruptEnable  = (1U << 9),  /*!< Event 9 interrupt */
    kSCTIMER_Event10InterruptEnable = (1U << 10), /*!< Event 10 interrupt */
    kSCTIMER_Event11InterruptEnable = (1U << 11), /*!< Event 11 interrupt */
    kSCTIMER_Event12InterruptEnable = (1U << 12), /*!< Event 12 interrupt */
} sctimer_interrupt_enable_t;

/*! @brief List of SCTimer flags */
typedef enum _sctimer_status_flags
{
    kSCTIMER_Event0Flag  = (1U << 0),  /*!< Event 0 Flag */
    kSCTIMER_Event1Flag  = (1U << 1),  /*!< Event 1 Flag */
    kSCTIMER_Event2Flag  = (1U << 2),  /*!< Event 2 Flag */
    kSCTIMER_Event3Flag  = (1U << 3),  /*!< Event 3 Flag */
    kSCTIMER_Event4Flag  = (1U << 4),  /*!< Event 4 Flag */
    kSCTIMER_Event5Flag  = (1U << 5),  /*!< Event 5 Flag */
    kSCTIMER_Event6Flag  = (1U << 6),  /*!< Event 6 Flag */
    kSCTIMER_Event7Flag  = (1U << 7),  /*!< Event 7 Flag */
    kSCTIMER_Event8Flag  = (1U << 8),  /*!< Event 8 Flag */
    kSCTIMER_Event9Flag  = (1U << 9),  /*!< Event 9 Flag */
    kSCTIMER_Event10Flag = (1U << 10), /*!< Event 10 Flag */
    kSCTIMER_Event11Flag = (1U << 11), /*!< Event 11 Flag */
    kSCTIMER_Event12Flag = (1U << 12), /*!< Event 12 Flag */
    kSCTIMER_BusErrorLFlag =
        (1U << SCT_CONFLAG_BUSERRL_SHIFT), /*!< Bus error due to write when L counter was not halted */
    kSCTIMER_BusErrorHFlag =
        (int)(1U << SCT_CONFLAG_BUSERRH_SHIFT) /*!< Bus error due to write when H counter was not halted */
} sctimer_status_flags_t;

/*!
 * @brief SCTimer configuration structure
 *
 * This structure holds the configuration settings for the SCTimer peripheral. To initialize this
 * structure to reasonable defaults, call the SCTMR_GetDefaultConfig() function and pass a
 * pointer to the configuration structure instance.
 *
 * The configuration structure can be made constant so as to reside in flash.
 */
typedef struct _sctimer_config
{
    bool enableCounterUnify;            /*!< true: SCT operates as a unified 32-bit counter;
                                             false: SCT operates as two 16-bit counters.
                                             User can use the 16-bit low counter and the 16-bit high counters at the
                                             same time; for Hardware limit, user can not use unified 32-bit counter
                                             and any 16-bit low/high counter at the same time. */
    sctimer_clock_mode_t clockMode;     /*!< SCT clock mode value */
    sctimer_clock_select_t clockSelect; /*!< SCT clock select value */
    bool enableBidirection_l;           /*!< true: Up-down count mode for the L or unified counter
                                             false: Up count mode only for the L or unified counter */
    bool enableBidirection_h;           /*!< true: Up-down count mode for the H or unified counter
                                             false: Up count mode only for the H or unified counter.
                                             This field is used only if the enableCounterUnify is set
                                             to false */
    uint8_t prescale_l;                 /*!< Prescale value to produce the L or unified counter clock */
    uint8_t prescale_h;                 /*!< Prescale value to produce the H counter clock.
                                             This field is used only if the enableCounterUnify is set
                                             to false */
    uint8_t outInitState;               /*!< Defines the initial output value */
    uint8_t inputsync;                  /*!< SCT INSYNC value, INSYNC field in the CONFIG register, from bit9 to bit 16.
                                             it is used to define synchronization for input N:
                                             bit 9  = input 0
                                             bit 10 = input 1
                                             bit 11 = input 2
                                             bit 12 = input 3
                                             All other bits are reserved (bit13 ~bit 16).
                                             How User to set the the value for the member inputsync.
                                             IE: delay for input0, and input 1, bypasses for input 2 and input 3
                                             MACRO definition in user level.
                                             \#define INPUTSYNC0      (0U)
                                             \#define INPUTSYNC1      (1U)
                                             \#define INPUTSYNC2      (2U)
                                             \#define INPUTSYNC3      (3U)
                                             User Code.
                                             sctimerInfo.inputsync = (1 << INPUTSYNC2) | (1 << INPUTSYNC3); */
} sctimer_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Ungates the SCTimer clock and configures the peripheral for basic operation.
 *
 * @note This API should be called at the beginning of the application using the SCTimer driver.
 *
 * @param base   SCTimer peripheral base address
 * @param config Pointer to the user configuration structure.
 *
 * @return kStatus_Success indicates success; Else indicates failure.
 */
status_t SCTIMER_Init(SCT_Type *base, const sctimer_config_t *config);

/*!
 * @brief Gates the SCTimer clock.
 *
 * @param base SCTimer peripheral base address
 */
void SCTIMER_Deinit(SCT_Type *base);

/*!
 * @brief  Fills in the SCTimer configuration structure with the default settings.
 *
 * The default values are:
 * @code
 *  config->enableCounterUnify = true;
 *  config->clockMode = kSCTIMER_System_ClockMode;
 *  config->clockSelect = kSCTIMER_Clock_On_Rise_Input_0;
 *  config->enableBidirection_l = false;
 *  config->enableBidirection_h = false;
 *  config->prescale_l = 0U;
 *  config->prescale_h = 0U;
 *  config->outInitState = 0U;
 *  config->inputsync  = 0xFU;
 * @endcode
 * @param config Pointer to the user configuration structure.
 */
void SCTIMER_GetDefaultConfig(sctimer_config_t *config);

/*! @}*/

/*!
 * @name PWM setup operations
 * @{
 */

/*!
 * @brief Configures the PWM signal parameters.
 *
 * @deprecated Use SCTIMER_SetupSharedPeriodPwm() instead. That function configures one channel per call
 * and reuses a single shared period/limit event across same-frequency channels (N + 1 events for N
 * channels instead of 2 * N), and returns the pulse event explicitly so the duty cycle can be updated
 * with SCTIMER_UpdatePwmDutycycleByEvent(). This function remains functional for backward compatibility.
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
 * @note When setting PWM output from multiple output pins, they all should use the same PWM mode
 * i.e all PWM's should be either edge-aligned or center-aligned.
 * When using this API, the PWM signal frequency of all the initialized channels must be the same.
 * Otherwise all the initialized channels' PWM signal frequency is equal to the last call to the
 * API's pwmFreq_Hz.
 *
 * @param base        SCTimer peripheral base address
 * @param pwmParams   PWM parameters to configure the output
 * @param mode        PWM operation mode, options available in enumeration ::sctimer_pwm_mode_t
 * @param pwmFreq_Hz  PWM signal frequency in Hz
 * @param srcClock_Hz SCTimer counter clock in Hz
 * @param event       Pointer to a variable where the PWM period event number is stored
 *
 * @return kStatus_Success on success
 *         kStatus_Fail If we have hit the limit in terms of number of events created or if
 *                      an incorrect PWM dutycylce is passed in.
 */
status_t SCTIMER_SetupPwm(SCT_Type *base,
                          const sctimer_pwm_signal_param_t *pwmParams,
                          sctimer_pwm_mode_t mode,
                          uint32_t pwmFreq_Hz,
                          uint32_t srcClock_Hz,
                          uint32_t *event);

/*!
 * @brief Updates the duty cycle of an active PWM signal.
 *
 * @deprecated Use SCTIMER_UpdatePwmDutycycleByEvent() instead. That function takes the period and pulse
 * events explicitly (it does not assume the pulse event is event + 1), so it works with channels created
 * by SCTIMER_SetupSharedPeriodPwm(), and it can update immediately or glitchlessly at the next period.
 * This function remains functional for backward compatibility.
 *
 * Before calling  this function, the counter is set to operate as one 32-bit counter (unify bit is set to 1).
 *
 * @param base              SCTimer peripheral base address
 * @param output            The output to configure
 * @param dutyCyclePercent  New PWM pulse width; the value should be between 1 to 100
 * @param event             Event number associated with this PWM signal. This was returned to the user by the
 *                          function SCTIMER_SetupPwm().
 */
void SCTIMER_UpdatePwmDutycycle(SCT_Type *base, sctimer_out_t output, uint8_t dutyCyclePercent, uint32_t event);

/*!
 * @brief Configures one PWM channel that shares an auto-detected period event across calls.
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
 * @note Period detection assumes the shared PWM period/limit is the lowest-numbered unified-counter
 * limit event (the only limit events created by this function and SCTIMER_SetupPwm()). If the application
 * created other unified-counter limit events before calling this function, detection may match the wrong
 * event; in that case create the PWM channels before any unrelated limit events.
 *
 * @note Each call configures exactly one channel and is atomic for that channel only (on failure it
 * creates nothing). Building a multi-channel group is a sequence of independent calls; this API does NOT
 * roll the whole group back if a later call fails.
 *
 * @note The channel is enabled in the current state only. In a multi-state design the caller must
 * re-enable the returned periodEvent and each channel's pulseEvent in every state that should run the
 * group (via SCTIMER_ScheduleEvent()). Because the period event is shared, failing to re-schedule it in a
 * state disrupts ALL channels in that state, not just one.
 *
 * @param base         SCTimer peripheral base address
 * @param pwmParam     Pointer to this channel's PWM parameters (output, level, duty)
 * @param mode         PWM operation mode (all sharing channels must use the same mode), see ::sctimer_pwm_mode_t
 * @param pwmFreq_Hz   Common PWM signal frequency in Hz (all sharing channels must use the same frequency)
 * @param srcClock_Hz  SCTimer counter clock in Hz
 * @param periodEvent  Pointer to a variable where the shared period event number (new or reused) is stored
 * @param pulseEvent   Pointer to a variable where this channel's pulse event number is stored
 *
 * @return kStatus_Success on success
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
                                      uint32_t *pulseEvent);

/*!
 * @brief Updates the duty cycle of a PWM signal using explicit period and pulse events.
 *
 * Unlike SCTIMER_UpdatePwmDutycycle(), this function does not assume the pulse event is periodEvent + 1,
 * so it works for channels created by SCTIMER_SetupSharedPeriodPwm() where the pulse events are not
 * adjacent to the shared period event. The counter must be in unified 32-bit mode.
 *
 * @param base              SCTimer peripheral base address
 * @param output            The output to configure
 * @param dutyCyclePercent  New PWM pulse width; the value should be between 0 and 100
 * @param periodEvent       The shared period event (as returned by SCTIMER_SetupSharedPeriodPwm())
 * @param pulseEvent        The channel's pulse event (as returned by SCTIMER_SetupSharedPeriodPwm())
 * @param updateMode        When the new duty cycle takes effect, see ::sctimer_pwm_update_mode_t
 */
void SCTIMER_UpdatePwmDutycycleByEvent(SCT_Type *base,
                                       sctimer_out_t output,
                                       uint8_t dutyCyclePercent,
                                       uint32_t periodEvent,
                                       uint32_t pulseEvent,
                                       sctimer_pwm_update_mode_t updateMode);

/*!
 * @brief Configures a complementary PWM output pair with programmable dead time.
 *
 * Builds a high-side/low-side complementary pair on the unified 32-bit counter from one duty value plus a
 * dead time expressed in SCT counter clock ticks. Dead time is inserted by delaying each output's turn-on
 * by deadTimeTicks while keeping turn-off immediate, which guarantees a non-overlap (dead-time) gap at
 * both switching edges so the two outputs are never simultaneously active (no shoot-through).
 *
 * The shared period event also limits (resets) the counter. The returned handle is used to update the
 * pair's duty cycle later with SCTIMER_UpdateComplementaryPwmDutycycle().
 *
 * @note Dead time is inserted by delaying the relevant turn-on edge - the high side in edge-aligned mode,
 * the low side in center-aligned mode - so that output's active width shrinks by deadTimeTicks (the usual
 * cost of dead time).
 *
 * @note For a switching duty the valid range is 0 < duty < 100 (needs deadTimeTicks < duty and
 * duty + deadTimeTicks < period); deadTimeTicks = 0 is allowed (strict complementary). 0 % and 100 % are
 * accepted as constant complementary levels (high-side fully off / fully on): the pair is driven to static
 * opposite levels with no switching and no dead-time window. A both-off fault state is not expressible as a
 * duty - use a separate output force/disable path for that.
 *
 * @note Call this function once per complementary pair. To drive several pairs on the same SCTimer (for
 * example the three half-bridges of a 3-phase inverter), call it once for each pair — but all pairs MUST
 * use the same pwmFreq_Hz and the same mode, because they share one unified counter (a single count
 * direction and period). Mixing frequencies or alignments across pairs creates conflicting limit events
 * on the counter and produces an incorrect waveform.
 *
 * @param base             SCTimer peripheral base address
 * @param outHigh          High-side output pin
 * @param outLow           Low-side output pin (complement of outHigh)
 * @param dutyCyclePercent High-side duty cycle, value should be between 0 and 100
 * @param deadTimeTicks    Dead time in SCT counter clock ticks, inserted at both edges; 0 = no dead time
 *                         (strict complementary)
 * @param mode             PWM operation mode, see ::sctimer_pwm_mode_t
 * @param pwmFreq_Hz       PWM signal frequency in Hz
 * @param srcClock_Hz      SCTimer counter clock in Hz
 * @param handle           Pointer to a handle that receives the pair's event numbers and parameters
 *
 * @return kStatus_Success on success
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
                                       sctimer_complementary_pwm_handle_t *handle);

/*!
 * @brief Updates the duty cycle of a complementary PWM pair, preserving dead time.
 *
 * Recomputes both moving switching edges (high-side turn-off and low-side turn-on) from the new duty
 * cycle while keeping the dead-time offset, and writes them so the no-overlap guarantee holds across the
 * update. In kSCTIMER_UpdateOnNextPeriod mode both edges reload together at the next counter cycle, so
 * the dead-time relationship is updated atomically and glitchlessly.
 *
 * @note A switching duty must keep the dead time inside the period (deadTimeTicks < duty and
 * duty + deadTimeTicks < period). 0 % and 100 % are accepted as constant complementary levels: the pair is
 * driven to static opposite levels (no switching, no dead time). Switching between a constant level and a
 * switching duty briefly halts the counter to re-bind the outputs. A both-off fault state is not a duty -
 * use a separate output force/disable path.
 *
 * @note updateMode is honored only for a switching duty (0 < duty < 100). A 0 % or 100 % update is always
 * applied immediately (counter briefly halted), regardless of updateMode, because a constant level cannot
 * be loaded through the glitchless reload-register (MATCHREL) path: it requires detaching the events and
 * forcing the output levels, which needs a halt. kSCTIMER_UpdateOnNextPeriod therefore does not defer a
 * 0 %/100 % change to the next period boundary.
 *
 * @param base             SCTimer peripheral base address
 * @param handle           Handle returned by SCTIMER_SetupComplementaryPwm()
 * @param dutyCyclePercent New high-side duty cycle, value should be between 0 and 100
 * @param updateMode       When the new duty cycle takes effect, see ::sctimer_pwm_update_mode_t. Ignored for
 *                         a 0 %/100 % update, which is always immediate; see the note above.
 *
 * @return kStatus_Success on success
 *         kStatus_InvalidArgument if the dead time does not fit the requested duty/period
 */
status_t SCTIMER_UpdateComplementaryPwmDutycycle(SCT_Type *base,
                                                 const sctimer_complementary_pwm_handle_t *handle,
                                                 uint8_t dutyCyclePercent,
                                                 sctimer_pwm_update_mode_t updateMode);

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief Enables the selected SCTimer interrupts.
 *
 * @param base SCTimer peripheral base address
 * @param mask The interrupts to enable. This is a logical OR of members of the
 *             enumeration ::sctimer_interrupt_enable_t
 */
static inline void SCTIMER_EnableInterrupts(SCT_Type *base, uint32_t mask)
{
    base->EVEN |= mask;
}

/*!
 * @brief Disables the selected SCTimer interrupts.
 *
 * @param base SCTimer peripheral base address
 * @param mask The interrupts to enable. This is a logical OR of members of the
 *             enumeration ::sctimer_interrupt_enable_t
 */
static inline void SCTIMER_DisableInterrupts(SCT_Type *base, uint32_t mask)
{
    base->EVEN &= ~mask;
}

/*!
 * @brief Gets the enabled SCTimer interrupts.
 *
 * @param base SCTimer peripheral base address
 *
 * @return The enabled interrupts. This is the logical OR of members of the
 *         enumeration ::sctimer_interrupt_enable_t
 */
static inline uint32_t SCTIMER_GetEnabledInterrupts(SCT_Type *base)
{
    return (base->EVEN & 0xFFFFU);
}

/*! @}*/

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Gets the SCTimer status flags.
 *
 * @param base SCTimer peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::sctimer_status_flags_t
 */
static inline uint32_t SCTIMER_GetStatusFlags(SCT_Type *base)
{
    uint32_t statusFlags = 0;

    /* Add the recorded events */
    statusFlags = (base->EVFLAG & 0xFFFFU);

    /* Add bus error flags */
    statusFlags |= (base->CONFLAG & (SCT_CONFLAG_BUSERRL_MASK | SCT_CONFLAG_BUSERRH_MASK));

    return statusFlags;
}

/*!
 * @brief Clears the SCTimer status flags.
 *
 * @param base SCTimer peripheral base address
 * @param mask The status flags to clear. This is a logical OR of members of the
 *             enumeration ::sctimer_status_flags_t
 */
static inline void SCTIMER_ClearStatusFlags(SCT_Type *base, uint32_t mask)
{
    /* Write to the flag registers */
    base->EVFLAG  = (mask & 0xFFFFU);
    base->CONFLAG = (mask & (SCT_CONFLAG_BUSERRL_MASK | SCT_CONFLAG_BUSERRH_MASK));
}

/*! @}*/

/*!
 * @name Counter Start and Stop
 * @{
 */

/*!
 * @brief Starts the SCTimer counter.
 *
 * @note In 16-bit mode, we can enable both Counter_L and Counter_H, In 32-bit mode, we only can select Counter_U.
 *
 * @param base            SCTimer peripheral base address
 * @param countertoStart  The SCTimer counters to enable. This is a logical OR of members of the
 *                        enumeration ::sctimer_counter_t.
 */
static inline void SCTIMER_StartTimer(SCT_Type *base, uint32_t countertoStart)
{
    switch (countertoStart)
    {
        case (uint32_t)kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Clear HALT_L bit when user wants to start the Low counter */
            base->CTRL_ACCESS16BIT.CTRLL &= MCUX_MASK_INVERT_16(SCT_CTRLL_HALT_L_MASK);
            break;

        case (uint32_t)kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Clear HALT_H bit when user wants to start the High counter */
            base->CTRL &= ~(SCT_CTRL_HALT_H_MASK);
            break;

        case (uint32_t)kSCTIMER_Counter_L | (uint32_t)kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Clear HALT_L/HALT_H bit when user wants to H counter and L counter at same time */
            base->CTRL &= ~(SCT_CTRL_HALT_L_MASK | SCT_CTRL_HALT_H_MASK);
            break;

        case (uint32_t)kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Clear HALT_L bit when the counter is operating in 32-bit mode (unify counter). */
            base->CTRL &= ~(SCT_CTRL_HALT_L_MASK);
            break;

        default:
            /* Counter_L/Counter_H can't work together with Counter_U. */
            assert(false);
            break;
    }
}

/*!
 * @brief Halts the SCTimer counter.
 *
 * @param base          SCTimer peripheral base address
 * @param countertoStop The SCTimer counters to stop. This is a logical OR of members of the
 *                      enumeration ::sctimer_counter_t.
 */
static inline void SCTIMER_StopTimer(SCT_Type *base, uint32_t countertoStop)
{
    switch (countertoStop)
    {
        case (uint32_t)kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Set HALT_L bit when user wants to start the Low counter */
            base->CTRL_ACCESS16BIT.CTRLL |= (SCT_CTRLL_HALT_L_MASK);
            break;

        case (uint32_t)kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Set HALT_H bit when user wants to start the High counter */
            base->CTRL |= (SCT_CTRL_HALT_H_MASK);
            break;

        case (uint32_t)kSCTIMER_Counter_L | (uint32_t)kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Clear HALT_L/HALT_H bit when user wants to H counter and L counter at same time */
            base->CTRL |= (SCT_CTRL_HALT_L_MASK | SCT_CTRL_HALT_H_MASK);
            break;

        case (uint32_t)kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Set HALT_L bit when the counter is operating in 32-bit mode (unify counter). */
            base->CTRL |= (SCT_CTRL_HALT_L_MASK);
            break;

        default:
            /* Counter_L/Counter_H can't work together with Counter_U. */
            assert(false);
            break;
    }
}

/*! @}*/

/*!
 * @name Functions to create a new event and manage the state logic
 * @{
 */

/*!
 * @brief Create an event that is triggered on a match or IO and schedule in current state.
 *
 * This function will configure an event using the options provided by the user. If the event type uses
 * the counter match, then the function will set the user provided match value into a match register
 * and put this match register number into the event control register.
 * The event is enabled for the current state and the event number is increased by one at the end.
 * The function returns the event number; this event number can be used to configure actions to be
 * done when this event is triggered.
 *
 * @param base         SCTimer peripheral base address
 * @param howToMonitor Event type; options are available in the enumeration ::sctimer_interrupt_enable_t
 * @param matchValue   The match value that will be programmed to a match register
 * @param whichIO      The input or output that will be involved in event triggering. This field
 *                      is ignored if the event type is "match only"
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @param event        Pointer to a variable where the new event number is stored
 *
 * @return kStatus_Success on success
 *         kStatus_Error if we have hit the limit in terms of number of events created or
                         if we have reached the limit in terms of number of match registers
 */
status_t SCTIMER_CreateAndScheduleEvent(SCT_Type *base,
                                        sctimer_event_t howToMonitor,
                                        uint32_t matchValue,
                                        uint32_t whichIO,
                                        sctimer_counter_t whichCounter,
                                        uint32_t *event);

/*!
 * @brief Enable an event in the current state.
 *
 * This function will allow the event passed in to trigger in the current state. The event must
 * be created earlier by either calling the function SCTIMER_SetupPwm() or function
 * SCTIMER_CreateAndScheduleEvent() .
 *
 * @param base  SCTimer peripheral base address
 * @param event Event number to enable in the current state
 *
 */
void SCTIMER_ScheduleEvent(SCT_Type *base, uint32_t event);

/*!
 * @brief Increase the state by 1
 *
 * All future events created by calling the function SCTIMER_ScheduleEvent() will be enabled in this new
 * state.
 *
 * @param base  SCTimer peripheral base address
 *
 * @return kStatus_Success on success
 *         kStatus_Error if we have hit the limit in terms of states used

 */
status_t SCTIMER_IncreaseState(SCT_Type *base);

/*!
 * @brief Provides the current state
 *
 * User can use this to set the next state by calling the function SCTIMER_SetupNextStateAction().
 *
 * @param base SCTimer peripheral base address
 *
 * @return The current state
 */
uint32_t SCTIMER_GetCurrentState(SCT_Type *base);

/*!
 * @brief Set the counter current state.
 *
 * The function is to set the state variable bit field of STATE register. Writing to the STATE_L, STATE_H, or unified
 * register is only allowed when the corresponding counter is halted (HALT bits are set to 1 in the CTRL register).
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                     In 32-bit mode, we can select Counter_U.
 * @param state        The counter current state number (only support range from 0~31).
 */
static inline void SCTIMER_SetCounterState(SCT_Type *base, sctimer_counter_t whichCounter, uint32_t state)
{
    /* SCT only support 0 ~ FSL_FEATURE_SCT_NUMBER_OF_STATES state value. */
    assert(state < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_STATES);

    SCTIMER_StopTimer(base, (uint32_t)whichCounter);

    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use STATE_L bits when user wants to setup the Low counter */
            base->STATE_ACCESS16BIT.STATEL = SCT_STATEL_STATEL(state);
            break;

        case kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use STATE_H bits when user wants to start the High counter */
            base->STATE = (uint32_t)base->STATE_ACCESS16BIT.STATEL | SCT_STATE_STATE_H(state);
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use STATE_L bits when counter is operating in 32-bit mode (unify counter). */
            base->STATE = SCT_STATE_STATE_L(state);
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }

    SCTIMER_StartTimer(base, (uint32_t)whichCounter);
}

/*!
 * @brief Get the counter current state value.
 *
 * The function is to get the state variable bit field of STATE register.
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                     In 32-bit mode, we can select Counter_U.
 * @return The the counter current state value.
 */
static inline uint16_t SCTIMER_GetCounterState(SCT_Type *base, sctimer_counter_t whichCounter)
{
    uint16_t regs;

    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use STATE_L bits when user wants to setup the Low counter */
            regs = base->STATE_ACCESS16BIT.STATEL & SCT_STATEL_STATEL_MASK;
            break;

        case kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use STATE_H bits when user wants to start the High counter */
            regs = base->STATE_ACCESS16BIT.STATEH & SCT_STATEH_STATEH_MASK;
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use STATE_L bits when counter is operating in 32-bit mode (unify counter). */
            regs = (uint16_t)(base->STATE & SCT_STATE_STATE_L_MASK);
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }

    return regs;
}

/*! @}*/

/*!
 * @name Actions to take in response to an event
 * @{
 */

/*!
 * @brief Setup capture of the counter value on trigger of a selected event
 *
 * @param base            SCTimer peripheral base address
 * @param whichCounter    SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                         In 32-bit mode, we can select Counter_U.
 * @param captureRegister Pointer to a variable where the capture register number will be returned. User
 *                         can read the captured value from this register when the specified event is triggered.
 * @param event           Event number that will trigger the capture
 *
 * @return kStatus_Success on success
 *         kStatus_Error if we have hit the limit in terms of number of match/capture registers available
 */
status_t SCTIMER_SetupCaptureAction(SCT_Type *base,
                                    sctimer_counter_t whichCounter,
                                    uint32_t *captureRegister,
                                    uint32_t event);

/*!
 * @brief Receive noticification when the event trigger an interrupt.
 *
 * If the interrupt for the event is enabled by the user, then a callback can be registered
 * which will be invoked when the event is triggered
 *
 * @param base     SCTimer peripheral base address
 * @param event    Event number that will trigger the interrupt
 * @param callback Function to invoke when the event is triggered
 */

void SCTIMER_SetCallback(SCT_Type *base, sctimer_event_callback_t callback, uint32_t event);

/*!
 * @brief Change the load method of transition to the specified state.
 *
 * Change the load method of transition, it will be triggered by the event number that is passed in by the user.
 *
 * @param base      SCTimer peripheral base address
 * @param event     Event number that will change the method to trigger the state transition
 * @param fgLoad    The method to load highest-numbered event occurring for that state to the STATE register.
 *                  - true: Load the STATEV value to STATE when the event occurs to be the next state.
 *                  - false: Add the STATEV value to STATE when the event occurs to be the next state.
 */
static inline void SCTIMER_SetupStateLdMethodAction(SCT_Type *base, uint32_t event, bool fgLoad)
{
    uint32_t reg = base->EV[event].CTRL;

    if (fgLoad)
    {
        /* Load the STATEV value to STATE when the event occurs to be the next state */
        reg |= SCT_EV_CTRL_STATELD_MASK;
    }
    else
    {
        /* Add the STATEV value to STATE when the event occurs to be the next state */
        reg &= ~SCT_EV_CTRL_STATELD_MASK;
    }

    base->EV[event].CTRL = reg;
}

/*!
 * @brief Transition to the specified state with Load method.
 *
 * This transition will be triggered by the event number that is passed in by the user, the method decide how to load
 * the highest-numbered event occurring for that state to the STATE register.
 *
 * @param base      SCTimer peripheral base address
 * @param nextState The next state SCTimer will transition to
 * @param event     Event number that will trigger the state transition
 * @param fgLoad    The method to load the highest-numbered event occurring for that state to the STATE register.
 *                  - true: Load the STATEV value to STATE when the event occurs to be the next state.
 *                  - false: Add the STATEV value to STATE when the event occurs to be the next state.
 */
static inline void SCTIMER_SetupNextStateActionwithLdMethod(SCT_Type *base,
                                                            uint32_t nextState,
                                                            uint32_t event,
                                                            bool fgLoad)
{
    uint32_t reg = base->EV[event].CTRL;

    reg &= ~(SCT_EV_CTRL_STATEV_MASK | SCT_EV_CTRL_STATELD_MASK);

    reg |= SCT_EV_CTRL_STATEV(nextState);

    if (fgLoad)
    {
        /* Load the STATEV value when the event occurs to be the next state */
        reg |= SCT_EV_CTRL_STATELD_MASK;
    }

    base->EV[event].CTRL = reg;
}

/*!
 * @brief Transition to the specified state.
 * @deprecated Do not use this function.  It has been superceded by @ref SCTIMER_SetupNextStateActionwithLdMethod
 *
 * This transition will be triggered by the event number that is passed in by the user.
 *
 * @param base      SCTimer peripheral base address
 * @param nextState The next state SCTimer will transition to
 * @param event     Event number that will trigger the state transition
 */
static inline void SCTIMER_SetupNextStateAction(SCT_Type *base, uint32_t nextState, uint32_t event)
{
    uint32_t reg = base->EV[event].CTRL;

    reg &= ~(SCT_EV_CTRL_STATEV_MASK);
    /* Load the STATEV value when the event occurs to be the next state */
    reg |= SCT_EV_CTRL_STATEV(nextState) | SCT_EV_CTRL_STATELD_MASK;

    base->EV[event].CTRL = reg;
}

/*!
 * @brief Setup event active direction when the counters are operating in BIDIR mode.
 *
 * @param base              SCTimer peripheral base address
 * @param activeDirection   Event generation active direction, see @ref sctimer_event_active_direction_t.
 * @param event             Event number that need setup the active direction.
 */
static inline void SCTIMER_SetupEventActiveDirection(SCT_Type *base,
                                                     sctimer_event_active_direction_t activeDirection,
                                                     uint32_t event)
{
    uint32_t reg = base->EV[event].CTRL;

    reg &= ~(SCT_EV_CTRL_DIRECTION_MASK);

    reg |= SCT_EV_CTRL_DIRECTION(activeDirection);

    base->EV[event].CTRL = reg;
}

/*!
 * @brief Set the Output.
 *
 * This output will be set when the event number that is passed in by the user is triggered.
 *
 * @param base    SCTimer peripheral base address
 * @param whichIO The output to set
 * @param event   Event number that will trigger the output change
 */
static inline void SCTIMER_SetupOutputSetAction(SCT_Type *base, uint32_t whichIO, uint32_t event)
{
    assert(whichIO < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS);

    base->OUT[whichIO].SET |= (1UL << event);
}

/*!
 * @brief Clear the Output.
 *
 * This output will be cleared when the event number that is passed in by the user is triggered.
 *
 * @param base    SCTimer peripheral base address
 * @param whichIO The output to clear
 * @param event   Event number that will trigger the output change
 */
static inline void SCTIMER_SetupOutputClearAction(SCT_Type *base, uint32_t whichIO, uint32_t event)
{
    assert(whichIO < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS);

    base->OUT[whichIO].CLR |= (1UL << event);
}

/*!
 * @brief Toggle the output level.
 *
 * This change in the output level is triggered by the event number that is passed in by the user.
 *
 * @param base    SCTimer peripheral base address
 * @param whichIO The output to toggle
 * @param event   Event number that will trigger the output change
 */
void SCTIMER_SetupOutputToggleAction(SCT_Type *base, uint32_t whichIO, uint32_t event);

/*!
 * @brief Limit the running counter.
 *
 * The counter is limited when the event number that is passed in by the user is triggered.
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @param event        Event number that will trigger the counter to be limited
 */
static inline void SCTIMER_SetupCounterLimitAction(SCT_Type *base, sctimer_counter_t whichCounter, uint32_t event)
{
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);
    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when user wants to setup the Low counter */
            base->LIMIT_ACCESS16BIT.LIMITL |= SCT_LIMITL_LIMITL((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_H bits when user wants to setup the High counter */
            base->LIMIT |= SCT_LIMIT_LIMMSK_H((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when counter is operating in 32-bit mode (unify counter). */
            base->LIMIT |= SCT_LIMIT_LIMMSK_L((1UL << event) & 0xFFFFU);
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }
}

/*!
 * @brief Stop the running counter.
 *
 * The counter is stopped when the event number that is passed in by the user is triggered.
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @param event        Event number that will trigger the counter to be stopped
 */
static inline void SCTIMER_SetupCounterStopAction(SCT_Type *base, sctimer_counter_t whichCounter, uint32_t event)
{
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);
    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when user wants to setup the Low counter */
            base->STOP_ACCESS16BIT.STOPL |= SCT_STOPL_STOPL((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_H bits when user wants to start the High counter */
            base->STOP |= SCT_STOP_STOPMSK_H((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when counter is operating in 32-bit mode (unify counter). */
            base->STOP |= SCT_STOP_STOPMSK_L((1UL << event) & 0xFFFFU);
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }
}

/*!
 * @brief Re-start the stopped counter.
 *
 * The counter will re-start when the event number that is passed in by the user is triggered.
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @param event        Event number that will trigger the counter to re-start
 */
static inline void SCTIMER_SetupCounterStartAction(SCT_Type *base, sctimer_counter_t whichCounter, uint32_t event)
{
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);
    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when user wants to setup the Low counter */
            base->START_ACCESS16BIT.STARTL |= SCT_STARTL_STARTL((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_H bits when user wants to start the High counter */
            base->START |= SCT_START_STARTMSK_H((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when counter is operating in 32-bit mode (unify counter). */
            base->START |= SCT_START_STARTMSK_L((1UL << event) & 0xFFFFU);
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }
}

/*!
 * @brief Halt the running counter.
 *
 * The counter is disabled (halted) when the event number that is passed in by the user is
 * triggered. When the counter is halted, all further events are disabled. The HALT condition
 * can only be removed by calling the SCTIMER_StartTimer() function.
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @param event        Event number that will trigger the counter to be halted
 */
static inline void SCTIMER_SetupCounterHaltAction(SCT_Type *base, sctimer_counter_t whichCounter, uint32_t event)
{
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);
    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when user wants to setup the Low counter */
            base->HALT_ACCESS16BIT.HALTL |= SCT_HALTL_HALTL((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_H bits when user wants to start the High counter */
            base->HALT |= SCT_HALT_HALTMSK_H((1UL << event) & 0xFFFFU);
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when counter is operating in 32-bit mode (unify counter). */
            base->HALT |= SCT_HALT_HALTMSK_L((1UL << event) & 0xFFFFU);
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }
}

#if !(defined(FSL_FEATURE_SCT_HAS_NO_DMA_REQUEST) && FSL_FEATURE_SCT_HAS_NO_DMA_REQUEST)
/*!
 * @brief Generate a DMA request.
 *
 * DMA request will be triggered by the event number that is passed in by the user.
 *
 * @param base      SCTimer peripheral base address
 * @param dmaNumber The DMA request to generate
 * @param event     Event number that will trigger the DMA request
 */
static inline void SCTIMER_SetupDmaTriggerAction(SCT_Type *base, uint32_t dmaNumber, uint32_t event)
{
    if (dmaNumber == 0U)
    {
        base->DMAREQ0 |= (1UL << event);
    }
    else
    {
        base->DMAREQ1 |= (1UL << event);
    }
}
#endif /* FSL_FEATURE_SCT_HAS_NO_DMA_REQUEST */

/*!
 * @brief Set the value of counter.
 *
 * The function is to set the value of Count register, Writing to the COUNT_L, COUNT_H, or unified register
 * is only allowed when the corresponding counter is halted (HALT bits are set to 1 in the CTRL register).
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @param value        the counter value update to the COUNT register.
 */
static inline void SCTIMER_SetCOUNTValue(SCT_Type *base, sctimer_counter_t whichCounter, uint32_t value)
{
    SCTIMER_StopTimer(base, (uint32_t)whichCounter);

    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(value <= 0xFFFFU);
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when user wants to setup the Low counter */
            base->COUNT_ACCESS16BIT.COUNTL = (uint16_t)value;
            break;

        case kSCTIMER_Counter_H:
            assert(value <= 0xFFFFU);
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_H bits when user wants to setup the High counter */
            base->COUNT = (uint32_t)base->COUNT_ACCESS16BIT.COUNTL | SCT_COUNT_CTR_H(value);
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use both Counter_L/Counter_H bits when counter is operating in 32-bit mode (unify counter). */
            base->COUNT = value;
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }

    SCTIMER_StartTimer(base, (uint32_t)whichCounter);
}

/*!
 * @brief Get the value of counter.
 *
 * The function is to read the value of Count register, software can read the counter registers at any time..
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @return The value of counter selected.
 */
static inline uint32_t SCTIMER_GetCOUNTValue(SCT_Type *base, sctimer_counter_t whichCounter)
{
    uint32_t value;

    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when user wants to setup the Low counter */
            value = base->COUNT_ACCESS16BIT.COUNTL;
            break;

        case kSCTIMER_Counter_H:
            assert(0U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_H bits when user wants to start the High counter */
            value = base->COUNT_ACCESS16BIT.COUNTH;
            break;

        case kSCTIMER_Counter_U:
            assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));
            /* Use Counter_L bits when counter is operating in 32-bit mode (unify counter). */
            value = base->COUNT;
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }

    return value;
}

/*!
 * @brief Set the state mask bit field of EV_STATE register.
 *
 * @param base         SCTimer peripheral base address
 * @param event        The EV_STATE register be set.
 * @param state        The state value in which the event is enabled to occur.
 */
static inline void SCTIMER_SetEventInState(SCT_Type *base, uint32_t event, uint32_t state)
{
    assert(state < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_STATES);
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);

    base->EV[event].STATE |= SCT_EV_STATE_STATEMSKn((uint32_t)1U << state);
}

/*!
 * @brief Clear the state mask bit field of EV_STATE register.
 *
 * @param base         SCTimer peripheral base address
 * @param event        The EV_STATE register be clear.
 * @param state        The state value in which the event is disabled to occur.
 */
static inline void SCTIMER_ClearEventInState(SCT_Type *base, uint32_t event, uint32_t state)
{
    assert(state < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_STATES);
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);

    base->EV[event].STATE &= ~SCT_EV_STATE_STATEMSKn((uint32_t)1U << state);
}

/*!
 * @brief Get the state mask bit field of EV_STATE register.
 *
 * @note This function is to check whether the event is enabled in a specific state.
 *
 * @param base         SCTimer peripheral base address
 * @param event        The EV_STATE register be read.
 * @param state        The state value.
 *
 * @return The the state mask bit field of EV_STATE register.
 *                      - true: The event is enable in state.
 *                      - false: The event is disable in state.
 */
static inline bool SCTIMER_GetEventInState(SCT_Type *base, uint32_t event, uint32_t state)
{
    assert(state < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_STATES);
    assert(event < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_EVENTS);

    return (0U != (base->EV[event].STATE & SCT_EV_STATE_STATEMSKn((uint32_t)1U << state)));
}

/*!
 * @brief Get the value of capture register.
 *
 * This function returns the captured value upon occurrence of the events selected by the corresponding
 * Capture Control registers occurred.
 *
 * @param base         SCTimer peripheral base address
 * @param whichCounter SCTimer counter to use. In 16-bit mode, we can select Counter_L and Counter_H,
 *                      In 32-bit mode, we can select Counter_U.
 * @param capChannel   SCTimer capture register of capture channel.
 *
 * @return The SCTimer counter value at which this register was last captured.
 */
static inline uint32_t SCTIMER_GetCaptureValue(SCT_Type *base, sctimer_counter_t whichCounter, uint8_t capChannel)
{
    uint32_t value = 0;

    switch (whichCounter)
    {
        case kSCTIMER_Counter_L:
            assert(capChannel < SCT_CAPL_COUNT);
            /* Use Counter_L bits when user wants to setup the Low counter */
            value = base->CAP_ACCESS16BIT[capChannel].CAPL;
            break;

        case kSCTIMER_Counter_H:
            assert(capChannel < SCT_CAPH_COUNT);
            /* Use Counter_H bits when user wants to start the High counter */
            value = base->CAP_ACCESS16BIT[capChannel].CAPH;
            break;

        case kSCTIMER_Counter_U:
            assert(capChannel < SCT_CAP_COUNT);
            /* Use Counter_L bits when counter is operating in 32-bit mode (unify counter). */
            value = base->CAP[capChannel];
            break;

        default:
            /* Fix the MISRA C-2012 issue rule 16.4. */
            break;
    }

    return value;
}

/*!
 * @brief SCTimer interrupt handler.
 *
 * @param base SCTimer peripheral base address.
 */
void SCTIMER_EventHandleIRQ(SCT_Type *base);

/*!
 * @brief Common IRQ handler for SCTimer, which can be used for SCTimer IRQ remapping.
 *
 * @param instance SCTimer instance number.
 */
void SCTIMER_DriverIRQHandler(uint32_t instance);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_SCTIMER_H_ */
