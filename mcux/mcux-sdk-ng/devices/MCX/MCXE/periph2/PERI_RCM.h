/*
** ###################################################################
**     Processors:          MCXE246VLH
**                          MCXE246VLL
**                          MCXE246VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250424
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_RCM.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for RCM
 *
 * CMSIS Peripheral Access Layer for RCM
 */

#if !defined(PERI_RCM_H_)
#define PERI_RCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE246VLH) || defined(CPU_MCXE246VLL) || defined(CPU_MCXE246VLQ))
#include "MCXE246_COMMON.h"
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
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Peripheral_Access_Layer RCM Peripheral Access Layer
 * @{
 */

/** RCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __I  uint32_t SRS;                               /**< System Reset Status Register, offset: 0x8 */
  __IO uint32_t RPC;                               /**< Reset Pin Control register, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t SSRS;                              /**< Sticky System Reset Status Register, offset: 0x18 */
  __IO uint32_t SRIE;                              /**< System Reset Interrupt Enable Register, offset: 0x1C */
} RCM_Type;

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define RCM_VERID_FEATURE_MASK                   (0xFFFFU)
#define RCM_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000011..Standard feature set.
 */
#define RCM_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_VERID_FEATURE_SHIFT)) & RCM_VERID_FEATURE_MASK)

#define RCM_VERID_MINOR_MASK                     (0xFF0000U)
#define RCM_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define RCM_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << RCM_VERID_MINOR_SHIFT)) & RCM_VERID_MINOR_MASK)

