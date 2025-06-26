/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_PIT_H_
#define FSL_PIT_H_

#include "fsl_common.h"

/*!
 * @defgroup pit PIT: Periodic Interrupt Timer (PIT) Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief PIT driver version. */
#define FSL_PIT_DRIVER_VERSION (MAKE_VERSION(2, 3, 1))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup pit_driver_log The Driver Change Log
 * @ingroup pit
 * @{
 * The current PIT driver version is 2.3.0.
 * - 2.3.0
 *   - Improvements
 *     - Filtered Preset input to reset PIT counter.
 *     - Support SYNC_OUT output stretch and toggle mode.
 *     - Added PIT_SetPresetFiltConfig() to set FILT register configurations.
 *     - Added PIT_SetSyncOutConfig() to set SYNC register configurations.
 *
 * - 2.2.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.2.0
 *   - Improvements
 *     - Updated pit_config_t member naming.
 *     - Removed some APIs for prescaler and clock source selection.
 *
 * - 2.1.0
 *   - Improvements
 *     - Updated PIT clock source and PIT prescaler with more meaningful comments.
 *     - Updated PIT_SetTimerPeriod() and PIT_GetCurrentTimerCount() with 16-bit parameter.
 *     - Deleted mask parameter for PIT_ClearStatusFlags/PIT_EnableInterrupts/PIT_DisableInterrupts.
 *     - Added PIT_SetTimerClockSource() API to configure clock source.
 *     - Added PIT_EnableSlaveMode() API to configure slave mode.
 *
 * - 2.0.1
 *   - New Features
 *     - Added PIT_SetTimerPrescaler() API to configure clock prescaler value.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup pit_intro PIT Peripheral and Driver Overview
 * @ingroup pit
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method
 * @{
 *
 * Peripheral features and how this peripheral works
 * ==================================================
 * The programmable interval timer module (PIT) contains clock select logic, a up counter,
 * a modulo register, and a control register. The purpose of the PIT is to create a repeated
 * interrupt request at a programmable time interval.
 *
 *  Features
 *  ---------
 *  + 32-bit counter/timer if defined FSL_FEATURE_PIT_32BIT_COUNTER, else 16-bit counter/timer.
 *  + Programmable count modulo which determines counting period. If defined FSL_FEATURE_PIT_32BIT_COUNTER,
 * 32-bit count modulo, else 16-bit modulo.
 *  + Selectable clock sources, up to 4.
 *  + Programmable clock prescaler, maximum count rate equal to clocking rate.
 *  + Support interrupt generation for counter roll over from 0, interrupt could be enabled/disabled.
 *  + Support slave mode, allows one PIT work as master to sync multiple PIT count with master enable, by
 * default, PIT0 is the master PIT. This configuration could be changed in SIM_MISC0.
 *
 *  How this peripheral works
 *  -------------------------
 *  1. Configure PIT features, set period timeout value.
 *  2. Enable interrupt, Enable timer
 *  3. PIT will enter interrupt according to configured period repeatedly
 *
 *  Low Power Modes
 *  ---------------
 *  + If the PIT is enable prior to entering wait mode, then the PIT continues to count and can wake
 * the chip by asserting its interrupt upon reaching the modulo value.
 *  + Stop mode operation depends on whether the system integration module (SIM) is set to allow the
 * PIT to be clocked in stop mode.
 *    - If not, the PIT counter does not operate during stop mode, but does retain its current settings.
 *   If PIT timer is enabled/started, then the counter resumes counting upon exit of stop mode
 *   assuming the exit isn't caused by a reset.
 *    - If the PIT does receive clocks while the chip is in stop mode, then operation continues normally.
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 * The pit driver provides a structure @ref pit_config_t which contains all the programmable features of PIT. The
 * PIT_Init() function takes the argument of the structure pointer and configures the PIT features accordingly.
 * Besides initialize operation, PIT driver provide several functional groups to do feature re-configuration,
 * interrupt enable/disable and status flag get and clear. Functional groups are simply described as below:
 *
 *  + Initialization and deinitialization Interfaces
 *      The APIs in the functional group is used to initialize/deinitialize PIT module.
 *  + PIT operation Interfaces
 *      The APIs in this functional group allows user to re-configure the PIT features and Start/Stop PIT timer.
 *  + Interrupt control Interfaces
 *      The APIs in this functional group can be used to enable/disable PIT interrupt
 *  + PIT Status Flag Interfaces
 *      The APIs in this functional group can be used to get/clear PIT status
 *
 * How to use this driver
 * =======================
 *  + Sets the PIT features by invoking PIT_Init()
 *    - Defines the variable in type of @ref pit_config_t. This variable takes 12 Bytes space.
 *    - [Optional] Invokes PIT_GetDefaultConfig() function with the pointer of variable which is type of
 *      @ref pit_config_t to get the default options.
 *    - Sets the member of the variable which is in type of @ref pit_config_t.
 *    - Invoke PIT_Init to set the PIT features
 *  + Implement interrupt handler to handle the PIT interrupt if PIT interrupt is enabled.
 *    - If bEnableInterrupt is set to true, then interrupt is enabled after call PIT_Init.
 *    - If interrupt is not enabled after call PIT_Init, call PIT_EnableInterrupt to enable interrupt.
 *  + Enable timer if needed
 *    - For some cases, user do not want to enable clock at the beginning, after call to PIT_Init, user could
 *      call PIT_StartTimer() to start the timer.
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief PIT clock prescaler values*/
typedef enum _pit_prescaler_value
{
    kPIT_PrescalerDivBy1     = 0x0U, /*!< Clock divided by 1 */
    kPIT_PrescalerDivBy2     = 0x1U, /*!< Clock divided by 2 */
    kPIT_PrescalerDivBy4     = 0x2U, /*!< Clock divided by 4 */
    kPIT_PrescalerDivBy8     = 0x3U, /*!< Clock divided by 8 */
    kPIT_PrescalerDivBy16    = 0x4U, /*!< Clock divided by 16 */
    kPIT_PrescalerDivBy32    = 0x5U, /*!< Clock divided by 32 */
    kPIT_PrescalerDivBy64    = 0x6U, /*!< Clock divided by 64 */
    kPIT_PrescalerDivBy128   = 0x7U, /*!< Clock divided by 128 */
    kPIT_PrescalerDivBy256   = 0x8U, /*!< Clock divided by 256 */
    kPIT_PrescalerDivBy512   = 0x9U, /*!< Clock divided by 512 */
    kPIT_PrescalerDivBy1024  = 0xAU, /*!< Clock divided by 1024 */
    kPIT_PrescalerDivBy2048  = 0xBU, /*!< Clock divided by 2048 */
    kPIT_PrescalerDivBy4096  = 0xCU, /*!< Clock divided by 4096 */
    kPIT_PrescalerDivBy8192  = 0xDU, /*!< Clock divided by 8192 */
    kPIT_PrescalerDivBy16384 = 0xEU, /*!< Clock divided by 16384 */
    kPIT_PrescalerDivBy32768 = 0xFU  /*!< Clock divided by 32768 */
} pit_prescaler_value_t;

/*! @brief List of PIT status flags */
enum _pit_status_flags
{
    kPIT_Timer_RollOverFlag = PIT_CTRL_PRF_MASK, /*!< Timer roll over flag */
};

/*! @brief List of SYNC_OUT output mode */
#if defined(FSL_FEATURE_PIT_HAS_CTRL2) && FSL_FEATURE_PIT_HAS_CTRL2
typedef enum _pit_syncout_mode
{
    kPIT_Syncout_Default = 0x0U, /*!< SYNC_OUT takes affect when PIT counter equals to the MODULO value (default)*/
    kPIT_Syncout_Toggle  = 0x1U  /*!< SYNC_OUT is in toggle mode */
} pit_syncout_mode_t;
#endif

/*!
 * @brief PIT FILT configuration structure
 *
 * This structure holds the configuration settings for the PIT FILT register. To initialize this
 * structure to reasonable defaults, call the PIT_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
#if defined(FSL_FEATURE_PIT_HAS_FILT) && FSL_FEATURE_PIT_HAS_FILT
typedef struct _pit_config_filt
{
    bool bFilterClock : 1;                                /*!<Filter Clock Source selection. */
    pit_prescaler_value_t eFilterPrescalerPeripheral : 4; /*!<Sets the peripheral clock prescaler. */
    uint8_t u16FilterSampleCount : 3;                     /*!< Input Filter Sample Count. */
    uint8_t u16FilterSamplePeriod;                        /*!< Input Filter Sample Period. */
} pit_config_filt_t;
#endif

/*!
 * @brief PIT CTRL2 configuration structure
 *
 * This structure holds the configuration settings for the PIT CTRL2 register. To initialize this
 * structure to reasonable defaults, call the PIT_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
#if defined(FSL_FEATURE_PIT_HAS_CTRL2) && FSL_FEATURE_PIT_HAS_CTRL2
typedef struct _pit_config_ctrl2
{
    uint8_t u8StretchCount : 3;         /*!< The cycle number to be stretched for SYNC_OUT signal.*/
    pit_syncout_mode_t eSyncOutSel : 1; /*!<Select the output mode of SYNC_OUT.*/
} pit_config_ctrl2_t;
#endif

