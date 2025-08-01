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
**         CMSIS Peripheral Access Layer for KBI
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
 * @file PERI_KBI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for KBI
 *
 * CMSIS Peripheral Access Layer for KBI
 */

#if !defined(PERI_KBI_H_)
#define PERI_KBI_H_                              /**< Symbol preventing repeated inclusion */

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
   -- KBI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KBI_Peripheral_Access_Layer KBI Peripheral Access Layer
 * @{
 */

/** KBI - Register Layout Typedef */
typedef struct {
  __IO uint8_t SC;                                 /**< KBI Status and Control Register, offset: 0x0 */
  __IO uint8_t PE;                                 /**< KBI Pin Enable Register, offset: 0x1 */
  __IO uint8_t ES;                                 /**< KBI Edge Select Register, offset: 0x2 */
} KBI_Type;

/* ----------------------------------------------------------------------------
   -- KBI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KBI_Register_Masks KBI Register Masks
 * @{
 */

/*! @name SC - KBI Status and Control Register */
/*! @{ */

#define KBI_SC_KBMOD_MASK                        (0x1U)
#define KBI_SC_KBMOD_SHIFT                       (0U)
/*! KBMOD - KBI Detection Mode
 *  0b0..Keyboard detects edges only.
 *  0b1..Keyboard detects both edges and levels.
 */
#define KBI_SC_KBMOD(x)                          (((uint8_t)(((uint8_t)(x)) << KBI_SC_KBMOD_SHIFT)) & KBI_SC_KBMOD_MASK)

#define KBI_SC_KBIE_MASK                         (0x2U)
#define KBI_SC_KBIE_SHIFT                        (1U)
/*! KBIE - KBI Interrupt Enable
 *  0b0..KBI interrupt not enabled.
 *  0b1..KBI interrupt enabled.
 */
#define KBI_SC_KBIE(x)                           (((uint8_t)(((uint8_t)(x)) << KBI_SC_KBIE_SHIFT)) & KBI_SC_KBIE_MASK)

#define KBI_SC_KBACK_MASK                        (0x4U)
#define KBI_SC_KBACK_SHIFT                       (2U)
/*! KBACK - KBI Acknowledge */
#define KBI_SC_KBACK(x)                          (((uint8_t)(((uint8_t)(x)) << KBI_SC_KBACK_SHIFT)) & KBI_SC_KBACK_MASK)

#define KBI_SC_KBF_MASK                          (0x8U)
#define KBI_SC_KBF_SHIFT                         (3U)
/*! KBF - KBI Interrupt Flag
 *  0b0..KBI interrupt request not detected.
 *  0b1..KBI interrupt request detected.
 */
#define KBI_SC_KBF(x)                            (((uint8_t)(((uint8_t)(x)) << KBI_SC_KBF_SHIFT)) & KBI_SC_KBF_MASK)
/*! @} */

/*! @name PE - KBI Pin Enable Register */
/*! @{ */

#define KBI_PE_KBIPE_MASK                        (0xFFU)
#define KBI_PE_KBIPE_SHIFT                       (0U)
/*! KBIPE - KBI Pin Enables
 *  0b00000000..Pin is not enabled as KBI interrupt.
 *  0b00000001..Pin is enabled as KBI interrupt.
 */
#define KBI_PE_KBIPE(x)                          (((uint8_t)(((uint8_t)(x)) << KBI_PE_KBIPE_SHIFT)) & KBI_PE_KBIPE_MASK)
/*! @} */

/*! @name ES - KBI Edge Select Register */
/*! @{ */

#define KBI_ES_KBEDG_MASK                        (0xFFU)
#define KBI_ES_KBEDG_SHIFT                       (0U)
/*! KBEDG - KBI Edge Selects
 *  0b00000000..Falling edge/low level.
 *  0b00000001..Rising edge/high level.
 */
#define KBI_ES_KBEDG(x)                          (((uint8_t)(((uint8_t)(x)) << KBI_ES_KBEDG_SHIFT)) & KBI_ES_KBEDG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group KBI_Register_Masks */


/*!
 * @}
 */ /* end of group KBI_Peripheral_Access_Layer */


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


#endif  /* PERI_KBI_H_ */

