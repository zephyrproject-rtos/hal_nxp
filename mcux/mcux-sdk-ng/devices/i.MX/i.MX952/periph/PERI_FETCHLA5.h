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
**         CMSIS Peripheral Access Layer for fetchla5
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
 * @file PERI_fetchla5.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchla5
 *
 * CMSIS Peripheral Access Layer for fetchla5
 */

#if !defined(PERI_FETCHLA5_H_)
#define PERI_FETCHLA5_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchla5 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla5_Peripheral_Access_Layer fetchla5 Peripheral Access Layer
 * @{
 */

/** fetchla5 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA4;                            /**< BaseAddress4, offset: 0x0 */
  __IO uint32_t BASAMSB4;                          /**< BaseAddressMSB4, offset: 0x4 */
  __IO uint32_t AUTOUBA4;                          /**< AutoUpdateBaseAddress4, offset: 0x8 */
  __IO uint32_t AUTUBAM4;                          /**< AutoUpdateBaseAddressMSB4, offset: 0xC */
  __IO uint32_t SOUBUAT4;                          /**< SourceBufferAttributes4, offset: 0x10 */
  __IO uint32_t SOUBUDI4;                          /**< SourceBufferDimension4, offset: 0x14 */
  __IO uint32_t COLCOMB4;                          /**< ColorComponentBits4, offset: 0x18 */
  __IO uint32_t COLCOMS4;                          /**< ColorComponentShift4, offset: 0x1C */
  __IO uint32_t LAYOFF4;                           /**< LayerOffset4, offset: 0x20 */
  __IO uint32_t CLIPWO4;                           /**< ClipWindowOffset4, offset: 0x24 */
  __IO uint32_t CLIPWID4;                          /**< ClipWindowDimensions4, offset: 0x28 */
  __IO uint32_t CONSTC4;                           /**< ConstantColor4, offset: 0x2C */
  __IO uint32_t LAYPRO4;                           /**< LayerProperty4, offset: 0x30 */
} fetchla5_Type;

/* ----------------------------------------------------------------------------
   -- fetchla5 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla5_Register_Masks fetchla5 Register Masks
 * @{
 */

/*! @name BASEA4 - BaseAddress4 */
/*! @{ */

#define fetchla5_BASEA4_BaseAdd4_MASK            (0xFFFFFFFFU)
#define fetchla5_BASEA4_BaseAdd4_SHIFT           (0U)
/*! BaseAdd4 - BaseAddress4 */
#define fetchla5_BASEA4_BaseAdd4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_BASEA4_BaseAdd4_SHIFT)) & fetchla5_BASEA4_BaseAdd4_MASK)
/*! @} */

/*! @name BASAMSB4 - BaseAddressMSB4 */
/*! @{ */

#define fetchla5_BASAMSB4_BaAdMB4_MASK           (0xFFU)
#define fetchla5_BASAMSB4_BaAdMB4_SHIFT          (0U)
/*! BaAdMB4 - BaseAddressMSB4 */
#define fetchla5_BASAMSB4_BaAdMB4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_BASAMSB4_BaAdMB4_SHIFT)) & fetchla5_BASAMSB4_BaAdMB4_MASK)
/*! @} */

/*! @name AUTOUBA4 - AutoUpdateBaseAddress4 */
/*! @{ */

#define fetchla5_AUTOUBA4_AutoUBA4_MASK          (0xFFFFFFFFU)
#define fetchla5_AUTOUBA4_AutoUBA4_SHIFT         (0U)
/*! AutoUBA4 - AutoUpdateBaseAddress4 */
#define fetchla5_AUTOUBA4_AutoUBA4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_AUTOUBA4_AutoUBA4_SHIFT)) & fetchla5_AUTOUBA4_AutoUBA4_MASK)
/*! @} */

/*! @name AUTUBAM4 - AutoUpdateBaseAddressMSB4 */
/*! @{ */

#define fetchla5_AUTUBAM4_AutoUBM4_MASK          (0xFFU)
#define fetchla5_AUTUBAM4_AutoUBM4_SHIFT         (0U)
/*! AutoUBM4 - AutoUpdateBaseAddressMSB4 */
#define fetchla5_AUTUBAM4_AutoUBM4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_AUTUBAM4_AutoUBM4_SHIFT)) & fetchla5_AUTUBAM4_AutoUBM4_MASK)
/*! @} */

