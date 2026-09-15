/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_DUAL_ADC_H_
#define FSL_DUAL_ADC_H_

#include "fsl_common.h"

/*!
 * @addtogroup dual_adc_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_DUAL_ADC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0 */
/*! @} */

/*!
 * @brief NOP loop count used to hold CTRL[RSTA]/CTRL[RSTB] asserted long enough
 *        for the software reset to take effect.
 *
 * CTRL[RSTA] and CTRL[RSTB] are NOT self-clearing. The logic high level must be
 * sustained for more than 2 ADC functional clock cycles before the reset takes
 * effect; the bits must then be cleared explicitly by software. This macro
 * controls how many __NOP() iterations are executed between asserting and
 * releasing the reset bits in DUALADC_Init, providing a portable hold time that
 * scales with CPU clock speed.
 *
 * The required NOP count scales with the CPU-to-ADC clock frequency ratio:
 *   min_count = ceil(2 * f_CPU / f_ADC)
 * The default value of 20 covers ratios up to 10 (e.g., 150 MHz CPU with
 * 16 MHz ADC clock). Increase this value via Kconfig option
 * CONFIG_DUALADC_RESET_TIMEOUT when the CPU clock is much faster than the
 * ADC functional clock (large f_CPU/f_ADC ratio).
 */
#ifndef DUALADC_RESET_TIMEOUT
#ifdef CONFIG_DUALADC_RESET_TIMEOUT
#define DUALADC_RESET_TIMEOUT (uint32_t)CONFIG_DUALADC_RESET_TIMEOUT
#else
#define DUALADC_RESET_TIMEOUT (20UL)
#endif
#endif

/*!
 * @brief Max loop count waiting for each calibration step (STAT0[CAL_RDY], GCC[n][RDY]) to complete.
 *
 * Set via Kconfig option CONFIG_DUALADC_CALIBRATION_TIMEOUT. Default 0 means wait forever.
 */
#ifndef DUALADC_CALIBRATION_TIMEOUT
#ifdef CONFIG_DUALADC_CALIBRATION_TIMEOUT
#define DUALADC_CALIBRATION_TIMEOUT CONFIG_DUALADC_CALIBRATION_TIMEOUT
#else
#define DUALADC_CALIBRATION_TIMEOUT 0 /* Wait forever until calibration completes. */
#endif
#endif

/*!
 * @brief DualADC conversion mode selection.
 *
 * Controls whether ADCA and ADCB share one conversion sequence (cooperation)
 * or run independent sequences (independence).
 */
typedef enum _dadc_conversion_mode
{
    kDADC_CooperationMode  = 0U, /*!< Cooperation mode: ADCA and ADCB share one conversion sequence. */
    kDADC_IndependenceMode = 1U, /*!< Independence mode: ADCA and ADCB run independent sequences. */
} dadc_conversion_mode_t;

/*!
 * @brief DualADC power configuration.
 *
 * Selects the power and maximum ADCK frequency trade-off.
 */
typedef enum _dadc_power_config
{
    kDADC_LowPowerConfig  = 0U, /*!< Low power mode: maximum ADCK frequency 24 MHz (default). */
    kDADC_HighPowerConfig = 1U, /*!< High power mode: maximum ADCK frequency 64 MHz. */
} dadc_power_config_t;

/*!
 * @brief DualADC voltage reference source selection.
 */
typedef enum _dadc_ref_voltage_src
{
    kDADC_VrefH0 = 0U, /*!< VREFH0x - default reference. */
    kDADC_VrefH1 = 1U, /*!< VREFH1x. */
    kDADC_VrefH2 = 2U, /*!< VREFH2x. */
} dadc_ref_voltage_src_t;

/*!
 * @brief DualADC tune mode selection.
 *
 * @note Consult the device-specific reference manual for the effect of each value.
 */
typedef enum _dadc_tune_mode
{
    kDADC_TuneMode0 = 0U, /*!< Tune mode 0. */
    kDADC_TuneMode1 = 1U, /*!< Tune mode 1. */
    kDADC_TuneMode2 = 2U, /*!< Tune mode 2. */
} dadc_tune_mode_t;

/*!
 * @brief Number of ADC conversions averaged during calibration routines.
 *
 * Applied to offset calibration (CTRL[CALOFS]), high-speed calibration (CTRL[CALHS]),
 * and gain calibration (CTRL[CAL_REQ]).
 * The recommended minimum is @ref kDADC_CalibrationAverage256.
 */
typedef enum _dadc_calibration_averages
{
    kDADC_CalibrationAverageSingle = 0U,  /*!< Single conversion - no averaging. */
    kDADC_CalibrationAverage2      = 1U,  /*!< 2 conversions averaged. */
    kDADC_CalibrationAverage4      = 2U,  /*!< 4 conversions averaged. */
    kDADC_CalibrationAverage8      = 3U,  /*!< 8 conversions averaged. */
    kDADC_CalibrationAverage16     = 4U,  /*!< 16 conversions averaged. */
    kDADC_CalibrationAverage32     = 5U,  /*!< 32 conversions averaged. */
    kDADC_CalibrationAverage64     = 6U,  /*!< 64 conversions averaged. */
    kDADC_CalibrationAverage128    = 7U,  /*!< 128 conversions averaged. */
    kDADC_CalibrationAverage256    = 8U,  /*!< 256 conversions averaged (RM recommended minimum). */
    kDADC_CalibrationAverage512    = 9U,  /*!< 512 conversions averaged. */
    kDADC_CalibrationAverage1024   = 10U, /*!< 1024 conversions averaged. */
} dadc_calibration_averages_t;

/*!
 * @brief DualADC trigger source selection for ADCA (CFG0[TRIGSEL]).
 */
typedef enum _dadc_trig_sel
{
    kDADC_TrigSelTrigger0      = 0U,    /*!< Trigger0 input. */
    kDADC_TrigSelTriggerSyncIn = 1U,    /*!< Trigger_sync_in input. */
} dadc_trig_sel_t;

/*!
 * @brief DualADC DMA trigger source selection (DE[DMASRCA/B]).
 */
typedef enum _dadc_dma_src
{
    kDADC_DmaSrcEndOfScan   = 0U, /*!< DMA triggered by end-of-scan; cleared by DMA ack. */
    kDADC_DmaSrcResultReady = 1U, /*!< DMA triggered by result-ready; cleared by reading RSLT. */
} dadc_dma_src_t;

