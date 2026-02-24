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
**         CMSIS Peripheral Access Layer for fetchl21
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
 * @file PERI_fetchl21.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchl21
 *
 * CMSIS Peripheral Access Layer for fetchl21
 */

#if !defined(PERI_FETCHL21_H_)
#define PERI_FETCHL21_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchl21 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl21_Peripheral_Access_Layer fetchl21 Peripheral Access Layer
 * @{
 */

/** fetchl21 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA7;                            /**< BaseAddress7, offset: 0x0 */
  __IO uint32_t BASAMSB7;                          /**< BaseAddressMSB7, offset: 0x4 */
  __IO uint32_t AUTOUBA7;                          /**< AutoUpdateBaseAddress7, offset: 0x8 */
  __IO uint32_t AUTUBAM7;                          /**< AutoUpdateBaseAddressMSB7, offset: 0xC */
  __IO uint32_t SOUBUAT7;                          /**< SourceBufferAttributes7, offset: 0x10 */
  __IO uint32_t SOUBUDI7;                          /**< SourceBufferDimension7, offset: 0x14 */
  __IO uint32_t COLCOMB7;                          /**< ColorComponentBits7, offset: 0x18 */
  __IO uint32_t COLCOMS7;                          /**< ColorComponentShift7, offset: 0x1C */
  __IO uint32_t LAYOFF7;                           /**< LayerOffset7, offset: 0x20 */
  __IO uint32_t CLIPWO7;                           /**< ClipWindowOffset7, offset: 0x24 */
  __IO uint32_t CLIPWID7;                          /**< ClipWindowDimensions7, offset: 0x28 */
  __IO uint32_t CONSTC7;                           /**< ConstantColor7, offset: 0x2C */
  __IO uint32_t LAYPRO7;                           /**< LayerProperty7, offset: 0x30 */
} fetchl21_Type;

/* ----------------------------------------------------------------------------
   -- fetchl21 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl21_Register_Masks fetchl21 Register Masks
 * @{
 */

/*! @name BASEA7 - BaseAddress7 */
/*! @{ */

#define fetchl21_BASEA7_BaseAdd7_MASK            (0xFFFFFFFFU)
#define fetchl21_BASEA7_BaseAdd7_SHIFT           (0U)
/*! BaseAdd7 - BaseAddress7 */
#define fetchl21_BASEA7_BaseAdd7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_BASEA7_BaseAdd7_SHIFT)) & fetchl21_BASEA7_BaseAdd7_MASK)
/*! @} */

/*! @name BASAMSB7 - BaseAddressMSB7 */
/*! @{ */

#define fetchl21_BASAMSB7_BaAdMB8_MASK           (0xFFU)
#define fetchl21_BASAMSB7_BaAdMB8_SHIFT          (0U)
/*! BaAdMB8 - BaseAddressMSB7 */
#define fetchl21_BASAMSB7_BaAdMB8(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_BASAMSB7_BaAdMB8_SHIFT)) & fetchl21_BASAMSB7_BaAdMB8_MASK)
/*! @} */

/*! @name AUTOUBA7 - AutoUpdateBaseAddress7 */
/*! @{ */

#define fetchl21_AUTOUBA7_AutoUBA7_MASK          (0xFFFFFFFFU)
#define fetchl21_AUTOUBA7_AutoUBA7_SHIFT         (0U)
/*! AutoUBA7 - AutoUpdateBaseAddress7 */
#define fetchl21_AUTOUBA7_AutoUBA7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_AUTOUBA7_AutoUBA7_SHIFT)) & fetchl21_AUTOUBA7_AutoUBA7_MASK)
/*! @} */

/*! @name AUTUBAM7 - AutoUpdateBaseAddressMSB7 */
/*! @{ */

#define fetchl21_AUTUBAM7_AutoUBM7_MASK          (0xFFU)
#define fetchl21_AUTUBAM7_AutoUBM7_SHIFT         (0U)
/*! AutoUBM7 - AutoUpdateBaseAddressMSB7 */
#define fetchl21_AUTUBAM7_AutoUBM7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_AUTUBAM7_AutoUBM7_SHIFT)) & fetchl21_AUTUBAM7_AutoUBM7_MASK)
/*! @} */

