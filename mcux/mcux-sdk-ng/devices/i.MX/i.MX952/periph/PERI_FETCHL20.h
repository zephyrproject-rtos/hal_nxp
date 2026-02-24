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
**         CMSIS Peripheral Access Layer for fetchl20
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
 * @file PERI_fetchl20.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchl20
 *
 * CMSIS Peripheral Access Layer for fetchl20
 */

#if !defined(PERI_FETCHL20_H_)
#define PERI_FETCHL20_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchl20 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl20_Peripheral_Access_Layer fetchl20 Peripheral Access Layer
 * @{
 */

/** fetchl20 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA6;                            /**< BaseAddress6, offset: 0x0 */
  __IO uint32_t BASAMSB6;                          /**< BaseAddressMSB6, offset: 0x4 */
  __IO uint32_t AUTOUBA6;                          /**< AutoUpdateBaseAddress6, offset: 0x8 */
  __IO uint32_t AUTUBAM6;                          /**< AutoUpdateBaseAddressMSB6, offset: 0xC */
  __IO uint32_t SOUBUAT6;                          /**< SourceBufferAttributes6, offset: 0x10 */
  __IO uint32_t SOUBUDI6;                          /**< SourceBufferDimension6, offset: 0x14 */
  __IO uint32_t COLCOMB6;                          /**< ColorComponentBits6, offset: 0x18 */
  __IO uint32_t COLCOMS6;                          /**< ColorComponentShift6, offset: 0x1C */
  __IO uint32_t LAYOFF6;                           /**< LayerOffset6, offset: 0x20 */
  __IO uint32_t CLIPWO6;                           /**< ClipWindowOffset6, offset: 0x24 */
  __IO uint32_t CLIPWID6;                          /**< ClipWindowDimensions6, offset: 0x28 */
  __IO uint32_t CONSTC6;                           /**< ConstantColor6, offset: 0x2C */
  __IO uint32_t LAYPRO6;                           /**< LayerProperty6, offset: 0x30 */
} fetchl20_Type;

/* ----------------------------------------------------------------------------
   -- fetchl20 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl20_Register_Masks fetchl20 Register Masks
 * @{
 */

/*! @name BASEA6 - BaseAddress6 */
/*! @{ */

#define fetchl20_BASEA6_BaseAdd6_MASK            (0xFFFFFFFFU)
#define fetchl20_BASEA6_BaseAdd6_SHIFT           (0U)
/*! BaseAdd6 - BaseAddress6 */
#define fetchl20_BASEA6_BaseAdd6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_BASEA6_BaseAdd6_SHIFT)) & fetchl20_BASEA6_BaseAdd6_MASK)
/*! @} */

/*! @name BASAMSB6 - BaseAddressMSB6 */
/*! @{ */

#define fetchl20_BASAMSB6_BaAdMB6_MASK           (0xFFU)
#define fetchl20_BASAMSB6_BaAdMB6_SHIFT          (0U)
/*! BaAdMB6 - BaseAddressMSB6 */
#define fetchl20_BASAMSB6_BaAdMB6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_BASAMSB6_BaAdMB6_SHIFT)) & fetchl20_BASAMSB6_BaAdMB6_MASK)
/*! @} */

/*! @name AUTOUBA6 - AutoUpdateBaseAddress6 */
/*! @{ */

#define fetchl20_AUTOUBA6_AutoUBA6_MASK          (0xFFFFFFFFU)
#define fetchl20_AUTOUBA6_AutoUBA6_SHIFT         (0U)
/*! AutoUBA6 - AutoUpdateBaseAddress6 */
#define fetchl20_AUTOUBA6_AutoUBA6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_AUTOUBA6_AutoUBA6_SHIFT)) & fetchl20_AUTOUBA6_AutoUBA6_MASK)
/*! @} */

/*! @name AUTUBAM6 - AutoUpdateBaseAddressMSB6 */
/*! @{ */

#define fetchl20_AUTUBAM6_AutoUBM6_MASK          (0xFFU)
#define fetchl20_AUTUBAM6_AutoUBM6_SHIFT         (0U)
/*! AutoUBM6 - AutoUpdateBaseAddressMSB6 */
#define fetchl20_AUTUBAM6_AutoUBM6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_AUTUBAM6_AutoUBM6_SHIFT)) & fetchl20_AUTUBAM6_AutoUBM6_MASK)
/*! @} */

