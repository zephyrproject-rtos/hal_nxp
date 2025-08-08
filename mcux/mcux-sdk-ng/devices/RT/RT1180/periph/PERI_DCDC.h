/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DCDC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DCDC
 *
 * CMSIS Peripheral Access Layer for DCDC
 */

#if !defined(PERI_DCDC_H_)
#define PERI_DCDC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
  __IO uint32_t REG0;                              /**< DCDC Register 0, offset: 0x0 */
  __IO uint32_t REG1;                              /**< DCDC Register 1, offset: 0x4 */
  __IO uint32_t REG2;                              /**< DCDC Register 2, offset: 0x8 */
  __IO uint32_t REG3;                              /**< DCDC Register 3, offset: 0xC */
  __IO uint32_t CTRL0;                             /**< DCDC Control Register 0, offset: 0x10 */
  __IO uint32_t OK_CNT;                            /**< OK CNT, offset: 0x14 */
  __IO uint32_t CURRENT_TRG;                       /**< CURRENT TARGET VALUE for DCDC ANALOG, offset: 0x18 */
  __IO uint32_t FILTER_CNT;                        /**< FILTER CNT, offset: 0x1C */
  __IO uint32_t TRG_0_AUTHEN;                      /**< TRG_0 Authentication Control, offset: 0x20 */
  __IO uint32_t TRG_SW_0;                          /**< Target SW Control for CORE 0, offset: 0x24 */
  __IO uint32_t TRG_GPC_0;                         /**< Target GPC Control for CORE 0, offset: 0x28 */
       uint8_t RESERVED_0[4];
  __IO uint32_t TRG_1_AUTHEN;                      /**< TRG_1 Authentication Control, offset: 0x30 */
  __IO uint32_t TRG_SW_1;                          /**< Target SW Control for CORE 1, offset: 0x34 */
  __IO uint32_t TRG_GPC_1;                         /**< Target GPC Control for CORE 1, offset: 0x38 */
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
 *  0b0..Zero cross detection function powered up
 *  0b1..Zero cross detection function powered down
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
 *  0b00..In Run Mode, 1.5 A. In LP Mode, 150 mA
 *  0b01..In Run Mode, 1.5 A. In LP Mode, 130 mA
 *  0b10..In Run Mode, 2 A. In LP Mode, 150 mA
 *  0b11..In Run Mode, 2 A. In LP Mode, 130 mA
 */
#define DCDC_REG0_OVERCUR_TRIG_ADJ(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_OVERCUR_TRIG_ADJ_SHIFT)) & DCDC_REG0_OVERCUR_TRIG_ADJ_MASK)

#define DCDC_REG0_PWD_CMP_DCDC_IN_DET_MASK       (0x800U)
#define DCDC_REG0_PWD_CMP_DCDC_IN_DET_SHIFT      (11U)
/*! PWD_CMP_DCDC_IN_DET
 *  0b0..Low voltage detection comparator is enabled
 *  0b1..Low voltage detection comparator is disabled
 */
#define DCDC_REG0_PWD_CMP_DCDC_IN_DET(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_CMP_DCDC_IN_DET_SHIFT)) & DCDC_REG0_PWD_CMP_DCDC_IN_DET_MASK)

#define DCDC_REG0_PWD_HIGH_VDD1P8_DET_MASK       (0x10000U)
#define DCDC_REG0_PWD_HIGH_VDD1P8_DET_SHIFT      (16U)
/*! PWD_HIGH_VDD1P8_DET - Power Down High Voltage Detection for VDD1P8
 *  0b0..Overvoltage detection comparator for the VDD1P8 output is enabled
 *  0b1..Overvoltage detection comparator for the VDD1P8 output is disabled
 */
#define DCDC_REG0_PWD_HIGH_VDD1P8_DET(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_HIGH_VDD1P8_DET_SHIFT)) & DCDC_REG0_PWD_HIGH_VDD1P8_DET_MASK)

#define DCDC_REG0_PWD_HIGH_VDD1P0_DET_MASK       (0x20000U)
#define DCDC_REG0_PWD_HIGH_VDD1P0_DET_SHIFT      (17U)
/*! PWD_HIGH_VDD1P0_DET - Power Down High Voltage Detection for VDD1P0
 *  0b0..Overvoltage detection comparator for the VDD1P0 output is enabled
 *  0b1..Overvoltage detection comparator for the VDD1P0 output is disabled
 */
#define DCDC_REG0_PWD_HIGH_VDD1P0_DET(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_HIGH_VDD1P0_DET_SHIFT)) & DCDC_REG0_PWD_HIGH_VDD1P0_DET_MASK)

#define DCDC_REG0_PWD_CMP_OFFSET_MASK            (0x4000000U)
#define DCDC_REG0_PWD_CMP_OFFSET_SHIFT           (26U)
/*! PWD_CMP_OFFSET - power down the out-of-range detection comparator
 *  0b0..Out-of-range comparator powered up
 *  0b1..Out-of-range comparator powered down
 */
#define DCDC_REG0_PWD_CMP_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_PWD_CMP_OFFSET_SHIFT)) & DCDC_REG0_PWD_CMP_OFFSET_MASK)

