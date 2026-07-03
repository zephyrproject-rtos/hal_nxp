/*
** ###################################################################
**     Processors:          MCXL142VDH_cm0plus
**                          MCXL142VDH_cm33
**                          MCXL142VLL_cm0plus
**                          MCXL142VLL_cm33
**                          MCXL143VDH_cm0plus
**                          MCXL143VDH_cm33
**                          MCXL143VLL_cm0plus
**                          MCXL143VLL_cm33
**                          MCXL144VDH_cm0plus
**                          MCXL144VDH_cm33
**                          MCXL144VLL_cm0plus
**                          MCXL144VLL_cm33
**
**     Version:             rev. 2.1, 2026-05-02
**     Build:               b260512
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
**     - rev. 1.0 (2025-06-13)
**         Generated based on Rev1 DraftH.
**     - rev. 1.1 (2026-01-02)
**         Generated based on Rev.1 RC.
**     - rev. 2.0 (2026-04-22)
**         Generated based on Rev. 2 DraftA.
**     - rev. 2.1 (2026-05-02)
**         Generated based on Rev. 2.
**
** ###################################################################
*/

/*!
 * @file PERI_PMU.h
 * @version 2.1
 * @date 2026-05-02
 * @brief CMSIS Peripheral Access Layer for PMU
 *
 * CMSIS Peripheral Access Layer for PMU
 */

#if !defined(PERI_PMU_H_)
#define PERI_PMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL142VDH_cm0plus) || defined(CPU_MCXL142VLL_cm0plus))
#include "MCXL142_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL142VDH_cm33) || defined(CPU_MCXL142VLL_cm33))
#include "MCXL142_cm33_COMMON.h"
#elif (defined(CPU_MCXL143VDH_cm0plus) || defined(CPU_MCXL143VLL_cm0plus))
#include "MCXL143_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL143VDH_cm33) || defined(CPU_MCXL143VLL_cm33))
#include "MCXL143_cm33_COMMON.h"
#elif (defined(CPU_MCXL144VDH_cm0plus) || defined(CPU_MCXL144VLL_cm0plus))
#include "MCXL144_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL144VDH_cm33) || defined(CPU_MCXL144VLL_cm33))
#include "MCXL144_cm33_COMMON.h"
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
  __IO uint32_t PCTRL;                             /**< Power Control, offset: 0x0 */
  __IO uint32_t VDD_CORE_AON_CONFIG;               /**< VDD_CORE_AON Power Configuration, offset: 0x4 */
  __IO uint32_t VDD_CORE_MAIN_CONFIG;              /**< VDD_CORE_MAIN Configuration, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t FRO_CTRL;                          /**< FRO16K Control, offset: 0x10 */
  __IO uint32_t BGR_LVHV_DETECT_CTRL;              /**< BGR Low/High Voltage Detect Control, offset: 0x14 */
       uint8_t RESERVED_1[56];
  __IO uint32_t PMU_TRIM4;                         /**< PMU Trim4, offset: 0x50 */
  __IO uint32_t PMU_DPD3_CTRL;                     /**< Deep Power Down 3 Mode Control, offset: 0x54 */
       uint8_t RESERVED_2[8];
  __IO uint32_t AWK_UP_TIME;                       /**< Analog Wakeup Time, offset: 0x60 */
  __IO uint32_t AGDET_HV_CTRL;                     /**< High Voltage Glitch Detect Control, offset: 0x64 */
  __IO uint32_t AGDET_LV_CTRL;                     /**< Low Voltage Glitch Detect Control, offset: 0x68 */
       uint8_t RESERVED_3[4];
  __IO uint32_t VDD_LVD_HVD_CTRL;                  /**< VDD LVD_HVD_CTRL, offset: 0x70 */
} PMU_Type;

/* ----------------------------------------------------------------------------
   -- PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Register_Masks PMU Register Masks
 * @{
 */

/*! @name PCTRL - Power Control */
/*! @{ */

