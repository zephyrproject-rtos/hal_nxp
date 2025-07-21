/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MU
 *
 * CMSIS Peripheral Access Layer for MU
 */

#if !defined(PERI_MU_H_)
#define PERI_MU_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
  __IO uint32_t SR;                                /**< Status, offset: 0xC */
       uint32_t CCR0;                              /**< Core Control 0, offset: 0x10 */
       uint32_t CIER0;                             /**< Core Interrupt Enable 0, offset: 0x14 */
       uint8_t RESERVED_0[232];
  __IO uint32_t FCR;                               /**< Flag Control, offset: 0x100 */
  __I  uint32_t FSR;                               /**< Flag Status, offset: 0x104 */
       uint8_t RESERVED_1[8];
  __IO uint32_t GIER;                              /**< General-Purpose Interrupt Enable, offset: 0x110 */
  __IO uint32_t GCR;                               /**< General-Purpose Control, offset: 0x114 */
  __IO uint32_t GSR;                               /**< General-purpose Status, offset: 0x118 */
       uint8_t RESERVED_2[4];
  __IO uint32_t TCR;                               /**< Transmit Control, offset: 0x120 */
  __I  uint32_t TSR;                               /**< Transmit Status, offset: 0x124 */
  __IO uint32_t RCR;                               /**< Receive Control, offset: 0x128 */
  __I  uint32_t RSR;                               /**< Receive Status, offset: 0x12C */
       uint8_t RESERVED_3[208];
  __IO uint32_t TR[MU_TR_COUNT];                   /**< Transmit, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_4[112];
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

#define MU_CR_MURIE_MASK                         (0x2U)
#define MU_CR_MURIE_SHIFT                        (1U)
/*! MURIE - MUB Reset Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_CR_MURIE(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CR_MURIE_SHIFT)) & MU_CR_MURIE_MASK)
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

#define MU_SR_MURIP_MASK                         (0x2U)
#define MU_SR_MURIP_SHIFT                        (1U)
/*! MURIP - MU Reset Interrupt Pending Flag
 *  0b0..No effect
 *  0b0..Reset not issued
 *  0b1..Clear the flag
 *  0b1..Reset issued
 */
#define MU_SR_MURIP(x)                           (((uint32_t)(((uint32_t)(x)) << MU_SR_MURIP_SHIFT)) & MU_SR_MURIP_MASK)

#define MU_SR_EP_MASK                            (0x4U)
#define MU_SR_EP_SHIFT                           (2U)
/*! EP - MUB Side Event Pending
 *  0b0..Not pending
 *  0b1..Pending
 */
#define MU_SR_EP(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_EP_SHIFT)) & MU_SR_EP_MASK)

#define MU_SR_FUP_MASK                           (0x8U)
#define MU_SR_FUP_SHIFT                          (3U)
/*! FUP - MUB Flag Update Pending
 *  0b0..No pending update flags (initiated by MUA)
 *  0b1..Pending update flags (initiated by MUA)
 */
#define MU_SR_FUP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_FUP_SHIFT)) & MU_SR_FUP_MASK)

#define MU_SR_GIRP_MASK                          (0x10U)
#define MU_SR_GIRP_SHIFT                         (4U)
/*! GIRP - MUB General-Purpose Interrupt Pending
 *  0b0..No request sent
 *  0b1..Request sent
 */
#define MU_SR_GIRP(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_GIRP_SHIFT)) & MU_SR_GIRP_MASK)

#define MU_SR_TEP_MASK                           (0x20U)
#define MU_SR_TEP_SHIFT                          (5U)
/*! TEP - MUB Transmit Empty Pending
 *  0b0..Not pending; MUA is reading no Receive (RRn) register
 *  0b1..Pending; MUA is reading a Receive (RRn) register
 */
#define MU_SR_TEP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_TEP_SHIFT)) & MU_SR_TEP_MASK)

#define MU_SR_RFP_MASK                           (0x40U)
#define MU_SR_RFP_SHIFT                          (6U)
/*! RFP - MUB Receive Full Pending
 *  0b0..Not pending; MUA is not writing to a Transmit register
 *  0b1..Pending; MUA is writing to a Transmit register
 */
#define MU_SR_RFP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_RFP_SHIFT)) & MU_SR_RFP_MASK)
/*! @} */

/*! @name FCR - Flag Control */
/*! @{ */

#define MU_FCR_F0_MASK                           (0x1U)
#define MU_FCR_F0_SHIFT                          (0U)
/*! F0 - MUB to MUA Flag
 *  0b0..Clear MUA_FSR[Fn]
 *  0b1..Set MUA_FSR[Fn]
 */
#define MU_FCR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F0_SHIFT)) & MU_FCR_F0_MASK)

#define MU_FCR_F1_MASK                           (0x2U)
#define MU_FCR_F1_SHIFT                          (1U)
/*! F1 - MUB to MUA Flag
 *  0b0..Clear MUA_FSR[Fn]
 *  0b1..Set MUA_FSR[Fn]
 */
