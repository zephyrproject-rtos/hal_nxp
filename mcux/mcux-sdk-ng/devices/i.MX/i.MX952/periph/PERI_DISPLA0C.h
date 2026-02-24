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
**         CMSIS Peripheral Access Layer for displa0c
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
 * @file PERI_displa0c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for displa0c
 *
 * CMSIS Peripheral Access Layer for displa0c
 */

#if !defined(PERI_DISPLA0C_H_)
#define PERI_DISPLA0C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- displa0c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup displa0c_Peripheral_Access_Layer displa0c Peripheral Access Layer
 * @{
 */

/** displa0c - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t DISPXC;                            /**< DisplayPixelCtrl, offset: 0xC */
  __IO uint32_t POLCTRL0;                          /**< PolarityCtrl0, offset: 0x10 */
  __IO uint32_t COLPAER0;                          /**< ColorParityError0, offset: 0x14 */
  __IO uint32_t CONTRPE0;                          /**< ControlParityError0, offset: 0x18 */
  __O  uint32_t PARTRIG0;                          /**< ParityTrigger0, offset: 0x1C */
} displa0c_Type;

/* ----------------------------------------------------------------------------
   -- displa0c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup displa0c_Register_Masks displa0c Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define displa0c_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define displa0c_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define displa0c_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << displa0c_LU_LkUn_SHIFT)) & displa0c_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define displa0c_LOCKS_LkSus_MASK                (0x1U)
#define displa0c_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define displa0c_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << displa0c_LOCKS_LkSus_SHIFT)) & displa0c_LOCKS_LkSus_MASK)

#define displa0c_LOCKS_PriSt_MASK                (0x10U)
#define displa0c_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define displa0c_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << displa0c_LOCKS_PriSt_SHIFT)) & displa0c_LOCKS_PriSt_MASK)

#define displa0c_LOCKS_FreezeS_MASK              (0x100U)
#define displa0c_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define displa0c_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << displa0c_LOCKS_FreezeS_SHIFT)) & displa0c_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define displa0c_STATCON_ShdEn_MASK              (0x1U)
#define displa0c_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define displa0c_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << displa0c_STATCON_ShdEn_SHIFT)) & displa0c_STATCON_ShdEn_MASK)
/*! @} */

/*! @name DISPXC - DisplayPixelCtrl */
/*! @{ */

#define displa0c_DISPXC_DisplBl_MASK             (0x1U)
#define displa0c_DISPXC_DisplBl_SHIFT            (0U)
/*! DisplBl - DisplayBlack
 *  0b0..Normal operation
 *  0b1..Black output
 */
#define displa0c_DISPXC_DisplBl(x)               (((uint32_t)(((uint32_t)(x)) << displa0c_DISPXC_DisplBl_SHIFT)) & displa0c_DISPXC_DisplBl_MASK)
/*! @} */

/*! @name POLCTRL0 - PolarityCtrl0 */
/*! @{ */

#define displa0c_POLCTRL0_PolHs0_MASK            (0x1U)
#define displa0c_POLCTRL0_PolHs0_SHIFT           (0U)
/*! PolHs0 - PolHs0
 *  0b0..Low active
 *  0b1..High active
 */
#define displa0c_POLCTRL0_PolHs0(x)              (((uint32_t)(((uint32_t)(x)) << displa0c_POLCTRL0_PolHs0_SHIFT)) & displa0c_POLCTRL0_PolHs0_MASK)

#define displa0c_POLCTRL0_PolVs0_MASK            (0x2U)
#define displa0c_POLCTRL0_PolVs0_SHIFT           (1U)
/*! PolVs0 - PolVs0
 *  0b0..Low active
 *  0b1..High active
 */
#define displa0c_POLCTRL0_PolVs0(x)              (((uint32_t)(((uint32_t)(x)) << displa0c_POLCTRL0_PolVs0_SHIFT)) & displa0c_POLCTRL0_PolVs0_MASK)

#define displa0c_POLCTRL0_PolEn0_MASK            (0x4U)
#define displa0c_POLCTRL0_PolEn0_SHIFT           (2U)
/*! PolEn0 - PolEn0
 *  0b0..Low active
 *  0b1..High active
 */
