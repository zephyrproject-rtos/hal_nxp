/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_rtc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_rtc"
#endif

#define SECONDS_IN_A_DAY    (86400U)
#define SECONDS_IN_A_HOUR   (3600U)
#define SECONDS_IN_A_MINUTE (60U)
#define DAYS_IN_A_YEAR      (365U)
#define YEAR_RANGE_START    (1970U)
#define YEAR_RANGE_END      (2099U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Checks whether the date and time passed in is valid
 *
 * @param datetime Pointer to structure where the date and time details are stored
 *
 * @return Returns false if the date & time details are out of range; true if in range
 */
static bool RTC_CheckDatetimeFormat(const rtc_datetime_t *datetime);

/*!
 * @brief Converts time data from datetime to seconds
 *
 * @param datetime Pointer to datetime structure where the date and time details are stored
 *
 * @return The result of the conversion in seconds
 */
static uint32_t RTC_ConvertDatetimeToSeconds(const rtc_datetime_t *datetime);

/*!
 * @brief Converts time data from seconds to a datetime structure
 *
 * @param seconds  Seconds value that needs to be converted to datetime format
 * @param datetime Pointer to the datetime structure where the result of the conversion is stored
 */
static void RTC_ConvertSecondsToDatetime(uint32_t seconds, rtc_datetime_t *datetime);

/*******************************************************************************
 * Code
 ******************************************************************************/
static bool RTC_CheckDatetimeFormat(const rtc_datetime_t *datetime)
{
    assert(datetime != NULL);

    /* Table of days in a month for a non leap year. First entry in the table is not used,
     * valid months start from 1
     */
    uint8_t daysPerMonth[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};

    /* Check year, month, hour, minute, seconds */
    if ((datetime->year < YEAR_RANGE_START) || (datetime->year > YEAR_RANGE_END) || (datetime->month > 12U) ||
        (datetime->month < 1U) || (datetime->hour >= 24U) || (datetime->minute >= 60U) || (datetime->second >= 60U))
    {
        /* If not correct then error*/
        return false;
    }

    /* Adjust the days in February for a leap year */
    if ((((datetime->year & 3U) == 0) && (datetime->year % 100 != 0)) || (datetime->year % 400 == 0))
    {
        daysPerMonth[2] = 29U;
    }

    /* Check the validity of the day */
    if ((datetime->day > daysPerMonth[datetime->month]) || (datetime->day < 1U))
    {
        return false;
    }

    return true;
}

static uint32_t RTC_ConvertDatetimeToSeconds(const rtc_datetime_t *datetime)
{
    assert(datetime != NULL);

    /* Number of days from begin of the non Leap-year*/
    /* Number of days from begin of the non Leap-year*/
    uint16_t monthDays[] = {0U, 0U, 31U, 59U, 90U, 120U, 151U, 181U, 212U, 243U, 273U, 304U, 334U};
    uint32_t seconds;

    /* Compute number of days from 1970 till given year*/
    seconds = (datetime->year - 1970U) * DAYS_IN_A_YEAR;
    /* Add leap year days */
    seconds += ((datetime->year / 4) - (1970U / 4));
    /* Add number of days till given month*/
    seconds += monthDays[datetime->month];
    /* Add days in given month. We subtract the current day as it is
     * represented in the hours, minutes and seconds field*/
    seconds += (datetime->day - 1);
    /* For leap year if month less than or equal to Febraury, decrement day counter*/
    if ((!(datetime->year & 3U)) && (datetime->month <= 2U))
    {
        seconds--;
    }

    seconds = (seconds * SECONDS_IN_A_DAY) + (datetime->hour * SECONDS_IN_A_HOUR) +
              (datetime->minute * SECONDS_IN_A_MINUTE) + datetime->second;

    return seconds;
}

