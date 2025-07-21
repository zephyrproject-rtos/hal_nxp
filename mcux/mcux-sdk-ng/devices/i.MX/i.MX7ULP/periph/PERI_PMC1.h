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
**         CMSIS Peripheral Access Layer for PMC1
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
 * @file PERI_PMC1.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC1
 *
 * CMSIS Peripheral Access Layer for PMC1
 */

#if !defined(PERI_PMC1_H_)
#define PERI_PMC1_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PMC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC1_Peripheral_Access_Layer PMC1 Peripheral Access Layer
 * @{
 */

/** PMC1 - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< PMC 1 Version register, offset: 0x0 */
  __IO uint32_t HSRUN;                             /**< PMC 1 HSRUN mode register, offset: 0x4 */
  __IO uint32_t RUN;                               /**< PMC 1 RUN mode register, offset: 0x8 */
  __IO uint32_t VLPR;                              /**< PMC 1 VLPR mode register, offset: 0xC */
  __IO uint32_t STOP;                              /**< PMC 1 STOP mode register, offset: 0x10 */
  __IO uint32_t VLPS;                              /**< PMC 1 VLPS mode register, offset: 0x14 */
  __IO uint32_t LLS;                               /**< PMC 1 LLS mode register, offset: 0x18 */
  __IO uint32_t VLLS;                              /**< PMC 1 VLLS mode register, offset: 0x1C */
  __I  uint32_t STATUS;                            /**< PMC 1 Status register, offset: 0x20 */
  __IO uint32_t CTRL;                              /**< PMC 1 Control register, offset: 0x24 */
       uint8_t RESERVED_0[12];
  __IO uint32_t BCTRL;                             /**< PMC 1 Biasing Control register, offset: 0x34 */
       uint8_t RESERVED_1[12];
  __IO uint32_t SRAMCTRL;                          /**< PMC 1 SRAMs Control register, offset: 0x44 */
} PMC1_Type;

/* ----------------------------------------------------------------------------
   -- PMC1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC1_Register_Masks PMC1 Register Masks
 * @{
 */

/*! @name VERID - PMC 1 Version register */
/*! @{ */

#define PMC1_VERID_FEATURE_MASK                  (0xFFFFU)
#define PMC1_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented
 */
#define PMC1_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC1_VERID_FEATURE_SHIFT)) & PMC1_VERID_FEATURE_MASK)

#define PMC1_VERID_MINOR_MASK                    (0xFF0000U)
#define PMC1_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define PMC1_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VERID_MINOR_SHIFT)) & PMC1_VERID_MINOR_MASK)

#define PMC1_VERID_MAJOR_MASK                    (0xFF000000U)
#define PMC1_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define PMC1_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VERID_MAJOR_SHIFT)) & PMC1_VERID_MAJOR_MASK)
/*! @} */

/*! @name HSRUN - PMC 1 HSRUN mode register */
/*! @{ */

#define PMC1_HSRUN_LDOVL_MASK                    (0x3F0000U)
#define PMC1_HSRUN_LDOVL_SHIFT                   (16U)
/*! LDOVL - LDO Regulator Voltage Level
 *  0b000000..LDO Voltage Level is 0.60V
 *  0b000001..LDO Voltage Level is 0.61V
 *  0b110001..LDO Voltage Level is 1.09V
 *  0b110010..LDO Voltage Level is 1.10V
 */
#define PMC1_HSRUN_LDOVL(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_HSRUN_LDOVL_SHIFT)) & PMC1_HSRUN_LDOVL_MASK)

#define PMC1_HSRUN_FBBEN_MASK                    (0x1000000U)
#define PMC1_HSRUN_FBBEN_SHIFT                   (24U)
/*! FBBEN - Forward Back Bias Enable
 *  0b0..FBB is disabled
 *  0b1..FBB is enabled
 */
