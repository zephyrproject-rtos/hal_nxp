/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_TRGSYNC_H_
#define FSL_TRGSYNC_H_

#include "fsl_common.h"

/*!
 * @addtogroup trgsync
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief TRGSYNC driver version 2.0.0. */
#define FSL_TRGSYNC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @brief TRGSYNC channel polarity selection
 */
typedef enum _trgsync_polarity
{
    kTRGSYNC_PolarityActiveHigh = 0U, /*!< Active high polarity */
    kTRGSYNC_PolarityActiveLow  = 1U  /*!< Active low polarity */
} trgsync_polarity_t;

/*!
 * @brief TRGSYNC stretch width configuration
 */
typedef enum _trgsync_stretch_width
{
    kTRGSYNC_StretchDisable = 0U,  /*!< Disable stretch */
    kTRGSYNC_Stretch2Cycles = 1U,  /*!< Stretch 2 cycles */
    kTRGSYNC_Stretch4Cycles = 2U,  /*!< Stretch 4 cycles */
    kTRGSYNC_Stretch8Cycles = 3U   /*!< Stretch 8 cycles */
} trgsync_stretch_width_t;

/*!
 * @brief TRGSYNC functional clock source
 */
typedef enum _trgsync_func_clock_source
{
    kTRGSYNC_FuncClockBus    = 0U, /*!< Bus clock */
    kTRGSYNC_FuncClock32KHz  = 1U, /*!< 32KHz clock */
    kTRGSYNC_FuncClockExt    = 2U, /*!< External clock */
    kTRGSYNC_FuncClockReserved = 3U /*!< Reserved */
} trgsync_func_clock_source_t;

/*!
 * @brief TRGSYNC channel configuration structure
 */
typedef struct _trgsync_channel_config
{
    bool enableChannel;                           /*!< Enable channel */
    bool enableFunctionalClock;                   /*!< Enable functional clock */
    trgsync_polarity_t polarity;                  /*!< Polarity selection */
    trgsync_stretch_width_t stretchWidth;         /*!< Stretch width */
    trgsync_func_clock_source_t funcClockSource;  /*!< Functional clock source */
} trgsync_channel_config_t;

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
 * @brief Initializes the TRGSYNC module.
 *
 * This function initializes the TRGSYNC module with the user configuration.
 *
 * @param base TRGSYNC peripheral base address.
 */
void TRGSYNC_Init(TRGSYNC_Type *base);

/*!
 * @brief Deinitializes the TRGSYNC module.
 *
 * This function disables all TRGSYNC channels and gates the module clock.
 *
 * @param base TRGSYNC peripheral base address.
 */
void TRGSYNC_Deinit(TRGSYNC_Type *base);

/*!
 * @brief Gets the default configuration.
 *
 * This function fills the configuration structure with default settings.
 * The default values are:
 * @code
 *   config->channelConfig.enableChannel = false;
 *   config->channelConfig.enableFunctionalClock = false;
 *   config->channelConfig.polarity = kTRGSYNC_PolarityActiveHigh;
 *   config->channelConfig.stretchWidth = kTRGSYNC_StretchDisable;
 *   config->channelConfig.funcClockSource = kTRGSYNC_FuncClockBus;
 * @endcode
 *
 * @param config Pointer to the configuration structure.
 */
void TRGSYNC_GetDefaultConfig(trgsync_channel_config_t *config);

/*@}*/

/*!
 * @name Channel control
 * @{
 */

/*!
 * @brief Enables or disables a TRGSYNC channel.
 *
 * @param base TRGSYNC peripheral base address.
 * @param channel Channel number (0-7).
 * @param enable true to enable, false to disable.
 */
static inline void TRGSYNC_EnableChannel(TRGSYNC_Type *base, uint8_t channel, bool enable)
{
    assert(channel < FSL_FEATURE_TRGSYNC_CHANNEL_COUNTn(base));

    if (enable)
    {
        base->CHANNEL[channel] |= TRGSYNC_CHANNEL_CH_ENA_MASK;
    }
    else
    {
        base->CHANNEL[channel] &= ~TRGSYNC_CHANNEL_CH_ENA_MASK;
    }
}

/*!
 * @brief Sets the polarity for a TRGSYNC channel.
 *
 * @param base TRGSYNC peripheral base address.
 * @param channel Channel number (0-7).
 * @param polarity Polarity selection.
 */
static inline void TRGSYNC_SetChannelPolarity(TRGSYNC_Type *base, uint8_t channel, trgsync_polarity_t polarity)
{
    assert(channel < FSL_FEATURE_TRGSYNC_CHANNEL_COUNTn(base));

    base->CHANNEL[channel] = (base->CHANNEL[channel] & ~TRGSYNC_CHANNEL_POL_SEL_MASK) |
                              TRGSYNC_CHANNEL_POL_SEL(polarity);
}

/*!
 * @brief Sets the stretch width for a TRGSYNC channel.
 *
 * @param base TRGSYNC peripheral base address.
 * @param channel Channel number (0-7).
 * @param width Stretch width configuration.
 */
static inline void TRGSYNC_SetChannelStretchWidth(TRGSYNC_Type *base, uint8_t channel, trgsync_stretch_width_t width)
{
    assert(channel < FSL_FEATURE_TRGSYNC_CHANNEL_COUNTn(base));

    base->CHANNEL[channel] = (base->CHANNEL[channel] & ~TRGSYNC_CHANNEL_STRETCH_WIDTH_MASK) |
                              TRGSYNC_CHANNEL_STRETCH_WIDTH(width);
}

/*!
 * @brief Enables or disables functional clock for a TRGSYNC channel.
 *
 * @param base TRGSYNC peripheral base address.
 * @param channel Channel number (0-7).
 * @param enable true to enable, false to disable.
 */
static inline void TRGSYNC_EnableChannelFunctionalClock(TRGSYNC_Type *base, uint8_t channel, bool enable)
{
    assert(channel < FSL_FEATURE_TRGSYNC_CHANNEL_COUNTn(base));

    if (enable)
    {
        base->CHANNEL[channel] |= TRGSYNC_CHANNEL_FUNC_CK_ENA_MASK;
    }
    else
    {
        base->CHANNEL[channel] &= ~TRGSYNC_CHANNEL_FUNC_CK_ENA_MASK;
    }
}

/*!
 * @brief Sets the functional clock source for a TRGSYNC channel.
 *
 * @param base TRGSYNC peripheral base address.
 * @param channel Channel number (0-7).
 * @param source Functional clock source.
 */
static inline void TRGSYNC_SetChannelFunctionalClockSource(TRGSYNC_Type *base, 
                                                           uint8_t channel, 
                                                           trgsync_func_clock_source_t source)
{
    assert(channel < FSL_FEATURE_TRGSYNC_CHANNEL_COUNTn(base));

    base->CHANNEL[channel] = (base->CHANNEL[channel] & ~TRGSYNC_CHANNEL_FUNC_CK_MUX_MASK) |
                              TRGSYNC_CHANNEL_FUNC_CK_MUX(source);
}

/*!
 * @brief Configures a single TRGSYNC channel.
 *
 * @param base TRGSYNC peripheral base address.
 * @param channel Channel number (0-7).
 * @param config Pointer to the channel configuration structure.
 */
void TRGSYNC_ConfigureChannel(TRGSYNC_Type *base, uint8_t channel, const trgsync_channel_config_t *config);

/*@}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_TRGSYNC_H_ */