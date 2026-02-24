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
**         CMSIS Peripheral Access Layer for fetchde2
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
 * @file PERI_fetchde2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchde2
 *
 * CMSIS Peripheral Access Layer for fetchde2
 */

#if !defined(PERI_FETCHDE2_H_)
#define PERI_FETCHDE2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchde2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchde2_Peripheral_Access_Layer fetchde2 Peripheral Access Layer
 * @{
 */

/** fetchde2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t FRADIM;                            /**< FrameDimensions, offset: 0x0 */
  __IO uint32_t FRAR;                              /**< FrameResampling, offset: 0x4 */
  __IO uint32_t DECCON;                            /**< DecodeControl, offset: 0x8 */
  __IO uint32_t SOUBULEN;                          /**< SourceBufferLength, offset: 0xC */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x10 */
  __O  uint32_t CONTRIG;                           /**< ControlTrigger, offset: 0x14 */
  __O  uint32_t START;                             /**< Start, offset: 0x18 */
  __I  uint32_t FETTYPE;                           /**< FetchType, offset: 0x1C */
  __IO uint32_t DECSTA;                            /**< DecoderStatus, offset: 0x20 */
} fetchde2_Type;

/* ----------------------------------------------------------------------------
   -- fetchde2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchde2_Register_Masks fetchde2 Register Masks
 * @{
 */

/*! @name FRADIM - FrameDimensions */
/*! @{ */

#define fetchde2_FRADIM_FrameWid_MASK            (0x3FFFU)
#define fetchde2_FRADIM_FrameWid_SHIFT           (0U)
/*! FrameWid - FrameWidth */
#define fetchde2_FRADIM_FrameWid(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_FRADIM_FrameWid_SHIFT)) & fetchde2_FRADIM_FrameWid_MASK)

#define fetchde2_FRADIM_FrameHei_MASK            (0x3FFF0000U)
#define fetchde2_FRADIM_FrameHei_SHIFT           (16U)
/*! FrameHei - FrameHeight */
#define fetchde2_FRADIM_FrameHei(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_FRADIM_FrameHei_SHIFT)) & fetchde2_FRADIM_FrameHei_MASK)

#define fetchde2_FRADIM_EmptFram_MASK            (0x80000000U)
#define fetchde2_FRADIM_EmptFram_SHIFT           (31U)
/*! EmptFram - EmptyFrame */
#define fetchde2_FRADIM_EmptFram(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_FRADIM_EmptFram_SHIFT)) & fetchde2_FRADIM_EmptFram_MASK)
/*! @} */

/*! @name FRAR - FrameResampling */
/*! @{ */

#define fetchde2_FRAR_StartX_MASK                (0x3FU)
#define fetchde2_FRAR_StartX_SHIFT               (0U)
/*! StartX - StartX */
#define fetchde2_FRAR_StartX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchde2_FRAR_StartX_SHIFT)) & fetchde2_FRAR_StartX_MASK)

#define fetchde2_FRAR_StartY_MASK                (0xFC0U)
#define fetchde2_FRAR_StartY_SHIFT               (6U)
/*! StartY - StartY */
#define fetchde2_FRAR_StartY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchde2_FRAR_StartY_SHIFT)) & fetchde2_FRAR_StartY_MASK)

#define fetchde2_FRAR_DeltaX_MASK                (0x3F000U)
#define fetchde2_FRAR_DeltaX_SHIFT               (12U)
/*! DeltaX - DeltaX */
#define fetchde2_FRAR_DeltaX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchde2_FRAR_DeltaX_SHIFT)) & fetchde2_FRAR_DeltaX_MASK)

#define fetchde2_FRAR_DeltaY_MASK                (0xFC0000U)
#define fetchde2_FRAR_DeltaY_SHIFT               (18U)
/*! DeltaY - DeltaY */
#define fetchde2_FRAR_DeltaY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchde2_FRAR_DeltaY_SHIFT)) & fetchde2_FRAR_DeltaY_MASK)

