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
**         CMSIS Peripheral Access Layer for fetchde1
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
 * @file PERI_fetchde1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchde1
 *
 * CMSIS Peripheral Access Layer for fetchde1
 */

#if !defined(PERI_FETCHDE1_H_)
#define PERI_FETCHDE1_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchde1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchde1_Peripheral_Access_Layer fetchde1 Peripheral Access Layer
 * @{
 */

/** fetchde1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA0;                            /**< BaseAddress0, offset: 0x0 */
  __IO uint32_t BASAMSB0;                          /**< BaseAddressMSB0, offset: 0x4 */
  __IO uint32_t AUTOUBA0;                          /**< AutoUpdateBaseAddress0, offset: 0x8 */
  __IO uint32_t AUTUBAM0;                          /**< AutoUpdateBaseAddressMSB0, offset: 0xC */
  __IO uint32_t SOUBUAT0;                          /**< SourceBufferAttributes0, offset: 0x10 */
  __IO uint32_t SOUBUDI0;                          /**< SourceBufferDimension0, offset: 0x14 */
  __IO uint32_t COLCOMB0;                          /**< ColorComponentBits0, offset: 0x18 */
  __IO uint32_t COLCOMS0;                          /**< ColorComponentShift0, offset: 0x1C */
  __IO uint32_t LAYOFF0;                           /**< LayerOffset0, offset: 0x20 */
  __IO uint32_t CLIPWO0;                           /**< ClipWindowOffset0, offset: 0x24 */
  __IO uint32_t CLIPWID0;                          /**< ClipWindowDimensions0, offset: 0x28 */
  __IO uint32_t CONSTC0;                           /**< ConstantColor0, offset: 0x2C */
  __IO uint32_t LAYPRO0;                           /**< LayerProperty0, offset: 0x30 */
} fetchde1_Type;

/* ----------------------------------------------------------------------------
   -- fetchde1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchde1_Register_Masks fetchde1 Register Masks
 * @{
 */

/*! @name BASEA0 - BaseAddress0 */
/*! @{ */

#define fetchde1_BASEA0_BaseAdd0_MASK            (0xFFFFFFFFU)
#define fetchde1_BASEA0_BaseAdd0_SHIFT           (0U)
/*! BaseAdd0 - BaseAddress0 */
#define fetchde1_BASEA0_BaseAdd0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_BASEA0_BaseAdd0_SHIFT)) & fetchde1_BASEA0_BaseAdd0_MASK)
/*! @} */

/*! @name BASAMSB0 - BaseAddressMSB0 */
/*! @{ */

#define fetchde1_BASAMSB0_BaAdMB0_MASK           (0xFFU)
#define fetchde1_BASAMSB0_BaAdMB0_SHIFT          (0U)
/*! BaAdMB0 - BaseAddressMSB0 */
#define fetchde1_BASAMSB0_BaAdMB0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_BASAMSB0_BaAdMB0_SHIFT)) & fetchde1_BASAMSB0_BaAdMB0_MASK)
/*! @} */

/*! @name AUTOUBA0 - AutoUpdateBaseAddress0 */
/*! @{ */

#define fetchde1_AUTOUBA0_AutoUBA0_MASK          (0xFFFFFFFFU)
#define fetchde1_AUTOUBA0_AutoUBA0_SHIFT         (0U)
/*! AutoUBA0 - AutoUpdateBaseAddress0 */
#define fetchde1_AUTOUBA0_AutoUBA0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_AUTOUBA0_AutoUBA0_SHIFT)) & fetchde1_AUTOUBA0_AutoUBA0_MASK)
/*! @} */

/*! @name AUTUBAM0 - AutoUpdateBaseAddressMSB0 */
/*! @{ */

#define fetchde1_AUTUBAM0_AutoUBM0_MASK          (0xFFU)
#define fetchde1_AUTUBAM0_AutoUBM0_SHIFT         (0U)
/*! AutoUBM0 - AutoUpdateBaseAddressMSB0 */
#define fetchde1_AUTUBAM0_AutoUBM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_AUTUBAM0_AutoUBM0_SHIFT)) & fetchde1_AUTUBAM0_AutoUBM0_MASK)
/*! @} */

/*! @name SOUBUAT0 - SourceBufferAttributes0 */
/*! @{ */

