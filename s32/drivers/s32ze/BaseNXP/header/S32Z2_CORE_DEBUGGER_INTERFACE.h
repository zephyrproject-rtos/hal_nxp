/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CORE_DEBUGGER_INTERFACE.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CORE_DEBUGGER_INTERFACE
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
#if !defined(S32Z2_CORE_DEBUGGER_INTERFACE_H_)  /* Check if memory map has not been already included */
#define S32Z2_CORE_DEBUGGER_INTERFACE_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CORE_DEBUGGER_INTERFACE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORE_DEBUGGER_INTERFACE_Peripheral_Access_Layer CORE_DEBUGGER_INTERFACE Peripheral Access Layer
 * @{
 */

/** CORE_DEBUGGER_INTERFACE - Register Layout Typedef */
typedef struct {
  __IO uint32_t CORE_DRD3_RD;                      /**< Core DRD3 RD Register, offset: 0x0 */
  __IO uint32_t CORE_DRD2_RD;                      /**< Core DRD2 RD Register, offset: 0x4 */
  __IO uint32_t CORE_DRD1_RD;                      /**< Core DRD1 RD Register, offset: 0x8 */
  __IO uint32_t CORE_DRD_RD;                       /**< Core DRD RD Register, offset: 0xC */
} CORE_DEBUGGER_INTERFACE_Type, *CORE_DEBUGGER_INTERFACE_MemMapPtr;

/** Number of instances of the CORE_DEBUGGER_INTERFACE module. */
#define CORE_DEBUGGER_INTERFACE_INSTANCE_COUNT   (1u)

/* CORE_DEBUGGER_INTERFACE - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__CORE_DEBUGGER_INTERFACE base address */
#define IP_CEVA_SPF2__CORE_DEBUGGER_INTERFACE_BASE (0x244001D0u)
/** Peripheral CEVA_SPF2__CORE_DEBUGGER_INTERFACE base pointer */
#define IP_CEVA_SPF2__CORE_DEBUGGER_INTERFACE    ((CORE_DEBUGGER_INTERFACE_Type *)IP_CEVA_SPF2__CORE_DEBUGGER_INTERFACE_BASE)
/** Array initializer of CORE_DEBUGGER_INTERFACE peripheral base addresses */
#define IP_CORE_DEBUGGER_INTERFACE_BASE_ADDRS    { IP_CEVA_SPF2__CORE_DEBUGGER_INTERFACE_BASE }
/** Array initializer of CORE_DEBUGGER_INTERFACE peripheral base pointers */
#define IP_CORE_DEBUGGER_INTERFACE_BASE_PTRS     { IP_CEVA_SPF2__CORE_DEBUGGER_INTERFACE }

/* ----------------------------------------------------------------------------
   -- CORE_DEBUGGER_INTERFACE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORE_DEBUGGER_INTERFACE_Register_Masks CORE_DEBUGGER_INTERFACE Register Masks
 * @{
 */

/*! @name CORE_DRD3_RD - Core DRD3 RD Register */
/*! @{ */

#define CORE_DEBUGGER_INTERFACE_CORE_DRD3_RD_core_drd3_rd_MASK (0xFFFFFFFFU)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD3_RD_core_drd3_rd_SHIFT (0U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD3_RD_core_drd3_rd_WIDTH (32U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD3_RD_core_drd3_rd(x) (((uint32_t)(((uint32_t)(x)) << CORE_DEBUGGER_INTERFACE_CORE_DRD3_RD_core_drd3_rd_SHIFT)) & CORE_DEBUGGER_INTERFACE_CORE_DRD3_RD_core_drd3_rd_MASK)
/*! @} */

/*! @name CORE_DRD2_RD - Core DRD2 RD Register */
/*! @{ */

#define CORE_DEBUGGER_INTERFACE_CORE_DRD2_RD_core_drd2_rd_MASK (0xFFFFFFFFU)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD2_RD_core_drd2_rd_SHIFT (0U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD2_RD_core_drd2_rd_WIDTH (32U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD2_RD_core_drd2_rd(x) (((uint32_t)(((uint32_t)(x)) << CORE_DEBUGGER_INTERFACE_CORE_DRD2_RD_core_drd2_rd_SHIFT)) & CORE_DEBUGGER_INTERFACE_CORE_DRD2_RD_core_drd2_rd_MASK)
/*! @} */

/*! @name CORE_DRD1_RD - Core DRD1 RD Register */
/*! @{ */

#define CORE_DEBUGGER_INTERFACE_CORE_DRD1_RD_core_drd1_rd_MASK (0xFFFFFFFFU)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD1_RD_core_drd1_rd_SHIFT (0U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD1_RD_core_drd1_rd_WIDTH (32U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD1_RD_core_drd1_rd(x) (((uint32_t)(((uint32_t)(x)) << CORE_DEBUGGER_INTERFACE_CORE_DRD1_RD_core_drd1_rd_SHIFT)) & CORE_DEBUGGER_INTERFACE_CORE_DRD1_RD_core_drd1_rd_MASK)
/*! @} */

/*! @name CORE_DRD_RD - Core DRD RD Register */
/*! @{ */

#define CORE_DEBUGGER_INTERFACE_CORE_DRD_RD_core_drd_rd_MASK (0xFFFFFFFFU)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD_RD_core_drd_rd_SHIFT (0U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD_RD_core_drd_rd_WIDTH (32U)
#define CORE_DEBUGGER_INTERFACE_CORE_DRD_RD_core_drd_rd(x) (((uint32_t)(((uint32_t)(x)) << CORE_DEBUGGER_INTERFACE_CORE_DRD_RD_core_drd_rd_SHIFT)) & CORE_DEBUGGER_INTERFACE_CORE_DRD_RD_core_drd_rd_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CORE_DEBUGGER_INTERFACE_Register_Masks */

/*!
 * @}
 */ /* end of group CORE_DEBUGGER_INTERFACE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CORE_DEBUGGER_INTERFACE_H_) */
