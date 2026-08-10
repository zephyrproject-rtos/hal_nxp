/*
 * Copyright 2024-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pmu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG field positions */
#define DCDC_VOUT_ADJ_SHIFT          (0U)
#define DCDC_VOUT_ADJ_MASK           (0x1FU)
#define DCDC_VOUT_FINE_ADJ_SHIFT     (5U)
#define DCDC_VOUT_FINE_ADJ_MASK      (0x60U)
#define DCDC_IPK_ADJ_SHIFT           (7U)
#define DCDC_IPK_ADJ_MASK            (0x180U)
#define DCDC_OVL_VTH_ADJ_SHIFT       (19U)
#define DCDC_OVL_VTH_ADJ_MASK        (0x380000U)
#define DCDC_VSENSOR_VOUT_ADJ_EN_POS (25U)
#define DCDC_BYPASS_EN_POS           (26U)
#define DCDC_OVL_PD_EN_POS           (27U)

/* PMU_BUCK_VDDCORE_CTRL_PWM_REG field positions */
#define PWM_LOOPFILTER_RES_ADJ_SHIFT (0U)
#define PWM_LOOPFILTER_CAP_ADJ_SHIFT (3U)
#define PWM_SAWTOOTH_ADJ_SHIFT       (6U)
#define PWM_GM_ADJ_SHIFT             (9U)
#define PWM_GM_OVL_PULLUP_DIS_POS    (12U)
#define PWM_GM_INI_COND_POS          (13U)
#define PWM_IPK_OVR_POS              (14U)
#define PWM_PULSESKIP_SHIFT          (15U)
#define PWM_MASK_PEAKP_SHIFT         (17U)
#define PWM_MASK_SAWTOOTH_SHIFT      (19U)
#define PWM_SET_PWM_SHIFT            (21U)
#define PWM_MASK_OCL_SHIFT           (23U)
#define PWM_MASK_ZCS_SHIFT           (25U)
#define PWM_DIS_PULSESKIPING_POS     (27U)
#define PWM_VOUT_STEPS_POS           (28U)

/* PMU_BODYBIAS_CONFIG_REG field positions */
#define BB_MODE_SHIFT       (0U)
#define BB_MODE_MASK        (0x7U)
#define BB_PWELL_CLK_SHIFT  (4U)
#define BB_RAMP_CLK_SHIFT   (6U)
#define BB_ADVC_EN_POS      (15U)
#define BB_NWELL_VOL_SHIFT  (16U)
#define BB_NWELL_VOL_MASK   (0x7F0000U)
#define BB_PWELL_VOL_SHIFT  (24U)
#define BB_PWELL_VOL_MASK   (0x7F000000U)

/* PMU_BODYBIAS_COMMAND_REG commands */
#define BB_CMD_UPDATE       (1U)

/* PMU_BODYBIAS_STATUS_STS field positions used to verify WBIAS settled. */
#define BB_STATUS_NWELL_OK_MASK      (1UL << 0U)
#define BB_STATUS_PWELL_OK_MASK      (1UL << 1U)
#define BB_STATUS_SAFE_STATE_MASK    (1UL << 2U)
#define BB_STATUS_NWELL_STATE_SHIFT  (16U)
#define BB_STATUS_PWELL_STATE_SHIFT  (24U)
#define BB_STATUS_VSTATE_MASK        (0x7FU)

/* PMU_SENSOR_CTRL0_REG field positions */
#define SENSOR_CTRL0_CORE_LOWER_SHIFT (0U)
#define SENSOR_CTRL0_CORE_UPPER_SHIFT (2U)
#define SENSOR_CTRL0_0V8_LOWER_SHIFT  (4U)
#define SENSOR_CTRL0_0V8_UPPER_SHIFT  (6U)
#define SENSOR_CTRL0_1V8_LOWER_SHIFT  (8U)
#define SENSOR_CTRL0_1V8_UPPER_SHIFT  (10U)
#define SENSOR_CTRL0_VDDA_LOWER_SHIFT (12U)
#define SENSOR_CTRL0_VDDA_UPPER_SHIFT (14U)

/* PMU_SENSOR_CTRL1_REG field positions */
#define SENSOR_CTRL1_PMU1V8_LOWER_SHIFT (0U)
#define SENSOR_CTRL1_PMU1V8_UPPER_SHIFT (2U)
#define SENSOR_CTRL1_PMU3V_LOWER_SHIFT  (4U)
#define SENSOR_CTRL1_PMU3V_UPPER_SHIFT  (6U)

/* PMU_TEMP_SENSOR field positions */
#define TEMP_HT_THRE_SHIFT  (0U)
#define TEMP_LT_THRE_SHIFT  (2U)
#define TEMP_TRIM_EN_POS    (4U)

