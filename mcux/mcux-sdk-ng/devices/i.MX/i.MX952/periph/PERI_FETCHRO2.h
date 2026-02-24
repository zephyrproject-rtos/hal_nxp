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
**         CMSIS Peripheral Access Layer for fetchro2
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
 * @file PERI_fetchro2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchro2
 *
 * CMSIS Peripheral Access Layer for fetchro2
 */

#if !defined(PERI_FETCHRO2_H_)
#define PERI_FETCHRO2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchro2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro2_Peripheral_Access_Layer fetchro2 Peripheral Access Layer
 * @{
 */

/** fetchro2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t FRADIM;                            /**< FrameDimensions, offset: 0x0 */
  __IO uint32_t FRAR;                              /**< FrameResampling, offset: 0x4 */
  __IO uint32_t WARPCON;                           /**< WarpControl, offset: 0x8 */
  __IO uint32_t AFFINSTX;                          /**< AffineStartX, offset: 0xC */
  __IO uint32_t AFFINSTY;                          /**< AffineStartY, offset: 0x10 */
  __IO uint32_t AFFINDXX;                          /**< AffineDeltaXX, offset: 0x14 */
  __IO uint32_t AFFINDXY;                          /**< AffineDeltaXY, offset: 0x18 */
  __IO uint32_t AFFINDYX;                          /**< AffineDeltaYX, offset: 0x1C */
  __IO uint32_t AFFINDYY;                          /**< AffineDeltaYY, offset: 0x20 */
  __IO uint32_t ARBSTARX;                          /**< ArbStartX, offset: 0x24 */
  __IO uint32_t ARBSTARY;                          /**< ArbStartY, offset: 0x28 */
  __IO uint32_t ARBDELTA;                          /**< ArbDelta, offset: 0x2C */
  __IO uint32_t FIRPOS;                            /**< FIRPositions, offset: 0x30 */
  __IO uint32_t FIRCO;                             /**< FIRCoefficients, offset: 0x34 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x38 */
  __O  uint32_t CONTRIG;                           /**< ControlTrigger, offset: 0x3C */
  __O  uint32_t START;                             /**< Start, offset: 0x40 */
  __I  uint32_t FETTYPE;                           /**< FetchType, offset: 0x44 */
} fetchro2_Type;

/* ----------------------------------------------------------------------------
   -- fetchro2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro2_Register_Masks fetchro2 Register Masks
 * @{
 */

/*! @name FRADIM - FrameDimensions */
/*! @{ */

#define fetchro2_FRADIM_FrameWid_MASK            (0x3FFFU)
#define fetchro2_FRADIM_FrameWid_SHIFT           (0U)
/*! FrameWid - FrameWidth */
#define fetchro2_FRADIM_FrameWid(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FRADIM_FrameWid_SHIFT)) & fetchro2_FRADIM_FrameWid_MASK)

#define fetchro2_FRADIM_FrameHei_MASK            (0x3FFF0000U)
#define fetchro2_FRADIM_FrameHei_SHIFT           (16U)
/*! FrameHei - FrameHeight */
#define fetchro2_FRADIM_FrameHei(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FRADIM_FrameHei_SHIFT)) & fetchro2_FRADIM_FrameHei_MASK)

#define fetchro2_FRADIM_EmptFram_MASK            (0x80000000U)
#define fetchro2_FRADIM_EmptFram_SHIFT           (31U)
/*! EmptFram - EmptyFrame */
#define fetchro2_FRADIM_EmptFram(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FRADIM_EmptFram_SHIFT)) & fetchro2_FRADIM_EmptFram_MASK)
/*! @} */

/*! @name FRAR - FrameResampling */
/*! @{ */

#define fetchro2_FRAR_StartX_MASK                (0x3FU)
#define fetchro2_FRAR_StartX_SHIFT               (0U)
/*! StartX - StartX */
#define fetchro2_FRAR_StartX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchro2_FRAR_StartX_SHIFT)) & fetchro2_FRAR_StartX_MASK)