/*! @name SOUBUAT7 - SourceBufferAttributes7 */
/*! @{ */

#define fetchl21_SOUBUAT7_Stride7_MASK           (0xFFFFU)
#define fetchl21_SOUBUAT7_Stride7_SHIFT          (0U)
/*! Stride7 - Stride7 */
#define fetchl21_SOUBUAT7_Stride7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_SOUBUAT7_Stride7_SHIFT)) & fetchl21_SOUBUAT7_Stride7_MASK)

#define fetchl21_SOUBUAT7_BitsPP7_MASK           (0x3F0000U)
#define fetchl21_SOUBUAT7_BitsPP7_SHIFT          (16U)
/*! BitsPP7 - BitsPerPixel7 */
#define fetchl21_SOUBUAT7_BitsPP7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_SOUBUAT7_BitsPP7_SHIFT)) & fetchl21_SOUBUAT7_BitsPP7_MASK)

#define fetchl21_SOUBUAT7_BaAdAU7_MASK           (0x40000000U)
#define fetchl21_SOUBUAT7_BaAdAU7_SHIFT          (30U)
/*! BaAdAU7 - BaseAddressAutoUpdate7 */
#define fetchl21_SOUBUAT7_BaAdAU7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_SOUBUAT7_BaAdAU7_SHIFT)) & fetchl21_SOUBUAT7_BaAdAU7_MASK)

#define fetchl21_SOUBUAT7_DWBS7_MASK             (0x80000000U)
#define fetchl21_SOUBUAT7_DWBS7_SHIFT            (31U)
/*! DWBS7 - DWordByteSwap7 */
#define fetchl21_SOUBUAT7_DWBS7(x)               (((uint32_t)(((uint32_t)(x)) << fetchl21_SOUBUAT7_DWBS7_SHIFT)) & fetchl21_SOUBUAT7_DWBS7_MASK)
/*! @} */

/*! @name SOUBUDI7 - SourceBufferDimension7 */
/*! @{ */

#define fetchl21_SOUBUDI7_LineW7_MASK            (0x3FFFU)
#define fetchl21_SOUBUDI7_LineW7_SHIFT           (0U)
/*! LineW7 - LineWidth7 */
#define fetchl21_SOUBUDI7_LineW7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_SOUBUDI7_LineW7_SHIFT)) & fetchl21_SOUBUDI7_LineW7_MASK)

#define fetchl21_SOUBUDI7_LineC7_MASK            (0x3FFF0000U)
#define fetchl21_SOUBUDI7_LineC7_SHIFT           (16U)
/*! LineC7 - LineCount7 */
#define fetchl21_SOUBUDI7_LineC7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_SOUBUDI7_LineC7_SHIFT)) & fetchl21_SOUBUDI7_LineC7_MASK)
/*! @} */

/*! @name COLCOMB7 - ColorComponentBits7 */
/*! @{ */

#define fetchl21_COLCOMB7_CompBiA7_MASK          (0xFU)
#define fetchl21_COLCOMB7_CompBiA7_SHIFT         (0U)
/*! CompBiA7 - ComponentBitsAlpha7 */
#define fetchl21_COLCOMB7_CompBiA7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMB7_CompBiA7_SHIFT)) & fetchl21_COLCOMB7_CompBiA7_MASK)

#define fetchl21_COLCOMB7_CompBiB7_MASK          (0xF00U)
#define fetchl21_COLCOMB7_CompBiB7_SHIFT         (8U)
/*! CompBiB7 - ComponentBitsBlue7 */
#define fetchl21_COLCOMB7_CompBiB7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMB7_CompBiB7_SHIFT)) & fetchl21_COLCOMB7_CompBiB7_MASK)

#define fetchl21_COLCOMB7_CompBiG7_MASK          (0xF0000U)
#define fetchl21_COLCOMB7_CompBiG7_SHIFT         (16U)
/*! CompBiG7 - ComponentBitsGreen7 */
#define fetchl21_COLCOMB7_CompBiG7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMB7_CompBiG7_SHIFT)) & fetchl21_COLCOMB7_CompBiG7_MASK)

