/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_LMEM64.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_LMEM64
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
#if !defined(S32Z2_LMEM64_H_)  /* Check if memory map has not been already included */
#define S32Z2_LMEM64_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LMEM64 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM64_Peripheral_Access_Layer LMEM64 Peripheral Access Layer
 * @{
 */

/** LMEM64 - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCCCR;                             /**< PC bus Cache control register, offset: 0x0 */
  __IO uint32_t PCCLCR;                            /**< PC bus Cache line control register, offset: 0x4 */
  __IO uint32_t PCCSAR;                            /**< PC bus Cache search address register, offset: 0x8 */
  __IO uint32_t PCCCVR;                            /**< PC bus Cache read/write value register, offset: 0xC */
  uint8_t RESERVED_0[2032];
  __IO uint32_t PSCCR;                             /**< PS bus Cache control register, offset: 0x800 */
  __IO uint32_t PSCLCR;                            /**< PS bus Cache line control register, offset: 0x804 */
  __IO uint32_t PSCSAR;                            /**< PS bus Cache search address register, offset: 0x808 */
  __IO uint32_t PSCCVR;                            /**< PS bus Cache read/write value register, offset: 0x80C */
} LMEM64_Type, *LMEM64_MemMapPtr;

/** Number of instances of the LMEM64 module. */
#define LMEM64_INSTANCE_COUNT                    (2u)

/* LMEM64 - Peripheral instance base addresses */
/** Peripheral CE_LMEM64 base address */
#define IP_CE_LMEM64_BASE                        (0xE0082000u)
/** Peripheral CE_LMEM64 base pointer */
#define IP_CE_LMEM64                             ((LMEM64_Type *)IP_CE_LMEM64_BASE)
/** Peripheral SMU__LMEM64 base address */
#define IP_SMU__LMEM64_BASE                      (0xE0082000u)
/** Peripheral SMU__LMEM64 base pointer */
#define IP_SMU__LMEM64                           ((LMEM64_Type *)IP_SMU__LMEM64_BASE)
/** Array initializer of LMEM64 peripheral base addresses */
#define IP_LMEM64_BASE_ADDRS                     { IP_CE_LMEM64_BASE, IP_SMU__LMEM64_BASE }
/** Array initializer of LMEM64 peripheral base pointers */
#define IP_LMEM64_BASE_PTRS                      { IP_CE_LMEM64, IP_SMU__LMEM64 }

/* ----------------------------------------------------------------------------
   -- LMEM64 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM64_Register_Masks LMEM64 Register Masks
 * @{
 */

/*! @name PCCCR - PC bus Cache control register */
/*! @{ */

#define LMEM64_PCCCR_ENCACHE_MASK                (0x1U)
#define LMEM64_PCCCR_ENCACHE_SHIFT               (0U)
#define LMEM64_PCCCR_ENCACHE_WIDTH               (1U)
#define LMEM64_PCCCR_ENCACHE(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_ENCACHE_SHIFT)) & LMEM64_PCCCR_ENCACHE_MASK)

#define LMEM64_PCCCR_ENWRBUF_MASK                (0x2U)
#define LMEM64_PCCCR_ENWRBUF_SHIFT               (1U)
#define LMEM64_PCCCR_ENWRBUF_WIDTH               (1U)
#define LMEM64_PCCCR_ENWRBUF(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_ENWRBUF_SHIFT)) & LMEM64_PCCCR_ENWRBUF_MASK)

#define LMEM64_PCCCR_PCCR2_MASK                  (0x4U)
#define LMEM64_PCCCR_PCCR2_SHIFT                 (2U)
#define LMEM64_PCCCR_PCCR2_WIDTH                 (1U)
#define LMEM64_PCCCR_PCCR2(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_PCCR2_SHIFT)) & LMEM64_PCCCR_PCCR2_MASK)

#define LMEM64_PCCCR_PCCR3_MASK                  (0x8U)
#define LMEM64_PCCCR_PCCR3_SHIFT                 (3U)
#define LMEM64_PCCCR_PCCR3_WIDTH                 (1U)
#define LMEM64_PCCCR_PCCR3(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_PCCR3_SHIFT)) & LMEM64_PCCCR_PCCR3_MASK)

