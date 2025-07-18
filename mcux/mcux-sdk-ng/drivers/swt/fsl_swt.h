/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SWT_H_
#define FSL_SWT_H_

#include "fsl_common.h"

/*!
 * @addtogroup swt
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief SWT Driver Version 2.1.0 */
#define FSL_SWT_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*! @name Soft unlock sequence */
/*! @{ */
#define SWT_FIRST_WORD_OF_SOFT_UNLOCK  (0xC520U) /*!< First word of soft unlock sequence */
#define SWT_SECOND_WORD_OF_SOFT_UNLOCK (0xD928U) /*!< Second word of soft unlock sequence */
/*! @} */

/*! @name Fixed service sequence */
/*! @{ */
#define SWT_FIRST_WORD_OF_FIXED_SERVICE  (0xA602U) /*!< First word of fixed service sequence */
#define SWT_SECOND_WORD_OF_FIXED_SERVICE (0xB480U) /*!< Second word of fixed service sequence */
/*! @} */

/*!
 * @brief SWT service mode
 */
typedef enum _swt_service_mode_t
{
    kSWT_FixedServiceSequence = 0x00U, /*!< Write the fixed sequence */
    kSWT_KeyedServiceSequence = 0x01U  /*!< write two pseudorandom key values */
} swt_service_mode_t;