#define PMC1_HSRUN_FBBEN(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_HSRUN_FBBEN_SHIFT)) & PMC1_HSRUN_FBBEN_MASK)
/*! @} */

/*! @name RUN - PMC 1 RUN mode register */
/*! @{ */

#define PMC1_RUN_LDOVL_MASK                      (0x3F0000U)
#define PMC1_RUN_LDOVL_SHIFT                     (16U)
/*! LDOVL - LDO Regulator Voltage Level
 *  0b000000..LDO Voltage Level is 0.60V
 *  0b000001..LDO Voltage Level is 0.61V
 *  0b110001..LDO Voltage Level is 1.09V
 *  0b110010..LDO Voltage Level is 1.10V
 */
#define PMC1_RUN_LDOVL(x)                        (((uint32_t)(((uint32_t)(x)) << PMC1_RUN_LDOVL_SHIFT)) & PMC1_RUN_LDOVL_MASK)
/*! @} */

/*! @name VLPR - PMC 1 VLPR mode register */
/*! @{ */

#define PMC1_VLPR_LDOM_MASK                      (0x1U)
#define PMC1_VLPR_LDOM_SHIFT                     (0U)
/*! LDOM - LDO Regulator Mode
 *  0b0..Linear LDO LP Regulator is enabled.
 *  0b1..Linear LDO HP Regulator is enabled.
 */
#define PMC1_VLPR_LDOM(x)                        (((uint32_t)(((uint32_t)(x)) << PMC1_VLPR_LDOM_SHIFT)) & PMC1_VLPR_LDOM_MASK)

#define PMC1_VLPR_MONLVD_MASK                    (0x10U)
#define PMC1_VLPR_MONLVD_SHIFT                   (4U)
/*! MONLVD - Low-Voltage Detector
 *  0b0..LP monitor is enabled.
 *  0b1..HP monitor is enabled.
 */
#define PMC1_VLPR_MONLVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VLPR_MONLVD_SHIFT)) & PMC1_VLPR_MONLVD_MASK)

#define PMC1_VLPR_MONHVD_MASK                    (0x20U)
#define PMC1_VLPR_MONHVD_SHIFT                   (5U)
/*! MONHVD - 1.2V HP High-Voltage Detector
 *  0b0..The monitor is disabled.
 *  0b1..The monitor is enabled.
 */
#define PMC1_VLPR_MONHVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VLPR_MONHVD_SHIFT)) & PMC1_VLPR_MONHVD_MASK)

#define PMC1_VLPR_LDOVL_MASK                     (0x3F0000U)
#define PMC1_VLPR_LDOVL_SHIFT                    (16U)
/*! LDOVL - LDO Regulator Voltage Level
 *  0b000000..LDO Voltage Level is 0.60V
 *  0b000001..LDO Voltage Level is 0.61V
 *  0b110001..LDO Voltage Level is 1.09V
 *  0b110010..LDO Voltage Level is 1.10V
 */
#define PMC1_VLPR_LDOVL(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_VLPR_LDOVL_SHIFT)) & PMC1_VLPR_LDOVL_MASK)
/*! @} */

/*! @name STOP - PMC 1 STOP mode register */
/*! @{ */

#define PMC1_STOP_LDOVL_MASK                     (0x3F0000U)
#define PMC1_STOP_LDOVL_SHIFT                    (16U)
/*! LDOVL - LDO Regulator Voltage Level
 *  0b000000..LDO Voltage Level is 0.60V
 *  0b000001..LDO Voltage Level is 0.61V
 *  0b110001..LDO Voltage Level is 1.09V
 *  0b110010..LDO Voltage Level is 1.10V
 */
#define PMC1_STOP_LDOVL(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_STOP_LDOVL_SHIFT)) & PMC1_STOP_LDOVL_MASK)
/*! @} */

/*! @name VLPS - PMC 1 VLPS mode register */
/*! @{ */

