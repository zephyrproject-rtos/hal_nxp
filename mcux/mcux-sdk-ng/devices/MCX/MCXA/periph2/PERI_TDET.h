/*
** ###################################################################
**     Processors:          MCXA165VLH
**                          MCXA165VLL
**                          MCXA165VLQ
**                          MCXA165VPN
**                          MCXA166VLH
**                          MCXA166VLL
**                          MCXA166VLQ
**                          MCXA166VPN
**                          MCXA175VLH
**                          MCXA175VLL
**                          MCXA175VLQ
**                          MCXA175VPN
**                          MCXA176VLH
**                          MCXA176VLL
**                          MCXA176VLQ
**                          MCXA176VPN
**                          MCXA275VLH
**                          MCXA275VLL
**                          MCXA275VLQ
**                          MCXA275VPN
**                          MCXA276VLH
**                          MCXA276VLL
**                          MCXA276VLQ
**                          MCXA276VPN
**
**     Version:             rev. 1.0, 2024-03-26
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TDET
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**
** ###################################################################
*/

/*!
 * @file TDET.h
 * @version 1.0
 * @date 2024-03-26
 * @brief CMSIS Peripheral Access Layer for TDET
 *
 * CMSIS Peripheral Access Layer for TDET
 */

#if !defined(TDET_H_)
#define TDET_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA165VLH) || defined(CPU_MCXA165VLL) || defined(CPU_MCXA165VLQ) || defined(CPU_MCXA165VPN))
#include "MCXA165_COMMON.h"
#elif (defined(CPU_MCXA166VLH) || defined(CPU_MCXA166VLL) || defined(CPU_MCXA166VLQ) || defined(CPU_MCXA166VPN))
#include "MCXA166_COMMON.h"
#elif (defined(CPU_MCXA175VLH) || defined(CPU_MCXA175VLL) || defined(CPU_MCXA175VLQ) || defined(CPU_MCXA175VPN))
#include "MCXA175_COMMON.h"
#elif (defined(CPU_MCXA176VLH) || defined(CPU_MCXA176VLL) || defined(CPU_MCXA176VLQ) || defined(CPU_MCXA176VPN))
#include "MCXA176_COMMON.h"
#elif (defined(CPU_MCXA275VLH) || defined(CPU_MCXA275VLL) || defined(CPU_MCXA275VLQ) || defined(CPU_MCXA275VPN))
#include "MCXA275_COMMON.h"
#elif (defined(CPU_MCXA276VLH) || defined(CPU_MCXA276VLL) || defined(CPU_MCXA276VLQ) || defined(CPU_MCXA276VPN))
#include "MCXA276_COMMON.h"
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
   -- TDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TDET_Peripheral_Access_Layer TDET Peripheral Access Layer
 * @{
 */

/** TDET - Size of Registers Arrays */
#define TDET_PGFR_COUNT                           6u

/** TDET - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t CR;                                /**< Control, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status, offset: 0x14 */
  __IO uint32_t LR;                                /**< Lock, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t TSR;                               /**< Tamper Seconds, offset: 0x20 */
  __IO uint32_t TER;                               /**< Tamper Enable, offset: 0x24 */
       uint8_t RESERVED_1[4];
  __IO uint32_t PPR;                               /**< Pin Polarity, offset: 0x2C */
       uint8_t RESERVED_2[16];
  __IO uint32_t PGFR[TDET_PGFR_COUNT];             /**< Pin Glitch Filter, array offset: 0x40, array step: 0x4 */
} TDET_Type;

/* ----------------------------------------------------------------------------
   -- TDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TDET_Register_Masks TDET Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define TDET_CR_SWR_MASK                         (0x1U)
#define TDET_CR_SWR_SHIFT                        (0U)
/*! SWR - Software Reset
 *  0b0..No effect
 *  0b1..Perform a software reset
 */
#define TDET_CR_SWR(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_CR_SWR_SHIFT)) & TDET_CR_SWR_MASK)

