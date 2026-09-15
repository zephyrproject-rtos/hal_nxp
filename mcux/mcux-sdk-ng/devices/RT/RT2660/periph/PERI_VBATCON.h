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
**         CMSIS Peripheral Access Layer for VBATCON
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
 * @file PERI_VBATCON.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for VBATCON
 *
 * CMSIS Peripheral Access Layer for VBATCON
 */

#if !defined(PERI_VBATCON_H_)
#define PERI_VBATCON_H_                          /**< Symbol preventing repeated inclusion */

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
   -- VBATCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBATCON_Peripheral_Access_Layer VBATCON Peripheral Access Layer
 * @{
 */

/** VBATCON - Size of Registers Arrays */
#define VBATCON_GPR_COUNT                         2u

/** VBATCON - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t FEATURES;                          /**< Features, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< Control, offset: 0x8 */
       uint8_t RESERVED_0[8];
  __IO uint32_t EVENTS;                            /**< Events, offset: 0x14 */
       uint8_t RESERVED_1[76];
  __IO uint32_t CLOCK_CTRL;                        /**< Clock Control, offset: 0x64 */
       uint8_t RESERVED_2[664];
  __IO uint32_t GPR[VBATCON_GPR_COUNT];            /**< General Purpose Register, array offset: 0x300, array step: 0x4 */
} VBATCON_Type;

/* ----------------------------------------------------------------------------
   -- VBATCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBATCON_Register_Masks VBATCON Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define VBATCON_VERID_IPID_MASK                  (0xFFU)
#define VBATCON_VERID_IPID_SHIFT                 (0U)
/*! IPID - IP ID */
#define VBATCON_VERID_IPID(x)                    (((uint32_t)(((uint32_t)(x)) << VBATCON_VERID_IPID_SHIFT)) & VBATCON_VERID_IPID_MASK)

#define VBATCON_VERID_REVISION_MASK              (0xFF00U)
#define VBATCON_VERID_REVISION_SHIFT             (8U)
/*! REVISION - Revision */
#define VBATCON_VERID_REVISION(x)                (((uint32_t)(((uint32_t)(x)) << VBATCON_VERID_REVISION_SHIFT)) & VBATCON_VERID_REVISION_MASK)

#define VBATCON_VERID_VERSION_MASK               (0xFF0000U)
#define VBATCON_VERID_VERSION_SHIFT              (16U)
/*! VERSION - Version ID */
#define VBATCON_VERID_VERSION(x)                 (((uint32_t)(((uint32_t)(x)) << VBATCON_VERID_VERSION_SHIFT)) & VBATCON_VERID_VERSION_MASK)
/*! @} */

/*! @name FEATURES - Features */
/*! @{ */

#define VBATCON_FEATURES_GPR_SZ_MASK             (0xFCU)
#define VBATCON_FEATURES_GPR_SZ_SHIFT            (2U)
/*! GPR_SZ - General-Purpose Register Array Size */
#define VBATCON_FEATURES_GPR_SZ(x)               (((uint32_t)(((uint32_t)(x)) << VBATCON_FEATURES_GPR_SZ_SHIFT)) & VBATCON_FEATURES_GPR_SZ_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define VBATCON_CTRL_BTN_TIMEOUT_MASK            (0x30000U)
#define VBATCON_CTRL_BTN_TIMEOUT_SHIFT           (16U)
/*! BTN_TIMEOUT - Button Press Timeout
 *  0b00..5
 *  0b01..10
 *  0b10..15
 *  0b11..Timeout disabled. Long button presses will not trigger a power-down request.
 */
#define VBATCON_CTRL_BTN_TIMEOUT(x)              (((uint32_t)(((uint32_t)(x)) << VBATCON_CTRL_BTN_TIMEOUT_SHIFT)) & VBATCON_CTRL_BTN_TIMEOUT_MASK)

