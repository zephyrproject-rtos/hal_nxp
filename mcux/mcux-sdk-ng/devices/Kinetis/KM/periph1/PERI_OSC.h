/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
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
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
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

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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

#define OSC_CR_SC16P_MASK                        (0x1U)
#define OSC_CR_SC16P_SHIFT                       (0U)
/*! SC16P - Oscillator 16 pF Capacitor Load Configure
 *  0b0..Disable the selection.
 *  0b1..Add 16 pF capacitor to the oscillator load.
 */
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC16P_SHIFT)) & OSC_CR_SC16P_MASK)

#define OSC_CR_SC8P_MASK                         (0x2U)
#define OSC_CR_SC8P_SHIFT                        (1U)
/*! SC8P - Oscillator 8 pF Capacitor Load Configure
 *  0b0..Disable the selection.
 *  0b1..Add 8 pF capacitor to the oscillator load.
 */
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC8P_SHIFT)) & OSC_CR_SC8P_MASK)

#define OSC_CR_SC4P_MASK                         (0x4U)
#define OSC_CR_SC4P_SHIFT                        (2U)
/*! SC4P - Oscillator 4 pF Capacitor Load Configure
 *  0b0..Disable the selection.
 *  0b1..Add 4 pF capacitor to the oscillator load.
 */
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC4P_SHIFT)) & OSC_CR_SC4P_MASK)

#define OSC_CR_SC2P_MASK                         (0x8U)
#define OSC_CR_SC2P_SHIFT                        (3U)
/*! SC2P - Oscillator 2 pF Capacitor Load Configure
 *  0b0..Disable the selection.
 *  0b1..Add 2 pF capacitor to the oscillator load.
 */
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC2P_SHIFT)) & OSC_CR_SC2P_MASK)

#define OSC_CR_EREFSTEN_MASK                     (0x20U)
#define OSC_CR_EREFSTEN_SHIFT                    (5U)
/*! EREFSTEN - External Reference Stop Enable
 *  0b0..External reference clock is disabled in Stop mode.
 *  0b1..External reference clock stays enabled in Stop mode if ERCLKEN is set before entering Stop mode.
 */
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x)) << OSC_CR_EREFSTEN_SHIFT)) & OSC_CR_EREFSTEN_MASK)

#define OSC_CR_ERCLKEN_MASK                      (0x80U)
#define OSC_CR_ERCLKEN_SHIFT                     (7U)
/*! ERCLKEN - External Reference Enable
 *  0b0..External reference clock is inactive.
 *  0b1..External reference clock is enabled.
 */
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x)) << OSC_CR_ERCLKEN_SHIFT)) & OSC_CR_ERCLKEN_MASK)
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

