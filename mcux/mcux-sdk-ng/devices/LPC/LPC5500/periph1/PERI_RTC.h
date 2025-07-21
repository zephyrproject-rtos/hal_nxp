/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RTC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint16_t YEARMON;                           /**< Year and Month Counters, offset: 0x0 */
  __IO uint16_t DAYS;                              /**< Days and Day-of-Week Counters, offset: 0x2 */
  __IO uint16_t HOURMIN;                           /**< Hours and Minutes Counters, offset: 0x4 */
  __IO uint16_t SECONDS;                           /**< Seconds Counters, offset: 0x6 */
  __IO uint16_t ALM_YEARMON;                       /**< Year and Months Alarm, offset: 0x8 */
  __IO uint16_t ALM_DAYS;                          /**< Days Alarm, offset: 0xA */
  __IO uint16_t ALM_HOURMIN;                       /**< Hours and Minutes Alarm, offset: 0xC */
  __IO uint16_t ALM_SECONDS;                       /**< Seconds Alarm, offset: 0xE */
  __IO uint16_t CTRL;                              /**< Control, offset: 0x10 */
  __IO uint16_t STATUS;                            /**< Status, offset: 0x12 */
  __IO uint16_t ISR;                               /**< Interrupt Status, offset: 0x14 */
  __IO uint16_t IER;                               /**< Interrupt Enable, offset: 0x16 */
       uint8_t RESERVED_0[8];
  __IO uint16_t GP_DATA_REG;                       /**< General Purpose Data, offset: 0x20 */
  __IO uint16_t DST_HOUR;                          /**< Daylight Saving Hour, offset: 0x22 */
  __IO uint16_t DST_MONTH;                         /**< Daylight Saving Month, offset: 0x24 */
  __IO uint16_t DST_DAY;                           /**< Daylight Saving Day, offset: 0x26 */
  __IO uint16_t COMPEN;                            /**< Compensation, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint16_t TAMPER_QSCR;                       /**< Tamper Queue Status and Control, offset: 0x2E */
       uint8_t RESERVED_2[2];
  __IO uint16_t TAMPER_SCR;                        /**< Tamper Status and Control, offset: 0x32 */
  __IO uint16_t FILTER01_CFG;                      /**< Tamper 01 Filter Configuration, offset: 0x34 */
  __IO uint16_t FILTER23_CFG;                      /**< Tamper 23 Filter Configuration, offset: 0x36 */
       uint8_t RESERVED_3[8];
  __I  uint16_t TAMPER_QUEUE;                      /**< Tamper Queue, offset: 0x40 */
  __IO uint16_t CTRL2;                             /**< Control 2, offset: 0x42 */
       uint8_t RESERVED_4[1980];
  __IO uint32_t SUBSECOND_CTRL;                    /**< Sub-second control, offset: 0x800 */
  __I  uint32_t SUBSECOND_CNT;                     /**< Sub-second counter, offset: 0x804 */
       uint8_t RESERVED_5[1016];
  __IO uint32_t WAKE_TIMER_CTRL;                   /**< Wake timer control, offset: 0xC00 */
       uint8_t RESERVED_6[8];
  __IO uint32_t WAKE_TIMER_CNT;                    /**< Wake timer counter, offset: 0xC0C */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name YEARMON - Year and Month Counters */
/*! @{ */

#define RTC_YEARMON_MON_CNT_MASK                 (0xFU)
#define RTC_YEARMON_MON_CNT_SHIFT                (0U)
/*! MON_CNT - Month Counter
 *  0b0000, 0b1101, 0b1110, 0b1111..Illegal Value
 *  0b0001..January
 *  0b0010..February
 *  0b0011..March
 *  0b0100..April
 *  0b0101..May
 *  0b0110..June
 *  0b0111..July
 *  0b1000..August
 *  0b1001..September
 *  0b1010..October
 *  0b1011..November
 *  0b1100..December
 */
#define RTC_YEARMON_MON_CNT(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_YEARMON_MON_CNT_SHIFT)) & RTC_YEARMON_MON_CNT_MASK)

#define RTC_YEARMON_YROFST_MASK                  (0xFF00U)
#define RTC_YEARMON_YROFST_SHIFT                 (8U)
/*! YROFST - Year Offset Count Value */
#define RTC_YEARMON_YROFST(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_YEARMON_YROFST_SHIFT)) & RTC_YEARMON_YROFST_MASK)
/*! @} */

/*! @name DAYS - Days and Day-of-Week Counters */
/*! @{ */

#define RTC_DAYS_DAY_CNT_MASK                    (0x1FU)
#define RTC_DAYS_DAY_CNT_SHIFT                   (0U)
/*! DAY_CNT - Days Counter Value */
#define RTC_DAYS_DAY_CNT(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_DAYS_DAY_CNT_SHIFT)) & RTC_DAYS_DAY_CNT_MASK)

#define RTC_DAYS_DOW_MASK                        (0x700U)
#define RTC_DAYS_DOW_SHIFT                       (8U)
/*! DOW - Day of Week Counter Value
 *  0b000..Sunday
 *  0b001..Monday
 *  0b010..Tuesday
 *  0b011..Wednesday
 *  0b100..Thursday
 *  0b101..Friday
 *  0b110..Saturday
 *  0b111..
 */
#define RTC_DAYS_DOW(x)                          (((uint16_t)(((uint16_t)(x)) << RTC_DAYS_DOW_SHIFT)) & RTC_DAYS_DOW_MASK)
/*! @} */

/*! @name HOURMIN - Hours and Minutes Counters */
/*! @{ */

#define RTC_HOURMIN_MIN_CNT_MASK                 (0x3FU)
#define RTC_HOURMIN_MIN_CNT_SHIFT                (0U)
/*! MIN_CNT - Minutes Counter Value */
#define RTC_HOURMIN_MIN_CNT(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_HOURMIN_MIN_CNT_SHIFT)) & RTC_HOURMIN_MIN_CNT_MASK)

#define RTC_HOURMIN_HOUR_CNT_MASK                (0x1F00U)
#define RTC_HOURMIN_HOUR_CNT_SHIFT               (8U)
/*! HOUR_CNT - Hours Counter Value */
#define RTC_HOURMIN_HOUR_CNT(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_HOURMIN_HOUR_CNT_SHIFT)) & RTC_HOURMIN_HOUR_CNT_MASK)
/*! @} */

/*! @name SECONDS - Seconds Counters */
/*! @{ */