#define DCDC_REG0_XTALOK_DISABLE_MASK            (0x8000000U)
#define DCDC_REG0_XTALOK_DISABLE_SHIFT           (27U)
/*! XTALOK_DISABLE - Disable xtalok detection circuit
 *  0b0..Enable xtalok detection circuit
 *  0b1..Disable xtalok detection circuit and always outputs OK signal "1"
 */
#define DCDC_REG0_XTALOK_DISABLE(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_REG0_XTALOK_DISABLE_SHIFT)) & DCDC_REG0_XTALOK_DISABLE_MASK)

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

#define DCDC_REG1_RLOAD_REG_EN_MASK              (0x10U)
#define DCDC_REG1_RLOAD_REG_EN_SHIFT             (4U)
/*! RLOAD_REG_EN - Resistor Load of Regulator Enable
 *  0b0..Resistor load disconnected
 *  0b1..Resistor load connected
 */
#define DCDC_REG1_RLOAD_REG_EN(x)                (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_RLOAD_REG_EN_SHIFT)) & DCDC_REG1_RLOAD_REG_EN_MASK)

#define DCDC_REG1_VBG_TRIM_MASK                  (0x7C0U)
#define DCDC_REG1_VBG_TRIM_SHIFT                 (6U)
#define DCDC_REG1_VBG_TRIM(x)                    (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_VBG_TRIM_SHIFT)) & DCDC_REG1_VBG_TRIM_MASK)

#define DCDC_REG1_NEGLIMIT_IN_MASK               (0xFE000U)
#define DCDC_REG1_NEGLIMIT_IN_SHIFT              (13U)
#define DCDC_REG1_NEGLIMIT_IN(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_NEGLIMIT_IN_SHIFT)) & DCDC_REG1_NEGLIMIT_IN_MASK)

#define DCDC_REG1_LOOPCTRL_CM_HST_THRESH_MASK    (0x8000000U)
#define DCDC_REG1_LOOPCTRL_CM_HST_THRESH_SHIFT   (27U)
/*! LOOPCTRL_CM_HST_THRESH - Increase Threshold Detection
 *  0b0..Disable increase the threshold detection for common mode analog comparators.
 *  0b1..Enable increase the threshold detection for common mode analog comparators.
 */
#define DCDC_REG1_LOOPCTRL_CM_HST_THRESH(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_LOOPCTRL_CM_HST_THRESH_SHIFT)) & DCDC_REG1_LOOPCTRL_CM_HST_THRESH_MASK)

#define DCDC_REG1_LOOPCTRL_DF_HST_THRESH_MASK    (0x10000000U)
#define DCDC_REG1_LOOPCTRL_DF_HST_THRESH_SHIFT   (28U)
/*! LOOPCTRL_DF_HST_THRESH - Increase Threshold Detection
 *  0b0..Disable increase the threshold detection for differential mode analog comparators.
 *  0b1..Enable increase the threshold detection for differential mode analog comparators.
 */
#define DCDC_REG1_LOOPCTRL_DF_HST_THRESH(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_LOOPCTRL_DF_HST_THRESH_SHIFT)) & DCDC_REG1_LOOPCTRL_DF_HST_THRESH_MASK)

#define DCDC_REG1_LOOPCTRL_EN_CM_HYST_MASK       (0x20000000U)
#define DCDC_REG1_LOOPCTRL_EN_CM_HYST_SHIFT      (29U)
/*! LOOPCTRL_EN_CM_HYST
 *  0b0..Disable hysteresis in switching converter common mode analog comparators
 *  0b1..Enable hysteresis in switching converter common mode analog comparators
 */
#define DCDC_REG1_LOOPCTRL_EN_CM_HYST(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_LOOPCTRL_EN_CM_HYST_SHIFT)) & DCDC_REG1_LOOPCTRL_EN_CM_HYST_MASK)

#define DCDC_REG1_LOOPCTRL_EN_DF_HYST_MASK       (0x40000000U)
#define DCDC_REG1_LOOPCTRL_EN_DF_HYST_SHIFT      (30U)
/*! LOOPCTRL_EN_DF_HYST
 *  0b0..Disable hysteresis in switching converter differential mode analog comparators
 *  0b1..Enable hysteresis in switching converter differential mode analog comparators
 */
#define DCDC_REG1_LOOPCTRL_EN_DF_HYST(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG1_LOOPCTRL_EN_DF_HYST_SHIFT)) & DCDC_REG1_LOOPCTRL_EN_DF_HYST_MASK)
/*! @} */

/*! @name REG2 - DCDC Register 2 */
/*! @{ */

#define DCDC_REG2_LOOPCTRL_DC_C_MASK             (0x3U)
#define DCDC_REG2_LOOPCTRL_DC_C_SHIFT            (0U)
#define DCDC_REG2_LOOPCTRL_DC_C(x)               (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_DC_C_SHIFT)) & DCDC_REG2_LOOPCTRL_DC_C_MASK)

#define DCDC_REG2_LOOPCTRL_DC_R_MASK             (0x3CU)
#define DCDC_REG2_LOOPCTRL_DC_R_SHIFT            (2U)
#define DCDC_REG2_LOOPCTRL_DC_R(x)               (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_DC_R_SHIFT)) & DCDC_REG2_LOOPCTRL_DC_R_MASK)

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
 *  0b0..Disable increasing the threshold detection function.
 *  0b1..Enable increasing the threshold detection function.
 */
