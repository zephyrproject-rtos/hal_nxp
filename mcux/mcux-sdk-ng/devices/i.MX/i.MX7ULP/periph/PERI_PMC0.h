/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMC0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PMC0.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC0
 *
 * CMSIS Peripheral Access Layer for PMC0
 */

#if !defined(PERI_PMC0_H_)
#define PERI_PMC0_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- PMC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC0_Peripheral_Access_Layer PMC0 Peripheral Access Layer
 * @{
 */

/** PMC0 - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< PMC 0 Version register, offset: 0x0 */
  __I  uint32_t PM_STAT;                           /**< PMC 0 Power Mode Status register, offset: 0x4 */
  __IO uint32_t HSRUN;                             /**< PMC 0 HSRUN mode register, offset: 0x8 */
  __IO uint32_t RUN;                               /**< PMC 0 RUN mode register, offset: 0xC */
  __IO uint32_t VLPR;                              /**< PMC 0 VLPR mode register, offset: 0x10 */
  __IO uint32_t STOP;                              /**< PMC 0 STOP mode register, offset: 0x14 */
  __IO uint32_t VLPS;                              /**< PMC 0 VLPS mode register, offset: 0x18 */
  __IO uint32_t LLS;                               /**< PMC 0 LLS mode register, offset: 0x1C */
  __IO uint32_t VLLS;                              /**< PMC 0 VLLS mode register, offset: 0x20 */
  __I  uint32_t STATUS;                            /**< PMC 0 Status register, offset: 0x24 */
  __IO uint32_t CTRL;                              /**< PMC 0 Control register, offset: 0x28 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ACTRL;                             /**< PMC 0 Analog Core Control register, offset: 0x30 */
       uint8_t RESERVED_1[4];
  __IO uint32_t BCTRL;                             /**< PMC 0 Biasing Control register, offset: 0x38 */
       uint8_t RESERVED_2[12];
  __IO uint32_t SRAMCTRL_0;                        /**< PMC 0 SRAMs Control 0 register, offset: 0x48 */
  __IO uint32_t SRAMCTRL_1;                        /**< PMC 0 SRAMs Control 1 register, offset: 0x4C */
  __IO uint32_t SRAMCTRL_2;                        /**< PMC 0 SRAMs Control 2 register, offset: 0x50 */
} PMC0_Type;

/* ----------------------------------------------------------------------------
   -- PMC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC0_Register_Masks PMC0 Register Masks
 * @{
 */

/*! @name VERID - PMC 0 Version register */
/*! @{ */

#define PMC0_VERID_FEATURE_MASK                  (0xFFFFU)
#define PMC0_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented
 */
#define PMC0_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_VERID_FEATURE_SHIFT)) & PMC0_VERID_FEATURE_MASK)

#define PMC0_VERID_MINOR_MASK                    (0xFF0000U)
#define PMC0_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define PMC0_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VERID_MINOR_SHIFT)) & PMC0_VERID_MINOR_MASK)

#define PMC0_VERID_MAJOR_MASK                    (0xFF000000U)
#define PMC0_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define PMC0_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VERID_MAJOR_SHIFT)) & PMC0_VERID_MAJOR_MASK)
/*! @} */

/*! @name PM_STAT - PMC 0 Power Mode Status register */
/*! @{ */

#define PMC0_PM_STAT_PMC0CURRPM_MASK             (0x7U)
#define PMC0_PM_STAT_PMC0CURRPM_SHIFT            (0U)
/*! PMC0CURRPM - PMC 0 Current Power Mode
 *  0b000..HSRUN Mode
 *  0b001..RUN Mode
 *  0b010..STOP Mode
 *  0b011..VLPR Mode
 *  0b100..VLPS Mode
 *  0b101..LLS Mode
 *  0b110..VLLS Mode
 */
#define PMC0_PM_STAT_PMC0CURRPM(x)               (((uint32_t)(((uint32_t)(x)) << PMC0_PM_STAT_PMC0CURRPM_SHIFT)) & PMC0_PM_STAT_PMC0CURRPM_MASK)

#define PMC0_PM_STAT_PMC0TRANPM_MASK             (0x10U)
#define PMC0_PM_STAT_PMC0TRANPM_SHIFT            (4U)
/*! PMC0TRANPM - PMC 0 Power Mode transition status
 *  0b0..PMC 0 is not in a power mode transition.
 *  0b1..PMC 0 is in a power mode transition.
 */
#define PMC0_PM_STAT_PMC0TRANPM(x)               (((uint32_t)(((uint32_t)(x)) << PMC0_PM_STAT_PMC0TRANPM_SHIFT)) & PMC0_PM_STAT_PMC0TRANPM_MASK)

#define PMC0_PM_STAT_PMC1CURRPM_MASK             (0x70000U)
#define PMC0_PM_STAT_PMC1CURRPM_SHIFT            (16U)
/*! PMC1CURRPM - PMC 1 Current Power Mode
 *  0b000..HSRUN Mode
 *  0b001..RUN Mode
 *  0b010..STOP Mode
 *  0b011..VLPR Mode
 *  0b100..VLPS Mode
 *  0b101..LLS Mode
 *  0b110..VLLS Mode
 */
