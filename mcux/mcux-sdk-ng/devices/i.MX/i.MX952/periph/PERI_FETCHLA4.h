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
**         CMSIS Peripheral Access Layer for fetchla4
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
 * @file PERI_fetchla4.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchla4
 *
 * CMSIS Peripheral Access Layer for fetchla4
 */

#if !defined(PERI_FETCHLA4_H_)
#define PERI_FETCHLA4_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchla4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla4_Peripheral_Access_Layer fetchla4 Peripheral Access Layer
 * @{
 */

/** fetchla4 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA3;                            /**< BaseAddress3, offset: 0x0 */
  __IO uint32_t BASAMSB3;                          /**< BaseAddressMSB3, offset: 0x4 */
  __IO uint32_t AUTOUBA3;                          /**< AutoUpdateBaseAddress3, offset: 0x8 */
  __IO uint32_t AUTUBAM3;                          /**< AutoUpdateBaseAddressMSB3, offset: 0xC */
  __IO uint32_t SOUBUAT3;                          /**< SourceBufferAttributes3, offset: 0x10 */
  __IO uint32_t SOUBUDI3;                          /**< SourceBufferDimension3, offset: 0x14 */
  __IO uint32_t COLCOMB3;                          /**< ColorComponentBits3, offset: 0x18 */
  __IO uint32_t COLCOMS3;                          /**< ColorComponentShift3, offset: 0x1C */
  __IO uint32_t LAYOFF3;                           /**< LayerOffset3, offset: 0x20 */
  __IO uint32_t CLIPWO3;                           /**< ClipWindowOffset3, offset: 0x24 */
  __IO uint32_t CLIPWID3;                          /**< ClipWindowDimensions3, offset: 0x28 */
  __IO uint32_t CONSTC3;                           /**< ConstantColor3, offset: 0x2C */
  __IO uint32_t LAYPRO3;                           /**< LayerProperty3, offset: 0x30 */
} fetchla4_Type;

/* ----------------------------------------------------------------------------
   -- fetchla4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla4_Register_Masks fetchla4 Register Masks
 * @{
 */

/*! @name BASEA3 - BaseAddress3 */
/*! @{ */

#define fetchla4_BASEA3_BaseAdd3_MASK            (0xFFFFFFFFU)
#define fetchla4_BASEA3_BaseAdd3_SHIFT           (0U)
/*! BaseAdd3 - BaseAddress3 */
#define fetchla4_BASEA3_BaseAdd3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_BASEA3_BaseAdd3_SHIFT)) & fetchla4_BASEA3_BaseAdd3_MASK)
/*! @} */

/*! @name BASAMSB3 - BaseAddressMSB3 */
/*! @{ */

#define fetchla4_BASAMSB3_BaAdMB3_MASK           (0xFFU)
#define fetchla4_BASAMSB3_BaAdMB3_SHIFT          (0U)
/*! BaAdMB3 - BaseAddressMSB3 */
#define fetchla4_BASAMSB3_BaAdMB3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_BASAMSB3_BaAdMB3_SHIFT)) & fetchla4_BASAMSB3_BaAdMB3_MASK)
/*! @} */

/*! @name AUTOUBA3 - AutoUpdateBaseAddress3 */
/*! @{ */

#define fetchla4_AUTOUBA3_AutoUBA3_MASK          (0xFFFFFFFFU)
#define fetchla4_AUTOUBA3_AutoUBA3_SHIFT         (0U)
/*! AutoUBA3 - AutoUpdateBaseAddress3 */
#define fetchla4_AUTOUBA3_AutoUBA3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_AUTOUBA3_AutoUBA3_SHIFT)) & fetchla4_AUTOUBA3_AutoUBA3_MASK)
/*! @} */

/*! @name AUTUBAM3 - AutoUpdateBaseAddressMSB3 */
/*! @{ */

#define fetchla4_AUTUBAM3_AutoUBM3_MASK          (0xFFU)
#define fetchla4_AUTUBAM3_AutoUBM3_SHIFT         (0U)
/*! AutoUBM3 - AutoUpdateBaseAddressMSB3 */
#define fetchla4_AUTUBAM3_AutoUBM3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_AUTUBAM3_AutoUBM3_SHIFT)) & fetchla4_AUTUBAM3_AutoUBM3_MASK)
/*! @} */

