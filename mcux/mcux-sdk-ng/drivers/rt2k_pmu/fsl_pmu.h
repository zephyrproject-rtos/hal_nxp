/*
 * Copyright 2024-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PMU_H_
#define FSL_PMU_H_

#include "fsl_common.h"

/*!
 * @addtogroup pmu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief PMU driver version 2.0.0. */
#define FSL_PMU_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief Body bias update polling timeout (iterations).
 *
 *  0 (default) = wait indefinitely.  Override via Kconfig
 *  (CONFIG_PMU_BB_UPDATE_TIMEOUT) or a direct preprocessor definition.
 */
#ifndef PMU_BB_UPDATE_TIMEOUT
#ifdef CONFIG_PMU_BB_UPDATE_TIMEOUT
#define PMU_BB_UPDATE_TIMEOUT CONFIG_PMU_BB_UPDATE_TIMEOUT
#else
#define PMU_BB_UPDATE_TIMEOUT 0U
#endif
#endif

/*!
 * @brief PMU overall operating mode.
 *
 * Values match POWERCON_SOC_CTRL.PMUCFG_ACTIVE/PMUCFG_STBY.PMU_MODE encoding.
 */
typedef enum _pmu_mode
{
    kPMU_ModeHP     = 0U, /*!< High-performance (HP/NP/LP RUN, Sleep) */
    kPMU_ModeHPProg = 1U, /*!< HP programming mode (internal use) */
    kPMU_ModeLP     = 2U, /*!< Low-power (Deep Sleep standby) */
    kPMU_ModeRET    = 3U, /*!< Retention (Power Down) */
    kPMU_ModeBB     = 4U, /*!< Body Bias / VBAT domain (Deep Power Down) */
} pmu_mode_t;

/*!
 * @brief PMU FSM boot error reason.
 *
 * Encodes the 6-bit PMU_STS[13:8] field. Values 0x00–0x19 are defined by
 * hardware; any other value indicates an undocumented FSM stop reason.
 */
typedef enum _pmu_boot_error_reason
{
    kPMU_BootErrorNone                  = 0x00U, /*!< No error. */
    kPMU_BootErrorHqrefSettle           = 0x01U, /*!< HQ_VREF_OK not asserted during cold boot. */
    kPMU_BootErrorVddCoreAonSettle      = 0x02U, /*!< VDD_CORE_AON OK not asserted during cold boot. */
    kPMU_BootErrorLdoSettle             = 0x03U, /*!< PMU_MONITOR_VDD(A)1V8_OK not asserted during cold boot. */
    kPMU_BootErrorVdd0V8Settle          = 0x04U, /*!< PMU_MONITOR_VDD0V8_OK not asserted during cold boot. */
    kPMU_BootErrorPfmSettle             = 0x05U, /*!< PFM_RDY not asserted during cold boot. */
    kPMU_BootErrorMonVddCoreSettle      = 0x06U, /*!< VDD_CORE_OK not asserted during cold boot. */
    kPMU_BootErrorCguOtpRdyWait         = 0x07U, /*!< 192 MHz not ready for OTP access. */
    kPMU_BootErrorOtpSettle             = 0x08U, /*!< OTP_RDY not asserted. */
    kPMU_BootErrorCguRdyWaitSettle      = 0x09U, /*!< 192 MHz not ready for DC-DC PWM mode. */
    kPMU_BootErrorPwmSettle             = 0x0AU, /*!< PMU PWM settle failure. */
    kPMU_BootErrorVoltCheck             = 0x0BU, /*!< Not all main voltages OK. */
    kPMU_BootErrorPllOkSettle           = 0x0CU, /*!< 192 MHz or MAINPLL not ready. */
    kPMU_BootErrorBodyBiasSettle        = 0x0DU, /*!< PWELL_OK or NWELL_OK not asserted. */
    kPMU_BootErrorHpUpdate              = 0x0EU, /*!< Clocks requested by PSTATE not ready. */
    kPMU_BootErrorPfmLpSettle           = 0x0FU, /*!< PFM_RDY not OK when PFM required in LP. */
    kPMU_BootErrorRetHqRefOffSettle     = 0x10U, /*!< DPD_RDY not asserted when waking from retention. */
    kPMU_BootErrorRetExitSettle         = 0x11U, /*!< HQ_VREF_OK not asserted when waking from PMU_RET. */
    kPMU_BootErrorLpExitSettle          = 0x12U, /*!< Not all main voltages OK when waking from PMU_LP. */
    kPMU_BootErrorCguReqFromLp          = 0x13U, /*!< VDD_CORE not ready when waking from PMU_LP. */
    kPMU_BootErrorWarmResetCguOffSettle = 0x14U, /*!< Clock de-assert not confirmed by CGU during warm reset. */
    kPMU_BootErrorWarmHqrefSettle       = 0x15U, /*!< HQ_VREF_OK not asserted during warm reset. */
    kPMU_BootErrorWarmLdoSettle         = 0x16U, /*!< PMU_MONITOR_VDD(A)1V8_OK not asserted during warm reset. */
    kPMU_BootErrorWarmVdd0V8Settle      = 0x17U, /*!< PMU_MONITOR_VDD0V8_OK not asserted during warm reset. */
    kPMU_BootErrorWarmPfmSettle         = 0x18U, /*!< PFM_RDY not asserted during warm reset. */
    kPMU_BootErrorWarmMonVddCoreSettle  = 0x19U, /*!< VDD_CORE_OK not asserted during warm reset. */
} pmu_boot_error_reason_t;

