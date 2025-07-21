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
**         CMSIS Peripheral Access Layer for TSPC
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
 * @file PERI_TSPC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for TSPC
 *
 * CMSIS Peripheral Access Layer for TSPC
 */

#if !defined(PERI_TSPC_H_)
#define PERI_TSPC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- TSPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSPC_Peripheral_Access_Layer TSPC Peripheral Access Layer
 * @{
 */

/** TSPC - Size of Registers Arrays */
#define TSPC_GROUP_COUNT                          2u

/** TSPC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GRP_EN;                            /**< Group Enable, offset: 0x0 */
       uint8_t RESERVED_0[76];
  struct {                                         /* offset: 0x50, array step: 0x50 */
    __IO uint32_t GRP_OBE1;                          /**< Group OBE, array offset: 0x50, array step: 0x50 */
    __IO uint32_t GRP_OBE2;                          /**< Group OBE, array offset: 0x54, array step: 0x50 */
         uint8_t RESERVED_0[72];
  } GROUP[TSPC_GROUP_COUNT];
} TSPC_Type;

/* ----------------------------------------------------------------------------
   -- TSPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSPC_Register_Masks TSPC Register Masks
 * @{
 */

/*! @name GRP_EN - Group Enable */
/*! @{ */

#define TSPC_GRP_EN_GRP1_EN_MASK                 (0x1U)
#define TSPC_GRP_EN_GRP1_EN_SHIFT                (0U)
/*! GRP1_EN - Enable for GRP1_OBEn Register
 *  0b0..Disable
 *  0b1..Enable
 */
#define TSPC_GRP_EN_GRP1_EN(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_EN_GRP1_EN_SHIFT)) & TSPC_GRP_EN_GRP1_EN_MASK)

#define TSPC_GRP_EN_GRP2_EN_MASK                 (0x2U)
#define TSPC_GRP_EN_GRP2_EN_SHIFT                (1U)
/*! GRP2_EN - Enable for GRP2_OBEn Register
 *  0b0..Disable
 *  0b1..Enable
 */
#define TSPC_GRP_EN_GRP2_EN(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_EN_GRP2_EN_SHIFT)) & TSPC_GRP_EN_GRP2_EN_MASK)
/*! @} */

/*! @name GRP_OBE1 - Group OBE */
/*! @{ */

