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
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RTC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_RTC.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Size of Registers Arrays */
#define RTC_RTC_COUNT_COUNT                       3u
#define RTC_SECURE_KEY_COUNT                      8u

/** RTC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  __IO uint32_t CONFIG;                            /**< Configuration, offset: 0x100 */
  __IO uint32_t CNT_H;                             /**< Counter High, offset: 0x104 */
  __IO uint32_t CNT_M;                             /**< Counter Middle, offset: 0x108 */
  __IO uint32_t CNT_L;                             /**< Counter Low, offset: 0x10C */
  __IO uint32_t YEAR;                              /**< Year, offset: 0x110 */
  __IO uint32_t MONTH;                             /**< Month, offset: 0x114 */
  __IO uint32_t HOUR_M;                            /**< Hour Minute, offset: 0x118 */
  __IO uint32_t SEC_HUND;                          /**< Second Hundredth, offset: 0x11C */
  __IO uint32_t INT;                               /**< Interrupts, offset: 0x120 */
  __O  uint32_t ALARM_H;                           /**< Alarm High, offset: 0x124 */
  __O  uint32_t ALARM_MID;                         /**< Alarm Middle, offset: 0x128 */
  __O  uint32_t ALARM_LOW;                         /**< Alarm Low, offset: 0x12C */
  __O  uint32_t BCD_ALARM_H;                       /**< BCD Alarm Hour, offset: 0x130 */
  __O  uint32_t BCD_ALARM_MIN;                     /**< BCD Alarm, offset: 0x134 */
  __O  uint32_t BCD_ALARM_L;                       /**< BCD Alarm Low, offset: 0x138 */
  __IO uint32_t WDT_SET_VA;                        /**< WDT Set Value, offset: 0x13C */
  __IO uint32_t TAMP_CTRL;                         /**< Tamper Control, offset: 0x140 */
  __IO uint32_t RTC_COUNT[RTC_RTC_COUNT_COUNT];    /**< Latched RTC Counter, array offset: 0x144, array step: 0x4 */
  __IO uint32_t SECURE_KEY[RTC_SECURE_KEY_COUNT];  /**< Secure Key, array offset: 0x150, array step: 0x4 */
  __IO uint32_t RTC_ALV_DTCT;                      /**< RTC Alive Detector, offset: 0x170 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name CONFIG - Configuration */
/*! @{ */

#define RTC_CONFIG_EN_MASK                       (0x1U)
#define RTC_CONFIG_EN_SHIFT                      (0U)
/*! EN - Enable */
#define RTC_CONFIG_EN(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_EN_SHIFT)) & RTC_CONFIG_EN_MASK)

#define RTC_CONFIG_FREE_RUNNING_MASK             (0x2U)
#define RTC_CONFIG_FREE_RUNNING_SHIFT            (1U)
/*! FREE_RUNNING - FREE_RUNNING
 *  0b0..Time date format
 *  0b1..Free running counter
 */
#define RTC_CONFIG_FREE_RUNNING(x)               (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_FREE_RUNNING_SHIFT)) & RTC_CONFIG_FREE_RUNNING_MASK)

#define RTC_CONFIG_WDOG_EN_MASK                  (0x4U)
#define RTC_CONFIG_WDOG_EN_SHIFT                 (2U)
/*! WDOG_EN - Watchdog Enable */
#define RTC_CONFIG_WDOG_EN(x)                    (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_WDOG_EN_SHIFT)) & RTC_CONFIG_WDOG_EN_MASK)

#define RTC_CONFIG_SW_RST_MASK                   (0x20U)
#define RTC_CONFIG_SW_RST_SHIFT                  (5U)
/*! SW_RST - Software Reset */
#define RTC_CONFIG_SW_RST(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_SW_RST_SHIFT)) & RTC_CONFIG_SW_RST_MASK)

#define RTC_CONFIG_ALARM0_DIS_MASK               (0x40U)
#define RTC_CONFIG_ALARM0_DIS_SHIFT              (6U)
/*! ALARM0_DIS - Alarm0 Disable */
#define RTC_CONFIG_ALARM0_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_ALARM0_DIS_SHIFT)) & RTC_CONFIG_ALARM0_DIS_MASK)

