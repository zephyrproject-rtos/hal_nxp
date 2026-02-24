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
**         CMSIS Peripheral Access Layer for blitbld
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
 * @file PERI_blitbld.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for blitbld
 *
 * CMSIS Peripheral Access Layer for blitbld
 */

#if !defined(PERI_BLITBLD_H_)
#define PERI_BLITBLD_H_                          /**< Symbol preventing repeated inclusion */

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
   -- blitbld Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup blitbld_Peripheral_Access_Layer blitbld Peripheral Access Layer
 * @{
 */

/** blitbld - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __IO uint32_t NEUTBOR;                           /**< NeutralBorder, offset: 0x10 */
  __IO uint32_t CONSTC;                            /**< ConstantColor, offset: 0x14 */
  __IO uint32_t COLRBFU;                           /**< ColorRedBlendFunction, offset: 0x18 */
  __IO uint32_t COLGBF;                            /**< ColorGreenBlendFunction, offset: 0x1C */
  __IO uint32_t COLBBFUN;                          /**< ColorBlueBlendFunction, offset: 0x20 */
  __IO uint32_t ALPHABF;                           /**< AlphaBlendFunction, offset: 0x24 */
  __IO uint32_t BLENDMO1;                          /**< BlendMode1, offset: 0x28 */
  __IO uint32_t BLENDMO2;                          /**< BlendMode2, offset: 0x2C */
  __IO uint32_t DIRSET;                            /**< DirectSetup, offset: 0x30 */
  __I  uint32_t PRIMCOWO;                          /**< PrimControlWord, offset: 0x34 */
  __I  uint32_t SECCONTW;                          /**< SecControlWord, offset: 0x38 */
} blitbld_Type;

/* ----------------------------------------------------------------------------
   -- blitbld Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup blitbld_Register_Masks blitbld Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define blitbld_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define blitbld_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define blitbld_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << blitbld_LU_LkUn_SHIFT)) & blitbld_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define blitbld_LOCKS_LkSus_MASK                 (0x1U)
#define blitbld_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define blitbld_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << blitbld_LOCKS_LkSus_SHIFT)) & blitbld_LOCKS_LkSus_MASK)

#define blitbld_LOCKS_PriSt_MASK                 (0x10U)
#define blitbld_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define blitbld_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << blitbld_LOCKS_PriSt_SHIFT)) & blitbld_LOCKS_PriSt_MASK)

#define blitbld_LOCKS_FreezeS_MASK               (0x100U)
#define blitbld_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define blitbld_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_LOCKS_FreezeS_SHIFT)) & blitbld_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define blitbld_STATCON_ShdEn_MASK               (0x1U)
#define blitbld_STATCON_ShdEn_SHIFT              (0U)
/*! ShdEn - ShdEn */
#define blitbld_STATCON_ShdEn(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_STATCON_ShdEn_SHIFT)) & blitbld_STATCON_ShdEn_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define blitbld_CONTR_Mode1_MASK                 (0x1U)
#define blitbld_CONTR_Mode1_SHIFT                (0U)
/*! Mode1 - Mode
 *  0b0..Neutral mode, only route pixels and commands from primary input to output
 *  0b1..Normal Operation
 */
#define blitbld_CONTR_Mode1(x)                   (((uint32_t)(((uint32_t)(x)) << blitbld_CONTR_Mode1_SHIFT)) & blitbld_CONTR_Mode1_MASK)
/*! @} */

/*! @name NEUTBOR - NeutralBorder */
/*! @{ */

#define blitbld_NEUTBOR_NeulBMo_MASK             (0x1U)
#define blitbld_NEUTBOR_NeulBMo_SHIFT            (0U)
/*! NeulBMo - NeutralBorderMode
 *  0b0..Bypasses primary pixel
 *  0b1..Bypasses secondary pixel
 */
#define blitbld_NEUTBOR_NeulBMo(x)               (((uint32_t)(((uint32_t)(x)) << blitbld_NEUTBOR_NeulBMo_SHIFT)) & blitbld_NEUTBOR_NeulBMo_MASK)

#define blitbld_NEUTBOR_NeulBL_MASK              (0x700U)
#define blitbld_NEUTBOR_NeulBL_SHIFT             (8U)
/*! NeulBL - NeutralBorderLeft */
#define blitbld_NEUTBOR_NeulBL(x)                (((uint32_t)(((uint32_t)(x)) << blitbld_NEUTBOR_NeulBL_SHIFT)) & blitbld_NEUTBOR_NeulBL_MASK)