#define RCM_VERID_MAJOR_MASK                     (0xFF000000U)
#define RCM_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define RCM_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << RCM_VERID_MAJOR_SHIFT)) & RCM_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define RCM_PARAM_EWAKEUP_MASK                   (0x1U)
#define RCM_PARAM_EWAKEUP_SHIFT                  (0U)
/*! EWAKEUP - Existence of SRS[WAKEUP] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_EWAKEUP(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_EWAKEUP_SHIFT)) & RCM_PARAM_EWAKEUP_MASK)

#define RCM_PARAM_ELVD_MASK                      (0x2U)
#define RCM_PARAM_ELVD_SHIFT                     (1U)
/*! ELVD - Existence of SRS[LVD] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ELVD(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ELVD_SHIFT)) & RCM_PARAM_ELVD_MASK)

#define RCM_PARAM_ELOC_MASK                      (0x4U)
#define RCM_PARAM_ELOC_SHIFT                     (2U)
/*! ELOC - Existence of SRS[LOC] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ELOC(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ELOC_SHIFT)) & RCM_PARAM_ELOC_MASK)

#define RCM_PARAM_ELOL_MASK                      (0x8U)
#define RCM_PARAM_ELOL_SHIFT                     (3U)
/*! ELOL - Existence of SRS[LOL] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ELOL(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ELOL_SHIFT)) & RCM_PARAM_ELOL_MASK)

#define RCM_PARAM_ECMU_LOC_MASK                  (0x10U)
#define RCM_PARAM_ECMU_LOC_SHIFT                 (4U)
/*! ECMU_LOC - Existence of SRS[CMU_LOC] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ECMU_LOC(x)                    (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ECMU_LOC_SHIFT)) & RCM_PARAM_ECMU_LOC_MASK)

#define RCM_PARAM_EWDOG_MASK                     (0x20U)
#define RCM_PARAM_EWDOG_SHIFT                    (5U)
/*! EWDOG - Existence of SRS[WDOG] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_EWDOG(x)                       (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_EWDOG_SHIFT)) & RCM_PARAM_EWDOG_MASK)

#define RCM_PARAM_EPIN_MASK                      (0x40U)
#define RCM_PARAM_EPIN_SHIFT                     (6U)
/*! EPIN - Existence of SRS[PIN] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_EPIN(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_EPIN_SHIFT)) & RCM_PARAM_EPIN_MASK)

#define RCM_PARAM_EPOR_MASK                      (0x80U)
#define RCM_PARAM_EPOR_SHIFT                     (7U)
/*! EPOR - Existence of SRS[POR] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_EPOR(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_EPOR_SHIFT)) & RCM_PARAM_EPOR_MASK)

#define RCM_PARAM_EJTAG_MASK                     (0x100U)
#define RCM_PARAM_EJTAG_SHIFT                    (8U)
/*! EJTAG - Existence of SRS[JTAG] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_EJTAG(x)                       (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_EJTAG_SHIFT)) & RCM_PARAM_EJTAG_MASK)

#define RCM_PARAM_ELOCKUP_MASK                   (0x200U)
#define RCM_PARAM_ELOCKUP_SHIFT                  (9U)
/*! ELOCKUP - Existence of SRS[LOCKUP] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ELOCKUP(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ELOCKUP_SHIFT)) & RCM_PARAM_ELOCKUP_MASK)

#define RCM_PARAM_ESW_MASK                       (0x400U)
#define RCM_PARAM_ESW_SHIFT                      (10U)
/*! ESW - Existence of SRS[SW] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ESW(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ESW_SHIFT)) & RCM_PARAM_ESW_MASK)

#define RCM_PARAM_EMDM_AP_MASK                   (0x800U)
#define RCM_PARAM_EMDM_AP_SHIFT                  (11U)
/*! EMDM_AP - Existence of SRS[MDM_AP] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_EMDM_AP(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_EMDM_AP_SHIFT)) & RCM_PARAM_EMDM_AP_MASK)

#define RCM_PARAM_ESACKERR_MASK                  (0x2000U)
#define RCM_PARAM_ESACKERR_SHIFT                 (13U)
/*! ESACKERR - Existence of SRS[SACKERR] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ESACKERR(x)                    (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ESACKERR_SHIFT)) & RCM_PARAM_ESACKERR_MASK)

#define RCM_PARAM_ETAMPER_MASK                   (0x8000U)
#define RCM_PARAM_ETAMPER_SHIFT                  (15U)
/*! ETAMPER - Existence of SRS[TAMPER] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ETAMPER(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ETAMPER_SHIFT)) & RCM_PARAM_ETAMPER_MASK)

#define RCM_PARAM_ECORE1_MASK                    (0x10000U)
#define RCM_PARAM_ECORE1_SHIFT                   (16U)
/*! ECORE1 - Existence of SRS[CORE1] status indication feature
 *  0b0..The feature is not available.
 *  0b1..The feature is available.
 */
#define RCM_PARAM_ECORE1(x)                      (((uint32_t)(((uint32_t)(x)) << RCM_PARAM_ECORE1_SHIFT)) & RCM_PARAM_ECORE1_MASK)
/*! @} */

/*! @name SRS - System Reset Status Register */
/*! @{ */

#define RCM_SRS_LVD_MASK                         (0x2U)
#define RCM_SRS_LVD_SHIFT                        (1U)
/*! LVD - Low-Voltage Detect Reset or High-Voltage Detect Reset
 *  0b0..Reset not caused by LVD trip, HVD trip or POR
 *  0b1..Reset caused by LVD trip, HVD trip or POR
 */
#define RCM_SRS_LVD(x)                           (((uint32_t)(((uint32_t)(x)) << RCM_SRS_LVD_SHIFT)) & RCM_SRS_LVD_MASK)

#define RCM_SRS_LOC_MASK                         (0x4U)
#define RCM_SRS_LOC_SHIFT                        (2U)
/*! LOC - Loss-of-Clock Reset
 *  0b0..Reset not caused by a loss of external clock.
 *  0b1..Reset caused by a loss of external clock.
 */
#define RCM_SRS_LOC(x)                           (((uint32_t)(((uint32_t)(x)) << RCM_SRS_LOC_SHIFT)) & RCM_SRS_LOC_MASK)

