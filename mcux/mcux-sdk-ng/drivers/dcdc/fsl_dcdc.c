/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dcdc.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dcdc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for DCDC module.
 *
 * @param base DCDC peripheral base address
 */
static uint32_t DCDC_GetInstance(DCDC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to DCDC bases for each instance. */
static DCDC_Type *const s_dcdcBases[] = DCDC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to DCDC clocks for each instance. */
static const clock_ip_name_t s_dcdcClocks[] = DCDC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t DCDC_GetInstance(DCDC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_dcdcBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_dcdcBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_dcdcBases));

    return instance;
}

/*!
 * brief Enable the access to DCDC registers.
 *
 * param base   DCDC peripheral base address.
 */
void DCDC_Init(DCDC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_dcdcClocks[DCDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Disable the access to DCDC registers.
 *
 * param base DCDC peripheral base address.
 */
void DCDC_Deinit(DCDC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_dcdcClocks[DCDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Get status flags.
 *
 * brief base DCDC peripheral base address.
 * return Masks of asserted status flags. See to "_dcdc_status_flags_t".
 */
uint32_t DCDC_GetStatusFlags(DCDC_Type *base)
{
    uint32_t tmp32 = 0U;

    /* kDCDC_LockedOKStatus. */
    if (0U != (DCDC_REG0_DCDC_STS_DC_OK_MASK & base->REG0))
    {
        tmp32 |= (uint32_t)kDCDC_LockedOKStatus;
    }
    /* kDCDC_PSwitchStatus. */
    if (0U != (DCDC_REG0_PSWITCH_STATUS_MASK & base->REG0))
    {
        tmp32 |= (uint32_t)kDCDC_PSwitchStatus;
    }
    /* kDCDC_PSwitchInterruptStatus. */
    if (0U != (DCDC_REG6_PSWITCH_INT_STS_MASK & base->REG6))
    {
        tmp32 |= (uint32_t)kDCDC_PSwitchInterruptStatus;
    }

    return tmp32;
}

/*!
 * brief Clear status flags.
 *
 * brief base DCDC peripheral base address.
 * brief mask Mask of status values that would be cleared. See to "_dcdc_status_flags_t".
 */
void DCDC_ClearStatusFlags(DCDC_Type *base, uint32_t mask) /* Clear flags indicated by mask. */
{
    if (0U != ((uint32_t)kDCDC_PSwitchInterruptStatus & mask))
    {
        /* Write 1 to clear interrupt. Set to 0 after clear. */
        base->REG6 |= DCDC_REG6_PSWITCH_INT_CLEAR_MASK;
        base->REG6 &= ~DCDC_REG6_PSWITCH_INT_CLEAR_MASK;
    }
}

/*!
 * brief Configure the PSWITCH interrupts.
 *
 * There are PSWITCH interrupt events can be triggered by falling edge or rising edge. So user can set the interrupt
 * events that would be triggered with this function. Un-asserted events would be disabled. The interrupt of PSwitch
 * should be enabled as well if to sense the PSWTICH event.
 * By default, no interrupt events would be enabled.
 *
 * param base DCDC peripheral base address.
 * param mask Mask of interrupt events for PSwtich. See to "_dcdc_pswitch_detect_event_t".
 */
void DCDC_SetPSwitchInterruptConfig(DCDC_Type *base, uint32_t mask)
{
    assert(0U == (mask & ~(DCDC_REG6_PSWITCH_INT_RISE_EN_MASK | DCDC_REG6_PSWITCH_INT_FALL_EN_MASK)));

    uint32_t tmp32 = base->REG6 & ~(DCDC_REG6_PSWITCH_INT_RISE_EN_MASK | DCDC_REG6_PSWITCH_INT_FALL_EN_MASK);

    tmp32 |= mask;
    base->REG6 = tmp32;
}

/*!
 * brief Get the default setting for low power configuration.
 *
 * The default configuration are set according to responding registers' setting when powered on.
 * They are:
 * code
 *   config->workModeInVLPRW = kDCDC_WorkInPulsedMode;
 *   config->workModeInVLPS = kDCDC_WorkInPulsedMode;
 *   config->enableHysteresisVoltageSense = true;
 *   config->enableAdjustHystereticValueSense = false;
 *   config->enableHystersisComparator = true;
 *   config->enableAdjustHystereticValueComparator = false;
 *   config->hystereticUpperThresholdValue = kDCDC_HystereticThresholdOffset75mV;
 *   config->hystereticLowerThresholdValue = kDCDC_HystereticThresholdOffset0mV;
 *   config->enableDiffComparators = false;
 * endcode
 *
 * param config Pointer to configuration structure. See to "dcdc_low_power_config_t".
 */
void DCDC_GetDefaultLowPowerConfig(dcdc_low_power_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->workModeInVLPRW                       = kDCDC_WorkInPulsedMode;
    config->workModeInVLPS                        = kDCDC_WorkInPulsedMode;
    config->enableHysteresisVoltageSense          = true;
    config->enableAdjustHystereticValueSense      = false;
    config->enableHystersisComparator             = true;
    config->enableAdjustHystereticValueComparator = false;
    config->hystereticUpperThresholdValue         = kDCDC_HystereticThresholdOffset75mV;
    config->hystereticLowerThresholdValue         = kDCDC_HystereticThresholdOffset0mV;
    config->enableDiffComparators                 = false;
}

/*!
 * brief Configure the low power for DCDC.
 *
 * param base DCDC peripheral base address.
 * param config Pointer to configuration structure. See to "dcdc_low_power_config_t".
 */
void DCDC_SetLowPowerConfig(DCDC_Type *base, const dcdc_low_power_config_t *config)
{
    uint32_t tmp32;

    tmp32 = base->REG0 & ~(DCDC_REG0_VLPR_VLPW_CONFIG_DCDC_HP_MASK | DCDC_REG0_VLPS_CONFIG_DCDC_HP_MASK |
                           DCDC_REG0_OFFSET_RSNS_LP_DISABLE_MASK | DCDC_REG0_OFFSET_RSNS_LP_ADJ_MASK |
                           DCDC_REG0_HYST_LP_CMP_DISABLE_MASK | DCDC_REG0_HYST_LP_COMP_ADJ_MASK |
                           DCDC_REG0_DCDC_LP_STATE_HYS_H_MASK | DCDC_REG0_DCDC_LP_STATE_HYS_L_MASK |
                           DCDC_REG0_DCDC_LP_DF_CMP_ENABLE_MASK);
    if (kDCDC_WorkInContinuousMode == config->workModeInVLPRW)
    {
        tmp32 |= DCDC_REG0_VLPR_VLPW_CONFIG_DCDC_HP_MASK;
    }
    if (kDCDC_WorkInContinuousMode == config->workModeInVLPS)
    {
        tmp32 |= DCDC_REG0_VLPS_CONFIG_DCDC_HP_MASK;
    }
    if (false == config->enableHysteresisVoltageSense)
    {
        tmp32 |= DCDC_REG0_OFFSET_RSNS_LP_DISABLE_MASK;
    }
    if (true == config->enableAdjustHystereticValueSense)
    {
        tmp32 |= DCDC_REG0_OFFSET_RSNS_LP_ADJ_MASK;
    }
    if (false == config->enableHystersisComparator)
    {
        tmp32 |= DCDC_REG0_HYST_LP_CMP_DISABLE_MASK;
    }
    if (true == config->enableAdjustHystereticValueComparator)
    {
        tmp32 |= DCDC_REG0_HYST_LP_COMP_ADJ_MASK;
    }
    tmp32 |= DCDC_REG0_DCDC_LP_STATE_HYS_H(config->hystereticUpperThresholdValue) |
             DCDC_REG0_DCDC_LP_STATE_HYS_L(config->hystereticLowerThresholdValue);
    /* true  - DCDC compare the lower supply(relative to target value) with DCDC_LP_STATE_HYS_L. When it is lower than
     *         DCDC_LP_STATE_HYS_L, re-charge output.
     * false - DCDC compare the common mode sense of supply(relative to target value) with DCDC_LP_STATE_HYS_L. When it
     *         is lower than DCDC_LP_STATE_HYS_L, re-charge output.
     */
    if (true == config->enableDiffComparators)
    {
        tmp32 |= DCDC_REG0_DCDC_LP_DF_CMP_ENABLE_MASK;
    }

    base->REG0 = tmp32;
}

/*!
 * brief Get the default setting for loop control configuration.
 *
 * The default configuration are set according to responding registers' setting when powered on.
 * They are:
 * code
 *   config->enableDiffHysteresis = false;
 *   config->enableCommonHysteresis = false;
 *   config->enableDiffHysteresisThresh = false;
 *   config->enableCommonHysteresisThresh = false;
 *   config->enableInvertHysteresisSign = false;
 * endcode
 *
 * param config Pointer to configuration structure. See to "dcdc_loop_control_config_t".
 */
void DCDC_GetDefaultLoopControlConfig(dcdc_loop_control_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableDiffHysteresis         = false;
    config->enableCommonHysteresis       = false;
    config->enableDiffHysteresisThresh   = false;
    config->enableCommonHysteresisThresh = false;
    config->enableInvertHysteresisSign   = false;
}

/*!
 * brief Configure the loop control for DCDC.
 *
 * param base DCDC peripheral base address.
 * param config Pointer to configuration structure. See to "dcdc_loop_control_config_t".
 */
void DCDC_SetLoopControlConfig(DCDC_Type *base, const dcdc_loop_control_config_t *config)
{
    uint32_t tmp32;

    /* DCDC_REG1. */
    tmp32 = base->REG1 & ~(DCDC_REG1_DCDC_LOOPCTRL_EN_DF_HYST_MASK | DCDC_REG1_DCDC_LOOPCTRL_EN_CM_HYST_MASK |
                           DCDC_REG1_DCDC_LOOPCTRL_DF_HST_THRESH_MASK | DCDC_REG1_DCDC_LOOPCTRL_CM_HST_THRESH_MASK);
    if (true == config->enableDiffHysteresis)
    {
        tmp32 |= DCDC_REG1_DCDC_LOOPCTRL_EN_DF_HYST_MASK;
    }
    if (true == config->enableCommonHysteresis)
    {
        tmp32 |= DCDC_REG1_DCDC_LOOPCTRL_EN_CM_HYST_MASK;
    }
    if (true == config->enableDiffHysteresisThresh)
    {
        tmp32 |= DCDC_REG1_DCDC_LOOPCTRL_DF_HST_THRESH_MASK;
    }
    if (true == config->enableCommonHysteresisThresh)
    {
        tmp32 |= DCDC_REG1_DCDC_LOOPCTRL_CM_HST_THRESH_MASK;
    }
    base->REG1 = tmp32;

    /* DCDC_REG2. */
    if (true == config->enableInvertHysteresisSign)
    {
        base->REG2 |= DCDC_REG2_DCDC_LOOPCTRL_HYST_SIGN_MASK;
    }
    else
    {
        base->REG2 &= ~DCDC_REG2_DCDC_LOOPCTRL_HYST_SIGN_MASK;
    }
}

/*!
 * brief Set the clock source for DCDC.
 *
 * This function is to set the clock source for DCDC. By default, DCDC can switch the clock from internal oscillator to
 * external clock automatically. Once the application choose to use the external clock with function, the internal
 * oscillator would be powered down. However, the internal oscillator could be powered down only when 32MHz crystal
 * oscillator is available.
 *
 * param base DCDC peripheral base address.
 * param clockSource Clock source for DCDC. See to "dcdc_clock_source_t".
 */
void DCDC_SetClockSource(DCDC_Type *base, dcdc_clock_source_t clockSource)
{
    uint32_t tmp32;

    tmp32 = base->REG0 & ~(DCDC_REG0_DCDC_PWD_OSC_INT_MASK | DCDC_REG0_DCDC_SEL_CLK_MASK |
                           DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK);
    switch (clockSource)
    {
        case kDCDC_ClockInternalOsc:
            tmp32 |= DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK;
            break;
        case kDCDC_ClockExternalOsc:
            /* Choose the external clock and disable the internal clock. */
            tmp32 |= DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK | DCDC_REG0_DCDC_SEL_CLK_MASK |
                     DCDC_REG0_DCDC_PWD_OSC_INT_MASK;
            break;
        case kDCDC_ClockAutoSwitch:
            tmp32 &= ~DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
    base->REG0 = tmp32;
}

/*!
 * @brief Adjust the target voltage of DCDC output.
 * @deprecated Do not use this function. It has been superceded by @ref DCDC_AdjustRunTargetVoltage
 * and @ref DCDC_AdjustLowPowerTargetVoltage
 *
 * This function is to adjust the target voltage of DCDC output. It would unlock the setting of target voltages, change
 * them and finally wait until the output is stabled.
 *
 * @param base DCDC peripheral base address.
 * @param vdd1p5xBoost Target value of VDD1P5X in boost mode, 25 mV each step from 0x00 to 0x0F. 0x00 is for 1.275V.
 * @param vdd1p5xBuck Target value of VDD1P5X in buck mode, 25 mV each step from 0x00 to 0x0F. 0x00 is for 1.275V.
 * @param vdd1p8 Target value of VDD1P8, 25 mV each step in two ranges, from 0x00 to 0x11 and 0x20 to 0x3F.
 *               0x00 is for 1.65V, 0x20 is for 2.8V.
 */
void DCDC_AdjustTargetVoltage(DCDC_Type *base,
#if (!defined(FSL_FEATURE_DCDC_HAS_BOOST_MODE) || (FSL_FEATURE_DCDC_HAS_BOOST_MODE == 1))
                              uint32_t vdd1p5xBoost,
#endif
                              uint32_t vdd1p5xBuck,
                              uint32_t vdd1p8)
{
    uint32_t tmp32;

    /* Unlock the limitation of setting target voltage. */
    base->REG3 &= ~(DCDC_REG3_DCDC_VDD1P8CTRL_DISABLE_STEP_MASK | DCDC_REG3_DCDC_VDD1P5XCTRL_DISABLE_STEP_MASK);
    /* Change the target voltage value. */
    tmp32 = base->REG3 & ~(
#if (!defined(FSL_FEATURE_DCDC_HAS_BOOST_MODE) || (FSL_FEATURE_DCDC_HAS_BOOST_MODE == 1))
                             DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BOOST_MASK |
#endif
                             DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BUCK_MASK | DCDC_REG3_DCDC_VDD1P8CTRL_TRG_MASK);
    tmp32 |=
#if (!defined(FSL_FEATURE_DCDC_HAS_BOOST_MODE) || (FSL_FEATURE_DCDC_HAS_BOOST_MODE == 1))
        DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BOOST(vdd1p5xBoost) |
#endif
        DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BUCK(vdd1p5xBuck) | DCDC_REG3_DCDC_VDD1P8CTRL_TRG(vdd1p8);
    base->REG3 = tmp32;

    /* DCDC_STS_DC_OK bit will be de-asserted after target register changes. After output voltage settling to new
     * target value, DCDC_STS_DC_OK will be asserted. */
    while (DCDC_REG0_DCDC_STS_DC_OK_MASK != (DCDC_REG0_DCDC_STS_DC_OK_MASK & base->REG0))
    {
    }
}

/*!
 * @brief Adjust the regular target voltage of DCDC output.
 *
 * This function is to adjust the target voltage of DCDC output. It would unlock the setting of target voltages, change
 * them and finally wait until the output is stabled.
 *
 * @param base DCDC peripheral base address.
 * @param vdd1p8 Target value of VDD1P8, 25 mV each step in two ranges, from 0x00 to 0x11 and 0x20 to 0x3F.
 *               0x00 is for 1.65V, 0x20 is for 2.8V.
 */
void DCDC_AdjustRunTargetVoltage(DCDC_Type *base, uint32_t vdd1p8)
{
    uint32_t tmp32;

    /* Unlock the limitation of setting target voltage. */
    base->REG3 &= ~DCDC_REG3_DCDC_VDD1P8CTRL_DISABLE_STEP_MASK;
    /* Change the target voltage value. */
    tmp32 = base->REG3 & ~DCDC_REG3_DCDC_VDD1P8CTRL_TRG_MASK;
    tmp32 |= DCDC_REG3_DCDC_VDD1P8CTRL_TRG(vdd1p8);
    base->REG3 = tmp32;

    /* DCDC_STS_DC_OK bit will be de-asserted after target register changes. After output voltage settling to new
     * target value, DCDC_STS_DC_OK will be asserted. */
    while (DCDC_REG0_DCDC_STS_DC_OK_MASK != (DCDC_REG0_DCDC_STS_DC_OK_MASK & base->REG0))
    {
    }
}

/*!
 * @brief Adjust the low power target voltage of DCDC output.
 *
 * This function is to adjust the target voltage of DCDC output. It would unlock the setting of target voltages, change
 * them and finally wait until the output is stabled.
 *
 * @param base DCDC peripheral base address.
 * @param vdd1p5xBoost Target value of VDD1P5X in boost mode, 25 mV each step from 0x00 to 0x0F. 0x00 is for 1.275V.
 * @param vdd1p5xBuck Target value of VDD1P5X in buck mode, 25 mV each step from 0x00 to 0x0F. 0x00 is for 1.275V.
 */
void DCDC_AdjustLowPowerTargetVoltage(DCDC_Type *base,
#if (!defined(FSL_FEATURE_DCDC_HAS_BOOST_MODE) || (FSL_FEATURE_DCDC_HAS_BOOST_MODE == 1))
                                      uint32_t vdd1p5xBoost,
#endif
                                      uint32_t vdd1p5xBuck)
{
    uint32_t tmp32;

    /* Unlock the limitation of setting target voltage. */
    base->REG3 &= ~DCDC_REG3_DCDC_VDD1P5XCTRL_DISABLE_STEP_MASK;
    /* Change the target voltage value. */
    tmp32 = base->REG3 & ~(
#if (!defined(FSL_FEATURE_DCDC_HAS_BOOST_MODE) || (FSL_FEATURE_DCDC_HAS_BOOST_MODE == 1))
                             DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BOOST_MASK |
#endif
                             DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BUCK_MASK);
    tmp32 |=
#if (!defined(FSL_FEATURE_DCDC_HAS_BOOST_MODE) || (FSL_FEATURE_DCDC_HAS_BOOST_MODE == 1))
        DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BOOST(vdd1p5xBoost) |
#endif
        DCDC_REG3_DCDC_VDD1P5XCTRL_TRG_BUCK(vdd1p5xBuck);
    base->REG3 = tmp32;

    /* DCDC_STS_DC_OK bit will be de-asserted after target register changes. After output voltage settling to new
     * target value, DCDC_STS_DC_OK will be asserted. */
    while (DCDC_REG0_DCDC_STS_DC_OK_MASK != (DCDC_REG0_DCDC_STS_DC_OK_MASK & base->REG0))
    {
    }
}

/*!
 * brief Set battery monitor value.
 *
 * This function is to set the battery monitor value. If the feature of monitoring battery voltage is enabled (with
 * non-zero value set), user should set the battery voltage measured with an 8 mV LSB resolution from the ADC sample
 * channel. It would improve efficiency and minimize ripple.
 *
 * param base DCDC peripheral base address.
 * param battValue Battery voltage measured with an 8 mV LSB resolution with 10-bit ADC sample. Setting 0x0 would
 *                  disable feature of monitoring battery voltage.
 */
void DCDC_SetBatteryMonitorValue(DCDC_Type *base, uint32_t battValue)
{
    uint32_t tmp32;

    /* Disable the monitor before setting the new value */
    base->REG2 &= ~DCDC_REG2_DCDC_BATTMONITOR_EN_BATADJ_MASK;
    if (0U != battValue)
    {
        tmp32 = base->REG2 & ~DCDC_REG2_DCDC_BATTMONITOR_BATT_VAL_MASK;
        /* Enable the monitor with setting value. */
        tmp32 |= (DCDC_REG2_DCDC_BATTMONITOR_EN_BATADJ_MASK | DCDC_REG2_DCDC_BATTMONITOR_BATT_VAL(battValue));
        base->REG2 = tmp32;
    }
}

/*!
 * brief Configure for the min power.
 *
 * param base DCDC peripheral base address.
 * param config Pointer to configuration structure. See to "dcdc_min_power_config_t".
 */
void DCDC_SetMinPowerConfig(DCDC_Type *base, const dcdc_min_power_config_t *config)
{
    uint32_t tmp32 =
        base->REG3 & ~(DCDC_REG3_DCDC_MINPWR_HALF_FETS_MASK | DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_MASK |
                       DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_MASK | DCDC_REG3_DCDC_MINPWR_HALF_FETS_PULSED_MASK |
                       DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_PULSED_MASK | DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_PULSED_MASK);

    /* For Continuous mode. */
    if (true == config->enableUseHalfFetForContinuous)
    {
        tmp32 |= DCDC_REG3_DCDC_MINPWR_HALF_FETS_MASK;
    }
    if (true == config->enableUseDoubleFetForContinuous)
    {
        tmp32 |= DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_MASK;
    }
    if (true == config->enableUseHalfFreqForContinuous)
    {
        tmp32 |= DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_MASK;
    }
    /* For Pulsed mode. */
    if (true == config->enableUseHalfFetForPulsed)
    {
        tmp32 |= DCDC_REG3_DCDC_MINPWR_HALF_FETS_PULSED_MASK;
    }
    if (true == config->enableUseDoubleFetForPulsed)
    {
        tmp32 |= DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_PULSED_MASK;
    }
    if (true == config->enableUseHalfFreqForPulsed)
    {
        tmp32 |= DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_PULSED_MASK;
    }
    base->REG3 = tmp32;
}

/*!
 * brief Get the default configuration for min power.
 *
 * The default configuration are set according to responding registers' setting when powered on.
 * They are:
 * code
 *   config->enableUseHalfFetForContinuous = false;
 *   config->enableUseDoubleFetForContinuous = false;
 *   config->enableUseHalfFreqForContinuous = false;
 *   config->enableUseHalfFetForPulsed = false;
 *   config->enableUseDoubleFetForPulsed = false;
 *   config->enableUseHalfFreqForPulsed = false;
 * endcode
 *
 * param config Pointer to configuration structure. See to "dcdc_min_power_config_t".
 */
void DCDC_GetDefaultMinPowerDefault(dcdc_min_power_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* For Continuous mode. */
    config->enableUseHalfFetForContinuous   = false;
    config->enableUseDoubleFetForContinuous = false;
    config->enableUseHalfFreqForContinuous  = false;
    /* For Pulsed mode. */
    config->enableUseHalfFetForPulsed   = false;
    config->enableUseDoubleFetForPulsed = false;
    config->enableUseHalfFreqForPulsed  = false;
}

/*!
 * brief Configure the integrator in pulsed mode.
 *
 * param base DCDC peripheral base address.
 * config Pointer to configuration structure. See to "dcdc_pulsed_integrator_config_t".
 */
void DCDC_SetPulsedIntegratorConfig(DCDC_Type *base, const dcdc_pulsed_integrator_config_t *config)
{
    if (true == config->enableUseUserIntegratorValue) /* Enable to use the user integrator value. */
    {
        base->REG7 = (base->REG7 & ~DCDC_REG7_INTEGRATOR_VALUE_MASK) | DCDC_REG7_INTEGRATOR_VALUE_SEL_MASK |
                     DCDC_REG7_INTEGRATOR_VALUE(config->userIntegratorValue);
        if (true == config->enablePulseRunSpeedup)
        {
            base->REG7 |= DCDC_REG7_PULSE_RUN_SPEEDUP_MASK;
        }
    }
    else
    {
        base->REG7 = 0U;
    }
}

/*!
 * brief Get the default setting for integrator configuration in pulsed mode.
 *
 * The default configuration are set according to responding registers' setting when powered on.
 * They are:
 * code
 *   config->enableUseUserIntegratorValue = false;
 *   config->userIntegratorValue = 0U;
 *   config->enablePulseRunSpeedup = false;
 * endcode
 *
 * param config Pointer to configuration structure. See to "dcdc_pulsed_integrator_config_t".
 */
void DCDC_GetDefaultPulsedIntegratorConfig(dcdc_pulsed_integrator_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableUseUserIntegratorValue = false;
    config->userIntegratorValue          = 0U;
    config->enablePulseRunSpeedup        = false;
}
