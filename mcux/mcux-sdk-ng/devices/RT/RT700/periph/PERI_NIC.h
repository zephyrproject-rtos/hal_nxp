/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NIC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_NIC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NIC
 *
 * CMSIS Peripheral Access Layer for NIC
 */

#if !defined(PERI_NIC_H_)
#define PERI_NIC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- NIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NIC_Peripheral_Access_Layer NIC Peripheral Access Layer
 * @{
 */

/** NIC - Size of Registers Arrays */
#define NIC_ASIB_COUNT                            10u

/** NIC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[73728];
  struct {                                         /* offset: 0x12000, array step: 0x1000 */
         uint8_t RESERVED_0[256];
    __IO uint32_t READ_QOS;                          /**< Read Channel QoS Value, array offset: 0x12100, array step: 0x1000 */
    __IO uint32_t WRITE_QOS;                         /**< Write Channel QoS Value, array offset: 0x12104, array step: 0x1000 */
    __IO uint32_t FN_MOD;                            /**< Issuing Functionality Modification, array offset: 0x12108, array step: 0x1000 */
    __IO uint32_t QOS_CNTL;                          /**< QoS Control, array offset: 0x1210C, array step: 0x1000 */
    __IO uint32_t MAX_OT;                            /**< Maximum Number of Outstanding Transactions, array offset: 0x12110, array step: 0x1000 */
    __IO uint32_t MAX_COMB_OT;                       /**< Maximum Combined Outstanding Transactions, array offset: 0x12114, array step: 0x1000 */
    __IO uint32_t AW_P;                              /**< AW Channel Peak Rate, array offset: 0x12118, array step: 0x1000 */
    __IO uint32_t AW_B;                              /**< AW Channel Burstiness Allowance, array offset: 0x1211C, array step: 0x1000 */
    __IO uint32_t AW_R;                              /**< AW Channel Average Rate, array offset: 0x12120, array step: 0x1000 */
    __IO uint32_t AR_P;                              /**< AR Channel Peak Rate, array offset: 0x12124, array step: 0x1000 */
    __IO uint32_t AR_B;                              /**< AR Channel Burstiness Allowance, array offset: 0x12128, array step: 0x1000 */
    __IO uint32_t AR_R;                              /**< AR Channel Average Rate, array offset: 0x1212C, array step: 0x1000 */
    __IO uint32_t TARGET_FC;                         /**< Feedback Controlled Target, array offset: 0x12130, array step: 0x1000 */
    __IO uint32_t KI_FC;                             /**< Feedback Controlled Scale, array offset: 0x12134, array step: 0x1000 */
    __IO uint32_t QOS_RANGE;                         /**< QoS Range, array offset: 0x12138, array step: 0x1000 */
         uint8_t RESERVED_1[3780];
  } ASIB[NIC_ASIB_COUNT];
} NIC_Type;

/* ----------------------------------------------------------------------------
   -- NIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NIC_Register_Masks NIC Register Masks
 * @{
 */

/*! @name READ_QOS - Read Channel QoS Value */
/*! @{ */

#define NIC_READ_QOS_READ_QOS_MASK               (0xFU)
#define NIC_READ_QOS_READ_QOS_SHIFT              (0U)
/*! READ_QOS - Read Channel QoS Value
 *  0b0000..The lowest priority
 *  0b0001-0b1110.....
 *  0b1111..The highest priority
 */
#define NIC_READ_QOS_READ_QOS(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_READ_QOS_READ_QOS_SHIFT)) & NIC_READ_QOS_READ_QOS_MASK)
/*! @} */

/* The count of NIC_READ_QOS */
#define NIC_READ_QOS_COUNT                       (10U)

/*! @name WRITE_QOS - Write Channel QoS Value */
/*! @{ */

#define NIC_WRITE_QOS_WRITE_QOS_MASK             (0xFU)
#define NIC_WRITE_QOS_WRITE_QOS_SHIFT            (0U)
/*! WRITE_QOS - Write channel QoS value
 *  0b0000..The lowest priority
 *  0b0001-0b1110.....
 *  0b1111..The highest priority
 */
#define NIC_WRITE_QOS_WRITE_QOS(x)               (((uint32_t)(((uint32_t)(x)) << NIC_WRITE_QOS_WRITE_QOS_SHIFT)) & NIC_WRITE_QOS_WRITE_QOS_MASK)
/*! @} */

/* The count of NIC_WRITE_QOS */
#define NIC_WRITE_QOS_COUNT                      (10U)

/*! @name FN_MOD - Issuing Functionality Modification */
/*! @{ */