/*!
 * @brief PIT configuration structure
 *
 * This structure holds the configuration settings for the PIT peripheral. To initialize this
 * structure to reasonable defaults, call the PIT_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
typedef struct _pit_config
{
    pit_prescaler_value_t ePrescaler : 5;  /*!< Clock prescaler value */
    bool bEnableInterrupt : 1;             /*!< Enable PIT Roll-Over Interrupt */
    bool bEnableSlaveMode : 1;             /*!< Enable the PIT module in slave mode, in which mode the timer
                                      will be triggered by master PIT enable.*/
    bool bEnableTimer : 1;                 /*!< PIT timer enable flag, which is false by default */
    pit_count_clock_source_t eClockSource; /*!< Specify the PIT count clock source */
#if defined(FSL_FEATURE_PIT_32BIT_COUNTER) && FSL_FEATURE_PIT_32BIT_COUNTER
    uint32_t u32PeriodCount; /*!< Timer period in clock cycles, Use macro definition MSEC_TO_COUNT
                              * to convert value in ms to count of ticks, the COP clock rate is
                              * source clock divide prescaler. */
#else
    uint16_t u16PeriodCount; /*!< Timer period in clock cycles, Use macro definition MSEC_TO_COUNT
                              * to convert value in ms to count of ticks, the COP clock rate is
                              * source clock divide prescaler. */
