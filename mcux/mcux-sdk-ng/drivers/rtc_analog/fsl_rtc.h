/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_RTC_H_
#define FSL_RTC_H_

#include "fsl_common.h"

/*! @file fsl_rtc.h */

/*!
 * @addtogroup rtc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_RTC_DRIVER_VERSION (MAKE_VERSION(1, 0, 0)) /*!< Version 1.0.0 */
/*! @} */

/*! @name RTC tamper */
/*! @{ */
/* Size of the secure key in bytes, 256bits */
#define RTC_SECURE_KEY_SIZE_BYTES (32U)
/* Number of 32-bit registers for the secure key */
#define RTC_SECURE_KEY_REG_COUNT (RTC_SECURE_KEY_SIZE_BYTES / 4U)
/* Number of tamper inputs supported by the rtc_tamper_config_t structure */
#define RTC_MAX_TAMPER_INPUTS (2U)
/*! @} */

/*! @brief RTC wait inteface ready timeout  */
#ifndef RTC_WAIT_INTERFACE_READY_TIMEOUT
#ifdef CONFIG_RTC_WAIT_INTERFACE_READY_TIMEOUT
#define RTC_WAIT_INTERFACE_READY_TIMEOUT CONFIG_RTC_WAIT_INTERFACE_READY_TIMEOUT
#else
#define RTC_WAIT_INTERFACE_READY_TIMEOUT 0U
#endif
#endif

/*! @brief RTC wait read counter latched timeout  */
#ifndef RTC_WAIT_READ_COUNTER_LATCHED_READY
#ifdef CONFIG_RTC_WAIT_READ_COUNTER_LATCHED_READY
#define RTC_WAIT_READ_COUNTER_LATCHED_READY CONFIG_RTC_WAIT_READ_COUNTER_LATCHED_READY
#else
#define RTC_WAIT_READ_COUNTER_LATCHED_READY 0U
#endif
#endif

/*! @brief RTC wait secure key ready timeout  */
#ifndef RTC_WAIT_SECURE_KEY_READY_TIMEOUT
#ifdef CONFIG_RTC_WAIT_SECURE_KEY_READY_TIMEOUT
#define RTC_WAIT_SECURE_KEY_READY_TIMEOUT CONFIG_RTC_WAIT_SECURE_KEY_READY_TIMEOUT
#else
#define RTC_WAIT_SECURE_KEY_READY_TIMEOUT 0U
#endif
#endif

/*! @brief RTC operating modes. */
typedef enum _rtc_operating_mode
{
    kRTC_ModeTimeDate           = 0U, /*!< RTC operates in Time/Date counting mode. */
    kRTC_ModeFreeRunningCounter = 1U  /*!< RTC operates as a free-running counter. */
} rtc_operating_mode_t;

/*! @brief RTC date and time structure. */
typedef struct _rtc_datetime
{
    uint16_t year;             /*!< Year (e.g., 2023) */
    uint8_t month;             /*!< Month (1-12) */
    uint8_t day;               /*!< Day of the month (1-31) */
    uint8_t hour;              /*!< Hour (0-23) */
    uint8_t minute;            /*!< Minute (0-59) */
    uint8_t second;            /*!< Second (0-59) */
    uint8_t hundredthOfSecond; /*!< Hundredth of a second (0-99) */
    uint8_t dayOfWeek;         /*!< Day of the week (e.g., 0 for Sunday, 1 for Monday, etc.) */
} rtc_datetime_t;

/*! @brief RTC Alarm identifiers. Corresponds to Alarm 0, 1, 2. */
typedef enum _rtc_alarm_id
{
    kRTC_Alarm_0 = 0U, /*!< Identifier for Alarm 0 */
    kRTC_Alarm_1 = 1U, /*!< Identifier for Alarm 1 */
    kRTC_Alarm_2 = 2U  /*!< Identifier for Alarm 2 */
} rtc_alarm_id_t;

