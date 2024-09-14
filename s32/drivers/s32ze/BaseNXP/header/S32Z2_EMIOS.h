/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_eMIOS.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_eMIOS
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
#if !defined(S32Z2_eMIOS_H_)  /* Check if memory map has not been already included */
#define S32Z2_eMIOS_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- eMIOS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup eMIOS_Peripheral_Access_Layer eMIOS Peripheral Access Layer
 * @{
 */

/** eMIOS - Size of Registers Arrays */
#define eMIOS_CH_UC_UC_COUNT                      32u
#define eMIOS_CH_WSC_WSC_COUNT                    8u

/** eMIOS - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
  __I  uint32_t GFLAG;                             /**< Global Flag, offset: 0x4 */
  __IO uint32_t OUDIS;                             /**< Output Update Disable, offset: 0x8 */
  uint8_t RESERVED_0[20];
  union {                                          /* offset: 0x20 */
    struct eMIOS_CH_UC {                             /* offset: 0x20, array step: 0x20 */
      __IO uint32_t A;                                 /**< UC A 0..UC A 31, array offset: 0x20, array step: 0x20, valid indices: [0-7, 16-31] */
      __IO uint32_t B;                                 /**< UC B 0..UC B 31, array offset: 0x24, array step: 0x20, valid indices: [0-7, 16-31] */
      __IO uint32_t CNT;                               /**< UC Counter 0..UC Counter 31, array offset: 0x28, array step: 0x20, valid indices: [0-7, 16-31] */
      __IO uint32_t C;                                 /**< UC Control 0..UC Control 31, array offset: 0x2C, array step: 0x20, valid indices: [0-7, 16-31] */
      __IO uint32_t S;                                 /**< UC Status 0..UC Status 31, array offset: 0x30, array step: 0x20, valid indices: [0-7, 16-31] */
      __IO uint32_t ALTA;                              /**< Alternate Address 0..Alternate Address 31, array offset: 0x34, array step: 0x20, valid indices: [0-7, 16-31] */
      __IO uint32_t C2;                                /**< UC Control 2 0..UC Control 2 31, array offset: 0x38, array step: 0x20, valid indices: [0-7, 16-31] */
      uint8_t RESERVED_0[4];
    } UC[eMIOS_CH_UC_UC_COUNT];
    struct eMIOS_CH_WSC {                            /* offset: 0x20, array step: 0x40 */
      __IO uint32_t WSCAEC;                            /**< WSC Capture A and Event Counter 8..WSC Capture A and Event Counter 14, array offset: 0x20, array step: 0x40, valid indices: [4-7] */
      __I  uint32_t WSCAPB;                            /**< WSC Capture B 8..WSC Capture B 14, array offset: 0x24, array step: 0x40, valid indices: [4-7] */
      __IO uint32_t WSC1;                              /**< WSC Control 1 8..WSC Control 1 14, array offset: 0x28, array step: 0x40, valid indices: [4-7] */
      __IO uint32_t WSC2;                              /**< WSC Control 2 8..WSC Control 2 14, array offset: 0x2C, array step: 0x40, valid indices: [4-7] */
      __IO uint32_t WSS;                               /**< WSC Status 8..WSC Status 14, array offset: 0x30, array step: 0x40, valid indices: [4-7] */
      __IO uint32_t WSEV;                              /**< WSC Event 8..WSC Event 14, array offset: 0x34, array step: 0x40, valid indices: [4-7] */
      __I  uint32_t WSCEV;                             /**< WSC Capture Event 8..WSC Capture Event 14, array offset: 0x38, array step: 0x40, valid indices: [4-7] */
      __I  uint32_t WSPW;                              /**< WSC Pulse Width 8..WSC Pulse Width 14, array offset: 0x3C, array step: 0x40, valid indices: [4-7] */
      __IO uint32_t WSPWCNT;                           /**< WSC Pulse Width Counter 8..WSC Pulse Width Counter 14, array offset: 0x40, array step: 0x40, valid indices: [4-7] */
      __IO uint32_t WSFC;                              /**< WSC FIFO Control 8..WSC FIFO Control 14, array offset: 0x44, array step: 0x40, valid indices: [4-7] */
      __I  uint32_t WSFR;                              /**< WSC FIFO Read 8..WSC FIFO Read 14, array offset: 0x48, array step: 0x40, valid indices: [4-7] */
      __I  uint32_t WSFCNT;                            /**< WSC FIFO Counter 8..WSC FIFO Counter 14, array offset: 0x4C, array step: 0x40, valid indices: [4-7] */
      __I  uint32_t WSFPNT;                            /**< WSC FIFO Pointer 8..WSC FIFO Pointer 14, array offset: 0x50, array step: 0x40, valid indices: [4-7] */
      uint8_t RESERVED_0[12];
    } WSC[eMIOS_CH_WSC_WSC_COUNT];
  } CH;
} eMIOS_Type, *eMIOS_MemMapPtr;

/** Number of instances of the eMIOS module. */
#define eMIOS_INSTANCE_COUNT                     (2)

/* eMIOS - Peripheral instance base addresses */
/** Peripheral EMIOS_0 base address */
#define IP_EMIOS_0_BASE                          (0x420B0000u)
/** Peripheral EMIOS_0 base pointer */
#define IP_EMIOS_0                               ((eMIOS_Type *)IP_EMIOS_0_BASE)
/** Peripheral EMIOS_1 base address */
#define IP_EMIOS_1_BASE                          (0x400B0000u)
/** Peripheral EMIOS_1 base pointer */
#define IP_EMIOS_1                               ((eMIOS_Type *)IP_EMIOS_1_BASE)
/** Array initializer of eMIOS peripheral base addresses */
#define IP_eMIOS_BASE_ADDRS                      { IP_EMIOS_0_BASE, IP_EMIOS_1_BASE }
/** Array initializer of eMIOS peripheral base pointers */
#define IP_eMIOS_BASE_PTRS                       { IP_EMIOS_0, IP_EMIOS_1 }

/* ----------------------------------------------------------------------------
   -- eMIOS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup eMIOS_Register_Masks eMIOS Register Masks
 * @{
 */

/*! @name MCR - Module Configuration */
/*! @{ */

#define eMIOS_MCR_GPRE_MASK                      (0xFF00U)
#define eMIOS_MCR_GPRE_SHIFT                     (8U)
#define eMIOS_MCR_GPRE_WIDTH                     (8U)
#define eMIOS_MCR_GPRE(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_MCR_GPRE_SHIFT)) & eMIOS_MCR_GPRE_MASK)

#define eMIOS_MCR_GPREN_MASK                     (0x4000000U)
#define eMIOS_MCR_GPREN_SHIFT                    (26U)
#define eMIOS_MCR_GPREN_WIDTH                    (1U)
#define eMIOS_MCR_GPREN(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_MCR_GPREN_SHIFT)) & eMIOS_MCR_GPREN_MASK)

#define eMIOS_MCR_GTBE_MASK                      (0x10000000U)
#define eMIOS_MCR_GTBE_SHIFT                     (28U)
#define eMIOS_MCR_GTBE_WIDTH                     (1U)
#define eMIOS_MCR_GTBE(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_MCR_GTBE_SHIFT)) & eMIOS_MCR_GTBE_MASK)

#define eMIOS_MCR_FRZ_MASK                       (0x20000000U)
#define eMIOS_MCR_FRZ_SHIFT                      (29U)
#define eMIOS_MCR_FRZ_WIDTH                      (1U)
#define eMIOS_MCR_FRZ(x)                         (((uint32_t)(((uint32_t)(x)) << eMIOS_MCR_FRZ_SHIFT)) & eMIOS_MCR_FRZ_MASK)
/*! @} */

/*! @name GFLAG - Global Flag */
/*! @{ */