#define PMC1_VLPS_LDOM_MASK                      (0x1U)
#define PMC1_VLPS_LDOM_SHIFT                     (0U)
/*! LDOM - LDO Regulator Mode
 *  0b0..Linear LDO LP Regulator is enabled.
 *  0b1..Linear LDO HP Regulator is enabled.
 */
#define PMC1_VLPS_LDOM(x)                        (((uint32_t)(((uint32_t)(x)) << PMC1_VLPS_LDOM_SHIFT)) & PMC1_VLPS_LDOM_MASK)

#define PMC1_VLPS_MONLVD_MASK                    (0x10U)
#define PMC1_VLPS_MONLVD_SHIFT                   (4U)
/*! MONLVD - Low-Voltage Detector
 *  0b0..LP monitor is enabled.
 *  0b1..HP monitor is enabled.
 */
#define PMC1_VLPS_MONLVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VLPS_MONLVD_SHIFT)) & PMC1_VLPS_MONLVD_MASK)

#define PMC1_VLPS_MONHVD_MASK                    (0x20U)
#define PMC1_VLPS_MONHVD_SHIFT                   (5U)
/*! MONHVD - 1.2V HP High-Voltage Detector
 *  0b0..The monitor is disabled.
 *  0b1..The monitor is enabled.
 */
#define PMC1_VLPS_MONHVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VLPS_MONHVD_SHIFT)) & PMC1_VLPS_MONHVD_MASK)

#define PMC1_VLPS_LDOVL_MASK                     (0x3F0000U)
#define PMC1_VLPS_LDOVL_SHIFT                    (16U)
/*! LDOVL - LDO Regulator Voltage Level
 *  0b000000..LDO Voltage Level is 0.60V
 *  0b000001..LDO Voltage Level is 0.61V
 *  0b110001..LDO Voltage Level is 1.09V
 *  0b110010..LDO Voltage Level is 1.10V
 */
#define PMC1_VLPS_LDOVL(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_VLPS_LDOVL_SHIFT)) & PMC1_VLPS_LDOVL_MASK)

#define PMC1_VLPS_RBBEN_MASK                     (0x10000000U)
#define PMC1_VLPS_RBBEN_SHIFT                    (28U)
/*! RBBEN - Reverse Back Bias Enable
 *  0b0..RBB is disabled
 *  0b1..RBB is enabled
 */
#define PMC1_VLPS_RBBEN(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_VLPS_RBBEN_SHIFT)) & PMC1_VLPS_RBBEN_MASK)
/*! @} */

/*! @name LLS - PMC 1 LLS mode register */
/*! @{ */

#define PMC1_LLS_LDOM_MASK                       (0x1U)
#define PMC1_LLS_LDOM_SHIFT                      (0U)
/*! LDOM - LDO Regulator Mode
 *  0b0..Linear LDO LP Regulator is enabled.
 *  0b1..Linear LDO HP Regulator is enabled.
 */
#define PMC1_LLS_LDOM(x)                         (((uint32_t)(((uint32_t)(x)) << PMC1_LLS_LDOM_SHIFT)) & PMC1_LLS_LDOM_MASK)

#define PMC1_LLS_MONLVD_MASK                     (0x10U)
#define PMC1_LLS_MONLVD_SHIFT                    (4U)
/*! MONLVD - Low-Voltage Detector
 *  0b0..LP monitor is enabled.
 *  0b1..HP monitor is enabled.
 */
#define PMC1_LLS_MONLVD(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_LLS_MONLVD_SHIFT)) & PMC1_LLS_MONLVD_MASK)

#define PMC1_LLS_MONHVD_MASK                     (0x20U)
#define PMC1_LLS_MONHVD_SHIFT                    (5U)
/*! MONHVD - 1.2V HP High-Voltage Detector
 *  0b0..The monitor is disabled.
 *  0b1..The monitor is enabled.
 */
#define PMC1_LLS_MONHVD(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_LLS_MONHVD_SHIFT)) & PMC1_LLS_MONHVD_MASK)