/*! @brief RTC alarm operational modes. */
typedef enum _rtc_alarm_mode
{
    kRTC_AlarmModeSingleShot =
        0U,                   /*!< Alarm triggers once and then (typically) disables itself or requires re-arming. */
    kRTC_AlarmModeRepeat = 1U /*!< Alarm triggers repeatedly based on its configuration (e.g., daily, weekly). */
} rtc_alarm_mode_t;

/*!
 * @brief RTC alarm mask fields.
 * Used with rtc_bcd_alarm_config_t's mask member. Set a bit to 1 to ignore the corresponding field for alarm matching.
 */
typedef enum _rtc_alarm_mask_fields
{
    kRTC_AlarmMaskIgnoreNothing   = 0U,        /*!< Match all fields specified in alarm time/date. */
    kRTC_AlarmMaskIgnoreSecond    = (1U << 0), /*!< Ignore seconds field for alarm match. */
    kRTC_AlarmMaskIgnoreMinute    = (1U << 1), /*!< Ignore minutes field for alarm match. */
    kRTC_AlarmMaskIgnoreHour      = (1U << 2), /*!< Ignore hours field for alarm match. */
    kRTC_AlarmMaskIgnoreDay       = (1U << 3), /*!< Ignore day of the month field for alarm match. */
    kRTC_AlarmMaskIgnoreDayOfWeek = (1U << 4), /*!< Ignore day of the week field for alarm match. */
    kRTC_AlarmMaskIgnoreMonth     = (1U << 5), /*!< Ignore month field for alarm match. */
    kRTC_AlarmMaskIgnoreAll       = 0x3FU      /*!< Ignore all field for alarm match. */
} rtc_alarm_mask_fields_t;

/*! @brief RTC bcd alarm configuration structure. */
typedef struct _rtc_alarm_config
{
    uint8_t hour;              /*!< Alarm hour (0-23). Relevant if not masked. */
    uint8_t minute;            /*!< Alarm minute (0-59). Relevant if not masked. */
    uint8_t second;            /*!< Alarm second (0-59). Relevant if not masked. */
    uint8_t hundredthOfSecond; /*!< Alarm hundredth of second (0-99). */
    uint8_t day;               /*!< Alarm day of the month (1-31). Relevant if not masked. */
    uint8_t dayOfWeek;         /*!< Alarm day of the week. Sunday is 0, Monday is 1. Relevant if not masked. */
    uint8_t month;             /*!< Alarm month (1-12). Relevant if not masked. */
    uint8_t mask;          /*!< Alarm mask, it a logical OR of members of the enumeration ::rtc_alarm_mask_fields_t. */
    rtc_alarm_mode_t mode; /*!< Alarm mode: kRTC_AlarmModeSingleShot or kRTC_AlarmModeRepeat. */
    bool enable; /*!< Initial enable state for this alarm when configured. True to enable, false to disable. */
} rtc_bcd_alarm_config_t;

/*! @brief RTC free run mode alarm  */
typedef struct _rtc_free_run_alarm_config
{
    uint64_t alarmCounter; /*!< Alarm counter value. */
    rtc_alarm_mode_t mode; /*!< Alarm mode: kRTC_AlarmModeSingleShot or kRTC_AlarmModeRepeat. */
    bool enable; /*!< Initial enable state for this alarm when configured. True to enable, false to disable. */
} rtc_free_run_alarm_config_t;

/*! @brief RTC Tamper input identifiers. Corresponds to Tamper 0, 1. */
typedef enum _rtc_tamper_input_id
{
    kRTC_TamperInput0 = 0U, /*!< Enable Tamper input 0. */
    kRTC_TamperInput1 = 1U, /*!< Enable Tamper input 1. */
} rtc_tamper_input_id_t;

/*! @brief RTC tamper input filter configuration. */
typedef enum _rtc_tamper_filter
{
    kRTC_TamperFilterDisabled = 0U, /*!< Digital filter disabled for this tamper input. */
    kRTC_TamperFilterEnabled  = 1U, /*!< Digital filter enabled for this tamper input. */
} rtc_tamper_filter_t;

/*! @brief RTC tamper input trigger level. */
typedef enum _rtc_tamper_polarity
{
    kRTC_TamperPolarityLow  = 0U, /*!< Tamper event triggered on a low level or falling edge. */
    kRTC_TamperPolarityHigh = 1U  /*!< Tamper event triggered on a high level or rising edge. */
} rtc_tamper_polarity_t;