#define fetchl21_COLCOMB7_CompBiR7_MASK          (0xF000000U)
#define fetchl21_COLCOMB7_CompBiR7_SHIFT         (24U)
/*! CompBiR7 - ComponentBitsRed7 */
#define fetchl21_COLCOMB7_CompBiR7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMB7_CompBiR7_SHIFT)) & fetchl21_COLCOMB7_CompBiR7_MASK)

#define fetchl21_COLCOMB7_ITUForm7_MASK          (0x80000000U)
#define fetchl21_COLCOMB7_ITUForm7_SHIFT         (31U)
/*! ITUForm7 - ITUFormat7 */
#define fetchl21_COLCOMB7_ITUForm7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMB7_ITUForm7_SHIFT)) & fetchl21_COLCOMB7_ITUForm7_MASK)
/*! @} */

/*! @name COLCOMS7 - ColorComponentShift7 */
/*! @{ */

#define fetchl21_COLCOMS7_CompShA7_MASK          (0x1FU)
#define fetchl21_COLCOMS7_CompShA7_SHIFT         (0U)
/*! CompShA7 - ComponentShiftAlpha7 */
#define fetchl21_COLCOMS7_CompShA7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMS7_CompShA7_SHIFT)) & fetchl21_COLCOMS7_CompShA7_MASK)

#define fetchl21_COLCOMS7_CompShB7_MASK          (0x1F00U)
#define fetchl21_COLCOMS7_CompShB7_SHIFT         (8U)
/*! CompShB7 - ComponentShiftBlue7 */
#define fetchl21_COLCOMS7_CompShB7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMS7_CompShB7_SHIFT)) & fetchl21_COLCOMS7_CompShB7_MASK)

#define fetchl21_COLCOMS7_CompShG7_MASK          (0x1F0000U)
#define fetchl21_COLCOMS7_CompShG7_SHIFT         (16U)
/*! CompShG7 - ComponentShiftGreen7 */
#define fetchl21_COLCOMS7_CompShG7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMS7_CompShG7_SHIFT)) & fetchl21_COLCOMS7_CompShG7_MASK)

#define fetchl21_COLCOMS7_CompShR7_MASK          (0x1F000000U)
#define fetchl21_COLCOMS7_CompShR7_SHIFT         (24U)
/*! CompShR7 - ComponentShiftRed7 */
#define fetchl21_COLCOMS7_CompShR7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl21_COLCOMS7_CompShR7_SHIFT)) & fetchl21_COLCOMS7_CompShR7_MASK)
/*! @} */

/*! @name LAYOFF7 - LayerOffset7 */
/*! @{ */

#define fetchl21_LAYOFF7_LayXOs7_MASK            (0x7FFFU)
#define fetchl21_LAYOFF7_LayXOs7_SHIFT           (0U)
/*! LayXOs7 - LayerXOffset7 */
#define fetchl21_LAYOFF7_LayXOs7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYOFF7_LayXOs7_SHIFT)) & fetchl21_LAYOFF7_LayXOs7_MASK)

#define fetchl21_LAYOFF7_LayYOs7_MASK            (0x7FFF0000U)
#define fetchl21_LAYOFF7_LayYOs7_SHIFT           (16U)
/*! LayYOs7 - LayerYOffset7 */
#define fetchl21_LAYOFF7_LayYOs7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYOFF7_LayYOs7_SHIFT)) & fetchl21_LAYOFF7_LayYOs7_MASK)
/*! @} */

/*! @name CLIPWO7 - ClipWindowOffset7 */
/*! @{ */

#define fetchl21_CLIPWO7_ClipWXO7_MASK           (0x7FFFU)
#define fetchl21_CLIPWO7_ClipWXO7_SHIFT          (0U)
/*! ClipWXO7 - ClipWindowXOffset7 */
#define fetchl21_CLIPWO7_ClipWXO7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_CLIPWO7_ClipWXO7_SHIFT)) & fetchl21_CLIPWO7_ClipWXO7_MASK)

