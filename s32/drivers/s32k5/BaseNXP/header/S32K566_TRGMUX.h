/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_TRGMUX.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_TRGMUX
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
#if !defined(S32K566_TRGMUX_H_)  /* Check if memory map has not been already included */
#define S32K566_TRGMUX_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */

/** TRGMUX - Register Layout Typedef */
typedef struct TRGMUX_Struct {
  __IO uint32_t REG_0;                             /**< TRGMUX REG_0, offset: 0x0 */
  __IO uint32_t REG_1;                             /**< TRGMUX REG_1, offset: 0x4 */
  __IO uint32_t REG_2;                             /**< TRGMUX REG_2, offset: 0x8 */
  __IO uint32_t REG_3;                             /**< TRGMUX REG_3, offset: 0xC */
  __IO uint32_t REG_4;                             /**< TRGMUX REG_4, offset: 0x10 */
  __IO uint32_t REG_5;                             /**< TRGMUX REG_5, offset: 0x14 */
  __IO uint32_t REG_6;                             /**< TRGMUX REG_6, offset: 0x18 */
  __IO uint32_t REG_7;                             /**< TRGMUX REG_7, offset: 0x1C */
  __IO uint32_t REG_8;                             /**< TRGMUX REG_8, offset: 0x20 */
  __IO uint32_t REG_9;                             /**< TRGMUX REG_9, offset: 0x24 */
  __IO uint32_t REG_10;                            /**< TRGMUX REG_10, offset: 0x28 */
  __IO uint32_t REG_11;                            /**< TRGMUX REG_11, offset: 0x2C */
  __IO uint32_t REG_12;                            /**< TRGMUX REG_12, offset: 0x30 */
  __IO uint32_t REG_13;                            /**< TRGMUX REG_13, offset: 0x34 */
  __IO uint32_t REG_14;                            /**< TRGMUX REG_14, offset: 0x38 */
  __IO uint32_t REG_15;                            /**< TRGMUX REG_15, offset: 0x3C */
  __IO uint32_t REG_16;                            /**< TRGMUX REG_16, offset: 0x40, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_17;                            /**< TRGMUX REG_17, offset: 0x44, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_18;                            /**< TRGMUX REG_18, offset: 0x48, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_19;                            /**< TRGMUX REG_19, offset: 0x4C, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_20;                            /**< TRGMUX REG_20, offset: 0x50, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_21;                            /**< TRGMUX REG_21, offset: 0x54, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_22;                            /**< TRGMUX REG_22, offset: 0x58, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_23;                            /**< TRGMUX REG_23, offset: 0x5C, available only on: TRGMUX_0, TRGMUX_1 (missing on LPE_TRGMUX) */
  __IO uint32_t REG_24;                            /**< TRGMUX REG_24, offset: 0x60, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_25;                            /**< TRGMUX REG_25, offset: 0x64, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_26;                            /**< TRGMUX REG_26, offset: 0x68, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_27;                            /**< TRGMUX REG_27, offset: 0x6C, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_28;                            /**< TRGMUX REG_28, offset: 0x70, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_29;                            /**< TRGMUX REG_29, offset: 0x74, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_30;                            /**< TRGMUX REG_30, offset: 0x78, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_31;                            /**< TRGMUX REG_31, offset: 0x7C, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_32;                            /**< TRGMUX REG_32, offset: 0x80, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  uint8_t RESERVED_0[32];
  __IO uint32_t REG_41;                            /**< TRGMUX REG_41, offset: 0xA4, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_42;                            /**< TRGMUX REG_42, offset: 0xA8, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_43;                            /**< TRGMUX REG_43, offset: 0xAC, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
  __IO uint32_t REG_44;                            /**< TRGMUX REG_44, offset: 0xB0, available only on: TRGMUX_0 (missing on LPE_TRGMUX, TRGMUX_1) */
} TRGMUX_Type, *TRGMUX_MemMapPtr;