#define DCDC_REG2_LOOPCTRL_RCSCALE_THRSH(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_RCSCALE_THRSH_SHIFT)) & DCDC_REG2_LOOPCTRL_RCSCALE_THRSH_MASK)

#define DCDC_REG2_LOOPCTRL_HYST_SIGN_MASK        (0x2000U)
#define DCDC_REG2_LOOPCTRL_HYST_SIGN_SHIFT       (13U)
/*! LOOPCTRL_HYST_SIGN
 *  0b0..Disable the invert function.
 *  0b1..Enable the invert function.
 */
#define DCDC_REG2_LOOPCTRL_HYST_SIGN(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_HYST_SIGN_SHIFT)) & DCDC_REG2_LOOPCTRL_HYST_SIGN_MASK)

#define DCDC_REG2_BATTMONITOR_EN_BATADJ_MASK     (0x8000U)
#define DCDC_REG2_BATTMONITOR_EN_BATADJ_SHIFT    (15U)
/*! BATTMONITOR_EN_BATADJ
 *  0b0..Disable the improvement function.
 *  0b1..Enable the improvement function.
 */
#define DCDC_REG2_BATTMONITOR_EN_BATADJ(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_BATTMONITOR_EN_BATADJ_SHIFT)) & DCDC_REG2_BATTMONITOR_EN_BATADJ_MASK)

#define DCDC_REG2_BATTMONITOR_BATT_VAL_MASK      (0x3FF0000U)
#define DCDC_REG2_BATTMONITOR_BATT_VAL_SHIFT     (16U)
#define DCDC_REG2_BATTMONITOR_BATT_VAL(x)        (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_BATTMONITOR_BATT_VAL_SHIFT)) & DCDC_REG2_BATTMONITOR_BATT_VAL_MASK)

#define DCDC_REG2_LOOPCTRL_TOGGLE_DIF_MASK       (0x40000000U)
#define DCDC_REG2_LOOPCTRL_TOGGLE_DIF_SHIFT      (30U)
/*! LOOPCTRL_TOGGLE_DIF
 *  0b0..Disable supply stepping to change.
 *  0b1..Enable supply stepping to change.
 */
#define DCDC_REG2_LOOPCTRL_TOGGLE_DIF(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG2_LOOPCTRL_TOGGLE_DIF_SHIFT)) & DCDC_REG2_LOOPCTRL_TOGGLE_DIF_MASK)
/*! @} */

/*! @name REG3 - DCDC Register 3 */
/*! @{ */

#define DCDC_REG3_IN_BROWNOUT_WARN_MASK          (0x200U)
#define DCDC_REG3_IN_BROWNOUT_WARN_SHIFT         (9U)
/*! IN_BROWNOUT_WARN
 *  0b0..The voltage on DCDC_IN raises up to 2.8V.
 *  0b1..The voltage on DCDC_IN is lower than 2.8V. Once this bit sets, the bit must be cleared by software write
 *       one clear action while the voltage on DCDC_IN raises up to 2.8V. Writing "0" to this bit has no effect.
 *       Writing "1" to this bit has no effect while it's "0".
 */
#define DCDC_REG3_IN_BROWNOUT_WARN(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_IN_BROWNOUT_WARN_SHIFT)) & DCDC_REG3_IN_BROWNOUT_WARN_MASK)

#define DCDC_REG3_ENABLE_FF_MASK                 (0x40000U)
#define DCDC_REG3_ENABLE_FF_SHIFT                (18U)
/*! ENABLE_FF
 *  0b0..Enable the FF function.
 *  0b1..Disable the FF function.
 */
#define DCDC_REG3_ENABLE_FF(x)                   (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_ENABLE_FF_SHIFT)) & DCDC_REG3_ENABLE_FF_MASK)

#define DCDC_REG3_DISABLE_PULSE_SKIP_MASK        (0x80000U)
#define DCDC_REG3_DISABLE_PULSE_SKIP_SHIFT       (19U)
/*! DISABLE_PULSE_SKIP - Disable Pulse Skip */
#define DCDC_REG3_DISABLE_PULSE_SKIP(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DISABLE_PULSE_SKIP_SHIFT)) & DCDC_REG3_DISABLE_PULSE_SKIP_MASK)

#define DCDC_REG3_DISABLE_IDLE_SKIP_MASK         (0x100000U)
#define DCDC_REG3_DISABLE_IDLE_SKIP_SHIFT        (20U)
/*! DISABLE_IDLE_SKIP
 *  0b0..Enable the idle skip function.
 *  0b1..Disable the idle skip function.
 */
#define DCDC_REG3_DISABLE_IDLE_SKIP(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DISABLE_IDLE_SKIP_SHIFT)) & DCDC_REG3_DISABLE_IDLE_SKIP_MASK)

#define DCDC_REG3_DOUBLE_IBIAS_CMP_LP_MASK       (0x200000U)
#define DCDC_REG3_DOUBLE_IBIAS_CMP_LP_SHIFT      (21U)
/*! DOUBLE_IBIAS_CMP_LP
 *  0b0..Disable the function.
 *  0b1..Enable the function.
 */
#define DCDC_REG3_DOUBLE_IBIAS_CMP_LP(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_DOUBLE_IBIAS_CMP_LP_SHIFT)) & DCDC_REG3_DOUBLE_IBIAS_CMP_LP_MASK)

