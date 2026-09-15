/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DIGTMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DIGTMP.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DIGTMP
 *
 * CMSIS Peripheral Access Layer for DIGTMP
 */

#if !defined(PERI_DIGTMP_H_)
#define PERI_DIGTMP_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- DIGTMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIGTMP_Peripheral_Access_Layer DIGTMP Peripheral Access Layer
 * @{
 */

/** DIGTMP - Size of Registers Arrays */
#define DIGTMP_ATR_COUNT                          2u
#define DIGTMP_PGFR_COUNT                         2u

/** DIGTMP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t CR;                                /**< Control, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status, offset: 0x14 */
  __IO uint32_t LR;                                /**< Lock, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t TSR;                               /**< Tamper Seconds, offset: 0x20 */
  __IO uint32_t TER;                               /**< Tamper Enable, offset: 0x24 */
  __IO uint32_t PDR;                               /**< Pin Direction, offset: 0x28 */
  __IO uint32_t PPR;                               /**< Pin Polarity, offset: 0x2C */
  __IO uint32_t ATR[DIGTMP_ATR_COUNT];             /**< Active Tamper, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PGFR[DIGTMP_PGFR_COUNT];           /**< Pin Glitch Filter, array offset: 0x40, array step: 0x4 */
} DIGTMP_Type;

/* ----------------------------------------------------------------------------
   -- DIGTMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIGTMP_Register_Masks DIGTMP Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define DIGTMP_CR_SWR_MASK                       (0x1U)
#define DIGTMP_CR_SWR_SHIFT                      (0U)
/*! SWR - Software Reset
 *  0b0..No effect
 *  0b1..Perform a software reset
 */
#define DIGTMP_CR_SWR(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_SWR_SHIFT)) & DIGTMP_CR_SWR_MASK)

#define DIGTMP_CR_DEN_MASK                       (0x2U)
#define DIGTMP_CR_DEN_SHIFT                      (1U)
/*! DEN - Digital Tamper Enable
 *  0b0..Disables TDET clock and prescaler
 *  0b1..Enables TDET clock and prescaler
 */
#define DIGTMP_CR_DEN(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_DEN_SHIFT)) & DIGTMP_CR_DEN_MASK)

#define DIGTMP_CR_TFSR_MASK                      (0x4U)
#define DIGTMP_CR_TFSR_SHIFT                     (2U)
/*! TFSR - Tamper Force System Reset
 *  0b0..Do not force chip reset
 *  0b1..Force chip reset
 */
#define DIGTMP_CR_TFSR(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_TFSR_SHIFT)) & DIGTMP_CR_TFSR_MASK)

#define DIGTMP_CR_UM_MASK                        (0x8U)
#define DIGTMP_CR_UM_SHIFT                       (3U)
/*! UM - Update Mode
 *  0b0..No effect
 *  0b1..Allows the clearing of interrupts
 */
#define DIGTMP_CR_UM(x)                          (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_UM_SHIFT)) & DIGTMP_CR_UM_MASK)

#define DIGTMP_CR_ATCS0_MASK                     (0x10U)
#define DIGTMP_CR_ATCS0_SHIFT                    (4U)
/*! ATCS0 - Active Tamper Clock Source
 *  0b0..1 Hz prescaler clock
 *  0b1..64 Hz prescaler clock
 */
#define DIGTMP_CR_ATCS0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_ATCS0_SHIFT)) & DIGTMP_CR_ATCS0_MASK)

#define DIGTMP_CR_ATCS1_MASK                     (0x20U)
#define DIGTMP_CR_ATCS1_SHIFT                    (5U)
/*! ATCS1 - Active Tamper Clock Source
 *  0b0..1 Hz prescaler clock
 *  0b1..64 Hz prescaler clock
 */
#define DIGTMP_CR_ATCS1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_ATCS1_SHIFT)) & DIGTMP_CR_ATCS1_MASK)

#define DIGTMP_CR_DISTAM_MASK                    (0x100U)
#define DIGTMP_CR_DISTAM_SHIFT                   (8U)
/*! DISTAM - Disable Prescaler On Tamper
 *  0b0..No effect
 *  0b1..Automatically disables the prescaler after tamper detection
 */