/*! @name SOUBUAT6 - SourceBufferAttributes6 */
/*! @{ */

#define fetchl20_SOUBUAT6_Stride6_MASK           (0xFFFFU)
#define fetchl20_SOUBUAT6_Stride6_SHIFT          (0U)
/*! Stride6 - Stride6 */
#define fetchl20_SOUBUAT6_Stride6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_SOUBUAT6_Stride6_SHIFT)) & fetchl20_SOUBUAT6_Stride6_MASK)

#define fetchl20_SOUBUAT6_BitsPP6_MASK           (0x3F0000U)
#define fetchl20_SOUBUAT6_BitsPP6_SHIFT          (16U)
/*! BitsPP6 - BitsPerPixel6 */
#define fetchl20_SOUBUAT6_BitsPP6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_SOUBUAT6_BitsPP6_SHIFT)) & fetchl20_SOUBUAT6_BitsPP6_MASK)

#define fetchl20_SOUBUAT6_BaAdAU6_MASK           (0x40000000U)
#define fetchl20_SOUBUAT6_BaAdAU6_SHIFT          (30U)
/*! BaAdAU6 - BaseAddressAutoUpdate6 */
#define fetchl20_SOUBUAT6_BaAdAU6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_SOUBUAT6_BaAdAU6_SHIFT)) & fetchl20_SOUBUAT6_BaAdAU6_MASK)

#define fetchl20_SOUBUAT6_DWBS6_MASK             (0x80000000U)
#define fetchl20_SOUBUAT6_DWBS6_SHIFT            (31U)
/*! DWBS6 - DWordByteSwap6 */
#define fetchl20_SOUBUAT6_DWBS6(x)               (((uint32_t)(((uint32_t)(x)) << fetchl20_SOUBUAT6_DWBS6_SHIFT)) & fetchl20_SOUBUAT6_DWBS6_MASK)
/*! @} */

/*! @name SOUBUDI6 - SourceBufferDimension6 */
/*! @{ */

#define fetchl20_SOUBUDI6_LineW6_MASK            (0x3FFFU)
#define fetchl20_SOUBUDI6_LineW6_SHIFT           (0U)
/*! LineW6 - LineWidth6 */
#define fetchl20_SOUBUDI6_LineW6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_SOUBUDI6_LineW6_SHIFT)) & fetchl20_SOUBUDI6_LineW6_MASK)

#define fetchl20_SOUBUDI6_LineC6_MASK            (0x3FFF0000U)
#define fetchl20_SOUBUDI6_LineC6_SHIFT           (16U)
/*! LineC6 - LineCount6 */
#define fetchl20_SOUBUDI6_LineC6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_SOUBUDI6_LineC6_SHIFT)) & fetchl20_SOUBUDI6_LineC6_MASK)
/*! @} */

/*! @name COLCOMB6 - ColorComponentBits6 */
/*! @{ */

#define fetchl20_COLCOMB6_CompBiA6_MASK          (0xFU)
#define fetchl20_COLCOMB6_CompBiA6_SHIFT         (0U)
/*! CompBiA6 - ComponentBitsAlpha6 */
#define fetchl20_COLCOMB6_CompBiA6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMB6_CompBiA6_SHIFT)) & fetchl20_COLCOMB6_CompBiA6_MASK)

#define fetchl20_COLCOMB6_CompBiB6_MASK          (0xF00U)
#define fetchl20_COLCOMB6_CompBiB6_SHIFT         (8U)
/*! CompBiB6 - ComponentBitsBlue6 */
#define fetchl20_COLCOMB6_CompBiB6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMB6_CompBiB6_SHIFT)) & fetchl20_COLCOMB6_CompBiB6_MASK)

#define fetchl20_COLCOMB6_CompBiG6_MASK          (0xF0000U)
#define fetchl20_COLCOMB6_CompBiG6_SHIFT         (16U)
/*! CompBiG6 - ComponentBitsGreen6 */
#define fetchl20_COLCOMB6_CompBiG6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMB6_CompBiG6_SHIFT)) & fetchl20_COLCOMB6_CompBiG6_MASK)

