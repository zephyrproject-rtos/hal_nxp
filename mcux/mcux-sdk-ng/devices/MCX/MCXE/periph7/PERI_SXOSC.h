/*
** ###################################################################
**     Processors:          MCXE327MPA_cm7_core0
**                          MCXE327MPA_cm7_core1
**                          MCXE327MPB_cm7_core0
**                          MCXE327MPB_cm7_core1
**
**     Version:             rev. 1.0, 2025-07-18
**     Build:               b260609
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SXOSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**     - rev. 1.0 (2025-07-18)
**         Rev2 RM.
**
** ###################################################################
*/

/*!
 * @file PERI_SXOSC.h
 * @version 1.0
 * @date 2025-07-18
 * @brief CMSIS Peripheral Access Layer for SXOSC
 *
 * CMSIS Peripheral Access Layer for SXOSC
 */

#if !defined(PERI_SXOSC_H_)
#define PERI_SXOSC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE327MPA_cm7_core0) || defined(CPU_MCXE327MPB_cm7_core0))
#include "MCXE327_cm7_core0_COMMON.h"
#elif (defined(CPU_MCXE327MPA_cm7_core1) || defined(CPU_MCXE327MPB_cm7_core1))
#include "MCXE327_cm7_core1_COMMON.h"
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
   -- SXOSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SXOSC_Peripheral_Access_Layer SXOSC Peripheral Access Layer
 * @{
 */

/** SXOSC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SXOSC_CTRL;                        /**< Oscillator Control Register, offset: 0x0 */
  __I  uint32_t SXOSC_STAT;                        /**< Oscillator Status Register, offset: 0x4 */
} SXOSC_Type;

/* ----------------------------------------------------------------------------
   -- SXOSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SXOSC_Register_Masks SXOSC Register Masks
 * @{
 */

/*! @name SXOSC_CTRL - Oscillator Control Register */
/*! @{ */

#define SXOSC_SXOSC_CTRL_OSCON_MASK              (0x1U)
#define SXOSC_SXOSC_CTRL_OSCON_SHIFT             (0U)
/*! OSCON - Crystal oscillator power-down control
 *  0b0..Crystal oscillator is switched OFF
 *  0b1..Crystal oscillator is switched ON
 */
#define SXOSC_SXOSC_CTRL_OSCON(x)                (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_CTRL_OSCON_SHIFT)) & SXOSC_SXOSC_CTRL_OSCON_MASK)

#define SXOSC_SXOSC_CTRL_GM_SEL_MASK             (0xC0U)
#define SXOSC_SXOSC_CTRL_GM_SEL_SHIFT            (6U)
/*! GM_SEL - Crystal overdrive protection This field setting decides the trans-conductance applied
 *    by XOSC amplifier, and it will depend on crystal specification.
 */
#define SXOSC_SXOSC_CTRL_GM_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_CTRL_GM_SEL_SHIFT)) & SXOSC_SXOSC_CTRL_GM_SEL_MASK)

#define SXOSC_SXOSC_CTRL_EOCV_MASK               (0xFF0000U)
#define SXOSC_SXOSC_CTRL_EOCV_SHIFT              (16U)
/*! EOCV - End of count value */
#define SXOSC_SXOSC_CTRL_EOCV(x)                 (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_CTRL_EOCV_SHIFT)) & SXOSC_SXOSC_CTRL_EOCV_MASK)

#define SXOSC_SXOSC_CTRL_CURR_PRG_COMP_MASK      (0x3000000U)
#define SXOSC_SXOSC_CTRL_CURR_PRG_COMP_SHIFT     (24U)
/*! CURR_PRG_COMP - These bits specify programmability of comparator current. */
#define SXOSC_SXOSC_CTRL_CURR_PRG_COMP(x)        (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_CTRL_CURR_PRG_COMP_SHIFT)) & SXOSC_SXOSC_CTRL_CURR_PRG_COMP_MASK)

#define SXOSC_SXOSC_CTRL_CURR_PRG_SF_MASK        (0xC000000U)
#define SXOSC_SXOSC_CTRL_CURR_PRG_SF_SHIFT       (26U)
/*! CURR_PRG_SF - These bits specify programmability of level shifter current. */
#define SXOSC_SXOSC_CTRL_CURR_PRG_SF(x)          (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_CTRL_CURR_PRG_SF_SHIFT)) & SXOSC_SXOSC_CTRL_CURR_PRG_SF_MASK)
/*! @} */

/*! @name SXOSC_STAT - Oscillator Status Register */
/*! @{ */

#define SXOSC_SXOSC_STAT_OSC_STAT_MASK           (0x80000000U)
#define SXOSC_SXOSC_STAT_OSC_STAT_SHIFT          (31U)
/*! OSC_STAT - Crystal oscillator status
 *  0b0..Crystal oscillator output clock is not stable.
 *  0b1..Crystal oscillator is providing a stable clock.
 */
#define SXOSC_SXOSC_STAT_OSC_STAT(x)             (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_STAT_OSC_STAT_SHIFT)) & SXOSC_SXOSC_STAT_OSC_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SXOSC_Register_Masks */


/*!
 * @}
 */ /* end of group SXOSC_Peripheral_Access_Layer */


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


#endif  /* PERI_SXOSC_H_ */

