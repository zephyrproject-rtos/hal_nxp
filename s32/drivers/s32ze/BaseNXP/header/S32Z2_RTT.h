/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_RTT.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_RTT
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
#if !defined(S32Z2_RTT_H_)  /* Check if memory map has not been already included */
#define S32Z2_RTT_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- RTT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTT_Peripheral_Access_Layer RTT Peripheral Access Layer
 * @{
 */

/** RTT - Register Layout Typedef */
typedef struct {
  __IO uint32_t MODE;                              /**< MODE Register, offset: 0x0 */
} RTT_Type, *RTT_MemMapPtr;

/** Number of instances of the RTT module. */
#define RTT_INSTANCE_COUNT                       (1u)

/* RTT - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__RTT base address */
#define IP_CEVA_SPF2__RTT_BASE                   (0x24400180u)
/** Peripheral CEVA_SPF2__RTT base pointer */
#define IP_CEVA_SPF2__RTT                        ((RTT_Type *)IP_CEVA_SPF2__RTT_BASE)
/** Array initializer of RTT peripheral base addresses */
#define IP_RTT_BASE_ADDRS                        { IP_CEVA_SPF2__RTT_BASE }
/** Array initializer of RTT peripheral base pointers */
#define IP_RTT_BASE_PTRS                         { IP_CEVA_SPF2__RTT }

/* ----------------------------------------------------------------------------
   -- RTT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTT_Register_Masks RTT Register Masks
 * @{
 */

/*! @name MODE - MODE Register */
/*! @{ */

#define RTT_MODE_WR_EN_MASK                      (0x40U)
#define RTT_MODE_WR_EN_SHIFT                     (6U)
#define RTT_MODE_WR_EN_WIDTH                     (1U)
#define RTT_MODE_WR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << RTT_MODE_WR_EN_SHIFT)) & RTT_MODE_WR_EN_MASK)

#define RTT_MODE_WR_RESET_MASK                   (0x80U)
#define RTT_MODE_WR_RESET_SHIFT                  (7U)
#define RTT_MODE_WR_RESET_WIDTH                  (1U)
#define RTT_MODE_WR_RESET(x)                     (((uint32_t)(((uint32_t)(x)) << RTT_MODE_WR_RESET_SHIFT)) & RTT_MODE_WR_RESET_MASK)

#define RTT_MODE_BR_ALL_MASK                     (0x400U)
#define RTT_MODE_BR_ALL_SHIFT                    (10U)
#define RTT_MODE_BR_ALL_WIDTH                    (1U)
#define RTT_MODE_BR_ALL(x)                       (((uint32_t)(((uint32_t)(x)) << RTT_MODE_BR_ALL_SHIFT)) & RTT_MODE_BR_ALL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group RTT_Register_Masks */

/*!
 * @}
 */ /* end of group RTT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_RTT_H_) */