/*!
 * @brief DualADC software trigger selection mask.
 *
 * Values may be OR'd together to assert Trigger0 and Trigger1 simultaneously.
 * In cooperation mode Trigger0 starts both ADCA and ADCB; Trigger1 is unused.
 * In independence mode Trigger0 starts ADCA and Trigger1 starts ADCB.
 */
typedef enum _dadc_software_trigger
{
    kDADC_SoftwareTrigger0 = DADC_SWTRIG_SWT0_MASK, /*!< Software Trigger0: ADCA (ADCA+ADCB in cooperation mode). */
    kDADC_SoftwareTrigger1 = DADC_SWTRIG_SWT1_MASK, /*!< Software Trigger1: ADCB (independence mode only). */
} dadc_software_trigger_t;

/*!
 * @brief DualADC conversion type selection (CMD[CTYPE]).
 */
typedef enum _dadc_conversion_type
{
    kDADC_ConversionSingleEndedA    = 0U, /*!< Single-ended, A-side channel only. */
    kDADC_ConversionSingleEndedB    = 1U, /*!< Single-ended, B-side channel only. */
    kDADC_ConversionDifferential    = 2U, /*!< Differential mode (A minus B). */
    kDADC_ConversionDualSingleEnded = 3U, /*!< Dual single-ended: A and B sides converted independently. */
} dadc_conversion_type_t;

/*!
 * @brief DualADC conversion resolution selection (CMD[MODE]).
 */
typedef enum _dadc_resolution
{
    kDADC_ResolutionStandard = 0U, /*!< Standard: 12-bit single-ended or 13-bit differential. */
    kDADC_ResolutionHigh     = 1U, /*!< High: 16-bit single-ended or differential. */
} dadc_resolution_t;

/*!
 * @brief DualADC sample time selection in ADCK cycles (CMD[STS]).
 */
typedef enum _dadc_sample_time
{
    kDADC_SampleTime3_5   = 0U, /*!< 3.5 ADCK cycles (minimum sample time). */
    kDADC_SampleTime5_5   = 1U, /*!< 5.5 ADCK cycles. */
    kDADC_SampleTime7_5   = 2U, /*!< 7.5 ADCK cycles. */
    kDADC_SampleTime11_5  = 3U, /*!< 11.5 ADCK cycles. */
    kDADC_SampleTime19_5  = 4U, /*!< 19.5 ADCK cycles. */
    kDADC_SampleTime35_5  = 5U, /*!< 35.5 ADCK cycles. */
    kDADC_SampleTime67_5  = 6U, /*!< 67.5 ADCK cycles. */
    kDADC_SampleTime131_5 = 7U, /*!< 131.5 ADCK cycles (maximum sample time). */
} dadc_sample_time_t;

/*!
 * @brief DualADC hardware averaging count for conversions (CMD[AVGS]).
 */
typedef enum _dadc_hardware_averages
{
    kDADC_HardwareAverageSingle = 0U,  /*!< Single conversion, no averaging. */
    kDADC_HardwareAverage2      = 1U,  /*!< 2 conversions averaged. */
    kDADC_HardwareAverage4      = 2U,  /*!< 4 conversions averaged. */
    kDADC_HardwareAverage8      = 3U,  /*!< 8 conversions averaged. */
    kDADC_HardwareAverage16     = 4U,  /*!< 16 conversions averaged. */
    kDADC_HardwareAverage32     = 5U,  /*!< 32 conversions averaged. */
    kDADC_HardwareAverage64     = 6U,  /*!< 64 conversions averaged. */
    kDADC_HardwareAverage128    = 7U,  /*!< 128 conversions averaged. */
    kDADC_HardwareAverage256    = 8U,  /*!< 256 conversions averaged. */
    kDADC_HardwareAverage512    = 9U,  /*!< 512 conversions averaged. */
    kDADC_HardwareAverage1024   = 10U, /*!< 1024 conversions averaged. */
} dadc_hardware_averages_t;

/*!
 * @brief DualADC interrupt source selection mask for the IE register.
 *
 * Values may be OR'd together. ADCB interrupt sources are only generated
 * in independence mode (CFG0[INDEP]=1).
 */
typedef enum _dadc_interrupt
{
    kDADC_InterruptEndOfScanA       = DADC_IE_EOSIEA_MASK,         /*!< End of scan sequence for ADCA. */
    kDADC_InterruptOverlapA         = DADC_IE_OVERLAPIEA_MASK,     /*!< Trigger overlap interrupt for ADCA. */
    kDADC_InterruptIntervalTimeErrA = DADC_IE_INTVTIMEERRIEA_MASK, /*!< Average-with-timer interval error for ADCA. */
    kDADC_InterruptEndOfScanB       = DADC_IE_EOSIEB_MASK,         /*!< End of scan sequence for ADCB. */
    kDADC_InterruptOverlapB         = DADC_IE_OVERLAPIEB_MASK,     /*!< Trigger overlap interrupt for ADCB. */
    kDADC_InterruptIntervalTimeErrB = DADC_IE_INTVTIMEERRIEB_MASK, /*!< Average-with-timer interval error for ADCB. */
} dadc_interrupt_t;

/*!
 * @brief DualADC scan sequence completion status flag mask (STAT2[EOSI]).
 *
 * Used with @ref DUALADC_GetScanSequenceStatusFlags and @ref DUALADC_ClearScanSequenceStatusFlags.
 * Values may be OR'd together. kDADC_EndofScanBFlag is only generated in independence mode
 * (CFG0[INDEP]=1).
 */
typedef enum _dadc_scan_seq_status_flag
{
    kDADC_EndofScanAFlag = DADC_STAT2_EOSIA_MASK, /*!< ADCA scan sequence complete. */
    kDADC_EndofScanBFlag = DADC_STAT2_EOSIB_MASK, /*!< ADCB scan sequence complete. */
} dadc_scan_seq_status_flag_t;

/*!
 * @brief DualADC error status flag mask (STAT1).
 *
 * Used with @ref DUALADC_GetErrorStatusFlags and @ref DUALADC_ClearErrorStatusFlags.
 * Values may be OR'd together. ADCB flags are only generated in independence mode
 * (CFG0[INDEP]=1).
 */
