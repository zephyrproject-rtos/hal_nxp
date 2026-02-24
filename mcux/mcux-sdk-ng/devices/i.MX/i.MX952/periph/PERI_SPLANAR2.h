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
**         CMSIS Peripheral Access Layer for splanar2
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
 * @file PERI_splanar2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for splanar2
 *
 * CMSIS Peripheral Access Layer for splanar2
 */

#if !defined(PERI_SPLANAR2_H_)
#define PERI_SPLANAR2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- splanar2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar2_Peripheral_Access_Layer splanar2 Peripheral Access Layer
 * @{
 */

/** splanar2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA2;                            /**< BaseAddress2, offset: 0x0 */
  __IO uint32_t BASAMSB2;                          /**< BaseAddressMSB2, offset: 0x4 */
  __IO uint32_t DESBUFA2;                          /**< DestinationBufferAttributes2, offset: 0x8 */
  __IO uint32_t DESBD;                             /**< DestinationBufferDimension, offset: 0xC */
  __IO uint32_t FRAOFF;                            /**< FrameOffset, offset: 0x10 */
  __IO uint32_t COLCOMB;                           /**< ColorComponentBits, offset: 0x14 */
  __IO uint32_t COLCOMS;                           /**< ColorComponentShift, offset: 0x18 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x1C */
  __O  uint32_t START;                             /**< Start, offset: 0x20 */
} splanar2_Type;

/* ----------------------------------------------------------------------------
   -- splanar2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar2_Register_Masks splanar2 Register Masks
 * @{
 */

/*! @name BASEA2 - BaseAddress2 */
/*! @{ */

#define splanar2_BASEA2_BaseAdd2_MASK            (0xFFFFFFFFU)
#define splanar2_BASEA2_BaseAdd2_SHIFT           (0U)
/*! BaseAdd2 - BaseAddress2 */
#define splanar2_BASEA2_BaseAdd2(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_BASEA2_BaseAdd2_SHIFT)) & splanar2_BASEA2_BaseAdd2_MASK)
/*! @} */

/*! @name BASAMSB2 - BaseAddressMSB2 */
/*! @{ */

#define splanar2_BASAMSB2_BaAdMB2_MASK           (0xFFU)
#define splanar2_BASAMSB2_BaAdMB2_SHIFT          (0U)
/*! BaAdMB2 - BaseAddressMSB2 */
#define splanar2_BASAMSB2_BaAdMB2(x)             (((uint32_t)(((uint32_t)(x)) << splanar2_BASAMSB2_BaAdMB2_SHIFT)) & splanar2_BASAMSB2_BaAdMB2_MASK)
/*! @} */

/*! @name DESBUFA2 - DestinationBufferAttributes2 */
/*! @{ */

#define splanar2_DESBUFA2_Stride2_MASK           (0x1FFFFU)
#define splanar2_DESBUFA2_Stride2_SHIFT          (0U)
/*! Stride2 - Stride2 */
#define splanar2_DESBUFA2_Stride2(x)             (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_Stride2_SHIFT)) & splanar2_DESBUFA2_Stride2_MASK)

#define splanar2_DESBUFA2_XDownsc2_MASK          (0x20000U)
#define splanar2_DESBUFA2_XDownsc2_SHIFT         (17U)
/*! XDownsc2 - XDownscale2
 *  0b0..write every pixel to buffer.
 *  0b1..write every second pixel to buffer. Enables YUV422Downsampling. Only for Rastermode = NORMAL. All
 *       correlated widths and horizontal offsets must be even.
 */
#define splanar2_DESBUFA2_XDownsc2(x)            (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_XDownsc2_SHIFT)) & splanar2_DESBUFA2_XDownsc2_MASK)

#define splanar2_DESBUFA2_YDownsc2_MASK          (0x40000U)
#define splanar2_DESBUFA2_YDownsc2_SHIFT         (18U)
/*! YDownsc2 - YDownscale2
 *  0b0..write every line to buffer.
 *  0b1..write every second line to buffer. Enables YUV420Downsampling. All correlated heights and vertical offsets must be even.
 */
#define splanar2_DESBUFA2_YDownsc2(x)            (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_YDownsc2_SHIFT)) & splanar2_DESBUFA2_YDownsc2_MASK)

