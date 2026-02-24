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
**         CMSIS Peripheral Access Layer for fetchla2
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
 * @file PERI_fetchla2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchla2
 *
 * CMSIS Peripheral Access Layer for fetchla2
 */

#if !defined(PERI_FETCHLA2_H_)
#define PERI_FETCHLA2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchla2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla2_Peripheral_Access_Layer fetchla2 Peripheral Access Layer
 * @{
 */

/** fetchla2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA1;                            /**< BaseAddress1, offset: 0x0 */
  __IO uint32_t BASAMSB1;                          /**< BaseAddressMSB1, offset: 0x4 */
  __IO uint32_t AUTOUBA1;                          /**< AutoUpdateBaseAddress1, offset: 0x8 */
  __IO uint32_t AUTUBAM1;                          /**< AutoUpdateBaseAddressMSB1, offset: 0xC */
  __IO uint32_t SOUBUAT1;                          /**< SourceBufferAttributes1, offset: 0x10 */
  __IO uint32_t SOUBUDI1;                          /**< SourceBufferDimension1, offset: 0x14 */
  __IO uint32_t COLCOMB1;                          /**< ColorComponentBits1, offset: 0x18 */
  __IO uint32_t COLCOMS1;                          /**< ColorComponentShift1, offset: 0x1C */
  __IO uint32_t LAYROF1;                           /**< LayerOffset1, offset: 0x20 */
  __IO uint32_t CLIPWO1;                           /**< ClipWindowOffset1, offset: 0x24 */
  __IO uint32_t CLIPWID1;                          /**< ClipWindowDimensions1, offset: 0x28 */
  __IO uint32_t CONSTC1;                           /**< ConstantColor1, offset: 0x2C */
  __IO uint32_t LAYPRO1;                           /**< LayerProperty1, offset: 0x30 */
} fetchla2_Type;

/* ----------------------------------------------------------------------------
   -- fetchla2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchla2_Register_Masks fetchla2 Register Masks
 * @{
 */

/*! @name BASEA1 - BaseAddress1 */
/*! @{ */

#define fetchla2_BASEA1_BaseAdd1_MASK            (0xFFFFFFFFU)
#define fetchla2_BASEA1_BaseAdd1_SHIFT           (0U)
/*! BaseAdd1 - BaseAddress1 */
#define fetchla2_BASEA1_BaseAdd1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_BASEA1_BaseAdd1_SHIFT)) & fetchla2_BASEA1_BaseAdd1_MASK)
/*! @} */

/*! @name BASAMSB1 - BaseAddressMSB1 */
/*! @{ */

#define fetchla2_BASAMSB1_BaAdMB1_MASK           (0xFFU)
#define fetchla2_BASAMSB1_BaAdMB1_SHIFT          (0U)
/*! BaAdMB1 - BaseAddressMSB1 */
#define fetchla2_BASAMSB1_BaAdMB1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_BASAMSB1_BaAdMB1_SHIFT)) & fetchla2_BASAMSB1_BaAdMB1_MASK)
/*! @} */

/*! @name AUTOUBA1 - AutoUpdateBaseAddress1 */
/*! @{ */

#define fetchla2_AUTOUBA1_AutoUBA1_MASK          (0xFFFFFFFFU)
#define fetchla2_AUTOUBA1_AutoUBA1_SHIFT         (0U)
/*! AutoUBA1 - AutoUpdateBaseAddress1 */
#define fetchla2_AUTOUBA1_AutoUBA1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_AUTOUBA1_AutoUBA1_SHIFT)) & fetchla2_AUTOUBA1_AutoUBA1_MASK)
/*! @} */

/*! @name AUTUBAM1 - AutoUpdateBaseAddressMSB1 */
/*! @{ */

#define fetchla2_AUTUBAM1_AutoUBM1_MASK          (0xFFU)
#define fetchla2_AUTUBAM1_AutoUBM1_SHIFT         (0U)
/*! AutoUBM1 - AutoUpdateBaseAddressMSB1 */
#define fetchla2_AUTUBAM1_AutoUBM1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_AUTUBAM1_AutoUBM1_SHIFT)) & fetchla2_AUTUBAM1_AutoUBM1_MASK)
/*! @} */