typedef enum _dadc_error_status_flag
{
    kDADC_OverlapAFlag = DADC_STAT1_OVERLAP_FLAGA_MASK, /*!< ADCA Trigger overlap detected. */
    kDADC_OverlapBFlag = DADC_STAT1_OVERLAP_FLAGB_MASK, /*!< ADCB Trigger overlap detected. */
    kDADC_IntervalErrAFlag = DADC_STAT1_INTVTIMEERR_FLAGA_MASK, /*!< ADCA Average-with-timer interval too short. */
    kDADC_IntervalErrBFlag = DADC_STAT1_INTVTIMEERR_FLAGB_MASK, /*!< ADCB Average-with-timer interval too short. */
} dadc_error_status_flag_t;

/*!
 * @brief DualADC general read-only status flag mask (STAT0 and STAT2[STARTUPSTS]).
 *
 * Used with @ref DUALADC_GetStatusFlags. All flags are read-only and cannot be
 * cleared by software. Values may be OR'd together to test multiple flags at once.
 */
typedef enum _dadc_status_flag
{
    kDADC_AdcActiveAFlag       = DADC_STAT0_ADC_ACTIVEA_MASK, /*!< ADCA is actively converting. */
    kDADC_AdcActiveBFlag       = DADC_STAT0_ADC_ACTIVEB_MASK, /*!< ADCB is actively converting. */
    kDADC_CalibrationReadyFlag = DADC_STAT0_CAL_RDY_MASK, /*!< Calibration complete. */

    kDADC_StartupDoneAFlag = DADC_STAT2_STARTUPSTSA_MASK, /*!< ADCA analog startup complete. */
    kDADC_StartupDoneBFlag = DADC_STAT2_STARTUPSTSB_MASK, /*!< ADCB analog startup complete. */
} dadc_status_flag_t;

/*!
 * @brief DualADC command buffer bitmask values for RSLTRDY_IE and CMP_IE registers.
 *
 * Values may be OR'd together to address multiple command buffers simultaneously.
 */
typedef enum _dadc_cmd_mask
{
    kDADC_Cmd1Mask  = (1U << 0U),  /*!< Command buffer 1. */
    kDADC_Cmd2Mask  = (1U << 1U),  /*!< Command buffer 2. */
    kDADC_Cmd3Mask  = (1U << 2U),  /*!< Command buffer 3. */
    kDADC_Cmd4Mask  = (1U << 3U),  /*!< Command buffer 4. */
    kDADC_Cmd5Mask  = (1U << 4U),  /*!< Command buffer 5. */
    kDADC_Cmd6Mask  = (1U << 5U),  /*!< Command buffer 6. */
    kDADC_Cmd7Mask  = (1U << 6U),  /*!< Command buffer 7. */
    kDADC_Cmd8Mask  = (1U << 7U),  /*!< Command buffer 8. */
    kDADC_Cmd9Mask  = (1U << 8U),  /*!< Command buffer 9. */
    kDADC_Cmd10Mask = (1U << 9U),  /*!< Command buffer 10. */
    kDADC_Cmd11Mask = (1U << 10U), /*!< Command buffer 11. */
    kDADC_Cmd12Mask = (1U << 11U), /*!< Command buffer 12. */
    kDADC_Cmd13Mask = (1U << 12U), /*!< Command buffer 13. */
    kDADC_Cmd14Mask = (1U << 13U), /*!< Command buffer 14. */
    kDADC_Cmd15Mask = (1U << 14U), /*!< Command buffer 15. */
    kDADC_Cmd16Mask = (1U << 15U), /*!< Command buffer 16. */
    kDADC_Cmd17Mask = (1U << 16U), /*!< Command buffer 17. */
    kDADC_Cmd18Mask = (1U << 17U), /*!< Command buffer 18. */
    kDADC_Cmd19Mask = (1U << 18U), /*!< Command buffer 19. */
    kDADC_Cmd20Mask = (1U << 19U), /*!< Command buffer 20. */
} dadc_cmd_mask_t;

/*!
 * @brief DualADC conversion command configuration structure.
 *
 * Configure each command buffer entry and pass to @ref DUALADC_ConfigConversionCommand.
 * Use @ref DUALADC_GetDefaultConvCmdConfig for safe defaults.
 *
 * @note CMD[CDIS] (sequence terminator) is not included here; use the dedicated
 *       @ref DUALADC_SetConvSequenceEndCommand inline function instead.
 */
typedef struct _dadc_cmd_config
{
    dadc_conversion_type_t conversionType;  /*!< Conversion type (A-side/B-side/differential/dual). */
    dadc_resolution_t resolutionMode;   /*!< Conversion resolution (standard or high). */
    dadc_sample_time_t sampleTimeMode;  /*!< Input sample time in ADCK cycles. */
    dadc_hardware_averages_t hardwareAverages; /*!< Number of conversions averaged per result. */

    uint8_t channelNumber;      /*!< A-side input channel select (0-31). */
    bool enableAltBChannel;     /*!< Use altBChannelNumber for B-side instead of channelNumber. */
    uint8_t altBChannelNumber;  /*!< B-side channel select when enableAltBChannel is true (0-31). */

    bool enableCompare;         /*!< Enable hardware compare for this command. */
    uint16_t compareValueHigh;  /*!< Compare value high (CVH); written to CV[n] when enableCompare is true. */
    uint16_t compareValueLow;   /*!< Compare value low (CVL); written to CV[n] when enableCompare is true. */

    bool enableWaitTrigger; /*!< Require trigger re-assertion before this command executes. */
} dadc_cmd_config_t;

/*!
 * @brief DualADC initialization configuration structure.
 *
 * Pass a populated instance of this structure to @ref DUALADC_Init.
 * Use @ref DUALADC_GetDefaultConfig to obtain safe reset-state defaults before
 * modifying individual fields.
 *
 * @note CTRL[ADCEN] is always asserted at the end of @ref DUALADC_Init and must
 *       not be set by the caller beforehand.
 * @note Calibration request bits (CTRL[CAL_REQ], CTRL[CALOFS], CTRL[CALHS]) are excluded
 *       from this structure and must be triggered through @ref DUALADC_DoCalibration.
 */