#endif
#if defined(FSL_FEATURE_PIT_CTRL_HAS_PRESET_POLARITY_BIT) && FSL_FEATURE_PIT_CTRL_HAS_PRESET_POLARITY_BIT
    bool bEnableNegativeEdge; /*!< choose the polarity of Preset input. */
#endif
#if defined(FSL_FEATURE_PIT_HAS_FILT) && FSL_FEATURE_PIT_HAS_FILT
    pit_config_filt_t sPresetFilter; /*!< Specify the PIT preset filter source */
#endif
#if defined(FSL_FEATURE_PIT_HAS_CTRL2) && FSL_FEATURE_PIT_HAS_CTRL2
    pit_config_ctrl2_t sSyncSource; /*!< Specify the PIT Sync source */
#endif
} pit_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization Interfaces
 * @{
 */

/*!
 * @brief Ungates the PIT clock, configures the PIT features.
 * The configurations are:
 * - Clock source selection for PIT module
 * - Prescaler configuration to the input clock source
 * - PIT period interval
 * - PIT slave mode enable/disable
 * - Interrupt enable/disable
 * - PIT timer enable/disable
 * - Preset Polarity positive edge/negative edge
 *
 * @note This API should be called at the beginning of the application using the PIT driver and call PIT_StartTimer()
 * API to start PIT timer.
 *
 * @param base   PIT peripheral base address
 * @param psConfig Pointer to the user's PIT config structure
 */
void PIT_Init(PIT_Type *base, const pit_config_t *psConfig);

/*!
 * @brief Gates the PIT clock and disables the PIT module.
 *
 * @param base PIT peripheral base address
 */
void PIT_Deinit(PIT_Type *base);

/*!
 * @brief  Fill in the PIT config structure with the default settings
 *
 * This function initializes the PIT configuration structure to default values.
 * @code
 *    psConfig->eClockSource = kPIT_CountClockSource0;
 *    psConfig->bEnableTimer = false;
 *    psConfig->bEnableSlaveMode = false;
 *    psConfig->ePrescaler = kPIT_PrescalerDivBy1;
 *    psConfig->bEnableInterrupt = false;
 *    psConfig->u32PeriodCount = 0xFFFFFFFFU;
 *    psConfig->bEnableNegativeEdge = false;
 *    psConfig->sPresetFilter.u16FilterSamplePeriod = 0x0U;
 *    psConfig->sPresetFilter.u16FilterSampleCount = 0x0U;
 *    psConfig->sPresetFilter.bFilterClock = true;
 *    psConfig->sPresetFilter.eFilterPrescalerPeripheral = kPIT_PrescalerDivBy1;
 *    psConfig->sSyncSource.u8StretchCount = 0x0U;
 *    psConfig->sSyncSource.eSyncOutSel = kPIT_Syncout_Default;
 * @endcode
 * @param psConfig Pointer to user's PIT config structure.
 */
void PIT_GetDefaultConfig(pit_config_t *psConfig);

/*! @}*/

/*!
 * @name PIT operation Interfaces
 * @{
 */

/*!
 * @brief Enable/Disable PIT slave mode.
 *
 * @param base    PIT peripheral base address
 * @param bEnable  enable/disable  slave mode
 */
static inline void PIT_EnableSlaveMode(PIT_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL = base->CTRL & (~(uint16_t)PIT_CTRL_SLAVE_MASK);
    }
    else
    {
        base->CTRL = base->CTRL | PIT_CTRL_SLAVE_MASK;
    }
}