/*! @name SOUBUAT4 - SourceBufferAttributes4 */
/*! @{ */

#define fetchla5_SOUBUAT4_Stride4_MASK           (0xFFFFU)
#define fetchla5_SOUBUAT4_Stride4_SHIFT          (0U)
/*! Stride4 - Stride4 */
#define fetchla5_SOUBUAT4_Stride4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_SOUBUAT4_Stride4_SHIFT)) & fetchla5_SOUBUAT4_Stride4_MASK)

#define fetchla5_SOUBUAT4_BitsPP4_MASK           (0x3F0000U)
#define fetchla5_SOUBUAT4_BitsPP4_SHIFT          (16U)
/*! BitsPP4 - BitsPerPixel4 */
#define fetchla5_SOUBUAT4_BitsPP4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_SOUBUAT4_BitsPP4_SHIFT)) & fetchla5_SOUBUAT4_BitsPP4_MASK)

#define fetchla5_SOUBUAT4_BaAdAU4_MASK           (0x40000000U)
#define fetchla5_SOUBUAT4_BaAdAU4_SHIFT          (30U)
/*! BaAdAU4 - BaseAddressAutoUpdate4 */
#define fetchla5_SOUBUAT4_BaAdAU4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_SOUBUAT4_BaAdAU4_SHIFT)) & fetchla5_SOUBUAT4_BaAdAU4_MASK)

#define fetchla5_SOUBUAT4_DWBS4_MASK             (0x80000000U)
#define fetchla5_SOUBUAT4_DWBS4_SHIFT            (31U)
/*! DWBS4 - DWordByteSwap4 */
#define fetchla5_SOUBUAT4_DWBS4(x)               (((uint32_t)(((uint32_t)(x)) << fetchla5_SOUBUAT4_DWBS4_SHIFT)) & fetchla5_SOUBUAT4_DWBS4_MASK)
/*! @} */

/*! @name SOUBUDI4 - SourceBufferDimension4 */
/*! @{ */

#define fetchla5_SOUBUDI4_LineW4_MASK            (0x3FFFU)
#define fetchla5_SOUBUDI4_LineW4_SHIFT           (0U)
/*! LineW4 - LineWidth4 */
#define fetchla5_SOUBUDI4_LineW4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_SOUBUDI4_LineW4_SHIFT)) & fetchla5_SOUBUDI4_LineW4_MASK)

#define fetchla5_SOUBUDI4_LineC4_MASK            (0x3FFF0000U)
#define fetchla5_SOUBUDI4_LineC4_SHIFT           (16U)
/*! LineC4 - LineCount4 */
#define fetchla5_SOUBUDI4_LineC4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_SOUBUDI4_LineC4_SHIFT)) & fetchla5_SOUBUDI4_LineC4_MASK)
/*! @} */

/*! @name COLCOMB4 - ColorComponentBits4 */
/*! @{ */

#define fetchla5_COLCOMB4_CompBiA4_MASK          (0xFU)
#define fetchla5_COLCOMB4_CompBiA4_SHIFT         (0U)
/*! CompBiA4 - ComponentBitsAlpha4 */
#define fetchla5_COLCOMB4_CompBiA4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMB4_CompBiA4_SHIFT)) & fetchla5_COLCOMB4_CompBiA4_MASK)

#define fetchla5_COLCOMB4_CompBiB4_MASK          (0xF00U)
#define fetchla5_COLCOMB4_CompBiB4_SHIFT         (8U)
/*! CompBiB4 - ComponentBitsBlue4 */
#define fetchla5_COLCOMB4_CompBiB4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMB4_CompBiB4_SHIFT)) & fetchla5_COLCOMB4_CompBiB4_MASK)

#define fetchla5_COLCOMB4_CompBiG4_MASK          (0xF0000U)
#define fetchla5_COLCOMB4_CompBiG4_SHIFT         (16U)
/*! CompBiG4 - ComponentBitsGreen4 */
#define fetchla5_COLCOMB4_CompBiG4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMB4_CompBiG4_SHIFT)) & fetchla5_COLCOMB4_CompBiG4_MASK)

