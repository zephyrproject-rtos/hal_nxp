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
**         CMSIS Peripheral Access Layer for OSC
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
 * @file PERI_OSC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OSC
 *
 * CMSIS Peripheral Access Layer for OSC
 */

#if !defined(PERI_OSC_H_)
#define PERI_OSC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- OSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Peripheral_Access_Layer OSC Peripheral Access Layer
 * @{
 */

/** OSC - Register Layout Typedef */
typedef struct {
  __IO uint8_t CR;                                 /**< OSC Control Register, offset: 0x0 */
} OSC_Type;

/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/*! @name CR - OSC Control Register */
/*! @{ */

#define OSC_CR_OSCINIT_MASK                      (0x1U)
#define OSC_CR_OSCINIT_SHIFT                     (0U)
/*! OSCINIT - OSC Initialization
 *  0b0..Oscillator initialization is not complete.
 *  0b1..Oscillator initialization is completed.
 */
#define OSC_CR_OSCINIT(x)                        (((uint8_t)(((uint8_t)(x)) << OSC_CR_OSCINIT_SHIFT)) & OSC_CR_OSCINIT_MASK)

#define OSC_CR_HGO_MASK                          (0x2U)
#define OSC_CR_HGO_SHIFT                         (1U)
/*! HGO - High Gain Oscillator Select
 *  0b0..Low-power mode
 *  0b1..High-gain mode
 */
#define OSC_CR_HGO(x)                            (((uint8_t)(((uint8_t)(x)) << OSC_CR_HGO_SHIFT)) & OSC_CR_HGO_MASK)

#define OSC_CR_RANGE_MASK                        (0x4U)
#define OSC_CR_RANGE_SHIFT                       (2U)
/*! RANGE - Frequency Range Select
 *  0b0..Low frequency range of 32 kHz.
 *  0b1..High frequency range of 4-20 MHz.
 */
#define OSC_CR_RANGE(x)                          (((uint8_t)(((uint8_t)(x)) << OSC_CR_RANGE_SHIFT)) & OSC_CR_RANGE_MASK)

#define OSC_CR_OSCOS_MASK                        (0x10U)
#define OSC_CR_OSCOS_SHIFT                       (4U)
/*! OSCOS - OSC Output Select
 *  0b0..External clock source from EXTAL pin is selected.
 *  0b1..Oscillator clock source is selected.
 */
#define OSC_CR_OSCOS(x)                          (((uint8_t)(((uint8_t)(x)) << OSC_CR_OSCOS_SHIFT)) & OSC_CR_OSCOS_MASK)

#define OSC_CR_OSCSTEN_MASK                      (0x20U)
#define OSC_CR_OSCSTEN_SHIFT                     (5U)
/*! OSCSTEN - OSC Enable in Stop mode
 *  0b0..OSC clock is disabled in Stop mode.
 *  0b1..OSC clock stays enabled in Stop mode.
 */
#define OSC_CR_OSCSTEN(x)                        (((uint8_t)(((uint8_t)(x)) << OSC_CR_OSCSTEN_SHIFT)) & OSC_CR_OSCSTEN_MASK)

#define OSC_CR_OSCEN_MASK                        (0x80U)
#define OSC_CR_OSCEN_SHIFT                       (7U)
/*! OSCEN - OSC Enable
 *  0b0..OSC module is disabled.
 *  0b1..OSC module is enabled.
 */
#define OSC_CR_OSCEN(x)                          (((uint8_t)(((uint8_t)(x)) << OSC_CR_OSCEN_SHIFT)) & OSC_CR_OSCEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSC_Register_Masks */


/*!
 * @}
 */ /* end of group OSC_Peripheral_Access_Layer */


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


#endif  /* PERI_OSC_H_ */

