/*
 * Copyright 2019-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_VREF_H_
#define FSL_VREF_H_

#include "fsl_common.h"

/*!
 * @addtogroup vref
 * @{
 */

/******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_VREF_DRIVER_VERSION (MAKE_VERSION(2, 4, 0)) /*!< Version 2.4.0. */
/*! @} */

/*! @brief VREF buffer modes. */
typedef enum _vref_buffer_mode
{
    kVREF_ModeBandgapOnly     = 0U, /*!< Bandgap enabled/standby. */
    kVREF_ModeLowPowerBuffer  = 1U, /*!< Low-power buffer mode enabled */
    kVREF_ModeHighPowerBuffer = 2U, /*!< High-power buffer mode enabled */
} vref_buffer_mode_t;

/*! @brief The description structure for the VREF module. */
typedef struct _vref_config
{
    vref_buffer_mode_t bufferMode;       /*!< Buffer mode selection */
    bool enableInternalVoltageRegulator; /*!< Provide additional supply noise rejection. */
    bool enableChopOscillator;           /*!< Enable Chop oscillator.*/
    bool enableHCBandgap;                /*!< Enable High-Accurate bandgap.*/
    bool enableCurvatureCompensation;    /*!< Enable second order curvature compensation. */
#if !(defined(FSL_FEATURE_VREF_HAS_LOWPOWER_BUFFER) && (FSL_FEATURE_VREF_HAS_LOWPOWER_BUFFER == 0U))
    bool enableLowPowerBuff;             /*!< Provides bias current for other peripherals.*/
#endif /* FSL_FEATURE_VREF_HAS_LOWPOWER_BUFFER */

} vref_config_t;

/******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Enables the clock gate and configures the VREF module according to the configuration structure.
 *
 * This function must be called before calling all other VREF driver functions, read/write registers, and
 * configurations with user-defined settings. The example below shows how to set up vref_config_t parameters
 * and how to call the VREF_Init function by passing in these parameters.
 * @code
 *    vref_config_t vrefConfig;
 *    VREF_GetDefaultConfig(VREF, &vrefConfig);
 *    vrefConfig.bufferMode = kVREF_ModeHighPowerBuffer;
 *    VREF_Init(VREF, &vrefConfig);
 * @endcode
 *
 * @param base VREF peripheral address.
 * @param config Pointer to the configuration structure.
 */
void VREF_Init(VREF_Type *base, const vref_config_t *config);

/*!
 * @brief Stops and disables the clock for the VREF module.
 *
 * This function should be called to shut down the module.
 * This is an example.
 * @code
 *    vref_config_t vrefUserConfig;
 *    VREF_GetDefaultConfig(VREF, &vrefUserConfig);
 *    VREF_Init(VREF, &vrefUserConfig);
 *    ...
 *    VREF_Deinit(VREF);
 * @endcode
 *
 * @param base VREF peripheral address.
 */
void VREF_Deinit(VREF_Type *base);

/*!
 * @brief Initializes the VREF configuration structure.
 *
 * This function initializes the VREF configuration structure to default values.
 * This is an example.
 * @code
 *    config->bufferMode = kVREF_ModeHighPowerBuffer;
 *    config->enableInternalVoltageRegulator = true;
 *    config->enableChopOscillator           = true;
 *    config->enableHCBandgap                = true;
 *    config->enableCurvatureCompensation    = true;
 *    config->enableLowPowerBuff             = true;
 * @endcode
 *
 * @param config Pointer to the initialization structure.
 */
void VREF_GetDefaultConfig(vref_config_t *config);

/*! @} */

/*!
 * @name Trim functions
 * @{
 */

/*!
 * @brief Sets a TRIM value for the accurate 1.0V bandgap output.
 *
 * This function sets a TRIM value for the reference voltage. It will trim the accurate 1.0V bandgap by 0.5mV each step.
 *
 * @param base VREF peripheral address.
 * @param trimValue Value of the trim register to set the output reference voltage (maximum 0x3F (6-bit)).
 */
void VREF_SetVrefTrimVal(VREF_Type *base, uint8_t trimValue);

#if !(defined(FSL_FEATURE_VREF_HAS_TRIM2V1) && (FSL_FEATURE_VREF_HAS_TRIM2V1 == 0U))
/*!
 * @brief Sets a TRIM value for the accurate buffered VREF output.
 *
 * This function sets a TRIM value for the reference voltage. If buffer mode be set to other values (Buf21
 * enabled), it will trim the VREF_OUT by 0.1V each step from 1.0V to 2.1V.
 *
 * @note When Buf21 is enabled, the value of UTRIM[TRIM2V1] should be ranged from 0b0000 to 0b1011 in order to trim the
 * output voltage from 1.0V to 2.1V, other values will make the VREF_OUT to default value, 1.0V.
 *
 * @param base VREF peripheral address.
 * @param trim21Value Value of the trim register to set the output reference voltage (maximum 0xF (4-bit)).
 */
