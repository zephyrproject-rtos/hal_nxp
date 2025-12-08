/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MRU.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MRU
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
#if !defined(S32K566_MRU_H_)  /* Check if memory map has not been already included */
#define S32K566_MRU_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MRU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRU_Peripheral_Access_Layer MRU Peripheral Access Layer
 * @{
 */

/** MRU - Size of Registers Arrays */
#define MRU_CHXCONFIG_COUNT                       6u
#define MRU_NOTIFY_COUNT                          4u

/** MRU - Register Layout Typedef */
typedef struct MRU_Struct {
  struct MRU_CHXCONFIG {                           /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG0;                           /**< Channel (x) Configuration 0, array offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG1;                           /**< Channel (x) Configuration 1, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CH_MBSTAT;                         /**< Channel (x) Mailbox Status, array offset: 0x8, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CHXCONFIG[MRU_CHXCONFIG_COUNT];
  uint8_t RESERVED_0[416];
  __I  uint32_t NOTIFY[MRU_NOTIFY_COUNT];          /**< Notification 0 Status..Notification 3 Status, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_1[15856];
  __IO uint32_t CH1_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x4000 */
  __IO uint32_t CH1_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x4004 */
  __IO uint32_t CH1_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x4008 */
  __IO uint32_t CH1_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x400C */
  uint8_t RESERVED_2[16368];
  __IO uint32_t CH2_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x8000 */
  __IO uint32_t CH2_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x8004 */
  __IO uint32_t CH2_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x8008 */
  __IO uint32_t CH2_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x800C */
  uint8_t RESERVED_3[16368];
  __IO uint32_t CH3_MB0;                           /**< Channel (x) Mailbox (n), offset: 0xC000 */
  __IO uint32_t CH3_MB1;                           /**< Channel (x) Mailbox (n), offset: 0xC004 */
  __IO uint32_t CH3_MB2;                           /**< Channel (x) Mailbox (n), offset: 0xC008 */
  __IO uint32_t CH3_MB3;                           /**< Channel (x) Mailbox (n), offset: 0xC00C */
  uint8_t RESERVED_4[16368];
  __IO uint32_t CH4_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x10000 */
  __IO uint32_t CH4_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x10004 */
  __IO uint32_t CH4_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x10008 */
  __IO uint32_t CH4_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x1000C */
  uint8_t RESERVED_5[16368];
  __IO uint32_t CH5_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x14000 */
  __IO uint32_t CH5_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x14004 */
  __IO uint32_t CH5_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x14008 */
  __IO uint32_t CH5_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x1400C */
  uint8_t RESERVED_6[16368];
  __IO uint32_t CH6_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x18000 */
  __IO uint32_t CH6_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x18004 */
  __IO uint32_t CH6_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x18008 */
  __IO uint32_t CH6_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x1800C */
} MRU_Type, *MRU_MemMapPtr;

/** Number of instances of the MRU module. */
#define MRU_INSTANCE_COUNT                       (9u)

/* MRU - Peripheral instance base addresses */
/** Peripheral LPE_MRU base address */
#define IP_LPE_MRU_BASE                          (0x4204C000u)
/** Peripheral LPE_MRU base pointer */
#define IP_LPE_MRU                               ((MRU_Type *)IP_LPE_MRU_BASE)
/** Peripheral MRU_0 base address */
#define IP_MRU_0_BASE                            (0x4045C000u)
/** Peripheral MRU_0 base pointer */
#define IP_MRU_0                                 ((MRU_Type *)IP_MRU_0_BASE)
/** Peripheral MRU_1 base address */
#define IP_MRU_1_BASE                            (0x40478000u)
/** Peripheral MRU_1 base pointer */
#define IP_MRU_1                                 ((MRU_Type *)IP_MRU_1_BASE)
/** Peripheral MRU_2 base address */
#define IP_MRU_2_BASE                            (0x40A68000u)
/** Peripheral MRU_2 base pointer */
#define IP_MRU_2                                 ((MRU_Type *)IP_MRU_2_BASE)
/** Peripheral MRU_3 base address */
#define IP_MRU_3_BASE                            (0x40A84000u)
/** Peripheral MRU_3 base pointer */
#define IP_MRU_3                                 ((MRU_Type *)IP_MRU_3_BASE)
/** Peripheral MRU_4 base address */
#define IP_MRU_4_BASE                            (0x40AA0000u)
/** Peripheral MRU_4 base pointer */
#define IP_MRU_4                                 ((MRU_Type *)IP_MRU_4_BASE)
/** Peripheral MRU_5 base address */
#define IP_MRU_5_BASE                            (0x40ABC000u)
/** Peripheral MRU_5 base pointer */
#define IP_MRU_5                                 ((MRU_Type *)IP_MRU_5_BASE)
/** Peripheral MRU_6 base address */
#define IP_MRU_6_BASE                            (0x40AD8000u)
/** Peripheral MRU_6 base pointer */
#define IP_MRU_6                                 ((MRU_Type *)IP_MRU_6_BASE)
/** Peripheral MRU_7 base address */
#define IP_MRU_7_BASE                            (0x40AF4000u)
/** Peripheral MRU_7 base pointer */
#define IP_MRU_7                                 ((MRU_Type *)IP_MRU_7_BASE)
/** Array initializer of MRU peripheral base addresses */
#define IP_MRU_BASE_ADDRS                        { IP_LPE_MRU_BASE, IP_MRU_0_BASE, IP_MRU_1_BASE, IP_MRU_2_BASE, IP_MRU_3_BASE, IP_MRU_4_BASE, IP_MRU_5_BASE, IP_MRU_6_BASE, IP_MRU_7_BASE }
/** Array initializer of MRU peripheral base pointers */
#define IP_MRU_BASE_PTRS                         { IP_LPE_MRU, IP_MRU_0, IP_MRU_1, IP_MRU_2, IP_MRU_3, IP_MRU_4, IP_MRU_5, IP_MRU_6, IP_MRU_7 }

/* ----------------------------------------------------------------------------
   -- MRU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRU_Register_Masks MRU Register Masks
 * @{
 */

/*! @name CH_CFG0 - Channel (x) Configuration 0 */
/*! @{ */

#define MRU_CH_CFG0_CHE_MASK                     (0x1U)
#define MRU_CH_CFG0_CHE_SHIFT                    (0U)
#define MRU_CH_CFG0_CHE_WIDTH                    (1U)
#define MRU_CH_CFG0_CHE(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG0_CHE_SHIFT)) & MRU_CH_CFG0_CHE_MASK)

#define MRU_CH_CFG0_CHR_MASK                     (0x2U)
#define MRU_CH_CFG0_CHR_SHIFT                    (1U)
#define MRU_CH_CFG0_CHR_WIDTH                    (1U)
#define MRU_CH_CFG0_CHR(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG0_CHR_SHIFT)) & MRU_CH_CFG0_CHR_MASK)

#define MRU_CH_CFG0_IE_MASK                      (0x4U)
#define MRU_CH_CFG0_IE_SHIFT                     (2U)
#define MRU_CH_CFG0_IE_WIDTH                     (1U)
#define MRU_CH_CFG0_IE(x)                        (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG0_IE_SHIFT)) & MRU_CH_CFG0_IE_MASK)

#define MRU_CH_CFG0_MBE0_MASK                    (0x10000U)
#define MRU_CH_CFG0_MBE0_SHIFT                   (16U)
#define MRU_CH_CFG0_MBE0_WIDTH                   (1U)
#define MRU_CH_CFG0_MBE0(x)                      (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG0_MBE0_SHIFT)) & MRU_CH_CFG0_MBE0_MASK)

#define MRU_CH_CFG0_MBE1_MASK                    (0x20000U)
#define MRU_CH_CFG0_MBE1_SHIFT                   (17U)
#define MRU_CH_CFG0_MBE1_WIDTH                   (1U)
#define MRU_CH_CFG0_MBE1(x)                      (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG0_MBE1_SHIFT)) & MRU_CH_CFG0_MBE1_MASK)

#define MRU_CH_CFG0_MBE2_MASK                    (0x40000U)
#define MRU_CH_CFG0_MBE2_SHIFT                   (18U)
#define MRU_CH_CFG0_MBE2_WIDTH                   (1U)
#define MRU_CH_CFG0_MBE2(x)                      (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG0_MBE2_SHIFT)) & MRU_CH_CFG0_MBE2_MASK)

#define MRU_CH_CFG0_MBE3_MASK                    (0x80000U)
#define MRU_CH_CFG0_MBE3_SHIFT                   (19U)
#define MRU_CH_CFG0_MBE3_WIDTH                   (1U)
#define MRU_CH_CFG0_MBE3(x)                      (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG0_MBE3_SHIFT)) & MRU_CH_CFG0_MBE3_MASK)
/*! @} */

/*! @name CH_CFG1 - Channel (x) Configuration 1 */
/*! @{ */

#define MRU_CH_CFG1_MBIC0_MASK                   (0x3U)
#define MRU_CH_CFG1_MBIC0_SHIFT                  (0U)
#define MRU_CH_CFG1_MBIC0_WIDTH                  (2U)
#define MRU_CH_CFG1_MBIC0(x)                     (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG1_MBIC0_SHIFT)) & MRU_CH_CFG1_MBIC0_MASK)

#define MRU_CH_CFG1_MBIC1_MASK                   (0xCU)
#define MRU_CH_CFG1_MBIC1_SHIFT                  (2U)
#define MRU_CH_CFG1_MBIC1_WIDTH                  (2U)
#define MRU_CH_CFG1_MBIC1(x)                     (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG1_MBIC1_SHIFT)) & MRU_CH_CFG1_MBIC1_MASK)

#define MRU_CH_CFG1_MBIC2_MASK                   (0x30U)
#define MRU_CH_CFG1_MBIC2_SHIFT                  (4U)
#define MRU_CH_CFG1_MBIC2_WIDTH                  (2U)
#define MRU_CH_CFG1_MBIC2(x)                     (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG1_MBIC2_SHIFT)) & MRU_CH_CFG1_MBIC2_MASK)

#define MRU_CH_CFG1_MBIC3_MASK                   (0xC0U)
#define MRU_CH_CFG1_MBIC3_SHIFT                  (6U)
#define MRU_CH_CFG1_MBIC3_WIDTH                  (2U)
#define MRU_CH_CFG1_MBIC3(x)                     (((uint32_t)(((uint32_t)(x)) << MRU_CH_CFG1_MBIC3_SHIFT)) & MRU_CH_CFG1_MBIC3_MASK)
/*! @} */

/*! @name CH_MBSTAT - Channel (x) Mailbox Status */
/*! @{ */

#define MRU_CH_MBSTAT_MBS0_MASK                  (0x10000U)
#define MRU_CH_MBSTAT_MBS0_SHIFT                 (16U)
#define MRU_CH_MBSTAT_MBS0_WIDTH                 (1U)
#define MRU_CH_MBSTAT_MBS0(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_CH_MBSTAT_MBS0_SHIFT)) & MRU_CH_MBSTAT_MBS0_MASK)

#define MRU_CH_MBSTAT_MBS1_MASK                  (0x20000U)
#define MRU_CH_MBSTAT_MBS1_SHIFT                 (17U)
#define MRU_CH_MBSTAT_MBS1_WIDTH                 (1U)
#define MRU_CH_MBSTAT_MBS1(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_CH_MBSTAT_MBS1_SHIFT)) & MRU_CH_MBSTAT_MBS1_MASK)

#define MRU_CH_MBSTAT_MBS2_MASK                  (0x40000U)
#define MRU_CH_MBSTAT_MBS2_SHIFT                 (18U)
#define MRU_CH_MBSTAT_MBS2_WIDTH                 (1U)
#define MRU_CH_MBSTAT_MBS2(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_CH_MBSTAT_MBS2_SHIFT)) & MRU_CH_MBSTAT_MBS2_MASK)

#define MRU_CH_MBSTAT_MBS3_MASK                  (0x80000U)
#define MRU_CH_MBSTAT_MBS3_SHIFT                 (19U)
#define MRU_CH_MBSTAT_MBS3_WIDTH                 (1U)
#define MRU_CH_MBSTAT_MBS3(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_CH_MBSTAT_MBS3_SHIFT)) & MRU_CH_MBSTAT_MBS3_MASK)
/*! @} */

/*! @name NOTIFY - Notification 0 Status..Notification 3 Status */
/*! @{ */

#define MRU_NOTIFY_CH1_IS0_MASK                  (0x1U)
#define MRU_NOTIFY_CH1_IS0_SHIFT                 (0U)
#define MRU_NOTIFY_CH1_IS0_WIDTH                 (1U)
#define MRU_NOTIFY_CH1_IS0(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH1_IS0_SHIFT)) & MRU_NOTIFY_CH1_IS0_MASK)

#define MRU_NOTIFY_CH1_IS1_MASK                  (0x1U)
#define MRU_NOTIFY_CH1_IS1_SHIFT                 (0U)
#define MRU_NOTIFY_CH1_IS1_WIDTH                 (1U)
#define MRU_NOTIFY_CH1_IS1(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH1_IS1_SHIFT)) & MRU_NOTIFY_CH1_IS1_MASK)

#define MRU_NOTIFY_CH1_IS2_MASK                  (0x1U)
#define MRU_NOTIFY_CH1_IS2_SHIFT                 (0U)
#define MRU_NOTIFY_CH1_IS2_WIDTH                 (1U)
#define MRU_NOTIFY_CH1_IS2(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH1_IS2_SHIFT)) & MRU_NOTIFY_CH1_IS2_MASK)

#define MRU_NOTIFY_CH1_IS3_MASK                  (0x1U)
#define MRU_NOTIFY_CH1_IS3_SHIFT                 (0U)
#define MRU_NOTIFY_CH1_IS3_WIDTH                 (1U)
#define MRU_NOTIFY_CH1_IS3(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH1_IS3_SHIFT)) & MRU_NOTIFY_CH1_IS3_MASK)

#define MRU_NOTIFY_CH2_IS0_MASK                  (0x2U)
#define MRU_NOTIFY_CH2_IS0_SHIFT                 (1U)
#define MRU_NOTIFY_CH2_IS0_WIDTH                 (1U)
#define MRU_NOTIFY_CH2_IS0(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH2_IS0_SHIFT)) & MRU_NOTIFY_CH2_IS0_MASK)

#define MRU_NOTIFY_CH2_IS1_MASK                  (0x2U)
#define MRU_NOTIFY_CH2_IS1_SHIFT                 (1U)
#define MRU_NOTIFY_CH2_IS1_WIDTH                 (1U)
#define MRU_NOTIFY_CH2_IS1(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH2_IS1_SHIFT)) & MRU_NOTIFY_CH2_IS1_MASK)

#define MRU_NOTIFY_CH2_IS2_MASK                  (0x2U)
#define MRU_NOTIFY_CH2_IS2_SHIFT                 (1U)
#define MRU_NOTIFY_CH2_IS2_WIDTH                 (1U)
#define MRU_NOTIFY_CH2_IS2(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH2_IS2_SHIFT)) & MRU_NOTIFY_CH2_IS2_MASK)

#define MRU_NOTIFY_CH2_IS3_MASK                  (0x2U)
#define MRU_NOTIFY_CH2_IS3_SHIFT                 (1U)
#define MRU_NOTIFY_CH2_IS3_WIDTH                 (1U)
#define MRU_NOTIFY_CH2_IS3(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH2_IS3_SHIFT)) & MRU_NOTIFY_CH2_IS3_MASK)

#define MRU_NOTIFY_CH3_IS0_MASK                  (0x4U)
#define MRU_NOTIFY_CH3_IS0_SHIFT                 (2U)
#define MRU_NOTIFY_CH3_IS0_WIDTH                 (1U)
#define MRU_NOTIFY_CH3_IS0(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH3_IS0_SHIFT)) & MRU_NOTIFY_CH3_IS0_MASK)

#define MRU_NOTIFY_CH3_IS1_MASK                  (0x4U)
#define MRU_NOTIFY_CH3_IS1_SHIFT                 (2U)
#define MRU_NOTIFY_CH3_IS1_WIDTH                 (1U)
#define MRU_NOTIFY_CH3_IS1(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH3_IS1_SHIFT)) & MRU_NOTIFY_CH3_IS1_MASK)

#define MRU_NOTIFY_CH3_IS2_MASK                  (0x4U)
#define MRU_NOTIFY_CH3_IS2_SHIFT                 (2U)
#define MRU_NOTIFY_CH3_IS2_WIDTH                 (1U)
#define MRU_NOTIFY_CH3_IS2(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH3_IS2_SHIFT)) & MRU_NOTIFY_CH3_IS2_MASK)

#define MRU_NOTIFY_CH3_IS3_MASK                  (0x4U)
#define MRU_NOTIFY_CH3_IS3_SHIFT                 (2U)
#define MRU_NOTIFY_CH3_IS3_WIDTH                 (1U)
#define MRU_NOTIFY_CH3_IS3(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH3_IS3_SHIFT)) & MRU_NOTIFY_CH3_IS3_MASK)

#define MRU_NOTIFY_CH4_IS0_MASK                  (0x8U)
#define MRU_NOTIFY_CH4_IS0_SHIFT                 (3U)
#define MRU_NOTIFY_CH4_IS0_WIDTH                 (1U)
#define MRU_NOTIFY_CH4_IS0(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH4_IS0_SHIFT)) & MRU_NOTIFY_CH4_IS0_MASK)

#define MRU_NOTIFY_CH4_IS1_MASK                  (0x8U)
#define MRU_NOTIFY_CH4_IS1_SHIFT                 (3U)
#define MRU_NOTIFY_CH4_IS1_WIDTH                 (1U)
#define MRU_NOTIFY_CH4_IS1(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH4_IS1_SHIFT)) & MRU_NOTIFY_CH4_IS1_MASK)

#define MRU_NOTIFY_CH4_IS2_MASK                  (0x8U)
#define MRU_NOTIFY_CH4_IS2_SHIFT                 (3U)
#define MRU_NOTIFY_CH4_IS2_WIDTH                 (1U)
#define MRU_NOTIFY_CH4_IS2(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH4_IS2_SHIFT)) & MRU_NOTIFY_CH4_IS2_MASK)

#define MRU_NOTIFY_CH4_IS3_MASK                  (0x8U)
#define MRU_NOTIFY_CH4_IS3_SHIFT                 (3U)
#define MRU_NOTIFY_CH4_IS3_WIDTH                 (1U)
#define MRU_NOTIFY_CH4_IS3(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH4_IS3_SHIFT)) & MRU_NOTIFY_CH4_IS3_MASK)

#define MRU_NOTIFY_CH5_IS0_MASK                  (0x10U)
#define MRU_NOTIFY_CH5_IS0_SHIFT                 (4U)
#define MRU_NOTIFY_CH5_IS0_WIDTH                 (1U)
#define MRU_NOTIFY_CH5_IS0(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH5_IS0_SHIFT)) & MRU_NOTIFY_CH5_IS0_MASK)

#define MRU_NOTIFY_CH5_IS1_MASK                  (0x10U)
#define MRU_NOTIFY_CH5_IS1_SHIFT                 (4U)
#define MRU_NOTIFY_CH5_IS1_WIDTH                 (1U)
#define MRU_NOTIFY_CH5_IS1(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH5_IS1_SHIFT)) & MRU_NOTIFY_CH5_IS1_MASK)

#define MRU_NOTIFY_CH5_IS2_MASK                  (0x10U)
#define MRU_NOTIFY_CH5_IS2_SHIFT                 (4U)
#define MRU_NOTIFY_CH5_IS2_WIDTH                 (1U)
#define MRU_NOTIFY_CH5_IS2(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH5_IS2_SHIFT)) & MRU_NOTIFY_CH5_IS2_MASK)

#define MRU_NOTIFY_CH5_IS3_MASK                  (0x10U)
#define MRU_NOTIFY_CH5_IS3_SHIFT                 (4U)
#define MRU_NOTIFY_CH5_IS3_WIDTH                 (1U)
#define MRU_NOTIFY_CH5_IS3(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH5_IS3_SHIFT)) & MRU_NOTIFY_CH5_IS3_MASK)

#define MRU_NOTIFY_CH6_IS0_MASK                  (0x20U)
#define MRU_NOTIFY_CH6_IS0_SHIFT                 (5U)
#define MRU_NOTIFY_CH6_IS0_WIDTH                 (1U)
#define MRU_NOTIFY_CH6_IS0(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH6_IS0_SHIFT)) & MRU_NOTIFY_CH6_IS0_MASK)

#define MRU_NOTIFY_CH6_IS1_MASK                  (0x20U)
#define MRU_NOTIFY_CH6_IS1_SHIFT                 (5U)
#define MRU_NOTIFY_CH6_IS1_WIDTH                 (1U)
#define MRU_NOTIFY_CH6_IS1(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH6_IS1_SHIFT)) & MRU_NOTIFY_CH6_IS1_MASK)

#define MRU_NOTIFY_CH6_IS2_MASK                  (0x20U)
#define MRU_NOTIFY_CH6_IS2_SHIFT                 (5U)
#define MRU_NOTIFY_CH6_IS2_WIDTH                 (1U)
#define MRU_NOTIFY_CH6_IS2(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH6_IS2_SHIFT)) & MRU_NOTIFY_CH6_IS2_MASK)

#define MRU_NOTIFY_CH6_IS3_MASK                  (0x20U)
#define MRU_NOTIFY_CH6_IS3_SHIFT                 (5U)
#define MRU_NOTIFY_CH6_IS3_WIDTH                 (1U)
#define MRU_NOTIFY_CH6_IS3(x)                    (((uint32_t)(((uint32_t)(x)) << MRU_NOTIFY_CH6_IS3_SHIFT)) & MRU_NOTIFY_CH6_IS3_MASK)
/*! @} */

/*! @name CH1_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH1_MB0_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH1_MB0_MBD_SHIFT                    (0U)
#define MRU_CH1_MB0_MBD_WIDTH                    (32U)
#define MRU_CH1_MB0_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH1_MB0_MBD_SHIFT)) & MRU_CH1_MB0_MBD_MASK)
/*! @} */

/*! @name CH1_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH1_MB1_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH1_MB1_MBD_SHIFT                    (0U)
#define MRU_CH1_MB1_MBD_WIDTH                    (32U)
#define MRU_CH1_MB1_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH1_MB1_MBD_SHIFT)) & MRU_CH1_MB1_MBD_MASK)
/*! @} */

/*! @name CH1_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH1_MB2_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH1_MB2_MBD_SHIFT                    (0U)
#define MRU_CH1_MB2_MBD_WIDTH                    (32U)
#define MRU_CH1_MB2_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH1_MB2_MBD_SHIFT)) & MRU_CH1_MB2_MBD_MASK)
/*! @} */

/*! @name CH1_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH1_MB3_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH1_MB3_MBD_SHIFT                    (0U)
#define MRU_CH1_MB3_MBD_WIDTH                    (32U)
#define MRU_CH1_MB3_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH1_MB3_MBD_SHIFT)) & MRU_CH1_MB3_MBD_MASK)
/*! @} */

/*! @name CH2_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH2_MB0_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH2_MB0_MBD_SHIFT                    (0U)
#define MRU_CH2_MB0_MBD_WIDTH                    (32U)
#define MRU_CH2_MB0_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH2_MB0_MBD_SHIFT)) & MRU_CH2_MB0_MBD_MASK)
/*! @} */

/*! @name CH2_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH2_MB1_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH2_MB1_MBD_SHIFT                    (0U)
#define MRU_CH2_MB1_MBD_WIDTH                    (32U)
#define MRU_CH2_MB1_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH2_MB1_MBD_SHIFT)) & MRU_CH2_MB1_MBD_MASK)
/*! @} */

/*! @name CH2_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH2_MB2_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH2_MB2_MBD_SHIFT                    (0U)
#define MRU_CH2_MB2_MBD_WIDTH                    (32U)
#define MRU_CH2_MB2_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH2_MB2_MBD_SHIFT)) & MRU_CH2_MB2_MBD_MASK)
/*! @} */

/*! @name CH2_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH2_MB3_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH2_MB3_MBD_SHIFT                    (0U)
#define MRU_CH2_MB3_MBD_WIDTH                    (32U)
#define MRU_CH2_MB3_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH2_MB3_MBD_SHIFT)) & MRU_CH2_MB3_MBD_MASK)
/*! @} */

/*! @name CH3_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH3_MB0_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH3_MB0_MBD_SHIFT                    (0U)
#define MRU_CH3_MB0_MBD_WIDTH                    (32U)
#define MRU_CH3_MB0_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH3_MB0_MBD_SHIFT)) & MRU_CH3_MB0_MBD_MASK)
/*! @} */

/*! @name CH3_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH3_MB1_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH3_MB1_MBD_SHIFT                    (0U)
#define MRU_CH3_MB1_MBD_WIDTH                    (32U)
#define MRU_CH3_MB1_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH3_MB1_MBD_SHIFT)) & MRU_CH3_MB1_MBD_MASK)
/*! @} */

/*! @name CH3_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH3_MB2_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH3_MB2_MBD_SHIFT                    (0U)
#define MRU_CH3_MB2_MBD_WIDTH                    (32U)
#define MRU_CH3_MB2_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH3_MB2_MBD_SHIFT)) & MRU_CH3_MB2_MBD_MASK)
/*! @} */

/*! @name CH3_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH3_MB3_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH3_MB3_MBD_SHIFT                    (0U)
#define MRU_CH3_MB3_MBD_WIDTH                    (32U)
#define MRU_CH3_MB3_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH3_MB3_MBD_SHIFT)) & MRU_CH3_MB3_MBD_MASK)
/*! @} */

/*! @name CH4_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH4_MB0_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH4_MB0_MBD_SHIFT                    (0U)
#define MRU_CH4_MB0_MBD_WIDTH                    (32U)
#define MRU_CH4_MB0_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH4_MB0_MBD_SHIFT)) & MRU_CH4_MB0_MBD_MASK)
/*! @} */

/*! @name CH4_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH4_MB1_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH4_MB1_MBD_SHIFT                    (0U)
#define MRU_CH4_MB1_MBD_WIDTH                    (32U)
#define MRU_CH4_MB1_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH4_MB1_MBD_SHIFT)) & MRU_CH4_MB1_MBD_MASK)
/*! @} */

/*! @name CH4_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH4_MB2_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH4_MB2_MBD_SHIFT                    (0U)
#define MRU_CH4_MB2_MBD_WIDTH                    (32U)
#define MRU_CH4_MB2_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH4_MB2_MBD_SHIFT)) & MRU_CH4_MB2_MBD_MASK)
/*! @} */

/*! @name CH4_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH4_MB3_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH4_MB3_MBD_SHIFT                    (0U)
#define MRU_CH4_MB3_MBD_WIDTH                    (32U)
#define MRU_CH4_MB3_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH4_MB3_MBD_SHIFT)) & MRU_CH4_MB3_MBD_MASK)
/*! @} */

/*! @name CH5_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH5_MB0_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH5_MB0_MBD_SHIFT                    (0U)
#define MRU_CH5_MB0_MBD_WIDTH                    (32U)
#define MRU_CH5_MB0_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH5_MB0_MBD_SHIFT)) & MRU_CH5_MB0_MBD_MASK)
/*! @} */

/*! @name CH5_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH5_MB1_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH5_MB1_MBD_SHIFT                    (0U)
#define MRU_CH5_MB1_MBD_WIDTH                    (32U)
#define MRU_CH5_MB1_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH5_MB1_MBD_SHIFT)) & MRU_CH5_MB1_MBD_MASK)
/*! @} */

/*! @name CH5_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH5_MB2_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH5_MB2_MBD_SHIFT                    (0U)
#define MRU_CH5_MB2_MBD_WIDTH                    (32U)
#define MRU_CH5_MB2_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH5_MB2_MBD_SHIFT)) & MRU_CH5_MB2_MBD_MASK)
/*! @} */

/*! @name CH5_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH5_MB3_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH5_MB3_MBD_SHIFT                    (0U)
#define MRU_CH5_MB3_MBD_WIDTH                    (32U)
#define MRU_CH5_MB3_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH5_MB3_MBD_SHIFT)) & MRU_CH5_MB3_MBD_MASK)
/*! @} */

/*! @name CH6_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH6_MB0_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH6_MB0_MBD_SHIFT                    (0U)
#define MRU_CH6_MB0_MBD_WIDTH                    (32U)
#define MRU_CH6_MB0_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH6_MB0_MBD_SHIFT)) & MRU_CH6_MB0_MBD_MASK)
/*! @} */

/*! @name CH6_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH6_MB1_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH6_MB1_MBD_SHIFT                    (0U)
#define MRU_CH6_MB1_MBD_WIDTH                    (32U)
#define MRU_CH6_MB1_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH6_MB1_MBD_SHIFT)) & MRU_CH6_MB1_MBD_MASK)
/*! @} */

/*! @name CH6_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH6_MB2_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH6_MB2_MBD_SHIFT                    (0U)
#define MRU_CH6_MB2_MBD_WIDTH                    (32U)
#define MRU_CH6_MB2_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH6_MB2_MBD_SHIFT)) & MRU_CH6_MB2_MBD_MASK)
/*! @} */

/*! @name CH6_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define MRU_CH6_MB3_MBD_MASK                     (0xFFFFFFFFU)
#define MRU_CH6_MB3_MBD_SHIFT                    (0U)
#define MRU_CH6_MB3_MBD_WIDTH                    (32U)
#define MRU_CH6_MB3_MBD(x)                       (((uint32_t)(((uint32_t)(x)) << MRU_CH6_MB3_MBD_SHIFT)) & MRU_CH6_MB3_MBD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MRU_Register_Masks */

/*!
 * @}
 */ /* end of group MRU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MRU_H_) */
