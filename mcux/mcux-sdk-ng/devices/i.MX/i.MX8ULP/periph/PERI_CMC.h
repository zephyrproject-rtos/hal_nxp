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
**         CMSIS Peripheral Access Layer for CMC
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
 * @file PERI_CMC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CMC
 *
 * CMSIS Peripheral Access Layer for CMC
 */

#if !defined(PERI_CMC_H_)
#define PERI_CMC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_Peripheral_Access_Layer CMC Peripheral Access Layer
 * @{
 */

/** CMC - Size of Registers Arrays */
#define CMC_MR_COUNT                              1u
#define CMC_FM_COUNT                              1u

/** CMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CKCTRL;                            /**< Clock Control Register, offset: 0x10 */
  __IO uint32_t CKSTAT;                            /**< Clock Status Register, offset: 0x14 */
  __IO uint32_t RTD_PMPROT;                        /**< Power Mode Protection Register, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t RTD_PMCTRL;                        /**< Real Time Domain Power Mode Control Register, offset: 0x20 */
       uint8_t RESERVED_2[76];
  __IO uint32_t RTD_PSDORF;                        /**< Real Time Domain Power Switch Domain Out of Reset Interrupt Flag, offset: 0x70 */
  __IO uint32_t RTD_PSDORIE;                       /**< Real Time Domain Power Switch Domain Out of Reset Interrupt Enable, offset: 0x74 */
  __I  uint32_t RTD_PSDS;                          /**< Real Time Domain Power Switch Domain Status, offset: 0x78 */
       uint8_t RESERVED_3[4];
  __I  uint32_t SRS;                               /**< System Reset Status, offset: 0x80 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SSRS;                              /**< Sticky System Reset Status, offset: 0x88 */
  __IO uint32_t SRIE;                              /**< System Reset Interrupt Enable, offset: 0x8C */
  __IO uint32_t SRIF;                              /**< System Reset Interrupt Flag, offset: 0x90 */
       uint8_t RESERVED_5[12];
  __IO uint32_t MR[CMC_MR_COUNT];                  /**< Mode Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_6[12];
  __IO uint32_t FM[CMC_FM_COUNT];                  /**< Force Mode Register, array offset: 0xB0, array step: 0x4 */
       uint8_t RESERVED_7[92];
  __IO uint32_t CORECTL;                           /**< Core Control Register, offset: 0x110 */
       uint8_t RESERVED_8[12];
  __IO uint32_t DBGCTL;                            /**< Debug Control Register, offset: 0x120 */
} CMC_Type;

/* ----------------------------------------------------------------------------
   -- CMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_Register_Masks CMC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define CMC_VERID_FEATURE_MASK                   (0xFFFFU)
#define CMC_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number */
#define CMC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_VERID_FEATURE_SHIFT)) & CMC_VERID_FEATURE_MASK)

#define CMC_VERID_MINOR_MASK                     (0xFF0000U)
#define CMC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define CMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_VERID_MINOR_SHIFT)) & CMC_VERID_MINOR_MASK)

#define CMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define CMC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define CMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_VERID_MAJOR_SHIFT)) & CMC_VERID_MAJOR_MASK)
/*! @} */

/*! @name CKCTRL - Clock Control Register */
/*! @{ */

#define CMC_CKCTRL_CKMODE_MASK                   (0x7U)
#define CMC_CKCTRL_CKMODE_SHIFT                  (0U)
/*! CKMODE - Clocking Mode
 *  0b000..No clock gating.
 *  0b001..Core clock is gated.
 *  0b011..Core and platform clocks are gated.
 *  0b111..Core, platform, bus and slow clocks are gated.
 */
#define CMC_CKCTRL_CKMODE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_CKCTRL_CKMODE_SHIFT)) & CMC_CKCTRL_CKMODE_MASK)

#define CMC_CKCTRL_LOCK_MASK                     (0x80000000U)
#define CMC_CKCTRL_LOCK_SHIFT                    (31U)
/*! LOCK - Lock Register
 *  0b0..Register writes are allowed.
 *  0b1..Register writes are blocked.
 */
#define CMC_CKCTRL_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_CKCTRL_LOCK_SHIFT)) & CMC_CKCTRL_LOCK_MASK)
/*! @} */

/*! @name CKSTAT - Clock Status Register */
/*! @{ */

#define CMC_CKSTAT_CKMODE_MASK                   (0x7U)
#define CMC_CKSTAT_CKMODE_SHIFT                  (0U)
/*! CKMODE - Low Power Status
 *  0b000..Core clock not gated.
 *  0b001..Core clock was gated
 *  0b011..Core and platform clocks were gated
 *  0b111..Core, platform, bus and slow clocks were gated
 */
#define CMC_CKSTAT_CKMODE(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_CKSTAT_CKMODE_SHIFT)) & CMC_CKSTAT_CKMODE_MASK)

#define CMC_CKSTAT_WAKEUP_MASK                   (0x1F00U)
#define CMC_CKSTAT_WAKEUP_SHIFT                  (8U)
/*! WAKEUP - Wakeup Source */
#define CMC_CKSTAT_WAKEUP(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_CKSTAT_WAKEUP_SHIFT)) & CMC_CKSTAT_WAKEUP_MASK)

#define CMC_CKSTAT_VALID_MASK                    (0x80000000U)
#define CMC_CKSTAT_VALID_SHIFT                   (31U)
/*! VALID - Clock Status Valid
 *  0b0..Core clock not gated.
 *  0b1..Core clock was gated due to low power mode entry.
 */
#define CMC_CKSTAT_VALID(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_CKSTAT_VALID_SHIFT)) & CMC_CKSTAT_VALID_MASK)
/*! @} */