/*!
* @brief SWT configuration structure
*
* This structure holds the configuration settings for the SWT peripheral. To initialize this
* structure to reasonable defaults, call the SWT_GetDefaultConfig() function and pass a
* pointer to your config structure instance.
*/
typedef struct _swt_config
{
    bool enableSwt;                 /*!< Enables SWT */
    bool enableRunInDebug;          /*!< Enable timers continues in debug mode */
    bool enableRunInStop;           /*!< Enable timers continues in stop/standby mode */
    bool interruptThenReset;        /*!< true: Generate an interrupt and load the countdown timer on an inital timeout, 
                                         then generate a reset request on a subsequent timeout.
                                         false: Generate an immediate reset request on any timeout. */
    bool enableWindowMode;          /*!< Enable timers run in window mode */
    bool resetOnInvalidAccess;      /*!< true: Generate a bus error and reset request; false: Generate a bus error */
    swt_service_mode_t serviceMode; /*!< Service mode, @ref swt_service_mode_t */
    uint32_t timeoutValue;          /*!< Watchdog timeout period in clock cycles */
    uint32_t windowValue;           /*!< Window start value */
    uint16_t serviceKey;            /*!< Service key */
} swt_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name SWT Initialization and De-initialization
 * @{
 */

/*!
 * @brief Initializes the SWT module with configuration.
 *
 * This function initializes the SWT. When called, the SWT runs according to the configuration.
 * This is an example.
 * @code
 *   swt_config_t config;
 *   SWT_GetDefaultConfig(&config);
 *   config.timeoutValue = 32000U;
 *   SWT_Init(swt_base, &config);
 * @endcode
 *
 * @param base   SWT peripheral base address
 * @param config Pointer to the SWT configuration structure.
 */
void SWT_Init(SWT_Type *base, const swt_config_t *config);

/*!
 * @brief De-initializes the SWT module.
 *
 * This function de-initializes the SWT.
 *
 * @param base SWT peripheral base address
 */
void SWT_Deinit(SWT_Type *base);

/*!
 * @brief Gets the default configuration for SWT.
 *
 * This function initializes the SWT configuration structure to a default value. The default
 * values are as follows.
 * @code
 *   config->enableSwt = true;
 *   config->enableRunInDebug = false;
 *   config->enableRunInStop = true;
 *   config->interruptThenReset = false;
 *   config->enableWindowMode = false;
 *   config->resetOnInvalidAccess = true;
 *   config->serviceMode = kSWT_FixedServiceSequence;
 *   config->timeoutValue = 0xFFFFU;
 *   config->windowValue = 0U;
 *   config->serviceKey = 0U;
 * @endcode
 * @param config Pointer to the configuration structure.
 */
void SWT_GetDefaultConfig(swt_config_t *config);

/*!
 * @brief Enable SWT module
 *
 * @param base SWT peripheral base address
 */
static inline void SWT_Enable(SWT_Type *base)
{
    base->CR |= SWT_CR_WEN(1U);
}

/*!
 * @brief Disable SWT module
 *
 * @param base SWT peripheral base address
 */
static inline void SWT_Disable(SWT_Type *base)
{
    base->CR &= ~SWT_CR_WEN(1U);
}

/*! @} */

/*!
 * @name Lock and Unlock SWT
 * @{
 */

/*!
 * @brief Enable the hard lock
 *
 * This function will hard lock the SWT registers.
 * Hard lock is disabled only by a reset.
 * 
 * @param base SWT peripheral base address
 */
static inline void SWT_HardLock(SWT_Type *base)
{
    base->CR |= SWT_CR_HLK(1U);
}

/*!
 * @brief Enable the soft lock
 *
 * This function will soft lock the SWT registers.
 * Soft lock is disabled by a reset or by writing the unlock sequence.
 * 
 * @param base SWT peripheral base address
 */
static inline void SWT_SoftLock(SWT_Type *base)
{
    base->CR |= SWT_CR_SLK(1U);
}

/*!
 * @brief Unlock the soft lock
 *
 * This function will unlock the SWT registers locked by @ref SWT_SoftLock.
 * 
 * @param base SWT peripheral base address
 */
void SWT_SoftUnlock(SWT_Type *base);

/*! @} */

/*!
 * @name SWT Refresh
 * @{
 */

/*!
 * @brief SWT Refresh with Fixed Service Sequence
 *
 * This function will execute a fixed service sequence to refresh the SWT.
 * SWT shall work in fixed service sequence mode @ref swt_service_mode_t.
 * 
 * @param base SWT peripheral base address
 */
void SWT_RefreshWithFixedServiceSequence(SWT_Type *base);

/*!
 * @brief Set the service key
 *
 * This function will set the initial service key for the keyed service sequence.
 * 
 * @param base SWT peripheral base address
 * @param serviceKey The service key
 */
static inline void SWT_SetServiceKey(SWT_Type *base, uint16_t serviceKey)
{
    base->SK = SWT_SK_SK(serviceKey);
}

/*!
 * @brief SWT Refresh with Keyed Service Sequence
 *
 * This function will excute a keyed service sequence to refresh the SWT.
 * SWT shall work in keyed service sequence mode @ref swt_service_mode_t.
 * 
 * @param base SWT peripheral base address
 */
void SWT_RefreshWithKeyedServiceSequence(SWT_Type *base);

/*!
 * @brief SWT Refresh with automatic service sequence
 *
 * This function will automatically select the service sequence to refresh the SWT.
 *
 * @param base SWT peripheral base address
 */
void SWT_Refresh(SWT_Type *base);

/*! @} */

/*!
 * @name SWT Operations
 * @{
 */

/*!
 * @brief Set the timeout value
 *
 * This function will set the SWT timeout period in clock cycles.
 * 
 * @param base SWT peripheral base address
 * @param timeoutValue The timeout value
 */
void SWT_SetTimeoutValue(SWT_Type *base, uint32_t timeoutValue);

/*!
 * @brief Set the window start value
 * 
 * This function will set the window start value for SWT window mode. Software can write the service sequence only when
 * the internal timer is less than this value.
 * 
 * @param base SWT peripheral base address
 * @param windowValue The window start value
 */
static inline void SWT_SetWindowValue(SWT_Type *base, uint32_t windowValue)
{
    base->WN = SWT_WN_WST(windowValue);
}

/*!
 * @brief Get the counter value
 *
 * This function will get the internal counter value when SWT is disabled.
 * It is usually used to determine whether the internal countdown timer is working properly.
 * 
 * This is an example:
 * @code
 *   SWT_Enable(SWT_BASE);
 *   Delay(the_delay_time_shall_less_than_timeout_value);
 *   SWT_Disable(SWT_BASE);
 *   uint32_t counter_value = SWT_GetCounterValue(SWT_BASE);
 * @endcode
 * 
 * @param base SWT peripheral base address
 * @return The counter value
 */
static inline uint32_t SWT_GetCounterValue(SWT_Type *base)
{
    return base->CO;
}

/*!
 * @brief Get the timeout interrupt flag
 *
 * This function will get the timeout interrupt flag.
 *
 * @param base SWT peripheral base address
 * @return The timeout interrupt flag. true: Interrupt request due to an initial timeout
 *                                     false: No interrupt request
 */
static inline bool SWT_GetTimeoutInterruptFlag(SWT_Type *base)
{
    return SWT_IR_TIF_MASK == (base->IR & SWT_IR_TIF_MASK);
}

/*!
 * @brief Clear the timeout interrupt flag
 *
 * This function will clear the timeout interrupt flag and then SWT will send interrupt request due to an initial
 * timeout.
 * 
 * @param base SWT peripheral base address
 */
static inline void SWT_ClearTimeoutInterruptFlag(SWT_Type *base)
{
    base->IR = SWT_IR_TIF(1U);
}

/*!
 * @brief Get the timeout reset flag
 *
 * This funcion can get the SWT reset request flag.
 *
 * @param base SWT peripheral base address
 * @return The reset request flag. true: Any reset request initiated
 *                                 false: No reset request
 */
static inline bool SWT_GetTimeoutResetFlag(SWT_Type *base)
{
    return SWT_RRR_RRF_MASK == (base->RRR & SWT_RRR_RRF_MASK);
}

/*!
 * @brief Clear the timeout reset flag
 *
 * This funcion can only reset the SWT module instead of the whole system. See the chip-specific information for the
 * specific event associated with this flag.
 *
 * @param base SWT peripheral base address
 */
static inline void SWT_ClearTimeoutResetFlag(SWT_Type *base)
{
    base->RRR = SWT_RRR_RRF(1U);
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_SWT_H_ */
