/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ERM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_ERM.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for ERM
 *
 * CMSIS Peripheral Access Layer for ERM
 */

#if !defined(PERI_ERM_H_)
#define PERI_ERM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ERM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_Peripheral_Access_Layer ERM Peripheral Access Layer
 * @{
 */

/** ERM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< ERM Configuration Register 0, offset: 0x0 */
  __IO uint32_t CR1;                               /**< ERM Configuration Register 1, offset: 0x4 */
  __IO uint32_t CR2;                               /**< ERM Configuration Register 2, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SR0;                               /**< ERM Status Register 0, offset: 0x10 */
  __IO uint32_t SR1;                               /**< ERM Status Register 1, offset: 0x14 */
  __IO uint32_t SR2;                               /**< ERM Status Register 2, offset: 0x18 */
       uint8_t RESERVED_1[228];
  __I  uint32_t EAR0;                              /**< ERM Memory 0 Error Address Register, offset: 0x100 */
  __I  uint32_t SYN0;                              /**< ERM Memory 0 Syndrome Register, offset: 0x104 */
  __IO uint32_t CORR_ERR_CNT0;                     /**< ERM Memory 0 Correctable Error Count Register, offset: 0x108 */
       uint8_t RESERVED_2[28];
  __IO uint32_t CORR_ERR_CNT2;                     /**< ERM Memory 2 Correctable Error Count Register, offset: 0x128 */
       uint8_t RESERVED_3[12];
  __IO uint32_t CORR_ERR_CNT3;                     /**< ERM Memory 3 Correctable Error Count Register, offset: 0x138 */
       uint8_t RESERVED_4[12];
  __IO uint32_t CORR_ERR_CNT4;                     /**< ERM Memory 4 Correctable Error Count Register, offset: 0x148 */
       uint8_t RESERVED_5[12];
  __IO uint32_t CORR_ERR_CNT5;                     /**< ERM Memory 5 Correctable Error Count Register, offset: 0x158 */
       uint8_t RESERVED_6[68];
  __I  uint32_t EAR10;                             /**< ERM Memory 10 Error Address Register, offset: 0x1A0 */
  __I  uint32_t SYN10;                             /**< ERM Memory 10 Syndrome Register, offset: 0x1A4 */
  __IO uint32_t CORR_ERR_CNT10;                    /**< ERM Memory 10 Correctable Error Count Register, offset: 0x1A8 */
       uint8_t RESERVED_7[4];
  __I  uint32_t EAR11;                             /**< ERM Memory 11 Error Address Register, offset: 0x1B0 */
  __I  uint32_t SYN11;                             /**< ERM Memory 11 Syndrome Register, offset: 0x1B4 */
  __IO uint32_t CORR_ERR_CNT11;                    /**< ERM Memory 11 Correctable Error Count Register, offset: 0x1B8 */
       uint8_t RESERVED_8[4];
  __I  uint32_t EAR12;                             /**< ERM Memory 12 Error Address Register, offset: 0x1C0 */
  __I  uint32_t SYN12;                             /**< ERM Memory 12 Syndrome Register, offset: 0x1C4 */
  __IO uint32_t CORR_ERR_CNT12;                    /**< ERM Memory 12 Correctable Error Count Register, offset: 0x1C8 */
       uint8_t RESERVED_9[52];
  __I  uint32_t EAR16;                             /**< ERM Memory 16 Error Address Register, offset: 0x200 */
  __I  uint32_t SYN16;                             /**< ERM Memory 16 Syndrome Register, offset: 0x204 */
  __IO uint32_t CORR_ERR_CNT16;                    /**< ERM Memory 16 Correctable Error Count Register, offset: 0x208 */
       uint8_t RESERVED_10[4];
  __I  uint32_t EAR17;                             /**< ERM Memory 17 Error Address Register, offset: 0x210 */
       uint8_t RESERVED_11[4];
  __IO uint32_t CORR_ERR_CNT17;                    /**< ERM Memory 17 Correctable Error Count Register, offset: 0x218 */
       uint8_t RESERVED_12[4];
  __I  uint32_t EAR18;                             /**< ERM Memory 18 Error Address Register, offset: 0x220 */
       uint8_t RESERVED_13[4];
  __IO uint32_t CORR_ERR_CNT18;                    /**< ERM Memory 18 Correctable Error Count Register, offset: 0x228 */
} ERM_Type;