/* PMU_LDO_CTRL_REG field positions */
#define LDO_VDD1V8_SEL_SHIFT     (0U)
#define LDO_VDD1V8_BYPASS_POS    (2U)
#define LDO_VDD0V8_SEL_SHIFT     (4U)
#define LDO_VDD0V8_BYPASS_POS    (6U)
#define LDO_VDD0V8_DISILIM_POS   (7U)
#define LDO_VDD1V8_LP_SEL_SHIFT  (8U)
#define LDO_VDD0V8_LP_SEL_SHIFT  (10U)
#define LDO_VDDA1V8_SEL_SHIFT    (12U)
#define LDO_VDDA1V8_BYPASS_POS   (14U)
#define LDO_VDDA1V8_DISILIM_POS  (15U)

/*******************************************************************************
 * Code
 ******************************************************************************/

static bool PMU_IsBodyBiasStable(PMU_Type *base, const pmu_body_bias_config_t *config)
{
    uint32_t sts = base->PMU_BODYBIAS_STATUS_STS;
    bool stable = ((sts & BB_STATUS_SAFE_STATE_MASK) != 0UL);

    if (config->mode == kPMU_BodyBiasFBBFull)
    {
        uint32_t nwellState = (sts >> BB_STATUS_NWELL_STATE_SHIFT) & BB_STATUS_VSTATE_MASK;
        uint32_t pwellState = (sts >> BB_STATUS_PWELL_STATE_SHIFT) & BB_STATUS_VSTATE_MASK;

        stable = stable && ((sts & BB_STATUS_NWELL_OK_MASK) != 0UL) &&
                 ((sts & BB_STATUS_PWELL_OK_MASK) != 0UL) &&
                 (nwellState == config->nwellVolSel) && (pwellState == config->pwellVolSel);
    }
    else if (config->mode == kPMU_BodyBiasFBBPWell)
    {
        uint32_t pwellState = (sts >> BB_STATUS_PWELL_STATE_SHIFT) & BB_STATUS_VSTATE_MASK;

        stable = stable && ((sts & BB_STATUS_PWELL_OK_MASK) != 0UL) &&
                 (pwellState == config->pwellVolSel);
    }
    else if (config->mode == kPMU_BodyBiasFBBNWell)
    {
        uint32_t nwellState = (sts >> BB_STATUS_NWELL_STATE_SHIFT) & BB_STATUS_VSTATE_MASK;

        stable = stable && ((sts & BB_STATUS_NWELL_OK_MASK) != 0UL) &&
                 (nwellState == config->nwellVolSel);
    }
    else if (config->mode == kPMU_BodyBiasZBB)
    {
        uint32_t nwellState = (sts >> BB_STATUS_NWELL_STATE_SHIFT) & BB_STATUS_VSTATE_MASK;
        uint32_t pwellState = (sts >> BB_STATUS_PWELL_STATE_SHIFT) & BB_STATUS_VSTATE_MASK;

        stable = stable && (nwellState == 0U) && (pwellState == 0U);
    }

    return stable;
}

uint32_t PMU_GetStatus(PMU_Type *base)
{
    return base->PMU_STS;
}

pmu_boot_error_reason_t PMU_GetBootErrorReason(PMU_Type *base)
{
    /* Extract the boot error reason code from the PMU status register. */
    return (pmu_boot_error_reason_t)((base->PMU_STS & PMU_PMU_STS_PMU_BOOT_ERROR_STS_MASK) >>
                                     PMU_PMU_STS_PMU_BOOT_ERROR_STS_SHIFT);
}

/* -------------------------------------------------------------------------- */
/* DCDC                                                                       */
/* -------------------------------------------------------------------------- */