/*! @brief RTC tamper input pull-up configuration. */
typedef enum _rtc_tamper_pullup
{
    kRTC_TamperPullupDisabled = 0U, /*!< No pull-up resistor enabled for this tamper input. */
    kRTC_TamperPullupEnabled  = 1U  /*!< Pull-up resistor enabled for this tamper input. */
} rtc_tamper_pullup_t;

/*! @brief RTC tamper input configuration structure. */
typedef struct _rtc_tamper_input_config
{
    bool enableTamperInput; /*!< True to enable this tamper input, false to disable. (Maps to TAMP_CTRL[TAMP_EN] bit) */
    rtc_tamper_polarity_t polarity; /*!< Trigger level for this tamper input. */
    rtc_tamper_pullup_t pullup;     /*!< Pull-up configuration for this tamper input. */
    rtc_tamper_filter_t filter;     /*!< Digital filter configuration for this tamper input. */
} rtc_tamper_input_config_t;

/*! @brief RTC global tamper detection configuration structure. */
typedef struct _rtc_tamper_config
{
    bool enableGlobalTamper;                        /*!< Master enable for the tamper detection sub-module. */
    rtc_tamper_input_config_t tamperInputConfig[2]; /*!< Configuration for the tamper input pins. This structure is used
                                                    to configure each tamper input pin's behavior, such as trigger
                                                    level, pull-up, and filtering. */
} rtc_tamper_config_t;

/*! @brief RTC alive detector configuration structure. */
typedef struct _rtc_alive_detector_config
{
    bool enableAliveDetector;        /*!< True to enable the RTC alive detector, false to disable. */
    bool bypassAnalogAliveMechanism; /*!< Bypass the RTC analog alive mechanism, implemented at the PAC. After
                                        de-activation of the SMM reset this value is sample back value from PAC. */
    uint8_t mechanismPeriod; /*!< Define the length of the active period of the Alive Detector Mechanism in 2KHz clock
                                cycles */
} rtc_alive_detector_config_t;

/*! @brief RTC general configuration structure. */
typedef struct _rtc_config
{
    rtc_operating_mode_t operatingMode; /*!< RTC operating mode: Time/Date or Free-Running Counter. */
    bool enableXtal32;                  /*!< Enable/disable the 32kHz crystal oscillator circuitry. True to enable. */
    bool enable2kHzOutputSMM;           /*!< Enable/disable 2kHz output towards SMM. True to enable. */
    bool alarmInitialEnable[3];         /*!< Initial enable state for Alarm 0, 1, 2. True to enable. */
    bool enableWatchdog;                /*!< Initial enable state for the Watchdog Timer. True to enable. */
    uint32_t watchdogTimeoutValue; /*!< Watchdog Timer timeout value (units are MCU specific, e.g., seconds or RTC clock
                                      cycles). */
    rtc_tamper_config_t tamperConfig;                /*!< Tamper detection configuration. */
    rtc_alive_detector_config_t aliveDetectorConfig; /*!< RTC alive detector configuration. */
} rtc_config_t;

/*! @brief Callback type identifiers for RTC events. */
typedef enum _rtc_callback_type
{
    kRTC_Alarm0Callback,   /*!< Alarm 0 interrupt callback type */
    kRTC_Alarm1Callback,   /*!< Alarm 1 interrupt callback type */
    kRTC_Alarm2Callback,   /*!< Alarm 2 interrupt callback type */
    kRTC_XtalFailCallback, /*!< XTAL Fail interrupt callback type */
    kRTC_WatchDogCallback, /*!< WatchDog timer timeout interrupt callback type */
    kRTC_Tamper0Callback,  /*!< Tamper 0 detection interrupt callback type */
    kRTC_Tamper1Callback   /*!< Tamper 1 detection interrupt callback type */
} rtc_callback_type_t;