/* ----------------------------------------------------------------------------
   -- ERM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_Register_Masks ERM Register Masks
 * @{
 */

/*! @name CR0 - ERM Configuration Register 0 */
/*! @{ */

#define ERM_CR0_ENCIE5_MASK                      (0x400U)
#define ERM_CR0_ENCIE5_SHIFT                     (10U)
/*! ENCIE5 - ENCIE5
 *  0b0..Interrupt notification of Memory 5 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 5 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE5(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE5_SHIFT)) & ERM_CR0_ENCIE5_MASK)

#define ERM_CR0_ESCIE5_MASK                      (0x800U)
#define ERM_CR0_ESCIE5_SHIFT                     (11U)
/*! ESCIE5 - ESCIE5
 *  0b0..Interrupt notification of Memory 5 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 5 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE5(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE5_SHIFT)) & ERM_CR0_ESCIE5_MASK)

#define ERM_CR0_ENCIE4_MASK                      (0x4000U)
#define ERM_CR0_ENCIE4_SHIFT                     (14U)
/*! ENCIE4 - ENCIE4
 *  0b0..Interrupt notification of Memory 4 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 4 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE4(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE4_SHIFT)) & ERM_CR0_ENCIE4_MASK)

#define ERM_CR0_ESCIE4_MASK                      (0x8000U)
#define ERM_CR0_ESCIE4_SHIFT                     (15U)
/*! ESCIE4 - ESCIE4
 *  0b0..Interrupt notification of Memory 4 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 4 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE4(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE4_SHIFT)) & ERM_CR0_ESCIE4_MASK)

#define ERM_CR0_ENCIE3_MASK                      (0x40000U)
#define ERM_CR0_ENCIE3_SHIFT                     (18U)
/*! ENCIE3 - ENCIE3
 *  0b0..Interrupt notification of Memory 3 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 3 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE3(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE3_SHIFT)) & ERM_CR0_ENCIE3_MASK)

#define ERM_CR0_ESCIE3_MASK                      (0x80000U)
#define ERM_CR0_ESCIE3_SHIFT                     (19U)
/*! ESCIE3 - ESCIE3
 *  0b0..Interrupt notification of Memory 3 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 3 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE3(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE3_SHIFT)) & ERM_CR0_ESCIE3_MASK)

#define ERM_CR0_ENCIE2_MASK                      (0x400000U)
#define ERM_CR0_ENCIE2_SHIFT                     (22U)
/*! ENCIE2 - ENCIE2
 *  0b0..Interrupt notification of Memory 2 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 2 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE2(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE2_SHIFT)) & ERM_CR0_ENCIE2_MASK)

#define ERM_CR0_ESCIE2_MASK                      (0x800000U)
#define ERM_CR0_ESCIE2_SHIFT                     (23U)
/*! ESCIE2 - ESCIE2
 *  0b0..Interrupt notification of Memory 2 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 2 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE2(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE2_SHIFT)) & ERM_CR0_ESCIE2_MASK)

#define ERM_CR0_ENCIE0_MASK                      (0x40000000U)
#define ERM_CR0_ENCIE0_SHIFT                     (30U)
/*! ENCIE0 - ENCIE0
 *  0b0..Interrupt notification of Memory 0 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 0 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE0(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE0_SHIFT)) & ERM_CR0_ENCIE0_MASK)

#define ERM_CR0_ESCIE0_MASK                      (0x80000000U)
#define ERM_CR0_ESCIE0_SHIFT                     (31U)
/*! ESCIE0 - ESCIE0
 *  0b0..Interrupt notification of Memory 0 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 0 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE0(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE0_SHIFT)) & ERM_CR0_ESCIE0_MASK)
/*! @} */

