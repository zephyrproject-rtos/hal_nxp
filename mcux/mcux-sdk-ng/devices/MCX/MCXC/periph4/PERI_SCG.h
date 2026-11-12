/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**                          MCXC353GAMFM
**                          MCXC353GAMFT
**                          MCXC353MLF
**
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SCG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_SCG.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for SCG
 *
 * CMSIS Peripheral Access Layer for SCG
 */

#if !defined(PERI_SCG_H_)
#define PERI_SCG_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC352GAMFM) || defined(CPU_MCXC352GAMFT) || defined(CPU_MCXC352MLF))
#include "MCXC352_COMMON.h"
#elif (defined(CPU_MCXC353GAMFM) || defined(CPU_MCXC353GAMFT) || defined(CPU_MCXC353MLF))
#include "MCXC353_COMMON.h"
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
  __I  uint32_t SOSCCFG;                           /**< SOSC Configuration, offset: 0x108 */
       uint8_t RESERVED_3[244];
  __IO uint32_t SIRCCSR;                           /**< SIRC Control Status, offset: 0x200 */
       uint8_t RESERVED_4[252];
  __IO uint32_t FIRCCSR;                           /**< FIRC Control Status, offset: 0x300 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FIRCCFG;                           /**< FIRC Configuration, offset: 0x308 */
  __IO uint32_t FIRCTCFG;                          /**< FIRC Trim Configuration, offset: 0x30C */
  __IO uint32_t FIRCTRIM;                          /**< FIRC Trim, offset: 0x310 */
       uint8_t RESERVED_6[4];
  __IO uint32_t FIRCSTAT;                          /**< FIRC Auto-trimming Status, offset: 0x318 */
  __IO uint32_t FIRCATC1;                          /**< FIRC Auto-trimming Counter 1, offset: 0x31C */
  __IO uint32_t FIRCATC2;                          /**< FIRC Auto-trimming Counter 2, offset: 0x320 */
  __IO uint32_t FIRCATC3;                          /**< FIRC Auto-trimming Counter 3, offset: 0x324 */
       uint8_t RESERVED_7[216];
  __IO uint32_t ROSCCSR;                           /**< ROSC Control Status, offset: 0x400 */
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
 *  0b001..SOSC (CLK_IN)
 *  0b010..SIRC
 *  0b011..FIRC (FRO_HF)
 *  0b100..ROSC (FRO_16K)
 */
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x)) << SCG_CSR_SCS_SHIFT)) & SCG_CSR_SCS_MASK)
/*! @} */

/*! @name RCCR - Run Clock Control */
/*! @{ */

#define SCG_RCCR_SCS_MASK                        (0x7000000U)
#define SCG_RCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b001..SOSC (CLK_IN)
 *  0b010..SIRC
 *  0b011..FIRC (FRO_HF)
 *  0b100..ROSC (FRO_16K)
 */
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_SCS_SHIFT)) & SCG_RCCR_SCS_MASK)
/*! @} */

/*! @name SOSCCSR - SOSC Control Status */
/*! @{ */

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
/*! @} */

/*! @name SIRCCSR - SIRC Control Status */
/*! @{ */

#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK      (0x20U)
#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_SHIFT     (5U)
/*! SIRC_CLK_PERIPH_EN - SIRC Clock to Peripherals Enable
 *  0b0..SIRC clock to peripherals is disabled
 *  0b1..SIRC clock to peripherals is enabled
 */
#define SCG_SIRCCSR_SIRC_CLK_PERIPH_EN(x)        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_SHIFT)) & SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK)

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
/*! FIRC_SCLK_PERIPH_EN - FIRC_48MHz Clock to Peripherals Enable
 *  0b0..FIRC_48MHz disabled
 *  0b1..FIRC_48MHz enabled
 */
#define SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK     (0x20U)
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT    (5U)
/*! FIRC_FCLK_PERIPH_EN - FRO_HF_GATED to Peripherals Enable
 *  0b0..FRO_HF_GATED disabled
 *  0b1..FRO_HF_GATED enabled
 */
