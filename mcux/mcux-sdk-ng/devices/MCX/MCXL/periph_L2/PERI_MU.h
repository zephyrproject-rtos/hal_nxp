/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_MU.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for MU
 *
 * CMSIS Peripheral Access Layer for MU
 */

#if !defined(PERI_MU_H_)
#define PERI_MU_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- MU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_Peripheral_Access_Layer MU Peripheral Access Layer
 * @{
 */

/** MU - Size of Registers Arrays */
#define MU_TR_COUNT                               4u
#define MU_RR_COUNT                               4u

/** MU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VER;                               /**< Version ID, offset: 0x0 */
  __I  uint32_t PAR;                               /**< Parameter, offset: 0x4 */
  __IO uint32_t CR;                                /**< Control, offset: 0x8 */
  __I  uint32_t SR;                                /**< Status, offset: 0xC */
       uint8_t RESERVED_0[4];
       uint32_t CIER0;                             /**< Core Interrupt Enable 0, offset: 0x14 */
       uint8_t RESERVED_1[232];
  __IO uint32_t FCR;                               /**< Flag Control, offset: 0x100 */
  __I  uint32_t FSR;                               /**< Flag Status, offset: 0x104 */
       uint8_t RESERVED_2[8];
  __IO uint32_t GIER;                              /**< General-Purpose Interrupt Enable, offset: 0x110 */
  __IO uint32_t GCR;                               /**< General-Purpose Control, offset: 0x114 */
  __IO uint32_t GSR;                               /**< General-purpose Status, offset: 0x118 */
       uint8_t RESERVED_3[4];
  __IO uint32_t TCR;                               /**< Transmit Control, offset: 0x120 */
  __I  uint32_t TSR;                               /**< Transmit Status, offset: 0x124 */
  __IO uint32_t RCR;                               /**< Receive Control, offset: 0x128 */
  __I  uint32_t RSR;                               /**< Receive Status, offset: 0x12C */
       uint8_t RESERVED_4[208];
  __IO uint32_t TR[MU_TR_COUNT];                   /**< Transmit, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_5[112];
  __I  uint32_t RR[MU_RR_COUNT];                   /**< Receive, array offset: 0x280, array step: 0x4 */
} MU_Type;

/* ----------------------------------------------------------------------------
   -- MU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_Register_Masks MU Register Masks
 * @{
 */

/*! @name VER - Version ID */
/*! @{ */

#define MU_VER_FEATURE_MASK                      (0xFFFFU)
#define MU_VER_FEATURE_SHIFT                     (0U)
/*! FEATURE - Feature Set Number */
#define MU_VER_FEATURE(x)                        (((uint32_t)(((uint32_t)(x)) << MU_VER_FEATURE_SHIFT)) & MU_VER_FEATURE_MASK)

#define MU_VER_MINOR_MASK                        (0xFF0000U)
#define MU_VER_MINOR_SHIFT                       (16U)
/*! MINOR - Minor Version Number */
#define MU_VER_MINOR(x)                          (((uint32_t)(((uint32_t)(x)) << MU_VER_MINOR_SHIFT)) & MU_VER_MINOR_MASK)

#define MU_VER_MAJOR_MASK                        (0xFF000000U)
#define MU_VER_MAJOR_SHIFT                       (24U)
/*! MAJOR - Major Version Number */
#define MU_VER_MAJOR(x)                          (((uint32_t)(((uint32_t)(x)) << MU_VER_MAJOR_SHIFT)) & MU_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR - Parameter */
/*! @{ */

#define MU_PAR_TR_NUM_MASK                       (0xFFU)
#define MU_PAR_TR_NUM_SHIFT                      (0U)
/*! TR_NUM - Transmit Register Number */
#define MU_PAR_TR_NUM(x)                         (((uint32_t)(((uint32_t)(x)) << MU_PAR_TR_NUM_SHIFT)) & MU_PAR_TR_NUM_MASK)

#define MU_PAR_RR_NUM_MASK                       (0xFF00U)
#define MU_PAR_RR_NUM_SHIFT                      (8U)
/*! RR_NUM - Receive Register Number */
#define MU_PAR_RR_NUM(x)                         (((uint32_t)(((uint32_t)(x)) << MU_PAR_RR_NUM_SHIFT)) & MU_PAR_RR_NUM_MASK)

