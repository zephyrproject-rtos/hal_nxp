/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K358_VIRT_WRAPPER.h
 * @version 1.1
 * @date 2022-10-01
 * @brief Peripheral Access Layer for S32K358_VIRT_WRAPPER
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
#if !defined(S32K358_VIRT_WRAPPER_H_)  /* Check if memory map has not been already included */
#define S32K358_VIRT_WRAPPER_H_

#include "S32K358_COMMON.h"

/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Peripheral_Access_Layer VIRT_WRAPPER Peripheral Access Layer
 * @{
 */

/** VIRT_WRAPPER - Size of Registers Arrays */
#define VIRT_WRAPPER_REG_C_COUNT                  1u

/** VIRT_WRAPPER - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG_A0;                            /**< Parameter_n Register, offset: 0x0 */
  __IO uint32_t REG_A1;                            /**< Parameter_n Register, offset: 0x4 */
  __IO uint32_t REG_A2;                            /**< Parameter_n Register, offset: 0x8 */
  __IO uint32_t REG_A3;                            /**< Parameter_n Register, offset: 0xC */
  __IO uint32_t REG_A4;                            /**< Parameter_n Register, offset: 0x10 */
  __IO uint32_t REG_A5;                            /**< Parameter_n Register, offset: 0x14 */
  __IO uint32_t REG_A6;                            /**< Parameter_n Register, offset: 0x18 */
  __IO uint32_t REG_A7;                            /**< Parameter_n Register, offset: 0x1C */
  __IO uint32_t REG_A8;                            /**< Parameter_n Register, offset: 0x20 */
  __IO uint32_t REG_A9;                            /**< Parameter_n Register, offset: 0x24 */
  __IO uint32_t REG_A10;                           /**< Parameter_n Register, offset: 0x28 */
  __IO uint32_t REG_A11;                           /**< Parameter_n Register, offset: 0x2C */
  __IO uint32_t REG_A12;                           /**< Parameter_n Register, offset: 0x30 */
  __IO uint32_t REG_A13;                           /**< Parameter_n Register, offset: 0x34 */
  __IO uint32_t REG_A14;                           /**< Parameter_n Register, offset: 0x38 */
  uint8_t RESERVED_0[68];
  __IO uint32_t REG_B0;                            /**< Parameter_n Register, offset: 0x80 */
  __IO uint32_t REG_B1;                            /**< Parameter_n Register, offset: 0x84 */
  __IO uint32_t REG_B2;                            /**< Parameter_n Register, offset: 0x88 */
  __IO uint32_t REG_B3;                            /**< Parameter_n Register, offset: 0x8C */
  __IO uint32_t REG_B4;                            /**< Parameter_n Register, offset: 0x90 */
  __IO uint32_t REG_B5;                            /**< Parameter_n Register, offset: 0x94 */
  __IO uint32_t REG_B6;                            /**< Parameter_n Register, offset: 0x98 */
  __IO uint32_t REG_B7;                            /**< Parameter_n Register, offset: 0x9C */
  __IO uint32_t REG_B8;                            /**< Parameter_n Register, offset: 0xA0 */
  __IO uint32_t REG_B9;                            /**< Parameter_n Register, offset: 0xA4 */
  __IO uint32_t REG_B10;                           /**< Parameter_n Register, offset: 0xA8 */
  __IO uint32_t REG_B11;                           /**< Parameter_n Register, offset: 0xAC */
  __IO uint32_t REG_B12;                           /**< Parameter_n Register, offset: 0xB0 */
  __IO uint32_t REG_B13;                           /**< Parameter_n Register, offset: 0xB4 */
  __IO uint32_t REG_B14;                           /**< Parameter_n Register, offset: 0xB8 */
  __IO uint32_t REG_B15;                           /**< Parameter_n Register, offset: 0xBC */
  __IO uint32_t REG_B16;                           /**< Parameter_n Register, offset: 0xC0 */
  uint8_t RESERVED_1[4];
  __IO uint32_t REG_B18;                           /**< Parameter_n Register, offset: 0xC8 */
  __IO uint32_t REG_B19;                           /**< Parameter_n Register, offset: 0xCC */
  __IO uint32_t REG_B20;                           /**< Parameter_n Register, offset: 0xD0 */
  __IO uint32_t REG_B21;                           /**< Parameter_n Register, offset: 0xD4 */
  __IO uint32_t REG_B22;                           /**< Parameter_n Register, offset: 0xD8 */
  __IO uint32_t REG_B23;                           /**< Parameter_n Register, offset: 0xDC */
  __IO uint32_t REG_B24;                           /**< Parameter_n Register, offset: 0xE0 */
  __IO uint32_t REG_B25;                           /**< Parameter_n Register, offset: 0xE4 */
  __IO uint32_t REG_B26;                           /**< Parameter_n Register, offset: 0xE8 */
  __IO uint32_t REG_B27;                           /**< Parameter_n Register, offset: 0xEC */
  uint8_t RESERVED_2[16];
  __IO uint32_t REG_C[VIRT_WRAPPER_REG_C_COUNT];   /**< Parameter_n Register, array offset: 0x100, array step: 0x4 */
} VIRT_WRAPPER_Type, *VIRT_WRAPPER_MemMapPtr;

/** Number of instances of the VIRT_WRAPPER module. */
#define VIRT_WRAPPER_INSTANCE_COUNT              (1u)

