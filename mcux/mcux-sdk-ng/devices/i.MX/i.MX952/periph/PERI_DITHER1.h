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
**         CMSIS Peripheral Access Layer for dither1
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
 * @file PERI_dither1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for dither1
 *
 * CMSIS Peripheral Access Layer for dither1
 */

#if !defined(PERI_DITHER1_H_)
#define PERI_DITHER1_H_                          /**< Symbol preventing repeated inclusion */

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
   -- dither1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup dither1_Peripheral_Access_Layer dither1 Peripheral Access Layer
 * @{
 */

/** dither1 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x8 */
  __IO uint32_t MASKSTAR;                          /**< MaskStart, offset: 0xC */
  __IO uint32_t MASKSIZE;                          /**< MaskSize, offset: 0x10 */
  __IO uint32_t DITCON10;                          /**< DitherControl10bits, offset: 0x14 */
  __IO uint32_t DITCON12;                          /**< DitherControl12bits, offset: 0x18 */
} dither1_Type;

/* ----------------------------------------------------------------------------
   -- dither1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup dither1_Register_Masks dither1 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define dither1_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define dither1_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define dither1_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << dither1_LU_LkUn_SHIFT)) & dither1_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define dither1_LOCKS_LkSus_MASK                 (0x1U)
#define dither1_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define dither1_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << dither1_LOCKS_LkSus_SHIFT)) & dither1_LOCKS_LkSus_MASK)

#define dither1_LOCKS_PriSt_MASK                 (0x10U)
#define dither1_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define dither1_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << dither1_LOCKS_PriSt_SHIFT)) & dither1_LOCKS_PriSt_MASK)

#define dither1_LOCKS_FreezeS_MASK               (0x100U)
#define dither1_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define dither1_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << dither1_LOCKS_FreezeS_SHIFT)) & dither1_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define dither1_CONTR_mode_MASK                  (0x3U)
#define dither1_CONTR_mode_SHIFT                 (0U)
/*! mode - mode
 *  0b00..Neutral mode. Pixels by-pass the Dither Unit, all other settings are ignored.
 *  0b01..Dither Unit is active (uses 10bit input).
 *  0b10..Dither Unit is active (uses 12bit input).
 */
#define dither1_CONTR_mode(x)                    (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_mode_SHIFT)) & dither1_CONTR_mode_MASK)

#define dither1_CONTR_offstsel_MASK              (0x10000U)
#define dither1_CONTR_offstsel_SHIFT             (16U)
/*! offstsel - offset_select
 *  0b0..Offset is a bayer matrix value, which is selected according to pixel frame position.
 *  0b1..Offset is the sum from a bayer matrix value, which is selected according to pixel frame position, and a
 *       value from a regular sequence, which changes each frame.
 */
#define dither1_CONTR_offstsel(x)                (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_offstsel_SHIFT)) & dither1_CONTR_offstsel_MASK)

#define dither1_CONTR_algosel_MASK               (0x300000U)
#define dither1_CONTR_algosel_SHIFT              (20U)
/*! algosel - algo_select
 *  0b01..Best possible resolution for most dark colors. Adds a diminutive offset to overall image brightness.
 *  0b10..Preserves overall image brightness. Cannot resolve most dark and most bright colors. All codes in-between are distributed perfectly smooth.
 *  0b11..Preserves overall image brightness. Best possible distribution of color codes over complete range.
 */
#define dither1_CONTR_algosel(x)                 (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_algosel_SHIFT)) & dither1_CONTR_algosel_MASK)

#define dither1_CONTR_makinen_MASK               (0x1000000U)
#define dither1_CONTR_makinen_SHIFT              (24U)
/*! makinen - maskin_en
 *  0b0..disable external masking.
 *  0b1..enable external masking.
 */
#define dither1_CONTR_makinen(x)                 (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_makinen_SHIFT)) & dither1_CONTR_makinen_MASK)

