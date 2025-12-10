/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_WKPU.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_WKPU
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
#if !defined(S32K566_WKPU_H_)  /* Check if memory map has not been already included */
#define S32K566_WKPU_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- WKPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKPU_Peripheral_Access_Layer WKPU Peripheral Access Layer
 * @{
 */

/** WKPU - Register Layout Typedef */
typedef struct WKPU_Struct {
  __IO uint32_t NSR;                               /**< NMI Status Flag, offset: 0x0 */
  __IO uint32_t NSR_8;                             /**< NMI Status Flag, offset: 0x4 */
  __IO uint32_t NCR;                               /**< NMI Configuration, offset: 0x8 */
  __IO uint32_t NCR_8;                             /**< NMI Configuration, offset: 0xC */
  __IO uint32_t WBMSR;                             /**< Wake-Up Boot Mode Select, offset: 0x10 */
  __IO uint32_t WISR;                              /**< Wake-Up and Interrupt Status Flag, offset: 0x14 */
  __IO uint32_t IRER;                              /**< Interrupt Request Enable, offset: 0x18 */
  __IO uint32_t WRER;                              /**< Wake-Up Request Enable, offset: 0x1C */
  uint8_t RESERVED_0[8];
  __IO uint32_t WIREER;                            /**< Wake-Up and Interrupt Rising-Edge Event Enable, offset: 0x28 */
  __IO uint32_t WIFEER;                            /**< Wake-Up and Interrupt Falling-Edge Event Enable, offset: 0x2C */
  __IO uint32_t WIFER;                             /**< Wake-Up and Interrupt Filter Enable, offset: 0x30 */
  uint8_t RESERVED_1[16];
  __IO uint32_t GPIO_QUAL;                         /**< GPIO Qualifier, offset: 0x44 */
  __IO uint32_t WKPU_NMI_BMSR;                     /**< NMI Boot Mode Select, offset: 0x48 */
  uint8_t RESERVED_2[4];
  __IO uint32_t WBMSR_64;                          /**< Wake-Up Boot Mode Select, offset: 0x50 */
  __IO uint32_t WISR_64;                           /**< Wake-Up and Interrupt Status Flag, offset: 0x54 */
  __IO uint32_t IRER_64;                           /**< Interrupt Request Enable, offset: 0x58 */
  __IO uint32_t WRER_64;                           /**< Wake-Up Request Enable, offset: 0x5C */
  uint8_t RESERVED_3[8];
  __IO uint32_t WIREER_64;                         /**< Wake-Up and Interrupt Rising-Edge Event Enable, offset: 0x68 */
  __IO uint32_t WIFEER_64;                         /**< Wake-Up and Interrupt Falling-Edge Event Enable, offset: 0x6C */
  __IO uint32_t WIFER_64;                          /**< Wake-Up and Interrupt Filter Enable, offset: 0x70 */
  uint8_t RESERVED_4[148];
  __IO uint32_t WBMSR_96;                          /**< Wake-Up Boot Mode Select, offset: 0x108 */
  __IO uint32_t WISR_96;                           /**< Wake-Up and Interrupt Status Flag, offset: 0x10C */
  __IO uint32_t IRER_96;                           /**< Interrupt Request Enable, offset: 0x110 */
  __IO uint32_t WRER_96;                           /**< Wake-Up Request Enable, offset: 0x114 */
  __IO uint32_t WIREER_96;                         /**< Wake-Up and Interrupt Rising-Edge Event Enable, offset: 0x118 */
  __IO uint32_t WIFEER_96;                         /**< Wake-Up and Interrupt Falling-Edge Event Enable, offset: 0x11C */
  __IO uint32_t WIFER_96;                          /**< Wake-Up and Interrupt Filter Enable, offset: 0x120 */
} WKPU_Type, *WKPU_MemMapPtr;

/** Number of instances of the WKPU module. */
#define WKPU_INSTANCE_COUNT                      (1u)

/* WKPU - Peripheral instance base addresses */
/** Peripheral LPE_WKPU base address */
#define IP_LPE_WKPU_BASE                         (0x4210C000u)
/** Peripheral LPE_WKPU base pointer */
#define IP_LPE_WKPU                              ((WKPU_Type *)IP_LPE_WKPU_BASE)
/** Array initializer of WKPU peripheral base addresses */
#define IP_WKPU_BASE_ADDRS                       { IP_LPE_WKPU_BASE }
/** Array initializer of WKPU peripheral base pointers */
#define IP_WKPU_BASE_PTRS                        { IP_LPE_WKPU }

/* ----------------------------------------------------------------------------
   -- WKPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKPU_Register_Masks WKPU Register Masks
 * @{
 */

/*! @name NSR - NMI Status Flag */
/*! @{ */

#define WKPU_NSR_NOVF3_MASK                      (0x40U)
#define WKPU_NSR_NOVF3_SHIFT                     (6U)
#define WKPU_NSR_NOVF3_WIDTH                     (1U)
#define WKPU_NSR_NOVF3(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NOVF3_SHIFT)) & WKPU_NSR_NOVF3_MASK)

#define WKPU_NSR_NIF3_MASK                       (0x80U)
#define WKPU_NSR_NIF3_SHIFT                      (7U)
#define WKPU_NSR_NIF3_WIDTH                      (1U)
#define WKPU_NSR_NIF3(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NIF3_SHIFT)) & WKPU_NSR_NIF3_MASK)

#define WKPU_NSR_NOVF2_MASK                      (0x4000U)
#define WKPU_NSR_NOVF2_SHIFT                     (14U)
#define WKPU_NSR_NOVF2_WIDTH                     (1U)
#define WKPU_NSR_NOVF2(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NOVF2_SHIFT)) & WKPU_NSR_NOVF2_MASK)

#define WKPU_NSR_NIF2_MASK                       (0x8000U)
#define WKPU_NSR_NIF2_SHIFT                      (15U)
#define WKPU_NSR_NIF2_WIDTH                      (1U)
#define WKPU_NSR_NIF2(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NIF2_SHIFT)) & WKPU_NSR_NIF2_MASK)

#define WKPU_NSR_NOVF1_MASK                      (0x400000U)
#define WKPU_NSR_NOVF1_SHIFT                     (22U)
#define WKPU_NSR_NOVF1_WIDTH                     (1U)
#define WKPU_NSR_NOVF1(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NOVF1_SHIFT)) & WKPU_NSR_NOVF1_MASK)

#define WKPU_NSR_NIF1_MASK                       (0x800000U)
#define WKPU_NSR_NIF1_SHIFT                      (23U)
#define WKPU_NSR_NIF1_WIDTH                      (1U)
#define WKPU_NSR_NIF1(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NIF1_SHIFT)) & WKPU_NSR_NIF1_MASK)

#define WKPU_NSR_NOVF0_MASK                      (0x40000000U)
#define WKPU_NSR_NOVF0_SHIFT                     (30U)
#define WKPU_NSR_NOVF0_WIDTH                     (1U)
#define WKPU_NSR_NOVF0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NOVF0_SHIFT)) & WKPU_NSR_NOVF0_MASK)

#define WKPU_NSR_NIF0_MASK                       (0x80000000U)
#define WKPU_NSR_NIF0_SHIFT                      (31U)
#define WKPU_NSR_NIF0_WIDTH                      (1U)
#define WKPU_NSR_NIF0(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NIF0_SHIFT)) & WKPU_NSR_NIF0_MASK)
/*! @} */

/*! @name NSR_8 - NMI Status Flag */
/*! @{ */

#define WKPU_NSR_8_NOVF6_MASK                    (0x4000U)
#define WKPU_NSR_8_NOVF6_SHIFT                   (14U)
#define WKPU_NSR_8_NOVF6_WIDTH                   (1U)
#define WKPU_NSR_8_NOVF6(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_8_NOVF6_SHIFT)) & WKPU_NSR_8_NOVF6_MASK)

#define WKPU_NSR_8_NIF6_MASK                     (0x8000U)
#define WKPU_NSR_8_NIF6_SHIFT                    (15U)
#define WKPU_NSR_8_NIF6_WIDTH                    (1U)
#define WKPU_NSR_8_NIF6(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_8_NIF6_SHIFT)) & WKPU_NSR_8_NIF6_MASK)

#define WKPU_NSR_8_NOVF5_MASK                    (0x400000U)
#define WKPU_NSR_8_NOVF5_SHIFT                   (22U)
#define WKPU_NSR_8_NOVF5_WIDTH                   (1U)
#define WKPU_NSR_8_NOVF5(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_8_NOVF5_SHIFT)) & WKPU_NSR_8_NOVF5_MASK)

#define WKPU_NSR_8_NIF5_MASK                     (0x800000U)
#define WKPU_NSR_8_NIF5_SHIFT                    (23U)
#define WKPU_NSR_8_NIF5_WIDTH                    (1U)
#define WKPU_NSR_8_NIF5(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_8_NIF5_SHIFT)) & WKPU_NSR_8_NIF5_MASK)

#define WKPU_NSR_8_NOVF4_MASK                    (0x40000000U)
#define WKPU_NSR_8_NOVF4_SHIFT                   (30U)
#define WKPU_NSR_8_NOVF4_WIDTH                   (1U)
#define WKPU_NSR_8_NOVF4(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_8_NOVF4_SHIFT)) & WKPU_NSR_8_NOVF4_MASK)

#define WKPU_NSR_8_NIF4_MASK                     (0x80000000U)
#define WKPU_NSR_8_NIF4_SHIFT                    (31U)
#define WKPU_NSR_8_NIF4_WIDTH                    (1U)
#define WKPU_NSR_8_NIF4(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_8_NIF4_SHIFT)) & WKPU_NSR_8_NIF4_MASK)
/*! @} */

/*! @name NCR - NMI Configuration */
/*! @{ */

#define WKPU_NCR_NFE3_MASK                       (0x1U)
#define WKPU_NCR_NFE3_SHIFT                      (0U)
#define WKPU_NCR_NFE3_WIDTH                      (1U)
#define WKPU_NCR_NFE3(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFE3_SHIFT)) & WKPU_NCR_NFE3_MASK)

#define WKPU_NCR_NFEE3_RFEE_MASK                 (0x2U)
#define WKPU_NCR_NFEE3_RFEE_SHIFT                (1U)
#define WKPU_NCR_NFEE3_RFEE_WIDTH                (1U)
#define WKPU_NCR_NFEE3_RFEE(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFEE3_RFEE_SHIFT)) & WKPU_NCR_NFEE3_RFEE_MASK)

#define WKPU_NCR_NREE3_RREE_MASK                 (0x4U)
#define WKPU_NCR_NREE3_RREE_SHIFT                (2U)
#define WKPU_NCR_NREE3_RREE_WIDTH                (1U)
#define WKPU_NCR_NREE3_RREE(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NREE3_RREE_SHIFT)) & WKPU_NCR_NREE3_RREE_MASK)

#define WKPU_NCR_NWRE3_RWRE_MASK                 (0x10U)
#define WKPU_NCR_NWRE3_RWRE_SHIFT                (4U)
#define WKPU_NCR_NWRE3_RWRE_WIDTH                (1U)
#define WKPU_NCR_NWRE3_RWRE(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NWRE3_RWRE_SHIFT)) & WKPU_NCR_NWRE3_RWRE_MASK)

#define WKPU_NCR_NDSS3_RDSS_MASK                 (0x60U)
#define WKPU_NCR_NDSS3_RDSS_SHIFT                (5U)
#define WKPU_NCR_NDSS3_RDSS_WIDTH                (2U)
#define WKPU_NCR_NDSS3_RDSS(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NDSS3_RDSS_SHIFT)) & WKPU_NCR_NDSS3_RDSS_MASK)

#define WKPU_NCR_NLOCK3_RLOCK_MASK               (0x80U)
#define WKPU_NCR_NLOCK3_RLOCK_SHIFT              (7U)
#define WKPU_NCR_NLOCK3_RLOCK_WIDTH              (1U)
#define WKPU_NCR_NLOCK3_RLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NLOCK3_RLOCK_SHIFT)) & WKPU_NCR_NLOCK3_RLOCK_MASK)

#define WKPU_NCR_NFE2_MASK                       (0x100U)
#define WKPU_NCR_NFE2_SHIFT                      (8U)
#define WKPU_NCR_NFE2_WIDTH                      (1U)
#define WKPU_NCR_NFE2(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFE2_SHIFT)) & WKPU_NCR_NFE2_MASK)

#define WKPU_NCR_NFEE2_MASK                      (0x200U)
#define WKPU_NCR_NFEE2_SHIFT                     (9U)
#define WKPU_NCR_NFEE2_WIDTH                     (1U)
#define WKPU_NCR_NFEE2(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFEE2_SHIFT)) & WKPU_NCR_NFEE2_MASK)

#define WKPU_NCR_NREE2_MASK                      (0x400U)
#define WKPU_NCR_NREE2_SHIFT                     (10U)
#define WKPU_NCR_NREE2_WIDTH                     (1U)
#define WKPU_NCR_NREE2(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NREE2_SHIFT)) & WKPU_NCR_NREE2_MASK)

#define WKPU_NCR_NWRE2_MASK                      (0x1000U)
#define WKPU_NCR_NWRE2_SHIFT                     (12U)
#define WKPU_NCR_NWRE2_WIDTH                     (1U)
#define WKPU_NCR_NWRE2(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NWRE2_SHIFT)) & WKPU_NCR_NWRE2_MASK)

#define WKPU_NCR_NDSS2_MASK                      (0x6000U)
#define WKPU_NCR_NDSS2_SHIFT                     (13U)
#define WKPU_NCR_NDSS2_WIDTH                     (2U)
#define WKPU_NCR_NDSS2(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NDSS2_SHIFT)) & WKPU_NCR_NDSS2_MASK)

#define WKPU_NCR_NLOCK2_MASK                     (0x8000U)
#define WKPU_NCR_NLOCK2_SHIFT                    (15U)
#define WKPU_NCR_NLOCK2_WIDTH                    (1U)
#define WKPU_NCR_NLOCK2(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NLOCK2_SHIFT)) & WKPU_NCR_NLOCK2_MASK)

#define WKPU_NCR_NFE1_MASK                       (0x10000U)
#define WKPU_NCR_NFE1_SHIFT                      (16U)
#define WKPU_NCR_NFE1_WIDTH                      (1U)
#define WKPU_NCR_NFE1(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFE1_SHIFT)) & WKPU_NCR_NFE1_MASK)

#define WKPU_NCR_NFEE1_MASK                      (0x20000U)
#define WKPU_NCR_NFEE1_SHIFT                     (17U)
#define WKPU_NCR_NFEE1_WIDTH                     (1U)
#define WKPU_NCR_NFEE1(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFEE1_SHIFT)) & WKPU_NCR_NFEE1_MASK)

#define WKPU_NCR_NREE1_MASK                      (0x40000U)
#define WKPU_NCR_NREE1_SHIFT                     (18U)
#define WKPU_NCR_NREE1_WIDTH                     (1U)
#define WKPU_NCR_NREE1(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NREE1_SHIFT)) & WKPU_NCR_NREE1_MASK)

#define WKPU_NCR_NWRE1_MASK                      (0x100000U)
#define WKPU_NCR_NWRE1_SHIFT                     (20U)
#define WKPU_NCR_NWRE1_WIDTH                     (1U)
#define WKPU_NCR_NWRE1(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NWRE1_SHIFT)) & WKPU_NCR_NWRE1_MASK)

#define WKPU_NCR_NDSS1_MASK                      (0x600000U)
#define WKPU_NCR_NDSS1_SHIFT                     (21U)
#define WKPU_NCR_NDSS1_WIDTH                     (2U)
#define WKPU_NCR_NDSS1(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NDSS1_SHIFT)) & WKPU_NCR_NDSS1_MASK)

#define WKPU_NCR_NLOCK1_MASK                     (0x800000U)
#define WKPU_NCR_NLOCK1_SHIFT                    (23U)
#define WKPU_NCR_NLOCK1_WIDTH                    (1U)
#define WKPU_NCR_NLOCK1(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NLOCK1_SHIFT)) & WKPU_NCR_NLOCK1_MASK)

#define WKPU_NCR_NFE0_MASK                       (0x1000000U)
#define WKPU_NCR_NFE0_SHIFT                      (24U)
#define WKPU_NCR_NFE0_WIDTH                      (1U)
#define WKPU_NCR_NFE0(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFE0_SHIFT)) & WKPU_NCR_NFE0_MASK)

#define WKPU_NCR_NFEE0_MASK                      (0x2000000U)
#define WKPU_NCR_NFEE0_SHIFT                     (25U)
#define WKPU_NCR_NFEE0_WIDTH                     (1U)
#define WKPU_NCR_NFEE0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFEE0_SHIFT)) & WKPU_NCR_NFEE0_MASK)

#define WKPU_NCR_NREE0_MASK                      (0x4000000U)
#define WKPU_NCR_NREE0_SHIFT                     (26U)
#define WKPU_NCR_NREE0_WIDTH                     (1U)
#define WKPU_NCR_NREE0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NREE0_SHIFT)) & WKPU_NCR_NREE0_MASK)

#define WKPU_NCR_NWRE0_MASK                      (0x10000000U)
#define WKPU_NCR_NWRE0_SHIFT                     (28U)
#define WKPU_NCR_NWRE0_WIDTH                     (1U)
#define WKPU_NCR_NWRE0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NWRE0_SHIFT)) & WKPU_NCR_NWRE0_MASK)

#define WKPU_NCR_NDSS0_MASK                      (0x60000000U)
#define WKPU_NCR_NDSS0_SHIFT                     (29U)
#define WKPU_NCR_NDSS0_WIDTH                     (2U)
#define WKPU_NCR_NDSS0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NDSS0_SHIFT)) & WKPU_NCR_NDSS0_MASK)

#define WKPU_NCR_NLOCK0_MASK                     (0x80000000U)
#define WKPU_NCR_NLOCK0_SHIFT                    (31U)
#define WKPU_NCR_NLOCK0_WIDTH                    (1U)
#define WKPU_NCR_NLOCK0(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NLOCK0_SHIFT)) & WKPU_NCR_NLOCK0_MASK)
/*! @} */

/*! @name NCR_8 - NMI Configuration */
/*! @{ */

#define WKPU_NCR_8_NFE6_MASK                     (0x100U)
#define WKPU_NCR_8_NFE6_SHIFT                    (8U)
#define WKPU_NCR_8_NFE6_WIDTH                    (1U)
#define WKPU_NCR_8_NFE6(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NFE6_SHIFT)) & WKPU_NCR_8_NFE6_MASK)

#define WKPU_NCR_8_NFEE6_MASK                    (0x200U)
#define WKPU_NCR_8_NFEE6_SHIFT                   (9U)
#define WKPU_NCR_8_NFEE6_WIDTH                   (1U)
#define WKPU_NCR_8_NFEE6(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NFEE6_SHIFT)) & WKPU_NCR_8_NFEE6_MASK)

#define WKPU_NCR_8_NREE6_MASK                    (0x400U)
#define WKPU_NCR_8_NREE6_SHIFT                   (10U)
#define WKPU_NCR_8_NREE6_WIDTH                   (1U)
#define WKPU_NCR_8_NREE6(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NREE6_SHIFT)) & WKPU_NCR_8_NREE6_MASK)

#define WKPU_NCR_8_NWRE6_MASK                    (0x1000U)
#define WKPU_NCR_8_NWRE6_SHIFT                   (12U)
#define WKPU_NCR_8_NWRE6_WIDTH                   (1U)
#define WKPU_NCR_8_NWRE6(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NWRE6_SHIFT)) & WKPU_NCR_8_NWRE6_MASK)

#define WKPU_NCR_8_NDSS6_MASK                    (0x6000U)
#define WKPU_NCR_8_NDSS6_SHIFT                   (13U)
#define WKPU_NCR_8_NDSS6_WIDTH                   (2U)
#define WKPU_NCR_8_NDSS6(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NDSS6_SHIFT)) & WKPU_NCR_8_NDSS6_MASK)

#define WKPU_NCR_8_NLOCK6_MASK                   (0x8000U)
#define WKPU_NCR_8_NLOCK6_SHIFT                  (15U)
#define WKPU_NCR_8_NLOCK6_WIDTH                  (1U)
#define WKPU_NCR_8_NLOCK6(x)                     (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NLOCK6_SHIFT)) & WKPU_NCR_8_NLOCK6_MASK)

#define WKPU_NCR_8_NFE5_MASK                     (0x10000U)
#define WKPU_NCR_8_NFE5_SHIFT                    (16U)
#define WKPU_NCR_8_NFE5_WIDTH                    (1U)
#define WKPU_NCR_8_NFE5(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NFE5_SHIFT)) & WKPU_NCR_8_NFE5_MASK)

#define WKPU_NCR_8_NFEE5_MASK                    (0x20000U)
#define WKPU_NCR_8_NFEE5_SHIFT                   (17U)
#define WKPU_NCR_8_NFEE5_WIDTH                   (1U)
#define WKPU_NCR_8_NFEE5(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NFEE5_SHIFT)) & WKPU_NCR_8_NFEE5_MASK)

#define WKPU_NCR_8_NREE5_MASK                    (0x40000U)
#define WKPU_NCR_8_NREE5_SHIFT                   (18U)
#define WKPU_NCR_8_NREE5_WIDTH                   (1U)
#define WKPU_NCR_8_NREE5(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NREE5_SHIFT)) & WKPU_NCR_8_NREE5_MASK)

#define WKPU_NCR_8_NWRE5_MASK                    (0x100000U)
#define WKPU_NCR_8_NWRE5_SHIFT                   (20U)
#define WKPU_NCR_8_NWRE5_WIDTH                   (1U)
#define WKPU_NCR_8_NWRE5(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NWRE5_SHIFT)) & WKPU_NCR_8_NWRE5_MASK)

#define WKPU_NCR_8_NDSS5_MASK                    (0x600000U)
#define WKPU_NCR_8_NDSS5_SHIFT                   (21U)
#define WKPU_NCR_8_NDSS5_WIDTH                   (2U)
#define WKPU_NCR_8_NDSS5(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NDSS5_SHIFT)) & WKPU_NCR_8_NDSS5_MASK)

#define WKPU_NCR_8_NLOCK5_MASK                   (0x800000U)
#define WKPU_NCR_8_NLOCK5_SHIFT                  (23U)
#define WKPU_NCR_8_NLOCK5_WIDTH                  (1U)
#define WKPU_NCR_8_NLOCK5(x)                     (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NLOCK5_SHIFT)) & WKPU_NCR_8_NLOCK5_MASK)

#define WKPU_NCR_8_NFE4_MASK                     (0x1000000U)
#define WKPU_NCR_8_NFE4_SHIFT                    (24U)
#define WKPU_NCR_8_NFE4_WIDTH                    (1U)
#define WKPU_NCR_8_NFE4(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NFE4_SHIFT)) & WKPU_NCR_8_NFE4_MASK)

#define WKPU_NCR_8_NFEE4_MASK                    (0x2000000U)
#define WKPU_NCR_8_NFEE4_SHIFT                   (25U)
#define WKPU_NCR_8_NFEE4_WIDTH                   (1U)
#define WKPU_NCR_8_NFEE4(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NFEE4_SHIFT)) & WKPU_NCR_8_NFEE4_MASK)

#define WKPU_NCR_8_NREE4_MASK                    (0x4000000U)
#define WKPU_NCR_8_NREE4_SHIFT                   (26U)
#define WKPU_NCR_8_NREE4_WIDTH                   (1U)
#define WKPU_NCR_8_NREE4(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NREE4_SHIFT)) & WKPU_NCR_8_NREE4_MASK)

#define WKPU_NCR_8_NWRE4_MASK                    (0x10000000U)
#define WKPU_NCR_8_NWRE4_SHIFT                   (28U)
#define WKPU_NCR_8_NWRE4_WIDTH                   (1U)
#define WKPU_NCR_8_NWRE4(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NWRE4_SHIFT)) & WKPU_NCR_8_NWRE4_MASK)

#define WKPU_NCR_8_NDSS4_MASK                    (0x60000000U)
#define WKPU_NCR_8_NDSS4_SHIFT                   (29U)
#define WKPU_NCR_8_NDSS4_WIDTH                   (2U)
#define WKPU_NCR_8_NDSS4(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NDSS4_SHIFT)) & WKPU_NCR_8_NDSS4_MASK)

#define WKPU_NCR_8_NLOCK4_MASK                   (0x80000000U)
#define WKPU_NCR_8_NLOCK4_SHIFT                  (31U)
#define WKPU_NCR_8_NLOCK4_WIDTH                  (1U)
#define WKPU_NCR_8_NLOCK4(x)                     (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_8_NLOCK4_SHIFT)) & WKPU_NCR_8_NLOCK4_MASK)
/*! @} */

/*! @name WBMSR - Wake-Up Boot Mode Select */
/*! @{ */

#define WKPU_WBMSR_WBMS_32_MASK                  (0xFFFFFFFFU)
#define WKPU_WBMSR_WBMS_32_SHIFT                 (0U)
#define WKPU_WBMSR_WBMS_32_WIDTH                 (32U)
#define WKPU_WBMSR_WBMS_32(x)                    (((uint32_t)(((uint32_t)(x)) << WKPU_WBMSR_WBMS_32_SHIFT)) & WKPU_WBMSR_WBMS_32_MASK)
/*! @} */

/*! @name WISR - Wake-Up and Interrupt Status Flag */
/*! @{ */

#define WKPU_WISR_EIF_MASK                       (0xFFFFFFFFU)
#define WKPU_WISR_EIF_SHIFT                      (0U)
#define WKPU_WISR_EIF_WIDTH                      (32U)
#define WKPU_WISR_EIF(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_WISR_EIF_SHIFT)) & WKPU_WISR_EIF_MASK)
/*! @} */

/*! @name IRER - Interrupt Request Enable */
/*! @{ */

#define WKPU_IRER_EIRE_MASK                      (0xFFFFFFFFU)
#define WKPU_IRER_EIRE_SHIFT                     (0U)
#define WKPU_IRER_EIRE_WIDTH                     (32U)
#define WKPU_IRER_EIRE(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_IRER_EIRE_SHIFT)) & WKPU_IRER_EIRE_MASK)
/*! @} */

/*! @name WRER - Wake-Up Request Enable */
/*! @{ */

#define WKPU_WRER_WRE_MASK                       (0xFFFFFFFFU)
#define WKPU_WRER_WRE_SHIFT                      (0U)
#define WKPU_WRER_WRE_WIDTH                      (32U)
#define WKPU_WRER_WRE(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_WRER_WRE_SHIFT)) & WKPU_WRER_WRE_MASK)
/*! @} */

/*! @name WIREER - Wake-Up and Interrupt Rising-Edge Event Enable */
/*! @{ */

#define WKPU_WIREER_IREE_MASK                    (0xFFFFFFFFU)
#define WKPU_WIREER_IREE_SHIFT                   (0U)
#define WKPU_WIREER_IREE_WIDTH                   (32U)
#define WKPU_WIREER_IREE(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_WIREER_IREE_SHIFT)) & WKPU_WIREER_IREE_MASK)
/*! @} */

/*! @name WIFEER - Wake-Up and Interrupt Falling-Edge Event Enable */
/*! @{ */

#define WKPU_WIFEER_IFEEx_MASK                   (0xFFFFFFFFU)
#define WKPU_WIFEER_IFEEx_SHIFT                  (0U)
#define WKPU_WIFEER_IFEEx_WIDTH                  (32U)
#define WKPU_WIFEER_IFEEx(x)                     (((uint32_t)(((uint32_t)(x)) << WKPU_WIFEER_IFEEx_SHIFT)) & WKPU_WIFEER_IFEEx_MASK)
/*! @} */

/*! @name WIFER - Wake-Up and Interrupt Filter Enable */
/*! @{ */

#define WKPU_WIFER_IFE_MASK                      (0xFFFFFFFFU)
#define WKPU_WIFER_IFE_SHIFT                     (0U)
#define WKPU_WIFER_IFE_WIDTH                     (32U)
#define WKPU_WIFER_IFE(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_WIFER_IFE_SHIFT)) & WKPU_WIFER_IFE_MASK)
/*! @} */

/*! @name GPIO_QUAL - GPIO Qualifier */
/*! @{ */

#define WKPU_GPIO_QUAL_PD1_PD0_MASK              (0x1U)
#define WKPU_GPIO_QUAL_PD1_PD0_SHIFT             (0U)
#define WKPU_GPIO_QUAL_PD1_PD0_WIDTH             (1U)
#define WKPU_GPIO_QUAL_PD1_PD0(x)                (((uint32_t)(((uint32_t)(x)) << WKPU_GPIO_QUAL_PD1_PD0_SHIFT)) & WKPU_GPIO_QUAL_PD1_PD0_MASK)

#define WKPU_GPIO_QUAL_PD2_PD0_MASK              (0x2U)
#define WKPU_GPIO_QUAL_PD2_PD0_SHIFT             (1U)
#define WKPU_GPIO_QUAL_PD2_PD0_WIDTH             (1U)
#define WKPU_GPIO_QUAL_PD2_PD0(x)                (((uint32_t)(((uint32_t)(x)) << WKPU_GPIO_QUAL_PD2_PD0_SHIFT)) & WKPU_GPIO_QUAL_PD2_PD0_MASK)

#define WKPU_GPIO_QUAL_Other_Power_Domains_MASK  (0xFFFFFFFCU)
#define WKPU_GPIO_QUAL_Other_Power_Domains_SHIFT (2U)
#define WKPU_GPIO_QUAL_Other_Power_Domains_WIDTH (30U)
#define WKPU_GPIO_QUAL_Other_Power_Domains(x)    (((uint32_t)(((uint32_t)(x)) << WKPU_GPIO_QUAL_Other_Power_Domains_SHIFT)) & WKPU_GPIO_QUAL_Other_Power_Domains_MASK)
/*! @} */

/*! @name WKPU_NMI_BMSR - NMI Boot Mode Select */
/*! @{ */

#define WKPU_WKPU_NMI_BMSR_NMIBMS_MASK           (0x7FU)
#define WKPU_WKPU_NMI_BMSR_NMIBMS_SHIFT          (0U)
#define WKPU_WKPU_NMI_BMSR_NMIBMS_WIDTH          (7U)
#define WKPU_WKPU_NMI_BMSR_NMIBMS(x)             (((uint32_t)(((uint32_t)(x)) << WKPU_WKPU_NMI_BMSR_NMIBMS_SHIFT)) & WKPU_WKPU_NMI_BMSR_NMIBMS_MASK)
/*! @} */

/*! @name WBMSR_64 - Wake-Up Boot Mode Select */
/*! @{ */

#define WKPU_WBMSR_64_WBMS_64_MASK               (0xFFFFFFFFU)
#define WKPU_WBMSR_64_WBMS_64_SHIFT              (0U)
#define WKPU_WBMSR_64_WBMS_64_WIDTH              (32U)
#define WKPU_WBMSR_64_WBMS_64(x)                 (((uint32_t)(((uint32_t)(x)) << WKPU_WBMSR_64_WBMS_64_SHIFT)) & WKPU_WBMSR_64_WBMS_64_MASK)
/*! @} */

/*! @name WISR_64 - Wake-Up and Interrupt Status Flag */
/*! @{ */

#define WKPU_WISR_64_EIF_1_MASK                  (0xFFFFFFFFU)
#define WKPU_WISR_64_EIF_1_SHIFT                 (0U)
#define WKPU_WISR_64_EIF_1_WIDTH                 (32U)
#define WKPU_WISR_64_EIF_1(x)                    (((uint32_t)(((uint32_t)(x)) << WKPU_WISR_64_EIF_1_SHIFT)) & WKPU_WISR_64_EIF_1_MASK)
/*! @} */

/*! @name IRER_64 - Interrupt Request Enable */
/*! @{ */

#define WKPU_IRER_64_EIRE_1_MASK                 (0xFFFFFFFFU)
#define WKPU_IRER_64_EIRE_1_SHIFT                (0U)
#define WKPU_IRER_64_EIRE_1_WIDTH                (32U)
#define WKPU_IRER_64_EIRE_1(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_IRER_64_EIRE_1_SHIFT)) & WKPU_IRER_64_EIRE_1_MASK)
/*! @} */

/*! @name WRER_64 - Wake-Up Request Enable */
/*! @{ */

#define WKPU_WRER_64_WRE_1_MASK                  (0xFFFFFFFFU)
#define WKPU_WRER_64_WRE_1_SHIFT                 (0U)
#define WKPU_WRER_64_WRE_1_WIDTH                 (32U)
#define WKPU_WRER_64_WRE_1(x)                    (((uint32_t)(((uint32_t)(x)) << WKPU_WRER_64_WRE_1_SHIFT)) & WKPU_WRER_64_WRE_1_MASK)
/*! @} */

/*! @name WIREER_64 - Wake-Up and Interrupt Rising-Edge Event Enable */
/*! @{ */

#define WKPU_WIREER_64_IREE_1_MASK               (0xFFFFFFFFU)
#define WKPU_WIREER_64_IREE_1_SHIFT              (0U)
#define WKPU_WIREER_64_IREE_1_WIDTH              (32U)
#define WKPU_WIREER_64_IREE_1(x)                 (((uint32_t)(((uint32_t)(x)) << WKPU_WIREER_64_IREE_1_SHIFT)) & WKPU_WIREER_64_IREE_1_MASK)
/*! @} */

/*! @name WIFEER_64 - Wake-Up and Interrupt Falling-Edge Event Enable */
/*! @{ */

#define WKPU_WIFEER_64_IFEEx_1_MASK              (0xFFFFFFFFU)
#define WKPU_WIFEER_64_IFEEx_1_SHIFT             (0U)
#define WKPU_WIFEER_64_IFEEx_1_WIDTH             (32U)
#define WKPU_WIFEER_64_IFEEx_1(x)                (((uint32_t)(((uint32_t)(x)) << WKPU_WIFEER_64_IFEEx_1_SHIFT)) & WKPU_WIFEER_64_IFEEx_1_MASK)
/*! @} */

/*! @name WIFER_64 - Wake-Up and Interrupt Filter Enable */
/*! @{ */

#define WKPU_WIFER_64_IFE_1_MASK                 (0xFFFFFFFFU)
#define WKPU_WIFER_64_IFE_1_SHIFT                (0U)
#define WKPU_WIFER_64_IFE_1_WIDTH                (32U)
#define WKPU_WIFER_64_IFE_1(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_WIFER_64_IFE_1_SHIFT)) & WKPU_WIFER_64_IFE_1_MASK)
/*! @} */

/*! @name WBMSR_96 - Wake-Up Boot Mode Select */
/*! @{ */

#define WKPU_WBMSR_96_WBMS_96_MASK               (0xFU)
#define WKPU_WBMSR_96_WBMS_96_SHIFT              (0U)
#define WKPU_WBMSR_96_WBMS_96_WIDTH              (4U)
#define WKPU_WBMSR_96_WBMS_96(x)                 (((uint32_t)(((uint32_t)(x)) << WKPU_WBMSR_96_WBMS_96_SHIFT)) & WKPU_WBMSR_96_WBMS_96_MASK)
/*! @} */

/*! @name WISR_96 - Wake-Up and Interrupt Status Flag */
/*! @{ */

#define WKPU_WISR_96_EIF_1_MASK                  (0xFU)
#define WKPU_WISR_96_EIF_1_SHIFT                 (0U)
#define WKPU_WISR_96_EIF_1_WIDTH                 (4U)
#define WKPU_WISR_96_EIF_1(x)                    (((uint32_t)(((uint32_t)(x)) << WKPU_WISR_96_EIF_1_SHIFT)) & WKPU_WISR_96_EIF_1_MASK)
/*! @} */

/*! @name IRER_96 - Interrupt Request Enable */
/*! @{ */

#define WKPU_IRER_96_EIRE_1_MASK                 (0xFU)
#define WKPU_IRER_96_EIRE_1_SHIFT                (0U)
#define WKPU_IRER_96_EIRE_1_WIDTH                (4U)
#define WKPU_IRER_96_EIRE_1(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_IRER_96_EIRE_1_SHIFT)) & WKPU_IRER_96_EIRE_1_MASK)
/*! @} */

/*! @name WRER_96 - Wake-Up Request Enable */
/*! @{ */

#define WKPU_WRER_96_WRE_1_MASK                  (0xFU)
#define WKPU_WRER_96_WRE_1_SHIFT                 (0U)
#define WKPU_WRER_96_WRE_1_WIDTH                 (4U)
#define WKPU_WRER_96_WRE_1(x)                    (((uint32_t)(((uint32_t)(x)) << WKPU_WRER_96_WRE_1_SHIFT)) & WKPU_WRER_96_WRE_1_MASK)
/*! @} */

/*! @name WIREER_96 - Wake-Up and Interrupt Rising-Edge Event Enable */
/*! @{ */

#define WKPU_WIREER_96_IREE_1_MASK               (0xFU)
#define WKPU_WIREER_96_IREE_1_SHIFT              (0U)
#define WKPU_WIREER_96_IREE_1_WIDTH              (4U)
#define WKPU_WIREER_96_IREE_1(x)                 (((uint32_t)(((uint32_t)(x)) << WKPU_WIREER_96_IREE_1_SHIFT)) & WKPU_WIREER_96_IREE_1_MASK)
/*! @} */

/*! @name WIFEER_96 - Wake-Up and Interrupt Falling-Edge Event Enable */
/*! @{ */

#define WKPU_WIFEER_96_IFEEx_1_MASK              (0xFU)
#define WKPU_WIFEER_96_IFEEx_1_SHIFT             (0U)
#define WKPU_WIFEER_96_IFEEx_1_WIDTH             (4U)
#define WKPU_WIFEER_96_IFEEx_1(x)                (((uint32_t)(((uint32_t)(x)) << WKPU_WIFEER_96_IFEEx_1_SHIFT)) & WKPU_WIFEER_96_IFEEx_1_MASK)
/*! @} */

/*! @name WIFER_96 - Wake-Up and Interrupt Filter Enable */
/*! @{ */

#define WKPU_WIFER_96_IFE_2_MASK                 (0xFU)
#define WKPU_WIFER_96_IFE_2_SHIFT                (0U)
#define WKPU_WIFER_96_IFE_2_WIDTH                (4U)
#define WKPU_WIFER_96_IFE_2(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_WIFER_96_IFE_2_SHIFT)) & WKPU_WIFER_96_IFE_2_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group WKPU_Register_Masks */

/*!
 * @}
 */ /* end of group WKPU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_WKPU_H_) */