#define DIGTMP_CR_DISTAM(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_DISTAM_SHIFT)) & DIGTMP_CR_DISTAM_MASK)

#define DIGTMP_CR_DPR_MASK                       (0xFFFE0000U)
#define DIGTMP_CR_DPR_SHIFT                      (17U)
/*! DPR - Digital Tamper Prescaler */
#define DIGTMP_CR_DPR(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_CR_DPR_SHIFT)) & DIGTMP_CR_DPR_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define DIGTMP_SR_DTF_MASK                       (0x1U)
#define DIGTMP_SR_DTF_SHIFT                      (0U)
/*! DTF - Digital Tamper Flag
 *  0b0..TDET tampering not detected
 *  0b1..TDET tampering detected
 */
#define DIGTMP_SR_DTF(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_DTF_SHIFT)) & DIGTMP_SR_DTF_MASK)

#define DIGTMP_SR_TAF_MASK                       (0x2U)
#define DIGTMP_SR_TAF_SHIFT                      (1U)
/*! TAF - Tamper Acknowledge Flag
 *  0b0..Digital Tamper Flag (SR[DTF]) is clear or chip reset has not occurred after Digital Tamper Flag (SR[DTF]) was set.
 *  0b1..Chip reset has occurred after Digital Tamper Flag (SR[DTF]) was set.
 */
#define DIGTMP_SR_TAF(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TAF_SHIFT)) & DIGTMP_SR_TAF_MASK)

#define DIGTMP_SR_TIF0_MASK                      (0x4U)
#define DIGTMP_SR_TIF0_SHIFT                     (2U)
/*! TIF0 - Tamper Input n Flag
 *  0b0..On-chip tamper not detected
 *  0b1..On-chip tamper detected
 */
#define DIGTMP_SR_TIF0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TIF0_SHIFT)) & DIGTMP_SR_TIF0_MASK)

#define DIGTMP_SR_TPF0_MASK                      (0x10000U)
#define DIGTMP_SR_TPF0_SHIFT                     (16U)
/*! TPF0 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF0_SHIFT)) & DIGTMP_SR_TPF0_MASK)

#define DIGTMP_SR_TPF1_MASK                      (0x20000U)
#define DIGTMP_SR_TPF1_SHIFT                     (17U)
/*! TPF1 - Tamper Pin n Flag
 *  0b0..Pin tamper not detected
 *  0b1..Pin tamper detected
 */
#define DIGTMP_SR_TPF1(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_SR_TPF1_SHIFT)) & DIGTMP_SR_TPF1_MASK)
/*! @} */

/*! @name LR - Lock */
/*! @{ */