/*! @brief RTC interrupt enable masks. Use bitwise OR to enable multiple interrupts. */
typedef enum _rtc_interrupt_enable
{
    kRTC_Alarm0InterruptEnable   = RTC_INT_ALARM0_IE_MASK,       /*!< Enable Alarm 0 interrupt. */
    kRTC_Alarm1InterruptEnable   = RTC_INT_ALARM1_IE_MASK,       /*!< Enable Alarm 1 interrupt. */
    kRTC_Alarm2InterruptEnable   = RTC_INT_ALARM2_IE_MASK,       /*!< Enable Alarm 2 interrupt. */
    kRTC_XtalFailInterruptEnable = RTC_INT_XTAL_FAIL_IE_MASK,    /*!< Enable XTAL Fail interrupt. */
    kRTC_WatchdogInterruptEnable = RTC_INT_WDT_IE_MASK,          /*!< Enable Watchdog timeout interrupt. */
    kRTC_Tamper0InterruptEnable  = RTC_INT_TMP_DET_PIN0_IE_MASK, /*!< Enable Tamper 0 detection interrupt. */
    kRTC_Tamper1InterruptEnable  = RTC_INT_TMP_DET_PIN1_IE_MASK, /*!< Enable Tamper 1 detection interrupt. */
    kRTC_AllInterruptsEnable     = (RTC_INT_ALARM0_IE_MASK | RTC_INT_ALARM1_IE_MASK | RTC_INT_ALARM2_IE_MASK |
                                RTC_INT_XTAL_FAIL_IE_MASK | RTC_INT_WDT_IE_MASK | RTC_INT_TMP_DET_PIN0_IE_MASK |
                                RTC_INT_TMP_DET_PIN1_IE_MASK) /*!< Enable all RTC interrupts. */
} rtc_interrupt_enable_t;

/*! @brief RTC status flags. Use bitwise OR to check multiple flags. */
typedef enum _rtc_status_flags
{
    kRTC_Alarm0InterruptFlag   = RTC_INT_ALARM0_IF_MASK,     /*!< Alarm 0 flag. */
    kRTC_Alarm1InterruptFlag   = RTC_INT_ALARM1_IF_MASK,     /*!< Alarm 1 flag. */
    kRTC_Alarm2InterruptFlag   = RTC_INT_ALARM2_IF_MASK,     /*!< Alarm 2 flag. */
    kRTC_XtalFailInterruptFlag = RTC_INT_XTAL_FAIL_IF_MASK,  /*!< XTAL Fail flag. */
    kRTC_WatchdogInterruptFlag = RTC_INT_WDT_IF_MASK,        /*!< Watchdog timeout flag. */
    kRTC_Tamper0InterruptFlag  = RTC_INT_TAMP_DET_PIN0_MASK, /*!< Tamper 0 detection flag. */
    kRTC_Tamper1InterruptFlag  = RTC_INT_TAMP_DET_PIN1_MASK, /*!< Tamper 1 detection flag. */
    kRTC_AllStatusFlags        = (RTC_INT_ALARM0_IF_MASK | RTC_INT_ALARM1_IF_MASK | RTC_INT_ALARM2_IF_MASK |
                           RTC_INT_XTAL_FAIL_IF_MASK | RTC_INT_WDT_IF_MASK | RTC_INT_TAMP_DET_PIN0_MASK |
                           RTC_INT_TAMP_DET_PIN1_MASK) /*!< Mask for all RTC status flags. */
} rtc_status_flags_t;