#define NIC_FN_MOD_FN_MOD_MASK                   (0x3U)
#define NIC_FN_MOD_FN_MOD_SHIFT                  (0U)
/*! FN_MOD - Issuing Functionality Modification
 *  0b00..Default issuing
 *  0b01..Read issuing
 *  0b10..Write issuing
 *  0b11..Read and write issuing
 */
#define NIC_FN_MOD_FN_MOD(x)                     (((uint32_t)(((uint32_t)(x)) << NIC_FN_MOD_FN_MOD_SHIFT)) & NIC_FN_MOD_FN_MOD_MASK)
/*! @} */

/* The count of NIC_FN_MOD */
#define NIC_FN_MOD_COUNT                         (10U)

/*! @name QOS_CNTL - QoS Control */
/*! @{ */

#define NIC_QOS_CNTL_EN_AW_RATE_MASK             (0x1U)
#define NIC_QOS_CNTL_EN_AW_RATE_SHIFT            (0U)
/*! EN_AW_RATE - Enable AW Transaction Rate Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AW_RATE(x)               (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AW_RATE_SHIFT)) & NIC_QOS_CNTL_EN_AW_RATE_MASK)

#define NIC_QOS_CNTL_EN_AR_RATE_MASK             (0x2U)
#define NIC_QOS_CNTL_EN_AR_RATE_SHIFT            (1U)
/*! EN_AR_RATE - Enable AR Transaction Rate Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AR_RATE(x)               (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AR_RATE_SHIFT)) & NIC_QOS_CNTL_EN_AR_RATE_MASK)

#define NIC_QOS_CNTL_EN_AWAR_RATE_MASK           (0x4U)
#define NIC_QOS_CNTL_EN_AWAR_RATE_SHIFT          (2U)
/*! EN_AWAR_RATE - Enable Combined AW And AR Transaction Rate Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AWAR_RATE(x)             (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AWAR_RATE_SHIFT)) & NIC_QOS_CNTL_EN_AWAR_RATE_MASK)

#define NIC_QOS_CNTL_EN_AW_FC_MASK               (0x8U)
#define NIC_QOS_CNTL_EN_AW_FC_SHIFT              (3U)
/*! EN_AW_FC - Enable AW Feedback Control Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AW_FC(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AW_FC_SHIFT)) & NIC_QOS_CNTL_EN_AW_FC_MASK)

#define NIC_QOS_CNTL_EN_AR_FC_MASK               (0x10U)
#define NIC_QOS_CNTL_EN_AR_FC_SHIFT              (4U)
/*! EN_AR_FC - Enable AR Feedback Control Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AR_FC(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AR_FC_SHIFT)) & NIC_QOS_CNTL_EN_AR_FC_MASK)

#define NIC_QOS_CNTL_EN_AW_OT_MASK               (0x20U)
#define NIC_QOS_CNTL_EN_AW_OT_SHIFT              (5U)
/*! EN_AW_OT - Enable AW Outstanding Transaction Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AW_OT(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AW_OT_SHIFT)) & NIC_QOS_CNTL_EN_AW_OT_MASK)

#define NIC_QOS_CNTL_EN_AR_OT_MASK               (0x40U)
#define NIC_QOS_CNTL_EN_AR_OT_SHIFT              (6U)
/*! EN_AR_OT - Enable AR Outstanding Transaction Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AR_OT(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AR_OT_SHIFT)) & NIC_QOS_CNTL_EN_AR_OT_MASK)

#define NIC_QOS_CNTL_EN_AWAR_OT_MASK             (0x80U)
#define NIC_QOS_CNTL_EN_AWAR_OT_SHIFT            (7U)
/*! EN_AWAR_OT - Enable AW/AR Outstanding Transaction Regulation
 *  0b0..Disables
 *  0b1..Enables
 */
#define NIC_QOS_CNTL_EN_AWAR_OT(x)               (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_EN_AWAR_OT_SHIFT)) & NIC_QOS_CNTL_EN_AWAR_OT_MASK)

#define NIC_QOS_CNTL_MODE_AW_FC_MASK             (0x10000U)
#define NIC_QOS_CNTL_MODE_AW_FC_SHIFT            (16U)
/*! MODE_AW_FC - AW Feedback Control Mode
 *  0b0..Transaction latency
 *  0b1..Address latency
 */
#define NIC_QOS_CNTL_MODE_AW_FC(x)               (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_MODE_AW_FC_SHIFT)) & NIC_QOS_CNTL_MODE_AW_FC_MASK)