#define MU_PAR_GIR_NUM_MASK                      (0xFF0000U)
#define MU_PAR_GIR_NUM_SHIFT                     (16U)
/*! GIR_NUM - General-Purpose Interrupt Request Number */
#define MU_PAR_GIR_NUM(x)                        (((uint32_t)(((uint32_t)(x)) << MU_PAR_GIR_NUM_SHIFT)) & MU_PAR_GIR_NUM_MASK)

#define MU_PAR_FLAG_WIDTH_MASK                   (0xFF000000U)
#define MU_PAR_FLAG_WIDTH_SHIFT                  (24U)
/*! FLAG_WIDTH - Flag Width */
#define MU_PAR_FLAG_WIDTH(x)                     (((uint32_t)(((uint32_t)(x)) << MU_PAR_FLAG_WIDTH_SHIFT)) & MU_PAR_FLAG_WIDTH_MASK)
/*! @} */

/*! @name CR - Control */
/*! @{ */

#define MU_CR_MUR_MASK                           (0x1U)
#define MU_CR_MUR_SHIFT                          (0U)
/*! MUR - MU Reset
 *  0b0..Idle
 *  0b1..Reset
 */
#define MU_CR_MUR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_MUR_SHIFT)) & MU_CR_MUR_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define MU_SR_MURS_MASK                          (0x1U)
#define MU_SR_MURS_SHIFT                         (0U)
/*! MURS - MUA and MUB Reset State
 *  0b0..Out of reset
 *  0b1..In reset
 */
#define MU_SR_MURS(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_MURS_SHIFT)) & MU_SR_MURS_MASK)

#define MU_SR_EP_MASK                            (0x4U)
#define MU_SR_EP_SHIFT                           (2U)
/*! EP - pd_vsys.cm0p_mix.mub Side Event Pending
 *  0b0..Not pending
 *  0b1..Pending
 */
#define MU_SR_EP(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_EP_SHIFT)) & MU_SR_EP_MASK)

#define MU_SR_FUP_MASK                           (0x8U)
#define MU_SR_FUP_SHIFT                          (3U)
/*! FUP - pd_vsys.cm0p_mix.mub Flag Update Pending
 *  0b0..No pending update flags (initiated by pd_vsys.cm0p_mix.mub)
 *  0b1..Pending update flags (initiated by pd_vsys.cm0p_mix.mub)
 */
#define MU_SR_FUP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_FUP_SHIFT)) & MU_SR_FUP_MASK)

#define MU_SR_GIRP_MASK                          (0x10U)
#define MU_SR_GIRP_SHIFT                         (4U)
/*! GIRP - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Pending
 *  0b0..No request sent
 *  0b1..Request sent
 */
#define MU_SR_GIRP(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_GIRP_SHIFT)) & MU_SR_GIRP_MASK)

#define MU_SR_TEP_MASK                           (0x20U)
#define MU_SR_TEP_SHIFT                          (5U)
/*! TEP - pd_vsys.cm0p_mix.mub Transmit Empty Pending
 *  0b0..No pd_vsys.cm0p_mix.mub transmit empty event pending
 *  0b1..Pending; any TCR[TIEn] field is 1 and TSR[TEn] flag is set
 */
#define MU_SR_TEP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_TEP_SHIFT)) & MU_SR_TEP_MASK)

#define MU_SR_RFP_MASK                           (0x40U)
#define MU_SR_RFP_SHIFT                          (6U)
/*! RFP - pd_vsys.cm0p_mix.mub Receive Full Pending
 *  0b0..Not pending; MUB is not writing to a Transmit register
 *  0b1..Pending; MUB is writing to a Transmit register
 */
#define MU_SR_RFP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_RFP_SHIFT)) & MU_SR_RFP_MASK)
/*! @} */

/*! @name FCR - Flag Control */
/*! @{ */

#define MU_FCR_F0_MASK                           (0x1U)
#define MU_FCR_F0_SHIFT                          (0U)
/*! F0 - pd_vsys.cm0p_mix.mub to MUB Flag
 *  0b0..Clear MUB_FSR[Fn]
 *  0b1..Set MUB_FSR[Fn]
 */
#define MU_FCR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F0_SHIFT)) & MU_FCR_F0_MASK)

#define MU_FCR_F1_MASK                           (0x2U)
#define MU_FCR_F1_SHIFT                          (1U)
/*! F1 - pd_vsys.cm0p_mix.mub to MUB Flag
 *  0b0..Clear MUB_FSR[Fn]
 *  0b1..Set MUB_FSR[Fn]
 */