#define fetchde1_SOUBUAT0_Stride0_MASK           (0xFFFFU)
#define fetchde1_SOUBUAT0_Stride0_SHIFT          (0U)
/*! Stride0 - Stride0 */
#define fetchde1_SOUBUAT0_Stride0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_SOUBUAT0_Stride0_SHIFT)) & fetchde1_SOUBUAT0_Stride0_MASK)

#define fetchde1_SOUBUAT0_BitsPP0_MASK           (0x3F0000U)
#define fetchde1_SOUBUAT0_BitsPP0_SHIFT          (16U)
/*! BitsPP0 - BitsPerPixel0 */
#define fetchde1_SOUBUAT0_BitsPP0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_SOUBUAT0_BitsPP0_SHIFT)) & fetchde1_SOUBUAT0_BitsPP0_MASK)

#define fetchde1_SOUBUAT0_BaAdAU0_MASK           (0x40000000U)
#define fetchde1_SOUBUAT0_BaAdAU0_SHIFT          (30U)
/*! BaAdAU0 - BaseAddressAutoUpdate0 */
#define fetchde1_SOUBUAT0_BaAdAU0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_SOUBUAT0_BaAdAU0_SHIFT)) & fetchde1_SOUBUAT0_BaAdAU0_MASK)

#define fetchde1_SOUBUAT0_DWBS0_MASK             (0x80000000U)
#define fetchde1_SOUBUAT0_DWBS0_SHIFT            (31U)
/*! DWBS0 - DWordByteSwap0 */
#define fetchde1_SOUBUAT0_DWBS0(x)               (((uint32_t)(((uint32_t)(x)) << fetchde1_SOUBUAT0_DWBS0_SHIFT)) & fetchde1_SOUBUAT0_DWBS0_MASK)
/*! @} */

/*! @name SOUBUDI0 - SourceBufferDimension0 */
/*! @{ */

#define fetchde1_SOUBUDI0_LineW0_MASK            (0x3FFFU)
#define fetchde1_SOUBUDI0_LineW0_SHIFT           (0U)
/*! LineW0 - LineWidth0 */
#define fetchde1_SOUBUDI0_LineW0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_SOUBUDI0_LineW0_SHIFT)) & fetchde1_SOUBUDI0_LineW0_MASK)

#define fetchde1_SOUBUDI0_LineC0_MASK            (0x3FFF0000U)
#define fetchde1_SOUBUDI0_LineC0_SHIFT           (16U)
/*! LineC0 - LineCount0 */
#define fetchde1_SOUBUDI0_LineC0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_SOUBUDI0_LineC0_SHIFT)) & fetchde1_SOUBUDI0_LineC0_MASK)
/*! @} */

/*! @name COLCOMB0 - ColorComponentBits0 */
/*! @{ */

#define fetchde1_COLCOMB0_CompBiA0_MASK          (0xFU)
#define fetchde1_COLCOMB0_CompBiA0_SHIFT         (0U)
/*! CompBiA0 - ComponentBitsAlpha0 */
#define fetchde1_COLCOMB0_CompBiA0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMB0_CompBiA0_SHIFT)) & fetchde1_COLCOMB0_CompBiA0_MASK)

#define fetchde1_COLCOMB0_CompBiB0_MASK          (0xF00U)
#define fetchde1_COLCOMB0_CompBiB0_SHIFT         (8U)
/*! CompBiB0 - ComponentBitsBlue0 */
#define fetchde1_COLCOMB0_CompBiB0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMB0_CompBiB0_SHIFT)) & fetchde1_COLCOMB0_CompBiB0_MASK)

#define fetchde1_COLCOMB0_CompBiG0_MASK          (0xF0000U)
#define fetchde1_COLCOMB0_CompBiG0_SHIFT         (16U)
/*! CompBiG0 - ComponentBitsGreen0 */
#define fetchde1_COLCOMB0_CompBiG0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMB0_CompBiG0_SHIFT)) & fetchde1_COLCOMB0_CompBiG0_MASK)

#define fetchde1_COLCOMB0_CompBiR0_MASK          (0xF000000U)
#define fetchde1_COLCOMB0_CompBiR0_SHIFT         (24U)
/*! CompBiR0 - ComponentBitsRed0 */
#define fetchde1_COLCOMB0_CompBiR0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMB0_CompBiR0_SHIFT)) & fetchde1_COLCOMB0_CompBiR0_MASK)

