/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_TRGMUX_2.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_TRGMUX_2
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
#if !defined(S32Z2_TRGMUX_2_H_)  /* Check if memory map has not been already included */
#define S32Z2_TRGMUX_2_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TRGMUX_2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_2_Peripheral_Access_Layer TRGMUX_2 Peripheral Access Layer
 * @{
 */

/** TRGMUX_2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t TIM0_1_0;                          /**< TRGMUX TIM0_1_0, offset: 0x0 */
  __IO uint32_t TIM0_3_2;                          /**< TRGMUX TIM0_3_2, offset: 0x4 */
  __IO uint32_t TIM0_5_4;                          /**< TRGMUX TIM0_5_4, offset: 0x8 */
  __IO uint32_t TIM0_7_6;                          /**< TRGMUX TIM0_7_6, offset: 0xC */
  __IO uint32_t TIM1_1_0;                          /**< TRGMUX TIM1_1_0, offset: 0x10 */
  __IO uint32_t TIM1_3_2;                          /**< TRGMUX TIM1_3_2, offset: 0x14 */
  __IO uint32_t TIM1_5_4;                          /**< TRGMUX TIM1_5_4, offset: 0x18 */
  __IO uint32_t TIM1_7_6;                          /**< TRGMUX TIM1_7_6, offset: 0x1C */
  __IO uint32_t TIM2_1_0;                          /**< TRGMUX TIM2_1_0, offset: 0x20 */
  __IO uint32_t TIM2_3_2;                          /**< TRGMUX TIM2_3_2, offset: 0x24 */
  __IO uint32_t TIM2_5_4;                          /**< TRGMUX TIM2_5_4, offset: 0x28 */
  __IO uint32_t TIM2_7_6;                          /**< TRGMUX TIM2_7_6, offset: 0x2C */
  __IO uint32_t TIO1_1_0;                          /**< TRGMUX TIO1_1_0, offset: 0x30 */
  __IO uint32_t TIO1_3_2;                          /**< TRGMUX TIO1_3_2, offset: 0x34 */
  __IO uint32_t TIO1_5_4;                          /**< TRGMUX TIO1_5_4, offset: 0x38 */
  __IO uint32_t TIO1_7_6;                          /**< TRGMUX TIO1_7_6, offset: 0x3C */
  __IO uint32_t TIO2_1_0;                          /**< TRGMUX TIO2_1_0, offset: 0x40 */
  __IO uint32_t TIO2_3_2;                          /**< TRGMUX TIO2_3_2, offset: 0x44 */
  __IO uint32_t TIO2_5_4;                          /**< TRGMUX TIO2_5_4, offset: 0x48 */
  __IO uint32_t TIO2_7_6;                          /**< TRGMUX TIO2_7_6, offset: 0x4C */
  __IO uint32_t TIO3_1_0;                          /**< TRGMUX TIO3_1_0, offset: 0x50 */
  __IO uint32_t TIO3_3_2;                          /**< TRGMUX TIO3_3_2, offset: 0x54 */
  __IO uint32_t TIO3_5_4;                          /**< TRGMUX TIO3_5_4, offset: 0x58 */
  __IO uint32_t TIO3_7_6;                          /**< TRGMUX TIO3_7_6, offset: 0x5C */
} TRGMUX_2_Type, *TRGMUX_2_MemMapPtr;

/** Number of instances of the TRGMUX_2 module. */
#define TRGMUX_2_INSTANCE_COUNT                  (1u)

/* TRGMUX_2 - Peripheral instance base addresses */
/** Peripheral TRGMUX_2 base address */
#define IP_TRGMUX_2_BASE                         (0x40370000u)
/** Peripheral TRGMUX_2 base pointer */
#define IP_TRGMUX_2                              ((TRGMUX_2_Type *)IP_TRGMUX_2_BASE)
/** Array initializer of TRGMUX_2 peripheral base addresses */
#define IP_TRGMUX_2_BASE_ADDRS                   { IP_TRGMUX_2_BASE }
/** Array initializer of TRGMUX_2 peripheral base pointers */
#define IP_TRGMUX_2_BASE_PTRS                    { IP_TRGMUX_2 }

