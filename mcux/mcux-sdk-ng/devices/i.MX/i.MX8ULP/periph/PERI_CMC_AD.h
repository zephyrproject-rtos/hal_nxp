/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CMC_AD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CMC_AD.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CMC_AD
 *
 * CMSIS Peripheral Access Layer for CMC_AD
 */

#if !defined(PERI_CMC_AD_H_)
#define PERI_CMC_AD_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- CMC_AD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_AD_Peripheral_Access_Layer CMC_AD Peripheral Access Layer
 * @{
 */

/** CMC_AD - Size of Registers Arrays */
#define CMC_AD_MR_COUNT                           1u
#define CMC_AD_FM_COUNT                           1u

/** CMC_AD - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CKCTRL;                            /**< Clock Control Register, offset: 0x10 */
  __IO uint32_t CKSTAT;                            /**< Clock Status Register, offset: 0x14 */
  __IO uint32_t AD_PMPROT;                         /**< Power Mode Protection Register, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t AD_PMCTRL;                         /**< AD Power Mode Control Register, offset: 0x20 */
       uint8_t RESERVED_2[44];
  __IO uint32_t AD_A35CORE0_LPMODE;                /**< AD A35 CORE0 Low Power Mode Control Register, offset: 0x50 */
  __IO uint32_t AD_A35CORE1_LPMODE;                /**< AD A35 CORE1 Low Power Mode Control Register, offset: 0x54 */
       uint8_t RESERVED_3[24];
  __IO uint32_t AD_PSDORF;                         /**< Application Domain Power Switch Domain Out of Reset Interrupt Flag Register, offset: 0x70 */
  __IO uint32_t AD_PSDORIE;                        /**< Application Domain Power Switch Domain Out of Reset Interrupt Enable Register, offset: 0x74 */
  __I  uint32_t AD_PSDS;                           /**< Application Domain Power Switch Domain Status Register, offset: 0x78 */
       uint8_t RESERVED_4[4];
  __I  uint32_t SRS;                               /**< System Reset Status Register, offset: 0x80 */
       uint8_t RESERVED_5[4];
  __IO uint32_t SSRS;                              /**< Sticky System Reset Status Register, offset: 0x88 */
  __IO uint32_t SRIE;                              /**< System Reset Interrupt Enable Register, offset: 0x8C */
  __IO uint32_t SRIF;                              /**< System Reset Interrupt Flag Register, offset: 0x90 */
       uint8_t RESERVED_6[12];
  __IO uint32_t MR[CMC_AD_MR_COUNT];               /**< Mode Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_7[12];
  __IO uint32_t FM[CMC_AD_FM_COUNT];               /**< Force Mode Register, array offset: 0xB0, array step: 0x4 */
       uint8_t RESERVED_8[92];
  __IO uint32_t CORECTL;                           /**< Core Control Register, offset: 0x110 */
       uint8_t RESERVED_9[12];
  __IO uint32_t DBGCTL;                            /**< Debug Control Register, offset: 0x120 */
} CMC_AD_Type;

/* ----------------------------------------------------------------------------
   -- CMC_AD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_AD_Register_Masks CMC_AD Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define CMC_AD_VERID_FEATURE_MASK                (0xFFFFU)
#define CMC_AD_VERID_FEATURE_SHIFT               (0U)
/*! FEATURE - Feature Specification Number */
#define CMC_AD_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_VERID_FEATURE_SHIFT)) & CMC_AD_VERID_FEATURE_MASK)

#define CMC_AD_VERID_MINOR_MASK                  (0xFF0000U)
#define CMC_AD_VERID_MINOR_SHIFT                 (16U)
/*! MINOR - Minor Version Number */
#define CMC_AD_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_VERID_MINOR_SHIFT)) & CMC_AD_VERID_MINOR_MASK)

#define CMC_AD_VERID_MAJOR_MASK                  (0xFF000000U)
#define CMC_AD_VERID_MAJOR_SHIFT                 (24U)
/*! MAJOR - Major Version Number */
#define CMC_AD_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_VERID_MAJOR_SHIFT)) & CMC_AD_VERID_MAJOR_MASK)
/*! @} */

/*! @name CKCTRL - Clock Control Register */
/*! @{ */

#define CMC_AD_CKCTRL_CKMODE_MASK                (0x7U)
#define CMC_AD_CKCTRL_CKMODE_SHIFT               (0U)
/*! CKMODE - Clocking Mode
 *  0b000..No clock gating.
 *  0b001..Core clock is gated.
 *  0b011..Core and platform clocks are gated.
 *  0b111..Core, platform, bus and slow clocks are gated.
 */
#define CMC_AD_CKCTRL_CKMODE(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_CKCTRL_CKMODE_SHIFT)) & CMC_AD_CKCTRL_CKMODE_MASK)

#define CMC_AD_CKCTRL_LOCK_MASK                  (0x80000000U)
#define CMC_AD_CKCTRL_LOCK_SHIFT                 (31U)
/*! LOCK - Lock Register
 *  0b0..Register writes are allowed.
 *  0b1..Register writes are blocked.
 */
#define CMC_AD_CKCTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_CKCTRL_LOCK_SHIFT)) & CMC_AD_CKCTRL_LOCK_MASK)
/*! @} */

/*! @name CKSTAT - Clock Status Register */
/*! @{ */