#define RCM_SRS_LOL_MASK                         (0x8U)
#define RCM_SRS_LOL_SHIFT                        (3U)
/*! LOL - Loss-of-Lock Reset
 *  0b0..Reset not caused by a loss of lock in the PLL/FLL
 *  0b1..Reset caused by a loss of lock in the PLL/FLL
 */
#define RCM_SRS_LOL(x)                           (((uint32_t)(((uint32_t)(x)) << RCM_SRS_LOL_SHIFT)) & RCM_SRS_LOL_MASK)

#define RCM_SRS_WDOG_MASK                        (0x20U)
#define RCM_SRS_WDOG_SHIFT                       (5U)
/*! WDOG - Watchdog
 *  0b0..Reset not caused by watchdog timeout
 *  0b1..Reset caused by watchdog timeout
 */
#define RCM_SRS_WDOG(x)                          (((uint32_t)(((uint32_t)(x)) << RCM_SRS_WDOG_SHIFT)) & RCM_SRS_WDOG_MASK)

#define RCM_SRS_PIN_MASK                         (0x40U)
#define RCM_SRS_PIN_SHIFT                        (6U)
/*! PIN - External Reset Pin
 *  0b0..Reset not caused by external reset pin
 *  0b1..Reset caused by external reset pin
 */
#define RCM_SRS_PIN(x)                           (((uint32_t)(((uint32_t)(x)) << RCM_SRS_PIN_SHIFT)) & RCM_SRS_PIN_MASK)

#define RCM_SRS_POR_MASK                         (0x80U)
#define RCM_SRS_POR_SHIFT                        (7U)
/*! POR - Power-On Reset
 *  0b0..Reset not caused by POR
 *  0b1..Reset caused by POR
 */
#define RCM_SRS_POR(x)                           (((uint32_t)(((uint32_t)(x)) << RCM_SRS_POR_SHIFT)) & RCM_SRS_POR_MASK)

#define RCM_SRS_JTAG_MASK                        (0x100U)
#define RCM_SRS_JTAG_SHIFT                       (8U)
/*! JTAG - JTAG generated reset
 *  0b0..Reset not caused by JTAG
 *  0b1..Reset caused by JTAG
 */
#define RCM_SRS_JTAG(x)                          (((uint32_t)(((uint32_t)(x)) << RCM_SRS_JTAG_SHIFT)) & RCM_SRS_JTAG_MASK)

#define RCM_SRS_LOCKUP_MASK                      (0x200U)
#define RCM_SRS_LOCKUP_SHIFT                     (9U)
/*! LOCKUP - Core Lockup
 *  0b0..Reset not caused by core LOCKUP event
 *  0b1..Reset caused by core LOCKUP event
 */
#define RCM_SRS_LOCKUP(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_SRS_LOCKUP_SHIFT)) & RCM_SRS_LOCKUP_MASK)

#define RCM_SRS_SW_MASK                          (0x400U)
#define RCM_SRS_SW_SHIFT                         (10U)
/*! SW - Software
 *  0b0..Reset not caused by software setting of SYSRESETREQ bit
 *  0b1..Reset caused by software setting of SYSRESETREQ bit
 */
#define RCM_SRS_SW(x)                            (((uint32_t)(((uint32_t)(x)) << RCM_SRS_SW_SHIFT)) & RCM_SRS_SW_MASK)

#define RCM_SRS_MDM_AP_MASK                      (0x800U)
#define RCM_SRS_MDM_AP_SHIFT                     (11U)
/*! MDM_AP - MDM-AP System Reset Request
 *  0b0..Reset was not caused by host debugger system setting of the System Reset Request bit
 *  0b1..Reset was caused by host debugger system setting of the System Reset Request bit
 */
#define RCM_SRS_MDM_AP(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_SRS_MDM_AP_SHIFT)) & RCM_SRS_MDM_AP_MASK)

