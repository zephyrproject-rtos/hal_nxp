/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_COP_H_
#define FSL_COP_H_

#include "fsl_common.h"

/*!
 * @defgroup cop COP: Computer Operating Properly(Watchdog) Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief COP driver version. */
#define FSL_COP_DRIVER_VERSION (MAKE_VERSION(2, 2, 3))
/*! @} */

/*******************************************************************************
 * COP peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup cop_driver_log The Driver Change Log
 * @ingroup cop
 * @{
 * The current COP driver version is 2.2.2.
 *
 * - 2.2.2
 *   - Bug Fixes
 *     - Added configuration of CWP bits in COP_Init, fixed write protection bEnableWriteProtect cannot be configured as
 * 		 part of cop_config_t.
 *
 * - 2.2.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.2.0
 *   - Improvements
 *     - Updated cop_config_t member naming.
 *     - Deleted COP_Disable API, added COP_Enable to enable/disable COP.
 *
 * - 2.1.0
 *   - Improvements
 *     - API interface changes:
 *       - Renamed "COP_EnableInterrupts/COP_DisableInterrupts" to "COP_EnableInterrupt/COP_DisableInterrupt"
 *         and remove unnecessary parameter.
 *   - New Features
 *     - Added APIs to enable/disable the COP COP Loss of Reference counter.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup cop_intro COP Peripheral and Driver Overview
 * @ingroup cop
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method.
 * @{
 * Peripheral features and how this peripheral works
 * ==================================================
 * The computer operating properly (COP) module is used to help software recover from runaway code. It's a
 * free-running down counter that, once enabled, is designed to generate a reset upon reaching zero.
 * Software must periodically service the COP in order to reload the counter and prevent a reset.
 *
 *  Features
 *  ---------
 *  + Choice of clock sources for counter, integrated low speed oscillator
 *  + Programmable prescaler to input clock source
 *  + Programmable timeout period= (cop_prescaler*(TIMEOUT + 1)) clock cycles, where TIMEOUT can
 * be from 0x0000 to 0xFFFF
 *  + Programmable window timing to ensure that servicing doesn't occur too soon
 *  + Programmable work enablement under WAIT and STOP mode
 *  + COP timer is disabled while the DSC is in debug mode
 *  + COP will assert different system reset signals according to situation, status could be read out in SIM_RSTAT:
 *    - COP_RST_B, assert when COP counter counts down to zero
 *    - COP_WNDW_RST_B, assert when COP counter is serviced when the count is greater than the WINDOW value
 *    - LOR_RST_B, assert loss of reference reset 128 cycles after loss of reference clock to the PLL is detected
 *  + COP supports interrupt generation:
 *    - Programmable interrupt timing configuration, interrupt can occur when the counter matches interrupt timing
 * configuration when interrupt is enabled.
 *  + COP feature operation write protect, once write protect is enabled, all configured features cannt be changed
 * until reset the module.
 *
 *  How this peripheral works
 *  -------------------------
 *  1. Configure the COP features properly, enable COP
 *  2. Service periodically to prevent reset event
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 * The cop driver provides a structure @ref cop_config_t which contains all the programmable features of COP. The
 * COP_Init() function takes the argument of structure pointer to @ref cop_config_t and configures the COP features,
 * then enable COP. For the most simple user scenarios, only need to provide COP service function to feed the COP timer
 * to avoid reset. But considering user may have some enhanced situation which needs to re-configure the features, such
 * as to re-install timeout value, enable/disable interrupt functionality of COP, several function groups are designed
 * as below:
 *
 *  + Initialization Interfaces
 *      The APIs in the functional group is used to initialize COP module.
 *  + COP operation Interfaces
 *      The APIs in this functional group allows user to re-configure the COP features and service COP timer.
 *  + Interrupt control Interfaces
 *      The APIs in this functional group can be used to enable/disable COP interrupt
 *
 * How to use this driver
 * =======================
 *  + Sets the COP features by invoking COP_Init()
 *    - Defines the variable in type of @ref cop_config_t. This variable takes 10 Bytes space.
 *    - [Optional] Invokes COP_GetDefaultConfig() function with the pointer of variable which is type of
 *      @ref cop_config_t to get the default options.
 *    - Sets the member of the variable which is in type of @ref cop_config_t.
 *    - Invoke COP_Init to set the COP features and enable COP.
 *  + Call to COP service API to feed COP periodically by invoking COP_Refresh()
 * @}
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name COP refresh sequence. */
/*! @{ */
/*! @brief COP refresh key word. */
#define COP_FIRST_WORD_OF_REFRESH  (0x5555U) /*!< First word of refresh sequence */
#define COP_SECOND_WORD_OF_REFRESH (0xAAAAU) /*!< Second word of refresh sequence */
/*! @} */