#define fetchro2_FRAR_StartY_MASK                (0xFC0U)
#define fetchro2_FRAR_StartY_SHIFT               (6U)
/*! StartY - StartY */
#define fetchro2_FRAR_StartY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchro2_FRAR_StartY_SHIFT)) & fetchro2_FRAR_StartY_MASK)

#define fetchro2_FRAR_DeltaX_MASK                (0x3F000U)
#define fetchro2_FRAR_DeltaX_SHIFT               (12U)
/*! DeltaX - DeltaX */
#define fetchro2_FRAR_DeltaX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchro2_FRAR_DeltaX_SHIFT)) & fetchro2_FRAR_DeltaX_MASK)

#define fetchro2_FRAR_DeltaY_MASK                (0xFC0000U)
#define fetchro2_FRAR_DeltaY_SHIFT               (18U)
/*! DeltaY - DeltaY */
#define fetchro2_FRAR_DeltaY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchro2_FRAR_DeltaY_SHIFT)) & fetchro2_FRAR_DeltaY_MASK)

#define fetchro2_FRAR_SwaDir_MASK                (0x1000000U)
#define fetchro2_FRAR_SwaDir_SHIFT               (24U)
/*! SwaDir - SwapDirection */
#define fetchro2_FRAR_SwaDir(x)                  (((uint32_t)(((uint32_t)(x)) << fetchro2_FRAR_SwaDir_SHIFT)) & fetchro2_FRAR_SwaDir_MASK)
/*! @} */

/*! @name WARPCON - WarpControl */
/*! @{ */

#define fetchro2_WARPCON_WarpBPP_MASK            (0x3FU)
#define fetchro2_WARPCON_WarpBPP_SHIFT           (0U)
/*! WarpBPP - WarpBitsPerPixel */
#define fetchro2_WARPCON_WarpBPP(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_WARPCON_WarpBPP_SHIFT)) & fetchro2_WARPCON_WarpBPP_MASK)

#define fetchro2_WARPCON_WarpCM_MASK             (0x300U)
#define fetchro2_WARPCON_WarpCM_SHIFT            (8U)
/*! WarpCM - WarpCoordinateMode
 *  0b00..x and y (sample points).
 *  0b01..dx and dy (vectors between adjacent sample points).
 *  0b10..ddx and ddy (deltas between adjacent vectors).
 */
#define fetchro2_WARPCON_WarpCM(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_WARPCON_WarpCM_SHIFT)) & fetchro2_WARPCON_WarpCM_MASK)

#define fetchro2_WARPCON_WarpSO_MASK             (0x1000U)
#define fetchro2_WARPCON_WarpSO_SHIFT            (12U)
/*! WarpSO - WarpSymmetricOffset */
#define fetchro2_WARPCON_WarpSO(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_WARPCON_WarpSO_SHIFT)) & fetchro2_WARPCON_WarpSO_MASK)

#define fetchro2_WARPCON_WRPXRasr_MASK           (0x30000U)
#define fetchro2_WARPCON_WRPXRasr_SHIFT          (16U)
/*! WRPXRasr - WRPT_XRaster
 *  0b00..X-Raster is 16 pixel.
 *  0b01..X-Raster is 32 pixel.
 *  0b10..X-Raster is 64 pixel.
 */
#define fetchro2_WARPCON_WRPXRasr(x)             (((uint32_t)(((uint32_t)(x)) << fetchro2_WARPCON_WRPXRasr_SHIFT)) & fetchro2_WARPCON_WRPXRasr_MASK)

#define fetchro2_WARPCON_WRPYRasr_MASK           (0xC0000U)
#define fetchro2_WARPCON_WRPYRasr_SHIFT          (18U)
/*! WRPYRasr - WRPT_YRaster
 *  0b00..Y-Raster is 16 pixel.
 *  0b01..Y-Raster is 32 pixel.
 *  0b10..Y-Raster is 64 pixel.
 */
#define fetchro2_WARPCON_WRPYRasr(x)             (((uint32_t)(((uint32_t)(x)) << fetchro2_WARPCON_WRPYRasr_SHIFT)) & fetchro2_WARPCON_WRPYRasr_MASK)

