/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ERM_GTM.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_ERM_GTM
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
#if !defined(S32Z2_ERM_GTM_H_)  /* Check if memory map has not been already included */
#define S32Z2_ERM_GTM_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ERM_GTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_GTM_Peripheral_Access_Layer ERM_GTM Peripheral Access Layer
 * @{
 */

/** ERM_GTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< ERM Configuration Register 0, offset: 0x0 */
  __IO uint32_t CR1;                               /**< ERM Configuration Register 1, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __IO uint32_t SR0;                               /**< ERM Status Register 0, offset: 0x10 */
  __IO uint32_t SR1;                               /**< ERM Status Register 1, offset: 0x14 */
  uint8_t RESERVED_1[232];
  __I  uint32_t EAR0;                              /**< ERM Memory 0 Error Address Register, offset: 0x100 */
  __I  uint32_t SYN0;                              /**< ERM Memory 0 Syndrome Register, offset: 0x104 */
  __IO uint32_t CORR_ERR_CNT0;                     /**< ERM Memory 0 Correctable Error Count Register, offset: 0x108 */
  uint8_t RESERVED_2[4];
  __I  uint32_t EAR1;                              /**< ERM Memory 1 Error Address Register, offset: 0x110 */
  __I  uint32_t SYN1;                              /**< ERM Memory 1 Syndrome Register, offset: 0x114 */
  __IO uint32_t CORR_ERR_CNT1;                     /**< ERM Memory 1 Correctable Error Count Register, offset: 0x118 */
  uint8_t RESERVED_3[4];
  __I  uint32_t EAR2;                              /**< ERM Memory 2 Error Address Register, offset: 0x120 */
  __I  uint32_t SYN2;                              /**< ERM Memory 2 Syndrome Register, offset: 0x124 */
  __IO uint32_t CORR_ERR_CNT2;                     /**< ERM Memory 2 Correctable Error Count Register, offset: 0x128 */
  uint8_t RESERVED_4[4];
  __I  uint32_t EAR3;                              /**< ERM Memory 3 Error Address Register, offset: 0x130 */
  __I  uint32_t SYN3;                              /**< ERM Memory 3 Syndrome Register, offset: 0x134 */
  __IO uint32_t CORR_ERR_CNT3;                     /**< ERM Memory 3 Correctable Error Count Register, offset: 0x138 */
  uint8_t RESERVED_5[4];
  __I  uint32_t EAR4;                              /**< ERM Memory 4 Error Address Register, offset: 0x140 */
  __I  uint32_t SYN4;                              /**< ERM Memory 4 Syndrome Register, offset: 0x144 */
  __IO uint32_t CORR_ERR_CNT4;                     /**< ERM Memory 4 Correctable Error Count Register, offset: 0x148 */
  uint8_t RESERVED_6[4];
  __I  uint32_t EAR5;                              /**< ERM Memory 5 Error Address Register, offset: 0x150 */
  __I  uint32_t SYN5;                              /**< ERM Memory 5 Syndrome Register, offset: 0x154 */
  __IO uint32_t CORR_ERR_CNT5;                     /**< ERM Memory 5 Correctable Error Count Register, offset: 0x158 */
  uint8_t RESERVED_7[4];
  __I  uint32_t EAR6;                              /**< ERM Memory 6 Error Address Register, offset: 0x160 */
  __I  uint32_t SYN6;                              /**< ERM Memory 6 Syndrome Register, offset: 0x164 */
  __IO uint32_t CORR_ERR_CNT6;                     /**< ERM Memory 6 Correctable Error Count Register, offset: 0x168 */
  uint8_t RESERVED_8[4];
  __I  uint32_t EAR7;                              /**< ERM Memory 7 Error Address Register, offset: 0x170 */
  __I  uint32_t SYN7;                              /**< ERM Memory 7 Syndrome Register, offset: 0x174 */
  __IO uint32_t CORR_ERR_CNT7;                     /**< ERM Memory 7 Correctable Error Count Register, offset: 0x178 */
  uint8_t RESERVED_9[4];
  __I  uint32_t EAR8;                              /**< ERM Memory 8 Error Address Register, offset: 0x180 */
  __I  uint32_t SYN8;                              /**< ERM Memory 8 Syndrome Register, offset: 0x184 */
  __IO uint32_t CORR_ERR_CNT8;                     /**< ERM Memory 8 Correctable Error Count Register, offset: 0x188 */
  uint8_t RESERVED_10[4];
  __I  uint32_t EAR9;                              /**< ERM Memory 9 Error Address Register, offset: 0x190 */
  __I  uint32_t SYN9;                              /**< ERM Memory 9 Syndrome Register, offset: 0x194 */
  __IO uint32_t CORR_ERR_CNT9;                     /**< ERM Memory 9 Correctable Error Count Register, offset: 0x198 */
  uint8_t RESERVED_11[4];
  __I  uint32_t EAR10;                             /**< ERM Memory 10 Error Address Register, offset: 0x1A0 */
  __I  uint32_t SYN10;                             /**< ERM Memory 10 Syndrome Register, offset: 0x1A4 */
  __IO uint32_t CORR_ERR_CNT10;                    /**< ERM Memory 10 Correctable Error Count Register, offset: 0x1A8 */
  uint8_t RESERVED_12[4];
  __I  uint32_t EAR11;                             /**< ERM Memory 11 Error Address Register, offset: 0x1B0 */
  __I  uint32_t SYN11;                             /**< ERM Memory 11 Syndrome Register, offset: 0x1B4 */
  __IO uint32_t CORR_ERR_CNT11;                    /**< ERM Memory 11 Correctable Error Count Register, offset: 0x1B8 */
} ERM_GTM_Type, *ERM_GTM_MemMapPtr;

