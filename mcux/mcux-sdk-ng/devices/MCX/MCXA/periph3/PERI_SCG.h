/*
** ###################################################################
**     Processors:          MCXA343VFM
**                          MCXA343VLF
**                          MCXA343VLH
**                          MCXA343VLL
**                          MCXA344VFM
**                          MCXA344VLF
**                          MCXA344VLH
**                          MCXA344VLL
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250806
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SCG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SCG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SCG
 *
 * CMSIS Peripheral Access Layer for SCG
 */

#if !defined(PERI_SCG_H_)
#define PERI_SCG_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA343VFM) || defined(CPU_MCXA343VLF) || defined(CPU_MCXA343VLH) || defined(CPU_MCXA343VLL))
#include "MCXA343_COMMON.h"
#elif (defined(CPU_MCXA344VFM) || defined(CPU_MCXA344VLF) || defined(CPU_MCXA344VLH) || defined(CPU_MCXA344VLL))
#include "MCXA344_COMMON.h"
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
   -- SCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Peripheral_Access_Layer SCG Peripheral Access Layer
 * @{
 */

/** SCG - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t TRIM_LOCK;                         /**< Trim Lock, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __I  uint32_t CSR;                               /**< Clock Status, offset: 0x10 */
  __IO uint32_t RCCR;                              /**< Run Clock Control, offset: 0x14 */
       uint8_t RESERVED_1[232];
  __IO uint32_t SOSCCSR;                           /**< SOSC Control Status, offset: 0x100 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SOSCCFG;                           /**< SOSC Configuration, offset: 0x108 */
       uint8_t RESERVED_3[244];
  __IO uint32_t SIRCCSR;                           /**< SIRC Control Status, offset: 0x200 */
       uint8_t RESERVED_4[8];
  __IO uint32_t SIRCTCFG;                          /**< SIRC Trim Configuration, offset: 0x20C */
  __IO uint32_t SIRCTRIM;                          /**< SIRC Trim, offset: 0x210 */
       uint8_t RESERVED_5[4];
  __IO uint32_t SIRCSTAT;                          /**< SIRC Auto-trimming Status, offset: 0x218 */
       uint8_t RESERVED_6[228];
  __IO uint32_t FIRCCSR;                           /**< FIRC Control Status, offset: 0x300 */
       uint8_t RESERVED_7[4];
  __IO uint32_t FIRCCFG;                           /**< FIRC Configuration, offset: 0x308 */
       uint8_t RESERVED_8[4];
  __IO uint32_t FIRCTRIM;                          /**< FIRC Trim, offset: 0x310 */
       uint8_t RESERVED_9[236];
  __IO uint32_t ROSCCSR;                           /**< ROSC Control Status, offset: 0x400 */
       uint8_t RESERVED_10[1020];
  __IO uint32_t LDOCSR;                            /**< LDO Control and Status, offset: 0x800 */
} SCG_Type;

/* ----------------------------------------------------------------------------
   -- SCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Masks SCG Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define SCG_VERID_VERSION_MASK                   (0xFFFFFFFFU)
#define SCG_VERID_VERSION_SHIFT                  (0U)
/*! VERSION - SCG Version Number */
#define SCG_VERID_VERSION(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_VERID_VERSION_SHIFT)) & SCG_VERID_VERSION_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define SCG_PARAM_SOSCCLKPRES_MASK               (0x2U)
#define SCG_PARAM_SOSCCLKPRES_SHIFT              (1U)
/*! SOSCCLKPRES - SOSC Clock Present
 *  0b0..SOSC clock source is not present
 *  0b1..SOSC clock source is present
 */
#define SCG_PARAM_SOSCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_SOSCCLKPRES_SHIFT)) & SCG_PARAM_SOSCCLKPRES_MASK)

#define SCG_PARAM_SIRCCLKPRES_MASK               (0x4U)
#define SCG_PARAM_SIRCCLKPRES_SHIFT              (2U)
/*! SIRCCLKPRES - SIRC Clock Present
 *  0b0..SIRC clock source is not present
 *  0b1..SIRC clock source is present
 */
#define SCG_PARAM_SIRCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_SIRCCLKPRES_SHIFT)) & SCG_PARAM_SIRCCLKPRES_MASK)