#define fetchl21_CLIPWO7_ClipWYO7_MASK           (0x7FFF0000U)
#define fetchl21_CLIPWO7_ClipWYO7_SHIFT          (16U)
/*! ClipWYO7 - ClipWindowYOffset7 */
#define fetchl21_CLIPWO7_ClipWYO7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_CLIPWO7_ClipWYO7_SHIFT)) & fetchl21_CLIPWO7_ClipWYO7_MASK)
/*! @} */

/*! @name CLIPWID7 - ClipWindowDimensions7 */
/*! @{ */

#define fetchl21_CLIPWID7_ClipWW7_MASK           (0x3FFFU)
#define fetchl21_CLIPWID7_ClipWW7_SHIFT          (0U)
/*! ClipWW7 - ClipWindowWidth7 */
#define fetchl21_CLIPWID7_ClipWW7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_CLIPWID7_ClipWW7_SHIFT)) & fetchl21_CLIPWID7_ClipWW7_MASK)

#define fetchl21_CLIPWID7_ClipWH7_MASK           (0x3FFF0000U)
#define fetchl21_CLIPWID7_ClipWH7_SHIFT          (16U)
/*! ClipWH7 - ClipWindowHeight7 */
#define fetchl21_CLIPWID7_ClipWH7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_CLIPWID7_ClipWH7_SHIFT)) & fetchl21_CLIPWID7_ClipWH7_MASK)
/*! @} */

/*! @name CONSTC7 - ConstantColor7 */
/*! @{ */

#define fetchl21_CONSTC7_ConstA7_MASK            (0xFFU)
#define fetchl21_CONSTC7_ConstA7_SHIFT           (0U)
/*! ConstA7 - ConstantAlpha7 */
#define fetchl21_CONSTC7_ConstA7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_CONSTC7_ConstA7_SHIFT)) & fetchl21_CONSTC7_ConstA7_MASK)

#define fetchl21_CONSTC7_ConstB7_MASK            (0xFF00U)
#define fetchl21_CONSTC7_ConstB7_SHIFT           (8U)
/*! ConstB7 - ConstantBlue7 */
#define fetchl21_CONSTC7_ConstB7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_CONSTC7_ConstB7_SHIFT)) & fetchl21_CONSTC7_ConstB7_MASK)

#define fetchl21_CONSTC7_ConstG7_MASK            (0xFF0000U)
#define fetchl21_CONSTC7_ConstG7_SHIFT           (16U)
/*! ConstG7 - ConstantGreen7 */
#define fetchl21_CONSTC7_ConstG7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_CONSTC7_ConstG7_SHIFT)) & fetchl21_CONSTC7_ConstG7_MASK)

#define fetchl21_CONSTC7_ConstR7_MASK            (0xFF000000U)
#define fetchl21_CONSTC7_ConstR7_SHIFT           (24U)
/*! ConstR7 - ConstantRed7 */
#define fetchl21_CONSTC7_ConstR7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_CONSTC7_ConstR7_SHIFT)) & fetchl21_CONSTC7_ConstR7_MASK)
/*! @} */

/*! @name LAYPRO7 - LayerProperty7 */
/*! @{ */

#define fetchl21_LAYPRO7_PaletE7_MASK            (0x1U)
#define fetchl21_LAYPRO7_PaletE7_SHIFT           (0U)
/*! PaletE7 - PaletteEnable7 */
#define fetchl21_LAYPRO7_PaletE7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_PaletE7_SHIFT)) & fetchl21_LAYPRO7_PaletE7_MASK)

#define fetchl21_LAYPRO7_TileMod7_MASK           (0x30U)
#define fetchl21_LAYPRO7_TileMod7_SHIFT          (4U)
/*! TileMod7 - TileMode7
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchl21_LAYPRO7_TileMod7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_TileMod7_SHIFT)) & fetchl21_LAYPRO7_TileMod7_MASK)

#define fetchl21_LAYPRO7_AlpSE7_MASK             (0x100U)
#define fetchl21_LAYPRO7_AlpSE7_SHIFT            (8U)
/*! AlpSE7 - AlphaSrcEnable7 */
#define fetchl21_LAYPRO7_AlpSE7(x)               (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_AlpSE7_SHIFT)) & fetchl21_LAYPRO7_AlpSE7_MASK)

