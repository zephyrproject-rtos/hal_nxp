/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_DMAMUX.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_DMAMUX
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
#if !defined(S32K566_DMAMUX_H_)  /* Check if memory map has not been already included */
#define S32K566_DMAMUX_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Size of Registers Arrays */
#define DMAMUX_CHCFG_REG_ARRAY_COUNT              16u

/** DMAMUX - Register Layout Typedef */
typedef struct DMAMUX_Struct {
  __IO uint32_t CHCFG[DMAMUX_CHCFG_REG_ARRAY_COUNT]; /**< Channel 0 Configuration..Channel 15 Configuration, array offset: 0x0, array step: 0x4 */
} DMAMUX_Type, *DMAMUX_MemMapPtr;

/** Number of instances of the DMAMUX module. */
#define DMAMUX_INSTANCE_COUNT                    (3u)

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX_0 base address */
#define IP_DMAMUX_0_BASE                         (0x4040C000u)
/** Peripheral DMAMUX_0 base pointer */
#define IP_DMAMUX_0                              ((DMAMUX_Type *)IP_DMAMUX_0_BASE)
/** Peripheral DMAMUX_1 base address */
#define IP_DMAMUX_1_BASE                         (0x40A08000u)
/** Peripheral DMAMUX_1 base pointer */
#define IP_DMAMUX_1                              ((DMAMUX_Type *)IP_DMAMUX_1_BASE)
/** Peripheral LPE_DMAMUX base address */
#define IP_LPE_DMAMUX_BASE                       (0x42004000u)
/** Peripheral LPE_DMAMUX base pointer */
#define IP_LPE_DMAMUX                            ((DMAMUX_Type *)IP_LPE_DMAMUX_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define IP_DMAMUX_BASE_ADDRS                     { IP_DMAMUX_0_BASE, IP_DMAMUX_1_BASE, IP_LPE_DMAMUX_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define IP_DMAMUX_BASE_PTRS                      { IP_DMAMUX_0, IP_DMAMUX_1, IP_LPE_DMAMUX }

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCFG - Channel 0 Configuration..Channel 15 Configuration */
/*! @{ */

#define DMAMUX_CHCFG_SOURCE_MASK                 (0xFFU)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)
#define DMAMUX_CHCFG_SOURCE_WIDTH                (8U)
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_SOURCE_SHIFT)) & DMAMUX_CHCFG_SOURCE_MASK)  /* Merged from fields with different position or width, of widths (6, 8), largest definition used */

#define DMAMUX_CHCFG_A_ON_MASK                   (0x20000000U)
#define DMAMUX_CHCFG_A_ON_SHIFT                  (29U)
#define DMAMUX_CHCFG_A_ON_WIDTH                  (1U)
#define DMAMUX_CHCFG_A_ON(x)                     (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_A_ON_SHIFT)) & DMAMUX_CHCFG_A_ON_MASK)

#define DMAMUX_CHCFG_TRIG_MASK                   (0x40000000U)
#define DMAMUX_CHCFG_TRIG_SHIFT                  (30U)
#define DMAMUX_CHCFG_TRIG_WIDTH                  (1U)
#define DMAMUX_CHCFG_TRIG(x)                     (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_TRIG_SHIFT)) & DMAMUX_CHCFG_TRIG_MASK)

#define DMAMUX_CHCFG_ENBL_MASK                   (0x80000000U)
#define DMAMUX_CHCFG_ENBL_SHIFT                  (31U)
#define DMAMUX_CHCFG_ENBL_WIDTH                  (1U)
#define DMAMUX_CHCFG_ENBL(x)                     (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_ENBL_SHIFT)) & DMAMUX_CHCFG_ENBL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */

/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_DMAMUX_H_) */
