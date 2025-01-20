/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_RTC_H_
#define FSL_RTC_H_

#include "fsl_common.h"

/*!
 * @addtogroup rtc
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_RTC_DRIVER_VERSION (MAKE_VERSION(2, 1, 0)) /*!< Version 2.1.0 */
/*! @} */

/* Definition is the RTC clock source TFRO. */
#define RTC_TFRO_FREQ 32768U
/*!
 * @brief Time-out ticks is (in ARM clock ticks) that a bus synchronization wait should take.
 * Worst-case wait is 3 TFRO ticks. Worst case ARM speed is full SFRO (no divider).
 * Since the TFRO could be somewhat slower than spec'd, and the SFRO somewhat faster,
 * we add 33% as margin - it is just for an emergency time-out.
 */
#define RTC_SYNC_TIME_OUT_TICKS ((SystemCoreClock * (3 + 1)) / RTC_TFRO_FREQ)

/*! @brief List of RTC interrupts */
typedef enum _rtc_interrupt_enable
{
    kRTC_CountDownInterruptEnable = RTC_IMIS_IE_MASK, /*!< Count down interrupt.*/
} rtc_interrupt_enable_t;

/*! @brief List of RTC flags */
typedef enum _rtc_status_flags
{
    kRTC_EnabledFlag = RTC_SR_EN_MASK,     /*!< Flag for RTC enabled or not.*/
    kRTC_FreezedFlag = RTC_SR_FREEZE_MASK, /*!< Flag for RTC freezed or not. */
    kRTC_RunFlag     = RTC_SR_RUN_MASK,    /*!< Flag for RTC running status. */
} rtc_status_flags_t;

/*! @brief List of RTC raw interrupt status */
typedef enum _rtc_raw_interrupt_status
{
    kRTC_CountDownRawStatus = RTC_RIS_RIS_MASK, /*!< Raw interrupt status for count down finish.*/
} rtc_raw_interrupt_status_t;

/*! @brief List of RTC masked interrupt status */
typedef enum _rtc_masked_interrupt_status
{
    kRTC_CountDownMaskedStatus = RTC_MIS_MIS_MASK, /*!< Masked interrupt status for count down finish.*/
} rtc_masked_interrupt_status_t;

/*! @brief Structure is used to hold the date and time */
typedef struct _rtc_datetime
{
    uint16_t year;  /*!< Range from 1970 to 2099.*/
    uint8_t month;  /*!< Range from 1 to 12.*/
    uint8_t day;    /*!< Range from 1 to 31 (depending on month).*/
    uint8_t hour;   /*!< Range from 0 to 23.*/
    uint8_t minute; /*!< Range from 0 to 59.*/
    uint8_t second; /*!< Range from 0 to 59.*/
} rtc_datetime_t;