#define TDET_CR_DEN_MASK                         (0x2U)
#define TDET_CR_DEN_SHIFT                        (1U)
/*! DEN - Digital Tamper Enable
 *  0b0..Disables TDET clock and prescaler
 *  0b1..Enables TDET clock and prescaler
 */
#define TDET_CR_DEN(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_CR_DEN_SHIFT)) & TDET_CR_DEN_MASK)

#define TDET_CR_TFSR_MASK                        (0x4U)
#define TDET_CR_TFSR_SHIFT                       (2U)
/*! TFSR - Tamper Force System Reset
 *  0b0..Do not force chip reset
 *  0b1..Force chip reset
 */
#define TDET_CR_TFSR(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_CR_TFSR_SHIFT)) & TDET_CR_TFSR_MASK)

#define TDET_CR_UM_MASK                          (0x8U)
#define TDET_CR_UM_SHIFT                         (3U)
/*! UM - Update Mode
 *  0b0..No effect
 *  0b1..Allows the clearing of interrupts
 */
#define TDET_CR_UM(x)                            (((uint32_t)(((uint32_t)(x)) << TDET_CR_UM_SHIFT)) & TDET_CR_UM_MASK)

#define TDET_CR_DISTAM_MASK                      (0x100U)
#define TDET_CR_DISTAM_SHIFT                     (8U)
/*! DISTAM - Disable Prescaler On Tamper
 *  0b0..No effect
 *  0b1..Automatically disables the prescaler after tamper detection
 */
#define TDET_CR_DISTAM(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_CR_DISTAM_SHIFT)) & TDET_CR_DISTAM_MASK)

#define TDET_CR_DPR_MASK                         (0xFFFE0000U)
#define TDET_CR_DPR_SHIFT                        (17U)
/*! DPR - Digital Tamper Prescaler */
#define TDET_CR_DPR(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_CR_DPR_SHIFT)) & TDET_CR_DPR_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define TDET_SR_DTF_MASK                         (0x1U)
#define TDET_SR_DTF_SHIFT                        (0U)
/*! DTF - Digital Tamper Flag
 *  0b0..TDET tampering not detected
 *  0b1..TDET tampering detected
 */
#define TDET_SR_DTF(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_SR_DTF_SHIFT)) & TDET_SR_DTF_MASK)

#define TDET_SR_TAF_MASK                         (0x2U)
#define TDET_SR_TAF_SHIFT                        (1U)
/*! TAF - Tamper Acknowledge Flag
 *  0b0..Digital Tamper Flag (SR[DTF]) is clear or chip reset has not occurred after Digital Tamper Flag (SR[DTF]) was set.
 *  0b1..Chip reset has occurred after Digital Tamper Flag (SR[DTF]) was set.
 */
#define TDET_SR_TAF(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_SR_TAF_SHIFT)) & TDET_SR_TAF_MASK)