void VREF_SetTrim21Val(VREF_Type *base, uint8_t trim21Value);
#endif /* FSL_FEATURE_VREF_HAS_TRIM2V1 */

/*!
 * @brief Reads the trim value.
 *
 * This function gets the TRIM value from the UTRIM register. It reads UTRIM[VREFTRIM] (13:8)
 *
 * @param base VREF peripheral address.
 * @return 6-bit value of trim setting.
 */
uint8_t VREF_GetVrefTrimVal(VREF_Type *base);

#if !(defined(FSL_FEATURE_VREF_HAS_TRIM2V1) && (FSL_FEATURE_VREF_HAS_TRIM2V1 == 0U))
/*!
 * @brief Reads the VREF 2.1V trim value.
 *
 * This function gets the TRIM value from the UTRIM register. It reads UTRIM[TRIM2V1] (3:0),
 *
 * @param base VREF peripheral address.
 * @return 4-bit value of trim setting.
 */
uint8_t VREF_GetTrim21Val(VREF_Type *base);
#endif /* FSL_FEATURE_VREF_HAS_TRIM2V1 */

#if (defined(FSL_FEATURE_VREF_HAS_TEST_UNLOCK_REG) && (FSL_FEATURE_VREF_HAS_TEST_UNLOCK_REG == 1U))
/*!
 * @brief Set VREF test unlock value.
 *
 * @param base VREF peripheral address.
 * @param value VREF test unlock value.
 */
static inline void VREF_SetTestUlockValue(VREF_Type *base, uint16_t value)
{
    base->TEST_UNLOCK |= VREF_TEST_UNLOCK_TEST_UNLOCK(value);
}

/*!
 * @brief Get VREF test unlock value.
 *
 * @param base VREF peripheral address.
 * @return VREF test unlock value.
 */
static inline uint16_t VREF_GetTestUlockValue(VREF_Type *base)
{
    return (uint16_t)(base->TEST_UNLOCK & VREF_TEST_UNLOCK_TEST_UNLOCK_VALUE_MASK >> VREF_TEST_UNLOCK_TEST_UNLOCK_VALUE_SHIFT);
}

/*!
 * @brief Decides whether to enable/disable VREF test unlock.
 *
 * @param base VREF peripheral address.
 * @param enable VREF test unlock enable/disable.
 * - \b true  VREF test unlock enable.
 * - \b false VREF test unlock disable.
 */
static inline void VREF_SetTestUlockEnable(VREF_Type *base, bool enable)
{
    if (enable)
    {
        base->TEST_UNLOCK |= VREF_TEST_UNLOCK_TEST_UNLOCK_MASK;
    }
    else
    {
        base->TEST_UNLOCK &= ~VREF_TEST_UNLOCK_TEST_UNLOCK_MASK;
    }
}
#endif /* FSL_FEATURE_VREF_HAS_TEST_UNLOCK_REG */

#if (defined(FSL_FEATURE_VREF_HAS_TRIM0_REG) && (FSL_FEATURE_VREF_HAS_TRIM0_REG == 1U))
/*!
 * @brief Decides whether to reverse VREF amplifier polarity.
 *
 * @param base VREF peripheral address.
 * @param reverse VREF amplifier polarity reverse enable/disable.
 * - \b true  VREF amplifier polarity reverse enable.
 * - \b false VREF amplifier polarity reverse disable.
 */
static inline void VREF_SetAmpPolValue(VREF_Type *base, uint16_t reverse)
{
    if (reverse)
    {
        base->TRIM0 |= VREF_TRIM0_FLIP_MASK;
    }
    else
    {
        base->TRIM0 &= ~VREF_TRIM0_FLIP_MASK;
    }
}

/*!
 * @brief Set VREF P7 trim value.
 *
 * @param base VREF peripheral address.
 * @param value VREF P7 trim value.
 */
static inline void VREF_SetP7TrimValue(VREF_Type *base, uint8_t value)
{
    base->TRIM0 = (base->TRIM0 & ~VREF_TRIM0_P7_TRIM_MASK) | VREF_TRIM0_P7_TRIM(value);
}

/*!
 * @brief Get VREF P7 trim value.
 *
 * @param base VREF peripheral address.
 * @return VREF P7 trim value.
 */