#define RTC_CONFIG_ALARM1_DIS_MASK               (0x80U)
#define RTC_CONFIG_ALARM1_DIS_SHIFT              (7U)
/*! ALARM1_DIS - Alarm1 Disable */
#define RTC_CONFIG_ALARM1_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_ALARM1_DIS_SHIFT)) & RTC_CONFIG_ALARM1_DIS_MASK)

#define RTC_CONFIG_ALARM2_DIS_MASK               (0x100U)
#define RTC_CONFIG_ALARM2_DIS_SHIFT              (8U)
/*! ALARM2_DIS - Alarm2 Disable */
#define RTC_CONFIG_ALARM2_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_ALARM2_DIS_SHIFT)) & RTC_CONFIG_ALARM2_DIS_MASK)

#define RTC_CONFIG_IF_READY_MASK                 (0x200U)
#define RTC_CONFIG_IF_READY_SHIFT                (9U)
/*! IF_READY - Interface Ready
 *  0b0..RTC interface is busy, CPU should wait before start the next transaction
 *  0b1..RTC interface is idle, the CPU can start the next transaction
 */
#define RTC_CONFIG_IF_READY(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_IF_READY_SHIFT)) & RTC_CONFIG_IF_READY_MASK)

#define RTC_CONFIG_READ_COLL_MASK                (0x400U)
#define RTC_CONFIG_READ_COLL_SHIFT               (10U)
/*! READ_COLL - Read Collision */
#define RTC_CONFIG_READ_COLL(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_READ_COLL_SHIFT)) & RTC_CONFIG_READ_COLL_MASK)

#define RTC_CONFIG_K_EN_MASK                     (0x800U)
#define RTC_CONFIG_K_EN_SHIFT                    (11U)
/*! K_EN - 2K Enable */
#define RTC_CONFIG_K_EN(x)                       (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_K_EN_SHIFT)) & RTC_CONFIG_K_EN_MASK)

#define RTC_CONFIG_XTAL32_EN_MASK                (0x1000U)
#define RTC_CONFIG_XTAL32_EN_SHIFT               (12U)
/*! XTAL32_EN - XTAL32 Enable */
#define RTC_CONFIG_XTAL32_EN(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_CONFIG_XTAL32_EN_SHIFT)) & RTC_CONFIG_XTAL32_EN_MASK)
/*! @} */

/*! @name CNT_H - Counter High */
/*! @{ */

#define RTC_CNT_H_CTRL_HIGH_MASK                 (0xFFU)
#define RTC_CNT_H_CTRL_HIGH_SHIFT                (0U)
/*! CTRL_HIGH - Control High */
#define RTC_CNT_H_CTRL_HIGH(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CNT_H_CTRL_HIGH_SHIFT)) & RTC_CNT_H_CTRL_HIGH_MASK)
/*! @} */

/*! @name CNT_M - Counter Middle */
/*! @{ */

#define RTC_CNT_M_CTRL_MIDDLE_MASK               (0xFFFFU)
#define RTC_CNT_M_CTRL_MIDDLE_SHIFT              (0U)
/*! CTRL_MIDDLE - Control Middle */
#define RTC_CNT_M_CTRL_MIDDLE(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_CNT_M_CTRL_MIDDLE_SHIFT)) & RTC_CNT_M_CTRL_MIDDLE_MASK)
/*! @} */

/*! @name CNT_L - Counter Low */
/*! @{ */

#define RTC_CNT_L_CTRL_LOW_MASK                  (0xFFFFU)
#define RTC_CNT_L_CTRL_LOW_SHIFT                 (0U)
/*! CTRL_LOW - Control Low */
#define RTC_CNT_L_CTRL_LOW(x)                    (((uint32_t)(((uint32_t)(x)) << RTC_CNT_L_CTRL_LOW_SHIFT)) & RTC_CNT_L_CTRL_LOW_MASK)
/*! @} */

/*! @name YEAR - Year */
/*! @{ */

#define RTC_YEAR_YEAR_MASK                       (0x7FU)
#define RTC_YEAR_YEAR_SHIFT                      (0U)
#define RTC_YEAR_YEAR(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_YEAR_YEAR_SHIFT)) & RTC_YEAR_YEAR_MASK)
/*! @} */

/*! @name MONTH - Month */
/*! @{ */

#define RTC_MONTH_DAY_MASK                       (0x1FU)
#define RTC_MONTH_DAY_SHIFT                      (0U)
/*! DAY - DAY */
#define RTC_MONTH_DAY(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_MONTH_DAY_SHIFT)) & RTC_MONTH_DAY_MASK)