/*! @brief RTC callback function pointer type. */
typedef void (*rtc_callback_t)(rtc_callback_type_t type);

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
 * @brief Fills the RTC configuration structure with default values.
 *
 * The default values are chosen for safe and common startup behavior.
 * For example:
 * @code
 *  config->operatingMode                               = kRTC_ModeTimeDate;
 *  config->enableXtal32                                = true;
 *  config->enable2kHzOutputSMM                         = false;
 *  config->alarmInitialEnable[0]                       = false;
 *  config->alarmInitialEnable[1]                       = false;
 *  config->alarmInitialEnable[2]                       = false;
 *  config->enableWatchdog                              = false;
 *  config->watchdogTimeoutValue                        = 0U;
 *  config->tamperConfig.enableGlobalTamper             = false;
 *  config->tamperConfig.tamperInputConfig[0].enableTamperInput = false;
 *  config->tamperConfig.tamperInputConfig[0].polarity = kRTC_TamperPolarityLow;
 *  config->tamperConfig.tamperInputConfig[0].pullup = kRTC_TamperPullupDisabled;
 *  config->tamperConfig.tamperInputConfig[0].filter = kRTC_TamperFilterDisabled;
 *  config->tamperConfig.tamperInputConfig[1].enableTamperInput = false;
 *  config->tamperConfig.tamperInputConfig[1].polarity = kRTC_TamperPolarityLow;
 *  config->tamperConfig.tamperInputConfig[1].pullup = kRTC_TamperPullupDisabled;
 *  config->tamperConfig.tamperInputConfig[1].filter = kRTC_TamperFilterDisabled;
 *  config->aliveDetectorConfig.enableAliveDetector     = false;
 *  config->aliveDetectorConfig.bypassAnalogAliveMechanism = false;
 *  config->aliveDetectorConfig.mechanismPeriod          = 0U;
 * @endcode
 * This function should be called before RTC_Init() if custom configuration is not fully provided.
 *
 * @param config Pointer to the rtc_config_t structure to be filled.
 */
void RTC_GetDefaultConfig(rtc_config_t *config);

/*!
 * @brief Initializes the RTC peripheral.
 *
 * This function configures the RTC module according to the settings provided in the config structure.
 * It setups initial operating mode, watchdog, tamper detection, and alive detector.
 *
 * @param base RTC peripheral base address.
 * @param config Pointer to the user-defined rtc_config_t structure.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready,
 */
status_t RTC_Init(RTC_Type *base, const rtc_config_t *config);

/*!
 * @brief De-initializes the RTC peripheral.
 *
 * This function resets RTC registers to a default state and stops the RTC.
 *
 * @param base RTC peripheral base address.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_Deinit(RTC_Type *base);

/*! @}*/

/*!
 * @name Timer Start and Stop
 * @{
 */

/*!
 * @brief Starts the RTC time counter.
 *
 * @param base RTC peripheral base address
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_StartTimer(RTC_Type *base);

/*!
 * @brief Stops the RTC time counter.
 *
 * @param base RTC peripheral base address
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_StopTimer(RTC_Type *base);

/*! @}*/

/*!
 * @name Time and Date Operations (Time/Date Mode)
 * @{
 */

/*!
 * @brief Sets the current RTC date and time.
 *
 * Validates the provided date and time before setting. If the input is invalid,
 * an error status is returned.
 *
 * @param base RTC peripheral base address.
 * @param datetime Pointer to the rtc_datetime_t structure containing the new date and time.
 * @return kStatus_Success if the operation was successful, kStatus_Fail if RTC is not working in time date mode,
 * kStatus_InvalidArgument if the input was invalid, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_SetDatetime(RTC_Type *base, const rtc_datetime_t *datetime);

/*!
 * @brief Retrieves the current RTC date and time.
 *
 * @param base RTC peripheral base address.
 * @param datetime Pointer to the rtc_datetime_t structure to store the current date and time.
 * @return kStatus_Success if the operation was successful, kStatus_InvalidArgument if not in time/date mode,
 * kStatus_Fail if a read collision occurred, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_GetDatetime(RTC_Type *base, rtc_datetime_t *datetime);

/*! @}*/

/*!
 * @name Free-Running Counter Operations (Free-Running Mode)
 * @{
 */

/*!
 * @brief Sets the initial value of the RTC free-running counter.
 *
 * This function is applicable only when the RTC is in Free-Running Counter mode.
 *
 * @param base RTC peripheral base address.
 * @param countValue The initial value to set for the counter.
 * @return kStatus_Success if the operation was successful, kStatus_InvalidArgument if the input was invalid, or
 * kStatus_Timeout if the interface is not ready.
 */
status_t RTC_SetFreeRunningCounter(RTC_Type *base, uint64_t countValue);

