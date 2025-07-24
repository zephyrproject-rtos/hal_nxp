/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_STM_H_
#define FSL_STM_H_

#include "fsl_common.h"

/*!
 * @addtogroup stm
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Defines STM driver version. */
#define FSL_STM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief List of STM channels */
typedef enum _stm_channel
{
    kSTM_Channel_0 = 0U, /*!< STM channel 0 */
    kSTM_Channel_1,      /*!< STM  channel 1 */
    kSTM_Channel_2,      /*!< STM  channel 2 */
    kSTM_Channel_3,      /*!< STM  channel 3 */
} stm_channel_t;

/*! @brief List of STM compare match mask to indicate channel interrupt in stm_callback_t function flags parameters*/
typedef enum _stm_channel_match
{
    kSTM_Channel_Match_Msk_0 = 1U,     /*!< STM channel compare register 0 */
    kSTM_Channel_Match_Msk_1 = 2U,     /*!< STM channel compare register 1 */
    kSTM_Channel_Match_Msk_2 = 4U,     /*!< STM channel compare register 2 */
    kSTM_Channel_Match_Msk_3 = 8U,     /*!< STM channel compare register 3 */
} stm_channel_match_t;

/*! @brief Describes STM configuration structure. */
typedef struct _stm_config
{
    bool enableRunInDebug;         /*!< true:  Timer stops in Debug mode
                                    false: Timer runs in Debug mode */
    bool enableIRQ;            /*!< true: Enable STM interrupt
                                    false: Disable STM interrupt */
    uint8_t prescale;          /*!< Selects the module clock divide value for the prescale (0–255). */
} stm_config_t;

/*! @brief Define STM interrupt callback function pointer*/
typedef void (*stm_callback_t)(uint32_t flags);

/*******************************************************************************
 * API
 *******************************************************************************/
extern void STM_DriverIRQHandler(uint32_t index);

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
* @name Initialization and deinitialization
* @{
*/

/*!
 * @brief Initializes STM configure structure.
 *
 * This function initializes the STM configure structure to default value. The default
 * value are:
 * @code
 *   config->enableRunInDebug = true;
 *   config->enableIRQ = true;
 *   config->prescale = 0U;
 * @endcode
 *
 * @param config Pointer to STM config structure.
 * @see stm_config_t
 */
void STM_GetDefaultConfig(stm_config_t *config);

/*!
 * @brief Initializes the STM.
 *
 * This function configures the peripheral for basic operation.
 *
 * @param base   STM peripheral base address
 * @param config The configuration of STM
 */
void STM_Init(STM_Type *base, const stm_config_t *config);

/*!
 * @brief Shuts down the STM.
 *
 * This function shuts down the STM.
 *
 * @param base STM peripheral base address
 */
void STM_Deinit(STM_Type *base);

/*! @}*/

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Clear STM flag.
 *
 * This function clears STM channel interrupt flag which is set due to a match on the channel.
 *
 * @param base STM peripheral base address
 * @param channel The compare channel that corresponds to the flag that needs to be cleared.
 * @see stm_channel_t
 */
static inline void STM_ClearStatusFlags(STM_Type *base, stm_channel_t channel)
{
    base->CHANNEL[channel].CIR = STM_CIR_CIF_MASK;
}

/*!
 * @brief Gets channel interrupt flag of the STM
 *
 * @param base        STM peripheral base address
 * @param channel     The channel number. @see stm_channel_t
 * @return The channel Interrupt flag.
 */
static inline uint32_t STM_GetStatusFlags(STM_Type *base, stm_channel_t channel)
{
    return base->CHANNEL[channel].CIR;
}

/*! @}*/

/*!
* @name STM match value configuration
* @{
*/

/*!
* @brief Set compare value for specific channel of the STM module and enable the channel.
*
* @param base             STM peripheral base address
* @param channel          The compare channel to be configured. @see stm_channel_t
* @param value            Compare value, range from 0 to 0xFFFFFFFF
*/
void STM_SetCompare(STM_Type *base, stm_channel_t channel, uint32_t value);

/*! @}*/

/*!
 * @name Channel enable and Disable
 * @{
 */

/*!
 * @brief Enable STM compare channel
 *
 * @param base        STM peripheral base address
 * @param channel     The channel number. @see stm_channel_t
 */
static inline void STM_EnableCompareChannel(STM_Type *base, stm_channel_t channel)
{
    base->CHANNEL[channel].CCR |= STM_CCR_CEN_MASK;
}

/*!
 * @brief Disable STM compare channel
 *
 * @param base        STM peripheral base address
 * @param channel     The channel number. @see stm_channel_t
 */
static inline void STM_DisableCompareChannel(STM_Type *base, stm_channel_t channel)
{
    base->CHANNEL[channel].CCR &= ~STM_CCR_CEN_MASK;
} 

/*! @}*/

/*!
 * @brief Start the STM module.
 *
 * This function write value into STM_CR register to enable the STM
 *
 * @param base STM peripheral base address
 */
static inline void STM_StartTimer(STM_Type *base)
{
    base->CR |= STM_CR_TEN_MASK;
}

/*!
 * @brief Stop the STM module.
 *
 * This function write value into STM_CR register to disable the STM.
 *
 * @param base STM peripheral base address
 */
static inline void STM_StopTimer(STM_Type *base)
{
    base->CR &= ~STM_CR_TEN_MASK;
}

/*! @}*/

/*!
 * @brief Get the timer count value from CNT register.
 *
 * @param base STM peripheral base address
 */
static inline uint32_t STM_GetTimerCount(STM_Type *base)
{
    return base->CNT;
}

/*!
 * @brief Register callback.
 *
 * @param base      STM peripheral base address
 * @param cb_func   callback function
 */
void STM_RegisterCallBack(STM_Type *base, stm_callback_t cb_func);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_STM_H_ */
