/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_CPE_MRU3.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_CPE_MRU3
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
#if !defined(S32K566_CPE_MRU3_H_)  /* Check if memory map has not been already included */
#define S32K566_CPE_MRU3_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CPE_MRU3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_MRU3_Peripheral_Access_Layer CPE_MRU3 Peripheral Access Layer
 * @{
 */

/** CPE_MRU3 - Size of Registers Arrays */
#define CPE_MRU3_CHXCONFIG_COUNT                  6u
#define CPE_MRU3_NOTIFY_COUNT                     4u

/** CPE_MRU3 - Register Layout Typedef */
typedef struct CPE_MRU3_Struct {
  struct CPE_MRU3_CHXCONFIG {                      /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG0;                           /**< Channel (x) Configuration 0, array offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG1;                           /**< Channel (x) Configuration 1, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CH_MBSTAT;                         /**< Channel (x) Mailbox Status, array offset: 0x8, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CHXCONFIG[CPE_MRU3_CHXCONFIG_COUNT];
  uint8_t RESERVED_0[416];
  __I  uint32_t NOTIFY[CPE_MRU3_NOTIFY_COUNT];     /**< Notification 0 Status..Notification 3 Status, array offset: 0x200, array step: 0x4 */
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
} CPE_MRU3_Type, *CPE_MRU3_MemMapPtr;

/** Number of instances of the CPE_MRU3 module. */
#define CPE_MRU3_INSTANCE_COUNT                  (1u)

/* CPE_MRU3 - Peripheral instance base addresses */
/** Peripheral CPE_MRU_3 base address */
#define IP_CPE_MRU_3_BASE                        (0x4111C000u)
/** Peripheral CPE_MRU_3 base pointer */
#define IP_CPE_MRU_3                             ((CPE_MRU3_Type *)IP_CPE_MRU_3_BASE)
/** Array initializer of CPE_MRU3 peripheral base addresses */
#define IP_CPE_MRU3_BASE_ADDRS                   { IP_CPE_MRU_3_BASE }
/** Array initializer of CPE_MRU3 peripheral base pointers */
#define IP_CPE_MRU3_BASE_PTRS                    { IP_CPE_MRU_3 }

/* ----------------------------------------------------------------------------
   -- CPE_MRU3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_MRU3_Register_Masks CPE_MRU3 Register Masks
 * @{
 */

/*! @name CH_CFG0 - Channel (x) Configuration 0 */
/*! @{ */

#define CPE_MRU3_CH_CFG0_CHE_MASK                (0x1U)
#define CPE_MRU3_CH_CFG0_CHE_SHIFT               (0U)
#define CPE_MRU3_CH_CFG0_CHE_WIDTH               (1U)
#define CPE_MRU3_CH_CFG0_CHE(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG0_CHE_SHIFT)) & CPE_MRU3_CH_CFG0_CHE_MASK)

#define CPE_MRU3_CH_CFG0_CHR_MASK                (0x2U)
#define CPE_MRU3_CH_CFG0_CHR_SHIFT               (1U)
#define CPE_MRU3_CH_CFG0_CHR_WIDTH               (1U)
#define CPE_MRU3_CH_CFG0_CHR(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG0_CHR_SHIFT)) & CPE_MRU3_CH_CFG0_CHR_MASK)

#define CPE_MRU3_CH_CFG0_IE_MASK                 (0x4U)
#define CPE_MRU3_CH_CFG0_IE_SHIFT                (2U)
#define CPE_MRU3_CH_CFG0_IE_WIDTH                (1U)
#define CPE_MRU3_CH_CFG0_IE(x)                   (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG0_IE_SHIFT)) & CPE_MRU3_CH_CFG0_IE_MASK)

#define CPE_MRU3_CH_CFG0_MBE0_MASK               (0x10000U)
#define CPE_MRU3_CH_CFG0_MBE0_SHIFT              (16U)
#define CPE_MRU3_CH_CFG0_MBE0_WIDTH              (1U)
#define CPE_MRU3_CH_CFG0_MBE0(x)                 (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG0_MBE0_SHIFT)) & CPE_MRU3_CH_CFG0_MBE0_MASK)

#define CPE_MRU3_CH_CFG0_MBE1_MASK               (0x20000U)
#define CPE_MRU3_CH_CFG0_MBE1_SHIFT              (17U)
#define CPE_MRU3_CH_CFG0_MBE1_WIDTH              (1U)
#define CPE_MRU3_CH_CFG0_MBE1(x)                 (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG0_MBE1_SHIFT)) & CPE_MRU3_CH_CFG0_MBE1_MASK)

#define CPE_MRU3_CH_CFG0_MBE2_MASK               (0x40000U)
#define CPE_MRU3_CH_CFG0_MBE2_SHIFT              (18U)
#define CPE_MRU3_CH_CFG0_MBE2_WIDTH              (1U)
#define CPE_MRU3_CH_CFG0_MBE2(x)                 (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG0_MBE2_SHIFT)) & CPE_MRU3_CH_CFG0_MBE2_MASK)

#define CPE_MRU3_CH_CFG0_MBE3_MASK               (0x80000U)
#define CPE_MRU3_CH_CFG0_MBE3_SHIFT              (19U)
#define CPE_MRU3_CH_CFG0_MBE3_WIDTH              (1U)
#define CPE_MRU3_CH_CFG0_MBE3(x)                 (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG0_MBE3_SHIFT)) & CPE_MRU3_CH_CFG0_MBE3_MASK)
/*! @} */

/*! @name CH_CFG1 - Channel (x) Configuration 1 */
/*! @{ */

#define CPE_MRU3_CH_CFG1_MBIC0_MASK              (0x3U)
#define CPE_MRU3_CH_CFG1_MBIC0_SHIFT             (0U)
#define CPE_MRU3_CH_CFG1_MBIC0_WIDTH             (2U)
#define CPE_MRU3_CH_CFG1_MBIC0(x)                (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG1_MBIC0_SHIFT)) & CPE_MRU3_CH_CFG1_MBIC0_MASK)

#define CPE_MRU3_CH_CFG1_MBIC1_MASK              (0xCU)
#define CPE_MRU3_CH_CFG1_MBIC1_SHIFT             (2U)
#define CPE_MRU3_CH_CFG1_MBIC1_WIDTH             (2U)
#define CPE_MRU3_CH_CFG1_MBIC1(x)                (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG1_MBIC1_SHIFT)) & CPE_MRU3_CH_CFG1_MBIC1_MASK)

#define CPE_MRU3_CH_CFG1_MBIC2_MASK              (0x30U)
#define CPE_MRU3_CH_CFG1_MBIC2_SHIFT             (4U)
#define CPE_MRU3_CH_CFG1_MBIC2_WIDTH             (2U)
#define CPE_MRU3_CH_CFG1_MBIC2(x)                (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG1_MBIC2_SHIFT)) & CPE_MRU3_CH_CFG1_MBIC2_MASK)

#define CPE_MRU3_CH_CFG1_MBIC3_MASK              (0xC0U)
#define CPE_MRU3_CH_CFG1_MBIC3_SHIFT             (6U)
#define CPE_MRU3_CH_CFG1_MBIC3_WIDTH             (2U)
#define CPE_MRU3_CH_CFG1_MBIC3(x)                (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_CFG1_MBIC3_SHIFT)) & CPE_MRU3_CH_CFG1_MBIC3_MASK)
/*! @} */

/*! @name CH_MBSTAT - Channel (x) Mailbox Status */
/*! @{ */

#define CPE_MRU3_CH_MBSTAT_MBS0_MASK             (0x10000U)
#define CPE_MRU3_CH_MBSTAT_MBS0_SHIFT            (16U)
#define CPE_MRU3_CH_MBSTAT_MBS0_WIDTH            (1U)
#define CPE_MRU3_CH_MBSTAT_MBS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_MBSTAT_MBS0_SHIFT)) & CPE_MRU3_CH_MBSTAT_MBS0_MASK)

#define CPE_MRU3_CH_MBSTAT_MBS1_MASK             (0x20000U)
#define CPE_MRU3_CH_MBSTAT_MBS1_SHIFT            (17U)
#define CPE_MRU3_CH_MBSTAT_MBS1_WIDTH            (1U)
#define CPE_MRU3_CH_MBSTAT_MBS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_MBSTAT_MBS1_SHIFT)) & CPE_MRU3_CH_MBSTAT_MBS1_MASK)

#define CPE_MRU3_CH_MBSTAT_MBS2_MASK             (0x40000U)
#define CPE_MRU3_CH_MBSTAT_MBS2_SHIFT            (18U)
#define CPE_MRU3_CH_MBSTAT_MBS2_WIDTH            (1U)
#define CPE_MRU3_CH_MBSTAT_MBS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_MBSTAT_MBS2_SHIFT)) & CPE_MRU3_CH_MBSTAT_MBS2_MASK)

#define CPE_MRU3_CH_MBSTAT_MBS3_MASK             (0x80000U)
#define CPE_MRU3_CH_MBSTAT_MBS3_SHIFT            (19U)
#define CPE_MRU3_CH_MBSTAT_MBS3_WIDTH            (1U)
#define CPE_MRU3_CH_MBSTAT_MBS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH_MBSTAT_MBS3_SHIFT)) & CPE_MRU3_CH_MBSTAT_MBS3_MASK)
/*! @} */

/*! @name NOTIFY - Notification 0 Status..Notification 3 Status */
/*! @{ */

#define CPE_MRU3_NOTIFY_CH1_IS0_MASK             (0x1U)
#define CPE_MRU3_NOTIFY_CH1_IS0_SHIFT            (0U)
#define CPE_MRU3_NOTIFY_CH1_IS0_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH1_IS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH1_IS0_SHIFT)) & CPE_MRU3_NOTIFY_CH1_IS0_MASK)

#define CPE_MRU3_NOTIFY_CH2_IS0_MASK             (0x2U)
#define CPE_MRU3_NOTIFY_CH2_IS0_SHIFT            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS0_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH2_IS0_SHIFT)) & CPE_MRU3_NOTIFY_CH2_IS0_MASK)

#define CPE_MRU3_NOTIFY_CH3_IS0_MASK             (0x4U)
#define CPE_MRU3_NOTIFY_CH3_IS0_SHIFT            (2U)
#define CPE_MRU3_NOTIFY_CH3_IS0_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH3_IS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH3_IS0_SHIFT)) & CPE_MRU3_NOTIFY_CH3_IS0_MASK)

#define CPE_MRU3_NOTIFY_CH4_IS0_MASK             (0x8U)
#define CPE_MRU3_NOTIFY_CH4_IS0_SHIFT            (3U)
#define CPE_MRU3_NOTIFY_CH4_IS0_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH4_IS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH4_IS0_SHIFT)) & CPE_MRU3_NOTIFY_CH4_IS0_MASK)

#define CPE_MRU3_NOTIFY_CH5_IS0_MASK             (0x10U)
#define CPE_MRU3_NOTIFY_CH5_IS0_SHIFT            (4U)
#define CPE_MRU3_NOTIFY_CH5_IS0_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH5_IS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH5_IS0_SHIFT)) & CPE_MRU3_NOTIFY_CH5_IS0_MASK)

#define CPE_MRU3_NOTIFY_CH6_IS0_MASK             (0x20U)
#define CPE_MRU3_NOTIFY_CH6_IS0_SHIFT            (5U)
#define CPE_MRU3_NOTIFY_CH6_IS0_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH6_IS0(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH6_IS0_SHIFT)) & CPE_MRU3_NOTIFY_CH6_IS0_MASK)

#define CPE_MRU3_NOTIFY_CH1_IS1_MASK             (0x1U)
#define CPE_MRU3_NOTIFY_CH1_IS1_SHIFT            (0U)
#define CPE_MRU3_NOTIFY_CH1_IS1_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH1_IS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH1_IS1_SHIFT)) & CPE_MRU3_NOTIFY_CH1_IS1_MASK)

#define CPE_MRU3_NOTIFY_CH2_IS1_MASK             (0x2U)
#define CPE_MRU3_NOTIFY_CH2_IS1_SHIFT            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS1_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH2_IS1_SHIFT)) & CPE_MRU3_NOTIFY_CH2_IS1_MASK)

#define CPE_MRU3_NOTIFY_CH3_IS1_MASK             (0x4U)
#define CPE_MRU3_NOTIFY_CH3_IS1_SHIFT            (2U)
#define CPE_MRU3_NOTIFY_CH3_IS1_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH3_IS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH3_IS1_SHIFT)) & CPE_MRU3_NOTIFY_CH3_IS1_MASK)

#define CPE_MRU3_NOTIFY_CH4_IS1_MASK             (0x8U)
#define CPE_MRU3_NOTIFY_CH4_IS1_SHIFT            (3U)
#define CPE_MRU3_NOTIFY_CH4_IS1_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH4_IS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH4_IS1_SHIFT)) & CPE_MRU3_NOTIFY_CH4_IS1_MASK)

#define CPE_MRU3_NOTIFY_CH5_IS1_MASK             (0x10U)
#define CPE_MRU3_NOTIFY_CH5_IS1_SHIFT            (4U)
#define CPE_MRU3_NOTIFY_CH5_IS1_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH5_IS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH5_IS1_SHIFT)) & CPE_MRU3_NOTIFY_CH5_IS1_MASK)

#define CPE_MRU3_NOTIFY_CH6_IS1_MASK             (0x20U)
#define CPE_MRU3_NOTIFY_CH6_IS1_SHIFT            (5U)
#define CPE_MRU3_NOTIFY_CH6_IS1_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH6_IS1(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH6_IS1_SHIFT)) & CPE_MRU3_NOTIFY_CH6_IS1_MASK)

#define CPE_MRU3_NOTIFY_CH1_IS2_MASK             (0x1U)
#define CPE_MRU3_NOTIFY_CH1_IS2_SHIFT            (0U)
#define CPE_MRU3_NOTIFY_CH1_IS2_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH1_IS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH1_IS2_SHIFT)) & CPE_MRU3_NOTIFY_CH1_IS2_MASK)

#define CPE_MRU3_NOTIFY_CH2_IS2_MASK             (0x2U)
#define CPE_MRU3_NOTIFY_CH2_IS2_SHIFT            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS2_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH2_IS2_SHIFT)) & CPE_MRU3_NOTIFY_CH2_IS2_MASK)

#define CPE_MRU3_NOTIFY_CH3_IS2_MASK             (0x4U)
#define CPE_MRU3_NOTIFY_CH3_IS2_SHIFT            (2U)
#define CPE_MRU3_NOTIFY_CH3_IS2_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH3_IS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH3_IS2_SHIFT)) & CPE_MRU3_NOTIFY_CH3_IS2_MASK)

#define CPE_MRU3_NOTIFY_CH4_IS2_MASK             (0x8U)
#define CPE_MRU3_NOTIFY_CH4_IS2_SHIFT            (3U)
#define CPE_MRU3_NOTIFY_CH4_IS2_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH4_IS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH4_IS2_SHIFT)) & CPE_MRU3_NOTIFY_CH4_IS2_MASK)

#define CPE_MRU3_NOTIFY_CH5_IS2_MASK             (0x10U)
#define CPE_MRU3_NOTIFY_CH5_IS2_SHIFT            (4U)
#define CPE_MRU3_NOTIFY_CH5_IS2_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH5_IS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH5_IS2_SHIFT)) & CPE_MRU3_NOTIFY_CH5_IS2_MASK)

#define CPE_MRU3_NOTIFY_CH6_IS2_MASK             (0x20U)
#define CPE_MRU3_NOTIFY_CH6_IS2_SHIFT            (5U)
#define CPE_MRU3_NOTIFY_CH6_IS2_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH6_IS2(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH6_IS2_SHIFT)) & CPE_MRU3_NOTIFY_CH6_IS2_MASK)

#define CPE_MRU3_NOTIFY_CH1_IS3_MASK             (0x1U)
#define CPE_MRU3_NOTIFY_CH1_IS3_SHIFT            (0U)
#define CPE_MRU3_NOTIFY_CH1_IS3_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH1_IS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH1_IS3_SHIFT)) & CPE_MRU3_NOTIFY_CH1_IS3_MASK)

#define CPE_MRU3_NOTIFY_CH2_IS3_MASK             (0x2U)
#define CPE_MRU3_NOTIFY_CH2_IS3_SHIFT            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS3_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH2_IS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH2_IS3_SHIFT)) & CPE_MRU3_NOTIFY_CH2_IS3_MASK)

#define CPE_MRU3_NOTIFY_CH3_IS3_MASK             (0x4U)
#define CPE_MRU3_NOTIFY_CH3_IS3_SHIFT            (2U)
#define CPE_MRU3_NOTIFY_CH3_IS3_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH3_IS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH3_IS3_SHIFT)) & CPE_MRU3_NOTIFY_CH3_IS3_MASK)

#define CPE_MRU3_NOTIFY_CH4_IS3_MASK             (0x8U)
#define CPE_MRU3_NOTIFY_CH4_IS3_SHIFT            (3U)
#define CPE_MRU3_NOTIFY_CH4_IS3_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH4_IS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH4_IS3_SHIFT)) & CPE_MRU3_NOTIFY_CH4_IS3_MASK)

#define CPE_MRU3_NOTIFY_CH5_IS3_MASK             (0x10U)
#define CPE_MRU3_NOTIFY_CH5_IS3_SHIFT            (4U)
#define CPE_MRU3_NOTIFY_CH5_IS3_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH5_IS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH5_IS3_SHIFT)) & CPE_MRU3_NOTIFY_CH5_IS3_MASK)

#define CPE_MRU3_NOTIFY_CH6_IS3_MASK             (0x20U)
#define CPE_MRU3_NOTIFY_CH6_IS3_SHIFT            (5U)
#define CPE_MRU3_NOTIFY_CH6_IS3_WIDTH            (1U)
#define CPE_MRU3_NOTIFY_CH6_IS3(x)               (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_NOTIFY_CH6_IS3_SHIFT)) & CPE_MRU3_NOTIFY_CH6_IS3_MASK)
/*! @} */

/*! @name CH1_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH1_MB0_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH1_MB0_MBD_SHIFT               (0U)
#define CPE_MRU3_CH1_MB0_MBD_WIDTH               (32U)
#define CPE_MRU3_CH1_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH1_MB0_MBD_SHIFT)) & CPE_MRU3_CH1_MB0_MBD_MASK)
/*! @} */

/*! @name CH1_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH1_MB1_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH1_MB1_MBD_SHIFT               (0U)
#define CPE_MRU3_CH1_MB1_MBD_WIDTH               (32U)
#define CPE_MRU3_CH1_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH1_MB1_MBD_SHIFT)) & CPE_MRU3_CH1_MB1_MBD_MASK)
/*! @} */

/*! @name CH1_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH1_MB2_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH1_MB2_MBD_SHIFT               (0U)
#define CPE_MRU3_CH1_MB2_MBD_WIDTH               (32U)
#define CPE_MRU3_CH1_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH1_MB2_MBD_SHIFT)) & CPE_MRU3_CH1_MB2_MBD_MASK)
/*! @} */

/*! @name CH1_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH1_MB3_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH1_MB3_MBD_SHIFT               (0U)
#define CPE_MRU3_CH1_MB3_MBD_WIDTH               (32U)
#define CPE_MRU3_CH1_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH1_MB3_MBD_SHIFT)) & CPE_MRU3_CH1_MB3_MBD_MASK)
/*! @} */

/*! @name CH2_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH2_MB0_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH2_MB0_MBD_SHIFT               (0U)
#define CPE_MRU3_CH2_MB0_MBD_WIDTH               (32U)
#define CPE_MRU3_CH2_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH2_MB0_MBD_SHIFT)) & CPE_MRU3_CH2_MB0_MBD_MASK)
/*! @} */

/*! @name CH2_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH2_MB1_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH2_MB1_MBD_SHIFT               (0U)
#define CPE_MRU3_CH2_MB1_MBD_WIDTH               (32U)
#define CPE_MRU3_CH2_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH2_MB1_MBD_SHIFT)) & CPE_MRU3_CH2_MB1_MBD_MASK)
/*! @} */

/*! @name CH2_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH2_MB2_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH2_MB2_MBD_SHIFT               (0U)
#define CPE_MRU3_CH2_MB2_MBD_WIDTH               (32U)
#define CPE_MRU3_CH2_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH2_MB2_MBD_SHIFT)) & CPE_MRU3_CH2_MB2_MBD_MASK)
/*! @} */

/*! @name CH2_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH2_MB3_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH2_MB3_MBD_SHIFT               (0U)
#define CPE_MRU3_CH2_MB3_MBD_WIDTH               (32U)
#define CPE_MRU3_CH2_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH2_MB3_MBD_SHIFT)) & CPE_MRU3_CH2_MB3_MBD_MASK)
/*! @} */

/*! @name CH3_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH3_MB0_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH3_MB0_MBD_SHIFT               (0U)
#define CPE_MRU3_CH3_MB0_MBD_WIDTH               (32U)
#define CPE_MRU3_CH3_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH3_MB0_MBD_SHIFT)) & CPE_MRU3_CH3_MB0_MBD_MASK)
/*! @} */

/*! @name CH3_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH3_MB1_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH3_MB1_MBD_SHIFT               (0U)
#define CPE_MRU3_CH3_MB1_MBD_WIDTH               (32U)
#define CPE_MRU3_CH3_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH3_MB1_MBD_SHIFT)) & CPE_MRU3_CH3_MB1_MBD_MASK)
/*! @} */

/*! @name CH3_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH3_MB2_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH3_MB2_MBD_SHIFT               (0U)
#define CPE_MRU3_CH3_MB2_MBD_WIDTH               (32U)
#define CPE_MRU3_CH3_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH3_MB2_MBD_SHIFT)) & CPE_MRU3_CH3_MB2_MBD_MASK)
/*! @} */

/*! @name CH3_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH3_MB3_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH3_MB3_MBD_SHIFT               (0U)
#define CPE_MRU3_CH3_MB3_MBD_WIDTH               (32U)
#define CPE_MRU3_CH3_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH3_MB3_MBD_SHIFT)) & CPE_MRU3_CH3_MB3_MBD_MASK)
/*! @} */

/*! @name CH4_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH4_MB0_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH4_MB0_MBD_SHIFT               (0U)
#define CPE_MRU3_CH4_MB0_MBD_WIDTH               (32U)
#define CPE_MRU3_CH4_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH4_MB0_MBD_SHIFT)) & CPE_MRU3_CH4_MB0_MBD_MASK)
/*! @} */

/*! @name CH4_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH4_MB1_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH4_MB1_MBD_SHIFT               (0U)
#define CPE_MRU3_CH4_MB1_MBD_WIDTH               (32U)
#define CPE_MRU3_CH4_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH4_MB1_MBD_SHIFT)) & CPE_MRU3_CH4_MB1_MBD_MASK)
/*! @} */

/*! @name CH4_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH4_MB2_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH4_MB2_MBD_SHIFT               (0U)
#define CPE_MRU3_CH4_MB2_MBD_WIDTH               (32U)
#define CPE_MRU3_CH4_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH4_MB2_MBD_SHIFT)) & CPE_MRU3_CH4_MB2_MBD_MASK)
/*! @} */

/*! @name CH4_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH4_MB3_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH4_MB3_MBD_SHIFT               (0U)
#define CPE_MRU3_CH4_MB3_MBD_WIDTH               (32U)
#define CPE_MRU3_CH4_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH4_MB3_MBD_SHIFT)) & CPE_MRU3_CH4_MB3_MBD_MASK)
/*! @} */

/*! @name CH5_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH5_MB0_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH5_MB0_MBD_SHIFT               (0U)
#define CPE_MRU3_CH5_MB0_MBD_WIDTH               (32U)
#define CPE_MRU3_CH5_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH5_MB0_MBD_SHIFT)) & CPE_MRU3_CH5_MB0_MBD_MASK)
/*! @} */

/*! @name CH5_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH5_MB1_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH5_MB1_MBD_SHIFT               (0U)
#define CPE_MRU3_CH5_MB1_MBD_WIDTH               (32U)
#define CPE_MRU3_CH5_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH5_MB1_MBD_SHIFT)) & CPE_MRU3_CH5_MB1_MBD_MASK)
/*! @} */

/*! @name CH5_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH5_MB2_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH5_MB2_MBD_SHIFT               (0U)
#define CPE_MRU3_CH5_MB2_MBD_WIDTH               (32U)
#define CPE_MRU3_CH5_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH5_MB2_MBD_SHIFT)) & CPE_MRU3_CH5_MB2_MBD_MASK)
/*! @} */

/*! @name CH5_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH5_MB3_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH5_MB3_MBD_SHIFT               (0U)
#define CPE_MRU3_CH5_MB3_MBD_WIDTH               (32U)
#define CPE_MRU3_CH5_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH5_MB3_MBD_SHIFT)) & CPE_MRU3_CH5_MB3_MBD_MASK)
/*! @} */

/*! @name CH6_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH6_MB0_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH6_MB0_MBD_SHIFT               (0U)
#define CPE_MRU3_CH6_MB0_MBD_WIDTH               (32U)
#define CPE_MRU3_CH6_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH6_MB0_MBD_SHIFT)) & CPE_MRU3_CH6_MB0_MBD_MASK)
/*! @} */

/*! @name CH6_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH6_MB1_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH6_MB1_MBD_SHIFT               (0U)
#define CPE_MRU3_CH6_MB1_MBD_WIDTH               (32U)
#define CPE_MRU3_CH6_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH6_MB1_MBD_SHIFT)) & CPE_MRU3_CH6_MB1_MBD_MASK)
/*! @} */

/*! @name CH6_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH6_MB2_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH6_MB2_MBD_SHIFT               (0U)
#define CPE_MRU3_CH6_MB2_MBD_WIDTH               (32U)
#define CPE_MRU3_CH6_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH6_MB2_MBD_SHIFT)) & CPE_MRU3_CH6_MB2_MBD_MASK)
/*! @} */

/*! @name CH6_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CPE_MRU3_CH6_MB3_MBD_MASK                (0xFFFFFFFFU)
#define CPE_MRU3_CH6_MB3_MBD_SHIFT               (0U)
#define CPE_MRU3_CH6_MB3_MBD_WIDTH               (32U)
#define CPE_MRU3_CH6_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << CPE_MRU3_CH6_MB3_MBD_SHIFT)) & CPE_MRU3_CH6_MB3_MBD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CPE_MRU3_Register_Masks */

/*!
 * @}
 */ /* end of group CPE_MRU3_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_CPE_MRU3_H_) */
