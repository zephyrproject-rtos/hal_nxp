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
**         CMSIS Peripheral Access Layer for ITRC
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
 * @file PERI_ITRC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ITRC
 *
 * CMSIS Peripheral Access Layer for ITRC
 */

#if !defined(PERI_ITRC_H_)
#define PERI_ITRC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- ITRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITRC_Peripheral_Access_Layer ITRC Peripheral Access Layer
 * @{
 */

/** ITRC - Size of Registers Arrays */
#define ITRC_OUTX_SEL_COUNT                       8u
#define ITRC_OUTX_SEL_OUTX_SELY_COUNT             2u

/** ITRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t STATUS;                            /**< ITRC outputs and IN0 to IN15 Status, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t OUT_SEL[ITRC_OUTX_SEL_COUNT][ITRC_OUTX_SEL_OUTX_SELY_COUNT]; /**< Trigger Source IN0 to IN15 selector, array offset: 0x8, array step: index*0x8, index2*0x4 */
       uint8_t RESERVED_1[168];
  __O  uint32_t SW_EVENT0;                         /**< Software event 0, offset: 0xF0 */
  __O  uint32_t SW_EVENT1;                         /**< Software event 1, offset: 0xF4 */
} ITRC_Type;

/* ----------------------------------------------------------------------------
   -- ITRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ITRC_Register_Masks ITRC Register Masks
 * @{
 */

/*! @name STATUS - ITRC outputs and IN0 to IN15 Status */
/*! @{ */

#define ITRC_STATUS_IN0_STATUS_MASK              (0x1U)
#define ITRC_STATUS_IN0_STATUS_SHIFT             (0U)
/*! IN0_STATUS - Digital glitch detector event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN0_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN0_STATUS_SHIFT)) & ITRC_STATUS_IN0_STATUS_MASK)

#define ITRC_STATUS_IN1_STATUS_MASK              (0x2U)
#define ITRC_STATUS_IN1_STATUS_SHIFT             (1U)
/*! IN1_STATUS - Tamper pins logic detected an event.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN1_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN1_STATUS_SHIFT)) & ITRC_STATUS_IN1_STATUS_MASK)

#define ITRC_STATUS_IN2_STATUS_MASK              (0x4U)
#define ITRC_STATUS_IN2_STATUS_SHIFT             (2U)
/*! IN2_STATUS - Code watchdog detected an code execution anomaly.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN2_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN2_STATUS_SHIFT)) & ITRC_STATUS_IN2_STATUS_MASK)

#define ITRC_STATUS_IN3_STATUS_MASK              (0x8U)
#define ITRC_STATUS_IN3_STATUS_SHIFT             (3U)
/*! IN3_STATUS - Low voltage event (BoD) detected on VDD_MAIN rail.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN3_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN3_STATUS_SHIFT)) & ITRC_STATUS_IN3_STATUS_MASK)

#define ITRC_STATUS_IN4_STATUS_MASK              (0x10U)
#define ITRC_STATUS_IN4_STATUS_SHIFT             (4U)
/*! IN4_STATUS - Low voltage event (BoD) detected on VDD_CORE rail.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN4_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN4_STATUS_SHIFT)) & ITRC_STATUS_IN4_STATUS_MASK)

#define ITRC_STATUS_IN5_STATUS_MASK              (0x20U)
#define ITRC_STATUS_IN5_STATUS_SHIFT             (5U)
/*! IN5_STATUS - Watch Dog timer event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN5_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN5_STATUS_SHIFT)) & ITRC_STATUS_IN5_STATUS_MASK)

#define ITRC_STATUS_IN6_STATUS_MASK              (0x40U)
#define ITRC_STATUS_IN6_STATUS_SHIFT             (6U)
/*! IN6_STATUS - Flash ECC mismatch event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN6_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN6_STATUS_SHIFT)) & ITRC_STATUS_IN6_STATUS_MASK)

#define ITRC_STATUS_IN7_STATUS_MASK              (0x80U)
#define ITRC_STATUS_IN7_STATUS_SHIFT             (7U)
/*! IN7_STATUS - AHB secure bus checkers detected illegal access.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN7_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN7_STATUS_SHIFT)) & ITRC_STATUS_IN7_STATUS_MASK)

#define ITRC_STATUS_IN8_STATUS_MASK              (0x100U)
#define ITRC_STATUS_IN8_STATUS_SHIFT             (8U)
/*! IN8_STATUS - ELS error event occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN8_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN8_STATUS_SHIFT)) & ITRC_STATUS_IN8_STATUS_MASK)

#define ITRC_STATUS_IN10_STATUS_MASK             (0x400U)
#define ITRC_STATUS_IN10_STATUS_SHIFT            (10U)
/*! IN10_STATUS - PKC module detected an error event.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN10_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN10_STATUS_SHIFT)) & ITRC_STATUS_IN10_STATUS_MASK)

#define ITRC_STATUS_IN14_STATUS_MASK             (0x4000U)
#define ITRC_STATUS_IN14_STATUS_SHIFT            (14U)
/*! IN14_STATUS - Software event 0 occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN14_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN14_STATUS_SHIFT)) & ITRC_STATUS_IN14_STATUS_MASK)

#define ITRC_STATUS_IN15_STATUS_MASK             (0x8000U)
#define ITRC_STATUS_IN15_STATUS_SHIFT            (15U)
/*! IN15_STATUS - Software event 1 occurred.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_IN15_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_IN15_STATUS_SHIFT)) & ITRC_STATUS_IN15_STATUS_MASK)

#define ITRC_STATUS_OUT0_STATUS_MASK             (0x10000U)
#define ITRC_STATUS_OUT0_STATUS_SHIFT            (16U)
/*! OUT0_STATUS - ITRC triggered ITRC_IRQ output.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT0_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT0_STATUS_SHIFT)) & ITRC_STATUS_OUT0_STATUS_MASK)

#define ITRC_STATUS_OUT1_STATUS_MASK             (0x20000U)
#define ITRC_STATUS_OUT1_STATUS_SHIFT            (17U)
/*! OUT1_STATUS - ITRC triggered ELS_RESET to clear ELS key store.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT1_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT1_STATUS_SHIFT)) & ITRC_STATUS_OUT1_STATUS_MASK)

#define ITRC_STATUS_OUT2_STATUS_MASK             (0x40000U)
#define ITRC_STATUS_OUT2_STATUS_SHIFT            (18U)
/*! OUT2_STATUS - ITRC triggered PUF_ZEROIZE to clear PUF key store and RAM.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT2_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT2_STATUS_SHIFT)) & ITRC_STATUS_OUT2_STATUS_MASK)

#define ITRC_STATUS_OUT3_STATUS_MASK             (0x80000U)
#define ITRC_STATUS_OUT3_STATUS_SHIFT            (19U)
/*! OUT3_STATUS - ITRC triggered RAM_ZEROIZE to clear retention and PKC RAM contents.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT3_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT3_STATUS_SHIFT)) & ITRC_STATUS_OUT3_STATUS_MASK)

#define ITRC_STATUS_OUT4_STATUS_MASK             (0x100000U)
#define ITRC_STATUS_OUT4_STATUS_SHIFT            (20U)
/*! OUT4_STATUS - ITRC triggered CHIP_RESET to reset the chip after all other response process finished.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT4_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT4_STATUS_SHIFT)) & ITRC_STATUS_OUT4_STATUS_MASK)

#define ITRC_STATUS_OUT5_STATUS_MASK             (0x200000U)
#define ITRC_STATUS_OUT5_STATUS_SHIFT            (21U)
/*! OUT5_STATUS - ITRC triggered TMPR_OUT internal signal connected to various on-chip multiplexers.
 *  0b0..Output not triggered.
 *  0b1..Output has been triggered.
 */
