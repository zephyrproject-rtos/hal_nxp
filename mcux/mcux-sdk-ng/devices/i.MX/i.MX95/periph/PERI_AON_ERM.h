/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b250106
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AON_ERM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file AON_ERM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_ERM
 *
 * CMSIS Peripheral Access Layer for AON_ERM
 */

#if !defined(AON_ERM_H_)
#define AON_ERM_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- AON_ERM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_ERM_Peripheral_Access_Layer AON_ERM Peripheral Access Layer
 * @{
 */

/** AON_ERM - Register Layout Typedef */
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
} AON_ERM_Type;

/* ----------------------------------------------------------------------------
   -- AON_ERM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_ERM_Register_Masks AON_ERM Register Masks
 * @{
 */

/*! @name CR0 - ERM Configuration Register 0 */
/*! @{ */

#define AON_ERM_CR0_ENCIE7_MASK                  (0x4U)
#define AON_ERM_CR0_ENCIE7_SHIFT                 (2U)
/*! ENCIE7 - ENCIE7
 *  0b0..Interrupt notification of Memory 7 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 7 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE7_SHIFT)) & AON_ERM_CR0_ENCIE7_MASK)

#define AON_ERM_CR0_ESCIE7_MASK                  (0x8U)
#define AON_ERM_CR0_ESCIE7_SHIFT                 (3U)
/*! ESCIE7 - ESCIE7
 *  0b0..Interrupt notification of Memory 7 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 7 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE7_SHIFT)) & AON_ERM_CR0_ESCIE7_MASK)

#define AON_ERM_CR0_ENCIE6_MASK                  (0x40U)
#define AON_ERM_CR0_ENCIE6_SHIFT                 (6U)
/*! ENCIE6 - ENCIE6
 *  0b0..Interrupt notification of Memory 6 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 6 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE6_SHIFT)) & AON_ERM_CR0_ENCIE6_MASK)

#define AON_ERM_CR0_ESCIE6_MASK                  (0x80U)
#define AON_ERM_CR0_ESCIE6_SHIFT                 (7U)
/*! ESCIE6 - ESCIE6
 *  0b0..Interrupt notification of Memory 6 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 6 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE6_SHIFT)) & AON_ERM_CR0_ESCIE6_MASK)

#define AON_ERM_CR0_ENCIE5_MASK                  (0x400U)
#define AON_ERM_CR0_ENCIE5_SHIFT                 (10U)
/*! ENCIE5 - ENCIE5
 *  0b0..Interrupt notification of Memory 5 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 5 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE5_SHIFT)) & AON_ERM_CR0_ENCIE5_MASK)

#define AON_ERM_CR0_ESCIE5_MASK                  (0x800U)
#define AON_ERM_CR0_ESCIE5_SHIFT                 (11U)
/*! ESCIE5 - ESCIE5
 *  0b0..Interrupt notification of Memory 5 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 5 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE5_SHIFT)) & AON_ERM_CR0_ESCIE5_MASK)

#define AON_ERM_CR0_ENCIE4_MASK                  (0x4000U)
#define AON_ERM_CR0_ENCIE4_SHIFT                 (14U)
/*! ENCIE4 - ENCIE4
 *  0b0..Interrupt notification of Memory 4 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 4 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE4_SHIFT)) & AON_ERM_CR0_ENCIE4_MASK)

#define AON_ERM_CR0_ESCIE4_MASK                  (0x8000U)
#define AON_ERM_CR0_ESCIE4_SHIFT                 (15U)
/*! ESCIE4 - ESCIE4
 *  0b0..Interrupt notification of Memory 4 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 4 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE4_SHIFT)) & AON_ERM_CR0_ESCIE4_MASK)

#define AON_ERM_CR0_ENCIE3_MASK                  (0x40000U)
#define AON_ERM_CR0_ENCIE3_SHIFT                 (18U)
/*! ENCIE3 - ENCIE3
 *  0b0..Interrupt notification of Memory 3 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 3 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE3_SHIFT)) & AON_ERM_CR0_ENCIE3_MASK)

#define AON_ERM_CR0_ESCIE3_MASK                  (0x80000U)
#define AON_ERM_CR0_ESCIE3_SHIFT                 (19U)
/*! ESCIE3 - ESCIE3
 *  0b0..Interrupt notification of Memory 3 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 3 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE3_SHIFT)) & AON_ERM_CR0_ESCIE3_MASK)

#define AON_ERM_CR0_ENCIE2_MASK                  (0x400000U)
#define AON_ERM_CR0_ENCIE2_SHIFT                 (22U)
/*! ENCIE2 - ENCIE2
 *  0b0..Interrupt notification of Memory 2 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 2 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE2_SHIFT)) & AON_ERM_CR0_ENCIE2_MASK)

#define AON_ERM_CR0_ESCIE2_MASK                  (0x800000U)
#define AON_ERM_CR0_ESCIE2_SHIFT                 (23U)
/*! ESCIE2 - ESCIE2
 *  0b0..Interrupt notification of Memory 2 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 2 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE2_SHIFT)) & AON_ERM_CR0_ESCIE2_MASK)

#define AON_ERM_CR0_ENCIE1_MASK                  (0x4000000U)
#define AON_ERM_CR0_ENCIE1_SHIFT                 (26U)
/*! ENCIE1 - ENCIE1
 *  0b0..Interrupt notification of Memory 1 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 1 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE1_SHIFT)) & AON_ERM_CR0_ENCIE1_MASK)

#define AON_ERM_CR0_ESCIE1_MASK                  (0x8000000U)
#define AON_ERM_CR0_ESCIE1_SHIFT                 (27U)
/*! ESCIE1 - ESCIE1
 *  0b0..Interrupt notification of Memory 1 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 1 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE1_SHIFT)) & AON_ERM_CR0_ESCIE1_MASK)

#define AON_ERM_CR0_ENCIE0_MASK                  (0x40000000U)
#define AON_ERM_CR0_ENCIE0_SHIFT                 (30U)
/*! ENCIE0 - ENCIE0
 *  0b0..Interrupt notification of Memory 0 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 0 non-correctable error events is enabled.
 */