#define fetchla5_COLCOMB4_CompBiR4_MASK          (0xF000000U)
#define fetchla5_COLCOMB4_CompBiR4_SHIFT         (24U)
/*! CompBiR4 - ComponentBitsRed4 */
#define fetchla5_COLCOMB4_CompBiR4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMB4_CompBiR4_SHIFT)) & fetchla5_COLCOMB4_CompBiR4_MASK)

#define fetchla5_COLCOMB4_ITUForm4_MASK          (0x80000000U)
#define fetchla5_COLCOMB4_ITUForm4_SHIFT         (31U)
/*! ITUForm4 - ITUFormat4 */
#define fetchla5_COLCOMB4_ITUForm4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMB4_ITUForm4_SHIFT)) & fetchla5_COLCOMB4_ITUForm4_MASK)
/*! @} */

/*! @name COLCOMS4 - ColorComponentShift4 */
/*! @{ */

#define fetchla5_COLCOMS4_CompShA4_MASK          (0x1FU)
#define fetchla5_COLCOMS4_CompShA4_SHIFT         (0U)
/*! CompShA4 - ComponentShiftAlpha4 */
#define fetchla5_COLCOMS4_CompShA4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMS4_CompShA4_SHIFT)) & fetchla5_COLCOMS4_CompShA4_MASK)

#define fetchla5_COLCOMS4_CompShB4_MASK          (0x1F00U)
#define fetchla5_COLCOMS4_CompShB4_SHIFT         (8U)
/*! CompShB4 - ComponentShiftBlue4 */
#define fetchla5_COLCOMS4_CompShB4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMS4_CompShB4_SHIFT)) & fetchla5_COLCOMS4_CompShB4_MASK)

#define fetchla5_COLCOMS4_CompShG4_MASK          (0x1F0000U)
#define fetchla5_COLCOMS4_CompShG4_SHIFT         (16U)
/*! CompShG4 - ComponentShiftGreen4 */
#define fetchla5_COLCOMS4_CompShG4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMS4_CompShG4_SHIFT)) & fetchla5_COLCOMS4_CompShG4_MASK)

#define fetchla5_COLCOMS4_CompShR4_MASK          (0x1F000000U)
#define fetchla5_COLCOMS4_CompShR4_SHIFT         (24U)
/*! CompShR4 - ComponentShiftRed4 */
#define fetchla5_COLCOMS4_CompShR4(x)            (((uint32_t)(((uint32_t)(x)) << fetchla5_COLCOMS4_CompShR4_SHIFT)) & fetchla5_COLCOMS4_CompShR4_MASK)
/*! @} */

/*! @name LAYOFF4 - LayerOffset4 */
/*! @{ */

#define fetchla5_LAYOFF4_LayXOs4_MASK            (0x7FFFU)
#define fetchla5_LAYOFF4_LayXOs4_SHIFT           (0U)
/*! LayXOs4 - LayerXOffset4 */
#define fetchla5_LAYOFF4_LayXOs4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYOFF4_LayXOs4_SHIFT)) & fetchla5_LAYOFF4_LayXOs4_MASK)

#define fetchla5_LAYOFF4_LayYOs4_MASK            (0x7FFF0000U)
#define fetchla5_LAYOFF4_LayYOs4_SHIFT           (16U)
/*! LayYOs4 - LayerYOffset4 */
#define fetchla5_LAYOFF4_LayYOs4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYOFF4_LayYOs4_SHIFT)) & fetchla5_LAYOFF4_LayYOs4_MASK)
/*! @} */

/*! @name CLIPWO4 - ClipWindowOffset4 */
/*! @{ */

#define fetchla5_CLIPWO4_ClipWXO4_MASK           (0x7FFFU)
#define fetchla5_CLIPWO4_ClipWXO4_SHIFT          (0U)
/*! ClipWXO4 - ClipWindowXOffset4 */
#define fetchla5_CLIPWO4_ClipWXO4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_CLIPWO4_ClipWXO4_SHIFT)) & fetchla5_CLIPWO4_ClipWXO4_MASK)

