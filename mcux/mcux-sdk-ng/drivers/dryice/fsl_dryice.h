/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DRYICE_H_
#define FSL_DRYICE_H_

#include "fsl_common.h"

/*!
 * @addtogroup dryice
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief DRYICE driver version. Version 2.0.3.
 *
 * Current version: 2.0.3
 *
 * Change log:
 * - Version 2.0.3
 *   - Fix MISRA issue
 * - Version 2.0.2
 *   - Fix MISRA issue KPSDK-18251
 * - Version 2.0.1
 *   - Add support for DRYICE feature macro
 *    - FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT
 *    - FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT
 *    - FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING
 *    - FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT
 */
#define FSL_DRYICE_DRIVER_VERSION (MAKE_VERSION(2, 0, 3))
/*! @} */

/*!
 * @brief DryIce Update Mode.
 *
 * These constants allow DryIce interrupts to be cleared if no tampering has been detected, while still preventing
 * the DryIce Tamper Flag (SR[DTF]) from being cleared once it is set.
 */
typedef enum _dryice_update_mode
{
    kDRYICE_StatusLockNormal = 0U,     /*!< DryIce Status Register cannot be written when the Status Register Lock bit
                                          within the Lock Register (LR[SRL]) is clear */
    kDRYICE_StatusLockWithTamper = 1U, /*!< DryIce Status Register cannot be written when the Status Register Lock bit
                                          within the Lock Register (LR[SRL]) is clear and DryIce Tamper Flag (SR[DTF])
                                          is set*/
} dryice_update_mode_t;

#if defined(FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT > 0)
/*!
 * @brief DryIce Active Tamper Clock Source.
 *
 * These constants define the clock source for Active Tamper Shift Register to configure in a DryIce base.
 */
typedef enum _dryice_active_tamper_clock
{
    kDRYICE_ClockType1Hz   = 0U, /*!< clocked by 1 Hz prescaler clock  */
    kDRYICE_ClockType512Hz = 1U, /*!< clocked by 512 Hz prescaler clock */
} dryice_active_tamper_clock_t;
#endif /* FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT */

/*!
 * @brief DryIce Tamper Hysteresis Select.
 *
 * These constants define the tamper pin hysteresis range to configure in a DryIce base.
 */
typedef enum _dryice_hysteresis
{
    kDRYICE_Hysteresis305mV = 0U, /*!< hysteresis set to a range of 305 mV to 440 mV  */
    kDRYICE_Hysteresis490mV = 1U, /*!< hysteresis set to a range of 490 mV to 705 mV */
} dryice_hysteresis_t;

/*!
 * @brief DryIce Tamper Drive Strength.
 *
 * These constants define tamper pin drive strength to configure in a DryIce base.
 */
typedef enum _dryice_drive_strength
{
    kDRYICE_DriveStrengthLow  = 0U, /*!< tamper pins configured for low drive strength  */
    kDRYICE_DriveStrengthHigh = 1U, /*!< tamper pins configured for high drive strength */
} dryice_drive_strength_t;

/*!
 * @brief DryIce Tamper Slew Rate.
 *
 * These constants define tamper pin slew rate to configure in a DryIce base.
 */
typedef enum _dryice_slew_rate
{
    kDRYICE_SlewRateSlow = 0U, /*!< Tamper pins configured for slow slew rate  */
    kDRYICE_SlewRateFast = 1U, /*!< Tamper pins configured for fast slew rate */
} dryice_slew_rate_t;

#if defined(FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT > 0)
/*!
 * @brief DryIce Secure Register File.
 *
 * These constants define general purpose VBAT Register File to configure in a DryIce base.
 */
typedef enum _dryice_vbat_register_file
{
    kDRYICE_VbatRegisterGeneral =
        0U, /*!< VBAT Register File is general purpose, reset on VBAT POR only, supervisor and user mode accessible */
    kDRYICE_VbatRegisterResetWithTamper =
        2U, /*!< VBAT Register file is secure, reset on DryIce tampering detected, supervisor mode access only */
    kDRYICE_VbatRegisterResetWithTamperOrInterrupt = 3U, /*!< VBAT Register file is secure, reset on DryIce tampering
                                                            detected or DryIce interrupt assertion, supervisor mode
                                                            access only */
} dryice_vbat_register_file_t;
#endif /* FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT */

/*!
 * @brief DryIce Control Register.
 *
 * This structure defines values for DryIce Control Register.
 */
typedef struct _dryice_config
{
    bool innerClockAndPrescalerEnable;   /*!< Enable/disable 32768 Hz clock within DryIce and the DryIce prescaler that
                                            generates 512 Hz and 1 Hz prescaler clocks  */
    bool tamperForceSystemResetEnable;   /*!< Enable/disable assertion of chip reset when tampering is detected */
    enum _dryice_update_mode updateMode; /*!< Selects update mode for DryIce Status Register */
#if defined(FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT > 0)
    enum _dryice_active_tamper_clock
        clockSourceActiveTamper0; /*!< Selects clock source for Active Tamper Shift Register 0 */
    enum _dryice_active_tamper_clock
        clockSourceActiveTamper1;                    /*!< Selects clock source for Active Tamper Shift Register 1 */
#endif                                               /* FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT */
    enum _dryice_hysteresis tamperHysteresisSelect;  /*!< Selects tamper pin hysteresis */
    bool tamperPassiveFilterEnable;                  /*!< Enable/disable tamper pin passive filter */
    enum _dryice_drive_strength tamperDriveStrength; /*!< Selects tamper pin drive strength */
    enum _dryice_slew_rate tamperSlewRate;           /*!< Selects tamper pin slew rate */
#if defined(FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT > 0)
    enum _dryice_vbat_register_file secureRegisterFile; /*!< Configures the general purpose VBAT file security */
#endif                                                  /* FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT */
    uint32_t prescaler;                                 /*!< Initial value for the DryIce prescaler 15-bit value. */
} dryice_config_t;