/*! @name RTD_PMPROT - Power Mode Protection Register */
/*! @{ */

#define CMC_RTD_PMPROT_AS_MASK                   (0x1U)
#define CMC_RTD_PMPROT_AS_SHIFT                  (0U)
/*! AS - Allow Sleep
 *  0b0..Sleep is not allowed
 *  0b1..Sleep is allowed
 */
#define CMC_RTD_PMPROT_AS(x)                     (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PMPROT_AS_SHIFT)) & CMC_RTD_PMPROT_AS_MASK)

#define CMC_RTD_PMPROT_ADS_MASK                  (0x2U)
#define CMC_RTD_PMPROT_ADS_SHIFT                 (1U)
/*! ADS - Allow Deep Sleep
 *  0b0..Deep Sleep is not allowed
 *  0b1..Deep Sleep is allowed
 */
#define CMC_RTD_PMPROT_ADS(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PMPROT_ADS_SHIFT)) & CMC_RTD_PMPROT_ADS_MASK)

#define CMC_RTD_PMPROT_APD_MASK                  (0x4U)
#define CMC_RTD_PMPROT_APD_SHIFT                 (2U)
/*! APD - Allow Power Down
 *  0b0..Power Down is not allowed
 *  0b1..Power Down is allowed
 */
#define CMC_RTD_PMPROT_APD(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PMPROT_APD_SHIFT)) & CMC_RTD_PMPROT_APD_MASK)

#define CMC_RTD_PMPROT_ADPD_MASK                 (0x8U)
#define CMC_RTD_PMPROT_ADPD_SHIFT                (3U)
/*! ADPD - Allow Deep Power Down
 *  0b0..Deep Power Down is not allowed
 *  0b1..Deep Power Down is allowed
 */
#define CMC_RTD_PMPROT_ADPD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PMPROT_ADPD_SHIFT)) & CMC_RTD_PMPROT_ADPD_MASK)

#define CMC_RTD_PMPROT_AHLD_MASK                 (0x10U)
#define CMC_RTD_PMPROT_AHLD_SHIFT                (4U)
/*! AHLD - Allow Hold
 *  0b0..Hold is not allowed
 *  0b1..Hold is allowed
 */
#define CMC_RTD_PMPROT_AHLD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PMPROT_AHLD_SHIFT)) & CMC_RTD_PMPROT_AHLD_MASK)

#define CMC_RTD_PMPROT_LOCK_MASK                 (0x80000000U)
#define CMC_RTD_PMPROT_LOCK_SHIFT                (31U)
/*! LOCK - Lock Register
 *  0b0..Register writes are allowed.
 *  0b1..Register writes are blocked.
 */
#define CMC_RTD_PMPROT_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PMPROT_LOCK_SHIFT)) & CMC_RTD_PMPROT_LOCK_MASK)
/*! @} */

/*! @name RTD_PMCTRL - Real Time Domain Power Mode Control Register */
/*! @{ */

#define CMC_RTD_PMCTRL_RTD_LPMODE_MASK           (0x1FU)
#define CMC_RTD_PMCTRL_RTD_LPMODE_SHIFT          (0U)
/*! RTD_LPMODE - Low Power Mode
 *  0b00000..Active
 *  0b00001..Sleep
 *  0b00011..Deep Sleep
 *  0b00111..Power Down
 *  0b01111..Deep Power Down
 *  0b11111..Hold
 */
#define CMC_RTD_PMCTRL_RTD_LPMODE(x)             (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PMCTRL_RTD_LPMODE_SHIFT)) & CMC_RTD_PMCTRL_RTD_LPMODE_MASK)
/*! @} */

/*! @name RTD_PSDORF - Real Time Domain Power Switch Domain Out of Reset Interrupt Flag */
/*! @{ */

#define CMC_RTD_PSDORF_FUSION_MASK               (0x2U)
#define CMC_RTD_PSDORF_FUSION_SHIFT              (1U)
/*! Fusion - Fusion Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..Fusion Power Switch Domain in reset or user has cleared it by writing 1 to clear
 *  0b1..Fusion Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_RTD_PSDORF_FUSION(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PSDORF_FUSION_SHIFT)) & CMC_RTD_PSDORF_FUSION_MASK)

#define CMC_RTD_PSDORF_FUSION_AO_MASK            (0x4U)
#define CMC_RTD_PSDORF_FUSION_AO_SHIFT           (2U)
/*! Fusion_AO - Fusion Always ON Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..Fusion Always ON Power Switch Domain in reset or user has cleared it by writing 1 to clear
 *  0b1..Fusion Always ON Power switch domain out of reset interrupt flag. This bit is asserted only once after
 *       the power switch domain exits the reset.
 */
#define CMC_RTD_PSDORF_FUSION_AO(x)              (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PSDORF_FUSION_AO_SHIFT)) & CMC_RTD_PSDORF_FUSION_AO_MASK)
/*! @} */

/*! @name RTD_PSDORIE - Real Time Domain Power Switch Domain Out of Reset Interrupt Enable */
/*! @{ */

#define CMC_RTD_PSDORIE_FUSION_MASK              (0x2U)
#define CMC_RTD_PSDORIE_FUSION_SHIFT             (1U)
/*! Fusion - Fusion Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..Fusion Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..Fusion Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_RTD_PSDORIE_FUSION(x)                (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PSDORIE_FUSION_SHIFT)) & CMC_RTD_PSDORIE_FUSION_MASK)

#define CMC_RTD_PSDORIE_FUSION_AO_MASK           (0x4U)
#define CMC_RTD_PSDORIE_FUSION_AO_SHIFT          (2U)
/*! Fusion_AO - Fusion Always ON Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..Fusion Always ON Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..Fusion Always ON Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_RTD_PSDORIE_FUSION_AO(x)             (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PSDORIE_FUSION_AO_SHIFT)) & CMC_RTD_PSDORIE_FUSION_AO_MASK)
/*! @} */