/** Number of instances of the ERM_GTM module. */
#define ERM_GTM_INSTANCE_COUNT                   (1u)

/* ERM_GTM - Peripheral instance base addresses */
/** Peripheral ERM_GTM base address */
#define IP_ERM_GTM_BASE                          (0x40374000u)
/** Peripheral ERM_GTM base pointer */
#define IP_ERM_GTM                               ((ERM_GTM_Type *)IP_ERM_GTM_BASE)
/** Array initializer of ERM_GTM peripheral base addresses */
#define IP_ERM_GTM_BASE_ADDRS                    { IP_ERM_GTM_BASE }
/** Array initializer of ERM_GTM peripheral base pointers */
#define IP_ERM_GTM_BASE_PTRS                     { IP_ERM_GTM }

/* ----------------------------------------------------------------------------
   -- ERM_GTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_GTM_Register_Masks ERM_GTM Register Masks
 * @{
 */

/*! @name CR0 - ERM Configuration Register 0 */
/*! @{ */

#define ERM_GTM_CR0_ENCIE7_MASK                  (0x4U)
#define ERM_GTM_CR0_ENCIE7_SHIFT                 (2U)
#define ERM_GTM_CR0_ENCIE7_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE7(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE7_SHIFT)) & ERM_GTM_CR0_ENCIE7_MASK)

#define ERM_GTM_CR0_ESCIE7_MASK                  (0x8U)
#define ERM_GTM_CR0_ESCIE7_SHIFT                 (3U)
#define ERM_GTM_CR0_ESCIE7_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE7(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE7_SHIFT)) & ERM_GTM_CR0_ESCIE7_MASK)

#define ERM_GTM_CR0_ENCIE6_MASK                  (0x40U)
#define ERM_GTM_CR0_ENCIE6_SHIFT                 (6U)
#define ERM_GTM_CR0_ENCIE6_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE6(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE6_SHIFT)) & ERM_GTM_CR0_ENCIE6_MASK)

#define ERM_GTM_CR0_ESCIE6_MASK                  (0x80U)
#define ERM_GTM_CR0_ESCIE6_SHIFT                 (7U)
#define ERM_GTM_CR0_ESCIE6_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE6(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE6_SHIFT)) & ERM_GTM_CR0_ESCIE6_MASK)