#define eMIOS_GFLAG_F0_MASK                      (0x1U)
#define eMIOS_GFLAG_F0_SHIFT                     (0U)
#define eMIOS_GFLAG_F0_WIDTH                     (1U)
#define eMIOS_GFLAG_F0(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F0_SHIFT)) & eMIOS_GFLAG_F0_MASK)

#define eMIOS_GFLAG_F1_MASK                      (0x2U)
#define eMIOS_GFLAG_F1_SHIFT                     (1U)
#define eMIOS_GFLAG_F1_WIDTH                     (1U)
#define eMIOS_GFLAG_F1(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F1_SHIFT)) & eMIOS_GFLAG_F1_MASK)

#define eMIOS_GFLAG_F2_MASK                      (0x4U)
#define eMIOS_GFLAG_F2_SHIFT                     (2U)
#define eMIOS_GFLAG_F2_WIDTH                     (1U)
#define eMIOS_GFLAG_F2(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F2_SHIFT)) & eMIOS_GFLAG_F2_MASK)

#define eMIOS_GFLAG_F3_MASK                      (0x8U)
#define eMIOS_GFLAG_F3_SHIFT                     (3U)
#define eMIOS_GFLAG_F3_WIDTH                     (1U)
#define eMIOS_GFLAG_F3(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F3_SHIFT)) & eMIOS_GFLAG_F3_MASK)

#define eMIOS_GFLAG_F4_MASK                      (0x10U)
#define eMIOS_GFLAG_F4_SHIFT                     (4U)
#define eMIOS_GFLAG_F4_WIDTH                     (1U)
#define eMIOS_GFLAG_F4(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F4_SHIFT)) & eMIOS_GFLAG_F4_MASK)

#define eMIOS_GFLAG_F5_MASK                      (0x20U)
#define eMIOS_GFLAG_F5_SHIFT                     (5U)
#define eMIOS_GFLAG_F5_WIDTH                     (1U)
#define eMIOS_GFLAG_F5(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F5_SHIFT)) & eMIOS_GFLAG_F5_MASK)

#define eMIOS_GFLAG_F6_MASK                      (0x40U)
#define eMIOS_GFLAG_F6_SHIFT                     (6U)
#define eMIOS_GFLAG_F6_WIDTH                     (1U)
#define eMIOS_GFLAG_F6(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F6_SHIFT)) & eMIOS_GFLAG_F6_MASK)

#define eMIOS_GFLAG_F7_MASK                      (0x80U)
#define eMIOS_GFLAG_F7_SHIFT                     (7U)
#define eMIOS_GFLAG_F7_WIDTH                     (1U)
#define eMIOS_GFLAG_F7(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F7_SHIFT)) & eMIOS_GFLAG_F7_MASK)

#define eMIOS_GFLAG_F8_MASK                      (0x100U)
#define eMIOS_GFLAG_F8_SHIFT                     (8U)
#define eMIOS_GFLAG_F8_WIDTH                     (1U)
#define eMIOS_GFLAG_F8(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F8_SHIFT)) & eMIOS_GFLAG_F8_MASK)

#define eMIOS_GFLAG_F9_MASK                      (0x200U)
#define eMIOS_GFLAG_F9_SHIFT                     (9U)
#define eMIOS_GFLAG_F9_WIDTH                     (1U)
#define eMIOS_GFLAG_F9(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F9_SHIFT)) & eMIOS_GFLAG_F9_MASK)

#define eMIOS_GFLAG_F10_MASK                     (0x400U)
#define eMIOS_GFLAG_F10_SHIFT                    (10U)
#define eMIOS_GFLAG_F10_WIDTH                    (1U)
#define eMIOS_GFLAG_F10(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F10_SHIFT)) & eMIOS_GFLAG_F10_MASK)

#define eMIOS_GFLAG_F11_MASK                     (0x800U)
#define eMIOS_GFLAG_F11_SHIFT                    (11U)
#define eMIOS_GFLAG_F11_WIDTH                    (1U)
#define eMIOS_GFLAG_F11(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F11_SHIFT)) & eMIOS_GFLAG_F11_MASK)

#define eMIOS_GFLAG_F12_MASK                     (0x1000U)
#define eMIOS_GFLAG_F12_SHIFT                    (12U)
#define eMIOS_GFLAG_F12_WIDTH                    (1U)
#define eMIOS_GFLAG_F12(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F12_SHIFT)) & eMIOS_GFLAG_F12_MASK)

#define eMIOS_GFLAG_F13_MASK                     (0x2000U)
#define eMIOS_GFLAG_F13_SHIFT                    (13U)
#define eMIOS_GFLAG_F13_WIDTH                    (1U)
#define eMIOS_GFLAG_F13(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F13_SHIFT)) & eMIOS_GFLAG_F13_MASK)

#define eMIOS_GFLAG_F14_MASK                     (0x4000U)
#define eMIOS_GFLAG_F14_SHIFT                    (14U)
#define eMIOS_GFLAG_F14_WIDTH                    (1U)
#define eMIOS_GFLAG_F14(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F14_SHIFT)) & eMIOS_GFLAG_F14_MASK)

#define eMIOS_GFLAG_F15_MASK                     (0x8000U)
#define eMIOS_GFLAG_F15_SHIFT                    (15U)
#define eMIOS_GFLAG_F15_WIDTH                    (1U)
#define eMIOS_GFLAG_F15(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F15_SHIFT)) & eMIOS_GFLAG_F15_MASK)

#define eMIOS_GFLAG_F16_MASK                     (0x10000U)
#define eMIOS_GFLAG_F16_SHIFT                    (16U)
#define eMIOS_GFLAG_F16_WIDTH                    (1U)
#define eMIOS_GFLAG_F16(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F16_SHIFT)) & eMIOS_GFLAG_F16_MASK)

#define eMIOS_GFLAG_F17_MASK                     (0x20000U)
#define eMIOS_GFLAG_F17_SHIFT                    (17U)
#define eMIOS_GFLAG_F17_WIDTH                    (1U)
#define eMIOS_GFLAG_F17(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F17_SHIFT)) & eMIOS_GFLAG_F17_MASK)

#define eMIOS_GFLAG_F18_MASK                     (0x40000U)
#define eMIOS_GFLAG_F18_SHIFT                    (18U)
#define eMIOS_GFLAG_F18_WIDTH                    (1U)
#define eMIOS_GFLAG_F18(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F18_SHIFT)) & eMIOS_GFLAG_F18_MASK)

#define eMIOS_GFLAG_F19_MASK                     (0x80000U)
#define eMIOS_GFLAG_F19_SHIFT                    (19U)
#define eMIOS_GFLAG_F19_WIDTH                    (1U)
#define eMIOS_GFLAG_F19(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F19_SHIFT)) & eMIOS_GFLAG_F19_MASK)

#define eMIOS_GFLAG_F20_MASK                     (0x100000U)
#define eMIOS_GFLAG_F20_SHIFT                    (20U)
#define eMIOS_GFLAG_F20_WIDTH                    (1U)
#define eMIOS_GFLAG_F20(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F20_SHIFT)) & eMIOS_GFLAG_F20_MASK)

#define eMIOS_GFLAG_F21_MASK                     (0x200000U)
#define eMIOS_GFLAG_F21_SHIFT                    (21U)
#define eMIOS_GFLAG_F21_WIDTH                    (1U)
#define eMIOS_GFLAG_F21(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F21_SHIFT)) & eMIOS_GFLAG_F21_MASK)

#define eMIOS_GFLAG_F22_MASK                     (0x400000U)
#define eMIOS_GFLAG_F22_SHIFT                    (22U)
#define eMIOS_GFLAG_F22_WIDTH                    (1U)
#define eMIOS_GFLAG_F22(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F22_SHIFT)) & eMIOS_GFLAG_F22_MASK)

