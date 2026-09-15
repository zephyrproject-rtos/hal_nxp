/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_PMU.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for PMU
 *
 * CMSIS Peripheral Access Layer for PMU
 */

#if !defined(PERI_PMU_H_)
#define PERI_PMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Peripheral_Access_Layer PMU Peripheral Access Layer
 * @{
 */

/** PMU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t PMU_TEMP_SENSOR;                   /**< Temperature Sensor, offset: 0x4 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PMU_LDO_CTRL_REG;                  /**< Regulator Control, offset: 0x14 */
       uint8_t RESERVED_2[20];
  __IO uint32_t PMU_SENSOR_CTRL0_REG;              /**< Sensor Control 0, offset: 0x2C */
       uint8_t RESERVED_3[8];
  __IO uint32_t PMU_SENSOR_CTRL1_REG;              /**< Sensor Control 1, offset: 0x38 */
       uint8_t RESERVED_4[16];
  __I  uint32_t PMU_STS;                           /**< Status, offset: 0x4C */
  __I  uint32_t PMU_BODYBIAS_VERID_REG;            /**< Body Biasing Version ID, offset: 0x50 */
  __IO uint32_t PMU_BODYBIAS_CONFIG_REG;           /**< Body Biasing Configuration, offset: 0x54 */
  __O  uint32_t PMU_BODYBIAS_COMMAND_REG;          /**< Body Biasing Commands, offset: 0x58 */
  __I  uint32_t PMU_BODYBIAS_STATUS_STS;           /**< Body Biasing Status, offset: 0x5C */
  __I  uint32_t PMU_BODYBIAS_INTSTATUS_STS;        /**< Body Biasing Interrupt Status, offset: 0x60 */
  __IO uint32_t PMU_BODYBIAS_INTENABLE_REG;        /**< Body Biasing Interrupt Enable, offset: 0x64 */
  __O  uint32_t PMU_BODYBIAS_INTCLEAR_REG;         /**< Body Biasing Interrupt Clear, offset: 0x68 */
       uint8_t RESERVED_5[8];
  __IO uint32_t PMU_BODYBIAS_PWPSCFG;              /**< Body Biasing P-Well Power Stage Configuration, offset: 0x74 */
       uint8_t RESERVED_6[8];
  __IO uint32_t PMU_RESETCON_WARM_CTRL;            /**< IRQ Enable for Warm Reset, offset: 0x80 */
  __IO uint32_t PMU_RESETCON_COLD_CTRL;            /**< IRQ Enable for Cold Reset, offset: 0x84 */
  __O  uint32_t PMU_DIG_IRQ_FLAG_CLEAR_REG;        /**< IRQ Flag Clear, offset: 0x88 */
  __I  uint32_t PMU_DIG_IRQ_FLAG_REG;              /**< IRQ Flag, offset: 0x8C */
  __I  uint32_t PMU_DIG_IRQ_STATUS_STS;            /**< IRQ Status, offset: 0x90 */
  __IO uint32_t PMU_DIG_IRQ_EN_REG;                /**< IRQ Enable, offset: 0x94 */
  __IO uint32_t PMU_XOSC32KNP_CTRL_REG;            /**< XOSC32KNP Control, offset: 0x98 */
       uint8_t RESERVED_7[8];
  __I  uint32_t PMU_XOSC32KNP_STS;                 /**< XOSC32KNP Status, offset: 0xA4 */
       uint8_t RESERVED_8[4];
  __IO uint32_t PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG; /**< BUCK_VDD_CORE Analog Control, offset: 0xAC */
       uint8_t RESERVED_9[8];
  __IO uint32_t PMU_BUCK_VDDCORE_CTRL_PWM_REG;     /**< BUCK_VDD_CORE PWM Control, offset: 0xB8 */
} PMU_Type;

/* ----------------------------------------------------------------------------
   -- PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Register_Masks PMU Register Masks
 * @{
 */

/*! @name PMU_TEMP_SENSOR - Temperature Sensor */
/*! @{ */

#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TH_THRE_MASK (0x3U)
#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TH_THRE_SHIFT (0U)
/*! PMU_TEMP_SENSOR_TH_THRE - High Temperature Sensor Threshold
 *  0b00..120degree C
 *  0b01..125degree C
 *  0b10..130degree C
 *  0b11..135degree C
 */
#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TH_THRE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TH_THRE_SHIFT)) & PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TH_THRE_MASK)

#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TL_THRE_MASK (0xCU)
#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TL_THRE_SHIFT (2U)
/*! PMU_TEMP_SENSOR_TL_THRE - Low Temperature Sensor Threshold
 *  0b01..-30degree C
 *  0b10..-40degree C
 */
#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TL_THRE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TL_THRE_SHIFT)) & PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TL_THRE_MASK)

#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TRIM_EN_MASK (0x10U)
#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TRIM_EN_SHIFT (4U)
/*! PMU_TEMP_SENSOR_TRIM_EN - Temperature Sensor Trim Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TRIM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TRIM_EN_SHIFT)) & PMU_PMU_TEMP_SENSOR_PMU_TEMP_SENSOR_TRIM_EN_MASK)
/*! @} */

/*! @name PMU_LDO_CTRL_REG - Regulator Control */
/*! @{ */

#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_BYPASS_MASK (0x20U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_BYPASS_SHIFT (5U)
/*! PMU_VDDA_1V8_BYPASS - VDDA_1V8 Bypass
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_BYPASS_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_BYPASS_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_SEL_MASK (0xC0U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_SEL_SHIFT (6U)
/*! PMU_VDDA_1V8_SEL - VDDA_1V8 Select
 *  0b00..Nominal value
 *  0b01..Nominal value + 5%
 *  0b10..Nominal value + 10%
 *  0b11..Nominal value + 20%
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_SEL_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_SEL_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_DISILIM_MASK (0x100U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_DISILIM_SHIFT (8U)
/*! PMU_VDDA_1V8_DISILIM - VDDA_1V8 Limit Disable
 *  0b0..Limitation at 200 mA is activated
 *  0b1..Disables limitation
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_DISILIM(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_DISILIM_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDDA_1V8_DISILIM_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_BYPASS_MASK (0x200U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_BYPASS_SHIFT (9U)
/*! PMU_VDD_1V8_BYPASS - VDD_1V8 Bypass
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_BYPASS_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_BYPASS_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_SEL_MASK (0xC00U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_SEL_SHIFT (10U)
/*! PMU_VDD_1V8_SEL - VDD_1V8 Select
 *  0b00..Nominal value
 *  0b01..Nominal value + 5%
 *  0b10..Nominal value + 10%
 *  0b11..Nominal value + 20%
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_SEL(x)  (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_SEL_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_SEL_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_DISILIM_MASK (0x1000U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_DISILIM_SHIFT (12U)
/*! PMU_VDD_1V8_DISILIM - VDD_1V8 Limit Disable
 *  0b0..Limitation at 200 mA is activated
 *  0b1..Disables limitation
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_DISILIM(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_DISILIM_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDD_1V8_DISILIM_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_SEL_MASK (0x6000U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_SEL_SHIFT (13U)
/*! PMU_VDD_0V8_SEL - VDD_0V8 Select
 *  0b00..Nominal value
 *  0b01..Nominal value + 5%
 *  0b10..Nominal value + 10%
 *  0b11..Nominal value + 20%
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_SEL(x)  (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_SEL_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_SEL_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_BYPASS_MASK (0x8000U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_BYPASS_SHIFT (15U)
/*! PMU_VDD_0V8_BYPASS - VDD_0V8 Bypass
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_BYPASS_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_BYPASS_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_DISILIM_MASK (0x10000U)
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_DISILIM_SHIFT (16U)
/*! PMU_VDD_0V8_DISILIM - VDD_0V8 Limit Disable
 *  0b0..Limitation at 100 mA is activated
 *  0b1..Disables limitation
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_DISILIM(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_DISILIM_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_VDD_0V8_DISILIM_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_1V8_SEL_MASK (0x60000U)
#define PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_1V8_SEL_SHIFT (17U)
/*! PMU_LPVDDREG_1V8_SEL - Low-Power VDD_1V8 Regulator Select
 *  0b00..Nominal value
 *  0b01..Nominal value + 5%
 *  0b10..Nominal value +10%
 *  0b11..Nominal value + 20%
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_1V8_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_1V8_SEL_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_1V8_SEL_MASK)

#define PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_0V8_SEL_MASK (0x180000U)
#define PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_0V8_SEL_SHIFT (19U)
/*! PMU_LPVDDREG_0V8_SEL - Low-Power VDD_0V8 Regulator Select
 *  0b00..Nominal value
 *  0b01..Nominal value + 5%
 *  0b10..Nominal value +10%
 *  0b11..Nominal value + 20%
 */
