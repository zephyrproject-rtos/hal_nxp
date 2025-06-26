/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DRYICE_DIGITAL_H_
#define FSL_DRYICE_DIGITAL_H_

#include "fsl_common.h"

/*!
 * @addtogroup dryice_digital
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_DRYICE_DIGITAL_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0 */
/*! @} */

/*! @brief List of dryice tamper pins */
typedef enum _dryice_digital_tamper_pin
{
    kDRYICE_DIGITAL_TamperPin0  = 0U,
    kDRYICE_DIGITAL_TamperPin1  = 1U,
    kDRYICE_DIGITAL_TamperPin2  = 2U,
    kDRYICE_DIGITAL_TamperPin3  = 3U,
    kDRYICE_DIGITAL_TamperPin4  = 4U,
    kDRYICE_DIGITAL_TamperPin5  = 5U,
    kDRYICE_DIGITAL_TamperPin6  = 6U,
    kDRYICE_DIGITAL_TamperPin7  = 7U,
    kDRYICE_DIGITAL_TamperPin8  = 8U,
    kDRYICE_DIGITAL_TamperPin9  = 9U,
    kDRYICE_DIGITAL_TamperPin10 = 10U,
    kDRYICE_DIGITAL_TamperPin11 = 11U
} dryice_digital_tamper_pin_t;

/*! Ignored window width, countered in 32 kHz clock */
typedef enum _dryice_digital_ignored_win_width
{
    kDRYICE_DIGITAL_NoIgnoredWindow       = 0U,
    kDRYICE_DIGITAL_IgnoredWindow1Cycle   = 1U,
    kDRYICE_DIGITAL_IgnoredWindow2Cycle   = 2U,
    kDRYICE_DIGITAL_IgnoredWindow4Cycle   = 3U,
    kDRYICE_DIGITAL_IgnoredWindow8Cycle   = 4U,
    kDRYICE_DIGITAL_IgnoredWindow16Cycle  = 5U,
    kDRYICE_DIGITAL_IgnoredWindow32Cycle  = 6U,
    kDRYICE_DIGITAL_IgnoredWindow64Cycle  = 7U,
    kDRYICE_DIGITAL_IgnoredWindow128Cycle = 8U,
    kDRYICE_DIGITAL_IgnoredWindow256Cycle = 9U,
    kDRYICE_DIGITAL_IgnoredWindow512Cycle = 10U
} dryice_digital_ignored_win_width_t;

/*! Clock selection for ignored window and pin sampling */
typedef enum _dryice_digital_clk_freq
{
    kDRYICE_DIGITAL_32768Hz = 0U,
    kDRYICE_DIGITAL_512Hz   = 1U
} dryice_digital_clk_freq_t;

/*! Tamper pull select */
typedef enum _dryice_digital_pull_select
{
    kDRYICE_DIGITAL_PullDown = 0U,
    kDRYICE_DIGITAL_PullUp   = 1U
} dryice_digital_pull_select_t;

/*! Control signal to select Schmitt trigger or CMOS input */
typedef enum _dryice_digital_hysteresis_control
{
    kDRYICE_DIGITAL_CMOS    = 0U,
    kDRYICE_DIGITAL_Schmitt = 1U
} dryice_digital_hysteresis_control_t;

/*! External tamper routing control */
typedef enum _dryice_digital_tamper_routing_control
{
    kDRYICE_DIGITAL_PassiveInput  = 0U,
    kDRYICE_DIGITAL_ActiveTamper1 = 1U,
    kDRYICE_DIGITAL_ActiveTamper2 = 2U,
    kDRYICE_DIGITAL_ActiveTamper3 = 3U,
    kDRYICE_DIGITAL_ActiveTamper4 = 4U,
    kDRYICE_DIGITAL_ActiveTamper5 = 5U
} dryice_digital_tamper_routing_control_t;

/*! Passive tamper expected data */
typedef enum _dryice_digital_tamper_expected_data
{
    kDRYICE_DIGITAL_ExpectedTamperHigh = 0U,
    kDRYICE_DIGITAL_ExpectedTamperLow  = 1U
} dryice_digital_tamper_expected_data_t;

/*! Tamper pin sampling frequency */
typedef enum _dryice_digital_pin_sampling_freq
{
    kDRYICE_DIGITAL_Every8Cycles   = 0U,
    kDRYICE_DIGITAL_Every32Cycles  = 1U,
    kDRYICE_DIGITAL_Every128Cycles = 2U,
    kDRYICE_DIGITAL_Every512Cycles = 3U
} dryice_digital_pin_sampling_freq_t;