void PMU_ConfigDcdc(PMU_Type *base, const pmu_dcdc_config_t *config)
{
    assert(config != NULL);

    /* Configure DCDC converter registers in four sequential write passes. */
    /* Assemble PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG. */
    uint32_t reg = 0U;
    reg |= ((uint32_t)config->voutAdj & DCDC_VOUT_ADJ_MASK) << DCDC_VOUT_ADJ_SHIFT;
    reg |= ((uint32_t)config->voutFineAdj & 0x3U) << DCDC_VOUT_FINE_ADJ_SHIFT;
    reg |= ((uint32_t)config->mode & 0x3U) << DCDC_IPK_ADJ_SHIFT;
    reg |= ((uint32_t)config->ovlVthAdj & 0x7U) << DCDC_OVL_VTH_ADJ_SHIFT;
    /* Optional analog control flags: voltage sensor adjust, bypass, OVL power-down. */
    if (config->vsensorVoutAdjEn)
    {
        reg |= (1UL << DCDC_VSENSOR_VOUT_ADJ_EN_POS);
    }
    if (config->bypassEn)
    {
        reg |= (1UL << DCDC_BYPASS_EN_POS);
    }
    if (config->ovlPdEn)
    {
        reg |= (1UL << DCDC_OVL_PD_EN_POS);
    }
    base->PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG = reg;

    /* Sensor thresholds in SENSOR_CTRL0_REG bits [3:0]. */
    uint32_t sensor0 = base->PMU_SENSOR_CTRL0_REG;
    sensor0 &= ~(0xFUL); /* Clear bits [3:0] */
    sensor0 |= ((uint32_t)config->sensorLowerThres & 0x3U) << SENSOR_CTRL0_CORE_LOWER_SHIFT;
    sensor0 |= ((uint32_t)config->sensorUpperThres & 0x3U) << SENSOR_CTRL0_CORE_UPPER_SHIFT;
    base->PMU_SENSOR_CTRL0_REG = sensor0;

    /* IRQ enables — DCDC bits in PMU_DIG_IRQ_EN_REG [4:0]. */
    uint32_t irqEn = base->PMU_DIG_IRQ_EN_REG;
    irqEn &= ~(0x1FUL);
    /* Set DCDC interrupt source enables per config. */
    if (config->irqOnVmaxError) { irqEn |= (1UL << 0U); }
    if (config->irqOnVminError) { irqEn |= (1UL << 1U); }
    if (config->irqOnClkLost)   { irqEn |= (1UL << 2U); }
    if (config->irqOnUvlo)      { irqEn |= (1UL << 3U); }
    if (config->irqOnOclWarn)   { irqEn |= (1UL << 4U); }
    base->PMU_DIG_IRQ_EN_REG = irqEn;

    /* Warm reset triggers — DCDC bits in RESETCON_WARM_CTRL [4:0]. */
    uint32_t warm = base->PMU_RESETCON_WARM_CTRL;
    warm &= ~(0x1FUL);
    /* Set DCDC warm-reset trigger enables per config. */
    if (config->warmResetOnVmaxError) { warm |= (1UL << 0U); }
    if (config->warmResetOnVminError) { warm |= (1UL << 1U); }
    if (config->warmResetOnClkLost)   { warm |= (1UL << 2U); }
    if (config->warmResetOnUvlo)      { warm |= (1UL << 3U); }
    if (config->warmResetOnOclWarn)   { warm |= (1UL << 4U); }
    base->PMU_RESETCON_WARM_CTRL = warm;

    /* Cold reset triggers — DCDC bits in RESETCON_COLD_CTRL [4:0]. */
    uint32_t cold = base->PMU_RESETCON_COLD_CTRL;
    cold &= ~(0x1FUL);
    /* Set DCDC cold-reset trigger enables per config. */
    if (config->coldResetOnVmaxError) { cold |= (1UL << 0U); }
    if (config->coldResetOnVminError) { cold |= (1UL << 1U); }
    if (config->coldResetOnClkLost)   { cold |= (1UL << 2U); }
    if (config->coldResetOnUvlo)      { cold |= (1UL << 3U); }
    if (config->coldResetOnOclWarn)   { cold |= (1UL << 4U); }
    base->PMU_RESETCON_COLD_CTRL = cold;
}

void PMU_ConfigDcdcPwmMode(PMU_Type *base, const pmu_dcdc_pwm_config_t *config)
{
    assert(config != NULL);

    /* Assemble PMU_BUCK_VDDCORE_CTRL_PWM_REG from all PWM mode config fields. */
    uint32_t reg = 0U;
    /* Analog loop compensation: filter resistor, capacitor, and sawtooth trim. */
    reg |= ((uint32_t)config->loopFilterResAdj & 0x7U) << PWM_LOOPFILTER_RES_ADJ_SHIFT;
    reg |= ((uint32_t)config->loopFilterCapAdj & 0x7U) << PWM_LOOPFILTER_CAP_ADJ_SHIFT;
    reg |= ((uint32_t)config->sawtoothAdj & 0x7U) << PWM_SAWTOOTH_ADJ_SHIFT;
    reg |= ((uint32_t)config->gmAdj & 0x7U) << PWM_GM_ADJ_SHIFT;
    /* Gate-driver strength and peak current override flags. */
    if (config->gmOvlPullupDis)   { reg |= (1UL << PWM_GM_OVL_PULLUP_DIS_POS); }
    if (config->gmIniCond)        { reg |= (1UL << PWM_GM_INI_COND_POS); }
    if (config->ipkOvr)           { reg |= (1UL << PWM_IPK_OVR_POS); }
    /* PWM switching masks and output voltage mode selection fields. */
    reg |= ((uint32_t)config->pulseSkip & 0x3U) << PWM_PULSESKIP_SHIFT;
    reg |= ((uint32_t)config->maskPeakP & 0x3U) << PWM_MASK_PEAKP_SHIFT;
    reg |= ((uint32_t)config->maskSawtooth & 0x3U) << PWM_MASK_SAWTOOTH_SHIFT;
    reg |= ((uint32_t)config->setPwm & 0x3U) << PWM_SET_PWM_SHIFT;
    reg |= ((uint32_t)config->maskOcl & 0x3U) << PWM_MASK_OCL_SHIFT;
    reg |= ((uint32_t)config->maskZcs & 0x3U) << PWM_MASK_ZCS_SHIFT;
    /* Output voltage step mode and pulse-skip disable flags. */
    if (config->disPulseSkipping) { reg |= (1UL << PWM_DIS_PULSESKIPING_POS); }
    if (config->voutSteps)        { reg |= (1UL << PWM_VOUT_STEPS_POS); }

    base->PMU_BUCK_VDDCORE_CTRL_PWM_REG = reg;
}