/*! @brief enumeration for COP clock source selection. */
typedef enum _cop_clock_source
{
    kCOP_RoscClockSource = 0U, /*!< COP clock sourced from Relaxation oscillator (ROSC) */
    kCOP_CoscClockSource = 1U, /*!< COP clock sourced from Crystal oscillator (COSCs)*/
    kCOP_BusClockSource  = 2U, /*!< COP clock sourced from IP Bus clock */
    kCOP_LpoClockSource  = 3U, /*!< COP clock sourced from Low speed oscillator */
} cop_clock_source_t;

/*! @brief enumeration for COP clock prescaler to input source clock. */
typedef enum _cop_clock_prescaler
{
    kCOP_ClockPrescalerDivide1    = 0U, /*!< Divided by 1 */
    kCOP_ClockPrescalerDivide16   = 1U, /*!< Divided by 16 */
    kCOP_ClockPrescalerDivide256  = 2U, /*!< Divided by 256 */
    kCOP_ClockPrescalerDivide1024 = 3U, /*!< Divided by 1024 */
} cop_clock_prescaler_t;

/*! @brief structure for COP module initialization configuration. */
typedef struct _cop_config
{
    bool bEnableWriteProtect : 1;        /*!< Set COP Write protected */
    bool bEnableStop : 1;                /*!< Enable or disable COP in STOP mode */
    bool bEnableWait : 1;                /*!< Enable or disable COP in WAIT mode */
    bool bEnableLossOfReference : 1;     /*!< Enable or disable COP loss of reference counter */
    bool bEnableInterrupt : 1;           /*!< Enables or disables COP interrupt */
    bool bEnableCOP : 1;                 /*!< Enables or disables COP module */
    cop_clock_source_t eClockSource : 2; /*!< Set COP clock source */
    cop_clock_prescaler_t ePrescaler;    /*!< Set COP clock prescaler */
    uint16_t u16TimeoutCount;            /*!< Timeout count in clock cycles, Use macro definition MSEC_TO_COUNT
                                          * to convert value in ms to count of ticks, the COP clock rate is
                                          * source clock divide prescaler. */
#if (defined(FSL_FEATURE_COP_HAS_WINDOW_REGISTER) && FSL_FEATURE_COP_HAS_WINDOW_REGISTER)
    uint16_t u16WindowCount; /*!< Window count in clock cycles, Use macro definition MSEC_TO_COUNT
                              * to convert value in ms to count of ticks, the COP clock rate is
                              * source clock divide prescaler. */
#endif
    uint16_t u16InterruptCount; /*!< Interrupt count in clock cycles, Use macro definition MSEC_TO_COUNT
                                 * to convert value in ms to count of ticks, the COP clock rate is
                                 * source clock divide prescaler. */
} cop_config_t;

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*!
 * @name Initialization Interfaces
 * @{
 */

/*!
 * @brief Initializes the COP module with input configuration
 *
 * Call this function to do initialization configuration for COP module.
 * The configurations are:
 * - COP configuration write protect enablement
 * - Clock source selection for COP module
 * - Prescaler configuration to the input clock source
 * - Counter timeout value
 * - Window value
 * - WAIT/STOP work mode enablement
 * - Interrupt enable/disable and interrupt timing value
 * - Loss of reference counter enablement
 * - COP enable/disable
 *
 * note: Once set bEnableWriteProtect=true, the CTRL, INTVAL, WINDOW and TOUT registers are read-only.
 *
 * @param base   COP peripheral base address.
 * @param psConfig The pointer to COP configuration structure, @ref cop_config_t.
 */
void COP_Init(COP_Type *base, const cop_config_t *psConfig);

/*!
 * @brief Prepares an available pre-defined setting for module's configuration.
 *
 * This function initializes the COP configuration structure to default values.
 * @code
 *   psConfig->bEnableWriteProtect = false;
 *   psConfig->bEnableWait = false;
 *   psConfig->bEnableStop = false;
 *   psConfig->bEnableLossOfReference = false;
 *   psConfig->bEnableInterrupt = false;
 *   psConfig->bEnableCOP       = false;
 *   psConfig->ePrescaler = kCOP_ClockPrescalerDivide1;
 *   psConfig->u16TimeoutCount = 0xFFFFU;
 *   psConfig->u16WindowCount = 0xFFFFU;
 *   psConfig->u16InterruptCount = 0xFFU;
 *   psConfig->eClockSource = kCOP_RoscClockSource;
 * @endcode
 **

 * @param psConfig Pointer to the COP configuration structure, @ref cop_config_t.
 */
void COP_GetDefaultConfig(cop_config_t *psConfig);
/*! @} */

/*!
 * @name COP Operation Interfaces
 * @{
 */
/*!
 * @brief Enable/Disable the COP module.
 *
 * This function disables the COP Watchdog.
 * To disable the COP Watchdog, call COP_Enable(base, false).
 * @param base  COP peripheral base address.
 * @param bEnable Enable the feature or not.
 */
static inline void COP_Enable(COP_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL |= (uint16_t)COP_CTRL_CEN_MASK;
    }
    else
    {
        base->CTRL &= ~(uint16_t)COP_CTRL_CEN_MASK;
    }
}