/*!
 * @brief Sets the PIT clock prescaler.
 *
 * @param base    PIT peripheral base address
 * @param ePrescaler   Timer prescaler value
 */
static inline void PIT_SetTimerPrescaler(PIT_Type *base, pit_prescaler_value_t ePrescaler)
{
    base->CTRL = (base->CTRL & (~(uint16_t)PIT_CTRL_PRESCALER_MASK)) | PIT_CTRL_PRESCALER(ePrescaler);
}

#if defined(FSL_FEATURE_PIT_32BIT_COUNTER) && FSL_FEATURE_PIT_32BIT_COUNTER
/*!
 * @brief Sets the timer period in units of count.
 *
 * Timers begin counting from 0 until it reaches the value set by this function,
 * then it generates an interrupt and counter resumes counting from 0 again.
 *
 * @note Users can call the utility macros provided in fsl_common.h to convert to ticks.
 *
 * @param base    PIT peripheral base address
 * @param u32PeriodCount   Timer period in units of ticks, use macro definition MSEC_TO_COUNT
 * to convert value in ms to count of ticks, the PIT clock rate is source clock
 * divide prescaler.
 */
static inline void PIT_SetTimerPeriod(PIT_Type *base, uint32_t u32PeriodCount)
{
    base->MOD_L = (uint16_t)(u32PeriodCount & 0xFFFFU);
    base->MOD_H = (uint16_t)((u32PeriodCount >> 16U) & 0xFFFFU);
}
#else
/*!
 * @brief Sets the timer period in units of count.
 *
 * Timers begin counting from 0 until it reaches the value set by this function,
 * then it generates an interrupt and counter resumes counting from 0 again.
 *
 * @note Users can call the utility macros provided in fsl_common.h to convert to ticks.
 *
 * @param base    PIT peripheral base address
 * @param u16PeriodCount   Timer period in units of ticks, use macro definition MSEC_TO_COUNT
 * to convert value in ms to count of ticks, the PIT clock rate is source clock
 * divide prescaler.
 */
static inline void PIT_SetTimerPeriod(PIT_Type *base, uint16_t u16PeriodCount)
{
    base->MOD = u16PeriodCount;
}
#endif
/*!
 * @brief Reads the current timer counting value.
 *
 * This function returns the real-time timer counting value, in a range from 0 to a
 * timer period.
 *
 * @note Users can call the utility macros provided in fsl_common.h to convert ticks to usec or msec.
 *
 * @param base    PIT peripheral base address
 *
 * @return Current timer counting value in ticks, use macro definition COUNT_TO_MSEC
 * to convert value in ticks to count of millisecond, the PIT clock rate is source clock
 * divide prescaler.
 */
