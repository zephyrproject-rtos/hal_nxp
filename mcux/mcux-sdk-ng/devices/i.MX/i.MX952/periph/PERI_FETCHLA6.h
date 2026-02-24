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
**         CMSIS Peripheral Access Layer for fetchla6
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
 * @file PERI_fetchla6.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchla6
 *
 * CMSIS Peripheral Access Layer for fetchla6
 */

#if !defined(PERI_FETCHLA6_H_)
#define PERI_FETCHLA6_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchla6 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla6_Peripheral_Access_Layer fetchla6 Peripheral Access Layer
 * @{
 */

/** fetchla6 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA5;                            /**< BaseAddress5, offset: 0x0 */
  __IO uint32_t BASAMSB5;                          /**< BaseAddressMSB5, offset: 0x4 */
  __IO uint32_t AUTOUBA5;                          /**< AutoUpdateBaseAddress5, offset: 0x8 */
  __IO uint32_t AUTUBAM5;                          /**< AutoUpdateBaseAddressMSB5, offset: 0xC */
  __IO uint32_t SOUBUAT5;                          /**< SourceBufferAttributes5, offset: 0x10 */
  __IO uint32_t SOUBUDI5;                          /**< SourceBufferDimension5, offset: 0x14 */
  __IO uint32_t COLCOMB5;                          /**< ColorComponentBits5, offset: 0x18 */
  __IO uint32_t COLCOMS5;                          /**< ColorComponentShift5, offset: 0x1C */
  __IO uint32_t LAYOFF5;                           /**< LayerOffset5, offset: 0x20 */
  __IO uint32_t CLIPWO5;                           /**< ClipWindowOffset5, offset: 0x24 */
  __IO uint32_t CLIPWID5;                          /**< ClipWindowDimensions5, offset: 0x28 */
  __IO uint32_t CONSTC5;                           /**< ConstantColor5, offset: 0x2C */
  __IO uint32_t LAYROP5;                           /**< LayerProperty5, offset: 0x30 */
} fetchla6_Type;

/* ----------------------------------------------------------------------------
   -- fetchla6 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla6_Register_Masks fetchla6 Register Masks
 * @{
 */

/*! @name BASEA5 - BaseAddress5 */
/*! @{ */

#define fetchla6_BASEA5_BaseAdd5_MASK            (0xFFFFFFFFU)
#define fetchla6_BASEA5_BaseAdd5_SHIFT           (0U)
/*! BaseAdd5 - BaseAddress5 */
#define fetchla6_BASEA5_BaseAdd5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_BASEA5_BaseAdd5_SHIFT)) & fetchla6_BASEA5_BaseAdd5_MASK)
/*! @} */

/*! @name BASAMSB5 - BaseAddressMSB5 */
/*! @{ */

#define fetchla6_BASAMSB5_BaAdMB5_MASK           (0xFFU)
#define fetchla6_BASAMSB5_BaAdMB5_SHIFT          (0U)
/*! BaAdMB5 - BaseAddressMSB5 */
#define fetchla6_BASAMSB5_BaAdMB5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_BASAMSB5_BaAdMB5_SHIFT)) & fetchla6_BASAMSB5_BaAdMB5_MASK)
/*! @} */

/*! @name AUTOUBA5 - AutoUpdateBaseAddress5 */
/*! @{ */

#define fetchla6_AUTOUBA5_AutoUBA5_MASK          (0xFFFFFFFFU)
#define fetchla6_AUTOUBA5_AutoUBA5_SHIFT         (0U)
/*! AutoUBA5 - AutoUpdateBaseAddress5 */
#define fetchla6_AUTOUBA5_AutoUBA5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_AUTOUBA5_AutoUBA5_SHIFT)) & fetchla6_AUTOUBA5_AutoUBA5_MASK)
/*! @} */

/*! @name AUTUBAM5 - AutoUpdateBaseAddressMSB5 */
/*! @{ */

#define fetchla6_AUTUBAM5_AutoUBM5_MASK          (0xFFU)
#define fetchla6_AUTUBAM5_AutoUBM5_SHIFT         (0U)
/*! AutoUBM5 - AutoUpdateBaseAddressMSB5 */
#define fetchla6_AUTUBAM5_AutoUBM5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_AUTUBAM5_AutoUBM5_SHIFT)) & fetchla6_AUTUBAM5_AutoUBM5_MASK)
/*! @} */

