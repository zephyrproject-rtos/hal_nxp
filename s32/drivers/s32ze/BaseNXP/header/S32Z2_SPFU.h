/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SPFU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SPFU
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
#if !defined(S32Z2_SPFU_H_)  /* Check if memory map has not been already included */
#define S32Z2_SPFU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SPFU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPFU_Peripheral_Access_Layer SPFU Peripheral Access Layer
 * @{
 */

/** SPFU - Size of Registers Arrays */
#define SPFU_PFN_COUNT                            5u

/** SPFU - Register Layout Typedef */
typedef struct {
  struct SPFU_PFN {                                /* offset: 0x0, array step: 0x100 */
    __IO uint32_t PF_CFG;                            /**< Prefetch Configuration, array offset: 0x0, array step: 0x100 */
    uint8_t RESERVED_0[252];
  } PFN[SPFU_PFN_COUNT];
} SPFU_Type, *SPFU_MemMapPtr;

/** Number of instances of the SPFU module. */
#define SPFU_INSTANCE_COUNT                      (2u)

/* SPFU - Peripheral instance base addresses */
/** Peripheral RTU0__SPFU base address */
#define IP_RTU0__SPFU_BASE                       (0x76060000u)
/** Peripheral RTU0__SPFU base pointer */
#define IP_RTU0__SPFU                            ((SPFU_Type *)IP_RTU0__SPFU_BASE)
/** Peripheral RTU1__SPFU base address */
#define IP_RTU1__SPFU_BASE                       (0x76860000u)
/** Peripheral RTU1__SPFU base pointer */
#define IP_RTU1__SPFU                            ((SPFU_Type *)IP_RTU1__SPFU_BASE)
/** Array initializer of SPFU peripheral base addresses */
#define IP_SPFU_BASE_ADDRS                       { IP_RTU0__SPFU_BASE, IP_RTU1__SPFU_BASE }
/** Array initializer of SPFU peripheral base pointers */
#define IP_SPFU_BASE_PTRS                        { IP_RTU0__SPFU, IP_RTU1__SPFU }

/* ----------------------------------------------------------------------------
   -- SPFU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPFU_Register_Masks SPFU Register Masks
 * @{
 */

/*! @name PF_CFG - Prefetch Configuration */
/*! @{ */

#define SPFU_PF_CFG_PFEN_MASK                    (0x1U)
#define SPFU_PF_CFG_PFEN_SHIFT                   (0U)
#define SPFU_PF_CFG_PFEN_WIDTH                   (1U)
#define SPFU_PF_CFG_PFEN(x)                      (((uint32_t)(((uint32_t)(x)) << SPFU_PF_CFG_PFEN_SHIFT)) & SPFU_PF_CFG_PFEN_MASK)

#define SPFU_PF_CFG_DID_MASK                     (0xF00U)
#define SPFU_PF_CFG_DID_SHIFT                    (8U)
#define SPFU_PF_CFG_DID_WIDTH                    (4U)
#define SPFU_PF_CFG_DID(x)                       (((uint32_t)(((uint32_t)(x)) << SPFU_PF_CFG_DID_SHIFT)) & SPFU_PF_CFG_DID_MASK)

#define SPFU_PF_CFG_THRSHLD_MASK                 (0xF0000U)
#define SPFU_PF_CFG_THRSHLD_SHIFT                (16U)
#define SPFU_PF_CFG_THRSHLD_WIDTH                (4U)
#define SPFU_PF_CFG_THRSHLD(x)                   (((uint32_t)(((uint32_t)(x)) << SPFU_PF_CFG_THRSHLD_SHIFT)) & SPFU_PF_CFG_THRSHLD_MASK)

#define SPFU_PF_CFG_PF_SIZE_MASK                 (0xF000000U)
#define SPFU_PF_CFG_PF_SIZE_SHIFT                (24U)
#define SPFU_PF_CFG_PF_SIZE_WIDTH                (4U)
#define SPFU_PF_CFG_PF_SIZE(x)                   (((uint32_t)(((uint32_t)(x)) << SPFU_PF_CFG_PF_SIZE_SHIFT)) & SPFU_PF_CFG_PF_SIZE_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SPFU_Register_Masks */

/*!
 * @}
 */ /* end of group SPFU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SPFU_H_) */
