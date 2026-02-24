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
**         CMSIS Peripheral Access Layer for lut3d2
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
 * @file PERI_lut3d2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for lut3d2
 *
 * CMSIS Peripheral Access Layer for lut3d2
 */

#if !defined(PERI_LUT3D2_H_)
#define PERI_LUT3D2_H_                           /**< Symbol preventing repeated inclusion */

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
   -- lut3d2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup lut3d2_Peripheral_Access_Layer lut3d2 Peripheral Access Layer
 * @{
 */

/** lut3d2 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __IO uint32_t MASKSTAR;                          /**< MaskStart, offset: 0x10 */
  __IO uint32_t MASKSIZE;                          /**< MaskSize, offset: 0x14 */
} lut3d2_Type;

/* ----------------------------------------------------------------------------
   -- lut3d2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup lut3d2_Register_Masks lut3d2 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define lut3d2_LU_LkUn_MASK                      (0xFFFFFFFFU)
#define lut3d2_LU_LkUn_SHIFT                     (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define lut3d2_LU_LkUn(x)                        (((uint32_t)(((uint32_t)(x)) << lut3d2_LU_LkUn_SHIFT)) & lut3d2_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define lut3d2_LOCKS_LkSus_MASK                  (0x1U)
#define lut3d2_LOCKS_LkSus_SHIFT                 (0U)
/*! LkSus - LockStatus */
#define lut3d2_LOCKS_LkSus(x)                    (((uint32_t)(((uint32_t)(x)) << lut3d2_LOCKS_LkSus_SHIFT)) & lut3d2_LOCKS_LkSus_MASK)

#define lut3d2_LOCKS_PriSt_MASK                  (0x10U)
#define lut3d2_LOCKS_PriSt_SHIFT                 (4U)
/*! PriSt - PrivilegeStatus */
#define lut3d2_LOCKS_PriSt(x)                    (((uint32_t)(((uint32_t)(x)) << lut3d2_LOCKS_PriSt_SHIFT)) & lut3d2_LOCKS_PriSt_MASK)

#define lut3d2_LOCKS_FreezeS_MASK                (0x100U)
#define lut3d2_LOCKS_FreezeS_SHIFT               (8U)
/*! FreezeS - FreezeStatus */
#define lut3d2_LOCKS_FreezeS(x)                  (((uint32_t)(((uint32_t)(x)) << lut3d2_LOCKS_FreezeS_SHIFT)) & lut3d2_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define lut3d2_STATCON_ShdEn_MASK                (0x1U)
#define lut3d2_STATCON_ShdEn_SHIFT               (0U)
/*! ShdEn - ShdEn */
#define lut3d2_STATCON_ShdEn(x)                  (((uint32_t)(((uint32_t)(x)) << lut3d2_STATCON_ShdEn_SHIFT)) & lut3d2_STATCON_ShdEn_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define lut3d2_CONTR_MODE2_MASK                  (0x7U)
#define lut3d2_CONTR_MODE2_SHIFT                 (0U)
/*! MODE2 - MODE
 *  0b000..Module in neutral mode, RGBA input data is bypassed to the output unchanged.
 *  0b001..LUT operates in 3D mode.
 *  0b010..Each RGB input is used as individual index into the respective LUT. Alpha channel is bypassed to output.
 *  0b011..Red input is used as common index for any RGB LUT. The alpha channel is bypassed to output.
 *  0b100..Red input is used as common index for any RGB LUT. The result is remapped and upconverted to RGBA.
 */
#define lut3d2_CONTR_MODE2(x)                    (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_MODE2_SHIFT)) & lut3d2_CONTR_MODE2_MASK)

#define lut3d2_CONTR_DITHEN_MASK                 (0x8U)
#define lut3d2_CONTR_DITHEN_SHIFT                (3U)
/*! DITHEN - DITH_EN
 *  0b0..Output 12bit.
 *  0b1..Dither output to 10bit, only recommended if next module uses 10 MSB bit.
 */
#define lut3d2_CONTR_DITHEN(x)                   (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_DITHEN_SHIFT)) & lut3d2_CONTR_DITHEN_MASK)

#define lut3d2_CONTR_IDXBITS_MASK                (0xF00U)
#define lut3d2_CONTR_IDXBITS_SHIFT               (8U)
/*! IDXBITS - IDX_BITS */
#define lut3d2_CONTR_IDXBITS(x)                  (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_IDXBITS_SHIFT)) & lut3d2_CONTR_IDXBITS_MASK)