/*! @name CR1 - ERM Configuration Register 1 */
/*! @{ */

#define ERM_CR1_ENCIE12_MASK                     (0x4000U)
#define ERM_CR1_ENCIE12_SHIFT                    (14U)
/*! ENCIE12 - ENCIE12
 *  0b0..Interrupt notification of Memory 12 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 12 non-correctable error events is enabled.
 */
#define ERM_CR1_ENCIE12(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR1_ENCIE12_SHIFT)) & ERM_CR1_ENCIE12_MASK)

#define ERM_CR1_ESCIE12_MASK                     (0x8000U)
#define ERM_CR1_ESCIE12_SHIFT                    (15U)
/*! ESCIE12 - ESCIE12
 *  0b0..Interrupt notification of Memory 12 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 12 single-bit correction events is enabled.
 */
#define ERM_CR1_ESCIE12(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR1_ESCIE12_SHIFT)) & ERM_CR1_ESCIE12_MASK)

#define ERM_CR1_ENCIE11_MASK                     (0x40000U)
#define ERM_CR1_ENCIE11_SHIFT                    (18U)
/*! ENCIE11 - ENCIE11
 *  0b0..Interrupt notification of Memory 11 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 11 non-correctable error events is enabled.
 */
#define ERM_CR1_ENCIE11(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR1_ENCIE11_SHIFT)) & ERM_CR1_ENCIE11_MASK)

#define ERM_CR1_ESCIE11_MASK                     (0x80000U)
#define ERM_CR1_ESCIE11_SHIFT                    (19U)
/*! ESCIE11 - ESCIE11
 *  0b0..Interrupt notification of Memory 11 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 11 single-bit correction events is enabled.
 */
#define ERM_CR1_ESCIE11(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR1_ESCIE11_SHIFT)) & ERM_CR1_ESCIE11_MASK)

#define ERM_CR1_ENCIE10_MASK                     (0x400000U)
#define ERM_CR1_ENCIE10_SHIFT                    (22U)
/*! ENCIE10 - ENCIE10
 *  0b0..Interrupt notification of Memory 10 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 10 non-correctable error events is enabled.
 */
#define ERM_CR1_ENCIE10(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR1_ENCIE10_SHIFT)) & ERM_CR1_ENCIE10_MASK)

#define ERM_CR1_ESCIE10_MASK                     (0x800000U)
#define ERM_CR1_ESCIE10_SHIFT                    (23U)
/*! ESCIE10 - ESCIE10
 *  0b0..Interrupt notification of Memory 10 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 10 single-bit correction events is enabled.
 */
#define ERM_CR1_ESCIE10(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR1_ESCIE10_SHIFT)) & ERM_CR1_ESCIE10_MASK)
/*! @} */

/*! @name CR2 - ERM Configuration Register 2 */
/*! @{ */

#define ERM_CR2_ENCIE18_MASK                     (0x400000U)
#define ERM_CR2_ENCIE18_SHIFT                    (22U)
/*! ENCIE18 - ENCIE18
 *  0b0..Interrupt notification of Memory 18 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 18 non-correctable error events is enabled.
 */
#define ERM_CR2_ENCIE18(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR2_ENCIE18_SHIFT)) & ERM_CR2_ENCIE18_MASK)

#define ERM_CR2_ESCIE18_MASK                     (0x800000U)
#define ERM_CR2_ESCIE18_SHIFT                    (23U)
/*! ESCIE18 - ESCIE18
 *  0b0..Interrupt notification of Memory 18 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 18 single-bit correction events is enabled.
 */
#define ERM_CR2_ESCIE18(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR2_ESCIE18_SHIFT)) & ERM_CR2_ESCIE18_MASK)

#define ERM_CR2_ENCIE17_MASK                     (0x4000000U)
#define ERM_CR2_ENCIE17_SHIFT                    (26U)
/*! ENCIE17 - ENCIE17
 *  0b0..Interrupt notification of Memory 17 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 17 non-correctable error events is enabled.
 */