/** Number of instances of the TRGMUX module. */
#define TRGMUX_INSTANCE_COUNT                    (3u)

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral LPE_TRGMUX base address */
#define IP_LPE_TRGMUX_BASE                       (0x42084000u)
/** Peripheral LPE_TRGMUX base pointer */
#define IP_LPE_TRGMUX                            ((TRGMUX_Type *)IP_LPE_TRGMUX_BASE)
/** Peripheral TRGMUX_0 base address */
#define IP_TRGMUX_0_BASE                         (0x40600000u)
/** Peripheral TRGMUX_0 base pointer */
#define IP_TRGMUX_0                              ((TRGMUX_Type *)IP_TRGMUX_0_BASE)
/** Peripheral TRGMUX_1 base address */
#define IP_TRGMUX_1_BASE                         (0x40690000u)
/** Peripheral TRGMUX_1 base pointer */
#define IP_TRGMUX_1                              ((TRGMUX_Type *)IP_TRGMUX_1_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define IP_TRGMUX_BASE_ADDRS                     { IP_LPE_TRGMUX_BASE, IP_TRGMUX_0_BASE, IP_TRGMUX_1_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define IP_TRGMUX_BASE_PTRS                      { IP_LPE_TRGMUX, IP_TRGMUX_0, IP_TRGMUX_1 }

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name REG_0 - TRGMUX REG_0 */
/*! @{ */

#define TRGMUX_REG_0_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_0_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_0_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_0_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_0_SEL0_SHIFT)) & TRGMUX_REG_0_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_0_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_0_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_0_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_0_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_0_SEL1_SHIFT)) & TRGMUX_REG_0_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_0_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_0_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_0_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_0_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_0_SEL2_SHIFT)) & TRGMUX_REG_0_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_0_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_0_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_0_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_0_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_0_SEL3_SHIFT)) & TRGMUX_REG_0_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_1 - TRGMUX REG_1 */
/*! @{ */

#define TRGMUX_REG_1_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_1_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_1_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_1_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_1_SEL0_SHIFT)) & TRGMUX_REG_1_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_1_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_1_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_1_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_1_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_1_SEL1_SHIFT)) & TRGMUX_REG_1_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_1_SEL2_MASK                   (0x7F0000U)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
#define TRGMUX_REG_1_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_1_SEL2_WIDTH                  (7U)
#define TRGMUX_REG_1_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_1_SEL2_SHIFT)) & TRGMUX_REG_1_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */

#define TRGMUX_REG_1_SEL3_MASK                   (0x7F000000U)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
#define TRGMUX_REG_1_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_1_SEL3_WIDTH                  (7U)
#define TRGMUX_REG_1_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_1_SEL3_SHIFT)) & TRGMUX_REG_1_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
/*! @} */

/*! @name REG_2 - TRGMUX REG_2 */
/*! @{ */

#define TRGMUX_REG_2_SEL0_MASK                   (0x7FU)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
#define TRGMUX_REG_2_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_2_SEL0_WIDTH                  (7U)
#define TRGMUX_REG_2_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_2_SEL0_SHIFT)) & TRGMUX_REG_2_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */

#define TRGMUX_REG_2_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_2_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_2_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_2_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_2_SEL1_SHIFT)) & TRGMUX_REG_2_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_2_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_2_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_2_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_2_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_2_SEL2_SHIFT)) & TRGMUX_REG_2_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_2_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_2_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_2_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_2_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_2_SEL3_SHIFT)) & TRGMUX_REG_2_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_3 - TRGMUX REG_3 */
/*! @{ */

#define TRGMUX_REG_3_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_3_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_3_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_3_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_3_SEL0_SHIFT)) & TRGMUX_REG_3_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_3_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_3_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_3_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_3_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_3_SEL1_SHIFT)) & TRGMUX_REG_3_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_3_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_3_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_3_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_3_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_3_SEL2_SHIFT)) & TRGMUX_REG_3_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_3_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_3_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_3_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_3_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_3_SEL3_SHIFT)) & TRGMUX_REG_3_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_4 - TRGMUX REG_4 */
/*! @{ */

#define TRGMUX_REG_4_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_4_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_4_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_4_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_4_SEL0_SHIFT)) & TRGMUX_REG_4_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_4_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_4_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_4_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_4_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_4_SEL1_SHIFT)) & TRGMUX_REG_4_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_4_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_4_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_4_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_4_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_4_SEL2_SHIFT)) & TRGMUX_REG_4_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_4_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_4_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_4_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_4_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_4_SEL3_SHIFT)) & TRGMUX_REG_4_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_5 - TRGMUX REG_5 */
/*! @{ */

