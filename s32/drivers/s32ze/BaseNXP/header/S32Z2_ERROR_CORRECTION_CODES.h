/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ERROR_CORRECTION_CODES.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_ERROR_CORRECTION_CODES
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
#if !defined(S32Z2_ERROR_CORRECTION_CODES_H_)  /* Check if memory map has not been already included */
#define S32Z2_ERROR_CORRECTION_CODES_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ERROR_CORRECTION_CODES Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERROR_CORRECTION_CODES_Peripheral_Access_Layer ERROR_CORRECTION_CODES Peripheral Access Layer
 * @{
 */

/** ERROR_CORRECTION_CODES - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[4];
  __I  uint32_t D_ECCCOR;                          /**< ECC Correctable Error Address, offset: 0x4 */
  __I  uint32_t D_ECCERR;                          /**< ECC Uncorrectable Error Address, offset: 0x8 */
} ERROR_CORRECTION_CODES_Type, *ERROR_CORRECTION_CODES_MemMapPtr;

/** Number of instances of the ERROR_CORRECTION_CODES module. */
#define ERROR_CORRECTION_CODES_INSTANCE_COUNT    (1u)

/* ERROR_CORRECTION_CODES - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__ERROR_CORRECTION_CODES base address */
#define IP_CEVA_SPF2__ERROR_CORRECTION_CODES_BASE (0x24400780u)
/** Peripheral CEVA_SPF2__ERROR_CORRECTION_CODES base pointer */
#define IP_CEVA_SPF2__ERROR_CORRECTION_CODES     ((ERROR_CORRECTION_CODES_Type *)IP_CEVA_SPF2__ERROR_CORRECTION_CODES_BASE)
/** Array initializer of ERROR_CORRECTION_CODES peripheral base addresses */
#define IP_ERROR_CORRECTION_CODES_BASE_ADDRS     { IP_CEVA_SPF2__ERROR_CORRECTION_CODES_BASE }
/** Array initializer of ERROR_CORRECTION_CODES peripheral base pointers */
#define IP_ERROR_CORRECTION_CODES_BASE_PTRS      { IP_CEVA_SPF2__ERROR_CORRECTION_CODES }

/* ----------------------------------------------------------------------------
   -- ERROR_CORRECTION_CODES Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERROR_CORRECTION_CODES_Register_Masks ERROR_CORRECTION_CODES Register Masks
 * @{
 */

/*! @name D_ECCCOR - ECC Correctable Error Address */
/*! @{ */

#define ERROR_CORRECTION_CODES_D_ECCCOR_D_ECCCORADD_MASK (0xFFFFFFFCU)
#define ERROR_CORRECTION_CODES_D_ECCCOR_D_ECCCORADD_SHIFT (2U)
#define ERROR_CORRECTION_CODES_D_ECCCOR_D_ECCCORADD_WIDTH (30U)
#define ERROR_CORRECTION_CODES_D_ECCCOR_D_ECCCORADD(x) (((uint32_t)(((uint32_t)(x)) << ERROR_CORRECTION_CODES_D_ECCCOR_D_ECCCORADD_SHIFT)) & ERROR_CORRECTION_CODES_D_ECCCOR_D_ECCCORADD_MASK)
/*! @} */

/*! @name D_ECCERR - ECC Uncorrectable Error Address */
/*! @{ */

#define ERROR_CORRECTION_CODES_D_ECCERR_D_ECCERRADD_MASK (0xFFFFFFFCU)
#define ERROR_CORRECTION_CODES_D_ECCERR_D_ECCERRADD_SHIFT (2U)
#define ERROR_CORRECTION_CODES_D_ECCERR_D_ECCERRADD_WIDTH (30U)
#define ERROR_CORRECTION_CODES_D_ECCERR_D_ECCERRADD(x) (((uint32_t)(((uint32_t)(x)) << ERROR_CORRECTION_CODES_D_ECCERR_D_ECCERRADD_SHIFT)) & ERROR_CORRECTION_CODES_D_ECCERR_D_ECCERRADD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ERROR_CORRECTION_CODES_Register_Masks */

/*!
 * @}
 */ /* end of group ERROR_CORRECTION_CODES_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ERROR_CORRECTION_CODES_H_) */