#define PMC1_LLS_LDOVL_MASK                      (0x3F0000U)
#define PMC1_LLS_LDOVL_SHIFT                     (16U)
/*! LDOVL - Linear LDO Regulator Voltage Level
 *  0b000000..LDO Voltage Level is 0.60V
 *  0b000001..LDO Voltage Level is 0.61V
 *  0b110001..LDO Voltage Level is 1.09V
 *  0b110010..LDO Voltage Level is 1.10V
 */
#define PMC1_LLS_LDOVL(x)                        (((uint32_t)(((uint32_t)(x)) << PMC1_LLS_LDOVL_SHIFT)) & PMC1_LLS_LDOVL_MASK)

#define PMC1_LLS_RBBEN_MASK                      (0x10000000U)
#define PMC1_LLS_RBBEN_SHIFT                     (28U)
/*! RBBEN - Reverse Back Bias Enable
 *  0b0..RBB is disabled
 *  0b1..RBB is enabled
 */
#define PMC1_LLS_RBBEN(x)                        (((uint32_t)(((uint32_t)(x)) << PMC1_LLS_RBBEN_SHIFT)) & PMC1_LLS_RBBEN_MASK)
/*! @} */

/*! @name VLLS - PMC 1 VLLS mode register */
/*! @{ */

#define PMC1_VLLS_LDOM_MASK                      (0x1U)
#define PMC1_VLLS_LDOM_SHIFT                     (0U)
/*! LDOM - LDO Regulator Mode
 *  0b0..Linear LDO LP Regulator is enabled.
 *  0b1..Linear LDO HP Regulator is enabled.
 */
#define PMC1_VLLS_LDOM(x)                        (((uint32_t)(((uint32_t)(x)) << PMC1_VLLS_LDOM_SHIFT)) & PMC1_VLLS_LDOM_MASK)

#define PMC1_VLLS_MONLVD_MASK                    (0x10U)
#define PMC1_VLLS_MONLVD_SHIFT                   (4U)
/*! MONLVD - Low-Voltage Detector
 *  0b0..LP monitor is enabled.
 *  0b1..HP monitor is enabled.
 */
#define PMC1_VLLS_MONLVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VLLS_MONLVD_SHIFT)) & PMC1_VLLS_MONLVD_MASK)

#define PMC1_VLLS_MONHVD_MASK                    (0x20U)
#define PMC1_VLLS_MONHVD_SHIFT                   (5U)
/*! MONHVD - 1.2V HP High-Voltage Detector
 *  0b0..The monitor is disabled.
 *  0b1..The monitor is enabled.
 */
#define PMC1_VLLS_MONHVD(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_VLLS_MONHVD_SHIFT)) & PMC1_VLLS_MONHVD_MASK)
/*! @} */

/*! @name STATUS - PMC 1 Status register */
/*! @{ */

#define PMC1_STATUS_LVDF_MASK                    (0x1U)
#define PMC1_STATUS_LVDF_SHIFT                   (0U)
/*! LVDF - 1.2V Low-Voltage Detector Flag
 *  0b0..Low-voltage event was not detected by the 1.2V LVD monitor in the PMC 1
 *  0b1..Low-voltage event was detected by the 1.2V LVD monitor in the PMC 1
 */
#define PMC1_STATUS_LVDF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_STATUS_LVDF_SHIFT)) & PMC1_STATUS_LVDF_MASK)

#define PMC1_STATUS_LVDV_MASK                    (0x2U)
#define PMC1_STATUS_LVDV_SHIFT                   (1U)
/*! LVDV - 1.2V Low-Voltage Detector Value
 *  0b0..Low-voltage event was not detected by the 1.2V LVD monitor in the PMC 1
 *  0b1..Low-voltage event was detected by the 1.2V LVD monitor in the PMC 1
 */