#define eMIOS_GFLAG_F23_MASK                     (0x800000U)
#define eMIOS_GFLAG_F23_SHIFT                    (23U)
#define eMIOS_GFLAG_F23_WIDTH                    (1U)
#define eMIOS_GFLAG_F23(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F23_SHIFT)) & eMIOS_GFLAG_F23_MASK)

#define eMIOS_GFLAG_F24_MASK                     (0x1000000U)
#define eMIOS_GFLAG_F24_SHIFT                    (24U)
#define eMIOS_GFLAG_F24_WIDTH                    (1U)
#define eMIOS_GFLAG_F24(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F24_SHIFT)) & eMIOS_GFLAG_F24_MASK)

#define eMIOS_GFLAG_F25_MASK                     (0x2000000U)
#define eMIOS_GFLAG_F25_SHIFT                    (25U)
#define eMIOS_GFLAG_F25_WIDTH                    (1U)
#define eMIOS_GFLAG_F25(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F25_SHIFT)) & eMIOS_GFLAG_F25_MASK)

#define eMIOS_GFLAG_F26_MASK                     (0x4000000U)
#define eMIOS_GFLAG_F26_SHIFT                    (26U)
#define eMIOS_GFLAG_F26_WIDTH                    (1U)
#define eMIOS_GFLAG_F26(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F26_SHIFT)) & eMIOS_GFLAG_F26_MASK)

#define eMIOS_GFLAG_F27_MASK                     (0x8000000U)
#define eMIOS_GFLAG_F27_SHIFT                    (27U)
#define eMIOS_GFLAG_F27_WIDTH                    (1U)
#define eMIOS_GFLAG_F27(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F27_SHIFT)) & eMIOS_GFLAG_F27_MASK)

#define eMIOS_GFLAG_F28_MASK                     (0x10000000U)
#define eMIOS_GFLAG_F28_SHIFT                    (28U)
#define eMIOS_GFLAG_F28_WIDTH                    (1U)
#define eMIOS_GFLAG_F28(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F28_SHIFT)) & eMIOS_GFLAG_F28_MASK)

#define eMIOS_GFLAG_F29_MASK                     (0x20000000U)
#define eMIOS_GFLAG_F29_SHIFT                    (29U)
#define eMIOS_GFLAG_F29_WIDTH                    (1U)
#define eMIOS_GFLAG_F29(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F29_SHIFT)) & eMIOS_GFLAG_F29_MASK)

#define eMIOS_GFLAG_F30_MASK                     (0x40000000U)
#define eMIOS_GFLAG_F30_SHIFT                    (30U)
#define eMIOS_GFLAG_F30_WIDTH                    (1U)
#define eMIOS_GFLAG_F30(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F30_SHIFT)) & eMIOS_GFLAG_F30_MASK)

#define eMIOS_GFLAG_F31_MASK                     (0x80000000U)
#define eMIOS_GFLAG_F31_SHIFT                    (31U)
#define eMIOS_GFLAG_F31_WIDTH                    (1U)
#define eMIOS_GFLAG_F31(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_GFLAG_F31_SHIFT)) & eMIOS_GFLAG_F31_MASK)
/*! @} */

/*! @name OUDIS - Output Update Disable */
/*! @{ */

#define eMIOS_OUDIS_OU0_MASK                     (0x1U)
#define eMIOS_OUDIS_OU0_SHIFT                    (0U)
#define eMIOS_OUDIS_OU0_WIDTH                    (1U)
#define eMIOS_OUDIS_OU0(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU0_SHIFT)) & eMIOS_OUDIS_OU0_MASK)

#define eMIOS_OUDIS_OU1_MASK                     (0x2U)
#define eMIOS_OUDIS_OU1_SHIFT                    (1U)
#define eMIOS_OUDIS_OU1_WIDTH                    (1U)
#define eMIOS_OUDIS_OU1(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU1_SHIFT)) & eMIOS_OUDIS_OU1_MASK)

#define eMIOS_OUDIS_OU2_MASK                     (0x4U)
#define eMIOS_OUDIS_OU2_SHIFT                    (2U)
#define eMIOS_OUDIS_OU2_WIDTH                    (1U)
#define eMIOS_OUDIS_OU2(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU2_SHIFT)) & eMIOS_OUDIS_OU2_MASK)

#define eMIOS_OUDIS_OU3_MASK                     (0x8U)
#define eMIOS_OUDIS_OU3_SHIFT                    (3U)
#define eMIOS_OUDIS_OU3_WIDTH                    (1U)
#define eMIOS_OUDIS_OU3(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU3_SHIFT)) & eMIOS_OUDIS_OU3_MASK)

#define eMIOS_OUDIS_OU4_MASK                     (0x10U)
#define eMIOS_OUDIS_OU4_SHIFT                    (4U)
#define eMIOS_OUDIS_OU4_WIDTH                    (1U)
#define eMIOS_OUDIS_OU4(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU4_SHIFT)) & eMIOS_OUDIS_OU4_MASK)

#define eMIOS_OUDIS_OU5_MASK                     (0x20U)
#define eMIOS_OUDIS_OU5_SHIFT                    (5U)
#define eMIOS_OUDIS_OU5_WIDTH                    (1U)
#define eMIOS_OUDIS_OU5(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU5_SHIFT)) & eMIOS_OUDIS_OU5_MASK)

#define eMIOS_OUDIS_OU6_MASK                     (0x40U)
#define eMIOS_OUDIS_OU6_SHIFT                    (6U)
#define eMIOS_OUDIS_OU6_WIDTH                    (1U)
#define eMIOS_OUDIS_OU6(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU6_SHIFT)) & eMIOS_OUDIS_OU6_MASK)

#define eMIOS_OUDIS_OU7_MASK                     (0x80U)
#define eMIOS_OUDIS_OU7_SHIFT                    (7U)
#define eMIOS_OUDIS_OU7_WIDTH                    (1U)
#define eMIOS_OUDIS_OU7(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU7_SHIFT)) & eMIOS_OUDIS_OU7_MASK)

#define eMIOS_OUDIS_OU16_MASK                    (0x10000U)
#define eMIOS_OUDIS_OU16_SHIFT                   (16U)
#define eMIOS_OUDIS_OU16_WIDTH                   (1U)
#define eMIOS_OUDIS_OU16(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU16_SHIFT)) & eMIOS_OUDIS_OU16_MASK)

#define eMIOS_OUDIS_OU17_MASK                    (0x20000U)
#define eMIOS_OUDIS_OU17_SHIFT                   (17U)
#define eMIOS_OUDIS_OU17_WIDTH                   (1U)
#define eMIOS_OUDIS_OU17(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU17_SHIFT)) & eMIOS_OUDIS_OU17_MASK)

#define eMIOS_OUDIS_OU18_MASK                    (0x40000U)
#define eMIOS_OUDIS_OU18_SHIFT                   (18U)
#define eMIOS_OUDIS_OU18_WIDTH                   (1U)
#define eMIOS_OUDIS_OU18(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU18_SHIFT)) & eMIOS_OUDIS_OU18_MASK)

#define eMIOS_OUDIS_OU19_MASK                    (0x80000U)
#define eMIOS_OUDIS_OU19_SHIFT                   (19U)
#define eMIOS_OUDIS_OU19_WIDTH                   (1U)
#define eMIOS_OUDIS_OU19(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU19_SHIFT)) & eMIOS_OUDIS_OU19_MASK)

#define eMIOS_OUDIS_OU20_MASK                    (0x100000U)
#define eMIOS_OUDIS_OU20_SHIFT                   (20U)
#define eMIOS_OUDIS_OU20_WIDTH                   (1U)
#define eMIOS_OUDIS_OU20(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU20_SHIFT)) & eMIOS_OUDIS_OU20_MASK)

#define eMIOS_OUDIS_OU21_MASK                    (0x200000U)
#define eMIOS_OUDIS_OU21_SHIFT                   (21U)
#define eMIOS_OUDIS_OU21_WIDTH                   (1U)
#define eMIOS_OUDIS_OU21(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU21_SHIFT)) & eMIOS_OUDIS_OU21_MASK)