#define PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_0V8_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_0V8_SEL_SHIFT)) & PMU_PMU_LDO_CTRL_REG_PMU_LPVDDREG_0V8_SEL_MASK)
/*! @} */

/*! @name PMU_SENSOR_CTRL0_REG - Sensor Control 0 */
/*! @{ */

#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_LOWER_THRES_MASK (0x3U)
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_LOWER_THRES_SHIFT (0U)
/*! PMU_SENSOR_VDD_CORE_LOWER_THRES - VDD_CORE Sensor Lower Threshold
 *  0b00..0.725 V
 *  0b01..0.675 V
 *  0b10..0.625 V
 *  0b11..0.575 V
 */
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_LOWER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_LOWER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_LOWER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_UPPER_THRES_MASK (0xCU)
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_UPPER_THRES_SHIFT (2U)
/*! PMU_SENSOR_VDD_CORE_UPPER_THRES - VDD_CORE Sensor Upper Threshold
 *  0b00..0.875 V
 *  0b01..0.925 V
 *  0b10..0.975 V
 *  0b11..1.025 V
 */
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_UPPER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_UPPER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD_CORE_UPPER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_LOWER_THRES_MASK (0x30U)
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_LOWER_THRES_SHIFT (4U)
/*! PMU_SENSOR_VDD0V8_LOWER_THRES - VDD_0V8 Sensor Lower Threshold
 *  0b00..0.725 V
 *  0b01..0.675 V
 *  0b10..0.625 V
 *  0b11..0.575 V
 */
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_LOWER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_LOWER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_LOWER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_UPPER_THRES_MASK (0xC0U)
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_UPPER_THRES_SHIFT (6U)
/*! PMU_SENSOR_VDD0V8_UPPER_THRES - VDD_0V8 Sensor Upper Threshold
 *  0b00..0.875 V
 *  0b01..0.925 V
 *  0b10..0.975 V
 *  0b11..1.025 V
 */
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_UPPER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_UPPER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD0V8_UPPER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_LOWER_THRES_MASK (0x300U)
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_LOWER_THRES_SHIFT (8U)
/*! PMU_SENSOR_VDD1V8_LOWER_THRES - VDD_1V8 Sensor Lower Threshold
 *  0b00..1.65 V
 *  0b01..1.6 V
 *  0b10..1.55 V
 *  0b11..1.5 V
 */
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_LOWER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_LOWER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_LOWER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_UPPER_THRES_MASK (0xC00U)
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_UPPER_THRES_SHIFT (10U)
/*! PMU_SENSOR_VDD1V8_UPPER_THRES - VDD_1V8 Sensor Upper Threshold
 *  0b00..2.05 V
 *  0b01..2.1 V
 *  0b10..2.15 V
 *  0b11..2.2 V
 */
#define PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_UPPER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_UPPER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL0_REG_PMU_SENSOR_VDD1V8_UPPER_THRES_MASK)
/*! @} */

/*! @name PMU_SENSOR_CTRL1_REG - Sensor Control 1 */
/*! @{ */

#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_LOWER_THRES_MASK (0x3U)
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_LOWER_THRES_SHIFT (0U)
/*! PMU_SENSOR_VDD_PMU3V_LOWER_THRES - VDD_PMU_3V Sensor Lower Threshold
 *  0b00..2.35 V
 *  0b01..2.3 V
 *  0b10..2.25 V
 *  0b11..2.2 V
 */
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_LOWER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_LOWER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_LOWER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_UPPER_THRES_MASK (0xCU)
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_UPPER_THRES_SHIFT (2U)
/*! PMU_SENSOR_VDD_PMU3V_UPPER_THRES - VDD_PMU_3V Sensor Upper Threshold
 *  0b00..3.7 V
 *  0b01..3.75 V
 *  0b10..3.8 V
 *  0b11..3.85 V
 */
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_UPPER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_UPPER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU3V_UPPER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_LOWER_THRES_MASK (0x30U)
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_LOWER_THRES_SHIFT (4U)
/*! PMU_SENSOR_VDD_PMU1V8_LOWER_THRES - VDD_PMU_1V8 Sensor Lower Threshold
 *  0b00..1.65 V
 *  0b01..1.6 V
 *  0b10..1.55 V
 *  0b11..1.5 V
 */
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_LOWER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_LOWER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_LOWER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_UPPER_THRES_MASK (0xC0U)
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_UPPER_THRES_SHIFT (6U)
/*! PMU_SENSOR_VDD_PMU1V8_UPPER_THRES - VDD_PMU_1V8 Sensor Upper Threshold
 *  0b00..2.05 V
 *  0b01..2.1 V
 *  0b10..2.15 V
 *  0b11..2.2 V
 */
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_UPPER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_UPPER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDD_PMU1V8_UPPER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_LOWER_THRES_MASK (0x300U)
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_LOWER_THRES_SHIFT (8U)
/*! PMU_SENSOR_VDDA1V8_LOWER_THRES - VDDA_1V8 Sensor Lower Threshold
 *  0b00..1.65 V
 *  0b01..1.6 V
 *  0b10..1.55 V
 *  0b11..1.5 V
 */
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_LOWER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_LOWER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_LOWER_THRES_MASK)

#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_UPPER_THRES_MASK (0xC00U)
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_UPPER_THRES_SHIFT (10U)
/*! PMU_SENSOR_VDDA1V8_UPPER_THRES - VDDA_1V8 Sensor Upper Threshold
 *  0b00..2.05 V
 *  0b01..2.1 V
 *  0b10..2.15 V
 *  0b11..2.2 V
 */
#define PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_UPPER_THRES(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_UPPER_THRES_SHIFT)) & PMU_PMU_SENSOR_CTRL1_REG_PMU_SENSOR_VDDA1V8_UPPER_THRES_MASK)
/*! @} */

/*! @name PMU_STS - Status */
/*! @{ */

#define PMU_PMU_STS_PMU_TEMP_SENSOR_HT_OK_MASK   (0x1U)
#define PMU_PMU_STS_PMU_TEMP_SENSOR_HT_OK_SHIFT  (0U)
/*! PMU_TEMP_SENSOR_HT_OK - Temperature Sensor High Temperature OK
 *  0b0..Temperature reaches the threshold
 *  0b1..Temperature is below the threshold
 */
#define PMU_PMU_STS_PMU_TEMP_SENSOR_HT_OK(x)     (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_TEMP_SENSOR_HT_OK_SHIFT)) & PMU_PMU_STS_PMU_TEMP_SENSOR_HT_OK_MASK)

#define PMU_PMU_STS_PMU_TEMP_SENSOR_LT_OK_MASK   (0x2U)
#define PMU_PMU_STS_PMU_TEMP_SENSOR_LT_OK_SHIFT  (1U)
/*! PMU_TEMP_SENSOR_LT_OK - Temperature Sensor Low Temperature OK
 *  0b0..Temperature reaches the threshold
 *  0b1..Temperature is below the threshold
 */
#define PMU_PMU_STS_PMU_TEMP_SENSOR_LT_OK(x)     (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_TEMP_SENSOR_LT_OK_SHIFT)) & PMU_PMU_STS_PMU_TEMP_SENSOR_LT_OK_MASK)

#define PMU_PMU_STS_PMU_MONITOR_VDDCORE_OK_MASK  (0x4U)
#define PMU_PMU_STS_PMU_MONITOR_VDDCORE_OK_SHIFT (2U)
/*! PMU_MONITOR_VDDCORE_OK - VDD_CORE Monitor OK
 *  0b0..VDD_CORE voltage is not ok
 *  0b1..VDD_CORE voltage is ok
 */
#define PMU_PMU_STS_PMU_MONITOR_VDDCORE_OK(x)    (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_MONITOR_VDDCORE_OK_SHIFT)) & PMU_PMU_STS_PMU_MONITOR_VDDCORE_OK_MASK)

#define PMU_PMU_STS_PMU_MONITOR_VDD0V8_OK_MASK   (0x8U)
#define PMU_PMU_STS_PMU_MONITOR_VDD0V8_OK_SHIFT  (3U)
/*! PMU_MONITOR_VDD0V8_OK - VDD_0V8 Monitor OK
 *  0b0..VDD_0V8 voltage is not ok
 *  0b1..VDD_0V8 voltage is ok
 */