#define TSPC_GRP_OBE1_OBE0_MASK                  (0x1U)
#define TSPC_GRP_OBE1_OBE0_SHIFT                 (0U)
/*! OBE0 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE0(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE0_SHIFT)) & TSPC_GRP_OBE1_OBE0_MASK)

#define TSPC_GRP_OBE1_OBE1_MASK                  (0x2U)
#define TSPC_GRP_OBE1_OBE1_SHIFT                 (1U)
/*! OBE1 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE1(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE1_SHIFT)) & TSPC_GRP_OBE1_OBE1_MASK)

#define TSPC_GRP_OBE1_OBE2_MASK                  (0x4U)
#define TSPC_GRP_OBE1_OBE2_SHIFT                 (2U)
/*! OBE2 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE2(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE2_SHIFT)) & TSPC_GRP_OBE1_OBE2_MASK)

#define TSPC_GRP_OBE1_OBE3_MASK                  (0x8U)
#define TSPC_GRP_OBE1_OBE3_SHIFT                 (3U)
/*! OBE3 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE3(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE3_SHIFT)) & TSPC_GRP_OBE1_OBE3_MASK)

#define TSPC_GRP_OBE1_OBE4_MASK                  (0x10U)
#define TSPC_GRP_OBE1_OBE4_SHIFT                 (4U)
/*! OBE4 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE4(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE4_SHIFT)) & TSPC_GRP_OBE1_OBE4_MASK)

#define TSPC_GRP_OBE1_OBE5_MASK                  (0x20U)
#define TSPC_GRP_OBE1_OBE5_SHIFT                 (5U)
/*! OBE5 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE5(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE5_SHIFT)) & TSPC_GRP_OBE1_OBE5_MASK)

#define TSPC_GRP_OBE1_OBE6_MASK                  (0x40U)
#define TSPC_GRP_OBE1_OBE6_SHIFT                 (6U)
/*! OBE6 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE6(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE6_SHIFT)) & TSPC_GRP_OBE1_OBE6_MASK)

#define TSPC_GRP_OBE1_OBE7_MASK                  (0x80U)
#define TSPC_GRP_OBE1_OBE7_SHIFT                 (7U)
/*! OBE7 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE7(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE7_SHIFT)) & TSPC_GRP_OBE1_OBE7_MASK)

#define TSPC_GRP_OBE1_OBE8_MASK                  (0x100U)
#define TSPC_GRP_OBE1_OBE8_SHIFT                 (8U)
/*! OBE8 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE8(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE8_SHIFT)) & TSPC_GRP_OBE1_OBE8_MASK)

#define TSPC_GRP_OBE1_OBE9_MASK                  (0x200U)
#define TSPC_GRP_OBE1_OBE9_SHIFT                 (9U)
/*! OBE9 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE9(x)                    (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE9_SHIFT)) & TSPC_GRP_OBE1_OBE9_MASK)

#define TSPC_GRP_OBE1_OBE10_MASK                 (0x400U)
#define TSPC_GRP_OBE1_OBE10_SHIFT                (10U)
/*! OBE10 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE10(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE10_SHIFT)) & TSPC_GRP_OBE1_OBE10_MASK)

#define TSPC_GRP_OBE1_OBE11_MASK                 (0x800U)
#define TSPC_GRP_OBE1_OBE11_SHIFT                (11U)
/*! OBE11 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE11(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE11_SHIFT)) & TSPC_GRP_OBE1_OBE11_MASK)

#define TSPC_GRP_OBE1_OBE12_MASK                 (0x1000U)
#define TSPC_GRP_OBE1_OBE12_SHIFT                (12U)
/*! OBE12 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE12(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE12_SHIFT)) & TSPC_GRP_OBE1_OBE12_MASK)

#define TSPC_GRP_OBE1_OBE13_MASK                 (0x2000U)
#define TSPC_GRP_OBE1_OBE13_SHIFT                (13U)
/*! OBE13 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE13(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE13_SHIFT)) & TSPC_GRP_OBE1_OBE13_MASK)

#define TSPC_GRP_OBE1_OBE14_MASK                 (0x4000U)
#define TSPC_GRP_OBE1_OBE14_SHIFT                (14U)
/*! OBE14 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE14(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE14_SHIFT)) & TSPC_GRP_OBE1_OBE14_MASK)

#define TSPC_GRP_OBE1_OBE15_MASK                 (0x8000U)
#define TSPC_GRP_OBE1_OBE15_SHIFT                (15U)
/*! OBE15 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE15(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE15_SHIFT)) & TSPC_GRP_OBE1_OBE15_MASK)

#define TSPC_GRP_OBE1_OBE16_MASK                 (0x10000U)
#define TSPC_GRP_OBE1_OBE16_SHIFT                (16U)
/*! OBE16 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE16(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE16_SHIFT)) & TSPC_GRP_OBE1_OBE16_MASK)

#define TSPC_GRP_OBE1_OBE17_MASK                 (0x20000U)
#define TSPC_GRP_OBE1_OBE17_SHIFT                (17U)
/*! OBE17 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE17(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE17_SHIFT)) & TSPC_GRP_OBE1_OBE17_MASK)

#define TSPC_GRP_OBE1_OBE18_MASK                 (0x40000U)
#define TSPC_GRP_OBE1_OBE18_SHIFT                (18U)
/*! OBE18 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE18(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE18_SHIFT)) & TSPC_GRP_OBE1_OBE18_MASK)

#define TSPC_GRP_OBE1_OBE19_MASK                 (0x80000U)
#define TSPC_GRP_OBE1_OBE19_SHIFT                (19U)
/*! OBE19 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE19(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE19_SHIFT)) & TSPC_GRP_OBE1_OBE19_MASK)

#define TSPC_GRP_OBE1_OBE20_MASK                 (0x100000U)
#define TSPC_GRP_OBE1_OBE20_SHIFT                (20U)
/*! OBE20 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE20(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE20_SHIFT)) & TSPC_GRP_OBE1_OBE20_MASK)

#define TSPC_GRP_OBE1_OBE21_MASK                 (0x200000U)
#define TSPC_GRP_OBE1_OBE21_SHIFT                (21U)
/*! OBE21 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE21(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE21_SHIFT)) & TSPC_GRP_OBE1_OBE21_MASK)

#define TSPC_GRP_OBE1_OBE22_MASK                 (0x400000U)
#define TSPC_GRP_OBE1_OBE22_SHIFT                (22U)
/*! OBE22 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE22(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE22_SHIFT)) & TSPC_GRP_OBE1_OBE22_MASK)

#define TSPC_GRP_OBE1_OBE23_MASK                 (0x800000U)
#define TSPC_GRP_OBE1_OBE23_SHIFT                (23U)
/*! OBE23 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE23(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE23_SHIFT)) & TSPC_GRP_OBE1_OBE23_MASK)

#define TSPC_GRP_OBE1_OBE24_MASK                 (0x1000000U)
#define TSPC_GRP_OBE1_OBE24_SHIFT                (24U)
/*! OBE24 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE24(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE24_SHIFT)) & TSPC_GRP_OBE1_OBE24_MASK)

#define TSPC_GRP_OBE1_OBE25_MASK                 (0x2000000U)
#define TSPC_GRP_OBE1_OBE25_SHIFT                (25U)
/*! OBE25 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE25(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE25_SHIFT)) & TSPC_GRP_OBE1_OBE25_MASK)

#define TSPC_GRP_OBE1_OBE26_MASK                 (0x4000000U)
#define TSPC_GRP_OBE1_OBE26_SHIFT                (26U)
/*! OBE26 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE26(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE26_SHIFT)) & TSPC_GRP_OBE1_OBE26_MASK)

#define TSPC_GRP_OBE1_OBE27_MASK                 (0x8000000U)
#define TSPC_GRP_OBE1_OBE27_SHIFT                (27U)
/*! OBE27 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE27(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE27_SHIFT)) & TSPC_GRP_OBE1_OBE27_MASK)

#define TSPC_GRP_OBE1_OBE28_MASK                 (0x10000000U)
#define TSPC_GRP_OBE1_OBE28_SHIFT                (28U)
/*! OBE28 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE28(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE28_SHIFT)) & TSPC_GRP_OBE1_OBE28_MASK)

#define TSPC_GRP_OBE1_OBE29_MASK                 (0x20000000U)
#define TSPC_GRP_OBE1_OBE29_SHIFT                (29U)
/*! OBE29 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE29(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE29_SHIFT)) & TSPC_GRP_OBE1_OBE29_MASK)

#define TSPC_GRP_OBE1_OBE30_MASK                 (0x40000000U)
#define TSPC_GRP_OBE1_OBE30_SHIFT                (30U)
/*! OBE30 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE30(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE30_SHIFT)) & TSPC_GRP_OBE1_OBE30_MASK)

#define TSPC_GRP_OBE1_OBE31_MASK                 (0x80000000U)
#define TSPC_GRP_OBE1_OBE31_SHIFT                (31U)
/*! OBE31 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE1_OBE31(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE1_OBE31_SHIFT)) & TSPC_GRP_OBE1_OBE31_MASK)
/*! @} */