#if FSL_FEATURE_PIT_32BIT_COUNTER
static inline uint32_t PIT_GetCurrentTimerCount(PIT_Type *base)
{
    return (((uint32_t)(base->CNTR_H)) << 16U) | ((uint32_t)(base->CNTR_L));
}
#else
static inline uint16_t PIT_GetCurrentTimerCount(PIT_Type *base)
{
    return base->CNTR;
}
#endif

/*!
 * @brief Starts the timer counting.
 *
 * After calling this function, timers load period value, count down to 0 and
 * then load the respective start value again. Each time a timer reaches 0,
 * it generates a trigger pulse and sets the timeout interrupt flag.
 *
 * @param base    PIT peripheral base address
 */
static inline void PIT_StartTimer(PIT_Type *base)
{
    base->CTRL |= PIT_CTRL_CNT_EN_MASK;
}

/*!
 * @brief Stops the timer counting.
 *
 * This function stops timer counting, and the counter remains at or returns to
 * a 0 value.
 *
 * @param base    PIT peripheral base address
 */
static inline void PIT_StopTimer(PIT_Type *base)
{
    base->CTRL &= ~(uint16_t)PIT_CTRL_CNT_EN_MASK;
}

/*! @}*/

/*!
 * @name Interrupt control Interfaces
 * @{
 */

/*!
 * @brief Enables the PIT interrupts.
 *
 * @param base    PIT peripheral base address
 */
static inline void PIT_EnableInterrupt(PIT_Type *base)
{
    base->CTRL |= PIT_CTRL_PRIE_MASK;
}

/*!
 * @brief Disables the selected PIT interrupts.
 *
 * @param base    PIT peripheral base address
 */
static inline void PIT_DisableInterrupt(PIT_Type *base)
{
    base->CTRL &= ~(uint16_t)PIT_CTRL_PRIE_MASK;
}

/*! @}*/

/*!
 * @name PIT Status Flag Interfaces.
 * @{
 */

/*!
 * @brief Gets the PIT status flags.
 *
 * @param base    PIT peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::_pit_status_flags
 */
static inline uint16_t PIT_GetStatusFlags(PIT_Type *base)
{
    return (base->CTRL & PIT_CTRL_PRF_MASK);
}

/*!
 * @brief  Clears the PIT status flags.
 *
 * @param base    PIT peripheral base address
 */
static inline void PIT_ClearStatusFlags(PIT_Type *base)
{
    base->CTRL &= ~(uint16_t)PIT_CTRL_PRF_MASK;
}

/*! @}*/

/*!
 * @name Preset filt control Interfaces
 * @{
 */

#if defined(FSL_FEATURE_PIT_HAS_FILT) && FSL_FEATURE_PIT_HAS_FILT
/*!
 * @brief Set FILT configurations
 *
 * @param base    PIT peripheral base address
 * @param psConfig  Pointer to user's PIT FILT config structure
 */
static inline void PIT_SetPresetFiltConfig(PIT_Type *base, const pit_config_filt_t psConfig)
{
    base->FILT = PIT_FILT_PER(psConfig.u16FilterSamplePeriod) | PIT_FILT_CNT(psConfig.u16FilterSampleCount) |
                 PIT_FILT_CS(psConfig.bFilterClock) | PIT_FILT_PRSC(psConfig.eFilterPrescalerPeripheral);
}
#endif

/*! @}*/

/*!
 * @name Sync control Interfaces
 * @{
 */

#if defined(FSL_FEATURE_PIT_HAS_CTRL2) && FSL_FEATURE_PIT_HAS_CTRL2
/*!
 * @brief Set Sync configurations
 *
 * @param base    PIT peripheral base address
 * @param psConfig  Pointer to user's PIT SYNC config structure
 */
static inline void PIT_SetSyncOutConfig(PIT_Type *base, const pit_config_ctrl2_t psConfig)
{
    base->CTRL2 = PIT_CTRL2_STRETCH_COUNT(psConfig.u8StretchCount) | PIT_CTRL2_SYNC_OUT_SEL(psConfig.eSyncOutSel);
}
#endif

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_PIT_H_ */