typedef struct _dadc_config
{
    /* CFG0 - Configuration 0 Register */
    dadc_conversion_mode_t conversionMode;      /*!< ADCA/ADCB conversion mode (cooperation or independence). */
    dadc_power_config_t powerConfig;            /*!< Power and maximum ADCK frequency. */
    bool enableAnalogPreEnable;                 /*!< Pre-enable analog circuits for faster conversion startup. */
    dadc_ref_voltage_src_t refVoltageSource;    /*!< Voltage reference source. */
    uint8_t powerUpDelayCount;                  /*!< Power-up delay count; must exceed device tADCSTUP. */
    dadc_trig_sel_t triggerSource;              /*!< Trigger source for ADCA (CFG0[TRIGSEL]). */

    /* CFG1 - Configuration 1 Register */
    bool enableLeftJustify;         /*!< Left-justify the 12-bit result in the result register. */
    bool enableHighSpeedMode;       /*!< Enable high-speed conversion mode. */
    bool enableHighSpeedExtra;      /*!< Add one extra conversion cycle in high-speed mode. */
    dadc_tune_mode_t tuneMode;      /*!< Tune mode; see device reference manual. */

    /* CTRL - Control Register */
    bool enableDoze;                        /*!< ADC finishes current scan then goes inactive on doze entry. */
    bool enableLongCalSampleTime;           /*!< Use long (67.5 ADCK) sample time during calibration. */
    dadc_calibration_averages_t calibrationAverages;    /*!< Conversion averages during calibration routines. */

    /* PAUSE - Pause Register */
    bool enableConversionPause;     /*!< Insert a delay between consecutive conversions in a sequence. */
    uint16_t conversionPauseDelay;  /*!< Pause delay count (0-511); delay = conversionPauseDelay * 4 ADCK cycles. */

    /* TCTRL - Trigger Control Register */
    bool enableHardwareTrigger0;    /*!< Enable hardware Trigger0 for ADCA (or both in cooperation mode). */
    bool enableHardwareTrigger1;    /*!< Enable hardware Trigger1 for ADCB (independence mode only). */
    uint8_t hardwareTrigger0Delay;  /*!< Trigger0 delay select (0-15, raw count);
                                        delay time 2^hardwareTrigger0Delay ADCK cycles. */
    uint8_t hardwareTrigger1Delay;  /*!< Trigger1 delay select (0-15, raw count);
                                        delay time 2^hardwareTrigger1Delay ADCK cycles. */

    /* DE - DMA trigger source */
    dadc_dma_src_t dmaSourceA; /*!< DMA trigger source for ADCA. */
    dadc_dma_src_t dmaSourceB; /*!< DMA trigger source for ADCB (independence mode only). */
} dadc_config_t;

/*!
 * @brief DualADC average-with-timer interval prescaler (ITCFG[PRESCALERA/B]).
 *
 * Interval = ITCFG[INTERVAL] * ADCK_period * 2^prescaler
 */
typedef enum _dadc_avgt_prescaler
{
    kDADC_AvgtPrescaler1   = 0U, /*!< Prescaled by 1. */
    kDADC_AvgtPrescaler2   = 1U, /*!< Prescaled by 2. */
    kDADC_AvgtPrescaler4   = 2U, /*!< Prescaled by 4. */
    kDADC_AvgtPrescaler8   = 3U, /*!< Prescaled by 8. */
    kDADC_AvgtPrescaler16  = 4U, /*!< Prescaled by 16. */
    kDADC_AvgtPrescaler32  = 5U, /*!< Prescaled by 32. */
    kDADC_AvgtPrescaler64  = 6U, /*!< Prescaled by 64. */
    kDADC_AvgtPrescaler128 = 7U, /*!< Prescaled by 128. */
} dadc_avgt_prescaler_t;

/*!
 * @brief DualADC average-with-timer configuration structure.
 *
 * The average-with-timer feature repeats a conversion sequence automatically at a
 * configurable interval. Pass to @ref DUALADC_ConfigAvgTimer.
 * Use @ref DUALADC_GetDefaultAvgTimerConfig for safe defaults.
 *
 * In cooperation mode only the ADCA fields (A suffix) take effect; ADCB follows ADCA
 * and the ADCB fields are ignored by hardware.
 * In independence mode both sets of fields are independent.
 *
 * Interval formula: Interval = interval * ADCK_period * 2^prescaler
 */
typedef struct _dadc_avgt_config
{
    /* ADCA - valid in both cooperation and independence modes */
    bool enableAvgTimerA;       /*!< Enable average-with-timer for ADCA. */
    uint16_t repeatCountA;      /*!< Sequence repeat count for ADCA (1-512); stored as AVGTA_TIMES+1. */
    uint16_t intervalA;         /*!< ADCA timer interval raw count (ITCFG[INTERVALA]). */
    dadc_avgt_prescaler_t prescalerA;   /*!< ADCA interval timer prescaler. */

    /* ADCB - valid in independence mode only; ignored by hardware in cooperation mode */
    bool enableAvgTimerB;       /*!< Enable average-with-timer for ADCB (independence mode only). */
    uint16_t repeatCountB;      /*!< Sequence repeat count for ADCB (1-512, independence mode only). */
    uint16_t intervalB;         /*!< ADCB timer interval raw count (ITCFG[INTERVALB], independence mode only). */
    dadc_avgt_prescaler_t prescalerB;   /*!< ADCB interval timer prescaler (independence mode only). */
} dadc_avgt_config_t;

/*!
 * @brief DualADC calibration value structure.
 */
typedef struct _dadc_calibration_value
{
    uint16_t offsetTrimA;       /*!< OFSTRIM[OFSTRIMA]: ADCA offset trim (10-bit). */
    uint16_t offsetTrimB;       /*!< OFSTRIM[OFSTRIMB]: ADCB offset trim (10-bit). */
    uint16_t highSpeedTrimA;    /*!< HSTRIM[HSTRIMA]: ADCA high-speed trim (5-bit). */
    uint16_t highSpeedTrimB;    /*!< HSTRIM[HSTRIMB]: ADCB high-speed trim (5-bit). */
    uint32_t gcalr[DADC_GCR_COUNT];         /*!< GCR[n].GCALR: 17-bit gain calibration result (RDY bit excluded). */
    uint16_t calGar[DADC_CAL_GAR_COUNT];    /*!< CAL_GAR[0..32]: linearity calibration values for ADCA. */
    uint16_t calGbr[DADC_CAL_GBR_COUNT];    /*!< CAL_GBR[0..32]: linearity calibration values for ADCB. */
} dadc_calibration_value_t;