#define PMC0_PM_STAT_PMC1CURRPM(x)               (((uint32_t)(((uint32_t)(x)) << PMC0_PM_STAT_PMC1CURRPM_SHIFT)) & PMC0_PM_STAT_PMC1CURRPM_MASK)

#define PMC0_PM_STAT_PMC1TRANPM_MASK             (0x100000U)
#define PMC0_PM_STAT_PMC1TRANPM_SHIFT            (20U)
/*! PMC1TRANPM - PMC 1 Power Mode transition status
 *  0b0..PMC 1 is not in a power mode transition.
 *  0b1..PMC 1 is in a power mode transition.
 */
#define PMC0_PM_STAT_PMC1TRANPM(x)               (((uint32_t)(((uint32_t)(x)) << PMC0_PM_STAT_PMC1TRANPM_SHIFT)) & PMC0_PM_STAT_PMC1TRANPM_MASK)
/*! @} */

/*! @name HSRUN - PMC 0 HSRUN mode register */
/*! @{ */

#define PMC0_HSRUN_COREREGVL_MASK                (0x3F0000U)
#define PMC0_HSRUN_COREREGVL_SHIFT               (16U)
/*! COREREGVL - Core Regulator Voltage Level
 *  0b000000..Core Voltage Level is 0.596V
 *  0b000001..Core Voltage Level is 0.607V
 *  0b110001..Core Voltage Level is 1.127V
 *  0b110010..Core Voltage Level is 1.138V
 */
#define PMC0_HSRUN_COREREGVL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC0_HSRUN_COREREGVL_SHIFT)) & PMC0_HSRUN_COREREGVL_MASK)

#define PMC0_HSRUN_FBBEN_MASK                    (0x1000000U)
#define PMC0_HSRUN_FBBEN_SHIFT                   (24U)
/*! FBBEN - Forward Back Bias Enable
 *  0b0..FBB is disabled
 *  0b1..FBB is enabled
 */
#define PMC0_HSRUN_FBBEN(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_HSRUN_FBBEN_SHIFT)) & PMC0_HSRUN_FBBEN_MASK)
/*! @} */

/*! @name RUN - PMC 0 RUN mode register */
/*! @{ */

#define PMC0_RUN_COREREGVL_MASK                  (0x3F0000U)
#define PMC0_RUN_COREREGVL_SHIFT                 (16U)
/*! COREREGVL - Core Regulator Voltage Level
 *  0b000000..Core Voltage Level is 0.596V
 *  0b000001..Core Voltage Level is 0.607V
 *  0b110001..Core Voltage Level is 1.127V
 *  0b110010..Core Voltage Level is 1.138V
 */
#define PMC0_RUN_COREREGVL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_RUN_COREREGVL_SHIFT)) & PMC0_RUN_COREREGVL_MASK)
/*! @} */

/*! @name VLPR - PMC 0 VLPR mode register */
/*! @{ */

#define PMC0_VLPR_ARRAYREG_MASK                  (0x1U)
#define PMC0_VLPR_ARRAYREG_SHIFT                 (0U)
/*! ARRAYREG - Array Regulator
 *  0b0..LP Regulator is on
 *  0b1..HP Regulator is on
 */
#define PMC0_VLPR_ARRAYREG(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_VLPR_ARRAYREG_SHIFT)) & PMC0_VLPR_ARRAYREG_MASK)

#define PMC0_VLPR_COREREG_MASK                   (0x4U)
#define PMC0_VLPR_COREREG_SHIFT                  (2U)
/*! COREREG - Core Regulator Enable
 *  0b0..LP Regulator is on
 *  0b1..HP Regulator is on
 */
#define PMC0_VLPR_COREREG(x)                     (((uint32_t)(((uint32_t)(x)) << PMC0_VLPR_COREREG_SHIFT)) & PMC0_VLPR_COREREG_MASK)

#define PMC0_VLPR_MONLVD_MASK                    (0x10U)
#define PMC0_VLPR_MONLVD_SHIFT                   (4U)
/*! MONLVD - 1.2V LVD HP Monitor Enable
 *  0b0..LP monitor is enabled
 *  0b1..HP monitor is enabled
 */
#define PMC0_VLPR_MONLVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VLPR_MONLVD_SHIFT)) & PMC0_VLPR_MONLVD_MASK)

#define PMC0_VLPR_MONHVD_MASK                    (0x20U)
#define PMC0_VLPR_MONHVD_SHIFT                   (5U)
/*! MONHVD - 1.8V HVD HP Monitor Enable
 *  0b0..The monitor is disabled
 *  0b1..The monitor is enabled
 */
#define PMC0_VLPR_MONHVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VLPR_MONHVD_SHIFT)) & PMC0_VLPR_MONHVD_MASK)