#define CMC_AD_CKSTAT_CKMODE_MASK                (0x7U)
#define CMC_AD_CKSTAT_CKMODE_SHIFT               (0U)
/*! CKMODE - Low Power Status
 *  0b000..Core clock not gated.
 *  0b001..Core clock was gated
 *  0b011..Core and platform clocks were gated
 *  0b111..Core, platform, bus and slow clocks were gated
 */
#define CMC_AD_CKSTAT_CKMODE(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_CKSTAT_CKMODE_SHIFT)) & CMC_AD_CKSTAT_CKMODE_MASK)

#define CMC_AD_CKSTAT_WAKEUP_MASK                (0x3F00U)
#define CMC_AD_CKSTAT_WAKEUP_SHIFT               (8U)
/*! WAKEUP - Wakeup Source */
#define CMC_AD_CKSTAT_WAKEUP(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_CKSTAT_WAKEUP_SHIFT)) & CMC_AD_CKSTAT_WAKEUP_MASK)

#define CMC_AD_CKSTAT_VALID_MASK                 (0x80000000U)
#define CMC_AD_CKSTAT_VALID_SHIFT                (31U)
/*! VALID - Clock Status Valid
 *  0b0..Core clock not gated.
 *  0b1..Core clock was gated due to low power mode entry.
 */
#define CMC_AD_CKSTAT_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_CKSTAT_VALID_SHIFT)) & CMC_AD_CKSTAT_VALID_MASK)
/*! @} */

/*! @name AD_PMPROT - Power Mode Protection Register */
/*! @{ */

#define CMC_AD_AD_PMPROT_AS_MASK                 (0x1U)
#define CMC_AD_AD_PMPROT_AS_SHIFT                (0U)
/*! AS - Allow Sleep
 *  0b0..Sleep is not allowed
 *  0b1..Sleep is allowed
 */
#define CMC_AD_AD_PMPROT_AS(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMPROT_AS_SHIFT)) & CMC_AD_AD_PMPROT_AS_MASK)

#define CMC_AD_AD_PMPROT_ADS_MASK                (0x2U)
#define CMC_AD_AD_PMPROT_ADS_SHIFT               (1U)
/*! ADS - Allow Deep Sleep
 *  0b0..Deep Sleep is not allowed
 *  0b1..Deep Sleep is allowed
 */
#define CMC_AD_AD_PMPROT_ADS(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMPROT_ADS_SHIFT)) & CMC_AD_AD_PMPROT_ADS_MASK)

#define CMC_AD_AD_PMPROT_APA_MASK                (0x4U)
#define CMC_AD_AD_PMPROT_APA_SHIFT               (2U)
/*! APA - Allow Partial Active
 *  0b0..Partial Active is not allowed
 *  0b1..Partial Active is allowed
 */
#define CMC_AD_AD_PMPROT_APA(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMPROT_APA_SHIFT)) & CMC_AD_AD_PMPROT_APA_MASK)

#define CMC_AD_AD_PMPROT_APD_MASK                (0x8U)
#define CMC_AD_AD_PMPROT_APD_SHIFT               (3U)
/*! APD - Allow Power Down
 *  0b0..Power Down is not allowed
 *  0b1..Power Down is allowed
 */
#define CMC_AD_AD_PMPROT_APD(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMPROT_APD_SHIFT)) & CMC_AD_AD_PMPROT_APD_MASK)

#define CMC_AD_AD_PMPROT_ADPD_MASK               (0x10U)
#define CMC_AD_AD_PMPROT_ADPD_SHIFT              (4U)
/*! ADPD - Allow Deep Power Down
 *  0b0..Deep Power Down is not allowed
 *  0b1..Deep Power Down is allowed
 */
#define CMC_AD_AD_PMPROT_ADPD(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMPROT_ADPD_SHIFT)) & CMC_AD_AD_PMPROT_ADPD_MASK)

#define CMC_AD_AD_PMPROT_AHLD_MASK               (0x20U)
#define CMC_AD_AD_PMPROT_AHLD_SHIFT              (5U)
/*! AHLD - Allow Hold
 *  0b0..Hold is not allowed
 *  0b1..Hold is allowed
 */
#define CMC_AD_AD_PMPROT_AHLD(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMPROT_AHLD_SHIFT)) & CMC_AD_AD_PMPROT_AHLD_MASK)

#define CMC_AD_AD_PMPROT_LOCK_MASK               (0x80000000U)
#define CMC_AD_AD_PMPROT_LOCK_SHIFT              (31U)
/*! LOCK - Lock Register
 *  0b0..Register writes are allowed.
 *  0b1..Register writes are blocked.
 */
#define CMC_AD_AD_PMPROT_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMPROT_LOCK_SHIFT)) & CMC_AD_AD_PMPROT_LOCK_MASK)
/*! @} */

/*! @name AD_PMCTRL - AD Power Mode Control Register */
/*! @{ */

#define CMC_AD_AD_PMCTRL_AD_LPMODE_MASK          (0x3FU)
#define CMC_AD_AD_PMCTRL_AD_LPMODE_SHIFT         (0U)
/*! AD_LPMODE - Low Power Mode
 *  0b000000..Active
 *  0b000001..Sleep
 *  0b000011..Deep Sleep
 *  0b000111..Partial Active
 *  0b001111..Power Down
 *  0b011111..Deep Power Down
 *  0b111111..Hold
 */
#define CMC_AD_AD_PMCTRL_AD_LPMODE(x)            (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PMCTRL_AD_LPMODE_SHIFT)) & CMC_AD_AD_PMCTRL_AD_LPMODE_MASK)
/*! @} */