#define RTC_SECONDS_SEC_CNT_MASK                 (0x3FU)
#define RTC_SECONDS_SEC_CNT_SHIFT                (0U)
/*! SEC_CNT - Seconds Counter Value */
#define RTC_SECONDS_SEC_CNT(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_SECONDS_SEC_CNT_SHIFT)) & RTC_SECONDS_SEC_CNT_MASK)
/*! @} */

/*! @name ALM_YEARMON - Year and Months Alarm */
/*! @{ */

#define RTC_ALM_YEARMON_ALM_MON_MASK             (0xFU)
#define RTC_ALM_YEARMON_ALM_MON_SHIFT            (0U)
/*! ALM_MON - Months Value for Alarm */
#define RTC_ALM_YEARMON_ALM_MON(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_YEARMON_ALM_MON_SHIFT)) & RTC_ALM_YEARMON_ALM_MON_MASK)

#define RTC_ALM_YEARMON_ALM_YEAR_MASK            (0xFF00U)
#define RTC_ALM_YEARMON_ALM_YEAR_SHIFT           (8U)
/*! ALM_YEAR - Year Value for Alarm */
#define RTC_ALM_YEARMON_ALM_YEAR(x)              (((uint16_t)(((uint16_t)(x)) << RTC_ALM_YEARMON_ALM_YEAR_SHIFT)) & RTC_ALM_YEARMON_ALM_YEAR_MASK)
/*! @} */

/*! @name ALM_DAYS - Days Alarm */
/*! @{ */

#define RTC_ALM_DAYS_ALM_DAY_MASK                (0x1FU)
#define RTC_ALM_DAYS_ALM_DAY_SHIFT               (0U)
/*! ALM_DAY - Days Value for Alarm */
#define RTC_ALM_DAYS_ALM_DAY(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_ALM_DAYS_ALM_DAY_SHIFT)) & RTC_ALM_DAYS_ALM_DAY_MASK)
/*! @} */

/*! @name ALM_HOURMIN - Hours and Minutes Alarm */
/*! @{ */

#define RTC_ALM_HOURMIN_ALM_MIN_MASK             (0x3FU)
#define RTC_ALM_HOURMIN_ALM_MIN_SHIFT            (0U)
/*! ALM_MIN - Minutes Value for Alarm */
#define RTC_ALM_HOURMIN_ALM_MIN(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_HOURMIN_ALM_MIN_SHIFT)) & RTC_ALM_HOURMIN_ALM_MIN_MASK)

#define RTC_ALM_HOURMIN_ALM_HOUR_MASK            (0x1F00U)
#define RTC_ALM_HOURMIN_ALM_HOUR_SHIFT           (8U)
/*! ALM_HOUR - Hours Value for Alarm */
#define RTC_ALM_HOURMIN_ALM_HOUR(x)              (((uint16_t)(((uint16_t)(x)) << RTC_ALM_HOURMIN_ALM_HOUR_SHIFT)) & RTC_ALM_HOURMIN_ALM_HOUR_MASK)
/*! @} */

/*! @name ALM_SECONDS - Seconds Alarm */
/*! @{ */

#define RTC_ALM_SECONDS_ALM_SEC_MASK             (0x3FU)
#define RTC_ALM_SECONDS_ALM_SEC_SHIFT            (0U)
/*! ALM_SEC - Seconds Alarm Value */
#define RTC_ALM_SECONDS_ALM_SEC(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_SECONDS_ALM_SEC_SHIFT)) & RTC_ALM_SECONDS_ALM_SEC_MASK)

#define RTC_ALM_SECONDS_DEC_SEC_MASK             (0x100U)
#define RTC_ALM_SECONDS_DEC_SEC_SHIFT            (8U)
/*! DEC_SEC - Decrement Seconds Counter by 1. */
#define RTC_ALM_SECONDS_DEC_SEC(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_SECONDS_DEC_SEC_SHIFT)) & RTC_ALM_SECONDS_DEC_SEC_MASK)

#define RTC_ALM_SECONDS_INC_SEC_MASK             (0x200U)
#define RTC_ALM_SECONDS_INC_SEC_SHIFT            (9U)
/*! INC_SEC - Increment Seconds Counter by 1. */
#define RTC_ALM_SECONDS_INC_SEC(x)               (((uint16_t)(((uint16_t)(x)) << RTC_ALM_SECONDS_INC_SEC_SHIFT)) & RTC_ALM_SECONDS_INC_SEC_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define RTC_CTRL_FINEEN_MASK                     (0x1U)
#define RTC_CTRL_FINEEN_SHIFT                    (0U)
/*! FINEEN - Fine Compensation Enable
 *  0b0..Fine compensation is disabled
 *  0b1..Fine compensation is enabled.
 */
#define RTC_CTRL_FINEEN(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_FINEEN_SHIFT)) & RTC_CTRL_FINEEN_MASK)

#define RTC_CTRL_COMP_EN_MASK                    (0x2U)
#define RTC_CTRL_COMP_EN_SHIFT                   (1U)
/*! COMP_EN - Compensation Enable
 *  0b0..Coarse Compensation is disabled.
 *  0b1..Coarse Compensation is enabled.
 */
#define RTC_CTRL_COMP_EN(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_COMP_EN_SHIFT)) & RTC_CTRL_COMP_EN_MASK)

#define RTC_CTRL_ALM_MATCH_MASK                  (0xCU)
#define RTC_CTRL_ALM_MATCH_SHIFT                 (2U)
/*! ALM_MATCH - Alarm Match
 *  0b00..Only Seconds, Minutes, and Hours matched.
 *  0b01..Only Seconds, Minutes, Hours, and Days matched.
 *  0b10..Only Seconds, Minutes, Hours, Days, and Months matched.
 *  0b11..Only Seconds, Minutes, Hours, Days, Months, and Year (offset) matched.
 */
#define RTC_CTRL_ALM_MATCH(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_ALM_MATCH_SHIFT)) & RTC_CTRL_ALM_MATCH_MASK)

#define RTC_CTRL_TIMER_STB_MASK_MASK             (0x10U)
#define RTC_CTRL_TIMER_STB_MASK_SHIFT            (4U)
/*! TIMER_STB_MASK - Sampling Timer Clocks Mask
 *  0b0..Sampling clocks are not gated when in standby mode
 *  0b1..Sampling clocks are gated in Standby mode
 */
#define RTC_CTRL_TIMER_STB_MASK(x)               (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_TIMER_STB_MASK_SHIFT)) & RTC_CTRL_TIMER_STB_MASK_MASK)