/*!
 * @brief DualADC conversion result structure.
 *
 * All three members are derived from a single RSLT register read. Use the member
 * that matches the conversion configuration.
 *
 * @note The raw values are not final ADC codes. In standard 12-bit mode (CMD[MODE]=0) the ADC
 *       code does not start at bit 0:
 *       - CFG1[JLEFT]=0: 12-bit code at bit[14:3]; right-shift by 3 to obtain the value.
 *       - CFG1[JLEFT]=1: 12-bit code at bit[15:4]; right-shift by 4 to obtain the value.
 *       In high-resolution 16-bit mode (CMD[MODE]=1) the result fills bit[15:0] and no shift
 *       is needed.
 *       When average-with-timer is enabled result32 holds the sum of raw register values;
 *       apply the same right-shift before dividing by the repeat count.
 */
typedef struct _dadc_conversion_result
{
    uint16_t resultLow;  /*!< bit[15:0]: single-ended or differential result;
                              A-side result in dual single-ended mode. */
    uint16_t resultHigh; /*!< bit[31:16]: B-side result in dual single-ended mode (CTYPE=3). */
    uint32_t result32;   /*!< bit[31:0]: full 32-bit summed result when average-with-timer is enabled. */
} dadc_conversion_result_t;

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
 * @brief Get the instance for DualADC module.
 *
 * @param base DualADC base address
 * @return Instance number if valid base address is provided, otherwise returns 0xFFFFFFFF
 */
uint32_t DUALADC_GetInstance(DADC_Type *base);

/*!
 * @brief Populate a @ref dadc_config_t with reset-state defaults.
 *
 * Defaults applied:
 * - Cooperation mode
 * - Low power (max 24 MHz ADCK)
 * - Analog pre-enable disabled
 * - VREFH0x reference voltage
 * - Power-up delay count: 0x80 (adjust per device tADCSTUP specification)
 * - Right-justified result
 * - High-speed mode disabled
 * - Tune mode 1
 * - Doze: ADC continues converting through system low-power entry (DOZEN = 0)
 * - Normal calibration sample time (3.5 ADCK cycles)
 * - 256-average calibration (RM recommended minimum)
 *
 * @param config Pointer to the configuration structure to populate. Must not be NULL.
 */
void DUALADC_GetDefaultConfig(dadc_config_t *config);

/*!
 * @brief Initialize the DualADC module.
 *
 * Initialization sequence:
 * 1. Enable the peripheral clock.
 * 2. Release the peripheral reset (if supported by the platform).
 * 3. Assert then release software reset for ADCA and ADCB (CTRL[RSTA]/CTRL[RSTB]).
 * 4. Configure CFG0 via read-modify-write.
 * 5. Configure CFG1 via read-modify-write.
 * 6. Configure CTRL fields (DOZEN, CST_LONG, CAL_AVGS) via read-modify-write.
 *
 * On return the ADC is enabled and ready for calibration or conversion.
 *
 * @param base   DualADC peripheral base address.
 * @param config Pointer to the initialization configuration. Must not be NULL.
 * @retval kStatus_Success           Initialization succeeded.
 * @retval kStatus_InvalidArgument   @p base is not a valid DualADC peripheral address.
 * @retval kStatus_Timeout           Reset operation times out.
 */
status_t DUALADC_Init(DADC_Type *base, const dadc_config_t *config);

/*!
 * @brief Deinitialize the DualADC module.
 *
 * Clears CTRL[ADCEN] to terminate any active conversion, gates the peripheral
 * clock, and asserts the peripheral reset (if supported by the platform).
 *
 * @param base DualADC peripheral base address.
 * @retval kStatus_Success           Deinitialization succeeded.
 * @retval kStatus_InvalidArgument   @p base is not a valid DualADC peripheral address.
 */
status_t DUALADC_DeInit(DADC_Type *base);

/*! @} */

/*!
 * @name Calibration
 * @{
 */

/*!
 * @brief Perform all DualADC calibration routines.
 *
 * Executes in order:
 * 1. Offset calibration (CTRL[CALOFS]) - updates OFSTRIM.
 * 2. High-speed calibration (CTRL[CALHS]) - only when CFG1[HS] is set; updates HSTRIM.
 * 3. Gain and linearity calibration (CTRL[CAL_REQ]) - polls GCC[0/1].RDY, computes
 *    the 17-bit fixed-point gain result, writes GCR[0/1], and waits for STAT0[CAL_RDY].
 *
 * Must be called after @ref DUALADC_Enable to ensure ADC enabled.
 * CTRL[CAL_AVGS] (set in @ref DUALADC_Init) applies to all three calibration steps.
 *
 * @param base DualADC peripheral base address.
 * @retval kStatus_Success  All calibration steps completed successfully.
 * @retval kStatus_Timeout  A calibration poll loop exceeded @ref DUALADC_CALIBRATION_TIMEOUT
 *                          iterations (only possible when the timeout is non-zero).
 */
status_t DUALADC_DoCalibration(DADC_Type *base);

/*!
 * @brief Restore calibration registers from a previously saved @ref dadc_calibration_value_t.
 *
 * Writes OFSTRIM, HSTRIM, CAL_GAR[0..32], CAL_GBR[0..32], GCR[0], and GCR[1] from the
 * supplied structure. GCR[n].RDY is set automatically so the hardware uses the restored values.
 * CTRL[ADCEN] is cleared before writing and restored afterwards. No CAL_RDY polling is performed.
 *
 * @param base DualADC peripheral base address.
 * @param ptrCalibrationValue Pointer to the calibration value structure to restore. Must not be NULL.
 */
void DUALADC_SetCalibrationValue(DADC_Type *base, const dadc_calibration_value_t *ptrCalibrationValue);

/*! @} */

/*!
 * @name Configuration
 * @{
 */

