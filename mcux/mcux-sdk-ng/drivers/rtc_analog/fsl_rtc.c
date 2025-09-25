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
#define FSL_COMPONENT_ID "platform.drivers.rtc"
#endif

#define YEAR_RANGE_START (2000U)
#define YEAR_RANGE_END   (2099U)

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Days in each month for a non-leap year */
static const uint8_t daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Days in each month for a leap year */
static const uint8_t daysInMonthLeapYear[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Callback function for RTC events */
static rtc_callback_t s_rtcCallback = NULL;

/* Last watchdog timeout value */
static uint32_t s_lastWdtTimeout = 0;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* Wait for RTC interface is idle. */
static inline status_t RTC_WaitForInterfaceReady(RTC_Type *base);

/* Check if the given year is a leap year */
static bool RTC_IsLeapYear(uint16_t year);

/* Check if the given date and time are valid */
static bool RTC_ValidateDateTime(const rtc_datetime_t *datetime);

/*!
 * @brief Get the RTC operating mode.
 *
 * @param base RTC peripheral base address.
 * @return The current RTC operating mode, kRTC_ModeTimeDate or kRTC_ModeFreeRunningCounter.
 */
static rtc_operating_mode_t RTC_GetOperatingMode(RTC_Type *base);

/*!
 * @brief Validates the BCD alarm configuration structure.
 *
 * This function checks if the alarm date/time fields are within valid ranges.
 * Fields that are masked (set to be ignored) in the alarm configuration are not validated.
 *
 * @param alarmConfig Pointer to alarm configuration structure to validate
 * @return true if configuration is valid, false if any enabled field is out of range
 */
static bool RTC_ValidateBCDAlarmDateTime(const rtc_bcd_alarm_config_t *alarmConfig);

/*!
 * @brief Validates the free running alarm configuration structure.
 *
 * This function validates:
 * 1. In single shot mode, counter must not exceed 40 bits (0xFFFFFFFFFF)
 * 2. In repeat mode, counter must not exceed 24 bits (0x00FFFFFF)
 *
 * @param alarmConfig Pointer to alarm configuration structure to validate
 * @return true if configuration is valid, false if counter value exceeds limits
 */
static bool RTC_ValidateFreeRunAlarmCounter(const rtc_free_run_alarm_config_t *alarmConfig);

/*******************************************************************************
 * Code
 ******************************************************************************/
static inline status_t RTC_WaitForInterfaceReady(RTC_Type *base)
{
#if defined(RTC_WAIT_INTERFACE_READY_TIMEOUT) && (RTC_WAIT_INTERFACE_READY_TIMEOUT > 0U)
    uint32_t timeout = RTC_WAIT_INTERFACE_READY_TIMEOUT;
#endif
    /* Wait until the RTC interface is ready (IF_READY bit is set) */
    while (!(base->CONFIG & RTC_CONFIG_IF_READY_MASK))
    {
#if defined(RTC_WAIT_INTERFACE_READY_TIMEOUT) && (RTC_WAIT_INTERFACE_READY_TIMEOUT > 0U)
        if ((--timeout) == 0U)
        {
            /* Timeout occurred */
            return kStatus_Timeout;
        }
#endif
    }
    return kStatus_Success;
}
static bool RTC_IsLeapYear(uint16_t year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

static bool RTC_ValidateDateTime(const rtc_datetime_t *datetime)
{
    /* Check input parameters */
    if (datetime == NULL)
    {
        return false;
    }

    /* Check year, month, day, hour, minute, second ranges */
    if ((datetime->year < 2000U) || (datetime->year > 2099U) || (datetime->month < 1U) || (datetime->month > 12U) ||
        (datetime->day < 1U) || (datetime->hour > 23U) || (datetime->minute > 59U) || (datetime->second > 59U) ||
        (datetime->hundredthOfSecond > 99U) || (datetime->dayOfWeek > 6U))
    {
        return false;
    }

    /* Check day of month validity based on month and leap year */
    const uint8_t *days = RTC_IsLeapYear(datetime->year) ? daysInMonthLeapYear : daysInMonth;
    if (datetime->day > days[datetime->month])
    {
        return false;
    }

    return true;
}

/*!
 * @brief Validates the BCD alarm configuration structure.
 *
 * This function checks if the alarm date/time fields are within valid ranges.
 * Fields that are masked (set to be ignored) in the alarm configuration are not validated.
 *
 * @param alarmConfig Pointer to alarm configuration structure to validate
 * @return true if configuration is valid, false if any enabled field is out of range
 */
static bool RTC_ValidateBCDAlarmDateTime(const rtc_bcd_alarm_config_t *alarmConfig)
{
    /* Check input parameters */
    if (alarmConfig == NULL)
    {
        return false;
    }

    /* Only validate fields that are not masked (i.e., will be used for matching) */

    /* Check month if not masked */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreMonth) == 0U)
    {
        if (alarmConfig->month < 1U || alarmConfig->month > 12U)
        {
            return false;
        }
    }

    /* Check day if not masked */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreDay) == 0U)
    {
        if (alarmConfig->day < 1U || alarmConfig->day > 31U)
        {
            return false;
        }
        /* Note: We can't validate exact day of month since we don't have year info for leap year check */
    }

    /* Check day of week if not masked */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreDayOfWeek) == 0U)
    {
        if (alarmConfig->dayOfWeek > 6U)
        {
            return false;
        }
    }

    /* Check hour if not masked */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreHour) == 0U)
    {
        if (alarmConfig->hour > 23U)
        {
            return false;
        }
    }

    /* Check minute if not masked */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreMinute) == 0U)
    {
        if (alarmConfig->minute > 59U)
        {
            return false;
        }
    }

    /* Check second if not masked */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreSecond) == 0U)
    {
        if (alarmConfig->second > 59U)
        {
            return false;
        }
    }

    if (alarmConfig->hundredthOfSecond > 99U)
    {
        return false;
    }

    return true;
}

