/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_TRGMUX_1.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_TRGMUX_1
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
#if !defined(S32Z2_TRGMUX_1_H_)  /* Check if memory map has not been already included */
#define S32Z2_TRGMUX_1_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TRGMUX_1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_1_Peripheral_Access_Layer TRGMUX_1 Peripheral Access Layer
 * @{
 */

/** TRGMUX_1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG_0;                             /**< TRGMUX REG_0, offset: 0x0 */
  __IO uint32_t REG_1;                             /**< TRGMUX REG_1, offset: 0x4 */
  __IO uint32_t REG_2;                             /**< TRGMUX REG_2, offset: 0x8 */
  __IO uint32_t REG_3;                             /**< TRGMUX REG_3, offset: 0xC */
  __IO uint32_t REG_4;                             /**< TRGMUX REG_4, offset: 0x10 */
} TRGMUX_1_Type, *TRGMUX_1_MemMapPtr;

/** Number of instances of the TRGMUX_1 module. */
#define TRGMUX_1_INSTANCE_COUNT                  (1u)

/* TRGMUX_1 - Peripheral instance base addresses */
/** Peripheral TRGMUX_1 base address */
#define IP_TRGMUX_1_BASE                         (0x40090000u)
/** Peripheral TRGMUX_1 base pointer */
#define IP_TRGMUX_1                              ((TRGMUX_1_Type *)IP_TRGMUX_1_BASE)
/** Array initializer of TRGMUX_1 peripheral base addresses */
#define IP_TRGMUX_1_BASE_ADDRS                   { IP_TRGMUX_1_BASE }
/** Array initializer of TRGMUX_1 peripheral base pointers */
#define IP_TRGMUX_1_BASE_PTRS                    { IP_TRGMUX_1 }

/* ----------------------------------------------------------------------------
   -- TRGMUX_1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_1_Register_Masks TRGMUX_1 Register Masks
 * @{
 */

/*! @name REG_0 - TRGMUX REG_0 */
/*! @{ */

#define TRGMUX_1_REG_0_SEL0_MASK                 (0x3FU)
#define TRGMUX_1_REG_0_SEL0_SHIFT                (0U)
#define TRGMUX_1_REG_0_SEL0_WIDTH                (6U)
#define TRGMUX_1_REG_0_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_0_SEL0_SHIFT)) & TRGMUX_1_REG_0_SEL0_MASK)

#define TRGMUX_1_REG_0_SEL1_MASK                 (0x3F00U)
#define TRGMUX_1_REG_0_SEL1_SHIFT                (8U)
#define TRGMUX_1_REG_0_SEL1_WIDTH                (6U)
#define TRGMUX_1_REG_0_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_0_SEL1_SHIFT)) & TRGMUX_1_REG_0_SEL1_MASK)

#define TRGMUX_1_REG_0_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_1_REG_0_SEL2_SHIFT                (16U)
#define TRGMUX_1_REG_0_SEL2_WIDTH                (6U)
#define TRGMUX_1_REG_0_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_0_SEL2_SHIFT)) & TRGMUX_1_REG_0_SEL2_MASK)

#define TRGMUX_1_REG_0_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_1_REG_0_SEL3_SHIFT                (24U)
#define TRGMUX_1_REG_0_SEL3_WIDTH                (6U)
#define TRGMUX_1_REG_0_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_0_SEL3_SHIFT)) & TRGMUX_1_REG_0_SEL3_MASK)

#define TRGMUX_1_REG_0_LK_MASK                   (0x80000000U)
#define TRGMUX_1_REG_0_LK_SHIFT                  (31U)
#define TRGMUX_1_REG_0_LK_WIDTH                  (1U)
#define TRGMUX_1_REG_0_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_0_LK_SHIFT)) & TRGMUX_1_REG_0_LK_MASK)
/*! @} */

/*! @name REG_1 - TRGMUX REG_1 */
/*! @{ */

#define TRGMUX_1_REG_1_SEL0_MASK                 (0x3FU)
#define TRGMUX_1_REG_1_SEL0_SHIFT                (0U)
#define TRGMUX_1_REG_1_SEL0_WIDTH                (6U)
#define TRGMUX_1_REG_1_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_1_SEL0_SHIFT)) & TRGMUX_1_REG_1_SEL0_MASK)

#define TRGMUX_1_REG_1_SEL1_MASK                 (0x3F00U)
#define TRGMUX_1_REG_1_SEL1_SHIFT                (8U)
#define TRGMUX_1_REG_1_SEL1_WIDTH                (6U)
#define TRGMUX_1_REG_1_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_1_SEL1_SHIFT)) & TRGMUX_1_REG_1_SEL1_MASK)

#define TRGMUX_1_REG_1_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_1_REG_1_SEL2_SHIFT                (16U)
#define TRGMUX_1_REG_1_SEL2_WIDTH                (6U)
#define TRGMUX_1_REG_1_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_1_SEL2_SHIFT)) & TRGMUX_1_REG_1_SEL2_MASK)

#define TRGMUX_1_REG_1_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_1_REG_1_SEL3_SHIFT                (24U)
#define TRGMUX_1_REG_1_SEL3_WIDTH                (6U)
#define TRGMUX_1_REG_1_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_1_SEL3_SHIFT)) & TRGMUX_1_REG_1_SEL3_MASK)