#define RTC_MONTH_MONTH_MASK                     (0xF00U)
#define RTC_MONTH_MONTH_SHIFT                    (8U)
/*! MONTH - Month
 *  0b0000..January
 *  0b0001..February
 *  0b0010..March
 *  0b0100..April
 *  0b0101..May
 *  0b0110..June
 *  0b0111..July
 *  0b1000..August
 *  0b1001..September
 */
#define RTC_MONTH_MONTH(x)                       (((uint32_t)(((uint32_t)(x)) << RTC_MONTH_MONTH_SHIFT)) & RTC_MONTH_MONTH_MASK)

#define RTC_MONTH_WEEK_MASK                      (0xE000U)
#define RTC_MONTH_WEEK_SHIFT                     (13U)
/*! WEEK - Day of the week
 *  0b000..Sunday
 *  0b001..Monday
 *  0b010..Tuesday
 *  0b011..Wednesday
 *  0b100..Thursday
 *  0b101..Friday
 *  0b110..Saturday
 */
#define RTC_MONTH_WEEK(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_MONTH_WEEK_SHIFT)) & RTC_MONTH_WEEK_MASK)
/*! @} */

/*! @name HOUR_M - Hour Minute */
/*! @{ */

#define RTC_HOUR_M_MIN_MASK                      (0x3FU)
#define RTC_HOUR_M_MIN_SHIFT                     (0U)
/*! MIN - Minute */
#define RTC_HOUR_M_MIN(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_HOUR_M_MIN_SHIFT)) & RTC_HOUR_M_MIN_MASK)

#define RTC_HOUR_M_HOUR_MASK                     (0x1F00U)
#define RTC_HOUR_M_HOUR_SHIFT                    (8U)
/*! HOUR - Hour */
#define RTC_HOUR_M_HOUR(x)                       (((uint32_t)(((uint32_t)(x)) << RTC_HOUR_M_HOUR_SHIFT)) & RTC_HOUR_M_HOUR_MASK)
/*! @} */

/*! @name SEC_HUND - Second Hundredth */
/*! @{ */

#define RTC_SEC_HUND_HUND_MASK                   (0x7FU)
#define RTC_SEC_HUND_HUND_SHIFT                  (0U)
/*! HUND - Hundredth */
#define RTC_SEC_HUND_HUND(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_SEC_HUND_HUND_SHIFT)) & RTC_SEC_HUND_HUND_MASK)

#define RTC_SEC_HUND_SEC_MASK                    (0x3F00U)
#define RTC_SEC_HUND_SEC_SHIFT                   (8U)
/*! SEC - Second */
#define RTC_SEC_HUND_SEC(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_SEC_HUND_SEC_SHIFT)) & RTC_SEC_HUND_SEC_MASK)
/*! @} */

/*! @name INT - Interrupts */
/*! @{ */

#define RTC_INT_ALARM0_IF_MASK                   (0x1U)
#define RTC_INT_ALARM0_IF_SHIFT                  (0U)
/*! ALARM0_IF - Alarm 0 interrupt flag, write 1 to this bit will reset the flag */
#define RTC_INT_ALARM0_IF(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_INT_ALARM0_IF_SHIFT)) & RTC_INT_ALARM0_IF_MASK)

#define RTC_INT_ALARM1_IF_MASK                   (0x2U)
#define RTC_INT_ALARM1_IF_SHIFT                  (1U)
/*! ALARM1_IF - Alarm 1 interrupt flag, write 1 to this bit will reset the flag */
#define RTC_INT_ALARM1_IF(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_INT_ALARM1_IF_SHIFT)) & RTC_INT_ALARM1_IF_MASK)

#define RTC_INT_ALARM2_IF_MASK                   (0x4U)
#define RTC_INT_ALARM2_IF_SHIFT                  (2U)
/*! ALARM2_IF - Alarm 2 interrupt flag, write 1 to this bit will reset the flag */
#define RTC_INT_ALARM2_IF(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_INT_ALARM2_IF_SHIFT)) & RTC_INT_ALARM2_IF_MASK)

#define RTC_INT_XTAL_FAIL_IF_MASK                (0x8U)
#define RTC_INT_XTAL_FAIL_IF_SHIFT               (3U)
/*! XTAL_FAIL_IF - XTAL failed interrupt flag, write 1 to this bit will reset the flag */
#define RTC_INT_XTAL_FAIL_IF(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_INT_XTAL_FAIL_IF_SHIFT)) & RTC_INT_XTAL_FAIL_IF_MASK)