#define SCG_PARAM_FIRCCLKPRES_MASK               (0x8U)
#define SCG_PARAM_FIRCCLKPRES_SHIFT              (3U)
/*! FIRCCLKPRES - FIRC Clock Present
 *  0b0..FIRC clock source is not present
 *  0b1..FIRC clock source is present
 */
#define SCG_PARAM_FIRCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_FIRCCLKPRES_SHIFT)) & SCG_PARAM_FIRCCLKPRES_MASK)

#define SCG_PARAM_ROSCCLKPRES_MASK               (0x10U)
#define SCG_PARAM_ROSCCLKPRES_SHIFT              (4U)
/*! ROSCCLKPRES - ROSC Clock Present
 *  0b0..ROSC clock source is not present
 *  0b1..ROSC clock source is present
 */
#define SCG_PARAM_ROSCCLKPRES(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_ROSCCLKPRES_SHIFT)) & SCG_PARAM_ROSCCLKPRES_MASK)
/*! @} */

/*! @name TRIM_LOCK - Trim Lock */
/*! @{ */

#define SCG_TRIM_LOCK_TRIM_UNLOCK_MASK           (0x1U)
#define SCG_TRIM_LOCK_TRIM_UNLOCK_SHIFT          (0U)
/*! TRIM_UNLOCK - TRIM_UNLOCK
 *  0b0..SCG Trim Registers locked and not writable.
 *  0b1..SCG Trim registers unlocked and writable.
 */
#define SCG_TRIM_LOCK_TRIM_UNLOCK(x)             (((uint32_t)(((uint32_t)(x)) << SCG_TRIM_LOCK_TRIM_UNLOCK_SHIFT)) & SCG_TRIM_LOCK_TRIM_UNLOCK_MASK)

#define SCG_TRIM_LOCK_IFR_DISABLE_MASK           (0x2U)
#define SCG_TRIM_LOCK_IFR_DISABLE_SHIFT          (1U)
/*! IFR_DISABLE - IFR_DISABLE
 *  0b0..IFR write access to SCG trim registers not disabled. The SCG Trim registers are reprogrammed with the IFR values after any system reset.
 *  0b1..IFR write access to SCG trim registers during system reset is blocked.
 */
#define SCG_TRIM_LOCK_IFR_DISABLE(x)             (((uint32_t)(((uint32_t)(x)) << SCG_TRIM_LOCK_IFR_DISABLE_SHIFT)) & SCG_TRIM_LOCK_IFR_DISABLE_MASK)

#define SCG_TRIM_LOCK_TRIM_LOCK_KEY_MASK         (0xFFFF0000U)
#define SCG_TRIM_LOCK_TRIM_LOCK_KEY_SHIFT        (16U)
/*! TRIM_LOCK_KEY - TRIM_LOCK_KEY */
#define SCG_TRIM_LOCK_TRIM_LOCK_KEY(x)           (((uint32_t)(((uint32_t)(x)) << SCG_TRIM_LOCK_TRIM_LOCK_KEY_SHIFT)) & SCG_TRIM_LOCK_TRIM_LOCK_KEY_MASK)
/*! @} */

/*! @name CSR - Clock Status */
/*! @{ */

#define SCG_CSR_SCS_MASK                         (0x7000000U)
#define SCG_CSR_SCS_SHIFT                        (24U)
/*! SCS - System Clock Source
 *  0b001..SOSC
 *  0b010..SIRC
 *  0b011..FIRC
 *  0b100..ROSC
 */
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x)) << SCG_CSR_SCS_SHIFT)) & SCG_CSR_SCS_MASK)
/*! @} */

/*! @name RCCR - Run Clock Control */
/*! @{ */

#define SCG_RCCR_SCS_MASK                        (0x7000000U)
#define SCG_RCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b001..SOSC
 *  0b010..SIRC
 *  0b011..FIRC
 *  0b100..ROSC
 */
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_SCS_SHIFT)) & SCG_RCCR_SCS_MASK)
/*! @} */

/*! @name SOSCCSR - SOSC Control Status */
/*! @{ */

#define SCG_SOSCCSR_SOSCEN_MASK                  (0x1U)
#define SCG_SOSCCSR_SOSCEN_SHIFT                 (0U)
/*! SOSCEN - SOSC Enable
 *  0b0..SOSC is disabled
 *  0b1..SOSC is enabled
 */
