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
**         CMSIS Peripheral Access Layer for displa1c
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
 * @file PERI_displa1c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for displa1c
 *
 * CMSIS Peripheral Access Layer for displa1c
 */

#if !defined(PERI_DISPLA1C_H_)
#define PERI_DISPLA1C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- displa1c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup displa1c_Peripheral_Access_Layer displa1c Peripheral Access Layer
 * @{
 */

/** displa1c - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t DISPXC;                            /**< DisplayPixelCtrl, offset: 0xC */
  __IO uint32_t POLCTRL1;                          /**< PolarityCtrl1, offset: 0x10 */
  __IO uint32_t COLPAER1;                          /**< ColorParityError1, offset: 0x14 */
  __IO uint32_t CONTRPE1;                          /**< ControlParityError1, offset: 0x18 */
  __O  uint32_t PARTRIG1;                          /**< ParityTrigger1, offset: 0x1C */
} displa1c_Type;

/* ----------------------------------------------------------------------------
   -- displa1c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup displa1c_Register_Masks displa1c Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define displa1c_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define displa1c_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define displa1c_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << displa1c_LU_LkUn_SHIFT)) & displa1c_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define displa1c_LOCKS_LkSus_MASK                (0x1U)
#define displa1c_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define displa1c_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << displa1c_LOCKS_LkSus_SHIFT)) & displa1c_LOCKS_LkSus_MASK)

#define displa1c_LOCKS_PriSt_MASK                (0x10U)
#define displa1c_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define displa1c_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << displa1c_LOCKS_PriSt_SHIFT)) & displa1c_LOCKS_PriSt_MASK)

#define displa1c_LOCKS_FreezeS_MASK              (0x100U)
#define displa1c_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define displa1c_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << displa1c_LOCKS_FreezeS_SHIFT)) & displa1c_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define displa1c_STATCON_ShdEn_MASK              (0x1U)
#define displa1c_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define displa1c_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << displa1c_STATCON_ShdEn_SHIFT)) & displa1c_STATCON_ShdEn_MASK)
/*! @} */

/*! @name DISPXC - DisplayPixelCtrl */
/*! @{ */

#define displa1c_DISPXC_DisplBl_MASK             (0x1U)
#define displa1c_DISPXC_DisplBl_SHIFT            (0U)
/*! DisplBl - DisplayBlack
 *  0b0..Normal operation
 *  0b1..Black output
 */
#define displa1c_DISPXC_DisplBl(x)               (((uint32_t)(((uint32_t)(x)) << displa1c_DISPXC_DisplBl_SHIFT)) & displa1c_DISPXC_DisplBl_MASK)
/*! @} */

/*! @name POLCTRL1 - PolarityCtrl1 */
/*! @{ */

#define displa1c_POLCTRL1_PolHs1_MASK            (0x1U)
#define displa1c_POLCTRL1_PolHs1_SHIFT           (0U)
/*! PolHs1 - PolHs1
 *  0b0..Low active
 *  0b1..High active
 */
#define displa1c_POLCTRL1_PolHs1(x)              (((uint32_t)(((uint32_t)(x)) << displa1c_POLCTRL1_PolHs1_SHIFT)) & displa1c_POLCTRL1_PolHs1_MASK)

#define displa1c_POLCTRL1_PolVs1_MASK            (0x2U)
#define displa1c_POLCTRL1_PolVs1_SHIFT           (1U)
/*! PolVs1 - PolVs1
 *  0b0..Low active
 *  0b1..High active
 */
#define displa1c_POLCTRL1_PolVs1(x)              (((uint32_t)(((uint32_t)(x)) << displa1c_POLCTRL1_PolVs1_SHIFT)) & displa1c_POLCTRL1_PolVs1_MASK)

#define displa1c_POLCTRL1_PolEn1_MASK            (0x4U)
#define displa1c_POLCTRL1_PolEn1_SHIFT           (2U)
/*! PolEn1 - PolEn1
 *  0b0..Low active
 *  0b1..High active
 */
#define displa1c_POLCTRL1_PolEn1(x)              (((uint32_t)(((uint32_t)(x)) << displa1c_POLCTRL1_PolEn1_SHIFT)) & displa1c_POLCTRL1_PolEn1_MASK)
/*! @} */