#define fetchde1_COLCOMB0_ITUForm0_MASK          (0x80000000U)
#define fetchde1_COLCOMB0_ITUForm0_SHIFT         (31U)
/*! ITUForm0 - ITUFormat0 */
#define fetchde1_COLCOMB0_ITUForm0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMB0_ITUForm0_SHIFT)) & fetchde1_COLCOMB0_ITUForm0_MASK)
/*! @} */

/*! @name COLCOMS0 - ColorComponentShift0 */
/*! @{ */

#define fetchde1_COLCOMS0_CompShA0_MASK          (0x1FU)
#define fetchde1_COLCOMS0_CompShA0_SHIFT         (0U)
/*! CompShA0 - ComponentShiftAlpha0 */
#define fetchde1_COLCOMS0_CompShA0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMS0_CompShA0_SHIFT)) & fetchde1_COLCOMS0_CompShA0_MASK)

#define fetchde1_COLCOMS0_CompShB0_MASK          (0x1F00U)
#define fetchde1_COLCOMS0_CompShB0_SHIFT         (8U)
/*! CompShB0 - ComponentShiftBlue0 */
#define fetchde1_COLCOMS0_CompShB0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMS0_CompShB0_SHIFT)) & fetchde1_COLCOMS0_CompShB0_MASK)

#define fetchde1_COLCOMS0_CompShG0_MASK          (0x1F0000U)
#define fetchde1_COLCOMS0_CompShG0_SHIFT         (16U)
/*! CompShG0 - ComponentShiftGreen0 */
#define fetchde1_COLCOMS0_CompShG0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMS0_CompShG0_SHIFT)) & fetchde1_COLCOMS0_CompShG0_MASK)

#define fetchde1_COLCOMS0_CompShR0_MASK          (0x1F000000U)
#define fetchde1_COLCOMS0_CompShR0_SHIFT         (24U)
/*! CompShR0 - ComponentShiftRed0 */
#define fetchde1_COLCOMS0_CompShR0(x)            (((uint32_t)(((uint32_t)(x)) << fetchde1_COLCOMS0_CompShR0_SHIFT)) & fetchde1_COLCOMS0_CompShR0_MASK)
/*! @} */

/*! @name LAYOFF0 - LayerOffset0 */
/*! @{ */

#define fetchde1_LAYOFF0_LayXOs0_MASK            (0x7FFFU)
#define fetchde1_LAYOFF0_LayXOs0_SHIFT           (0U)
/*! LayXOs0 - LayerXOffset0 */
#define fetchde1_LAYOFF0_LayXOs0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYOFF0_LayXOs0_SHIFT)) & fetchde1_LAYOFF0_LayXOs0_MASK)

#define fetchde1_LAYOFF0_LayYOs0_MASK            (0x7FFF0000U)
#define fetchde1_LAYOFF0_LayYOs0_SHIFT           (16U)
/*! LayYOs0 - LayerYOffset0 */
#define fetchde1_LAYOFF0_LayYOs0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYOFF0_LayYOs0_SHIFT)) & fetchde1_LAYOFF0_LayYOs0_MASK)
/*! @} */

/*! @name CLIPWO0 - ClipWindowOffset0 */
/*! @{ */

#define fetchde1_CLIPWO0_ClipWXO0_MASK           (0x7FFFU)
#define fetchde1_CLIPWO0_ClipWXO0_SHIFT          (0U)
/*! ClipWXO0 - ClipWindowXOffset0 */
#define fetchde1_CLIPWO0_ClipWXO0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_CLIPWO0_ClipWXO0_SHIFT)) & fetchde1_CLIPWO0_ClipWXO0_MASK)

#define fetchde1_CLIPWO0_ClipWYO0_MASK           (0x7FFF0000U)
#define fetchde1_CLIPWO0_ClipWYO0_SHIFT          (16U)
/*! ClipWYO0 - ClipWindowYOffset0 */
#define fetchde1_CLIPWO0_ClipWYO0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_CLIPWO0_ClipWYO0_SHIFT)) & fetchde1_CLIPWO0_ClipWYO0_MASK)
/*! @} */

/*! @name CLIPWID0 - ClipWindowDimensions0 */
/*! @{ */