#define VBATCON_CTRL_DEBOUNCE_MASK               (0xC0000U)
#define VBATCON_CTRL_DEBOUNCE_SHIFT              (18U)
/*! DEBOUNCE - Debounce Time
 *  0b00..50
 *  0b01..100
 *  0b10..500
 *  0b11..0
 */
#define VBATCON_CTRL_DEBOUNCE(x)                 (((uint32_t)(((uint32_t)(x)) << VBATCON_CTRL_DEBOUNCE_SHIFT)) & VBATCON_CTRL_DEBOUNCE_MASK)

#define VBATCON_CTRL_TURN_ON_TIME_MASK           (0x300000U)
#define VBATCON_CTRL_TURN_ON_TIME_SHIFT          (20U)
/*! TURN_ON_TIME - Turn-On Time
 *  0b00..500
 *  0b01..50
 *  0b10..100
 *  0b11..0 (It needs to ensure already in DPD (deep_power_down) mode at this time, and the pressing time must be
 *        greater than 50 microseconds (one and a half 32k clock cycles))
 */
#define VBATCON_CTRL_TURN_ON_TIME(x)             (((uint32_t)(((uint32_t)(x)) << VBATCON_CTRL_TURN_ON_TIME_SHIFT)) & VBATCON_CTRL_TURN_ON_TIME_MASK)

#define VBATCON_CTRL_LONG_PRESS_EN_MASK          (0x1000000U)
#define VBATCON_CTRL_LONG_PRESS_EN_SHIFT         (24U)
/*! LONG_PRESS_EN - Long Press Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VBATCON_CTRL_LONG_PRESS_EN(x)            (((uint32_t)(((uint32_t)(x)) << VBATCON_CTRL_LONG_PRESS_EN_SHIFT)) & VBATCON_CTRL_LONG_PRESS_EN_MASK)

#define VBATCON_CTRL_TOSP_MASK                   (0x2000000U)
#define VBATCON_CTRL_TOSP_SHIFT                  (25U)
/*! TOSP - Turn Off System Power
 *  0b0..Leaves the system power on.
 *  0b1..Turns off the system power.
 */
#define VBATCON_CTRL_TOSP(x)                     (((uint32_t)(((uint32_t)(x)) << VBATCON_CTRL_TOSP_SHIFT)) & VBATCON_CTRL_TOSP_MASK)

#define VBATCON_CTRL_AEC_MASK                    (0x4000000U)
#define VBATCON_CTRL_AEC_SHIFT                   (26U)
/*! AEC - Abnormal Entry Check
 *  0b0..Disables
 *  0b1..Enables
 */
#define VBATCON_CTRL_AEC(x)                      (((uint32_t)(((uint32_t)(x)) << VBATCON_CTRL_AEC_SHIFT)) & VBATCON_CTRL_AEC_MASK)

#define VBATCON_CTRL_NAT_MASK                    (0x8000000U)
#define VBATCON_CTRL_NAT_SHIFT                   (27U)
/*! NAT - No ACK Time
 *  0b0..1000
 *  0b1..500
 */
#define VBATCON_CTRL_NAT(x)                      (((uint32_t)(((uint32_t)(x)) << VBATCON_CTRL_NAT_SHIFT)) & VBATCON_CTRL_NAT_MASK)
/*! @} */

/*! @name EVENTS - Events */
/*! @{ */

#define VBATCON_EVENTS_EMG_OFF_MASK              (0x10U)
#define VBATCON_EVENTS_EMG_OFF_SHIFT             (4U)
/*! EMG_OFF - Emergency Power Off
 *  0b0..An emergency power-off has not been requested.
 *  0b1..An emergency power-off has been requested.
 */
#define VBATCON_EVENTS_EMG_OFF(x)                (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_EMG_OFF_SHIFT)) & VBATCON_EVENTS_EMG_OFF_MASK)

#define VBATCON_EVENTS_PWR_OFF_MASK              (0x20U)
#define VBATCON_EVENTS_PWR_OFF_SHIFT             (5U)
/*! PWR_OFF - Set Power Off Event
 *  0b0..The power-off interrupt has not been requested.
 *  0b1..The power-off interrupt has been requested.
 */