#define DCDC_REG3_REG_FBK_SEL_MASK               (0xC00000U)
#define DCDC_REG3_REG_FBK_SEL_SHIFT              (22U)
#define DCDC_REG3_REG_FBK_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_REG_FBK_SEL_SHIFT)) & DCDC_REG3_REG_FBK_SEL_MASK)

#define DCDC_REG3_MINPWR_HALF_FETS_MASK          (0x4000000U)
#define DCDC_REG3_MINPWR_HALF_FETS_SHIFT         (26U)
/*! MINPWR_HALF_FETS
 *  0b0..Donot use half switch FET.
 *  0b1..Use half switch FET.
 */
#define DCDC_REG3_MINPWR_HALF_FETS(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_MINPWR_HALF_FETS_SHIFT)) & DCDC_REG3_MINPWR_HALF_FETS_MASK)

#define DCDC_REG3_MISC_DELAY_TIMING_MASK         (0x8000000U)
#define DCDC_REG3_MISC_DELAY_TIMING_SHIFT        (27U)
/*! MISC_DELAY_TIMING - Miscellaneous Delay Timing
 *  0b0..Disable the function.
 *  0b1..Enable the function.
 */
#define DCDC_REG3_MISC_DELAY_TIMING(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_MISC_DELAY_TIMING_SHIFT)) & DCDC_REG3_MISC_DELAY_TIMING_MASK)

#define DCDC_REG3_VDD1P0CTRL_DISABLE_STEP_MASK   (0x20000000U)
#define DCDC_REG3_VDD1P0CTRL_DISABLE_STEP_SHIFT  (29U)
/*! VDD1P0CTRL_DISABLE_STEP - Disable Step for VDD1P0
 *  0b0..Enable stepping for VDD1P0
 *  0b1..Disable stepping for VDD1P0
 */
#define DCDC_REG3_VDD1P0CTRL_DISABLE_STEP(x)     (((uint32_t)(((uint32_t)(x)) << DCDC_REG3_VDD1P0CTRL_DISABLE_STEP_SHIFT)) & DCDC_REG3_VDD1P0CTRL_DISABLE_STEP_MASK)
/*! @} */

/*! @name CTRL0 - DCDC Control Register 0 */
/*! @{ */

#define DCDC_CTRL0_ENABLE_OK_CNT_MASK            (0x20U)
#define DCDC_CTRL0_ENABLE_OK_CNT_SHIFT           (5U)
/*! ENABLE_OK_CNT - Enable internal count for DCDC_OK timeout
 *  0b0..Wait DCDC_OK for ACK
 *  0b1..Enable internal count for DCDC_OK timeout
 */
#define DCDC_CTRL0_ENABLE_OK_CNT(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_CTRL0_ENABLE_OK_CNT_SHIFT)) & DCDC_CTRL0_ENABLE_OK_CNT_MASK)

#define DCDC_CTRL0_TRIM_HOLD_MASK                (0x40U)
#define DCDC_CTRL0_TRIM_HOLD_SHIFT               (6U)
/*! TRIM_HOLD - Hold trim input
 *  0b0..Sample trim value from FUSE or value from REG1[VBG_TRIM] depending on FUSE select bit.
 *  0b1..Use value from REG1[VBG_TRIM] as trim value.
 */
#define DCDC_CTRL0_TRIM_HOLD(x)                  (((uint32_t)(((uint32_t)(x)) << DCDC_CTRL0_TRIM_HOLD_SHIFT)) & DCDC_CTRL0_TRIM_HOLD_MASK)

#define DCDC_CTRL0_IN_BROWNOUT_WARN_EN_MASK      (0x200U)
#define DCDC_CTRL0_IN_BROWNOUT_WARN_EN_SHIFT     (9U)
/*! IN_BROWNOUT_WARN_EN - IN_BROWNOUT_WARN_EN
 *  0b0..Disable IN_BROWNOUT_WARN int flag bit output to CORE as an interrupt resource.
 *  0b1..Enable IN_BROWNOUT_WARN int flag bit output to CORE as an interrupt resource.
 */
#define DCDC_CTRL0_IN_BROWNOUT_WARN_EN(x)        (((uint32_t)(((uint32_t)(x)) << DCDC_CTRL0_IN_BROWNOUT_WARN_EN_SHIFT)) & DCDC_CTRL0_IN_BROWNOUT_WARN_EN_MASK)

#define DCDC_CTRL0_DEBUG_BITS_MASK               (0x7FF80000U)
#define DCDC_CTRL0_DEBUG_BITS_SHIFT              (19U)
#define DCDC_CTRL0_DEBUG_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_CTRL0_DEBUG_BITS_SHIFT)) & DCDC_CTRL0_DEBUG_BITS_MASK)

#define DCDC_CTRL0_TRG_GPC_EN_MASK               (0x80000000U)
#define DCDC_CTRL0_TRG_GPC_EN_SHIFT              (31U)
/*! TRG_GPC_EN - TRG_GPC_EN: used to enable TRG_GPC_* value or not.
 *  0b0..No matter there is GPC stby request or not, value in TRG_SW_* register will always be used as DCDC analog target value.
 *  0b1..When there is a GPC stby request, value in TRG_GPC_* register will be used as DCDC analog target value instead of TRG_SW_*'s
 */