/* -------------------------------------------------------------------------- */
/* LDOs                                                                       */
/* -------------------------------------------------------------------------- */

void PMU_ConfigLdoVdd0V8(PMU_Type *base, const pmu_ldo_vdd0v8_config_t *config)
{
    assert(config != NULL);

    /* LDO_CTRL_REG: VDD_0V8 fields at bits [11:4]. */
    uint32_t ldo = base->PMU_LDO_CTRL_REG;
    ldo &= ~(0xFF0U); /* Clear bits [11:4] */
    ldo |= ((uint32_t)config->voltSel & 0x3U) << LDO_VDD0V8_SEL_SHIFT;
    if (config->bypassEn)     { ldo |= (1UL << LDO_VDD0V8_BYPASS_POS); }
    if (config->limitDisable) { ldo |= (1UL << LDO_VDD0V8_DISILIM_POS); }
    ldo |= ((uint32_t)config->lpVoltSel & 0x3U) << LDO_VDD0V8_LP_SEL_SHIFT;
    base->PMU_LDO_CTRL_REG = ldo;

    /* Sensor thresholds: SENSOR_CTRL0_REG bits [7:4]. */
    uint32_t sensor0 = base->PMU_SENSOR_CTRL0_REG;
    sensor0 &= ~(0xF0UL);
    sensor0 |= ((uint32_t)config->sensorLowerThres & 0x3U) << SENSOR_CTRL0_0V8_LOWER_SHIFT;
    sensor0 |= ((uint32_t)config->sensorUpperThres & 0x3U) << SENSOR_CTRL0_0V8_UPPER_SHIFT;
    base->PMU_SENSOR_CTRL0_REG = sensor0;

    /* IRQ: VDD_0V8 bits at [6:5] of PMU_DIG_IRQ_EN_REG. */
    uint32_t irqEn = base->PMU_DIG_IRQ_EN_REG;
    irqEn &= ~(0x3UL << 5U);
    if (config->irqOnVmaxError) { irqEn |= (1UL << 5U); }
    if (config->irqOnVminError) { irqEn |= (1UL << 6U); }
    base->PMU_DIG_IRQ_EN_REG = irqEn;

    /* Warm reset: VDD_0V8 bits at [6:5] of RESETCON_WARM_CTRL. */
    uint32_t warm = base->PMU_RESETCON_WARM_CTRL;
    warm &= ~(0x3UL << 5U);
    if (config->warmResetOnVmaxError) { warm |= (1UL << 5U); }
    if (config->warmResetOnVminError) { warm |= (1UL << 6U); }
    base->PMU_RESETCON_WARM_CTRL = warm;

    /* Cold reset: VDD_0V8 bits at [6:5] of RESETCON_COLD_CTRL. */
    uint32_t cold = base->PMU_RESETCON_COLD_CTRL;
    cold &= ~(0x3UL << 5U);
    if (config->coldResetOnVmaxError) { cold |= (1UL << 5U); }
    if (config->coldResetOnVminError) { cold |= (1UL << 6U); }
    base->PMU_RESETCON_COLD_CTRL = cold;
}

