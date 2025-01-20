/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_EWM_H_
#define FSL_EWM_H_

#include "fsl_common.h"

/*!
 * @defgroup ewm EWM: External Watchdog Monitor Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief EWM driver version. */
#define FSL_EWM_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup ewm_driver_log The Driver Change Log
 * @ingroup ewm
 * @{
 * The current EWM driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup ewm_intro EWM Peripheral and Driver Overview
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @ingroup ewm
 * @{
 *
 * Peripheral feature and how this peripheral works
 * ==================================================
 *
 * Features
 * --------
 *   + Independent LPO_CLK clock source
 *   + Programmable time-out period specified in terms of number of EWM LPO_CLK clock cycles.
 *   + Robust Windowed refresh
 *   + One output port, EWM_out, when asserted is used to reset or place the external circuit into safe mode
 *   + One Input port, EWM_in, allows an external circuit to control the assertion of the EWM_out signal
 *   + EWM counter will freeze in STOP/WAIT mode, work in RUN mode.
 *
 * How this driver is designed to make this peripheral work
 * ========================================================
 * This driver provides interfaces to initialize the EWM peripheral, then user can enable/disable interrupt
 * on demand. For watch dog, there's a refresh function to reload it.
 *
 * How to use this driver
 * =======================
 *   + Use EWM_Init() to enable all EWM features on demand. The EWM_GetDefaultConfig() help user to get
 *     basic setting of this peripheral, user also can modify @ref ewm_config_t in line with the actual case.
 *   + With bEnableInterrupt of @ref ewm_config_t user can choose to enable/disable EWM interrupt when this peripheral
 *     is initialized, EWM_EnableInterrupt() and EWM_DisableInterrupt() help user to enable/disable EWM interrupt after
 *     EWM_Init() has been called.
 *   + EWM_Refresh() can reload the watch dog count which is very common function for all similar peripheral.
 *   + The bEnableEwmInput and eSetInputAssertLogic of @ref ewm_config_t can enable the EWM_in signal control the assert
 *     of EWM_out.
 *
 * Typical Use Case
 * ================
 * EWM is used to monitor the flow and execution of embedded software within an MCU, refresh operation should be
 * periodically done, if the EWM is not refreshed in specified time window, EWM_Out signal will be asserted to to reset
 * or place the external circuit into safe mode.
 *
 * @code
     App_Function
     {
       EWM_GetDefaultConfig(&sConfig);
       EWM_Init(EXAMPLE_EWM, &sConfig);
       xxxxx //set up periodical timer to refresh EWM
       if(timerISR) // when timer interrupt happens, refresh EWM
       {
           EWM_Refresh(EXAMPLE_EWM);
       }
     }
   @endcode
 * @}
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @brief Assert pin voltage configuration. */
typedef enum _ewm_input_assert_state
{
    kEWM_EwmInZeroAssert = 0U, /*!< EWM-in assert with low-voltage logic */
    kEWM_EwmInOneAssert  = 1U, /*!< EWM-in assert with high-voltage logic */
} ewm_input_assert_state_t;

/*!
 * @brief Data structure for EWM configuration.
 *
 * This structure is used to configure the EWM.
 */
typedef struct _ewm_config
{
    uint8_t bEnableEWM : 1;                         /*!< Enable EWM module */
    uint8_t bEnableEWMInput : 1;                    /*!< Enable EWM_in input */
    uint8_t bEnableInterrupt : 1;                   /*!< Enable EWM interrupt */
    ewm_input_assert_state_t eInputAssertState : 1; /*!< EWM_in signal assertion state select */
#if defined(FSL_FEATURE_EWM_HAS_CLOCK_SELECT) && FSL_FEATURE_EWM_HAS_CLOCK_SELECT
    ewm_lpo_clock_source_t eClockSource : 2; /*!< Clock source select */
#endif                                       /* FSL_FEATURE_EWM_HAS_CLOCK_SELECT */
#if defined(FSL_FEATURE_EWM_HAS_PRESCALER) && FSL_FEATURE_EWM_HAS_PRESCALER
    uint8_t u8ClockDivder;      /*!< EWM counter clock is clockSource/(clockDivder+1) */
#endif                          /* FSL_FEATURE_EWM_HAS_PRESCALER */
    uint8_t u8CompareLowValue;  /*!< Compare low-register value */
    uint8_t u8CompareHighValue; /*!< Compare high-register value, maximum setting is 0xFE */
} ewm_config_t;

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name EWM initialization and de-initialization
 * @{
 */

/*!
 * @brief Initializes the EWM peripheral.
 *
 * This function is used to initialize the EWM. After calling, the EWM
 * runs immediately according to the configuration.
 * @note Except for the interrupt enable control bit, other control bits and registers are write once after a
 * CPU reset. Modifying them more than once generates a bus transfer error.
 *
 * This is an example.
 * @code
 *   ewm_config_t psConfig;
 *   EWM_GetDefaultConfig(&psConfig);
 *   psConfig.compareHighValue = 0xAAU;
 *   EWM_Init(ewm_base,&psConfig);
 * @endcode
 *
 * @param base EWM peripheral base address
 * @param psConfig The configuration of the EWM
 */
void EWM_Init(EWM_Type *base, const ewm_config_t *psConfig);

/*!
 * @brief Deinitializes the EWM peripheral.
 *
 * This function is used to shut down the EWM.
 *
 * @param base EWM peripheral base address
 */
void EWM_Deinit(EWM_Type *base);

/*!
 * @brief Initializes the EWM configuration structure.
 *
 * This function initializes the EWM configuration structure to default values. The default
 * values are as follows.
 * @code
 *   ewmConfig->bEnableEWM = true;
 *   ewmConfig->bEnableEWMInput = false;
 *   ewmConfig->eInputAssertState = kEWM_EwmInZeroAssert;
 *   ewmConfig->bEnableInterrupt = false;
 *   ewmConfig->eClockSource = kEWM_LpoClockSource0;
 *   ewmConfig->u8ClockDivder = 0;
 *   ewmConfig->u8CompareLowValue = 0;
 *   ewmConfig->u8CompareHighValue = 0xFEU;
 * @endcode
 *
 * @param psConfig Pointer to the EWM configuration structure.
 * @see ewm_config_t
 */
void EWM_GetDefaultConfig(ewm_config_t *psConfig);

/*! @} */

/*!
 * @name EWM functional Operation
 * @{
 */

/*!
 * @brief Enables the EWM interrupt.
 *
 * This function enables the EWM interrupt.
 *
 * @param base EWM peripheral base address
 */
static inline void EWM_EnableInterrupt(EWM_Type *base)
{
    base->CTRL |= EWM_CTRL_INTEN_MASK;
}

/*!
 * @brief Disables the EWM interrupt.
 *
 * This function disables the EWM interrupt.
 *
 * @param base EWM peripheral base address
 */
static inline void EWM_DisableInterrupt(EWM_Type *base)
{
    base->CTRL &= ~(uint16_t)EWM_CTRL_INTEN_MASK;
}

/*!
 * @brief Services the EWM.
 *
 * This function resets the EWM counter to zero.
 *
 * @param base EWM peripheral base address
 */
void EWM_Refresh(EWM_Type *base);

/*! @}*/

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_EWM_H_ */