/*! @name SOUBUAT3 - SourceBufferAttributes3 */
/*! @{ */

#define fetchla4_SOUBUAT3_Stride3_MASK           (0xFFFFU)
#define fetchla4_SOUBUAT3_Stride3_SHIFT          (0U)
/*! Stride3 - Stride3 */
#define fetchla4_SOUBUAT3_Stride3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_SOUBUAT3_Stride3_SHIFT)) & fetchla4_SOUBUAT3_Stride3_MASK)

#define fetchla4_SOUBUAT3_BitsPP3_MASK           (0x3F0000U)
#define fetchla4_SOUBUAT3_BitsPP3_SHIFT          (16U)
/*! BitsPP3 - BitsPerPixel3 */
#define fetchla4_SOUBUAT3_BitsPP3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_SOUBUAT3_BitsPP3_SHIFT)) & fetchla4_SOUBUAT3_BitsPP3_MASK)

#define fetchla4_SOUBUAT3_BaAdAU3_MASK           (0x40000000U)
#define fetchla4_SOUBUAT3_BaAdAU3_SHIFT          (30U)
/*! BaAdAU3 - BaseAddressAutoUpdate3 */
#define fetchla4_SOUBUAT3_BaAdAU3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_SOUBUAT3_BaAdAU3_SHIFT)) & fetchla4_SOUBUAT3_BaAdAU3_MASK)

#define fetchla4_SOUBUAT3_DWBS3_MASK             (0x80000000U)
#define fetchla4_SOUBUAT3_DWBS3_SHIFT            (31U)
/*! DWBS3 - DWordByteSwap3 */
#define fetchla4_SOUBUAT3_DWBS3(x)               (((uint32_t)(((uint32_t)(x)) << fetchla4_SOUBUAT3_DWBS3_SHIFT)) & fetchla4_SOUBUAT3_DWBS3_MASK)
/*! @} */

/*! @name SOUBUDI3 - SourceBufferDimension3 */
/*! @{ */

#define fetchla4_SOUBUDI3_LineW3_MASK            (0x3FFFU)
#define fetchla4_SOUBUDI3_LineW3_SHIFT           (0U)
/*! LineW3 - LineWidth3 */
#define fetchla4_SOUBUDI3_LineW3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_SOUBUDI3_LineW3_SHIFT)) & fetchla4_SOUBUDI3_LineW3_MASK)

#define fetchla4_SOUBUDI3_LineC3_MASK            (0x3FFF0000U)
#define fetchla4_SOUBUDI3_LineC3_SHIFT           (16U)
/*! LineC3 - LineCount3 */
#define fetchla4_SOUBUDI3_LineC3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_SOUBUDI3_LineC3_SHIFT)) & fetchla4_SOUBUDI3_LineC3_MASK)
/*! @} */

/*! @name COLCOMB3 - ColorComponentBits3 */
/*! @{ */

#define fetchla4_COLCOMB3_CompBiA3_MASK          (0xFU)
#define fetchla4_COLCOMB3_CompBiA3_SHIFT         (0U)
/*! CompBiA3 - ComponentBitsAlpha3 */
#define fetchla4_COLCOMB3_CompBiA3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMB3_CompBiA3_SHIFT)) & fetchla4_COLCOMB3_CompBiA3_MASK)

#define fetchla4_COLCOMB3_CompBiB3_MASK          (0xF00U)
#define fetchla4_COLCOMB3_CompBiB3_SHIFT         (8U)
/*! CompBiB3 - ComponentBitsBlue3 */
#define fetchla4_COLCOMB3_CompBiB3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMB3_CompBiB3_SHIFT)) & fetchla4_COLCOMB3_CompBiB3_MASK)

#define fetchla4_COLCOMB3_CompBiG3_MASK          (0xF0000U)
#define fetchla4_COLCOMB3_CompBiG3_SHIFT         (16U)
/*! CompBiG3 - ComponentBitsGreen3 */
#define fetchla4_COLCOMB3_CompBiG3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMB3_CompBiG3_SHIFT)) & fetchla4_COLCOMB3_CompBiG3_MASK)