#define fetchde2_FRAR_SwaDir_MASK                (0x1000000U)
#define fetchde2_FRAR_SwaDir_SHIFT               (24U)
/*! SwaDir - SwapDirection */
#define fetchde2_FRAR_SwaDir(x)                  (((uint32_t)(((uint32_t)(x)) << fetchde2_FRAR_SwaDir_SHIFT)) & fetchde2_FRAR_SwaDir_MASK)
/*! @} */

/*! @name DECCON - DecodeControl */
/*! @{ */

#define fetchde2_DECCON_CompMod_MASK             (0x3U)
#define fetchde2_DECCON_CompMod_SHIFT            (0U)
/*! CompMod - CompressionMode
 *  0b00..Run-Length Adaptive Dithering (lossy compression).
 *  0b01..Run-Length Adaptive Dithering (lossy compression; uniform package size).
 *  0b10..Run-Length Adaptive (lossless compression).
 *  0b11..Standard Run-Length.
 */
#define fetchde2_DECCON_CompMod(x)               (((uint32_t)(((uint32_t)(x)) << fetchde2_DECCON_CompMod_SHIFT)) & fetchde2_DECCON_CompMod_MASK)

#define fetchde2_DECCON_REndians_MASK            (0x8000U)
#define fetchde2_DECCON_REndians_SHIFT           (15U)
/*! REndians - RLADEndianness
 *  0b0..Big endian format
 *  0b1..Little endian format
 */
#define fetchde2_DECCON_REndians(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_DECCON_REndians_SHIFT)) & fetchde2_DECCON_REndians_MASK)

#define fetchde2_DECCON_RCompBiR_MASK            (0xF0000U)
#define fetchde2_DECCON_RCompBiR_SHIFT           (16U)
/*! RCompBiR - RLADCompBitsRed */
#define fetchde2_DECCON_RCompBiR(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_DECCON_RCompBiR_SHIFT)) & fetchde2_DECCON_RCompBiR_MASK)

#define fetchde2_DECCON_RCompBiG_MASK            (0xF00000U)
#define fetchde2_DECCON_RCompBiG_SHIFT           (20U)
/*! RCompBiG - RLADCompBitsGreen */
#define fetchde2_DECCON_RCompBiG(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_DECCON_RCompBiG_SHIFT)) & fetchde2_DECCON_RCompBiG_MASK)

#define fetchde2_DECCON_RCompBiB_MASK            (0xF000000U)
#define fetchde2_DECCON_RCompBiB_SHIFT           (24U)
/*! RCompBiB - RLADCompBitsBlue */
#define fetchde2_DECCON_RCompBiB(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_DECCON_RCompBiB_SHIFT)) & fetchde2_DECCON_RCompBiB_MASK)

#define fetchde2_DECCON_RCompBiA_MASK            (0xF0000000U)
#define fetchde2_DECCON_RCompBiA_SHIFT           (28U)
/*! RCompBiA - RLADCompBitsAlpha */
#define fetchde2_DECCON_RCompBiA(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_DECCON_RCompBiA_SHIFT)) & fetchde2_DECCON_RCompBiA_MASK)
/*! @} */

/*! @name SOUBULEN - SourceBufferLength */
/*! @{ */