#define SCG_SOSCCSR_SOSCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCEN_SHIFT)) & SCG_SOSCCSR_SOSCEN_MASK)

#define SCG_SOSCCSR_SOSCSTEN_MASK                (0x2U)
#define SCG_SOSCCSR_SOSCSTEN_SHIFT               (1U)
/*! SOSCSTEN - SOSC Stop Enable
 *  0b0..SOSC is disabled in Deep Sleep mode
 *  0b1..SOSC is enabled in Deep Sleep mode only if SOSCEN is set
 */
#define SCG_SOSCCSR_SOSCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSTEN_SHIFT)) & SCG_SOSCCSR_SOSCSTEN_MASK)

#define SCG_SOSCCSR_SOSCCM_MASK                  (0x10000U)
#define SCG_SOSCCSR_SOSCCM_SHIFT                 (16U)
/*! SOSCCM - SOSC Clock Monitor Enable
 *  0b0..SOSC Clock Monitor is disabled
 *  0b1..SOSC Clock Monitor is enabled
 */
#define SCG_SOSCCSR_SOSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCM_SHIFT)) & SCG_SOSCCSR_SOSCCM_MASK)

#define SCG_SOSCCSR_SOSCCMRE_MASK                (0x20000U)
#define SCG_SOSCCSR_SOSCCMRE_SHIFT               (17U)
/*! SOSCCMRE - SOSC Clock Monitor Reset Enable
 *  0b0..Clock monitor generates an interrupt when an error is detected
 *  0b1..Clock monitor generates a reset when an error is detected
 */
#define SCG_SOSCCSR_SOSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCMRE_SHIFT)) & SCG_SOSCCSR_SOSCCMRE_MASK)

#define SCG_SOSCCSR_LK_MASK                      (0x800000U)
#define SCG_SOSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..This Control Status Register can be written
 *  0b1..This Control Status Register cannot be written
 */
#define SCG_SOSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_LK_SHIFT)) & SCG_SOSCCSR_LK_MASK)

#define SCG_SOSCCSR_SOSCVLD_MASK                 (0x1000000U)
#define SCG_SOSCCSR_SOSCVLD_SHIFT                (24U)
/*! SOSCVLD - SOSC Valid
 *  0b0..SOSC is not enabled or clock is not valid
 *  0b1..SOSC is enabled and output clock is valid
 */
#define SCG_SOSCCSR_SOSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCVLD_SHIFT)) & SCG_SOSCCSR_SOSCVLD_MASK)

#define SCG_SOSCCSR_SOSCSEL_MASK                 (0x2000000U)
#define SCG_SOSCCSR_SOSCSEL_SHIFT                (25U)
/*! SOSCSEL - SOSC Selected
 *  0b0..SOSC is not the system clock source
 *  0b1..SOSC is the system clock source
 */
#define SCG_SOSCCSR_SOSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSEL_SHIFT)) & SCG_SOSCCSR_SOSCSEL_MASK)

#define SCG_SOSCCSR_SOSCERR_MASK                 (0x4000000U)
#define SCG_SOSCCSR_SOSCERR_SHIFT                (26U)
/*! SOSCERR - SOSC Clock Error
 *  0b0..SOSC Clock Monitor is disabled or has not detected an error
 *  0b1..SOSC Clock Monitor is enabled and detected an error
 */
#define SCG_SOSCCSR_SOSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCERR_SHIFT)) & SCG_SOSCCSR_SOSCERR_MASK)

#define SCG_SOSCCSR_SOSCVLD_IE_MASK              (0x40000000U)
#define SCG_SOSCCSR_SOSCVLD_IE_SHIFT             (30U)
/*! SOSCVLD_IE - SOSC Valid Interrupt Enable
 *  0b0..SOSCVLD interrupt is not enabled
 *  0b1..SOSCVLD interrupt is enabled
 */
#define SCG_SOSCCSR_SOSCVLD_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCVLD_IE_SHIFT)) & SCG_SOSCCSR_SOSCVLD_IE_MASK)
/*! @} */

/*! @name SOSCCFG - SOSC Configuration */
/*! @{ */

