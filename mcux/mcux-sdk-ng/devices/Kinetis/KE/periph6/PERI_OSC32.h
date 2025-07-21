/*
** ###################################################################
**     Processors:          MKE14Z128VLH7
**                          MKE14Z128VLL7
**                          MKE14Z256VLH7
**                          MKE14Z256VLL7
**                          MKE15Z128VLH7
**                          MKE15Z128VLL7
**                          MKE15Z256VLH7
**                          MKE15Z256VLL7
**
**     Version:             rev. 7.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OSC32
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-08-19)
**         Initial version.
**     - rev. 2.0 (2015-09-22)
**         Based on rev0final RDP, add PCC/TRGMUX.
**     - rev. 3.0 (2015-12-29)
**         Align LPFLL register names.
**     - rev. 4.0 (2016-02-19)
**         Based on rev1final RDP.
**     - rev. 5.0 (2016-08-02)
**         Based on rev1.x RDP.
**     - rev. 6.0 (2016-09-20)
**         Based on rev2 RDP.
**     - rev. 7.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OSC32.h
 * @version 7.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OSC32
 *
 * CMSIS Peripheral Access Layer for OSC32
 */

#if !defined(PERI_OSC32_H_)
#define PERI_OSC32_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z128VLH7) || defined(CPU_MKE14Z128VLL7) || defined(CPU_MKE14Z256VLH7) || defined(CPU_MKE14Z256VLL7))
#include "MKE14Z7_COMMON.h"
#elif (defined(CPU_MKE15Z128VLH7) || defined(CPU_MKE15Z128VLL7) || defined(CPU_MKE15Z256VLH7) || defined(CPU_MKE15Z256VLL7))
#include "MKE15Z7_COMMON.h"
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
   -- OSC32 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC32_Peripheral_Access_Layer OSC32 Peripheral Access Layer
 * @{
 */

/** OSC32 - Register Layout Typedef */
typedef struct {
  __IO uint8_t CR;                                 /**< RTC Oscillator Control Register, offset: 0x0 */
} OSC32_Type;

/* ----------------------------------------------------------------------------
   -- OSC32 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC32_Register_Masks OSC32 Register Masks
 * @{
 */

/*! @name CR - RTC Oscillator Control Register */
/*! @{ */

#define OSC32_CR_ROSCEREFS_MASK                  (0x10U)
#define OSC32_CR_ROSCEREFS_SHIFT                 (4U)
/*! ROSCEREFS - RTC 32k Oscillator external reference clcok selection
 *  0b0..Bypass mode. RTC oscillator selects the external 32k clock.
 *  0b1..Crystal mode.
 */
#define OSC32_CR_ROSCEREFS(x)                    (((uint8_t)(((uint8_t)(x)) << OSC32_CR_ROSCEREFS_SHIFT)) & OSC32_CR_ROSCEREFS_MASK)

#define OSC32_CR_ROSCSTB_MASK                    (0x20U)
#define OSC32_CR_ROSCSTB_SHIFT                   (5U)
/*! ROSCSTB - RTC 32k Oscillator stable flag
 *  0b0..RTC 32k oscillator is unstable now and no clock will go out of the block.
 *  0b1..RTC 32k oscillator is stable.
 */
#define OSC32_CR_ROSCSTB(x)                      (((uint8_t)(((uint8_t)(x)) << OSC32_CR_ROSCSTB_SHIFT)) & OSC32_CR_ROSCSTB_MASK)

#define OSC32_CR_ROSCSTPEN_MASK                  (0x40U)
#define OSC32_CR_ROSCSTPEN_SHIFT                 (6U)
/*! ROSCSTPEN - RTC 32k Oscillator stop mode enable
 *  0b0..Oscillator is disabled regardless the state of ROSCEN.
 *  0b1..Oscillator is enabled in Stop mode when ROSCEN is set.
 */
#define OSC32_CR_ROSCSTPEN(x)                    (((uint8_t)(((uint8_t)(x)) << OSC32_CR_ROSCSTPEN_SHIFT)) & OSC32_CR_ROSCSTPEN_MASK)

#define OSC32_CR_ROSCEN_MASK                     (0x80U)
#define OSC32_CR_ROSCEN_SHIFT                    (7U)
/*! ROSCEN - RTC 32k Oscillator enable
 *  0b0..Oscillator is disabled.
 *  0b1..Oscillator is enabled.
 */
#define OSC32_CR_ROSCEN(x)                       (((uint8_t)(((uint8_t)(x)) << OSC32_CR_ROSCEN_SHIFT)) & OSC32_CR_ROSCEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSC32_Register_Masks */


/*!
 * @}
 */ /* end of group OSC32_Peripheral_Access_Layer */


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


#endif  /* PERI_OSC32_H_ */

