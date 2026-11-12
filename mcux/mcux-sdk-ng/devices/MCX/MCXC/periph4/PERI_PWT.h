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
**         CMSIS Peripheral Access Layer for PWT
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
 * @file PERI_PWT.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for PWT
 *
 * CMSIS Peripheral Access Layer for PWT
 */

#if !defined(PERI_PWT_H_)
#define PERI_PWT_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWT_Peripheral_Access_Layer PWT Peripheral Access Layer
 * @{
 */

/** PWT - Register Layout Typedef */
typedef struct {
  __IO uint32_t R1;                                /**< Pulse Width Timer Register 1, offset: 0x0 */
  __I  uint32_t R2;                                /**< Pulse Width Timer Register 2, offset: 0x4 */
} PWT_Type;

/* ----------------------------------------------------------------------------
   -- PWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWT_Register_Masks PWT Register Masks
 * @{
 */

/*! @name R1 - Pulse Width Timer Register 1 */
/*! @{ */

#define PWT_R1_PWTOV_MASK                        (0x1U)
#define PWT_R1_PWTOV_SHIFT                       (0U)
/*! PWTOV - PWT Counter Overflow
 *  0b0..PWT counter no overflow.
 *  0b1..PWT counter runs exceeding 0xFFFF (then it re-counts from 0).
 */
#define PWT_R1_PWTOV(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R1_PWTOV_SHIFT)) & PWT_R1_PWTOV_MASK)

#define PWT_R1_PWTRDY_MASK                       (0x2U)
#define PWT_R1_PWTRDY_SHIFT                      (1U)
/*! PWTRDY - PWT Pulse Width Valid
 *  0b0..PWT pulse width register(s) is not up-to-date.
 *  0b1..PWT pulse width register(s) has been updated.
 */
#define PWT_R1_PWTRDY(x)                         (((uint32_t)(((uint32_t)(x)) << PWT_R1_PWTRDY_SHIFT)) & PWT_R1_PWTRDY_MASK)

#define PWT_R1_FCTLE_MASK                        (0x4U)
#define PWT_R1_FCTLE_SHIFT                       (2U)
/*! FCTLE - First counter load enable after enable
 *  0b0..Not to load the first counter values to the corresponding registers
 *  0b1..Load the first counter values to the corresponding registers depending on the PWTIN level
 */
#define PWT_R1_FCTLE(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R1_FCTLE_SHIFT)) & PWT_R1_FCTLE_MASK)

#define PWT_R1_PWTSR_MASK                        (0x8U)
#define PWT_R1_PWTSR_SHIFT                       (3U)
/*! PWTSR - PWT Soft Reset
 *  0b0..No action taken.
 *  0b1..Writing 1 to this field will perform soft reset to PWT.
 */
#define PWT_R1_PWTSR(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R1_PWTSR_SHIFT)) & PWT_R1_PWTSR_MASK)

#define PWT_R1_POVIE_MASK                        (0x10U)
#define PWT_R1_POVIE_SHIFT                       (4U)
/*! POVIE - PWT Counter Overflow Interrupt Enable
 *  0b0..Disable PWT to generate interrupt when PWTOV is set.
 *  0b1..Enable PWT to generate interrupt when PWTOV is set.
 */
#define PWT_R1_POVIE(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R1_POVIE_SHIFT)) & PWT_R1_POVIE_MASK)

#define PWT_R1_PRDYIE_MASK                       (0x20U)
#define PWT_R1_PRDYIE_SHIFT                      (5U)
/*! PRDYIE - PWT Pulse Width Data Ready Interrupt Enable
 *  0b0..Disable PWT to generate interrupt when PWTRDY is set.
 *  0b1..Enable PWT to generate interrupt when PWTRDY is set.
 */
#define PWT_R1_PRDYIE(x)                         (((uint32_t)(((uint32_t)(x)) << PWT_R1_PRDYIE_SHIFT)) & PWT_R1_PRDYIE_MASK)

#define PWT_R1_PWTIE_MASK                        (0x40U)
#define PWT_R1_PWTIE_SHIFT                       (6U)
/*! PWTIE - PWT Module Interrupt Enable
 *  0b0..Disables the PWT to generate interrupt.
 *  0b1..Enables the PWT to generate interrupt.
 */
#define PWT_R1_PWTIE(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R1_PWTIE_SHIFT)) & PWT_R1_PWTIE_MASK)

#define PWT_R1_PWTEN_MASK                        (0x80U)
#define PWT_R1_PWTEN_SHIFT                       (7U)
/*! PWTEN - PWT Module Enable
 *  0b0..The PWT is disabled.
 *  0b1..The PWT is enabled.
 */
#define PWT_R1_PWTEN(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R1_PWTEN_SHIFT)) & PWT_R1_PWTEN_MASK)

#define PWT_R1_PRE_MASK                          (0x700U)
#define PWT_R1_PRE_SHIFT                         (8U)
/*! PRE - PWT Clock Prescaler (CLKPRE) Setting
 *  0b000..Clock divided by 1.
 *  0b001..Clock divided by 2.
 *  0b010..Clock divided by 4.
 *  0b011..Clock divided by 8.
 *  0b100..Clock divided by 16.
 *  0b101..Clock divided by 32.
 *  0b110..Clock divided by 64.
 *  0b111..Clock divided by 128.
 */
#define PWT_R1_PRE(x)                            (((uint32_t)(((uint32_t)(x)) << PWT_R1_PRE_SHIFT)) & PWT_R1_PRE_MASK)

#define PWT_R1_LVL_MASK                          (0x800U)
#define PWT_R1_LVL_SHIFT                         (11U)
/*! LVL - PWTIN Level when Overflows */
#define PWT_R1_LVL(x)                            (((uint32_t)(((uint32_t)(x)) << PWT_R1_LVL_SHIFT)) & PWT_R1_LVL_MASK)

#define PWT_R1_TGL_MASK                          (0x1000U)
#define PWT_R1_TGL_SHIFT                         (12U)
/*! TGL - PWTIN states Toggled from last state
 *  0b0..The selected PWTIN hasn't changed its original states from last time.
 *  0b1..The selected PWTIN has toggled its states.
 */
#define PWT_R1_TGL(x)                            (((uint32_t)(((uint32_t)(x)) << PWT_R1_TGL_SHIFT)) & PWT_R1_TGL_MASK)

#define PWT_R1_PINSEL_MASK                       (0x6000U)
#define PWT_R1_PINSEL_SHIFT                      (13U)
/*! PINSEL - PWT Pulse Inputs Selection
 *  0b00..PWTIN0 is enabled.
 *  0b01..PWTIN1 is enabled.
 *  0b10..PWTIN2 enabled.
 *  0b11..PWTIN3 enabled.
 */
#define PWT_R1_PINSEL(x)                         (((uint32_t)(((uint32_t)(x)) << PWT_R1_PINSEL_SHIFT)) & PWT_R1_PINSEL_MASK)

#define PWT_R1_PCLKS_MASK                        (0x8000U)
#define PWT_R1_PCLKS_SHIFT                       (15U)
/*! PCLKS - PWT Clock Source Selection
 *  0b0..PWT_CLK is selected as the clock source of PWT counter.
 *  0b1..Alternative clock is selected as the clock source of PWT counter.
 */
#define PWT_R1_PCLKS(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R1_PCLKS_SHIFT)) & PWT_R1_PCLKS_MASK)

#define PWT_R1_PPWH_MASK                         (0xFF0000U)
#define PWT_R1_PPWH_SHIFT                        (16U)
/*! PPWH - Positive Pulse Width (High) */
#define PWT_R1_PPWH(x)                           (((uint32_t)(((uint32_t)(x)) << PWT_R1_PPWH_SHIFT)) & PWT_R1_PPWH_MASK)

#define PWT_R1_PPWL_MASK                         (0xFF000000U)
#define PWT_R1_PPWL_SHIFT                        (24U)
/*! PPWL - Positive Pulse Width (Low) */
#define PWT_R1_PPWL(x)                           (((uint32_t)(((uint32_t)(x)) << PWT_R1_PPWL_SHIFT)) & PWT_R1_PPWL_MASK)
/*! @} */

/*! @name R2 - Pulse Width Timer Register 2 */
/*! @{ */

#define PWT_R2_NPWH_MASK                         (0xFFU)
#define PWT_R2_NPWH_SHIFT                        (0U)
/*! NPWH - Negative Pulse Width (High) */
#define PWT_R2_NPWH(x)                           (((uint32_t)(((uint32_t)(x)) << PWT_R2_NPWH_SHIFT)) & PWT_R2_NPWH_MASK)

#define PWT_R2_NPWL_MASK                         (0xFF00U)
#define PWT_R2_NPWL_SHIFT                        (8U)
/*! NPWL - Negative Pulse Width (Low) */
#define PWT_R2_NPWL(x)                           (((uint32_t)(((uint32_t)(x)) << PWT_R2_NPWL_SHIFT)) & PWT_R2_NPWL_MASK)

#define PWT_R2_PWTCH_MASK                        (0xFF0000U)
#define PWT_R2_PWTCH_SHIFT                       (16U)
/*! PWTCH - PWT Counter (High) */
#define PWT_R2_PWTCH(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R2_PWTCH_SHIFT)) & PWT_R2_PWTCH_MASK)

#define PWT_R2_PWTCL_MASK                        (0xFF000000U)
#define PWT_R2_PWTCL_SHIFT                       (24U)
/*! PWTCL - PWT Counter (Low) */
#define PWT_R2_PWTCL(x)                          (((uint32_t)(((uint32_t)(x)) << PWT_R2_PWTCL_SHIFT)) & PWT_R2_PWTCL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PWT_Register_Masks */


/*!
 * @}
 */ /* end of group PWT_Peripheral_Access_Layer */


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


#endif  /* PERI_PWT_H_ */

