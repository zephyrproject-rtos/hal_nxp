/*
 * Copyright 2018-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FSL_CMP_H_
#define __FSL_CMP_H_

#include "fsl_common.h"

/*!
 * @addtogroup cmp_1
 * @{
 */

/******************************************************************************
 * Definitions.
 *****************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief Driver version 2.1.0. */
#define FSL_CMP_DRIVER_VERSION (MAKE_VERSION(2U, 1U, 0U))
/*@}*/

/*! @brief CMP input mux for positive and negative sides. */
enum _cmp_input_mux
{
    kCMP_InputVREF = 0U, /*!< Cmp input from VREF. */
    kCMP_Input1    = 1U, /*!< Cmp input source 1. */
    kCMP_Input2    = 2U, /*!< Cmp input source 2. */
    kCMP_Input3    = 3U, /*!< Cmp input source 3. */
    kCMP_Input4    = 4U, /*!< Cmp input source 4. */
    kCMP_Input5    = 5U, /*!< Cmp input source 5. */
};

/*! @brief CMP interrupt type. */
enum _cmp_interrupt_type
{
    kCMP_EdgeDisable       = 0U, /*!< Disable edge interupt. */
    kCMP_EdgeRising        = 2U, /*!< Interrupt on falling edge. */
    kCMP_EdgeFalling       = 4U, /*!< Interrupt on rising edge. */
    kCMP_EdgeRisingFalling = 6U, /*!< Interrupt on both rising and falling edges. */

    kCMP_LevelDisable = 1U, /*!< Disable level interupt. */
    kCMP_LevelHigh    = 3U, /*!< Interrupt on high level. */
    kCMP_LevelLow     = 5U, /*!< Interrupt on low level. */
};

/*! @brief CMP Voltage Reference source. */
typedef enum _cmp_vref_source
{
    KCMP_VREFSourceVDDA         = 1U, /*!< Select VDDA as VREF. */
    KCMP_VREFSourceInternalVREF = 0U, /*!< Select internal VREF as VREF. */
} cmp_vref_source_t;

typedef struct _cmp_vref_config
{
    cmp_vref_source_t vrefSource; /*!< Reference voltage source. */
    uint8_t vrefValue; /*!< Reference voltage step. Available range is 0-31. Per step equals to VREFINPUT/31. */
} cmp_vref_config_t;

/*! @brief CMP configuration structure. */
typedef struct _cmp_config
{
    bool enableHysteresis; /*!< Enable hysteresis. */
    bool enableLowPower;   /*!< Enable low power mode. */
    uint8_t
        filterClockDivider; /* Filter clock divider. The module clock source will be divided by this value plus one. */
} cmp_config_t;

/*************************************************************************************************
 * API
 ************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief CMP initialization.
 *
 * This function enables the CMP module and do necessary settings.
 *
 * @param config Pointer to the configuration structure.
 */
void CMP_Init(const cmp_config_t *config);

/*!
 * @brief CMP deinitialization.
 *
 * This function gates the clock for CMP module.
 */
void CMP_Deinit(void);

/*!
 * @brief Initializes the CMP user configuration structure.
 *
 * This function initializes the user configuration structure to these default values.
 * @code
 *   config->enableHysteresis    = true;
 *   config->enableLowPower      = true;
 *   config->filterClockDivider  = 0;
 * @endcode
 * @param config Pointer to the configuration structure.
 */
void CMP_GetDefaultConfig(cmp_config_t *config);

/* @} */

/*!
 * @name Compare Interface
 * @{
 */

/*
 * @brief Set the input channels for the comparator.
 *
 * @param positiveChannel Positive side input channel number. See "_cmp_input_mux".
 * @param negativeChannel Negative side input channel number. See "_cmp_input_mux".
 */
static inline void CMP_SetInputChannels(uint8_t positiveChannel, uint8_t negativeChannel)
{
    PMC->COMP &= ~(PMC_COMP_PMUX_MASK | PMC_COMP_NMUX_MASK);
    PMC->COMP |= (PMC_COMP_PMUX(positiveChannel) | PMC_COMP_NMUX(negativeChannel));
}

/*!
 * @brief Configures the VREFINPUT.
 *
 * @param config Pointer to the configuration structure.
 */
void CMP_SetVREF(const cmp_vref_config_t *config);

/*!
 * @brief Get CMP compare output.
 *
 * @return The output result. true: voltage on positive side is greater than negative side.
 *                            false: voltage on positive side is lower than negative side.
 */
static inline bool CMP_GetOutput(void)
{
    return SYSCON_COMP_INT_STATUS_VAL_MASK == (SYSCON->COMP_INT_STATUS & SYSCON_COMP_INT_STATUS_VAL_MASK);
}

/* @} */

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief CMP enable interrupt.
 *
 * @param type CMP interrupt type. See "_cmp_interrupt_type".
 */
static inline void CMP_EnableInterrupt(uint32_t type)
{
    SYSCON->COMP_INT_CTRL |= (SYSCON_COMP_INT_CTRL_INT_CTRL(type) | SYSCON_COMP_INT_CTRL_INT_ENABLE_MASK);
}

/*!
 * @brief CMP disable interrupt.
 *
 */
static inline void CMP_DisableInterrupt(void)
{
    SYSCON->COMP_INT_CTRL &= ~SYSCON_COMP_INT_CTRL_INT_ENABLE_MASK;
}

/*!
 * @brief CMP clear interrupt.
 *
 */
static inline void CMP_ClearInterrupt(void)
{
    SYSCON->COMP_INT_CTRL |= SYSCON_COMP_INT_CTRL_INT_CLEAR_MASK;
}

/*!
 * @brief Select which Analog comparator output (filtered or un-filtered) is used for interrupt detection.
 *
 * @param enable false: Select Analog Comparator raw output (unfiltered) as input for interrupt detection.
 *               true: Select Analog Comparator filtered output as input for interrupt detection.
 *
 * @note: When CMP is configured as the wakeup source in power down mode, this function must use the raw output as the
 *        interupt source, that is, call this function and set parameter enable to false.
 */
static inline void CMP_EnableFilteredInterruptSource(bool enable)
{
    if (enable)
    {
        SYSCON->COMP_INT_CTRL &= ~SYSCON_COMP_INT_CTRL_INT_SOURCE_MASK;
    }
    else
    {
        SYSCON->COMP_INT_CTRL |= SYSCON_COMP_INT_CTRL_INT_SOURCE_MASK;
    }
}
/* @} */

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Get CMP interrupt status before interupt enable.
 *
 * @return Interrupt status. true: interrupt pending,
 *                           false: no interrupt pending.
 */
static inline bool CMP_GetPreviousInterruptStatus(void)
{
    return SYSCON_COMP_INT_STATUS_STATUS_MASK == (SYSCON->COMP_INT_STATUS & SYSCON_COMP_INT_STATUS_STATUS_MASK);
}

/*!
 * @brief Get CMP interrupt status after interupt enable.
 *
 * @return Interrupt status. true: interrupt pending,
 *                           false: no interrupt pending.
 */
static inline bool CMP_GetInterruptStatus(void)
{
    return SYSCON_COMP_INT_STATUS_INT_STATUS_MASK == (SYSCON->COMP_INT_STATUS & SYSCON_COMP_INT_STATUS_INT_STATUS_MASK);
}
/* @} */

#if defined(__cplusplus)
}
#endif

/*! @} */
#endif /* __FSL_CMP_H_ */
