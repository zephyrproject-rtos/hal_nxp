/*
** ###################################################################
**     Processors:          MKM35Z256VLL7
**                          MKM35Z256VLL7R
**                          MKM35Z256VLQ7
**                          MKM35Z256VLQ7R
**                          MKM35Z512VLL7
**                          MKM35Z512VLL7R
**                          MKM35Z512VLQ7
**                          MKM35Z512VLQ7R
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VREF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-08-01)
**         Initial version.
**     - rev. 2.0 (2019-12-20)
**         Based on RM Rev.1.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VREF.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VREF
 *
 * CMSIS Peripheral Access Layer for VREF
 */

#if !defined(PERI_VREF_H_)
#define PERI_VREF_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM35Z256VLL7) || defined(CPU_MKM35Z256VLL7R) || defined(CPU_MKM35Z256VLQ7) || defined(CPU_MKM35Z256VLQ7R) || defined(CPU_MKM35Z512VLL7) || defined(CPU_MKM35Z512VLL7R) || defined(CPU_MKM35Z512VLQ7) || defined(CPU_MKM35Z512VLQ7R))
#include "MKM35Z7_COMMON.h"
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
   -- VREF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Peripheral_Access_Layer VREF Peripheral Access Layer
 * @{
 */

/** VREF - Register Layout Typedef */
typedef struct {
  __IO uint8_t VREFH_TRM;                          /**< VREF Trim Register, offset: 0x0 */
  __IO uint8_t VREFH_SC;                           /**< VREF Status and Control Register, offset: 0x1 */
       uint8_t RESERVED_0[3];
  __IO uint8_t VREFL_TRM;                          /**< VREFL TRIM Register, offset: 0x5 */
} VREF_Type;

/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Register_Masks VREF Register Masks
 * @{
 */

/*! @name VREFH_TRM - VREF Trim Register */
/*! @{ */

#define VREF_VREFH_TRM_TRIM_MASK                 (0x3FU)
#define VREF_VREFH_TRM_TRIM_SHIFT                (0U)
/*! TRIM - Trim bits
 *  0b000000..Min
 *  0b111111..Max
 */
#define VREF_VREFH_TRM_TRIM(x)                   (((uint8_t)(((uint8_t)(x)) << VREF_VREFH_TRM_TRIM_SHIFT)) & VREF_VREFH_TRM_TRIM_MASK)

#define VREF_VREFH_TRM_CHOPEN_MASK               (0x40U)
#define VREF_VREFH_TRM_CHOPEN_SHIFT              (6U)
/*! CHOPEN - Chop oscillator enable. When set, internal chopping operation is enabled and the
 *    internal analog offset will be minimized.
 *  0b0..Chop oscillator is disabled.
 *  0b1..Chop oscillator is enabled.
 */
#define VREF_VREFH_TRM_CHOPEN(x)                 (((uint8_t)(((uint8_t)(x)) << VREF_VREFH_TRM_CHOPEN_SHIFT)) & VREF_VREFH_TRM_CHOPEN_MASK)
/*! @} */

/*! @name VREFH_SC - VREF Status and Control Register */
/*! @{ */

#define VREF_VREFH_SC_MODE_LV_MASK               (0x3U)
#define VREF_VREFH_SC_MODE_LV_SHIFT              (0U)
/*! MODE_LV - Buffer Mode selection
 *  0b00..Bandgap on only, for stabilization and startup
 *  0b01..High power buffer mode enabled
 *  0b10..Low-power buffer mode enabled
 *  0b11..Reserved
 */
#define VREF_VREFH_SC_MODE_LV(x)                 (((uint8_t)(((uint8_t)(x)) << VREF_VREFH_SC_MODE_LV_SHIFT)) & VREF_VREFH_SC_MODE_LV_MASK)

#define VREF_VREFH_SC_VREFST_MASK                (0x4U)
#define VREF_VREFH_SC_VREFST_SHIFT               (2U)
/*! VREFST - Internal Voltage Reference stable
 *  0b0..The module is disabled or not stable.
 *  0b1..The module is stable.
 */
#define VREF_VREFH_SC_VREFST(x)                  (((uint8_t)(((uint8_t)(x)) << VREF_VREFH_SC_VREFST_SHIFT)) & VREF_VREFH_SC_VREFST_MASK)

#define VREF_VREFH_SC_ICOMPEN_MASK               (0x20U)
#define VREF_VREFH_SC_ICOMPEN_SHIFT              (5U)
/*! ICOMPEN - Second order curvature compensation enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define VREF_VREFH_SC_ICOMPEN(x)                 (((uint8_t)(((uint8_t)(x)) << VREF_VREFH_SC_ICOMPEN_SHIFT)) & VREF_VREFH_SC_ICOMPEN_MASK)

#define VREF_VREFH_SC_REGEN_MASK                 (0x40U)
#define VREF_VREFH_SC_REGEN_SHIFT                (6U)
/*! REGEN - Regulator enable
 *  0b0..Internal 1.75 V regulator is disabled.
 *  0b1..Internal 1.75 V regulator is enabled.
 */
#define VREF_VREFH_SC_REGEN(x)                   (((uint8_t)(((uint8_t)(x)) << VREF_VREFH_SC_REGEN_SHIFT)) & VREF_VREFH_SC_REGEN_MASK)

#define VREF_VREFH_SC_VREFEN_MASK                (0x80U)
#define VREF_VREFH_SC_VREFEN_SHIFT               (7U)
/*! VREFEN - Internal Voltage Reference enable
 *  0b0..The module is disabled.
 *  0b1..The module is enabled.
 */
#define VREF_VREFH_SC_VREFEN(x)                  (((uint8_t)(((uint8_t)(x)) << VREF_VREFH_SC_VREFEN_SHIFT)) & VREF_VREFH_SC_VREFEN_MASK)
/*! @} */

/*! @name VREFL_TRM - VREFL TRIM Register */
/*! @{ */

#define VREF_VREFL_TRM_VREFL_TRIM_MASK           (0x7U)
#define VREF_VREFL_TRM_VREFL_TRIM_SHIFT          (0U)
#define VREF_VREFL_TRM_VREFL_TRIM(x)             (((uint8_t)(((uint8_t)(x)) << VREF_VREFL_TRM_VREFL_TRIM_SHIFT)) & VREF_VREFL_TRM_VREFL_TRIM_MASK)

#define VREF_VREFL_TRM_VREFL_EN_MASK             (0x8U)
#define VREF_VREFL_TRM_VREFL_EN_SHIFT            (3U)
/*! VREFL_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VREF_VREFL_TRM_VREFL_EN(x)               (((uint8_t)(((uint8_t)(x)) << VREF_VREFL_TRM_VREFL_EN_SHIFT)) & VREF_VREFL_TRM_VREFL_EN_MASK)

#define VREF_VREFL_TRM_VREFL_SEL_MASK            (0x10U)
#define VREF_VREFL_TRM_VREFL_SEL_SHIFT           (4U)
/*! VREFL_SEL
 *  0b0..Internal reference
 *  0b1..External reference
 */
#define VREF_VREFL_TRM_VREFL_SEL(x)              (((uint8_t)(((uint8_t)(x)) << VREF_VREFL_TRM_VREFL_SEL_SHIFT)) & VREF_VREFL_TRM_VREFL_SEL_MASK)
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


#endif  /* PERI_VREF_H_ */

