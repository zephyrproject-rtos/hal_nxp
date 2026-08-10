/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_FLEXPWM_H_
#define FSL_FLEXPWM_H_

#include "fsl_common.h"

/*!
 * @addtogroup flexpwm_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_FLEXPWM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0 */
/*! @} */

/* 
 * These macros abstract the difference between single-channel and dual-channel fault register layouts.
 *  - Single-channel (FSL_FEATURE_PWM_FAULT_CH_COUNT == 1): Direct global registers
 *  - Dual-channel (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1): Array of fault structures
 */
#if defined(FSL_FEATURE_PWM_FAULT_CH_COUNT) && (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1)
#define FLEXPWM_GET_FCTRL_REG(base, ch)  (&(base)->FAULT[ch].FCTRL)
#define FLEXPWM_GET_FSTS_REG(base, ch)   (&(base)->FAULT[ch].FSTS)
#define FLEXPWM_GET_FFILT_REG(base, ch)  (&(base)->FAULT[ch].FFILT)
#define FLEXPWM_GET_FCTRL2_REG(base, ch) (&(base)->FAULT[ch].FCTRL2)
#else
#define FLEXPWM_GET_FCTRL_REG(base, ch)  (&(base)->FCTRL)
#define FLEXPWM_GET_FSTS_REG(base, ch)   (&(base)->FSTS)
#define FLEXPWM_GET_FFILT_REG(base, ch)  (&(base)->FFILT)
#define FLEXPWM_GET_FCTRL2_REG(base, ch) (&(base)->FCTRL2)
#endif

/*!
 * @brief FlexPWM clock source selection
 */
typedef enum _flexpwm_clock_source
{
    kFLEXPWM_ClockSource_IPBusClock = 0U,      /*!< IPBus clock */
    kFLEXPWM_ClockSource_ExtClock = 1U,        /*!< External clock (EXT_CLK) */
    kFLEXPWM_ClockSource_Submodule0Clock = 2U, /*!< Submodule 0 auxiliary clock */
} flexpwm_clock_source_t;

/*!
 * @brief FlexPWM clock prescaler selection
 */
typedef enum _flexpwm_prescaler
{
    kFLEXPWM_Prescale_Divide_1 = 0U,   /*!< Divide by 1 */
    kFLEXPWM_Prescale_Divide_2 = 1U,   /*!< Divide by 2 */
    kFLEXPWM_Prescale_Divide_4 = 2U,   /*!< Divide by 4 */
    kFLEXPWM_Prescale_Divide_8 = 3U,   /*!< Divide by 8 */
    kFLEXPWM_Prescale_Divide_16 = 4U,  /*!< Divide by 16 */
    kFLEXPWM_Prescale_Divide_32 = 5U,  /*!< Divide by 32 */
    kFLEXPWM_Prescale_Divide_64 = 6U,  /*!< Divide by 64 */
    kFLEXPWM_Prescale_Divide_128 = 7U, /*!< Divide by 128 */
} flexpwm_prescaler_t;

/*!
 * @brief FlexPWM load mode selection
 */
typedef enum _flexpwm_load_mode
{
    kFLEXPWM_LoadMode_Opportunity = 0U, /*!< Load at PWM reload opportunity */
    kFLEXPWM_LoadMode_Immediate = 1U,   /*!< Load immediately after LDOK is set */
} flexpwm_load_mode_t;

/*!
 * @brief FlexPWM reload source selection
 */
typedef enum _flexpwm_reload_source
{
    kFLEXPWM_ReloadSource_LocalReload = 0U,  /*!< Local reload signal */
    kFLEXPWM_ReloadSource_MasterReload = 1U, /*!< Master reload signal from submodule 0 */
} flexpwm_reload_source_t;

/*!
 * @brief FlexPWM counter initialization source selection
 */
typedef enum _flexpwm_init_source
{
    kFLEXPWM_InitSource_LocalSync = 0U,    /*!< Local sync signal */
    kFLEXPWM_InitSource_MasterReload = 1U, /*!< Master reload signal from submodule 0 */
    kFLEXPWM_InitSource_MasterSync = 2U,   /*!< Master sync signal from submodule 0 */
    kFLEXPWM_InitSource_ExtSync = 3U,      /*!< External sync signal (EXT_SYNC) */
} flexpwm_init_source_t;

/*!
 * @brief FlexPWM PWM compare mode selection
 */
typedef enum _flexpwm_compare_mode
{
    kFLEXPWM_CompareMode_Equal = 0U,        /*!< Compare when counter equals compare value */
    kFLEXPWM_CompareMode_EqualGreater = 1U, /*!< Compare when counter is equal or greater than compare value */
} flexpwm_compare_mode_t;

/*!
 * @brief FlexPWM submodule mask for multi-submodule operations
 *
 * These flags can be OR'ed together to specify multiple submodules simultaneously.
 * Used with functions that operate on multiple submodules at once.
 */
typedef enum _flexpwm_submodule_mask
{
    kFLEXPWM_SubmoduleMask_0 = (1U << 0U), /*!< Submodule 0 */
    kFLEXPWM_SubmoduleMask_1 = (1U << 1U), /*!< Submodule 1 */
    kFLEXPWM_SubmoduleMask_2 = (1U << 2U), /*!< Submodule 2 */
#if defined(FSL_FEATURE_PWM_SUBMODULE_COUNT) && (FSL_FEATURE_PWM_SUBMODULE_COUNT == 4)
    kFLEXPWM_SubmoduleMask_3 = (1U << 3U), /*!< Submodule 3 */
#endif
} flexpwm_submodule_mask_t;

/*!
 * @brief FlexPWM counter configuration structure
 */
typedef struct _flexpwm_counter_config
{
    uint16_t initValue;                   /*!< Counter initial value (INIT register). */
    uint16_t modValue;                    /*!< Counter modulo value (VAL1 register).
                                               Defines the PWM period upper limit. */
    flexpwm_init_source_t initSource;     /*!< Counter initialization source selection.
                                               Determines when the counter resets to initValue. */
} flexpwm_counter_config_t;

/*!
 * @brief FlexPWM reload configuration structure
 */
typedef struct _flexpwm_reload_config
{
    flexpwm_load_mode_t loadMode;         /*!< Register load mode selection.
                                               - kFLEXPWM_LoadMode_Opportunity: Load at next reload
                                                 opportunity (PWM cycle)
                                               - kFLEXPWM_LoadMode_Immediate: Load immediately after LDOK is set */
    uint8_t loadFrequency;                /*!< Load frequency divider (LDFQ field, 0-15).
                                               Buffered registers reload every (loadFrequency + 1) PWM cycles.
                                               - 0: Every PWM cycle
                                               - 1: Every 2 PWM cycles
                                               - 15: Every 16 PWM cycles */
    bool enableHalfCycleReload;           /*!< Enable reload at half-cycle point (VAL0 match).
                                               - true: Reload can occur at VAL0 match
                                               - false: No reload at half-cycle */
    bool enableFullCycleReload;           /*!< Enable reload at full-cycle point (VAL1 match).
                                               - true: Reload can occur at VAL1 match
                                               - false: No reload at full-cycle */
    flexpwm_reload_source_t reloadSource; /*!< Reload signal source selection.
                                               - kFLEXPWM_ReloadSource_LocalReload: Use local reload
                                                 signal
                                               - kFLEXPWM_ReloadSource_MasterReload: Use master
                                                 reload from submodule 0 */
    uint16_t halfCycleValue;              /*!< Half-cycle reload point (VAL0 register).
                                               This value determines when half-cycle reload occurs.
                                               Note: Does not need to be exactly half the PWM period. */
} flexpwm_reload_config_t;

/*!
 * @brief FlexPWM submodule configuration structure
 *
 * This structure defines the basic configuration parameters for a FlexPWM submodule,
 * including clock source, prescaler, counter behavior, reload mechanism, and operating modes.
 *
 * @note This configuration writes to buffered registers. After calling FLEXPWM_ConfigSubmodule(),
 *       you must set MCTRL[LDOK] using a separate function to transfer the configuration to active registers.
 * @note This function does not start the PWM counter. Use a separate API to enable the counter.
 */
typedef struct _flexpwm_submodule_config
{
    flexpwm_clock_source_t clockSource;          /*!< Clock source for the submodule PWM counter. */
    flexpwm_prescaler_t prescaler;               /*!< Clock prescaler divider. */
    flexpwm_counter_config_t counterConfig;      /*!< Counter initialization and behavior configuration. */
    flexpwm_reload_config_t reloadConfig;        /*!< Register reload mechanism configuration. */
    bool enableDebugMode;                        /*!< PWM behavior in Debug mode.
                                                      - true: PWM continues running when MCU enters Debug mode
                                                      - false: PWM stops when MCU enters Debug mode */
#if !(defined(FSL_FEATURE_PWM_HAS_NO_WAITEN) && FSL_FEATURE_PWM_HAS_NO_WAITEN)
    bool enableWaitMode;                         /*!< PWM behavior in Wait mode.
                                                      - true: PWM continues running when MCU enters Wait mode
                                                      - false: PWM stops when MCU enters Wait mode */
#endif
} flexpwm_submodule_config_t;

/*!
 * @brief FlexPWM PWM output polarity selection
 */
typedef enum _flexpwm_pwm_polarity
{
    kFLEXPWM_Polarity_ActiveHigh = 0U, /*!< PWM signal is normal (active high) */
    kFLEXPWM_Polarity_ActiveLow = 1U,  /*!< PWM signal is inverted (active low) */
} flexpwm_pwm_polarity_t;

/*!
 * @brief FlexPWM PWM output source selection for complementary mode
 */
typedef enum _flexpwm_ipol_source
{
    kFLEXPWM_IPOL_PWM23 = 0U, /*!< Use PWM23 (PWM_A) as complementary PWM source */
    kFLEXPWM_IPOL_PWM45 = 1U, /*!< Use PWM45 (PWM_B) as complementary PWM source */
} flexpwm_ipol_source_t;

/*!
 * @brief FlexPWM PWM channel configuration structure
 *
 * This structure defines the configuration for a PWM channel pair (PWM_A or PWM_B),
 * including compare values, output polarity, and initial value.
 */
typedef struct _flexpwm_pwm_channel_config
{
    uint16_t compareValue_ON;   /*!< Compare value that defines the PWM turn-on edge
                                     (in normal polarity). Mapping per channel:
                                     - PWM_A: written to VAL2
                                     - PWM_B: written to VAL4
                                     - PWM_X: written to VAL0 */
    uint16_t compareValue_OFF;  /*!< Compare value that defines the PWM turn-off edge
                                     (in normal polarity). Mapping per channel:
                                     - PWM_A: written to VAL3
                                     - PWM_B: written to VAL5
                                     - PWM_X: written to VAL1 */
    flexpwm_pwm_polarity_t polarity; /*!< Output polarity.
                                          - kFLEXPWM_Polarity_ActiveLow: PWM signal is inverted (active low)
                                          - kFLEXPWM_Polarity_ActiveHigh: PWM signal is normal (active high) */
} flexpwm_pwm_channel_config_t;

/*!
 * @brief FlexPWM PWM configuration structure
 *
 * This structure defines the PWM output configuration for a FlexPWM submodule,
 * including compare values, polarity, and operating mode (independent or complementary).
 *
 * @note For complementary mode:
 *       Only the selected channel (specified by ipolSource) needs to be configured.
 *       The other channel will be ignored by the hardware.
 *       For example, if ipolSource = kFLEXPWM_IPOL_PWM23, only pwma will be used.
 *
 * @note For independent mode:
 *       Both pwma and pwmb must be configured separately.
 *       The ipolSource field is ignored when complementary = false.
 */
typedef struct _flexpwm_pwm_config
{
    flexpwm_pwm_channel_config_t pwma;     /*!< PWM_A (PWM23) channel configuration */
    flexpwm_pwm_channel_config_t pwmb;     /*!< PWM_B (PWM45) channel configuration */
    bool complementary;                     /*!< Operating mode.
                                               - true: Complementary mode (PWM_A and PWM_B form a complementary pair)
                                               - false: Independent mode (PWM_A and PWM_B are independent channels) */
    flexpwm_ipol_source_t ipolSource;      /*!< MCTRL[IPOL] - Select which channel pair as complementary source.
                                               Only used when complementary = true.
                                               - kFLEXPWM_IPOL_PWM23: Use PWM23 as source
                                               - kFLEXPWM_IPOL_PWM45: Use PWM45 as source */
} flexpwm_pwm_config_t;

/*!
 * @brief FlexPWM FORCE_OUT event source selection
 */
typedef enum _flexpwm_force_output_source
{
    kFLEXPWM_ForceOutputSource_LocalForce = 0U,    /*!< Local software forced event */
    kFLEXPWM_ForceOutputSource_MasterForce = 1U,   /*!< Master force signal from submodule 0 */
    kFLEXPWM_ForceOutputSource_LocalReload = 2U,   /*!< Local reload signal */
    kFLEXPWM_ForceOutputSource_MasterReload = 3U,  /*!< Master reload signal from submodule 0 */
    kFLEXPWM_ForceOutputSource_LocalSync = 4U,     /*!< Local sync signal */
    kFLEXPWM_ForceOutputSource_MasterSync = 5U,    /*!< Master sync signal from submodule 0 */
    kFLEXPWM_ForceOutputSource_ExtForce = 6U,      /*!< External force signal (EXT_FORCE) */
    kFLEXPWM_ForceOutputSource_ExtSync = 7U,       /*!< External sync signal (EXT_SYNC) */
} flexpwm_force_output_source_t;

/*!
 * @brief FlexPWM PWM source selection for deadtime logic (DTSRCSEL)
 */
typedef enum _flexpwm_force_pwm_source
{
    kFLEXPWM_ForcePwmSource_Generated = 0U,     /*!< Generated PWM signal */
    kFLEXPWM_ForcePwmSource_Inverted = 1U,      /*!< Inverted PWM signal */
    kFLEXPWM_ForcePwmSource_Software = 2U,      /*!< Software controlled output (SWCOUT) */
    kFLEXPWM_ForcePwmSource_External = 3U,      /*!< External signal */
} flexpwm_force_pwm_source_t;

/*!
 * @brief FlexPWM PWM channel force output configuration structure
 *
 * This structure defines the force output configuration for a PWM channel (PWM_A or PWM_B),
 * including the source selection and software-controlled output value.
 */
typedef struct _flexpwm_force_out_channel_config
{
    flexpwm_force_pwm_source_t source;  /*!< PWM source selection for this channel (DTSRCSEL). */
    bool softwareValue;                 /*!< When source=kFLEXPWM_ForcePwmSource_Software,
                                             this value (0 or 1) is output to deadtime logic (SWCOUT). */
} flexpwm_force_out_channel_config_t;

/*!
 * @brief FlexPWM force output configuration structure
 *
 * This structure defines the force output (FORCE_OUT event) configuration for a FlexPWM submodule,
 * including the trigger source, PWM logical initial value, and PWM source selection.
 */
