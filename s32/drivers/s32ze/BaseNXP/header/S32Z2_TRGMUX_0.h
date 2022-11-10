/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_TRGMUX_0.h
 * @version 1.8
 * @date 2022-07-13
 * @brief Peripheral Access Layer for S32Z2_TRGMUX_0
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
#if !defined(S32Z2_TRGMUX_0_H_)  /* Check if memory map has not been already included */
#define S32Z2_TRGMUX_0_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TRGMUX_0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_0_Peripheral_Access_Layer TRGMUX_0 Peripheral Access Layer
 * @{
 */

/** TRGMUX_0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG_0;                             /**< TRGMUX REG_0 Register, offset: 0x0 */
  __IO uint32_t REG_1;                             /**< TRGMUX REG_1 Register, offset: 0x4 */
  __IO uint32_t REG_2;                             /**< TRGMUX REG_2 Register, offset: 0x8 */
  __IO uint32_t REG_3;                             /**< TRGMUX REG_3 Register, offset: 0xC */
  __IO uint32_t REG_4;                             /**< TRGMUX REG_4 Register, offset: 0x10 */
} TRGMUX_0_Type, *TRGMUX_0_MemMapPtr;

/** Number of instances of the TRGMUX_0 module. */
#define TRGMUX_0_INSTANCE_COUNT                  (1u)

/* TRGMUX_0 - Peripheral instance base addresses */
/** Peripheral TRGMUX_0 base address */
#define IP_TRGMUX_0_BASE                         (0x42090000u)
/** Peripheral TRGMUX_0 base pointer */
#define IP_TRGMUX_0                              ((TRGMUX_0_Type *)IP_TRGMUX_0_BASE)
/** Array initializer of TRGMUX_0 peripheral base addresses */
#define IP_TRGMUX_0_BASE_ADDRS                   { IP_TRGMUX_0_BASE }
/** Array initializer of TRGMUX_0 peripheral base pointers */
#define IP_TRGMUX_0_BASE_PTRS                    { IP_TRGMUX_0 }

/* ----------------------------------------------------------------------------
   -- TRGMUX_0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_0_Register_Masks TRGMUX_0 Register Masks
 * @{
 */

/*! @name REG_0 - TRGMUX REG_0 Register */
/*! @{ */

#define TRGMUX_0_REG_0_SEL0_MASK                 (0x3FU)
#define TRGMUX_0_REG_0_SEL0_SHIFT                (0U)
#define TRGMUX_0_REG_0_SEL0_WIDTH                (6U)
#define TRGMUX_0_REG_0_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_0_SEL0_SHIFT)) & TRGMUX_0_REG_0_SEL0_MASK)

#define TRGMUX_0_REG_0_SEL1_MASK                 (0x3F00U)
#define TRGMUX_0_REG_0_SEL1_SHIFT                (8U)
#define TRGMUX_0_REG_0_SEL1_WIDTH                (6U)
#define TRGMUX_0_REG_0_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_0_SEL1_SHIFT)) & TRGMUX_0_REG_0_SEL1_MASK)

#define TRGMUX_0_REG_0_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_0_REG_0_SEL2_SHIFT                (16U)
#define TRGMUX_0_REG_0_SEL2_WIDTH                (6U)
#define TRGMUX_0_REG_0_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_0_SEL2_SHIFT)) & TRGMUX_0_REG_0_SEL2_MASK)

#define TRGMUX_0_REG_0_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_0_REG_0_SEL3_SHIFT                (24U)
#define TRGMUX_0_REG_0_SEL3_WIDTH                (6U)
#define TRGMUX_0_REG_0_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_0_SEL3_SHIFT)) & TRGMUX_0_REG_0_SEL3_MASK)

#define TRGMUX_0_REG_0_LK_MASK                   (0x80000000U)
#define TRGMUX_0_REG_0_LK_SHIFT                  (31U)
#define TRGMUX_0_REG_0_LK_WIDTH                  (1U)
#define TRGMUX_0_REG_0_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_0_LK_SHIFT)) & TRGMUX_0_REG_0_LK_MASK)
/*! @} */

/*! @name REG_1 - TRGMUX REG_1 Register */
/*! @{ */

#define TRGMUX_0_REG_1_SEL0_MASK                 (0x3FU)
#define TRGMUX_0_REG_1_SEL0_SHIFT                (0U)
#define TRGMUX_0_REG_1_SEL0_WIDTH                (6U)
#define TRGMUX_0_REG_1_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_1_SEL0_SHIFT)) & TRGMUX_0_REG_1_SEL0_MASK)

#define TRGMUX_0_REG_1_SEL1_MASK                 (0x3F00U)
#define TRGMUX_0_REG_1_SEL1_SHIFT                (8U)
#define TRGMUX_0_REG_1_SEL1_WIDTH                (6U)
#define TRGMUX_0_REG_1_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_1_SEL1_SHIFT)) & TRGMUX_0_REG_1_SEL1_MASK)

#define TRGMUX_0_REG_1_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_0_REG_1_SEL2_SHIFT                (16U)
#define TRGMUX_0_REG_1_SEL2_WIDTH                (6U)
#define TRGMUX_0_REG_1_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_1_SEL2_SHIFT)) & TRGMUX_0_REG_1_SEL2_MASK)

#define TRGMUX_0_REG_1_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_0_REG_1_SEL3_SHIFT                (24U)
#define TRGMUX_0_REG_1_SEL3_WIDTH                (6U)
#define TRGMUX_0_REG_1_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_1_SEL3_SHIFT)) & TRGMUX_0_REG_1_SEL3_MASK)