/* -------------------------------------------------------------------------- */
/* Sensor Threshold Enumerations                                              */
/* -------------------------------------------------------------------------- */

/*! @brief Voltage sensor upper threshold for 0.8 V rail (DCDC / LDO_VDD_0V8). */
typedef enum _pmu_sensor_upper_thres_0v8
{
    kPMU_SensorUpper0V8_875mV  = 0U, /*!< Upper threshold 875 mV. */
    kPMU_SensorUpper0V8_925mV  = 1U, /*!< Upper threshold 925 mV. */
    kPMU_SensorUpper0V8_975mV  = 2U, /*!< Upper threshold 975 mV. */
    kPMU_SensorUpper0V8_1025mV = 3U, /*!< Upper threshold 1025 mV. */
} pmu_sensor_upper_thres_0v8_t;

/*! @brief Voltage sensor lower threshold for 0.8 V rail (DCDC / LDO_VDD_0V8). */
typedef enum _pmu_sensor_lower_thres_0v8
{
    kPMU_SensorLower0V8_725mV = 0U, /*!< Lower threshold 725 mV. */
    kPMU_SensorLower0V8_675mV = 1U, /*!< Lower threshold 675 mV. */
    kPMU_SensorLower0V8_625mV = 2U, /*!< Lower threshold 625 mV. */
    kPMU_SensorLower0V8_575mV = 3U, /*!< Lower threshold 575 mV. */
} pmu_sensor_lower_thres_0v8_t;

/*! @brief Voltage sensor upper threshold for 1.8 V rail (LDO_VDD_1V8 / LDO_VDDA_1V8). */
typedef enum _pmu_sensor_upper_thres_1v8
{
    kPMU_SensorUpper1V8_2V05 = 0U, /*!< Upper threshold 2.05 V. */
    kPMU_SensorUpper1V8_2V10 = 1U, /*!< Upper threshold 2.10 V. */
    kPMU_SensorUpper1V8_2V15 = 2U, /*!< Upper threshold 2.15 V. */
    kPMU_SensorUpper1V8_2V20 = 3U, /*!< Upper threshold 2.20 V. */
} pmu_sensor_upper_thres_1v8_t;

/*! @brief Voltage sensor lower threshold for 1.8 V rail (LDO_VDD_1V8 / LDO_VDDA_1V8). */
typedef enum _pmu_sensor_lower_thres_1v8
{
    kPMU_SensorLower1V8_1V65 = 0U, /*!< Lower threshold 1.65 V. */
    kPMU_SensorLower1V8_1V60 = 1U, /*!< Lower threshold 1.60 V. */
    kPMU_SensorLower1V8_1V55 = 2U, /*!< Lower threshold 1.55 V. */
    kPMU_SensorLower1V8_1V50 = 3U, /*!< Lower threshold 1.50 V. */
} pmu_sensor_lower_thres_1v8_t;

/*! @brief Voltage sensor upper threshold for 3 V rail (VDD_PMU). */
typedef enum _pmu_sensor_upper_thres_3v
{
    kPMU_SensorUpper3V_3V70 = 0U, /*!< Upper threshold 3.70 V. */
    kPMU_SensorUpper3V_3V75 = 1U, /*!< Upper threshold 3.75 V. */
    kPMU_SensorUpper3V_3V80 = 2U, /*!< Upper threshold 3.80 V. */
    kPMU_SensorUpper3V_3V85 = 3U, /*!< Upper threshold 3.85 V. */
} pmu_sensor_upper_thres_3v_t;

/*! @brief Voltage sensor lower threshold for 3 V rail (VDD_PMU). */
typedef enum _pmu_sensor_lower_thres_3v
{
    kPMU_SensorLower3V_2V35 = 0U, /*!< Lower threshold 2.35 V. */
    kPMU_SensorLower3V_2V30 = 1U, /*!< Lower threshold 2.30 V. */
    kPMU_SensorLower3V_2V25 = 2U, /*!< Lower threshold 2.25 V. */
    kPMU_SensorLower3V_2V20 = 3U, /*!< Lower threshold 2.20 V. */
} pmu_sensor_lower_thres_3v_t;

/*! @brief LDO output voltage trim selection (offset from nominal). */
typedef enum _pmu_ldo_volt_sel
{
    kPMU_LdoVoltSelNom    = 0U, /*!< Nominal voltage. */
    kPMU_LdoVoltSelNomP5  = 1U, /*!< Nominal + 5 %. */
    kPMU_LdoVoltSelNomP10 = 2U, /*!< Nominal + 10 %. */
    kPMU_LdoVoltSelNomP20 = 3U, /*!< Nominal + 20 %. */
} pmu_ldo_volt_sel_t;

/* -------------------------------------------------------------------------- */
/* DCDC (VDD_CORE)                                                            */
/* -------------------------------------------------------------------------- */

/*! @brief DCDC converter operating mode. */
typedef enum _pmu_dcdc_mode
{
    kPMU_DcdcModePFM     = 0U, /*!< PFM (pulse-frequency modulation) mode. */
    kPMU_DcdcModeStartup = 1U, /*!< Startup mode (internal use). */
    kPMU_DcdcModePWM     = 2U, /*!< PWM (fixed-frequency) mode. */
    kPMU_DcdcModeDPD     = 3U, /*!< Deep power-down mode (DCDC off). */
} pmu_dcdc_mode_t;

