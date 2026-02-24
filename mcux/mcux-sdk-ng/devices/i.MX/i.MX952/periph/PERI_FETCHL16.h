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
**         CMSIS Peripheral Access Layer for fetchl16
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
 * @file PERI_fetchl16.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchl16
 *
 * CMSIS Peripheral Access Layer for fetchl16
 */

#if !defined(PERI_FETCHL16_H_)
#define PERI_FETCHL16_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchl16 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl16_Peripheral_Access_Layer fetchl16 Peripheral Access Layer
 * @{
 */

/** fetchl16 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA2;                            /**< BaseAddress2, offset: 0x0 */
  __IO uint32_t BASAMSB2;                          /**< BaseAddressMSB2, offset: 0x4 */
  __IO uint32_t AUTOUBA2;                          /**< AutoUpdateBaseAddress2, offset: 0x8 */
  __IO uint32_t AUTUBAM2;                          /**< AutoUpdateBaseAddressMSB2, offset: 0xC */
  __IO uint32_t SOUBUAT2;                          /**< SourceBufferAttributes2, offset: 0x10 */
  __IO uint32_t SOUBUDI2;                          /**< SourceBufferDimension2, offset: 0x14 */
  __IO uint32_t COLCOMB2;                          /**< ColorComponentBits2, offset: 0x18 */
  __IO uint32_t COLCOMS2;                          /**< ColorComponentShift2, offset: 0x1C */
  __IO uint32_t LAYOFF2;                           /**< LayerOffset2, offset: 0x20 */
  __IO uint32_t CLIPWO2;                           /**< ClipWindowOffset2, offset: 0x24 */
  __IO uint32_t CLIPWID2;                          /**< ClipWindowDimensions2, offset: 0x28 */
  __IO uint32_t CONSTC2;                           /**< ConstantColor2, offset: 0x2C */
  __IO uint32_t LAYPRO2;                           /**< LayerProperty2, offset: 0x30 */
} fetchl16_Type;

/* ----------------------------------------------------------------------------
   -- fetchl16 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl16_Register_Masks fetchl16 Register Masks
 * @{
 */

/*! @name BASEA2 - BaseAddress2 */
/*! @{ */

#define fetchl16_BASEA2_BaseAdd2_MASK            (0xFFFFFFFFU)
#define fetchl16_BASEA2_BaseAdd2_SHIFT           (0U)
/*! BaseAdd2 - BaseAddress2 */
#define fetchl16_BASEA2_BaseAdd2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_BASEA2_BaseAdd2_SHIFT)) & fetchl16_BASEA2_BaseAdd2_MASK)
/*! @} */

/*! @name BASAMSB2 - BaseAddressMSB2 */
/*! @{ */

#define fetchl16_BASAMSB2_BaAdMB2_MASK           (0xFFU)
#define fetchl16_BASAMSB2_BaAdMB2_SHIFT          (0U)
/*! BaAdMB2 - BaseAddressMSB2 */
#define fetchl16_BASAMSB2_BaAdMB2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_BASAMSB2_BaAdMB2_SHIFT)) & fetchl16_BASAMSB2_BaAdMB2_MASK)
/*! @} */

/*! @name AUTOUBA2 - AutoUpdateBaseAddress2 */
/*! @{ */

#define fetchl16_AUTOUBA2_AutoUBA2_MASK          (0xFFFFFFFFU)
#define fetchl16_AUTOUBA2_AutoUBA2_SHIFT         (0U)
/*! AutoUBA2 - AutoUpdateBaseAddress2 */
#define fetchl16_AUTOUBA2_AutoUBA2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_AUTOUBA2_AutoUBA2_SHIFT)) & fetchl16_AUTOUBA2_AutoUBA2_MASK)
/*! @} */

/*! @name AUTUBAM2 - AutoUpdateBaseAddressMSB2 */
/*! @{ */

#define fetchl16_AUTUBAM2_AutoUBM2_MASK          (0xFFU)
#define fetchl16_AUTUBAM2_AutoUBM2_SHIFT         (0U)
/*! AutoUBM2 - AutoUpdateBaseAddressMSB2 */
#define fetchl16_AUTUBAM2_AutoUBM2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_AUTUBAM2_AutoUBM2_SHIFT)) & fetchl16_AUTUBAM2_AutoUBM2_MASK)
/*! @} */