#define RTC_INT_WDT_IF_MASK                      (0x10U)
#define RTC_INT_WDT_IF_SHIFT                     (4U)
/*! WDT_IF - Watch Dog Interrupt Flag */
#define RTC_INT_WDT_IF(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_INT_WDT_IF_SHIFT)) & RTC_INT_WDT_IF_MASK)

#define RTC_INT_TAMP_DET_PIN0_MASK               (0x20U)
#define RTC_INT_TAMP_DET_PIN0_SHIFT              (5U)
/*! TAMP_DET_PIN0 - Tamper Detect Pin 0 */
#define RTC_INT_TAMP_DET_PIN0(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_INT_TAMP_DET_PIN0_SHIFT)) & RTC_INT_TAMP_DET_PIN0_MASK)

#define RTC_INT_TAMP_DET_PIN1_MASK               (0x40U)
#define RTC_INT_TAMP_DET_PIN1_SHIFT              (6U)
/*! TAMP_DET_PIN1 - Tamper Detect Pin 1 */
#define RTC_INT_TAMP_DET_PIN1(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_INT_TAMP_DET_PIN1_SHIFT)) & RTC_INT_TAMP_DET_PIN1_MASK)

#define RTC_INT_ALARM0_IE_MASK                   (0x100U)
#define RTC_INT_ALARM0_IE_SHIFT                  (8U)
/*! ALARM0_IE - Alarm0 Interrupt Enable */
#define RTC_INT_ALARM0_IE(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_INT_ALARM0_IE_SHIFT)) & RTC_INT_ALARM0_IE_MASK)

#define RTC_INT_ALARM1_IE_MASK                   (0x200U)
#define RTC_INT_ALARM1_IE_SHIFT                  (9U)
/*! ALARM1_IE - Alarm1 Interrupt Enable */
#define RTC_INT_ALARM1_IE(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_INT_ALARM1_IE_SHIFT)) & RTC_INT_ALARM1_IE_MASK)

#define RTC_INT_ALARM2_IE_MASK                   (0x400U)
#define RTC_INT_ALARM2_IE_SHIFT                  (10U)
/*! ALARM2_IE - Alarm 2 Interrupt Enable */
#define RTC_INT_ALARM2_IE(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_INT_ALARM2_IE_SHIFT)) & RTC_INT_ALARM2_IE_MASK)

#define RTC_INT_XTAL_FAIL_IE_MASK                (0x800U)
#define RTC_INT_XTAL_FAIL_IE_SHIFT               (11U)
/*! XTAL_FAIL_IE - XTAL Fail Interrupt Enable */
#define RTC_INT_XTAL_FAIL_IE(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_INT_XTAL_FAIL_IE_SHIFT)) & RTC_INT_XTAL_FAIL_IE_MASK)

#define RTC_INT_WDT_IE_MASK                      (0x1000U)
#define RTC_INT_WDT_IE_SHIFT                     (12U)
/*! WDT_IE - Watch dog interrupt enable */
#define RTC_INT_WDT_IE(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_INT_WDT_IE_SHIFT)) & RTC_INT_WDT_IE_MASK)

#define RTC_INT_TMP_DET_PIN0_IE_MASK             (0x2000U)
#define RTC_INT_TMP_DET_PIN0_IE_SHIFT            (13U)
/*! TMP_DET_PIN0_IE - Temperature Detect Pin0 Interrupt Enable */
#define RTC_INT_TMP_DET_PIN0_IE(x)               (((uint32_t)(((uint32_t)(x)) << RTC_INT_TMP_DET_PIN0_IE_SHIFT)) & RTC_INT_TMP_DET_PIN0_IE_MASK)

#define RTC_INT_TMP_DET_PIN1_IE_MASK             (0x4000U)
#define RTC_INT_TMP_DET_PIN1_IE_SHIFT            (14U)
/*! TMP_DET_PIN1_IE - Temperature Detect Pin1 Interrupt Enable */
#define RTC_INT_TMP_DET_PIN1_IE(x)               (((uint32_t)(((uint32_t)(x)) << RTC_INT_TMP_DET_PIN1_IE_SHIFT)) & RTC_INT_TMP_DET_PIN1_IE_MASK)
/*! @} */