/* VIRT_WRAPPER - Peripheral instance base addresses */
/** Peripheral VIRT_WRAPPER base address */
#define IP_VIRT_WRAPPER_BASE                     (0x402A8000u)
/** Peripheral VIRT_WRAPPER base pointer */
#define IP_VIRT_WRAPPER                          ((VIRT_WRAPPER_Type *)IP_VIRT_WRAPPER_BASE)
/** Array initializer of VIRT_WRAPPER peripheral base addresses */
#define IP_VIRT_WRAPPER_BASE_ADDRS               { IP_VIRT_WRAPPER_BASE }
/** Array initializer of VIRT_WRAPPER peripheral base pointers */
#define IP_VIRT_WRAPPER_BASE_PTRS                { IP_VIRT_WRAPPER }

/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Register_Masks VIRT_WRAPPER Register Masks
 * @{
 */

/*! @name REG_A0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A0_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A0_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A0_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A0_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A0_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A0_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A0_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A0_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A0_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A0_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A0_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A0_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A0_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A0_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A0_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A0_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A0_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A0_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A0_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A0_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A0_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A0_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A0_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A0_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A0_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A0_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A0_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A0_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A0_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A0_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A0_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A0_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A0_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A0_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A0_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A0_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A0_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A0_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A0_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_15_MASK)
/*! @} */

/*! @name REG_A1 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A1_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A1_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A1_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A1_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A1_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A1_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A1_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A1_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A1_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A1_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A1_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A1_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A1_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A1_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A1_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A1_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A1_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A1_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A1_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A1_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A1_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A1_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A1_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A1_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A1_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A1_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A1_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A1_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A1_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A1_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A1_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A1_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A1_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A1_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A1_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A1_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A1_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A1_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A1_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_15_MASK)
/*! @} */

/*! @name REG_A2 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A2_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A2_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A2_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A2_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A2_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A2_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A2_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A2_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A2_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A2_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A2_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A2_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A2_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A2_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A2_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A2_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A2_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A2_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A2_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A2_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A2_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A2_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A2_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A2_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A2_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A2_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A2_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A2_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A2_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A2_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A2_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A2_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A2_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A2_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A2_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_15_MASK)
/*! @} */

/*! @name REG_A3 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A3_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A3_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A3_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A3_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A3_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A3_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A3_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A3_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A3_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A3_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A3_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A3_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A3_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A3_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A3_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A3_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A3_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A3_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A3_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A3_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A3_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A3_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A3_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A3_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A3_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A3_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A3_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A3_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A3_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A3_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A3_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A3_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A3_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A3_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A3_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A3_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A3_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A3_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A3_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_15_MASK)
/*! @} */

/*! @name REG_A4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A4_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A4_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A4_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A4_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A4_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A4_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A4_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A4_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A4_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A4_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A4_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A4_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A4_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A4_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A4_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A4_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A4_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A4_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A4_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A4_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A4_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A4_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A4_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A4_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A4_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A4_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A4_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A4_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A4_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A4_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A4_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A4_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A4_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A4_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A4_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A4_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A4_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A4_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A4_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_15_MASK)
/*! @} */

/*! @name REG_A5 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A5_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A5_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A5_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A5_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A5_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A5_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A5_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A5_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A5_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A5_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A5_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A5_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A5_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A5_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A5_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A5_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A5_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A5_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A5_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A5_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A5_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A5_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A5_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A5_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A5_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A5_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A5_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A5_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A5_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A5_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A5_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A5_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A5_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A5_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A5_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A5_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A5_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A5_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A5_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_15_MASK)
/*! @} */

/*! @name REG_A6 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A6_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A6_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A6_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A6_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A6_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A6_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A6_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A6_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A6_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A6_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A6_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A6_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A6_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A6_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A6_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A6_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A6_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A6_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A6_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A6_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A6_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A6_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A6_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A6_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A6_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A6_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A6_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A6_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A6_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A6_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A6_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A6_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A6_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A6_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A6_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A6_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A6_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A6_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A6_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_15_MASK)
/*! @} */

/*! @name REG_A7 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A7_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A7_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A7_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A7_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A7_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A7_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A7_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A7_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A7_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A7_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A7_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A7_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A7_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A7_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A7_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A7_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A7_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A7_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A7_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A7_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A7_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A7_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A7_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A7_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A7_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A7_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A7_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A7_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A7_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A7_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A7_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A7_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A7_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A7_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A7_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A7_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A7_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A7_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A7_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_15_MASK)
/*! @} */

/*! @name REG_A8 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A8_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A8_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A8_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A8_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A8_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A8_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A8_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A8_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A8_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A8_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A8_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A8_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A8_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A8_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A8_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A8_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A8_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A8_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A8_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A8_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A8_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A8_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A8_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A8_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A8_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A8_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A8_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A8_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A8_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A8_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A8_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A8_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A8_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A8_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A8_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A8_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A8_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A8_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A8_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_15_MASK)
/*! @} */

/*! @name REG_A9 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A9_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A9_PAD_0_SHIFT          (0U)
#define VIRT_WRAPPER_REG_A9_PAD_0_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A9_PAD_1_SHIFT          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_1_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A9_PAD_2_SHIFT          (4U)
#define VIRT_WRAPPER_REG_A9_PAD_2_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A9_PAD_3_SHIFT          (6U)
#define VIRT_WRAPPER_REG_A9_PAD_3_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A9_PAD_4_SHIFT          (8U)
#define VIRT_WRAPPER_REG_A9_PAD_4_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A9_PAD_5_SHIFT          (10U)
#define VIRT_WRAPPER_REG_A9_PAD_5_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A9_PAD_6_SHIFT          (12U)
#define VIRT_WRAPPER_REG_A9_PAD_6_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A9_PAD_7_SHIFT          (14U)
#define VIRT_WRAPPER_REG_A9_PAD_7_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A9_PAD_8_SHIFT          (16U)
#define VIRT_WRAPPER_REG_A9_PAD_8_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A9_PAD_9_SHIFT          (18U)
#define VIRT_WRAPPER_REG_A9_PAD_9_WIDTH          (2U)
#define VIRT_WRAPPER_REG_A9_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A9_PAD_10_SHIFT         (20U)
#define VIRT_WRAPPER_REG_A9_PAD_10_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A9_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A9_PAD_11_SHIFT         (22U)
#define VIRT_WRAPPER_REG_A9_PAD_11_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A9_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A9_PAD_12_SHIFT         (24U)
#define VIRT_WRAPPER_REG_A9_PAD_12_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A9_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A9_PAD_13_SHIFT         (26U)
#define VIRT_WRAPPER_REG_A9_PAD_13_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A9_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A9_PAD_14_SHIFT         (28U)
#define VIRT_WRAPPER_REG_A9_PAD_14_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A9_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A9_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A9_PAD_15_SHIFT         (30U)
#define VIRT_WRAPPER_REG_A9_PAD_15_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A9_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_15_MASK)
/*! @} */

/*! @name REG_A10 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A10_PAD_0_MASK          (0x3U)
#define VIRT_WRAPPER_REG_A10_PAD_0_SHIFT         (0U)
#define VIRT_WRAPPER_REG_A10_PAD_0_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_1_MASK          (0xCU)
#define VIRT_WRAPPER_REG_A10_PAD_1_SHIFT         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_1_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_2_MASK          (0x30U)
#define VIRT_WRAPPER_REG_A10_PAD_2_SHIFT         (4U)
#define VIRT_WRAPPER_REG_A10_PAD_2_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_3_MASK          (0xC0U)
#define VIRT_WRAPPER_REG_A10_PAD_3_SHIFT         (6U)
#define VIRT_WRAPPER_REG_A10_PAD_3_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_4_MASK          (0x300U)
#define VIRT_WRAPPER_REG_A10_PAD_4_SHIFT         (8U)
#define VIRT_WRAPPER_REG_A10_PAD_4_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_4(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_5_MASK          (0xC00U)
#define VIRT_WRAPPER_REG_A10_PAD_5_SHIFT         (10U)
#define VIRT_WRAPPER_REG_A10_PAD_5_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_5(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_6_MASK          (0x3000U)
#define VIRT_WRAPPER_REG_A10_PAD_6_SHIFT         (12U)
#define VIRT_WRAPPER_REG_A10_PAD_6_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_6(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_7_MASK          (0xC000U)
#define VIRT_WRAPPER_REG_A10_PAD_7_SHIFT         (14U)
#define VIRT_WRAPPER_REG_A10_PAD_7_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_7(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_8_MASK          (0x30000U)
#define VIRT_WRAPPER_REG_A10_PAD_8_SHIFT         (16U)
#define VIRT_WRAPPER_REG_A10_PAD_8_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_8(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_9_MASK          (0xC0000U)
#define VIRT_WRAPPER_REG_A10_PAD_9_SHIFT         (18U)
#define VIRT_WRAPPER_REG_A10_PAD_9_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A10_PAD_9(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_10_MASK         (0x300000U)
#define VIRT_WRAPPER_REG_A10_PAD_10_SHIFT        (20U)
#define VIRT_WRAPPER_REG_A10_PAD_10_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A10_PAD_10(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_11_MASK         (0xC00000U)
#define VIRT_WRAPPER_REG_A10_PAD_11_SHIFT        (22U)
#define VIRT_WRAPPER_REG_A10_PAD_11_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A10_PAD_11(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_12_MASK         (0x3000000U)
#define VIRT_WRAPPER_REG_A10_PAD_12_SHIFT        (24U)
#define VIRT_WRAPPER_REG_A10_PAD_12_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A10_PAD_12(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_13_MASK         (0xC000000U)
#define VIRT_WRAPPER_REG_A10_PAD_13_SHIFT        (26U)
#define VIRT_WRAPPER_REG_A10_PAD_13_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A10_PAD_13(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_14_MASK         (0x30000000U)
#define VIRT_WRAPPER_REG_A10_PAD_14_SHIFT        (28U)
#define VIRT_WRAPPER_REG_A10_PAD_14_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A10_PAD_14(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A10_PAD_15_MASK         (0xC0000000U)
#define VIRT_WRAPPER_REG_A10_PAD_15_SHIFT        (30U)
#define VIRT_WRAPPER_REG_A10_PAD_15_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A10_PAD_15(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A10_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A10_PAD_15_MASK)
/*! @} */

/*! @name REG_A11 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A11_PAD_0_MASK          (0x3U)
#define VIRT_WRAPPER_REG_A11_PAD_0_SHIFT         (0U)
#define VIRT_WRAPPER_REG_A11_PAD_0_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_1_MASK          (0xCU)
#define VIRT_WRAPPER_REG_A11_PAD_1_SHIFT         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_1_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_2_MASK          (0x30U)
#define VIRT_WRAPPER_REG_A11_PAD_2_SHIFT         (4U)
#define VIRT_WRAPPER_REG_A11_PAD_2_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_3_MASK          (0xC0U)
#define VIRT_WRAPPER_REG_A11_PAD_3_SHIFT         (6U)
#define VIRT_WRAPPER_REG_A11_PAD_3_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_4_MASK          (0x300U)
#define VIRT_WRAPPER_REG_A11_PAD_4_SHIFT         (8U)
#define VIRT_WRAPPER_REG_A11_PAD_4_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_4(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_5_MASK          (0xC00U)
#define VIRT_WRAPPER_REG_A11_PAD_5_SHIFT         (10U)
#define VIRT_WRAPPER_REG_A11_PAD_5_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_5(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_6_MASK          (0x3000U)
#define VIRT_WRAPPER_REG_A11_PAD_6_SHIFT         (12U)
#define VIRT_WRAPPER_REG_A11_PAD_6_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_6(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_7_MASK          (0xC000U)
#define VIRT_WRAPPER_REG_A11_PAD_7_SHIFT         (14U)
#define VIRT_WRAPPER_REG_A11_PAD_7_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_7(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_8_MASK          (0x30000U)
#define VIRT_WRAPPER_REG_A11_PAD_8_SHIFT         (16U)
#define VIRT_WRAPPER_REG_A11_PAD_8_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_8(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_9_MASK          (0xC0000U)
#define VIRT_WRAPPER_REG_A11_PAD_9_SHIFT         (18U)
#define VIRT_WRAPPER_REG_A11_PAD_9_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A11_PAD_9(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_10_MASK         (0x300000U)
#define VIRT_WRAPPER_REG_A11_PAD_10_SHIFT        (20U)
#define VIRT_WRAPPER_REG_A11_PAD_10_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A11_PAD_10(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_11_MASK         (0xC00000U)
#define VIRT_WRAPPER_REG_A11_PAD_11_SHIFT        (22U)
#define VIRT_WRAPPER_REG_A11_PAD_11_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A11_PAD_11(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_12_MASK         (0x3000000U)
#define VIRT_WRAPPER_REG_A11_PAD_12_SHIFT        (24U)
#define VIRT_WRAPPER_REG_A11_PAD_12_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A11_PAD_12(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_13_MASK         (0xC000000U)
#define VIRT_WRAPPER_REG_A11_PAD_13_SHIFT        (26U)
#define VIRT_WRAPPER_REG_A11_PAD_13_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A11_PAD_13(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_14_MASK         (0x30000000U)
#define VIRT_WRAPPER_REG_A11_PAD_14_SHIFT        (28U)
#define VIRT_WRAPPER_REG_A11_PAD_14_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A11_PAD_14(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A11_PAD_15_MASK         (0xC0000000U)
#define VIRT_WRAPPER_REG_A11_PAD_15_SHIFT        (30U)
#define VIRT_WRAPPER_REG_A11_PAD_15_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A11_PAD_15(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A11_PAD_15_MASK)
/*! @} */

/*! @name REG_A12 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A12_PAD_0_MASK          (0x3U)
#define VIRT_WRAPPER_REG_A12_PAD_0_SHIFT         (0U)
#define VIRT_WRAPPER_REG_A12_PAD_0_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_1_MASK          (0xCU)
#define VIRT_WRAPPER_REG_A12_PAD_1_SHIFT         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_1_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_2_MASK          (0x30U)
#define VIRT_WRAPPER_REG_A12_PAD_2_SHIFT         (4U)
#define VIRT_WRAPPER_REG_A12_PAD_2_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_3_MASK          (0xC0U)
#define VIRT_WRAPPER_REG_A12_PAD_3_SHIFT         (6U)
#define VIRT_WRAPPER_REG_A12_PAD_3_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_4_MASK          (0x300U)
#define VIRT_WRAPPER_REG_A12_PAD_4_SHIFT         (8U)
#define VIRT_WRAPPER_REG_A12_PAD_4_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_4(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_5_MASK          (0xC00U)
#define VIRT_WRAPPER_REG_A12_PAD_5_SHIFT         (10U)
#define VIRT_WRAPPER_REG_A12_PAD_5_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_5(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_6_MASK          (0x3000U)
#define VIRT_WRAPPER_REG_A12_PAD_6_SHIFT         (12U)
#define VIRT_WRAPPER_REG_A12_PAD_6_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_6(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_7_MASK          (0xC000U)
#define VIRT_WRAPPER_REG_A12_PAD_7_SHIFT         (14U)
#define VIRT_WRAPPER_REG_A12_PAD_7_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_7(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_8_MASK          (0x30000U)
#define VIRT_WRAPPER_REG_A12_PAD_8_SHIFT         (16U)
#define VIRT_WRAPPER_REG_A12_PAD_8_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_8(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_9_MASK          (0xC0000U)
#define VIRT_WRAPPER_REG_A12_PAD_9_SHIFT         (18U)
#define VIRT_WRAPPER_REG_A12_PAD_9_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A12_PAD_9(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_10_MASK         (0x300000U)
#define VIRT_WRAPPER_REG_A12_PAD_10_SHIFT        (20U)
#define VIRT_WRAPPER_REG_A12_PAD_10_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A12_PAD_10(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_11_MASK         (0xC00000U)
#define VIRT_WRAPPER_REG_A12_PAD_11_SHIFT        (22U)
#define VIRT_WRAPPER_REG_A12_PAD_11_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A12_PAD_11(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_12_MASK         (0x3000000U)
#define VIRT_WRAPPER_REG_A12_PAD_12_SHIFT        (24U)
#define VIRT_WRAPPER_REG_A12_PAD_12_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A12_PAD_12(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_13_MASK         (0xC000000U)
#define VIRT_WRAPPER_REG_A12_PAD_13_SHIFT        (26U)
#define VIRT_WRAPPER_REG_A12_PAD_13_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A12_PAD_13(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_14_MASK         (0x30000000U)
#define VIRT_WRAPPER_REG_A12_PAD_14_SHIFT        (28U)
#define VIRT_WRAPPER_REG_A12_PAD_14_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A12_PAD_14(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A12_PAD_15_MASK         (0xC0000000U)
#define VIRT_WRAPPER_REG_A12_PAD_15_SHIFT        (30U)
#define VIRT_WRAPPER_REG_A12_PAD_15_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A12_PAD_15(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A12_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A12_PAD_15_MASK)
/*! @} */

/*! @name REG_A13 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A13_PAD_0_MASK          (0x3U)
#define VIRT_WRAPPER_REG_A13_PAD_0_SHIFT         (0U)
#define VIRT_WRAPPER_REG_A13_PAD_0_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_1_MASK          (0xCU)
#define VIRT_WRAPPER_REG_A13_PAD_1_SHIFT         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_1_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_2_MASK          (0x30U)
#define VIRT_WRAPPER_REG_A13_PAD_2_SHIFT         (4U)
#define VIRT_WRAPPER_REG_A13_PAD_2_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_3_MASK          (0xC0U)
#define VIRT_WRAPPER_REG_A13_PAD_3_SHIFT         (6U)
#define VIRT_WRAPPER_REG_A13_PAD_3_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_4_MASK          (0x300U)
#define VIRT_WRAPPER_REG_A13_PAD_4_SHIFT         (8U)
#define VIRT_WRAPPER_REG_A13_PAD_4_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_4(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_5_MASK          (0xC00U)
#define VIRT_WRAPPER_REG_A13_PAD_5_SHIFT         (10U)
#define VIRT_WRAPPER_REG_A13_PAD_5_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_5(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_6_MASK          (0x3000U)
#define VIRT_WRAPPER_REG_A13_PAD_6_SHIFT         (12U)
#define VIRT_WRAPPER_REG_A13_PAD_6_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_6(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_7_MASK          (0xC000U)
#define VIRT_WRAPPER_REG_A13_PAD_7_SHIFT         (14U)
#define VIRT_WRAPPER_REG_A13_PAD_7_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_7(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_8_MASK          (0x30000U)
#define VIRT_WRAPPER_REG_A13_PAD_8_SHIFT         (16U)
#define VIRT_WRAPPER_REG_A13_PAD_8_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_8(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_9_MASK          (0xC0000U)
#define VIRT_WRAPPER_REG_A13_PAD_9_SHIFT         (18U)
#define VIRT_WRAPPER_REG_A13_PAD_9_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A13_PAD_9(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_10_MASK         (0x300000U)
#define VIRT_WRAPPER_REG_A13_PAD_10_SHIFT        (20U)
#define VIRT_WRAPPER_REG_A13_PAD_10_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A13_PAD_10(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_11_MASK         (0xC00000U)
#define VIRT_WRAPPER_REG_A13_PAD_11_SHIFT        (22U)
#define VIRT_WRAPPER_REG_A13_PAD_11_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A13_PAD_11(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_12_MASK         (0x3000000U)
#define VIRT_WRAPPER_REG_A13_PAD_12_SHIFT        (24U)
#define VIRT_WRAPPER_REG_A13_PAD_12_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A13_PAD_12(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_13_MASK         (0xC000000U)
#define VIRT_WRAPPER_REG_A13_PAD_13_SHIFT        (26U)
#define VIRT_WRAPPER_REG_A13_PAD_13_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A13_PAD_13(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_14_MASK         (0x30000000U)
#define VIRT_WRAPPER_REG_A13_PAD_14_SHIFT        (28U)
#define VIRT_WRAPPER_REG_A13_PAD_14_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A13_PAD_14(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A13_PAD_15_MASK         (0xC0000000U)
#define VIRT_WRAPPER_REG_A13_PAD_15_SHIFT        (30U)
#define VIRT_WRAPPER_REG_A13_PAD_15_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A13_PAD_15(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A13_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A13_PAD_15_MASK)
/*! @} */

/*! @name REG_A14 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A14_PAD_0_MASK          (0x3U)
#define VIRT_WRAPPER_REG_A14_PAD_0_SHIFT         (0U)
#define VIRT_WRAPPER_REG_A14_PAD_0_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_1_MASK          (0xCU)
#define VIRT_WRAPPER_REG_A14_PAD_1_SHIFT         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_1_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_2_MASK          (0x30U)
#define VIRT_WRAPPER_REG_A14_PAD_2_SHIFT         (4U)
#define VIRT_WRAPPER_REG_A14_PAD_2_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_3_MASK          (0xC0U)
#define VIRT_WRAPPER_REG_A14_PAD_3_SHIFT         (6U)
#define VIRT_WRAPPER_REG_A14_PAD_3_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_4_MASK          (0x300U)
#define VIRT_WRAPPER_REG_A14_PAD_4_SHIFT         (8U)
#define VIRT_WRAPPER_REG_A14_PAD_4_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_4(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_5_MASK          (0xC00U)
#define VIRT_WRAPPER_REG_A14_PAD_5_SHIFT         (10U)
#define VIRT_WRAPPER_REG_A14_PAD_5_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_5(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_6_MASK          (0x3000U)
#define VIRT_WRAPPER_REG_A14_PAD_6_SHIFT         (12U)
#define VIRT_WRAPPER_REG_A14_PAD_6_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_6(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_7_MASK          (0xC000U)
#define VIRT_WRAPPER_REG_A14_PAD_7_SHIFT         (14U)
#define VIRT_WRAPPER_REG_A14_PAD_7_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_7(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_8_MASK          (0x30000U)
#define VIRT_WRAPPER_REG_A14_PAD_8_SHIFT         (16U)
#define VIRT_WRAPPER_REG_A14_PAD_8_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_8(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_9_MASK          (0xC0000U)
#define VIRT_WRAPPER_REG_A14_PAD_9_SHIFT         (18U)
#define VIRT_WRAPPER_REG_A14_PAD_9_WIDTH         (2U)
#define VIRT_WRAPPER_REG_A14_PAD_9(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_10_MASK         (0x300000U)
#define VIRT_WRAPPER_REG_A14_PAD_10_SHIFT        (20U)
#define VIRT_WRAPPER_REG_A14_PAD_10_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A14_PAD_10(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_11_MASK         (0xC00000U)
#define VIRT_WRAPPER_REG_A14_PAD_11_SHIFT        (22U)
#define VIRT_WRAPPER_REG_A14_PAD_11_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A14_PAD_11(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A14_PAD_12_MASK         (0x3000000U)
#define VIRT_WRAPPER_REG_A14_PAD_12_SHIFT        (24U)
#define VIRT_WRAPPER_REG_A14_PAD_12_WIDTH        (2U)
#define VIRT_WRAPPER_REG_A14_PAD_12(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A14_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A14_PAD_12_MASK)
/*! @} */

/*! @name REG_B0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B0_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B0_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B0_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B0_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B0_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B0_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B0_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B0_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B0_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B0_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B0_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B0_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B0_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B0_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B0_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B0_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B0_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B0_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B0_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B0_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B0_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B0_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B0_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B0_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_5_MASK)
/*! @} */

/*! @name REG_B1 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B1_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B1_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B1_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B1_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B1_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B1_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B1_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B1_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B1_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B1_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B1_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B1_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B1_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B1_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B1_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B1_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B1_INMUX_8_SHIFT        (16U)
#define VIRT_WRAPPER_REG_B1_INMUX_8_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B1_INMUX_9_SHIFT        (18U)
#define VIRT_WRAPPER_REG_B1_INMUX_9_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B1_INMUX_10_SHIFT       (20U)
#define VIRT_WRAPPER_REG_B1_INMUX_10_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B1_INMUX_11_SHIFT       (22U)
#define VIRT_WRAPPER_REG_B1_INMUX_11_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_12_SHIFT       (24U)
#define VIRT_WRAPPER_REG_B1_INMUX_12_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_13_SHIFT       (26U)
#define VIRT_WRAPPER_REG_B1_INMUX_13_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_14_SHIFT       (28U)
#define VIRT_WRAPPER_REG_B1_INMUX_14_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_15_SHIFT       (30U)
#define VIRT_WRAPPER_REG_B1_INMUX_15_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B1_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_15_MASK)
/*! @} */

/*! @name REG_B2 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B2_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B2_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B2_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B2_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B2_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B2_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B2_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B2_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B2_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B2_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B2_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B2_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B2_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B2_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B2_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B2_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B2_INMUX_8_SHIFT        (16U)
#define VIRT_WRAPPER_REG_B2_INMUX_8_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B2_INMUX_9_SHIFT        (18U)
#define VIRT_WRAPPER_REG_B2_INMUX_9_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B2_INMUX_10_SHIFT       (20U)
#define VIRT_WRAPPER_REG_B2_INMUX_10_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B2_INMUX_11_SHIFT       (22U)
#define VIRT_WRAPPER_REG_B2_INMUX_11_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_12_SHIFT       (24U)
#define VIRT_WRAPPER_REG_B2_INMUX_12_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_13_SHIFT       (26U)
#define VIRT_WRAPPER_REG_B2_INMUX_13_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_14_SHIFT       (28U)
#define VIRT_WRAPPER_REG_B2_INMUX_14_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_15_SHIFT       (30U)
#define VIRT_WRAPPER_REG_B2_INMUX_15_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B2_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_15_MASK)
/*! @} */

/*! @name REG_B3 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B3_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B3_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B3_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B3_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B3_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B3_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B3_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B3_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B3_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B3_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B3_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B3_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B3_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B3_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B3_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B3_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B3_INMUX_8_SHIFT        (16U)
#define VIRT_WRAPPER_REG_B3_INMUX_8_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B3_INMUX_9_SHIFT        (18U)
#define VIRT_WRAPPER_REG_B3_INMUX_9_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B3_INMUX_10_SHIFT       (20U)
#define VIRT_WRAPPER_REG_B3_INMUX_10_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B3_INMUX_11_SHIFT       (22U)
#define VIRT_WRAPPER_REG_B3_INMUX_11_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_12_SHIFT       (24U)
#define VIRT_WRAPPER_REG_B3_INMUX_12_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_13_SHIFT       (26U)
#define VIRT_WRAPPER_REG_B3_INMUX_13_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_14_SHIFT       (28U)
#define VIRT_WRAPPER_REG_B3_INMUX_14_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_15_SHIFT       (30U)
#define VIRT_WRAPPER_REG_B3_INMUX_15_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B3_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_15_MASK)
/*! @} */

/*! @name REG_B4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B4_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B4_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B4_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B4_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B4_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B4_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B4_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B4_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B4_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B4_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B4_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B4_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B4_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B4_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B4_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B4_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B4_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_7_MASK)
/*! @} */

/*! @name REG_B5 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B5_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B5_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B5_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B5_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B5_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B5_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B5_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B5_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B5_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B5_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B5_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B5_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B5_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B5_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B5_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B5_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B5_INMUX_8_SHIFT        (16U)
#define VIRT_WRAPPER_REG_B5_INMUX_8_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B5_INMUX_9_SHIFT        (18U)
#define VIRT_WRAPPER_REG_B5_INMUX_9_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B5_INMUX_10_SHIFT       (20U)
#define VIRT_WRAPPER_REG_B5_INMUX_10_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B5_INMUX_11_SHIFT       (22U)
#define VIRT_WRAPPER_REG_B5_INMUX_11_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_12_SHIFT       (24U)
#define VIRT_WRAPPER_REG_B5_INMUX_12_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_13_SHIFT       (26U)
#define VIRT_WRAPPER_REG_B5_INMUX_13_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_14_SHIFT       (28U)
#define VIRT_WRAPPER_REG_B5_INMUX_14_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_15_SHIFT       (30U)
#define VIRT_WRAPPER_REG_B5_INMUX_15_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B5_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_15_MASK)
/*! @} */

/*! @name REG_B6 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B6_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B6_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B6_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B6_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B6_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B6_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B6_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B6_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B6_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B6_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B6_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B6_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B6_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B6_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B6_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B6_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B6_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_7_MASK)
/*! @} */

/*! @name REG_B7 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B7_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B7_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B7_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B7_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B7_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B7_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B7_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B7_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B7_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B7_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B7_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B7_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B7_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B7_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B7_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B7_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B7_INMUX_8_SHIFT        (16U)
#define VIRT_WRAPPER_REG_B7_INMUX_8_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B7_INMUX_9_SHIFT        (18U)
#define VIRT_WRAPPER_REG_B7_INMUX_9_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B7_INMUX_10_SHIFT       (20U)
#define VIRT_WRAPPER_REG_B7_INMUX_10_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B7_INMUX_11_SHIFT       (22U)
#define VIRT_WRAPPER_REG_B7_INMUX_11_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B7_INMUX_12_SHIFT       (24U)
#define VIRT_WRAPPER_REG_B7_INMUX_12_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B7_INMUX_13_SHIFT       (26U)
#define VIRT_WRAPPER_REG_B7_INMUX_13_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B7_INMUX_14_SHIFT       (28U)
#define VIRT_WRAPPER_REG_B7_INMUX_14_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B7_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B7_INMUX_15_SHIFT       (30U)
#define VIRT_WRAPPER_REG_B7_INMUX_15_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B7_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B7_INMUX_15_MASK)
/*! @} */

/*! @name REG_B8 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B8_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B8_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B8_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B8_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B8_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B8_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B8_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B8_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B8_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B8_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B8_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B8_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B8_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B8_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B8_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B8_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B8_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B8_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B8_INMUX_6_SHIFT        (12U)
#define VIRT_WRAPPER_REG_B8_INMUX_6_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B8_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B8_INMUX_7_SHIFT        (14U)
#define VIRT_WRAPPER_REG_B8_INMUX_7_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B8_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B8_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B8_INMUX_7_MASK)
/*! @} */

/*! @name REG_B9 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B9_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B9_INMUX_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_B9_INMUX_0_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B9_INMUX_1_SHIFT        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_1_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B9_INMUX_2_SHIFT        (4U)
#define VIRT_WRAPPER_REG_B9_INMUX_2_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B9_INMUX_3_SHIFT        (6U)
#define VIRT_WRAPPER_REG_B9_INMUX_3_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B9_INMUX_4_SHIFT        (8U)
#define VIRT_WRAPPER_REG_B9_INMUX_4_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B9_INMUX_5_SHIFT        (10U)
#define VIRT_WRAPPER_REG_B9_INMUX_5_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B9_INMUX_8_SHIFT        (16U)
#define VIRT_WRAPPER_REG_B9_INMUX_8_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B9_INMUX_9_SHIFT        (18U)
#define VIRT_WRAPPER_REG_B9_INMUX_9_WIDTH        (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B9_INMUX_10_SHIFT       (20U)
#define VIRT_WRAPPER_REG_B9_INMUX_10_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B9_INMUX_11_SHIFT       (22U)
#define VIRT_WRAPPER_REG_B9_INMUX_11_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_12_SHIFT       (24U)
#define VIRT_WRAPPER_REG_B9_INMUX_12_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_13_SHIFT       (26U)
#define VIRT_WRAPPER_REG_B9_INMUX_13_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_14_SHIFT       (28U)
#define VIRT_WRAPPER_REG_B9_INMUX_14_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_15_SHIFT       (30U)
#define VIRT_WRAPPER_REG_B9_INMUX_15_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B9_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_15_MASK)
/*! @} */

/*! @name REG_B10 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B10_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B10_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B10_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B10_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B10_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B10_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B10_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B10_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B10_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B10_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B10_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B10_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B10_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B10_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B10_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B10_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B10_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B10_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B10_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B10_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B10_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B10_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B10_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B10_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B10_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B10_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B10_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B10_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B10_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B10_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B10_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B10_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B10_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_15_MASK)
/*! @} */

/*! @name REG_B11 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B11_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B11_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B11_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B11_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B11_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B11_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B11_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B11_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B11_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B11_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B11_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B11_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B11_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B11_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B11_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B11_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B11_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B11_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B11_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B11_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B11_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B11_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B11_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B11_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B11_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B11_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B11_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B11_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B11_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B11_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B11_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B11_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B11_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_15_MASK)
/*! @} */

/*! @name REG_B12 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B12_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B12_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B12_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B12_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B12_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B12_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B12_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B12_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B12_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B12_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B12_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B12_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B12_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B12_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B12_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B12_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B12_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B12_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B12_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B12_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B12_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B12_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B12_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B12_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B12_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B12_INMUX_10_MASK)
/*! @} */

/*! @name REG_B13 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B13_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B13_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B13_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B13_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B13_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B13_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B13_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B13_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B13_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B13_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B13_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B13_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B13_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B13_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B13_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B13_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B13_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B13_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B13_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B13_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B13_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B13_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B13_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B13_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_15_MASK)
/*! @} */

/*! @name REG_B14 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B14_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B14_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B14_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B14_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B14_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B14_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B14_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B14_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B14_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B14_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B14_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B14_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B14_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B14_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B14_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B14_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B14_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B14_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B14_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B14_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B14_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B14_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B14_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B14_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B14_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B14_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B14_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B14_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B14_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_15_MASK)
/*! @} */

/*! @name REG_B15 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B15_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B15_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B15_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B15_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B15_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B15_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B15_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B15_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B15_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B15_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B15_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B15_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B15_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B15_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B15_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B15_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B15_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B15_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B15_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B15_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B15_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B15_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B15_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B15_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B15_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B15_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B15_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B15_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B15_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B15_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B15_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B15_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B15_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_15_MASK)
/*! @} */

/*! @name REG_B16 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B16_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B16_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B16_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B16_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B16_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B16_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B16_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B16_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B16_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B16_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B16_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B16_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B16_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B16_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B16_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B16_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B16_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B16_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B16_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B16_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B16_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B16_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B16_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B16_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B16_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B16_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B16_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B16_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B16_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B16_INMUX_12_MASK)
/*! @} */

/*! @name REG_B18 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B18_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B18_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B18_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B18_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B18_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B18_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B18_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B18_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B18_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B18_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B18_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B18_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B18_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B18_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B18_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B18_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B18_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B18_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B18_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B18_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B18_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B18_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B18_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B18_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B18_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B18_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B18_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B18_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B18_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B18_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B18_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B18_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B18_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B18_INMUX_15_MASK)
/*! @} */

/*! @name REG_B19 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B19_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B19_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B19_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B19_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B19_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B19_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B19_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B19_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B19_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B19_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B19_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B19_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B19_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B19_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B19_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B19_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B19_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B19_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B19_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B19_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B19_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B19_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B19_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B19_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B19_INMUX_15_MASK)
/*! @} */

/*! @name REG_B20 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B20_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B20_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B20_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B20_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B20_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B20_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B20_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B20_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B20_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B20_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B20_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B20_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B20_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B20_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B20_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B20_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B20_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B20_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B20_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B20_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B20_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B20_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B20_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B20_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B20_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B20_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B20_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B20_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B20_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B20_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B20_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B20_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B20_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B20_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B20_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B20_INMUX_5_MASK)
/*! @} */

/*! @name REG_B21 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B21_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B21_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B21_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B21_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B21_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B21_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B21_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B21_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B21_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B21_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B21_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B21_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B21_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B21_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B21_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B21_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_15_MASK)
/*! @} */

/*! @name REG_B22 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B22_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B22_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B22_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B22_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B22_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B22_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B22_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B22_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B22_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B22_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B22_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B22_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B22_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B22_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B22_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B22_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B22_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B22_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B22_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B22_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B22_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B22_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B22_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B22_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B22_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B22_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B22_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B22_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B22_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B22_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B22_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B22_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B22_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_15_MASK)
/*! @} */

/*! @name REG_B23 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B23_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B23_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B23_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B23_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B23_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B23_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B23_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B23_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B23_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B23_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B23_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B23_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B23_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B23_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B23_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B23_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B23_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B23_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B23_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B23_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B23_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B23_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B23_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_10_MASK)
/*! @} */

/*! @name REG_B24 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B24_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B24_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B24_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B24_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B24_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B24_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B24_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B24_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B24_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B24_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B24_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B24_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B24_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B24_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B24_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B24_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B24_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B24_INMUX_15_MASK)
/*! @} */

/*! @name REG_B25 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B25_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B25_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B25_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B25_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B25_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B25_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B25_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B25_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B25_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B25_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B25_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B25_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B25_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B25_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B25_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B25_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B25_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B25_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B25_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B25_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B25_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B25_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B25_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B25_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B25_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B25_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B25_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B25_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B25_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B25_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B25_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B25_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B25_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B25_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B25_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B25_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B25_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B25_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B25_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B25_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B25_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B25_INMUX_15_MASK)
/*! @} */

/*! @name REG_B26 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B26_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B26_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B26_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B26_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B26_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B26_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B26_INMUX_3_SHIFT       (6U)
#define VIRT_WRAPPER_REG_B26_INMUX_3_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B26_INMUX_4_SHIFT       (8U)
#define VIRT_WRAPPER_REG_B26_INMUX_4_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B26_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B26_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B26_INMUX_6_SHIFT       (12U)
#define VIRT_WRAPPER_REG_B26_INMUX_6_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B26_INMUX_7_SHIFT       (14U)
#define VIRT_WRAPPER_REG_B26_INMUX_7_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B26_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B26_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B26_INMUX_9_SHIFT       (18U)
#define VIRT_WRAPPER_REG_B26_INMUX_9_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B26_INMUX_10_SHIFT      (20U)
#define VIRT_WRAPPER_REG_B26_INMUX_10_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B26_INMUX_11_SHIFT      (22U)
#define VIRT_WRAPPER_REG_B26_INMUX_11_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B26_INMUX_12_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B26_INMUX_12_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B26_INMUX_13_SHIFT      (26U)
#define VIRT_WRAPPER_REG_B26_INMUX_13_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B26_INMUX_14_SHIFT      (28U)
#define VIRT_WRAPPER_REG_B26_INMUX_14_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B26_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B26_INMUX_15_SHIFT      (30U)
#define VIRT_WRAPPER_REG_B26_INMUX_15_WIDTH      (2U)
#define VIRT_WRAPPER_REG_B26_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B26_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B26_INMUX_15_MASK)
/*! @} */

/*! @name REG_B27 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B27_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B27_INMUX_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_B27_INMUX_0_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B27_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B27_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B27_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B27_INMUX_1_SHIFT       (2U)
#define VIRT_WRAPPER_REG_B27_INMUX_1_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B27_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B27_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B27_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B27_INMUX_2_SHIFT       (4U)
#define VIRT_WRAPPER_REG_B27_INMUX_2_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B27_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B27_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B27_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B27_INMUX_5_SHIFT       (10U)
#define VIRT_WRAPPER_REG_B27_INMUX_5_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B27_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B27_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B27_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B27_INMUX_8_SHIFT       (16U)
#define VIRT_WRAPPER_REG_B27_INMUX_8_WIDTH       (2U)
#define VIRT_WRAPPER_REG_B27_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B27_INMUX_8_MASK)
/*! @} */

/*! @name REG_C - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_C_INTC_CTRL_MASK        (0x3U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT       (0U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL_WIDTH       (2U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT)) & VIRT_WRAPPER_REG_C_INTC_CTRL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Register_Masks */

/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K358_VIRT_WRAPPER_H_) */