/*!
 * @brief Populate a @ref dadc_cmd_config_t with reset-state defaults.
 *
 * Defaults applied:
 * - Single-ended A-side conversion
 * - Standard resolution (12-bit)
 * - Minimum sample time (3.5 ADCK)
 * - No hardware averaging
 * - Channel 0, no alternate B-channel
 * - Compare disabled, wait-trigger disabled
 *
 * @param config Pointer to the command configuration structure. Must not be NULL.
 */
void DUALADC_GetDefaultConversionCommandConfig(dadc_cmd_config_t *config);

/*!
 * @brief Configure a DualADC conversion command buffer entry.
 *
 * CMD[CDIS] is not touched; use @ref DUALADC_SetConversionSequenceEndCommand
 * to set the sequence terminator separately.
 *
 * @param base DualADC peripheral base address.
 * @param index Command buffer index, range 1-20 (maps to CMD[0]-CMD[19]).
 * @param config Pointer to the command configuration.
 */
void DUALADC_ConfigConversionCommand(DADC_Type *base, uint32_t index, const dadc_cmd_config_t *config);

/*!
 * @brief Mark a command buffer entry as the conversion sequence terminator.
 *
 * Sets CMD[CDIS] for @p index. The conversion sequence ends after the
 * previous command is executed; @p index itself is not executed.
 * If CMD1 is marked as the sequence end, the sequence will not start.
 *
 * @param base DualADC peripheral base address.
 * @param index Command buffer index, range 1-20.
 */
static inline void DUALADC_SetConversionSequenceEndCommand(DADC_Type *base, uint32_t index)
{
    assert(index >= 1U && index <= DADC_CMD_COUNT);
    base->CMD[index - 1U] |= DADC_CMD_CDIS_MASK;
}

/*!
 * @brief Populate a @ref dadc_avgt_config_t with reset-state defaults.
 *
 * Defaults: average-with-timer disabled for both ADCA and ADCB; repeat count 1;
 * interval 0; prescaler *1.
 *
 * @param config Pointer to the configuration structure to populate. Must not be NULL.
 */
void DUALADC_GetDefaultAverageTimerConfig(dadc_avgt_config_t *config);

/*!
 * @brief Configure the average-with-timer feature.
 *
 * Writes AVGT_CTRL and ITCFG registers via read-modify-write.
 * In cooperation mode the ADCB fields in @p config are written to hardware but ignored;
 * in independence mode both sets are independent.
 *
 * @param base   DualADC peripheral base address.
 * @param config Pointer to the average-with-timer configuration. Must not be NULL.
 */
void DUALADC_ConfigAverageTimer(DADC_Type *base, const dadc_avgt_config_t *config);

/*! @} */

/*!
 * @name Dynamic Update
 * @{
 */

/*!
 * @brief Enable the DualADC module.
 *
 * Call this after @ref DUALADC_Init when the application is ready to start the ADC.
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_Enable(DADC_Type *base)
{
    base->CTRL |= DADC_CTRL_ADCEN_MASK;
}

/*!
 * @brief Disable the DualADC module.
 *
 * The peripheral clock and configuration registers are preserved; call
 * @ref DUALADC_Enable to restart the ADC without re-initializing.
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_Disable(DADC_Type *base)
{
    base->CTRL &= MCUX_MASK_INVERT_32(DADC_CTRL_ADCEN_MASK);
}

/*!
 * @brief Read the conversion result for a command buffer entry.
 *
 * Reads RSLT[index-1] once and populates all three members of @p result.
 * Reading the result register automatically clears the corresponding
 * RSLTRDY_STAT bit.
 *
 * @param base   DualADC peripheral base address.
 * @param index  Command buffer index, range 1-20.
 * @param result Pointer to the result structure to populate. Must not be NULL.
 */
static inline void DUALADC_GetConversionResult(DADC_Type *base, uint32_t index, dadc_conversion_result_t *result)
{
    assert(NULL != result);
    assert(index >= 1U && index <= DADC_RSLT_COUNT);

    uint32_t raw = base->RSLT[index - 1U];
    result->result32   = raw;
    result->resultLow  = (uint16_t)(raw & 0xFFFFUL);
    result->resultHigh = (uint16_t)((raw >> 16U) & 0xFFFFUL);
}

/*!
 * @brief Assert one or both software triggers.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_software_trigger_t values.
 */
static inline void DUALADC_SetSoftwareTrigger(DADC_Type *base, uint32_t mask)
{
    base->SWTRIG = mask;
}

/*!
 * @brief Enable the DMA request for ADCA.
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_EnableDmaA(DADC_Type *base)
{
    base->DE |= DADC_DE_DMAENAA_MASK;
}

/*!
 * @brief Disable the DMA request for ADCA.
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_DisableDmaA(DADC_Type *base)
{
    base->DE &= MCUX_MASK_INVERT_32(DADC_DE_DMAENAA_MASK);
}

/*!
 * @brief Enable the DMA request for ADCB (independence mode only).
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_EnableDmaB(DADC_Type *base)
{
    base->DE |= DADC_DE_DMAENAB_MASK;
}

/*!
 * @brief Disable the DMA request for ADCB.
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_DisableDmaB(DADC_Type *base)
{
    base->DE &= MCUX_MASK_INVERT_32(DADC_DE_DMAENAB_MASK);
}

/*!
 * @brief Assert the software reset for ADCA (CTRL[RSTA]).
 *
 * @note CTRL[RSTA] is NOT self-clearing. After asserting reset, the logic high level
 *       must be held for more than 2 ADC functional clock cycles before invoking
 *       @ref DUALADC_ReleaseResetADCA to release it explicitly.
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_ResetADCA(DADC_Type *base)
{
    base->CTRL |= DADC_CTRL_RSTA_MASK;
}

/*!
 * @brief Release the software reset for ADCA by clearing CTRL[RSTA].
 *
 * @note Must be called after the reset has been held for more than 2 ADC functional
 *       clock cycles, see @ref DUALADC_ResetADCA.
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_ReleaseResetADCA(DADC_Type *base)
{
    base->CTRL &= MCUX_MASK_INVERT_32(DADC_CTRL_RSTA_MASK);
}

/*!
 * @brief Assert the software reset for ADCB (CTRL[RSTB]).
 *
 * @note CTRL[RSTB] is NOT self-clearing. After asserting reset, the logic high level
 *       must be held for more than 2 ADC functional clock cycles before invoking
 *       @ref DUALADC_ReleaseResetADCB to release it explicitly.
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_ResetADCB(DADC_Type *base)
{
    base->CTRL |= DADC_CTRL_RSTB_MASK;
}

/*!
 * @brief Release the software reset for ADCB by clearing CTRL[RSTB].
 *
 * @note Must be called after the reset has been held for more than 2 ADC functional
 *       clock cycles, see @ref DUALADC_ResetADCB.
 *
 * @param base DualADC peripheral base address.
 */