static void RTC_ConvertSecondsToDatetime(uint32_t seconds, rtc_datetime_t *datetime)
{
    assert(datetime != NULL);

    uint32_t x;
    uint32_t secondsRemaining, days;
    uint16_t daysInYear;
    /* Table of days in a month for a non leap year. First entry in the table is not used,
     * valid months start from 1
     */
    uint8_t daysPerMonth[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};

    /* Start with the seconds value that is passed in to be converted to date time format */
    secondsRemaining = seconds;

    /* Calcuate the number of days, we add 1 for the current day which is represented in the
     * hours and seconds field
     */
    days = secondsRemaining / SECONDS_IN_A_DAY + 1;

    /* Update seconds left*/
    secondsRemaining = secondsRemaining % SECONDS_IN_A_DAY;

    /* Calculate the datetime hour, minute and second fields */
    datetime->hour   = secondsRemaining / SECONDS_IN_A_HOUR;
    secondsRemaining = secondsRemaining % SECONDS_IN_A_HOUR;
    datetime->minute = secondsRemaining / 60U;
    datetime->second = secondsRemaining % SECONDS_IN_A_MINUTE;

    /* Calculate year */
    daysInYear     = DAYS_IN_A_YEAR;
    datetime->year = YEAR_RANGE_START;
    while (days > daysInYear)
    {
        /* Decrease day count by a year and increment year by 1 */
        days -= daysInYear;
        datetime->year++;

        /* Adjust the number of days for a leap year */
        if (datetime->year & 3U)
        {
            daysInYear = DAYS_IN_A_YEAR;
        }
        else
        {
            daysInYear = DAYS_IN_A_YEAR + 1;
        }
    }

    /* Adjust the days in February for a leap year */
    if (!(datetime->year & 3U))
    {
        daysPerMonth[2] = 29U;
    }

    for (x = 1U; x <= 12U; x++)
    {
        if (days <= daysPerMonth[x])
        {
            datetime->month = x;
            break;
        }
        else
        {
            days -= daysPerMonth[x];
        }
    }

    datetime->day = days;
}

/*!
 * brief Sets the RTC date and time according to the given time structure.
 *
 * The RTC counter must be stopped prior to calling this function as writes to the RTC
 * seconds register will fail if the RTC counter is running.
 *
 * param base     RTC peripheral base address
 * param datetime Pointer to structure where the date and time details to set are stored
 *
 * return kStatus_Success: Success in setting the time and starting the RTC
 *         kStatus_InvalidArgument: Error because the datetime format is incorrect
 */
status_t RTC_SetDatetime(RTC_Type *base, const rtc_datetime_t *datetime)
{
    assert(datetime != NULL);

    /* Return error if the time provided is not valid */
    if (!(RTC_CheckDatetimeFormat(datetime)))
    {
        return kStatus_InvalidArgument;
    }

    /* Set time in seconds */
    base->SEC = RTC_ConvertDatetimeToSeconds(datetime);
    /* Wait for synchronize */
    while (base->STATUS & RTC_STATUS_SEC_SYNC_MASK)
    {
    }
    base->CTRL |= RTC_CTRL_CFG_MASK;
    /* Wait for synchronize */
    while (base->STATUS & RTC_STATUS_CTRL_SYNC_MASK)
    {
    }
    return kStatus_Success;
}

/*!
 * brief Gets the RTC time and stores it in the given time structure.
 *
 * param base     RTC peripheral base address.
 * param datetime Pointer to structure where the date and time details are stored.
 */
void RTC_GetDatetime(RTC_Type *base, rtc_datetime_t *datetime)
{
    assert(datetime != NULL);

    uint32_t seconds = RTC_GetSecond(RTC);
    RTC_ConvertSecondsToDatetime(seconds, datetime);
}

/*!
 * brief RTC calibration.
 *
 * param base RTC peripheral base address.
 * param dir Forward or backward calibration.
 * param value calibration value.
 */
void RTC_Calibration(RTC_Type *base, rtc_calibration_direction_t dir, uint16_t value)
{
    base->CAL = (base->CAL & ~(RTC_CAL_PPM_MASK | RTC_CAL_DIR_MASK)) | (RTC_CAL_DIR(dir) | RTC_CAL_PPM(value));
    while (base->STATUS & RTC_STATUS_CALIB_SYNC_MASK)
    {
    }
    base->CTRL |= RTC_CTRL_CAL_EN_MASK;
    while (base->STATUS & RTC_STATUS_CTRL_SYNC_MASK)
    {
    }
}

/*!
 * brief Enable/Disable free running reset.
 *
 * param base RTC peripheral base address.
 * param enable true to enable the reset, false to disable.
 */
void RTC_EnableFreeRunningReset(RTC_Type *base, bool enable)
{
    uint32_t tmp32;

    tmp32 = base->CNT2_CTRL;
    if (enable)
    {
        tmp32 |= RTC_CNT2_CTRL_CNT2_RST_MASK;
    }
    else
    {
        tmp32 &= ~RTC_CNT2_CTRL_CNT2_RST_MASK;
    }

    base->CNT2_CTRL = (tmp32 | RTC_FREERUNNING_MAGIC_NUM);
    while (base->STATUS & RTC_STATUS_FREE_SYNC_MASK)
    {
    }
}

