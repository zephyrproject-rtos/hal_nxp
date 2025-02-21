/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VREF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file VREF.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for VREF
 *
 * CMSIS Peripheral Access Layer for VREF
 */

#if !defined(VREF_H_)
#define VREF_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- VREF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Peripheral_Access_Layer VREF Peripheral Access Layer
 * @{
 */

/** VREF - Register Layout Typedef */
typedef struct {
  __IO uint8_t TRM;                                /**< VREF Trim Register, offset: 0x0 */
  __IO uint8_t SC;                                 /**< VREF Status and Control Register, offset: 0x1 */
} VREF_Type;

/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Register_Masks VREF Register Masks
 * @{
 */

/*! @name TRM - VREF Trim Register */
/*! @{ */

#define VREF_TRM_TRIM_MASK                       (0x3FU)
#define VREF_TRM_TRIM_SHIFT                      (0U)
/*! TRIM - Trim bits
 *  0b000000..Min
 *  0b111111..Max
 */
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x)) << VREF_TRM_TRIM_SHIFT)) & VREF_TRM_TRIM_MASK)

#define VREF_TRM_CHOPEN_MASK                     (0x40U)
#define VREF_TRM_CHOPEN_SHIFT                    (6U)
/*! CHOPEN - Chop oscillator enable. When set, internal chopping operation is enabled and the
 *    internal analog offset will be minimized.
 *  0b0..Chop oscillator is disabled.
 *  0b1..Chop oscillator is enabled.
 */
#define VREF_TRM_CHOPEN(x)                       (((uint8_t)(((uint8_t)(x)) << VREF_TRM_CHOPEN_SHIFT)) & VREF_TRM_CHOPEN_MASK)
/*! @} */

/*! @name SC - VREF Status and Control Register */
/*! @{ */

#define VREF_SC_MODE_LV_MASK                     (0x3U)
#define VREF_SC_MODE_LV_SHIFT                    (0U)
/*! MODE_LV - Buffer Mode selection
 *  0b00..Bandgap on only, for stabilization and startup
 *  0b01..High power buffer mode enabled
 *  0b10..Low-power buffer mode enabled
 *  0b11..Reserved
 */
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x)) << VREF_SC_MODE_LV_SHIFT)) & VREF_SC_MODE_LV_MASK)

#define VREF_SC_VREFST_MASK                      (0x4U)
#define VREF_SC_VREFST_SHIFT                     (2U)
/*! VREFST - Internal Voltage Reference stable
 *  0b0..The module is disabled or not stable.
 *  0b1..The module is stable.
 */
#define VREF_SC_VREFST(x)                        (((uint8_t)(((uint8_t)(x)) << VREF_SC_VREFST_SHIFT)) & VREF_SC_VREFST_MASK)

#define VREF_SC_ICOMPEN_MASK                     (0x20U)
#define VREF_SC_ICOMPEN_SHIFT                    (5U)
/*! ICOMPEN - Second order curvature compensation enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define VREF_SC_ICOMPEN(x)                       (((uint8_t)(((uint8_t)(x)) << VREF_SC_ICOMPEN_SHIFT)) & VREF_SC_ICOMPEN_MASK)

#define VREF_SC_REGEN_MASK                       (0x40U)
#define VREF_SC_REGEN_SHIFT                      (6U)
/*! REGEN - Regulator enable
 *  0b0..Internal 1.75 V regulator is disabled.
 *  0b1..Internal 1.75 V regulator is enabled.
 */
#define VREF_SC_REGEN(x)                         (((uint8_t)(((uint8_t)(x)) << VREF_SC_REGEN_SHIFT)) & VREF_SC_REGEN_MASK)

#define VREF_SC_VREFEN_MASK                      (0x80U)
#define VREF_SC_VREFEN_SHIFT                     (7U)
/*! VREFEN - Internal Voltage Reference enable
 *  0b0..The module is disabled.
 *  0b1..The module is enabled.
 */
#define VREF_SC_VREFEN(x)                        (((uint8_t)(((uint8_t)(x)) << VREF_SC_VREFEN_SHIFT)) & VREF_SC_VREFEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VREF_Register_Masks */


/*!
 * @}
 */ /* end of group VREF_Peripheral_Access_Layer */


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


#endif  /* VREF_H_ */