#define ERM_GTM_CR0_ENCIE5_MASK                  (0x400U)
#define ERM_GTM_CR0_ENCIE5_SHIFT                 (10U)
#define ERM_GTM_CR0_ENCIE5_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE5(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE5_SHIFT)) & ERM_GTM_CR0_ENCIE5_MASK)

#define ERM_GTM_CR0_ESCIE5_MASK                  (0x800U)
#define ERM_GTM_CR0_ESCIE5_SHIFT                 (11U)
#define ERM_GTM_CR0_ESCIE5_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE5(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE5_SHIFT)) & ERM_GTM_CR0_ESCIE5_MASK)

#define ERM_GTM_CR0_ENCIE4_MASK                  (0x4000U)
#define ERM_GTM_CR0_ENCIE4_SHIFT                 (14U)
#define ERM_GTM_CR0_ENCIE4_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE4(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE4_SHIFT)) & ERM_GTM_CR0_ENCIE4_MASK)

#define ERM_GTM_CR0_ESCIE4_MASK                  (0x8000U)
#define ERM_GTM_CR0_ESCIE4_SHIFT                 (15U)
#define ERM_GTM_CR0_ESCIE4_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE4(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE4_SHIFT)) & ERM_GTM_CR0_ESCIE4_MASK)

#define ERM_GTM_CR0_ENCIE3_MASK                  (0x40000U)
#define ERM_GTM_CR0_ENCIE3_SHIFT                 (18U)
#define ERM_GTM_CR0_ENCIE3_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE3(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE3_SHIFT)) & ERM_GTM_CR0_ENCIE3_MASK)

#define ERM_GTM_CR0_ESCIE3_MASK                  (0x80000U)
#define ERM_GTM_CR0_ESCIE3_SHIFT                 (19U)
#define ERM_GTM_CR0_ESCIE3_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE3(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE3_SHIFT)) & ERM_GTM_CR0_ESCIE3_MASK)

#define ERM_GTM_CR0_ENCIE2_MASK                  (0x400000U)
#define ERM_GTM_CR0_ENCIE2_SHIFT                 (22U)
#define ERM_GTM_CR0_ENCIE2_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE2(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE2_SHIFT)) & ERM_GTM_CR0_ENCIE2_MASK)

#define ERM_GTM_CR0_ESCIE2_MASK                  (0x800000U)
#define ERM_GTM_CR0_ESCIE2_SHIFT                 (23U)
#define ERM_GTM_CR0_ESCIE2_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE2(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE2_SHIFT)) & ERM_GTM_CR0_ESCIE2_MASK)

#define ERM_GTM_CR0_ENCIE1_MASK                  (0x4000000U)
#define ERM_GTM_CR0_ENCIE1_SHIFT                 (26U)
#define ERM_GTM_CR0_ENCIE1_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE1(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE1_SHIFT)) & ERM_GTM_CR0_ENCIE1_MASK)

#define ERM_GTM_CR0_ESCIE1_MASK                  (0x8000000U)
#define ERM_GTM_CR0_ESCIE1_SHIFT                 (27U)
#define ERM_GTM_CR0_ESCIE1_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE1(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE1_SHIFT)) & ERM_GTM_CR0_ESCIE1_MASK)

#define ERM_GTM_CR0_ENCIE0_MASK                  (0x40000000U)
#define ERM_GTM_CR0_ENCIE0_SHIFT                 (30U)
#define ERM_GTM_CR0_ENCIE0_WIDTH                 (1U)
#define ERM_GTM_CR0_ENCIE0(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ENCIE0_SHIFT)) & ERM_GTM_CR0_ENCIE0_MASK)

#define ERM_GTM_CR0_ESCIE0_MASK                  (0x80000000U)
#define ERM_GTM_CR0_ESCIE0_SHIFT                 (31U)
#define ERM_GTM_CR0_ESCIE0_WIDTH                 (1U)
#define ERM_GTM_CR0_ESCIE0(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR0_ESCIE0_SHIFT)) & ERM_GTM_CR0_ESCIE0_MASK)
/*! @} */

/*! @name CR1 - ERM Configuration Register 1 */
/*! @{ */