#define RTC_CTRL_DST_EN_MASK                     (0x40U)
#define RTC_CTRL_DST_EN_SHIFT                    (6U)
/*! DST_EN - Daylight Saving Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define RTC_CTRL_DST_EN(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_DST_EN_SHIFT)) & RTC_CTRL_DST_EN_MASK)

#define RTC_CTRL_SWR_MASK                        (0x100U)
#define RTC_CTRL_SWR_SHIFT                       (8U)
/*! SWR - Software Reset
 *  0b0..Software Reset cleared
 *  0b1..Software Reset asserted
 */
#define RTC_CTRL_SWR(x)                          (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_SWR_SHIFT)) & RTC_CTRL_SWR_MASK)

#define RTC_CTRL_CLKOUT_MASK                     (0x6000U)
#define RTC_CTRL_CLKOUT_SHIFT                    (13U)
/*! CLKOUT - RTC Clock Output Selection
 *  0b00..No Output Clock
 *  0b01..Fine 1 Hz Clock with both precise edges
 *  0b10..32.768 kHz Clock
 *  0b11..Coarse 1 Hz Clock with both precise edges
 */
#define RTC_CTRL_CLKOUT(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_CTRL_CLKOUT_SHIFT)) & RTC_CTRL_CLKOUT_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define RTC_STATUS_INVAL_BIT_MASK                (0x1U)
#define RTC_STATUS_INVAL_BIT_SHIFT               (0U)
/*! INVAL_BIT - Invalidate CPU Read/Write Access
 *  0b0..Time /Date Counters can be read/written. Time /Date is valid.
 *  0b1..Time /Date Counter values are changing or Time /Date is invalid and cannot be read or written.
 */
#define RTC_STATUS_INVAL_BIT(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_INVAL_BIT_SHIFT)) & RTC_STATUS_INVAL_BIT_MASK)

#define RTC_STATUS_WRITE_PROT_EN_MASK            (0x2U)
#define RTC_STATUS_WRITE_PROT_EN_SHIFT           (1U)
/*! WRITE_PROT_EN - Write Protect Enable Status
 *  0b0..Registers are unlocked and can be accessed.
 *  0b1..Registers are locked and in read-only mode.
 */
#define RTC_STATUS_WRITE_PROT_EN(x)              (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_WRITE_PROT_EN_SHIFT)) & RTC_STATUS_WRITE_PROT_EN_MASK)

#define RTC_STATUS_CPU_LOW_VOLT_MASK             (0x4U)
#define RTC_STATUS_CPU_LOW_VOLT_SHIFT            (2U)
/*! CPU_LOW_VOLT - CPU Low Voltage Warning Status
 *  0b0..CPU in Normal Operating Voltage.
 *  0b1..CPU Voltage is below Normal Operating Voltage. RTC Registers in read-only mode.
 */
#define RTC_STATUS_CPU_LOW_VOLT(x)               (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_CPU_LOW_VOLT_SHIFT)) & RTC_STATUS_CPU_LOW_VOLT_MASK)

#define RTC_STATUS_RST_SRC_MASK                  (0x8U)
#define RTC_STATUS_RST_SRC_SHIFT                 (3U)
/*! RST_SRC - Reset Source
 *  0b0..Standby Mode Exit
 *  0b1..Power-On Reset
 */
#define RTC_STATUS_RST_SRC(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_RST_SRC_SHIFT)) & RTC_STATUS_RST_SRC_MASK)

#define RTC_STATUS_CMP_INT_MASK                  (0x20U)
#define RTC_STATUS_CMP_INT_SHIFT                 (5U)
/*! CMP_INT - Compensation Interval */
#define RTC_STATUS_CMP_INT(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_CMP_INT_SHIFT)) & RTC_STATUS_CMP_INT_MASK)

#define RTC_STATUS_WE_MASK                       (0xC0U)
#define RTC_STATUS_WE_SHIFT                      (6U)
/*! WE - Write Enable
 *  0b00, 0b01, 0b11, 0b10..Disable Write Protection - Registers are unlocked.
 *  0b10..Enable Write Protection - Registers are locked.
 */
#define RTC_STATUS_WE(x)                         (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_WE_SHIFT)) & RTC_STATUS_WE_MASK)

#define RTC_STATUS_BUS_ERR_MASK                  (0x100U)
#define RTC_STATUS_BUS_ERR_SHIFT                 (8U)
/*! BUS_ERR - Bus Error
 *  0b0..Read and Write accesses are normal.
 *  0b1..Read or Write accesses occurred when STATUS[INVAL_BIT] was asserted.
 */
#define RTC_STATUS_BUS_ERR(x)                    (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_BUS_ERR_SHIFT)) & RTC_STATUS_BUS_ERR_MASK)

#define RTC_STATUS_CMP_DONE_MASK                 (0x800U)
#define RTC_STATUS_CMP_DONE_SHIFT                (11U)
/*! CMP_DONE - Compensation Done
 *  0b0..Compensation busy or not enabled
 *  0b1..Compensation completed
 */
#define RTC_STATUS_CMP_DONE(x)                   (((uint16_t)(((uint16_t)(x)) << RTC_STATUS_CMP_DONE_SHIFT)) & RTC_STATUS_CMP_DONE_MASK)
/*! @} */

/*! @name ISR - Interrupt Status */
/*! @{ */

#define RTC_ISR_TAMPER_IS_MASK                   (0x1U)
#define RTC_ISR_TAMPER_IS_SHIFT                  (0U)
/*! TAMPER_IS - Tamper Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted (Default on reset) .
 */
#define RTC_ISR_TAMPER_IS(x)                     (((uint16_t)(((uint16_t)(x)) << RTC_ISR_TAMPER_IS_SHIFT)) & RTC_ISR_TAMPER_IS_MASK)