/*!
 * @brief Enables or disables the COP Loss of Reference counter.
 *
 * This function writes a value into the COP_CTRL register to enable or disable the COP Loss of Reference counter.
 *
 * @param base COP peripheral base address.
 * @param bEnable Enable the feature or not.
 */
static inline void COP_EnableLossOfReferenceCounter(COP_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL |= (uint16_t)COP_CTRL_CLOREN_MASK;
    }
    else
    {
        base->CTRL &= ~(uint16_t)COP_CTRL_CLOREN_MASK;
    }
}

/*!
 * @brief Sets the COP timeout value.
 *
 * This function sets the COP timeout value, if psConfig->bEnableWriteProtect is set
 * to true for calling WDOG_Init, the set does not take effect.
 * It should be ensured that the time-out value for the COP is always greater than
 * interrupt time + 40 bus clock cycles.
 * This function writes a value into COP_TOUT register, when COP count down to zero
 * from the timeout count value, COP_RST_B signal will be asserted.
 * There are some considerations for setting the timeout count afer COP is enabled:
 *   - The recommended procedure for changing TIMEOUT is to disable the COP by invoking
 * COP_Enable(), then call the function COP_SetTimeoutCount, and then re-enable the by
 * invoking COP_Enable() again.
 *   - Alternatively, call the function COP_SetTimeoutCount, then feed the COP by invoking
 * COP_Refresh() to reload the timeout.
 *
 * @param base COP peripheral base address
 * @param u16TimeoutCount COP timeout value, count of COP clock tick. Use macro definition
 * MSEC_TO_COUNT to convert value in ms to count of ticks, the COP clock rate is source clock
 * divide prescaler.
 */
static inline void COP_SetTimeoutCount(COP_Type *base, uint16_t u16TimeoutCount)
{
    base->TOUT = u16TimeoutCount;
}

/*!
 * @brief Sets the COP interrupt value.
 *
 * This function sets the COP interrupt value, if psConfig->bEnableWriteProtect is set
 * to true for calling WDOG_Init, the set does not take effect.
 * This function writes a value into COP_INTVAL register, if COP interrupt is enabled
 * and COP count down to the interrupt value configured, an interrupt will be triggered.
 * Ensure the COP counter is disabled while the function is called.
 *
 * @param base COP peripheral base address
 * @param u16InterruptCount COP interrupt value, count of COP clock tick. Use macro definition
 * MSEC_TO_COUNT to convert value in ms to count of ticks, the COP clock rate is source clock
 * divide prescaler.
 */
static inline void COP_SetInterruptCount(COP_Type *base, uint16_t u16InterruptCount)
{
    base->INTVAL = u16InterruptCount;
}

#if (defined(FSL_FEATURE_COP_HAS_WINDOW_REGISTER) && FSL_FEATURE_COP_HAS_WINDOW_REGISTER)
/*!
 * @brief Sets the COP window value.
 *
 * This function sets the COP window value, if psConfig->bEnableWriteProtect is set
 * to true for calling WDOG_Init, the set does not take effect.
 * This function writes a value into COP_WINDOW register.
 * Ensure the COP counter is disabled while the function is called.
 *
 * @param base COP peripheral base address
 * @param u16WindowCount COP window value, count of COP clock tick. Use macro definition
 * MSEC_TO_COUNT to convert value in ms to count of ticks, the COP clock rate is source clock
 * divide prescaler.
 */
static inline void COP_SetWindowCount(COP_Type *base, uint16_t u16WindowCount)
{
    base->WINDOW = u16WindowCount;
}
#endif

/*!
 * @brief Refreshes the COP timer
 *
 * This function feeds/services the COP.
 *
 * @param base  COP peripheral base address.
 */
void COP_Refresh(COP_Type *base);

/*! @} */

/*!
 * @name Interrupt Control Interfaces
 * @{
 */

/*!
 * @brief Enables the COP interrupt, if psConfig->bEnableWriteProtect is set
 * to true for calling WDOG_Init, the operation does not take effect.
 *
 * This function writes a value into the COP_CTRL register to enable the COP interrupt.
 *
 * @param base COP peripheral base address
 */
static inline void COP_EnableInterrupt(COP_Type *base)
{
    base->CTRL |= (uint16_t)COP_CTRL_INTEN_MASK;
}

/*!
 * @brief Disables the COP interrupt, if psConfig->bEnableWriteProtect is set
 * to true for calling WDOG_Init, the operation does not take effect.
 *
 * This function writes a value into the COP_CTRL register to disable the COP interrupt.
 *
 * @param base COP peripheral base address
 */
static inline void COP_DisableInterrupt(COP_Type *base)
{
    base->CTRL &= ~(uint16_t)COP_CTRL_INTEN_MASK;
}

/*! @}*/

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_COP_H_ */