#define ERM_GTM_CR1_ENCIE11_MASK                 (0x40000U)
#define ERM_GTM_CR1_ENCIE11_SHIFT                (18U)
#define ERM_GTM_CR1_ENCIE11_WIDTH                (1U)
#define ERM_GTM_CR1_ENCIE11(x)                   (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ENCIE11_SHIFT)) & ERM_GTM_CR1_ENCIE11_MASK)

#define ERM_GTM_CR1_ESCIE11_MASK                 (0x80000U)
#define ERM_GTM_CR1_ESCIE11_SHIFT                (19U)
#define ERM_GTM_CR1_ESCIE11_WIDTH                (1U)
#define ERM_GTM_CR1_ESCIE11(x)                   (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ESCIE11_SHIFT)) & ERM_GTM_CR1_ESCIE11_MASK)

#define ERM_GTM_CR1_ENCIE10_MASK                 (0x400000U)
#define ERM_GTM_CR1_ENCIE10_SHIFT                (22U)
#define ERM_GTM_CR1_ENCIE10_WIDTH                (1U)
#define ERM_GTM_CR1_ENCIE10(x)                   (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ENCIE10_SHIFT)) & ERM_GTM_CR1_ENCIE10_MASK)

#define ERM_GTM_CR1_ESCIE10_MASK                 (0x800000U)
#define ERM_GTM_CR1_ESCIE10_SHIFT                (23U)
#define ERM_GTM_CR1_ESCIE10_WIDTH                (1U)
#define ERM_GTM_CR1_ESCIE10(x)                   (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ESCIE10_SHIFT)) & ERM_GTM_CR1_ESCIE10_MASK)

#define ERM_GTM_CR1_ENCIE9_MASK                  (0x4000000U)
#define ERM_GTM_CR1_ENCIE9_SHIFT                 (26U)
#define ERM_GTM_CR1_ENCIE9_WIDTH                 (1U)
#define ERM_GTM_CR1_ENCIE9(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ENCIE9_SHIFT)) & ERM_GTM_CR1_ENCIE9_MASK)

#define ERM_GTM_CR1_ESCIE9_MASK                  (0x8000000U)
#define ERM_GTM_CR1_ESCIE9_SHIFT                 (27U)
#define ERM_GTM_CR1_ESCIE9_WIDTH                 (1U)
#define ERM_GTM_CR1_ESCIE9(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ESCIE9_SHIFT)) & ERM_GTM_CR1_ESCIE9_MASK)

#define ERM_GTM_CR1_ENCIE8_MASK                  (0x40000000U)
#define ERM_GTM_CR1_ENCIE8_SHIFT                 (30U)
#define ERM_GTM_CR1_ENCIE8_WIDTH                 (1U)
#define ERM_GTM_CR1_ENCIE8(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ENCIE8_SHIFT)) & ERM_GTM_CR1_ENCIE8_MASK)

#define ERM_GTM_CR1_ESCIE8_MASK                  (0x80000000U)
#define ERM_GTM_CR1_ESCIE8_SHIFT                 (31U)
#define ERM_GTM_CR1_ESCIE8_WIDTH                 (1U)
#define ERM_GTM_CR1_ESCIE8(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CR1_ESCIE8_SHIFT)) & ERM_GTM_CR1_ESCIE8_MASK)
/*! @} */

/*! @name SR0 - ERM Status Register 0 */
/*! @{ */

#define ERM_GTM_SR0_NCE7_MASK                    (0x4U)
#define ERM_GTM_SR0_NCE7_SHIFT                   (2U)
#define ERM_GTM_SR0_NCE7_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE7(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE7_SHIFT)) & ERM_GTM_SR0_NCE7_MASK)

#define ERM_GTM_SR0_SBC7_MASK                    (0x8U)
#define ERM_GTM_SR0_SBC7_SHIFT                   (3U)
#define ERM_GTM_SR0_SBC7_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC7(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC7_SHIFT)) & ERM_GTM_SR0_SBC7_MASK)

#define ERM_GTM_SR0_NCE6_MASK                    (0x40U)
#define ERM_GTM_SR0_NCE6_SHIFT                   (6U)
#define ERM_GTM_SR0_NCE6_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE6(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE6_SHIFT)) & ERM_GTM_SR0_NCE6_MASK)