#define TRGMUX_1_REG_1_LK_MASK                   (0x80000000U)
#define TRGMUX_1_REG_1_LK_SHIFT                  (31U)
#define TRGMUX_1_REG_1_LK_WIDTH                  (1U)
#define TRGMUX_1_REG_1_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_1_LK_SHIFT)) & TRGMUX_1_REG_1_LK_MASK)
/*! @} */

/*! @name REG_2 - TRGMUX REG_2 */
/*! @{ */

#define TRGMUX_1_REG_2_SEL0_MASK                 (0x3FU)
#define TRGMUX_1_REG_2_SEL0_SHIFT                (0U)
#define TRGMUX_1_REG_2_SEL0_WIDTH                (6U)
#define TRGMUX_1_REG_2_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_2_SEL0_SHIFT)) & TRGMUX_1_REG_2_SEL0_MASK)

#define TRGMUX_1_REG_2_SEL1_MASK                 (0x3F00U)
#define TRGMUX_1_REG_2_SEL1_SHIFT                (8U)
#define TRGMUX_1_REG_2_SEL1_WIDTH                (6U)
#define TRGMUX_1_REG_2_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_2_SEL1_SHIFT)) & TRGMUX_1_REG_2_SEL1_MASK)

#define TRGMUX_1_REG_2_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_1_REG_2_SEL2_SHIFT                (16U)
#define TRGMUX_1_REG_2_SEL2_WIDTH                (6U)
#define TRGMUX_1_REG_2_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_2_SEL2_SHIFT)) & TRGMUX_1_REG_2_SEL2_MASK)

#define TRGMUX_1_REG_2_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_1_REG_2_SEL3_SHIFT                (24U)
#define TRGMUX_1_REG_2_SEL3_WIDTH                (6U)
#define TRGMUX_1_REG_2_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_2_SEL3_SHIFT)) & TRGMUX_1_REG_2_SEL3_MASK)

#define TRGMUX_1_REG_2_LK_MASK                   (0x80000000U)
#define TRGMUX_1_REG_2_LK_SHIFT                  (31U)
#define TRGMUX_1_REG_2_LK_WIDTH                  (1U)
#define TRGMUX_1_REG_2_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_2_LK_SHIFT)) & TRGMUX_1_REG_2_LK_MASK)
/*! @} */

/*! @name REG_3 - TRGMUX REG_3 */
/*! @{ */

#define TRGMUX_1_REG_3_SEL0_MASK                 (0x3FU)
#define TRGMUX_1_REG_3_SEL0_SHIFT                (0U)
#define TRGMUX_1_REG_3_SEL0_WIDTH                (6U)
#define TRGMUX_1_REG_3_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_3_SEL0_SHIFT)) & TRGMUX_1_REG_3_SEL0_MASK)

#define TRGMUX_1_REG_3_SEL1_MASK                 (0x3F00U)
#define TRGMUX_1_REG_3_SEL1_SHIFT                (8U)
#define TRGMUX_1_REG_3_SEL1_WIDTH                (6U)
#define TRGMUX_1_REG_3_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_3_SEL1_SHIFT)) & TRGMUX_1_REG_3_SEL1_MASK)

#define TRGMUX_1_REG_3_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_1_REG_3_SEL2_SHIFT                (16U)
#define TRGMUX_1_REG_3_SEL2_WIDTH                (6U)
#define TRGMUX_1_REG_3_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_3_SEL2_SHIFT)) & TRGMUX_1_REG_3_SEL2_MASK)

#define TRGMUX_1_REG_3_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_1_REG_3_SEL3_SHIFT                (24U)
#define TRGMUX_1_REG_3_SEL3_WIDTH                (6U)
#define TRGMUX_1_REG_3_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_3_SEL3_SHIFT)) & TRGMUX_1_REG_3_SEL3_MASK)

#define TRGMUX_1_REG_3_LK_MASK                   (0x80000000U)
#define TRGMUX_1_REG_3_LK_SHIFT                  (31U)
#define TRGMUX_1_REG_3_LK_WIDTH                  (1U)
#define TRGMUX_1_REG_3_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_3_LK_SHIFT)) & TRGMUX_1_REG_3_LK_MASK)
/*! @} */

/*! @name REG_4 - TRGMUX REG_4 */
/*! @{ */

#define TRGMUX_1_REG_4_SEL0_MASK                 (0x3FU)
#define TRGMUX_1_REG_4_SEL0_SHIFT                (0U)
#define TRGMUX_1_REG_4_SEL0_WIDTH                (6U)
#define TRGMUX_1_REG_4_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_4_SEL0_SHIFT)) & TRGMUX_1_REG_4_SEL0_MASK)

#define TRGMUX_1_REG_4_SEL1_MASK                 (0x3F00U)
#define TRGMUX_1_REG_4_SEL1_SHIFT                (8U)
#define TRGMUX_1_REG_4_SEL1_WIDTH                (6U)
#define TRGMUX_1_REG_4_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_4_SEL1_SHIFT)) & TRGMUX_1_REG_4_SEL1_MASK)

#define TRGMUX_1_REG_4_LK_MASK                   (0x80000000U)
#define TRGMUX_1_REG_4_LK_SHIFT                  (31U)
#define TRGMUX_1_REG_4_LK_WIDTH                  (1U)
#define TRGMUX_1_REG_4_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_1_REG_4_LK_SHIFT)) & TRGMUX_1_REG_4_LK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TRGMUX_1_Register_Masks */

/*!
 * @}
 */ /* end of group TRGMUX_1_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_TRGMUX_1_H_) */