static bool RTC_ValidateFreeRunAlarmCounter(const rtc_free_run_alarm_config_t *alarmConfig)
{
    /* Check input parameters */
    if (alarmConfig == NULL)
    {
        return false;
    }

    /* Validate counter value based on mode */
    if (alarmConfig->mode == kRTC_AlarmModeRepeat)
    {
        /* For repeat mode, counter must not exceed 24 bits (0x00FFFFFF) */
        if (alarmConfig->alarmCounter > 0x00FFFFFF)
        {
            return false;
        }
    }
    else
    {
        /* For single shot mode, counter must not exceed 40 bits (0xFFFFFFFFFF) */
        if (alarmConfig->alarmCounter > 0xFFFFFFFFFF)
        {
            return false;
        }
    }

    return true;
}

/*!
 * brief Get the RTC operating mode.
 *
 * param base RTC peripheral base address.
 * @return The current RTC operating mode.
 */
static rtc_operating_mode_t RTC_GetOperatingMode(RTC_Type *base)
{
    /* Wait until the RTC interface is ready (IF_READY bit is set) */
    while (!(base->CONFIG & RTC_CONFIG_IF_READY_MASK))
    {
    }
    return (base->CONFIG & RTC_CONFIG_FREE_RUNNING_MASK) ? kRTC_ModeFreeRunningCounter : kRTC_ModeTimeDate;
}

/*!
 * brief Fills the RTC configuration structure with default values.
 *
 * The default values are chosen for safe and common startup behavior.
 * For example:
 * code
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
 * endcode
 * This function should be called before RTC_Init() if custom configuration is not fully provided.
 *
 * param config Pointer to the rtc_config_t structure to be filled.
 */
void RTC_GetDefaultConfig(rtc_config_t *config)
{
    /* Check input parameters */
    assert(config != NULL);

    /* Clear the structure */
    (void)memset(config, 0, sizeof(rtc_config_t));

    /* Set default values */
    config->operatingMode                   = kRTC_ModeTimeDate;
    config->enableXtal32                    = true;
    config->enable2kHzOutputSMM             = true;
    config->alarmInitialEnable[0]           = false;
    config->alarmInitialEnable[1]           = false;
    config->alarmInitialEnable[2]           = false;
    config->enableWatchdog                  = false;
    config->watchdogTimeoutValue            = 0U;
    config->tamperConfig.enableGlobalTamper = false;
    for (uint8_t i = 0U; i < RTC_MAX_TAMPER_INPUTS; ++i)
    {
        config->tamperConfig.tamperInputConfig[i].enableTamperInput = false;
        config->tamperConfig.tamperInputConfig[i].polarity          = kRTC_TamperPolarityLow;
        config->tamperConfig.tamperInputConfig[i].pullup            = kRTC_TamperPullupDisabled;
        config->tamperConfig.tamperInputConfig[i].filter            = kRTC_TamperFilterDisabled;
    }
    config->aliveDetectorConfig.enableAliveDetector        = true;
    config->aliveDetectorConfig.bypassAnalogAliveMechanism = false;
    config->aliveDetectorConfig.mechanismPeriod            = 0U;
}

/*!
 * brief Initializes the RTC peripheral.
 *
 * This function configures the RTC module according to the settings provided in the config structure.
 * It setups initial operating mode, watchdog, tamper detection, and alive detector.
 *
 * param base RTC peripheral base address.
 * param config Pointer to the user-defined rtc_config_t structure.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready,
 */
status_t RTC_Init(RTC_Type *base, const rtc_config_t *config)
{
    /* Check input parameters */
    assert(config != NULL);
    uint32_t configReg     = 0;
    uint32_t aliveDetector = 0;

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* First perform a software reset */
    base->CONFIG |= RTC_CONFIG_SW_RST_MASK;
    base->CONFIG &= ~RTC_CONFIG_SW_RST_MASK;

    /* Configure operating mode and enable the RTC */
    configReg = RTC_CONFIG_FREE_RUNNING(config->operatingMode == kRTC_ModeFreeRunningCounter ? 1U : 0U) |
                RTC_CONFIG_ALARM0_DIS(config->alarmInitialEnable[0] ? 0U : 1U) |
                RTC_CONFIG_ALARM1_DIS(config->alarmInitialEnable[1] ? 0U : 1U) |
                RTC_CONFIG_ALARM2_DIS(config->alarmInitialEnable[2] ? 0U : 1U) |
                RTC_CONFIG_K_EN(config->enable2kHzOutputSMM ? 1U : 0U) |
                RTC_CONFIG_XTAL32_EN(config->enableXtal32 ? 1U : 0U);
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->CONFIG = configReg;
    /* Configure watchdog timer */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->WDT_SET_VA = RTC_WDT_SET_VA_WDT_CNTR(config->watchdogTimeoutValue);
    s_lastWdtTimeout = config->watchdogTimeoutValue;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* WDOG_EN can only be enabled when WDT_SET_VA has non zero value */
    base->CONFIG |= RTC_CONFIG_WDOG_EN(config->enableWatchdog ? 1U : 0U);

    /* Configure tamper detection */
    for (uint8_t i = 0U; i < RTC_MAX_TAMPER_INPUTS; ++i)
    {
        RTC_ConfigureTamperInput(base, (rtc_tamper_input_id_t)i, &config->tamperConfig.tamperInputConfig[i]);
    }
    /* Clear tamper interrupt flags */
    RTC_ClearInterruptFlags(base, kRTC_AllStatusFlags);

    aliveDetector = RTC_RTC_ALV_DTCT_DTCT_EN(config->aliveDetectorConfig.enableAliveDetector ? 1U : 0U) |
                    RTC_RTC_ALV_DTCT_BYPASS(config->aliveDetectorConfig.bypassAnalogAliveMechanism ? 1U : 0U) |
                    RTC_RTC_ALV_DTCT_ACTV_PRD(config->aliveDetectorConfig.mechanismPeriod);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->RTC_ALV_DTCT = aliveDetector;

    /* Enable RTC peripheral */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }

    return kStatus_Success;
}