#define fetchla4_COLCOMB3_CompBiR3_MASK          (0xF000000U)
#define fetchla4_COLCOMB3_CompBiR3_SHIFT         (24U)
/*! CompBiR3 - ComponentBitsRed3 */
#define fetchla4_COLCOMB3_CompBiR3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMB3_CompBiR3_SHIFT)) & fetchla4_COLCOMB3_CompBiR3_MASK)

#define fetchla4_COLCOMB3_ITUForm3_MASK          (0x80000000U)
#define fetchla4_COLCOMB3_ITUForm3_SHIFT         (31U)
/*! ITUForm3 - ITUFormat3 */
#define fetchla4_COLCOMB3_ITUForm3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMB3_ITUForm3_SHIFT)) & fetchla4_COLCOMB3_ITUForm3_MASK)
/*! @} */

/*! @name COLCOMS3 - ColorComponentShift3 */
/*! @{ */

#define fetchla4_COLCOMS3_CompShA3_MASK          (0x1FU)
#define fetchla4_COLCOMS3_CompShA3_SHIFT         (0U)
/*! CompShA3 - ComponentShiftAlpha3 */
#define fetchla4_COLCOMS3_CompShA3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMS3_CompShA3_SHIFT)) & fetchla4_COLCOMS3_CompShA3_MASK)

#define fetchla4_COLCOMS3_CompShB3_MASK          (0x1F00U)
#define fetchla4_COLCOMS3_CompShB3_SHIFT         (8U)
/*! CompShB3 - ComponentShiftBlue3 */
#define fetchla4_COLCOMS3_CompShB3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMS3_CompShB3_SHIFT)) & fetchla4_COLCOMS3_CompShB3_MASK)

#define fetchla4_COLCOMS3_CompShG3_MASK          (0x1F0000U)
#define fetchla4_COLCOMS3_CompShG3_SHIFT         (16U)
/*! CompShG3 - ComponentShiftGreen3 */
#define fetchla4_COLCOMS3_CompShG3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMS3_CompShG3_SHIFT)) & fetchla4_COLCOMS3_CompShG3_MASK)

#define fetchla4_COLCOMS3_CompShR3_MASK          (0x1F000000U)
#define fetchla4_COLCOMS3_CompShR3_SHIFT         (24U)
/*! CompShR3 - ComponentShiftRed3 */
#define fetchla4_COLCOMS3_CompShR3(x)            (((uint32_t)(((uint32_t)(x)) << fetchla4_COLCOMS3_CompShR3_SHIFT)) & fetchla4_COLCOMS3_CompShR3_MASK)
/*! @} */

/*! @name LAYOFF3 - LayerOffset3 */
/*! @{ */

#define fetchla4_LAYOFF3_LayXOs3_MASK            (0x7FFFU)
#define fetchla4_LAYOFF3_LayXOs3_SHIFT           (0U)
/*! LayXOs3 - LayerXOffset3 */
#define fetchla4_LAYOFF3_LayXOs3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYOFF3_LayXOs3_SHIFT)) & fetchla4_LAYOFF3_LayXOs3_MASK)

#define fetchla4_LAYOFF3_LayYOs3_MASK            (0x7FFF0000U)
#define fetchla4_LAYOFF3_LayYOs3_SHIFT           (16U)
/*! LayYOs3 - LayerYOffset3 */
#define fetchla4_LAYOFF3_LayYOs3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYOFF3_LayYOs3_SHIFT)) & fetchla4_LAYOFF3_LayYOs3_MASK)
/*! @} */

/*! @name CLIPWO3 - ClipWindowOffset3 */
/*! @{ */

#define fetchla4_CLIPWO3_ClipWXO3_MASK           (0x7FFFU)
#define fetchla4_CLIPWO3_ClipWXO3_SHIFT          (0U)
/*! ClipWXO3 - ClipWindowXOffset3 */
#define fetchla4_CLIPWO3_ClipWXO3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_CLIPWO3_ClipWXO3_SHIFT)) & fetchla4_CLIPWO3_ClipWXO3_MASK)

