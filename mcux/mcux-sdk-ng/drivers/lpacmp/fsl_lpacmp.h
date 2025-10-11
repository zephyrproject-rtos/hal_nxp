/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_LPACMP_H
#define FSL_LPACMP_H

#include "fsl_common.h"

/*!
 * @addtogroup lpacmp
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief LPACMP driver version */
#define FSL_LPACMP_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! @brief Comparator negative input source */
typedef enum _lpacmp_negative_input {
    kLPACMP_Negative_Input_Avdd_Divide_15 = 0U,          /*!< Comparator negative input source 1 x AVDD / 15 */
    kLPACMP_Negative_Input_2Avdd_Divide_15 = 1U,         /*!< Comparator negative input source 2 x AVDD / 15 */
    kLPACMP_Negative_Input_3Avdd_Divide_15 = 2U,         /*!< Comparator negative input source 3 x AVDD / 15 */
    kLPACMP_Negative_Input_4Avdd_Divide_15 = 3U,         /*!< Comparator negative input source 4 x AVDD / 15 */
    kLPACMP_Negative_Input_5Avdd_Divide_15 = 4U,         /*!< Comparator negative input source 5 x AVDD / 15 */
    kLPACMP_Negative_Input_6Avdd_Divide_15 = 5U,         /*!< Comparator negative input source 6 x AVDD / 15 */
    kLPACMP_Negative_Input_7Avdd_Divide_15 = 6U,         /*!< Comparator negative input source 7 x AVDD / 15 */
    kLPACMP_Negative_Input_8Avdd_Divide_15 = 7U,         /*!< Comparator negative input source 8 x AVDD / 15 */
    kLPACMP_Negative_Input_9Avdd_Divide_15 = 8U,         /*!< Comparator negative input source 9 x AVDD / 15 */
    kLPACMP_Negative_Input_10Avdd_Divide_15 = 9U,        /*!< Comparator negative input source 10 x AVDD / 15 */
    kLPACMP_Negative_Input_11Avdd_Divide_15 = 10U,       /*!< Comparator negative input source 11 x AVDD / 15 */
    kLPACMP_Negative_Input_12Avdd_Divide_15 = 11U,       /*!< Comparator negative input source 12 x AVDD / 15 */
    kLPACMP_Negative_Input_13Avdd_Divide_15 = 12U,       /*!< Comparator negative input source 13 x AVDD / 15 */
    kLPACMP_Negative_Input_14Avdd_Divide_15 = 13U,       /*!< Comparator negative input source 14 x AVDD / 15 */
    kLPACMP_Negative_Input_In4 = 14U,                    /*!< Comparator negative input source 4 */
    kLPACMP_Negative_Input_In5 = 15U,                    /*!< Comparator negative input source 5 */
} lpacmp_negative_input_t;

/*! @brief Comparator positive input source */
typedef enum _lpacmp_positive_input {
    kLPACMP_Positive_Input_In4 = 0U,    /*!< Comparator positive input source 4 */
    kLPACMP_Positive_Input_In5 = 1U,    /*!< Comparator positive input source 5 */
    kLPACMP_Positive_Input_In0 = 2U,    /*!< Comparator positive input source 0 */
    kLPACMP_Positive_Input_In1 = 3U,    /*!< Comparator positive input source 1 */
    kLPACMP_Positive_Input_In2 = 4U,    /*!< Comparator positive input source 2 */
    kLPACMP_Positive_Input_In3 = 5U,    /*!< Comparator positive input source 3 */
} lpacmp_positive_input_t;

/*! @brief Comparator operation modes */
typedef enum _lpacmp_mode {
    kLPACMP_Continuous_Mode = 0U,    /*!< Always-on comparison */
    kLPACMP_Interval_Mode   = 1U,    /*!< Periodic sampling with internal timer */
    kLPACMP_Trigger_Mode    = 2U,    /*!< External trigger activation */
} lpacmp_mode_t;

/*! @brief Channel configuration structure */
typedef struct _lpacmp_channel_config {
    bool enableWakeupToSmm;     /*!< Decides whether to enable wakeup to SMM */
    bool enableTriggerOutput;   /*!< Decides whether to enable trigger output */
    bool enableInterrupt;       /*!< Decides whether to enable match interrupt */
    bool comparePolarityHigher; /*!< Decides comparison polarity */
    uint8_t channelIndex;       /*!< Indicates the channel being configured */
    uint8_t triggerOutputWidth; /*!< Sets trigger output width */
    uint16_t delay;             /*!< Sets the delay value for which a compare event is sampled */
    lpacmp_positive_input_t positiveInput;      /*!< Positive input selection (see RM SELn.INP_SEL) */
    lpacmp_negative_input_t negativeInput;      /*!< Negative input selection (see RM SELn.INN_SEL) */
} lpacmp_channel_config_t;