#define TDET_SR_TIF0_MASK                        (0x4U)
#define TDET_SR_TIF0_SHIFT                       (2U)
/*! TIF0 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF0(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF0_SHIFT)) & TDET_SR_TIF0_MASK)

#define TDET_SR_TIF1_MASK                        (0x8U)
#define TDET_SR_TIF1_SHIFT                       (3U)
/*! TIF1 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF1(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF1_SHIFT)) & TDET_SR_TIF1_MASK)

#define TDET_SR_TIF2_MASK                        (0x10U)
#define TDET_SR_TIF2_SHIFT                       (4U)
/*! TIF2 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF2(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF2_SHIFT)) & TDET_SR_TIF2_MASK)

#define TDET_SR_TIF3_MASK                        (0x20U)
#define TDET_SR_TIF3_SHIFT                       (5U)
/*! TIF3 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF3(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF3_SHIFT)) & TDET_SR_TIF3_MASK)

#define TDET_SR_TIF4_MASK                        (0x40U)
#define TDET_SR_TIF4_SHIFT                       (6U)
/*! TIF4 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF4(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF4_SHIFT)) & TDET_SR_TIF4_MASK)

#define TDET_SR_TIF5_MASK                        (0x80U)
#define TDET_SR_TIF5_SHIFT                       (7U)
/*! TIF5 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF5(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF5_SHIFT)) & TDET_SR_TIF5_MASK)

#define TDET_SR_TIF6_MASK                        (0x100U)
#define TDET_SR_TIF6_SHIFT                       (8U)
/*! TIF6 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF6(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF6_SHIFT)) & TDET_SR_TIF6_MASK)

#define TDET_SR_TIF7_MASK                        (0x200U)
#define TDET_SR_TIF7_SHIFT                       (9U)
/*! TIF7 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF7(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF7_SHIFT)) & TDET_SR_TIF7_MASK)

#define TDET_SR_TIF8_MASK                        (0x400U)
#define TDET_SR_TIF8_SHIFT                       (10U)
/*! TIF8 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF8(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF8_SHIFT)) & TDET_SR_TIF8_MASK)

#define TDET_SR_TIF9_MASK                        (0x800U)
#define TDET_SR_TIF9_SHIFT                       (11U)
/*! TIF9 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF9(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF9_SHIFT)) & TDET_SR_TIF9_MASK)

#define TDET_SR_TIF10_MASK                       (0x1000U)
#define TDET_SR_TIF10_SHIFT                      (12U)
/*! TIF10 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define TDET_SR_TIF10(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_SR_TIF10_SHIFT)) & TDET_SR_TIF10_MASK)

#define TDET_SR_TPF0_MASK                        (0x10000U)
#define TDET_SR_TPF0_SHIFT                       (16U)
/*! TPF0 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define TDET_SR_TPF0(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TPF0_SHIFT)) & TDET_SR_TPF0_MASK)

#define TDET_SR_TPF1_MASK                        (0x20000U)
#define TDET_SR_TPF1_SHIFT                       (17U)
/*! TPF1 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define TDET_SR_TPF1(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TPF1_SHIFT)) & TDET_SR_TPF1_MASK)

#define TDET_SR_TPF2_MASK                        (0x40000U)
#define TDET_SR_TPF2_SHIFT                       (18U)
/*! TPF2 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define TDET_SR_TPF2(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TPF2_SHIFT)) & TDET_SR_TPF2_MASK)

#define TDET_SR_TPF3_MASK                        (0x80000U)
#define TDET_SR_TPF3_SHIFT                       (19U)
/*! TPF3 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define TDET_SR_TPF3(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TPF3_SHIFT)) & TDET_SR_TPF3_MASK)

#define TDET_SR_TPF4_MASK                        (0x100000U)
#define TDET_SR_TPF4_SHIFT                       (20U)
/*! TPF4 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define TDET_SR_TPF4(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TPF4_SHIFT)) & TDET_SR_TPF4_MASK)

#define TDET_SR_TPF5_MASK                        (0x200000U)
#define TDET_SR_TPF5_SHIFT                       (21U)
/*! TPF5 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define TDET_SR_TPF5(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_SR_TPF5_SHIFT)) & TDET_SR_TPF5_MASK)
/*! @} */

/*! @name LR - Lock */
/*! @{ */

