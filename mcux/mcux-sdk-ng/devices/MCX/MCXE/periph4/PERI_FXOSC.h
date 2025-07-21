/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FXOSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_FXOSC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for FXOSC
 *
 * CMSIS Peripheral Access Layer for FXOSC
 */

#if !defined(PERI_FXOSC_H_)
#define PERI_FXOSC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
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
   -- FXOSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FXOSC_Peripheral_Access_Layer FXOSC Peripheral Access Layer
 * @{
 */

/** FXOSC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< FXOSC Control Register, offset: 0x0 */
  __I  uint32_t STAT;                              /**< Oscillator Status Register, offset: 0x4 */
} FXOSC_Type;

/* ----------------------------------------------------------------------------
   -- FXOSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FXOSC_Register_Masks FXOSC Register Masks
 * @{
 */

/*! @name CTRL - FXOSC Control Register */
/*! @{ */

#define FXOSC_CTRL_OSCON_MASK                    (0x1U)
#define FXOSC_CTRL_OSCON_SHIFT                   (0U)
/*! OSCON - Crystal oscillator power-down control
 *  0b0..Disables FXOSC
 *  0b1..Enables FXOSC
 */
#define FXOSC_CTRL_OSCON(x)                      (((uint32_t)(((uint32_t)(x)) << FXOSC_CTRL_OSCON_SHIFT)) & FXOSC_CTRL_OSCON_MASK)

#define FXOSC_CTRL_GM_SEL_MASK                   (0xF0U)
#define FXOSC_CTRL_GM_SEL_SHIFT                  (4U)
/*! GM_SEL - Crystal overdrive protection
 *  0b0000..0x
 *  0b0001..0.1004x
 *  0b0010..0.2009x
 *  0b0011..0.3013x
 *  0b0100..0.2343x
 *  0b0101..0.3348x
 *  0b0110..0.4345x
 *  0b0111..0.5349x
 *  0b1000..0.4679x
 *  0b1001..0.5684x
 *  0b1010..0.6681x
 *  0b1011..0.7678x
 *  0b1100..0.7016x
 *  0b1101..0.8013x
 *  0b1110..0.9003x
 *  0b1111..1x
 */
#define FXOSC_CTRL_GM_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << FXOSC_CTRL_GM_SEL_SHIFT)) & FXOSC_CTRL_GM_SEL_MASK)

#define FXOSC_CTRL_EOCV_MASK                     (0xFF0000U)
#define FXOSC_CTRL_EOCV_SHIFT                    (16U)
/*! EOCV - End of count value */
#define FXOSC_CTRL_EOCV(x)                       (((uint32_t)(((uint32_t)(x)) << FXOSC_CTRL_EOCV_SHIFT)) & FXOSC_CTRL_EOCV_MASK)

#define FXOSC_CTRL_COMP_EN_MASK                  (0x1000000U)
#define FXOSC_CTRL_COMP_EN_SHIFT                 (24U)
/*! COMP_EN - Comparator enable
 *  0b0..Comparator disabled
 *  0b1..Comparator enabled
 */
#define FXOSC_CTRL_COMP_EN(x)                    (((uint32_t)(((uint32_t)(x)) << FXOSC_CTRL_COMP_EN_SHIFT)) & FXOSC_CTRL_COMP_EN_MASK)

#define FXOSC_CTRL_OSC_BYP_MASK                  (0x80000000U)
#define FXOSC_CTRL_OSC_BYP_SHIFT                 (31U)
/*! OSC_BYP - Oscillator bypass
 *  0b0..Internal oscillator not bypassed
 *  0b1..Internal oscillator bypassed
 */
#define FXOSC_CTRL_OSC_BYP(x)                    (((uint32_t)(((uint32_t)(x)) << FXOSC_CTRL_OSC_BYP_SHIFT)) & FXOSC_CTRL_OSC_BYP_MASK)
/*! @} */

/*! @name STAT - Oscillator Status Register */
/*! @{ */

#define FXOSC_STAT_OSC_STAT_MASK                 (0x80000000U)
#define FXOSC_STAT_OSC_STAT_SHIFT                (31U)
/*! OSC_STAT - Crystal oscillator status
 *  0b0..Crystal oscillator is off or on but not stable.
 *  0b1..Crystal oscillator is on and providing a stable clock.
 */
#define FXOSC_STAT_OSC_STAT(x)                   (((uint32_t)(((uint32_t)(x)) << FXOSC_STAT_OSC_STAT_SHIFT)) & FXOSC_STAT_OSC_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FXOSC_Register_Masks */


/*!
 * @}
 */ /* end of group FXOSC_Peripheral_Access_Layer */


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


#endif  /* PERI_FXOSC_H_ */