/* The count of TSPC_GRP_OBE1 */
#define TSPC_GRP_OBE1_COUNT                      (2U)

/*! @name GRP_OBE2 - Group OBE */
/*! @{ */

#define TSPC_GRP_OBE2_OBE32_MASK                 (0x1U)
#define TSPC_GRP_OBE2_OBE32_SHIFT                (0U)
/*! OBE32 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE32(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE32_SHIFT)) & TSPC_GRP_OBE2_OBE32_MASK)

#define TSPC_GRP_OBE2_OBE33_MASK                 (0x2U)
#define TSPC_GRP_OBE2_OBE33_SHIFT                (1U)
/*! OBE33 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE33(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE33_SHIFT)) & TSPC_GRP_OBE2_OBE33_MASK)

#define TSPC_GRP_OBE2_OBE34_MASK                 (0x4U)
#define TSPC_GRP_OBE2_OBE34_SHIFT                (2U)
/*! OBE34 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE34(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE34_SHIFT)) & TSPC_GRP_OBE2_OBE34_MASK)

#define TSPC_GRP_OBE2_OBE35_MASK                 (0x8U)
#define TSPC_GRP_OBE2_OBE35_SHIFT                (3U)
/*! OBE35 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE35(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE35_SHIFT)) & TSPC_GRP_OBE2_OBE35_MASK)

#define TSPC_GRP_OBE2_OBE36_MASK                 (0x10U)
#define TSPC_GRP_OBE2_OBE36_SHIFT                (4U)
/*! OBE36 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE36(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE36_SHIFT)) & TSPC_GRP_OBE2_OBE36_MASK)

#define TSPC_GRP_OBE2_OBE37_MASK                 (0x20U)
#define TSPC_GRP_OBE2_OBE37_SHIFT                (5U)
/*! OBE37 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE37(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE37_SHIFT)) & TSPC_GRP_OBE2_OBE37_MASK)

#define TSPC_GRP_OBE2_OBE38_MASK                 (0x40U)
#define TSPC_GRP_OBE2_OBE38_SHIFT                (6U)
/*! OBE38 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE38(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE38_SHIFT)) & TSPC_GRP_OBE2_OBE38_MASK)

#define TSPC_GRP_OBE2_OBE39_MASK                 (0x80U)
#define TSPC_GRP_OBE2_OBE39_SHIFT                (7U)
/*! OBE39 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE39(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE39_SHIFT)) & TSPC_GRP_OBE2_OBE39_MASK)

#define TSPC_GRP_OBE2_OBE40_MASK                 (0x100U)
#define TSPC_GRP_OBE2_OBE40_SHIFT                (8U)
/*! OBE40 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE40(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE40_SHIFT)) & TSPC_GRP_OBE2_OBE40_MASK)

#define TSPC_GRP_OBE2_OBE41_MASK                 (0x200U)
#define TSPC_GRP_OBE2_OBE41_SHIFT                (9U)
/*! OBE41 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE41(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE41_SHIFT)) & TSPC_GRP_OBE2_OBE41_MASK)

#define TSPC_GRP_OBE2_OBE42_MASK                 (0x400U)
#define TSPC_GRP_OBE2_OBE42_SHIFT                (10U)
/*! OBE42 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE42(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE42_SHIFT)) & TSPC_GRP_OBE2_OBE42_MASK)

#define TSPC_GRP_OBE2_OBE43_MASK                 (0x800U)
#define TSPC_GRP_OBE2_OBE43_SHIFT                (11U)
/*! OBE43 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE43(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE43_SHIFT)) & TSPC_GRP_OBE2_OBE43_MASK)

#define TSPC_GRP_OBE2_OBE44_MASK                 (0x1000U)
#define TSPC_GRP_OBE2_OBE44_SHIFT                (12U)
/*! OBE44 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE44(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE44_SHIFT)) & TSPC_GRP_OBE2_OBE44_MASK)

#define TSPC_GRP_OBE2_OBE45_MASK                 (0x2000U)
#define TSPC_GRP_OBE2_OBE45_SHIFT                (13U)
/*! OBE45 - Output Buffer Enable
 *  0b0..OBE pad does not transition if any OBE in group transitions from high to low. The OBE pad value is unaltered at the output.
 *  0b1..OBE pad transitions from high to low if any OBE in group transitions from high to low.
 */
#define TSPC_GRP_OBE2_OBE45(x)                   (((uint32_t)(((uint32_t)(x)) << TSPC_GRP_OBE2_OBE45_SHIFT)) & TSPC_GRP_OBE2_OBE45_MASK)
/*! @} */

/* The count of TSPC_GRP_OBE2 */
#define TSPC_GRP_OBE2_COUNT                      (2U)


/*!
 * @}
 */ /* end of group TSPC_Register_Masks */


/*!
 * @}
 */ /* end of group TSPC_Peripheral_Access_Layer */


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


#endif  /* PERI_TSPC_H_ */