#define blitbld_NEUTBOR_NeulBRi_MASK             (0x7000U)
#define blitbld_NEUTBOR_NeulBRi_SHIFT            (12U)
/*! NeulBRi - NeutralBorderRight */
#define blitbld_NEUTBOR_NeulBRi(x)               (((uint32_t)(((uint32_t)(x)) << blitbld_NEUTBOR_NeulBRi_SHIFT)) & blitbld_NEUTBOR_NeulBRi_MASK)
/*! @} */

/*! @name CONSTC - ConstantColor */
/*! @{ */

#define blitbld_CONSTC_ConstA_MASK               (0xFFU)
#define blitbld_CONSTC_ConstA_SHIFT              (0U)
/*! ConstA - ConstantAlpha */
#define blitbld_CONSTC_ConstA(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_CONSTC_ConstA_SHIFT)) & blitbld_CONSTC_ConstA_MASK)

#define blitbld_CONSTC_ConstB_MASK               (0xFF00U)
#define blitbld_CONSTC_ConstB_SHIFT              (8U)
/*! ConstB - ConstantBlue */
#define blitbld_CONSTC_ConstB(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_CONSTC_ConstB_SHIFT)) & blitbld_CONSTC_ConstB_MASK)

#define blitbld_CONSTC_ConstG_MASK               (0xFF0000U)
#define blitbld_CONSTC_ConstG_SHIFT              (16U)
/*! ConstG - ConstantGreen */
#define blitbld_CONSTC_ConstG(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_CONSTC_ConstG_SHIFT)) & blitbld_CONSTC_ConstG_MASK)

#define blitbld_CONSTC_ConstR_MASK               (0xFF000000U)
#define blitbld_CONSTC_ConstR_SHIFT              (24U)
/*! ConstR - ConstantRed */
#define blitbld_CONSTC_ConstR(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_CONSTC_ConstR_SHIFT)) & blitbld_CONSTC_ConstR_MASK)
/*! @} */

/*! @name COLRBFU - ColorRedBlendFunction */
/*! @{ */

#define blitbld_COLRBFU_BleFCRlS_MASK            (0xFFFFU)
#define blitbld_COLRBFU_BleFCRlS_SHIFT           (0U)
/*! BleFCRlS - BlendFuncColorRedSrc
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_COLRBFU_BleFCRlS(x)              (((uint32_t)(((uint32_t)(x)) << blitbld_COLRBFU_BleFCRlS_SHIFT)) & blitbld_COLRBFU_BleFCRlS_MASK)

#define blitbld_COLRBFU_BleFCRlD_MASK            (0xFFFF0000U)
#define blitbld_COLRBFU_BleFCRlD_SHIFT           (16U)
/*! BleFCRlD - BlendFuncColorRedDst
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_COLRBFU_BleFCRlD(x)              (((uint32_t)(((uint32_t)(x)) << blitbld_COLRBFU_BleFCRlD_SHIFT)) & blitbld_COLRBFU_BleFCRlD_MASK)
/*! @} */

/*! @name COLGBF - ColorGreenBlendFunction */
/*! @{ */

#define blitbld_COLGBF_BleFCGlS_MASK             (0xFFFFU)
#define blitbld_COLGBF_BleFCGlS_SHIFT            (0U)
/*! BleFCGlS - BlendFuncColorGreenSrc
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_COLGBF_BleFCGlS(x)               (((uint32_t)(((uint32_t)(x)) << blitbld_COLGBF_BleFCGlS_SHIFT)) & blitbld_COLGBF_BleFCGlS_MASK)

#define blitbld_COLGBF_BleFCGlD_MASK             (0xFFFF0000U)
#define blitbld_COLGBF_BleFCGlD_SHIFT            (16U)
/*! BleFCGlD - BlendFuncColorGreenDst
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_COLGBF_BleFCGlD(x)               (((uint32_t)(((uint32_t)(x)) << blitbld_COLGBF_BleFCGlD_SHIFT)) & blitbld_COLGBF_BleFCGlD_MASK)
/*! @} */

/*! @name COLBBFUN - ColorBlueBlendFunction */
/*! @{ */

