/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_POWER_SCALING_UNIT.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_POWER_SCALING_UNIT
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
#if !defined(S32Z2_POWER_SCALING_UNIT_H_)  /* Check if memory map has not been already included */
#define S32Z2_POWER_SCALING_UNIT_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- POWER_SCALING_UNIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWER_SCALING_UNIT_Peripheral_Access_Layer POWER_SCALING_UNIT Peripheral Access Layer
 * @{
 */

/** POWER_SCALING_UNIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t PSVM;                              /**< PSU Power Save Mode Register, offset: 0x0 */
  __IO uint32_t PGR;                               /**< PSU General Register, offset: 0x4 */
} POWER_SCALING_UNIT_Type, *POWER_SCALING_UNIT_MemMapPtr;

/** Number of instances of the POWER_SCALING_UNIT module. */
#define POWER_SCALING_UNIT_INSTANCE_COUNT        (1u)

/* POWER_SCALING_UNIT - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__POWER_SCALING_UNIT base address */
#define IP_CEVA_SPF2__POWER_SCALING_UNIT_BASE    (0x24400E50u)
/** Peripheral CEVA_SPF2__POWER_SCALING_UNIT base pointer */
#define IP_CEVA_SPF2__POWER_SCALING_UNIT         ((POWER_SCALING_UNIT_Type *)IP_CEVA_SPF2__POWER_SCALING_UNIT_BASE)
/** Array initializer of POWER_SCALING_UNIT peripheral base addresses */
#define IP_POWER_SCALING_UNIT_BASE_ADDRS         { IP_CEVA_SPF2__POWER_SCALING_UNIT_BASE }
/** Array initializer of POWER_SCALING_UNIT peripheral base pointers */
#define IP_POWER_SCALING_UNIT_BASE_PTRS          { IP_CEVA_SPF2__POWER_SCALING_UNIT }

/* ----------------------------------------------------------------------------
   -- POWER_SCALING_UNIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWER_SCALING_UNIT_Register_Masks POWER_SCALING_UNIT Register Masks
 * @{
 */

/*! @name PSVM - PSU Power Save Mode Register */
/*! @{ */

#define POWER_SCALING_UNIT_PSVM_PMOD_MASK        (0x3U)
#define POWER_SCALING_UNIT_PSVM_PMOD_SHIFT       (0U)
#define POWER_SCALING_UNIT_PSVM_PMOD_WIDTH       (2U)
#define POWER_SCALING_UNIT_PSVM_PMOD(x)          (((uint32_t)(((uint32_t)(x)) << POWER_SCALING_UNIT_PSVM_PMOD_SHIFT)) & POWER_SCALING_UNIT_PSVM_PMOD_MASK)

#define POWER_SCALING_UNIT_PSVM_DBC_MASK         (0x4U)
#define POWER_SCALING_UNIT_PSVM_DBC_SHIFT        (2U)
#define POWER_SCALING_UNIT_PSVM_DBC_WIDTH        (1U)
#define POWER_SCALING_UNIT_PSVM_DBC(x)           (((uint32_t)(((uint32_t)(x)) << POWER_SCALING_UNIT_PSVM_DBC_SHIFT)) & POWER_SCALING_UNIT_PSVM_DBC_MASK)
/*! @} */

/*! @name PGR - PSU General Register */
/*! @{ */

#define POWER_SCALING_UNIT_PGR_MSS_AE_MASK       (0x4U)
#define POWER_SCALING_UNIT_PGR_MSS_AE_SHIFT      (2U)
#define POWER_SCALING_UNIT_PGR_MSS_AE_WIDTH      (1U)
#define POWER_SCALING_UNIT_PGR_MSS_AE(x)         (((uint32_t)(((uint32_t)(x)) << POWER_SCALING_UNIT_PGR_MSS_AE_SHIFT)) & POWER_SCALING_UNIT_PGR_MSS_AE_MASK)

#define POWER_SCALING_UNIT_PGR_EDAP_AE_MASK      (0x8U)
#define POWER_SCALING_UNIT_PGR_EDAP_AE_SHIFT     (3U)
#define POWER_SCALING_UNIT_PGR_EDAP_AE_WIDTH     (1U)
#define POWER_SCALING_UNIT_PGR_EDAP_AE(x)        (((uint32_t)(((uint32_t)(x)) << POWER_SCALING_UNIT_PGR_EDAP_AE_SHIFT)) & POWER_SCALING_UNIT_PGR_EDAP_AE_MASK)

#define POWER_SCALING_UNIT_PGR_QMAN_AE_MASK      (0x80U)
#define POWER_SCALING_UNIT_PGR_QMAN_AE_SHIFT     (7U)
#define POWER_SCALING_UNIT_PGR_QMAN_AE_WIDTH     (1U)
#define POWER_SCALING_UNIT_PGR_QMAN_AE(x)        (((uint32_t)(((uint32_t)(x)) << POWER_SCALING_UNIT_PGR_QMAN_AE_SHIFT)) & POWER_SCALING_UNIT_PGR_QMAN_AE_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group POWER_SCALING_UNIT_Register_Masks */

/*!
 * @}
 */ /* end of group POWER_SCALING_UNIT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_POWER_SCALING_UNIT_H_) */