/*! @name RTD_PSDS - Real Time Domain Power Switch Domain Status */
/*! @{ */

#define CMC_RTD_PSDS_RTD_MASK                    (0x1U)
#define CMC_RTD_PSDS_RTD_SHIFT                   (0U)
/*! RTD - Realtime Power Switch Domain Status
 *  0b0..Realtime Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..Realtime Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_RTD_PSDS_RTD(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PSDS_RTD_SHIFT)) & CMC_RTD_PSDS_RTD_MASK)

#define CMC_RTD_PSDS_FUSION_MASK                 (0x2U)
#define CMC_RTD_PSDS_FUSION_SHIFT                (1U)
/*! Fusion - Fusion Power Switch Domain Status
 *  0b0..Fusion Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..Fusion Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_RTD_PSDS_FUSION(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PSDS_FUSION_SHIFT)) & CMC_RTD_PSDS_FUSION_MASK)

#define CMC_RTD_PSDS_FUSION_AO_MASK              (0x4U)
#define CMC_RTD_PSDS_FUSION_AO_SHIFT             (2U)
/*! Fusion_AO - Fusion Always ON Power Switch Domain Status
 *  0b0..Fusion Always ON Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..Fusion Always ON Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_RTD_PSDS_FUSION_AO(x)                (((uint32_t)(((uint32_t)(x)) << CMC_RTD_PSDS_FUSION_AO_SHIFT)) & CMC_RTD_PSDS_FUSION_AO_MASK)
/*! @} */

/*! @name SRS - System Reset Status */
/*! @{ */

#define CMC_SRS_WAKEUP_MASK                      (0x1U)
#define CMC_SRS_WAKEUP_SHIFT                     (0U)
/*! WAKEUP - Wakeup Reset
 *  0b0..Reset not generated by wakeup from Power Down or Deep Power Down mode.
 *  0b1..Reset generated by wakeup from Power Down or Deep Power Down mode.
 */
#define CMC_SRS_WAKEUP(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WAKEUP_SHIFT)) & CMC_SRS_WAKEUP_MASK)

#define CMC_SRS_POR_MASK                         (0x2U)
#define CMC_SRS_POR_SHIFT                        (1U)
/*! POR - Power-On Reset
 *  0b0..Reset not generated by POR.
 *  0b1..Reset generated by POR.
 */
#define CMC_SRS_POR(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_POR_SHIFT)) & CMC_SRS_POR_MASK)

#define CMC_SRS_HLVD_MASK                        (0x4U)
#define CMC_SRS_HLVD_SHIFT                       (2U)
/*! HLVD - High or Low Voltage Detect Reset
 *  0b0..Reset not generated by HLVD.
 *  0b1..Reset generated by HLVD.
 */
#define CMC_SRS_HLVD(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_HLVD_SHIFT)) & CMC_SRS_HLVD_MASK)

#define CMC_SRS_WARM_MASK                        (0x10U)
#define CMC_SRS_WARM_SHIFT                       (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated by Warm Reset source.
 *  0b1..Reset generated by Warm Reset source.
 */
#define CMC_SRS_WARM(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WARM_SHIFT)) & CMC_SRS_WARM_MASK)

#define CMC_SRS_FATAL_MASK                       (0x20U)
#define CMC_SRS_FATAL_SHIFT                      (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated by a fatal reset source.
 *  0b1..Reset was generated by a fatal reset source.
 */
#define CMC_SRS_FATAL(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_FATAL_SHIFT)) & CMC_SRS_FATAL_MASK)

#define CMC_SRS_PIN_MASK                         (0x100U)
#define CMC_SRS_PIN_SHIFT                        (8U)
/*! PIN - Pin Reset
 *  0b0..Reset was not generated from the assertion of RESET0_b pin.
 *  0b1..Reset was generated from the assertion of RESET0_b pin.
 */
#define CMC_SRS_PIN(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_PIN_SHIFT)) & CMC_SRS_PIN_MASK)

#define CMC_SRS_ISP_AP_MASK                      (0x200U)
#define CMC_SRS_ISP_AP_SHIFT                     (9U)
/*! ISP_AP - In-System Programming Access Port Reset
 *  0b0..Reset was not generated from a ISP_AP reset request.
 *  0b1..Reset was generated from a ISP_AP reset request.
 */
#define CMC_SRS_ISP_AP(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_ISP_AP_SHIFT)) & CMC_SRS_ISP_AP_MASK)

#define CMC_SRS_RSTACK_MASK                      (0x400U)
#define CMC_SRS_RSTACK_SHIFT                     (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated from Reset Controller Timeout.
 *  0b1..Reset generated from Reset Controller Timeout.
 */
#define CMC_SRS_RSTACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_RSTACK_SHIFT)) & CMC_SRS_RSTACK_MASK)

#define CMC_SRS_LPACK_MASK                       (0x800U)
#define CMC_SRS_LPACK_SHIFT                      (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset not generated by Low Power Acknowledge Timeout.
 *  0b1..Reset generated by Low Power Acknowledge Timeout.
 */
#define CMC_SRS_LPACK(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_LPACK_SHIFT)) & CMC_SRS_LPACK_MASK)