#define fetchla4_CLIPWO3_ClipWYO3_MASK           (0x7FFF0000U)
#define fetchla4_CLIPWO3_ClipWYO3_SHIFT          (16U)
/*! ClipWYO3 - ClipWindowYOffset3 */
#define fetchla4_CLIPWO3_ClipWYO3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_CLIPWO3_ClipWYO3_SHIFT)) & fetchla4_CLIPWO3_ClipWYO3_MASK)
/*! @} */

/*! @name CLIPWID3 - ClipWindowDimensions3 */
/*! @{ */

#define fetchla4_CLIPWID3_ClipWW3_MASK           (0x3FFFU)
#define fetchla4_CLIPWID3_ClipWW3_SHIFT          (0U)
/*! ClipWW3 - ClipWindowWidth3 */
#define fetchla4_CLIPWID3_ClipWW3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_CLIPWID3_ClipWW3_SHIFT)) & fetchla4_CLIPWID3_ClipWW3_MASK)

#define fetchla4_CLIPWID3_ClipWH3_MASK           (0x3FFF0000U)
#define fetchla4_CLIPWID3_ClipWH3_SHIFT          (16U)
/*! ClipWH3 - ClipWindowHeight3 */
#define fetchla4_CLIPWID3_ClipWH3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_CLIPWID3_ClipWH3_SHIFT)) & fetchla4_CLIPWID3_ClipWH3_MASK)
/*! @} */

/*! @name CONSTC3 - ConstantColor3 */
/*! @{ */

#define fetchla4_CONSTC3_ConstA3_MASK            (0xFFU)
#define fetchla4_CONSTC3_ConstA3_SHIFT           (0U)
/*! ConstA3 - ConstantAlpha3 */
#define fetchla4_CONSTC3_ConstA3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_CONSTC3_ConstA3_SHIFT)) & fetchla4_CONSTC3_ConstA3_MASK)

#define fetchla4_CONSTC3_ConstB3_MASK            (0xFF00U)
#define fetchla4_CONSTC3_ConstB3_SHIFT           (8U)
/*! ConstB3 - ConstantBlue3 */
#define fetchla4_CONSTC3_ConstB3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_CONSTC3_ConstB3_SHIFT)) & fetchla4_CONSTC3_ConstB3_MASK)

#define fetchla4_CONSTC3_ConstG3_MASK            (0xFF0000U)
#define fetchla4_CONSTC3_ConstG3_SHIFT           (16U)
/*! ConstG3 - ConstantGreen3 */
#define fetchla4_CONSTC3_ConstG3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_CONSTC3_ConstG3_SHIFT)) & fetchla4_CONSTC3_ConstG3_MASK)

#define fetchla4_CONSTC3_ConstR3_MASK            (0xFF000000U)
#define fetchla4_CONSTC3_ConstR3_SHIFT           (24U)
/*! ConstR3 - ConstantRed3 */
#define fetchla4_CONSTC3_ConstR3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_CONSTC3_ConstR3_SHIFT)) & fetchla4_CONSTC3_ConstR3_MASK)
/*! @} */

/*! @name LAYPRO3 - LayerProperty3 */
/*! @{ */

#define fetchla4_LAYPRO3_PaletE3_MASK            (0x1U)
#define fetchla4_LAYPRO3_PaletE3_SHIFT           (0U)
/*! PaletE3 - PaletteEnable3 */
#define fetchla4_LAYPRO3_PaletE3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_PaletE3_SHIFT)) & fetchla4_LAYPRO3_PaletE3_MASK)

#define fetchla4_LAYPRO3_TileMod3_MASK           (0x30U)
#define fetchla4_LAYPRO3_TileMod3_SHIFT          (4U)
/*! TileMod3 - TileMode3
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchla4_LAYPRO3_TileMod3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_TileMod3_SHIFT)) & fetchla4_LAYPRO3_TileMod3_MASK)

#define fetchla4_LAYPRO3_AlpSE3_MASK             (0x100U)
#define fetchla4_LAYPRO3_AlpSE3_SHIFT            (8U)
/*! AlpSE3 - AlphaSrcEnable3 */
#define fetchla4_LAYPRO3_AlpSE3(x)               (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_AlpSE3_SHIFT)) & fetchla4_LAYPRO3_AlpSE3_MASK)