#define fetchro2_WARPCON_WRPSel_MASK             (0x100000U)
#define fetchro2_WARPCON_WRPSel_SHIFT            (20U)
/*! WRPSel - WRPT_Select
 *  0b0..Use WarpReferencePointsTable 0.
 *  0b1..Use WarpReferencePointsTable 1.
 */
#define fetchro2_WARPCON_WRPSel(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_WARPCON_WRPSel_SHIFT)) & fetchro2_WARPCON_WRPSel_MASK)
/*! @} */

/*! @name AFFINSTX - AffineStartX */
/*! @{ */

#define fetchro2_AFFINSTX_AffiSX_MASK            (0xFFFFF800U)
#define fetchro2_AFFINSTX_AffiSX_SHIFT           (11U)
/*! AffiSX - AffineStartX */
#define fetchro2_AFFINSTX_AffiSX(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_AFFINSTX_AffiSX_SHIFT)) & fetchro2_AFFINSTX_AffiSX_MASK)
/*! @} */

/*! @name AFFINSTY - AffineStartY */
/*! @{ */

#define fetchro2_AFFINSTY_AffiSY_MASK            (0xFFFFF800U)
#define fetchro2_AFFINSTY_AffiSY_SHIFT           (11U)
/*! AffiSY - AffineStartY */
#define fetchro2_AFFINSTY_AffiSY(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_AFFINSTY_AffiSY_SHIFT)) & fetchro2_AFFINSTY_AffiSY_MASK)
/*! @} */

/*! @name AFFINDXX - AffineDeltaXX */
/*! @{ */

#define fetchro2_AFFINDXX_AffiDXX_MASK           (0x1FFFFFFU)
#define fetchro2_AFFINDXX_AffiDXX_SHIFT          (0U)
/*! AffiDXX - AffineDeltaXX */
#define fetchro2_AFFINDXX_AffiDXX(x)             (((uint32_t)(((uint32_t)(x)) << fetchro2_AFFINDXX_AffiDXX_SHIFT)) & fetchro2_AFFINDXX_AffiDXX_MASK)
/*! @} */

/*! @name AFFINDXY - AffineDeltaXY */
/*! @{ */

#define fetchro2_AFFINDXY_AffiDXY_MASK           (0x1FFFFFFU)
#define fetchro2_AFFINDXY_AffiDXY_SHIFT          (0U)
/*! AffiDXY - AffineDeltaXY */
#define fetchro2_AFFINDXY_AffiDXY(x)             (((uint32_t)(((uint32_t)(x)) << fetchro2_AFFINDXY_AffiDXY_SHIFT)) & fetchro2_AFFINDXY_AffiDXY_MASK)
/*! @} */

/*! @name AFFINDYX - AffineDeltaYX */
/*! @{ */

#define fetchro2_AFFINDYX_AffiDYX_MASK           (0x1FFFFFFU)
#define fetchro2_AFFINDYX_AffiDYX_SHIFT          (0U)
/*! AffiDYX - AffineDeltaYX */
#define fetchro2_AFFINDYX_AffiDYX(x)             (((uint32_t)(((uint32_t)(x)) << fetchro2_AFFINDYX_AffiDYX_SHIFT)) & fetchro2_AFFINDYX_AffiDYX_MASK)
/*! @} */

/*! @name AFFINDYY - AffineDeltaYY */
/*! @{ */

#define fetchro2_AFFINDYY_AffiDYY_MASK           (0x1FFFFFFU)
#define fetchro2_AFFINDYY_AffiDYY_SHIFT          (0U)
/*! AffiDYY - AffineDeltaYY */
#define fetchro2_AFFINDYY_AffiDYY(x)             (((uint32_t)(((uint32_t)(x)) << fetchro2_AFFINDYY_AffiDYY_SHIFT)) & fetchro2_AFFINDYY_AffiDYY_MASK)
/*! @} */

/*! @name ARBSTARX - ArbStartX */
/*! @{ */

#define fetchro2_ARBSTARX_ArbSX_MASK             (0x1FFFFFU)
#define fetchro2_ARBSTARX_ArbSX_SHIFT            (0U)
/*! ArbSX - ArbStartX */
#define fetchro2_ARBSTARX_ArbSX(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_ARBSTARX_ArbSX_SHIFT)) & fetchro2_ARBSTARX_ArbSX_MASK)
/*! @} */