#define SCG_SOSCCFG_EREFS_MASK                   (0x4U)
#define SCG_SOSCCFG_EREFS_SHIFT                  (2U)
/*! EREFS - External Reference Select
 *  0b0..External reference clock selected.
 *  0b1..Internal crystal oscillator of OSC selected.
 */
#define SCG_SOSCCFG_EREFS(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_EREFS_SHIFT)) & SCG_SOSCCFG_EREFS_MASK)

#define SCG_SOSCCFG_RANGE_MASK                   (0x30U)
#define SCG_SOSCCFG_RANGE_SHIFT                  (4U)
/*! RANGE - SOSC Range Select
 *  0b00..Frequency range select of 8-16 MHz.
 *  0b01..Frequency range select of 16-25 MHz.
 *  0b10..Frequency range select of 25-40 MHz.
 *  0b11..Frequency range select of 40-50 MHz.
 */
#define SCG_SOSCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_RANGE_SHIFT)) & SCG_SOSCCFG_RANGE_MASK)
/*! @} */

/*! @name SIRCCSR - SIRC Control Status */
/*! @{ */

#define SCG_SIRCCSR_SIRCSTEN_MASK                (0x2U)
#define SCG_SIRCCSR_SIRCSTEN_SHIFT               (1U)
/*! SIRCSTEN - SIRC Stop Enable
 *  0b0..SIRC is disabled in Deep Sleep mode
 *  0b1..SIRC is enabled in Deep Sleep mode
 */
#define SCG_SIRCCSR_SIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSTEN_SHIFT)) & SCG_SIRCCSR_SIRCSTEN_MASK)

#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK      (0x20U)
#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_SHIFT     (5U)
/*! SIRC_CLK_PERIPH_EN - SIRC Clock to Peripherals Enable
 *  0b0..SIRC clock to peripherals is disabled
 *  0b1..SIRC clock to peripherals is enabled
 */
#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN(x)        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_SHIFT)) & SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK)

#define SCG_SIRCCSR_SIRCTREN_MASK                (0x100U)
#define SCG_SIRCCSR_SIRCTREN_SHIFT               (8U)
/*! SIRCTREN - SIRC 12 MHz Trim Enable (SIRCCFG[RANGE]=1)
 *  0b0..Disables trimming SIRC to an external clock source
 *  0b1..Enables trimming SIRC to an external clock source
 */
#define SCG_SIRCCSR_SIRCTREN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCTREN_SHIFT)) & SCG_SIRCCSR_SIRCTREN_MASK)

#define SCG_SIRCCSR_SIRCTRUP_MASK                (0x200U)
#define SCG_SIRCCSR_SIRCTRUP_SHIFT               (9U)
/*! SIRCTRUP - SIRC Trim Update
 *  0b0..Disables SIRC trimming updates
 *  0b1..Enables SIRC trimming updates
 */
#define SCG_SIRCCSR_SIRCTRUP(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCTRUP_SHIFT)) & SCG_SIRCCSR_SIRCTRUP_MASK)

#define SCG_SIRCCSR_TRIM_LOCK_MASK               (0x400U)
#define SCG_SIRCCSR_TRIM_LOCK_SHIFT              (10U)
/*! TRIM_LOCK - SIRC TRIM LOCK
 *  0b0..SIRC auto trim not locked to target frequency range
 *  0b1..SIRC auto trim locked to target frequency range
 */
#define SCG_SIRCCSR_TRIM_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_TRIM_LOCK_SHIFT)) & SCG_SIRCCSR_TRIM_LOCK_MASK)

#define SCG_SIRCCSR_COARSE_TRIM_BYPASS_MASK      (0x800U)
#define SCG_SIRCCSR_COARSE_TRIM_BYPASS_SHIFT     (11U)
/*! COARSE_TRIM_BYPASS - Coarse Auto Trim Bypass
 *  0b0..SIRC Coarse Auto Trim NOT Bypassed
 *  0b1..SIRC Coarse Auto Trim Bypassed
 */
#define SCG_SIRCCSR_COARSE_TRIM_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_COARSE_TRIM_BYPASS_SHIFT)) & SCG_SIRCCSR_COARSE_TRIM_BYPASS_MASK)