#define TDET_LR_CRL_MASK                         (0x10U)
#define TDET_LR_CRL_SHIFT                        (4U)
/*! CRL - Control Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_CRL(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_LR_CRL_SHIFT)) & TDET_LR_CRL_MASK)

#define TDET_LR_SRL_MASK                         (0x20U)
#define TDET_LR_SRL_SHIFT                        (5U)
/*! SRL - Status Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_SRL(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_LR_SRL_SHIFT)) & TDET_LR_SRL_MASK)

#define TDET_LR_LRL_MASK                         (0x40U)
#define TDET_LR_LRL_SHIFT                        (6U)
/*! LRL - Lock Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_LRL(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_LR_LRL_SHIFT)) & TDET_LR_LRL_MASK)

#define TDET_LR_IEL_MASK                         (0x80U)
#define TDET_LR_IEL_SHIFT                        (7U)
/*! IEL - Interrupt Enable Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_IEL(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_LR_IEL_SHIFT)) & TDET_LR_IEL_MASK)

#define TDET_LR_TSL_MASK                         (0x100U)
#define TDET_LR_TSL_SHIFT                        (8U)
/*! TSL - Tamper Seconds Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_TSL(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_LR_TSL_SHIFT)) & TDET_LR_TSL_MASK)

#define TDET_LR_TEL_MASK                         (0x200U)
#define TDET_LR_TEL_SHIFT                        (9U)
/*! TEL - Tamper Enable Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_TEL(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_LR_TEL_SHIFT)) & TDET_LR_TEL_MASK)

#define TDET_LR_PPL_MASK                         (0x800U)
#define TDET_LR_PPL_SHIFT                        (11U)
/*! PPL - Pin Polarity Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_PPL(x)                           (((uint32_t)(((uint32_t)(x)) << TDET_LR_PPL_SHIFT)) & TDET_LR_PPL_MASK)

#define TDET_LR_GFL0_MASK                        (0x10000U)
#define TDET_LR_GFL0_SHIFT                       (16U)
/*! GFL0 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_GFL0(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_LR_GFL0_SHIFT)) & TDET_LR_GFL0_MASK)

#define TDET_LR_GFL1_MASK                        (0x20000U)
#define TDET_LR_GFL1_SHIFT                       (17U)
/*! GFL1 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_GFL1(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_LR_GFL1_SHIFT)) & TDET_LR_GFL1_MASK)

#define TDET_LR_GFL2_MASK                        (0x40000U)
#define TDET_LR_GFL2_SHIFT                       (18U)
/*! GFL2 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_GFL2(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_LR_GFL2_SHIFT)) & TDET_LR_GFL2_MASK)

#define TDET_LR_GFL3_MASK                        (0x80000U)
#define TDET_LR_GFL3_SHIFT                       (19U)
/*! GFL3 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_GFL3(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_LR_GFL3_SHIFT)) & TDET_LR_GFL3_MASK)

#define TDET_LR_GFL4_MASK                        (0x100000U)
#define TDET_LR_GFL4_SHIFT                       (20U)
/*! GFL4 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_GFL4(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_LR_GFL4_SHIFT)) & TDET_LR_GFL4_MASK)

#define TDET_LR_GFL5_MASK                        (0x200000U)
#define TDET_LR_GFL5_SHIFT                       (21U)
/*! GFL5 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define TDET_LR_GFL5(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_LR_GFL5_SHIFT)) & TDET_LR_GFL5_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define TDET_IER_DTIE_MASK                       (0x1U)
#define TDET_IER_DTIE_SHIFT                      (0U)
/*! DTIE - Digital Tamper Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_DTIE(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_IER_DTIE_SHIFT)) & TDET_IER_DTIE_MASK)

#define TDET_IER_TIIE0_MASK                      (0x4U)
#define TDET_IER_TIIE0_SHIFT                     (2U)
/*! TIIE0 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE0(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE0_SHIFT)) & TDET_IER_TIIE0_MASK)

#define TDET_IER_TIIE1_MASK                      (0x8U)
#define TDET_IER_TIIE1_SHIFT                     (3U)
/*! TIIE1 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE1(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE1_SHIFT)) & TDET_IER_TIIE1_MASK)

#define TDET_IER_TIIE2_MASK                      (0x10U)
#define TDET_IER_TIIE2_SHIFT                     (4U)
/*! TIIE2 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE2(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE2_SHIFT)) & TDET_IER_TIIE2_MASK)

#define TDET_IER_TIIE3_MASK                      (0x20U)
#define TDET_IER_TIIE3_SHIFT                     (5U)
/*! TIIE3 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE3(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE3_SHIFT)) & TDET_IER_TIIE3_MASK)

#define TDET_IER_TIIE4_MASK                      (0x40U)
#define TDET_IER_TIIE4_SHIFT                     (6U)
/*! TIIE4 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE4(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE4_SHIFT)) & TDET_IER_TIIE4_MASK)

#define TDET_IER_TIIE5_MASK                      (0x80U)
#define TDET_IER_TIIE5_SHIFT                     (7U)
/*! TIIE5 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE5(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE5_SHIFT)) & TDET_IER_TIIE5_MASK)

#define TDET_IER_TIIE6_MASK                      (0x100U)
#define TDET_IER_TIIE6_SHIFT                     (8U)
/*! TIIE6 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE6(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE6_SHIFT)) & TDET_IER_TIIE6_MASK)

#define TDET_IER_TIIE7_MASK                      (0x200U)
#define TDET_IER_TIIE7_SHIFT                     (9U)
/*! TIIE7 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE7(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE7_SHIFT)) & TDET_IER_TIIE7_MASK)

#define TDET_IER_TIIE8_MASK                      (0x400U)
#define TDET_IER_TIIE8_SHIFT                     (10U)
/*! TIIE8 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE8(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE8_SHIFT)) & TDET_IER_TIIE8_MASK)

#define TDET_IER_TIIE9_MASK                      (0x800U)
#define TDET_IER_TIIE9_SHIFT                     (11U)
/*! TIIE9 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE9(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE9_SHIFT)) & TDET_IER_TIIE9_MASK)

#define TDET_IER_TIIE10_MASK                     (0x1000U)
#define TDET_IER_TIIE10_SHIFT                    (12U)
/*! TIIE10 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TIIE10(x)                       (((uint32_t)(((uint32_t)(x)) << TDET_IER_TIIE10_SHIFT)) & TDET_IER_TIIE10_MASK)

#define TDET_IER_TPIE0_MASK                      (0x10000U)
#define TDET_IER_TPIE0_SHIFT                     (16U)
/*! TPIE0 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TPIE0(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TPIE0_SHIFT)) & TDET_IER_TPIE0_MASK)

#define TDET_IER_TPIE1_MASK                      (0x20000U)
#define TDET_IER_TPIE1_SHIFT                     (17U)
/*! TPIE1 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TPIE1(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TPIE1_SHIFT)) & TDET_IER_TPIE1_MASK)

#define TDET_IER_TPIE2_MASK                      (0x40000U)
#define TDET_IER_TPIE2_SHIFT                     (18U)
/*! TPIE2 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TPIE2(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TPIE2_SHIFT)) & TDET_IER_TPIE2_MASK)

#define TDET_IER_TPIE3_MASK                      (0x80000U)
#define TDET_IER_TPIE3_SHIFT                     (19U)
/*! TPIE3 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TPIE3(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TPIE3_SHIFT)) & TDET_IER_TPIE3_MASK)

#define TDET_IER_TPIE4_MASK                      (0x100000U)
#define TDET_IER_TPIE4_SHIFT                     (20U)
/*! TPIE4 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TPIE4(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TPIE4_SHIFT)) & TDET_IER_TPIE4_MASK)

#define TDET_IER_TPIE5_MASK                      (0x200000U)
#define TDET_IER_TPIE5_SHIFT                     (21U)
/*! TPIE5 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_IER_TPIE5(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_IER_TPIE5_SHIFT)) & TDET_IER_TPIE5_MASK)
/*! @} */