/*! @name SOUBUAT5 - SourceBufferAttributes5 */
/*! @{ */

#define fetchla6_SOUBUAT5_Stride5_MASK           (0xFFFFU)
#define fetchla6_SOUBUAT5_Stride5_SHIFT          (0U)
/*! Stride5 - Stride5 */
#define fetchla6_SOUBUAT5_Stride5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_SOUBUAT5_Stride5_SHIFT)) & fetchla6_SOUBUAT5_Stride5_MASK)

#define fetchla6_SOUBUAT5_BitsPP5_MASK           (0x3F0000U)
#define fetchla6_SOUBUAT5_BitsPP5_SHIFT          (16U)
/*! BitsPP5 - BitsPerPixel5 */
#define fetchla6_SOUBUAT5_BitsPP5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_SOUBUAT5_BitsPP5_SHIFT)) & fetchla6_SOUBUAT5_BitsPP5_MASK)

#define fetchla6_SOUBUAT5_BaAdAU5_MASK           (0x40000000U)
#define fetchla6_SOUBUAT5_BaAdAU5_SHIFT          (30U)
/*! BaAdAU5 - BaseAddressAutoUpdate5 */
#define fetchla6_SOUBUAT5_BaAdAU5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_SOUBUAT5_BaAdAU5_SHIFT)) & fetchla6_SOUBUAT5_BaAdAU5_MASK)

#define fetchla6_SOUBUAT5_DWBS5_MASK             (0x80000000U)
#define fetchla6_SOUBUAT5_DWBS5_SHIFT            (31U)
/*! DWBS5 - DWordByteSwap5 */
#define fetchla6_SOUBUAT5_DWBS5(x)               (((uint32_t)(((uint32_t)(x)) << fetchla6_SOUBUAT5_DWBS5_SHIFT)) & fetchla6_SOUBUAT5_DWBS5_MASK)
/*! @} */

/*! @name SOUBUDI5 - SourceBufferDimension5 */
/*! @{ */

#define fetchla6_SOUBUDI5_LineW5_MASK            (0x3FFFU)
#define fetchla6_SOUBUDI5_LineW5_SHIFT           (0U)
/*! LineW5 - LineWidth5 */
#define fetchla6_SOUBUDI5_LineW5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_SOUBUDI5_LineW5_SHIFT)) & fetchla6_SOUBUDI5_LineW5_MASK)

#define fetchla6_SOUBUDI5_LineC5_MASK            (0x3FFF0000U)
#define fetchla6_SOUBUDI5_LineC5_SHIFT           (16U)
/*! LineC5 - LineCount5 */
#define fetchla6_SOUBUDI5_LineC5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_SOUBUDI5_LineC5_SHIFT)) & fetchla6_SOUBUDI5_LineC5_MASK)
/*! @} */

/*! @name COLCOMB5 - ColorComponentBits5 */
/*! @{ */

#define fetchla6_COLCOMB5_CompBiA5_MASK          (0xFU)
#define fetchla6_COLCOMB5_CompBiA5_SHIFT         (0U)
/*! CompBiA5 - ComponentBitsAlpha5 */
#define fetchla6_COLCOMB5_CompBiA5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMB5_CompBiA5_SHIFT)) & fetchla6_COLCOMB5_CompBiA5_MASK)

#define fetchla6_COLCOMB5_CompBiB5_MASK          (0xF00U)
#define fetchla6_COLCOMB5_CompBiB5_SHIFT         (8U)
/*! CompBiB5 - ComponentBitsBlue5 */
#define fetchla6_COLCOMB5_CompBiB5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMB5_CompBiB5_SHIFT)) & fetchla6_COLCOMB5_CompBiB5_MASK)

#define fetchla6_COLCOMB5_CompBiG5_MASK          (0xF0000U)
#define fetchla6_COLCOMB5_CompBiG5_SHIFT         (16U)
/*! CompBiG5 - ComponentBitsGreen5 */
#define fetchla6_COLCOMB5_CompBiG5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMB5_CompBiG5_SHIFT)) & fetchla6_COLCOMB5_CompBiG5_MASK)

