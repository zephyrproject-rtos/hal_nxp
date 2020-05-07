/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _FSL_TSI_V2_H_
#define _FSL_TSI_V2_H_

#include "fsl_common.h"

/*!
 * @addtogroup tsi_v2_driver
 * @{
 */


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief TSI driver version */
#define FSL_TSI_DRIVER_VERSION (MAKE_VERSION(2, 1, 2))
/*@}*/

/*! @brief TSI status flags macro collection */
#define ALL_FLAGS_MASK  (TSI_GENCS_EOSF_MASK   |\
                         TSI_GENCS_OUTRGF_MASK |\
                         TSI_GENCS_EXTERF_MASK  |\
                         TSI_GENCS_OVRF_MASK)


/*!
 * @brief TSI number of scan intervals for each electrode.
 *
 * These constants define the TSI number of consecutive scans in a TSI instance for each electrode.
 */
typedef enum _tsi_n_consecutive_scans
{
    kTSI_ConsecutiveScansNumber_1time = 0U,   /*!< Once per electrode */
    kTSI_ConsecutiveScansNumber_2time = 1U,   /*!< Twice per electrode */
    kTSI_ConsecutiveScansNumber_3time = 2U,   /*!< 3 times consecutive scan */
    kTSI_ConsecutiveScansNumber_4time = 3U,   /*!< 4 times consecutive scan */
    kTSI_ConsecutiveScansNumber_5time = 4U,   /*!< 5 times consecutive scan */
    kTSI_ConsecutiveScansNumber_6time = 5U,   /*!< 6 times consecutive scan */
    kTSI_ConsecutiveScansNumber_7time = 6U,   /*!< 7 times consecutive scan */
    kTSI_ConsecutiveScansNumber_8time = 7U,   /*!< 8 times consecutive scan */
    kTSI_ConsecutiveScansNumber_9time = 8U,   /*!< 9 times consecutive scan */
    kTSI_ConsecutiveScansNumber_10time = 9U,  /*!< 10 times consecutive scan */
    kTSI_ConsecutiveScansNumber_11time = 10U, /*!< 11 times consecutive scan */
    kTSI_ConsecutiveScansNumber_12time = 11U, /*!< 12 times consecutive scan */
    kTSI_ConsecutiveScansNumber_13time = 12U, /*!< 13 times consecutive scan */
    kTSI_ConsecutiveScansNumber_14time = 13U, /*!< 14 times consecutive scan */
    kTSI_ConsecutiveScansNumber_15time = 14U, /*!< 15 times consecutive scan */
    kTSI_ConsecutiveScansNumber_16time = 15U, /*!< 16 times consecutive scan */
    kTSI_ConsecutiveScansNumber_17time = 16U, /*!< 17 times consecutive scan */
    kTSI_ConsecutiveScansNumber_18time = 17U, /*!< 18 times consecutive scan */
    kTSI_ConsecutiveScansNumber_19time = 18U, /*!< 19 times consecutive scan */
    kTSI_ConsecutiveScansNumber_20time = 19U, /*!< 20 times consecutive scan */
    kTSI_ConsecutiveScansNumber_21time = 20U, /*!< 21 times consecutive scan */
    kTSI_ConsecutiveScansNumber_22time = 21U, /*!< 22 times consecutive scan */
    kTSI_ConsecutiveScansNumber_23time = 22U, /*!< 23 times consecutive scan */
    kTSI_ConsecutiveScansNumber_24time = 23U, /*!< 24 times consecutive scan */
    kTSI_ConsecutiveScansNumber_25time = 24U, /*!< 25 times consecutive scan */
    kTSI_ConsecutiveScansNumber_26time = 25U, /*!< 26 times consecutive scan */
    kTSI_ConsecutiveScansNumber_27time = 26U, /*!< 27 times consecutive scan */
    kTSI_ConsecutiveScansNumber_28time = 27U, /*!< 28 times consecutive scan */
    kTSI_ConsecutiveScansNumber_29time = 28U, /*!< 29 times consecutive scan */
    kTSI_ConsecutiveScansNumber_30time = 29U, /*!< 30 times consecutive scan */
    kTSI_ConsecutiveScansNumber_31time = 30U, /*!< 31 times consecutive scan */
    kTSI_ConsecutiveScansNumber_32time = 31U  /*!< 32 times consecutive scan */
} tsi_n_consecutive_scans_t;