#define AON_ERM_CR0_ENCIE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ENCIE0_SHIFT)) & AON_ERM_CR0_ENCIE0_MASK)

#define AON_ERM_CR0_ESCIE0_MASK                  (0x80000000U)
#define AON_ERM_CR0_ESCIE0_SHIFT                 (31U)
/*! ESCIE0 - ESCIE0
 *  0b0..Interrupt notification of Memory 0 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 0 single-bit correction events is enabled.
 */
#define AON_ERM_CR0_ESCIE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR0_ESCIE0_SHIFT)) & AON_ERM_CR0_ESCIE0_MASK)
/*! @} */

/*! @name CR1 - ERM Configuration Register 1 */
/*! @{ */

#define AON_ERM_CR1_ENCIE9_MASK                  (0x4000000U)
#define AON_ERM_CR1_ENCIE9_SHIFT                 (26U)
/*! ENCIE9 - ENCIE9
 *  0b0..Interrupt notification of Memory 9 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 9 non-correctable error events is enabled.
 */
#define AON_ERM_CR1_ENCIE9(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR1_ENCIE9_SHIFT)) & AON_ERM_CR1_ENCIE9_MASK)

#define AON_ERM_CR1_ESCIE9_MASK                  (0x8000000U)
#define AON_ERM_CR1_ESCIE9_SHIFT                 (27U)
/*! ESCIE9 - ESCIE9
 *  0b0..Interrupt notification of Memory 9 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 9 single-bit correction events is enabled.
 */
#define AON_ERM_CR1_ESCIE9(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR1_ESCIE9_SHIFT)) & AON_ERM_CR1_ESCIE9_MASK)

#define AON_ERM_CR1_ENCIE8_MASK                  (0x40000000U)
#define AON_ERM_CR1_ENCIE8_SHIFT                 (30U)
/*! ENCIE8 - ENCIE8
 *  0b0..Interrupt notification of Memory 8 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 8 non-correctable error events is enabled.
 */