#define RTC_ISR_ALM_IS_MASK                      (0x4U)
#define RTC_ISR_ALM_IS_SHIFT                     (2U)
/*! ALM_IS - Alarm Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_ALM_IS(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_ALM_IS_SHIFT)) & RTC_ISR_ALM_IS_MASK)

#define RTC_ISR_DAY_IS_MASK                      (0x8U)
#define RTC_ISR_DAY_IS_SHIFT                     (3U)
/*! DAY_IS - Days Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_DAY_IS(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_DAY_IS_SHIFT)) & RTC_ISR_DAY_IS_MASK)

#define RTC_ISR_HOUR_IS_MASK                     (0x10U)
#define RTC_ISR_HOUR_IS_SHIFT                    (4U)
/*! HOUR_IS - Hours Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_HOUR_IS(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_HOUR_IS_SHIFT)) & RTC_ISR_HOUR_IS_MASK)

#define RTC_ISR_MIN_IS_MASK                      (0x20U)
#define RTC_ISR_MIN_IS_SHIFT                     (5U)
/*! MIN_IS - Minutes Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_MIN_IS(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_MIN_IS_SHIFT)) & RTC_ISR_MIN_IS_MASK)

#define RTC_ISR_IS_1HZ_MASK                      (0x40U)
#define RTC_ISR_IS_1HZ_SHIFT                     (6U)
/*! IS_1HZ - 1 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_1HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_1HZ_SHIFT)) & RTC_ISR_IS_1HZ_MASK)

#define RTC_ISR_IS_2HZ_MASK                      (0x80U)
#define RTC_ISR_IS_2HZ_SHIFT                     (7U)
/*! IS_2HZ - 2 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_2HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_2HZ_SHIFT)) & RTC_ISR_IS_2HZ_MASK)

#define RTC_ISR_IS_4HZ_MASK                      (0x100U)
#define RTC_ISR_IS_4HZ_SHIFT                     (8U)
/*! IS_4HZ - 4 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_4HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_4HZ_SHIFT)) & RTC_ISR_IS_4HZ_MASK)

#define RTC_ISR_IS_8HZ_MASK                      (0x200U)
#define RTC_ISR_IS_8HZ_SHIFT                     (9U)
/*! IS_8HZ - 8 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_8HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_8HZ_SHIFT)) & RTC_ISR_IS_8HZ_MASK)

#define RTC_ISR_IS_16HZ_MASK                     (0x400U)
#define RTC_ISR_IS_16HZ_SHIFT                    (10U)
/*! IS_16HZ - 16 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_16HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_16HZ_SHIFT)) & RTC_ISR_IS_16HZ_MASK)

#define RTC_ISR_IS_32HZ_MASK                     (0x800U)
#define RTC_ISR_IS_32HZ_SHIFT                    (11U)
/*! IS_32HZ - 32 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_32HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_32HZ_SHIFT)) & RTC_ISR_IS_32HZ_MASK)

#define RTC_ISR_IS_64HZ_MASK                     (0x1000U)
#define RTC_ISR_IS_64HZ_SHIFT                    (12U)
/*! IS_64HZ - 64 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_64HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_64HZ_SHIFT)) & RTC_ISR_IS_64HZ_MASK)

#define RTC_ISR_IS_128HZ_MASK                    (0x2000U)
#define RTC_ISR_IS_128HZ_SHIFT                   (13U)
/*! IS_128HZ - 128 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_128HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_128HZ_SHIFT)) & RTC_ISR_IS_128HZ_MASK)

#define RTC_ISR_IS_256HZ_MASK                    (0x4000U)
#define RTC_ISR_IS_256HZ_SHIFT                   (14U)
/*! IS_256HZ - 256 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_256HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_256HZ_SHIFT)) & RTC_ISR_IS_256HZ_MASK)

#define RTC_ISR_IS_512HZ_MASK                    (0x8000U)
#define RTC_ISR_IS_512HZ_SHIFT                   (15U)
/*! IS_512HZ - 512 Hz Interval Interrupt Status
 *  0b0..Interrupt is de-asserted.
 *  0b1..Interrupt is asserted.
 */
#define RTC_ISR_IS_512HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_ISR_IS_512HZ_SHIFT)) & RTC_ISR_IS_512HZ_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define RTC_IER_TAMPER_IE_MASK                   (0x1U)
#define RTC_IER_TAMPER_IE_SHIFT                  (0U)
/*! TAMPER_IE - Tamper Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled (Default on reset).
 */
#define RTC_IER_TAMPER_IE(x)                     (((uint16_t)(((uint16_t)(x)) << RTC_IER_TAMPER_IE_SHIFT)) & RTC_IER_TAMPER_IE_MASK)

#define RTC_IER_ALM_IE_MASK                      (0x4U)
#define RTC_IER_ALM_IE_SHIFT                     (2U)
/*! ALM_IE - Alarm Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_ALM_IE(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_ALM_IE_SHIFT)) & RTC_IER_ALM_IE_MASK)

#define RTC_IER_DAY_IE_MASK                      (0x8U)
#define RTC_IER_DAY_IE_SHIFT                     (3U)
/*! DAY_IE - Days Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_DAY_IE(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_DAY_IE_SHIFT)) & RTC_IER_DAY_IE_MASK)

#define RTC_IER_HOUR_IE_MASK                     (0x10U)
#define RTC_IER_HOUR_IE_SHIFT                    (4U)
/*! HOUR_IE - Hours Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_HOUR_IE(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_HOUR_IE_SHIFT)) & RTC_IER_HOUR_IE_MASK)

#define RTC_IER_MIN_IE_MASK                      (0x20U)
#define RTC_IER_MIN_IE_SHIFT                     (5U)
/*! MIN_IE - Minutes Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_MIN_IE(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_MIN_IE_SHIFT)) & RTC_IER_MIN_IE_MASK)

#define RTC_IER_IE_1HZ_MASK                      (0x40U)
#define RTC_IER_IE_1HZ_SHIFT                     (6U)
/*! IE_1HZ - 1 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_1HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_1HZ_SHIFT)) & RTC_IER_IE_1HZ_MASK)

#define RTC_IER_IE_2HZ_MASK                      (0x80U)
#define RTC_IER_IE_2HZ_SHIFT                     (7U)
/*! IE_2HZ - 2 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_2HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_2HZ_SHIFT)) & RTC_IER_IE_2HZ_MASK)

#define RTC_IER_IE_4HZ_MASK                      (0x100U)
#define RTC_IER_IE_4HZ_SHIFT                     (8U)
/*! IE_4HZ - 4 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_4HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_4HZ_SHIFT)) & RTC_IER_IE_4HZ_MASK)

#define RTC_IER_IE_8HZ_MASK                      (0x200U)
#define RTC_IER_IE_8HZ_SHIFT                     (9U)
/*! IE_8HZ - 8 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_8HZ(x)                        (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_8HZ_SHIFT)) & RTC_IER_IE_8HZ_MASK)

#define RTC_IER_IE_16HZ_MASK                     (0x400U)
#define RTC_IER_IE_16HZ_SHIFT                    (10U)
/*! IE_16HZ - 16 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_16HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_16HZ_SHIFT)) & RTC_IER_IE_16HZ_MASK)

#define RTC_IER_IE_32HZ_MASK                     (0x800U)
#define RTC_IER_IE_32HZ_SHIFT                    (11U)
/*! IE_32HZ - 32 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_32HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_32HZ_SHIFT)) & RTC_IER_IE_32HZ_MASK)

#define RTC_IER_IE_64HZ_MASK                     (0x1000U)
#define RTC_IER_IE_64HZ_SHIFT                    (12U)
/*! IE_64HZ - 64 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_64HZ(x)                       (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_64HZ_SHIFT)) & RTC_IER_IE_64HZ_MASK)

#define RTC_IER_IE_128HZ_MASK                    (0x2000U)
#define RTC_IER_IE_128HZ_SHIFT                   (13U)
/*! IE_128HZ - 128 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_128HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_128HZ_SHIFT)) & RTC_IER_IE_128HZ_MASK)

#define RTC_IER_IE_256HZ_MASK                    (0x4000U)
#define RTC_IER_IE_256HZ_SHIFT                   (14U)
/*! IE_256HZ - 256 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_256HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_256HZ_SHIFT)) & RTC_IER_IE_256HZ_MASK)

#define RTC_IER_IE_512HZ_MASK                    (0x8000U)
#define RTC_IER_IE_512HZ_SHIFT                   (15U)
/*! IE_512HZ - 512 Hz Interval Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define RTC_IER_IE_512HZ(x)                      (((uint16_t)(((uint16_t)(x)) << RTC_IER_IE_512HZ_SHIFT)) & RTC_IER_IE_512HZ_MASK)
/*! @} */