#define MU_FCR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F1_SHIFT)) & MU_FCR_F1_MASK)

#define MU_FCR_F2_MASK                           (0x4U)
#define MU_FCR_F2_SHIFT                          (2U)
/*! F2 - pd_vsys.cm0p_mix.mub to MUB Flag
 *  0b0..Clear MUB_FSR[Fn]
 *  0b1..Set MUB_FSR[Fn]
 */
#define MU_FCR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F2_SHIFT)) & MU_FCR_F2_MASK)
/*! @} */

/*! @name FSR - Flag Status */
/*! @{ */

#define MU_FSR_F0_MASK                           (0x1U)
#define MU_FSR_F0_SHIFT                          (0U)
/*! F0 - MUB to pd_vsys.cm0p_mix.mub-Side Flag
 *  0b0..MUB_FCR[Fn] = 0
 *  0b1..MUB_FCR[Fn] = 1
 */
#define MU_FSR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F0_SHIFT)) & MU_FSR_F0_MASK)

#define MU_FSR_F1_MASK                           (0x2U)
#define MU_FSR_F1_SHIFT                          (1U)
/*! F1 - MUB to pd_vsys.cm0p_mix.mub-Side Flag
 *  0b0..MUB_FCR[Fn] = 0
 *  0b1..MUB_FCR[Fn] = 1
 */
#define MU_FSR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F1_SHIFT)) & MU_FSR_F1_MASK)

#define MU_FSR_F2_MASK                           (0x4U)
#define MU_FSR_F2_SHIFT                          (2U)
/*! F2 - MUB to pd_vsys.cm0p_mix.mub-Side Flag
 *  0b0..MUB_FCR[Fn] = 0
 *  0b1..MUB_FCR[Fn] = 1
 */
#define MU_FSR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F2_SHIFT)) & MU_FSR_F2_MASK)
/*! @} */

/*! @name GIER - General-Purpose Interrupt Enable */
/*! @{ */

