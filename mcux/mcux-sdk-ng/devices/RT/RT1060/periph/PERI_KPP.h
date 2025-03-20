/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 1.4, 2022-03-25
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for KPP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**
** ###################################################################
*/

/*!
 * @file KPP.h
 * @version 1.4
 * @date 2022-03-25
 * @brief CMSIS Peripheral Access Layer for KPP
 *
 * CMSIS Peripheral Access Layer for KPP
 */

#if !defined(KPP_H_)
#define KPP_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
   -- KPP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KPP_Peripheral_Access_Layer KPP Peripheral Access Layer
 * @{
 */

/** KPP - Register Layout Typedef */
typedef struct {
  __IO uint16_t KPCR;                              /**< Keypad Control Register, offset: 0x0 */
  __IO uint16_t KPSR;                              /**< Keypad Status Register, offset: 0x2 */
  __IO uint16_t KDDR;                              /**< Keypad Data Direction Register, offset: 0x4 */
  __IO uint16_t KPDR;                              /**< Keypad Data Register, offset: 0x6 */
} KPP_Type;

/* ----------------------------------------------------------------------------
   -- KPP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KPP_Register_Masks KPP Register Masks
 * @{
 */

/*! @name KPCR - Keypad Control Register */
/*! @{ */

#define KPP_KPCR_KRE_MASK                        (0xFFU)
#define KPP_KPCR_KRE_SHIFT                       (0U)
/*! KRE - KRE
 *  0b00000000..Row is not included in the keypad key press detect.
 *  0b00000001..Row is included in the keypad key press detect.
 */
#define KPP_KPCR_KRE(x)                          (((uint16_t)(((uint16_t)(x)) << KPP_KPCR_KRE_SHIFT)) & KPP_KPCR_KRE_MASK)

#define KPP_KPCR_KCO_MASK                        (0xFF00U)
#define KPP_KPCR_KCO_SHIFT                       (8U)
/*! KCO - KCO
 *  0b00000000..Column strobe output is totem pole drive.
 *  0b00000001..Column strobe output is open drain.
 */
#define KPP_KPCR_KCO(x)                          (((uint16_t)(((uint16_t)(x)) << KPP_KPCR_KCO_SHIFT)) & KPP_KPCR_KCO_MASK)
/*! @} */

/*! @name KPSR - Keypad Status Register */
/*! @{ */

#define KPP_KPSR_KPKD_MASK                       (0x1U)
#define KPP_KPSR_KPKD_SHIFT                      (0U)
/*! KPKD - KPKD
 *  0b0..No key presses detected
 *  0b1..A key has been depressed
 */
#define KPP_KPSR_KPKD(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KPSR_KPKD_SHIFT)) & KPP_KPSR_KPKD_MASK)

#define KPP_KPSR_KPKR_MASK                       (0x2U)
#define KPP_KPSR_KPKR_SHIFT                      (1U)
/*! KPKR - KPKR
 *  0b0..No key release detected
 *  0b1..All keys have been released
 */
#define KPP_KPSR_KPKR(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KPSR_KPKR_SHIFT)) & KPP_KPSR_KPKR_MASK)

#define KPP_KPSR_KDSC_MASK                       (0x4U)
#define KPP_KPSR_KDSC_SHIFT                      (2U)
/*! KDSC - KDSC
 *  0b0..No effect
 *  0b1..Set bits that clear the keypad depress synchronizer chain
 */
#define KPP_KPSR_KDSC(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KPSR_KDSC_SHIFT)) & KPP_KPSR_KDSC_MASK)

#define KPP_KPSR_KRSS_MASK                       (0x8U)
#define KPP_KPSR_KRSS_SHIFT                      (3U)
/*! KRSS - KRSS
 *  0b0..No effect
 *  0b1..Set bits which sets keypad release synchronizer chain
 */
#define KPP_KPSR_KRSS(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KPSR_KRSS_SHIFT)) & KPP_KPSR_KRSS_MASK)

#define KPP_KPSR_KDIE_MASK                       (0x100U)
#define KPP_KPSR_KDIE_SHIFT                      (8U)
/*! KDIE - KDIE
 *  0b0..No interrupt request is generated when KPKD is set.
 *  0b1..An interrupt request is generated when KPKD is set.
 */
#define KPP_KPSR_KDIE(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KPSR_KDIE_SHIFT)) & KPP_KPSR_KDIE_MASK)

#define KPP_KPSR_KRIE_MASK                       (0x200U)
#define KPP_KPSR_KRIE_SHIFT                      (9U)
/*! KRIE - KRIE
 *  0b0..No interrupt request is generated when KPKR is set.
 *  0b1..An interrupt request is generated when KPKR is set.
 */
#define KPP_KPSR_KRIE(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KPSR_KRIE_SHIFT)) & KPP_KPSR_KRIE_MASK)
/*! @} */

/*! @name KDDR - Keypad Data Direction Register */
/*! @{ */

#define KPP_KDDR_KRDD_MASK                       (0xFFU)
#define KPP_KDDR_KRDD_SHIFT                      (0U)
/*! KRDD - KRDD
 *  0b00000000..ROWn pin configured as an input.
 *  0b00000001..ROWn pin configured as an output.
 */
#define KPP_KDDR_KRDD(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KDDR_KRDD_SHIFT)) & KPP_KDDR_KRDD_MASK)

#define KPP_KDDR_KCDD_MASK                       (0xFF00U)
#define KPP_KDDR_KCDD_SHIFT                      (8U)
/*! KCDD - KCDD
 *  0b00000000..COLn pin is configured as an input.
 *  0b00000001..COLn pin is configured as an output.
 */
#define KPP_KDDR_KCDD(x)                         (((uint16_t)(((uint16_t)(x)) << KPP_KDDR_KCDD_SHIFT)) & KPP_KDDR_KCDD_MASK)
/*! @} */

/*! @name KPDR - Keypad Data Register */
/*! @{ */

#define KPP_KPDR_KRD_MASK                        (0xFFU)
#define KPP_KPDR_KRD_SHIFT                       (0U)
/*! KRD - KRD */
#define KPP_KPDR_KRD(x)                          (((uint16_t)(((uint16_t)(x)) << KPP_KPDR_KRD_SHIFT)) & KPP_KPDR_KRD_MASK)

#define KPP_KPDR_KCD_MASK                        (0xFF00U)
#define KPP_KPDR_KCD_SHIFT                       (8U)
/*! KCD - KCD */
#define KPP_KPDR_KCD(x)                          (((uint16_t)(((uint16_t)(x)) << KPP_KPDR_KCD_SHIFT)) & KPP_KPDR_KCD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group KPP_Register_Masks */


/*!
 * @}
 */ /* end of group KPP_Peripheral_Access_Layer */


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


#endif  /* KPP_H_ */

