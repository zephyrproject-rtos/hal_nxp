/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RTC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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
  __IO uint32_t CTRL;                              /**< RTC Control, offset: 0x0 */
  __IO uint32_t MATCH;                             /**< RTC Match, offset: 0x4 */
  __IO uint32_t COUNT;                             /**< RTC Counter, offset: 0x8 */
  __IO uint32_t WAKE;                              /**< High-resolution/Wake-up Timer Control, offset: 0xC */
  __I  uint32_t SUBSEC;                            /**< RTC Sub-second Counter, offset: 0x10 */
       uint8_t RESERVED_0[44];
  __IO uint32_t GPREG[RTC_GPREG_COUNT];            /**< General Purpose, array offset: 0x40, array step: 0x4 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name CTRL - RTC Control */
/*! @{ */

#define RTC_CTRL_SWRESET_MASK                    (0x1U)
#define RTC_CTRL_SWRESET_SHIFT                   (0U)
/*! SWRESET - Software Reset Control
 *  0b0..Not in reset. The RTC is not held in reset. Clear SWRESET before configuring or initiating any operation of the RTC.
 *  0b1..In reset
 */
#define RTC_CTRL_SWRESET(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_SWRESET_SHIFT)) & RTC_CTRL_SWRESET_MASK)

#define RTC_CTRL_ALARM1HZ_MASK                   (0x4U)
#define RTC_CTRL_ALARM1HZ_SHIFT                  (2U)
/*! ALARM1HZ - RTC 1 Hz Timer Alarm Flag Status
 *  0b0..No match. No match condition has occurred on the 1 Hz RTC timer. Writing a 0 has no effect.
 *  0b1..Match
 */
#define RTC_CTRL_ALARM1HZ(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_ALARM1HZ_SHIFT)) & RTC_CTRL_ALARM1HZ_MASK)

#define RTC_CTRL_WAKE1KHZ_MASK                   (0x8U)
#define RTC_CTRL_WAKE1KHZ_SHIFT                  (3U)
/*! WAKE1KHZ - RTC 1 kHz Timer Wake-up Flag Status
 *  0b0..Run. The RTC 1 kHz timer is running. Writing a 0 has no effect.
 *  0b1..Time-out. The 1 kHz high-resolution/wake-up timer has timed out. This flag generates an RTC wake-up
 *       interrupt request RTC-WAKE which can also wake up the device from any low power mode. Write 1 to clear.
 */
#define RTC_CTRL_WAKE1KHZ(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_WAKE1KHZ_SHIFT)) & RTC_CTRL_WAKE1KHZ_MASK)

#define RTC_CTRL_ALARMDPD_EN_MASK                (0x10U)
#define RTC_CTRL_ALARMDPD_EN_SHIFT               (4U)
/*! ALARMDPD_EN - RTC 1 Hz Timer Alarm Enable for Deep Power-down
 *  0b0..Disable. A match on the 1 Hz RTC timer does not bring the device out of Deep Power-down mode.
 *  0b1..Enable. A match on the 1 Hz RTC timer brings the device out of Deep Power-down mode.
 */
#define RTC_CTRL_ALARMDPD_EN(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_ALARMDPD_EN_SHIFT)) & RTC_CTRL_ALARMDPD_EN_MASK)

#define RTC_CTRL_WAKEDPD_EN_MASK                 (0x20U)
#define RTC_CTRL_WAKEDPD_EN_SHIFT                (5U)
/*! WAKEDPD_EN - RTC 1 kHz Timer Wake-up Enable for Deep Power-down
 *  0b0..Disable. A match on the 1 kHz RTC timer does not bring the device out of Deep Power-down mode.
 *  0b1..Enable. A match on the 1 kHz RTC timer brings the device out of Deep Power-down mode.
 */
#define RTC_CTRL_WAKEDPD_EN(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_WAKEDPD_EN_SHIFT)) & RTC_CTRL_WAKEDPD_EN_MASK)

#define RTC_CTRL_RTC1KHZ_EN_MASK                 (0x40U)
#define RTC_CTRL_RTC1KHZ_EN_SHIFT                (6U)
/*! RTC1KHZ_EN - RTC 1 kHz Clock Enable
 *  0b0..Disable. A match on the 1 kHz RTC timer does not bring the device out of Deep Power-down mode.
 *  0b1..Enable. The 1 kHz RTC timer is enabled.
 */
#define RTC_CTRL_RTC1KHZ_EN(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC1KHZ_EN_SHIFT)) & RTC_CTRL_RTC1KHZ_EN_MASK)