#define splanar2_DESBUFA2_AlphaE2_MASK           (0x100000U)
#define splanar2_DESBUFA2_AlphaE2_SHIFT          (20U)
/*! AlphaE2 - AlphaEnable2 */
#define splanar2_DESBUFA2_AlphaE2(x)             (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_AlphaE2_SHIFT)) & splanar2_DESBUFA2_AlphaE2_MASK)

#define splanar2_DESBUFA2_RedEn2_MASK            (0x200000U)
#define splanar2_DESBUFA2_RedEn2_SHIFT           (21U)
/*! RedEn2 - RedEnable2 */
#define splanar2_DESBUFA2_RedEn2(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_RedEn2_SHIFT)) & splanar2_DESBUFA2_RedEn2_MASK)

#define splanar2_DESBUFA2_GreenEn2_MASK          (0x400000U)
#define splanar2_DESBUFA2_GreenEn2_SHIFT         (22U)
/*! GreenEn2 - GreenEnable2 */
#define splanar2_DESBUFA2_GreenEn2(x)            (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_GreenEn2_SHIFT)) & splanar2_DESBUFA2_GreenEn2_MASK)

#define splanar2_DESBUFA2_BlueE2_MASK            (0x800000U)
#define splanar2_DESBUFA2_BlueE2_SHIFT           (23U)
/*! BlueE2 - BlueEnable2 */
#define splanar2_DESBUFA2_BlueE2(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_BlueE2_SHIFT)) & splanar2_DESBUFA2_BlueE2_MASK)

#define splanar2_DESBUFA2_BitsPP2_MASK           (0x3F000000U)
#define splanar2_DESBUFA2_BitsPP2_SHIFT          (24U)
/*! BitsPP2 - BitsPerPixel2 */
#define splanar2_DESBUFA2_BitsPP2(x)             (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_BitsPP2_SHIFT)) & splanar2_DESBUFA2_BitsPP2_MASK)

#define splanar2_DESBUFA2_DWBS2_MASK             (0x80000000U)
#define splanar2_DESBUFA2_DWBS2_SHIFT            (31U)
/*! DWBS2 - DWordByteSwap2 */
#define splanar2_DESBUFA2_DWBS2(x)               (((uint32_t)(((uint32_t)(x)) << splanar2_DESBUFA2_DWBS2_SHIFT)) & splanar2_DESBUFA2_DWBS2_MASK)
/*! @} */

/*! @name DESBD - DestinationBufferDimension */
/*! @{ */

#define splanar2_DESBD_LineW_MASK                (0x3FFFU)
#define splanar2_DESBD_LineW_SHIFT               (0U)
/*! LineW - LineWidth */
#define splanar2_DESBD_LineW(x)                  (((uint32_t)(((uint32_t)(x)) << splanar2_DESBD_LineW_SHIFT)) & splanar2_DESBD_LineW_MASK)

#define splanar2_DESBD_LineC_MASK                (0x3FFF0000U)
#define splanar2_DESBD_LineC_SHIFT               (16U)
/*! LineC - LineCount */
#define splanar2_DESBD_LineC(x)                  (((uint32_t)(((uint32_t)(x)) << splanar2_DESBD_LineC_SHIFT)) & splanar2_DESBD_LineC_MASK)
/*! @} */

/*! @name FRAOFF - FrameOffset */
/*! @{ */

#define splanar2_FRAOFF_FrameXOf_MASK            (0x7FFFU)
#define splanar2_FRAOFF_FrameXOf_SHIFT           (0U)
/*! FrameXOf - FrameXOffset */
#define splanar2_FRAOFF_FrameXOf(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_FRAOFF_FrameXOf_SHIFT)) & splanar2_FRAOFF_FrameXOf_MASK)

#define splanar2_FRAOFF_FrameYOf_MASK            (0x7FFF0000U)
#define splanar2_FRAOFF_FrameYOf_SHIFT           (16U)
/*! FrameYOf - FrameYOffset */
#define splanar2_FRAOFF_FrameYOf(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_FRAOFF_FrameYOf_SHIFT)) & splanar2_FRAOFF_FrameYOf_MASK)
/*! @} */