#define eMIOS_OUDIS_OU22_MASK                    (0x400000U)
#define eMIOS_OUDIS_OU22_SHIFT                   (22U)
#define eMIOS_OUDIS_OU22_WIDTH                   (1U)
#define eMIOS_OUDIS_OU22(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU22_SHIFT)) & eMIOS_OUDIS_OU22_MASK)

#define eMIOS_OUDIS_OU23_MASK                    (0x800000U)
#define eMIOS_OUDIS_OU23_SHIFT                   (23U)
#define eMIOS_OUDIS_OU23_WIDTH                   (1U)
#define eMIOS_OUDIS_OU23(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU23_SHIFT)) & eMIOS_OUDIS_OU23_MASK)

#define eMIOS_OUDIS_OU24_MASK                    (0x1000000U)
#define eMIOS_OUDIS_OU24_SHIFT                   (24U)
#define eMIOS_OUDIS_OU24_WIDTH                   (1U)
#define eMIOS_OUDIS_OU24(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU24_SHIFT)) & eMIOS_OUDIS_OU24_MASK)

#define eMIOS_OUDIS_OU25_MASK                    (0x2000000U)
#define eMIOS_OUDIS_OU25_SHIFT                   (25U)
#define eMIOS_OUDIS_OU25_WIDTH                   (1U)
#define eMIOS_OUDIS_OU25(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU25_SHIFT)) & eMIOS_OUDIS_OU25_MASK)

#define eMIOS_OUDIS_OU26_MASK                    (0x4000000U)
#define eMIOS_OUDIS_OU26_SHIFT                   (26U)
#define eMIOS_OUDIS_OU26_WIDTH                   (1U)
#define eMIOS_OUDIS_OU26(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU26_SHIFT)) & eMIOS_OUDIS_OU26_MASK)

#define eMIOS_OUDIS_OU27_MASK                    (0x8000000U)
#define eMIOS_OUDIS_OU27_SHIFT                   (27U)
#define eMIOS_OUDIS_OU27_WIDTH                   (1U)
#define eMIOS_OUDIS_OU27(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU27_SHIFT)) & eMIOS_OUDIS_OU27_MASK)

#define eMIOS_OUDIS_OU28_MASK                    (0x10000000U)
#define eMIOS_OUDIS_OU28_SHIFT                   (28U)
#define eMIOS_OUDIS_OU28_WIDTH                   (1U)
#define eMIOS_OUDIS_OU28(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU28_SHIFT)) & eMIOS_OUDIS_OU28_MASK)

#define eMIOS_OUDIS_OU29_MASK                    (0x20000000U)
#define eMIOS_OUDIS_OU29_SHIFT                   (29U)
#define eMIOS_OUDIS_OU29_WIDTH                   (1U)
#define eMIOS_OUDIS_OU29(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU29_SHIFT)) & eMIOS_OUDIS_OU29_MASK)

#define eMIOS_OUDIS_OU30_MASK                    (0x40000000U)
#define eMIOS_OUDIS_OU30_SHIFT                   (30U)
#define eMIOS_OUDIS_OU30_WIDTH                   (1U)
#define eMIOS_OUDIS_OU30(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU30_SHIFT)) & eMIOS_OUDIS_OU30_MASK)

#define eMIOS_OUDIS_OU31_MASK                    (0x80000000U)
#define eMIOS_OUDIS_OU31_SHIFT                   (31U)
#define eMIOS_OUDIS_OU31_WIDTH                   (1U)
#define eMIOS_OUDIS_OU31(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_OUDIS_OU31_SHIFT)) & eMIOS_OUDIS_OU31_MASK)
/*! @} */

/*! @name A - UC A 0..UC A 31 */
/*! @{ */

#define eMIOS_A_A_MASK                           (0xFFFFFFU)
#define eMIOS_A_A_SHIFT                          (0U)
#define eMIOS_A_A_WIDTH                          (24U)
#define eMIOS_A_A(x)                             (((uint32_t)(((uint32_t)(x)) << eMIOS_A_A_SHIFT)) & eMIOS_A_A_MASK)

#define eMIOS_A_RISE_FALL_MASK                   (0x80000000U)
#define eMIOS_A_RISE_FALL_SHIFT                  (31U)
#define eMIOS_A_RISE_FALL_WIDTH                  (1U)
#define eMIOS_A_RISE_FALL(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_A_RISE_FALL_SHIFT)) & eMIOS_A_RISE_FALL_MASK)
/*! @} */

/*! @name B - UC B 0..UC B 31 */
/*! @{ */

#define eMIOS_B_B_MASK                           (0xFFFFFFU)
#define eMIOS_B_B_SHIFT                          (0U)
#define eMIOS_B_B_WIDTH                          (24U)
#define eMIOS_B_B(x)                             (((uint32_t)(((uint32_t)(x)) << eMIOS_B_B_SHIFT)) & eMIOS_B_B_MASK)
/*! @} */

/*! @name CNT - UC Counter 0..UC Counter 31 */
/*! @{ */

#define eMIOS_CNT_C_MASK                         (0xFFFFFFU)
#define eMIOS_CNT_C_SHIFT                        (0U)
#define eMIOS_CNT_C_WIDTH                        (24U)
#define eMIOS_CNT_C(x)                           (((uint32_t)(((uint32_t)(x)) << eMIOS_CNT_C_SHIFT)) & eMIOS_CNT_C_MASK)
/*! @} */

/*! @name C - UC Control 0..UC Control 31 */
/*! @{ */

#define eMIOS_C_MODE_MASK                        (0x7FU)
#define eMIOS_C_MODE_SHIFT                       (0U)
#define eMIOS_C_MODE_WIDTH                       (7U)
#define eMIOS_C_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << eMIOS_C_MODE_SHIFT)) & eMIOS_C_MODE_MASK)

#define eMIOS_C_EDPOL_MASK                       (0x80U)
#define eMIOS_C_EDPOL_SHIFT                      (7U)
#define eMIOS_C_EDPOL_WIDTH                      (1U)
#define eMIOS_C_EDPOL(x)                         (((uint32_t)(((uint32_t)(x)) << eMIOS_C_EDPOL_SHIFT)) & eMIOS_C_EDPOL_MASK)

#define eMIOS_C_EDSEL_MASK                       (0x100U)
#define eMIOS_C_EDSEL_SHIFT                      (8U)
#define eMIOS_C_EDSEL_WIDTH                      (1U)
#define eMIOS_C_EDSEL(x)                         (((uint32_t)(((uint32_t)(x)) << eMIOS_C_EDSEL_SHIFT)) & eMIOS_C_EDSEL_MASK)

#define eMIOS_C_BSL_MASK                         (0x600U)
#define eMIOS_C_BSL_SHIFT                        (9U)
#define eMIOS_C_BSL_WIDTH                        (2U)
#define eMIOS_C_BSL(x)                           (((uint32_t)(((uint32_t)(x)) << eMIOS_C_BSL_SHIFT)) & eMIOS_C_BSL_MASK)

#define eMIOS_C_FORCMB_MASK                      (0x1000U)
#define eMIOS_C_FORCMB_SHIFT                     (12U)
#define eMIOS_C_FORCMB_WIDTH                     (1U)
#define eMIOS_C_FORCMB(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_C_FORCMB_SHIFT)) & eMIOS_C_FORCMB_MASK)

#define eMIOS_C_FORCMA_MASK                      (0x2000U)
#define eMIOS_C_FORCMA_SHIFT                     (13U)
#define eMIOS_C_FORCMA_WIDTH                     (1U)
#define eMIOS_C_FORCMA(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_C_FORCMA_SHIFT)) & eMIOS_C_FORCMA_MASK)

