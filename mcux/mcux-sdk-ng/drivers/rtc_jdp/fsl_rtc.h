/*
 * Copyright 2025 NXP
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

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_RTC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0 */
/*! @} */

/*! @name Minimun compare value */
/*! @{ */
#define MINIMUM_RTCVAL                                                                                         \
    (4U) /*!< Minimum RTC compare value. Program RTCVAL register with the value greater than 4 if RTCF related \
            functionality is required */
#define MINIMUM_APIVAL                                                                                         \
    (4U) /*!< Minimum API compare value. Program APIVAL register with the value greater than 4 if APIF related \
            functionality is required */
/*! @} */

/*! @brief List of RTC clock divide */
typedef enum _rtc_clock_divide
{
    kRTC_ClockDivide1     = 0U,                                            /*!< Clock divide 1 */
    kRTC_ClockDivide32    = RTC_RTCC_DIV32EN_MASK,                         /*!< Clock divide 32 */
    kRTC_ClockDivide512   = RTC_RTCC_DIV512EN_MASK,                        /*!< Clock divide 512 */
    kRTC_ClockDivide16384 = RTC_RTCC_DIV32EN_MASK | RTC_RTCC_DIV512EN_MASK /*!< Clock divide 16384 */
} rtc_clock_divide_t;

/*! @brief List of RTC interrupts */
typedef enum _rtc_interrupt_enable
{
    kRTC_APIInterruptEnable                = RTC_RTCC_APIIE_MASK,  /*!< API interrupt enable, bit 14 */
    kRTC_AutonomousPeriodicInterruptEnable = RTC_RTCC_APIEN_MASK,  /*!< Autonomous periodic interrupt enable, bit 15 */
    kRTC_CounterRollOverInterruptEnable    = RTC_RTCC_ROVREN_MASK, /*!< Counter roll over interrupt Enable, bit 28 */
    kRTC_RTCInterruptEnable                = RTC_RTCC_RTCIE_MASK,  /*!< RTC interrupt enable, bit 30 */
    kRTC_AllInterruptEnable = RTC_RTCC_APIIE_MASK | RTC_RTCC_APIEN_MASK | RTC_RTCC_ROVREN_MASK | RTC_RTCC_RTCIE_MASK
    /*!< All interrupt enable */
} rtc_interrupt_enable_t;

/*! @brief List of RTC Interrupt flags */
typedef enum _RTC_status_flags
{
    kRTC_CounterRollOverInterruptFlag = RTC_RTCS_ROVRF_MASK,   /*!< Counter roll over interrupt flag, bit 10. */
    kRTC_APIInterruptFlag             = RTC_RTCS_APIF_MASK,    /*!< API interrupt flag, bit 13. */
    kRTC_InvalidAPIFlag               = RTC_RTCS_INV_API_MASK, /*!< Invalid APIVAL write flag, bit 17. */
    kRTC_InvalidRTCFlag               = RTC_RTCS_INV_RTC_MASK, /*!< Invalid RTCVAL write flag, bit 18. */
    kRTC_RTCInterruptFlag             = RTC_RTCS_RTCF_MASK,    /*!< RTC interrupt flag, bit 29. */
    kRTC_AllInterruptFlags = RTC_RTCS_ROVRF_MASK | RTC_RTCS_APIF_MASK | RTC_RTCS_RTCF_MASK, /*!< All interrupt flags */
    kRTC_AllStatusFlags    = RTC_RTCS_ROVRF_MASK | RTC_RTCS_APIF_MASK | RTC_RTCS_INV_API_MASK | RTC_RTCS_INV_RTC_MASK |
                          RTC_RTCS_RTCF_MASK                                                /*!< All status flags */
} rtc_status_flags_t;

/*!
 * @brief RTC config structure
 *
 * This structure holds the configuration settings for the RTC peripheral. To initialize this
 * structure to reasonable defaults, call the RTC_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 */
typedef struct _rtc_config
{
    rtc_clock_source_t clockSource;         /*< Select RTC clock source */
    rtc_clock_divide_t clockDivide;         /*< Select clock divide */
    bool registerAcessibleInSupervisorOnly; /*< Select register accessible in supervisor mode */
    bool freezeCounterInDebugMode;          /*< Freeze counter in debug mode */
    bool enableAnalogComparatorTrigger;     /*< Enable trigger for analog comparator  */
} rtc_config_t;

/*! @brief Callback type when registering for a callback. It tells the call back is RTC, API or counter roll over call
 * back.
 */
typedef enum
{
    kRTC_APICallback,             /*!< API interrupt callback */
    kRTC_CounterRollOverCallback, /*!< Counter roll over interrupt callback */
    kRTC_RTCCallback              /*!< RTC interrupt callback */
} rtc_callback_type_t;

/*! @brief RTC callback function. */
typedef void (*rtc_callback_t)(rtc_callback_type_t type);