/*! @name ALARM_H - Alarm High */
/*! @{ */

#define RTC_ALARM_H_ALARM_MASK                   (0xFFU)
#define RTC_ALARM_H_ALARM_SHIFT                  (0U)
/*! ALARM - ALARMN */
#define RTC_ALARM_H_ALARM(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_ALARM_H_ALARM_SHIFT)) & RTC_ALARM_H_ALARM_MASK)

#define RTC_ALARM_H_ALARM_NUM_MASK               (0x6000U)
#define RTC_ALARM_H_ALARM_NUM_SHIFT              (13U)
/*! ALARM_NUM - Alarm Number */
#define RTC_ALARM_H_ALARM_NUM(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_ALARM_H_ALARM_NUM_SHIFT)) & RTC_ALARM_H_ALARM_NUM_MASK)

#define RTC_ALARM_H_ALARM_REP_MASK               (0x8000U)
#define RTC_ALARM_H_ALARM_REP_SHIFT              (15U)
/*! ALARM_REP - Alarm Repeat */
#define RTC_ALARM_H_ALARM_REP(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_ALARM_H_ALARM_REP_SHIFT)) & RTC_ALARM_H_ALARM_REP_MASK)
/*! @} */

/*! @name ALARM_MID - Alarm Middle */
/*! @{ */

#define RTC_ALARM_MID_ALARM_M_MASK               (0xFFFFU)
#define RTC_ALARM_MID_ALARM_M_SHIFT              (0U)
/*! ALARM_M - Alarmn Middle */
#define RTC_ALARM_MID_ALARM_M(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_ALARM_MID_ALARM_M_SHIFT)) & RTC_ALARM_MID_ALARM_M_MASK)
/*! @} */

/*! @name ALARM_LOW - Alarm Low */
/*! @{ */

#define RTC_ALARM_LOW_ALARMN_L_MASK              (0xFFFFU)
#define RTC_ALARM_LOW_ALARMN_L_SHIFT             (0U)
/*! ALARMN_L - Alarmn Low */
#define RTC_ALARM_LOW_ALARMN_L(x)                (((uint32_t)(((uint32_t)(x)) << RTC_ALARM_LOW_ALARMN_L_SHIFT)) & RTC_ALARM_LOW_ALARMN_L_MASK)
/*! @} */

/*! @name BCD_ALARM_H - BCD Alarm Hour */
/*! @{ */

#define RTC_BCD_ALARM_H_DAY_WEEK_MASK            (0x7FU)
#define RTC_BCD_ALARM_H_DAY_WEEK_SHIFT           (0U)
/*! DAY_WEEK - Alarm Day of Week */
#define RTC_BCD_ALARM_H_DAY_WEEK(x)              (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_H_DAY_WEEK_SHIFT)) & RTC_BCD_ALARM_H_DAY_WEEK_MASK)

#define RTC_BCD_ALARM_H_USE_DAY_MO_MASK          (0x80U)
#define RTC_BCD_ALARM_H_USE_DAY_MO_SHIFT         (7U)
/*! USE_DAY_MO - Alarm Use Day of Month */
#define RTC_BCD_ALARM_H_USE_DAY_MO(x)            (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_H_USE_DAY_MO_SHIFT)) & RTC_BCD_ALARM_H_USE_DAY_MO_MASK)

#define RTC_BCD_ALARM_H_MONTH_MASK               (0xF00U)
#define RTC_BCD_ALARM_H_MONTH_SHIFT              (8U)
/*! MONTH - Alarm Month
 *  0b0000..January
 *  0b0001..February
 *  0b0010..March
 *  0b0011..April
 *  0b0100..May
 *  0b0101..June
 *  0b0110..July
 *  0b0111..August
 *  0b1000..September
 *  0b1001..October
 *  0b1010..November
 *  0b1011..December
 */
#define RTC_BCD_ALARM_H_MONTH(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_H_MONTH_SHIFT)) & RTC_BCD_ALARM_H_MONTH_MASK)

#define RTC_BCD_ALARM_H_USE_MO_MASK              (0x1000U)
#define RTC_BCD_ALARM_H_USE_MO_SHIFT             (12U)
/*! USE_MO - Alarm Use Month */
#define RTC_BCD_ALARM_H_USE_MO(x)                (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_H_USE_MO_SHIFT)) & RTC_BCD_ALARM_H_USE_MO_MASK)