/* ----------------------------------------------------------------------------
   -- TRGMUX_2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_2_Register_Masks TRGMUX_2 Register Masks
 * @{
 */

/*! @name TIM0_1_0 - TRGMUX TIM0_1_0 */
/*! @{ */

#define TRGMUX_2_TIM0_1_0_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM0_1_0_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM0_1_0_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM0_1_0_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_1_0_SEL0_SHIFT)) & TRGMUX_2_TIM0_1_0_SEL0_MASK)

#define TRGMUX_2_TIM0_1_0_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM0_1_0_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM0_1_0_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM0_1_0_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_1_0_SEL1_SHIFT)) & TRGMUX_2_TIM0_1_0_SEL1_MASK)

#define TRGMUX_2_TIM0_1_0_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM0_1_0_LK_SHIFT               (31U)
#define TRGMUX_2_TIM0_1_0_LK_WIDTH               (1U)
#define TRGMUX_2_TIM0_1_0_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_1_0_LK_SHIFT)) & TRGMUX_2_TIM0_1_0_LK_MASK)
/*! @} */

/*! @name TIM0_3_2 - TRGMUX TIM0_3_2 */
/*! @{ */

#define TRGMUX_2_TIM0_3_2_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM0_3_2_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM0_3_2_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM0_3_2_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_3_2_SEL0_SHIFT)) & TRGMUX_2_TIM0_3_2_SEL0_MASK)

#define TRGMUX_2_TIM0_3_2_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM0_3_2_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM0_3_2_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM0_3_2_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_3_2_SEL1_SHIFT)) & TRGMUX_2_TIM0_3_2_SEL1_MASK)

#define TRGMUX_2_TIM0_3_2_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM0_3_2_LK_SHIFT               (31U)
#define TRGMUX_2_TIM0_3_2_LK_WIDTH               (1U)
#define TRGMUX_2_TIM0_3_2_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_3_2_LK_SHIFT)) & TRGMUX_2_TIM0_3_2_LK_MASK)
/*! @} */

/*! @name TIM0_5_4 - TRGMUX TIM0_5_4 */
/*! @{ */

#define TRGMUX_2_TIM0_5_4_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM0_5_4_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM0_5_4_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM0_5_4_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_5_4_SEL0_SHIFT)) & TRGMUX_2_TIM0_5_4_SEL0_MASK)

#define TRGMUX_2_TIM0_5_4_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM0_5_4_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM0_5_4_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM0_5_4_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_5_4_SEL1_SHIFT)) & TRGMUX_2_TIM0_5_4_SEL1_MASK)

#define TRGMUX_2_TIM0_5_4_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM0_5_4_LK_SHIFT               (31U)
#define TRGMUX_2_TIM0_5_4_LK_WIDTH               (1U)
#define TRGMUX_2_TIM0_5_4_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_5_4_LK_SHIFT)) & TRGMUX_2_TIM0_5_4_LK_MASK)
/*! @} */

/*! @name TIM0_7_6 - TRGMUX TIM0_7_6 */
/*! @{ */

#define TRGMUX_2_TIM0_7_6_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM0_7_6_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM0_7_6_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM0_7_6_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_7_6_SEL0_SHIFT)) & TRGMUX_2_TIM0_7_6_SEL0_MASK)

#define TRGMUX_2_TIM0_7_6_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM0_7_6_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM0_7_6_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM0_7_6_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_7_6_SEL1_SHIFT)) & TRGMUX_2_TIM0_7_6_SEL1_MASK)