#define eMIOS_C_FEN_MASK                         (0x20000U)
#define eMIOS_C_FEN_SHIFT                        (17U)
#define eMIOS_C_FEN_WIDTH                        (1U)
#define eMIOS_C_FEN(x)                           (((uint32_t)(((uint32_t)(x)) << eMIOS_C_FEN_SHIFT)) & eMIOS_C_FEN_MASK)

#define eMIOS_C_FCK_MASK                         (0x40000U)
#define eMIOS_C_FCK_SHIFT                        (18U)
#define eMIOS_C_FCK_WIDTH                        (1U)
#define eMIOS_C_FCK(x)                           (((uint32_t)(((uint32_t)(x)) << eMIOS_C_FCK_SHIFT)) & eMIOS_C_FCK_MASK)

#define eMIOS_C_IF_MASK                          (0x780000U)
#define eMIOS_C_IF_SHIFT                         (19U)
#define eMIOS_C_IF_WIDTH                         (4U)
#define eMIOS_C_IF(x)                            (((uint32_t)(((uint32_t)(x)) << eMIOS_C_IF_SHIFT)) & eMIOS_C_IF_MASK)

#define eMIOS_C_DMA_MASK                         (0x1000000U)
#define eMIOS_C_DMA_SHIFT                        (24U)
#define eMIOS_C_DMA_WIDTH                        (1U)
#define eMIOS_C_DMA(x)                           (((uint32_t)(((uint32_t)(x)) << eMIOS_C_DMA_SHIFT)) & eMIOS_C_DMA_MASK)

#define eMIOS_C_UCPREN_MASK                      (0x2000000U)
#define eMIOS_C_UCPREN_SHIFT                     (25U)
#define eMIOS_C_UCPREN_WIDTH                     (1U)
#define eMIOS_C_UCPREN(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_C_UCPREN_SHIFT)) & eMIOS_C_UCPREN_MASK)

#define eMIOS_C_UCPRE_MASK                       (0xC000000U)
#define eMIOS_C_UCPRE_SHIFT                      (26U)
#define eMIOS_C_UCPRE_WIDTH                      (2U)
#define eMIOS_C_UCPRE(x)                         (((uint32_t)(((uint32_t)(x)) << eMIOS_C_UCPRE_SHIFT)) & eMIOS_C_UCPRE_MASK)

#define eMIOS_C_ODISSL_MASK                      (0x30000000U)
#define eMIOS_C_ODISSL_SHIFT                     (28U)
#define eMIOS_C_ODISSL_WIDTH                     (2U)
#define eMIOS_C_ODISSL(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_C_ODISSL_SHIFT)) & eMIOS_C_ODISSL_MASK)

#define eMIOS_C_ODIS_MASK                        (0x40000000U)
#define eMIOS_C_ODIS_SHIFT                       (30U)
#define eMIOS_C_ODIS_WIDTH                       (1U)
#define eMIOS_C_ODIS(x)                          (((uint32_t)(((uint32_t)(x)) << eMIOS_C_ODIS_SHIFT)) & eMIOS_C_ODIS_MASK)

#define eMIOS_C_FREN_MASK                        (0x80000000U)
#define eMIOS_C_FREN_SHIFT                       (31U)
#define eMIOS_C_FREN_WIDTH                       (1U)
#define eMIOS_C_FREN(x)                          (((uint32_t)(((uint32_t)(x)) << eMIOS_C_FREN_SHIFT)) & eMIOS_C_FREN_MASK)
/*! @} */

/*! @name S - UC Status 0..UC Status 31 */
/*! @{ */

#define eMIOS_S_FLAG_MASK                        (0x1U)
#define eMIOS_S_FLAG_SHIFT                       (0U)
#define eMIOS_S_FLAG_WIDTH                       (1U)
#define eMIOS_S_FLAG(x)                          (((uint32_t)(((uint32_t)(x)) << eMIOS_S_FLAG_SHIFT)) & eMIOS_S_FLAG_MASK)

#define eMIOS_S_UCOUT_MASK                       (0x2U)
#define eMIOS_S_UCOUT_SHIFT                      (1U)
#define eMIOS_S_UCOUT_WIDTH                      (1U)
#define eMIOS_S_UCOUT(x)                         (((uint32_t)(((uint32_t)(x)) << eMIOS_S_UCOUT_SHIFT)) & eMIOS_S_UCOUT_MASK)

#define eMIOS_S_UCIN_MASK                        (0x4U)
#define eMIOS_S_UCIN_SHIFT                       (2U)
#define eMIOS_S_UCIN_WIDTH                       (1U)
#define eMIOS_S_UCIN(x)                          (((uint32_t)(((uint32_t)(x)) << eMIOS_S_UCIN_SHIFT)) & eMIOS_S_UCIN_MASK)

#define eMIOS_S_OVFL_MASK                        (0x8000U)
#define eMIOS_S_OVFL_SHIFT                       (15U)
#define eMIOS_S_OVFL_WIDTH                       (1U)
#define eMIOS_S_OVFL(x)                          (((uint32_t)(((uint32_t)(x)) << eMIOS_S_OVFL_SHIFT)) & eMIOS_S_OVFL_MASK)

#define eMIOS_S_OVR_MASK                         (0x80000000U)
#define eMIOS_S_OVR_SHIFT                        (31U)
#define eMIOS_S_OVR_WIDTH                        (1U)
#define eMIOS_S_OVR(x)                           (((uint32_t)(((uint32_t)(x)) << eMIOS_S_OVR_SHIFT)) & eMIOS_S_OVR_MASK)
/*! @} */

/*! @name ALTA - Alternate Address 0..Alternate Address 31 */
/*! @{ */

#define eMIOS_ALTA_ALTA_MASK                     (0xFFFFFFU)
#define eMIOS_ALTA_ALTA_SHIFT                    (0U)
#define eMIOS_ALTA_ALTA_WIDTH                    (24U)
#define eMIOS_ALTA_ALTA(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_ALTA_ALTA_SHIFT)) & eMIOS_ALTA_ALTA_MASK)
/*! @} */

/*! @name C2 - UC Control 2 0..UC Control 2 31 */
/*! @{ */

#define eMIOS_C2_UCRELDEL_INT_MASK               (0x1FU)
#define eMIOS_C2_UCRELDEL_INT_SHIFT              (0U)
#define eMIOS_C2_UCRELDEL_INT_WIDTH              (5U)
#define eMIOS_C2_UCRELDEL_INT(x)                 (((uint32_t)(((uint32_t)(x)) << eMIOS_C2_UCRELDEL_INT_SHIFT)) & eMIOS_C2_UCRELDEL_INT_MASK)

#define eMIOS_C2_UCPRECLK_MASK                   (0x4000U)
#define eMIOS_C2_UCPRECLK_SHIFT                  (14U)
#define eMIOS_C2_UCPRECLK_WIDTH                  (1U)
#define eMIOS_C2_UCPRECLK(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_C2_UCPRECLK_SHIFT)) & eMIOS_C2_UCPRECLK_MASK)

#define eMIOS_C2_UCEXTPRE_MASK                   (0x3FFF0000U)
#define eMIOS_C2_UCEXTPRE_SHIFT                  (16U)
#define eMIOS_C2_UCEXTPRE_WIDTH                  (14U)
#define eMIOS_C2_UCEXTPRE(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_C2_UCEXTPRE_SHIFT)) & eMIOS_C2_UCEXTPRE_MASK)
/*! @} */

/*! @name WSCAEC - WSC Capture A and Event Counter 8..WSC Capture A and Event Counter 14 */
/*! @{ */

#define eMIOS_WSCAEC_T24CAPA_MASK                (0xFFFFFFU)
#define eMIOS_WSCAEC_T24CAPA_SHIFT               (0U)
#define eMIOS_WSCAEC_T24CAPA_WIDTH               (24U)
#define eMIOS_WSCAEC_T24CAPA(x)                  (((uint32_t)(((uint32_t)(x)) << eMIOS_WSCAEC_T24CAPA_SHIFT)) & eMIOS_WSCAEC_T24CAPA_MASK)