/*!
 * @brief TSI electrode oscillator prescaler.
 *
 * These constants define the TSI electrode oscillator prescaler in a TSI instance.
 */
typedef enum _tsi_electrode_osc_prescaler
{
    kTSI_ElecOscPrescaler_1div = 0U,  /*!< Electrode oscillator frequency divided by 1 */
    kTSI_ElecOscPrescaler_2div = 1U,  /*!< Electrode oscillator frequency divided by 2 */
    kTSI_ElecOscPrescaler_4div = 2U,  /*!< Electrode oscillator frequency divided by 4 */
    kTSI_ElecOscPrescaler_8div = 3U,  /*!< Electrode oscillator frequency divided by 8 */
    kTSI_ElecOscPrescaler_16div = 4U, /*!< Electrode oscillator frequency divided by 16 */
    kTSI_ElecOscPrescaler_32div = 5U, /*!< Electrode oscillator frequency divided by 32 */
    kTSI_ElecOscPrescaler_64div = 6U, /*!< Electrode oscillator frequency divided by 64 */
    kTSI_ElecOscPrescaler_128div = 7U /*!< Electrode oscillator frequency divided by 128 */
} tsi_electrode_osc_prescaler_t;

/*!
 * @brief TSI low power mode clock source.
 */
typedef enum _tsi_low_power_clock_source
{
    kTSI_LowPowerClockSource_LPOCLK = 0U,   /*!< LPOCLK is selected */
    kTSI_LowPowerClockSource_VLPOSCCLK = 1U /*!< VLPOSCCLK is selected */
} tsi_low_power_clock_source_t;

/*!
 * @brief TSI low power scan intervals.
 *
 * These constants define the TSI low power scan intervals in a TSI instance.
 */
typedef enum _tsi_low_power_scan_interval
{
    kTSI_LowPowerInterval_1ms = 0U,    /*!< 1 ms scan interval */
    kTSI_LowPowerInterval_5ms = 1U,    /*!< 5 ms scan interval */
    kTSI_LowPowerInterval_10ms = 2U,   /*!< 10 ms scan interval */
    kTSI_LowPowerInterval_15ms = 3U,   /*!< 15 ms scan interval */
    kTSI_LowPowerInterval_20ms = 4U,   /*!< 20 ms scan interval */
    kTSI_LowPowerInterval_30ms = 5U,   /*!< 30 ms scan interval */
    kTSI_LowPowerInterval_40ms = 6U,   /*!< 40 ms scan interval */
    kTSI_LowPowerInterval_50ms = 7U,   /*!< 50 ms scan interval */
    kTSI_LowPowerInterval_75ms = 8U,   /*!< 75 ms scan interval */
    kTSI_LowPowerInterval_100ms = 9U,  /*!< 100 ms scan interval */
    kTSI_LowPowerInterval_125ms = 10U, /*!< 125 ms scan interval */
    kTSI_LowPowerInterval_150ms = 11U, /*!< 150 ms scan interval */
    kTSI_LowPowerInterval_200ms = 12U, /*!< 200 ms scan interval */
    kTSI_LowPowerInterval_300ms = 13U, /*!< 300 ms scan interval */
    kTSI_LowPowerInterval_400ms = 14U, /*!< 400 ms scan interval */
    kTSI_LowPowerInterval_500ms = 15U  /*!< 500 ms scan interval */
} tsi_low_power_scan_interval_t;

/*!
 * @brief TSI Reference oscillator charge current select.
 *
 * These constants define the TSI Reference oscillator charge current select in a TSI instance.
 */