#define TRGMUX_2_TIM0_7_6_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM0_7_6_LK_SHIFT               (31U)
#define TRGMUX_2_TIM0_7_6_LK_WIDTH               (1U)
#define TRGMUX_2_TIM0_7_6_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM0_7_6_LK_SHIFT)) & TRGMUX_2_TIM0_7_6_LK_MASK)
/*! @} */

/*! @name TIM1_1_0 - TRGMUX TIM1_1_0 */
/*! @{ */

#define TRGMUX_2_TIM1_1_0_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM1_1_0_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM1_1_0_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM1_1_0_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_1_0_SEL0_SHIFT)) & TRGMUX_2_TIM1_1_0_SEL0_MASK)

#define TRGMUX_2_TIM1_1_0_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM1_1_0_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM1_1_0_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM1_1_0_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_1_0_SEL1_SHIFT)) & TRGMUX_2_TIM1_1_0_SEL1_MASK)

#define TRGMUX_2_TIM1_1_0_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM1_1_0_LK_SHIFT               (31U)
#define TRGMUX_2_TIM1_1_0_LK_WIDTH               (1U)
#define TRGMUX_2_TIM1_1_0_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_1_0_LK_SHIFT)) & TRGMUX_2_TIM1_1_0_LK_MASK)
/*! @} */

/*! @name TIM1_3_2 - TRGMUX TIM1_3_2 */
/*! @{ */

#define TRGMUX_2_TIM1_3_2_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM1_3_2_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM1_3_2_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM1_3_2_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_3_2_SEL0_SHIFT)) & TRGMUX_2_TIM1_3_2_SEL0_MASK)

#define TRGMUX_2_TIM1_3_2_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM1_3_2_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM1_3_2_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM1_3_2_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_3_2_SEL1_SHIFT)) & TRGMUX_2_TIM1_3_2_SEL1_MASK)

#define TRGMUX_2_TIM1_3_2_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM1_3_2_LK_SHIFT               (31U)
#define TRGMUX_2_TIM1_3_2_LK_WIDTH               (1U)
#define TRGMUX_2_TIM1_3_2_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_3_2_LK_SHIFT)) & TRGMUX_2_TIM1_3_2_LK_MASK)
/*! @} */

/*! @name TIM1_5_4 - TRGMUX TIM1_5_4 */
/*! @{ */

#define TRGMUX_2_TIM1_5_4_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM1_5_4_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM1_5_4_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM1_5_4_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_5_4_SEL0_SHIFT)) & TRGMUX_2_TIM1_5_4_SEL0_MASK)

#define TRGMUX_2_TIM1_5_4_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM1_5_4_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM1_5_4_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM1_5_4_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_5_4_SEL1_SHIFT)) & TRGMUX_2_TIM1_5_4_SEL1_MASK)

#define TRGMUX_2_TIM1_5_4_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM1_5_4_LK_SHIFT               (31U)
#define TRGMUX_2_TIM1_5_4_LK_WIDTH               (1U)
#define TRGMUX_2_TIM1_5_4_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_5_4_LK_SHIFT)) & TRGMUX_2_TIM1_5_4_LK_MASK)
/*! @} */

/*! @name TIM1_7_6 - TRGMUX TIM1_7_6 */
/*! @{ */

#define TRGMUX_2_TIM1_7_6_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM1_7_6_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM1_7_6_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM1_7_6_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_7_6_SEL0_SHIFT)) & TRGMUX_2_TIM1_7_6_SEL0_MASK)

#define TRGMUX_2_TIM1_7_6_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM1_7_6_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM1_7_6_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM1_7_6_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_7_6_SEL1_SHIFT)) & TRGMUX_2_TIM1_7_6_SEL1_MASK)

#define TRGMUX_2_TIM1_7_6_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM1_7_6_LK_SHIFT               (31U)
#define TRGMUX_2_TIM1_7_6_LK_WIDTH               (1U)
#define TRGMUX_2_TIM1_7_6_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM1_7_6_LK_SHIFT)) & TRGMUX_2_TIM1_7_6_LK_MASK)
/*! @} */