#define SCG_SIRCCSR_LK_MASK                      (0x800000U)
#define SCG_SIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_SIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_LK_SHIFT)) & SCG_SIRCCSR_LK_MASK)

#define SCG_SIRCCSR_SIRCVLD_MASK                 (0x1000000U)
#define SCG_SIRCCSR_SIRCVLD_SHIFT                (24U)
/*! SIRCVLD - SIRC Valid
 *  0b0..SIRC is not enabled or clock is not valid
 *  0b1..SIRC is enabled and output clock is valid
 */
#define SCG_SIRCCSR_SIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCVLD_SHIFT)) & SCG_SIRCCSR_SIRCVLD_MASK)

#define SCG_SIRCCSR_SIRCSEL_MASK                 (0x2000000U)
#define SCG_SIRCCSR_SIRCSEL_SHIFT                (25U)
/*! SIRCSEL - SIRC Selected
 *  0b0..SIRC is not the system clock source
 *  0b1..SIRC is the system clock source
 */
#define SCG_SIRCCSR_SIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSEL_SHIFT)) & SCG_SIRCCSR_SIRCSEL_MASK)

#define SCG_SIRCCSR_SIRCERR_MASK                 (0x4000000U)
#define SCG_SIRCCSR_SIRCERR_SHIFT                (26U)
/*! SIRCERR - SIRC Clock Error
 *  0b0..Error not detected with the SIRC trimming
 *  0b1..Error detected with the SIRC trimming
 */
#define SCG_SIRCCSR_SIRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCERR_SHIFT)) & SCG_SIRCCSR_SIRCERR_MASK)

#define SCG_SIRCCSR_SIRCERR_IE_MASK              (0x8000000U)
#define SCG_SIRCCSR_SIRCERR_IE_SHIFT             (27U)
/*! SIRCERR_IE - SIRC Clock Error Interrupt Enable
 *  0b0..SIRCERR interrupt is not enabled
 *  0b1..SIRCERR interrupt is enabled
 */
#define SCG_SIRCCSR_SIRCERR_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCERR_IE_SHIFT)) & SCG_SIRCCSR_SIRCERR_IE_MASK)
/*! @} */

/*! @name SIRCTCFG - SIRC Trim Configuration */
/*! @{ */

#define SCG_SIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_SIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..SOSC. This option requires that SOSC be divided using the TRIMDIV field to get a frequency of 1 MHz.
 *  0b11..Reserved
 */
#define SCG_SIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTCFG_TRIMSRC_SHIFT)) & SCG_SIRCTCFG_TRIMSRC_MASK)

#define SCG_SIRCTCFG_TRIMDIV_MASK                (0x7F0000U)
#define SCG_SIRCTCFG_TRIMDIV_SHIFT               (16U)
/*! TRIMDIV - SIRC Trim Pre-divider */
#define SCG_SIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTCFG_TRIMDIV_SHIFT)) & SCG_SIRCTCFG_TRIMDIV_MASK)
/*! @} */

/*! @name SIRCTRIM - SIRC Trim */
/*! @{ */

#define SCG_SIRCTRIM_CCOTRIM_MASK                (0x3FU)
#define SCG_SIRCTRIM_CCOTRIM_SHIFT               (0U)
/*! CCOTRIM - CCO Trim */
#define SCG_SIRCTRIM_CCOTRIM(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_CCOTRIM_SHIFT)) & SCG_SIRCTRIM_CCOTRIM_MASK)

#define SCG_SIRCTRIM_CLTRIM_MASK                 (0x3F00U)
#define SCG_SIRCTRIM_CLTRIM_SHIFT                (8U)
/*! CLTRIM - CL Trim */
#define SCG_SIRCTRIM_CLTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_CLTRIM_SHIFT)) & SCG_SIRCTRIM_CLTRIM_MASK)

#define SCG_SIRCTRIM_TCTRIM_MASK                 (0x1F0000U)
#define SCG_SIRCTRIM_TCTRIM_SHIFT                (16U)
/*! TCTRIM - Trim Temp */
#define SCG_SIRCTRIM_TCTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_TCTRIM_SHIFT)) & SCG_SIRCTRIM_TCTRIM_MASK)