/*! @name GP_DATA_REG - General Purpose Data */
/*! @{ */

#define RTC_GP_DATA_REG_CFG0_MASK                (0x1U)
#define RTC_GP_DATA_REG_CFG0_SHIFT               (0U)
/*! CFG0 - CFGn */
#define RTC_GP_DATA_REG_CFG0(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG0_SHIFT)) & RTC_GP_DATA_REG_CFG0_MASK)

#define RTC_GP_DATA_REG_CFG1_MASK                (0x2U)
#define RTC_GP_DATA_REG_CFG1_SHIFT               (1U)
/*! CFG1 - CFGn */
#define RTC_GP_DATA_REG_CFG1(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG1_SHIFT)) & RTC_GP_DATA_REG_CFG1_MASK)

#define RTC_GP_DATA_REG_CFG2_MASK                (0x4U)
#define RTC_GP_DATA_REG_CFG2_SHIFT               (2U)
/*! CFG2 - CFGn */
#define RTC_GP_DATA_REG_CFG2(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG2_SHIFT)) & RTC_GP_DATA_REG_CFG2_MASK)

#define RTC_GP_DATA_REG_CFG3_MASK                (0x8U)
#define RTC_GP_DATA_REG_CFG3_SHIFT               (3U)
/*! CFG3 - CFGn */
#define RTC_GP_DATA_REG_CFG3(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG3_SHIFT)) & RTC_GP_DATA_REG_CFG3_MASK)

#define RTC_GP_DATA_REG_CFG4_MASK                (0x10U)
#define RTC_GP_DATA_REG_CFG4_SHIFT               (4U)
/*! CFG4 - CFGn */
#define RTC_GP_DATA_REG_CFG4(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG4_SHIFT)) & RTC_GP_DATA_REG_CFG4_MASK)

#define RTC_GP_DATA_REG_CFG5_MASK                (0x20U)
#define RTC_GP_DATA_REG_CFG5_SHIFT               (5U)
/*! CFG5 - CFGn */
#define RTC_GP_DATA_REG_CFG5(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG5_SHIFT)) & RTC_GP_DATA_REG_CFG5_MASK)

#define RTC_GP_DATA_REG_CFG6_MASK                (0x40U)
#define RTC_GP_DATA_REG_CFG6_SHIFT               (6U)
/*! CFG6 - CFGn */
#define RTC_GP_DATA_REG_CFG6(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG6_SHIFT)) & RTC_GP_DATA_REG_CFG6_MASK)

#define RTC_GP_DATA_REG_CFG7_MASK                (0x80U)
#define RTC_GP_DATA_REG_CFG7_SHIFT               (7U)
/*! CFG7 - CFGn */
#define RTC_GP_DATA_REG_CFG7(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG7_SHIFT)) & RTC_GP_DATA_REG_CFG7_MASK)

#define RTC_GP_DATA_REG_CFG8_MASK                (0x100U)
#define RTC_GP_DATA_REG_CFG8_SHIFT               (8U)
/*! CFG8 - CFGn */
#define RTC_GP_DATA_REG_CFG8(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG8_SHIFT)) & RTC_GP_DATA_REG_CFG8_MASK)

#define RTC_GP_DATA_REG_CFG9_MASK                (0x200U)
#define RTC_GP_DATA_REG_CFG9_SHIFT               (9U)
/*! CFG9 - CFGn */
#define RTC_GP_DATA_REG_CFG9(x)                  (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG9_SHIFT)) & RTC_GP_DATA_REG_CFG9_MASK)

#define RTC_GP_DATA_REG_CFG10_MASK               (0x400U)
#define RTC_GP_DATA_REG_CFG10_SHIFT              (10U)
/*! CFG10 - CFGn */
#define RTC_GP_DATA_REG_CFG10(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG10_SHIFT)) & RTC_GP_DATA_REG_CFG10_MASK)

#define RTC_GP_DATA_REG_CFG11_MASK               (0x800U)
#define RTC_GP_DATA_REG_CFG11_SHIFT              (11U)
/*! CFG11 - CFGn */
#define RTC_GP_DATA_REG_CFG11(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG11_SHIFT)) & RTC_GP_DATA_REG_CFG11_MASK)

#define RTC_GP_DATA_REG_CFG12_MASK               (0x1000U)
#define RTC_GP_DATA_REG_CFG12_SHIFT              (12U)
/*! CFG12 - CFGn */
#define RTC_GP_DATA_REG_CFG12(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG12_SHIFT)) & RTC_GP_DATA_REG_CFG12_MASK)

#define RTC_GP_DATA_REG_CFG13_MASK               (0x2000U)
#define RTC_GP_DATA_REG_CFG13_SHIFT              (13U)
/*! CFG13 - CFGn */
#define RTC_GP_DATA_REG_CFG13(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG13_SHIFT)) & RTC_GP_DATA_REG_CFG13_MASK)

#define RTC_GP_DATA_REG_CFG14_MASK               (0x4000U)
#define RTC_GP_DATA_REG_CFG14_SHIFT              (14U)
/*! CFG14 - CFGn */
#define RTC_GP_DATA_REG_CFG14(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG14_SHIFT)) & RTC_GP_DATA_REG_CFG14_MASK)

#define RTC_GP_DATA_REG_CFG15_MASK               (0x8000U)
#define RTC_GP_DATA_REG_CFG15_SHIFT              (15U)
/*! CFG15 - CFGn */
#define RTC_GP_DATA_REG_CFG15(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_GP_DATA_REG_CFG15_SHIFT)) & RTC_GP_DATA_REG_CFG15_MASK)
/*! @} */