#define DIGTMP_LR_CRL_MASK                       (0x10U)
#define DIGTMP_LR_CRL_SHIFT                      (4U)
/*! CRL - Control Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_CRL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_CRL_SHIFT)) & DIGTMP_LR_CRL_MASK)

#define DIGTMP_LR_SRL_MASK                       (0x20U)
#define DIGTMP_LR_SRL_SHIFT                      (5U)
/*! SRL - Status Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_SRL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_SRL_SHIFT)) & DIGTMP_LR_SRL_MASK)

#define DIGTMP_LR_LRL_MASK                       (0x40U)
#define DIGTMP_LR_LRL_SHIFT                      (6U)
/*! LRL - Lock Register Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_LRL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_LRL_SHIFT)) & DIGTMP_LR_LRL_MASK)

#define DIGTMP_LR_IEL_MASK                       (0x80U)
#define DIGTMP_LR_IEL_SHIFT                      (7U)
/*! IEL - Interrupt Enable Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_IEL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_IEL_SHIFT)) & DIGTMP_LR_IEL_MASK)

#define DIGTMP_LR_TSL_MASK                       (0x100U)
#define DIGTMP_LR_TSL_SHIFT                      (8U)
/*! TSL - Tamper Seconds Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_TSL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_TSL_SHIFT)) & DIGTMP_LR_TSL_MASK)

#define DIGTMP_LR_TEL_MASK                       (0x200U)
#define DIGTMP_LR_TEL_SHIFT                      (9U)
/*! TEL - Tamper Enable Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_TEL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_TEL_SHIFT)) & DIGTMP_LR_TEL_MASK)

#define DIGTMP_LR_PDL_MASK                       (0x400U)
#define DIGTMP_LR_PDL_SHIFT                      (10U)
/*! PDL - Pin Direction Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_PDL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_PDL_SHIFT)) & DIGTMP_LR_PDL_MASK)

#define DIGTMP_LR_PPL_MASK                       (0x800U)
#define DIGTMP_LR_PPL_SHIFT                      (11U)
/*! PPL - Pin Polarity Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_PPL(x)                         (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_PPL_SHIFT)) & DIGTMP_LR_PPL_MASK)

#define DIGTMP_LR_ATL0_MASK                      (0x1000U)
#define DIGTMP_LR_ATL0_SHIFT                     (12U)
/*! ATL0 - Active Tamper Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_ATL0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_ATL0_SHIFT)) & DIGTMP_LR_ATL0_MASK)

#define DIGTMP_LR_ATL1_MASK                      (0x2000U)
#define DIGTMP_LR_ATL1_SHIFT                     (13U)
/*! ATL1 - Active Tamper Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_ATL1(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_ATL1_SHIFT)) & DIGTMP_LR_ATL1_MASK)

#define DIGTMP_LR_GFL0_MASK                      (0x10000U)
#define DIGTMP_LR_GFL0_SHIFT                     (16U)
/*! GFL0 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL0(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL0_SHIFT)) & DIGTMP_LR_GFL0_MASK)

#define DIGTMP_LR_GFL1_MASK                      (0x20000U)
#define DIGTMP_LR_GFL1_SHIFT                     (17U)
/*! GFL1 - Glitch Filter Lock
 *  0b0..Locked and writes are ignored
 *  0b1..Not locked and writes complete as normal
 */
#define DIGTMP_LR_GFL1(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_LR_GFL1_SHIFT)) & DIGTMP_LR_GFL1_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define DIGTMP_IER_DTIE_MASK                     (0x1U)
#define DIGTMP_IER_DTIE_SHIFT                    (0U)
/*! DTIE - Digital Tamper Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_DTIE(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_DTIE_SHIFT)) & DIGTMP_IER_DTIE_MASK)

#define DIGTMP_IER_TIIE0_MASK                    (0x4U)
#define DIGTMP_IER_TIIE0_SHIFT                   (2U)
/*! TIIE0 - Tamper Input n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TIIE0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TIIE0_SHIFT)) & DIGTMP_IER_TIIE0_MASK)

#define DIGTMP_IER_TPIE0_MASK                    (0x10000U)
#define DIGTMP_IER_TPIE0_SHIFT                   (16U)
/*! TPIE0 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE0_SHIFT)) & DIGTMP_IER_TPIE0_MASK)

#define DIGTMP_IER_TPIE1_MASK                    (0x20000U)
#define DIGTMP_IER_TPIE1_SHIFT                   (17U)
/*! TPIE1 - Tamper Pin n Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_IER_TPIE1(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_IER_TPIE1_SHIFT)) & DIGTMP_IER_TPIE1_MASK)
/*! @} */

/*! @name TSR - Tamper Seconds */
/*! @{ */

#define DIGTMP_TSR_TTS_MASK                      (0xFFFFFFFFU)
#define DIGTMP_TSR_TTS_SHIFT                     (0U)
/*! TTS - Tamper Time Seconds */
#define DIGTMP_TSR_TTS(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_TSR_TTS_SHIFT)) & DIGTMP_TSR_TTS_MASK)
/*! @} */

/*! @name TER - Tamper Enable */
/*! @{ */

