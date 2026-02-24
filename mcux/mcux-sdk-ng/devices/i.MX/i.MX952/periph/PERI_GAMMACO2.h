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
**         CMSIS Peripheral Access Layer for gammaco2
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
 * @file PERI_gammaco2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for gammaco2
 *
 * CMSIS Peripheral Access Layer for gammaco2
 */

#if !defined(PERI_GAMMACO2_H_)
#define PERI_GAMMACO2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- gammaco2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup gammaco2_Peripheral_Access_Layer gammaco2 Peripheral Access Layer
 * @{
 */

/** gammaco2 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __IO uint32_t MASKSTAR;                          /**< MaskStart, offset: 0x10 */
  __IO uint32_t MASKSIZE;                          /**< MaskSize, offset: 0x14 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0x18 */
} gammaco2_Type;

/* ----------------------------------------------------------------------------
   -- gammaco2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup gammaco2_Register_Masks gammaco2 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define gammaco2_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define gammaco2_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define gammaco2_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << gammaco2_LU_LkUn_SHIFT)) & gammaco2_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define gammaco2_LOCKS_LkSus_MASK                (0x1U)
#define gammaco2_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define gammaco2_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << gammaco2_LOCKS_LkSus_SHIFT)) & gammaco2_LOCKS_LkSus_MASK)

#define gammaco2_LOCKS_PriSt_MASK                (0x10U)
#define gammaco2_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define gammaco2_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << gammaco2_LOCKS_PriSt_SHIFT)) & gammaco2_LOCKS_PriSt_MASK)

#define gammaco2_LOCKS_FreezeS_MASK              (0x100U)
#define gammaco2_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define gammaco2_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << gammaco2_LOCKS_FreezeS_SHIFT)) & gammaco2_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define gammaco2_STATCON_ShdEn_MASK              (0x1U)
#define gammaco2_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define gammaco2_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << gammaco2_STATCON_ShdEn_SHIFT)) & gammaco2_STATCON_ShdEn_MASK)

#define gammaco2_STATCON_BEN_MASK                (0x2U)
#define gammaco2_STATCON_BEN_SHIFT               (1U)
/*! BEN - B_EN */
#define gammaco2_STATCON_BEN(x)                  (((uint32_t)(((uint32_t)(x)) << gammaco2_STATCON_BEN_SHIFT)) & gammaco2_STATCON_BEN_MASK)

#define gammaco2_STATCON_GEN_MASK                (0x4U)
#define gammaco2_STATCON_GEN_SHIFT               (2U)
/*! GEN - G_EN */
#define gammaco2_STATCON_GEN(x)                  (((uint32_t)(((uint32_t)(x)) << gammaco2_STATCON_GEN_SHIFT)) & gammaco2_STATCON_GEN_MASK)

#define gammaco2_STATCON_REN_MASK                (0x8U)
#define gammaco2_STATCON_REN_SHIFT               (3U)
/*! REN - R_EN */
#define gammaco2_STATCON_REN(x)                  (((uint32_t)(((uint32_t)(x)) << gammaco2_STATCON_REN_SHIFT)) & gammaco2_STATCON_REN_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define gammaco2_CONTR_Mode1_MASK                (0x1U)
#define gammaco2_CONTR_Mode1_SHIFT               (0U)
/*! Mode1 - Mode
 *  0b0..Module in neutral mode, input data is bypassed to the output.
 *  0b1..Module in gamma correction mode.
 */
#define gammaco2_CONTR_Mode1(x)                  (((uint32_t)(((uint32_t)(x)) << gammaco2_CONTR_Mode1_SHIFT)) & gammaco2_CONTR_Mode1_MASK)

#define gammaco2_CONTR_makinen_MASK              (0x1000000U)
#define gammaco2_CONTR_makinen_SHIFT             (24U)
/*! makinen - maskin_en
 *  0b0..disable external masking.
 *  0b1..enable external masking.
 */
#define gammaco2_CONTR_makinen(x)                (((uint32_t)(((uint32_t)(x)) << gammaco2_CONTR_makinen_SHIFT)) & gammaco2_CONTR_makinen_MASK)

#define gammaco2_CONTR_makinsel_MASK             (0x2000000U)
#define gammaco2_CONTR_makinsel_SHIFT            (25U)
/*! makinsel - maskin_sel
 *  0b0..mask signal 0 is used.
 *  0b1..mask signal 1 is used.
 */
#define gammaco2_CONTR_makinsel(x)               (((uint32_t)(((uint32_t)(x)) << gammaco2_CONTR_makinsel_SHIFT)) & gammaco2_CONTR_makinsel_MASK)