#define fetchde1_CLIPWID0_ClipWW0_MASK           (0x3FFFU)
#define fetchde1_CLIPWID0_ClipWW0_SHIFT          (0U)
/*! ClipWW0 - ClipWindowWidth0 */
#define fetchde1_CLIPWID0_ClipWW0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_CLIPWID0_ClipWW0_SHIFT)) & fetchde1_CLIPWID0_ClipWW0_MASK)

#define fetchde1_CLIPWID0_ClipWH0_MASK           (0x3FFF0000U)
#define fetchde1_CLIPWID0_ClipWH0_SHIFT          (16U)
/*! ClipWH0 - ClipWindowHeight0 */
#define fetchde1_CLIPWID0_ClipWH0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_CLIPWID0_ClipWH0_SHIFT)) & fetchde1_CLIPWID0_ClipWH0_MASK)
/*! @} */

/*! @name CONSTC0 - ConstantColor0 */
/*! @{ */

#define fetchde1_CONSTC0_ConstA0_MASK            (0xFFU)
#define fetchde1_CONSTC0_ConstA0_SHIFT           (0U)
/*! ConstA0 - ConstantAlpha0 */
#define fetchde1_CONSTC0_ConstA0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_CONSTC0_ConstA0_SHIFT)) & fetchde1_CONSTC0_ConstA0_MASK)

#define fetchde1_CONSTC0_ConstB0_MASK            (0xFF00U)
#define fetchde1_CONSTC0_ConstB0_SHIFT           (8U)
/*! ConstB0 - ConstantBlue0 */
#define fetchde1_CONSTC0_ConstB0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_CONSTC0_ConstB0_SHIFT)) & fetchde1_CONSTC0_ConstB0_MASK)

#define fetchde1_CONSTC0_ConstG0_MASK            (0xFF0000U)
#define fetchde1_CONSTC0_ConstG0_SHIFT           (16U)
/*! ConstG0 - ConstantGreen0 */
#define fetchde1_CONSTC0_ConstG0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_CONSTC0_ConstG0_SHIFT)) & fetchde1_CONSTC0_ConstG0_MASK)

#define fetchde1_CONSTC0_ConstR0_MASK            (0xFF000000U)
#define fetchde1_CONSTC0_ConstR0_SHIFT           (24U)
/*! ConstR0 - ConstantRed0 */
#define fetchde1_CONSTC0_ConstR0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_CONSTC0_ConstR0_SHIFT)) & fetchde1_CONSTC0_ConstR0_MASK)
/*! @} */

/*! @name LAYPRO0 - LayerProperty0 */
/*! @{ */

#define fetchde1_LAYPRO0_PaletE0_MASK            (0x1U)
#define fetchde1_LAYPRO0_PaletE0_SHIFT           (0U)
/*! PaletE0 - PaletteEnable0 */
#define fetchde1_LAYPRO0_PaletE0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_PaletE0_SHIFT)) & fetchde1_LAYPRO0_PaletE0_MASK)

#define fetchde1_LAYPRO0_TileMod0_MASK           (0x30U)
#define fetchde1_LAYPRO0_TileMod0_SHIFT          (4U)
/*! TileMod0 - TileMode0
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchde1_LAYPRO0_TileMod0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_TileMod0_SHIFT)) & fetchde1_LAYPRO0_TileMod0_MASK)

#define fetchde1_LAYPRO0_AlpSE0_MASK             (0x100U)
#define fetchde1_LAYPRO0_AlpSE0_SHIFT            (8U)
/*! AlpSE0 - AlphaSrcEnable0 */
#define fetchde1_LAYPRO0_AlpSE0(x)               (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_AlpSE0_SHIFT)) & fetchde1_LAYPRO0_AlpSE0_MASK)

#define fetchde1_LAYPRO0_AlphaCE0_MASK           (0x200U)
#define fetchde1_LAYPRO0_AlphaCE0_SHIFT          (9U)
/*! AlphaCE0 - AlphaConstEnable0 */
#define fetchde1_LAYPRO0_AlphaCE0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_AlphaCE0_SHIFT)) & fetchde1_LAYPRO0_AlphaCE0_MASK)

#define fetchde1_LAYPRO0_AlpMaE0_MASK            (0x400U)
#define fetchde1_LAYPRO0_AlpMaE0_SHIFT           (10U)
/*! AlpMaE0 - AlphaMaskEnable0 */
#define fetchde1_LAYPRO0_AlpMaE0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_AlpMaE0_SHIFT)) & fetchde1_LAYPRO0_AlpMaE0_MASK)