typedef struct _flexpwm_force_out_config
{
    flexpwm_force_output_source_t forceSource;  /*!< FORCE_OUT trigger source (CTRL2[FORCE_SEL]). */
    flexpwm_force_out_channel_config_t pwma;    /*!< PWM_A (PWM23) force output configuration. */
    flexpwm_force_out_channel_config_t pwmb;    /*!< PWM_B (PWM45) force output configuration. */
    bool pwma_initialValue;                     /*!< PWM_A (PWM23) logical initial value in normal polarity.
                                                     - true: PWM_A output starts at logic 1
                                                     - false: PWM_A output starts at logic 0 */
    bool pwmb_initialValue;                     /*!< PWM_B (PWM45) logical initial value in normal polarity.
                                                     - true: PWM_B output starts at logic 1
                                                     - false: PWM_B output starts at logic 0 */
    bool pwmx_initialValue;                     /*!< PWM_X logical initial value in normal polarity.
                                                     - true: PWM_X output starts at logic 1
                                                     - false: PWM_X output starts at logic 0 */
} flexpwm_force_out_config_t;

/*!
 * @brief FlexPWM fault output behavior during fault condition
 *
 * Defines how PWM outputs respond when a fault is detected.
 * Values map directly to SMxOCTRL[PWMAFS/PWMBFS/PWMXFS] bitfields.
 */
typedef enum _flexpwm_fault_output_behavior
{
    kFLEXPWM_FaultOutput_Force0 = 0U,   /*!< 0b00 - Force output to logic 0 */
    kFLEXPWM_FaultOutput_Force1 = 1U,   /*!< 0b01 - Force output to logic 1 */
    kFLEXPWM_FaultOutput_HighZ = 2U,    /*!< 0b10/0b11 - High impedance (3-state) output */
} flexpwm_fault_output_behavior_t;

/*!
 * @brief FlexPWM fault input mask for fault protection configuration
 *
 * These flags can be OR'ed together to configure multiple fault inputs simultaneously
 * with the same protection parameters.
 * Used with FLEXPWM_ConfigFaultProtection() function.
 *
 * @note For dual-channel platforms (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1):
 *       - When faultChannel = 0: Use kFLEXPWM_FaultMask_0/1/2/3 for FAULT0-3
 *       - When faultChannel = 1: Use kFLEXPWM_FaultMask_0/1/2/3 for FAULT4-7
 *       The enum values are the same, but the channel parameter determines which
 *       physical fault inputs are configured.
 */
typedef enum _flexpwm_fault_mask
{
    kFLEXPWM_FaultMask_0 = (1U << 0U), /*!< FAULT0 (ch0) or FAULT4 (ch1) */
    kFLEXPWM_FaultMask_1 = (1U << 1U), /*!< FAULT1 (ch0) or FAULT5 (ch1) */
    kFLEXPWM_FaultMask_2 = (1U << 2U), /*!< FAULT2 (ch0) or FAULT6 (ch1) */
    kFLEXPWM_FaultMask_3 = (1U << 3U), /*!< FAULT3 (ch0) or FAULT7 (ch1) */
} flexpwm_fault_mask_t;

/*!
 * @brief FlexPWM fault output configuration structure
 *
 * Configures fault protection for a single PWM output (PWM_A, PWM_B, or PWM_X).
 * Supports both single-channel (FAULT0-3 only) and dual-channel (FAULT0-3 and FAULT4-7)
 * platforms via conditional compilation.
 * Can use flexpwm_fault_mask_t enum values (kFLEXPWM_FaultMask_0/1/2/3) and OR them together
 * for multiple faults.
 */
typedef struct _flexpwm_fault_output_config
{
    uint16_t disableMask_ch0; /*!< Fault disable mask for channel 0 (FAULT0-3).
                                   Each bit selects one fault input:
                                   - bit[0] = FAULT0
                                   - bit[1] = FAULT1
                                   - bit[2] = FAULT2
                                   - bit[3] = FAULT3
                                   Maps to SMxDISMAP[0] register. */
#if defined(FSL_FEATURE_PWM_FAULT_CH_COUNT) && (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1)
    uint16_t disableMask_ch1; /*!< Fault disable mask for channel 1 (FAULT4-7).
                                   Each bit selects one fault input:
                                   - bit[0] = FAULT4
                                   - bit[1] = FAULT5
                                   - bit[2] = FAULT6
                                   - bit[3] = FAULT7
                                   Maps to SMxDISMAP[1] register. */
#endif
    flexpwm_fault_output_behavior_t outputBehavior;  /*!< Output behavior when fault is detected
                                                           Maps to SMxOCTRL[PWMAFS/PWMBFS/PWMXFS]. */
} flexpwm_fault_output_config_t;

/*!
 * @brief FlexPWM fault submodule configuration structure
 *
 * Configures fault protection for all three PWM outputs (PWM_A, PWM_B, PWM_X)
 * of a FlexPWM submodule. Includes fault disable mapping and output behavior
 * for each output.
 */
typedef struct _flexpwm_fault_submodule_config
{
    flexpwm_fault_output_config_t pwma;  /*!< PWM_A (PWM23) fault configuration.
                                               Controls which faults disable PWM_A output
                                               and how PWM_A behaves during fault. */
    flexpwm_fault_output_config_t pwmb;  /*!< PWM_B (PWM45) fault configuration.
                                               Controls which faults disable PWM_B output
                                               and how PWM_B behaves during fault. */
    flexpwm_fault_output_config_t pwmx;  /*!< PWM_X fault configuration.
                                               Controls which faults disable PWM_X output
                                               and how PWM_X behaves during fault. */
} flexpwm_fault_submodule_config_t;

/*!
 * @brief FlexPWM fault clearing mode selection
 *
 * Defines how fault conditions are cleared after a fault event.
 */
typedef enum _flexpwm_fault_clearing_mode
{
    kFLEXPWM_FaultClearingMode_Manual = 0U,      /*!< Manual clearing - software must clear FSTS[FFLAGx] */
    kFLEXPWM_FaultClearingMode_Automatic = 1U,   /*!< Automatic clearing when FAULTx de-asserts */
} flexpwm_fault_clearing_mode_t;

/*!
 * @brief FlexPWM fault protection configuration structure
 *
 * Configures global fault protection parameters for one fault channel.
 * These settings apply to all submodules and their outputs that reference this channel.
 * For platforms with dual fault channels (FAULT0-3 and FAULT4-7), configure each
 * channel separately using FLEXPWM_ConfigFaultProtection().
 */
typedef struct _flexpwm_fault_config
{
    bool faultInputActiveLevel;  /*!< FAULTx input active level (FCTRL[FLVL])
                                      - false: Logic 0 on FAULTx indicates fault (active low)
                                      - true: Logic 1 on FAULTx indicates fault (active high) */

    flexpwm_fault_clearing_mode_t faultClearingMode; /*!< Fault clearing mode (FCTRL[FAUTO]) */

    bool enableSafetyMode;       /*!< Safety Mode (FCTRL[FSAFE])
                                      Only useful for Manual fault clearing mode
                                      - false: Normal mode (PWM outputs enabled when FFLAG clears)
                                      - true: Safe mode (PWM outputs enabled only when both FFLAG
                                               and FFPIN are clear) */
    bool enableFullCycleRecovery; /*!< Full Cycle Recovery (FSTS[FFULL])
                                      - true: PWM outputs can be re-enabled at PWM full cycle start
                                      - false: No re-enable at full cycle */
    bool enableHalfCycleRecovery; /*!< Half Cycle Recovery (FSTS[FHALF])
                                      - true: PWM outputs can be re-enabled at PWM half cycle start
                                      - false: No re-enable at half cycle */
    bool enableCombinatorialPath; /*!< Combinational Path Control (FCTRL2[NOCOMB])
                                      - true: Combinational path active - fault input directly
                                              disables PWM outputs (fastest response)
                                      - false: Combinational path disabled - only latched fault
                                               signal disables PWM outputs (adds latency) */
} flexpwm_fault_config_t;

/*!
 * @brief FlexPWM fault filter configuration structure
 *
 * Configures input filter for fault protection pins to debounce electrical noise.
 * The filter requires the input signal to be stable for N consecutive samples
 * (where each sample is taken every T IPBus clock cycles) before reporting a fault.
 * Helps avoid false fault triggers from noise on FAULTx pins.
 */
typedef struct _flexpwm_fault_filter_config
{
    uint8_t filterPeriod;        /*!< Fault Filter Period (FFILT[FILT_PER])
                                      Sampling period in IPBus clock cycles.
                                      Range: 0-255
                                      - 0: Input filter bypassed
                                      - N: FAULTx sampled every N IPBus cycles */
    uint8_t filterCount;         /*!< Fault Filter Count (FFILT[FILT_CNT])
                                      Number of consecutive stable samples required
                                      to accept input transition.
                                      Range: 0-7 (actual samples = value + 3)
                                      - 0: 3 samples
                                      - 1: 4 samples
                                      - 7: 10 samples */
    bool enableGlitchStretch;    /*!< Fault Glitch Stretching (FFILT[GSTR])
                                      - false: Glitch stretching disabled
                                      - true: Input fault signals stretched to min 2 IPBus cycles
                                              Prevents false triggers from narrow glitches */
} flexpwm_fault_filter_config_t;

/*!
 * @brief FlexPWM write protection mode selection
 */
typedef enum _flexpwm_write_protect
{
    kFLEXPWM_WriteProtect_Off = 0U,        /*!< Write protection off (default) */
    kFLEXPWM_WriteProtect_On = 1U,         /*!< Write protection on */
    kFLEXPWM_WriteProtect_OffLocked = 2U,  /*!< Write protection off and locked until chip reset */
    kFLEXPWM_WriteProtect_OnLocked = 3U,   /*!< Write protection on and locked until chip reset */
} flexpwm_write_protect_t;

/*!
 * @brief FlexPWM trigger signal stretch prescaler selection
 *
 * Stretch IPBus clock count prescaler for trigger signals including:
 * mux0_trig, mux1_trig, out0_trig, out1_trig, pwma_trig, pwmb_trig
 */
typedef enum _flexpwm_stretch_prescaler
{
    kFLEXPWM_StretchPrescaler_None = 0U,      /*!< No stretch */
    kFLEXPWM_StretchPrescaler_2Clocks = 1U,   /*!< Stretch for 2 IPBus clock periods */
    kFLEXPWM_StretchPrescaler_4Clocks = 2U,   /*!< Stretch for 4 IPBus clock periods */
    kFLEXPWM_StretchPrescaler_8Clocks = 3U,   /*!< Stretch for 8 IPBus clock periods */
} flexpwm_stretch_prescaler_t;

/*!
 * @brief FlexPWM output trigger source selection for PWM_MUX_TRIG0/1 ports
 *
 * Selects which signal is routed to the PWM_MUX_TRIG0/1 output ports.
 */
typedef enum _flexpwm_trigger_mux_source
{
    kFLEXPWM_TriggerMuxSource_GeneratedTrigger = 0U, /*!< Use PWM_OUT_TRIG0/1 (generated trigger signal) */
    kFLEXPWM_TriggerMuxSource_PWMOutput = 1U,        /*!< Use PWM_A/PWM_B output directly */
} flexpwm_trigger_mux_source_t;

/*!
 * @brief FlexPWM output trigger frequency selection
 *
 * Controls the trigger output frequency when CTRL[LDFQ] is non-zero.
 * Only takes effect when reload frequency divider is active (LDFQ > 0).
 */
typedef enum _flexpwm_trigger_frequency
{
    kFLEXPWM_TriggerFrequency_EveryCycle = 0U,  /*!< Trigger every PWM cycle even if reload doesn't occur */
    kFLEXPWM_TriggerFrequency_OnReload = 1U,    /*!< Trigger only on last cycle before reload opportunity */
} flexpwm_trigger_frequency_t;

/*!
 * @brief FlexPWM output trigger enable mask
 *
 * These flags can be OR'ed together to enable multiple trigger sources simultaneously.
 * Used with outTriggerEnable field in flexpwm_output_trigger_config_t structure.
 */
typedef enum _flexpwm_output_trigger_mask
{
    kFLEXPWM_OutputTriggerMask_VAL0 = (1U << 0U), /*!< VAL0 match triggers PWM_OUT_TRIG0 */
    kFLEXPWM_OutputTriggerMask_VAL1 = (1U << 1U), /*!< VAL1 match triggers PWM_OUT_TRIG1 */
    kFLEXPWM_OutputTriggerMask_VAL2 = (1U << 2U), /*!< VAL2 match triggers PWM_OUT_TRIG0 */
    kFLEXPWM_OutputTriggerMask_VAL3 = (1U << 3U), /*!< VAL3 match triggers PWM_OUT_TRIG1 */
    kFLEXPWM_OutputTriggerMask_VAL4 = (1U << 4U), /*!< VAL4 match triggers PWM_OUT_TRIG0 */
    kFLEXPWM_OutputTriggerMask_VAL5 = (1U << 5U), /*!< VAL5 match triggers PWM_OUT_TRIG1 */
} flexpwm_output_trigger_mask_t;

/*!
 * @brief FlexPWM output trigger configuration structure
 *
 * This structure defines the output trigger configuration for a FlexPWM submodule,
 * including trigger source mapping from VAL registers, trigger frequency control,
 * and output port routing.
 *
 * @note outTriggerEnable is a 6-bit mask corresponding to OUT_TRIG_EN[5:0], where each bit
 *       enables a trigger source from VAL0-5 register matches:
 *       - bit[0]: VAL0 match triggers PWM_OUT_TRIG0
 *       - bit[1]: VAL1 match triggers PWM_OUT_TRIG1
 *       - bit[2]: VAL2 match triggers PWM_OUT_TRIG0
 *       - bit[3]: VAL3 match triggers PWM_OUT_TRIG1
 *       - bit[4]: VAL4 match triggers PWM_OUT_TRIG0
 *       - bit[5]: VAL5 match triggers PWM_OUT_TRIG1
 *       Multiple bits can be set to combine trigger sources (OR logic).
 *
 * @note triggerFrequency only takes effect when CTRL[LDFQ] is non-zero.
 *       - false: Triggers output every PWM cycle even if reload doesn't occur
 *       - true: Triggers output only on the last PWM cycle before a reload opportunity
 */