/*! @name AD_A35CORE0_LPMODE - AD A35 CORE0 Low Power Mode Control Register */
/*! @{ */

#define CMC_AD_AD_A35CORE0_LPMODE_A35CORE0_LPMODE_MASK (0x3U)
#define CMC_AD_AD_A35CORE0_LPMODE_A35CORE0_LPMODE_SHIFT (0U)
/*! A35CORE0_LPMODE - Low Power Mode
 *  0b00..A35 CORE0 Active(ACT)
 *  0b01..A35 CORE0 Standby(STDB)
 *  0b11..A35 CORE0 PowerDown(PD)
 */
#define CMC_AD_AD_A35CORE0_LPMODE_A35CORE0_LPMODE(x) (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_A35CORE0_LPMODE_A35CORE0_LPMODE_SHIFT)) & CMC_AD_AD_A35CORE0_LPMODE_A35CORE0_LPMODE_MASK)
/*! @} */

/*! @name AD_A35CORE1_LPMODE - AD A35 CORE1 Low Power Mode Control Register */
/*! @{ */

#define CMC_AD_AD_A35CORE1_LPMODE_A35CORE1_LPMODE_MASK (0x3U)
#define CMC_AD_AD_A35CORE1_LPMODE_A35CORE1_LPMODE_SHIFT (0U)
/*! A35CORE1_LPMODE - Low Power Mode
 *  0b00..A35 CORE1 Active(ACT)
 *  0b01..A35 CORE1 Standby(STDB)
 *  0b11..A35 CORE1 PowerDown(PD)
 */
#define CMC_AD_AD_A35CORE1_LPMODE_A35CORE1_LPMODE(x) (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_A35CORE1_LPMODE_A35CORE1_LPMODE_SHIFT)) & CMC_AD_AD_A35CORE1_LPMODE_A35CORE1_LPMODE_MASK)
/*! @} */

/*! @name AD_PSDORF - Application Domain Power Switch Domain Out of Reset Interrupt Flag Register */
/*! @{ */

#define CMC_AD_AD_PSDORF_A35_0_MASK              (0x1U)
#define CMC_AD_AD_PSDORF_A35_0_SHIFT             (0U)
/*! A35_0 - A35_Core0 Power switch domain out of reset interrupt flag
 *  0b0..A35_Core0 Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..A35_Core0 Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_AD_AD_PSDORF_A35_0(x)                (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDORF_A35_0_SHIFT)) & CMC_AD_AD_PSDORF_A35_0_MASK)

#define CMC_AD_AD_PSDORF_A35_1_MASK              (0x2U)
#define CMC_AD_AD_PSDORF_A35_1_SHIFT             (1U)
/*! A35_1 - A35_Core1 Power switch domain out of reset interrupt flag
 *  0b0..A35_Core1 Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..A35_Core1 Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_AD_AD_PSDORF_A35_1(x)                (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDORF_A35_1_SHIFT)) & CMC_AD_AD_PSDORF_A35_1_MASK)

#define CMC_AD_AD_PSDORF_AD_PERIPH_MASK          (0x10U)
#define CMC_AD_AD_PSDORF_AD_PERIPH_SHIFT         (4U)
/*! AD_PERIPH - AD_PERIPH Power switch domain out of reset interrupt flag
 *  0b0..AD_PERIPH Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..AD_PERIPH Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_AD_AD_PSDORF_AD_PERIPH(x)            (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDORF_AD_PERIPH_SHIFT)) & CMC_AD_AD_PSDORF_AD_PERIPH_MASK)
/*! @} */

/*! @name AD_PSDORIE - Application Domain Power Switch Domain Out of Reset Interrupt Enable Register */
/*! @{ */

#define CMC_AD_AD_PSDORIE_A35_0_MASK             (0x1U)
#define CMC_AD_AD_PSDORIE_A35_0_SHIFT            (0U)
/*! A35_0 - A35_Core0 Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..A35_Core0 Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..A35_Core0 Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_AD_AD_PSDORIE_A35_0(x)               (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDORIE_A35_0_SHIFT)) & CMC_AD_AD_PSDORIE_A35_0_MASK)

#define CMC_AD_AD_PSDORIE_A35_1_MASK             (0x2U)
#define CMC_AD_AD_PSDORIE_A35_1_SHIFT            (1U)
/*! A35_1 - A35_Core1 Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..A35_Core1 Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..A35_Core1 Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_AD_AD_PSDORIE_A35_1(x)               (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDORIE_A35_1_SHIFT)) & CMC_AD_AD_PSDORIE_A35_1_MASK)

#define CMC_AD_AD_PSDORIE_AD_PERIPH_MASK         (0x10U)
#define CMC_AD_AD_PSDORIE_AD_PERIPH_SHIFT        (4U)
/*! AD_PERIPH - AD_PERIPH Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..AD_PERIPH Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..AD_PERIPH Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_AD_AD_PSDORIE_AD_PERIPH(x)           (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDORIE_AD_PERIPH_SHIFT)) & CMC_AD_AD_PSDORIE_AD_PERIPH_MASK)
/*! @} */

/*! @name AD_PSDS - Application Domain Power Switch Domain Status Register */
/*! @{ */