/*! @brief Comparator configuration structure */
typedef struct _lpacmp_config {
    uint8_t channelCount;                   /*!< Indicates the channel counts */
    uint16_t intervalTime;                  /*!< Indicates the interval time */
    lpacmp_mode_t mode;                     /*!< Operating mode */
    lpacmp_channel_config_t *channelConfig; /*!< Channel configuration */
} lpacmp_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name LPACMP initialization, de-initialization, and configuration
 * @{
 */
/*!
 * @brief Initialize the LPACMP module
 *
 * @param base LPACMP peripheral base address
 * @param config Pointer to the LPACMP configuration structure, please refer to @ref lpacmp_config_t for details.
 */
void LPACMP_Init(LPACMP_Type *base, const lpacmp_config_t *config);

/*!
 * @brief Gets an available pre-defined settings for LPACMP configuration.
 *
 * @param config Pointer to the LPACMP configuration structure, please refer to @ref lpacmp_config_t for details.
 */
void LPACMP_GetDefaultConfig(lpacmp_config_t *config);

/*!
 * @brief De-initializes the LPACMP module
 *
 * @param base LPACMP peripheral base address
 */
void LPACMP_Deinit(LPACMP_Type *base);

/*!
 * @brief Enable/Disable comparator module
 *
 * @param base LPACMP peripheral base address
 * @param enable Indicates whether to enable the comparator module
 *   @b true Enable the comparator module
 *   @b false Disable the comparator module
 */
static inline void LPACMP_EnableComparator(LPACMP_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= LPACMP_CTRL_BLOCK_EN_MASK;
    }
    else
    {
        base->CTRL &= ~LPACMP_CTRL_BLOCK_EN_MASK;
    }
}

/*!
 * @brief Set comparator mode
 *
 * @param base LPACMP peripheral base address
 * @param mode comparator mode
 */
static inline void LPACMP_SetComparatorMode(LPACMP_Type *base, lpacmp_mode_t mode)
{
    base->CTRL = ((base->CTRL & ~(LPACMP_CTRL_MODE_MASK)) | LPACMP_CTRL_MODE(mode));
}

/*!
 * @brief Compare event trigger interval time
 *
 * @param base LPACMP peripheral base address
 * @param time Compare event trigger interval time
 */
static inline void LPACMP_SetIntervalTime(LPACMP_Type *base, uint16_t time)
{
    base->INTERVAL = ((base->INTERVAL & ~(LPACMP_INTERVAL_INVL_MASK)) | LPACMP_INTERVAL_INVL(time));
}
/*! @} */

/*!
 * @name LPACMP channel configuration
 * @{
 */
/*!
 * @brief Channel positive and negative input selection
 *
 * @param base LPACMP peripheral base address
 * @param channel Trigger channel index (0-3)
 * @param positive Positive input channel selection
 * @param negative Negative input channel selection
 */
static inline void LPACMP_ChannelInputSelection(LPACMP_Type *base,
                                                uint8_t channel,
                                                lpacmp_positive_input_t positive,
                                                lpacmp_negative_input_t negative)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    base->EXT_TRIG[channel].SEL = ((base->EXT_TRIG[channel].SEL & ~(LPACMP_SEL_INN_SEL_MASK | LPACMP_SEL_INP_SEL_MASK)) |
                          (LPACMP_SEL_INP_SEL(positive) | LPACMP_SEL_INN_SEL(negative)));
}

/*!
 * @brief Comparison polarity configuration
 *
 * @param base LPACMP peripheral base address
 * @param channel Trigger channel index (0-3)
 * @param polarity Comparison polarity
 * - @b true When the value we are checking is higher than the reference value.
 * input parameter 'result'.
 * - @b false When the value we are checking is lower than the reference value.
 */
static inline void LPACMP_SetComparePolarity(LPACMP_Type *base,
                                             uint8_t channel,
                                             bool polarity)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    base->EXT_TRIG[channel].SEL = ((base->EXT_TRIG[channel].SEL & ~(LPACMP_SEL_HIGHER_MASK)) |
                                    LPACMP_SEL_HIGHER(polarity ? 1U : 0U));
}

/*!
 * @brief Compare event sample delay value
 *
 * @param base LPACMP peripheral base address
 * @param channel Trigger channel index (0-3)
 * @param delay Compare event sample delay value
 */