typedef struct _flexpwm_output_trigger_config
{
    uint16_t outTriggerEnable;                        /*!< Output trigger enable mask (OUT_TRIG_EN[5:0]).
                                                           Bit mask for VAL0-5 trigger sources.
                                                           OR'ed combination of flexpwm_output_trigger_mask_t
                                                           Example: 0x05 enables VAL0 and VAL2 for TRIG0. */
    flexpwm_trigger_mux_source_t muxTrig0Source;      /*!< PWM_MUX_TRIG0 port source selection (PWAOT0).
                                                           - kFLEXPWM_TriggerMuxSource_GeneratedTrigger:
                                                             Route PWM_OUT_TRIG0 signal
                                                           - kFLEXPWM_TriggerMuxSource_PWMOutput:
                                                             Route PWM_A output directly */
    flexpwm_trigger_mux_source_t muxTrig1Source;      /*!< PWM_MUX_TRIG1 port source selection (PWBOT1).
                                                           - kFLEXPWM_TriggerMuxSource_GeneratedTrigger:
                                                             Route PWM_OUT_TRIG1 signal
                                                           - kFLEXPWM_TriggerMuxSource_PWMOutput:
                                                             Route PWM_B output directly */
    flexpwm_trigger_frequency_t triggerFrequency;     /*!< Trigger frequency control (TRGFRQ).
                                                           Controls trigger output frequency when CTRL[LDFQ] > 0.
                                                           - kFLEXPWM_TriggerFrequency_EveryCycle:
                                                             Trigger every PWM cycle
                                                           - kFLEXPWM_TriggerFrequency_OnReload:
                                                             Trigger only on last cycle before reload */
#if (defined(FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD) &&   \
             FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD)
    flexpwm_stretch_prescaler_t stretchPrescaler;     /*!< Trigger signal stretch prescaler (MCTRL2[STRETCH_CNT_PRSC]).
                                                           Stretches trigger signal pulse width by specified IPBus
                                                           clock cycles. */
#endif
} flexpwm_output_trigger_config_t;

/*!
 * @brief FlexPWM input capture edge selection
 *
 * This enumeration defines the edge detection modes for input capture.
 * The enum values directly map to hardware register bit values.
 */
typedef enum _flexpwm_capture_edge
{
    kFLEXPWM_CaptureEdge_Disabled = 0U,  /*!< Disable capture (register bit value: 00b) */
    kFLEXPWM_CaptureEdge_Falling = 1U,   /*!< Capture on falling edge (register bit value: 01b) */
    kFLEXPWM_CaptureEdge_Rising = 2U,    /*!< Capture on rising edge (register bit value: 10b) */
    kFLEXPWM_CaptureEdge_Both = 3U,      /*!< Capture on any edge (register bit value: 11b) */
} flexpwm_capture_edge_t;

/*!
 * @brief FlexPWM capture FIFO watermark selection
 *
 * This enumeration defines the FIFO watermark levels that determine when
 * a watermark interrupt is triggered based on the number of valid samples in the FIFO.
 */
typedef enum _flexpwm_capture_fifo_watermark
{
    kFLEXPWM_CaptureFifoWatermark_1 = 0U,  /*!< Trigger when FIFO has 1 or more samples (00b) */
    kFLEXPWM_CaptureFifoWatermark_2 = 1U,  /*!< Trigger when FIFO has 2 or more samples (01b) */
    kFLEXPWM_CaptureFifoWatermark_3 = 2U,  /*!< Trigger when FIFO has 3 or more samples (10b) */
    kFLEXPWM_CaptureFifoWatermark_4 = 3U,  /*!< Trigger when FIFO is full with 4 samples (11b) */
} flexpwm_capture_fifo_watermark_t;

/*!
 * @brief FlexPWM capture input source selection
 *
 * This enumeration selects the source signal for input capture.
 */
typedef enum _flexpwm_capture_input_select
{
    kFLEXPWM_CaptureInput_RawSignal = 0U,     /*!< Use raw PWM input signal (register bit value: 0) */
    kFLEXPWM_CaptureInput_EdgeCounter = 1U,   /*!< Use edge counter output (register bit value: 1).
                                                   Used to reduce capture frequency by counting N edges */
} flexpwm_capture_input_select_t;

/*!
 * @brief FlexPWM capture value index
 *
 * This enumeration defines the index for accessing capture value registers (CVAL0-5).
 * 
 * @note Capture channel to CVAL register mapping (non-intuitive hardware mapping):
 *       - Capture_X Edge0/Edge1 -> CVAL0/CVAL1 (and CVAL0CYC/CVAL1CYC)
 *       - Capture_A Edge0/Edge1 -> CVAL2/CVAL3 (and CVAL2CYC/CVAL3CYC)
 *       - Capture_B Edge0/Edge1 -> CVAL4/CVAL5 (and CVAL4CYC/CVAL5CYC)
 */
typedef enum _flexpwm_capture_index
{
    kFLEXPWM_Capture_X_Edge0 = 0U,  /*!< CVAL0 - Capture_X Edge0 */
    kFLEXPWM_Capture_X_Edge1 = 1U,  /*!< CVAL1 - Capture_X Edge1 */
    kFLEXPWM_Capture_A_Edge0 = 2U,  /*!< CVAL2 - Capture_A Edge0 */
    kFLEXPWM_Capture_A_Edge1 = 3U,  /*!< CVAL3 - Capture_A Edge1 */
    kFLEXPWM_Capture_B_Edge0 = 4U,  /*!< CVAL4 - Capture_B Edge0 */
    kFLEXPWM_Capture_B_Edge1 = 5U,  /*!< CVAL5 - Capture_B Edge1 */
} flexpwm_capture_index_t;

/*!
 * @brief FlexPWM capture channel selection
 *
 * This enumeration defines the capture channel for enable/disable operations.
 */
typedef enum _flexpwm_capture_channel
{
    kFLEXPWM_Capture_A = 0U,  /*!< Capture channel A (PWM_A) */
    kFLEXPWM_Capture_B = 1U,  /*!< Capture channel B (PWM_B) */
    kFLEXPWM_Capture_X = 2U,  /*!< Capture channel X (PWM_X) */
} flexpwm_capture_channel_t;

/*!
 * @brief FlexPWM single capture channel configuration structure
 *
 * This structure defines the configuration parameters for a single input capture channel.
 */
typedef struct _flexpwm_capture_channel_config
{
    flexpwm_capture_edge_t edge0;                 /*!< Edge0 capture edge selection */
    flexpwm_capture_edge_t edge1;                 /*!< Edge1 capture edge selection */
    bool oneshot;                                  /*!< Capture mode.
                                                       - true: One-shot mode
                                                       - false: Free-running mode */
    flexpwm_capture_input_select_t inputSelect;   /*!< Input signal source selection.
                                                       - kFLEXPWM_CaptureInput_RawSignal: Raw PWM input
                                                       - kFLEXPWM_CaptureInput_EdgeCounter: Edge counter output */
    bool enableEdgeCounter;                        /*!< Edge counter enable control.
                                                       - true: Enable edge counter (EDGCNT_EN = 1)
                                                       - false: Disable edge counter (EDGCNT_EN = 0) */
    uint8_t edgeCompareValue;                      /*!< Edge counter compare value (0-255).
                                                       Capture occurs when edge count reaches this value.
                                                       Only valid when enableEdgeCounter = true */
    flexpwm_capture_fifo_watermark_t fifoWatermark; /*!< FIFO watermark level */
} flexpwm_capture_channel_config_t;

/*!
 * @brief FlexPWM input capture configuration structure
 *
 * This structure contains the configuration for three independent input capture channels.
 * Users can configure only the channels they need; unused channels should be left at default values.
 *
 * @note Capture channel to CVAL/CVALxCYC register mapping (important for reading capture values):
 *       - captureA -> CVAL2/CVAL3 (CVAL2CYC/CVAL3CYC)
 *       - captureB -> CVAL4/CVAL5 (CVAL4CYC/CVAL5CYC)
 *       - captureX -> CVAL0/CVAL1 (CVAL0CYC/CVAL1CYC)
 */
typedef struct _flexpwm_input_capture_config
{
    flexpwm_capture_channel_config_t captureA;  /*!< Capture_A (PWM_A) channel configuration */
    flexpwm_capture_channel_config_t captureB;  /*!< Capture_B (PWM_B) channel configuration */
    flexpwm_capture_channel_config_t captureX;  /*!< Capture_X (PWM_X) channel configuration */
} flexpwm_input_capture_config_t;

/*!
 * @brief FlexPWM capture filter channel configuration structure
 *
 * This structure defines the digital filter parameters for a single capture input pin.
 */
typedef struct _flexpwm_capture_filter_channel_config
{
    uint8_t filterPeriod;  /*!< Filter sampling period in IPBus clock cycles (0-255).
                                - 0: Bypass filter (default)
                                - Non-zero: Enable filter with specified sampling period */
    uint8_t filterCount;   /*!< Number of consecutive consistent samples required (0-7).
                                Actual sample count = filterCount + 3 (i.e., 3-10 samples) */
} flexpwm_capture_filter_channel_config_t;

#if (defined(FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE) && FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE)
/*!
 * @brief FlexPWM input capture filter configuration structure
 *
 * This structure contains the filter configuration for three independent capture input pins.
 *
 * @note Capture filter to register mapping:
 *       - captureA -> SMxCAPTFILTA register
 *       - captureB -> SMxCAPTFILTB register
 *       - captureX -> SMxCAPTFILTX register
 */
typedef struct _flexpwm_capture_filter_config
{
    flexpwm_capture_filter_channel_config_t captureA;  /*!< Capture_A filter configuration */
    flexpwm_capture_filter_channel_config_t captureB;  /*!< Capture_B filter configuration */
    flexpwm_capture_filter_channel_config_t captureX;  /*!< Capture_X filter configuration */
} flexpwm_capture_filter_config_t;
#endif

/*!
 * @brief FlexPWM submodule interrupt enable flags
 *
 * These flags can be OR'ed together to enable multiple interrupt sources simultaneously.
 * Use with FLEXPWM_EnableSubmoduleInterrupts() and FLEXPWM_DisableSubmoduleInterrupts().
 */
enum _flexpwm_submodule_interrupt_enable
{
    kFLEXPWM_Compare0InterruptEnable    = (PWM_INTEN_CMPIE(1U << 0U)),      /*!< VAL0 compare interrupt */
    kFLEXPWM_Compare1InterruptEnable    = (PWM_INTEN_CMPIE(1U << 1U)),      /*!< VAL1 compare interrupt */
    kFLEXPWM_Compare2InterruptEnable    = (PWM_INTEN_CMPIE(1U << 2U)),      /*!< VAL2 compare interrupt */
    kFLEXPWM_Compare3InterruptEnable    = (PWM_INTEN_CMPIE(1U << 3U)),      /*!< VAL3 compare interrupt */
    kFLEXPWM_Compare4InterruptEnable    = (PWM_INTEN_CMPIE(1U << 4U)),      /*!< VAL4 compare interrupt */
    kFLEXPWM_Compare5InterruptEnable    = (PWM_INTEN_CMPIE(1U << 5U)),      /*!< VAL5 compare interrupt */
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
    kFLEXPWM_CaptureX0InterruptEnable   = PWM_INTEN_CX0IE_MASK,             /*!< Capture X0 interrupt */
    kFLEXPWM_CaptureX1InterruptEnable   = PWM_INTEN_CX1IE_MASK,             /*!< Capture X1 interrupt */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
    kFLEXPWM_CaptureB0InterruptEnable   = PWM_INTEN_CB0IE_MASK,             /*!< Capture B0 interrupt */
    kFLEXPWM_CaptureB1InterruptEnable   = PWM_INTEN_CB1IE_MASK,             /*!< Capture B1 interrupt */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
    kFLEXPWM_CaptureA0InterruptEnable   = PWM_INTEN_CA0IE_MASK,             /*!< Capture A0 interrupt */
    kFLEXPWM_CaptureA1InterruptEnable   = PWM_INTEN_CA1IE_MASK,             /*!< Capture A1 interrupt */
#endif
    kFLEXPWM_ReloadInterruptEnable      = PWM_INTEN_RIE_MASK,               /*!< Reload interrupt */
    kFLEXPWM_ReloadErrorInterruptEnable = PWM_INTEN_REIE_MASK,              /*!< Reload error interrupt */
};

/*!
 * @brief FlexPWM submodule status flags
 *
 * These flags represent the status of various events in a FlexPWM submodule.
 * Use with FLEXPWM_GetSubmoduleStatusFlags() and FLEXPWM_ClearSubmoduleStatusFlags().
 *
 * @note kFLEXPWM_RegisterUpdatedFlag is read-only and cannot be cleared by software.
 */
enum _flexpwm_submodule_status_flag
{
    kFLEXPWM_Compare0Flag          = (PWM_STS_CMPF(1U << 0U)),      /*!< VAL0 compare flag */
    kFLEXPWM_Compare1Flag          = (PWM_STS_CMPF(1U << 1U)),      /*!< VAL1 compare flag */
    kFLEXPWM_Compare2Flag          = (PWM_STS_CMPF(1U << 2U)),      /*!< VAL2 compare flag */
    kFLEXPWM_Compare3Flag          = (PWM_STS_CMPF(1U << 3U)),      /*!< VAL3 compare flag */
    kFLEXPWM_Compare4Flag          = (PWM_STS_CMPF(1U << 4U)),      /*!< VAL4 compare flag */
    kFLEXPWM_Compare5Flag          = (PWM_STS_CMPF(1U << 5U)),      /*!< VAL5 compare flag */
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
    kFLEXPWM_CaptureX0Flag         = PWM_STS_CFX0_MASK,             /*!< Capture X0 flag */
    kFLEXPWM_CaptureX1Flag         = PWM_STS_CFX1_MASK,             /*!< Capture X1 flag */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
    kFLEXPWM_CaptureB0Flag         = PWM_STS_CFB0_MASK,             /*!< Capture B0 flag */
    kFLEXPWM_CaptureB1Flag         = PWM_STS_CFB1_MASK,             /*!< Capture B1 flag */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
    kFLEXPWM_CaptureA0Flag         = PWM_STS_CFA0_MASK,             /*!< Capture A0 flag */
    kFLEXPWM_CaptureA1Flag         = PWM_STS_CFA1_MASK,             /*!< Capture A1 flag */
#endif
    kFLEXPWM_ReloadFlag            = PWM_STS_RF_MASK,               /*!< Reload flag */
    kFLEXPWM_ReloadErrorFlag       = PWM_STS_REF_MASK,              /*!< Reload error flag */
    kFLEXPWM_RegisterUpdatedFlag   = PWM_STS_RUF_MASK,              /*!< Register updated flag (read-only) */
};

/*!
 * @brief FlexPWM fault interrupt enable flags
 *
 * These flags can be OR'ed together to enable multiple fault interrupt sources.
 * Use with FLEXPWM_EnableFaultInterrupts() and FLEXPWM_DisableFaultInterrupts().
 *
 * @note For dual-channel platforms (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1):
 *       The same bit mask values are used for both fault channels:
 *       - faultChannel = 0: Controls FAULT0-3
 *       - faultChannel = 1: Controls FAULT4-7
 *       The bit positions are the same, but the function parameter determines which
 *       fault channel is configured.
 */
enum _flexpwm_fault_interrupt_enable
{
    kFLEXPWM_Fault0InterruptEnable = (PWM_FCTRL_FIE(1U << 0U)), /*!< FAULT0 (ch0) or FAULT4 (ch1) interrupt */
    kFLEXPWM_Fault1InterruptEnable = (PWM_FCTRL_FIE(1U << 1U)), /*!< FAULT1 (ch0) or FAULT5 (ch1) interrupt */
    kFLEXPWM_Fault2InterruptEnable = (PWM_FCTRL_FIE(1U << 2U)), /*!< FAULT2 (ch0) or FAULT6 (ch1) interrupt */
    kFLEXPWM_Fault3InterruptEnable = (PWM_FCTRL_FIE(1U << 3U)), /*!< FAULT3 (ch0) or FAULT7 (ch1) interrupt */
};