#define PMU_PCTRL_VDD_CORE_AON_EN_MASK           (0x1U)
#define PMU_PCTRL_VDD_CORE_AON_EN_SHIFT          (0U)
/*! VDD_CORE_AON_EN - VDD_CORE_AON Power Enable
 *  0b0..Disables DCDC_AON
 *  0b1..Enables DCDC_AON during Active mode
 */
#define PMU_PCTRL_VDD_CORE_AON_EN(x)             (((uint32_t)(((uint32_t)(x)) << PMU_PCTRL_VDD_CORE_AON_EN_SHIFT)) & PMU_PCTRL_VDD_CORE_AON_EN_MASK)

#define PMU_PCTRL_VDD_CORE_MAIN_EN_MASK          (0x2U)
#define PMU_PCTRL_VDD_CORE_MAIN_EN_SHIFT         (1U)
/*! VDD_CORE_MAIN_EN - VDD_CORE_MAIN Power Enable
 *  0b0..Disables DCDC_MAIN
 *  0b1..Enables DCDC_MAIN during Active mode
 */
#define PMU_PCTRL_VDD_CORE_MAIN_EN(x)            (((uint32_t)(((uint32_t)(x)) << PMU_PCTRL_VDD_CORE_MAIN_EN_SHIFT)) & PMU_PCTRL_VDD_CORE_MAIN_EN_MASK)

#define PMU_PCTRL_VDD_MAIN_LPWR_MASK             (0x4000U)
#define PMU_PCTRL_VDD_MAIN_LPWR_SHIFT            (14U)
/*! VDD_MAIN_LPWR - DCDC_MAIN Low-Power Mode Enable
 *  0b0..DCDC_MAIN operates in normal power mode.
 *  0b1..DCDC_MAIN operates in low power mode.
 */
#define PMU_PCTRL_VDD_MAIN_LPWR(x)               (((uint32_t)(((uint32_t)(x)) << PMU_PCTRL_VDD_MAIN_LPWR_SHIFT)) & PMU_PCTRL_VDD_MAIN_LPWR_MASK)
/*! @} */

/*! @name VDD_CORE_AON_CONFIG - VDD_CORE_AON Power Configuration */
/*! @{ */

#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_MASK (0x3FU)
#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_SHIFT (0U)
/*! VDD_CORE_AON_ACONFIG - VDD_CORE_AON Active Configuration
 *  0b010100..0.8V
 *  0b101100..0.6V
 */
#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG(x) (((uint32_t)(((uint32_t)(x)) << PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_SHIFT)) & PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_MASK)

#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG_MASK (0xFC0U)
#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG_SHIFT (6U)
/*! VDD_CORE_AON_DCONFIG - VDD_CORE_AON DPD2 Configuration
 *  0b010100..0.8V
 *  0b101100..0.6V
 */
#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG(x) (((uint32_t)(((uint32_t)(x)) << PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG_SHIFT)) & PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG_MASK)
/*! @} */

/*! @name VDD_CORE_MAIN_CONFIG - VDD_CORE_MAIN Configuration */
/*! @{ */

#define PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_ACONFIG_MASK (0xFFU)
#define PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_ACONFIG_SHIFT (0U)
/*! VDD_CORE_MAIN_ACONFIG - VDD_CORE_MAIN Active Configuration */
#define PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_ACONFIG(x) (((uint32_t)(((uint32_t)(x)) << PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_ACONFIG_SHIFT)) & PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_ACONFIG_MASK)

#define PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_VOUTSEL_LPWR_MASK (0x1F00U)
#define PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_VOUTSEL_LPWR_SHIFT (8U)
/*! VDD_CORE_MAIN_VOUTSEL_LPWR - VDD_CORE_MAIN Vout Select Low Power */
#define PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_VOUTSEL_LPWR(x) (((uint32_t)(((uint32_t)(x)) << PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_VOUTSEL_LPWR_SHIFT)) & PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_VOUTSEL_LPWR_MASK)
/*! @} */

