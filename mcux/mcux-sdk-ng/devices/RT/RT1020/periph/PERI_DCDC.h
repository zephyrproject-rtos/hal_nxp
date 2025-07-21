/*
** ###################################################################
**     Processors:          MIMXRT1021CAF4A
**                          MIMXRT1021CAF4B
**                          MIMXRT1021CAG4A
**                          MIMXRT1021CAG4B
**                          MIMXRT1021DAF5A
**                          MIMXRT1021DAF5B
**                          MIMXRT1021DAG5A
**                          MIMXRT1021DAG5B
**                          MIMXRT1024CAG4A
**                          MIMXRT1024CAG4B
**                          MIMXRT1024DAG5A
**                          MIMXRT1024DAG5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DCDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-11-06)
**         Initial version.
**     - rev. 1.0 (2018-11-27)
**         Update header files to align with IMXRT1020RM Rev.1.
**     - rev. 1.1 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1020RM Rev.2.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DCDC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DCDC
 *
 * CMSIS Peripheral Access Layer for DCDC
 */

#if !defined(PERI_DCDC_H_)
#define PERI_DCDC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1021CAF4A) || defined(CPU_MIMXRT1021CAF4B) || defined(CPU_MIMXRT1021CAG4A) || defined(CPU_MIMXRT1021CAG4B) || defined(CPU_MIMXRT1021DAF5A) || defined(CPU_MIMXRT1021DAF5B) || defined(CPU_MIMXRT1021DAG5A) || defined(CPU_MIMXRT1021DAG5B))
#include "MIMXRT1021_COMMON.h"
#elif (defined(CPU_MIMXRT1024CAG4A) || defined(CPU_MIMXRT1024CAG4B) || defined(CPU_MIMXRT1024DAG5A) || defined(CPU_MIMXRT1024DAG5B))
#include "MIMXRT1024_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DCDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCDC_Peripheral_Access_Layer DCDC Peripheral Access Layer
 * @{
 */

/** DCDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG0;                              /**< DCDC Register 0, offset: 0x0 */
  __IO uint32_t REG1;                              /**< DCDC Register 1, offset: 0x4 */
  __IO uint32_t REG2;                              /**< DCDC Register 2, offset: 0x8 */
  __IO uint32_t REG3;                              /**< DCDC Register 3, offset: 0xC */
} DCDC_Type;

/* ----------------------------------------------------------------------------
   -- DCDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCDC_Register_Masks DCDC Register Masks
 * @{
 */

/*! @name REG0 - DCDC Register 0 */
/*! @{ */

#define DCDC_REG0_PWD_ZCD_MASK                   (0x1U)
#define DCDC_REG0_PWD_ZCD_SHIFT                  (0U)
/*! PWD_ZCD - Power Down Zero Cross Detection
 *  0b0..Zero cross detetion function powered up
 *  0b1..Zero cross detetion function powered down
 */
#define DCDC_REG0_PWD_ZCD(x)                     (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_ZCD_SHIFT)) & DCDC_REG0_PWD_ZCD_MASK)

#define DCDC_REG0_DISABLE_AUTO_CLK_SWITCH_MASK   (0x2U)
#define DCDC_REG0_DISABLE_AUTO_CLK_SWITCH_SHIFT  (1U)
/*! DISABLE_AUTO_CLK_SWITCH - Disable Auto Clock Switch
 *  0b0..If DISABLE_AUTO_CLK_SWITCH is set to 0 and 24M xtal is OK, the clock source will switch from internal ring OSC to 24M xtal automatically
 *  0b1..If DISABLE_AUTO_CLK_SWITCH is set to 1, SEL_CLK will determine which clock source the DCDC uses
 */
#define DCDC_REG0_DISABLE_AUTO_CLK_SWITCH(x)     (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DISABLE_AUTO_CLK_SWITCH_SHIFT)) & DCDC_REG0_DISABLE_AUTO_CLK_SWITCH_MASK)

#define DCDC_REG0_SEL_CLK_MASK                   (0x4U)
#define DCDC_REG0_SEL_CLK_SHIFT                  (2U)
/*! SEL_CLK - Select Clock
 *  0b0..DCDC uses internal ring oscillator
 *  0b1..DCDC uses 24M xtal
 */
#define DCDC_REG0_SEL_CLK(x)                     (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_SEL_CLK_SHIFT)) & DCDC_REG0_SEL_CLK_MASK)

#define DCDC_REG0_PWD_OSC_INT_MASK               (0x8U)
#define DCDC_REG0_PWD_OSC_INT_SHIFT              (3U)
/*! PWD_OSC_INT - Power down internal osc
 *  0b0..Internal oscillator powered up
 *  0b1..Internal oscillator powered down
 */