/*!
 * brief Set free running interrupt threshold.
 *
 * param base RTC peripheral base address.
 * param value Free running interrupt threshold value.
 */
void RTC_SetFreeRunningInterruptThreshold(RTC_Type *base, uint32_t value)
{
    base->THR_INT = value;
    while (base->STATUS & RTC_STATUS_THR_INT_SYNC_MASK)
    {
    }
}

/*!
 * brief Set free running reset threshold.
 *
 * param base RTC peripheral base address.
 * param value Free running reset threshold value.
 */
void RTC_SetFreeRunningResetThreshold(RTC_Type *base, uint32_t value)
{
    base->THR_RST = value;
    while (base->STATUS & RTC_STATUS_THR_RST_SYNC_MASK)
    {
    }
}

/*!
 * brief Enable/Disable RTC free running.
 *
 * param base RTC peripheral base address.
 * param enable true to enable free running, false to disable.
 */
void RTC_FreeRunningEnable(RTC_Type *base, bool enable)
{
    uint32_t tmp32;

    tmp32 = base->CNT2_CTRL;
    if (enable)
    {
        tmp32 |= RTC_CNT2_CTRL_CNT2_EN_MASK;
    }
    else
    {
        tmp32 &= ~RTC_CNT2_CTRL_CNT2_EN_MASK;
    }

    base->CNT2_CTRL = (tmp32 | RTC_FREERUNNING_MAGIC_NUM);
    while (base->STATUS & RTC_STATUS_FREE_SYNC_MASK)
    {
    }
}

/*!
 * brief Enable RTC interrupts according to the provided mask.
 *
 * This function enables the RTC interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members. See ref _rtc_interrupt_enable
 *
 * param base RTC peripheral base address.
 * param mask The interrupts to enable. Logical OR of ref _rtc_interrupt_enable.
 */
void RTC_EnableInterrupts(RTC_Type *base, uint32_t mask)
{
    uint32_t tmp32;

    if (mask & kRTC_SecondInterruptEnable)
    {
        base->CTRL |= RTC_CTRL_SEC_INT_EN_MASK;
        while (base->STATUS & RTC_STATUS_CTRL_SYNC_MASK)
        {
        }
    }
    if (mask & kRTC_FreeRunningInterruptEnable)
    {
        tmp32 = base->CNT2_CTRL;
        tmp32 |= (RTC_CNT2_CTRL_CNT2_INT_EN_MASK | RTC_CNT2_CTRL_CNT2_WAKEUP_MASK);
        base->CNT2_CTRL = (tmp32 | RTC_FREERUNNING_MAGIC_NUM);
        while (base->STATUS & RTC_STATUS_FREE_SYNC_MASK)
        {
        }
    }
}

/*!
 * brief Disable RTC interrupts according to the provided mask.
 *
 * This function disables the RTC interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members. See ref _rtc_interrupt_enable
 *
 * param base RTC peripheral base address.
 * param mask The interrupts to disable. Logical OR of ref _rtc_interrupt_enable.
 */
void RTC_DisableInterrupts(RTC_Type *base, uint32_t mask)
{
    uint32_t tmp32;

    if (mask & kRTC_SecondInterruptEnable)
    {
        base->CTRL &= ~RTC_CTRL_SEC_INT_EN_MASK;
        while (base->STATUS & RTC_STATUS_CTRL_SYNC_MASK)
        {
        }
    }
    if (mask & kRTC_FreeRunningInterruptEnable)
    {
        tmp32 = base->CNT2_CTRL;
        tmp32 &= ~(RTC_CNT2_CTRL_CNT2_INT_EN_MASK | RTC_CNT2_CTRL_CNT2_WAKEUP_MASK);
        base->CNT2_CTRL = (tmp32 | RTC_FREERUNNING_MAGIC_NUM);
        while (base->STATUS & RTC_STATUS_FREE_SYNC_MASK)
        {
        }
    }
}

/*!
 * brief Clears status flags with the provided mask.
 *
 * This function clears RTC status flags with a provided mask.
 *
 * param base RTC peripheral base address.
 * param mask The status flags to be cleared, it is logical OR value of ref _rtc_status_flags.
 */
void RTC_ClearStatusFlags(RTC_Type *base, uint32_t mask)
{
    base->STATUS = mask;
    while (base->STATUS & RTC_STATUS_STATUS_SYNC_MASK)
    {
    }
}