#define PMC0_VLPR_FBGHP_MASK                     (0x80U)
#define PMC0_VLPR_FBGHP_SHIFT                    (7U)
/*! FBGHP - Force HP band-gap
 *  0b0..No action
 *  0b1..Turn on the HP band-gap
 */
#define PMC0_VLPR_FBGHP(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_VLPR_FBGHP_SHIFT)) & PMC0_VLPR_FBGHP_MASK)

#define PMC0_VLPR_COREREGVL_MASK                 (0x3F0000U)
#define PMC0_VLPR_COREREGVL_SHIFT                (16U)
/*! COREREGVL - Core Regulator Voltage Level
 *  0b000000..Core Voltage Level is 0.596V
 *  0b000001..Core Voltage Level is 0.607V
 *  0b110001..Core Voltage Level is 1.127V
 *  0b110010..Core Voltage Level is 1.138V
 */
#define PMC0_VLPR_COREREGVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC0_VLPR_COREREGVL_SHIFT)) & PMC0_VLPR_COREREGVL_MASK)

#define PMC0_VLPR_RBBEN_MASK                     (0x10000000U)
#define PMC0_VLPR_RBBEN_SHIFT                    (28U)
/*! RBBEN - Reverse Back Bias Enable
 *  0b0..RBB is disabled
 *  0b1..RBB is enabled
 */
#define PMC0_VLPR_RBBEN(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_VLPR_RBBEN_SHIFT)) & PMC0_VLPR_RBBEN_MASK)
/*! @} */

/*! @name STOP - PMC 0 STOP mode register */
/*! @{ */

#define PMC0_STOP_COREREGVL_MASK                 (0x3F0000U)
#define PMC0_STOP_COREREGVL_SHIFT                (16U)
/*! COREREGVL - Core Regulator Voltage Level
 *  0b000000..Core Voltage Level is 0.596V
 *  0b000001..Core Voltage Level is 0.607V
 *  0b110001..Core Voltage Level is 1.127V
 *  0b110010..Core Voltage Level is 1.138V
 */
#define PMC0_STOP_COREREGVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC0_STOP_COREREGVL_SHIFT)) & PMC0_STOP_COREREGVL_MASK)
/*! @} */

/*! @name VLPS - PMC 0 VLPS mode register */
/*! @{ */

#define PMC0_VLPS_ARRAYREG_MASK                  (0x1U)
#define PMC0_VLPS_ARRAYREG_SHIFT                 (0U)
/*! ARRAYREG - Array Regulator
 *  0b0..LP Regulator is on
 *  0b1..HP Regulator is on
 */
#define PMC0_VLPS_ARRAYREG(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_VLPS_ARRAYREG_SHIFT)) & PMC0_VLPS_ARRAYREG_MASK)

#define PMC0_VLPS_COREREG_MASK                   (0x4U)
#define PMC0_VLPS_COREREG_SHIFT                  (2U)
/*! COREREG - Core Regulator
 *  0b0..LP Regulator is on
 *  0b1..HP Regulator is on
 */
#define PMC0_VLPS_COREREG(x)                     (((uint32_t)(((uint32_t)(x)) << PMC0_VLPS_COREREG_SHIFT)) & PMC0_VLPS_COREREG_MASK)

#define PMC0_VLPS_MONLVD_MASK                    (0x10U)
#define PMC0_VLPS_MONLVD_SHIFT                   (4U)
/*! MONLVD - 1.2V LVD HP Monitor Enable
 *  0b0..LP monitor is enabled
 *  0b1..HP monitor is enabled
 */
#define PMC0_VLPS_MONLVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VLPS_MONLVD_SHIFT)) & PMC0_VLPS_MONLVD_MASK)

#define PMC0_VLPS_MONHVD_MASK                    (0x20U)
#define PMC0_VLPS_MONHVD_SHIFT                   (5U)
/*! MONHVD - 1.8V HVD HP Monitor Enable
 *  0b0..The monitor is disabled
 *  0b1..The monitor is enabled
 */
#define PMC0_VLPS_MONHVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VLPS_MONHVD_SHIFT)) & PMC0_VLPS_MONHVD_MASK)

#define PMC0_VLPS_FBGHP_MASK                     (0x80U)
#define PMC0_VLPS_FBGHP_SHIFT                    (7U)
/*! FBGHP - Force HP band-gap
 *  0b0..No action
 *  0b1..Turn on the HP band-gap
 */
#define PMC0_VLPS_FBGHP(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_VLPS_FBGHP_SHIFT)) & PMC0_VLPS_FBGHP_MASK)

#define PMC0_VLPS_COREREGVL_MASK                 (0x3F0000U)
#define PMC0_VLPS_COREREGVL_SHIFT                (16U)
/*! COREREGVL - Core Regulator Voltage Level
 *  0b000000..Core Voltage Level is 0.596V
 *  0b000001..Core Voltage Level is 0.607V
 *  0b110001..Core Voltage Level is 1.127V
 *  0b110010..Core Voltage Level is 1.138V
 */