#define AON_ERM_CR1_ENCIE8(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR1_ENCIE8_SHIFT)) & AON_ERM_CR1_ENCIE8_MASK)

#define AON_ERM_CR1_ESCIE8_MASK                  (0x80000000U)
#define AON_ERM_CR1_ESCIE8_SHIFT                 (31U)
/*! ESCIE8 - ESCIE8
 *  0b0..Interrupt notification of Memory 8 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 8 single-bit correction events is enabled.
 */
#define AON_ERM_CR1_ESCIE8(x)                    (((uint32_t)(((uint32_t)(x)) << AON_ERM_CR1_ESCIE8_SHIFT)) & AON_ERM_CR1_ESCIE8_MASK)
/*! @} */

/*! @name SR0 - ERM Status Register 0 */
/*! @{ */

#define AON_ERM_SR0_NCE7_MASK                    (0x4U)
#define AON_ERM_SR0_NCE7_SHIFT                   (2U)
/*! NCE7 - NCE7
 *  0b0..No non-correctable error event on Memory 7 detected.
 *  0b1..Non-correctable error event on Memory 7 detected.
 */
#define AON_ERM_SR0_NCE7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE7_SHIFT)) & AON_ERM_SR0_NCE7_MASK)

#define AON_ERM_SR0_SBC7_MASK                    (0x8U)
#define AON_ERM_SR0_SBC7_SHIFT                   (3U)
/*! SBC7 - SBC7
 *  0b0..No single-bit correction event on Memory 7 detected.
 *  0b1..Single-bit correction event on Memory 7 detected.
 */
#define AON_ERM_SR0_SBC7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC7_SHIFT)) & AON_ERM_SR0_SBC7_MASK)

#define AON_ERM_SR0_NCE6_MASK                    (0x40U)
#define AON_ERM_SR0_NCE6_SHIFT                   (6U)
/*! NCE6 - NCE6
 *  0b0..No non-correctable error event on Memory 6 detected.
 *  0b1..Non-correctable error event on Memory 6 detected.
 */
#define AON_ERM_SR0_NCE6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE6_SHIFT)) & AON_ERM_SR0_NCE6_MASK)

#define AON_ERM_SR0_SBC6_MASK                    (0x80U)
#define AON_ERM_SR0_SBC6_SHIFT                   (7U)
/*! SBC6 - SBC6
 *  0b0..No single-bit correction event on Memory 6 detected.
 *  0b1..Single-bit correction event on Memory 6 detected.
 */
#define AON_ERM_SR0_SBC6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC6_SHIFT)) & AON_ERM_SR0_SBC6_MASK)

#define AON_ERM_SR0_NCE5_MASK                    (0x400U)
#define AON_ERM_SR0_NCE5_SHIFT                   (10U)
/*! NCE5 - NCE5
 *  0b0..No non-correctable error event on Memory 5 detected.
 *  0b1..Non-correctable error event on Memory 5 detected.
 */
#define AON_ERM_SR0_NCE5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE5_SHIFT)) & AON_ERM_SR0_NCE5_MASK)

#define AON_ERM_SR0_SBC5_MASK                    (0x800U)
#define AON_ERM_SR0_SBC5_SHIFT                   (11U)
/*! SBC5 - SBC5
 *  0b0..No single-bit correction event on Memory 5 detected.
 *  0b1..Single-bit correction event on Memory 5 detected.
 */
#define AON_ERM_SR0_SBC5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC5_SHIFT)) & AON_ERM_SR0_SBC5_MASK)

#define AON_ERM_SR0_NCE4_MASK                    (0x4000U)
#define AON_ERM_SR0_NCE4_SHIFT                   (14U)
/*! NCE4 - NCE4
 *  0b0..No non-correctable error event on Memory 4 detected.
 *  0b1..Non-correctable error event on Memory 4 detected.
 */
#define AON_ERM_SR0_NCE4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE4_SHIFT)) & AON_ERM_SR0_NCE4_MASK)