#define blitbld_COLBBFUN_BleFCBlS_MASK           (0xFFFFU)
#define blitbld_COLBBFUN_BleFCBlS_SHIFT          (0U)
/*! BleFCBlS - BlendFuncColorBlueSrc
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_COLBBFUN_BleFCBlS(x)             (((uint32_t)(((uint32_t)(x)) << blitbld_COLBBFUN_BleFCBlS_SHIFT)) & blitbld_COLBBFUN_BleFCBlS_MASK)

#define blitbld_COLBBFUN_BleFCBlD_MASK           (0xFFFF0000U)
#define blitbld_COLBBFUN_BleFCBlD_SHIFT          (16U)
/*! BleFCBlD - BlendFuncColorBlueDst
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_COLBBFUN_BleFCBlD(x)             (((uint32_t)(((uint32_t)(x)) << blitbld_COLBBFUN_BleFCBlD_SHIFT)) & blitbld_COLBBFUN_BleFCBlD_MASK)
/*! @} */

/*! @name ALPHABF - AlphaBlendFunction */
/*! @{ */

#define blitbld_ALPHABF_BlendFAS_MASK            (0xFFFFU)
#define blitbld_ALPHABF_BlendFAS_SHIFT           (0U)
/*! BlendFAS - BlendFuncAlphaSrc
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_ALPHABF_BlendFAS(x)              (((uint32_t)(((uint32_t)(x)) << blitbld_ALPHABF_BlendFAS_SHIFT)) & blitbld_ALPHABF_BlendFAS_MASK)

#define blitbld_ALPHABF_BlendFAD_MASK            (0xFFFF0000U)
#define blitbld_ALPHABF_BlendFAD_SHIFT           (16U)
/*! BlendFAD - BlendFuncAlphaDst
 *  0b0000000000000000..
 *  0b0000000000000001..
 *  0b0000001100000000..
 *  0b0000001100000001..
 *  0b0000001100000010..
 *  0b0000001100000011..
 *  0b0000001100000100..
 *  0b0000001100000101..
 *  0b0000001100000110..
 *  0b0000001100000111..
 *  0b0000001100001000..
 *  0b1000000000000001..
 *  0b1000000000000010..
 *  0b1000000000000011..
 *  0b1000000000000100..
 */
#define blitbld_ALPHABF_BlendFAD(x)              (((uint32_t)(((uint32_t)(x)) << blitbld_ALPHABF_BlendFAD_SHIFT)) & blitbld_ALPHABF_BlendFAD_MASK)
/*! @} */

/*! @name BLENDMO1 - BlendMode1 */
/*! @{ */

#define blitbld_BLENDMO1_BlendMCR_MASK           (0xFFFFU)
#define blitbld_BLENDMO1_BlendMCR_SHIFT          (0U)
/*! BlendMCR - BlendModeColorRed
 *  0b0010000000000000..
 *  0b0010000000000001..
 *  0b0010000000000010..
 *  0b0010000000000011..
 *  0b0010000000000100..
 *  0b0010000000000101..
 *  0b0010000000000110..
 *  0b0010000000000111..
 *  0b0010000000001000..
 *  0b0010000000001001..
 *  0b1000000000000110..
 *  0b1000000000000111..
 *  0b1000000000001000..
 *  0b1000000000001010..
 *  0b1000000000001011..
 */
#define blitbld_BLENDMO1_BlendMCR(x)             (((uint32_t)(((uint32_t)(x)) << blitbld_BLENDMO1_BlendMCR_SHIFT)) & blitbld_BLENDMO1_BlendMCR_MASK)

#define blitbld_BLENDMO1_BlendMCG_MASK           (0xFFFF0000U)
#define blitbld_BLENDMO1_BlendMCG_SHIFT          (16U)
/*! BlendMCG - BlendModeColorGreen
 *  0b0010000000000000..
 *  0b0010000000000001..
 *  0b0010000000000010..
 *  0b0010000000000011..
 *  0b0010000000000100..
 *  0b0010000000000101..
 *  0b0010000000000110..
 *  0b0010000000000111..
 *  0b0010000000001000..
 *  0b0010000000001001..
 *  0b1000000000000110..
 *  0b1000000000000111..
 *  0b1000000000001000..
 *  0b1000000000001010..
 *  0b1000000000001011..
 */