/*!
 * @brief DryIce Tamper Pin Direction.
 *
 * These constants define tamper pin direction to configure in a DryIce base.
 */
typedef enum _dryice_pin_direction
{
    kDRYICE_TamperPinDirectionIn  = 0U, /*!< Tamper pins configured as input  */
    kDRYICE_TamperPinDirectionOut = 1U, /*!< Tamper pins configured as output, drives inverse of expected value */
} dryice_pin_direction_t;

/*!
 * @brief DryIce Tamper Pin Polarity.
 *
 * These constants define tamper pin polarity to configure in a DryIce base.
 */
typedef enum _dryice_pin_polarity
{
    kDRYICE_TamperPinPolarityExpectNormal   = 0U, /*!< Tamper pin expected value is not inverted  */
    kDRYICE_TamperPinPolarityExpectInverted = 1U, /*!< Tamper pin expected value is inverted */
} dryice_pin_polarity_t;

/*!
 * @brief DryIce Glitch Filter Tamper Pin Clock Source.
 *
 * These constants define tamper pin glitch filter clock source to configure in a DryIce base.
 */
typedef enum _dryice_glitch_filter_prescaler
{
    kDRYICE_GlitchFilterClock512Hz = 0U, /*!< Glitch Filter on tamper pin is clocked by the 512 Hz prescaler clock */
    kDRYICE_GlitchFilterClock32768Hz =
        1U, /*!< Glitch Filter on tamper pin is clocked by the 32768 Hz prescaler clock */
} dryice_glitch_filter_prescaler_t;

#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING > 0)
/*!
 * @brief DryIce Glitch Filter Tamper Pin Sample Width.
 *
 * These constants define tamper pin glitch filter sample width to configure in a DryIce base.
 */
typedef enum _dryice_glitch_filter_sample_width
{
    kDRYICE_GlitchFilterSampleDisable = 0U, /*!<  Sampling disabled */
    kDRYICE_GlitchFilterSampleCycle2  = 1U, /*!<  Sample width pull enable/input buffer enable=2 cycles/1 cycle */
    kDRYICE_GlitchFilterSampleCycle4  = 2U, /*!<  Sample width pull enable/input buffer enable=4 cycles/2 cycles */
    kDRYICE_GlitchFilterSampleCycle8  = 3U, /*!<  Sample width pull enable/input buffer enable=8 cycles/4 cycles */
} dryice_glitch_filter_sample_width_t;

/*!
 * @brief DryIce Glitch Filter Tamper Pin Sample Frequency.
 *
 * These constants define tamper pin glitch filter sample frequency to configure in a DryIce base.
 */
typedef enum _dryice_glitch_filter_sample_freq
{
    kDRYICE_GlitchFilterSamplingEveryCycle8   = 0U, /*!<  Sample once every 8 cycles */
    kDRYICE_GlitchFilterSamplingEveryCycle32  = 1U, /*!<  Sample once every 32 cycles */
    kDRYICE_GlitchFilterSamplingEveryCycle128 = 2U, /*!<  Sample once every 128 cycles */
    kDRYICE_GlitchFilterSamplingEveryCycle512 = 3U, /*!<  Sample once every 512 cycles */
} dryice_glitch_filter_sample_freq_t;
#endif /* FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING */

/*!
 * @brief DryIce Glitch Filter Tamper Pin Expected Value.
 *
 * These constants define tamper pin glitch filter expected value to configure in a DryIce base.
 */
typedef enum _dryice_glitch_filter_expected
{
    kDRYICE_GlitchFilterExpectedLogicZero     = 0U, /*!<  Expected value is logic zero */
    kDRYICE_GlitchFilterExpectedActTamperOut0 = 1U, /*!<  Expected value is active tamper 0 output */
    kDRYICE_GlitchFilterExpectedActTamperOut1 = 2U, /*!<  Expected value is active tamper 1 output */
    kDRYICE_GlitchFilterExpectedActTamperOutXOR =
        3U, /*!<  Expected value is active tamper 0 output XORed with active tamper 1 output */
} dryice_glitch_filter_expected_t;

#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT > 0)
/*!
 * @brief DryIce Glitch Filter Tamper Pull Select.
 *
 * These constants define tamper pin glitch filter pull direction to configure in a DryIce base.
 */
typedef enum _dryice_glitch_filter_pull
{
    kDRYICE_GlitchFilterPullTypeAssert = 0U, /*!< Tamper pin pull direction always asserts the tamper pin. */
    kDRYICE_GlitchFilterPullTypeNegate = 1U, /*!< Tamper pin pull direction always negates the tamper pin. */
} dryice_glitch_filter_pull_t;
#endif /* FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT */

/*!
 * @brief DryIce Tamper Pin configuration registers.
 *
 * This structure defines values for DryIce Pin Direction, Pin Polarity, and Glitch Filter registers.
 */