#define fetchla5_CLIPWO4_ClipWYO4_MASK           (0x7FFF0000U)
#define fetchla5_CLIPWO4_ClipWYO4_SHIFT          (16U)
/*! ClipWYO4 - ClipWindowYOffset4 */
#define fetchla5_CLIPWO4_ClipWYO4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_CLIPWO4_ClipWYO4_SHIFT)) & fetchla5_CLIPWO4_ClipWYO4_MASK)
/*! @} */

/*! @name CLIPWID4 - ClipWindowDimensions4 */
/*! @{ */

#define fetchla5_CLIPWID4_ClipWW4_MASK           (0x3FFFU)
#define fetchla5_CLIPWID4_ClipWW4_SHIFT          (0U)
/*! ClipWW4 - ClipWindowWidth4 */
#define fetchla5_CLIPWID4_ClipWW4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_CLIPWID4_ClipWW4_SHIFT)) & fetchla5_CLIPWID4_ClipWW4_MASK)

#define fetchla5_CLIPWID4_ClipWH4_MASK           (0x3FFF0000U)
#define fetchla5_CLIPWID4_ClipWH4_SHIFT          (16U)
/*! ClipWH4 - ClipWindowHeight4 */
#define fetchla5_CLIPWID4_ClipWH4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_CLIPWID4_ClipWH4_SHIFT)) & fetchla5_CLIPWID4_ClipWH4_MASK)
/*! @} */

/*! @name CONSTC4 - ConstantColor4 */
/*! @{ */

#define fetchla5_CONSTC4_ConstA4_MASK            (0xFFU)
#define fetchla5_CONSTC4_ConstA4_SHIFT           (0U)
/*! ConstA4 - ConstantAlpha4 */
#define fetchla5_CONSTC4_ConstA4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_CONSTC4_ConstA4_SHIFT)) & fetchla5_CONSTC4_ConstA4_MASK)

#define fetchla5_CONSTC4_ConstB4_MASK            (0xFF00U)
#define fetchla5_CONSTC4_ConstB4_SHIFT           (8U)
/*! ConstB4 - ConstantBlue4 */
#define fetchla5_CONSTC4_ConstB4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_CONSTC4_ConstB4_SHIFT)) & fetchla5_CONSTC4_ConstB4_MASK)

#define fetchla5_CONSTC4_ConstG4_MASK            (0xFF0000U)
#define fetchla5_CONSTC4_ConstG4_SHIFT           (16U)
/*! ConstG4 - ConstantGreen4 */
#define fetchla5_CONSTC4_ConstG4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_CONSTC4_ConstG4_SHIFT)) & fetchla5_CONSTC4_ConstG4_MASK)

#define fetchla5_CONSTC4_ConstR4_MASK            (0xFF000000U)
#define fetchla5_CONSTC4_ConstR4_SHIFT           (24U)
/*! ConstR4 - ConstantRed4 */
#define fetchla5_CONSTC4_ConstR4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_CONSTC4_ConstR4_SHIFT)) & fetchla5_CONSTC4_ConstR4_MASK)
/*! @} */

/*! @name LAYPRO4 - LayerProperty4 */
/*! @{ */

#define fetchla5_LAYPRO4_PaletE4_MASK            (0x1U)
#define fetchla5_LAYPRO4_PaletE4_SHIFT           (0U)
/*! PaletE4 - PaletteEnable4 */
#define fetchla5_LAYPRO4_PaletE4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_PaletE4_SHIFT)) & fetchla5_LAYPRO4_PaletE4_MASK)

#define fetchla5_LAYPRO4_TileMod4_MASK           (0x30U)
#define fetchla5_LAYPRO4_TileMod4_SHIFT          (4U)
/*! TileMod4 - TileMode4
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchla5_LAYPRO4_TileMod4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_TileMod4_SHIFT)) & fetchla5_LAYPRO4_TileMod4_MASK)

#define fetchla5_LAYPRO4_AlpSE4_MASK             (0x100U)
#define fetchla5_LAYPRO4_AlpSE4_SHIFT            (8U)
/*! AlpSE4 - AlphaSrcEnable4 */
#define fetchla5_LAYPRO4_AlpSE4(x)               (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_AlpSE4_SHIFT)) & fetchla5_LAYPRO4_AlpSE4_MASK)