#define SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN(x)       (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT)) & SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK)

#define SCG_FIRCCSR_FIRCTREN_MASK                (0x100U)
#define SCG_FIRCCSR_FIRCTREN_SHIFT               (8U)
/*! FIRCTREN - FRO_HF Trim Enable
 *  0b0..Disables trimming FRO_HF by an external clock source
 *  0b1..Enables trimming FRO_HF by an external clock source
 */
#define SCG_FIRCCSR_FIRCTREN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTREN_SHIFT)) & SCG_FIRCCSR_FIRCTREN_MASK)

#define SCG_FIRCCSR_FIRCTRUP_MASK                (0x200U)
#define SCG_FIRCCSR_FIRCTRUP_SHIFT               (9U)
/*! FIRCTRUP - FIRC Trim Update
 *  0b0..Disables FIRC trimming updates
 *  0b1..Enables FIRC trimming updates
 */
#define SCG_FIRCCSR_FIRCTRUP(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTRUP_SHIFT)) & SCG_FIRCCSR_FIRCTRUP_MASK)

#define SCG_FIRCCSR_TRIM_LOCK_MASK               (0x400U)
#define SCG_FIRCCSR_TRIM_LOCK_SHIFT              (10U)
/*! TRIM_LOCK - FIRC TRIM LOCK
 *  0b0..FIRC auto trim not locked to target frequency range
 *  0b1..FIRC auto trim locked to target frequency range
 */
#define SCG_FIRCCSR_TRIM_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_TRIM_LOCK_SHIFT)) & SCG_FIRCCSR_TRIM_LOCK_MASK)

#define SCG_FIRCCSR_COARSE_TRIM_BYPASS_MASK      (0x800U)
#define SCG_FIRCCSR_COARSE_TRIM_BYPASS_SHIFT     (11U)
/*! COARSE_TRIM_BYPASS - Coarse Auto Trim Bypass
 *  0b0..FIRC Coarse Auto Trim NOT Bypassed
 *  0b1..FIRC Coarse Auto Trim Bypassed
 */
#define SCG_FIRCCSR_COARSE_TRIM_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_COARSE_TRIM_BYPASS_SHIFT)) & SCG_FIRCCSR_COARSE_TRIM_BYPASS_MASK)

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
 *  0b001..48 MHz FIRC clock selected, divided from 192 MHz
 *  0b011..64 MHz FIRC clock selected
 *  0b101..96 MHz FIRC clock selected
 *  0b111..192 MHz FIRC clock selected
 */
#define SCG_FIRCCFG_FREQ_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCFG_FREQ_SEL_SHIFT)) & SCG_FIRCCFG_FREQ_SEL_MASK)
/*! @} */

/*! @name FIRCTCFG - FIRC Trim Configuration */
/*! @{ */

#define SCG_FIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_FIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..SOSC. This option requires that SOSC be divided using the TRIMDIV field to get a frequency of 1 MHz.
 *  0b11..Reserved
 */
#define SCG_FIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMSRC_SHIFT)) & SCG_FIRCTCFG_TRIMSRC_MASK)

#define SCG_FIRCTCFG_TRIMDIV_MASK                (0x7F0000U)
#define SCG_FIRCTCFG_TRIMDIV_SHIFT               (16U)
/*! TRIMDIV - FIRC Trim Pre-divider */
#define SCG_FIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMDIV_SHIFT)) & SCG_FIRCTCFG_TRIMDIV_MASK)
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

/*! @name FIRCSTAT - FIRC Auto-trimming Status */
/*! @{ */

#define SCG_FIRCSTAT_TRIMFINE_MASK               (0xFFU)
#define SCG_FIRCSTAT_TRIMFINE_SHIFT              (0U)
/*! TRIMFINE - Trim Fine */
#define SCG_FIRCSTAT_TRIMFINE(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCSTAT_TRIMFINE_SHIFT)) & SCG_FIRCSTAT_TRIMFINE_MASK)

