/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_L_VFCCU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_L_VFCCU
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_L_VFCCU_H_)  /* Check if memory map has not been already included */
#define S32Z2_L_VFCCU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- L_VFCCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup L_VFCCU_Peripheral_Access_Layer L_VFCCU Peripheral Access Layer
 * @{
 */

/** L_VFCCU - Register Layout Typedef */
typedef struct {
  __IO uint32_t GDFHID_C0;                         /**< Global DID-FHID Map, offset: 0x0 */
  __IO uint32_t GDFHID_C1;                         /**< Global DID-FHID Map, offset: 0x4 */
  uint8_t RESERVED_0[24];
  __IO uint32_t GFLTPO_C0;                         /**< Global Fault Polarity, offset: 0x20 */
  uint8_t RESERVED_1[60];
  __IO uint32_t GFLTRC_C0;                         /**< Global Fault Recovery, offset: 0x60 */
  uint8_t RESERVED_2[60];
  __IO uint32_t GFLTOVDC0;                         /**< Global Fault Overflow Detection, offset: 0xA0 */
  uint8_t RESERVED_3[140];
  __IO uint32_t GCTRL;                             /**< Global Space Control, offset: 0x130 */
  __IO uint32_t GINTOVFS;                          /**< Global DID FSM Status, offset: 0x134 */
  uint8_t RESERVED_4[428];
  __IO uint32_t GDBGCFG;                           /**< Global Debug, offset: 0x2E4 */
  __I  uint32_t GDBGSTAT;                          /**< Global Debug Status, offset: 0x2E8 */
  uint8_t RESERVED_5[64788];
  __IO uint32_t FHCFG0;                            /**< Fault Handler, offset: 0x10000 */
  __I  uint32_t FHSRVDS0;                          /**< Fault Handler Status, offset: 0x10004 */
  uint8_t RESERVED_6[8];
  __IO uint32_t FHFLTENC00;                        /**< Fault Enable, offset: 0x10010 */
  uint8_t RESERVED_7[60];
  __IO uint32_t FHFLTS00;                          /**< Fault Status, offset: 0x10050 */
  uint8_t RESERVED_8[60];
  __IO uint32_t FHFLTRKC00;                        /**< Fault Reaction Set Configuration, offset: 0x10090 */
  __IO uint32_t FHFLTRKC01;                        /**< Fault Reaction Set Configuration, offset: 0x10094 */
  __IO uint32_t FHFLTRKC02;                        /**< Fault Reaction Set Configuration, offset: 0x10098 */
  __IO uint32_t FHFLTRKC03;                        /**< Fault Reaction Set Configuration, offset: 0x1009C, available only on: L_VFCCU_3, L_VFCCU_5 (missing on L_VFCCU_0, L_VFCCU_1, L_VFCCU_2, L_VFCCU_4, L_VFCCU_6) */
  uint8_t RESERVED_9[240];
  __IO uint32_t FHIMRKC0_00;                       /**< Immediate Reaction Configuration, offset: 0x10190 */
  uint8_t RESERVED_10[12];
  __IO uint32_t FHIMRKC0_10;                       /**< Immediate Reaction Configuration, offset: 0x101A0 */
  uint8_t RESERVED_11[12];
  __IO uint32_t FHIMRKC0_20;                       /**< Immediate Reaction Configuration, offset: 0x101B0 */
  uint8_t RESERVED_12[12];
  __IO uint32_t FHIMRKC0_30;                       /**< Immediate Reaction Configuration, offset: 0x101C0 */
  uint8_t RESERVED_13[12];
  __IO uint32_t FHIMRKC0_40;                       /**< Immediate Reaction Configuration, offset: 0x101D0 */
  uint8_t RESERVED_14[12];
  __IO uint32_t FHIMRKC0_50;                       /**< Immediate Reaction Configuration, offset: 0x101E0 */
} L_VFCCU_Type, *L_VFCCU_MemMapPtr;

/** Number of instances of the L_VFCCU module. */
#define L_VFCCU_INSTANCE_COUNT                   (7u)

/* L_VFCCU - Peripheral instance base addresses */
/** Peripheral L_VFCCU_0 base address */
#define IP_L_VFCCU_0_BASE                        (0x40410000u)
/** Peripheral L_VFCCU_0 base pointer */
#define IP_L_VFCCU_0                             ((L_VFCCU_Type *)IP_L_VFCCU_0_BASE)
/** Peripheral L_VFCCU_1 base address */
#define IP_L_VFCCU_1_BASE                        (0x40C10000u)
/** Peripheral L_VFCCU_1 base pointer */
#define IP_L_VFCCU_1                             ((L_VFCCU_Type *)IP_L_VFCCU_1_BASE)
/** Peripheral L_VFCCU_2 base address */
#define IP_L_VFCCU_2_BASE                        (0x410E0000u)
/** Peripheral L_VFCCU_2 base pointer */
#define IP_L_VFCCU_2                             ((L_VFCCU_Type *)IP_L_VFCCU_2_BASE)
/** Peripheral L_VFCCU_3 base address */
#define IP_L_VFCCU_3_BASE                        (0x41C10000u)
/** Peripheral L_VFCCU_3 base pointer */
#define IP_L_VFCCU_3                             ((L_VFCCU_Type *)IP_L_VFCCU_3_BASE)
/** Peripheral L_VFCCU_4 base address */
#define IP_L_VFCCU_4_BASE                        (0x42410000u)
/** Peripheral L_VFCCU_4 base pointer */
#define IP_L_VFCCU_4                             ((L_VFCCU_Type *)IP_L_VFCCU_4_BASE)
/** Peripheral L_VFCCU_5 base address */
#define IP_L_VFCCU_5_BASE                        (0x42C10000u)
/** Peripheral L_VFCCU_5 base pointer */
#define IP_L_VFCCU_5                             ((L_VFCCU_Type *)IP_L_VFCCU_5_BASE)
/** Peripheral L_VFCCU_6 base address */
#define IP_L_VFCCU_6_BASE                        (0x440E0000u)
/** Peripheral L_VFCCU_6 base pointer */
#define IP_L_VFCCU_6                             ((L_VFCCU_Type *)IP_L_VFCCU_6_BASE)
/** Array initializer of L_VFCCU peripheral base addresses */
#define IP_L_VFCCU_BASE_ADDRS                    { IP_L_VFCCU_0_BASE, IP_L_VFCCU_1_BASE, IP_L_VFCCU_2_BASE, IP_L_VFCCU_3_BASE, IP_L_VFCCU_4_BASE, IP_L_VFCCU_5_BASE, IP_L_VFCCU_6_BASE }
/** Array initializer of L_VFCCU peripheral base pointers */
#define IP_L_VFCCU_BASE_PTRS                     { IP_L_VFCCU_0, IP_L_VFCCU_1, IP_L_VFCCU_2, IP_L_VFCCU_3, IP_L_VFCCU_4, IP_L_VFCCU_5, IP_L_VFCCU_6 }

/* ----------------------------------------------------------------------------
   -- L_VFCCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup L_VFCCU_Register_Masks L_VFCCU Register Masks
 * @{
 */

/*! @name GDFHID_C0 - Global DID-FHID Map */
/*! @{ */

#define L_VFCCU_GDFHID_C0_FHDID0_MASK            (0x7U)
#define L_VFCCU_GDFHID_C0_FHDID0_SHIFT           (0U)
#define L_VFCCU_GDFHID_C0_FHDID0_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID0(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID0_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID0_MASK)

#define L_VFCCU_GDFHID_C0_FHDID1_MASK            (0x70U)
#define L_VFCCU_GDFHID_C0_FHDID1_SHIFT           (4U)
#define L_VFCCU_GDFHID_C0_FHDID1_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID1(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID1_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID1_MASK)

#define L_VFCCU_GDFHID_C0_FHDID2_MASK            (0x700U)
#define L_VFCCU_GDFHID_C0_FHDID2_SHIFT           (8U)
#define L_VFCCU_GDFHID_C0_FHDID2_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID2(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID2_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID2_MASK)

#define L_VFCCU_GDFHID_C0_FHDID3_MASK            (0x7000U)
#define L_VFCCU_GDFHID_C0_FHDID3_SHIFT           (12U)
#define L_VFCCU_GDFHID_C0_FHDID3_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID3(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID3_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID3_MASK)

#define L_VFCCU_GDFHID_C0_FHDID4_MASK            (0x70000U)
#define L_VFCCU_GDFHID_C0_FHDID4_SHIFT           (16U)
#define L_VFCCU_GDFHID_C0_FHDID4_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID4(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID4_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID4_MASK)

#define L_VFCCU_GDFHID_C0_FHDID5_MASK            (0x700000U)
#define L_VFCCU_GDFHID_C0_FHDID5_SHIFT           (20U)
#define L_VFCCU_GDFHID_C0_FHDID5_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID5(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID5_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID5_MASK)

#define L_VFCCU_GDFHID_C0_FHDID6_MASK            (0x7000000U)
#define L_VFCCU_GDFHID_C0_FHDID6_SHIFT           (24U)
#define L_VFCCU_GDFHID_C0_FHDID6_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID6(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID6_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID6_MASK)

#define L_VFCCU_GDFHID_C0_FHDID7_MASK            (0x70000000U)
#define L_VFCCU_GDFHID_C0_FHDID7_SHIFT           (28U)
#define L_VFCCU_GDFHID_C0_FHDID7_WIDTH           (3U)
#define L_VFCCU_GDFHID_C0_FHDID7(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C0_FHDID7_SHIFT)) & L_VFCCU_GDFHID_C0_FHDID7_MASK)
/*! @} */

/*! @name GDFHID_C1 - Global DID-FHID Map */
/*! @{ */

#define L_VFCCU_GDFHID_C1_FHDID8_MASK            (0x7U)
#define L_VFCCU_GDFHID_C1_FHDID8_SHIFT           (0U)
#define L_VFCCU_GDFHID_C1_FHDID8_WIDTH           (3U)
#define L_VFCCU_GDFHID_C1_FHDID8(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID8_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID8_MASK)

#define L_VFCCU_GDFHID_C1_FHDID9_MASK            (0x70U)
#define L_VFCCU_GDFHID_C1_FHDID9_SHIFT           (4U)
#define L_VFCCU_GDFHID_C1_FHDID9_WIDTH           (3U)
#define L_VFCCU_GDFHID_C1_FHDID9(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID9_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID9_MASK)

#define L_VFCCU_GDFHID_C1_FHDID10_MASK           (0x700U)
#define L_VFCCU_GDFHID_C1_FHDID10_SHIFT          (8U)
#define L_VFCCU_GDFHID_C1_FHDID10_WIDTH          (3U)
#define L_VFCCU_GDFHID_C1_FHDID10(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID10_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID10_MASK)

#define L_VFCCU_GDFHID_C1_FHDID11_MASK           (0x7000U)
#define L_VFCCU_GDFHID_C1_FHDID11_SHIFT          (12U)
#define L_VFCCU_GDFHID_C1_FHDID11_WIDTH          (3U)
#define L_VFCCU_GDFHID_C1_FHDID11(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID11_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID11_MASK)

#define L_VFCCU_GDFHID_C1_FHDID12_MASK           (0x70000U)
#define L_VFCCU_GDFHID_C1_FHDID12_SHIFT          (16U)
#define L_VFCCU_GDFHID_C1_FHDID12_WIDTH          (3U)
#define L_VFCCU_GDFHID_C1_FHDID12(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID12_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID12_MASK)

#define L_VFCCU_GDFHID_C1_FHDID13_MASK           (0x700000U)
#define L_VFCCU_GDFHID_C1_FHDID13_SHIFT          (20U)
#define L_VFCCU_GDFHID_C1_FHDID13_WIDTH          (3U)
#define L_VFCCU_GDFHID_C1_FHDID13(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID13_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID13_MASK)

#define L_VFCCU_GDFHID_C1_FHDID14_MASK           (0x7000000U)
#define L_VFCCU_GDFHID_C1_FHDID14_SHIFT          (24U)
#define L_VFCCU_GDFHID_C1_FHDID14_WIDTH          (3U)
#define L_VFCCU_GDFHID_C1_FHDID14(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID14_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID14_MASK)

#define L_VFCCU_GDFHID_C1_FHDID15_MASK           (0x70000000U)
#define L_VFCCU_GDFHID_C1_FHDID15_SHIFT          (28U)
#define L_VFCCU_GDFHID_C1_FHDID15_WIDTH          (3U)
#define L_VFCCU_GDFHID_C1_FHDID15(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDFHID_C1_FHDID15_SHIFT)) & L_VFCCU_GDFHID_C1_FHDID15_MASK)
/*! @} */

/*! @name GFLTPO_C0 - Global Fault Polarity */
/*! @{ */

#define L_VFCCU_GFLTPO_C0_PS0_MASK               (0x1U)
#define L_VFCCU_GFLTPO_C0_PS0_SHIFT              (0U)
#define L_VFCCU_GFLTPO_C0_PS0_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS0(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS0_SHIFT)) & L_VFCCU_GFLTPO_C0_PS0_MASK)

#define L_VFCCU_GFLTPO_C0_PS1_MASK               (0x2U)
#define L_VFCCU_GFLTPO_C0_PS1_SHIFT              (1U)
#define L_VFCCU_GFLTPO_C0_PS1_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS1(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS1_SHIFT)) & L_VFCCU_GFLTPO_C0_PS1_MASK)

#define L_VFCCU_GFLTPO_C0_PS2_MASK               (0x4U)
#define L_VFCCU_GFLTPO_C0_PS2_SHIFT              (2U)
#define L_VFCCU_GFLTPO_C0_PS2_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS2(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS2_SHIFT)) & L_VFCCU_GFLTPO_C0_PS2_MASK)

#define L_VFCCU_GFLTPO_C0_PS3_MASK               (0x8U)
#define L_VFCCU_GFLTPO_C0_PS3_SHIFT              (3U)
#define L_VFCCU_GFLTPO_C0_PS3_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS3(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS3_SHIFT)) & L_VFCCU_GFLTPO_C0_PS3_MASK)

#define L_VFCCU_GFLTPO_C0_PS4_MASK               (0x10U)
#define L_VFCCU_GFLTPO_C0_PS4_SHIFT              (4U)
#define L_VFCCU_GFLTPO_C0_PS4_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS4(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS4_SHIFT)) & L_VFCCU_GFLTPO_C0_PS4_MASK)

#define L_VFCCU_GFLTPO_C0_PS5_MASK               (0x20U)
#define L_VFCCU_GFLTPO_C0_PS5_SHIFT              (5U)
#define L_VFCCU_GFLTPO_C0_PS5_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS5(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS5_SHIFT)) & L_VFCCU_GFLTPO_C0_PS5_MASK)

#define L_VFCCU_GFLTPO_C0_PS6_MASK               (0x40U)
#define L_VFCCU_GFLTPO_C0_PS6_SHIFT              (6U)
#define L_VFCCU_GFLTPO_C0_PS6_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS6(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS6_SHIFT)) & L_VFCCU_GFLTPO_C0_PS6_MASK)

#define L_VFCCU_GFLTPO_C0_PS7_MASK               (0x80U)
#define L_VFCCU_GFLTPO_C0_PS7_SHIFT              (7U)
#define L_VFCCU_GFLTPO_C0_PS7_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS7(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS7_SHIFT)) & L_VFCCU_GFLTPO_C0_PS7_MASK)

#define L_VFCCU_GFLTPO_C0_PS8_MASK               (0x100U)
#define L_VFCCU_GFLTPO_C0_PS8_SHIFT              (8U)
#define L_VFCCU_GFLTPO_C0_PS8_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS8(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS8_SHIFT)) & L_VFCCU_GFLTPO_C0_PS8_MASK)

#define L_VFCCU_GFLTPO_C0_PS9_MASK               (0x200U)
#define L_VFCCU_GFLTPO_C0_PS9_SHIFT              (9U)
#define L_VFCCU_GFLTPO_C0_PS9_WIDTH              (1U)
#define L_VFCCU_GFLTPO_C0_PS9(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS9_SHIFT)) & L_VFCCU_GFLTPO_C0_PS9_MASK)

#define L_VFCCU_GFLTPO_C0_PS10_MASK              (0x400U)
#define L_VFCCU_GFLTPO_C0_PS10_SHIFT             (10U)
#define L_VFCCU_GFLTPO_C0_PS10_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS10(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS10_SHIFT)) & L_VFCCU_GFLTPO_C0_PS10_MASK)

#define L_VFCCU_GFLTPO_C0_PS11_MASK              (0x800U)
#define L_VFCCU_GFLTPO_C0_PS11_SHIFT             (11U)
#define L_VFCCU_GFLTPO_C0_PS11_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS11(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS11_SHIFT)) & L_VFCCU_GFLTPO_C0_PS11_MASK)

#define L_VFCCU_GFLTPO_C0_PS12_MASK              (0x1000U)
#define L_VFCCU_GFLTPO_C0_PS12_SHIFT             (12U)
#define L_VFCCU_GFLTPO_C0_PS12_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS12(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS12_SHIFT)) & L_VFCCU_GFLTPO_C0_PS12_MASK)

#define L_VFCCU_GFLTPO_C0_PS13_MASK              (0x2000U)
#define L_VFCCU_GFLTPO_C0_PS13_SHIFT             (13U)
#define L_VFCCU_GFLTPO_C0_PS13_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS13(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS13_SHIFT)) & L_VFCCU_GFLTPO_C0_PS13_MASK)

#define L_VFCCU_GFLTPO_C0_PS14_MASK              (0x4000U)
#define L_VFCCU_GFLTPO_C0_PS14_SHIFT             (14U)
#define L_VFCCU_GFLTPO_C0_PS14_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS14(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS14_SHIFT)) & L_VFCCU_GFLTPO_C0_PS14_MASK)

#define L_VFCCU_GFLTPO_C0_PS15_MASK              (0x8000U)
#define L_VFCCU_GFLTPO_C0_PS15_SHIFT             (15U)
#define L_VFCCU_GFLTPO_C0_PS15_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS15(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS15_SHIFT)) & L_VFCCU_GFLTPO_C0_PS15_MASK)

#define L_VFCCU_GFLTPO_C0_PS16_MASK              (0x10000U)
#define L_VFCCU_GFLTPO_C0_PS16_SHIFT             (16U)
#define L_VFCCU_GFLTPO_C0_PS16_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS16(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS16_SHIFT)) & L_VFCCU_GFLTPO_C0_PS16_MASK)

#define L_VFCCU_GFLTPO_C0_PS17_MASK              (0x20000U)
#define L_VFCCU_GFLTPO_C0_PS17_SHIFT             (17U)
#define L_VFCCU_GFLTPO_C0_PS17_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS17(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS17_SHIFT)) & L_VFCCU_GFLTPO_C0_PS17_MASK)

#define L_VFCCU_GFLTPO_C0_PS18_MASK              (0x40000U)
#define L_VFCCU_GFLTPO_C0_PS18_SHIFT             (18U)
#define L_VFCCU_GFLTPO_C0_PS18_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS18(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS18_SHIFT)) & L_VFCCU_GFLTPO_C0_PS18_MASK)

#define L_VFCCU_GFLTPO_C0_PS19_MASK              (0x80000U)
#define L_VFCCU_GFLTPO_C0_PS19_SHIFT             (19U)
#define L_VFCCU_GFLTPO_C0_PS19_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS19(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS19_SHIFT)) & L_VFCCU_GFLTPO_C0_PS19_MASK)

#define L_VFCCU_GFLTPO_C0_PS20_MASK              (0x100000U)
#define L_VFCCU_GFLTPO_C0_PS20_SHIFT             (20U)
#define L_VFCCU_GFLTPO_C0_PS20_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS20(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS20_SHIFT)) & L_VFCCU_GFLTPO_C0_PS20_MASK)

#define L_VFCCU_GFLTPO_C0_PS21_MASK              (0x200000U)
#define L_VFCCU_GFLTPO_C0_PS21_SHIFT             (21U)
#define L_VFCCU_GFLTPO_C0_PS21_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS21(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS21_SHIFT)) & L_VFCCU_GFLTPO_C0_PS21_MASK)

#define L_VFCCU_GFLTPO_C0_PS22_MASK              (0x400000U)
#define L_VFCCU_GFLTPO_C0_PS22_SHIFT             (22U)
#define L_VFCCU_GFLTPO_C0_PS22_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS22(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS22_SHIFT)) & L_VFCCU_GFLTPO_C0_PS22_MASK)

#define L_VFCCU_GFLTPO_C0_PS23_MASK              (0x800000U)
#define L_VFCCU_GFLTPO_C0_PS23_SHIFT             (23U)
#define L_VFCCU_GFLTPO_C0_PS23_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS23(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS23_SHIFT)) & L_VFCCU_GFLTPO_C0_PS23_MASK)

#define L_VFCCU_GFLTPO_C0_PS24_MASK              (0x1000000U)
#define L_VFCCU_GFLTPO_C0_PS24_SHIFT             (24U)
#define L_VFCCU_GFLTPO_C0_PS24_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS24(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS24_SHIFT)) & L_VFCCU_GFLTPO_C0_PS24_MASK)

#define L_VFCCU_GFLTPO_C0_PS25_MASK              (0x2000000U)
#define L_VFCCU_GFLTPO_C0_PS25_SHIFT             (25U)
#define L_VFCCU_GFLTPO_C0_PS25_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS25(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS25_SHIFT)) & L_VFCCU_GFLTPO_C0_PS25_MASK)

#define L_VFCCU_GFLTPO_C0_PS26_MASK              (0x4000000U)
#define L_VFCCU_GFLTPO_C0_PS26_SHIFT             (26U)
#define L_VFCCU_GFLTPO_C0_PS26_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS26(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS26_SHIFT)) & L_VFCCU_GFLTPO_C0_PS26_MASK)

#define L_VFCCU_GFLTPO_C0_PS27_MASK              (0x8000000U)
#define L_VFCCU_GFLTPO_C0_PS27_SHIFT             (27U)
#define L_VFCCU_GFLTPO_C0_PS27_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS27(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS27_SHIFT)) & L_VFCCU_GFLTPO_C0_PS27_MASK)

#define L_VFCCU_GFLTPO_C0_PS28_MASK              (0x10000000U)
#define L_VFCCU_GFLTPO_C0_PS28_SHIFT             (28U)
#define L_VFCCU_GFLTPO_C0_PS28_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS28(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS28_SHIFT)) & L_VFCCU_GFLTPO_C0_PS28_MASK)

#define L_VFCCU_GFLTPO_C0_PS29_MASK              (0x20000000U)
#define L_VFCCU_GFLTPO_C0_PS29_SHIFT             (29U)
#define L_VFCCU_GFLTPO_C0_PS29_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS29(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS29_SHIFT)) & L_VFCCU_GFLTPO_C0_PS29_MASK)

#define L_VFCCU_GFLTPO_C0_PS30_MASK              (0x40000000U)
#define L_VFCCU_GFLTPO_C0_PS30_SHIFT             (30U)
#define L_VFCCU_GFLTPO_C0_PS30_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS30(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS30_SHIFT)) & L_VFCCU_GFLTPO_C0_PS30_MASK)

#define L_VFCCU_GFLTPO_C0_PS31_MASK              (0x80000000U)
#define L_VFCCU_GFLTPO_C0_PS31_SHIFT             (31U)
#define L_VFCCU_GFLTPO_C0_PS31_WIDTH             (1U)
#define L_VFCCU_GFLTPO_C0_PS31(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTPO_C0_PS31_SHIFT)) & L_VFCCU_GFLTPO_C0_PS31_MASK)
/*! @} */

/*! @name GFLTRC_C0 - Global Fault Recovery */
/*! @{ */

#define L_VFCCU_GFLTRC_C0_RHWSW0_MASK            (0x1U)
#define L_VFCCU_GFLTRC_C0_RHWSW0_SHIFT           (0U)
#define L_VFCCU_GFLTRC_C0_RHWSW0_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW0(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW0_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW0_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW1_MASK            (0x2U)
#define L_VFCCU_GFLTRC_C0_RHWSW1_SHIFT           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW1_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW1(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW1_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW1_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW2_MASK            (0x4U)
#define L_VFCCU_GFLTRC_C0_RHWSW2_SHIFT           (2U)
#define L_VFCCU_GFLTRC_C0_RHWSW2_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW2(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW2_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW2_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW3_MASK            (0x8U)
#define L_VFCCU_GFLTRC_C0_RHWSW3_SHIFT           (3U)
#define L_VFCCU_GFLTRC_C0_RHWSW3_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW3(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW3_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW3_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW4_MASK            (0x10U)
#define L_VFCCU_GFLTRC_C0_RHWSW4_SHIFT           (4U)
#define L_VFCCU_GFLTRC_C0_RHWSW4_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW4(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW4_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW4_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW5_MASK            (0x20U)
#define L_VFCCU_GFLTRC_C0_RHWSW5_SHIFT           (5U)
#define L_VFCCU_GFLTRC_C0_RHWSW5_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW5(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW5_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW5_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW6_MASK            (0x40U)
#define L_VFCCU_GFLTRC_C0_RHWSW6_SHIFT           (6U)
#define L_VFCCU_GFLTRC_C0_RHWSW6_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW6(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW6_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW6_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW7_MASK            (0x80U)
#define L_VFCCU_GFLTRC_C0_RHWSW7_SHIFT           (7U)
#define L_VFCCU_GFLTRC_C0_RHWSW7_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW7(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW7_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW7_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW8_MASK            (0x100U)
#define L_VFCCU_GFLTRC_C0_RHWSW8_SHIFT           (8U)
#define L_VFCCU_GFLTRC_C0_RHWSW8_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW8(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW8_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW8_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW9_MASK            (0x200U)
#define L_VFCCU_GFLTRC_C0_RHWSW9_SHIFT           (9U)
#define L_VFCCU_GFLTRC_C0_RHWSW9_WIDTH           (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW9(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW9_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW9_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW10_MASK           (0x400U)
#define L_VFCCU_GFLTRC_C0_RHWSW10_SHIFT          (10U)
#define L_VFCCU_GFLTRC_C0_RHWSW10_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW10(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW10_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW10_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW11_MASK           (0x800U)
#define L_VFCCU_GFLTRC_C0_RHWSW11_SHIFT          (11U)
#define L_VFCCU_GFLTRC_C0_RHWSW11_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW11(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW11_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW11_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW12_MASK           (0x1000U)
#define L_VFCCU_GFLTRC_C0_RHWSW12_SHIFT          (12U)
#define L_VFCCU_GFLTRC_C0_RHWSW12_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW12(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW12_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW12_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW13_MASK           (0x2000U)
#define L_VFCCU_GFLTRC_C0_RHWSW13_SHIFT          (13U)
#define L_VFCCU_GFLTRC_C0_RHWSW13_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW13(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW13_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW13_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW14_MASK           (0x4000U)
#define L_VFCCU_GFLTRC_C0_RHWSW14_SHIFT          (14U)
#define L_VFCCU_GFLTRC_C0_RHWSW14_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW14(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW14_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW14_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW15_MASK           (0x8000U)
#define L_VFCCU_GFLTRC_C0_RHWSW15_SHIFT          (15U)
#define L_VFCCU_GFLTRC_C0_RHWSW15_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW15(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW15_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW15_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW16_MASK           (0x10000U)
#define L_VFCCU_GFLTRC_C0_RHWSW16_SHIFT          (16U)
#define L_VFCCU_GFLTRC_C0_RHWSW16_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW16(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW16_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW16_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW17_MASK           (0x20000U)
#define L_VFCCU_GFLTRC_C0_RHWSW17_SHIFT          (17U)
#define L_VFCCU_GFLTRC_C0_RHWSW17_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW17(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW17_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW17_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW18_MASK           (0x40000U)
#define L_VFCCU_GFLTRC_C0_RHWSW18_SHIFT          (18U)
#define L_VFCCU_GFLTRC_C0_RHWSW18_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW18(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW18_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW18_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW19_MASK           (0x80000U)
#define L_VFCCU_GFLTRC_C0_RHWSW19_SHIFT          (19U)
#define L_VFCCU_GFLTRC_C0_RHWSW19_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW19(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW19_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW19_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW20_MASK           (0x100000U)
#define L_VFCCU_GFLTRC_C0_RHWSW20_SHIFT          (20U)
#define L_VFCCU_GFLTRC_C0_RHWSW20_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW20(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW20_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW20_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW21_MASK           (0x200000U)
#define L_VFCCU_GFLTRC_C0_RHWSW21_SHIFT          (21U)
#define L_VFCCU_GFLTRC_C0_RHWSW21_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW21(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW21_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW21_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW22_MASK           (0x400000U)
#define L_VFCCU_GFLTRC_C0_RHWSW22_SHIFT          (22U)
#define L_VFCCU_GFLTRC_C0_RHWSW22_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW22(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW22_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW22_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW23_MASK           (0x800000U)
#define L_VFCCU_GFLTRC_C0_RHWSW23_SHIFT          (23U)
#define L_VFCCU_GFLTRC_C0_RHWSW23_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW23(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW23_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW23_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW24_MASK           (0x1000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW24_SHIFT          (24U)
#define L_VFCCU_GFLTRC_C0_RHWSW24_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW24(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW24_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW24_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW25_MASK           (0x2000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW25_SHIFT          (25U)
#define L_VFCCU_GFLTRC_C0_RHWSW25_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW25(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW25_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW25_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW26_MASK           (0x4000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW26_SHIFT          (26U)
#define L_VFCCU_GFLTRC_C0_RHWSW26_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW26(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW26_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW26_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW27_MASK           (0x8000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW27_SHIFT          (27U)
#define L_VFCCU_GFLTRC_C0_RHWSW27_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW27(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW27_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW27_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW28_MASK           (0x10000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW28_SHIFT          (28U)
#define L_VFCCU_GFLTRC_C0_RHWSW28_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW28(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW28_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW28_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW29_MASK           (0x20000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW29_SHIFT          (29U)
#define L_VFCCU_GFLTRC_C0_RHWSW29_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW29(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW29_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW29_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW30_MASK           (0x40000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW30_SHIFT          (30U)
#define L_VFCCU_GFLTRC_C0_RHWSW30_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW30(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW30_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW30_MASK)

#define L_VFCCU_GFLTRC_C0_RHWSW31_MASK           (0x80000000U)
#define L_VFCCU_GFLTRC_C0_RHWSW31_SHIFT          (31U)
#define L_VFCCU_GFLTRC_C0_RHWSW31_WIDTH          (1U)
#define L_VFCCU_GFLTRC_C0_RHWSW31(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTRC_C0_RHWSW31_SHIFT)) & L_VFCCU_GFLTRC_C0_RHWSW31_MASK)
/*! @} */

/*! @name GFLTOVDC0 - Global Fault Overflow Detection */
/*! @{ */

#define L_VFCCU_GFLTOVDC0_OVF_DIS0_MASK          (0x1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS0_SHIFT         (0U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS0_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS0_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS0_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS1_MASK          (0x2U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS1_SHIFT         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS1_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS1_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS1_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS2_MASK          (0x4U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS2_SHIFT         (2U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS2_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS2_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS2_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS3_MASK          (0x8U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS3_SHIFT         (3U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS3_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS3_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS3_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS4_MASK          (0x10U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS4_SHIFT         (4U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS4_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS4_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS4_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS5_MASK          (0x20U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS5_SHIFT         (5U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS5_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS5_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS5_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS6_MASK          (0x40U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS6_SHIFT         (6U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS6_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS6(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS6_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS6_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS7_MASK          (0x80U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS7_SHIFT         (7U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS7_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS7(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS7_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS7_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS8_MASK          (0x100U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS8_SHIFT         (8U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS8_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS8(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS8_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS8_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS9_MASK          (0x200U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS9_SHIFT         (9U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS9_WIDTH         (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS9(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS9_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS9_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS10_MASK         (0x400U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS10_SHIFT        (10U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS10_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS10(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS10_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS10_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS11_MASK         (0x800U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS11_SHIFT        (11U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS11_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS11(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS11_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS11_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS12_MASK         (0x1000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS12_SHIFT        (12U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS12_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS12(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS12_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS12_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS13_MASK         (0x2000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS13_SHIFT        (13U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS13_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS13(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS13_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS13_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS14_MASK         (0x4000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS14_SHIFT        (14U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS14_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS14(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS14_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS14_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS15_MASK         (0x8000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS15_SHIFT        (15U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS15_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS15(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS15_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS15_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS16_MASK         (0x10000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS16_SHIFT        (16U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS16_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS16(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS16_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS16_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS17_MASK         (0x20000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS17_SHIFT        (17U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS17_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS17(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS17_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS17_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS18_MASK         (0x40000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS18_SHIFT        (18U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS18_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS18(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS18_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS18_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS19_MASK         (0x80000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS19_SHIFT        (19U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS19_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS19(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS19_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS19_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS20_MASK         (0x100000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS20_SHIFT        (20U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS20_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS20(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS20_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS20_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS21_MASK         (0x200000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS21_SHIFT        (21U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS21_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS21(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS21_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS21_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS22_MASK         (0x400000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS22_SHIFT        (22U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS22_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS22(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS22_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS22_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS23_MASK         (0x800000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS23_SHIFT        (23U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS23_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS23(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS23_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS23_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS24_MASK         (0x1000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS24_SHIFT        (24U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS24_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS24(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS24_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS24_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS25_MASK         (0x2000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS25_SHIFT        (25U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS25_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS25(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS25_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS25_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS26_MASK         (0x4000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS26_SHIFT        (26U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS26_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS26(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS26_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS26_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS27_MASK         (0x8000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS27_SHIFT        (27U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS27_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS27(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS27_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS27_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS28_MASK         (0x10000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS28_SHIFT        (28U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS28_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS28(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS28_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS28_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS29_MASK         (0x20000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS29_SHIFT        (29U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS29_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS29(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS29_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS29_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS30_MASK         (0x40000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS30_SHIFT        (30U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS30_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS30(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS30_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS30_MASK)

#define L_VFCCU_GFLTOVDC0_OVF_DIS31_MASK         (0x80000000U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS31_SHIFT        (31U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS31_WIDTH        (1U)
#define L_VFCCU_GFLTOVDC0_OVF_DIS31(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GFLTOVDC0_OVF_DIS31_SHIFT)) & L_VFCCU_GFLTOVDC0_OVF_DIS31_MASK)
/*! @} */

/*! @name GCTRL - Global Space Control */
/*! @{ */

#define L_VFCCU_GCTRL_OVF_EN_MASK                (0x1U)
#define L_VFCCU_GCTRL_OVF_EN_SHIFT               (0U)
#define L_VFCCU_GCTRL_OVF_EN_WIDTH               (1U)
#define L_VFCCU_GCTRL_OVF_EN(x)                  (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GCTRL_OVF_EN_SHIFT)) & L_VFCCU_GCTRL_OVF_EN_MASK)
/*! @} */

/*! @name GINTOVFS - Global DID FSM Status */
/*! @{ */

#define L_VFCCU_GINTOVFS_FLTSERV_MASK            (0x80U)
#define L_VFCCU_GINTOVFS_FLTSERV_SHIFT           (7U)
#define L_VFCCU_GINTOVFS_FLTSERV_WIDTH           (1U)
#define L_VFCCU_GINTOVFS_FLTSERV(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GINTOVFS_FLTSERV_SHIFT)) & L_VFCCU_GINTOVFS_FLTSERV_MASK)

#define L_VFCCU_GINTOVFS_OVF_DET_MASK            (0x100U)
#define L_VFCCU_GINTOVFS_OVF_DET_SHIFT           (8U)
#define L_VFCCU_GINTOVFS_OVF_DET_WIDTH           (1U)
#define L_VFCCU_GINTOVFS_OVF_DET(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GINTOVFS_OVF_DET_SHIFT)) & L_VFCCU_GINTOVFS_OVF_DET_MASK)

#define L_VFCCU_GINTOVFS_SERV_DID_MASK           (0xF0000U)
#define L_VFCCU_GINTOVFS_SERV_DID_SHIFT          (16U)
#define L_VFCCU_GINTOVFS_SERV_DID_WIDTH          (4U)
#define L_VFCCU_GINTOVFS_SERV_DID(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GINTOVFS_SERV_DID_SHIFT)) & L_VFCCU_GINTOVFS_SERV_DID_MASK)

#define L_VFCCU_GINTOVFS_OVF_DID_MASK            (0xF000000U)
#define L_VFCCU_GINTOVFS_OVF_DID_SHIFT           (24U)
#define L_VFCCU_GINTOVFS_OVF_DID_WIDTH           (4U)
#define L_VFCCU_GINTOVFS_OVF_DID(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GINTOVFS_OVF_DID_SHIFT)) & L_VFCCU_GINTOVFS_OVF_DID_MASK)
/*! @} */

/*! @name GDBGCFG - Global Debug */
/*! @{ */

#define L_VFCCU_GDBGCFG_FRZ_MASK                 (0x10000U)
#define L_VFCCU_GDBGCFG_FRZ_SHIFT                (16U)
#define L_VFCCU_GDBGCFG_FRZ_WIDTH                (1U)
#define L_VFCCU_GDBGCFG_FRZ(x)                   (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDBGCFG_FRZ_SHIFT)) & L_VFCCU_GDBGCFG_FRZ_MASK)
/*! @} */

/*! @name GDBGSTAT - Global Debug Status */
/*! @{ */

#define L_VFCCU_GDBGSTAT_FLTIND_MASK             (0xFFU)
#define L_VFCCU_GDBGSTAT_FLTIND_SHIFT            (0U)
#define L_VFCCU_GDBGSTAT_FLTIND_WIDTH            (8U)
#define L_VFCCU_GDBGSTAT_FLTIND(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_GDBGSTAT_FLTIND_SHIFT)) & L_VFCCU_GDBGSTAT_FLTIND_MASK)
/*! @} */

/*! @name FHCFG0 - Fault Handler */
/*! @{ */

#define L_VFCCU_FHCFG0_FHIDEN_MASK               (0x1U)
#define L_VFCCU_FHCFG0_FHIDEN_SHIFT              (0U)
#define L_VFCCU_FHCFG0_FHIDEN_WIDTH              (1U)
#define L_VFCCU_FHCFG0_FHIDEN(x)                 (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHCFG0_FHIDEN_SHIFT)) & L_VFCCU_FHCFG0_FHIDEN_MASK)
/*! @} */

/*! @name FHSRVDS0 - Fault Handler Status */
/*! @{ */

#define L_VFCCU_FHSRVDS0_SERV_DID_MASK           (0xFU)
#define L_VFCCU_FHSRVDS0_SERV_DID_SHIFT          (0U)
#define L_VFCCU_FHSRVDS0_SERV_DID_WIDTH          (4U)
#define L_VFCCU_FHSRVDS0_SERV_DID(x)             (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHSRVDS0_SERV_DID_SHIFT)) & L_VFCCU_FHSRVDS0_SERV_DID_MASK)

#define L_VFCCU_FHSRVDS0_AGGFLTS_MASK            (0x10U)
#define L_VFCCU_FHSRVDS0_AGGFLTS_SHIFT           (4U)
#define L_VFCCU_FHSRVDS0_AGGFLTS_WIDTH           (1U)
#define L_VFCCU_FHSRVDS0_AGGFLTS(x)              (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHSRVDS0_AGGFLTS_SHIFT)) & L_VFCCU_FHSRVDS0_AGGFLTS_MASK)
/*! @} */

/*! @name FHFLTENC00 - Fault Enable */
/*! @{ */

#define L_VFCCU_FHFLTENC00_EN0_MASK              (0x1U)
#define L_VFCCU_FHFLTENC00_EN0_SHIFT             (0U)
#define L_VFCCU_FHFLTENC00_EN0_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN0(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN0_SHIFT)) & L_VFCCU_FHFLTENC00_EN0_MASK)

#define L_VFCCU_FHFLTENC00_EN1_MASK              (0x2U)
#define L_VFCCU_FHFLTENC00_EN1_SHIFT             (1U)
#define L_VFCCU_FHFLTENC00_EN1_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN1(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN1_SHIFT)) & L_VFCCU_FHFLTENC00_EN1_MASK)

#define L_VFCCU_FHFLTENC00_EN2_MASK              (0x4U)
#define L_VFCCU_FHFLTENC00_EN2_SHIFT             (2U)
#define L_VFCCU_FHFLTENC00_EN2_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN2(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN2_SHIFT)) & L_VFCCU_FHFLTENC00_EN2_MASK)

#define L_VFCCU_FHFLTENC00_EN3_MASK              (0x8U)
#define L_VFCCU_FHFLTENC00_EN3_SHIFT             (3U)
#define L_VFCCU_FHFLTENC00_EN3_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN3(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN3_SHIFT)) & L_VFCCU_FHFLTENC00_EN3_MASK)

#define L_VFCCU_FHFLTENC00_EN4_MASK              (0x10U)
#define L_VFCCU_FHFLTENC00_EN4_SHIFT             (4U)
#define L_VFCCU_FHFLTENC00_EN4_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN4(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN4_SHIFT)) & L_VFCCU_FHFLTENC00_EN4_MASK)

#define L_VFCCU_FHFLTENC00_EN5_MASK              (0x20U)
#define L_VFCCU_FHFLTENC00_EN5_SHIFT             (5U)
#define L_VFCCU_FHFLTENC00_EN5_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN5(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN5_SHIFT)) & L_VFCCU_FHFLTENC00_EN5_MASK)

#define L_VFCCU_FHFLTENC00_EN6_MASK              (0x40U)
#define L_VFCCU_FHFLTENC00_EN6_SHIFT             (6U)
#define L_VFCCU_FHFLTENC00_EN6_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN6(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN6_SHIFT)) & L_VFCCU_FHFLTENC00_EN6_MASK)

#define L_VFCCU_FHFLTENC00_EN7_MASK              (0x80U)
#define L_VFCCU_FHFLTENC00_EN7_SHIFT             (7U)
#define L_VFCCU_FHFLTENC00_EN7_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN7(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN7_SHIFT)) & L_VFCCU_FHFLTENC00_EN7_MASK)

#define L_VFCCU_FHFLTENC00_EN8_MASK              (0x100U)
#define L_VFCCU_FHFLTENC00_EN8_SHIFT             (8U)
#define L_VFCCU_FHFLTENC00_EN8_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN8(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN8_SHIFT)) & L_VFCCU_FHFLTENC00_EN8_MASK)

#define L_VFCCU_FHFLTENC00_EN9_MASK              (0x200U)
#define L_VFCCU_FHFLTENC00_EN9_SHIFT             (9U)
#define L_VFCCU_FHFLTENC00_EN9_WIDTH             (1U)
#define L_VFCCU_FHFLTENC00_EN9(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN9_SHIFT)) & L_VFCCU_FHFLTENC00_EN9_MASK)

#define L_VFCCU_FHFLTENC00_EN10_MASK             (0x400U)
#define L_VFCCU_FHFLTENC00_EN10_SHIFT            (10U)
#define L_VFCCU_FHFLTENC00_EN10_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN10(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN10_SHIFT)) & L_VFCCU_FHFLTENC00_EN10_MASK)

#define L_VFCCU_FHFLTENC00_EN11_MASK             (0x800U)
#define L_VFCCU_FHFLTENC00_EN11_SHIFT            (11U)
#define L_VFCCU_FHFLTENC00_EN11_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN11(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN11_SHIFT)) & L_VFCCU_FHFLTENC00_EN11_MASK)

#define L_VFCCU_FHFLTENC00_EN12_MASK             (0x1000U)
#define L_VFCCU_FHFLTENC00_EN12_SHIFT            (12U)
#define L_VFCCU_FHFLTENC00_EN12_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN12(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN12_SHIFT)) & L_VFCCU_FHFLTENC00_EN12_MASK)

#define L_VFCCU_FHFLTENC00_EN13_MASK             (0x2000U)
#define L_VFCCU_FHFLTENC00_EN13_SHIFT            (13U)
#define L_VFCCU_FHFLTENC00_EN13_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN13(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN13_SHIFT)) & L_VFCCU_FHFLTENC00_EN13_MASK)

#define L_VFCCU_FHFLTENC00_EN14_MASK             (0x4000U)
#define L_VFCCU_FHFLTENC00_EN14_SHIFT            (14U)
#define L_VFCCU_FHFLTENC00_EN14_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN14(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN14_SHIFT)) & L_VFCCU_FHFLTENC00_EN14_MASK)

#define L_VFCCU_FHFLTENC00_EN15_MASK             (0x8000U)
#define L_VFCCU_FHFLTENC00_EN15_SHIFT            (15U)
#define L_VFCCU_FHFLTENC00_EN15_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN15(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN15_SHIFT)) & L_VFCCU_FHFLTENC00_EN15_MASK)

#define L_VFCCU_FHFLTENC00_EN16_MASK             (0x10000U)
#define L_VFCCU_FHFLTENC00_EN16_SHIFT            (16U)
#define L_VFCCU_FHFLTENC00_EN16_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN16(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN16_SHIFT)) & L_VFCCU_FHFLTENC00_EN16_MASK)

#define L_VFCCU_FHFLTENC00_EN17_MASK             (0x20000U)
#define L_VFCCU_FHFLTENC00_EN17_SHIFT            (17U)
#define L_VFCCU_FHFLTENC00_EN17_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN17(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN17_SHIFT)) & L_VFCCU_FHFLTENC00_EN17_MASK)

#define L_VFCCU_FHFLTENC00_EN18_MASK             (0x40000U)
#define L_VFCCU_FHFLTENC00_EN18_SHIFT            (18U)
#define L_VFCCU_FHFLTENC00_EN18_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN18(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN18_SHIFT)) & L_VFCCU_FHFLTENC00_EN18_MASK)

#define L_VFCCU_FHFLTENC00_EN19_MASK             (0x80000U)
#define L_VFCCU_FHFLTENC00_EN19_SHIFT            (19U)
#define L_VFCCU_FHFLTENC00_EN19_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN19(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN19_SHIFT)) & L_VFCCU_FHFLTENC00_EN19_MASK)

#define L_VFCCU_FHFLTENC00_EN20_MASK             (0x100000U)
#define L_VFCCU_FHFLTENC00_EN20_SHIFT            (20U)
#define L_VFCCU_FHFLTENC00_EN20_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN20(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN20_SHIFT)) & L_VFCCU_FHFLTENC00_EN20_MASK)

#define L_VFCCU_FHFLTENC00_EN21_MASK             (0x200000U)
#define L_VFCCU_FHFLTENC00_EN21_SHIFT            (21U)
#define L_VFCCU_FHFLTENC00_EN21_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN21(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN21_SHIFT)) & L_VFCCU_FHFLTENC00_EN21_MASK)

#define L_VFCCU_FHFLTENC00_EN22_MASK             (0x400000U)
#define L_VFCCU_FHFLTENC00_EN22_SHIFT            (22U)
#define L_VFCCU_FHFLTENC00_EN22_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN22(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN22_SHIFT)) & L_VFCCU_FHFLTENC00_EN22_MASK)

#define L_VFCCU_FHFLTENC00_EN23_MASK             (0x800000U)
#define L_VFCCU_FHFLTENC00_EN23_SHIFT            (23U)
#define L_VFCCU_FHFLTENC00_EN23_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN23(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN23_SHIFT)) & L_VFCCU_FHFLTENC00_EN23_MASK)

#define L_VFCCU_FHFLTENC00_EN24_MASK             (0x1000000U)
#define L_VFCCU_FHFLTENC00_EN24_SHIFT            (24U)
#define L_VFCCU_FHFLTENC00_EN24_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN24(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN24_SHIFT)) & L_VFCCU_FHFLTENC00_EN24_MASK)

#define L_VFCCU_FHFLTENC00_EN25_MASK             (0x2000000U)
#define L_VFCCU_FHFLTENC00_EN25_SHIFT            (25U)
#define L_VFCCU_FHFLTENC00_EN25_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN25(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN25_SHIFT)) & L_VFCCU_FHFLTENC00_EN25_MASK)

#define L_VFCCU_FHFLTENC00_EN26_MASK             (0x4000000U)
#define L_VFCCU_FHFLTENC00_EN26_SHIFT            (26U)
#define L_VFCCU_FHFLTENC00_EN26_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN26(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN26_SHIFT)) & L_VFCCU_FHFLTENC00_EN26_MASK)

#define L_VFCCU_FHFLTENC00_EN27_MASK             (0x8000000U)
#define L_VFCCU_FHFLTENC00_EN27_SHIFT            (27U)
#define L_VFCCU_FHFLTENC00_EN27_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN27(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN27_SHIFT)) & L_VFCCU_FHFLTENC00_EN27_MASK)

#define L_VFCCU_FHFLTENC00_EN28_MASK             (0x10000000U)
#define L_VFCCU_FHFLTENC00_EN28_SHIFT            (28U)
#define L_VFCCU_FHFLTENC00_EN28_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN28(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN28_SHIFT)) & L_VFCCU_FHFLTENC00_EN28_MASK)

#define L_VFCCU_FHFLTENC00_EN29_MASK             (0x20000000U)
#define L_VFCCU_FHFLTENC00_EN29_SHIFT            (29U)
#define L_VFCCU_FHFLTENC00_EN29_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN29(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN29_SHIFT)) & L_VFCCU_FHFLTENC00_EN29_MASK)

#define L_VFCCU_FHFLTENC00_EN30_MASK             (0x40000000U)
#define L_VFCCU_FHFLTENC00_EN30_SHIFT            (30U)
#define L_VFCCU_FHFLTENC00_EN30_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN30(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN30_SHIFT)) & L_VFCCU_FHFLTENC00_EN30_MASK)

#define L_VFCCU_FHFLTENC00_EN31_MASK             (0x80000000U)
#define L_VFCCU_FHFLTENC00_EN31_SHIFT            (31U)
#define L_VFCCU_FHFLTENC00_EN31_WIDTH            (1U)
#define L_VFCCU_FHFLTENC00_EN31(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTENC00_EN31_SHIFT)) & L_VFCCU_FHFLTENC00_EN31_MASK)
/*! @} */

/*! @name FHFLTS00 - Fault Status */
/*! @{ */

#define L_VFCCU_FHFLTS00_STAT0_MASK              (0x1U)
#define L_VFCCU_FHFLTS00_STAT0_SHIFT             (0U)
#define L_VFCCU_FHFLTS00_STAT0_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT0(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT0_SHIFT)) & L_VFCCU_FHFLTS00_STAT0_MASK)

#define L_VFCCU_FHFLTS00_STAT1_MASK              (0x2U)
#define L_VFCCU_FHFLTS00_STAT1_SHIFT             (1U)
#define L_VFCCU_FHFLTS00_STAT1_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT1(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT1_SHIFT)) & L_VFCCU_FHFLTS00_STAT1_MASK)

#define L_VFCCU_FHFLTS00_STAT2_MASK              (0x4U)
#define L_VFCCU_FHFLTS00_STAT2_SHIFT             (2U)
#define L_VFCCU_FHFLTS00_STAT2_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT2(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT2_SHIFT)) & L_VFCCU_FHFLTS00_STAT2_MASK)

#define L_VFCCU_FHFLTS00_STAT3_MASK              (0x8U)
#define L_VFCCU_FHFLTS00_STAT3_SHIFT             (3U)
#define L_VFCCU_FHFLTS00_STAT3_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT3(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT3_SHIFT)) & L_VFCCU_FHFLTS00_STAT3_MASK)

#define L_VFCCU_FHFLTS00_STAT4_MASK              (0x10U)
#define L_VFCCU_FHFLTS00_STAT4_SHIFT             (4U)
#define L_VFCCU_FHFLTS00_STAT4_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT4(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT4_SHIFT)) & L_VFCCU_FHFLTS00_STAT4_MASK)

#define L_VFCCU_FHFLTS00_STAT5_MASK              (0x20U)
#define L_VFCCU_FHFLTS00_STAT5_SHIFT             (5U)
#define L_VFCCU_FHFLTS00_STAT5_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT5(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT5_SHIFT)) & L_VFCCU_FHFLTS00_STAT5_MASK)

#define L_VFCCU_FHFLTS00_STAT6_MASK              (0x40U)
#define L_VFCCU_FHFLTS00_STAT6_SHIFT             (6U)
#define L_VFCCU_FHFLTS00_STAT6_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT6(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT6_SHIFT)) & L_VFCCU_FHFLTS00_STAT6_MASK)

#define L_VFCCU_FHFLTS00_STAT7_MASK              (0x80U)
#define L_VFCCU_FHFLTS00_STAT7_SHIFT             (7U)
#define L_VFCCU_FHFLTS00_STAT7_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT7(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT7_SHIFT)) & L_VFCCU_FHFLTS00_STAT7_MASK)

#define L_VFCCU_FHFLTS00_STAT8_MASK              (0x100U)
#define L_VFCCU_FHFLTS00_STAT8_SHIFT             (8U)
#define L_VFCCU_FHFLTS00_STAT8_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT8(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT8_SHIFT)) & L_VFCCU_FHFLTS00_STAT8_MASK)

#define L_VFCCU_FHFLTS00_STAT9_MASK              (0x200U)
#define L_VFCCU_FHFLTS00_STAT9_SHIFT             (9U)
#define L_VFCCU_FHFLTS00_STAT9_WIDTH             (1U)
#define L_VFCCU_FHFLTS00_STAT9(x)                (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT9_SHIFT)) & L_VFCCU_FHFLTS00_STAT9_MASK)

#define L_VFCCU_FHFLTS00_STAT10_MASK             (0x400U)
#define L_VFCCU_FHFLTS00_STAT10_SHIFT            (10U)
#define L_VFCCU_FHFLTS00_STAT10_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT10(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT10_SHIFT)) & L_VFCCU_FHFLTS00_STAT10_MASK)

#define L_VFCCU_FHFLTS00_STAT11_MASK             (0x800U)
#define L_VFCCU_FHFLTS00_STAT11_SHIFT            (11U)
#define L_VFCCU_FHFLTS00_STAT11_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT11(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT11_SHIFT)) & L_VFCCU_FHFLTS00_STAT11_MASK)

#define L_VFCCU_FHFLTS00_STAT12_MASK             (0x1000U)
#define L_VFCCU_FHFLTS00_STAT12_SHIFT            (12U)
#define L_VFCCU_FHFLTS00_STAT12_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT12(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT12_SHIFT)) & L_VFCCU_FHFLTS00_STAT12_MASK)

#define L_VFCCU_FHFLTS00_STAT13_MASK             (0x2000U)
#define L_VFCCU_FHFLTS00_STAT13_SHIFT            (13U)
#define L_VFCCU_FHFLTS00_STAT13_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT13(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT13_SHIFT)) & L_VFCCU_FHFLTS00_STAT13_MASK)

#define L_VFCCU_FHFLTS00_STAT14_MASK             (0x4000U)
#define L_VFCCU_FHFLTS00_STAT14_SHIFT            (14U)
#define L_VFCCU_FHFLTS00_STAT14_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT14(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT14_SHIFT)) & L_VFCCU_FHFLTS00_STAT14_MASK)

#define L_VFCCU_FHFLTS00_STAT15_MASK             (0x8000U)
#define L_VFCCU_FHFLTS00_STAT15_SHIFT            (15U)
#define L_VFCCU_FHFLTS00_STAT15_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT15(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT15_SHIFT)) & L_VFCCU_FHFLTS00_STAT15_MASK)

#define L_VFCCU_FHFLTS00_STAT16_MASK             (0x10000U)
#define L_VFCCU_FHFLTS00_STAT16_SHIFT            (16U)
#define L_VFCCU_FHFLTS00_STAT16_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT16(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT16_SHIFT)) & L_VFCCU_FHFLTS00_STAT16_MASK)

#define L_VFCCU_FHFLTS00_STAT17_MASK             (0x20000U)
#define L_VFCCU_FHFLTS00_STAT17_SHIFT            (17U)
#define L_VFCCU_FHFLTS00_STAT17_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT17(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT17_SHIFT)) & L_VFCCU_FHFLTS00_STAT17_MASK)

#define L_VFCCU_FHFLTS00_STAT18_MASK             (0x40000U)
#define L_VFCCU_FHFLTS00_STAT18_SHIFT            (18U)
#define L_VFCCU_FHFLTS00_STAT18_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT18(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT18_SHIFT)) & L_VFCCU_FHFLTS00_STAT18_MASK)

#define L_VFCCU_FHFLTS00_STAT19_MASK             (0x80000U)
#define L_VFCCU_FHFLTS00_STAT19_SHIFT            (19U)
#define L_VFCCU_FHFLTS00_STAT19_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT19(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT19_SHIFT)) & L_VFCCU_FHFLTS00_STAT19_MASK)

#define L_VFCCU_FHFLTS00_STAT20_MASK             (0x100000U)
#define L_VFCCU_FHFLTS00_STAT20_SHIFT            (20U)
#define L_VFCCU_FHFLTS00_STAT20_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT20(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT20_SHIFT)) & L_VFCCU_FHFLTS00_STAT20_MASK)

#define L_VFCCU_FHFLTS00_STAT21_MASK             (0x200000U)
#define L_VFCCU_FHFLTS00_STAT21_SHIFT            (21U)
#define L_VFCCU_FHFLTS00_STAT21_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT21(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT21_SHIFT)) & L_VFCCU_FHFLTS00_STAT21_MASK)

#define L_VFCCU_FHFLTS00_STAT22_MASK             (0x400000U)
#define L_VFCCU_FHFLTS00_STAT22_SHIFT            (22U)
#define L_VFCCU_FHFLTS00_STAT22_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT22(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT22_SHIFT)) & L_VFCCU_FHFLTS00_STAT22_MASK)

#define L_VFCCU_FHFLTS00_STAT23_MASK             (0x800000U)
#define L_VFCCU_FHFLTS00_STAT23_SHIFT            (23U)
#define L_VFCCU_FHFLTS00_STAT23_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT23(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT23_SHIFT)) & L_VFCCU_FHFLTS00_STAT23_MASK)

#define L_VFCCU_FHFLTS00_STAT24_MASK             (0x1000000U)
#define L_VFCCU_FHFLTS00_STAT24_SHIFT            (24U)
#define L_VFCCU_FHFLTS00_STAT24_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT24(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT24_SHIFT)) & L_VFCCU_FHFLTS00_STAT24_MASK)

#define L_VFCCU_FHFLTS00_STAT25_MASK             (0x2000000U)
#define L_VFCCU_FHFLTS00_STAT25_SHIFT            (25U)
#define L_VFCCU_FHFLTS00_STAT25_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT25(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT25_SHIFT)) & L_VFCCU_FHFLTS00_STAT25_MASK)

#define L_VFCCU_FHFLTS00_STAT26_MASK             (0x4000000U)
#define L_VFCCU_FHFLTS00_STAT26_SHIFT            (26U)
#define L_VFCCU_FHFLTS00_STAT26_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT26(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT26_SHIFT)) & L_VFCCU_FHFLTS00_STAT26_MASK)

#define L_VFCCU_FHFLTS00_STAT27_MASK             (0x8000000U)
#define L_VFCCU_FHFLTS00_STAT27_SHIFT            (27U)
#define L_VFCCU_FHFLTS00_STAT27_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT27(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT27_SHIFT)) & L_VFCCU_FHFLTS00_STAT27_MASK)

#define L_VFCCU_FHFLTS00_STAT28_MASK             (0x10000000U)
#define L_VFCCU_FHFLTS00_STAT28_SHIFT            (28U)
#define L_VFCCU_FHFLTS00_STAT28_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT28(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT28_SHIFT)) & L_VFCCU_FHFLTS00_STAT28_MASK)

#define L_VFCCU_FHFLTS00_STAT29_MASK             (0x20000000U)
#define L_VFCCU_FHFLTS00_STAT29_SHIFT            (29U)
#define L_VFCCU_FHFLTS00_STAT29_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT29(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT29_SHIFT)) & L_VFCCU_FHFLTS00_STAT29_MASK)

#define L_VFCCU_FHFLTS00_STAT30_MASK             (0x40000000U)
#define L_VFCCU_FHFLTS00_STAT30_SHIFT            (30U)
#define L_VFCCU_FHFLTS00_STAT30_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT30(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT30_SHIFT)) & L_VFCCU_FHFLTS00_STAT30_MASK)

#define L_VFCCU_FHFLTS00_STAT31_MASK             (0x80000000U)
#define L_VFCCU_FHFLTS00_STAT31_SHIFT            (31U)
#define L_VFCCU_FHFLTS00_STAT31_WIDTH            (1U)
#define L_VFCCU_FHFLTS00_STAT31(x)               (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTS00_STAT31_SHIFT)) & L_VFCCU_FHFLTS00_STAT31_MASK)
/*! @} */

/*! @name FHFLTRKC00 - Fault Reaction Set Configuration */
/*! @{ */

#define L_VFCCU_FHFLTRKC00_RKNSEL0_MASK          (0x7U)
#define L_VFCCU_FHFLTRKC00_RKNSEL0_SHIFT         (0U)
#define L_VFCCU_FHFLTRKC00_RKNSEL0_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL0_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL0_MASK)

#define L_VFCCU_FHFLTRKC00_RKNSEL1_MASK          (0x70U)
#define L_VFCCU_FHFLTRKC00_RKNSEL1_SHIFT         (4U)
#define L_VFCCU_FHFLTRKC00_RKNSEL1_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL1_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL1_MASK)

#define L_VFCCU_FHFLTRKC00_RKNSEL2_MASK          (0x700U)
#define L_VFCCU_FHFLTRKC00_RKNSEL2_SHIFT         (8U)
#define L_VFCCU_FHFLTRKC00_RKNSEL2_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL2_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL2_MASK)

#define L_VFCCU_FHFLTRKC00_RKNSEL3_MASK          (0x7000U)
#define L_VFCCU_FHFLTRKC00_RKNSEL3_SHIFT         (12U)
#define L_VFCCU_FHFLTRKC00_RKNSEL3_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL3_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL3_MASK)

#define L_VFCCU_FHFLTRKC00_RKNSEL4_MASK          (0x70000U)
#define L_VFCCU_FHFLTRKC00_RKNSEL4_SHIFT         (16U)
#define L_VFCCU_FHFLTRKC00_RKNSEL4_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL4_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL4_MASK)

#define L_VFCCU_FHFLTRKC00_RKNSEL5_MASK          (0x700000U)
#define L_VFCCU_FHFLTRKC00_RKNSEL5_SHIFT         (20U)
#define L_VFCCU_FHFLTRKC00_RKNSEL5_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL5_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL5_MASK)

#define L_VFCCU_FHFLTRKC00_RKNSEL6_MASK          (0x7000000U)
#define L_VFCCU_FHFLTRKC00_RKNSEL6_SHIFT         (24U)
#define L_VFCCU_FHFLTRKC00_RKNSEL6_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL6(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL6_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL6_MASK)

#define L_VFCCU_FHFLTRKC00_RKNSEL7_MASK          (0x70000000U)
#define L_VFCCU_FHFLTRKC00_RKNSEL7_SHIFT         (28U)
#define L_VFCCU_FHFLTRKC00_RKNSEL7_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC00_RKNSEL7(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC00_RKNSEL7_SHIFT)) & L_VFCCU_FHFLTRKC00_RKNSEL7_MASK)
/*! @} */

/*! @name FHFLTRKC01 - Fault Reaction Set Configuration */
/*! @{ */

#define L_VFCCU_FHFLTRKC01_RKNSEL8_MASK          (0x7U)
#define L_VFCCU_FHFLTRKC01_RKNSEL8_SHIFT         (0U)
#define L_VFCCU_FHFLTRKC01_RKNSEL8_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL8(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL8_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL8_MASK)

#define L_VFCCU_FHFLTRKC01_RKNSEL9_MASK          (0x70U)
#define L_VFCCU_FHFLTRKC01_RKNSEL9_SHIFT         (4U)
#define L_VFCCU_FHFLTRKC01_RKNSEL9_WIDTH         (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL9(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL9_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL9_MASK)

#define L_VFCCU_FHFLTRKC01_RKNSEL10_MASK         (0x700U)
#define L_VFCCU_FHFLTRKC01_RKNSEL10_SHIFT        (8U)
#define L_VFCCU_FHFLTRKC01_RKNSEL10_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL10(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL10_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL10_MASK)

#define L_VFCCU_FHFLTRKC01_RKNSEL11_MASK         (0x7000U)
#define L_VFCCU_FHFLTRKC01_RKNSEL11_SHIFT        (12U)
#define L_VFCCU_FHFLTRKC01_RKNSEL11_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL11(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL11_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL11_MASK)

#define L_VFCCU_FHFLTRKC01_RKNSEL12_MASK         (0x70000U)
#define L_VFCCU_FHFLTRKC01_RKNSEL12_SHIFT        (16U)
#define L_VFCCU_FHFLTRKC01_RKNSEL12_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL12(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL12_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL12_MASK)

#define L_VFCCU_FHFLTRKC01_RKNSEL13_MASK         (0x700000U)
#define L_VFCCU_FHFLTRKC01_RKNSEL13_SHIFT        (20U)
#define L_VFCCU_FHFLTRKC01_RKNSEL13_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL13(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL13_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL13_MASK)

#define L_VFCCU_FHFLTRKC01_RKNSEL14_MASK         (0x7000000U)
#define L_VFCCU_FHFLTRKC01_RKNSEL14_SHIFT        (24U)
#define L_VFCCU_FHFLTRKC01_RKNSEL14_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL14(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL14_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL14_MASK)

#define L_VFCCU_FHFLTRKC01_RKNSEL15_MASK         (0x70000000U)
#define L_VFCCU_FHFLTRKC01_RKNSEL15_SHIFT        (28U)
#define L_VFCCU_FHFLTRKC01_RKNSEL15_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC01_RKNSEL15(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC01_RKNSEL15_SHIFT)) & L_VFCCU_FHFLTRKC01_RKNSEL15_MASK)
/*! @} */

/*! @name FHFLTRKC02 - Fault Reaction Set Configuration */
/*! @{ */

#define L_VFCCU_FHFLTRKC02_RKNSEL16_MASK         (0x7U)
#define L_VFCCU_FHFLTRKC02_RKNSEL16_SHIFT        (0U)
#define L_VFCCU_FHFLTRKC02_RKNSEL16_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL16(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL16_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL16_MASK)

#define L_VFCCU_FHFLTRKC02_RKNSEL17_MASK         (0x70U)
#define L_VFCCU_FHFLTRKC02_RKNSEL17_SHIFT        (4U)
#define L_VFCCU_FHFLTRKC02_RKNSEL17_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL17(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL17_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL17_MASK)

#define L_VFCCU_FHFLTRKC02_RKNSEL18_MASK         (0x700U)
#define L_VFCCU_FHFLTRKC02_RKNSEL18_SHIFT        (8U)
#define L_VFCCU_FHFLTRKC02_RKNSEL18_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL18(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL18_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL18_MASK)

#define L_VFCCU_FHFLTRKC02_RKNSEL19_MASK         (0x7000U)
#define L_VFCCU_FHFLTRKC02_RKNSEL19_SHIFT        (12U)
#define L_VFCCU_FHFLTRKC02_RKNSEL19_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL19(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL19_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL19_MASK)

#define L_VFCCU_FHFLTRKC02_RKNSEL20_MASK         (0x70000U)
#define L_VFCCU_FHFLTRKC02_RKNSEL20_SHIFT        (16U)
#define L_VFCCU_FHFLTRKC02_RKNSEL20_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL20(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL20_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL20_MASK)

#define L_VFCCU_FHFLTRKC02_RKNSEL21_MASK         (0x700000U)
#define L_VFCCU_FHFLTRKC02_RKNSEL21_SHIFT        (20U)
#define L_VFCCU_FHFLTRKC02_RKNSEL21_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL21(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL21_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL21_MASK)

#define L_VFCCU_FHFLTRKC02_RKNSEL22_MASK         (0x7000000U)
#define L_VFCCU_FHFLTRKC02_RKNSEL22_SHIFT        (24U)
#define L_VFCCU_FHFLTRKC02_RKNSEL22_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL22(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL22_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL22_MASK)

#define L_VFCCU_FHFLTRKC02_RKNSEL23_MASK         (0x70000000U)
#define L_VFCCU_FHFLTRKC02_RKNSEL23_SHIFT        (28U)
#define L_VFCCU_FHFLTRKC02_RKNSEL23_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC02_RKNSEL23(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC02_RKNSEL23_SHIFT)) & L_VFCCU_FHFLTRKC02_RKNSEL23_MASK)
/*! @} */

/*! @name FHFLTRKC03 - Fault Reaction Set Configuration */
/*! @{ */

#define L_VFCCU_FHFLTRKC03_RKNSEL24_MASK         (0x7U)
#define L_VFCCU_FHFLTRKC03_RKNSEL24_SHIFT        (0U)
#define L_VFCCU_FHFLTRKC03_RKNSEL24_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL24(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL24_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL24_MASK)

#define L_VFCCU_FHFLTRKC03_RKNSEL25_MASK         (0x70U)
#define L_VFCCU_FHFLTRKC03_RKNSEL25_SHIFT        (4U)
#define L_VFCCU_FHFLTRKC03_RKNSEL25_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL25(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL25_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL25_MASK)

#define L_VFCCU_FHFLTRKC03_RKNSEL26_MASK         (0x700U)
#define L_VFCCU_FHFLTRKC03_RKNSEL26_SHIFT        (8U)
#define L_VFCCU_FHFLTRKC03_RKNSEL26_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL26(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL26_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL26_MASK)

#define L_VFCCU_FHFLTRKC03_RKNSEL27_MASK         (0x7000U)
#define L_VFCCU_FHFLTRKC03_RKNSEL27_SHIFT        (12U)
#define L_VFCCU_FHFLTRKC03_RKNSEL27_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL27(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL27_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL27_MASK)

#define L_VFCCU_FHFLTRKC03_RKNSEL28_MASK         (0x70000U)
#define L_VFCCU_FHFLTRKC03_RKNSEL28_SHIFT        (16U)
#define L_VFCCU_FHFLTRKC03_RKNSEL28_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL28(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL28_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL28_MASK)

#define L_VFCCU_FHFLTRKC03_RKNSEL29_MASK         (0x700000U)
#define L_VFCCU_FHFLTRKC03_RKNSEL29_SHIFT        (20U)
#define L_VFCCU_FHFLTRKC03_RKNSEL29_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL29(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL29_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL29_MASK)

#define L_VFCCU_FHFLTRKC03_RKNSEL30_MASK         (0x7000000U)
#define L_VFCCU_FHFLTRKC03_RKNSEL30_SHIFT        (24U)
#define L_VFCCU_FHFLTRKC03_RKNSEL30_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL30(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL30_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL30_MASK)

#define L_VFCCU_FHFLTRKC03_RKNSEL31_MASK         (0x70000000U)
#define L_VFCCU_FHFLTRKC03_RKNSEL31_SHIFT        (28U)
#define L_VFCCU_FHFLTRKC03_RKNSEL31_WIDTH        (3U)
#define L_VFCCU_FHFLTRKC03_RKNSEL31(x)           (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHFLTRKC03_RKNSEL31_SHIFT)) & L_VFCCU_FHFLTRKC03_RKNSEL31_MASK)
/*! @} */

/*! @name FHIMRKC0_00 - Immediate Reaction Configuration */
/*! @{ */

#define L_VFCCU_FHIMRKC0_00_RKNEN0_MASK          (0x1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN0_SHIFT         (0U)
#define L_VFCCU_FHIMRKC0_00_RKNEN0_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_00_RKNEN0_SHIFT)) & L_VFCCU_FHIMRKC0_00_RKNEN0_MASK)

#define L_VFCCU_FHIMRKC0_00_RKNEN1_MASK          (0x2U)
#define L_VFCCU_FHIMRKC0_00_RKNEN1_SHIFT         (1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN1_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_00_RKNEN1_SHIFT)) & L_VFCCU_FHIMRKC0_00_RKNEN1_MASK)

#define L_VFCCU_FHIMRKC0_00_RKNEN2_MASK          (0x4U)
#define L_VFCCU_FHIMRKC0_00_RKNEN2_SHIFT         (2U)
#define L_VFCCU_FHIMRKC0_00_RKNEN2_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_00_RKNEN2_SHIFT)) & L_VFCCU_FHIMRKC0_00_RKNEN2_MASK)

#define L_VFCCU_FHIMRKC0_00_RKNEN3_MASK          (0x8U)
#define L_VFCCU_FHIMRKC0_00_RKNEN3_SHIFT         (3U)
#define L_VFCCU_FHIMRKC0_00_RKNEN3_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_00_RKNEN3_SHIFT)) & L_VFCCU_FHIMRKC0_00_RKNEN3_MASK)

#define L_VFCCU_FHIMRKC0_00_RKNEN4_MASK          (0x10U)
#define L_VFCCU_FHIMRKC0_00_RKNEN4_SHIFT         (4U)
#define L_VFCCU_FHIMRKC0_00_RKNEN4_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_00_RKNEN4_SHIFT)) & L_VFCCU_FHIMRKC0_00_RKNEN4_MASK)

#define L_VFCCU_FHIMRKC0_00_RKNEN5_MASK          (0x20U)
#define L_VFCCU_FHIMRKC0_00_RKNEN5_SHIFT         (5U)
#define L_VFCCU_FHIMRKC0_00_RKNEN5_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_00_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_00_RKNEN5_SHIFT)) & L_VFCCU_FHIMRKC0_00_RKNEN5_MASK)
/*! @} */

/*! @name FHIMRKC0_10 - Immediate Reaction Configuration */
/*! @{ */

#define L_VFCCU_FHIMRKC0_10_RKNEN0_MASK          (0x1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN0_SHIFT         (0U)
#define L_VFCCU_FHIMRKC0_10_RKNEN0_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_10_RKNEN0_SHIFT)) & L_VFCCU_FHIMRKC0_10_RKNEN0_MASK)

#define L_VFCCU_FHIMRKC0_10_RKNEN1_MASK          (0x2U)
#define L_VFCCU_FHIMRKC0_10_RKNEN1_SHIFT         (1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN1_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_10_RKNEN1_SHIFT)) & L_VFCCU_FHIMRKC0_10_RKNEN1_MASK)

#define L_VFCCU_FHIMRKC0_10_RKNEN2_MASK          (0x4U)
#define L_VFCCU_FHIMRKC0_10_RKNEN2_SHIFT         (2U)
#define L_VFCCU_FHIMRKC0_10_RKNEN2_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_10_RKNEN2_SHIFT)) & L_VFCCU_FHIMRKC0_10_RKNEN2_MASK)

#define L_VFCCU_FHIMRKC0_10_RKNEN3_MASK          (0x8U)
#define L_VFCCU_FHIMRKC0_10_RKNEN3_SHIFT         (3U)
#define L_VFCCU_FHIMRKC0_10_RKNEN3_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_10_RKNEN3_SHIFT)) & L_VFCCU_FHIMRKC0_10_RKNEN3_MASK)

#define L_VFCCU_FHIMRKC0_10_RKNEN4_MASK          (0x10U)
#define L_VFCCU_FHIMRKC0_10_RKNEN4_SHIFT         (4U)
#define L_VFCCU_FHIMRKC0_10_RKNEN4_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_10_RKNEN4_SHIFT)) & L_VFCCU_FHIMRKC0_10_RKNEN4_MASK)

#define L_VFCCU_FHIMRKC0_10_RKNEN5_MASK          (0x20U)
#define L_VFCCU_FHIMRKC0_10_RKNEN5_SHIFT         (5U)
#define L_VFCCU_FHIMRKC0_10_RKNEN5_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_10_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_10_RKNEN5_SHIFT)) & L_VFCCU_FHIMRKC0_10_RKNEN5_MASK)
/*! @} */

/*! @name FHIMRKC0_20 - Immediate Reaction Configuration */
/*! @{ */

#define L_VFCCU_FHIMRKC0_20_RKNEN0_MASK          (0x1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN0_SHIFT         (0U)
#define L_VFCCU_FHIMRKC0_20_RKNEN0_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_20_RKNEN0_SHIFT)) & L_VFCCU_FHIMRKC0_20_RKNEN0_MASK)

#define L_VFCCU_FHIMRKC0_20_RKNEN1_MASK          (0x2U)
#define L_VFCCU_FHIMRKC0_20_RKNEN1_SHIFT         (1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN1_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_20_RKNEN1_SHIFT)) & L_VFCCU_FHIMRKC0_20_RKNEN1_MASK)

#define L_VFCCU_FHIMRKC0_20_RKNEN2_MASK          (0x4U)
#define L_VFCCU_FHIMRKC0_20_RKNEN2_SHIFT         (2U)
#define L_VFCCU_FHIMRKC0_20_RKNEN2_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_20_RKNEN2_SHIFT)) & L_VFCCU_FHIMRKC0_20_RKNEN2_MASK)

#define L_VFCCU_FHIMRKC0_20_RKNEN3_MASK          (0x8U)
#define L_VFCCU_FHIMRKC0_20_RKNEN3_SHIFT         (3U)
#define L_VFCCU_FHIMRKC0_20_RKNEN3_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_20_RKNEN3_SHIFT)) & L_VFCCU_FHIMRKC0_20_RKNEN3_MASK)

#define L_VFCCU_FHIMRKC0_20_RKNEN4_MASK          (0x10U)
#define L_VFCCU_FHIMRKC0_20_RKNEN4_SHIFT         (4U)
#define L_VFCCU_FHIMRKC0_20_RKNEN4_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_20_RKNEN4_SHIFT)) & L_VFCCU_FHIMRKC0_20_RKNEN4_MASK)

#define L_VFCCU_FHIMRKC0_20_RKNEN5_MASK          (0x20U)
#define L_VFCCU_FHIMRKC0_20_RKNEN5_SHIFT         (5U)
#define L_VFCCU_FHIMRKC0_20_RKNEN5_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_20_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_20_RKNEN5_SHIFT)) & L_VFCCU_FHIMRKC0_20_RKNEN5_MASK)
/*! @} */

/*! @name FHIMRKC0_30 - Immediate Reaction Configuration */
/*! @{ */

#define L_VFCCU_FHIMRKC0_30_RKNEN0_MASK          (0x1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN0_SHIFT         (0U)
#define L_VFCCU_FHIMRKC0_30_RKNEN0_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_30_RKNEN0_SHIFT)) & L_VFCCU_FHIMRKC0_30_RKNEN0_MASK)

#define L_VFCCU_FHIMRKC0_30_RKNEN1_MASK          (0x2U)
#define L_VFCCU_FHIMRKC0_30_RKNEN1_SHIFT         (1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN1_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_30_RKNEN1_SHIFT)) & L_VFCCU_FHIMRKC0_30_RKNEN1_MASK)

#define L_VFCCU_FHIMRKC0_30_RKNEN2_MASK          (0x4U)
#define L_VFCCU_FHIMRKC0_30_RKNEN2_SHIFT         (2U)
#define L_VFCCU_FHIMRKC0_30_RKNEN2_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_30_RKNEN2_SHIFT)) & L_VFCCU_FHIMRKC0_30_RKNEN2_MASK)

#define L_VFCCU_FHIMRKC0_30_RKNEN3_MASK          (0x8U)
#define L_VFCCU_FHIMRKC0_30_RKNEN3_SHIFT         (3U)
#define L_VFCCU_FHIMRKC0_30_RKNEN3_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_30_RKNEN3_SHIFT)) & L_VFCCU_FHIMRKC0_30_RKNEN3_MASK)

#define L_VFCCU_FHIMRKC0_30_RKNEN4_MASK          (0x10U)
#define L_VFCCU_FHIMRKC0_30_RKNEN4_SHIFT         (4U)
#define L_VFCCU_FHIMRKC0_30_RKNEN4_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_30_RKNEN4_SHIFT)) & L_VFCCU_FHIMRKC0_30_RKNEN4_MASK)

#define L_VFCCU_FHIMRKC0_30_RKNEN5_MASK          (0x20U)
#define L_VFCCU_FHIMRKC0_30_RKNEN5_SHIFT         (5U)
#define L_VFCCU_FHIMRKC0_30_RKNEN5_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_30_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_30_RKNEN5_SHIFT)) & L_VFCCU_FHIMRKC0_30_RKNEN5_MASK)
/*! @} */

/*! @name FHIMRKC0_40 - Immediate Reaction Configuration */
/*! @{ */

#define L_VFCCU_FHIMRKC0_40_RKNEN0_MASK          (0x1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN0_SHIFT         (0U)
#define L_VFCCU_FHIMRKC0_40_RKNEN0_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_40_RKNEN0_SHIFT)) & L_VFCCU_FHIMRKC0_40_RKNEN0_MASK)

#define L_VFCCU_FHIMRKC0_40_RKNEN1_MASK          (0x2U)
#define L_VFCCU_FHIMRKC0_40_RKNEN1_SHIFT         (1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN1_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_40_RKNEN1_SHIFT)) & L_VFCCU_FHIMRKC0_40_RKNEN1_MASK)

#define L_VFCCU_FHIMRKC0_40_RKNEN2_MASK          (0x4U)
#define L_VFCCU_FHIMRKC0_40_RKNEN2_SHIFT         (2U)
#define L_VFCCU_FHIMRKC0_40_RKNEN2_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_40_RKNEN2_SHIFT)) & L_VFCCU_FHIMRKC0_40_RKNEN2_MASK)

#define L_VFCCU_FHIMRKC0_40_RKNEN3_MASK          (0x8U)
#define L_VFCCU_FHIMRKC0_40_RKNEN3_SHIFT         (3U)
#define L_VFCCU_FHIMRKC0_40_RKNEN3_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_40_RKNEN3_SHIFT)) & L_VFCCU_FHIMRKC0_40_RKNEN3_MASK)

#define L_VFCCU_FHIMRKC0_40_RKNEN4_MASK          (0x10U)
#define L_VFCCU_FHIMRKC0_40_RKNEN4_SHIFT         (4U)
#define L_VFCCU_FHIMRKC0_40_RKNEN4_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_40_RKNEN4_SHIFT)) & L_VFCCU_FHIMRKC0_40_RKNEN4_MASK)

#define L_VFCCU_FHIMRKC0_40_RKNEN5_MASK          (0x20U)
#define L_VFCCU_FHIMRKC0_40_RKNEN5_SHIFT         (5U)
#define L_VFCCU_FHIMRKC0_40_RKNEN5_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_40_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_40_RKNEN5_SHIFT)) & L_VFCCU_FHIMRKC0_40_RKNEN5_MASK)
/*! @} */

/*! @name FHIMRKC0_50 - Immediate Reaction Configuration */
/*! @{ */

#define L_VFCCU_FHIMRKC0_50_RKNEN0_MASK          (0x1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN0_SHIFT         (0U)
#define L_VFCCU_FHIMRKC0_50_RKNEN0_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_50_RKNEN0_SHIFT)) & L_VFCCU_FHIMRKC0_50_RKNEN0_MASK)

#define L_VFCCU_FHIMRKC0_50_RKNEN1_MASK          (0x2U)
#define L_VFCCU_FHIMRKC0_50_RKNEN1_SHIFT         (1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN1_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_50_RKNEN1_SHIFT)) & L_VFCCU_FHIMRKC0_50_RKNEN1_MASK)

#define L_VFCCU_FHIMRKC0_50_RKNEN2_MASK          (0x4U)
#define L_VFCCU_FHIMRKC0_50_RKNEN2_SHIFT         (2U)
#define L_VFCCU_FHIMRKC0_50_RKNEN2_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_50_RKNEN2_SHIFT)) & L_VFCCU_FHIMRKC0_50_RKNEN2_MASK)

#define L_VFCCU_FHIMRKC0_50_RKNEN3_MASK          (0x8U)
#define L_VFCCU_FHIMRKC0_50_RKNEN3_SHIFT         (3U)
#define L_VFCCU_FHIMRKC0_50_RKNEN3_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_50_RKNEN3_SHIFT)) & L_VFCCU_FHIMRKC0_50_RKNEN3_MASK)

#define L_VFCCU_FHIMRKC0_50_RKNEN4_MASK          (0x10U)
#define L_VFCCU_FHIMRKC0_50_RKNEN4_SHIFT         (4U)
#define L_VFCCU_FHIMRKC0_50_RKNEN4_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_50_RKNEN4_SHIFT)) & L_VFCCU_FHIMRKC0_50_RKNEN4_MASK)

#define L_VFCCU_FHIMRKC0_50_RKNEN5_MASK          (0x20U)
#define L_VFCCU_FHIMRKC0_50_RKNEN5_SHIFT         (5U)
#define L_VFCCU_FHIMRKC0_50_RKNEN5_WIDTH         (1U)
#define L_VFCCU_FHIMRKC0_50_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << L_VFCCU_FHIMRKC0_50_RKNEN5_SHIFT)) & L_VFCCU_FHIMRKC0_50_RKNEN5_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group L_VFCCU_Register_Masks */

/*!
 * @}
 */ /* end of group L_VFCCU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_L_VFCCU_H_) */