/*! @name TIM2_1_0 - TRGMUX TIM2_1_0 */
/*! @{ */

#define TRGMUX_2_TIM2_1_0_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM2_1_0_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM2_1_0_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM2_1_0_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_1_0_SEL0_SHIFT)) & TRGMUX_2_TIM2_1_0_SEL0_MASK)

#define TRGMUX_2_TIM2_1_0_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM2_1_0_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM2_1_0_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM2_1_0_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_1_0_SEL1_SHIFT)) & TRGMUX_2_TIM2_1_0_SEL1_MASK)

#define TRGMUX_2_TIM2_1_0_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM2_1_0_LK_SHIFT               (31U)
#define TRGMUX_2_TIM2_1_0_LK_WIDTH               (1U)
#define TRGMUX_2_TIM2_1_0_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_1_0_LK_SHIFT)) & TRGMUX_2_TIM2_1_0_LK_MASK)
/*! @} */

/*! @name TIM2_3_2 - TRGMUX TIM2_3_2 */
/*! @{ */

#define TRGMUX_2_TIM2_3_2_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM2_3_2_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM2_3_2_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM2_3_2_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_3_2_SEL0_SHIFT)) & TRGMUX_2_TIM2_3_2_SEL0_MASK)

#define TRGMUX_2_TIM2_3_2_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM2_3_2_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM2_3_2_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM2_3_2_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_3_2_SEL1_SHIFT)) & TRGMUX_2_TIM2_3_2_SEL1_MASK)

#define TRGMUX_2_TIM2_3_2_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM2_3_2_LK_SHIFT               (31U)
#define TRGMUX_2_TIM2_3_2_LK_WIDTH               (1U)
#define TRGMUX_2_TIM2_3_2_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_3_2_LK_SHIFT)) & TRGMUX_2_TIM2_3_2_LK_MASK)
/*! @} */

/*! @name TIM2_5_4 - TRGMUX TIM2_5_4 */
/*! @{ */

#define TRGMUX_2_TIM2_5_4_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM2_5_4_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM2_5_4_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM2_5_4_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_5_4_SEL0_SHIFT)) & TRGMUX_2_TIM2_5_4_SEL0_MASK)

#define TRGMUX_2_TIM2_5_4_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM2_5_4_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM2_5_4_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM2_5_4_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_5_4_SEL1_SHIFT)) & TRGMUX_2_TIM2_5_4_SEL1_MASK)

#define TRGMUX_2_TIM2_5_4_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM2_5_4_LK_SHIFT               (31U)
#define TRGMUX_2_TIM2_5_4_LK_WIDTH               (1U)
#define TRGMUX_2_TIM2_5_4_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_5_4_LK_SHIFT)) & TRGMUX_2_TIM2_5_4_LK_MASK)
/*! @} */

/*! @name TIM2_7_6 - TRGMUX TIM2_7_6 */
/*! @{ */

#define TRGMUX_2_TIM2_7_6_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIM2_7_6_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIM2_7_6_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIM2_7_6_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_7_6_SEL0_SHIFT)) & TRGMUX_2_TIM2_7_6_SEL0_MASK)

#define TRGMUX_2_TIM2_7_6_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIM2_7_6_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIM2_7_6_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIM2_7_6_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_7_6_SEL1_SHIFT)) & TRGMUX_2_TIM2_7_6_SEL1_MASK)

#define TRGMUX_2_TIM2_7_6_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIM2_7_6_LK_SHIFT               (31U)
#define TRGMUX_2_TIM2_7_6_LK_WIDTH               (1U)
#define TRGMUX_2_TIM2_7_6_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIM2_7_6_LK_SHIFT)) & TRGMUX_2_TIM2_7_6_LK_MASK)
/*! @} */

/*! @name TIO1_1_0 - TRGMUX TIO1_1_0 */
/*! @{ */