#define fetchla6_COLCOMB5_CompBiR5_MASK          (0xF000000U)
#define fetchla6_COLCOMB5_CompBiR5_SHIFT         (24U)
/*! CompBiR5 - ComponentBitsRed5 */
#define fetchla6_COLCOMB5_CompBiR5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMB5_CompBiR5_SHIFT)) & fetchla6_COLCOMB5_CompBiR5_MASK)

#define fetchla6_COLCOMB5_ITUForm5_MASK          (0x80000000U)
#define fetchla6_COLCOMB5_ITUForm5_SHIFT         (31U)
/*! ITUForm5 - ITUFormat5 */
#define fetchla6_COLCOMB5_ITUForm5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMB5_ITUForm5_SHIFT)) & fetchla6_COLCOMB5_ITUForm5_MASK)
/*! @} */

/*! @name COLCOMS5 - ColorComponentShift5 */
/*! @{ */

#define fetchla6_COLCOMS5_CompShA5_MASK          (0x1FU)
#define fetchla6_COLCOMS5_CompShA5_SHIFT         (0U)
/*! CompShA5 - ComponentShiftAlpha5 */
#define fetchla6_COLCOMS5_CompShA5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMS5_CompShA5_SHIFT)) & fetchla6_COLCOMS5_CompShA5_MASK)

#define fetchla6_COLCOMS5_CompShB5_MASK          (0x1F00U)
#define fetchla6_COLCOMS5_CompShB5_SHIFT         (8U)
/*! CompShB5 - ComponentShiftBlue5 */
#define fetchla6_COLCOMS5_CompShB5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMS5_CompShB5_SHIFT)) & fetchla6_COLCOMS5_CompShB5_MASK)

#define fetchla6_COLCOMS5_CompShG5_MASK          (0x1F0000U)
#define fetchla6_COLCOMS5_CompShG5_SHIFT         (16U)
/*! CompShG5 - ComponentShiftGreen5 */
#define fetchla6_COLCOMS5_CompShG5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMS5_CompShG5_SHIFT)) & fetchla6_COLCOMS5_CompShG5_MASK)

#define fetchla6_COLCOMS5_CompShR5_MASK          (0x1F000000U)
#define fetchla6_COLCOMS5_CompShR5_SHIFT         (24U)
/*! CompShR5 - ComponentShiftRed5 */
#define fetchla6_COLCOMS5_CompShR5(x)            (((uint32_t)(((uint32_t)(x)) << fetchla6_COLCOMS5_CompShR5_SHIFT)) & fetchla6_COLCOMS5_CompShR5_MASK)
/*! @} */

/*! @name LAYOFF5 - LayerOffset5 */
/*! @{ */

#define fetchla6_LAYOFF5_LayXOs5_MASK            (0x7FFFU)
#define fetchla6_LAYOFF5_LayXOs5_SHIFT           (0U)
/*! LayXOs5 - LayerXOffset5 */
#define fetchla6_LAYOFF5_LayXOs5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYOFF5_LayXOs5_SHIFT)) & fetchla6_LAYOFF5_LayXOs5_MASK)

#define fetchla6_LAYOFF5_LayYOs5_MASK            (0x7FFF0000U)
#define fetchla6_LAYOFF5_LayYOs5_SHIFT           (16U)
/*! LayYOs5 - LayerYOffset5 */
#define fetchla6_LAYOFF5_LayYOs5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYOFF5_LayYOs5_SHIFT)) & fetchla6_LAYOFF5_LayYOs5_MASK)
/*! @} */

/*! @name CLIPWO5 - ClipWindowOffset5 */
/*! @{ */

#define fetchla6_CLIPWO5_ClipWXO5_MASK           (0x7FFFU)
#define fetchla6_CLIPWO5_ClipWXO5_SHIFT          (0U)
/*! ClipWXO5 - ClipWindowXOffset5 */
#define fetchla6_CLIPWO5_ClipWXO5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_CLIPWO5_ClipWXO5_SHIFT)) & fetchla6_CLIPWO5_ClipWXO5_MASK)