#define fetchde1_LAYPRO0_AlpTE0_MASK             (0x800U)
#define fetchde1_LAYPRO0_AlpTE0_SHIFT            (11U)
/*! AlpTE0 - AlphaTransEnable0 */
#define fetchde1_LAYPRO0_AlpTE0(x)               (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_AlpTE0_SHIFT)) & fetchde1_LAYPRO0_AlpTE0_MASK)

#define fetchde1_LAYPRO0_RGBASEn0_MASK           (0x1000U)
#define fetchde1_LAYPRO0_RGBASEn0_SHIFT          (12U)
/*! RGBASEn0 - RGBAlphaSrcEnable0 */
#define fetchde1_LAYPRO0_RGBASEn0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_RGBASEn0_SHIFT)) & fetchde1_LAYPRO0_RGBASEn0_MASK)

#define fetchde1_LAYPRO0_RGBACEn0_MASK           (0x2000U)
#define fetchde1_LAYPRO0_RGBACEn0_SHIFT          (13U)
/*! RGBACEn0 - RGBAlphaConstEnable0 */
#define fetchde1_LAYPRO0_RGBACEn0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_RGBACEn0_SHIFT)) & fetchde1_LAYPRO0_RGBACEn0_MASK)

#define fetchde1_LAYPRO0_RGBAMEn0_MASK           (0x4000U)
#define fetchde1_LAYPRO0_RGBAMEn0_SHIFT          (14U)
/*! RGBAMEn0 - RGBAlphaMaskEnable0 */
#define fetchde1_LAYPRO0_RGBAMEn0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_RGBAMEn0_SHIFT)) & fetchde1_LAYPRO0_RGBAMEn0_MASK)

#define fetchde1_LAYPRO0_RGBATrE0_MASK           (0x8000U)
#define fetchde1_LAYPRO0_RGBATrE0_SHIFT          (15U)
/*! RGBATrE0 - RGBAlphaTransEnable0 */
#define fetchde1_LAYPRO0_RGBATrE0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_RGBATrE0_SHIFT)) & fetchde1_LAYPRO0_RGBATrE0_MASK)

#define fetchde1_LAYPRO0_PreCRGB0_MASK           (0x10000U)
#define fetchde1_LAYPRO0_PreCRGB0_SHIFT          (16U)
/*! PreCRGB0 - PremulConstRGB0 */
#define fetchde1_LAYPRO0_PreCRGB0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_PreCRGB0_SHIFT)) & fetchde1_LAYPRO0_PreCRGB0_MASK)

#define fetchde1_LAYPRO0_YUVConM0_MASK           (0x60000U)
#define fetchde1_LAYPRO0_YUVConM0_SHIFT          (17U)
/*! YUVConM0 - YUVConversionMode0
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchde1_LAYPRO0_YUVConM0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_YUVConM0_SHIFT)) & fetchde1_LAYPRO0_YUVConM0_MASK)

#define fetchde1_LAYPRO0_GamReE0_MASK            (0x100000U)
#define fetchde1_LAYPRO0_GamReE0_SHIFT           (20U)
/*! GamReE0 - GammaRemoveEnable0 */
#define fetchde1_LAYPRO0_GamReE0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_GamReE0_SHIFT)) & fetchde1_LAYPRO0_GamReE0_MASK)

#define fetchde1_LAYPRO0_ClipWE0_MASK            (0x40000000U)
#define fetchde1_LAYPRO0_ClipWE0_SHIFT           (30U)
/*! ClipWE0 - ClipWindowEnable0 */
#define fetchde1_LAYPRO0_ClipWE0(x)              (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_ClipWE0_SHIFT)) & fetchde1_LAYPRO0_ClipWE0_MASK)

#define fetchde1_LAYPRO0_SrcBuEn0_MASK           (0x80000000U)
#define fetchde1_LAYPRO0_SrcBuEn0_SHIFT          (31U)
/*! SrcBuEn0 - SourceBufferEnable0 */
#define fetchde1_LAYPRO0_SrcBuEn0(x)             (((uint32_t)(((uint32_t)(x)) << fetchde1_LAYPRO0_SrcBuEn0_SHIFT)) & fetchde1_LAYPRO0_SrcBuEn0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchde1_Register_Masks */


/*!
 * @}
 */ /* end of group fetchde1_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHDE1_H_ */