#define PMC0_VLPS_COREREGVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC0_VLPS_COREREGVL_SHIFT)) & PMC0_VLPS_COREREGVL_MASK)

#define PMC0_VLPS_RBBEN_MASK                     (0x10000000U)
#define PMC0_VLPS_RBBEN_SHIFT                    (28U)
/*! RBBEN - Reverse Back Bias Enable
 *  0b0..RBB is disabled
 *  0b1..RBB is enabled
 */
#define PMC0_VLPS_RBBEN(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_VLPS_RBBEN_SHIFT)) & PMC0_VLPS_RBBEN_MASK)
/*! @} */

/*! @name LLS - PMC 0 LLS mode register */
/*! @{ */

#define PMC0_LLS_ARRAYREG_MASK                   (0x1U)
#define PMC0_LLS_ARRAYREG_SHIFT                  (0U)
/*! ARRAYREG - Array Regulator
 *  0b0..LP Regulator is on
 *  0b1..HP Regulator is on
 */
#define PMC0_LLS_ARRAYREG(x)                     (((uint32_t)(((uint32_t)(x)) << PMC0_LLS_ARRAYREG_SHIFT)) & PMC0_LLS_ARRAYREG_MASK)

#define PMC0_LLS_COREREG_MASK                    (0x4U)
#define PMC0_LLS_COREREG_SHIFT                   (2U)
/*! COREREG - Core Regulator
 *  0b0..LP Regulator is on
 *  0b1..HP Regulator is on
 */
#define PMC0_LLS_COREREG(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_LLS_COREREG_SHIFT)) & PMC0_LLS_COREREG_MASK)

#define PMC0_LLS_MONLVD_MASK                     (0x10U)
#define PMC0_LLS_MONLVD_SHIFT                    (4U)
/*! MONLVD - 1.2V LVD HP Monitor Enable
 *  0b0..LP monitor is enabled
 *  0b1..HP monitor is enabled
 */
#define PMC0_LLS_MONLVD(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_LLS_MONLVD_SHIFT)) & PMC0_LLS_MONLVD_MASK)

#define PMC0_LLS_MONHVD_MASK                     (0x20U)
#define PMC0_LLS_MONHVD_SHIFT                    (5U)
/*! MONHVD - 1.8V HVD HP Monitor Enable
 *  0b0..The monitor is disabled
 *  0b1..The monitor is enabled
 */
#define PMC0_LLS_MONHVD(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_LLS_MONHVD_SHIFT)) & PMC0_LLS_MONHVD_MASK)

#define PMC0_LLS_FBGHP_MASK                      (0x80U)
#define PMC0_LLS_FBGHP_SHIFT                     (7U)
/*! FBGHP - Force HP band-gap
 *  0b0..No action
 *  0b1..Turn on the HP band-gap
 */
#define PMC0_LLS_FBGHP(x)                        (((uint32_t)(((uint32_t)(x)) << PMC0_LLS_FBGHP_SHIFT)) & PMC0_LLS_FBGHP_MASK)

#define PMC0_LLS_COREREGVL_MASK                  (0x3F0000U)
#define PMC0_LLS_COREREGVL_SHIFT                 (16U)
/*! COREREGVL - Core Regulator Voltage Level
 *  0b000000..Core Voltage Level is 0.596V
 *  0b000001..Core Voltage Level is 0.607V
 *  0b110001..Core Voltage Level is 1.127V
 *  0b110010..Core Voltage Level is 1.138V
 */
#define PMC0_LLS_COREREGVL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_LLS_COREREGVL_SHIFT)) & PMC0_LLS_COREREGVL_MASK)

#define PMC0_LLS_RBBEN_MASK                      (0x10000000U)
#define PMC0_LLS_RBBEN_SHIFT                     (28U)
/*! RBBEN - Reverse Back Bias Enable
 *  0b0..RBB is disabled
 *  0b1..RBB is enabled
 */
#define PMC0_LLS_RBBEN(x)                        (((uint32_t)(((uint32_t)(x)) << PMC0_LLS_RBBEN_SHIFT)) & PMC0_LLS_RBBEN_MASK)
/*! @} */

/*! @name VLLS - PMC 0 VLLS mode register */
/*! @{ */

#define PMC0_VLLS_ARRAYREG_MASK                  (0x3U)
#define PMC0_VLLS_ARRAYREG_SHIFT                 (0U)
/*! ARRAYREG - Array Regulator
 *  0b00..Regulator is off
 *  0b01..Reserved
 *  0b10..LP Regulator is on
 *  0b11..HP Regulator is on
 */
#define PMC0_VLLS_ARRAYREG(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_VLLS_ARRAYREG_SHIFT)) & PMC0_VLLS_ARRAYREG_MASK)