/*! @name SOUBUAT2 - SourceBufferAttributes2 */
/*! @{ */

#define fetchl16_SOUBUAT2_Stride2_MASK           (0xFFFFU)
#define fetchl16_SOUBUAT2_Stride2_SHIFT          (0U)
/*! Stride2 - Stride2 */
#define fetchl16_SOUBUAT2_Stride2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_SOUBUAT2_Stride2_SHIFT)) & fetchl16_SOUBUAT2_Stride2_MASK)

#define fetchl16_SOUBUAT2_BitsPP2_MASK           (0x3F0000U)
#define fetchl16_SOUBUAT2_BitsPP2_SHIFT          (16U)
/*! BitsPP2 - BitsPerPixel2 */
#define fetchl16_SOUBUAT2_BitsPP2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_SOUBUAT2_BitsPP2_SHIFT)) & fetchl16_SOUBUAT2_BitsPP2_MASK)

#define fetchl16_SOUBUAT2_BaAdAU2_MASK           (0x40000000U)
#define fetchl16_SOUBUAT2_BaAdAU2_SHIFT          (30U)
/*! BaAdAU2 - BaseAddressAutoUpdate2 */
#define fetchl16_SOUBUAT2_BaAdAU2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_SOUBUAT2_BaAdAU2_SHIFT)) & fetchl16_SOUBUAT2_BaAdAU2_MASK)

#define fetchl16_SOUBUAT2_DWBS2_MASK             (0x80000000U)
#define fetchl16_SOUBUAT2_DWBS2_SHIFT            (31U)
/*! DWBS2 - DWordByteSwap2 */
#define fetchl16_SOUBUAT2_DWBS2(x)               (((uint32_t)(((uint32_t)(x)) << fetchl16_SOUBUAT2_DWBS2_SHIFT)) & fetchl16_SOUBUAT2_DWBS2_MASK)
/*! @} */

/*! @name SOUBUDI2 - SourceBufferDimension2 */
/*! @{ */

#define fetchl16_SOUBUDI2_LineW2_MASK            (0x3FFFU)
#define fetchl16_SOUBUDI2_LineW2_SHIFT           (0U)
/*! LineW2 - LineWidth2 */
#define fetchl16_SOUBUDI2_LineW2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_SOUBUDI2_LineW2_SHIFT)) & fetchl16_SOUBUDI2_LineW2_MASK)

#define fetchl16_SOUBUDI2_LineC2_MASK            (0x3FFF0000U)
#define fetchl16_SOUBUDI2_LineC2_SHIFT           (16U)
/*! LineC2 - LineCount2 */
#define fetchl16_SOUBUDI2_LineC2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_SOUBUDI2_LineC2_SHIFT)) & fetchl16_SOUBUDI2_LineC2_MASK)
/*! @} */

/*! @name COLCOMB2 - ColorComponentBits2 */
/*! @{ */

#define fetchl16_COLCOMB2_CompBiA2_MASK          (0xFU)
#define fetchl16_COLCOMB2_CompBiA2_SHIFT         (0U)
/*! CompBiA2 - ComponentBitsAlpha2 */
#define fetchl16_COLCOMB2_CompBiA2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMB2_CompBiA2_SHIFT)) & fetchl16_COLCOMB2_CompBiA2_MASK)

#define fetchl16_COLCOMB2_CompBiB2_MASK          (0xF00U)
#define fetchl16_COLCOMB2_CompBiB2_SHIFT         (8U)
/*! CompBiB2 - ComponentBitsBlue2 */
#define fetchl16_COLCOMB2_CompBiB2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMB2_CompBiB2_SHIFT)) & fetchl16_COLCOMB2_CompBiB2_MASK)

#define fetchl16_COLCOMB2_CompBiG2_MASK          (0xF0000U)
#define fetchl16_COLCOMB2_CompBiG2_SHIFT         (16U)
/*! CompBiG2 - ComponentBitsGreen2 */
#define fetchl16_COLCOMB2_CompBiG2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMB2_CompBiG2_SHIFT)) & fetchl16_COLCOMB2_CompBiG2_MASK)