#define ERM_GTM_SR0_SBC6_MASK                    (0x80U)
#define ERM_GTM_SR0_SBC6_SHIFT                   (7U)
#define ERM_GTM_SR0_SBC6_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC6(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC6_SHIFT)) & ERM_GTM_SR0_SBC6_MASK)

#define ERM_GTM_SR0_NCE5_MASK                    (0x400U)
#define ERM_GTM_SR0_NCE5_SHIFT                   (10U)
#define ERM_GTM_SR0_NCE5_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE5(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE5_SHIFT)) & ERM_GTM_SR0_NCE5_MASK)

#define ERM_GTM_SR0_SBC5_MASK                    (0x800U)
#define ERM_GTM_SR0_SBC5_SHIFT                   (11U)
#define ERM_GTM_SR0_SBC5_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC5(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC5_SHIFT)) & ERM_GTM_SR0_SBC5_MASK)

#define ERM_GTM_SR0_NCE4_MASK                    (0x4000U)
#define ERM_GTM_SR0_NCE4_SHIFT                   (14U)
#define ERM_GTM_SR0_NCE4_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE4(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE4_SHIFT)) & ERM_GTM_SR0_NCE4_MASK)

#define ERM_GTM_SR0_SBC4_MASK                    (0x8000U)
#define ERM_GTM_SR0_SBC4_SHIFT                   (15U)
#define ERM_GTM_SR0_SBC4_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC4(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC4_SHIFT)) & ERM_GTM_SR0_SBC4_MASK)

#define ERM_GTM_SR0_NCE3_MASK                    (0x40000U)
#define ERM_GTM_SR0_NCE3_SHIFT                   (18U)
#define ERM_GTM_SR0_NCE3_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE3(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE3_SHIFT)) & ERM_GTM_SR0_NCE3_MASK)

#define ERM_GTM_SR0_SBC3_MASK                    (0x80000U)
#define ERM_GTM_SR0_SBC3_SHIFT                   (19U)
#define ERM_GTM_SR0_SBC3_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC3(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC3_SHIFT)) & ERM_GTM_SR0_SBC3_MASK)

#define ERM_GTM_SR0_NCE2_MASK                    (0x400000U)
#define ERM_GTM_SR0_NCE2_SHIFT                   (22U)
#define ERM_GTM_SR0_NCE2_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE2(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE2_SHIFT)) & ERM_GTM_SR0_NCE2_MASK)

#define ERM_GTM_SR0_SBC2_MASK                    (0x800000U)
#define ERM_GTM_SR0_SBC2_SHIFT                   (23U)
#define ERM_GTM_SR0_SBC2_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC2(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC2_SHIFT)) & ERM_GTM_SR0_SBC2_MASK)

#define ERM_GTM_SR0_NCE1_MASK                    (0x4000000U)
#define ERM_GTM_SR0_NCE1_SHIFT                   (26U)
#define ERM_GTM_SR0_NCE1_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE1(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE1_SHIFT)) & ERM_GTM_SR0_NCE1_MASK)

#define ERM_GTM_SR0_SBC1_MASK                    (0x8000000U)
#define ERM_GTM_SR0_SBC1_SHIFT                   (27U)
#define ERM_GTM_SR0_SBC1_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC1(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC1_SHIFT)) & ERM_GTM_SR0_SBC1_MASK)

#define ERM_GTM_SR0_NCE0_MASK                    (0x40000000U)
#define ERM_GTM_SR0_NCE0_SHIFT                   (30U)
#define ERM_GTM_SR0_NCE0_WIDTH                   (1U)
#define ERM_GTM_SR0_NCE0(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_NCE0_SHIFT)) & ERM_GTM_SR0_NCE0_MASK)

#define ERM_GTM_SR0_SBC0_MASK                    (0x80000000U)
#define ERM_GTM_SR0_SBC0_SHIFT                   (31U)
#define ERM_GTM_SR0_SBC0_WIDTH                   (1U)
#define ERM_GTM_SR0_SBC0(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR0_SBC0_SHIFT)) & ERM_GTM_SR0_SBC0_MASK)
/*! @} */