/*! @} */

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
 * @brief Selects the RTC clock source and configures the RTC basic configuration.
 *
 * @note This API should be called at the beginning of the application using the RTC driver.
 *
 * @param base   RTC peripheral base address
 * @param config Pointer to the user defined RTC configuration structure.
 */
void RTC_Init(RTC_Type *base, const rtc_config_t *config);

/*!
 * @brief Deinit RTC by disabling the RTC counter and API(Autonomous Periodic Interrupt).
 *
 * @param base RTC peripheral base address
 */
void RTC_Deinit(RTC_Type *base);

/*!
 * @brief Fills in the RTC config struct with the default settings.
 *
 * The default values are as follows.
 * @code
 *     config->clockSource                       = (rtc_clock_source_t)0U;
 *     config->clockDivide                       = kRTC_ClockDivide1;
 *     config->registerAcessibleInSupervisorOnly = false;
 *     config->freezeCounterInDebugMode          = true;
 *     config->enableAnalogComparatorTrigger     = false;
 * @endcode
 *
 * @param config Pointer to the user defined RTC configuration structure.
 */
void RTC_GetDefaultConfig(rtc_config_t *config);

/*! @} */

/*!
 * @name Select Source clock and divider
 * @{
 */

/*!
 * @brief Select RTC Clock Source and divider
 *
 * @note  RTC Clock source can only be switched when CNTEN is 0. The oscillator shall be enabled before selecting it as
 *          a clock source for RTC.
 *
 * @param base   RTC peripheral base address
 * @param clock  RTC clock source.
 */
static inline void RTC_SelectSourceClock(RTC_Type *base, rtc_clock_source_t clock)
{
    assert((base->RTCC & (uint32_t)RTC_RTCC_CNTEN_MASK) == 0x0U);

    base->RTCC &= ~((uint32_t)RTC_RTCC_CLKSEL_MASK);
    base->RTCC |= RTC_RTCC_CLKSEL(clock);
}

/*!
 * @brief Set the RTC clock divide value.
 *
 * @note This API should be called after selecting clock source.
 *
 * @param base    RTC peripheral base address
 * @param divide  The Divider value.
 */
static inline void RTC_SetDivideValue(RTC_Type *base, rtc_clock_divide_t divide)
{
    base->RTCC =
        (base->RTCC & ~((uint32_t)kRTC_ClockDivide16384)) | ((uint32_t)divide & (uint32_t)kRTC_ClockDivide16384);
}

/*!
 * @brief Get the RTC Divide value.
 *
 * @param base    RTC peripheral base address
 * @return The Divider value
 */
uint32_t RTC_GetDivideValue(RTC_Type *base);

/*! @}*/

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief Enables the selected RTC interrupts.
 *
 * @param base    RTC peripheral base address
 * @param mask    The interrupts to enable. This is a logical OR of members of the
 *                enumeration ::rtc_interrupt_enable_t
 */
static inline void RTC_EnableInterrupts(RTC_Type *base, uint32_t mask)
{
    mask &= (uint32_t)kRTC_AllInterruptEnable;
    base->RTCC |= (uint32_t)mask;
}

/*!

 * @brief Disables the selected RTC interrupts.
 *
 * @param base    PIT peripheral base address
 * @param mask    The interrupts to disable. This is a logical OR of members of the
 *                enumeration ::rtc_interrupt_enable_t
 */
static inline void RTC_DisableInterrupts(RTC_Type *base, uint32_t mask)
{
    mask &= (uint32_t)kRTC_AllInterruptEnable;
    base->RTCC &= ~((uint32_t)mask);
}

/*!
 * @brief Gets the enabled RTC interrupts.
 *
 * @param base    RTC peripheral base address
 *
 * @return The enabled interrupts. This is the logical OR of members of the
 *         enumeration ::rtc_interrupt_enable_t
 */
static inline uint32_t RTC_GetEnabledInterrupts(RTC_Type *base)
{
    return (base->RTCC & (uint32_t)kRTC_AllInterruptEnable);
}

/*!
 * @brief  Get the RTC interrupt flags.
 *
 * @param base    RTC peripheral base address
 */
static inline uint32_t RTC_GetInterruptFlags(RTC_Type *base)
{
    return (base->RTCS & (uint32_t)kRTC_AllInterruptFlags);
}

/*!
 * @brief Clears the RTC interrupt flags.
 *
 * @param base    RTC peripheral base address
 * @param mask    The interrupt flags to clear. This is a logical OR of members of the
 *                enumeration ::rtc_status_flags_t
 */
static inline void RTC_ClearInterruptFlags(RTC_Type *base, uint32_t mask)
{
    mask &= (uint32_t)kRTC_AllInterruptFlags;
    base->RTCS = (uint32_t)mask;
}

/*!
 * @brief Register callback.
 *
 * @param cb_func   callback function
 */