#define PMC0_VLLS_MONLVD_MASK                    (0x10U)
#define PMC0_VLLS_MONLVD_SHIFT                   (4U)
/*! MONLVD - 1.2V LVD HP Monitor Enable
 *  0b0..LP monitor is enabled
 *  0b1..HP monitor is enabled
 */
#define PMC0_VLLS_MONLVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VLLS_MONLVD_SHIFT)) & PMC0_VLLS_MONLVD_MASK)

#define PMC0_VLLS_MONHVD_MASK                    (0x20U)
#define PMC0_VLLS_MONHVD_SHIFT                   (5U)
/*! MONHVD - 1.8V HVD HP Monitor Enable
 *  0b0..The monitor is disabled
 *  0b1..The monitor is enabled
 */
#define PMC0_VLLS_MONHVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_VLLS_MONHVD_SHIFT)) & PMC0_VLLS_MONHVD_MASK)

#define PMC0_VLLS_FBGHP_MASK                     (0x80U)
#define PMC0_VLLS_FBGHP_SHIFT                    (7U)
/*! FBGHP - Force HP band-gap
 *  0b0..No action
 *  0b1..Turn on the HP band-gap
 */
#define PMC0_VLLS_FBGHP(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_VLLS_FBGHP_SHIFT)) & PMC0_VLLS_FBGHP_MASK)
/*! @} */

/*! @name STATUS - PMC 0 Status register */
/*! @{ */

#define PMC0_STATUS_LVDF_MASK                    (0x1U)
#define PMC0_STATUS_LVDF_SHIFT                   (0U)
/*! LVDF - 1.2V Low-Voltage Detector Flag
 *  0b0..Low-voltage event was not detected by the 1.2V LVD monitor in the PMC 0
 *  0b1..Low-voltage event was detected by the 1.2V LVD monitor in the PMC 0
 */
#define PMC0_STATUS_LVDF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_STATUS_LVDF_SHIFT)) & PMC0_STATUS_LVDF_MASK)

#define PMC0_STATUS_LVDV_MASK                    (0x2U)
#define PMC0_STATUS_LVDV_SHIFT                   (1U)
/*! LVDV - 1.2V Low-Voltage Detector Value
 *  0b0..Low-voltage event was not detected by the 1.2V LVD monitor in the PMC 0
 *  0b1..Low-voltage event was detected by the 1.2V LVD monitor in the PMC 0
 */
#define PMC0_STATUS_LVDV(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_STATUS_LVDV_SHIFT)) & PMC0_STATUS_LVDV_MASK)

#define PMC0_STATUS_HVDF_MASK                    (0x10U)
#define PMC0_STATUS_HVDF_SHIFT                   (4U)
/*! HVDF - 1.8V High-Voltage Detector Flag
 *  0b0..High-voltage event was not detected by the 1.8V HVD monitor in the PMC 0
 *  0b1..High-voltage event was detected by the 1.8V HVD monitor in the PMC 0
 */
#define PMC0_STATUS_HVDF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_STATUS_HVDF_SHIFT)) & PMC0_STATUS_HVDF_MASK)

#define PMC0_STATUS_HVDV_MASK                    (0x20U)
#define PMC0_STATUS_HVDV_SHIFT                   (5U)
/*! HVDV - 1.8V High-Voltage Detector Value
 *  0b0..High-voltage event was not detected by the 1.8V HVD monitor in the PMC 0
 *  0b1..High-voltage event was detected by the 1.8V HVD monitor in the PMC 0
 */
#define PMC0_STATUS_HVDV(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_STATUS_HVDV_SHIFT)) & PMC0_STATUS_HVDV_MASK)

#define PMC0_STATUS_COREVLF_MASK                 (0x100U)
#define PMC0_STATUS_COREVLF_SHIFT                (8U)
/*! COREVLF - Core Regulator Voltage Level Flag
 *  0b0..Core Regulator Voltage Level is stable
 *  0b1..Core Regulator Voltage Level is changing
 */
#define PMC0_STATUS_COREVLF(x)                   (((uint32_t)(((uint32_t)(x)) << PMC0_STATUS_COREVLF_SHIFT)) & PMC0_STATUS_COREVLF_MASK)

#define PMC0_STATUS_SRAMF_MASK                   (0x1000000U)
#define PMC0_STATUS_SRAMF_SHIFT                  (24U)
/*! SRAMF - SRAM Flag
 *  0b0..No change request in the SRAMs.
 *  0b1..A change mode request is being processed in the SRAMs.
 */
#define PMC0_STATUS_SRAMF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC0_STATUS_SRAMF_SHIFT)) & PMC0_STATUS_SRAMF_MASK)

#define PMC0_STATUS_PMC1VSRC_MASK                (0x80000000U)
#define PMC0_STATUS_PMC1VSRC_SHIFT               (31U)
/*! PMC1VSRC - PMC 1 Voltage Source
 *  0b0..The internal LDO supplies the PMC 1, the PMC 1's LVD/HVD sense point is at the supply of the LDO regulator.
 *  0b1..The external PMIC supplies the PMC 1; the PMC 1's LVD/HVD sense point is at the pin connected to the PMIC.
 */