#define DCDC_CTRL0_TRG_GPC_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DCDC_CTRL0_TRG_GPC_EN_SHIFT)) & DCDC_CTRL0_TRG_GPC_EN_MASK)
/*! @} */

/*! @name OK_CNT - OK CNT */
/*! @{ */

#define DCDC_OK_CNT_OK_COUNT_MASK                (0xFFFFFFFFU)
#define DCDC_OK_CNT_OK_COUNT_SHIFT               (0U)
/*! OK_COUNT - OK_COUNT */
#define DCDC_OK_CNT_OK_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << DCDC_OK_CNT_OK_COUNT_SHIFT)) & DCDC_OK_CNT_OK_COUNT_MASK)
/*! @} */

/*! @name CURRENT_TRG - CURRENT TARGET VALUE for DCDC ANALOG */
/*! @{ */

#define DCDC_CURRENT_TRG_VDD1P0CTRL_TRG_MASK     (0x1FU)
#define DCDC_CURRENT_TRG_VDD1P0CTRL_TRG_SHIFT    (0U)
#define DCDC_CURRENT_TRG_VDD1P0CTRL_TRG(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_CURRENT_TRG_VDD1P0CTRL_TRG_SHIFT)) & DCDC_CURRENT_TRG_VDD1P0CTRL_TRG_MASK)

#define DCDC_CURRENT_TRG_VDD1P8CTRL_TRG_MASK     (0x1F00U)
#define DCDC_CURRENT_TRG_VDD1P8CTRL_TRG_SHIFT    (8U)
#define DCDC_CURRENT_TRG_VDD1P8CTRL_TRG(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_CURRENT_TRG_VDD1P8CTRL_TRG_SHIFT)) & DCDC_CURRENT_TRG_VDD1P8CTRL_TRG_MASK)

#define DCDC_CURRENT_TRG_DCDC_UPDATING_MASK      (0x8000U)
#define DCDC_CURRENT_TRG_DCDC_UPDATING_SHIFT     (15U)
/*! DCDC_UPDATING
 *  0b0..Last DCDC change has been done. New value can be written to TRG register to trigger a new change of DCDC voltage.
 *  0b1..Last DCDC change is still not done. New value should not be written to TRG register to trigger a new change of DCDC voltage.
 */
#define DCDC_CURRENT_TRG_DCDC_UPDATING(x)        (((uint32_t)(((uint32_t)(x)) << DCDC_CURRENT_TRG_DCDC_UPDATING_SHIFT)) & DCDC_CURRENT_TRG_DCDC_UPDATING_MASK)

#define DCDC_CURRENT_TRG_VDD1P0CTRL_LP_TRG_MASK  (0x1F0000U)
#define DCDC_CURRENT_TRG_VDD1P0CTRL_LP_TRG_SHIFT (16U)
#define DCDC_CURRENT_TRG_VDD1P0CTRL_LP_TRG(x)    (((uint32_t)(((uint32_t)(x)) << DCDC_CURRENT_TRG_VDD1P0CTRL_LP_TRG_SHIFT)) & DCDC_CURRENT_TRG_VDD1P0CTRL_LP_TRG_MASK)

#define DCDC_CURRENT_TRG_LP_EN_1P0_MASK          (0x80000000U)
#define DCDC_CURRENT_TRG_LP_EN_1P0_SHIFT         (31U)
/*! LP_EN_1P0 - This value comes from the smaller one between TRG_SW_0 and TRG_SW_1. This bit only
 *    controls 1P0. 1P8 is always controlled by VDD1P8CTRL_TRG
 *  0b0..DCDC 1P0 works in run mode. Its output voltage is controlled by VDD1P0CTRL_TRG.
 *  0b1..DCDC 1P0 works in low power mode. Its output voltage is controlled by VDD1P0CTRL_LP_TRG and its output current is less than 50mA.
 */
#define DCDC_CURRENT_TRG_LP_EN_1P0(x)            (((uint32_t)(((uint32_t)(x)) << DCDC_CURRENT_TRG_LP_EN_1P0_SHIFT)) & DCDC_CURRENT_TRG_LP_EN_1P0_MASK)
/*! @} */

/*! @name FILTER_CNT - FILTER CNT */
/*! @{ */

#define DCDC_FILTER_CNT_FILTER_CNT_CFG_MASK      (0xFFFFFFFFU)
#define DCDC_FILTER_CNT_FILTER_CNT_CFG_SHIFT     (0U)
/*! FILTER_CNT_CFG - FILTER_CNT_CFG */
#define DCDC_FILTER_CNT_FILTER_CNT_CFG(x)        (((uint32_t)(((uint32_t)(x)) << DCDC_FILTER_CNT_FILTER_CNT_CFG_SHIFT)) & DCDC_FILTER_CNT_FILTER_CNT_CFG_MASK)
/*! @} */

/*! @name TRG_0_AUTHEN - TRG_0 Authentication Control */
/*! @{ */

#define DCDC_TRG_0_AUTHEN_TZ_USER_MASK           (0x100U)
#define DCDC_TRG_0_AUTHEN_TZ_USER_SHIFT          (8U)
/*! TZ_USER - Allow user mode write
 *  0b0..TRG_0 registers can only be written in privilege mode.
 *  0b1..TRG_0 registers can be written either in privilege mode or user mode.
 */