void PMU_ConfigLdoVdd1V8(PMU_Type *base, const pmu_ldo_vdd1v8_config_t *config)
{
    assert(config != NULL);

    /* Configure VDD_1V8 LDO: voltage, LP voltage, sensor thresholds, IRQ, and reset settings. */
    /* LDO_CTRL_REG: VDD_1V8 fields at bits [2:0] and [9:8]. */
    uint32_t ldo = base->PMU_LDO_CTRL_REG;
    ldo &= ~(0x307U); /* Clear bits [2:0] and [9:8] */
    ldo |= ((uint32_t)config->voltSel & 0x3U) << LDO_VDD1V8_SEL_SHIFT;
    if (config->bypassEn) { ldo |= (1UL << LDO_VDD1V8_BYPASS_POS); }
    ldo |= ((uint32_t)config->lpVoltSel & 0x3U) << LDO_VDD1V8_LP_SEL_SHIFT;
    base->PMU_LDO_CTRL_REG = ldo;

    /* Sensor thresholds: SENSOR_CTRL0_REG bits [11:8]. */
    uint32_t sensor0 = base->PMU_SENSOR_CTRL0_REG;
    sensor0 &= ~(0xF00UL);
    sensor0 |= ((uint32_t)config->sensorLowerThres & 0x3U) << SENSOR_CTRL0_1V8_LOWER_SHIFT;
    sensor0 |= ((uint32_t)config->sensorUpperThres & 0x3U) << SENSOR_CTRL0_1V8_UPPER_SHIFT;
    base->PMU_SENSOR_CTRL0_REG = sensor0;

    /* IRQ: VDD_1V8 bits at [9:7] of PMU_DIG_IRQ_EN_REG. */
    /* Clear VDD_1V8 IRQ bits; preserve all other interrupt enables. */
    uint32_t irqEn = base->PMU_DIG_IRQ_EN_REG;
    irqEn &= ~(0x7UL << 7U);
    if (config->irqOnMonitorOk) { irqEn |= (1UL << 7U); }
    if (config->irqOnVmaxError) { irqEn |= (1UL << 8U); }
    if (config->irqOnVminError) { irqEn |= (1UL << 9U); }
    base->PMU_DIG_IRQ_EN_REG = irqEn;

    /* Warm reset: VDD_1V8 bits at [9:7] of RESETCON_WARM_CTRL. */
    uint32_t warm = base->PMU_RESETCON_WARM_CTRL;
    warm &= ~(0x7UL << 7U);
    if (config->warmResetOnMonitorOk) { warm |= (1UL << 7U); }
    if (config->warmResetOnVmaxError) { warm |= (1UL << 8U); }
    if (config->warmResetOnVminError) { warm |= (1UL << 9U); }
    base->PMU_RESETCON_WARM_CTRL = warm;

    /* Cold reset: VDD_1V8 bits at [9:7] of RESETCON_COLD_CTRL. */
    uint32_t cold = base->PMU_RESETCON_COLD_CTRL;
    cold &= ~(0x7UL << 7U);
    if (config->coldResetOnMonitorOk) { cold |= (1UL << 7U); }
    if (config->coldResetOnVmaxError) { cold |= (1UL << 8U); }
    if (config->coldResetOnVminError) { cold |= (1UL << 9U); }
    base->PMU_RESETCON_COLD_CTRL = cold;
}

void PMU_ConfigLdoVdda1V8(PMU_Type *base, const pmu_ldo_vdda1v8_config_t *config)
{
    assert(config != NULL);

    /* Configure VDDA_1V8 LDO: voltage, sensor thresholds, IRQ, and reset settings. */
    /* LDO_CTRL_REG: VDDA_1V8 fields at bits [15:12]. */
    uint32_t ldo = base->PMU_LDO_CTRL_REG;
    ldo &= ~(0xF000UL);
    ldo |= ((uint32_t)config->voltSel & 0x3U) << LDO_VDDA1V8_SEL_SHIFT;
    if (config->bypassEn)     { ldo |= (1UL << LDO_VDDA1V8_BYPASS_POS); }
    if (config->limitDisable) { ldo |= (1UL << LDO_VDDA1V8_DISILIM_POS); }
    base->PMU_LDO_CTRL_REG = ldo;

    /* Sensor thresholds: SENSOR_CTRL0_REG bits [15:12]. */
    uint32_t sensor0 = base->PMU_SENSOR_CTRL0_REG;
    sensor0 &= ~(0xF000UL);
    sensor0 |= ((uint32_t)config->sensorLowerThres & 0x3U) << SENSOR_CTRL0_VDDA_LOWER_SHIFT;
    sensor0 |= ((uint32_t)config->sensorUpperThres & 0x3U) << SENSOR_CTRL0_VDDA_UPPER_SHIFT;
    base->PMU_SENSOR_CTRL0_REG = sensor0;

    /* IRQ: VDDA_1V8 bits at [11:10] of PMU_DIG_IRQ_EN_REG. */
    /* Clear VDDA_1V8 IRQ bits; preserve all other interrupt enables. */
    uint32_t irqEn = base->PMU_DIG_IRQ_EN_REG;
    irqEn &= ~(0x3UL << 10U);
    if (config->irqOnVmaxError) { irqEn |= (1UL << 10U); }
    if (config->irqOnVminError) { irqEn |= (1UL << 11U); }
    base->PMU_DIG_IRQ_EN_REG = irqEn;

    /* Warm reset: VDDA_1V8 bits at [11:10] of RESETCON_WARM_CTRL. */
    uint32_t warm = base->PMU_RESETCON_WARM_CTRL;
    warm &= ~(0x3UL << 10U);
    if (config->warmResetOnVmaxError) { warm |= (1UL << 10U); }
    if (config->warmResetOnVminError) { warm |= (1UL << 11U); }
    base->PMU_RESETCON_WARM_CTRL = warm;

    /* Cold reset: VDDA_1V8 bits at [11:10] of RESETCON_COLD_CTRL. */
    uint32_t cold = base->PMU_RESETCON_COLD_CTRL;
    cold &= ~(0x3UL << 10U);
    if (config->coldResetOnVmaxError) { cold |= (1UL << 10U); }
    if (config->coldResetOnVminError) { cold |= (1UL << 11U); }
    base->PMU_RESETCON_COLD_CTRL = cold;
}