#define RCM_SRS_SACKERR_MASK                     (0x2000U)
#define RCM_SRS_SACKERR_SHIFT                    (13U)
/*! SACKERR - Stop Acknowledge Error
 *  0b0..Reset not caused by peripheral failure to acknowledge attempt to enter stop mode
 *  0b1..Reset caused by peripheral failure to acknowledge attempt to enter stop mode
 */
#define RCM_SRS_SACKERR(x)                       (((uint32_t)(((uint32_t)(x)) << RCM_SRS_SACKERR_SHIFT)) & RCM_SRS_SACKERR_MASK)
/*! @} */

/*! @name RPC - Reset Pin Control register */
/*! @{ */

#define RCM_RPC_RSTFLTSRW_MASK                   (0x3U)
#define RCM_RPC_RSTFLTSRW_SHIFT                  (0U)
/*! RSTFLTSRW - Reset Pin Filter Select in Run and Wait Modes
 *  0b00..All filtering disabled
 *  0b01..Bus clock filter enabled for normal operation
 *  0b10..LPO clock filter enabled for normal operation
 *  0b11..Reserved
 */
#define RCM_RPC_RSTFLTSRW(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_RPC_RSTFLTSRW_SHIFT)) & RCM_RPC_RSTFLTSRW_MASK)

#define RCM_RPC_RSTFLTSS_MASK                    (0x4U)
#define RCM_RPC_RSTFLTSS_SHIFT                   (2U)
/*! RSTFLTSS - Reset Pin Filter Select in Stop Mode
 *  0b0..All filtering disabled
 *  0b1..LPO clock filter enabled
 */
#define RCM_RPC_RSTFLTSS(x)                      (((uint32_t)(((uint32_t)(x)) << RCM_RPC_RSTFLTSS_SHIFT)) & RCM_RPC_RSTFLTSS_MASK)

#define RCM_RPC_RSTFLTSEL_MASK                   (0x1F00U)
#define RCM_RPC_RSTFLTSEL_SHIFT                  (8U)
/*! RSTFLTSEL - Reset Pin Filter Bus Clock Select */
#define RCM_RPC_RSTFLTSEL(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_RPC_RSTFLTSEL_SHIFT)) & RCM_RPC_RSTFLTSEL_MASK)
/*! @} */

/*! @name SSRS - Sticky System Reset Status Register */
/*! @{ */

#define RCM_SSRS_SLVD_MASK                       (0x2U)
#define RCM_SSRS_SLVD_SHIFT                      (1U)
/*! SLVD - Sticky Low-Voltage Detect Reset
 *  0b0..Reset not caused by LVD trip or POR
 *  0b1..Reset caused by LVD trip or POR
 */
#define RCM_SSRS_SLVD(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SLVD_SHIFT)) & RCM_SSRS_SLVD_MASK)

#define RCM_SSRS_SLOC_MASK                       (0x4U)
#define RCM_SSRS_SLOC_SHIFT                      (2U)
/*! SLOC - Sticky Loss-of-Clock Reset
 *  0b0..Reset not caused by a loss of external clock.
 *  0b1..Reset caused by a loss of external clock.
 */
#define RCM_SSRS_SLOC(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SLOC_SHIFT)) & RCM_SSRS_SLOC_MASK)

#define RCM_SSRS_SLOL_MASK                       (0x8U)
#define RCM_SSRS_SLOL_SHIFT                      (3U)
/*! SLOL - Sticky Loss-of-Lock Reset
 *  0b0..Reset not caused by a loss of lock in the PLL/FLL
 *  0b1..Reset caused by a loss of lock in the PLL/FLL
 */
#define RCM_SSRS_SLOL(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SLOL_SHIFT)) & RCM_SSRS_SLOL_MASK)

#define RCM_SSRS_SWDOG_MASK                      (0x20U)
#define RCM_SSRS_SWDOG_SHIFT                     (5U)
/*! SWDOG - Sticky Watchdog
 *  0b0..Reset not caused by watchdog timeout
 *  0b1..Reset caused by watchdog timeout
 */
