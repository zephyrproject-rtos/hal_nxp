/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SEMA4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SEMA4.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SEMA4
 *
 * CMSIS Peripheral Access Layer for SEMA4
 */

#if !defined(PERI_SEMA4_H_)
#define PERI_SEMA4_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- SEMA4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA4_Peripheral_Access_Layer SEMA4 Peripheral Access Layer
 * @{
 */

/** SEMA4 - Size of Registers Arrays */
#define SEMA4_CPINE_COUNT                         2u
#define SEMA4_CPNTF_COUNT                         2u

/** SEMA4 - Register Layout Typedef */
typedef struct {
  __IO uint8_t Gate00;                             /**< Semaphores Gate 0 Register, offset: 0x0 */
  __IO uint8_t Gate01;                             /**< Semaphores Gate 1 Register, offset: 0x1 */
  __IO uint8_t Gate02;                             /**< Semaphores Gate 2 Register, offset: 0x2 */
  __IO uint8_t Gate03;                             /**< Semaphores Gate 3 Register, offset: 0x3 */
  __IO uint8_t Gate04;                             /**< Semaphores Gate 4 Register, offset: 0x4 */
  __IO uint8_t Gate05;                             /**< Semaphores Gate 5 Register, offset: 0x5 */
  __IO uint8_t Gate06;                             /**< Semaphores Gate 6 Register, offset: 0x6 */
  __IO uint8_t Gate07;                             /**< Semaphores Gate 7 Register, offset: 0x7 */
  __IO uint8_t Gate08;                             /**< Semaphores Gate 8 Register, offset: 0x8 */
  __IO uint8_t Gate09;                             /**< Semaphores Gate 9 Register, offset: 0x9 */
  __IO uint8_t Gate10;                             /**< Semaphores Gate 10 Register, offset: 0xA */
  __IO uint8_t Gate11;                             /**< Semaphores Gate 11 Register, offset: 0xB */
  __IO uint8_t Gate12;                             /**< Semaphores Gate 12 Register, offset: 0xC */
  __IO uint8_t Gate13;                             /**< Semaphores Gate 13 Register, offset: 0xD */
  __IO uint8_t Gate14;                             /**< Semaphores Gate 14 Register, offset: 0xE */
  __IO uint8_t Gate15;                             /**< Semaphores Gate 15 Register, offset: 0xF */
       uint8_t RESERVED_0[48];
  struct {                                         /* offset: 0x40, array step: 0x8 */
    __IO uint16_t CPINE;                             /**< Semaphores Processor n IRQ Notification Enable, array offset: 0x40, array step: 0x8 */
         uint8_t RESERVED_0[6];
  } CPINE[SEMA4_CPINE_COUNT];
       uint8_t RESERVED_1[48];
  struct {                                         /* offset: 0x80, array step: 0x8 */
    __IO uint16_t CPNTF;                             /**< Semaphores Processor n IRQ Notification, array offset: 0x80, array step: 0x8 */
         uint8_t RESERVED_0[6];
  } CPNTF[SEMA4_CPNTF_COUNT];
       uint8_t RESERVED_2[112];
  __IO uint16_t RSTGT;                             /**< Semaphores (Secure) Reset Gate n, offset: 0x100 */
       uint8_t RESERVED_3[2];
  __IO uint16_t RSTNTF;                            /**< Semaphores (Secure) Reset IRQ Notification, offset: 0x104 */
} SEMA4_Type;

/* ----------------------------------------------------------------------------
   -- SEMA4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA4_Register_Masks SEMA4 Register Masks
 * @{
 */

/*! @name Gate00 - Semaphores Gate 0 Register */
/*! @{ */

#define SEMA4_Gate00_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate00_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate00_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate00_GTFSM_SHIFT)) & SEMA4_Gate00_GTFSM_MASK)
/*! @} */

/*! @name Gate01 - Semaphores Gate 1 Register */
/*! @{ */

#define SEMA4_Gate01_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate01_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate01_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate01_GTFSM_SHIFT)) & SEMA4_Gate01_GTFSM_MASK)
/*! @} */

/*! @name Gate02 - Semaphores Gate 2 Register */
/*! @{ */

#define SEMA4_Gate02_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate02_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate02_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate02_GTFSM_SHIFT)) & SEMA4_Gate02_GTFSM_MASK)
/*! @} */

/*! @name Gate03 - Semaphores Gate 3 Register */
/*! @{ */

#define SEMA4_Gate03_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate03_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate03_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate03_GTFSM_SHIFT)) & SEMA4_Gate03_GTFSM_MASK)
/*! @} */

/*! @name Gate04 - Semaphores Gate 4 Register */
/*! @{ */

#define SEMA4_Gate04_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate04_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate04_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate04_GTFSM_SHIFT)) & SEMA4_Gate04_GTFSM_MASK)
/*! @} */

/*! @name Gate05 - Semaphores Gate 5 Register */
/*! @{ */

#define SEMA4_Gate05_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate05_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate05_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate05_GTFSM_SHIFT)) & SEMA4_Gate05_GTFSM_MASK)
/*! @} */

/*! @name Gate06 - Semaphores Gate 6 Register */
/*! @{ */

#define SEMA4_Gate06_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate06_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate06_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate06_GTFSM_SHIFT)) & SEMA4_Gate06_GTFSM_MASK)
/*! @} */

/*! @name Gate07 - Semaphores Gate 7 Register */
/*! @{ */

#define SEMA4_Gate07_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate07_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate07_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate07_GTFSM_SHIFT)) & SEMA4_Gate07_GTFSM_MASK)
/*! @} */

/*! @name Gate08 - Semaphores Gate 8 Register */
/*! @{ */

#define SEMA4_Gate08_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate08_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate08_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate08_GTFSM_SHIFT)) & SEMA4_Gate08_GTFSM_MASK)
/*! @} */

/*! @name Gate09 - Semaphores Gate 9 Register */
/*! @{ */

#define SEMA4_Gate09_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate09_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate09_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate09_GTFSM_SHIFT)) & SEMA4_Gate09_GTFSM_MASK)
/*! @} */

/*! @name Gate10 - Semaphores Gate 10 Register */
/*! @{ */

#define SEMA4_Gate10_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate10_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate10_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate10_GTFSM_SHIFT)) & SEMA4_Gate10_GTFSM_MASK)
/*! @} */

/*! @name Gate11 - Semaphores Gate 11 Register */
/*! @{ */

#define SEMA4_Gate11_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate11_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate11_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate11_GTFSM_SHIFT)) & SEMA4_Gate11_GTFSM_MASK)
/*! @} */

/*! @name Gate12 - Semaphores Gate 12 Register */
/*! @{ */

#define SEMA4_Gate12_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate12_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate12_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate12_GTFSM_SHIFT)) & SEMA4_Gate12_GTFSM_MASK)
/*! @} */

/*! @name Gate13 - Semaphores Gate 13 Register */
/*! @{ */

#define SEMA4_Gate13_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate13_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate13_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate13_GTFSM_SHIFT)) & SEMA4_Gate13_GTFSM_MASK)
/*! @} */

/*! @name Gate14 - Semaphores Gate 14 Register */
/*! @{ */

#define SEMA4_Gate14_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate14_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate14_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate14_GTFSM_SHIFT)) & SEMA4_Gate14_GTFSM_MASK)
/*! @} */

/*! @name Gate15 - Semaphores Gate 15 Register */
/*! @{ */

#define SEMA4_Gate15_GTFSM_MASK                  (0x3U)
#define SEMA4_Gate15_GTFSM_SHIFT                 (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b00..The gate is unlocked (free).
 *  0b01..The gate has been locked by processor 0.
 *  0b10..The gate has been locked by processor 1.
 *  0b11..This state encoding is never used and therefore reserved. Attempted writes of 0x03 are treated as "no
 *        operation" and do not affect the gate state machine.
 */
#define SEMA4_Gate15_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA4_Gate15_GTFSM_SHIFT)) & SEMA4_Gate15_GTFSM_MASK)
/*! @} */

/*! @name CPINE - Semaphores Processor n IRQ Notification Enable */
/*! @{ */

#define SEMA4_CPINE_INE7_MASK                    (0x1U)
#define SEMA4_CPINE_INE7_SHIFT                   (0U)
/*! INE7 - Interrupt Request Notification Enable 7. This field is a bitmap to enable the generation
 *    of an interrupt notification from a failed attempt to lock gate 7.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE7(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE7_SHIFT)) & SEMA4_CPINE_INE7_MASK)

#define SEMA4_CPINE_INE6_MASK                    (0x2U)
#define SEMA4_CPINE_INE6_SHIFT                   (1U)
/*! INE6 - Interrupt Request Notification Enable 6. This field is a bitmap to enable the generation
 *    of an interrupt notification from a failed attempt to lock gate 6.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE6(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE6_SHIFT)) & SEMA4_CPINE_INE6_MASK)

#define SEMA4_CPINE_INE5_MASK                    (0x4U)
#define SEMA4_CPINE_INE5_SHIFT                   (2U)
/*! INE5 - Interrupt Request Notification Enable 5. This field is a bitmap to enable the generation
 *    of an interrupt notification from a failed attempt to lock gate 5.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE5(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE5_SHIFT)) & SEMA4_CPINE_INE5_MASK)

#define SEMA4_CPINE_INE4_MASK                    (0x8U)
#define SEMA4_CPINE_INE4_SHIFT                   (3U)
/*! INE4 - Interrupt Request Notification Enable 4. This field is a bitmap to enable the generation
 *    of an interrupt notification from a failed attempt to lock gate 4.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE4(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE4_SHIFT)) & SEMA4_CPINE_INE4_MASK)

#define SEMA4_CPINE_INE3_MASK                    (0x10U)
#define SEMA4_CPINE_INE3_SHIFT                   (4U)
/*! INE3
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE3(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE3_SHIFT)) & SEMA4_CPINE_INE3_MASK)

#define SEMA4_CPINE_INE2_MASK                    (0x20U)
#define SEMA4_CPINE_INE2_SHIFT                   (5U)
/*! INE2
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE2(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE2_SHIFT)) & SEMA4_CPINE_INE2_MASK)

#define SEMA4_CPINE_INE1_MASK                    (0x40U)
#define SEMA4_CPINE_INE1_SHIFT                   (6U)
/*! INE1
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE1(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE1_SHIFT)) & SEMA4_CPINE_INE1_MASK)

#define SEMA4_CPINE_INE0_MASK                    (0x80U)
#define SEMA4_CPINE_INE0_SHIFT                   (7U)
/*! INE0
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE0(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE0_SHIFT)) & SEMA4_CPINE_INE0_MASK)

#define SEMA4_CPINE_INE15_MASK                   (0x100U)
#define SEMA4_CPINE_INE15_SHIFT                  (8U)
/*! INE15 - Interrupt Request Notification Enable 15. This field is a bitmap to enable the
 *    generation of an interrupt notification from a failed attempt to lock gate 15.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE15(x)                     (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE15_SHIFT)) & SEMA4_CPINE_INE15_MASK)

#define SEMA4_CPINE_INE14_MASK                   (0x200U)
#define SEMA4_CPINE_INE14_SHIFT                  (9U)
/*! INE14 - Interrupt Request Notification Enable 14. This field is a bitmap to enable the
 *    generation of an interrupt notification from a failed attempt to lock gate 14.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE14(x)                     (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE14_SHIFT)) & SEMA4_CPINE_INE14_MASK)

#define SEMA4_CPINE_INE13_MASK                   (0x400U)
#define SEMA4_CPINE_INE13_SHIFT                  (10U)
/*! INE13 - Interrupt Request Notification Enable 13. This field is a bitmap to enable the
 *    generation of an interrupt notification from a failed attempt to lock gate 13.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE13(x)                     (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE13_SHIFT)) & SEMA4_CPINE_INE13_MASK)

#define SEMA4_CPINE_INE12_MASK                   (0x800U)
#define SEMA4_CPINE_INE12_SHIFT                  (11U)
/*! INE12 - Interrupt Request Notification Enable 12. This field is a bitmap to enable the
 *    generation of an interrupt notification from a failed attempt to lock gate 12.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE12(x)                     (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE12_SHIFT)) & SEMA4_CPINE_INE12_MASK)

#define SEMA4_CPINE_INE11_MASK                   (0x1000U)
#define SEMA4_CPINE_INE11_SHIFT                  (12U)
/*! INE11 - Interrupt Request Notification Enable 11. This field is a bitmap to enable the
 *    generation of an interrupt notification from a failed attempt to lock gate 11.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE11(x)                     (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE11_SHIFT)) & SEMA4_CPINE_INE11_MASK)

#define SEMA4_CPINE_INE10_MASK                   (0x2000U)
#define SEMA4_CPINE_INE10_SHIFT                  (13U)
/*! INE10 - Interrupt Request Notification Enable 10. This field is a bitmap to enable the
 *    generation of an interrupt notification from a failed attempt to lock gate 10.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE10(x)                     (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE10_SHIFT)) & SEMA4_CPINE_INE10_MASK)

#define SEMA4_CPINE_INE9_MASK                    (0x4000U)
#define SEMA4_CPINE_INE9_SHIFT                   (14U)
/*! INE9 - Interrupt Request Notification Enable 9. This field is a bitmap to enable the generation
 *    of an interrupt notification from a failed attempt to lock gate 9.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE9(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE9_SHIFT)) & SEMA4_CPINE_INE9_MASK)

#define SEMA4_CPINE_INE8_MASK                    (0x8000U)
#define SEMA4_CPINE_INE8_SHIFT                   (15U)
/*! INE8 - Interrupt Request Notification Enable 8. This field is a bitmap to enable the generation
 *    of an interrupt notification from a failed attempt to lock gate 8.
 *  0b0..The generation of the notification interrupt is disabled.
 *  0b1..The generation of the notification interrupt is enabled.
 */
#define SEMA4_CPINE_INE8(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPINE_INE8_SHIFT)) & SEMA4_CPINE_INE8_MASK)
/*! @} */

/*! @name CPNTF - Semaphores Processor n IRQ Notification */
/*! @{ */

#define SEMA4_CPNTF_GN7_MASK                     (0x1U)
#define SEMA4_CPNTF_GN7_SHIFT                    (0U)
#define SEMA4_CPNTF_GN7(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN7_SHIFT)) & SEMA4_CPNTF_GN7_MASK)

#define SEMA4_CPNTF_GN6_MASK                     (0x2U)
#define SEMA4_CPNTF_GN6_SHIFT                    (1U)
#define SEMA4_CPNTF_GN6(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN6_SHIFT)) & SEMA4_CPNTF_GN6_MASK)

#define SEMA4_CPNTF_GN5_MASK                     (0x4U)
#define SEMA4_CPNTF_GN5_SHIFT                    (2U)
#define SEMA4_CPNTF_GN5(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN5_SHIFT)) & SEMA4_CPNTF_GN5_MASK)

#define SEMA4_CPNTF_GN4_MASK                     (0x8U)
#define SEMA4_CPNTF_GN4_SHIFT                    (3U)
#define SEMA4_CPNTF_GN4(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN4_SHIFT)) & SEMA4_CPNTF_GN4_MASK)

#define SEMA4_CPNTF_GN3_MASK                     (0x10U)
#define SEMA4_CPNTF_GN3_SHIFT                    (4U)
#define SEMA4_CPNTF_GN3(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN3_SHIFT)) & SEMA4_CPNTF_GN3_MASK)

#define SEMA4_CPNTF_GN2_MASK                     (0x20U)
#define SEMA4_CPNTF_GN2_SHIFT                    (5U)
#define SEMA4_CPNTF_GN2(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN2_SHIFT)) & SEMA4_CPNTF_GN2_MASK)

#define SEMA4_CPNTF_GN1_MASK                     (0x40U)
#define SEMA4_CPNTF_GN1_SHIFT                    (6U)
#define SEMA4_CPNTF_GN1(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN1_SHIFT)) & SEMA4_CPNTF_GN1_MASK)

#define SEMA4_CPNTF_GN0_MASK                     (0x80U)
#define SEMA4_CPNTF_GN0_SHIFT                    (7U)
#define SEMA4_CPNTF_GN0(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN0_SHIFT)) & SEMA4_CPNTF_GN0_MASK)

#define SEMA4_CPNTF_GN15_MASK                    (0x100U)
#define SEMA4_CPNTF_GN15_SHIFT                   (8U)
#define SEMA4_CPNTF_GN15(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN15_SHIFT)) & SEMA4_CPNTF_GN15_MASK)

#define SEMA4_CPNTF_GN14_MASK                    (0x200U)
#define SEMA4_CPNTF_GN14_SHIFT                   (9U)
#define SEMA4_CPNTF_GN14(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN14_SHIFT)) & SEMA4_CPNTF_GN14_MASK)

#define SEMA4_CPNTF_GN13_MASK                    (0x400U)
#define SEMA4_CPNTF_GN13_SHIFT                   (10U)
#define SEMA4_CPNTF_GN13(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN13_SHIFT)) & SEMA4_CPNTF_GN13_MASK)

#define SEMA4_CPNTF_GN12_MASK                    (0x800U)
#define SEMA4_CPNTF_GN12_SHIFT                   (11U)
#define SEMA4_CPNTF_GN12(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN12_SHIFT)) & SEMA4_CPNTF_GN12_MASK)

#define SEMA4_CPNTF_GN11_MASK                    (0x1000U)
#define SEMA4_CPNTF_GN11_SHIFT                   (12U)
#define SEMA4_CPNTF_GN11(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN11_SHIFT)) & SEMA4_CPNTF_GN11_MASK)

#define SEMA4_CPNTF_GN10_MASK                    (0x2000U)
#define SEMA4_CPNTF_GN10_SHIFT                   (13U)
#define SEMA4_CPNTF_GN10(x)                      (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN10_SHIFT)) & SEMA4_CPNTF_GN10_MASK)

#define SEMA4_CPNTF_GN9_MASK                     (0x4000U)
#define SEMA4_CPNTF_GN9_SHIFT                    (14U)
#define SEMA4_CPNTF_GN9(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN9_SHIFT)) & SEMA4_CPNTF_GN9_MASK)

#define SEMA4_CPNTF_GN8_MASK                     (0x8000U)
#define SEMA4_CPNTF_GN8_SHIFT                    (15U)
#define SEMA4_CPNTF_GN8(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA4_CPNTF_GN8_SHIFT)) & SEMA4_CPNTF_GN8_MASK)
/*! @} */

/*! @name RSTGT - Semaphores (Secure) Reset Gate n */
/*! @{ */

#define SEMA4_RSTGT_RSTGSM_RSTGMS_RSTGDP_MASK    (0xFFU)
#define SEMA4_RSTGT_RSTGSM_RSTGMS_RSTGDP_SHIFT   (0U)
#define SEMA4_RSTGT_RSTGSM_RSTGMS_RSTGDP(x)      (((uint16_t)(((uint16_t)(x)) << SEMA4_RSTGT_RSTGSM_RSTGMS_RSTGDP_SHIFT)) & SEMA4_RSTGT_RSTGSM_RSTGMS_RSTGDP_MASK)

#define SEMA4_RSTGT_RSTGTN_MASK                  (0xFF00U)
#define SEMA4_RSTGT_RSTGTN_SHIFT                 (8U)
#define SEMA4_RSTGT_RSTGTN(x)                    (((uint16_t)(((uint16_t)(x)) << SEMA4_RSTGT_RSTGTN_SHIFT)) & SEMA4_RSTGT_RSTGTN_MASK)
/*! @} */

/*! @name RSTNTF - Semaphores (Secure) Reset IRQ Notification */
/*! @{ */

#define SEMA4_RSTNTF_RSTNSM_RSTNMS_RSTNDP_MASK   (0xFFU)
#define SEMA4_RSTNTF_RSTNSM_RSTNMS_RSTNDP_SHIFT  (0U)
#define SEMA4_RSTNTF_RSTNSM_RSTNMS_RSTNDP(x)     (((uint16_t)(((uint16_t)(x)) << SEMA4_RSTNTF_RSTNSM_RSTNMS_RSTNDP_SHIFT)) & SEMA4_RSTNTF_RSTNSM_RSTNMS_RSTNDP_MASK)

#define SEMA4_RSTNTF_RSTNTN_MASK                 (0xFF00U)
#define SEMA4_RSTNTF_RSTNTN_SHIFT                (8U)
#define SEMA4_RSTNTF_RSTNTN(x)                   (((uint16_t)(((uint16_t)(x)) << SEMA4_RSTNTF_RSTNTN_SHIFT)) & SEMA4_RSTNTF_RSTNTN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SEMA4_Register_Masks */


/*!
 * @}
 */ /* end of group SEMA4_Peripheral_Access_Layer */


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


#endif  /* PERI_SEMA4_H_ */