#define DIGTMP_TER_TIE0_MASK                     (0x4U)
#define DIGTMP_TER_TIE0_SHIFT                    (2U)
/*! TIE0 - Tamper Input Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TIE0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TIE0_SHIFT)) & DIGTMP_TER_TIE0_MASK)

#define DIGTMP_TER_TPE0_MASK                     (0x10000U)
#define DIGTMP_TER_TPE0_SHIFT                    (16U)
/*! TPE0 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE0_SHIFT)) & DIGTMP_TER_TPE0_MASK)

#define DIGTMP_TER_TPE1_MASK                     (0x20000U)
#define DIGTMP_TER_TPE1_SHIFT                    (17U)
/*! TPE1 - Tamper Pin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_TER_TPE1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_TER_TPE1_SHIFT)) & DIGTMP_TER_TPE1_MASK)
/*! @} */

/*! @name PDR - Pin Direction */
/*! @{ */

#define DIGTMP_PDR_TPD0_MASK                     (0x1U)
#define DIGTMP_PDR_TPD0_SHIFT                    (0U)
/*! TPD0 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD0_SHIFT)) & DIGTMP_PDR_TPD0_MASK)

#define DIGTMP_PDR_TPD1_MASK                     (0x2U)
#define DIGTMP_PDR_TPD1_SHIFT                    (1U)
/*! TPD1 - Tamper Pin Direction
 *  0b0..Input
 *  0b1..Output and drives the inverse of the expected value (tamper pin is asserted)
 */
#define DIGTMP_PDR_TPD1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPD1_SHIFT)) & DIGTMP_PDR_TPD1_MASK)

#define DIGTMP_PDR_TPOD0_MASK                    (0x10000U)
#define DIGTMP_PDR_TPOD0_SHIFT                   (16U)
/*! TPOD0 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD0_SHIFT)) & DIGTMP_PDR_TPOD0_MASK)

#define DIGTMP_PDR_TPOD1_MASK                    (0x20000U)
#define DIGTMP_PDR_TPOD1_SHIFT                   (17U)
/*! TPOD1 - Tamper Pin Output Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PDR_TPOD1(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PDR_TPOD1_SHIFT)) & DIGTMP_PDR_TPOD1_MASK)
/*! @} */

/*! @name PPR - Pin Polarity */
/*! @{ */

#define DIGTMP_PPR_TPP0_MASK                     (0x1U)
#define DIGTMP_PPR_TPP0_SHIFT                    (0U)
/*! TPP0 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP0(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP0_SHIFT)) & DIGTMP_PPR_TPP0_MASK)

#define DIGTMP_PPR_TPP1_MASK                     (0x2U)
#define DIGTMP_PPR_TPP1_SHIFT                    (1U)
/*! TPP1 - Tamper Pin n Polarity
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DIGTMP_PPR_TPP1(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPP1_SHIFT)) & DIGTMP_PPR_TPP1_MASK)

#define DIGTMP_PPR_TPID0_MASK                    (0x10000U)
#define DIGTMP_PPR_TPID0_SHIFT                   (16U)
/*! TPID0 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID0(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID0_SHIFT)) & DIGTMP_PPR_TPID0_MASK)

#define DIGTMP_PPR_TPID1_MASK                    (0x20000U)
#define DIGTMP_PPR_TPID1_SHIFT                   (17U)
/*! TPID1 - Tamper Pin n Input Data
 *  0b0..Zero
 *  0b1..One
 */
#define DIGTMP_PPR_TPID1(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PPR_TPID1_SHIFT)) & DIGTMP_PPR_TPID1_MASK)
/*! @} */

/*! @name ATR - Active Tamper */
/*! @{ */

#define DIGTMP_ATR_ATSR_MASK                     (0xFFFFU)
#define DIGTMP_ATR_ATSR_SHIFT                    (0U)
/*! ATSR - Active Tamper Shift Register */
#define DIGTMP_ATR_ATSR(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_ATR_ATSR_SHIFT)) & DIGTMP_ATR_ATSR_MASK)

#define DIGTMP_ATR_ATP_MASK                      (0xFFFF0000U)
#define DIGTMP_ATR_ATP_SHIFT                     (16U)
/*! ATP - Active Tamper Polynomial */
#define DIGTMP_ATR_ATP(x)                        (((uint32_t)(((uint32_t)(x)) << DIGTMP_ATR_ATP_SHIFT)) & DIGTMP_ATR_ATP_MASK)
/*! @} */