/*!
 * @brief DCDC converter configuration.
 *
 * Controls operating mode, output voltage, protection thresholds, and
 * the actions taken (IRQ / warm reset / cold reset) on fault events.
 */
typedef struct _pmu_dcdc_config
{
    pmu_dcdc_mode_t mode;             /*!< DCDC operating mode. */
    uint8_t         voutAdj;          /*!< Coarse output voltage adjustment code. */
    uint8_t         voutFineAdj;      /*!< Fine output voltage adjustment code. */
    uint8_t         ovlVthAdj;        /*!< Over-voltage lock-out threshold adjust. */
    bool            vsensorVoutAdjEn; /*!< true = enable voltage-sensor-controlled output adjustment. */
    bool            bypassEn;         /*!< true = enable DCDC bypass path. */
    bool            ovlPdEn;          /*!< true = pull down output on OVL event. */

    bool                         sensorEnable;     /*!< true = enable output voltage monitor. */
    pmu_sensor_upper_thres_0v8_t sensorUpperThres; /*!< Over-voltage sensor threshold. */
    pmu_sensor_lower_thres_0v8_t sensorLowerThres; /*!< Under-voltage sensor threshold. */

    bool irqOnVmaxError;  /*!< true = generate IRQ on over-voltage error. */
    bool irqOnVminError;  /*!< true = generate IRQ on under-voltage error. */
    bool irqOnClkLost;    /*!< true = generate IRQ when switching clock is lost. */
    bool irqOnUvlo;       /*!< true = generate IRQ on UVLO event. */
    bool irqOnOclWarn;    /*!< true = generate IRQ on over-current warning. */

    bool warmResetOnVmaxError; /*!< true = trigger warm reset on over-voltage error. */
    bool warmResetOnVminError; /*!< true = trigger warm reset on under-voltage error. */
    bool warmResetOnClkLost;   /*!< true = trigger warm reset when clock is lost. */
    bool warmResetOnUvlo;      /*!< true = trigger warm reset on UVLO event. */
    bool warmResetOnOclWarn;   /*!< true = trigger warm reset on over-current warning. */

    bool coldResetOnVmaxError; /*!< true = trigger cold reset on over-voltage error. */
    bool coldResetOnVminError; /*!< true = trigger cold reset on under-voltage error. */
    bool coldResetOnClkLost;   /*!< true = trigger cold reset when clock is lost. */
    bool coldResetOnUvlo;      /*!< true = trigger cold reset on UVLO event. */
    bool coldResetOnOclWarn;   /*!< true = trigger cold reset on over-current warning. */
} pmu_dcdc_config_t;

/*!
 * @brief DCDC PWM loop compensation configuration.
 *
 * Only relevant when the DCDC is in @ref kPMU_DcdcModePWM mode.
 */
typedef struct _pmu_dcdc_pwm_config
{
    uint8_t loopFilterResAdj;  /*!< Loop filter resistor adjustment code. */
    uint8_t loopFilterCapAdj;  /*!< Loop filter capacitor adjustment code. */
    uint8_t sawtoothAdj;       /*!< Sawtooth ramp adjustment code. */
    uint8_t gmAdj;             /*!< Transconductance (Gm) adjustment code. */
    bool    gmOvlPullupDis;    /*!< true = disable Gm OVL pull-up. */
    bool    gmIniCond;         /*!< true = enable Gm initial condition. */
    bool    ipkOvr;            /*!< true = override peak current limit. */
    uint8_t pulseSkip;         /*!< Pulse skip threshold code. */
    uint8_t maskPeakP;         /*!< Peak-P mask code. */
    uint8_t maskSawtooth;      /*!< Sawtooth mask code. */
    uint8_t setPwm;            /*!< PWM set code. */
    uint8_t maskOcl;           /*!< Over-current limit mask code. */
    uint8_t maskZcs;           /*!< Zero-crossing sense mask code. */
    bool    disPulseSkipping;  /*!< true = disable pulse skipping. */
    bool    voutSteps;         /*!< true = enable voltage output stepping. */
} pmu_dcdc_pwm_config_t;

/* -------------------------------------------------------------------------- */
/* LDOs                                                                       */
/* -------------------------------------------------------------------------- */

/*! @brief LDO operating mode (shared by LDO_VDD_0V8 and LDO_VDD_1V8). */
typedef enum _pmu_ldo_mode
{
    kPMU_LdoModeOff = 0U, /*!< LDO disabled. */
    kPMU_LdoModeHP  = 1U, /*!< High-performance (low-dropout) mode. */
    kPMU_LdoModeLP  = 2U, /*!< Low-power mode. */
} pmu_ldo_mode_t;

