/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SXOSC
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
 * @file PERI_SXOSC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for SXOSC
 *
 * CMSIS Peripheral Access Layer for SXOSC
 */

#if !defined(PERI_SXOSC_H_)
#define PERI_SXOSC_H_                            /**< Symbol preventing repeated inclusion */

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
   -- SXOSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SXOSC_Peripheral_Access_Layer SXOSC Peripheral Access Layer
 * @{
 */

/** SXOSC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SXOSC_CTRL;                        /**< Oscillator Control, offset: 0x0 */
  __I  uint32_t SXOSC_STAT;                        /**< Oscillator Status, offset: 0x4 */
} SXOSC_Type;

/* ----------------------------------------------------------------------------
   -- SXOSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SXOSC_Register_Masks SXOSC Register Masks
 * @{
 */

/*! @name SXOSC_CTRL - Oscillator Control */
/*! @{ */

#define SXOSC_SXOSC_CTRL_OSCON_MASK              (0x1U)
#define SXOSC_SXOSC_CTRL_OSCON_SHIFT             (0U)
/*! OSCON - Crystal Oscillator Power-Down Control
 *  0b0..Disabled (switched off)
 *  0b1..Enabled (switched on)
 */
#define SXOSC_SXOSC_CTRL_OSCON(x)                (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_CTRL_OSCON_SHIFT)) & SXOSC_SXOSC_CTRL_OSCON_MASK)

#define SXOSC_SXOSC_CTRL_EOCV_MASK               (0xFF0000U)
#define SXOSC_SXOSC_CTRL_EOCV_SHIFT              (16U)
/*! EOCV - End Of Count Value */
#define SXOSC_SXOSC_CTRL_EOCV(x)                 (((uint32_t)(((uint32_t)(x)) << SXOSC_SXOSC_CTRL_EOCV_SHIFT)) & SXOSC_SXOSC_CTRL_EOCV_MASK)
/*! @} */

/*! @name SXOSC_STAT - Oscillator Status */
/*! @{ */

#define SXOSC_SXOSC_STAT_OSC_STAT_MASK           (0x80000000U)
#define SXOSC_SXOSC_STAT_OSC_STAT_SHIFT          (31U)
/*! OSC_STAT - Crystal Oscillator Status
 *  0b0..Unstable
 *  0b1..Stable
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