#define TRGMUX_2_TIO1_1_0_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO1_1_0_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO1_1_0_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO1_1_0_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_1_0_SEL0_SHIFT)) & TRGMUX_2_TIO1_1_0_SEL0_MASK)

#define TRGMUX_2_TIO1_1_0_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO1_1_0_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO1_1_0_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO1_1_0_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_1_0_SEL1_SHIFT)) & TRGMUX_2_TIO1_1_0_SEL1_MASK)

#define TRGMUX_2_TIO1_1_0_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO1_1_0_LK_SHIFT               (31U)
#define TRGMUX_2_TIO1_1_0_LK_WIDTH               (1U)
#define TRGMUX_2_TIO1_1_0_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_1_0_LK_SHIFT)) & TRGMUX_2_TIO1_1_0_LK_MASK)
/*! @} */

/*! @name TIO1_3_2 - TRGMUX TIO1_3_2 */
/*! @{ */

#define TRGMUX_2_TIO1_3_2_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO1_3_2_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO1_3_2_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO1_3_2_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_3_2_SEL0_SHIFT)) & TRGMUX_2_TIO1_3_2_SEL0_MASK)

#define TRGMUX_2_TIO1_3_2_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO1_3_2_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO1_3_2_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO1_3_2_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_3_2_SEL1_SHIFT)) & TRGMUX_2_TIO1_3_2_SEL1_MASK)

#define TRGMUX_2_TIO1_3_2_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO1_3_2_LK_SHIFT               (31U)
#define TRGMUX_2_TIO1_3_2_LK_WIDTH               (1U)
#define TRGMUX_2_TIO1_3_2_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_3_2_LK_SHIFT)) & TRGMUX_2_TIO1_3_2_LK_MASK)
/*! @} */

/*! @name TIO1_5_4 - TRGMUX TIO1_5_4 */
/*! @{ */

#define TRGMUX_2_TIO1_5_4_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO1_5_4_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO1_5_4_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO1_5_4_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_5_4_SEL0_SHIFT)) & TRGMUX_2_TIO1_5_4_SEL0_MASK)

#define TRGMUX_2_TIO1_5_4_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO1_5_4_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO1_5_4_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO1_5_4_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_5_4_SEL1_SHIFT)) & TRGMUX_2_TIO1_5_4_SEL1_MASK)

#define TRGMUX_2_TIO1_5_4_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO1_5_4_LK_SHIFT               (31U)
#define TRGMUX_2_TIO1_5_4_LK_WIDTH               (1U)
#define TRGMUX_2_TIO1_5_4_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_5_4_LK_SHIFT)) & TRGMUX_2_TIO1_5_4_LK_MASK)
/*! @} */

/*! @name TIO1_7_6 - TRGMUX TIO1_7_6 */
/*! @{ */

#define TRGMUX_2_TIO1_7_6_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO1_7_6_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO1_7_6_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO1_7_6_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_7_6_SEL0_SHIFT)) & TRGMUX_2_TIO1_7_6_SEL0_MASK)

#define TRGMUX_2_TIO1_7_6_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO1_7_6_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO1_7_6_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO1_7_6_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_7_6_SEL1_SHIFT)) & TRGMUX_2_TIO1_7_6_SEL1_MASK)

#define TRGMUX_2_TIO1_7_6_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO1_7_6_LK_SHIFT               (31U)
#define TRGMUX_2_TIO1_7_6_LK_WIDTH               (1U)
#define TRGMUX_2_TIO1_7_6_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO1_7_6_LK_SHIFT)) & TRGMUX_2_TIO1_7_6_LK_MASK)
/*! @} */

/*! @name TIO2_1_0 - TRGMUX TIO2_1_0 */
/*! @{ */

#define TRGMUX_2_TIO2_1_0_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO2_1_0_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO2_1_0_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO2_1_0_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_1_0_SEL0_SHIFT)) & TRGMUX_2_TIO2_1_0_SEL0_MASK)

