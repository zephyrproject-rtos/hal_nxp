/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K344_PRAMC.h
 * @version 1.9
 * @date 2021-10-27
 * @brief Peripheral Access Layer for S32K344_PRAMC
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
#if !defined(S32K344_PRAMC_H_)  /* Check if memory map has not been already included */
#define S32K344_PRAMC_H_

#include "S32K344_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PRAMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PRAMC_Peripheral_Access_Layer PRAMC Peripheral Access Layer
 * @{
 */

/** PRAMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PRCR1;                             /**< Platform RAM Configuration register 1, offset: 0x0 */
} PRAMC_Type, *PRAMC_MemMapPtr;

/** Number of instances of the PRAMC module. */
#define PRAMC_INSTANCE_COUNT                     (2u)

/* PRAMC - Peripheral instance base addresses */
/** Peripheral PRAMC_0 base address */
#define IP_PRAMC_0_BASE                          (0x40264000u)
/** Peripheral PRAMC_0 base pointer */
#define IP_PRAMC_0                               ((PRAMC_Type *)IP_PRAMC_0_BASE)
/** Peripheral PRAMC_1 base address */
#define IP_PRAMC_1_BASE                          (0x40464000u)
/** Peripheral PRAMC_1 base pointer */
#define IP_PRAMC_1                               ((PRAMC_Type *)IP_PRAMC_1_BASE)
/** Array initializer of PRAMC peripheral base addresses */
#define IP_PRAMC_BASE_ADDRS                      { IP_PRAMC_0_BASE, IP_PRAMC_1_BASE }
/** Array initializer of PRAMC peripheral base pointers */
#define IP_PRAMC_BASE_PTRS                       { IP_PRAMC_0, IP_PRAMC_1 }

/* ----------------------------------------------------------------------------
   -- PRAMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PRAMC_Register_Masks PRAMC Register Masks
 * @{
 */

/*! @name PRCR1 - Platform RAM Configuration register 1 */
/*! @{ */

#define PRAMC_PRCR1_FT_DIS_MASK                  (0x1U)
#define PRAMC_PRCR1_FT_DIS_SHIFT                 (0U)
#define PRAMC_PRCR1_FT_DIS_WIDTH                 (1U)
#define PRAMC_PRCR1_FT_DIS(x)                    (((uint32_t)(((uint32_t)(x)) << PRAMC_PRCR1_FT_DIS_SHIFT)) & PRAMC_PRCR1_FT_DIS_MASK)

#define PRAMC_PRCR1_P0_BO_DIS_MASK               (0x40U)
#define PRAMC_PRCR1_P0_BO_DIS_SHIFT              (6U)
#define PRAMC_PRCR1_P0_BO_DIS_WIDTH              (1U)
#define PRAMC_PRCR1_P0_BO_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << PRAMC_PRCR1_P0_BO_DIS_SHIFT)) & PRAMC_PRCR1_P0_BO_DIS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PRAMC_Register_Masks */

/*!
 * @}
 */ /* end of group PRAMC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K344_PRAMC_H_) */