/*!
 * brief De-initializes the RTC peripheral.
 *
 * This function resets RTC registers to a default state and stops the RTC.
 *
 * param base RTC peripheral base address.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_Deinit(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Disable the RTC */
    base->CONFIG &= ~RTC_CONFIG_EN_MASK;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Reset the RTC */
    base->CONFIG |= RTC_CONFIG_SW_RST_MASK;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->CONFIG &= ~RTC_CONFIG_SW_RST_MASK;

    return kStatus_Success;
}

/*!
 * brief Starts the RTC time counter.
 *
 * param base RTC peripheral base address
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_StartTimer(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }

    base->CONFIG |= RTC_CONFIG_EN_MASK;

    return kStatus_Success;
}

/*!
 * brief Stops the RTC time counter.
 *
 * param base RTC peripheral base address
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_StopTimer(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }

    base->CONFIG &= ~RTC_CONFIG_EN_MASK;

    return kStatus_Success;
}

/*!
 * brief Sets the current RTC date and time.
 *
 * Validates the provided date and time before setting. If the input is invalid,
 * an error status is returned.
 *
 * param base RTC peripheral base address.
 * param datetime Pointer to the rtc_datetime_t structure containing the new date and time.
 * return kStatus_Success if the operation was successful, kStatus_Fail if RTC is not working in time date mode,
 * kStatus_InvalidArgument if the input was invalid, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_SetDatetime(RTC_Type *base, const rtc_datetime_t *datetime)
{
    /* Check input parameters */
    assert(datetime != NULL);

    /* Check if in time date mode */
    if (RTC_GetOperatingMode(base) != kRTC_ModeTimeDate)
    {
        return kStatus_Fail;
    }

    if (!RTC_ValidateDateTime(datetime))
    {
        return kStatus_InvalidArgument;
    }

    /* Wait for RTC interface is ready */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set year */
    base->YEAR = RTC_YEAR_YEAR(datetime->year - YEAR_RANGE_START);

    /* Wait for RTC interface is ready */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set month and day */
    base->MONTH =
        RTC_MONTH_MONTH(datetime->month - 1) | RTC_MONTH_DAY(datetime->day - 1) | RTC_MONTH_WEEK(datetime->dayOfWeek);

    /* Wait for RTC interface is ready */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set hour and minute */
    base->HOUR_M = RTC_HOUR_M_HOUR(datetime->hour) | RTC_HOUR_M_MIN(datetime->minute);

    /* Wait for RTC interface is ready */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set second and hundredth - this write triggers the RTC update */
    base->SEC_HUND =
        RTC_SEC_HUND_SEC(datetime->second) | RTC_SEC_HUND_HUND(datetime->hundredthOfSecond); /* Set hundredths to 0 */

    return kStatus_Success;
}

/*!
 * brief Retrieves the current RTC date and time.
 *
 * param base RTC peripheral base address.
 * param datetime Pointer to the rtc_datetime_t structure to store the current date and time.
 * return kStatus_Success if the operation was successful, kStatus_InvalidArgument if not in time/date mode,
 * kStatus_Fail if a read collision occurred, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_GetDatetime(RTC_Type *base, rtc_datetime_t *datetime)
{
    /* Check input parameters */
    assert(datetime != NULL);

    /* Check if in time date mode */
    if (RTC_GetOperatingMode(base) != kRTC_ModeTimeDate)
    {
        return kStatus_InvalidArgument;
    }

    /* Wait for RTC interface is ready */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }

    /* Clear any previous read collision flag */
    base->CONFIG &= ~RTC_CONFIG_READ_COLL_MASK;

    /* Read year */
    datetime->year = YEAR_RANGE_START + ((base->YEAR & RTC_YEAR_YEAR_MASK) >> RTC_YEAR_YEAR_SHIFT);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Read month and day */
    uint32_t monthReg   = base->MONTH;
    datetime->month     = (uint8_t)((monthReg & RTC_MONTH_MONTH_MASK) >> RTC_MONTH_MONTH_SHIFT) + 1U;
    datetime->day       = (uint8_t)((monthReg & RTC_MONTH_DAY_MASK) >> RTC_MONTH_DAY_SHIFT) + 1U;
    datetime->dayOfWeek = (uint8_t)((monthReg & RTC_MONTH_WEEK_MASK) >> RTC_MONTH_WEEK_SHIFT);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Read hour and minute */
    uint32_t hourMinReg = base->HOUR_M;
    datetime->hour      = (uint8_t)((hourMinReg & RTC_HOUR_M_HOUR_MASK) >> RTC_HOUR_M_HOUR_SHIFT);
    datetime->minute    = (uint8_t)((hourMinReg & RTC_HOUR_M_MIN_MASK) >> RTC_HOUR_M_MIN_SHIFT);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Read second and hundredth */
    uint32_t secondHundredth    = base->SEC_HUND;
    datetime->second            = (uint8_t)((secondHundredth & RTC_SEC_HUND_SEC_MASK) >> RTC_SEC_HUND_SEC_SHIFT);
    datetime->hundredthOfSecond = (uint8_t)((secondHundredth & RTC_SEC_HUND_HUND_MASK) >> RTC_SEC_HUND_HUND_SHIFT);

    /* Check if any read collision occurred during the whole read sequence */
    if (base->CONFIG & RTC_CONFIG_READ_COLL_MASK)
    {
        return kStatus_Fail;
    }

    return kStatus_Success;
}