/*! @name SOUBUAT1 - SourceBufferAttributes1 */
/*! @{ */

#define fetchla2_SOUBUAT1_Stride1_MASK           (0xFFFFU)
#define fetchla2_SOUBUAT1_Stride1_SHIFT          (0U)
/*! Stride1 - Stride1 */
#define fetchla2_SOUBUAT1_Stride1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_SOUBUAT1_Stride1_SHIFT)) & fetchla2_SOUBUAT1_Stride1_MASK)

#define fetchla2_SOUBUAT1_BitsPP1_MASK           (0x3F0000U)
#define fetchla2_SOUBUAT1_BitsPP1_SHIFT          (16U)
/*! BitsPP1 - BitsPerPixel1 */
#define fetchla2_SOUBUAT1_BitsPP1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_SOUBUAT1_BitsPP1_SHIFT)) & fetchla2_SOUBUAT1_BitsPP1_MASK)

#define fetchla2_SOUBUAT1_BaAdAU1_MASK           (0x40000000U)
#define fetchla2_SOUBUAT1_BaAdAU1_SHIFT          (30U)
/*! BaAdAU1 - BaseAddressAutoUpdate1 */
#define fetchla2_SOUBUAT1_BaAdAU1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_SOUBUAT1_BaAdAU1_SHIFT)) & fetchla2_SOUBUAT1_BaAdAU1_MASK)

#define fetchla2_SOUBUAT1_DWBS1_MASK             (0x80000000U)
#define fetchla2_SOUBUAT1_DWBS1_SHIFT            (31U)
/*! DWBS1 - DWordByteSwap1 */
#define fetchla2_SOUBUAT1_DWBS1(x)               (((uint32_t)(((uint32_t)(x)) << fetchla2_SOUBUAT1_DWBS1_SHIFT)) & fetchla2_SOUBUAT1_DWBS1_MASK)
/*! @} */

/*! @name SOUBUDI1 - SourceBufferDimension1 */
/*! @{ */

#define fetchla2_SOUBUDI1_LineW1_MASK            (0x3FFFU)
#define fetchla2_SOUBUDI1_LineW1_SHIFT           (0U)
/*! LineW1 - LineWidth1 */
#define fetchla2_SOUBUDI1_LineW1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_SOUBUDI1_LineW1_SHIFT)) & fetchla2_SOUBUDI1_LineW1_MASK)

#define fetchla2_SOUBUDI1_LineC1_MASK            (0x3FFF0000U)
#define fetchla2_SOUBUDI1_LineC1_SHIFT           (16U)
/*! LineC1 - LineCount1 */
#define fetchla2_SOUBUDI1_LineC1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_SOUBUDI1_LineC1_SHIFT)) & fetchla2_SOUBUDI1_LineC1_MASK)
/*! @} */

/*! @name COLCOMB1 - ColorComponentBits1 */
/*! @{ */

#define fetchla2_COLCOMB1_CompBiA1_MASK          (0xFU)
#define fetchla2_COLCOMB1_CompBiA1_SHIFT         (0U)
/*! CompBiA1 - ComponentBitsAlpha1 */
#define fetchla2_COLCOMB1_CompBiA1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMB1_CompBiA1_SHIFT)) & fetchla2_COLCOMB1_CompBiA1_MASK)

#define fetchla2_COLCOMB1_CompBiB1_MASK          (0xF00U)
#define fetchla2_COLCOMB1_CompBiB1_SHIFT         (8U)
/*! CompBiB1 - ComponentBitsBlue1 */
#define fetchla2_COLCOMB1_CompBiB1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMB1_CompBiB1_SHIFT)) & fetchla2_COLCOMB1_CompBiB1_MASK)

#define fetchla2_COLCOMB1_CompBiG1_MASK          (0xF0000U)
#define fetchla2_COLCOMB1_CompBiG1_SHIFT         (16U)
/*! CompBiG1 - ComponentBitsGreen1 */
#define fetchla2_COLCOMB1_CompBiG1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMB1_CompBiG1_SHIFT)) & fetchla2_COLCOMB1_CompBiG1_MASK)

