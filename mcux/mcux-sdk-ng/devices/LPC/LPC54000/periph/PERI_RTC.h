/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
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

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
#define RTC_GPREG_COUNT                           8u

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< RTC control register, offset: 0x0 */
  __IO uint32_t MATCH;                             /**< RTC match register, offset: 0x4 */
  __IO uint32_t COUNT;                             /**< RTC counter register, offset: 0x8 */
  __IO uint32_t WAKE;                              /**< High-resolution/wake-up timer control register, offset: 0xC */
       uint8_t RESERVED_0[48];
  __IO uint32_t GPREG[RTC_GPREG_COUNT];            /**< General Purpose register, array offset: 0x40, array step: 0x4 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name CTRL - RTC control register */
/*! @{ */

#define RTC_CTRL_SWRESET_MASK                    (0x1U)
#define RTC_CTRL_SWRESET_SHIFT                   (0U)
/*! SWRESET - Software reset control
 *  0b0..Not in reset. The RTC is not held in reset. This bit must be cleared prior to configuring or initiating any operation of the RTC.
 *  0b1..In reset. The RTC is held in reset. All register bits within the RTC will be forced to their reset value
 *       except the OFD bit. This bit must be cleared before writing to any register in the RTC - including writes
 *       to set any of the other bits within this register. Do not attempt to write to any bits of this register at
 *       the same time that the reset bit is being cleared.
 */
#define RTC_CTRL_SWRESET(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_SWRESET_SHIFT)) & RTC_CTRL_SWRESET_MASK)

#define RTC_CTRL_ALARM1HZ_MASK                   (0x4U)
#define RTC_CTRL_ALARM1HZ_SHIFT                  (2U)
/*! ALARM1HZ - RTC 1 Hz timer alarm flag status.
 *  0b0..No match. No match has occurred on the 1 Hz RTC timer. Writing a 0 has no effect.
 *  0b1..Match. A match condition has occurred on the 1 Hz RTC timer. This flag generates an RTC alarm interrupt
 *       request RTC_ALARM which can also wake up the part from any low power mode. Writing a 1 clears this bit.
 */
#define RTC_CTRL_ALARM1HZ(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_ALARM1HZ_SHIFT)) & RTC_CTRL_ALARM1HZ_MASK)

#define RTC_CTRL_WAKE1KHZ_MASK                   (0x8U)
#define RTC_CTRL_WAKE1KHZ_SHIFT                  (3U)
/*! WAKE1KHZ - RTC 1 kHz timer wake-up flag status.
 *  0b0..Run. The RTC 1 kHz timer is running. Writing a 0 has no effect.
 *  0b1..Time-out. The 1 kHz high-resolution/wake-up timer has timed out. This flag generates an RTC wake-up
 *       interrupt request RTC-WAKE which can also wake up the part from any low power mode. Writing a 1 clears this bit.
 */
#define RTC_CTRL_WAKE1KHZ(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_WAKE1KHZ_SHIFT)) & RTC_CTRL_WAKE1KHZ_MASK)

#define RTC_CTRL_ALARMDPD_EN_MASK                (0x10U)
#define RTC_CTRL_ALARMDPD_EN_SHIFT               (4U)
/*! ALARMDPD_EN - RTC 1 Hz timer alarm enable for Deep power-down.
 *  0b0..Disable. A match on the 1 Hz RTC timer will not bring the part out of Deep power-down mode.
 *  0b1..Enable. A match on the 1 Hz RTC timer bring the part out of Deep power-down mode.
 */
#define RTC_CTRL_ALARMDPD_EN(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_ALARMDPD_EN_SHIFT)) & RTC_CTRL_ALARMDPD_EN_MASK)

#define RTC_CTRL_WAKEDPD_EN_MASK                 (0x20U)
#define RTC_CTRL_WAKEDPD_EN_SHIFT                (5U)
/*! WAKEDPD_EN - RTC 1 kHz timer wake-up enable for Deep power-down.
 *  0b0..Disable. A match on the 1 kHz RTC timer will not bring the part out of Deep power-down mode.
 *  0b1..Enable. A match on the 1 kHz RTC timer bring the part out of Deep power-down mode.
 */
#define RTC_CTRL_WAKEDPD_EN(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_WAKEDPD_EN_SHIFT)) & RTC_CTRL_WAKEDPD_EN_MASK)