#define CMC_AD_AD_PSDS_A35_0_MASK                (0x1U)
#define CMC_AD_AD_PSDS_A35_0_SHIFT               (0U)
/*! A35_0 - A35_Core0 Power Switch Domain Status
 *  0b0..A35_Core0 Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..A35_Core0 Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_AD_AD_PSDS_A35_0(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDS_A35_0_SHIFT)) & CMC_AD_AD_PSDS_A35_0_MASK)

#define CMC_AD_AD_PSDS_A35_1_MASK                (0x2U)
#define CMC_AD_AD_PSDS_A35_1_SHIFT               (1U)
/*! A35_1 - A35_Core1 Power Switch Domain Status
 *  0b0..A35_Core1 Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..A35_Core1 Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_AD_AD_PSDS_A35_1(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDS_A35_1_SHIFT)) & CMC_AD_AD_PSDS_A35_1_MASK)

#define CMC_AD_AD_PSDS_L2_CACHE_MASK             (0x4U)
#define CMC_AD_AD_PSDS_L2_CACHE_SHIFT            (2U)
/*! L2_CACHE - L2 Cache Power Switch Domain Status
 *  0b0..L2 Cache Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..L2 Cache Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_AD_AD_PSDS_L2_CACHE(x)               (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDS_L2_CACHE_SHIFT)) & CMC_AD_AD_PSDS_L2_CACHE_MASK)

#define CMC_AD_AD_PSDS_FAST_NIC_MASK             (0x8U)
#define CMC_AD_AD_PSDS_FAST_NIC_SHIFT            (3U)
/*! FAST_NIC - Fast NIC Power Switch Domain Status
 *  0b0..Fast NIC Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..Fast NIC Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_AD_AD_PSDS_FAST_NIC(x)               (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDS_FAST_NIC_SHIFT)) & CMC_AD_AD_PSDS_FAST_NIC_MASK)

#define CMC_AD_AD_PSDS_AD_PERIPH_MASK            (0x10U)
#define CMC_AD_AD_PSDS_AD_PERIPH_SHIFT           (4U)
/*! AD_PERIPH - Application Power Switch Domain Status
 *  0b0..Application Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..Application Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_AD_AD_PSDS_AD_PERIPH(x)              (((uint32_t)(((uint32_t)(x)) << CMC_AD_AD_PSDS_AD_PERIPH_SHIFT)) & CMC_AD_AD_PSDS_AD_PERIPH_MASK)
/*! @} */

/*! @name SRS - System Reset Status Register */
/*! @{ */

#define CMC_AD_SRS_WAKEUP_MASK                   (0x1U)
#define CMC_AD_SRS_WAKEUP_SHIFT                  (0U)
/*! WAKEUP - Wakeup Reset
 *  0b0..Reset not generated by wakeup from Power Down or Deep Power Down mode.
 *  0b1..Reset generated by wakeup from Power Down or Deep Power Down mode.
 */
#define CMC_AD_SRS_WAKEUP(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_WAKEUP_SHIFT)) & CMC_AD_SRS_WAKEUP_MASK)

#define CMC_AD_SRS_POR_MASK                      (0x2U)
#define CMC_AD_SRS_POR_SHIFT                     (1U)
/*! POR - Power On Reset
 *  0b0..Reset not generated by POR.
 *  0b1..Reset generated by POR.
 */
#define CMC_AD_SRS_POR(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_POR_SHIFT)) & CMC_AD_SRS_POR_MASK)

#define CMC_AD_SRS_HLVD_MASK                     (0x4U)
#define CMC_AD_SRS_HLVD_SHIFT                    (2U)
/*! HLVD - High or Low Voltage Detect Reset
 *  0b0..Reset not generated by HLVD.
 *  0b1..Reset generated by HLVD.
 */
#define CMC_AD_SRS_HLVD(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_HLVD_SHIFT)) & CMC_AD_SRS_HLVD_MASK)

#define CMC_AD_SRS_WARM_MASK                     (0x10U)
#define CMC_AD_SRS_WARM_SHIFT                    (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated by Warm Reset source.
 *  0b1..Reset generated by Warm Reset source.
 */
#define CMC_AD_SRS_WARM(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_WARM_SHIFT)) & CMC_AD_SRS_WARM_MASK)

#define CMC_AD_SRS_FATAL_MASK                    (0x20U)
#define CMC_AD_SRS_FATAL_SHIFT                   (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated by a fatal reset source.
 *  0b1..Reset was generated by a fatal reset source.
 */
#define CMC_AD_SRS_FATAL(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_FATAL_SHIFT)) & CMC_AD_SRS_FATAL_MASK)

#define CMC_AD_SRS_PIN_MASK                      (0x100U)
#define CMC_AD_SRS_PIN_SHIFT                     (8U)
/*! PIN - Pin Reset
 *  0b0..Reset was not generated from the assertion of RESET_b pin.
 *  0b1..Reset was generated from the assertion of RESET_b pin.
 */
#define CMC_AD_SRS_PIN(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_PIN_SHIFT)) & CMC_AD_SRS_PIN_MASK)

#define CMC_AD_SRS_RSTACK_MASK                   (0x400U)
#define CMC_AD_SRS_RSTACK_SHIFT                  (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated from Reset Controller Timeout.
 *  0b1..Reset generated from Reset Controller Timeout.
 */
#define CMC_AD_SRS_RSTACK(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_RSTACK_SHIFT)) & CMC_AD_SRS_RSTACK_MASK)

#define CMC_AD_SRS_LPACK_MASK                    (0x800U)
#define CMC_AD_SRS_LPACK_SHIFT                   (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset not generated by Low Power Acknowledge Timeout.
 *  0b1..Reset generated by Low Power Acknowledge Timeout.
 */
#define CMC_AD_SRS_LPACK(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_LPACK_SHIFT)) & CMC_AD_SRS_LPACK_MASK)