#define fetchla2_COLCOMB1_CompBiR1_MASK          (0xF000000U)
#define fetchla2_COLCOMB1_CompBiR1_SHIFT         (24U)
/*! CompBiR1 - ComponentBitsRed1 */
#define fetchla2_COLCOMB1_CompBiR1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMB1_CompBiR1_SHIFT)) & fetchla2_COLCOMB1_CompBiR1_MASK)

#define fetchla2_COLCOMB1_ITUForm1_MASK          (0x80000000U)
#define fetchla2_COLCOMB1_ITUForm1_SHIFT         (31U)
/*! ITUForm1 - ITUFormat1 */
#define fetchla2_COLCOMB1_ITUForm1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMB1_ITUForm1_SHIFT)) & fetchla2_COLCOMB1_ITUForm1_MASK)
/*! @} */

/*! @name COLCOMS1 - ColorComponentShift1 */
/*! @{ */

#define fetchla2_COLCOMS1_CompShA1_MASK          (0x1FU)
#define fetchla2_COLCOMS1_CompShA1_SHIFT         (0U)
/*! CompShA1 - ComponentShiftAlpha1 */
#define fetchla2_COLCOMS1_CompShA1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMS1_CompShA1_SHIFT)) & fetchla2_COLCOMS1_CompShA1_MASK)

#define fetchla2_COLCOMS1_CompShB1_MASK          (0x1F00U)
#define fetchla2_COLCOMS1_CompShB1_SHIFT         (8U)
/*! CompShB1 - ComponentShiftBlue1 */
#define fetchla2_COLCOMS1_CompShB1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMS1_CompShB1_SHIFT)) & fetchla2_COLCOMS1_CompShB1_MASK)

#define fetchla2_COLCOMS1_CompShG1_MASK          (0x1F0000U)
#define fetchla2_COLCOMS1_CompShG1_SHIFT         (16U)
/*! CompShG1 - ComponentShiftGreen1 */
#define fetchla2_COLCOMS1_CompShG1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMS1_CompShG1_SHIFT)) & fetchla2_COLCOMS1_CompShG1_MASK)

#define fetchla2_COLCOMS1_CompShR1_MASK          (0x1F000000U)
#define fetchla2_COLCOMS1_CompShR1_SHIFT         (24U)
/*! CompShR1 - ComponentShiftRed1 */
#define fetchla2_COLCOMS1_CompShR1(x)            (((uint32_t)(((uint32_t)(x)) << fetchla2_COLCOMS1_CompShR1_SHIFT)) & fetchla2_COLCOMS1_CompShR1_MASK)
/*! @} */

/*! @name LAYROF1 - LayerOffset1 */
/*! @{ */

#define fetchla2_LAYROF1_LayXOs1_MASK            (0x7FFFU)
#define fetchla2_LAYROF1_LayXOs1_SHIFT           (0U)
/*! LayXOs1 - LayerXOffset1 */
#define fetchla2_LAYROF1_LayXOs1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYROF1_LayXOs1_SHIFT)) & fetchla2_LAYROF1_LayXOs1_MASK)

#define fetchla2_LAYROF1_LayYOs1_MASK            (0x7FFF0000U)
#define fetchla2_LAYROF1_LayYOs1_SHIFT           (16U)
/*! LayYOs1 - LayerYOffset1 */
#define fetchla2_LAYROF1_LayYOs1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYROF1_LayYOs1_SHIFT)) & fetchla2_LAYROF1_LayYOs1_MASK)
/*! @} */

/*! @name CLIPWO1 - ClipWindowOffset1 */
/*! @{ */

#define fetchla2_CLIPWO1_ClipWXO1_MASK           (0x7FFFU)
#define fetchla2_CLIPWO1_ClipWXO1_SHIFT          (0U)
/*! ClipWXO1 - ClipWindowXOffset1 */
#define fetchla2_CLIPWO1_ClipWXO1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_CLIPWO1_ClipWXO1_SHIFT)) & fetchla2_CLIPWO1_ClipWXO1_MASK)

#define fetchla2_CLIPWO1_ClipWYO1_MASK           (0x7FFF0000U)
#define fetchla2_CLIPWO1_ClipWYO1_SHIFT          (16U)
/*! ClipWYO1 - ClipWindowYOffset1 */
#define fetchla2_CLIPWO1_ClipWYO1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_CLIPWO1_ClipWYO1_SHIFT)) & fetchla2_CLIPWO1_ClipWYO1_MASK)
/*! @} */

