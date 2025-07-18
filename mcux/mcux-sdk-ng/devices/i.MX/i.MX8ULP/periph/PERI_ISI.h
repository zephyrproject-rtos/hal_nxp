/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ISI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ISI.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ISI
 *
 * CMSIS Peripheral Access Layer for ISI
 */

#if !defined(PERI_ISI_H_)
#define PERI_ISI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ISI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISI_Peripheral_Access_Layer ISI Peripheral Access Layer
 * @{
 */

/** ISI - Size of Registers Arrays */
#define ISI_ROI_COUNT                             4u

/** ISI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CHNL_CTRL;                         /**< Channel Control, offset: 0x0 */
  __IO uint32_t CHNL_IMG_CTRL;                     /**< Channel Image Control, offset: 0x4 */
  __IO uint32_t CHNL_OUT_BUF_CTRL;                 /**< Channel Output Buffer Control, offset: 0x8 */
  __IO uint32_t CHNL_IMG_CFG;                      /**< Channel Image Configuration, offset: 0xC */
  __IO uint32_t CHNL_IER;                          /**< Channel Interrupt Enable, offset: 0x10 */
  __IO uint32_t CHNL_STS;                          /**< Channel Status, offset: 0x14 */
  __IO uint32_t CHNL_SCALE_FACTOR;                 /**< Channel Scale Factor, offset: 0x18 */
  __IO uint32_t CHNL_SCALE_OFFSET;                 /**< Channel Scale Offset, offset: 0x1C */
  __IO uint32_t CHNL_CROP_ULC;                     /**< Channel Crop Upper Left Corner Coordinate, offset: 0x20 */
  __IO uint32_t CHNL_CROP_LRC;                     /**< Channel Crop Lower Right Corner Coordinate, offset: 0x24 */
  __IO uint32_t CHNL_CSC_COEFF0;                   /**< Channel Color Space Conversion Coefficient 0, offset: 0x28 */
  __IO uint32_t CHNL_CSC_COEFF1;                   /**< Channel Color Space Conversion Coefficient 1, offset: 0x2C */
  __IO uint32_t CHNL_CSC_COEFF2;                   /**< Channel Color Space Conversion Coefficient 2, offset: 0x30 */
  __IO uint32_t CHNL_CSC_COEFF3;                   /**< Channel Color Space Conversion Coefficient 3, offset: 0x34 */
  __IO uint32_t CHNL_CSC_COEFF4;                   /**< Channel Color Space Conversion Coefficient 4, offset: 0x38 */
  __IO uint32_t CHNL_CSC_COEFF5;                   /**< Channel Color Space Conversion Coefficient 5, offset: 0x3C */
  struct {                                         /* offset: 0x40, array step: 0xC */
    __IO uint32_t CHNL_ROI_ALPHA;                    /**< Channel Alpha Value for ROI 0..Channel Alpha Value for ROI 3, array offset: 0x40, array step: 0xC */
    __IO uint32_t CHNL_ROI_ULC;                      /**< Channel Upper Left Coordinate for ROI 0..Channel Upper Left Coordinate for ROI 3, array offset: 0x44, array step: 0xC */
    __IO uint32_t CHNL_ROI_LRC;                      /**< Channel Lower Right Coordinate for ROI 0..Channel Lower Right Coordinate for ROI 3, array offset: 0x48, array step: 0xC */
  } ROI[ISI_ROI_COUNT];
  __IO uint32_t CHNL_OUT_BUF1_ADDR_Y;              /**< Channel RGB or Luma (Y) Output Buffer 1 Address, offset: 0x70 */
  __IO uint32_t CHNL_OUT_BUF1_ADDR_U;              /**< Channel Chroma (U/Cb/UV/CbCr) Output Buffer 1 Address, offset: 0x74 */
  __IO uint32_t CHNL_OUT_BUF1_ADDR_V;              /**< Channel Chroma (V/Cr) Output Buffer 1 Address, offset: 0x78 */
  __IO uint32_t CHNL_OUT_BUF_PITCH;                /**< Channel Output Buffer Pitch, offset: 0x7C */
  __IO uint32_t CHNL_IN_BUF_ADDR;                  /**< Channel Input Buffer Address, offset: 0x80 */
  __IO uint32_t CHNL_IN_BUF_PITCH;                 /**< Channel Input Buffer Pitch, offset: 0x84 */
  __IO uint32_t CHNL_MEM_RD_CTRL;                  /**< Channel Memory Read Control, offset: 0x88 */
  __IO uint32_t CHNL_OUT_BUF2_ADDR_Y;              /**< Channel RGB or Luma (Y) Output Buffer 2 Address, offset: 0x8C */
  __IO uint32_t CHNL_OUT_BUF2_ADDR_U;              /**< Channel Chroma (U/Cb/UV/CbCr) Output Buffer 2 Address, offset: 0x90 */
  __IO uint32_t CHNL_OUT_BUF2_ADDR_V;              /**< Channel Chroma (V/Cr) Output Buffer 2 Address, offset: 0x94 */
  __IO uint32_t CHNL_SCL_IMG_CFG;                  /**< Channel Scaled Image Configuration, offset: 0x98 */
  __IO uint32_t CHNL_FLOW_CTRL;                    /**< Channel Flow Control, offset: 0x9C */
} ISI_Type;

/* ----------------------------------------------------------------------------
   -- ISI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISI_Register_Masks ISI Register Masks
 * @{
 */

/*! @name CHNL_CTRL - Channel Control */
/*! @{ */

#define ISI_CHNL_CTRL_SRC_MASK                   (0x1U)
#define ISI_CHNL_CTRL_SRC_SHIFT                  (0U)
/*! SRC - Input Image Source Port Selection
 *  0b0..Port 0
 *  0b1..Port 1
 */
#define ISI_CHNL_CTRL_SRC(x)                     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SRC_SHIFT)) & ISI_CHNL_CTRL_SRC_MASK)

#define ISI_CHNL_CTRL_SRC_TYPE_MASK              (0x10U)
#define ISI_CHNL_CTRL_SRC_TYPE_SHIFT             (4U)
/*! SRC_TYPE - Type of Selected Input Image Source
 *  0b0..Pixel link
 *  0b1..Memory
 */