void RTC_RegisterCallBack(rtc_callback_t cb_func);

/*! @}*/

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the RTC status flags.
 *
 * @param base RTC peripheral base address
 *
 * @return The status flags.
 */
static inline uint32_t RTC_GetStatusFlags(RTC_Type *base)
{
    return (base->RTCS & (uint32_t)kRTC_AllStatusFlags);
}

/*! @}*/

/*!
 * @name Module Operation
 */

/*!
 * @brief  Enable the RTC count. It has the effect of asynchronously resetting all the RTC and API logic.
 *         It allows RTC configuration and clock source selection to be updated without causing synchronization issues.
 *
 * @param base    RTC peripheral base address
 */
static inline void RTC_EnableRTC(RTC_Type *base)
{
    base->RTCC |= (uint32_t)RTC_RTCC_CNTEN_MASK;
}

/*!
 * @brief  Disable the RTC count.
 *
 * @param base    RTC peripheral base address
 */
static inline void RTC_DisableRTC(RTC_Type *base)
{
    base->RTCC &= ~((uint32_t)RTC_RTCC_CNTEN_MASK);
}

/*!
 * @brief  Enable the (API)autonomous periodic interrupt function.
 *
 * @param base    RTC peripheral base address
 */
static inline void RTC_EnableAPI(RTC_Type *base)
{
    base->RTCC |= (uint32_t)RTC_RTCC_APIEN_MASK;
}

/*!
 * @brief  Disable the autonomous periodic interrupt function.
 *
 * @param base    RTC peripheral base address
 */
static inline void RTC_DisableAPI(RTC_Type *base)
{
    base->RTCC &= ~((uint32_t)RTC_RTCC_APIEN_MASK);
}

/*!
 * @brief  Enable counter roll over wakeup and interrupt
 *
 * @param base  RTC peripheral base address
 */
static inline void RTC_EnableCounterRollOverWakeupInterrupt(RTC_Type *base)
{
    base->RTCC |= (uint32_t)RTC_RTCC_ROVREN_MASK;
}

/*!
 * @brief  Disable counter roll over wakeup and interrupt
 *
 * @param base  RTC peripheral base address
 */
static inline void RTC_DisableCounterRollOverWakeupInterrupt(RTC_Type *base)
{
    base->RTCC &= ~((uint32_t)RTC_RTCC_ROVREN_MASK);
}

/*!
 * @brief  Counter freezes in debug mode. The counter freezes on entering the debug mode on the last valid count value
 *   if the FRZEN bit is set. After passing of the debug mode counter starts from the frozen value.
 *
 * @param base    RTC peripheral base address
 */
static inline void RTC_EnableDebugFreeze(RTC_Type *base)
{
    base->RTCC |= (uint32_t)RTC_RTCC_FRZEN_MASK;
}

/*!
 * @brief  Counter does not freeze in debug mode.
 *
 * @param base    RTC peripheral base address
 */
static inline void RTC_DisableDebugFreeze(RTC_Type *base)
{
    base->RTCC &= ~((uint32_t)RTC_RTCC_FRZEN_MASK);
}

/*!
 * @brief Trigger enable for Analog Comparator.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_EnableAnalogComparatorTrigger(RTC_Type *base)
{
    base->RTCC |= (uint32_t)RTC_RTCC_TRIG_EN_MASK;
}

/*!
 * @brief Trigger disable for Analog Comparator.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_DisableAnalogComparatorTrigger(RTC_Type *base)
{
    base->RTCC &= ~((uint32_t)RTC_RTCC_TRIG_EN_MASK);
}

/*!
 * @brief  Get the RTC count value.
 *
 * @param base RTC peripheral base address
 * @return The Count Value.
 */
static inline uint32_t RTC_GetCountValue(RTC_Type *base)
{
    return base->RTCCNT;
}

/*!
 * @brief  Set the RTC compare value.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_SetRTCValue(RTC_Type *base, uint32_t value)
{
    assert(value > MINIMUM_RTCVAL);
    base->RTCVAL = value;
}

/*!
 * @brief  Get the RTC compare value.
 *
 * @param base RTC peripheral base address
 * @return The compare Value.
 */
static inline uint32_t RTC_GetRTCValue(RTC_Type *base)
{
    return base->RTCVAL;
}

/*!
 * @brief  Set the RTC API value.
 *
 * @param base RTC peripheral base address
 */
static inline void RTC_SetAPIValue(RTC_Type *base, uint32_t value)
{
    assert(value > MINIMUM_APIVAL);
    base->APIVAL = value;
}

/*!
 * @brief  Get the RTC API value.
 *
 * @param base RTC peripheral base address
 * @return The API Value.
 */
static inline uint32_t RTC_GetAPIValue(RTC_Type *base)
{
    return base->APIVAL;
}

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_RTC_H_ */