/*! @name CLIPWID1 - ClipWindowDimensions1 */
/*! @{ */

#define fetchla2_CLIPWID1_ClipWW1_MASK           (0x3FFFU)
#define fetchla2_CLIPWID1_ClipWW1_SHIFT          (0U)
/*! ClipWW1 - ClipWindowWidth1 */
#define fetchla2_CLIPWID1_ClipWW1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_CLIPWID1_ClipWW1_SHIFT)) & fetchla2_CLIPWID1_ClipWW1_MASK)

#define fetchla2_CLIPWID1_ClipWH1_MASK           (0x3FFF0000U)
#define fetchla2_CLIPWID1_ClipWH1_SHIFT          (16U)
/*! ClipWH1 - ClipWindowHeight1 */
#define fetchla2_CLIPWID1_ClipWH1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_CLIPWID1_ClipWH1_SHIFT)) & fetchla2_CLIPWID1_ClipWH1_MASK)
/*! @} */

/*! @name CONSTC1 - ConstantColor1 */
/*! @{ */

#define fetchla2_CONSTC1_ConstA1_MASK            (0xFFU)
#define fetchla2_CONSTC1_ConstA1_SHIFT           (0U)
/*! ConstA1 - ConstantAlpha1 */
#define fetchla2_CONSTC1_ConstA1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_CONSTC1_ConstA1_SHIFT)) & fetchla2_CONSTC1_ConstA1_MASK)

#define fetchla2_CONSTC1_ConstB1_MASK            (0xFF00U)
#define fetchla2_CONSTC1_ConstB1_SHIFT           (8U)
/*! ConstB1 - ConstantBlue1 */
#define fetchla2_CONSTC1_ConstB1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_CONSTC1_ConstB1_SHIFT)) & fetchla2_CONSTC1_ConstB1_MASK)

#define fetchla2_CONSTC1_ConstG1_MASK            (0xFF0000U)
#define fetchla2_CONSTC1_ConstG1_SHIFT           (16U)
/*! ConstG1 - ConstantGreen1 */
#define fetchla2_CONSTC1_ConstG1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_CONSTC1_ConstG1_SHIFT)) & fetchla2_CONSTC1_ConstG1_MASK)

#define fetchla2_CONSTC1_ConstR1_MASK            (0xFF000000U)
#define fetchla2_CONSTC1_ConstR1_SHIFT           (24U)
/*! ConstR1 - ConstantRed1 */
#define fetchla2_CONSTC1_ConstR1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_CONSTC1_ConstR1_SHIFT)) & fetchla2_CONSTC1_ConstR1_MASK)
/*! @} */

/*! @name LAYPRO1 - LayerProperty1 */
/*! @{ */

#define fetchla2_LAYPRO1_PaletE1_MASK            (0x1U)
#define fetchla2_LAYPRO1_PaletE1_SHIFT           (0U)
/*! PaletE1 - PaletteEnable1 */
#define fetchla2_LAYPRO1_PaletE1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_PaletE1_SHIFT)) & fetchla2_LAYPRO1_PaletE1_MASK)

#define fetchla2_LAYPRO1_TileMod1_MASK           (0x30U)
#define fetchla2_LAYPRO1_TileMod1_SHIFT          (4U)
/*! TileMod1 - TileMode1
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchla2_LAYPRO1_TileMod1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_TileMod1_SHIFT)) & fetchla2_LAYPRO1_TileMod1_MASK)

#define fetchla2_LAYPRO1_AlpSE1_MASK             (0x100U)
#define fetchla2_LAYPRO1_AlpSE1_SHIFT            (8U)
/*! AlpSE1 - AlphaSrcEnable1 */
#define fetchla2_LAYPRO1_AlpSE1(x)               (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_AlpSE1_SHIFT)) & fetchla2_LAYPRO1_AlpSE1_MASK)