#define MU_GIER_GIE0_MASK                        (0x1U)
#define MU_GIER_GIE0_SHIFT                       (0U)
/*! GIE0 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE0(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE0_SHIFT)) & MU_GIER_GIE0_MASK)

#define MU_GIER_GIE1_MASK                        (0x2U)
#define MU_GIER_GIE1_SHIFT                       (1U)
/*! GIE1 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE1(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE1_SHIFT)) & MU_GIER_GIE1_MASK)

#define MU_GIER_GIE2_MASK                        (0x4U)
#define MU_GIER_GIE2_SHIFT                       (2U)
/*! GIE2 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE2(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE2_SHIFT)) & MU_GIER_GIE2_MASK)

#define MU_GIER_GIE3_MASK                        (0x8U)
#define MU_GIER_GIE3_SHIFT                       (3U)
/*! GIE3 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE3(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE3_SHIFT)) & MU_GIER_GIE3_MASK)

#define MU_GIER_GIE4_MASK                        (0x10U)
#define MU_GIER_GIE4_SHIFT                       (4U)
/*! GIE4 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE4(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE4_SHIFT)) & MU_GIER_GIE4_MASK)

#define MU_GIER_GIE5_MASK                        (0x20U)
#define MU_GIER_GIE5_SHIFT                       (5U)
/*! GIE5 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE5(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE5_SHIFT)) & MU_GIER_GIE5_MASK)

#define MU_GIER_GIE6_MASK                        (0x40U)
#define MU_GIER_GIE6_SHIFT                       (6U)
/*! GIE6 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE6(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE6_SHIFT)) & MU_GIER_GIE6_MASK)

#define MU_GIER_GIE7_MASK                        (0x80U)
#define MU_GIER_GIE7_SHIFT                       (7U)
/*! GIE7 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE7(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE7_SHIFT)) & MU_GIER_GIE7_MASK)

#define MU_GIER_GIE8_MASK                        (0x100U)
#define MU_GIER_GIE8_SHIFT                       (8U)
/*! GIE8 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE8(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE8_SHIFT)) & MU_GIER_GIE8_MASK)

#define MU_GIER_GIE9_MASK                        (0x200U)
#define MU_GIER_GIE9_SHIFT                       (9U)
/*! GIE9 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE9(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE9_SHIFT)) & MU_GIER_GIE9_MASK)

#define MU_GIER_GIE10_MASK                       (0x400U)
#define MU_GIER_GIE10_SHIFT                      (10U)
/*! GIE10 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE10(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE10_SHIFT)) & MU_GIER_GIE10_MASK)

#define MU_GIER_GIE11_MASK                       (0x800U)
#define MU_GIER_GIE11_SHIFT                      (11U)
/*! GIE11 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE11(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE11_SHIFT)) & MU_GIER_GIE11_MASK)

#define MU_GIER_GIE12_MASK                       (0x1000U)
#define MU_GIER_GIE12_SHIFT                      (12U)
/*! GIE12 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE12(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE12_SHIFT)) & MU_GIER_GIE12_MASK)

#define MU_GIER_GIE13_MASK                       (0x2000U)
#define MU_GIER_GIE13_SHIFT                      (13U)
/*! GIE13 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE13(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE13_SHIFT)) & MU_GIER_GIE13_MASK)

#define MU_GIER_GIE14_MASK                       (0x4000U)
#define MU_GIER_GIE14_SHIFT                      (14U)
/*! GIE14 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE14(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE14_SHIFT)) & MU_GIER_GIE14_MASK)

#define MU_GIER_GIE15_MASK                       (0x8000U)
#define MU_GIER_GIE15_SHIFT                      (15U)
/*! GIE15 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE15(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE15_SHIFT)) & MU_GIER_GIE15_MASK)

#define MU_GIER_GIE16_MASK                       (0x10000U)
#define MU_GIER_GIE16_SHIFT                      (16U)
/*! GIE16 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE16(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE16_SHIFT)) & MU_GIER_GIE16_MASK)

#define MU_GIER_GIE17_MASK                       (0x20000U)
#define MU_GIER_GIE17_SHIFT                      (17U)
/*! GIE17 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE17(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE17_SHIFT)) & MU_GIER_GIE17_MASK)

#define MU_GIER_GIE18_MASK                       (0x40000U)
#define MU_GIER_GIE18_SHIFT                      (18U)
/*! GIE18 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE18(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE18_SHIFT)) & MU_GIER_GIE18_MASK)

#define MU_GIER_GIE19_MASK                       (0x80000U)
#define MU_GIER_GIE19_SHIFT                      (19U)
/*! GIE19 - pd_vsys.cm0p_mix.mub General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE19(x)                         (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE19_SHIFT)) & MU_GIER_GIE19_MASK)
/*! @} */

/*! @name GCR - General-Purpose Control */
/*! @{ */