#define NIC_QOS_CNTL_MODE_AR_FC_MASK             (0x100000U)
#define NIC_QOS_CNTL_MODE_AR_FC_SHIFT            (20U)
/*! MODE_AR_FC - AR Feedback Control Mode
 *  0b0..Transaction latency
 *  0b1..Address latency
 */
#define NIC_QOS_CNTL_MODE_AR_FC(x)               (((uint32_t)(((uint32_t)(x)) << NIC_QOS_CNTL_MODE_AR_FC_SHIFT)) & NIC_QOS_CNTL_MODE_AR_FC_MASK)
/*! @} */

/* The count of NIC_QOS_CNTL */
#define NIC_QOS_CNTL_COUNT                       (10U)

/*! @name MAX_OT - Maximum Number of Outstanding Transactions */
/*! @{ */

#define NIC_MAX_OT_AW_MAX_OTF_MASK               (0xFFU)
#define NIC_MAX_OT_AW_MAX_OTF_SHIFT              (0U)
/*! AW_MAX_OTF - Fractional Part of Maximum Outstanding AW Addresses */
#define NIC_MAX_OT_AW_MAX_OTF(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_MAX_OT_AW_MAX_OTF_SHIFT)) & NIC_MAX_OT_AW_MAX_OTF_MASK)

#define NIC_MAX_OT_AW_MAX_OTI_MASK               (0x3F00U)
#define NIC_MAX_OT_AW_MAX_OTI_SHIFT              (8U)
/*! AW_MAX_OTI - Integer Part of Maximum Outstanding AW Addresses */
#define NIC_MAX_OT_AW_MAX_OTI(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_MAX_OT_AW_MAX_OTI_SHIFT)) & NIC_MAX_OT_AW_MAX_OTI_MASK)

#define NIC_MAX_OT_AR_MAX_OTF_MASK               (0xFF0000U)
#define NIC_MAX_OT_AR_MAX_OTF_SHIFT              (16U)
/*! AR_MAX_OTF - Fractional Part of Maximum Outstanding AR Addresses */
#define NIC_MAX_OT_AR_MAX_OTF(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_MAX_OT_AR_MAX_OTF_SHIFT)) & NIC_MAX_OT_AR_MAX_OTF_MASK)

#define NIC_MAX_OT_AR_MAX_OTI_MASK               (0x3F000000U)
#define NIC_MAX_OT_AR_MAX_OTI_SHIFT              (24U)
/*! AR_MAX_OTI - Integer Part of Maximum Outstanding AR Addresses */
#define NIC_MAX_OT_AR_MAX_OTI(x)                 (((uint32_t)(((uint32_t)(x)) << NIC_MAX_OT_AR_MAX_OTI_SHIFT)) & NIC_MAX_OT_AR_MAX_OTI_MASK)
/*! @} */

/* The count of NIC_MAX_OT */
#define NIC_MAX_OT_COUNT                         (10U)

/*! @name MAX_COMB_OT - Maximum Combined Outstanding Transactions */
/*! @{ */

#define NIC_MAX_COMB_OT_AWAR_MAX_OTF_MASK        (0xFFU)
#define NIC_MAX_COMB_OT_AWAR_MAX_OTF_SHIFT       (0U)
/*! AWAR_MAX_OTF - Fractional Part of Maximum Combined Outstanding AW and AR Addresses */
#define NIC_MAX_COMB_OT_AWAR_MAX_OTF(x)          (((uint32_t)(((uint32_t)(x)) << NIC_MAX_COMB_OT_AWAR_MAX_OTF_SHIFT)) & NIC_MAX_COMB_OT_AWAR_MAX_OTF_MASK)

#define NIC_MAX_COMB_OT_AWAR_MAX_OTI_MASK        (0x7F00U)
#define NIC_MAX_COMB_OT_AWAR_MAX_OTI_SHIFT       (8U)
/*! AWAR_MAX_OTI - Integer Part of Maximum Combined Outstanding AW and AR Addresses */
#define NIC_MAX_COMB_OT_AWAR_MAX_OTI(x)          (((uint32_t)(((uint32_t)(x)) << NIC_MAX_COMB_OT_AWAR_MAX_OTI_SHIFT)) & NIC_MAX_COMB_OT_AWAR_MAX_OTI_MASK)
/*! @} */

/* The count of NIC_MAX_COMB_OT */
#define NIC_MAX_COMB_OT_COUNT                    (10U)

/*! @name AW_P - AW Channel Peak Rate */
/*! @{ */

