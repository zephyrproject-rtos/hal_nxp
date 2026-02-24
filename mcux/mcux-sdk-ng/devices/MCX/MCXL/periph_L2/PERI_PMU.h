/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.1, 2026-01-02
**     Build:               b260106
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
**
** ###################################################################
*/

/*!
 * @file PERI_PMU.h
 * @version 1.1
 * @date 2026-01-02
 * @brief CMSIS Peripheral Access Layer for PMU
 *
 * CMSIS Peripheral Access Layer for PMU
 */

#if !defined(PERI_PMU_H_)
#define PERI_PMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
  __IO uint32_t BGR_CTRL;                          /**< Band Gap Reference Control, offset: 0x14 */
       uint8_t RESERVED_1[56];
  __IO uint32_t PMU_TRIM4;                         /**< PMU Trim4, offset: 0x50 */
  __IO uint32_t PMU_DPD3_CTRL;                     /**< PMU DPD3 Control, offset: 0x54 */
       uint8_t RESERVED_2[4];
  __IO uint32_t VDD_CORE_AON_WKUP_WDTC;            /**< VDD Wakeup Watchdog Time Count, offset: 0x5C */
  __IO uint32_t AWK_UP_TIME;                       /**< Analog Wakeup Time, offset: 0x60 */
  __IO uint32_t AGDET_HV_CTRL;                     /**< High Voltage Glitch Detect Control, offset: 0x64 */
  __IO uint32_t AGDET_LV_CTRL;                     /**< Low Voltage Glitch Detect Control, offset: 0x68 */
  __I  uint32_t STATUS;                            /**< Status, offset: 0x6C */
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
/*! VDD_CORE_AON_EN - VDD Power Enable */
#define PMU_PCTRL_VDD_CORE_AON_EN(x)             (((uint32_t)(((uint32_t)(x)) << PMU_PCTRL_VDD_CORE_AON_EN_SHIFT)) & PMU_PCTRL_VDD_CORE_AON_EN_MASK)

#define PMU_PCTRL_VDD_CORE_MAIN_EN_MASK          (0x2U)
#define PMU_PCTRL_VDD_CORE_MAIN_EN_SHIFT         (1U)
/*! VDD_CORE_MAIN_EN - VDD_CORE_MAIN Power Enable */
#define PMU_PCTRL_VDD_CORE_MAIN_EN(x)            (((uint32_t)(((uint32_t)(x)) << PMU_PCTRL_VDD_CORE_MAIN_EN_SHIFT)) & PMU_PCTRL_VDD_CORE_MAIN_EN_MASK)

#define PMU_PCTRL_VDD_MAIN_LPWR_MASK             (0x4000U)
#define PMU_PCTRL_VDD_MAIN_LPWR_SHIFT            (14U)
/*! VDD_MAIN_LPWR - Signal to indicate the DCDC_MAIN to work in low power mode.
 *  0b0..DC to DC Main in normal power mode.
 *  0b1..DC to DC Main in low power mode.
 */
#define PMU_PCTRL_VDD_MAIN_LPWR(x)               (((uint32_t)(((uint32_t)(x)) << PMU_PCTRL_VDD_MAIN_LPWR_SHIFT)) & PMU_PCTRL_VDD_MAIN_LPWR_MASK)
/*! @} */

/*! @name VDD_CORE_AON_CONFIG - VDD_CORE_AON Power Configuration */
/*! @{ */

#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_MASK (0x3FU)
#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_SHIFT (0U)
/*! VDD_CORE_AON_ACONFIG - VDD_CORE_AON Active Configuration */
#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG(x) (((uint32_t)(((uint32_t)(x)) << PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_SHIFT)) & PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_MASK)

#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG_MASK (0xFC0U)
#define PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG_SHIFT (6U)
/*! VDD_CORE_AON_DCONFIG - VDD_CORE_AON DPD2 Configuration */
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