#define fetchl21_LAYPRO7_AlphaCE7_MASK           (0x200U)
#define fetchl21_LAYPRO7_AlphaCE7_SHIFT          (9U)
/*! AlphaCE7 - AlphaConstEnable7 */
#define fetchl21_LAYPRO7_AlphaCE7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_AlphaCE7_SHIFT)) & fetchl21_LAYPRO7_AlphaCE7_MASK)

#define fetchl21_LAYPRO7_AlpTE7_MASK             (0x800U)
#define fetchl21_LAYPRO7_AlpTE7_SHIFT            (11U)
/*! AlpTE7 - AlphaTransEnable7 */
#define fetchl21_LAYPRO7_AlpTE7(x)               (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_AlpTE7_SHIFT)) & fetchl21_LAYPRO7_AlpTE7_MASK)

#define fetchl21_LAYPRO7_RGBASEn7_MASK           (0x1000U)
#define fetchl21_LAYPRO7_RGBASEn7_SHIFT          (12U)
/*! RGBASEn7 - RGBAlphaSrcEnable7 */
#define fetchl21_LAYPRO7_RGBASEn7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_RGBASEn7_SHIFT)) & fetchl21_LAYPRO7_RGBASEn7_MASK)

#define fetchl21_LAYPRO7_RGBACEn7_MASK           (0x2000U)
#define fetchl21_LAYPRO7_RGBACEn7_SHIFT          (13U)
/*! RGBACEn7 - RGBAlphaConstEnable7 */
#define fetchl21_LAYPRO7_RGBACEn7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_RGBACEn7_SHIFT)) & fetchl21_LAYPRO7_RGBACEn7_MASK)

#define fetchl21_LAYPRO7_RGBATrE7_MASK           (0x8000U)
#define fetchl21_LAYPRO7_RGBATrE7_SHIFT          (15U)
/*! RGBATrE7 - RGBAlphaTransEnable7 */
#define fetchl21_LAYPRO7_RGBATrE7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_RGBATrE7_SHIFT)) & fetchl21_LAYPRO7_RGBATrE7_MASK)

#define fetchl21_LAYPRO7_PreCRGB7_MASK           (0x10000U)
#define fetchl21_LAYPRO7_PreCRGB7_SHIFT          (16U)
/*! PreCRGB7 - PremulConstRGB7 */
#define fetchl21_LAYPRO7_PreCRGB7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_PreCRGB7_SHIFT)) & fetchl21_LAYPRO7_PreCRGB7_MASK)

#define fetchl21_LAYPRO7_YUVConM7_MASK           (0x60000U)
#define fetchl21_LAYPRO7_YUVConM7_SHIFT          (17U)
/*! YUVConM7 - YUVConversionMode7
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchl21_LAYPRO7_YUVConM7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_YUVConM7_SHIFT)) & fetchl21_LAYPRO7_YUVConM7_MASK)

#define fetchl21_LAYPRO7_GamReE7_MASK            (0x100000U)
#define fetchl21_LAYPRO7_GamReE7_SHIFT           (20U)
/*! GamReE7 - GammaRemoveEnable7 */
#define fetchl21_LAYPRO7_GamReE7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_GamReE7_SHIFT)) & fetchl21_LAYPRO7_GamReE7_MASK)

#define fetchl21_LAYPRO7_ClipWE7_MASK            (0x40000000U)
#define fetchl21_LAYPRO7_ClipWE7_SHIFT           (30U)
/*! ClipWE7 - ClipWindowEnable7 */
#define fetchl21_LAYPRO7_ClipWE7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_ClipWE7_SHIFT)) & fetchl21_LAYPRO7_ClipWE7_MASK)

#define fetchl21_LAYPRO7_SrcBuEn7_MASK           (0x80000000U)
#define fetchl21_LAYPRO7_SrcBuEn7_SHIFT          (31U)
/*! SrcBuEn7 - SourceBufferEnable7 */
#define fetchl21_LAYPRO7_SrcBuEn7(x)             (((uint32_t)(((uint32_t)(x)) << fetchl21_LAYPRO7_SrcBuEn7_SHIFT)) & fetchl21_LAYPRO7_SrcBuEn7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchl21_Register_Masks */


/*!
 * @}
 */ /* end of group fetchl21_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHL21_H_ */

