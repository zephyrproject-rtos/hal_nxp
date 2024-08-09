/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ACCESS_PROTECTION.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_ACCESS_PROTECTION
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
#if !defined(S32Z2_ACCESS_PROTECTION_H_)  /* Check if memory map has not been already included */
#define S32Z2_ACCESS_PROTECTION_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ACCESS_PROTECTION Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACCESS_PROTECTION_Peripheral_Access_Layer ACCESS_PROTECTION Peripheral Access Layer
 * @{
 */

/** ACCESS_PROTECTION - Register Layout Typedef */
typedef struct {
  __I  uint32_t MAPAR;                             /**< Memory Access Protection Address Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __IO uint32_t D_DTAP;                            /**< IDM Access Configuration, offset: 0x8 */
} ACCESS_PROTECTION_Type, *ACCESS_PROTECTION_MemMapPtr;

/** Number of instances of the ACCESS_PROTECTION module. */
#define ACCESS_PROTECTION_INSTANCE_COUNT         (1u)

/* ACCESS_PROTECTION - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__ACCESS_PROTECTION base address */
#define IP_CEVA_SPF2__ACCESS_PROTECTION_BASE     (0x24400C80u)
/** Peripheral CEVA_SPF2__ACCESS_PROTECTION base pointer */
#define IP_CEVA_SPF2__ACCESS_PROTECTION          ((ACCESS_PROTECTION_Type *)IP_CEVA_SPF2__ACCESS_PROTECTION_BASE)
/** Array initializer of ACCESS_PROTECTION peripheral base addresses */
#define IP_ACCESS_PROTECTION_BASE_ADDRS          { IP_CEVA_SPF2__ACCESS_PROTECTION_BASE }
/** Array initializer of ACCESS_PROTECTION peripheral base pointers */
#define IP_ACCESS_PROTECTION_BASE_PTRS           { IP_CEVA_SPF2__ACCESS_PROTECTION }

/* ----------------------------------------------------------------------------
   -- ACCESS_PROTECTION Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACCESS_PROTECTION_Register_Masks ACCESS_PROTECTION Register Masks
 * @{
 */

/*! @name MAPAR - Memory Access Protection Address Register */
/*! @{ */

#define ACCESS_PROTECTION_MAPAR_MAPA_MASK        (0xFFFFFFFFU)
#define ACCESS_PROTECTION_MAPAR_MAPA_SHIFT       (0U)
#define ACCESS_PROTECTION_MAPAR_MAPA_WIDTH       (32U)
#define ACCESS_PROTECTION_MAPAR_MAPA(x)          (((uint32_t)(((uint32_t)(x)) << ACCESS_PROTECTION_MAPAR_MAPA_SHIFT)) & ACCESS_PROTECTION_MAPAR_MAPA_MASK)
/*! @} */

/*! @name D_DTAP - IDM Access Configuration */
/*! @{ */

#define ACCESS_PROTECTION_D_DTAP_AP_MASK         (0x7U)
#define ACCESS_PROTECTION_D_DTAP_AP_SHIFT        (0U)
#define ACCESS_PROTECTION_D_DTAP_AP_WIDTH        (3U)
#define ACCESS_PROTECTION_D_DTAP_AP(x)           (((uint32_t)(((uint32_t)(x)) << ACCESS_PROTECTION_D_DTAP_AP_SHIFT)) & ACCESS_PROTECTION_D_DTAP_AP_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ACCESS_PROTECTION_Register_Masks */

/*!
 * @}
 */ /* end of group ACCESS_PROTECTION_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ACCESS_PROTECTION_H_) */
