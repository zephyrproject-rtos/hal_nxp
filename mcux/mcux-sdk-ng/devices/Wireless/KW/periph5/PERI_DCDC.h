/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DCDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file DCDC.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for DCDC
 *
 * CMSIS Peripheral Access Layer for DCDC
 */

#if !defined(DCDC_H_)
#define DCDC_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
  __IO uint32_t REG0;                              /**< DCDC REGISTER 0, offset: 0x0 */
  __IO uint32_t REG1;                              /**< DCDC REGISTER 1, offset: 0x4 */
  __IO uint32_t REG2;                              /**< DCDC REGISTER 2, offset: 0x8 */
  __IO uint32_t REG3;                              /**< DCDC REGISTER 3, offset: 0xC */
  __IO uint32_t REG4;                              /**< DCDC REGISTER 4, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __IO uint32_t REG6;                              /**< DCDC REGISTER 6, offset: 0x18 */
  __IO uint32_t REG7;                              /**< DCDC REGISTER 7, offset: 0x1C */
} DCDC_Type;

/* ----------------------------------------------------------------------------
   -- DCDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCDC_Register_Masks DCDC Register Masks
 * @{
 */

/*! @name REG0 - DCDC REGISTER 0 */
/*! @{ */

#define DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK (0x2U)
#define DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_SHIFT (1U)
#define DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_SHIFT)) & DCDC_REG0_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK)

#define DCDC_REG0_DCDC_SEL_CLK_MASK              (0x4U)
#define DCDC_REG0_DCDC_SEL_CLK_SHIFT             (2U)
#define DCDC_REG0_DCDC_SEL_CLK(x)                (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_SEL_CLK_SHIFT)) & DCDC_REG0_DCDC_SEL_CLK_MASK)

#define DCDC_REG0_DCDC_PWD_OSC_INT_MASK          (0x8U)
#define DCDC_REG0_DCDC_PWD_OSC_INT_SHIFT         (3U)
#define DCDC_REG0_DCDC_PWD_OSC_INT(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_PWD_OSC_INT_SHIFT)) & DCDC_REG0_DCDC_PWD_OSC_INT_MASK)

#define DCDC_REG0_DCDC_LP_DF_CMP_ENABLE_MASK     (0x200U)
#define DCDC_REG0_DCDC_LP_DF_CMP_ENABLE_SHIFT    (9U)
#define DCDC_REG0_DCDC_LP_DF_CMP_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_LP_DF_CMP_ENABLE_SHIFT)) & DCDC_REG0_DCDC_LP_DF_CMP_ENABLE_MASK)

#define DCDC_REG0_DCDC_VBAT_DIV_CTRL_MASK        (0xC00U)
#define DCDC_REG0_DCDC_VBAT_DIV_CTRL_SHIFT       (10U)
#define DCDC_REG0_DCDC_VBAT_DIV_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_VBAT_DIV_CTRL_SHIFT)) & DCDC_REG0_DCDC_VBAT_DIV_CTRL_MASK)

#define DCDC_REG0_DCDC_LP_STATE_HYS_L_MASK       (0x60000U)
#define DCDC_REG0_DCDC_LP_STATE_HYS_L_SHIFT      (17U)
/*! DCDC_LP_STATE_HYS_L
 *  0b00..Target voltage value - 0 mV
 *  0b01..Target voltage value - 25 mV
 *  0b10..Target voltage value - 50 mV
 *  0b11..Target voltage value - 75 mV
 */
#define DCDC_REG0_DCDC_LP_STATE_HYS_L(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_LP_STATE_HYS_L_SHIFT)) & DCDC_REG0_DCDC_LP_STATE_HYS_L_MASK)

#define DCDC_REG0_DCDC_LP_STATE_HYS_H_MASK       (0x180000U)
#define DCDC_REG0_DCDC_LP_STATE_HYS_H_SHIFT      (19U)
/*! DCDC_LP_STATE_HYS_H
 *  0b00..Target voltage value + 0 mV
 *  0b01..Target voltage value + 25 mV
 *  0b10..Target voltage value + 50 mV
 *  0b11..Target voltage value + 75 mV
 */
#define DCDC_REG0_DCDC_LP_STATE_HYS_H(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_LP_STATE_HYS_H_SHIFT)) & DCDC_REG0_DCDC_LP_STATE_HYS_H_MASK)

#define DCDC_REG0_HYST_LP_COMP_ADJ_MASK          (0x200000U)
#define DCDC_REG0_HYST_LP_COMP_ADJ_SHIFT         (21U)
#define DCDC_REG0_HYST_LP_COMP_ADJ(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_HYST_LP_COMP_ADJ_SHIFT)) & DCDC_REG0_HYST_LP_COMP_ADJ_MASK)