typedef enum _tsi_reference_osc_charge_current
{
    kTSI_RefOscChargeCurrent_2uA = 0U,   /*!< Reference oscillator charge current is 2 µA */
    kTSI_RefOscChargeCurrent_4uA = 1U,   /*!< Reference oscillator charge current is 4 µA */
    kTSI_RefOscChargeCurrent_6uA = 2U,   /*!< Reference oscillator charge current is 6 µA */
    kTSI_RefOscChargeCurrent_8uA = 3U,   /*!< Reference oscillator charge current is 8 µA */
    kTSI_RefOscChargeCurrent_10uA = 4U,  /*!< Reference oscillator charge current is 10 µA */
    kTSI_RefOscChargeCurrent_12uA = 5U,  /*!< Reference oscillator charge current is 12 µA */
    kTSI_RefOscChargeCurrent_14uA = 6U,  /*!< Reference oscillator charge current is 14 µA */
    kTSI_RefOscChargeCurrent_16uA = 7U,  /*!< Reference oscillator charge current is 16 µA */
    kTSI_RefOscChargeCurrent_18uA = 8U,  /*!< Reference oscillator charge current is 18 µA */
    kTSI_RefOscChargeCurrent_20uA = 9U,  /*!< Reference oscillator charge current is 20 µA */
    kTSI_RefOscChargeCurrent_22uA = 10U, /*!< Reference oscillator charge current is 22 µA */
    kTSI_RefOscChargeCurrent_24uA = 11U, /*!< Reference oscillator charge current is 24 µA */
    kTSI_RefOscChargeCurrent_26uA = 12U, /*!< Reference oscillator charge current is 26 µA */
    kTSI_RefOscChargeCurrent_28uA = 13U, /*!< Reference oscillator charge current is 28 µA */
    kTSI_RefOscChargeCurrent_30uA = 14U, /*!< Reference oscillator charge current is 30 µA */
    kTSI_RefOscChargeCurrent_32uA = 15U  /*!< Reference oscillator charge current is 32 µA */
} tsi_reference_osc_charge_current_t;

/*!
 * @brief TSI External oscillator charge current select.
 *
 * These constants define the TSI External oscillator charge current select in a TSI instance.
 */
typedef enum _tsi_external_osc_charge_current
{
    kTSI_ExtOscChargeCurrent_2uA = 0U,   /*!< External oscillator charge current is 2 µA */
    kTSI_ExtOscChargeCurrent_4uA = 1U,   /*!< External oscillator charge current is 4 µA */
    kTSI_ExtOscChargeCurrent_6uA = 2U,   /*!< External oscillator charge current is 6 µA */
    kTSI_ExtOscChargeCurrent_8uA = 3U,   /*!< External oscillator charge current is 8 µA */
    kTSI_ExtOscChargeCurrent_10uA = 4U,  /*!< External oscillator charge current is 10 µA */
    kTSI_ExtOscChargeCurrent_12uA = 5U,  /*!< External oscillator charge current is 12 µA */
    kTSI_ExtOscChargeCurrent_14uA = 6U,  /*!< External oscillator charge current is 14 µA */
    kTSI_ExtOscChargeCurrent_16uA = 7U,  /*!< External oscillator charge current is 16 µA */
    kTSI_ExtOscChargeCurrent_18uA = 8U,  /*!< External oscillator charge current is 18 µA */
    kTSI_ExtOscChargeCurrent_20uA = 9U,  /*!< External oscillator charge current is 20 µA */
    kTSI_ExtOscChargeCurrent_22uA = 10U, /*!< External oscillator charge current is 22 µA */
    kTSI_ExtOscChargeCurrent_24uA = 11U, /*!< External oscillator charge current is 24 µA */
    kTSI_ExtOscChargeCurrent_26uA = 12U, /*!< External oscillator charge current is 26 µA */
    kTSI_ExtOscChargeCurrent_28uA = 13U, /*!< External oscillator charge current is 28 µA */
    kTSI_ExtOscChargeCurrent_30uA = 14U, /*!< External oscillator charge current is 30 µA */
    kTSI_ExtOscChargeCurrent_32uA = 15U  /*!< External oscillator charge current is 32 µA */
} tsi_external_osc_charge_current_t;

/*!
 * @brief TSI Active mode clock source.
 *
 * These constants define the active mode clock source in a TSI instance.
 */
typedef enum _tsi_active_mode_clock_source
{
    kTSI_ActiveClkSource_LPOSCCLK = 0U, /*!< Active mode clock source is set to LPOOSC Clock */
    kTSI_ActiveClkSource_MCGIRCLK = 1U, /*!< Active mode clock source is set to MCG Internal reference clock */
    kTSI_ActiveClkSource_OSCERCLK = 2U  /*!< Active mode clock source is set to System oscillator output */
} tsi_active_mode_clock_source_t;

/*!
 * @brief TSI active mode prescaler.
 *
 * These constants define the TSI active mode prescaler in a TSI instance.
 */