/*!
 * brief Sets the initial value of the RTC free-running counter.
 *
 * This function is applicable only when the RTC is in Free-Running Counter mode.
 *
 * param base RTC peripheral base address.
 * param countValue The initial value to set for the counter.
 * return kStatus_Success if the operation was successful, kStatus_InvalidArgument if the input is invalid, or
 * kStatus_Timeout if the interface is not ready.
 */
status_t RTC_SetFreeRunningCounter(RTC_Type *base, uint64_t countValue)
{
    /* Check if in free-running mode */
    if (RTC_GetOperatingMode(base) != kRTC_ModeFreeRunningCounter)
    {
        return kStatus_InvalidArgument;
    }

    /* Check if countValue exceeds 40-bit maximum (0xFFFFFFFFFF) */
    if (countValue > 0xFFFFFFFFFFULL)
    {
        return kStatus_InvalidArgument;
    }

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set counter values */
    base->CNT_H = RTC_CNT_H_CTRL_HIGH((countValue >> 32) & 0xFFU);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->CNT_M = RTC_CNT_M_CTRL_MIDDLE((countValue >> 16) & 0xFFFFU);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Writing to CNT_L triggers the update */
    base->CNT_L = RTC_CNT_L_CTRL_LOW(countValue & 0xFFFFU);

    return kStatus_Success;
}

/*!
 * brief Retrieves the current value of the RTC free-running counter.
 *
 * This function is applicable only when the RTC is in Free-Running Counter mode.
 *
 * param base RTC peripheral base address.
 * param countValue Pointer to a variable to store the current counter value.
 * return kStatus_Success if the operation was successful, kStatus_InvalidArgument if not in free-running mode, or
 * kStatus_Fail if a read collision occurred. kStatus_Timeout if the interface is not ready.
 */
status_t RTC_GetFreeRunningCounter(RTC_Type *base, uint64_t *countValue)
{
    assert(countValue != NULL);

    /* Check if in free-running mode */
    if (RTC_GetOperatingMode(base) != kRTC_ModeFreeRunningCounter)
    {
        return kStatus_InvalidArgument;
    }

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Clear any previous read collision flag */
    base->CONFIG &= ~RTC_CONFIG_READ_COLL_MASK;

    /* Read counter values */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    uint64_t high = (uint64_t)((base->CNT_H & RTC_CNT_H_CTRL_HIGH_MASK) >> RTC_CNT_H_CTRL_HIGH_SHIFT);
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    uint32_t middle = (base->CNT_M & RTC_CNT_M_CTRL_MIDDLE_MASK) >> RTC_CNT_M_CTRL_MIDDLE_SHIFT;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    uint32_t low = (base->CNT_L & RTC_CNT_L_CTRL_LOW_MASK) >> RTC_CNT_L_CTRL_LOW_SHIFT;

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Check if any read collision occurred during the whole read sequence */
    if (base->CONFIG & RTC_CONFIG_READ_COLL_MASK)
    {
        return kStatus_Fail;
    }

    /* Combine the values - cast to uint64_t first, then shift */
    *countValue = (high << 32) | ((uint64_t)middle << 16) | (uint64_t)low;

    return kStatus_Success;
}

/*!
 * brief Configures a specific RTC BCD alarm.
 *
 * Sets the alarm time, date, mask, mode, and initial enable state.
 * The number of alarms is MCU-dependent (e.g., 3 alarms: Alarm0, Alarm1, Alarm2).
 *
 * param base RTC peripheral base address.
 * param alarmId The ID of the alarm to configure (e.g., kRTC_Alarm_0).
 * param alarmConfig Pointer to the rtc_bcd_alarm_config_t structure with alarm settings.
 * return kStatus_Success if the operation was successful, kStatus_InvalidArgument if the input was invalid, or
 * kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureBCDAlarm(RTC_Type *base, rtc_alarm_id_t alarmId, const rtc_bcd_alarm_config_t *alarmConfig)
{
    /* Check input parameters */
    assert(alarmConfig != NULL);
    assert(alarmId <= kRTC_Alarm_2);
    uint32_t bcdAlarmH   = 0U;
    uint32_t bcdAlarmL   = 0U;
    uint32_t bcdAlarmMin = 0U;

    /* Validate the alarm configuration */
    if (!RTC_ValidateBCDAlarmDateTime(alarmConfig))
    {
        return kStatus_InvalidArgument;
    }

    /* Disable the alarm first if it's enabled */
    RTC_DisableAlarm(base, alarmId);

    /* Set up the BCD alarm configuration */
    /* Configure high word - includes alarm number and repeat flag */
    bcdAlarmH = RTC_BCD_ALARM_H_NUM(alarmId) | RTC_BCD_ALARM_H_REP(alarmConfig->mode == kRTC_AlarmModeRepeat ? 1U : 0U);

    /* Configure mask bits */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreMonth) == 0U)
    {
        bcdAlarmH |= RTC_BCD_ALARM_H_USE_MO_MASK;
        bcdAlarmH |= RTC_BCD_ALARM_H_MONTH(alarmConfig->month - 1);
    }
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreDay) == 0U)
    {
        bcdAlarmH |= RTC_BCD_ALARM_H_USE_DAY_MO_MASK;
        bcdAlarmMin = RTC_BCD_ALARM_MIN_DAY_MO(alarmConfig->day - 1);
    }

    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreHour) == 0U)
    {
        bcdAlarmL |= RTC_BCD_ALARM_L_USE_HOUR_MASK;
        bcdAlarmMin |= RTC_BCD_ALARM_MIN_HOUR(alarmConfig->hour);
    }

    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreMinute) == 0U)
    {
        bcdAlarmL |= RTC_BCD_ALARM_L_USE_MIN_MASK;
        bcdAlarmMin |= RTC_BCD_ALARM_MIN_MIN(alarmConfig->minute);
    }

    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreSecond) == 0U)
    {
        bcdAlarmL |= RTC_BCD_ALARM_L_USE_SEC_MASK;
        bcdAlarmL |= RTC_BCD_ALARM_L_SEC(alarmConfig->second);
    }

    bcdAlarmL |= RTC_BCD_ALARM_L_HUND(alarmConfig->hundredthOfSecond);

    /* Day of week mask handling - set the specific days of week in the dayOfWeek field */
    /* If day of week is not ignored, set the specific day of week */
    if ((alarmConfig->mask & kRTC_AlarmMaskIgnoreDayOfWeek) == 0U)
    {
        bcdAlarmH |= RTC_BCD_ALARM_H_DAY_WEEK(1U << alarmConfig->dayOfWeek);
    }
    /* If day of week is ignored, set all days (0x7F) */
    else
    {
        bcdAlarmH |= RTC_BCD_ALARM_H_DAY_WEEK(0x7FU);
    }

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Write the high word of the alarm */
    base->BCD_ALARM_H = bcdAlarmH;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Write the min word of the alarm */
    base->BCD_ALARM_MIN = bcdAlarmMin;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Write the low word of the alarm */
    base->BCD_ALARM_L = bcdAlarmL;

    /* Enable the alarm if requested */
    if (alarmConfig->enable)
    {
        RTC_EnableAlarm(base, alarmId);
    }

    return kStatus_Success;
}