#define NIC_AW_P_AW_P_MASK                       (0xFF000000U)
#define NIC_AW_P_AW_P_SHIFT                      (24U)
/*! AW_P - AW Channel Peak Rate */
#define NIC_AW_P_AW_P(x)                         (((uint32_t)(((uint32_t)(x)) << NIC_AW_P_AW_P_SHIFT)) & NIC_AW_P_AW_P_MASK)
/*! @} */

/* The count of NIC_AW_P */
#define NIC_AW_P_COUNT                           (10U)

/*! @name AW_B - AW Channel Burstiness Allowance */
/*! @{ */

#define NIC_AW_B_AW_B_MASK                       (0xFFFFU)
#define NIC_AW_B_AW_B_SHIFT                      (0U)
/*! AW_B - AW Channel Burstiness */
#define NIC_AW_B_AW_B(x)                         (((uint32_t)(((uint32_t)(x)) << NIC_AW_B_AW_B_SHIFT)) & NIC_AW_B_AW_B_MASK)
/*! @} */

/* The count of NIC_AW_B */
#define NIC_AW_B_COUNT                           (10U)

/*! @name AW_R - AW Channel Average Rate */
/*! @{ */

#define NIC_AW_R_AW_R_MASK                       (0xFFF00000U)
#define NIC_AW_R_AW_R_SHIFT                      (20U)
/*! AW_R - AW Channel Average Rate */
#define NIC_AW_R_AW_R(x)                         (((uint32_t)(((uint32_t)(x)) << NIC_AW_R_AW_R_SHIFT)) & NIC_AW_R_AW_R_MASK)
/*! @} */

/* The count of NIC_AW_R */
#define NIC_AW_R_COUNT                           (10U)

/*! @name AR_P - AR Channel Peak Rate */
/*! @{ */

#define NIC_AR_P_AR_P_MASK                       (0xFF000000U)
#define NIC_AR_P_AR_P_SHIFT                      (24U)
/*! AR_P - AR Channel Peak Rate */
#define NIC_AR_P_AR_P(x)                         (((uint32_t)(((uint32_t)(x)) << NIC_AR_P_AR_P_SHIFT)) & NIC_AR_P_AR_P_MASK)
/*! @} */

/* The count of NIC_AR_P */
#define NIC_AR_P_COUNT                           (10U)

/*! @name AR_B - AR Channel Burstiness Allowance */
/*! @{ */

#define NIC_AR_B_AR_B_MASK                       (0xFFFFU)
#define NIC_AR_B_AR_B_SHIFT                      (0U)
/*! AR_B - AR Channel Burstiness */
#define NIC_AR_B_AR_B(x)                         (((uint32_t)(((uint32_t)(x)) << NIC_AR_B_AR_B_SHIFT)) & NIC_AR_B_AR_B_MASK)
/*! @} */

/* The count of NIC_AR_B */
#define NIC_AR_B_COUNT                           (10U)

/*! @name AR_R - AR Channel Average Rate */
/*! @{ */

#define NIC_AR_R_AR_R_MASK                       (0xFFF00000U)
#define NIC_AR_R_AR_R_SHIFT                      (20U)
/*! AR_R - AR Channel Average Rate */
#define NIC_AR_R_AR_R(x)                         (((uint32_t)(((uint32_t)(x)) << NIC_AR_R_AR_R_SHIFT)) & NIC_AR_R_AR_R_MASK)
/*! @} */

/* The count of NIC_AR_R */
#define NIC_AR_R_COUNT                           (10U)

/*! @name TARGET_FC - Feedback Controlled Target */
/*! @{ */

#define NIC_TARGET_FC_AW_TGT_LATENCY_MASK        (0xFFFU)
#define NIC_TARGET_FC_AW_TGT_LATENCY_SHIFT       (0U)
/*! AW_TGT_LATENCY - AW Channel Target Latency */
#define NIC_TARGET_FC_AW_TGT_LATENCY(x)          (((uint32_t)(((uint32_t)(x)) << NIC_TARGET_FC_AW_TGT_LATENCY_SHIFT)) & NIC_TARGET_FC_AW_TGT_LATENCY_MASK)

#define NIC_TARGET_FC_AR_TGT_LATENCY_MASK        (0xFFF0000U)
#define NIC_TARGET_FC_AR_TGT_LATENCY_SHIFT       (16U)
/*! AR_TGT_LATENCY - AR Channel Target Latency */
#define NIC_TARGET_FC_AR_TGT_LATENCY(x)          (((uint32_t)(((uint32_t)(x)) << NIC_TARGET_FC_AR_TGT_LATENCY_SHIFT)) & NIC_TARGET_FC_AR_TGT_LATENCY_MASK)
/*! @} */