/*! @brief Structure used for configuration. */
typedef struct _rtc_config
{
    bool enableAutoStart;      /*!< Enable count down auto start.*/
    bool enableTimer;          /*!< Enable RTC timer. */
    uint32_t calibrationValue; /* Set calibration value. */
    rtc_datetime_t date;       /* Set date value. */
} rtc_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Bus synchornous operations.
 * @{
 */

/*!
 *@brief Write value to RTC register.
 *
 *@note This API will write data to RTC register, all bus synchornous operation will be done.
 *
 */
void RTC_WriteRegister(__IO uint32_t *reg, uint32_t value);

/*!
 *@brief Read data from RTC register.
 *
 *@note This API will read the RTC's register value.
 *
 */
uint32_t RTC_ReadRegister(__I uint32_t *reg);
/*! @}*/

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initalize the RTC mudule.
 *
 * @note This API should be called at the beginning of the application using the RTC driver.
 *       This API will help configure the calibration value, count down auto start, enable RTC timer
 *       and the initialized date for counting.
 *
 * @param base RTC peripheral base address
 * @param config  configuration for initializing RTC.
 */
void RTC_Init(RTC_Type *base, rtc_config_t *config);

/*!
 * @brief Stop the timer and gate the RTC clock
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_Deinit(RTC_Type *base)
{
    /* Stop the RTC timer */
    RTC_WriteRegister(&base->CR, 0U);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the module clock */
    CLOCK_DisableClock(kCLOCK_Rtc);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * @brief Get default config for RTC setting.
 *        This configure structure will help setup calibration value, formated date value.
 *        And set if enable RTC timer and count down auto start function.
 *
 * @param base RTC peripheral base address
 * @param config Configure structure for setting RTC module. Refer to @ref rtc_config_t.
 */
void RTC_GetDefaultConfig(RTC_Type *base, rtc_config_t *config);
/*! @}*/

/*!
 * @name Current Time date.
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
 * @param base     RTC peripheral base address
 * @param datetime Pointer to structure where the date and time details are stored.
 */
void RTC_GetDatetime(RTC_Type *base, rtc_datetime_t *datetime);

/*!
 * @brief Sets the RTC sleep time
 *
 * The function will set the sleep time for counting down, if the value in SLEEPT register
 * equals to 0, an interrupt will be generated if this interrupt is enabled.
 *
 * @param base    RTC peripheral base address
 * @param value   sleep time, uint is seconds.
 */
static inline void RTC_SetSleepTime(RTC_Type *base, uint32_t value)
{
    assert(value != 0U);

    RTC_WriteRegister(&base->SLEEPT, value);
}
/*!
 * @brief Returns the current RTC sleep time value.
 *
 * @param base   RTC peripheral base address
 * @return The sleep remaining in register.
 */
static inline uint32_t RTC_GetSleepTime(RTC_Type *base)
{
    return (RTC_ReadRegister(&base->SLEEPT));
}
/*! @}*/

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief Enables the selected RTC interrupts.
 *
 * @param base RTC peripheral base address
 * @param mask The interrupts to enable.
 *             Refer to the enumeration ::rtc_interrupt_enable_t
 */
static inline void RTC_EnableInterrupts(RTC_Type *base, uint32_t mask)
{
    RTC_WriteRegister(&base->IMIS, mask);
}

/*!
 * @brief Disables the selected RTC interrupts.
 *
 * @param base RTC peripheral base address
 * @param mask The interrupts to enable. This is a logical OR of members of the
 *             enumeration ::rtc_interrupt_enable_t
 */
static inline void RTC_DisableInterrupts(RTC_Type *base, uint32_t mask)
{
    RTC_WriteRegister(&base->IMIS, ~mask);
}
/*! @}*/

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Gets the RTC status flags
 *
 * @param base RTC peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::rtc_status_flags_t
 */
static inline uint32_t RTC_GetStatusFlags(RTC_Type *base)
{
    return RTC_ReadRegister(&base->SR);
}

/*!
 * @brief Gets the RTC Raw interrupt status.
 *
 * @param base RTC peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::rtc_status_flags_t
 */
static inline uint32_t RTC_GetRawInterruptStatus(RTC_Type *base)
{
    return RTC_ReadRegister(&base->RIS);
}

/*!
 * @brief Gets the RTC status flags
 *
 * @param base RTC peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::rtc_status_flags_t
 */
static inline uint32_t RTC_GetMaskedInterruptStatus(RTC_Type *base)
{
    return RTC_ReadRegister(&base->MIS);
}

/*!
 * @brief Clear masked interrupt status.
 *
 * @param base RTC peripheral base address.
 * @param mask The interrupts to enable.
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::rtc_masked_interrupt_status_t
 */
static inline void RTC_ClearMaskedInterruptStatus(RTC_Type *base, uint32_t mask)
{
    RTC_WriteRegister(&base->ICR, ~mask);
}
/*! @}*/

/*!
 * @name Timer Start and Stop
 * @{
 */

/*!
 * @brief Starts the RTC time counter.
 *
 * After calling this function, the timer counter increments once a second.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_StartTimer(RTC_Type *base)
{
    uint32_t reg = 0U;
    reg          = RTC_ReadRegister(&base->CR);
    reg |= RTC_CR_EN_MASK;
    RTC_WriteRegister(&base->CR, reg);
}

/*!
 * @brief Stops the RTC time counter.
 *
 * RTC's seconds register can be written to only when the timer is stopped.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_StopTimer(RTC_Type *base)
{
    uint32_t reg = 0U;
    reg          = RTC_ReadRegister(&base->CR);
    reg &= ~RTC_CR_EN_MASK;
    RTC_WriteRegister(&base->CR, reg);
}

/*!
 * @brief Enable the sleep count down auto Start.
 *
 * @param base   RTC peripheral base address
 * @param enable 1 for enable, 0 for disable.
 */
void RTC_EnableSleepAutoStart(RTC_Type *base, bool enable);

/*!
 * @brief Start the count down manually.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_StartSleep(RTC_Type *base)
{
    uint32_t reg = 0U;
    reg          = RTC_ReadRegister(&base->CR);
    reg |= RTC_CR_START_MASK;
    RTC_WriteRegister(&base->CR, reg);
}

/*!
 * @brief Set calibration value.
 *        The calibration value decide the number of TFRO clock pulses in one tick
 *
 * @param base RTC peripheral base address
 * @param value The value to be set.
 */
static inline void RTC_SetCalibrationValue(RTC_Type *base, uint32_t value)
{
    RTC_WriteRegister(&base->CAL, value);
}

/*!
 * @brief Get the calibration value from register.
 *
 * @param base RTC peripheral base address
 */
static inline uint32_t RTC_GetCalibrationValue(RTC_Type *base)
{
    return (RTC_ReadRegister(&base->CAL));
}
/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_RTC_H_ */