static inline void DUALADC_ReleaseResetADCB(DADC_Type *base)
{
    base->CTRL &= MCUX_MASK_INVERT_32(DADC_CTRL_RSTB_MASK);
}

/*! @} */

/*!
 * @name Interrupt and Status
 * @{
 */

/*!
 * @brief Enable DualADC interrupts in the IE register.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_interrupt_t values.
 */
static inline void DUALADC_EnableInterrupts(DADC_Type *base, uint32_t mask)
{
    base->IE |= mask;
}

/*!
 * @brief Disable DualADC interrupts in the IE register.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_interrupt_t values.
 */
static inline void DUALADC_DisableInterrupts(DADC_Type *base, uint32_t mask)
{
    base->IE &= MCUX_MASK_INVERT_32(mask);
}

/*!
 * @brief Enable result-ready interrupts for one or more command buffers.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_cmd_mask_t values.
 */
static inline void DUALADC_EnableResultReadyInterrupts(DADC_Type *base, uint32_t mask)
{
    base->RSLTRDY_IE |= mask;
}

/*!
 * @brief Disable result-ready interrupts for one or more command buffers.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_cmd_mask_t values.
 */
static inline void DUALADC_DisableResultReadyInterrupts(DADC_Type *base, uint32_t mask)
{
    base->RSLTRDY_IE &= MCUX_MASK_INVERT_32(mask);
}

/*!
 * @brief Enable compare interrupts for one or more command buffers.
 *
 * The compare interrupt fires when a command's conversion result satisfies the
 * compare condition (CMD[CMPEN] must also be set for that command buffer).
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_cmd_mask_t values.
 */
static inline void DUALADC_EnableCompareInterrupts(DADC_Type *base, uint32_t mask)
{
    base->CMP_IE |= mask;
}

/*!
 * @brief Disable compare interrupts for one or more command buffers.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_cmd_mask_t values.
 */
static inline void DUALADC_DisableCompareInterrupts(DADC_Type *base, uint32_t mask)
{
    base->CMP_IE &= MCUX_MASK_INVERT_32(mask);
}

/*!
 * @brief Get scan sequence completion status flags for ADCA and ADCB (STAT2[EOSI]).
 *
 * Returns the OR-combination of STAT2[EOSIA] and STAT2[EOSIB].
 * Test the return value against @ref kDADC_EndofScanAFlag and @ref kDADC_EndofScanBFlag.
 *
 * @param base DualADC peripheral base address.
 * @return OR combination of asserted end-of-scan flag bits from @ref dadc_scan_seq_status_flag_t.
 */
static inline uint32_t DUALADC_GetScanSequenceStatusFlags(DADC_Type *base)
{
    return base->STAT2 & (DADC_STAT2_EOSIA_MASK | DADC_STAT2_EOSIB_MASK);
}

/*!
 * @brief Clear scan sequence completion status flags for ADCA and ADCB (STAT2[EOSI]).
 *
 * Writes 1 to the selected STAT2[EOSIA/B] bits to clear them.
 * Bits not present in @p mask are not affected.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref kDADC_EndofScanAFlag and/or @ref kDADC_EndofScanBFlag.
 */
static inline void DUALADC_ClearScanSequenceStatusFlags(DADC_Type *base, uint32_t mask)
{
    base->STAT2 = mask & (DADC_STAT2_EOSIA_MASK | DADC_STAT2_EOSIB_MASK);
}

/*!
 * @brief Get error status flags for ADCA and ADCB (STAT1).
 *
 * Returns the OR-combination of STAT1[INTVTIMEERR_FLAGA/B] and STAT1[OVERLAP_FLAGA/B].
 * Test the return value against @ref kDADC_OverlapAFlag, @ref kDADC_OverlapBFlag,
 * @ref kDADC_IntervalErrAFlag, and @ref kDADC_IntervalErrBFlag.
 *
 * @param base DualADC peripheral base address.
 * @return OR combination of asserted error flag bits from @ref dadc_error_status_flag_t.
 */
static inline uint32_t DUALADC_GetErrorStatusFlags(DADC_Type *base)
{
    return base->STAT1 & (DADC_STAT1_INTVTIMEERR_FLAGA_MASK | DADC_STAT1_OVERLAP_FLAGA_MASK |
                          DADC_STAT1_INTVTIMEERR_FLAGB_MASK  | DADC_STAT1_OVERLAP_FLAGB_MASK);
}

/*!
 * @brief Clear error status flags for ADCA and ADCB (STAT1).
 *
 * Writes 1 to the selected STAT1[INTVTIMEERR_FLAG] and STAT1[OVERLAP_FLAG] bits to clear them.
 * Bits not present in @p mask are not affected.
 *
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_error_status_flag_t values.
 */
static inline void DUALADC_ClearErrorStatusFlags(DADC_Type *base, uint32_t mask)
{
    base->STAT1 = mask & (DADC_STAT1_INTVTIMEERR_FLAGA_MASK | DADC_STAT1_OVERLAP_FLAGA_MASK |
                          DADC_STAT1_INTVTIMEERR_FLAGB_MASK  | DADC_STAT1_OVERLAP_FLAGB_MASK);
}

/*!
 * @brief Get general read-only status flags for ADCA and ADCB (STAT0 and STAT2[STARTUPSTS]).
 *
 * Returns the OR-combination of:
 *   - STAT0[ADC_ACTIVEA], STAT0[ADC_ACTIVEB]  - conversion in progress indicators
 *   - STAT0[CAL_RDY]                          - calibration complete
 *   - STAT2[STARTUPSTSA], STAT2[STARTUPSTSB]  - analog startup complete
 *
 * All flags are read-only; none can be cleared by software.
 * Test the return value against @ref kDADC_AdcActiveAFlag, @ref kDADC_AdcActiveBFlag,
 * @ref kDADC_CalibrationReadyFlag, @ref kDADC_StartupDoneAFlag, and @ref kDADC_StartupDoneBFlag.
 *
 * @param base DualADC peripheral base address.
 * @return OR combination of asserted general status flag bits from @ref dadc_status_flag_t.
 */