/*! Tamper pin sample width */
typedef enum _dryice_digital_pin_sampling_width
{
    kDRYICE_DIGITAL_SamplingDisabled  = 0U,
    kDRYICE_DIGITAL_1CycleSampleWidth = 1U,
    kDRYICE_DIGITAL_2CycleSampleWidth = 2U,
    kDRYICE_DIGITAL_4CycleSampleWidth = 3U
} dryice_digital_pin_sampling_width_t;

/*! Drive strength controlling */
typedef enum _dryice_digital_drive_strength
{
    kDRYICE_DIGITAL_DriveStrenght1 = 1U,
    kDRYICE_DIGITAL_DriveStrenght2 = 2U,
    kDRYICE_DIGITAL_DriveStrenght3 = 3U,
    kDRYICE_DIGITAL_DriveStrenght4 = 4U,
    kDRYICE_DIGITAL_DriveStrenght5 = 5U,
    kDRYICE_DIGITAL_DriveStrenght6 = 6U,
    kDRYICE_DIGITAL_DriveStrenght7 = 7U
} dryice_digital_drive_strength_t;

/*! Tamper pin pull transition width */
typedef enum _dryice_digital_pull_transition_width
{
    kDRYICE_DIGITAL_1CycleTransitionWidth = 0U,
    kDRYICE_DIGITAL_2CycleTransitionWidth = 1U,
    kDRYICE_DIGITAL_4CycleTransitionWidth = 2U,
    kDRYICE_DIGITAL_8CycleTransitionWidth = 3U
} dryice_digital_pull_transition_width_t;

/*! Temperature detect selection */
typedef enum _dryice_digital_temp_range
{
    kDRYICE_DIGITAL_Range_105C_125C = 0U,
    kDRYICE_DIGITAL_Range_125C_145C = 1U
} dryice_digital_temp_range_t;

/*! List of tamper events */
typedef enum _dryice_digital_tamper_result
{
    kDRYICE_DIGITAL_TemperatureTamperDetected = 1U,
    kDRYICE_DIGITAL_VoltageTamperDetected     = 2U,
    kDRYICE_DIGITAL_ClockTamperDetected       = 4U
} dryice_digital_tamper_result_t;

/*! List of tamper status flags */
typedef enum _dryice_digital_tamper_enable
{
    kDRYICE_DIGITAL_TemperatureTamper = 1U,
    kDRYICE_DIGITAL_VoltageTamper     = 2U,
    kDRYICE_DIGITAL_ClockTamper       = 4U
} dryice_digital_tamper_enable_t;

/*! Config struct for DRYICE DIGITAL module */
typedef struct _dryice_digital_config
{
    uint32_t tempHighOffset;
    uint32_t tempLowOffset;
    uint32_t tempMonTrim;
    uint32_t voltMonTrim;
    uint32_t bgrTrim;
    bool tempDetSel;
} dryice_digital_config_t;

/*! Config struct for DRYICE DIGITAL tamper pin */
typedef struct _dryice_digital_pin_config
{
    uint32_t ignoredWindowWidth;
    bool ignoredWinClkSel;
    uint32_t ignoredWinStartCycle;
    uint32_t extTamperRoutingCtrl;
    bool passiveTamperExpDat;
    bool pullContinuousEnable;
    bool pullSelect;
    bool pullEnable;
    uint32_t pullTransWidth;
    uint32_t driveStrength;
    bool hysteresisCtrl;
    bool outputKeepEnable;
    bool sampleClkSel;
    uint32_t sampleFreqSel;
    uint32_t sampleWidth;
} dryice_digital_pin_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

/*!
 * @brief Enables the DryIce Digital module.
 *
 * This function enables the DryIce peripheral.
 */
void DRYICE_DIGITAL_Init(DRYICE_Type *base, const dryice_digital_config_t *config);

/*!
 * @brief Disables the DryIce Digital module.
 *
 * This function disables the DryIce peripheral.
 */
void DRYICE_DIGITAL_Deinit(DRYICE_Type *base);