#define PMU_FRO_CTRL_FRO16K_EN_MASK              (0x1U)
#define PMU_FRO_CTRL_FRO16K_EN_SHIFT             (0U)
/*! FRO16K_EN - FRO16K Enable
 *  0b0..Enable
 *  0b1..Disable
 */
#define PMU_FRO_CTRL_FRO16K_EN(x)                (((uint32_t)(((uint32_t)(x)) << PMU_FRO_CTRL_FRO16K_EN_SHIFT)) & PMU_FRO_CTRL_FRO16K_EN_MASK)

#define PMU_FRO_CTRL_CLOCK_SEL_MASK              (0x2000U)
#define PMU_FRO_CTRL_CLOCK_SEL_SHIFT             (13U)
/*! CLOCK_SEL - Clock Select
 *  0b0..Use 16 KHz
 *  0b1..Use 8 KHz
 */
#define PMU_FRO_CTRL_CLOCK_SEL(x)                (((uint32_t)(((uint32_t)(x)) << PMU_FRO_CTRL_CLOCK_SEL_SHIFT)) & PMU_FRO_CTRL_CLOCK_SEL_MASK)
/*! @} */

/*! @name BGR_CTRL - Band Gap Reference Control */
/*! @{ */

#define PMU_BGR_CTRL_BG_EN_MASK                  (0x4U)
#define PMU_BGR_CTRL_BG_EN_SHIFT                 (2U)
/*! BG_EN - Band gap Enable */
#define PMU_BGR_CTRL_BG_EN(x)                    (((uint32_t)(((uint32_t)(x)) << PMU_BGR_CTRL_BG_EN_SHIFT)) & PMU_BGR_CTRL_BG_EN_MASK)

#define PMU_BGR_CTRL_VDD_BAT_LVDH_EN_MASK        (0x100U)
#define PMU_BGR_CTRL_VDD_BAT_LVDH_EN_SHIFT       (8U)
/*! VDD_BAT_LVDH_EN - LVD High Voltage Supply Enable */
#define PMU_BGR_CTRL_VDD_BAT_LVDH_EN(x)          (((uint32_t)(((uint32_t)(x)) << PMU_BGR_CTRL_VDD_BAT_LVDH_EN_SHIFT)) & PMU_BGR_CTRL_VDD_BAT_LVDH_EN_MASK)

#define PMU_BGR_CTRL_VDD_BAT_LVDH_LEVEL_MASK     (0x200U)
#define PMU_BGR_CTRL_VDD_BAT_LVDH_LEVEL_SHIFT    (9U)
/*! VDD_BAT_LVDH_LEVEL - LVD High Voltage Supply Level
 *  0b0..Default
 *  0b1..Safe Mode
 */
#define PMU_BGR_CTRL_VDD_BAT_LVDH_LEVEL(x)       (((uint32_t)(((uint32_t)(x)) << PMU_BGR_CTRL_VDD_BAT_LVDH_LEVEL_SHIFT)) & PMU_BGR_CTRL_VDD_BAT_LVDH_LEVEL_MASK)

#define PMU_BGR_CTRL_VDD_CORE_MAIN_LVD_EN_MASK   (0x400U)
#define PMU_BGR_CTRL_VDD_CORE_MAIN_LVD_EN_SHIFT  (10U)
/*! VDD_CORE_MAIN_LVD_EN - LVD Low Voltage Supply Enable */
#define PMU_BGR_CTRL_VDD_CORE_MAIN_LVD_EN(x)     (((uint32_t)(((uint32_t)(x)) << PMU_BGR_CTRL_VDD_CORE_MAIN_LVD_EN_SHIFT)) & PMU_BGR_CTRL_VDD_CORE_MAIN_LVD_EN_MASK)