#define CMC_SRS_RTD_CGC_LOC_MASK                 (0x1000U)
#define CMC_SRS_RTD_CGC_LOC_SHIFT                (12U)
/*! RTD_CGC_LOC - Real Time Domain Clock Generation and Control Loss-of-Clock Reset
 *  0b0..Reset is not generated from an RTD_CGC loss of clock.
 *  0b1..Reset is generated from an RTD_CGC loss of clock.
 */
#define CMC_SRS_RTD_CGC_LOC(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_SRS_RTD_CGC_LOC_SHIFT)) & CMC_SRS_RTD_CGC_LOC_MASK)

#define CMC_SRS_WDOG0_MASK                       (0x2000U)
#define CMC_SRS_WDOG0_SHIFT                      (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Reset is not generated from the WatchDog 0 timeout.
 *  0b1..Reset is generated from the WatchDog 0 timeout.
 */
#define CMC_SRS_WDOG0(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WDOG0_SHIFT)) & CMC_SRS_WDOG0_MASK)

#define CMC_SRS_SW_MASK                          (0x4000U)
#define CMC_SRS_SW_SHIFT                         (14U)
/*! SW - Software Reset
 *  0b0..Reset not generated by software request from core.
 *  0b1..Reset generated by software request from core.
 */
#define CMC_SRS_SW(x)                            (((uint32_t)(((uint32_t)(x)) << CMC_SRS_SW_SHIFT)) & CMC_SRS_SW_MASK)

#define CMC_SRS_LOCKUP_MASK                      (0x8000U)
#define CMC_SRS_LOCKUP_SHIFT                     (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset not generated by core lockup or exception.
 *  0b1..Reset generated by core lockup or exception.
 */
#define CMC_SRS_LOCKUP(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_LOCKUP_SHIFT)) & CMC_SRS_LOCKUP_MASK)

#define CMC_SRS_AD_MU_MASK                       (0x10000U)
#define CMC_SRS_AD_MU_SHIFT                      (16U)
/*! AD_MU - Application Domain MU System Reset
 *  0b0..Reset not generated from AD_MU reset source.
 *  0b1..Reset generated from AD_MU reset source.
 */
#define CMC_SRS_AD_MU(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_AD_MU_SHIFT)) & CMC_SRS_AD_MU_MASK)

#define CMC_SRS_RTD_CGC_LOS_MASK                 (0x80000U)
#define CMC_SRS_RTD_CGC_LOS_SHIFT                (19U)
/*! RTD_CGC_LOS - RTD Clock Generation and Control Loss Of Sync
 *  0b0..Reset not generated from RTD_CGC_LOS system reset source.
 *  0b1..Reset generated from RTD_CGC_LOS system reset source.
 */
#define CMC_SRS_RTD_CGC_LOS(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_SRS_RTD_CGC_LOS_SHIFT)) & CMC_SRS_RTD_CGC_LOS_MASK)

#define CMC_SRS_LPAV_CGC_LOS_MASK                (0x400000U)
#define CMC_SRS_LPAV_CGC_LOS_SHIFT               (22U)
/*! LPAV_CGC_LOS - LPAV Clock Generation and Control Loss Of Sync
 *  0b0..Reset not generated from LPAV_CGC_LOS system reset source.
 *  0b1..Reset generated from LPAV_CGC_LOS system reset source.
 */
#define CMC_SRS_LPAV_CGC_LOS(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_SRS_LPAV_CGC_LOS_SHIFT)) & CMC_SRS_LPAV_CGC_LOS_MASK)

#define CMC_SRS_UPOWER_MASK                      (0x800000U)
#define CMC_SRS_UPOWER_SHIFT                     (23U)
/*! uPOWER - uPOWER WDOG System Reset
 *  0b0..Reset not generated by uPOWER WDOG timeout.
 *  0b1..Reset generated by uPOWER WDOG timeout.
 */
#define CMC_SRS_UPOWER(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRS_UPOWER_SHIFT)) & CMC_SRS_UPOWER_MASK)

#define CMC_SRS_VBAT_MASK                        (0x1000000U)
#define CMC_SRS_VBAT_SHIFT                       (24U)
/*! VBAT - VBAT System Reset
 *  0b0..Reset not generated by VBAT system reset.
 *  0b1..Reset generated by VBAT system reset.
 */
#define CMC_SRS_VBAT(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_VBAT_SHIFT)) & CMC_SRS_VBAT_MASK)

#define CMC_SRS_WDOG_S_RTD_MASK                  (0x2000000U)
#define CMC_SRS_WDOG_S_RTD_SHIFT                 (25U)
/*! WDOG_S_RTD - Watchdog 1 Reset
 *  0b0..Reset is not generated from the WDOG_S_RTD timeout.
 *  0b1..Reset is generated from the WDOG_S_RTD timeout.
 */
#define CMC_SRS_WDOG_S_RTD(x)                    (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WDOG_S_RTD_SHIFT)) & CMC_SRS_WDOG_S_RTD_MASK)

#define CMC_SRS_WDOG5_MASK                       (0x4000000U)
#define CMC_SRS_WDOG5_SHIFT                      (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Reset is not generated from the WDOG5 timeout.
 *  0b1..Reset is generated from the WDOG5 timeout.
 */
#define CMC_SRS_WDOG5(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WDOG5_SHIFT)) & CMC_SRS_WDOG5_MASK)

#define CMC_SRS_WDOG_FUSION_MASK                 (0x8000000U)
#define CMC_SRS_WDOG_FUSION_SHIFT                (27U)
/*! WDOG_FUSION - Watchdog 2 Reset
 *  0b0..Reset is not generated from the WDOG_FUSION timeout.
 *  0b1..Reset is generated from the WDOG_FUSION timeout.
 */