/*!
 * @brief Retrieves the current value of the RTC free-running counter.
 *
 * This function is applicable only when the RTC is in Free-Running Counter mode.
 *
 * @param base RTC peripheral base address.
 * @param countValue Pointer to a variable to store the current counter value.
 * @return kStatus_Success if the operation was successful, kStatus_InvalidArgument if not in free-running mode, or
 * kStatus_Fail if a read collision occurred, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_GetFreeRunningCounter(RTC_Type *base, uint64_t *countValue);

/*! @}*/

/*!
 * @name Alarm Functionality
 * @{
 */

/*!
 * @brief Configures a specific RTC BCD alarm.
 *
 * Sets the alarm time, date, mask, mode, and initial enable state.
 * The number of alarms is MCU-dependent (e.g., 3 alarms: Alarm0, Alarm1, Alarm2).
 *
 * @param base RTC peripheral base address.
 * @param alarmId The ID of the alarm to configure (e.g., kRTC_Alarm_0).
 * @param alarmConfig Pointer to the rtc_bcd_alarm_config_t structure with alarm settings.
 * @return kStatus_Success if the operation was successful, kStatus_InvalidArgument if the input was invalid, or
 * kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureBCDAlarm(RTC_Type *base, rtc_alarm_id_t alarmId, const rtc_bcd_alarm_config_t *alarmConfig);

/*!
 * @brief Configures a specific RTC free running mode alarm.
 *
 * Select the alarm id and set the alarm counter value
 *
 * @param base RTC peripheral base address.
 * @param alarmId The ID of the alarm to configure (e.g., kRTC_Alarm_0).
 * @param alarmConfig Pointer to the rtc_free_run_alarm_config_t structure with alarm settings.
 * @return kStatus_Success if the operation was successful, kStatus_InvalidArgument if the input was invalid,
 * or kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureFreeRunningAlarm(RTC_Type *base,
                                       rtc_alarm_id_t alarmId,
                                       const rtc_free_run_alarm_config_t *alarmConfig);

/*!
 * @brief Enables a specific RTC alarm.
 *
 * @param base RTC peripheral base address.
 * @param alarmId The ID of the alarm to enable.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableAlarm(RTC_Type *base, rtc_alarm_id_t alarmId);

/*!
 * @brief Disables a specific RTC alarm.
 *
 * @param base RTC peripheral base address.
 * @param alarmId The ID of the alarm to disable.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableAlarm(RTC_Type *base, rtc_alarm_id_t alarmId);

/*! @}*/

/*!
 * @name Interrupt Handling
 * @{
 */

/*!
 * @brief Enables specified RTC interrupt sources.
 *
 * @param base RTC peripheral base address.
 * @param mask Bitmask of interrupts to enable (see rtc_interrupt_enable_t).
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableInterrupts(RTC_Type *base, uint32_t mask);

/*!
 * @brief Disables specified RTC interrupt sources.
 *
 * @param base RTC peripheral base address.
 * @param mask Bitmask of interrupts to disable (see rtc_interrupt_enable_t).
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableInterrupts(RTC_Type *base, uint32_t mask);

/*!
 * @brief Gets the enabled RTC interrupts.
 *
 * @param base    RTC peripheral base address
 * @return enabled interrupts bitmask.
 */
static inline uint32_t RTC_GetEnabledInterrupts(RTC_Type *base)
{
    return (base->INT & (uint32_t)kRTC_AllInterruptsEnable);
}

/*!
 * @brief  Get the RTC interrupt flags.
 *
 * @param base    RTC peripheral base address
 * @return Occured interrupt flags bitmask.
 */
static inline uint32_t RTC_GetInterruptFlags(RTC_Type *base)
{
    return (base->INT & (uint32_t)kRTC_AllStatusFlags);
}

/*!
 * @brief Clears the RTC interrupt flags.
 *
 * @param base    RTC peripheral base address
 * @param mask    The interrupt flags to clear. This is a logical OR of members of the
 *                enumeration ::rtc_status_flags_t
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ClearInterruptFlags(RTC_Type *base, uint32_t mask);

/*!
 * @brief Register callback.
 *
 * @param cb_func   callback function
 */