#define ISI_CHNL_CTRL_SRC_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SRC_TYPE_SHIFT)) & ISI_CHNL_CTRL_SRC_TYPE_MASK)

#define ISI_CHNL_CTRL_SEC_LB_SRC_MASK            (0x700U)
#define ISI_CHNL_CTRL_SEC_LB_SRC_SHIFT           (8U)
/*! SEC_LB_SRC - Secondary Line Buffer Source */
#define ISI_CHNL_CTRL_SEC_LB_SRC(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SEC_LB_SRC_SHIFT)) & ISI_CHNL_CTRL_SEC_LB_SRC_MASK)

#define ISI_CHNL_CTRL_VER_ID_MASK                (0x3C0000U)
#define ISI_CHNL_CTRL_VER_ID_SHIFT               (18U)
/*! VER_ID - Version ID */
#define ISI_CHNL_CTRL_VER_ID(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_VER_ID_SHIFT)) & ISI_CHNL_CTRL_VER_ID_MASK)

#define ISI_CHNL_CTRL_SW_RST_MASK                (0x1000000U)
#define ISI_CHNL_CTRL_SW_RST_SHIFT               (24U)
/*! SW_RST - Software Reset
 *  0b0..No reset
 *  0b1..Software reset
 */
#define ISI_CHNL_CTRL_SW_RST(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SW_RST_SHIFT)) & ISI_CHNL_CTRL_SW_RST_MASK)

#define ISI_CHNL_CTRL_CHAIN_BUF_MASK             (0x6000000U)
#define ISI_CHNL_CTRL_CHAIN_BUF_SHIFT            (25U)
/*! CHAIN_BUF - Chain Line Buffer Control
 *  0b00..No line buffers chained (supports 2048 or less horizontal resolution)
 *  0b01..Two line buffers chained (supports 4096 horizontal resolution)
 *  0b10..
 *  0b11..
 */
#define ISI_CHNL_CTRL_CHAIN_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHAIN_BUF_SHIFT)) & ISI_CHNL_CTRL_CHAIN_BUF_MASK)

#define ISI_CHNL_CTRL_CHNL_BYPASS_MASK           (0x20000000U)
#define ISI_CHNL_CTRL_CHNL_BYPASS_SHIFT          (29U)
/*! CHNL_BYPASS - Channel Bypass Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_CTRL_CHNL_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHNL_BYPASS_SHIFT)) & ISI_CHNL_CTRL_CHNL_BYPASS_MASK)

#define ISI_CHNL_CTRL_CLK_EN_MASK                (0x40000000U)
#define ISI_CHNL_CTRL_CLK_EN_SHIFT               (30U)
/*! CLK_EN - Channel Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_CTRL_CLK_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CLK_EN_SHIFT)) & ISI_CHNL_CTRL_CLK_EN_MASK)

#define ISI_CHNL_CTRL_CHNL_EN_MASK               (0x80000000U)
#define ISI_CHNL_CTRL_CHNL_EN_SHIFT              (31U)
/*! CHNL_EN - Enable Channel Processing
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_CTRL_CHNL_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHNL_EN_SHIFT)) & ISI_CHNL_CTRL_CHNL_EN_MASK)
/*! @} */

/*! @name CHNL_IMG_CTRL - Channel Image Control */
/*! @{ */

#define ISI_CHNL_IMG_CTRL_CSC_BYP_MASK           (0x1U)
#define ISI_CHNL_IMG_CTRL_CSC_BYP_SHIFT          (0U)
/*! CSC_BYP - Color Space Conversion Bypass Control
 *  0b0..CSC operational
 *  0b1..CSC bypassed
 */
#define ISI_CHNL_IMG_CTRL_CSC_BYP(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CSC_BYP_SHIFT)) & ISI_CHNL_IMG_CTRL_CSC_BYP_MASK)

#define ISI_CHNL_IMG_CTRL_CSC_MODE_MASK          (0x6U)
#define ISI_CHNL_IMG_CTRL_CSC_MODE_SHIFT         (1U)
/*! CSC_MODE - Color Space Conversion Operating Mode
 *  0b00..Convert from YUV to RGB
 *  0b01..Convert from YCbCr to RGB
 *  0b10..Convert from RGB to YUV
 *  0b11..Convert from RGB to YCbCr
 */
#define ISI_CHNL_IMG_CTRL_CSC_MODE(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CSC_MODE_SHIFT)) & ISI_CHNL_IMG_CTRL_CSC_MODE_MASK)

#define ISI_CHNL_IMG_CTRL_YCBCR_MODE_MASK        (0x8U)
#define ISI_CHNL_IMG_CTRL_YCBCR_MODE_SHIFT       (3U)
/*! YCBCR_MODE - YCbCr Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IMG_CTRL_YCBCR_MODE(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_YCBCR_MODE_SHIFT)) & ISI_CHNL_IMG_CTRL_YCBCR_MODE_MASK)

#define ISI_CHNL_IMG_CTRL_HFLIP_EN_MASK          (0x20U)
#define ISI_CHNL_IMG_CTRL_HFLIP_EN_SHIFT         (5U)
/*! HFLIP_EN - Horizontal Flip Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IMG_CTRL_HFLIP_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_HFLIP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_HFLIP_EN_MASK)

#define ISI_CHNL_IMG_CTRL_VFLIP_EN_MASK          (0x40U)
#define ISI_CHNL_IMG_CTRL_VFLIP_EN_SHIFT         (6U)
/*! VFLIP_EN - Vertical Flip Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IMG_CTRL_VFLIP_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_VFLIP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_VFLIP_EN_MASK)

#define ISI_CHNL_IMG_CTRL_CROP_EN_MASK           (0x80U)
#define ISI_CHNL_IMG_CTRL_CROP_EN_SHIFT          (7U)
/*! CROP_EN - Output Image Cropping Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IMG_CTRL_CROP_EN(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CROP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_CROP_EN_MASK)

#define ISI_CHNL_IMG_CTRL_DEC_Y_MASK             (0x300U)
#define ISI_CHNL_IMG_CTRL_DEC_Y_SHIFT            (8U)
/*! DEC_Y - Vertical Pre-Decimation Control
 *  0b00..Disabled
 *  0b01..Decimate by 2
 *  0b10..Decimate by 4
 *  0b11..Decimate by 8
 */