#define eMIOS_WSCAEC_EVCNT_MASK                  (0xFF000000U)
#define eMIOS_WSCAEC_EVCNT_SHIFT                 (24U)
#define eMIOS_WSCAEC_EVCNT_WIDTH                 (8U)
#define eMIOS_WSCAEC_EVCNT(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSCAEC_EVCNT_SHIFT)) & eMIOS_WSCAEC_EVCNT_MASK)
/*! @} */

/*! @name WSCAPB - WSC Capture B 8..WSC Capture B 14 */
/*! @{ */

#define eMIOS_WSCAPB_T24CAPB_MASK                (0xFFFFFFU)
#define eMIOS_WSCAPB_T24CAPB_SHIFT               (0U)
#define eMIOS_WSCAPB_T24CAPB_WIDTH               (24U)
#define eMIOS_WSCAPB_T24CAPB(x)                  (((uint32_t)(((uint32_t)(x)) << eMIOS_WSCAPB_T24CAPB_SHIFT)) & eMIOS_WSCAPB_T24CAPB_MASK)
/*! @} */

/*! @name WSC1 - WSC Control 1 8..WSC Control 1 14 */
/*! @{ */

#define eMIOS_WSC1_MODE_MASK                     (0x7FU)
#define eMIOS_WSC1_MODE_SHIFT                    (0U)
#define eMIOS_WSC1_MODE_WIDTH                    (7U)
#define eMIOS_WSC1_MODE(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_MODE_SHIFT)) & eMIOS_WSC1_MODE_MASK)

#define eMIOS_WSC1_EDPOLCAP_MASK                 (0x80U)
#define eMIOS_WSC1_EDPOLCAP_SHIFT                (7U)
#define eMIOS_WSC1_EDPOLCAP_WIDTH                (1U)
#define eMIOS_WSC1_EDPOLCAP(x)                   (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_EDPOLCAP_SHIFT)) & eMIOS_WSC1_EDPOLCAP_MASK)

#define eMIOS_WSC1_EDSELCAP_MASK                 (0x100U)
#define eMIOS_WSC1_EDSELCAP_SHIFT                (8U)
#define eMIOS_WSC1_EDSELCAP_WIDTH                (1U)
#define eMIOS_WSC1_EDSELCAP(x)                   (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_EDSELCAP_SHIFT)) & eMIOS_WSC1_EDSELCAP_MASK)

#define eMIOS_WSC1_BSL_MASK                      (0x600U)
#define eMIOS_WSC1_BSL_SHIFT                     (9U)
#define eMIOS_WSC1_BSL_WIDTH                     (2U)
#define eMIOS_WSC1_BSL(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_BSL_SHIFT)) & eMIOS_WSC1_BSL_MASK)

#define eMIOS_WSC1_FEN_MASK                      (0x20000U)
#define eMIOS_WSC1_FEN_SHIFT                     (17U)
#define eMIOS_WSC1_FEN_WIDTH                     (1U)
#define eMIOS_WSC1_FEN(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_FEN_SHIFT)) & eMIOS_WSC1_FEN_MASK)

#define eMIOS_WSC1_FCK_MASK                      (0x40000U)
#define eMIOS_WSC1_FCK_SHIFT                     (18U)
#define eMIOS_WSC1_FCK_WIDTH                     (1U)
#define eMIOS_WSC1_FCK(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_FCK_SHIFT)) & eMIOS_WSC1_FCK_MASK)

#define eMIOS_WSC1_IF0_3_MASK                    (0x780000U)
#define eMIOS_WSC1_IF0_3_SHIFT                   (19U)
#define eMIOS_WSC1_IF0_3_WIDTH                   (4U)
#define eMIOS_WSC1_IF0_3(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_IF0_3_SHIFT)) & eMIOS_WSC1_IF0_3_MASK)

#define eMIOS_WSC1_DMA_MASK                      (0x1000000U)
#define eMIOS_WSC1_DMA_SHIFT                     (24U)
#define eMIOS_WSC1_DMA_WIDTH                     (1U)
#define eMIOS_WSC1_DMA(x)                        (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_DMA_SHIFT)) & eMIOS_WSC1_DMA_MASK)

#define eMIOS_WSC1_CPREN_MASK                    (0x2000000U)
#define eMIOS_WSC1_CPREN_SHIFT                   (25U)
#define eMIOS_WSC1_CPREN_WIDTH                   (1U)
#define eMIOS_WSC1_CPREN(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_CPREN_SHIFT)) & eMIOS_WSC1_CPREN_MASK)

#define eMIOS_WSC1_IF4_7_MASK                    (0x3C000000U)
#define eMIOS_WSC1_IF4_7_SHIFT                   (26U)
#define eMIOS_WSC1_IF4_7_WIDTH                   (4U)
#define eMIOS_WSC1_IF4_7(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_IF4_7_SHIFT)) & eMIOS_WSC1_IF4_7_MASK)

#define eMIOS_WSC1_FREN_MASK                     (0x80000000U)
#define eMIOS_WSC1_FREN_SHIFT                    (31U)
#define eMIOS_WSC1_FREN_WIDTH                    (1U)
#define eMIOS_WSC1_FREN(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC1_FREN_SHIFT)) & eMIOS_WSC1_FREN_MASK)
/*! @} */

/*! @name WSC2 - WSC Control 2 8..WSC Control 2 14 */
/*! @{ */

#define eMIOS_WSC2_FLAGSEL_MASK                  (0x3FU)
#define eMIOS_WSC2_FLAGSEL_SHIFT                 (0U)
#define eMIOS_WSC2_FLAGSEL_WIDTH                 (6U)
#define eMIOS_WSC2_FLAGSEL(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC2_FLAGSEL_SHIFT)) & eMIOS_WSC2_FLAGSEL_MASK)

#define eMIOS_WSC2_EDPOLPW_MASK                  (0x80U)
#define eMIOS_WSC2_EDPOLPW_SHIFT                 (7U)
#define eMIOS_WSC2_EDPOLPW_WIDTH                 (1U)
#define eMIOS_WSC2_EDPOLPW(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC2_EDPOLPW_SHIFT)) & eMIOS_WSC2_EDPOLPW_MASK)

#define eMIOS_WSC2_EDSELPW_MASK                  (0x100U)
#define eMIOS_WSC2_EDSELPW_SHIFT                 (8U)
#define eMIOS_WSC2_EDSELPW_WIDTH                 (1U)
#define eMIOS_WSC2_EDSELPW(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC2_EDSELPW_SHIFT)) & eMIOS_WSC2_EDSELPW_MASK)

#define eMIOS_WSC2_PWREN_MASK                    (0x1000U)
#define eMIOS_WSC2_PWREN_SHIFT                   (12U)
#define eMIOS_WSC2_PWREN_WIDTH                   (1U)
#define eMIOS_WSC2_PWREN(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC2_PWREN_SHIFT)) & eMIOS_WSC2_PWREN_MASK)

#define eMIOS_WSC2_PWSWR_MASK                    (0x2000U)
#define eMIOS_WSC2_PWSWR_SHIFT                   (13U)
#define eMIOS_WSC2_PWSWR_WIDTH                   (1U)
#define eMIOS_WSC2_PWSWR(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC2_PWSWR_SHIFT)) & eMIOS_WSC2_PWSWR_MASK)

#define eMIOS_WSC2_WSPREMODE_MASK                (0x4000U)
#define eMIOS_WSC2_WSPREMODE_SHIFT               (14U)
#define eMIOS_WSC2_WSPREMODE_WIDTH               (1U)
#define eMIOS_WSC2_WSPREMODE(x)                  (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC2_WSPREMODE_SHIFT)) & eMIOS_WSC2_WSPREMODE_MASK)