/*! @name FRO_CTRL - FRO16K Control */
/*! @{ */

#define PMU_FRO_CTRL_CLOCK_SEL_MASK              (0x2000U)
#define PMU_FRO_CTRL_CLOCK_SEL_SHIFT             (13U)
/*! CLOCK_SEL - Clock Select
 *  0b0..Use 16 kHz
 *  0b1..Use 8 kHz
 */
#define PMU_FRO_CTRL_CLOCK_SEL(x)                (((uint32_t)(((uint32_t)(x)) << PMU_FRO_CTRL_CLOCK_SEL_SHIFT)) & PMU_FRO_CTRL_CLOCK_SEL_MASK)
/*! @} */

/*! @name BGR_LVHV_DETECT_CTRL - BGR Low/High Voltage Detect Control */
/*! @{ */

#define PMU_BGR_LVHV_DETECT_CTRL_DET_RST_EN_MASK (0x2U)
#define PMU_BGR_LVHV_DETECT_CTRL_DET_RST_EN_SHIFT (1U)
/*! DET_RST_EN - Security Detect Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_BGR_LVHV_DETECT_CTRL_DET_RST_EN(x)   (((uint32_t)(((uint32_t)(x)) << PMU_BGR_LVHV_DETECT_CTRL_DET_RST_EN_SHIFT)) & PMU_BGR_LVHV_DETECT_CTRL_DET_RST_EN_MASK)

#define PMU_BGR_LVHV_DETECT_CTRL_BG_EN_MASK      (0x4U)
#define PMU_BGR_LVHV_DETECT_CTRL_BG_EN_SHIFT     (2U)
/*! BG_EN - Band gap Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_BGR_LVHV_DETECT_CTRL_BG_EN(x)        (((uint32_t)(((uint32_t)(x)) << PMU_BGR_LVHV_DETECT_CTRL_BG_EN_SHIFT)) & PMU_BGR_LVHV_DETECT_CTRL_BG_EN_MASK)

#define PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_EN_MASK (0x100U)
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_EN_SHIFT (8U)
/*! VDD_BAT_LVD_EN - LVD Supply Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_EN_SHIFT)) & PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_EN_MASK)

#define PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_LEVEL_MASK (0x200U)
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_LEVEL_SHIFT (9U)
/*! VDD_BAT_LVD_LEVEL - LVD Supply Level
 *  0b0..Low range
 *  0b1..High range
 */
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_LEVEL_SHIFT)) & PMU_BGR_LVHV_DETECT_CTRL_VDD_BAT_LVD_LEVEL_MASK)

#define PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_LVD_EN_MASK (0x400U)
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_LVD_EN_SHIFT (10U)
/*! VDD_CORE_MAIN_LVD_EN - LVD Supply Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_LVD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_LVD_EN_SHIFT)) & PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_LVD_EN_MASK)

#define PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_HVD_EN_MASK (0x800U)
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_HVD_EN_SHIFT (11U)
/*! VDD_CORE_MAIN_HVD_EN - HVD High Supply Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_HVD_EN(x) (((uint32_t)(((uint32_t)(x)) << PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_HVD_EN_SHIFT)) & PMU_BGR_LVHV_DETECT_CTRL_VDD_CORE_MAIN_HVD_EN_MASK)

#define PMU_BGR_LVHV_DETECT_CTRL_VDD_HVD_EN_MASK (0x4000U)
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_HVD_EN_SHIFT (14U)
/*! VDD_HVD_EN - HVD Supply Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_BGR_LVHV_DETECT_CTRL_VDD_HVD_EN(x)   (((uint32_t)(((uint32_t)(x)) << PMU_BGR_LVHV_DETECT_CTRL_VDD_HVD_EN_SHIFT)) & PMU_BGR_LVHV_DETECT_CTRL_VDD_HVD_EN_MASK)
/*! @} */