/* -------------------------------------------------------------------------- */
/* VDD_PMU Monitor                                                            */
/* -------------------------------------------------------------------------- */

void PMU_ConfigVddPmu(PMU_Type *base, const pmu_vdd_pmu_config_t *config)
{
    assert(config != NULL);

    /* Configure VDD_PMU voltage monitor: sensor thresholds, interrupt, and reset settings. */
    /* Sensor thresholds: SENSOR_CTRL1_REG bits [7:0]. */
    uint32_t sensor1 = base->PMU_SENSOR_CTRL1_REG;
    sensor1 &= ~(0xFFUL);
    /* Two threshold fields each for PMU_1V8 and PMU_3V (lower and upper limits). */
    sensor1 |= ((uint32_t)config->sensor1V8LowerThres & 0x3U) << SENSOR_CTRL1_PMU1V8_LOWER_SHIFT;
    sensor1 |= ((uint32_t)config->sensor1V8UpperThres & 0x3U) << SENSOR_CTRL1_PMU1V8_UPPER_SHIFT;
    sensor1 |= ((uint32_t)config->sensor3VLowerThres & 0x3U) << SENSOR_CTRL1_PMU3V_LOWER_SHIFT;
    sensor1 |= ((uint32_t)config->sensor3VUpperThres & 0x3U) << SENSOR_CTRL1_PMU3V_UPPER_SHIFT;
    base->PMU_SENSOR_CTRL1_REG = sensor1;

    /* IRQ: VDD_PMU bits at [16:12] of PMU_DIG_IRQ_EN_REG. */
    /* Five sources: 3V monitor OK, sensor 1V8 max/min, sensor 3V max/min. */
    uint32_t irqEn = base->PMU_DIG_IRQ_EN_REG;
    irqEn &= ~(0x1FUL << 12U);
    if (config->irqOnMonitor3VOk)        { irqEn |= (1UL << 12U); }
    if (config->irqOnSensor1V8VmaxError) { irqEn |= (1UL << 13U); }
    if (config->irqOnSensor1V8VminError) { irqEn |= (1UL << 14U); }
    if (config->irqOnSensor3VVmaxError)  { irqEn |= (1UL << 15U); }
    if (config->irqOnSensor3VVminError)  { irqEn |= (1UL << 16U); }
    base->PMU_DIG_IRQ_EN_REG = irqEn;

    /* Warm reset: VDD_PMU bits at [16:12] of RESETCON_WARM_CTRL. */
    /* Same five sources as IRQ, mapped to warm-reset trigger register. */
    uint32_t warm = base->PMU_RESETCON_WARM_CTRL;
    warm &= ~(0x1FUL << 12U);
    if (config->warmResetOnMonitor3VOk)        { warm |= (1UL << 12U); }
    if (config->warmResetOnSensor1V8VmaxError) { warm |= (1UL << 13U); }
    if (config->warmResetOnSensor1V8VminError) { warm |= (1UL << 14U); }
    if (config->warmResetOnSensor3VVmaxError)  { warm |= (1UL << 15U); }
    if (config->warmResetOnSensor3VVminError)  { warm |= (1UL << 16U); }
    base->PMU_RESETCON_WARM_CTRL = warm;

    /* Cold reset: VDD_PMU bits at [16:12] of RESETCON_COLD_CTRL. */
    uint32_t cold = base->PMU_RESETCON_COLD_CTRL;
    cold &= ~(0x1FUL << 12U);
    if (config->coldResetOnMonitor3VOk)        { cold |= (1UL << 12U); }
    if (config->coldResetOnSensor1V8VmaxError) { cold |= (1UL << 13U); }
    if (config->coldResetOnSensor1V8VminError) { cold |= (1UL << 14U); }
    if (config->coldResetOnSensor3VVmaxError)  { cold |= (1UL << 15U); }
    if (config->coldResetOnSensor3VVminError)  { cold |= (1UL << 16U); }
    base->PMU_RESETCON_COLD_CTRL = cold;
}