/*! @name TSR - Tamper Seconds */
/*! @{ */

#define TDET_TSR_TTS_MASK                        (0xFFFFFFFFU)
#define TDET_TSR_TTS_SHIFT                       (0U)
/*! TTS - Tamper Time Seconds */
#define TDET_TSR_TTS(x)                          (((uint32_t)(((uint32_t)(x)) << TDET_TSR_TTS_SHIFT)) & TDET_TSR_TTS_MASK)
/*! @} */

/*! @name TER - Tamper Enable */
/*! @{ */

#define TDET_TER_TIE0_MASK                       (0x4U)
#define TDET_TER_TIE0_SHIFT                      (2U)
/*! TIE0 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE0(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE0_SHIFT)) & TDET_TER_TIE0_MASK)

#define TDET_TER_TIE1_MASK                       (0x8U)
#define TDET_TER_TIE1_SHIFT                      (3U)
/*! TIE1 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE1(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE1_SHIFT)) & TDET_TER_TIE1_MASK)

#define TDET_TER_TIE2_MASK                       (0x10U)
#define TDET_TER_TIE2_SHIFT                      (4U)
/*! TIE2 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE2(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE2_SHIFT)) & TDET_TER_TIE2_MASK)

#define TDET_TER_TIE3_MASK                       (0x20U)
#define TDET_TER_TIE3_SHIFT                      (5U)
/*! TIE3 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE3(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE3_SHIFT)) & TDET_TER_TIE3_MASK)

#define TDET_TER_TIE4_MASK                       (0x40U)
#define TDET_TER_TIE4_SHIFT                      (6U)
/*! TIE4 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE4(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE4_SHIFT)) & TDET_TER_TIE4_MASK)

#define TDET_TER_TIE5_MASK                       (0x80U)
#define TDET_TER_TIE5_SHIFT                      (7U)
/*! TIE5 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE5(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE5_SHIFT)) & TDET_TER_TIE5_MASK)

#define TDET_TER_TIE6_MASK                       (0x100U)
#define TDET_TER_TIE6_SHIFT                      (8U)
/*! TIE6 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE6(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE6_SHIFT)) & TDET_TER_TIE6_MASK)

#define TDET_TER_TIE7_MASK                       (0x200U)
#define TDET_TER_TIE7_SHIFT                      (9U)
/*! TIE7 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE7(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE7_SHIFT)) & TDET_TER_TIE7_MASK)

#define TDET_TER_TIE8_MASK                       (0x400U)
#define TDET_TER_TIE8_SHIFT                      (10U)
/*! TIE8 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE8(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE8_SHIFT)) & TDET_TER_TIE8_MASK)

#define TDET_TER_TIE9_MASK                       (0x800U)
#define TDET_TER_TIE9_SHIFT                      (11U)
/*! TIE9 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE9(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE9_SHIFT)) & TDET_TER_TIE9_MASK)

#define TDET_TER_TIE10_MASK                      (0x1000U)
#define TDET_TER_TIE10_SHIFT                     (12U)
/*! TIE10 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TIE10(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_TER_TIE10_SHIFT)) & TDET_TER_TIE10_MASK)

#define TDET_TER_TPE0_MASK                       (0x10000U)
#define TDET_TER_TPE0_SHIFT                      (16U)
/*! TPE0 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TPE0(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TPE0_SHIFT)) & TDET_TER_TPE0_MASK)

#define TDET_TER_TPE1_MASK                       (0x20000U)
#define TDET_TER_TPE1_SHIFT                      (17U)
/*! TPE1 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TPE1(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TPE1_SHIFT)) & TDET_TER_TPE1_MASK)

#define TDET_TER_TPE2_MASK                       (0x40000U)
#define TDET_TER_TPE2_SHIFT                      (18U)
/*! TPE2 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TPE2(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TPE2_SHIFT)) & TDET_TER_TPE2_MASK)

#define TDET_TER_TPE3_MASK                       (0x80000U)
#define TDET_TER_TPE3_SHIFT                      (19U)
/*! TPE3 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TPE3(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TPE3_SHIFT)) & TDET_TER_TPE3_MASK)

#define TDET_TER_TPE4_MASK                       (0x100000U)
#define TDET_TER_TPE4_SHIFT                      (20U)
/*! TPE4 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TPE4(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TPE4_SHIFT)) & TDET_TER_TPE4_MASK)

#define TDET_TER_TPE5_MASK                       (0x200000U)
#define TDET_TER_TPE5_SHIFT                      (21U)
/*! TPE5 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_TER_TPE5(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_TER_TPE5_SHIFT)) & TDET_TER_TPE5_MASK)
/*! @} */