#define ERM_CR2_ENCIE17(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR2_ENCIE17_SHIFT)) & ERM_CR2_ENCIE17_MASK)

#define ERM_CR2_ESCIE17_MASK                     (0x8000000U)
#define ERM_CR2_ESCIE17_SHIFT                    (27U)
/*! ESCIE17 - ESCIE17
 *  0b0..Interrupt notification of Memory 17 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 17 single-bit correction events is enabled.
 */
#define ERM_CR2_ESCIE17(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR2_ESCIE17_SHIFT)) & ERM_CR2_ESCIE17_MASK)

#define ERM_CR2_ENCIE16_MASK                     (0x40000000U)
#define ERM_CR2_ENCIE16_SHIFT                    (30U)
/*! ENCIE16 - ENCIE16
 *  0b0..Interrupt notification of Memory 16 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 16 non-correctable error events is enabled.
 */
#define ERM_CR2_ENCIE16(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR2_ENCIE16_SHIFT)) & ERM_CR2_ENCIE16_MASK)

#define ERM_CR2_ESCIE16_MASK                     (0x80000000U)
#define ERM_CR2_ESCIE16_SHIFT                    (31U)
/*! ESCIE16 - ESCIE16
 *  0b0..Interrupt notification of Memory 16 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 16 single-bit correction events is enabled.
 */
#define ERM_CR2_ESCIE16(x)                       (((uint32_t)(((uint32_t)(x)) << ERM_CR2_ESCIE16_SHIFT)) & ERM_CR2_ESCIE16_MASK)
/*! @} */

/*! @name SR0 - ERM Status Register 0 */
/*! @{ */

#define ERM_SR0_NCE5_MASK                        (0x400U)
#define ERM_SR0_NCE5_SHIFT                       (10U)
/*! NCE5 - NCE5
 *  0b0..No non-correctable error event on Memory 5 detected.
 *  0b1..Non-correctable error event on Memory 5 detected.
 */
#define ERM_SR0_NCE5(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE5_SHIFT)) & ERM_SR0_NCE5_MASK)

#define ERM_SR0_SBC5_MASK                        (0x800U)
#define ERM_SR0_SBC5_SHIFT                       (11U)
/*! SBC5 - SBC5
 *  0b0..No single-bit correction event on Memory 5 detected.
 *  0b1..Single-bit correction event on Memory 5 detected.
 */
#define ERM_SR0_SBC5(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC5_SHIFT)) & ERM_SR0_SBC5_MASK)

#define ERM_SR0_NCE4_MASK                        (0x4000U)
#define ERM_SR0_NCE4_SHIFT                       (14U)
/*! NCE4 - NCE4
 *  0b0..No non-correctable error event on Memory 4 detected.
 *  0b1..Non-correctable error event on Memory 4 detected.
 */
#define ERM_SR0_NCE4(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE4_SHIFT)) & ERM_SR0_NCE4_MASK)

#define ERM_SR0_SBC4_MASK                        (0x8000U)
#define ERM_SR0_SBC4_SHIFT                       (15U)
/*! SBC4 - SBC4
 *  0b0..No single-bit correction event on Memory 4 detected.
 *  0b1..Single-bit correction event on Memory 4 detected.
 */
#define ERM_SR0_SBC4(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC4_SHIFT)) & ERM_SR0_SBC4_MASK)

#define ERM_SR0_NCE3_MASK                        (0x40000U)
#define ERM_SR0_NCE3_SHIFT                       (18U)
/*! NCE3 - NCE3
 *  0b0..No non-correctable error event on Memory 3 detected.
 *  0b1..Non-correctable error event on Memory 3 detected.
 */
#define ERM_SR0_NCE3(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE3_SHIFT)) & ERM_SR0_NCE3_MASK)

#define ERM_SR0_SBC3_MASK                        (0x80000U)
#define ERM_SR0_SBC3_SHIFT                       (19U)
/*! SBC3 - SBC3
 *  0b0..No single-bit correction event on Memory 3 detected.
 *  0b1..Single-bit correction event on Memory 3 detected.
 */
