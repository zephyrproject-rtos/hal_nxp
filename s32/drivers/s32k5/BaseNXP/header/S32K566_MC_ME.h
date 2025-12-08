/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MC_ME.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MC_ME
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
#if !defined(S32K566_MC_ME_H_)  /* Check if memory map has not been already included */
#define S32K566_MC_ME_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MC_ME Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_ME_Peripheral_Access_Layer MC_ME Peripheral Access Layer
 * @{
 */

/** MC_ME - Register Layout Typedef */
typedef struct MC_ME_Struct {
  __IO uint32_t CTL_KEY;                           /**< Control Key Register, offset: 0x0 */
  uint8_t RESERVED_0[252];
  __IO uint32_t PRTN0_PCONF;                       /**< Partition 0 Process Configuration Register, offset: 0x100 */
  __IO uint32_t PRTN0_PUPD;                        /**< Partition 0 Process Update Register, offset: 0x104 */
  __I  uint32_t PRTN0_STAT;                        /**< Partition 0 Status Register, offset: 0x108 */
  __IO uint32_t PRTN0_CORE_LOCKSTEP;               /**< Partition 0 Core Lockstep Control Register, offset: 0x10C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN0_COFB0_STAT;                  /**< Partition 0 COFB Set 0 Clock Status Register, offset: 0x110 */
  __I  uint32_t PRTN0_COFB1_STAT;                  /**< Partition 0 COFB Set 1 Clock Status Register, offset: 0x114 */
  __I  uint32_t PRTN0_COFB2_STAT;                  /**< Partition 0 COFB Set 2 Clock Status Register, offset: 0x118, available only on: LPE_MC_ME, MC_ME (missing on CPE_MC_ME) */
  __I  uint32_t PRTN0_COFB3_STAT;                  /**< Partition 0 COFB Set 3 Clock Status Register, offset: 0x11C, available only on: LPE_MC_ME (missing on CPE_MC_ME, MC_ME) */
  uint8_t RESERVED_1[16];
  __IO uint32_t PRTN0_COFB0_CLKEN;                 /**< Partition 0 COFB Set 0 Clock Enable Register, offset: 0x130 */
  __IO uint32_t PRTN0_COFB1_CLKEN;                 /**< Partition 0 COFB Set 1 Clock Enable Register, offset: 0x134 */
  __IO uint32_t PRTN0_COFB2_CLKEN;                 /**< Partition 0 COFB Set 2 Clock Enable Register, offset: 0x138, available only on: LPE_MC_ME, MC_ME (missing on CPE_MC_ME) */
  __IO uint32_t PRTN0_COFB3_CLKEN;                 /**< Partition 0 COFB Set 3 Clock Enable Register, offset: 0x13C, available only on: LPE_MC_ME (missing on CPE_MC_ME, MC_ME) */
  __IO uint32_t PRTN0_CORE0_PCONF;                 /**< Partition 0 Core 0 Process Configuration Register, offset: 0x140 */
  __IO uint32_t PRTN0_CORE0_PUPD;                  /**< Partition 0 Core 0 Process Update Register, offset: 0x144 */
  __I  uint32_t PRTN0_CORE0_STAT;                  /**< Partition 0 Core 0 Status Register, offset: 0x148 */
  __IO uint32_t PRTN0_CORE0_ADDR;                  /**< Partition 0 Core 0 Address Register, offset: 0x14C */
  uint8_t RESERVED_2[16];
  __IO uint32_t PRTN0_CORE1_PCONF;                 /**< Partition 0 Core 1 Process Configuration Register, offset: 0x160, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE1_PUPD;                  /**< Partition 0 Core 1 Process Update Register, offset: 0x164, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  __I  uint32_t PRTN0_CORE1_STAT;                  /**< Partition 0 Core 1 Status Register, offset: 0x168, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE1_ADDR;                  /**< Partition 0 Core 1 Address Register, offset: 0x16C, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  uint8_t RESERVED_3[16];
  __IO uint32_t PRTN0_CORE2_PCONF;                 /**< Partition 0 Core 2 Process Configuration Register, offset: 0x180, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE2_PUPD;                  /**< Partition 0 Core 2 Process Update Register, offset: 0x184, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN0_CORE2_STAT;                  /**< Partition 0 Core 2 Status Register, offset: 0x188, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE2_ADDR;                  /**< Partition 0 Core 2 Address Register, offset: 0x18C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_4[16];
  __IO uint32_t PRTN0_CORE3_PCONF;                 /**< Partition 0 Core 3 Process Configuration Register, offset: 0x1A0, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE3_PUPD;                  /**< Partition 0 Core 3 Process Update Register, offset: 0x1A4, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN0_CORE3_STAT;                  /**< Partition 0 Core 3 Status Register, offset: 0x1A8, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE3_ADDR;                  /**< Partition 0 Core 3 Address Register, offset: 0x1AC, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_5[16];
  __IO uint32_t PRTN0_CORE4_PCONF;                 /**< Partition 0 Core 4 Process Configuration Register, offset: 0x1C0, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE4_PUPD;                  /**< Partition 0 Core 4 Process Update Register, offset: 0x1C4, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN0_CORE4_STAT;                  /**< Partition 0 Core 4 Status Register, offset: 0x1C8, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE4_ADDR;                  /**< Partition 0 Core 4 Address Register, offset: 0x1CC, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_6[16];
  __IO uint32_t PRTN0_CORE5_PCONF;                 /**< Partition 0 Core 5 Process Configuration Register, offset: 0x1E0, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE5_PUPD;                  /**< Partition 0 Core 5 Process Update Register, offset: 0x1E4, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN0_CORE5_STAT;                  /**< Partition 0 Core 5 Status Register, offset: 0x1E8, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE5_ADDR;                  /**< Partition 0 Core 5 Address Register, offset: 0x1EC, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_7[24];
  __I  uint32_t PRTN0_CORE6_STAT;                  /**< Partition 0 Core 6 Status Register, offset: 0x208, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN0_CORE6_ADDR;                  /**< Partition 0 Core 6 Address Register, offset: 0x20C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_8[16];
  __IO uint32_t PRTN0_CORE7_PCONF;                 /**< Partition 0 Core 7 Process Configuration Register, offset: 0x220, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE7_PUPD;                  /**< Partition 0 Core 7 Process Update Register, offset: 0x224, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN0_CORE7_STAT;                  /**< Partition 0 Core 7 Status Register, offset: 0x228, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN0_CORE7_ADDR;                  /**< Partition 0 Core 7 Address Register, offset: 0x22C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_9[208];
  __IO uint32_t PRTN1_PCONF;                       /**< Partition 1 Process Configuration Register, offset: 0x300, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  __IO uint32_t PRTN1_PUPD;                        /**< Partition 1 Process Update Register, offset: 0x304, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  __I  uint32_t PRTN1_STAT;                        /**< Partition 1 Status Register, offset: 0x308, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  uint8_t RESERVED_10[4];
  __I  uint32_t PRTN1_COFB0_STAT;                  /**< Partition 1 COFB Set 0 Clock Status Register, offset: 0x310, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  __I  uint32_t PRTN1_COFB1_STAT;                  /**< Partition 1 COFB Set 1 Clock Status Register, offset: 0x314, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_11[24];
  __IO uint32_t PRTN1_COFB0_CLKEN;                 /**< Partition 1 COFB Set 0 Clock Enable Register, offset: 0x330, available only on: CPE_MC_ME, MC_ME (missing on LPE_MC_ME) */
  __IO uint32_t PRTN1_COFB1_CLKEN;                 /**< Partition 1 COFB Set 1 Clock Enable Register, offset: 0x334, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_12[8];
  __IO uint32_t PRTN1_CORE0_PCONF;                 /**< Partition 1 Core 0 Process Configuration Register, offset: 0x340, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN1_CORE0_PUPD;                  /**< Partition 1 Core 0 Process Update Register, offset: 0x344, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN1_CORE0_STAT;                  /**< Partition 1 Core 0 Status Register, offset: 0x348, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN1_CORE0_ADDR;                  /**< Partition 1 Core 0 Address Register, offset: 0x34C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_13[432];
  __IO uint32_t PRTN2_PCONF;                       /**< Partition 2 Process Configuration Register, offset: 0x500, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN2_PUPD;                        /**< Partition 2 Process Update Register, offset: 0x504, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN2_STAT;                        /**< Partition 2 Status Register, offset: 0x508, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_14[4];
  __I  uint32_t PRTN2_COFB0_STAT;                  /**< Partition 2 COFB Set 0 Clock Status Register, offset: 0x510, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN2_COFB1_STAT;                  /**< Partition 2 COFB Set 1 Clock Status Register, offset: 0x514, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN2_COFB2_STAT;                  /**< Partition 2 COFB Set 2 Clock Status Register, offset: 0x518, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN2_COFB3_STAT;                  /**< Partition 2 COFB Set 3 Clock Status Register, offset: 0x51C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_15[16];
  __IO uint32_t PRTN2_COFB0_CLKEN;                 /**< Partition 2 COFB Set 0 Clock Enable Register, offset: 0x530, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN2_COFB1_CLKEN;                 /**< Partition 2 COFB Set 1 Clock Enable Register, offset: 0x534, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN2_COFB2_CLKEN;                 /**< Partition 2 COFB Set 2 Clock Enable Register, offset: 0x538, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN2_COFB3_CLKEN;                 /**< Partition 2 COFB Set 3 Clock Enable Register, offset: 0x53C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_16[448];
  __IO uint32_t PRTN3_PCONF;                       /**< Partition 3 Process Configuration Register, offset: 0x700, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN3_PUPD;                        /**< Partition 3 Process Update Register, offset: 0x704, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN3_STAT;                        /**< Partition 3 Status Register, offset: 0x708, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_17[4];
  __I  uint32_t PRTN3_COFB0_STAT;                  /**< Partition 3 COFB Set 0 Clock Status Register, offset: 0x710, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN3_COFB1_STAT;                  /**< Partition 3 COFB Set 1 Clock Status Register, offset: 0x714, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_18[24];
  __IO uint32_t PRTN3_COFB0_CLKEN;                 /**< Partition 3 COFB Set 0 Clock Enable Register, offset: 0x730, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN3_COFB1_CLKEN;                 /**< Partition 3 COFB Set 1 Clock Enable Register, offset: 0x734, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_19[456];
  __IO uint32_t PRTN4_PCONF;                       /**< Partition 4 Process Configuration Register, offset: 0x900, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN4_PUPD;                        /**< Partition 4 Process Update Register, offset: 0x904, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN4_STAT;                        /**< Partition 4 Status Register, offset: 0x908, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_20[4];
  __I  uint32_t PRTN4_COFB0_STAT;                  /**< Partition 4 COFB Set 0 Clock Status Register, offset: 0x910, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN4_COFB1_STAT;                  /**< Partition 4 COFB Set 1 Clock Status Register, offset: 0x914, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_21[24];
  __IO uint32_t PRTN4_COFB0_CLKEN;                 /**< Partition 4 COFB Set 0 Clock Enable Register, offset: 0x930, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN4_COFB1_CLKEN;                 /**< Partition 4 COFB Set 1 Clock Enable Register, offset: 0x934, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_22[456];
  __IO uint32_t PRTN5_PCONF;                       /**< Partition 5 Process Configuration Register, offset: 0xB00, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN5_PUPD;                        /**< Partition 5 Process Update Register, offset: 0xB04, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN5_STAT;                        /**< Partition 5 Status Register, offset: 0xB08, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_23[4];
  __I  uint32_t PRTN5_COFB0_STAT;                  /**< Partition 5 COFB Set 0 Clock Status Register, offset: 0xB10, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN5_COFB1_STAT;                  /**< Partition 5 COFB Set 1 Clock Status Register, offset: 0xB14, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN5_COFB2_STAT;                  /**< Partition 5 COFB Set 2 Clock Status Register, offset: 0xB18, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __I  uint32_t PRTN5_COFB3_STAT;                  /**< Partition 5 COFB Set 3 Clock Status Register, offset: 0xB1C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  uint8_t RESERVED_24[16];
  __IO uint32_t PRTN5_COFB0_CLKEN;                 /**< Partition 5 COFB Set 0 Clock Enable Register, offset: 0xB30, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN5_COFB1_CLKEN;                 /**< Partition 5 COFB Set 1 Clock Enable Register, offset: 0xB34, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN5_COFB2_CLKEN;                 /**< Partition 5 COFB Set 2 Clock Enable Register, offset: 0xB38, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
  __IO uint32_t PRTN5_COFB3_CLKEN;                 /**< Partition 5 COFB Set 3 Clock Enable Register, offset: 0xB3C, available only on: MC_ME (missing on CPE_MC_ME, LPE_MC_ME) */
} MC_ME_Type, *MC_ME_MemMapPtr;

/** Number of instances of the MC_ME module. */
#define MC_ME_INSTANCE_COUNT                     (3u)

/* MC_ME - Peripheral instance base addresses */
/** Peripheral CPE_MC_ME base address */
#define IP_CPE_MC_ME_BASE                        (0x41050000u)
/** Peripheral CPE_MC_ME base pointer */
#define IP_CPE_MC_ME                             ((MC_ME_Type *)IP_CPE_MC_ME_BASE)
/** Peripheral LPE_MC_ME base address */
#define IP_LPE_MC_ME_BASE                        (0x4206C000u)
/** Peripheral LPE_MC_ME base pointer */
#define IP_LPE_MC_ME                             ((MC_ME_Type *)IP_LPE_MC_ME_BASE)
/** Peripheral MC_ME base address */
#define IP_MC_ME_BASE                            (0x40498000u)
/** Peripheral MC_ME base pointer */
#define IP_MC_ME                                 ((MC_ME_Type *)IP_MC_ME_BASE)
/** Array initializer of MC_ME peripheral base addresses */
#define IP_MC_ME_BASE_ADDRS                      { IP_CPE_MC_ME_BASE, IP_LPE_MC_ME_BASE, IP_MC_ME_BASE }
/** Array initializer of MC_ME peripheral base pointers */
#define IP_MC_ME_BASE_PTRS                       { IP_CPE_MC_ME, IP_LPE_MC_ME, IP_MC_ME }

/* ----------------------------------------------------------------------------
   -- MC_ME Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_ME_Register_Masks MC_ME Register Masks
 * @{
 */

/*! @name CTL_KEY - Control Key Register */
/*! @{ */

#define MC_ME_CTL_KEY_KEY_MASK                   (0xFFFFU)
#define MC_ME_CTL_KEY_KEY_SHIFT                  (0U)
#define MC_ME_CTL_KEY_KEY_WIDTH                  (16U)
#define MC_ME_CTL_KEY_KEY(x)                     (((uint32_t)(((uint32_t)(x)) << MC_ME_CTL_KEY_KEY_SHIFT)) & MC_ME_CTL_KEY_KEY_MASK)
/*! @} */

/*! @name PRTN0_PCONF - Partition 0 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN0_PCONF_PCE_SHIFT              (0U)
#define MC_ME_PRTN0_PCONF_PCE_WIDTH              (1U)
#define MC_ME_PRTN0_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_PCONF_PCE_SHIFT)) & MC_ME_PRTN0_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN0_PUPD - Partition 0 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN0_PUPD_PCUD_SHIFT              (0U)
#define MC_ME_PRTN0_PUPD_PCUD_WIDTH              (1U)
#define MC_ME_PRTN0_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_PUPD_PCUD_SHIFT)) & MC_ME_PRTN0_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN0_STAT - Partition 0 Status Register */
/*! @{ */

#define MC_ME_PRTN0_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN0_STAT_PCS_SHIFT               (0U)
#define MC_ME_PRTN0_STAT_PCS_WIDTH               (1U)
#define MC_ME_PRTN0_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_STAT_PCS_SHIFT)) & MC_ME_PRTN0_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN0_CORE_LOCKSTEP - Partition 0 Core Lockstep Control Register */
/*! @{ */

#define MC_ME_PRTN0_CORE_LOCKSTEP_LS0_MASK       (0x1U)
#define MC_ME_PRTN0_CORE_LOCKSTEP_LS0_SHIFT      (0U)
#define MC_ME_PRTN0_CORE_LOCKSTEP_LS0_WIDTH      (1U)
#define MC_ME_PRTN0_CORE_LOCKSTEP_LS0(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE_LOCKSTEP_LS0_SHIFT)) & MC_ME_PRTN0_CORE_LOCKSTEP_LS0_MASK)

#define MC_ME_PRTN0_CORE_LOCKSTEP_LS2_MASK       (0x4U)
#define MC_ME_PRTN0_CORE_LOCKSTEP_LS2_SHIFT      (2U)
#define MC_ME_PRTN0_CORE_LOCKSTEP_LS2_WIDTH      (1U)
#define MC_ME_PRTN0_CORE_LOCKSTEP_LS2(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE_LOCKSTEP_LS2_SHIFT)) & MC_ME_PRTN0_CORE_LOCKSTEP_LS2_MASK)
/*! @} */

/*! @name PRTN0_COFB0_STAT - Partition 0 COFB Set 0 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN0_COFB0_STAT_BLOCK0_MASK       (0x1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK0_SHIFT      (0U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK0_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK0(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK0_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK0_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK1_MASK       (0x2U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK1_SHIFT      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK1_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK1(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK1_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK1_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK2_MASK       (0x4U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK2_SHIFT      (2U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK2_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK2(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK2_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK2_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK3_MASK       (0x8U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK3_SHIFT      (3U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK3_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK3(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK3_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK3_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK4_MASK       (0x10U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK4_SHIFT      (4U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK4_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK4(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK4_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK4_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK5_MASK       (0x20U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK5_SHIFT      (5U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK5_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK5(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK5_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK5_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK6_MASK       (0x40U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK6_SHIFT      (6U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK6_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK6(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK6_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK6_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK7_MASK       (0x80U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK7_SHIFT      (7U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK7_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK7(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK7_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK7_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK8_MASK       (0x100U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK8_SHIFT      (8U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK8_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK8(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK8_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK8_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK9_MASK       (0x200U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK9_SHIFT      (9U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK9_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK9(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK9_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK9_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK10_MASK      (0x400U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK10_SHIFT     (10U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK10_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK10(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK10_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK10_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK11_MASK      (0x800U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK11_SHIFT     (11U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK11_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK11(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK11_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK11_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK12_MASK      (0x1000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK12_SHIFT     (12U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK12_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK12(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK12_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK12_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK13_MASK      (0x2000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK13_SHIFT     (13U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK13_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK13(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK13_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK13_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK14_MASK      (0x4000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK14_SHIFT     (14U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK14_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK14(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK14_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK14_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK15_MASK      (0x8000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK15_SHIFT     (15U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK15_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK15(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK15_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK15_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK16_MASK      (0x10000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK16_SHIFT     (16U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK16_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK16(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK16_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK16_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK17_MASK      (0x20000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK17_SHIFT     (17U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK17_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK17(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK17_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK17_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK18_MASK      (0x40000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK18_SHIFT     (18U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK18_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK18(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK18_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK18_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK19_MASK      (0x80000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK19_SHIFT     (19U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK19_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK19(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK19_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK19_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK20_MASK      (0x100000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK20_SHIFT     (20U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK20_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK20(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK20_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK20_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK21_MASK      (0x200000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK21_SHIFT     (21U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK21_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK21(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK21_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK21_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK22_MASK      (0x400000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK22_SHIFT     (22U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK22_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK22(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK22_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK22_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK23_MASK      (0x800000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK23_SHIFT     (23U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK23_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK23(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK23_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK23_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK24_MASK      (0x1000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK24_SHIFT     (24U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK24_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK24(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK24_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK24_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK25_MASK      (0x2000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK25_SHIFT     (25U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK25_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK25(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK25_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK25_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK26_MASK      (0x4000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK26_SHIFT     (26U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK26_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK26(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK26_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK26_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK27_MASK      (0x8000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK27_SHIFT     (27U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK27_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK27(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK27_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK27_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK28_MASK      (0x10000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK28_SHIFT     (28U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK28_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK28(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK28_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK28_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK29_MASK      (0x20000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK29_SHIFT     (29U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK29_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK29(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK29_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK29_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK30_MASK      (0x40000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK30_SHIFT     (30U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK30_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK30(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK30_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK30_MASK)

#define MC_ME_PRTN0_COFB0_STAT_BLOCK31_MASK      (0x80000000U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK31_SHIFT     (31U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK31_WIDTH     (1U)
#define MC_ME_PRTN0_COFB0_STAT_BLOCK31(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_STAT_BLOCK31_SHIFT)) & MC_ME_PRTN0_COFB0_STAT_BLOCK31_MASK)
/*! @} */

/*! @name PRTN0_COFB1_STAT - Partition 0 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN0_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK32_SHIFT     (0U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK32_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK33_MASK      (0x2U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK33_SHIFT     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK33_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK33(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK33_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK33_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK34_MASK      (0x4U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK34_SHIFT     (2U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK34_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK34(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK34_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK34_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK35_SHIFT     (3U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK35_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK36_MASK      (0x10U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK36_SHIFT     (4U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK36_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK36(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK36_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK36_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK37_MASK      (0x20U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK37_SHIFT     (5U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK37_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK37(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK37_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK37_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK38_SHIFT     (6U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK38_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK39_SHIFT     (7U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK39_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK40_MASK      (0x100U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK40_SHIFT     (8U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK40_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK40(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK40_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK40_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK41_MASK      (0x200U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK41_SHIFT     (9U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK41_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK41(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK41_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK41_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK42_MASK      (0x400U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK42_SHIFT     (10U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK42_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK42(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK42_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK42_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK43_MASK      (0x800U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK43_SHIFT     (11U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK43_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK43(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK43_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK43_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK44_MASK      (0x1000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK44_SHIFT     (12U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK44_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK44(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK44_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK44_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK45_SHIFT     (13U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK45_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK46_MASK      (0x4000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK46_SHIFT     (14U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK46_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK46(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK46_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK46_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK47_MASK      (0x8000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK47_SHIFT     (15U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK47_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK47(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK47_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK47_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK48_MASK      (0x10000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK48_SHIFT     (16U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK48_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK48(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK48_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK48_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK49_MASK      (0x20000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK49_SHIFT     (17U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK49_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK49(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK49_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK49_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK50_MASK      (0x40000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK50_SHIFT     (18U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK50_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK50(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK50_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK50_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK51_MASK      (0x80000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK51_SHIFT     (19U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK51_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK51(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK51_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK51_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK52_MASK      (0x100000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK52_SHIFT     (20U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK52_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK52(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK52_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK52_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK53_MASK      (0x200000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK53_SHIFT     (21U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK53_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK53(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK53_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK53_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK54_MASK      (0x400000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK54_SHIFT     (22U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK54_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK54(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK54_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK54_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK55_MASK      (0x800000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK55_SHIFT     (23U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK55_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK55(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK55_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK55_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK56_MASK      (0x1000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK56_SHIFT     (24U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK56_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK56(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK56_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK56_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK57_MASK      (0x2000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK57_SHIFT     (25U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK57_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK57(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK57_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK57_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK58_MASK      (0x4000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK58_SHIFT     (26U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK58_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK58(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK58_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK58_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK59_MASK      (0x8000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK59_SHIFT     (27U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK59_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK59(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK59_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK59_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK60_MASK      (0x10000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK60_SHIFT     (28U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK60_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK60(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK60_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK60_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK61_MASK      (0x20000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK61_SHIFT     (29U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK61_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK61(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK61_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK61_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK62_MASK      (0x40000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK62_SHIFT     (30U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK62_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK62(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK62_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK62_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK63_MASK      (0x80000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK63_SHIFT     (31U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK63_WIDTH     (1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK63(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK63_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK63_MASK)
/*! @} */

/*! @name PRTN0_COFB2_STAT - Partition 0 COFB Set 2 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN0_COFB2_STAT_BLOCK64_MASK      (0x1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK64_SHIFT     (0U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK64_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK64(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK64_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK64_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK65_MASK      (0x2U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK65_SHIFT     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK65_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK65(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK65_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK65_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK66_MASK      (0x4U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK66_SHIFT     (2U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK66_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK66(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK66_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK66_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK67_MASK      (0x8U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK67_SHIFT     (3U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK67_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK67(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK67_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK67_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK68_MASK      (0x10U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK68_SHIFT     (4U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK68_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK68(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK68_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK68_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK69_MASK      (0x20U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK69_SHIFT     (5U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK69_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK69(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK69_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK69_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK70_MASK      (0x40U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK70_SHIFT     (6U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK70_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK70(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK70_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK70_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK71_MASK      (0x80U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK71_SHIFT     (7U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK71_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK71(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK71_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK71_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK72_MASK      (0x100U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK72_SHIFT     (8U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK72_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK72(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK72_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK72_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK73_MASK      (0x200U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK73_SHIFT     (9U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK73_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK73(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK73_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK73_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK74_MASK      (0x400U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK74_SHIFT     (10U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK74_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK74(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK74_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK74_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK75_MASK      (0x800U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK75_SHIFT     (11U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK75_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK75(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK75_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK75_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK76_MASK      (0x1000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK76_SHIFT     (12U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK76_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK76(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK76_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK76_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK77_MASK      (0x2000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK77_SHIFT     (13U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK77_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK77(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK77_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK77_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK78_MASK      (0x4000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK78_SHIFT     (14U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK78_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK78(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK78_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK78_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK79_MASK      (0x8000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK79_SHIFT     (15U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK79_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK79(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK79_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK79_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK80_MASK      (0x10000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK80_SHIFT     (16U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK80_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK80(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK80_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK80_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK81_MASK      (0x20000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK81_SHIFT     (17U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK81_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK81(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK81_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK81_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK82_MASK      (0x40000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK82_SHIFT     (18U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK82_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK82(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK82_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK82_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK83_MASK      (0x80000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK83_SHIFT     (19U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK83_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK83(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK83_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK83_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK84_MASK      (0x100000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK84_SHIFT     (20U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK84_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK84(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK84_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK84_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK85_MASK      (0x200000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK85_SHIFT     (21U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK85_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK85(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK85_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK85_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK86_MASK      (0x400000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK86_SHIFT     (22U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK86_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK86(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK86_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK86_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK87_MASK      (0x800000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK87_SHIFT     (23U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK87_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK87(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK87_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK87_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK88_MASK      (0x1000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK88_SHIFT     (24U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK88_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK88(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK88_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK88_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK89_MASK      (0x2000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK89_SHIFT     (25U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK89_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK89(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK89_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK89_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK90_MASK      (0x4000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK90_SHIFT     (26U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK90_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK90(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK90_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK90_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK91_MASK      (0x8000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK91_SHIFT     (27U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK91_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK91(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK91_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK91_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK92_MASK      (0x10000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK92_SHIFT     (28U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK92_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK92(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK92_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK92_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK93_MASK      (0x20000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK93_SHIFT     (29U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK93_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK93(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK93_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK93_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK94_MASK      (0x40000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK94_SHIFT     (30U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK94_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK94(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK94_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK94_MASK)

#define MC_ME_PRTN0_COFB2_STAT_BLOCK95_MASK      (0x80000000U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK95_SHIFT     (31U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK95_WIDTH     (1U)
#define MC_ME_PRTN0_COFB2_STAT_BLOCK95(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_STAT_BLOCK95_SHIFT)) & MC_ME_PRTN0_COFB2_STAT_BLOCK95_MASK)
/*! @} */

/*! @name PRTN0_COFB3_STAT - Partition 0 COFB Set 3 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN0_COFB3_STAT_BLOCK96_MASK      (0x1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK96_SHIFT     (0U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK96_WIDTH     (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK96(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK96_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK96_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK97_MASK      (0x2U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK97_SHIFT     (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK97_WIDTH     (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK97(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK97_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK97_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK98_MASK      (0x4U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK98_SHIFT     (2U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK98_WIDTH     (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK98(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK98_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK98_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK99_MASK      (0x8U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK99_SHIFT     (3U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK99_WIDTH     (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK99(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK99_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK99_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK100_MASK     (0x10U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK100_SHIFT    (4U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK100_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK100(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK100_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK100_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK101_MASK     (0x20U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK101_SHIFT    (5U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK101_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK101(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK101_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK101_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK102_MASK     (0x40U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK102_SHIFT    (6U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK102_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK102(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK102_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK102_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK103_MASK     (0x80U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK103_SHIFT    (7U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK103_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK103(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK103_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK103_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK104_MASK     (0x100U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK104_SHIFT    (8U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK104_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK104(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK104_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK104_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK105_MASK     (0x200U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK105_SHIFT    (9U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK105_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK105(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK105_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK105_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK106_MASK     (0x400U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK106_SHIFT    (10U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK106_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK106(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK106_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK106_MASK)

#define MC_ME_PRTN0_COFB3_STAT_BLOCK107_MASK     (0x800U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK107_SHIFT    (11U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK107_WIDTH    (1U)
#define MC_ME_PRTN0_COFB3_STAT_BLOCK107(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_STAT_BLOCK107_SHIFT)) & MC_ME_PRTN0_COFB3_STAT_BLOCK107_MASK)
/*! @} */

/*! @name PRTN0_COFB0_CLKEN - Partition 0 COFB Set 0 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN0_COFB0_CLKEN_REQ1_MASK        (0x2U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ1_SHIFT       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ1_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ1(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ1_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ1_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ2_MASK        (0x4U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ2_SHIFT       (2U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ2_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ2(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ2_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ2_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ3_MASK        (0x8U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ3_SHIFT       (3U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ3_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ3(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ3_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ3_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ4_MASK        (0x10U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ4_SHIFT       (4U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ4_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ4(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ4_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ4_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ5_MASK        (0x20U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ5_SHIFT       (5U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ5_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ5(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ5_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ5_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ6_MASK        (0x40U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ6_SHIFT       (6U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ6_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ6(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ6_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ6_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ7_MASK        (0x80U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ7_SHIFT       (7U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ7_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ7(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ7_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ7_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ8_MASK        (0x100U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ8_SHIFT       (8U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ8_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ8(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ8_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ8_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ9_MASK        (0x200U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ9_SHIFT       (9U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ9_WIDTH       (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ9(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ9_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ9_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ10_MASK       (0x400U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ10_SHIFT      (10U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ10_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ10(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ10_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ10_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ11_MASK       (0x800U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ11_SHIFT      (11U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ11_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ11(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ11_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ11_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ12_MASK       (0x1000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ12_SHIFT      (12U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ12_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ12(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ12_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ12_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ13_MASK       (0x2000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ13_SHIFT      (13U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ13_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ13(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ13_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ13_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ14_MASK       (0x4000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ14_SHIFT      (14U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ14_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ14(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ14_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ14_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ15_MASK       (0x8000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ15_SHIFT      (15U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ15_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ15(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ15_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ15_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ16_MASK       (0x10000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ16_SHIFT      (16U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ16_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ16(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ16_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ16_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ17_MASK       (0x20000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ17_SHIFT      (17U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ17_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ17(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ17_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ17_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ18_MASK       (0x40000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ18_SHIFT      (18U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ18_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ18(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ18_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ18_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ19_MASK       (0x80000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ19_SHIFT      (19U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ19_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ19(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ19_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ19_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ20_MASK       (0x100000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ20_SHIFT      (20U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ20_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ20(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ20_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ20_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ21_MASK       (0x200000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ21_SHIFT      (21U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ21_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ21(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ21_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ21_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ22_MASK       (0x400000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ22_SHIFT      (22U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ22_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ22(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ22_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ22_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ23_MASK       (0x800000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ23_SHIFT      (23U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ23_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ23(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ23_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ23_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ24_MASK       (0x1000000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ24_SHIFT      (24U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ24_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ24(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ24_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ24_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ25_MASK       (0x2000000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ25_SHIFT      (25U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ25_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ25(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ25_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ25_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ30_MASK       (0x40000000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ30_SHIFT      (30U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ30_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ30(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ30_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ30_MASK)

#define MC_ME_PRTN0_COFB0_CLKEN_REQ31_MASK       (0x80000000U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ31_SHIFT      (31U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ31_WIDTH      (1U)
#define MC_ME_PRTN0_COFB0_CLKEN_REQ31(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB0_CLKEN_REQ31_SHIFT)) & MC_ME_PRTN0_COFB0_CLKEN_REQ31_MASK)
/*! @} */

/*! @name PRTN0_COFB1_CLKEN - Partition 0 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN0_COFB1_CLKEN_REQ33_MASK       (0x2U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ33_SHIFT      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ33_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ33(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ33_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ33_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ34_MASK       (0x4U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ34_SHIFT      (2U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ34_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ34(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ34_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ34_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ35_MASK       (0x8U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ35_SHIFT      (3U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ35_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ35(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ35_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ35_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ40_MASK       (0x100U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ40_SHIFT      (8U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ40_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ40(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ40_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ40_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ41_MASK       (0x200U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ41_SHIFT      (9U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ41_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ41(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ41_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ41_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ46_MASK       (0x4000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ46_SHIFT      (14U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ46_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ46(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ46_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ46_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ47_MASK       (0x8000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ47_SHIFT      (15U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ47_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ47(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ47_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ47_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ48_MASK       (0x10000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ48_SHIFT      (16U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ48_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ48(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ48_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ48_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ49_MASK       (0x20000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ49_SHIFT      (17U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ49_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ49(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ49_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ49_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ53_MASK       (0x200000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ53_SHIFT      (21U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ53_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ53(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ53_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ53_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ54_MASK       (0x400000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ54_SHIFT      (22U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ54_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ54(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ54_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ54_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ55_MASK       (0x800000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ55_SHIFT      (23U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ55_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ55(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ55_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ55_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ56_MASK       (0x1000000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ56_SHIFT      (24U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ56_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ56(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ56_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ56_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ57_MASK       (0x2000000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ57_SHIFT      (25U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ57_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ57(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ57_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ57_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ60_MASK       (0x10000000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ60_SHIFT      (28U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ60_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ60(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ60_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ60_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ61_MASK       (0x20000000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ61_SHIFT      (29U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ61_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ61(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ61_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ61_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ62_MASK       (0x40000000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ62_SHIFT      (30U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ62_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ62(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ62_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ62_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ63_MASK       (0x80000000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ63_SHIFT      (31U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ63_WIDTH      (1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ63(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ63_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ63_MASK)
/*! @} */

/*! @name PRTN0_COFB2_CLKEN - Partition 0 COFB Set 2 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN0_COFB2_CLKEN_REQ64_MASK       (0x1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ64_SHIFT      (0U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ64_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ64(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ64_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ64_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ65_MASK       (0x2U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ65_SHIFT      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ65_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ65(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ65_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ65_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ66_MASK       (0x4U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ66_SHIFT      (2U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ66_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ66(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ66_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ66_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ67_MASK       (0x8U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ67_SHIFT      (3U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ67_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ67(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ67_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ67_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ68_MASK       (0x10U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ68_SHIFT      (4U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ68_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ68(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ68_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ68_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ69_MASK       (0x20U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ69_SHIFT      (5U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ69_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ69(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ69_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ69_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ70_MASK       (0x40U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ70_SHIFT      (6U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ70_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ70(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ70_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ70_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ71_MASK       (0x80U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ71_SHIFT      (7U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ71_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ71(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ71_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ71_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ73_MASK       (0x200U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ73_SHIFT      (9U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ73_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ73(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ73_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ73_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ74_MASK       (0x400U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ74_SHIFT      (10U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ74_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ74(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ74_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ74_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ75_MASK       (0x800U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ75_SHIFT      (11U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ75_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ75(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ75_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ75_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ76_MASK       (0x1000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ76_SHIFT      (12U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ76_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ76(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ76_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ76_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ79_MASK       (0x8000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ79_SHIFT      (15U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ79_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ79(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ79_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ79_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ80_MASK       (0x10000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ80_SHIFT      (16U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ80_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ80(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ80_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ80_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ81_MASK       (0x20000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ81_SHIFT      (17U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ81_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ81(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ81_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ81_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ82_MASK       (0x40000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ82_SHIFT      (18U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ82_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ82(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ82_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ82_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ83_MASK       (0x80000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ83_SHIFT      (19U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ83_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ83(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ83_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ83_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ85_MASK       (0x200000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ85_SHIFT      (21U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ85_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ85(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ85_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ85_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ86_MASK       (0x400000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ86_SHIFT      (22U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ86_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ86(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ86_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ86_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ87_MASK       (0x800000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ87_SHIFT      (23U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ87_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ87(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ87_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ87_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ88_MASK       (0x1000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ88_SHIFT      (24U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ88_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ88(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ88_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ88_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ89_MASK       (0x2000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ89_SHIFT      (25U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ89_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ89(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ89_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ89_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ90_MASK       (0x4000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ90_SHIFT      (26U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ90_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ90(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ90_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ90_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ91_MASK       (0x8000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ91_SHIFT      (27U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ91_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ91(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ91_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ91_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ92_MASK       (0x10000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ92_SHIFT      (28U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ92_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ92(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ92_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ92_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ93_MASK       (0x20000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ93_SHIFT      (29U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ93_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ93(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ93_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ93_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ94_MASK       (0x40000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ94_SHIFT      (30U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ94_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ94(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ94_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ94_MASK)

#define MC_ME_PRTN0_COFB2_CLKEN_REQ95_MASK       (0x80000000U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ95_SHIFT      (31U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ95_WIDTH      (1U)
#define MC_ME_PRTN0_COFB2_CLKEN_REQ95(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB2_CLKEN_REQ95_SHIFT)) & MC_ME_PRTN0_COFB2_CLKEN_REQ95_MASK)
/*! @} */

/*! @name PRTN0_COFB3_CLKEN - Partition 0 COFB Set 3 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN0_COFB3_CLKEN_REQ96_MASK       (0x1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ96_SHIFT      (0U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ96_WIDTH      (1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ96(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_CLKEN_REQ96_SHIFT)) & MC_ME_PRTN0_COFB3_CLKEN_REQ96_MASK)

#define MC_ME_PRTN0_COFB3_CLKEN_REQ97_MASK       (0x2U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ97_SHIFT      (1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ97_WIDTH      (1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ97(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_CLKEN_REQ97_SHIFT)) & MC_ME_PRTN0_COFB3_CLKEN_REQ97_MASK)

#define MC_ME_PRTN0_COFB3_CLKEN_REQ98_MASK       (0x4U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ98_SHIFT      (2U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ98_WIDTH      (1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ98(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_CLKEN_REQ98_SHIFT)) & MC_ME_PRTN0_COFB3_CLKEN_REQ98_MASK)

#define MC_ME_PRTN0_COFB3_CLKEN_REQ99_MASK       (0x8U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ99_SHIFT      (3U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ99_WIDTH      (1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ99(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_CLKEN_REQ99_SHIFT)) & MC_ME_PRTN0_COFB3_CLKEN_REQ99_MASK)

#define MC_ME_PRTN0_COFB3_CLKEN_REQ100_MASK      (0x10U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ100_SHIFT     (4U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ100_WIDTH     (1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ100(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_CLKEN_REQ100_SHIFT)) & MC_ME_PRTN0_COFB3_CLKEN_REQ100_MASK)

#define MC_ME_PRTN0_COFB3_CLKEN_REQ106_MASK      (0x400U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ106_SHIFT     (10U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ106_WIDTH     (1U)
#define MC_ME_PRTN0_COFB3_CLKEN_REQ106(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB3_CLKEN_REQ106_SHIFT)) & MC_ME_PRTN0_COFB3_CLKEN_REQ106_MASK)
/*! @} */

/*! @name PRTN0_CORE0_PCONF - Partition 0 Core 0 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE0_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN0_CORE0_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN0_CORE0_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE0_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE0_PUPD - Partition 0 Core 0 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE0_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN0_CORE0_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN0_CORE0_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE0_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE0_STAT - Partition 0 Core 0 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE0_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE0_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE0_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE0_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE0_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE0_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE0_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE0_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE0_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE0_ADDR - Partition 0 Core 0 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE0_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE0_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE0_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE0_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE1_PCONF - Partition 0 Core 1 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE1_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE1_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN0_CORE1_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN0_CORE1_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE1_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE1_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE1_PUPD - Partition 0 Core 1 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE1_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE1_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN0_CORE1_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN0_CORE1_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE1_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE1_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE1_STAT - Partition 0 Core 1 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE1_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE1_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE1_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE1_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE1_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE1_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE1_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE1_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE1_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE1_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE1_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE1_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE1_ADDR - Partition 0 Core 1 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE1_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE1_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE1_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE1_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE1_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE1_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE2_PCONF - Partition 0 Core 2 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE2_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE2_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN0_CORE2_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN0_CORE2_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE2_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE2_PUPD - Partition 0 Core 2 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE2_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE2_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN0_CORE2_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN0_CORE2_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE2_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE2_STAT - Partition 0 Core 2 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE2_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE2_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE2_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE2_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE2_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE2_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE2_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE2_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE2_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE2_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE2_ADDR - Partition 0 Core 2 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE2_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE2_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE2_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE2_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE2_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE3_PCONF - Partition 0 Core 3 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE3_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE3_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN0_CORE3_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN0_CORE3_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE3_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE3_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE3_PUPD - Partition 0 Core 3 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE3_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE3_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN0_CORE3_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN0_CORE3_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE3_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE3_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE3_STAT - Partition 0 Core 3 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE3_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE3_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE3_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE3_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE3_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE3_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE3_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE3_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE3_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE3_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE3_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE3_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE3_ADDR - Partition 0 Core 3 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE3_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE3_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE3_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE3_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE3_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE3_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE4_PCONF - Partition 0 Core 4 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE4_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE4_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN0_CORE4_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN0_CORE4_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE4_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE4_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE4_PUPD - Partition 0 Core 4 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE4_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE4_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN0_CORE4_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN0_CORE4_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE4_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE4_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE4_STAT - Partition 0 Core 4 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE4_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE4_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE4_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE4_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE4_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE4_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE4_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE4_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE4_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE4_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE4_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE4_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE4_ADDR - Partition 0 Core 4 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE4_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE4_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE4_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE4_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE4_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE4_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE5_PCONF - Partition 0 Core 5 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE5_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE5_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN0_CORE5_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN0_CORE5_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE5_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE5_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE5_PUPD - Partition 0 Core 5 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE5_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE5_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN0_CORE5_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN0_CORE5_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE5_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE5_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE5_STAT - Partition 0 Core 5 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE5_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE5_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE5_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE5_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE5_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE5_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE5_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE5_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE5_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE5_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE5_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE5_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE5_ADDR - Partition 0 Core 5 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE5_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE5_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE5_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE5_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE5_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE5_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE6_STAT - Partition 0 Core 6 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE6_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE6_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE6_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE6_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE6_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE6_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE6_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE6_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE6_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE6_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE6_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE6_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE6_ADDR - Partition 0 Core 6 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE6_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE6_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE6_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE6_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE6_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE6_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE7_PCONF - Partition 0 Core 7 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE7_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE7_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN0_CORE7_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN0_CORE7_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE7_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE7_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE7_PUPD - Partition 0 Core 7 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE7_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE7_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN0_CORE7_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN0_CORE7_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE7_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE7_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE7_STAT - Partition 0 Core 7 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE7_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE7_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN0_CORE7_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN0_CORE7_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE7_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE7_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE7_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE7_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN0_CORE7_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN0_CORE7_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE7_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE7_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE7_ADDR - Partition 0 Core 7 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE7_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE7_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN0_CORE7_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN0_CORE7_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE7_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE7_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN1_PCONF - Partition 1 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN1_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN1_PCONF_PCE_SHIFT              (0U)
#define MC_ME_PRTN1_PCONF_PCE_WIDTH              (1U)
#define MC_ME_PRTN1_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_PCONF_PCE_SHIFT)) & MC_ME_PRTN1_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN1_PUPD - Partition 1 Process Update Register */
/*! @{ */

#define MC_ME_PRTN1_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN1_PUPD_PCUD_SHIFT              (0U)
#define MC_ME_PRTN1_PUPD_PCUD_WIDTH              (1U)
#define MC_ME_PRTN1_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_PUPD_PCUD_SHIFT)) & MC_ME_PRTN1_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN1_STAT - Partition 1 Status Register */
/*! @{ */

#define MC_ME_PRTN1_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN1_STAT_PCS_SHIFT               (0U)
#define MC_ME_PRTN1_STAT_PCS_WIDTH               (1U)
#define MC_ME_PRTN1_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_STAT_PCS_SHIFT)) & MC_ME_PRTN1_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN1_COFB0_STAT - Partition 1 COFB Set 0 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN1_COFB0_STAT_BLOCK0_MASK       (0x1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK0_SHIFT      (0U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK0_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK0(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK0_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK0_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK1_MASK       (0x2U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK1_SHIFT      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK1_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK1(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK1_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK1_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK2_MASK       (0x4U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK2_SHIFT      (2U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK2_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK2(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK2_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK2_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK3_MASK       (0x8U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK3_SHIFT      (3U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK3_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK3(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK3_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK3_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK4_MASK       (0x10U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK4_SHIFT      (4U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK4_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK4(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK4_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK4_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK5_MASK       (0x20U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK5_SHIFT      (5U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK5_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK5(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK5_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK5_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK6_MASK       (0x40U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK6_SHIFT      (6U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK6_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK6(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK6_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK6_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK7_MASK       (0x80U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK7_SHIFT      (7U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK7_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK7(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK7_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK7_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK8_MASK       (0x100U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK8_SHIFT      (8U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK8_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK8(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK8_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK8_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK9_MASK       (0x200U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK9_SHIFT      (9U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK9_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK9(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK9_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK9_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK10_MASK      (0x400U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK10_SHIFT     (10U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK10_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK10(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK10_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK10_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK11_MASK      (0x800U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK11_SHIFT     (11U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK11_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK11(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK11_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK11_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK12_MASK      (0x1000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK12_SHIFT     (12U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK12_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK12(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK12_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK12_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK13_MASK      (0x2000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK13_SHIFT     (13U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK13_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK13(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK13_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK13_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK14_MASK      (0x4000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK14_SHIFT     (14U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK14_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK14(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK14_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK14_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK15_MASK      (0x8000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK15_SHIFT     (15U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK15_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK15(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK15_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK15_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK16_MASK      (0x10000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK16_SHIFT     (16U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK16_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK16(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK16_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK16_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK17_MASK      (0x20000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK17_SHIFT     (17U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK17_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK17(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK17_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK17_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK18_MASK      (0x40000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK18_SHIFT     (18U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK18_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK18(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK18_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK18_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK19_MASK      (0x80000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK19_SHIFT     (19U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK19_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK19(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK19_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK19_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK20_MASK      (0x100000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK20_SHIFT     (20U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK20_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK20(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK20_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK20_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK21_MASK      (0x200000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK21_SHIFT     (21U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK21_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK21(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK21_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK21_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK22_MASK      (0x400000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK22_SHIFT     (22U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK22_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK22(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK22_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK22_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK23_MASK      (0x800000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK23_SHIFT     (23U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK23_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK23(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK23_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK23_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK24_MASK      (0x1000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK24_SHIFT     (24U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK24_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK24(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK24_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK24_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK25_MASK      (0x2000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK25_SHIFT     (25U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK25_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK25(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK25_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK25_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK26_MASK      (0x4000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK26_SHIFT     (26U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK26_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK26(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK26_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK26_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK27_MASK      (0x8000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK27_SHIFT     (27U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK27_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK27(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK27_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK27_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK28_MASK      (0x10000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK28_SHIFT     (28U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK28_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK28(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK28_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK28_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK29_MASK      (0x20000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK29_SHIFT     (29U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK29_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK29(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK29_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK29_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK30_MASK      (0x40000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK30_SHIFT     (30U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK30_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK30(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK30_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK30_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK31_MASK      (0x80000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK31_SHIFT     (31U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK31_WIDTH     (1U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK31(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK31_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK31_MASK)
/*! @} */

/*! @name PRTN1_COFB1_STAT - Partition 1 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN1_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK32_SHIFT     (0U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK32_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK35_SHIFT     (3U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK35_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK36_MASK      (0x10U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK36_SHIFT     (4U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK36_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK36(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK36_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK36_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK37_MASK      (0x20U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK37_SHIFT     (5U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK37_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK37(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK37_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK37_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK38_SHIFT     (6U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK38_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK39_SHIFT     (7U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK39_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK40_MASK      (0x100U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK40_SHIFT     (8U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK40_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK40(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK40_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK40_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK41_MASK      (0x200U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK41_SHIFT     (9U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK41_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK41(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK41_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK41_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK42_MASK      (0x400U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK42_SHIFT     (10U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK42_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK42(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK42_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK42_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK43_MASK      (0x800U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK43_SHIFT     (11U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK43_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK43(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK43_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK43_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK44_MASK      (0x1000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK44_SHIFT     (12U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK44_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK44(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK44_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK44_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK45_SHIFT     (13U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK45_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK46_MASK      (0x4000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK46_SHIFT     (14U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK46_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK46(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK46_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK46_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK47_MASK      (0x8000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK47_SHIFT     (15U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK47_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK47(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK47_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK47_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK48_MASK      (0x10000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK48_SHIFT     (16U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK48_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK48(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK48_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK48_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK49_MASK      (0x20000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK49_SHIFT     (17U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK49_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK49(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK49_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK49_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK50_MASK      (0x40000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK50_SHIFT     (18U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK50_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK50(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK50_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK50_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK51_MASK      (0x80000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK51_SHIFT     (19U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK51_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK51(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK51_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK51_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK52_MASK      (0x100000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK52_SHIFT     (20U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK52_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK52(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK52_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK52_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK53_MASK      (0x200000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK53_SHIFT     (21U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK53_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK53(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK53_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK53_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK54_MASK      (0x400000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK54_SHIFT     (22U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK54_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK54(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK54_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK54_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK55_MASK      (0x800000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK55_SHIFT     (23U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK55_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK55(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK55_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK55_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK56_MASK      (0x1000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK56_SHIFT     (24U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK56_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK56(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK56_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK56_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK57_MASK      (0x2000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK57_SHIFT     (25U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK57_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK57(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK57_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK57_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK58_MASK      (0x4000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK58_SHIFT     (26U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK58_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK58(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK58_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK58_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK59_MASK      (0x8000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK59_SHIFT     (27U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK59_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK59(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK59_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK59_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK60_MASK      (0x10000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK60_SHIFT     (28U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK60_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK60(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK60_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK60_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK61_MASK      (0x20000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK61_SHIFT     (29U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK61_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK61(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK61_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK61_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK62_MASK      (0x40000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK62_SHIFT     (30U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK62_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK62(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK62_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK62_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK63_MASK      (0x80000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK63_SHIFT     (31U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK63_WIDTH     (1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK63(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK63_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK63_MASK)
/*! @} */

/*! @name PRTN1_COFB0_CLKEN - Partition 1 COFB Set 0 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN1_COFB0_CLKEN_REQ0_MASK        (0x1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ0_SHIFT       (0U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ0_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ0(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ0_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ0_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ1_MASK        (0x2U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ1_SHIFT       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ1_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ1(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ1_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ1_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ2_MASK        (0x4U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ2_SHIFT       (2U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ2_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ2(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ2_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ2_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ3_MASK        (0x8U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ3_SHIFT       (3U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ3_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ3(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ3_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ3_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ4_MASK        (0x10U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ4_SHIFT       (4U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ4_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ4(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ4_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ4_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ5_MASK        (0x20U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ5_SHIFT       (5U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ5_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ5(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ5_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ5_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ6_MASK        (0x40U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ6_SHIFT       (6U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ6_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ6(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ6_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ6_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ7_MASK        (0x80U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ7_SHIFT       (7U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ7_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ7(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ7_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ7_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ8_MASK        (0x100U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ8_SHIFT       (8U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ8_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ8(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ8_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ8_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ9_MASK        (0x200U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ9_SHIFT       (9U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ9_WIDTH       (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ9(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ9_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ9_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ10_MASK       (0x400U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ10_SHIFT      (10U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ10_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ10(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ10_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ10_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ11_MASK       (0x800U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ11_SHIFT      (11U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ11_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ11(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ11_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ11_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ12_MASK       (0x1000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ12_SHIFT      (12U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ12_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ12(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ12_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ12_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ13_MASK       (0x2000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ13_SHIFT      (13U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ13_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ13(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ13_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ13_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ14_MASK       (0x4000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ14_SHIFT      (14U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ14_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ14(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ14_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ14_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ15_MASK       (0x8000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ15_SHIFT      (15U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ15_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ15(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ15_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ15_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ18_MASK       (0x40000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ18_SHIFT      (18U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ18_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ18(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ18_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ18_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ20_MASK       (0x100000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ20_SHIFT      (20U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ20_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ20(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ20_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ20_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ21_MASK       (0x200000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ21_SHIFT      (21U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ21_WIDTH      (1U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ21(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ21_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ21_MASK)
/*! @} */

/*! @name PRTN1_COFB1_CLKEN - Partition 1 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN1_COFB1_CLKEN_REQ35_MASK       (0x8U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ35_SHIFT      (3U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ35_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ35(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ35_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ35_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ36_MASK       (0x10U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ36_SHIFT      (4U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ36_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ36(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ36_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ36_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ37_MASK       (0x20U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ37_SHIFT      (5U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ37_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ37(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ37_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ37_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ38_MASK       (0x40U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ38_SHIFT      (6U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ38_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ38(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ38_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ38_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ39_MASK       (0x80U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ39_SHIFT      (7U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ39_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ39(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ39_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ39_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ40_MASK       (0x100U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ40_SHIFT      (8U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ40_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ40(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ40_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ40_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ41_MASK       (0x200U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ41_SHIFT      (9U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ41_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ41(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ41_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ41_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ42_MASK       (0x400U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ42_SHIFT      (10U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ42_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ42(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ42_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ42_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ43_MASK       (0x800U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ43_SHIFT      (11U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ43_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ43(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ43_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ43_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ44_MASK       (0x1000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ44_SHIFT      (12U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ44_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ44(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ44_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ44_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ45_MASK       (0x2000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ45_SHIFT      (13U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ45_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ45(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ45_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ45_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ46_MASK       (0x4000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ46_SHIFT      (14U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ46_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ46(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ46_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ46_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ47_MASK       (0x8000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ47_SHIFT      (15U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ47_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ47(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ47_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ47_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ48_MASK       (0x10000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ48_SHIFT      (16U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ48_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ48(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ48_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ48_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ49_MASK       (0x20000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ49_SHIFT      (17U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ49_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ49(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ49_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ49_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ50_MASK       (0x40000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ50_SHIFT      (18U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ50_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ50(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ50_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ50_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ51_MASK       (0x80000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ51_SHIFT      (19U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ51_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ51(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ51_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ51_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ52_MASK       (0x100000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ52_SHIFT      (20U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ52_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ52(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ52_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ52_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ53_MASK       (0x200000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ53_SHIFT      (21U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ53_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ53(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ53_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ53_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ54_MASK       (0x400000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ54_SHIFT      (22U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ54_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ54(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ54_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ54_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ55_MASK       (0x800000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ55_SHIFT      (23U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ55_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ55(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ55_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ55_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ56_MASK       (0x1000000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ56_SHIFT      (24U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ56_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ56(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ56_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ56_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ57_MASK       (0x2000000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ57_SHIFT      (25U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ57_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ57(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ57_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ57_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ58_MASK       (0x4000000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ58_SHIFT      (26U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ58_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ58(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ58_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ58_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ59_MASK       (0x8000000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ59_SHIFT      (27U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ59_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ59(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ59_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ59_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ60_MASK       (0x10000000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ60_SHIFT      (28U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ60_WIDTH      (1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ60(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ60_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ60_MASK)
/*! @} */

/*! @name PRTN1_CORE0_PCONF - Partition 1 Core 0 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN1_CORE0_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN1_CORE0_PCONF_CCE_SHIFT        (0U)
#define MC_ME_PRTN1_CORE0_PCONF_CCE_WIDTH        (1U)
#define MC_ME_PRTN1_CORE0_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_CORE0_PCONF_CCE_SHIFT)) & MC_ME_PRTN1_CORE0_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN1_CORE0_PUPD - Partition 1 Core 0 Process Update Register */
/*! @{ */

#define MC_ME_PRTN1_CORE0_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN1_CORE0_PUPD_CCUPD_SHIFT       (0U)
#define MC_ME_PRTN1_CORE0_PUPD_CCUPD_WIDTH       (1U)
#define MC_ME_PRTN1_CORE0_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_CORE0_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN1_CORE0_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN1_CORE0_STAT - Partition 1 Core 0 Status Register */
/*! @{ */

#define MC_ME_PRTN1_CORE0_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN1_CORE0_STAT_CCS_SHIFT         (0U)
#define MC_ME_PRTN1_CORE0_STAT_CCS_WIDTH         (1U)
#define MC_ME_PRTN1_CORE0_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_CORE0_STAT_CCS_SHIFT)) & MC_ME_PRTN1_CORE0_STAT_CCS_MASK)

#define MC_ME_PRTN1_CORE0_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN1_CORE0_STAT_WFI_SHIFT         (31U)
#define MC_ME_PRTN1_CORE0_STAT_WFI_WIDTH         (1U)
#define MC_ME_PRTN1_CORE0_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_CORE0_STAT_WFI_SHIFT)) & MC_ME_PRTN1_CORE0_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN1_CORE0_ADDR - Partition 1 Core 0 Address Register */
/*! @{ */

#define MC_ME_PRTN1_CORE0_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN1_CORE0_ADDR_ADDR_SHIFT        (2U)
#define MC_ME_PRTN1_CORE0_ADDR_ADDR_WIDTH        (30U)
#define MC_ME_PRTN1_CORE0_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_CORE0_ADDR_ADDR_SHIFT)) & MC_ME_PRTN1_CORE0_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN2_PCONF - Partition 2 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN2_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN2_PCONF_PCE_SHIFT              (0U)
#define MC_ME_PRTN2_PCONF_PCE_WIDTH              (1U)
#define MC_ME_PRTN2_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_PCONF_PCE_SHIFT)) & MC_ME_PRTN2_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN2_PUPD - Partition 2 Process Update Register */
/*! @{ */

#define MC_ME_PRTN2_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN2_PUPD_PCUD_SHIFT              (0U)
#define MC_ME_PRTN2_PUPD_PCUD_WIDTH              (1U)
#define MC_ME_PRTN2_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_PUPD_PCUD_SHIFT)) & MC_ME_PRTN2_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN2_STAT - Partition 2 Status Register */
/*! @{ */

#define MC_ME_PRTN2_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN2_STAT_PCS_SHIFT               (0U)
#define MC_ME_PRTN2_STAT_PCS_WIDTH               (1U)
#define MC_ME_PRTN2_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_STAT_PCS_SHIFT)) & MC_ME_PRTN2_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN2_COFB0_STAT - Partition 2 COFB Set 0 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN2_COFB0_STAT_BLOCK0_MASK       (0x1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK0_SHIFT      (0U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK0_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK0(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK0_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK0_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK1_MASK       (0x2U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK1_SHIFT      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK1_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK1(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK1_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK1_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK2_MASK       (0x4U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK2_SHIFT      (2U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK2_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK2(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK2_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK2_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK3_MASK       (0x8U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK3_SHIFT      (3U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK3_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK3(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK3_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK3_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK4_MASK       (0x10U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK4_SHIFT      (4U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK4_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK4(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK4_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK4_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK5_MASK       (0x20U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK5_SHIFT      (5U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK5_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK5(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK5_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK5_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK7_MASK       (0x80U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK7_SHIFT      (7U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK7_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK7(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK7_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK7_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK9_MASK       (0x200U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK9_SHIFT      (9U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK9_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK9(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK9_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK9_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK11_MASK      (0x800U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK11_SHIFT     (11U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK11_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK11(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK11_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK11_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK13_MASK      (0x2000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK13_SHIFT     (13U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK13_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK13(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK13_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK13_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK15_MASK      (0x8000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK15_SHIFT     (15U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK15_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK15(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK15_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK15_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK17_MASK      (0x20000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK17_SHIFT     (17U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK17_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK17(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK17_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK17_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK19_MASK      (0x80000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK19_SHIFT     (19U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK19_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK19(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK19_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK19_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK21_MASK      (0x200000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK21_SHIFT     (21U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK21_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK21(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK21_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK21_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK22_MASK      (0x400000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK22_SHIFT     (22U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK22_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK22(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK22_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK22_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK23_MASK      (0x800000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK23_SHIFT     (23U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK23_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK23(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK23_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK23_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK24_MASK      (0x1000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK24_SHIFT     (24U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK24_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK24(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK24_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK24_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK25_MASK      (0x2000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK25_SHIFT     (25U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK25_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK25(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK25_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK25_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK26_MASK      (0x4000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK26_SHIFT     (26U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK26_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK26(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK26_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK26_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK27_MASK      (0x8000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK27_SHIFT     (27U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK27_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK27(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK27_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK27_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK28_MASK      (0x10000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK28_SHIFT     (28U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK28_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK28(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK28_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK28_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK29_MASK      (0x20000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK29_SHIFT     (29U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK29_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK29(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK29_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK29_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK30_MASK      (0x40000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK30_SHIFT     (30U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK30_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK30(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK30_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK30_MASK)

#define MC_ME_PRTN2_COFB0_STAT_BLOCK31_MASK      (0x80000000U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK31_SHIFT     (31U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK31_WIDTH     (1U)
#define MC_ME_PRTN2_COFB0_STAT_BLOCK31(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_STAT_BLOCK31_SHIFT)) & MC_ME_PRTN2_COFB0_STAT_BLOCK31_MASK)
/*! @} */

/*! @name PRTN2_COFB1_STAT - Partition 2 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN2_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK32_SHIFT     (0U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK32_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK33_MASK      (0x2U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK33_SHIFT     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK33_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK33(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK33_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK33_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK34_MASK      (0x4U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK34_SHIFT     (2U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK34_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK34(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK34_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK34_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK35_SHIFT     (3U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK35_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK36_MASK      (0x10U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK36_SHIFT     (4U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK36_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK36(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK36_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK36_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK37_MASK      (0x20U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK37_SHIFT     (5U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK37_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK37(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK37_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK37_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK38_SHIFT     (6U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK38_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK39_SHIFT     (7U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK39_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK40_MASK      (0x100U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK40_SHIFT     (8U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK40_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK40(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK40_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK40_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK41_MASK      (0x200U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK41_SHIFT     (9U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK41_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK41(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK41_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK41_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK42_MASK      (0x400U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK42_SHIFT     (10U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK42_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK42(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK42_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK42_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK43_MASK      (0x800U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK43_SHIFT     (11U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK43_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK43(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK43_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK43_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK45_SHIFT     (13U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK45_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK46_MASK      (0x4000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK46_SHIFT     (14U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK46_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK46(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK46_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK46_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK47_MASK      (0x8000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK47_SHIFT     (15U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK47_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK47(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK47_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK47_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK48_MASK      (0x10000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK48_SHIFT     (16U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK48_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK48(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK48_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK48_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK49_MASK      (0x20000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK49_SHIFT     (17U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK49_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK49(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK49_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK49_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK50_MASK      (0x40000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK50_SHIFT     (18U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK50_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK50(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK50_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK50_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK51_MASK      (0x80000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK51_SHIFT     (19U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK51_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK51(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK51_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK51_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK52_MASK      (0x100000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK52_SHIFT     (20U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK52_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK52(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK52_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK52_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK54_MASK      (0x400000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK54_SHIFT     (22U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK54_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK54(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK54_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK54_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK55_MASK      (0x800000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK55_SHIFT     (23U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK55_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK55(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK55_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK55_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK56_MASK      (0x1000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK56_SHIFT     (24U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK56_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK56(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK56_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK56_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK57_MASK      (0x2000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK57_SHIFT     (25U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK57_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK57(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK57_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK57_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK58_MASK      (0x4000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK58_SHIFT     (26U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK58_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK58(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK58_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK58_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK59_MASK      (0x8000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK59_SHIFT     (27U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK59_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK59(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK59_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK59_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK60_MASK      (0x10000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK60_SHIFT     (28U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK60_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK60(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK60_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK60_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK61_MASK      (0x20000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK61_SHIFT     (29U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK61_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK61(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK61_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK61_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK62_MASK      (0x40000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK62_SHIFT     (30U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK62_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK62(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK62_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK62_MASK)

#define MC_ME_PRTN2_COFB1_STAT_BLOCK63_MASK      (0x80000000U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK63_SHIFT     (31U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK63_WIDTH     (1U)
#define MC_ME_PRTN2_COFB1_STAT_BLOCK63(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_STAT_BLOCK63_SHIFT)) & MC_ME_PRTN2_COFB1_STAT_BLOCK63_MASK)
/*! @} */

/*! @name PRTN2_COFB2_STAT - Partition 2 COFB Set 2 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN2_COFB2_STAT_BLOCK64_MASK      (0x1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK64_SHIFT     (0U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK64_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK64(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK64_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK64_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK65_MASK      (0x2U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK65_SHIFT     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK65_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK65(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK65_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK65_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK66_MASK      (0x4U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK66_SHIFT     (2U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK66_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK66(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK66_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK66_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK67_MASK      (0x8U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK67_SHIFT     (3U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK67_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK67(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK67_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK67_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK68_MASK      (0x10U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK68_SHIFT     (4U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK68_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK68(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK68_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK68_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK69_MASK      (0x20U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK69_SHIFT     (5U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK69_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK69(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK69_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK69_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK70_MASK      (0x40U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK70_SHIFT     (6U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK70_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK70(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK70_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK70_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK71_MASK      (0x80U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK71_SHIFT     (7U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK71_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK71(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK71_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK71_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK72_MASK      (0x100U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK72_SHIFT     (8U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK72_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK72(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK72_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK72_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK73_MASK      (0x200U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK73_SHIFT     (9U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK73_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK73(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK73_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK73_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK74_MASK      (0x400U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK74_SHIFT     (10U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK74_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK74(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK74_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK74_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK75_MASK      (0x800U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK75_SHIFT     (11U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK75_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK75(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK75_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK75_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK76_MASK      (0x1000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK76_SHIFT     (12U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK76_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK76(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK76_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK76_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK77_MASK      (0x2000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK77_SHIFT     (13U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK77_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK77(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK77_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK77_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK78_MASK      (0x4000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK78_SHIFT     (14U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK78_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK78(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK78_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK78_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK79_MASK      (0x8000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK79_SHIFT     (15U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK79_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK79(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK79_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK79_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK80_MASK      (0x10000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK80_SHIFT     (16U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK80_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK80(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK80_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK80_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK81_MASK      (0x20000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK81_SHIFT     (17U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK81_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK81(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK81_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK81_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK82_MASK      (0x40000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK82_SHIFT     (18U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK82_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK82(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK82_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK82_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK83_MASK      (0x80000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK83_SHIFT     (19U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK83_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK83(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK83_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK83_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK84_MASK      (0x100000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK84_SHIFT     (20U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK84_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK84(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK84_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK84_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK85_MASK      (0x200000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK85_SHIFT     (21U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK85_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK85(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK85_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK85_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK86_MASK      (0x400000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK86_SHIFT     (22U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK86_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK86(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK86_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK86_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK87_MASK      (0x800000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK87_SHIFT     (23U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK87_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK87(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK87_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK87_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK88_MASK      (0x1000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK88_SHIFT     (24U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK88_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK88(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK88_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK88_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK89_MASK      (0x2000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK89_SHIFT     (25U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK89_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK89(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK89_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK89_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK90_MASK      (0x4000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK90_SHIFT     (26U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK90_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK90(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK90_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK90_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK91_MASK      (0x8000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK91_SHIFT     (27U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK91_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK91(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK91_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK91_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK92_MASK      (0x10000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK92_SHIFT     (28U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK92_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK92(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK92_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK92_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK93_MASK      (0x20000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK93_SHIFT     (29U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK93_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK93(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK93_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK93_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK94_MASK      (0x40000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK94_SHIFT     (30U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK94_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK94(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK94_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK94_MASK)

#define MC_ME_PRTN2_COFB2_STAT_BLOCK95_MASK      (0x80000000U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK95_SHIFT     (31U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK95_WIDTH     (1U)
#define MC_ME_PRTN2_COFB2_STAT_BLOCK95(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_STAT_BLOCK95_SHIFT)) & MC_ME_PRTN2_COFB2_STAT_BLOCK95_MASK)
/*! @} */

/*! @name PRTN2_COFB3_STAT - Partition 2 COFB Set 3 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN2_COFB3_STAT_BLOCK96_MASK      (0x1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK96_SHIFT     (0U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK96_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK96(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK96_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK96_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK97_MASK      (0x2U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK97_SHIFT     (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK97_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK97(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK97_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK97_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK98_MASK      (0x4U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK98_SHIFT     (2U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK98_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK98(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK98_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK98_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK99_MASK      (0x8U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK99_SHIFT     (3U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK99_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK99(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK99_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK99_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK100_MASK     (0x10U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK100_SHIFT    (4U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK100_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK100(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK100_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK100_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK101_MASK     (0x20U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK101_SHIFT    (5U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK101_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK101(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK101_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK101_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK102_MASK     (0x40U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK102_SHIFT    (6U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK102_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK102(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK102_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK102_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK103_MASK     (0x80U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK103_SHIFT    (7U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK103_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK103(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK103_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK103_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK104_MASK     (0x100U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK104_SHIFT    (8U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK104_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK104(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK104_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK104_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK105_MASK     (0x200U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK105_SHIFT    (9U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK105_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK105(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK105_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK105_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK106_MASK     (0x400U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK106_SHIFT    (10U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK106_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK106(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK106_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK106_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK107_MASK     (0x800U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK107_SHIFT    (11U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK107_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK107(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK107_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK107_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK108_MASK     (0x1000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK108_SHIFT    (12U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK108_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK108(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK108_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK108_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK109_MASK     (0x2000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK109_SHIFT    (13U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK109_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK109(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK109_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK109_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK110_MASK     (0x4000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK110_SHIFT    (14U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK110_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK110(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK110_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK110_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK111_MASK     (0x8000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK111_SHIFT    (15U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK111_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK111(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK111_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK111_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK112_MASK     (0x10000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK112_SHIFT    (16U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK112_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK112(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK112_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK112_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK113_MASK     (0x20000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK113_SHIFT    (17U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK113_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK113(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK113_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK113_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK114_MASK     (0x40000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK114_SHIFT    (18U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK114_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK114(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK114_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK114_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK115_MASK     (0x80000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK115_SHIFT    (19U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK115_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK115(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK115_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK115_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK116_MASK     (0x100000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK116_SHIFT    (20U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK116_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK116(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK116_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK116_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK117_MASK     (0x200000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK117_SHIFT    (21U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK117_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK117(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK117_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK117_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK118_MASK     (0x400000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK118_SHIFT    (22U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK118_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK118(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK118_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK118_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK119_MASK     (0x800000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK119_SHIFT    (23U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK119_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK119(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK119_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK119_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK120_MASK     (0x1000000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK120_SHIFT    (24U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK120_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK120(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK120_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK120_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK121_MASK     (0x2000000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK121_SHIFT    (25U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK121_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK121(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK121_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK121_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK122_MASK     (0x4000000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK122_SHIFT    (26U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK122_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK122(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK122_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK122_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK123_MASK     (0x8000000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK123_SHIFT    (27U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK123_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK123(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK123_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK123_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK124_MASK     (0x10000000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK124_SHIFT    (28U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK124_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK124(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK124_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK124_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK125_MASK     (0x20000000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK125_SHIFT    (29U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK125_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK125(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK125_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK125_MASK)

#define MC_ME_PRTN2_COFB3_STAT_BLOCK126_MASK     (0x40000000U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK126_SHIFT    (30U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK126_WIDTH    (1U)
#define MC_ME_PRTN2_COFB3_STAT_BLOCK126(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_STAT_BLOCK126_SHIFT)) & MC_ME_PRTN2_COFB3_STAT_BLOCK126_MASK)
/*! @} */

/*! @name PRTN2_COFB0_CLKEN - Partition 2 COFB Set 0 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN2_COFB0_CLKEN_REQ3_MASK        (0x8U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ3_SHIFT       (3U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ3_WIDTH       (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ3(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ3_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ3_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ4_MASK        (0x10U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ4_SHIFT       (4U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ4_WIDTH       (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ4(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ4_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ4_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ5_MASK        (0x20U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ5_SHIFT       (5U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ5_WIDTH       (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ5(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ5_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ5_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ7_MASK        (0x80U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ7_SHIFT       (7U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ7_WIDTH       (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ7(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ7_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ7_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ9_MASK        (0x200U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ9_SHIFT       (9U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ9_WIDTH       (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ9(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ9_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ9_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ11_MASK       (0x800U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ11_SHIFT      (11U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ11_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ11(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ11_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ11_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ13_MASK       (0x2000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ13_SHIFT      (13U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ13_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ13(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ13_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ13_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ15_MASK       (0x8000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ15_SHIFT      (15U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ15_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ15(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ15_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ15_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ17_MASK       (0x20000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ17_SHIFT      (17U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ17_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ17(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ17_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ17_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ19_MASK       (0x80000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ19_SHIFT      (19U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ19_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ19(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ19_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ19_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ21_MASK       (0x200000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ21_SHIFT      (21U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ21_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ21(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ21_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ21_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ23_MASK       (0x800000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ23_SHIFT      (23U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ23_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ23(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ23_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ23_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ24_MASK       (0x1000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ24_SHIFT      (24U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ24_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ24(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ24_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ24_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ25_MASK       (0x2000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ25_SHIFT      (25U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ25_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ25(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ25_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ25_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ26_MASK       (0x4000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ26_SHIFT      (26U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ26_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ26(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ26_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ26_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ27_MASK       (0x8000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ27_SHIFT      (27U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ27_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ27(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ27_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ27_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ28_MASK       (0x10000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ28_SHIFT      (28U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ28_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ28(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ28_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ28_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ29_MASK       (0x20000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ29_SHIFT      (29U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ29_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ29(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ29_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ29_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ30_MASK       (0x40000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ30_SHIFT      (30U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ30_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ30(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ30_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ30_MASK)

#define MC_ME_PRTN2_COFB0_CLKEN_REQ31_MASK       (0x80000000U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ31_SHIFT      (31U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ31_WIDTH      (1U)
#define MC_ME_PRTN2_COFB0_CLKEN_REQ31(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB0_CLKEN_REQ31_SHIFT)) & MC_ME_PRTN2_COFB0_CLKEN_REQ31_MASK)
/*! @} */

/*! @name PRTN2_COFB1_CLKEN - Partition 2 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN2_COFB1_CLKEN_REQ32_MASK       (0x1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ32_SHIFT      (0U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ32_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ32(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ32_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ32_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ33_MASK       (0x2U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ33_SHIFT      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ33_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ33(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ33_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ33_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ34_MASK       (0x4U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ34_SHIFT      (2U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ34_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ34(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ34_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ34_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ35_MASK       (0x8U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ35_SHIFT      (3U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ35_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ35(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ35_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ35_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ36_MASK       (0x10U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ36_SHIFT      (4U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ36_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ36(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ36_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ36_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ37_MASK       (0x20U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ37_SHIFT      (5U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ37_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ37(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ37_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ37_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ41_MASK       (0x200U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ41_SHIFT      (9U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ41_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ41(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ41_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ41_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ42_MASK       (0x400U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ42_SHIFT      (10U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ42_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ42(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ42_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ42_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ47_MASK       (0x8000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ47_SHIFT      (15U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ47_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ47(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ47_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ47_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ48_MASK       (0x10000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ48_SHIFT      (16U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ48_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ48(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ48_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ48_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ49_MASK       (0x20000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ49_SHIFT      (17U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ49_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ49(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ49_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ49_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ50_MASK       (0x40000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ50_SHIFT      (18U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ50_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ50(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ50_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ50_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ51_MASK       (0x80000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ51_SHIFT      (19U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ51_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ51(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ51_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ51_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ52_MASK       (0x100000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ52_SHIFT      (20U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ52_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ52(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ52_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ52_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ54_MASK       (0x400000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ54_SHIFT      (22U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ54_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ54(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ54_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ54_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ55_MASK       (0x800000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ55_SHIFT      (23U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ55_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ55(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ55_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ55_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ56_MASK       (0x1000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ56_SHIFT      (24U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ56_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ56(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ56_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ56_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ57_MASK       (0x2000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ57_SHIFT      (25U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ57_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ57(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ57_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ57_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ58_MASK       (0x4000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ58_SHIFT      (26U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ58_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ58(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ58_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ58_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ59_MASK       (0x8000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ59_SHIFT      (27U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ59_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ59(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ59_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ59_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ60_MASK       (0x10000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ60_SHIFT      (28U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ60_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ60(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ60_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ60_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ61_MASK       (0x20000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ61_SHIFT      (29U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ61_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ61(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ61_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ61_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ62_MASK       (0x40000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ62_SHIFT      (30U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ62_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ62(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ62_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ62_MASK)

#define MC_ME_PRTN2_COFB1_CLKEN_REQ63_MASK       (0x80000000U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ63_SHIFT      (31U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ63_WIDTH      (1U)
#define MC_ME_PRTN2_COFB1_CLKEN_REQ63(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB1_CLKEN_REQ63_SHIFT)) & MC_ME_PRTN2_COFB1_CLKEN_REQ63_MASK)
/*! @} */

/*! @name PRTN2_COFB2_CLKEN - Partition 2 COFB Set 2 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN2_COFB2_CLKEN_REQ64_MASK       (0x1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ64_SHIFT      (0U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ64_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ64(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ64_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ64_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ65_MASK       (0x2U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ65_SHIFT      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ65_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ65(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ65_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ65_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ66_MASK       (0x4U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ66_SHIFT      (2U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ66_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ66(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ66_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ66_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ67_MASK       (0x8U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ67_SHIFT      (3U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ67_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ67(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ67_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ67_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ68_MASK       (0x10U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ68_SHIFT      (4U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ68_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ68(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ68_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ68_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ69_MASK       (0x20U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ69_SHIFT      (5U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ69_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ69(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ69_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ69_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ70_MASK       (0x40U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ70_SHIFT      (6U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ70_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ70(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ70_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ70_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ71_MASK       (0x80U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ71_SHIFT      (7U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ71_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ71(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ71_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ71_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ72_MASK       (0x100U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ72_SHIFT      (8U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ72_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ72(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ72_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ72_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ73_MASK       (0x200U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ73_SHIFT      (9U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ73_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ73(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ73_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ73_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ74_MASK       (0x400U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ74_SHIFT      (10U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ74_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ74(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ74_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ74_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ75_MASK       (0x800U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ75_SHIFT      (11U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ75_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ75(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ75_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ75_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ76_MASK       (0x1000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ76_SHIFT      (12U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ76_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ76(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ76_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ76_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ77_MASK       (0x2000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ77_SHIFT      (13U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ77_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ77(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ77_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ77_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ78_MASK       (0x4000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ78_SHIFT      (14U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ78_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ78(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ78_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ78_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ79_MASK       (0x8000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ79_SHIFT      (15U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ79_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ79(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ79_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ79_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ80_MASK       (0x10000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ80_SHIFT      (16U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ80_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ80(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ80_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ80_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ81_MASK       (0x20000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ81_SHIFT      (17U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ81_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ81(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ81_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ81_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ82_MASK       (0x40000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ82_SHIFT      (18U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ82_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ82(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ82_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ82_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ83_MASK       (0x80000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ83_SHIFT      (19U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ83_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ83(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ83_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ83_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ84_MASK       (0x100000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ84_SHIFT      (20U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ84_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ84(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ84_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ84_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ85_MASK       (0x200000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ85_SHIFT      (21U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ85_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ85(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ85_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ85_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ86_MASK       (0x400000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ86_SHIFT      (22U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ86_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ86(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ86_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ86_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ87_MASK       (0x800000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ87_SHIFT      (23U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ87_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ87(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ87_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ87_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ88_MASK       (0x1000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ88_SHIFT      (24U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ88_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ88(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ88_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ88_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ89_MASK       (0x2000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ89_SHIFT      (25U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ89_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ89(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ89_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ89_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ90_MASK       (0x4000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ90_SHIFT      (26U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ90_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ90(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ90_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ90_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ91_MASK       (0x8000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ91_SHIFT      (27U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ91_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ91(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ91_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ91_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ92_MASK       (0x10000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ92_SHIFT      (28U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ92_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ92(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ92_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ92_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ93_MASK       (0x20000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ93_SHIFT      (29U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ93_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ93(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ93_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ93_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ94_MASK       (0x40000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ94_SHIFT      (30U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ94_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ94(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ94_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ94_MASK)

#define MC_ME_PRTN2_COFB2_CLKEN_REQ95_MASK       (0x80000000U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ95_SHIFT      (31U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ95_WIDTH      (1U)
#define MC_ME_PRTN2_COFB2_CLKEN_REQ95(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB2_CLKEN_REQ95_SHIFT)) & MC_ME_PRTN2_COFB2_CLKEN_REQ95_MASK)
/*! @} */

/*! @name PRTN2_COFB3_CLKEN - Partition 2 COFB Set 3 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN2_COFB3_CLKEN_REQ96_MASK       (0x1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ96_SHIFT      (0U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ96_WIDTH      (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ96(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ96_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ96_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ97_MASK       (0x2U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ97_SHIFT      (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ97_WIDTH      (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ97(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ97_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ97_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ98_MASK       (0x4U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ98_SHIFT      (2U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ98_WIDTH      (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ98(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ98_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ98_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ99_MASK       (0x8U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ99_SHIFT      (3U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ99_WIDTH      (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ99(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ99_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ99_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ100_MASK      (0x10U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ100_SHIFT     (4U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ100_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ100(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ100_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ100_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ101_MASK      (0x20U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ101_SHIFT     (5U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ101_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ101(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ101_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ101_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ102_MASK      (0x40U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ102_SHIFT     (6U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ102_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ102(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ102_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ102_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ103_MASK      (0x80U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ103_SHIFT     (7U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ103_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ103(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ103_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ103_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ104_MASK      (0x100U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ104_SHIFT     (8U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ104_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ104(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ104_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ104_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ105_MASK      (0x200U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ105_SHIFT     (9U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ105_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ105(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ105_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ105_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ114_MASK      (0x40000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ114_SHIFT     (18U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ114_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ114(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ114_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ114_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ115_MASK      (0x80000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ115_SHIFT     (19U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ115_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ115(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ115_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ115_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ116_MASK      (0x100000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ116_SHIFT     (20U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ116_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ116(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ116_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ116_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ117_MASK      (0x200000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ117_SHIFT     (21U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ117_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ117(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ117_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ117_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ118_MASK      (0x400000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ118_SHIFT     (22U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ118_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ118(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ118_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ118_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ119_MASK      (0x800000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ119_SHIFT     (23U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ119_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ119(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ119_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ119_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ120_MASK      (0x1000000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ120_SHIFT     (24U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ120_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ120(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ120_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ120_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ121_MASK      (0x2000000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ121_SHIFT     (25U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ121_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ121(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ121_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ121_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ125_MASK      (0x20000000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ125_SHIFT     (29U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ125_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ125(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ125_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ125_MASK)

#define MC_ME_PRTN2_COFB3_CLKEN_REQ126_MASK      (0x40000000U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ126_SHIFT     (30U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ126_WIDTH     (1U)
#define MC_ME_PRTN2_COFB3_CLKEN_REQ126(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN2_COFB3_CLKEN_REQ126_SHIFT)) & MC_ME_PRTN2_COFB3_CLKEN_REQ126_MASK)
/*! @} */

/*! @name PRTN3_PCONF - Partition 3 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN3_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN3_PCONF_PCE_SHIFT              (0U)
#define MC_ME_PRTN3_PCONF_PCE_WIDTH              (1U)
#define MC_ME_PRTN3_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_PCONF_PCE_SHIFT)) & MC_ME_PRTN3_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN3_PUPD - Partition 3 Process Update Register */
/*! @{ */

#define MC_ME_PRTN3_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN3_PUPD_PCUD_SHIFT              (0U)
#define MC_ME_PRTN3_PUPD_PCUD_WIDTH              (1U)
#define MC_ME_PRTN3_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_PUPD_PCUD_SHIFT)) & MC_ME_PRTN3_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN3_STAT - Partition 3 Status Register */
/*! @{ */

#define MC_ME_PRTN3_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN3_STAT_PCS_SHIFT               (0U)
#define MC_ME_PRTN3_STAT_PCS_WIDTH               (1U)
#define MC_ME_PRTN3_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_STAT_PCS_SHIFT)) & MC_ME_PRTN3_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN3_COFB0_STAT - Partition 3 COFB Set 0 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN3_COFB0_STAT_BLOCK0_MASK       (0x1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK0_SHIFT      (0U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK0_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK0(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK0_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK0_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK3_MASK       (0x8U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK3_SHIFT      (3U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK3_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK3(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK3_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK3_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK4_MASK       (0x10U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK4_SHIFT      (4U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK4_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK4(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK4_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK4_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK5_MASK       (0x20U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK5_SHIFT      (5U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK5_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK5(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK5_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK5_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK6_MASK       (0x40U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK6_SHIFT      (6U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK6_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK6(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK6_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK6_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK7_MASK       (0x80U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK7_SHIFT      (7U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK7_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK7(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK7_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK7_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK8_MASK       (0x100U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK8_SHIFT      (8U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK8_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK8(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK8_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK8_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK9_MASK       (0x200U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK9_SHIFT      (9U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK9_WIDTH      (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK9(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK9_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK9_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK10_MASK      (0x400U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK10_SHIFT     (10U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK10_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK10(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK10_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK10_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK11_MASK      (0x800U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK11_SHIFT     (11U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK11_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK11(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK11_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK11_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK12_MASK      (0x1000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK12_SHIFT     (12U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK12_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK12(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK12_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK12_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK13_MASK      (0x2000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK13_SHIFT     (13U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK13_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK13(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK13_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK13_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK14_MASK      (0x4000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK14_SHIFT     (14U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK14_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK14(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK14_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK14_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK15_MASK      (0x8000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK15_SHIFT     (15U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK15_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK15(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK15_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK15_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK16_MASK      (0x10000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK16_SHIFT     (16U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK16_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK16(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK16_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK16_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK17_MASK      (0x20000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK17_SHIFT     (17U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK17_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK17(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK17_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK17_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK18_MASK      (0x40000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK18_SHIFT     (18U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK18_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK18(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK18_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK18_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK19_MASK      (0x80000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK19_SHIFT     (19U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK19_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK19(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK19_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK19_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK20_MASK      (0x100000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK20_SHIFT     (20U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK20_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK20(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK20_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK20_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK21_MASK      (0x200000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK21_SHIFT     (21U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK21_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK21(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK21_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK21_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK22_MASK      (0x400000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK22_SHIFT     (22U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK22_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK22(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK22_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK22_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK23_MASK      (0x800000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK23_SHIFT     (23U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK23_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK23(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK23_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK23_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK24_MASK      (0x1000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK24_SHIFT     (24U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK24_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK24(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK24_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK24_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK25_MASK      (0x2000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK25_SHIFT     (25U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK25_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK25(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK25_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK25_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK26_MASK      (0x4000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK26_SHIFT     (26U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK26_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK26(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK26_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK26_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK27_MASK      (0x8000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK27_SHIFT     (27U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK27_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK27(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK27_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK27_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK28_MASK      (0x10000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK28_SHIFT     (28U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK28_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK28(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK28_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK28_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK29_MASK      (0x20000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK29_SHIFT     (29U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK29_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK29(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK29_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK29_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK30_MASK      (0x40000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK30_SHIFT     (30U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK30_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK30(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK30_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK30_MASK)

#define MC_ME_PRTN3_COFB0_STAT_BLOCK31_MASK      (0x80000000U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK31_SHIFT     (31U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK31_WIDTH     (1U)
#define MC_ME_PRTN3_COFB0_STAT_BLOCK31(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_STAT_BLOCK31_SHIFT)) & MC_ME_PRTN3_COFB0_STAT_BLOCK31_MASK)
/*! @} */

/*! @name PRTN3_COFB1_STAT - Partition 3 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN3_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK32_SHIFT     (0U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK32_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK33_MASK      (0x2U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK33_SHIFT     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK33_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK33(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK33_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK33_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK34_MASK      (0x4U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK34_SHIFT     (2U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK34_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK34(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK34_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK34_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK35_SHIFT     (3U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK35_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK36_MASK      (0x10U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK36_SHIFT     (4U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK36_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK36(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK36_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK36_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK38_SHIFT     (6U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK38_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK39_SHIFT     (7U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK39_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK40_MASK      (0x100U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK40_SHIFT     (8U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK40_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK40(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK40_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK40_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK41_MASK      (0x200U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK41_SHIFT     (9U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK41_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK41(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK41_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK41_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK42_MASK      (0x400U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK42_SHIFT     (10U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK42_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK42(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK42_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK42_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK43_MASK      (0x800U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK43_SHIFT     (11U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK43_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK43(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK43_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK43_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK44_MASK      (0x1000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK44_SHIFT     (12U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK44_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK44(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK44_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK44_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK45_SHIFT     (13U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK45_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK46_MASK      (0x4000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK46_SHIFT     (14U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK46_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK46(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK46_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK46_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK47_MASK      (0x8000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK47_SHIFT     (15U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK47_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK47(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK47_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK47_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK48_MASK      (0x10000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK48_SHIFT     (16U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK48_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK48(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK48_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK48_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK49_MASK      (0x20000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK49_SHIFT     (17U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK49_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK49(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK49_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK49_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK50_MASK      (0x40000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK50_SHIFT     (18U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK50_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK50(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK50_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK50_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK51_MASK      (0x80000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK51_SHIFT     (19U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK51_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK51(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK51_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK51_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK52_MASK      (0x100000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK52_SHIFT     (20U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK52_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK52(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK52_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK52_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK53_MASK      (0x200000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK53_SHIFT     (21U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK53_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK53(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK53_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK53_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK56_MASK      (0x1000000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK56_SHIFT     (24U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK56_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK56(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK56_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK56_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK58_MASK      (0x4000000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK58_SHIFT     (26U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK58_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK58(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK58_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK58_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK59_MASK      (0x8000000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK59_SHIFT     (27U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK59_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK59(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK59_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK59_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK60_MASK      (0x10000000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK60_SHIFT     (28U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK60_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK60(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK60_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK60_MASK)

#define MC_ME_PRTN3_COFB1_STAT_BLOCK61_MASK      (0x20000000U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK61_SHIFT     (29U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK61_WIDTH     (1U)
#define MC_ME_PRTN3_COFB1_STAT_BLOCK61(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_STAT_BLOCK61_SHIFT)) & MC_ME_PRTN3_COFB1_STAT_BLOCK61_MASK)
/*! @} */

/*! @name PRTN3_COFB0_CLKEN - Partition 3 COFB Set 0 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN3_COFB0_CLKEN_REQ0_MASK        (0x1U)
#define MC_ME_PRTN3_COFB0_CLKEN_REQ0_SHIFT       (0U)
#define MC_ME_PRTN3_COFB0_CLKEN_REQ0_WIDTH       (1U)
#define MC_ME_PRTN3_COFB0_CLKEN_REQ0(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_CLKEN_REQ0_SHIFT)) & MC_ME_PRTN3_COFB0_CLKEN_REQ0_MASK)

#define MC_ME_PRTN3_COFB0_CLKEN_REQ3_MASK        (0x8U)
#define MC_ME_PRTN3_COFB0_CLKEN_REQ3_SHIFT       (3U)
#define MC_ME_PRTN3_COFB0_CLKEN_REQ3_WIDTH       (1U)
#define MC_ME_PRTN3_COFB0_CLKEN_REQ3(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB0_CLKEN_REQ3_SHIFT)) & MC_ME_PRTN3_COFB0_CLKEN_REQ3_MASK)
/*! @} */

/*! @name PRTN3_COFB1_CLKEN - Partition 3 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN3_COFB1_CLKEN_REQ36_MASK       (0x10U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ36_SHIFT      (4U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ36_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ36(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ36_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ36_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ38_MASK       (0x40U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ38_SHIFT      (6U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ38_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ38(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ38_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ38_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ39_MASK       (0x80U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ39_SHIFT      (7U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ39_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ39(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ39_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ39_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ40_MASK       (0x100U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ40_SHIFT      (8U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ40_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ40(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ40_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ40_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ41_MASK       (0x200U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ41_SHIFT      (9U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ41_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ41(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ41_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ41_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ42_MASK       (0x400U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ42_SHIFT      (10U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ42_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ42(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ42_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ42_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ43_MASK       (0x800U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ43_SHIFT      (11U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ43_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ43(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ43_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ43_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ44_MASK       (0x1000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ44_SHIFT      (12U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ44_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ44(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ44_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ44_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ45_MASK       (0x2000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ45_SHIFT      (13U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ45_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ45(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ45_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ45_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ46_MASK       (0x4000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ46_SHIFT      (14U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ46_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ46(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ46_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ46_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ47_MASK       (0x8000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ47_SHIFT      (15U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ47_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ47(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ47_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ47_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ48_MASK       (0x10000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ48_SHIFT      (16U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ48_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ48(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ48_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ48_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ49_MASK       (0x20000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ49_SHIFT      (17U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ49_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ49(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ49_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ49_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ50_MASK       (0x40000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ50_SHIFT      (18U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ50_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ50(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ50_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ50_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ51_MASK       (0x80000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ51_SHIFT      (19U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ51_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ51(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ51_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ51_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ52_MASK       (0x100000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ52_SHIFT      (20U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ52_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ52(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ52_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ52_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ53_MASK       (0x200000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ53_SHIFT      (21U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ53_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ53(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ53_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ53_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ59_MASK       (0x8000000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ59_SHIFT      (27U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ59_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ59(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ59_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ59_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ60_MASK       (0x10000000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ60_SHIFT      (28U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ60_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ60(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ60_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ60_MASK)

#define MC_ME_PRTN3_COFB1_CLKEN_REQ61_MASK       (0x20000000U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ61_SHIFT      (29U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ61_WIDTH      (1U)
#define MC_ME_PRTN3_COFB1_CLKEN_REQ61(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN3_COFB1_CLKEN_REQ61_SHIFT)) & MC_ME_PRTN3_COFB1_CLKEN_REQ61_MASK)
/*! @} */

/*! @name PRTN4_PCONF - Partition 4 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN4_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN4_PCONF_PCE_SHIFT              (0U)
#define MC_ME_PRTN4_PCONF_PCE_WIDTH              (1U)
#define MC_ME_PRTN4_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_PCONF_PCE_SHIFT)) & MC_ME_PRTN4_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN4_PUPD - Partition 4 Process Update Register */
/*! @{ */

#define MC_ME_PRTN4_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN4_PUPD_PCUD_SHIFT              (0U)
#define MC_ME_PRTN4_PUPD_PCUD_WIDTH              (1U)
#define MC_ME_PRTN4_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_PUPD_PCUD_SHIFT)) & MC_ME_PRTN4_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN4_STAT - Partition 4 Status Register */
/*! @{ */

#define MC_ME_PRTN4_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN4_STAT_PCS_SHIFT               (0U)
#define MC_ME_PRTN4_STAT_PCS_WIDTH               (1U)
#define MC_ME_PRTN4_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_STAT_PCS_SHIFT)) & MC_ME_PRTN4_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN4_COFB0_STAT - Partition 4 COFB Set 0 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN4_COFB0_STAT_BLOCK0_MASK       (0x1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK0_SHIFT      (0U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK0_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK0(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK0_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK0_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK1_MASK       (0x2U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK1_SHIFT      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK1_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK1(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK1_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK1_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK2_MASK       (0x4U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK2_SHIFT      (2U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK2_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK2(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK2_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK2_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK3_MASK       (0x8U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK3_SHIFT      (3U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK3_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK3(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK3_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK3_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK4_MASK       (0x10U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK4_SHIFT      (4U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK4_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK4(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK4_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK4_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK5_MASK       (0x20U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK5_SHIFT      (5U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK5_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK5(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK5_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK5_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK6_MASK       (0x40U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK6_SHIFT      (6U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK6_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK6(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK6_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK6_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK7_MASK       (0x80U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK7_SHIFT      (7U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK7_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK7(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK7_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK7_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK8_MASK       (0x100U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK8_SHIFT      (8U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK8_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK8(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK8_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK8_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK9_MASK       (0x200U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK9_SHIFT      (9U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK9_WIDTH      (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK9(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK9_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK9_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK10_MASK      (0x400U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK10_SHIFT     (10U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK10_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK10(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK10_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK10_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK11_MASK      (0x800U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK11_SHIFT     (11U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK11_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK11(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK11_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK11_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK12_MASK      (0x1000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK12_SHIFT     (12U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK12_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK12(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK12_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK12_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK13_MASK      (0x2000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK13_SHIFT     (13U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK13_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK13(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK13_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK13_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK14_MASK      (0x4000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK14_SHIFT     (14U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK14_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK14(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK14_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK14_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK15_MASK      (0x8000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK15_SHIFT     (15U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK15_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK15(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK15_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK15_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK16_MASK      (0x10000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK16_SHIFT     (16U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK16_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK16(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK16_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK16_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK17_MASK      (0x20000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK17_SHIFT     (17U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK17_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK17(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK17_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK17_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK18_MASK      (0x40000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK18_SHIFT     (18U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK18_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK18(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK18_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK18_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK19_MASK      (0x80000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK19_SHIFT     (19U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK19_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK19(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK19_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK19_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK20_MASK      (0x100000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK20_SHIFT     (20U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK20_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK20(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK20_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK20_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK21_MASK      (0x200000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK21_SHIFT     (21U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK21_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK21(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK21_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK21_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK22_MASK      (0x400000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK22_SHIFT     (22U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK22_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK22(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK22_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK22_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK23_MASK      (0x800000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK23_SHIFT     (23U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK23_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK23(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK23_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK23_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK24_MASK      (0x1000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK24_SHIFT     (24U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK24_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK24(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK24_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK24_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK25_MASK      (0x2000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK25_SHIFT     (25U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK25_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK25(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK25_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK25_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK26_MASK      (0x4000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK26_SHIFT     (26U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK26_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK26(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK26_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK26_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK27_MASK      (0x8000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK27_SHIFT     (27U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK27_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK27(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK27_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK27_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK28_MASK      (0x10000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK28_SHIFT     (28U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK28_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK28(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK28_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK28_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK29_MASK      (0x20000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK29_SHIFT     (29U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK29_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK29(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK29_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK29_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK30_MASK      (0x40000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK30_SHIFT     (30U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK30_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK30(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK30_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK30_MASK)

#define MC_ME_PRTN4_COFB0_STAT_BLOCK31_MASK      (0x80000000U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK31_SHIFT     (31U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK31_WIDTH     (1U)
#define MC_ME_PRTN4_COFB0_STAT_BLOCK31(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_STAT_BLOCK31_SHIFT)) & MC_ME_PRTN4_COFB0_STAT_BLOCK31_MASK)
/*! @} */

/*! @name PRTN4_COFB1_STAT - Partition 4 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN4_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK32_SHIFT     (0U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK32_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK35_SHIFT     (3U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK35_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK36_MASK      (0x10U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK36_SHIFT     (4U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK36_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK36(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK36_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK36_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK37_MASK      (0x20U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK37_SHIFT     (5U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK37_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK37(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK37_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK37_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK38_SHIFT     (6U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK38_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK39_SHIFT     (7U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK39_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK40_MASK      (0x100U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK40_SHIFT     (8U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK40_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK40(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK40_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK40_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK41_MASK      (0x200U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK41_SHIFT     (9U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK41_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK41(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK41_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK41_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK42_MASK      (0x400U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK42_SHIFT     (10U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK42_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK42(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK42_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK42_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK43_MASK      (0x800U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK43_SHIFT     (11U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK43_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK43(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK43_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK43_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK44_MASK      (0x1000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK44_SHIFT     (12U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK44_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK44(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK44_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK44_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK45_SHIFT     (13U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK45_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK46_MASK      (0x4000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK46_SHIFT     (14U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK46_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK46(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK46_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK46_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK49_MASK      (0x20000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK49_SHIFT     (17U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK49_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK49(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK49_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK49_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK50_MASK      (0x40000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK50_SHIFT     (18U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK50_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK50(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK50_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK50_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK51_MASK      (0x80000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK51_SHIFT     (19U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK51_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK51(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK51_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK51_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK52_MASK      (0x100000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK52_SHIFT     (20U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK52_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK52(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK52_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK52_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK55_MASK      (0x800000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK55_SHIFT     (23U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK55_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK55(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK55_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK55_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK57_MASK      (0x2000000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK57_SHIFT     (25U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK57_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK57(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK57_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK57_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK58_MASK      (0x4000000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK58_SHIFT     (26U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK58_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK58(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK58_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK58_MASK)

#define MC_ME_PRTN4_COFB1_STAT_BLOCK59_MASK      (0x8000000U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK59_SHIFT     (27U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK59_WIDTH     (1U)
#define MC_ME_PRTN4_COFB1_STAT_BLOCK59(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_STAT_BLOCK59_SHIFT)) & MC_ME_PRTN4_COFB1_STAT_BLOCK59_MASK)
/*! @} */

/*! @name PRTN4_COFB0_CLKEN - Partition 4 COFB Set 0 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN4_COFB0_CLKEN_REQ0_MASK        (0x1U)
#define MC_ME_PRTN4_COFB0_CLKEN_REQ0_SHIFT       (0U)
#define MC_ME_PRTN4_COFB0_CLKEN_REQ0_WIDTH       (1U)
#define MC_ME_PRTN4_COFB0_CLKEN_REQ0(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB0_CLKEN_REQ0_SHIFT)) & MC_ME_PRTN4_COFB0_CLKEN_REQ0_MASK)
/*! @} */

/*! @name PRTN4_COFB1_CLKEN - Partition 4 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN4_COFB1_CLKEN_REQ35_MASK       (0x8U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ35_SHIFT      (3U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ35_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ35(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ35_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ35_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ36_MASK       (0x10U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ36_SHIFT      (4U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ36_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ36(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ36_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ36_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ37_MASK       (0x20U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ37_SHIFT      (5U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ37_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ37(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ37_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ37_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ38_MASK       (0x40U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ38_SHIFT      (6U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ38_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ38(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ38_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ38_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ39_MASK       (0x80U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ39_SHIFT      (7U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ39_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ39(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ39_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ39_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ40_MASK       (0x100U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ40_SHIFT      (8U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ40_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ40(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ40_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ40_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ41_MASK       (0x200U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ41_SHIFT      (9U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ41_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ41(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ41_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ41_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ42_MASK       (0x400U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ42_SHIFT      (10U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ42_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ42(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ42_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ42_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ43_MASK       (0x800U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ43_SHIFT      (11U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ43_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ43(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ43_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ43_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ44_MASK       (0x1000U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ44_SHIFT      (12U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ44_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ44(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ44_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ44_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ45_MASK       (0x2000U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ45_SHIFT      (13U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ45_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ45(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ45_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ45_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ46_MASK       (0x4000U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ46_SHIFT      (14U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ46_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ46(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ46_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ46_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ49_MASK       (0x20000U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ49_SHIFT      (17U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ49_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ49(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ49_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ49_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ50_MASK       (0x40000U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ50_SHIFT      (18U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ50_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ50(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ50_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ50_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ51_MASK       (0x80000U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ51_SHIFT      (19U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ51_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ51(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ51_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ51_MASK)

#define MC_ME_PRTN4_COFB1_CLKEN_REQ52_MASK       (0x100000U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ52_SHIFT      (20U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ52_WIDTH      (1U)
#define MC_ME_PRTN4_COFB1_CLKEN_REQ52(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN4_COFB1_CLKEN_REQ52_SHIFT)) & MC_ME_PRTN4_COFB1_CLKEN_REQ52_MASK)
/*! @} */

/*! @name PRTN5_PCONF - Partition 5 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN5_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN5_PCONF_PCE_SHIFT              (0U)
#define MC_ME_PRTN5_PCONF_PCE_WIDTH              (1U)
#define MC_ME_PRTN5_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_PCONF_PCE_SHIFT)) & MC_ME_PRTN5_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN5_PUPD - Partition 5 Process Update Register */
/*! @{ */

#define MC_ME_PRTN5_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN5_PUPD_PCUD_SHIFT              (0U)
#define MC_ME_PRTN5_PUPD_PCUD_WIDTH              (1U)
#define MC_ME_PRTN5_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_PUPD_PCUD_SHIFT)) & MC_ME_PRTN5_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN5_STAT - Partition 5 Status Register */
/*! @{ */

#define MC_ME_PRTN5_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN5_STAT_PCS_SHIFT               (0U)
#define MC_ME_PRTN5_STAT_PCS_WIDTH               (1U)
#define MC_ME_PRTN5_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_STAT_PCS_SHIFT)) & MC_ME_PRTN5_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN5_COFB0_STAT - Partition 5 COFB Set 0 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN5_COFB0_STAT_BLOCK1_MASK       (0x2U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK1_SHIFT      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK1_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK1(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK1_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK1_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK2_MASK       (0x4U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK2_SHIFT      (2U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK2_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK2(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK2_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK2_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK3_MASK       (0x8U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK3_SHIFT      (3U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK3_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK3(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK3_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK3_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK4_MASK       (0x10U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK4_SHIFT      (4U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK4_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK4(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK4_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK4_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK5_MASK       (0x20U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK5_SHIFT      (5U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK5_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK5(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK5_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK5_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK6_MASK       (0x40U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK6_SHIFT      (6U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK6_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK6(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK6_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK6_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK7_MASK       (0x80U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK7_SHIFT      (7U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK7_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK7(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK7_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK7_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK8_MASK       (0x100U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK8_SHIFT      (8U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK8_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK8(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK8_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK8_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK10_MASK      (0x400U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK10_SHIFT     (10U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK10_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK10(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK10_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK10_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK12_MASK      (0x1000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK12_SHIFT     (12U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK12_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK12(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK12_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK12_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK14_MASK      (0x4000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK14_SHIFT     (14U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK14_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK14(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK14_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK14_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK16_MASK      (0x10000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK16_SHIFT     (16U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK16_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK16(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK16_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK16_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK18_MASK      (0x40000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK18_SHIFT     (18U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK18_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK18(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK18_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK18_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK20_MASK      (0x100000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK20_SHIFT     (20U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK20_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK20(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK20_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK20_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK22_MASK      (0x400000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK22_SHIFT     (22U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK22_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK22(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK22_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK22_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK24_MASK      (0x1000000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK24_SHIFT     (24U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK24_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK24(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK24_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK24_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK26_MASK      (0x4000000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK26_SHIFT     (26U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK26_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK26(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK26_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK26_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK27_MASK      (0x8000000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK27_SHIFT     (27U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK27_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK27(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK27_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK27_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK28_MASK      (0x10000000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK28_SHIFT     (28U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK28_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK28(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK28_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK28_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK29_MASK      (0x20000000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK29_SHIFT     (29U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK29_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK29(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK29_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK29_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK30_MASK      (0x40000000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK30_SHIFT     (30U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK30_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK30(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK30_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK30_MASK)

#define MC_ME_PRTN5_COFB0_STAT_BLOCK31_MASK      (0x80000000U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK31_SHIFT     (31U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK31_WIDTH     (1U)
#define MC_ME_PRTN5_COFB0_STAT_BLOCK31(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_STAT_BLOCK31_SHIFT)) & MC_ME_PRTN5_COFB0_STAT_BLOCK31_MASK)
/*! @} */

/*! @name PRTN5_COFB1_STAT - Partition 5 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN5_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK32_SHIFT     (0U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK32_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK33_MASK      (0x2U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK33_SHIFT     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK33_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK33(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK33_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK33_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK34_MASK      (0x4U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK34_SHIFT     (2U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK34_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK34(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK34_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK34_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK35_SHIFT     (3U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK35_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK36_MASK      (0x10U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK36_SHIFT     (4U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK36_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK36(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK36_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK36_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK37_MASK      (0x20U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK37_SHIFT     (5U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK37_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK37(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK37_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK37_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK38_SHIFT     (6U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK38_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK39_SHIFT     (7U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK39_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK40_MASK      (0x100U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK40_SHIFT     (8U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK40_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK40(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK40_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK40_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK41_MASK      (0x200U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK41_SHIFT     (9U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK41_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK41(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK41_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK41_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK42_MASK      (0x400U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK42_SHIFT     (10U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK42_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK42(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK42_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK42_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK43_MASK      (0x800U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK43_SHIFT     (11U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK43_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK43(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK43_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK43_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK44_MASK      (0x1000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK44_SHIFT     (12U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK44_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK44(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK44_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK44_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK45_SHIFT     (13U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK45_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK46_MASK      (0x4000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK46_SHIFT     (14U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK46_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK46(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK46_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK46_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK47_MASK      (0x8000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK47_SHIFT     (15U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK47_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK47(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK47_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK47_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK48_MASK      (0x10000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK48_SHIFT     (16U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK48_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK48(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK48_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK48_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK49_MASK      (0x20000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK49_SHIFT     (17U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK49_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK49(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK49_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK49_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK50_MASK      (0x40000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK50_SHIFT     (18U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK50_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK50(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK50_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK50_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK51_MASK      (0x80000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK51_SHIFT     (19U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK51_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK51(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK51_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK51_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK52_MASK      (0x100000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK52_SHIFT     (20U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK52_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK52(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK52_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK52_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK53_MASK      (0x200000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK53_SHIFT     (21U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK53_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK53(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK53_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK53_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK54_MASK      (0x400000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK54_SHIFT     (22U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK54_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK54(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK54_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK54_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK55_MASK      (0x800000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK55_SHIFT     (23U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK55_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK55(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK55_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK55_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK56_MASK      (0x1000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK56_SHIFT     (24U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK56_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK56(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK56_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK56_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK57_MASK      (0x2000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK57_SHIFT     (25U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK57_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK57(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK57_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK57_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK58_MASK      (0x4000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK58_SHIFT     (26U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK58_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK58(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK58_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK58_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK59_MASK      (0x8000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK59_SHIFT     (27U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK59_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK59(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK59_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK59_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK60_MASK      (0x10000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK60_SHIFT     (28U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK60_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK60(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK60_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK60_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK61_MASK      (0x20000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK61_SHIFT     (29U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK61_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK61(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK61_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK61_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK62_MASK      (0x40000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK62_SHIFT     (30U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK62_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK62(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK62_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK62_MASK)

#define MC_ME_PRTN5_COFB1_STAT_BLOCK63_MASK      (0x80000000U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK63_SHIFT     (31U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK63_WIDTH     (1U)
#define MC_ME_PRTN5_COFB1_STAT_BLOCK63(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_STAT_BLOCK63_SHIFT)) & MC_ME_PRTN5_COFB1_STAT_BLOCK63_MASK)
/*! @} */

/*! @name PRTN5_COFB2_STAT - Partition 5 COFB Set 2 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN5_COFB2_STAT_BLOCK64_MASK      (0x1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK64_SHIFT     (0U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK64_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK64(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK64_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK64_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK65_MASK      (0x2U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK65_SHIFT     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK65_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK65(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK65_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK65_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK66_MASK      (0x4U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK66_SHIFT     (2U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK66_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK66(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK66_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK66_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK67_MASK      (0x8U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK67_SHIFT     (3U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK67_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK67(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK67_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK67_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK68_MASK      (0x10U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK68_SHIFT     (4U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK68_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK68(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK68_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK68_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK69_MASK      (0x20U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK69_SHIFT     (5U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK69_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK69(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK69_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK69_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK70_MASK      (0x40U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK70_SHIFT     (6U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK70_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK70(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK70_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK70_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK71_MASK      (0x80U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK71_SHIFT     (7U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK71_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK71(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK71_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK71_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK72_MASK      (0x100U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK72_SHIFT     (8U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK72_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK72(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK72_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK72_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK73_MASK      (0x200U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK73_SHIFT     (9U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK73_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK73(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK73_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK73_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK76_MASK      (0x1000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK76_SHIFT     (12U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK76_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK76(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK76_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK76_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK77_MASK      (0x2000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK77_SHIFT     (13U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK77_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK77(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK77_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK77_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK78_MASK      (0x4000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK78_SHIFT     (14U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK78_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK78(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK78_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK78_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK79_MASK      (0x8000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK79_SHIFT     (15U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK79_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK79(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK79_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK79_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK80_MASK      (0x10000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK80_SHIFT     (16U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK80_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK80(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK80_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK80_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK81_MASK      (0x20000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK81_SHIFT     (17U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK81_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK81(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK81_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK81_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK82_MASK      (0x40000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK82_SHIFT     (18U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK82_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK82(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK82_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK82_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK83_MASK      (0x80000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK83_SHIFT     (19U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK83_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK83(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK83_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK83_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK84_MASK      (0x100000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK84_SHIFT     (20U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK84_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK84(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK84_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK84_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK85_MASK      (0x200000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK85_SHIFT     (21U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK85_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK85(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK85_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK85_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK86_MASK      (0x400000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK86_SHIFT     (22U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK86_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK86(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK86_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK86_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK87_MASK      (0x800000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK87_SHIFT     (23U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK87_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK87(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK87_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK87_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK88_MASK      (0x1000000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK88_SHIFT     (24U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK88_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK88(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK88_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK88_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK90_MASK      (0x4000000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK90_SHIFT     (26U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK90_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK90(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK90_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK90_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK91_MASK      (0x8000000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK91_SHIFT     (27U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK91_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK91(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK91_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK91_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK92_MASK      (0x10000000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK92_SHIFT     (28U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK92_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK92(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK92_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK92_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK94_MASK      (0x40000000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK94_SHIFT     (30U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK94_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK94(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK94_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK94_MASK)

#define MC_ME_PRTN5_COFB2_STAT_BLOCK95_MASK      (0x80000000U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK95_SHIFT     (31U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK95_WIDTH     (1U)
#define MC_ME_PRTN5_COFB2_STAT_BLOCK95(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_STAT_BLOCK95_SHIFT)) & MC_ME_PRTN5_COFB2_STAT_BLOCK95_MASK)
/*! @} */

/*! @name PRTN5_COFB3_STAT - Partition 5 COFB Set 3 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN5_COFB3_STAT_BLOCK96_MASK      (0x1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK96_SHIFT     (0U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK96_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK96(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK96_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK96_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK97_MASK      (0x2U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK97_SHIFT     (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK97_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK97(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK97_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK97_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK98_MASK      (0x4U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK98_SHIFT     (2U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK98_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK98(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK98_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK98_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK99_MASK      (0x8U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK99_SHIFT     (3U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK99_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK99(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK99_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK99_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK100_MASK     (0x10U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK100_SHIFT    (4U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK100_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK100(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK100_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK100_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK101_MASK     (0x20U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK101_SHIFT    (5U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK101_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK101(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK101_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK101_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK102_MASK     (0x40U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK102_SHIFT    (6U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK102_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK102(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK102_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK102_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK103_MASK     (0x80U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK103_SHIFT    (7U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK103_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK103(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK103_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK103_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK104_MASK     (0x100U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK104_SHIFT    (8U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK104_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK104(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK104_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK104_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK105_MASK     (0x200U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK105_SHIFT    (9U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK105_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK105(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK105_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK105_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK106_MASK     (0x400U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK106_SHIFT    (10U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK106_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK106(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK106_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK106_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK107_MASK     (0x800U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK107_SHIFT    (11U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK107_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK107(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK107_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK107_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK108_MASK     (0x1000U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK108_SHIFT    (12U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK108_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK108(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK108_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK108_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK109_MASK     (0x2000U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK109_SHIFT    (13U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK109_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK109(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK109_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK109_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK110_MASK     (0x4000U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK110_SHIFT    (14U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK110_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK110(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK110_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK110_MASK)

#define MC_ME_PRTN5_COFB3_STAT_BLOCK111_MASK     (0x8000U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK111_SHIFT    (15U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK111_WIDTH    (1U)
#define MC_ME_PRTN5_COFB3_STAT_BLOCK111(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_STAT_BLOCK111_SHIFT)) & MC_ME_PRTN5_COFB3_STAT_BLOCK111_MASK)
/*! @} */

/*! @name PRTN5_COFB0_CLKEN - Partition 5 COFB Set 0 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN5_COFB0_CLKEN_REQ2_MASK        (0x4U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ2_SHIFT       (2U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ2_WIDTH       (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ2(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ2_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ2_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ3_MASK        (0x8U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ3_SHIFT       (3U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ3_WIDTH       (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ3(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ3_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ3_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ4_MASK        (0x10U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ4_SHIFT       (4U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ4_WIDTH       (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ4(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ4_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ4_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ5_MASK        (0x20U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ5_SHIFT       (5U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ5_WIDTH       (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ5(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ5_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ5_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ6_MASK        (0x40U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ6_SHIFT       (6U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ6_WIDTH       (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ6(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ6_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ6_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ7_MASK        (0x80U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ7_SHIFT       (7U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ7_WIDTH       (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ7(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ7_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ7_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ8_MASK        (0x100U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ8_SHIFT       (8U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ8_WIDTH       (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ8(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ8_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ8_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ10_MASK       (0x400U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ10_SHIFT      (10U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ10_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ10(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ10_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ10_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ12_MASK       (0x1000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ12_SHIFT      (12U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ12_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ12(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ12_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ12_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ14_MASK       (0x4000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ14_SHIFT      (14U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ14_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ14(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ14_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ14_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ16_MASK       (0x10000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ16_SHIFT      (16U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ16_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ16(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ16_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ16_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ18_MASK       (0x40000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ18_SHIFT      (18U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ18_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ18(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ18_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ18_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ20_MASK       (0x100000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ20_SHIFT      (20U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ20_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ20(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ20_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ20_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ22_MASK       (0x400000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ22_SHIFT      (22U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ22_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ22(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ22_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ22_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ26_MASK       (0x4000000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ26_SHIFT      (26U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ26_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ26(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ26_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ26_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ27_MASK       (0x8000000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ27_SHIFT      (27U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ27_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ27(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ27_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ27_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ28_MASK       (0x10000000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ28_SHIFT      (28U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ28_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ28(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ28_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ28_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ29_MASK       (0x20000000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ29_SHIFT      (29U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ29_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ29(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ29_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ29_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ30_MASK       (0x40000000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ30_SHIFT      (30U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ30_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ30(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ30_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ30_MASK)

#define MC_ME_PRTN5_COFB0_CLKEN_REQ31_MASK       (0x80000000U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ31_SHIFT      (31U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ31_WIDTH      (1U)
#define MC_ME_PRTN5_COFB0_CLKEN_REQ31(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB0_CLKEN_REQ31_SHIFT)) & MC_ME_PRTN5_COFB0_CLKEN_REQ31_MASK)
/*! @} */

/*! @name PRTN5_COFB1_CLKEN - Partition 5 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN5_COFB1_CLKEN_REQ32_MASK       (0x1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ32_SHIFT      (0U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ32_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ32(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ32_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ32_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ33_MASK       (0x2U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ33_SHIFT      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ33_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ33(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ33_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ33_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ34_MASK       (0x4U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ34_SHIFT      (2U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ34_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ34(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ34_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ34_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ35_MASK       (0x8U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ35_SHIFT      (3U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ35_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ35(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ35_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ35_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ36_MASK       (0x10U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ36_SHIFT      (4U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ36_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ36(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ36_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ36_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ37_MASK       (0x20U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ37_SHIFT      (5U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ37_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ37(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ37_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ37_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ38_MASK       (0x40U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ38_SHIFT      (6U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ38_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ38(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ38_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ38_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ39_MASK       (0x80U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ39_SHIFT      (7U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ39_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ39(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ39_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ39_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ40_MASK       (0x100U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ40_SHIFT      (8U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ40_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ40(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ40_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ40_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ41_MASK       (0x200U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ41_SHIFT      (9U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ41_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ41(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ41_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ41_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ42_MASK       (0x400U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ42_SHIFT      (10U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ42_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ42(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ42_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ42_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ43_MASK       (0x800U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ43_SHIFT      (11U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ43_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ43(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ43_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ43_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ44_MASK       (0x1000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ44_SHIFT      (12U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ44_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ44(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ44_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ44_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ45_MASK       (0x2000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ45_SHIFT      (13U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ45_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ45(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ45_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ45_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ46_MASK       (0x4000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ46_SHIFT      (14U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ46_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ46(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ46_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ46_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ47_MASK       (0x8000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ47_SHIFT      (15U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ47_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ47(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ47_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ47_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ48_MASK       (0x10000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ48_SHIFT      (16U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ48_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ48(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ48_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ48_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ49_MASK       (0x20000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ49_SHIFT      (17U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ49_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ49(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ49_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ49_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ50_MASK       (0x40000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ50_SHIFT      (18U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ50_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ50(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ50_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ50_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ51_MASK       (0x80000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ51_SHIFT      (19U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ51_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ51(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ51_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ51_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ52_MASK       (0x100000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ52_SHIFT      (20U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ52_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ52(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ52_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ52_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ53_MASK       (0x200000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ53_SHIFT      (21U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ53_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ53(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ53_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ53_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ54_MASK       (0x400000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ54_SHIFT      (22U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ54_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ54(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ54_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ54_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ55_MASK       (0x800000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ55_SHIFT      (23U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ55_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ55(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ55_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ55_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ56_MASK       (0x1000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ56_SHIFT      (24U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ56_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ56(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ56_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ56_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ57_MASK       (0x2000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ57_SHIFT      (25U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ57_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ57(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ57_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ57_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ58_MASK       (0x4000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ58_SHIFT      (26U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ58_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ58(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ58_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ58_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ59_MASK       (0x8000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ59_SHIFT      (27U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ59_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ59(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ59_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ59_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ60_MASK       (0x10000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ60_SHIFT      (28U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ60_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ60(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ60_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ60_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ61_MASK       (0x20000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ61_SHIFT      (29U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ61_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ61(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ61_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ61_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ62_MASK       (0x40000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ62_SHIFT      (30U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ62_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ62(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ62_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ62_MASK)

#define MC_ME_PRTN5_COFB1_CLKEN_REQ63_MASK       (0x80000000U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ63_SHIFT      (31U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ63_WIDTH      (1U)
#define MC_ME_PRTN5_COFB1_CLKEN_REQ63(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB1_CLKEN_REQ63_SHIFT)) & MC_ME_PRTN5_COFB1_CLKEN_REQ63_MASK)
/*! @} */

/*! @name PRTN5_COFB2_CLKEN - Partition 5 COFB Set 2 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN5_COFB2_CLKEN_REQ64_MASK       (0x1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ64_SHIFT      (0U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ64_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ64(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ64_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ64_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ65_MASK       (0x2U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ65_SHIFT      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ65_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ65(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ65_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ65_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ66_MASK       (0x4U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ66_SHIFT      (2U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ66_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ66(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ66_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ66_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ67_MASK       (0x8U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ67_SHIFT      (3U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ67_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ67(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ67_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ67_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ70_MASK       (0x40U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ70_SHIFT      (6U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ70_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ70(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ70_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ70_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ71_MASK       (0x80U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ71_SHIFT      (7U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ71_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ71(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ71_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ71_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ72_MASK       (0x100U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ72_SHIFT      (8U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ72_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ72(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ72_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ72_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ73_MASK       (0x200U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ73_SHIFT      (9U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ73_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ73(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ73_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ73_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ80_MASK       (0x10000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ80_SHIFT      (16U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ80_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ80(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ80_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ80_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ82_MASK       (0x40000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ82_SHIFT      (18U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ82_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ82(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ82_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ82_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ83_MASK       (0x80000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ83_SHIFT      (19U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ83_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ83(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ83_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ83_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ84_MASK       (0x100000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ84_SHIFT      (20U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ84_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ84(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ84_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ84_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ87_MASK       (0x800000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ87_SHIFT      (23U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ87_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ87(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ87_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ87_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ88_MASK       (0x1000000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ88_SHIFT      (24U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ88_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ88(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ88_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ88_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ94_MASK       (0x40000000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ94_SHIFT      (30U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ94_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ94(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ94_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ94_MASK)

#define MC_ME_PRTN5_COFB2_CLKEN_REQ95_MASK       (0x80000000U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ95_SHIFT      (31U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ95_WIDTH      (1U)
#define MC_ME_PRTN5_COFB2_CLKEN_REQ95(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB2_CLKEN_REQ95_SHIFT)) & MC_ME_PRTN5_COFB2_CLKEN_REQ95_MASK)
/*! @} */

/*! @name PRTN5_COFB3_CLKEN - Partition 5 COFB Set 3 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN5_COFB3_CLKEN_REQ96_MASK       (0x1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ96_SHIFT      (0U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ96_WIDTH      (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ96(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ96_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ96_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ97_MASK       (0x2U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ97_SHIFT      (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ97_WIDTH      (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ97(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ97_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ97_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ98_MASK       (0x4U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ98_SHIFT      (2U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ98_WIDTH      (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ98(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ98_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ98_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ99_MASK       (0x8U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ99_SHIFT      (3U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ99_WIDTH      (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ99(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ99_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ99_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ100_MASK      (0x10U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ100_SHIFT     (4U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ100_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ100(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ100_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ100_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ101_MASK      (0x20U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ101_SHIFT     (5U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ101_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ101(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ101_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ101_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ102_MASK      (0x40U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ102_SHIFT     (6U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ102_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ102(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ102_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ102_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ103_MASK      (0x80U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ103_SHIFT     (7U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ103_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ103(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ103_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ103_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ104_MASK      (0x100U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ104_SHIFT     (8U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ104_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ104(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ104_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ104_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ105_MASK      (0x200U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ105_SHIFT     (9U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ105_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ105(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ105_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ105_MASK)

#define MC_ME_PRTN5_COFB3_CLKEN_REQ106_MASK      (0x400U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ106_SHIFT     (10U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ106_WIDTH     (1U)
#define MC_ME_PRTN5_COFB3_CLKEN_REQ106(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN5_COFB3_CLKEN_REQ106_SHIFT)) & MC_ME_PRTN5_COFB3_CLKEN_REQ106_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MC_ME_Register_Masks */

/*!
 * @}
 */ /* end of group MC_ME_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MC_ME_H_) */
