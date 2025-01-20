/*
 * Copyright 2018, NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_TSENS_H__
#define FSL_TSENS_H__

#include "fsl_common.h"
#include "fsl_power.h"

/*!
 * @addtogroup tsens
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief TSENS driver version. */
#define FSL_TSENS_DRIVER_VERSION (MAKE_VERSION(2, 0, 1)) /*!< Version 2.0.1. */`

/*!
 * @brief TSENS interrupt
 */
enum _tsens_interrupt_enable
{
    kTSENS_ConversionReadyInterruptEnable =
        TSENS_IMSC_RDYI_MASK, /*!< The temperature sensor conversion ready interrupt. */
    kTSENS_LowThresholdInterruptEnable  = TSENS_IMSC_TLOE_MASK, /*!< The temperature sensor low threshold interrupt.  */
    kTSENS_HighThresholdInterruptEnable = TSENS_IMSC_THIE_MASK, /*!< The temperature sensor high threshold interrupt. */
    kTSENS_AllInterruptEnable = TSENS_IMSC_RDYI_MASK | TSENS_IMSC_TLOE_MASK | TSENS_IMSC_THIE_MASK, /* All interrupts */
};

/*!
 * @brief TSENS status flags
 */
enum _tsens_flags
{
    kTSENS_LowCoarseRangeFlag           = TSENS_SR_TRANLOC_MASK, /*!< Coarse range mask, out of range (too low).  */
    kTSENS_HighCoarseRangeFlag          = TSENS_SR_TRANHIC_MASK, /*!< Coarse range mask, out of range (too high). */
    kTSENS_LowFineRangeFlag             = TSENS_SR_TRANLOF_MASK, /*!< Fine range mask, out of range (too low).    */
    kTSENS_HighFineRangeFlag            = TSENS_SR_TRANHIF_MASK, /*!< Fine range mask, out of range (too low).    */
    kTSENS_ConversionSuccessFlag        = TSENS_SR_TSUCC_MASK,   /*!< Successful conversion mask.                 */
    kTSENS_ConversionReadyInterruptFlag = TSENS_RIS_RDYI_MASK << 16U, /*!< A temperature conversion has finished. */
    kTSENS_LowThresholdInterruptFlag =
        TSENS_RIS_TLOI_MASK
        << 16U, /*!< A temperature conversion has finished and the value is below the value stored in TLO. */
    kTSENS_HighThresholdInterruptFlag =
        TSENS_RIS_THII_MASK
        << 16U, /*!< A temperature conversion has finished and the value exceeds the THI threshold value. */
};

/*!
 * @brief TSENS resolution modes
 */
typedef enum _tsens_resolution_mode
{
    kTSENS_Resolution7bit = 2U, /*!< 7-bit resoultion mode  */
    kTSENS_Resolution8bit,      /*!< 8-bit resoultion mode  */
    kTSENS_Resolution9bit,      /*!< 9-bit resoultion mode  */
    kTSENS_Resolution10bit,     /*!< 10-bit resoultion mode */
    kTSENS_Resolution11bit,     /*!< 11-bit resoultion mode */
    kTSENS_Resolution12bit,     /*!< 12-bit resoultion mode */
} tsens_resolution_mode_t;

/*!
 * @brief TSENS output modes
 */
typedef enum _tsens_output_mode
{
    kTSENS_OutputRawData = 0U,   /*!< Raw data mode, unsigned fixed point (5.11)      */
    kTSENS_OutputCalibratedData, /*!< Calibrated data mode, signed fixed point (10.6) */
} tsens_output_mode_t;

/*!
 * @brief Configuration for Temperature sensor
 *
 * This structure holds the configuration settings for the temperature sensor. To initialize this
 * structure to reasonable defaults, call the TSENS_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 */
typedef struct _tsens_config
{
    tsens_output_mode_t outputMode;         /*!< Set temperature sensor output mode.            */
    tsens_resolution_mode_t resolutionMode; /*!< Set temperature sensor resolution mode.        */
    bool enableVolatgeCalibration;          /*!< Enable temperature sensor voltage calibration. */
} tsens_config_t;

/*!
 * @brief Configuration for tsens clibration parameters
 *
 * This structure holds the configuration settings for the calibration parameters. To initialize this
 * structure to reasonable defaults, call the TSENS_GetCalibrationDefaultConfig() function and pass a
 * pointer to your config structure instance.
 *
 * The calibration values A, B, and alpha for the default resolution settings are determined
 * during the calibration phase of the manufacturing process and stored in EEPROM.
 */
typedef struct _tsens_calibration_config
{
    uint16_t parameterA;     /*!< Calibration parameter A     */
    uint16_t parameterB;     /*!< Calibration parameter B     */
    uint16_t parameterAlpha; /*!< Calibration parameter ALPHA */
} tsens_calibration_config_t;

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
 * @brief Enable the access to TSENS registers and initialize TSENS module.
 *
 * @param base TSENS peripheral base address.
 * @param config Pointer to configuration structure. Refer to "tsens_config_t" structure.
 */
void TSENS_Init(TSENS_Type *base, const tsens_config_t *config);

/*!
 * @brief De-initialize TSENS module.
 *
 * @param base TSENS peripheral base address.
 */
void TSENS_Deinit(TSENS_Type *base);