/*!
 * brief Configures a specific RTC free running mode alarm.
 *
 * Select the alarm id and set the alarm counter value
 *
 * param base RTC peripheral base address.
 * param alarmId The ID of the alarm to configure (e.g., kRTC_Alarm_0).
 * param alarmConfig Pointer to the rtc_free_run_alarm_config_t structure with alarm settings.
 * return kStatus_Success if the operation was successful, kStatus_InvalidArgument if the input was invalid,
 * or kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureFreeRunningAlarm(RTC_Type *base,
                                       rtc_alarm_id_t alarmId,
                                       const rtc_free_run_alarm_config_t *alarmConfig)
{
    assert(alarmConfig != NULL);
    assert(alarmId <= kRTC_Alarm_2);

    /* Validate the free running alarm configuration */
    if (!RTC_ValidateFreeRunAlarmCounter(alarmConfig))
    {
        return kStatus_InvalidArgument;
    }

    uint32_t alarmH   = 0U;
    uint32_t alarmMid = 0U;
    uint32_t alarmLow = 0U;

    /* Disable the alarm before configuration */
    RTC_DisableAlarm(base, alarmId);

    /* Set alarm number and repeat mode */
    alarmH = RTC_ALARM_H_ALARM_NUM(alarmId);
    if (alarmConfig->mode == kRTC_AlarmModeRepeat)
    {
        alarmH |= RTC_ALARM_H_ALARM_REP_MASK;

        /* Only lower 24 bits are used in repeat mode (relative value) */
        uint32_t relVal = alarmConfig->alarmCounter & 0xFFFFFFU;
        /* bits 23:16 */
        alarmMid = RTC_ALARM_MID_ALARM_M((relVal >> 16) & 0xFFU);
        /* bits 15:0 */
        alarmLow = RTC_ALARM_LOW_ALARMN_L(relVal & 0xFFFFU);
    }
    /* Single shot mode */
    else
    {
        /* All 40 bits are used (absolute value) */
        /* bits 39:32 */
        alarmH |= RTC_ALARM_H_ALARM((uint32_t)((alarmConfig->alarmCounter >> 32) & 0xFFU));
        /* bits 31:16 */
        alarmMid = RTC_ALARM_MID_ALARM_M((uint32_t)((alarmConfig->alarmCounter >> 16) & 0xFFFFU));
        /* bits 15:0 */
        alarmLow = RTC_ALARM_LOW_ALARMN_L((uint32_t)(alarmConfig->alarmCounter & 0xFFFFU));
    }

    /* Write to hardware registers with interface ready checks */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->ALARM_H = alarmH;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->ALARM_MID = alarmMid;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->ALARM_LOW = alarmLow;

    /* Enable the alarm if requested */
    if (alarmConfig->enable)
    {
        RTC_EnableAlarm(base, alarmId);
    }

    return kStatus_Success;
}

/*!
 * brief Enables a specific RTC alarm.
 *
 * param base RTC peripheral base address.
 * param alarmId The ID of the alarm to enable.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableAlarm(RTC_Type *base, rtc_alarm_id_t alarmId)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Clear the disable bit for the specified alarm */
    switch (alarmId)
    {
        case kRTC_Alarm_0:
            base->CONFIG &= ~RTC_CONFIG_ALARM0_DIS_MASK;
            break;
        case kRTC_Alarm_1:
            base->CONFIG &= ~RTC_CONFIG_ALARM1_DIS_MASK;
            break;
        case kRTC_Alarm_2:
            base->CONFIG &= ~RTC_CONFIG_ALARM2_DIS_MASK;
            break;
        default:
            /* Invalid alarm ID */
            assert(false);
            break;
    }

    return kStatus_Success;
}

/*!
 * brief Disables a specific RTC alarm.
 *
 * param base RTC peripheral base address.
 * param alarmId The ID of the alarm to disable.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableAlarm(RTC_Type *base, rtc_alarm_id_t alarmId)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set the disable bit for the specified alarm */
    switch (alarmId)
    {
        case kRTC_Alarm_0:
            base->CONFIG |= RTC_CONFIG_ALARM0_DIS_MASK;
            break;
        case kRTC_Alarm_1:
            base->CONFIG |= RTC_CONFIG_ALARM1_DIS_MASK;
            break;
        case kRTC_Alarm_2:
            base->CONFIG |= RTC_CONFIG_ALARM2_DIS_MASK;
            break;
        default:
            /* Invalid alarm ID */
            assert(false);
            break;
    }

    return kStatus_Success;
}