#define TRGMUX_REG_5_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_5_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_5_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_5_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_5_SEL0_SHIFT)) & TRGMUX_REG_5_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_5_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_5_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_5_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_5_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_5_SEL1_SHIFT)) & TRGMUX_REG_5_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_5_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_5_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_5_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_5_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_5_SEL2_SHIFT)) & TRGMUX_REG_5_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_5_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_5_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_5_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_5_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_5_SEL3_SHIFT)) & TRGMUX_REG_5_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_6 - TRGMUX REG_6 */
/*! @{ */

#define TRGMUX_REG_6_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_6_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_6_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_6_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_6_SEL0_SHIFT)) & TRGMUX_REG_6_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_6_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_6_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_6_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_6_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_6_SEL1_SHIFT)) & TRGMUX_REG_6_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_6_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_6_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_6_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_6_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_6_SEL2_SHIFT)) & TRGMUX_REG_6_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_6_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_6_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_6_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_6_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_6_SEL3_SHIFT)) & TRGMUX_REG_6_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_7 - TRGMUX REG_7 */
/*! @{ */

#define TRGMUX_REG_7_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_7_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_7_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_7_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_7_SEL0_SHIFT)) & TRGMUX_REG_7_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_7_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_7_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_7_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_7_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_7_SEL1_SHIFT)) & TRGMUX_REG_7_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_7_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_7_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_7_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_7_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_7_SEL2_SHIFT)) & TRGMUX_REG_7_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_7_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_7_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_7_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_7_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_7_SEL3_SHIFT)) & TRGMUX_REG_7_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_8 - TRGMUX REG_8 */
/*! @{ */

#define TRGMUX_REG_8_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_8_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_8_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_8_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_8_SEL0_SHIFT)) & TRGMUX_REG_8_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_8_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_8_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_8_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_8_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_8_SEL1_SHIFT)) & TRGMUX_REG_8_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_8_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_8_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_8_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_8_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_8_SEL2_SHIFT)) & TRGMUX_REG_8_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_8_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_8_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_8_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_8_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_8_SEL3_SHIFT)) & TRGMUX_REG_8_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_9 - TRGMUX REG_9 */
/*! @{ */

#define TRGMUX_REG_9_SEL0_MASK                   (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_9_SEL0_SHIFT                  (0U)
#define TRGMUX_REG_9_SEL0_WIDTH                  (8U)
#define TRGMUX_REG_9_SEL0(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_9_SEL0_SHIFT)) & TRGMUX_REG_9_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_9_SEL1_MASK                   (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_9_SEL1_SHIFT                  (8U)
#define TRGMUX_REG_9_SEL1_WIDTH                  (8U)
#define TRGMUX_REG_9_SEL1(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_9_SEL1_SHIFT)) & TRGMUX_REG_9_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_9_SEL2_MASK                   (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_9_SEL2_SHIFT                  (16U)
#define TRGMUX_REG_9_SEL2_WIDTH                  (8U)
#define TRGMUX_REG_9_SEL2(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_9_SEL2_SHIFT)) & TRGMUX_REG_9_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_9_SEL3_MASK                   (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_9_SEL3_SHIFT                  (24U)
#define TRGMUX_REG_9_SEL3_WIDTH                  (8U)
#define TRGMUX_REG_9_SEL3(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_9_SEL3_SHIFT)) & TRGMUX_REG_9_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_10 - TRGMUX REG_10 */
/*! @{ */

#define TRGMUX_REG_10_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_10_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_10_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_10_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_10_SEL0_SHIFT)) & TRGMUX_REG_10_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_10_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_10_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_10_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_10_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_10_SEL1_SHIFT)) & TRGMUX_REG_10_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_10_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_10_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_10_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_10_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_10_SEL2_SHIFT)) & TRGMUX_REG_10_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_10_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_10_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_10_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_10_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_10_SEL3_SHIFT)) & TRGMUX_REG_10_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_11 - TRGMUX REG_11 */
/*! @{ */

#define TRGMUX_REG_11_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_11_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_11_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_11_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_11_SEL0_SHIFT)) & TRGMUX_REG_11_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_11_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_11_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_11_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_11_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_11_SEL1_SHIFT)) & TRGMUX_REG_11_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_11_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_11_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_11_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_11_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_11_SEL2_SHIFT)) & TRGMUX_REG_11_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_11_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_11_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_11_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_11_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_11_SEL3_SHIFT)) & TRGMUX_REG_11_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_12 - TRGMUX REG_12 */
/*! @{ */