#define CMC_AD_SRS_WDOG_AD_MASK                  (0x2000U)
#define CMC_AD_SRS_WDOG_AD_SHIFT                 (13U)
/*! WDOG_AD - Watchdog 3 Reset
 *  0b0..Reset is not generated from the WatchDog 0 timeout.
 *  0b1..Reset is generated from the WatchDog 0 timeout.
 */
#define CMC_AD_SRS_WDOG_AD(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_WDOG_AD_SHIFT)) & CMC_AD_SRS_WDOG_AD_MASK)

#define CMC_AD_SRS_SW_MASK                       (0x4000U)
#define CMC_AD_SRS_SW_SHIFT                      (14U)
/*! SW - Software Reset (SIM)
 *  0b0..Reset not generated by software request from core.
 *  0b1..Reset generated by software request from core.
 */
#define CMC_AD_SRS_SW(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_SW_SHIFT)) & CMC_AD_SRS_SW_MASK)

#define CMC_AD_SRS_GIC_ECC_MASK                  (0x8000U)
#define CMC_AD_SRS_GIC_ECC_SHIFT                 (15U)
/*! GIC_ECC - Interrupt SRAM Controller ECC Error
 *  0b0..Reset not generated by GIC SRAM ECC error.
 *  0b1..Reset generated by GIC SRAM ECC error.
 */
#define CMC_AD_SRS_GIC_ECC(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_GIC_ECC_SHIFT)) & CMC_AD_SRS_GIC_ECC_MASK)

#define CMC_AD_SRS_RTD_MU_MASK                   (0x10000U)
#define CMC_AD_SRS_RTD_MU_SHIFT                  (16U)
/*! RTD_MU - Real Time Domain MU System Reset
 *  0b0..Reset not generated from RTD_MU reset source.
 *  0b1..Reset generated from RTD_MU reset source.
 */
#define CMC_AD_SRS_RTD_MU(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_RTD_MU_SHIFT)) & CMC_AD_SRS_RTD_MU_MASK)

#define CMC_AD_SRS_AD_CGC_LOS_MASK               (0x80000U)
#define CMC_AD_SRS_AD_CGC_LOS_SHIFT              (19U)
/*! AD_CGC_LOS - AD CGC Loss Of Sync
 *  0b0..Reset not generated from CGC_LOS system reset source.
 *  0b1..Reset generated from CGC_LOS system reset source.
 */
#define CMC_AD_SRS_AD_CGC_LOS(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_AD_CGC_LOS_SHIFT)) & CMC_AD_SRS_AD_CGC_LOS_MASK)

#define CMC_AD_SRS_LPAV_CGC_LOS_MASK             (0x400000U)
#define CMC_AD_SRS_LPAV_CGC_LOS_SHIFT            (22U)
/*! LPAV_CGC_LOS - LPAV CGC Loss Of Sync
 *  0b0..Reset not generated from LPAV_CGC_LOS system reset source.
 *  0b1..Reset generated from LPAV_CGC_LOS system reset source.
 */
#define CMC_AD_SRS_LPAV_CGC_LOS(x)               (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_LPAV_CGC_LOS_SHIFT)) & CMC_AD_SRS_LPAV_CGC_LOS_MASK)

#define CMC_AD_SRS_UPOWER_MASK                   (0x800000U)
#define CMC_AD_SRS_UPOWER_SHIFT                  (23U)
/*! uPOWER - uPOWER WDOG System Reset
 *  0b0..Reset not generated by uPOWER WDOG timeout.
 *  0b1..Reset generated by uPOWER WDOG timeout.
 */
#define CMC_AD_SRS_UPOWER(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_UPOWER_SHIFT)) & CMC_AD_SRS_UPOWER_MASK)

#define CMC_AD_SRS_WDOG_S_AD_MASK                (0x2000000U)
#define CMC_AD_SRS_WDOG_S_AD_SHIFT               (25U)
/*! WDOG_S_AD - Watchdog 4 Reset
 *  0b0..Reset is not generated from the WDOG_S_AD timeout.
 *  0b1..Reset is generated from the WDOG_S_AD timeout.
 */
#define CMC_AD_SRS_WDOG_S_AD(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_WDOG_S_AD_SHIFT)) & CMC_AD_SRS_WDOG_S_AD_MASK)

#define CMC_AD_SRS_WDOG5_MASK                    (0x4000000U)
#define CMC_AD_SRS_WDOG5_SHIFT                   (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Reset is not generated from the WDOG5 timeout.
 *  0b1..Reset is generated from the WDOG5 timeout.
 */
#define CMC_AD_SRS_WDOG5(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRS_WDOG5_SHIFT)) & CMC_AD_SRS_WDOG5_MASK)
/*! @} */

/*! @name SSRS - Sticky System Reset Status Register */
/*! @{ */

#define CMC_AD_SSRS_WAKEUP_MASK                  (0x1U)
#define CMC_AD_SSRS_WAKEUP_SHIFT                 (0U)
/*! WAKEUP - Wakeup Reset
 *  0b0..Reset not generated by wakeup from DPD mode.
 *  0b1..Reset generated by wakeup from DPD mode.
 */
#define CMC_AD_SSRS_WAKEUP(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_WAKEUP_SHIFT)) & CMC_AD_SSRS_WAKEUP_MASK)

#define CMC_AD_SSRS_POR_MASK                     (0x2U)
#define CMC_AD_SSRS_POR_SHIFT                    (1U)
/*! POR - Power On Reset
 *  0b0..Reset not generated by POR.
 *  0b1..Reset generated by POR.
 */