#define VBATCON_EVENTS_PWR_OFF(x)                (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_PWR_OFF_SHIFT)) & VBATCON_EVENTS_PWR_OFF_MASK)

#define VBATCON_EVENTS_PWR_ON_MASK               (0x40U)
#define VBATCON_EVENTS_PWR_ON_SHIFT              (6U)
/*! PWR_ON - Set Power On Event
 *  0b0..The power-on interrupt has not been requested.
 *  0b1..The power-on interrupt has been requested.
 */
#define VBATCON_EVENTS_PWR_ON(x)                 (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_PWR_ON_SHIFT)) & VBATCON_EVENTS_PWR_ON_MASK)

#define VBATCON_EVENTS_OSC_ERROR_MASK            (0x80U)
#define VBATCON_EVENTS_OSC_ERROR_SHIFT           (7U)
/*! OSC_ERROR - Set OSC32K Error Event
 *  0b0..The OSC error interrupt has not been requested.
 *  0b1..The OSC error interrupt has been requested.
 */
#define VBATCON_EVENTS_OSC_ERROR(x)              (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_OSC_ERROR_SHIFT)) & VBATCON_EVENTS_OSC_ERROR_MASK)

#define VBATCON_EVENTS_EMG_OFF_EN_MASK           (0x100000U)
#define VBATCON_EVENTS_EMG_OFF_EN_SHIFT          (20U)
/*! EMG_OFF_EN
 *  0b0..Disables
 *  0b1..Enables
 */
#define VBATCON_EVENTS_EMG_OFF_EN(x)             (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_EMG_OFF_EN_SHIFT)) & VBATCON_EVENTS_EMG_OFF_EN_MASK)

#define VBATCON_EVENTS_PWR_OFF_EN_MASK           (0x200000U)
#define VBATCON_EVENTS_PWR_OFF_EN_SHIFT          (21U)
/*! PWR_OFF_EN
 *  0b0..Disables
 *  0b1..Enables
 */
#define VBATCON_EVENTS_PWR_OFF_EN(x)             (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_PWR_OFF_EN_SHIFT)) & VBATCON_EVENTS_PWR_OFF_EN_MASK)

#define VBATCON_EVENTS_PWR_ON_EN_MASK            (0x400000U)
#define VBATCON_EVENTS_PWR_ON_EN_SHIFT           (22U)
/*! PWR_ON_EN
 *  0b0..Disables
 *  0b1..Enables
 */
#define VBATCON_EVENTS_PWR_ON_EN(x)              (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_PWR_ON_EN_SHIFT)) & VBATCON_EVENTS_PWR_ON_EN_MASK)

#define VBATCON_EVENTS_OSC_ERROR_EN_MASK         (0x800000U)
#define VBATCON_EVENTS_OSC_ERROR_EN_SHIFT        (23U)
/*! OSC_ERROR_EN
 *  0b0..Disables
 *  0b1..Enables
 */
#define VBATCON_EVENTS_OSC_ERROR_EN(x)           (((uint32_t)(((uint32_t)(x)) << VBATCON_EVENTS_OSC_ERROR_EN_SHIFT)) & VBATCON_EVENTS_OSC_ERROR_EN_MASK)
/*! @} */

/*! @name CLOCK_CTRL - Clock Control */
/*! @{ */

#define VBATCON_CLOCK_CTRL_BBSM_CG_EN_MASK       (0x4U)
#define VBATCON_CLOCK_CTRL_BBSM_CG_EN_SHIFT      (2U)
/*! BBSM_CG_EN - BBSM Clock Gate Enable
 *  0b0..Disables Clock Gate
 *  0b1..Enable Clock Gate
 */
#define VBATCON_CLOCK_CTRL_BBSM_CG_EN(x)         (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_BBSM_CG_EN_SHIFT)) & VBATCON_CLOCK_CTRL_BBSM_CG_EN_MASK)