#define PMC1_STATUS_LVDV(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_STATUS_LVDV_SHIFT)) & PMC1_STATUS_LVDV_MASK)

#define PMC1_STATUS_HVDF_MASK                    (0x10U)
#define PMC1_STATUS_HVDF_SHIFT                   (4U)
/*! HVDF - 1.2V High-Voltage Detector Flag
 *  0b0..High-voltage event was not detected by the 1.2V HVD monitor in PMC 1
 *  0b1..High-voltage event was detected by the 1.2V HVD monitor in PMC 1
 */
#define PMC1_STATUS_HVDF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_STATUS_HVDF_SHIFT)) & PMC1_STATUS_HVDF_MASK)

#define PMC1_STATUS_HVDV_MASK                    (0x20U)
#define PMC1_STATUS_HVDV_SHIFT                   (5U)
/*! HVDV - 1.2V High-Voltage Detector Value
 *  0b0..High-voltage event was not detected by the 1.2V HVD monitor in PMC 1
 *  0b1..High-voltage event was detected by the 1.2V HVD monitor in PMC 1
 */
#define PMC1_STATUS_HVDV(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_STATUS_HVDV_SHIFT)) & PMC1_STATUS_HVDV_MASK)

#define PMC1_STATUS_LDOVLF_MASK                  (0x100U)
#define PMC1_STATUS_LDOVLF_SHIFT                 (8U)
/*! LDOVLF - LDO Voltage Level Flag
 *  0b0..LDO Voltage Level is stable
 *  0b1..LDO Voltage Level is changing
 */
#define PMC1_STATUS_LDOVLF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC1_STATUS_LDOVLF_SHIFT)) & PMC1_STATUS_LDOVLF_MASK)

#define PMC1_STATUS_SRAMF_MASK                   (0x1000000U)
#define PMC1_STATUS_SRAMF_SHIFT                  (24U)
/*! SRAMF - SRAM Flag
 *  0b0..No change request in the SRAMs.
 *  0b1..A change mode request is being processed in the SRAMs.
 */
#define PMC1_STATUS_SRAMF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC1_STATUS_SRAMF_SHIFT)) & PMC1_STATUS_SRAMF_MASK)
/*! @} */

/*! @name CTRL - PMC 1 Control register */
/*! @{ */

#define PMC1_CTRL_LVDIE_MASK                     (0x1U)
#define PMC1_CTRL_LVDIE_SHIFT                    (0U)
/*! LVDIE - Low-Voltage Detector Interrupt Enable
 *  0b0..Low-voltage detector interrupt is disabled
 *  0b1..Low-voltage detector interrupt is enabled
 */
#define PMC1_CTRL_LVDIE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_CTRL_LVDIE_SHIFT)) & PMC1_CTRL_LVDIE_MASK)

#define PMC1_CTRL_LVDACK_MASK                    (0x2U)
#define PMC1_CTRL_LVDACK_SHIFT                   (1U)
/*! LVDACK - 1.2V Low-Voltage Detector Acknowledge */
#define PMC1_CTRL_LVDACK(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_CTRL_LVDACK_SHIFT)) & PMC1_CTRL_LVDACK_MASK)

#define PMC1_CTRL_HVDIE_MASK                     (0x4U)
#define PMC1_CTRL_HVDIE_SHIFT                    (2U)
/*! HVDIE - 1.2V High-Voltage Detector Interrupt Enable
 *  0b0..1.2V high-voltage detector interrupt is disabled
 *  0b1..1.2V high-voltage detector interrupt is enabled
 */
#define PMC1_CTRL_HVDIE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_CTRL_HVDIE_SHIFT)) & PMC1_CTRL_HVDIE_MASK)

#define PMC1_CTRL_HVDACK_MASK                    (0x8U)
#define PMC1_CTRL_HVDACK_SHIFT                   (3U)
/*! HVDACK - 1.2V High-Voltage Detector Acknowledge */
#define PMC1_CTRL_HVDACK(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_CTRL_HVDACK_SHIFT)) & PMC1_CTRL_HVDACK_MASK)