typedef struct _dryice_pin_config
{
    enum _dryice_pin_direction pinDirection; /*!< Selects tamper pin direction */
    enum _dryice_pin_polarity pinPolarity;   /*!< Selects tamper pin expected value */
    uint8_t glitchFilterWidth; /*!< 6-bit value to configure number of clock edges the input must remain stable for to
                                  be passed through the glitch filter for the tamper pin */
    enum _dryice_glitch_filter_prescaler
        glitchFilterPrescaler; /*!< Selects the prescaler for the glitch filter on tamper pin */
    bool glitchFilterEnable;   /*!< Enable/disable glitch filter on the tamper pin */
#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING > 0)
    enum _dryice_glitch_filter_sample_width tamperPinSampleWidth;    /*!< Selects tamper pin sample width */
    enum _dryice_glitch_filter_sample_freq tamperPinSampleFrequency; /*!< Selects tamper pin sample frequency */
#endif
    enum _dryice_glitch_filter_expected tamperPinExpected; /*!< Selects tamper pin expected value */
    bool tamperPullEnable;                                 /*!< Enable/disable pull resistor on the tamper pin */
#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT > 0)
    enum _dryice_glitch_filter_pull tamperPullSelect; /*!< Selects the direction of the tamper pin pull resistor */
#endif
} dryice_pin_config_t;

/*!
 * @brief DryIce Tamper Pin Select.
 *
 * These constants are used to define pinSelect argument (tamper pin selection) to be used with DRYICE_PinConfigure().
 */
typedef enum _dryice_tamper_pin
{
    kDRYICE_Pin0 = 1u << 0,
    kDRYICE_Pin1 = 1u << 1,
    kDRYICE_Pin2 = 1u << 2,
    kDRYICE_Pin3 = 1u << 3,
    kDRYICE_Pin4 = 1u << 4,
    kDRYICE_Pin5 = 1u << 5,
    kDRYICE_Pin6 = 1u << 6,
    kDRYICE_Pin7 = 1u << 7,
} dryice_tamper_pin_t;

/*!
 * @brief DryIce Active Tamper registers.
 *
 * This structure defines values for DryIce Active Tamper Registers.
 */
typedef struct _dryice_active_tamper_config
{
    uint32_t activeTamperShift;      /*!< Active tamper shift register. initialize to non-zero value. */
    uint32_t activeTamperPolynomial; /*!< Polynomial of the active tamper shift register. */
} dryice_active_tamper_config_t;

/*!
 * @brief DryIce Active Tamper Register Select.
 *
 * These constants are used to define activeTamperRegisterSelect argument to be used with
 * DRYICE_ActiveTamperConfigure().
 */
typedef enum _dryice_active_tamper_register
{
    kDRYICE_ActiveTamperRegister0 = 1u << 0,
    kDRYICE_ActiveTamperRegister1 = 1u << 1,
} dryice_active_tamper_register_t;

/*!
 * @brief DryIce Status Register flags.
 *
 * This provides constants for the DryIce Status Register.
 */
typedef enum _dryice_status_flag
{
    kDRYICE_StatusTamperFlag              = 1U << DRY_SR_DTF_SHIFT, /*!< DryIce Tamper Flag */
    kDRYICE_StatusTamperAcknowledgeFlag   = 1U << DRY_SR_TAF_SHIFT, /*!< DryIce Tamper Acknowledge Flag */
    kDRYICE_StatusTimeOverflowTamper      = 1U << DRY_SR_TOF_SHIFT, /*!< DryIce RTC Time Overflow Tamper detected */
    kDRYICE_StatusMonotonicOverflowTamper = 1U
                                            << DRY_SR_MOF_SHIFT, /*!< DryIce RTC Monotonic Overflow Tamper detected */
    kDRYICE_StatusVoltageTamper       = 1U << DRY_SR_VTF_SHIFT,  /*!< DryIce Voltage Tamper detected */
    kDRYICE_StatusClockTamper         = 1U << DRY_SR_CTF_SHIFT,  /*!< DryIce Clock Tamper detected */
    kDRYICE_StatusTemperatureTamper   = 1U << DRY_SR_TTF_SHIFT,  /*!< DryIce Temperature Tamper detected */
    kDRYICE_StatusSecurityTamper      = 1U << DRY_SR_STF_SHIFT,  /*!< DryIce Security Tamper detected */
    kDRYICE_StatusFlashSecurityTamper = 1U << DRY_SR_FSF_SHIFT,  /*!< DryIce Flash Security Tamper detected */
    kDRYICE_StatusTestModeTamper      = 1U << DRY_SR_TMF_SHIFT,  /*!< DryIce Test Mode Tamper detected */
    kDRYICE_StatusTamperPinTamper0    = 1U << DRY_SR_TPF_SHIFT,  /*!< DryIce Tamper Pin 0 Tamper detected */
    kDRYICE_StatusTamperPinTamper1    = 1U << (DRY_SR_TPF_SHIFT + 1), /*!< DryIce Tamper Pin 1 Tamper detected */
    kDRYICE_StatusTamperPinTamper2    = 1U << (DRY_SR_TPF_SHIFT + 2), /*!< DryIce Tamper Pin 2 Tamper detected */
    kDRYICE_StatusTamperPinTamper3    = 1U << (DRY_SR_TPF_SHIFT + 3), /*!< DryIce Tamper Pin 3 Tamper detected */
    kDRYICE_StatusTamperPinTamper4    = 1U << (DRY_SR_TPF_SHIFT + 4), /*!< DryIce Tamper Pin 4 Tamper detected */
    kDRYICE_StatusTamperPinTamper5    = 1U << (DRY_SR_TPF_SHIFT + 5), /*!< DryIce Tamper Pin 5 Tamper detected */
    kDRYICE_StatusTamperPinTamper6    = 1U << (DRY_SR_TPF_SHIFT + 6), /*!< DryIce Tamper Pin 6 Tamper detected */
    kDRYICE_StatusTamperPinTamper7    = 1U << (DRY_SR_TPF_SHIFT + 7), /*!< DryIce Tamper Pin 7 Tamper detected */
    kDRYICE_StatusAll = DRY_SR_TPF_MASK | DRY_SR_TMF_MASK | DRY_SR_FSF_MASK | DRY_SR_STF_MASK | DRY_SR_TTF_MASK |
                        DRY_SR_CTF_MASK | DRY_SR_VTF_MASK | DRY_SR_MOF_MASK | DRY_SR_TOF_MASK | DRY_SR_TAF_MASK |
                        DRY_SR_DTF_MASK, /*!< Mask for all of the DryIce Status Register bits */
} dryice_status_flag_t;