typedef enum _tsi_active_mode_prescaler
{
    kTSI_ActiveModePrescaler_1div = 0U,  /*!< Input clock source divided by 1 */
    kTSI_ActiveModePrescaler_2div = 1U,  /*!< Input clock source divided by 2 */
    kTSI_ActiveModePrescaler_4div = 2U,  /*!< Input clock source divided by 4 */
    kTSI_ActiveModePrescaler_8div = 3U,  /*!< Input clock source divided by 8 */
    kTSI_ActiveModePrescaler_16div = 4U, /*!< Input clock source divided by 16 */
    kTSI_ActiveModePrescaler_32div = 5U, /*!< Input clock source divided by 32 */
    kTSI_ActiveModePrescaler_64div = 6U, /*!< Input clock source divided by 64 */
    kTSI_ActiveModePrescaler_128div = 7U /*!< Input clock source divided by 128 */
} tsi_active_mode_prescaler_t;

/*! @brief TSI status flags. */
typedef enum _tsi_status_flags
{
    kTSI_EndOfScanFlag = TSI_GENCS_EOSF_MASK,                /*!< End-Of-Scan flag */
    kTSI_OutOfRangeFlag = TSI_GENCS_OUTRGF_MASK,             /*!< Out-Of-Range flag */
    kTSI_ExternalElectrodeErrorFlag = TSI_GENCS_EXTERF_MASK, /*!< External electrode error flag */
    kTSI_OverrunErrorFlag = TSI_GENCS_OVRF_MASK              /*!< Overrun error flag  */
} tsi_status_flags_t;

/*! @brief TSI feature interrupt source.*/
typedef enum _tsi_interrupt_enable
{
    kTSI_GlobalInterruptEnable = 1U,     /*!< TSI module global interrupt */
    kTSI_OutOfRangeInterruptEnable = 2U, /*!< Out-Of-Range interrupt */
    kTSI_EndOfScanInterruptEnable = 4U,  /*!< End-Of-Scan interrupt */
    kTSI_ErrorInterrruptEnable = 8U      /*!< Error interrupt */
} tsi_interrupt_enable_t;

/*! @brief TSI calibration data storage. */
typedef struct _tsi_calibration_data
{
    uint16_t calibratedData[FSL_FEATURE_TSI_CHANNEL_COUNT]; /*!< TSI calibration data storage buffer */
} tsi_calibration_data_t;

/*!
 * @brief TSI configuration structure.
 *
 * This structure contains the settings for the most common TSI configurations including
 * the TSI module charge currents, number of scans, thresholds, and so on.
 */
typedef struct _tsi_config
{
    uint16_t thresh;                            /*!< High threshold. */
    uint16_t thresl;                            /*!< Low threshold. */
    tsi_low_power_clock_source_t lpclks;        /*!< Low power clock. */
    tsi_low_power_scan_interval_t lpscnitv;     /*!< Low power scan interval. */
    tsi_active_mode_clock_source_t amclks;      /*!< Active mode clock source. */
    tsi_active_mode_prescaler_t ampsc;          /*!< Active mode prescaler. */
    tsi_electrode_osc_prescaler_t ps;           /*!< Electrode Oscillator Prescaler */
    tsi_external_osc_charge_current_t extchrg;  /*!< External Oscillator charge current */
    tsi_reference_osc_charge_current_t refchrg; /*!< Reference Oscillator charge current */
    tsi_n_consecutive_scans_t nscn;             /*!< Number of scans. */
} tsi_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Initializes hardware.
 *
 * @details Initializes the peripheral to the targeted state specified by the parameter configuration,
 *          such as initialize and set prescalers, number of scans, clocks, delta voltage
 *          capacitance trimmer, reference, and electrode charge current and threshold.
 *
 * @param   base    TSI peripheral base address.
 * @param   config  Pointer to the TSI peripheral configuration structure.
 * @return none
 */
void TSI_Init(TSI_Type *base, const tsi_config_t *config);

/*!
 * @brief De-initializes hardware.
 *
 * @details De-initializes the peripheral to default state.
 *
 * @param  base  TSI peripheral base address.
 * @return none
 */
void TSI_Deinit(TSI_Type *base);