/*! @name DST_HOUR - Daylight Saving Hour */
/*! @{ */

#define RTC_DST_HOUR_DST_END_HOUR_MASK           (0x1FU)
#define RTC_DST_HOUR_DST_END_HOUR_SHIFT          (0U)
/*! DST_END_HOUR - Daylight Saving Time (DST) Hours End Value */
#define RTC_DST_HOUR_DST_END_HOUR(x)             (((uint16_t)(((uint16_t)(x)) << RTC_DST_HOUR_DST_END_HOUR_SHIFT)) & RTC_DST_HOUR_DST_END_HOUR_MASK)

#define RTC_DST_HOUR_DST_START_HOUR_MASK         (0x1F00U)
#define RTC_DST_HOUR_DST_START_HOUR_SHIFT        (8U)
/*! DST_START_HOUR - Daylight Saving Time (DST) Hours Start Value */
#define RTC_DST_HOUR_DST_START_HOUR(x)           (((uint16_t)(((uint16_t)(x)) << RTC_DST_HOUR_DST_START_HOUR_SHIFT)) & RTC_DST_HOUR_DST_START_HOUR_MASK)
/*! @} */

/*! @name DST_MONTH - Daylight Saving Month */
/*! @{ */

#define RTC_DST_MONTH_DST_END_MONTH_MASK         (0xFU)
#define RTC_DST_MONTH_DST_END_MONTH_SHIFT        (0U)
/*! DST_END_MONTH - Daylight Saving Time (DST) Month End Value */
#define RTC_DST_MONTH_DST_END_MONTH(x)           (((uint16_t)(((uint16_t)(x)) << RTC_DST_MONTH_DST_END_MONTH_SHIFT)) & RTC_DST_MONTH_DST_END_MONTH_MASK)

#define RTC_DST_MONTH_DST_START_MONTH_MASK       (0xF00U)
#define RTC_DST_MONTH_DST_START_MONTH_SHIFT      (8U)
/*! DST_START_MONTH - Daylight Saving Time (DST) Month Start Value */
#define RTC_DST_MONTH_DST_START_MONTH(x)         (((uint16_t)(((uint16_t)(x)) << RTC_DST_MONTH_DST_START_MONTH_SHIFT)) & RTC_DST_MONTH_DST_START_MONTH_MASK)
/*! @} */

/*! @name DST_DAY - Daylight Saving Day */
/*! @{ */

#define RTC_DST_DAY_DST_END_DAY_MASK             (0x1FU)
#define RTC_DST_DAY_DST_END_DAY_SHIFT            (0U)
/*! DST_END_DAY - Daylight Saving Time (DST) Day End Value */
#define RTC_DST_DAY_DST_END_DAY(x)               (((uint16_t)(((uint16_t)(x)) << RTC_DST_DAY_DST_END_DAY_SHIFT)) & RTC_DST_DAY_DST_END_DAY_MASK)

#define RTC_DST_DAY_DST_START_DAY_MASK           (0x1F00U)
#define RTC_DST_DAY_DST_START_DAY_SHIFT          (8U)
/*! DST_START_DAY - Daylight Saving Time (DST) Day Start Value */
#define RTC_DST_DAY_DST_START_DAY(x)             (((uint16_t)(((uint16_t)(x)) << RTC_DST_DAY_DST_START_DAY_SHIFT)) & RTC_DST_DAY_DST_START_DAY_MASK)
/*! @} */

/*! @name COMPEN - Compensation */
/*! @{ */

#define RTC_COMPEN_COMPEN_VAL_MASK               (0xFFFFU)
#define RTC_COMPEN_COMPEN_VAL_SHIFT              (0U)
/*! COMPEN_VAL - Compensation Value */
#define RTC_COMPEN_COMPEN_VAL(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_COMPEN_COMPEN_VAL_SHIFT)) & RTC_COMPEN_COMPEN_VAL_MASK)
/*! @} */

/*! @name TAMPER_QSCR - Tamper Queue Status and Control */
/*! @{ */

#define RTC_TAMPER_QSCR_Q_FULL_MASK              (0x1U)
#define RTC_TAMPER_QSCR_Q_FULL_SHIFT             (0U)
/*! Q_FULL - Q_FULL
 *  0b0..The tamper queue is not full.
 *  0b1..The tamper queue is full.
 */
#define RTC_TAMPER_QSCR_Q_FULL(x)                (((uint16_t)(((uint16_t)(x)) << RTC_TAMPER_QSCR_Q_FULL_SHIFT)) & RTC_TAMPER_QSCR_Q_FULL_MASK)

#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK       (0x2U)
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_SHIFT      (1U)
/*! Q_FULL_INT_EN - Q_FULL_INT_EN
 *  0b0..Queue full interrupt is disabled.
 *  0b1..Queue full interrupt is enabled.
 */
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN(x)         (((uint16_t)(((uint16_t)(x)) << RTC_TAMPER_QSCR_Q_FULL_INT_EN_SHIFT)) & RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK)

#define RTC_TAMPER_QSCR_Q_CLEAR_MASK             (0x4U)
#define RTC_TAMPER_QSCR_Q_CLEAR_SHIFT            (2U)
/*! Q_CLEAR - Q_CLEAR */
#define RTC_TAMPER_QSCR_Q_CLEAR(x)               (((uint16_t)(((uint16_t)(x)) << RTC_TAMPER_QSCR_Q_CLEAR_SHIFT)) & RTC_TAMPER_QSCR_Q_CLEAR_MASK)
/*! @} */

/*! @name TAMPER_SCR - Tamper Status and Control */
/*! @{ */

#define RTC_TAMPER_SCR_TMPR_EN_MASK              (0xFU)
#define RTC_TAMPER_SCR_TMPR_EN_SHIFT             (0U)
/*! TMPR_EN - Tamper Control
 *  0b0000..Tamper Status reporting disabled.
 *  0b0001..Tamper Status reporting enabled.
 */
#define RTC_TAMPER_SCR_TMPR_EN(x)                (((uint16_t)(((uint16_t)(x)) << RTC_TAMPER_SCR_TMPR_EN_SHIFT)) & RTC_TAMPER_SCR_TMPR_EN_MASK)

#define RTC_TAMPER_SCR_TMPR_STS_MASK             (0xF00U)
#define RTC_TAMPER_SCR_TMPR_STS_SHIFT            (8U)
/*! TMPR_STS - Tamper Status
 *  0b0000..No Tamper Detected
 *  0b0001..Tamper Event Detected
 */