/*! @name ARBSTARY - ArbStartY */
/*! @{ */

#define fetchro2_ARBSTARY_ArbSY_MASK             (0x1FFFFFU)
#define fetchro2_ARBSTARY_ArbSY_SHIFT            (0U)
/*! ArbSY - ArbStartY */
#define fetchro2_ARBSTARY_ArbSY(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_ARBSTARY_ArbSY_SHIFT)) & fetchro2_ARBSTARY_ArbSY_MASK)
/*! @} */

/*! @name ARBDELTA - ArbDelta */
/*! @{ */

#define fetchro2_ARBDELTA_ArbDXX_MASK            (0xFFU)
#define fetchro2_ARBDELTA_ArbDXX_SHIFT           (0U)
/*! ArbDXX - ArbDeltaXX */
#define fetchro2_ARBDELTA_ArbDXX(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_ARBDELTA_ArbDXX_SHIFT)) & fetchro2_ARBDELTA_ArbDXX_MASK)

#define fetchro2_ARBDELTA_ArbDXY_MASK            (0xFF00U)
#define fetchro2_ARBDELTA_ArbDXY_SHIFT           (8U)
/*! ArbDXY - ArbDeltaXY */
#define fetchro2_ARBDELTA_ArbDXY(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_ARBDELTA_ArbDXY_SHIFT)) & fetchro2_ARBDELTA_ArbDXY_MASK)

#define fetchro2_ARBDELTA_ArbDYX_MASK            (0xFF0000U)
#define fetchro2_ARBDELTA_ArbDYX_SHIFT           (16U)
/*! ArbDYX - ArbDeltaYX */
#define fetchro2_ARBDELTA_ArbDYX(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_ARBDELTA_ArbDYX_SHIFT)) & fetchro2_ARBDELTA_ArbDYX_MASK)

#define fetchro2_ARBDELTA_ArbDYY_MASK            (0xFF000000U)
#define fetchro2_ARBDELTA_ArbDYY_SHIFT           (24U)
/*! ArbDYY - ArbDeltaYY */
#define fetchro2_ARBDELTA_ArbDYY(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_ARBDELTA_ArbDYY_SHIFT)) & fetchro2_ARBDELTA_ArbDYY_MASK)
/*! @} */

/*! @name FIRPOS - FIRPositions */
/*! @{ */

#define fetchro2_FIRPOS_FIR0Posi_MASK            (0xFU)
#define fetchro2_FIRPOS_FIR0Posi_SHIFT           (0U)
/*! FIR0Posi - FIR0Position */
#define fetchro2_FIRPOS_FIR0Posi(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRPOS_FIR0Posi_SHIFT)) & fetchro2_FIRPOS_FIR0Posi_MASK)

#define fetchro2_FIRPOS_FIR1Posi_MASK            (0xF0U)
#define fetchro2_FIRPOS_FIR1Posi_SHIFT           (4U)
/*! FIR1Posi - FIR1Position */
#define fetchro2_FIRPOS_FIR1Posi(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRPOS_FIR1Posi_SHIFT)) & fetchro2_FIRPOS_FIR1Posi_MASK)

#define fetchro2_FIRPOS_FIR2Posi_MASK            (0xF00U)
#define fetchro2_FIRPOS_FIR2Posi_SHIFT           (8U)
/*! FIR2Posi - FIR2Position */
#define fetchro2_FIRPOS_FIR2Posi(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRPOS_FIR2Posi_SHIFT)) & fetchro2_FIRPOS_FIR2Posi_MASK)

#define fetchro2_FIRPOS_FIR3Posi_MASK            (0xF000U)
#define fetchro2_FIRPOS_FIR3Posi_SHIFT           (12U)
/*! FIR3Posi - FIR3Position */
#define fetchro2_FIRPOS_FIR3Posi(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRPOS_FIR3Posi_SHIFT)) & fetchro2_FIRPOS_FIR3Posi_MASK)
/*! @} */

/*! @name FIRCO - FIRCoefficients */
/*! @{ */