#define PMU_PMU_STS_PMU_MONITOR_VDD0V8_OK(x)     (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_MONITOR_VDD0V8_OK_SHIFT)) & PMU_PMU_STS_PMU_MONITOR_VDD0V8_OK_MASK)

#define PMU_PMU_STS_PMU_MONITOR_VDD1V8_OK_MASK   (0x10U)
#define PMU_PMU_STS_PMU_MONITOR_VDD1V8_OK_SHIFT  (4U)
/*! PMU_MONITOR_VDD1V8_OK - VDD_1V8 Monitor OK
 *  0b0..VDD_1V8 voltage is not ok
 *  0b1..VDD_1V8 voltage is ok
 */
#define PMU_PMU_STS_PMU_MONITOR_VDD1V8_OK(x)     (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_MONITOR_VDD1V8_OK_SHIFT)) & PMU_PMU_STS_PMU_MONITOR_VDD1V8_OK_MASK)

#define PMU_PMU_STS_PMU_MONITOR_VDDA1V8_OK_MASK  (0x20U)
#define PMU_PMU_STS_PMU_MONITOR_VDDA1V8_OK_SHIFT (5U)
/*! PMU_MONITOR_VDDA1V8_OK - VDDA_1V8 Monitor OK
 *  0b0..VDDA_1V8 voltage is not ok
 *  0b1..VDDA_1V8 voltage is ok
 */
#define PMU_PMU_STS_PMU_MONITOR_VDDA1V8_OK(x)    (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_MONITOR_VDDA1V8_OK_SHIFT)) & PMU_PMU_STS_PMU_MONITOR_VDDA1V8_OK_MASK)

#define PMU_PMU_STS_PMU_MONITOR_VDDPMU_1V8_OK_MASK (0x40U)
#define PMU_PMU_STS_PMU_MONITOR_VDDPMU_1V8_OK_SHIFT (6U)
/*! PMU_MONITOR_VDDPMU_1V8_OK - VDD_PMU_1V8 Monitor OK
 *  0b0..VDD_PMU_1V8 voltage is not ok
 *  0b1..VDD_PMU_1V8 voltage is ok
 */
#define PMU_PMU_STS_PMU_MONITOR_VDDPMU_1V8_OK(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_MONITOR_VDDPMU_1V8_OK_SHIFT)) & PMU_PMU_STS_PMU_MONITOR_VDDPMU_1V8_OK_MASK)

#define PMU_PMU_STS_PMU_MONITOR_VDDPMU_3V_OK_MASK (0x80U)
#define PMU_PMU_STS_PMU_MONITOR_VDDPMU_3V_OK_SHIFT (7U)
/*! PMU_MONITOR_VDDPMU_3V_OK - VDD_PMU_3V Monitor OK
 *  0b0..VDD_PMU_3V voltage is not ok
 *  0b1..VDD_PMU_3V voltage is ok
 */
#define PMU_PMU_STS_PMU_MONITOR_VDDPMU_3V_OK(x)  (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_MONITOR_VDDPMU_3V_OK_SHIFT)) & PMU_PMU_STS_PMU_MONITOR_VDDPMU_3V_OK_MASK)

#define PMU_PMU_STS_PMU_BOOT_ERROR_STS_MASK      (0x3F00U)
#define PMU_PMU_STS_PMU_BOOT_ERROR_STS_SHIFT     (8U)
/*! PMU_BOOT_ERROR_STS - Boot Error Status
 *  0b000000..No error
 *  0b000001..PMU_HQREF_SETTLE: HQ_VREF_OK not asserted during cold boot
 *  0b000010..PMU_VDDCOREAON_SETTLE: VDD_CORE_AON OK not asserted during cold boot
 *  0b000011..PMU_LDO_SETTLE: PMU_MONITOR_VDD(A)1V8_OK not asserted during cold boot
 *  0b000100..PMU_VDD_0V8_SETTLE: PMU_MONITOR_VDD0V8_OK not asserted during cold boot
 *  0b000101..PMU_PFM_SETTLE: PFM_RDY not asserted during cold boot
 *  0b000110..PMU_MON_VDDCORE_SETTLE: VDD_CORE_OK not asserted during cold boot
 *  0b000111..CGU_OTP_RDY_WAIT: 192M not ready for OTP
 *  0b001000..PMU_OTP_SETTLE: OTP_RDY not asserted
 *  0b001001..CGU_RDY_WAIT_SETTLE: 192M not ready for DC-DC PWM mode
 *  0b001010..PMU_PWM_SETTLE: PMU_PWM_SETTLE
 *  0b001011..PMU_VOLT_CHECK: Not all main voltages are OK
 *  0b001100..PMU_PLL_OK_SETTLE: 192M or MAINPLL not ready
 *  0b001101..PMU_BODY_BIAS_WAIT_OK_SETTLE: PWELL_OK or NWELL_OK are not OK
 *  0b001110..PMU_HP_UPDATE: Clocks asked with PSTATE not ready
 *  0b001111..PMU_PFM_LP_SETTLE: PFM_RDY not okay if PFM is required on LP
 *  0b010000..RET_HQ_REF_OFF_SETTLE: DPD_RDY not asserted if required and not externally supplied
 *  0b010001..PMU_RET_EXIT_SETTLE: HQ_VREF_OK not asserted when waking up from PMU_RET
 *  0b010010..PMU_LP_EXIT_SETTLE: Not all main voltages are OK when waking up from PMU_LP
 *  0b010011..CGU_REQ_FROM_LP: VDD_CORE is not ready when waking up from PMU_LP
 *  0b010100..WARM_RESET_CGU_OFF_SETTLE: Clocks de-assert not confirmed by CGU during warm reset
 *  0b010101..PMU_HQREF_SETTLE: HQ_VREF_OK not asserted during warm reset
 *  0b010110..PMU_LDO_SETTLE: PMU_MONITOR_VDD(A)1V8_OK not asserted during warm reset
 *  0b010111..PMU_VDD_0V8_SETTLE: PMU_MONITOR_VDD0V8_OK not asserted during warm reset
 *  0b011000..PMU_PFM_SETTLE: PFM_RDY not asserted during warm reset
 *  0b011001..PMU_MON_VDDCORE_SETTLE: VDD_CORE_OK not asserted during warm reset
 */
#define PMU_PMU_STS_PMU_BOOT_ERROR_STS(x)        (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_BOOT_ERROR_STS_SHIFT)) & PMU_PMU_STS_PMU_BOOT_ERROR_STS_MASK)

#define PMU_PMU_STS_PMU_LFRO32K_RDY_MASK         (0x4000U)
#define PMU_PMU_STS_PMU_LFRO32K_RDY_SHIFT        (14U)
/*! PMU_LFRO32K_RDY - LFRO_32K Ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define PMU_PMU_STS_PMU_LFRO32K_RDY(x)           (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_LFRO32K_RDY_SHIFT)) & PMU_PMU_STS_PMU_LFRO32K_RDY_MASK)

#define PMU_PMU_STS_PMU_XTAL32K_RDY_MASK         (0x8000U)
#define PMU_PMU_STS_PMU_XTAL32K_RDY_SHIFT        (15U)
/*! PMU_XTAL32K_RDY - XTAL 32K Ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define PMU_PMU_STS_PMU_XTAL32K_RDY(x)           (((uint32_t)(((uint32_t)(x)) << PMU_PMU_STS_PMU_XTAL32K_RDY_SHIFT)) & PMU_PMU_STS_PMU_XTAL32K_RDY_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_VERID_REG - Body Biasing Version ID */
/*! @{ */

#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_FEATURE_MASK (0xFU)
#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_FEATURE_SHIFT (0U)
/*! PMU_BB_FEATURE - Feature
 *  0b0001..Standard feature set
 *  0b0011..Standard feature set with adaptative dynamic voltage control (ADVC) support
 */
#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_FEATURE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_FEATURE_SHIFT)) & PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_FEATURE_MASK)

#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MINOR_MASK (0x30000U)
#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MINOR_SHIFT (16U)
/*! PMU_BB_MINOR - Minor Version */
#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MINOR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MINOR_SHIFT)) & PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MINOR_MASK)

#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MAJOR_MASK (0x3000000U)
#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MAJOR_SHIFT (24U)
/*! PMU_BB_MAJOR - Major Version */
#define PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MAJOR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MAJOR_SHIFT)) & PMU_PMU_BODYBIAS_VERID_REG_PMU_BB_MAJOR_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_CONFIG_REG - Body Biasing Configuration */
/*! @{ */