/* -------------------------------------------------------------------------- */
/* Body Bias                                                                  */
/* -------------------------------------------------------------------------- */

void PMU_ConfigBodyBias(PMU_Type *base, const pmu_body_bias_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = 0U;
    reg |= ((uint32_t)config->mode & BB_MODE_MASK) << BB_MODE_SHIFT;
    reg |= ((uint32_t)config->pwellClkSel & 0x3U) << BB_PWELL_CLK_SHIFT;
    reg |= ((uint32_t)config->rampClkSel & 0x3U) << BB_RAMP_CLK_SHIFT;
    if (config->advcEnable) { reg |= (1UL << BB_ADVC_EN_POS); }
    reg |= ((uint32_t)config->nwellVolSel & 0x7FU) << BB_NWELL_VOL_SHIFT;
    reg |= ((uint32_t)config->pwellVolSel & 0x7FU) << BB_PWELL_VOL_SHIFT;
    base->PMU_BODYBIAS_CONFIG_REG = reg;

    /* Interrupt enable register. */
    uint32_t intEn = 0U;
    if (config->irqOnCfgDone)  { intEn |= (1UL << 0U); }
    if (config->irqOnCfgError) { intEn |= (1UL << 1U); }
    base->PMU_BODYBIAS_INTENABLE_REG = intEn;
}