#define LMEM64_PCCCR_INVW0_MASK                  (0x1000000U)
#define LMEM64_PCCCR_INVW0_SHIFT                 (24U)
#define LMEM64_PCCCR_INVW0_WIDTH                 (1U)
#define LMEM64_PCCCR_INVW0(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_INVW0_SHIFT)) & LMEM64_PCCCR_INVW0_MASK)

#define LMEM64_PCCCR_PUSHW0_MASK                 (0x2000000U)
#define LMEM64_PCCCR_PUSHW0_SHIFT                (25U)
#define LMEM64_PCCCR_PUSHW0_WIDTH                (1U)
#define LMEM64_PCCCR_PUSHW0(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_PUSHW0_SHIFT)) & LMEM64_PCCCR_PUSHW0_MASK)

#define LMEM64_PCCCR_INVW1_MASK                  (0x4000000U)
#define LMEM64_PCCCR_INVW1_SHIFT                 (26U)
#define LMEM64_PCCCR_INVW1_WIDTH                 (1U)
#define LMEM64_PCCCR_INVW1(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_INVW1_SHIFT)) & LMEM64_PCCCR_INVW1_MASK)

#define LMEM64_PCCCR_PUSHW1_MASK                 (0x8000000U)
#define LMEM64_PCCCR_PUSHW1_SHIFT                (27U)
#define LMEM64_PCCCR_PUSHW1_WIDTH                (1U)
#define LMEM64_PCCCR_PUSHW1(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_PUSHW1_SHIFT)) & LMEM64_PCCCR_PUSHW1_MASK)

#define LMEM64_PCCCR_GO_MASK                     (0x80000000U)
#define LMEM64_PCCCR_GO_SHIFT                    (31U)
#define LMEM64_PCCCR_GO_WIDTH                    (1U)
#define LMEM64_PCCCR_GO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCR_GO_SHIFT)) & LMEM64_PCCCR_GO_MASK)
/*! @} */

/*! @name PCCLCR - PC bus Cache line control register */
/*! @{ */

#define LMEM64_PCCLCR_LGO_MASK                   (0x1U)
#define LMEM64_PCCLCR_LGO_SHIFT                  (0U)
#define LMEM64_PCCLCR_LGO_WIDTH                  (1U)
#define LMEM64_PCCLCR_LGO(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_LGO_SHIFT)) & LMEM64_PCCLCR_LGO_MASK)

#define LMEM64_PCCLCR_CACHEADDR_MASK             (0x3FFCU)
#define LMEM64_PCCLCR_CACHEADDR_SHIFT            (2U)
#define LMEM64_PCCLCR_CACHEADDR_WIDTH            (12U)
#define LMEM64_PCCLCR_CACHEADDR(x)               (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_CACHEADDR_SHIFT)) & LMEM64_PCCLCR_CACHEADDR_MASK)

#define LMEM64_PCCLCR_WSEL_MASK                  (0x4000U)
#define LMEM64_PCCLCR_WSEL_SHIFT                 (14U)
#define LMEM64_PCCLCR_WSEL_WIDTH                 (1U)
#define LMEM64_PCCLCR_WSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_WSEL_SHIFT)) & LMEM64_PCCLCR_WSEL_MASK)

#define LMEM64_PCCLCR_TDSEL_MASK                 (0x10000U)
#define LMEM64_PCCLCR_TDSEL_SHIFT                (16U)
#define LMEM64_PCCLCR_TDSEL_WIDTH                (1U)
#define LMEM64_PCCLCR_TDSEL(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_TDSEL_SHIFT)) & LMEM64_PCCLCR_TDSEL_MASK)

#define LMEM64_PCCLCR_LCIVB_MASK                 (0x100000U)
#define LMEM64_PCCLCR_LCIVB_SHIFT                (20U)
#define LMEM64_PCCLCR_LCIVB_WIDTH                (1U)
#define LMEM64_PCCLCR_LCIVB(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_LCIVB_SHIFT)) & LMEM64_PCCLCR_LCIVB_MASK)