#define fetchla6_CLIPWO5_ClipWYO5_MASK           (0x7FFF0000U)
#define fetchla6_CLIPWO5_ClipWYO5_SHIFT          (16U)
/*! ClipWYO5 - ClipWindowYOffset5 */
#define fetchla6_CLIPWO5_ClipWYO5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_CLIPWO5_ClipWYO5_SHIFT)) & fetchla6_CLIPWO5_ClipWYO5_MASK)
/*! @} */

/*! @name CLIPWID5 - ClipWindowDimensions5 */
/*! @{ */

#define fetchla6_CLIPWID5_ClipWW5_MASK           (0x3FFFU)
#define fetchla6_CLIPWID5_ClipWW5_SHIFT          (0U)
/*! ClipWW5 - ClipWindowWidth5 */
#define fetchla6_CLIPWID5_ClipWW5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_CLIPWID5_ClipWW5_SHIFT)) & fetchla6_CLIPWID5_ClipWW5_MASK)

#define fetchla6_CLIPWID5_ClipWH5_MASK           (0x3FFF0000U)
#define fetchla6_CLIPWID5_ClipWH5_SHIFT          (16U)
/*! ClipWH5 - ClipWindowHeight5 */
#define fetchla6_CLIPWID5_ClipWH5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_CLIPWID5_ClipWH5_SHIFT)) & fetchla6_CLIPWID5_ClipWH5_MASK)
/*! @} */

/*! @name CONSTC5 - ConstantColor5 */
/*! @{ */

#define fetchla6_CONSTC5_ConstA5_MASK            (0xFFU)
#define fetchla6_CONSTC5_ConstA5_SHIFT           (0U)
/*! ConstA5 - ConstantAlpha5 */
#define fetchla6_CONSTC5_ConstA5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_CONSTC5_ConstA5_SHIFT)) & fetchla6_CONSTC5_ConstA5_MASK)

#define fetchla6_CONSTC5_ConstB5_MASK            (0xFF00U)
#define fetchla6_CONSTC5_ConstB5_SHIFT           (8U)
/*! ConstB5 - ConstantBlue5 */
#define fetchla6_CONSTC5_ConstB5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_CONSTC5_ConstB5_SHIFT)) & fetchla6_CONSTC5_ConstB5_MASK)

#define fetchla6_CONSTC5_ConstG5_MASK            (0xFF0000U)
#define fetchla6_CONSTC5_ConstG5_SHIFT           (16U)
/*! ConstG5 - ConstantGreen5 */
#define fetchla6_CONSTC5_ConstG5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_CONSTC5_ConstG5_SHIFT)) & fetchla6_CONSTC5_ConstG5_MASK)

#define fetchla6_CONSTC5_ConstR5_MASK            (0xFF000000U)
#define fetchla6_CONSTC5_ConstR5_SHIFT           (24U)
/*! ConstR5 - ConstantRed5 */
#define fetchla6_CONSTC5_ConstR5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_CONSTC5_ConstR5_SHIFT)) & fetchla6_CONSTC5_ConstR5_MASK)
/*! @} */

/*! @name LAYROP5 - LayerProperty5 */
/*! @{ */

#define fetchla6_LAYROP5_PaletE5_MASK            (0x1U)
#define fetchla6_LAYROP5_PaletE5_SHIFT           (0U)
/*! PaletE5 - PaletteEnable5 */
#define fetchla6_LAYROP5_PaletE5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_PaletE5_SHIFT)) & fetchla6_LAYROP5_PaletE5_MASK)

#define fetchla6_LAYROP5_TileMod5_MASK           (0x30U)
#define fetchla6_LAYROP5_TileMod5_SHIFT          (4U)
/*! TileMod5 - TileMode5
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchla6_LAYROP5_TileMod5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_TileMod5_SHIFT)) & fetchla6_LAYROP5_TileMod5_MASK)

#define fetchla6_LAYROP5_AlpSE5_MASK             (0x100U)
#define fetchla6_LAYROP5_AlpSE5_SHIFT            (8U)
/*! AlpSE5 - AlphaSrcEnable5 */
#define fetchla6_LAYROP5_AlpSE5(x)               (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_AlpSE5_SHIFT)) & fetchla6_LAYROP5_AlpSE5_MASK)