#define DCDC_REG0_HYST_LP_CMP_DISABLE_MASK       (0x400000U)
#define DCDC_REG0_HYST_LP_CMP_DISABLE_SHIFT      (22U)
#define DCDC_REG0_HYST_LP_CMP_DISABLE(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_HYST_LP_CMP_DISABLE_SHIFT)) & DCDC_REG0_HYST_LP_CMP_DISABLE_MASK)

#define DCDC_REG0_OFFSET_RSNS_LP_ADJ_MASK        (0x800000U)
#define DCDC_REG0_OFFSET_RSNS_LP_ADJ_SHIFT       (23U)
#define DCDC_REG0_OFFSET_RSNS_LP_ADJ(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_OFFSET_RSNS_LP_ADJ_SHIFT)) & DCDC_REG0_OFFSET_RSNS_LP_ADJ_MASK)

#define DCDC_REG0_OFFSET_RSNS_LP_DISABLE_MASK    (0x1000000U)
#define DCDC_REG0_OFFSET_RSNS_LP_DISABLE_SHIFT   (24U)
#define DCDC_REG0_OFFSET_RSNS_LP_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_OFFSET_RSNS_LP_DISABLE_SHIFT)) & DCDC_REG0_OFFSET_RSNS_LP_DISABLE_MASK)

#define DCDC_REG0_DCDC_LESS_I_MASK               (0x2000000U)
#define DCDC_REG0_DCDC_LESS_I_SHIFT              (25U)
#define DCDC_REG0_DCDC_LESS_I(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_LESS_I_SHIFT)) & DCDC_REG0_DCDC_LESS_I_MASK)

#define DCDC_REG0_PWD_CMP_OFFSET_MASK            (0x4000000U)
#define DCDC_REG0_PWD_CMP_OFFSET_SHIFT           (26U)
#define DCDC_REG0_PWD_CMP_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_CMP_OFFSET_SHIFT)) & DCDC_REG0_PWD_CMP_OFFSET_MASK)

#define DCDC_REG0_DCDC_XTALOK_DISABLE_MASK       (0x8000000U)
#define DCDC_REG0_DCDC_XTALOK_DISABLE_SHIFT      (27U)
#define DCDC_REG0_DCDC_XTALOK_DISABLE(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_XTALOK_DISABLE_SHIFT)) & DCDC_REG0_DCDC_XTALOK_DISABLE_MASK)

#define DCDC_REG0_PSWITCH_STATUS_MASK            (0x10000000U)
#define DCDC_REG0_PSWITCH_STATUS_SHIFT           (28U)
#define DCDC_REG0_PSWITCH_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PSWITCH_STATUS_SHIFT)) & DCDC_REG0_PSWITCH_STATUS_MASK)

#define DCDC_REG0_VLPS_CONFIG_DCDC_HP_MASK       (0x20000000U)
#define DCDC_REG0_VLPS_CONFIG_DCDC_HP_SHIFT      (29U)
#define DCDC_REG0_VLPS_CONFIG_DCDC_HP(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_VLPS_CONFIG_DCDC_HP_SHIFT)) & DCDC_REG0_VLPS_CONFIG_DCDC_HP_MASK)

#define DCDC_REG0_VLPR_VLPW_CONFIG_DCDC_HP_MASK  (0x40000000U)
#define DCDC_REG0_VLPR_VLPW_CONFIG_DCDC_HP_SHIFT (30U)
#define DCDC_REG0_VLPR_VLPW_CONFIG_DCDC_HP(x)    (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_VLPR_VLPW_CONFIG_DCDC_HP_SHIFT)) & DCDC_REG0_VLPR_VLPW_CONFIG_DCDC_HP_MASK)

#define DCDC_REG0_DCDC_STS_DC_OK_MASK            (0x80000000U)
#define DCDC_REG0_DCDC_STS_DC_OK_SHIFT           (31U)
#define DCDC_REG0_DCDC_STS_DC_OK(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_DCDC_STS_DC_OK_SHIFT)) & DCDC_REG0_DCDC_STS_DC_OK_MASK)
/*! @} */

/*! @name REG1 - DCDC REGISTER 1 */
/*! @{ */

#define DCDC_REG1_POSLIMIT_BUCK_IN_MASK          (0x7FU)
#define DCDC_REG1_POSLIMIT_BUCK_IN_SHIFT         (0U)
#define DCDC_REG1_POSLIMIT_BUCK_IN(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_POSLIMIT_BUCK_IN_SHIFT)) & DCDC_REG1_POSLIMIT_BUCK_IN_MASK)