#define ISI_CHNL_IMG_CTRL_DEC_Y(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEC_Y_SHIFT)) & ISI_CHNL_IMG_CTRL_DEC_Y_MASK)

#define ISI_CHNL_IMG_CTRL_DEC_X_MASK             (0xC00U)
#define ISI_CHNL_IMG_CTRL_DEC_X_SHIFT            (10U)
/*! DEC_X - Horizontal Pre-Decimation Control
 *  0b00..Disabled
 *  0b01..Decimate by 2
 *  0b10..Decimate by 4
 *  0b11..Decimate by 8
 */
#define ISI_CHNL_IMG_CTRL_DEC_X(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEC_X_SHIFT)) & ISI_CHNL_IMG_CTRL_DEC_X_MASK)

#define ISI_CHNL_IMG_CTRL_DEINT_MASK             (0x7000U)
#define ISI_CHNL_IMG_CTRL_DEINT_SHIFT            (12U)
/*! DEINT - Deinterlace Control
 *  0b000, 0b001..No deinterlacing
 *  0b010..Weave deinterlacing (odd, even)
 *  0b011..Weave deinterlacing (even, odd)
 */
#define ISI_CHNL_IMG_CTRL_DEINT(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEINT_SHIFT)) & ISI_CHNL_IMG_CTRL_DEINT_MASK)

#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_MASK      (0x8000U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_SHIFT     (15U)
/*! GBL_ALPHA_EN - Global Alpha Value Insertion Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_MASK)

#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_MASK     (0xFF0000U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_SHIFT    (16U)
/*! GBL_ALPHA_VAL - Global Alpha Value
 *  0b00000000-0b11111111..Alpha value to be inserted with all RGB pixels
 */
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_SHIFT)) & ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_MASK)

#define ISI_CHNL_IMG_CTRL_FORMAT_MASK            (0x7F000000U)
#define ISI_CHNL_IMG_CTRL_FORMAT_SHIFT           (24U)
/*! FORMAT - Output Image Format */
#define ISI_CHNL_IMG_CTRL_FORMAT(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_FORMAT_SHIFT)) & ISI_CHNL_IMG_CTRL_FORMAT_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF_CTRL - Channel Output Buffer Control */
/*! @{ */