#define CMC_SRS_WDOG_FUSION(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_SRS_WDOG_FUSION_SHIFT)) & CMC_SRS_WDOG_FUSION_MASK)

#define CMC_SRS_JTAG_MASK                        (0x10000000U)
#define CMC_SRS_JTAG_SHIFT                       (28U)
/*! JTAG - JTAG System Reset
 *  0b0..Reset not generated by JTAG system reset.
 *  0b1..Reset generated by JTAG system reset.
 */
#define CMC_SRS_JTAG(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SRS_JTAG_SHIFT)) & CMC_SRS_JTAG_MASK)

#define CMC_SRS_SLB_MASK                         (0x20000000U)
#define CMC_SRS_SLB_SHIFT                        (29U)
/*! SLB - Secure enclave Lifecycle Bricked Reset
 *  0b0..Reset not generated by Secure enclave Lifecycle check.
 *  0b1..Reset generated by Secure enclave Lifecycle check.
 */
#define CMC_SRS_SLB(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_SLB_SHIFT)) & CMC_SRS_SLB_MASK)

#define CMC_SRS_SRR_MASK                         (0x40000000U)
#define CMC_SRS_SRR_SHIFT                        (30U)
/*! SRR - Secure enclave Reset Request
 *  0b0..Reset not generated by SRR.
 *  0b1..Reset generated by SRR.
 */
#define CMC_SRS_SRR(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_SRR_SHIFT)) & CMC_SRS_SRR_MASK)

#define CMC_SRS_SSF_MASK                         (0x80000000U)
#define CMC_SRS_SSF_SHIFT                        (31U)
/*! SSF - Secure enclave System Fail Reset
 *  0b0..Reset not generated by SSF.
 *  0b1..Reset generated by SSF.
 */
#define CMC_SRS_SSF(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRS_SSF_SHIFT)) & CMC_SRS_SSF_MASK)
/*! @} */

/*! @name SSRS - Sticky System Reset Status */
/*! @{ */

#define CMC_SSRS_WAKEUP_MASK                     (0x1U)
#define CMC_SSRS_WAKEUP_SHIFT                    (0U)
/*! WAKEUP - Wakeup Reset
 *  0b0..Reset not generated by wakeup from DPD mode.
 *  0b1..Reset generated by wakeup from DPD mode.
 */
#define CMC_SSRS_WAKEUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WAKEUP_SHIFT)) & CMC_SSRS_WAKEUP_MASK)

#define CMC_SSRS_POR_MASK                        (0x2U)
#define CMC_SSRS_POR_SHIFT                       (1U)
/*! POR - Power-On Reset
 *  0b0..Reset not generated by POR.
 *  0b1..Reset generated by POR.
 */
#define CMC_SSRS_POR(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_POR_SHIFT)) & CMC_SSRS_POR_MASK)

#define CMC_SSRS_HLVD_MASK                       (0x4U)
#define CMC_SSRS_HLVD_SHIFT                      (2U)
/*! HLVD - High or Low Voltage Detect Reset
 *  0b0..Reset not generated by HLVD.
 *  0b1..Reset generated by HLVD.
 */
#define CMC_SSRS_HLVD(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_HLVD_SHIFT)) & CMC_SSRS_HLVD_MASK)

#define CMC_SSRS_WARM_MASK                       (0x10U)
#define CMC_SSRS_WARM_SHIFT                      (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated by warm reset source.
 *  0b1..Reset generated by warm reset source.
 */
#define CMC_SSRS_WARM(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WARM_SHIFT)) & CMC_SSRS_WARM_MASK)

#define CMC_SSRS_FATAL_MASK                      (0x20U)
#define CMC_SSRS_FATAL_SHIFT                     (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated by a fatal reset source.
 *  0b1..Reset was generated by a fatal reset source.
 */
#define CMC_SSRS_FATAL(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_FATAL_SHIFT)) & CMC_SSRS_FATAL_MASK)

#define CMC_SSRS_PIN_MASK                        (0x100U)
#define CMC_SSRS_PIN_SHIFT                       (8U)
/*! PIN - Pin Reset
 *  0b0..Reset was not generated from the RESET_B pin.
 *  0b1..Reset was generated from the RESET_B pin.
 */
#define CMC_SSRS_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_PIN_SHIFT)) & CMC_SSRS_PIN_MASK)

#define CMC_SSRS_ISP_AP_MASK                     (0x200U)
#define CMC_SSRS_ISP_AP_SHIFT                    (9U)
/*! ISP_AP - In-System Programming Access Port Reset
 *  0b0..Reset was not generated from a Debug Access Port reset request.
 *  0b1..Reset was generated from a Debug Access Port reset request.
 */
#define CMC_SSRS_ISP_AP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_ISP_AP_SHIFT)) & CMC_SSRS_ISP_AP_MASK)

#define CMC_SSRS_RSTACK_MASK                     (0x400U)
#define CMC_SSRS_RSTACK_SHIFT                    (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated from Reset Controller Timeout.
 *  0b1..Reset generated from Reset Controller Timeout.
 */
#define CMC_SSRS_RSTACK(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_RSTACK_SHIFT)) & CMC_SSRS_RSTACK_MASK)

#define CMC_SSRS_LPACK_MASK                      (0x800U)
#define CMC_SSRS_LPACK_SHIFT                     (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset not generated by Low Power Acknowledge Timeout.
 *  0b1..Reset generated by Low Power Acknowledge Timeout.
 */
#define CMC_SSRS_LPACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_LPACK_SHIFT)) & CMC_SSRS_LPACK_MASK)

