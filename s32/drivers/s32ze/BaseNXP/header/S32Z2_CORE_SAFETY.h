/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CORE_SAFETY.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CORE_SAFETY
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
#if !defined(S32Z2_CORE_SAFETY_H_)  /* Check if memory map has not been already included */
#define S32Z2_CORE_SAFETY_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CORE_SAFETY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORE_SAFETY_Peripheral_Access_Layer CORE_SAFETY Peripheral Access Layer
 * @{
 */

/** CORE_SAFETY - Register Layout Typedef */
typedef struct {
  __IO uint32_t C_UCPERR;                          /**< Core UCP ERR Register, offset: 0x0 */
  __O  uint32_t C_UCPERR_S;                        /**< Core UCP ERR Shadow Register, offset: 0x4 */
} CORE_SAFETY_Type, *CORE_SAFETY_MemMapPtr;

/** Number of instances of the CORE_SAFETY module. */
#define CORE_SAFETY_INSTANCE_COUNT               (1u)

/* CORE_SAFETY - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__CORE_SAFETY base address */
#define IP_CEVA_SPF2__CORE_SAFETY_BASE           (0x24400750u)
/** Peripheral CEVA_SPF2__CORE_SAFETY base pointer */
#define IP_CEVA_SPF2__CORE_SAFETY                ((CORE_SAFETY_Type *)IP_CEVA_SPF2__CORE_SAFETY_BASE)
/** Array initializer of CORE_SAFETY peripheral base addresses */
#define IP_CORE_SAFETY_BASE_ADDRS                { IP_CEVA_SPF2__CORE_SAFETY_BASE }
/** Array initializer of CORE_SAFETY peripheral base pointers */
#define IP_CORE_SAFETY_BASE_PTRS                 { IP_CEVA_SPF2__CORE_SAFETY }

/* ----------------------------------------------------------------------------
   -- CORE_SAFETY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORE_SAFETY_Register_Masks CORE_SAFETY Register Masks
 * @{
 */

/*! @name C_UCPERR - Core UCP ERR Register */
/*! @{ */

#define CORE_SAFETY_C_UCPERR_C_UCPERR_MASK       (0x1U)
#define CORE_SAFETY_C_UCPERR_C_UCPERR_SHIFT      (0U)
#define CORE_SAFETY_C_UCPERR_C_UCPERR_WIDTH      (1U)
#define CORE_SAFETY_C_UCPERR_C_UCPERR(x)         (((uint32_t)(((uint32_t)(x)) << CORE_SAFETY_C_UCPERR_C_UCPERR_SHIFT)) & CORE_SAFETY_C_UCPERR_C_UCPERR_MASK)

#define CORE_SAFETY_C_UCPERR_P_ECC_ERR_MASK      (0x2U)
#define CORE_SAFETY_C_UCPERR_P_ECC_ERR_SHIFT     (1U)
#define CORE_SAFETY_C_UCPERR_P_ECC_ERR_WIDTH     (1U)
#define CORE_SAFETY_C_UCPERR_P_ECC_ERR(x)        (((uint32_t)(((uint32_t)(x)) << CORE_SAFETY_C_UCPERR_P_ECC_ERR_SHIFT)) & CORE_SAFETY_C_UCPERR_P_ECC_ERR_MASK)

#define CORE_SAFETY_C_UCPERR_P_EAC_ERR_MASK      (0x8U)
#define CORE_SAFETY_C_UCPERR_P_EAC_ERR_SHIFT     (3U)
#define CORE_SAFETY_C_UCPERR_P_EAC_ERR_WIDTH     (1U)
#define CORE_SAFETY_C_UCPERR_P_EAC_ERR(x)        (((uint32_t)(((uint32_t)(x)) << CORE_SAFETY_C_UCPERR_P_EAC_ERR_SHIFT)) & CORE_SAFETY_C_UCPERR_P_EAC_ERR_MASK)

#define CORE_SAFETY_C_UCPERR_C_ILPE_MASK         (0x100U)
#define CORE_SAFETY_C_UCPERR_C_ILPE_SHIFT        (8U)
#define CORE_SAFETY_C_UCPERR_C_ILPE_WIDTH        (1U)
#define CORE_SAFETY_C_UCPERR_C_ILPE(x)           (((uint32_t)(((uint32_t)(x)) << CORE_SAFETY_C_UCPERR_C_ILPE_SHIFT)) & CORE_SAFETY_C_UCPERR_C_ILPE_MASK)
/*! @} */

/*! @name C_UCPERR_S - Core UCP ERR Shadow Register */
/*! @{ */

#define CORE_SAFETY_C_UCPERR_S_P_ECC_ERR_S_MASK  (0x2U)
#define CORE_SAFETY_C_UCPERR_S_P_ECC_ERR_S_SHIFT (1U)
#define CORE_SAFETY_C_UCPERR_S_P_ECC_ERR_S_WIDTH (1U)
#define CORE_SAFETY_C_UCPERR_S_P_ECC_ERR_S(x)    (((uint32_t)(((uint32_t)(x)) << CORE_SAFETY_C_UCPERR_S_P_ECC_ERR_S_SHIFT)) & CORE_SAFETY_C_UCPERR_S_P_ECC_ERR_S_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CORE_SAFETY_Register_Masks */

/*!
 * @}
 */ /* end of group CORE_SAFETY_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CORE_SAFETY_H_) */
