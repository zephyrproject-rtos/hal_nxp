/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for hscaler
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_hscaler.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for hscaler
 *
 * CMSIS Peripheral Access Layer for hscaler
 */

#if !defined(PERI_HSCALER_H_)
#define PERI_HSCALER_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- hscaler Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup hscaler_Peripheral_Access_Layer hscaler Peripheral Access Layer
 * @{
 */

/** hscaler - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t SETUP1;                            /**< Setup1, offset: 0xC */
  __IO uint32_t SETUP2;                            /**< Setup2, offset: 0x10 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x14 */
} hscaler_Type;

/* ----------------------------------------------------------------------------
   -- hscaler Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup hscaler_Register_Masks hscaler Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define hscaler_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define hscaler_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define hscaler_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << hscaler_LU_LkUn_SHIFT)) & hscaler_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define hscaler_LOCKS_LkSus_MASK                 (0x1U)
#define hscaler_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define hscaler_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << hscaler_LOCKS_LkSus_SHIFT)) & hscaler_LOCKS_LkSus_MASK)

#define hscaler_LOCKS_PriSt_MASK                 (0x10U)
#define hscaler_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define hscaler_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << hscaler_LOCKS_PriSt_SHIFT)) & hscaler_LOCKS_PriSt_MASK)

#define hscaler_LOCKS_FreezeS_MASK               (0x100U)
#define hscaler_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define hscaler_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << hscaler_LOCKS_FreezeS_SHIFT)) & hscaler_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define hscaler_STATCON_ShdEn_MASK               (0x1U)
#define hscaler_STATCON_ShdEn_SHIFT              (0U)
/*! ShdEn - ShdEn */
#define hscaler_STATCON_ShdEn(x)                 (((uint32_t)(((uint32_t)(x)) << hscaler_STATCON_ShdEn_SHIFT)) & hscaler_STATCON_ShdEn_MASK)
/*! @} */

/*! @name SETUP1 - Setup1 */
/*! @{ */

#define hscaler_SETUP1_scalefac_MASK             (0xFFFFFU)
#define hscaler_SETUP1_scalefac_SHIFT            (0U)
/*! scalefac - scale_factor */
#define hscaler_SETUP1_scalefac(x)               (((uint32_t)(((uint32_t)(x)) << hscaler_SETUP1_scalefac_SHIFT)) & hscaler_SETUP1_scalefac_MASK)
/*! @} */

/*! @name SETUP2 - Setup2 */
/*! @{ */

#define hscaler_SETUP2_phaseoff_MASK             (0x1FFFFFU)
#define hscaler_SETUP2_phaseoff_SHIFT            (0U)
/*! phaseoff - phase_offset */
#define hscaler_SETUP2_phaseoff(x)               (((uint32_t)(((uint32_t)(x)) << hscaler_SETUP2_phaseoff_SHIFT)) & hscaler_SETUP2_phaseoff_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define hscaler_CONTR_mode_MASK                  (0x1U)
#define hscaler_CONTR_mode_SHIFT                 (0U)
/*! mode - mode
 *  0b0..Neutral mode. Pixels by-pass the scaler, all other settings are ignored.
 *  0b1..Scaler is active.
 */
#define hscaler_CONTR_mode(x)                    (((uint32_t)(((uint32_t)(x)) << hscaler_CONTR_mode_SHIFT)) & hscaler_CONTR_mode_MASK)

#define hscaler_CONTR_scalemod_MASK              (0x10U)
#define hscaler_CONTR_scalemod_SHIFT             (4U)
/*! scalemod - scale_mode
 *  0b0..Down-scaling (output size less or equal input size).
 *  0b1..Up-scaling (output size greater or equal input size)
 */
#define hscaler_CONTR_scalemod(x)                (((uint32_t)(((uint32_t)(x)) << hscaler_CONTR_scalemod_SHIFT)) & hscaler_CONTR_scalemod_MASK)

#define hscaler_CONTR_filmode_MASK               (0x100U)
#define hscaler_CONTR_filmode_SHIFT              (8U)
/*! filmode - filter_mode
 *  0b0..Nearest filter (point-sampling)
 *  0b1..Box filter (linear)
 */
#define hscaler_CONTR_filmode(x)                 (((uint32_t)(((uint32_t)(x)) << hscaler_CONTR_filmode_SHIFT)) & hscaler_CONTR_filmode_MASK)

#define hscaler_CONTR_outpsize_MASK              (0x3FFF0000U)
#define hscaler_CONTR_outpsize_SHIFT             (16U)
/*! outpsize - output_size */
#define hscaler_CONTR_outpsize(x)                (((uint32_t)(((uint32_t)(x)) << hscaler_CONTR_outpsize_SHIFT)) & hscaler_CONTR_outpsize_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group hscaler_Register_Masks */


/*!
 * @}
 */ /* end of group hscaler_Peripheral_Access_Layer */


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


#endif  /* PERI_HSCALER_H_ */