/*!
 * @brief DryIce Interrupt Enable Register.
 *
 * This provides constants for the DryIce Interrupt Enable Register.
 */
typedef enum _dryice_interrupt
{
    kDRYICE_InterruptTamper              = 1U << DRY_IER_DTIE_SHIFT, /*!< DryIce Tamper Interrupt  */
    kDRYICE_InterruptTimeOverflow        = 1U << DRY_IER_TOIE_SHIFT, /*!< DryIce Time Overflow Interrupt */
    kDRYICE_InterruptMonotonicOverflow   = 1U << DRY_IER_MOIE_SHIFT, /*!< DryIce Monotonic Overflow Interrupt */
    kDRYICE_InterruptVoltageTamper       = 1U << DRY_IER_VTIE_SHIFT, /*!< DryIce Voltage Tamper Interrupt */
    kDRYICE_InterruptClockTamper         = 1U << DRY_IER_CTIE_SHIFT, /*!< DryIce Clock Tamper Interrupt */
    kDRYICE_InterruptTemperatureTamper   = 1U << DRY_IER_TTIE_SHIFT, /*!< DryIce Temperature Tamper Interrupt */
    kDRYICE_InterruptSecurityTamper      = 1U << DRY_IER_STIE_SHIFT, /*!< DryIce Security Tamper Interrupt */
    kDRYICE_InterruptFlashSecurityTamper = 1U << DRY_IER_FSIE_SHIFT, /*!< DryIce Flash Security Tamper Interrupt */
    kDRYICE_InterruptTestModeTamper      = 1U << DRY_IER_TMIE_SHIFT, /*!< DryIce Test Mode Tamper Interrupt */
    kDRYICE_InterruptTamperPinTamper0    = 1U << DRY_IER_TPIE_SHIFT, /*!< DryIce Tamper Pin Tamper 0 Interrupt */
    kDRYICE_InterruptTamperPinTamper1    = 1U << (DRY_IER_TPIE_SHIFT + 1), /*!< DryIce Tamper Pin Tamper 1 Interrupt */
    kDRYICE_InterruptTamperPinTamper2    = 1U << (DRY_IER_TPIE_SHIFT + 2), /*!< DryIce Tamper Pin Tamper 2 Interrupt */
    kDRYICE_InterruptTamperPinTamper3    = 1U << (DRY_IER_TPIE_SHIFT + 3), /*!< DryIce Tamper Pin Tamper 3 Interrupt */
    kDRYICE_InterruptTamperPinTamper4    = 1U << (DRY_IER_TPIE_SHIFT + 4), /*!< DryIce Tamper Pin Tamper 4 Interrupt */
    kDRYICE_InterruptTamperPinTamper5    = 1U << (DRY_IER_TPIE_SHIFT + 5), /*!< DryIce Tamper Pin Tamper 5 Interrupt */
    kDRYICE_InterruptTamperPinTamper6    = 1U << (DRY_IER_TPIE_SHIFT + 6), /*!< DryIce Tamper Pin Tamper 6 Interrupt */
    kDRYICE_InterruptTamperPinTamper7    = 1U << (DRY_IER_TPIE_SHIFT + 7), /*!< DryIce Tamper Pin Tamper 7 Interrupt */
    kDRYICE_InterruptTamperPinTamper_All = DRY_IER_TPIE_MASK,              /*!< DryIce All Tamper Pins Interrupt */
    kDRYICE_InterruptAll = DRY_IER_TPIE_MASK | DRY_IER_TMIE_MASK | DRY_IER_FSIE_MASK | DRY_IER_STIE_MASK |
                           DRY_IER_TTIE_MASK | DRY_IER_CTIE_MASK | DRY_IER_VTIE_MASK | DRY_IER_MOIE_MASK |
                           DRY_IER_TOIE_MASK |
                           DRY_IER_DTIE_MASK, /*!< Mask to select all DryIce Interrupt Enable Register bits */
} dryice_interrupt_t;

/*!
 * @brief DryIce Tamper Enable Register.
 *
 * This provides constants for the DryIce Tamper Enable Register.
 */