#define displa0c_POLCTRL0_PolEn0(x)              (((uint32_t)(((uint32_t)(x)) << displa0c_POLCTRL0_PolEn0_SHIFT)) & displa0c_POLCTRL0_PolEn0_MASK)
/*! @} */

/*! @name COLPAER0 - ColorParityError0 */
/*! @{ */

#define displa0c_COLPAER0_RedXor0_MASK           (0x3FFU)
#define displa0c_COLPAER0_RedXor0_SHIFT          (0U)
/*! RedXor0 - RedXor0 */
#define displa0c_COLPAER0_RedXor0(x)             (((uint32_t)(((uint32_t)(x)) << displa0c_COLPAER0_RedXor0_SHIFT)) & displa0c_COLPAER0_RedXor0_MASK)

#define displa0c_COLPAER0_GreenXo0_MASK          (0xFFC00U)
#define displa0c_COLPAER0_GreenXo0_SHIFT         (10U)
/*! GreenXo0 - GreenXor0 */
#define displa0c_COLPAER0_GreenXo0(x)            (((uint32_t)(((uint32_t)(x)) << displa0c_COLPAER0_GreenXo0_SHIFT)) & displa0c_COLPAER0_GreenXo0_MASK)

#define displa0c_COLPAER0_BlueXor0_MASK          (0x3FF00000U)
#define displa0c_COLPAER0_BlueXor0_SHIFT         (20U)
/*! BlueXor0 - BlueXor0 */
#define displa0c_COLPAER0_BlueXor0(x)            (((uint32_t)(((uint32_t)(x)) << displa0c_COLPAER0_BlueXor0_SHIFT)) & displa0c_COLPAER0_BlueXor0_MASK)
/*! @} */

/*! @name CONTRPE0 - ControlParityError0 */
/*! @{ */

#define displa0c_CONTRPE0_EnXor0_MASK            (0x1U)
#define displa0c_CONTRPE0_EnXor0_SHIFT           (0U)
/*! EnXor0 - EnXor0 */
#define displa0c_CONTRPE0_EnXor0(x)              (((uint32_t)(((uint32_t)(x)) << displa0c_CONTRPE0_EnXor0_SHIFT)) & displa0c_CONTRPE0_EnXor0_MASK)

#define displa0c_CONTRPE0_HsXor0_MASK            (0x2U)
#define displa0c_CONTRPE0_HsXor0_SHIFT           (1U)
/*! HsXor0 - HsXor0 */
#define displa0c_CONTRPE0_HsXor0(x)              (((uint32_t)(((uint32_t)(x)) << displa0c_CONTRPE0_HsXor0_SHIFT)) & displa0c_CONTRPE0_HsXor0_MASK)

#define displa0c_CONTRPE0_VsXor0_MASK            (0x4U)
#define displa0c_CONTRPE0_VsXor0_SHIFT           (2U)
/*! VsXor0 - VsXor0 */
#define displa0c_CONTRPE0_VsXor0(x)              (((uint32_t)(((uint32_t)(x)) << displa0c_CONTRPE0_VsXor0_SHIFT)) & displa0c_CONTRPE0_VsXor0_MASK)

#define displa0c_CONTRPE0_ParXor0_MASK           (0xF0U)
#define displa0c_CONTRPE0_ParXor0_SHIFT          (4U)
/*! ParXor0 - ParityXor0 */
#define displa0c_CONTRPE0_ParXor0(x)             (((uint32_t)(((uint32_t)(x)) << displa0c_CONTRPE0_ParXor0_SHIFT)) & displa0c_CONTRPE0_ParXor0_MASK)
/*! @} */

/*! @name PARTRIG0 - ParityTrigger0 */
/*! @{ */

#define displa0c_PARTRIG0_ParErrT0_MASK          (0x1U)
#define displa0c_PARTRIG0_ParErrT0_SHIFT         (0U)
/*! ParErrT0 - ParityErrTrig0 */
#define displa0c_PARTRIG0_ParErrT0(x)            (((uint32_t)(((uint32_t)(x)) << displa0c_PARTRIG0_ParErrT0_SHIFT)) & displa0c_PARTRIG0_ParErrT0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group displa0c_Register_Masks */


/*!
 * @}
 */ /* end of group displa0c_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLA0C_H_ */