/*! @name PMU_TRIM4 - PMU Trim4 */
/*! @{ */

#define PMU_PMU_TRIM4_LVD_LV_TRIM_MASK           (0xFU)
#define PMU_PMU_TRIM4_LVD_LV_TRIM_SHIFT          (0U)
/*! LVD_LV_TRIM - LVD LV Trim */
#define PMU_PMU_TRIM4_LVD_LV_TRIM(x)             (((uint32_t)(((uint32_t)(x)) << PMU_PMU_TRIM4_LVD_LV_TRIM_SHIFT)) & PMU_PMU_TRIM4_LVD_LV_TRIM_MASK)

#define PMU_PMU_TRIM4_HVD_LV_TRIM_MASK           (0xF00U)
#define PMU_PMU_TRIM4_HVD_LV_TRIM_SHIFT          (8U)
/*! HVD_LV_TRIM - VBAT Low Voltage Detect Trim */
#define PMU_PMU_TRIM4_HVD_LV_TRIM(x)             (((uint32_t)(((uint32_t)(x)) << PMU_PMU_TRIM4_HVD_LV_TRIM_SHIFT)) & PMU_PMU_TRIM4_HVD_LV_TRIM_MASK)

#define PMU_PMU_TRIM4_HVD_HV_TRIM_MASK           (0xF000U)
#define PMU_PMU_TRIM4_HVD_HV_TRIM_SHIFT          (12U)
/*! HVD_HV_TRIM - VBAT High Voltage Detect Trim */
#define PMU_PMU_TRIM4_HVD_HV_TRIM(x)             (((uint32_t)(((uint32_t)(x)) << PMU_PMU_TRIM4_HVD_HV_TRIM_SHIFT)) & PMU_PMU_TRIM4_HVD_HV_TRIM_MASK)
/*! @} */

/*! @name PMU_DPD3_CTRL - Deep Power Down 3 Mode Control */
/*! @{ */

#define PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_MASK      (0x100U)
#define PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_SHIFT     (8U)
/*! FRO16KHZ_ACT - FRO16K Active
 *  0b0..FRO16K is disabled in DPD3 and Shutdown modes
 *  0b1..FRO16K is enabled in DPD3 and Shutdown modes
 */
#define PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT(x)        (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_SHIFT)) & PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_MASK)
/*! @} */

/*! @name AWK_UP_TIME - Analog Wakeup Time */
/*! @{ */

#define PMU_AWK_UP_TIME_WKUP_TIME_MASK           (0xFFFU)
#define PMU_AWK_UP_TIME_WKUP_TIME_SHIFT          (0U)
/*! WKUP_TIME - Wakeup Time */
#define PMU_AWK_UP_TIME_WKUP_TIME(x)             (((uint32_t)(((uint32_t)(x)) << PMU_AWK_UP_TIME_WKUP_TIME_SHIFT)) & PMU_AWK_UP_TIME_WKUP_TIME_MASK)
/*! @} */

/*! @name AGDET_HV_CTRL - High Voltage Glitch Detect Control */
/*! @{ */

#define PMU_AGDET_HV_CTRL_AGDET_HV_EN_MASK       (0x2U)
#define PMU_AGDET_HV_CTRL_AGDET_HV_EN_SHIFT      (1U)
/*! AGDET_HV_EN - High Voltage Glitch Detect Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_AGDET_HV_CTRL_AGDET_HV_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_HV_CTRL_AGDET_HV_EN_SHIFT)) & PMU_AGDET_HV_CTRL_AGDET_HV_EN_MASK)

#define PMU_AGDET_HV_CTRL_AGDET_HV_RES_MASK      (0x4U)
#define PMU_AGDET_HV_CTRL_AGDET_HV_RES_SHIFT     (2U)
/*! AGDET_HV_RES - High Voltage Glitch Detect Reset
 *  0b0..Reset disable
 *  0b1..Reset enable
 */