#define eMIOS_WSC2_WSPRE_MASK                    (0xFFF0000U)
#define eMIOS_WSC2_WSPRE_SHIFT                   (16U)
#define eMIOS_WSC2_WSPRE_WIDTH                   (12U)
#define eMIOS_WSC2_WSPRE(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSC2_WSPRE_SHIFT)) & eMIOS_WSC2_WSPRE_MASK)
/*! @} */

/*! @name WSS - WSC Status 8..WSC Status 14 */
/*! @{ */

#define eMIOS_WSS_FLAGCE_MASK                    (0x1U)
#define eMIOS_WSS_FLAGCE_SHIFT                   (0U)
#define eMIOS_WSS_FLAGCE_WIDTH                   (1U)
#define eMIOS_WSS_FLAGCE(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGCE_SHIFT)) & eMIOS_WSS_FLAGCE_MASK)

#define eMIOS_WSS_FLAGECO_MASK                   (0x2U)
#define eMIOS_WSS_FLAGECO_SHIFT                  (1U)
#define eMIOS_WSS_FLAGECO_WIDTH                  (1U)
#define eMIOS_WSS_FLAGECO(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGECO_SHIFT)) & eMIOS_WSS_FLAGECO_MASK)

#define eMIOS_WSS_FLAGPW_MASK                    (0x4U)
#define eMIOS_WSS_FLAGPW_SHIFT                   (2U)
#define eMIOS_WSS_FLAGPW_WIDTH                   (1U)
#define eMIOS_WSS_FLAGPW(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGPW_SHIFT)) & eMIOS_WSS_FLAGPW_MASK)

#define eMIOS_WSS_FLAGCAP_MASK                   (0x8U)
#define eMIOS_WSS_FLAGCAP_SHIFT                  (3U)
#define eMIOS_WSS_FLAGCAP_WIDTH                  (1U)
#define eMIOS_WSS_FLAGCAP(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGCAP_SHIFT)) & eMIOS_WSS_FLAGCAP_MASK)

#define eMIOS_WSS_FLAGPWO_MASK                   (0x10U)
#define eMIOS_WSS_FLAGPWO_SHIFT                  (4U)
#define eMIOS_WSS_FLAGPWO_WIDTH                  (1U)
#define eMIOS_WSS_FLAGPWO(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGPWO_SHIFT)) & eMIOS_WSS_FLAGPWO_MASK)

#define eMIOS_WSS_FLAGFF_MASK                    (0x20U)
#define eMIOS_WSS_FLAGFF_SHIFT                   (5U)
#define eMIOS_WSS_FLAGFF_WIDTH                   (1U)
#define eMIOS_WSS_FLAGFF(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGFF_SHIFT)) & eMIOS_WSS_FLAGFF_MASK)

#define eMIOS_WSS_OVRCE_MASK                     (0x100U)
#define eMIOS_WSS_OVRCE_SHIFT                    (8U)
#define eMIOS_WSS_OVRCE_WIDTH                    (1U)
#define eMIOS_WSS_OVRCE(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRCE_SHIFT)) & eMIOS_WSS_OVRCE_MASK)

#define eMIOS_WSS_OVRECO_MASK                    (0x200U)
#define eMIOS_WSS_OVRECO_SHIFT                   (9U)
#define eMIOS_WSS_OVRECO_WIDTH                   (1U)
#define eMIOS_WSS_OVRECO(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRECO_SHIFT)) & eMIOS_WSS_OVRECO_MASK)

#define eMIOS_WSS_OVRPW_MASK                     (0x400U)
#define eMIOS_WSS_OVRPW_SHIFT                    (10U)
#define eMIOS_WSS_OVRPW_WIDTH                    (1U)
#define eMIOS_WSS_OVRPW(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRPW_SHIFT)) & eMIOS_WSS_OVRPW_MASK)

#define eMIOS_WSS_OVRCAP_MASK                    (0x800U)
#define eMIOS_WSS_OVRCAP_SHIFT                   (11U)
#define eMIOS_WSS_OVRCAP_WIDTH                   (1U)
#define eMIOS_WSS_OVRCAP(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRCAP_SHIFT)) & eMIOS_WSS_OVRCAP_MASK)

#define eMIOS_WSS_OVRPWO_MASK                    (0x1000U)
#define eMIOS_WSS_OVRPWO_SHIFT                   (12U)
#define eMIOS_WSS_OVRPWO_WIDTH                   (1U)
#define eMIOS_WSS_OVRPWO(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRPWO_SHIFT)) & eMIOS_WSS_OVRPWO_MASK)

#define eMIOS_WSS_WSCIN_MASK                     (0x8000U)
#define eMIOS_WSS_WSCIN_SHIFT                    (15U)
#define eMIOS_WSS_WSCIN_WIDTH                    (1U)
#define eMIOS_WSS_WSCIN(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_WSCIN_SHIFT)) & eMIOS_WSS_WSCIN_MASK)

#define eMIOS_WSS_FLAGCEC_MASK                   (0x10000U)
#define eMIOS_WSS_FLAGCEC_SHIFT                  (16U)
#define eMIOS_WSS_FLAGCEC_WIDTH                  (1U)
#define eMIOS_WSS_FLAGCEC(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGCEC_SHIFT)) & eMIOS_WSS_FLAGCEC_MASK)

#define eMIOS_WSS_FLAGECOC_MASK                  (0x20000U)
#define eMIOS_WSS_FLAGECOC_SHIFT                 (17U)
#define eMIOS_WSS_FLAGECOC_WIDTH                 (1U)
#define eMIOS_WSS_FLAGECOC(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGECOC_SHIFT)) & eMIOS_WSS_FLAGECOC_MASK)

#define eMIOS_WSS_FLAGPWC_MASK                   (0x40000U)
#define eMIOS_WSS_FLAGPWC_SHIFT                  (18U)
#define eMIOS_WSS_FLAGPWC_WIDTH                  (1U)
#define eMIOS_WSS_FLAGPWC(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGPWC_SHIFT)) & eMIOS_WSS_FLAGPWC_MASK)

#define eMIOS_WSS_FLAGCAPC_MASK                  (0x80000U)
#define eMIOS_WSS_FLAGCAPC_SHIFT                 (19U)
#define eMIOS_WSS_FLAGCAPC_WIDTH                 (1U)
#define eMIOS_WSS_FLAGCAPC(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGCAPC_SHIFT)) & eMIOS_WSS_FLAGCAPC_MASK)

#define eMIOS_WSS_FLAGPWOC_MASK                  (0x100000U)
#define eMIOS_WSS_FLAGPWOC_SHIFT                 (20U)
#define eMIOS_WSS_FLAGPWOC_WIDTH                 (1U)
#define eMIOS_WSS_FLAGPWOC(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGPWOC_SHIFT)) & eMIOS_WSS_FLAGPWOC_MASK)

#define eMIOS_WSS_FLAGFFC_MASK                   (0x200000U)
#define eMIOS_WSS_FLAGFFC_SHIFT                  (21U)
#define eMIOS_WSS_FLAGFFC_WIDTH                  (1U)
#define eMIOS_WSS_FLAGFFC(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_FLAGFFC_SHIFT)) & eMIOS_WSS_FLAGFFC_MASK)

#define eMIOS_WSS_OVRCEC_MASK                    (0x1000000U)
#define eMIOS_WSS_OVRCEC_SHIFT                   (24U)
#define eMIOS_WSS_OVRCEC_WIDTH                   (1U)
#define eMIOS_WSS_OVRCEC(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRCEC_SHIFT)) & eMIOS_WSS_OVRCEC_MASK)

#define eMIOS_WSS_OVRECOC_MASK                   (0x2000000U)
#define eMIOS_WSS_OVRECOC_SHIFT                  (25U)
#define eMIOS_WSS_OVRECOC_WIDTH                  (1U)
#define eMIOS_WSS_OVRECOC(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRECOC_SHIFT)) & eMIOS_WSS_OVRECOC_MASK)

