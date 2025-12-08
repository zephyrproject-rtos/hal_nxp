/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_CPE_VFCCU.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_CPE_VFCCU
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
#if !defined(S32K566_CPE_VFCCU_H_)  /* Check if memory map has not been already included */
#define S32K566_CPE_VFCCU_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CPE_VFCCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_VFCCU_Peripheral_Access_Layer CPE_VFCCU Peripheral Access Layer
 * @{
 */

/** CPE_VFCCU - Register Layout Typedef */
typedef struct CPE_VFCCU_Struct {
  uint8_t RESERVED_0[1024];
  __IO uint32_t GFLTPO_C0;                         /**< Global Fault Polarity, offset: 0x400 */
  __IO uint32_t GFLTPO_C1;                         /**< Global Fault Polarity, offset: 0x404 */
  uint8_t RESERVED_1[56];
  __IO uint32_t GFLTRC_C0;                         /**< Global Fault Recovery, offset: 0x440 */
  __IO uint32_t GFLTRC_C1;                         /**< Global Fault Recovery, offset: 0x444 */
  uint8_t RESERVED_2[2240];
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
  uint8_t RESERVED_6[56];
  __IO uint32_t FHFLTS0_0;                         /**< Fault Status, offset: 0x1050 */
  __IO uint32_t FHFLTS0_1;                         /**< Fault Status, offset: 0x1054 */
  uint8_t RESERVED_7[56];
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
  uint8_t RESERVED_8[448];
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
} CPE_VFCCU_Type, *CPE_VFCCU_MemMapPtr;

/** Number of instances of the CPE_VFCCU module. */
#define CPE_VFCCU_INSTANCE_COUNT                 (1u)

/* CPE_VFCCU - Peripheral instance base addresses */
/** Peripheral CPE_VFCCU base address */
#define IP_CPE_VFCCU_BASE                        (0x41098000u)
/** Peripheral CPE_VFCCU base pointer */
#define IP_CPE_VFCCU                             ((CPE_VFCCU_Type *)IP_CPE_VFCCU_BASE)
/** Array initializer of CPE_VFCCU peripheral base addresses */
#define IP_CPE_VFCCU_BASE_ADDRS                  { IP_CPE_VFCCU_BASE }
/** Array initializer of CPE_VFCCU peripheral base pointers */
#define IP_CPE_VFCCU_BASE_PTRS                   { IP_CPE_VFCCU }

/* ----------------------------------------------------------------------------
   -- CPE_VFCCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_VFCCU_Register_Masks CPE_VFCCU Register Masks
 * @{
 */

/*! @name GFLTPO_C0 - Global Fault Polarity */
/*! @{ */

#define CPE_VFCCU_GFLTPO_C0_PS0_MASK             (0x1U)
#define CPE_VFCCU_GFLTPO_C0_PS0_SHIFT            (0U)
#define CPE_VFCCU_GFLTPO_C0_PS0_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS0_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS0_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS1_MASK             (0x2U)
#define CPE_VFCCU_GFLTPO_C0_PS1_SHIFT            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS1_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS1_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS1_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS2_MASK             (0x4U)
#define CPE_VFCCU_GFLTPO_C0_PS2_SHIFT            (2U)
#define CPE_VFCCU_GFLTPO_C0_PS2_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS2_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS2_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS3_MASK             (0x8U)
#define CPE_VFCCU_GFLTPO_C0_PS3_SHIFT            (3U)
#define CPE_VFCCU_GFLTPO_C0_PS3_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS3_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS3_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS4_MASK             (0x10U)
#define CPE_VFCCU_GFLTPO_C0_PS4_SHIFT            (4U)
#define CPE_VFCCU_GFLTPO_C0_PS4_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS4(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS4_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS4_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS5_MASK             (0x20U)
#define CPE_VFCCU_GFLTPO_C0_PS5_SHIFT            (5U)
#define CPE_VFCCU_GFLTPO_C0_PS5_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS5(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS5_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS5_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS6_MASK             (0x40U)
#define CPE_VFCCU_GFLTPO_C0_PS6_SHIFT            (6U)
#define CPE_VFCCU_GFLTPO_C0_PS6_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS6(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS6_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS6_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS7_MASK             (0x80U)
#define CPE_VFCCU_GFLTPO_C0_PS7_SHIFT            (7U)
#define CPE_VFCCU_GFLTPO_C0_PS7_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS7(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS7_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS7_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS8_MASK             (0x100U)
#define CPE_VFCCU_GFLTPO_C0_PS8_SHIFT            (8U)
#define CPE_VFCCU_GFLTPO_C0_PS8_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS8(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS8_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS8_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS9_MASK             (0x200U)
#define CPE_VFCCU_GFLTPO_C0_PS9_SHIFT            (9U)
#define CPE_VFCCU_GFLTPO_C0_PS9_WIDTH            (1U)
#define CPE_VFCCU_GFLTPO_C0_PS9(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS9_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS9_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS10_MASK            (0x400U)
#define CPE_VFCCU_GFLTPO_C0_PS10_SHIFT           (10U)
#define CPE_VFCCU_GFLTPO_C0_PS10_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS10(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS10_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS10_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS11_MASK            (0x800U)
#define CPE_VFCCU_GFLTPO_C0_PS11_SHIFT           (11U)
#define CPE_VFCCU_GFLTPO_C0_PS11_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS11(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS11_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS11_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS12_MASK            (0x1000U)
#define CPE_VFCCU_GFLTPO_C0_PS12_SHIFT           (12U)
#define CPE_VFCCU_GFLTPO_C0_PS12_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS12(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS12_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS12_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS13_MASK            (0x2000U)
#define CPE_VFCCU_GFLTPO_C0_PS13_SHIFT           (13U)
#define CPE_VFCCU_GFLTPO_C0_PS13_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS13(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS13_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS13_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS14_MASK            (0x4000U)
#define CPE_VFCCU_GFLTPO_C0_PS14_SHIFT           (14U)
#define CPE_VFCCU_GFLTPO_C0_PS14_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS14(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS14_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS14_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS15_MASK            (0x8000U)
#define CPE_VFCCU_GFLTPO_C0_PS15_SHIFT           (15U)
#define CPE_VFCCU_GFLTPO_C0_PS15_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS15(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS15_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS15_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS16_MASK            (0x10000U)
#define CPE_VFCCU_GFLTPO_C0_PS16_SHIFT           (16U)
#define CPE_VFCCU_GFLTPO_C0_PS16_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS16(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS16_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS16_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS17_MASK            (0x20000U)
#define CPE_VFCCU_GFLTPO_C0_PS17_SHIFT           (17U)
#define CPE_VFCCU_GFLTPO_C0_PS17_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS17(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS17_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS17_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS18_MASK            (0x40000U)
#define CPE_VFCCU_GFLTPO_C0_PS18_SHIFT           (18U)
#define CPE_VFCCU_GFLTPO_C0_PS18_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS18(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS18_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS18_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS19_MASK            (0x80000U)
#define CPE_VFCCU_GFLTPO_C0_PS19_SHIFT           (19U)
#define CPE_VFCCU_GFLTPO_C0_PS19_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS19(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS19_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS19_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS20_MASK            (0x100000U)
#define CPE_VFCCU_GFLTPO_C0_PS20_SHIFT           (20U)
#define CPE_VFCCU_GFLTPO_C0_PS20_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS20(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS20_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS20_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS21_MASK            (0x200000U)
#define CPE_VFCCU_GFLTPO_C0_PS21_SHIFT           (21U)
#define CPE_VFCCU_GFLTPO_C0_PS21_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS21(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS21_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS21_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS22_MASK            (0x400000U)
#define CPE_VFCCU_GFLTPO_C0_PS22_SHIFT           (22U)
#define CPE_VFCCU_GFLTPO_C0_PS22_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS22(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS22_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS22_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS23_MASK            (0x800000U)
#define CPE_VFCCU_GFLTPO_C0_PS23_SHIFT           (23U)
#define CPE_VFCCU_GFLTPO_C0_PS23_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS23(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS23_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS23_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS24_MASK            (0x1000000U)
#define CPE_VFCCU_GFLTPO_C0_PS24_SHIFT           (24U)
#define CPE_VFCCU_GFLTPO_C0_PS24_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS24(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS24_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS24_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS25_MASK            (0x2000000U)
#define CPE_VFCCU_GFLTPO_C0_PS25_SHIFT           (25U)
#define CPE_VFCCU_GFLTPO_C0_PS25_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS25(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS25_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS25_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS26_MASK            (0x4000000U)
#define CPE_VFCCU_GFLTPO_C0_PS26_SHIFT           (26U)
#define CPE_VFCCU_GFLTPO_C0_PS26_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS26(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS26_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS26_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS27_MASK            (0x8000000U)
#define CPE_VFCCU_GFLTPO_C0_PS27_SHIFT           (27U)
#define CPE_VFCCU_GFLTPO_C0_PS27_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS27(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS27_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS27_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS28_MASK            (0x10000000U)
#define CPE_VFCCU_GFLTPO_C0_PS28_SHIFT           (28U)
#define CPE_VFCCU_GFLTPO_C0_PS28_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS28(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS28_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS28_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS29_MASK            (0x20000000U)
#define CPE_VFCCU_GFLTPO_C0_PS29_SHIFT           (29U)
#define CPE_VFCCU_GFLTPO_C0_PS29_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS29(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS29_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS29_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS30_MASK            (0x40000000U)
#define CPE_VFCCU_GFLTPO_C0_PS30_SHIFT           (30U)
#define CPE_VFCCU_GFLTPO_C0_PS30_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS30(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS30_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS30_MASK)

#define CPE_VFCCU_GFLTPO_C0_PS31_MASK            (0x80000000U)
#define CPE_VFCCU_GFLTPO_C0_PS31_SHIFT           (31U)
#define CPE_VFCCU_GFLTPO_C0_PS31_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C0_PS31(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C0_PS31_SHIFT)) & CPE_VFCCU_GFLTPO_C0_PS31_MASK)
/*! @} */

/*! @name GFLTPO_C1 - Global Fault Polarity */
/*! @{ */

#define CPE_VFCCU_GFLTPO_C1_PS32_MASK            (0x1U)
#define CPE_VFCCU_GFLTPO_C1_PS32_SHIFT           (0U)
#define CPE_VFCCU_GFLTPO_C1_PS32_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS32(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS32_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS32_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS33_MASK            (0x2U)
#define CPE_VFCCU_GFLTPO_C1_PS33_SHIFT           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS33_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS33(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS33_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS33_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS34_MASK            (0x4U)
#define CPE_VFCCU_GFLTPO_C1_PS34_SHIFT           (2U)
#define CPE_VFCCU_GFLTPO_C1_PS34_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS34(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS34_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS34_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS35_MASK            (0x8U)
#define CPE_VFCCU_GFLTPO_C1_PS35_SHIFT           (3U)
#define CPE_VFCCU_GFLTPO_C1_PS35_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS35(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS35_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS35_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS36_MASK            (0x10U)
#define CPE_VFCCU_GFLTPO_C1_PS36_SHIFT           (4U)
#define CPE_VFCCU_GFLTPO_C1_PS36_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS36(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS36_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS36_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS37_MASK            (0x20U)
#define CPE_VFCCU_GFLTPO_C1_PS37_SHIFT           (5U)
#define CPE_VFCCU_GFLTPO_C1_PS37_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS37(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS37_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS37_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS38_MASK            (0x40U)
#define CPE_VFCCU_GFLTPO_C1_PS38_SHIFT           (6U)
#define CPE_VFCCU_GFLTPO_C1_PS38_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS38(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS38_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS38_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS39_MASK            (0x80U)
#define CPE_VFCCU_GFLTPO_C1_PS39_SHIFT           (7U)
#define CPE_VFCCU_GFLTPO_C1_PS39_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS39(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS39_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS39_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS40_MASK            (0x100U)
#define CPE_VFCCU_GFLTPO_C1_PS40_SHIFT           (8U)
#define CPE_VFCCU_GFLTPO_C1_PS40_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS40(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS40_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS40_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS41_MASK            (0x200U)
#define CPE_VFCCU_GFLTPO_C1_PS41_SHIFT           (9U)
#define CPE_VFCCU_GFLTPO_C1_PS41_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS41(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS41_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS41_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS42_MASK            (0x400U)
#define CPE_VFCCU_GFLTPO_C1_PS42_SHIFT           (10U)
#define CPE_VFCCU_GFLTPO_C1_PS42_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS42(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS42_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS42_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS43_MASK            (0x800U)
#define CPE_VFCCU_GFLTPO_C1_PS43_SHIFT           (11U)
#define CPE_VFCCU_GFLTPO_C1_PS43_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS43(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS43_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS43_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS44_MASK            (0x1000U)
#define CPE_VFCCU_GFLTPO_C1_PS44_SHIFT           (12U)
#define CPE_VFCCU_GFLTPO_C1_PS44_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS44(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS44_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS44_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS45_MASK            (0x2000U)
#define CPE_VFCCU_GFLTPO_C1_PS45_SHIFT           (13U)
#define CPE_VFCCU_GFLTPO_C1_PS45_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS45(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS45_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS45_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS46_MASK            (0x4000U)
#define CPE_VFCCU_GFLTPO_C1_PS46_SHIFT           (14U)
#define CPE_VFCCU_GFLTPO_C1_PS46_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS46(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS46_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS46_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS47_MASK            (0x8000U)
#define CPE_VFCCU_GFLTPO_C1_PS47_SHIFT           (15U)
#define CPE_VFCCU_GFLTPO_C1_PS47_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS47(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS47_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS47_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS48_MASK            (0x10000U)
#define CPE_VFCCU_GFLTPO_C1_PS48_SHIFT           (16U)
#define CPE_VFCCU_GFLTPO_C1_PS48_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS48(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS48_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS48_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS49_MASK            (0x20000U)
#define CPE_VFCCU_GFLTPO_C1_PS49_SHIFT           (17U)
#define CPE_VFCCU_GFLTPO_C1_PS49_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS49(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS49_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS49_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS50_MASK            (0x40000U)
#define CPE_VFCCU_GFLTPO_C1_PS50_SHIFT           (18U)
#define CPE_VFCCU_GFLTPO_C1_PS50_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS50(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS50_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS50_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS51_MASK            (0x80000U)
#define CPE_VFCCU_GFLTPO_C1_PS51_SHIFT           (19U)
#define CPE_VFCCU_GFLTPO_C1_PS51_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS51(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS51_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS51_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS52_MASK            (0x100000U)
#define CPE_VFCCU_GFLTPO_C1_PS52_SHIFT           (20U)
#define CPE_VFCCU_GFLTPO_C1_PS52_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS52(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS52_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS52_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS53_MASK            (0x200000U)
#define CPE_VFCCU_GFLTPO_C1_PS53_SHIFT           (21U)
#define CPE_VFCCU_GFLTPO_C1_PS53_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS53(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS53_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS53_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS54_MASK            (0x400000U)
#define CPE_VFCCU_GFLTPO_C1_PS54_SHIFT           (22U)
#define CPE_VFCCU_GFLTPO_C1_PS54_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS54(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS54_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS54_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS55_MASK            (0x800000U)
#define CPE_VFCCU_GFLTPO_C1_PS55_SHIFT           (23U)
#define CPE_VFCCU_GFLTPO_C1_PS55_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS55(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS55_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS55_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS56_MASK            (0x1000000U)
#define CPE_VFCCU_GFLTPO_C1_PS56_SHIFT           (24U)
#define CPE_VFCCU_GFLTPO_C1_PS56_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS56(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS56_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS56_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS57_MASK            (0x2000000U)
#define CPE_VFCCU_GFLTPO_C1_PS57_SHIFT           (25U)
#define CPE_VFCCU_GFLTPO_C1_PS57_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS57(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS57_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS57_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS58_MASK            (0x4000000U)
#define CPE_VFCCU_GFLTPO_C1_PS58_SHIFT           (26U)
#define CPE_VFCCU_GFLTPO_C1_PS58_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS58(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS58_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS58_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS59_MASK            (0x8000000U)
#define CPE_VFCCU_GFLTPO_C1_PS59_SHIFT           (27U)
#define CPE_VFCCU_GFLTPO_C1_PS59_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS59(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS59_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS59_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS60_MASK            (0x10000000U)
#define CPE_VFCCU_GFLTPO_C1_PS60_SHIFT           (28U)
#define CPE_VFCCU_GFLTPO_C1_PS60_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS60(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS60_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS60_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS61_MASK            (0x20000000U)
#define CPE_VFCCU_GFLTPO_C1_PS61_SHIFT           (29U)
#define CPE_VFCCU_GFLTPO_C1_PS61_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS61(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS61_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS61_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS62_MASK            (0x40000000U)
#define CPE_VFCCU_GFLTPO_C1_PS62_SHIFT           (30U)
#define CPE_VFCCU_GFLTPO_C1_PS62_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS62(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS62_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS62_MASK)

#define CPE_VFCCU_GFLTPO_C1_PS63_MASK            (0x80000000U)
#define CPE_VFCCU_GFLTPO_C1_PS63_SHIFT           (31U)
#define CPE_VFCCU_GFLTPO_C1_PS63_WIDTH           (1U)
#define CPE_VFCCU_GFLTPO_C1_PS63(x)              (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTPO_C1_PS63_SHIFT)) & CPE_VFCCU_GFLTPO_C1_PS63_MASK)
/*! @} */

/*! @name GFLTRC_C0 - Global Fault Recovery */
/*! @{ */

#define CPE_VFCCU_GFLTRC_C0_RHWSW0_MASK          (0x1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW0_SHIFT         (0U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW0_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW0(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW0_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW0_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW1_MASK          (0x2U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW1_SHIFT         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW1_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW1(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW1_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW1_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW2_MASK          (0x4U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW2_SHIFT         (2U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW2_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW2(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW2_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW2_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW3_MASK          (0x8U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW3_SHIFT         (3U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW3_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW3(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW3_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW3_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW4_MASK          (0x10U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW4_SHIFT         (4U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW4_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW4(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW4_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW4_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW5_MASK          (0x20U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW5_SHIFT         (5U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW5_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW5(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW5_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW5_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW6_MASK          (0x40U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW6_SHIFT         (6U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW6_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW6(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW6_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW6_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW7_MASK          (0x80U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW7_SHIFT         (7U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW7_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW7(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW7_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW7_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW8_MASK          (0x100U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW8_SHIFT         (8U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW8_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW8(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW8_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW8_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW9_MASK          (0x200U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW9_SHIFT         (9U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW9_WIDTH         (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW9(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW9_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW9_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW10_MASK         (0x400U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW10_SHIFT        (10U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW10_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW10(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW10_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW10_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW11_MASK         (0x800U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW11_SHIFT        (11U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW11_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW11(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW11_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW11_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW12_MASK         (0x1000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW12_SHIFT        (12U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW12_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW12(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW12_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW12_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW13_MASK         (0x2000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW13_SHIFT        (13U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW13_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW13(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW13_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW13_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW14_MASK         (0x4000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW14_SHIFT        (14U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW14_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW14(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW14_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW14_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW15_MASK         (0x8000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW15_SHIFT        (15U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW15_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW15(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW15_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW15_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW16_MASK         (0x10000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW16_SHIFT        (16U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW16_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW16(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW16_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW16_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW17_MASK         (0x20000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW17_SHIFT        (17U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW17_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW17(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW17_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW17_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW18_MASK         (0x40000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW18_SHIFT        (18U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW18_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW18(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW18_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW18_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW19_MASK         (0x80000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW19_SHIFT        (19U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW19_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW19(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW19_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW19_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW20_MASK         (0x100000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW20_SHIFT        (20U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW20_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW20(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW20_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW20_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW21_MASK         (0x200000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW21_SHIFT        (21U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW21_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW21(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW21_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW21_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW22_MASK         (0x400000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW22_SHIFT        (22U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW22_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW22(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW22_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW22_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW23_MASK         (0x800000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW23_SHIFT        (23U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW23_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW23(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW23_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW23_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW24_MASK         (0x1000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW24_SHIFT        (24U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW24_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW24(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW24_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW24_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW25_MASK         (0x2000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW25_SHIFT        (25U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW25_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW25(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW25_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW25_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW26_MASK         (0x4000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW26_SHIFT        (26U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW26_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW26(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW26_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW26_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW27_MASK         (0x8000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW27_SHIFT        (27U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW27_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW27(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW27_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW27_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW28_MASK         (0x10000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW28_SHIFT        (28U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW28_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW28(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW28_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW28_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW29_MASK         (0x20000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW29_SHIFT        (29U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW29_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW29(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW29_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW29_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW30_MASK         (0x40000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW30_SHIFT        (30U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW30_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW30(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW30_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW30_MASK)

#define CPE_VFCCU_GFLTRC_C0_RHWSW31_MASK         (0x80000000U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW31_SHIFT        (31U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW31_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C0_RHWSW31(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C0_RHWSW31_SHIFT)) & CPE_VFCCU_GFLTRC_C0_RHWSW31_MASK)
/*! @} */

/*! @name GFLTRC_C1 - Global Fault Recovery */
/*! @{ */

#define CPE_VFCCU_GFLTRC_C1_RHWSW32_MASK         (0x1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW32_SHIFT        (0U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW32_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW32(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW32_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW32_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW33_MASK         (0x2U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW33_SHIFT        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW33_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW33(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW33_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW33_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW34_MASK         (0x4U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW34_SHIFT        (2U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW34_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW34(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW34_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW34_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW35_MASK         (0x8U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW35_SHIFT        (3U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW35_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW35(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW35_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW35_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW36_MASK         (0x10U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW36_SHIFT        (4U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW36_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW36(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW36_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW36_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW37_MASK         (0x20U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW37_SHIFT        (5U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW37_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW37(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW37_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW37_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW38_MASK         (0x40U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW38_SHIFT        (6U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW38_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW38(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW38_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW38_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW39_MASK         (0x80U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW39_SHIFT        (7U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW39_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW39(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW39_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW39_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW40_MASK         (0x100U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW40_SHIFT        (8U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW40_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW40(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW40_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW40_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW41_MASK         (0x200U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW41_SHIFT        (9U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW41_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW41(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW41_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW41_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW42_MASK         (0x400U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW42_SHIFT        (10U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW42_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW42(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW42_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW42_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW43_MASK         (0x800U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW43_SHIFT        (11U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW43_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW43(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW43_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW43_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW44_MASK         (0x1000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW44_SHIFT        (12U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW44_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW44(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW44_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW44_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW45_MASK         (0x2000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW45_SHIFT        (13U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW45_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW45(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW45_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW45_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW46_MASK         (0x4000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW46_SHIFT        (14U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW46_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW46(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW46_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW46_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW47_MASK         (0x8000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW47_SHIFT        (15U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW47_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW47(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW47_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW47_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW48_MASK         (0x10000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW48_SHIFT        (16U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW48_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW48(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW48_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW48_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW49_MASK         (0x20000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW49_SHIFT        (17U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW49_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW49(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW49_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW49_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW50_MASK         (0x40000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW50_SHIFT        (18U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW50_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW50(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW50_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW50_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW51_MASK         (0x80000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW51_SHIFT        (19U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW51_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW51(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW51_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW51_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW52_MASK         (0x100000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW52_SHIFT        (20U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW52_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW52(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW52_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW52_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW53_MASK         (0x200000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW53_SHIFT        (21U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW53_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW53(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW53_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW53_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW54_MASK         (0x400000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW54_SHIFT        (22U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW54_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW54(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW54_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW54_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW55_MASK         (0x800000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW55_SHIFT        (23U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW55_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW55(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW55_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW55_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW56_MASK         (0x1000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW56_SHIFT        (24U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW56_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW56(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW56_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW56_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW57_MASK         (0x2000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW57_SHIFT        (25U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW57_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW57(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW57_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW57_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW58_MASK         (0x4000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW58_SHIFT        (26U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW58_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW58(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW58_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW58_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW59_MASK         (0x8000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW59_SHIFT        (27U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW59_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW59(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW59_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW59_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW60_MASK         (0x10000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW60_SHIFT        (28U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW60_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW60(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW60_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW60_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW61_MASK         (0x20000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW61_SHIFT        (29U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW61_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW61(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW61_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW61_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW62_MASK         (0x40000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW62_SHIFT        (30U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW62_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW62(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW62_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW62_MASK)

#define CPE_VFCCU_GFLTRC_C1_RHWSW63_MASK         (0x80000000U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW63_SHIFT        (31U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW63_WIDTH        (1U)
#define CPE_VFCCU_GFLTRC_C1_RHWSW63(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GFLTRC_C1_RHWSW63_SHIFT)) & CPE_VFCCU_GFLTRC_C1_RHWSW63_MASK)
/*! @} */

/*! @name GINTOVFS - Global DID FSM Status */
/*! @{ */

#define CPE_VFCCU_GINTOVFS_FLTSERV_MASK          (0x80U)
#define CPE_VFCCU_GINTOVFS_FLTSERV_SHIFT         (7U)
#define CPE_VFCCU_GINTOVFS_FLTSERV_WIDTH         (1U)
#define CPE_VFCCU_GINTOVFS_FLTSERV(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GINTOVFS_FLTSERV_SHIFT)) & CPE_VFCCU_GINTOVFS_FLTSERV_MASK)

#define CPE_VFCCU_GINTOVFS_SERV_DID_MASK         (0xF0000U)
#define CPE_VFCCU_GINTOVFS_SERV_DID_SHIFT        (16U)
#define CPE_VFCCU_GINTOVFS_SERV_DID_WIDTH        (4U)
#define CPE_VFCCU_GINTOVFS_SERV_DID(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GINTOVFS_SERV_DID_SHIFT)) & CPE_VFCCU_GINTOVFS_SERV_DID_MASK)
/*! @} */

/*! @name GDBGCFG - Global Debug */
/*! @{ */

#define CPE_VFCCU_GDBGCFG_FRZ_MASK               (0x10000U)
#define CPE_VFCCU_GDBGCFG_FRZ_SHIFT              (16U)
#define CPE_VFCCU_GDBGCFG_FRZ_WIDTH              (1U)
#define CPE_VFCCU_GDBGCFG_FRZ(x)                 (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GDBGCFG_FRZ_SHIFT)) & CPE_VFCCU_GDBGCFG_FRZ_MASK)
/*! @} */

/*! @name GDBGSTAT - Global Debug Status */
/*! @{ */

#define CPE_VFCCU_GDBGSTAT_FLTIND_MASK           (0xFFU)
#define CPE_VFCCU_GDBGSTAT_FLTIND_SHIFT          (0U)
#define CPE_VFCCU_GDBGSTAT_FLTIND_WIDTH          (8U)
#define CPE_VFCCU_GDBGSTAT_FLTIND(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GDBGSTAT_FLTIND_SHIFT)) & CPE_VFCCU_GDBGSTAT_FLTIND_MASK)

#define CPE_VFCCU_GDBGSTAT_RKN_ACK_MASK          (0x40000000U)
#define CPE_VFCCU_GDBGSTAT_RKN_ACK_SHIFT         (30U)
#define CPE_VFCCU_GDBGSTAT_RKN_ACK_WIDTH         (1U)
#define CPE_VFCCU_GDBGSTAT_RKN_ACK(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GDBGSTAT_RKN_ACK_SHIFT)) & CPE_VFCCU_GDBGSTAT_RKN_ACK_MASK)

#define CPE_VFCCU_GDBGSTAT_RKN_REQ_MASK          (0x80000000U)
#define CPE_VFCCU_GDBGSTAT_RKN_REQ_SHIFT         (31U)
#define CPE_VFCCU_GDBGSTAT_RKN_REQ_WIDTH         (1U)
#define CPE_VFCCU_GDBGSTAT_RKN_REQ(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_GDBGSTAT_RKN_REQ_SHIFT)) & CPE_VFCCU_GDBGSTAT_RKN_REQ_MASK)
/*! @} */

/*! @name FHCFG0 - Fault Handler */
/*! @{ */

#define CPE_VFCCU_FHCFG0_FHIDEN_MASK             (0x1U)
#define CPE_VFCCU_FHCFG0_FHIDEN_SHIFT            (0U)
#define CPE_VFCCU_FHCFG0_FHIDEN_WIDTH            (1U)
#define CPE_VFCCU_FHCFG0_FHIDEN(x)               (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHCFG0_FHIDEN_SHIFT)) & CPE_VFCCU_FHCFG0_FHIDEN_MASK)
/*! @} */

/*! @name FHSRVDS0 - Fault Handler Status */
/*! @{ */

#define CPE_VFCCU_FHSRVDS0_SERV_DID_MASK         (0xFU)
#define CPE_VFCCU_FHSRVDS0_SERV_DID_SHIFT        (0U)
#define CPE_VFCCU_FHSRVDS0_SERV_DID_WIDTH        (4U)
#define CPE_VFCCU_FHSRVDS0_SERV_DID(x)           (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHSRVDS0_SERV_DID_SHIFT)) & CPE_VFCCU_FHSRVDS0_SERV_DID_MASK)

#define CPE_VFCCU_FHSRVDS0_AGGFLTS_MASK          (0x100U)
#define CPE_VFCCU_FHSRVDS0_AGGFLTS_SHIFT         (8U)
#define CPE_VFCCU_FHSRVDS0_AGGFLTS_WIDTH         (1U)
#define CPE_VFCCU_FHSRVDS0_AGGFLTS(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHSRVDS0_AGGFLTS_SHIFT)) & CPE_VFCCU_FHSRVDS0_AGGFLTS_MASK)
/*! @} */

/*! @name FHFLTENC0_0 - Fault Enable */
/*! @{ */

#define CPE_VFCCU_FHFLTENC0_0_EN0_MASK           (0x1U)
#define CPE_VFCCU_FHFLTENC0_0_EN0_SHIFT          (0U)
#define CPE_VFCCU_FHFLTENC0_0_EN0_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN0(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN0_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN0_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN1_MASK           (0x2U)
#define CPE_VFCCU_FHFLTENC0_0_EN1_SHIFT          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN1_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN1(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN1_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN1_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN2_MASK           (0x4U)
#define CPE_VFCCU_FHFLTENC0_0_EN2_SHIFT          (2U)
#define CPE_VFCCU_FHFLTENC0_0_EN2_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN2(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN2_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN2_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN3_MASK           (0x8U)
#define CPE_VFCCU_FHFLTENC0_0_EN3_SHIFT          (3U)
#define CPE_VFCCU_FHFLTENC0_0_EN3_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN3(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN3_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN3_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN4_MASK           (0x10U)
#define CPE_VFCCU_FHFLTENC0_0_EN4_SHIFT          (4U)
#define CPE_VFCCU_FHFLTENC0_0_EN4_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN4(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN4_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN4_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN5_MASK           (0x20U)
#define CPE_VFCCU_FHFLTENC0_0_EN5_SHIFT          (5U)
#define CPE_VFCCU_FHFLTENC0_0_EN5_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN5(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN5_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN5_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN6_MASK           (0x40U)
#define CPE_VFCCU_FHFLTENC0_0_EN6_SHIFT          (6U)
#define CPE_VFCCU_FHFLTENC0_0_EN6_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN6(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN6_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN6_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN7_MASK           (0x80U)
#define CPE_VFCCU_FHFLTENC0_0_EN7_SHIFT          (7U)
#define CPE_VFCCU_FHFLTENC0_0_EN7_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN7(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN7_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN7_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN8_MASK           (0x100U)
#define CPE_VFCCU_FHFLTENC0_0_EN8_SHIFT          (8U)
#define CPE_VFCCU_FHFLTENC0_0_EN8_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN8(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN8_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN8_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN9_MASK           (0x200U)
#define CPE_VFCCU_FHFLTENC0_0_EN9_SHIFT          (9U)
#define CPE_VFCCU_FHFLTENC0_0_EN9_WIDTH          (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN9(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN9_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN9_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN10_MASK          (0x400U)
#define CPE_VFCCU_FHFLTENC0_0_EN10_SHIFT         (10U)
#define CPE_VFCCU_FHFLTENC0_0_EN10_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN10(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN10_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN10_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN11_MASK          (0x800U)
#define CPE_VFCCU_FHFLTENC0_0_EN11_SHIFT         (11U)
#define CPE_VFCCU_FHFLTENC0_0_EN11_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN11(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN11_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN11_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN12_MASK          (0x1000U)
#define CPE_VFCCU_FHFLTENC0_0_EN12_SHIFT         (12U)
#define CPE_VFCCU_FHFLTENC0_0_EN12_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN12(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN12_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN12_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN13_MASK          (0x2000U)
#define CPE_VFCCU_FHFLTENC0_0_EN13_SHIFT         (13U)
#define CPE_VFCCU_FHFLTENC0_0_EN13_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN13(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN13_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN13_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN14_MASK          (0x4000U)
#define CPE_VFCCU_FHFLTENC0_0_EN14_SHIFT         (14U)
#define CPE_VFCCU_FHFLTENC0_0_EN14_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN14(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN14_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN14_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN15_MASK          (0x8000U)
#define CPE_VFCCU_FHFLTENC0_0_EN15_SHIFT         (15U)
#define CPE_VFCCU_FHFLTENC0_0_EN15_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN15(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN15_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN15_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN16_MASK          (0x10000U)
#define CPE_VFCCU_FHFLTENC0_0_EN16_SHIFT         (16U)
#define CPE_VFCCU_FHFLTENC0_0_EN16_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN16(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN16_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN16_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN17_MASK          (0x20000U)
#define CPE_VFCCU_FHFLTENC0_0_EN17_SHIFT         (17U)
#define CPE_VFCCU_FHFLTENC0_0_EN17_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN17(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN17_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN17_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN18_MASK          (0x40000U)
#define CPE_VFCCU_FHFLTENC0_0_EN18_SHIFT         (18U)
#define CPE_VFCCU_FHFLTENC0_0_EN18_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN18(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN18_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN18_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN19_MASK          (0x80000U)
#define CPE_VFCCU_FHFLTENC0_0_EN19_SHIFT         (19U)
#define CPE_VFCCU_FHFLTENC0_0_EN19_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN19(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN19_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN19_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN20_MASK          (0x100000U)
#define CPE_VFCCU_FHFLTENC0_0_EN20_SHIFT         (20U)
#define CPE_VFCCU_FHFLTENC0_0_EN20_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN20(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN20_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN20_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN21_MASK          (0x200000U)
#define CPE_VFCCU_FHFLTENC0_0_EN21_SHIFT         (21U)
#define CPE_VFCCU_FHFLTENC0_0_EN21_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN21(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN21_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN21_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN22_MASK          (0x400000U)
#define CPE_VFCCU_FHFLTENC0_0_EN22_SHIFT         (22U)
#define CPE_VFCCU_FHFLTENC0_0_EN22_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN22(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN22_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN22_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN23_MASK          (0x800000U)
#define CPE_VFCCU_FHFLTENC0_0_EN23_SHIFT         (23U)
#define CPE_VFCCU_FHFLTENC0_0_EN23_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN23(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN23_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN23_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN24_MASK          (0x1000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN24_SHIFT         (24U)
#define CPE_VFCCU_FHFLTENC0_0_EN24_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN24(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN24_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN24_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN25_MASK          (0x2000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN25_SHIFT         (25U)
#define CPE_VFCCU_FHFLTENC0_0_EN25_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN25(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN25_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN25_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN26_MASK          (0x4000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN26_SHIFT         (26U)
#define CPE_VFCCU_FHFLTENC0_0_EN26_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN26(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN26_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN26_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN27_MASK          (0x8000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN27_SHIFT         (27U)
#define CPE_VFCCU_FHFLTENC0_0_EN27_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN27(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN27_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN27_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN28_MASK          (0x10000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN28_SHIFT         (28U)
#define CPE_VFCCU_FHFLTENC0_0_EN28_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN28(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN28_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN28_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN29_MASK          (0x20000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN29_SHIFT         (29U)
#define CPE_VFCCU_FHFLTENC0_0_EN29_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN29(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN29_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN29_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN30_MASK          (0x40000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN30_SHIFT         (30U)
#define CPE_VFCCU_FHFLTENC0_0_EN30_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN30(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN30_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN30_MASK)

#define CPE_VFCCU_FHFLTENC0_0_EN31_MASK          (0x80000000U)
#define CPE_VFCCU_FHFLTENC0_0_EN31_SHIFT         (31U)
#define CPE_VFCCU_FHFLTENC0_0_EN31_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_0_EN31(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_0_EN31_SHIFT)) & CPE_VFCCU_FHFLTENC0_0_EN31_MASK)
/*! @} */

/*! @name FHFLTENC0_1 - Fault Enable */
/*! @{ */

#define CPE_VFCCU_FHFLTENC0_1_EN32_MASK          (0x1U)
#define CPE_VFCCU_FHFLTENC0_1_EN32_SHIFT         (0U)
#define CPE_VFCCU_FHFLTENC0_1_EN32_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN32(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN32_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN32_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN33_MASK          (0x2U)
#define CPE_VFCCU_FHFLTENC0_1_EN33_SHIFT         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN33_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN33(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN33_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN33_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN34_MASK          (0x4U)
#define CPE_VFCCU_FHFLTENC0_1_EN34_SHIFT         (2U)
#define CPE_VFCCU_FHFLTENC0_1_EN34_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN34(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN34_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN34_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN35_MASK          (0x8U)
#define CPE_VFCCU_FHFLTENC0_1_EN35_SHIFT         (3U)
#define CPE_VFCCU_FHFLTENC0_1_EN35_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN35(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN35_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN35_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN36_MASK          (0x10U)
#define CPE_VFCCU_FHFLTENC0_1_EN36_SHIFT         (4U)
#define CPE_VFCCU_FHFLTENC0_1_EN36_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN36(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN36_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN36_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN37_MASK          (0x20U)
#define CPE_VFCCU_FHFLTENC0_1_EN37_SHIFT         (5U)
#define CPE_VFCCU_FHFLTENC0_1_EN37_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN37(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN37_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN37_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN38_MASK          (0x40U)
#define CPE_VFCCU_FHFLTENC0_1_EN38_SHIFT         (6U)
#define CPE_VFCCU_FHFLTENC0_1_EN38_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN38(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN38_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN38_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN39_MASK          (0x80U)
#define CPE_VFCCU_FHFLTENC0_1_EN39_SHIFT         (7U)
#define CPE_VFCCU_FHFLTENC0_1_EN39_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN39(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN39_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN39_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN40_MASK          (0x100U)
#define CPE_VFCCU_FHFLTENC0_1_EN40_SHIFT         (8U)
#define CPE_VFCCU_FHFLTENC0_1_EN40_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN40(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN40_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN40_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN41_MASK          (0x200U)
#define CPE_VFCCU_FHFLTENC0_1_EN41_SHIFT         (9U)
#define CPE_VFCCU_FHFLTENC0_1_EN41_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN41(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN41_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN41_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN42_MASK          (0x400U)
#define CPE_VFCCU_FHFLTENC0_1_EN42_SHIFT         (10U)
#define CPE_VFCCU_FHFLTENC0_1_EN42_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN42(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN42_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN42_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN43_MASK          (0x800U)
#define CPE_VFCCU_FHFLTENC0_1_EN43_SHIFT         (11U)
#define CPE_VFCCU_FHFLTENC0_1_EN43_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN43(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN43_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN43_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN44_MASK          (0x1000U)
#define CPE_VFCCU_FHFLTENC0_1_EN44_SHIFT         (12U)
#define CPE_VFCCU_FHFLTENC0_1_EN44_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN44(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN44_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN44_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN45_MASK          (0x2000U)
#define CPE_VFCCU_FHFLTENC0_1_EN45_SHIFT         (13U)
#define CPE_VFCCU_FHFLTENC0_1_EN45_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN45(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN45_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN45_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN46_MASK          (0x4000U)
#define CPE_VFCCU_FHFLTENC0_1_EN46_SHIFT         (14U)
#define CPE_VFCCU_FHFLTENC0_1_EN46_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN46(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN46_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN46_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN47_MASK          (0x8000U)
#define CPE_VFCCU_FHFLTENC0_1_EN47_SHIFT         (15U)
#define CPE_VFCCU_FHFLTENC0_1_EN47_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN47(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN47_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN47_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN48_MASK          (0x10000U)
#define CPE_VFCCU_FHFLTENC0_1_EN48_SHIFT         (16U)
#define CPE_VFCCU_FHFLTENC0_1_EN48_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN48(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN48_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN48_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN49_MASK          (0x20000U)
#define CPE_VFCCU_FHFLTENC0_1_EN49_SHIFT         (17U)
#define CPE_VFCCU_FHFLTENC0_1_EN49_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN49(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN49_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN49_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN50_MASK          (0x40000U)
#define CPE_VFCCU_FHFLTENC0_1_EN50_SHIFT         (18U)
#define CPE_VFCCU_FHFLTENC0_1_EN50_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN50(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN50_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN50_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN51_MASK          (0x80000U)
#define CPE_VFCCU_FHFLTENC0_1_EN51_SHIFT         (19U)
#define CPE_VFCCU_FHFLTENC0_1_EN51_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN51(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN51_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN51_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN52_MASK          (0x100000U)
#define CPE_VFCCU_FHFLTENC0_1_EN52_SHIFT         (20U)
#define CPE_VFCCU_FHFLTENC0_1_EN52_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN52(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN52_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN52_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN53_MASK          (0x200000U)
#define CPE_VFCCU_FHFLTENC0_1_EN53_SHIFT         (21U)
#define CPE_VFCCU_FHFLTENC0_1_EN53_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN53(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN53_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN53_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN54_MASK          (0x400000U)
#define CPE_VFCCU_FHFLTENC0_1_EN54_SHIFT         (22U)
#define CPE_VFCCU_FHFLTENC0_1_EN54_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN54(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN54_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN54_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN55_MASK          (0x800000U)
#define CPE_VFCCU_FHFLTENC0_1_EN55_SHIFT         (23U)
#define CPE_VFCCU_FHFLTENC0_1_EN55_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN55(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN55_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN55_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN56_MASK          (0x1000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN56_SHIFT         (24U)
#define CPE_VFCCU_FHFLTENC0_1_EN56_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN56(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN56_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN56_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN57_MASK          (0x2000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN57_SHIFT         (25U)
#define CPE_VFCCU_FHFLTENC0_1_EN57_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN57(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN57_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN57_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN58_MASK          (0x4000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN58_SHIFT         (26U)
#define CPE_VFCCU_FHFLTENC0_1_EN58_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN58(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN58_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN58_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN59_MASK          (0x8000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN59_SHIFT         (27U)
#define CPE_VFCCU_FHFLTENC0_1_EN59_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN59(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN59_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN59_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN60_MASK          (0x10000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN60_SHIFT         (28U)
#define CPE_VFCCU_FHFLTENC0_1_EN60_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN60(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN60_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN60_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN61_MASK          (0x20000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN61_SHIFT         (29U)
#define CPE_VFCCU_FHFLTENC0_1_EN61_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN61(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN61_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN61_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN62_MASK          (0x40000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN62_SHIFT         (30U)
#define CPE_VFCCU_FHFLTENC0_1_EN62_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN62(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN62_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN62_MASK)

#define CPE_VFCCU_FHFLTENC0_1_EN63_MASK          (0x80000000U)
#define CPE_VFCCU_FHFLTENC0_1_EN63_SHIFT         (31U)
#define CPE_VFCCU_FHFLTENC0_1_EN63_WIDTH         (1U)
#define CPE_VFCCU_FHFLTENC0_1_EN63(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTENC0_1_EN63_SHIFT)) & CPE_VFCCU_FHFLTENC0_1_EN63_MASK)
/*! @} */

/*! @name FHFLTS0_0 - Fault Status */
/*! @{ */

#define CPE_VFCCU_FHFLTS0_0_STAT0_MASK           (0x1U)
#define CPE_VFCCU_FHFLTS0_0_STAT0_SHIFT          (0U)
#define CPE_VFCCU_FHFLTS0_0_STAT0_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT0(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT0_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT0_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT1_MASK           (0x2U)
#define CPE_VFCCU_FHFLTS0_0_STAT1_SHIFT          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT1_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT1(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT1_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT1_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT2_MASK           (0x4U)
#define CPE_VFCCU_FHFLTS0_0_STAT2_SHIFT          (2U)
#define CPE_VFCCU_FHFLTS0_0_STAT2_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT2(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT2_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT2_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT3_MASK           (0x8U)
#define CPE_VFCCU_FHFLTS0_0_STAT3_SHIFT          (3U)
#define CPE_VFCCU_FHFLTS0_0_STAT3_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT3(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT3_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT3_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT4_MASK           (0x10U)
#define CPE_VFCCU_FHFLTS0_0_STAT4_SHIFT          (4U)
#define CPE_VFCCU_FHFLTS0_0_STAT4_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT4(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT4_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT4_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT5_MASK           (0x20U)
#define CPE_VFCCU_FHFLTS0_0_STAT5_SHIFT          (5U)
#define CPE_VFCCU_FHFLTS0_0_STAT5_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT5(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT5_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT5_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT6_MASK           (0x40U)
#define CPE_VFCCU_FHFLTS0_0_STAT6_SHIFT          (6U)
#define CPE_VFCCU_FHFLTS0_0_STAT6_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT6(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT6_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT6_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT7_MASK           (0x80U)
#define CPE_VFCCU_FHFLTS0_0_STAT7_SHIFT          (7U)
#define CPE_VFCCU_FHFLTS0_0_STAT7_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT7(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT7_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT7_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT8_MASK           (0x100U)
#define CPE_VFCCU_FHFLTS0_0_STAT8_SHIFT          (8U)
#define CPE_VFCCU_FHFLTS0_0_STAT8_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT8(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT8_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT8_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT9_MASK           (0x200U)
#define CPE_VFCCU_FHFLTS0_0_STAT9_SHIFT          (9U)
#define CPE_VFCCU_FHFLTS0_0_STAT9_WIDTH          (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT9(x)             (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT9_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT9_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT10_MASK          (0x400U)
#define CPE_VFCCU_FHFLTS0_0_STAT10_SHIFT         (10U)
#define CPE_VFCCU_FHFLTS0_0_STAT10_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT10(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT10_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT10_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT11_MASK          (0x800U)
#define CPE_VFCCU_FHFLTS0_0_STAT11_SHIFT         (11U)
#define CPE_VFCCU_FHFLTS0_0_STAT11_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT11(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT11_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT11_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT12_MASK          (0x1000U)
#define CPE_VFCCU_FHFLTS0_0_STAT12_SHIFT         (12U)
#define CPE_VFCCU_FHFLTS0_0_STAT12_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT12(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT12_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT12_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT13_MASK          (0x2000U)
#define CPE_VFCCU_FHFLTS0_0_STAT13_SHIFT         (13U)
#define CPE_VFCCU_FHFLTS0_0_STAT13_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT13(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT13_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT13_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT14_MASK          (0x4000U)
#define CPE_VFCCU_FHFLTS0_0_STAT14_SHIFT         (14U)
#define CPE_VFCCU_FHFLTS0_0_STAT14_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT14(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT14_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT14_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT15_MASK          (0x8000U)
#define CPE_VFCCU_FHFLTS0_0_STAT15_SHIFT         (15U)
#define CPE_VFCCU_FHFLTS0_0_STAT15_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT15(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT15_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT15_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT16_MASK          (0x10000U)
#define CPE_VFCCU_FHFLTS0_0_STAT16_SHIFT         (16U)
#define CPE_VFCCU_FHFLTS0_0_STAT16_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT16(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT16_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT16_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT17_MASK          (0x20000U)
#define CPE_VFCCU_FHFLTS0_0_STAT17_SHIFT         (17U)
#define CPE_VFCCU_FHFLTS0_0_STAT17_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT17(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT17_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT17_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT18_MASK          (0x40000U)
#define CPE_VFCCU_FHFLTS0_0_STAT18_SHIFT         (18U)
#define CPE_VFCCU_FHFLTS0_0_STAT18_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT18(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT18_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT18_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT19_MASK          (0x80000U)
#define CPE_VFCCU_FHFLTS0_0_STAT19_SHIFT         (19U)
#define CPE_VFCCU_FHFLTS0_0_STAT19_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT19(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT19_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT19_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT20_MASK          (0x100000U)
#define CPE_VFCCU_FHFLTS0_0_STAT20_SHIFT         (20U)
#define CPE_VFCCU_FHFLTS0_0_STAT20_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT20(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT20_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT20_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT21_MASK          (0x200000U)
#define CPE_VFCCU_FHFLTS0_0_STAT21_SHIFT         (21U)
#define CPE_VFCCU_FHFLTS0_0_STAT21_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT21(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT21_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT21_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT22_MASK          (0x400000U)
#define CPE_VFCCU_FHFLTS0_0_STAT22_SHIFT         (22U)
#define CPE_VFCCU_FHFLTS0_0_STAT22_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT22(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT22_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT22_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT23_MASK          (0x800000U)
#define CPE_VFCCU_FHFLTS0_0_STAT23_SHIFT         (23U)
#define CPE_VFCCU_FHFLTS0_0_STAT23_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT23(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT23_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT23_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT24_MASK          (0x1000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT24_SHIFT         (24U)
#define CPE_VFCCU_FHFLTS0_0_STAT24_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT24(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT24_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT24_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT25_MASK          (0x2000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT25_SHIFT         (25U)
#define CPE_VFCCU_FHFLTS0_0_STAT25_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT25(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT25_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT25_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT26_MASK          (0x4000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT26_SHIFT         (26U)
#define CPE_VFCCU_FHFLTS0_0_STAT26_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT26(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT26_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT26_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT27_MASK          (0x8000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT27_SHIFT         (27U)
#define CPE_VFCCU_FHFLTS0_0_STAT27_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT27(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT27_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT27_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT28_MASK          (0x10000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT28_SHIFT         (28U)
#define CPE_VFCCU_FHFLTS0_0_STAT28_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT28(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT28_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT28_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT29_MASK          (0x20000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT29_SHIFT         (29U)
#define CPE_VFCCU_FHFLTS0_0_STAT29_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT29(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT29_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT29_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT30_MASK          (0x40000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT30_SHIFT         (30U)
#define CPE_VFCCU_FHFLTS0_0_STAT30_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT30(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT30_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT30_MASK)

#define CPE_VFCCU_FHFLTS0_0_STAT31_MASK          (0x80000000U)
#define CPE_VFCCU_FHFLTS0_0_STAT31_SHIFT         (31U)
#define CPE_VFCCU_FHFLTS0_0_STAT31_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_0_STAT31(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_0_STAT31_SHIFT)) & CPE_VFCCU_FHFLTS0_0_STAT31_MASK)
/*! @} */

/*! @name FHFLTS0_1 - Fault Status */
/*! @{ */

#define CPE_VFCCU_FHFLTS0_1_STAT32_MASK          (0x1U)
#define CPE_VFCCU_FHFLTS0_1_STAT32_SHIFT         (0U)
#define CPE_VFCCU_FHFLTS0_1_STAT32_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT32(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT32_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT32_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT33_MASK          (0x2U)
#define CPE_VFCCU_FHFLTS0_1_STAT33_SHIFT         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT33_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT33(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT33_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT33_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT34_MASK          (0x4U)
#define CPE_VFCCU_FHFLTS0_1_STAT34_SHIFT         (2U)
#define CPE_VFCCU_FHFLTS0_1_STAT34_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT34(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT34_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT34_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT35_MASK          (0x8U)
#define CPE_VFCCU_FHFLTS0_1_STAT35_SHIFT         (3U)
#define CPE_VFCCU_FHFLTS0_1_STAT35_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT35(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT35_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT35_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT36_MASK          (0x10U)
#define CPE_VFCCU_FHFLTS0_1_STAT36_SHIFT         (4U)
#define CPE_VFCCU_FHFLTS0_1_STAT36_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT36(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT36_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT36_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT37_MASK          (0x20U)
#define CPE_VFCCU_FHFLTS0_1_STAT37_SHIFT         (5U)
#define CPE_VFCCU_FHFLTS0_1_STAT37_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT37(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT37_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT37_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT38_MASK          (0x40U)
#define CPE_VFCCU_FHFLTS0_1_STAT38_SHIFT         (6U)
#define CPE_VFCCU_FHFLTS0_1_STAT38_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT38(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT38_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT38_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT39_MASK          (0x80U)
#define CPE_VFCCU_FHFLTS0_1_STAT39_SHIFT         (7U)
#define CPE_VFCCU_FHFLTS0_1_STAT39_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT39(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT39_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT39_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT40_MASK          (0x100U)
#define CPE_VFCCU_FHFLTS0_1_STAT40_SHIFT         (8U)
#define CPE_VFCCU_FHFLTS0_1_STAT40_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT40(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT40_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT40_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT41_MASK          (0x200U)
#define CPE_VFCCU_FHFLTS0_1_STAT41_SHIFT         (9U)
#define CPE_VFCCU_FHFLTS0_1_STAT41_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT41(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT41_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT41_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT42_MASK          (0x400U)
#define CPE_VFCCU_FHFLTS0_1_STAT42_SHIFT         (10U)
#define CPE_VFCCU_FHFLTS0_1_STAT42_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT42(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT42_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT42_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT43_MASK          (0x800U)
#define CPE_VFCCU_FHFLTS0_1_STAT43_SHIFT         (11U)
#define CPE_VFCCU_FHFLTS0_1_STAT43_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT43(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT43_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT43_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT44_MASK          (0x1000U)
#define CPE_VFCCU_FHFLTS0_1_STAT44_SHIFT         (12U)
#define CPE_VFCCU_FHFLTS0_1_STAT44_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT44(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT44_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT44_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT45_MASK          (0x2000U)
#define CPE_VFCCU_FHFLTS0_1_STAT45_SHIFT         (13U)
#define CPE_VFCCU_FHFLTS0_1_STAT45_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT45(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT45_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT45_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT46_MASK          (0x4000U)
#define CPE_VFCCU_FHFLTS0_1_STAT46_SHIFT         (14U)
#define CPE_VFCCU_FHFLTS0_1_STAT46_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT46(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT46_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT46_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT47_MASK          (0x8000U)
#define CPE_VFCCU_FHFLTS0_1_STAT47_SHIFT         (15U)
#define CPE_VFCCU_FHFLTS0_1_STAT47_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT47(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT47_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT47_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT48_MASK          (0x10000U)
#define CPE_VFCCU_FHFLTS0_1_STAT48_SHIFT         (16U)
#define CPE_VFCCU_FHFLTS0_1_STAT48_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT48(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT48_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT48_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT49_MASK          (0x20000U)
#define CPE_VFCCU_FHFLTS0_1_STAT49_SHIFT         (17U)
#define CPE_VFCCU_FHFLTS0_1_STAT49_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT49(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT49_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT49_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT50_MASK          (0x40000U)
#define CPE_VFCCU_FHFLTS0_1_STAT50_SHIFT         (18U)
#define CPE_VFCCU_FHFLTS0_1_STAT50_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT50(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT50_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT50_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT51_MASK          (0x80000U)
#define CPE_VFCCU_FHFLTS0_1_STAT51_SHIFT         (19U)
#define CPE_VFCCU_FHFLTS0_1_STAT51_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT51(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT51_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT51_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT52_MASK          (0x100000U)
#define CPE_VFCCU_FHFLTS0_1_STAT52_SHIFT         (20U)
#define CPE_VFCCU_FHFLTS0_1_STAT52_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT52(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT52_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT52_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT53_MASK          (0x200000U)
#define CPE_VFCCU_FHFLTS0_1_STAT53_SHIFT         (21U)
#define CPE_VFCCU_FHFLTS0_1_STAT53_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT53(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT53_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT53_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT54_MASK          (0x400000U)
#define CPE_VFCCU_FHFLTS0_1_STAT54_SHIFT         (22U)
#define CPE_VFCCU_FHFLTS0_1_STAT54_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT54(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT54_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT54_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT55_MASK          (0x800000U)
#define CPE_VFCCU_FHFLTS0_1_STAT55_SHIFT         (23U)
#define CPE_VFCCU_FHFLTS0_1_STAT55_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT55(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT55_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT55_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT56_MASK          (0x1000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT56_SHIFT         (24U)
#define CPE_VFCCU_FHFLTS0_1_STAT56_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT56(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT56_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT56_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT57_MASK          (0x2000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT57_SHIFT         (25U)
#define CPE_VFCCU_FHFLTS0_1_STAT57_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT57(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT57_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT57_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT58_MASK          (0x4000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT58_SHIFT         (26U)
#define CPE_VFCCU_FHFLTS0_1_STAT58_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT58(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT58_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT58_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT59_MASK          (0x8000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT59_SHIFT         (27U)
#define CPE_VFCCU_FHFLTS0_1_STAT59_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT59(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT59_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT59_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT60_MASK          (0x10000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT60_SHIFT         (28U)
#define CPE_VFCCU_FHFLTS0_1_STAT60_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT60(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT60_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT60_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT61_MASK          (0x20000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT61_SHIFT         (29U)
#define CPE_VFCCU_FHFLTS0_1_STAT61_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT61(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT61_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT61_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT62_MASK          (0x40000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT62_SHIFT         (30U)
#define CPE_VFCCU_FHFLTS0_1_STAT62_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT62(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT62_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT62_MASK)

#define CPE_VFCCU_FHFLTS0_1_STAT63_MASK          (0x80000000U)
#define CPE_VFCCU_FHFLTS0_1_STAT63_SHIFT         (31U)
#define CPE_VFCCU_FHFLTS0_1_STAT63_WIDTH         (1U)
#define CPE_VFCCU_FHFLTS0_1_STAT63(x)            (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTS0_1_STAT63_SHIFT)) & CPE_VFCCU_FHFLTS0_1_STAT63_MASK)
/*! @} */

/*! @name FHFLTRKC0_0 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL0_MASK       (0x7U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL0_SHIFT      (0U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL0_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL0(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_0_RKNSEL0_SHIFT)) & CPE_VFCCU_FHFLTRKC0_0_RKNSEL0_MASK)

#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL1_MASK       (0x700U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL1_SHIFT      (8U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL1_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL1(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_0_RKNSEL1_SHIFT)) & CPE_VFCCU_FHFLTRKC0_0_RKNSEL1_MASK)

#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL2_MASK       (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL2_SHIFT      (16U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL2_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL2(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_0_RKNSEL2_SHIFT)) & CPE_VFCCU_FHFLTRKC0_0_RKNSEL2_MASK)

#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL3_MASK       (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL3_SHIFT      (24U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL3_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_0_RKNSEL3(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_0_RKNSEL3_SHIFT)) & CPE_VFCCU_FHFLTRKC0_0_RKNSEL3_MASK)
/*! @} */

/*! @name FHFLTRKC0_1 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL4_MASK       (0x7U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL4_SHIFT      (0U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL4_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL4(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_1_RKNSEL4_SHIFT)) & CPE_VFCCU_FHFLTRKC0_1_RKNSEL4_MASK)

#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL5_MASK       (0x700U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL5_SHIFT      (8U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL5_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL5(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_1_RKNSEL5_SHIFT)) & CPE_VFCCU_FHFLTRKC0_1_RKNSEL5_MASK)

#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL6_MASK       (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL6_SHIFT      (16U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL6_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL6(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_1_RKNSEL6_SHIFT)) & CPE_VFCCU_FHFLTRKC0_1_RKNSEL6_MASK)

#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL7_MASK       (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL7_SHIFT      (24U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL7_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_1_RKNSEL7(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_1_RKNSEL7_SHIFT)) & CPE_VFCCU_FHFLTRKC0_1_RKNSEL7_MASK)
/*! @} */

/*! @name FHFLTRKC0_2 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL8_MASK       (0x7U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL8_SHIFT      (0U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL8_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL8(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_2_RKNSEL8_SHIFT)) & CPE_VFCCU_FHFLTRKC0_2_RKNSEL8_MASK)

#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL9_MASK       (0x700U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL9_SHIFT      (8U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL9_WIDTH      (3U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL9(x)         (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_2_RKNSEL9_SHIFT)) & CPE_VFCCU_FHFLTRKC0_2_RKNSEL9_MASK)

#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL10_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL10_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL10_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL10(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_2_RKNSEL10_SHIFT)) & CPE_VFCCU_FHFLTRKC0_2_RKNSEL10_MASK)

#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL11_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL11_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL11_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_2_RKNSEL11(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_2_RKNSEL11_SHIFT)) & CPE_VFCCU_FHFLTRKC0_2_RKNSEL11_MASK)
/*! @} */

/*! @name FHFLTRKC0_3 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL12_MASK      (0x7U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL12_SHIFT     (0U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL12_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL12(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_3_RKNSEL12_SHIFT)) & CPE_VFCCU_FHFLTRKC0_3_RKNSEL12_MASK)

#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL13_MASK      (0x700U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL13_SHIFT     (8U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL13_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL13(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_3_RKNSEL13_SHIFT)) & CPE_VFCCU_FHFLTRKC0_3_RKNSEL13_MASK)

#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL14_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL14_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL14_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL14(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_3_RKNSEL14_SHIFT)) & CPE_VFCCU_FHFLTRKC0_3_RKNSEL14_MASK)

#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL15_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL15_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL15_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_3_RKNSEL15(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_3_RKNSEL15_SHIFT)) & CPE_VFCCU_FHFLTRKC0_3_RKNSEL15_MASK)
/*! @} */

/*! @name FHFLTRKC0_4 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL16_MASK      (0x7U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL16_SHIFT     (0U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL16_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL16(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_4_RKNSEL16_SHIFT)) & CPE_VFCCU_FHFLTRKC0_4_RKNSEL16_MASK)

#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL17_MASK      (0x700U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL17_SHIFT     (8U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL17_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL17(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_4_RKNSEL17_SHIFT)) & CPE_VFCCU_FHFLTRKC0_4_RKNSEL17_MASK)

#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL18_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL18_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL18_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL18(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_4_RKNSEL18_SHIFT)) & CPE_VFCCU_FHFLTRKC0_4_RKNSEL18_MASK)

#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL19_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL19_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL19_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_4_RKNSEL19(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_4_RKNSEL19_SHIFT)) & CPE_VFCCU_FHFLTRKC0_4_RKNSEL19_MASK)
/*! @} */

/*! @name FHFLTRKC0_5 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL20_MASK      (0x7U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL20_SHIFT     (0U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL20_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL20(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_5_RKNSEL20_SHIFT)) & CPE_VFCCU_FHFLTRKC0_5_RKNSEL20_MASK)

#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL21_MASK      (0x700U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL21_SHIFT     (8U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL21_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL21(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_5_RKNSEL21_SHIFT)) & CPE_VFCCU_FHFLTRKC0_5_RKNSEL21_MASK)

#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL22_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL22_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL22_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL22(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_5_RKNSEL22_SHIFT)) & CPE_VFCCU_FHFLTRKC0_5_RKNSEL22_MASK)

#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL23_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL23_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL23_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_5_RKNSEL23(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_5_RKNSEL23_SHIFT)) & CPE_VFCCU_FHFLTRKC0_5_RKNSEL23_MASK)
/*! @} */

/*! @name FHFLTRKC0_6 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL24_MASK      (0x7U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL24_SHIFT     (0U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL24_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL24(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_6_RKNSEL24_SHIFT)) & CPE_VFCCU_FHFLTRKC0_6_RKNSEL24_MASK)

#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL25_MASK      (0x700U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL25_SHIFT     (8U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL25_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL25(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_6_RKNSEL25_SHIFT)) & CPE_VFCCU_FHFLTRKC0_6_RKNSEL25_MASK)

#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL26_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL26_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL26_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL26(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_6_RKNSEL26_SHIFT)) & CPE_VFCCU_FHFLTRKC0_6_RKNSEL26_MASK)

#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL27_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL27_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL27_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_6_RKNSEL27(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_6_RKNSEL27_SHIFT)) & CPE_VFCCU_FHFLTRKC0_6_RKNSEL27_MASK)
/*! @} */

/*! @name FHFLTRKC0_7 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL28_MASK      (0x7U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL28_SHIFT     (0U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL28_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL28(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_7_RKNSEL28_SHIFT)) & CPE_VFCCU_FHFLTRKC0_7_RKNSEL28_MASK)

#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL29_MASK      (0x700U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL29_SHIFT     (8U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL29_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL29(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_7_RKNSEL29_SHIFT)) & CPE_VFCCU_FHFLTRKC0_7_RKNSEL29_MASK)

#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL30_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL30_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL30_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL30(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_7_RKNSEL30_SHIFT)) & CPE_VFCCU_FHFLTRKC0_7_RKNSEL30_MASK)

#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL31_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL31_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL31_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_7_RKNSEL31(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_7_RKNSEL31_SHIFT)) & CPE_VFCCU_FHFLTRKC0_7_RKNSEL31_MASK)
/*! @} */

/*! @name FHFLTRKC0_8 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL32_MASK      (0x7U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL32_SHIFT     (0U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL32_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL32(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_8_RKNSEL32_SHIFT)) & CPE_VFCCU_FHFLTRKC0_8_RKNSEL32_MASK)

#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL33_MASK      (0x700U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL33_SHIFT     (8U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL33_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL33(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_8_RKNSEL33_SHIFT)) & CPE_VFCCU_FHFLTRKC0_8_RKNSEL33_MASK)

#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL34_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL34_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL34_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL34(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_8_RKNSEL34_SHIFT)) & CPE_VFCCU_FHFLTRKC0_8_RKNSEL34_MASK)

#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL35_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL35_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL35_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_8_RKNSEL35(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_8_RKNSEL35_SHIFT)) & CPE_VFCCU_FHFLTRKC0_8_RKNSEL35_MASK)
/*! @} */

/*! @name FHFLTRKC0_9 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL36_MASK      (0x7U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL36_SHIFT     (0U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL36_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL36(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_9_RKNSEL36_SHIFT)) & CPE_VFCCU_FHFLTRKC0_9_RKNSEL36_MASK)

#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL37_MASK      (0x700U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL37_SHIFT     (8U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL37_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL37(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_9_RKNSEL37_SHIFT)) & CPE_VFCCU_FHFLTRKC0_9_RKNSEL37_MASK)

#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL38_MASK      (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL38_SHIFT     (16U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL38_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL38(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_9_RKNSEL38_SHIFT)) & CPE_VFCCU_FHFLTRKC0_9_RKNSEL38_MASK)

#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL39_MASK      (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL39_SHIFT     (24U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL39_WIDTH     (3U)
#define CPE_VFCCU_FHFLTRKC0_9_RKNSEL39(x)        (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_9_RKNSEL39_SHIFT)) & CPE_VFCCU_FHFLTRKC0_9_RKNSEL39_MASK)
/*! @} */

/*! @name FHFLTRKC0_10 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL40_MASK     (0x7U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL40_SHIFT    (0U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL40_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL40(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_10_RKNSEL40_SHIFT)) & CPE_VFCCU_FHFLTRKC0_10_RKNSEL40_MASK)

#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL41_MASK     (0x700U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL41_SHIFT    (8U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL41_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL41(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_10_RKNSEL41_SHIFT)) & CPE_VFCCU_FHFLTRKC0_10_RKNSEL41_MASK)

#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL42_MASK     (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL42_SHIFT    (16U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL42_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL42(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_10_RKNSEL42_SHIFT)) & CPE_VFCCU_FHFLTRKC0_10_RKNSEL42_MASK)

#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL43_MASK     (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL43_SHIFT    (24U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL43_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_10_RKNSEL43(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_10_RKNSEL43_SHIFT)) & CPE_VFCCU_FHFLTRKC0_10_RKNSEL43_MASK)
/*! @} */

/*! @name FHFLTRKC0_11 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL44_MASK     (0x7U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL44_SHIFT    (0U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL44_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL44(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_11_RKNSEL44_SHIFT)) & CPE_VFCCU_FHFLTRKC0_11_RKNSEL44_MASK)

#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL45_MASK     (0x700U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL45_SHIFT    (8U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL45_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL45(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_11_RKNSEL45_SHIFT)) & CPE_VFCCU_FHFLTRKC0_11_RKNSEL45_MASK)

#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL46_MASK     (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL46_SHIFT    (16U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL46_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL46(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_11_RKNSEL46_SHIFT)) & CPE_VFCCU_FHFLTRKC0_11_RKNSEL46_MASK)

#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL47_MASK     (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL47_SHIFT    (24U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL47_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_11_RKNSEL47(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_11_RKNSEL47_SHIFT)) & CPE_VFCCU_FHFLTRKC0_11_RKNSEL47_MASK)
/*! @} */

/*! @name FHFLTRKC0_12 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL48_MASK     (0x7U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL48_SHIFT    (0U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL48_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL48(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_12_RKNSEL48_SHIFT)) & CPE_VFCCU_FHFLTRKC0_12_RKNSEL48_MASK)

#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL49_MASK     (0x700U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL49_SHIFT    (8U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL49_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL49(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_12_RKNSEL49_SHIFT)) & CPE_VFCCU_FHFLTRKC0_12_RKNSEL49_MASK)

#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL50_MASK     (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL50_SHIFT    (16U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL50_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL50(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_12_RKNSEL50_SHIFT)) & CPE_VFCCU_FHFLTRKC0_12_RKNSEL50_MASK)

#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL51_MASK     (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL51_SHIFT    (24U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL51_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_12_RKNSEL51(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_12_RKNSEL51_SHIFT)) & CPE_VFCCU_FHFLTRKC0_12_RKNSEL51_MASK)
/*! @} */

/*! @name FHFLTRKC0_13 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL52_MASK     (0x7U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL52_SHIFT    (0U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL52_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL52(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_13_RKNSEL52_SHIFT)) & CPE_VFCCU_FHFLTRKC0_13_RKNSEL52_MASK)

#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL53_MASK     (0x700U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL53_SHIFT    (8U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL53_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL53(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_13_RKNSEL53_SHIFT)) & CPE_VFCCU_FHFLTRKC0_13_RKNSEL53_MASK)

#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL54_MASK     (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL54_SHIFT    (16U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL54_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL54(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_13_RKNSEL54_SHIFT)) & CPE_VFCCU_FHFLTRKC0_13_RKNSEL54_MASK)

#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL55_MASK     (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL55_SHIFT    (24U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL55_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_13_RKNSEL55(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_13_RKNSEL55_SHIFT)) & CPE_VFCCU_FHFLTRKC0_13_RKNSEL55_MASK)
/*! @} */

/*! @name FHFLTRKC0_14 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL56_MASK     (0x7U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL56_SHIFT    (0U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL56_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL56(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_14_RKNSEL56_SHIFT)) & CPE_VFCCU_FHFLTRKC0_14_RKNSEL56_MASK)

#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL57_MASK     (0x700U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL57_SHIFT    (8U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL57_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL57(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_14_RKNSEL57_SHIFT)) & CPE_VFCCU_FHFLTRKC0_14_RKNSEL57_MASK)

#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL58_MASK     (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL58_SHIFT    (16U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL58_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL58(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_14_RKNSEL58_SHIFT)) & CPE_VFCCU_FHFLTRKC0_14_RKNSEL58_MASK)

#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL59_MASK     (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL59_SHIFT    (24U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL59_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_14_RKNSEL59(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_14_RKNSEL59_SHIFT)) & CPE_VFCCU_FHFLTRKC0_14_RKNSEL59_MASK)
/*! @} */

/*! @name FHFLTRKC0_15 - Fault Reaction Set Configuration */
/*! @{ */

#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL60_MASK     (0x7U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL60_SHIFT    (0U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL60_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL60(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_15_RKNSEL60_SHIFT)) & CPE_VFCCU_FHFLTRKC0_15_RKNSEL60_MASK)

#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL61_MASK     (0x700U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL61_SHIFT    (8U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL61_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL61(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_15_RKNSEL61_SHIFT)) & CPE_VFCCU_FHFLTRKC0_15_RKNSEL61_MASK)

#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL62_MASK     (0x70000U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL62_SHIFT    (16U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL62_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL62(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_15_RKNSEL62_SHIFT)) & CPE_VFCCU_FHFLTRKC0_15_RKNSEL62_MASK)

#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL63_MASK     (0x7000000U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL63_SHIFT    (24U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL63_WIDTH    (3U)
#define CPE_VFCCU_FHFLTRKC0_15_RKNSEL63(x)       (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHFLTRKC0_15_RKNSEL63_SHIFT)) & CPE_VFCCU_FHFLTRKC0_15_RKNSEL63_MASK)
/*! @} */

/*! @name FHIMRKC0_00 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_00_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_00_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_00_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_00_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_00_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_00_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_00_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_00_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_00_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_00_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_00_RKNEN7_MASK)
/*! @} */

/*! @name FHIMRKC0_10 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_10_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_10_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_10_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_10_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_10_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_10_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_10_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_10_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_10_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_10_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_10_RKNEN7_MASK)
/*! @} */

/*! @name FHIMRKC0_20 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_20_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_20_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_20_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_20_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_20_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_20_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_20_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_20_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_20_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_20_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_20_RKNEN7_MASK)
/*! @} */

/*! @name FHIMRKC0_30 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_30_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_30_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_30_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_30_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_30_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_30_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_30_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_30_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_30_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_30_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_30_RKNEN7_MASK)
/*! @} */

/*! @name FHIMRKC0_40 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_40_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_40_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_40_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_40_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_40_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_40_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_40_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_40_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_40_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_40_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_40_RKNEN7_MASK)
/*! @} */

/*! @name FHIMRKC0_50 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_50_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_50_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_50_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_50_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_50_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_50_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_50_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_50_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_50_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_50_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_50_RKNEN7_MASK)
/*! @} */

/*! @name FHIMRKC0_60 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_60_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_60_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_60_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_60_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_60_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_60_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_60_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_60_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_60_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_60_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_60_RKNEN7_MASK)
/*! @} */

/*! @name FHIMRKC0_70 - Immediate Reaction Configuration */
/*! @{ */

#define CPE_VFCCU_FHIMRKC0_70_RKNEN0_MASK        (0x1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN0_SHIFT       (0U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN0_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN0(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN0_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN0_MASK)

#define CPE_VFCCU_FHIMRKC0_70_RKNEN1_MASK        (0x2U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN1_SHIFT       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN1_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN1(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN1_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN1_MASK)

#define CPE_VFCCU_FHIMRKC0_70_RKNEN2_MASK        (0x4U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN2_SHIFT       (2U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN2_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN2(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN2_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN2_MASK)

#define CPE_VFCCU_FHIMRKC0_70_RKNEN3_MASK        (0x8U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN3_SHIFT       (3U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN3_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN3(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN3_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN3_MASK)

#define CPE_VFCCU_FHIMRKC0_70_RKNEN4_MASK        (0x10U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN4_SHIFT       (4U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN4_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN4(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN4_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN4_MASK)

#define CPE_VFCCU_FHIMRKC0_70_RKNEN5_MASK        (0x20U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN5_SHIFT       (5U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN5_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN5(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN5_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN5_MASK)

#define CPE_VFCCU_FHIMRKC0_70_RKNEN6_MASK        (0x40U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN6_SHIFT       (6U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN6_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN6(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN6_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN6_MASK)

#define CPE_VFCCU_FHIMRKC0_70_RKNEN7_MASK        (0x80U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN7_SHIFT       (7U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN7_WIDTH       (1U)
#define CPE_VFCCU_FHIMRKC0_70_RKNEN7(x)          (((uint32_t)(((uint32_t)(x)) << CPE_VFCCU_FHIMRKC0_70_RKNEN7_SHIFT)) & CPE_VFCCU_FHIMRKC0_70_RKNEN7_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CPE_VFCCU_Register_Masks */

/*!
 * @}
 */ /* end of group CPE_VFCCU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_CPE_VFCCU_H_) */