#define PMU_AGDET_HV_CTRL_AGDET_HV_RES(x)        (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_HV_CTRL_AGDET_HV_RES_SHIFT)) & PMU_AGDET_HV_CTRL_AGDET_HV_RES_MASK)

#define PMU_AGDET_HV_CTRL_AGDET_HV_SEC_RES_MASK  (0x600U)
#define PMU_AGDET_HV_CTRL_AGDET_HV_SEC_RES_SHIFT (9U)
/*! AGDET_HV_SEC_RES - High Voltage Glitch Detect Bit Security Reset
 *  0b00..1 glitch.
 *  0b01..3 glitches.
 *  0b10..7 glitches.
 *  0b11..15 glitches.
 */
#define PMU_AGDET_HV_CTRL_AGDET_HV_SEC_RES(x)    (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_HV_CTRL_AGDET_HV_SEC_RES_SHIFT)) & PMU_AGDET_HV_CTRL_AGDET_HV_SEC_RES_MASK)

#define PMU_AGDET_HV_CTRL_AGDET_LV_SEC_RES_MASK  (0x1800U)
#define PMU_AGDET_HV_CTRL_AGDET_LV_SEC_RES_SHIFT (11U)
/*! AGDET_LV_SEC_RES - Low Voltage Glitch Detect Bit Security Reset
 *  0b00..1 glitch.
 *  0b01..3 glitches.
 *  0b10..7 glitches.
 *  0b11..15 glitches.
 */
#define PMU_AGDET_HV_CTRL_AGDET_LV_SEC_RES(x)    (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_HV_CTRL_AGDET_LV_SEC_RES_SHIFT)) & PMU_AGDET_HV_CTRL_AGDET_LV_SEC_RES_MASK)
/*! @} */

/*! @name AGDET_LV_CTRL - Low Voltage Glitch Detect Control */
/*! @{ */

#define PMU_AGDET_LV_CTRL_AGDET_LV_EN_MASK       (0x2U)
#define PMU_AGDET_LV_CTRL_AGDET_LV_EN_SHIFT      (1U)
/*! AGDET_LV_EN - Low Voltage Glitch Detect Signal
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_AGDET_LV_CTRL_AGDET_LV_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_LV_CTRL_AGDET_LV_EN_SHIFT)) & PMU_AGDET_LV_CTRL_AGDET_LV_EN_MASK)

#define PMU_AGDET_LV_CTRL_AGDET_LV_RES_MASK      (0x4U)
#define PMU_AGDET_LV_CTRL_AGDET_LV_RES_SHIFT     (2U)
/*! AGDET_LV_RES - Low Voltage Glitch Detect Reset
 *  0b0..Reset disable
 *  0b1..Reset enable
 */
#define PMU_AGDET_LV_CTRL_AGDET_LV_RES(x)        (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_LV_CTRL_AGDET_LV_RES_SHIFT)) & PMU_AGDET_LV_CTRL_AGDET_LV_RES_MASK)
/*! @} */

/*! @name VDD_LVD_HVD_CTRL - VDD LVD_HVD_CTRL */
/*! @{ */

#define PMU_VDD_LVD_HVD_CTRL_VDD_LVD_EN_MASK     (0x1U)
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVD_EN_SHIFT    (0U)
/*! VDD_LVD_EN - VDD LVD Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVD_EN(x)       (((uint32_t)(((uint32_t)(x)) << PMU_VDD_LVD_HVD_CTRL_VDD_LVD_EN_SHIFT)) & PMU_VDD_LVD_HVD_CTRL_VDD_LVD_EN_MASK)

#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_MASK (0x2U)
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_SHIFT (1U)
/*! VDD_LVDH_LEVEL - LVD Level Select
 *  0b0..Low range
 *  0b1..High range
 */
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL(x)   (((uint32_t)(((uint32_t)(x)) << PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_SHIFT)) & PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_MASK)
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

