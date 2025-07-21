/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ACMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ACMP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ACMP
 *
 * CMSIS Peripheral Access Layer for ACMP
 */

#if !defined(PERI_ACMP_H_)
#define PERI_ACMP_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ACMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Peripheral_Access_Layer ACMP Peripheral Access Layer
 * @{
 */

/** ACMP - Register Layout Typedef */
typedef struct {
  __IO uint8_t CS;                                 /**< ACMP Control and Status Register, offset: 0x0 */
  __IO uint8_t C0;                                 /**< ACMP Control Register 0, offset: 0x1 */
  __IO uint8_t C1;                                 /**< ACMP Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< ACMP Control Register 2, offset: 0x3 */
} ACMP_Type;

/* ----------------------------------------------------------------------------
   -- ACMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Register_Masks ACMP Register Masks
 * @{
 */

/*! @name CS - ACMP Control and Status Register */
/*! @{ */

#define ACMP_CS_ACMOD_MASK                       (0x3U)
#define ACMP_CS_ACMOD_SHIFT                      (0U)
/*! ACMOD - ACMP MOD
 *  0b00..ACMP interrupt on output falling edge.
 *  0b01..ACMP interrupt on output rising edge.
 *  0b10..ACMP interrupt on output falling edge.
 *  0b11..ACMP interrupt on output falling or rising edge.
 */
#define ACMP_CS_ACMOD(x)                         (((uint8_t)(((uint8_t)(x)) << ACMP_CS_ACMOD_SHIFT)) & ACMP_CS_ACMOD_MASK)

#define ACMP_CS_ACOPE_MASK                       (0x4U)
#define ACMP_CS_ACOPE_SHIFT                      (2U)
/*! ACOPE - ACMP Output Pin Enable
 *  0b0..ACMP output cannot be placed onto external pin.
 *  0b1..ACMP output can be placed onto external pin.
 */
#define ACMP_CS_ACOPE(x)                         (((uint8_t)(((uint8_t)(x)) << ACMP_CS_ACOPE_SHIFT)) & ACMP_CS_ACOPE_MASK)

#define ACMP_CS_ACO_MASK                         (0x8U)
#define ACMP_CS_ACO_SHIFT                        (3U)
/*! ACO - ACMP Output */
#define ACMP_CS_ACO(x)                           (((uint8_t)(((uint8_t)(x)) << ACMP_CS_ACO_SHIFT)) & ACMP_CS_ACO_MASK)

#define ACMP_CS_ACIE_MASK                        (0x10U)
#define ACMP_CS_ACIE_SHIFT                       (4U)
/*! ACIE - ACMP Interrupt Enable
 *  0b0..Disable the ACMP Interrupt.
 *  0b1..Enable the ACMP Interrupt.
 */
#define ACMP_CS_ACIE(x)                          (((uint8_t)(((uint8_t)(x)) << ACMP_CS_ACIE_SHIFT)) & ACMP_CS_ACIE_MASK)

#define ACMP_CS_ACF_MASK                         (0x20U)
#define ACMP_CS_ACF_SHIFT                        (5U)
/*! ACF - ACMP Interrupt Flag Bit */
#define ACMP_CS_ACF(x)                           (((uint8_t)(((uint8_t)(x)) << ACMP_CS_ACF_SHIFT)) & ACMP_CS_ACF_MASK)

#define ACMP_CS_HYST_MASK                        (0x40U)
#define ACMP_CS_HYST_SHIFT                       (6U)
/*! HYST - Analog Comparator Hysterisis Selection
 *  0b0..20 mV.
 *  0b1..30 mV.
 */
#define ACMP_CS_HYST(x)                          (((uint8_t)(((uint8_t)(x)) << ACMP_CS_HYST_SHIFT)) & ACMP_CS_HYST_MASK)

#define ACMP_CS_ACE_MASK                         (0x80U)
#define ACMP_CS_ACE_SHIFT                        (7U)
/*! ACE - Analog Comparator Enable
 *  0b0..The ACMP is disabled.
 *  0b1..The ACMP is enabled.
 */
#define ACMP_CS_ACE(x)                           (((uint8_t)(((uint8_t)(x)) << ACMP_CS_ACE_SHIFT)) & ACMP_CS_ACE_MASK)
/*! @} */

/*! @name C0 - ACMP Control Register 0 */
/*! @{ */

#define ACMP_C0_ACNSEL_MASK                      (0x3U)
#define ACMP_C0_ACNSEL_SHIFT                     (0U)
/*! ACNSEL - ACMP Negative Input Select
 *  0b00..External reference 0
 *  0b01..External reference 1
 *  0b10..External reference 2
 *  0b11..DAC output
 */
#define ACMP_C0_ACNSEL(x)                        (((uint8_t)(((uint8_t)(x)) << ACMP_C0_ACNSEL_SHIFT)) & ACMP_C0_ACNSEL_MASK)

#define ACMP_C0_ACPSEL_MASK                      (0x30U)
#define ACMP_C0_ACPSEL_SHIFT                     (4U)
/*! ACPSEL - ACMP Positive Input Select
 *  0b00..External reference 0
 *  0b01..External reference 1
 *  0b10..External reference 2
 *  0b11..DAC output
 */
#define ACMP_C0_ACPSEL(x)                        (((uint8_t)(((uint8_t)(x)) << ACMP_C0_ACPSEL_SHIFT)) & ACMP_C0_ACPSEL_MASK)
/*! @} */

/*! @name C1 - ACMP Control Register 1 */
/*! @{ */

#define ACMP_C1_DACVAL_MASK                      (0x3FU)
#define ACMP_C1_DACVAL_SHIFT                     (0U)
/*! DACVAL - DAC Output Level Selection */
#define ACMP_C1_DACVAL(x)                        (((uint8_t)(((uint8_t)(x)) << ACMP_C1_DACVAL_SHIFT)) & ACMP_C1_DACVAL_MASK)

#define ACMP_C1_DACREF_MASK                      (0x40U)
#define ACMP_C1_DACREF_SHIFT                     (6U)
/*! DACREF - DAC Reference Select
 *  0b0..The DAC selects Bandgap as the reference.
 *  0b1..The DAC selects VDDA as the reference.
 */
#define ACMP_C1_DACREF(x)                        (((uint8_t)(((uint8_t)(x)) << ACMP_C1_DACREF_SHIFT)) & ACMP_C1_DACREF_MASK)

#define ACMP_C1_DACEN_MASK                       (0x80U)
#define ACMP_C1_DACEN_SHIFT                      (7U)
/*! DACEN - DAC Enable
 *  0b0..The DAC is disabled.
 *  0b1..The DAC is enabled.
 */
#define ACMP_C1_DACEN(x)                         (((uint8_t)(((uint8_t)(x)) << ACMP_C1_DACEN_SHIFT)) & ACMP_C1_DACEN_MASK)
/*! @} */

/*! @name C2 - ACMP Control Register 2 */
/*! @{ */

#define ACMP_C2_ACIPE_MASK                       (0x7U)
#define ACMP_C2_ACIPE_SHIFT                      (0U)
/*! ACIPE - ACMP Input Pin Enable
 *  0b000..The corresponding external analog input is not allowed.
 *  0b001..The corresponding external analog input is allowed.
 */
#define ACMP_C2_ACIPE(x)                         (((uint8_t)(((uint8_t)(x)) << ACMP_C2_ACIPE_SHIFT)) & ACMP_C2_ACIPE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ACMP_Register_Masks */


/*!
 * @}
 */ /* end of group ACMP_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_ACMP_H_ */