#define RTC_TAMPER_SCR_TMPR_STS(x)               (((uint16_t)(((uint16_t)(x)) << RTC_TAMPER_SCR_TMPR_STS_SHIFT)) & RTC_TAMPER_SCR_TMPR_STS_MASK)
/*! @} */

/*! @name FILTER01_CFG - Tamper 01 Filter Configuration */
/*! @{ */

#define RTC_FILTER01_CFG_FIL_DUR1_MASK           (0xFU)
#define RTC_FILTER01_CFG_FIL_DUR1_SHIFT          (0U)
/*! FIL_DUR1 - Tamper Detect Bit 1 Filter Duration
 *  0b0000..Filtering operation disabled.
 *  0b0001-0b1111..Number of tamper filter clock cycles to be counted when tamper is asserted.
 */
#define RTC_FILTER01_CFG_FIL_DUR1(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER01_CFG_FIL_DUR1_SHIFT)) & RTC_FILTER01_CFG_FIL_DUR1_MASK)

#define RTC_FILTER01_CFG_CLK_SEL1_MASK           (0x70U)
#define RTC_FILTER01_CFG_CLK_SEL1_SHIFT          (4U)
/*! CLK_SEL1 - Tamper Filter 1 Clock Select
 *  0b000..32 kHz clock
 *  0b001..512 Hz clock
 *  0b010..128 Hz clock
 *  0b011..64 Hz clock
 *  0b100..16 Hz clock
 *  0b101..8 Hz clock
 *  0b110..4 Hz clock
 *  0b111..2 Hz clock
 */
#define RTC_FILTER01_CFG_CLK_SEL1(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER01_CFG_CLK_SEL1_SHIFT)) & RTC_FILTER01_CFG_CLK_SEL1_MASK)

#define RTC_FILTER01_CFG_POL1_MASK               (0x80U)
#define RTC_FILTER01_CFG_POL1_SHIFT              (7U)
/*! POL1 - Tamper Detect Input Bit 1 Polarity Control
 *  0b0..Tamper detect input bit 1 is active high.
 *  0b1..Tamper detect input bit 1 is active low.
 */
#define RTC_FILTER01_CFG_POL1(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_FILTER01_CFG_POL1_SHIFT)) & RTC_FILTER01_CFG_POL1_MASK)

#define RTC_FILTER01_CFG_FIL_DUR0_MASK           (0xF00U)
#define RTC_FILTER01_CFG_FIL_DUR0_SHIFT          (8U)
/*! FIL_DUR0 - Tamper Detect Bit 0 Filter Duration
 *  0b0000..Filtering operation disabled.
 *  0b0001-0b1111..Number of tamper filter clock cycles to be counted when tamper is asserted.
 */
#define RTC_FILTER01_CFG_FIL_DUR0(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER01_CFG_FIL_DUR0_SHIFT)) & RTC_FILTER01_CFG_FIL_DUR0_MASK)

#define RTC_FILTER01_CFG_CLK_SEL0_MASK           (0x7000U)
#define RTC_FILTER01_CFG_CLK_SEL0_SHIFT          (12U)
/*! CLK_SEL0 - Tamper Filter 0 Clock Select
 *  0b000..32 kHz clock
 *  0b001..512 Hz clock
 *  0b010..128 Hz clock
 *  0b011..64 Hz clock
 *  0b100..16 Hz clock
 *  0b101..8 Hz clock
 *  0b110..4 Hz clock
 *  0b111..2 Hz clock
 */
#define RTC_FILTER01_CFG_CLK_SEL0(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER01_CFG_CLK_SEL0_SHIFT)) & RTC_FILTER01_CFG_CLK_SEL0_MASK)

#define RTC_FILTER01_CFG_POL0_MASK               (0x8000U)
#define RTC_FILTER01_CFG_POL0_SHIFT              (15U)
/*! POL0 - Tamper Detect Input Bit 0 Polarity Control
 *  0b0..Tamper detect input bit 0 is active high.
 *  0b1..Tamper detect input bit 0 is active low.
 */
#define RTC_FILTER01_CFG_POL0(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_FILTER01_CFG_POL0_SHIFT)) & RTC_FILTER01_CFG_POL0_MASK)
/*! @} */

/*! @name FILTER23_CFG - Tamper 23 Filter Configuration */
/*! @{ */

#define RTC_FILTER23_CFG_FIL_DUR3_MASK           (0xFU)
#define RTC_FILTER23_CFG_FIL_DUR3_SHIFT          (0U)
/*! FIL_DUR3 - Tamper Detect Bit 3 Filter Duration
 *  0b0000..Filtering operation disabled.
 *  0b0001-0b1111..Number of tamper filter clock cycles to be counted when tamper is asserted.
 */
#define RTC_FILTER23_CFG_FIL_DUR3(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER23_CFG_FIL_DUR3_SHIFT)) & RTC_FILTER23_CFG_FIL_DUR3_MASK)

#define RTC_FILTER23_CFG_CLK_SEL3_MASK           (0x70U)
#define RTC_FILTER23_CFG_CLK_SEL3_SHIFT          (4U)
/*! CLK_SEL3 - Tamper Filter 3 Clock Select
 *  0b000..32 kHz clock
 *  0b001..512 Hz clock
 *  0b010..128 Hz clock
 *  0b011..64 Hz clock
 *  0b100..16 Hz clock
 *  0b101..8 Hz clock
 *  0b110..4 Hz clock
 *  0b111..2 Hz clock
 */
#define RTC_FILTER23_CFG_CLK_SEL3(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER23_CFG_CLK_SEL3_SHIFT)) & RTC_FILTER23_CFG_CLK_SEL3_MASK)

#define RTC_FILTER23_CFG_POL3_MASK               (0x80U)
#define RTC_FILTER23_CFG_POL3_SHIFT              (7U)
/*! POL3 - Tamper Detect Input Bit 3 Polarity Control
 *  0b0..Tamper detect input bit 3 is active high.
 *  0b1..Tamper detect input bit 3 is active low.
 */
#define RTC_FILTER23_CFG_POL3(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_FILTER23_CFG_POL3_SHIFT)) & RTC_FILTER23_CFG_POL3_MASK)

#define RTC_FILTER23_CFG_FIL_DUR2_MASK           (0xF00U)
#define RTC_FILTER23_CFG_FIL_DUR2_SHIFT          (8U)
/*! FIL_DUR2 - Tamper Detect Bit 2 Filter Duration
 *  0b0000..Filtering operation disabled.
 *  0b0001-0b1111..Number of tamper filter clock cycles to be counted when tamper is asserted.
 */