status_t PMU_ApplyBodyBiasBlocking(PMU_Type *base)
{
    uint32_t configReg = base->PMU_BODYBIAS_CONFIG_REG;
    pmu_body_bias_config_t appliedConfig;

    appliedConfig.mode        = (pmu_body_bias_mode_t)((configReg >> BB_MODE_SHIFT) & BB_MODE_MASK);
    appliedConfig.nwellVolSel = (uint8_t)((configReg & BB_NWELL_VOL_MASK) >> BB_NWELL_VOL_SHIFT);
    appliedConfig.pwellVolSel = (uint8_t)((configReg & BB_PWELL_VOL_MASK) >> BB_PWELL_VOL_SHIFT);

    /* Clear previous status. */
    base->PMU_BODYBIAS_INTCLEAR_REG = 0x3U;

    /* Issue update command. */
    base->PMU_BODYBIAS_COMMAND_REG = BB_CMD_UPDATE;

    /* Poll for completion or error. */
#if PMU_BB_UPDATE_TIMEOUT
    uint32_t timeout = PMU_BB_UPDATE_TIMEOUT;
#endif
    while (true)
    {
        uint32_t sts = base->PMU_BODYBIAS_INTSTATUS_STS;
        if ((sts & (1UL << 1U)) != 0UL)
        {
            return kStatus_Fail; /* Error */
        }
        if ((sts & (1UL << 0U)) != 0UL)
        {
            break; /* Done */
        }
#if PMU_BB_UPDATE_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

#if PMU_BB_UPDATE_TIMEOUT
    timeout = PMU_BB_UPDATE_TIMEOUT;
#endif
    while (!PMU_IsBodyBiasStable(base, &appliedConfig))
    {
#if PMU_BB_UPDATE_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

void PMU_ApplyBodyBiasNonBlocking(PMU_Type *base)
{
    base->PMU_BODYBIAS_INTCLEAR_REG = 0x3U;
    base->PMU_BODYBIAS_COMMAND_REG  = BB_CMD_UPDATE;
}

void PMU_GetDefaultBodyBiasConfig(pmu_body_bias_config_t *config)
{
    assert(config != NULL);

    config->mode          = kPMU_BodyBiasZBB;
    config->nwellVolSel   = 0U;
    config->pwellVolSel   = 0U;
    config->advcEnable    = false;
    config->rampClkSel    = kPMU_BbRampClk750kHz;
    config->pwellClkSel   = kPMU_BbPwellClkDiv1;
    config->irqOnCfgDone  = false;
    config->irqOnCfgError = false;
}

/* -------------------------------------------------------------------------- */
/* Temperature Sensor                                                         */
/* -------------------------------------------------------------------------- */

void PMU_ConfigTemperatureSensor(PMU_Type *base, const pmu_temperature_sensor_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = 0U;
    reg |= ((uint32_t)config->htThreshold & 0x3U) << TEMP_HT_THRE_SHIFT;
    reg |= ((uint32_t)config->ltThreshold & 0x3U) << TEMP_LT_THRE_SHIFT;
    if (config->trimEnable) { reg |= (1UL << TEMP_TRIM_EN_POS); }
    base->PMU_TEMP_SENSOR = reg;

    /* IRQ: TEMP bits at [18:17] of PMU_DIG_IRQ_EN_REG. */
    uint32_t irqEn = base->PMU_DIG_IRQ_EN_REG;
    irqEn &= ~(0x3UL << 17U);
    if (config->irqOnHtOk) { irqEn |= (1UL << 17U); }
    if (config->irqOnLtOk) { irqEn |= (1UL << 18U); }
    base->PMU_DIG_IRQ_EN_REG = irqEn;

    /* Warm reset: TEMP bits at [18:17] of RESETCON_WARM_CTRL. */
    uint32_t warm = base->PMU_RESETCON_WARM_CTRL;
    warm &= ~(0x3UL << 17U);
    if (config->warmResetOnHtOk) { warm |= (1UL << 17U); }
    if (config->warmResetOnLtOk) { warm |= (1UL << 18U); }
    base->PMU_RESETCON_WARM_CTRL = warm;

    /* Cold reset: TEMP bits at [18:17] of RESETCON_COLD_CTRL. */
    uint32_t cold = base->PMU_RESETCON_COLD_CTRL;
    cold &= ~(0x3UL << 17U);
    if (config->coldResetOnHtOk) { cold |= (1UL << 17U); }
    if (config->coldResetOnLtOk) { cold |= (1UL << 18U); }
    base->PMU_RESETCON_COLD_CTRL = cold;
}

/* -------------------------------------------------------------------------- */
/* Oscillators                                                                */
/* -------------------------------------------------------------------------- */

void PMU_ConfigLfro1M(PMU_Type *base, const pmu_lfro1m_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = base->PMU_CLK_REG & ~PMU_PMU_CLK_REG_PMU_LFRO1M_FROM_CGU_MASK;
    if (config->fromCgu)
    {
        reg |= PMU_PMU_CLK_REG_PMU_LFRO1M_FROM_CGU_MASK;
    }
    base->PMU_CLK_REG = reg;
}

void PMU_ConfigXOSC32K(PMU_Type *base, const pmu_xosc32k_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = 0U;
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKOUT_EN(config->clkoutEnable ? 1UL : 0UL);
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_MODE(config->tcxoMode ? 1UL : 0UL);
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_BYPASS_EN(config->bypassEnable ? 1UL : 0UL);
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKMON_EN(config->clkMonEnable ? 1UL : 0UL);
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL0(config->gmSel0 ? 1UL : 0UL);
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL1(config->gmSel1 ? 1UL : 0UL);
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL0(config->dll0 ? 1UL : 0UL);
    reg |= PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL1(config->dll1 ? 1UL : 0UL);
    base->PMU_XOSC32KNP_CTRL_REG = reg;
}

/* -------------------------------------------------------------------------- */
/* Reset Gate Control                                                         */
/* -------------------------------------------------------------------------- */

void PMU_ConfigWarmResetGates(PMU_Type *base, uint32_t mask, bool enable)
{
    if (enable)
    {
        base->PMU_RESETCON_WARM_CTRL |= mask;
    }
    else
    {
        base->PMU_RESETCON_WARM_CTRL &= ~mask;
    }
}

void PMU_ConfigColdResetGates(PMU_Type *base, uint32_t mask, bool enable)
{
    if (enable)
    {
        base->PMU_RESETCON_COLD_CTRL |= mask;
    }
    else
    {
        base->PMU_RESETCON_COLD_CTRL &= ~mask;
    }
}

/* -------------------------------------------------------------------------- */
/* Interrupts                                                                 */
/* -------------------------------------------------------------------------- */

void PMU_EnableInterrupts(PMU_Type *base, uint32_t mask)
{
    base->PMU_DIG_IRQ_EN_REG |= mask;
}

void PMU_DisableInterrupts(PMU_Type *base, uint32_t mask)
{
    base->PMU_DIG_IRQ_EN_REG &= ~mask;
}

void PMU_ClearInterruptStatusFlags(PMU_Type *base, uint32_t clearMask)
{
    base->PMU_DIG_IRQ_FLAG_CLEAR_REG = clearMask;
}

uint32_t PMU_GetInterruptStatusFlags(PMU_Type *base)
{
    return base->PMU_DIG_IRQ_FLAG_REG;
}

uint32_t PMU_GetInterruptStatus(PMU_Type *base)
{
    return base->PMU_DIG_IRQ_STATUS_STS;
}