/*!
 * @brief Gets TSI normal mode user configuration structure.
 * This interface sets the userConfig structure to a default value. The configuration structure only
 * includes the settings for the whole TSI.
 * The user configure is set to these values:
 * @code
    userConfig.lpclks = kTSI_LowPowerClockSource_LPOCLK;
    userConfig.lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig.amclks = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig.ampsc = kTSI_ActiveModePrescaler_8div;
    userConfig.ps = kTSI_ElecOscPrescaler_2div;
    userConfig.extchrg = kTSI_ExtOscChargeCurrent_10uA;
    userConfig.refchrg = kTSI_RefOscChargeCurrent_10uA;
    userConfig.nscn = kTSI_ConsecutiveScansNumber_8time;
    userConfig.thresh = 0U;
    userConfig.thresl = 0U;
   @endcode
 *
 * @param userConfig Pointer to the TSI user configuration structure.
 */
void TSI_GetNormalModeDefaultConfig(tsi_config_t *userConfig);

/*!
 * @brief Gets the TSI low power mode default user configuration structure.
 * This interface sets userConfig structure to a default value. The configuration structure only
 * includes the settings for the whole TSI.
 * The user configure is set to these values:
 * @code
    userConfig.lpclks = kTSI_LowPowerClockSource_LPOCLK;
    userConfig.lpscnitv = kTSI_LowPowerInterval_100ms;
    userConfig.amclks = kTSI_ActiveClkSource_LPOSCCLK;
    userConfig.ampsc = kTSI_ActiveModePrescaler_64div;
    userConfig.ps = kTSI_ElecOscPrescaler_1div;
    userConfig.extchrg = kTSI_ExtOscChargeCurrent_2uA;
    userConfig.refchrg = kTSI_RefOscChargeCurrent_32uA;
    userConfig.nscn = kTSI_ConsecutiveScansNumber_26time;
    userConfig.thresh = 15000U;
    userConfig.thresl = 1000U;
   @endcode
 *
 * @param userConfig Pointer to the TSI user configuration structure.
 */
void TSI_GetLowPowerModeDefaultConfig(tsi_config_t *userConfig);

/*!
 * @brief Hardware calibration.
 *
 * @details Calibrates the peripheral to fetch the initial counter value of the enabled electrodes.
 *          This API is mostly used at the initial application setup. Call this function after the \ref TSI_Init API
 *          and use the calibrated counter values to set up applications
 *          (such as to determine under which counter value a touch event occurs).
 *
 * @note    This API is called in normal power modes.
 * @note    For K60 series, the calibrated baseline counter value CANNOT be used in low power modes. To obtain
 *          the calibrated counter values in low power modes, see K60 Mask Set Errata for Mask 5N22D.
 * @param   base   TSI peripheral base address.
 * @param   calBuff Data buffer that store the calibrated counter value.
 * @return  none
 *
 */
void TSI_Calibrate(TSI_Type *base, tsi_calibration_data_t *calBuff);

/*!
 * @brief Enables the TSI interrupt requests.
 * @param base TSI peripheral base address.
 * @param mask interrupt source
 *     The parameter can be a combination of the following source if defined:
 *     @arg kTSI_GlobalInterruptEnable
 *     @arg kTSI_EndOfScanInterruptEnable
 *     @arg kTSI_OutOfRangeInterruptEnable
 *     @arg kTSI_ErrorInterrruptEnable
 */
void TSI_EnableInterrupts(TSI_Type *base, uint32_t mask);

/*!
 * @brief Disables the TSI interrupt requests.
 * @param base TSI peripheral base address.
 * @param mask interrupt source
 *     The parameter can be a combination of the following source if defined:
 *     @arg kTSI_GlobalInterruptEnable
 *     @arg kTSI_EndOfScanInterruptEnable
 *     @arg kTSI_OutOfRangeInterruptEnable
 *     @arg kTSI_ErrorInterrruptEnable
 */
void TSI_DisableInterrupts(TSI_Type *base, uint32_t mask);

/*!
* @brief Gets the interrupt flags.
* This function get TSI interrupt flags.
*
* @param   base  TSI peripheral base address.
* @return        The mask of these status flag bits.
*/
static inline uint32_t TSI_GetStatusFlags(TSI_Type *base)
{
    return (base->GENCS &
            (kTSI_EndOfScanFlag | kTSI_OutOfRangeFlag | kTSI_ExternalElectrodeErrorFlag | kTSI_OverrunErrorFlag));
}