#define DCDC_REG0_PWD_OSC_INT(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_OSC_INT_SHIFT)) & DCDC_REG0_PWD_OSC_INT_MASK)

#define DCDC_REG0_PWD_CUR_SNS_CMP_MASK           (0x10U)
#define DCDC_REG0_PWD_CUR_SNS_CMP_SHIFT          (4U)
/*! PWD_CUR_SNS_CMP - Power down signal of the current detector.
 *  0b0..Current Detector powered up
 *  0b1..Current Detector powered down
 */
#define DCDC_REG0_PWD_CUR_SNS_CMP(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_CUR_SNS_CMP_SHIFT)) & DCDC_REG0_PWD_CUR_SNS_CMP_MASK)

#define DCDC_REG0_CUR_SNS_THRSH_MASK             (0xE0U)
#define DCDC_REG0_CUR_SNS_THRSH_SHIFT            (5U)
/*! CUR_SNS_THRSH - Current Sense (detector) Threshold
 *  0b000..150 mA
 *  0b001..250 mA
 *  0b010..350 mA
 *  0b011..450 mA
 *  0b100..550 mA
 *  0b101..650 mA
 */
#define DCDC_REG0_CUR_SNS_THRSH(x)               (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_CUR_SNS_THRSH_SHIFT)) & DCDC_REG0_CUR_SNS_THRSH_MASK)

#define DCDC_REG0_PWD_OVERCUR_DET_MASK           (0x100U)
#define DCDC_REG0_PWD_OVERCUR_DET_SHIFT          (8U)
/*! PWD_OVERCUR_DET - Power down overcurrent detection comparator
 *  0b0..Overcurrent detection comparator is enabled
 *  0b1..Overcurrent detection comparator is disabled
 */
#define DCDC_REG0_PWD_OVERCUR_DET(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_OVERCUR_DET_SHIFT)) & DCDC_REG0_PWD_OVERCUR_DET_MASK)

#define DCDC_REG0_OVERCUR_TRIG_ADJ_MASK          (0x600U)
#define DCDC_REG0_OVERCUR_TRIG_ADJ_SHIFT         (9U)
/*! OVERCUR_TRIG_ADJ - Overcurrent Trigger Adjust
 *  0b00..In Run Mode, 1 A. In Power Save Mode, 0.25 A
 *  0b01..In Run Mode, 2 A. In Power Save Mode, 0.25 A
 *  0b10..In Run Mode, 1 A. In Power Save Mode, 0.2 A
 *  0b11..In Run Mode, 2 A. In Power Save Mode, 0.2 A
 */
#define DCDC_REG0_OVERCUR_TRIG_ADJ(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_OVERCUR_TRIG_ADJ_SHIFT)) & DCDC_REG0_OVERCUR_TRIG_ADJ_MASK)

#define DCDC_REG0_PWD_CMP_BATT_DET_MASK          (0x800U)
#define DCDC_REG0_PWD_CMP_BATT_DET_SHIFT         (11U)
/*! PWD_CMP_BATT_DET - Power Down Battery Detection Comparator
 *  0b0..Low voltage detection comparator is enabled
 *  0b1..Low voltage detection comparator is disabled
 */
#define DCDC_REG0_PWD_CMP_BATT_DET(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_CMP_BATT_DET_SHIFT)) & DCDC_REG0_PWD_CMP_BATT_DET_MASK)

#define DCDC_REG0_EN_LP_OVERLOAD_SNS_MASK        (0x10000U)
#define DCDC_REG0_EN_LP_OVERLOAD_SNS_SHIFT       (16U)
/*! EN_LP_OVERLOAD_SNS - Low Power Overload Sense Enable
 *  0b0..Overload Detection in power save mode disabled
 *  0b1..Overload Detection in power save mode enabled
 */
#define DCDC_REG0_EN_LP_OVERLOAD_SNS(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_EN_LP_OVERLOAD_SNS_SHIFT)) & DCDC_REG0_EN_LP_OVERLOAD_SNS_MASK)

#define DCDC_REG0_PWD_HIGH_VOLT_DET_MASK         (0x20000U)
#define DCDC_REG0_PWD_HIGH_VOLT_DET_SHIFT        (17U)
/*! PWD_HIGH_VOLT_DET - Power Down High Voltage Detection
 *  0b0..Overvoltage detection comparator is enabled
 *  0b1..Overvoltage detection comparator is disabled
 */