typedef enum _dryice_tamper
{
    kDRYICE_TamperTimeOverflow      = 1U << DRY_TER_TOE_SHIFT,       /*!< Time Overflow Tamper Enable */
    kDRYICE_TamperMonotonicOverflow = 1U << DRY_TER_MOE_SHIFT,       /*!< Monotonic Overflow Tamper Enable */
    kDRYICE_TamperVoltage           = 1U << DRY_TER_VTE_SHIFT,       /*!< Voltage Tamper Enable */
    kDRYICE_TamperClock             = 1U << DRY_TER_CTE_SHIFT,       /*!< Clock Tamper Enable */
    kDRYICE_TamperTemperature       = 1U << DRY_TER_TTE_SHIFT,       /*!< Temperature Tamper Enable */
    kDRYICE_TamperSecurity          = 1U << DRY_TER_STE_SHIFT,       /*!< Security Tamper Enable */
    kDRYICE_TamperFlashSecurity     = 1U << DRY_TER_FSE_SHIFT,       /*!< Flash Security Tamper Enable */
    kDRYICE_TamperTestMode          = 1U << DRY_TER_TME_SHIFT,       /*!< Test Mode Tamper Enable */
    kDRYICE_TamperTamperPin0        = 1U << DRY_TER_TPE_SHIFT,       /*!< Tamper Pin 0 Tamper Enable */
    kDRYICE_TamperTamperPin1        = 1U << (DRY_TER_TPE_SHIFT + 1), /*!< Tamper Pin 1 Tamper Enable */
    kDRYICE_TamperTamperPin2        = 1U << (DRY_TER_TPE_SHIFT + 2), /*!< Tamper Pin 2 Tamper Enable */
    kDRYICE_TamperTamperPin3        = 1U << (DRY_TER_TPE_SHIFT + 3), /*!< Tamper Pin 3 Tamper Enable */
    kDRYICE_TamperTamperPin4        = 1U << (DRY_TER_TPE_SHIFT + 4), /*!< Tamper Pin 4 Tamper Enable */
    kDRYICE_TamperTamperPin5        = 1U << (DRY_TER_TPE_SHIFT + 5), /*!< Tamper Pin 5 Tamper Enable */
    kDRYICE_TamperTamperPin6        = 1U << (DRY_TER_TPE_SHIFT + 6), /*!< Tamper Pin 6 Tamper Enable */
    kDRYICE_TamperTamperPin7        = 1U << (DRY_TER_TPE_SHIFT + 7), /*!< Tamper Pin 7 Tamper Enable */
    kDRYICE_TamperTamperPinAll      = DRY_TER_TPE_MASK,              /*!< All Tamper Pin Tamper Enable */
    kDRYICE_TamperAll = DRY_TER_TPE_MASK | DRY_TER_TME_MASK | DRY_TER_FSE_MASK | DRY_TER_STE_MASK | DRY_TER_TTE_MASK |
                        DRY_TER_CTE_MASK | DRY_TER_VTE_MASK | DRY_TER_MOE_MASK |
                        DRY_TER_TOE_MASK, /*!< Mask to select all Tamper Enable Register bits */
} dryice_tamper_t;

/*!
 * @brief DryIce Registers.
 *
 * This provides constants to encode a mask for the DryIce Registers.
 */
typedef enum _dryice_register
{
    kDRYICE_NoRegister                = 0U,                           /*!< No Register */
    kDRYICE_KeyValid                  = 1U << DRY_LR_KVL_SHIFT,       /*!< Secure Key Valid Register */
    kDRYICE_KeyWrite                  = 1U << DRY_LR_KWL_SHIFT,       /*!< Secure Key Write Register */
    kDRYICE_KeyRead                   = 1U << DRY_LR_KRL_SHIFT,       /*!< Secure Key Read Register */
    kDRYICE_Control                   = 1U << DRY_LR_CRL_SHIFT,       /*!< Control Register */
    kDRYICE_Status                    = 1U << DRY_LR_SRL_SHIFT,       /*!< Status Register */
    kDRYICE_Lock                      = 1U << DRY_LR_LRL_SHIFT,       /*!< Lock Register */
    kDRYICE_InterruptEnable           = 1U << DRY_LR_IEL_SHIFT,       /*!< Interrupt Enable Register */
    kDRYICE_TamperSeconds             = 1U << DRY_LR_TSL_SHIFT,       /*!< Tamper Seconds Register */
    kDRYICE_TamperEnable              = 1U << DRY_LR_TEL_SHIFT,       /*!< Tamper Enable Register */
    kDRYICE_PinDirection              = 1U << DRY_LR_PDL_SHIFT,       /*!< Pin Direction Register */
    kDRYICE_PinPolarity               = 1U << DRY_LR_PPL_SHIFT,       /*!< Pin Polarity Register */
    kDRYICE_ActiveTamper0             = 1U << DRY_LR_ATL_SHIFT,       /*!< Active Tamper Register 0 */
    kDRYICE_ActiveTamper1             = 1U << (DRY_LR_ATL_SHIFT + 1), /*!< Active Tamper Register 1 */
    kDRYICE_GlitchFilter0             = 1U << DRY_LR_GFL_SHIFT,       /*!< Glitch Filter Register 0 */
    kDRYICE_GlitchFilter1             = 1U << (DRY_LR_GFL_SHIFT + 1), /*!< Glitch Filter Register 1 */
    kDRYICE_GlitchFilter2             = 1U << (DRY_LR_GFL_SHIFT + 2), /*!< Glitch Filter Register 2 */
    kDRYICE_GlitchFilter3             = 1U << (DRY_LR_GFL_SHIFT + 3), /*!< Glitch Filter Register 3 */
    kDRYICE_GlitchFilter4             = 1U << (DRY_LR_GFL_SHIFT + 4), /*!< Glitch Filter Register 4 */
    kDRYICE_GlitchFilter5             = 1U << (DRY_LR_GFL_SHIFT + 5), /*!< Glitch Filter Register 5 */
    kDRYICE_GlitchFilter6             = 1U << (DRY_LR_GFL_SHIFT + 6), /*!< Glitch Filter Register 6 */
    kDRYICE_GlitchFilter7             = 1U << (DRY_LR_GFL_SHIFT + 7), /*!< Glitch Filter Register 7 */
    kDRYICE_PinConfigurationRegisters = DRY_LR_GFL_MASK | DRY_LR_ATL_MASK | DRY_LR_PPL_MASK |
                                        DRY_LR_PDL_MASK, /*!< Mask to select all DryIce Pin Configuration Registers */
    kDRYICE_AllRegisters = DRY_LR_GFL_MASK | DRY_LR_ATL_MASK | DRY_LR_PPL_MASK | DRY_LR_PDL_MASK | DRY_LR_TEL_MASK |
                           DRY_LR_TSL_MASK | DRY_LR_IEL_MASK | DRY_LR_LRL_MASK | DRY_LR_SRL_MASK | DRY_LR_CRL_MASK |
                           DRY_LR_KRL_MASK | DRY_LR_KWL_MASK |
                           DRY_LR_KVL_MASK, /*!< Mask to select all DryIce Registers */
} dryice_register_t;