#define gammaco2_CONTR_makininv_MASK             (0x4000000U)
#define gammaco2_CONTR_makininv_SHIFT            (26U)
/*! makininv - maskin_inv
 *  0b0..bypassed when the related mask input signal is high.
 *  0b1..bypassed when the related mask input signal is low.
 */
#define gammaco2_CONTR_makininv(x)               (((uint32_t)(((uint32_t)(x)) << gammaco2_CONTR_makininv_SHIFT)) & gammaco2_CONTR_makininv_MASK)

#define gammaco2_CONTR_pxwinon0_MASK             (0x10000000U)
#define gammaco2_CONTR_pxwinon0_SHIFT            (28U)
/*! pxwinon0 - pixwinon
 *  0b0..disable internal masking.
 *  0b1..enable internal masking.
 */
#define gammaco2_CONTR_pxwinon0(x)               (((uint32_t)(((uint32_t)(x)) << gammaco2_CONTR_pxwinon0_SHIFT)) & gammaco2_CONTR_pxwinon0_MASK)

#define gammaco2_CONTR_pxwininv_MASK             (0x20000000U)
#define gammaco2_CONTR_pxwininv_SHIFT            (29U)
/*! pxwininv - pixwin_inv
 *  0b0..input pixels inside the defined window will be bypassed.
 *  0b1..input pixels outside the defined window will be bypassed.
 */
#define gammaco2_CONTR_pxwininv(x)               (((uint32_t)(((uint32_t)(x)) << gammaco2_CONTR_pxwininv_SHIFT)) & gammaco2_CONTR_pxwininv_MASK)
/*! @} */

/*! @name MASKSTAR - MaskStart */
/*! @{ */

#define gammaco2_MASKSTAR_passvst_MASK           (0x3FFFU)
#define gammaco2_MASKSTAR_passvst_SHIFT          (0U)
/*! passvst - pass_vstart */
#define gammaco2_MASKSTAR_passvst(x)             (((uint32_t)(((uint32_t)(x)) << gammaco2_MASKSTAR_passvst_SHIFT)) & gammaco2_MASKSTAR_passvst_MASK)

#define gammaco2_MASKSTAR_passhst_MASK           (0x3FFF0000U)
#define gammaco2_MASKSTAR_passhst_SHIFT          (16U)
/*! passhst - pass_hstart */
#define gammaco2_MASKSTAR_passhst(x)             (((uint32_t)(((uint32_t)(x)) << gammaco2_MASKSTAR_passhst_SHIFT)) & gammaco2_MASKSTAR_passhst_MASK)
/*! @} */

/*! @name MASKSIZE - MaskSize */
/*! @{ */

#define gammaco2_MASKSIZE_passvsi_MASK           (0x3FFFU)
#define gammaco2_MASKSIZE_passvsi_SHIFT          (0U)
/*! passvsi - pass_vsize */
#define gammaco2_MASKSIZE_passvsi(x)             (((uint32_t)(((uint32_t)(x)) << gammaco2_MASKSIZE_passvsi_SHIFT)) & gammaco2_MASKSIZE_passvsi_MASK)

#define gammaco2_MASKSIZE_passhsi_MASK           (0x3FFF0000U)
#define gammaco2_MASKSIZE_passhsi_SHIFT          (16U)
/*! passhsi - pass_hsize */
#define gammaco2_MASKSIZE_passhsi(x)             (((uint32_t)(((uint32_t)(x)) << gammaco2_MASKSIZE_passhsi_SHIFT)) & gammaco2_MASKSIZE_passhsi_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define gammaco2_STATUS_WrtTout_MASK             (0x1U)
#define gammaco2_STATUS_WrtTout_SHIFT            (0U)
/*! WrtTout - WriteTimeout */
#define gammaco2_STATUS_WrtTout(x)               (((uint32_t)(((uint32_t)(x)) << gammaco2_STATUS_WrtTout_SHIFT)) & gammaco2_STATUS_WrtTout_MASK)

#define gammaco2_STATUS_ReadTiou_MASK            (0x10U)
#define gammaco2_STATUS_ReadTiou_SHIFT           (4U)
/*! ReadTiou - ReadTimeout */
#define gammaco2_STATUS_ReadTiou(x)              (((uint32_t)(((uint32_t)(x)) << gammaco2_STATUS_ReadTiou_SHIFT)) & gammaco2_STATUS_ReadTiou_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group gammaco2_Register_Masks */


/*!
 * @}
 */ /* end of group gammaco2_Peripheral_Access_Layer */


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


#endif  /* PERI_GAMMACO2_H_ */