#define DCDC_REG0_PWD_HIGH_VOLT_DET(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_HIGH_VOLT_DET_SHIFT)) & DCDC_REG0_PWD_HIGH_VOLT_DET_MASK)

#define DCDC_REG0_LP_OVERLOAD_THRSH_MASK         (0xC0000U)
#define DCDC_REG0_LP_OVERLOAD_THRSH_SHIFT        (18U)
/*! LP_OVERLOAD_THRSH - Low Power Overload Threshold
 *  0b00..32
 *  0b01..64
 *  0b10..16
 *  0b11..8
 */
#define DCDC_REG0_LP_OVERLOAD_THRSH(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_LP_OVERLOAD_THRSH_SHIFT)) & DCDC_REG0_LP_OVERLOAD_THRSH_MASK)

#define DCDC_REG0_LP_OVERLOAD_FREQ_SEL_MASK      (0x100000U)
#define DCDC_REG0_LP_OVERLOAD_FREQ_SEL_SHIFT     (20U)
/*! LP_OVERLOAD_FREQ_SEL - Low Power Overload Frequency Select
 *  0b0..eight 32k cycle
 *  0b1..sixteen 32k cycle
 */
#define DCDC_REG0_LP_OVERLOAD_FREQ_SEL(x)        (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_LP_OVERLOAD_FREQ_SEL_SHIFT)) & DCDC_REG0_LP_OVERLOAD_FREQ_SEL_MASK)

#define DCDC_REG0_LP_HIGH_HYS_MASK               (0x200000U)
#define DCDC_REG0_LP_HIGH_HYS_SHIFT              (21U)
/*! LP_HIGH_HYS - Low Power High Hysteric Value
 *  0b0..Adjust hysteretic value in low power to 12.5mV
 *  0b1..Adjust hysteretic value in low power to 25mV
 */
#define DCDC_REG0_LP_HIGH_HYS(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_LP_HIGH_HYS_SHIFT)) & DCDC_REG0_LP_HIGH_HYS_MASK)

#define DCDC_REG0_PWD_CMP_OFFSET_MASK            (0x4000000U)
#define DCDC_REG0_PWD_CMP_OFFSET_SHIFT           (26U)
/*! PWD_CMP_OFFSET - Power down output range comparator
 *  0b0..Output range comparator powered up
 *  0b1..Output range comparator powered down
 */
#define DCDC_REG0_PWD_CMP_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_CMP_OFFSET_SHIFT)) & DCDC_REG0_PWD_CMP_OFFSET_MASK)

#define DCDC_REG0_XTALOK_DISABLE_MASK            (0x8000000U)
#define DCDC_REG0_XTALOK_DISABLE_SHIFT           (27U)
/*! XTALOK_DISABLE - Disable xtalok detection circuit
 *  0b0..Enable xtalok detection circuit
 *  0b1..Disable xtalok detection circuit and always outputs OK signal "1"
 */
#define DCDC_REG0_XTALOK_DISABLE(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_XTALOK_DISABLE_SHIFT)) & DCDC_REG0_XTALOK_DISABLE_MASK)

#define DCDC_REG0_CURRENT_ALERT_RESET_MASK       (0x10000000U)
#define DCDC_REG0_CURRENT_ALERT_RESET_SHIFT      (28U)
/*! CURRENT_ALERT_RESET - Reset Current Alert Signal
 *  0b0..Current Alert Signal not reset
 *  0b1..Current Alert Signal reset
 */
#define DCDC_REG0_CURRENT_ALERT_RESET(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_CURRENT_ALERT_RESET_SHIFT)) & DCDC_REG0_CURRENT_ALERT_RESET_MASK)

#define DCDC_REG0_XTAL_24M_OK_MASK               (0x20000000U)
#define DCDC_REG0_XTAL_24M_OK_SHIFT              (29U)
/*! XTAL_24M_OK - 24M XTAL OK
 *  0b0..DCDC uses internal ring OSC
 *  0b1..DCDC uses xtal 24M
 */
#define DCDC_REG0_XTAL_24M_OK(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_XTAL_24M_OK_SHIFT)) & DCDC_REG0_XTAL_24M_OK_MASK)

#define DCDC_REG0_STS_DC_OK_MASK                 (0x80000000U)
#define DCDC_REG0_STS_DC_OK_SHIFT                (31U)
/*! STS_DC_OK - DCDC Output OK
 *  0b0..DCDC is settling
 *  0b1..DCDC already settled
 */
#define DCDC_REG0_STS_DC_OK(x)                   (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_STS_DC_OK_SHIFT)) & DCDC_REG0_STS_DC_OK_MASK)
/*! @} */