#define ERM_SR0_SBC3(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC3_SHIFT)) & ERM_SR0_SBC3_MASK)

#define ERM_SR0_NCE2_MASK                        (0x400000U)
#define ERM_SR0_NCE2_SHIFT                       (22U)
/*! NCE2 - NCE2
 *  0b0..No non-correctable error event on Memory 2 detected.
 *  0b1..Non-correctable error event on Memory 2 detected.
 */
#define ERM_SR0_NCE2(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE2_SHIFT)) & ERM_SR0_NCE2_MASK)

#define ERM_SR0_SBC2_MASK                        (0x800000U)
#define ERM_SR0_SBC2_SHIFT                       (23U)
/*! SBC2 - SBC2
 *  0b0..No single-bit correction event on Memory 2 detected.
 *  0b1..Single-bit correction event on Memory 2 detected.
 */
#define ERM_SR0_SBC2(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC2_SHIFT)) & ERM_SR0_SBC2_MASK)

#define ERM_SR0_NCE0_MASK                        (0x40000000U)
#define ERM_SR0_NCE0_SHIFT                       (30U)
/*! NCE0 - NCE0
 *  0b0..No non-correctable error event on Memory 0 detected.
 *  0b1..Non-correctable error event on Memory 0 detected.
 */
#define ERM_SR0_NCE0(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE0_SHIFT)) & ERM_SR0_NCE0_MASK)

#define ERM_SR0_SBC0_MASK                        (0x80000000U)
#define ERM_SR0_SBC0_SHIFT                       (31U)
/*! SBC0 - SBC0
 *  0b0..No single-bit correction event on Memory 0 detected.
 *  0b1..Single-bit correction event on Memory 0 detected.
 */
#define ERM_SR0_SBC0(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC0_SHIFT)) & ERM_SR0_SBC0_MASK)
/*! @} */

/*! @name SR1 - ERM Status Register 1 */
/*! @{ */

#define ERM_SR1_NCE12_MASK                       (0x4000U)
#define ERM_SR1_NCE12_SHIFT                      (14U)
/*! NCE12 - NCE12
 *  0b0..No non-correctable error event on Memory 12 detected.
 *  0b1..Non-correctable error event on Memory 12 detected.
 */
#define ERM_SR1_NCE12(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR1_NCE12_SHIFT)) & ERM_SR1_NCE12_MASK)

#define ERM_SR1_SBC12_MASK                       (0x8000U)
#define ERM_SR1_SBC12_SHIFT                      (15U)
/*! SBC12 - SBC12
 *  0b0..No single-bit correction event on Memory 12 detected.
 *  0b1..Single-bit correction event on Memory 12 detected.
 */
#define ERM_SR1_SBC12(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR1_SBC12_SHIFT)) & ERM_SR1_SBC12_MASK)

#define ERM_SR1_NCE11_MASK                       (0x40000U)
#define ERM_SR1_NCE11_SHIFT                      (18U)
/*! NCE11 - NCE11
 *  0b0..No non-correctable error event on Memory 11 detected.
 *  0b1..Non-correctable error event on Memory 11 detected.
 */
#define ERM_SR1_NCE11(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR1_NCE11_SHIFT)) & ERM_SR1_NCE11_MASK)

#define ERM_SR1_SBC11_MASK                       (0x80000U)
#define ERM_SR1_SBC11_SHIFT                      (19U)
/*! SBC11 - SBC11
 *  0b0..No single-bit correction event on Memory 11 detected.
 *  0b1..Single-bit correction event on Memory 11 detected.
 */
#define ERM_SR1_SBC11(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR1_SBC11_SHIFT)) & ERM_SR1_SBC11_MASK)

#define ERM_SR1_NCE10_MASK                       (0x400000U)
#define ERM_SR1_NCE10_SHIFT                      (22U)
/*! NCE10 - NCE10
 *  0b0..No non-correctable error event on Memory 10 detected.
 *  0b1..Non-correctable error event on Memory 10 detected.
 */