#define eMIOS_WSS_OVRPWC_MASK                    (0x4000000U)
#define eMIOS_WSS_OVRPWC_SHIFT                   (26U)
#define eMIOS_WSS_OVRPWC_WIDTH                   (1U)
#define eMIOS_WSS_OVRPWC(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRPWC_SHIFT)) & eMIOS_WSS_OVRPWC_MASK)

#define eMIOS_WSS_OVRCAPC_MASK                   (0x8000000U)
#define eMIOS_WSS_OVRCAPC_SHIFT                  (27U)
#define eMIOS_WSS_OVRCAPC_WIDTH                  (1U)
#define eMIOS_WSS_OVRCAPC(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRCAPC_SHIFT)) & eMIOS_WSS_OVRCAPC_MASK)

#define eMIOS_WSS_OVRPWOC_MASK                   (0x10000000U)
#define eMIOS_WSS_OVRPWOC_SHIFT                  (28U)
#define eMIOS_WSS_OVRPWOC_WIDTH                  (1U)
#define eMIOS_WSS_OVRPWOC(x)                     (((uint32_t)(((uint32_t)(x)) << eMIOS_WSS_OVRPWOC_SHIFT)) & eMIOS_WSS_OVRPWOC_MASK)
/*! @} */

/*! @name WSEV - WSC Event 8..WSC Event 14 */
/*! @{ */

#define eMIOS_WSEV_EVENT_MASK                    (0xFFU)
#define eMIOS_WSEV_EVENT_SHIFT                   (0U)
#define eMIOS_WSEV_EVENT_WIDTH                   (8U)
#define eMIOS_WSEV_EVENT(x)                      (((uint32_t)(((uint32_t)(x)) << eMIOS_WSEV_EVENT_SHIFT)) & eMIOS_WSEV_EVENT_MASK)
/*! @} */

/*! @name WSCEV - WSC Capture Event 8..WSC Capture Event 14 */
/*! @{ */

#define eMIOS_WSCEV_T24CAPEV_MASK                (0xFFFFFFU)
#define eMIOS_WSCEV_T24CAPEV_SHIFT               (0U)
#define eMIOS_WSCEV_T24CAPEV_WIDTH               (24U)
#define eMIOS_WSCEV_T24CAPEV(x)                  (((uint32_t)(((uint32_t)(x)) << eMIOS_WSCEV_T24CAPEV_SHIFT)) & eMIOS_WSCEV_T24CAPEV_MASK)
/*! @} */

/*! @name WSPW - WSC Pulse Width 8..WSC Pulse Width 14 */
/*! @{ */

#define eMIOS_WSPW_T16PWCAP_MASK                 (0xFFFFU)
#define eMIOS_WSPW_T16PWCAP_SHIFT                (0U)
#define eMIOS_WSPW_T16PWCAP_WIDTH                (16U)
#define eMIOS_WSPW_T16PWCAP(x)                   (((uint32_t)(((uint32_t)(x)) << eMIOS_WSPW_T16PWCAP_SHIFT)) & eMIOS_WSPW_T16PWCAP_MASK)
/*! @} */

/*! @name WSPWCNT - WSC Pulse Width Counter 8..WSC Pulse Width Counter 14 */
/*! @{ */

#define eMIOS_WSPWCNT_T16PWCNT_MASK              (0xFFFFU)
#define eMIOS_WSPWCNT_T16PWCNT_SHIFT             (0U)
#define eMIOS_WSPWCNT_T16PWCNT_WIDTH             (16U)
#define eMIOS_WSPWCNT_T16PWCNT(x)                (((uint32_t)(((uint32_t)(x)) << eMIOS_WSPWCNT_T16PWCNT_SHIFT)) & eMIOS_WSPWCNT_T16PWCNT_MASK)
/*! @} */

/*! @name WSFC - WSC FIFO Control 8..WSC FIFO Control 14 */
/*! @{ */

#define eMIOS_WSFC_CLRF_MASK                     (0x1U)
#define eMIOS_WSFC_CLRF_SHIFT                    (0U)
#define eMIOS_WSFC_CLRF_WIDTH                    (1U)
#define eMIOS_WSFC_CLRF(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_WSFC_CLRF_SHIFT)) & eMIOS_WSFC_CLRF_MASK)

#define eMIOS_WSFC_FOOE_MASK                     (0x2U)
#define eMIOS_WSFC_FOOE_SHIFT                    (1U)
#define eMIOS_WSFC_FOOE_WIDTH                    (1U)
#define eMIOS_WSFC_FOOE(x)                       (((uint32_t)(((uint32_t)(x)) << eMIOS_WSFC_FOOE_SHIFT)) & eMIOS_WSFC_FOOE_MASK)
/*! @} */

/*! @name WSFR - WSC FIFO Read 8..WSC FIFO Read 14 */
/*! @{ */

#define eMIOS_WSFR_T24CAPA_T16PWD_VAL_MASK       (0xFFFFU)
#define eMIOS_WSFR_T24CAPA_T16PWD_VAL_SHIFT      (0U)
#define eMIOS_WSFR_T24CAPA_T16PWD_VAL_WIDTH      (16U)
#define eMIOS_WSFR_T24CAPA_T16PWD_VAL(x)         (((uint32_t)(((uint32_t)(x)) << eMIOS_WSFR_T24CAPA_T16PWD_VAL_SHIFT)) & eMIOS_WSFR_T24CAPA_T16PWD_VAL_MASK)

#define eMIOS_WSFR_E_MASK                        (0x10000U)
#define eMIOS_WSFR_E_SHIFT                       (16U)
#define eMIOS_WSFR_E_WIDTH                       (1U)
#define eMIOS_WSFR_E(x)                          (((uint32_t)(((uint32_t)(x)) << eMIOS_WSFR_E_SHIFT)) & eMIOS_WSFR_E_MASK)
/*! @} */

/*! @name WSFCNT - WSC FIFO Counter 8..WSC FIFO Counter 14 */
/*! @{ */

#define eMIOS_WSFCNT_FCNTR_MASK                  (0x1FU)
#define eMIOS_WSFCNT_FCNTR_SHIFT                 (0U)
#define eMIOS_WSFCNT_FCNTR_WIDTH                 (5U)
#define eMIOS_WSFCNT_FCNTR(x)                    (((uint32_t)(((uint32_t)(x)) << eMIOS_WSFCNT_FCNTR_SHIFT)) & eMIOS_WSFCNT_FCNTR_MASK)
/*! @} */

/*! @name WSFPNT - WSC FIFO Pointer 8..WSC FIFO Pointer 14 */
/*! @{ */

#define eMIOS_WSFPNT_FIFORDPT_MASK               (0xFU)
#define eMIOS_WSFPNT_FIFORDPT_SHIFT              (0U)
#define eMIOS_WSFPNT_FIFORDPT_WIDTH              (4U)
#define eMIOS_WSFPNT_FIFORDPT(x)                 (((uint32_t)(((uint32_t)(x)) << eMIOS_WSFPNT_FIFORDPT_SHIFT)) & eMIOS_WSFPNT_FIFORDPT_MASK)

#define eMIOS_WSFPNT_FIFOWRPT_MASK               (0xF0000U)
#define eMIOS_WSFPNT_FIFOWRPT_SHIFT              (16U)
#define eMIOS_WSFPNT_FIFOWRPT_WIDTH              (4U)
#define eMIOS_WSFPNT_FIFOWRPT(x)                 (((uint32_t)(((uint32_t)(x)) << eMIOS_WSFPNT_FIFOWRPT_SHIFT)) & eMIOS_WSFPNT_FIFOWRPT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group eMIOS_Register_Masks */

/*!
 * @}
 */ /* end of group eMIOS_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_eMIOS_H_) */