#define fetchla6_LAYROP5_AlphaCE5_MASK           (0x200U)
#define fetchla6_LAYROP5_AlphaCE5_SHIFT          (9U)
/*! AlphaCE5 - AlphaConstEnable5 */
#define fetchla6_LAYROP5_AlphaCE5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_AlphaCE5_SHIFT)) & fetchla6_LAYROP5_AlphaCE5_MASK)

#define fetchla6_LAYROP5_AlpTE5_MASK             (0x800U)
#define fetchla6_LAYROP5_AlpTE5_SHIFT            (11U)
/*! AlpTE5 - AlphaTransEnable5 */
#define fetchla6_LAYROP5_AlpTE5(x)               (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_AlpTE5_SHIFT)) & fetchla6_LAYROP5_AlpTE5_MASK)

#define fetchla6_LAYROP5_RGBASEn5_MASK           (0x1000U)
#define fetchla6_LAYROP5_RGBASEn5_SHIFT          (12U)
/*! RGBASEn5 - RGBAlphaSrcEnable5 */
#define fetchla6_LAYROP5_RGBASEn5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_RGBASEn5_SHIFT)) & fetchla6_LAYROP5_RGBASEn5_MASK)

#define fetchla6_LAYROP5_RGBACEn5_MASK           (0x2000U)
#define fetchla6_LAYROP5_RGBACEn5_SHIFT          (13U)
/*! RGBACEn5 - RGBAlphaConstEnable5 */
#define fetchla6_LAYROP5_RGBACEn5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_RGBACEn5_SHIFT)) & fetchla6_LAYROP5_RGBACEn5_MASK)

#define fetchla6_LAYROP5_RGBATrE5_MASK           (0x8000U)
#define fetchla6_LAYROP5_RGBATrE5_SHIFT          (15U)
/*! RGBATrE5 - RGBAlphaTransEnable5 */
#define fetchla6_LAYROP5_RGBATrE5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_RGBATrE5_SHIFT)) & fetchla6_LAYROP5_RGBATrE5_MASK)

#define fetchla6_LAYROP5_PreCRGB5_MASK           (0x10000U)
#define fetchla6_LAYROP5_PreCRGB5_SHIFT          (16U)
/*! PreCRGB5 - PremulConstRGB5 */
#define fetchla6_LAYROP5_PreCRGB5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_PreCRGB5_SHIFT)) & fetchla6_LAYROP5_PreCRGB5_MASK)

#define fetchla6_LAYROP5_YUVConM5_MASK           (0x60000U)
#define fetchla6_LAYROP5_YUVConM5_SHIFT          (17U)
/*! YUVConM5 - YUVConversionMode5
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchla6_LAYROP5_YUVConM5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_YUVConM5_SHIFT)) & fetchla6_LAYROP5_YUVConM5_MASK)

#define fetchla6_LAYROP5_GamReE5_MASK            (0x100000U)
#define fetchla6_LAYROP5_GamReE5_SHIFT           (20U)
/*! GamReE5 - GammaRemoveEnable5 */
#define fetchla6_LAYROP5_GamReE5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_GamReE5_SHIFT)) & fetchla6_LAYROP5_GamReE5_MASK)

#define fetchla6_LAYROP5_ClipWE5_MASK            (0x40000000U)
#define fetchla6_LAYROP5_ClipWE5_SHIFT           (30U)
/*! ClipWE5 - ClipWindowEnable5 */
#define fetchla6_LAYROP5_ClipWE5(x)              (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_ClipWE5_SHIFT)) & fetchla6_LAYROP5_ClipWE5_MASK)

#define fetchla6_LAYROP5_SrcBuEn5_MASK           (0x80000000U)
#define fetchla6_LAYROP5_SrcBuEn5_SHIFT          (31U)
/*! SrcBuEn5 - SourceBufferEnable5 */
#define fetchla6_LAYROP5_SrcBuEn5(x)             (((uint32_t)(((uint32_t)(x)) << fetchla6_LAYROP5_SrcBuEn5_SHIFT)) & fetchla6_LAYROP5_SrcBuEn5_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchla6_Register_Masks */


/*!
 * @}
 */ /* end of group fetchla6_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHLA6_H_ */