#define TRGMUX_REG_12_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_12_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_12_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_12_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_12_SEL0_SHIFT)) & TRGMUX_REG_12_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_12_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_12_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_12_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_12_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_12_SEL1_SHIFT)) & TRGMUX_REG_12_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_12_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_12_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_12_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_12_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_12_SEL2_SHIFT)) & TRGMUX_REG_12_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_12_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_12_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_12_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_12_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_12_SEL3_SHIFT)) & TRGMUX_REG_12_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_13 - TRGMUX REG_13 */
/*! @{ */

#define TRGMUX_REG_13_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_13_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_13_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_13_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_13_SEL0_SHIFT)) & TRGMUX_REG_13_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_13_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_13_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_13_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_13_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_13_SEL1_SHIFT)) & TRGMUX_REG_13_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_13_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_13_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_13_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_13_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_13_SEL2_SHIFT)) & TRGMUX_REG_13_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_13_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_13_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_13_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_13_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_13_SEL3_SHIFT)) & TRGMUX_REG_13_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_14 - TRGMUX REG_14 */
/*! @{ */

#define TRGMUX_REG_14_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_14_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_14_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_14_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_14_SEL0_SHIFT)) & TRGMUX_REG_14_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_14_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_14_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_14_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_14_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_14_SEL1_SHIFT)) & TRGMUX_REG_14_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_14_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_14_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_14_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_14_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_14_SEL2_SHIFT)) & TRGMUX_REG_14_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_14_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_14_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_14_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_14_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_14_SEL3_SHIFT)) & TRGMUX_REG_14_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
/*! @} */

/*! @name REG_15 - TRGMUX REG_15 */
/*! @{ */

#define TRGMUX_REG_15_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */
#define TRGMUX_REG_15_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_15_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_15_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_15_SEL0_SHIFT)) & TRGMUX_REG_15_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7, 8), largest definition used */

#define TRGMUX_REG_15_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_15_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_15_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_15_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_15_SEL1_SHIFT)) & TRGMUX_REG_15_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_15_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_15_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_15_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_15_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_15_SEL2_SHIFT)) & TRGMUX_REG_15_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_15_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_15_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_15_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_15_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_15_SEL3_SHIFT)) & TRGMUX_REG_15_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_16 - TRGMUX REG_16 */
/*! @{ */

#define TRGMUX_REG_16_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_16_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_16_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_16_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_16_SEL0_SHIFT)) & TRGMUX_REG_16_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_16_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_16_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_16_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_16_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_16_SEL1_SHIFT)) & TRGMUX_REG_16_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_16_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_16_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_16_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_16_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_16_SEL2_SHIFT)) & TRGMUX_REG_16_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_16_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_16_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_16_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_16_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_16_SEL3_SHIFT)) & TRGMUX_REG_16_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_17 - TRGMUX REG_17 */
/*! @{ */

#define TRGMUX_REG_17_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_17_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_17_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_17_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_17_SEL0_SHIFT)) & TRGMUX_REG_17_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_17_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_17_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_17_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_17_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_17_SEL1_SHIFT)) & TRGMUX_REG_17_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_17_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_17_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_17_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_17_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_17_SEL2_SHIFT)) & TRGMUX_REG_17_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_17_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_17_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_17_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_17_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_17_SEL3_SHIFT)) & TRGMUX_REG_17_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_18 - TRGMUX REG_18 */
/*! @{ */

#define TRGMUX_REG_18_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_18_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_18_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_18_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_18_SEL0_SHIFT)) & TRGMUX_REG_18_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_18_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_18_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_18_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_18_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_18_SEL1_SHIFT)) & TRGMUX_REG_18_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_18_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_18_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_18_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_18_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_18_SEL2_SHIFT)) & TRGMUX_REG_18_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_18_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_18_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_18_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_18_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_18_SEL3_SHIFT)) & TRGMUX_REG_18_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_19 - TRGMUX REG_19 */
/*! @{ */