/*! @name PPR - Pin Polarity */
/*! @{ */

#define TDET_PPR_TPP0_MASK                       (0x1U)
#define TDET_PPR_TPP0_SHIFT                      (0U)
/*! TPP0 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define TDET_PPR_TPP0(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPP0_SHIFT)) & TDET_PPR_TPP0_MASK)

#define TDET_PPR_TPP1_MASK                       (0x2U)
#define TDET_PPR_TPP1_SHIFT                      (1U)
/*! TPP1 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define TDET_PPR_TPP1(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPP1_SHIFT)) & TDET_PPR_TPP1_MASK)

#define TDET_PPR_TPP2_MASK                       (0x4U)
#define TDET_PPR_TPP2_SHIFT                      (2U)
/*! TPP2 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define TDET_PPR_TPP2(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPP2_SHIFT)) & TDET_PPR_TPP2_MASK)

#define TDET_PPR_TPP3_MASK                       (0x8U)
#define TDET_PPR_TPP3_SHIFT                      (3U)
/*! TPP3 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define TDET_PPR_TPP3(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPP3_SHIFT)) & TDET_PPR_TPP3_MASK)

#define TDET_PPR_TPP4_MASK                       (0x10U)
#define TDET_PPR_TPP4_SHIFT                      (4U)
/*! TPP4 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define TDET_PPR_TPP4(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPP4_SHIFT)) & TDET_PPR_TPP4_MASK)

#define TDET_PPR_TPP5_MASK                       (0x20U)
#define TDET_PPR_TPP5_SHIFT                      (5U)
/*! TPP5 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define TDET_PPR_TPP5(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPP5_SHIFT)) & TDET_PPR_TPP5_MASK)

#define TDET_PPR_TPID0_MASK                      (0x10000U)
#define TDET_PPR_TPID0_SHIFT                     (16U)
/*! TPID0 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define TDET_PPR_TPID0(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPID0_SHIFT)) & TDET_PPR_TPID0_MASK)

#define TDET_PPR_TPID1_MASK                      (0x20000U)
#define TDET_PPR_TPID1_SHIFT                     (17U)
/*! TPID1 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define TDET_PPR_TPID1(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPID1_SHIFT)) & TDET_PPR_TPID1_MASK)

#define TDET_PPR_TPID2_MASK                      (0x40000U)
#define TDET_PPR_TPID2_SHIFT                     (18U)
/*! TPID2 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define TDET_PPR_TPID2(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPID2_SHIFT)) & TDET_PPR_TPID2_MASK)

#define TDET_PPR_TPID3_MASK                      (0x80000U)
#define TDET_PPR_TPID3_SHIFT                     (19U)
/*! TPID3 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define TDET_PPR_TPID3(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPID3_SHIFT)) & TDET_PPR_TPID3_MASK)

#define TDET_PPR_TPID4_MASK                      (0x100000U)
#define TDET_PPR_TPID4_SHIFT                     (20U)
/*! TPID4 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define TDET_PPR_TPID4(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPID4_SHIFT)) & TDET_PPR_TPID4_MASK)

#define TDET_PPR_TPID5_MASK                      (0x200000U)
#define TDET_PPR_TPID5_SHIFT                     (21U)
/*! TPID5 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define TDET_PPR_TPID5(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PPR_TPID5_SHIFT)) & TDET_PPR_TPID5_MASK)
/*! @} */