/*!
 * @brief DryIce Secure Key Registers.
 *
 * This provides constants to encode a mask for the DryIce Secure Key Registers.
 */
typedef enum _dryice_secure_key
{
    kDRYICE_NoSecureKey   = 0U,      /*!< No Secure Key */
    kDRYICE_SecureKey0    = 1U << 0, /*!< Secure Key Register 0 */
    kDRYICE_SecureKey1    = 1U << 1, /*!< Secure Key Register 1 */
    kDRYICE_SecureKey2    = 1U << 2, /*!< Secure Key Register 2 */
    kDRYICE_SecureKey3    = 1U << 3, /*!< Secure Key Register 3 */
    kDRYICE_SecureKey4    = 1U << 4, /*!< Secure Key Register 4 */
    kDRYICE_SecureKey5    = 1U << 5, /*!< Secure Key Register 5 */
    kDRYICE_SecureKey6    = 1U << 6, /*!< Secure Key Register 6 */
    kDRYICE_SecureKey7    = 1U << 7, /*!< Secure Key Register 7 */
    kDRYICE_AllSecureKeys = 0xffU,   /*!< Mask to select all DryIce Secure Key Registers */
} dryice_secure_key_t;

/*!
 * @brief DryIce Access Types.
 *
 * This provides constants to encode select between Read, Write and ReadWrite access types.
 */
typedef enum _dryice_readwrite
{
    kDRYICE_Read      = 0U,
    kDRYICE_Write     = 1U,
    kDRYICE_ReadWrite = 2U,
} dryice_readwrite_t;

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
 * @brief Enables the clock gate for the DryIce.
 *
 * This function enables the clock gate for the DryIce peripheral.
 */
void DRYICE_Init(DRY_Type *base);

/*!
 * @brief Disables the clock the DryIce peripheral.
 *
 * This function disables glitch filters and active tampers
 * This function disables the DryIce clock and prescaler in DryIce Control Register.
 * This function disables the clock gate for the DryIce peripheral.
 */
void DRYICE_Deinit(DRY_Type *base);

/*!
 * @brief Gets default values for the DryIce Control Register.
 *
 * This function fills the given structure with default values for the DryIce Control Register.
 * The default values are:
 * @code
 *     defaultConfig->innerClockAndPrescalerEnable = true
 *     defaultConfig->tamperForceSystemResetEnable = false
 *     defaultConfig->updateMode = kDRYICE_StatusLockWithTamper
 *     defaultConfig->clockSourceActiveTamper0 = kDRYICE_ClockType1Hz
 *     defaultConfig->clockSourceActiveTamper1 = kDRYICE_ClockType1Hz
 *     defaultConfig->tamperHysteresisSelect = kDRYICE_Hysteresis305mV
 *     defaultConfig->tamperPassiveFilterEnable = false
 *     defaultConfig->tamperDriveStrength = kDRYICE_DriveStrengthLow
 *     defaultConfig->tamperSlewRate = kDRYICE_SlewRateSlow
 *     defaultConfig->secureRegisterFile = kDRYICE_VbatRegisterResetWithTamperOrInterrupt
 *     defaultConfig->prescaler = 0
 * @endcode
 * @param base DryIce peripheral base address
 * @param[out] defaultConfig Pointer to structure to be filled with default parameters
 */
void DRYICE_GetDefaultConfig(DRY_Type *base, dryice_config_t *defaultConfig);

/*!
 * @brief Writes to the DryIce Control Register.
 *
 * This function writes the given structure to the DryIce Control Register.
 * @param base DryIce peripheral base address
 * @param config Pointer to structure with DryIce peripheral configuration parameters
 * @return kStatus_Fail when writing to DryIce Control Register is not allowed
 * @return kStatus_Success when operation completes successfully
 */
status_t DRYICE_SetConfig(DRY_Type *base, const dryice_config_t *config);