#define CMC_SSRS_RTD_CGC_LOC_MASK                (0x1000U)
#define CMC_SSRS_RTD_CGC_LOC_SHIFT               (12U)
/*! RTD_CGC_LOC - RTD Clock Generation and Control Loss-of-Clock Reset
 *  0b0..Reset is not generated from an RTD CGC loss of clock.
 *  0b1..Reset is generated from an RTDF CGC loss of clock.
 */
#define CMC_SSRS_RTD_CGC_LOC(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_RTD_CGC_LOC_SHIFT)) & CMC_SSRS_RTD_CGC_LOC_MASK)

#define CMC_SSRS_WDOG0_MASK                      (0x2000U)
#define CMC_SSRS_WDOG0_SHIFT                     (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Reset is not generated from the WatchDog 0 timeout.
 *  0b1..Reset is generated from the WatchDog 0 timeout.
 */
#define CMC_SSRS_WDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WDOG0_SHIFT)) & CMC_SSRS_WDOG0_MASK)

#define CMC_SSRS_SW_MASK                         (0x4000U)
#define CMC_SSRS_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Reset not generated by software request from core.
 *  0b1..Reset generated by software request from core.
 */
#define CMC_SSRS_SW(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_SW_SHIFT)) & CMC_SSRS_SW_MASK)

#define CMC_SSRS_LOCKUP_MASK                     (0x8000U)
#define CMC_SSRS_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset not generated by core lockup.
 *  0b1..Reset generated by core lockup.
 */
#define CMC_SSRS_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_LOCKUP_SHIFT)) & CMC_SSRS_LOCKUP_MASK)

#define CMC_SSRS_AD_MU_MASK                      (0x10000U)
#define CMC_SSRS_AD_MU_SHIFT                     (16U)
/*! AD_MU - Application Domain MU System Reset
 *  0b0..Reset not generated from AD_MU reset source.
 *  0b1..Reset generated from AD_MU reset source.
 */
#define CMC_SSRS_AD_MU(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_AD_MU_SHIFT)) & CMC_SSRS_AD_MU_MASK)

#define CMC_SSRS_RTD_CGC_LOS_MASK                (0x80000U)
#define CMC_SSRS_RTD_CGC_LOS_SHIFT               (19U)
/*! RTD_CGC_LOS - RTD Clock Generation and Control Loss Of Sync
 *  0b0..Reset not generated from RTD_CGC_LOS system reset source.
 *  0b1..Reset generated from RTD_CGC_LOS system reset source.
 */
#define CMC_SSRS_RTD_CGC_LOS(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_RTD_CGC_LOS_SHIFT)) & CMC_SSRS_RTD_CGC_LOS_MASK)

#define CMC_SSRS_LPAV_CGC_LOS_MASK               (0x400000U)
#define CMC_SSRS_LPAV_CGC_LOS_SHIFT              (22U)
/*! LPAV_CGC_LOS - LPAV Clock Generation and Control Loss Of Sync
 *  0b0..Reset not generated from LPAV_CGC_LOS system reset source.
 *  0b1..Reset generated from LPAV_CGC_LOS system reset source.
 */
#define CMC_SSRS_LPAV_CGC_LOS(x)                 (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_LPAV_CGC_LOS_SHIFT)) & CMC_SSRS_LPAV_CGC_LOS_MASK)

#define CMC_SSRS_UPOWER_MASK                     (0x800000U)
#define CMC_SSRS_UPOWER_SHIFT                    (23U)
/*! uPOWER - uPOWER WDOG System Reset
 *  0b0..Reset not generated by uPOWER WDOG timeout.
 *  0b1..Reset generated by uPOWER WDOG timeout.
 */
#define CMC_SSRS_UPOWER(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_UPOWER_SHIFT)) & CMC_SSRS_UPOWER_MASK)

#define CMC_SSRS_VBAT_MASK                       (0x1000000U)
#define CMC_SSRS_VBAT_SHIFT                      (24U)
/*! VBAT - VBAT System Reset
 *  0b0..Reset not generated by VBAT system reset.
 *  0b1..Reset generated by VBAT system reset.
 */
#define CMC_SSRS_VBAT(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_VBAT_SHIFT)) & CMC_SSRS_VBAT_MASK)

#define CMC_SSRS_WDOG_S_RTD_MASK                 (0x2000000U)
#define CMC_SSRS_WDOG_S_RTD_SHIFT                (25U)
/*! WDOG_S_RTD - Watchdog 1 Reset
 *  0b0..Reset is not generated from the WDOG_S_RTD timeout.
 *  0b1..Reset is generated from the WDOG_S_RTD timeout.
 */
#define CMC_SSRS_WDOG_S_RTD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WDOG_S_RTD_SHIFT)) & CMC_SSRS_WDOG_S_RTD_MASK)

#define CMC_SSRS_WDOG5_MASK                      (0x4000000U)
#define CMC_SSRS_WDOG5_SHIFT                     (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Reset is not generated from the WDOG5 timeout.
 *  0b1..Reset is generated from the WDOG5 timeout.
 */
#define CMC_SSRS_WDOG5(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WDOG5_SHIFT)) & CMC_SSRS_WDOG5_MASK)

#define CMC_SSRS_WDOG_FUSION_MASK                (0x8000000U)
#define CMC_SSRS_WDOG_FUSION_SHIFT               (27U)
/*! WDOG_FUSION - Watchdog 2 Reset
 *  0b0..Reset is not generated from the WDOG_FUSION timeout.
 *  0b1..Reset is generated from the WDOG_FUSION timeout.
 */