/*!
 * @brief Clears the interrupt flags.
 *
 * This function clears the TSI interrupt flags.
 * @note The automatically cleared flags can't be cleared by this function.
 *
 * @param base TSI peripheral base address.
 * @param mask the status flags to clear.
 */
void TSI_ClearStatusFlags(TSI_Type *base, uint32_t mask);

/*!
* @brief Gets the TSI scan trigger mode.
*
* @param  base  TSI peripheral base address.
* @return       Scan trigger mode.
*/
static inline uint32_t TSI_GetScanTriggerMode(TSI_Type *base)
{
    return (base->GENCS & TSI_GENCS_STM_MASK);
}

/*!
* @brief Gets the scan in progress flag.
*
* @param    base TSI peripheral base address.
* @return   True - if scan is in progress.
*           False - if scan is not in progress.
*/
static inline bool TSI_IsScanInProgress(TSI_Type *base)
{
    return (base->GENCS & TSI_GENCS_SCNIP_MASK);
}

/*!
* @brief Sets the electrode oscillator prescaler.
*
* @param   base       TSI peripheral base address.
* @param   prescaler  Prescaler value.
* @return  none.
*/
static inline void TSI_SetElectrodeOSCPrescaler(TSI_Type *base, tsi_electrode_osc_prescaler_t prescaler)
{
    base->GENCS = (base->GENCS & ~(TSI_GENCS_PS_MASK | ALL_FLAGS_MASK)) | (TSI_GENCS_PS(prescaler));
}

/*!
* @brief Sets the number of scans (NSCN).
*
* @param   base   TSI peripheral base address.
* @param   number Number of scans.
* @return  none.
*/
static inline void TSI_SetNumberOfScans(TSI_Type *base, tsi_n_consecutive_scans_t number)
{
    base->GENCS = (base->GENCS & ~(TSI_GENCS_NSCN_MASK | ALL_FLAGS_MASK)) | (TSI_GENCS_NSCN(number));
}

/*!
* @brief Enables/disables the TSI module.
*
* @param    base TSI peripheral base address.
* @param    enable  Choose whether to enable TSI module.
*                   - true  Enable module;
*                   - false Disable module;
* @return   none.
*/
static inline void TSI_EnableModule(TSI_Type *base, bool enable)
{
    if (enable)
    {
        base->GENCS = (base->GENCS & ~ALL_FLAGS_MASK) | TSI_GENCS_TSIEN_MASK;    /* Enable module */
    }
    else
    {
        base->GENCS = (base->GENCS & ~ALL_FLAGS_MASK) & (~TSI_GENCS_TSIEN_MASK); /* Disable module */
    }
}

/*!
* @brief    Enables/disables the TSI module in low power stop mode.
*
* @param    base TSI peripheral base address.
* @param    enable  Choose whether to enable TSI module in low power modes.
*                   - true  Enable module in low power modes;
*                   - false Disable module in low power modes;
* @return   none.
*/
static inline void TSI_EnableLowPower(TSI_Type *base, bool enable)
{
    if (enable)
    {
        base->GENCS = (base->GENCS & ~ALL_FLAGS_MASK) | TSI_GENCS_STPE_MASK;    /* Enable module in low power stop mode */
    }
    else
    {
        base->GENCS = (base->GENCS & ~ALL_FLAGS_MASK) & (~TSI_GENCS_STPE_MASK); /* Disable module in low power stop mode */
    }
}

/*!
* @brief Enables/disables the periodical (hardware) trigger scan.
*
* @param    base TSI peripheral base address.
* @param    enable  Choose whether to enable periodical trigger scan.
*                   - true  Enable periodical trigger scan;
*                   - false Enable software trigger scan;
* @return   none.
*/
static inline void TSI_EnablePeriodicalScan(TSI_Type *base, bool enable)
{
    if (enable)
    {
        base->GENCS = (base->GENCS & ~ALL_FLAGS_MASK) | TSI_GENCS_STM_MASK;    /* Enable period trigger scan */
    }
    else
    {
        base->GENCS = (base->GENCS & ~ALL_FLAGS_MASK) & (~TSI_GENCS_STM_MASK); /* Enable software trigger scan */
    }
}