static inline uint32_t DUALADC_GetStatusFlags(DADC_Type *base)
{
    /* STAT0: ADC_ACTIVEA, ADC_ACTIVEB, and CAL_RDY at natural bit positions. */
    uint32_t reg = base->STAT0 & (DADC_STAT0_ADC_ACTIVEA_MASK | DADC_STAT0_ADC_ACTIVEB_MASK |
                                  DADC_STAT0_CAL_RDY_MASK);

    /* STAT2: STARTUPSTSA and STARTUPSTSB at natural bit positions. */
    reg |= base->STAT2 & (DADC_STAT2_STARTUPSTSA_MASK | DADC_STAT2_STARTUPSTSB_MASK);

    return reg;
}

/*!
 * @brief Get the command buffer index currently executing in ADCA (0 = idle).
 * @param base DualADC peripheral base address.
 * @return Active command index for ADCA (0~20).
 */
static inline uint32_t DUALADC_GetActiveCommandA(DADC_Type *base)
{
    return (base->STAT0 & DADC_STAT0_CMDACTA_MASK) >> DADC_STAT0_CMDACTA_SHIFT;
}

/*!
 * @brief Get the command buffer index currently executing in ADCB (0 = idle).
 * @param base DualADC peripheral base address.
 * @return Active command index for ADCB (0~20).
 */
static inline uint32_t DUALADC_GetActiveCommandB(DADC_Type *base)
{
    return (base->STAT0 & DADC_STAT0_CMDACTB_MASK) >> DADC_STAT0_CMDACTB_SHIFT;
}

/*!
 * @brief Get the average-with-timer remaining repeat count for ADCA.
 * @param base DualADC peripheral base address.
 * @return Remaining sequence repeat count for ADCA.
 */
static inline uint32_t DUALADC_GetAvgTimerStatusA(DADC_Type *base)
{
    return (base->STAT0 & DADC_STAT0_AVGTSTSA_MASK) >> DADC_STAT0_AVGTSTSA_SHIFT;
}

/*!
 * @brief Get the average-with-timer remaining repeat count for ADCB.
 * @param base DualADC peripheral base address.
 * @return Remaining sequence repeat count for ADCB.
 */
static inline uint32_t DUALADC_GetAvgTimerStatusB(DADC_Type *base)
{
    return (base->STAT0 & DADC_STAT0_AVGTSTSB_MASK) >> DADC_STAT0_AVGTSTSB_SHIFT;
}

/*!
 * @brief Get the command index that was executing when a trigger overlap occurred for ADCA.
 * @note Valid only when @ref kDADC_OverlapAFlag is asserted.
 * @param base DualADC peripheral base address.
 * @return Command index that was active during the overlap event (1~20).
 */
static inline uint32_t DUALADC_GetOverlapCommandA(DADC_Type *base)
{
    return (base->STAT1 & DADC_STAT1_OVERLAP_CMDA_MASK) >> DADC_STAT1_OVERLAP_CMDA_SHIFT;
}

/*!
 * @brief Get the command index that was executing when a trigger overlap occurred for ADCB.
 * @note Valid only when @ref kDADC_OverlapBFlag is asserted.
 * @param base DualADC peripheral base address.
 * @return Command index that was active during the overlap event (1~20).
 */
static inline uint32_t DUALADC_GetOverlapCommandB(DADC_Type *base)
{
    return (base->STAT1 & DADC_STAT1_OVERLAP_CMDB_MASK) >> DADC_STAT1_OVERLAP_CMDB_SHIFT;
}

/*!
 * @brief Get the command index executing when an interval timer error occurred for ADCA.
 * @note Valid only when @ref kDADC_IntervalErrAFlag is asserted.
 * @param base DualADC peripheral base address.
 * @return Command index that was active during the interval error (1~20).
 */
static inline uint32_t DUALADC_GetIntervalErrCommandA(DADC_Type *base)
{
    return (base->STAT1 & DADC_STAT1_INTVTIMEERR_CMDA_MASK) >> DADC_STAT1_INTVTIMEERR_CMDA_SHIFT;
}

/*!
 * @brief Get the command index executing when an interval timer error occurred for ADCB.
 * @note Valid only when @ref kDADC_IntervalErrBFlag is asserted.
 * @param base DualADC peripheral base address.
 * @return Command index that was active during the interval error (1~20).
 */
static inline uint32_t DUALADC_GetIntervalErrCommandB(DADC_Type *base)
{
    return (base->STAT1 & DADC_STAT1_INTVTIMEERR_CMDB_MASK) >> DADC_STAT1_INTVTIMEERR_CMDB_SHIFT;
}

/*!
 * @brief Get the compare status flags for all command buffers.
 * @param base DualADC peripheral base address.
 * @return Bitmask of compare results; use @ref dadc_cmd_mask_t to check individual commands.
 */
static inline uint32_t DUALADC_GetCompareStatusFlags(DADC_Type *base)
{
    return base->CMP_STAT;
}

/*!
 * @brief Clear compare status flags for one or more command buffers.
 * @param base DualADC peripheral base address.
 * @param mask OR combination of @ref dadc_cmd_mask_t values to clear.
 */
static inline void DUALADC_ClearCompareStatusFlags(DADC_Type *base, uint32_t mask)
{
    base->CMP_STAT = mask;
}

/*!
 * @brief Get the result-ready flags for all command buffers.
 *
 * Each bit indicates a conversion result is available in the corresponding RSLT register.
 * Flags clear automatically when the associated RSLT register is read by @ref DUALADC_GetConversionResult.
 *
 * @param base DualADC peripheral base address.
 * @return Bitmask of ready results; use @ref dadc_cmd_mask_t to check individual commands.
 */
static inline uint32_t DUALADC_GetResultReadyFlags(DADC_Type *base)
{
    return base->RSLTRDY_STAT;
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_DUAL_ADC_H_ */