#define fetchro2_FIRCO_FIR0Coef_MASK             (0xFFU)
#define fetchro2_FIRCO_FIR0Coef_SHIFT            (0U)
/*! FIR0Coef - FIR0Coefficient */
#define fetchro2_FIRCO_FIR0Coef(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRCO_FIR0Coef_SHIFT)) & fetchro2_FIRCO_FIR0Coef_MASK)

#define fetchro2_FIRCO_FIR1Coef_MASK             (0xFF00U)
#define fetchro2_FIRCO_FIR1Coef_SHIFT            (8U)
/*! FIR1Coef - FIR1Coefficient */
#define fetchro2_FIRCO_FIR1Coef(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRCO_FIR1Coef_SHIFT)) & fetchro2_FIRCO_FIR1Coef_MASK)

#define fetchro2_FIRCO_FIR2Coef_MASK             (0xFF0000U)
#define fetchro2_FIRCO_FIR2Coef_SHIFT            (16U)
/*! FIR2Coef - FIR2Coefficient */
#define fetchro2_FIRCO_FIR2Coef(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRCO_FIR2Coef_SHIFT)) & fetchro2_FIRCO_FIR2Coef_MASK)

#define fetchro2_FIRCO_FIR3Coef_MASK             (0xFF000000U)
#define fetchro2_FIRCO_FIR3Coef_SHIFT            (24U)
/*! FIR3Coef - FIR3Coefficient */
#define fetchro2_FIRCO_FIR3Coef(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_FIRCO_FIR3Coef_SHIFT)) & fetchro2_FIRCO_FIR3Coef_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define fetchro2_CONTR_RasterMo_MASK             (0x7U)
#define fetchro2_CONTR_RasterMo_SHIFT            (0U)
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
#define fetchro2_CONTR_RasterMo(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_RasterMo_SHIFT)) & fetchro2_CONTR_RasterMo_MASK)

#define fetchro2_CONTR_InputS_MASK               (0x18U)
#define fetchro2_CONTR_InputS_SHIFT              (3U)
/*! InputS - InputSelect
 *  0b00..Not used.
 *  0b01..Used for component packing (e.g. UV or source alpha buffer).
 *  0b10..Used for RGB and alpha pre-multiply stage (mask alpha buffer).
 *  0b11..Used for arbitrary warping (coordinate buffer).
 */
#define fetchro2_CONTR_InputS(x)                 (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_InputS_SHIFT)) & fetchro2_CONTR_InputS_MASK)

#define fetchro2_CONTR_YUV422UM_MASK             (0x20U)
#define fetchro2_CONTR_YUV422UM_SHIFT            (5U)
/*! YUV422UM - YUV422UpsamplingMode
 *  0b0..Replicate mode for interspersed samples (UV samples between Y samples).
 *  0b1..Interpolate mode for coaligned samples (UV samples at Y sample positions).
 */
#define fetchro2_CONTR_YUV422UM(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_YUV422UM_SHIFT)) & fetchro2_CONTR_YUV422UM_MASK)

#define fetchro2_CONTR_RawPixel_MASK             (0x80U)
#define fetchro2_CONTR_RawPixel_SHIFT            (7U)
/*! RawPixel - RawPixel */
#define fetchro2_CONTR_RawPixel(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_RawPixel_SHIFT)) & fetchro2_CONTR_RawPixel_MASK)

#define fetchro2_CONTR_ClipCol_MASK              (0x10000U)
#define fetchro2_CONTR_ClipCol_SHIFT             (16U)
/*! ClipCol - ClipColor
 *  0b0..Null color.
 *  0b1..Color of layer number given by ClipLayer (or layer 0 when Fetch unit has one layer only). The color is
 *       then the layer's source or tiling color.
 */
#define fetchro2_CONTR_ClipCol(x)                (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_ClipCol_SHIFT)) & fetchro2_CONTR_ClipCol_MASK)

#define fetchro2_CONTR_FilMode0_MASK             (0x1C00000U)
#define fetchro2_CONTR_FilMode0_SHIFT            (22U)
/*! FilMode0 - FilterMode
 *  0b000..Chooses pixel closest to sample point
 *  0b001..Calculates result from 4 pixels closest to sample point
 *  0b010..FIR mode with 2 programmable pixel positions and coefficients
 *  0b011..FIR mode with 4 programmable pixel positions and coefficients
 *  0b100..Calculates result from 2 pixels closest to the sample point and on the same line
 */