#define fetchl20_COLCOMB6_CompBiR6_MASK          (0xF000000U)
#define fetchl20_COLCOMB6_CompBiR6_SHIFT         (24U)
/*! CompBiR6 - ComponentBitsRed6 */
#define fetchl20_COLCOMB6_CompBiR6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMB6_CompBiR6_SHIFT)) & fetchl20_COLCOMB6_CompBiR6_MASK)

#define fetchl20_COLCOMB6_ITUForm6_MASK          (0x80000000U)
#define fetchl20_COLCOMB6_ITUForm6_SHIFT         (31U)
/*! ITUForm6 - ITUFormat6 */
#define fetchl20_COLCOMB6_ITUForm6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMB6_ITUForm6_SHIFT)) & fetchl20_COLCOMB6_ITUForm6_MASK)
/*! @} */

/*! @name COLCOMS6 - ColorComponentShift6 */
/*! @{ */

#define fetchl20_COLCOMS6_CompShA6_MASK          (0x1FU)
#define fetchl20_COLCOMS6_CompShA6_SHIFT         (0U)
/*! CompShA6 - ComponentShiftAlpha6 */
#define fetchl20_COLCOMS6_CompShA6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMS6_CompShA6_SHIFT)) & fetchl20_COLCOMS6_CompShA6_MASK)

#define fetchl20_COLCOMS6_CompShB6_MASK          (0x1F00U)
#define fetchl20_COLCOMS6_CompShB6_SHIFT         (8U)
/*! CompShB6 - ComponentShiftBlue6 */
#define fetchl20_COLCOMS6_CompShB6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMS6_CompShB6_SHIFT)) & fetchl20_COLCOMS6_CompShB6_MASK)

#define fetchl20_COLCOMS6_CompShG6_MASK          (0x1F0000U)
#define fetchl20_COLCOMS6_CompShG6_SHIFT         (16U)
/*! CompShG6 - ComponentShiftGreen6 */
#define fetchl20_COLCOMS6_CompShG6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMS6_CompShG6_SHIFT)) & fetchl20_COLCOMS6_CompShG6_MASK)

#define fetchl20_COLCOMS6_CompShR6_MASK          (0x1F000000U)
#define fetchl20_COLCOMS6_CompShR6_SHIFT         (24U)
/*! CompShR6 - ComponentShiftRed6 */
#define fetchl20_COLCOMS6_CompShR6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl20_COLCOMS6_CompShR6_SHIFT)) & fetchl20_COLCOMS6_CompShR6_MASK)
/*! @} */

/*! @name LAYOFF6 - LayerOffset6 */
/*! @{ */

#define fetchl20_LAYOFF6_LayXOs6_MASK            (0x7FFFU)
#define fetchl20_LAYOFF6_LayXOs6_SHIFT           (0U)
/*! LayXOs6 - LayerXOffset6 */
#define fetchl20_LAYOFF6_LayXOs6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYOFF6_LayXOs6_SHIFT)) & fetchl20_LAYOFF6_LayXOs6_MASK)

#define fetchl20_LAYOFF6_LayYOs6_MASK            (0x7FFF0000U)
#define fetchl20_LAYOFF6_LayYOs6_SHIFT           (16U)
/*! LayYOs6 - LayerYOffset6 */
#define fetchl20_LAYOFF6_LayYOs6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYOFF6_LayYOs6_SHIFT)) & fetchl20_LAYOFF6_LayYOs6_MASK)
/*! @} */

/*! @name CLIPWO6 - ClipWindowOffset6 */
/*! @{ */

#define fetchl20_CLIPWO6_ClipWXO6_MASK           (0x7FFFU)
#define fetchl20_CLIPWO6_ClipWXO6_SHIFT          (0U)
/*! ClipWXO6 - ClipWindowXOffset6 */
#define fetchl20_CLIPWO6_ClipWXO6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_CLIPWO6_ClipWXO6_SHIFT)) & fetchl20_CLIPWO6_ClipWXO6_MASK)