#define lut3d2_CONTR_makinen_MASK                (0x1000000U)
#define lut3d2_CONTR_makinen_SHIFT               (24U)
/*! makinen - maskin_en
 *  0b0..Disable external masking.
 *  0b1..Enable external masking.
 */
#define lut3d2_CONTR_makinen(x)                  (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_makinen_SHIFT)) & lut3d2_CONTR_makinen_MASK)

#define lut3d2_CONTR_makinsel_MASK               (0x2000000U)
#define lut3d2_CONTR_makinsel_SHIFT              (25U)
/*! makinsel - maskin_sel
 *  0b0..mask signal 0 is used.
 *  0b1..mask signal 1 is used.
 */
#define lut3d2_CONTR_makinsel(x)                 (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_makinsel_SHIFT)) & lut3d2_CONTR_makinsel_MASK)

#define lut3d2_CONTR_makininv_MASK               (0x4000000U)
#define lut3d2_CONTR_makininv_SHIFT              (26U)
/*! makininv - maskin_inv
 *  0b0..Bypassed when the related mask input signal is high.
 *  0b1..Bypassed when the related mask input signal is low.
 */
#define lut3d2_CONTR_makininv(x)                 (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_makininv_SHIFT)) & lut3d2_CONTR_makininv_MASK)

#define lut3d2_CONTR_pxwinon_MASK                (0x10000000U)
#define lut3d2_CONTR_pxwinon_SHIFT               (28U)
/*! pxwinon - pixwin_on
 *  0b0..Disable internal masking.
 *  0b1..Enable internal masking.
 */
#define lut3d2_CONTR_pxwinon(x)                  (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_pxwinon_SHIFT)) & lut3d2_CONTR_pxwinon_MASK)

#define lut3d2_CONTR_pxwininv_MASK               (0x20000000U)
#define lut3d2_CONTR_pxwininv_SHIFT              (29U)
/*! pxwininv - pixwin_inv
 *  0b0..Input pixels inside the defined window will be bypassed.
 *  0b1..Input pixels outside the defined window will be bypassed.
 */
#define lut3d2_CONTR_pxwininv(x)                 (((uint32_t)(((uint32_t)(x)) << lut3d2_CONTR_pxwininv_SHIFT)) & lut3d2_CONTR_pxwininv_MASK)
/*! @} */

/*! @name MASKSTAR - MaskStart */
/*! @{ */

#define lut3d2_MASKSTAR_passvst_MASK             (0x3FFFU)
#define lut3d2_MASKSTAR_passvst_SHIFT            (0U)
/*! passvst - pass_vstart */
#define lut3d2_MASKSTAR_passvst(x)               (((uint32_t)(((uint32_t)(x)) << lut3d2_MASKSTAR_passvst_SHIFT)) & lut3d2_MASKSTAR_passvst_MASK)

#define lut3d2_MASKSTAR_passhst_MASK             (0x3FFF0000U)
#define lut3d2_MASKSTAR_passhst_SHIFT            (16U)
/*! passhst - pass_hstart */
#define lut3d2_MASKSTAR_passhst(x)               (((uint32_t)(((uint32_t)(x)) << lut3d2_MASKSTAR_passhst_SHIFT)) & lut3d2_MASKSTAR_passhst_MASK)
/*! @} */

/*! @name MASKSIZE - MaskSize */
/*! @{ */

#define lut3d2_MASKSIZE_passvsi_MASK             (0x3FFFU)
#define lut3d2_MASKSIZE_passvsi_SHIFT            (0U)
/*! passvsi - pass_vsize */
#define lut3d2_MASKSIZE_passvsi(x)               (((uint32_t)(((uint32_t)(x)) << lut3d2_MASKSIZE_passvsi_SHIFT)) & lut3d2_MASKSIZE_passvsi_MASK)

#define lut3d2_MASKSIZE_passhsi_MASK             (0x3FFF0000U)
#define lut3d2_MASKSIZE_passhsi_SHIFT            (16U)
/*! passhsi - pass_hsize */
#define lut3d2_MASKSIZE_passhsi(x)               (((uint32_t)(((uint32_t)(x)) << lut3d2_MASKSIZE_passhsi_SHIFT)) & lut3d2_MASKSIZE_passhsi_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group lut3d2_Register_Masks */


/*!
 * @}
 */ /* end of group lut3d2_Peripheral_Access_Layer */


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


#endif  /* PERI_LUT3D2_H_ */