/*!
 * @brief FlexPWM fault status flags (FFLAG)
 *
 * These flags represent the latched fault status (FFLAG bits in FSTS register).
 * Use with FLEXPWM_GetFaultStatusFlags() and FLEXPWM_ClearFaultStatusFlags().
 *
 * @note FFLAG characteristics:
 *       - Write-1-to-clear: Software must write 1 to clear each flag
 *       - Latched event: Set within 2 CPU cycles after FAULTx pin transitions to active state
 *       - Historical record: Indicates a fault event has occurred (not current pin state)
 *       - Interrupt capable: Can generate CPU interrupt requests when enabled
 *       - Manual clearing: Does not auto-clear; requires explicit software action
 *
 * @note To check the real-time, filtered hardware pin status (not the latched event),
 *       use FLEXPWM_GetFaultFilteredPinStatusFlags() to read FFPIN instead.
 *
 * @note For dual-channel platforms: The same bit mask values apply to both channels.
 *       - faultChannel = 0: FAULT0-3 flags
 *       - faultChannel = 1: FAULT4-7 flags
 */
enum _flexpwm_fault_status_flag
{
    kFLEXPWM_Fault0Flag = (PWM_FSTS_FFLAG(1U << 0U)),   /*!< FAULT0 (ch0) or FAULT4 (ch1) flag */
    kFLEXPWM_Fault1Flag = (PWM_FSTS_FFLAG(1U << 1U)),   /*!< FAULT1 (ch0) or FAULT5 (ch1) flag */
    kFLEXPWM_Fault2Flag = (PWM_FSTS_FFLAG(1U << 2U)),   /*!< FAULT2 (ch0) or FAULT6 (ch1) flag */
    kFLEXPWM_Fault3Flag = (PWM_FSTS_FFLAG(1U << 3U)),   /*!< FAULT3 (ch0) or FAULT7 (ch1) flag */
};

/*!
 * @brief FlexPWM filtered fault pin status (FFPIN - read-only)
 *
 * These flags represent the real-time status of fault pins after filtering (FFPIN bits in FSTS register).
 * Use with FLEXPWM_GetFaultFilteredPinStatusFlags() to check if external fault signals
 * are currently active.
 *
 * @note FFPIN characteristics:
 *       - Read-only: Cannot be written or cleared by software
 *       - Real-time status: Reflects current state of filtered FAULTx pin (not historical)
 *       - Polarity converted: Always shows active-high logic (1 = fault present)
 *       - Filter output: Shows fault filter output, not raw pin state
 *       - No interrupt: Does not directly generate interrupts (use FFLAG for interrupts)
 *       - Filter delay: May remain high briefly after raw pin clears due to filter latency
 *
 * @note Key differences from FFLAG:
 *       - FFLAG: Software-clearable latched flag (historical event - "a fault occurred")
 *       - FFPIN: Read-only real-time status (current state - "fault is active now")
 *
 * @note For dual-channel platforms: The same bit positions apply to both channels.
 *       - faultChannel = 0: FAULT0-3 pin status
 *       - faultChannel = 1: FAULT4-7 pin status
 */
enum _flexpwm_fault_pin_status
{
    kFLEXPWM_Fault0PinActive = (PWM_FSTS_FFPIN(1U << 0U)),  /*!< FAULT0/4 pin active (filtered) */
    kFLEXPWM_Fault1PinActive = (PWM_FSTS_FFPIN(1U << 1U)),  /*!< FAULT1/5 pin active (filtered) */
    kFLEXPWM_Fault2PinActive = (PWM_FSTS_FFPIN(1U << 2U)),  /*!< FAULT2/6 pin active (filtered) */
    kFLEXPWM_Fault3PinActive = (PWM_FSTS_FFPIN(1U << 3U)),  /*!< FAULT3/7 pin active (filtered) */
};

/*!
 * @brief FlexPWM DMA capture source selection
 *
 * This enumeration defines the trigger source for DMA read requests from capture FIFOs.
 */
typedef enum _flexpwm_dma_capture_source
{
    kFLEXPWM_DMADisable = 0U,           /*!< Read DMA requests disabled */
    kFLEXPWM_DMAFIFOWatermark = 1U,     /*!< Exceeding FIFO watermark sets read DMA request */
    kFLEXPWM_DMALocalSync = 2U,         /*!< Local sync sets read DMA request */
    kFLEXPWM_DMALocalReload = 3U        /*!< Local reload sets read DMA request */
} flexpwm_dma_capture_source_t;

/*!
 * @brief FlexPWM DMA enable flags
 *
 * These flags are used with FLEXPWM_EnableDMA() and FLEXPWM_DisableDMA()
 * to control individual DMA channel enables. Multiple flags can be ORed together.
 */
enum _flexpwm_dma_enable
{
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
    kFLEXPWM_DMA_CaptureX0Enable = PWM_DMAEN_CX0DE_MASK,  /*!< Capture X0 FIFO DMA enable (CX0DE) */
    kFLEXPWM_DMA_CaptureX1Enable = PWM_DMAEN_CX1DE_MASK,  /*!< Capture X1 FIFO DMA enable (CX1DE) */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
    kFLEXPWM_DMA_CaptureB0Enable = PWM_DMAEN_CB0DE_MASK,  /*!< Capture B0 FIFO DMA enable (CB0DE) */
    kFLEXPWM_DMA_CaptureB1Enable = PWM_DMAEN_CB1DE_MASK,  /*!< Capture B1 FIFO DMA enable (CB1DE) */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
    kFLEXPWM_DMA_CaptureA0Enable = PWM_DMAEN_CA0DE_MASK,  /*!< Capture A0 FIFO DMA enable (CA0DE) */
    kFLEXPWM_DMA_CaptureA1Enable = PWM_DMAEN_CA1DE_MASK,  /*!< Capture A1 FIFO DMA enable (CA1DE) */
#endif
    kFLEXPWM_DMA_ValueWriteEnable = PWM_DMAEN_VALDE_MASK, /*!< Value registers DMA write enable (VALDE) */
};

/*!
 * @brief FlexPWM DMA configuration structure
 *
 * This structure holds the DMA control strategy configuration.
 * These settings should be configured during initialization and
 * typically do not need to be modified at runtime.
 */
typedef struct _flexpwm_dma_config
{
    flexpwm_dma_capture_source_t captureSource; /*!< Capture DMA enable source selection (CAPTDE[7:6]) */
    bool fifoWatermarkAND;                      /*!< FIFO watermark AND/OR control (FAND).
                                                     - true: Selected FIFO watermarks are ANDed
                                                     - false: Selected FIFO watermarks are ORed */
} flexpwm_dma_config_t;


/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Get the instance for FlexPWM module.
 *
 * @param base FlexPWM base address
 * @return Instance number if valid base address is provided, otherwise returns ARRAY_SIZE(s_flexpwmBases)
 */
uint32_t FLEXPWM_GetInstance(PWM_Type *base);

/*!
 * @brief Initialize the FlexPWM module.
 *
 * This function initializes the FlexPWM peripheral by:
 * - Enabling clocks for all submodules (SM0-SM3)
 * - Releasing peripheral reset (if supported by platform)
 *
 * After calling this function, the FlexPWM module is ready for configuration.
 * Additional configuration functions (FLEXPWM_ConfigSubmodule, FLEXPWM_ConfigPWM, etc.)
 * should be called to set up the desired PWM behavior.
 *
 * @note This function does not configure any PWM parameters. It only enables the peripheral.
 * @note This function does not start PWM generation. Use FLEXPWM_EnableSubmoduleCounter()
 *       and FLEXPWM_EnablePWMOutput() to start PWM output.
 *
 * @param base FlexPWM peripheral base address.
 * @return kStatus_Success if initialization is successful.
 *         kStatus_InvalidArgument if the base address is invalid.
 */
status_t FLEXPWM_Init(PWM_Type *base);

/*!  
 * @brief Deinitialize the FlexPWM module.
 *
 * This function deinitializes the FlexPWM peripheral by:
 * - Disabling clocks for all submodules (SM0-SM3)
 * - Asserting peripheral reset (if supported by platform)
 *
 * After calling this function, all FlexPWM registers are reset.
 *
 * @note To re-enable PWM operation, call FLEXPWM_Init() again.
 *
 * @param base FlexPWM peripheral base address.
 * @return kStatus_Success if deinitialization is successful.
 *         kStatus_InvalidArgument if the base address is invalid.
 */
status_t FLEXPWM_DeInit(PWM_Type *base);

/*!
 * @name Submodule Configuration
 * @{
 */

/*!
 * @brief Get default configuration for FlexPWM submodule.
 *
 * This function initializes the FlexPWM submodule configuration structure with safe default values.
 * The default configuration can be used directly or modified before calling FLEXPWM_ConfigSubmodule().
 *
 * Default values:
 * - Clock source: IPBus clock (kFLEXPWM_ClockSource_IPBusClock)
 * - Prescaler: Divide by 1 (no prescaling)
 * - Counter initial value: 0
 * - Counter modulo value: 0xFFFF (maximum range)
 * - Initialization source: Local sync
 * - Load mode: Opportunity (load at PWM reload opportunity)
 * - Load frequency: 0 (every PWM cycle)
 * - Half-cycle reload: Disabled
 * - Full-cycle reload: Enabled
 * - Reload source: Local reload
 * - Half-cycle value: 0
 * - Debug mode: Disabled (PWM stops in Debug mode)
 * - Wait mode: Disabled (PWM stops in Wait mode)
 *
 * @param config Pointer to the submodule configuration structure.
 */
void FLEXPWM_GetDefaultSubmoduleConfig(flexpwm_submodule_config_t *config);

/*!
 * @brief Configure a FlexPWM submodule.
 *
 * This function configures the basic parameters of a FlexPWM submodule, including:
 * - Clock source and prescaler (CTRL2[CLK_SEL], CTRL[PRSC])
 * - Counter initialization and modulo values (INIT, VAL1)
 * - Counter initialization source (CTRL2[INIT_SEL])
 * - Register reload mode, frequency, and timing (CTRL[LDMOD, LDFQ, HALF, FULL], CTRL2[RELOAD_SEL])
 * - Half-cycle reload point (VAL0)
 * - Debug and Wait mode behavior (CTRL2[DBGEN, WAITEN])
 *
 * @note Prerequisites:
 *       - Call FLEXPWM_Init() before this function to enable the peripheral clock.
 *
 * @note Configuration write behavior:
 *       - This function writes configuration values to buffered registers.
 *       - The configuration does NOT take effect immediately.
 *       - After calling this function, you must set MCTRL[LDOK] bit using a separate function
 *         to transfer buffered register values to active registers.
 *       - The actual transfer timing depends on the configured reload mode and reload opportunities.
 *
 * @note This function does NOT:
 *       - Set the MCTRL[LDOK] bit (you must call a separate LDOK function)
 *       - Start the PWM counter (use a separate start API)
 *       - Configure PWM waveform parameters (VAL2-VAL5, deadtime, polarity, etc.)
 *       - Configure fault protection or capture functionality
 *       - Configure FORCE_OUT behavior (use FLEXPWM_ConfigForceOut)
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the submodule configuration structure.
 */
void FLEXPWM_ConfigSubmodule(PWM_Type *base, uint8_t submodule, const flexpwm_submodule_config_t *config);

/*!
 * @brief Configure PWM output for a FlexPWM submodule.
 *
 * This function configures the PWM output parameters for a FlexPWM submodule, including:
 * - Compare values (VAL2, VAL3, VAL4, VAL5)
 * - Output polarity (POLA, POLB)
 * - Initial values (PWM23_INIT, PWM45_INIT)
 * - Operating mode: independent or complementary (INDEP)
 * - Complementary mode source selection (MCTRL[IPOL]) - only in complementary mode
 *
 * @note For complementary mode (complementary = true):
 *       - Only the selected channel compare values (pwma if ipolSource=kFLEXPWM_IPOL_PWM23,
 *         or pwmb if ipolSource=kFLEXPWM_IPOL_PWM45) needs to be configured.
 *       - But polarity still needs to be set for the complementary output to work correctly.
 *       - The unselected channel will be ignored by the hardware.
 *       - MCTRL[IPOL] will be set according to ipolSource parameter.
 *
 * @note For independent mode (complementary = false):
 *       - Both pwma and pwmb must be fully configured.
 *       - INDEP bit will be set to 1 in SMxCTRL2.
 *       - MCTRL[IPOL] is ignored by the hardware in this mode.
 *
 * @note This function does NOT:
 *       - Set the MCTRL[LDOK] bit (you must call a separate LDOK function)
 *       - Trigger FORCE_OUT events (in complementary mode, MCTRL[IPOL] requires FORCE_OUT to take effect)
 *       - Enable PWM_A Output or PWM_B Output (use a separate API to enable outputs)
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the PWM configuration structure.
 */
void FLEXPWM_ConfigPWM(PWM_Type *base, uint8_t submodule, const flexpwm_pwm_config_t *config);

/*!
 * @brief Configure PWM_X output for a FlexPWM submodule.
 *
 * This function configures the PWM_X output parameters for a FlexPWM submodule, including:
 * - Compare values (VAL0, VAL1)
 * - Output polarity (POLX)
 * - Initial values (PWMX_INIT)
 *
 * @note When submodule works in local sync mode, PWM_X polarity is inverted, because VAL1
 *       determines both counter modulo and PWM_X turn-off edge. VAL0 determines PWM_X turn-on
 *       edge. 
 *       Recommend setting submodule counter works in master sync mode if you want to use the
 *       PWM_X output, then both VAL0 and VAL1 can be used to control PWM_X waveform shape and
 *       polarity is normal.
 *
 * @note This function does NOT:
 *       - Set the MCTRL[LDOK] bit (you must call a separate LDOK function)
 *       - Enable PWM_X Output (use a separate API to enable outputs) 
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param pwmx Pointer to the PWM_X configuration structure.
 */
void FLEXPWM_ConfigPWMChannelX(PWM_Type *base, uint8_t submodule, const flexpwm_pwm_channel_config_t *pwmx);

/*!
 * @brief Get default configuration for force output.
 *
 * This function initializes the force output configuration structure with safe default values.
 * The default configuration can be used directly or modified before calling FLEXPWM_ConfigForceOut().
 *
 * Default values:
 * - FORCE_OUT trigger source: Local software force (kFLEXPWM_ForceOutputSource_LocalForce)
 * - Counter initialization on FORCE_OUT: Disabled (false)
 * - PWM_A source: Generated PWM signal (kFLEXPWM_ForcePwmSource_Generated)
 * - PWM_A software value: Logic 0 (false)
 * - PWM_B source: Generated PWM signal (kFLEXPWM_ForcePwmSource_Generated)
 * - PWM_B software value: Logic 0 (false)
 *
 * @param config Pointer to the force output configuration structure.
 */