#define RCM_SSRS_SWDOG(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SWDOG_SHIFT)) & RCM_SSRS_SWDOG_MASK)

#define RCM_SSRS_SPIN_MASK                       (0x40U)
#define RCM_SSRS_SPIN_SHIFT                      (6U)
/*! SPIN - Sticky External Reset Pin
 *  0b0..Reset not caused by external reset pin
 *  0b1..Reset caused by external reset pin
 */
#define RCM_SSRS_SPIN(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SPIN_SHIFT)) & RCM_SSRS_SPIN_MASK)

#define RCM_SSRS_SPOR_MASK                       (0x80U)
#define RCM_SSRS_SPOR_SHIFT                      (7U)
/*! SPOR - Sticky Power-On Reset
 *  0b0..Reset not caused by POR
 *  0b1..Reset caused by POR
 */
#define RCM_SSRS_SPOR(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SPOR_SHIFT)) & RCM_SSRS_SPOR_MASK)

#define RCM_SSRS_SJTAG_MASK                      (0x100U)
#define RCM_SSRS_SJTAG_SHIFT                     (8U)
/*! SJTAG - Sticky JTAG generated reset
 *  0b0..Reset not caused by JTAG
 *  0b1..Reset caused by JTAG
 */
#define RCM_SSRS_SJTAG(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SJTAG_SHIFT)) & RCM_SSRS_SJTAG_MASK)

#define RCM_SSRS_SLOCKUP_MASK                    (0x200U)
#define RCM_SSRS_SLOCKUP_SHIFT                   (9U)
/*! SLOCKUP - Sticky Core Lockup
 *  0b0..Reset not caused by core LOCKUP event
 *  0b1..Reset caused by core LOCKUP event
 */
#define RCM_SSRS_SLOCKUP(x)                      (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SLOCKUP_SHIFT)) & RCM_SSRS_SLOCKUP_MASK)

#define RCM_SSRS_SSW_MASK                        (0x400U)
#define RCM_SSRS_SSW_SHIFT                       (10U)
/*! SSW - Sticky Software
 *  0b0..Reset not caused by software setting of SYSRESETREQ bit
 *  0b1..Reset caused by software setting of SYSRESETREQ bit
 */
#define RCM_SSRS_SSW(x)                          (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SSW_SHIFT)) & RCM_SSRS_SSW_MASK)

#define RCM_SSRS_SMDM_AP_MASK                    (0x800U)
#define RCM_SSRS_SMDM_AP_SHIFT                   (11U)
/*! SMDM_AP - Sticky MDM-AP System Reset Request
 *  0b0..Reset was not caused by host debugger system setting of the System Reset Request bit
 *  0b1..Reset was caused by host debugger system setting of the System Reset Request bit
 */
#define RCM_SSRS_SMDM_AP(x)                      (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SMDM_AP_SHIFT)) & RCM_SSRS_SMDM_AP_MASK)

#define RCM_SSRS_SSACKERR_MASK                   (0x2000U)
#define RCM_SSRS_SSACKERR_SHIFT                  (13U)
/*! SSACKERR - Sticky Stop Acknowledge Error
 *  0b0..Reset not caused by peripheral failure to acknowledge attempt to enter stop mode
 *  0b1..Reset caused by peripheral failure to acknowledge attempt to enter stop mode
 */
#define RCM_SSRS_SSACKERR(x)                     (((uint32_t)(((uint32_t)(x)) << RCM_SSRS_SSACKERR_SHIFT)) & RCM_SSRS_SSACKERR_MASK)
/*! @} */

/*! @name SRIE - System Reset Interrupt Enable Register */
/*! @{ */