static inline void LPACMP_SetDelayValue(LPACMP_Type *base, uint8_t channel, uint16_t delay)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    base->EXT_TRIG[channel].DELAY = ((base->EXT_TRIG[channel].DELAY & ~(LPACMP_DELAY_DEL_MASK)) | LPACMP_DELAY_DEL(delay));
}

/*!
 * @brief Set the trigger output width in clock units
 *
 * @param base LPACMP peripheral base address
 * @param channel Trigger channel index (0-3)
 * @param width trigger output width
 */
static inline void LPACMP_SetTriggerOutputWidth(LPACMP_Type *base, uint8_t channel, uint8_t width)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    base->EXT_TRIG[channel].STATUS |= ((base->EXT_TRIG[channel].STATUS & ~(LPACMP_STATUS_TRGOPWDH_MASK)) | LPACMP_STATUS_TRGOPWDH(width));
}

/*!
 * @brief Enable/Disable wakeup to SMM
 *
 * @param base LPACMP peripheral base address
 * @param channel Trigger channel index (0-3)
 * @param enable Indicates whether to enable the comparator module
 * - @b true Enable the comparator module
 * - @b false Disable the comparator module
 */
static inline void LPACMP_EnableWakeupToSmm(LPACMP_Type *base, uint8_t channel, bool enable)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    if (enable)
    {
        base->EXT_TRIG[channel].STATUS |= LPACMP_STATUS_WAKEUPEN_MASK;
    }
    else
    {
        base->EXT_TRIG[channel].STATUS &= ~LPACMP_STATUS_WAKEUPEN_MASK;
    }
}

/*!
 * @brief Enable/Disable trigger output
 *
 * @param base LPACMP peripheral base address
 * @param channel Channel index (0-3)
 * @param enable Indicates whether to enable the trigger output
 * - @b true Enable the trigger output
 * - @b false Disable the trigger output
 */
static inline void LPACMP_EnableTriggerOutput(LPACMP_Type *base, uint8_t channel, bool enable)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    if (enable)
    {
        base->EXT_TRIG[channel].STATUS |= LPACMP_STATUS_TRGOP_EN_MASK;
    }
    else
    {
        base->EXT_TRIG[channel].STATUS &= ~LPACMP_STATUS_TRGOP_EN_MASK;
    }
}

/*!
 * @brief Enable/Disable channel
 *
 * @param base LPACMP peripheral base address
 * @param channel Channel index (0-3)
 * @param enable Indicates whether to enable the trigger output
 *   @b true Enable the trigger output
 *   @b false Disable the trigger output
 */
static inline void LPACMP_EnableChannel(LPACMP_Type *base, uint8_t channel, bool enable)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    if (enable)
    {
        base->EXT_TRIG[channel].STATUS |= LPACMP_STATUS_CHNL_EN_MASK;
    }
    else
    {
        base->EXT_TRIG[channel].STATUS &= ~LPACMP_STATUS_CHNL_EN_MASK;
    }
}
/*! @} */

/*!
 * @name LPACMP interrupts control
 * @{
 */
/*!
 * @brief Enable/Disable match interrupt for specific channel
 *
 * @param base LPACMP peripheral base address 
 * @param channel Trigger channel index (0-3)
 * @param enable Indicates whether to enable or disable the match interrupt
 *   @b true Enable the match interrupt
 *   @b false Disable the match interrupt
 */
static inline void LPACMP_EnableInterrupt(LPACMP_Type *base, uint8_t channel, bool enable)
{
    assert(channel < LPACMP_EXT_TRIG_COUNT);

    if (enable)
    {
        base->EXT_TRIG[channel].STATUS |= LPACMP_STATUS_MATCH_IE_MASK;
    }
    else
    {
        base->EXT_TRIG[channel].STATUS &= ~LPACMP_STATUS_MATCH_IE_MASK;
    }
}

/*!
 * @brief Clear comparison interrupt status flags
 *
 * @param base LPACMP peripheral base address
 * @param channel Trigger channel index (0-3)
 * @remark Uses Write-1-to-Clear (W1C) mechanism
 */
static inline void LPACMP_ClearInterruptStatusFlags(LPACMP_Type *base, uint8_t channel)
{
    base->COMP_IF = 1U;
}

/*!
 * @brief Get the comparison interrupt status flag
 *
 * @param base LPACMP peripheral base address
 * @return Comparison interrupt status flags
 */
static inline uint32_t LPACMP_GetInterruptStatusFlags(LPACMP_Type *base)
{
    return base->COMP_IF;
}
/*! @} */

#if defined(__cplusplus)
}
#endif
/*! @} */

#endif /* FSL_LPACMP_H */
