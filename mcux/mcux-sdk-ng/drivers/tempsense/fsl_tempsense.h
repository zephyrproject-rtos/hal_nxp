/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_TEMPSENSE_H_
#define FSL_TEMPSENSE_H_

#include "fsl_common.h"

/*!
 * @addtogroup tempsense
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version
 * @{
 */
/*! @brief Tempsense driver version 2.0.0. */
#define FSL_TEMPSENSE_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*!
 * @}
 */

/*!
 * @brief This structure is used to configure the tempsense.
 */
typedef struct _tempsense_config
{
    bool exposeGround; /*!< Decides whether to expose ground on the ADC output. */
} tempsense_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Tempsense configuration.
 *
 * @{
 */
/*!
 * @brief This function is used to get predefined configurations for the tempsense initialization.
 *
 * @param config Pointer to the tempsense configuration structure, please refer to @ref tempsense_config_t for details.
 */
void TEMPSENSE_GetDefaultConfig(tempsense_config_t *config);

/*!
 * @brief This function is used to initialize the tempsense.
 *
 * @param base Tempsense peripheral base address.
 * @param config Pointer to the tempsense configuration structure, please refer to @ref tempsense_config_t for details.
 */
void TEMPSENSE_Init(TEMPSENSE_Type *base, const tempsense_config_t *config);

/*!
 * @brief This function is used to de-initialize the tempsense.
 *
 * @param base Tempsense peripheral base address.
 */
void TEMPSENSE_Deinit(TEMPSENSE_Type *base);

/*!
 * @brief Get current temperature
 *
 * @param base Tempsense base pointer
 * @param adcResult The ADC conversion result.
 * @param adcRef The ADC VREF which used to calculate the real temperature.
 * @param adcRes The ADC resolution.
 *
 * @return current temperature with degrees Celsius.
 */
float TEMPSENSE_GetCurrentTemperature(TEMPSENSE_Type *base,
                                        uint16_t adcResult,
                                        float adcRef,
                                        uint8_t adcRes);

/*!
 * @brief Enable tempsense.
 *
 * @param base Tempsense base pointer.
 * @param enable Indicates whether to enable the tempsense.
 * - \b true Enable the tempsense.
 * - \b false Disable the tempsense.
 */
static inline void TEMPSENSE_EnableTempsense(TEMPSENSE_Type *base, bool enable)
{
    if (enable)
    {
        base->ETSCTL |= TEMPSENSE_ETSCTL_ETS_EN_MASK;
    }
    else
    {
        base->ETSCTL &= ~TEMPSENSE_ETSCTL_ETS_EN_MASK;
    }
}

/*!
 * @brief Expose ground.
 *
 * @param base TEMPMON base pointer.
 * @param enable Indicates whether to expose the ground.
 * - \b true Expose the ground.
 * - \b false No exposure of the ground.
 */
static inline void TEMPSENSE_ExposeGround(TEMPSENSE_Type *base, bool enable)
{
    if (enable)
    {
        base->ETSCTL |= TEMPSENSE_ETSCTL_GNDSEL_MASK;
    }
    else
    {
        base->ETSCTL &= ~TEMPSENSE_ETSCTL_GNDSEL_MASK;
    }
}

/*!
 * @}
 */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_TEMPSENSE_H_ */
