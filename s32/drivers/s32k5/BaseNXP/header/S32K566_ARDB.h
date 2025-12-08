/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_ARDB.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_ARDB
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
#if !defined(S32K566_ARDB_H_)  /* Check if memory map has not been already included */
#define S32K566_ARDB_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ARDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ARDB_Peripheral_Access_Layer ARDB Peripheral Access Layer
 * @{
 */

/** ARDB - Size of Registers Arrays */
#define ARDB_ARDB_COUNT                           128u

/** ARDB - Register Layout Typedef */
typedef struct ARDB_Struct {
  __I  uint32_t ARDB[ARDB_ARDB_COUNT];             /**< AHB RX Data Buffer Register, array offset: 0x0, array step: 0x4 */
} ARDB_Type, *ARDB_MemMapPtr;

/** Number of instances of the ARDB module. */
#define ARDB_INSTANCE_COUNT                      (1u)

/* ARDB - Peripheral instance base addresses */
/** Peripheral XSPI__ARDB base address */
#define IP_XSPI__ARDB_BASE                       (0x61000000u)
/** Peripheral XSPI__ARDB base pointer */
#define IP_XSPI__ARDB                            ((ARDB_Type *)IP_XSPI__ARDB_BASE)
/** Array initializer of ARDB peripheral base addresses */
#define IP_ARDB_BASE_ADDRS                       { IP_XSPI__ARDB_BASE }
/** Array initializer of ARDB peripheral base pointers */
#define IP_ARDB_BASE_PTRS                        { IP_XSPI__ARDB }

/* ----------------------------------------------------------------------------
   -- ARDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ARDB_Register_Masks ARDB Register Masks
 * @{
 */

/*! @name ARDB - AHB RX Data Buffer Register */
/*! @{ */

#define ARDB_ARDB_ARXD_MASK                      (0xFFFFFFFFU)
#define ARDB_ARDB_ARXD_SHIFT                     (0U)
#define ARDB_ARDB_ARXD_WIDTH                     (32U)
#define ARDB_ARDB_ARXD(x)                        (((uint32_t)(((uint32_t)(x)) << ARDB_ARDB_ARXD_SHIFT)) & ARDB_ARDB_ARXD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ARDB_Register_Masks */

/*!
 * @}
 */ /* end of group ARDB_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_ARDB_H_) */