#define RCM_SRIE_DELAY_MASK                      (0x3U)
#define RCM_SRIE_DELAY_SHIFT                     (0U)
/*! DELAY - Reset Delay Time
 *  0b00..10 LPO cycles
 *  0b01..34 LPO cycles
 *  0b10..130 LPO cycles
 *  0b11..514 LPO cycles
 */
#define RCM_SRIE_DELAY(x)                        (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_DELAY_SHIFT)) & RCM_SRIE_DELAY_MASK)

#define RCM_SRIE_LOC_MASK                        (0x4U)
#define RCM_SRIE_LOC_SHIFT                       (2U)
/*! LOC - Loss-of-Clock Interrupt
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_LOC(x)                          (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_LOC_SHIFT)) & RCM_SRIE_LOC_MASK)

#define RCM_SRIE_LOL_MASK                        (0x8U)
#define RCM_SRIE_LOL_SHIFT                       (3U)
/*! LOL - Loss-of-Lock Interrupt
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_LOL(x)                          (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_LOL_SHIFT)) & RCM_SRIE_LOL_MASK)

#define RCM_SRIE_WDOG_MASK                       (0x20U)
#define RCM_SRIE_WDOG_SHIFT                      (5U)
/*! WDOG - Watchdog Interrupt
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_WDOG(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_WDOG_SHIFT)) & RCM_SRIE_WDOG_MASK)

#define RCM_SRIE_PIN_MASK                        (0x40U)
#define RCM_SRIE_PIN_SHIFT                       (6U)
/*! PIN - External Reset Pin Interrupt
 *  0b0..Reset not caused by external reset pin
 *  0b1..Reset caused by external reset pin
 */
#define RCM_SRIE_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_PIN_SHIFT)) & RCM_SRIE_PIN_MASK)

#define RCM_SRIE_GIE_MASK                        (0x80U)
#define RCM_SRIE_GIE_SHIFT                       (7U)
/*! GIE - Global Interrupt Enable
 *  0b0..All interrupt sources disabled.
 *  0b1..All interrupt sources enabled. Note that the individual interrupt-enable bits still need to be set to generate interrupts.
 */
#define RCM_SRIE_GIE(x)                          (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_GIE_SHIFT)) & RCM_SRIE_GIE_MASK)

#define RCM_SRIE_JTAG_MASK                       (0x100U)
#define RCM_SRIE_JTAG_SHIFT                      (8U)
/*! JTAG - JTAG generated reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_JTAG(x)                         (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_JTAG_SHIFT)) & RCM_SRIE_JTAG_MASK)

#define RCM_SRIE_LOCKUP_MASK                     (0x200U)
#define RCM_SRIE_LOCKUP_SHIFT                    (9U)
/*! LOCKUP - Core Lockup Interrupt
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_LOCKUP_SHIFT)) & RCM_SRIE_LOCKUP_MASK)

#define RCM_SRIE_SW_MASK                         (0x400U)
#define RCM_SRIE_SW_SHIFT                        (10U)
/*! SW - Software Interrupt
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_SW(x)                           (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_SW_SHIFT)) & RCM_SRIE_SW_MASK)

#define RCM_SRIE_MDM_AP_MASK                     (0x800U)
#define RCM_SRIE_MDM_AP_SHIFT                    (11U)
/*! MDM_AP - MDM-AP System Reset Request
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_MDM_AP(x)                       (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_MDM_AP_SHIFT)) & RCM_SRIE_MDM_AP_MASK)

#define RCM_SRIE_SACKERR_MASK                    (0x2000U)
#define RCM_SRIE_SACKERR_SHIFT                   (13U)
/*! SACKERR - Stop Acknowledge Error Interrupt
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define RCM_SRIE_SACKERR(x)                      (((uint32_t)(((uint32_t)(x)) << RCM_SRIE_SACKERR_SHIFT)) & RCM_SRIE_SACKERR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/*!
 * @}
 */ /* end of group RCM_Peripheral_Access_Layer */


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


#endif  /* PERI_RCM_H_ */