#define AON_ERM_SR0_SBC4_MASK                    (0x8000U)
#define AON_ERM_SR0_SBC4_SHIFT                   (15U)
/*! SBC4 - SBC4
 *  0b0..No single-bit correction event on Memory 4 detected.
 *  0b1..Single-bit correction event on Memory 4 detected.
 */
#define AON_ERM_SR0_SBC4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC4_SHIFT)) & AON_ERM_SR0_SBC4_MASK)

#define AON_ERM_SR0_NCE3_MASK                    (0x40000U)
#define AON_ERM_SR0_NCE3_SHIFT                   (18U)
/*! NCE3 - NCE3
 *  0b0..No non-correctable error event on Memory 3 detected.
 *  0b1..Non-correctable error event on Memory 3 detected.
 */
#define AON_ERM_SR0_NCE3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE3_SHIFT)) & AON_ERM_SR0_NCE3_MASK)

#define AON_ERM_SR0_SBC3_MASK                    (0x80000U)
#define AON_ERM_SR0_SBC3_SHIFT                   (19U)
/*! SBC3 - SBC3
 *  0b0..No single-bit correction event on Memory 3 detected.
 *  0b1..Single-bit correction event on Memory 3 detected.
 */
#define AON_ERM_SR0_SBC3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC3_SHIFT)) & AON_ERM_SR0_SBC3_MASK)

#define AON_ERM_SR0_NCE2_MASK                    (0x400000U)
#define AON_ERM_SR0_NCE2_SHIFT                   (22U)
/*! NCE2 - NCE2
 *  0b0..No non-correctable error event on Memory 2 detected.
 *  0b1..Non-correctable error event on Memory 2 detected.
 */
#define AON_ERM_SR0_NCE2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE2_SHIFT)) & AON_ERM_SR0_NCE2_MASK)

#define AON_ERM_SR0_SBC2_MASK                    (0x800000U)
#define AON_ERM_SR0_SBC2_SHIFT                   (23U)
/*! SBC2 - SBC2
 *  0b0..No single-bit correction event on Memory 2 detected.
 *  0b1..Single-bit correction event on Memory 2 detected.
 */
#define AON_ERM_SR0_SBC2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC2_SHIFT)) & AON_ERM_SR0_SBC2_MASK)

#define AON_ERM_SR0_NCE1_MASK                    (0x4000000U)
#define AON_ERM_SR0_NCE1_SHIFT                   (26U)
/*! NCE1 - NCE1
 *  0b0..No non-correctable error event on Memory 1 detected.
 *  0b1..Non-correctable error event on Memory 1 detected.
 */
#define AON_ERM_SR0_NCE1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE1_SHIFT)) & AON_ERM_SR0_NCE1_MASK)

#define AON_ERM_SR0_SBC1_MASK                    (0x8000000U)
#define AON_ERM_SR0_SBC1_SHIFT                   (27U)
/*! SBC1 - SBC1
 *  0b0..No single-bit correction event on Memory 1 detected.
 *  0b1..Single-bit correction event on Memory 1 detected.
 */
#define AON_ERM_SR0_SBC1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC1_SHIFT)) & AON_ERM_SR0_SBC1_MASK)

#define AON_ERM_SR0_NCE0_MASK                    (0x40000000U)
#define AON_ERM_SR0_NCE0_SHIFT                   (30U)
/*! NCE0 - NCE0
 *  0b0..No non-correctable error event on Memory 0 detected.
 *  0b1..Non-correctable error event on Memory 0 detected.
 */
#define AON_ERM_SR0_NCE0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_NCE0_SHIFT)) & AON_ERM_SR0_NCE0_MASK)

#define AON_ERM_SR0_SBC0_MASK                    (0x80000000U)
#define AON_ERM_SR0_SBC0_SHIFT                   (31U)
/*! SBC0 - SBC0
 *  0b0..No single-bit correction event on Memory 0 detected.
 *  0b1..Single-bit correction event on Memory 0 detected.
 */
#define AON_ERM_SR0_SBC0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR0_SBC0_SHIFT)) & AON_ERM_SR0_SBC0_MASK)
/*! @} */

/*! @name SR1 - ERM Status Register 1 */
/*! @{ */