#define dither1_CONTR_makinsel_MASK              (0x2000000U)
#define dither1_CONTR_makinsel_SHIFT             (25U)
/*! makinsel - maskin_sel
 *  0b0..mask signal 0 is used.
 *  0b1..mask signal 1 is used.
 */
#define dither1_CONTR_makinsel(x)                (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_makinsel_SHIFT)) & dither1_CONTR_makinsel_MASK)

#define dither1_CONTR_makininv_MASK              (0x4000000U)
#define dither1_CONTR_makininv_SHIFT             (26U)
/*! makininv - maskin_inv
 *  0b0..bypassed when the related mask input signal is high.
 *  0b1..bypassed when the related mask input signal is low.
 */
#define dither1_CONTR_makininv(x)                (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_makininv_SHIFT)) & dither1_CONTR_makininv_MASK)

#define dither1_CONTR_pxwinon0_MASK              (0x10000000U)
#define dither1_CONTR_pxwinon0_SHIFT             (28U)
/*! pxwinon0 - pixwinon
 *  0b0..disable internal masking.
 *  0b1..enable internal masking.
 */
#define dither1_CONTR_pxwinon0(x)                (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_pxwinon0_SHIFT)) & dither1_CONTR_pxwinon0_MASK)

#define dither1_CONTR_pxwininv_MASK              (0x20000000U)
#define dither1_CONTR_pxwininv_SHIFT             (29U)
/*! pxwininv - pixwin_inv
 *  0b0..input pixels inside the defined window will be bypassed.
 *  0b1..input pixels outside the defined window will be bypassed.
 */
#define dither1_CONTR_pxwininv(x)                (((uint32_t)(((uint32_t)(x)) << dither1_CONTR_pxwininv_SHIFT)) & dither1_CONTR_pxwininv_MASK)
/*! @} */

/*! @name MASKSTAR - MaskStart */
/*! @{ */

#define dither1_MASKSTAR_passvst_MASK            (0x3FFFU)
#define dither1_MASKSTAR_passvst_SHIFT           (0U)
/*! passvst - pass_vstart */
#define dither1_MASKSTAR_passvst(x)              (((uint32_t)(((uint32_t)(x)) << dither1_MASKSTAR_passvst_SHIFT)) & dither1_MASKSTAR_passvst_MASK)

#define dither1_MASKSTAR_passhst_MASK            (0x3FFF0000U)
#define dither1_MASKSTAR_passhst_SHIFT           (16U)
/*! passhst - pass_hstart */
#define dither1_MASKSTAR_passhst(x)              (((uint32_t)(((uint32_t)(x)) << dither1_MASKSTAR_passhst_SHIFT)) & dither1_MASKSTAR_passhst_MASK)
/*! @} */

/*! @name MASKSIZE - MaskSize */
/*! @{ */

#define dither1_MASKSIZE_passvsi_MASK            (0x3FFFU)
#define dither1_MASKSIZE_passvsi_SHIFT           (0U)
/*! passvsi - pass_vsize */
#define dither1_MASKSIZE_passvsi(x)              (((uint32_t)(((uint32_t)(x)) << dither1_MASKSIZE_passvsi_SHIFT)) & dither1_MASKSIZE_passvsi_MASK)

#define dither1_MASKSIZE_passhsi_MASK            (0x3FFF0000U)
#define dither1_MASKSIZE_passhsi_SHIFT           (16U)
/*! passhsi - pass_hsize */
#define dither1_MASKSIZE_passhsi(x)              (((uint32_t)(((uint32_t)(x)) << dither1_MASKSIZE_passhsi_SHIFT)) & dither1_MASKSIZE_passhsi_MASK)
/*! @} */

/*! @name DITCON10 - DitherControl10bits */
/*! @{ */

#define dither1_DITCON10_bluers10_MASK           (0x7U)
#define dither1_DITCON10_bluers10_SHIFT          (0U)
/*! bluers10 - blue_range_select_10bit
 *  0b010..Reduces blue component width from 10 bit to 8bit.
 *  0b011..Reduces blue component width from 10 bit to 7bit.
 *  0b100..Reduces blue component width from 10 bit to 6bit.
 *  0b101..Reduces blue component width from 10 bit to 5bit.
 */