#define PMC1_CTRL_LVDRE_MASK                     (0x100U)
#define PMC1_CTRL_LVDRE_SHIFT                    (8U)
/*! LVDRE - Low-Voltage Detector Reset Enable
 *  0b0..Low-voltage detector reset is disabled
 *  0b1..Low-voltage detector reset is enabled
 */
#define PMC1_CTRL_LVDRE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_CTRL_LVDRE_SHIFT)) & PMC1_CTRL_LVDRE_MASK)

#define PMC1_CTRL_HVDRE_MASK                     (0x400U)
#define PMC1_CTRL_HVDRE_SHIFT                    (10U)
/*! HVDRE - 1.2V High-Voltage Detector Reset Enable
 *  0b0..1.2V high-voltage detector reset is disabled
 *  0b1..1.2V high-voltage detector reset is enabled
 */
#define PMC1_CTRL_HVDRE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC1_CTRL_HVDRE_SHIFT)) & PMC1_CTRL_HVDRE_MASK)

#define PMC1_CTRL_ISOACK_MASK                    (0x4000U)
#define PMC1_CTRL_ISOACK_SHIFT                   (14U)
/*! ISOACK - Isolation Acknowledge */
#define PMC1_CTRL_ISOACK(x)                      (((uint32_t)(((uint32_t)(x)) << PMC1_CTRL_ISOACK_SHIFT)) & PMC1_CTRL_ISOACK_MASK)
/*! @} */

/*! @name BCTRL - PMC 1 Biasing Control register */
/*! @{ */

#define PMC1_BCTRL_RBBNLEVEL_MASK                (0xFU)
#define PMC1_BCTRL_RBBNLEVEL_SHIFT               (0U)
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
#define PMC1_BCTRL_RBBNLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC1_BCTRL_RBBNLEVEL_SHIFT)) & PMC1_BCTRL_RBBNLEVEL_MASK)

#define PMC1_BCTRL_RBBPLEVEL_MASK                (0xF00U)
#define PMC1_BCTRL_RBBPLEVEL_SHIFT               (8U)
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
#define PMC1_BCTRL_RBBPLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC1_BCTRL_RBBPLEVEL_SHIFT)) & PMC1_BCTRL_RBBPLEVEL_MASK)

#define PMC1_BCTRL_FBBNLEVEL_MASK                (0xF0000U)
#define PMC1_BCTRL_FBBNLEVEL_SHIFT               (16U)
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
#define PMC1_BCTRL_FBBNLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC1_BCTRL_FBBNLEVEL_SHIFT)) & PMC1_BCTRL_FBBNLEVEL_MASK)

#define PMC1_BCTRL_FBBPLEVEL_MASK                (0xF000000U)
#define PMC1_BCTRL_FBBPLEVEL_SHIFT               (24U)
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
#define PMC1_BCTRL_FBBPLEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC1_BCTRL_FBBPLEVEL_SHIFT)) & PMC1_BCTRL_FBBPLEVEL_MASK)
/*! @} */

/*! @name SRAMCTRL - PMC 1 SRAMs Control register */
/*! @{ */

#define PMC1_SRAMCTRL_SRAM_STDY_MASK             (0xFFU)
#define PMC1_SRAMCTRL_SRAM_STDY_SHIFT            (0U)
/*! SRAM_STDY - PMC 1 SRAM Bank in Standby Mode */
#define PMC1_SRAMCTRL_SRAM_STDY(x)               (((uint32_t)(((uint32_t)(x)) << PMC1_SRAMCTRL_SRAM_STDY_SHIFT)) & PMC1_SRAMCTRL_SRAM_STDY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC1_Register_Masks */


/*!
 * @}
 */ /* end of group PMC1_Peripheral_Access_Layer */


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


#endif  /* PERI_PMC1_H_ */