#define fetchl20_CLIPWO6_ClipWYO6_MASK           (0x7FFF0000U)
#define fetchl20_CLIPWO6_ClipWYO6_SHIFT          (16U)
/*! ClipWYO6 - ClipWindowYOffset6 */
#define fetchl20_CLIPWO6_ClipWYO6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_CLIPWO6_ClipWYO6_SHIFT)) & fetchl20_CLIPWO6_ClipWYO6_MASK)
/*! @} */

/*! @name CLIPWID6 - ClipWindowDimensions6 */
/*! @{ */

#define fetchl20_CLIPWID6_ClipWW6_MASK           (0x3FFFU)
#define fetchl20_CLIPWID6_ClipWW6_SHIFT          (0U)
/*! ClipWW6 - ClipWindowWidth6 */
#define fetchl20_CLIPWID6_ClipWW6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_CLIPWID6_ClipWW6_SHIFT)) & fetchl20_CLIPWID6_ClipWW6_MASK)

#define fetchl20_CLIPWID6_ClipWH6_MASK           (0x3FFF0000U)
#define fetchl20_CLIPWID6_ClipWH6_SHIFT          (16U)
/*! ClipWH6 - ClipWindowHeight6 */
#define fetchl20_CLIPWID6_ClipWH6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_CLIPWID6_ClipWH6_SHIFT)) & fetchl20_CLIPWID6_ClipWH6_MASK)
/*! @} */

/*! @name CONSTC6 - ConstantColor6 */
/*! @{ */

#define fetchl20_CONSTC6_ConstA6_MASK            (0xFFU)
#define fetchl20_CONSTC6_ConstA6_SHIFT           (0U)
/*! ConstA6 - ConstantAlpha6 */
#define fetchl20_CONSTC6_ConstA6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_CONSTC6_ConstA6_SHIFT)) & fetchl20_CONSTC6_ConstA6_MASK)

#define fetchl20_CONSTC6_ConstB6_MASK            (0xFF00U)
#define fetchl20_CONSTC6_ConstB6_SHIFT           (8U)
/*! ConstB6 - ConstantBlue6 */
#define fetchl20_CONSTC6_ConstB6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_CONSTC6_ConstB6_SHIFT)) & fetchl20_CONSTC6_ConstB6_MASK)

#define fetchl20_CONSTC6_ConstG6_MASK            (0xFF0000U)
#define fetchl20_CONSTC6_ConstG6_SHIFT           (16U)
/*! ConstG6 - ConstantGreen6 */
#define fetchl20_CONSTC6_ConstG6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_CONSTC6_ConstG6_SHIFT)) & fetchl20_CONSTC6_ConstG6_MASK)

#define fetchl20_CONSTC6_ConstR6_MASK            (0xFF000000U)
#define fetchl20_CONSTC6_ConstR6_SHIFT           (24U)
/*! ConstR6 - ConstantRed6 */
#define fetchl20_CONSTC6_ConstR6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_CONSTC6_ConstR6_SHIFT)) & fetchl20_CONSTC6_ConstR6_MASK)
/*! @} */

/*! @name LAYPRO6 - LayerProperty6 */
/*! @{ */

#define fetchl20_LAYPRO6_PaletE6_MASK            (0x1U)
#define fetchl20_LAYPRO6_PaletE6_SHIFT           (0U)
/*! PaletE6 - PaletteEnable6 */
#define fetchl20_LAYPRO6_PaletE6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_PaletE6_SHIFT)) & fetchl20_LAYPRO6_PaletE6_MASK)

#define fetchl20_LAYPRO6_TileMod6_MASK           (0x30U)
#define fetchl20_LAYPRO6_TileMod6_SHIFT          (4U)
/*! TileMod6 - TileMode6
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchl20_LAYPRO6_TileMod6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_TileMod6_SHIFT)) & fetchl20_LAYPRO6_TileMod6_MASK)

#define fetchl20_LAYPRO6_AlpSE6_MASK             (0x100U)
#define fetchl20_LAYPRO6_AlpSE6_SHIFT            (8U)
/*! AlpSE6 - AlphaSrcEnable6 */
#define fetchl20_LAYPRO6_AlpSE6(x)               (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_AlpSE6_SHIFT)) & fetchl20_LAYPRO6_AlpSE6_MASK)