#define fetchde2_SOUBULEN_RLEWords_MASK          (0x1FFFFFFFU)
#define fetchde2_SOUBULEN_RLEWords_SHIFT         (0U)
/*! RLEWords - RLEWords */
#define fetchde2_SOUBULEN_RLEWords(x)            (((uint32_t)(((uint32_t)(x)) << fetchde2_SOUBULEN_RLEWords_SHIFT)) & fetchde2_SOUBULEN_RLEWords_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define fetchde2_CONTR_RasterMo_MASK             (0x7U)
#define fetchde2_CONTR_RasterMo_SHIFT            (0U)
/*! RasterMo - RasterMode
 *  0b000..First sample at StartX/Y relative to origin. Hor/ver increments using DeltaX/Y and DeltaSwap setup.
 *  0b001..[FetchDecode/FetchDecodeL only] Source buffer is an encoded bit stream. First sample at origin (0,0). Hor/ver increments = (1,0)/(0,1).
 *  0b010..[FetchPersp/Warp/Rot only] Arbitrary warping (filter is active). Coordinates are read from frame input
 *         port. InputSelect must be set to COORDINATE. ArbStartX/Y and ArbDeltaXX/XY/YX/YY must be setup.
 *  0b011..[FetchPersp only] Affine/Perspective warping (filter is active). First sample at PerspStartX/Y/W.
 *         Hor/ver increments using PerspDeltaXX/XY/YX/YY/WX/WY. Homogeneous coordinates.
 *  0b100..[FetchPersp/Decode/YUV only] Source buffer is packed YUV 4:2:2. First sample at origin (0,0). Hor/ver
 *         increments = (1,0)/(0,1). All corellated window widths and horizontal offsets must be even. First Chroma
 *         Sample is U.
 *  0b101..[FetchRot/RotL only] Affine warping (filter is active). First sample at AffineStartX/Y. Hor/ver
 *         increments using AffineDeltaXX/XY/YX/YY. Cartesian coordinates.
 *  0b110..[FetchPersp/Decode/YUV only] Source buffer is packed YUV 4:2:2. First sample at origin (0,0). Hor/ver
 *         increments = (1,0)/(0,1). All corellated window widths and horizontal offsets must be even. First Chroma
 *         Sample is V.
 */
#define fetchde2_CONTR_RasterMo(x)               (((uint32_t)(((uint32_t)(x)) << fetchde2_CONTR_RasterMo_SHIFT)) & fetchde2_CONTR_RasterMo_MASK)

#define fetchde2_CONTR_InputS_MASK               (0x18U)
#define fetchde2_CONTR_InputS_SHIFT              (3U)
/*! InputS - InputSelect
 *  0b00..Not used.
 *  0b01..Used for component packing (e.g. UV or source alpha buffer).
 *  0b10..Used for RGB and alpha pre-multiply stage (mask alpha buffer).
 *  0b11..Used for arbitrary warping (coordinate buffer).
 */
#define fetchde2_CONTR_InputS(x)                 (((uint32_t)(((uint32_t)(x)) << fetchde2_CONTR_InputS_SHIFT)) & fetchde2_CONTR_InputS_MASK)

#define fetchde2_CONTR_YUV422UM_MASK             (0x20U)
#define fetchde2_CONTR_YUV422UM_SHIFT            (5U)
/*! YUV422UM - YUV422UpsamplingMode
 *  0b0..Replicate mode for interspersed samples (UV samples between Y samples).
 *  0b1..Interpolate mode for coaligned samples (UV samples at Y sample positions).
 */
#define fetchde2_CONTR_YUV422UM(x)               (((uint32_t)(((uint32_t)(x)) << fetchde2_CONTR_YUV422UM_SHIFT)) & fetchde2_CONTR_YUV422UM_MASK)

#define fetchde2_CONTR_RawPixel_MASK             (0x80U)
#define fetchde2_CONTR_RawPixel_SHIFT            (7U)
/*! RawPixel - RawPixel */
#define fetchde2_CONTR_RawPixel(x)               (((uint32_t)(((uint32_t)(x)) << fetchde2_CONTR_RawPixel_SHIFT)) & fetchde2_CONTR_RawPixel_MASK)

#define fetchde2_CONTR_PalIdxW_MASK              (0x700U)
#define fetchde2_CONTR_PalIdxW_SHIFT             (8U)
/*! PalIdxW - PaletteIdxWidth */
#define fetchde2_CONTR_PalIdxW(x)                (((uint32_t)(((uint32_t)(x)) << fetchde2_CONTR_PalIdxW_SHIFT)) & fetchde2_CONTR_PalIdxW_MASK)

#define fetchde2_CONTR_ClipCol_MASK              (0x10000U)
#define fetchde2_CONTR_ClipCol_SHIFT             (16U)
/*! ClipCol - ClipColor
 *  0b0..Null color.
 *  0b1..Color of layer number given by ClipLayer (or layer 0 when Fetch unit has one layer only). The color is
 *       then the layer's source or tiling color.
 */