#define PMC0_STATUS_PMC1VSRC(x)                  (((uint32_t)(((uint32_t)(x)) << PMC0_STATUS_PMC1VSRC_SHIFT)) & PMC0_STATUS_PMC1VSRC_MASK)
/*! @} */

/*! @name CTRL - PMC 0 Control register */
/*! @{ */

#define PMC0_CTRL_LVDIE_MASK                     (0x1U)
#define PMC0_CTRL_LVDIE_SHIFT                    (0U)
/*! LVDIE - 1.2V Low-Voltage Detector Interrupt Enable
 *  0b0..1.2V low-voltage detector interrupt is disabled
 *  0b1..1.2V low-voltage detector interrupt is enabled
 */
#define PMC0_CTRL_LVDIE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_LVDIE_SHIFT)) & PMC0_CTRL_LVDIE_MASK)

#define PMC0_CTRL_LVDACK_MASK                    (0x2U)
#define PMC0_CTRL_LVDACK_SHIFT                   (1U)
/*! LVDACK - 1.2V Low-Voltage Detector Acknowledge */
#define PMC0_CTRL_LVDACK(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_LVDACK_SHIFT)) & PMC0_CTRL_LVDACK_MASK)

#define PMC0_CTRL_HVDIE_MASK                     (0x4U)
#define PMC0_CTRL_HVDIE_SHIFT                    (2U)
/*! HVDIE - 1.8V High-Voltage Detector Interrupt Enable
 *  0b0..1.8V high-voltage detector interrupt is disabled
 *  0b1..1.8V high-voltage detector interrupt is enabled
 */
#define PMC0_CTRL_HVDIE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_HVDIE_SHIFT)) & PMC0_CTRL_HVDIE_MASK)

#define PMC0_CTRL_HVDACK_MASK                    (0x8U)
#define PMC0_CTRL_HVDACK_SHIFT                   (3U)
/*! HVDACK - 1.8V High-Voltage Detector Acknowledge */
#define PMC0_CTRL_HVDACK(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_HVDACK_SHIFT)) & PMC0_CTRL_HVDACK_MASK)

#define PMC0_CTRL_LVDRE_MASK                     (0x100U)
#define PMC0_CTRL_LVDRE_SHIFT                    (8U)
/*! LVDRE - 1.2V Low-Voltage Detector Reset Enable
 *  0b0..1.2V low-voltage detector reset is disabled
 *  0b1..1.2V low-voltage detector reset is enabled
 */
#define PMC0_CTRL_LVDRE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_LVDRE_SHIFT)) & PMC0_CTRL_LVDRE_MASK)

#define PMC0_CTRL_HVDRE_MASK                     (0x400U)
#define PMC0_CTRL_HVDRE_SHIFT                    (10U)
/*! HVDRE - 1.8V High-Voltage Detector Reset Enable
 *  0b0..1.8V high-voltage detector reset is disabled
 *  0b1..1.8V high-voltage detector reset is enabled
 */
#define PMC0_CTRL_HVDRE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_HVDRE_SHIFT)) & PMC0_CTRL_HVDRE_MASK)

#define PMC0_CTRL_ISOACK_MASK                    (0x4000U)
#define PMC0_CTRL_ISOACK_SHIFT                   (14U)
/*! ISOACK - Isolation Acknowledge */
#define PMC0_CTRL_ISOACK(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_ISOACK_SHIFT)) & PMC0_CTRL_ISOACK_MASK)

#define PMC0_CTRL_PMC1ON_MASK                    (0x1000000U)
#define PMC0_CTRL_PMC1ON_SHIFT                   (24U)
/*! PMC1ON - PMC 1 Power On */
#define PMC0_CTRL_PMC1ON(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_PMC1ON_SHIFT)) & PMC0_CTRL_PMC1ON_MASK)

#define PMC0_CTRL_LDOOKDIS_MASK                  (0x40000000U)
#define PMC0_CTRL_LDOOKDIS_SHIFT                 (30U)
/*! LDOOKDIS - Disable to Wait LDO OK Signal
 *  0b0..The PMC will wait for the OK signal from LDO Regulator
 *  0b1..The PMC will not wait for the OK signal from LDO Regulator
 */
#define PMC0_CTRL_LDOOKDIS(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_LDOOKDIS_SHIFT)) & PMC0_CTRL_LDOOKDIS_MASK)

#define PMC0_CTRL_LDOEN_MASK                     (0x80000000U)
#define PMC0_CTRL_LDOEN_SHIFT                    (31U)
/*! LDOEN - PMC 1 LDO Regulator Enable
 *  0b0..PMC 1 LDO Regulator is disabled.
 *  0b1..PMC 1 LDO Regulator is enabled.
 */
#define PMC0_CTRL_LDOEN(x)                       (((uint32_t)(((uint32_t)(x)) << PMC0_CTRL_LDOEN_SHIFT)) & PMC0_CTRL_LDOEN_MASK)
/*! @} */