#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_MODE_SEL_MASK (0x7U)
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_MODE_SEL_SHIFT (0U)
/*! PMU_BB_MODE_SEL - Mode Select
 *  0b000..Zero body biasing (no body biasing)
 *  0b001..N-well enabled, P-well enabled
 *  0b010..N-well disabled, P-well enabled
 *  0b011..N-well enabled, P-well disabled
 *  0b100..
 *  0b101..Standby
 */
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_MODE_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_MODE_SEL_SHIFT)) & PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_MODE_SEL_MASK)

#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_CLK_SEL_MASK (0x30U)
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_CLK_SEL_SHIFT (4U)
/*! PMU_BB_PWELL_CLK_SEL - PMOS Well (P-Well) Charge-Pump Clock Configuration
 *  0b00..CLK_IN_12M (no clock division)
 *  0b01..CLK_IN_12M / 2 (divide by 2)
 *  0b10..CLK_IN_12M / 4 (divide by 4)
 *  0b11..CLK_IN_12M / 8 (divide by 8)
 */
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_CLK_SEL_SHIFT)) & PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_CLK_SEL_MASK)

#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_RAMP_CLK_SEL_MASK (0xC0U)
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_RAMP_CLK_SEL_SHIFT (6U)
/*! PMU_BB_RAMP_CLK_SEL - Well Voltage Change Slope Control
 *  0b00..0.750 MHz
 *  0b01..0.667 MHz
 *  0b10..0.375 MHz
 *  0b11..1.2 MHz
 */
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_RAMP_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_RAMP_CLK_SEL_SHIFT)) & PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_RAMP_CLK_SEL_MASK)

#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_ADVC_MASK (0x8000U)
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_ADVC_SHIFT (15U)
/*! PMU_BB_ADVC - Adaptative Dynamic Voltage Control (ADVC)
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_ADVC(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_ADVC_SHIFT)) & PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_ADVC_MASK)

#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_NWELL_V_SEL_MASK (0x7F0000U)
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_NWELL_V_SEL_SHIFT (16U)
/*! PMU_BB_NWELL_V_SEL - N-Well Voltage Select
 *  0b0000000-0b0000110..Vnwell = 0.150 V
 *  0b0000111..Vnwell = 0.175 V
 *  0b0001000..Vnwell = 0.200 V
 *  0b0001001-0b0111110.....
 *  0b0111111..Vnwell = 1.575 V
 */
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_NWELL_V_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_NWELL_V_SEL_SHIFT)) & PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_NWELL_V_SEL_MASK)

#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_V_SEL_MASK (0x7F000000U)
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_V_SEL_SHIFT (24U)
/*! PMU_BB_PWELL_V_SEL - P-Well Voltage Select
 *  0b0000000-0b0000100..Vpwell = -0.100 V
 *  0b0000101..Vpwell = -0.125 V
 *  0b0000110..Vpwell = -0.150 V
 *  0b0000111-0b1001010.....
 *  0b1001011..Vpwell = -1.875 V
 */
#define PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_V_SEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_V_SEL_SHIFT)) & PMU_PMU_BODYBIAS_CONFIG_REG_PMU_BB_PWELL_V_SEL_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_COMMAND_REG - Body Biasing Commands */
/*! @{ */

#define PMU_PMU_BODYBIAS_COMMAND_REG_PMU_BB_CFG_UPDATE_MASK (0x1U)
#define PMU_PMU_BODYBIAS_COMMAND_REG_PMU_BB_CFG_UPDATE_SHIFT (0U)
/*! PMU_BB_CFG_UPDATE - Configuration Update
 *  0b0..No effect
 *  0b1..Configuration updated
 */
#define PMU_PMU_BODYBIAS_COMMAND_REG_PMU_BB_CFG_UPDATE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_COMMAND_REG_PMU_BB_CFG_UPDATE_SHIFT)) & PMU_PMU_BODYBIAS_COMMAND_REG_PMU_BB_CFG_UPDATE_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_STATUS_STS - Body Biasing Status */
/*! @{ */

#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_OK_MASK (0x1U)
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_OK_SHIFT (0U)
/*! PMU_BB_NWELL_V_OK - N-Well Voltage OK
 *  0b0..Not reached yet
 *  0b1..Reached
 */
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_OK(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_OK_SHIFT)) & PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_OK_MASK)

#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_OK_MASK (0x2U)
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_OK_SHIFT (1U)
/*! PMU_BB_PWELL_V_OK - P-Well Voltage OK
 *  0b0..Not reached yet
 *  0b1..Reached
 */
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_OK(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_OK_SHIFT)) & PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_OK_MASK)

#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_SAFE_STATE_MASK (0x4U)
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_SAFE_STATE_SHIFT (2U)
/*! PMU_BB_SAFE_STATE - Safe State
 *  0b0..An issue was met during initialization phase
 *  0b1..Operating normally
 */
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_SAFE_STATE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_SAFE_STATE_SHIFT)) & PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_SAFE_STATE_MASK)

#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_STATE_MASK (0x7F0000U)
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_STATE_SHIFT (16U)
/*! PMU_BB_NWELL_V_STATE - N-Well Current Voltage */
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_STATE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_STATE_SHIFT)) & PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_NWELL_V_STATE_MASK)

#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_STATE_MASK (0x7F000000U)
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_STATE_SHIFT (24U)
/*! PMU_BB_PWELL_V_STATE - P-Well Current Voltage */
#define PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_STATE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_STATE_SHIFT)) & PMU_PMU_BODYBIAS_STATUS_STS_PMU_BB_PWELL_V_STATE_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_INTSTATUS_STS - Body Biasing Interrupt Status */
/*! @{ */

#define PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_DONE_MASK (0x1U)
#define PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_DONE_SHIFT (0U)
/*! PMU_BB_CFG_DONE - Configuration Done
 *  0b0..Not completed
 *  0b1..Completed
 */
#define PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_DONE_SHIFT)) & PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_DONE_MASK)

#define PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_ERROR_MASK (0x2U)
#define PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_ERROR_SHIFT (1U)
/*! PMU_BB_CFG_ERROR - Configuration Error
 *  0b0..No error
 *  0b1..Error occurred
 */
#define PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_ERROR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_ERROR_SHIFT)) & PMU_PMU_BODYBIAS_INTSTATUS_STS_PMU_BB_CFG_ERROR_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_INTENABLE_REG - Body Biasing Interrupt Enable */
/*! @{ */

#define PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_DONE_MASK (0x1U)
#define PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_DONE_SHIFT (0U)
/*! PMU_BB_ENA_CFG_DONE - Configuration Done Enable
 *  0b0..Disables CFG_DONE interrupt
 *  0b1..Enables CFG_DONE interrupt
 */
#define PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_DONE_SHIFT)) & PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_DONE_MASK)

#define PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_ERROR_MASK (0x2U)
#define PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_ERROR_SHIFT (1U)
/*! PMU_BB_ENA_CFG_ERROR - Configuration Error Enable
 *  0b0..Disables CFG_DONE interrupt
 *  0b1..Enables CFG_DONE interrupt
 */
#define PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_ERROR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_ERROR_SHIFT)) & PMU_PMU_BODYBIAS_INTENABLE_REG_PMU_BB_ENA_CFG_ERROR_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_INTCLEAR_REG - Body Biasing Interrupt Clear */
/*! @{ */

#define PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_DONE_MASK (0x1U)
#define PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_DONE_SHIFT (0U)
/*! PMU_BB_CLR_CFG_DONE - Configuration Done Clear
 *  0b0..No effect
 *  0b1..Clears CFG_DONE interrupt
 */
#define PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_DONE_SHIFT)) & PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_DONE_MASK)

#define PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_ERROR_MASK (0x2U)
#define PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_ERROR_SHIFT (1U)
/*! PMU_BB_CLR_CFG_ERROR - Configuration Error Clear
 *  0b0..No effect
 *  0b1..Clears CFG_ERROR interrupt
 */
#define PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_ERROR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_ERROR_SHIFT)) & PMU_PMU_BODYBIAS_INTCLEAR_REG_PMU_BB_CLR_CFG_ERROR_MASK)
/*! @} */

/*! @name PMU_BODYBIAS_PWPSCFG - Body Biasing P-Well Power Stage Configuration */
/*! @{ */

#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_1_LL_MASK (0x7FU)
#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_1_LL_SHIFT (0U)
/*! PMU_BB_STRENGTH_1_LL - Second Strength Lower Limit */
#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_1_LL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_1_LL_SHIFT)) & PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_1_LL_MASK)

