/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_VFCCU_1.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_VFCCU_1
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
#if !defined(S32K566_VFCCU_1_H_)  /* Check if memory map has not been already included */
#define S32K566_VFCCU_1_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- VFCCU_1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VFCCU_1_Peripheral_Access_Layer VFCCU_1 Peripheral Access Layer
 * @{
 */

/** VFCCU_1 - Register Layout Typedef */
typedef struct VFCCU_1_Struct {
  uint8_t RESERVED_0[1024];
  __IO uint32_t GFLTPO_C0;                         /**< Global Fault Polarity, offset: 0x400 */
  __IO uint32_t GFLTPO_C1;                         /**< Global Fault Polarity, offset: 0x404 */
  __IO uint32_t GFLTPO_C2;                         /**< Global Fault Polarity, offset: 0x408 */
  __IO uint32_t GFLTPO_C3;                         /**< Global Fault Polarity, offset: 0x40C */
  uint8_t RESERVED_1[48];
  __IO uint32_t GFLTRC_C0;                         /**< Global Fault Recovery, offset: 0x440 */
  __IO uint32_t GFLTRC_C1;                         /**< Global Fault Recovery, offset: 0x444 */
  __IO uint32_t GFLTRC_C2;                         /**< Global Fault Recovery, offset: 0x448 */
  __IO uint32_t GFLTRC_C3;                         /**< Global Fault Recovery, offset: 0x44C */
  uint8_t RESERVED_2[2232];
  __I  uint32_t GINTOVFS;                          /**< Global DID FSM Status, offset: 0xD08 */
  uint8_t RESERVED_3[676];
  __IO uint32_t GDBGCFG;                           /**< Global Debug, offset: 0xFB0 */
  __I  uint32_t GDBGSTAT;                          /**< Global Debug Status, offset: 0xFB4 */
  uint8_t RESERVED_4[72];
  __IO uint32_t FHCFG0;                            /**< Fault Handler, offset: 0x1000 */
  __I  uint32_t FHSRVDS0;                          /**< Fault Handler Status, offset: 0x1004 */
  uint8_t RESERVED_5[8];
  __IO uint32_t FHFLTENC0_0;                       /**< Fault Enable, offset: 0x1010 */
  __IO uint32_t FHFLTENC0_1;                       /**< Fault Enable, offset: 0x1014 */
  __IO uint32_t FHFLTENC0_2;                       /**< Fault Enable, offset: 0x1018 */
  __IO uint32_t FHFLTENC0_3;                       /**< Fault Enable, offset: 0x101C */
  uint8_t RESERVED_6[48];
  __IO uint32_t FHFLTS0_0;                         /**< Fault Status, offset: 0x1050 */
  __IO uint32_t FHFLTS0_1;                         /**< Fault Status, offset: 0x1054 */
  __IO uint32_t FHFLTS0_2;                         /**< Fault Status, offset: 0x1058 */
  __IO uint32_t FHFLTS0_3;                         /**< Fault Status, offset: 0x105C */
  uint8_t RESERVED_7[48];
  __IO uint32_t FHFLTRKC0_0;                       /**< Fault Reaction Set Configuration, offset: 0x1090 */
  __IO uint32_t FHFLTRKC0_1;                       /**< Fault Reaction Set Configuration, offset: 0x1094 */
  __IO uint32_t FHFLTRKC0_2;                       /**< Fault Reaction Set Configuration, offset: 0x1098 */
  __IO uint32_t FHFLTRKC0_3;                       /**< Fault Reaction Set Configuration, offset: 0x109C */
  __IO uint32_t FHFLTRKC0_4;                       /**< Fault Reaction Set Configuration, offset: 0x10A0 */
  __IO uint32_t FHFLTRKC0_5;                       /**< Fault Reaction Set Configuration, offset: 0x10A4 */
  __IO uint32_t FHFLTRKC0_6;                       /**< Fault Reaction Set Configuration, offset: 0x10A8 */
  __IO uint32_t FHFLTRKC0_7;                       /**< Fault Reaction Set Configuration, offset: 0x10AC */
  __IO uint32_t FHFLTRKC0_8;                       /**< Fault Reaction Set Configuration, offset: 0x10B0 */
  __IO uint32_t FHFLTRKC0_9;                       /**< Fault Reaction Set Configuration, offset: 0x10B4 */
  __IO uint32_t FHFLTRKC0_10;                      /**< Fault Reaction Set Configuration, offset: 0x10B8 */
  __IO uint32_t FHFLTRKC0_11;                      /**< Fault Reaction Set Configuration, offset: 0x10BC */
  __IO uint32_t FHFLTRKC0_12;                      /**< Fault Reaction Set Configuration, offset: 0x10C0 */
  __IO uint32_t FHFLTRKC0_13;                      /**< Fault Reaction Set Configuration, offset: 0x10C4 */
  __IO uint32_t FHFLTRKC0_14;                      /**< Fault Reaction Set Configuration, offset: 0x10C8 */
  __IO uint32_t FHFLTRKC0_15;                      /**< Fault Reaction Set Configuration, offset: 0x10CC */
  __IO uint32_t FHFLTRKC0_16;                      /**< Fault Reaction Set Configuration, offset: 0x10D0 */
  __IO uint32_t FHFLTRKC0_17;                      /**< Fault Reaction Set Configuration, offset: 0x10D4 */
  __IO uint32_t FHFLTRKC0_18;                      /**< Fault Reaction Set Configuration, offset: 0x10D8 */
  __IO uint32_t FHFLTRKC0_19;                      /**< Fault Reaction Set Configuration, offset: 0x10DC */
  __IO uint32_t FHFLTRKC0_20;                      /**< Fault Reaction Set Configuration, offset: 0x10E0 */
  __IO uint32_t FHFLTRKC0_21;                      /**< Fault Reaction Set Configuration, offset: 0x10E4 */
  __IO uint32_t FHFLTRKC0_22;                      /**< Fault Reaction Set Configuration, offset: 0x10E8 */
  __IO uint32_t FHFLTRKC0_23;                      /**< Fault Reaction Set Configuration, offset: 0x10EC */
  __IO uint32_t FHFLTRKC0_24;                      /**< Fault Reaction Set Configuration, offset: 0x10F0 */
  __IO uint32_t FHFLTRKC0_25;                      /**< Fault Reaction Set Configuration, offset: 0x10F4 */
  __IO uint32_t FHFLTRKC0_26;                      /**< Fault Reaction Set Configuration, offset: 0x10F8 */
  __IO uint32_t FHFLTRKC0_27;                      /**< Fault Reaction Set Configuration, offset: 0x10FC */
  __IO uint32_t FHFLTRKC0_28;                      /**< Fault Reaction Set Configuration, offset: 0x1100 */
  __IO uint32_t FHFLTRKC0_29;                      /**< Fault Reaction Set Configuration, offset: 0x1104 */
  __IO uint32_t FHFLTRKC0_30;                      /**< Fault Reaction Set Configuration, offset: 0x1108 */
  __IO uint32_t FHFLTRKC0_31;                      /**< Fault Reaction Set Configuration, offset: 0x110C */
  uint8_t RESERVED_8[384];
  __IO uint32_t FHIMRKC0_00;                       /**< Immediate Reaction Configuration, offset: 0x1290 */
  uint8_t RESERVED_9[28];
  __IO uint32_t FHIMRKC0_10;                       /**< Immediate Reaction Configuration, offset: 0x12B0 */
  uint8_t RESERVED_10[28];
  __IO uint32_t FHIMRKC0_20;                       /**< Immediate Reaction Configuration, offset: 0x12D0 */
  uint8_t RESERVED_11[28];
  __IO uint32_t FHIMRKC0_30;                       /**< Immediate Reaction Configuration, offset: 0x12F0 */
  uint8_t RESERVED_12[28];
  __IO uint32_t FHIMRKC0_40;                       /**< Immediate Reaction Configuration, offset: 0x1310 */
  uint8_t RESERVED_13[28];
  __IO uint32_t FHIMRKC0_50;                       /**< Immediate Reaction Configuration, offset: 0x1330 */
  uint8_t RESERVED_14[28];
  __IO uint32_t FHIMRKC0_60;                       /**< Immediate Reaction Configuration, offset: 0x1350 */
  uint8_t RESERVED_15[28];
  __IO uint32_t FHIMRKC0_70;                       /**< Immediate Reaction Configuration, offset: 0x1370 */
  uint8_t RESERVED_16[28];
  __IO uint32_t FHIMRKC0_80;                       /**< Immediate Reaction Configuration, offset: 0x1390 */
  uint8_t RESERVED_17[28];
  __IO uint32_t FHIMRKC0_90;                       /**< Immediate Reaction Configuration, offset: 0x13B0 */
  uint8_t RESERVED_18[28];
  __IO uint32_t FHIMRKC0_100;                      /**< Immediate Reaction Configuration, offset: 0x13D0 */
  uint8_t RESERVED_19[28];
  __IO uint32_t FHIMRKC0_110;                      /**< Immediate Reaction Configuration, offset: 0x13F0 */
  uint8_t RESERVED_20[28];
  __IO uint32_t FHIMRKC0_120;                      /**< Immediate Reaction Configuration, offset: 0x1410 */
  uint8_t RESERVED_21[28];
  __IO uint32_t FHIMRKC0_130;                      /**< Immediate Reaction Configuration, offset: 0x1430 */
  uint8_t RESERVED_22[28];
  __IO uint32_t FHIMRKC0_140;                      /**< Immediate Reaction Configuration, offset: 0x1450 */
  uint8_t RESERVED_23[28];
  __IO uint32_t FHIMRKC0_150;                      /**< Immediate Reaction Configuration, offset: 0x1470 */
} VFCCU_1_Type, *VFCCU_1_MemMapPtr;

/** Number of instances of the VFCCU_1 module. */
#define VFCCU_1_INSTANCE_COUNT                   (1u)

/* VFCCU_1 - Peripheral instance base addresses */
/** Peripheral VFCCU_1 base address */
#define IP_VFCCU_1_BASE                          (0x40B68000u)
/** Peripheral VFCCU_1 base pointer */
#define IP_VFCCU_1                               ((VFCCU_1_Type *)IP_VFCCU_1_BASE)
/** Array initializer of VFCCU_1 peripheral base addresses */
#define IP_VFCCU_1_BASE_ADDRS                    { IP_VFCCU_1_BASE }
/** Array initializer of VFCCU_1 peripheral base pointers */
#define IP_VFCCU_1_BASE_PTRS                     { IP_VFCCU_1 }

/* ----------------------------------------------------------------------------
   -- VFCCU_1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VFCCU_1_Register_Masks VFCCU_1 Register Masks
 * @{
 */

/*! @name GFLTPO_C0 - Global Fault Polarity */
/*! @{ */

#define VFCCU_1_GFLTPO_C0_PS0_MASK               (0x1U)
#define VFCCU_1_GFLTPO_C0_PS0_SHIFT              (0U)
#define VFCCU_1_GFLTPO_C0_PS0_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS0(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS0_SHIFT)) & VFCCU_1_GFLTPO_C0_PS0_MASK)

#define VFCCU_1_GFLTPO_C0_PS1_MASK               (0x2U)
#define VFCCU_1_GFLTPO_C0_PS1_SHIFT              (1U)
#define VFCCU_1_GFLTPO_C0_PS1_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS1(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS1_SHIFT)) & VFCCU_1_GFLTPO_C0_PS1_MASK)

#define VFCCU_1_GFLTPO_C0_PS2_MASK               (0x4U)
#define VFCCU_1_GFLTPO_C0_PS2_SHIFT              (2U)
#define VFCCU_1_GFLTPO_C0_PS2_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS2(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS2_SHIFT)) & VFCCU_1_GFLTPO_C0_PS2_MASK)

#define VFCCU_1_GFLTPO_C0_PS3_MASK               (0x8U)
#define VFCCU_1_GFLTPO_C0_PS3_SHIFT              (3U)
#define VFCCU_1_GFLTPO_C0_PS3_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS3(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS3_SHIFT)) & VFCCU_1_GFLTPO_C0_PS3_MASK)

#define VFCCU_1_GFLTPO_C0_PS4_MASK               (0x10U)
#define VFCCU_1_GFLTPO_C0_PS4_SHIFT              (4U)
#define VFCCU_1_GFLTPO_C0_PS4_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS4(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS4_SHIFT)) & VFCCU_1_GFLTPO_C0_PS4_MASK)

#define VFCCU_1_GFLTPO_C0_PS5_MASK               (0x20U)
#define VFCCU_1_GFLTPO_C0_PS5_SHIFT              (5U)
#define VFCCU_1_GFLTPO_C0_PS5_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS5(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS5_SHIFT)) & VFCCU_1_GFLTPO_C0_PS5_MASK)

#define VFCCU_1_GFLTPO_C0_PS6_MASK               (0x40U)
#define VFCCU_1_GFLTPO_C0_PS6_SHIFT              (6U)
#define VFCCU_1_GFLTPO_C0_PS6_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS6(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS6_SHIFT)) & VFCCU_1_GFLTPO_C0_PS6_MASK)

#define VFCCU_1_GFLTPO_C0_PS7_MASK               (0x80U)
#define VFCCU_1_GFLTPO_C0_PS7_SHIFT              (7U)
#define VFCCU_1_GFLTPO_C0_PS7_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS7(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS7_SHIFT)) & VFCCU_1_GFLTPO_C0_PS7_MASK)

#define VFCCU_1_GFLTPO_C0_PS8_MASK               (0x100U)
#define VFCCU_1_GFLTPO_C0_PS8_SHIFT              (8U)
#define VFCCU_1_GFLTPO_C0_PS8_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS8(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS8_SHIFT)) & VFCCU_1_GFLTPO_C0_PS8_MASK)

#define VFCCU_1_GFLTPO_C0_PS9_MASK               (0x200U)
#define VFCCU_1_GFLTPO_C0_PS9_SHIFT              (9U)
#define VFCCU_1_GFLTPO_C0_PS9_WIDTH              (1U)
#define VFCCU_1_GFLTPO_C0_PS9(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS9_SHIFT)) & VFCCU_1_GFLTPO_C0_PS9_MASK)

#define VFCCU_1_GFLTPO_C0_PS10_MASK              (0x400U)
#define VFCCU_1_GFLTPO_C0_PS10_SHIFT             (10U)
#define VFCCU_1_GFLTPO_C0_PS10_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS10(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS10_SHIFT)) & VFCCU_1_GFLTPO_C0_PS10_MASK)

#define VFCCU_1_GFLTPO_C0_PS11_MASK              (0x800U)
#define VFCCU_1_GFLTPO_C0_PS11_SHIFT             (11U)
#define VFCCU_1_GFLTPO_C0_PS11_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS11(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS11_SHIFT)) & VFCCU_1_GFLTPO_C0_PS11_MASK)

#define VFCCU_1_GFLTPO_C0_PS12_MASK              (0x1000U)
#define VFCCU_1_GFLTPO_C0_PS12_SHIFT             (12U)
#define VFCCU_1_GFLTPO_C0_PS12_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS12(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS12_SHIFT)) & VFCCU_1_GFLTPO_C0_PS12_MASK)

#define VFCCU_1_GFLTPO_C0_PS13_MASK              (0x2000U)
#define VFCCU_1_GFLTPO_C0_PS13_SHIFT             (13U)
#define VFCCU_1_GFLTPO_C0_PS13_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS13(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS13_SHIFT)) & VFCCU_1_GFLTPO_C0_PS13_MASK)

#define VFCCU_1_GFLTPO_C0_PS14_MASK              (0x4000U)
#define VFCCU_1_GFLTPO_C0_PS14_SHIFT             (14U)
#define VFCCU_1_GFLTPO_C0_PS14_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS14(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS14_SHIFT)) & VFCCU_1_GFLTPO_C0_PS14_MASK)

#define VFCCU_1_GFLTPO_C0_PS15_MASK              (0x8000U)
#define VFCCU_1_GFLTPO_C0_PS15_SHIFT             (15U)
#define VFCCU_1_GFLTPO_C0_PS15_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS15(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS15_SHIFT)) & VFCCU_1_GFLTPO_C0_PS15_MASK)

#define VFCCU_1_GFLTPO_C0_PS16_MASK              (0x10000U)
#define VFCCU_1_GFLTPO_C0_PS16_SHIFT             (16U)
#define VFCCU_1_GFLTPO_C0_PS16_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS16(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS16_SHIFT)) & VFCCU_1_GFLTPO_C0_PS16_MASK)

#define VFCCU_1_GFLTPO_C0_PS17_MASK              (0x20000U)
#define VFCCU_1_GFLTPO_C0_PS17_SHIFT             (17U)
#define VFCCU_1_GFLTPO_C0_PS17_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS17(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS17_SHIFT)) & VFCCU_1_GFLTPO_C0_PS17_MASK)

#define VFCCU_1_GFLTPO_C0_PS18_MASK              (0x40000U)
#define VFCCU_1_GFLTPO_C0_PS18_SHIFT             (18U)
#define VFCCU_1_GFLTPO_C0_PS18_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS18(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS18_SHIFT)) & VFCCU_1_GFLTPO_C0_PS18_MASK)

#define VFCCU_1_GFLTPO_C0_PS19_MASK              (0x80000U)
#define VFCCU_1_GFLTPO_C0_PS19_SHIFT             (19U)
#define VFCCU_1_GFLTPO_C0_PS19_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS19(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS19_SHIFT)) & VFCCU_1_GFLTPO_C0_PS19_MASK)

#define VFCCU_1_GFLTPO_C0_PS20_MASK              (0x100000U)
#define VFCCU_1_GFLTPO_C0_PS20_SHIFT             (20U)
#define VFCCU_1_GFLTPO_C0_PS20_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS20(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS20_SHIFT)) & VFCCU_1_GFLTPO_C0_PS20_MASK)

#define VFCCU_1_GFLTPO_C0_PS21_MASK              (0x200000U)
#define VFCCU_1_GFLTPO_C0_PS21_SHIFT             (21U)
#define VFCCU_1_GFLTPO_C0_PS21_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS21(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS21_SHIFT)) & VFCCU_1_GFLTPO_C0_PS21_MASK)

#define VFCCU_1_GFLTPO_C0_PS22_MASK              (0x400000U)
#define VFCCU_1_GFLTPO_C0_PS22_SHIFT             (22U)
#define VFCCU_1_GFLTPO_C0_PS22_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS22(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS22_SHIFT)) & VFCCU_1_GFLTPO_C0_PS22_MASK)

#define VFCCU_1_GFLTPO_C0_PS23_MASK              (0x800000U)
#define VFCCU_1_GFLTPO_C0_PS23_SHIFT             (23U)
#define VFCCU_1_GFLTPO_C0_PS23_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS23(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS23_SHIFT)) & VFCCU_1_GFLTPO_C0_PS23_MASK)

#define VFCCU_1_GFLTPO_C0_PS24_MASK              (0x1000000U)
#define VFCCU_1_GFLTPO_C0_PS24_SHIFT             (24U)
#define VFCCU_1_GFLTPO_C0_PS24_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS24(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS24_SHIFT)) & VFCCU_1_GFLTPO_C0_PS24_MASK)

#define VFCCU_1_GFLTPO_C0_PS25_MASK              (0x2000000U)
#define VFCCU_1_GFLTPO_C0_PS25_SHIFT             (25U)
#define VFCCU_1_GFLTPO_C0_PS25_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS25(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS25_SHIFT)) & VFCCU_1_GFLTPO_C0_PS25_MASK)

#define VFCCU_1_GFLTPO_C0_PS26_MASK              (0x4000000U)
#define VFCCU_1_GFLTPO_C0_PS26_SHIFT             (26U)
#define VFCCU_1_GFLTPO_C0_PS26_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS26(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS26_SHIFT)) & VFCCU_1_GFLTPO_C0_PS26_MASK)

#define VFCCU_1_GFLTPO_C0_PS27_MASK              (0x8000000U)
#define VFCCU_1_GFLTPO_C0_PS27_SHIFT             (27U)
#define VFCCU_1_GFLTPO_C0_PS27_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS27(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS27_SHIFT)) & VFCCU_1_GFLTPO_C0_PS27_MASK)

#define VFCCU_1_GFLTPO_C0_PS28_MASK              (0x10000000U)
#define VFCCU_1_GFLTPO_C0_PS28_SHIFT             (28U)
#define VFCCU_1_GFLTPO_C0_PS28_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS28(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS28_SHIFT)) & VFCCU_1_GFLTPO_C0_PS28_MASK)

#define VFCCU_1_GFLTPO_C0_PS29_MASK              (0x20000000U)
#define VFCCU_1_GFLTPO_C0_PS29_SHIFT             (29U)
#define VFCCU_1_GFLTPO_C0_PS29_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS29(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS29_SHIFT)) & VFCCU_1_GFLTPO_C0_PS29_MASK)

#define VFCCU_1_GFLTPO_C0_PS30_MASK              (0x40000000U)
#define VFCCU_1_GFLTPO_C0_PS30_SHIFT             (30U)
#define VFCCU_1_GFLTPO_C0_PS30_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS30(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS30_SHIFT)) & VFCCU_1_GFLTPO_C0_PS30_MASK)

#define VFCCU_1_GFLTPO_C0_PS31_MASK              (0x80000000U)
#define VFCCU_1_GFLTPO_C0_PS31_SHIFT             (31U)
#define VFCCU_1_GFLTPO_C0_PS31_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C0_PS31(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C0_PS31_SHIFT)) & VFCCU_1_GFLTPO_C0_PS31_MASK)
/*! @} */

/*! @name GFLTPO_C1 - Global Fault Polarity */
/*! @{ */

#define VFCCU_1_GFLTPO_C1_PS32_MASK              (0x1U)
#define VFCCU_1_GFLTPO_C1_PS32_SHIFT             (0U)
#define VFCCU_1_GFLTPO_C1_PS32_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS32(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS32_SHIFT)) & VFCCU_1_GFLTPO_C1_PS32_MASK)

#define VFCCU_1_GFLTPO_C1_PS33_MASK              (0x2U)
#define VFCCU_1_GFLTPO_C1_PS33_SHIFT             (1U)
#define VFCCU_1_GFLTPO_C1_PS33_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS33(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS33_SHIFT)) & VFCCU_1_GFLTPO_C1_PS33_MASK)

#define VFCCU_1_GFLTPO_C1_PS34_MASK              (0x4U)
#define VFCCU_1_GFLTPO_C1_PS34_SHIFT             (2U)
#define VFCCU_1_GFLTPO_C1_PS34_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS34(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS34_SHIFT)) & VFCCU_1_GFLTPO_C1_PS34_MASK)

#define VFCCU_1_GFLTPO_C1_PS35_MASK              (0x8U)
#define VFCCU_1_GFLTPO_C1_PS35_SHIFT             (3U)
#define VFCCU_1_GFLTPO_C1_PS35_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS35(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS35_SHIFT)) & VFCCU_1_GFLTPO_C1_PS35_MASK)

#define VFCCU_1_GFLTPO_C1_PS36_MASK              (0x10U)
#define VFCCU_1_GFLTPO_C1_PS36_SHIFT             (4U)
#define VFCCU_1_GFLTPO_C1_PS36_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS36(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS36_SHIFT)) & VFCCU_1_GFLTPO_C1_PS36_MASK)

#define VFCCU_1_GFLTPO_C1_PS37_MASK              (0x20U)
#define VFCCU_1_GFLTPO_C1_PS37_SHIFT             (5U)
#define VFCCU_1_GFLTPO_C1_PS37_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS37(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS37_SHIFT)) & VFCCU_1_GFLTPO_C1_PS37_MASK)

#define VFCCU_1_GFLTPO_C1_PS38_MASK              (0x40U)
#define VFCCU_1_GFLTPO_C1_PS38_SHIFT             (6U)
#define VFCCU_1_GFLTPO_C1_PS38_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS38(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS38_SHIFT)) & VFCCU_1_GFLTPO_C1_PS38_MASK)

#define VFCCU_1_GFLTPO_C1_PS39_MASK              (0x80U)
#define VFCCU_1_GFLTPO_C1_PS39_SHIFT             (7U)
#define VFCCU_1_GFLTPO_C1_PS39_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS39(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS39_SHIFT)) & VFCCU_1_GFLTPO_C1_PS39_MASK)

#define VFCCU_1_GFLTPO_C1_PS40_MASK              (0x100U)
#define VFCCU_1_GFLTPO_C1_PS40_SHIFT             (8U)
#define VFCCU_1_GFLTPO_C1_PS40_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS40(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS40_SHIFT)) & VFCCU_1_GFLTPO_C1_PS40_MASK)

#define VFCCU_1_GFLTPO_C1_PS41_MASK              (0x200U)
#define VFCCU_1_GFLTPO_C1_PS41_SHIFT             (9U)
#define VFCCU_1_GFLTPO_C1_PS41_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS41(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS41_SHIFT)) & VFCCU_1_GFLTPO_C1_PS41_MASK)

#define VFCCU_1_GFLTPO_C1_PS42_MASK              (0x400U)
#define VFCCU_1_GFLTPO_C1_PS42_SHIFT             (10U)
#define VFCCU_1_GFLTPO_C1_PS42_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS42(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS42_SHIFT)) & VFCCU_1_GFLTPO_C1_PS42_MASK)

#define VFCCU_1_GFLTPO_C1_PS43_MASK              (0x800U)
#define VFCCU_1_GFLTPO_C1_PS43_SHIFT             (11U)
#define VFCCU_1_GFLTPO_C1_PS43_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS43(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS43_SHIFT)) & VFCCU_1_GFLTPO_C1_PS43_MASK)

#define VFCCU_1_GFLTPO_C1_PS44_MASK              (0x1000U)
#define VFCCU_1_GFLTPO_C1_PS44_SHIFT             (12U)
#define VFCCU_1_GFLTPO_C1_PS44_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS44(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS44_SHIFT)) & VFCCU_1_GFLTPO_C1_PS44_MASK)

#define VFCCU_1_GFLTPO_C1_PS45_MASK              (0x2000U)
#define VFCCU_1_GFLTPO_C1_PS45_SHIFT             (13U)
#define VFCCU_1_GFLTPO_C1_PS45_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS45(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS45_SHIFT)) & VFCCU_1_GFLTPO_C1_PS45_MASK)

#define VFCCU_1_GFLTPO_C1_PS46_MASK              (0x4000U)
#define VFCCU_1_GFLTPO_C1_PS46_SHIFT             (14U)
#define VFCCU_1_GFLTPO_C1_PS46_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS46(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS46_SHIFT)) & VFCCU_1_GFLTPO_C1_PS46_MASK)

#define VFCCU_1_GFLTPO_C1_PS47_MASK              (0x8000U)
#define VFCCU_1_GFLTPO_C1_PS47_SHIFT             (15U)
#define VFCCU_1_GFLTPO_C1_PS47_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS47(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS47_SHIFT)) & VFCCU_1_GFLTPO_C1_PS47_MASK)

#define VFCCU_1_GFLTPO_C1_PS48_MASK              (0x10000U)
#define VFCCU_1_GFLTPO_C1_PS48_SHIFT             (16U)
#define VFCCU_1_GFLTPO_C1_PS48_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS48(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS48_SHIFT)) & VFCCU_1_GFLTPO_C1_PS48_MASK)

#define VFCCU_1_GFLTPO_C1_PS49_MASK              (0x20000U)
#define VFCCU_1_GFLTPO_C1_PS49_SHIFT             (17U)
#define VFCCU_1_GFLTPO_C1_PS49_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS49(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS49_SHIFT)) & VFCCU_1_GFLTPO_C1_PS49_MASK)

#define VFCCU_1_GFLTPO_C1_PS50_MASK              (0x40000U)
#define VFCCU_1_GFLTPO_C1_PS50_SHIFT             (18U)
#define VFCCU_1_GFLTPO_C1_PS50_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS50(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS50_SHIFT)) & VFCCU_1_GFLTPO_C1_PS50_MASK)

#define VFCCU_1_GFLTPO_C1_PS51_MASK              (0x80000U)
#define VFCCU_1_GFLTPO_C1_PS51_SHIFT             (19U)
#define VFCCU_1_GFLTPO_C1_PS51_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS51(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS51_SHIFT)) & VFCCU_1_GFLTPO_C1_PS51_MASK)

#define VFCCU_1_GFLTPO_C1_PS52_MASK              (0x100000U)
#define VFCCU_1_GFLTPO_C1_PS52_SHIFT             (20U)
#define VFCCU_1_GFLTPO_C1_PS52_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS52(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS52_SHIFT)) & VFCCU_1_GFLTPO_C1_PS52_MASK)

#define VFCCU_1_GFLTPO_C1_PS53_MASK              (0x200000U)
#define VFCCU_1_GFLTPO_C1_PS53_SHIFT             (21U)
#define VFCCU_1_GFLTPO_C1_PS53_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS53(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS53_SHIFT)) & VFCCU_1_GFLTPO_C1_PS53_MASK)

#define VFCCU_1_GFLTPO_C1_PS54_MASK              (0x400000U)
#define VFCCU_1_GFLTPO_C1_PS54_SHIFT             (22U)
#define VFCCU_1_GFLTPO_C1_PS54_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS54(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS54_SHIFT)) & VFCCU_1_GFLTPO_C1_PS54_MASK)

#define VFCCU_1_GFLTPO_C1_PS55_MASK              (0x800000U)
#define VFCCU_1_GFLTPO_C1_PS55_SHIFT             (23U)
#define VFCCU_1_GFLTPO_C1_PS55_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS55(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS55_SHIFT)) & VFCCU_1_GFLTPO_C1_PS55_MASK)

#define VFCCU_1_GFLTPO_C1_PS56_MASK              (0x1000000U)
#define VFCCU_1_GFLTPO_C1_PS56_SHIFT             (24U)
#define VFCCU_1_GFLTPO_C1_PS56_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS56(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS56_SHIFT)) & VFCCU_1_GFLTPO_C1_PS56_MASK)

#define VFCCU_1_GFLTPO_C1_PS57_MASK              (0x2000000U)
#define VFCCU_1_GFLTPO_C1_PS57_SHIFT             (25U)
#define VFCCU_1_GFLTPO_C1_PS57_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS57(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS57_SHIFT)) & VFCCU_1_GFLTPO_C1_PS57_MASK)

#define VFCCU_1_GFLTPO_C1_PS58_MASK              (0x4000000U)
#define VFCCU_1_GFLTPO_C1_PS58_SHIFT             (26U)
#define VFCCU_1_GFLTPO_C1_PS58_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS58(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS58_SHIFT)) & VFCCU_1_GFLTPO_C1_PS58_MASK)

#define VFCCU_1_GFLTPO_C1_PS59_MASK              (0x8000000U)
#define VFCCU_1_GFLTPO_C1_PS59_SHIFT             (27U)
#define VFCCU_1_GFLTPO_C1_PS59_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS59(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS59_SHIFT)) & VFCCU_1_GFLTPO_C1_PS59_MASK)

#define VFCCU_1_GFLTPO_C1_PS60_MASK              (0x10000000U)
#define VFCCU_1_GFLTPO_C1_PS60_SHIFT             (28U)
#define VFCCU_1_GFLTPO_C1_PS60_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS60(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS60_SHIFT)) & VFCCU_1_GFLTPO_C1_PS60_MASK)

#define VFCCU_1_GFLTPO_C1_PS61_MASK              (0x20000000U)
#define VFCCU_1_GFLTPO_C1_PS61_SHIFT             (29U)
#define VFCCU_1_GFLTPO_C1_PS61_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS61(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS61_SHIFT)) & VFCCU_1_GFLTPO_C1_PS61_MASK)

#define VFCCU_1_GFLTPO_C1_PS62_MASK              (0x40000000U)
#define VFCCU_1_GFLTPO_C1_PS62_SHIFT             (30U)
#define VFCCU_1_GFLTPO_C1_PS62_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS62(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS62_SHIFT)) & VFCCU_1_GFLTPO_C1_PS62_MASK)

#define VFCCU_1_GFLTPO_C1_PS63_MASK              (0x80000000U)
#define VFCCU_1_GFLTPO_C1_PS63_SHIFT             (31U)
#define VFCCU_1_GFLTPO_C1_PS63_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C1_PS63(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C1_PS63_SHIFT)) & VFCCU_1_GFLTPO_C1_PS63_MASK)
/*! @} */

/*! @name GFLTPO_C2 - Global Fault Polarity */
/*! @{ */

#define VFCCU_1_GFLTPO_C2_PS64_MASK              (0x1U)
#define VFCCU_1_GFLTPO_C2_PS64_SHIFT             (0U)
#define VFCCU_1_GFLTPO_C2_PS64_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS64(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS64_SHIFT)) & VFCCU_1_GFLTPO_C2_PS64_MASK)

#define VFCCU_1_GFLTPO_C2_PS65_MASK              (0x2U)
#define VFCCU_1_GFLTPO_C2_PS65_SHIFT             (1U)
#define VFCCU_1_GFLTPO_C2_PS65_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS65(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS65_SHIFT)) & VFCCU_1_GFLTPO_C2_PS65_MASK)

#define VFCCU_1_GFLTPO_C2_PS66_MASK              (0x4U)
#define VFCCU_1_GFLTPO_C2_PS66_SHIFT             (2U)
#define VFCCU_1_GFLTPO_C2_PS66_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS66(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS66_SHIFT)) & VFCCU_1_GFLTPO_C2_PS66_MASK)

#define VFCCU_1_GFLTPO_C2_PS67_MASK              (0x8U)
#define VFCCU_1_GFLTPO_C2_PS67_SHIFT             (3U)
#define VFCCU_1_GFLTPO_C2_PS67_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS67(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS67_SHIFT)) & VFCCU_1_GFLTPO_C2_PS67_MASK)

#define VFCCU_1_GFLTPO_C2_PS68_MASK              (0x10U)
#define VFCCU_1_GFLTPO_C2_PS68_SHIFT             (4U)
#define VFCCU_1_GFLTPO_C2_PS68_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS68(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS68_SHIFT)) & VFCCU_1_GFLTPO_C2_PS68_MASK)

#define VFCCU_1_GFLTPO_C2_PS69_MASK              (0x20U)
#define VFCCU_1_GFLTPO_C2_PS69_SHIFT             (5U)
#define VFCCU_1_GFLTPO_C2_PS69_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS69(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS69_SHIFT)) & VFCCU_1_GFLTPO_C2_PS69_MASK)

#define VFCCU_1_GFLTPO_C2_PS70_MASK              (0x40U)
#define VFCCU_1_GFLTPO_C2_PS70_SHIFT             (6U)
#define VFCCU_1_GFLTPO_C2_PS70_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS70(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS70_SHIFT)) & VFCCU_1_GFLTPO_C2_PS70_MASK)

#define VFCCU_1_GFLTPO_C2_PS71_MASK              (0x80U)
#define VFCCU_1_GFLTPO_C2_PS71_SHIFT             (7U)
#define VFCCU_1_GFLTPO_C2_PS71_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS71(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS71_SHIFT)) & VFCCU_1_GFLTPO_C2_PS71_MASK)

#define VFCCU_1_GFLTPO_C2_PS72_MASK              (0x100U)
#define VFCCU_1_GFLTPO_C2_PS72_SHIFT             (8U)
#define VFCCU_1_GFLTPO_C2_PS72_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS72(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS72_SHIFT)) & VFCCU_1_GFLTPO_C2_PS72_MASK)

#define VFCCU_1_GFLTPO_C2_PS73_MASK              (0x200U)
#define VFCCU_1_GFLTPO_C2_PS73_SHIFT             (9U)
#define VFCCU_1_GFLTPO_C2_PS73_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS73(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS73_SHIFT)) & VFCCU_1_GFLTPO_C2_PS73_MASK)

#define VFCCU_1_GFLTPO_C2_PS74_MASK              (0x400U)
#define VFCCU_1_GFLTPO_C2_PS74_SHIFT             (10U)
#define VFCCU_1_GFLTPO_C2_PS74_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS74(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS74_SHIFT)) & VFCCU_1_GFLTPO_C2_PS74_MASK)

#define VFCCU_1_GFLTPO_C2_PS75_MASK              (0x800U)
#define VFCCU_1_GFLTPO_C2_PS75_SHIFT             (11U)
#define VFCCU_1_GFLTPO_C2_PS75_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS75(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS75_SHIFT)) & VFCCU_1_GFLTPO_C2_PS75_MASK)

#define VFCCU_1_GFLTPO_C2_PS76_MASK              (0x1000U)
#define VFCCU_1_GFLTPO_C2_PS76_SHIFT             (12U)
#define VFCCU_1_GFLTPO_C2_PS76_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS76(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS76_SHIFT)) & VFCCU_1_GFLTPO_C2_PS76_MASK)

#define VFCCU_1_GFLTPO_C2_PS77_MASK              (0x2000U)
#define VFCCU_1_GFLTPO_C2_PS77_SHIFT             (13U)
#define VFCCU_1_GFLTPO_C2_PS77_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS77(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS77_SHIFT)) & VFCCU_1_GFLTPO_C2_PS77_MASK)

#define VFCCU_1_GFLTPO_C2_PS78_MASK              (0x4000U)
#define VFCCU_1_GFLTPO_C2_PS78_SHIFT             (14U)
#define VFCCU_1_GFLTPO_C2_PS78_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS78(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS78_SHIFT)) & VFCCU_1_GFLTPO_C2_PS78_MASK)

#define VFCCU_1_GFLTPO_C2_PS79_MASK              (0x8000U)
#define VFCCU_1_GFLTPO_C2_PS79_SHIFT             (15U)
#define VFCCU_1_GFLTPO_C2_PS79_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS79(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS79_SHIFT)) & VFCCU_1_GFLTPO_C2_PS79_MASK)

#define VFCCU_1_GFLTPO_C2_PS80_MASK              (0x10000U)
#define VFCCU_1_GFLTPO_C2_PS80_SHIFT             (16U)
#define VFCCU_1_GFLTPO_C2_PS80_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS80(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS80_SHIFT)) & VFCCU_1_GFLTPO_C2_PS80_MASK)

#define VFCCU_1_GFLTPO_C2_PS81_MASK              (0x20000U)
#define VFCCU_1_GFLTPO_C2_PS81_SHIFT             (17U)
#define VFCCU_1_GFLTPO_C2_PS81_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS81(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS81_SHIFT)) & VFCCU_1_GFLTPO_C2_PS81_MASK)

#define VFCCU_1_GFLTPO_C2_PS82_MASK              (0x40000U)
#define VFCCU_1_GFLTPO_C2_PS82_SHIFT             (18U)
#define VFCCU_1_GFLTPO_C2_PS82_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS82(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS82_SHIFT)) & VFCCU_1_GFLTPO_C2_PS82_MASK)

#define VFCCU_1_GFLTPO_C2_PS83_MASK              (0x80000U)
#define VFCCU_1_GFLTPO_C2_PS83_SHIFT             (19U)
#define VFCCU_1_GFLTPO_C2_PS83_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS83(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS83_SHIFT)) & VFCCU_1_GFLTPO_C2_PS83_MASK)

#define VFCCU_1_GFLTPO_C2_PS84_MASK              (0x100000U)
#define VFCCU_1_GFLTPO_C2_PS84_SHIFT             (20U)
#define VFCCU_1_GFLTPO_C2_PS84_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS84(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS84_SHIFT)) & VFCCU_1_GFLTPO_C2_PS84_MASK)

#define VFCCU_1_GFLTPO_C2_PS85_MASK              (0x200000U)
#define VFCCU_1_GFLTPO_C2_PS85_SHIFT             (21U)
#define VFCCU_1_GFLTPO_C2_PS85_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS85(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS85_SHIFT)) & VFCCU_1_GFLTPO_C2_PS85_MASK)

#define VFCCU_1_GFLTPO_C2_PS86_MASK              (0x400000U)
#define VFCCU_1_GFLTPO_C2_PS86_SHIFT             (22U)
#define VFCCU_1_GFLTPO_C2_PS86_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS86(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS86_SHIFT)) & VFCCU_1_GFLTPO_C2_PS86_MASK)

#define VFCCU_1_GFLTPO_C2_PS87_MASK              (0x800000U)
#define VFCCU_1_GFLTPO_C2_PS87_SHIFT             (23U)
#define VFCCU_1_GFLTPO_C2_PS87_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS87(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS87_SHIFT)) & VFCCU_1_GFLTPO_C2_PS87_MASK)

#define VFCCU_1_GFLTPO_C2_PS88_MASK              (0x1000000U)
#define VFCCU_1_GFLTPO_C2_PS88_SHIFT             (24U)
#define VFCCU_1_GFLTPO_C2_PS88_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS88(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS88_SHIFT)) & VFCCU_1_GFLTPO_C2_PS88_MASK)

#define VFCCU_1_GFLTPO_C2_PS89_MASK              (0x2000000U)
#define VFCCU_1_GFLTPO_C2_PS89_SHIFT             (25U)
#define VFCCU_1_GFLTPO_C2_PS89_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS89(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS89_SHIFT)) & VFCCU_1_GFLTPO_C2_PS89_MASK)

#define VFCCU_1_GFLTPO_C2_PS90_MASK              (0x4000000U)
#define VFCCU_1_GFLTPO_C2_PS90_SHIFT             (26U)
#define VFCCU_1_GFLTPO_C2_PS90_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS90(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS90_SHIFT)) & VFCCU_1_GFLTPO_C2_PS90_MASK)

#define VFCCU_1_GFLTPO_C2_PS91_MASK              (0x8000000U)
#define VFCCU_1_GFLTPO_C2_PS91_SHIFT             (27U)
#define VFCCU_1_GFLTPO_C2_PS91_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS91(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS91_SHIFT)) & VFCCU_1_GFLTPO_C2_PS91_MASK)

#define VFCCU_1_GFLTPO_C2_PS92_MASK              (0x10000000U)
#define VFCCU_1_GFLTPO_C2_PS92_SHIFT             (28U)
#define VFCCU_1_GFLTPO_C2_PS92_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS92(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS92_SHIFT)) & VFCCU_1_GFLTPO_C2_PS92_MASK)

#define VFCCU_1_GFLTPO_C2_PS93_MASK              (0x20000000U)
#define VFCCU_1_GFLTPO_C2_PS93_SHIFT             (29U)
#define VFCCU_1_GFLTPO_C2_PS93_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS93(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS93_SHIFT)) & VFCCU_1_GFLTPO_C2_PS93_MASK)

#define VFCCU_1_GFLTPO_C2_PS94_MASK              (0x40000000U)
#define VFCCU_1_GFLTPO_C2_PS94_SHIFT             (30U)
#define VFCCU_1_GFLTPO_C2_PS94_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS94(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS94_SHIFT)) & VFCCU_1_GFLTPO_C2_PS94_MASK)

#define VFCCU_1_GFLTPO_C2_PS95_MASK              (0x80000000U)
#define VFCCU_1_GFLTPO_C2_PS95_SHIFT             (31U)
#define VFCCU_1_GFLTPO_C2_PS95_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C2_PS95(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C2_PS95_SHIFT)) & VFCCU_1_GFLTPO_C2_PS95_MASK)
/*! @} */

/*! @name GFLTPO_C3 - Global Fault Polarity */
/*! @{ */

#define VFCCU_1_GFLTPO_C3_PS96_MASK              (0x1U)
#define VFCCU_1_GFLTPO_C3_PS96_SHIFT             (0U)
#define VFCCU_1_GFLTPO_C3_PS96_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C3_PS96(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS96_SHIFT)) & VFCCU_1_GFLTPO_C3_PS96_MASK)

#define VFCCU_1_GFLTPO_C3_PS97_MASK              (0x2U)
#define VFCCU_1_GFLTPO_C3_PS97_SHIFT             (1U)
#define VFCCU_1_GFLTPO_C3_PS97_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C3_PS97(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS97_SHIFT)) & VFCCU_1_GFLTPO_C3_PS97_MASK)

#define VFCCU_1_GFLTPO_C3_PS98_MASK              (0x4U)
#define VFCCU_1_GFLTPO_C3_PS98_SHIFT             (2U)
#define VFCCU_1_GFLTPO_C3_PS98_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C3_PS98(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS98_SHIFT)) & VFCCU_1_GFLTPO_C3_PS98_MASK)

#define VFCCU_1_GFLTPO_C3_PS99_MASK              (0x8U)
#define VFCCU_1_GFLTPO_C3_PS99_SHIFT             (3U)
#define VFCCU_1_GFLTPO_C3_PS99_WIDTH             (1U)
#define VFCCU_1_GFLTPO_C3_PS99(x)                (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS99_SHIFT)) & VFCCU_1_GFLTPO_C3_PS99_MASK)

#define VFCCU_1_GFLTPO_C3_PS100_MASK             (0x10U)
#define VFCCU_1_GFLTPO_C3_PS100_SHIFT            (4U)
#define VFCCU_1_GFLTPO_C3_PS100_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS100(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS100_SHIFT)) & VFCCU_1_GFLTPO_C3_PS100_MASK)

#define VFCCU_1_GFLTPO_C3_PS101_MASK             (0x20U)
#define VFCCU_1_GFLTPO_C3_PS101_SHIFT            (5U)
#define VFCCU_1_GFLTPO_C3_PS101_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS101(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS101_SHIFT)) & VFCCU_1_GFLTPO_C3_PS101_MASK)

#define VFCCU_1_GFLTPO_C3_PS102_MASK             (0x40U)
#define VFCCU_1_GFLTPO_C3_PS102_SHIFT            (6U)
#define VFCCU_1_GFLTPO_C3_PS102_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS102(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS102_SHIFT)) & VFCCU_1_GFLTPO_C3_PS102_MASK)

#define VFCCU_1_GFLTPO_C3_PS103_MASK             (0x80U)
#define VFCCU_1_GFLTPO_C3_PS103_SHIFT            (7U)
#define VFCCU_1_GFLTPO_C3_PS103_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS103(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS103_SHIFT)) & VFCCU_1_GFLTPO_C3_PS103_MASK)

#define VFCCU_1_GFLTPO_C3_PS104_MASK             (0x100U)
#define VFCCU_1_GFLTPO_C3_PS104_SHIFT            (8U)
#define VFCCU_1_GFLTPO_C3_PS104_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS104(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS104_SHIFT)) & VFCCU_1_GFLTPO_C3_PS104_MASK)

#define VFCCU_1_GFLTPO_C3_PS105_MASK             (0x200U)
#define VFCCU_1_GFLTPO_C3_PS105_SHIFT            (9U)
#define VFCCU_1_GFLTPO_C3_PS105_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS105(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS105_SHIFT)) & VFCCU_1_GFLTPO_C3_PS105_MASK)

#define VFCCU_1_GFLTPO_C3_PS106_MASK             (0x400U)
#define VFCCU_1_GFLTPO_C3_PS106_SHIFT            (10U)
#define VFCCU_1_GFLTPO_C3_PS106_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS106(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS106_SHIFT)) & VFCCU_1_GFLTPO_C3_PS106_MASK)

#define VFCCU_1_GFLTPO_C3_PS107_MASK             (0x800U)
#define VFCCU_1_GFLTPO_C3_PS107_SHIFT            (11U)
#define VFCCU_1_GFLTPO_C3_PS107_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS107(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS107_SHIFT)) & VFCCU_1_GFLTPO_C3_PS107_MASK)

#define VFCCU_1_GFLTPO_C3_PS108_MASK             (0x1000U)
#define VFCCU_1_GFLTPO_C3_PS108_SHIFT            (12U)
#define VFCCU_1_GFLTPO_C3_PS108_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS108(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS108_SHIFT)) & VFCCU_1_GFLTPO_C3_PS108_MASK)

#define VFCCU_1_GFLTPO_C3_PS109_MASK             (0x2000U)
#define VFCCU_1_GFLTPO_C3_PS109_SHIFT            (13U)
#define VFCCU_1_GFLTPO_C3_PS109_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS109(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS109_SHIFT)) & VFCCU_1_GFLTPO_C3_PS109_MASK)

#define VFCCU_1_GFLTPO_C3_PS110_MASK             (0x4000U)
#define VFCCU_1_GFLTPO_C3_PS110_SHIFT            (14U)
#define VFCCU_1_GFLTPO_C3_PS110_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS110(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS110_SHIFT)) & VFCCU_1_GFLTPO_C3_PS110_MASK)

#define VFCCU_1_GFLTPO_C3_PS111_MASK             (0x8000U)
#define VFCCU_1_GFLTPO_C3_PS111_SHIFT            (15U)
#define VFCCU_1_GFLTPO_C3_PS111_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS111(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS111_SHIFT)) & VFCCU_1_GFLTPO_C3_PS111_MASK)

#define VFCCU_1_GFLTPO_C3_PS112_MASK             (0x10000U)
#define VFCCU_1_GFLTPO_C3_PS112_SHIFT            (16U)
#define VFCCU_1_GFLTPO_C3_PS112_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS112(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS112_SHIFT)) & VFCCU_1_GFLTPO_C3_PS112_MASK)

#define VFCCU_1_GFLTPO_C3_PS113_MASK             (0x20000U)
#define VFCCU_1_GFLTPO_C3_PS113_SHIFT            (17U)
#define VFCCU_1_GFLTPO_C3_PS113_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS113(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS113_SHIFT)) & VFCCU_1_GFLTPO_C3_PS113_MASK)

#define VFCCU_1_GFLTPO_C3_PS114_MASK             (0x40000U)
#define VFCCU_1_GFLTPO_C3_PS114_SHIFT            (18U)
#define VFCCU_1_GFLTPO_C3_PS114_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS114(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS114_SHIFT)) & VFCCU_1_GFLTPO_C3_PS114_MASK)

#define VFCCU_1_GFLTPO_C3_PS115_MASK             (0x80000U)
#define VFCCU_1_GFLTPO_C3_PS115_SHIFT            (19U)
#define VFCCU_1_GFLTPO_C3_PS115_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS115(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS115_SHIFT)) & VFCCU_1_GFLTPO_C3_PS115_MASK)

#define VFCCU_1_GFLTPO_C3_PS116_MASK             (0x100000U)
#define VFCCU_1_GFLTPO_C3_PS116_SHIFT            (20U)
#define VFCCU_1_GFLTPO_C3_PS116_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS116(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS116_SHIFT)) & VFCCU_1_GFLTPO_C3_PS116_MASK)

#define VFCCU_1_GFLTPO_C3_PS117_MASK             (0x200000U)
#define VFCCU_1_GFLTPO_C3_PS117_SHIFT            (21U)
#define VFCCU_1_GFLTPO_C3_PS117_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS117(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS117_SHIFT)) & VFCCU_1_GFLTPO_C3_PS117_MASK)

#define VFCCU_1_GFLTPO_C3_PS118_MASK             (0x400000U)
#define VFCCU_1_GFLTPO_C3_PS118_SHIFT            (22U)
#define VFCCU_1_GFLTPO_C3_PS118_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS118(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS118_SHIFT)) & VFCCU_1_GFLTPO_C3_PS118_MASK)

#define VFCCU_1_GFLTPO_C3_PS119_MASK             (0x800000U)
#define VFCCU_1_GFLTPO_C3_PS119_SHIFT            (23U)
#define VFCCU_1_GFLTPO_C3_PS119_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS119(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS119_SHIFT)) & VFCCU_1_GFLTPO_C3_PS119_MASK)

#define VFCCU_1_GFLTPO_C3_PS120_MASK             (0x1000000U)
#define VFCCU_1_GFLTPO_C3_PS120_SHIFT            (24U)
#define VFCCU_1_GFLTPO_C3_PS120_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS120(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS120_SHIFT)) & VFCCU_1_GFLTPO_C3_PS120_MASK)

#define VFCCU_1_GFLTPO_C3_PS121_MASK             (0x2000000U)
#define VFCCU_1_GFLTPO_C3_PS121_SHIFT            (25U)
#define VFCCU_1_GFLTPO_C3_PS121_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS121(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS121_SHIFT)) & VFCCU_1_GFLTPO_C3_PS121_MASK)

#define VFCCU_1_GFLTPO_C3_PS122_MASK             (0x4000000U)
#define VFCCU_1_GFLTPO_C3_PS122_SHIFT            (26U)
#define VFCCU_1_GFLTPO_C3_PS122_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS122(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS122_SHIFT)) & VFCCU_1_GFLTPO_C3_PS122_MASK)

#define VFCCU_1_GFLTPO_C3_PS123_MASK             (0x8000000U)
#define VFCCU_1_GFLTPO_C3_PS123_SHIFT            (27U)
#define VFCCU_1_GFLTPO_C3_PS123_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS123(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS123_SHIFT)) & VFCCU_1_GFLTPO_C3_PS123_MASK)

#define VFCCU_1_GFLTPO_C3_PS124_MASK             (0x10000000U)
#define VFCCU_1_GFLTPO_C3_PS124_SHIFT            (28U)
#define VFCCU_1_GFLTPO_C3_PS124_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS124(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS124_SHIFT)) & VFCCU_1_GFLTPO_C3_PS124_MASK)

#define VFCCU_1_GFLTPO_C3_PS125_MASK             (0x20000000U)
#define VFCCU_1_GFLTPO_C3_PS125_SHIFT            (29U)
#define VFCCU_1_GFLTPO_C3_PS125_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS125(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS125_SHIFT)) & VFCCU_1_GFLTPO_C3_PS125_MASK)

#define VFCCU_1_GFLTPO_C3_PS126_MASK             (0x40000000U)
#define VFCCU_1_GFLTPO_C3_PS126_SHIFT            (30U)
#define VFCCU_1_GFLTPO_C3_PS126_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS126(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS126_SHIFT)) & VFCCU_1_GFLTPO_C3_PS126_MASK)

#define VFCCU_1_GFLTPO_C3_PS127_MASK             (0x80000000U)
#define VFCCU_1_GFLTPO_C3_PS127_SHIFT            (31U)
#define VFCCU_1_GFLTPO_C3_PS127_WIDTH            (1U)
#define VFCCU_1_GFLTPO_C3_PS127(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTPO_C3_PS127_SHIFT)) & VFCCU_1_GFLTPO_C3_PS127_MASK)
/*! @} */

/*! @name GFLTRC_C0 - Global Fault Recovery */
/*! @{ */

#define VFCCU_1_GFLTRC_C0_RHWSW0_MASK            (0x1U)
#define VFCCU_1_GFLTRC_C0_RHWSW0_SHIFT           (0U)
#define VFCCU_1_GFLTRC_C0_RHWSW0_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW0(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW0_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW0_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW1_MASK            (0x2U)
#define VFCCU_1_GFLTRC_C0_RHWSW1_SHIFT           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW1_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW1(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW1_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW1_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW2_MASK            (0x4U)
#define VFCCU_1_GFLTRC_C0_RHWSW2_SHIFT           (2U)
#define VFCCU_1_GFLTRC_C0_RHWSW2_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW2(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW2_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW2_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW3_MASK            (0x8U)
#define VFCCU_1_GFLTRC_C0_RHWSW3_SHIFT           (3U)
#define VFCCU_1_GFLTRC_C0_RHWSW3_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW3(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW3_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW3_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW4_MASK            (0x10U)
#define VFCCU_1_GFLTRC_C0_RHWSW4_SHIFT           (4U)
#define VFCCU_1_GFLTRC_C0_RHWSW4_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW4(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW4_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW4_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW5_MASK            (0x20U)
#define VFCCU_1_GFLTRC_C0_RHWSW5_SHIFT           (5U)
#define VFCCU_1_GFLTRC_C0_RHWSW5_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW5(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW5_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW5_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW6_MASK            (0x40U)
#define VFCCU_1_GFLTRC_C0_RHWSW6_SHIFT           (6U)
#define VFCCU_1_GFLTRC_C0_RHWSW6_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW6(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW6_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW6_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW7_MASK            (0x80U)
#define VFCCU_1_GFLTRC_C0_RHWSW7_SHIFT           (7U)
#define VFCCU_1_GFLTRC_C0_RHWSW7_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW7(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW7_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW7_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW8_MASK            (0x100U)
#define VFCCU_1_GFLTRC_C0_RHWSW8_SHIFT           (8U)
#define VFCCU_1_GFLTRC_C0_RHWSW8_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW8(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW8_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW8_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW9_MASK            (0x200U)
#define VFCCU_1_GFLTRC_C0_RHWSW9_SHIFT           (9U)
#define VFCCU_1_GFLTRC_C0_RHWSW9_WIDTH           (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW9(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW9_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW9_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW10_MASK           (0x400U)
#define VFCCU_1_GFLTRC_C0_RHWSW10_SHIFT          (10U)
#define VFCCU_1_GFLTRC_C0_RHWSW10_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW10(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW10_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW10_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW11_MASK           (0x800U)
#define VFCCU_1_GFLTRC_C0_RHWSW11_SHIFT          (11U)
#define VFCCU_1_GFLTRC_C0_RHWSW11_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW11(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW11_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW11_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW12_MASK           (0x1000U)
#define VFCCU_1_GFLTRC_C0_RHWSW12_SHIFT          (12U)
#define VFCCU_1_GFLTRC_C0_RHWSW12_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW12(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW12_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW12_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW13_MASK           (0x2000U)
#define VFCCU_1_GFLTRC_C0_RHWSW13_SHIFT          (13U)
#define VFCCU_1_GFLTRC_C0_RHWSW13_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW13(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW13_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW13_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW14_MASK           (0x4000U)
#define VFCCU_1_GFLTRC_C0_RHWSW14_SHIFT          (14U)
#define VFCCU_1_GFLTRC_C0_RHWSW14_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW14(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW14_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW14_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW15_MASK           (0x8000U)
#define VFCCU_1_GFLTRC_C0_RHWSW15_SHIFT          (15U)
#define VFCCU_1_GFLTRC_C0_RHWSW15_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW15(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW15_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW15_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW16_MASK           (0x10000U)
#define VFCCU_1_GFLTRC_C0_RHWSW16_SHIFT          (16U)
#define VFCCU_1_GFLTRC_C0_RHWSW16_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW16(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW16_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW16_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW17_MASK           (0x20000U)
#define VFCCU_1_GFLTRC_C0_RHWSW17_SHIFT          (17U)
#define VFCCU_1_GFLTRC_C0_RHWSW17_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW17(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW17_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW17_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW18_MASK           (0x40000U)
#define VFCCU_1_GFLTRC_C0_RHWSW18_SHIFT          (18U)
#define VFCCU_1_GFLTRC_C0_RHWSW18_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW18(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW18_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW18_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW19_MASK           (0x80000U)
#define VFCCU_1_GFLTRC_C0_RHWSW19_SHIFT          (19U)
#define VFCCU_1_GFLTRC_C0_RHWSW19_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW19(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW19_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW19_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW20_MASK           (0x100000U)
#define VFCCU_1_GFLTRC_C0_RHWSW20_SHIFT          (20U)
#define VFCCU_1_GFLTRC_C0_RHWSW20_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW20(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW20_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW20_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW21_MASK           (0x200000U)
#define VFCCU_1_GFLTRC_C0_RHWSW21_SHIFT          (21U)
#define VFCCU_1_GFLTRC_C0_RHWSW21_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW21(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW21_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW21_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW22_MASK           (0x400000U)
#define VFCCU_1_GFLTRC_C0_RHWSW22_SHIFT          (22U)
#define VFCCU_1_GFLTRC_C0_RHWSW22_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW22(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW22_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW22_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW23_MASK           (0x800000U)
#define VFCCU_1_GFLTRC_C0_RHWSW23_SHIFT          (23U)
#define VFCCU_1_GFLTRC_C0_RHWSW23_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW23(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW23_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW23_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW24_MASK           (0x1000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW24_SHIFT          (24U)
#define VFCCU_1_GFLTRC_C0_RHWSW24_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW24(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW24_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW24_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW25_MASK           (0x2000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW25_SHIFT          (25U)
#define VFCCU_1_GFLTRC_C0_RHWSW25_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW25(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW25_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW25_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW26_MASK           (0x4000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW26_SHIFT          (26U)
#define VFCCU_1_GFLTRC_C0_RHWSW26_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW26(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW26_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW26_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW27_MASK           (0x8000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW27_SHIFT          (27U)
#define VFCCU_1_GFLTRC_C0_RHWSW27_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW27(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW27_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW27_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW28_MASK           (0x10000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW28_SHIFT          (28U)
#define VFCCU_1_GFLTRC_C0_RHWSW28_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW28(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW28_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW28_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW29_MASK           (0x20000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW29_SHIFT          (29U)
#define VFCCU_1_GFLTRC_C0_RHWSW29_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW29(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW29_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW29_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW30_MASK           (0x40000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW30_SHIFT          (30U)
#define VFCCU_1_GFLTRC_C0_RHWSW30_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW30(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW30_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW30_MASK)

#define VFCCU_1_GFLTRC_C0_RHWSW31_MASK           (0x80000000U)
#define VFCCU_1_GFLTRC_C0_RHWSW31_SHIFT          (31U)
#define VFCCU_1_GFLTRC_C0_RHWSW31_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C0_RHWSW31(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C0_RHWSW31_SHIFT)) & VFCCU_1_GFLTRC_C0_RHWSW31_MASK)
/*! @} */

/*! @name GFLTRC_C1 - Global Fault Recovery */
/*! @{ */

#define VFCCU_1_GFLTRC_C1_RHWSW32_MASK           (0x1U)
#define VFCCU_1_GFLTRC_C1_RHWSW32_SHIFT          (0U)
#define VFCCU_1_GFLTRC_C1_RHWSW32_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW32(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW32_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW32_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW33_MASK           (0x2U)
#define VFCCU_1_GFLTRC_C1_RHWSW33_SHIFT          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW33_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW33(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW33_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW33_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW34_MASK           (0x4U)
#define VFCCU_1_GFLTRC_C1_RHWSW34_SHIFT          (2U)
#define VFCCU_1_GFLTRC_C1_RHWSW34_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW34(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW34_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW34_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW35_MASK           (0x8U)
#define VFCCU_1_GFLTRC_C1_RHWSW35_SHIFT          (3U)
#define VFCCU_1_GFLTRC_C1_RHWSW35_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW35(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW35_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW35_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW36_MASK           (0x10U)
#define VFCCU_1_GFLTRC_C1_RHWSW36_SHIFT          (4U)
#define VFCCU_1_GFLTRC_C1_RHWSW36_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW36(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW36_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW36_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW37_MASK           (0x20U)
#define VFCCU_1_GFLTRC_C1_RHWSW37_SHIFT          (5U)
#define VFCCU_1_GFLTRC_C1_RHWSW37_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW37(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW37_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW37_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW38_MASK           (0x40U)
#define VFCCU_1_GFLTRC_C1_RHWSW38_SHIFT          (6U)
#define VFCCU_1_GFLTRC_C1_RHWSW38_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW38(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW38_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW38_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW39_MASK           (0x80U)
#define VFCCU_1_GFLTRC_C1_RHWSW39_SHIFT          (7U)
#define VFCCU_1_GFLTRC_C1_RHWSW39_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW39(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW39_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW39_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW40_MASK           (0x100U)
#define VFCCU_1_GFLTRC_C1_RHWSW40_SHIFT          (8U)
#define VFCCU_1_GFLTRC_C1_RHWSW40_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW40(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW40_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW40_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW41_MASK           (0x200U)
#define VFCCU_1_GFLTRC_C1_RHWSW41_SHIFT          (9U)
#define VFCCU_1_GFLTRC_C1_RHWSW41_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW41(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW41_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW41_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW42_MASK           (0x400U)
#define VFCCU_1_GFLTRC_C1_RHWSW42_SHIFT          (10U)
#define VFCCU_1_GFLTRC_C1_RHWSW42_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW42(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW42_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW42_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW43_MASK           (0x800U)
#define VFCCU_1_GFLTRC_C1_RHWSW43_SHIFT          (11U)
#define VFCCU_1_GFLTRC_C1_RHWSW43_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW43(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW43_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW43_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW44_MASK           (0x1000U)
#define VFCCU_1_GFLTRC_C1_RHWSW44_SHIFT          (12U)
#define VFCCU_1_GFLTRC_C1_RHWSW44_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW44(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW44_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW44_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW45_MASK           (0x2000U)
#define VFCCU_1_GFLTRC_C1_RHWSW45_SHIFT          (13U)
#define VFCCU_1_GFLTRC_C1_RHWSW45_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW45(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW45_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW45_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW46_MASK           (0x4000U)
#define VFCCU_1_GFLTRC_C1_RHWSW46_SHIFT          (14U)
#define VFCCU_1_GFLTRC_C1_RHWSW46_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW46(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW46_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW46_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW47_MASK           (0x8000U)
#define VFCCU_1_GFLTRC_C1_RHWSW47_SHIFT          (15U)
#define VFCCU_1_GFLTRC_C1_RHWSW47_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW47(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW47_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW47_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW48_MASK           (0x10000U)
#define VFCCU_1_GFLTRC_C1_RHWSW48_SHIFT          (16U)
#define VFCCU_1_GFLTRC_C1_RHWSW48_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW48(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW48_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW48_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW49_MASK           (0x20000U)
#define VFCCU_1_GFLTRC_C1_RHWSW49_SHIFT          (17U)
#define VFCCU_1_GFLTRC_C1_RHWSW49_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW49(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW49_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW49_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW50_MASK           (0x40000U)
#define VFCCU_1_GFLTRC_C1_RHWSW50_SHIFT          (18U)
#define VFCCU_1_GFLTRC_C1_RHWSW50_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW50(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW50_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW50_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW51_MASK           (0x80000U)
#define VFCCU_1_GFLTRC_C1_RHWSW51_SHIFT          (19U)
#define VFCCU_1_GFLTRC_C1_RHWSW51_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW51(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW51_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW51_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW52_MASK           (0x100000U)
#define VFCCU_1_GFLTRC_C1_RHWSW52_SHIFT          (20U)
#define VFCCU_1_GFLTRC_C1_RHWSW52_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW52(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW52_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW52_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW53_MASK           (0x200000U)
#define VFCCU_1_GFLTRC_C1_RHWSW53_SHIFT          (21U)
#define VFCCU_1_GFLTRC_C1_RHWSW53_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW53(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW53_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW53_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW54_MASK           (0x400000U)
#define VFCCU_1_GFLTRC_C1_RHWSW54_SHIFT          (22U)
#define VFCCU_1_GFLTRC_C1_RHWSW54_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW54(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW54_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW54_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW55_MASK           (0x800000U)
#define VFCCU_1_GFLTRC_C1_RHWSW55_SHIFT          (23U)
#define VFCCU_1_GFLTRC_C1_RHWSW55_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW55(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW55_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW55_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW56_MASK           (0x1000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW56_SHIFT          (24U)
#define VFCCU_1_GFLTRC_C1_RHWSW56_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW56(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW56_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW56_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW57_MASK           (0x2000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW57_SHIFT          (25U)
#define VFCCU_1_GFLTRC_C1_RHWSW57_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW57(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW57_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW57_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW58_MASK           (0x4000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW58_SHIFT          (26U)
#define VFCCU_1_GFLTRC_C1_RHWSW58_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW58(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW58_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW58_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW59_MASK           (0x8000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW59_SHIFT          (27U)
#define VFCCU_1_GFLTRC_C1_RHWSW59_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW59(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW59_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW59_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW60_MASK           (0x10000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW60_SHIFT          (28U)
#define VFCCU_1_GFLTRC_C1_RHWSW60_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW60(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW60_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW60_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW61_MASK           (0x20000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW61_SHIFT          (29U)
#define VFCCU_1_GFLTRC_C1_RHWSW61_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW61(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW61_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW61_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW62_MASK           (0x40000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW62_SHIFT          (30U)
#define VFCCU_1_GFLTRC_C1_RHWSW62_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW62(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW62_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW62_MASK)

#define VFCCU_1_GFLTRC_C1_RHWSW63_MASK           (0x80000000U)
#define VFCCU_1_GFLTRC_C1_RHWSW63_SHIFT          (31U)
#define VFCCU_1_GFLTRC_C1_RHWSW63_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C1_RHWSW63(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C1_RHWSW63_SHIFT)) & VFCCU_1_GFLTRC_C1_RHWSW63_MASK)
/*! @} */

/*! @name GFLTRC_C2 - Global Fault Recovery */
/*! @{ */

#define VFCCU_1_GFLTRC_C2_RHWSW64_MASK           (0x1U)
#define VFCCU_1_GFLTRC_C2_RHWSW64_SHIFT          (0U)
#define VFCCU_1_GFLTRC_C2_RHWSW64_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW64(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW64_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW64_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW65_MASK           (0x2U)
#define VFCCU_1_GFLTRC_C2_RHWSW65_SHIFT          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW65_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW65(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW65_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW65_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW66_MASK           (0x4U)
#define VFCCU_1_GFLTRC_C2_RHWSW66_SHIFT          (2U)
#define VFCCU_1_GFLTRC_C2_RHWSW66_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW66(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW66_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW66_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW67_MASK           (0x8U)
#define VFCCU_1_GFLTRC_C2_RHWSW67_SHIFT          (3U)
#define VFCCU_1_GFLTRC_C2_RHWSW67_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW67(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW67_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW67_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW68_MASK           (0x10U)
#define VFCCU_1_GFLTRC_C2_RHWSW68_SHIFT          (4U)
#define VFCCU_1_GFLTRC_C2_RHWSW68_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW68(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW68_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW68_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW69_MASK           (0x20U)
#define VFCCU_1_GFLTRC_C2_RHWSW69_SHIFT          (5U)
#define VFCCU_1_GFLTRC_C2_RHWSW69_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW69(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW69_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW69_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW70_MASK           (0x40U)
#define VFCCU_1_GFLTRC_C2_RHWSW70_SHIFT          (6U)
#define VFCCU_1_GFLTRC_C2_RHWSW70_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW70(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW70_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW70_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW71_MASK           (0x80U)
#define VFCCU_1_GFLTRC_C2_RHWSW71_SHIFT          (7U)
#define VFCCU_1_GFLTRC_C2_RHWSW71_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW71(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW71_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW71_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW72_MASK           (0x100U)
#define VFCCU_1_GFLTRC_C2_RHWSW72_SHIFT          (8U)
#define VFCCU_1_GFLTRC_C2_RHWSW72_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW72(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW72_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW72_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW73_MASK           (0x200U)
#define VFCCU_1_GFLTRC_C2_RHWSW73_SHIFT          (9U)
#define VFCCU_1_GFLTRC_C2_RHWSW73_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW73(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW73_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW73_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW74_MASK           (0x400U)
#define VFCCU_1_GFLTRC_C2_RHWSW74_SHIFT          (10U)
#define VFCCU_1_GFLTRC_C2_RHWSW74_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW74(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW74_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW74_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW75_MASK           (0x800U)
#define VFCCU_1_GFLTRC_C2_RHWSW75_SHIFT          (11U)
#define VFCCU_1_GFLTRC_C2_RHWSW75_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW75(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW75_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW75_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW76_MASK           (0x1000U)
#define VFCCU_1_GFLTRC_C2_RHWSW76_SHIFT          (12U)
#define VFCCU_1_GFLTRC_C2_RHWSW76_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW76(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW76_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW76_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW77_MASK           (0x2000U)
#define VFCCU_1_GFLTRC_C2_RHWSW77_SHIFT          (13U)
#define VFCCU_1_GFLTRC_C2_RHWSW77_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW77(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW77_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW77_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW78_MASK           (0x4000U)
#define VFCCU_1_GFLTRC_C2_RHWSW78_SHIFT          (14U)
#define VFCCU_1_GFLTRC_C2_RHWSW78_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW78(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW78_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW78_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW79_MASK           (0x8000U)
#define VFCCU_1_GFLTRC_C2_RHWSW79_SHIFT          (15U)
#define VFCCU_1_GFLTRC_C2_RHWSW79_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW79(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW79_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW79_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW80_MASK           (0x10000U)
#define VFCCU_1_GFLTRC_C2_RHWSW80_SHIFT          (16U)
#define VFCCU_1_GFLTRC_C2_RHWSW80_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW80(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW80_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW80_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW81_MASK           (0x20000U)
#define VFCCU_1_GFLTRC_C2_RHWSW81_SHIFT          (17U)
#define VFCCU_1_GFLTRC_C2_RHWSW81_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW81(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW81_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW81_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW82_MASK           (0x40000U)
#define VFCCU_1_GFLTRC_C2_RHWSW82_SHIFT          (18U)
#define VFCCU_1_GFLTRC_C2_RHWSW82_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW82(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW82_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW82_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW83_MASK           (0x80000U)
#define VFCCU_1_GFLTRC_C2_RHWSW83_SHIFT          (19U)
#define VFCCU_1_GFLTRC_C2_RHWSW83_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW83(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW83_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW83_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW84_MASK           (0x100000U)
#define VFCCU_1_GFLTRC_C2_RHWSW84_SHIFT          (20U)
#define VFCCU_1_GFLTRC_C2_RHWSW84_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW84(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW84_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW84_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW85_MASK           (0x200000U)
#define VFCCU_1_GFLTRC_C2_RHWSW85_SHIFT          (21U)
#define VFCCU_1_GFLTRC_C2_RHWSW85_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW85(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW85_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW85_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW86_MASK           (0x400000U)
#define VFCCU_1_GFLTRC_C2_RHWSW86_SHIFT          (22U)
#define VFCCU_1_GFLTRC_C2_RHWSW86_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW86(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW86_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW86_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW87_MASK           (0x800000U)
#define VFCCU_1_GFLTRC_C2_RHWSW87_SHIFT          (23U)
#define VFCCU_1_GFLTRC_C2_RHWSW87_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW87(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW87_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW87_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW88_MASK           (0x1000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW88_SHIFT          (24U)
#define VFCCU_1_GFLTRC_C2_RHWSW88_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW88(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW88_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW88_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW89_MASK           (0x2000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW89_SHIFT          (25U)
#define VFCCU_1_GFLTRC_C2_RHWSW89_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW89(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW89_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW89_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW90_MASK           (0x4000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW90_SHIFT          (26U)
#define VFCCU_1_GFLTRC_C2_RHWSW90_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW90(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW90_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW90_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW91_MASK           (0x8000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW91_SHIFT          (27U)
#define VFCCU_1_GFLTRC_C2_RHWSW91_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW91(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW91_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW91_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW92_MASK           (0x10000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW92_SHIFT          (28U)
#define VFCCU_1_GFLTRC_C2_RHWSW92_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW92(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW92_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW92_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW93_MASK           (0x20000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW93_SHIFT          (29U)
#define VFCCU_1_GFLTRC_C2_RHWSW93_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW93(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW93_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW93_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW94_MASK           (0x40000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW94_SHIFT          (30U)
#define VFCCU_1_GFLTRC_C2_RHWSW94_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW94(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW94_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW94_MASK)

#define VFCCU_1_GFLTRC_C2_RHWSW95_MASK           (0x80000000U)
#define VFCCU_1_GFLTRC_C2_RHWSW95_SHIFT          (31U)
#define VFCCU_1_GFLTRC_C2_RHWSW95_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C2_RHWSW95(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C2_RHWSW95_SHIFT)) & VFCCU_1_GFLTRC_C2_RHWSW95_MASK)
/*! @} */

/*! @name GFLTRC_C3 - Global Fault Recovery */
/*! @{ */

#define VFCCU_1_GFLTRC_C3_RHWSW96_MASK           (0x1U)
#define VFCCU_1_GFLTRC_C3_RHWSW96_SHIFT          (0U)
#define VFCCU_1_GFLTRC_C3_RHWSW96_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW96(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW96_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW96_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW97_MASK           (0x2U)
#define VFCCU_1_GFLTRC_C3_RHWSW97_SHIFT          (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW97_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW97(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW97_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW97_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW98_MASK           (0x4U)
#define VFCCU_1_GFLTRC_C3_RHWSW98_SHIFT          (2U)
#define VFCCU_1_GFLTRC_C3_RHWSW98_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW98(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW98_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW98_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW99_MASK           (0x8U)
#define VFCCU_1_GFLTRC_C3_RHWSW99_SHIFT          (3U)
#define VFCCU_1_GFLTRC_C3_RHWSW99_WIDTH          (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW99(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW99_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW99_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW100_MASK          (0x10U)
#define VFCCU_1_GFLTRC_C3_RHWSW100_SHIFT         (4U)
#define VFCCU_1_GFLTRC_C3_RHWSW100_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW100(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW100_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW100_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW101_MASK          (0x20U)
#define VFCCU_1_GFLTRC_C3_RHWSW101_SHIFT         (5U)
#define VFCCU_1_GFLTRC_C3_RHWSW101_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW101(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW101_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW101_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW102_MASK          (0x40U)
#define VFCCU_1_GFLTRC_C3_RHWSW102_SHIFT         (6U)
#define VFCCU_1_GFLTRC_C3_RHWSW102_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW102(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW102_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW102_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW103_MASK          (0x80U)
#define VFCCU_1_GFLTRC_C3_RHWSW103_SHIFT         (7U)
#define VFCCU_1_GFLTRC_C3_RHWSW103_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW103(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW103_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW103_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW104_MASK          (0x100U)
#define VFCCU_1_GFLTRC_C3_RHWSW104_SHIFT         (8U)
#define VFCCU_1_GFLTRC_C3_RHWSW104_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW104(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW104_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW104_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW105_MASK          (0x200U)
#define VFCCU_1_GFLTRC_C3_RHWSW105_SHIFT         (9U)
#define VFCCU_1_GFLTRC_C3_RHWSW105_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW105(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW105_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW105_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW106_MASK          (0x400U)
#define VFCCU_1_GFLTRC_C3_RHWSW106_SHIFT         (10U)
#define VFCCU_1_GFLTRC_C3_RHWSW106_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW106(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW106_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW106_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW107_MASK          (0x800U)
#define VFCCU_1_GFLTRC_C3_RHWSW107_SHIFT         (11U)
#define VFCCU_1_GFLTRC_C3_RHWSW107_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW107(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW107_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW107_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW108_MASK          (0x1000U)
#define VFCCU_1_GFLTRC_C3_RHWSW108_SHIFT         (12U)
#define VFCCU_1_GFLTRC_C3_RHWSW108_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW108(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW108_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW108_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW109_MASK          (0x2000U)
#define VFCCU_1_GFLTRC_C3_RHWSW109_SHIFT         (13U)
#define VFCCU_1_GFLTRC_C3_RHWSW109_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW109(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW109_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW109_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW110_MASK          (0x4000U)
#define VFCCU_1_GFLTRC_C3_RHWSW110_SHIFT         (14U)
#define VFCCU_1_GFLTRC_C3_RHWSW110_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW110(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW110_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW110_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW111_MASK          (0x8000U)
#define VFCCU_1_GFLTRC_C3_RHWSW111_SHIFT         (15U)
#define VFCCU_1_GFLTRC_C3_RHWSW111_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW111(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW111_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW111_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW112_MASK          (0x10000U)
#define VFCCU_1_GFLTRC_C3_RHWSW112_SHIFT         (16U)
#define VFCCU_1_GFLTRC_C3_RHWSW112_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW112(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW112_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW112_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW113_MASK          (0x20000U)
#define VFCCU_1_GFLTRC_C3_RHWSW113_SHIFT         (17U)
#define VFCCU_1_GFLTRC_C3_RHWSW113_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW113(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW113_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW113_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW114_MASK          (0x40000U)
#define VFCCU_1_GFLTRC_C3_RHWSW114_SHIFT         (18U)
#define VFCCU_1_GFLTRC_C3_RHWSW114_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW114(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW114_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW114_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW115_MASK          (0x80000U)
#define VFCCU_1_GFLTRC_C3_RHWSW115_SHIFT         (19U)
#define VFCCU_1_GFLTRC_C3_RHWSW115_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW115(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW115_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW115_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW116_MASK          (0x100000U)
#define VFCCU_1_GFLTRC_C3_RHWSW116_SHIFT         (20U)
#define VFCCU_1_GFLTRC_C3_RHWSW116_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW116(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW116_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW116_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW117_MASK          (0x200000U)
#define VFCCU_1_GFLTRC_C3_RHWSW117_SHIFT         (21U)
#define VFCCU_1_GFLTRC_C3_RHWSW117_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW117(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW117_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW117_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW118_MASK          (0x400000U)
#define VFCCU_1_GFLTRC_C3_RHWSW118_SHIFT         (22U)
#define VFCCU_1_GFLTRC_C3_RHWSW118_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW118(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW118_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW118_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW119_MASK          (0x800000U)
#define VFCCU_1_GFLTRC_C3_RHWSW119_SHIFT         (23U)
#define VFCCU_1_GFLTRC_C3_RHWSW119_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW119(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW119_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW119_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW120_MASK          (0x1000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW120_SHIFT         (24U)
#define VFCCU_1_GFLTRC_C3_RHWSW120_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW120(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW120_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW120_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW121_MASK          (0x2000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW121_SHIFT         (25U)
#define VFCCU_1_GFLTRC_C3_RHWSW121_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW121(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW121_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW121_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW122_MASK          (0x4000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW122_SHIFT         (26U)
#define VFCCU_1_GFLTRC_C3_RHWSW122_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW122(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW122_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW122_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW123_MASK          (0x8000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW123_SHIFT         (27U)
#define VFCCU_1_GFLTRC_C3_RHWSW123_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW123(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW123_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW123_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW124_MASK          (0x10000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW124_SHIFT         (28U)
#define VFCCU_1_GFLTRC_C3_RHWSW124_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW124(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW124_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW124_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW125_MASK          (0x20000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW125_SHIFT         (29U)
#define VFCCU_1_GFLTRC_C3_RHWSW125_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW125(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW125_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW125_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW126_MASK          (0x40000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW126_SHIFT         (30U)
#define VFCCU_1_GFLTRC_C3_RHWSW126_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW126(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW126_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW126_MASK)

#define VFCCU_1_GFLTRC_C3_RHWSW127_MASK          (0x80000000U)
#define VFCCU_1_GFLTRC_C3_RHWSW127_SHIFT         (31U)
#define VFCCU_1_GFLTRC_C3_RHWSW127_WIDTH         (1U)
#define VFCCU_1_GFLTRC_C3_RHWSW127(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GFLTRC_C3_RHWSW127_SHIFT)) & VFCCU_1_GFLTRC_C3_RHWSW127_MASK)
/*! @} */

/*! @name GINTOVFS - Global DID FSM Status */
/*! @{ */

#define VFCCU_1_GINTOVFS_FLTSERV_MASK            (0x80U)
#define VFCCU_1_GINTOVFS_FLTSERV_SHIFT           (7U)
#define VFCCU_1_GINTOVFS_FLTSERV_WIDTH           (1U)
#define VFCCU_1_GINTOVFS_FLTSERV(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GINTOVFS_FLTSERV_SHIFT)) & VFCCU_1_GINTOVFS_FLTSERV_MASK)

#define VFCCU_1_GINTOVFS_SERV_DID_MASK           (0xF0000U)
#define VFCCU_1_GINTOVFS_SERV_DID_SHIFT          (16U)
#define VFCCU_1_GINTOVFS_SERV_DID_WIDTH          (4U)
#define VFCCU_1_GINTOVFS_SERV_DID(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GINTOVFS_SERV_DID_SHIFT)) & VFCCU_1_GINTOVFS_SERV_DID_MASK)
/*! @} */

/*! @name GDBGCFG - Global Debug */
/*! @{ */

#define VFCCU_1_GDBGCFG_FRZ_MASK                 (0x10000U)
#define VFCCU_1_GDBGCFG_FRZ_SHIFT                (16U)
#define VFCCU_1_GDBGCFG_FRZ_WIDTH                (1U)
#define VFCCU_1_GDBGCFG_FRZ(x)                   (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GDBGCFG_FRZ_SHIFT)) & VFCCU_1_GDBGCFG_FRZ_MASK)
/*! @} */

/*! @name GDBGSTAT - Global Debug Status */
/*! @{ */

#define VFCCU_1_GDBGSTAT_FLTIND_MASK             (0xFFU)
#define VFCCU_1_GDBGSTAT_FLTIND_SHIFT            (0U)
#define VFCCU_1_GDBGSTAT_FLTIND_WIDTH            (8U)
#define VFCCU_1_GDBGSTAT_FLTIND(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GDBGSTAT_FLTIND_SHIFT)) & VFCCU_1_GDBGSTAT_FLTIND_MASK)

#define VFCCU_1_GDBGSTAT_RKN_ACK_MASK            (0x40000000U)
#define VFCCU_1_GDBGSTAT_RKN_ACK_SHIFT           (30U)
#define VFCCU_1_GDBGSTAT_RKN_ACK_WIDTH           (1U)
#define VFCCU_1_GDBGSTAT_RKN_ACK(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GDBGSTAT_RKN_ACK_SHIFT)) & VFCCU_1_GDBGSTAT_RKN_ACK_MASK)

#define VFCCU_1_GDBGSTAT_RKN_REQ_MASK            (0x80000000U)
#define VFCCU_1_GDBGSTAT_RKN_REQ_SHIFT           (31U)
#define VFCCU_1_GDBGSTAT_RKN_REQ_WIDTH           (1U)
#define VFCCU_1_GDBGSTAT_RKN_REQ(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_GDBGSTAT_RKN_REQ_SHIFT)) & VFCCU_1_GDBGSTAT_RKN_REQ_MASK)
/*! @} */

/*! @name FHCFG0 - Fault Handler */
/*! @{ */

#define VFCCU_1_FHCFG0_FHIDEN_MASK               (0x1U)
#define VFCCU_1_FHCFG0_FHIDEN_SHIFT              (0U)
#define VFCCU_1_FHCFG0_FHIDEN_WIDTH              (1U)
#define VFCCU_1_FHCFG0_FHIDEN(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHCFG0_FHIDEN_SHIFT)) & VFCCU_1_FHCFG0_FHIDEN_MASK)
/*! @} */

/*! @name FHSRVDS0 - Fault Handler Status */
/*! @{ */

#define VFCCU_1_FHSRVDS0_SERV_DID_MASK           (0xFU)
#define VFCCU_1_FHSRVDS0_SERV_DID_SHIFT          (0U)
#define VFCCU_1_FHSRVDS0_SERV_DID_WIDTH          (4U)
#define VFCCU_1_FHSRVDS0_SERV_DID(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHSRVDS0_SERV_DID_SHIFT)) & VFCCU_1_FHSRVDS0_SERV_DID_MASK)

#define VFCCU_1_FHSRVDS0_AGGFLTS_MASK            (0x100U)
#define VFCCU_1_FHSRVDS0_AGGFLTS_SHIFT           (8U)
#define VFCCU_1_FHSRVDS0_AGGFLTS_WIDTH           (1U)
#define VFCCU_1_FHSRVDS0_AGGFLTS(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHSRVDS0_AGGFLTS_SHIFT)) & VFCCU_1_FHSRVDS0_AGGFLTS_MASK)
/*! @} */

/*! @name FHFLTENC0_0 - Fault Enable */
/*! @{ */

#define VFCCU_1_FHFLTENC0_0_EN0_MASK             (0x1U)
#define VFCCU_1_FHFLTENC0_0_EN0_SHIFT            (0U)
#define VFCCU_1_FHFLTENC0_0_EN0_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN0(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN0_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN0_MASK)

#define VFCCU_1_FHFLTENC0_0_EN1_MASK             (0x2U)
#define VFCCU_1_FHFLTENC0_0_EN1_SHIFT            (1U)
#define VFCCU_1_FHFLTENC0_0_EN1_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN1(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN1_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN1_MASK)

#define VFCCU_1_FHFLTENC0_0_EN2_MASK             (0x4U)
#define VFCCU_1_FHFLTENC0_0_EN2_SHIFT            (2U)
#define VFCCU_1_FHFLTENC0_0_EN2_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN2(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN2_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN2_MASK)

#define VFCCU_1_FHFLTENC0_0_EN3_MASK             (0x8U)
#define VFCCU_1_FHFLTENC0_0_EN3_SHIFT            (3U)
#define VFCCU_1_FHFLTENC0_0_EN3_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN3(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN3_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN3_MASK)

#define VFCCU_1_FHFLTENC0_0_EN4_MASK             (0x10U)
#define VFCCU_1_FHFLTENC0_0_EN4_SHIFT            (4U)
#define VFCCU_1_FHFLTENC0_0_EN4_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN4(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN4_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN4_MASK)

#define VFCCU_1_FHFLTENC0_0_EN5_MASK             (0x20U)
#define VFCCU_1_FHFLTENC0_0_EN5_SHIFT            (5U)
#define VFCCU_1_FHFLTENC0_0_EN5_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN5(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN5_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN5_MASK)

#define VFCCU_1_FHFLTENC0_0_EN6_MASK             (0x40U)
#define VFCCU_1_FHFLTENC0_0_EN6_SHIFT            (6U)
#define VFCCU_1_FHFLTENC0_0_EN6_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN6(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN6_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN6_MASK)

#define VFCCU_1_FHFLTENC0_0_EN7_MASK             (0x80U)
#define VFCCU_1_FHFLTENC0_0_EN7_SHIFT            (7U)
#define VFCCU_1_FHFLTENC0_0_EN7_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN7(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN7_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN7_MASK)

#define VFCCU_1_FHFLTENC0_0_EN8_MASK             (0x100U)
#define VFCCU_1_FHFLTENC0_0_EN8_SHIFT            (8U)
#define VFCCU_1_FHFLTENC0_0_EN8_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN8(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN8_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN8_MASK)

#define VFCCU_1_FHFLTENC0_0_EN9_MASK             (0x200U)
#define VFCCU_1_FHFLTENC0_0_EN9_SHIFT            (9U)
#define VFCCU_1_FHFLTENC0_0_EN9_WIDTH            (1U)
#define VFCCU_1_FHFLTENC0_0_EN9(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN9_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN9_MASK)

#define VFCCU_1_FHFLTENC0_0_EN10_MASK            (0x400U)
#define VFCCU_1_FHFLTENC0_0_EN10_SHIFT           (10U)
#define VFCCU_1_FHFLTENC0_0_EN10_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN10(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN10_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN10_MASK)

#define VFCCU_1_FHFLTENC0_0_EN11_MASK            (0x800U)
#define VFCCU_1_FHFLTENC0_0_EN11_SHIFT           (11U)
#define VFCCU_1_FHFLTENC0_0_EN11_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN11(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN11_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN11_MASK)

#define VFCCU_1_FHFLTENC0_0_EN12_MASK            (0x1000U)
#define VFCCU_1_FHFLTENC0_0_EN12_SHIFT           (12U)
#define VFCCU_1_FHFLTENC0_0_EN12_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN12(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN12_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN12_MASK)

#define VFCCU_1_FHFLTENC0_0_EN13_MASK            (0x2000U)
#define VFCCU_1_FHFLTENC0_0_EN13_SHIFT           (13U)
#define VFCCU_1_FHFLTENC0_0_EN13_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN13(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN13_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN13_MASK)

#define VFCCU_1_FHFLTENC0_0_EN14_MASK            (0x4000U)
#define VFCCU_1_FHFLTENC0_0_EN14_SHIFT           (14U)
#define VFCCU_1_FHFLTENC0_0_EN14_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN14(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN14_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN14_MASK)

#define VFCCU_1_FHFLTENC0_0_EN15_MASK            (0x8000U)
#define VFCCU_1_FHFLTENC0_0_EN15_SHIFT           (15U)
#define VFCCU_1_FHFLTENC0_0_EN15_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN15(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN15_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN15_MASK)

#define VFCCU_1_FHFLTENC0_0_EN16_MASK            (0x10000U)
#define VFCCU_1_FHFLTENC0_0_EN16_SHIFT           (16U)
#define VFCCU_1_FHFLTENC0_0_EN16_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN16(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN16_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN16_MASK)

#define VFCCU_1_FHFLTENC0_0_EN17_MASK            (0x20000U)
#define VFCCU_1_FHFLTENC0_0_EN17_SHIFT           (17U)
#define VFCCU_1_FHFLTENC0_0_EN17_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN17(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN17_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN17_MASK)

#define VFCCU_1_FHFLTENC0_0_EN18_MASK            (0x40000U)
#define VFCCU_1_FHFLTENC0_0_EN18_SHIFT           (18U)
#define VFCCU_1_FHFLTENC0_0_EN18_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN18(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN18_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN18_MASK)

#define VFCCU_1_FHFLTENC0_0_EN19_MASK            (0x80000U)
#define VFCCU_1_FHFLTENC0_0_EN19_SHIFT           (19U)
#define VFCCU_1_FHFLTENC0_0_EN19_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN19(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN19_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN19_MASK)

#define VFCCU_1_FHFLTENC0_0_EN20_MASK            (0x100000U)
#define VFCCU_1_FHFLTENC0_0_EN20_SHIFT           (20U)
#define VFCCU_1_FHFLTENC0_0_EN20_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN20(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN20_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN20_MASK)

#define VFCCU_1_FHFLTENC0_0_EN21_MASK            (0x200000U)
#define VFCCU_1_FHFLTENC0_0_EN21_SHIFT           (21U)
#define VFCCU_1_FHFLTENC0_0_EN21_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN21(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN21_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN21_MASK)

#define VFCCU_1_FHFLTENC0_0_EN22_MASK            (0x400000U)
#define VFCCU_1_FHFLTENC0_0_EN22_SHIFT           (22U)
#define VFCCU_1_FHFLTENC0_0_EN22_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN22(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN22_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN22_MASK)

#define VFCCU_1_FHFLTENC0_0_EN23_MASK            (0x800000U)
#define VFCCU_1_FHFLTENC0_0_EN23_SHIFT           (23U)
#define VFCCU_1_FHFLTENC0_0_EN23_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN23(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN23_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN23_MASK)

#define VFCCU_1_FHFLTENC0_0_EN24_MASK            (0x1000000U)
#define VFCCU_1_FHFLTENC0_0_EN24_SHIFT           (24U)
#define VFCCU_1_FHFLTENC0_0_EN24_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN24(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN24_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN24_MASK)

#define VFCCU_1_FHFLTENC0_0_EN25_MASK            (0x2000000U)
#define VFCCU_1_FHFLTENC0_0_EN25_SHIFT           (25U)
#define VFCCU_1_FHFLTENC0_0_EN25_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN25(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN25_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN25_MASK)

#define VFCCU_1_FHFLTENC0_0_EN26_MASK            (0x4000000U)
#define VFCCU_1_FHFLTENC0_0_EN26_SHIFT           (26U)
#define VFCCU_1_FHFLTENC0_0_EN26_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN26(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN26_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN26_MASK)

#define VFCCU_1_FHFLTENC0_0_EN27_MASK            (0x8000000U)
#define VFCCU_1_FHFLTENC0_0_EN27_SHIFT           (27U)
#define VFCCU_1_FHFLTENC0_0_EN27_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN27(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN27_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN27_MASK)

#define VFCCU_1_FHFLTENC0_0_EN28_MASK            (0x10000000U)
#define VFCCU_1_FHFLTENC0_0_EN28_SHIFT           (28U)
#define VFCCU_1_FHFLTENC0_0_EN28_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN28(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN28_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN28_MASK)

#define VFCCU_1_FHFLTENC0_0_EN29_MASK            (0x20000000U)
#define VFCCU_1_FHFLTENC0_0_EN29_SHIFT           (29U)
#define VFCCU_1_FHFLTENC0_0_EN29_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN29(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN29_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN29_MASK)

#define VFCCU_1_FHFLTENC0_0_EN30_MASK            (0x40000000U)
#define VFCCU_1_FHFLTENC0_0_EN30_SHIFT           (30U)
#define VFCCU_1_FHFLTENC0_0_EN30_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN30(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN30_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN30_MASK)

#define VFCCU_1_FHFLTENC0_0_EN31_MASK            (0x80000000U)
#define VFCCU_1_FHFLTENC0_0_EN31_SHIFT           (31U)
#define VFCCU_1_FHFLTENC0_0_EN31_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_0_EN31(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_0_EN31_SHIFT)) & VFCCU_1_FHFLTENC0_0_EN31_MASK)
/*! @} */

/*! @name FHFLTENC0_1 - Fault Enable */
/*! @{ */

#define VFCCU_1_FHFLTENC0_1_EN32_MASK            (0x1U)
#define VFCCU_1_FHFLTENC0_1_EN32_SHIFT           (0U)
#define VFCCU_1_FHFLTENC0_1_EN32_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN32(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN32_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN32_MASK)

#define VFCCU_1_FHFLTENC0_1_EN33_MASK            (0x2U)
#define VFCCU_1_FHFLTENC0_1_EN33_SHIFT           (1U)
#define VFCCU_1_FHFLTENC0_1_EN33_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN33(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN33_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN33_MASK)

#define VFCCU_1_FHFLTENC0_1_EN34_MASK            (0x4U)
#define VFCCU_1_FHFLTENC0_1_EN34_SHIFT           (2U)
#define VFCCU_1_FHFLTENC0_1_EN34_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN34(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN34_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN34_MASK)

#define VFCCU_1_FHFLTENC0_1_EN35_MASK            (0x8U)
#define VFCCU_1_FHFLTENC0_1_EN35_SHIFT           (3U)
#define VFCCU_1_FHFLTENC0_1_EN35_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN35(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN35_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN35_MASK)

#define VFCCU_1_FHFLTENC0_1_EN36_MASK            (0x10U)
#define VFCCU_1_FHFLTENC0_1_EN36_SHIFT           (4U)
#define VFCCU_1_FHFLTENC0_1_EN36_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN36(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN36_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN36_MASK)

#define VFCCU_1_FHFLTENC0_1_EN37_MASK            (0x20U)
#define VFCCU_1_FHFLTENC0_1_EN37_SHIFT           (5U)
#define VFCCU_1_FHFLTENC0_1_EN37_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN37(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN37_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN37_MASK)

#define VFCCU_1_FHFLTENC0_1_EN38_MASK            (0x40U)
#define VFCCU_1_FHFLTENC0_1_EN38_SHIFT           (6U)
#define VFCCU_1_FHFLTENC0_1_EN38_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN38(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN38_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN38_MASK)

#define VFCCU_1_FHFLTENC0_1_EN39_MASK            (0x80U)
#define VFCCU_1_FHFLTENC0_1_EN39_SHIFT           (7U)
#define VFCCU_1_FHFLTENC0_1_EN39_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN39(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN39_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN39_MASK)

#define VFCCU_1_FHFLTENC0_1_EN40_MASK            (0x100U)
#define VFCCU_1_FHFLTENC0_1_EN40_SHIFT           (8U)
#define VFCCU_1_FHFLTENC0_1_EN40_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN40(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN40_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN40_MASK)

#define VFCCU_1_FHFLTENC0_1_EN41_MASK            (0x200U)
#define VFCCU_1_FHFLTENC0_1_EN41_SHIFT           (9U)
#define VFCCU_1_FHFLTENC0_1_EN41_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN41(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN41_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN41_MASK)

#define VFCCU_1_FHFLTENC0_1_EN42_MASK            (0x400U)
#define VFCCU_1_FHFLTENC0_1_EN42_SHIFT           (10U)
#define VFCCU_1_FHFLTENC0_1_EN42_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN42(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN42_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN42_MASK)

#define VFCCU_1_FHFLTENC0_1_EN43_MASK            (0x800U)
#define VFCCU_1_FHFLTENC0_1_EN43_SHIFT           (11U)
#define VFCCU_1_FHFLTENC0_1_EN43_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN43(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN43_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN43_MASK)

#define VFCCU_1_FHFLTENC0_1_EN44_MASK            (0x1000U)
#define VFCCU_1_FHFLTENC0_1_EN44_SHIFT           (12U)
#define VFCCU_1_FHFLTENC0_1_EN44_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN44(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN44_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN44_MASK)

#define VFCCU_1_FHFLTENC0_1_EN45_MASK            (0x2000U)
#define VFCCU_1_FHFLTENC0_1_EN45_SHIFT           (13U)
#define VFCCU_1_FHFLTENC0_1_EN45_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN45(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN45_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN45_MASK)

#define VFCCU_1_FHFLTENC0_1_EN46_MASK            (0x4000U)
#define VFCCU_1_FHFLTENC0_1_EN46_SHIFT           (14U)
#define VFCCU_1_FHFLTENC0_1_EN46_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN46(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN46_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN46_MASK)

#define VFCCU_1_FHFLTENC0_1_EN47_MASK            (0x8000U)
#define VFCCU_1_FHFLTENC0_1_EN47_SHIFT           (15U)
#define VFCCU_1_FHFLTENC0_1_EN47_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN47(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN47_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN47_MASK)

#define VFCCU_1_FHFLTENC0_1_EN48_MASK            (0x10000U)
#define VFCCU_1_FHFLTENC0_1_EN48_SHIFT           (16U)
#define VFCCU_1_FHFLTENC0_1_EN48_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN48(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN48_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN48_MASK)

#define VFCCU_1_FHFLTENC0_1_EN49_MASK            (0x20000U)
#define VFCCU_1_FHFLTENC0_1_EN49_SHIFT           (17U)
#define VFCCU_1_FHFLTENC0_1_EN49_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN49(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN49_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN49_MASK)

#define VFCCU_1_FHFLTENC0_1_EN50_MASK            (0x40000U)
#define VFCCU_1_FHFLTENC0_1_EN50_SHIFT           (18U)
#define VFCCU_1_FHFLTENC0_1_EN50_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN50(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN50_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN50_MASK)

#define VFCCU_1_FHFLTENC0_1_EN51_MASK            (0x80000U)
#define VFCCU_1_FHFLTENC0_1_EN51_SHIFT           (19U)
#define VFCCU_1_FHFLTENC0_1_EN51_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN51(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN51_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN51_MASK)

#define VFCCU_1_FHFLTENC0_1_EN52_MASK            (0x100000U)
#define VFCCU_1_FHFLTENC0_1_EN52_SHIFT           (20U)
#define VFCCU_1_FHFLTENC0_1_EN52_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN52(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN52_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN52_MASK)

#define VFCCU_1_FHFLTENC0_1_EN53_MASK            (0x200000U)
#define VFCCU_1_FHFLTENC0_1_EN53_SHIFT           (21U)
#define VFCCU_1_FHFLTENC0_1_EN53_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN53(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN53_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN53_MASK)

#define VFCCU_1_FHFLTENC0_1_EN54_MASK            (0x400000U)
#define VFCCU_1_FHFLTENC0_1_EN54_SHIFT           (22U)
#define VFCCU_1_FHFLTENC0_1_EN54_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN54(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN54_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN54_MASK)

#define VFCCU_1_FHFLTENC0_1_EN55_MASK            (0x800000U)
#define VFCCU_1_FHFLTENC0_1_EN55_SHIFT           (23U)
#define VFCCU_1_FHFLTENC0_1_EN55_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN55(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN55_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN55_MASK)

#define VFCCU_1_FHFLTENC0_1_EN56_MASK            (0x1000000U)
#define VFCCU_1_FHFLTENC0_1_EN56_SHIFT           (24U)
#define VFCCU_1_FHFLTENC0_1_EN56_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN56(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN56_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN56_MASK)

#define VFCCU_1_FHFLTENC0_1_EN57_MASK            (0x2000000U)
#define VFCCU_1_FHFLTENC0_1_EN57_SHIFT           (25U)
#define VFCCU_1_FHFLTENC0_1_EN57_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN57(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN57_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN57_MASK)

#define VFCCU_1_FHFLTENC0_1_EN58_MASK            (0x4000000U)
#define VFCCU_1_FHFLTENC0_1_EN58_SHIFT           (26U)
#define VFCCU_1_FHFLTENC0_1_EN58_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN58(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN58_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN58_MASK)

#define VFCCU_1_FHFLTENC0_1_EN59_MASK            (0x8000000U)
#define VFCCU_1_FHFLTENC0_1_EN59_SHIFT           (27U)
#define VFCCU_1_FHFLTENC0_1_EN59_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN59(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN59_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN59_MASK)

#define VFCCU_1_FHFLTENC0_1_EN60_MASK            (0x10000000U)
#define VFCCU_1_FHFLTENC0_1_EN60_SHIFT           (28U)
#define VFCCU_1_FHFLTENC0_1_EN60_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN60(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN60_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN60_MASK)

#define VFCCU_1_FHFLTENC0_1_EN61_MASK            (0x20000000U)
#define VFCCU_1_FHFLTENC0_1_EN61_SHIFT           (29U)
#define VFCCU_1_FHFLTENC0_1_EN61_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN61(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN61_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN61_MASK)

#define VFCCU_1_FHFLTENC0_1_EN62_MASK            (0x40000000U)
#define VFCCU_1_FHFLTENC0_1_EN62_SHIFT           (30U)
#define VFCCU_1_FHFLTENC0_1_EN62_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN62(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN62_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN62_MASK)

#define VFCCU_1_FHFLTENC0_1_EN63_MASK            (0x80000000U)
#define VFCCU_1_FHFLTENC0_1_EN63_SHIFT           (31U)
#define VFCCU_1_FHFLTENC0_1_EN63_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_1_EN63(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_1_EN63_SHIFT)) & VFCCU_1_FHFLTENC0_1_EN63_MASK)
/*! @} */

/*! @name FHFLTENC0_2 - Fault Enable */
/*! @{ */

#define VFCCU_1_FHFLTENC0_2_EN64_MASK            (0x1U)
#define VFCCU_1_FHFLTENC0_2_EN64_SHIFT           (0U)
#define VFCCU_1_FHFLTENC0_2_EN64_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN64(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN64_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN64_MASK)

#define VFCCU_1_FHFLTENC0_2_EN65_MASK            (0x2U)
#define VFCCU_1_FHFLTENC0_2_EN65_SHIFT           (1U)
#define VFCCU_1_FHFLTENC0_2_EN65_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN65(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN65_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN65_MASK)

#define VFCCU_1_FHFLTENC0_2_EN66_MASK            (0x4U)
#define VFCCU_1_FHFLTENC0_2_EN66_SHIFT           (2U)
#define VFCCU_1_FHFLTENC0_2_EN66_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN66(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN66_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN66_MASK)

#define VFCCU_1_FHFLTENC0_2_EN67_MASK            (0x8U)
#define VFCCU_1_FHFLTENC0_2_EN67_SHIFT           (3U)
#define VFCCU_1_FHFLTENC0_2_EN67_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN67(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN67_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN67_MASK)

#define VFCCU_1_FHFLTENC0_2_EN68_MASK            (0x10U)
#define VFCCU_1_FHFLTENC0_2_EN68_SHIFT           (4U)
#define VFCCU_1_FHFLTENC0_2_EN68_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN68(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN68_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN68_MASK)

#define VFCCU_1_FHFLTENC0_2_EN69_MASK            (0x20U)
#define VFCCU_1_FHFLTENC0_2_EN69_SHIFT           (5U)
#define VFCCU_1_FHFLTENC0_2_EN69_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN69(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN69_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN69_MASK)

#define VFCCU_1_FHFLTENC0_2_EN70_MASK            (0x40U)
#define VFCCU_1_FHFLTENC0_2_EN70_SHIFT           (6U)
#define VFCCU_1_FHFLTENC0_2_EN70_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN70(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN70_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN70_MASK)

#define VFCCU_1_FHFLTENC0_2_EN71_MASK            (0x80U)
#define VFCCU_1_FHFLTENC0_2_EN71_SHIFT           (7U)
#define VFCCU_1_FHFLTENC0_2_EN71_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN71(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN71_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN71_MASK)

#define VFCCU_1_FHFLTENC0_2_EN72_MASK            (0x100U)
#define VFCCU_1_FHFLTENC0_2_EN72_SHIFT           (8U)
#define VFCCU_1_FHFLTENC0_2_EN72_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN72(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN72_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN72_MASK)

#define VFCCU_1_FHFLTENC0_2_EN73_MASK            (0x200U)
#define VFCCU_1_FHFLTENC0_2_EN73_SHIFT           (9U)
#define VFCCU_1_FHFLTENC0_2_EN73_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN73(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN73_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN73_MASK)

#define VFCCU_1_FHFLTENC0_2_EN74_MASK            (0x400U)
#define VFCCU_1_FHFLTENC0_2_EN74_SHIFT           (10U)
#define VFCCU_1_FHFLTENC0_2_EN74_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN74(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN74_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN74_MASK)

#define VFCCU_1_FHFLTENC0_2_EN75_MASK            (0x800U)
#define VFCCU_1_FHFLTENC0_2_EN75_SHIFT           (11U)
#define VFCCU_1_FHFLTENC0_2_EN75_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN75(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN75_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN75_MASK)

#define VFCCU_1_FHFLTENC0_2_EN76_MASK            (0x1000U)
#define VFCCU_1_FHFLTENC0_2_EN76_SHIFT           (12U)
#define VFCCU_1_FHFLTENC0_2_EN76_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN76(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN76_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN76_MASK)

#define VFCCU_1_FHFLTENC0_2_EN77_MASK            (0x2000U)
#define VFCCU_1_FHFLTENC0_2_EN77_SHIFT           (13U)
#define VFCCU_1_FHFLTENC0_2_EN77_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN77(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN77_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN77_MASK)

#define VFCCU_1_FHFLTENC0_2_EN78_MASK            (0x4000U)
#define VFCCU_1_FHFLTENC0_2_EN78_SHIFT           (14U)
#define VFCCU_1_FHFLTENC0_2_EN78_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN78(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN78_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN78_MASK)

#define VFCCU_1_FHFLTENC0_2_EN79_MASK            (0x8000U)
#define VFCCU_1_FHFLTENC0_2_EN79_SHIFT           (15U)
#define VFCCU_1_FHFLTENC0_2_EN79_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN79(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN79_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN79_MASK)

#define VFCCU_1_FHFLTENC0_2_EN80_MASK            (0x10000U)
#define VFCCU_1_FHFLTENC0_2_EN80_SHIFT           (16U)
#define VFCCU_1_FHFLTENC0_2_EN80_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN80(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN80_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN80_MASK)

#define VFCCU_1_FHFLTENC0_2_EN81_MASK            (0x20000U)
#define VFCCU_1_FHFLTENC0_2_EN81_SHIFT           (17U)
#define VFCCU_1_FHFLTENC0_2_EN81_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN81(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN81_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN81_MASK)

#define VFCCU_1_FHFLTENC0_2_EN82_MASK            (0x40000U)
#define VFCCU_1_FHFLTENC0_2_EN82_SHIFT           (18U)
#define VFCCU_1_FHFLTENC0_2_EN82_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN82(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN82_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN82_MASK)

#define VFCCU_1_FHFLTENC0_2_EN83_MASK            (0x80000U)
#define VFCCU_1_FHFLTENC0_2_EN83_SHIFT           (19U)
#define VFCCU_1_FHFLTENC0_2_EN83_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN83(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN83_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN83_MASK)

#define VFCCU_1_FHFLTENC0_2_EN84_MASK            (0x100000U)
#define VFCCU_1_FHFLTENC0_2_EN84_SHIFT           (20U)
#define VFCCU_1_FHFLTENC0_2_EN84_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN84(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN84_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN84_MASK)

#define VFCCU_1_FHFLTENC0_2_EN85_MASK            (0x200000U)
#define VFCCU_1_FHFLTENC0_2_EN85_SHIFT           (21U)
#define VFCCU_1_FHFLTENC0_2_EN85_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN85(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN85_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN85_MASK)

#define VFCCU_1_FHFLTENC0_2_EN86_MASK            (0x400000U)
#define VFCCU_1_FHFLTENC0_2_EN86_SHIFT           (22U)
#define VFCCU_1_FHFLTENC0_2_EN86_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN86(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN86_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN86_MASK)

#define VFCCU_1_FHFLTENC0_2_EN87_MASK            (0x800000U)
#define VFCCU_1_FHFLTENC0_2_EN87_SHIFT           (23U)
#define VFCCU_1_FHFLTENC0_2_EN87_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN87(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN87_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN87_MASK)

#define VFCCU_1_FHFLTENC0_2_EN88_MASK            (0x1000000U)
#define VFCCU_1_FHFLTENC0_2_EN88_SHIFT           (24U)
#define VFCCU_1_FHFLTENC0_2_EN88_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN88(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN88_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN88_MASK)

#define VFCCU_1_FHFLTENC0_2_EN89_MASK            (0x2000000U)
#define VFCCU_1_FHFLTENC0_2_EN89_SHIFT           (25U)
#define VFCCU_1_FHFLTENC0_2_EN89_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN89(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN89_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN89_MASK)

#define VFCCU_1_FHFLTENC0_2_EN90_MASK            (0x4000000U)
#define VFCCU_1_FHFLTENC0_2_EN90_SHIFT           (26U)
#define VFCCU_1_FHFLTENC0_2_EN90_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN90(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN90_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN90_MASK)

#define VFCCU_1_FHFLTENC0_2_EN91_MASK            (0x8000000U)
#define VFCCU_1_FHFLTENC0_2_EN91_SHIFT           (27U)
#define VFCCU_1_FHFLTENC0_2_EN91_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN91(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN91_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN91_MASK)

#define VFCCU_1_FHFLTENC0_2_EN92_MASK            (0x10000000U)
#define VFCCU_1_FHFLTENC0_2_EN92_SHIFT           (28U)
#define VFCCU_1_FHFLTENC0_2_EN92_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN92(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN92_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN92_MASK)

#define VFCCU_1_FHFLTENC0_2_EN93_MASK            (0x20000000U)
#define VFCCU_1_FHFLTENC0_2_EN93_SHIFT           (29U)
#define VFCCU_1_FHFLTENC0_2_EN93_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN93(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN93_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN93_MASK)

#define VFCCU_1_FHFLTENC0_2_EN94_MASK            (0x40000000U)
#define VFCCU_1_FHFLTENC0_2_EN94_SHIFT           (30U)
#define VFCCU_1_FHFLTENC0_2_EN94_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN94(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN94_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN94_MASK)

#define VFCCU_1_FHFLTENC0_2_EN95_MASK            (0x80000000U)
#define VFCCU_1_FHFLTENC0_2_EN95_SHIFT           (31U)
#define VFCCU_1_FHFLTENC0_2_EN95_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_2_EN95(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_2_EN95_SHIFT)) & VFCCU_1_FHFLTENC0_2_EN95_MASK)
/*! @} */

/*! @name FHFLTENC0_3 - Fault Enable */
/*! @{ */

#define VFCCU_1_FHFLTENC0_3_EN96_MASK            (0x1U)
#define VFCCU_1_FHFLTENC0_3_EN96_SHIFT           (0U)
#define VFCCU_1_FHFLTENC0_3_EN96_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_3_EN96(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN96_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN96_MASK)

#define VFCCU_1_FHFLTENC0_3_EN97_MASK            (0x2U)
#define VFCCU_1_FHFLTENC0_3_EN97_SHIFT           (1U)
#define VFCCU_1_FHFLTENC0_3_EN97_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_3_EN97(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN97_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN97_MASK)

#define VFCCU_1_FHFLTENC0_3_EN98_MASK            (0x4U)
#define VFCCU_1_FHFLTENC0_3_EN98_SHIFT           (2U)
#define VFCCU_1_FHFLTENC0_3_EN98_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_3_EN98(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN98_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN98_MASK)

#define VFCCU_1_FHFLTENC0_3_EN99_MASK            (0x8U)
#define VFCCU_1_FHFLTENC0_3_EN99_SHIFT           (3U)
#define VFCCU_1_FHFLTENC0_3_EN99_WIDTH           (1U)
#define VFCCU_1_FHFLTENC0_3_EN99(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN99_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN99_MASK)

#define VFCCU_1_FHFLTENC0_3_EN100_MASK           (0x10U)
#define VFCCU_1_FHFLTENC0_3_EN100_SHIFT          (4U)
#define VFCCU_1_FHFLTENC0_3_EN100_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN100(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN100_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN100_MASK)

#define VFCCU_1_FHFLTENC0_3_EN101_MASK           (0x20U)
#define VFCCU_1_FHFLTENC0_3_EN101_SHIFT          (5U)
#define VFCCU_1_FHFLTENC0_3_EN101_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN101(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN101_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN101_MASK)

#define VFCCU_1_FHFLTENC0_3_EN102_MASK           (0x40U)
#define VFCCU_1_FHFLTENC0_3_EN102_SHIFT          (6U)
#define VFCCU_1_FHFLTENC0_3_EN102_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN102(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN102_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN102_MASK)

#define VFCCU_1_FHFLTENC0_3_EN103_MASK           (0x80U)
#define VFCCU_1_FHFLTENC0_3_EN103_SHIFT          (7U)
#define VFCCU_1_FHFLTENC0_3_EN103_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN103(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN103_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN103_MASK)

#define VFCCU_1_FHFLTENC0_3_EN104_MASK           (0x100U)
#define VFCCU_1_FHFLTENC0_3_EN104_SHIFT          (8U)
#define VFCCU_1_FHFLTENC0_3_EN104_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN104(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN104_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN104_MASK)

#define VFCCU_1_FHFLTENC0_3_EN105_MASK           (0x200U)
#define VFCCU_1_FHFLTENC0_3_EN105_SHIFT          (9U)
#define VFCCU_1_FHFLTENC0_3_EN105_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN105(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN105_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN105_MASK)

#define VFCCU_1_FHFLTENC0_3_EN106_MASK           (0x400U)
#define VFCCU_1_FHFLTENC0_3_EN106_SHIFT          (10U)
#define VFCCU_1_FHFLTENC0_3_EN106_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN106(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN106_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN106_MASK)

#define VFCCU_1_FHFLTENC0_3_EN107_MASK           (0x800U)
#define VFCCU_1_FHFLTENC0_3_EN107_SHIFT          (11U)
#define VFCCU_1_FHFLTENC0_3_EN107_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN107(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN107_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN107_MASK)

#define VFCCU_1_FHFLTENC0_3_EN108_MASK           (0x1000U)
#define VFCCU_1_FHFLTENC0_3_EN108_SHIFT          (12U)
#define VFCCU_1_FHFLTENC0_3_EN108_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN108(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN108_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN108_MASK)

#define VFCCU_1_FHFLTENC0_3_EN109_MASK           (0x2000U)
#define VFCCU_1_FHFLTENC0_3_EN109_SHIFT          (13U)
#define VFCCU_1_FHFLTENC0_3_EN109_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN109(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN109_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN109_MASK)

#define VFCCU_1_FHFLTENC0_3_EN110_MASK           (0x4000U)
#define VFCCU_1_FHFLTENC0_3_EN110_SHIFT          (14U)
#define VFCCU_1_FHFLTENC0_3_EN110_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN110(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN110_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN110_MASK)

#define VFCCU_1_FHFLTENC0_3_EN111_MASK           (0x8000U)
#define VFCCU_1_FHFLTENC0_3_EN111_SHIFT          (15U)
#define VFCCU_1_FHFLTENC0_3_EN111_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN111(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN111_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN111_MASK)

#define VFCCU_1_FHFLTENC0_3_EN112_MASK           (0x10000U)
#define VFCCU_1_FHFLTENC0_3_EN112_SHIFT          (16U)
#define VFCCU_1_FHFLTENC0_3_EN112_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN112(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN112_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN112_MASK)

#define VFCCU_1_FHFLTENC0_3_EN113_MASK           (0x20000U)
#define VFCCU_1_FHFLTENC0_3_EN113_SHIFT          (17U)
#define VFCCU_1_FHFLTENC0_3_EN113_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN113(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN113_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN113_MASK)

#define VFCCU_1_FHFLTENC0_3_EN114_MASK           (0x40000U)
#define VFCCU_1_FHFLTENC0_3_EN114_SHIFT          (18U)
#define VFCCU_1_FHFLTENC0_3_EN114_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN114(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN114_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN114_MASK)

#define VFCCU_1_FHFLTENC0_3_EN115_MASK           (0x80000U)
#define VFCCU_1_FHFLTENC0_3_EN115_SHIFT          (19U)
#define VFCCU_1_FHFLTENC0_3_EN115_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN115(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN115_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN115_MASK)

#define VFCCU_1_FHFLTENC0_3_EN116_MASK           (0x100000U)
#define VFCCU_1_FHFLTENC0_3_EN116_SHIFT          (20U)
#define VFCCU_1_FHFLTENC0_3_EN116_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN116(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN116_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN116_MASK)

#define VFCCU_1_FHFLTENC0_3_EN117_MASK           (0x200000U)
#define VFCCU_1_FHFLTENC0_3_EN117_SHIFT          (21U)
#define VFCCU_1_FHFLTENC0_3_EN117_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN117(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN117_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN117_MASK)

#define VFCCU_1_FHFLTENC0_3_EN118_MASK           (0x400000U)
#define VFCCU_1_FHFLTENC0_3_EN118_SHIFT          (22U)
#define VFCCU_1_FHFLTENC0_3_EN118_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN118(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN118_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN118_MASK)

#define VFCCU_1_FHFLTENC0_3_EN119_MASK           (0x800000U)
#define VFCCU_1_FHFLTENC0_3_EN119_SHIFT          (23U)
#define VFCCU_1_FHFLTENC0_3_EN119_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN119(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN119_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN119_MASK)

#define VFCCU_1_FHFLTENC0_3_EN120_MASK           (0x1000000U)
#define VFCCU_1_FHFLTENC0_3_EN120_SHIFT          (24U)
#define VFCCU_1_FHFLTENC0_3_EN120_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN120(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN120_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN120_MASK)

#define VFCCU_1_FHFLTENC0_3_EN121_MASK           (0x2000000U)
#define VFCCU_1_FHFLTENC0_3_EN121_SHIFT          (25U)
#define VFCCU_1_FHFLTENC0_3_EN121_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN121(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN121_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN121_MASK)

#define VFCCU_1_FHFLTENC0_3_EN122_MASK           (0x4000000U)
#define VFCCU_1_FHFLTENC0_3_EN122_SHIFT          (26U)
#define VFCCU_1_FHFLTENC0_3_EN122_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN122(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN122_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN122_MASK)

#define VFCCU_1_FHFLTENC0_3_EN123_MASK           (0x8000000U)
#define VFCCU_1_FHFLTENC0_3_EN123_SHIFT          (27U)
#define VFCCU_1_FHFLTENC0_3_EN123_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN123(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN123_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN123_MASK)

#define VFCCU_1_FHFLTENC0_3_EN124_MASK           (0x10000000U)
#define VFCCU_1_FHFLTENC0_3_EN124_SHIFT          (28U)
#define VFCCU_1_FHFLTENC0_3_EN124_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN124(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN124_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN124_MASK)

#define VFCCU_1_FHFLTENC0_3_EN125_MASK           (0x20000000U)
#define VFCCU_1_FHFLTENC0_3_EN125_SHIFT          (29U)
#define VFCCU_1_FHFLTENC0_3_EN125_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN125(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN125_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN125_MASK)

#define VFCCU_1_FHFLTENC0_3_EN126_MASK           (0x40000000U)
#define VFCCU_1_FHFLTENC0_3_EN126_SHIFT          (30U)
#define VFCCU_1_FHFLTENC0_3_EN126_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN126(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN126_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN126_MASK)

#define VFCCU_1_FHFLTENC0_3_EN127_MASK           (0x80000000U)
#define VFCCU_1_FHFLTENC0_3_EN127_SHIFT          (31U)
#define VFCCU_1_FHFLTENC0_3_EN127_WIDTH          (1U)
#define VFCCU_1_FHFLTENC0_3_EN127(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTENC0_3_EN127_SHIFT)) & VFCCU_1_FHFLTENC0_3_EN127_MASK)
/*! @} */

/*! @name FHFLTS0_0 - Fault Status */
/*! @{ */

#define VFCCU_1_FHFLTS0_0_STAT0_MASK             (0x1U)
#define VFCCU_1_FHFLTS0_0_STAT0_SHIFT            (0U)
#define VFCCU_1_FHFLTS0_0_STAT0_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT0(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT0_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT0_MASK)

#define VFCCU_1_FHFLTS0_0_STAT1_MASK             (0x2U)
#define VFCCU_1_FHFLTS0_0_STAT1_SHIFT            (1U)
#define VFCCU_1_FHFLTS0_0_STAT1_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT1(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT1_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT1_MASK)

#define VFCCU_1_FHFLTS0_0_STAT2_MASK             (0x4U)
#define VFCCU_1_FHFLTS0_0_STAT2_SHIFT            (2U)
#define VFCCU_1_FHFLTS0_0_STAT2_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT2(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT2_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT2_MASK)

#define VFCCU_1_FHFLTS0_0_STAT3_MASK             (0x8U)
#define VFCCU_1_FHFLTS0_0_STAT3_SHIFT            (3U)
#define VFCCU_1_FHFLTS0_0_STAT3_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT3(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT3_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT3_MASK)

#define VFCCU_1_FHFLTS0_0_STAT4_MASK             (0x10U)
#define VFCCU_1_FHFLTS0_0_STAT4_SHIFT            (4U)
#define VFCCU_1_FHFLTS0_0_STAT4_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT4(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT4_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT4_MASK)

#define VFCCU_1_FHFLTS0_0_STAT5_MASK             (0x20U)
#define VFCCU_1_FHFLTS0_0_STAT5_SHIFT            (5U)
#define VFCCU_1_FHFLTS0_0_STAT5_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT5(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT5_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT5_MASK)

#define VFCCU_1_FHFLTS0_0_STAT6_MASK             (0x40U)
#define VFCCU_1_FHFLTS0_0_STAT6_SHIFT            (6U)
#define VFCCU_1_FHFLTS0_0_STAT6_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT6(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT6_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT6_MASK)

#define VFCCU_1_FHFLTS0_0_STAT7_MASK             (0x80U)
#define VFCCU_1_FHFLTS0_0_STAT7_SHIFT            (7U)
#define VFCCU_1_FHFLTS0_0_STAT7_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT7(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT7_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT7_MASK)

#define VFCCU_1_FHFLTS0_0_STAT8_MASK             (0x100U)
#define VFCCU_1_FHFLTS0_0_STAT8_SHIFT            (8U)
#define VFCCU_1_FHFLTS0_0_STAT8_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT8(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT8_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT8_MASK)

#define VFCCU_1_FHFLTS0_0_STAT9_MASK             (0x200U)
#define VFCCU_1_FHFLTS0_0_STAT9_SHIFT            (9U)
#define VFCCU_1_FHFLTS0_0_STAT9_WIDTH            (1U)
#define VFCCU_1_FHFLTS0_0_STAT9(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT9_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT9_MASK)

#define VFCCU_1_FHFLTS0_0_STAT10_MASK            (0x400U)
#define VFCCU_1_FHFLTS0_0_STAT10_SHIFT           (10U)
#define VFCCU_1_FHFLTS0_0_STAT10_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT10(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT10_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT10_MASK)

#define VFCCU_1_FHFLTS0_0_STAT11_MASK            (0x800U)
#define VFCCU_1_FHFLTS0_0_STAT11_SHIFT           (11U)
#define VFCCU_1_FHFLTS0_0_STAT11_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT11(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT11_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT11_MASK)

#define VFCCU_1_FHFLTS0_0_STAT12_MASK            (0x1000U)
#define VFCCU_1_FHFLTS0_0_STAT12_SHIFT           (12U)
#define VFCCU_1_FHFLTS0_0_STAT12_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT12(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT12_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT12_MASK)

#define VFCCU_1_FHFLTS0_0_STAT13_MASK            (0x2000U)
#define VFCCU_1_FHFLTS0_0_STAT13_SHIFT           (13U)
#define VFCCU_1_FHFLTS0_0_STAT13_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT13(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT13_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT13_MASK)

#define VFCCU_1_FHFLTS0_0_STAT14_MASK            (0x4000U)
#define VFCCU_1_FHFLTS0_0_STAT14_SHIFT           (14U)
#define VFCCU_1_FHFLTS0_0_STAT14_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT14(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT14_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT14_MASK)

#define VFCCU_1_FHFLTS0_0_STAT15_MASK            (0x8000U)
#define VFCCU_1_FHFLTS0_0_STAT15_SHIFT           (15U)
#define VFCCU_1_FHFLTS0_0_STAT15_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT15(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT15_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT15_MASK)

#define VFCCU_1_FHFLTS0_0_STAT16_MASK            (0x10000U)
#define VFCCU_1_FHFLTS0_0_STAT16_SHIFT           (16U)
#define VFCCU_1_FHFLTS0_0_STAT16_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT16(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT16_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT16_MASK)

#define VFCCU_1_FHFLTS0_0_STAT17_MASK            (0x20000U)
#define VFCCU_1_FHFLTS0_0_STAT17_SHIFT           (17U)
#define VFCCU_1_FHFLTS0_0_STAT17_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT17(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT17_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT17_MASK)

#define VFCCU_1_FHFLTS0_0_STAT18_MASK            (0x40000U)
#define VFCCU_1_FHFLTS0_0_STAT18_SHIFT           (18U)
#define VFCCU_1_FHFLTS0_0_STAT18_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT18(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT18_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT18_MASK)

#define VFCCU_1_FHFLTS0_0_STAT19_MASK            (0x80000U)
#define VFCCU_1_FHFLTS0_0_STAT19_SHIFT           (19U)
#define VFCCU_1_FHFLTS0_0_STAT19_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT19(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT19_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT19_MASK)

#define VFCCU_1_FHFLTS0_0_STAT20_MASK            (0x100000U)
#define VFCCU_1_FHFLTS0_0_STAT20_SHIFT           (20U)
#define VFCCU_1_FHFLTS0_0_STAT20_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT20(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT20_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT20_MASK)

#define VFCCU_1_FHFLTS0_0_STAT21_MASK            (0x200000U)
#define VFCCU_1_FHFLTS0_0_STAT21_SHIFT           (21U)
#define VFCCU_1_FHFLTS0_0_STAT21_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT21(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT21_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT21_MASK)

#define VFCCU_1_FHFLTS0_0_STAT22_MASK            (0x400000U)
#define VFCCU_1_FHFLTS0_0_STAT22_SHIFT           (22U)
#define VFCCU_1_FHFLTS0_0_STAT22_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT22(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT22_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT22_MASK)

#define VFCCU_1_FHFLTS0_0_STAT23_MASK            (0x800000U)
#define VFCCU_1_FHFLTS0_0_STAT23_SHIFT           (23U)
#define VFCCU_1_FHFLTS0_0_STAT23_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT23(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT23_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT23_MASK)

#define VFCCU_1_FHFLTS0_0_STAT24_MASK            (0x1000000U)
#define VFCCU_1_FHFLTS0_0_STAT24_SHIFT           (24U)
#define VFCCU_1_FHFLTS0_0_STAT24_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT24(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT24_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT24_MASK)

#define VFCCU_1_FHFLTS0_0_STAT25_MASK            (0x2000000U)
#define VFCCU_1_FHFLTS0_0_STAT25_SHIFT           (25U)
#define VFCCU_1_FHFLTS0_0_STAT25_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT25(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT25_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT25_MASK)

#define VFCCU_1_FHFLTS0_0_STAT26_MASK            (0x4000000U)
#define VFCCU_1_FHFLTS0_0_STAT26_SHIFT           (26U)
#define VFCCU_1_FHFLTS0_0_STAT26_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT26(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT26_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT26_MASK)

#define VFCCU_1_FHFLTS0_0_STAT27_MASK            (0x8000000U)
#define VFCCU_1_FHFLTS0_0_STAT27_SHIFT           (27U)
#define VFCCU_1_FHFLTS0_0_STAT27_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT27(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT27_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT27_MASK)

#define VFCCU_1_FHFLTS0_0_STAT28_MASK            (0x10000000U)
#define VFCCU_1_FHFLTS0_0_STAT28_SHIFT           (28U)
#define VFCCU_1_FHFLTS0_0_STAT28_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT28(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT28_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT28_MASK)

#define VFCCU_1_FHFLTS0_0_STAT29_MASK            (0x20000000U)
#define VFCCU_1_FHFLTS0_0_STAT29_SHIFT           (29U)
#define VFCCU_1_FHFLTS0_0_STAT29_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT29(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT29_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT29_MASK)

#define VFCCU_1_FHFLTS0_0_STAT30_MASK            (0x40000000U)
#define VFCCU_1_FHFLTS0_0_STAT30_SHIFT           (30U)
#define VFCCU_1_FHFLTS0_0_STAT30_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT30(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT30_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT30_MASK)

#define VFCCU_1_FHFLTS0_0_STAT31_MASK            (0x80000000U)
#define VFCCU_1_FHFLTS0_0_STAT31_SHIFT           (31U)
#define VFCCU_1_FHFLTS0_0_STAT31_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_0_STAT31(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_0_STAT31_SHIFT)) & VFCCU_1_FHFLTS0_0_STAT31_MASK)
/*! @} */

/*! @name FHFLTS0_1 - Fault Status */
/*! @{ */

#define VFCCU_1_FHFLTS0_1_STAT32_MASK            (0x1U)
#define VFCCU_1_FHFLTS0_1_STAT32_SHIFT           (0U)
#define VFCCU_1_FHFLTS0_1_STAT32_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT32(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT32_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT32_MASK)

#define VFCCU_1_FHFLTS0_1_STAT33_MASK            (0x2U)
#define VFCCU_1_FHFLTS0_1_STAT33_SHIFT           (1U)
#define VFCCU_1_FHFLTS0_1_STAT33_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT33(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT33_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT33_MASK)

#define VFCCU_1_FHFLTS0_1_STAT34_MASK            (0x4U)
#define VFCCU_1_FHFLTS0_1_STAT34_SHIFT           (2U)
#define VFCCU_1_FHFLTS0_1_STAT34_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT34(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT34_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT34_MASK)

#define VFCCU_1_FHFLTS0_1_STAT35_MASK            (0x8U)
#define VFCCU_1_FHFLTS0_1_STAT35_SHIFT           (3U)
#define VFCCU_1_FHFLTS0_1_STAT35_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT35(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT35_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT35_MASK)

#define VFCCU_1_FHFLTS0_1_STAT36_MASK            (0x10U)
#define VFCCU_1_FHFLTS0_1_STAT36_SHIFT           (4U)
#define VFCCU_1_FHFLTS0_1_STAT36_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT36(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT36_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT36_MASK)

#define VFCCU_1_FHFLTS0_1_STAT37_MASK            (0x20U)
#define VFCCU_1_FHFLTS0_1_STAT37_SHIFT           (5U)
#define VFCCU_1_FHFLTS0_1_STAT37_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT37(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT37_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT37_MASK)

#define VFCCU_1_FHFLTS0_1_STAT38_MASK            (0x40U)
#define VFCCU_1_FHFLTS0_1_STAT38_SHIFT           (6U)
#define VFCCU_1_FHFLTS0_1_STAT38_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT38(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT38_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT38_MASK)

#define VFCCU_1_FHFLTS0_1_STAT39_MASK            (0x80U)
#define VFCCU_1_FHFLTS0_1_STAT39_SHIFT           (7U)
#define VFCCU_1_FHFLTS0_1_STAT39_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT39(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT39_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT39_MASK)

#define VFCCU_1_FHFLTS0_1_STAT40_MASK            (0x100U)
#define VFCCU_1_FHFLTS0_1_STAT40_SHIFT           (8U)
#define VFCCU_1_FHFLTS0_1_STAT40_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT40(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT40_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT40_MASK)

#define VFCCU_1_FHFLTS0_1_STAT41_MASK            (0x200U)
#define VFCCU_1_FHFLTS0_1_STAT41_SHIFT           (9U)
#define VFCCU_1_FHFLTS0_1_STAT41_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT41(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT41_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT41_MASK)

#define VFCCU_1_FHFLTS0_1_STAT42_MASK            (0x400U)
#define VFCCU_1_FHFLTS0_1_STAT42_SHIFT           (10U)
#define VFCCU_1_FHFLTS0_1_STAT42_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT42(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT42_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT42_MASK)

#define VFCCU_1_FHFLTS0_1_STAT43_MASK            (0x800U)
#define VFCCU_1_FHFLTS0_1_STAT43_SHIFT           (11U)
#define VFCCU_1_FHFLTS0_1_STAT43_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT43(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT43_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT43_MASK)

#define VFCCU_1_FHFLTS0_1_STAT44_MASK            (0x1000U)
#define VFCCU_1_FHFLTS0_1_STAT44_SHIFT           (12U)
#define VFCCU_1_FHFLTS0_1_STAT44_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT44(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT44_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT44_MASK)

#define VFCCU_1_FHFLTS0_1_STAT45_MASK            (0x2000U)
#define VFCCU_1_FHFLTS0_1_STAT45_SHIFT           (13U)
#define VFCCU_1_FHFLTS0_1_STAT45_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT45(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT45_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT45_MASK)

#define VFCCU_1_FHFLTS0_1_STAT46_MASK            (0x4000U)
#define VFCCU_1_FHFLTS0_1_STAT46_SHIFT           (14U)
#define VFCCU_1_FHFLTS0_1_STAT46_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT46(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT46_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT46_MASK)

#define VFCCU_1_FHFLTS0_1_STAT47_MASK            (0x8000U)
#define VFCCU_1_FHFLTS0_1_STAT47_SHIFT           (15U)
#define VFCCU_1_FHFLTS0_1_STAT47_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT47(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT47_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT47_MASK)

#define VFCCU_1_FHFLTS0_1_STAT48_MASK            (0x10000U)
#define VFCCU_1_FHFLTS0_1_STAT48_SHIFT           (16U)
#define VFCCU_1_FHFLTS0_1_STAT48_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT48(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT48_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT48_MASK)

#define VFCCU_1_FHFLTS0_1_STAT49_MASK            (0x20000U)
#define VFCCU_1_FHFLTS0_1_STAT49_SHIFT           (17U)
#define VFCCU_1_FHFLTS0_1_STAT49_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT49(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT49_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT49_MASK)

#define VFCCU_1_FHFLTS0_1_STAT50_MASK            (0x40000U)
#define VFCCU_1_FHFLTS0_1_STAT50_SHIFT           (18U)
#define VFCCU_1_FHFLTS0_1_STAT50_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT50(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT50_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT50_MASK)

#define VFCCU_1_FHFLTS0_1_STAT51_MASK            (0x80000U)
#define VFCCU_1_FHFLTS0_1_STAT51_SHIFT           (19U)
#define VFCCU_1_FHFLTS0_1_STAT51_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT51(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT51_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT51_MASK)

#define VFCCU_1_FHFLTS0_1_STAT52_MASK            (0x100000U)
#define VFCCU_1_FHFLTS0_1_STAT52_SHIFT           (20U)
#define VFCCU_1_FHFLTS0_1_STAT52_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT52(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT52_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT52_MASK)

#define VFCCU_1_FHFLTS0_1_STAT53_MASK            (0x200000U)
#define VFCCU_1_FHFLTS0_1_STAT53_SHIFT           (21U)
#define VFCCU_1_FHFLTS0_1_STAT53_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT53(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT53_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT53_MASK)

#define VFCCU_1_FHFLTS0_1_STAT54_MASK            (0x400000U)
#define VFCCU_1_FHFLTS0_1_STAT54_SHIFT           (22U)
#define VFCCU_1_FHFLTS0_1_STAT54_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT54(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT54_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT54_MASK)

#define VFCCU_1_FHFLTS0_1_STAT55_MASK            (0x800000U)
#define VFCCU_1_FHFLTS0_1_STAT55_SHIFT           (23U)
#define VFCCU_1_FHFLTS0_1_STAT55_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT55(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT55_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT55_MASK)

#define VFCCU_1_FHFLTS0_1_STAT56_MASK            (0x1000000U)
#define VFCCU_1_FHFLTS0_1_STAT56_SHIFT           (24U)
#define VFCCU_1_FHFLTS0_1_STAT56_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT56(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT56_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT56_MASK)

#define VFCCU_1_FHFLTS0_1_STAT57_MASK            (0x2000000U)
#define VFCCU_1_FHFLTS0_1_STAT57_SHIFT           (25U)
#define VFCCU_1_FHFLTS0_1_STAT57_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT57(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT57_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT57_MASK)

#define VFCCU_1_FHFLTS0_1_STAT58_MASK            (0x4000000U)
#define VFCCU_1_FHFLTS0_1_STAT58_SHIFT           (26U)
#define VFCCU_1_FHFLTS0_1_STAT58_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT58(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT58_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT58_MASK)

#define VFCCU_1_FHFLTS0_1_STAT59_MASK            (0x8000000U)
#define VFCCU_1_FHFLTS0_1_STAT59_SHIFT           (27U)
#define VFCCU_1_FHFLTS0_1_STAT59_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT59(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT59_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT59_MASK)

#define VFCCU_1_FHFLTS0_1_STAT60_MASK            (0x10000000U)
#define VFCCU_1_FHFLTS0_1_STAT60_SHIFT           (28U)
#define VFCCU_1_FHFLTS0_1_STAT60_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT60(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT60_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT60_MASK)

#define VFCCU_1_FHFLTS0_1_STAT61_MASK            (0x20000000U)
#define VFCCU_1_FHFLTS0_1_STAT61_SHIFT           (29U)
#define VFCCU_1_FHFLTS0_1_STAT61_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT61(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT61_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT61_MASK)

#define VFCCU_1_FHFLTS0_1_STAT62_MASK            (0x40000000U)
#define VFCCU_1_FHFLTS0_1_STAT62_SHIFT           (30U)
#define VFCCU_1_FHFLTS0_1_STAT62_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT62(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT62_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT62_MASK)

#define VFCCU_1_FHFLTS0_1_STAT63_MASK            (0x80000000U)
#define VFCCU_1_FHFLTS0_1_STAT63_SHIFT           (31U)
#define VFCCU_1_FHFLTS0_1_STAT63_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_1_STAT63(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_1_STAT63_SHIFT)) & VFCCU_1_FHFLTS0_1_STAT63_MASK)
/*! @} */

/*! @name FHFLTS0_2 - Fault Status */
/*! @{ */

#define VFCCU_1_FHFLTS0_2_STAT64_MASK            (0x1U)
#define VFCCU_1_FHFLTS0_2_STAT64_SHIFT           (0U)
#define VFCCU_1_FHFLTS0_2_STAT64_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT64(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT64_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT64_MASK)

#define VFCCU_1_FHFLTS0_2_STAT65_MASK            (0x2U)
#define VFCCU_1_FHFLTS0_2_STAT65_SHIFT           (1U)
#define VFCCU_1_FHFLTS0_2_STAT65_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT65(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT65_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT65_MASK)

#define VFCCU_1_FHFLTS0_2_STAT66_MASK            (0x4U)
#define VFCCU_1_FHFLTS0_2_STAT66_SHIFT           (2U)
#define VFCCU_1_FHFLTS0_2_STAT66_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT66(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT66_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT66_MASK)

#define VFCCU_1_FHFLTS0_2_STAT67_MASK            (0x8U)
#define VFCCU_1_FHFLTS0_2_STAT67_SHIFT           (3U)
#define VFCCU_1_FHFLTS0_2_STAT67_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT67(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT67_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT67_MASK)

#define VFCCU_1_FHFLTS0_2_STAT68_MASK            (0x10U)
#define VFCCU_1_FHFLTS0_2_STAT68_SHIFT           (4U)
#define VFCCU_1_FHFLTS0_2_STAT68_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT68(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT68_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT68_MASK)

#define VFCCU_1_FHFLTS0_2_STAT69_MASK            (0x20U)
#define VFCCU_1_FHFLTS0_2_STAT69_SHIFT           (5U)
#define VFCCU_1_FHFLTS0_2_STAT69_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT69(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT69_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT69_MASK)

#define VFCCU_1_FHFLTS0_2_STAT70_MASK            (0x40U)
#define VFCCU_1_FHFLTS0_2_STAT70_SHIFT           (6U)
#define VFCCU_1_FHFLTS0_2_STAT70_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT70(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT70_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT70_MASK)

#define VFCCU_1_FHFLTS0_2_STAT71_MASK            (0x80U)
#define VFCCU_1_FHFLTS0_2_STAT71_SHIFT           (7U)
#define VFCCU_1_FHFLTS0_2_STAT71_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT71(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT71_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT71_MASK)

#define VFCCU_1_FHFLTS0_2_STAT72_MASK            (0x100U)
#define VFCCU_1_FHFLTS0_2_STAT72_SHIFT           (8U)
#define VFCCU_1_FHFLTS0_2_STAT72_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT72(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT72_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT72_MASK)

#define VFCCU_1_FHFLTS0_2_STAT73_MASK            (0x200U)
#define VFCCU_1_FHFLTS0_2_STAT73_SHIFT           (9U)
#define VFCCU_1_FHFLTS0_2_STAT73_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT73(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT73_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT73_MASK)

#define VFCCU_1_FHFLTS0_2_STAT74_MASK            (0x400U)
#define VFCCU_1_FHFLTS0_2_STAT74_SHIFT           (10U)
#define VFCCU_1_FHFLTS0_2_STAT74_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT74(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT74_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT74_MASK)

#define VFCCU_1_FHFLTS0_2_STAT75_MASK            (0x800U)
#define VFCCU_1_FHFLTS0_2_STAT75_SHIFT           (11U)
#define VFCCU_1_FHFLTS0_2_STAT75_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT75(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT75_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT75_MASK)

#define VFCCU_1_FHFLTS0_2_STAT76_MASK            (0x1000U)
#define VFCCU_1_FHFLTS0_2_STAT76_SHIFT           (12U)
#define VFCCU_1_FHFLTS0_2_STAT76_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT76(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT76_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT76_MASK)

#define VFCCU_1_FHFLTS0_2_STAT77_MASK            (0x2000U)
#define VFCCU_1_FHFLTS0_2_STAT77_SHIFT           (13U)
#define VFCCU_1_FHFLTS0_2_STAT77_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT77(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT77_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT77_MASK)

#define VFCCU_1_FHFLTS0_2_STAT78_MASK            (0x4000U)
#define VFCCU_1_FHFLTS0_2_STAT78_SHIFT           (14U)
#define VFCCU_1_FHFLTS0_2_STAT78_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT78(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT78_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT78_MASK)

#define VFCCU_1_FHFLTS0_2_STAT79_MASK            (0x8000U)
#define VFCCU_1_FHFLTS0_2_STAT79_SHIFT           (15U)
#define VFCCU_1_FHFLTS0_2_STAT79_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT79(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT79_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT79_MASK)

#define VFCCU_1_FHFLTS0_2_STAT80_MASK            (0x10000U)
#define VFCCU_1_FHFLTS0_2_STAT80_SHIFT           (16U)
#define VFCCU_1_FHFLTS0_2_STAT80_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT80(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT80_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT80_MASK)

#define VFCCU_1_FHFLTS0_2_STAT81_MASK            (0x20000U)
#define VFCCU_1_FHFLTS0_2_STAT81_SHIFT           (17U)
#define VFCCU_1_FHFLTS0_2_STAT81_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT81(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT81_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT81_MASK)

#define VFCCU_1_FHFLTS0_2_STAT82_MASK            (0x40000U)
#define VFCCU_1_FHFLTS0_2_STAT82_SHIFT           (18U)
#define VFCCU_1_FHFLTS0_2_STAT82_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT82(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT82_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT82_MASK)

#define VFCCU_1_FHFLTS0_2_STAT83_MASK            (0x80000U)
#define VFCCU_1_FHFLTS0_2_STAT83_SHIFT           (19U)
#define VFCCU_1_FHFLTS0_2_STAT83_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT83(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT83_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT83_MASK)

#define VFCCU_1_FHFLTS0_2_STAT84_MASK            (0x100000U)
#define VFCCU_1_FHFLTS0_2_STAT84_SHIFT           (20U)
#define VFCCU_1_FHFLTS0_2_STAT84_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT84(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT84_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT84_MASK)

#define VFCCU_1_FHFLTS0_2_STAT85_MASK            (0x200000U)
#define VFCCU_1_FHFLTS0_2_STAT85_SHIFT           (21U)
#define VFCCU_1_FHFLTS0_2_STAT85_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT85(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT85_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT85_MASK)

#define VFCCU_1_FHFLTS0_2_STAT86_MASK            (0x400000U)
#define VFCCU_1_FHFLTS0_2_STAT86_SHIFT           (22U)
#define VFCCU_1_FHFLTS0_2_STAT86_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT86(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT86_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT86_MASK)

#define VFCCU_1_FHFLTS0_2_STAT87_MASK            (0x800000U)
#define VFCCU_1_FHFLTS0_2_STAT87_SHIFT           (23U)
#define VFCCU_1_FHFLTS0_2_STAT87_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT87(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT87_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT87_MASK)

#define VFCCU_1_FHFLTS0_2_STAT88_MASK            (0x1000000U)
#define VFCCU_1_FHFLTS0_2_STAT88_SHIFT           (24U)
#define VFCCU_1_FHFLTS0_2_STAT88_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT88(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT88_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT88_MASK)

#define VFCCU_1_FHFLTS0_2_STAT89_MASK            (0x2000000U)
#define VFCCU_1_FHFLTS0_2_STAT89_SHIFT           (25U)
#define VFCCU_1_FHFLTS0_2_STAT89_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT89(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT89_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT89_MASK)

#define VFCCU_1_FHFLTS0_2_STAT90_MASK            (0x4000000U)
#define VFCCU_1_FHFLTS0_2_STAT90_SHIFT           (26U)
#define VFCCU_1_FHFLTS0_2_STAT90_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT90(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT90_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT90_MASK)

#define VFCCU_1_FHFLTS0_2_STAT91_MASK            (0x8000000U)
#define VFCCU_1_FHFLTS0_2_STAT91_SHIFT           (27U)
#define VFCCU_1_FHFLTS0_2_STAT91_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT91(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT91_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT91_MASK)

#define VFCCU_1_FHFLTS0_2_STAT92_MASK            (0x10000000U)
#define VFCCU_1_FHFLTS0_2_STAT92_SHIFT           (28U)
#define VFCCU_1_FHFLTS0_2_STAT92_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT92(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT92_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT92_MASK)

#define VFCCU_1_FHFLTS0_2_STAT93_MASK            (0x20000000U)
#define VFCCU_1_FHFLTS0_2_STAT93_SHIFT           (29U)
#define VFCCU_1_FHFLTS0_2_STAT93_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT93(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT93_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT93_MASK)

#define VFCCU_1_FHFLTS0_2_STAT94_MASK            (0x40000000U)
#define VFCCU_1_FHFLTS0_2_STAT94_SHIFT           (30U)
#define VFCCU_1_FHFLTS0_2_STAT94_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT94(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT94_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT94_MASK)

#define VFCCU_1_FHFLTS0_2_STAT95_MASK            (0x80000000U)
#define VFCCU_1_FHFLTS0_2_STAT95_SHIFT           (31U)
#define VFCCU_1_FHFLTS0_2_STAT95_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_2_STAT95(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_2_STAT95_SHIFT)) & VFCCU_1_FHFLTS0_2_STAT95_MASK)
/*! @} */

/*! @name FHFLTS0_3 - Fault Status */
/*! @{ */

#define VFCCU_1_FHFLTS0_3_STAT96_MASK            (0x1U)
#define VFCCU_1_FHFLTS0_3_STAT96_SHIFT           (0U)
#define VFCCU_1_FHFLTS0_3_STAT96_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_3_STAT96(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT96_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT96_MASK)

#define VFCCU_1_FHFLTS0_3_STAT97_MASK            (0x2U)
#define VFCCU_1_FHFLTS0_3_STAT97_SHIFT           (1U)
#define VFCCU_1_FHFLTS0_3_STAT97_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_3_STAT97(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT97_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT97_MASK)

#define VFCCU_1_FHFLTS0_3_STAT98_MASK            (0x4U)
#define VFCCU_1_FHFLTS0_3_STAT98_SHIFT           (2U)
#define VFCCU_1_FHFLTS0_3_STAT98_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_3_STAT98(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT98_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT98_MASK)

#define VFCCU_1_FHFLTS0_3_STAT99_MASK            (0x8U)
#define VFCCU_1_FHFLTS0_3_STAT99_SHIFT           (3U)
#define VFCCU_1_FHFLTS0_3_STAT99_WIDTH           (1U)
#define VFCCU_1_FHFLTS0_3_STAT99(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT99_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT99_MASK)

#define VFCCU_1_FHFLTS0_3_STAT100_MASK           (0x10U)
#define VFCCU_1_FHFLTS0_3_STAT100_SHIFT          (4U)
#define VFCCU_1_FHFLTS0_3_STAT100_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT100(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT100_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT100_MASK)

#define VFCCU_1_FHFLTS0_3_STAT101_MASK           (0x20U)
#define VFCCU_1_FHFLTS0_3_STAT101_SHIFT          (5U)
#define VFCCU_1_FHFLTS0_3_STAT101_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT101(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT101_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT101_MASK)

#define VFCCU_1_FHFLTS0_3_STAT102_MASK           (0x40U)
#define VFCCU_1_FHFLTS0_3_STAT102_SHIFT          (6U)
#define VFCCU_1_FHFLTS0_3_STAT102_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT102(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT102_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT102_MASK)

#define VFCCU_1_FHFLTS0_3_STAT103_MASK           (0x80U)
#define VFCCU_1_FHFLTS0_3_STAT103_SHIFT          (7U)
#define VFCCU_1_FHFLTS0_3_STAT103_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT103(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT103_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT103_MASK)

#define VFCCU_1_FHFLTS0_3_STAT104_MASK           (0x100U)
#define VFCCU_1_FHFLTS0_3_STAT104_SHIFT          (8U)
#define VFCCU_1_FHFLTS0_3_STAT104_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT104(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT104_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT104_MASK)

#define VFCCU_1_FHFLTS0_3_STAT105_MASK           (0x200U)
#define VFCCU_1_FHFLTS0_3_STAT105_SHIFT          (9U)
#define VFCCU_1_FHFLTS0_3_STAT105_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT105(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT105_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT105_MASK)

#define VFCCU_1_FHFLTS0_3_STAT106_MASK           (0x400U)
#define VFCCU_1_FHFLTS0_3_STAT106_SHIFT          (10U)
#define VFCCU_1_FHFLTS0_3_STAT106_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT106(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT106_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT106_MASK)

#define VFCCU_1_FHFLTS0_3_STAT107_MASK           (0x800U)
#define VFCCU_1_FHFLTS0_3_STAT107_SHIFT          (11U)
#define VFCCU_1_FHFLTS0_3_STAT107_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT107(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT107_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT107_MASK)

#define VFCCU_1_FHFLTS0_3_STAT108_MASK           (0x1000U)
#define VFCCU_1_FHFLTS0_3_STAT108_SHIFT          (12U)
#define VFCCU_1_FHFLTS0_3_STAT108_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT108(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT108_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT108_MASK)

#define VFCCU_1_FHFLTS0_3_STAT109_MASK           (0x2000U)
#define VFCCU_1_FHFLTS0_3_STAT109_SHIFT          (13U)
#define VFCCU_1_FHFLTS0_3_STAT109_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT109(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT109_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT109_MASK)

#define VFCCU_1_FHFLTS0_3_STAT110_MASK           (0x4000U)
#define VFCCU_1_FHFLTS0_3_STAT110_SHIFT          (14U)
#define VFCCU_1_FHFLTS0_3_STAT110_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT110(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT110_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT110_MASK)

#define VFCCU_1_FHFLTS0_3_STAT111_MASK           (0x8000U)
#define VFCCU_1_FHFLTS0_3_STAT111_SHIFT          (15U)
#define VFCCU_1_FHFLTS0_3_STAT111_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT111(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT111_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT111_MASK)

#define VFCCU_1_FHFLTS0_3_STAT112_MASK           (0x10000U)
#define VFCCU_1_FHFLTS0_3_STAT112_SHIFT          (16U)
#define VFCCU_1_FHFLTS0_3_STAT112_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT112(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT112_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT112_MASK)

#define VFCCU_1_FHFLTS0_3_STAT113_MASK           (0x20000U)
#define VFCCU_1_FHFLTS0_3_STAT113_SHIFT          (17U)
#define VFCCU_1_FHFLTS0_3_STAT113_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT113(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT113_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT113_MASK)

#define VFCCU_1_FHFLTS0_3_STAT114_MASK           (0x40000U)
#define VFCCU_1_FHFLTS0_3_STAT114_SHIFT          (18U)
#define VFCCU_1_FHFLTS0_3_STAT114_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT114(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT114_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT114_MASK)

#define VFCCU_1_FHFLTS0_3_STAT115_MASK           (0x80000U)
#define VFCCU_1_FHFLTS0_3_STAT115_SHIFT          (19U)
#define VFCCU_1_FHFLTS0_3_STAT115_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT115(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT115_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT115_MASK)

#define VFCCU_1_FHFLTS0_3_STAT116_MASK           (0x100000U)
#define VFCCU_1_FHFLTS0_3_STAT116_SHIFT          (20U)
#define VFCCU_1_FHFLTS0_3_STAT116_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT116(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT116_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT116_MASK)

#define VFCCU_1_FHFLTS0_3_STAT117_MASK           (0x200000U)
#define VFCCU_1_FHFLTS0_3_STAT117_SHIFT          (21U)
#define VFCCU_1_FHFLTS0_3_STAT117_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT117(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT117_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT117_MASK)

#define VFCCU_1_FHFLTS0_3_STAT118_MASK           (0x400000U)
#define VFCCU_1_FHFLTS0_3_STAT118_SHIFT          (22U)
#define VFCCU_1_FHFLTS0_3_STAT118_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT118(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT118_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT118_MASK)

#define VFCCU_1_FHFLTS0_3_STAT119_MASK           (0x800000U)
#define VFCCU_1_FHFLTS0_3_STAT119_SHIFT          (23U)
#define VFCCU_1_FHFLTS0_3_STAT119_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT119(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT119_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT119_MASK)

#define VFCCU_1_FHFLTS0_3_STAT120_MASK           (0x1000000U)
#define VFCCU_1_FHFLTS0_3_STAT120_SHIFT          (24U)
#define VFCCU_1_FHFLTS0_3_STAT120_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT120(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT120_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT120_MASK)

#define VFCCU_1_FHFLTS0_3_STAT121_MASK           (0x2000000U)
#define VFCCU_1_FHFLTS0_3_STAT121_SHIFT          (25U)
#define VFCCU_1_FHFLTS0_3_STAT121_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT121(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT121_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT121_MASK)

#define VFCCU_1_FHFLTS0_3_STAT122_MASK           (0x4000000U)
#define VFCCU_1_FHFLTS0_3_STAT122_SHIFT          (26U)
#define VFCCU_1_FHFLTS0_3_STAT122_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT122(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT122_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT122_MASK)

#define VFCCU_1_FHFLTS0_3_STAT123_MASK           (0x8000000U)
#define VFCCU_1_FHFLTS0_3_STAT123_SHIFT          (27U)
#define VFCCU_1_FHFLTS0_3_STAT123_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT123(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT123_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT123_MASK)

#define VFCCU_1_FHFLTS0_3_STAT124_MASK           (0x10000000U)
#define VFCCU_1_FHFLTS0_3_STAT124_SHIFT          (28U)
#define VFCCU_1_FHFLTS0_3_STAT124_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT124(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT124_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT124_MASK)

#define VFCCU_1_FHFLTS0_3_STAT125_MASK           (0x20000000U)
#define VFCCU_1_FHFLTS0_3_STAT125_SHIFT          (29U)
#define VFCCU_1_FHFLTS0_3_STAT125_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT125(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT125_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT125_MASK)

#define VFCCU_1_FHFLTS0_3_STAT126_MASK           (0x40000000U)
#define VFCCU_1_FHFLTS0_3_STAT126_SHIFT          (30U)
#define VFCCU_1_FHFLTS0_3_STAT126_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT126(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT126_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT126_MASK)

#define VFCCU_1_FHFLTS0_3_STAT127_MASK           (0x80000000U)
#define VFCCU_1_FHFLTS0_3_STAT127_SHIFT          (31U)
#define VFCCU_1_FHFLTS0_3_STAT127_WIDTH          (1U)
#define VFCCU_1_FHFLTS0_3_STAT127(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTS0_3_STAT127_SHIFT)) & VFCCU_1_FHFLTS0_3_STAT127_MASK)
/*! @} */

/*! @name FHFLTRKC0_0 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_0_RKNSEL0_MASK         (0xFU)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL0_SHIFT        (0U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL0_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_0_RKNSEL0_SHIFT)) & VFCCU_1_FHFLTRKC0_0_RKNSEL0_MASK)

#define VFCCU_1_FHFLTRKC0_0_RKNSEL1_MASK         (0xF00U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL1_SHIFT        (8U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL1_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_0_RKNSEL1_SHIFT)) & VFCCU_1_FHFLTRKC0_0_RKNSEL1_MASK)

#define VFCCU_1_FHFLTRKC0_0_RKNSEL2_MASK         (0xF0000U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL2_SHIFT        (16U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL2_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_0_RKNSEL2_SHIFT)) & VFCCU_1_FHFLTRKC0_0_RKNSEL2_MASK)

#define VFCCU_1_FHFLTRKC0_0_RKNSEL3_MASK         (0xF000000U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL3_SHIFT        (24U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL3_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_0_RKNSEL3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_0_RKNSEL3_SHIFT)) & VFCCU_1_FHFLTRKC0_0_RKNSEL3_MASK)
/*! @} */

/*! @name FHFLTRKC0_1 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_1_RKNSEL4_MASK         (0xFU)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL4_SHIFT        (0U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL4_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_1_RKNSEL4_SHIFT)) & VFCCU_1_FHFLTRKC0_1_RKNSEL4_MASK)

#define VFCCU_1_FHFLTRKC0_1_RKNSEL5_MASK         (0xF00U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL5_SHIFT        (8U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL5_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_1_RKNSEL5_SHIFT)) & VFCCU_1_FHFLTRKC0_1_RKNSEL5_MASK)

#define VFCCU_1_FHFLTRKC0_1_RKNSEL6_MASK         (0xF0000U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL6_SHIFT        (16U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL6_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_1_RKNSEL6_SHIFT)) & VFCCU_1_FHFLTRKC0_1_RKNSEL6_MASK)

#define VFCCU_1_FHFLTRKC0_1_RKNSEL7_MASK         (0xF000000U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL7_SHIFT        (24U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL7_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_1_RKNSEL7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_1_RKNSEL7_SHIFT)) & VFCCU_1_FHFLTRKC0_1_RKNSEL7_MASK)
/*! @} */

/*! @name FHFLTRKC0_2 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_2_RKNSEL8_MASK         (0xFU)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL8_SHIFT        (0U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL8_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_2_RKNSEL8_SHIFT)) & VFCCU_1_FHFLTRKC0_2_RKNSEL8_MASK)

#define VFCCU_1_FHFLTRKC0_2_RKNSEL9_MASK         (0xF00U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL9_SHIFT        (8U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL9_WIDTH        (4U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_2_RKNSEL9_SHIFT)) & VFCCU_1_FHFLTRKC0_2_RKNSEL9_MASK)

#define VFCCU_1_FHFLTRKC0_2_RKNSEL10_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL10_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL10_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_2_RKNSEL10_SHIFT)) & VFCCU_1_FHFLTRKC0_2_RKNSEL10_MASK)

#define VFCCU_1_FHFLTRKC0_2_RKNSEL11_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL11_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL11_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_2_RKNSEL11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_2_RKNSEL11_SHIFT)) & VFCCU_1_FHFLTRKC0_2_RKNSEL11_MASK)
/*! @} */

/*! @name FHFLTRKC0_3 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_3_RKNSEL12_MASK        (0xFU)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL12_SHIFT       (0U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL12_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_3_RKNSEL12_SHIFT)) & VFCCU_1_FHFLTRKC0_3_RKNSEL12_MASK)

#define VFCCU_1_FHFLTRKC0_3_RKNSEL13_MASK        (0xF00U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL13_SHIFT       (8U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL13_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_3_RKNSEL13_SHIFT)) & VFCCU_1_FHFLTRKC0_3_RKNSEL13_MASK)

#define VFCCU_1_FHFLTRKC0_3_RKNSEL14_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL14_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL14_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_3_RKNSEL14_SHIFT)) & VFCCU_1_FHFLTRKC0_3_RKNSEL14_MASK)

#define VFCCU_1_FHFLTRKC0_3_RKNSEL15_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL15_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL15_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_3_RKNSEL15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_3_RKNSEL15_SHIFT)) & VFCCU_1_FHFLTRKC0_3_RKNSEL15_MASK)
/*! @} */

/*! @name FHFLTRKC0_4 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_4_RKNSEL16_MASK        (0xFU)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL16_SHIFT       (0U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL16_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_4_RKNSEL16_SHIFT)) & VFCCU_1_FHFLTRKC0_4_RKNSEL16_MASK)

#define VFCCU_1_FHFLTRKC0_4_RKNSEL17_MASK        (0xF00U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL17_SHIFT       (8U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL17_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_4_RKNSEL17_SHIFT)) & VFCCU_1_FHFLTRKC0_4_RKNSEL17_MASK)

#define VFCCU_1_FHFLTRKC0_4_RKNSEL18_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL18_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL18_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_4_RKNSEL18_SHIFT)) & VFCCU_1_FHFLTRKC0_4_RKNSEL18_MASK)

#define VFCCU_1_FHFLTRKC0_4_RKNSEL19_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL19_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL19_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_4_RKNSEL19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_4_RKNSEL19_SHIFT)) & VFCCU_1_FHFLTRKC0_4_RKNSEL19_MASK)
/*! @} */

/*! @name FHFLTRKC0_5 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_5_RKNSEL20_MASK        (0xFU)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL20_SHIFT       (0U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL20_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_5_RKNSEL20_SHIFT)) & VFCCU_1_FHFLTRKC0_5_RKNSEL20_MASK)

#define VFCCU_1_FHFLTRKC0_5_RKNSEL21_MASK        (0xF00U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL21_SHIFT       (8U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL21_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_5_RKNSEL21_SHIFT)) & VFCCU_1_FHFLTRKC0_5_RKNSEL21_MASK)

#define VFCCU_1_FHFLTRKC0_5_RKNSEL22_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL22_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL22_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_5_RKNSEL22_SHIFT)) & VFCCU_1_FHFLTRKC0_5_RKNSEL22_MASK)

#define VFCCU_1_FHFLTRKC0_5_RKNSEL23_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL23_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL23_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_5_RKNSEL23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_5_RKNSEL23_SHIFT)) & VFCCU_1_FHFLTRKC0_5_RKNSEL23_MASK)
/*! @} */

/*! @name FHFLTRKC0_6 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_6_RKNSEL24_MASK        (0xFU)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL24_SHIFT       (0U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL24_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_6_RKNSEL24_SHIFT)) & VFCCU_1_FHFLTRKC0_6_RKNSEL24_MASK)

#define VFCCU_1_FHFLTRKC0_6_RKNSEL25_MASK        (0xF00U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL25_SHIFT       (8U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL25_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_6_RKNSEL25_SHIFT)) & VFCCU_1_FHFLTRKC0_6_RKNSEL25_MASK)

#define VFCCU_1_FHFLTRKC0_6_RKNSEL26_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL26_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL26_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_6_RKNSEL26_SHIFT)) & VFCCU_1_FHFLTRKC0_6_RKNSEL26_MASK)

#define VFCCU_1_FHFLTRKC0_6_RKNSEL27_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL27_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL27_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_6_RKNSEL27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_6_RKNSEL27_SHIFT)) & VFCCU_1_FHFLTRKC0_6_RKNSEL27_MASK)
/*! @} */

/*! @name FHFLTRKC0_7 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_7_RKNSEL28_MASK        (0xFU)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL28_SHIFT       (0U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL28_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_7_RKNSEL28_SHIFT)) & VFCCU_1_FHFLTRKC0_7_RKNSEL28_MASK)

#define VFCCU_1_FHFLTRKC0_7_RKNSEL29_MASK        (0xF00U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL29_SHIFT       (8U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL29_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_7_RKNSEL29_SHIFT)) & VFCCU_1_FHFLTRKC0_7_RKNSEL29_MASK)

#define VFCCU_1_FHFLTRKC0_7_RKNSEL30_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL30_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL30_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL30(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_7_RKNSEL30_SHIFT)) & VFCCU_1_FHFLTRKC0_7_RKNSEL30_MASK)

#define VFCCU_1_FHFLTRKC0_7_RKNSEL31_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL31_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL31_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_7_RKNSEL31(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_7_RKNSEL31_SHIFT)) & VFCCU_1_FHFLTRKC0_7_RKNSEL31_MASK)
/*! @} */

/*! @name FHFLTRKC0_8 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_8_RKNSEL32_MASK        (0xFU)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL32_SHIFT       (0U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL32_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL32(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_8_RKNSEL32_SHIFT)) & VFCCU_1_FHFLTRKC0_8_RKNSEL32_MASK)

#define VFCCU_1_FHFLTRKC0_8_RKNSEL33_MASK        (0xF00U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL33_SHIFT       (8U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL33_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL33(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_8_RKNSEL33_SHIFT)) & VFCCU_1_FHFLTRKC0_8_RKNSEL33_MASK)

#define VFCCU_1_FHFLTRKC0_8_RKNSEL34_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL34_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL34_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL34(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_8_RKNSEL34_SHIFT)) & VFCCU_1_FHFLTRKC0_8_RKNSEL34_MASK)

#define VFCCU_1_FHFLTRKC0_8_RKNSEL35_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL35_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL35_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_8_RKNSEL35(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_8_RKNSEL35_SHIFT)) & VFCCU_1_FHFLTRKC0_8_RKNSEL35_MASK)
/*! @} */

/*! @name FHFLTRKC0_9 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_9_RKNSEL36_MASK        (0xFU)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL36_SHIFT       (0U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL36_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL36(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_9_RKNSEL36_SHIFT)) & VFCCU_1_FHFLTRKC0_9_RKNSEL36_MASK)

#define VFCCU_1_FHFLTRKC0_9_RKNSEL37_MASK        (0xF00U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL37_SHIFT       (8U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL37_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL37(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_9_RKNSEL37_SHIFT)) & VFCCU_1_FHFLTRKC0_9_RKNSEL37_MASK)

#define VFCCU_1_FHFLTRKC0_9_RKNSEL38_MASK        (0xF0000U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL38_SHIFT       (16U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL38_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL38(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_9_RKNSEL38_SHIFT)) & VFCCU_1_FHFLTRKC0_9_RKNSEL38_MASK)

#define VFCCU_1_FHFLTRKC0_9_RKNSEL39_MASK        (0xF000000U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL39_SHIFT       (24U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL39_WIDTH       (4U)
#define VFCCU_1_FHFLTRKC0_9_RKNSEL39(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_9_RKNSEL39_SHIFT)) & VFCCU_1_FHFLTRKC0_9_RKNSEL39_MASK)
/*! @} */

/*! @name FHFLTRKC0_10 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_10_RKNSEL40_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL40_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL40_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL40(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_10_RKNSEL40_SHIFT)) & VFCCU_1_FHFLTRKC0_10_RKNSEL40_MASK)

#define VFCCU_1_FHFLTRKC0_10_RKNSEL41_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL41_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL41_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL41(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_10_RKNSEL41_SHIFT)) & VFCCU_1_FHFLTRKC0_10_RKNSEL41_MASK)

#define VFCCU_1_FHFLTRKC0_10_RKNSEL42_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL42_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL42_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL42(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_10_RKNSEL42_SHIFT)) & VFCCU_1_FHFLTRKC0_10_RKNSEL42_MASK)

#define VFCCU_1_FHFLTRKC0_10_RKNSEL43_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL43_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL43_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_10_RKNSEL43(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_10_RKNSEL43_SHIFT)) & VFCCU_1_FHFLTRKC0_10_RKNSEL43_MASK)
/*! @} */

/*! @name FHFLTRKC0_11 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_11_RKNSEL44_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL44_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL44_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL44(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_11_RKNSEL44_SHIFT)) & VFCCU_1_FHFLTRKC0_11_RKNSEL44_MASK)

#define VFCCU_1_FHFLTRKC0_11_RKNSEL45_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL45_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL45_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL45(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_11_RKNSEL45_SHIFT)) & VFCCU_1_FHFLTRKC0_11_RKNSEL45_MASK)

#define VFCCU_1_FHFLTRKC0_11_RKNSEL46_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL46_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL46_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL46(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_11_RKNSEL46_SHIFT)) & VFCCU_1_FHFLTRKC0_11_RKNSEL46_MASK)

#define VFCCU_1_FHFLTRKC0_11_RKNSEL47_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL47_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL47_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_11_RKNSEL47(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_11_RKNSEL47_SHIFT)) & VFCCU_1_FHFLTRKC0_11_RKNSEL47_MASK)
/*! @} */

/*! @name FHFLTRKC0_12 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_12_RKNSEL48_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL48_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL48_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL48(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_12_RKNSEL48_SHIFT)) & VFCCU_1_FHFLTRKC0_12_RKNSEL48_MASK)

#define VFCCU_1_FHFLTRKC0_12_RKNSEL49_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL49_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL49_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL49(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_12_RKNSEL49_SHIFT)) & VFCCU_1_FHFLTRKC0_12_RKNSEL49_MASK)

#define VFCCU_1_FHFLTRKC0_12_RKNSEL50_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL50_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL50_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL50(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_12_RKNSEL50_SHIFT)) & VFCCU_1_FHFLTRKC0_12_RKNSEL50_MASK)

#define VFCCU_1_FHFLTRKC0_12_RKNSEL51_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL51_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL51_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_12_RKNSEL51(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_12_RKNSEL51_SHIFT)) & VFCCU_1_FHFLTRKC0_12_RKNSEL51_MASK)
/*! @} */

/*! @name FHFLTRKC0_13 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_13_RKNSEL52_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL52_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL52_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL52(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_13_RKNSEL52_SHIFT)) & VFCCU_1_FHFLTRKC0_13_RKNSEL52_MASK)

#define VFCCU_1_FHFLTRKC0_13_RKNSEL53_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL53_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL53_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL53(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_13_RKNSEL53_SHIFT)) & VFCCU_1_FHFLTRKC0_13_RKNSEL53_MASK)

#define VFCCU_1_FHFLTRKC0_13_RKNSEL54_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL54_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL54_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL54(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_13_RKNSEL54_SHIFT)) & VFCCU_1_FHFLTRKC0_13_RKNSEL54_MASK)

#define VFCCU_1_FHFLTRKC0_13_RKNSEL55_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL55_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL55_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_13_RKNSEL55(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_13_RKNSEL55_SHIFT)) & VFCCU_1_FHFLTRKC0_13_RKNSEL55_MASK)
/*! @} */

/*! @name FHFLTRKC0_14 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_14_RKNSEL56_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL56_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL56_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL56(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_14_RKNSEL56_SHIFT)) & VFCCU_1_FHFLTRKC0_14_RKNSEL56_MASK)

#define VFCCU_1_FHFLTRKC0_14_RKNSEL57_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL57_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL57_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL57(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_14_RKNSEL57_SHIFT)) & VFCCU_1_FHFLTRKC0_14_RKNSEL57_MASK)

#define VFCCU_1_FHFLTRKC0_14_RKNSEL58_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL58_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL58_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL58(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_14_RKNSEL58_SHIFT)) & VFCCU_1_FHFLTRKC0_14_RKNSEL58_MASK)

#define VFCCU_1_FHFLTRKC0_14_RKNSEL59_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL59_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL59_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_14_RKNSEL59(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_14_RKNSEL59_SHIFT)) & VFCCU_1_FHFLTRKC0_14_RKNSEL59_MASK)
/*! @} */

/*! @name FHFLTRKC0_15 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_15_RKNSEL60_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL60_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL60_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL60(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_15_RKNSEL60_SHIFT)) & VFCCU_1_FHFLTRKC0_15_RKNSEL60_MASK)

#define VFCCU_1_FHFLTRKC0_15_RKNSEL61_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL61_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL61_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL61(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_15_RKNSEL61_SHIFT)) & VFCCU_1_FHFLTRKC0_15_RKNSEL61_MASK)

#define VFCCU_1_FHFLTRKC0_15_RKNSEL62_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL62_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL62_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL62(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_15_RKNSEL62_SHIFT)) & VFCCU_1_FHFLTRKC0_15_RKNSEL62_MASK)

#define VFCCU_1_FHFLTRKC0_15_RKNSEL63_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL63_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL63_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_15_RKNSEL63(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_15_RKNSEL63_SHIFT)) & VFCCU_1_FHFLTRKC0_15_RKNSEL63_MASK)
/*! @} */

/*! @name FHFLTRKC0_16 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_16_RKNSEL64_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL64_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL64_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL64(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_16_RKNSEL64_SHIFT)) & VFCCU_1_FHFLTRKC0_16_RKNSEL64_MASK)

#define VFCCU_1_FHFLTRKC0_16_RKNSEL65_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL65_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL65_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL65(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_16_RKNSEL65_SHIFT)) & VFCCU_1_FHFLTRKC0_16_RKNSEL65_MASK)

#define VFCCU_1_FHFLTRKC0_16_RKNSEL66_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL66_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL66_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL66(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_16_RKNSEL66_SHIFT)) & VFCCU_1_FHFLTRKC0_16_RKNSEL66_MASK)

#define VFCCU_1_FHFLTRKC0_16_RKNSEL67_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL67_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL67_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_16_RKNSEL67(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_16_RKNSEL67_SHIFT)) & VFCCU_1_FHFLTRKC0_16_RKNSEL67_MASK)
/*! @} */

/*! @name FHFLTRKC0_17 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_17_RKNSEL68_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL68_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL68_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL68(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_17_RKNSEL68_SHIFT)) & VFCCU_1_FHFLTRKC0_17_RKNSEL68_MASK)

#define VFCCU_1_FHFLTRKC0_17_RKNSEL69_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL69_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL69_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL69(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_17_RKNSEL69_SHIFT)) & VFCCU_1_FHFLTRKC0_17_RKNSEL69_MASK)

#define VFCCU_1_FHFLTRKC0_17_RKNSEL70_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL70_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL70_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL70(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_17_RKNSEL70_SHIFT)) & VFCCU_1_FHFLTRKC0_17_RKNSEL70_MASK)

#define VFCCU_1_FHFLTRKC0_17_RKNSEL71_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL71_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL71_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_17_RKNSEL71(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_17_RKNSEL71_SHIFT)) & VFCCU_1_FHFLTRKC0_17_RKNSEL71_MASK)
/*! @} */

/*! @name FHFLTRKC0_18 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_18_RKNSEL72_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL72_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL72_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL72(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_18_RKNSEL72_SHIFT)) & VFCCU_1_FHFLTRKC0_18_RKNSEL72_MASK)

#define VFCCU_1_FHFLTRKC0_18_RKNSEL73_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL73_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL73_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL73(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_18_RKNSEL73_SHIFT)) & VFCCU_1_FHFLTRKC0_18_RKNSEL73_MASK)

#define VFCCU_1_FHFLTRKC0_18_RKNSEL74_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL74_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL74_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL74(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_18_RKNSEL74_SHIFT)) & VFCCU_1_FHFLTRKC0_18_RKNSEL74_MASK)

#define VFCCU_1_FHFLTRKC0_18_RKNSEL75_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL75_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL75_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_18_RKNSEL75(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_18_RKNSEL75_SHIFT)) & VFCCU_1_FHFLTRKC0_18_RKNSEL75_MASK)
/*! @} */

/*! @name FHFLTRKC0_19 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_19_RKNSEL76_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL76_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL76_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL76(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_19_RKNSEL76_SHIFT)) & VFCCU_1_FHFLTRKC0_19_RKNSEL76_MASK)

#define VFCCU_1_FHFLTRKC0_19_RKNSEL77_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL77_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL77_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL77(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_19_RKNSEL77_SHIFT)) & VFCCU_1_FHFLTRKC0_19_RKNSEL77_MASK)

#define VFCCU_1_FHFLTRKC0_19_RKNSEL78_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL78_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL78_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL78(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_19_RKNSEL78_SHIFT)) & VFCCU_1_FHFLTRKC0_19_RKNSEL78_MASK)

#define VFCCU_1_FHFLTRKC0_19_RKNSEL79_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL79_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL79_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_19_RKNSEL79(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_19_RKNSEL79_SHIFT)) & VFCCU_1_FHFLTRKC0_19_RKNSEL79_MASK)
/*! @} */

/*! @name FHFLTRKC0_20 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_20_RKNSEL80_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL80_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL80_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL80(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_20_RKNSEL80_SHIFT)) & VFCCU_1_FHFLTRKC0_20_RKNSEL80_MASK)

#define VFCCU_1_FHFLTRKC0_20_RKNSEL81_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL81_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL81_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL81(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_20_RKNSEL81_SHIFT)) & VFCCU_1_FHFLTRKC0_20_RKNSEL81_MASK)

#define VFCCU_1_FHFLTRKC0_20_RKNSEL82_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL82_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL82_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL82(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_20_RKNSEL82_SHIFT)) & VFCCU_1_FHFLTRKC0_20_RKNSEL82_MASK)

#define VFCCU_1_FHFLTRKC0_20_RKNSEL83_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL83_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL83_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_20_RKNSEL83(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_20_RKNSEL83_SHIFT)) & VFCCU_1_FHFLTRKC0_20_RKNSEL83_MASK)
/*! @} */

/*! @name FHFLTRKC0_21 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_21_RKNSEL84_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL84_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL84_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL84(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_21_RKNSEL84_SHIFT)) & VFCCU_1_FHFLTRKC0_21_RKNSEL84_MASK)

#define VFCCU_1_FHFLTRKC0_21_RKNSEL85_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL85_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL85_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL85(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_21_RKNSEL85_SHIFT)) & VFCCU_1_FHFLTRKC0_21_RKNSEL85_MASK)

#define VFCCU_1_FHFLTRKC0_21_RKNSEL86_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL86_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL86_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL86(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_21_RKNSEL86_SHIFT)) & VFCCU_1_FHFLTRKC0_21_RKNSEL86_MASK)

#define VFCCU_1_FHFLTRKC0_21_RKNSEL87_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL87_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL87_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_21_RKNSEL87(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_21_RKNSEL87_SHIFT)) & VFCCU_1_FHFLTRKC0_21_RKNSEL87_MASK)
/*! @} */

/*! @name FHFLTRKC0_22 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_22_RKNSEL88_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL88_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL88_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL88(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_22_RKNSEL88_SHIFT)) & VFCCU_1_FHFLTRKC0_22_RKNSEL88_MASK)

#define VFCCU_1_FHFLTRKC0_22_RKNSEL89_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL89_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL89_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL89(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_22_RKNSEL89_SHIFT)) & VFCCU_1_FHFLTRKC0_22_RKNSEL89_MASK)

#define VFCCU_1_FHFLTRKC0_22_RKNSEL90_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL90_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL90_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL90(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_22_RKNSEL90_SHIFT)) & VFCCU_1_FHFLTRKC0_22_RKNSEL90_MASK)

#define VFCCU_1_FHFLTRKC0_22_RKNSEL91_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL91_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL91_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_22_RKNSEL91(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_22_RKNSEL91_SHIFT)) & VFCCU_1_FHFLTRKC0_22_RKNSEL91_MASK)
/*! @} */

/*! @name FHFLTRKC0_23 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_23_RKNSEL92_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL92_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL92_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL92(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_23_RKNSEL92_SHIFT)) & VFCCU_1_FHFLTRKC0_23_RKNSEL92_MASK)

#define VFCCU_1_FHFLTRKC0_23_RKNSEL93_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL93_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL93_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL93(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_23_RKNSEL93_SHIFT)) & VFCCU_1_FHFLTRKC0_23_RKNSEL93_MASK)

#define VFCCU_1_FHFLTRKC0_23_RKNSEL94_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL94_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL94_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL94(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_23_RKNSEL94_SHIFT)) & VFCCU_1_FHFLTRKC0_23_RKNSEL94_MASK)

#define VFCCU_1_FHFLTRKC0_23_RKNSEL95_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL95_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL95_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_23_RKNSEL95(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_23_RKNSEL95_SHIFT)) & VFCCU_1_FHFLTRKC0_23_RKNSEL95_MASK)
/*! @} */

/*! @name FHFLTRKC0_24 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_24_RKNSEL96_MASK       (0xFU)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL96_SHIFT      (0U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL96_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL96(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_24_RKNSEL96_SHIFT)) & VFCCU_1_FHFLTRKC0_24_RKNSEL96_MASK)

#define VFCCU_1_FHFLTRKC0_24_RKNSEL97_MASK       (0xF00U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL97_SHIFT      (8U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL97_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL97(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_24_RKNSEL97_SHIFT)) & VFCCU_1_FHFLTRKC0_24_RKNSEL97_MASK)

#define VFCCU_1_FHFLTRKC0_24_RKNSEL98_MASK       (0xF0000U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL98_SHIFT      (16U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL98_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL98(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_24_RKNSEL98_SHIFT)) & VFCCU_1_FHFLTRKC0_24_RKNSEL98_MASK)

#define VFCCU_1_FHFLTRKC0_24_RKNSEL99_MASK       (0xF000000U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL99_SHIFT      (24U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL99_WIDTH      (4U)
#define VFCCU_1_FHFLTRKC0_24_RKNSEL99(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_24_RKNSEL99_SHIFT)) & VFCCU_1_FHFLTRKC0_24_RKNSEL99_MASK)
/*! @} */

/*! @name FHFLTRKC0_25 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_25_RKNSEL100_MASK      (0xFU)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL100_SHIFT     (0U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL100_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL100(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_25_RKNSEL100_SHIFT)) & VFCCU_1_FHFLTRKC0_25_RKNSEL100_MASK)

#define VFCCU_1_FHFLTRKC0_25_RKNSEL101_MASK      (0xF00U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL101_SHIFT     (8U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL101_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL101(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_25_RKNSEL101_SHIFT)) & VFCCU_1_FHFLTRKC0_25_RKNSEL101_MASK)

#define VFCCU_1_FHFLTRKC0_25_RKNSEL102_MASK      (0xF0000U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL102_SHIFT     (16U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL102_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL102(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_25_RKNSEL102_SHIFT)) & VFCCU_1_FHFLTRKC0_25_RKNSEL102_MASK)

#define VFCCU_1_FHFLTRKC0_25_RKNSEL103_MASK      (0xF000000U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL103_SHIFT     (24U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL103_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_25_RKNSEL103(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_25_RKNSEL103_SHIFT)) & VFCCU_1_FHFLTRKC0_25_RKNSEL103_MASK)
/*! @} */

/*! @name FHFLTRKC0_26 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_26_RKNSEL104_MASK      (0xFU)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL104_SHIFT     (0U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL104_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL104(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_26_RKNSEL104_SHIFT)) & VFCCU_1_FHFLTRKC0_26_RKNSEL104_MASK)

#define VFCCU_1_FHFLTRKC0_26_RKNSEL105_MASK      (0xF00U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL105_SHIFT     (8U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL105_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL105(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_26_RKNSEL105_SHIFT)) & VFCCU_1_FHFLTRKC0_26_RKNSEL105_MASK)

#define VFCCU_1_FHFLTRKC0_26_RKNSEL106_MASK      (0xF0000U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL106_SHIFT     (16U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL106_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL106(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_26_RKNSEL106_SHIFT)) & VFCCU_1_FHFLTRKC0_26_RKNSEL106_MASK)

#define VFCCU_1_FHFLTRKC0_26_RKNSEL107_MASK      (0xF000000U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL107_SHIFT     (24U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL107_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_26_RKNSEL107(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_26_RKNSEL107_SHIFT)) & VFCCU_1_FHFLTRKC0_26_RKNSEL107_MASK)
/*! @} */

/*! @name FHFLTRKC0_27 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_27_RKNSEL108_MASK      (0xFU)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL108_SHIFT     (0U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL108_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL108(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_27_RKNSEL108_SHIFT)) & VFCCU_1_FHFLTRKC0_27_RKNSEL108_MASK)

#define VFCCU_1_FHFLTRKC0_27_RKNSEL109_MASK      (0xF00U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL109_SHIFT     (8U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL109_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL109(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_27_RKNSEL109_SHIFT)) & VFCCU_1_FHFLTRKC0_27_RKNSEL109_MASK)

#define VFCCU_1_FHFLTRKC0_27_RKNSEL110_MASK      (0xF0000U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL110_SHIFT     (16U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL110_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL110(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_27_RKNSEL110_SHIFT)) & VFCCU_1_FHFLTRKC0_27_RKNSEL110_MASK)

#define VFCCU_1_FHFLTRKC0_27_RKNSEL111_MASK      (0xF000000U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL111_SHIFT     (24U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL111_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_27_RKNSEL111(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_27_RKNSEL111_SHIFT)) & VFCCU_1_FHFLTRKC0_27_RKNSEL111_MASK)
/*! @} */

/*! @name FHFLTRKC0_28 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_28_RKNSEL112_MASK      (0xFU)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL112_SHIFT     (0U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL112_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL112(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_28_RKNSEL112_SHIFT)) & VFCCU_1_FHFLTRKC0_28_RKNSEL112_MASK)

#define VFCCU_1_FHFLTRKC0_28_RKNSEL113_MASK      (0xF00U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL113_SHIFT     (8U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL113_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL113(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_28_RKNSEL113_SHIFT)) & VFCCU_1_FHFLTRKC0_28_RKNSEL113_MASK)

#define VFCCU_1_FHFLTRKC0_28_RKNSEL114_MASK      (0xF0000U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL114_SHIFT     (16U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL114_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL114(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_28_RKNSEL114_SHIFT)) & VFCCU_1_FHFLTRKC0_28_RKNSEL114_MASK)

#define VFCCU_1_FHFLTRKC0_28_RKNSEL115_MASK      (0xF000000U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL115_SHIFT     (24U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL115_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_28_RKNSEL115(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_28_RKNSEL115_SHIFT)) & VFCCU_1_FHFLTRKC0_28_RKNSEL115_MASK)
/*! @} */

/*! @name FHFLTRKC0_29 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_29_RKNSEL116_MASK      (0xFU)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL116_SHIFT     (0U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL116_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL116(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_29_RKNSEL116_SHIFT)) & VFCCU_1_FHFLTRKC0_29_RKNSEL116_MASK)

#define VFCCU_1_FHFLTRKC0_29_RKNSEL117_MASK      (0xF00U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL117_SHIFT     (8U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL117_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL117(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_29_RKNSEL117_SHIFT)) & VFCCU_1_FHFLTRKC0_29_RKNSEL117_MASK)

#define VFCCU_1_FHFLTRKC0_29_RKNSEL118_MASK      (0xF0000U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL118_SHIFT     (16U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL118_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL118(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_29_RKNSEL118_SHIFT)) & VFCCU_1_FHFLTRKC0_29_RKNSEL118_MASK)

#define VFCCU_1_FHFLTRKC0_29_RKNSEL119_MASK      (0xF000000U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL119_SHIFT     (24U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL119_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_29_RKNSEL119(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_29_RKNSEL119_SHIFT)) & VFCCU_1_FHFLTRKC0_29_RKNSEL119_MASK)
/*! @} */

/*! @name FHFLTRKC0_30 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_30_RKNSEL120_MASK      (0xFU)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL120_SHIFT     (0U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL120_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL120(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_30_RKNSEL120_SHIFT)) & VFCCU_1_FHFLTRKC0_30_RKNSEL120_MASK)

#define VFCCU_1_FHFLTRKC0_30_RKNSEL121_MASK      (0xF00U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL121_SHIFT     (8U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL121_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL121(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_30_RKNSEL121_SHIFT)) & VFCCU_1_FHFLTRKC0_30_RKNSEL121_MASK)

#define VFCCU_1_FHFLTRKC0_30_RKNSEL122_MASK      (0xF0000U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL122_SHIFT     (16U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL122_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL122(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_30_RKNSEL122_SHIFT)) & VFCCU_1_FHFLTRKC0_30_RKNSEL122_MASK)

#define VFCCU_1_FHFLTRKC0_30_RKNSEL123_MASK      (0xF000000U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL123_SHIFT     (24U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL123_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_30_RKNSEL123(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_30_RKNSEL123_SHIFT)) & VFCCU_1_FHFLTRKC0_30_RKNSEL123_MASK)
/*! @} */

/*! @name FHFLTRKC0_31 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_1_FHFLTRKC0_31_RKNSEL124_MASK      (0xFU)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL124_SHIFT     (0U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL124_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL124(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_31_RKNSEL124_SHIFT)) & VFCCU_1_FHFLTRKC0_31_RKNSEL124_MASK)

#define VFCCU_1_FHFLTRKC0_31_RKNSEL125_MASK      (0xF00U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL125_SHIFT     (8U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL125_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL125(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_31_RKNSEL125_SHIFT)) & VFCCU_1_FHFLTRKC0_31_RKNSEL125_MASK)

#define VFCCU_1_FHFLTRKC0_31_RKNSEL126_MASK      (0xF0000U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL126_SHIFT     (16U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL126_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL126(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_31_RKNSEL126_SHIFT)) & VFCCU_1_FHFLTRKC0_31_RKNSEL126_MASK)

#define VFCCU_1_FHFLTRKC0_31_RKNSEL127_MASK      (0xF000000U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL127_SHIFT     (24U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL127_WIDTH     (4U)
#define VFCCU_1_FHFLTRKC0_31_RKNSEL127(x)        (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHFLTRKC0_31_RKNSEL127_SHIFT)) & VFCCU_1_FHFLTRKC0_31_RKNSEL127_MASK)
/*! @} */

/*! @name FHIMRKC0_00 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_00_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_00_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_00_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_00_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_00_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_00_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_00_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_00_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_00_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_00_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_00_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_00_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_00_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_00_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_00_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_00_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_00_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_00_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_00_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_00_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_00_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_00_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_00_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_00_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_00_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_00_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_00_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_00_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_00_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_00_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_00_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_00_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_00_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_00_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_00_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_10 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_10_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_10_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_10_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_10_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_10_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_10_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_10_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_10_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_10_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_10_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_10_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_10_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_10_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_10_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_10_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_10_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_10_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_10_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_10_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_10_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_10_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_10_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_10_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_10_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_10_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_10_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_10_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_10_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_10_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_10_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_10_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_10_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_10_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_10_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_10_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_20 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_20_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_20_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_20_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_20_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_20_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_20_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_20_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_20_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_20_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_20_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_20_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_20_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_20_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_20_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_20_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_20_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_20_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_20_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_20_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_20_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_20_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_20_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_20_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_20_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_20_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_20_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_20_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_20_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_20_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_20_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_20_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_20_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_20_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_20_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_20_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_30 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_30_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_30_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_30_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_30_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_30_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_30_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_30_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_30_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_30_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_30_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_30_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_30_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_30_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_30_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_30_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_30_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_30_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_30_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_30_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_30_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_30_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_30_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_30_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_30_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_30_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_30_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_30_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_30_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_30_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_30_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_30_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_30_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_30_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_30_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_30_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_40 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_40_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_40_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_40_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_40_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_40_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_40_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_40_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_40_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_40_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_40_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_40_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_40_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_40_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_40_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_40_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_40_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_40_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_40_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_40_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_40_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_40_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_40_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_40_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_40_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_40_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_40_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_40_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_40_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_40_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_40_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_40_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_40_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_40_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_40_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_40_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_50 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_50_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_50_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_50_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_50_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_50_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_50_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_50_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_50_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_50_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_50_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_50_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_50_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_50_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_50_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_50_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_50_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_50_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_50_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_50_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_50_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_50_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_50_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_50_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_50_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_50_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_50_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_50_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_50_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_50_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_50_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_50_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_50_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_50_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_50_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_50_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_60 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_60_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_60_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_60_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_60_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_60_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_60_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_60_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_60_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_60_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_60_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_60_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_60_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_60_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_60_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_60_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_60_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_60_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_60_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_60_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_60_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_60_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_60_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_60_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_60_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_60_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_60_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_60_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_60_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_60_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_60_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_60_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_60_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_60_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_60_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_60_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_70 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_70_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_70_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_70_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_70_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_70_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_70_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_70_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_70_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_70_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_70_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_70_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_70_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_70_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_70_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_70_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_70_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_70_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_70_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_70_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_70_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_70_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_70_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_70_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_70_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_70_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_70_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_70_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_70_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_70_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_70_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_70_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_70_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_70_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_70_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_70_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_80 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_80_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_80_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_80_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_80_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_80_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_80_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_80_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_80_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_80_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_80_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_80_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_80_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_80_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_80_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_80_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_80_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_80_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_80_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_80_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_80_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_80_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_80_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_80_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_80_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_80_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_80_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_80_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_80_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_80_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_80_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_80_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_80_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_80_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_80_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_80_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_90 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_90_RKNEN0_MASK          (0x1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN0_SHIFT         (0U)
#define VFCCU_1_FHIMRKC0_90_RKNEN0_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN1_MASK          (0x2U)
#define VFCCU_1_FHIMRKC0_90_RKNEN1_SHIFT         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN1_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN2_MASK          (0x4U)
#define VFCCU_1_FHIMRKC0_90_RKNEN2_SHIFT         (2U)
#define VFCCU_1_FHIMRKC0_90_RKNEN2_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN3_MASK          (0x8U)
#define VFCCU_1_FHIMRKC0_90_RKNEN3_SHIFT         (3U)
#define VFCCU_1_FHIMRKC0_90_RKNEN3_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN4_MASK          (0x10U)
#define VFCCU_1_FHIMRKC0_90_RKNEN4_SHIFT         (4U)
#define VFCCU_1_FHIMRKC0_90_RKNEN4_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN5_MASK          (0x20U)
#define VFCCU_1_FHIMRKC0_90_RKNEN5_SHIFT         (5U)
#define VFCCU_1_FHIMRKC0_90_RKNEN5_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN6_MASK          (0x40U)
#define VFCCU_1_FHIMRKC0_90_RKNEN6_SHIFT         (6U)
#define VFCCU_1_FHIMRKC0_90_RKNEN6_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN7_MASK          (0x80U)
#define VFCCU_1_FHIMRKC0_90_RKNEN7_SHIFT         (7U)
#define VFCCU_1_FHIMRKC0_90_RKNEN7_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN8_MASK          (0x100U)
#define VFCCU_1_FHIMRKC0_90_RKNEN8_SHIFT         (8U)
#define VFCCU_1_FHIMRKC0_90_RKNEN8_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN9_MASK          (0x200U)
#define VFCCU_1_FHIMRKC0_90_RKNEN9_SHIFT         (9U)
#define VFCCU_1_FHIMRKC0_90_RKNEN9_WIDTH         (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN10_MASK         (0x400U)
#define VFCCU_1_FHIMRKC0_90_RKNEN10_SHIFT        (10U)
#define VFCCU_1_FHIMRKC0_90_RKNEN10_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN11_MASK         (0x800U)
#define VFCCU_1_FHIMRKC0_90_RKNEN11_SHIFT        (11U)
#define VFCCU_1_FHIMRKC0_90_RKNEN11_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN12_MASK         (0x1000U)
#define VFCCU_1_FHIMRKC0_90_RKNEN12_SHIFT        (12U)
#define VFCCU_1_FHIMRKC0_90_RKNEN12_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN13_MASK         (0x2000U)
#define VFCCU_1_FHIMRKC0_90_RKNEN13_SHIFT        (13U)
#define VFCCU_1_FHIMRKC0_90_RKNEN13_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN14_MASK         (0x4000U)
#define VFCCU_1_FHIMRKC0_90_RKNEN14_SHIFT        (14U)
#define VFCCU_1_FHIMRKC0_90_RKNEN14_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_90_RKNEN15_MASK         (0x8000U)
#define VFCCU_1_FHIMRKC0_90_RKNEN15_SHIFT        (15U)
#define VFCCU_1_FHIMRKC0_90_RKNEN15_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_90_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_90_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_90_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_100 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_100_RKNEN0_MASK         (0x1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN0_SHIFT        (0U)
#define VFCCU_1_FHIMRKC0_100_RKNEN0_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN1_MASK         (0x2U)
#define VFCCU_1_FHIMRKC0_100_RKNEN1_SHIFT        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN1_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN2_MASK         (0x4U)
#define VFCCU_1_FHIMRKC0_100_RKNEN2_SHIFT        (2U)
#define VFCCU_1_FHIMRKC0_100_RKNEN2_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN3_MASK         (0x8U)
#define VFCCU_1_FHIMRKC0_100_RKNEN3_SHIFT        (3U)
#define VFCCU_1_FHIMRKC0_100_RKNEN3_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN4_MASK         (0x10U)
#define VFCCU_1_FHIMRKC0_100_RKNEN4_SHIFT        (4U)
#define VFCCU_1_FHIMRKC0_100_RKNEN4_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN5_MASK         (0x20U)
#define VFCCU_1_FHIMRKC0_100_RKNEN5_SHIFT        (5U)
#define VFCCU_1_FHIMRKC0_100_RKNEN5_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN6_MASK         (0x40U)
#define VFCCU_1_FHIMRKC0_100_RKNEN6_SHIFT        (6U)
#define VFCCU_1_FHIMRKC0_100_RKNEN6_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN7_MASK         (0x80U)
#define VFCCU_1_FHIMRKC0_100_RKNEN7_SHIFT        (7U)
#define VFCCU_1_FHIMRKC0_100_RKNEN7_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN8_MASK         (0x100U)
#define VFCCU_1_FHIMRKC0_100_RKNEN8_SHIFT        (8U)
#define VFCCU_1_FHIMRKC0_100_RKNEN8_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN9_MASK         (0x200U)
#define VFCCU_1_FHIMRKC0_100_RKNEN9_SHIFT        (9U)
#define VFCCU_1_FHIMRKC0_100_RKNEN9_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN10_MASK        (0x400U)
#define VFCCU_1_FHIMRKC0_100_RKNEN10_SHIFT       (10U)
#define VFCCU_1_FHIMRKC0_100_RKNEN10_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN11_MASK        (0x800U)
#define VFCCU_1_FHIMRKC0_100_RKNEN11_SHIFT       (11U)
#define VFCCU_1_FHIMRKC0_100_RKNEN11_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN12_MASK        (0x1000U)
#define VFCCU_1_FHIMRKC0_100_RKNEN12_SHIFT       (12U)
#define VFCCU_1_FHIMRKC0_100_RKNEN12_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN13_MASK        (0x2000U)
#define VFCCU_1_FHIMRKC0_100_RKNEN13_SHIFT       (13U)
#define VFCCU_1_FHIMRKC0_100_RKNEN13_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN14_MASK        (0x4000U)
#define VFCCU_1_FHIMRKC0_100_RKNEN14_SHIFT       (14U)
#define VFCCU_1_FHIMRKC0_100_RKNEN14_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_100_RKNEN15_MASK        (0x8000U)
#define VFCCU_1_FHIMRKC0_100_RKNEN15_SHIFT       (15U)
#define VFCCU_1_FHIMRKC0_100_RKNEN15_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_100_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_100_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_100_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_110 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_110_RKNEN0_MASK         (0x1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN0_SHIFT        (0U)
#define VFCCU_1_FHIMRKC0_110_RKNEN0_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN1_MASK         (0x2U)
#define VFCCU_1_FHIMRKC0_110_RKNEN1_SHIFT        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN1_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN2_MASK         (0x4U)
#define VFCCU_1_FHIMRKC0_110_RKNEN2_SHIFT        (2U)
#define VFCCU_1_FHIMRKC0_110_RKNEN2_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN3_MASK         (0x8U)
#define VFCCU_1_FHIMRKC0_110_RKNEN3_SHIFT        (3U)
#define VFCCU_1_FHIMRKC0_110_RKNEN3_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN4_MASK         (0x10U)
#define VFCCU_1_FHIMRKC0_110_RKNEN4_SHIFT        (4U)
#define VFCCU_1_FHIMRKC0_110_RKNEN4_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN5_MASK         (0x20U)
#define VFCCU_1_FHIMRKC0_110_RKNEN5_SHIFT        (5U)
#define VFCCU_1_FHIMRKC0_110_RKNEN5_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN6_MASK         (0x40U)
#define VFCCU_1_FHIMRKC0_110_RKNEN6_SHIFT        (6U)
#define VFCCU_1_FHIMRKC0_110_RKNEN6_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN7_MASK         (0x80U)
#define VFCCU_1_FHIMRKC0_110_RKNEN7_SHIFT        (7U)
#define VFCCU_1_FHIMRKC0_110_RKNEN7_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN8_MASK         (0x100U)
#define VFCCU_1_FHIMRKC0_110_RKNEN8_SHIFT        (8U)
#define VFCCU_1_FHIMRKC0_110_RKNEN8_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN9_MASK         (0x200U)
#define VFCCU_1_FHIMRKC0_110_RKNEN9_SHIFT        (9U)
#define VFCCU_1_FHIMRKC0_110_RKNEN9_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN10_MASK        (0x400U)
#define VFCCU_1_FHIMRKC0_110_RKNEN10_SHIFT       (10U)
#define VFCCU_1_FHIMRKC0_110_RKNEN10_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN11_MASK        (0x800U)
#define VFCCU_1_FHIMRKC0_110_RKNEN11_SHIFT       (11U)
#define VFCCU_1_FHIMRKC0_110_RKNEN11_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN12_MASK        (0x1000U)
#define VFCCU_1_FHIMRKC0_110_RKNEN12_SHIFT       (12U)
#define VFCCU_1_FHIMRKC0_110_RKNEN12_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN13_MASK        (0x2000U)
#define VFCCU_1_FHIMRKC0_110_RKNEN13_SHIFT       (13U)
#define VFCCU_1_FHIMRKC0_110_RKNEN13_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN14_MASK        (0x4000U)
#define VFCCU_1_FHIMRKC0_110_RKNEN14_SHIFT       (14U)
#define VFCCU_1_FHIMRKC0_110_RKNEN14_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_110_RKNEN15_MASK        (0x8000U)
#define VFCCU_1_FHIMRKC0_110_RKNEN15_SHIFT       (15U)
#define VFCCU_1_FHIMRKC0_110_RKNEN15_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_110_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_110_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_110_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_120 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_120_RKNEN0_MASK         (0x1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN0_SHIFT        (0U)
#define VFCCU_1_FHIMRKC0_120_RKNEN0_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN1_MASK         (0x2U)
#define VFCCU_1_FHIMRKC0_120_RKNEN1_SHIFT        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN1_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN2_MASK         (0x4U)
#define VFCCU_1_FHIMRKC0_120_RKNEN2_SHIFT        (2U)
#define VFCCU_1_FHIMRKC0_120_RKNEN2_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN3_MASK         (0x8U)
#define VFCCU_1_FHIMRKC0_120_RKNEN3_SHIFT        (3U)
#define VFCCU_1_FHIMRKC0_120_RKNEN3_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN4_MASK         (0x10U)
#define VFCCU_1_FHIMRKC0_120_RKNEN4_SHIFT        (4U)
#define VFCCU_1_FHIMRKC0_120_RKNEN4_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN5_MASK         (0x20U)
#define VFCCU_1_FHIMRKC0_120_RKNEN5_SHIFT        (5U)
#define VFCCU_1_FHIMRKC0_120_RKNEN5_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN6_MASK         (0x40U)
#define VFCCU_1_FHIMRKC0_120_RKNEN6_SHIFT        (6U)
#define VFCCU_1_FHIMRKC0_120_RKNEN6_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN7_MASK         (0x80U)
#define VFCCU_1_FHIMRKC0_120_RKNEN7_SHIFT        (7U)
#define VFCCU_1_FHIMRKC0_120_RKNEN7_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN8_MASK         (0x100U)
#define VFCCU_1_FHIMRKC0_120_RKNEN8_SHIFT        (8U)
#define VFCCU_1_FHIMRKC0_120_RKNEN8_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN9_MASK         (0x200U)
#define VFCCU_1_FHIMRKC0_120_RKNEN9_SHIFT        (9U)
#define VFCCU_1_FHIMRKC0_120_RKNEN9_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN10_MASK        (0x400U)
#define VFCCU_1_FHIMRKC0_120_RKNEN10_SHIFT       (10U)
#define VFCCU_1_FHIMRKC0_120_RKNEN10_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN11_MASK        (0x800U)
#define VFCCU_1_FHIMRKC0_120_RKNEN11_SHIFT       (11U)
#define VFCCU_1_FHIMRKC0_120_RKNEN11_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN12_MASK        (0x1000U)
#define VFCCU_1_FHIMRKC0_120_RKNEN12_SHIFT       (12U)
#define VFCCU_1_FHIMRKC0_120_RKNEN12_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN13_MASK        (0x2000U)
#define VFCCU_1_FHIMRKC0_120_RKNEN13_SHIFT       (13U)
#define VFCCU_1_FHIMRKC0_120_RKNEN13_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN14_MASK        (0x4000U)
#define VFCCU_1_FHIMRKC0_120_RKNEN14_SHIFT       (14U)
#define VFCCU_1_FHIMRKC0_120_RKNEN14_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_120_RKNEN15_MASK        (0x8000U)
#define VFCCU_1_FHIMRKC0_120_RKNEN15_SHIFT       (15U)
#define VFCCU_1_FHIMRKC0_120_RKNEN15_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_120_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_120_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_120_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_130 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_130_RKNEN0_MASK         (0x1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN0_SHIFT        (0U)
#define VFCCU_1_FHIMRKC0_130_RKNEN0_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN1_MASK         (0x2U)
#define VFCCU_1_FHIMRKC0_130_RKNEN1_SHIFT        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN1_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN2_MASK         (0x4U)
#define VFCCU_1_FHIMRKC0_130_RKNEN2_SHIFT        (2U)
#define VFCCU_1_FHIMRKC0_130_RKNEN2_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN3_MASK         (0x8U)
#define VFCCU_1_FHIMRKC0_130_RKNEN3_SHIFT        (3U)
#define VFCCU_1_FHIMRKC0_130_RKNEN3_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN4_MASK         (0x10U)
#define VFCCU_1_FHIMRKC0_130_RKNEN4_SHIFT        (4U)
#define VFCCU_1_FHIMRKC0_130_RKNEN4_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN5_MASK         (0x20U)
#define VFCCU_1_FHIMRKC0_130_RKNEN5_SHIFT        (5U)
#define VFCCU_1_FHIMRKC0_130_RKNEN5_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN6_MASK         (0x40U)
#define VFCCU_1_FHIMRKC0_130_RKNEN6_SHIFT        (6U)
#define VFCCU_1_FHIMRKC0_130_RKNEN6_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN7_MASK         (0x80U)
#define VFCCU_1_FHIMRKC0_130_RKNEN7_SHIFT        (7U)
#define VFCCU_1_FHIMRKC0_130_RKNEN7_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN8_MASK         (0x100U)
#define VFCCU_1_FHIMRKC0_130_RKNEN8_SHIFT        (8U)
#define VFCCU_1_FHIMRKC0_130_RKNEN8_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN9_MASK         (0x200U)
#define VFCCU_1_FHIMRKC0_130_RKNEN9_SHIFT        (9U)
#define VFCCU_1_FHIMRKC0_130_RKNEN9_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN10_MASK        (0x400U)
#define VFCCU_1_FHIMRKC0_130_RKNEN10_SHIFT       (10U)
#define VFCCU_1_FHIMRKC0_130_RKNEN10_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN11_MASK        (0x800U)
#define VFCCU_1_FHIMRKC0_130_RKNEN11_SHIFT       (11U)
#define VFCCU_1_FHIMRKC0_130_RKNEN11_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN12_MASK        (0x1000U)
#define VFCCU_1_FHIMRKC0_130_RKNEN12_SHIFT       (12U)
#define VFCCU_1_FHIMRKC0_130_RKNEN12_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN13_MASK        (0x2000U)
#define VFCCU_1_FHIMRKC0_130_RKNEN13_SHIFT       (13U)
#define VFCCU_1_FHIMRKC0_130_RKNEN13_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN14_MASK        (0x4000U)
#define VFCCU_1_FHIMRKC0_130_RKNEN14_SHIFT       (14U)
#define VFCCU_1_FHIMRKC0_130_RKNEN14_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_130_RKNEN15_MASK        (0x8000U)
#define VFCCU_1_FHIMRKC0_130_RKNEN15_SHIFT       (15U)
#define VFCCU_1_FHIMRKC0_130_RKNEN15_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_130_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_130_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_130_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_140 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_140_RKNEN0_MASK         (0x1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN0_SHIFT        (0U)
#define VFCCU_1_FHIMRKC0_140_RKNEN0_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN1_MASK         (0x2U)
#define VFCCU_1_FHIMRKC0_140_RKNEN1_SHIFT        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN1_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN2_MASK         (0x4U)
#define VFCCU_1_FHIMRKC0_140_RKNEN2_SHIFT        (2U)
#define VFCCU_1_FHIMRKC0_140_RKNEN2_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN3_MASK         (0x8U)
#define VFCCU_1_FHIMRKC0_140_RKNEN3_SHIFT        (3U)
#define VFCCU_1_FHIMRKC0_140_RKNEN3_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN4_MASK         (0x10U)
#define VFCCU_1_FHIMRKC0_140_RKNEN4_SHIFT        (4U)
#define VFCCU_1_FHIMRKC0_140_RKNEN4_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN5_MASK         (0x20U)
#define VFCCU_1_FHIMRKC0_140_RKNEN5_SHIFT        (5U)
#define VFCCU_1_FHIMRKC0_140_RKNEN5_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN6_MASK         (0x40U)
#define VFCCU_1_FHIMRKC0_140_RKNEN6_SHIFT        (6U)
#define VFCCU_1_FHIMRKC0_140_RKNEN6_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN7_MASK         (0x80U)
#define VFCCU_1_FHIMRKC0_140_RKNEN7_SHIFT        (7U)
#define VFCCU_1_FHIMRKC0_140_RKNEN7_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN8_MASK         (0x100U)
#define VFCCU_1_FHIMRKC0_140_RKNEN8_SHIFT        (8U)
#define VFCCU_1_FHIMRKC0_140_RKNEN8_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN9_MASK         (0x200U)
#define VFCCU_1_FHIMRKC0_140_RKNEN9_SHIFT        (9U)
#define VFCCU_1_FHIMRKC0_140_RKNEN9_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN10_MASK        (0x400U)
#define VFCCU_1_FHIMRKC0_140_RKNEN10_SHIFT       (10U)
#define VFCCU_1_FHIMRKC0_140_RKNEN10_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN11_MASK        (0x800U)
#define VFCCU_1_FHIMRKC0_140_RKNEN11_SHIFT       (11U)
#define VFCCU_1_FHIMRKC0_140_RKNEN11_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN12_MASK        (0x1000U)
#define VFCCU_1_FHIMRKC0_140_RKNEN12_SHIFT       (12U)
#define VFCCU_1_FHIMRKC0_140_RKNEN12_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN13_MASK        (0x2000U)
#define VFCCU_1_FHIMRKC0_140_RKNEN13_SHIFT       (13U)
#define VFCCU_1_FHIMRKC0_140_RKNEN13_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN14_MASK        (0x4000U)
#define VFCCU_1_FHIMRKC0_140_RKNEN14_SHIFT       (14U)
#define VFCCU_1_FHIMRKC0_140_RKNEN14_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_140_RKNEN15_MASK        (0x8000U)
#define VFCCU_1_FHIMRKC0_140_RKNEN15_SHIFT       (15U)
#define VFCCU_1_FHIMRKC0_140_RKNEN15_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_140_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_140_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_140_RKNEN15_MASK)
/*! @} */

/*! @name FHIMRKC0_150 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_1_FHIMRKC0_150_RKNEN0_MASK         (0x1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN0_SHIFT        (0U)
#define VFCCU_1_FHIMRKC0_150_RKNEN0_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN0_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN0_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN1_MASK         (0x2U)
#define VFCCU_1_FHIMRKC0_150_RKNEN1_SHIFT        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN1_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN1_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN1_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN2_MASK         (0x4U)
#define VFCCU_1_FHIMRKC0_150_RKNEN2_SHIFT        (2U)
#define VFCCU_1_FHIMRKC0_150_RKNEN2_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN2_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN2_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN3_MASK         (0x8U)
#define VFCCU_1_FHIMRKC0_150_RKNEN3_SHIFT        (3U)
#define VFCCU_1_FHIMRKC0_150_RKNEN3_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN3_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN3_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN4_MASK         (0x10U)
#define VFCCU_1_FHIMRKC0_150_RKNEN4_SHIFT        (4U)
#define VFCCU_1_FHIMRKC0_150_RKNEN4_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN4_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN4_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN5_MASK         (0x20U)
#define VFCCU_1_FHIMRKC0_150_RKNEN5_SHIFT        (5U)
#define VFCCU_1_FHIMRKC0_150_RKNEN5_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN5_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN5_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN6_MASK         (0x40U)
#define VFCCU_1_FHIMRKC0_150_RKNEN6_SHIFT        (6U)
#define VFCCU_1_FHIMRKC0_150_RKNEN6_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN6_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN6_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN7_MASK         (0x80U)
#define VFCCU_1_FHIMRKC0_150_RKNEN7_SHIFT        (7U)
#define VFCCU_1_FHIMRKC0_150_RKNEN7_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN7_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN7_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN8_MASK         (0x100U)
#define VFCCU_1_FHIMRKC0_150_RKNEN8_SHIFT        (8U)
#define VFCCU_1_FHIMRKC0_150_RKNEN8_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN8_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN8_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN9_MASK         (0x200U)
#define VFCCU_1_FHIMRKC0_150_RKNEN9_SHIFT        (9U)
#define VFCCU_1_FHIMRKC0_150_RKNEN9_WIDTH        (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN9_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN9_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN10_MASK        (0x400U)
#define VFCCU_1_FHIMRKC0_150_RKNEN10_SHIFT       (10U)
#define VFCCU_1_FHIMRKC0_150_RKNEN10_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN10_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN10_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN11_MASK        (0x800U)
#define VFCCU_1_FHIMRKC0_150_RKNEN11_SHIFT       (11U)
#define VFCCU_1_FHIMRKC0_150_RKNEN11_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN11_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN11_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN12_MASK        (0x1000U)
#define VFCCU_1_FHIMRKC0_150_RKNEN12_SHIFT       (12U)
#define VFCCU_1_FHIMRKC0_150_RKNEN12_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN12_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN12_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN13_MASK        (0x2000U)
#define VFCCU_1_FHIMRKC0_150_RKNEN13_SHIFT       (13U)
#define VFCCU_1_FHIMRKC0_150_RKNEN13_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN13_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN13_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN14_MASK        (0x4000U)
#define VFCCU_1_FHIMRKC0_150_RKNEN14_SHIFT       (14U)
#define VFCCU_1_FHIMRKC0_150_RKNEN14_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN14_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN14_MASK)

#define VFCCU_1_FHIMRKC0_150_RKNEN15_MASK        (0x8000U)
#define VFCCU_1_FHIMRKC0_150_RKNEN15_SHIFT       (15U)
#define VFCCU_1_FHIMRKC0_150_RKNEN15_WIDTH       (1U)
#define VFCCU_1_FHIMRKC0_150_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_1_FHIMRKC0_150_RKNEN15_SHIFT)) & VFCCU_1_FHIMRKC0_150_RKNEN15_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group VFCCU_1_Register_Masks */

/*!
 * @}
 */ /* end of group VFCCU_1_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_VFCCU_1_H_) */