/*! @name SR1 - ERM Status Register 1 */
/*! @{ */

#define ERM_GTM_SR1_NCE11_MASK                   (0x40000U)
#define ERM_GTM_SR1_NCE11_SHIFT                  (18U)
#define ERM_GTM_SR1_NCE11_WIDTH                  (1U)
#define ERM_GTM_SR1_NCE11(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_NCE11_SHIFT)) & ERM_GTM_SR1_NCE11_MASK)

#define ERM_GTM_SR1_SBC11_MASK                   (0x80000U)
#define ERM_GTM_SR1_SBC11_SHIFT                  (19U)
#define ERM_GTM_SR1_SBC11_WIDTH                  (1U)
#define ERM_GTM_SR1_SBC11(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_SBC11_SHIFT)) & ERM_GTM_SR1_SBC11_MASK)

#define ERM_GTM_SR1_NCE10_MASK                   (0x400000U)
#define ERM_GTM_SR1_NCE10_SHIFT                  (22U)
#define ERM_GTM_SR1_NCE10_WIDTH                  (1U)
#define ERM_GTM_SR1_NCE10(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_NCE10_SHIFT)) & ERM_GTM_SR1_NCE10_MASK)

#define ERM_GTM_SR1_SBC10_MASK                   (0x800000U)
#define ERM_GTM_SR1_SBC10_SHIFT                  (23U)
#define ERM_GTM_SR1_SBC10_WIDTH                  (1U)
#define ERM_GTM_SR1_SBC10(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_SBC10_SHIFT)) & ERM_GTM_SR1_SBC10_MASK)

#define ERM_GTM_SR1_NCE9_MASK                    (0x4000000U)
#define ERM_GTM_SR1_NCE9_SHIFT                   (26U)
#define ERM_GTM_SR1_NCE9_WIDTH                   (1U)
#define ERM_GTM_SR1_NCE9(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_NCE9_SHIFT)) & ERM_GTM_SR1_NCE9_MASK)

#define ERM_GTM_SR1_SBC9_MASK                    (0x8000000U)
#define ERM_GTM_SR1_SBC9_SHIFT                   (27U)
#define ERM_GTM_SR1_SBC9_WIDTH                   (1U)
#define ERM_GTM_SR1_SBC9(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_SBC9_SHIFT)) & ERM_GTM_SR1_SBC9_MASK)

#define ERM_GTM_SR1_NCE8_MASK                    (0x40000000U)
#define ERM_GTM_SR1_NCE8_SHIFT                   (30U)
#define ERM_GTM_SR1_NCE8_WIDTH                   (1U)
#define ERM_GTM_SR1_NCE8(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_NCE8_SHIFT)) & ERM_GTM_SR1_NCE8_MASK)

#define ERM_GTM_SR1_SBC8_MASK                    (0x80000000U)
#define ERM_GTM_SR1_SBC8_SHIFT                   (31U)
#define ERM_GTM_SR1_SBC8_WIDTH                   (1U)
#define ERM_GTM_SR1_SBC8(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SR1_SBC8_SHIFT)) & ERM_GTM_SR1_SBC8_MASK)
/*! @} */

/*! @name EAR0 - ERM Memory 0 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR0_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR0_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR0_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR0_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR0_EAR_SHIFT)) & ERM_GTM_EAR0_EAR_MASK)
/*! @} */

/*! @name SYN0 - ERM Memory 0 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN0_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN0_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN0_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN0_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN0_SYNDROME_SHIFT)) & ERM_GTM_SYN0_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT0 - ERM Memory 0 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT0_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT0_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT0_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT0_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT0_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT0_COUNT_MASK)
/*! @} */

/*! @name EAR1 - ERM Memory 1 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR1_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR1_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR1_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR1_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR1_EAR_SHIFT)) & ERM_GTM_EAR1_EAR_MASK)
/*! @} */

