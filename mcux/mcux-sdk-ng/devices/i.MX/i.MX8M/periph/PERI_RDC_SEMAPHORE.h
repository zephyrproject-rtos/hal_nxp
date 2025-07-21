/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RDC_SEMAPHORE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RDC_SEMAPHORE.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RDC_SEMAPHORE
 *
 * CMSIS Peripheral Access Layer for RDC_SEMAPHORE
 */

#if !defined(PERI_RDC_SEMAPHORE_H_)
#define PERI_RDC_SEMAPHORE_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- RDC_SEMAPHORE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RDC_SEMAPHORE_Peripheral_Access_Layer RDC_SEMAPHORE Peripheral Access Layer
 * @{
 */

/** RDC_SEMAPHORE - Register Layout Typedef */
typedef struct {
  __IO uint8_t GATE0;                              /**< Gate Register, offset: 0x0 */
  __IO uint8_t GATE1;                              /**< Gate Register, offset: 0x1 */
  __IO uint8_t GATE2;                              /**< Gate Register, offset: 0x2 */
  __IO uint8_t GATE3;                              /**< Gate Register, offset: 0x3 */
  __IO uint8_t GATE4;                              /**< Gate Register, offset: 0x4 */
  __IO uint8_t GATE5;                              /**< Gate Register, offset: 0x5 */
  __IO uint8_t GATE6;                              /**< Gate Register, offset: 0x6 */
  __IO uint8_t GATE7;                              /**< Gate Register, offset: 0x7 */
  __IO uint8_t GATE8;                              /**< Gate Register, offset: 0x8 */
  __IO uint8_t GATE9;                              /**< Gate Register, offset: 0x9 */
  __IO uint8_t GATE10;                             /**< Gate Register, offset: 0xA */
  __IO uint8_t GATE11;                             /**< Gate Register, offset: 0xB */
  __IO uint8_t GATE12;                             /**< Gate Register, offset: 0xC */
  __IO uint8_t GATE13;                             /**< Gate Register, offset: 0xD */
  __IO uint8_t GATE14;                             /**< Gate Register, offset: 0xE */
  __IO uint8_t GATE15;                             /**< Gate Register, offset: 0xF */
  __IO uint8_t GATE16;                             /**< Gate Register, offset: 0x10 */
  __IO uint8_t GATE17;                             /**< Gate Register, offset: 0x11 */
  __IO uint8_t GATE18;                             /**< Gate Register, offset: 0x12 */
  __IO uint8_t GATE19;                             /**< Gate Register, offset: 0x13 */
  __IO uint8_t GATE20;                             /**< Gate Register, offset: 0x14 */
  __IO uint8_t GATE21;                             /**< Gate Register, offset: 0x15 */
  __IO uint8_t GATE22;                             /**< Gate Register, offset: 0x16 */
  __IO uint8_t GATE23;                             /**< Gate Register, offset: 0x17 */
  __IO uint8_t GATE24;                             /**< Gate Register, offset: 0x18 */
  __IO uint8_t GATE25;                             /**< Gate Register, offset: 0x19 */
  __IO uint8_t GATE26;                             /**< Gate Register, offset: 0x1A */
  __IO uint8_t GATE27;                             /**< Gate Register, offset: 0x1B */
  __IO uint8_t GATE28;                             /**< Gate Register, offset: 0x1C */
  __IO uint8_t GATE29;                             /**< Gate Register, offset: 0x1D */
  __IO uint8_t GATE30;                             /**< Gate Register, offset: 0x1E */
  __IO uint8_t GATE31;                             /**< Gate Register, offset: 0x1F */
  __IO uint8_t GATE32;                             /**< Gate Register, offset: 0x20 */
  __IO uint8_t GATE33;                             /**< Gate Register, offset: 0x21 */
  __IO uint8_t GATE34;                             /**< Gate Register, offset: 0x22 */
  __IO uint8_t GATE35;                             /**< Gate Register, offset: 0x23 */
  __IO uint8_t GATE36;                             /**< Gate Register, offset: 0x24 */
  __IO uint8_t GATE37;                             /**< Gate Register, offset: 0x25 */
  __IO uint8_t GATE38;                             /**< Gate Register, offset: 0x26 */
  __IO uint8_t GATE39;                             /**< Gate Register, offset: 0x27 */
  __IO uint8_t GATE40;                             /**< Gate Register, offset: 0x28 */
  __IO uint8_t GATE41;                             /**< Gate Register, offset: 0x29 */
  __IO uint8_t GATE42;                             /**< Gate Register, offset: 0x2A */
  __IO uint8_t GATE43;                             /**< Gate Register, offset: 0x2B */
  __IO uint8_t GATE44;                             /**< Gate Register, offset: 0x2C */
  __IO uint8_t GATE45;                             /**< Gate Register, offset: 0x2D */
  __IO uint8_t GATE46;                             /**< Gate Register, offset: 0x2E */
  __IO uint8_t GATE47;                             /**< Gate Register, offset: 0x2F */
  __IO uint8_t GATE48;                             /**< Gate Register, offset: 0x30 */
  __IO uint8_t GATE49;                             /**< Gate Register, offset: 0x31 */
  __IO uint8_t GATE50;                             /**< Gate Register, offset: 0x32 */
  __IO uint8_t GATE51;                             /**< Gate Register, offset: 0x33 */
  __IO uint8_t GATE52;                             /**< Gate Register, offset: 0x34 */
  __IO uint8_t GATE53;                             /**< Gate Register, offset: 0x35 */
  __IO uint8_t GATE54;                             /**< Gate Register, offset: 0x36 */
  __IO uint8_t GATE55;                             /**< Gate Register, offset: 0x37 */
  __IO uint8_t GATE56;                             /**< Gate Register, offset: 0x38 */
  __IO uint8_t GATE57;                             /**< Gate Register, offset: 0x39 */
  __IO uint8_t GATE58;                             /**< Gate Register, offset: 0x3A */
  __IO uint8_t GATE59;                             /**< Gate Register, offset: 0x3B */
  __IO uint8_t GATE60;                             /**< Gate Register, offset: 0x3C */
  __IO uint8_t GATE61;                             /**< Gate Register, offset: 0x3D */
  __IO uint8_t GATE62;                             /**< Gate Register, offset: 0x3E */
  __IO uint8_t GATE63;                             /**< Gate Register, offset: 0x3F */
  union {                                          /* offset: 0x40 */
    __IO uint16_t RSTGT_R;                           /**< Reset Gate Read, offset: 0x40 */
    __IO uint16_t RSTGT_W;                           /**< Reset Gate Write, offset: 0x40 */
  };
} RDC_SEMAPHORE_Type;

/* ----------------------------------------------------------------------------
   -- RDC_SEMAPHORE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RDC_SEMAPHORE_Register_Masks RDC_SEMAPHORE Register Masks
 * @{
 */

/*! @name GATE0 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE0_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE0_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE0_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE0_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE0_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE0_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE0_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE0_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE0_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE0_LDOM_MASK)
/*! @} */

/*! @name GATE1 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE1_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE1_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE1_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE1_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE1_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE1_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE1_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE1_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE1_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE1_LDOM_MASK)
/*! @} */

/*! @name GATE2 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE2_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE2_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE2_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE2_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE2_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE2_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE2_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE2_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE2_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE2_LDOM_MASK)
/*! @} */

/*! @name GATE3 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE3_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE3_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE3_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE3_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE3_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE3_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE3_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE3_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE3_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE3_LDOM_MASK)
/*! @} */

/*! @name GATE4 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE4_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE4_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE4_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE4_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE4_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE4_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE4_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE4_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE4_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE4_LDOM_MASK)
/*! @} */

/*! @name GATE5 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE5_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE5_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE5_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE5_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE5_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE5_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE5_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE5_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE5_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE5_LDOM_MASK)
/*! @} */

/*! @name GATE6 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE6_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE6_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE6_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE6_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE6_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE6_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE6_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE6_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE6_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE6_LDOM_MASK)
/*! @} */

/*! @name GATE7 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE7_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE7_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE7_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE7_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE7_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE7_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE7_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE7_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE7_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE7_LDOM_MASK)
/*! @} */

/*! @name GATE8 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE8_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE8_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE8_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE8_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE8_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE8_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE8_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE8_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE8_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE8_LDOM_MASK)
/*! @} */

/*! @name GATE9 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE9_GTFSM_MASK           (0xFU)
#define RDC_SEMAPHORE_GATE9_GTFSM_SHIFT          (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE9_GTFSM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE9_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE9_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE9_LDOM_MASK            (0x30U)
#define RDC_SEMAPHORE_GATE9_LDOM_SHIFT           (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE9_LDOM(x)              (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE9_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE9_LDOM_MASK)
/*! @} */

/*! @name GATE10 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE10_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE10_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE10_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE10_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE10_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE10_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE10_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE10_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE10_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE10_LDOM_MASK)
/*! @} */

/*! @name GATE11 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE11_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE11_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE11_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE11_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE11_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE11_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE11_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE11_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE11_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE11_LDOM_MASK)
/*! @} */

/*! @name GATE12 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE12_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE12_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE12_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE12_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE12_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE12_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE12_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE12_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE12_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE12_LDOM_MASK)
/*! @} */

/*! @name GATE13 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE13_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE13_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE13_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE13_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE13_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE13_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE13_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE13_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE13_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE13_LDOM_MASK)
/*! @} */

/*! @name GATE14 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE14_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE14_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE14_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE14_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE14_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE14_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE14_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE14_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE14_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE14_LDOM_MASK)
/*! @} */

/*! @name GATE15 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE15_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE15_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE15_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE15_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE15_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE15_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE15_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE15_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE15_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE15_LDOM_MASK)
/*! @} */

/*! @name GATE16 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE16_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE16_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE16_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE16_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE16_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE16_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE16_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE16_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE16_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE16_LDOM_MASK)
/*! @} */

/*! @name GATE17 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE17_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE17_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE17_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE17_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE17_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE17_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE17_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE17_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE17_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE17_LDOM_MASK)
/*! @} */

/*! @name GATE18 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE18_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE18_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE18_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE18_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE18_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE18_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE18_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE18_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE18_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE18_LDOM_MASK)
/*! @} */

/*! @name GATE19 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE19_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE19_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE19_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE19_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE19_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE19_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE19_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE19_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE19_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE19_LDOM_MASK)
/*! @} */

/*! @name GATE20 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE20_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE20_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE20_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE20_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE20_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE20_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE20_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE20_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE20_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE20_LDOM_MASK)
/*! @} */

/*! @name GATE21 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE21_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE21_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE21_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE21_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE21_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE21_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE21_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE21_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE21_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE21_LDOM_MASK)
/*! @} */

/*! @name GATE22 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE22_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE22_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE22_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE22_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE22_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE22_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE22_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE22_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE22_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE22_LDOM_MASK)
/*! @} */

/*! @name GATE23 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE23_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE23_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE23_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE23_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE23_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE23_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE23_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE23_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE23_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE23_LDOM_MASK)
/*! @} */

/*! @name GATE24 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE24_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE24_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE24_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE24_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE24_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE24_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE24_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE24_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE24_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE24_LDOM_MASK)
/*! @} */

/*! @name GATE25 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE25_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE25_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE25_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE25_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE25_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE25_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE25_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE25_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE25_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE25_LDOM_MASK)
/*! @} */

/*! @name GATE26 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE26_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE26_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE26_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE26_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE26_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE26_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE26_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE26_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE26_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE26_LDOM_MASK)
/*! @} */

/*! @name GATE27 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE27_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE27_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE27_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE27_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE27_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE27_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE27_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE27_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE27_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE27_LDOM_MASK)
/*! @} */

/*! @name GATE28 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE28_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE28_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE28_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE28_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE28_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE28_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE28_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE28_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE28_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE28_LDOM_MASK)
/*! @} */

/*! @name GATE29 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE29_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE29_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE29_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE29_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE29_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE29_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE29_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE29_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE29_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE29_LDOM_MASK)
/*! @} */

/*! @name GATE30 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE30_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE30_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE30_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE30_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE30_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE30_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE30_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE30_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE30_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE30_LDOM_MASK)
/*! @} */

/*! @name GATE31 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE31_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE31_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE31_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE31_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE31_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE31_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE31_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE31_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE31_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE31_LDOM_MASK)
/*! @} */

/*! @name GATE32 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE32_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE32_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE32_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE32_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE32_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE32_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE32_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE32_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE32_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE32_LDOM_MASK)
/*! @} */

/*! @name GATE33 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE33_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE33_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE33_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE33_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE33_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE33_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE33_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE33_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE33_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE33_LDOM_MASK)
/*! @} */

/*! @name GATE34 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE34_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE34_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE34_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE34_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE34_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE34_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE34_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE34_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE34_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE34_LDOM_MASK)
/*! @} */

/*! @name GATE35 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE35_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE35_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE35_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE35_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE35_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE35_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE35_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE35_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE35_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE35_LDOM_MASK)
/*! @} */

/*! @name GATE36 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE36_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE36_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE36_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE36_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE36_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE36_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE36_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE36_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE36_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE36_LDOM_MASK)
/*! @} */

/*! @name GATE37 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE37_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE37_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE37_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE37_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE37_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE37_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE37_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE37_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE37_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE37_LDOM_MASK)
/*! @} */

/*! @name GATE38 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE38_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE38_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE38_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE38_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE38_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE38_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE38_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE38_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE38_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE38_LDOM_MASK)
/*! @} */

/*! @name GATE39 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE39_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE39_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE39_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE39_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE39_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE39_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE39_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE39_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE39_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE39_LDOM_MASK)
/*! @} */

/*! @name GATE40 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE40_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE40_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE40_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE40_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE40_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE40_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE40_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE40_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE40_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE40_LDOM_MASK)
/*! @} */

/*! @name GATE41 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE41_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE41_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE41_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE41_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE41_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE41_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE41_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE41_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE41_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE41_LDOM_MASK)
/*! @} */

/*! @name GATE42 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE42_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE42_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE42_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE42_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE42_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE42_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE42_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE42_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE42_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE42_LDOM_MASK)
/*! @} */

/*! @name GATE43 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE43_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE43_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE43_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE43_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE43_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE43_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE43_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE43_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE43_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE43_LDOM_MASK)
/*! @} */

/*! @name GATE44 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE44_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE44_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE44_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE44_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE44_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE44_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE44_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE44_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE44_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE44_LDOM_MASK)
/*! @} */

/*! @name GATE45 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE45_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE45_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE45_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE45_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE45_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE45_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE45_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE45_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE45_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE45_LDOM_MASK)
/*! @} */

/*! @name GATE46 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE46_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE46_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE46_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE46_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE46_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE46_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE46_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE46_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE46_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE46_LDOM_MASK)
/*! @} */

/*! @name GATE47 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE47_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE47_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE47_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE47_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE47_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE47_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE47_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE47_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE47_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE47_LDOM_MASK)
/*! @} */

/*! @name GATE48 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE48_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE48_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE48_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE48_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE48_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE48_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE48_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE48_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE48_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE48_LDOM_MASK)
/*! @} */

/*! @name GATE49 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE49_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE49_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE49_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE49_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE49_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE49_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE49_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE49_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE49_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE49_LDOM_MASK)
/*! @} */

/*! @name GATE50 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE50_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE50_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE50_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE50_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE50_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE50_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE50_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE50_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE50_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE50_LDOM_MASK)
/*! @} */

/*! @name GATE51 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE51_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE51_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE51_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE51_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE51_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE51_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE51_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE51_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE51_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE51_LDOM_MASK)
/*! @} */

/*! @name GATE52 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE52_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE52_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE52_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE52_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE52_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE52_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE52_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE52_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE52_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE52_LDOM_MASK)
/*! @} */

/*! @name GATE53 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE53_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE53_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE53_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE53_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE53_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE53_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE53_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE53_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE53_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE53_LDOM_MASK)
/*! @} */

/*! @name GATE54 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE54_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE54_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE54_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE54_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE54_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE54_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE54_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE54_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE54_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE54_LDOM_MASK)
/*! @} */

/*! @name GATE55 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE55_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE55_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE55_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE55_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE55_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE55_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE55_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE55_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE55_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE55_LDOM_MASK)
/*! @} */

/*! @name GATE56 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE56_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE56_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE56_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE56_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE56_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE56_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE56_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE56_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE56_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE56_LDOM_MASK)
/*! @} */

/*! @name GATE57 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE57_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE57_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE57_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE57_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE57_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE57_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE57_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE57_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE57_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE57_LDOM_MASK)
/*! @} */

/*! @name GATE58 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE58_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE58_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE58_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE58_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE58_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE58_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE58_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE58_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE58_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE58_LDOM_MASK)
/*! @} */

/*! @name GATE59 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE59_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE59_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE59_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE59_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE59_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE59_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE59_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE59_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE59_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE59_LDOM_MASK)
/*! @} */

/*! @name GATE60 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE60_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE60_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE60_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE60_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE60_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE60_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE60_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE60_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE60_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE60_LDOM_MASK)
/*! @} */

/*! @name GATE61 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE61_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE61_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE61_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE61_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE61_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE61_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE61_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE61_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE61_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE61_LDOM_MASK)
/*! @} */

/*! @name GATE62 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE62_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE62_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE62_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE62_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE62_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE62_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE62_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE62_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE62_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE62_LDOM_MASK)
/*! @} */

/*! @name GATE63 - Gate Register */
/*! @{ */

#define RDC_SEMAPHORE_GATE63_GTFSM_MASK          (0xFU)
#define RDC_SEMAPHORE_GATE63_GTFSM_SHIFT         (0U)
/*! GTFSM - Gate Finite State Machine.
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor with master_index = 0.
 *  0b0010..The gate has been locked by processor with master_index = 1.
 *  0b0011..The gate has been locked by processor with master_index = 2.
 *  0b0100..The gate has been locked by processor with master_index = 3.
 *  0b0101..The gate has been locked by processor with master_index = 4.
 *  0b0110..The gate has been locked by processor with master_index = 5.
 *  0b0111..The gate has been locked by processor with master_index = 6.
 *  0b1000..The gate has been locked by processor with master_index = 7.
 *  0b1001..The gate has been locked by processor with master_index = 8.
 *  0b1010..The gate has been locked by processor with master_index = 9.
 *  0b1011..The gate has been locked by processor with master_index = 10.
 *  0b1100..The gate has been locked by processor with master_index = 11.
 *  0b1101..The gate has been locked by processor with master_index = 12.
 *  0b1110..The gate has been locked by processor with master_index = 13.
 *  0b1111..The gate has been locked by processor with master_index = 14.
 */
#define RDC_SEMAPHORE_GATE63_GTFSM(x)            (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE63_GTFSM_SHIFT)) & RDC_SEMAPHORE_GATE63_GTFSM_MASK)

#define RDC_SEMAPHORE_GATE63_LDOM_MASK           (0x30U)
#define RDC_SEMAPHORE_GATE63_LDOM_SHIFT          (4U)
/*! LDOM
 *  0b00..The gate is locked by domain 0. (True if bits [3:0] do not equal 0000.)
 *  0b01..The gate has been locked by domain 1.
 *  0b10..The gate has been locked by domain 2.
 *  0b11..The gate has been locked by domain 3.
 */
#define RDC_SEMAPHORE_GATE63_LDOM(x)             (((uint8_t)(((uint8_t)(x)) << RDC_SEMAPHORE_GATE63_LDOM_SHIFT)) & RDC_SEMAPHORE_GATE63_LDOM_MASK)
/*! @} */

/*! @name RSTGT_R - Reset Gate Read */
/*! @{ */

#define RDC_SEMAPHORE_RSTGT_R_RSTGMS_MASK        (0xFU)
#define RDC_SEMAPHORE_RSTGT_R_RSTGMS_SHIFT       (0U)
#define RDC_SEMAPHORE_RSTGT_R_RSTGMS(x)          (((uint16_t)(((uint16_t)(x)) << RDC_SEMAPHORE_RSTGT_R_RSTGMS_SHIFT)) & RDC_SEMAPHORE_RSTGT_R_RSTGMS_MASK)

#define RDC_SEMAPHORE_RSTGT_R_RSTGSM_MASK        (0x30U)
#define RDC_SEMAPHORE_RSTGT_R_RSTGSM_SHIFT       (4U)
/*! RSTGSM
 *  0b00..Idle, waiting for the first data pattern write.
 *  0b01..Waiting for the second data pattern write.
 *  0b10..The 2-write sequence has completed. Generate the specified gate reset(s). After the reset is performed,
 *        this machine returns to the idle (waiting for first data pattern write) state. The "01" state persists
 *        for only one clock cycle. Software will never be able to observe this state.
 *  0b11..This state encoding is never used and therefore reserved.
 */
#define RDC_SEMAPHORE_RSTGT_R_RSTGSM(x)          (((uint16_t)(((uint16_t)(x)) << RDC_SEMAPHORE_RSTGT_R_RSTGSM_SHIFT)) & RDC_SEMAPHORE_RSTGT_R_RSTGSM_MASK)

#define RDC_SEMAPHORE_RSTGT_R_RSTGTN_MASK        (0xFF00U)
#define RDC_SEMAPHORE_RSTGT_R_RSTGTN_SHIFT       (8U)
#define RDC_SEMAPHORE_RSTGT_R_RSTGTN(x)          (((uint16_t)(((uint16_t)(x)) << RDC_SEMAPHORE_RSTGT_R_RSTGTN_SHIFT)) & RDC_SEMAPHORE_RSTGT_R_RSTGTN_MASK)
/*! @} */

/*! @name RSTGT_W - Reset Gate Write */
/*! @{ */

#define RDC_SEMAPHORE_RSTGT_W_RSTGDP_MASK        (0xFFU)
#define RDC_SEMAPHORE_RSTGT_W_RSTGDP_SHIFT       (0U)
#define RDC_SEMAPHORE_RSTGT_W_RSTGDP(x)          (((uint16_t)(((uint16_t)(x)) << RDC_SEMAPHORE_RSTGT_W_RSTGDP_SHIFT)) & RDC_SEMAPHORE_RSTGT_W_RSTGDP_MASK)

#define RDC_SEMAPHORE_RSTGT_W_RSTGTN_MASK        (0xFF00U)
#define RDC_SEMAPHORE_RSTGT_W_RSTGTN_SHIFT       (8U)
#define RDC_SEMAPHORE_RSTGT_W_RSTGTN(x)          (((uint16_t)(((uint16_t)(x)) << RDC_SEMAPHORE_RSTGT_W_RSTGTN_SHIFT)) & RDC_SEMAPHORE_RSTGT_W_RSTGTN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RDC_SEMAPHORE_Register_Masks */


/*!
 * @}
 */ /* end of group RDC_SEMAPHORE_Peripheral_Access_Layer */


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


#endif  /* PERI_RDC_SEMAPHORE_H_ */