#define LMEM64_PCCLCR_LCIMB_MASK                 (0x200000U)
#define LMEM64_PCCLCR_LCIMB_SHIFT                (21U)
#define LMEM64_PCCLCR_LCIMB_WIDTH                (1U)
#define LMEM64_PCCLCR_LCIMB(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_LCIMB_SHIFT)) & LMEM64_PCCLCR_LCIMB_MASK)

#define LMEM64_PCCLCR_LCWAY_MASK                 (0x400000U)
#define LMEM64_PCCLCR_LCWAY_SHIFT                (22U)
#define LMEM64_PCCLCR_LCWAY_WIDTH                (1U)
#define LMEM64_PCCLCR_LCWAY(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_LCWAY_SHIFT)) & LMEM64_PCCLCR_LCWAY_MASK)

#define LMEM64_PCCLCR_LCMD_MASK                  (0x3000000U)
#define LMEM64_PCCLCR_LCMD_SHIFT                 (24U)
#define LMEM64_PCCLCR_LCMD_WIDTH                 (2U)
#define LMEM64_PCCLCR_LCMD(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_LCMD_SHIFT)) & LMEM64_PCCLCR_LCMD_MASK)

#define LMEM64_PCCLCR_LADSEL_MASK                (0x4000000U)
#define LMEM64_PCCLCR_LADSEL_SHIFT               (26U)
#define LMEM64_PCCLCR_LADSEL_WIDTH               (1U)
#define LMEM64_PCCLCR_LADSEL(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_LADSEL_SHIFT)) & LMEM64_PCCLCR_LADSEL_MASK)

#define LMEM64_PCCLCR_LACC_MASK                  (0x8000000U)
#define LMEM64_PCCLCR_LACC_SHIFT                 (27U)
#define LMEM64_PCCLCR_LACC_WIDTH                 (1U)
#define LMEM64_PCCLCR_LACC(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCLCR_LACC_SHIFT)) & LMEM64_PCCLCR_LACC_MASK)
/*! @} */

/*! @name PCCSAR - PC bus Cache search address register */
/*! @{ */

#define LMEM64_PCCSAR_LGO_MASK                   (0x1U)
#define LMEM64_PCCSAR_LGO_SHIFT                  (0U)
#define LMEM64_PCCSAR_LGO_WIDTH                  (1U)
#define LMEM64_PCCSAR_LGO(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCSAR_LGO_SHIFT)) & LMEM64_PCCSAR_LGO_MASK)

#define LMEM64_PCCSAR_PHYADDR_MASK               (0xFFFFFFFEU)
#define LMEM64_PCCSAR_PHYADDR_SHIFT              (1U)
#define LMEM64_PCCSAR_PHYADDR_WIDTH              (31U)
#define LMEM64_PCCSAR_PHYADDR(x)                 (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCSAR_PHYADDR_SHIFT)) & LMEM64_PCCSAR_PHYADDR_MASK)
/*! @} */

/*! @name PCCCVR - PC bus Cache read/write value register */
/*! @{ */

#define LMEM64_PCCCVR_DATA_MASK                  (0xFFFFFFFFU)
#define LMEM64_PCCCVR_DATA_SHIFT                 (0U)
#define LMEM64_PCCCVR_DATA_WIDTH                 (32U)
#define LMEM64_PCCCVR_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PCCCVR_DATA_SHIFT)) & LMEM64_PCCCVR_DATA_MASK)
/*! @} */

/*! @name PSCCR - PS bus Cache control register */
/*! @{ */

#define LMEM64_PSCCR_ENCACHE_MASK                (0x1U)
#define LMEM64_PSCCR_ENCACHE_SHIFT               (0U)
#define LMEM64_PSCCR_ENCACHE_WIDTH               (1U)
#define LMEM64_PSCCR_ENCACHE(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_ENCACHE_SHIFT)) & LMEM64_PSCCR_ENCACHE_MASK)

#define LMEM64_PSCCR_ENWRBUF_MASK                (0x2U)
#define LMEM64_PSCCR_ENWRBUF_SHIFT               (1U)
#define LMEM64_PSCCR_ENWRBUF_WIDTH               (1U)
#define LMEM64_PSCCR_ENWRBUF(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_ENWRBUF_SHIFT)) & LMEM64_PSCCR_ENWRBUF_MASK)