#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_MASK (0xFU)
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_SHIFT (0U)
/*! PANIC_SET_THD_Y - Overflow Panic Set Threshold Value for Y or RGB Output Buffer
 *  0b0000..No panic alert
 *  0b0001-0b1111..Panic asserts
 */
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_MASK (0xF00U)
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_SHIFT (8U)
/*! PANIC_SET_THD_U - Overflow Panic Set Threshold Value for U Output Buffer
 *  0b0000..No panic alert
 *  0b0001-0b1111..Panic asserts
 */
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_MASK (0x4000U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_SHIFT (14U)
/*! LOAD_BUF1_ADDR - Load Buffer 1 Address */
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_MASK (0x8000U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_SHIFT (15U)
/*! LOAD_BUF2_ADDR - Load Buffer 2 Address */
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_MASK (0xF0000U)
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_SHIFT (16U)
/*! PANIC_SET_THD_V - Overflow Panic Set Threshold Value for V Output Buffer
 *  0b0000..No panic alert
 *  0b0001-0b1111..Panic asserts
 */
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_MASK (0x40000000U)
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_SHIFT (30U)
/*! MAX_WR_BEATS_UV - Maximum AXI Write Beats for U- and V-Buffers
 *  0b0..8 beats per write (128 bytes)
 *  0b1..16 beats per write (256 bytes)
 */
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_MASK (0x80000000U)
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_SHIFT (31U)
/*! MAX_WR_BEATS_Y - Maximum AXI Write Beats for Y-Buffer
 *  0b0..8 beats per write (128 bytes)
 *  0b1..16 beats per write (256 bytes)
 */
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_MASK)
/*! @} */

/*! @name CHNL_IMG_CFG - Channel Image Configuration */
/*! @{ */

#define ISI_CHNL_IMG_CFG_WIDTH_MASK              (0x1FFFU)
#define ISI_CHNL_IMG_CFG_WIDTH_SHIFT             (0U)
/*! WIDTH - Input Image Width */
#define ISI_CHNL_IMG_CFG_WIDTH(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_WIDTH_SHIFT)) & ISI_CHNL_IMG_CFG_WIDTH_MASK)

#define ISI_CHNL_IMG_CFG_HEIGHT_MASK             (0x1FFF0000U)
#define ISI_CHNL_IMG_CFG_HEIGHT_SHIFT            (16U)
/*! HEIGHT - Input Image Height */
#define ISI_CHNL_IMG_CFG_HEIGHT(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_HEIGHT_SHIFT)) & ISI_CHNL_IMG_CFG_HEIGHT_MASK)
/*! @} */

/*! @name CHNL_IER - Channel Interrupt Enable */
/*! @{ */

#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN_MASK      (0x10000U)
#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN_SHIFT     (16U)
/*! LATE_VSYNC_ERR_EN - VSYNC Timing (Late) Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_LATE_VSYNC_ERR_EN_SHIFT)) & ISI_CHNL_IER_LATE_VSYNC_ERR_EN_MASK)

#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_MASK     (0x20000U)
#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_SHIFT    (17U)
/*! EARLY_VSYNC_ERR_EN - VSYNC Timing (Early) Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_SHIFT)) & ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_MASK)

#define ISI_CHNL_IER_OFLW_Y_BUF_EN_MASK          (0x40000U)
#define ISI_CHNL_IER_OFLW_Y_BUF_EN_SHIFT         (18U)
/*! OFLW_Y_BUF_EN - Y Output Buffer Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_OFLW_Y_BUF_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_Y_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_Y_BUF_EN_MASK)

#define ISI_CHNL_IER_PANIC_Y_BUF_EN_MASK         (0x80000U)
#define ISI_CHNL_IER_PANIC_Y_BUF_EN_SHIFT        (19U)
/*! PANIC_Y_BUF_EN - Y Output Buffer Potential Overflow Panic Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_PANIC_Y_BUF_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_PANIC_Y_BUF_EN_SHIFT)) & ISI_CHNL_IER_PANIC_Y_BUF_EN_MASK)

#define ISI_CHNL_IER_OFLW_U_BUF_EN_MASK          (0x100000U)
#define ISI_CHNL_IER_OFLW_U_BUF_EN_SHIFT         (20U)
/*! OFLW_U_BUF_EN - U Output Buffer Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_OFLW_U_BUF_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_U_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_U_BUF_EN_MASK)

#define ISI_CHNL_IER_PANIC_U_BUF_EN_MASK         (0x200000U)
#define ISI_CHNL_IER_PANIC_U_BUF_EN_SHIFT        (21U)
/*! PANIC_U_BUF_EN - U Output Buffer Potential Overflow Panic Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_PANIC_U_BUF_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_PANIC_U_BUF_EN_SHIFT)) & ISI_CHNL_IER_PANIC_U_BUF_EN_MASK)

#define ISI_CHNL_IER_OFLW_V_BUF_EN_MASK          (0x400000U)
#define ISI_CHNL_IER_OFLW_V_BUF_EN_SHIFT         (22U)
/*! OFLW_V_BUF_EN - V Output Buffer Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_OFLW_V_BUF_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_V_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_V_BUF_EN_MASK)

#define ISI_CHNL_IER_PANIC_V_BUF_EN_MASK         (0x800000U)
#define ISI_CHNL_IER_PANIC_V_BUF_EN_SHIFT        (23U)
/*! PANIC_V_BUF_EN - V Output Buffer Potential Overflow Panic Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_PANIC_V_BUF_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_PANIC_V_BUF_EN_SHIFT)) & ISI_CHNL_IER_PANIC_V_BUF_EN_MASK)

#define ISI_CHNL_IER_AXI_RD_ERR_EN_MASK          (0x2000000U)
#define ISI_CHNL_IER_AXI_RD_ERR_EN_SHIFT         (25U)
/*! AXI_RD_ERR_EN - AXI Bus Read Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_AXI_RD_ERR_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_RD_ERR_EN_SHIFT)) & ISI_CHNL_IER_AXI_RD_ERR_EN_MASK)

#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN_MASK        (0x4000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN_SHIFT       (26U)
/*! AXI_WR_ERR_Y_EN - AXI Bus Read Error Interrupt Enable for Y and RGB Data Buffer
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_Y_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_Y_EN_MASK)

#define ISI_CHNL_IER_AXI_WR_ERR_U_EN_MASK        (0x8000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_U_EN_SHIFT       (27U)
/*! AXI_WR_ERR_U_EN - AXI Bus Read Error Interrupt Enable for U Data Buffer
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_AXI_WR_ERR_U_EN(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_U_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_U_EN_MASK)

#define ISI_CHNL_IER_AXI_WR_ERR_V_EN_MASK        (0x10000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_V_EN_SHIFT       (28U)
/*! AXI_WR_ERR_V_EN - AXI Bus Read Error Interrupt Enable for V Data Buffer
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_AXI_WR_ERR_V_EN(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_V_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_V_EN_MASK)

#define ISI_CHNL_IER_FRM_RCVD_EN_MASK            (0x20000000U)
#define ISI_CHNL_IER_FRM_RCVD_EN_SHIFT           (29U)
/*! FRM_RCVD_EN - Frame Received Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_FRM_RCVD_EN(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_FRM_RCVD_EN_SHIFT)) & ISI_CHNL_IER_FRM_RCVD_EN_MASK)

#define ISI_CHNL_IER_LINE_RCVD_EN_MASK           (0x40000000U)
#define ISI_CHNL_IER_LINE_RCVD_EN_SHIFT          (30U)
/*! LINE_RCVD_EN - Line Received Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_LINE_RCVD_EN(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_LINE_RCVD_EN_SHIFT)) & ISI_CHNL_IER_LINE_RCVD_EN_MASK)

#define ISI_CHNL_IER_MEM_RD_DONE_EN_MASK         (0x80000000U)
#define ISI_CHNL_IER_MEM_RD_DONE_EN_SHIFT        (31U)
/*! MEM_RD_DONE_EN - Memory Read Complete Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_IER_MEM_RD_DONE_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_MEM_RD_DONE_EN_SHIFT)) & ISI_CHNL_IER_MEM_RD_DONE_EN_MASK)
/*! @} */

/*! @name CHNL_STS - Channel Status */
/*! @{ */

#define ISI_CHNL_STS_BUF1_ACTIVE_MASK            (0x100U)
#define ISI_CHNL_STS_BUF1_ACTIVE_SHIFT           (8U)
/*! BUF1_ACTIVE - Current Frame Stored in Buffer 1 Address
 *  0b0..Buffer 1 address inactive
 *  0b1..Buffer 1 address in use
 */
#define ISI_CHNL_STS_BUF1_ACTIVE(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_BUF1_ACTIVE_SHIFT)) & ISI_CHNL_STS_BUF1_ACTIVE_MASK)

#define ISI_CHNL_STS_BUF2_ACTIVE_MASK            (0x200U)
#define ISI_CHNL_STS_BUF2_ACTIVE_SHIFT           (9U)
/*! BUF2_ACTIVE - Current Frame Stored in Buffer 2 Address
 *  0b0..Buffer 2 address inactive
 *  0b1..Buffer 2 address in use
 */
#define ISI_CHNL_STS_BUF2_ACTIVE(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_BUF2_ACTIVE_SHIFT)) & ISI_CHNL_STS_BUF2_ACTIVE_MASK)

#define ISI_CHNL_STS_MEM_RD_OFLOW_MASK           (0x400U)
#define ISI_CHNL_STS_MEM_RD_OFLOW_SHIFT          (10U)
/*! MEM_RD_OFLOW - Memory Read FIFO Overflow Error Status
 *  0b0..No overflow
 *  0b1..FIFO overflow
 */
#define ISI_CHNL_STS_MEM_RD_OFLOW(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_MEM_RD_OFLOW_SHIFT)) & ISI_CHNL_STS_MEM_RD_OFLOW_MASK)

#define ISI_CHNL_STS_LATE_VSYNC_ERR_MASK         (0x10000U)
#define ISI_CHNL_STS_LATE_VSYNC_ERR_SHIFT        (16U)
/*! LATE_VSYNC_ERR - VSYNC Timing (Late) Error Interrupt flag
 *  0b0..No error
 *  0b1..VSYNC detected later
 */
#define ISI_CHNL_STS_LATE_VSYNC_ERR(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_LATE_VSYNC_ERR_SHIFT)) & ISI_CHNL_STS_LATE_VSYNC_ERR_MASK)

#define ISI_CHNL_STS_EARLY_VSYNC_ERR_MASK        (0x20000U)
#define ISI_CHNL_STS_EARLY_VSYNC_ERR_SHIFT       (17U)
/*! EARLY_VSYNC_ERR - VSYNC Timing (Early) Error Interrupt flag
 *  0b0..No error
 *  0b1..VSYNC detected earlier
 */
#define ISI_CHNL_STS_EARLY_VSYNC_ERR(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_EARLY_VSYNC_ERR_SHIFT)) & ISI_CHNL_STS_EARLY_VSYNC_ERR_MASK)

#define ISI_CHNL_STS_OFLW_Y_BUF_MASK             (0x40000U)
#define ISI_CHNL_STS_OFLW_Y_BUF_SHIFT            (18U)
/*! OFLW_Y_BUF - Overflow in Y or RGB Output Buffer Interrupt Flag
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define ISI_CHNL_STS_OFLW_Y_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_Y_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_Y_BUF_MASK)

#define ISI_CHNL_STS_PANIC_Y_BUF_MASK            (0x80000U)
#define ISI_CHNL_STS_PANIC_Y_BUF_SHIFT           (19U)
/*! PANIC_Y_BUF - Y or RGB Output Buffer Potential Overflow Panic Alert Interrupt Flag
 *  0b0..Threshold limit not crossed
 *  0b1..Threshold limit crossed
 */
#define ISI_CHNL_STS_PANIC_Y_BUF(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_PANIC_Y_BUF_SHIFT)) & ISI_CHNL_STS_PANIC_Y_BUF_MASK)

#define ISI_CHNL_STS_OFLW_U_BUF_MASK             (0x100000U)
#define ISI_CHNL_STS_OFLW_U_BUF_SHIFT            (20U)
/*! OFLW_U_BUF - Overflow in U Output Buffer Interrupt Flag
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define ISI_CHNL_STS_OFLW_U_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_U_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_U_BUF_MASK)

#define ISI_CHNL_STS_PANIC_U_BUF_MASK            (0x200000U)
#define ISI_CHNL_STS_PANIC_U_BUF_SHIFT           (21U)
/*! PANIC_U_BUF - U Output Buffer Potential Overflow Panic Alert Interrupt Flag
 *  0b0..Threshold limit not crossed
 *  0b1..Threshold limit crossed
 */
#define ISI_CHNL_STS_PANIC_U_BUF(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_PANIC_U_BUF_SHIFT)) & ISI_CHNL_STS_PANIC_U_BUF_MASK)

#define ISI_CHNL_STS_OFLW_V_BUF_MASK             (0x400000U)
#define ISI_CHNL_STS_OFLW_V_BUF_SHIFT            (22U)
/*! OFLW_V_BUF - Overflow in V Output Buffer Interrupt Flag
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define ISI_CHNL_STS_OFLW_V_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_V_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_V_BUF_MASK)

#define ISI_CHNL_STS_PANIC_V_BUF_MASK            (0x800000U)
#define ISI_CHNL_STS_PANIC_V_BUF_SHIFT           (23U)
/*! PANIC_V_BUF - V Output Buffer Potential Overflow Panic Alert Interrupt Flag
 *  0b0..Threshold limit not crossed
 *  0b1..Threshold limit crossed
 */
#define ISI_CHNL_STS_PANIC_V_BUF(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_PANIC_V_BUF_SHIFT)) & ISI_CHNL_STS_PANIC_V_BUF_MASK)

#define ISI_CHNL_STS_AXI_RD_ERR_MASK             (0x2000000U)
#define ISI_CHNL_STS_AXI_RD_ERR_SHIFT            (25U)
/*! AXI_RD_ERR - AXI Bus Read Error Interrupt Flag
 *  0b0..No error
 *  0b1..Error occurred
 */
#define ISI_CHNL_STS_AXI_RD_ERR(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_RD_ERR_SHIFT)) & ISI_CHNL_STS_AXI_RD_ERR_MASK)

#define ISI_CHNL_STS_AXI_WR_ERR_Y_MASK           (0x4000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_Y_SHIFT          (26U)
/*! AXI_WR_ERR_Y - AXI Bus Write Error Interrupt Flag for Y/RGB Data Buffer
 *  0b0..No error
 *  0b1..Error occurred
 */
#define ISI_CHNL_STS_AXI_WR_ERR_Y(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_Y_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_Y_MASK)

#define ISI_CHNL_STS_AXI_WR_ERR_U_MASK           (0x8000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_U_SHIFT          (27U)
/*! AXI_WR_ERR_U - AXI Bus Write Error Interrupt Flag for U Data Buffer
 *  0b0..No error
 *  0b1..Error occurred
 */
#define ISI_CHNL_STS_AXI_WR_ERR_U(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_U_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_U_MASK)

#define ISI_CHNL_STS_AXI_WR_ERR_V_MASK           (0x10000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_V_SHIFT          (28U)
/*! AXI_WR_ERR_V - AXI Bus Write Error Interrupt Flag for V Data Buffer
 *  0b0..No error
 *  0b1..Error occurred
 */
#define ISI_CHNL_STS_AXI_WR_ERR_V(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_V_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_V_MASK)

#define ISI_CHNL_STS_FRM_STRD_MASK               (0x20000000U)
#define ISI_CHNL_STS_FRM_STRD_SHIFT              (29U)
/*! FRM_STRD - Frame Stored Successfully Interrupt Flag
 *  0b0..Not received or in progress
 *  0b1..Received and stored
 */
#define ISI_CHNL_STS_FRM_STRD(x)                 (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_FRM_STRD_SHIFT)) & ISI_CHNL_STS_FRM_STRD_MASK)

#define ISI_CHNL_STS_LINE_STRD_MASK              (0x40000000U)
#define ISI_CHNL_STS_LINE_STRD_SHIFT             (30U)
/*! LINE_STRD - Line Received and Stored Interrupt Flag
 *  0b0..Not received
 *  0b1..Received and stored
 */
#define ISI_CHNL_STS_LINE_STRD(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_LINE_STRD_SHIFT)) & ISI_CHNL_STS_LINE_STRD_MASK)

#define ISI_CHNL_STS_MEM_RD_DONE_MASK            (0x80000000U)
#define ISI_CHNL_STS_MEM_RD_DONE_SHIFT           (31U)
/*! MEM_RD_DONE - Memory Read Complete Interrupt Flag
 *  0b0..Not complete or not started
 *  0b1..Completed
 */
#define ISI_CHNL_STS_MEM_RD_DONE(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_MEM_RD_DONE_SHIFT)) & ISI_CHNL_STS_MEM_RD_DONE_MASK)
/*! @} */

/*! @name CHNL_SCALE_FACTOR - Channel Scale Factor */
/*! @{ */

#define ISI_CHNL_SCALE_FACTOR_X_SCALE_MASK       (0x3FFFU)
#define ISI_CHNL_SCALE_FACTOR_X_SCALE_SHIFT      (0U)
/*! X_SCALE - Horizontal Scaling Factor */
#define ISI_CHNL_SCALE_FACTOR_X_SCALE(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_X_SCALE_SHIFT)) & ISI_CHNL_SCALE_FACTOR_X_SCALE_MASK)

#define ISI_CHNL_SCALE_FACTOR_Y_SCALE_MASK       (0x3FFF0000U)
#define ISI_CHNL_SCALE_FACTOR_Y_SCALE_SHIFT      (16U)
/*! Y_SCALE - Vertical Scaling Factor */
#define ISI_CHNL_SCALE_FACTOR_Y_SCALE(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_Y_SCALE_SHIFT)) & ISI_CHNL_SCALE_FACTOR_Y_SCALE_MASK)
/*! @} */

/*! @name CHNL_SCALE_OFFSET - Channel Scale Offset */
/*! @{ */

#define ISI_CHNL_SCALE_OFFSET_X_OFFSET_MASK      (0xFFFU)
#define ISI_CHNL_SCALE_OFFSET_X_OFFSET_SHIFT     (0U)
/*! X_OFFSET - Horizontal Scaling Offset */
#define ISI_CHNL_SCALE_OFFSET_X_OFFSET(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_X_OFFSET_SHIFT)) & ISI_CHNL_SCALE_OFFSET_X_OFFSET_MASK)

#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET_MASK      (0xFFF0000U)
#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET_SHIFT     (16U)
/*! Y_OFFSET - Vertical Scaling Offset */
#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_Y_OFFSET_SHIFT)) & ISI_CHNL_SCALE_OFFSET_Y_OFFSET_MASK)
/*! @} */

/*! @name CHNL_CROP_ULC - Channel Crop Upper Left Corner Coordinate */
/*! @{ */

#define ISI_CHNL_CROP_ULC_Y_MASK                 (0xFFFU)
#define ISI_CHNL_CROP_ULC_Y_SHIFT                (0U)
/*! Y - Upper Left Y-Coordinate */
#define ISI_CHNL_CROP_ULC_Y(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_Y_SHIFT)) & ISI_CHNL_CROP_ULC_Y_MASK)

#define ISI_CHNL_CROP_ULC_X_MASK                 (0xFFF0000U)
#define ISI_CHNL_CROP_ULC_X_SHIFT                (16U)
/*! X - Upper Left X-Coordinate */
#define ISI_CHNL_CROP_ULC_X(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_X_SHIFT)) & ISI_CHNL_CROP_ULC_X_MASK)
/*! @} */

/*! @name CHNL_CROP_LRC - Channel Crop Lower Right Corner Coordinate */
/*! @{ */

#define ISI_CHNL_CROP_LRC_Y_MASK                 (0xFFFU)
#define ISI_CHNL_CROP_LRC_Y_SHIFT                (0U)
/*! Y - Lower Right Y-Coordinate */
#define ISI_CHNL_CROP_LRC_Y(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_Y_SHIFT)) & ISI_CHNL_CROP_LRC_Y_MASK)

#define ISI_CHNL_CROP_LRC_X_MASK                 (0xFFF0000U)
#define ISI_CHNL_CROP_LRC_X_SHIFT                (16U)
/*! X - Lower Right X-Coordinate */
#define ISI_CHNL_CROP_LRC_X(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_X_SHIFT)) & ISI_CHNL_CROP_LRC_X_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF0 - Channel Color Space Conversion Coefficient 0 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF0_A1_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF0_A1_SHIFT             (0U)
/*! A1 - CSC Coefficient A1 Value */
#define ISI_CHNL_CSC_COEFF0_A1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_A1_SHIFT)) & ISI_CHNL_CSC_COEFF0_A1_MASK)

#define ISI_CHNL_CSC_COEFF0_A2_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF0_A2_SHIFT             (16U)
/*! A2 - CSC Coefficient A2 Value */
#define ISI_CHNL_CSC_COEFF0_A2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_A2_SHIFT)) & ISI_CHNL_CSC_COEFF0_A2_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF1 - Channel Color Space Conversion Coefficient 1 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF1_A3_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF1_A3_SHIFT             (0U)
/*! A3 - CSC Coefficient A3 Value */
#define ISI_CHNL_CSC_COEFF1_A3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_A3_SHIFT)) & ISI_CHNL_CSC_COEFF1_A3_MASK)

#define ISI_CHNL_CSC_COEFF1_B1_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF1_B1_SHIFT             (16U)
/*! B1 - CSC Coefficient B1 Value */
#define ISI_CHNL_CSC_COEFF1_B1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_B1_SHIFT)) & ISI_CHNL_CSC_COEFF1_B1_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF2 - Channel Color Space Conversion Coefficient 2 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF2_B2_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF2_B2_SHIFT             (0U)
/*! B2 - CSC Coefficient B2 Value */
#define ISI_CHNL_CSC_COEFF2_B2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_B2_SHIFT)) & ISI_CHNL_CSC_COEFF2_B2_MASK)

#define ISI_CHNL_CSC_COEFF2_B3_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF2_B3_SHIFT             (16U)
/*! B3 - CSC Coefficient B3 Value */
#define ISI_CHNL_CSC_COEFF2_B3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_B3_SHIFT)) & ISI_CHNL_CSC_COEFF2_B3_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF3 - Channel Color Space Conversion Coefficient 3 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF3_C1_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF3_C1_SHIFT             (0U)
/*! C1 - CSC Coefficient C1 Value */
#define ISI_CHNL_CSC_COEFF3_C1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_C1_SHIFT)) & ISI_CHNL_CSC_COEFF3_C1_MASK)

#define ISI_CHNL_CSC_COEFF3_C2_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF3_C2_SHIFT             (16U)
/*! C2 - CSC Coefficient C2 Value */
#define ISI_CHNL_CSC_COEFF3_C2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_C2_SHIFT)) & ISI_CHNL_CSC_COEFF3_C2_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF4 - Channel Color Space Conversion Coefficient 4 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF4_C3_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF4_C3_SHIFT             (0U)
/*! C3 - CSC Coefficient C3 Value */
#define ISI_CHNL_CSC_COEFF4_C3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_C3_SHIFT)) & ISI_CHNL_CSC_COEFF4_C3_MASK)

#define ISI_CHNL_CSC_COEFF4_D1_MASK              (0x1FF0000U)
#define ISI_CHNL_CSC_COEFF4_D1_SHIFT             (16U)
/*! D1 - CSC Coefficient D1 Value */
#define ISI_CHNL_CSC_COEFF4_D1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_D1_SHIFT)) & ISI_CHNL_CSC_COEFF4_D1_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF5 - Channel Color Space Conversion Coefficient 5 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF5_D2_MASK              (0x1FFU)
#define ISI_CHNL_CSC_COEFF5_D2_SHIFT             (0U)
/*! D2 - CSC Coefficient D2 Value */
#define ISI_CHNL_CSC_COEFF5_D2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_D2_SHIFT)) & ISI_CHNL_CSC_COEFF5_D2_MASK)

#define ISI_CHNL_CSC_COEFF5_D3_MASK              (0x1FF0000U)
#define ISI_CHNL_CSC_COEFF5_D3_SHIFT             (16U)
/*! D3 - CSC Coefficient D3 Value */
#define ISI_CHNL_CSC_COEFF5_D3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_D3_SHIFT)) & ISI_CHNL_CSC_COEFF5_D3_MASK)
/*! @} */

/*! @name CHNL_ROI_ALPHA - Channel Alpha Value for ROI 0..Channel Alpha Value for ROI 3 */
/*! @{ */

#define ISI_CHNL_ROI_ALPHA_ALPHA_EN_MASK         (0x10000U)
#define ISI_CHNL_ROI_ALPHA_ALPHA_EN_SHIFT        (16U)
/*! ALPHA_EN - Alpha Value Insertion Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ISI_CHNL_ROI_ALPHA_ALPHA_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_ALPHA_ALPHA_EN_MASK)

#define ISI_CHNL_ROI_ALPHA_ALPHA_MASK            (0xFF000000U)
#define ISI_CHNL_ROI_ALPHA_ALPHA_SHIFT           (24U)
/*! ALPHA - Alpha Value */
#define ISI_CHNL_ROI_ALPHA_ALPHA(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_ALPHA_ALPHA_MASK)
/*! @} */

/* The count of ISI_CHNL_ROI_ALPHA */
#define ISI_CHNL_ROI_ALPHA_COUNT                 (4U)

/*! @name CHNL_ROI_ULC - Channel Upper Left Coordinate for ROI 0..Channel Upper Left Coordinate for ROI 3 */
/*! @{ */

#define ISI_CHNL_ROI_ULC_Y_MASK                  (0xFFFU)
#define ISI_CHNL_ROI_ULC_Y_SHIFT                 (0U)
/*! Y - Upper Left Y-Coordinate */
#define ISI_CHNL_ROI_ULC_Y(x)                    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_ULC_Y_SHIFT)) & ISI_CHNL_ROI_ULC_Y_MASK)

#define ISI_CHNL_ROI_ULC_X_MASK                  (0xFFF0000U)
#define ISI_CHNL_ROI_ULC_X_SHIFT                 (16U)
/*! X - Upper Left X-Coordinate */
#define ISI_CHNL_ROI_ULC_X(x)                    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_ULC_X_SHIFT)) & ISI_CHNL_ROI_ULC_X_MASK)
/*! @} */

/* The count of ISI_CHNL_ROI_ULC */
#define ISI_CHNL_ROI_ULC_COUNT                   (4U)

/*! @name CHNL_ROI_LRC - Channel Lower Right Coordinate for ROI 0..Channel Lower Right Coordinate for ROI 3 */
/*! @{ */

#define ISI_CHNL_ROI_LRC_Y_MASK                  (0xFFFU)
#define ISI_CHNL_ROI_LRC_Y_SHIFT                 (0U)
/*! Y - Lower Right Y-Coordinate */
#define ISI_CHNL_ROI_LRC_Y(x)                    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_LRC_Y_SHIFT)) & ISI_CHNL_ROI_LRC_Y_MASK)

#define ISI_CHNL_ROI_LRC_X_MASK                  (0xFFF0000U)
#define ISI_CHNL_ROI_LRC_X_SHIFT                 (16U)
/*! X - Lower Right X-Coordinate */
#define ISI_CHNL_ROI_LRC_X(x)                    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_LRC_X_SHIFT)) & ISI_CHNL_ROI_LRC_X_MASK)
/*! @} */

/* The count of ISI_CHNL_ROI_LRC */
#define ISI_CHNL_ROI_LRC_COUNT                   (4U)

/*! @name CHNL_OUT_BUF1_ADDR_Y - Channel RGB or Luma (Y) Output Buffer 1 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_SHIFT      (0U)
/*! ADDR - Address for RGB or Y (Luma) */
#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF1_ADDR_U - Channel Chroma (U/Cb/UV/CbCr) Output Buffer 1 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_SHIFT      (0U)
/*! ADDR - Address for U/Cb/UV/CbCr */
#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF1_ADDR_V - Channel Chroma (V/Cr) Output Buffer 1 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_SHIFT      (0U)
/*! ADDR - Address for V or Cr */
#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF_PITCH - Channel Output Buffer Pitch */
/*! @{ */

#define ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_MASK   (0xFFFFU)
#define ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_SHIFT  (0U)
/*! LINE_PITCH - Output Buffer Line Pitch */
#define ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH(x)     (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_SHIFT)) & ISI_CHNL_OUT_BUF_PITCH_LINE_PITCH_MASK)
/*! @} */

/*! @name CHNL_IN_BUF_ADDR - Channel Input Buffer Address */
/*! @{ */

#define ISI_CHNL_IN_BUF_ADDR_ADDR_MASK           (0xFFFFFFFFU)
#define ISI_CHNL_IN_BUF_ADDR_ADDR_SHIFT          (0U)
/*! ADDR - Starting Address */
#define ISI_CHNL_IN_BUF_ADDR_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IN_BUF_ADDR_ADDR_SHIFT)) & ISI_CHNL_IN_BUF_ADDR_ADDR_MASK)
/*! @} */

/*! @name CHNL_IN_BUF_PITCH - Channel Input Buffer Pitch */
/*! @{ */

#define ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_MASK    (0xFFFFU)
#define ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_SHIFT   (0U)
/*! LINE_PITCH - Line Pitch */
#define ISI_CHNL_IN_BUF_PITCH_LINE_PITCH(x)      (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_SHIFT)) & ISI_CHNL_IN_BUF_PITCH_LINE_PITCH_MASK)

#define ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_MASK     (0xFFFF0000U)
#define ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_SHIFT    (16U)
/*! FRM_PITCH - Frame Pitch */
#define ISI_CHNL_IN_BUF_PITCH_FRM_PITCH(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_SHIFT)) & ISI_CHNL_IN_BUF_PITCH_FRM_PITCH_MASK)
/*! @} */

/*! @name CHNL_MEM_RD_CTRL - Channel Memory Read Control */
/*! @{ */

#define ISI_CHNL_MEM_RD_CTRL_READ_MEM_MASK       (0x1U)
#define ISI_CHNL_MEM_RD_CTRL_READ_MEM_SHIFT      (0U)
/*! READ_MEM - Initiate Read from Memory
 *  0b0..No reads
 *  0b1..Reads initiated
 */
#define ISI_CHNL_MEM_RD_CTRL_READ_MEM(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_READ_MEM_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_READ_MEM_MASK)

#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_MASK       (0xF0000000U)
#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_SHIFT      (28U)
/*! IMG_TYPE - Input Image Format */
#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF2_ADDR_Y - Channel RGB or Luma (Y) Output Buffer 2 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_SHIFT      (0U)
/*! ADDR - Starting Address for RGB or Y */
#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF2_ADDR_U - Channel Chroma (U/Cb/UV/CbCr) Output Buffer 2 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_SHIFT      (0U)
/*! ADDR - Starting Address for U/Cb or 2-plane UV/CbCr */
#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF2_ADDR_V - Channel Chroma (V/Cr) Output Buffer 2 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_SHIFT      (0U)
/*! ADDR - Starting Address for V or Cr */
#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_MASK)
/*! @} */

/*! @name CHNL_SCL_IMG_CFG - Channel Scaled Image Configuration */
/*! @{ */

#define ISI_CHNL_SCL_IMG_CFG_WIDTH_MASK          (0x1FFFU)
#define ISI_CHNL_SCL_IMG_CFG_WIDTH_SHIFT         (0U)
/*! WIDTH - Scaled Image Width (Pixels) */
#define ISI_CHNL_SCL_IMG_CFG_WIDTH(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_WIDTH_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_WIDTH_MASK)

#define ISI_CHNL_SCL_IMG_CFG_HEIGHT_MASK         (0x1FFF0000U)
#define ISI_CHNL_SCL_IMG_CFG_HEIGHT_SHIFT        (16U)
/*! HEIGHT - Scaled Image Height (Lines) */
#define ISI_CHNL_SCL_IMG_CFG_HEIGHT(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_HEIGHT_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_HEIGHT_MASK)
/*! @} */

/*! @name CHNL_FLOW_CTRL - Channel Flow Control */
/*! @{ */

#define ISI_CHNL_FLOW_CTRL_FC_DENOM_MASK         (0xFFU)
#define ISI_CHNL_FLOW_CTRL_FC_DENOM_SHIFT        (0U)
/*! FC_DENOM - Denominator Value of Fraction of Usable Bandwidth
 *  0b00000000..Invalid value (flow control disabled)
 */
#define ISI_CHNL_FLOW_CTRL_FC_DENOM(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_FLOW_CTRL_FC_DENOM_SHIFT)) & ISI_CHNL_FLOW_CTRL_FC_DENOM_MASK)

#define ISI_CHNL_FLOW_CTRL_FC_NUMER_MASK         (0xFF0000U)
#define ISI_CHNL_FLOW_CTRL_FC_NUMER_SHIFT        (16U)
/*! FC_NUMER - Numerator Value of Fraction of Usable Bandwidth
 *  0b00000000..Invalid value (flow control disabled)
 */
#define ISI_CHNL_FLOW_CTRL_FC_NUMER(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_FLOW_CTRL_FC_NUMER_SHIFT)) & ISI_CHNL_FLOW_CTRL_FC_NUMER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ISI_Register_Masks */


/*!
 * @}
 */ /* end of group ISI_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ISI_H_ */