/*!
 * brief Enables specified RTC interrupt sources.
 *
 * param base RTC peripheral base address.
 * param mask Bitmask of interrupts to enable (see rtc_interrupt_enable_t).
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableInterrupts(RTC_Type *base, uint32_t mask)
{
    uint32_t enabledInterrupts;
    mask &= (uint32_t)kRTC_AllInterruptsEnable;

    enabledInterrupts = base->INT & (uint32_t)kRTC_AllInterruptsEnable;
    enabledInterrupts |= mask;

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->INT = enabledInterrupts;

    return kStatus_Success;
}
/*!
 * brief Disables specified RTC interrupt sources.
 *
 * param base RTC peripheral base address.
 * param mask Bitmask of interrupts to disable (see rtc_interrupt_enable_t).
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableInterrupts(RTC_Type *base, uint32_t mask)
{
    uint32_t enabledInterrupts;
    mask &= (uint32_t)kRTC_AllInterruptsEnable;

    enabledInterrupts = base->INT & (uint32_t)kRTC_AllInterruptsEnable;
    enabledInterrupts &= ~mask;

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->INT = enabledInterrupts;

    return kStatus_Success;
}

/*!
 * brief Clears the RTC interrupt flags.
 *
 * param base    RTC peripheral base address
 * param mask    The interrupt flags to clear. This is a logical OR of members of the
 *                enumeration ::rtc_status_flags_t
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ClearInterruptFlags(RTC_Type *base, uint32_t mask)
{
    uint32_t regValue;
    mask &= (uint32_t)kRTC_AllStatusFlags;

    regValue = base->INT;
    /* Clear all interrupt flag bits */
    regValue &= ~(uint32_t)kRTC_AllStatusFlags;
    regValue |= mask;

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->INT = regValue;

    return kStatus_Success;
}

/*!
 * brief Register callback.
 *
 * param cb_func   callback function
 */
void RTC_RegisterCallBack(rtc_callback_t cb_func)
{
    s_rtcCallback = cb_func;
}

/*!
 * brief Enables the RTC Watchdog Timer.
 * Assumes timeout is already configured via RTC_Init or RTC_SetWatchdogTimeout.
 *
 * param base RTC peripheral base address.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableWatchdog(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->CONFIG |= RTC_CONFIG_WDOG_EN_MASK;
    return kStatus_Success;
}

/*!
 * brief Disables the RTC Watchdog Timer.
 *
 * param base RTC peripheral base address.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableWatchdog(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->CONFIG &= ~RTC_CONFIG_WDOG_EN_MASK;

    return kStatus_Success;
}

/*!
 * brief Sets the timeout value for the RTC Watchdog Timer.
 *
 * param base RTC peripheral base address.
 * param timeoutValue The desired timeout value.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_SetWatchdogTimeout(RTC_Type *base, uint32_t timeoutValue)
{
    s_lastWdtTimeout = timeoutValue;
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->WDT_SET_VA = RTC_WDT_SET_VA_WDT_CNTR(timeoutValue);

    return kStatus_Success;
}

/*!
 * brief Refreshes the RTC Watchdog Timer.
 *
 * param base RTC peripheral base address.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_RefreshWatchdog(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->WDT_SET_VA = RTC_WDT_SET_VA_WDT_CNTR(s_lastWdtTimeout);

    return kStatus_Success;
}

/*!
 * brief Configures a specific tamper input.
 *
 * This function sets up the tamper input configuration, including enabling/disabling the input,
 * setting polarity, pullup and filters.
 *
 * param base RTC peripheral base address.
 * param tamperInputId The ID of the tamper input to configure (e.g., kRTC_TamperInput0).
 * param config Pointer to the rtc_tamper_config_t structure containing tamper input settings.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureTamperInput(RTC_Type *base,
                                  rtc_tamper_input_id_t tamperInputId,
                                  const rtc_tamper_input_config_t *config)
{
    /* Check input parameters */
    assert(config != NULL);
    assert(tamperInputId < RTC_MAX_TAMPER_INPUTS);

    /* First clean tamper input bits value*/
    uint32_t tamperCtrl = base->TAMP_CTRL;

    tamperCtrl &= ~(((1 << tamperInputId) << RTC_TAMP_CTRL_TAMP_EN_SHIFT) |
                    ((1 << tamperInputId) << RTC_TAMP_CTRL_TAMP_POL_SHIFT) |
                    ((1 << tamperInputId) << RTC_TAMP_CTRL_TAMP_PULL_CTRL_SHIFT) |
                    ((1 << tamperInputId) << RTC_TAMP_CTRL_TAMP_CTRL_SHIFT));

    /* Configure tamper global settings */
    tamperCtrl |= RTC_TAMP_CTRL_TAMP_EN((config->enableTamperInput ? 1U : 0U) << tamperInputId) |
                  RTC_TAMP_CTRL_TAMP_POL(config->polarity << tamperInputId) |
                  RTC_TAMP_CTRL_TAMP_PULL_CTRL(config->pullup << tamperInputId) |
                  RTC_TAMP_CTRL_TAMP_CTRL(config->filter << tamperInputId);

    if (config->enableTamperInput)
    {
        /* Enable global tamper detection if not already enabled */
        tamperCtrl |= RTC_TAMP_CTRL_TAMP_LOG_EN_MASK;
    }
    else
    {
        /* If disabling, check if any other tamper input is still enabled */
        if ((tamperCtrl & RTC_TAMP_CTRL_TAMP_EN_MASK) == 0U)
        {
            tamperCtrl &= ~RTC_TAMP_CTRL_TAMP_LOG_EN_MASK; /* Disable global tamper detection */
        }
    }

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->TAMP_CTRL = tamperCtrl;

    return kStatus_Success;
}

