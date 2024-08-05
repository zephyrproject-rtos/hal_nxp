/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SMU_MRU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SMU_MRU
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
#if !defined(S32Z2_SMU_MRU_H_)  /* Check if memory map has not been already included */
#define S32Z2_SMU_MRU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SMU_MRU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMU_MRU_Peripheral_Access_Layer SMU_MRU Peripheral Access Layer
 * @{
 */

/** SMU_MRU - Size of Registers Arrays */
#define SMU_MRU_CHXCONFIG_COUNT                   12u
#define SMU_MRU_NOTIFY_COUNT                      2u

/** SMU_MRU - Register Layout Typedef */
typedef struct {
  struct SMU_MRU_CHXCONFIG {                       /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG0;                           /**< Channel (x) Configuration 0, array offset: 0x0, array step: 0x10 */
    __IO uint32_t CH_CFG1;                           /**< Channel (x) Configuration 1, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CH_MBSTAT;                         /**< Channel (x) Mailbox Status, array offset: 0x8, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CHXCONFIG[SMU_MRU_CHXCONFIG_COUNT];
  uint8_t RESERVED_0[320];
  __I  uint32_t NOTIFY[SMU_MRU_NOTIFY_COUNT];      /**< Notification 0 Status..Notification 1 Status, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_1[65016];
  __IO uint32_t CH1_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x10000 */
  __IO uint32_t CH1_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x10004 */
  __IO uint32_t CH1_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x10008 */
  __IO uint32_t CH1_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x1000C */
  uint8_t RESERVED_2[65520];
  __IO uint32_t CH2_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x20000 */
  __IO uint32_t CH2_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x20004 */
  __IO uint32_t CH2_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x20008 */
  __IO uint32_t CH2_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x2000C */
  uint8_t RESERVED_3[65520];
  __IO uint32_t CH3_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x30000 */
  __IO uint32_t CH3_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x30004 */
  __IO uint32_t CH3_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x30008 */
  __IO uint32_t CH3_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x3000C */
  uint8_t RESERVED_4[65520];
  __IO uint32_t CH4_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x40000 */
  __IO uint32_t CH4_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x40004 */
  __IO uint32_t CH4_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x40008 */
  __IO uint32_t CH4_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x4000C */
  uint8_t RESERVED_5[65520];
  __IO uint32_t CH5_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x50000 */
  __IO uint32_t CH5_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x50004 */
  uint8_t RESERVED_6[65528];
  __IO uint32_t CH6_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x60000 */
  __IO uint32_t CH6_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x60004 */
  uint8_t RESERVED_7[65528];
  __IO uint32_t CH7_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x70000 */
  __IO uint32_t CH7_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x70004 */
  uint8_t RESERVED_8[65528];
  __IO uint32_t CH8_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x80000 */
  __IO uint32_t CH8_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x80004 */
  uint8_t RESERVED_9[65528];
  __IO uint32_t CH9_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x90000 */
  __IO uint32_t CH9_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x90004 */
  uint8_t RESERVED_10[65528];
  __IO uint32_t CH10_MB0;                          /**< Channel (x) Mailbox (n), offset: 0xA0000 */
  __IO uint32_t CH10_MB1;                          /**< Channel (x) Mailbox (n), offset: 0xA0004 */
  uint8_t RESERVED_11[65528];
  __IO uint32_t CH11_MB0;                          /**< Channel (x) Mailbox (n), offset: 0xB0000 */
  __IO uint32_t CH11_MB1;                          /**< Channel (x) Mailbox (n), offset: 0xB0004 */
  uint8_t RESERVED_12[65528];
  __IO uint32_t CH12_MB0;                          /**< Channel (x) Mailbox (n), offset: 0xC0000 */
  __IO uint32_t CH12_MB1;                          /**< Channel (x) Mailbox (n), offset: 0xC0004 */
} SMU_MRU_Type, *SMU_MRU_MemMapPtr;

/** Number of instances of the SMU_MRU module. */
#define SMU_MRU_INSTANCE_COUNT                   (1u)

/* SMU_MRU - Peripheral instance base addresses */
/** Peripheral SMU__MRU base address */
#define IP_SMU__MRU_BASE                         (0x45300000u)
/** Peripheral SMU__MRU base pointer */
#define IP_SMU__MRU                              ((SMU_MRU_Type *)IP_SMU__MRU_BASE)
/** Array initializer of SMU_MRU peripheral base addresses */
#define IP_SMU_MRU_BASE_ADDRS                    { IP_SMU__MRU_BASE }
/** Array initializer of SMU_MRU peripheral base pointers */
#define IP_SMU_MRU_BASE_PTRS                     { IP_SMU__MRU }

/* ----------------------------------------------------------------------------
   -- SMU_MRU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMU_MRU_Register_Masks SMU_MRU Register Masks
 * @{
 */

/*! @name CH_CFG0 - Channel (x) Configuration 0 */
/*! @{ */

#define SMU_MRU_CH_CFG0_CHE_MASK                 (0x1U)
#define SMU_MRU_CH_CFG0_CHE_SHIFT                (0U)
#define SMU_MRU_CH_CFG0_CHE_WIDTH                (1U)
#define SMU_MRU_CH_CFG0_CHE(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG0_CHE_SHIFT)) & SMU_MRU_CH_CFG0_CHE_MASK)

#define SMU_MRU_CH_CFG0_CHR_MASK                 (0x2U)
#define SMU_MRU_CH_CFG0_CHR_SHIFT                (1U)
#define SMU_MRU_CH_CFG0_CHR_WIDTH                (1U)
#define SMU_MRU_CH_CFG0_CHR(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG0_CHR_SHIFT)) & SMU_MRU_CH_CFG0_CHR_MASK)

#define SMU_MRU_CH_CFG0_IE_MASK                  (0x4U)
#define SMU_MRU_CH_CFG0_IE_SHIFT                 (2U)
#define SMU_MRU_CH_CFG0_IE_WIDTH                 (1U)
#define SMU_MRU_CH_CFG0_IE(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG0_IE_SHIFT)) & SMU_MRU_CH_CFG0_IE_MASK)

#define SMU_MRU_CH_CFG0_MBE0_MASK                (0x10000U)
#define SMU_MRU_CH_CFG0_MBE0_SHIFT               (16U)
#define SMU_MRU_CH_CFG0_MBE0_WIDTH               (1U)
#define SMU_MRU_CH_CFG0_MBE0(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG0_MBE0_SHIFT)) & SMU_MRU_CH_CFG0_MBE0_MASK)

#define SMU_MRU_CH_CFG0_MBE1_MASK                (0x20000U)
#define SMU_MRU_CH_CFG0_MBE1_SHIFT               (17U)
#define SMU_MRU_CH_CFG0_MBE1_WIDTH               (1U)
#define SMU_MRU_CH_CFG0_MBE1(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG0_MBE1_SHIFT)) & SMU_MRU_CH_CFG0_MBE1_MASK)

#define SMU_MRU_CH_CFG0_MBE2_MASK                (0x40000U)
#define SMU_MRU_CH_CFG0_MBE2_SHIFT               (18U)
#define SMU_MRU_CH_CFG0_MBE2_WIDTH               (1U)
#define SMU_MRU_CH_CFG0_MBE2(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG0_MBE2_SHIFT)) & SMU_MRU_CH_CFG0_MBE2_MASK)

#define SMU_MRU_CH_CFG0_MBE3_MASK                (0x80000U)
#define SMU_MRU_CH_CFG0_MBE3_SHIFT               (19U)
#define SMU_MRU_CH_CFG0_MBE3_WIDTH               (1U)
#define SMU_MRU_CH_CFG0_MBE3(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG0_MBE3_SHIFT)) & SMU_MRU_CH_CFG0_MBE3_MASK)
/*! @} */

/*! @name CH_CFG1 - Channel (x) Configuration 1 */
/*! @{ */

#define SMU_MRU_CH_CFG1_MBIC0_MASK               (0x10000U)
#define SMU_MRU_CH_CFG1_MBIC0_SHIFT              (16U)
#define SMU_MRU_CH_CFG1_MBIC0_WIDTH              (1U)
#define SMU_MRU_CH_CFG1_MBIC0(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG1_MBIC0_SHIFT)) & SMU_MRU_CH_CFG1_MBIC0_MASK)

#define SMU_MRU_CH_CFG1_MBIC1_MASK               (0x20000U)
#define SMU_MRU_CH_CFG1_MBIC1_SHIFT              (17U)
#define SMU_MRU_CH_CFG1_MBIC1_WIDTH              (1U)
#define SMU_MRU_CH_CFG1_MBIC1(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG1_MBIC1_SHIFT)) & SMU_MRU_CH_CFG1_MBIC1_MASK)

#define SMU_MRU_CH_CFG1_MBIC2_MASK               (0x40000U)
#define SMU_MRU_CH_CFG1_MBIC2_SHIFT              (18U)
#define SMU_MRU_CH_CFG1_MBIC2_WIDTH              (1U)
#define SMU_MRU_CH_CFG1_MBIC2(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG1_MBIC2_SHIFT)) & SMU_MRU_CH_CFG1_MBIC2_MASK)

#define SMU_MRU_CH_CFG1_MBIC3_MASK               (0x80000U)
#define SMU_MRU_CH_CFG1_MBIC3_SHIFT              (19U)
#define SMU_MRU_CH_CFG1_MBIC3_WIDTH              (1U)
#define SMU_MRU_CH_CFG1_MBIC3(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_CFG1_MBIC3_SHIFT)) & SMU_MRU_CH_CFG1_MBIC3_MASK)
/*! @} */

/*! @name CH_MBSTAT - Channel (x) Mailbox Status */
/*! @{ */

#define SMU_MRU_CH_MBSTAT_MBS0_MASK              (0x10000U)
#define SMU_MRU_CH_MBSTAT_MBS0_SHIFT             (16U)
#define SMU_MRU_CH_MBSTAT_MBS0_WIDTH             (1U)
#define SMU_MRU_CH_MBSTAT_MBS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_MBSTAT_MBS0_SHIFT)) & SMU_MRU_CH_MBSTAT_MBS0_MASK)

#define SMU_MRU_CH_MBSTAT_MBS1_MASK              (0x20000U)
#define SMU_MRU_CH_MBSTAT_MBS1_SHIFT             (17U)
#define SMU_MRU_CH_MBSTAT_MBS1_WIDTH             (1U)
#define SMU_MRU_CH_MBSTAT_MBS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_MBSTAT_MBS1_SHIFT)) & SMU_MRU_CH_MBSTAT_MBS1_MASK)

#define SMU_MRU_CH_MBSTAT_MBS2_MASK              (0x40000U)
#define SMU_MRU_CH_MBSTAT_MBS2_SHIFT             (18U)
#define SMU_MRU_CH_MBSTAT_MBS2_WIDTH             (1U)
#define SMU_MRU_CH_MBSTAT_MBS2(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_MBSTAT_MBS2_SHIFT)) & SMU_MRU_CH_MBSTAT_MBS2_MASK)

#define SMU_MRU_CH_MBSTAT_MBS3_MASK              (0x80000U)
#define SMU_MRU_CH_MBSTAT_MBS3_SHIFT             (19U)
#define SMU_MRU_CH_MBSTAT_MBS3_WIDTH             (1U)
#define SMU_MRU_CH_MBSTAT_MBS3(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH_MBSTAT_MBS3_SHIFT)) & SMU_MRU_CH_MBSTAT_MBS3_MASK)
/*! @} */

/*! @name NOTIFY - Notification 0 Status..Notification 1 Status */
/*! @{ */

#define SMU_MRU_NOTIFY_CH1_IS0_MASK              (0x1U)
#define SMU_MRU_NOTIFY_CH1_IS0_SHIFT             (0U)
#define SMU_MRU_NOTIFY_CH1_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH1_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH1_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH1_IS0_MASK)

#define SMU_MRU_NOTIFY_CH2_IS0_MASK              (0x2U)
#define SMU_MRU_NOTIFY_CH2_IS0_SHIFT             (1U)
#define SMU_MRU_NOTIFY_CH2_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH2_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH2_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH2_IS0_MASK)

#define SMU_MRU_NOTIFY_CH3_IS0_MASK              (0x4U)
#define SMU_MRU_NOTIFY_CH3_IS0_SHIFT             (2U)
#define SMU_MRU_NOTIFY_CH3_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH3_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH3_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH3_IS0_MASK)

#define SMU_MRU_NOTIFY_CH4_IS0_MASK              (0x8U)
#define SMU_MRU_NOTIFY_CH4_IS0_SHIFT             (3U)
#define SMU_MRU_NOTIFY_CH4_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH4_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH4_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH4_IS0_MASK)

#define SMU_MRU_NOTIFY_CH5_IS0_MASK              (0x10U)
#define SMU_MRU_NOTIFY_CH5_IS0_SHIFT             (4U)
#define SMU_MRU_NOTIFY_CH5_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH5_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH5_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH5_IS0_MASK)

#define SMU_MRU_NOTIFY_CH6_IS0_MASK              (0x20U)
#define SMU_MRU_NOTIFY_CH6_IS0_SHIFT             (5U)
#define SMU_MRU_NOTIFY_CH6_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH6_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH6_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH6_IS0_MASK)

#define SMU_MRU_NOTIFY_CH7_IS0_MASK              (0x40U)
#define SMU_MRU_NOTIFY_CH7_IS0_SHIFT             (6U)
#define SMU_MRU_NOTIFY_CH7_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH7_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH7_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH7_IS0_MASK)

#define SMU_MRU_NOTIFY_CH8_IS0_MASK              (0x80U)
#define SMU_MRU_NOTIFY_CH8_IS0_SHIFT             (7U)
#define SMU_MRU_NOTIFY_CH8_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH8_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH8_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH8_IS0_MASK)

#define SMU_MRU_NOTIFY_CH9_IS0_MASK              (0x100U)
#define SMU_MRU_NOTIFY_CH9_IS0_SHIFT             (8U)
#define SMU_MRU_NOTIFY_CH9_IS0_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH9_IS0(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH9_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH9_IS0_MASK)

#define SMU_MRU_NOTIFY_CH10_IS0_MASK             (0x200U)
#define SMU_MRU_NOTIFY_CH10_IS0_SHIFT            (9U)
#define SMU_MRU_NOTIFY_CH10_IS0_WIDTH            (1U)
#define SMU_MRU_NOTIFY_CH10_IS0(x)               (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH10_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH10_IS0_MASK)

#define SMU_MRU_NOTIFY_CH11_IS0_MASK             (0x400U)
#define SMU_MRU_NOTIFY_CH11_IS0_SHIFT            (10U)
#define SMU_MRU_NOTIFY_CH11_IS0_WIDTH            (1U)
#define SMU_MRU_NOTIFY_CH11_IS0(x)               (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH11_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH11_IS0_MASK)

#define SMU_MRU_NOTIFY_CH12_IS0_MASK             (0x800U)
#define SMU_MRU_NOTIFY_CH12_IS0_SHIFT            (11U)
#define SMU_MRU_NOTIFY_CH12_IS0_WIDTH            (1U)
#define SMU_MRU_NOTIFY_CH12_IS0(x)               (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH12_IS0_SHIFT)) & SMU_MRU_NOTIFY_CH12_IS0_MASK)

#define SMU_MRU_NOTIFY_CH1_IS1_MASK              (0x1U)
#define SMU_MRU_NOTIFY_CH1_IS1_SHIFT             (0U)
#define SMU_MRU_NOTIFY_CH1_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH1_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH1_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH1_IS1_MASK)

#define SMU_MRU_NOTIFY_CH2_IS1_MASK              (0x2U)
#define SMU_MRU_NOTIFY_CH2_IS1_SHIFT             (1U)
#define SMU_MRU_NOTIFY_CH2_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH2_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH2_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH2_IS1_MASK)

#define SMU_MRU_NOTIFY_CH3_IS1_MASK              (0x4U)
#define SMU_MRU_NOTIFY_CH3_IS1_SHIFT             (2U)
#define SMU_MRU_NOTIFY_CH3_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH3_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH3_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH3_IS1_MASK)

#define SMU_MRU_NOTIFY_CH4_IS1_MASK              (0x8U)
#define SMU_MRU_NOTIFY_CH4_IS1_SHIFT             (3U)
#define SMU_MRU_NOTIFY_CH4_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH4_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH4_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH4_IS1_MASK)

#define SMU_MRU_NOTIFY_CH5_IS1_MASK              (0x10U)
#define SMU_MRU_NOTIFY_CH5_IS1_SHIFT             (4U)
#define SMU_MRU_NOTIFY_CH5_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH5_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH5_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH5_IS1_MASK)

#define SMU_MRU_NOTIFY_CH6_IS1_MASK              (0x20U)
#define SMU_MRU_NOTIFY_CH6_IS1_SHIFT             (5U)
#define SMU_MRU_NOTIFY_CH6_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH6_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH6_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH6_IS1_MASK)

#define SMU_MRU_NOTIFY_CH7_IS1_MASK              (0x40U)
#define SMU_MRU_NOTIFY_CH7_IS1_SHIFT             (6U)
#define SMU_MRU_NOTIFY_CH7_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH7_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH7_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH7_IS1_MASK)

#define SMU_MRU_NOTIFY_CH8_IS1_MASK              (0x80U)
#define SMU_MRU_NOTIFY_CH8_IS1_SHIFT             (7U)
#define SMU_MRU_NOTIFY_CH8_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH8_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH8_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH8_IS1_MASK)

#define SMU_MRU_NOTIFY_CH9_IS1_MASK              (0x100U)
#define SMU_MRU_NOTIFY_CH9_IS1_SHIFT             (8U)
#define SMU_MRU_NOTIFY_CH9_IS1_WIDTH             (1U)
#define SMU_MRU_NOTIFY_CH9_IS1(x)                (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH9_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH9_IS1_MASK)

#define SMU_MRU_NOTIFY_CH10_IS1_MASK             (0x200U)
#define SMU_MRU_NOTIFY_CH10_IS1_SHIFT            (9U)
#define SMU_MRU_NOTIFY_CH10_IS1_WIDTH            (1U)
#define SMU_MRU_NOTIFY_CH10_IS1(x)               (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH10_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH10_IS1_MASK)

#define SMU_MRU_NOTIFY_CH11_IS1_MASK             (0x400U)
#define SMU_MRU_NOTIFY_CH11_IS1_SHIFT            (10U)
#define SMU_MRU_NOTIFY_CH11_IS1_WIDTH            (1U)
#define SMU_MRU_NOTIFY_CH11_IS1(x)               (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH11_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH11_IS1_MASK)

#define SMU_MRU_NOTIFY_CH12_IS1_MASK             (0x800U)
#define SMU_MRU_NOTIFY_CH12_IS1_SHIFT            (11U)
#define SMU_MRU_NOTIFY_CH12_IS1_WIDTH            (1U)
#define SMU_MRU_NOTIFY_CH12_IS1(x)               (((uint32_t)(((uint32_t)(x)) << SMU_MRU_NOTIFY_CH12_IS1_SHIFT)) & SMU_MRU_NOTIFY_CH12_IS1_MASK)
/*! @} */

/*! @name CH1_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH1_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH1_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH1_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH1_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH1_MB0_MBD_SHIFT)) & SMU_MRU_CH1_MB0_MBD_MASK)
/*! @} */

/*! @name CH1_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH1_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH1_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH1_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH1_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH1_MB1_MBD_SHIFT)) & SMU_MRU_CH1_MB1_MBD_MASK)
/*! @} */

/*! @name CH1_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH1_MB2_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH1_MB2_MBD_SHIFT                (0U)
#define SMU_MRU_CH1_MB2_MBD_WIDTH                (32U)
#define SMU_MRU_CH1_MB2_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH1_MB2_MBD_SHIFT)) & SMU_MRU_CH1_MB2_MBD_MASK)
/*! @} */

/*! @name CH1_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH1_MB3_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH1_MB3_MBD_SHIFT                (0U)
#define SMU_MRU_CH1_MB3_MBD_WIDTH                (32U)
#define SMU_MRU_CH1_MB3_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH1_MB3_MBD_SHIFT)) & SMU_MRU_CH1_MB3_MBD_MASK)
/*! @} */

/*! @name CH2_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH2_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH2_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH2_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH2_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH2_MB0_MBD_SHIFT)) & SMU_MRU_CH2_MB0_MBD_MASK)
/*! @} */

/*! @name CH2_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH2_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH2_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH2_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH2_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH2_MB1_MBD_SHIFT)) & SMU_MRU_CH2_MB1_MBD_MASK)
/*! @} */

/*! @name CH2_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH2_MB2_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH2_MB2_MBD_SHIFT                (0U)
#define SMU_MRU_CH2_MB2_MBD_WIDTH                (32U)
#define SMU_MRU_CH2_MB2_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH2_MB2_MBD_SHIFT)) & SMU_MRU_CH2_MB2_MBD_MASK)
/*! @} */

/*! @name CH2_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH2_MB3_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH2_MB3_MBD_SHIFT                (0U)
#define SMU_MRU_CH2_MB3_MBD_WIDTH                (32U)
#define SMU_MRU_CH2_MB3_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH2_MB3_MBD_SHIFT)) & SMU_MRU_CH2_MB3_MBD_MASK)
/*! @} */

/*! @name CH3_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH3_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH3_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH3_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH3_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH3_MB0_MBD_SHIFT)) & SMU_MRU_CH3_MB0_MBD_MASK)
/*! @} */

/*! @name CH3_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH3_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH3_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH3_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH3_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH3_MB1_MBD_SHIFT)) & SMU_MRU_CH3_MB1_MBD_MASK)
/*! @} */

/*! @name CH3_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH3_MB2_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH3_MB2_MBD_SHIFT                (0U)
#define SMU_MRU_CH3_MB2_MBD_WIDTH                (32U)
#define SMU_MRU_CH3_MB2_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH3_MB2_MBD_SHIFT)) & SMU_MRU_CH3_MB2_MBD_MASK)
/*! @} */

/*! @name CH3_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH3_MB3_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH3_MB3_MBD_SHIFT                (0U)
#define SMU_MRU_CH3_MB3_MBD_WIDTH                (32U)
#define SMU_MRU_CH3_MB3_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH3_MB3_MBD_SHIFT)) & SMU_MRU_CH3_MB3_MBD_MASK)
/*! @} */

/*! @name CH4_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH4_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH4_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH4_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH4_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH4_MB0_MBD_SHIFT)) & SMU_MRU_CH4_MB0_MBD_MASK)
/*! @} */

/*! @name CH4_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH4_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH4_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH4_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH4_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH4_MB1_MBD_SHIFT)) & SMU_MRU_CH4_MB1_MBD_MASK)
/*! @} */

/*! @name CH4_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH4_MB2_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH4_MB2_MBD_SHIFT                (0U)
#define SMU_MRU_CH4_MB2_MBD_WIDTH                (32U)
#define SMU_MRU_CH4_MB2_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH4_MB2_MBD_SHIFT)) & SMU_MRU_CH4_MB2_MBD_MASK)
/*! @} */

/*! @name CH4_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH4_MB3_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH4_MB3_MBD_SHIFT                (0U)
#define SMU_MRU_CH4_MB3_MBD_WIDTH                (32U)
#define SMU_MRU_CH4_MB3_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH4_MB3_MBD_SHIFT)) & SMU_MRU_CH4_MB3_MBD_MASK)
/*! @} */

/*! @name CH5_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH5_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH5_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH5_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH5_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH5_MB0_MBD_SHIFT)) & SMU_MRU_CH5_MB0_MBD_MASK)
/*! @} */

/*! @name CH5_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH5_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH5_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH5_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH5_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH5_MB1_MBD_SHIFT)) & SMU_MRU_CH5_MB1_MBD_MASK)
/*! @} */

/*! @name CH6_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH6_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH6_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH6_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH6_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH6_MB0_MBD_SHIFT)) & SMU_MRU_CH6_MB0_MBD_MASK)
/*! @} */

/*! @name CH6_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH6_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH6_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH6_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH6_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH6_MB1_MBD_SHIFT)) & SMU_MRU_CH6_MB1_MBD_MASK)
/*! @} */

/*! @name CH7_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH7_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH7_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH7_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH7_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH7_MB0_MBD_SHIFT)) & SMU_MRU_CH7_MB0_MBD_MASK)
/*! @} */

/*! @name CH7_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH7_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH7_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH7_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH7_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH7_MB1_MBD_SHIFT)) & SMU_MRU_CH7_MB1_MBD_MASK)
/*! @} */

/*! @name CH8_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH8_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH8_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH8_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH8_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH8_MB0_MBD_SHIFT)) & SMU_MRU_CH8_MB0_MBD_MASK)
/*! @} */

/*! @name CH8_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH8_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH8_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH8_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH8_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH8_MB1_MBD_SHIFT)) & SMU_MRU_CH8_MB1_MBD_MASK)
/*! @} */

/*! @name CH9_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH9_MB0_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH9_MB0_MBD_SHIFT                (0U)
#define SMU_MRU_CH9_MB0_MBD_WIDTH                (32U)
#define SMU_MRU_CH9_MB0_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH9_MB0_MBD_SHIFT)) & SMU_MRU_CH9_MB0_MBD_MASK)
/*! @} */

/*! @name CH9_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH9_MB1_MBD_MASK                 (0xFFFFFFFFU)
#define SMU_MRU_CH9_MB1_MBD_SHIFT                (0U)
#define SMU_MRU_CH9_MB1_MBD_WIDTH                (32U)
#define SMU_MRU_CH9_MB1_MBD(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH9_MB1_MBD_SHIFT)) & SMU_MRU_CH9_MB1_MBD_MASK)
/*! @} */

/*! @name CH10_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH10_MB0_MBD_MASK                (0xFFFFFFFFU)
#define SMU_MRU_CH10_MB0_MBD_SHIFT               (0U)
#define SMU_MRU_CH10_MB0_MBD_WIDTH               (32U)
#define SMU_MRU_CH10_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH10_MB0_MBD_SHIFT)) & SMU_MRU_CH10_MB0_MBD_MASK)
/*! @} */

/*! @name CH10_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH10_MB1_MBD_MASK                (0xFFFFFFFFU)
#define SMU_MRU_CH10_MB1_MBD_SHIFT               (0U)
#define SMU_MRU_CH10_MB1_MBD_WIDTH               (32U)
#define SMU_MRU_CH10_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH10_MB1_MBD_SHIFT)) & SMU_MRU_CH10_MB1_MBD_MASK)
/*! @} */

/*! @name CH11_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH11_MB0_MBD_MASK                (0xFFFFFFFFU)
#define SMU_MRU_CH11_MB0_MBD_SHIFT               (0U)
#define SMU_MRU_CH11_MB0_MBD_WIDTH               (32U)
#define SMU_MRU_CH11_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH11_MB0_MBD_SHIFT)) & SMU_MRU_CH11_MB0_MBD_MASK)
/*! @} */

/*! @name CH11_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH11_MB1_MBD_MASK                (0xFFFFFFFFU)
#define SMU_MRU_CH11_MB1_MBD_SHIFT               (0U)
#define SMU_MRU_CH11_MB1_MBD_WIDTH               (32U)
#define SMU_MRU_CH11_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH11_MB1_MBD_SHIFT)) & SMU_MRU_CH11_MB1_MBD_MASK)
/*! @} */

/*! @name CH12_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH12_MB0_MBD_MASK                (0xFFFFFFFFU)
#define SMU_MRU_CH12_MB0_MBD_SHIFT               (0U)
#define SMU_MRU_CH12_MB0_MBD_WIDTH               (32U)
#define SMU_MRU_CH12_MB0_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH12_MB0_MBD_SHIFT)) & SMU_MRU_CH12_MB0_MBD_MASK)
/*! @} */

/*! @name CH12_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define SMU_MRU_CH12_MB1_MBD_MASK                (0xFFFFFFFFU)
#define SMU_MRU_CH12_MB1_MBD_SHIFT               (0U)
#define SMU_MRU_CH12_MB1_MBD_WIDTH               (32U)
#define SMU_MRU_CH12_MB1_MBD(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_MRU_CH12_MB1_MBD_SHIFT)) & SMU_MRU_CH12_MB1_MBD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SMU_MRU_Register_Masks */

/*!
 * @}
 */ /* end of group SMU_MRU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SMU_MRU_H_) */