#define MU_FCR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F1_SHIFT)) & MU_FCR_F1_MASK)

#define MU_FCR_F2_MASK                           (0x4U)
#define MU_FCR_F2_SHIFT                          (2U)
/*! F2 - MUB to MUA Flag
 *  0b0..Clear MUA_FSR[Fn]
 *  0b1..Set MUA_FSR[Fn]
 */
#define MU_FCR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F2_SHIFT)) & MU_FCR_F2_MASK)
/*! @} */

/*! @name FSR - Flag Status */
/*! @{ */

#define MU_FSR_F0_MASK                           (0x1U)
#define MU_FSR_F0_SHIFT                          (0U)
/*! F0 - MUB to MUA-Side Flag
 *  0b0..MUA_FCR[Fn] = 0
 *  0b1..MUA_FCR[Fn] = 1
 */
#define MU_FSR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F0_SHIFT)) & MU_FSR_F0_MASK)

#define MU_FSR_F1_MASK                           (0x2U)
#define MU_FSR_F1_SHIFT                          (1U)
/*! F1 - MUB to MUA-Side Flag
 *  0b0..MUA_FCR[Fn] = 0
 *  0b1..MUA_FCR[Fn] = 1
 */
#define MU_FSR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F1_SHIFT)) & MU_FSR_F1_MASK)

#define MU_FSR_F2_MASK                           (0x4U)
#define MU_FSR_F2_SHIFT                          (2U)
/*! F2 - MUB to MUA-Side Flag
 *  0b0..MUA_FCR[Fn] = 0
 *  0b1..MUA_FCR[Fn] = 1
 */
#define MU_FSR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F2_SHIFT)) & MU_FSR_F2_MASK)
/*! @} */

/*! @name GIER - General-Purpose Interrupt Enable */
/*! @{ */

#define MU_GIER_GIE0_MASK                        (0x1U)
#define MU_GIER_GIE0_SHIFT                       (0U)
/*! GIE0 - MUB General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE0(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE0_SHIFT)) & MU_GIER_GIE0_MASK)

#define MU_GIER_GIE1_MASK                        (0x2U)
#define MU_GIER_GIE1_SHIFT                       (1U)
/*! GIE1 - MUB General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE1(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE1_SHIFT)) & MU_GIER_GIE1_MASK)

#define MU_GIER_GIE2_MASK                        (0x4U)
#define MU_GIER_GIE2_SHIFT                       (2U)
/*! GIE2 - MUB General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE2(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE2_SHIFT)) & MU_GIER_GIE2_MASK)

#define MU_GIER_GIE3_MASK                        (0x8U)
#define MU_GIER_GIE3_SHIFT                       (3U)
/*! GIE3 - MUB General-purpose Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_GIER_GIE3(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE3_SHIFT)) & MU_GIER_GIE3_MASK)
/*! @} */

/*! @name GCR - General-Purpose Control */
/*! @{ */

#define MU_GCR_GIR0_MASK                         (0x1U)
#define MU_GCR_GIR0_SHIFT                        (0U)
/*! GIR0 - MUB General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR0_SHIFT)) & MU_GCR_GIR0_MASK)

#define MU_GCR_GIR1_MASK                         (0x2U)
#define MU_GCR_GIR1_SHIFT                        (1U)
/*! GIR1 - MUB General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR1_SHIFT)) & MU_GCR_GIR1_MASK)

#define MU_GCR_GIR2_MASK                         (0x4U)
#define MU_GCR_GIR2_SHIFT                        (2U)
/*! GIR2 - MUB General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR2_SHIFT)) & MU_GCR_GIR2_MASK)

#define MU_GCR_GIR3_MASK                         (0x8U)
#define MU_GCR_GIR3_SHIFT                        (3U)
/*! GIR3 - MUB General-Purpose Interrupt Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define MU_GCR_GIR3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR3_SHIFT)) & MU_GCR_GIR3_MASK)
/*! @} */

/*! @name GSR - General-purpose Status */
/*! @{ */

#define MU_GSR_GIP0_MASK                         (0x1U)
#define MU_GSR_GIP0_SHIFT                        (0U)
/*! GIP0 - MUB General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP0_SHIFT)) & MU_GSR_GIP0_MASK)

#define MU_GSR_GIP1_MASK                         (0x2U)
#define MU_GSR_GIP1_SHIFT                        (1U)
/*! GIP1 - MUB General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP1_SHIFT)) & MU_GSR_GIP1_MASK)

#define MU_GSR_GIP2_MASK                         (0x4U)
#define MU_GSR_GIP2_SHIFT                        (2U)
/*! GIP2 - MUB General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP2_SHIFT)) & MU_GSR_GIP2_MASK)

#define MU_GSR_GIP3_MASK                         (0x8U)
#define MU_GSR_GIP3_SHIFT                        (3U)
/*! GIP3 - MUB General-Purpose Interrupt Request Pending
 *  0b0..No effect
 *  0b0..Not pending
 *  0b1..Clear the flag
 *  0b1..Pending
 */