#define RTC_FILTER23_CFG_FIL_DUR2(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER23_CFG_FIL_DUR2_SHIFT)) & RTC_FILTER23_CFG_FIL_DUR2_MASK)

#define RTC_FILTER23_CFG_CLK_SEL2_MASK           (0x7000U)
#define RTC_FILTER23_CFG_CLK_SEL2_SHIFT          (12U)
/*! CLK_SEL2 - Tamper Filter 2 Clock Select
 *  0b000..32 kHz clock
 *  0b001..512 Hz clock
 *  0b010..128 Hz clock
 *  0b011..64 Hz clock
 *  0b100..16 Hz clock
 *  0b101..8 Hz clock
 *  0b110..4 Hz clock
 *  0b111..2 Hz clock
 */
#define RTC_FILTER23_CFG_CLK_SEL2(x)             (((uint16_t)(((uint16_t)(x)) << RTC_FILTER23_CFG_CLK_SEL2_SHIFT)) & RTC_FILTER23_CFG_CLK_SEL2_MASK)

#define RTC_FILTER23_CFG_POL2_MASK               (0x8000U)
#define RTC_FILTER23_CFG_POL2_SHIFT              (15U)
/*! POL2 - Tamper Detect Input Bit 2 Polarity Control
 *  0b0..Tamper detect input bit 2 is active high.
 *  0b1..Tamper detect input bit 2 is active low.
 */
#define RTC_FILTER23_CFG_POL2(x)                 (((uint16_t)(((uint16_t)(x)) << RTC_FILTER23_CFG_POL2_SHIFT)) & RTC_FILTER23_CFG_POL2_MASK)
/*! @} */

/*! @name TAMPER_QUEUE - Tamper Queue */
/*! @{ */

#define RTC_TAMPER_QUEUE_TAMPER_DATA_MASK        (0xFFFFU)
#define RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT       (0U)
/*! TAMPER_DATA - Tamper type stamp and pin number information register */
#define RTC_TAMPER_QUEUE_TAMPER_DATA(x)          (((uint16_t)(((uint16_t)(x)) << RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT)) & RTC_TAMPER_QUEUE_TAMPER_DATA_MASK)
/*! @} */

/*! @name CTRL2 - Control 2 */
/*! @{ */

#define RTC_CTRL2_TAMP_CFG_OVER_MASK             (0x1U)
#define RTC_CTRL2_TAMP_CFG_OVER_SHIFT            (0U)
/*! TAMP_CFG_OVER - Tamper Configuration Over
 *  0b0..Tamper filter processing disabled.
 *  0b1..Tamper filter processing enabled.
 */
#define RTC_CTRL2_TAMP_CFG_OVER(x)               (((uint16_t)(((uint16_t)(x)) << RTC_CTRL2_TAMP_CFG_OVER_SHIFT)) & RTC_CTRL2_TAMP_CFG_OVER_MASK)
/*! @} */

/*! @name SUBSECOND_CTRL - Sub-second control */
/*! @{ */

#define RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_MASK (0x1U)
#define RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_SHIFT (0U)
/*! SUB_SECOND_CNT_EN - Sub-second counter enable bit
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN(x)  (((uint32_t)(((uint32_t)(x)) << RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_SHIFT)) & RTC_SUBSECOND_CTRL_SUB_SECOND_CNT_EN_MASK)
/*! @} */

/*! @name SUBSECOND_CNT - Sub-second counter */
/*! @{ */

#define RTC_SUBSECOND_CNT_SUBSECOND_CNT_MASK     (0xFFFFU)
#define RTC_SUBSECOND_CNT_SUBSECOND_CNT_SHIFT    (0U)
/*! SUBSECOND_CNT - Current sub-second counter value */
#define RTC_SUBSECOND_CNT_SUBSECOND_CNT(x)       (((uint32_t)(((uint32_t)(x)) << RTC_SUBSECOND_CNT_SUBSECOND_CNT_SHIFT)) & RTC_SUBSECOND_CNT_SUBSECOND_CNT_MASK)
/*! @} */

/*! @name WAKE_TIMER_CTRL - Wake timer control */
/*! @{ */

#define RTC_WAKE_TIMER_CTRL_WAKE_FLAG_MASK       (0x2U)
#define RTC_WAKE_TIMER_CTRL_WAKE_FLAG_SHIFT      (1U)
/*! WAKE_FLAG - Wake timer status flag
 *  0b0..Wake timer has not timed out.
 *  0b1..Wake timer has timed out.
 */
#define RTC_WAKE_TIMER_CTRL_WAKE_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_WAKE_FLAG_SHIFT)) & RTC_WAKE_TIMER_CTRL_WAKE_FLAG_MASK)

#define RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_MASK  (0x4U)
#define RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_SHIFT (2U)
/*! CLR_WAKE_TIMER - Clear wake timer
 *  0b0..No effect.
 *  0b1..Clears the wake counter and halt operation until a new count value is loaded.
 */
#define RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER(x)    (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_SHIFT)) & RTC_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_MASK)

#define RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_MASK     (0x10U)
#define RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_SHIFT    (4U)
/*! OSC_DIV_ENA - Enable the 5-bit clock divider to divide down the 32Khz input clock to generate
 *    the 1Khz clock source for the wake timer.
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA(x)       (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_SHIFT)) & RTC_WAKE_TIMER_CTRL_OSC_DIV_ENA_MASK)

#define RTC_WAKE_TIMER_CTRL_INTR_EN_MASK         (0x20U)
#define RTC_WAKE_TIMER_CTRL_INTR_EN_SHIFT        (5U)
/*! INTR_EN - Enable interrupt when WAKE_FLAG is set.
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define RTC_WAKE_TIMER_CTRL_INTR_EN(x)           (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CTRL_INTR_EN_SHIFT)) & RTC_WAKE_TIMER_CTRL_INTR_EN_MASK)
/*! @} */

/*! @name WAKE_TIMER_CNT - Wake timer counter */
/*! @{ */

#define RTC_WAKE_TIMER_CNT_WAKE_CNT_MASK         (0xFFFFFFFFU)
#define RTC_WAKE_TIMER_CNT_WAKE_CNT_SHIFT        (0U)
/*! WAKE_CNT - Wake counter */
#define RTC_WAKE_TIMER_CNT_WAKE_CNT(x)           (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_TIMER_CNT_WAKE_CNT_SHIFT)) & RTC_WAKE_TIMER_CNT_WAKE_CNT_MASK)
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