static inline uint8_t VREF_GetP7TrimValue(VREF_Type *base)
{
    return (uint8_t)((base->TRIM0 & VREF_TRIM0_P7_TRIM_MASK) >> VREF_TRIM0_P7_TRIM_SHIFT);
}

/*!
 * @brief Set VREF chop osc trim value.
 *
 * @param base VREF peripheral address.
 * @param value VREF chop osc trim value.
 */
static inline void VREF_SetChopOscTrimValue(VREF_Type *base, uint8_t value)
{
    base->TRIM0 = (base->TRIM0 & ~VREF_TRIM0_CHOPOSCTRIM_MASK) | VREF_TRIM0_CHOPOSCTRIM(value);
}

/*!
 * @brief Get VREF chop osc trim value.
 *
 * @param base VREF peripheral address.
 * @return VREF chop osc trim value.
 */
static inline uint8_t VREF_GetChopOscTrimValue(VREF_Type *base)
{
    return (uint8_t)((base->TRIM0 & VREF_TRIM0_CHOPOSCTRIM_MASK) >> VREF_TRIM0_CHOPOSCTRIM_SHIFT);
}

/*!
 * @brief Set VREF bandgap MSB value.
 *
 * @param base VREF peripheral address.
 * @param value VREF bandgap MSB value.
 */
static inline void VREF_SetBandgapMsb(VREF_Type *base, uint8_t value)
{
    base->TRIM0 = (base->TRIM0 & ~VREF_TRIM0_BPMSB_MASK) | VREF_TRIM0_BPMSB(value);
}

/*!
 * @brief Get VREF bandgap MSB value.
 *
 * @param base VREF peripheral address.
 * @return VREF bandgap MSB value.
 */
static inline uint8_t VREF_GetBandgapMsb(VREF_Type *base)
{
    return (uint8_t)((base->TRIM0 & VREF_TRIM0_BPMSB_MASK) >> VREF_TRIM0_BPMSB_SHIFT);
}

/*!
 * @brief Set VREF bandgap LSB value.
 *
 * @param base VREF peripheral address.
 * @param value VREF bandgap LSB value.
 */
static inline void VREF_SetBandgapLsb(VREF_Type *base, uint8_t value)
{
    base->TRIM0 = (base->TRIM0 & ~VREF_TRIM0_BPLSB_MASK) | VREF_TRIM0_BPLSB(value);
}

/*!
 * @brief Get VREF bandgap LSB value.
 *
 * @param base VREF peripheral address.
 * @return VREF bandgap LSB value.
 */
static inline uint8_t VREF_GetBandgapLsb(VREF_Type *base)
{
    return (uint8_t)((base->TRIM0 & VREF_TRIM0_BPLSB_MASK) >> VREF_TRIM0_BPLSB_SHIFT);
}

/*!
 * @brief Set VREF temperature compensation MSB value.
 *
 * @param base VREF peripheral address.
 * @param value VREF temperature compensation MSB value.
 */
static inline void VREF_SetTempCompMsb(VREF_Type *base, uint8_t value)
{
    base->TRIM0 = (base->TRIM0 & ~VREF_TRIM0_COMPMSB_MASK) | VREF_TRIM0_COMPMSB(value);
}

/*!
 * @brief Get VREF temperature compensation MSB value.
 *
 * @param base VREF peripheral address.
 * @return VREF temperature compensation MSB value.
 */
static inline uint8_t VREF_GetTempCompMsb(VREF_Type *base)
{
    return (uint8_t)((base->TRIM0 & VREF_TRIM0_COMPMSB_MASK) >> VREF_TRIM0_COMPMSB_SHIFT);
}

/*!
 * @brief Set VREF temperature compensation LSB value.
 *
 * @param base VREF peripheral address.
 * @param value VREF temperature compensation LSB value.
 */
static inline void VREF_SetTempCompLsb(VREF_Type *base, uint8_t value)
{
    base->TRIM0 = (base->TRIM0 & ~VREF_TRIM0_COMPLSB_MASK) | VREF_TRIM0_COMPLSB(value);
}

/*!
 * @brief Get VREF temperature compensation LSB value.
 *
 * @param base VREF peripheral address.
 * @return VREF temperature compensation LSB value.
 */
static inline uint8_t VREF_GetTempCompLsb(VREF_Type *base)
{
    return (uint8_t)((base->TRIM0 & VREF_TRIM0_COMPLSB_MASK) >> VREF_TRIM0_COMPLSB_SHIFT);
}
#endif /* FSL_FEATURE_VREF_HAS_TRIM0_REG */

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_VREF_H_ */