/*! @name PGFR - Pin Glitch Filter */
/*! @{ */

#define TDET_PGFR_GFW_MASK                       (0x3FU)
#define TDET_PGFR_GFW_SHIFT                      (0U)
/*! GFW - Glitch Filter Width */
#define TDET_PGFR_GFW(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_GFW_SHIFT)) & TDET_PGFR_GFW_MASK)

#define TDET_PGFR_GFP_MASK                       (0x40U)
#define TDET_PGFR_GFP_SHIFT                      (6U)
/*! GFP - Glitch Filter Prescaler
 *  0b0..512 Hz prescaler clock
 *  0b1..32.768 kHz clock
 */
#define TDET_PGFR_GFP(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_GFP_SHIFT)) & TDET_PGFR_GFP_MASK)

#define TDET_PGFR_GFE_MASK                       (0x80U)
#define TDET_PGFR_GFE_SHIFT                      (7U)
/*! GFE - Glitch Filter Enable
 *  0b0..Bypasses
 *  0b1..Enables
 */
#define TDET_PGFR_GFE(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_GFE_SHIFT)) & TDET_PGFR_GFE_MASK)

#define TDET_PGFR_TPSW_MASK                      (0x300U)
#define TDET_PGFR_TPSW_SHIFT                     (8U)
/*! TPSW - Tamper Pin Sample Width
 *  0b00..Continuous monitoring, pin sampling disabled
 *  0b01..2 cycles for pull enable and 1 cycle for input buffer enable
 *  0b10..4 cycles for pull enable and 2 cycles for input buffer enable
 *  0b11..8 cycles for pull enable and 4 cycles for input buffer enable
 */
