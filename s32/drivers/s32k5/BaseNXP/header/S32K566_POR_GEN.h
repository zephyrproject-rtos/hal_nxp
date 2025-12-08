/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_POR_GEN.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_POR_GEN
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
#if !defined(S32K566_POR_GEN_H_)  /* Check if memory map has not been already included */
#define S32K566_POR_GEN_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- POR_GEN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POR_GEN_Peripheral_Access_Layer POR_GEN Peripheral Access Layer
 * @{
 */

/** POR_GEN - Register Layout Typedef */
typedef struct POR_GEN_Struct {
  __IO uint32_t RESETF;                            /**< Reset Flag, offset: 0x0 */
} POR_GEN_Type, *POR_GEN_MemMapPtr;

/** Number of instances of the POR_GEN module. */
#define POR_GEN_INSTANCE_COUNT                   (1u)

/* POR_GEN - Peripheral instance base addresses */
/** Peripheral POR_GEN base address */
#define IP_POR_GEN_BASE                          (0x42194000u)
/** Peripheral POR_GEN base pointer */
#define IP_POR_GEN                               ((POR_GEN_Type *)IP_POR_GEN_BASE)
/** Array initializer of POR_GEN peripheral base addresses */
#define IP_POR_GEN_BASE_ADDRS                    { IP_POR_GEN_BASE }
/** Array initializer of POR_GEN peripheral base pointers */
#define IP_POR_GEN_BASE_PTRS                     { IP_POR_GEN }

/* ----------------------------------------------------------------------------
   -- POR_GEN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POR_GEN_Register_Masks POR_GEN Register Masks
 * @{
 */

/*! @name RESETF - Reset Flag */
/*! @{ */

#define POR_GEN_RESETF_SPDF_MASK                 (0x2U)
#define POR_GEN_RESETF_SPDF_SHIFT                (1U)
#define POR_GEN_RESETF_SPDF_WIDTH                (1U)
#define POR_GEN_RESETF_SPDF(x)                   (((uint32_t)(((uint32_t)(x)) << POR_GEN_RESETF_SPDF_SHIFT)) & POR_GEN_RESETF_SPDF_MASK)

#define POR_GEN_RESETF_SPSF0_MASK                (0x100U)
#define POR_GEN_RESETF_SPSF0_SHIFT               (8U)
#define POR_GEN_RESETF_SPSF0_WIDTH               (1U)
#define POR_GEN_RESETF_SPSF0(x)                  (((uint32_t)(((uint32_t)(x)) << POR_GEN_RESETF_SPSF0_SHIFT)) & POR_GEN_RESETF_SPSF0_MASK)

#define POR_GEN_RESETF_SPSF1_MASK                (0x200U)
#define POR_GEN_RESETF_SPSF1_SHIFT               (9U)
#define POR_GEN_RESETF_SPSF1_WIDTH               (1U)
#define POR_GEN_RESETF_SPSF1(x)                  (((uint32_t)(((uint32_t)(x)) << POR_GEN_RESETF_SPSF1_SHIFT)) & POR_GEN_RESETF_SPSF1_MASK)

#define POR_GEN_RESETF_SPSF2_MASK                (0x400U)
#define POR_GEN_RESETF_SPSF2_SHIFT               (10U)
#define POR_GEN_RESETF_SPSF2_WIDTH               (1U)
#define POR_GEN_RESETF_SPSF2(x)                  (((uint32_t)(((uint32_t)(x)) << POR_GEN_RESETF_SPSF2_SHIFT)) & POR_GEN_RESETF_SPSF2_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group POR_GEN_Register_Masks */

/*!
 * @}
 */ /* end of group POR_GEN_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_POR_GEN_H_) */