/*!
 * @brief Software reset.
 *
 * This function resets all DryIce registers except WAC, RAC, SRAC, and SWAC. The CR[SWR] field is also not affected;
 * it is reset by VBAT POR only.
 *
 * @param base DryIce peripheral base address
 * @return kStatus_Fail when writing to DryIce Control Register is not allowed
 * @return kStatus_Success when operation completes successfully
 */
status_t DRYICE_SoftwareReset(DRY_Type *base);

/*!
 * @brief Writes to the active tamper register(s).
 *
 * This function writes per active tamper register parameters to active tamper register(s).
 *
 * @param base DryIce peripheral base address
 * @param activeTamperConfig Pointer to structure with active tamper register parameters
 * @param activeTamperRegisterSelect Bit mask for active tamper registers to be configured. The passed value is
 *                                   combination of dryice_active_tamper_register_t values (OR'ed).
 * @return kStatus_Fail when writing to DryIce Active Tamper Register(s) is not allowed
 * @return kStatus_Success when operation completes successfully
 */
status_t DRYICE_ActiveTamperSetConfig(DRY_Type *base,
                                      const dryice_active_tamper_config_t *activeTamperConfig,
                                      uint32_t activeTamperRegisterSelect);

/*!
 * @brief Gets default values for tamper pin configuration.
 *
 * This function fills the give structure with default values for the tamper pin and glitch filter configuration.
 * The default values are:
 * @code
 *     pinConfig->pinDirection = kDRYICE_TamperPinDirectionIn;
 *     pinConfig->pinPolarity = kDRYICE_TamperPinPolarityExpectNormal;
 *     pinConfig->glitchFilterWidth = 0;
 *     pinConfig->glitchFilterPrescaler = kDRYICE_GlitchFilterClock512Hz;
 *     pinConfig->glitchFilterEnable = false;
 *     pinConfig->tamperPinSampleWidth = kDRYICE_GlitchFilterSampleDisable;
 *     pinConfig->tamperPinSampleFrequency = kDRYICE_GlitchFilterSamplingEveryCycle8;
 *     pinConfig->tamperPinExpected = kDRYICE_GlitchFilterExpectedLogicZero;
 *     pinConfig->tamperPullEnable = false;
 *     pinConfig->tamperPullSelect = kDRYICE_GlitchFilterPullTypeAssert;
 * @endcode
 *
 * @param base DryIce peripheral base address
 * @param[out] pinConfig Pointer to structure to be filled with tamper pins default parameters
 */
void DRYICE_PinGetDefaultConfig(DRY_Type *base, dryice_pin_config_t *pinConfig);

/*!
 * @brief Writes the tamper pin configuration.
 *
 * This function writes per pin parameters to tamper pin and glitch filter configuration registers.
 *
 * @param base DryIce peripheral base address
 * @param pinConfig Pointer to structure with tamper pin and glitch filter configuration parameters
 * @param pinSelect Bit mask for tamper pins to be configured. The passed value is combination of
 *                  enum _dryice_tamper_pin (dryice_tamper_pin_t) values (OR'ed).
 * @return kStatus_Fail when writing to DryIce Pin Direction, Pin Polarity or Glitch Filter Register(s) is not allowed
 * @return kStatus_Success when operation completes successfully
 */
status_t DRYICE_PinSetConfig(DRY_Type *base, const dryice_pin_config_t *pinConfig, uint32_t pinSelect);

/*!
 * @brief Reads the Secure Key Register(s).
 *
 * This function reads actual value from Secure Key Register(s).
 *
 * @param base DryIce peripheral base address
 * @param[out] key Pointer to storage array (application buffer)
 * @param keySize Storage array size in bytes
 * @return kStatus_Fail if reading is not allowed (read access disabled or key argument is NULL)
 * @return kStatus_Success when secure keys have been written to input storage array
 */
status_t DRYICE_GetKey(DRY_Type *base, uint8_t *key, size_t keySize);

/*!
 * @brief Writes the Secure Key Register(s).
 *
 * This function writes given data to Secure Key Register(s).
 *
 * @param base DryIce peripheral base address
 * @param key Pointer to key to be stored in the DryIce peripheral
 * @param keySize Key size in bytes
 * @return kStatus_Fail if writing is not allowed (locked or write access disabled or key argument is NULL)
 * @return kStatus_Success when Secure Key Register(s) have been written with new values
 */
status_t DRYICE_WriteKey(DRY_Type *base, const uint8_t *key, size_t keySize);

/*!
 * @brief Reads the Status Register.
 *
 * This function reads flag bits from DryIce Status Register.
 *
 * @param base DryIce peripheral base address
 * @param[out] result Pointer to uint32_t where to write Status Register read value. Use dryice_status_flag_t to decode
 *                    individual flags.
 * @return kStatus_Fail when Status Register reading is not allowed
 * @return kStatus_Success when result is written with the Status Register read value
 */
status_t DRYICE_GetStatusFlags(DRY_Type *base, uint32_t *result);

/*!
 * @brief Writes to the Status Register.
 *
 * This function clears specified flag bits in DryIce Status Register.
 *
 * @param base DryIce peripheral base address
 * @param mask Bit mask for the flag bits to be cleared. Use dryice_status_flag_t to encode flags.
 * @return kStatus_Fail when Status Register writing is not allowed
 * @return kStatus_Success when mask is written to the Status Register
 */
status_t DRYICE_ClearStatusFlags(DRY_Type *base, uint32_t mask);