#define TDET_PGFR_TPSW(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_TPSW_SHIFT)) & TDET_PGFR_TPSW_MASK)

#define TDET_PGFR_TPSF_MASK                      (0xC00U)
#define TDET_PGFR_TPSF_SHIFT                     (10U)
/*! TPSF - Tamper Pin Sample Frequency
 *  0b00..Every 8 cycles
 *  0b01..Every 32 cycles
 *  0b10..Every 128 cycles
 *  0b11..Every 512 cycles
 */
#define TDET_PGFR_TPSF(x)                        (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_TPSF_SHIFT)) & TDET_PGFR_TPSF_MASK)

#define TDET_PGFR_TPE_MASK                       (0x1000000U)
#define TDET_PGFR_TPE_SHIFT                      (24U)
/*! TPE - Tamper Pull Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_PGFR_TPE(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_TPE_SHIFT)) & TDET_PGFR_TPE_MASK)

#define TDET_PGFR_TPS_MASK                       (0x2000000U)
#define TDET_PGFR_TPS_SHIFT                      (25U)
/*! TPS - Tamper Pull Select
 *  0b0..Asserts
 *  0b1..Negates
 */
#define TDET_PGFR_TPS(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_TPS_SHIFT)) & TDET_PGFR_TPS_MASK)

#define TDET_PGFR_TPV_MASK                       (0x4000000U)
#define TDET_PGFR_TPV_SHIFT                      (26U)
/*! TPV - Tamper Pull Value
 *  0b0..Low
 *  0b1..High
 */
#define TDET_PGFR_TPV(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_TPV_SHIFT)) & TDET_PGFR_TPV_MASK)

#define TDET_PGFR_TPF_MASK                       (0x8000000U)
#define TDET_PGFR_TPF_SHIFT                      (27U)
/*! TPF - Tamper Passive Filter
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_PGFR_TPF(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_TPF_SHIFT)) & TDET_PGFR_TPF_MASK)

#define TDET_PGFR_IBE_MASK                       (0x80000000U)
#define TDET_PGFR_IBE_SHIFT                      (31U)
/*! IBE - Input Buffer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TDET_PGFR_IBE(x)                         (((uint32_t)(((uint32_t)(x)) << TDET_PGFR_IBE_SHIFT)) & TDET_PGFR_IBE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TDET_Register_Masks */


/*!
 * @}
 */ /* end of group TDET_Peripheral_Access_Layer */


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


#endif  /* TDET_H_ */