#define CMC_SSRS_WDOG_FUSION(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_WDOG_FUSION_SHIFT)) & CMC_SSRS_WDOG_FUSION_MASK)

#define CMC_SSRS_JTAG_MASK                       (0x10000000U)
#define CMC_SSRS_JTAG_SHIFT                      (28U)
/*! JTAG - JTAG System Reset
 *  0b0..Reset not generated by JTAG system reset.
 *  0b1..Reset generated by JTAG system reset.
 */
#define CMC_SSRS_JTAG(x)                         (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_JTAG_SHIFT)) & CMC_SSRS_JTAG_MASK)

#define CMC_SSRS_SLB_MASK                        (0x20000000U)
#define CMC_SSRS_SLB_SHIFT                       (29U)
/*! SLB - Secure enclave Lifecycle Bricked Reset
 *  0b0..Reset not generated by Secure enclave Lifecycle check.
 *  0b1..Reset generated by Secure enclave Lifecycle check.
 */
#define CMC_SSRS_SLB(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_SLB_SHIFT)) & CMC_SSRS_SLB_MASK)

#define CMC_SSRS_SRR_MASK                        (0x40000000U)
#define CMC_SSRS_SRR_SHIFT                       (30U)
/*! SRR - Secure enclave Reset Request
 *  0b0..Reset not generated by SRR.
 *  0b1..Reset generated by SRR.
 */
#define CMC_SSRS_SRR(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_SRR_SHIFT)) & CMC_SSRS_SRR_MASK)

#define CMC_SSRS_SFF_MASK                        (0x80000000U)
#define CMC_SSRS_SFF_SHIFT                       (31U)
/*! SFF - Secure enclave System Fail Reset
 *  0b0..Reset not generated by SFF.
 *  0b1..Reset generated by SFF.
 */
#define CMC_SSRS_SFF(x)                          (((uint32_t)(((uint32_t)(x)) << CMC_SSRS_SFF_SHIFT)) & CMC_SSRS_SFF_MASK)
/*! @} */

/*! @name SRIE - System Reset Interrupt Enable */
/*! @{ */

#define CMC_SRIE_ISP_AP_MASK                     (0x200U)
#define CMC_SRIE_ISP_AP_SHIFT                    (9U)
/*! ISP_AP - In-System Programming Access Port Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_ISP_AP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_ISP_AP_SHIFT)) & CMC_SRIE_ISP_AP_MASK)

#define CMC_SRIE_LPACK_MASK                      (0x800U)
#define CMC_SRIE_LPACK_SHIFT                     (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_LPACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_LPACK_SHIFT)) & CMC_SRIE_LPACK_MASK)

#define CMC_SRIE_WDOG0_MASK                      (0x2000U)
#define CMC_SRIE_WDOG0_SHIFT                     (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_WDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WDOG0_SHIFT)) & CMC_SRIE_WDOG0_MASK)

#define CMC_SRIE_SW_MASK                         (0x4000U)
#define CMC_SRIE_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_SW(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_SW_SHIFT)) & CMC_SRIE_SW_MASK)

#define CMC_SRIE_LOCKUP_MASK                     (0x8000U)
#define CMC_SRIE_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_LOCKUP_SHIFT)) & CMC_SRIE_LOCKUP_MASK)

#define CMC_SRIE_AD_MU_MASK                      (0x10000U)
#define CMC_SRIE_AD_MU_SHIFT                     (16U)
/*! AD_MU - Application Domain MU System Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_AD_MU(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_AD_MU_SHIFT)) & CMC_SRIE_AD_MU_MASK)

#define CMC_SRIE_WDOG_S_RTD_MASK                 (0x2000000U)
#define CMC_SRIE_WDOG_S_RTD_SHIFT                (25U)
/*! WDOG_S_RTD - Watchdog 1 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_WDOG_S_RTD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WDOG_S_RTD_SHIFT)) & CMC_SRIE_WDOG_S_RTD_MASK)

#define CMC_SRIE_WDOG5_MASK                      (0x4000000U)
#define CMC_SRIE_WDOG5_SHIFT                     (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_WDOG5(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WDOG5_SHIFT)) & CMC_SRIE_WDOG5_MASK)

#define CMC_SRIE_WDOG_FUSION_MASK                (0x8000000U)
#define CMC_SRIE_WDOG_FUSION_SHIFT               (27U)
/*! WDOG_FUSION - Watchdog 2 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define CMC_SRIE_WDOG_FUSION(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_SRIE_WDOG_FUSION_SHIFT)) & CMC_SRIE_WDOG_FUSION_MASK)
/*! @} */

/*! @name SRIF - System Reset Interrupt Flag */
/*! @{ */