#define DCDC_TRG_0_AUTHEN_TZ_USER(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_0_AUTHEN_TZ_USER_SHIFT)) & DCDC_TRG_0_AUTHEN_TZ_USER_MASK)

#define DCDC_TRG_0_AUTHEN_TZ_NS_MASK             (0x200U)
#define DCDC_TRG_0_AUTHEN_TZ_NS_SHIFT            (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..TRG_0 registers can only be written in secure mode.
 *  0b1..TRG_0 registers can be written either in secure mode or non-secure mode.
 */
#define DCDC_TRG_0_AUTHEN_TZ_NS(x)               (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_0_AUTHEN_TZ_NS_SHIFT)) & DCDC_TRG_0_AUTHEN_TZ_NS_MASK)

#define DCDC_TRG_0_AUTHEN_LOCK_TZ_MASK           (0x800U)
#define DCDC_TRG_0_AUTHEN_LOCK_TZ_SHIFT          (11U)
/*! LOCK_TZ - Lock TZ_NS and TZ_USER
 *  0b0..TZ_NS and TZ_USER value can be changed.
 *  0b1..LOCK_TZ, TZ_NS and TZ_USER value cannot be changed.
 */
#define DCDC_TRG_0_AUTHEN_LOCK_TZ(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_0_AUTHEN_LOCK_TZ_SHIFT)) & DCDC_TRG_0_AUTHEN_LOCK_TZ_MASK)

#define DCDC_TRG_0_AUTHEN_LOCK_LIST_MASK         (0x8000U)
#define DCDC_TRG_0_AUTHEN_LOCK_LIST_SHIFT        (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..LOCK_LIST and WHITE_LIST value cannot be changed.
 */
#define DCDC_TRG_0_AUTHEN_LOCK_LIST(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_0_AUTHEN_LOCK_LIST_SHIFT)) & DCDC_TRG_0_AUTHEN_LOCK_LIST_MASK)

#define DCDC_TRG_0_AUTHEN_WHITE_LIST_MASK        (0xFFFF0000U)
#define DCDC_TRG_0_AUTHEN_WHITE_LIST_SHIFT       (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write TRG_0 registers.
 *  0b0000000000000010..Core with domain ID=1 can write TRG_0 registers.
 *  0b0000000000000100..Core with domain ID=2 can write TRG_0 registers.
 *  0b0000000000001000..Core with domain ID=3 can write TRG_0 registers.
 *  0b0000000000010000..Core with domain ID=4 can write TRG_0 registers.
 *  0b0000000000100000..Core with domain ID=5 can write TRG_0 registers.
 *  0b0000000001000000..Core with domain ID=6 can write TRG_0 registers.
 *  0b0000000010000000..Core with domain ID=7 can write TRG_0 registers.
 *  0b0000000100000000..Core with domain ID=8 can write TRG_0 registers.
 *  0b0000001000000000..Core with domain ID=9 can write TRG_0 registers.
 *  0b0000010000000000..Core with domain ID=10 can write TRG_0 registers.
 *  0b0000100000000000..Core with domain ID=11 can write TRG_0 registers.
 *  0b0001000000000000..Core with domain ID=12 can write TRG_0 registers.
 *  0b0010000000000000..Core with domain ID=13 can write TRG_0 registers.
 *  0b0100000000000000..Core with domain ID=14 can write TRG_0 registers.
 *  0b1000000000000000..Core with domain ID=15 can write TRG_0 registers.
 */
#define DCDC_TRG_0_AUTHEN_WHITE_LIST(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_0_AUTHEN_WHITE_LIST_SHIFT)) & DCDC_TRG_0_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name TRG_SW_0 - Target SW Control for CORE 0 */
/*! @{ */

#define DCDC_TRG_SW_0_VDD1P0CTRL_TRG_MASK        (0x1FU)
#define DCDC_TRG_SW_0_VDD1P0CTRL_TRG_SHIFT       (0U)
#define DCDC_TRG_SW_0_VDD1P0CTRL_TRG(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_0_VDD1P0CTRL_TRG_SHIFT)) & DCDC_TRG_SW_0_VDD1P0CTRL_TRG_MASK)

#define DCDC_TRG_SW_0_VDD1P8CTRL_TRG_MASK        (0x1F00U)
#define DCDC_TRG_SW_0_VDD1P8CTRL_TRG_SHIFT       (8U)
#define DCDC_TRG_SW_0_VDD1P8CTRL_TRG(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_0_VDD1P8CTRL_TRG_SHIFT)) & DCDC_TRG_SW_0_VDD1P8CTRL_TRG_MASK)

#define DCDC_TRG_SW_0_VDD1P0CTRL_LP_TRG_MASK     (0x1F0000U)
#define DCDC_TRG_SW_0_VDD1P0CTRL_LP_TRG_SHIFT    (16U)
#define DCDC_TRG_SW_0_VDD1P0CTRL_LP_TRG(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_0_VDD1P0CTRL_LP_TRG_SHIFT)) & DCDC_TRG_SW_0_VDD1P0CTRL_LP_TRG_MASK)

#define DCDC_TRG_SW_0_LP_EN_1P0_MASK             (0x80000000U)
#define DCDC_TRG_SW_0_LP_EN_1P0_SHIFT            (31U)
/*! LP_EN_1P0 - LP_EN_1P0 only controls 1P0. 1P8 is always controlled by VDD1P8CTRL_TRG */
#define DCDC_TRG_SW_0_LP_EN_1P0(x)               (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_0_LP_EN_1P0_SHIFT)) & DCDC_TRG_SW_0_LP_EN_1P0_MASK)
/*! @} */