/*!
 * @brief Writes to the Interrupt Enable Register.
 *
 * This function sets specified interrupt enable bits in DryIce Interrupt Enable Register.
 *
 * @param base DryIce peripheral base address
 * @param mask Bit mask for the interrupt enable bits to be set.
 * @return kStatus_Fail when Interrupt Enable Register writing is not allowed
 * @return kStatus_Success when mask is written to the Interrupt Enable Register
 */
status_t DRYICE_EnableInterrupts(DRY_Type *base, uint32_t mask);

/*!
 * @brief Writes to the Interrupt Enable Register.
 *
 * This function clears specified interrupt enable bits in DryIce Interrupt Enable Register.
 *
 * @param base DryIce peripheral base address
 * @param mask Bit mask for the interrupt enable bits to be cleared.
 * @return kStatus_Fail when Interrupt Enable Register writing is not allowed
 * @return kStatus_Success when specified bits are cleared in the Interrupt Enable Register
 */
status_t DRYICE_DisableInterrupts(DRY_Type *base, uint32_t mask);

/*!
 * @brief Writes to the Tamper Enable Register.
 *
 * This function sets specified tamper enable bits in DryIce Tamper Enable Register.
 *
 * @param base DryIce peripheral base address
 * @param mask Bit mask for the tamper enable bits to be set.
 * @return kStatus_Fail when Tamper Enable Register writing is not allowed
 * @return kStatus_Success when mask is written to the Tamper Enable Register
 */
status_t DRYICE_EnableTampers(DRY_Type *base, uint32_t mask);

/*!
 * @brief Writes to the Tamper Enable Register.
 *
 * This function clears specified tamper enable bits in DryIce Tamper Enable Register.
 *
 * @param base DryIce peripheral base address
 * @param mask Bit mask for the tamper enable bits to be cleared.
 * @return kStatus_Fail when Tamper Enable Register writing is not allowed
 * @return kStatus_Success when specified bits are cleared in the Tamper Enable Register
 */
status_t DRYICE_DisableTampers(DRY_Type *base, uint32_t mask);

/*!
 * @brief Writes to the Tamper Seconds Register.
 *
 * This function writes to DryIce Tamper Seconds Register. This causes Status Register DTF flag to be set (DryIce
 * tampering detected).
 *
 * @param base DryIce peripheral base address
 * @return kStatus_Fail when Tamper Seconds Register writing is not allowed
 * @return kStatus_Success when Tamper Seconds Register is written
 */
status_t DRYICE_ForceTamper(DRY_Type *base);

/*!
 * @brief Reads the Tamper Seconds Register.
 *
 * This function reads DryIce Tamper Seconds Register. The read value returns the time in seconds at which the Status
 * Register DTF flag was set.
 *
 * @param base DryIce peripheral base address
 * @param tamperTimeSeconds Time in seconds at which the tamper detection SR[DTF] flag was set.
 * @return kStatus_Fail when Tamper Seconds Register reading is not allowed
 * @return kStatus_Success when Tamper Seconds Register is read
 */
status_t DRYICE_GetTamperTimeSeconds(DRY_Type *base, uint32_t *tamperTimeSeconds);

/*!
 * @brief Writes to the DryIce Lock Register.
 *
 * This function clears specified lock bits in the DryIce Lock Register.
 * When a lock bit is clear, a write to corresponding DryIce Register is ignored.
 * Once cleared, these bits can only be set by VBAT POR or software reset.
 *
 * @param base DryIce peripheral base address
 * @param mask Bit mask for the lock bits to be cleared. Use dryice_register_t values to encode (OR'ed) which DryIce
 * Registers shall be locked.
 */
void DRYICE_LockRegisters(DRY_Type *base, uint32_t mask);

/*!
 * @brief Writes to DryIce Secure Key Lock Registers.
 *
 * This function clears specified lock bits in the DryIce Secure Key Write or Secure Key Read Lock Registers.
 * When a lock bit is clear, a read/write from/to corresponding DryIce Secure Key Register is ignored.
 * Once cleared, these bits can only be set by VBAT POR or software reset.
 *
 * @param base DryIce peripheral base address
 * @param mask Bit mask for the lock bits to be cleared. Use dryice_secure_key_t values to encode (OR'ed) which DryIce
 *             Secure Key Registers shall be locked.
 * @param readWrite Select Read or Write (or ReadWrite) lock.
 */
void DRYICE_LockSecureKeys(DRY_Type *base, uint32_t mask, dryice_readwrite_t readWrite);

/*!
 * @brief Writes to DryIce Access Control Registers.
 *
 * This function clears specified access control bits in the DryIce Access Control Registers.
 * When an access control bit is clear, a read/write from/to corresponding DryIce Register or Secure Key Register is
 * ignored.
 * Once cleared, these bits can only be set by VBAT POR or software reset.
 *
 * @param base DryIce peripheral base address
 * @param maskRegisters Bit mask for the access control bits to be cleared. Use dryice_register_t values to encode
 *                      (OR'ed) which DryIce Registers shall be access controlled.
 * @param maskKeys Bit mask for the access control bits to be cleared. Use dryice_secure_key_t values to encode (OR'ed)
 *                 which DryIce Secure Key Registers shall be access controlled.
 * @param readWrite Disallow Read or Write (or ReadWrite).
 */
void DRYICE_DisableAccess(DRY_Type *base, uint32_t maskRegisters, uint32_t maskKeys, dryice_readwrite_t readWrite);

/*!
 *@}
 */

#endif /* FSL_DRYICE_H_ */