#define CMC_SRIF_ISP_AP_MASK                     (0x200U)
#define CMC_SRIF_ISP_AP_SHIFT                    (9U)
/*! ISP_AP - In-System Programming Access Port Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_ISP_AP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_ISP_AP_SHIFT)) & CMC_SRIF_ISP_AP_MASK)

#define CMC_SRIF_LPACK_MASK                      (0x800U)
#define CMC_SRIF_LPACK_SHIFT                     (11U)
/*! LPACK - Low Power Acknowledge Timeout Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_LPACK(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_LPACK_SHIFT)) & CMC_SRIF_LPACK_MASK)

#define CMC_SRIF_WDOG0_MASK                      (0x2000U)
#define CMC_SRIF_WDOG0_SHIFT                     (13U)
/*! WDOG0 - Watchdog 0 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_WDOG0(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WDOG0_SHIFT)) & CMC_SRIF_WDOG0_MASK)

#define CMC_SRIF_SW_MASK                         (0x4000U)
#define CMC_SRIF_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_SW(x)                           (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_SW_SHIFT)) & CMC_SRIF_SW_MASK)

#define CMC_SRIF_LOCKUP_MASK                     (0x8000U)
#define CMC_SRIF_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_LOCKUP_SHIFT)) & CMC_SRIF_LOCKUP_MASK)

#define CMC_SRIF_AD_MU_MASK                      (0x10000U)
#define CMC_SRIF_AD_MU_SHIFT                     (16U)
/*! AD_MU - Application Domain MU System Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_AD_MU(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_AD_MU_SHIFT)) & CMC_SRIF_AD_MU_MASK)

#define CMC_SRIF_WDOG_S_RTD_MASK                 (0x2000000U)
#define CMC_SRIF_WDOG_S_RTD_SHIFT                (25U)
/*! WDOG_S_RTD - Watchdog 1 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_WDOG_S_RTD(x)                   (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WDOG_S_RTD_SHIFT)) & CMC_SRIF_WDOG_S_RTD_MASK)

#define CMC_SRIF_WDOG5_MASK                      (0x4000000U)
#define CMC_SRIF_WDOG5_SHIFT                     (26U)
/*! WDOG5 - Watchdog 5 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_WDOG5(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WDOG5_SHIFT)) & CMC_SRIF_WDOG5_MASK)

#define CMC_SRIF_WDOG_FUSION_MASK                (0x8000000U)
#define CMC_SRIF_WDOG_FUSION_SHIFT               (27U)
/*! WDOG_FUSION - Watchdog 2 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define CMC_SRIF_WDOG_FUSION(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_SRIF_WDOG_FUSION_SHIFT)) & CMC_SRIF_WDOG_FUSION_MASK)
/*! @} */

/*! @name MR - Mode Register */
/*! @{ */

#define CMC_MR_BOOTCFG_MASK                      (0xFFFFFFFFU)
#define CMC_MR_BOOTCFG_SHIFT                     (0U)
/*! BOOTCFG - Boot Configuration */
#define CMC_MR_BOOTCFG(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_MR_BOOTCFG_SHIFT)) & CMC_MR_BOOTCFG_MASK)
/*! @} */

/*! @name FM - Force Mode Register */
/*! @{ */

#define CMC_FM_FORCECFG_MASK                     (0xFFFFFFFFU)
#define CMC_FM_FORCECFG_SHIFT                    (0U)
/*! FORCECFG - Boot Configuration
 *  0b00000000000000000000000000000000..No effect.
 *  0b00000000000000000000000000000001..Assert corresponding bit in Mode Register on next system reset.
 */
#define CMC_FM_FORCECFG(x)                       (((uint32_t)(((uint32_t)(x)) << CMC_FM_FORCECFG_SHIFT)) & CMC_FM_FORCECFG_MASK)
/*! @} */

/*! @name CORECTL - Core Control Register */
/*! @{ */

#define CMC_CORECTL_NPIE_MASK                    (0x1U)
#define CMC_CORECTL_NPIE_SHIFT                   (0U)
/*! NPIE - Non maskable Pin Interrupt Enable
 *  0b0..Pin interrupt disabled
 *  0b1..Pin interrupt enabled
 */
#define CMC_CORECTL_NPIE(x)                      (((uint32_t)(((uint32_t)(x)) << CMC_CORECTL_NPIE_SHIFT)) & CMC_CORECTL_NPIE_MASK)
/*! @} */

/*! @name DBGCTL - Debug Control Register */
/*! @{ */

#define CMC_DBGCTL_SOD_MASK                      (0x1U)
#define CMC_DBGCTL_SOD_SHIFT                     (0U)
/*! SOD - Sleep Or Debug
 *  0b0..Debug remains enabled when Core is sleeping.
 *  0b1..Debug is disabled when Core is sleeping.
 */
#define CMC_DBGCTL_SOD(x)                        (((uint32_t)(((uint32_t)(x)) << CMC_DBGCTL_SOD_SHIFT)) & CMC_DBGCTL_SOD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMC_Register_Masks */

/* Backward compatibility */
 #define CMC_SRS_WDOG_HIFI4_MASK                 CMC_SRS_WDOG5_MASK
 #define CMC_SRS_WDOG_HIFI4_SHIFT                CMC_SRS_WDOG5_SHIFT
 #define CMC_SRS_WDOG_HIFI4(x)                   CMC_SRS_WDOG5(x)
 #define CMC_SSRS_WDOG_HIFI4_MASK                CMC_SSRS_WDOG5_MASK
 #define CMC_SSRS_WDOG_HIFI4_SHIFT               CMC_SSRS_WDOG5_SHIFT
 #define CMC_SSRS_WDOG_HIFI4(x)                  CMC_SSRS_WDOG5(x)
 #define CMC_SRIE_WDOG_HIFI4_MASK                CMC_SRIE_WDOG5_MASK
 #define CMC_SRIE_WDOG_HIFI4_SHIFT               CMC_SRIE_WDOG5_SHIFT
 #define CMC_SRIE_WDOG_HIFI4(x)                  CMC_SRIE_WDOG5(x)
 #define CMC_SRIF_WDOG_HIFI4_MASK                CMC_SRIF_WDOG5_MASK
 #define CMC_SRIF_WDOG_HIFI4_SHIFT               CMC_SRIF_WDOG5_SHIFT
 #define CMC_SRIF_WDOG_HIFI4(x)                  CMC_SRIF_WDOG5(x)


/*!
 * @}
 */ /* end of group CMC_Peripheral_Access_Layer */


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


#endif  /* PERI_CMC_H_ */

