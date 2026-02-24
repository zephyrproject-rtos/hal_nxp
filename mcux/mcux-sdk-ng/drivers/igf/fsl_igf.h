/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_IGF_H_
#define FSL_IGF_H_

#include "fsl_common.h"


/*!
 * @addtogroup igf
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_IGF_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. */
/*! @} */

/*!
 * @brief IGF filter type enumeration.
 *
 * The selection item represents the Boolean evaluations.
 */
typedef enum _igf_filter_type
{
    kIGF_FilterBypass = 0U,               /*!< Bypass filter */
    kIGF_FilterWindowing = 1U,            /*!< Windowing filter */
    kIGF_FilterIntegrating = 2U,          /*!< Integrating filter */
    kIGF_FilterIntegratingHold = 3U,      /*!< Integrating-hold filter */
    kIGF_FilterWindowingPostSample = 4U,  /*!< Windowing with post sample filter */
} igf_filter_type_t;

/*!
 * @brief IGF status flags enumeration.
 *
 * These flags represent the status bits in the IGF MSR register.
 */
typedef enum _igf_status_flags
{
    kIGF_StatusWaitingEdge        = IGF_MSR_WEDGE_MASK, /*!< Filter is active waiting for an edge */
    kIGF_StatusProcessingEdge     = IGF_MSR_FEDGE_MASK, /*!< Filter is active processing an edge */
    kIGF_StatusRiseNoiseDetected  = IGF_MSR_RNDET_MASK, /*!< Noise detected after rising edge */
    kIGF_StatusFallNoiseDetected  = IGF_MSR_FNDET_MASK, /*!< Noise detected after falling edge */
    kIGF_StatusInputLevel         = IGF_MSR_FLI_MASK,   /*!< Filter input level */
    kIGF_StatusOutputLevel        = IGF_MSR_FLO_MASK    /*!< Filter output level */
} igf_status_flags_t;

/*!
 * @brief IGF configuration structure
 */
typedef struct _igf_config
{
    bool enableFilter;              /*!< Enable or disable the filter */
    bool invertOutput;              /*!< Invert the output signal */
    bool immediatePropagation;      /*!< Immediate edge propagation */
    bool useExternalPrescaler;      /*!< Use external prescaler */
    uint32_t prescaler;             /*!< Prescaler value */
    igf_filter_type_t risingEdgeFilter;   /*!< Filter type for rising edge */
    igf_filter_type_t fallingEdgeFilter;  /*!< Filter type for falling edge */
    uint32_t risingThreshold;       /*!< Threshold for rising edge */
    uint32_t fallingThreshold;      /*!< Threshold for falling edge */
} igf_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*!
 * @brief Initializes the IGF module with user configuration.
 *
 * @param base IGF peripheral base address.
 * @param config Pointer to user-defined configuration structure.
 */
void IGF_Init(IGF_Type *base);

/*!
 * @brief Deinitializes the IGF module.
 *
 * @param base IGF peripheral base address.
 */
void IGF_Deinit(IGF_Type *base);

/*!
 * @brief Gets the default configuration for IGF.
 *
 * @param config Pointer to configuration structure to populate.
 */
void IGF_GetDefaultConfig(igf_config_t *config);

/*!
 * @brief Enables or disables the IGF filter.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param enable True to enable, false to disable.
 */
void IGF_Enable(IGF_Type *base, uint32_t channel, bool enable);

/*!
 * @brief Gets the status flags from IGF module.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @return Status flags.
 */
uint32_t IGF_GetStatusFlags(IGF_Type *base, uint32_t channel);

/*!
 * @brief Clears the specified status flags.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param mask Mask of status flags to clear.
 */
void IGF_ClearStatusFlags(IGF_Type *base, uint32_t channel, uint32_t mask);

/*!
 * @brief Set the IGF module with the specified configuration.
 *
 * This function config IGF module.
 *
 * @param base IGF peripheral address.
 * @param channel IGF corresponding pin channel value.
 * @param config Pointer to configuration structure.
 */
void IGF_SetIgfConfig(IGF_Type *base, uint32_t channel, const igf_config_t *config);

/*!
 * @brief Sets the output polarity of the IGF filter.
 *
 * Note This function should be called when the filter is disabled.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param invertPolarity True to invert output, false for normal polarity.
 */
static inline void IGF_SetOutputPolarity(IGF_Type *base, uint32_t channel, bool invertPolarity)
{
    base->MCR[channel].MCR = (base->MCR[channel].MCR & ~IGF_MCR_POL_MASK) | IGF_MCR_POL((invertPolarity ? 1U : 0U));
}

/*!
 * @brief Sets the immediate propagation mode.
 *
 * Note This function should be called when the filter is disabled.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param enable True to enable immediate propagation, false to use prescaler.
 */
static inline void IGF_SetImmediatePropagation(IGF_Type *base, uint32_t channel, bool enable)
{
    base->MCR[channel].MCR = (base->MCR[channel].MCR & ~IGF_MCR_IMM_MASK) | IGF_MCR_IMM((enable ? 1U : 0U));
}

/*!
 * @brief Selects the prescaler source.
 *
 * Note This function should be called when the filter is disabled.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param external True to use external prescaler, false for internal.
 */
static inline void IGF_SelectPrescalerSource(IGF_Type *base, uint32_t channel, bool external)
{
    base->MCR[channel].MCR = (base->MCR[channel].MCR & ~IGF_MCR_PSSEL_MASK) | IGF_MCR_PSSEL((external ? 1U : 0U));
}

/*!
 * @brief Sets the rising edge filter type.
 *
 * Note This function should be called when the filter is disabled.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param type Filter type for rising edge.
 */
static inline void IGF_SetRisingEdgeFilter(IGF_Type *base, uint32_t channel, igf_filter_type_t type)
{
    base->MCR[channel].MCR = (base->MCR[channel].MCR & ~IGF_MCR_RFM_MASK) | IGF_MCR_RFM(type);
}

/*!
 * @brief Sets the falling edge filter type.
 *
 * Note This function should be called when the filter is disabled.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param type Filter type for falling edge.
 */
static inline void IGF_SetFallingEdgeFilter(IGF_Type *base, uint32_t channel, igf_filter_type_t type)
{
    base->MCR[channel].MCR = (base->MCR[channel].MCR & ~IGF_MCR_FFM_MASK) | IGF_MCR_FFM(type);
}

/*!
 * @brief Sets the prescaler value.
 *
 * This function sets the prescaler value for the IGF filter.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param value Prescaler value.
 */
static inline void IGF_SetPrescaler(IGF_Type *base, uint32_t channel, uint32_t value)
{
    base->MCR[channel].PRESR = IGF_PRESR_FPRE(value);
}

/*!
 * @brief Sets the rising edge threshold.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param threshold Rising edge threshold value.
 */
static inline void IGF_SetRisingThreshold(IGF_Type *base, uint32_t channel, uint32_t threshold)
{
    base->MCR[channel].RTHR = IGF_RTHR_RTH(threshold);
}

/*!
 * @brief Sets the falling edge threshold.
 *
 * @param base IGF peripheral base address.
 * @param channel IGF corresponding pin channel value.
 * @param threshold Falling edge threshold value.
 */
static inline void IGF_SetFallingThreshold(IGF_Type *base, uint32_t channel, uint32_t threshold)
{
    base->MCR[channel].FTHR = IGF_FTHR_FTH(threshold);
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @} */

#endif /* FSL_AOI_H_*/