/*! @name TRG_GPC_0 - Target GPC Control for CORE 0 */
/*! @{ */

#define DCDC_TRG_GPC_0_VDD1P0CTRL_TRG_MASK       (0x1FU)
#define DCDC_TRG_GPC_0_VDD1P0CTRL_TRG_SHIFT      (0U)
#define DCDC_TRG_GPC_0_VDD1P0CTRL_TRG(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_0_VDD1P0CTRL_TRG_SHIFT)) & DCDC_TRG_GPC_0_VDD1P0CTRL_TRG_MASK)

#define DCDC_TRG_GPC_0_VDD1P8CTRL_TRG_MASK       (0x1F00U)
#define DCDC_TRG_GPC_0_VDD1P8CTRL_TRG_SHIFT      (8U)
#define DCDC_TRG_GPC_0_VDD1P8CTRL_TRG(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_0_VDD1P8CTRL_TRG_SHIFT)) & DCDC_TRG_GPC_0_VDD1P8CTRL_TRG_MASK)

#define DCDC_TRG_GPC_0_VDD1P0CTRL_LP_TRG_MASK    (0x1F0000U)
#define DCDC_TRG_GPC_0_VDD1P0CTRL_LP_TRG_SHIFT   (16U)
#define DCDC_TRG_GPC_0_VDD1P0CTRL_LP_TRG(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_0_VDD1P0CTRL_LP_TRG_SHIFT)) & DCDC_TRG_GPC_0_VDD1P0CTRL_LP_TRG_MASK)

#define DCDC_TRG_GPC_0_LP_EN_1P0_MASK            (0x80000000U)
#define DCDC_TRG_GPC_0_LP_EN_1P0_SHIFT           (31U)
/*! LP_EN_1P0 - LP_EN_1P0 only controls 1P0. 1P8 is always controlled by VDD1P8CTRL_TRG */
#define DCDC_TRG_GPC_0_LP_EN_1P0(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_0_LP_EN_1P0_SHIFT)) & DCDC_TRG_GPC_0_LP_EN_1P0_MASK)
/*! @} */

/*! @name TRG_1_AUTHEN - TRG_1 Authentication Control */
/*! @{ */

#define DCDC_TRG_1_AUTHEN_TZ_USER_MASK           (0x100U)
#define DCDC_TRG_1_AUTHEN_TZ_USER_SHIFT          (8U)
/*! TZ_USER - Allow user mode write
 *  0b0..TRG_1 registers can only be written in privilege mode.
 *  0b1..TRG_1 registers can be written either in privilege mode or user mode.
 */
#define DCDC_TRG_1_AUTHEN_TZ_USER(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_1_AUTHEN_TZ_USER_SHIFT)) & DCDC_TRG_1_AUTHEN_TZ_USER_MASK)

#define DCDC_TRG_1_AUTHEN_TZ_NS_MASK             (0x200U)
#define DCDC_TRG_1_AUTHEN_TZ_NS_SHIFT            (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..TRG_1 registers can only be written in secure mode.
 *  0b1..TRG_1 registers can be written either in secure mode or non-secure mode.
 */
#define DCDC_TRG_1_AUTHEN_TZ_NS(x)               (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_1_AUTHEN_TZ_NS_SHIFT)) & DCDC_TRG_1_AUTHEN_TZ_NS_MASK)

#define DCDC_TRG_1_AUTHEN_LOCK_TZ_MASK           (0x800U)
#define DCDC_TRG_1_AUTHEN_LOCK_TZ_SHIFT          (11U)
/*! LOCK_TZ - Lock TZ_NS and TZ_USER
 *  0b0..TZ_NS and TZ_USER value can be changed.
 *  0b1..LOCK_TZ, TZ_NS and TZ_USER value cannot be changed.
 */
#define DCDC_TRG_1_AUTHEN_LOCK_TZ(x)             (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_1_AUTHEN_LOCK_TZ_SHIFT)) & DCDC_TRG_1_AUTHEN_LOCK_TZ_MASK)

#define DCDC_TRG_1_AUTHEN_LOCK_LIST_MASK         (0x8000U)
#define DCDC_TRG_1_AUTHEN_LOCK_LIST_SHIFT        (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..LOCK_LIST and WHITE_LIST value cannot be changed.
 */
#define DCDC_TRG_1_AUTHEN_LOCK_LIST(x)           (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_1_AUTHEN_LOCK_LIST_SHIFT)) & DCDC_TRG_1_AUTHEN_LOCK_LIST_MASK)