#define ERM_SR1_NCE10(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR1_NCE10_SHIFT)) & ERM_SR1_NCE10_MASK)

#define ERM_SR1_SBC10_MASK                       (0x800000U)
#define ERM_SR1_SBC10_SHIFT                      (23U)
/*! SBC10 - SBC10
 *  0b0..No single-bit correction event on Memory 10 detected.
 *  0b1..Single-bit correction event on Memory 10 detected.
 */
#define ERM_SR1_SBC10(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR1_SBC10_SHIFT)) & ERM_SR1_SBC10_MASK)
/*! @} */

/*! @name SR2 - ERM Status Register 2 */
/*! @{ */

#define ERM_SR2_NCE18_MASK                       (0x400000U)
#define ERM_SR2_NCE18_SHIFT                      (22U)
/*! NCE18 - NCE18
 *  0b0..No non-correctable error event on Memory 18 detected.
 *  0b1..Non-correctable error event on Memory 18 detected.
 */
#define ERM_SR2_NCE18(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR2_NCE18_SHIFT)) & ERM_SR2_NCE18_MASK)

#define ERM_SR2_SBC18_MASK                       (0x800000U)
#define ERM_SR2_SBC18_SHIFT                      (23U)
/*! SBC18 - SBC18
 *  0b0..No single-bit correction event on Memory 18 detected.
 *  0b1..Single-bit correction event on Memory 18 detected.
 */
#define ERM_SR2_SBC18(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR2_SBC18_SHIFT)) & ERM_SR2_SBC18_MASK)

#define ERM_SR2_NCE17_MASK                       (0x4000000U)
#define ERM_SR2_NCE17_SHIFT                      (26U)
/*! NCE17 - NCE17
 *  0b0..No non-correctable error event on Memory 17 detected.
 *  0b1..Non-correctable error event on Memory 17 detected.
 */
#define ERM_SR2_NCE17(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR2_NCE17_SHIFT)) & ERM_SR2_NCE17_MASK)

#define ERM_SR2_SBC17_MASK                       (0x8000000U)
#define ERM_SR2_SBC17_SHIFT                      (27U)
/*! SBC17 - SBC17
 *  0b0..No single-bit correction event on Memory 17 detected.
 *  0b1..Single-bit correction event on Memory 17 detected.
 */
#define ERM_SR2_SBC17(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR2_SBC17_SHIFT)) & ERM_SR2_SBC17_MASK)

#define ERM_SR2_NCE16_MASK                       (0x40000000U)
#define ERM_SR2_NCE16_SHIFT                      (30U)
/*! NCE16 - NCE16
 *  0b0..No non-correctable error event on Memory 16 detected.
 *  0b1..Non-correctable error event on Memory 16 detected.
 */
#define ERM_SR2_NCE16(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR2_NCE16_SHIFT)) & ERM_SR2_NCE16_MASK)

#define ERM_SR2_SBC16_MASK                       (0x80000000U)
#define ERM_SR2_SBC16_SHIFT                      (31U)
/*! SBC16 - SBC16
 *  0b0..No single-bit correction event on Memory 16 detected.
 *  0b1..Single-bit correction event on Memory 16 detected.
 */
#define ERM_SR2_SBC16(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_SR2_SBC16_SHIFT)) & ERM_SR2_SBC16_MASK)
/*! @} */

/*! @name EAR0 - ERM Memory 0 Error Address Register */
/*! @{ */

#define ERM_EAR0_EAR_MASK                        (0xFFFFFFFFU)
#define ERM_EAR0_EAR_SHIFT                       (0U)
/*! EAR - EAR */
#define ERM_EAR0_EAR(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_EAR0_EAR_SHIFT)) & ERM_EAR0_EAR_MASK)
/*! @} */

/*! @name SYN0 - ERM Memory 0 Syndrome Register */
/*! @{ */