#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_2_LL_MASK (0x3F80U)
#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_2_LL_SHIFT (7U)
/*! PMU_BB_STRENGTH_2_LL - Third Strength Lower Limit */
#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_2_LL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_2_LL_SHIFT)) & PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_2_LL_MASK)

#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_3_LL_MASK (0x1FC000U)
#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_3_LL_SHIFT (14U)
/*! PMU_BB_STRENGTH_3_LL - Fourth Strength Lower Limit */
#define PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_3_LL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_3_LL_SHIFT)) & PMU_PMU_BODYBIAS_PWPSCFG_PMU_BB_STRENGTH_3_LL_MASK)
/*! @} */

/*! @name PMU_RESETCON_WARM_CTRL - IRQ Enable for Warm Reset */
/*! @{ */

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK (0x1U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT (0U)
/*! PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN - VDD_1V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK (0x2U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT (1U)
/*! PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN - VDD_1V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK (0x4U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT (2U)
/*! PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_WARM_EN - VDD_CORE Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK (0x8U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT (3U)
/*! PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_WARM_EN - VDD_CORE Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK (0x10U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT (4U)
/*! PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_WARM_EN - VDD_0V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK (0x20U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT (5U)
/*! PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_WARM_EN - VDD_0V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK (0x40U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT (6U)
/*! PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN - VDDA_1V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK (0x80U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT (7U)
/*! PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN - VDDA_1V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK (0x100U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT (8U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN - VDD_PMU_1V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK (0x200U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT (9U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN - VDD_PMU_1V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK (0x400U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT (10U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_WARM_EN - VDD_PMU_3V Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK (0x800U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT (11U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_WARM_EN - VDD_PMU_3V Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_WARM_EN_MASK (0x2000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_WARM_EN_SHIFT (13U)
/*! PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_WARM_EN - VDD_1V8_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_WARM_EN_MASK (0x4000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_WARM_EN_SHIFT (14U)
/*! PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_WARM_EN - VDDA_1V8_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_WARM_EN_MASK (0x20000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_WARM_EN_SHIFT (17U)
/*! PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_WARM_EN - VDD_PMU_3V_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_WARM_EN_MASK (0x40000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_WARM_EN_SHIFT (18U)
/*! PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_WARM_EN - TEMP_SENSOR_HT_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_WARM_EN_MASK (0x80000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_WARM_EN_SHIFT (19U)
/*! PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_WARM_EN - TEMP_SENSOR_LT_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_WARM_EN_MASK (0x100000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_WARM_EN_SHIFT (20U)
/*! PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_WARM_EN - BUCK_VDDCORE Clock Lost Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_WARM_EN_MASK (0x200000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_WARM_EN_SHIFT (21U)
/*! PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_WARM_EN - BUCK_VDDCORE IRQ Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_WARM_EN_MASK)

#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_WARM_EN_MASK (0x400000U)
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_WARM_EN_SHIFT (22U)
/*! PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_WARM_EN - BUCK_VDDCORE OCL Warning Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_WARM_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_WARM_EN_SHIFT)) & PMU_PMU_RESETCON_WARM_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_WARM_EN_MASK)
/*! @} */

/*! @name PMU_RESETCON_COLD_CTRL - IRQ Enable for Cold Reset */
/*! @{ */

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK (0x1U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT (0U)
/*! PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN - VDD_1V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK (0x2U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT (1U)
/*! PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN - VDD_1V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK (0x4U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT (2U)
/*! PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_COLD_EN - VDD_CORE Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK (0x8U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT (3U)
/*! PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_COLD_EN - VDD_CORE Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK (0x10U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT (4U)
/*! PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_COLD_EN - VDD_0V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK (0x20U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT (5U)
/*! PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_COLD_EN - VDD_0V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK (0x40U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT (6U)
/*! PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN - VDDA_1V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK (0x80U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT (7U)
/*! PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN - VDDA_1V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK (0x100U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT (8U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN - VDD_PMU_1V8 Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK (0x200U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT (9U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN - VDD_PMU_1V8 Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK (0x400U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT (10U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_COLD_EN - VDD_PMU_3V Vmin Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK (0x800U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT (11U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_COLD_EN - VDD_PMU_3V Vmax Error Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD0V8_OK_ASYNC_RESET_COLD_EN_MASK (0x1000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD0V8_OK_ASYNC_RESET_COLD_EN_SHIFT (12U)
/*! PMU_DIG_MONITOR_VDD0V8_OK_ASYNC_RESET_COLD_EN - VDD_0V8_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD0V8_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD0V8_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD0V8_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_COLD_EN_MASK (0x2000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_COLD_EN_SHIFT (13U)
/*! PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_COLD_EN - VDD_1V8_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDD1V8_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_COLD_EN_MASK (0x4000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_COLD_EN_SHIFT (14U)
/*! PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_COLD_EN - VDDA_1V8_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDA1V8_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDCORE_OK_ASYNC_RESET_COLD_EN_MASK (0x8000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDCORE_OK_ASYNC_RESET_COLD_EN_SHIFT (15U)
/*! PMU_DIG_MONITOR_VDDCORE_OK_ASYNC_RESET_COLD_EN - VDD_CORE_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDCORE_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDCORE_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDCORE_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_1V8_OK_ASYNC_RESET_COLD_EN_MASK (0x10000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_1V8_OK_ASYNC_RESET_COLD_EN_SHIFT (16U)
/*! PMU_DIG_MONITOR_VDDPMU_1V8_OK_ASYNC_RESET_COLD_EN - VDD_PMU_1V8_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_1V8_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_1V8_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_1V8_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_COLD_EN_MASK (0x20000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_COLD_EN_SHIFT (17U)
/*! PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_COLD_EN - VDD_PMU_3V_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_MONITOR_VDDPMU_3V_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_COLD_EN_MASK (0x40000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_COLD_EN_SHIFT (18U)
/*! PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_COLD_EN - TEMP_SENSOR_HT_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_HT_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_COLD_EN_MASK (0x80000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_COLD_EN_SHIFT (19U)
/*! PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_COLD_EN - TEMP_SENSOR_LT_OK Monitor Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_TEMP_SENSOR_LT_OK_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_COLD_EN_MASK (0x100000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_COLD_EN_SHIFT (20U)
/*! PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_COLD_EN - BUCK_VDD_CORE Clock Lost Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_CLK_LOST_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_COLD_EN_MASK (0x200000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_COLD_EN_SHIFT (21U)
/*! PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_COLD_EN - BUCK_VDD_CORE IRQ Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_IRQ_ASYNC_RESET_COLD_EN_MASK)

#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_COLD_EN_MASK (0x400000U)
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_COLD_EN_SHIFT (22U)
/*! PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_COLD_EN - BUCK_VDD_CORE OCL Reset Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_COLD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_COLD_EN_SHIFT)) & PMU_PMU_RESETCON_COLD_CTRL_PMU_DIG_BUCK_VDDCORE_OCL_WARN_ASYNC_RESET_COLD_EN_MASK)
/*! @} */

/*! @name PMU_DIG_IRQ_FLAG_CLEAR_REG - IRQ Flag Clear */
/*! @{ */

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK (0x1U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT (0U)
/*! PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_CLEAR - VDD_1V8 Vmin Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK (0x2U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT (1U)
/*! PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_CLEAR - VDD_1V8 Vmax Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK (0x4U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT (2U)
/*! PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_CLEAR - VDD_CORE Vmin Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK (0x8U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT (3U)
/*! PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_CLEAR - VDD_CORE Vmax Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK (0x10U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT (4U)
/*! PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_CLEAR - VDD_0V8 Vmin Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK (0x20U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT (5U)
/*! PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_CLEAR - VDD_0V8 Vmax Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK (0x40U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT (6U)
/*! PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_CLEAR - VDDA_1V8 Vmin Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK (0x80U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT (7U)
/*! PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_CLEAR - VDDA_1V8 Vmax Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK (0x100U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT (8U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_CLEAR - VDD_PMU_1V8 Vmin Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK (0x200U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT (9U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_CLEAR - VDD_PMU_1V8 Vmax Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK (0x400U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT (10U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_CLEAR - VDD_PMU_3V Vmin Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK (0x800U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT (11U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_CLEAR - VDD_PMU_3V Vmax Error Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_CLEAR_MASK (0x2000U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_CLEAR_SHIFT (13U)
/*! PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_CLEAR - VDD_1V8_OK Monitor Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_CLEAR_MASK (0x20000U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_CLEAR_SHIFT (17U)
/*! PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_CLEAR - VDD_PMU_3V_OK Monitor Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_CLEAR_MASK (0x40000U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_CLEAR_SHIFT (18U)
/*! PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_CLEAR - TEMP_SENSOR_HT_OK Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_CLEAR_MASK (0x80000U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_CLEAR_SHIFT (19U)
/*! PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_CLEAR - TEMP_SENSOR_LT_OK Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_CLEAR_MASK (0x100000U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_CLEAR_SHIFT (20U)
/*! PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_CLEAR - BUCK_VDD_CORE Clock Lost Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_CLEAR_MASK (0x200000U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_CLEAR_SHIFT (21U)
/*! PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_CLEAR - BUCK_VDD_CORE IRQ Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_CLEAR_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_CLEAR_MASK (0x400000U)
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_CLEAR_SHIFT (22U)
/*! PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_CLEAR - BUCK_VDD_CORE OCL Flag Clear
 *  0b0..No action
 *  0b1..Removes interrupt level
 */
#define PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_CLEAR_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_CLEAR_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_CLEAR_MASK)
/*! @} */

/*! @name PMU_DIG_IRQ_FLAG_REG - IRQ Flag */
/*! @{ */

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_MASK (0x1U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_SHIFT (0U)
/*! PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG - VDD_1V8 Vmin Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_MASK (0x2U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_SHIFT (1U)
/*! PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG - VDD_1V8 Vmax Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_MASK (0x4U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_SHIFT (2U)
/*! PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG - VDD_CORE Vmin Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_MASK (0x8U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_SHIFT (3U)
/*! PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG - VDD_CORE Vmax Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_MASK (0x10U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_SHIFT (4U)
/*! PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG - VDD_0V8 Vmin Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_MASK (0x20U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_SHIFT (5U)
/*! PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG - VDD_0V8 Vmax Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_MASK (0x40U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_SHIFT (6U)
/*! PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG - VDDA_1V8 Vmin Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_MASK (0x80U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_SHIFT (7U)
/*! PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG - VDDA_1V8 Vmax Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_MASK (0x100U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_SHIFT (8U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG - VDD_PMU_1V8 Vmin Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_MASK (0x200U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_SHIFT (9U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG - VDD_PMU_1V8 Vmax Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_MASK (0x400U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_SHIFT (10U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG - VDD_PMU_3V Vmin Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_MASK (0x800U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_SHIFT (11U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG - VDD_PMU_3V Vmax Error Sensor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_MASK (0x2000U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_SHIFT (13U)
/*! PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG - VDD_1V8_OK Monitor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_MASK (0x20000U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_SHIFT (17U)
/*! PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG - VDD_PMU_3V_OK Monitor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_MASK (0x40000U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_SHIFT (18U)
/*! PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG - TEMP_SENSOR_HT_OK Monitor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_MASK (0x80000U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_SHIFT (19U)
/*! PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG - TEMP_SENSOR_LT_OK Monitor Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_MASK (0x100000U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_SHIFT (20U)
/*! PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG - BUCK_VDD_CORE Clock Lost Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_MASK (0x200000U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_SHIFT (21U)
/*! PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG - BUCK_VDD_CORE IRQ Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_FLAG_MASK)

#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_MASK (0x400000U)
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_SHIFT (22U)
/*! PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG - BUCK_VDD_CORE OCL Warning Interrupt Flag
 *  0b0..No action
 *  0b1..Generates interrupt flag
 */
#define PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_SHIFT)) & PMU_PMU_DIG_IRQ_FLAG_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_FLAG_MASK)
/*! @} */

/*! @name PMU_DIG_IRQ_STATUS_STS - IRQ Status */
/*! @{ */

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_STS_MASK (0x1U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_STS_SHIFT (0U)
/*! PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_STS - VDD_1V8 Vmin Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_1V8 below Vmin threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_STS_MASK (0x2U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_STS_SHIFT (1U)
/*! PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_STS - VDD_1V8 Vmax Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_1V8 above Vmax threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_STS_MASK (0x4U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_STS_SHIFT (2U)
/*! PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_STS - VDD_CORE Vmin Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_CORE below Vmin threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_STS_MASK (0x8U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_STS_SHIFT (3U)
/*! PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_STS - VDD_CORE Vmax Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_CORE above Vmax threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_STS_MASK (0x10U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_STS_SHIFT (4U)
/*! PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_STS - VDD_0V8 Vmin Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_0V8 below Vmin threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_STS_MASK (0x20U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_STS_SHIFT (5U)
/*! PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_STS - VDD_0V8 Vmax Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_0V8 above Vmax threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_STS_MASK (0x40U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_STS_SHIFT (6U)
/*! PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_STS - VDDA_1V8 Vmin Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDDA_1V8 below Vmin threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_STS_MASK (0x80U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_STS_SHIFT (7U)
/*! PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_STS - VDDA_1V8 Vmax Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDDA_1V8 above Vmax threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_STS_MASK (0x100U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_STS_SHIFT (8U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_STS - VDD_PMU_1V8 Vmin Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_PMU_1V8 below Vmin threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_STS_MASK (0x200U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_STS_SHIFT (9U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_STS - VDD_PMU_1V8 Vmax Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_PMU_1V8 above Vmax threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_STS_MASK (0x400U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_STS_SHIFT (10U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_STS - VDD_PMU_3V Vmin Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_PMU_3V below Vmin threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_STS_MASK (0x800U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_STS_SHIFT (11U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_STS - VDD_PMU_3V Vmax Error Sensor Status Flag
 *  0b0..No error
 *  0b1..VDD_PMU_3V above Vmax threshold
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_STS_MASK (0x2000U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_STS_SHIFT (13U)
/*! PMU_DIG_MONITOR_VDD1V8_OK_IRQ_STS - VDD_1V8_OK Monitor Status Flag
 *  0b0..VDD_1V8 is not OK
 *  0b1..VDD_1V8 is OK
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_STS_MASK (0x20000U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_STS_SHIFT (17U)
/*! PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_STS - VDD_PMU_3V_OK Monitor Status Flag
 *  0b0..VDD_PMU_3V is not OK
 *  0b1..VDD_PMU_3V is OK
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_STS_MASK (0x40000U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_STS_SHIFT (18U)
/*! PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_STS - TEMP_SENSOR_HT_OK Monitor Status Flag
 *  0b0..TEMP_SENSOR high temperature is not OK
 *  0b1..TEMP_SENSOR high temperature is OK
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_STS_MASK (0x80000U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_STS_SHIFT (19U)
/*! PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_STS - TEMP_SENSOR_LT_OK Monitor Status Flag
 *  0b0..TEMP_SENSOR low temperature is not OK
 *  0b1..TEMP_SENSOR low temperature is OK
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_STS_MASK (0x100000U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_STS_SHIFT (20U)
/*! PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_STS - BUCK_VDD_CORE Clock Lost Status Flag
 *  0b0..Clock is present
 *  0b1..Clock is lost
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_STS_MASK (0x200000U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_STS_SHIFT (21U)
/*! PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_STS - BUCK_VDD_CORE IRQ Status Flag
 *  0b0..No interrupt
 *  0b1..Interrupt is raised
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_STS_MASK)

#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_STS_MASK (0x400000U)
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_STS_SHIFT (22U)
/*! PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_STS - BUCK_VDD_CORE OCL Warning IRQ Status Flag
 *  0b0..No interrupt
 *  0b1..Interrupt is raised
 */
#define PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_STS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_STS_SHIFT)) & PMU_PMU_DIG_IRQ_STATUS_STS_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_STS_MASK)
/*! @} */

/*! @name PMU_DIG_IRQ_EN_REG - IRQ Enable */
/*! @{ */

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_EN_MASK (0x1U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_EN_SHIFT (0U)
/*! PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_EN - VDD_1V8 Vmin Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMIN_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_EN_MASK (0x2U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_EN_SHIFT (1U)
/*! PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_EN - VDD_1V8 Vmax Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD1V8_VMAX_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_EN_MASK (0x4U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_EN_SHIFT (2U)
/*! PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_EN - VDD_CORE Vmin Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMIN_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_EN_MASK (0x8U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_EN_SHIFT (3U)
/*! PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_EN - VDD_CORE Vmax Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDCORE_VMAX_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_EN_MASK (0x10U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_EN_SHIFT (4U)
/*! PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_EN - VDD_0V8 Vmin Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMIN_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_EN_MASK (0x20U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_EN_SHIFT (5U)
/*! PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_EN - VDD_0V8 Vmax Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD0V8_VMAX_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_EN_MASK (0x40U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_EN_SHIFT (6U)
/*! PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_EN - VDDA_1V8 Vmin Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMIN_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_EN_MASK (0x80U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_EN_SHIFT (7U)
/*! PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_EN - VDDA_1V8 Vmax Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDDA1V8_VMAX_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_EN_MASK (0x100U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_EN_SHIFT (8U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_EN - VDD_PMU_1V8 Vmin Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMIN_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_EN_MASK (0x200U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_EN_SHIFT (9U)
/*! PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_EN - VDD_1V8 Vmax Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU1V8_VMAX_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_EN_MASK (0x400U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_EN_SHIFT (10U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_EN - VDD_PMU_3V Vmin Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMIN_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_EN_MASK (0x800U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_EN_SHIFT (11U)
/*! PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_EN - VDD_PMU_3V Vmax Error Sensor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_SENSE_VDD_PMU3V_VMAX_ERROR_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_EN_MASK (0x2000U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_EN_SHIFT (13U)
/*! PMU_DIG_MONITOR_VDD1V8_OK_IRQ_EN - VDD_1V8_OK Monitor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDD1V8_OK_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_EN_MASK (0x20000U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_EN_SHIFT (17U)
/*! PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_EN - VDD_PMU_3V_OK Monitor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_MONITOR_VDDPMU_3V_OK_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_EN_MASK (0x40000U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_EN_SHIFT (18U)
/*! PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_EN - TEMP_SENSOR_HT_OK Monitor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_HT_OK_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_EN_MASK (0x80000U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_EN_SHIFT (19U)
/*! PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_EN - TEMP_SENSOR_LT_OK Monitor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_TEMP_SENSOR_LT_OK_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_EN_MASK (0x100000U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_EN_SHIFT (20U)
/*! PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_EN - BUCK_VDD_CORE Clock Lost Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_CLK_LOST_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_EN_MASK (0x200000U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_EN_SHIFT (21U)
/*! PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_EN - BUCK_VDD_CORE IRQ Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_IRQ_IRQ_EN_MASK)

#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_EN_MASK (0x400000U)
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_EN_SHIFT (22U)
/*! PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_EN - BUCK_VDD_CORE OCL Warning Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_EN_SHIFT)) & PMU_PMU_DIG_IRQ_EN_REG_PMU_DIG_BUCK_VDDCORE_OCL_WARN_IRQ_EN_MASK)
/*! @} */

/*! @name PMU_XOSC32KNP_CTRL_REG - XOSC32KNP Control */
/*! @{ */

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKOUT_EN_MASK (0x1U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKOUT_EN_SHIFT (0U)
/*! XOSC32KNP_CLKOUT_EN - Clock Output Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKOUT_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKOUT_EN_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKOUT_EN_MASK)

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_MODE_MASK (0x2U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_MODE_SHIFT (1U)
/*! XOSC32KNP_MODE - Mode
 *  0b0..Self-charge (SCXO) mode / nano-power mode
 *  0b1..Transconductance (TCXO) mode / high-power mode
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_MODE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_MODE_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_MODE_MASK)

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_BYPASS_EN_MASK (0x4U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_BYPASS_EN_SHIFT (2U)
/*! XOSC32KNP_BYPASS_EN - Bypass Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_BYPASS_EN_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_BYPASS_EN_MASK)

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKMON_EN_MASK (0x8U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKMON_EN_SHIFT (3U)
/*! XOSC32KNP_CLKMON_EN - Clock Monitoring Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKMON_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKMON_EN_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_CLKMON_EN_MASK)

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL0_MASK (0x10U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL0_SHIFT (4U)
/*! XOSC32KNP_GM_SEL0 - GM Select 0
 *  0b0..If GM_SEL1 = 0: Standard bias current for GM cell (Imax_psource = 3.7 uA); If GM_SEL1 = 1: High bias
 *       current for GM cell, level 0 (Imax_psource = 5.3 uA)
 *  0b1..If GM_SEL1 = 0: Low bias current for GM cell (Imax_psource = 2.7 uA); If GM_SEL1 = 1: High bias current
 *       for GM cell, level 1 (Imax_psource = 7.4 uA)
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL0(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL0_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL0_MASK)

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL1_MASK (0x20U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL1_SHIFT (5U)
/*! XOSC32KNP_GM_SEL1 - GM Select 1
 *  0b0..If GM_SEL0 = 0: Standard bias current for GM cell (Imax_psource = 3.7 uA); If GM_SEL0 = 1: Low bias
 *       current for GM cell (Imax_psource = 2.7 uA)
 *  0b1..If GM_SEL0 = 0: High bias current for GM cell, level 0 (Imax_psource = 5.3 uA); If GM_SEL0 = 1: High bias
 *       current for GM cell, level 1 (Imax_psource = 7.4 uA)
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL1(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL1_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_GM_SEL1_MASK)

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL0_MASK (0x100U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL0_SHIFT (8U)
/*! XOSC32KNP_DLL0 - DLL Output Select 0
 *  0b0..If DLL1 = 0: DLL output after 18 delay cells; If DLL1 = 1: DLL output after 14 delay cells
 *  0b1..If DLL1 = 0: DLL output after 16 delay cells; If DLL1 = 1: DLL output after 18 delay cells
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL0(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL0_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL0_MASK)

#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL1_MASK (0x200U)
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL1_SHIFT (9U)
/*! XOSC32KNP_DLL1 - DLL Output Select 1
 *  0b0..If DLL0 = 0: DLL output after 18 delay cells; If DLL0 = 1: DLL output after 16 delay cells
 *  0b1..If DLL0 = 0: DLL output after 14 delay cells; If DLL0 = 1: DLL output after 18 delay cells
 */
#define PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL1(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL1_SHIFT)) & PMU_PMU_XOSC32KNP_CTRL_REG_XOSC32KNP_DLL1_MASK)
/*! @} */

/*! @name PMU_XOSC32KNP_STS - XOSC32KNP Status */
/*! @{ */

#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_SCXO_STABLE_MASK (0x1U)
#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_SCXO_STABLE_SHIFT (0U)
/*! XOSC32KNP_SCXO_STABLE - SCXO Stable
 *  0b0..Not acknowledged
 *  0b1..Stable acknowledged
 */
#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_SCXO_STABLE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_STS_XOSC32KNP_SCXO_STABLE_SHIFT)) & PMU_PMU_XOSC32KNP_STS_XOSC32KNP_SCXO_STABLE_MASK)

#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_TCXO_STABLE_MASK (0x2U)
#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_TCXO_STABLE_SHIFT (1U)
/*! XOSC32KNP_TCXO_STABLE - TCXO Stable
 *  0b0..Not acknowledged
 *  0b1..Stable acknowledged
 */
#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_TCXO_STABLE(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_STS_XOSC32KNP_TCXO_STABLE_SHIFT)) & PMU_PMU_XOSC32KNP_STS_XOSC32KNP_TCXO_STABLE_MASK)

#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_CLK_TAMPER_DETECTED_MASK (0x4U)
#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_CLK_TAMPER_DETECTED_SHIFT (2U)
/*! XOSC32KNP_CLK_TAMPER_DETECTED - Clock Tamper Detected
 *  0b0..Not detected
 *  0b1..Detected
 */
#define PMU_PMU_XOSC32KNP_STS_XOSC32KNP_CLK_TAMPER_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_XOSC32KNP_STS_XOSC32KNP_CLK_TAMPER_DETECTED_SHIFT)) & PMU_PMU_XOSC32KNP_STS_XOSC32KNP_CLK_TAMPER_DETECTED_MASK)
/*! @} */

/*! @name PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG - BUCK_VDD_CORE Analog Control */
/*! @{ */

#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_ADJ_MASK (0x1FU)
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_ADJ_SHIFT (0U)
/*! BUCK_VDDCORE_VOUT_ADJ - Output Voltage Adjustment */
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_FINE_ADJ_MASK (0x60U)
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_FINE_ADJ_SHIFT (5U)
/*! BUCK_VDDCORE_VOUT_FINE_ADJ - Output Voltage Fine Adjustment */
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_FINE_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_FINE_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VOUT_FINE_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_IPK_ADJ_MASK (0x180U)
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_IPK_ADJ_SHIFT (7U)
/*! BUCK_VDDCORE_IPK_ADJ - IPK Adjustment
 *  0b00..PFM: OCL = 0.95 A
 *  0b01..STARTUP: OCL = 0.25 A
 *  0b10..PWM: OCL=2.8 A
 *  0b11..DPD: OCL=0.4 A
 */
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_IPK_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_IPK_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_IPK_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_VTH_ADJ_MASK (0x380000U)
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_VTH_ADJ_SHIFT (19U)
/*! BUCK_VDDCORE_OVL_VTH_ADJ - OVL_VTH Adjustment
 *  0b000..OVL = 0.95 V
 *  0b001..OVL = 0.85 V
 *  0b010..OVL = 0.875 V
 *  0b011..OVL = 0.9 V
 *  0b100..OVL = 0.925 V
 *  0b101..OVL = 0.95 V
 *  0b110..OVL = 0.975 V
 *  0b111..OVL = 1 V
 */
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_VTH_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_VTH_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_VTH_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VSENSOR_VOUT_ADJ_EN_MASK (0x2000000U)
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VSENSOR_VOUT_ADJ_EN_SHIFT (25U)
/*! BUCK_VDDCORE_VSENSOR_VOUT_ADJ_EN - Voltage Sensor Output Voltage Adjustment Enable
 *  0b0..Both NMOS and PMOS comparators are enabled
 *  0b1..Comparators enabling depends on Vout (BUCK_VDDCORE_VOUT_ADJ)
 */
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VSENSOR_VOUT_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VSENSOR_VOUT_ADJ_EN_SHIFT)) & PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_VSENSOR_VOUT_ADJ_EN_MASK)

#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_BYPASS_EN_MASK (0x4000000U)
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_BYPASS_EN_SHIFT (26U)
/*! BUCK_VDDCORE_BYPASS_EN - Bypass Enable
 *  0b0..No external supply source, bypass off
 *  0b1..External supply source, bypass on
 */
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_BYPASS_EN_SHIFT)) & PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_BYPASS_EN_MASK)

#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_PD_EN_MASK (0x8000000U)
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_PD_EN_SHIFT (27U)
/*! BUCK_VDDCORE_OVL_PD_EN - OVL Pulldown Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_PD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_PD_EN_SHIFT)) & PMU_PMU_BUCK_VDDCORE_ANACTRL_SETTING_REG_BUCK_VDDCORE_OVL_PD_EN_MASK)
/*! @} */

/*! @name PMU_BUCK_VDDCORE_CTRL_PWM_REG - BUCK_VDD_CORE PWM Control */
/*! @{ */

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_RES_ADJ_MASK (0x7U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_RES_ADJ_SHIFT (0U)
/*! BUCK_VDDCORE_LOOPFILTER_RES_ADJ - Loop Filter Resistance Adjustment
 *  0b000..160 kΩ
 *  0b001..80 kΩ
 *  0b010..120 kΩ
 *  0b011..200 kΩ
 *  0b100..240 kΩ
 *  0b101..280 kΩ
 *  0b110..320 kΩ
 *  0b111..360 kΩ
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_RES_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_RES_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_RES_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_CAP_ADJ_MASK (0x38U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_CAP_ADJ_SHIFT (3U)
/*! BUCK_VDDCORE_LOOPFILTER_CAP_ADJ - Loop Filter Capacitance Adjustment
 *  0b000..38 pF
 *  0b001..34 pF
 *  0b010..26 pF
 *  0b011..30 pF
 *  0b100..22 pF
 *  0b101..18 pF
 *  0b110..10 pF
 *  0b111..14 pF
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_CAP_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_CAP_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_LOOPFILTER_CAP_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SAWTOOTH_ADJ_MASK (0x1C0U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SAWTOOTH_ADJ_SHIFT (6U)
/*! BUCK_VDDCORE_SAWTOOTH_ADJ - Saw-Tooth Adjustment
 *  0b000..0.79 Mv/s
 *  0b001..0.92 Mv/s
 *  0b010..0.2 Mv/s
 *  0b011..0.33 Mv/s
 *  0b100..0.46 Mv/s
 *  0b101..0.59 Mv/s
 *  0b110..1.05 Mv/s
 *  0b111..1.18 Mv/s
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SAWTOOTH_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SAWTOOTH_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SAWTOOTH_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_ADJ_MASK (0xE00U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_ADJ_SHIFT (9U)
/*! BUCK_VDDCORE_GM_ADJ - Gm Adjustment
 *  0b000..50 uA/V
 *  0b001..15 uA/V
 *  0b010..20 uA/V
 *  0b011..30 uA/V
 *  0b100..40 uA/V
 *  0b101..60 uA/V
 *  0b110..70 uA/V
 *  0b111..80 uA/V
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_ADJ(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_ADJ_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_ADJ_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_OVL_PULLUP_DIS_MASK (0x1000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_OVL_PULLUP_DIS_SHIFT (12U)
/*! BUCK_VDDCORE_GM_OVL_PULLUP_DIS - Gm OVL Pullup Disable
 *  0b0..Current sensor measurement through LXSENSE
 *  0b1..Current sensor measurement through DRIVERP
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_OVL_PULLUP_DIS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_OVL_PULLUP_DIS_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_OVL_PULLUP_DIS_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_INI_COND_MASK (0x2000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_INI_COND_SHIFT (13U)
/*! BUCK_VDDCORE_GM_INI_COND - Gm Initial Condition
 *  0b0..VDD
 *  0b1..VDD/2
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_INI_COND(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_INI_COND_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_GM_INI_COND_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_IPK_OVR_MASK (0x4000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_IPK_OVR_SHIFT (14U)
/*! BUCK_VDDCORE_IPK_OVR - IPK Override
 *  0b0..OCL is OCL_PWM = 2.8 A
 *  0b1..OCL is OCL_PFM = 0.95 A
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_IPK_OVR(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_IPK_OVR_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_IPK_OVR_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_PULSESKIP_MASK (0x18000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_PULSESKIP_SHIFT (15U)
/*! BUCK_VDDCORE_PULSESKIP - Pulse Skip
 *  0b00..30 ns
 *  0b01..20 ns
 *  0b10..40 ns
 *  0b11..50 ns
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_PULSESKIP(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_PULSESKIP_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_PULSESKIP_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_PEAKP_MASK (0x60000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_PEAKP_SHIFT (17U)
/*! BUCK_VDDCORE_MASK_PEAKP - Mask Peak Pulse
 *  0b00..20 ns
 *  0b01..25 ns
 *  0b10..30 ns
 *  0b11..40 ns
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_PEAKP(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_PEAKP_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_PEAKP_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_SAWTOOTH_MASK (0x180000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_SAWTOOTH_SHIFT (19U)
/*! BUCK_VDDCORE_MASK_SAWTOOTH - Mask Saw-Tooth Pulse
 *  0b00..10 ns
 *  0b01..15 ns
 *  0b10..20 ns
 *  0b11..30 ns
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_SAWTOOTH(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_SAWTOOTH_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_SAWTOOTH_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SET_PWM_MASK (0x600000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SET_PWM_SHIFT (21U)
/*! BUCK_VDDCORE_SET_PWM - Set PWM Pulse
 *  0b00..20 ns
 *  0b01..15 ns
 *  0b10..30 ns
 *  0b11..40 ns
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SET_PWM(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SET_PWM_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_SET_PWM_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_OCL_MASK (0x1800000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_OCL_SHIFT (23U)
/*! BUCK_VDDCORE_MASK_OCL - Mask OCL Pulse
 *  0b00..30 ns
 *  0b01..20 ns
 *  0b10..50 ns
 *  0b11..70 ns
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_OCL(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_OCL_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_OCL_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_ZCS_MASK (0x6000000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_ZCS_SHIFT (25U)
/*! BUCK_VDDCORE_MASK_ZCS - Mask ZCS Pulse
 *  0b00..30 ns
 *  0b01..20 ns
 *  0b10..40 ns
 *  0b11..60 ns
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_ZCS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_ZCS_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_MASK_ZCS_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_DIS_PULSESKIPING_MASK (0x8000000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_DIS_PULSESKIPING_SHIFT (27U)
/*! BUCK_VDDCORE_DIS_PULSESKIPING - Pulse Skip Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_DIS_PULSESKIPING(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_DIS_PULSESKIPING_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_DIS_PULSESKIPING_MASK)

#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_VOUT_STEPS_MASK (0x10000000U)
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_VOUT_STEPS_SHIFT (28U)
/*! BUCK_VDDCORE_VOUT_STEPS - Output Voltage Steps
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_VOUT_STEPS(x) (((uint32_t)(((uint32_t)(x)) << PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_VOUT_STEPS_SHIFT)) & PMU_PMU_BUCK_VDDCORE_CTRL_PWM_REG_BUCK_VDDCORE_VOUT_STEPS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMU_Register_Masks */


/*!
 * @}
 */ /* end of group PMU_Peripheral_Access_Layer */


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


#endif  /* PERI_PMU_H_ */