#define DCDC_REG1_POSLIMIT_BOOST_IN_MASK         (0x3F80U)
#define DCDC_REG1_POSLIMIT_BOOST_IN_SHIFT        (7U)
#define DCDC_REG1_POSLIMIT_BOOST_IN(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_POSLIMIT_BOOST_IN_SHIFT)) & DCDC_REG1_POSLIMIT_BOOST_IN_MASK)

#define DCDC_REG1_DCDC_LOOPCTRL_CM_HST_THRESH_MASK (0x200000U)
#define DCDC_REG1_DCDC_LOOPCTRL_CM_HST_THRESH_SHIFT (21U)
#define DCDC_REG1_DCDC_LOOPCTRL_CM_HST_THRESH(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_DCDC_LOOPCTRL_CM_HST_THRESH_SHIFT)) & DCDC_REG1_DCDC_LOOPCTRL_CM_HST_THRESH_MASK)

#define DCDC_REG1_DCDC_LOOPCTRL_DF_HST_THRESH_MASK (0x400000U)
#define DCDC_REG1_DCDC_LOOPCTRL_DF_HST_THRESH_SHIFT (22U)
#define DCDC_REG1_DCDC_LOOPCTRL_DF_HST_THRESH(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_DCDC_LOOPCTRL_DF_HST_THRESH_SHIFT)) & DCDC_REG1_DCDC_LOOPCTRL_DF_HST_THRESH_MASK)

#define DCDC_REG1_DCDC_LOOPCTRL_EN_CM_HYST_MASK  (0x800000U)
#define DCDC_REG1_DCDC_LOOPCTRL_EN_CM_HYST_SHIFT (23U)
#define DCDC_REG1_DCDC_LOOPCTRL_EN_CM_HYST(x)    (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_DCDC_LOOPCTRL_EN_CM_HYST_SHIFT)) & DCDC_REG1_DCDC_LOOPCTRL_EN_CM_HYST_MASK)

#define DCDC_REG1_DCDC_LOOPCTRL_EN_DF_HYST_MASK  (0x1000000U)
#define DCDC_REG1_DCDC_LOOPCTRL_EN_DF_HYST_SHIFT (24U)
#define DCDC_REG1_DCDC_LOOPCTRL_EN_DF_HYST(x)    (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_DCDC_LOOPCTRL_EN_DF_HYST_SHIFT)) & DCDC_REG1_DCDC_LOOPCTRL_EN_DF_HYST_MASK)
/*! @} */

/*! @name REG2 - DCDC REGISTER 2 */
/*! @{ */

#define DCDC_REG2_DCDC_LOOPCTRL_HYST_SIGN_MASK   (0x2000U)
#define DCDC_REG2_DCDC_LOOPCTRL_HYST_SIGN_SHIFT  (13U)
#define DCDC_REG2_DCDC_LOOPCTRL_HYST_SIGN(x)     (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_DCDC_LOOPCTRL_HYST_SIGN_SHIFT)) & DCDC_REG2_DCDC_LOOPCTRL_HYST_SIGN_MASK)

#define DCDC_REG2_DCDC_BATTMONITOR_EN_BATADJ_MASK (0x8000U)
#define DCDC_REG2_DCDC_BATTMONITOR_EN_BATADJ_SHIFT (15U)
#define DCDC_REG2_DCDC_BATTMONITOR_EN_BATADJ(x)  (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_DCDC_BATTMONITOR_EN_BATADJ_SHIFT)) & DCDC_REG2_DCDC_BATTMONITOR_EN_BATADJ_MASK)

#define DCDC_REG2_DCDC_BATTMONITOR_BATT_VAL_MASK (0x3FF0000U)
#define DCDC_REG2_DCDC_BATTMONITOR_BATT_VAL_SHIFT (16U)
#define DCDC_REG2_DCDC_BATTMONITOR_BATT_VAL(x)   (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_DCDC_BATTMONITOR_BATT_VAL_SHIFT)) & DCDC_REG2_DCDC_BATTMONITOR_BATT_VAL_MASK)
/*! @} */

/*! @name REG3 - DCDC REGISTER 3 */
/*! @{ */

#define DCDC_REG3_DCDC_VDD1P8CTRL_TRG_MASK       (0x3FU)
#define DCDC_REG3_DCDC_VDD1P8CTRL_TRG_SHIFT      (0U)
/*! DCDC_VDD1P8CTRL_TRG
 *  0b000000..1.65 V
 *  0b000110..1.8 V
 *  0b010001..2.075 V
 *  0b100000..2.8 V
 *  0b110100..3.3 V
 *  0b111111..3.575 V
 */