#define fetchl16_COLCOMB2_CompBiR2_MASK          (0xF000000U)
#define fetchl16_COLCOMB2_CompBiR2_SHIFT         (24U)
/*! CompBiR2 - ComponentBitsRed2 */
#define fetchl16_COLCOMB2_CompBiR2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMB2_CompBiR2_SHIFT)) & fetchl16_COLCOMB2_CompBiR2_MASK)

#define fetchl16_COLCOMB2_ITUForm2_MASK          (0x80000000U)
#define fetchl16_COLCOMB2_ITUForm2_SHIFT         (31U)
/*! ITUForm2 - ITUFormat2 */
#define fetchl16_COLCOMB2_ITUForm2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMB2_ITUForm2_SHIFT)) & fetchl16_COLCOMB2_ITUForm2_MASK)
/*! @} */

/*! @name COLCOMS2 - ColorComponentShift2 */
/*! @{ */

#define fetchl16_COLCOMS2_CompShA2_MASK          (0x1FU)
#define fetchl16_COLCOMS2_CompShA2_SHIFT         (0U)
/*! CompShA2 - ComponentShiftAlpha2 */
#define fetchl16_COLCOMS2_CompShA2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMS2_CompShA2_SHIFT)) & fetchl16_COLCOMS2_CompShA2_MASK)

#define fetchl16_COLCOMS2_CompShB2_MASK          (0x1F00U)
#define fetchl16_COLCOMS2_CompShB2_SHIFT         (8U)
/*! CompShB2 - ComponentShiftBlue2 */
#define fetchl16_COLCOMS2_CompShB2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMS2_CompShB2_SHIFT)) & fetchl16_COLCOMS2_CompShB2_MASK)

#define fetchl16_COLCOMS2_CompShG2_MASK          (0x1F0000U)
#define fetchl16_COLCOMS2_CompShG2_SHIFT         (16U)
/*! CompShG2 - ComponentShiftGreen2 */
#define fetchl16_COLCOMS2_CompShG2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMS2_CompShG2_SHIFT)) & fetchl16_COLCOMS2_CompShG2_MASK)

#define fetchl16_COLCOMS2_CompShR2_MASK          (0x1F000000U)
#define fetchl16_COLCOMS2_CompShR2_SHIFT         (24U)
/*! CompShR2 - ComponentShiftRed2 */
#define fetchl16_COLCOMS2_CompShR2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl16_COLCOMS2_CompShR2_SHIFT)) & fetchl16_COLCOMS2_CompShR2_MASK)
/*! @} */

/*! @name LAYOFF2 - LayerOffset2 */
/*! @{ */

#define fetchl16_LAYOFF2_LayXOs2_MASK            (0x7FFFU)
#define fetchl16_LAYOFF2_LayXOs2_SHIFT           (0U)
/*! LayXOs2 - LayerXOffset2 */
#define fetchl16_LAYOFF2_LayXOs2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYOFF2_LayXOs2_SHIFT)) & fetchl16_LAYOFF2_LayXOs2_MASK)

#define fetchl16_LAYOFF2_LayYOs2_MASK            (0x7FFF0000U)
#define fetchl16_LAYOFF2_LayYOs2_SHIFT           (16U)
/*! LayYOs2 - LayerYOffset2 */
#define fetchl16_LAYOFF2_LayYOs2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYOFF2_LayYOs2_SHIFT)) & fetchl16_LAYOFF2_LayYOs2_MASK)
/*! @} */

/*! @name CLIPWO2 - ClipWindowOffset2 */
/*! @{ */

#define fetchl16_CLIPWO2_ClipWXO2_MASK           (0x7FFFU)
#define fetchl16_CLIPWO2_ClipWXO2_SHIFT          (0U)
/*! ClipWXO2 - ClipWindowXOffset2 */
#define fetchl16_CLIPWO2_ClipWXO2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_CLIPWO2_ClipWXO2_SHIFT)) & fetchl16_CLIPWO2_ClipWXO2_MASK)