#define MU_GCR_GIR0_MASK                         (0x1U)
#define MU_GCR_GIR0_SHIFT                        (0U)
/*! GIR0 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR0_SHIFT)) & MU_GCR_GIR0_MASK)

#define MU_GCR_GIR1_MASK                         (0x2U)
#define MU_GCR_GIR1_SHIFT                        (1U)
/*! GIR1 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR1_SHIFT)) & MU_GCR_GIR1_MASK)

#define MU_GCR_GIR2_MASK                         (0x4U)
#define MU_GCR_GIR2_SHIFT                        (2U)
/*! GIR2 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR2_SHIFT)) & MU_GCR_GIR2_MASK)

#define MU_GCR_GIR3_MASK                         (0x8U)
#define MU_GCR_GIR3_SHIFT                        (3U)
/*! GIR3 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR3_SHIFT)) & MU_GCR_GIR3_MASK)

#define MU_GCR_GIR4_MASK                         (0x10U)
#define MU_GCR_GIR4_SHIFT                        (4U)
/*! GIR4 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR4(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR4_SHIFT)) & MU_GCR_GIR4_MASK)

#define MU_GCR_GIR5_MASK                         (0x20U)
#define MU_GCR_GIR5_SHIFT                        (5U)
/*! GIR5 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR5(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR5_SHIFT)) & MU_GCR_GIR5_MASK)

#define MU_GCR_GIR6_MASK                         (0x40U)
#define MU_GCR_GIR6_SHIFT                        (6U)
/*! GIR6 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR6(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR6_SHIFT)) & MU_GCR_GIR6_MASK)

#define MU_GCR_GIR7_MASK                         (0x80U)
#define MU_GCR_GIR7_SHIFT                        (7U)
/*! GIR7 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR7(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR7_SHIFT)) & MU_GCR_GIR7_MASK)

#define MU_GCR_GIR8_MASK                         (0x100U)
#define MU_GCR_GIR8_SHIFT                        (8U)
/*! GIR8 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR8(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR8_SHIFT)) & MU_GCR_GIR8_MASK)

#define MU_GCR_GIR9_MASK                         (0x200U)
#define MU_GCR_GIR9_SHIFT                        (9U)
/*! GIR9 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR9(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR9_SHIFT)) & MU_GCR_GIR9_MASK)

#define MU_GCR_GIR10_MASK                        (0x400U)
#define MU_GCR_GIR10_SHIFT                       (10U)
/*! GIR10 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR10(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR10_SHIFT)) & MU_GCR_GIR10_MASK)

#define MU_GCR_GIR11_MASK                        (0x800U)
#define MU_GCR_GIR11_SHIFT                       (11U)
/*! GIR11 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR11(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR11_SHIFT)) & MU_GCR_GIR11_MASK)

#define MU_GCR_GIR12_MASK                        (0x1000U)
#define MU_GCR_GIR12_SHIFT                       (12U)
/*! GIR12 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR12(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR12_SHIFT)) & MU_GCR_GIR12_MASK)

#define MU_GCR_GIR13_MASK                        (0x2000U)
#define MU_GCR_GIR13_SHIFT                       (13U)
/*! GIR13 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR13(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR13_SHIFT)) & MU_GCR_GIR13_MASK)

#define MU_GCR_GIR14_MASK                        (0x4000U)
#define MU_GCR_GIR14_SHIFT                       (14U)
/*! GIR14 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR14(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR14_SHIFT)) & MU_GCR_GIR14_MASK)

#define MU_GCR_GIR15_MASK                        (0x8000U)
#define MU_GCR_GIR15_SHIFT                       (15U)
/*! GIR15 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR15(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR15_SHIFT)) & MU_GCR_GIR15_MASK)

#define MU_GCR_GIR16_MASK                        (0x10000U)
#define MU_GCR_GIR16_SHIFT                       (16U)
/*! GIR16 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR16(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR16_SHIFT)) & MU_GCR_GIR16_MASK)

#define MU_GCR_GIR17_MASK                        (0x20000U)
#define MU_GCR_GIR17_SHIFT                       (17U)
/*! GIR17 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR17(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR17_SHIFT)) & MU_GCR_GIR17_MASK)

#define MU_GCR_GIR18_MASK                        (0x40000U)
#define MU_GCR_GIR18_SHIFT                       (18U)
/*! GIR18 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR18(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR18_SHIFT)) & MU_GCR_GIR18_MASK)

#define MU_GCR_GIR19_MASK                        (0x80000U)
#define MU_GCR_GIR19_SHIFT                       (19U)
/*! GIR19 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR19(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR19_SHIFT)) & MU_GCR_GIR19_MASK)
/*! @} */

/*! @name GSR - General-purpose Status */
/*! @{ */