#define ITRC_STATUS_OUT5_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << ITRC_STATUS_OUT5_STATUS_SHIFT)) & ITRC_STATUS_OUT5_STATUS_MASK)
/*! @} */

/*! @name OUT_SEL - Trigger Source IN0 to IN15 selector */
/*! @{ */

#define ITRC_OUT_SEL_IN0_SELn_MASK               (0x3U)
#define ITRC_OUT_SEL_IN0_SELn_SHIFT              (0U)
/*! IN0_SELn - Selects digital glitch detector as a trigger source. */
#define ITRC_OUT_SEL_IN0_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN0_SELn_SHIFT)) & ITRC_OUT_SEL_IN0_SELn_MASK)

#define ITRC_OUT_SEL_IN1_SELn_MASK               (0xCU)
#define ITRC_OUT_SEL_IN1_SELn_SHIFT              (2U)
/*! IN1_SELn - Selects TDET event as a trigger source. */
#define ITRC_OUT_SEL_IN1_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN1_SELn_SHIFT)) & ITRC_OUT_SEL_IN1_SELn_MASK)

#define ITRC_OUT_SEL_IN2_SELn_MASK               (0x30U)
#define ITRC_OUT_SEL_IN2_SELn_SHIFT              (4U)
/*! IN2_SELn - Selects Code Watchdog 0 event as a trigger source. */
#define ITRC_OUT_SEL_IN2_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN2_SELn_SHIFT)) & ITRC_OUT_SEL_IN2_SELn_MASK)

#define ITRC_OUT_SEL_IN3_SELn_MASK               (0xC0U)
#define ITRC_OUT_SEL_IN3_SELn_SHIFT              (6U)
/*! IN3_SELn - Selects VDD_MAIN voltage tamper event as a trigger source. */
#define ITRC_OUT_SEL_IN3_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN3_SELn_SHIFT)) & ITRC_OUT_SEL_IN3_SELn_MASK)