#define fetchl16_CLIPWO2_ClipWYO2_MASK           (0x7FFF0000U)
#define fetchl16_CLIPWO2_ClipWYO2_SHIFT          (16U)
/*! ClipWYO2 - ClipWindowYOffset2 */
#define fetchl16_CLIPWO2_ClipWYO2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_CLIPWO2_ClipWYO2_SHIFT)) & fetchl16_CLIPWO2_ClipWYO2_MASK)
/*! @} */

/*! @name CLIPWID2 - ClipWindowDimensions2 */
/*! @{ */

#define fetchl16_CLIPWID2_ClipWW2_MASK           (0x3FFFU)
#define fetchl16_CLIPWID2_ClipWW2_SHIFT          (0U)
/*! ClipWW2 - ClipWindowWidth2 */
#define fetchl16_CLIPWID2_ClipWW2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_CLIPWID2_ClipWW2_SHIFT)) & fetchl16_CLIPWID2_ClipWW2_MASK)

#define fetchl16_CLIPWID2_ClipWH2_MASK           (0x3FFF0000U)
#define fetchl16_CLIPWID2_ClipWH2_SHIFT          (16U)
/*! ClipWH2 - ClipWindowHeight2 */
#define fetchl16_CLIPWID2_ClipWH2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_CLIPWID2_ClipWH2_SHIFT)) & fetchl16_CLIPWID2_ClipWH2_MASK)
/*! @} */

/*! @name CONSTC2 - ConstantColor2 */
/*! @{ */

#define fetchl16_CONSTC2_ConstA2_MASK            (0xFFU)
#define fetchl16_CONSTC2_ConstA2_SHIFT           (0U)
/*! ConstA2 - ConstantAlpha2 */
#define fetchl16_CONSTC2_ConstA2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_CONSTC2_ConstA2_SHIFT)) & fetchl16_CONSTC2_ConstA2_MASK)

#define fetchl16_CONSTC2_ConstB2_MASK            (0xFF00U)
#define fetchl16_CONSTC2_ConstB2_SHIFT           (8U)
/*! ConstB2 - ConstantBlue2 */
#define fetchl16_CONSTC2_ConstB2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_CONSTC2_ConstB2_SHIFT)) & fetchl16_CONSTC2_ConstB2_MASK)

#define fetchl16_CONSTC2_ConstG2_MASK            (0xFF0000U)
#define fetchl16_CONSTC2_ConstG2_SHIFT           (16U)
/*! ConstG2 - ConstantGreen2 */
#define fetchl16_CONSTC2_ConstG2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_CONSTC2_ConstG2_SHIFT)) & fetchl16_CONSTC2_ConstG2_MASK)

#define fetchl16_CONSTC2_ConstR2_MASK            (0xFF000000U)
#define fetchl16_CONSTC2_ConstR2_SHIFT           (24U)
/*! ConstR2 - ConstantRed2 */
#define fetchl16_CONSTC2_ConstR2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_CONSTC2_ConstR2_SHIFT)) & fetchl16_CONSTC2_ConstR2_MASK)
/*! @} */

/*! @name LAYPRO2 - LayerProperty2 */
/*! @{ */

#define fetchl16_LAYPRO2_PaletE2_MASK            (0x1U)
#define fetchl16_LAYPRO2_PaletE2_SHIFT           (0U)
/*! PaletE2 - PaletteEnable2 */
#define fetchl16_LAYPRO2_PaletE2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_PaletE2_SHIFT)) & fetchl16_LAYPRO2_PaletE2_MASK)

#define fetchl16_LAYPRO2_TileMod2_MASK           (0x30U)
#define fetchl16_LAYPRO2_TileMod2_SHIFT          (4U)
/*! TileMod2 - TileMode2
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchl16_LAYPRO2_TileMod2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_TileMod2_SHIFT)) & fetchl16_LAYPRO2_TileMod2_MASK)

#define fetchl16_LAYPRO2_AlpSE2_MASK             (0x100U)
#define fetchl16_LAYPRO2_AlpSE2_SHIFT            (8U)
/*! AlpSE2 - AlphaSrcEnable2 */
#define fetchl16_LAYPRO2_AlpSE2(x)               (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_AlpSE2_SHIFT)) & fetchl16_LAYPRO2_AlpSE2_MASK)

