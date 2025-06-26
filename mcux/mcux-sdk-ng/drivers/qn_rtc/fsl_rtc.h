/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_RTC_H_
#define FSL_RTC_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_rtc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_RTC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1)) /*!< Version 2.0.1 */
/*! @} */

#define RTC_FREERUNNING_MAGIC_NUM (0x5285U << 16)

/*!
 * @brief Structure is used to hold the date and time
 */
typedef struct _rtc_datetime
{
    uint16_t year;  /*!< Range from 1970 to 2099.*/
    uint8_t month;  /*!< Range from 1 to 12.*/
    uint8_t day;    /*!< Range from 1 to 31 (depending on month).*/
    uint8_t hour;   /*!< Range from 0 to 23.*/
    uint8_t minute; /*!< Range from 0 to 59.*/
    uint8_t second; /*!< Range from 0 to 59.*/
} rtc_datetime_t;

/*!
 * @brief RTC calibration direction.
 */
typedef enum _rtc_calibration_direction
{
    kRTC_ForwardCalibration = 0U, /*!< Forward calibration */
    kRTC_BackwardCalibration,     /*!< Backward calibration */
} rtc_calibration_direction_t;

/*!
 * @brief RTC interrupt configuration structure.
 */
enum _rtc_interrupt_enable
{
    kRTC_SecondInterruptEnable      = RTC_CTRL_SEC_INT_EN_MASK,
    kRTC_FreeRunningInterruptEnable = RTC_CNT2_CTRL_CNT2_INT_EN_MASK,
};

/*!
 * @brief RTC status flags.
 */
enum _rtc_status_flags
{
    kRTC_SecondInterruptFlag      = RTC_STATUS_SEC_INT_MASK,
    kRTC_FreeRunningInterruptFlag = RTC_STATUS_FREE_RUNNING_INT_MASK,
    kRTC_WakeupFlag               = RTC_STATUS_FREE_RUNNING_INT_MASK
};

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
 * @brief Ungates the RTC clock.
 *
 * @param base   RTC peripheral base address
 */
static inline void RTC_Init(RTC_Type *base)
{
    /* RTC clock(Included in BIV) enabled as default */
    (void)base->CTRL;

    RESET_PeripheralReset(kRTC_RST_SHIFT_RSTn);
}

/*!
 * @brief Gate the RTC clock.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_Deinit(RTC_Type *base)
{
    /* Do not disable RTC clock */
    (void)base->CTRL;
}

/*! @}*/

/*!
 * @name Current Time
 * @{
 */

/*!
 * @brief Sets the RTC date and time according to the given time structure.
 *
 * The RTC counter must be stopped prior to calling this function as writes to the RTC
 * seconds register will fail if the RTC counter is running.
 *
 * @param base     RTC peripheral base address
 * @param datetime Pointer to structure where the date and time details to set are stored
 *
 * @return kStatus_Success: Success in setting the time and starting the RTC
 *         kStatus_InvalidArgument: Error because the datetime format is incorrect
 */
status_t RTC_SetDatetime(RTC_Type *base, const rtc_datetime_t *datetime);

/*!
 * @brief Gets the RTC time and stores it in the given time structure.
 *
 * @param base     RTC peripheral base address.
 * @param datetime Pointer to structure where the date and time details are stored.
 */
void RTC_GetDatetime(RTC_Type *base, rtc_datetime_t *datetime);

/*!
 * @brief RTC calibration.
 *
 * @param base RTC peripheral base address.
 * @param dir Forward or backward calibration.
 * @param value calibration value.
 */
void RTC_Calibration(RTC_Type *base, rtc_calibration_direction_t dir, uint16_t value);

/*!
 * @brief Get RTC's second value.
 *
 * @param base RTC peripheral base address.
 *
 * @return RTC's second value
 */
static inline uint32_t RTC_GetSecond(RTC_Type *base)
{
    uint32_t a, cnt = 0U;
    volatile uint32_t b;

    do
    {
        a = base->SEC;
        b = base->SEC;
        if (a == b)
        {
            break;
        }
        cnt++;
    } while (cnt < 10U);

    return b;
}