void FLEXPWM_GetDefaultForceOutConfig(flexpwm_force_out_config_t *config);

/*!
 * @brief Configure FORCE_OUT for a FlexPWM submodule.
 *
 * This function configures the FORCE_OUT event parameters for a FlexPWM submodule, including:
 * - FORCE_OUT trigger source (CTRL2[FORCE_SEL]): software, master, external, sync signals, etc.
 * - Counter initialization triggered by FORCE_OUT (CTRL2[FRCEN])
 * - PWM source selection for deadtime logic (DTSRCSEL[SMxSEL23/45]): generated, inverted,
 *   software-controlled, or external signals
 * - Software-controlled output values (SWCOUT[SMxOUT23/45]) when source is software-controlled
 *
 * @note Configuration write behavior:
 *       - This function performs read-modify-write operations on global registers (DTSRCSEL, SWCOUT)
 *         to protect other submodules' configurations.
 *       - Register writes are immediate and take effect when the corresponding FORCE_OUT event occurs.
 *       - SWCOUT and DTSRCSEL are NOT affected by MCTRL[LDOK]; they are independent double-buffered
 *         registers that update on FORCE_OUT events.
 *
 * @note FORCE_OUT event effects:
 *       When a FORCE_OUT event occurs, the following updated values take effect simultaneously:
 *       - PWM source routing from DTSRCSEL
 *       - Software-controlled output values from SWCOUT
 *       - Counter may be reinitialized if FRCEN is enabled
 *
 * @note This function does NOT:
 *       - Trigger FORCE_OUT events (DTSRCSEL and SWCOUT settings require FORCE_OUT event to take effect)
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the force output configuration structure.
 */
void FLEXPWM_ConfigForceOut(PWM_Type *base, uint8_t submodule, const flexpwm_force_out_config_t *config);

/*! @} */

/*!
 * @name Fault Protection Configuration
 * @{
 */

/*!
 * @brief Get default configuration for fault protection.
 *
 * This function initializes the fault protection configuration structure with safe default values.
 * The default configuration can be used directly or modified before calling FLEXPWM_ConfigFaultProtection().
 *
 * Default values:
 * - Fault Input Active Level (faultInputActiveLevel): Active high (true)
 * - Fault Clearing Mode (faultClearingMode): Automatic fault clearing
 * - Safety Mode (enableSafetyMode): Enabled (safe mode)
 * - Full Cycle Recovery (enableFullCycleRecovery): Enabled
 * - Half Cycle Recovery (enableHalfCycleRecovery): Disabled
 * - Combinational Path (enableCombinatorialPath): Enabled (allow combinational path for fastest response)
 *
 * @param config Pointer to the fault protection configuration structure.
 */
void FLEXPWM_GetDefaultFaultConfig(flexpwm_fault_config_t *config);

/*!
 * @brief Get default configuration for fault submodule protection.
 *
 * This function initializes the fault submodule configuration structure with safe default values.
 * The default configuration can be used directly or modified before calling FLEXPWM_ConfigFaultSubmodule().
 *
 * Default values:
 * - Disable Mask: All faults (0x0F) affect each output
 * - Output Behavior: High-Z (high impedance) for all outputs
 *
 * For single-channel platforms: disableMask_ch0 = 0x0F
 * For dual-channel platforms: disableMask_ch0 = 0x0F, disableMask_ch1 = 0x0F
 *
 * @param config Pointer to the fault submodule configuration structure.
 */
void FLEXPWM_GetDefaultFaultSubmoduleConfig(flexpwm_fault_submodule_config_t *config);

/*!
 * @brief Get default configuration for fault filter.
 *
 * This function initializes the fault filter configuration structure with safe default values.
 * The default configuration provides moderate debouncing suitable for typical applications.
 *
 * Default values:
 * - Filter Period (FILT_PER): 0x08 (8 IPBus clock cycles)
 * - Filter Count (FILT_CNT): 0x04 (7 consecutive samples = 4+3)
 * - Glitch Stretching (GSTR): Enabled
 *
 * Effective debounce window: ~56 IPBus clock cycles
 *
 * @param config Pointer to the fault filter configuration structure.
 */
void FLEXPWM_GetDefaultFaultFilterConfig(flexpwm_fault_filter_config_t *config);

/*!
 * @brief Configure fault protection for a FlexPWM fault channel.
 *
 * This function configures global fault protection parameters for one fault channel,
 * including fault input active level, clearing mode, safety mode, and fault recovery timing.
 *
 * Configuration details:
 * - Fault input active level (faultInputActiveLevel): Selects whether fault is triggered by high or low
 * - Fault clearing mode (faultClearingMode): Controls how and when PWM outputs are re-enabled
 * - Safety mode (enableSafetyMode): Adds extra requirement that fault input be de-asserted before re-enable
 * - Fault recovery timing (enableFullCycleRecovery, enableHalfCycleRecovery): Specifies during which PWM cycle phase outputs re-enable
 * - Combinational path (enableCombinatorialPath): Trades off response speed vs. latency
 *
 * @note Prerequisites:
 *       - Call FLEXPWM_Init() before this function to enable the peripheral clock.
 *
 * @note Configuration applies to the entire fault channel (all submodules that reference it).
 *       For platforms with dual fault channels, call this function separately for each channel.
 *
 * @note For platforms with dual fault channels:
 *       - faultChannel 0: Configures FAULT0-3 (FCTRL/FSTS/FFILT at offset 0x18C)
 *       - faultChannel 1: Configures FAULT4-7 (FCTRL/FSTS/FFILT at offset 0x198)
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number (0 or 1 for dual-channel platforms).
 * @param config Pointer to the fault protection configuration structure.
 * @param faultMask Fault input selection mask for the channel. Each bit corresponds to one fault input:
 *                  - bit[0] = FAULT0 (or FAULT4 for channel 1)
 *                  - bit[1] = FAULT1 (or FAULT5 for channel 1)
 *                  - bit[2] = FAULT2 (or FAULT6 for channel 1)
 *                  - bit[3] = FAULT3 (or FAULT7 for channel 1)
 *                  Example: 0x05 = configure FAULT0 and FAULT2 with the same settings.
 *                  Can use flexpwm_fault_mask_t enum values (kFLEXPWM_FaultMask_0/1/2/3) and
 *                  OR them together for multiple faults:
 *                  (kFLEXPWM_FaultMask_0 | kFLEXPWM_FaultMask_2) = 0x05.
 */
void FLEXPWM_ConfigFaultProtection(PWM_Type *base, uint8_t faultChannel, const flexpwm_fault_config_t *config,
                                   uint16_t faultMask);

/*!
 * @brief Configure fault submodule protection for a FlexPWM submodule.
 *
 * This function configures fault-to-PWM-output mapping and output behavior for all three
 * PWM outputs (PWM_A, PWM_B, PWM_X) of a single submodule. Each output can independently
 * select which faults affect it and how it responds during a fault.
 *
 * Configuration per output:
 * - Disable Mask: Selects which fault inputs can disable this output
 *   - disableMask_ch0: Bits [0-3] for FAULT0-3
 *   - disableMask_ch1: Bits [0-3] for FAULT4-7 (dual-channel platforms only)
 * - Output Behavior: Specifies pin state during fault (Force 0, Force 1, or High-Z)
 *
 * @note Configuration applies to SMxDISMAP and SMxOCTRL registers.
 *       These registers are not affected by LDOK or FORCE_OUT; configuration takes effect
 *       immediately upon register write.
 *
 * @note For dual-channel platforms, specify disableMask_ch0 and disableMask_ch1 to control
 *       which faults (from either channel) can disable each output.
 *
 * @note For single-channel platforms, only disableMask_ch0 is used; disableMask_ch1 is
 *       conditionally compiled out.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the fault submodule configuration structure.
 */
void FLEXPWM_ConfigFaultSubmodule(PWM_Type *base, uint8_t submodule, const flexpwm_fault_submodule_config_t *config);

/*!
 * @brief Configure fault filter for a FlexPWM fault channel.
 *
 * This function configures the input filter for fault protection pins, including sampling
 * period, sample count requirement, and glitch stretching logic.
 *
 * The filter helps reject electrical noise and false fault triggers by requiring the
 * FAULTx signal to be stable for N consecutive samples before a fault is reported.
 * With GSTR enabled, narrow fault glitches (< 2 IPBus cycles) are automatically stretched.
 *
 * @note Prerequisites:
 *       - Call FLEXPWM_Init() before this function to enable the peripheral clock.
 *
 * @note Configuration applies to the entire fault channel (FFILT register).
 *       For platforms with dual fault channels, call this function separately for each channel.
 *
 * @note Filter delay calculation:
 *       - Without GSTR: delay = FILT_PER * (FILT_CNT + 3) IPBus cycles
 *       - With GSTR:    may be reduced due to glitch stretching logic
 *
 * @note To disable filtering:
 *       - Set filterPeriod = 0 (sampling disabled, filter bypassed)
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number (0 or 1 for dual-channel platforms).
 * @param config Pointer to the fault filter configuration structure.
 */
void FLEXPWM_ConfigFaultFilter(PWM_Type *base, uint8_t faultChannel, const flexpwm_fault_filter_config_t *config);

/*! @} */

/*!
 * @name Output Trigger Configuration
 * @{
 */

/*!
 * @brief Get default configuration for output trigger.
 *
 * This function initializes the output trigger configuration structure with safe default values:
 * - outTriggerEnable: 0 (all triggers disabled)
 * - triggerFrequency: kFLEXPWM_TriggerFrequency_EveryCycle (trigger every PWM cycle)
 * - muxTrig0Source: kFLEXPWM_TriggerMuxSource_GeneratedTrigger (use PWM_OUT_TRIG0)
 * - muxTrig1Source: kFLEXPWM_TriggerMuxSource_GeneratedTrigger (use PWM_OUT_TRIG1)
 * - stretchPrescaler: kFLEXPWM_StretchPrescaler_None (no prescaling, if supported)
 *
 * After calling this function, the user should modify the fields as needed before calling
 * FLEXPWM_ConfigOutputTrigger().
 */
void FLEXPWM_GetDefaultOutputTriggerConfig(flexpwm_output_trigger_config_t *config);

/*!
 * @brief Configure output trigger for a FlexPWM submodule.
 *
 * This function configures the output trigger parameters for a FlexPWM submodule, including:
 * - Trigger source mapping from VAL0-5 register matches (SMxTCTRL[OUT_TRIG_EN])
 * - Trigger output frequency control (SMxTCTRL[TRGFRQ])
 * - PWM_MUX_TRIG0 port source selection (SMxTCTRL[PWAOT0])
 * - PWM_MUX_TRIG1 port source selection (SMxTCTRL[PWBOT1])
 *
 * The output trigger mechanism allows PWM events (counter matches with VAL registers) to
 * trigger external modules such as ADC, DMA, or other peripherals for synchronized operation.
 *
 * @note Trigger source mapping:
 *       - VAL0, VAL2, VAL4 matches generate PWM_OUT_TRIG0
 *       - VAL1, VAL3, VAL5 matches generate PWM_OUT_TRIG1
 *       Multiple sources can be enabled simultaneously (OR logic).
 *
 * @note Trigger frequency control (TRGFRQ):
 *       This setting only takes effect when CTRL[LDFQ] is non-zero (reload frequency divider active).
 *       - false: Trigger outputs every PWM cycle regardless of reload occurrence
 *       - true: Trigger outputs only on the last PWM cycle before a reload opportunity
 *
 * @note Port routing:
 *       PWM_MUX_TRIG0/1 ports can be routed to either:
 *       - Generated trigger signals (PWM_OUT_TRIG0/1) from VAL register matches
 *       - Direct PWM outputs (PWM_A/PWM_B) for waveform monitoring
 *       Both ports are independently configurable.
 *
 * @note Configuration takes effect immediately upon register write.
 *       This function does NOT require setting MCTRL[LDOK].
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the output trigger configuration structure.
 */
void FLEXPWM_ConfigOutputTrigger(PWM_Type *base, uint8_t submodule, const flexpwm_output_trigger_config_t *config);

/*! @} */

/*!
 * @name Input Capture Configuration
 * @{
 */

/*!
 * @brief Get default configuration for input capture.
 *
 * This function initializes the input capture configuration structure with safe default values.
 * The default values are:
 *   - All channels (A/B/X):
 *     - edge0 = kFLEXPWM_CaptureEdge_Disabled
 *     - edge1 = kFLEXPWM_CaptureEdge_Disabled
 *     - oneshot = false (free running mode)
 *     - inputSelect = kFLEXPWM_CaptureInput_RawSignal
 *     - edgeCompareValue = 0
 *     - fifoWatermark = kFLEXPWM_CaptureFifoWatermark_1
 *
 * After calling this function, the user should modify the fields as needed before calling
 * FLEXPWM_ConfigInputCapture().
 *
 * @param config Pointer to the input capture configuration structure.
 */
void FLEXPWM_GetDefaultInputCaptureConfig(flexpwm_input_capture_config_t *config);

#if (defined(FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE) && FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE)
/*!
 * @brief Get default configuration for capture filter.
 *
 * This function initializes the capture filter configuration structure with safe default values.
 * The default values are:
 *   - All channels (A/B/X):
 *     - filterPeriod = 0 (filter bypassed, sampling disabled)
 *     - filterCount = 0 (requires 3 consecutive samples)
 *
 * After calling this function, the user should modify the fields as needed before calling
 * FLEXPWM_ConfigInputCaptureFilter().
 *
 * @param config Pointer to the capture filter configuration structure.
 */
void FLEXPWM_GetDefaultCaptureFilterConfig(flexpwm_capture_filter_config_t *config);
#endif

/*!
 * @brief Configure input capture for a FlexPWM submodule.
 *
 * This function configures the input capture parameters for up to three capture channels
 * (Capture_A, Capture_B, Capture_X) of a FlexPWM submodule, including:
 * - Edge detection configuration for two edge detectors per channel (SMxCAPTCTRLA/B/X[EDGx0/1])
 * - One-shot or free-running mode (SMxCAPTCTRLA/B/X[ONESHOTx])
 * - Input source selection: raw signal or edge counter output (SMxCAPTCTRLA/B/X[INP_SELx])
 * - Edge counter compare value (SMxCAPTCOMPA/B/X[EDGCMPx])
 * - FIFO watermark level (SMxCAPTCTRLA/B/X[CFxWM])
 *
 * @note Edge counter behavior:
 *       - When inputSelect = kFLEXPWM_CaptureInput_EdgeCounter, the edge counter is
 *         automatically enabled (EDGCNTx_EN = 1) by this function.
 *       - When inputSelect = kFLEXPWM_CaptureInput_RawSignal, the edge counter remains disabled.
 *
 * @note Capture enable control:
 *       - This function does NOT control the capture enable bits (ARMA/ARMB/ARMX).
 *       - After calling this function, use a separate enable API to start capture operation.
 *
 * @note CVAL register mapping (NON-INTUITIVE):
 *       - Capture_X: Edge0 -> CVAL0, Edge1 -> CVAL1
 *       - Capture_A: Edge0 -> CVAL2, Edge1 -> CVAL3
 *       - Capture_B: Edge0 -> CVAL4, Edge1 -> CVAL5
 *
 * @note Prerequisites:
 *       - Call FLEXPWM_Init() before this function to enable the peripheral clock.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the input capture configuration structure.
 */
