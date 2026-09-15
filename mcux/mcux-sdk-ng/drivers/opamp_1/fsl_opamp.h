/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_OPAMP_H_
#define FSL_OPAMP_H_

#include "fsl_common.h"

/*!
 * @addtogroup opamp_1_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief OPAMP driver version. */
#define FSL_OPAMP_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief OPAMP bias current ratio configuration.
 */
typedef enum _opamp_bias_current
{
    kOPAMP_BiasCurrentRatio1   = 0U, /*!< Bias current ratio = 1. */
    kOPAMP_BiasCurrentRatio1_4 = 1U, /*!< Bias current ratio = 1/4. */
    kOPAMP_BiasCurrentRatio1_2 = 2U, /*!< Bias current ratio = 1/2. */
    kOPAMP_BiasCurrentRatio3_2 = 3U, /*!< Bias current ratio = 3/2. */
} opamp_bias_current_t;

/*!
 * @brief OPAMP gain configuration.
 */
typedef enum _opamp_gain
{
    kOPAMP_Gain3   = 0U, /*!< OPAMP gain = 3. */
    kOPAMP_Gain4   = 1U, /*!< OPAMP gain = 4. */
    kOPAMP_Gain5   = 2U, /*!< OPAMP gain = 5. */
    kOPAMP_Gain6_5 = 3U, /*!< OPAMP gain = 6.5. */
    kOPAMP_Gain9   = 4U, /*!< OPAMP gain = 9. */
    kOPAMP_Gain11  = 5U, /*!< OPAMP gain = 11. */
    kOPAMP_Gain14  = 6U, /*!< OPAMP gain = 14. */
    kOPAMP_Gain19  = 7U, /*!< OPAMP gain = 19. */
} opamp_gain_t;

/*!
 * @brief OPAMP capacitance compensation configuration.
 *
 * @note CC_CONFIG must be set to match the selected GAIN_CONFIG.
 *       Refer to the device reference manual for the required pairing.
 */
typedef enum _opamp_cap_compensation
{
    kOPAMP_CapCompensationGain3   = 7U,  /*!< Capacitance compensation for gain = 3. */
    kOPAMP_CapCompensationGain4   = 8U,  /*!< Capacitance compensation for gain = 4. */
    kOPAMP_CapCompensationGain5   = 9U,  /*!< Capacitance compensation for gain = 5. */
    kOPAMP_CapCompensationGain6_5 = 11U, /*!< Capacitance compensation for gain = 6.5. */
    kOPAMP_CapCompensationGain9   = 12U, /*!< Capacitance compensation for gain = 9. */
    kOPAMP_CapCompensationGain11  = 13U, /*!< Capacitance compensation for gain = 11. */
    kOPAMP_CapCompensationGain14  = 14U, /*!< Capacitance compensation for gain = 14. */
    kOPAMP_CapCompensationGain19  = 15U, /*!< Capacitance compensation for gain = 19. */
} opamp_cap_compensation_t;

/*!
 * @brief OPAMP offset voltage reference selection.
 */
typedef enum _opamp_offset_sel
{
    kOPAMP_OffsetSelVddaDiv2 = 0U, /*!< Vref = VDDA / 2. */
    kOPAMP_OffsetSelVddaDiv4 = 1U, /*!< Vref = VDDA / 4. */
    kOPAMP_OffsetSelVddaDiv8 = 2U, /*!< Vref = VDDA / 8. */
} opamp_offset_sel_t;

/*!
 * @brief OPAMP input offset voltage trim.
 *
 * Values 0–7 all produce 0 V offset; values 8–15 select a non-zero trim.
 * Positive values shift the output up; negative values shift it down.
 */