#define CMC_AD_SSRS_POR(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_POR_SHIFT)) & CMC_AD_SSRS_POR_MASK)

#define CMC_AD_SSRS_HLVD_MASK                    (0x4U)
#define CMC_AD_SSRS_HLVD_SHIFT                   (2U)
/*! HLVD - High or Low Voltage Detect Reset
 *  0b0..Reset not generated by HLVD.
 *  0b1..Reset generated by HLVD.
 */
#define CMC_AD_SSRS_HLVD(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_HLVD_SHIFT)) & CMC_AD_SSRS_HLVD_MASK)

#define CMC_AD_SSRS_WARM_MASK                    (0x10U)
#define CMC_AD_SSRS_WARM_SHIFT                   (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated by warm reset source.
 *  0b1..Reset generated by warm reset source.
 */
#define CMC_AD_SSRS_WARM(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_WARM_SHIFT)) & CMC_AD_SSRS_WARM_MASK)

#define CMC_AD_SSRS_FATAL_MASK                   (0x20U)
#define CMC_AD_SSRS_FATAL_SHIFT                  (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated by a fatal reset source.
 *  0b1..Reset was generated by a fatal reset source.
 */
#define CMC_AD_SSRS_FATAL(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_FATAL_SHIFT)) & CMC_AD_SSRS_FATAL_MASK)

#define CMC_AD_SSRS_PIN_MASK                     (0x100U)
#define CMC_AD_SSRS_PIN_SHIFT                    (8U)
/*! PIN - Pin Reset
 *  0b0..Reset was not generated from the RESET_B pin.
 *  0b1..Reset was generated from the RESET_B pin.
 */
#define CMC_AD_SSRS_PIN(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_PIN_SHIFT)) & CMC_AD_SSRS_PIN_MASK)

#define CMC_AD_SSRS_RSTACK_MASK                  (0x400U)
#define CMC_AD_SSRS_RSTACK_SHIFT                 (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated from Reset Controller Timeout.
 *  0b1..Reset generated from Reset Controller Timeout.
 */
#define CMC_AD_SSRS_RSTACK(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_RSTACK_SHIFT)) & CMC_AD_SSRS_RSTACK_MASK)

#define CMC_AD_SSRS_LPACK_MASK                   (0x800U)
#define CMC_AD_SSRS_LPACK_SHIFT                  (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset not generated by Low Power Acknowledge Timeout.
 *  0b1..Reset generated by Low Power Acknowledge Timeout.
 */
#define CMC_AD_SSRS_LPACK(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_LPACK_SHIFT)) & CMC_AD_SSRS_LPACK_MASK)

#define CMC_AD_SSRS_WDOG_AD_MASK                 (0x2000U)
#define CMC_AD_SSRS_WDOG_AD_SHIFT                (13U)
/*! WDOG_AD - Watchdog 3 Reset
 *  0b0..Reset is not generated from the WatchDog 0 timeout.
 *  0b1..Reset is generated from the WatchDog 0 timeout.
 */
#define CMC_AD_SSRS_WDOG_AD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_WDOG_AD_SHIFT)) & CMC_AD_SSRS_WDOG_AD_MASK)

#define CMC_AD_SSRS_SW_MASK                      (0x4000U)
#define CMC_AD_SSRS_SW_SHIFT                     (14U)
/*! SW - Software Reset
 *  0b0..Reset not generated by software request from core.
 *  0b1..Reset generated by software request from core.
 */
#define CMC_AD_SSRS_SW(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_SW_SHIFT)) & CMC_AD_SSRS_SW_MASK)

#define CMC_AD_SSRS_GIC_ECC_MASK                 (0x8000U)
#define CMC_AD_SSRS_GIC_ECC_SHIFT                (15U)
/*! GIC_ECC - Interrupt SRAM Controller ECC Error
 *  0b0..Reset not generated by GIC SRAM ECC error.
 *  0b1..Reset generated by GIC SRAM ECC error.
 */
#define CMC_AD_SSRS_GIC_ECC(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_GIC_ECC_SHIFT)) & CMC_AD_SSRS_GIC_ECC_MASK)

#define CMC_AD_SSRS_RTD_MU_MASK                  (0x10000U)
#define CMC_AD_SSRS_RTD_MU_SHIFT                 (16U)
/*! RTD_MU - Real Time Domain MU Reset
 *  0b0..Reset not generated from Core0 reset source.
 *  0b1..Reset generated from Core0 reset source.
 */
#define CMC_AD_SSRS_RTD_MU(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_RTD_MU_SHIFT)) & CMC_AD_SSRS_RTD_MU_MASK)

#define CMC_AD_SSRS_AD_CGC_LOS_MASK              (0x80000U)
#define CMC_AD_SSRS_AD_CGC_LOS_SHIFT             (19U)
/*! AD_CGC_LOS - AD CGC Loss Of Sync
 *  0b0..Reset not generated from CGC_LOS system reset source.
 *  0b1..Reset generated from CGC_LOS system reset source.
 */
#define CMC_AD_SSRS_AD_CGC_LOS(x)                (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_AD_CGC_LOS_SHIFT)) & CMC_AD_SSRS_AD_CGC_LOS_MASK)

#define CMC_AD_SSRS_LPAV_CGC_LOS_MASK            (0x400000U)
#define CMC_AD_SSRS_LPAV_CGC_LOS_SHIFT           (22U)
/*! LPAV_CGC_LOS - LPAV CGC Loss Of Sync
 *  0b0..Reset not generated from LPAV_CGC_LOS system reset source.
 *  0b1..Reset generated from LPAV_CGC_LOS system reset source.
 */