/*! @name REG1 - DCDC Register 1 */
/*! @{ */

#define DCDC_REG1_REG_FBK_SEL_MASK               (0x180U)
#define DCDC_REG1_REG_FBK_SEL_SHIFT              (7U)
/*! REG_FBK_SEL
 *  0b00..The regulator outputs 1.0V with 1.2V reference voltage
 *  0b01..The regulator outputs 1.1V with 1.2V reference voltage
 *  0b10..The regulator outputs 1.0V with 1.3V reference voltage
 *  0b11..The regulator outputs 1.1V with 1.3V reference voltage
 */
#define DCDC_REG1_REG_FBK_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_REG_FBK_SEL_SHIFT)) & DCDC_REG1_REG_FBK_SEL_MASK)

#define DCDC_REG1_REG_RLOAD_SW_MASK              (0x200U)
#define DCDC_REG1_REG_RLOAD_SW_SHIFT             (9U)
/*! REG_RLOAD_SW
 *  0b0..Load resistor disconnected
 *  0b1..Load resistor connected
 */
#define DCDC_REG1_REG_RLOAD_SW(x)                (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_REG_RLOAD_SW_SHIFT)) & DCDC_REG1_REG_RLOAD_SW_MASK)

#define DCDC_REG1_LP_CMP_ISRC_SEL_MASK           (0x3000U)
#define DCDC_REG1_LP_CMP_ISRC_SEL_SHIFT          (12U)
/*! LP_CMP_ISRC_SEL - Low Power Comparator Current Bias
 *  0b00..50 nA
 *  0b01..100 nA
 *  0b10..200 nA
 *  0b11..400 nA
 */
#define DCDC_REG1_LP_CMP_ISRC_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_LP_CMP_ISRC_SEL_SHIFT)) & DCDC_REG1_LP_CMP_ISRC_SEL_MASK)

#define DCDC_REG1_LOOPCTRL_HST_THRESH_MASK       (0x200000U)
#define DCDC_REG1_LOOPCTRL_HST_THRESH_SHIFT      (21U)
/*! LOOPCTRL_HST_THRESH - Increase Threshold Detection
 *  0b0..Lower hysteresis threshold (about 2.5mV in typical, but this value can vary with PVT corners
 *  0b1..Higher hysteresis threshold (about 5mV in typical)
 */
#define DCDC_REG1_LOOPCTRL_HST_THRESH(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_LOOPCTRL_HST_THRESH_SHIFT)) & DCDC_REG1_LOOPCTRL_HST_THRESH_MASK)

#define DCDC_REG1_LOOPCTRL_EN_HYST_MASK          (0x800000U)
#define DCDC_REG1_LOOPCTRL_EN_HYST_SHIFT         (23U)
/*! LOOPCTRL_EN_HYST - Enable Hysteresis
 *  0b0..Disable hysteresis in switching converter common mode analog comparators
 *  0b1..Enable hysteresis in switching converter common mode analog comparators
 */
#define DCDC_REG1_LOOPCTRL_EN_HYST(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_LOOPCTRL_EN_HYST_SHIFT)) & DCDC_REG1_LOOPCTRL_EN_HYST_MASK)

#define DCDC_REG1_VBG_TRIM_MASK                  (0x1F000000U)
#define DCDC_REG1_VBG_TRIM_SHIFT                 (24U)
/*! VBG_TRIM - Trim Bandgap Voltage */
#define DCDC_REG1_VBG_TRIM(x)                    (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_VBG_TRIM_SHIFT)) & DCDC_REG1_VBG_TRIM_MASK)
/*! @} */

/*! @name REG2 - DCDC Register 2 */
/*! @{ */

#define DCDC_REG2_LOOPCTRL_DC_FF_MASK            (0x1C0U)
#define DCDC_REG2_LOOPCTRL_DC_FF_SHIFT           (6U)
#define DCDC_REG2_LOOPCTRL_DC_FF(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_DC_FF_SHIFT)) & DCDC_REG2_LOOPCTRL_DC_FF_MASK)

#define DCDC_REG2_LOOPCTRL_EN_RCSCALE_MASK       (0xE00U)
#define DCDC_REG2_LOOPCTRL_EN_RCSCALE_SHIFT      (9U)
/*! LOOPCTRL_EN_RCSCALE - Enable RC Scale */
#define DCDC_REG2_LOOPCTRL_EN_RCSCALE(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_EN_RCSCALE_SHIFT)) & DCDC_REG2_LOOPCTRL_EN_RCSCALE_MASK)