/*! @name COLCOMB - ColorComponentBits */
/*! @{ */

#define splanar2_COLCOMB_CompBiA_MASK            (0xFU)
#define splanar2_COLCOMB_CompBiA_SHIFT           (0U)
/*! CompBiA - ComponentBitsAlpha */
#define splanar2_COLCOMB_CompBiA(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMB_CompBiA_SHIFT)) & splanar2_COLCOMB_CompBiA_MASK)

#define splanar2_COLCOMB_CompBiB_MASK            (0xF00U)
#define splanar2_COLCOMB_CompBiB_SHIFT           (8U)
/*! CompBiB - ComponentBitsBlue */
#define splanar2_COLCOMB_CompBiB(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMB_CompBiB_SHIFT)) & splanar2_COLCOMB_CompBiB_MASK)

#define splanar2_COLCOMB_CompBiG_MASK            (0xF0000U)
#define splanar2_COLCOMB_CompBiG_SHIFT           (16U)
/*! CompBiG - ComponentBitsGreen */
#define splanar2_COLCOMB_CompBiG(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMB_CompBiG_SHIFT)) & splanar2_COLCOMB_CompBiG_MASK)

#define splanar2_COLCOMB_CompBiR_MASK            (0xF000000U)
#define splanar2_COLCOMB_CompBiR_SHIFT           (24U)
/*! CompBiR - ComponentBitsRed */
#define splanar2_COLCOMB_CompBiR(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMB_CompBiR_SHIFT)) & splanar2_COLCOMB_CompBiR_MASK)
/*! @} */

/*! @name COLCOMS - ColorComponentShift */
/*! @{ */

#define splanar2_COLCOMS_CompShA_MASK            (0x1FU)
#define splanar2_COLCOMS_CompShA_SHIFT           (0U)
/*! CompShA - ComponentShiftAlpha */
#define splanar2_COLCOMS_CompShA(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMS_CompShA_SHIFT)) & splanar2_COLCOMS_CompShA_MASK)

#define splanar2_COLCOMS_CompShB_MASK            (0x1F00U)
#define splanar2_COLCOMS_CompShB_SHIFT           (8U)
/*! CompShB - ComponentShiftBlue */
#define splanar2_COLCOMS_CompShB(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMS_CompShB_SHIFT)) & splanar2_COLCOMS_CompShB_MASK)

#define splanar2_COLCOMS_CompShG_MASK            (0x1F0000U)
#define splanar2_COLCOMS_CompShG_SHIFT           (16U)
/*! CompShG - ComponentShiftGreen */
#define splanar2_COLCOMS_CompShG(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMS_CompShG_SHIFT)) & splanar2_COLCOMS_CompShG_MASK)

#define splanar2_COLCOMS_CompShR_MASK            (0x1F000000U)
#define splanar2_COLCOMS_CompShR_SHIFT           (24U)
/*! CompShR - ComponentShiftRed */
#define splanar2_COLCOMS_CompShR(x)              (((uint32_t)(((uint32_t)(x)) << splanar2_COLCOMS_CompShR_SHIFT)) & splanar2_COLCOMS_CompShR_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define splanar2_CONTR_ColorDE_MASK              (0x1U)
#define splanar2_CONTR_ColorDE_SHIFT             (0U)
/*! ColorDE - ColorDitherEnable */
#define splanar2_CONTR_ColorDE(x)                (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_ColorDE_SHIFT)) & splanar2_CONTR_ColorDE_MASK)

#define splanar2_CONTR_AlphaDE_MASK              (0x2U)
#define splanar2_CONTR_AlphaDE_SHIFT             (1U)
/*! AlphaDE - AlphaDitherEnable */
#define splanar2_CONTR_AlphaDE(x)                (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_AlphaDE_SHIFT)) & splanar2_CONTR_AlphaDE_MASK)

#define splanar2_CONTR_DithOffs_MASK             (0xF0U)
#define splanar2_CONTR_DithOffs_SHIFT            (4U)
/*! DithOffs - DitherOffset */
#define splanar2_CONTR_DithOffs(x)               (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_DithOffs_SHIFT)) & splanar2_CONTR_DithOffs_MASK)