#define VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN_MASK (0x8U)
#define VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN_SHIFT (3U)
/*! VBAT_LPTMR_CG_EN - VBAT_LPTIMER Clock Gate Enable
 *  0b0..Disables Clock Gate
 *  0b1..Enable Clock Gate
 */
#define VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN(x)   (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN_SHIFT)) & VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN_MASK)

#define VBATCON_CLOCK_CTRL_SW_SEL_EN_MASK        (0x100U)
#define VBATCON_CLOCK_CTRL_SW_SEL_EN_SHIFT       (8U)
/*! SW_SEL_EN - ULP32K Switch Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VBATCON_CLOCK_CTRL_SW_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_SW_SEL_EN_SHIFT)) & VBATCON_CLOCK_CTRL_SW_SEL_EN_MASK)

#define VBATCON_CLOCK_CTRL_SW_SEL_MASK           (0x200U)
#define VBATCON_CLOCK_CTRL_SW_SEL_SHIFT          (9U)
/*! SW_SEL - ULP32K Switch Configuration
 *  0b0..FRO32K is selected as clock source.
 *  0b1..OSC32K is selected as clock source.
 */
#define VBATCON_CLOCK_CTRL_SW_SEL(x)             (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_SW_SEL_SHIFT)) & VBATCON_CLOCK_CTRL_SW_SEL_MASK)

#define VBATCON_CLOCK_CTRL_OSC_RDY_MASK          (0x10000U)
#define VBATCON_CLOCK_CTRL_OSC_RDY_SHIFT         (16U)
/*! OSC_RDY - OSC32K Ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define VBATCON_CLOCK_CTRL_OSC_RDY(x)            (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_OSC_RDY_SHIFT)) & VBATCON_CLOCK_CTRL_OSC_RDY_MASK)

#define VBATCON_CLOCK_CTRL_FRO_RDY_MASK          (0x20000U)
#define VBATCON_CLOCK_CTRL_FRO_RDY_SHIFT         (17U)
/*! FRO_RDY - FRO32K Ready
 *  0b0..Not Ready
 *  0b1..Ready
 */
#define VBATCON_CLOCK_CTRL_FRO_RDY(x)            (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_FRO_RDY_SHIFT)) & VBATCON_CLOCK_CTRL_FRO_RDY_MASK)

#define VBATCON_CLOCK_CTRL_OSS_MASK              (0x1000000U)
#define VBATCON_CLOCK_CTRL_OSS_SHIFT             (24U)
/*! OSS - OSC32K SCXO Stable
 *  0b0..Unstable
 *  0b1..Stable
 */
#define VBATCON_CLOCK_CTRL_OSS(x)                (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_OSS_SHIFT)) & VBATCON_CLOCK_CTRL_OSS_MASK)

#define VBATCON_CLOCK_CTRL_OTS_MASK              (0x2000000U)
#define VBATCON_CLOCK_CTRL_OTS_SHIFT             (25U)
/*! OTS - OSC32K TCXO Stable
 *  0b0..Unstable
 *  0b1..Stable
 */
#define VBATCON_CLOCK_CTRL_OTS(x)                (((uint32_t)(((uint32_t)(x)) << VBATCON_CLOCK_CTRL_OTS_SHIFT)) & VBATCON_CLOCK_CTRL_OTS_MASK)
/*! @} */

/*! @name GPR - General Purpose Register */
/*! @{ */

#define VBATCON_GPR_GPR_MASK                     (0xFFFFFFFFU)
#define VBATCON_GPR_GPR_SHIFT                    (0U)
/*! GPR - 32 bits of the GPR. */
#define VBATCON_GPR_GPR(x)                       (((uint32_t)(((uint32_t)(x)) << VBATCON_GPR_GPR_SHIFT)) & VBATCON_GPR_GPR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VBATCON_Register_Masks */


/*!
 * @}
 */ /* end of group VBATCON_Peripheral_Access_Layer */


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


#endif  /* PERI_VBATCON_H_ */