/*! @name COLPAER1 - ColorParityError1 */
/*! @{ */

#define displa1c_COLPAER1_RedXor1_MASK           (0x3FFU)
#define displa1c_COLPAER1_RedXor1_SHIFT          (0U)
/*! RedXor1 - RedXor1 */
#define displa1c_COLPAER1_RedXor1(x)             (((uint32_t)(((uint32_t)(x)) << displa1c_COLPAER1_RedXor1_SHIFT)) & displa1c_COLPAER1_RedXor1_MASK)

#define displa1c_COLPAER1_GreenXo1_MASK          (0xFFC00U)
#define displa1c_COLPAER1_GreenXo1_SHIFT         (10U)
/*! GreenXo1 - GreenXor1 */
#define displa1c_COLPAER1_GreenXo1(x)            (((uint32_t)(((uint32_t)(x)) << displa1c_COLPAER1_GreenXo1_SHIFT)) & displa1c_COLPAER1_GreenXo1_MASK)

#define displa1c_COLPAER1_BlueXor1_MASK          (0x3FF00000U)
#define displa1c_COLPAER1_BlueXor1_SHIFT         (20U)
/*! BlueXor1 - BlueXor1 */
#define displa1c_COLPAER1_BlueXor1(x)            (((uint32_t)(((uint32_t)(x)) << displa1c_COLPAER1_BlueXor1_SHIFT)) & displa1c_COLPAER1_BlueXor1_MASK)
/*! @} */

/*! @name CONTRPE1 - ControlParityError1 */
/*! @{ */

#define displa1c_CONTRPE1_EnXor1_MASK            (0x1U)
#define displa1c_CONTRPE1_EnXor1_SHIFT           (0U)
/*! EnXor1 - EnXor1 */
#define displa1c_CONTRPE1_EnXor1(x)              (((uint32_t)(((uint32_t)(x)) << displa1c_CONTRPE1_EnXor1_SHIFT)) & displa1c_CONTRPE1_EnXor1_MASK)

#define displa1c_CONTRPE1_HsXor1_MASK            (0x2U)
#define displa1c_CONTRPE1_HsXor1_SHIFT           (1U)
/*! HsXor1 - HsXor1 */
#define displa1c_CONTRPE1_HsXor1(x)              (((uint32_t)(((uint32_t)(x)) << displa1c_CONTRPE1_HsXor1_SHIFT)) & displa1c_CONTRPE1_HsXor1_MASK)

#define displa1c_CONTRPE1_VsXor1_MASK            (0x4U)
#define displa1c_CONTRPE1_VsXor1_SHIFT           (2U)
/*! VsXor1 - VsXor1 */
#define displa1c_CONTRPE1_VsXor1(x)              (((uint32_t)(((uint32_t)(x)) << displa1c_CONTRPE1_VsXor1_SHIFT)) & displa1c_CONTRPE1_VsXor1_MASK)

#define displa1c_CONTRPE1_ParXor1_MASK           (0xF0U)
#define displa1c_CONTRPE1_ParXor1_SHIFT          (4U)
/*! ParXor1 - ParityXor1 */
#define displa1c_CONTRPE1_ParXor1(x)             (((uint32_t)(((uint32_t)(x)) << displa1c_CONTRPE1_ParXor1_SHIFT)) & displa1c_CONTRPE1_ParXor1_MASK)
/*! @} */

/*! @name PARTRIG1 - ParityTrigger1 */
/*! @{ */

#define displa1c_PARTRIG1_ParErrT1_MASK          (0x1U)
#define displa1c_PARTRIG1_ParErrT1_SHIFT         (0U)
/*! ParErrT1 - ParityErrTrig1 */
#define displa1c_PARTRIG1_ParErrT1(x)            (((uint32_t)(((uint32_t)(x)) << displa1c_PARTRIG1_ParErrT1_SHIFT)) & displa1c_PARTRIG1_ParErrT1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group displa1c_Register_Masks */


/*!
 * @}
 */ /* end of group displa1c_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLA1C_H_ */