/*! @name SYN1 - ERM Memory 1 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN1_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN1_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN1_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN1_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN1_SYNDROME_SHIFT)) & ERM_GTM_SYN1_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT1 - ERM Memory 1 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT1_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT1_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT1_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT1_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT1_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT1_COUNT_MASK)
/*! @} */

/*! @name EAR2 - ERM Memory 2 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR2_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR2_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR2_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR2_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR2_EAR_SHIFT)) & ERM_GTM_EAR2_EAR_MASK)
/*! @} */

/*! @name SYN2 - ERM Memory 2 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN2_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN2_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN2_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN2_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN2_SYNDROME_SHIFT)) & ERM_GTM_SYN2_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT2 - ERM Memory 2 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT2_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT2_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT2_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT2_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT2_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT2_COUNT_MASK)
/*! @} */

/*! @name EAR3 - ERM Memory 3 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR3_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR3_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR3_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR3_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR3_EAR_SHIFT)) & ERM_GTM_EAR3_EAR_MASK)
/*! @} */

/*! @name SYN3 - ERM Memory 3 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN3_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN3_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN3_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN3_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN3_SYNDROME_SHIFT)) & ERM_GTM_SYN3_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT3 - ERM Memory 3 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT3_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT3_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT3_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT3_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT3_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT3_COUNT_MASK)
/*! @} */

/*! @name EAR4 - ERM Memory 4 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR4_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR4_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR4_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR4_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR4_EAR_SHIFT)) & ERM_GTM_EAR4_EAR_MASK)
/*! @} */

/*! @name SYN4 - ERM Memory 4 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN4_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN4_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN4_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN4_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN4_SYNDROME_SHIFT)) & ERM_GTM_SYN4_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT4 - ERM Memory 4 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT4_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT4_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT4_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT4_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT4_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT4_COUNT_MASK)
/*! @} */

/*! @name EAR5 - ERM Memory 5 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR5_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR5_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR5_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR5_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR5_EAR_SHIFT)) & ERM_GTM_EAR5_EAR_MASK)
/*! @} */

/*! @name SYN5 - ERM Memory 5 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN5_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN5_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN5_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN5_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN5_SYNDROME_SHIFT)) & ERM_GTM_SYN5_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT5 - ERM Memory 5 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT5_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT5_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT5_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT5_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT5_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT5_COUNT_MASK)
/*! @} */

/*! @name EAR6 - ERM Memory 6 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR6_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR6_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR6_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR6_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR6_EAR_SHIFT)) & ERM_GTM_EAR6_EAR_MASK)
/*! @} */

/*! @name SYN6 - ERM Memory 6 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN6_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN6_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN6_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN6_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN6_SYNDROME_SHIFT)) & ERM_GTM_SYN6_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT6 - ERM Memory 6 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT6_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT6_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT6_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT6_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT6_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT6_COUNT_MASK)
/*! @} */

/*! @name EAR7 - ERM Memory 7 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR7_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR7_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR7_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR7_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR7_EAR_SHIFT)) & ERM_GTM_EAR7_EAR_MASK)
/*! @} */

/*! @name SYN7 - ERM Memory 7 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN7_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN7_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN7_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN7_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN7_SYNDROME_SHIFT)) & ERM_GTM_SYN7_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT7 - ERM Memory 7 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT7_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT7_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT7_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT7_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT7_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT7_COUNT_MASK)
/*! @} */

/*! @name EAR8 - ERM Memory 8 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR8_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR8_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR8_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR8_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR8_EAR_SHIFT)) & ERM_GTM_EAR8_EAR_MASK)
/*! @} */

/*! @name SYN8 - ERM Memory 8 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN8_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN8_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN8_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN8_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN8_SYNDROME_SHIFT)) & ERM_GTM_SYN8_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT8 - ERM Memory 8 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT8_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT8_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT8_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT8_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT8_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT8_COUNT_MASK)
/*! @} */

/*! @name EAR9 - ERM Memory 9 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR9_EAR_MASK                    (0xFFFFFFFFU)
#define ERM_GTM_EAR9_EAR_SHIFT                   (0U)
#define ERM_GTM_EAR9_EAR_WIDTH                   (32U)
#define ERM_GTM_EAR9_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR9_EAR_SHIFT)) & ERM_GTM_EAR9_EAR_MASK)
/*! @} */