#define dither1_DITCON10_bluers10(x)             (((uint32_t)(((uint32_t)(x)) << dither1_DITCON10_bluers10_SHIFT)) & dither1_DITCON10_bluers10_MASK)

#define dither1_DITCON10_greers10_MASK           (0x70U)
#define dither1_DITCON10_greers10_SHIFT          (4U)
/*! greers10 - green_range_select_10bit
 *  0b010..Reduces green component width from 10 bit to 8bit.
 *  0b011..Reduces green component width from 10 bit to 7bit.
 *  0b100..Reduces green component width from 10 bit to 6bit.
 *  0b101..Reduces green component width from 10 bit to 5bit.
 */
#define dither1_DITCON10_greers10(x)             (((uint32_t)(((uint32_t)(x)) << dither1_DITCON10_greers10_SHIFT)) & dither1_DITCON10_greers10_MASK)

#define dither1_DITCON10_rranse10_MASK           (0x700U)
#define dither1_DITCON10_rranse10_SHIFT          (8U)
/*! rranse10 - red_range_select_10bit
 *  0b010..Reduces red component width from 10 bit to 8bit.
 *  0b011..Reduces red component width from 10 bit to 7bit.
 *  0b100..Reduces red component width from 10 bit to 6bit.
 *  0b101..Reduces red component width from 10 bit to 5bit.
 */
#define dither1_DITCON10_rranse10(x)             (((uint32_t)(((uint32_t)(x)) << dither1_DITCON10_rranse10_SHIFT)) & dither1_DITCON10_rranse10_MASK)
/*! @} */

/*! @name DITCON12 - DitherControl12bits */
/*! @{ */

#define dither1_DITCON12_bluers12_MASK           (0x7U)
#define dither1_DITCON12_bluers12_SHIFT          (0U)
/*! bluers12 - blue_range_select_12bit
 *  0b010..Reduces blue component width from 12 bit to 10bit.
 *  0b011..Reduces blue component width from 12 bit to 9bit.
 *  0b100..Reduces blue component width from 12 bit to 8bit.
 *  0b110..Reduces blue component width from 12 bit to 6bit.
 */
#define dither1_DITCON12_bluers12(x)             (((uint32_t)(((uint32_t)(x)) << dither1_DITCON12_bluers12_SHIFT)) & dither1_DITCON12_bluers12_MASK)

#define dither1_DITCON12_greers12_MASK           (0x70U)
#define dither1_DITCON12_greers12_SHIFT          (4U)
/*! greers12 - green_range_select_12bit
 *  0b010..Reduces green component width from 12 bit to 10bit.
 *  0b011..Reduces green component width from 12 bit to 9bit.
 *  0b100..Reduces green component width from 12 bit to 8bit.
 *  0b110..Reduces green component width from 12 bit to 6bit.
 */
#define dither1_DITCON12_greers12(x)             (((uint32_t)(((uint32_t)(x)) << dither1_DITCON12_greers12_SHIFT)) & dither1_DITCON12_greers12_MASK)

#define dither1_DITCON12_rranse12_MASK           (0x700U)
#define dither1_DITCON12_rranse12_SHIFT          (8U)
/*! rranse12 - red_range_select_12bit
 *  0b010..Reduces red component width from 12 bit to 10bit.
 *  0b011..Reduces red component width from 12 bit to 9bit.
 *  0b100..Reduces red component width from 12 bit to 8bit.
 *  0b110..Reduces red component width from 12 bit to 6bit.
 */
#define dither1_DITCON12_rranse12(x)             (((uint32_t)(((uint32_t)(x)) << dither1_DITCON12_rranse12_SHIFT)) & dither1_DITCON12_rranse12_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group dither1_Register_Masks */


/*!
 * @}
 */ /* end of group dither1_Peripheral_Access_Layer */


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


#endif  /* PERI_DITHER1_H_ */