#define SCG_FIRCSTAT_TRIMCOAR_MASK               (0x3F00U)
#define SCG_FIRCSTAT_TRIMCOAR_SHIFT              (8U)
/*! TRIMCOAR - Trim Coarse */
#define SCG_FIRCSTAT_TRIMCOAR(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCSTAT_TRIMCOAR_SHIFT)) & SCG_FIRCSTAT_TRIMCOAR_MASK)
/*! @} */

/*! @name FIRCATC1 - FIRC Auto-trimming Counter 1 */
/*! @{ */

#define SCG_FIRCATC1_IDEALC_SOSC_MASK            (0xFFFFU)
#define SCG_FIRCATC1_IDEALC_SOSC_SHIFT           (0U)
/*! IDEALC_SOSC - Ideal Counter SOSC */
#define SCG_FIRCATC1_IDEALC_SOSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC1_IDEALC_SOSC_SHIFT)) & SCG_FIRCATC1_IDEALC_SOSC_MASK)

#define SCG_FIRCATC1_SAMCYC_SOSC_MASK            (0xFF0000U)
#define SCG_FIRCATC1_SAMCYC_SOSC_SHIFT           (16U)
/*! SAMCYC_SOSC - Sample Cycle SOSC */
#define SCG_FIRCATC1_SAMCYC_SOSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC1_SAMCYC_SOSC_SHIFT)) & SCG_FIRCATC1_SAMCYC_SOSC_MASK)

#define SCG_FIRCATC1_SETCYC_SOSC_MASK            (0xFF000000U)
#define SCG_FIRCATC1_SETCYC_SOSC_SHIFT           (24U)
/*! SETCYC_SOSC - Setup Cycle SOSC */
#define SCG_FIRCATC1_SETCYC_SOSC(x)              (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC1_SETCYC_SOSC_SHIFT)) & SCG_FIRCATC1_SETCYC_SOSC_MASK)
/*! @} */

/*! @name FIRCATC2 - FIRC Auto-trimming Counter 2 */
/*! @{ */

#define SCG_FIRCATC2_COARMINC_SOSC_MASK          (0xFFFFU)
#define SCG_FIRCATC2_COARMINC_SOSC_SHIFT         (0U)
/*! COARMINC_SOSC - Coarse Trim Minimum Counter SOSC */
#define SCG_FIRCATC2_COARMINC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC2_COARMINC_SOSC_SHIFT)) & SCG_FIRCATC2_COARMINC_SOSC_MASK)

#define SCG_FIRCATC2_COARMAXC_SOSC_MASK          (0xFFFF0000U)
#define SCG_FIRCATC2_COARMAXC_SOSC_SHIFT         (16U)
/*! COARMAXC_SOSC - Coarse Trim Maximum Counter SOSC */
#define SCG_FIRCATC2_COARMAXC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC2_COARMAXC_SOSC_SHIFT)) & SCG_FIRCATC2_COARMAXC_SOSC_MASK)
/*! @} */

/*! @name FIRCATC3 - FIRC Auto-trimming Counter 3 */
/*! @{ */

#define SCG_FIRCATC3_FINEMINC_SOSC_MASK          (0xFFFFU)
#define SCG_FIRCATC3_FINEMINC_SOSC_SHIFT         (0U)
/*! FINEMINC_SOSC - Fine Trim Minimum Counter SOSC */
#define SCG_FIRCATC3_FINEMINC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC3_FINEMINC_SOSC_SHIFT)) & SCG_FIRCATC3_FINEMINC_SOSC_MASK)

#define SCG_FIRCATC3_FINEMAXC_SOSC_MASK          (0xFFFF0000U)
#define SCG_FIRCATC3_FINEMAXC_SOSC_SHIFT         (16U)
/*! FINEMAXC_SOSC - Fine Trim Maximum Counter SOSC */
#define SCG_FIRCATC3_FINEMAXC_SOSC(x)            (((uint32_t)(((uint32_t)(x)) << SCG_FIRCATC3_FINEMAXC_SOSC_SHIFT)) & SCG_FIRCATC3_FINEMAXC_SOSC_MASK)
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