typedef enum _opamp_vos_trim
{
    kOPAMP_VosTrim0mV      = 0U,  /*!< Input offset voltage = 0 mV (reset default). */
    kOPAMP_VosTrimPos1p5mV = 8U,  /*!< Input offset voltage = +1.5 mV. */
    kOPAMP_VosTrimPos3mV   = 9U,  /*!< Input offset voltage = +3 mV. */
    kOPAMP_VosTrimPos4p5mV = 10U, /*!< Input offset voltage = +4.5 mV. */
    kOPAMP_VosTrimPos6mV   = 11U, /*!< Input offset voltage = +6 mV. */
    kOPAMP_VosTrimNeg1p5mV = 12U, /*!< Input offset voltage = -1.5 mV. */
    kOPAMP_VosTrimNeg3mV   = 13U, /*!< Input offset voltage = -3 mV. */
    kOPAMP_VosTrimNeg4p5mV = 14U, /*!< Input offset voltage = -4.5 mV. */
    kOPAMP_VosTrimNeg6mV   = 15U, /*!< Input offset voltage = -6 mV. */
} opamp_vos_trim_t;

/*!
 * @brief OPAMP configuration structure.
 */
typedef struct _opamp_config
{
    opamp_gain_t gain;                /*!< Gain configuration. */
    opamp_offset_sel_t offsetSel;     /*!< Offset voltage reference. */
    opamp_vos_trim_t vosTrim;         /*!< Input offset voltage trim. */
    opamp_bias_current_t biasCurrent; /*!< Bias current ratio. */
    opamp_cap_compensation_t capCompensation; /*!< Capacitance compensation; must match gain. */
} opamp_config_t;

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
 * @brief Get the instance index for an OPAMP peripheral base address.
 *
 * @param base OPAMP peripheral base address.
 * @return Instance number (0-based).
 */
uint32_t OPAMP_GetInstance(OPAMP_Type *base);

/*!
 * @brief Populate an @ref opamp_config_t with default values.
 *
 * Default values:
 * @code
 *   config->biasCurrent     = kOPAMP_BiasCurrentRatio1;
 *   config->vosTrim         = kOPAMP_VosTrim0mV;
 *   config->gain            = kOPAMP_Gain3;
 *   config->capCompensation = kOPAMP_CapCompensationGain3;
 *   config->offsetSel       = kOPAMP_OffsetSelVddaDiv2;
 * @endcode
 *
 * @param config Pointer to configuration structure; must not be NULL.
 */
void OPAMP_GetDefaultConfig(opamp_config_t *config);

/*!
 * @brief Initialize the OPAMP module.
 *
 * Enables the peripheral clock, releases reset, and writes all CTRL configuration
 * fields (IREF_CONFIG, VOS_TRIM, GAIN_CONFIG, CC_CONFIG, OFFSET_SEL)
 * The OPAMP output is NOT enabled; call @ref OPAMP_Enable after initialization
 * when the application is ready to start the amplifier.
 *
 * @param base   OPAMP peripheral base address.
 * @param config Pointer to configuration structure; must not be NULL.
 * @retval kStatus_Success if initialization is successful.
 * @retval kStatus_InvalidArgument if the base address is invalid.
 */
status_t OPAMP_Init(OPAMP_Type *base, const opamp_config_t *config);

/*!
 * @brief De-initialize the OPAMP module.
 *
 * Clears the ENA bit, disables the peripheral clock, and asserts reset.
 *
 * @param base OPAMP peripheral base address.
 * @retval kStatus_Success if deinitialization is successful.
 * @retval kStatus_InvalidArgument if the base address is invalid.
 */
status_t OPAMP_Deinit(OPAMP_Type *base);

/*! @} */

/*!
 * @name Dynamic control
 * @{
 */

/*!
 * @brief Enable the OPAMP output.
 *
 * Call this after @ref OPAMP_Init when the application is ready to start the amplifier.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_Enable(OPAMP_Type *base)
{
    base->CTRL |= OPAMP_CTRL_ENA_MASK;
}

/*!
 * @brief Disable the OPAMP output.
 *
 * The peripheral clock and configuration registers are preserved; call
 * @ref OPAMP_Enable to restart the amplifier without re-initializing.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_Disable(OPAMP_Type *base)
{
    base->CTRL &= MCUX_MASK_INVERT_32(OPAMP_CTRL_ENA_MASK);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_OPAMP_H_ */