#define ERM_SYN0_SYNDROME_MASK                   (0xFF000000U)
#define ERM_SYN0_SYNDROME_SHIFT                  (24U)
/*! SYNDROME - SYNDROME */
#define ERM_SYN0_SYNDROME(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_SYN0_SYNDROME_SHIFT)) & ERM_SYN0_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT0 - ERM Memory 0 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT0_COUNT_MASK             (0xFFU)
#define ERM_CORR_ERR_CNT0_COUNT_SHIFT            (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT0_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT0_COUNT_SHIFT)) & ERM_CORR_ERR_CNT0_COUNT_MASK)
/*! @} */

/*! @name CORR_ERR_CNT2 - ERM Memory 2 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT2_COUNT_MASK             (0xFFU)
#define ERM_CORR_ERR_CNT2_COUNT_SHIFT            (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT2_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT2_COUNT_SHIFT)) & ERM_CORR_ERR_CNT2_COUNT_MASK)
/*! @} */

/*! @name CORR_ERR_CNT3 - ERM Memory 3 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT3_COUNT_MASK             (0xFFU)
#define ERM_CORR_ERR_CNT3_COUNT_SHIFT            (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT3_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT3_COUNT_SHIFT)) & ERM_CORR_ERR_CNT3_COUNT_MASK)
/*! @} */

/*! @name CORR_ERR_CNT4 - ERM Memory 4 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT4_COUNT_MASK             (0xFFU)
#define ERM_CORR_ERR_CNT4_COUNT_SHIFT            (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT4_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT4_COUNT_SHIFT)) & ERM_CORR_ERR_CNT4_COUNT_MASK)
/*! @} */

/*! @name CORR_ERR_CNT5 - ERM Memory 5 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT5_COUNT_MASK             (0xFFU)
#define ERM_CORR_ERR_CNT5_COUNT_SHIFT            (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT5_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT5_COUNT_SHIFT)) & ERM_CORR_ERR_CNT5_COUNT_MASK)
/*! @} */

/*! @name EAR10 - ERM Memory 10 Error Address Register */
/*! @{ */

#define ERM_EAR10_EAR_MASK                       (0xFFFFFFFFU)
#define ERM_EAR10_EAR_SHIFT                      (0U)
/*! EAR - EAR */
#define ERM_EAR10_EAR(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_EAR10_EAR_SHIFT)) & ERM_EAR10_EAR_MASK)
/*! @} */

/*! @name SYN10 - ERM Memory 10 Syndrome Register */
/*! @{ */

#define ERM_SYN10_SYNDROME_MASK                  (0xFF000000U)
#define ERM_SYN10_SYNDROME_SHIFT                 (24U)
/*! SYNDROME - SYNDROME */
#define ERM_SYN10_SYNDROME(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_SYN10_SYNDROME_SHIFT)) & ERM_SYN10_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT10 - ERM Memory 10 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT10_COUNT_MASK            (0xFFU)
#define ERM_CORR_ERR_CNT10_COUNT_SHIFT           (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT10_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT10_COUNT_SHIFT)) & ERM_CORR_ERR_CNT10_COUNT_MASK)
/*! @} */

/*! @name EAR11 - ERM Memory 11 Error Address Register */
/*! @{ */

#define ERM_EAR11_EAR_MASK                       (0xFFFFFFFFU)
#define ERM_EAR11_EAR_SHIFT                      (0U)
/*! EAR - EAR */
#define ERM_EAR11_EAR(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_EAR11_EAR_SHIFT)) & ERM_EAR11_EAR_MASK)
/*! @} */

/*! @name SYN11 - ERM Memory 11 Syndrome Register */
/*! @{ */

#define ERM_SYN11_SYNDROME_MASK                  (0xFF000000U)
#define ERM_SYN11_SYNDROME_SHIFT                 (24U)
/*! SYNDROME - SYNDROME */
#define ERM_SYN11_SYNDROME(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_SYN11_SYNDROME_SHIFT)) & ERM_SYN11_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT11 - ERM Memory 11 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT11_COUNT_MASK            (0xFFU)
#define ERM_CORR_ERR_CNT11_COUNT_SHIFT           (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT11_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT11_COUNT_SHIFT)) & ERM_CORR_ERR_CNT11_COUNT_MASK)
/*! @} */