/* The count of NIC_TARGET_FC */
#define NIC_TARGET_FC_COUNT                      (10U)

/*! @name KI_FC - Feedback Controlled Scale */
/*! @{ */

#define NIC_KI_FC_AW_KI_MASK                     (0x7U)
#define NIC_KI_FC_AW_KI_SHIFT                    (0U)
/*! AW_KI - awqos Scale Factor
 *  0b000..2^-3
 *  0b001..2^-4
 *  0b010-0b110..2^-5 to 2^-9
 *  0b111..2^-10
 */
#define NIC_KI_FC_AW_KI(x)                       (((uint32_t)(((uint32_t)(x)) << NIC_KI_FC_AW_KI_SHIFT)) & NIC_KI_FC_AW_KI_MASK)

#define NIC_KI_FC_AR_KI_MASK                     (0x700U)
#define NIC_KI_FC_AR_KI_SHIFT                    (8U)
/*! AR_KI - arqos Scale Factor
 *  0b000..2^-3
 *  0b001..2^-4
 *  0b010-0b110..2^-5 to 2^-9
 *  0b111..2^-10
 */
#define NIC_KI_FC_AR_KI(x)                       (((uint32_t)(((uint32_t)(x)) << NIC_KI_FC_AR_KI_SHIFT)) & NIC_KI_FC_AR_KI_MASK)
/*! @} */

/* The count of NIC_KI_FC */
#define NIC_KI_FC_COUNT                          (10U)

/*! @name QOS_RANGE - QoS Range */
/*! @{ */

#define NIC_QOS_RANGE_AW_MIN_QOS_MASK            (0xFU)
#define NIC_QOS_RANGE_AW_MIN_QOS_SHIFT           (0U)
/*! AW_MIN_QOS - Minimum awqos
 *  0b0000..The lowest priority
 *  0b0001-0b1110.....
 *  0b1111..The highest priority
 */
#define NIC_QOS_RANGE_AW_MIN_QOS(x)              (((uint32_t)(((uint32_t)(x)) << NIC_QOS_RANGE_AW_MIN_QOS_SHIFT)) & NIC_QOS_RANGE_AW_MIN_QOS_MASK)

#define NIC_QOS_RANGE_AW_MAX_QOS_MASK            (0xF00U)
#define NIC_QOS_RANGE_AW_MAX_QOS_SHIFT           (8U)
/*! AW_MAX_QOS - Maximum awqos
 *  0b0000..The lowest priority
 *  0b0001-0b1110.....
 *  0b1111..The highest priority
 */
#define NIC_QOS_RANGE_AW_MAX_QOS(x)              (((uint32_t)(((uint32_t)(x)) << NIC_QOS_RANGE_AW_MAX_QOS_SHIFT)) & NIC_QOS_RANGE_AW_MAX_QOS_MASK)

#define NIC_QOS_RANGE_AR_MIN_QOS_MASK            (0xF0000U)
#define NIC_QOS_RANGE_AR_MIN_QOS_SHIFT           (16U)
/*! AR_MIN_QOS - Minimum arqos
 *  0b0000..The lowest priority
 *  0b0001-0b1110.....
 *  0b1111..The highest priority
 */
#define NIC_QOS_RANGE_AR_MIN_QOS(x)              (((uint32_t)(((uint32_t)(x)) << NIC_QOS_RANGE_AR_MIN_QOS_SHIFT)) & NIC_QOS_RANGE_AR_MIN_QOS_MASK)

#define NIC_QOS_RANGE_AR_MAX_QOS_MASK            (0xF000000U)
#define NIC_QOS_RANGE_AR_MAX_QOS_SHIFT           (24U)
/*! AR_MAX_QOS - Maximum arqos
 *  0b0000..The lowest priority
 *  0b0001-0b1110.....
 *  0b1111..The highest priority
 */
#define NIC_QOS_RANGE_AR_MAX_QOS(x)              (((uint32_t)(((uint32_t)(x)) << NIC_QOS_RANGE_AR_MAX_QOS_SHIFT)) & NIC_QOS_RANGE_AR_MAX_QOS_MASK)
/*! @} */

/* The count of NIC_QOS_RANGE */
#define NIC_QOS_RANGE_COUNT                      (10U)


/*!
 * @}
 */ /* end of group NIC_Register_Masks */


/*!
 * @}
 */ /* end of group NIC_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_NIC_H_ */