#define LMEM64_PSCCR_PSCR2_MASK                  (0x4U)
#define LMEM64_PSCCR_PSCR2_SHIFT                 (2U)
#define LMEM64_PSCCR_PSCR2_WIDTH                 (1U)
#define LMEM64_PSCCR_PSCR2(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_PSCR2_SHIFT)) & LMEM64_PSCCR_PSCR2_MASK)

#define LMEM64_PSCCR_PSCR3_MASK                  (0x8U)
#define LMEM64_PSCCR_PSCR3_SHIFT                 (3U)
#define LMEM64_PSCCR_PSCR3_WIDTH                 (1U)
#define LMEM64_PSCCR_PSCR3(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_PSCR3_SHIFT)) & LMEM64_PSCCR_PSCR3_MASK)

#define LMEM64_PSCCR_INVW0_MASK                  (0x1000000U)
#define LMEM64_PSCCR_INVW0_SHIFT                 (24U)
#define LMEM64_PSCCR_INVW0_WIDTH                 (1U)
#define LMEM64_PSCCR_INVW0(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_INVW0_SHIFT)) & LMEM64_PSCCR_INVW0_MASK)

#define LMEM64_PSCCR_PUSHW0_MASK                 (0x2000000U)
#define LMEM64_PSCCR_PUSHW0_SHIFT                (25U)
#define LMEM64_PSCCR_PUSHW0_WIDTH                (1U)
#define LMEM64_PSCCR_PUSHW0(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_PUSHW0_SHIFT)) & LMEM64_PSCCR_PUSHW0_MASK)

#define LMEM64_PSCCR_INVW1_MASK                  (0x4000000U)
#define LMEM64_PSCCR_INVW1_SHIFT                 (26U)
#define LMEM64_PSCCR_INVW1_WIDTH                 (1U)
#define LMEM64_PSCCR_INVW1(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_INVW1_SHIFT)) & LMEM64_PSCCR_INVW1_MASK)

#define LMEM64_PSCCR_PUSHW1_MASK                 (0x8000000U)
#define LMEM64_PSCCR_PUSHW1_SHIFT                (27U)
#define LMEM64_PSCCR_PUSHW1_WIDTH                (1U)
#define LMEM64_PSCCR_PUSHW1(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_PUSHW1_SHIFT)) & LMEM64_PSCCR_PUSHW1_MASK)

#define LMEM64_PSCCR_GO_MASK                     (0x80000000U)
#define LMEM64_PSCCR_GO_SHIFT                    (31U)
#define LMEM64_PSCCR_GO_WIDTH                    (1U)
#define LMEM64_PSCCR_GO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCR_GO_SHIFT)) & LMEM64_PSCCR_GO_MASK)
/*! @} */

/*! @name PSCLCR - PS bus Cache line control register */
/*! @{ */

#define LMEM64_PSCLCR_LGO_MASK                   (0x1U)
#define LMEM64_PSCLCR_LGO_SHIFT                  (0U)
#define LMEM64_PSCLCR_LGO_WIDTH                  (1U)
#define LMEM64_PSCLCR_LGO(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_LGO_SHIFT)) & LMEM64_PSCLCR_LGO_MASK)

#define LMEM64_PSCLCR_CACHEADDR_MASK             (0x3FFCU)
#define LMEM64_PSCLCR_CACHEADDR_SHIFT            (2U)
#define LMEM64_PSCLCR_CACHEADDR_WIDTH            (12U)
#define LMEM64_PSCLCR_CACHEADDR(x)               (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_CACHEADDR_SHIFT)) & LMEM64_PSCLCR_CACHEADDR_MASK)

#define LMEM64_PSCLCR_WSEL_MASK                  (0x4000U)
#define LMEM64_PSCLCR_WSEL_SHIFT                 (14U)
#define LMEM64_PSCLCR_WSEL_WIDTH                 (1U)
#define LMEM64_PSCLCR_WSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_WSEL_SHIFT)) & LMEM64_PSCLCR_WSEL_MASK)