void RTC_RegisterCallBack(rtc_callback_t cb_func);

/*! @}*/

/*!
 * @name Watchdog Timer Functionality
 * @{
 */

/*!
 * @brief Enables the RTC Watchdog Timer.
 * Assumes timeout is already configured via RTC_Init or RTC_SetWatchdogTimeout.
 *
 * @param base RTC peripheral base address.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableWatchdog(RTC_Type *base);

/*!
 * @brief Disables the RTC Watchdog Timer.
 *
 * @param base RTC peripheral base address.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableWatchdog(RTC_Type *base);

/*!
 * @brief Sets the timeout value for the RTC Watchdog Timer.
 *
 * @param base RTC peripheral base address.
 * @param timeoutValue The desired timeout value.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_SetWatchdogTimeout(RTC_Type *base, uint32_t timeoutValue);

/*!
 * @brief Refreshes the RTC Watchdog Timer.
 *
 * @param base RTC peripheral base address.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_RefreshWatchdog(RTC_Type *base);

/*! @}*/

/*!
 * @name Tamper Detection
 * @{
 */

/*!
 * @brief Configures a specific tamper detection input.
 *
 * This function sets up the tamper input configuration, including enabling/disabling the input,
 * setting polarity, pullup and filters.
 *
 * @param base RTC peripheral base address.
 * @param config Pointer to the rtc_tamper_config_t structure containing tamper input settings. This structure defines
 *                 the behavior of the tamper input, such as polarity, pull-up configuration, and filtering.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureTamperInput(RTC_Type *base,
                                  rtc_tamper_input_id_t tamperInputId,
                                  const rtc_tamper_input_config_t *config);

/*!
 * @brief Enables the specific tamper detection input pin.
 *
 * @param base RTC peripheral base address.
 * @param tamperInputId Bitmask of tamper inputs to enable.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableTamperInputPin(RTC_Type *base, rtc_tamper_input_id_t tamperInputId);

/*!
 * @brief Disable the specific tamper detection input pin.
 *
 * @param base RTC peripheral base address.
 * @param tamperInputId Bitmask of tamper inputs to disable.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableTamperInputPin(RTC_Type *base, rtc_tamper_input_id_t tamperInputId);

/*!
 * @brief Gets the latched RTC counter value at the time of the last tamper event.
 *
 * @param base RTC peripheral base address.
 * @param latchedCount Pointer to a variable where the latched counter value will be stored.
 * @return kStatus_Success if the operation was successful, kStatus_InvalidArgument if not in tamper mode,
 */
status_t RTC_GetTamperTimestamp(RTC_Type *base, uint64_t *latchedCount);

/*! @}*/

/*!
 * @name Key Store Operations
 * @{
 */

/*!
 * @brief Writes a key to the RTC's non-volatile storage.
 *
 * @param base RTC peripheral base address.
 * @param keyData Pointer to the key data to be written.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_WriteKey(RTC_Type *base, const uint32_t *keyData);

/*!
 * @brief Reads a key from the RTC's non-volatile storage.
 *
 * @param base RTC peripheral base address.
 * @param keyBuffer Pointer to a buffer where the key data will be stored.
 * @return kStatus_Success if the operation was successful, kStatus_Fail if SECURE_KEY_READY is not set.
 */
status_t RTC_ReadKey(RTC_Type *base, uint32_t *keyBuffer);

/*! @}*/

/*!
 * @name Alive detector configuration
 * @{
 */

/*!
 * @brief Enables the RTC alive detector.
 *
 * @param base RTC peripheral base address.
 * @param config Pointer to the rtc_alive_detector_config_t structure containing alive detector settings.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureAliveDetector(RTC_Type *base, const rtc_alive_detector_config_t *config);
/*! @}*/

/*!
 * @brief Alive detector enable
 *
 * @param base RTC peripheral base address.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 *
 */
status_t RTC_EnableAliveDetector(RTC_Type *base);

/*!
 * @brief Alive detector disable
 *
 * @param base RTC peripheral base address.
 * @return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 *
 */
status_t RTC_DisableAliveDetector(RTC_Type *base);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_RTC_H_ */