/*!
 * @brief Gets default values for the DryIce Digital module.
 *
 * This function fills the given structure with default values for the DryIce module.
 * The default values are:
 * @code
 *     defaultConfig->tempHighOffset = 0U;
 *     defaultConfig->tempLowOffset = 0U;
 *     defaultConfig->tempMonTrim = 0U;
 *     defaultConfig->voltMonTrim = 0U;
 *     defaultConfig->bgrTrim = 0U;
 *     defaultConfig->tempDetSel = kDRYICE_DIGITAL_Range_105C_125C;
 * @endcode
 * @param base DryIce Digital peripheral base address
 * @param[out] defaultConfig Pointer to structure to be filled with default parameters
 */
void DRYICE_DIGITAL_GetDefaultConfig(DRYICE_Type *base, dryice_digital_config_t *config);

/*!
 * @brief Gets default values for tamper pin configuration.
 *
 * This function fills the give structure with default values for the tamper pin configuration.
 * The default values are:
 * @code
 *     pinConfig->pinDirection = kDRYICE_TamperPinDirectionIn;
 *     pinConfig->ignoredWindowWidth = kDRYICE_DIGITAL_NoIgnoredWindow;
 *     pinConfig->ignoredWinClkSel = kDRYICE_DIGITAL_32768Hz;
 *     pinConfig->ignoredWinStartCycle = 0U;
 *     pinConfig->extTamperRoutingCtrl = kDRYICE_DIGITAL_PassiveInput;
 *     pinConfig->passiveTamperExpDat = kDRYICE_DIGITAL_ExpectedTamperHigh;
 *     pinConfig->pullEnable = false;
 *     pinConfig->pullContinuousEnable = false;
 *     pinConfig->pullSelect = kDRYICE_DIGITAL_PullDown;
 *     pinConfig->pullTransWidth = kDRYICE_DIGITAL_1CycleTransitionWidth;
 *     pinConfig->driveStrength = kDRYICE_DIGITAL_DriveStrenght1;
 *     pinConfig->hysteresisCtrl = kDRYICE_DIGITAL_Schmitt;
 *     pinConfig->outputKeepEnable = false;
 *     pinConfig->sampleClkSel = kDRYICE_DIGITAL_32768Hz;
 *     pinConfig->sampleFreqSel = kDRYICE_DIGITAL_Every8Cycles;
 *     pinConfig->sampleWidth = kDRYICE_DIGITAL_SamplingDisabled;
 * @endcode
 *
 * @param base DryIce Digital peripheral base address
 * @param[out] pinConfig Pointer to structure to be filled with tamper pins default parameters
 */
void DRYICE_DIGITAL_PinGetDefaultConfig(DRYICE_Type *base, dryice_digital_pin_config_t *pinConfig);

/*!
 * @brief Writes to the DryIce Digital TPCTRLn register.
 *
 * This function writes the given structure to the DryIce Digital TPCTRLn Register.
 * @param base DryIce Digital peripheral base address
 * @param config Pointer to structure with DryIce Digital peripheral configuration parameters
 * @return kStatus_Fail when writing to DryIce Control Register is not allowed
 * @return kStatus_Success when operation completes successfully
 */
status_t DRYICE_DIGITAL_SetPinConfig(DRYICE_Type *base,
                                     dryice_digital_tamper_pin_t pin,
                                     const dryice_digital_pin_config_t *pinConfig);

/*!
 * @brief Writes to the DryIce Digital Control Register.
 *
 * This function sets specified tamper enable bits in DryIce Digital Control Register.
 *
 * @param base DryIce Digital peripheral base address
 * @param mask Bit mask for the tamper enable bits to be set.
 */
void DRYICE_DIGITAL_EnableTampers(DRYICE_Type *base, uint32_t mask);

/*!
 * @brief Writes to the DryIce Digital Control Register.
 *
 * This function clears specified tamper enable bits in DryIce Digital Control Register.
 *
 * @param base DryIce Digital peripheral base address
 * @param mask Bit mask for the tamper enable bits to be cleared.
 */
void DRYICE_DIGITAL_DisableTampers(DRYICE_Type *base, uint32_t mask);

/*!
 * @brief Reads the Tamper Resuts Register.
 *
 * This function reads result bits from DryIce Tamper Resuts Register.
 *
 * @param base DryIce Digital peripheral base address
 * @param[out] result Pointer to uint32_t where to write Status Register read value. Use dryice_digital_tamper_result_t
 * to decode
 *                    individual flags.
 */
static inline void DRYICE_DIGITAL_GetTamperResults(DRYICE_Type *base, uint32_t *result)
{
    *result = base->DTRR;
}

/*!
 *@}
 */

#endif /* FSL_DRYICE_DIGITAL_H_ */