#define TRGMUX_REG_19_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_19_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_19_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_19_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_19_SEL0_SHIFT)) & TRGMUX_REG_19_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_19_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_19_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_19_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_19_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_19_SEL1_SHIFT)) & TRGMUX_REG_19_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_19_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_19_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_19_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_19_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_19_SEL2_SHIFT)) & TRGMUX_REG_19_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_19_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_19_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_19_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_19_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_19_SEL3_SHIFT)) & TRGMUX_REG_19_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_20 - TRGMUX REG_20 */
/*! @{ */

#define TRGMUX_REG_20_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_20_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_20_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_20_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_20_SEL0_SHIFT)) & TRGMUX_REG_20_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_20_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_20_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_20_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_20_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_20_SEL1_SHIFT)) & TRGMUX_REG_20_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_20_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_20_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_20_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_20_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_20_SEL2_SHIFT)) & TRGMUX_REG_20_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_20_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_20_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_20_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_20_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_20_SEL3_SHIFT)) & TRGMUX_REG_20_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_21 - TRGMUX REG_21 */
/*! @{ */

#define TRGMUX_REG_21_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_21_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_21_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_21_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_21_SEL0_SHIFT)) & TRGMUX_REG_21_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_21_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_21_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_21_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_21_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_21_SEL1_SHIFT)) & TRGMUX_REG_21_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_21_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_21_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_21_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_21_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_21_SEL2_SHIFT)) & TRGMUX_REG_21_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_21_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_21_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_21_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_21_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_21_SEL3_SHIFT)) & TRGMUX_REG_21_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_22 - TRGMUX REG_22 */
/*! @{ */

#define TRGMUX_REG_22_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_22_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_22_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_22_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_22_SEL0_SHIFT)) & TRGMUX_REG_22_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_22_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_22_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_22_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_22_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_22_SEL1_SHIFT)) & TRGMUX_REG_22_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_22_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_22_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_22_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_22_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_22_SEL2_SHIFT)) & TRGMUX_REG_22_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_22_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_22_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_22_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_22_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_22_SEL3_SHIFT)) & TRGMUX_REG_22_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_23 - TRGMUX REG_23 */
/*! @{ */

#define TRGMUX_REG_23_SEL0_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_23_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_23_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_23_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_23_SEL0_SHIFT)) & TRGMUX_REG_23_SEL0_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_23_SEL1_MASK                  (0xFF00U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_23_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_23_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_23_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_23_SEL1_SHIFT)) & TRGMUX_REG_23_SEL1_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_23_SEL2_MASK                  (0xFF0000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_23_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_23_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_23_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_23_SEL2_SHIFT)) & TRGMUX_REG_23_SEL2_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */

#define TRGMUX_REG_23_SEL3_MASK                  (0xFF000000U)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
#define TRGMUX_REG_23_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_23_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_23_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_23_SEL3_SHIFT)) & TRGMUX_REG_23_SEL3_MASK)  /* Merged from fields with different position or width, of widths (7, 8), largest definition used */
/*! @} */

/*! @name REG_24 - TRGMUX REG_24 */
/*! @{ */

#define TRGMUX_REG_24_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_24_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_24_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_24_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_24_SEL0_SHIFT)) & TRGMUX_REG_24_SEL0_MASK)

#define TRGMUX_REG_24_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_24_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_24_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_24_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_24_SEL1_SHIFT)) & TRGMUX_REG_24_SEL1_MASK)

#define TRGMUX_REG_24_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_24_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_24_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_24_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_24_SEL2_SHIFT)) & TRGMUX_REG_24_SEL2_MASK)

#define TRGMUX_REG_24_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_24_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_24_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_24_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_24_SEL3_SHIFT)) & TRGMUX_REG_24_SEL3_MASK)
/*! @} */

/*! @name REG_25 - TRGMUX REG_25 */
/*! @{ */

#define TRGMUX_REG_25_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_25_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_25_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_25_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_25_SEL0_SHIFT)) & TRGMUX_REG_25_SEL0_MASK)

#define TRGMUX_REG_25_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_25_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_25_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_25_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_25_SEL1_SHIFT)) & TRGMUX_REG_25_SEL1_MASK)

#define TRGMUX_REG_25_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_25_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_25_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_25_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_25_SEL2_SHIFT)) & TRGMUX_REG_25_SEL2_MASK)

#define TRGMUX_REG_25_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_25_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_25_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_25_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_25_SEL3_SHIFT)) & TRGMUX_REG_25_SEL3_MASK)
/*! @} */