/*! @brief LDO_VDD_0V8 (core voltage LDO) configuration. */
typedef struct _pmu_ldo_vdd0v8_config
{
    pmu_ldo_mode_t     mode;         /*!< LDO operating mode. */
    pmu_ldo_volt_sel_t voltSel;      /*!< Output voltage trim in HP mode. */
    pmu_ldo_volt_sel_t lpVoltSel;    /*!< Output voltage trim in LP mode. */
    bool               bypassEn;     /*!< true = enable bypass (short) path. */
    bool               limitDisable; /*!< true = disable current limit. */

    bool                         sensorEnable;     /*!< true = enable output voltage monitor. */
    pmu_sensor_upper_thres_0v8_t sensorUpperThres; /*!< Over-voltage sensor threshold. */
    pmu_sensor_lower_thres_0v8_t sensorLowerThres; /*!< Under-voltage sensor threshold. */

    bool irqOnVmaxError;       /*!< true = generate IRQ on over-voltage error. */
    bool irqOnVminError;       /*!< true = generate IRQ on under-voltage error. */
    bool warmResetOnVmaxError; /*!< true = trigger warm reset on over-voltage error. */
    bool warmResetOnVminError; /*!< true = trigger warm reset on under-voltage error. */
    bool coldResetOnVmaxError; /*!< true = trigger cold reset on over-voltage error. */
    bool coldResetOnVminError; /*!< true = trigger cold reset on under-voltage error. */
} pmu_ldo_vdd0v8_config_t;

/*! @brief LDO_VDD_1V8 (I/O supply LDO) configuration. */
typedef struct _pmu_ldo_vdd1v8_config
{
    pmu_ldo_mode_t     mode;      /*!< LDO operating mode. */
    pmu_ldo_volt_sel_t voltSel;   /*!< Output voltage trim in HP mode. */
    pmu_ldo_volt_sel_t lpVoltSel; /*!< Output voltage trim in LP mode. */
    bool               bypassEn;  /*!< true = enable bypass path. */

    bool                         sensorEnable;     /*!< true = enable output voltage monitor. */
    pmu_sensor_upper_thres_1v8_t sensorUpperThres; /*!< Over-voltage sensor threshold. */
    pmu_sensor_lower_thres_1v8_t sensorLowerThres; /*!< Under-voltage sensor threshold. */

    bool irqOnMonitorOk;       /*!< true = generate IRQ when monitor reports in-range. */
    bool irqOnVmaxError;       /*!< true = generate IRQ on over-voltage error. */
    bool irqOnVminError;       /*!< true = generate IRQ on under-voltage error. */
    bool warmResetOnMonitorOk; /*!< true = trigger warm reset when monitor reports in-range. */
    bool warmResetOnVmaxError; /*!< true = trigger warm reset on over-voltage error. */
    bool warmResetOnVminError; /*!< true = trigger warm reset on under-voltage error. */
    bool coldResetOnMonitorOk; /*!< true = trigger cold reset when monitor reports in-range. */
    bool coldResetOnVmaxError; /*!< true = trigger cold reset on over-voltage error. */
    bool coldResetOnVminError; /*!< true = trigger cold reset on under-voltage error. */
} pmu_ldo_vdd1v8_config_t;

/*! @brief LDO_VDDA_1V8 (analog supply LDO) operating mode. */
typedef enum _pmu_ldo_vdda1v8_mode
{
    kPMU_LdoVdda1V8Off = 0U, /*!< LDO disabled. */
    kPMU_LdoVdda1V8HP  = 1U, /*!< High-performance mode. */
    kPMU_LdoVdda1V8LP  = 2U, /*!< Low-power mode. */
    kPMU_LdoVdda1V8ULP = 3U, /*!< Ultra-low-power mode. */
} pmu_ldo_vdda1v8_mode_t;

/*! @brief LDO_VDDA_1V8 (analog supply LDO) configuration. */
typedef struct _pmu_ldo_vdda1v8_config
{
    pmu_ldo_vdda1v8_mode_t mode;         /*!< LDO operating mode. */
    pmu_ldo_volt_sel_t     voltSel;      /*!< Output voltage trim. */
    bool                   bypassEn;     /*!< true = enable bypass path. */
    bool                   limitDisable; /*!< true = disable current limit. */

    bool                         sensorEnable;     /*!< true = enable output voltage monitor. */
    pmu_sensor_upper_thres_1v8_t sensorUpperThres; /*!< Over-voltage sensor threshold. */
    pmu_sensor_lower_thres_1v8_t sensorLowerThres; /*!< Under-voltage sensor threshold. */

    bool irqOnVmaxError;       /*!< true = generate IRQ on over-voltage error. */
    bool irqOnVminError;       /*!< true = generate IRQ on under-voltage error. */
    bool warmResetOnVmaxError; /*!< true = trigger warm reset on over-voltage error. */
    bool warmResetOnVminError; /*!< true = trigger warm reset on under-voltage error. */
    bool coldResetOnVmaxError; /*!< true = trigger cold reset on over-voltage error. */
    bool coldResetOnVminError; /*!< true = trigger cold reset on under-voltage error. */
} pmu_ldo_vdda1v8_config_t;

/* -------------------------------------------------------------------------- */
/* AON Regulators                                                             */
/* -------------------------------------------------------------------------- */

/*! @brief LDO_CORE_AON (always-on core LDO) configuration. */
typedef struct _pmu_ldo_core_aon_config
{
    bool useBatInput; /*!< true = use VBAT as LDO input; false = use VDD_PMU. */
} pmu_ldo_core_aon_config_t;

/*! @brief LDO_AON_1V8 (always-on 1.8 V LDO) configuration. */
typedef struct _pmu_ldo_aon1v8_config
{
    uint8_t reserved; /*!< Reserved — set to 0. */
} pmu_ldo_aon1v8_config_t;