#define PMU_BGR_CTRL_VDD_CORE_MAIN_HVDL_EN_MASK  (0x800U)
#define PMU_BGR_CTRL_VDD_CORE_MAIN_HVDL_EN_SHIFT (11U)
/*! VDD_CORE_MAIN_HVDL_EN - HVD Low Voltage Supply Enable */
#define PMU_BGR_CTRL_VDD_CORE_MAIN_HVDL_EN(x)    (((uint32_t)(((uint32_t)(x)) << PMU_BGR_CTRL_VDD_CORE_MAIN_HVDL_EN_SHIFT)) & PMU_BGR_CTRL_VDD_CORE_MAIN_HVDL_EN_MASK)

#define PMU_BGR_CTRL_VDD_CORE_MAIN_HVDH_EN_MASK  (0x4000U)
#define PMU_BGR_CTRL_VDD_CORE_MAIN_HVDH_EN_SHIFT (14U)
/*! VDD_CORE_MAIN_HVDH_EN - HVD High Voltage Supply Enable */
#define PMU_BGR_CTRL_VDD_CORE_MAIN_HVDH_EN(x)    (((uint32_t)(((uint32_t)(x)) << PMU_BGR_CTRL_VDD_CORE_MAIN_HVDH_EN_SHIFT)) & PMU_BGR_CTRL_VDD_CORE_MAIN_HVDH_EN_MASK)
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

/*! @name PMU_DPD3_CTRL - PMU DPD3 Control */
/*! @{ */

#define PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_MASK      (0x100U)
#define PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_SHIFT     (8U)
/*! FRO16KHZ_ACT - FRO16KHz Active */
#define PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT(x)        (((uint32_t)(((uint32_t)(x)) << PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_SHIFT)) & PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_MASK)
/*! @} */

/*! @name VDD_CORE_AON_WKUP_WDTC - VDD Wakeup Watchdog Time Count */
/*! @{ */

#define PMU_VDD_CORE_AON_WKUP_WDTC_DCDC_AON_WKUP_WDOG_MASK (0x7FFFU)
#define PMU_VDD_CORE_AON_WKUP_WDTC_DCDC_AON_WKUP_WDOG_SHIFT (0U)
/*! DCDC_AON_WKUP_WDOG - DCDC_AON Wakeup Watchdog */
#define PMU_VDD_CORE_AON_WKUP_WDTC_DCDC_AON_WKUP_WDOG(x) (((uint32_t)(((uint32_t)(x)) << PMU_VDD_CORE_AON_WKUP_WDTC_DCDC_AON_WKUP_WDOG_SHIFT)) & PMU_VDD_CORE_AON_WKUP_WDTC_DCDC_AON_WKUP_WDOG_MASK)
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
/*! AGDET_HV_EN - High Voltage Glitch Detect Enable */
#define PMU_AGDET_HV_CTRL_AGDET_HV_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_HV_CTRL_AGDET_HV_EN_SHIFT)) & PMU_AGDET_HV_CTRL_AGDET_HV_EN_MASK)

#define PMU_AGDET_HV_CTRL_AGDET_HV_RES_MASK      (0x4U)
#define PMU_AGDET_HV_CTRL_AGDET_HV_RES_SHIFT     (2U)
/*! AGDET_HV_RES - High Voltage Glitch Detect Reset */
#define PMU_AGDET_HV_CTRL_AGDET_HV_RES(x)        (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_HV_CTRL_AGDET_HV_RES_SHIFT)) & PMU_AGDET_HV_CTRL_AGDET_HV_RES_MASK)
/*! @} */

/*! @name AGDET_LV_CTRL - Low Voltage Glitch Detect Control */
/*! @{ */

#define PMU_AGDET_LV_CTRL_AGDET_LV_EN_MASK       (0x2U)
#define PMU_AGDET_LV_CTRL_AGDET_LV_EN_SHIFT      (1U)
/*! AGDET_LV_EN - Low Voltage Glitch Detect Signal */
#define PMU_AGDET_LV_CTRL_AGDET_LV_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_LV_CTRL_AGDET_LV_EN_SHIFT)) & PMU_AGDET_LV_CTRL_AGDET_LV_EN_MASK)