#define MU_GSR_GIP3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP3_SHIFT)) & MU_GSR_GIP3_MASK)
/*! @} */

/*! @name TCR - Transmit Control */
/*! @{ */

#define MU_TCR_TIE0_MASK                         (0x1U)
#define MU_TCR_TIE0_SHIFT                        (0U)
/*! TIE0 - MUB Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE0_SHIFT)) & MU_TCR_TIE0_MASK)

#define MU_TCR_TIE1_MASK                         (0x2U)
#define MU_TCR_TIE1_SHIFT                        (1U)
/*! TIE1 - MUB Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE1_SHIFT)) & MU_TCR_TIE1_MASK)

#define MU_TCR_TIE2_MASK                         (0x4U)
#define MU_TCR_TIE2_SHIFT                        (2U)
/*! TIE2 - MUB Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE2_SHIFT)) & MU_TCR_TIE2_MASK)

#define MU_TCR_TIE3_MASK                         (0x8U)
#define MU_TCR_TIE3_SHIFT                        (3U)
/*! TIE3 - MUB Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_TCR_TIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE3_SHIFT)) & MU_TCR_TIE3_MASK)
/*! @} */

/*! @name TSR - Transmit Status */
/*! @{ */

#define MU_TSR_TE0_MASK                          (0x1U)
#define MU_TSR_TE0_SHIFT                         (0U)
/*! TE0 - MUB Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE0_SHIFT)) & MU_TSR_TE0_MASK)

#define MU_TSR_TE1_MASK                          (0x2U)
#define MU_TSR_TE1_SHIFT                         (1U)
/*! TE1 - MUB Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE1_SHIFT)) & MU_TSR_TE1_MASK)

#define MU_TSR_TE2_MASK                          (0x4U)
#define MU_TSR_TE2_SHIFT                         (2U)
/*! TE2 - MUB Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE2_SHIFT)) & MU_TSR_TE2_MASK)

#define MU_TSR_TE3_MASK                          (0x8U)
#define MU_TSR_TE3_SHIFT                         (3U)
/*! TE3 - MUB Transmit Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define MU_TSR_TE3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE3_SHIFT)) & MU_TSR_TE3_MASK)
/*! @} */

/*! @name RCR - Receive Control */
/*! @{ */

#define MU_RCR_RIE0_MASK                         (0x1U)
#define MU_RCR_RIE0_SHIFT                        (0U)
/*! RIE0 - MUB Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE0_SHIFT)) & MU_RCR_RIE0_MASK)

#define MU_RCR_RIE1_MASK                         (0x2U)
#define MU_RCR_RIE1_SHIFT                        (1U)
/*! RIE1 - MUB Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE1_SHIFT)) & MU_RCR_RIE1_MASK)

#define MU_RCR_RIE2_MASK                         (0x4U)
#define MU_RCR_RIE2_SHIFT                        (2U)
/*! RIE2 - MUB Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE2_SHIFT)) & MU_RCR_RIE2_MASK)

#define MU_RCR_RIE3_MASK                         (0x8U)
#define MU_RCR_RIE3_SHIFT                        (3U)
/*! RIE3 - MUB Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MU_RCR_RIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE3_SHIFT)) & MU_RCR_RIE3_MASK)
/*! @} */

/*! @name RSR - Receive Status */
/*! @{ */

#define MU_RSR_RF0_MASK                          (0x1U)
#define MU_RSR_RF0_SHIFT                         (0U)
/*! RF0 - MUB Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF0_SHIFT)) & MU_RSR_RF0_MASK)

#define MU_RSR_RF1_MASK                          (0x2U)
#define MU_RSR_RF1_SHIFT                         (1U)
/*! RF1 - MUB Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF1_SHIFT)) & MU_RSR_RF1_MASK)

#define MU_RSR_RF2_MASK                          (0x4U)
#define MU_RSR_RF2_SHIFT                         (2U)
/*! RF2 - MUB Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF2_SHIFT)) & MU_RSR_RF2_MASK)

#define MU_RSR_RF3_MASK                          (0x8U)
#define MU_RSR_RF3_SHIFT                         (3U)
/*! RF3 - MUB Receive Register Full
 *  0b0..Not full
 *  0b1..Full
 */
#define MU_RSR_RF3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF3_SHIFT)) & MU_RSR_RF3_MASK)
/*! @} */

/*! @name TR - Transmit */
/*! @{ */

#define MU_TR_TR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_TR_TR_DATA_SHIFT                      (0U)
/*! TR_DATA - MUB Transmit Data */
#define MU_TR_TR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << MU_TR_TR_DATA_SHIFT)) & MU_TR_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive */
/*! @{ */

#define MU_RR_RR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_RR_RR_DATA_SHIFT                      (0U)
/*! RR_DATA - MUB Receive Data */
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