/* -------------------------------------------------------------------------- */
/* VDD_PMU Monitor                                                            */
/* -------------------------------------------------------------------------- */

/*! @brief VDD_PMU supply monitor configuration. */
typedef struct _pmu_vdd_pmu_config
{
    bool sensorEnable; /*!< true = enable VDD_PMU voltage monitors. */

    pmu_sensor_upper_thres_1v8_t sensor1V8UpperThres; /*!< 1.8 V sensor over-voltage threshold. */
    pmu_sensor_lower_thres_1v8_t sensor1V8LowerThres; /*!< 1.8 V sensor under-voltage threshold. */
    pmu_sensor_upper_thres_3v_t  sensor3VUpperThres;  /*!< 3 V sensor over-voltage threshold. */
    pmu_sensor_lower_thres_3v_t  sensor3VLowerThres;  /*!< 3 V sensor under-voltage threshold. */

    bool irqOnMonitor3VOk;           /*!< true = IRQ when 3 V monitor reports in-range. */
    bool irqOnSensor1V8VmaxError;    /*!< true = IRQ on 1.8 V over-voltage error. */
    bool irqOnSensor1V8VminError;    /*!< true = IRQ on 1.8 V under-voltage error. */
    bool irqOnSensor3VVmaxError;     /*!< true = IRQ on 3 V over-voltage error. */
    bool irqOnSensor3VVminError;     /*!< true = IRQ on 3 V under-voltage error. */

    bool warmResetOnMonitor3VOk;        /*!< true = warm reset when 3 V monitor reports in-range. */
    bool warmResetOnSensor1V8VmaxError; /*!< true = warm reset on 1.8 V over-voltage error. */
    bool warmResetOnSensor1V8VminError; /*!< true = warm reset on 1.8 V under-voltage error. */
    bool warmResetOnSensor3VVmaxError;  /*!< true = warm reset on 3 V over-voltage error. */
    bool warmResetOnSensor3VVminError;  /*!< true = warm reset on 3 V under-voltage error. */

    bool coldResetOnMonitor3VOk;        /*!< true = cold reset when 3 V monitor reports in-range. */
    bool coldResetOnSensor1V8VmaxError; /*!< true = cold reset on 1.8 V over-voltage error. */
    bool coldResetOnSensor1V8VminError; /*!< true = cold reset on 1.8 V under-voltage error. */
    bool coldResetOnSensor3VVmaxError;  /*!< true = cold reset on 3 V over-voltage error. */
    bool coldResetOnSensor3VVminError;  /*!< true = cold reset on 3 V under-voltage error. */
} pmu_vdd_pmu_config_t;

/* -------------------------------------------------------------------------- */
/* Body Bias                                                                  */
/* -------------------------------------------------------------------------- */

/*! @brief Body bias operating mode. */
typedef enum _pmu_body_bias_mode
{
    kPMU_BodyBiasZBB      = 0U, /*!< Zero body bias (ZBB) — safe power-on default. */
    kPMU_BodyBiasFBBFull  = 1U, /*!< Forward body bias on both N-well and P-well. */
    kPMU_BodyBiasFBBPWell = 2U, /*!< Forward body bias on P-well only. */
    kPMU_BodyBiasFBBNWell = 3U, /*!< Forward body bias on N-well only. */
    kPMU_BodyBiasHiZ      = 4U, /*!< High-impedance (body floating). */
    kPMU_BodyBiasStandby  = 5U, /*!< Standby body bias mode (used during Deep Sleep). */
} pmu_body_bias_mode_t;

/*! @brief Body bias voltage ramp clock frequency selection. */
typedef enum _pmu_bb_ramp_clk
{
    kPMU_BbRampClk750kHz  = 0U, /*!< Ramp clock 750 kHz (default). */
    kPMU_BbRampClk667kHz  = 1U, /*!< Ramp clock 667 kHz. */
    kPMU_BbRampClk375kHz  = 2U, /*!< Ramp clock 375 kHz. */
    kPMU_BbRampClk1200kHz = 3U, /*!< Ramp clock 1200 kHz. */
} pmu_bb_ramp_clk_t;

/*! @brief P-well body bias charge pump clock divider selection. */
typedef enum _pmu_bb_pwell_clk
{
    kPMU_BbPwellClkDiv1 = 0U, /*!< P-well clock = ramp clock / 1 (default). */
    kPMU_BbPwellClkDiv2 = 1U, /*!< P-well clock = ramp clock / 2. */
    kPMU_BbPwellClkDiv4 = 2U, /*!< P-well clock = ramp clock / 4. */
    kPMU_BbPwellClkDiv8 = 3U, /*!< P-well clock = ramp clock / 8. */
} pmu_bb_pwell_clk_t;

/*! @brief Body bias configuration. Pass to @ref PMU_ConfigBodyBias. */
typedef struct _pmu_body_bias_config
{
    pmu_body_bias_mode_t mode;        /*!< Body bias operating mode. */
    uint8_t              nwellVolSel; /*!< N-well target voltage selection code (0 = 0 mV for ZBB). */
    uint8_t              pwellVolSel; /*!< P-well target voltage selection code (0 = 0 mV for ZBB). */
    bool                 advcEnable;  /*!< true = enable advanced body bias control. */
    pmu_bb_ramp_clk_t    rampClkSel;  /*!< Voltage ramp clock frequency. */
    pmu_bb_pwell_clk_t   pwellClkSel; /*!< P-well charge pump clock divider. */
    bool                 irqOnCfgDone;  /*!< true = generate IRQ when body bias update completes. */
    bool                 irqOnCfgError; /*!< true = generate IRQ on body bias update error. */
} pmu_body_bias_config_t;

