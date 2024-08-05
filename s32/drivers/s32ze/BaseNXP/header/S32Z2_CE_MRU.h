/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CE_MRU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CE_MRU
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
#if !defined(S32Z2_CE_MRU_H_)  /* Check if memory map has not been already included */
#define S32Z2_CE_MRU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CE_MRU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CE_MRU_Peripheral_Access_Layer CE_MRU Peripheral Access Layer
 * @{
 */

/** CE_MRU - Size of Registers Arrays */
#define CE_MRU_CHXCONFIG_COUNT                    4u
#define CE_MRU_NOTIFY_COUNT                       2u

/** CE_MRU - Register Layout Typedef */
typedef struct {
  struct CE_MRU_CHXCONFIG {                        /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG0;                           /**< Channel (x) Configuration 0, array offset: 0x0, array step: 0x10, irregular array, not all indices are valid */
    __IO uint32_t CH_CFG1;                           /**< Channel (x) Configuration 1, array offset: 0x4, array step: 0x10, irregular array, not all indices are valid */
    __IO uint32_t CH_MBSTAT;                         /**< Channel (x) Mailbox Status, array offset: 0x8, array step: 0x10, irregular array, not all indices are valid */
    uint8_t RESERVED_0[4];
  } CHXCONFIG[CE_MRU_CHXCONFIG_COUNT];
  uint8_t RESERVED_0[448];
  __I  uint32_t NOTIFY[CE_MRU_NOTIFY_COUNT];       /**< Notification 0 Status..Notification 1 Status, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_1[15864];
  __IO uint32_t CH1_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x4000 */
  __IO uint32_t CH1_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x4004 */
  __IO uint32_t CH1_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x4008 */
  __IO uint32_t CH1_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x400C */
  __IO uint32_t CH1_MB4;                           /**< Channel (x) Mailbox (n), offset: 0x4010, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB5;                           /**< Channel (x) Mailbox (n), offset: 0x4014, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB6;                           /**< Channel (x) Mailbox (n), offset: 0x4018, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB7;                           /**< Channel (x) Mailbox (n), offset: 0x401C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB8;                           /**< Channel (x) Mailbox (n), offset: 0x4020, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB9;                           /**< Channel (x) Mailbox (n), offset: 0x4024, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB10;                          /**< Channel (x) Mailbox (n), offset: 0x4028, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB11;                          /**< Channel (x) Mailbox (n), offset: 0x402C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB12;                          /**< Channel (x) Mailbox (n), offset: 0x4030, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB13;                          /**< Channel (x) Mailbox (n), offset: 0x4034, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB14;                          /**< Channel (x) Mailbox (n), offset: 0x4038, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH1_MB15;                          /**< Channel (x) Mailbox (n), offset: 0x403C, not available in all instances (available on 12 out of 20) */
  uint8_t RESERVED_2[16320];
  __IO uint32_t CH2_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x8000, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x8004, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x8008, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x800C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB4;                           /**< Channel (x) Mailbox (n), offset: 0x8010, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB5;                           /**< Channel (x) Mailbox (n), offset: 0x8014, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB6;                           /**< Channel (x) Mailbox (n), offset: 0x8018, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB7;                           /**< Channel (x) Mailbox (n), offset: 0x801C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB8;                           /**< Channel (x) Mailbox (n), offset: 0x8020, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB9;                           /**< Channel (x) Mailbox (n), offset: 0x8024, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB10;                          /**< Channel (x) Mailbox (n), offset: 0x8028, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB11;                          /**< Channel (x) Mailbox (n), offset: 0x802C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB12;                          /**< Channel (x) Mailbox (n), offset: 0x8030, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB13;                          /**< Channel (x) Mailbox (n), offset: 0x8034, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB14;                          /**< Channel (x) Mailbox (n), offset: 0x8038, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH2_MB15;                          /**< Channel (x) Mailbox (n), offset: 0x803C, not available in all instances (available on 12 out of 20) */
  uint8_t RESERVED_3[16320];
  __IO uint32_t CH3_MB0;                           /**< Channel (x) Mailbox (n), offset: 0xC000, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB1;                           /**< Channel (x) Mailbox (n), offset: 0xC004, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB2;                           /**< Channel (x) Mailbox (n), offset: 0xC008, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB3;                           /**< Channel (x) Mailbox (n), offset: 0xC00C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB4;                           /**< Channel (x) Mailbox (n), offset: 0xC010, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB5;                           /**< Channel (x) Mailbox (n), offset: 0xC014, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB6;                           /**< Channel (x) Mailbox (n), offset: 0xC018, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB7;                           /**< Channel (x) Mailbox (n), offset: 0xC01C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB8;                           /**< Channel (x) Mailbox (n), offset: 0xC020, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB9;                           /**< Channel (x) Mailbox (n), offset: 0xC024, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB10;                          /**< Channel (x) Mailbox (n), offset: 0xC028, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB11;                          /**< Channel (x) Mailbox (n), offset: 0xC02C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB12;                          /**< Channel (x) Mailbox (n), offset: 0xC030, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB13;                          /**< Channel (x) Mailbox (n), offset: 0xC034, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB14;                          /**< Channel (x) Mailbox (n), offset: 0xC038, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH3_MB15;                          /**< Channel (x) Mailbox (n), offset: 0xC03C, not available in all instances (available on 12 out of 20) */
  uint8_t RESERVED_4[16320];
  __IO uint32_t CH4_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x10000, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x10004, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x10008, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x1000C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB4;                           /**< Channel (x) Mailbox (n), offset: 0x10010, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB5;                           /**< Channel (x) Mailbox (n), offset: 0x10014, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB6;                           /**< Channel (x) Mailbox (n), offset: 0x10018, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB7;                           /**< Channel (x) Mailbox (n), offset: 0x1001C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB8;                           /**< Channel (x) Mailbox (n), offset: 0x10020, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB9;                           /**< Channel (x) Mailbox (n), offset: 0x10024, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB10;                          /**< Channel (x) Mailbox (n), offset: 0x10028, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB11;                          /**< Channel (x) Mailbox (n), offset: 0x1002C, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB12;                          /**< Channel (x) Mailbox (n), offset: 0x10030, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB13;                          /**< Channel (x) Mailbox (n), offset: 0x10034, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB14;                          /**< Channel (x) Mailbox (n), offset: 0x10038, not available in all instances (available on 12 out of 20) */
  __IO uint32_t CH4_MB15;                          /**< Channel (x) Mailbox (n), offset: 0x1003C, not available in all instances (available on 12 out of 20) */
} CE_MRU_Type, *CE_MRU_MemMapPtr;

/** Number of instances of the CE_MRU module. */
#define CE_MRU_INSTANCE_COUNT                    (20u)

/* CE_MRU - Peripheral instance base addresses */
/** Peripheral CE_MRU_0 base address */
#define IP_CE_MRU_0_BASE                         (0x44AEC000u)
/** Peripheral CE_MRU_0 base pointer */
#define IP_CE_MRU_0                              ((CE_MRU_Type *)IP_CE_MRU_0_BASE)
/** Peripheral CE_MRU_1 base address */
#define IP_CE_MRU_1_BASE                         (0x44B0C000u)
/** Peripheral CE_MRU_1 base pointer */
#define IP_CE_MRU_1                              ((CE_MRU_Type *)IP_CE_MRU_1_BASE)
/** Peripheral CE_MRU_2 base address */
#define IP_CE_MRU_2_BASE                         (0x44B2C000u)
/** Peripheral CE_MRU_2 base pointer */
#define IP_CE_MRU_2                              ((CE_MRU_Type *)IP_CE_MRU_2_BASE)
/** Peripheral CE_MRU_3 base address */
#define IP_CE_MRU_3_BASE                         (0x44B4C000u)
/** Peripheral CE_MRU_3 base pointer */
#define IP_CE_MRU_3                              ((CE_MRU_Type *)IP_CE_MRU_3_BASE)
/** Peripheral CE_MRU_4 base address */
#define IP_CE_MRU_4_BASE                         (0x44B6C000u)
/** Peripheral CE_MRU_4 base pointer */
#define IP_CE_MRU_4                              ((CE_MRU_Type *)IP_CE_MRU_4_BASE)
/** Peripheral CE_MRU_5 base address */
#define IP_CE_MRU_5_BASE                         (0x44B8C000u)
/** Peripheral CE_MRU_5 base pointer */
#define IP_CE_MRU_5                              ((CE_MRU_Type *)IP_CE_MRU_5_BASE)
/** Peripheral CE_MRU_6 base address */
#define IP_CE_MRU_6_BASE                         (0x44C0C000u)
/** Peripheral CE_MRU_6 base pointer */
#define IP_CE_MRU_6                              ((CE_MRU_Type *)IP_CE_MRU_6_BASE)
/** Peripheral CE_MRU_7 base address */
#define IP_CE_MRU_7_BASE                         (0x44C3C000u)
/** Peripheral CE_MRU_7 base pointer */
#define IP_CE_MRU_7                              ((CE_MRU_Type *)IP_CE_MRU_7_BASE)
/** Peripheral CE_MRU_8 base address */
#define IP_CE_MRU_8_BASE                         (0x44C6C000u)
/** Peripheral CE_MRU_8 base pointer */
#define IP_CE_MRU_8                              ((CE_MRU_Type *)IP_CE_MRU_8_BASE)
/** Peripheral CE_MRU_9 base address */
#define IP_CE_MRU_9_BASE                         (0x44C9C000u)
/** Peripheral CE_MRU_9 base pointer */
#define IP_CE_MRU_9                              ((CE_MRU_Type *)IP_CE_MRU_9_BASE)
/** Peripheral CE_MRU_10 base address */
#define IP_CE_MRU_10_BASE                        (0x44CCC000u)
/** Peripheral CE_MRU_10 base pointer */
#define IP_CE_MRU_10                             ((CE_MRU_Type *)IP_CE_MRU_10_BASE)
/** Peripheral CE_MRU_11 base address */
#define IP_CE_MRU_11_BASE                        (0x44CFC000u)
/** Peripheral CE_MRU_11 base pointer */
#define IP_CE_MRU_11                             ((CE_MRU_Type *)IP_CE_MRU_11_BASE)
/** Peripheral CE_MRU_12 base address */
#define IP_CE_MRU_12_BASE                        (0x448EC000u)
/** Peripheral CE_MRU_12 base pointer */
#define IP_CE_MRU_12                             ((CE_MRU_Type *)IP_CE_MRU_12_BASE)
/** Peripheral CE_MRU_13 base address */
#define IP_CE_MRU_13_BASE                        (0x4490C000u)
/** Peripheral CE_MRU_13 base pointer */
#define IP_CE_MRU_13                             ((CE_MRU_Type *)IP_CE_MRU_13_BASE)
/** Peripheral CE_MRU_14 base address */
#define IP_CE_MRU_14_BASE                        (0x4492C000u)
/** Peripheral CE_MRU_14 base pointer */
#define IP_CE_MRU_14                             ((CE_MRU_Type *)IP_CE_MRU_14_BASE)
/** Peripheral CE_MRU_15 base address */
#define IP_CE_MRU_15_BASE                        (0x4494C000u)
/** Peripheral CE_MRU_15 base pointer */
#define IP_CE_MRU_15                             ((CE_MRU_Type *)IP_CE_MRU_15_BASE)
/** Peripheral CE_MRU_16 base address */
#define IP_CE_MRU_16_BASE                        (0x4496C000u)
/** Peripheral CE_MRU_16 base pointer */
#define IP_CE_MRU_16                             ((CE_MRU_Type *)IP_CE_MRU_16_BASE)
/** Peripheral CE_MRU_17 base address */
#define IP_CE_MRU_17_BASE                        (0x4498C000u)
/** Peripheral CE_MRU_17 base pointer */
#define IP_CE_MRU_17                             ((CE_MRU_Type *)IP_CE_MRU_17_BASE)
/** Peripheral CE_MRU_18 base address */
#define IP_CE_MRU_18_BASE                        (0x44D2C000u)
/** Peripheral CE_MRU_18 base pointer */
#define IP_CE_MRU_18                             ((CE_MRU_Type *)IP_CE_MRU_18_BASE)
/** Peripheral CE_MRU_19 base address */
#define IP_CE_MRU_19_BASE                        (0x44D4C000u)
/** Peripheral CE_MRU_19 base pointer */
#define IP_CE_MRU_19                             ((CE_MRU_Type *)IP_CE_MRU_19_BASE)
/** Array initializer of CE_MRU peripheral base addresses */
#define IP_CE_MRU_BASE_ADDRS                     { IP_CE_MRU_0_BASE, IP_CE_MRU_1_BASE, IP_CE_MRU_2_BASE, IP_CE_MRU_3_BASE, IP_CE_MRU_4_BASE, IP_CE_MRU_5_BASE, IP_CE_MRU_6_BASE, IP_CE_MRU_7_BASE, IP_CE_MRU_8_BASE, IP_CE_MRU_9_BASE, IP_CE_MRU_10_BASE, IP_CE_MRU_11_BASE, IP_CE_MRU_12_BASE, IP_CE_MRU_13_BASE, IP_CE_MRU_14_BASE, IP_CE_MRU_15_BASE, IP_CE_MRU_16_BASE, IP_CE_MRU_17_BASE, IP_CE_MRU_18_BASE, IP_CE_MRU_19_BASE }
/** Array initializer of CE_MRU peripheral base pointers */
#define IP_CE_MRU_BASE_PTRS                      { IP_CE_MRU_0, IP_CE_MRU_1, IP_CE_MRU_2, IP_CE_MRU_3, IP_CE_MRU_4, IP_CE_MRU_5, IP_CE_MRU_6, IP_CE_MRU_7, IP_CE_MRU_8, IP_CE_MRU_9, IP_CE_MRU_10, IP_CE_MRU_11, IP_CE_MRU_12, IP_CE_MRU_13, IP_CE_MRU_14, IP_CE_MRU_15, IP_CE_MRU_16, IP_CE_MRU_17, IP_CE_MRU_18, IP_CE_MRU_19 }

/* ----------------------------------------------------------------------------
   -- CE_MRU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CE_MRU_Register_Masks CE_MRU Register Masks
 * @{
 */

/*! @name CH_CFG0 - Channel (x) Configuration 0 */
/*! @{ */

#define CE_MRU_CH_CFG0_CHE_MASK                  (0x1U)
#define CE_MRU_CH_CFG0_CHE_SHIFT                 (0U)
#define CE_MRU_CH_CFG0_CHE_WIDTH                 (1U)
#define CE_MRU_CH_CFG0_CHE(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_CHE_SHIFT)) & CE_MRU_CH_CFG0_CHE_MASK)

#define CE_MRU_CH_CFG0_CHR_MASK                  (0x2U)
#define CE_MRU_CH_CFG0_CHR_SHIFT                 (1U)
#define CE_MRU_CH_CFG0_CHR_WIDTH                 (1U)
#define CE_MRU_CH_CFG0_CHR(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_CHR_SHIFT)) & CE_MRU_CH_CFG0_CHR_MASK)

#define CE_MRU_CH_CFG0_IE_MASK                   (0x4U)
#define CE_MRU_CH_CFG0_IE_SHIFT                  (2U)
#define CE_MRU_CH_CFG0_IE_WIDTH                  (1U)
#define CE_MRU_CH_CFG0_IE(x)                     (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_IE_SHIFT)) & CE_MRU_CH_CFG0_IE_MASK)

#define CE_MRU_CH_CFG0_MBE0_MASK                 (0x10000U)
#define CE_MRU_CH_CFG0_MBE0_SHIFT                (16U)
#define CE_MRU_CH_CFG0_MBE0_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE0(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE0_SHIFT)) & CE_MRU_CH_CFG0_MBE0_MASK)

#define CE_MRU_CH_CFG0_MBE1_MASK                 (0x20000U)
#define CE_MRU_CH_CFG0_MBE1_SHIFT                (17U)
#define CE_MRU_CH_CFG0_MBE1_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE1(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE1_SHIFT)) & CE_MRU_CH_CFG0_MBE1_MASK)

#define CE_MRU_CH_CFG0_MBE2_MASK                 (0x40000U)
#define CE_MRU_CH_CFG0_MBE2_SHIFT                (18U)
#define CE_MRU_CH_CFG0_MBE2_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE2(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE2_SHIFT)) & CE_MRU_CH_CFG0_MBE2_MASK)

#define CE_MRU_CH_CFG0_MBE3_MASK                 (0x80000U)
#define CE_MRU_CH_CFG0_MBE3_SHIFT                (19U)
#define CE_MRU_CH_CFG0_MBE3_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE3(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE3_SHIFT)) & CE_MRU_CH_CFG0_MBE3_MASK)

#define CE_MRU_CH_CFG0_MBE4_MASK                 (0x100000U)
#define CE_MRU_CH_CFG0_MBE4_SHIFT                (20U)
#define CE_MRU_CH_CFG0_MBE4_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE4(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE4_SHIFT)) & CE_MRU_CH_CFG0_MBE4_MASK)

#define CE_MRU_CH_CFG0_MBE5_MASK                 (0x200000U)
#define CE_MRU_CH_CFG0_MBE5_SHIFT                (21U)
#define CE_MRU_CH_CFG0_MBE5_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE5(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE5_SHIFT)) & CE_MRU_CH_CFG0_MBE5_MASK)

#define CE_MRU_CH_CFG0_MBE6_MASK                 (0x400000U)
#define CE_MRU_CH_CFG0_MBE6_SHIFT                (22U)
#define CE_MRU_CH_CFG0_MBE6_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE6(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE6_SHIFT)) & CE_MRU_CH_CFG0_MBE6_MASK)

#define CE_MRU_CH_CFG0_MBE7_MASK                 (0x800000U)
#define CE_MRU_CH_CFG0_MBE7_SHIFT                (23U)
#define CE_MRU_CH_CFG0_MBE7_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE7(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE7_SHIFT)) & CE_MRU_CH_CFG0_MBE7_MASK)

#define CE_MRU_CH_CFG0_MBE8_MASK                 (0x1000000U)
#define CE_MRU_CH_CFG0_MBE8_SHIFT                (24U)
#define CE_MRU_CH_CFG0_MBE8_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE8(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE8_SHIFT)) & CE_MRU_CH_CFG0_MBE8_MASK)

#define CE_MRU_CH_CFG0_MBE9_MASK                 (0x2000000U)
#define CE_MRU_CH_CFG0_MBE9_SHIFT                (25U)
#define CE_MRU_CH_CFG0_MBE9_WIDTH                (1U)
#define CE_MRU_CH_CFG0_MBE9(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE9_SHIFT)) & CE_MRU_CH_CFG0_MBE9_MASK)

#define CE_MRU_CH_CFG0_MBE10_MASK                (0x4000000U)
#define CE_MRU_CH_CFG0_MBE10_SHIFT               (26U)
#define CE_MRU_CH_CFG0_MBE10_WIDTH               (1U)
#define CE_MRU_CH_CFG0_MBE10(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE10_SHIFT)) & CE_MRU_CH_CFG0_MBE10_MASK)

#define CE_MRU_CH_CFG0_MBE11_MASK                (0x8000000U)
#define CE_MRU_CH_CFG0_MBE11_SHIFT               (27U)
#define CE_MRU_CH_CFG0_MBE11_WIDTH               (1U)
#define CE_MRU_CH_CFG0_MBE11(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE11_SHIFT)) & CE_MRU_CH_CFG0_MBE11_MASK)

#define CE_MRU_CH_CFG0_MBE12_MASK                (0x10000000U)
#define CE_MRU_CH_CFG0_MBE12_SHIFT               (28U)
#define CE_MRU_CH_CFG0_MBE12_WIDTH               (1U)
#define CE_MRU_CH_CFG0_MBE12(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE12_SHIFT)) & CE_MRU_CH_CFG0_MBE12_MASK)

#define CE_MRU_CH_CFG0_MBE13_MASK                (0x20000000U)
#define CE_MRU_CH_CFG0_MBE13_SHIFT               (29U)
#define CE_MRU_CH_CFG0_MBE13_WIDTH               (1U)
#define CE_MRU_CH_CFG0_MBE13(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE13_SHIFT)) & CE_MRU_CH_CFG0_MBE13_MASK)

#define CE_MRU_CH_CFG0_MBE14_MASK                (0x40000000U)
#define CE_MRU_CH_CFG0_MBE14_SHIFT               (30U)
#define CE_MRU_CH_CFG0_MBE14_WIDTH               (1U)
#define CE_MRU_CH_CFG0_MBE14(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE14_SHIFT)) & CE_MRU_CH_CFG0_MBE14_MASK)

#define CE_MRU_CH_CFG0_MBE15_MASK                (0x80000000U)
#define CE_MRU_CH_CFG0_MBE15_SHIFT               (31U)
#define CE_MRU_CH_CFG0_MBE15_WIDTH               (1U)
#define CE_MRU_CH_CFG0_MBE15(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG0_MBE15_SHIFT)) & CE_MRU_CH_CFG0_MBE15_MASK)
/*! @} */

/*! @name CH_CFG1 - Channel (x) Configuration 1 */
/*! @{ */

#define CE_MRU_CH_CFG1_MBIC0_MASK                (0x10000U)
#define CE_MRU_CH_CFG1_MBIC0_SHIFT               (16U)
#define CE_MRU_CH_CFG1_MBIC0_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC0(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC0_SHIFT)) & CE_MRU_CH_CFG1_MBIC0_MASK)

#define CE_MRU_CH_CFG1_MBIC1_MASK                (0x20000U)
#define CE_MRU_CH_CFG1_MBIC1_SHIFT               (17U)
#define CE_MRU_CH_CFG1_MBIC1_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC1(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC1_SHIFT)) & CE_MRU_CH_CFG1_MBIC1_MASK)

#define CE_MRU_CH_CFG1_MBIC2_MASK                (0x40000U)
#define CE_MRU_CH_CFG1_MBIC2_SHIFT               (18U)
#define CE_MRU_CH_CFG1_MBIC2_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC2(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC2_SHIFT)) & CE_MRU_CH_CFG1_MBIC2_MASK)

#define CE_MRU_CH_CFG1_MBIC3_MASK                (0x80000U)
#define CE_MRU_CH_CFG1_MBIC3_SHIFT               (19U)
#define CE_MRU_CH_CFG1_MBIC3_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC3(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC3_SHIFT)) & CE_MRU_CH_CFG1_MBIC3_MASK)

#define CE_MRU_CH_CFG1_MBIC4_MASK                (0x100000U)
#define CE_MRU_CH_CFG1_MBIC4_SHIFT               (20U)
#define CE_MRU_CH_CFG1_MBIC4_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC4(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC4_SHIFT)) & CE_MRU_CH_CFG1_MBIC4_MASK)

#define CE_MRU_CH_CFG1_MBIC5_MASK                (0x200000U)
#define CE_MRU_CH_CFG1_MBIC5_SHIFT               (21U)
#define CE_MRU_CH_CFG1_MBIC5_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC5(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC5_SHIFT)) & CE_MRU_CH_CFG1_MBIC5_MASK)

#define CE_MRU_CH_CFG1_MBIC6_MASK                (0x400000U)
#define CE_MRU_CH_CFG1_MBIC6_SHIFT               (22U)
#define CE_MRU_CH_CFG1_MBIC6_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC6(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC6_SHIFT)) & CE_MRU_CH_CFG1_MBIC6_MASK)

#define CE_MRU_CH_CFG1_MBIC7_MASK                (0x800000U)
#define CE_MRU_CH_CFG1_MBIC7_SHIFT               (23U)
#define CE_MRU_CH_CFG1_MBIC7_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC7(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC7_SHIFT)) & CE_MRU_CH_CFG1_MBIC7_MASK)

#define CE_MRU_CH_CFG1_MBIC8_MASK                (0x1000000U)
#define CE_MRU_CH_CFG1_MBIC8_SHIFT               (24U)
#define CE_MRU_CH_CFG1_MBIC8_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC8(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC8_SHIFT)) & CE_MRU_CH_CFG1_MBIC8_MASK)

#define CE_MRU_CH_CFG1_MBIC9_MASK                (0x2000000U)
#define CE_MRU_CH_CFG1_MBIC9_SHIFT               (25U)
#define CE_MRU_CH_CFG1_MBIC9_WIDTH               (1U)
#define CE_MRU_CH_CFG1_MBIC9(x)                  (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC9_SHIFT)) & CE_MRU_CH_CFG1_MBIC9_MASK)

#define CE_MRU_CH_CFG1_MBIC10_MASK               (0x4000000U)
#define CE_MRU_CH_CFG1_MBIC10_SHIFT              (26U)
#define CE_MRU_CH_CFG1_MBIC10_WIDTH              (1U)
#define CE_MRU_CH_CFG1_MBIC10(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC10_SHIFT)) & CE_MRU_CH_CFG1_MBIC10_MASK)

#define CE_MRU_CH_CFG1_MBIC11_MASK               (0x8000000U)
#define CE_MRU_CH_CFG1_MBIC11_SHIFT              (27U)
#define CE_MRU_CH_CFG1_MBIC11_WIDTH              (1U)
#define CE_MRU_CH_CFG1_MBIC11(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC11_SHIFT)) & CE_MRU_CH_CFG1_MBIC11_MASK)

#define CE_MRU_CH_CFG1_MBIC12_MASK               (0x10000000U)
#define CE_MRU_CH_CFG1_MBIC12_SHIFT              (28U)
#define CE_MRU_CH_CFG1_MBIC12_WIDTH              (1U)
#define CE_MRU_CH_CFG1_MBIC12(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC12_SHIFT)) & CE_MRU_CH_CFG1_MBIC12_MASK)

#define CE_MRU_CH_CFG1_MBIC13_MASK               (0x20000000U)
#define CE_MRU_CH_CFG1_MBIC13_SHIFT              (29U)
#define CE_MRU_CH_CFG1_MBIC13_WIDTH              (1U)
#define CE_MRU_CH_CFG1_MBIC13(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC13_SHIFT)) & CE_MRU_CH_CFG1_MBIC13_MASK)

#define CE_MRU_CH_CFG1_MBIC14_MASK               (0x40000000U)
#define CE_MRU_CH_CFG1_MBIC14_SHIFT              (30U)
#define CE_MRU_CH_CFG1_MBIC14_WIDTH              (1U)
#define CE_MRU_CH_CFG1_MBIC14(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC14_SHIFT)) & CE_MRU_CH_CFG1_MBIC14_MASK)

#define CE_MRU_CH_CFG1_MBIC15_MASK               (0x80000000U)
#define CE_MRU_CH_CFG1_MBIC15_SHIFT              (31U)
#define CE_MRU_CH_CFG1_MBIC15_WIDTH              (1U)
#define CE_MRU_CH_CFG1_MBIC15(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_CFG1_MBIC15_SHIFT)) & CE_MRU_CH_CFG1_MBIC15_MASK)
/*! @} */

/*! @name CH_MBSTAT - Channel (x) Mailbox Status */
/*! @{ */

#define CE_MRU_CH_MBSTAT_MBS0_MASK               (0x10000U)
#define CE_MRU_CH_MBSTAT_MBS0_SHIFT              (16U)
#define CE_MRU_CH_MBSTAT_MBS0_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS0(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS0_SHIFT)) & CE_MRU_CH_MBSTAT_MBS0_MASK)

#define CE_MRU_CH_MBSTAT_MBS1_MASK               (0x20000U)
#define CE_MRU_CH_MBSTAT_MBS1_SHIFT              (17U)
#define CE_MRU_CH_MBSTAT_MBS1_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS1(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS1_SHIFT)) & CE_MRU_CH_MBSTAT_MBS1_MASK)

#define CE_MRU_CH_MBSTAT_MBS2_MASK               (0x40000U)
#define CE_MRU_CH_MBSTAT_MBS2_SHIFT              (18U)
#define CE_MRU_CH_MBSTAT_MBS2_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS2(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS2_SHIFT)) & CE_MRU_CH_MBSTAT_MBS2_MASK)

#define CE_MRU_CH_MBSTAT_MBS3_MASK               (0x80000U)
#define CE_MRU_CH_MBSTAT_MBS3_SHIFT              (19U)
#define CE_MRU_CH_MBSTAT_MBS3_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS3(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS3_SHIFT)) & CE_MRU_CH_MBSTAT_MBS3_MASK)

#define CE_MRU_CH_MBSTAT_MBS4_MASK               (0x100000U)
#define CE_MRU_CH_MBSTAT_MBS4_SHIFT              (20U)
#define CE_MRU_CH_MBSTAT_MBS4_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS4(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS4_SHIFT)) & CE_MRU_CH_MBSTAT_MBS4_MASK)

#define CE_MRU_CH_MBSTAT_MBS5_MASK               (0x200000U)
#define CE_MRU_CH_MBSTAT_MBS5_SHIFT              (21U)
#define CE_MRU_CH_MBSTAT_MBS5_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS5(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS5_SHIFT)) & CE_MRU_CH_MBSTAT_MBS5_MASK)

#define CE_MRU_CH_MBSTAT_MBS6_MASK               (0x400000U)
#define CE_MRU_CH_MBSTAT_MBS6_SHIFT              (22U)
#define CE_MRU_CH_MBSTAT_MBS6_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS6(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS6_SHIFT)) & CE_MRU_CH_MBSTAT_MBS6_MASK)

#define CE_MRU_CH_MBSTAT_MBS7_MASK               (0x800000U)
#define CE_MRU_CH_MBSTAT_MBS7_SHIFT              (23U)
#define CE_MRU_CH_MBSTAT_MBS7_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS7(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS7_SHIFT)) & CE_MRU_CH_MBSTAT_MBS7_MASK)

#define CE_MRU_CH_MBSTAT_MBS8_MASK               (0x1000000U)
#define CE_MRU_CH_MBSTAT_MBS8_SHIFT              (24U)
#define CE_MRU_CH_MBSTAT_MBS8_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS8(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS8_SHIFT)) & CE_MRU_CH_MBSTAT_MBS8_MASK)

#define CE_MRU_CH_MBSTAT_MBS9_MASK               (0x2000000U)
#define CE_MRU_CH_MBSTAT_MBS9_SHIFT              (25U)
#define CE_MRU_CH_MBSTAT_MBS9_WIDTH              (1U)
#define CE_MRU_CH_MBSTAT_MBS9(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS9_SHIFT)) & CE_MRU_CH_MBSTAT_MBS9_MASK)

#define CE_MRU_CH_MBSTAT_MBS10_MASK              (0x4000000U)
#define CE_MRU_CH_MBSTAT_MBS10_SHIFT             (26U)
#define CE_MRU_CH_MBSTAT_MBS10_WIDTH             (1U)
#define CE_MRU_CH_MBSTAT_MBS10(x)                (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS10_SHIFT)) & CE_MRU_CH_MBSTAT_MBS10_MASK)

#define CE_MRU_CH_MBSTAT_MBS11_MASK              (0x8000000U)
#define CE_MRU_CH_MBSTAT_MBS11_SHIFT             (27U)
#define CE_MRU_CH_MBSTAT_MBS11_WIDTH             (1U)
#define CE_MRU_CH_MBSTAT_MBS11(x)                (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS11_SHIFT)) & CE_MRU_CH_MBSTAT_MBS11_MASK)

#define CE_MRU_CH_MBSTAT_MBS12_MASK              (0x10000000U)
#define CE_MRU_CH_MBSTAT_MBS12_SHIFT             (28U)
#define CE_MRU_CH_MBSTAT_MBS12_WIDTH             (1U)
#define CE_MRU_CH_MBSTAT_MBS12(x)                (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS12_SHIFT)) & CE_MRU_CH_MBSTAT_MBS12_MASK)

#define CE_MRU_CH_MBSTAT_MBS13_MASK              (0x20000000U)
#define CE_MRU_CH_MBSTAT_MBS13_SHIFT             (29U)
#define CE_MRU_CH_MBSTAT_MBS13_WIDTH             (1U)
#define CE_MRU_CH_MBSTAT_MBS13(x)                (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS13_SHIFT)) & CE_MRU_CH_MBSTAT_MBS13_MASK)

#define CE_MRU_CH_MBSTAT_MBS14_MASK              (0x40000000U)
#define CE_MRU_CH_MBSTAT_MBS14_SHIFT             (30U)
#define CE_MRU_CH_MBSTAT_MBS14_WIDTH             (1U)
#define CE_MRU_CH_MBSTAT_MBS14(x)                (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS14_SHIFT)) & CE_MRU_CH_MBSTAT_MBS14_MASK)

#define CE_MRU_CH_MBSTAT_MBS15_MASK              (0x80000000U)
#define CE_MRU_CH_MBSTAT_MBS15_SHIFT             (31U)
#define CE_MRU_CH_MBSTAT_MBS15_WIDTH             (1U)
#define CE_MRU_CH_MBSTAT_MBS15(x)                (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH_MBSTAT_MBS15_SHIFT)) & CE_MRU_CH_MBSTAT_MBS15_MASK)
/*! @} */

/*! @name NOTIFY - Notification 0 Status..Notification 1 Status */
/*! @{ */

#define CE_MRU_NOTIFY_CH1_IS0_MASK               (0x1U)
#define CE_MRU_NOTIFY_CH1_IS0_SHIFT              (0U)
#define CE_MRU_NOTIFY_CH1_IS0_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH1_IS0(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH1_IS0_SHIFT)) & CE_MRU_NOTIFY_CH1_IS0_MASK)

#define CE_MRU_NOTIFY_CH1_IS1_MASK               (0x1U)
#define CE_MRU_NOTIFY_CH1_IS1_SHIFT              (0U)
#define CE_MRU_NOTIFY_CH1_IS1_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH1_IS1(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH1_IS1_SHIFT)) & CE_MRU_NOTIFY_CH1_IS1_MASK)

#define CE_MRU_NOTIFY_CH2_IS0_MASK               (0x2U)
#define CE_MRU_NOTIFY_CH2_IS0_SHIFT              (1U)
#define CE_MRU_NOTIFY_CH2_IS0_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH2_IS0(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH2_IS0_SHIFT)) & CE_MRU_NOTIFY_CH2_IS0_MASK)

#define CE_MRU_NOTIFY_CH2_IS1_MASK               (0x2U)
#define CE_MRU_NOTIFY_CH2_IS1_SHIFT              (1U)
#define CE_MRU_NOTIFY_CH2_IS1_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH2_IS1(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH2_IS1_SHIFT)) & CE_MRU_NOTIFY_CH2_IS1_MASK)

#define CE_MRU_NOTIFY_CH3_IS0_MASK               (0x4U)
#define CE_MRU_NOTIFY_CH3_IS0_SHIFT              (2U)
#define CE_MRU_NOTIFY_CH3_IS0_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH3_IS0(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH3_IS0_SHIFT)) & CE_MRU_NOTIFY_CH3_IS0_MASK)

#define CE_MRU_NOTIFY_CH3_IS1_MASK               (0x4U)
#define CE_MRU_NOTIFY_CH3_IS1_SHIFT              (2U)
#define CE_MRU_NOTIFY_CH3_IS1_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH3_IS1(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH3_IS1_SHIFT)) & CE_MRU_NOTIFY_CH3_IS1_MASK)

#define CE_MRU_NOTIFY_CH4_IS0_MASK               (0x8U)
#define CE_MRU_NOTIFY_CH4_IS0_SHIFT              (3U)
#define CE_MRU_NOTIFY_CH4_IS0_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH4_IS0(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH4_IS0_SHIFT)) & CE_MRU_NOTIFY_CH4_IS0_MASK)

#define CE_MRU_NOTIFY_CH4_IS1_MASK               (0x8U)
#define CE_MRU_NOTIFY_CH4_IS1_SHIFT              (3U)
#define CE_MRU_NOTIFY_CH4_IS1_WIDTH              (1U)
#define CE_MRU_NOTIFY_CH4_IS1(x)                 (((uint32_t)(((uint32_t)(x)) << CE_MRU_NOTIFY_CH4_IS1_SHIFT)) & CE_MRU_NOTIFY_CH4_IS1_MASK)
/*! @} */

/*! @name CH1_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB0_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB0_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB0_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB0_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB0_MBD_SHIFT)) & CE_MRU_CH1_MB0_MBD_MASK)
/*! @} */

/*! @name CH1_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB1_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB1_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB1_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB1_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB1_MBD_SHIFT)) & CE_MRU_CH1_MB1_MBD_MASK)
/*! @} */

/*! @name CH1_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB2_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB2_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB2_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB2_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB2_MBD_SHIFT)) & CE_MRU_CH1_MB2_MBD_MASK)
/*! @} */

/*! @name CH1_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB3_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB3_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB3_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB3_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB3_MBD_SHIFT)) & CE_MRU_CH1_MB3_MBD_MASK)
/*! @} */

/*! @name CH1_MB4 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB4_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB4_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB4_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB4_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB4_MBD_SHIFT)) & CE_MRU_CH1_MB4_MBD_MASK)
/*! @} */

/*! @name CH1_MB5 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB5_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB5_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB5_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB5_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB5_MBD_SHIFT)) & CE_MRU_CH1_MB5_MBD_MASK)
/*! @} */

/*! @name CH1_MB6 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB6_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB6_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB6_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB6_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB6_MBD_SHIFT)) & CE_MRU_CH1_MB6_MBD_MASK)
/*! @} */

/*! @name CH1_MB7 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB7_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB7_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB7_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB7_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB7_MBD_SHIFT)) & CE_MRU_CH1_MB7_MBD_MASK)
/*! @} */

/*! @name CH1_MB8 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB8_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB8_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB8_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB8_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB8_MBD_SHIFT)) & CE_MRU_CH1_MB8_MBD_MASK)
/*! @} */

/*! @name CH1_MB9 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB9_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH1_MB9_MBD_SHIFT                 (0U)
#define CE_MRU_CH1_MB9_MBD_WIDTH                 (32U)
#define CE_MRU_CH1_MB9_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB9_MBD_SHIFT)) & CE_MRU_CH1_MB9_MBD_MASK)
/*! @} */

/*! @name CH1_MB10 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB10_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH1_MB10_MBD_SHIFT                (0U)
#define CE_MRU_CH1_MB10_MBD_WIDTH                (32U)
#define CE_MRU_CH1_MB10_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB10_MBD_SHIFT)) & CE_MRU_CH1_MB10_MBD_MASK)
/*! @} */

/*! @name CH1_MB11 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB11_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH1_MB11_MBD_SHIFT                (0U)
#define CE_MRU_CH1_MB11_MBD_WIDTH                (32U)
#define CE_MRU_CH1_MB11_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB11_MBD_SHIFT)) & CE_MRU_CH1_MB11_MBD_MASK)
/*! @} */

/*! @name CH1_MB12 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB12_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH1_MB12_MBD_SHIFT                (0U)
#define CE_MRU_CH1_MB12_MBD_WIDTH                (32U)
#define CE_MRU_CH1_MB12_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB12_MBD_SHIFT)) & CE_MRU_CH1_MB12_MBD_MASK)
/*! @} */

/*! @name CH1_MB13 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB13_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH1_MB13_MBD_SHIFT                (0U)
#define CE_MRU_CH1_MB13_MBD_WIDTH                (32U)
#define CE_MRU_CH1_MB13_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB13_MBD_SHIFT)) & CE_MRU_CH1_MB13_MBD_MASK)
/*! @} */

/*! @name CH1_MB14 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB14_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH1_MB14_MBD_SHIFT                (0U)
#define CE_MRU_CH1_MB14_MBD_WIDTH                (32U)
#define CE_MRU_CH1_MB14_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB14_MBD_SHIFT)) & CE_MRU_CH1_MB14_MBD_MASK)
/*! @} */

/*! @name CH1_MB15 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH1_MB15_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH1_MB15_MBD_SHIFT                (0U)
#define CE_MRU_CH1_MB15_MBD_WIDTH                (32U)
#define CE_MRU_CH1_MB15_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH1_MB15_MBD_SHIFT)) & CE_MRU_CH1_MB15_MBD_MASK)
/*! @} */

/*! @name CH2_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB0_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB0_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB0_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB0_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB0_MBD_SHIFT)) & CE_MRU_CH2_MB0_MBD_MASK)
/*! @} */

/*! @name CH2_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB1_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB1_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB1_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB1_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB1_MBD_SHIFT)) & CE_MRU_CH2_MB1_MBD_MASK)
/*! @} */

/*! @name CH2_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB2_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB2_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB2_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB2_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB2_MBD_SHIFT)) & CE_MRU_CH2_MB2_MBD_MASK)
/*! @} */

/*! @name CH2_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB3_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB3_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB3_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB3_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB3_MBD_SHIFT)) & CE_MRU_CH2_MB3_MBD_MASK)
/*! @} */

/*! @name CH2_MB4 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB4_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB4_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB4_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB4_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB4_MBD_SHIFT)) & CE_MRU_CH2_MB4_MBD_MASK)
/*! @} */

/*! @name CH2_MB5 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB5_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB5_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB5_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB5_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB5_MBD_SHIFT)) & CE_MRU_CH2_MB5_MBD_MASK)
/*! @} */

/*! @name CH2_MB6 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB6_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB6_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB6_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB6_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB6_MBD_SHIFT)) & CE_MRU_CH2_MB6_MBD_MASK)
/*! @} */

/*! @name CH2_MB7 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB7_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB7_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB7_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB7_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB7_MBD_SHIFT)) & CE_MRU_CH2_MB7_MBD_MASK)
/*! @} */

/*! @name CH2_MB8 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB8_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB8_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB8_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB8_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB8_MBD_SHIFT)) & CE_MRU_CH2_MB8_MBD_MASK)
/*! @} */

/*! @name CH2_MB9 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB9_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH2_MB9_MBD_SHIFT                 (0U)
#define CE_MRU_CH2_MB9_MBD_WIDTH                 (32U)
#define CE_MRU_CH2_MB9_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB9_MBD_SHIFT)) & CE_MRU_CH2_MB9_MBD_MASK)
/*! @} */

/*! @name CH2_MB10 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB10_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH2_MB10_MBD_SHIFT                (0U)
#define CE_MRU_CH2_MB10_MBD_WIDTH                (32U)
#define CE_MRU_CH2_MB10_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB10_MBD_SHIFT)) & CE_MRU_CH2_MB10_MBD_MASK)
/*! @} */

/*! @name CH2_MB11 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB11_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH2_MB11_MBD_SHIFT                (0U)
#define CE_MRU_CH2_MB11_MBD_WIDTH                (32U)
#define CE_MRU_CH2_MB11_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB11_MBD_SHIFT)) & CE_MRU_CH2_MB11_MBD_MASK)
/*! @} */

/*! @name CH2_MB12 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB12_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH2_MB12_MBD_SHIFT                (0U)
#define CE_MRU_CH2_MB12_MBD_WIDTH                (32U)
#define CE_MRU_CH2_MB12_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB12_MBD_SHIFT)) & CE_MRU_CH2_MB12_MBD_MASK)
/*! @} */

/*! @name CH2_MB13 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB13_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH2_MB13_MBD_SHIFT                (0U)
#define CE_MRU_CH2_MB13_MBD_WIDTH                (32U)
#define CE_MRU_CH2_MB13_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB13_MBD_SHIFT)) & CE_MRU_CH2_MB13_MBD_MASK)
/*! @} */

/*! @name CH2_MB14 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB14_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH2_MB14_MBD_SHIFT                (0U)
#define CE_MRU_CH2_MB14_MBD_WIDTH                (32U)
#define CE_MRU_CH2_MB14_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB14_MBD_SHIFT)) & CE_MRU_CH2_MB14_MBD_MASK)
/*! @} */

/*! @name CH2_MB15 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH2_MB15_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH2_MB15_MBD_SHIFT                (0U)
#define CE_MRU_CH2_MB15_MBD_WIDTH                (32U)
#define CE_MRU_CH2_MB15_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH2_MB15_MBD_SHIFT)) & CE_MRU_CH2_MB15_MBD_MASK)
/*! @} */

/*! @name CH3_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB0_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB0_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB0_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB0_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB0_MBD_SHIFT)) & CE_MRU_CH3_MB0_MBD_MASK)
/*! @} */

/*! @name CH3_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB1_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB1_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB1_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB1_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB1_MBD_SHIFT)) & CE_MRU_CH3_MB1_MBD_MASK)
/*! @} */

/*! @name CH3_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB2_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB2_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB2_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB2_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB2_MBD_SHIFT)) & CE_MRU_CH3_MB2_MBD_MASK)
/*! @} */

/*! @name CH3_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB3_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB3_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB3_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB3_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB3_MBD_SHIFT)) & CE_MRU_CH3_MB3_MBD_MASK)
/*! @} */

/*! @name CH3_MB4 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB4_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB4_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB4_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB4_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB4_MBD_SHIFT)) & CE_MRU_CH3_MB4_MBD_MASK)
/*! @} */

/*! @name CH3_MB5 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB5_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB5_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB5_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB5_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB5_MBD_SHIFT)) & CE_MRU_CH3_MB5_MBD_MASK)
/*! @} */

/*! @name CH3_MB6 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB6_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB6_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB6_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB6_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB6_MBD_SHIFT)) & CE_MRU_CH3_MB6_MBD_MASK)
/*! @} */

/*! @name CH3_MB7 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB7_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB7_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB7_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB7_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB7_MBD_SHIFT)) & CE_MRU_CH3_MB7_MBD_MASK)
/*! @} */

/*! @name CH3_MB8 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB8_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB8_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB8_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB8_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB8_MBD_SHIFT)) & CE_MRU_CH3_MB8_MBD_MASK)
/*! @} */

/*! @name CH3_MB9 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB9_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH3_MB9_MBD_SHIFT                 (0U)
#define CE_MRU_CH3_MB9_MBD_WIDTH                 (32U)
#define CE_MRU_CH3_MB9_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB9_MBD_SHIFT)) & CE_MRU_CH3_MB9_MBD_MASK)
/*! @} */

/*! @name CH3_MB10 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB10_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH3_MB10_MBD_SHIFT                (0U)
#define CE_MRU_CH3_MB10_MBD_WIDTH                (32U)
#define CE_MRU_CH3_MB10_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB10_MBD_SHIFT)) & CE_MRU_CH3_MB10_MBD_MASK)
/*! @} */

/*! @name CH3_MB11 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB11_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH3_MB11_MBD_SHIFT                (0U)
#define CE_MRU_CH3_MB11_MBD_WIDTH                (32U)
#define CE_MRU_CH3_MB11_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB11_MBD_SHIFT)) & CE_MRU_CH3_MB11_MBD_MASK)
/*! @} */

/*! @name CH3_MB12 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB12_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH3_MB12_MBD_SHIFT                (0U)
#define CE_MRU_CH3_MB12_MBD_WIDTH                (32U)
#define CE_MRU_CH3_MB12_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB12_MBD_SHIFT)) & CE_MRU_CH3_MB12_MBD_MASK)
/*! @} */

/*! @name CH3_MB13 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB13_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH3_MB13_MBD_SHIFT                (0U)
#define CE_MRU_CH3_MB13_MBD_WIDTH                (32U)
#define CE_MRU_CH3_MB13_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB13_MBD_SHIFT)) & CE_MRU_CH3_MB13_MBD_MASK)
/*! @} */

/*! @name CH3_MB14 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB14_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH3_MB14_MBD_SHIFT                (0U)
#define CE_MRU_CH3_MB14_MBD_WIDTH                (32U)
#define CE_MRU_CH3_MB14_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB14_MBD_SHIFT)) & CE_MRU_CH3_MB14_MBD_MASK)
/*! @} */

/*! @name CH3_MB15 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH3_MB15_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH3_MB15_MBD_SHIFT                (0U)
#define CE_MRU_CH3_MB15_MBD_WIDTH                (32U)
#define CE_MRU_CH3_MB15_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH3_MB15_MBD_SHIFT)) & CE_MRU_CH3_MB15_MBD_MASK)
/*! @} */

/*! @name CH4_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB0_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB0_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB0_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB0_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB0_MBD_SHIFT)) & CE_MRU_CH4_MB0_MBD_MASK)
/*! @} */

/*! @name CH4_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB1_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB1_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB1_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB1_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB1_MBD_SHIFT)) & CE_MRU_CH4_MB1_MBD_MASK)
/*! @} */

/*! @name CH4_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB2_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB2_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB2_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB2_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB2_MBD_SHIFT)) & CE_MRU_CH4_MB2_MBD_MASK)
/*! @} */

/*! @name CH4_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB3_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB3_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB3_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB3_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB3_MBD_SHIFT)) & CE_MRU_CH4_MB3_MBD_MASK)
/*! @} */

/*! @name CH4_MB4 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB4_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB4_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB4_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB4_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB4_MBD_SHIFT)) & CE_MRU_CH4_MB4_MBD_MASK)
/*! @} */

/*! @name CH4_MB5 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB5_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB5_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB5_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB5_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB5_MBD_SHIFT)) & CE_MRU_CH4_MB5_MBD_MASK)
/*! @} */

/*! @name CH4_MB6 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB6_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB6_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB6_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB6_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB6_MBD_SHIFT)) & CE_MRU_CH4_MB6_MBD_MASK)
/*! @} */

/*! @name CH4_MB7 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB7_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB7_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB7_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB7_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB7_MBD_SHIFT)) & CE_MRU_CH4_MB7_MBD_MASK)
/*! @} */

/*! @name CH4_MB8 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB8_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB8_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB8_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB8_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB8_MBD_SHIFT)) & CE_MRU_CH4_MB8_MBD_MASK)
/*! @} */

/*! @name CH4_MB9 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB9_MBD_MASK                  (0xFFFFFFFFU)
#define CE_MRU_CH4_MB9_MBD_SHIFT                 (0U)
#define CE_MRU_CH4_MB9_MBD_WIDTH                 (32U)
#define CE_MRU_CH4_MB9_MBD(x)                    (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB9_MBD_SHIFT)) & CE_MRU_CH4_MB9_MBD_MASK)
/*! @} */

/*! @name CH4_MB10 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB10_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH4_MB10_MBD_SHIFT                (0U)
#define CE_MRU_CH4_MB10_MBD_WIDTH                (32U)
#define CE_MRU_CH4_MB10_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB10_MBD_SHIFT)) & CE_MRU_CH4_MB10_MBD_MASK)
/*! @} */

/*! @name CH4_MB11 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB11_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH4_MB11_MBD_SHIFT                (0U)
#define CE_MRU_CH4_MB11_MBD_WIDTH                (32U)
#define CE_MRU_CH4_MB11_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB11_MBD_SHIFT)) & CE_MRU_CH4_MB11_MBD_MASK)
/*! @} */

/*! @name CH4_MB12 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB12_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH4_MB12_MBD_SHIFT                (0U)
#define CE_MRU_CH4_MB12_MBD_WIDTH                (32U)
#define CE_MRU_CH4_MB12_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB12_MBD_SHIFT)) & CE_MRU_CH4_MB12_MBD_MASK)
/*! @} */

/*! @name CH4_MB13 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB13_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH4_MB13_MBD_SHIFT                (0U)
#define CE_MRU_CH4_MB13_MBD_WIDTH                (32U)
#define CE_MRU_CH4_MB13_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB13_MBD_SHIFT)) & CE_MRU_CH4_MB13_MBD_MASK)
/*! @} */

/*! @name CH4_MB14 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB14_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH4_MB14_MBD_SHIFT                (0U)
#define CE_MRU_CH4_MB14_MBD_WIDTH                (32U)
#define CE_MRU_CH4_MB14_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB14_MBD_SHIFT)) & CE_MRU_CH4_MB14_MBD_MASK)
/*! @} */

/*! @name CH4_MB15 - Channel (x) Mailbox (n) */
/*! @{ */

#define CE_MRU_CH4_MB15_MBD_MASK                 (0xFFFFFFFFU)
#define CE_MRU_CH4_MB15_MBD_SHIFT                (0U)
#define CE_MRU_CH4_MB15_MBD_WIDTH                (32U)
#define CE_MRU_CH4_MB15_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << CE_MRU_CH4_MB15_MBD_SHIFT)) & CE_MRU_CH4_MB15_MBD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CE_MRU_Register_Masks */

/*!
 * @}
 */ /* end of group CE_MRU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CE_MRU_H_) */