#define SCG_SIRCTRIM_FVCHTRIM_MASK               (0x1F000000U)
#define SCG_SIRCTRIM_FVCHTRIM_SHIFT              (24U)
#define SCG_SIRCTRIM_FVCHTRIM(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_SIRCTRIM_FVCHTRIM_SHIFT)) & SCG_SIRCTRIM_FVCHTRIM_MASK)
/*! @} */

/*! @name SIRCSTAT - SIRC Auto-trimming Status */
/*! @{ */

#define SCG_SIRCSTAT_CCOTRIM_MASK                (0x3FU)
#define SCG_SIRCSTAT_CCOTRIM_SHIFT               (0U)
/*! CCOTRIM - CCO Trim */
#define SCG_SIRCSTAT_CCOTRIM(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCSTAT_CCOTRIM_SHIFT)) & SCG_SIRCSTAT_CCOTRIM_MASK)

#define SCG_SIRCSTAT_CLTRIM_MASK                 (0x3F00U)
#define SCG_SIRCSTAT_CLTRIM_SHIFT                (8U)
/*! CLTRIM - CL Trim */
#define SCG_SIRCSTAT_CLTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCSTAT_CLTRIM_SHIFT)) & SCG_SIRCSTAT_CLTRIM_MASK)
/*! @} */

/*! @name FIRCCSR - FIRC Control Status */
/*! @{ */

#define SCG_FIRCCSR_FIRCEN_MASK                  (0x1U)
#define SCG_FIRCCSR_FIRCEN_SHIFT                 (0U)
/*! FIRCEN - FIRC Enable
 *  0b0..FIRC is disabled
 *  0b1..FIRC is enabled
 */
#define SCG_FIRCCSR_FIRCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCEN_SHIFT)) & SCG_FIRCCSR_FIRCEN_MASK)

#define SCG_FIRCCSR_FIRCSTEN_MASK                (0x2U)
#define SCG_FIRCCSR_FIRCSTEN_SHIFT               (1U)
/*! FIRCSTEN - FIRC Stop Enable
 *  0b0..FIRC is disabled in Deep Sleep mode
 *  0b1..FIRC is enabled in Deep Sleep mode
 */
#define SCG_FIRCCSR_FIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSTEN_SHIFT)) & SCG_FIRCCSR_FIRCSTEN_MASK)

#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK     (0x10U)
#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_SHIFT    (4U)
/*! FIRC_SCLK_PERIPH_EN - FIRC 45 MHz Clock to peripherals Enable
 *  0b0..FIRC 45 MHz to peripherals is disabled
 *  0b1..FIRC 45 MHz to peripherals is enabled
 */
#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK     (0x20U)
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT    (5U)
/*! FIRC_FCLK_PERIPH_EN - FRO_HF Clock to peripherals Enable
 *  0b0..FRO_HF to peripherals is disabled
 *  0b1..FRO_HF to peripherals is enabled
 */
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_LK_MASK                      (0x800000U)
#define SCG_FIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_FIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_LK_SHIFT)) & SCG_FIRCCSR_LK_MASK)

#define SCG_FIRCCSR_FIRCVLD_MASK                 (0x1000000U)
#define SCG_FIRCCSR_FIRCVLD_SHIFT                (24U)
/*! FIRCVLD - FIRC Valid status
 *  0b0..FIRC is not enabled or clock is not valid.
 *  0b1..FIRC is enabled and output clock is valid. The clock is valid after there is an output clock from the FIRC analog.
 */
#define SCG_FIRCCSR_FIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCVLD_SHIFT)) & SCG_FIRCCSR_FIRCVLD_MASK)

#define SCG_FIRCCSR_FIRCSEL_MASK                 (0x2000000U)
#define SCG_FIRCCSR_FIRCSEL_SHIFT                (25U)
/*! FIRCSEL - FIRC Selected
 *  0b0..FIRC is not the system clock source
 *  0b1..FIRC is the system clock source
 */
#define SCG_FIRCCSR_FIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSEL_SHIFT)) & SCG_FIRCCSR_FIRCSEL_MASK)

#define SCG_FIRCCSR_FIRCERR_MASK                 (0x4000000U)
#define SCG_FIRCCSR_FIRCERR_SHIFT                (26U)
/*! FIRCERR - FIRC Clock Error
 *  0b0..Error not detected with the FIRC trimming
 *  0b1..Error detected with the FIRC trimming
 */
