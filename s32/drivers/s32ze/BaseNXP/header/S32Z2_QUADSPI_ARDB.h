/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_QuadSPI_ARDB.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_QuadSPI_ARDB
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
#if !defined(S32Z2_QuadSPI_ARDB_H_)  /* Check if memory map has not been already included */
#define S32Z2_QuadSPI_ARDB_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- QuadSPI_ARDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QuadSPI_ARDB_Peripheral_Access_Layer QuadSPI_ARDB Peripheral Access Layer
 * @{
 */

/** QuadSPI_ARDB - Size of Registers Arrays */
#define QuadSPI_ARDB_ARDB_COUNT                   128u

/** QuadSPI_ARDB - Register Layout Typedef */
typedef struct {
  __I  uint32_t ARDB[QuadSPI_ARDB_ARDB_COUNT];     /**< AHB RX Data Buffer Register, array offset: 0x0, array step: 0x4 */
} QuadSPI_ARDB_Type, *QuadSPI_ARDB_MemMapPtr;

/** Number of instances of the QuadSPI_ARDB module. */
#define QuadSPI_ARDB_INSTANCE_COUNT              (2u)

/* QuadSPI_ARDB - Peripheral instance base addresses */
/** Peripheral QUADSPI_0_ARDB base address */
#define IP_QUADSPI_0_ARDB_BASE                   (0x70000000u)
/** Peripheral QUADSPI_0_ARDB base pointer */
#define IP_QUADSPI_0_ARDB                        ((QuadSPI_ARDB_Type *)IP_QUADSPI_0_ARDB_BASE)
/** Peripheral QUADSPI_1_ARDB base address */
#define IP_QUADSPI_1_ARDB_BASE                   (0x71000000u)
/** Peripheral QUADSPI_1_ARDB base pointer */
#define IP_QUADSPI_1_ARDB                        ((QuadSPI_ARDB_Type *)IP_QUADSPI_1_ARDB_BASE)
/** Array initializer of QuadSPI_ARDB peripheral base addresses */
#define IP_QuadSPI_ARDB_BASE_ADDRS               { IP_QUADSPI_0_ARDB_BASE, IP_QUADSPI_1_ARDB_BASE }
/** Array initializer of QuadSPI_ARDB peripheral base pointers */
#define IP_QuadSPI_ARDB_BASE_PTRS                { IP_QUADSPI_0_ARDB, IP_QUADSPI_1_ARDB }

/* ----------------------------------------------------------------------------
   -- QuadSPI_ARDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QuadSPI_ARDB_Register_Masks QuadSPI_ARDB Register Masks
 * @{
 */

/*! @name ARDB - AHB RX Data Buffer Register */
/*! @{ */

#define QuadSPI_ARDB_ARDB_ARXD_MASK              (0xFFFFFFFFU)
#define QuadSPI_ARDB_ARDB_ARXD_SHIFT             (0U)
#define QuadSPI_ARDB_ARDB_ARXD_WIDTH             (32U)
#define QuadSPI_ARDB_ARDB_ARXD(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_ARDB_ARDB_ARXD_SHIFT)) & QuadSPI_ARDB_ARDB_ARXD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group QuadSPI_ARDB_Register_Masks */

/*!
 * @}
 */ /* end of group QuadSPI_ARDB_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_QuadSPI_ARDB_H_) */