#define ITRC_OUT_SEL_IN4_SELn_MASK               (0x300U)
#define ITRC_OUT_SEL_IN4_SELn_SHIFT              (8U)
/*! IN4_SELn - Selects low-voltage event on VDD_CORE rail as a trigger source. */
#define ITRC_OUT_SEL_IN4_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN4_SELn_SHIFT)) & ITRC_OUT_SEL_IN4_SELn_MASK)

#define ITRC_OUT_SEL_IN5_SELn_MASK               (0xC00U)
#define ITRC_OUT_SEL_IN5_SELn_SHIFT              (10U)
/*! IN5_SELn - Selects Watchdog 0 timer event as a trigger source. */
#define ITRC_OUT_SEL_IN5_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN5_SELn_SHIFT)) & ITRC_OUT_SEL_IN5_SELn_MASK)

#define ITRC_OUT_SEL_IN6_SELn_MASK               (0x3000U)
#define ITRC_OUT_SEL_IN6_SELn_SHIFT              (12U)
/*! IN6_SELn - Selects Flash ECC mismatch event as a trigger source. */
#define ITRC_OUT_SEL_IN6_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN6_SELn_SHIFT)) & ITRC_OUT_SEL_IN6_SELn_MASK)

#define ITRC_OUT_SEL_IN7_SELn_MASK               (0xC000U)
#define ITRC_OUT_SEL_IN7_SELn_SHIFT              (14U)
/*! IN7_SELn - Selects AHB secure bus or MBC bus illegal access event as a trigger source. */
#define ITRC_OUT_SEL_IN7_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN7_SELn_SHIFT)) & ITRC_OUT_SEL_IN7_SELn_MASK)

#define ITRC_OUT_SEL_IN8_SELn_MASK               (0x30000U)
#define ITRC_OUT_SEL_IN8_SELn_SHIFT              (16U)
/*! IN8_SELn - Selects ELS error event as a trigger source. */
#define ITRC_OUT_SEL_IN8_SELn(x)                 (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN8_SELn_SHIFT)) & ITRC_OUT_SEL_IN8_SELn_MASK)

#define ITRC_OUT_SEL_IN10_SELn_MASK              (0x300000U)
#define ITRC_OUT_SEL_IN10_SELn_SHIFT             (20U)
/*! IN10_SELn - Selects PKC error event as a trigger source. */
#define ITRC_OUT_SEL_IN10_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN10_SELn_SHIFT)) & ITRC_OUT_SEL_IN10_SELn_MASK)

#define ITRC_OUT_SEL_IN14_SELn_MASK              (0x30000000U)
#define ITRC_OUT_SEL_IN14_SELn_SHIFT             (28U)
/*! IN14_SELn - Selects software event 0 as a trigger source. */
#define ITRC_OUT_SEL_IN14_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN14_SELn_SHIFT)) & ITRC_OUT_SEL_IN14_SELn_MASK)

#define ITRC_OUT_SEL_IN15_SELn_MASK              (0xC0000000U)
#define ITRC_OUT_SEL_IN15_SELn_SHIFT             (30U)
/*! IN15_SELn - Selects software event 1 as a trigger source. */
#define ITRC_OUT_SEL_IN15_SELn(x)                (((uint32_t)(((uint32_t)(x)) << ITRC_OUT_SEL_IN15_SELn_SHIFT)) & ITRC_OUT_SEL_IN15_SELn_MASK)
/*! @} */

/* The count of ITRC_OUT_SEL */
#define ITRC_OUT_SEL_COUNT                       (8U)

/* The count of ITRC_OUT_SEL */
#define ITRC_OUT_SEL_COUNT2                      (2U)

/*! @name SW_EVENT0 - Software event 0 */
/*! @{ */

#define ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_MASK   (0xFFFFFFFFU)
#define ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_SHIFT  (0U)
/*! TRIGGER_SW_EVENT_0 - Trigger software event 0. */
#define ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0(x)     (((uint32_t)(((uint32_t)(x)) << ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_SHIFT)) & ITRC_SW_EVENT0_TRIGGER_SW_EVENT_0_MASK)
/*! @} */

/*! @name SW_EVENT1 - Software event 1 */
/*! @{ */

#define ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_MASK   (0xFFFFFFFFU)
#define ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_SHIFT  (0U)
/*! TRIGGER_SW_EVENT_1 - Trigger software event 1. */
#define ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1(x)     (((uint32_t)(((uint32_t)(x)) << ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_SHIFT)) & ITRC_SW_EVENT1_TRIGGER_SW_EVENT_1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ITRC_Register_Masks */


/*!
 * @}
 */ /* end of group ITRC_Peripheral_Access_Layer */


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


#endif  /* PERI_ITRC_H_ */