/*!
 * brief Enables the specific tamper detection input pin.
 *
 * param base RTC peripheral base address.
 * param tamperInputId Bitmask of tamper inputs to enable.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableTamperInputPin(RTC_Type *base, rtc_tamper_input_id_t tamperInputId)
{
    /* Ensure valid tamper pin */
    assert(tamperInputId < RTC_MAX_TAMPER_INPUTS);

    uint32_t tamperCtrl = base->TAMP_CTRL;

    /* Enable global tamper detection if requested */
    if ((tamperCtrl & RTC_TAMP_CTRL_TAMP_LOG_EN_MASK) == 0U)
    {
        tamperCtrl |= RTC_TAMP_CTRL_TAMP_LOG_EN_MASK;
    }

    tamperCtrl |= RTC_TAMP_CTRL_TAMP_EN(tamperInputId);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Update tamper control register */
    base->TAMP_CTRL = tamperCtrl;

    return kStatus_Success;
}

/*!
 * brief Disable the specific tamper detection input pin.
 *
 * param base RTC peripheral base address.
 * param tamperInputId Bitmask of tamper inputs to disable.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableTamperInputPin(RTC_Type *base, rtc_tamper_input_id_t tamperInputId)
{
    /* Ensure valid tamper pin */
    assert(tamperInputId < RTC_MAX_TAMPER_INPUTS);

    uint32_t tamperCtrl = base->TAMP_CTRL;

    tamperCtrl &= ~RTC_TAMP_CTRL_TAMP_EN(tamperInputId);

    /* If both pins are disabled, disable global tamper detection */
    if ((tamperCtrl & RTC_TAMP_CTRL_TAMP_EN_MASK) == 0U)
    {
        tamperCtrl &= ~RTC_TAMP_CTRL_TAMP_LOG_EN_MASK;
    }

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Update tamper control register */
    base->TAMP_CTRL = tamperCtrl;

    return kStatus_Success;
}

/*!
 * @brief Gets the latched RTC counter value at the time of the last tamper event.
 *
 * @param base RTC peripheral base address.
 * @param latchedCount Pointer to a variable where the latched counter value will be stored.
 * @return kStatus_Success if the operation was successful, kStatus_InvalidArgument if not in tamper mode,
 */
status_t RTC_GetTamperTimestamp(RTC_Type *base, uint64_t *latchedCount)
{
    assert(latchedCount != NULL);
    memset(latchedCount, 0, sizeof(uint64_t));

    /* 1. Trigger read of latched counter from RTC to SMM */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->TAMP_CTRL |= RTC_TAMP_CTRL_READ_CNTR_STRT_MASK;

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* 2. Poll for READ_CNTR_READY */
#if defined(RTC_WAIT_READ_COUNTER_LATCHED_READY) && (RTC_WAIT_READ_COUNTER_LATCHED_READY > 0U)
    uint32_t timeout = RTC_WAIT_READ_COUNTER_LATCHED_READY;
#endif
    /* Wait until the RTC interface is ready (IF_READY bit is set) */
    while (!(base->TAMP_CTRL & RTC_TAMP_CTRL_READ_CNTR_READY_MASK))
    {
        if (kStatus_Success != RTC_WaitForInterfaceReady(base))
        {
            return kStatus_Timeout;
        }
#if defined(RTC_WAIT_READ_COUNTER_LATCHED_READY) && (RTC_WAIT_READ_COUNTER_LATCHED_READY > 0U)
        if ((--timeout) == 0U)
        {
            /* Timeout occurred */
            return kStatus_Timeout;
        }
#endif
    }

    /* Bit READ_CNTR_STRT is auto-cleared by HW when READ_CNTR_READY is set */
    /* 3. Read the latched counter value */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    uint32_t count0 = base->RTC_COUNT[0]; /* RTC_COUNT[15:0]   */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    uint32_t count1 = base->RTC_COUNT[1]; /* RTC_COUNT[31:16]  */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    uint32_t count2 = base->RTC_COUNT[2]; /* RTC_COUNT[39:32] - only lower 8 bits are valid */

    *latchedCount = ((uint64_t)(count2 & 0xFFU) << 32U) | ((uint64_t)count1 << 16U) | ((uint64_t)count0);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Clean read counter ready. */
    base->TAMP_CTRL &= ~RTC_TAMP_CTRL_READ_CNTR_READY_MASK;

    return kStatus_Success;
}

/*!
 * brief Writes a key to the RTC's non-volatile storage.
 *
 * param base RTC peripheral base address.
 * param keyData Pointer to the key data to be written.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_WriteKey(RTC_Type *base, const uint32_t *keyData)
{
    /* Check input parameters */
    assert(keyData != NULL);

    for (uint8_t i = 0U; i < RTC_SECURE_KEY_REG_COUNT; ++i)
    {
        if (kStatus_Success != RTC_WaitForInterfaceReady(base))
        {
            return kStatus_Timeout;
        }
        /* RM: "After each write of the 2nd 16bit the 32bits will be written to the RTC."
         * This implies SMM handles sub-word writes if needed. CPU writes 32-bit words.
         */
        base->SECURE_KEY[i] = keyData[i];
    }

    return kStatus_Success;
}

/*!
 * brief Reads a key from the RTC's non-volatile storage.
 *
 * param base RTC peripheral base address.
 * param keyBuffer Pointer to a buffer where the key data will be stored.
 * return kStatus_Success if the operation was successful, kStatus_Fail if SECURE_KEY_READY is not set
 */