#define TRGMUX_0_REG_1_LK_MASK                   (0x80000000U)
#define TRGMUX_0_REG_1_LK_SHIFT                  (31U)
#define TRGMUX_0_REG_1_LK_WIDTH                  (1U)
#define TRGMUX_0_REG_1_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_1_LK_SHIFT)) & TRGMUX_0_REG_1_LK_MASK)
/*! @} */

/*! @name REG_2 - TRGMUX REG_2 Register */
/*! @{ */

#define TRGMUX_0_REG_2_SEL0_MASK                 (0x3FU)
#define TRGMUX_0_REG_2_SEL0_SHIFT                (0U)
#define TRGMUX_0_REG_2_SEL0_WIDTH                (6U)
#define TRGMUX_0_REG_2_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_2_SEL0_SHIFT)) & TRGMUX_0_REG_2_SEL0_MASK)

#define TRGMUX_0_REG_2_SEL1_MASK                 (0x3F00U)
#define TRGMUX_0_REG_2_SEL1_SHIFT                (8U)
#define TRGMUX_0_REG_2_SEL1_WIDTH                (6U)
#define TRGMUX_0_REG_2_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_2_SEL1_SHIFT)) & TRGMUX_0_REG_2_SEL1_MASK)

#define TRGMUX_0_REG_2_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_0_REG_2_SEL2_SHIFT                (16U)
#define TRGMUX_0_REG_2_SEL2_WIDTH                (6U)
#define TRGMUX_0_REG_2_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_2_SEL2_SHIFT)) & TRGMUX_0_REG_2_SEL2_MASK)

#define TRGMUX_0_REG_2_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_0_REG_2_SEL3_SHIFT                (24U)
#define TRGMUX_0_REG_2_SEL3_WIDTH                (6U)
#define TRGMUX_0_REG_2_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_2_SEL3_SHIFT)) & TRGMUX_0_REG_2_SEL3_MASK)

#define TRGMUX_0_REG_2_LK_MASK                   (0x80000000U)
#define TRGMUX_0_REG_2_LK_SHIFT                  (31U)
#define TRGMUX_0_REG_2_LK_WIDTH                  (1U)
#define TRGMUX_0_REG_2_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_2_LK_SHIFT)) & TRGMUX_0_REG_2_LK_MASK)
/*! @} */

/*! @name REG_3 - TRGMUX REG_3 Register */
/*! @{ */

#define TRGMUX_0_REG_3_SEL0_MASK                 (0x3FU)
#define TRGMUX_0_REG_3_SEL0_SHIFT                (0U)
#define TRGMUX_0_REG_3_SEL0_WIDTH                (6U)
#define TRGMUX_0_REG_3_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_3_SEL0_SHIFT)) & TRGMUX_0_REG_3_SEL0_MASK)

#define TRGMUX_0_REG_3_SEL1_MASK                 (0x3F00U)
#define TRGMUX_0_REG_3_SEL1_SHIFT                (8U)
#define TRGMUX_0_REG_3_SEL1_WIDTH                (6U)
#define TRGMUX_0_REG_3_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_3_SEL1_SHIFT)) & TRGMUX_0_REG_3_SEL1_MASK)

#define TRGMUX_0_REG_3_SEL2_MASK                 (0x3F0000U)
#define TRGMUX_0_REG_3_SEL2_SHIFT                (16U)
#define TRGMUX_0_REG_3_SEL2_WIDTH                (6U)
#define TRGMUX_0_REG_3_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_3_SEL2_SHIFT)) & TRGMUX_0_REG_3_SEL2_MASK)

#define TRGMUX_0_REG_3_SEL3_MASK                 (0x3F000000U)
#define TRGMUX_0_REG_3_SEL3_SHIFT                (24U)
#define TRGMUX_0_REG_3_SEL3_WIDTH                (6U)
#define TRGMUX_0_REG_3_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_3_SEL3_SHIFT)) & TRGMUX_0_REG_3_SEL3_MASK)

#define TRGMUX_0_REG_3_LK_MASK                   (0x80000000U)
#define TRGMUX_0_REG_3_LK_SHIFT                  (31U)
#define TRGMUX_0_REG_3_LK_WIDTH                  (1U)
#define TRGMUX_0_REG_3_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_3_LK_SHIFT)) & TRGMUX_0_REG_3_LK_MASK)
/*! @} */

/*! @name REG_4 - TRGMUX REG_4 Register */
/*! @{ */

#define TRGMUX_0_REG_4_SEL0_MASK                 (0x3FU)
#define TRGMUX_0_REG_4_SEL0_SHIFT                (0U)
#define TRGMUX_0_REG_4_SEL0_WIDTH                (6U)
#define TRGMUX_0_REG_4_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_4_SEL0_SHIFT)) & TRGMUX_0_REG_4_SEL0_MASK)

#define TRGMUX_0_REG_4_SEL1_MASK                 (0x3F00U)
#define TRGMUX_0_REG_4_SEL1_SHIFT                (8U)
#define TRGMUX_0_REG_4_SEL1_WIDTH                (6U)
#define TRGMUX_0_REG_4_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_4_SEL1_SHIFT)) & TRGMUX_0_REG_4_SEL1_MASK)

#define TRGMUX_0_REG_4_LK_MASK                   (0x80000000U)
#define TRGMUX_0_REG_4_LK_SHIFT                  (31U)
#define TRGMUX_0_REG_4_LK_WIDTH                  (1U)
#define TRGMUX_0_REG_4_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_0_REG_4_LK_SHIFT)) & TRGMUX_0_REG_4_LK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TRGMUX_0_Register_Masks */

/*!
 * @}
 */ /* end of group TRGMUX_0_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_TRGMUX_0_H_) */