#define MU_GSR_GIP0_MASK                         (0x1U)
#define MU_GSR_GIP0_SHIFT                        (0U)
/*! GIP0 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP0_SHIFT)) & MU_GSR_GIP0_MASK)

#define MU_GSR_GIP1_MASK                         (0x2U)
#define MU_GSR_GIP1_SHIFT                        (1U)
/*! GIP1 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP1_SHIFT)) & MU_GSR_GIP1_MASK)

#define MU_GSR_GIP2_MASK                         (0x4U)
#define MU_GSR_GIP2_SHIFT                        (2U)
/*! GIP2 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP2_SHIFT)) & MU_GSR_GIP2_MASK)

#define MU_GSR_GIP3_MASK                         (0x8U)
#define MU_GSR_GIP3_SHIFT                        (3U)
/*! GIP3 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP3_SHIFT)) & MU_GSR_GIP3_MASK)

#define MU_GSR_GIP4_MASK                         (0x10U)
#define MU_GSR_GIP4_SHIFT                        (4U)
/*! GIP4 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP4(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP4_SHIFT)) & MU_GSR_GIP4_MASK)

#define MU_GSR_GIP5_MASK                         (0x20U)
#define MU_GSR_GIP5_SHIFT                        (5U)
/*! GIP5 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP5(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP5_SHIFT)) & MU_GSR_GIP5_MASK)

#define MU_GSR_GIP6_MASK                         (0x40U)
#define MU_GSR_GIP6_SHIFT                        (6U)
/*! GIP6 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP6(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP6_SHIFT)) & MU_GSR_GIP6_MASK)

#define MU_GSR_GIP7_MASK                         (0x80U)
#define MU_GSR_GIP7_SHIFT                        (7U)
/*! GIP7 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP7(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP7_SHIFT)) & MU_GSR_GIP7_MASK)

#define MU_GSR_GIP8_MASK                         (0x100U)
#define MU_GSR_GIP8_SHIFT                        (8U)
/*! GIP8 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP8(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP8_SHIFT)) & MU_GSR_GIP8_MASK)

#define MU_GSR_GIP9_MASK                         (0x200U)
#define MU_GSR_GIP9_SHIFT                        (9U)
/*! GIP9 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP9(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP9_SHIFT)) & MU_GSR_GIP9_MASK)

#define MU_GSR_GIP10_MASK                        (0x400U)
#define MU_GSR_GIP10_SHIFT                       (10U)
/*! GIP10 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP10(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP10_SHIFT)) & MU_GSR_GIP10_MASK)

#define MU_GSR_GIP11_MASK                        (0x800U)
#define MU_GSR_GIP11_SHIFT                       (11U)
/*! GIP11 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP11(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP11_SHIFT)) & MU_GSR_GIP11_MASK)

#define MU_GSR_GIP12_MASK                        (0x1000U)
#define MU_GSR_GIP12_SHIFT                       (12U)
/*! GIP12 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP12(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP12_SHIFT)) & MU_GSR_GIP12_MASK)

#define MU_GSR_GIP13_MASK                        (0x2000U)
#define MU_GSR_GIP13_SHIFT                       (13U)
/*! GIP13 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP13(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP13_SHIFT)) & MU_GSR_GIP13_MASK)

#define MU_GSR_GIP14_MASK                        (0x4000U)
#define MU_GSR_GIP14_SHIFT                       (14U)
/*! GIP14 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP14(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP14_SHIFT)) & MU_GSR_GIP14_MASK)

#define MU_GSR_GIP15_MASK                        (0x8000U)
#define MU_GSR_GIP15_SHIFT                       (15U)
/*! GIP15 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP15(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP15_SHIFT)) & MU_GSR_GIP15_MASK)

#define MU_GSR_GIP16_MASK                        (0x10000U)
#define MU_GSR_GIP16_SHIFT                       (16U)
/*! GIP16 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP16(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP16_SHIFT)) & MU_GSR_GIP16_MASK)

#define MU_GSR_GIP17_MASK                        (0x20000U)
#define MU_GSR_GIP17_SHIFT                       (17U)
/*! GIP17 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP17(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP17_SHIFT)) & MU_GSR_GIP17_MASK)

#define MU_GSR_GIP18_MASK                        (0x40000U)
#define MU_GSR_GIP18_SHIFT                       (18U)
/*! GIP18 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP18(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP18_SHIFT)) & MU_GSR_GIP18_MASK)

#define MU_GSR_GIP19_MASK                        (0x80000U)
#define MU_GSR_GIP19_SHIFT                       (19U)
/*! GIP19 - pd_vsys.cm0p_mix.mub General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP19(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP19_SHIFT)) & MU_GSR_GIP19_MASK)
/*! @} */

/*! @name TCR - Transmit Control */
/*! @{ */

#define MU_TCR_TIE0_MASK                         (0x1U)
#define MU_TCR_TIE0_SHIFT                        (0U)
/*! TIE0 - pd_vsys.cm0p_mix.mub Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE0_SHIFT)) & MU_TCR_TIE0_MASK)

#define MU_TCR_TIE1_MASK                         (0x2U)
#define MU_TCR_TIE1_SHIFT                        (1U)
/*! TIE1 - pd_vsys.cm0p_mix.mub Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE1_SHIFT)) & MU_TCR_TIE1_MASK)

#define MU_TCR_TIE2_MASK                         (0x4U)
#define MU_TCR_TIE2_SHIFT                        (2U)
/*! TIE2 - pd_vsys.cm0p_mix.mub Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE2_SHIFT)) & MU_TCR_TIE2_MASK)

#define MU_TCR_TIE3_MASK                         (0x8U)
#define MU_TCR_TIE3_SHIFT                        (3U)
/*! TIE3 - pd_vsys.cm0p_mix.mub Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE3_SHIFT)) & MU_TCR_TIE3_MASK)
/*! @} */