/*! @name ACTRL - PMC 0 Analog Core Control register */
/*! @{ */

#define PMC0_ACTRL_BUFEN_MASK                    (0x1U)
#define PMC0_ACTRL_BUFEN_SHIFT                   (0U)
/*! BUFEN - Buffer Enable
 *  0b0..Analog buffer is disabled.
 *  0b1..Analog buffer is enabled.
 */
#define PMC0_ACTRL_BUFEN(x)                      (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_BUFEN_SHIFT)) & PMC0_ACTRL_BUFEN_MASK)

#define PMC0_ACTRL_BUFFLIP_MASK                  (0x2U)
#define PMC0_ACTRL_BUFFLIP_SHIFT                 (1U)
/*! BUFFLIP - Buffer Flip
 *  0b0..Buffer input not flipped.
 *  0b1..Buffer input flipped.
 */
#define PMC0_ACTRL_BUFFLIP(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_BUFFLIP_SHIFT)) & PMC0_ACTRL_BUFFLIP_MASK)

#define PMC0_ACTRL_BUFSEL_MASK                   (0xCU)
#define PMC0_ACTRL_BUFSEL_SHIFT                  (2U)
/*! BUFSEL - Buffer Selection */
#define PMC0_ACTRL_BUFSEL(x)                     (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_BUFSEL_SHIFT)) & PMC0_ACTRL_BUFSEL_MASK)

#define PMC0_ACTRL_TSENSEN_MASK                  (0x100U)
#define PMC0_ACTRL_TSENSEN_SHIFT                 (8U)
/*! TSENSEN - Temperature Sensor Enable
 *  0b0..The temperature sensor is disabled.
 *  0b1..The temperature sensor is enabled.
 */
#define PMC0_ACTRL_TSENSEN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_TSENSEN_SHIFT)) & PMC0_ACTRL_TSENSEN_MASK)

#define PMC0_ACTRL_TSENSM_MASK                   (0x7000U)
#define PMC0_ACTRL_TSENSM_SHIFT                  (12U)
/*! TSENSM - Temperature Sensor Mode */
#define PMC0_ACTRL_TSENSM(x)                     (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_TSENSM_SHIFT)) & PMC0_ACTRL_TSENSM_MASK)

#define PMC0_ACTRL_SWRBBEN_MASK                  (0x10000U)
#define PMC0_ACTRL_SWRBBEN_SHIFT                 (16U)
/*! SWRBBEN - PMC 1 Switch RBB Enable
 *  0b0..Switch RBB is disabled.
 *  0b1..Switch RBB is enabled.
 */
#define PMC0_ACTRL_SWRBBEN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_SWRBBEN_SHIFT)) & PMC0_ACTRL_SWRBBEN_MASK)

#define PMC0_ACTRL_OSC1KHZSEL_MASK               (0x700000U)
#define PMC0_ACTRL_OSC1KHZSEL_SHIFT              (20U)
/*! OSC1KHZSEL - 1KHz Oscillator Select */
#define PMC0_ACTRL_OSC1KHZSEL(x)                 (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_OSC1KHZSEL_SHIFT)) & PMC0_ACTRL_OSC1KHZSEL_MASK)

#define PMC0_ACTRL_CORECTRL_MASK                 (0xFF000000U)
#define PMC0_ACTRL_CORECTRL_SHIFT                (24U)
/*! CORECTRL - Controls to Analog PMC Core */
#define PMC0_ACTRL_CORECTRL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC0_ACTRL_CORECTRL_SHIFT)) & PMC0_ACTRL_CORECTRL_MASK)
/*! @} */

/*! @name BCTRL - PMC 0 Biasing Control register */
/*! @{ */

#define PMC0_BCTRL_RBBNLEVEL_MASK                (0xFU)
#define PMC0_BCTRL_RBBNLEVEL_SHIFT               (0U)
/*! RBBNLEVEL - RBB N-Well Voltage Level
 *  0b0000..Voltage level at 0.5V.
 *  0b0001..Voltage level at 0.6V.
 *  0b0010..Voltage level at 0.7V.
 *  0b0011..Voltage level at 0.8V.
 *  0b0100..Voltage level at 0.9V.
 *  0b0101..Voltage level at 1.0V.
 *  0b0110..Voltage level at 1.1V.
 *  0b0111..Voltage level at 1.2V.
 *  0b1000..Voltage level at 1.3V.
 */
#define PMC0_BCTRL_RBBNLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC0_BCTRL_RBBNLEVEL_SHIFT)) & PMC0_BCTRL_RBBNLEVEL_MASK)