#define DCDC_TRG_1_AUTHEN_WHITE_LIST_MASK        (0xFFFF0000U)
#define DCDC_TRG_1_AUTHEN_WHITE_LIST_SHIFT       (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write TRG_1 registers.
 *  0b0000000000000010..Core with domain ID=1 can write TRG_1 registers.
 *  0b0000000000000100..Core with domain ID=2 can write TRG_1 registers.
 *  0b0000000000001000..Core with domain ID=3 can write TRG_1 registers.
 *  0b0000000000010000..Core with domain ID=4 can write TRG_1 registers.
 *  0b0000000000100000..Core with domain ID=5 can write TRG_1 registers.
 *  0b0000000001000000..Core with domain ID=6 can write TRG_1 registers.
 *  0b0000000010000000..Core with domain ID=7 can write TRG_1 registers.
 *  0b0000000100000000..Core with domain ID=8 can write TRG_1 registers.
 *  0b0000001000000000..Core with domain ID=9 can write TRG_1 registers.
 *  0b0000010000000000..Core with domain ID=10 can write TRG_1 registers.
 *  0b0000100000000000..Core with domain ID=11 can write TRG_1 registers.
 *  0b0001000000000000..Core with domain ID=12 can write TRG_1 registers.
 *  0b0010000000000000..Core with domain ID=13 can write TRG_1 registers.
 *  0b0100000000000000..Core with domain ID=14 can write TRG_1 registers.
 *  0b1000000000000000..Core with domain ID=15 can write TRG_1 registers.
 */
#define DCDC_TRG_1_AUTHEN_WHITE_LIST(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_1_AUTHEN_WHITE_LIST_SHIFT)) & DCDC_TRG_1_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name TRG_SW_1 - Target SW Control for CORE 1 */
/*! @{ */

#define DCDC_TRG_SW_1_VDD1P0CTRL_TRG_MASK        (0x1FU)
#define DCDC_TRG_SW_1_VDD1P0CTRL_TRG_SHIFT       (0U)
#define DCDC_TRG_SW_1_VDD1P0CTRL_TRG(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_1_VDD1P0CTRL_TRG_SHIFT)) & DCDC_TRG_SW_1_VDD1P0CTRL_TRG_MASK)

#define DCDC_TRG_SW_1_VDD1P8CTRL_TRG_MASK        (0x1F00U)
#define DCDC_TRG_SW_1_VDD1P8CTRL_TRG_SHIFT       (8U)
#define DCDC_TRG_SW_1_VDD1P8CTRL_TRG(x)          (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_1_VDD1P8CTRL_TRG_SHIFT)) & DCDC_TRG_SW_1_VDD1P8CTRL_TRG_MASK)

#define DCDC_TRG_SW_1_VDD1P0CTRL_LP_TRG_MASK     (0x1F0000U)
#define DCDC_TRG_SW_1_VDD1P0CTRL_LP_TRG_SHIFT    (16U)
#define DCDC_TRG_SW_1_VDD1P0CTRL_LP_TRG(x)       (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_1_VDD1P0CTRL_LP_TRG_SHIFT)) & DCDC_TRG_SW_1_VDD1P0CTRL_LP_TRG_MASK)

#define DCDC_TRG_SW_1_LP_EN_1P0_MASK             (0x80000000U)
#define DCDC_TRG_SW_1_LP_EN_1P0_SHIFT            (31U)
/*! LP_EN_1P0 - LP_EN_1P0 only controls 1P0. 1P8 is always controlled by VDD1P8CTRL_TRG */
#define DCDC_TRG_SW_1_LP_EN_1P0(x)               (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_SW_1_LP_EN_1P0_SHIFT)) & DCDC_TRG_SW_1_LP_EN_1P0_MASK)
/*! @} */

/*! @name TRG_GPC_1 - Target GPC Control for CORE 1 */
/*! @{ */

#define DCDC_TRG_GPC_1_VDD1P0CTRL_TRG_MASK       (0x1FU)
#define DCDC_TRG_GPC_1_VDD1P0CTRL_TRG_SHIFT      (0U)
#define DCDC_TRG_GPC_1_VDD1P0CTRL_TRG(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_1_VDD1P0CTRL_TRG_SHIFT)) & DCDC_TRG_GPC_1_VDD1P0CTRL_TRG_MASK)

#define DCDC_TRG_GPC_1_VDD1P8CTRL_TRG_MASK       (0x1F00U)
#define DCDC_TRG_GPC_1_VDD1P8CTRL_TRG_SHIFT      (8U)
#define DCDC_TRG_GPC_1_VDD1P8CTRL_TRG(x)         (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_1_VDD1P8CTRL_TRG_SHIFT)) & DCDC_TRG_GPC_1_VDD1P8CTRL_TRG_MASK)

#define DCDC_TRG_GPC_1_VDD1P0CTRL_LP_TRG_MASK    (0x1F0000U)
#define DCDC_TRG_GPC_1_VDD1P0CTRL_LP_TRG_SHIFT   (16U)
#define DCDC_TRG_GPC_1_VDD1P0CTRL_LP_TRG(x)      (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_1_VDD1P0CTRL_LP_TRG_SHIFT)) & DCDC_TRG_GPC_1_VDD1P0CTRL_LP_TRG_MASK)

#define DCDC_TRG_GPC_1_LP_EN_1P0_MASK            (0x80000000U)
#define DCDC_TRG_GPC_1_LP_EN_1P0_SHIFT           (31U)
/*! LP_EN_1P0 - LP_EN_1P0 only controls 1P0. 1P8 is always controlled by VDD1P8CTRL_TRG */
#define DCDC_TRG_GPC_1_LP_EN_1P0(x)              (((uint32_t)(((uint32_t)(x)) << DCDC_TRG_GPC_1_LP_EN_1P0_SHIFT)) & DCDC_TRG_GPC_1_LP_EN_1P0_MASK)
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


#endif  /* PERI_DCDC_H_ */