#define RTC_CTRL_RTC_EN_MASK                     (0x80U)
#define RTC_CTRL_RTC_EN_SHIFT                    (7U)
/*! RTC_EN - RTC enable
 *  0b0..Disable. The RTC 1 Hz and 1 kHz clocks are shut down and the RTC operation is disabled. RTC_EN should be
 *       0 when writing to load a value in the RTC counter (COUNT) register .
 *  0b1..Enable. The 1 Hz RTC clock is running and RTC operation is enabled. The first clock to the RTC counter
 *       occurs 1 s after RTC_EN is set. To also enable the high-resolution, 1 kHz clock, set CTRL[RTC1KHZ_EN] = 1.
 */
#define RTC_CTRL_RTC_EN(x)                       (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC_EN_SHIFT)) & RTC_CTRL_RTC_EN_MASK)

#define RTC_CTRL_RTC_OSC_PD_MASK                 (0x100U)
#define RTC_CTRL_RTC_OSC_PD_SHIFT                (8U)
/*! RTC_OSC_PD - The RTC Oscillator Enable
 *  0b0..Enable. The RTC oscillator is enabled. RTC_OSC_PD must be cleared for the RTC module to function.
 *  0b1..Shut Off. The RTC operation is disabled. The RTC oscillator is shut-off to limit power consumption.
 */
#define RTC_CTRL_RTC_OSC_PD(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC_OSC_PD_SHIFT)) & RTC_CTRL_RTC_OSC_PD_MASK)

#define RTC_CTRL_RTC_SUBSEC_ENA_MASK             (0x400U)
#define RTC_CTRL_RTC_SUBSEC_ENA_SHIFT            (10U)
/*! RTC_SUBSEC_ENA - 32-KHz Sub-second Counter Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTC_CTRL_RTC_SUBSEC_ENA(x)               (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC_SUBSEC_ENA_SHIFT)) & RTC_CTRL_RTC_SUBSEC_ENA_MASK)

#define RTC_CTRL_RTC_OSC_loadcap_MASK            (0xF0000000U)
#define RTC_CTRL_RTC_OSC_loadcap_SHIFT           (28U)
/*! RTC_OSC_loadcap - Capacitive Load Selection */
#define RTC_CTRL_RTC_OSC_loadcap(x)              (((uint32_t)(((uint32_t)(x)) << RTC_CTRL_RTC_OSC_loadcap_SHIFT)) & RTC_CTRL_RTC_OSC_loadcap_MASK)
/*! @} */

/*! @name MATCH - RTC Match */
/*! @{ */

#define RTC_MATCH_MATVAL_MASK                    (0xFFFFFFFFU)
#define RTC_MATCH_MATVAL_SHIFT                   (0U)
/*! MATVAL - Match Value */
#define RTC_MATCH_MATVAL(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_MATCH_MATVAL_SHIFT)) & RTC_MATCH_MATVAL_MASK)
/*! @} */

/*! @name COUNT - RTC Counter */
/*! @{ */

#define RTC_COUNT_VAL_MASK                       (0xFFFFFFFFU)
#define RTC_COUNT_VAL_SHIFT                      (0U)
/*! VAL - Value */
#define RTC_COUNT_VAL(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_COUNT_VAL_SHIFT)) & RTC_COUNT_VAL_MASK)
/*! @} */

/*! @name WAKE - High-resolution/Wake-up Timer Control */
/*! @{ */

#define RTC_WAKE_VAL_MASK                        (0xFFFFU)
#define RTC_WAKE_VAL_SHIFT                       (0U)
/*! VAL - Value */
#define RTC_WAKE_VAL(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAKE_VAL_SHIFT)) & RTC_WAKE_VAL_MASK)
/*! @} */

/*! @name SUBSEC - RTC Sub-second Counter */
/*! @{ */

#define RTC_SUBSEC_RTC_SUBSEC_MASK               (0x7FFFU)
#define RTC_SUBSEC_RTC_SUBSEC_SHIFT              (0U)
/*! RTC_SUBSEC - RTC Sub-second Counter */
#define RTC_SUBSEC_RTC_SUBSEC(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_SUBSEC_RTC_SUBSEC_SHIFT)) & RTC_SUBSEC_RTC_SUBSEC_MASK)
/*! @} */

/*! @name GPREG - General Purpose */
/*! @{ */

#define RTC_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)
#define RTC_GPREG_GPDATA_SHIFT                   (0U)
/*! GPDATA - General Purpose Data */
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_RTC_H_ */