/*! @name PGFR - Pin Glitch Filter */
/*! @{ */

#define DIGTMP_PGFR_GFW_MASK                     (0x3FU)
#define DIGTMP_PGFR_GFW_SHIFT                    (0U)
/*! GFW - Glitch Filter Width */
#define DIGTMP_PGFR_GFW(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_GFW_SHIFT)) & DIGTMP_PGFR_GFW_MASK)

#define DIGTMP_PGFR_GFP_MASK                     (0x40U)
#define DIGTMP_PGFR_GFP_SHIFT                    (6U)
/*! GFP - Glitch Filter Prescaler
 *  0b0..512 Hz prescaler clock
 *  0b1..32.768 kHz clock
 */
#define DIGTMP_PGFR_GFP(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_GFP_SHIFT)) & DIGTMP_PGFR_GFP_MASK)

#define DIGTMP_PGFR_GFE_MASK                     (0x80U)
#define DIGTMP_PGFR_GFE_SHIFT                    (7U)
/*! GFE - Glitch Filter Enable
 *  0b0..Bypasses
 *  0b1..Enables
 */
#define DIGTMP_PGFR_GFE(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_GFE_SHIFT)) & DIGTMP_PGFR_GFE_MASK)

#define DIGTMP_PGFR_TPSW_MASK                    (0x300U)
#define DIGTMP_PGFR_TPSW_SHIFT                   (8U)
/*! TPSW - Tamper Pin Sample Width
 *  0b00..Continuous monitoring, pin sampling disabled
 *  0b01..2 cycles for pull enable and 1 cycle for input buffer enable
 *  0b10..4 cycles for pull enable and 2 cycles for input buffer enable
 *  0b11..8 cycles for pull enable and 4 cycles for input buffer enable
 */
#define DIGTMP_PGFR_TPSW(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPSW_SHIFT)) & DIGTMP_PGFR_TPSW_MASK)

#define DIGTMP_PGFR_TPSF_MASK                    (0xC00U)
#define DIGTMP_PGFR_TPSF_SHIFT                   (10U)
/*! TPSF - Tamper Pin Sample Frequency
 *  0b00..Every 8 cycles
 *  0b01..Every 32 cycles
 *  0b10..Every 128 cycles
 *  0b11..Every 512 cycles
 */
#define DIGTMP_PGFR_TPSF(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPSF_SHIFT)) & DIGTMP_PGFR_TPSF_MASK)

#define DIGTMP_PGFR_TPEX_MASK                    (0x30000U)
#define DIGTMP_PGFR_TPEX_SHIFT                   (16U)
/*! TPEX - Tamper Pin Expected
 *  0b00..Zero/passive tamper
 *  0b01..Active Tamper 0 output
 *  0b10..Active Tamper 1 output
 *  0b11..Active Tamper 0 output XORed with Active Tamper 1 output
 */
#define DIGTMP_PGFR_TPEX(x)                      (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPEX_SHIFT)) & DIGTMP_PGFR_TPEX_MASK)

#define DIGTMP_PGFR_TPE_MASK                     (0x1000000U)
#define DIGTMP_PGFR_TPE_SHIFT                    (24U)
/*! TPE - Tamper Pull Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DIGTMP_PGFR_TPE(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPE_SHIFT)) & DIGTMP_PGFR_TPE_MASK)

#define DIGTMP_PGFR_TPS_MASK                     (0x2000000U)
#define DIGTMP_PGFR_TPS_SHIFT                    (25U)
/*! TPS - Tamper Pull Select
 *  0b0..Asserts
 *  0b1..Negates
 */
#define DIGTMP_PGFR_TPS(x)                       (((uint32_t)(((uint32_t)(x)) << DIGTMP_PGFR_TPS_SHIFT)) & DIGTMP_PGFR_TPS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DIGTMP_Register_Masks */


/*!
 * @}
 */ /* end of group DIGTMP_Peripheral_Access_Layer */


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


#endif  /* PERI_DIGTMP_H_ */