/*!
* @brief Starts a measurement (trigger a new measurement).
*
* @param    base TSI peripheral base address.
* @return   none.
*/
static inline void TSI_StartSoftwareTrigger(TSI_Type *base)
{
    base->GENCS = (base->GENCS & ~ALL_FLAGS_MASK) | TSI_GENCS_SWTS_MASK;
}

/*!
* @brief Sets a low power scan interval.
*
* @param  base      TSI peripheral base address.
* @param  interval  Interval for low power scan.
* @return none.
*/
static inline void TSI_SetLowPowerScanInterval(TSI_Type *base, tsi_low_power_scan_interval_t interval)
{
    base->GENCS = (base->GENCS & ~(TSI_GENCS_LPSCNITV_MASK | ALL_FLAGS_MASK)) | (TSI_GENCS_LPSCNITV(interval));
}

/*!
* @brief Sets a low power clock.
*
* @param base  TSI peripheral base address.
* @param clock Low power clock selection.
*/
static inline void TSI_SetLowPowerClock(TSI_Type *base, uint32_t clock)
{
    base->GENCS = (base->GENCS & ~(TSI_GENCS_LPCLKS_MASK | ALL_FLAGS_MASK)) | (TSI_GENCS_LPCLKS(clock));
}

/*!
* @brief Sets the reference oscillator charge current.
*
* @param  base    TSI peripheral base address.
* @param  current The reference oscillator charge current.
* @return none.
*/
static inline void TSI_SetReferenceChargeCurrent(TSI_Type *base, tsi_reference_osc_charge_current_t current)
{
    base->SCANC = ((base->SCANC) & ~TSI_SCANC_REFCHRG_MASK) | (TSI_SCANC_REFCHRG(current));
}

/*!
* @brief Sets the electrode charge current.
*
* @param    base    TSI peripheral base address.
* @param    current The external electrode charge current.
* @return   none.
*/
static inline void TSI_SetElectrodeChargeCurrent(TSI_Type *base, tsi_external_osc_charge_current_t current)
{
    base->SCANC = ((base->SCANC) & ~TSI_SCANC_EXTCHRG_MASK) | (TSI_SCANC_EXTCHRG(current));
}

/*!
* @brief Sets the scan modulo value.
*
* @param    base    TSI peripheral base address.
* @param    modulo  Scan modulo value.
* @return   none.
*/
static inline void TSI_SetScanModulo(TSI_Type *base, uint32_t modulo)
{
    base->SCANC = ((base->SCANC) & ~TSI_SCANC_SMOD_MASK) | (TSI_SCANC_SMOD(modulo));
}

/*!
* @brief Sets the active mode source.
*
* @param    base    TSI peripheral base address.
* @param    source  Active mode clock source (LPOSCCLK, MCGIRCLK, OSCERCLK).
* @return   none.
*/
static inline void TSI_SetActiveModeSource(TSI_Type *base, uint32_t source)
{
    base->SCANC = ((base->SCANC) & ~TSI_SCANC_AMCLKS_MASK) | (TSI_SCANC_AMCLKS(source));
}

/*!
* @brief Sets the active mode prescaler.
*
* @param    base       TSI peripheral base address.
* @param    prescaler  Prescaler value.
* @return   none.
*/
static inline void TSI_SetActiveModePrescaler(TSI_Type *base, tsi_active_mode_prescaler_t prescaler)
{
    base->SCANC = ((base->SCANC) & ~TSI_SCANC_AMPSC_MASK) | (TSI_SCANC_AMPSC(prescaler));
}

/*!
* @brief Sets the low power channel.
*        Only one channel can be enabled in low power mode.
*
* @param    base    TSI peripheral base address.
* @param    channel Channel number.
* @return   none.
*/
static inline void TSI_SetLowPowerChannel(TSI_Type *base, uint16_t channel)
{
    assert(channel < FSL_FEATURE_TSI_CHANNEL_COUNT);

    base->PEN = ((base->PEN) & ~TSI_PEN_LPSP_MASK) | (TSI_PEN_LPSP(channel));
}

/*!
 * @brief  Gets the enabled channel in low power modes.
 * @note   Only one channel can be enabled in low power mode.
 *
 * @param  base TSI peripheral base address.
 * @return      Channel number.
 */