#define fetchla2_LAYPRO1_AlphaCE1_MASK           (0x200U)
#define fetchla2_LAYPRO1_AlphaCE1_SHIFT          (9U)
/*! AlphaCE1 - AlphaConstEnable1 */
#define fetchla2_LAYPRO1_AlphaCE1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_AlphaCE1_SHIFT)) & fetchla2_LAYPRO1_AlphaCE1_MASK)

#define fetchla2_LAYPRO1_AlpTE1_MASK             (0x800U)
#define fetchla2_LAYPRO1_AlpTE1_SHIFT            (11U)
/*! AlpTE1 - AlphaTransEnable1 */
#define fetchla2_LAYPRO1_AlpTE1(x)               (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_AlpTE1_SHIFT)) & fetchla2_LAYPRO1_AlpTE1_MASK)

#define fetchla2_LAYPRO1_RGBASEn1_MASK           (0x1000U)
#define fetchla2_LAYPRO1_RGBASEn1_SHIFT          (12U)
/*! RGBASEn1 - RGBAlphaSrcEnable1 */
#define fetchla2_LAYPRO1_RGBASEn1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_RGBASEn1_SHIFT)) & fetchla2_LAYPRO1_RGBASEn1_MASK)

#define fetchla2_LAYPRO1_RGBACEn1_MASK           (0x2000U)
#define fetchla2_LAYPRO1_RGBACEn1_SHIFT          (13U)
/*! RGBACEn1 - RGBAlphaConstEnable1 */
#define fetchla2_LAYPRO1_RGBACEn1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_RGBACEn1_SHIFT)) & fetchla2_LAYPRO1_RGBACEn1_MASK)

#define fetchla2_LAYPRO1_RGBATrE1_MASK           (0x8000U)
#define fetchla2_LAYPRO1_RGBATrE1_SHIFT          (15U)
/*! RGBATrE1 - RGBAlphaTransEnable1 */
#define fetchla2_LAYPRO1_RGBATrE1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_RGBATrE1_SHIFT)) & fetchla2_LAYPRO1_RGBATrE1_MASK)

#define fetchla2_LAYPRO1_PreCRGB1_MASK           (0x10000U)
#define fetchla2_LAYPRO1_PreCRGB1_SHIFT          (16U)
/*! PreCRGB1 - PremulConstRGB1 */
#define fetchla2_LAYPRO1_PreCRGB1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_PreCRGB1_SHIFT)) & fetchla2_LAYPRO1_PreCRGB1_MASK)

#define fetchla2_LAYPRO1_YUVConM1_MASK           (0x60000U)
#define fetchla2_LAYPRO1_YUVConM1_SHIFT          (17U)
/*! YUVConM1 - YUVConversionMode1
 *  0b00..No conversion.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define fetchla2_LAYPRO1_YUVConM1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_YUVConM1_SHIFT)) & fetchla2_LAYPRO1_YUVConM1_MASK)

#define fetchla2_LAYPRO1_GamReE1_MASK            (0x100000U)
#define fetchla2_LAYPRO1_GamReE1_SHIFT           (20U)
/*! GamReE1 - GammaRemoveEnable1 */
#define fetchla2_LAYPRO1_GamReE1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_GamReE1_SHIFT)) & fetchla2_LAYPRO1_GamReE1_MASK)

#define fetchla2_LAYPRO1_ClipWE1_MASK            (0x40000000U)
#define fetchla2_LAYPRO1_ClipWE1_SHIFT           (30U)
/*! ClipWE1 - ClipWindowEnable1 */
#define fetchla2_LAYPRO1_ClipWE1(x)              (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_ClipWE1_SHIFT)) & fetchla2_LAYPRO1_ClipWE1_MASK)

#define fetchla2_LAYPRO1_SrcBuEn1_MASK           (0x80000000U)
#define fetchla2_LAYPRO1_SrcBuEn1_SHIFT          (31U)
/*! SrcBuEn1 - SourceBufferEnable1 */
#define fetchla2_LAYPRO1_SrcBuEn1(x)             (((uint32_t)(((uint32_t)(x)) << fetchla2_LAYPRO1_SrcBuEn1_SHIFT)) & fetchla2_LAYPRO1_SrcBuEn1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchla2_Register_Masks */


/*!
 * @}
 */ /* end of group fetchla2_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHLA2_H_ */