#define TRGMUX_2_TIO2_1_0_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO2_1_0_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO2_1_0_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO2_1_0_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_1_0_SEL1_SHIFT)) & TRGMUX_2_TIO2_1_0_SEL1_MASK)

#define TRGMUX_2_TIO2_1_0_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO2_1_0_LK_SHIFT               (31U)
#define TRGMUX_2_TIO2_1_0_LK_WIDTH               (1U)
#define TRGMUX_2_TIO2_1_0_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_1_0_LK_SHIFT)) & TRGMUX_2_TIO2_1_0_LK_MASK)
/*! @} */

/*! @name TIO2_3_2 - TRGMUX TIO2_3_2 */
/*! @{ */

#define TRGMUX_2_TIO2_3_2_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO2_3_2_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO2_3_2_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO2_3_2_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_3_2_SEL0_SHIFT)) & TRGMUX_2_TIO2_3_2_SEL0_MASK)

#define TRGMUX_2_TIO2_3_2_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO2_3_2_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO2_3_2_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO2_3_2_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_3_2_SEL1_SHIFT)) & TRGMUX_2_TIO2_3_2_SEL1_MASK)

#define TRGMUX_2_TIO2_3_2_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO2_3_2_LK_SHIFT               (31U)
#define TRGMUX_2_TIO2_3_2_LK_WIDTH               (1U)
#define TRGMUX_2_TIO2_3_2_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_3_2_LK_SHIFT)) & TRGMUX_2_TIO2_3_2_LK_MASK)
/*! @} */

/*! @name TIO2_5_4 - TRGMUX TIO2_5_4 */
/*! @{ */

#define TRGMUX_2_TIO2_5_4_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO2_5_4_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO2_5_4_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO2_5_4_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_5_4_SEL0_SHIFT)) & TRGMUX_2_TIO2_5_4_SEL0_MASK)

#define TRGMUX_2_TIO2_5_4_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO2_5_4_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO2_5_4_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO2_5_4_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_5_4_SEL1_SHIFT)) & TRGMUX_2_TIO2_5_4_SEL1_MASK)

#define TRGMUX_2_TIO2_5_4_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO2_5_4_LK_SHIFT               (31U)
#define TRGMUX_2_TIO2_5_4_LK_WIDTH               (1U)
#define TRGMUX_2_TIO2_5_4_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_5_4_LK_SHIFT)) & TRGMUX_2_TIO2_5_4_LK_MASK)
/*! @} */

/*! @name TIO2_7_6 - TRGMUX TIO2_7_6 */
/*! @{ */

#define TRGMUX_2_TIO2_7_6_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO2_7_6_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO2_7_6_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO2_7_6_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_7_6_SEL0_SHIFT)) & TRGMUX_2_TIO2_7_6_SEL0_MASK)

#define TRGMUX_2_TIO2_7_6_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO2_7_6_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO2_7_6_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO2_7_6_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_7_6_SEL1_SHIFT)) & TRGMUX_2_TIO2_7_6_SEL1_MASK)

#define TRGMUX_2_TIO2_7_6_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO2_7_6_LK_SHIFT               (31U)
#define TRGMUX_2_TIO2_7_6_LK_WIDTH               (1U)
#define TRGMUX_2_TIO2_7_6_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO2_7_6_LK_SHIFT)) & TRGMUX_2_TIO2_7_6_LK_MASK)
/*! @} */

/*! @name TIO3_1_0 - TRGMUX TIO3_1_0 */
/*! @{ */

#define TRGMUX_2_TIO3_1_0_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO3_1_0_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO3_1_0_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO3_1_0_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_1_0_SEL0_SHIFT)) & TRGMUX_2_TIO3_1_0_SEL0_MASK)

#define TRGMUX_2_TIO3_1_0_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO3_1_0_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO3_1_0_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO3_1_0_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_1_0_SEL1_SHIFT)) & TRGMUX_2_TIO3_1_0_SEL1_MASK)