static inline uint32_t TSI_GetLowPowerChannel(TSI_Type *base)
{
    return ((base->PEN & TSI_PEN_LPSP_MASK) >> TSI_PEN_LPSP_SHIFT);
}

/*!
* @brief Enables/disables a channel.
*
* @param    base    TSI peripheral base address.
* @param    channel Channel to be enabled.
* @param    enable  Choose whether to enable specific channel.
*                   - true  Enable the specific channel;
*                   - false Disable the specific channel;
* @return   none.
*/
static inline void TSI_EnableChannel(TSI_Type *base, uint16_t channel, bool enable)
{
    assert(channel < FSL_FEATURE_TSI_CHANNEL_COUNT);

    if (enable)
    {
        base->PEN |= (1U << channel); /* Enable this specific channel */
    }
    else
    {
        base->PEN &= ~(1U << channel); /* Disable this specific channel */
    }
}

/*!
* @brief Enables/disables channels.
* The function enables or disables channels by mask. It can enable/disable all channels at once.
*
* @param    base         TSI peripheral base address.
* @param    channelsMask Channels mask that indicate channels that are to be enabled/disabled.
* @param    enable  Choose to enable or disable the specified channels.
*                   - true  Enable the specified channels;
*                   - false Disable the specified channels;
* @return   none.
*/
static inline void TSI_EnableChannels(TSI_Type *base, uint16_t channelsMask, bool enable)
{
    if (enable)
    {
        base->PEN |= channelsMask; /* Enable these specified channels */
    }
    else
    {
        base->PEN &= ~(0x0000FFFFU & (uint32_t)channelsMask); /* Disable these specified channels */
    }
}

/*!
 * @brief Returns if a channel is enabled.
 *
 * @param   base    TSI peripheral base address.
 * @param   channel Channel to be checked.
 *
 * @return true  - if the channel is enabled;
 *         false - if the channel is disabled;
 */
static inline bool TSI_IsChannelEnabled(TSI_Type *base, uint16_t channel)
{
    assert(channel < FSL_FEATURE_TSI_CHANNEL_COUNT);

    return ((base->PEN) & (1U << channel));
}

/*!
* @brief Returns the mask of enabled channels.
*
* @param   base  TSI peripheral base address.
* @return        Channels mask that indicates currently enabled channels.
*/
static inline uint16_t TSI_GetEnabledChannels(TSI_Type *base)
{
    return (uint16_t)(base->PEN & 0x0000FFFFU);
}

/*!
* @brief Gets the wake up channel counter for low-power mode usage.
*
* @param   base  TSI peripheral base address.
* @return        Wake up counter value.
*/
static inline uint16_t TSI_GetWakeUpChannelCounter(TSI_Type *base)
{
    return (uint16_t)base->WUCNTR;
}

/*!
* @brief Gets the TSI conversion counter of a specific channel in normal mode.
* @note    This API can only be used in normal active modes.
*
* @param   base    TSI peripheral base address.
* @param   channel Index of the specific TSI channel.
*
* @return   The counter value of the specific channel.
*/
static inline uint16_t TSI_GetNormalModeCounter(TSI_Type *base, uint16_t channel)
{
    assert(channel < FSL_FEATURE_TSI_CHANNEL_COUNT);

    uint16_t *counter = (uint16_t *)((uint32_t)(&(((base)->CNTR1))) + (channel * 2U));
    return (uint16_t)(*counter);
}

/*!
* @brief Sets a low threshold.
*
* @param    base           TSI peripheral base address.
* @param    low_threshold  Low counter threshold.
* @return   none.
*/
static inline void TSI_SetLowThreshold(TSI_Type *base, uint16_t low_threshold)
{
    base->THRESHOLD = ((base->THRESHOLD) & ~TSI_THRESHOLD_LTHH_MASK) | (TSI_THRESHOLD_LTHH(low_threshold));
}

/*!
* @brief Sets a high threshold.
*
* @param    base            TSI peripheral base address.
* @param    high_threshold  High counter threshold.
* @return   none.
*/
static inline void TSI_SetHighThreshold(TSI_Type *base, uint16_t high_threshold)
{
    base->THRESHOLD = ((base->THRESHOLD) & ~TSI_THRESHOLD_HTHH_MASK) | (TSI_THRESHOLD_HTHH(high_threshold));
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*! @}*/

#endif /* _FSL_TSI_V2_H_*/