/*! @name SYN9 - ERM Memory 9 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN9_SYNDROME_MASK               (0xFF000000U)
#define ERM_GTM_SYN9_SYNDROME_SHIFT              (24U)
#define ERM_GTM_SYN9_SYNDROME_WIDTH              (8U)
#define ERM_GTM_SYN9_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN9_SYNDROME_SHIFT)) & ERM_GTM_SYN9_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT9 - ERM Memory 9 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT9_COUNT_MASK         (0xFFU)
#define ERM_GTM_CORR_ERR_CNT9_COUNT_SHIFT        (0U)
#define ERM_GTM_CORR_ERR_CNT9_COUNT_WIDTH        (8U)
#define ERM_GTM_CORR_ERR_CNT9_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT9_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT9_COUNT_MASK)
/*! @} */

/*! @name EAR10 - ERM Memory 10 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR10_EAR_MASK                   (0xFFFFFFFFU)
#define ERM_GTM_EAR10_EAR_SHIFT                  (0U)
#define ERM_GTM_EAR10_EAR_WIDTH                  (32U)
#define ERM_GTM_EAR10_EAR(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR10_EAR_SHIFT)) & ERM_GTM_EAR10_EAR_MASK)
/*! @} */

/*! @name SYN10 - ERM Memory 10 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN10_SYNDROME_MASK              (0xFF000000U)
#define ERM_GTM_SYN10_SYNDROME_SHIFT             (24U)
#define ERM_GTM_SYN10_SYNDROME_WIDTH             (8U)
#define ERM_GTM_SYN10_SYNDROME(x)                (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN10_SYNDROME_SHIFT)) & ERM_GTM_SYN10_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT10 - ERM Memory 10 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT10_COUNT_MASK        (0xFFU)
#define ERM_GTM_CORR_ERR_CNT10_COUNT_SHIFT       (0U)
#define ERM_GTM_CORR_ERR_CNT10_COUNT_WIDTH       (8U)
#define ERM_GTM_CORR_ERR_CNT10_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT10_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT10_COUNT_MASK)
/*! @} */

/*! @name EAR11 - ERM Memory 11 Error Address Register */
/*! @{ */

#define ERM_GTM_EAR11_EAR_MASK                   (0xFFFFFFFFU)
#define ERM_GTM_EAR11_EAR_SHIFT                  (0U)
#define ERM_GTM_EAR11_EAR_WIDTH                  (32U)
#define ERM_GTM_EAR11_EAR(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_GTM_EAR11_EAR_SHIFT)) & ERM_GTM_EAR11_EAR_MASK)
/*! @} */

/*! @name SYN11 - ERM Memory 11 Syndrome Register */
/*! @{ */

#define ERM_GTM_SYN11_SYNDROME_MASK              (0xFF000000U)
#define ERM_GTM_SYN11_SYNDROME_SHIFT             (24U)
#define ERM_GTM_SYN11_SYNDROME_WIDTH             (8U)
#define ERM_GTM_SYN11_SYNDROME(x)                (((uint32_t)(((uint32_t)(x)) << ERM_GTM_SYN11_SYNDROME_SHIFT)) & ERM_GTM_SYN11_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT11 - ERM Memory 11 Correctable Error Count Register */
/*! @{ */

#define ERM_GTM_CORR_ERR_CNT11_COUNT_MASK        (0xFFU)
#define ERM_GTM_CORR_ERR_CNT11_COUNT_SHIFT       (0U)
#define ERM_GTM_CORR_ERR_CNT11_COUNT_WIDTH       (8U)
#define ERM_GTM_CORR_ERR_CNT11_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << ERM_GTM_CORR_ERR_CNT11_COUNT_SHIFT)) & ERM_GTM_CORR_ERR_CNT11_COUNT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ERM_GTM_Register_Masks */

/*!
 * @}
 */ /* end of group ERM_GTM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ERM_GTM_H_) */