#define DCDC_REG3_DCDC_VDD1P8CTRL_TRG(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_VDD1P8CTRL_TRG_SHIFT)) & DCDC_REG3_DCDC_VDD1P8CTRL_TRG_MASK)

#define DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BUCK_MASK  (0x7C0U)
#define DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BUCK_SHIFT (6U)
/*! DCDC_VDD1P5CTRL_TRG_BUCK
 *  0b01111..1.65 V
 *  0b01001..1.5 V
 *  0b00000..1.275 V
 */
#define DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BUCK(x)    (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BUCK_SHIFT)) & DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BUCK_MASK)

#define DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BOOST_MASK (0xF800U)
#define DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BOOST_SHIFT (11U)
/*! DCDC_VDD1P5CTRL_TRG_BOOST
 *  0b10101..1.8 V
 *  0b01111..1.65 V
 *  0b01001..1.5 V
 *  0b00000..1.275 V
 */
#define DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BOOST(x)   (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BOOST_SHIFT)) & DCDC_REG3_DCDC_VDD1P5CTRL_TRG_BOOST_MASK)

#define DCDC_REG3_DCDC_VDD1P5CTRL_ADJTN_MASK     (0x1E0000U)
#define DCDC_REG3_DCDC_VDD1P5CTRL_ADJTN_SHIFT    (17U)
#define DCDC_REG3_DCDC_VDD1P5CTRL_ADJTN(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_VDD1P5CTRL_ADJTN_SHIFT)) & DCDC_REG3_DCDC_VDD1P5CTRL_ADJTN_MASK)

#define DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_PULSED_MASK (0x200000U)
#define DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_PULSED_SHIFT (21U)
#define DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_PULSED(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_PULSED_SHIFT)) & DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_PULSED_MASK)

#define DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_PULSED_MASK (0x400000U)
#define DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_PULSED_SHIFT (22U)
#define DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_PULSED(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_PULSED_SHIFT)) & DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_PULSED_MASK)

#define DCDC_REG3_DCDC_MINPWR_HALF_FETS_PULSED_MASK (0x800000U)
#define DCDC_REG3_DCDC_MINPWR_HALF_FETS_PULSED_SHIFT (23U)
#define DCDC_REG3_DCDC_MINPWR_HALF_FETS_PULSED(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_MINPWR_HALF_FETS_PULSED_SHIFT)) & DCDC_REG3_DCDC_MINPWR_HALF_FETS_PULSED_MASK)

#define DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_MASK    (0x1000000U)
#define DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_SHIFT   (24U)
#define DCDC_REG3_DCDC_MINPWR_DC_HALFCLK(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_SHIFT)) & DCDC_REG3_DCDC_MINPWR_DC_HALFCLK_MASK)

#define DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_MASK   (0x2000000U)
#define DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_SHIFT  (25U)
#define DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS(x)     (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_SHIFT)) & DCDC_REG3_DCDC_MINPWR_DOUBLE_FETS_MASK)

#define DCDC_REG3_DCDC_MINPWR_HALF_FETS_MASK     (0x4000000U)
#define DCDC_REG3_DCDC_MINPWR_HALF_FETS_SHIFT    (26U)
#define DCDC_REG3_DCDC_MINPWR_HALF_FETS(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_MINPWR_HALF_FETS_SHIFT)) & DCDC_REG3_DCDC_MINPWR_HALF_FETS_MASK)

#define DCDC_REG3_DCDC_VDD1P5CTRL_DISABLE_STEP_MASK (0x20000000U)
#define DCDC_REG3_DCDC_VDD1P5CTRL_DISABLE_STEP_SHIFT (29U)
#define DCDC_REG3_DCDC_VDD1P5CTRL_DISABLE_STEP(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_VDD1P5CTRL_DISABLE_STEP_SHIFT)) & DCDC_REG3_DCDC_VDD1P5CTRL_DISABLE_STEP_MASK)

#define DCDC_REG3_DCDC_VDD1P8CTRL_DISABLE_STEP_MASK (0x40000000U)
#define DCDC_REG3_DCDC_VDD1P8CTRL_DISABLE_STEP_SHIFT (30U)
#define DCDC_REG3_DCDC_VDD1P8CTRL_DISABLE_STEP(x) (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DCDC_VDD1P8CTRL_DISABLE_STEP_SHIFT)) & DCDC_REG3_DCDC_VDD1P8CTRL_DISABLE_STEP_MASK)
/*! @} */

/*! @name REG4 - DCDC REGISTER 4 */
/*! @{ */