#define AON_ERM_SR1_NCE9_MASK                    (0x4000000U)
#define AON_ERM_SR1_NCE9_SHIFT                   (26U)
/*! NCE9 - NCE9
 *  0b0..No non-correctable error event on Memory 9 detected.
 *  0b1..Non-correctable error event on Memory 9 detected.
 */
#define AON_ERM_SR1_NCE9(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR1_NCE9_SHIFT)) & AON_ERM_SR1_NCE9_MASK)

#define AON_ERM_SR1_SBC9_MASK                    (0x8000000U)
#define AON_ERM_SR1_SBC9_SHIFT                   (27U)
/*! SBC9 - SBC9
 *  0b0..No single-bit correction event on Memory 9 detected.
 *  0b1..Single-bit correction event on Memory 9 detected.
 */
#define AON_ERM_SR1_SBC9(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR1_SBC9_SHIFT)) & AON_ERM_SR1_SBC9_MASK)

#define AON_ERM_SR1_NCE8_MASK                    (0x40000000U)
#define AON_ERM_SR1_NCE8_SHIFT                   (30U)
/*! NCE8 - NCE8
 *  0b0..No non-correctable error event on Memory 8 detected.
 *  0b1..Non-correctable error event on Memory 8 detected.
 */
#define AON_ERM_SR1_NCE8(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR1_NCE8_SHIFT)) & AON_ERM_SR1_NCE8_MASK)

#define AON_ERM_SR1_SBC8_MASK                    (0x80000000U)
#define AON_ERM_SR1_SBC8_SHIFT                   (31U)
/*! SBC8 - SBC8
 *  0b0..No single-bit correction event on Memory 8 detected.
 *  0b1..Single-bit correction event on Memory 8 detected.
 */
#define AON_ERM_SR1_SBC8(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_SR1_SBC8_SHIFT)) & AON_ERM_SR1_SBC8_MASK)
/*! @} */

/*! @name EAR0 - ERM Memory 0 Error Address Register */
/*! @{ */

#define AON_ERM_EAR0_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR0_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR0_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR0_EAR_SHIFT)) & AON_ERM_EAR0_EAR_MASK)
/*! @} */

/*! @name SYN0 - ERM Memory 0 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN0_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN0_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN0_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN0_SYNDROME_SHIFT)) & AON_ERM_SYN0_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT0 - ERM Memory 0 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT0_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT0_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT0_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT0_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT0_COUNT_MASK)
/*! @} */

/*! @name EAR1 - ERM Memory 1 Error Address Register */
/*! @{ */

#define AON_ERM_EAR1_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR1_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR1_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR1_EAR_SHIFT)) & AON_ERM_EAR1_EAR_MASK)
/*! @} */

/*! @name SYN1 - ERM Memory 1 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN1_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN1_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN1_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN1_SYNDROME_SHIFT)) & AON_ERM_SYN1_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT1 - ERM Memory 1 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT1_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT1_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT1_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT1_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT1_COUNT_MASK)
/*! @} */

/*! @name EAR2 - ERM Memory 2 Error Address Register */
/*! @{ */

#define AON_ERM_EAR2_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR2_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR2_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR2_EAR_SHIFT)) & AON_ERM_EAR2_EAR_MASK)
/*! @} */

/*! @name SYN2 - ERM Memory 2 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN2_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN2_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN2_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN2_SYNDROME_SHIFT)) & AON_ERM_SYN2_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT2 - ERM Memory 2 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT2_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT2_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT2_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT2_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT2_COUNT_MASK)
/*! @} */

/*! @name EAR3 - ERM Memory 3 Error Address Register */
/*! @{ */

#define AON_ERM_EAR3_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR3_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR3_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR3_EAR_SHIFT)) & AON_ERM_EAR3_EAR_MASK)
/*! @} */

/*! @name SYN3 - ERM Memory 3 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN3_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN3_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN3_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN3_SYNDROME_SHIFT)) & AON_ERM_SYN3_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT3 - ERM Memory 3 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT3_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT3_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT3_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT3_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT3_COUNT_MASK)
/*! @} */