#define TRGMUX_2_TIO3_1_0_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO3_1_0_LK_SHIFT               (31U)
#define TRGMUX_2_TIO3_1_0_LK_WIDTH               (1U)
#define TRGMUX_2_TIO3_1_0_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_1_0_LK_SHIFT)) & TRGMUX_2_TIO3_1_0_LK_MASK)
/*! @} */

/*! @name TIO3_3_2 - TRGMUX TIO3_3_2 */
/*! @{ */

#define TRGMUX_2_TIO3_3_2_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO3_3_2_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO3_3_2_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO3_3_2_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_3_2_SEL0_SHIFT)) & TRGMUX_2_TIO3_3_2_SEL0_MASK)

#define TRGMUX_2_TIO3_3_2_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO3_3_2_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO3_3_2_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO3_3_2_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_3_2_SEL1_SHIFT)) & TRGMUX_2_TIO3_3_2_SEL1_MASK)

#define TRGMUX_2_TIO3_3_2_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO3_3_2_LK_SHIFT               (31U)
#define TRGMUX_2_TIO3_3_2_LK_WIDTH               (1U)
#define TRGMUX_2_TIO3_3_2_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_3_2_LK_SHIFT)) & TRGMUX_2_TIO3_3_2_LK_MASK)
/*! @} */

/*! @name TIO3_5_4 - TRGMUX TIO3_5_4 */
/*! @{ */

#define TRGMUX_2_TIO3_5_4_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO3_5_4_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO3_5_4_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO3_5_4_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_5_4_SEL0_SHIFT)) & TRGMUX_2_TIO3_5_4_SEL0_MASK)

#define TRGMUX_2_TIO3_5_4_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO3_5_4_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO3_5_4_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO3_5_4_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_5_4_SEL1_SHIFT)) & TRGMUX_2_TIO3_5_4_SEL1_MASK)

#define TRGMUX_2_TIO3_5_4_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO3_5_4_LK_SHIFT               (31U)
#define TRGMUX_2_TIO3_5_4_LK_WIDTH               (1U)
#define TRGMUX_2_TIO3_5_4_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_5_4_LK_SHIFT)) & TRGMUX_2_TIO3_5_4_LK_MASK)
/*! @} */

/*! @name TIO3_7_6 - TRGMUX TIO3_7_6 */
/*! @{ */

#define TRGMUX_2_TIO3_7_6_SEL0_MASK              (0xFFU)
#define TRGMUX_2_TIO3_7_6_SEL0_SHIFT             (0U)
#define TRGMUX_2_TIO3_7_6_SEL0_WIDTH             (8U)
#define TRGMUX_2_TIO3_7_6_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_7_6_SEL0_SHIFT)) & TRGMUX_2_TIO3_7_6_SEL0_MASK)

#define TRGMUX_2_TIO3_7_6_SEL1_MASK              (0xFF00U)
#define TRGMUX_2_TIO3_7_6_SEL1_SHIFT             (8U)
#define TRGMUX_2_TIO3_7_6_SEL1_WIDTH             (8U)
#define TRGMUX_2_TIO3_7_6_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_7_6_SEL1_SHIFT)) & TRGMUX_2_TIO3_7_6_SEL1_MASK)

#define TRGMUX_2_TIO3_7_6_LK_MASK                (0x80000000U)
#define TRGMUX_2_TIO3_7_6_LK_SHIFT               (31U)
#define TRGMUX_2_TIO3_7_6_LK_WIDTH               (1U)
#define TRGMUX_2_TIO3_7_6_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_2_TIO3_7_6_LK_SHIFT)) & TRGMUX_2_TIO3_7_6_LK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TRGMUX_2_Register_Masks */

/*!
 * @}
 */ /* end of group TRGMUX_2_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_TRGMUX_2_H_) */