#define DCDC_REG4_DCDC_SW_SHUTDOWN_MASK          (0x1U)
#define DCDC_REG4_DCDC_SW_SHUTDOWN_SHIFT         (0U)
/*! DCDC_SW_SHUTDOWN - Shut down DCDC in buck mode. DCDC can be turned on by pulling PSWITCH to high
 *    momentarily (min 50 ms).DCDC_SW_SHUTDOWN should not be used in boost mode because when user
 *    write this bit, MCU won't be POR and enters an abnormal state.
 */
#define DCDC_REG4_DCDC_SW_SHUTDOWN(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG4_DCDC_SW_SHUTDOWN_SHIFT)) & DCDC_REG4_DCDC_SW_SHUTDOWN_MASK)

#define DCDC_REG4_UNLOCK_MASK                    (0xFFFF0000U)
#define DCDC_REG4_UNLOCK_SHIFT                   (16U)
#define DCDC_REG4_UNLOCK(x)                      (((uint32_t)(((uint32_t)(x)) << DCDC_REG4_UNLOCK_SHIFT)) & DCDC_REG4_UNLOCK_MASK)
/*! @} */

/*! @name REG6 - DCDC REGISTER 6 */
/*! @{ */

#define DCDC_REG6_PSWITCH_INT_RISE_EN_MASK       (0x1U)
#define DCDC_REG6_PSWITCH_INT_RISE_EN_SHIFT      (0U)
#define DCDC_REG6_PSWITCH_INT_RISE_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG6_PSWITCH_INT_RISE_EN_SHIFT)) & DCDC_REG6_PSWITCH_INT_RISE_EN_MASK)

#define DCDC_REG6_PSWITCH_INT_FALL_EN_MASK       (0x2U)
#define DCDC_REG6_PSWITCH_INT_FALL_EN_SHIFT      (1U)
#define DCDC_REG6_PSWITCH_INT_FALL_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG6_PSWITCH_INT_FALL_EN_SHIFT)) & DCDC_REG6_PSWITCH_INT_FALL_EN_MASK)

#define DCDC_REG6_PSWITCH_INT_CLEAR_MASK         (0x4U)
#define DCDC_REG6_PSWITCH_INT_CLEAR_SHIFT        (2U)
#define DCDC_REG6_PSWITCH_INT_CLEAR(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG6_PSWITCH_INT_CLEAR_SHIFT)) & DCDC_REG6_PSWITCH_INT_CLEAR_MASK)

#define DCDC_REG6_PSWITCH_INT_MUTE_MASK          (0x8U)
#define DCDC_REG6_PSWITCH_INT_MUTE_SHIFT         (3U)
#define DCDC_REG6_PSWITCH_INT_MUTE(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG6_PSWITCH_INT_MUTE_SHIFT)) & DCDC_REG6_PSWITCH_INT_MUTE_MASK)

#define DCDC_REG6_PSWITCH_INT_STS_MASK           (0x80000000U)
#define DCDC_REG6_PSWITCH_INT_STS_SHIFT          (31U)
#define DCDC_REG6_PSWITCH_INT_STS(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_REG6_PSWITCH_INT_STS_SHIFT)) & DCDC_REG6_PSWITCH_INT_STS_MASK)
/*! @} */

/*! @name REG7 - DCDC REGISTER 7 */
/*! @{ */

#define DCDC_REG7_INTEGRATOR_VALUE_MASK          (0x7FFFFU)
#define DCDC_REG7_INTEGRATOR_VALUE_SHIFT         (0U)
#define DCDC_REG7_INTEGRATOR_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG7_INTEGRATOR_VALUE_SHIFT)) & DCDC_REG7_INTEGRATOR_VALUE_MASK)

#define DCDC_REG7_INTEGRATOR_VALUE_SEL_MASK      (0x80000U)
#define DCDC_REG7_INTEGRATOR_VALUE_SEL_SHIFT     (19U)
#define DCDC_REG7_INTEGRATOR_VALUE_SEL(x)        (((uint32_t)(((uint32_t)(x)) << DCDC_REG7_INTEGRATOR_VALUE_SEL_SHIFT)) & DCDC_REG7_INTEGRATOR_VALUE_SEL_MASK)

#define DCDC_REG7_PULSE_RUN_SPEEDUP_MASK         (0x100000U)
#define DCDC_REG7_PULSE_RUN_SPEEDUP_SHIFT        (20U)
#define DCDC_REG7_PULSE_RUN_SPEEDUP(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG7_PULSE_RUN_SPEEDUP_SHIFT)) & DCDC_REG7_PULSE_RUN_SPEEDUP_MASK)
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


#endif  /* DCDC_H_ */

