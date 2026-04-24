/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for fetchyu7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
 * @file PERI_fetchyu7.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchyu7
 *
 * CMSIS Peripheral Access Layer for fetchyu7
 */

#if !defined(PERI_FETCHYU7_H_)
#define PERI_FETCHYU7_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- fetchyu7 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchyu7_Peripheral_Access_Layer fetchyu7 Peripheral Access Layer
 * @{
 */

/** fetchyu7 - Register Layout Typedef */
typedef struct {
  __IO uint32_t FRADIM;                            /**< FrameDimensions, offset: 0x0 */
  __IO uint32_t FRAR;                              /**< FrameResampling, offset: 0x4 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x8 */
  __O  uint32_t CONTRIG;                           /**< ControlTrigger, offset: 0xC */
  __O  uint32_t START;                             /**< Start, offset: 0x10 */
  __I  uint32_t FETTYPE;                           /**< FetchType, offset: 0x14 */
} fetchyu7_Type;

/* ----------------------------------------------------------------------------
   -- fetchyu7 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchyu7_Register_Masks fetchyu7 Register Masks
 * @{
 */

/*! @name FRADIM - FrameDimensions */
/*! @{ */

#define fetchyu7_FRADIM_FrameWid_MASK            (0x3FFFU)
#define fetchyu7_FRADIM_FrameWid_SHIFT           (0U)
/*! FrameWid - FrameWidth */
#define fetchyu7_FRADIM_FrameWid(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRADIM_FrameWid_SHIFT)) & fetchyu7_FRADIM_FrameWid_MASK)

#define fetchyu7_FRADIM_FrameHei_MASK            (0x3FFF0000U)
#define fetchyu7_FRADIM_FrameHei_SHIFT           (16U)
/*! FrameHei - FrameHeight */
#define fetchyu7_FRADIM_FrameHei(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRADIM_FrameHei_SHIFT)) & fetchyu7_FRADIM_FrameHei_MASK)

#define fetchyu7_FRADIM_EmptFram_MASK            (0x80000000U)
#define fetchyu7_FRADIM_EmptFram_SHIFT           (31U)
/*! EmptFram - EmptyFrame */
#define fetchyu7_FRADIM_EmptFram(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRADIM_EmptFram_SHIFT)) & fetchyu7_FRADIM_EmptFram_MASK)
/*! @} */

/*! @name FRAR - FrameResampling */
/*! @{ */

#define fetchyu7_FRAR_StartX_MASK                (0x3FU)
#define fetchyu7_FRAR_StartX_SHIFT               (0U)
/*! StartX - StartX */
#define fetchyu7_FRAR_StartX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRAR_StartX_SHIFT)) & fetchyu7_FRAR_StartX_MASK)

#define fetchyu7_FRAR_StartY_MASK                (0xFC0U)
#define fetchyu7_FRAR_StartY_SHIFT               (6U)
/*! StartY - StartY */
#define fetchyu7_FRAR_StartY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRAR_StartY_SHIFT)) & fetchyu7_FRAR_StartY_MASK)

#define fetchyu7_FRAR_DeltaX_MASK                (0x3F000U)
#define fetchyu7_FRAR_DeltaX_SHIFT               (12U)
/*! DeltaX - DeltaX */
#define fetchyu7_FRAR_DeltaX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRAR_DeltaX_SHIFT)) & fetchyu7_FRAR_DeltaX_MASK)

#define fetchyu7_FRAR_DeltaY_MASK                (0xFC0000U)
#define fetchyu7_FRAR_DeltaY_SHIFT               (18U)
/*! DeltaY - DeltaY */
#define fetchyu7_FRAR_DeltaY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRAR_DeltaY_SHIFT)) & fetchyu7_FRAR_DeltaY_MASK)

#define fetchyu7_FRAR_SwaDir_MASK                (0x1000000U)
#define fetchyu7_FRAR_SwaDir_SHIFT               (24U)
/*! SwaDir - SwapDirection */
#define fetchyu7_FRAR_SwaDir(x)                  (((uint32_t)(((uint32_t)(x)) << fetchyu7_FRAR_SwaDir_SHIFT)) & fetchyu7_FRAR_SwaDir_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define fetchyu7_CONTR_RasterMo_MASK             (0x7U)
#define fetchyu7_CONTR_RasterMo_SHIFT            (0U)
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
#define fetchyu7_CONTR_RasterMo(x)               (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_RasterMo_SHIFT)) & fetchyu7_CONTR_RasterMo_MASK)

#define fetchyu7_CONTR_InputS_MASK               (0x18U)
#define fetchyu7_CONTR_InputS_SHIFT              (3U)
/*! InputS - InputSelect
 *  0b00..Not used.
 *  0b01..Used for component packing (e.g. UV or source alpha buffer).
 *  0b10..Used for RGB and alpha pre-multiply stage (mask alpha buffer).
 *  0b11..Used for arbitrary warping (coordinate buffer).
 */
#define fetchyu7_CONTR_InputS(x)                 (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_InputS_SHIFT)) & fetchyu7_CONTR_InputS_MASK)

#define fetchyu7_CONTR_YUV422UM_MASK             (0x20U)
#define fetchyu7_CONTR_YUV422UM_SHIFT            (5U)
/*! YUV422UM - YUV422UpsamplingMode
 *  0b0..Replicate mode for interspersed samples (UV samples between Y samples).
 *  0b1..Interpolate mode for coaligned samples (UV samples at Y sample positions).
 */
#define fetchyu7_CONTR_YUV422UM(x)               (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_YUV422UM_SHIFT)) & fetchyu7_CONTR_YUV422UM_MASK)

#define fetchyu7_CONTR_ChrHREn_MASK              (0x40U)
#define fetchyu7_CONTR_ChrHREn_SHIFT             (6U)
/*! ChrHREn - ChromaHReplEn
 *  0b0..Not used.
 *  0b1..Replicate mode for input samples.
 */
#define fetchyu7_CONTR_ChrHREn(x)                (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_ChrHREn_SHIFT)) & fetchyu7_CONTR_ChrHREn_MASK)

#define fetchyu7_CONTR_RawPixel_MASK             (0x80U)
#define fetchyu7_CONTR_RawPixel_SHIFT            (7U)
/*! RawPixel - RawPixel */
#define fetchyu7_CONTR_RawPixel(x)               (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_RawPixel_SHIFT)) & fetchyu7_CONTR_RawPixel_MASK)

#define fetchyu7_CONTR_ScInSel_MASK              (0x1800U)
#define fetchyu7_CONTR_ScInSel_SHIFT             (11U)
/*! ScInSel - SecInputSelect
 *  0b00..Not used.
 *  0b01..Used for component packing (e.g. UV or source alpha buffer).
 *  0b10..Used for RGB and alpha pre-multiply stage (mask alpha buffer).
 */
#define fetchyu7_CONTR_ScInSel(x)                (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_ScInSel_SHIFT)) & fetchyu7_CONTR_ScInSel_MASK)

#define fetchyu7_CONTR_YUV420UM_MASK             (0x6000U)
#define fetchyu7_CONTR_YUV420UM_SHIFT            (13U)
/*! YUV420UM - YUV420UpsamplingMode
 *  0b00..Not used.
 *  0b01..Replicate mode for interspersed samples (UV samples between Y samples).
 *  0b10..Interpolate mode for coaligned samples (UV samples at Y sample positions).
 *  0b11..Interpolate mode for interspersed interlaced samples (UV samples betwween Y samples).
 */
#define fetchyu7_CONTR_YUV420UM(x)               (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_YUV420UM_SHIFT)) & fetchyu7_CONTR_YUV420UM_MASK)

#define fetchyu7_CONTR_ClipCol_MASK              (0x10000U)
#define fetchyu7_CONTR_ClipCol_SHIFT             (16U)
/*! ClipCol - ClipColor
 *  0b0..Null color.
 *  0b1..Color of layer number given by ClipLayer (or layer 0 when Fetch unit has one layer only). The color is
 *       then the layer's source or tiling color.
 */
#define fetchyu7_CONTR_ClipCol(x)                (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTR_ClipCol_SHIFT)) & fetchyu7_CONTR_ClipCol_MASK)
/*! @} */

/*! @name CONTRIG - ControlTrigger */
/*! @{ */

#define fetchyu7_CONTRIG_SdTokGen_MASK           (0x1U)
#define fetchyu7_CONTRIG_SdTokGen_SHIFT          (0U)
/*! SdTokGen - ShdTokGen */
#define fetchyu7_CONTRIG_SdTokGen(x)             (((uint32_t)(((uint32_t)(x)) << fetchyu7_CONTRIG_SdTokGen_SHIFT)) & fetchyu7_CONTRIG_SdTokGen_MASK)
/*! @} */

/*! @name START - Start */
/*! @{ */

#define fetchyu7_START_Start1_MASK               (0x1U)
#define fetchyu7_START_Start1_SHIFT              (0U)
/*! Start1 - Start */
#define fetchyu7_START_Start1(x)                 (((uint32_t)(((uint32_t)(x)) << fetchyu7_START_Start1_SHIFT)) & fetchyu7_START_Start1_MASK)
/*! @} */

/*! @name FETTYPE - FetchType */
/*! @{ */

#define fetchyu7_FETTYPE_FetType_MASK            (0xFU)
#define fetchyu7_FETTYPE_FetType_SHIFT           (0U)
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
#define fetchyu7_FETTYPE_FetType(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu7_FETTYPE_FetType_SHIFT)) & fetchyu7_FETTYPE_FetType_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchyu7_Register_Masks */


/*!
 * @}
 */ /* end of group fetchyu7_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHYU7_H_ */