#define fetchla5_LAYPRO4_AlphaCE4_MASK           (0x200U)
#define fetchla5_LAYPRO4_AlphaCE4_SHIFT          (9U)
/*! AlphaCE4 - AlphaConstEnable4 */
#define fetchla5_LAYPRO4_AlphaCE4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_AlphaCE4_SHIFT)) & fetchla5_LAYPRO4_AlphaCE4_MASK)

#define fetchla5_LAYPRO4_AlpTE4_MASK             (0x800U)
#define fetchla5_LAYPRO4_AlpTE4_SHIFT            (11U)
/*! AlpTE4 - AlphaTransEnable4 */
#define fetchla5_LAYPRO4_AlpTE4(x)               (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_AlpTE4_SHIFT)) & fetchla5_LAYPRO4_AlpTE4_MASK)

#define fetchla5_LAYPRO4_RGBASEn4_MASK           (0x1000U)
#define fetchla5_LAYPRO4_RGBASEn4_SHIFT          (12U)
/*! RGBASEn4 - RGBAlphaSrcEnable4 */
#define fetchla5_LAYPRO4_RGBASEn4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_RGBASEn4_SHIFT)) & fetchla5_LAYPRO4_RGBASEn4_MASK)

#define fetchla5_LAYPRO4_RGBACEn4_MASK           (0x2000U)
#define fetchla5_LAYPRO4_RGBACEn4_SHIFT          (13U)
/*! RGBACEn4 - RGBAlphaConstEnable4 */
#define fetchla5_LAYPRO4_RGBACEn4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_RGBACEn4_SHIFT)) & fetchla5_LAYPRO4_RGBACEn4_MASK)

#define fetchla5_LAYPRO4_RGBATrE4_MASK           (0x8000U)
#define fetchla5_LAYPRO4_RGBATrE4_SHIFT          (15U)
/*! RGBATrE4 - RGBAlphaTransEnable4 */
#define fetchla5_LAYPRO4_RGBATrE4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_RGBATrE4_SHIFT)) & fetchla5_LAYPRO4_RGBATrE4_MASK)

#define fetchla5_LAYPRO4_PreCRGB4_MASK           (0x10000U)
#define fetchla5_LAYPRO4_PreCRGB4_SHIFT          (16U)
/*! PreCRGB4 - PremulConstRGB4 */
#define fetchla5_LAYPRO4_PreCRGB4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_PreCRGB4_SHIFT)) & fetchla5_LAYPRO4_PreCRGB4_MASK)

#define fetchla5_LAYPRO4_YUVConM4_MASK           (0x60000U)
#define fetchla5_LAYPRO4_YUVConM4_SHIFT          (17U)
/*! YUVConM4 - YUVConversionMode4
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchla5_LAYPRO4_YUVConM4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_YUVConM4_SHIFT)) & fetchla5_LAYPRO4_YUVConM4_MASK)

#define fetchla5_LAYPRO4_GamReE4_MASK            (0x100000U)
#define fetchla5_LAYPRO4_GamReE4_SHIFT           (20U)
/*! GamReE4 - GammaRemoveEnable4 */
#define fetchla5_LAYPRO4_GamReE4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_GamReE4_SHIFT)) & fetchla5_LAYPRO4_GamReE4_MASK)

#define fetchla5_LAYPRO4_ClipWE4_MASK            (0x40000000U)
#define fetchla5_LAYPRO4_ClipWE4_SHIFT           (30U)
/*! ClipWE4 - ClipWindowEnable4 */
#define fetchla5_LAYPRO4_ClipWE4(x)              (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_ClipWE4_SHIFT)) & fetchla5_LAYPRO4_ClipWE4_MASK)

#define fetchla5_LAYPRO4_SrcBuEn4_MASK           (0x80000000U)
#define fetchla5_LAYPRO4_SrcBuEn4_SHIFT          (31U)
/*! SrcBuEn4 - SourceBufferEnable4 */
#define fetchla5_LAYPRO4_SrcBuEn4(x)             (((uint32_t)(((uint32_t)(x)) << fetchla5_LAYPRO4_SrcBuEn4_SHIFT)) & fetchla5_LAYPRO4_SrcBuEn4_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchla5_Register_Masks */


/*!
 * @}
 */ /* end of group fetchla5_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHLA5_H_ */