/*! @name EAR4 - ERM Memory 4 Error Address Register */
/*! @{ */

#define AON_ERM_EAR4_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR4_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR4_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR4_EAR_SHIFT)) & AON_ERM_EAR4_EAR_MASK)
/*! @} */

/*! @name SYN4 - ERM Memory 4 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN4_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN4_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN4_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN4_SYNDROME_SHIFT)) & AON_ERM_SYN4_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT4 - ERM Memory 4 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT4_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT4_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT4_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT4_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT4_COUNT_MASK)
/*! @} */

/*! @name EAR5 - ERM Memory 5 Error Address Register */
/*! @{ */

#define AON_ERM_EAR5_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR5_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR5_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR5_EAR_SHIFT)) & AON_ERM_EAR5_EAR_MASK)
/*! @} */

/*! @name SYN5 - ERM Memory 5 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN5_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN5_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN5_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN5_SYNDROME_SHIFT)) & AON_ERM_SYN5_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT5 - ERM Memory 5 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT5_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT5_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT5_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT5_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT5_COUNT_MASK)
/*! @} */

/*! @name EAR6 - ERM Memory 6 Error Address Register */
/*! @{ */

#define AON_ERM_EAR6_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR6_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR6_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR6_EAR_SHIFT)) & AON_ERM_EAR6_EAR_MASK)
/*! @} */

/*! @name SYN6 - ERM Memory 6 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN6_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN6_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN6_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN6_SYNDROME_SHIFT)) & AON_ERM_SYN6_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT6 - ERM Memory 6 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT6_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT6_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT6_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT6_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT6_COUNT_MASK)
/*! @} */

/*! @name EAR7 - ERM Memory 7 Error Address Register */
/*! @{ */

#define AON_ERM_EAR7_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR7_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR7_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR7_EAR_SHIFT)) & AON_ERM_EAR7_EAR_MASK)
/*! @} */

/*! @name SYN7 - ERM Memory 7 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN7_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN7_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN7_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN7_SYNDROME_SHIFT)) & AON_ERM_SYN7_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT7 - ERM Memory 7 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT7_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT7_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT7_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT7_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT7_COUNT_MASK)
/*! @} */

/*! @name EAR8 - ERM Memory 8 Error Address Register */
/*! @{ */

#define AON_ERM_EAR8_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR8_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR8_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR8_EAR_SHIFT)) & AON_ERM_EAR8_EAR_MASK)
/*! @} */

/*! @name SYN8 - ERM Memory 8 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN8_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN8_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN8_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN8_SYNDROME_SHIFT)) & AON_ERM_SYN8_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT8 - ERM Memory 8 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT8_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT8_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT8_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT8_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT8_COUNT_MASK)
/*! @} */

/*! @name EAR9 - ERM Memory 9 Error Address Register */
/*! @{ */

#define AON_ERM_EAR9_EAR_MASK                    (0xFFFFFFFFU)
#define AON_ERM_EAR9_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define AON_ERM_EAR9_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << AON_ERM_EAR9_EAR_SHIFT)) & AON_ERM_EAR9_EAR_MASK)
/*! @} */

/*! @name SYN9 - ERM Memory 9 Syndrome Register */
/*! @{ */

#define AON_ERM_SYN9_SYNDROME_MASK               (0xFF000000U)
#define AON_ERM_SYN9_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define AON_ERM_SYN9_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << AON_ERM_SYN9_SYNDROME_SHIFT)) & AON_ERM_SYN9_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT9 - ERM Memory 9 Correctable Error Count Register */
/*! @{ */

#define AON_ERM_CORR_ERR_CNT9_COUNT_MASK         (0xFFU)
#define AON_ERM_CORR_ERR_CNT9_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define AON_ERM_CORR_ERR_CNT9_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << AON_ERM_CORR_ERR_CNT9_COUNT_SHIFT)) & AON_ERM_CORR_ERR_CNT9_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AON_ERM_Register_Masks */


/*!
 * @}
 */ /* end of group AON_ERM_Peripheral_Access_Layer */


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


#endif  /* AON_ERM_H_ */