/*! @name REG_26 - TRGMUX REG_26 */
/*! @{ */

#define TRGMUX_REG_26_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_26_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_26_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_26_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_26_SEL0_SHIFT)) & TRGMUX_REG_26_SEL0_MASK)

#define TRGMUX_REG_26_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_26_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_26_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_26_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_26_SEL1_SHIFT)) & TRGMUX_REG_26_SEL1_MASK)

#define TRGMUX_REG_26_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_26_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_26_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_26_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_26_SEL2_SHIFT)) & TRGMUX_REG_26_SEL2_MASK)

#define TRGMUX_REG_26_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_26_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_26_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_26_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_26_SEL3_SHIFT)) & TRGMUX_REG_26_SEL3_MASK)
/*! @} */

/*! @name REG_27 - TRGMUX REG_27 */
/*! @{ */

#define TRGMUX_REG_27_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_27_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_27_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_27_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_27_SEL0_SHIFT)) & TRGMUX_REG_27_SEL0_MASK)

#define TRGMUX_REG_27_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_27_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_27_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_27_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_27_SEL1_SHIFT)) & TRGMUX_REG_27_SEL1_MASK)

#define TRGMUX_REG_27_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_27_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_27_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_27_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_27_SEL2_SHIFT)) & TRGMUX_REG_27_SEL2_MASK)

#define TRGMUX_REG_27_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_27_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_27_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_27_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_27_SEL3_SHIFT)) & TRGMUX_REG_27_SEL3_MASK)
/*! @} */

/*! @name REG_28 - TRGMUX REG_28 */
/*! @{ */

#define TRGMUX_REG_28_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_28_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_28_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_28_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_28_SEL0_SHIFT)) & TRGMUX_REG_28_SEL0_MASK)

#define TRGMUX_REG_28_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_28_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_28_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_28_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_28_SEL1_SHIFT)) & TRGMUX_REG_28_SEL1_MASK)

#define TRGMUX_REG_28_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_28_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_28_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_28_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_28_SEL2_SHIFT)) & TRGMUX_REG_28_SEL2_MASK)

#define TRGMUX_REG_28_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_28_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_28_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_28_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_28_SEL3_SHIFT)) & TRGMUX_REG_28_SEL3_MASK)
/*! @} */

/*! @name REG_29 - TRGMUX REG_29 */
/*! @{ */

#define TRGMUX_REG_29_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_29_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_29_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_29_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_29_SEL0_SHIFT)) & TRGMUX_REG_29_SEL0_MASK)

#define TRGMUX_REG_29_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_29_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_29_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_29_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_29_SEL1_SHIFT)) & TRGMUX_REG_29_SEL1_MASK)

#define TRGMUX_REG_29_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_29_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_29_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_29_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_29_SEL2_SHIFT)) & TRGMUX_REG_29_SEL2_MASK)

#define TRGMUX_REG_29_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_29_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_29_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_29_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_29_SEL3_SHIFT)) & TRGMUX_REG_29_SEL3_MASK)
/*! @} */

/*! @name REG_30 - TRGMUX REG_30 */
/*! @{ */

#define TRGMUX_REG_30_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_30_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_30_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_30_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_30_SEL0_SHIFT)) & TRGMUX_REG_30_SEL0_MASK)

#define TRGMUX_REG_30_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_30_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_30_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_30_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_30_SEL1_SHIFT)) & TRGMUX_REG_30_SEL1_MASK)

#define TRGMUX_REG_30_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_30_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_30_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_30_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_30_SEL2_SHIFT)) & TRGMUX_REG_30_SEL2_MASK)

#define TRGMUX_REG_30_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_30_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_30_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_30_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_30_SEL3_SHIFT)) & TRGMUX_REG_30_SEL3_MASK)
/*! @} */

/*! @name REG_31 - TRGMUX REG_31 */
/*! @{ */

#define TRGMUX_REG_31_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_31_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_31_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_31_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_31_SEL0_SHIFT)) & TRGMUX_REG_31_SEL0_MASK)

#define TRGMUX_REG_31_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_31_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_31_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_31_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_31_SEL1_SHIFT)) & TRGMUX_REG_31_SEL1_MASK)

