/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CSTCU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CSTCU
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
#if !defined(S32Z2_CSTCU_H_)  /* Check if memory map has not been already included */
#define S32Z2_CSTCU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CSTCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSTCU_Peripheral_Access_Layer CSTCU Peripheral Access Layer
 * @{
 */

/** CSTCU - Size of Registers Arrays */
#define CSTCU_LRFSTAT_COUNT                       1u
#define CSTCU_LUFSTAT_COUNT                       1u
#define CSTCU_BYPLSTCU_COUNT                      1u
#define CSTCU_LSTCU_MBSCH_COUNT                   20u
#define CSTCU_LSTCU_LBSCH_COUNT                   20u

/** CSTCU - Register Layout Typedef */
typedef struct {
  __IO uint32_t RUNSWREG;                          /**< Run Software, offset: 0x0 */
  __IO uint32_t LSCHLVLD;                          /**< LSTCU Scheduler List Valid, offset: 0x4 */
  uint8_t RESERVED_0[4];
  __IO uint32_t WDG;                               /**< Watchdog Timer, offset: 0xC */
  __IO uint32_t IE;                                /**< Interrupt Enable, offset: 0x10 */
  __IO uint32_t IF;                                /**< Interrupt Flag, offset: 0x14 */
  uint8_t RESERVED_1[8];
  __IO uint32_t ERR_STAT;                          /**< Error Status, offset: 0x20 */
  uint8_t RESERVED_2[4];
  __IO uint32_t ERR_FM;                            /**< Error Fault Mapping, offset: 0x28 */
  uint8_t RESERVED_3[4];
  __I  uint32_t LRFSTAT[CSTCU_LRFSTAT_COUNT];      /**< LSTCU Recoverable Fault Status, array offset: 0x30, array step: 0x4 */
  uint8_t RESERVED_4[12];
  __I  uint32_t LUFSTAT[CSTCU_LUFSTAT_COUNT];      /**< LSTCU Unrecoverable Fault Status, array offset: 0x40, array step: 0x4 */
  uint8_t RESERVED_5[12];
  __IO uint32_t RDEN;                              /**< Reset Domain Self-Test Enable, offset: 0x50 */
  __I  uint32_t RDENSTAT;                          /**< Reset Domain Enable Status, offset: 0x54 */
  __I  uint32_t LASTRDEN;                          /**< Last Run Reset Domain Enable, offset: 0x58 */
  uint8_t RESERVED_6[4];
  __IO uint32_t BYPLSTCU[CSTCU_BYPLSTCU_COUNT];    /**< Bypass LSTCU, array offset: 0x60, array step: 0x4 */
  uint8_t RESERVED_7[12];
  __IO uint32_t STAG;                              /**< Stagger, offset: 0x70 */
  uint8_t RESERVED_8[396];
  __IO uint32_t LMBPTR[CSTCU_LSTCU_MBSCH_COUNT];   /**< LSTCU MBIST Run Phase Scheduler Pointer, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_9[176];
  __IO uint32_t LLBPTR[CSTCU_LSTCU_LBSCH_COUNT];   /**< LSTCU LBIST Run phase Scheduler Pointer, array offset: 0x300, array step: 0x4 */
} CSTCU_Type, *CSTCU_MemMapPtr;

/** Number of instances of the CSTCU module. */
#define CSTCU_INSTANCE_COUNT                     (1u)

/* CSTCU - Peripheral instance base addresses */
/** Peripheral CSTCU base address */
#define IP_CSTCU_BASE                            (0x41910000u)
/** Peripheral CSTCU base pointer */
#define IP_CSTCU                                 ((CSTCU_Type *)IP_CSTCU_BASE)
/** Array initializer of CSTCU peripheral base addresses */
#define IP_CSTCU_BASE_ADDRS                      { IP_CSTCU_BASE }
/** Array initializer of CSTCU peripheral base pointers */
#define IP_CSTCU_BASE_PTRS                       { IP_CSTCU }

/* ----------------------------------------------------------------------------
   -- CSTCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSTCU_Register_Masks CSTCU Register Masks
 * @{
 */

/*! @name RUNSWREG - Run Software */
/*! @{ */

#define CSTCU_RUNSWREG_RUNSW_MASK                (0x1U)
#define CSTCU_RUNSWREG_RUNSW_SHIFT               (0U)
#define CSTCU_RUNSWREG_RUNSW_WIDTH               (1U)
#define CSTCU_RUNSWREG_RUNSW(x)                  (((uint32_t)(((uint32_t)(x)) << CSTCU_RUNSWREG_RUNSW_SHIFT)) & CSTCU_RUNSWREG_RUNSW_MASK)
/*! @} */

/*! @name LSCHLVLD - LSTCU Scheduler List Valid */
/*! @{ */

#define CSTCU_LSCHLVLD_MBPLVLD_MASK              (0x100U)
#define CSTCU_LSCHLVLD_MBPLVLD_SHIFT             (8U)
#define CSTCU_LSCHLVLD_MBPLVLD_WIDTH             (1U)
#define CSTCU_LSCHLVLD_MBPLVLD(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_LSCHLVLD_MBPLVLD_SHIFT)) & CSTCU_LSCHLVLD_MBPLVLD_MASK)

#define CSTCU_LSCHLVLD_LBPLVLD_MASK              (0x10000U)
#define CSTCU_LSCHLVLD_LBPLVLD_SHIFT             (16U)
#define CSTCU_LSCHLVLD_LBPLVLD_WIDTH             (1U)
#define CSTCU_LSCHLVLD_LBPLVLD(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_LSCHLVLD_LBPLVLD_SHIFT)) & CSTCU_LSCHLVLD_LBPLVLD_MASK)
/*! @} */

/*! @name WDG - Watchdog Timer */
/*! @{ */

#define CSTCU_WDG_WDGEOC_MASK                    (0xFFFFFFFFU)
#define CSTCU_WDG_WDGEOC_SHIFT                   (0U)
#define CSTCU_WDG_WDGEOC_WIDTH                   (32U)
#define CSTCU_WDG_WDGEOC(x)                      (((uint32_t)(((uint32_t)(x)) << CSTCU_WDG_WDGEOC_SHIFT)) & CSTCU_WDG_WDGEOC_MASK)
/*! @} */

/*! @name IE - Interrupt Enable */
/*! @{ */

#define CSTCU_IE_STEND_IE_MASK                   (0x1U)
#define CSTCU_IE_STEND_IE_SHIFT                  (0U)
#define CSTCU_IE_STEND_IE_WIDTH                  (1U)
#define CSTCU_IE_STEND_IE(x)                     (((uint32_t)(((uint32_t)(x)) << CSTCU_IE_STEND_IE_SHIFT)) & CSTCU_IE_STEND_IE_MASK)
/*! @} */

/*! @name IF - Interrupt Flag */
/*! @{ */

#define CSTCU_IF_STEND_IF_MASK                   (0x1U)
#define CSTCU_IF_STEND_IF_SHIFT                  (0U)
#define CSTCU_IF_STEND_IF_WIDTH                  (1U)
#define CSTCU_IF_STEND_IF(x)                     (((uint32_t)(((uint32_t)(x)) << CSTCU_IF_STEND_IF_SHIFT)) & CSTCU_IF_STEND_IF_MASK)
/*! @} */

/*! @name ERR_STAT - Error Status */
/*! @{ */

#define CSTCU_ERR_STAT_INVP_MB_MASK              (0x2U)
#define CSTCU_ERR_STAT_INVP_MB_SHIFT             (1U)
#define CSTCU_ERR_STAT_INVP_MB_WIDTH             (1U)
#define CSTCU_ERR_STAT_INVP_MB(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_ERR_STAT_INVP_MB_SHIFT)) & CSTCU_ERR_STAT_INVP_MB_MASK)

#define CSTCU_ERR_STAT_INVP_LB_MASK              (0x4U)
#define CSTCU_ERR_STAT_INVP_LB_SHIFT             (2U)
#define CSTCU_ERR_STAT_INVP_LB_WIDTH             (1U)
#define CSTCU_ERR_STAT_INVP_LB(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_ERR_STAT_INVP_LB_SHIFT)) & CSTCU_ERR_STAT_INVP_LB_MASK)

#define CSTCU_ERR_STAT_ABORTHW_MASK              (0x100U)
#define CSTCU_ERR_STAT_ABORTHW_SHIFT             (8U)
#define CSTCU_ERR_STAT_ABORTHW_WIDTH             (1U)
#define CSTCU_ERR_STAT_ABORTHW(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_ERR_STAT_ABORTHW_SHIFT)) & CSTCU_ERR_STAT_ABORTHW_MASK)

#define CSTCU_ERR_STAT_UFSF_MASK                 (0x10000U)
#define CSTCU_ERR_STAT_UFSF_SHIFT                (16U)
#define CSTCU_ERR_STAT_UFSF_WIDTH                (1U)
#define CSTCU_ERR_STAT_UFSF(x)                   (((uint32_t)(((uint32_t)(x)) << CSTCU_ERR_STAT_UFSF_SHIFT)) & CSTCU_ERR_STAT_UFSF_MASK)

#define CSTCU_ERR_STAT_RFSF_MASK                 (0x20000U)
#define CSTCU_ERR_STAT_RFSF_SHIFT                (17U)
#define CSTCU_ERR_STAT_RFSF_WIDTH                (1U)
#define CSTCU_ERR_STAT_RFSF(x)                   (((uint32_t)(((uint32_t)(x)) << CSTCU_ERR_STAT_RFSF_SHIFT)) & CSTCU_ERR_STAT_RFSF_MASK)
/*! @} */

/*! @name ERR_FM - Error Fault Mapping */
/*! @{ */

#define CSTCU_ERR_FM_INVPFMMB_MASK               (0x2U)
#define CSTCU_ERR_FM_INVPFMMB_SHIFT              (1U)
#define CSTCU_ERR_FM_INVPFMMB_WIDTH              (1U)
#define CSTCU_ERR_FM_INVPFMMB(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_ERR_FM_INVPFMMB_SHIFT)) & CSTCU_ERR_FM_INVPFMMB_MASK)

#define CSTCU_ERR_FM_INVPFMLB_MASK               (0x4U)
#define CSTCU_ERR_FM_INVPFMLB_SHIFT              (2U)
#define CSTCU_ERR_FM_INVPFMLB_WIDTH              (1U)
#define CSTCU_ERR_FM_INVPFMLB(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_ERR_FM_INVPFMLB_SHIFT)) & CSTCU_ERR_FM_INVPFMLB_MASK)
/*! @} */

/*! @name LRFSTAT - LSTCU Recoverable Fault Status */
/*! @{ */

#define CSTCU_LRFSTAT_RFSLSTCU0_MASK             (0x1U)
#define CSTCU_LRFSTAT_RFSLSTCU0_SHIFT            (0U)
#define CSTCU_LRFSTAT_RFSLSTCU0_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU0(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU0_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU0_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU1_MASK             (0x2U)
#define CSTCU_LRFSTAT_RFSLSTCU1_SHIFT            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU1_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU1(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU1_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU1_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU2_MASK             (0x4U)
#define CSTCU_LRFSTAT_RFSLSTCU2_SHIFT            (2U)
#define CSTCU_LRFSTAT_RFSLSTCU2_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU2(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU2_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU2_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU3_MASK             (0x8U)
#define CSTCU_LRFSTAT_RFSLSTCU3_SHIFT            (3U)
#define CSTCU_LRFSTAT_RFSLSTCU3_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU3(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU3_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU3_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU4_MASK             (0x10U)
#define CSTCU_LRFSTAT_RFSLSTCU4_SHIFT            (4U)
#define CSTCU_LRFSTAT_RFSLSTCU4_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU4(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU4_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU4_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU5_MASK             (0x20U)
#define CSTCU_LRFSTAT_RFSLSTCU5_SHIFT            (5U)
#define CSTCU_LRFSTAT_RFSLSTCU5_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU5(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU5_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU5_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU6_MASK             (0x40U)
#define CSTCU_LRFSTAT_RFSLSTCU6_SHIFT            (6U)
#define CSTCU_LRFSTAT_RFSLSTCU6_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU6(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU6_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU6_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU7_MASK             (0x80U)
#define CSTCU_LRFSTAT_RFSLSTCU7_SHIFT            (7U)
#define CSTCU_LRFSTAT_RFSLSTCU7_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU7(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU7_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU7_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU8_MASK             (0x100U)
#define CSTCU_LRFSTAT_RFSLSTCU8_SHIFT            (8U)
#define CSTCU_LRFSTAT_RFSLSTCU8_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU8(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU8_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU8_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU9_MASK             (0x200U)
#define CSTCU_LRFSTAT_RFSLSTCU9_SHIFT            (9U)
#define CSTCU_LRFSTAT_RFSLSTCU9_WIDTH            (1U)
#define CSTCU_LRFSTAT_RFSLSTCU9(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU9_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU9_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU10_MASK            (0x400U)
#define CSTCU_LRFSTAT_RFSLSTCU10_SHIFT           (10U)
#define CSTCU_LRFSTAT_RFSLSTCU10_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU10(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU10_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU10_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU11_MASK            (0x800U)
#define CSTCU_LRFSTAT_RFSLSTCU11_SHIFT           (11U)
#define CSTCU_LRFSTAT_RFSLSTCU11_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU11(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU11_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU11_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU12_MASK            (0x1000U)
#define CSTCU_LRFSTAT_RFSLSTCU12_SHIFT           (12U)
#define CSTCU_LRFSTAT_RFSLSTCU12_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU12(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU12_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU12_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU13_MASK            (0x2000U)
#define CSTCU_LRFSTAT_RFSLSTCU13_SHIFT           (13U)
#define CSTCU_LRFSTAT_RFSLSTCU13_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU13(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU13_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU13_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU14_MASK            (0x4000U)
#define CSTCU_LRFSTAT_RFSLSTCU14_SHIFT           (14U)
#define CSTCU_LRFSTAT_RFSLSTCU14_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU14(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU14_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU14_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU15_MASK            (0x8000U)
#define CSTCU_LRFSTAT_RFSLSTCU15_SHIFT           (15U)
#define CSTCU_LRFSTAT_RFSLSTCU15_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU15(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU15_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU15_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU16_MASK            (0x10000U)
#define CSTCU_LRFSTAT_RFSLSTCU16_SHIFT           (16U)
#define CSTCU_LRFSTAT_RFSLSTCU16_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU16(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU16_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU16_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU17_MASK            (0x20000U)
#define CSTCU_LRFSTAT_RFSLSTCU17_SHIFT           (17U)
#define CSTCU_LRFSTAT_RFSLSTCU17_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU17(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU17_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU17_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU18_MASK            (0x40000U)
#define CSTCU_LRFSTAT_RFSLSTCU18_SHIFT           (18U)
#define CSTCU_LRFSTAT_RFSLSTCU18_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU18(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU18_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU18_MASK)

#define CSTCU_LRFSTAT_RFSLSTCU19_MASK            (0x80000U)
#define CSTCU_LRFSTAT_RFSLSTCU19_SHIFT           (19U)
#define CSTCU_LRFSTAT_RFSLSTCU19_WIDTH           (1U)
#define CSTCU_LRFSTAT_RFSLSTCU19(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LRFSTAT_RFSLSTCU19_SHIFT)) & CSTCU_LRFSTAT_RFSLSTCU19_MASK)
/*! @} */

/*! @name LUFSTAT - LSTCU Unrecoverable Fault Status */
/*! @{ */

#define CSTCU_LUFSTAT_UFSLSTCU0_MASK             (0x1U)
#define CSTCU_LUFSTAT_UFSLSTCU0_SHIFT            (0U)
#define CSTCU_LUFSTAT_UFSLSTCU0_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU0(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU0_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU0_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU1_MASK             (0x2U)
#define CSTCU_LUFSTAT_UFSLSTCU1_SHIFT            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU1_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU1(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU1_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU1_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU2_MASK             (0x4U)
#define CSTCU_LUFSTAT_UFSLSTCU2_SHIFT            (2U)
#define CSTCU_LUFSTAT_UFSLSTCU2_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU2(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU2_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU2_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU3_MASK             (0x8U)
#define CSTCU_LUFSTAT_UFSLSTCU3_SHIFT            (3U)
#define CSTCU_LUFSTAT_UFSLSTCU3_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU3(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU3_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU3_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU4_MASK             (0x10U)
#define CSTCU_LUFSTAT_UFSLSTCU4_SHIFT            (4U)
#define CSTCU_LUFSTAT_UFSLSTCU4_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU4(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU4_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU4_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU5_MASK             (0x20U)
#define CSTCU_LUFSTAT_UFSLSTCU5_SHIFT            (5U)
#define CSTCU_LUFSTAT_UFSLSTCU5_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU5(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU5_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU5_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU6_MASK             (0x40U)
#define CSTCU_LUFSTAT_UFSLSTCU6_SHIFT            (6U)
#define CSTCU_LUFSTAT_UFSLSTCU6_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU6(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU6_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU6_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU7_MASK             (0x80U)
#define CSTCU_LUFSTAT_UFSLSTCU7_SHIFT            (7U)
#define CSTCU_LUFSTAT_UFSLSTCU7_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU7(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU7_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU7_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU8_MASK             (0x100U)
#define CSTCU_LUFSTAT_UFSLSTCU8_SHIFT            (8U)
#define CSTCU_LUFSTAT_UFSLSTCU8_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU8(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU8_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU8_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU9_MASK             (0x200U)
#define CSTCU_LUFSTAT_UFSLSTCU9_SHIFT            (9U)
#define CSTCU_LUFSTAT_UFSLSTCU9_WIDTH            (1U)
#define CSTCU_LUFSTAT_UFSLSTCU9(x)               (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU9_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU9_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU10_MASK            (0x400U)
#define CSTCU_LUFSTAT_UFSLSTCU10_SHIFT           (10U)
#define CSTCU_LUFSTAT_UFSLSTCU10_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU10(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU10_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU10_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU11_MASK            (0x800U)
#define CSTCU_LUFSTAT_UFSLSTCU11_SHIFT           (11U)
#define CSTCU_LUFSTAT_UFSLSTCU11_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU11(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU11_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU11_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU12_MASK            (0x1000U)
#define CSTCU_LUFSTAT_UFSLSTCU12_SHIFT           (12U)
#define CSTCU_LUFSTAT_UFSLSTCU12_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU12(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU12_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU12_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU13_MASK            (0x2000U)
#define CSTCU_LUFSTAT_UFSLSTCU13_SHIFT           (13U)
#define CSTCU_LUFSTAT_UFSLSTCU13_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU13(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU13_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU13_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU14_MASK            (0x4000U)
#define CSTCU_LUFSTAT_UFSLSTCU14_SHIFT           (14U)
#define CSTCU_LUFSTAT_UFSLSTCU14_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU14(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU14_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU14_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU15_MASK            (0x8000U)
#define CSTCU_LUFSTAT_UFSLSTCU15_SHIFT           (15U)
#define CSTCU_LUFSTAT_UFSLSTCU15_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU15(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU15_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU15_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU16_MASK            (0x10000U)
#define CSTCU_LUFSTAT_UFSLSTCU16_SHIFT           (16U)
#define CSTCU_LUFSTAT_UFSLSTCU16_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU16(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU16_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU16_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU17_MASK            (0x20000U)
#define CSTCU_LUFSTAT_UFSLSTCU17_SHIFT           (17U)
#define CSTCU_LUFSTAT_UFSLSTCU17_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU17(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU17_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU17_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU18_MASK            (0x40000U)
#define CSTCU_LUFSTAT_UFSLSTCU18_SHIFT           (18U)
#define CSTCU_LUFSTAT_UFSLSTCU18_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU18(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU18_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU18_MASK)

#define CSTCU_LUFSTAT_UFSLSTCU19_MASK            (0x80000U)
#define CSTCU_LUFSTAT_UFSLSTCU19_SHIFT           (19U)
#define CSTCU_LUFSTAT_UFSLSTCU19_WIDTH           (1U)
#define CSTCU_LUFSTAT_UFSLSTCU19(x)              (((uint32_t)(((uint32_t)(x)) << CSTCU_LUFSTAT_UFSLSTCU19_SHIFT)) & CSTCU_LUFSTAT_UFSLSTCU19_MASK)
/*! @} */

/*! @name RDEN - Reset Domain Self-Test Enable */
/*! @{ */

#define CSTCU_RDEN_SERD0_MASK                    (0x1U)
#define CSTCU_RDEN_SERD0_SHIFT                   (0U)
#define CSTCU_RDEN_SERD0_WIDTH                   (1U)
#define CSTCU_RDEN_SERD0(x)                      (((uint32_t)(((uint32_t)(x)) << CSTCU_RDEN_SERD0_SHIFT)) & CSTCU_RDEN_SERD0_MASK)

#define CSTCU_RDEN_SERD1_MASK                    (0x2U)
#define CSTCU_RDEN_SERD1_SHIFT                   (1U)
#define CSTCU_RDEN_SERD1_WIDTH                   (1U)
#define CSTCU_RDEN_SERD1(x)                      (((uint32_t)(((uint32_t)(x)) << CSTCU_RDEN_SERD1_SHIFT)) & CSTCU_RDEN_SERD1_MASK)

#define CSTCU_RDEN_SERD2_MASK                    (0x4U)
#define CSTCU_RDEN_SERD2_SHIFT                   (2U)
#define CSTCU_RDEN_SERD2_WIDTH                   (1U)
#define CSTCU_RDEN_SERD2(x)                      (((uint32_t)(((uint32_t)(x)) << CSTCU_RDEN_SERD2_SHIFT)) & CSTCU_RDEN_SERD2_MASK)

#define CSTCU_RDEN_SERD3_MASK                    (0x8U)
#define CSTCU_RDEN_SERD3_SHIFT                   (3U)
#define CSTCU_RDEN_SERD3_WIDTH                   (1U)
#define CSTCU_RDEN_SERD3(x)                      (((uint32_t)(((uint32_t)(x)) << CSTCU_RDEN_SERD3_SHIFT)) & CSTCU_RDEN_SERD3_MASK)
/*! @} */

/*! @name RDENSTAT - Reset Domain Enable Status */
/*! @{ */

#define CSTCU_RDENSTAT_SESRD0_MASK               (0x1U)
#define CSTCU_RDENSTAT_SESRD0_SHIFT              (0U)
#define CSTCU_RDENSTAT_SESRD0_WIDTH              (1U)
#define CSTCU_RDENSTAT_SESRD0(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_RDENSTAT_SESRD0_SHIFT)) & CSTCU_RDENSTAT_SESRD0_MASK)

#define CSTCU_RDENSTAT_SESRD1_MASK               (0x2U)
#define CSTCU_RDENSTAT_SESRD1_SHIFT              (1U)
#define CSTCU_RDENSTAT_SESRD1_WIDTH              (1U)
#define CSTCU_RDENSTAT_SESRD1(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_RDENSTAT_SESRD1_SHIFT)) & CSTCU_RDENSTAT_SESRD1_MASK)

#define CSTCU_RDENSTAT_SESRD2_MASK               (0x4U)
#define CSTCU_RDENSTAT_SESRD2_SHIFT              (2U)
#define CSTCU_RDENSTAT_SESRD2_WIDTH              (1U)
#define CSTCU_RDENSTAT_SESRD2(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_RDENSTAT_SESRD2_SHIFT)) & CSTCU_RDENSTAT_SESRD2_MASK)

#define CSTCU_RDENSTAT_SESRD3_MASK               (0x8U)
#define CSTCU_RDENSTAT_SESRD3_SHIFT              (3U)
#define CSTCU_RDENSTAT_SESRD3_WIDTH              (1U)
#define CSTCU_RDENSTAT_SESRD3(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_RDENSTAT_SESRD3_SHIFT)) & CSTCU_RDENSTAT_SESRD3_MASK)
/*! @} */

/*! @name LASTRDEN - Last Run Reset Domain Enable */
/*! @{ */

#define CSTCU_LASTRDEN_LRSERD0_MASK              (0x1U)
#define CSTCU_LASTRDEN_LRSERD0_SHIFT             (0U)
#define CSTCU_LASTRDEN_LRSERD0_WIDTH             (1U)
#define CSTCU_LASTRDEN_LRSERD0(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_LASTRDEN_LRSERD0_SHIFT)) & CSTCU_LASTRDEN_LRSERD0_MASK)

#define CSTCU_LASTRDEN_LRSERD1_MASK              (0x2U)
#define CSTCU_LASTRDEN_LRSERD1_SHIFT             (1U)
#define CSTCU_LASTRDEN_LRSERD1_WIDTH             (1U)
#define CSTCU_LASTRDEN_LRSERD1(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_LASTRDEN_LRSERD1_SHIFT)) & CSTCU_LASTRDEN_LRSERD1_MASK)

#define CSTCU_LASTRDEN_LRSERD2_MASK              (0x4U)
#define CSTCU_LASTRDEN_LRSERD2_SHIFT             (2U)
#define CSTCU_LASTRDEN_LRSERD2_WIDTH             (1U)
#define CSTCU_LASTRDEN_LRSERD2(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_LASTRDEN_LRSERD2_SHIFT)) & CSTCU_LASTRDEN_LRSERD2_MASK)

#define CSTCU_LASTRDEN_LRSERD3_MASK              (0x8U)
#define CSTCU_LASTRDEN_LRSERD3_SHIFT             (3U)
#define CSTCU_LASTRDEN_LRSERD3_WIDTH             (1U)
#define CSTCU_LASTRDEN_LRSERD3(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_LASTRDEN_LRSERD3_SHIFT)) & CSTCU_LASTRDEN_LRSERD3_MASK)
/*! @} */

/*! @name BYPLSTCU - Bypass LSTCU */
/*! @{ */

#define CSTCU_BYPLSTCU_BYP_L0_MASK               (0x1U)
#define CSTCU_BYPLSTCU_BYP_L0_SHIFT              (0U)
#define CSTCU_BYPLSTCU_BYP_L0_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L0(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L0_SHIFT)) & CSTCU_BYPLSTCU_BYP_L0_MASK)

#define CSTCU_BYPLSTCU_BYP_L1_MASK               (0x2U)
#define CSTCU_BYPLSTCU_BYP_L1_SHIFT              (1U)
#define CSTCU_BYPLSTCU_BYP_L1_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L1(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L1_SHIFT)) & CSTCU_BYPLSTCU_BYP_L1_MASK)

#define CSTCU_BYPLSTCU_BYP_L2_MASK               (0x4U)
#define CSTCU_BYPLSTCU_BYP_L2_SHIFT              (2U)
#define CSTCU_BYPLSTCU_BYP_L2_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L2(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L2_SHIFT)) & CSTCU_BYPLSTCU_BYP_L2_MASK)

#define CSTCU_BYPLSTCU_BYP_L3_MASK               (0x8U)
#define CSTCU_BYPLSTCU_BYP_L3_SHIFT              (3U)
#define CSTCU_BYPLSTCU_BYP_L3_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L3(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L3_SHIFT)) & CSTCU_BYPLSTCU_BYP_L3_MASK)

#define CSTCU_BYPLSTCU_BYP_L4_MASK               (0x10U)
#define CSTCU_BYPLSTCU_BYP_L4_SHIFT              (4U)
#define CSTCU_BYPLSTCU_BYP_L4_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L4(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L4_SHIFT)) & CSTCU_BYPLSTCU_BYP_L4_MASK)

#define CSTCU_BYPLSTCU_BYP_L5_MASK               (0x20U)
#define CSTCU_BYPLSTCU_BYP_L5_SHIFT              (5U)
#define CSTCU_BYPLSTCU_BYP_L5_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L5(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L5_SHIFT)) & CSTCU_BYPLSTCU_BYP_L5_MASK)

#define CSTCU_BYPLSTCU_BYP_L6_MASK               (0x40U)
#define CSTCU_BYPLSTCU_BYP_L6_SHIFT              (6U)
#define CSTCU_BYPLSTCU_BYP_L6_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L6(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L6_SHIFT)) & CSTCU_BYPLSTCU_BYP_L6_MASK)

#define CSTCU_BYPLSTCU_BYP_L7_MASK               (0x80U)
#define CSTCU_BYPLSTCU_BYP_L7_SHIFT              (7U)
#define CSTCU_BYPLSTCU_BYP_L7_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L7(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L7_SHIFT)) & CSTCU_BYPLSTCU_BYP_L7_MASK)

#define CSTCU_BYPLSTCU_BYP_L8_MASK               (0x100U)
#define CSTCU_BYPLSTCU_BYP_L8_SHIFT              (8U)
#define CSTCU_BYPLSTCU_BYP_L8_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L8(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L8_SHIFT)) & CSTCU_BYPLSTCU_BYP_L8_MASK)

#define CSTCU_BYPLSTCU_BYP_L9_MASK               (0x200U)
#define CSTCU_BYPLSTCU_BYP_L9_SHIFT              (9U)
#define CSTCU_BYPLSTCU_BYP_L9_WIDTH              (1U)
#define CSTCU_BYPLSTCU_BYP_L9(x)                 (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L9_SHIFT)) & CSTCU_BYPLSTCU_BYP_L9_MASK)

#define CSTCU_BYPLSTCU_BYP_L10_MASK              (0x400U)
#define CSTCU_BYPLSTCU_BYP_L10_SHIFT             (10U)
#define CSTCU_BYPLSTCU_BYP_L10_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L10(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L10_SHIFT)) & CSTCU_BYPLSTCU_BYP_L10_MASK)

#define CSTCU_BYPLSTCU_BYP_L11_MASK              (0x800U)
#define CSTCU_BYPLSTCU_BYP_L11_SHIFT             (11U)
#define CSTCU_BYPLSTCU_BYP_L11_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L11(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L11_SHIFT)) & CSTCU_BYPLSTCU_BYP_L11_MASK)

#define CSTCU_BYPLSTCU_BYP_L12_MASK              (0x1000U)
#define CSTCU_BYPLSTCU_BYP_L12_SHIFT             (12U)
#define CSTCU_BYPLSTCU_BYP_L12_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L12(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L12_SHIFT)) & CSTCU_BYPLSTCU_BYP_L12_MASK)

#define CSTCU_BYPLSTCU_BYP_L13_MASK              (0x2000U)
#define CSTCU_BYPLSTCU_BYP_L13_SHIFT             (13U)
#define CSTCU_BYPLSTCU_BYP_L13_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L13(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L13_SHIFT)) & CSTCU_BYPLSTCU_BYP_L13_MASK)

#define CSTCU_BYPLSTCU_BYP_L14_MASK              (0x4000U)
#define CSTCU_BYPLSTCU_BYP_L14_SHIFT             (14U)
#define CSTCU_BYPLSTCU_BYP_L14_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L14(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L14_SHIFT)) & CSTCU_BYPLSTCU_BYP_L14_MASK)

#define CSTCU_BYPLSTCU_BYP_L15_MASK              (0x8000U)
#define CSTCU_BYPLSTCU_BYP_L15_SHIFT             (15U)
#define CSTCU_BYPLSTCU_BYP_L15_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L15(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L15_SHIFT)) & CSTCU_BYPLSTCU_BYP_L15_MASK)

#define CSTCU_BYPLSTCU_BYP_L16_MASK              (0x10000U)
#define CSTCU_BYPLSTCU_BYP_L16_SHIFT             (16U)
#define CSTCU_BYPLSTCU_BYP_L16_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L16(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L16_SHIFT)) & CSTCU_BYPLSTCU_BYP_L16_MASK)

#define CSTCU_BYPLSTCU_BYP_L17_MASK              (0x20000U)
#define CSTCU_BYPLSTCU_BYP_L17_SHIFT             (17U)
#define CSTCU_BYPLSTCU_BYP_L17_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L17(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L17_SHIFT)) & CSTCU_BYPLSTCU_BYP_L17_MASK)

#define CSTCU_BYPLSTCU_BYP_L18_MASK              (0x40000U)
#define CSTCU_BYPLSTCU_BYP_L18_SHIFT             (18U)
#define CSTCU_BYPLSTCU_BYP_L18_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L18(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L18_SHIFT)) & CSTCU_BYPLSTCU_BYP_L18_MASK)

#define CSTCU_BYPLSTCU_BYP_L19_MASK              (0x80000U)
#define CSTCU_BYPLSTCU_BYP_L19_SHIFT             (19U)
#define CSTCU_BYPLSTCU_BYP_L19_WIDTH             (1U)
#define CSTCU_BYPLSTCU_BYP_L19(x)                (((uint32_t)(((uint32_t)(x)) << CSTCU_BYPLSTCU_BYP_L19_SHIFT)) & CSTCU_BYPLSTCU_BYP_L19_MASK)
/*! @} */

/*! @name STAG - Stagger */
/*! @{ */

#define CSTCU_STAG_MB_DELAY_MASK                 (0xFF00U)
#define CSTCU_STAG_MB_DELAY_SHIFT                (8U)
#define CSTCU_STAG_MB_DELAY_WIDTH                (8U)
#define CSTCU_STAG_MB_DELAY(x)                   (((uint32_t)(((uint32_t)(x)) << CSTCU_STAG_MB_DELAY_SHIFT)) & CSTCU_STAG_MB_DELAY_MASK)

#define CSTCU_STAG_LB_DELAY_MASK                 (0xFF0000U)
#define CSTCU_STAG_LB_DELAY_SHIFT                (16U)
#define CSTCU_STAG_LB_DELAY_WIDTH                (8U)
#define CSTCU_STAG_LB_DELAY(x)                   (((uint32_t)(((uint32_t)(x)) << CSTCU_STAG_LB_DELAY_SHIFT)) & CSTCU_STAG_LB_DELAY_MASK)
/*! @} */

/*! @name LMBPTR - LSTCU MBIST Run Phase Scheduler Pointer */
/*! @{ */

#define CSTCU_LMBPTR_MBPTR_MASK                  (0xFFU)
#define CSTCU_LMBPTR_MBPTR_SHIFT                 (0U)
#define CSTCU_LMBPTR_MBPTR_WIDTH                 (8U)
#define CSTCU_LMBPTR_MBPTR(x)                    (((uint32_t)(((uint32_t)(x)) << CSTCU_LMBPTR_MBPTR_SHIFT)) & CSTCU_LMBPTR_MBPTR_MASK)

#define CSTCU_LMBPTR_MBCSM_MASK                  (0x100U)
#define CSTCU_LMBPTR_MBCSM_SHIFT                 (8U)
#define CSTCU_LMBPTR_MBCSM_WIDTH                 (1U)
#define CSTCU_LMBPTR_MBCSM(x)                    (((uint32_t)(((uint32_t)(x)) << CSTCU_LMBPTR_MBCSM_SHIFT)) & CSTCU_LMBPTR_MBCSM_MASK)

#define CSTCU_LMBPTR_MBEOL_MASK                  (0x80000000U)
#define CSTCU_LMBPTR_MBEOL_SHIFT                 (31U)
#define CSTCU_LMBPTR_MBEOL_WIDTH                 (1U)
#define CSTCU_LMBPTR_MBEOL(x)                    (((uint32_t)(((uint32_t)(x)) << CSTCU_LMBPTR_MBEOL_SHIFT)) & CSTCU_LMBPTR_MBEOL_MASK)
/*! @} */

/*! @name LLBPTR - LSTCU LBIST Run phase Scheduler Pointer */
/*! @{ */

#define CSTCU_LLBPTR_LBPTR_MASK                  (0xFFU)
#define CSTCU_LLBPTR_LBPTR_SHIFT                 (0U)
#define CSTCU_LLBPTR_LBPTR_WIDTH                 (8U)
#define CSTCU_LLBPTR_LBPTR(x)                    (((uint32_t)(((uint32_t)(x)) << CSTCU_LLBPTR_LBPTR_SHIFT)) & CSTCU_LLBPTR_LBPTR_MASK)

#define CSTCU_LLBPTR_LBCSM_MASK                  (0x100U)
#define CSTCU_LLBPTR_LBCSM_SHIFT                 (8U)
#define CSTCU_LLBPTR_LBCSM_WIDTH                 (1U)
#define CSTCU_LLBPTR_LBCSM(x)                    (((uint32_t)(((uint32_t)(x)) << CSTCU_LLBPTR_LBCSM_SHIFT)) & CSTCU_LLBPTR_LBCSM_MASK)

#define CSTCU_LLBPTR_LBEOL_MASK                  (0x80000000U)
#define CSTCU_LLBPTR_LBEOL_SHIFT                 (31U)
#define CSTCU_LLBPTR_LBEOL_WIDTH                 (1U)
#define CSTCU_LLBPTR_LBEOL(x)                    (((uint32_t)(((uint32_t)(x)) << CSTCU_LLBPTR_LBEOL_SHIFT)) & CSTCU_LLBPTR_LBEOL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CSTCU_Register_Masks */

/*!
 * @}
 */ /* end of group CSTCU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CSTCU_H_) */