#define SCG_FIRCCSR_FIRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCERR_SHIFT)) & SCG_FIRCCSR_FIRCERR_MASK)

#define SCG_FIRCCSR_FIRCERR_IE_MASK              (0x8000000U)
#define SCG_FIRCCSR_FIRCERR_IE_SHIFT             (27U)
/*! FIRCERR_IE - FIRC Clock Error Interrupt Enable
 *  0b0..FIRCERR interrupt is not enabled
 *  0b1..FIRCERR interrupt is enabled
 */
#define SCG_FIRCCSR_FIRCERR_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCERR_IE_SHIFT)) & SCG_FIRCCSR_FIRCERR_IE_MASK)

#define SCG_FIRCCSR_FIRCACC_IE_MASK              (0x40000000U)
#define SCG_FIRCCSR_FIRCACC_IE_SHIFT             (30U)
/*! FIRCACC_IE - FIRC Accurate Interrupt Enable
 *  0b0..FIRCACC interrupt is not enabled
 *  0b1..FIRCACC interrupt is enabled
 */
#define SCG_FIRCCSR_FIRCACC_IE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCACC_IE_SHIFT)) & SCG_FIRCCSR_FIRCACC_IE_MASK)

#define SCG_FIRCCSR_FIRCACC_MASK                 (0x80000000U)
#define SCG_FIRCCSR_FIRCACC_SHIFT                (31U)
/*! FIRCACC - FIRC Frequency Accurate
 *  0b0..FIRC is not enabled or clock is not accurate.
 *  0b1..FIRC is enabled and output clock is accurate after some preparation time which is obtained by counting FRO_HF clock.
 */
#define SCG_FIRCCSR_FIRCACC(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCACC_SHIFT)) & SCG_FIRCCSR_FIRCACC_MASK)
/*! @} */

/*! @name FIRCCFG - FIRC Configuration */
/*! @{ */

#define SCG_FIRCCFG_FREQ_SEL_MASK                (0xEU)
#define SCG_FIRCCFG_FREQ_SEL_SHIFT               (1U)
/*! FREQ_SEL - Frequency select
 *  0b001..45 MHz FIRC clock selected, divided from 180 MHz
 *  0b011..60 MHz FIRC clock selected
 *  0b101..90 MHz FIRC clock selected
 *  0b111..180 MHz FIRC clock selected
 */
#define SCG_FIRCCFG_FREQ_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCFG_FREQ_SEL_SHIFT)) & SCG_FIRCCFG_FREQ_SEL_MASK)
/*! @} */

/*! @name FIRCTRIM - FIRC Trim */
/*! @{ */

#define SCG_FIRCTRIM_TRIMFINE_MASK               (0xFFU)
#define SCG_FIRCTRIM_TRIMFINE_SHIFT              (0U)
/*! TRIMFINE - Trim Fine */
#define SCG_FIRCTRIM_TRIMFINE(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMFINE_SHIFT)) & SCG_FIRCTRIM_TRIMFINE_MASK)

#define SCG_FIRCTRIM_TRIMCOAR_MASK               (0x3F00U)
#define SCG_FIRCTRIM_TRIMCOAR_SHIFT              (8U)
/*! TRIMCOAR - Trim Coarse */
#define SCG_FIRCTRIM_TRIMCOAR(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMCOAR_SHIFT)) & SCG_FIRCTRIM_TRIMCOAR_MASK)

#define SCG_FIRCTRIM_TRIMTEMP_MASK               (0xF0000U)
#define SCG_FIRCTRIM_TRIMTEMP_SHIFT              (16U)
/*! TRIMTEMP - Trim Temperature */
#define SCG_FIRCTRIM_TRIMTEMP(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMTEMP_SHIFT)) & SCG_FIRCTRIM_TRIMTEMP_MASK)

#define SCG_FIRCTRIM_TRIMSTART_MASK              (0x3F000000U)
#define SCG_FIRCTRIM_TRIMSTART_SHIFT             (24U)
/*! TRIMSTART - Trim Start */
#define SCG_FIRCTRIM_TRIMSTART(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTRIM_TRIMSTART_SHIFT)) & SCG_FIRCTRIM_TRIMSTART_MASK)
/*! @} */