#define RTC_BCD_ALARM_H_NUM_MASK                 (0x6000U)
#define RTC_BCD_ALARM_H_NUM_SHIFT                (13U)
/*! NUM - Alarm Number */
#define RTC_BCD_ALARM_H_NUM(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_H_NUM_SHIFT)) & RTC_BCD_ALARM_H_NUM_MASK)

#define RTC_BCD_ALARM_H_REP_MASK                 (0x8000U)
#define RTC_BCD_ALARM_H_REP_SHIFT                (15U)
/*! REP - Alarm Repeat */
#define RTC_BCD_ALARM_H_REP(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_H_REP_SHIFT)) & RTC_BCD_ALARM_H_REP_MASK)
/*! @} */

/*! @name BCD_ALARM_MIN - BCD Alarm */
/*! @{ */

#define RTC_BCD_ALARM_MIN_MIN_MASK               (0x3FU)
#define RTC_BCD_ALARM_MIN_MIN_SHIFT              (0U)
/*! MIN - Alarm Minute */
#define RTC_BCD_ALARM_MIN_MIN(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_MIN_MIN_SHIFT)) & RTC_BCD_ALARM_MIN_MIN_MASK)

#define RTC_BCD_ALARM_MIN_HOUR_MASK              (0x7C0U)
#define RTC_BCD_ALARM_MIN_HOUR_SHIFT             (6U)
/*! HOUR - Alarm Hour */
#define RTC_BCD_ALARM_MIN_HOUR(x)                (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_MIN_HOUR_SHIFT)) & RTC_BCD_ALARM_MIN_HOUR_MASK)

#define RTC_BCD_ALARM_MIN_DAY_MO_MASK            (0xF800U)
#define RTC_BCD_ALARM_MIN_DAY_MO_SHIFT           (11U)
/*! DAY_MO - Alarm Day of Month */
#define RTC_BCD_ALARM_MIN_DAY_MO(x)              (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_MIN_DAY_MO_SHIFT)) & RTC_BCD_ALARM_MIN_DAY_MO_MASK)
/*! @} */

/*! @name BCD_ALARM_L - BCD Alarm Low */
/*! @{ */

#define RTC_BCD_ALARM_L_HUND_MASK                (0x7FU)
#define RTC_BCD_ALARM_L_HUND_SHIFT               (0U)
/*! HUND - Alarm Hundredth */
#define RTC_BCD_ALARM_L_HUND(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_L_HUND_SHIFT)) & RTC_BCD_ALARM_L_HUND_MASK)

#define RTC_BCD_ALARM_L_USE_SEC_MASK             (0x80U)
#define RTC_BCD_ALARM_L_USE_SEC_SHIFT            (7U)
/*! USE_SEC - Alarm Use Second */
#define RTC_BCD_ALARM_L_USE_SEC(x)               (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_L_USE_SEC_SHIFT)) & RTC_BCD_ALARM_L_USE_SEC_MASK)

#define RTC_BCD_ALARM_L_SEC_MASK                 (0x3F00U)
#define RTC_BCD_ALARM_L_SEC_SHIFT                (8U)
/*! SEC - Alarm Second */
#define RTC_BCD_ALARM_L_SEC(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_L_SEC_SHIFT)) & RTC_BCD_ALARM_L_SEC_MASK)

#define RTC_BCD_ALARM_L_USE_MIN_MASK             (0x4000U)
#define RTC_BCD_ALARM_L_USE_MIN_SHIFT            (14U)
/*! USE_MIN - Alarm Use Minute */
#define RTC_BCD_ALARM_L_USE_MIN(x)               (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_L_USE_MIN_SHIFT)) & RTC_BCD_ALARM_L_USE_MIN_MASK)

#define RTC_BCD_ALARM_L_USE_HOUR_MASK            (0x8000U)
#define RTC_BCD_ALARM_L_USE_HOUR_SHIFT           (15U)
/*! USE_HOUR - Alarm Use Hour */
#define RTC_BCD_ALARM_L_USE_HOUR(x)              (((uint32_t)(((uint32_t)(x)) << RTC_BCD_ALARM_L_USE_HOUR_SHIFT)) & RTC_BCD_ALARM_L_USE_HOUR_MASK)
/*! @} */

/*! @name WDT_SET_VA - WDT Set Value */
/*! @{ */

