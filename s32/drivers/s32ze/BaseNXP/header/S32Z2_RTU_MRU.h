/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_RTU_MRU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_RTU_MRU
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
#if !defined(S32Z2_RTU_MRU_H_)  /* Check if memory map has not been already included */
#define S32Z2_RTU_MRU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- RTU_MRU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_MRU_Peripheral_Access_Layer RTU_MRU Peripheral Access Layer
 * @{
 */

/** RTU_MRU - Size of Registers Arrays */
#define RTU_MRU_CHXCONFIG_COUNT                   12u
#define RTU_MRU_NOTIFY_COUNT                      2u

/** RTU_MRU - Register Layout Typedef */
typedef struct {
  struct RTU_MRU_CHXCONFIG {                       /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG0;                           /**< Channel (x) Configuration 0, array offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG1;                           /**< Channel (x) Configuration 1, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CH_MBSTAT;                         /**< Channel (x) Mailbox Status, array offset: 0x8, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CHXCONFIG[RTU_MRU_CHXCONFIG_COUNT];
  uint8_t RESERVED_0[320];
  __I  uint32_t NOTIFY[RTU_MRU_NOTIFY_COUNT];      /**< Notification 0 Status..Notification 1 Status, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_1[3576];
  __IO uint32_t CH1_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x1000 */
  __IO uint32_t CH1_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x1004 */
  uint8_t RESERVED_2[4088];
  __IO uint32_t CH2_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x2000 */
  __IO uint32_t CH2_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x2004 */
  uint8_t RESERVED_3[4088];
  __IO uint32_t CH3_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x3000 */
  __IO uint32_t CH3_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x3004 */
  uint8_t RESERVED_4[4088];
  __IO uint32_t CH4_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x4000 */
  __IO uint32_t CH4_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x4004 */
  uint8_t RESERVED_5[4088];
  __IO uint32_t CH5_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x5000 */
  __IO uint32_t CH5_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x5004 */
  uint8_t RESERVED_6[4088];
  __IO uint32_t CH6_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x6000 */
  __IO uint32_t CH6_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x6004 */
  uint8_t RESERVED_7[4088];
  __IO uint32_t CH7_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x7000 */
  __IO uint32_t CH7_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x7004 */
  uint8_t RESERVED_8[4088];
  __IO uint32_t CH8_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x8000 */
  __IO uint32_t CH8_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x8004 */
  __IO uint32_t CH8_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x8008 */
  __IO uint32_t CH8_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x800C */
  __IO uint32_t CH8_MB4;                           /**< Channel (x) Mailbox (n), offset: 0x8010 */
  __IO uint32_t CH8_MB5;                           /**< Channel (x) Mailbox (n), offset: 0x8014 */
  __IO uint32_t CH8_MB6;                           /**< Channel (x) Mailbox (n), offset: 0x8018 */
  __IO uint32_t CH8_MB7;                           /**< Channel (x) Mailbox (n), offset: 0x801C */
  uint8_t RESERVED_9[4064];
  __IO uint32_t CH9_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x9000 */
  __IO uint32_t CH9_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x9004 */
  __IO uint32_t CH9_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x9008 */
  __IO uint32_t CH9_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x900C */
  uint8_t RESERVED_10[4080];
  __IO uint32_t CH10_MB0;                          /**< Channel (x) Mailbox (n), offset: 0xA000 */
  __IO uint32_t CH10_MB1;                          /**< Channel (x) Mailbox (n), offset: 0xA004 */
  __IO uint32_t CH10_MB2;                          /**< Channel (x) Mailbox (n), offset: 0xA008 */
  __IO uint32_t CH10_MB3;                          /**< Channel (x) Mailbox (n), offset: 0xA00C */
  uint8_t RESERVED_11[4080];
  __IO uint32_t CH11_MB0;                          /**< Channel (x) Mailbox (n), offset: 0xB000 */
  __IO uint32_t CH11_MB1;                          /**< Channel (x) Mailbox (n), offset: 0xB004 */
  __IO uint32_t CH11_MB2;                          /**< Channel (x) Mailbox (n), offset: 0xB008 */
  __IO uint32_t CH11_MB3;                          /**< Channel (x) Mailbox (n), offset: 0xB00C */
  uint8_t RESERVED_12[4080];
  __IO uint32_t CH12_MB0;                          /**< Channel (x) Mailbox (n), offset: 0xC000 */
  __IO uint32_t CH12_MB1;                          /**< Channel (x) Mailbox (n), offset: 0xC004 */
  __IO uint32_t CH12_MB2;                          /**< Channel (x) Mailbox (n), offset: 0xC008 */
  __IO uint32_t CH12_MB3;                          /**< Channel (x) Mailbox (n), offset: 0xC00C */
} RTU_MRU_Type, *RTU_MRU_MemMapPtr;

/** Number of instances of the RTU_MRU module. */
#define RTU_MRU_INSTANCE_COUNT                   (8)

/* RTU_MRU - Peripheral instance base addresses */
/** Peripheral RTU0__MRU_0 base address */
#define IP_RTU0__MRU_0_BASE                      (0x76070000u)
/** Peripheral RTU0__MRU_0 base pointer */
#define IP_RTU0__MRU_0                           ((RTU_MRU_Type *)IP_RTU0__MRU_0_BASE)
/** Peripheral RTU0__MRU_1 base address */
#define IP_RTU0__MRU_1_BASE                      (0x76090000u)
/** Peripheral RTU0__MRU_1 base pointer */
#define IP_RTU0__MRU_1                           ((RTU_MRU_Type *)IP_RTU0__MRU_1_BASE)
/** Peripheral RTU0__MRU_2 base address */
#define IP_RTU0__MRU_2_BASE                      (0x76270000u)
/** Peripheral RTU0__MRU_2 base pointer */
#define IP_RTU0__MRU_2                           ((RTU_MRU_Type *)IP_RTU0__MRU_2_BASE)
/** Peripheral RTU0__MRU_3 base address */
#define IP_RTU0__MRU_3_BASE                      (0x76290000u)
/** Peripheral RTU0__MRU_3 base pointer */
#define IP_RTU0__MRU_3                           ((RTU_MRU_Type *)IP_RTU0__MRU_3_BASE)
/** Peripheral RTU1__MRU_0 base address */
#define IP_RTU1__MRU_0_BASE                      (0x76870000u)
/** Peripheral RTU1__MRU_0 base pointer */
#define IP_RTU1__MRU_0                           ((RTU_MRU_Type *)IP_RTU1__MRU_0_BASE)
/** Peripheral RTU1__MRU_1 base address */
#define IP_RTU1__MRU_1_BASE                      (0x76890000u)
/** Peripheral RTU1__MRU_1 base pointer */
#define IP_RTU1__MRU_1                           ((RTU_MRU_Type *)IP_RTU1__MRU_1_BASE)
/** Peripheral RTU1__MRU_2 base address */
#define IP_RTU1__MRU_2_BASE                      (0x76A70000u)
/** Peripheral RTU1__MRU_2 base pointer */
#define IP_RTU1__MRU_2                           ((RTU_MRU_Type *)IP_RTU1__MRU_2_BASE)
/** Peripheral RTU1__MRU_3 base address */
#define IP_RTU1__MRU_3_BASE                      (0x76A90000u)
/** Peripheral RTU1__MRU_3 base pointer */
#define IP_RTU1__MRU_3                           ((RTU_MRU_Type *)IP_RTU1__MRU_3_BASE)
/** Array initializer of RTU_MRU peripheral base addresses */
#define IP_RTU_MRU_BASE_ADDRS                    { IP_RTU0__MRU_0_BASE, IP_RTU0__MRU_1_BASE, IP_RTU0__MRU_2_BASE, IP_RTU0__MRU_3_BASE, IP_RTU1__MRU_0_BASE, IP_RTU1__MRU_1_BASE, IP_RTU1__MRU_2_BASE, IP_RTU1__MRU_3_BASE }
/** Array initializer of RTU_MRU peripheral base pointers */
#define IP_RTU_MRU_BASE_PTRS                     { IP_RTU0__MRU_0, IP_RTU0__MRU_1, IP_RTU0__MRU_2, IP_RTU0__MRU_3, IP_RTU1__MRU_0, IP_RTU1__MRU_1, IP_RTU1__MRU_2, IP_RTU1__MRU_3 }

/* ----------------------------------------------------------------------------
   -- RTU_MRU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_MRU_Register_Masks RTU_MRU Register Masks
 * @{
 */

/*! @name CH_CFG0 - Channel (x) Configuration 0 */
/*! @{ */

#define RTU_MRU_CH_CFG0_CHE_MASK                 (0x1U)
#define RTU_MRU_CH_CFG0_CHE_SHIFT                (0U)
#define RTU_MRU_CH_CFG0_CHE_WIDTH                (1U)
#define RTU_MRU_CH_CFG0_CHE(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_CHE_SHIFT)) & RTU_MRU_CH_CFG0_CHE_MASK)

#define RTU_MRU_CH_CFG0_CHR_MASK                 (0x2U)
#define RTU_MRU_CH_CFG0_CHR_SHIFT                (1U)
#define RTU_MRU_CH_CFG0_CHR_WIDTH                (1U)
#define RTU_MRU_CH_CFG0_CHR(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_CHR_SHIFT)) & RTU_MRU_CH_CFG0_CHR_MASK)

#define RTU_MRU_CH_CFG0_IE_MASK                  (0x4U)
#define RTU_MRU_CH_CFG0_IE_SHIFT                 (2U)
#define RTU_MRU_CH_CFG0_IE_WIDTH                 (1U)
#define RTU_MRU_CH_CFG0_IE(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_IE_SHIFT)) & RTU_MRU_CH_CFG0_IE_MASK)

#define RTU_MRU_CH_CFG0_MBE0_MASK                (0x10000U)
#define RTU_MRU_CH_CFG0_MBE0_SHIFT               (16U)
#define RTU_MRU_CH_CFG0_MBE0_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE0(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE0_SHIFT)) & RTU_MRU_CH_CFG0_MBE0_MASK)

#define RTU_MRU_CH_CFG0_MBE1_MASK                (0x20000U)
#define RTU_MRU_CH_CFG0_MBE1_SHIFT               (17U)
#define RTU_MRU_CH_CFG0_MBE1_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE1(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE1_SHIFT)) & RTU_MRU_CH_CFG0_MBE1_MASK)

#define RTU_MRU_CH_CFG0_MBE2_MASK                (0x40000U)
#define RTU_MRU_CH_CFG0_MBE2_SHIFT               (18U)
#define RTU_MRU_CH_CFG0_MBE2_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE2(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE2_SHIFT)) & RTU_MRU_CH_CFG0_MBE2_MASK)

#define RTU_MRU_CH_CFG0_MBE3_MASK                (0x80000U)
#define RTU_MRU_CH_CFG0_MBE3_SHIFT               (19U)
#define RTU_MRU_CH_CFG0_MBE3_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE3(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE3_SHIFT)) & RTU_MRU_CH_CFG0_MBE3_MASK)

#define RTU_MRU_CH_CFG0_MBE4_MASK                (0x100000U)
#define RTU_MRU_CH_CFG0_MBE4_SHIFT               (20U)
#define RTU_MRU_CH_CFG0_MBE4_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE4(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE4_SHIFT)) & RTU_MRU_CH_CFG0_MBE4_MASK)

#define RTU_MRU_CH_CFG0_MBE5_MASK                (0x200000U)
#define RTU_MRU_CH_CFG0_MBE5_SHIFT               (21U)
#define RTU_MRU_CH_CFG0_MBE5_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE5(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE5_SHIFT)) & RTU_MRU_CH_CFG0_MBE5_MASK)

#define RTU_MRU_CH_CFG0_MBE6_MASK                (0x400000U)
#define RTU_MRU_CH_CFG0_MBE6_SHIFT               (22U)
#define RTU_MRU_CH_CFG0_MBE6_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE6(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE6_SHIFT)) & RTU_MRU_CH_CFG0_MBE6_MASK)

#define RTU_MRU_CH_CFG0_MBE7_MASK                (0x800000U)
#define RTU_MRU_CH_CFG0_MBE7_SHIFT               (23U)
#define RTU_MRU_CH_CFG0_MBE7_WIDTH               (1U)
#define RTU_MRU_CH_CFG0_MBE7(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG0_MBE7_SHIFT)) & RTU_MRU_CH_CFG0_MBE7_MASK)
/*! @} */

/*! @name CH_CFG1 - Channel (x) Configuration 1 */
/*! @{ */

#define RTU_MRU_CH_CFG1_MBIC0_MASK               (0x10000U)
#define RTU_MRU_CH_CFG1_MBIC0_SHIFT              (16U)
#define RTU_MRU_CH_CFG1_MBIC0_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC0(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC0_SHIFT)) & RTU_MRU_CH_CFG1_MBIC0_MASK)

#define RTU_MRU_CH_CFG1_MBIC1_MASK               (0x20000U)
#define RTU_MRU_CH_CFG1_MBIC1_SHIFT              (17U)
#define RTU_MRU_CH_CFG1_MBIC1_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC1(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC1_SHIFT)) & RTU_MRU_CH_CFG1_MBIC1_MASK)

#define RTU_MRU_CH_CFG1_MBIC2_MASK               (0x40000U)
#define RTU_MRU_CH_CFG1_MBIC2_SHIFT              (18U)
#define RTU_MRU_CH_CFG1_MBIC2_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC2(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC2_SHIFT)) & RTU_MRU_CH_CFG1_MBIC2_MASK)

#define RTU_MRU_CH_CFG1_MBIC3_MASK               (0x80000U)
#define RTU_MRU_CH_CFG1_MBIC3_SHIFT              (19U)
#define RTU_MRU_CH_CFG1_MBIC3_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC3(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC3_SHIFT)) & RTU_MRU_CH_CFG1_MBIC3_MASK)

#define RTU_MRU_CH_CFG1_MBIC4_MASK               (0x100000U)
#define RTU_MRU_CH_CFG1_MBIC4_SHIFT              (20U)
#define RTU_MRU_CH_CFG1_MBIC4_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC4(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC4_SHIFT)) & RTU_MRU_CH_CFG1_MBIC4_MASK)

#define RTU_MRU_CH_CFG1_MBIC5_MASK               (0x200000U)
#define RTU_MRU_CH_CFG1_MBIC5_SHIFT              (21U)
#define RTU_MRU_CH_CFG1_MBIC5_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC5(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC5_SHIFT)) & RTU_MRU_CH_CFG1_MBIC5_MASK)

#define RTU_MRU_CH_CFG1_MBIC6_MASK               (0x400000U)
#define RTU_MRU_CH_CFG1_MBIC6_SHIFT              (22U)
#define RTU_MRU_CH_CFG1_MBIC6_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC6(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC6_SHIFT)) & RTU_MRU_CH_CFG1_MBIC6_MASK)

#define RTU_MRU_CH_CFG1_MBIC7_MASK               (0x800000U)
#define RTU_MRU_CH_CFG1_MBIC7_SHIFT              (23U)
#define RTU_MRU_CH_CFG1_MBIC7_WIDTH              (1U)
#define RTU_MRU_CH_CFG1_MBIC7(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_CFG1_MBIC7_SHIFT)) & RTU_MRU_CH_CFG1_MBIC7_MASK)
/*! @} */

/*! @name CH_MBSTAT - Channel (x) Mailbox Status */
/*! @{ */

#define RTU_MRU_CH_MBSTAT_MBS0_MASK              (0x10000U)
#define RTU_MRU_CH_MBSTAT_MBS0_SHIFT             (16U)
#define RTU_MRU_CH_MBSTAT_MBS0_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS0_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS0_MASK)

#define RTU_MRU_CH_MBSTAT_MBS1_MASK              (0x20000U)
#define RTU_MRU_CH_MBSTAT_MBS1_SHIFT             (17U)
#define RTU_MRU_CH_MBSTAT_MBS1_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS1_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS1_MASK)

#define RTU_MRU_CH_MBSTAT_MBS2_MASK              (0x40000U)
#define RTU_MRU_CH_MBSTAT_MBS2_SHIFT             (18U)
#define RTU_MRU_CH_MBSTAT_MBS2_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS2(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS2_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS2_MASK)

#define RTU_MRU_CH_MBSTAT_MBS3_MASK              (0x80000U)
#define RTU_MRU_CH_MBSTAT_MBS3_SHIFT             (19U)
#define RTU_MRU_CH_MBSTAT_MBS3_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS3(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS3_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS3_MASK)

#define RTU_MRU_CH_MBSTAT_MBS4_MASK              (0x100000U)
#define RTU_MRU_CH_MBSTAT_MBS4_SHIFT             (20U)
#define RTU_MRU_CH_MBSTAT_MBS4_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS4(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS4_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS4_MASK)

#define RTU_MRU_CH_MBSTAT_MBS5_MASK              (0x200000U)
#define RTU_MRU_CH_MBSTAT_MBS5_SHIFT             (21U)
#define RTU_MRU_CH_MBSTAT_MBS5_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS5(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS5_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS5_MASK)

#define RTU_MRU_CH_MBSTAT_MBS6_MASK              (0x400000U)
#define RTU_MRU_CH_MBSTAT_MBS6_SHIFT             (22U)
#define RTU_MRU_CH_MBSTAT_MBS6_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS6(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS6_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS6_MASK)

#define RTU_MRU_CH_MBSTAT_MBS7_MASK              (0x800000U)
#define RTU_MRU_CH_MBSTAT_MBS7_SHIFT             (23U)
#define RTU_MRU_CH_MBSTAT_MBS7_WIDTH             (1U)
#define RTU_MRU_CH_MBSTAT_MBS7(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH_MBSTAT_MBS7_SHIFT)) & RTU_MRU_CH_MBSTAT_MBS7_MASK)
/*! @} */

/*! @name NOTIFY - Notification 0 Status..Notification 1 Status */
/*! @{ */

#define RTU_MRU_NOTIFY_CH1_IS0_MASK              (0x1U)
#define RTU_MRU_NOTIFY_CH1_IS0_SHIFT             (0U)
#define RTU_MRU_NOTIFY_CH1_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH1_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH1_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH1_IS0_MASK)

#define RTU_MRU_NOTIFY_CH1_IS1_MASK              (0x1U)
#define RTU_MRU_NOTIFY_CH1_IS1_SHIFT             (0U)
#define RTU_MRU_NOTIFY_CH1_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH1_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH1_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH1_IS1_MASK)

#define RTU_MRU_NOTIFY_CH2_IS0_MASK              (0x2U)
#define RTU_MRU_NOTIFY_CH2_IS0_SHIFT             (1U)
#define RTU_MRU_NOTIFY_CH2_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH2_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH2_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH2_IS0_MASK)

#define RTU_MRU_NOTIFY_CH2_IS1_MASK              (0x2U)
#define RTU_MRU_NOTIFY_CH2_IS1_SHIFT             (1U)
#define RTU_MRU_NOTIFY_CH2_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH2_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH2_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH2_IS1_MASK)

#define RTU_MRU_NOTIFY_CH3_IS0_MASK              (0x4U)
#define RTU_MRU_NOTIFY_CH3_IS0_SHIFT             (2U)
#define RTU_MRU_NOTIFY_CH3_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH3_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH3_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH3_IS0_MASK)

#define RTU_MRU_NOTIFY_CH3_IS1_MASK              (0x4U)
#define RTU_MRU_NOTIFY_CH3_IS1_SHIFT             (2U)
#define RTU_MRU_NOTIFY_CH3_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH3_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH3_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH3_IS1_MASK)

#define RTU_MRU_NOTIFY_CH4_IS0_MASK              (0x8U)
#define RTU_MRU_NOTIFY_CH4_IS0_SHIFT             (3U)
#define RTU_MRU_NOTIFY_CH4_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH4_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH4_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH4_IS0_MASK)

#define RTU_MRU_NOTIFY_CH4_IS1_MASK              (0x8U)
#define RTU_MRU_NOTIFY_CH4_IS1_SHIFT             (3U)
#define RTU_MRU_NOTIFY_CH4_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH4_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH4_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH4_IS1_MASK)

#define RTU_MRU_NOTIFY_CH5_IS0_MASK              (0x10U)
#define RTU_MRU_NOTIFY_CH5_IS0_SHIFT             (4U)
#define RTU_MRU_NOTIFY_CH5_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH5_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH5_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH5_IS0_MASK)

#define RTU_MRU_NOTIFY_CH5_IS1_MASK              (0x10U)
#define RTU_MRU_NOTIFY_CH5_IS1_SHIFT             (4U)
#define RTU_MRU_NOTIFY_CH5_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH5_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH5_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH5_IS1_MASK)

#define RTU_MRU_NOTIFY_CH6_IS0_MASK              (0x20U)
#define RTU_MRU_NOTIFY_CH6_IS0_SHIFT             (5U)
#define RTU_MRU_NOTIFY_CH6_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH6_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH6_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH6_IS0_MASK)

#define RTU_MRU_NOTIFY_CH6_IS1_MASK              (0x20U)
#define RTU_MRU_NOTIFY_CH6_IS1_SHIFT             (5U)
#define RTU_MRU_NOTIFY_CH6_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH6_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH6_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH6_IS1_MASK)

#define RTU_MRU_NOTIFY_CH7_IS0_MASK              (0x40U)
#define RTU_MRU_NOTIFY_CH7_IS0_SHIFT             (6U)
#define RTU_MRU_NOTIFY_CH7_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH7_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH7_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH7_IS0_MASK)

#define RTU_MRU_NOTIFY_CH7_IS1_MASK              (0x40U)
#define RTU_MRU_NOTIFY_CH7_IS1_SHIFT             (6U)
#define RTU_MRU_NOTIFY_CH7_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH7_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH7_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH7_IS1_MASK)

#define RTU_MRU_NOTIFY_CH8_IS0_MASK              (0x80U)
#define RTU_MRU_NOTIFY_CH8_IS0_SHIFT             (7U)
#define RTU_MRU_NOTIFY_CH8_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH8_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH8_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH8_IS0_MASK)

#define RTU_MRU_NOTIFY_CH8_IS1_MASK              (0x80U)
#define RTU_MRU_NOTIFY_CH8_IS1_SHIFT             (7U)
#define RTU_MRU_NOTIFY_CH8_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH8_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH8_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH8_IS1_MASK)

#define RTU_MRU_NOTIFY_CH9_IS0_MASK              (0x100U)
#define RTU_MRU_NOTIFY_CH9_IS0_SHIFT             (8U)
#define RTU_MRU_NOTIFY_CH9_IS0_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH9_IS0(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH9_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH9_IS0_MASK)

#define RTU_MRU_NOTIFY_CH9_IS1_MASK              (0x100U)
#define RTU_MRU_NOTIFY_CH9_IS1_SHIFT             (8U)
#define RTU_MRU_NOTIFY_CH9_IS1_WIDTH             (1U)
#define RTU_MRU_NOTIFY_CH9_IS1(x)                (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH9_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH9_IS1_MASK)

#define RTU_MRU_NOTIFY_CH10_IS0_MASK             (0x200U)
#define RTU_MRU_NOTIFY_CH10_IS0_SHIFT            (9U)
#define RTU_MRU_NOTIFY_CH10_IS0_WIDTH            (1U)
#define RTU_MRU_NOTIFY_CH10_IS0(x)               (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH10_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH10_IS0_MASK)

#define RTU_MRU_NOTIFY_CH10_IS1_MASK             (0x200U)
#define RTU_MRU_NOTIFY_CH10_IS1_SHIFT            (9U)
#define RTU_MRU_NOTIFY_CH10_IS1_WIDTH            (1U)
#define RTU_MRU_NOTIFY_CH10_IS1(x)               (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH10_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH10_IS1_MASK)

#define RTU_MRU_NOTIFY_CH11_IS0_MASK             (0x400U)
#define RTU_MRU_NOTIFY_CH11_IS0_SHIFT            (10U)
#define RTU_MRU_NOTIFY_CH11_IS0_WIDTH            (1U)
#define RTU_MRU_NOTIFY_CH11_IS0(x)               (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH11_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH11_IS0_MASK)

#define RTU_MRU_NOTIFY_CH11_IS1_MASK             (0x400U)
#define RTU_MRU_NOTIFY_CH11_IS1_SHIFT            (10U)
#define RTU_MRU_NOTIFY_CH11_IS1_WIDTH            (1U)
#define RTU_MRU_NOTIFY_CH11_IS1(x)               (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH11_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH11_IS1_MASK)

#define RTU_MRU_NOTIFY_CH12_IS0_MASK             (0x800U)
#define RTU_MRU_NOTIFY_CH12_IS0_SHIFT            (11U)
#define RTU_MRU_NOTIFY_CH12_IS0_WIDTH            (1U)
#define RTU_MRU_NOTIFY_CH12_IS0(x)               (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH12_IS0_SHIFT)) & RTU_MRU_NOTIFY_CH12_IS0_MASK)

#define RTU_MRU_NOTIFY_CH12_IS1_MASK             (0x800U)
#define RTU_MRU_NOTIFY_CH12_IS1_SHIFT            (11U)
#define RTU_MRU_NOTIFY_CH12_IS1_WIDTH            (1U)
#define RTU_MRU_NOTIFY_CH12_IS1(x)               (((uint32_t)(((uint32_t)(x)) << RTU_MRU_NOTIFY_CH12_IS1_SHIFT)) & RTU_MRU_NOTIFY_CH12_IS1_MASK)
/*! @} */

/*! @name CH1_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH1_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH1_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH1_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH1_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH1_MB0_MBD_SHIFT)) & RTU_MRU_CH1_MB0_MBD_MASK)
/*! @} */

/*! @name CH1_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH1_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH1_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH1_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH1_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH1_MB1_MBD_SHIFT)) & RTU_MRU_CH1_MB1_MBD_MASK)
/*! @} */

/*! @name CH2_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH2_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH2_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH2_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH2_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH2_MB0_MBD_SHIFT)) & RTU_MRU_CH2_MB0_MBD_MASK)
/*! @} */

/*! @name CH2_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH2_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH2_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH2_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH2_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH2_MB1_MBD_SHIFT)) & RTU_MRU_CH2_MB1_MBD_MASK)
/*! @} */

/*! @name CH3_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH3_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH3_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH3_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH3_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH3_MB0_MBD_SHIFT)) & RTU_MRU_CH3_MB0_MBD_MASK)
/*! @} */

/*! @name CH3_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH3_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH3_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH3_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH3_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH3_MB1_MBD_SHIFT)) & RTU_MRU_CH3_MB1_MBD_MASK)
/*! @} */

/*! @name CH4_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH4_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH4_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH4_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH4_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH4_MB0_MBD_SHIFT)) & RTU_MRU_CH4_MB0_MBD_MASK)
/*! @} */

/*! @name CH4_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH4_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH4_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH4_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH4_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH4_MB1_MBD_SHIFT)) & RTU_MRU_CH4_MB1_MBD_MASK)
/*! @} */

/*! @name CH5_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH5_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH5_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH5_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH5_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH5_MB0_MBD_SHIFT)) & RTU_MRU_CH5_MB0_MBD_MASK)
/*! @} */

/*! @name CH5_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH5_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH5_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH5_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH5_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH5_MB1_MBD_SHIFT)) & RTU_MRU_CH5_MB1_MBD_MASK)
/*! @} */

/*! @name CH6_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH6_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH6_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH6_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH6_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH6_MB0_MBD_SHIFT)) & RTU_MRU_CH6_MB0_MBD_MASK)
/*! @} */

/*! @name CH6_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH6_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH6_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH6_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH6_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH6_MB1_MBD_SHIFT)) & RTU_MRU_CH6_MB1_MBD_MASK)
/*! @} */

/*! @name CH7_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH7_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH7_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH7_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH7_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH7_MB0_MBD_SHIFT)) & RTU_MRU_CH7_MB0_MBD_MASK)
/*! @} */

/*! @name CH7_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH7_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH7_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH7_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH7_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH7_MB1_MBD_SHIFT)) & RTU_MRU_CH7_MB1_MBD_MASK)
/*! @} */

/*! @name CH8_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB0_MBD_SHIFT)) & RTU_MRU_CH8_MB0_MBD_MASK)
/*! @} */

/*! @name CH8_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB1_MBD_SHIFT)) & RTU_MRU_CH8_MB1_MBD_MASK)
/*! @} */

/*! @name CH8_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB2_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB2_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB2_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB2_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB2_MBD_SHIFT)) & RTU_MRU_CH8_MB2_MBD_MASK)
/*! @} */

/*! @name CH8_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB3_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB3_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB3_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB3_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB3_MBD_SHIFT)) & RTU_MRU_CH8_MB3_MBD_MASK)
/*! @} */

/*! @name CH8_MB4 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB4_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB4_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB4_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB4_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB4_MBD_SHIFT)) & RTU_MRU_CH8_MB4_MBD_MASK)
/*! @} */

/*! @name CH8_MB5 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB5_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB5_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB5_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB5_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB5_MBD_SHIFT)) & RTU_MRU_CH8_MB5_MBD_MASK)
/*! @} */

/*! @name CH8_MB6 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB6_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB6_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB6_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB6_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB6_MBD_SHIFT)) & RTU_MRU_CH8_MB6_MBD_MASK)
/*! @} */

/*! @name CH8_MB7 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH8_MB7_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH8_MB7_MBD_SHIFT                (0U)
#define RTU_MRU_CH8_MB7_MBD_WIDTH                (32U)
#define RTU_MRU_CH8_MB7_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH8_MB7_MBD_SHIFT)) & RTU_MRU_CH8_MB7_MBD_MASK)
/*! @} */

/*! @name CH9_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH9_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH9_MB0_MBD_SHIFT                (0U)
#define RTU_MRU_CH9_MB0_MBD_WIDTH                (32U)
#define RTU_MRU_CH9_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH9_MB0_MBD_SHIFT)) & RTU_MRU_CH9_MB0_MBD_MASK)
/*! @} */

/*! @name CH9_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH9_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH9_MB1_MBD_SHIFT                (0U)
#define RTU_MRU_CH9_MB1_MBD_WIDTH                (32U)
#define RTU_MRU_CH9_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH9_MB1_MBD_SHIFT)) & RTU_MRU_CH9_MB1_MBD_MASK)
/*! @} */

/*! @name CH9_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH9_MB2_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH9_MB2_MBD_SHIFT                (0U)
#define RTU_MRU_CH9_MB2_MBD_WIDTH                (32U)
#define RTU_MRU_CH9_MB2_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH9_MB2_MBD_SHIFT)) & RTU_MRU_CH9_MB2_MBD_MASK)
/*! @} */

/*! @name CH9_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH9_MB3_MBD_MASK                 (0xFFFFFFFFU)
#define RTU_MRU_CH9_MB3_MBD_SHIFT                (0U)
#define RTU_MRU_CH9_MB3_MBD_WIDTH                (32U)
#define RTU_MRU_CH9_MB3_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH9_MB3_MBD_SHIFT)) & RTU_MRU_CH9_MB3_MBD_MASK)
/*! @} */

/*! @name CH10_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH10_MB0_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH10_MB0_MBD_SHIFT               (0U)
#define RTU_MRU_CH10_MB0_MBD_WIDTH               (32U)
#define RTU_MRU_CH10_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH10_MB0_MBD_SHIFT)) & RTU_MRU_CH10_MB0_MBD_MASK)
/*! @} */

/*! @name CH10_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH10_MB1_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH10_MB1_MBD_SHIFT               (0U)
#define RTU_MRU_CH10_MB1_MBD_WIDTH               (32U)
#define RTU_MRU_CH10_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH10_MB1_MBD_SHIFT)) & RTU_MRU_CH10_MB1_MBD_MASK)
/*! @} */

/*! @name CH10_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH10_MB2_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH10_MB2_MBD_SHIFT               (0U)
#define RTU_MRU_CH10_MB2_MBD_WIDTH               (32U)
#define RTU_MRU_CH10_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH10_MB2_MBD_SHIFT)) & RTU_MRU_CH10_MB2_MBD_MASK)
/*! @} */

/*! @name CH10_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH10_MB3_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH10_MB3_MBD_SHIFT               (0U)
#define RTU_MRU_CH10_MB3_MBD_WIDTH               (32U)
#define RTU_MRU_CH10_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH10_MB3_MBD_SHIFT)) & RTU_MRU_CH10_MB3_MBD_MASK)
/*! @} */

/*! @name CH11_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH11_MB0_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH11_MB0_MBD_SHIFT               (0U)
#define RTU_MRU_CH11_MB0_MBD_WIDTH               (32U)
#define RTU_MRU_CH11_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH11_MB0_MBD_SHIFT)) & RTU_MRU_CH11_MB0_MBD_MASK)
/*! @} */

/*! @name CH11_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH11_MB1_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH11_MB1_MBD_SHIFT               (0U)
#define RTU_MRU_CH11_MB1_MBD_WIDTH               (32U)
#define RTU_MRU_CH11_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH11_MB1_MBD_SHIFT)) & RTU_MRU_CH11_MB1_MBD_MASK)
/*! @} */

/*! @name CH11_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH11_MB2_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH11_MB2_MBD_SHIFT               (0U)
#define RTU_MRU_CH11_MB2_MBD_WIDTH               (32U)
#define RTU_MRU_CH11_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH11_MB2_MBD_SHIFT)) & RTU_MRU_CH11_MB2_MBD_MASK)
/*! @} */

/*! @name CH11_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH11_MB3_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH11_MB3_MBD_SHIFT               (0U)
#define RTU_MRU_CH11_MB3_MBD_WIDTH               (32U)
#define RTU_MRU_CH11_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH11_MB3_MBD_SHIFT)) & RTU_MRU_CH11_MB3_MBD_MASK)
/*! @} */

/*! @name CH12_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH12_MB0_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH12_MB0_MBD_SHIFT               (0U)
#define RTU_MRU_CH12_MB0_MBD_WIDTH               (32U)
#define RTU_MRU_CH12_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH12_MB0_MBD_SHIFT)) & RTU_MRU_CH12_MB0_MBD_MASK)
/*! @} */

/*! @name CH12_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH12_MB1_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH12_MB1_MBD_SHIFT               (0U)
#define RTU_MRU_CH12_MB1_MBD_WIDTH               (32U)
#define RTU_MRU_CH12_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH12_MB1_MBD_SHIFT)) & RTU_MRU_CH12_MB1_MBD_MASK)
/*! @} */

/*! @name CH12_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH12_MB2_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH12_MB2_MBD_SHIFT               (0U)
#define RTU_MRU_CH12_MB2_MBD_WIDTH               (32U)
#define RTU_MRU_CH12_MB2_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH12_MB2_MBD_SHIFT)) & RTU_MRU_CH12_MB2_MBD_MASK)
/*! @} */

/*! @name CH12_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define RTU_MRU_CH12_MB3_MBD_MASK                (0xFFFFFFFFU)
#define RTU_MRU_CH12_MB3_MBD_SHIFT               (0U)
#define RTU_MRU_CH12_MB3_MBD_WIDTH               (32U)
#define RTU_MRU_CH12_MB3_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_MRU_CH12_MB3_MBD_SHIFT)) & RTU_MRU_CH12_MB3_MBD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group RTU_MRU_Register_Masks */

/*!
 * @}
 */ /* end of group RTU_MRU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_RTU_MRU_H_) */