/*! @name ROSCCSR - ROSC Control Status */
/*! @{ */

#define SCG_ROSCCSR_LK_MASK                      (0x800000U)
#define SCG_ROSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock
 *  0b0..Control Status Register can be written
 *  0b1..Control Status Register cannot be written
 */
#define SCG_ROSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_LK_SHIFT)) & SCG_ROSCCSR_LK_MASK)

#define SCG_ROSCCSR_ROSCVLD_MASK                 (0x1000000U)
#define SCG_ROSCCSR_ROSCVLD_SHIFT                (24U)
/*! ROSCVLD - ROSC Valid
 *  0b0..ROSC is not enabled or clock is not valid
 *  0b1..ROSC is enabled and output clock is valid
 */
#define SCG_ROSCCSR_ROSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCVLD_SHIFT)) & SCG_ROSCCSR_ROSCVLD_MASK)

#define SCG_ROSCCSR_ROSCSEL_MASK                 (0x2000000U)
#define SCG_ROSCCSR_ROSCSEL_SHIFT                (25U)
/*! ROSCSEL - ROSC Selected
 *  0b0..ROSC is not the system clock source
 *  0b1..ROSC is the system clock source
 */
#define SCG_ROSCCSR_ROSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCSEL_SHIFT)) & SCG_ROSCCSR_ROSCSEL_MASK)

#define SCG_ROSCCSR_ROSCERR_MASK                 (0x4000000U)
#define SCG_ROSCCSR_ROSCERR_SHIFT                (26U)
/*! ROSCERR - ROSC Clock Error
 *  0b0..ROSC Clock has not detected an error
 *  0b1..ROSC Clock has detected an error
 */
#define SCG_ROSCCSR_ROSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCERR_SHIFT)) & SCG_ROSCCSR_ROSCERR_MASK)
/*! @} */

/*! @name LDOCSR - LDO Control and Status */
/*! @{ */

#define SCG_LDOCSR_LDOEN_MASK                    (0x1U)
#define SCG_LDOCSR_LDOEN_SHIFT                   (0U)
/*! LDOEN - LDO Enable
 *  0b0..LDO is disabled
 *  0b1..LDO is enabled
 */
#define SCG_LDOCSR_LDOEN(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_LDOEN_SHIFT)) & SCG_LDOCSR_LDOEN_MASK)

#define SCG_LDOCSR_VOUT_SEL_MASK                 (0xEU)
#define SCG_LDOCSR_VOUT_SEL_SHIFT                (1U)
/*! VOUT_SEL - LDO output voltage select
 *  0b000..VOUT = 1V
 *  0b001..VOUT = 1V
 *  0b010..VOUT = 1V
 *  0b011..VOUT = 1.05V
 *  0b100..VOUT = 1.1V
 *  0b101..VOUT = 1.15V
 *  0b110..VOUT = 1.2V
 *  0b111..VOUT = 1.25V
 */
#define SCG_LDOCSR_VOUT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_VOUT_SEL_SHIFT)) & SCG_LDOCSR_VOUT_SEL_MASK)

#define SCG_LDOCSR_LDOBYPASS_MASK                (0x10U)
#define SCG_LDOCSR_LDOBYPASS_SHIFT               (4U)
/*! LDOBYPASS - LDO Bypass
 *  0b0..LDO is not bypassed
 *  0b1..LDO is bypassed
 */
#define SCG_LDOCSR_LDOBYPASS(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_LDOBYPASS_SHIFT)) & SCG_LDOCSR_LDOBYPASS_MASK)

#define SCG_LDOCSR_VOUT_OK_MASK                  (0x80000000U)
#define SCG_LDOCSR_VOUT_OK_SHIFT                 (31U)
/*! VOUT_OK - LDO VOUT OK Inform.
 *  0b0..LDO output VOUT is not OK
 *  0b1..LDO output VOUT is OK
 */
#define SCG_LDOCSR_VOUT_OK(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_LDOCSR_VOUT_OK_SHIFT)) & SCG_LDOCSR_VOUT_OK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SCG_Register_Masks */


/*!
 * @}
 */ /* end of group SCG_Peripheral_Access_Layer */


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


#endif  /* PERI_SCG_H_ */