#define CMC_AD_SSRS_LPAV_CGC_LOS(x)              (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_LPAV_CGC_LOS_SHIFT)) & CMC_AD_SSRS_LPAV_CGC_LOS_MASK)

#define CMC_AD_SSRS_UPOWER_MASK                  (0x800000U)
#define CMC_AD_SSRS_UPOWER_SHIFT                 (23U)
/*! uPOWER - uPOWER WDOG System Reset
 *  0b0..Reset not generated by uPOWER WDOG timeout.
 *  0b1..Reset generated by uPOWER WDOG timeout.
 */
#define CMC_AD_SSRS_UPOWER(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_UPOWER_SHIFT)) & CMC_AD_SSRS_UPOWER_MASK)

#define CMC_AD_SSRS_WDOG_S_AD_MASK               (0x2000000U)
#define CMC_AD_SSRS_WDOG_S_AD_SHIFT              (25U)
/*! WDOG_S_AD - Watchdog 4 Reset
 *  0b0..Reset is not generated from the WatchDog 1 timeout.
 *  0b1..Reset is generated from the WatchDog 1 timeout.
 */
#define CMC_AD_SSRS_WDOG_S_AD(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_WDOG_S_AD_SHIFT)) & CMC_AD_SSRS_WDOG_S_AD_MASK)

#define CMC_AD_SSRS_WDOG5_MASK                   (0x4000000U)
#define CMC_AD_SSRS_WDOG5_SHIFT                  (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Reset is not generated from the WDOG5 timeout.
 *  0b1..Reset is generated from the WDOG5 timeout.
 */
#define CMC_AD_SSRS_WDOG5(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SSRS_WDOG5_SHIFT)) & CMC_AD_SSRS_WDOG5_MASK)
/*! @} */

/*! @name SRIE - System Reset Interrupt Enable Register */
/*! @{ */

#define CMC_AD_SRIE_LPACK_MASK                   (0x800U)
#define CMC_AD_SRIE_LPACK_SHIFT                  (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_AD_SRIE_LPACK(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIE_LPACK_SHIFT)) & CMC_AD_SRIE_LPACK_MASK)

#define CMC_AD_SRIE_WDOG_AD_MASK                 (0x2000U)
#define CMC_AD_SRIE_WDOG_AD_SHIFT                (13U)
/*! WDOG_AD - Watchdog_AD Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_AD_SRIE_WDOG_AD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIE_WDOG_AD_SHIFT)) & CMC_AD_SRIE_WDOG_AD_MASK)

#define CMC_AD_SRIE_SW_MASK                      (0x4000U)
#define CMC_AD_SRIE_SW_SHIFT                     (14U)
/*! SW - Software Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_AD_SRIE_SW(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIE_SW_SHIFT)) & CMC_AD_SRIE_SW_MASK)

#define CMC_AD_SRIE_GIC_ECC_MASK                 (0x8000U)
#define CMC_AD_SRIE_GIC_ECC_SHIFT                (15U)
/*! GIC_ECC - Application domain Interrupt Controller ECC Error Event
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_AD_SRIE_GIC_ECC(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIE_GIC_ECC_SHIFT)) & CMC_AD_SRIE_GIC_ECC_MASK)

#define CMC_AD_SRIE_RTD_MU_MASK                  (0x10000U)
#define CMC_AD_SRIE_RTD_MU_SHIFT                 (16U)
/*! RTD_MU - Real Time Domain MU Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_AD_SRIE_RTD_MU(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIE_RTD_MU_SHIFT)) & CMC_AD_SRIE_RTD_MU_MASK)

#define CMC_AD_SRIE_WDOG_S_AD_MASK               (0x2000000U)
#define CMC_AD_SRIE_WDOG_S_AD_SHIFT              (25U)
/*! WDOG_S_AD - Watchdog 4 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_AD_SRIE_WDOG_S_AD(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIE_WDOG_S_AD_SHIFT)) & CMC_AD_SRIE_WDOG_S_AD_MASK)

#define CMC_AD_SRIE_WDOG5_MASK                   (0x4000000U)
#define CMC_AD_SRIE_WDOG5_SHIFT                  (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_AD_SRIE_WDOG5(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIE_WDOG5_SHIFT)) & CMC_AD_SRIE_WDOG5_MASK)
/*! @} */

/*! @name SRIF - System Reset Interrupt Flag Register */
/*! @{ */

#define CMC_AD_SRIF_LPACK_MASK                   (0x800U)
#define CMC_AD_SRIF_LPACK_SHIFT                  (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_AD_SRIF_LPACK(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIF_LPACK_SHIFT)) & CMC_AD_SRIF_LPACK_MASK)