void FLEXPWM_ConfigInputCapture(PWM_Type *base, uint8_t submodule, const flexpwm_input_capture_config_t *config);

#if (defined(FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE) && FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE)
/*!
 * @brief Configure input capture filter for a FlexPWM submodule.
 *
 * This function configures the digital filter parameters for the three capture channels
 * (Capture_A, Capture_B, Capture_X) of a FlexPWM submodule. The filter settings include:
 * - Filter sampling period (SMxCAPTFILTA/B/X[CAPTx_FILT_PER])
 * - Number of consecutive samples required (SMxCAPTFILTA/B/X[CAPTx_FILT_CNT])
 *
 * The digital filter can eliminate glitches and noise on the capture input signals.
 *
 * @note Filter bypassing:
 *       - Set filterPeriod = 0 to bypass the filter (no sampling, filter disabled).
 *
 * @note Filter delay calculation:
 *       - Delay = filterPeriod * (filterCount + 3) IPBus clock cycles
 *       - Example: filterPeriod=5, filterCount=2 -> delay = 5*(2+3) = 25 cycles
 *
 * @note Hardware behavior:
 *       - This function always writes 0 to the filter register first, then writes the
 *         configuration value. This ensures correct behavior per hardware requirements.
 *
 * @note Prerequisites:
 *       - Call FLEXPWM_Init() before this function to enable the peripheral clock.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the capture filter configuration structure.
 */
void FLEXPWM_ConfigInputCaptureFilter(PWM_Type *base, uint8_t submodule, const flexpwm_capture_filter_config_t *config);
#endif

/*!
 * @brief Read captured value from a FlexPWM capture channel.
 *
 * This function reads the captured counter value from one of the six capture value registers
 * (CVAL0-5) for the specified capture channel and edge detector.
 *
 * @warning Destructive read:
 *          - Reading a CVAL register decrements the FIFO count by 1.
 *          - If the FIFO is empty, the read value is undefined.
 *          - Check the FIFO empty flag (CFx) before reading to avoid invalid data.
 *
 * @note CVAL register mapping (NON-INTUITIVE):
 *       - kFLEXPWM_Capture_X_Edge0 -> CVAL0
 *       - kFLEXPWM_Capture_X_Edge1 -> CVAL1
 *       - kFLEXPWM_Capture_A_Edge0 -> CVAL2
 *       - kFLEXPWM_Capture_A_Edge1 -> CVAL3
 *       - kFLEXPWM_Capture_B_Edge0 -> CVAL4
 *       - kFLEXPWM_Capture_B_Edge1 -> CVAL5
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param captureIndex Capture channel and edge detector index (use flexpwm_capture_index_t enum).
 * @return The captured counter value (16-bit).
 */
uint16_t FLEXPWM_GetInputCaptureValue(PWM_Type *base, uint8_t submodule, flexpwm_capture_index_t captureIndex);

/*!
 * @brief Read captured cycle counter value from a FlexPWM capture channel.
 *
 * This function reads the captured cycle counter value from one of the six capture cycle
 * registers (CCYC0-5) for the specified capture channel and edge detector. The cycle counter
 * value represents the upper part of the extended timestamp when a capture event occurs.
 *
 * @note CCYC register mapping (matches CVAL mapping):
 *       - kFLEXPWM_Capture_X_Edge0 -> CCYC0
 *       - kFLEXPWM_Capture_X_Edge1 -> CCYC1
 *       - kFLEXPWM_Capture_A_Edge0 -> CCYC2
 *       - kFLEXPWM_Capture_A_Edge1 -> CCYC3
 *       - kFLEXPWM_Capture_B_Edge0 -> CCYC4
 *       - kFLEXPWM_Capture_B_Edge1 -> CCYC5
 *
 * @note Combined timestamp:
 *       - The full timestamp is {CCYC, CVAL} (cycle counter as upper 16 bits, capture value
 *         as lower 16 bits), forming a 32-bit extended timestamp.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param captureIndex Capture channel and edge detector index (use flexpwm_capture_index_t enum).
 * @return The captured cycle counter value (16-bit).
 */
uint16_t FLEXPWM_GetInputCaptureCycle(PWM_Type *base, uint8_t submodule, flexpwm_capture_index_t captureIndex);

/*!
 * @brief Enable input capture for a FlexPWM capture channel.
 *
 * This function enables input capture operation for the specified capture channel by setting
 * the corresponding ARM bit (ARMA/ARMB/ARMX) in the capture control register.
 *
 * @note ARM bit behavior in one-shot mode:
 *       When the capture channel is configured for one-shot mode (ONESHOT = 1), the ARM bit
 *       automatically clears after two capture events complete.
 *
 * @note Prerequisites:
 *       Before enabling capture, ensure:
 *       1. Capture channel is configured (FLEXPWM_ConfigInputCapture)
 *       2. Edge detectors are configured (EDGA0/EDGA1, EDGB0/EDGB1, or EDGX0/EDGX1)
 *       3. Counter is running (FLEXPWM_EnableSubmoduleCounter)
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param channel Capture channel selection (use flexpwm_capture_channel_t enum).
 */
void FLEXPWM_EnableInputCapture(PWM_Type *base, uint8_t submodule, flexpwm_capture_channel_t channel);

/*!
 * @brief Disable input capture for a FlexPWM capture channel.
 *
 * This function disables input capture operation for the specified capture channel by clearing
 * the corresponding ARM bit (ARMA/ARMB/ARMX) in the capture control register.
 *
 * @note FIFO handling:
 *       Disabling capture does not flush the FIFO. Any previously captured values remain
 *       readable. Clear the capture flags (CFx0/CFx1) separately if needed.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param channel Capture channel selection (use flexpwm_capture_channel_t enum).
 */
void FLEXPWM_DisableInputCapture(PWM_Type *base, uint8_t submodule, flexpwm_capture_channel_t channel);

/*! @} */

/*!
 * @name Dynamic Update
 * @{
 */

/*!
 * @brief Set the INIT register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the INIT register (initial count register).
 * The INIT register defines the starting value of the counter when it is initialized.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust PWM parameters. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for:
 *       - Ensuring LDOK is clear before calling this function
 *       - Setting LDOK after updating registers to trigger reload
 *       - Managing reload timing and synchronization
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the INIT register (16-bit).
 */
static inline void FLEXPWM_SetINIT(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].INIT = value;
}

/*!
 * @brief Set the VAL0 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the VAL0 register.
 * VAL0 defines the half-cycle reload point for the PWM counter.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust PWM parameters. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for reload timing.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the VAL0 register (16-bit).
 */
static inline void FLEXPWM_SetVAL0(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].VAL0 = value;
}

/*!
 * @brief Set the VAL1 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the VAL1 register.
 * VAL1 defines the modulo (period) value for the PWM counter.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust PWM period. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for reload timing.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the VAL1 register (16-bit).
 */
static inline void FLEXPWM_SetVAL1(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].VAL1 = value;
}

/*!
 * @brief Set the VAL2 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the VAL2 register.
 * VAL2 defines the count value at which PWM23 (PWM_A) is set high, controlling
 * the turn-on edge of PWM_A output.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust PWM_A duty cycle. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for reload timing.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the VAL2 register (16-bit).
 */
static inline void FLEXPWM_SetVAL2(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].VAL2 = value;
}

/*!
 * @brief Set the VAL3 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the VAL3 register.
 * VAL3 defines the count value at which PWM23 (PWM_A) is set low, controlling
 * the turn-off edge of PWM_A output.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust PWM_A duty cycle. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for reload timing.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the VAL3 register (16-bit).
 */
static inline void FLEXPWM_SetVAL3(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].VAL3 = value;
}

/*!
 * @brief Set the VAL4 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the VAL4 register.
 * VAL4 defines the count value at which PWM45 (PWM_B) is set high, controlling
 * the turn-on edge of PWM_B output.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust PWM_B duty cycle. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for reload timing.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the VAL4 register (16-bit).
 */
static inline void FLEXPWM_SetVAL4(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].VAL4 = value;
}

/*!
 * @brief Set the VAL5 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the VAL5 register.
 * VAL5 defines the count value at which PWM45 (PWM_B) is set low, controlling
 * the turn-off edge of PWM_B output.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust PWM_B duty cycle. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for reload timing.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the VAL5 register (16-bit).
 */
static inline void FLEXPWM_SetVAL5(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].VAL5 = value;
}

/*!
 * @brief Set the DTCNT0 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the DTCNT0 register (deadtime count register 0).
 * DTCNT0 specifies the number of IPBus clock cycles for deadtime delay insertion,
 * independent of the PWM clock prescaler settings (CTRL[PRSC] and CTRL2[CLK_SEL]).
 * DTCNT0 inserts software-selectable activation delays at PWM_A turn-on edge.
 *
 * @note DTCNT0 is an 11-bit register with valid range 0-0x7FF. Values exceeding this range
 *       will be masked to 11 bits.
 *
 * @note This function applies only to complementary PWM mode.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the DTCNT0 register (11-bit, range: 0-0x7FF).
 */
static inline void FLEXPWM_SetDTCNT0(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].DTCNT0 = value;
}

/*!
 * @brief Set the DTCNT1 register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the DTCNT1 register (deadtime count register 1).
 * DTCNT1 specifies the number of IPBus clock cycles for deadtime delay insertion,
 * independent of the PWM clock prescaler settings (CTRL[PRSC] and CTRL2[CLK_SEL]).
 * DTCNT1 inserts software-selectable activation delays at PWM_B turn-on edge.
 *
 * @note DTCNT1 is an 11-bit register with valid range 0-0x7FF. Values exceeding this range
 *       will be masked to 11 bits.
 *
 * @note This function applies only to complementary PWM mode.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param value The value to write to the DTCNT1 register (11-bit, range: 0-0x7FF).
 */
static inline void FLEXPWM_SetDTCNT1(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].DTCNT1 = value;
}

#if (defined(FSL_FEATURE_PWM_HAS_PHASE_DELAY) && FSL_FEATURE_PWM_HAS_PHASE_DELAY)
/*!
 * @brief Set the Phase Delay register value for a FlexPWM submodule.
 *
 * This function directly writes a value to the PHASEDLY register (phase delay register).
 * PHASEDLY defines the time delay from the master sync signal (from submodule 0) to when
 * this submodule recognizes the master sync, specified in PWM clock cycles.
 *
 * Setting this register to a non-zero value and using the master sync signal as the
 * initialization source allows this submodule's output to be delayed by a fixed number
 * of cycles relative to submodule 0, enabling phase-shifted PWM outputs.
 *
 * @note PHASEDLY is only valid for submodules 1-3. Submodule 0 is the master sync source
 *       and cannot have a phase delay relative to itself.
 *
 * @note This function is intended for use in runtime scenarios such as interrupt handlers
 *       to dynamically adjust phase delay. It performs a direct register write without
 *       checking or managing MCTRL[LDOK]. Users are responsible for reload timing.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (1-3, must NOT be 0).
 * @param value The value to write to the PHASEDLY register (16-bit).
 */
static inline void FLEXPWM_SetPhaseDelay(PWM_Type *base, uint8_t submodule, uint16_t value)
{
    assert(0U != submodule);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].PHASEDLY = value;
}
#endif

/*!
 * @brief Set Compare Mode for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param compareMode The compare mode to set for the submodule.
 */
static inline void FLEXPWM_SetCompareMode(PWM_Type *base, uint8_t submodule, flexpwm_compare_mode_t compareMode)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    uint16_t reg;
    reg = base->SM[submodule].CTRL;
    reg = (reg & MCUX_MASK_INVERT_16(PWM_CTRL_COMPMODE_MASK)) | PWM_CTRL_COMPMODE(compareMode);
    base->SM[submodule].CTRL = reg;
}

/*!
 * @brief Mask PWM_A, PWM_B, PWM_X outputs for specified submodules.
 *
 * This function sets the MASK register bits to mask (disable) PWM outputs by forcing them
 * to logic 0 before output polarity is applied. The mask takes effect when a FORCE_OUT
 * event occurs on the corresponding submodule, unless immediate update is enabled.
 *
 * @note MASK register characteristics:
 *       - Double-buffered register: writes take effect on next FORCE_OUT event
 *       - Use FLEXPWM_EnableUpdateMaskImmediately() to bypass FORCE_OUT requirement
 *       - Masking forces output to logic 0 before polarity inversion
 *
 * @note This function performs read-modify-write to preserve:
 *       - Mask settings for other submodules not specified in parameters
 *       - UPDATE_MASK bits (on platforms with FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
 *
 * @param base FlexPWM peripheral base address.
 * @param aMask Submodule mask for PWM_A outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param bMask Submodule mask for PWM_B outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param xMask Submodule mask for PWM_X outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_MaskPWMOutput(PWM_Type *base, uint16_t aMask, uint16_t bMask, uint16_t xMask)
{
    base->MASK |= (PWM_MASK_MASKA(aMask) | PWM_MASK_MASKB(bMask) | PWM_MASK_MASKX(xMask));
}

/*!
 * @brief Unmask PWM_A, PWM_B, PWM_X outputs for specified submodules.
 *
 * This function clears the MASK register bits to unmask (enable) PWM outputs.
 * The unmask takes effect when a FORCE_OUT event occurs on the corresponding submodule,
 * unless immediate update is enabled.
 *
 * @param base FlexPWM peripheral base address.
 * @param aMask Submodule mask for PWM_A outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param bMask Submodule mask for PWM_B outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param xMask Submodule mask for PWM_X outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_UnMaskPWMOutput(PWM_Type *base, uint16_t aMask, uint16_t bMask, uint16_t xMask)
{
    uint16_t mask = (PWM_MASK_MASKA(aMask) | PWM_MASK_MASKB(bMask) | PWM_MASK_MASKX(xMask));
    base->MASK &= MCUX_MASK_INVERT_16(mask);
}

#if (defined(FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD) && FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
/*!
 * @brief Enable immediate MASK register update for specified submodules.
 *
 * This function configures the specified submodules to update their MASK register values
 * immediately, bypassing the FORCE_OUT event requirement. This is useful for emergency
 * stop or fault protection scenarios where immediate output masking is required.
 *
 * @note MASK[UPDATE_MASK] register characteristics:
 *       - Setting a bit to 1 enables immediate MASK update for that submodule
 *       - Once enabled, MASK updates take effect immediately without waiting for FORCE_OUT
 *
 * @param base FlexPWM peripheral base address.
 * @param submoduleMask Submodule selection mask (OR'ed combination of flexpwm_submodule_mask_t).
 *                      bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_EnableUpdateMaskImmediately(PWM_Type *base, uint16_t submoduleMask)
{
    base->MASK |= (submoduleMask & 0x0FU) << PWM_MASK_UPDATE_MASK_SHIFT;
}
#endif

/*!
 * @brief Set PWM source for PWM23 (PWM_A) of a submodule.
 *
 * This function selects the signal source that feeds into the deadtime insertion logic
 * for PWM23 (PWM_A) output by configuring the DTSRCSEL register. The setting takes effect
 * when a FORCE_OUT event occurs on the submodule.
 *
 * Available sources:
 * - Generated PWM: Normal PWM signal from PWM generator
 * - Inverted PWM: Inverted version of generated PWM
 * - Software: Software-controlled value from SWCOUT register
 * - External: External input signal
 *
 * @note DTSRCSEL register characteristics:
 *       - Double-buffered: Changes take effect on next FORCE_OUT event
 *       - NOT affected by MCTRL[LDOK]: Independent of reload mechanism
 *       - Global register: This function performs read-modify-write to protect other submodules
 *
 * @note When source is set to kFLEXPWM_ForcePwmSource_Software, use
 *       FLEXPWM_SetSoftwareControlOutput23() to set the output value.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param source PWM source selection (use flexpwm_force_pwm_source_t enum).
 */