#define DCDC_REG2_LOOPCTRL_RCSCALE_THRSH_MASK    (0x1000U)
#define DCDC_REG2_LOOPCTRL_RCSCALE_THRSH_SHIFT   (12U)
/*! LOOPCTRL_RCSCALE_THRSH
 *  0b0..Do not increase the threshold detection for RC scale circuit.
 *  0b1..Increase the threshold detection for RC scale circuit.
 */
#define DCDC_REG2_LOOPCTRL_RCSCALE_THRSH(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_RCSCALE_THRSH_SHIFT)) & DCDC_REG2_LOOPCTRL_RCSCALE_THRSH_MASK)

#define DCDC_REG2_LOOPCTRL_HYST_SIGN_MASK        (0x2000U)
#define DCDC_REG2_LOOPCTRL_HYST_SIGN_SHIFT       (13U)
/*! LOOPCTRL_HYST_SIGN
 *  0b0..Do not invert sign of the hysteresis
 *  0b1..Invert sign of the hysteresis
 */
#define DCDC_REG2_LOOPCTRL_HYST_SIGN(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_HYST_SIGN_SHIFT)) & DCDC_REG2_LOOPCTRL_HYST_SIGN_MASK)

#define DCDC_REG2_DISABLE_PULSE_SKIP_MASK        (0x8000000U)
#define DCDC_REG2_DISABLE_PULSE_SKIP_SHIFT       (27U)
/*! DISABLE_PULSE_SKIP - Disable Pulse Skip
 *  0b0..DCDC will be idle to save current dissipation when the duty cycle get to the low limit which is set by NEGLIMIT_IN.
 *  0b1..DCDC will keep working with the low limited duty cycle NEGLIMIT_IN.
 */
#define DCDC_REG2_DISABLE_PULSE_SKIP(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_DISABLE_PULSE_SKIP_SHIFT)) & DCDC_REG2_DISABLE_PULSE_SKIP_MASK)

#define DCDC_REG2_DCM_SET_CTRL_MASK              (0x10000000U)
#define DCDC_REG2_DCM_SET_CTRL_SHIFT             (28U)
/*! DCM_SET_CTRL - DCM Set Control */
#define DCDC_REG2_DCM_SET_CTRL(x)                (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_DCM_SET_CTRL_SHIFT)) & DCDC_REG2_DCM_SET_CTRL_MASK)
/*! @} */

/*! @name REG3 - DCDC Register 3 */
/*! @{ */

#define DCDC_REG3_TRG_MASK                       (0x1FU)
#define DCDC_REG3_TRG_SHIFT                      (0U)
/*! TRG - Target value of VDD_SOC */
#define DCDC_REG3_TRG(x)                         (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_TRG_SHIFT)) & DCDC_REG3_TRG_MASK)

#define DCDC_REG3_TARGET_LP_MASK                 (0x700U)
#define DCDC_REG3_TARGET_LP_SHIFT                (8U)
/*! TARGET_LP - Low Power Target Value
 *  0b000..0.9 V
 *  0b001..0.925 V
 *  0b010..0.95 V
 *  0b011..0.975 V
 *  0b100..1.0 V
 */
#define DCDC_REG3_TARGET_LP(x)                   (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_TARGET_LP_SHIFT)) & DCDC_REG3_TARGET_LP_MASK)

#define DCDC_REG3_MINPWR_DC_HALFCLK_MASK         (0x1000000U)
#define DCDC_REG3_MINPWR_DC_HALFCLK_SHIFT        (24U)
/*! MINPWR_DC_HALFCLK
 *  0b0..DCDC clock remains at full frequency for continuous mode
 *  0b1..DCDC clock set to half frequency for continuous mode
 */
#define DCDC_REG3_MINPWR_DC_HALFCLK(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_MINPWR_DC_HALFCLK_SHIFT)) & DCDC_REG3_MINPWR_DC_HALFCLK_MASK)

#define DCDC_REG3_DISABLE_STEP_MASK              (0x40000000U)
#define DCDC_REG3_DISABLE_STEP_SHIFT             (30U)
/*! DISABLE_STEP - Disable Step
 *  0b0..Enable stepping for the output of VDD_SOC of DCDC
 *  0b1..Disable stepping for the output of VDD_SOC of DCDC
 */
#define DCDC_REG3_DISABLE_STEP(x)                (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DISABLE_STEP_SHIFT)) & DCDC_REG3_DISABLE_STEP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DCDC_Register_Masks */


/*!
 * @}
 */ /* end of group DCDC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DCDC_H_ */