#define fetchla4_LAYPRO3_AlphaCE3_MASK           (0x200U)
#define fetchla4_LAYPRO3_AlphaCE3_SHIFT          (9U)
/*! AlphaCE3 - AlphaConstEnable3 */
#define fetchla4_LAYPRO3_AlphaCE3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_AlphaCE3_SHIFT)) & fetchla4_LAYPRO3_AlphaCE3_MASK)

#define fetchla4_LAYPRO3_AlpTE3_MASK             (0x800U)
#define fetchla4_LAYPRO3_AlpTE3_SHIFT            (11U)
/*! AlpTE3 - AlphaTransEnable3 */
#define fetchla4_LAYPRO3_AlpTE3(x)               (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_AlpTE3_SHIFT)) & fetchla4_LAYPRO3_AlpTE3_MASK)

#define fetchla4_LAYPRO3_RGBASEn3_MASK           (0x1000U)
#define fetchla4_LAYPRO3_RGBASEn3_SHIFT          (12U)
/*! RGBASEn3 - RGBAlphaSrcEnable3 */
#define fetchla4_LAYPRO3_RGBASEn3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_RGBASEn3_SHIFT)) & fetchla4_LAYPRO3_RGBASEn3_MASK)

#define fetchla4_LAYPRO3_RGBACEn3_MASK           (0x2000U)
#define fetchla4_LAYPRO3_RGBACEn3_SHIFT          (13U)
/*! RGBACEn3 - RGBAlphaConstEnable3 */
#define fetchla4_LAYPRO3_RGBACEn3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_RGBACEn3_SHIFT)) & fetchla4_LAYPRO3_RGBACEn3_MASK)

#define fetchla4_LAYPRO3_RGBATrE3_MASK           (0x8000U)
#define fetchla4_LAYPRO3_RGBATrE3_SHIFT          (15U)
/*! RGBATrE3 - RGBAlphaTransEnable3 */
#define fetchla4_LAYPRO3_RGBATrE3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_RGBATrE3_SHIFT)) & fetchla4_LAYPRO3_RGBATrE3_MASK)

#define fetchla4_LAYPRO3_PreCRGB3_MASK           (0x10000U)
#define fetchla4_LAYPRO3_PreCRGB3_SHIFT          (16U)
/*! PreCRGB3 - PremulConstRGB3 */
#define fetchla4_LAYPRO3_PreCRGB3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_PreCRGB3_SHIFT)) & fetchla4_LAYPRO3_PreCRGB3_MASK)

#define fetchla4_LAYPRO3_YUVConM3_MASK           (0x60000U)
#define fetchla4_LAYPRO3_YUVConM3_SHIFT          (17U)
/*! YUVConM3 - YUVConversionMode3
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchla4_LAYPRO3_YUVConM3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_YUVConM3_SHIFT)) & fetchla4_LAYPRO3_YUVConM3_MASK)

#define fetchla4_LAYPRO3_GamReE3_MASK            (0x100000U)
#define fetchla4_LAYPRO3_GamReE3_SHIFT           (20U)
/*! GamReE3 - GammaRemoveEnable3 */
#define fetchla4_LAYPRO3_GamReE3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_GamReE3_SHIFT)) & fetchla4_LAYPRO3_GamReE3_MASK)

#define fetchla4_LAYPRO3_ClipWE3_MASK            (0x40000000U)
#define fetchla4_LAYPRO3_ClipWE3_SHIFT           (30U)
/*! ClipWE3 - ClipWindowEnable3 */
#define fetchla4_LAYPRO3_ClipWE3(x)              (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_ClipWE3_SHIFT)) & fetchla4_LAYPRO3_ClipWE3_MASK)

#define fetchla4_LAYPRO3_SrcBuEn3_MASK           (0x80000000U)
#define fetchla4_LAYPRO3_SrcBuEn3_SHIFT          (31U)
/*! SrcBuEn3 - SourceBufferEnable3 */
#define fetchla4_LAYPRO3_SrcBuEn3(x)             (((uint32_t)(((uint32_t)(x)) << fetchla4_LAYPRO3_SrcBuEn3_SHIFT)) & fetchla4_LAYPRO3_SrcBuEn3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchla4_Register_Masks */


/*!
 * @}
 */ /* end of group fetchla4_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHLA4_H_ */

