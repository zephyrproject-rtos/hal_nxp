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
**         CMSIS Peripheral Access Layer for PMC
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
 * @file PERI_PMC.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint8_t LVDSC1;                             /**< Low Voltage Detect Status and Control 1 Register, offset: 0x0 */
  __IO uint8_t LVDSC2;                             /**< Low Voltage Detect Status and Control 2 Register, offset: 0x1 */
  __IO uint8_t REGSC;                              /**< Regulator Status and Control Register, offset: 0x2 */
       uint8_t RESERVED_0[1];
  __IO uint8_t LPOTRIM;                            /**< Low Power Oscillator Trim Register, offset: 0x4 */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name LVDSC1 - Low Voltage Detect Status and Control 1 Register */
/*! @{ */

#define PMC_LVDSC1_LVDRE_MASK                    (0x10U)
#define PMC_LVDSC1_LVDRE_SHIFT                   (4U)
/*! LVDRE - Low Voltage Detect Reset Enable
 *  0b0..No system resets on low voltage detect events.
 *  0b1..If the supply voltage falls below VLVD, a system reset will be generated.
 */
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDRE_SHIFT)) & PMC_LVDSC1_LVDRE_MASK)

#define PMC_LVDSC1_LVDIE_MASK                    (0x20U)
#define PMC_LVDSC1_LVDIE_SHIFT                   (5U)
/*! LVDIE - Low Voltage Detect Interrupt Enable
 *  0b0..Hardware interrupt disabled (use polling)
 *  0b1..Request a hardware interrupt when LVDF = 1
 */
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDIE_SHIFT)) & PMC_LVDSC1_LVDIE_MASK)

#define PMC_LVDSC1_LVDACK_MASK                   (0x40U)
#define PMC_LVDSC1_LVDACK_SHIFT                  (6U)
/*! LVDACK - Low Voltage Detect Acknowledge */
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDACK_SHIFT)) & PMC_LVDSC1_LVDACK_MASK)

#define PMC_LVDSC1_LVDF_MASK                     (0x80U)
#define PMC_LVDSC1_LVDF_SHIFT                    (7U)
/*! LVDF - Low Voltage Detect Flag
 *  0b0..Low-voltage event not detected
 *  0b1..Low-voltage event detected
 */
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDF_SHIFT)) & PMC_LVDSC1_LVDF_MASK)
/*! @} */

/*! @name LVDSC2 - Low Voltage Detect Status and Control 2 Register */
/*! @{ */

#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)
/*! LVWIE - Low-Voltage Warning Interrupt Enable
 *  0b0..Hardware interrupt disabled (use polling)
 *  0b1..Request a hardware interrupt when LVWF=1
 */
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWIE_SHIFT)) & PMC_LVDSC2_LVWIE_MASK)

#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)
/*! LVWACK - Low-Voltage Warning Acknowledge */
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWACK_SHIFT)) & PMC_LVDSC2_LVWACK_MASK)

#define PMC_LVDSC2_LVWF_MASK                     (0x80U)
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)
/*! LVWF - Low-Voltage Warning Flag
 *  0b0..Low-voltage warning event not detected
 *  0b1..Low-voltage warning event detected
 */
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWF_SHIFT)) & PMC_LVDSC2_LVWF_MASK)
/*! @} */

/*! @name REGSC - Regulator Status and Control Register */
/*! @{ */

#define PMC_REGSC_BIASEN_MASK                    (0x1U)
#define PMC_REGSC_BIASEN_SHIFT                   (0U)
/*! BIASEN - Bias Enable Bit
 *  0b0..Biasing disabled, core logic can run in full performance
 *  0b1..Biasing enabled, core logic is slower and there are restrictions in allowed system clock speed (see Data Sheet for details)
 */
#define PMC_REGSC_BIASEN(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_BIASEN_SHIFT)) & PMC_REGSC_BIASEN_MASK)

#define PMC_REGSC_CLKBIASDIS_MASK                (0x2U)
#define PMC_REGSC_CLKBIASDIS_SHIFT               (1U)
/*! CLKBIASDIS - Clock Bias Disable Bit
 *  0b0..No effect
 *  0b1..In VLPS mode, the bias currents and reference voltages for the following clock modules are disabled:
 *       SIRC, FIRC, PLL. (if available on device)
 */
#define PMC_REGSC_CLKBIASDIS(x)                  (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_CLKBIASDIS_SHIFT)) & PMC_REGSC_CLKBIASDIS_MASK)

#define PMC_REGSC_REGFPM_MASK                    (0x4U)
#define PMC_REGSC_REGFPM_SHIFT                   (2U)
/*! REGFPM - Regulator in Full Performance Mode Status Bit
 *  0b0..Regulator is in low power mode or transition to/from
 *  0b1..Regulator is in full performance mode
 */
#define PMC_REGSC_REGFPM(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_REGFPM_SHIFT)) & PMC_REGSC_REGFPM_MASK)

#define PMC_REGSC_LPOSTAT_MASK                   (0x40U)
#define PMC_REGSC_LPOSTAT_SHIFT                  (6U)
/*! LPOSTAT - LPO Status Bit
 *  0b0..Low power oscillator in low phase
 *  0b1..Low power oscillator in high phase
 */
#define PMC_REGSC_LPOSTAT(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_LPOSTAT_SHIFT)) & PMC_REGSC_LPOSTAT_MASK)

#define PMC_REGSC_LPODIS_MASK                    (0x80U)
#define PMC_REGSC_LPODIS_SHIFT                   (7U)
/*! LPODIS - LPO Disable Bit
 *  0b0..Low power oscillator enabled
 *  0b1..Low power oscillator disabled
 */
#define PMC_REGSC_LPODIS(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_LPODIS_SHIFT)) & PMC_REGSC_LPODIS_MASK)
/*! @} */

/*! @name LPOTRIM - Low Power Oscillator Trim Register */
/*! @{ */

#define PMC_LPOTRIM_LPOTRIM_MASK                 (0x1FU)
#define PMC_LPOTRIM_LPOTRIM_SHIFT                (0U)
/*! LPOTRIM - LPO trimming bits */
#define PMC_LPOTRIM_LPOTRIM(x)                   (((uint8_t)(((uint8_t)(x)) << PMC_LPOTRIM_LPOTRIM_SHIFT)) & PMC_LPOTRIM_LPOTRIM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


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


#endif  /* PERI_PMC_H_ */