#define RTC_WDT_SET_VA_WDT_CNTR_MASK             (0xFFFFU)
#define RTC_WDT_SET_VA_WDT_CNTR_SHIFT            (0U)
/*! WDT_CNTR - WDT_CNTR */
#define RTC_WDT_SET_VA_WDT_CNTR(x)               (((uint32_t)(((uint32_t)(x)) << RTC_WDT_SET_VA_WDT_CNTR_SHIFT)) & RTC_WDT_SET_VA_WDT_CNTR_MASK)
/*! @} */

/*! @name TAMP_CTRL - Tamper Control */
/*! @{ */

#define RTC_TAMP_CTRL_TAMP_LOG_EN_MASK           (0x1U)
#define RTC_TAMP_CTRL_TAMP_LOG_EN_SHIFT          (0U)
/*! TAMP_LOG_EN - Tamper Logic Enable */
#define RTC_TAMP_CTRL_TAMP_LOG_EN(x)             (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_TAMP_LOG_EN_SHIFT)) & RTC_TAMP_CTRL_TAMP_LOG_EN_MASK)

#define RTC_TAMP_CTRL_TAMP_EN_MASK               (0x6U)
#define RTC_TAMP_CTRL_TAMP_EN_SHIFT              (1U)
/*! TAMP_EN - Tamper Enable */
#define RTC_TAMP_CTRL_TAMP_EN(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_TAMP_EN_SHIFT)) & RTC_TAMP_CTRL_TAMP_EN_MASK)

#define RTC_TAMP_CTRL_TAMP_POL_MASK              (0x18U)
#define RTC_TAMP_CTRL_TAMP_POL_SHIFT             (3U)
/*! TAMP_POL - Tamper Polarity
 *  0b00..Active Low Tamper
 *  0b01..Active High Tamper
 */
#define RTC_TAMP_CTRL_TAMP_POL(x)                (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_TAMP_POL_SHIFT)) & RTC_TAMP_CTRL_TAMP_POL_MASK)

#define RTC_TAMP_CTRL_TAMP_PULL_CTRL_MASK        (0x60U)
#define RTC_TAMP_CTRL_TAMP_PULL_CTRL_SHIFT       (5U)
/*! TAMP_PULL_CTRL - Tamper Pull Control
 *  0b00..Pull up is enabled
 *  0b01..Pull up is disabled
 */
#define RTC_TAMP_CTRL_TAMP_PULL_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_TAMP_PULL_CTRL_SHIFT)) & RTC_TAMP_CTRL_TAMP_PULL_CTRL_MASK)

#define RTC_TAMP_CTRL_READ_CNTR_STRT_MASK        (0x80U)
#define RTC_TAMP_CTRL_READ_CNTR_STRT_SHIFT       (7U)
/*! READ_CNTR_STRT - Read RTC Counter Latched Start */
#define RTC_TAMP_CTRL_READ_CNTR_STRT(x)          (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_READ_CNTR_STRT_SHIFT)) & RTC_TAMP_CTRL_READ_CNTR_STRT_MASK)

#define RTC_TAMP_CTRL_READ_SEC_KEY_MASK          (0x100U)
#define RTC_TAMP_CTRL_READ_SEC_KEY_SHIFT         (8U)
/*! READ_SEC_KEY - Read Secure Key Start */
#define RTC_TAMP_CTRL_READ_SEC_KEY(x)            (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_READ_SEC_KEY_SHIFT)) & RTC_TAMP_CTRL_READ_SEC_KEY_MASK)

#define RTC_TAMP_CTRL_READ_CNTR_READY_MASK       (0x200U)
#define RTC_TAMP_CTRL_READ_CNTR_READY_SHIFT      (9U)
/*! READ_CNTR_READY - Read RTC Counter Latched Ready */
#define RTC_TAMP_CTRL_READ_CNTR_READY(x)         (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_READ_CNTR_READY_SHIFT)) & RTC_TAMP_CTRL_READ_CNTR_READY_MASK)

#define RTC_TAMP_CTRL_SEC_KEY_READY_MASK         (0x400U)
#define RTC_TAMP_CTRL_SEC_KEY_READY_SHIFT        (10U)
/*! SEC_KEY_READY - Secure Key Ready */
#define RTC_TAMP_CTRL_SEC_KEY_READY(x)           (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_SEC_KEY_READY_SHIFT)) & RTC_TAMP_CTRL_SEC_KEY_READY_MASK)