#define splanar2_CONTR_GamAplEn_MASK             (0x1000U)
#define splanar2_CONTR_GamAplEn_SHIFT            (12U)
/*! GamAplEn - GammaApplyEnable */
#define splanar2_CONTR_GamAplEn(x)               (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_GamAplEn_SHIFT)) & splanar2_CONTR_GamAplEn_MASK)

#define splanar2_CONTR_YUVConM_MASK              (0x30000U)
#define splanar2_CONTR_YUVConM_SHIFT             (16U)
/*! YUVConM - YUVConversionMode
 *  0b00..No conversion. Input data must be RGB.
 *  0b01..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6 (standard definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 *  0b10..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.601-6, but assuming full range YUV
 *        inputs (0..255). Most typically used for computer graphics (e.g. for JPEG encoding).
 *  0b11..Conversion from YCbCr (YUV) to RGB according to ITU recommendation BT.709-5 part 2 (high definition TV).
 *        Input range is 16..235 for Y and 16..240 for U/V.
 */
#define splanar2_CONTR_YUVConM(x)                (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_YUVConM_SHIFT)) & splanar2_CONTR_YUVConM_MASK)

#define splanar2_CONTR_RasterMo_MASK             (0xC0000U)
#define splanar2_CONTR_RasterMo_SHIFT            (18U)
/*! RasterMo - RasterMode
 *  0b00..RGBA or YUV 4:4:4 pixel buffer.
 *  0b01..Packed YUV 4:2:2 pixel buffer. Effect is that U samples are written for pixels with even and V samples
 *        for odd column index only. Enables YUV422Downsampling. So BitsPerPixel must be set to the size that a pair
 *        of YU or YV has in memory (most typically 16 bits). All correlated widths and horizontal offsets must be
 *        even.
 *  0b10..[Store derivate only] RLAD compressed bit stream.
 *  0b11..Packed YUV 4:2:2 pixel buffer. Effect is that V samples are written for pixels with even and U samples
 *        for odd column index only. Enables YUV422Downsampling. So BitsPerPixel must be set to the size that a pair
 *        of YU or YV has in memory (most typically 16 bits). All correlated widths and horizontal offsets must be
 *        even.
 */
#define splanar2_CONTR_RasterMo(x)               (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_RasterMo_SHIFT)) & splanar2_CONTR_RasterMo_MASK)

#define splanar2_CONTR_YUV422DM_MASK             (0x300000U)
#define splanar2_CONTR_YUV422DM_SHIFT            (20U)
/*! YUV422DM - YUV422DownsamplingMode
 *  0b00..Nearest mode. Discards all odd samples, outputs even samples.
 *  0b01..Linear coaligned mode. 3 nearest UV samples are combined in linear filter to get one output sample.
 *  0b10..Linear interspersed mode. 2 nearest UV samples are combined in linear filter to get one output sample.
 */
#define splanar2_CONTR_YUV422DM(x)               (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_YUV422DM_SHIFT)) & splanar2_CONTR_YUV422DM_MASK)

#define splanar2_CONTR_YUV420DM_MASK             (0x400000U)
#define splanar2_CONTR_YUV420DM_SHIFT            (22U)
/*! YUV420DM - YUV420DownsamplingMode
 *  0b0..Nearest mode. Discards all odd samples, outputs even samples.
 *  0b1..Linear interspersed mode. 2 nearest UV samples are combined in linear filter to get one output sample.
 */
#define splanar2_CONTR_YUV420DM(x)               (((uint32_t)(((uint32_t)(x)) << splanar2_CONTR_YUV420DM_SHIFT)) & splanar2_CONTR_YUV420DM_MASK)
/*! @} */

/*! @name START - Start */
/*! @{ */

#define splanar2_START_Start1_MASK               (0x1U)
#define splanar2_START_Start1_SHIFT              (0U)
/*! Start1 - Start */
#define splanar2_START_Start1(x)                 (((uint32_t)(((uint32_t)(x)) << splanar2_START_Start1_SHIFT)) & splanar2_START_Start1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group splanar2_Register_Masks */


/*!
 * @}
 */ /* end of group splanar2_Peripheral_Access_Layer */


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


#endif  /* PERI_SPLANAR2_H_ */