/*!
 * @brief Get RTC counter value.
 *
 * @param base RTC peripheral base address.
 *
 * @return RTC counter value
 */
static inline uint32_t RTC_GetCount(RTC_Type *base)
{
    uint32_t a, cnt = 0U;
    volatile uint32_t b;

    do
    {
        a = base->CNT_VAL;
        b = base->CNT_VAL;
        if (a == b)
        {
            break;
        }
        cnt++;
    } while (cnt < 10U);

    return b;
}

/*! @}*/

/*!
 * @name RTC Free running
 * @{
 */

/*!
 * @brief Enable/Disable free running reset.
 *
 * @param base RTC peripheral base address.
 * @param enable true to enable the reset, false to disable.
 */
void RTC_EnableFreeRunningReset(RTC_Type *base, bool enable);

/*!
 * @brief Set free running interrupt threshold.
 *
 * @param base RTC peripheral base address.
 * @param value Free running interrupt threshold value.
 */
void RTC_SetFreeRunningInterruptThreshold(RTC_Type *base, uint32_t value);

/*!
 * @brief Get free running interrupt threshold.
 *
 * @param base RTC peripheral base address.
 *
 * @return Free running interrupt threshold value.
 */
static inline uint32_t RTC_GetFreeRunningInterruptThreshold(RTC_Type *base)
{
    return base->THR_INT;
}

/*!
 * @brief Set free running reset threshold.
 *
 * @param base RTC peripheral base address.
 * @param value Free running reset threshold value.
 */
void RTC_SetFreeRunningResetThreshold(RTC_Type *base, uint32_t value);

/*!
 * @brief Get free running reset threshold.
 *
 * @param base RTC peripheral base address.
 *
 * @return Free running reset threshold value.
 */
static inline uint32_t RTC_GetFreeRunningResetThreshold(RTC_Type *base)
{
    return base->THR_RST;
}

/*!
 * @brief Get free running counter value.
 *
 * @param base RTC peripheral base address.
 *
 * @return Free running counter value
 */
static inline uint32_t RTC_GetFreeRunningCount(RTC_Type *base)
{
    uint32_t a, cnt = 0U;
    volatile uint32_t b;

    do
    {
        a = base->CNT2;
        b = base->CNT2;
        if (a == b)
        {
            break;
        }
        cnt++;
    } while (cnt < 10U);

    return b;
}

/*!
 * @brief Enable/Disable RTC free running.
 *
 * @param base RTC peripheral base address.
 * @param enable true to enable free running, false to disable.
 */
void RTC_FreeRunningEnable(RTC_Type *base, bool enable);

/*! @}*/

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the RTC status flags.
 *
 * This function get all RTC status flags, the flags are returned as the logical
 * OR value of the enumerators @ref _rtc_status_flags.
 *
 * @param base RTC peripheral base address.
 *
 * @return RTC status flags which are ORed by the enumerators in the @ref _rtc_status_flags.
 */
static inline uint32_t RTC_GetStatusFlags(RTC_Type *base)
{
    return base->STATUS;
}

/*!
 * @brief Clears status flags with the provided mask.
 *
 * This function clears RTC status flags with a provided mask.
 *
 * @param base RTC peripheral base address.
 * @param mask The status flags to be cleared, it is logical OR value of @ref _rtc_status_flags.
 */
void RTC_ClearStatusFlags(RTC_Type *base, uint32_t mask);

/*! @}*/

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enable RTC interrupts according to the provided mask.
 *
 * This function enables the RTC interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members. See @ref _rtc_interrupt_enable
 *
 * @param base RTC peripheral base address.
 * @param mask The interrupts to enable. Logical OR of @ref _rtc_interrupt_enable.
 */
void RTC_EnableInterrupts(RTC_Type *base, uint32_t mask);

/*!
 * @brief Disable RTC interrupts according to the provided mask.
 *
 * This function disables the RTC interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members. See @ref _rtc_interrupt_enable
 *
 * @param base RTC peripheral base address.
 * @param mask The interrupts to disable. Logical OR of @ref _rtc_interrupt_enable.
 */
void RTC_DisableInterrupts(RTC_Type *base, uint32_t mask);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_RTC_H_ */
