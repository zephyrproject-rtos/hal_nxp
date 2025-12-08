/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LMEM_CACHE.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LMEM_CACHE
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
#if !defined(S32K566_LMEM_CACHE_H_)  /* Check if memory map has not been already included */
#define S32K566_LMEM_CACHE_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LMEM_CACHE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_CACHE_Peripheral_Access_Layer LMEM_CACHE Peripheral Access Layer
 * @{
 */

/** LMEM_CACHE - Register Layout Typedef */
typedef struct LMEM_CACHE_Struct {
  __IO uint32_t PCCCR;                             /**< Cache control register, offset: 0x0 */
  __IO uint32_t PCCLCR;                            /**< Cache line control register, offset: 0x4 */
  __IO uint32_t PCCSAR;                            /**< Cache search address register, offset: 0x8 */
  __IO uint32_t PCCCVR;                            /**< Cache read/write value register, offset: 0xC */
  uint8_t RESERVED_0[16];
  __IO uint32_t PCCRMR;                            /**< Cache regions mode register, offset: 0x20 */
} LMEM_CACHE_Type, *LMEM_CACHE_MemMapPtr;

/** Number of instances of the LMEM_CACHE module. */
#define LMEM_CACHE_INSTANCE_COUNT                (1u)

/* LMEM_CACHE - Peripheral instance base addresses */
/** Peripheral LMEM_CACHE base address */
#define IP_LMEM_CACHE_BASE                       (0xE0082000u)
/** Peripheral LMEM_CACHE base pointer */
#define IP_LMEM_CACHE                            ((LMEM_CACHE_Type *)IP_LMEM_CACHE_BASE)
/** Array initializer of LMEM_CACHE peripheral base addresses */
#define IP_LMEM_CACHE_BASE_ADDRS                 { IP_LMEM_CACHE_BASE }
/** Array initializer of LMEM_CACHE peripheral base pointers */
#define IP_LMEM_CACHE_BASE_PTRS                  { IP_LMEM_CACHE }

/* ----------------------------------------------------------------------------
   -- LMEM_CACHE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_CACHE_Register_Masks LMEM_CACHE Register Masks
 * @{
 */

/*! @name PCCCR - Cache control register */
/*! @{ */

#define LMEM_CACHE_PCCCR_ENCACHE_MASK            (0x1U)
#define LMEM_CACHE_PCCCR_ENCACHE_SHIFT           (0U)
#define LMEM_CACHE_PCCCR_ENCACHE_WIDTH           (1U)
#define LMEM_CACHE_PCCCR_ENCACHE(x)              (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_ENCACHE_SHIFT)) & LMEM_CACHE_PCCCR_ENCACHE_MASK)

#define LMEM_CACHE_PCCCR_PCCR2_MASK              (0x4U)
#define LMEM_CACHE_PCCCR_PCCR2_SHIFT             (2U)
#define LMEM_CACHE_PCCCR_PCCR2_WIDTH             (1U)
#define LMEM_CACHE_PCCCR_PCCR2(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_PCCR2_SHIFT)) & LMEM_CACHE_PCCCR_PCCR2_MASK)

#define LMEM_CACHE_PCCCR_PCCR3_MASK              (0x8U)
#define LMEM_CACHE_PCCCR_PCCR3_SHIFT             (3U)
#define LMEM_CACHE_PCCCR_PCCR3_WIDTH             (1U)
#define LMEM_CACHE_PCCCR_PCCR3(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_PCCR3_SHIFT)) & LMEM_CACHE_PCCCR_PCCR3_MASK)

#define LMEM_CACHE_PCCCR_INVW0_MASK              (0x1000000U)
#define LMEM_CACHE_PCCCR_INVW0_SHIFT             (24U)
#define LMEM_CACHE_PCCCR_INVW0_WIDTH             (1U)
#define LMEM_CACHE_PCCCR_INVW0(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_INVW0_SHIFT)) & LMEM_CACHE_PCCCR_INVW0_MASK)

#define LMEM_CACHE_PCCCR_PUSHW0_MASK             (0x2000000U)
#define LMEM_CACHE_PCCCR_PUSHW0_SHIFT            (25U)
#define LMEM_CACHE_PCCCR_PUSHW0_WIDTH            (1U)
#define LMEM_CACHE_PCCCR_PUSHW0(x)               (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_PUSHW0_SHIFT)) & LMEM_CACHE_PCCCR_PUSHW0_MASK)

#define LMEM_CACHE_PCCCR_INVW1_MASK              (0x4000000U)
#define LMEM_CACHE_PCCCR_INVW1_SHIFT             (26U)
#define LMEM_CACHE_PCCCR_INVW1_WIDTH             (1U)
#define LMEM_CACHE_PCCCR_INVW1(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_INVW1_SHIFT)) & LMEM_CACHE_PCCCR_INVW1_MASK)

#define LMEM_CACHE_PCCCR_PUSHW1_MASK             (0x8000000U)
#define LMEM_CACHE_PCCCR_PUSHW1_SHIFT            (27U)
#define LMEM_CACHE_PCCCR_PUSHW1_WIDTH            (1U)
#define LMEM_CACHE_PCCCR_PUSHW1(x)               (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_PUSHW1_SHIFT)) & LMEM_CACHE_PCCCR_PUSHW1_MASK)

#define LMEM_CACHE_PCCCR_GO_MASK                 (0x80000000U)
#define LMEM_CACHE_PCCCR_GO_SHIFT                (31U)
#define LMEM_CACHE_PCCCR_GO_WIDTH                (1U)
#define LMEM_CACHE_PCCCR_GO(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCR_GO_SHIFT)) & LMEM_CACHE_PCCCR_GO_MASK)
/*! @} */

/*! @name PCCLCR - Cache line control register */
/*! @{ */

#define LMEM_CACHE_PCCLCR_LGO_MASK               (0x1U)
#define LMEM_CACHE_PCCLCR_LGO_SHIFT              (0U)
#define LMEM_CACHE_PCCLCR_LGO_WIDTH              (1U)
#define LMEM_CACHE_PCCLCR_LGO(x)                 (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_LGO_SHIFT)) & LMEM_CACHE_PCCLCR_LGO_MASK)

#define LMEM_CACHE_PCCLCR_CACHEADDR_MASK         (0x3FFCU)
#define LMEM_CACHE_PCCLCR_CACHEADDR_SHIFT        (2U)
#define LMEM_CACHE_PCCLCR_CACHEADDR_WIDTH        (12U)
#define LMEM_CACHE_PCCLCR_CACHEADDR(x)           (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_CACHEADDR_SHIFT)) & LMEM_CACHE_PCCLCR_CACHEADDR_MASK)

#define LMEM_CACHE_PCCLCR_WSEL_MASK              (0x4000U)
#define LMEM_CACHE_PCCLCR_WSEL_SHIFT             (14U)
#define LMEM_CACHE_PCCLCR_WSEL_WIDTH             (1U)
#define LMEM_CACHE_PCCLCR_WSEL(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_WSEL_SHIFT)) & LMEM_CACHE_PCCLCR_WSEL_MASK)

#define LMEM_CACHE_PCCLCR_TDSEL_MASK             (0x10000U)
#define LMEM_CACHE_PCCLCR_TDSEL_SHIFT            (16U)
#define LMEM_CACHE_PCCLCR_TDSEL_WIDTH            (1U)
#define LMEM_CACHE_PCCLCR_TDSEL(x)               (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_TDSEL_SHIFT)) & LMEM_CACHE_PCCLCR_TDSEL_MASK)

#define LMEM_CACHE_PCCLCR_LCIVB_MASK             (0x100000U)
#define LMEM_CACHE_PCCLCR_LCIVB_SHIFT            (20U)
#define LMEM_CACHE_PCCLCR_LCIVB_WIDTH            (1U)
#define LMEM_CACHE_PCCLCR_LCIVB(x)               (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_LCIVB_SHIFT)) & LMEM_CACHE_PCCLCR_LCIVB_MASK)

#define LMEM_CACHE_PCCLCR_LCIMB_MASK             (0x200000U)
#define LMEM_CACHE_PCCLCR_LCIMB_SHIFT            (21U)
#define LMEM_CACHE_PCCLCR_LCIMB_WIDTH            (1U)
#define LMEM_CACHE_PCCLCR_LCIMB(x)               (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_LCIMB_SHIFT)) & LMEM_CACHE_PCCLCR_LCIMB_MASK)

#define LMEM_CACHE_PCCLCR_LCWAY_MASK             (0x400000U)
#define LMEM_CACHE_PCCLCR_LCWAY_SHIFT            (22U)
#define LMEM_CACHE_PCCLCR_LCWAY_WIDTH            (1U)
#define LMEM_CACHE_PCCLCR_LCWAY(x)               (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_LCWAY_SHIFT)) & LMEM_CACHE_PCCLCR_LCWAY_MASK)

#define LMEM_CACHE_PCCLCR_LCMD_MASK              (0x3000000U)
#define LMEM_CACHE_PCCLCR_LCMD_SHIFT             (24U)
#define LMEM_CACHE_PCCLCR_LCMD_WIDTH             (2U)
#define LMEM_CACHE_PCCLCR_LCMD(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_LCMD_SHIFT)) & LMEM_CACHE_PCCLCR_LCMD_MASK)

#define LMEM_CACHE_PCCLCR_LADSEL_MASK            (0x4000000U)
#define LMEM_CACHE_PCCLCR_LADSEL_SHIFT           (26U)
#define LMEM_CACHE_PCCLCR_LADSEL_WIDTH           (1U)
#define LMEM_CACHE_PCCLCR_LADSEL(x)              (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_LADSEL_SHIFT)) & LMEM_CACHE_PCCLCR_LADSEL_MASK)

#define LMEM_CACHE_PCCLCR_LACC_MASK              (0x8000000U)
#define LMEM_CACHE_PCCLCR_LACC_SHIFT             (27U)
#define LMEM_CACHE_PCCLCR_LACC_WIDTH             (1U)
#define LMEM_CACHE_PCCLCR_LACC(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCLCR_LACC_SHIFT)) & LMEM_CACHE_PCCLCR_LACC_MASK)
/*! @} */

/*! @name PCCSAR - Cache search address register */
/*! @{ */

#define LMEM_CACHE_PCCSAR_LGO_MASK               (0x1U)
#define LMEM_CACHE_PCCSAR_LGO_SHIFT              (0U)
#define LMEM_CACHE_PCCSAR_LGO_WIDTH              (1U)
#define LMEM_CACHE_PCCSAR_LGO(x)                 (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCSAR_LGO_SHIFT)) & LMEM_CACHE_PCCSAR_LGO_MASK)

#define LMEM_CACHE_PCCSAR_PHYADDR_MASK           (0xFFFFFFFCU)
#define LMEM_CACHE_PCCSAR_PHYADDR_SHIFT          (2U)
#define LMEM_CACHE_PCCSAR_PHYADDR_WIDTH          (30U)
#define LMEM_CACHE_PCCSAR_PHYADDR(x)             (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCSAR_PHYADDR_SHIFT)) & LMEM_CACHE_PCCSAR_PHYADDR_MASK)
/*! @} */

/*! @name PCCCVR - Cache read/write value register */
/*! @{ */

#define LMEM_CACHE_PCCCVR_DATA_MASK              (0xFFFFFFFFU)
#define LMEM_CACHE_PCCCVR_DATA_SHIFT             (0U)
#define LMEM_CACHE_PCCCVR_DATA_WIDTH             (32U)
#define LMEM_CACHE_PCCCVR_DATA(x)                (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCCVR_DATA_SHIFT)) & LMEM_CACHE_PCCCVR_DATA_MASK)
/*! @} */

/*! @name PCCRMR - Cache regions mode register */
/*! @{ */

#define LMEM_CACHE_PCCRMR_R2_MASK                (0xC000000U)
#define LMEM_CACHE_PCCRMR_R2_SHIFT               (26U)
#define LMEM_CACHE_PCCRMR_R2_WIDTH               (2U)
#define LMEM_CACHE_PCCRMR_R2(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCRMR_R2_SHIFT)) & LMEM_CACHE_PCCRMR_R2_MASK)

#define LMEM_CACHE_PCCRMR_R1_MASK                (0x30000000U)
#define LMEM_CACHE_PCCRMR_R1_SHIFT               (28U)
#define LMEM_CACHE_PCCRMR_R1_WIDTH               (2U)
#define LMEM_CACHE_PCCRMR_R1(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCRMR_R1_SHIFT)) & LMEM_CACHE_PCCRMR_R1_MASK)

#define LMEM_CACHE_PCCRMR_R0_MASK                (0xC0000000U)
#define LMEM_CACHE_PCCRMR_R0_SHIFT               (30U)
#define LMEM_CACHE_PCCRMR_R0_WIDTH               (2U)
#define LMEM_CACHE_PCCRMR_R0(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM_CACHE_PCCRMR_R0_SHIFT)) & LMEM_CACHE_PCCRMR_R0_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LMEM_CACHE_Register_Masks */

/*!
 * @}
 */ /* end of group LMEM_CACHE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LMEM_CACHE_H_) */