#define PMC0_BCTRL_RBBPLEVEL_MASK                (0xF00U)
#define PMC0_BCTRL_RBBPLEVEL_SHIFT               (8U)
/*! RBBPLEVEL - RBB P-Well Voltage Level
 *  0b0000..Voltage level at -0.5V.
 *  0b0001..Voltage level at -0.6V.
 *  0b0010..Voltage level at -0.7V.
 *  0b0011..Voltage level at -0.8V.
 *  0b0100..Voltage level at -0.9V.
 *  0b0101..Voltage level at -1.0V.
 *  0b0110..Voltage level at -1.1V.
 *  0b0111..Voltage level at -1.2V.
 *  0b1000..Voltage level at -1.3V.
 */
#define PMC0_BCTRL_RBBPLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC0_BCTRL_RBBPLEVEL_SHIFT)) & PMC0_BCTRL_RBBPLEVEL_MASK)

#define PMC0_BCTRL_RBBPDDIS_MASK                 (0x8000U)
#define PMC0_BCTRL_RBBPDDIS_SHIFT                (15U)
/*! RBBPDDIS - RBB Pull-down Disable
 *  0b0..RBB pull-down is enabled.
 *  0b1..RBB pull-down is disabled.
 */
#define PMC0_BCTRL_RBBPDDIS(x)                   (((uint32_t)(((uint32_t)(x)) << PMC0_BCTRL_RBBPDDIS_SHIFT)) & PMC0_BCTRL_RBBPDDIS_MASK)

#define PMC0_BCTRL_FBBNLEVEL_MASK                (0xF0000U)
#define PMC0_BCTRL_FBBNLEVEL_SHIFT               (16U)
/*! FBBNLEVEL - FBB N-Well Voltage Level
 *  0b0000..No BIAS condition.
 *  0b0001..Voltage level at -50mV.
 *  0b0010..Voltage level at -150mV.
 *  0b0011..Voltage level at -100mV.
 *  0b0100..Voltage level at -350mV.
 *  0b0101..Voltage level at -300mV.
 *  0b0110..Voltage level at -200mV.
 *  0b0111..Voltage level at -250mV.
 */
#define PMC0_BCTRL_FBBNLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC0_BCTRL_FBBNLEVEL_SHIFT)) & PMC0_BCTRL_FBBNLEVEL_MASK)

#define PMC0_BCTRL_FBBPLEVEL_MASK                (0xF000000U)
#define PMC0_BCTRL_FBBPLEVEL_SHIFT               (24U)
/*! FBBPLEVEL - FBB P-Well Voltage Level
 *  0b0000..No BIAS condition.
 *  0b0001..Voltage level at 50mV.
 *  0b0010..Voltage level at 150mV.
 *  0b0011..Voltage level at 100mV.
 *  0b0100..Voltage level at 350mV.
 *  0b0101..Voltage level at 300mV.
 *  0b0110..Voltage level at 200mV.
 *  0b0111..Voltage level at 250mV.
 */
#define PMC0_BCTRL_FBBPLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC0_BCTRL_FBBPLEVEL_SHIFT)) & PMC0_BCTRL_FBBPLEVEL_MASK)
/*! @} */

/*! @name SRAMCTRL_0 - PMC 0 SRAMs Control 0 register */
/*! @{ */

#define PMC0_SRAMCTRL_0_SRAM_PD_MASK             (0x1FU)
#define PMC0_SRAMCTRL_0_SRAM_PD_SHIFT            (0U)
/*! SRAM_PD - PMC 0 SRAM Bank Power Down */
#define PMC0_SRAMCTRL_0_SRAM_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC0_SRAMCTRL_0_SRAM_PD_SHIFT)) & PMC0_SRAMCTRL_0_SRAM_PD_MASK)
/*! @} */

/*! @name SRAMCTRL_1 - PMC 0 SRAMs Control 1 register */
/*! @{ */

#define PMC0_SRAMCTRL_1_SRAM_PDS_MASK            (0x1FU)
#define PMC0_SRAMCTRL_1_SRAM_PDS_SHIFT           (0U)
/*! SRAM_PDS - PMC 0 SRAM Bank Power Down in Stop Modes */
#define PMC0_SRAMCTRL_1_SRAM_PDS(x)              (((uint32_t)(((uint32_t)(x)) << PMC0_SRAMCTRL_1_SRAM_PDS_SHIFT)) & PMC0_SRAMCTRL_1_SRAM_PDS_MASK)
/*! @} */

/*! @name SRAMCTRL_2 - PMC 0 SRAMs Control 2 register */
/*! @{ */

#define PMC0_SRAMCTRL_2_SRAM_STDY_MASK           (0x1FU)
#define PMC0_SRAMCTRL_2_SRAM_STDY_SHIFT          (0U)
/*! SRAM_STDY - PMC 0 SRAM Bank in Standby Mode */
#define PMC0_SRAMCTRL_2_SRAM_STDY(x)             (((uint32_t)(((uint32_t)(x)) << PMC0_SRAMCTRL_2_SRAM_STDY_SHIFT)) & PMC0_SRAMCTRL_2_SRAM_STDY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC0_Register_Masks */


/*!
 * @}
 */ /* end of group PMC0_Peripheral_Access_Layer */


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


#endif  /* PERI_PMC0_H_ */