#define LMEM64_PSCLCR_TDSEL_MASK                 (0x10000U)
#define LMEM64_PSCLCR_TDSEL_SHIFT                (16U)
#define LMEM64_PSCLCR_TDSEL_WIDTH                (1U)
#define LMEM64_PSCLCR_TDSEL(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_TDSEL_SHIFT)) & LMEM64_PSCLCR_TDSEL_MASK)

#define LMEM64_PSCLCR_LCIVB_MASK                 (0x100000U)
#define LMEM64_PSCLCR_LCIVB_SHIFT                (20U)
#define LMEM64_PSCLCR_LCIVB_WIDTH                (1U)
#define LMEM64_PSCLCR_LCIVB(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_LCIVB_SHIFT)) & LMEM64_PSCLCR_LCIVB_MASK)

#define LMEM64_PSCLCR_LCIMB_MASK                 (0x200000U)
#define LMEM64_PSCLCR_LCIMB_SHIFT                (21U)
#define LMEM64_PSCLCR_LCIMB_WIDTH                (1U)
#define LMEM64_PSCLCR_LCIMB(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_LCIMB_SHIFT)) & LMEM64_PSCLCR_LCIMB_MASK)

#define LMEM64_PSCLCR_LCWAY_MASK                 (0x400000U)
#define LMEM64_PSCLCR_LCWAY_SHIFT                (22U)
#define LMEM64_PSCLCR_LCWAY_WIDTH                (1U)
#define LMEM64_PSCLCR_LCWAY(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_LCWAY_SHIFT)) & LMEM64_PSCLCR_LCWAY_MASK)

#define LMEM64_PSCLCR_LCMD_MASK                  (0x3000000U)
#define LMEM64_PSCLCR_LCMD_SHIFT                 (24U)
#define LMEM64_PSCLCR_LCMD_WIDTH                 (2U)
#define LMEM64_PSCLCR_LCMD(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_LCMD_SHIFT)) & LMEM64_PSCLCR_LCMD_MASK)

#define LMEM64_PSCLCR_LADSEL_MASK                (0x4000000U)
#define LMEM64_PSCLCR_LADSEL_SHIFT               (26U)
#define LMEM64_PSCLCR_LADSEL_WIDTH               (1U)
#define LMEM64_PSCLCR_LADSEL(x)                  (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_LADSEL_SHIFT)) & LMEM64_PSCLCR_LADSEL_MASK)

#define LMEM64_PSCLCR_LACC_MASK                  (0x8000000U)
#define LMEM64_PSCLCR_LACC_SHIFT                 (27U)
#define LMEM64_PSCLCR_LACC_WIDTH                 (1U)
#define LMEM64_PSCLCR_LACC(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCLCR_LACC_SHIFT)) & LMEM64_PSCLCR_LACC_MASK)
/*! @} */

/*! @name PSCSAR - PS bus Cache search address register */
/*! @{ */

#define LMEM64_PSCSAR_LGO_MASK                   (0x1U)
#define LMEM64_PSCSAR_LGO_SHIFT                  (0U)
#define LMEM64_PSCSAR_LGO_WIDTH                  (1U)
#define LMEM64_PSCSAR_LGO(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCSAR_LGO_SHIFT)) & LMEM64_PSCSAR_LGO_MASK)

#define LMEM64_PSCSAR_PHYADDR_MASK               (0xFFFFFFFEU)
#define LMEM64_PSCSAR_PHYADDR_SHIFT              (1U)
#define LMEM64_PSCSAR_PHYADDR_WIDTH              (31U)
#define LMEM64_PSCSAR_PHYADDR(x)                 (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCSAR_PHYADDR_SHIFT)) & LMEM64_PSCSAR_PHYADDR_MASK)
/*! @} */

/*! @name PSCCVR - PS bus Cache read/write value register */
/*! @{ */

#define LMEM64_PSCCVR_DATA_MASK                  (0xFFFFFFFFU)
#define LMEM64_PSCCVR_DATA_SHIFT                 (0U)
#define LMEM64_PSCCVR_DATA_WIDTH                 (32U)
#define LMEM64_PSCCVR_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM64_PSCCVR_DATA_SHIFT)) & LMEM64_PSCCVR_DATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LMEM64_Register_Masks */

/*!
 * @}
 */ /* end of group LMEM64_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_LMEM64_H_) */