static inline void FLEXPWM_SetPWMSource23(PWM_Type *base, uint8_t submodule, uint16_t source)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    assert(source <= 3U);
    uint16_t shift = (uint16_t)submodule * 4U + 2U;
    uint16_t mask = (uint16_t)((0x03UL << (uint32_t)shift) & 0xFFFFU);
    base->DTSRCSEL = (base->DTSRCSEL & MCUX_MASK_INVERT_16(mask)) | ((source << shift) & 0xFFFFU);
}

/*!
 * @brief Set PWM source for PWM45 (PWM_B) of a submodule.
 *
 * This function selects the signal source that feeds into the deadtime insertion logic
 * for PWM45 (PWM_B) output by configuring the DTSRCSEL register. The setting takes effect
 * when a FORCE_OUT event occurs on the submodule.
 *
 * @note See FLEXPWM_SetPWMSource23() documentation for detailed information about
 *       source selection, register characteristics, and usage notes.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param source PWM source selection (use flexpwm_force_pwm_source_t enum).
 */
static inline void FLEXPWM_SetPWMSource45(PWM_Type *base, uint8_t submodule, uint16_t source)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    assert(source <= 3U);
    uint16_t shift = (uint16_t)submodule * 4U;
    uint16_t mask = (uint16_t)((0x03UL << (uint32_t)shift) & 0xFFFFU);
    base->DTSRCSEL = (base->DTSRCSEL & MCUX_MASK_INVERT_16(mask)) | ((source << shift) & 0xFFFFU);
}

/*!
 * @brief Set software-controlled output value for PWM23 (PWM_A) of a submodule.
 *
 * This function sets the software-controlled PWM output value in the SWCOUT register.
 * This value is used as the PWM source when DTSRCSEL is configured to select software
 * control (kFLEXPWM_ForcePwmSource_Software). The setting takes effect when a FORCE_OUT
 * event occurs on the submodule.
 *
 * @note SWCOUT register characteristics:
 *       - Double-buffered: Changes take effect on next FORCE_OUT event
 *       - NOT affected by MCTRL[LDOK]: Independent of reload mechanism
 *       - Global register: This function performs read-modify-write to protect other submodules
 *
 * @note Typical usage sequence:
 *       1. Call FLEXPWM_SetPWMSource23(base, kFLEXPWM_ForcePwmSource_Software, submodule)
 *       2. Call FLEXPWM_SetSoftwareControlOutput23(base, value, submodule)
 *       3. Trigger FORCE_OUT event to make both settings take effect
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param softwareValue Software control output value (0 or 1).
 *                      - 0: Logic 0 provided to deadtime logic instead of PWM23
 *                      - 1: Logic 1 provided to deadtime logic instead of PWM23
 */
static inline void FLEXPWM_SetSoftwareControlOutput23(PWM_Type *base, uint8_t submodule, uint16_t softwareValue)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    assert(softwareValue <= 1U);
    uint16_t shift = (uint16_t)submodule * 2U + 1U;
    uint16_t mask = (uint16_t)((0x01UL << (uint32_t)shift) & 0xFFFFU);
    base->SWCOUT = (base->SWCOUT & MCUX_MASK_INVERT_16(mask)) | ((softwareValue << shift) & 0xFFFFU);
}

/*!
 * @brief Set software-controlled output value for PWM45 (PWM_B) of a submodule.
 *
 * This function sets the software-controlled PWM output value in the SWCOUT register.
 * This value is used as the PWM source when DTSRCSEL is configured to select software
 * control (kFLEXPWM_ForcePwmSource_Software).
 *
 * @note See FLEXPWM_SetSoftwareControlOutput23() documentation for detailed information
 *       about register characteristics, usage sequence, and notes.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param softwareValue Software control output value (0 or 1).
 *                      - 0: Logic 0 provided to deadtime logic instead of PWM45
 *                      - 1: Logic 1 provided to deadtime logic instead of PWM45
 */
static inline void FLEXPWM_SetSoftwareControlOutput45(PWM_Type *base, uint8_t submodule, uint16_t softwareValue)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    assert(softwareValue <= 1U);
    uint16_t shift = (uint16_t)submodule * 2U;
    uint16_t mask = (uint16_t)((0x01UL << (uint32_t)shift) & 0xFFFFU);
    base->SWCOUT = (base->SWCOUT & MCUX_MASK_INVERT_16(mask)) | ((softwareValue << shift) & 0xFFFFU);
}

/*!
 * @brief Select PWM23 (PWM_A) as complementary PWM source for specified submodules.
 *
 * This function configures the MCTRL[IPOL] register to select PWM23 (PWM_A) as the source
 * for generating complementary PWM pair outputs in complementary mode. The setting takes
 * effect when a FORCE_OUT event occurs on the submodule.
 *
 * In complementary mode:
 * - PWM_A output: PWM23 signal (non-inverted)
 * - PWM_B output: ~PWM23 signal (inverted complement)
 *
 * @note MCTRL[IPOL] register characteristics:
 *       - Takes effect on FORCE_OUT event (double-buffered behavior)
 *       - Only applies when submodule is in complementary mode (INDEP = 0)
 *       - Ignored in independent mode (INDEP = 1)
 *
 * @note This function clears IPOL bits for specified submodules (IPOL = 0 selects PWM23).
 *
 * @param base FlexPWM peripheral base address.
 * @param submoduleMask Submodule selection mask (OR'ed combination of flexpwm_submodule_mask_t).
 *                      bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_SetComplementaryPWMSource23(PWM_Type *base, uint16_t submoduleMask)
{
    base->MCTRL &= MCUX_MASK_INVERT_16((submoduleMask & 0x0FU) << PWM_MCTRL_IPOL_SHIFT);
}

/*!
 * @brief Select PWM45 (PWM_B) as complementary PWM source for specified submodules.
 *
 * This function configures the MCTRL[IPOL] register to select PWM45 (PWM_B) as the source
 * for generating complementary PWM pair outputs in complementary mode. The setting takes
 * effect when a FORCE_OUT event occurs on the submodule.
 *
 * In complementary mode:
 * - PWM_A output: ~PWM45 signal (inverted complement)
 * - PWM_B output: PWM45 signal (non-inverted)
 *
 * @note See FLEXPWM_SetComplementaryPWMSource23() documentation for detailed information
 *       about MCTRL[IPOL] characteristics and complementary mode operation.
 *
 * @note This function sets IPOL bits for specified submodules (IPOL = 1 selects PWM45).
 *
 * @param base FlexPWM peripheral base address.
 * @param submoduleMask Submodule selection mask (OR'ed combination of flexpwm_submodule_mask_t).
 *                      bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_SetComplementaryPWMSource45(PWM_Type *base, uint16_t submoduleMask)
{
    base->MCTRL |= (submoduleMask & 0x0FU) << PWM_MCTRL_IPOL_SHIFT;
}

/*!
 * @brief Set Load Okay (LDOK) for specified submodules.
 *
 * This function sets the MCTRL[LDOK] bits to enable register reload for the specified submodules.
 * When LDOK is set, buffered register values will be transferred to active registers according to
 * the reload mode and timing configured in CTRL[LDMOD, LDFQ, HALF, FULL].
 *
 * @note LDOK behavior:
 *       - Can only be set when the corresponding LDOK bit is currently 0
 *       - Automatically cleared by hardware after reload completes
 *       - Can be manually cleared using FLEXPWM_ClearLoadOkay()
 *       - While LDOK=1, writes to buffered registers are blocked
 *
 * @note Typical usage flow:
 *       1. Modify buffered registers (VAL0-5, INIT, etc.) using FLEXPWM_SetVALx() or similar
 *       2. Call FLEXPWM_SetLoadOkay() to trigger reload
 *       3. Hardware transfers buffered values at the configured reload opportunity
 *       4. LDOK automatically clears after reload completes
 *
 * @param base FlexPWM peripheral base address.
 * @param submoduleMask Submodule selection mask (OR'ed combination of flexpwm_submodule_mask_t).
 *                      bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_SetLoadOkay(PWM_Type *base, uint16_t submoduleMask)
{
    base->MCTRL |= PWM_MCTRL_LDOK(submoduleMask);
}

/*!
 * @brief Clear Load Okay (LDOK) for specified submodules.
 *
 * This function clears the MCTRL[LDOK] bits by writing to MCTRL[CLDOK] bits.
 * This cancels a pending reload operation for the specified submodules.
 *
 * @note MCTRL[CLDOK] (Clear LDOK) mechanism:
 *       - Writing 1 to CLDOK[x] clears the corresponding LDOK[x] bit
 *       - CLDOK is write-only; reading always returns 0
 *       - Use this when you need to cancel a pending reload
 *
 * @param base FlexPWM peripheral base address.
 * @param submoduleMask Submodule selection mask (OR'ed combination of flexpwm_submodule_mask_t).
 *                      bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_ClearLoadOkay(PWM_Type *base, uint16_t submoduleMask)
{
    base->MCTRL |= PWM_MCTRL_CLDOK(submoduleMask);
}

/*!
 * @brief Get Load Okay (LDOK) status.
 *
 * This function reads the MCTRL[LDOK] bits to check which submodules have pending reload operations.
 *
 * @note Return value format:
 *       - Bit[0]: Submodule 0 LDOK status
 *       - Bit[1]: Submodule 1 LDOK status
 *       - Bit[2]: Submodule 2 LDOK status
 *       - Bit[3]: Submodule 3 LDOK status
 *
 * @note Usage example:
 * @code
 *   uint16_t ldokStatus = FLEXPWM_GetLoadOkay(PWM0);
 *   if (ldokStatus & kFLEXPWM_SubmoduleMask_0) {
 *   }
 * @endcode
 *
 * @param base FlexPWM peripheral base address.
 * @return LDOK status bits (bit[3:0] correspond to submodules 3-0).
 *         Use flexpwm_submodule_mask_t enum values to check specific submodules.
 */
static inline uint16_t FLEXPWM_GetLoadOkay(PWM_Type *base)
{
    return (base->MCTRL & PWM_MCTRL_LDOK_MASK) >> PWM_MCTRL_LDOK_SHIFT;
}

/*!
 * @brief Set local FORCE_OUT event for a submodule.
 *
 * This function sets the SMxCTRL2[FORCE] bit to trigger a local FORCE_OUT event.
 * When a FORCE_OUT event occurs, several double-buffered registers immediately update:
 * - DTSRCSEL (PWM source selection)
 * - SWCOUT (software-controlled output values)
 * - MASK (output masking)
 * - MCTRL[IPOL] (complementary PWM source selection)
 *
 * Additionally, if CTRL2[FRCEN] is enabled and the counter is running, the counter
 * will be initialized to the INIT register value.
 *
 * @note FORCE_OUT trigger source:
 *       This function triggers a local FORCE_OUT event by setting CTRL2[FORCE].
 *       The FORCE_OUT event only occurs if CTRL2[FORCE_SEL] = 0 (local force selected).
 *       If FORCE_SEL selects a different source, setting FORCE has no effect.
 *
 * @note Counter initialization:
 *       The counter is reinitialized only if:
 *       - CTRL2[FRCEN] = 1 (force initialization enabled), AND
 *       - MCTRL[RUN] = 1 (counter running) OR CTRL2[CLK_SEL] = 2 (submodule 0 aux clock)
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 */
static inline void FLEXPWM_SetLocalForceOut(PWM_Type *base, uint8_t submodule)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].CTRL2 |= PWM_CTRL2_FORCE_MASK;
}

/*!
 * @brief Enable or disable counter initialization on FORCE_OUT event.
 *
 * This function controls whether FORCE_OUT events can trigger counter initialization
 * by configuring the CTRL2[FRCEN] bit. When enabled, the counter will be reset to
 * the INIT register value when local software forced event occurs.
 *
 * @note Counter initialization conditions:
 *       The counter is reinitialized only when ALL of the following conditions are met:
 *       - CTRL2[FRCEN] = 1 (enabled via this function), AND
 *       - A local FORCE_OUT event occurs (CTRL2[FORCE_SEL] = 0, CTRL2[FORCE] = 1)
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param enable Enable or disable counter force initialization:
 *               - true: FORCE_OUT events can trigger counter initialization (FRCEN = 1)
 *               - false: FORCE_OUT events do not affect counter initialization (FRCEN = 0)
 */
static inline void FLEXPWM_SetCounterForceInitialization(PWM_Type *base, uint8_t submodule, bool enable)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    uint16_t reg;
    uint16_t boolConvert = (enable == false) ? 0U : 1U;
    reg = base->SM[submodule].CTRL2;
    reg = (reg & MCUX_MASK_INVERT_16(PWM_CTRL2_FRCEN_MASK)) | PWM_CTRL2_FRCEN(boolConvert);
    base->SM[submodule].CTRL2 = reg;
}