/*! @name EAR12 - ERM Memory 12 Error Address Register */
/*! @{ */

#define ERM_EAR12_EAR_MASK                       (0xFFFFFFFFU)
#define ERM_EAR12_EAR_SHIFT                      (0U)
/*! EAR - EAR */
#define ERM_EAR12_EAR(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_EAR12_EAR_SHIFT)) & ERM_EAR12_EAR_MASK)
/*! @} */

/*! @name SYN12 - ERM Memory 12 Syndrome Register */
/*! @{ */

#define ERM_SYN12_SYNDROME_MASK                  (0xFF000000U)
#define ERM_SYN12_SYNDROME_SHIFT                 (24U)
/*! SYNDROME - SYNDROME */
#define ERM_SYN12_SYNDROME(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_SYN12_SYNDROME_SHIFT)) & ERM_SYN12_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT12 - ERM Memory 12 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT12_COUNT_MASK            (0xFFU)
#define ERM_CORR_ERR_CNT12_COUNT_SHIFT           (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT12_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT12_COUNT_SHIFT)) & ERM_CORR_ERR_CNT12_COUNT_MASK)
/*! @} */

/*! @name EAR16 - ERM Memory 16 Error Address Register */
/*! @{ */

#define ERM_EAR16_EAR_MASK                       (0xFFFFFFFFU)
#define ERM_EAR16_EAR_SHIFT                      (0U)
/*! EAR - EAR */
#define ERM_EAR16_EAR(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_EAR16_EAR_SHIFT)) & ERM_EAR16_EAR_MASK)
/*! @} */

/*! @name SYN16 - ERM Memory 16 Syndrome Register */
/*! @{ */

#define ERM_SYN16_SYNDROME_MASK                  (0xFF000000U)
#define ERM_SYN16_SYNDROME_SHIFT                 (24U)
/*! SYNDROME - SYNDROME */
#define ERM_SYN16_SYNDROME(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_SYN16_SYNDROME_SHIFT)) & ERM_SYN16_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT16 - ERM Memory 16 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT16_COUNT_MASK            (0xFFU)
#define ERM_CORR_ERR_CNT16_COUNT_SHIFT           (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT16_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT16_COUNT_SHIFT)) & ERM_CORR_ERR_CNT16_COUNT_MASK)
/*! @} */

/*! @name EAR17 - ERM Memory 17 Error Address Register */
/*! @{ */

#define ERM_EAR17_EAR_MASK                       (0xFFFFFFFFU)
#define ERM_EAR17_EAR_SHIFT                      (0U)
/*! EAR - EAR */
#define ERM_EAR17_EAR(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_EAR17_EAR_SHIFT)) & ERM_EAR17_EAR_MASK)
/*! @} */

/*! @name CORR_ERR_CNT17 - ERM Memory 17 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT17_COUNT_MASK            (0xFFU)
#define ERM_CORR_ERR_CNT17_COUNT_SHIFT           (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT17_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT17_COUNT_SHIFT)) & ERM_CORR_ERR_CNT17_COUNT_MASK)
/*! @} */

/*! @name EAR18 - ERM Memory 18 Error Address Register */
/*! @{ */

#define ERM_EAR18_EAR_MASK                       (0xFFFFFFFFU)
#define ERM_EAR18_EAR_SHIFT                      (0U)
/*! EAR - EAR */
#define ERM_EAR18_EAR(x)                         (((uint32_t)(((uint32_t)(x)) << ERM_EAR18_EAR_SHIFT)) & ERM_EAR18_EAR_MASK)
/*! @} */

/*! @name CORR_ERR_CNT18 - ERM Memory 18 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT18_COUNT_MASK            (0xFFU)
#define ERM_CORR_ERR_CNT18_COUNT_SHIFT           (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT18_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT18_COUNT_SHIFT)) & ERM_CORR_ERR_CNT18_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ERM_Register_Masks */


/*!
 * @}
 */ /* end of group ERM_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ERM_H_ */