#define fetchro2_CONTR_FilMode0(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_FilMode0_SHIFT)) & fetchro2_CONTR_FilMode0_MASK)

#define fetchro2_CONTR_SynEn_MASK                (0x2000000U)
#define fetchro2_CONTR_SynEn_SHIFT               (25U)
/*! SynEn - Sync_En
 *  0b0..Synchronization disabled.
 *  0b1..Synchronization enabled.
 */
#define fetchro2_CONTR_SynEn(x)                  (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_SynEn_SHIFT)) & fetchro2_CONTR_SynEn_MASK)

#define fetchro2_CONTR_WRPEn_MASK                (0x4000000U)
#define fetchro2_CONTR_WRPEn_SHIFT               (26U)
/*! WRPEn - WRPT_En
 *  0b0..Warp reference points table disabled.
 *  0b1..Warp reference points table enabled.
 */
#define fetchro2_CONTR_WRPEn(x)                  (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_WRPEn_SHIFT)) & fetchro2_CONTR_WRPEn_MASK)

#define fetchro2_CONTR_YUVRotEn_MASK             (0x8000000U)
#define fetchro2_CONTR_YUVRotEn_SHIFT            (27U)
/*! YUVRotEn - YUVRot_En
 *  0b0..YUV mode rotation is disabled.
 *  0b1..YUV mode rotation is enabled.
 */
#define fetchro2_CONTR_YUVRotEn(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_YUVRotEn_SHIFT)) & fetchro2_CONTR_YUVRotEn_MASK)

#define fetchro2_CONTR_YUVRotMd_MASK             (0x30000000U)
#define fetchro2_CONTR_YUVRotMd_SHIFT            (28U)
/*! YUVRotMd - YUVRot_Mode
 *  0b00..With Y0 at LSBs, order is Y0 U0 Y1 V0 Y2 U1 Y3 V1...
 *  0b01..With U0 at LSBs, order is U0 Y0 V0 Y1 U1 Y2 V1 Y3...
 *  0b10..With Y0 at LSBs, order is Y0 V0 Y1 U0 Y2 V1 Y3 U1...
 *  0b11..With V0 at LSBs, order is V0 Y0 U0 Y1 V1 Y2 U1 Y3...
 */
#define fetchro2_CONTR_YUVRotMd(x)               (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTR_YUVRotMd_SHIFT)) & fetchro2_CONTR_YUVRotMd_MASK)
/*! @} */

/*! @name CONTRIG - ControlTrigger */
/*! @{ */

#define fetchro2_CONTRIG_SdTokGen_MASK           (0x1U)
#define fetchro2_CONTRIG_SdTokGen_SHIFT          (0U)
/*! SdTokGen - ShdTokGen */
#define fetchro2_CONTRIG_SdTokGen(x)             (((uint32_t)(((uint32_t)(x)) << fetchro2_CONTRIG_SdTokGen_SHIFT)) & fetchro2_CONTRIG_SdTokGen_MASK)
/*! @} */

/*! @name START - Start */
/*! @{ */

#define fetchro2_START_Start1_MASK               (0x1U)
#define fetchro2_START_Start1_SHIFT              (0U)
/*! Start1 - Start */
#define fetchro2_START_Start1(x)                 (((uint32_t)(((uint32_t)(x)) << fetchro2_START_Start1_SHIFT)) & fetchro2_START_Start1_MASK)
/*! @} */

/*! @name FETTYPE - FetchType */
/*! @{ */

#define fetchro2_FETTYPE_FetType_MASK            (0xFU)
#define fetchro2_FETTYPE_FetType_SHIFT           (0U)
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
#define fetchro2_FETTYPE_FetType(x)              (((uint32_t)(((uint32_t)(x)) << fetchro2_FETTYPE_FetType_SHIFT)) & fetchro2_FETTYPE_FetType_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchro2_Register_Masks */


/*!
 * @}
 */ /* end of group fetchro2_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHRO2_H_ */