/* -------------------------------------------------------------------------- */
/* Temperature Sensor                                                         */
/* -------------------------------------------------------------------------- */

/*! @brief On-die temperature sensor high-temperature threshold. */
typedef enum _pmu_temp_ht_thre
{
    kPMU_TempHT120C = 0U, /*!< High-temperature threshold 120 °C. */
    kPMU_TempHT125C = 1U, /*!< High-temperature threshold 125 °C. */
    kPMU_TempHT130C = 2U, /*!< High-temperature threshold 130 °C. */
    kPMU_TempHT135C = 3U, /*!< High-temperature threshold 135 °C. */
} pmu_temp_ht_thre_t;

/*! @brief On-die temperature sensor low-temperature threshold. */
typedef enum _pmu_temp_lt_thre
{
    kPMU_TempLT_Minus30C = 1U, /*!< Low-temperature threshold -30 °C. */
    kPMU_TempLT_Minus40C = 2U, /*!< Low-temperature threshold -40 °C. */
} pmu_temp_lt_thre_t;

/*! @brief On-die temperature sensor configuration. */
typedef struct _pmu_temperature_sensor_config
{
    bool               sensorEnable; /*!< true = enable the temperature sensor. */
    bool               trimEnable;   /*!< true = apply factory trim values. */
    pmu_temp_ht_thre_t htThreshold;  /*!< High-temperature alert threshold. */
    pmu_temp_lt_thre_t ltThreshold;  /*!< Low-temperature alert threshold. */

    bool irqOnHtOk;       /*!< true = generate IRQ when temperature exceeds high threshold. */
    bool irqOnLtOk;       /*!< true = generate IRQ when temperature falls below low threshold. */
    bool warmResetOnHtOk; /*!< true = trigger warm reset on high-temperature event. */
    bool warmResetOnLtOk; /*!< true = trigger warm reset on low-temperature event. */
    bool coldResetOnHtOk; /*!< true = trigger cold reset on high-temperature event. */
    bool coldResetOnLtOk; /*!< true = trigger cold reset on low-temperature event. */
} pmu_temperature_sensor_config_t;

/* -------------------------------------------------------------------------- */
/* Oscillator Configs                                                         */
/* -------------------------------------------------------------------------- */

/*! @brief LFRO 1 MHz oscillator configuration. */
typedef struct _pmu_lfro1m_config
{
    bool fromCgu; /*!< true = FSM clock from CGU 1M; false = from PMU internal FRO_1M. Maps to PMU_CLK_REG bit 1. */
} pmu_lfro1m_config_t;

/*!
 * @brief XOSC 32K crystal oscillator configuration.
 *
 * Maps directly to PMU_XOSC32KNP_CTRL_REG.
 * gmSel0/gmSel1 together select the GM bias current; see RM for combined encoding.
 * dll0/dll1 together select the DLL output delay cell count; see RM for combined encoding.
 */