/*!
 * @brief Gets the default configuration for TSENS.
 *
 * This function initializes the user configuration structure to default value. The default value are:
 * @param config Pointer to TSENS configuration structure. Refer to "tsens_config_t" structure.
 */
void TSENS_GetDefaultConfig(tsens_config_t *config);
/*! @} */

/*!
 * @name Get temperature
 * @{
 */

/*!
 * @brief Start the coversion.
 *
 * @param base TSENS peripheral base address.
 */
static inline void TSENS_StartMeasurement(TSENS_Type *base)
{
    base->CR = TSENS_CR_START_MASK;
}

/*!
 * @brief Get the temperature data in last measurement.
 *
 * @param base TSENS peripheral base address.
 * @retval The temperature value.
 */
static inline uint32_t TSENS_GetTemperature(TSENS_Type *base)
{
    return base->DR;
}
/*! @} */

/*!
 * @name Calibration configuration
 * @{
 */

/*!
 * @brief Get the default calibration config.
 *
 * @param base TSENS peripheral base address.
 * @param caliConfig Pointer to TSENS calibration configuration structure. Refer to "tsens_calibration_config_t"
 * structure.
 */
void TSENS_GetDefaultCalibrationConfig(TSENS_Type *base, tsens_calibration_config_t *caliConfig);

/*!
 * @brief Config calibration parameters,
 *
 * @param base TSENS peripheral base address.
 * @param caliConfig Pointer to TSENS calibration configuration structure. Refer to "tsens_calibration_config_t"
 * structure.
 */
void TSENS_SetCalibrationConfig(TSENS_Type *base, const tsens_calibration_config_t *caliConfig);
/*! @} */

/*!
 * @name Interrupt interface
 * @{
 */

/*!
 * @brief Set the low temperature threshold.
 *
 * @param base TSENS peripheral base address.
 * @param temperature Low temperature threshold.
 */
static inline void TSENS_SetLowTemperatureThreshold(TSENS_Type *base, uint16_t temperature)
{
    base->TLO = temperature;
}

/*!
 * @brief Set the high temperature threshold.
 *
 * @param base TSENS peripheral base address.
 * @param temperature high temperature threshold.
 */
static inline void TSENS_SetHighTemperatureThreshold(TSENS_Type *base, uint16_t temperature)
{
    base->THI = temperature;
}

/*!
 * @brief Enable the TSENS interrupts.
 *
 * @param base TSENS peripheral base address.
 * @param mask The interrupt mask. Refer to "_tsens_interrupt" enumeration.
 */
static inline void TSENS_EnableInterrupt(TSENS_Type *base, uint32_t mask)
{
    mask &= kTSENS_AllInterruptEnable;
    base->IMSC |= mask;
}

/*!
 * @brief Disable the TSENS interrupts.
 *
 * @param base TSENS peripheral base address.
 * @param mask The interrupt mask. Refer to "_tsens_interrupt" enumeration.
 */
static inline void TSENS_DisableInterrupt(TSENS_Type *base, uint32_t mask)
{
    mask &= kTSENS_AllInterruptEnable;
    base->IMSC &= ~mask;
}
/*! @} */

/*!
 * @name Status interface
 * @{
 */

/*!
 * @brief Get TSENS status flags.
 *
 * This function gets all TSENS status flags. The flags are returned as the logical
 * OR value of the enumerators @ref _tsens_flags. To check for a specific status,
 * compare the return value with enumerators in the @ref _tsens_flags.
 * For example, to check whether the measurement value is ready in data register:
 * @code
 *     if (kTSENS_ConversionReadyInterruptFlag & TSENS_GetStatusFlags(TSENS))
 *     {
 *         ...
 *     }
 * @endcode
 *
 * @param base TSENS peripheral base address.
 * @return TSENS status flags which are given in the enumerators in the @ref _tsens_flags.
 */
static inline uint32_t TSENS_GetStatusFlags(TSENS_Type *base)
{
    return (base->SR & 0x1FU) | ((base->RIS & 0x7U) << 16U);
}

/*!
 * @brief Get TSENS interrupt status flags.
 *
 * This function gets all TSENS interrupt status flags. The flags are returned as the logical
 * OR value of the enumerators @ref _tsens_interrupt_enable. To check for a specific status,
 * compare the return value with enumerators in the @ref _tsens_interrupt_enable.
 * For example, to check whether the conversion ready interrupt is enabled:
 * @code
 *     if (kTSENS_ConversionReadyInterruptEnable & TSENS_GetInterruptStatusFlags(TSENS))
 *     {
 *         ...
 *     }
 * @endcode
 *
 * @param base TSENS peripheral base address.
 * @return TSENS interrupt status flags which are given in the enumerators in the @ref _tsens_interrupt_enable.
 */
static inline uint32_t TSENS_GetInterruptStatusFlags(TSENS_Type *base)
{
    return base->IMSC;
}

/*!
 * @brief Clear interrupt status flags.
 *
 * @param base LPADC peripheral base address.
 * @param mask Mask value for interrupt flags to be cleared. Refer to "tsens_status_flags".
 */
static inline void TSENS_ClearInterruptStatusFlags(TSENS_Type *base, uint32_t mask)
{
    base->ICR = (mask >> 16U);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_TSENS_H__ */