#define fetchde2_CONTR_ClipCol(x)                (((uint32_t)(((uint32_t)(x)) << fetchde2_CONTR_ClipCol_SHIFT)) & fetchde2_CONTR_ClipCol_MASK)
/*! @} */

/*! @name CONTRIG - ControlTrigger */
/*! @{ */

#define fetchde2_CONTRIG_SdTokGen_MASK           (0x1U)
#define fetchde2_CONTRIG_SdTokGen_SHIFT          (0U)
/*! SdTokGen - ShdTokGen */
#define fetchde2_CONTRIG_SdTokGen(x)             (((uint32_t)(((uint32_t)(x)) << fetchde2_CONTRIG_SdTokGen_SHIFT)) & fetchde2_CONTRIG_SdTokGen_MASK)
/*! @} */

/*! @name START - Start */
/*! @{ */

#define fetchde2_START_Start1_MASK               (0x1U)
#define fetchde2_START_Start1_SHIFT              (0U)
/*! Start1 - Start */
#define fetchde2_START_Start1(x)                 (((uint32_t)(((uint32_t)(x)) << fetchde2_START_Start1_SHIFT)) & fetchde2_START_Start1_MASK)
/*! @} */

/*! @name FETTYPE - FetchType */
/*! @{ */

#define fetchde2_FETTYPE_FetType_MASK            (0xFU)
#define fetchde2_FETTYPE_FetType_SHIFT           (0U)
/*! FetType - FetchType
 *  0b0000..Fetch unit with RL and RLAD decoder.
 *  0b0001..Fetch unit with fractional plane (8 layers).
 *  0b0010..Fetch unit with arbitrary warping and fractional plane (8 layers).
 *  0b0011..Fetch unit with minimum feature set for alpha, chroma and coordinate planes.
 *  0b0100..Fetch unit with affine, perspective and arbitrary warping.
 *  0b0101..Fetch unit with affine and arbitrary warping.
 *  0b0110..Fetch unit with RL and RLAD decoder, reduced feature set.
 *  0b0111..Fetch unit with fractional plane (8 layers), reduced feature set.
 *  0b1000..Fetch unit with affine and arbitrary warping, reduced feature set.
 *  0b1001..Fetch unit with reduced minimum feature set for alpha, chroma and coordinate planes.
 *  0b1010..Fetch unit with YUV420 upsampling support, without RL and RLAD decoder and palette.
 *  0b1011..Fetch unit with only RGB feature set.
 *  0b1100..Fetch unit with fractional plane (16 layers).
 *  0b1101..Fetch unit with RL and RLAD decoder, reduced feature set.
 */
#define fetchde2_FETTYPE_FetType(x)              (((uint32_t)(((uint32_t)(x)) << fetchde2_FETTYPE_FetType_SHIFT)) & fetchde2_FETTYPE_FetType_MASK)
/*! @} */

/*! @name DECSTA - DecoderStatus */
/*! @{ */

#define fetchde2_DECSTA_BufTooS_MASK             (0x1U)
#define fetchde2_DECSTA_BufTooS_SHIFT            (0U)
/*! BufTooS - BufferTooSmall */
#define fetchde2_DECSTA_BufTooS(x)               (((uint32_t)(((uint32_t)(x)) << fetchde2_DECSTA_BufTooS_SHIFT)) & fetchde2_DECSTA_BufTooS_MASK)

#define fetchde2_DECSTA_BufTooL_MASK             (0x2U)
#define fetchde2_DECSTA_BufTooL_SHIFT            (1U)
/*! BufTooL - BufferTooLarge */
#define fetchde2_DECSTA_BufTooL(x)               (((uint32_t)(((uint32_t)(x)) << fetchde2_DECSTA_BufTooL_SHIFT)) & fetchde2_DECSTA_BufTooL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchde2_Register_Masks */


/*!
 * @}
 */ /* end of group fetchde2_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHDE2_H_ */