typedef struct _pmu_xosc32k_config
{
    bool clkoutEnable; /*!< true = enable XOSC32K output clock to the chip. */
    bool tcxoMode;     /*!< true = TCXO (high-power) mode; false = SCXO (nano-power) mode. */
    bool bypassEnable; /*!< true = bypass OSC32K; clock taken from EXTAL pin directly. */
    bool clkMonEnable; /*!< true = enable XOSC32K output clock monitoring. */
    bool gmSel0;       /*!< GM bias current select bit 0. */
    bool gmSel1;       /*!< GM bias current select bit 1. */
    bool dll0;         /*!< DLL output delay cell select bit 0. */
    bool dll1;         /*!< DLL output delay cell select bit 1. */
} pmu_xosc32k_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Status and Boot
 * @{
 */

/*!
 * @brief Read the raw PMU status register.
 *
 * @param base  PMU peripheral base address.
 * @return      Raw PMU_STS register value.
 */
uint32_t PMU_GetStatus(PMU_Type *base);

/*!
 * @brief Return the boot error reason latched by the PMU at startup.
 *
 * @param base  PMU peripheral base address.
 * @return      @ref pmu_boot_error_reason_t value.
 */
pmu_boot_error_reason_t PMU_GetBootErrorReason(PMU_Type *base);

/*! @} */

/*!
 * @name DCDC (VDD_CORE)
 * @{
 */

/*!
 * @brief Write the DCDC configuration registers.
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to DCDC configuration. Must not be NULL.
 */
void PMU_ConfigDcdc(PMU_Type *base, const pmu_dcdc_config_t *config);

/*!
 * @brief Write the DCDC PWM loop compensation configuration.
 *
 * Call only when the DCDC is operating in PWM mode (@ref kPMU_DcdcModePWM).
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to PWM loop configuration. Must not be NULL.
 */
void PMU_ConfigDcdcPwmMode(PMU_Type *base, const pmu_dcdc_pwm_config_t *config);

/*! @} */

/*!
 * @name LDOs
 * @{
 */

/*!
 * @brief Configure LDO_VDD_0V8 (core voltage LDO).
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to LDO_VDD_0V8 configuration. Must not be NULL.
 */
void PMU_ConfigLdoVdd0V8(PMU_Type *base, const pmu_ldo_vdd0v8_config_t *config);

/*!
 * @brief Configure LDO_VDD_1V8 (I/O supply LDO).
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to LDO_VDD_1V8 configuration. Must not be NULL.
 */
void PMU_ConfigLdoVdd1V8(PMU_Type *base, const pmu_ldo_vdd1v8_config_t *config);

/*!
 * @brief Configure LDO_VDDA_1V8 (analog supply LDO).
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to LDO_VDDA_1V8 configuration. Must not be NULL.
 */
void PMU_ConfigLdoVdda1V8(PMU_Type *base, const pmu_ldo_vdda1v8_config_t *config);


/*! @} */

/*!
 * @name VDD_PMU Monitor
 * @{
 */

/*!
 * @brief Configure the VDD_PMU voltage monitor.
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to VDD_PMU monitor configuration. Must not be NULL.
 */
void PMU_ConfigVddPmu(PMU_Type *base, const pmu_vdd_pmu_config_t *config);

/*!
 * @brief Check whether VDD_PMU is in the 3 V supply range.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the VDD_PMU 3 V range flag is set.
 */
static inline bool PMU_IsVddPmu3VRange(PMU_Type *base)
{
    return (bool)((base->PMU_STS & PMU_PMU_STS_PMU_MONITOR_VDDPMU_3V_OK_MASK) != 0UL);
}

/*!
 * @brief Check whether VDD_PMU is in the 1.8 V supply range.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the VDD_PMU 1.8 V range flag is set.
 */
static inline bool PMU_IsVddPmu1V8Range(PMU_Type *base)
{
    return (bool)((base->PMU_STS & PMU_PMU_STS_PMU_MONITOR_VDDPMU_1V8_OK_MASK) != 0UL);
}

/*! @} */

/*!
 * @name Body Bias
 * @{
 */

/*!
 * @brief Write the body bias configuration registers.
 *
 * Writes configuration but does NOT trigger the body bias FSM update.
 * Call @ref PMU_ApplyBodyBiasBlocking or @ref PMU_ApplyBodyBiasNonBlocking
 * after this function to apply the new configuration to hardware.
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to body bias configuration. Must not be NULL.
 */
void PMU_ConfigBodyBias(PMU_Type *base, const pmu_body_bias_config_t *config);

/*!
 * @brief Trigger the body bias FSM and block until the update is stable.
 *
 * Clears previous done/error status, triggers the FSM, and polls until
 * either the done flag or the error flag is set. After done, verifies
 * PMU_BODYBIAS_STATUS_STS SAFE_STATE and mode-specific well voltage status.
 *
 * @param base  PMU peripheral base address.
 * @retval kStatus_Success  Body bias update completed without error.
 * @retval kStatus_Fail     Body bias FSM reported an error.
 * @retval kStatus_Timeout  Update or stable-state polling timed out if timeout is configured.
 */
status_t PMU_ApplyBodyBiasBlocking(PMU_Type *base);

/*!
 * @brief Trigger the body bias FSM without waiting for completion.
 *
 * Use @ref PMU_CheckBodyBiasUpdateDone and @ref PMU_CheckBodyBiasUpdateError
 * to poll for completion.
 *
 * @param base  PMU peripheral base address.
 */
void PMU_ApplyBodyBiasNonBlocking(PMU_Type *base);

/*!
 * @brief Fill a body bias config struct with ZBB power-on-safe defaults.
 *
 * Default configuration: mode = ZBB, all voltage selections 0 mV,
 * ramp clock 750 kHz, P-well clock divider 1, all interrupts disabled.
 *
 * @param config  Pointer to config struct to fill. Must not be NULL.
 */
void PMU_GetDefaultBodyBiasConfig(pmu_body_bias_config_t *config);

/*!
 * @brief Check whether the N-well body bias voltage is within the target range.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the N-well voltage-OK flag is set.
 */
static inline bool PMU_GetBodyBiasNwellVoltageOk(PMU_Type *base)
{
    return (bool)((base->PMU_BODYBIAS_STATUS_STS & (1UL << 0U)) != 0UL);
}

/*!
 * @brief Check whether the P-well body bias voltage is within the target range.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the P-well voltage-OK flag is set.
 */
static inline bool PMU_GetBodyBiasPwellVoltageOk(PMU_Type *base)
{
    return (bool)((base->PMU_BODYBIAS_STATUS_STS & (1UL << 1U)) != 0UL);
}

/*!
 * @brief Check whether the body bias is in a safe (non-ramping) state.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the body bias safe-state flag is set.
 */
static inline bool PMU_GetBodyBiasSafeState(PMU_Type *base)
{
    return (bool)((base->PMU_BODYBIAS_STATUS_STS & (1UL << 2U)) != 0UL);
}

/*!
 * @brief Check whether the body bias FSM update-done interrupt status is set.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the update-done interrupt status flag is set.
 */
static inline bool PMU_CheckBodyBiasUpdateDone(PMU_Type *base)
{
    return (bool)((base->PMU_BODYBIAS_INTSTATUS_STS & (1UL << 0U)) != 0UL);
}

/*!
 * @brief Clear the body bias update-done interrupt status flag.
 *
 * @param base  PMU peripheral base address.
 */
static inline void PMU_ClearBodyBiasUpdateStatus(PMU_Type *base)
{
    base->PMU_BODYBIAS_INTCLEAR_REG = (1UL << 0U);
}

/*!
 * @brief Check whether the body bias FSM error interrupt status is set.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the error interrupt status flag is set.
 */
static inline bool PMU_CheckBodyBiasUpdateError(PMU_Type *base)
{
    return (bool)((base->PMU_BODYBIAS_INTSTATUS_STS & (1UL << 1U)) != 0UL);
}

/*!
 * @brief Clear the body bias error interrupt status flag.
 *
 * @param base  PMU peripheral base address.
 */
static inline void PMU_ClearBodyBiasUpdateError(PMU_Type *base)
{
    base->PMU_BODYBIAS_INTCLEAR_REG = (1UL << 1U);
}

/*! @} */

/*!
 * @name Temperature Sensor
 * @{
 */

/*!
 * @brief Configure the on-die temperature sensor.
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to temperature sensor configuration. Must not be NULL.
 */
void PMU_ConfigTemperatureSensor(PMU_Type *base, const pmu_temperature_sensor_config_t *config);

/*!
 * @brief Check whether the die temperature exceeds the high threshold.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the high-temperature status flag is set.
 */
static inline bool PMU_IsTemperatureHigh(PMU_Type *base)
{
    /* PMU_TEMP_SENSOR_HT_OK (bit 0): 0 = temperature reached HT threshold, 1 = OK. */
    return (bool)((base->PMU_STS & PMU_PMU_STS_PMU_TEMP_SENSOR_HT_OK_MASK) == 0UL);
}

/*!
 * @brief Check whether the die temperature is below the low threshold.
 *
 * @param base  PMU peripheral base address.
 * @return      true if the low-temperature status flag is set.
 */
static inline bool PMU_IsTemperatureLow(PMU_Type *base)
{
    /* PMU_TEMP_SENSOR_LT_OK (bit 1): 0 = temperature reached LT threshold, 1 = OK. */
    return (bool)((base->PMU_STS & PMU_PMU_STS_PMU_TEMP_SENSOR_LT_OK_MASK) == 0UL);
}

/*! @} */

/*!
 * @name Oscillators
 * @{
 */

/*!
 * @brief Configure the 1 MHz low-frequency RC oscillator (LFRO 1M).
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to LFRO 1M configuration. Must not be NULL.
 */
void PMU_ConfigLfro1M(PMU_Type *base, const pmu_lfro1m_config_t *config);

/*!
 * @brief Configure the 32 kHz crystal oscillator (XOSC 32K).
 *
 * @param base    PMU peripheral base address.
 * @param config  Pointer to XOSC 32K configuration. Must not be NULL.
 */
void PMU_ConfigXOSC32K(PMU_Type *base, const pmu_xosc32k_config_t *config);

/*!
 * @brief Read the XOSC 32K status register.
 *
 * @param base  PMU peripheral base address.
 * @return      Raw PMU_XOSC32KNP_STS register value.
 */
static inline uint32_t PMU_GetXOSC32KStatus(PMU_Type *base)
{
    return base->PMU_XOSC32KNP_STS;
}

/*! @} */

/*!
 * @name Reset Gate Control
 * @{
 */

/*!
 * @brief Enable or disable PMU warm-reset source gates.
 *
 * @param base    PMU peripheral base address.
 * @param mask    Bitmask of warm-reset source bits to configure.
 * @param enable  true = allow warm reset from these sources; false = suppress.
 */
void PMU_ConfigWarmResetGates(PMU_Type *base, uint32_t mask, bool enable);

/*!
 * @brief Enable or disable PMU cold-reset source gates.
 *
 * @param base    PMU peripheral base address.
 * @param mask    Bitmask of cold-reset source bits to configure.
 * @param enable  true = allow cold reset from these sources; false = suppress.
 */
void PMU_ConfigColdResetGates(PMU_Type *base, uint32_t mask, bool enable);

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enable PMU interrupt sources.
 *
 * @param base  PMU peripheral base address.
 * @param mask  Bitmask of interrupt sources to enable.
 */
void PMU_EnableInterrupts(PMU_Type *base, uint32_t mask);

/*!
 * @brief Disable PMU interrupt sources.
 *
 * @param base  PMU peripheral base address.
 * @param mask  Bitmask of interrupt sources to disable.
 */
void PMU_DisableInterrupts(PMU_Type *base, uint32_t mask);

/*!
 * @brief Clear PMU interrupt status flags.
 *
 * @param base       PMU peripheral base address.
 * @param clearMask  Bitmask of interrupt status flags to clear.
 */
void PMU_ClearInterruptStatusFlags(PMU_Type *base, uint32_t clearMask);

/*!
 * @brief Read the PMU interrupt status for enabled (masked) sources only.
 *
 * @param base  PMU peripheral base address.
 * @return      Bitmask of active, enabled interrupt flags.
 */
uint32_t PMU_GetInterruptStatusFlags(PMU_Type *base);

/*!
 * @brief Read the raw PMU interrupt status regardless of enable state.
 *
 * @param base  PMU peripheral base address.
 * @return      Bitmask of all active interrupt flags.
 */
uint32_t PMU_GetInterruptStatus(PMU_Type *base);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_PMU_H_ */