#define PMU_AGDET_LV_CTRL_AGDET_LV_RES_MASK      (0x4U)
#define PMU_AGDET_LV_CTRL_AGDET_LV_RES_SHIFT     (2U)
/*! AGDET_LV_RES - Low Voltage Glitch Detect Reset */
#define PMU_AGDET_LV_CTRL_AGDET_LV_RES(x)        (((uint32_t)(((uint32_t)(x)) << PMU_AGDET_LV_CTRL_AGDET_LV_RES_SHIFT)) & PMU_AGDET_LV_CTRL_AGDET_LV_RES_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define PMU_STATUS_AGDET_HV_OUT_MASK             (0x8U)
#define PMU_STATUS_AGDET_HV_OUT_SHIFT            (3U)
/*! AGDET_HV_OUT - High-Voltage Glitch Detected Output */
#define PMU_STATUS_AGDET_HV_OUT(x)               (((uint32_t)(((uint32_t)(x)) << PMU_STATUS_AGDET_HV_OUT_SHIFT)) & PMU_STATUS_AGDET_HV_OUT_MASK)

#define PMU_STATUS_AGDET_HV_CNTR_MASK            (0xF0U)
#define PMU_STATUS_AGDET_HV_CNTR_SHIFT           (4U)
/*! AGDET_HV_CNTR - High-Voltage Glitch Counter Value */
#define PMU_STATUS_AGDET_HV_CNTR(x)              (((uint32_t)(((uint32_t)(x)) << PMU_STATUS_AGDET_HV_CNTR_SHIFT)) & PMU_STATUS_AGDET_HV_CNTR_MASK)

#define PMU_STATUS_AGDET_LV_OUT_MASK             (0x100U)
#define PMU_STATUS_AGDET_LV_OUT_SHIFT            (8U)
/*! AGDET_LV_OUT - Low Voltage Glitch Detected Output */
#define PMU_STATUS_AGDET_LV_OUT(x)               (((uint32_t)(((uint32_t)(x)) << PMU_STATUS_AGDET_LV_OUT_SHIFT)) & PMU_STATUS_AGDET_LV_OUT_MASK)

#define PMU_STATUS_AGDET_LV_CNTR_MASK            (0x1E00U)
#define PMU_STATUS_AGDET_LV_CNTR_SHIFT           (9U)
/*! AGDET_LV_CNTR - Low Voltage Glitch Counter Value */
#define PMU_STATUS_AGDET_LV_CNTR(x)              (((uint32_t)(((uint32_t)(x)) << PMU_STATUS_AGDET_LV_CNTR_SHIFT)) & PMU_STATUS_AGDET_LV_CNTR_MASK)
/*! @} */

/*! @name VDD_LVD_HVD_CTRL - VDD LVD_HVD_CTRL */
/*! @{ */

#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_EN_MASK    (0x1U)
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_EN_SHIFT   (0U)
/*! VDD_LVDH_EN - Low Voltage Detect Enable */
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_EN(x)      (((uint32_t)(((uint32_t)(x)) << PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_EN_SHIFT)) & PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_EN_MASK)

#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_MASK (0x2U)
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_SHIFT (1U)
/*! VDD_LVDH_LEVEL - LVD Level Select */
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL(x)   (((uint32_t)(((uint32_t)(x)) << PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_SHIFT)) & PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_LEVEL_MASK)

#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_MASK       (0x400U)
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_SHIFT      (10U)
/*! VDD_LVDH - Low Voltage Detect Output */
#define PMU_VDD_LVD_HVD_CTRL_VDD_LVDH(x)         (((uint32_t)(((uint32_t)(x)) << PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_SHIFT)) & PMU_VDD_LVD_HVD_CTRL_VDD_LVDH_MASK)
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