#define blitbld_BLENDMO1_BlendMCG(x)             (((uint32_t)(((uint32_t)(x)) << blitbld_BLENDMO1_BlendMCG_SHIFT)) & blitbld_BLENDMO1_BlendMCG_MASK)
/*! @} */

/*! @name BLENDMO2 - BlendMode2 */
/*! @{ */

#define blitbld_BLENDMO2_BlendMCB_MASK           (0xFFFFU)
#define blitbld_BLENDMO2_BlendMCB_SHIFT          (0U)
/*! BlendMCB - BlendModeColorBlue
 *  0b0010000000000000..
 *  0b0010000000000001..
 *  0b0010000000000010..
 *  0b0010000000000011..
 *  0b0010000000000100..
 *  0b0010000000000101..
 *  0b0010000000000110..
 *  0b0010000000000111..
 *  0b0010000000001000..
 *  0b0010000000001001..
 *  0b1000000000000110..
 *  0b1000000000000111..
 *  0b1000000000001000..
 *  0b1000000000001010..
 *  0b1000000000001011..
 */
#define blitbld_BLENDMO2_BlendMCB(x)             (((uint32_t)(((uint32_t)(x)) << blitbld_BLENDMO2_BlendMCB_SHIFT)) & blitbld_BLENDMO2_BlendMCB_MASK)

#define blitbld_BLENDMO2_BlendMA_MASK            (0xFFFF0000U)
#define blitbld_BLENDMO2_BlendMA_SHIFT           (16U)
/*! BlendMA - BlendModeAlpha
 *  0b0010000000000000..
 *  0b0010000000000001..
 *  0b0010000000000010..
 *  0b0010000000000011..
 *  0b0010000000000100..
 *  0b0010000000000101..
 *  0b0010000000000110..
 *  0b0010000000000111..
 *  0b0010000000001000..
 *  0b0010000000001001..
 *  0b1000000000000110..
 *  0b1000000000000111..
 *  0b1000000000001000..
 *  0b1000000000001010..
 *  0b1000000000001011..
 */
#define blitbld_BLENDMO2_BlendMA(x)              (((uint32_t)(((uint32_t)(x)) << blitbld_BLENDMO2_BlendMA_SHIFT)) & blitbld_BLENDMO2_BlendMA_MASK)
/*! @} */

/*! @name DIRSET - DirectSetup */
/*! @{ */

#define blitbld_DIRSET_ColorD_MASK               (0x3FFU)
#define blitbld_DIRSET_ColorD_SHIFT              (0U)
/*! ColorD - ColorDebug */
#define blitbld_DIRSET_ColorD(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_DIRSET_ColorD_SHIFT)) & blitbld_DIRSET_ColorD_MASK)

#define blitbld_DIRSET_AlphaDeb_MASK             (0x3FF0000U)
#define blitbld_DIRSET_AlphaDeb_SHIFT            (16U)
/*! AlphaDeb - AlphaDebug */
#define blitbld_DIRSET_AlphaDeb(x)               (((uint32_t)(((uint32_t)(x)) << blitbld_DIRSET_AlphaDeb_SHIFT)) & blitbld_DIRSET_AlphaDeb_MASK)
/*! @} */

/*! @name PRIMCOWO - PrimControlWord */
/*! @{ */

#define blitbld_PRIMCOWO_PVAL_MASK               (0xFFFFFFFFU)
#define blitbld_PRIMCOWO_PVAL_SHIFT              (0U)
/*! PVAL - P_VAL */
#define blitbld_PRIMCOWO_PVAL(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_PRIMCOWO_PVAL_SHIFT)) & blitbld_PRIMCOWO_PVAL_MASK)
/*! @} */

/*! @name SECCONTW - SecControlWord */
/*! @{ */

#define blitbld_SECCONTW_SVAL_MASK               (0xFFFFFFFFU)
#define blitbld_SECCONTW_SVAL_SHIFT              (0U)
/*! SVAL - S_VAL */
#define blitbld_SECCONTW_SVAL(x)                 (((uint32_t)(((uint32_t)(x)) << blitbld_SECCONTW_SVAL_SHIFT)) & blitbld_SECCONTW_SVAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group blitbld_Register_Masks */


/*!
 * @}
 */ /* end of group blitbld_Peripheral_Access_Layer */


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


#endif  /* PERI_BLITBLD_H_ */