#define fetchl20_LAYPRO6_AlphaCE6_MASK           (0x200U)
#define fetchl20_LAYPRO6_AlphaCE6_SHIFT          (9U)
/*! AlphaCE6 - AlphaConstEnable6 */
#define fetchl20_LAYPRO6_AlphaCE6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_AlphaCE6_SHIFT)) & fetchl20_LAYPRO6_AlphaCE6_MASK)

#define fetchl20_LAYPRO6_AlpTE6_MASK             (0x800U)
#define fetchl20_LAYPRO6_AlpTE6_SHIFT            (11U)
/*! AlpTE6 - AlphaTransEnable6 */
#define fetchl20_LAYPRO6_AlpTE6(x)               (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_AlpTE6_SHIFT)) & fetchl20_LAYPRO6_AlpTE6_MASK)

#define fetchl20_LAYPRO6_RGBASEn6_MASK           (0x1000U)
#define fetchl20_LAYPRO6_RGBASEn6_SHIFT          (12U)
/*! RGBASEn6 - RGBAlphaSrcEnable6 */
#define fetchl20_LAYPRO6_RGBASEn6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_RGBASEn6_SHIFT)) & fetchl20_LAYPRO6_RGBASEn6_MASK)

#define fetchl20_LAYPRO6_RGBACEn6_MASK           (0x2000U)
#define fetchl20_LAYPRO6_RGBACEn6_SHIFT          (13U)
/*! RGBACEn6 - RGBAlphaConstEnable6 */
#define fetchl20_LAYPRO6_RGBACEn6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_RGBACEn6_SHIFT)) & fetchl20_LAYPRO6_RGBACEn6_MASK)

#define fetchl20_LAYPRO6_RGBATrE6_MASK           (0x8000U)
#define fetchl20_LAYPRO6_RGBATrE6_SHIFT          (15U)
/*! RGBATrE6 - RGBAlphaTransEnable6 */
#define fetchl20_LAYPRO6_RGBATrE6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_RGBATrE6_SHIFT)) & fetchl20_LAYPRO6_RGBATrE6_MASK)

#define fetchl20_LAYPRO6_PreCRGB6_MASK           (0x10000U)
#define fetchl20_LAYPRO6_PreCRGB6_SHIFT          (16U)
/*! PreCRGB6 - PremulConstRGB6 */
#define fetchl20_LAYPRO6_PreCRGB6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_PreCRGB6_SHIFT)) & fetchl20_LAYPRO6_PreCRGB6_MASK)

#define fetchl20_LAYPRO6_YUVConM6_MASK           (0x60000U)
#define fetchl20_LAYPRO6_YUVConM6_SHIFT          (17U)
/*! YUVConM6 - YUVConversionMode6
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchl20_LAYPRO6_YUVConM6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_YUVConM6_SHIFT)) & fetchl20_LAYPRO6_YUVConM6_MASK)

#define fetchl20_LAYPRO6_GamReE6_MASK            (0x100000U)
#define fetchl20_LAYPRO6_GamReE6_SHIFT           (20U)
/*! GamReE6 - GammaRemoveEnable6 */
#define fetchl20_LAYPRO6_GamReE6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_GamReE6_SHIFT)) & fetchl20_LAYPRO6_GamReE6_MASK)

#define fetchl20_LAYPRO6_ClipWE6_MASK            (0x40000000U)
#define fetchl20_LAYPRO6_ClipWE6_SHIFT           (30U)
/*! ClipWE6 - ClipWindowEnable6 */
#define fetchl20_LAYPRO6_ClipWE6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_ClipWE6_SHIFT)) & fetchl20_LAYPRO6_ClipWE6_MASK)

#define fetchl20_LAYPRO6_SrcBuEn6_MASK           (0x80000000U)
#define fetchl20_LAYPRO6_SrcBuEn6_SHIFT          (31U)
/*! SrcBuEn6 - SourceBufferEnable6 */
#define fetchl20_LAYPRO6_SrcBuEn6(x)             (((uint32_t)(((uint32_t)(x)) << fetchl20_LAYPRO6_SrcBuEn6_SHIFT)) & fetchl20_LAYPRO6_SrcBuEn6_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchl20_Register_Masks */


/*!
 * @}
 */ /* end of group fetchl20_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHL20_H_ */