#define fetchl16_LAYPRO2_AlphaCE2_MASK           (0x200U)
#define fetchl16_LAYPRO2_AlphaCE2_SHIFT          (9U)
/*! AlphaCE2 - AlphaConstEnable2 */
#define fetchl16_LAYPRO2_AlphaCE2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_AlphaCE2_SHIFT)) & fetchl16_LAYPRO2_AlphaCE2_MASK)

#define fetchl16_LAYPRO2_AlpTE2_MASK             (0x800U)
#define fetchl16_LAYPRO2_AlpTE2_SHIFT            (11U)
/*! AlpTE2 - AlphaTransEnable2 */
#define fetchl16_LAYPRO2_AlpTE2(x)               (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_AlpTE2_SHIFT)) & fetchl16_LAYPRO2_AlpTE2_MASK)

#define fetchl16_LAYPRO2_RGBASEn2_MASK           (0x1000U)
#define fetchl16_LAYPRO2_RGBASEn2_SHIFT          (12U)
/*! RGBASEn2 - RGBAlphaSrcEnable2 */
#define fetchl16_LAYPRO2_RGBASEn2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_RGBASEn2_SHIFT)) & fetchl16_LAYPRO2_RGBASEn2_MASK)

#define fetchl16_LAYPRO2_RGBACEn2_MASK           (0x2000U)
#define fetchl16_LAYPRO2_RGBACEn2_SHIFT          (13U)
/*! RGBACEn2 - RGBAlphaConstEnable2 */
#define fetchl16_LAYPRO2_RGBACEn2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_RGBACEn2_SHIFT)) & fetchl16_LAYPRO2_RGBACEn2_MASK)

#define fetchl16_LAYPRO2_RGBATrE2_MASK           (0x8000U)
#define fetchl16_LAYPRO2_RGBATrE2_SHIFT          (15U)
/*! RGBATrE2 - RGBAlphaTransEnable2 */
#define fetchl16_LAYPRO2_RGBATrE2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_RGBATrE2_SHIFT)) & fetchl16_LAYPRO2_RGBATrE2_MASK)

#define fetchl16_LAYPRO2_PreCRGB2_MASK           (0x10000U)
#define fetchl16_LAYPRO2_PreCRGB2_SHIFT          (16U)
/*! PreCRGB2 - PremulConstRGB2 */
#define fetchl16_LAYPRO2_PreCRGB2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_PreCRGB2_SHIFT)) & fetchl16_LAYPRO2_PreCRGB2_MASK)

#define fetchl16_LAYPRO2_YUVConM2_MASK           (0x60000U)
#define fetchl16_LAYPRO2_YUVConM2_SHIFT          (17U)
/*! YUVConM2 - YUVConversionMode2
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchl16_LAYPRO2_YUVConM2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_YUVConM2_SHIFT)) & fetchl16_LAYPRO2_YUVConM2_MASK)

#define fetchl16_LAYPRO2_GamReE2_MASK            (0x100000U)
#define fetchl16_LAYPRO2_GamReE2_SHIFT           (20U)
/*! GamReE2 - GammaRemoveEnable2 */
#define fetchl16_LAYPRO2_GamReE2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_GamReE2_SHIFT)) & fetchl16_LAYPRO2_GamReE2_MASK)

#define fetchl16_LAYPRO2_ClipWE2_MASK            (0x40000000U)
#define fetchl16_LAYPRO2_ClipWE2_SHIFT           (30U)
/*! ClipWE2 - ClipWindowEnable2 */
#define fetchl16_LAYPRO2_ClipWE2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_ClipWE2_SHIFT)) & fetchl16_LAYPRO2_ClipWE2_MASK)

#define fetchl16_LAYPRO2_SrcBuEn2_MASK           (0x80000000U)
#define fetchl16_LAYPRO2_SrcBuEn2_SHIFT          (31U)
/*! SrcBuEn2 - SourceBufferEnable2 */
#define fetchl16_LAYPRO2_SrcBuEn2(x)             (((uint32_t)(((uint32_t)(x)) << fetchl16_LAYPRO2_SrcBuEn2_SHIFT)) & fetchl16_LAYPRO2_SrcBuEn2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchl16_Register_Masks */


/*!
 * @}
 */ /* end of group fetchl16_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHL16_H_ */