status_t RTC_ReadKey(RTC_Type *base, uint32_t *keyBuffer)
{
    assert(keyBuffer != NULL);

    /* Trigger read of secure key from RTC to SMM */
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set READ_SEC_KEY_START */
    base->TAMP_CTRL |= RTC_TAMP_CTRL_READ_SEC_KEY_MASK;

#if defined(RTC_WAIT_SECURE_KEY_READY_TIMEOUT) && (RTC_WAIT_SECURE_KEY_READY_TIMEOUT > 0U)
    uint32_t timeout = RTC_WAIT_SECURE_KEY_READY_TIMEOUT;
#endif
    while ((base->TAMP_CTRL & RTC_TAMP_CTRL_SEC_KEY_READY_MASK) == 0U)
    {
#if defined(RTC_WAIT_SECURE_KEY_READY_TIMEOUT) && (RTC_WAIT_SECURE_KEY_READY_TIMEOUT > 0U)
        if ((--timeout) == 0U)
        {
            /* Timeout occurred */
            return kStatus_Timeout;
        }
#endif
    }

    /* Bit READ_SEC_KEY is auto-cleared by HW when SEC_KEY_READY is set */
    for (uint32_t i = 0U; i < RTC_SECURE_KEY_REG_COUNT; ++i)
    {
        keyBuffer[i] = base->SECURE_KEY[i];
    }

    return kStatus_Success;
}

/*!
 * brief Enables the RTC alive detector.
 *
 * param base RTC peripheral base address.
 * param config Pointer to the rtc_alive_detector_config_t structure containing alive detector settings.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_ConfigureAliveDetector(RTC_Type *base, const rtc_alive_detector_config_t *config)
{
    /* Check input parameters */
    assert(config != NULL);

    /* Configure alive detector settings */
    uint32_t aliveDetector = RTC_RTC_ALV_DTCT_DTCT_EN(config->enableAliveDetector ? 1U : 0U) |
                             RTC_RTC_ALV_DTCT_BYPASS(config->bypassAnalogAliveMechanism ? 1U : 0U) |
                             RTC_RTC_ALV_DTCT_ACTV_PRD(config->mechanismPeriod);

    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    base->RTC_ALV_DTCT = aliveDetector;
    return kStatus_Success;
}

/*!
 * brief Alive detector enable
 *
 * param base RTC peripheral base address.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_EnableAliveDetector(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Set the enable bit for the alive detector */
    base->RTC_ALV_DTCT |= RTC_RTC_ALV_DTCT_DTCT_EN_MASK;
    return kStatus_Success;
}

/*!
 * brief Alive detector disable
 *
 * param base RTC peripheral base address.
 * return kStatus_Success if the operation was successful, kStatus_Timeout if the interface is not ready.
 */
status_t RTC_DisableAliveDetector(RTC_Type *base)
{
    if (kStatus_Success != RTC_WaitForInterfaceReady(base))
    {
        return kStatus_Timeout;
    }
    /* Clear the enable bit for the alive detector */
    base->RTC_ALV_DTCT &= ~RTC_RTC_ALV_DTCT_DTCT_EN_MASK;
    return kStatus_Success;
}

/*!
 * brief RTC Alarm 0 interrupt handler.
 *
 * This function is called when the RTC Alarm 0 interrupt occurs.
 * It clears the interrupt flags and calls the registered callback function if set.
 */
void RTC_ALARM0_DriverIRQHandler(void);
void RTC_ALARM0_DriverIRQHandler(void)
{
    RTC_ClearInterruptFlags(AON__RTC_AON, kRTC_Alarm0InterruptFlag);

    if (s_rtcCallback != NULL)
    {
        s_rtcCallback(kRTC_Alarm0Callback);
    }

    SDK_ISR_EXIT_BARRIER;
}

/*!
 * brief RTC Alarm 1 interrupt handler.
 *
 * This function is called when the RTC Alarm 1 interrupt occurs.
 * It clears the interrupt flags and calls the registered callback function if set.
 */
void RTC_ALARM1_DriverIRQHandler(void);
void RTC_ALARM1_DriverIRQHandler(void)
{
    RTC_ClearInterruptFlags(AON__RTC_AON, kRTC_Alarm1InterruptFlag);

    if (s_rtcCallback != NULL)
    {
        s_rtcCallback(kRTC_Alarm1Callback);
    }

    SDK_ISR_EXIT_BARRIER;
}

/*!
 * brief RTC Alarm 2 interrupt handler.
 *
 * This function is called when the RTC Alarm 2 interrupt occurs.
 * It clears the interrupt flags and calls the registered callback function if set.
 */
void RTC_ALARM2_DriverIRQHandler(void);
void RTC_ALARM2_DriverIRQHandler(void)
{
    RTC_ClearInterruptFlags(AON__RTC_AON, kRTC_Alarm2InterruptFlag);

    if (s_rtcCallback != NULL)
    {
        s_rtcCallback(kRTC_Alarm2Callback);
    }

    SDK_ISR_EXIT_BARRIER;
}

/*!
 * brief RTC watchdog interrupt handler.
 *
 * This function is called when the RTC Watchdog Timer interrupt occurs.
 * It clears the interrupt flags and calls the registered callback function if set.
 */
void RTC_WDT_DriverIRQHandler(void);
void RTC_WDT_DriverIRQHandler(void)
{
    RTC_ClearInterruptFlags(AON__RTC_AON, kRTC_WatchdogInterruptFlag);

    if (s_rtcCallback != NULL)
    {
        s_rtcCallback(kRTC_WatchDogCallback);
    }

    SDK_ISR_EXIT_BARRIER;
}

/*!
 * brief RTC xtal interrupt handler.
 * This function is called when the RTC Xtal interrupt occurs.
 * It clears the interrupt flags and calls the registered callback function if set.
 */
void RTC_XTAL_DriverIRQHandler(void);
void RTC_XTAL_DriverIRQHandler(void)
{
    RTC_ClearInterruptFlags(AON__RTC_AON, kRTC_XtalFailInterruptFlag);

    if (s_rtcCallback != NULL)
    {
        s_rtcCallback(kRTC_XtalFailCallback);
    }

    SDK_ISR_EXIT_BARRIER;
}
