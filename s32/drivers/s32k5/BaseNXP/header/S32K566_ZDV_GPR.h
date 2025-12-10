/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_ZDV_GPR.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_ZDV_GPR
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
#if !defined(S32K566_ZDV_GPR_H_)  /* Check if memory map has not been already included */
#define S32K566_ZDV_GPR_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ZDV_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ZDV_GPR_Peripheral_Access_Layer ZDV_GPR Peripheral Access Layer
 * @{
 */

/** ZDV_GPR - Register Layout Typedef */
typedef struct ZDV_GPR_Struct {
  __IO uint32_t LPID;                              /**< LPID Register, offset: 0x0 */
} ZDV_GPR_Type, *ZDV_GPR_MemMapPtr;

/** Number of instances of the ZDV_GPR module. */
#define ZDV_GPR_INSTANCE_COUNT                   (1u)

/* ZDV_GPR - Peripheral instance base addresses */
/** Peripheral DSP4__ZDV_GPR base address */
#define IP_DSP4__ZDV_GPR_BASE                    (0x4261C000u)
/** Peripheral DSP4__ZDV_GPR base pointer */
#define IP_DSP4__ZDV_GPR                         ((ZDV_GPR_Type *)IP_DSP4__ZDV_GPR_BASE)
/** Array initializer of ZDV_GPR peripheral base addresses */
#define IP_ZDV_GPR_BASE_ADDRS                    { IP_DSP4__ZDV_GPR_BASE }
/** Array initializer of ZDV_GPR peripheral base pointers */
#define IP_ZDV_GPR_BASE_PTRS                     { IP_DSP4__ZDV_GPR }

/* ----------------------------------------------------------------------------
   -- ZDV_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ZDV_GPR_Register_Masks ZDV_GPR Register Masks
 * @{
 */

/*! @name LPID - LPID Register */
/*! @{ */

#define ZDV_GPR_LPID_LPID_MASK                   (0xFU)
#define ZDV_GPR_LPID_LPID_SHIFT                  (0U)
#define ZDV_GPR_LPID_LPID_WIDTH                  (4U)
#define ZDV_GPR_LPID_LPID(x)                     (((uint32_t)(((uint32_t)(x)) << ZDV_GPR_LPID_LPID_SHIFT)) & ZDV_GPR_LPID_LPID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ZDV_GPR_Register_Masks */

/*!
 * @}
 */ /* end of group ZDV_GPR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_ZDV_GPR_H_) */