/*!
 * @brief Enable PWM counter for specified submodules.
 *
 * This function enables the PWM counters for the specified submodules by setting MCTRL[RUN] bits.
 * When enabled, the counters start running and generating PWM waveforms.
 *
 * @note Effects of enabling counter (RUN=1):
 *       - Counter begins incrementing/decrementing according to configuration
 *       - PWM generation starts (if outputs are also enabled)
 *       - Reload events can occur at configured opportunities
 *       - FORCE_OUT can trigger counter initialization (if FRCEN enabled)
 *
 * @param base FlexPWM peripheral base address.
 * @param submoduleMask Submodule selection mask (OR'ed combination of flexpwm_submodule_mask_t).
 *                      bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_EnableSubmoduleCounter(PWM_Type *base, uint16_t submoduleMask)
{
    base->MCTRL |= PWM_MCTRL_RUN(submoduleMask);
}

/*!
 * @brief Disable PWM counter for specified submodules.
 *
 * This function disables the PWM counters for the specified submodules by clearing MCTRL[RUN] bits.
 * When disabled, the counters stop running but retain their configuration.
 *
 * @note Effects of disabling counter (RUN=0):
 *       - Counter stops incrementing/decrementing
 *       - PWM generation ceases (outputs hold last state or go to fault state)
 *       - Configuration registers remain intact
 *       - Fault clearing behavior changes (see fault protection documentation)
 *
 * @param base FlexPWM peripheral base address.
 * @param submoduleMask Submodule selection mask (OR'ed combination of flexpwm_submodule_mask_t).
 *                      bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_DisableSubmoduleCounter(PWM_Type *base, uint16_t submoduleMask)
{
    base->MCTRL &= MCUX_MASK_INVERT_16(PWM_MCTRL_RUN(submoduleMask));
}

/*!
 * @brief Enable PWM_A, PWM_B, PWM_X outputs for specified submodules.
 *
 * This function enables PWM outputs by setting the corresponding bits in the OUTEN register.
 * Each output (PWM_A, PWM_B, PWM_X) can be independently enabled for each submodule.
 *
 * @note OUTEN register layout (same as MASK register):
 *       - bit[11:8]: PWMA_EN - PWM_A output enable for submodules 3-0
 *       - bit[7:4]:  PWMB_EN - PWM_B output enable for submodules 3-0
 *       - bit[3:0]:  PWMX_EN - PWM_X output enable for submodules 3-0
 *
 * @note Prerequisites:
 *       Before enabling outputs, ensure:
 *       1. PWM waveform is configured (FLEXPWM_ConfigPWM)
 *       2. Counter is running (FLEXPWM_EnableSubmoduleCounter)
 *       3. Outputs are not masked (check MASK register)
 *
 * @param base FlexPWM peripheral base address.
 * @param aMask Submodule mask for PWM_A outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param bMask Submodule mask for PWM_B outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param xMask Submodule mask for PWM_X outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_EnablePWMOutput(PWM_Type *base, uint16_t aMask, uint16_t bMask, uint16_t xMask)
{
    base->OUTEN |= (PWM_OUTEN_PWMA_EN(aMask) | PWM_OUTEN_PWMB_EN(bMask) | PWM_OUTEN_PWMX_EN(xMask));
}

/*!
 * @brief Disable PWM_A, PWM_B, PWM_X outputs for specified submodules.
 *
 * This function disables PWM outputs by clearing the corresponding bits in the OUTEN register.
 * When an output is disabled, the pin is released from FlexPWM control and may be controlled
 * by other peripherals or GPIO.
 *
 * @note Output disable effects:
 *       - Pin is tri-stated or controlled by GPIO/other peripherals
 *       - PWM waveform generation continues internally
 *       - Re-enabling the output will resume PWM operation seamlessly
 *
 * @param base FlexPWM peripheral base address.
 * @param aMask Submodule mask for PWM_A outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param bMask Submodule mask for PWM_B outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 * @param xMask Submodule mask for PWM_X outputs (OR'ed combination of flexpwm_submodule_mask_t).
 *              bit[0]=SM0, bit[1]=SM1, bit[2]=SM2, bit[3]=SM3.
 */
static inline void FLEXPWM_DisablePWMOutput(PWM_Type *base, uint16_t aMask, uint16_t bMask, uint16_t xMask)
{
    uint16_t mask = (PWM_OUTEN_PWMA_EN(aMask) | PWM_OUTEN_PWMB_EN(bMask) | PWM_OUTEN_PWMX_EN(xMask));
    base->OUTEN &= MCUX_MASK_INVERT_16(mask);
}

#if (defined(FSL_FEATURE_PWM_MCTRL2_HAS_WRPROT_BITFIELD) && FSL_FEATURE_PWM_MCTRL2_HAS_WRPROT_BITFIELD)
/*!  
 * @brief Set FlexPWM write protection mode.
 *
 * This function configures the write protection for FlexPWM registers by setting MCTRL2[WRPROT].
 * Write protection prevents accidental modification of critical PWM configuration registers.
 *
 * @note Write protection modes:
 *       - kFLEXPWM_WriteProtect_Off: Write protection is disabled (default after reset)
 *       - kFLEXPWM_WriteProtect_On: Write protection is enabled but can be disabled
 *       - kFLEXPWM_WriteProtect_OffLocked: Write protection is disabled and locked until chip reset
 *       - kFLEXPWM_WriteProtect_OnLocked: Write protection is enabled and locked until chip reset
 *
 * @note Once a locked mode is set (OffLocked or OnLocked), the write protection state cannot
 *       be changed until the next chip reset. Use locked modes for safety-critical applications.
 *
 * @param base FlexPWM peripheral base address.
 * @param config Write protection mode selection.
 */
static inline void FLEXPWM_SetWriteProtection(PWM_Type *base, flexpwm_write_protect_t config)
{
    base->MCTRL2 = (base->MCTRL2 & MCUX_MASK_INVERT_16(PWM_MCTRL2_WRPROT_MASK)) | PWM_MCTRL2_WRPROT(config);
}
#endif
/*! @} */

/*!
 * @name Interrupt and Status
 * @{
 */

/*!
 * @brief Enable FlexPWM submodule interrupts.
 *
 * This function enables the specified interrupt sources for a FlexPWM submodule by setting
 * the corresponding bits in the SMxINTEN register.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param mask Interrupt enable mask (OR'ed combination of _flexpwm_submodule_interrupt_enable flags).
 */
static inline void FLEXPWM_EnableSubmoduleInterrupts(PWM_Type *base, uint8_t submodule, uint16_t mask)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].INTEN |= mask;
}

/*!
 * @brief Disable FlexPWM submodule interrupts.
 *
 * This function disables the specified interrupt sources for a FlexPWM submodule by clearing
 * the corresponding bits in the SMxINTEN register.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param mask Interrupt disable mask (OR'ed combination of _flexpwm_submodule_interrupt_enable flags).
 */
static inline void FLEXPWM_DisableSubmoduleInterrupts(PWM_Type *base, uint8_t submodule, uint16_t mask)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].INTEN &= MCUX_MASK_INVERT_16(mask);
}

/*!
 * @brief Get FlexPWM submodule status flags.
 *
 * This function returns the current status flags from the SMxSTS register.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @return Current status flags (combination of _flexpwm_submodule_status_flag values).
 */
static inline uint16_t FLEXPWM_GetSubmoduleStatusFlags(PWM_Type *base, uint8_t submodule)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    return base->SM[submodule].STS;
}

/*!
 * @brief Clear FlexPWM submodule status flags.
 *
 * This function clears the specified status flags in the SMxSTS register using the
 * write-1-to-clear (W1C) mechanism.
 *
 * @note Do not attempt to clear kFLEXPWM_RegisterUpdatedFlag (RUF) as it is read-only.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param mask Status flag clear mask (OR'ed combination of _flexpwm_submodule_status_flag values).
 *             To clear a flag, set the corresponding bit to 1 in the mask.
 */
static inline void FLEXPWM_ClearSubmoduleStatusFlags(PWM_Type *base, uint8_t submodule, uint16_t mask)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);
    base->SM[submodule].STS = mask;
}

/*!
 * @brief Enable FlexPWM fault interrupts.
 *
 * This function enables the specified fault interrupt sources by setting the corresponding
 * bits in the FCTRL[FIE] field.
 *
 * @note For dual-channel platforms (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1):
 *       The same mask bit values are used for both fault channels. The faultChannel parameter
 *       determines which set of fault inputs is controlled:
 *       - faultChannel = 0: Controls FAULT0-3 interrupts
 *       - faultChannel = 1: Controls FAULT4-7 interrupts
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number:
 *                     - 0: Fault channel 0 (FAULT0-3)
 *                     - 1: Fault channel 1 (FAULT4-7, if supported)
 * @param mask Fault interrupt enable mask (OR'ed combination of _flexpwm_fault_interrupt_enable flags).
 */
static inline void FLEXPWM_EnableFaultInterrupts(PWM_Type *base, uint8_t faultChannel, uint16_t mask)
{
    assert(faultChannel < (uint8_t)FSL_FEATURE_PWM_FAULT_CH_COUNT);
    uint16_t reg = *FLEXPWM_GET_FCTRL_REG(base, faultChannel);
    reg |= (mask & PWM_FCTRL_FIE_MASK);
    *FLEXPWM_GET_FCTRL_REG(base, faultChannel) = reg;
}

/*!
 * @brief Disable FlexPWM fault interrupts.
 *
 * This function disables the specified fault interrupt sources by clearing the corresponding
 * bits in the FCTRL[FIE] field.
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number:
 *                     - 0: Fault channel 0 (FAULT0-3)
 *                     - 1: Fault channel 1 (FAULT4-7, if supported)
 * @param mask Fault interrupt disable mask (OR'ed combination of _flexpwm_fault_interrupt_enable flags).
 */
static inline void FLEXPWM_DisableFaultInterrupts(PWM_Type *base, uint8_t faultChannel, uint16_t mask)
{
    assert(faultChannel < (uint8_t)FSL_FEATURE_PWM_FAULT_CH_COUNT);
    uint16_t reg = *FLEXPWM_GET_FCTRL_REG(base, faultChannel);
    reg &= MCUX_MASK_INVERT_16(mask & PWM_FCTRL_FIE_MASK);
    *FLEXPWM_GET_FCTRL_REG(base, faultChannel) = reg;
}

/*!
 * @brief Get FlexPWM fault status flags.
 *
 * This function returns the current fault status flags (FFLAG bits) from the FSTS register.
 * These are latched flags that indicate a fault event has occurred.
 *
 * @note To check real-time hardware pin status (rather than latched flags), use
 *       FLEXPWM_GetFaultFilteredPinStatusFlags() instead.
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number:
 *                     - 0: Fault channel 0 (FAULT0-3)
 *                     - 1: Fault channel 1 (FAULT4-7, if supported)
 * @return Current fault flags (combination of _flexpwm_fault_status_flag values).
 */
static inline uint16_t FLEXPWM_GetFaultStatusFlags(PWM_Type *base, uint8_t faultChannel)
{
    assert(faultChannel < (uint8_t)FSL_FEATURE_PWM_FAULT_CH_COUNT);
    uint16_t reg;
    reg = *FLEXPWM_GET_FSTS_REG(base, faultChannel);
    reg &= (PWM_FSTS_FFLAG_MASK);
    return reg;
}

/*!
 * @brief Clear FlexPWM fault status flags.
 *
 * This function clears the specified fault status flags (FFLAG bits) in the FSTS register
 * using the write-1-to-clear (W1C) mechanism.
 *
 * @note Clearing FFLAG does not automatically re-enable PWM outputs. The re-enable timing
 *       depends on fault clearing mode (FAUTO), safety mode (FSAFE), recovery timing
 *       (FHALF/FFULL), and the state of FFPIN (filtered pin status).
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number:
 *                     - 0: Fault channel 0 (FAULT0-3)
 *                     - 1: Fault channel 1 (FAULT4-7, if supported)
 * @param mask Fault flag clear mask (OR'ed combination of _flexpwm_fault_status_flag values).
 *             To clear a flag, set the corresponding bit to 1 in the mask.
 */
static inline void FLEXPWM_ClearFaultStatusFlags(PWM_Type *base, uint8_t faultChannel, uint16_t mask)
{
    assert(faultChannel < (uint8_t)FSL_FEATURE_PWM_FAULT_CH_COUNT);
    uint16_t reg;
    reg = *FLEXPWM_GET_FSTS_REG(base, faultChannel);
    reg &= MCUX_MASK_INVERT_16(PWM_FSTS_FFLAG_MASK);
    reg |= (mask & PWM_FSTS_FFLAG_MASK);
    *FLEXPWM_GET_FSTS_REG(base, faultChannel) = reg;
}

/*!
 * @brief Get FlexPWM filtered fault pin status.
 *
 * This function returns the real-time status of fault pins after filtering (FFPIN bits)
 * from the FSTS register. These are read-only hardware status bits that reflect the
 * current state of external fault signals.
 *
 * @note Key differences:
 *       - FFLAG: Software-clearable latched flag (historical event - "a fault occurred")
 *       - FFPIN: Read-only real-time status (current state - "fault is active now")
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number:
 *                     - 0: Fault channel 0 (FAULT0-3 pins)
 *                     - 1: Fault channel 1 (FAULT4-7 pins, if supported)
 * @return Current filtered fault pin status (combination of _flexpwm_fault_pin_status values).
 */
static inline uint16_t FLEXPWM_GetFaultFilteredPinStatusFlags(PWM_Type *base, uint8_t faultChannel)
{
    assert(faultChannel < (uint8_t)FSL_FEATURE_PWM_FAULT_CH_COUNT);
    return (*FLEXPWM_GET_FSTS_REG(base, faultChannel)) & PWM_FSTS_FFPIN_MASK;
}

/*! @} */

/*!
 * @name DMA
 * @{
 */

/*!
 * @brief Configures the DMA control strategy for a FlexPWM submodule.
 *
 * This function configures the DMA trigger source and FIFO watermark logic.
 * These settings define the DMA request generation strategy and should
 * typically be configured once during initialization.
 *
 * @note This function only configures CAPTDE[7:6] and FAND bits in SMxDMAEN register.
 *       To enable/disable individual DMA channels at runtime, use FLEXPWM_EnableDMA()
 *       and FLEXPWM_DisableDMA().
 *
 * @note Prerequisites:
 *       Before calling this function, ensure:
 *       1. FIFO watermark levels are configured in FLEXPWM_ConfigInputCapture()
 *       2. Capture channels are properly configured if using capture DMA
 *
 * @param base FlexPWM peripheral base address
 * @param submodule FlexPWM submodule number (0-3)
 * @param config Pointer to DMA configuration structure
 */
void FLEXPWM_ConfigDMA(PWM_Type *base, uint8_t submodule, const flexpwm_dma_config_t *config);

/*!
 * @brief Enable FlexPWM submodule DMA requests.
 *
 * This function enables DMA request generation for the specified channels.
 * It controls the VALDE bit (VALx/FRACVALx write) and capture channel
 * enables (CX0DE, CX1DE, CB0DE, CB1DE, CA0DE, CA1DE).
 *
 * @note Before calling this function, ensure FLEXPWM_ConfigDMA() has been
 *       called to set up the DMA trigger strategy.
 *
 * @param base FlexPWM peripheral base address
 * @param submodule FlexPWM submodule number (0-3)
 * @param mask Bit mask of DMA enable flags (OR'ed combination of _flexpwm_dma_enable)
 */
static inline void FLEXPWM_EnableDMA(PWM_Type *base, uint8_t submodule, uint16_t mask)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    /* Set specified DMA enable bits (supports VALDE and all capture channels) */
    base->SM[submodule].DMAEN |= mask;
}

/*!
 * @brief Disable FlexPWM submodule DMA requests.
 *
 * This function disables DMA request generation for the specified channels.
 *
 * @param base FlexPWM peripheral base address
 * @param submodule FlexPWM submodule number (0-3)
 * @param mask Bit mask of DMA enable flags (OR'ed combination of _flexpwm_dma_enable)
 */
static inline void FLEXPWM_DisableDMA(PWM_Type *base, uint8_t submodule, uint16_t mask)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    /* Clear specified DMA enable bits */
    base->SM[submodule].DMAEN &= MCUX_MASK_INVERT_16(mask);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_FLEXPWM_H_ */