#define RTC_CTRL_RTC1KHZ_EN_MASK                 (0x40U)
#define RTC_CTRL_RTC1KHZ_EN_SHIFT                (6U)
/*! RTC1KHZ_EN - RTC 1 kHz clock enable. This bit can be set to 0 to conserve power if the 1 kHz
 *    timer is not used. This bit has no effect when the RTC is disabled (bit 7 of this register is 0).
 *  0b0..Disable. A match on the 1 kHz RTC timer will not bring the part out of Deep power-down mode.
 *  0b1..Enable. The 1 kHz RTC timer is enabled.
 */
#define RTC_CTRL_RTC1KHZ_EN(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC1KHZ_EN_SHIFT)) & RTC_CTRL_RTC1KHZ_EN_MASK)

#define RTC_CTRL_RTC_EN_MASK                     (0x80U)
#define RTC_CTRL_RTC_EN_SHIFT                    (7U)
/*! RTC_EN - RTC enable.
 *  0b0..Disable. The RTC 1 Hz and 1 kHz clocks are shut down and the RTC operation is disabled. This bit should
 *       be 0 when writing to load a value in the RTC counter register.
 *  0b1..Enable. The 1 Hz RTC clock is running and RTC operation is enabled. This bit must be set to initiate
 *       operation of the RTC. The first clock to the RTC counter occurs 1 s after this bit is set. To also enable the
 *       high-resolution, 1 kHz clock, set bit 6 in this register.
 */
#define RTC_CTRL_RTC_EN(x)                       (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC_EN_SHIFT)) & RTC_CTRL_RTC_EN_MASK)

#define RTC_CTRL_RTC_OSC_PD_MASK                 (0x100U)
#define RTC_CTRL_RTC_OSC_PD_SHIFT                (8U)
/*! RTC_OSC_PD - RTC oscillator power-down control.
 *  0b0..See RTC_OSC_BYPASS
 *  0b1..RTC oscillator is powered-down.
 */
#define RTC_CTRL_RTC_OSC_PD(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC_OSC_PD_SHIFT)) & RTC_CTRL_RTC_OSC_PD_MASK)
/*! @} */

/*! @name MATCH - RTC match register */
/*! @{ */

#define RTC_MATCH_MATVAL_MASK                    (0xFFFFFFFFU)
#define RTC_MATCH_MATVAL_SHIFT                   (0U)
/*! MATVAL - Contains the match value against which the 1 Hz RTC timer will be compared to set the
 *    alarm flag RTC_ALARM and generate an alarm interrupt/wake-up if enabled.
 */
#define RTC_MATCH_MATVAL(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_MATCH_MATVAL_SHIFT)) & RTC_MATCH_MATVAL_MASK)
/*! @} */

/*! @name COUNT - RTC counter register */
/*! @{ */

#define RTC_COUNT_VAL_MASK                       (0xFFFFFFFFU)
#define RTC_COUNT_VAL_SHIFT                      (0U)
/*! VAL - A read reflects the current value of the main, 1 Hz RTC timer. A write loads a new initial
 *    value into the timer. The RTC counter will count up continuously at a 1 Hz rate once the RTC
 *    Software Reset is removed (by clearing bit 0 of the CTRL register). Only write to this
 *    register when the RTC_EN bit in the RTC CTRL Register is 0. The counter increments one second after
 *    the RTC_EN bit is set.
 */
#define RTC_COUNT_VAL(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_COUNT_VAL_SHIFT)) & RTC_COUNT_VAL_MASK)
/*! @} */

/*! @name WAKE - High-resolution/wake-up timer control register */
/*! @{ */

#define RTC_WAKE_VAL_MASK                        (0xFFFFU)
#define RTC_WAKE_VAL_SHIFT                       (0U)
/*! VAL - A read reflects the current value of the high-resolution/wake-up timer. A write pre-loads
 *    a start count value into the wake-up timer and initializes a count-down sequence. Do not write
 *    to this register while counting is in progress.
 */
#define RTC_WAKE_VAL(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_VAL_SHIFT)) & RTC_WAKE_VAL_MASK)
/*! @} */

/*! @name GPREG - General Purpose register */
/*! @{ */

#define RTC_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)
#define RTC_GPREG_GPDATA_SHIFT                   (0U)
/*! GPDATA - Data retained during Deep power-down mode or loss of main power as long as VBAT is supplied. */
#define RTC_GPREG_GPDATA(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_GPREG_GPDATA_SHIFT)) & RTC_GPREG_GPDATA_MASK)
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