/*! @name TSR - Transmit Status */
/*! @{ */

#define MU_TSR_TE0_MASK                          (0x1U)
#define MU_TSR_TE0_SHIFT                         (0U)
/*! TE0 - pd_vsys.cm0p_mix.mub Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE0_SHIFT)) & MU_TSR_TE0_MASK)

#define MU_TSR_TE1_MASK                          (0x2U)
#define MU_TSR_TE1_SHIFT                         (1U)
/*! TE1 - pd_vsys.cm0p_mix.mub Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE1_SHIFT)) & MU_TSR_TE1_MASK)

#define MU_TSR_TE2_MASK                          (0x4U)
#define MU_TSR_TE2_SHIFT                         (2U)
/*! TE2 - pd_vsys.cm0p_mix.mub Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE2_SHIFT)) & MU_TSR_TE2_MASK)

#define MU_TSR_TE3_MASK                          (0x8U)
#define MU_TSR_TE3_SHIFT                         (3U)
/*! TE3 - pd_vsys.cm0p_mix.mub Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE3_SHIFT)) & MU_TSR_TE3_MASK)
/*! @} */

/*! @name RCR - Receive Control */
/*! @{ */

#define MU_RCR_RIE0_MASK                         (0x1U)
#define MU_RCR_RIE0_SHIFT                        (0U)
/*! RIE0 - pd_vsys.cm0p_mix.mub Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE0_SHIFT)) & MU_RCR_RIE0_MASK)

#define MU_RCR_RIE1_MASK                         (0x2U)
#define MU_RCR_RIE1_SHIFT                        (1U)
/*! RIE1 - pd_vsys.cm0p_mix.mub Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE1_SHIFT)) & MU_RCR_RIE1_MASK)

#define MU_RCR_RIE2_MASK                         (0x4U)
#define MU_RCR_RIE2_SHIFT                        (2U)
/*! RIE2 - pd_vsys.cm0p_mix.mub Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE2_SHIFT)) & MU_RCR_RIE2_MASK)

#define MU_RCR_RIE3_MASK                         (0x8U)
#define MU_RCR_RIE3_SHIFT                        (3U)
/*! RIE3 - pd_vsys.cm0p_mix.mub Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE3_SHIFT)) & MU_RCR_RIE3_MASK)
/*! @} */

/*! @name RSR - Receive Status */
/*! @{ */

#define MU_RSR_RF0_MASK                          (0x1U)
#define MU_RSR_RF0_SHIFT                         (0U)
/*! RF0 - pd_vsys.cm0p_mix.mub Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF0_SHIFT)) & MU_RSR_RF0_MASK)

#define MU_RSR_RF1_MASK                          (0x2U)
#define MU_RSR_RF1_SHIFT                         (1U)
/*! RF1 - pd_vsys.cm0p_mix.mub Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF1_SHIFT)) & MU_RSR_RF1_MASK)

#define MU_RSR_RF2_MASK                          (0x4U)
#define MU_RSR_RF2_SHIFT                         (2U)
/*! RF2 - pd_vsys.cm0p_mix.mub Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF2_SHIFT)) & MU_RSR_RF2_MASK)

#define MU_RSR_RF3_MASK                          (0x8U)
#define MU_RSR_RF3_SHIFT                         (3U)
/*! RF3 - pd_vsys.cm0p_mix.mub Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF3_SHIFT)) & MU_RSR_RF3_MASK)
/*! @} */

/*! @name TR - Transmit */
/*! @{ */

#define MU_TR_TR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_TR_TR_DATA_SHIFT                      (0U)
/*! TR_DATA - pd_vsys.cm0p_mix.mub Transmit Data */
#define MU_TR_TR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << MU_TR_TR_DATA_SHIFT)) & MU_TR_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive */
/*! @{ */

#define MU_RR_RR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_RR_RR_DATA_SHIFT                      (0U)
/*! RR_DATA - pd_vsys.cm0p_mix.mub Receive Data */
#define MU_RR_RR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << MU_RR_RR_DATA_SHIFT)) & MU_RR_RR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MU_Register_Masks */


/*!
 * @}
 */ /* end of group MU_Peripheral_Access_Layer */


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


#endif  /* PERI_MU_H_ */