#define CMC_AD_SRIF_WDOG_AD_MASK                 (0x2000U)
#define CMC_AD_SRIF_WDOG_AD_SHIFT                (13U)
/*! WDOG_AD - Watchdog_AD Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_AD_SRIF_WDOG_AD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIF_WDOG_AD_SHIFT)) & CMC_AD_SRIF_WDOG_AD_MASK)

#define CMC_AD_SRIF_SW_MASK                      (0x4000U)
#define CMC_AD_SRIF_SW_SHIFT                     (14U)
/*! SW - Software Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_AD_SRIF_SW(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIF_SW_SHIFT)) & CMC_AD_SRIF_SW_MASK)

#define CMC_AD_SRIF_GIC_ECC_MASK                 (0x8000U)
#define CMC_AD_SRIF_GIC_ECC_SHIFT                (15U)
/*! GIC_ECC - Application domain Interrupt Controller ECC Error Event
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_AD_SRIF_GIC_ECC(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIF_GIC_ECC_SHIFT)) & CMC_AD_SRIF_GIC_ECC_MASK)

#define CMC_AD_SRIF_RTD_MU_MASK                  (0x10000U)
#define CMC_AD_SRIF_RTD_MU_SHIFT                 (16U)
/*! RTD_MU - Real Time Domain MU Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_AD_SRIF_RTD_MU(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIF_RTD_MU_SHIFT)) & CMC_AD_SRIF_RTD_MU_MASK)

#define CMC_AD_SRIF_WDOG_S_AD_MASK               (0x2000000U)
#define CMC_AD_SRIF_WDOG_S_AD_SHIFT              (25U)
/*! WDOG_S_AD - Watchdog 4 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_AD_SRIF_WDOG_S_AD(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIF_WDOG_S_AD_SHIFT)) & CMC_AD_SRIF_WDOG_S_AD_MASK)

#define CMC_AD_SRIF_WDOG5_MASK                   (0x4000000U)
#define CMC_AD_SRIF_WDOG5_SHIFT                  (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_AD_SRIF_WDOG5(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_SRIF_WDOG5_SHIFT)) & CMC_AD_SRIF_WDOG5_MASK)
/*! @} */

/*! @name MR - Mode Register */
/*! @{ */

#define CMC_AD_MR_BOOTCFG_MASK                   (0xFFFFFFFFU)
#define CMC_AD_MR_BOOTCFG_SHIFT                  (0U)
/*! BOOTCFG - Boot Configuration */
#define CMC_AD_MR_BOOTCFG(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_MR_BOOTCFG_SHIFT)) & CMC_AD_MR_BOOTCFG_MASK)
/*! @} */

/*! @name FM - Force Mode Register */
/*! @{ */

#define CMC_AD_FM_FORCECFG_MASK                  (0xFFFFFFFFU)
#define CMC_AD_FM_FORCECFG_SHIFT                 (0U)
/*! FORCECFG - Boot Configuration
 *  0b00000000000000000000000000000000..No effect.
 *  0b00000000000000000000000000000001..Assert corresponding bit in Mode Register on next system reset.
 */
#define CMC_AD_FM_FORCECFG(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_AD_FM_FORCECFG_SHIFT)) & CMC_AD_FM_FORCECFG_MASK)
/*! @} */

/*! @name CORECTL - Core Control Register */
/*! @{ */

#define CMC_AD_CORECTL_NPIE_MASK                 (0x1U)
#define CMC_AD_CORECTL_NPIE_SHIFT                (0U)
/*! NPIE - Non maskable Pin Interrupt Enable
 *  0b0..Pin interrupt disabled
 *  0b1..Pin interrupt enabled
 */
#define CMC_AD_CORECTL_NPIE(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_AD_CORECTL_NPIE_SHIFT)) & CMC_AD_CORECTL_NPIE_MASK)
/*! @} */

/*! @name DBGCTL - Debug Control Register */
/*! @{ */

#define CMC_AD_DBGCTL_SOD_MASK                   (0x1U)
#define CMC_AD_DBGCTL_SOD_SHIFT                  (0U)
/*! SOD - Sleep Or Debug
 *  0b0..Debug remains enabled when Core is sleeping.
 *  0b1..Debug is disabled when Core is sleeping.
 */
#define CMC_AD_DBGCTL_SOD(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_AD_DBGCTL_SOD_SHIFT)) & CMC_AD_DBGCTL_SOD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMC_AD_Register_Masks */

/* Backward compatibility */
 #define CMC_AD_SRS_WDOG_HIFI4_MASK              CMC_AD_SRS_WDOG5_MASK
 #define CMC_AD_SRS_WDOG_HIFI4_SHIFT             CMC_AD_SRS_WDOG5_SHIFT
 #define CMC_AD_SRS_WDOG_HIFI4(x)                CMC_AD_SRS_WDOG5(x)
 #define CMC_AD_SSRS_WDOG_HIFI4_MASK             CMC_AD_SSRS_WDOG5_MASK
 #define CMC_AD_SSRS_WDOG_HIFI4_SHIFT            CMC_AD_SSRS_WDOG5_SHIFT
 #define CMC_AD_SSRS_WDOG_HIFI4(x)               CMC_AD_SSRS_WDOG5(x)
 #define CMC_AD_SRIE_WDOG_HIFI4_MASK             CMC_AD_SRIE_WDOG5_MASK
 #define CMC_AD_SRIE_WDOG_HIFI4_SHIFT            CMC_AD_SRIE_WDOG5_SHIFT
 #define CMC_AD_SRIE_WDOG_HIFI4(x)               CMC_AD_SRIE_WDOG5(x)
 #define CMC_AD_SRIF_WDOG_HIFI4_MASK             CMC_AD_SRIF_WDOG5_MASK
 #define CMC_AD_SRIF_WDOG_HIFI4_SHIFT            CMC_AD_SRIF_WDOG5_SHIFT
 #define CMC_AD_SRIF_WDOG_HIFI4(x)               CMC_AD_SRIF_WDOG5(x)


/*!
 * @}
 */ /* end of group CMC_AD_Peripheral_Access_Layer */


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


#endif  /* PERI_CMC_AD_H_ */

