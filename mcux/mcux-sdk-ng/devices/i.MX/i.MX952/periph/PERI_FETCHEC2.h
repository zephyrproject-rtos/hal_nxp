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
**         CMSIS Peripheral Access Layer for fetchec2
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
 * @file PERI_fetchec2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchec2
 *
 * CMSIS Peripheral Access Layer for fetchec2
 */

#if !defined(PERI_FETCHEC2_H_)
#define PERI_FETCHEC2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchec2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec2_Peripheral_Access_Layer fetchec2 Peripheral Access Layer
 * @{
 */

/** fetchec2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t FRADIM;                            /**< FrameDimensions, offset: 0x0 */
  __IO uint32_t FRAR;                              /**< FrameResampling, offset: 0x4 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x8 */
  __O  uint32_t CONTRIG;                           /**< ControlTrigger, offset: 0xC */
  __O  uint32_t START;                             /**< Start, offset: 0x10 */
  __I  uint32_t FETTYPE;                           /**< FetchType, offset: 0x14 */
} fetchec2_Type;

/* ----------------------------------------------------------------------------
   -- fetchec2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec2_Register_Masks fetchec2 Register Masks
 * @{
 */

/*! @name FRADIM - FrameDimensions */
/*! @{ */

#define fetchec2_FRADIM_FrameWid_MASK            (0x3FFFU)
#define fetchec2_FRADIM_FrameWid_SHIFT           (0U)
/*! FrameWid - FrameWidth */
#define fetchec2_FRADIM_FrameWid(x)              (((uint32_t)(((uint32_t)(x)) << fetchec2_FRADIM_FrameWid_SHIFT)) & fetchec2_FRADIM_FrameWid_MASK)

#define fetchec2_FRADIM_FrameHei_MASK            (0x3FFF0000U)
#define fetchec2_FRADIM_FrameHei_SHIFT           (16U)
/*! FrameHei - FrameHeight */
#define fetchec2_FRADIM_FrameHei(x)              (((uint32_t)(((uint32_t)(x)) << fetchec2_FRADIM_FrameHei_SHIFT)) & fetchec2_FRADIM_FrameHei_MASK)

#define fetchec2_FRADIM_EmptFram_MASK            (0x80000000U)
#define fetchec2_FRADIM_EmptFram_SHIFT           (31U)
/*! EmptFram - EmptyFrame */
#define fetchec2_FRADIM_EmptFram(x)              (((uint32_t)(((uint32_t)(x)) << fetchec2_FRADIM_EmptFram_SHIFT)) & fetchec2_FRADIM_EmptFram_MASK)
/*! @} */

/*! @name FRAR - FrameResampling */
/*! @{ */

#define fetchec2_FRAR_StartX_MASK                (0x3FU)
#define fetchec2_FRAR_StartX_SHIFT               (0U)
/*! StartX - StartX */
#define fetchec2_FRAR_StartX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchec2_FRAR_StartX_SHIFT)) & fetchec2_FRAR_StartX_MASK)

#define fetchec2_FRAR_StartY_MASK                (0xFC0U)
#define fetchec2_FRAR_StartY_SHIFT               (6U)
/*! StartY - StartY */
#define fetchec2_FRAR_StartY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchec2_FRAR_StartY_SHIFT)) & fetchec2_FRAR_StartY_MASK)

#define fetchec2_FRAR_DeltaX_MASK                (0x3F000U)
#define fetchec2_FRAR_DeltaX_SHIFT               (12U)
/*! DeltaX - DeltaX */
#define fetchec2_FRAR_DeltaX(x)                  (((uint32_t)(((uint32_t)(x)) << fetchec2_FRAR_DeltaX_SHIFT)) & fetchec2_FRAR_DeltaX_MASK)

#define fetchec2_FRAR_DeltaY_MASK                (0xFC0000U)
#define fetchec2_FRAR_DeltaY_SHIFT               (18U)
/*! DeltaY - DeltaY */
#define fetchec2_FRAR_DeltaY(x)                  (((uint32_t)(((uint32_t)(x)) << fetchec2_FRAR_DeltaY_SHIFT)) & fetchec2_FRAR_DeltaY_MASK)

#define fetchec2_FRAR_SwaDir_MASK                (0x1000000U)
#define fetchec2_FRAR_SwaDir_SHIFT               (24U)
/*! SwaDir - SwapDirection */
#define fetchec2_FRAR_SwaDir(x)                  (((uint32_t)(((uint32_t)(x)) << fetchec2_FRAR_SwaDir_SHIFT)) & fetchec2_FRAR_SwaDir_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define fetchec2_CONTR_RawPixel_MASK             (0x80U)
#define fetchec2_CONTR_RawPixel_SHIFT            (7U)
/*! RawPixel - RawPixel */
#define fetchec2_CONTR_RawPixel(x)               (((uint32_t)(((uint32_t)(x)) << fetchec2_CONTR_RawPixel_SHIFT)) & fetchec2_CONTR_RawPixel_MASK)

#define fetchec2_CONTR_ClipCol_MASK              (0x10000U)
#define fetchec2_CONTR_ClipCol_SHIFT             (16U)
/*! ClipCol - ClipColor
 *  0b0..Null color.
 *  0b1..Color of layer number given by ClipLayer (or layer 0 when Fetch unit has one layer only). The color is
 *       then the layer's source or tiling color.
 */
#define fetchec2_CONTR_ClipCol(x)                (((uint32_t)(((uint32_t)(x)) << fetchec2_CONTR_ClipCol_SHIFT)) & fetchec2_CONTR_ClipCol_MASK)
/*! @} */

/*! @name CONTRIG - ControlTrigger */
/*! @{ */

#define fetchec2_CONTRIG_SdTokGen_MASK           (0x1U)
#define fetchec2_CONTRIG_SdTokGen_SHIFT          (0U)
/*! SdTokGen - ShdTokGen */
#define fetchec2_CONTRIG_SdTokGen(x)             (((uint32_t)(((uint32_t)(x)) << fetchec2_CONTRIG_SdTokGen_SHIFT)) & fetchec2_CONTRIG_SdTokGen_MASK)
/*! @} */

/*! @name START - Start */
/*! @{ */

#define fetchec2_START_Start1_MASK               (0x1U)
#define fetchec2_START_Start1_SHIFT              (0U)
/*! Start1 - Start */
#define fetchec2_START_Start1(x)                 (((uint32_t)(((uint32_t)(x)) << fetchec2_START_Start1_SHIFT)) & fetchec2_START_Start1_MASK)
/*! @} */

/*! @name FETTYPE - FetchType */
/*! @{ */

#define fetchec2_FETTYPE_FetType_MASK            (0xFU)
#define fetchec2_FETTYPE_FetType_SHIFT           (0U)
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
#define fetchec2_FETTYPE_FetType(x)              (((uint32_t)(((uint32_t)(x)) << fetchec2_FETTYPE_FetType_SHIFT)) & fetchec2_FETTYPE_FetType_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchec2_Register_Masks */


/*!
 * @}
 */ /* end of group fetchec2_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHEC2_H_ */