#define RTC_TAMP_CTRL_WRITE_LCK_MASK             (0x800U)
#define RTC_TAMP_CTRL_WRITE_LCK_SHIFT            (11U)
/*! WRITE_LCK - Write Lock */
#define RTC_TAMP_CTRL_WRITE_LCK(x)               (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_WRITE_LCK_SHIFT)) & RTC_TAMP_CTRL_WRITE_LCK_MASK)

#define RTC_TAMP_CTRL_TAMP_DET_MASK              (0x3000U)
#define RTC_TAMP_CTRL_TAMP_DET_SHIFT             (12U)
/*! TAMP_DET - Tamper Detected */
#define RTC_TAMP_CTRL_TAMP_DET(x)                (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_TAMP_DET_SHIFT)) & RTC_TAMP_CTRL_TAMP_DET_MASK)

#define RTC_TAMP_CTRL_TAMP_CTRL_MASK             (0xC000U)
#define RTC_TAMP_CTRL_TAMP_CTRL_SHIFT            (14U)
/*! TAMP_CTRL - Tamper Control
 *  0b00..Filter is disabled
 *  0b01..Filter is disabled
 */
#define RTC_TAMP_CTRL_TAMP_CTRL(x)               (((uint32_t)(((uint32_t)(x)) << RTC_TAMP_CTRL_TAMP_CTRL_SHIFT)) & RTC_TAMP_CTRL_TAMP_CTRL_MASK)
/*! @} */

/*! @name RTC_COUNT - Latched RTC Counter */
/*! @{ */

#define RTC_RTC_COUNT_RTC_COUNT_MASK             (0xFFFFU)
#define RTC_RTC_COUNT_RTC_COUNT_SHIFT            (0U)
/*! RTC_COUNT - Latched RTC Count[x+15:x] */
#define RTC_RTC_COUNT_RTC_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << RTC_RTC_COUNT_RTC_COUNT_SHIFT)) & RTC_RTC_COUNT_RTC_COUNT_MASK)
/*! @} */

/*! @name SECURE_KEY - Secure Key */
/*! @{ */

#define RTC_SECURE_KEY_SEC_KEY_MASK              (0xFFFFU)
#define RTC_SECURE_KEY_SEC_KEY_SHIFT             (0U)
/*! SEC_KEY - Secure Key[x+15:x] */
#define RTC_SECURE_KEY_SEC_KEY(x)                (((uint32_t)(((uint32_t)(x)) << RTC_SECURE_KEY_SEC_KEY_SHIFT)) & RTC_SECURE_KEY_SEC_KEY_MASK)
/*! @} */

/*! @name RTC_ALV_DTCT - RTC Alive Detector */
/*! @{ */

#define RTC_RTC_ALV_DTCT_DTCT_EN_MASK            (0x1U)
#define RTC_RTC_ALV_DTCT_DTCT_EN_SHIFT           (0U)
/*! DTCT_EN - RTC alive detector enable */
#define RTC_RTC_ALV_DTCT_DTCT_EN(x)              (((uint32_t)(((uint32_t)(x)) << RTC_RTC_ALV_DTCT_DTCT_EN_SHIFT)) & RTC_RTC_ALV_DTCT_DTCT_EN_MASK)

#define RTC_RTC_ALV_DTCT_BYPASS_MASK             (0x2U)
#define RTC_RTC_ALV_DTCT_BYPASS_SHIFT            (1U)
/*! BYPASS - RTC alive bypass */
#define RTC_RTC_ALV_DTCT_BYPASS(x)               (((uint32_t)(((uint32_t)(x)) << RTC_RTC_ALV_DTCT_BYPASS_SHIFT)) & RTC_RTC_ALV_DTCT_BYPASS_MASK)

#define RTC_RTC_ALV_DTCT_ACTV_PRD_MASK           (0xFCU)
#define RTC_RTC_ALV_DTCT_ACTV_PRD_SHIFT          (2U)
/*! ACTV_PRD - Period of the Alive Detector Mechanism */
#define RTC_RTC_ALV_DTCT_ACTV_PRD(x)             (((uint32_t)(((uint32_t)(x)) << RTC_RTC_ALV_DTCT_ACTV_PRD_SHIFT)) & RTC_RTC_ALV_DTCT_ACTV_PRD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


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


#endif  /* PERI_RTC_H_ */