#define TRGMUX_REG_31_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_31_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_31_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_31_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_31_SEL2_SHIFT)) & TRGMUX_REG_31_SEL2_MASK)

#define TRGMUX_REG_31_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_31_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_31_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_31_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_31_SEL3_SHIFT)) & TRGMUX_REG_31_SEL3_MASK)
/*! @} */

/*! @name REG_32 - TRGMUX REG_32 */
/*! @{ */

#define TRGMUX_REG_32_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_32_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_32_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_32_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_32_SEL0_SHIFT)) & TRGMUX_REG_32_SEL0_MASK)

#define TRGMUX_REG_32_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_32_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_32_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_32_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_32_SEL1_SHIFT)) & TRGMUX_REG_32_SEL1_MASK)

#define TRGMUX_REG_32_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_32_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_32_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_32_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_32_SEL2_SHIFT)) & TRGMUX_REG_32_SEL2_MASK)
/*! @} */

/*! @name REG_41 - TRGMUX REG_41 */
/*! @{ */

#define TRGMUX_REG_41_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_41_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_41_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_41_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_41_SEL0_SHIFT)) & TRGMUX_REG_41_SEL0_MASK)

#define TRGMUX_REG_41_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_41_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_41_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_41_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_41_SEL1_SHIFT)) & TRGMUX_REG_41_SEL1_MASK)

#define TRGMUX_REG_41_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_41_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_41_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_41_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_41_SEL2_SHIFT)) & TRGMUX_REG_41_SEL2_MASK)

#define TRGMUX_REG_41_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_41_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_41_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_41_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_41_SEL3_SHIFT)) & TRGMUX_REG_41_SEL3_MASK)
/*! @} */

/*! @name REG_42 - TRGMUX REG_42 */
/*! @{ */

#define TRGMUX_REG_42_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_42_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_42_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_42_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_42_SEL0_SHIFT)) & TRGMUX_REG_42_SEL0_MASK)

#define TRGMUX_REG_42_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_42_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_42_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_42_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_42_SEL1_SHIFT)) & TRGMUX_REG_42_SEL1_MASK)

#define TRGMUX_REG_42_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_42_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_42_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_42_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_42_SEL2_SHIFT)) & TRGMUX_REG_42_SEL2_MASK)

#define TRGMUX_REG_42_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_42_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_42_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_42_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_42_SEL3_SHIFT)) & TRGMUX_REG_42_SEL3_MASK)
/*! @} */

/*! @name REG_43 - TRGMUX REG_43 */
/*! @{ */

#define TRGMUX_REG_43_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_43_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_43_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_43_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_43_SEL0_SHIFT)) & TRGMUX_REG_43_SEL0_MASK)

#define TRGMUX_REG_43_SEL1_MASK                  (0xFF00U)
#define TRGMUX_REG_43_SEL1_SHIFT                 (8U)
#define TRGMUX_REG_43_SEL1_WIDTH                 (8U)
#define TRGMUX_REG_43_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_43_SEL1_SHIFT)) & TRGMUX_REG_43_SEL1_MASK)

#define TRGMUX_REG_43_SEL2_MASK                  (0xFF0000U)
#define TRGMUX_REG_43_SEL2_SHIFT                 (16U)
#define TRGMUX_REG_43_SEL2_WIDTH                 (8U)
#define TRGMUX_REG_43_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_43_SEL2_SHIFT)) & TRGMUX_REG_43_SEL2_MASK)

#define TRGMUX_REG_43_SEL3_MASK                  (0xFF000000U)
#define TRGMUX_REG_43_SEL3_SHIFT                 (24U)
#define TRGMUX_REG_43_SEL3_WIDTH                 (8U)
#define TRGMUX_REG_43_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_43_SEL3_SHIFT)) & TRGMUX_REG_43_SEL3_MASK)
/*! @} */

/*! @name REG_44 - TRGMUX REG_44 */
/*! @{ */

#define TRGMUX_REG_44_SEL0_MASK                  (0xFFU)
#define TRGMUX_REG_44_SEL0_SHIFT                 (0U)
#define TRGMUX_REG_44_SEL0_WIDTH                 (8U)
#define TRGMUX_REG_44_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG_44_SEL0_SHIFT)) & TRGMUX_REG_44_SEL0_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */

/*!
 * @}
 */ /* end of group TRGMUX_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_TRGMUX_H_) */
