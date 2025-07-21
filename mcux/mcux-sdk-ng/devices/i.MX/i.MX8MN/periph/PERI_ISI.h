/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ISI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ISI
 *
 * CMSIS Peripheral Access Layer for ISI
 */

#if !defined(PERI_ISI_H_)
#define PERI_ISI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- ISI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISI_Peripheral_Access_Layer ISI Peripheral Access Layer
 * @{
 */

/** ISI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CHNL_CTRL;                         /**< Channel Control Register, offset: 0x0 */
  __IO uint32_t CHNL_IMG_CTRL;                     /**< Channel Image Control Register, offset: 0x4 */
  __IO uint32_t CHNL_OUT_BUF_CTRL;                 /**< Channel Output Buffer Control Register, offset: 0x8 */
  __IO uint32_t CHNL_IMG_CFG;                      /**< Channel Image Configuration, offset: 0xC */
  __IO uint32_t CHNL_IER;                          /**< Channel Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t CHNL_STS;                          /**< Channel Status Register, offset: 0x14 */
  __IO uint32_t CHNL_SCALE_FACTOR;                 /**< Channel Scale Factor Register, offset: 0x18 */
  __IO uint32_t CHNL_SCALE_OFFSET;                 /**< Channel Scale Offset Register, offset: 0x1C */
  __IO uint32_t CHNL_CROP_ULC;                     /**< Channel Crop Upper Left Corner Coordinate Register, offset: 0x20 */
  __IO uint32_t CHNL_CROP_LRC;                     /**< Channel Crop Lower Right Corner Coordinate Register, offset: 0x24 */
  __IO uint32_t CHNL_CSC_COEFF0;                   /**< Channel Color Space Conversion Coefficient Register 0, offset: 0x28 */
  __IO uint32_t CHNL_CSC_COEFF1;                   /**< Channel Color Space Conversion Coefficient Register 1, offset: 0x2C */
  __IO uint32_t CHNL_CSC_COEFF2;                   /**< Channel Color Space Conversion Coefficient Register 2, offset: 0x30 */
  __IO uint32_t CHNL_CSC_COEFF3;                   /**< Channel Color Space Conversion Coefficient Register 3, offset: 0x34 */
  __IO uint32_t CHNL_CSC_COEFF4;                   /**< Channel Color Space Conversion Coefficient Register 4, offset: 0x38 */
  __IO uint32_t CHNL_CSC_COEFF5;                   /**< Channel Color Space Conversion Coefficient Register 5, offset: 0x3C */
  __IO uint32_t CHNL_ROI_0_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 0, offset: 0x40 */
  __IO uint32_t CHNL_ROI_0_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 0, offset: 0x44 */
  __IO uint32_t CHNL_ROI_0_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 0, offset: 0x48 */
  __IO uint32_t CHNL_ROI_1_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 1, offset: 0x4C */
  __IO uint32_t CHNL_ROI_1_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 1, offset: 0x50 */
  __IO uint32_t CHNL_ROI_1_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 1, offset: 0x54 */
  __IO uint32_t CHNL_ROI_2_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 2, offset: 0x58 */
  __IO uint32_t CHNL_ROI_2_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 2, offset: 0x5C */
  __IO uint32_t CHNL_ROI_2_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 2, offset: 0x60 */
  __IO uint32_t CHNL_ROI_3_ALPHA;                  /**< Channel Alpha Value Register for Region of Interest 3, offset: 0x64 */
  __IO uint32_t CHNL_ROI_3_ULC;                    /**< Channel Upper Left Coordinate Register for Region of Interest 3, offset: 0x68 */
  __IO uint32_t CHNL_ROI_3_LRC;                    /**< Channel Lower Right Coordinate Register for Region of Interest 3, offset: 0x6C */
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
  __IO uint32_t CHNL_FLOW_CTRL;                    /**< Channel Flow Control Register, offset: 0x9C */
} ISI_Type;

/* ----------------------------------------------------------------------------
   -- ISI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ISI_Register_Masks ISI Register Masks
 * @{
 */

/*! @name CHNL_CTRL - Channel Control Register */
/*! @{ */

#define ISI_CHNL_CTRL_SRC_TYPE_MASK              (0x10U)
#define ISI_CHNL_CTRL_SRC_TYPE_SHIFT             (4U)
/*! SRC_TYPE - Type of selected input image source
 *  0b0..Image input source is Pixel Link
 *  0b1..Image input source is Memory
 */
#define ISI_CHNL_CTRL_SRC_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SRC_TYPE_SHIFT)) & ISI_CHNL_CTRL_SRC_TYPE_MASK)

#define ISI_CHNL_CTRL_VC_ID_MASK                 (0xC0U)
#define ISI_CHNL_CTRL_VC_ID_SHIFT                (6U)
/*! VC_ID - Virtual channel ID
 *  0b00..Virtual Channel 0 selected or no virtual channel used
 *  0b01..Virtual Channel 1 selected
 *  0b10..Virtual Channel 2 selected
 *  0b11..Virtual Channel 3 selected
 */
#define ISI_CHNL_CTRL_VC_ID(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_VC_ID_SHIFT)) & ISI_CHNL_CTRL_VC_ID_MASK)

#define ISI_CHNL_CTRL_SW_RST_MASK                (0x1000000U)
#define ISI_CHNL_CTRL_SW_RST_SHIFT               (24U)
/*! SW_RST - Software reset bit
 *  0b0..No Reset
 *  0b1..Channel pipeline is under software reset
 */
#define ISI_CHNL_CTRL_SW_RST(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_SW_RST_SHIFT)) & ISI_CHNL_CTRL_SW_RST_MASK)

#define ISI_CHNL_CTRL_CHAIN_BUF_MASK             (0x6000000U)
#define ISI_CHNL_CTRL_CHAIN_BUF_SHIFT            (25U)
/*! CHAIN_BUF - Chain line buffer control
 *  0b00..No line buffers chained (supports 2048 or less horizontal resolution)
 *  0b01..2 line buffers chained (supports 4096 horizontal resolution). Line buffers of channels 'n' and 'n+1' are chained.
 *  0b10..4 line buffers chained (supports 8192 horizontal resolution). Line buffers of channels 'n', 'n+1', 'n+2' and 'n+3' are chained.
 *  0b11..Reserved for future use
 */
#define ISI_CHNL_CTRL_CHAIN_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHAIN_BUF_SHIFT)) & ISI_CHNL_CTRL_CHAIN_BUF_MASK)

#define ISI_CHNL_CTRL_CHNL_BYPASS_MASK           (0x20000000U)
#define ISI_CHNL_CTRL_CHNL_BYPASS_SHIFT          (29U)
/*! CHNL_BYPASS - Channel bypass enable
 *  0b0..Channel is not bypassed
 *  0b1..Channel is bypassed
 */
#define ISI_CHNL_CTRL_CHNL_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHNL_BYPASS_SHIFT)) & ISI_CHNL_CTRL_CHNL_BYPASS_MASK)

#define ISI_CHNL_CTRL_CLK_EN_MASK                (0x40000000U)
#define ISI_CHNL_CTRL_CLK_EN_SHIFT               (30U)
/*! CLK_EN - Channel clock enable
 *  0b0..Channel processing clock is disabled
 *  0b1..Channel processing clock is enabled
 */
#define ISI_CHNL_CTRL_CLK_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CLK_EN_SHIFT)) & ISI_CHNL_CTRL_CLK_EN_MASK)

#define ISI_CHNL_CTRL_CHNL_EN_MASK               (0x80000000U)
#define ISI_CHNL_CTRL_CHNL_EN_SHIFT              (31U)
/*! CHNL_EN - Enable channel processing
 *  0b0..Processing channel is disabled
 *  0b1..Processing channel is enabled
 */
#define ISI_CHNL_CTRL_CHNL_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CTRL_CHNL_EN_SHIFT)) & ISI_CHNL_CTRL_CHNL_EN_MASK)
/*! @} */

/*! @name CHNL_IMG_CTRL - Channel Image Control Register */
/*! @{ */

#define ISI_CHNL_IMG_CTRL_CSC_BYP_MASK           (0x1U)
#define ISI_CHNL_IMG_CTRL_CSC_BYP_SHIFT          (0U)
/*! CSC_BYP - Color Space Conversion bypass control
 *  0b0..CSC is operational
 *  0b1..CSC is bypassed
 */
#define ISI_CHNL_IMG_CTRL_CSC_BYP(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CSC_BYP_SHIFT)) & ISI_CHNL_IMG_CTRL_CSC_BYP_MASK)

#define ISI_CHNL_IMG_CTRL_CSC_MODE_MASK          (0x6U)
#define ISI_CHNL_IMG_CTRL_CSC_MODE_SHIFT         (1U)
/*! CSC_MODE - Color Space Conversion operating mode
 *  0b00..Convert from YUV to RGB
 *  0b01..Convert from YCbCr to RGB
 *  0b10..Convert from RGB to YUV
 *  0b11..Convert from RGB to YCbCr
 */
#define ISI_CHNL_IMG_CTRL_CSC_MODE(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CSC_MODE_SHIFT)) & ISI_CHNL_IMG_CTRL_CSC_MODE_MASK)

#define ISI_CHNL_IMG_CTRL_YCBCR_MODE_MASK        (0x8U)
#define ISI_CHNL_IMG_CTRL_YCBCR_MODE_SHIFT       (3U)
/*! YCBCR_MODE - YCbCr Mode
 *  0b0..YCbCr mode is disabled
 *  0b1..YCbCr mode is enabled
 */
#define ISI_CHNL_IMG_CTRL_YCBCR_MODE(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_YCBCR_MODE_SHIFT)) & ISI_CHNL_IMG_CTRL_YCBCR_MODE_MASK)

#define ISI_CHNL_IMG_CTRL_RSVD2_MASK             (0x10U)
#define ISI_CHNL_IMG_CTRL_RSVD2_SHIFT            (4U)
/*! RSVD2 - Reserved field. Reads only zeros */
#define ISI_CHNL_IMG_CTRL_RSVD2(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_RSVD2_SHIFT)) & ISI_CHNL_IMG_CTRL_RSVD2_MASK)

#define ISI_CHNL_IMG_CTRL_HFLIP_EN_MASK          (0x20U)
#define ISI_CHNL_IMG_CTRL_HFLIP_EN_SHIFT         (5U)
/*! HFLIP_EN - Horizontal flip control
 *  0b0..Horizantal image flip disabled
 *  0b1..Horizontal image flip enabled
 */
#define ISI_CHNL_IMG_CTRL_HFLIP_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_HFLIP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_HFLIP_EN_MASK)

#define ISI_CHNL_IMG_CTRL_VFLIP_EN_MASK          (0x40U)
#define ISI_CHNL_IMG_CTRL_VFLIP_EN_SHIFT         (6U)
/*! VFLIP_EN - Veritical flip control
 *  0b0..Vertical image flip disabled
 *  0b1..Vertical image flip enabled
 */
#define ISI_CHNL_IMG_CTRL_VFLIP_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_VFLIP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_VFLIP_EN_MASK)

#define ISI_CHNL_IMG_CTRL_CROP_EN_MASK           (0x80U)
#define ISI_CHNL_IMG_CTRL_CROP_EN_SHIFT          (7U)
/*! CROP_EN - Output image cropping enable
 *  0b0..Image cropping is disabled
 *  0b1..Image cropping is enabled
 */
#define ISI_CHNL_IMG_CTRL_CROP_EN(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_CROP_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_CROP_EN_MASK)

#define ISI_CHNL_IMG_CTRL_DEC_Y_MASK             (0x300U)
#define ISI_CHNL_IMG_CTRL_DEC_Y_SHIFT            (8U)
/*! DEC_Y - Vertical pre-decimation control
 *  0b00..Pre-decimation filter is disabled. Bilinear scaling filter is still operational.
 *  0b01..Decimate by 2
 *  0b10..Decimate by 4
 *  0b11..Decimate by 8
 */
#define ISI_CHNL_IMG_CTRL_DEC_Y(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEC_Y_SHIFT)) & ISI_CHNL_IMG_CTRL_DEC_Y_MASK)

#define ISI_CHNL_IMG_CTRL_DEC_X_MASK             (0xC00U)
#define ISI_CHNL_IMG_CTRL_DEC_X_SHIFT            (10U)
/*! DEC_X - Horizontal pre-decimation control
 *  0b00..Pre-decimation filter is disabled. Bilinear scaling filter is still operational.
 *  0b01..Decimate by 2
 *  0b10..Decimate by 4
 *  0b11..Decimate by 8
 */
#define ISI_CHNL_IMG_CTRL_DEC_X(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEC_X_SHIFT)) & ISI_CHNL_IMG_CTRL_DEC_X_MASK)

#define ISI_CHNL_IMG_CTRL_DEINT_MASK             (0x7000U)
#define ISI_CHNL_IMG_CTRL_DEINT_SHIFT            (12U)
/*! DEINT - De-interlace control
 *  0b000, 0b001..No de-interlacing done
 *  0b010..Weave de-interlacing (Odd, Even) method used
 *  0b011..Weave de-interlacing (Even, Odd) method used
 *  0b100..Blending or linear interpolation (Odd + Even) de-interlacing method used
 *  0b101..Blending or linear interpolation (Even + Odd) de-interlacing method used
 *  0b110, 0b111..Line doubling de-interlacing method used. Both Odd and Even fields are doubled.
 */
#define ISI_CHNL_IMG_CTRL_DEINT(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_DEINT_SHIFT)) & ISI_CHNL_IMG_CTRL_DEINT_MASK)

#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_MASK      (0x8000U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_SHIFT     (15U)
/*! GBL_ALPHA_EN - Global alpha value insertion enable
 *  0b0..Global Alpha value insertion is disabled
 *  0b1..Global Alpha value insertion is enabled
 */
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_SHIFT)) & ISI_CHNL_IMG_CTRL_GBL_ALPHA_EN_MASK)

#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_MASK     (0xFF0000U)
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_SHIFT    (16U)
/*! GBL_ALPHA_VAL - Global alpha value
 *  0b00000000-0b11111111..Alpha value to be inserted with all RGB pixels
 */
#define ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_SHIFT)) & ISI_CHNL_IMG_CTRL_GBL_ALPHA_VAL_MASK)

#define ISI_CHNL_IMG_CTRL_FORMAT_MASK            (0x3F000000U)
#define ISI_CHNL_IMG_CTRL_FORMAT_SHIFT           (24U)
/*! FORMAT - Output image format
 *  0b000000..RGBA8888 - RGB format with alpha in LSB; 8-bits per component. 'A' indicates alpha value.
 *  0b000001..ABGR8888 - BGR format with alpha in MSB; 8-bits per component. 'A' indicates alpha value.
 *  0b000010..ARGB8888 - RGB format with alpha in MSB; 8-bits per component. 'A' indicates alpha value.
 *  0b000011..RGBX888 - RGB format with 8-bits per color component (unpacked and MSB-alinged in 32-bit DWORD). 'X' indicates the waste bits.
 *  0b000100..XBGR888 - BGR format with 8-bits per color component (unpacked and LSB aligned in 32-bit DWORD). 'X' indicates the waste bits.
 *  0b000101..XRGB888 - RGB format with 8-bits per color component (unpacked and LSB aligned in 32-bit DWORD). 'X' indicates the waste bits.
 *  0b000110..RGB888P - RGB format with 8-bits per color component (packed into 24-bits). No waste bits.
 *  0b000111..BGR888P - BGR format with 8-bits per color component (packed into 24-bits). No waste bits.
 *  0b001000..A2BGR10 - BGR format with 2-bits alpha in MSB; 10-bits per color component. 'A' indicates alpha value.
 *  0b001001..A2RGB10 - RGB format with 2-bits alpha in MSB; 10-bits per color component. 'A' indicates alpha value.
 *  0b001010..RGB565 - RGB format with 5-bits of R, B; 6-bits of G (packed into 16-bits WORD). No waste bits.
 *  0b001011..RAW8 - 8-bit RAW data packed into 32-bit DWORD
 *  0b001100..RAW10 - 10-bit RAW data packed into 16-bit WORD with 6 LSBs waste bits
 *  0b001101..RAW10P - 10-bit RAW data packed into 32-bit DWORD
 *  0b001110..RAW12 - 12-bit RAW data packed into 16-bit DWORD with 4 LSBs waste bits
 *  0b001111..RAW16 - 16-bit RAW data packed into 32-bit DWORD
 *  0b010000..YUV444_1P8P with 8-bits per color component; 1-plane, YUV interleaved packed bytes
 *  0b010001..YUV444_2P8P with 8-bits per color component; 2-plane, UV interleaved packed bytes
 *  0b010010..YUV444_3P8P with 8-bits per color component; 3-plane, non-interleaved packed bytes
 *  0b010011..YUV444_1P8 with 8-bits per color component; 1-plane YUV interleaved unpacked bytes (8 MSBs waste bits in 32-bit DWORD)
 *  0b010100..YUV444_1P10 with 10-bits per color component; 1-plane, YUV interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b010101..YUV444_2P10 with 10-bits per color component; 2-plane, UV interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b010110..YUV444_3P10 with 10-bits per color component; 3-plane, non-interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b010111..Reserved for future use
 *  0b011000..YUV444_1P10P with 10-bits per color component; 1-plane, YUV interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b011001..YUV444_2P10P with 10-bits per color component; 2-plane, UV interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b011010..YUV444_3P10P with 10-bits per color component; 3-plane, non-interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b011011..Reserved for future use
 *  0b011100..YUV444_1P12 with 12-bits per color component; 1-plane, YUV interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b011101..YUV444_2P12 with 12-bits per color component; 2-plane, UV interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b011110..YUV444_3P12 with 12-bits per color component; 3-plane, non-interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b011111..Reserved for future use
 *  0b100000..YUV422_1P8P with 8-bits per color component; 1-plane, YUV interleaved packed bytes
 *  0b100001..YUV422_2P8P with 8-bits per color component; 2-plane, UV interleaved packed bytes
 *  0b100010..YUV422_3P8P with 8-bits per color component; 3-plane, non-interleaved packed bytes
 *  0b100011..Reserved for future use
 *  0b100100..YUV422_1P10 with 10-bits per color component; 1-plane, YUV interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b100101..YUV422_2P10 with 10-bits per color component; 2-plane, UV interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b100110..YUV422_3P10 with 10-bits per color component; 3-plane, non-interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b100111..Reserved for future use
 *  0b101000..YUV422_1P10P with 10-bits per color component; 1-plane, YUV interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b101001..YUV422_2P10P with 10-bits per color component; 2-plane, UV interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b101010..YUV422_3P10P with 10-bits per color component; 3-plane, non-interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b101011..Reserved for future use
 *  0b101100..YUV422_1P12 with 12-bits per color component; 1-plane, YUV interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b101101..YUV422_2P12 with 12-bits per color component; 2-plane, UV interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b101110..YUV422_3P12 with 12-bits per color component; 3-plane, non-interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b101111..Reserved for future use
 *  0b110000..Reserved for future use
 *  0b110001..YUV420_2P8P with 8-bits per color component; 2-plane, UV interleaved packed bytes
 *  0b110010..YUV420_3P8P with 8-bits per color component; 3-plane, non-interleaved packed bytes
 *  0b110011..Reserved for future use
 *  0b110100..Reserved for future use
 *  0b110101..YUV420_2P10 with 10-bits per color component; 2-plane, UV interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b110110..YUV420_3P10 with 10-bits per color component; 3-plane, non-interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b110111..Reserved for future use
 *  0b111000..Reserved for future use
 *  0b111001..YUV420_2P10P with 10-bits per color component; 2-plane, UV interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b111010..YUV420_3P10P with 10-bits per color component; 3-plane, non-interleaved packed bytes (2 MSBs waste bits in 32-bit DWORD)
 *  0b111011..Reserved for future use
 *  0b111100..Reserved for future use
 *  0b111101..YUV420_2P12 with 12-bits per color component; 2-plane, UV interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b111110..YUV420_3P12 with 12-bits per color component; 3-plane, non-interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b111111..Reserved for future use
 */
#define ISI_CHNL_IMG_CTRL_FORMAT(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_FORMAT_SHIFT)) & ISI_CHNL_IMG_CTRL_FORMAT_MASK)

#define ISI_CHNL_IMG_CTRL_RSVD0_MASK             (0xC0000000U)
#define ISI_CHNL_IMG_CTRL_RSVD0_SHIFT            (30U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_IMG_CTRL_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CTRL_RSVD0_SHIFT)) & ISI_CHNL_IMG_CTRL_RSVD0_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF_CTRL - Channel Output Buffer Control Register */
/*! @{ */

#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_MASK (0xFU)
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_SHIFT (0U)
/*! PANIC_SET_THD_Y - Overflow panic set threshold value for Y/RGB output buffer
 *  0b0000..No panic alert will be asserted
 *  0b0001-0b1111..Panic will assert when buffer is n * 6.25% full, where n = 1 to 15
 */
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_Y_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_MASK (0xF00U)
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_SHIFT (8U)
/*! PANIC_SET_THD_U - Overflow panic set threshold value for U output buffer
 *  0b0000..No panic alert will be asserted
 *  0b0001-0b1111..Panic will assert when buffer is n * 6.25% full, where n = 1 to 15
 */
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_U_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_MASK (0x4000U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_SHIFT (14U)
/*! LOAD_BUF1_ADDR - Load Buffer 1 Address from CHNLOUT_BUF1_ADDR_* registers */
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF1_ADDR_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_MASK (0x8000U)
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_SHIFT (15U)
/*! LOAD_BUF2_ADDR - Load Buffer 2 Address from CHNLOUT_BUF2_ADDR_* registers */
#define ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_LOAD_BUF2_ADDR_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_MASK (0xF0000U)
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_SHIFT (16U)
/*! PANIC_SET_THD_V - Overflow panic set threshold value for V output buffer
 *  0b0000..No panic alert will be asserted
 *  0b0001-0b1111..Panic will assert when buffer is n * 6.25% full, where n = 1 to 15
 */
#define ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_PANIC_SET_THD_V_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_MASK (0x40000000U)
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_SHIFT (30U)
/*! MAX_WR_BEATS_UV - Maximum AXI write beats for U and V-buffers
 *  0b0..Maximum write beats per write request are 8 (i.e. 128 bytes)
 *  0b1..Maximum write beats per write request are 16 (i.e. 256 bytes)
 */
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV(x) (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_UV_MASK)

#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_MASK (0x80000000U)
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_SHIFT (31U)
/*! MAX_WR_BEATS_Y - Maximum AXI write beats for Y-buffer
 *  0b0..Maximum write beats per write request are 8 (i.e. 128 bytes)
 *  0b1..Maximum write beats per write request are 16 (i.e. 256 bytes)
 */
#define ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y(x)  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_SHIFT)) & ISI_CHNL_OUT_BUF_CTRL_MAX_WR_BEATS_Y_MASK)
/*! @} */

/*! @name CHNL_IMG_CFG - Channel Image Configuration */
/*! @{ */

#define ISI_CHNL_IMG_CFG_WIDTH_MASK              (0x1FFFU)
#define ISI_CHNL_IMG_CFG_WIDTH_SHIFT             (0U)
/*! WIDTH - Input image width (pixels) */
#define ISI_CHNL_IMG_CFG_WIDTH(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_WIDTH_SHIFT)) & ISI_CHNL_IMG_CFG_WIDTH_MASK)

#define ISI_CHNL_IMG_CFG_RSVD0_MASK              (0xE000U)
#define ISI_CHNL_IMG_CFG_RSVD0_SHIFT             (13U)
/*! RSVD0 - Reserved field. Reads only zeros. */
#define ISI_CHNL_IMG_CFG_RSVD0(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_RSVD0_SHIFT)) & ISI_CHNL_IMG_CFG_RSVD0_MASK)

#define ISI_CHNL_IMG_CFG_HEIGHT_MASK             (0x1FFF0000U)
#define ISI_CHNL_IMG_CFG_HEIGHT_SHIFT            (16U)
/*! HEIGHT - Input image height (lines) */
#define ISI_CHNL_IMG_CFG_HEIGHT(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_HEIGHT_SHIFT)) & ISI_CHNL_IMG_CFG_HEIGHT_MASK)

#define ISI_CHNL_IMG_CFG_RSVD1_MASK              (0xE0000000U)
#define ISI_CHNL_IMG_CFG_RSVD1_SHIFT             (29U)
/*! RSVD1 - Reserved field. Reads only zeros. */
#define ISI_CHNL_IMG_CFG_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IMG_CFG_RSVD1_SHIFT)) & ISI_CHNL_IMG_CFG_RSVD1_MASK)
/*! @} */

/*! @name CHNL_IER - Channel Interrupt Enable Register */
/*! @{ */

#define ISI_CHNL_IER_RSVD0_MASK                  (0xFFFFU)
#define ISI_CHNL_IER_RSVD0_SHIFT                 (0U)
/*! RSVD0 - Reserved field. Reads only zeros. */
#define ISI_CHNL_IER_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_RSVD0_SHIFT)) & ISI_CHNL_IER_RSVD0_MASK)

#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN_MASK      (0x10000U)
#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN_SHIFT     (16U)
/*! LATE_VSYNC_ERR_EN - VSYNC timing (Late) error interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_LATE_VSYNC_ERR_EN(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_LATE_VSYNC_ERR_EN_SHIFT)) & ISI_CHNL_IER_LATE_VSYNC_ERR_EN_MASK)

#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_MASK     (0x20000U)
#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_SHIFT    (17U)
/*! EARLY_VSYNC_ERR_EN - VSYNC timing (Early) error interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_EARLY_VSYNC_ERR_EN(x)       (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_SHIFT)) & ISI_CHNL_IER_EARLY_VSYNC_ERR_EN_MASK)

#define ISI_CHNL_IER_OFLW_Y_BUF_EN_MASK          (0x40000U)
#define ISI_CHNL_IER_OFLW_Y_BUF_EN_SHIFT         (18U)
/*! OFLW_Y_BUF_EN - Y output buffer overflow interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_OFLW_Y_BUF_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_Y_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_Y_BUF_EN_MASK)

#define ISI_CHNL_IER_PANIC_Y_BUF_EN_MASK         (0x80000U)
#define ISI_CHNL_IER_PANIC_Y_BUF_EN_SHIFT        (19U)
/*! PANIC_Y_BUF_EN - Y output buffer potential overflow panic interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_PANIC_Y_BUF_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_PANIC_Y_BUF_EN_SHIFT)) & ISI_CHNL_IER_PANIC_Y_BUF_EN_MASK)

#define ISI_CHNL_IER_OFLW_U_BUF_EN_MASK          (0x100000U)
#define ISI_CHNL_IER_OFLW_U_BUF_EN_SHIFT         (20U)
/*! OFLW_U_BUF_EN - U output buffer overflow interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_OFLW_U_BUF_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_U_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_U_BUF_EN_MASK)

#define ISI_CHNL_IER_PANIC_U_BUF_EN_MASK         (0x200000U)
#define ISI_CHNL_IER_PANIC_U_BUF_EN_SHIFT        (21U)
/*! PANIC_U_BUF_EN - U output buffer potential overflow panic interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_PANIC_U_BUF_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_PANIC_U_BUF_EN_SHIFT)) & ISI_CHNL_IER_PANIC_U_BUF_EN_MASK)

#define ISI_CHNL_IER_OFLW_V_BUF_EN_MASK          (0x400000U)
#define ISI_CHNL_IER_OFLW_V_BUF_EN_SHIFT         (22U)
/*! OFLW_V_BUF_EN - V output buffer overflow interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_OFLW_V_BUF_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_OFLW_V_BUF_EN_SHIFT)) & ISI_CHNL_IER_OFLW_V_BUF_EN_MASK)

#define ISI_CHNL_IER_PANIC_V_BUF_EN_MASK         (0x800000U)
#define ISI_CHNL_IER_PANIC_V_BUF_EN_SHIFT        (23U)
/*! PANIC_V_BUF_EN - V output buffer potential overflow panic interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_PANIC_V_BUF_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_PANIC_V_BUF_EN_SHIFT)) & ISI_CHNL_IER_PANIC_V_BUF_EN_MASK)

#define ISI_CHNL_IER_AXI_RD_ERR_EN_MASK          (0x2000000U)
#define ISI_CHNL_IER_AXI_RD_ERR_EN_SHIFT         (25U)
/*! AXI_RD_ERR_EN - AXI bus read error interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_AXI_RD_ERR_EN(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_RD_ERR_EN_SHIFT)) & ISI_CHNL_IER_AXI_RD_ERR_EN_MASK)

#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN_MASK        (0x4000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN_SHIFT       (26U)
/*! AXI_WR_ERR_Y_EN - AXI bus read error interrupt enable bit for Y/RGB data buffer
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_AXI_WR_ERR_Y_EN(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_Y_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_Y_EN_MASK)

#define ISI_CHNL_IER_AXI_WR_ERR_U_EN_MASK        (0x8000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_U_EN_SHIFT       (27U)
/*! AXI_WR_ERR_U_EN - AXI bus read error interrupt enable bit for U data buffer
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_AXI_WR_ERR_U_EN(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_U_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_U_EN_MASK)

#define ISI_CHNL_IER_AXI_WR_ERR_V_EN_MASK        (0x10000000U)
#define ISI_CHNL_IER_AXI_WR_ERR_V_EN_SHIFT       (28U)
/*! AXI_WR_ERR_V_EN - AXI bus read error interrupt enable bit for V data buffer
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_AXI_WR_ERR_V_EN(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_AXI_WR_ERR_V_EN_SHIFT)) & ISI_CHNL_IER_AXI_WR_ERR_V_EN_MASK)

#define ISI_CHNL_IER_FRM_RCVD_EN_MASK            (0x20000000U)
#define ISI_CHNL_IER_FRM_RCVD_EN_SHIFT           (29U)
/*! FRM_RCVD_EN - Frame received interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_FRM_RCVD_EN(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_FRM_RCVD_EN_SHIFT)) & ISI_CHNL_IER_FRM_RCVD_EN_MASK)

#define ISI_CHNL_IER_LINE_RCVD_EN_MASK           (0x40000000U)
#define ISI_CHNL_IER_LINE_RCVD_EN_SHIFT          (30U)
/*! LINE_RCVD_EN - Line received interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_LINE_RCVD_EN(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_LINE_RCVD_EN_SHIFT)) & ISI_CHNL_IER_LINE_RCVD_EN_MASK)

#define ISI_CHNL_IER_MEM_RD_DONE_EN_MASK         (0x80000000U)
#define ISI_CHNL_IER_MEM_RD_DONE_EN_SHIFT        (31U)
/*! MEM_RD_DONE_EN - Memory read complete interrupt enable bit
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define ISI_CHNL_IER_MEM_RD_DONE_EN(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_IER_MEM_RD_DONE_EN_SHIFT)) & ISI_CHNL_IER_MEM_RD_DONE_EN_MASK)
/*! @} */

/*! @name CHNL_STS - Channel Status Register */
/*! @{ */

#define ISI_CHNL_STS_BUF1_ACTIVE_MASK            (0x100U)
#define ISI_CHNL_STS_BUF1_ACTIVE_SHIFT           (8U)
/*! BUF1_ACTIVE - Current frame being stored in Buffer 1 Address
 *  0b0..Buffer 1 Address inactive
 *  0b1..Buffer 1 Address in use
 */
#define ISI_CHNL_STS_BUF1_ACTIVE(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_BUF1_ACTIVE_SHIFT)) & ISI_CHNL_STS_BUF1_ACTIVE_MASK)

#define ISI_CHNL_STS_BUF2_ACTIVE_MASK            (0x200U)
#define ISI_CHNL_STS_BUF2_ACTIVE_SHIFT           (9U)
/*! BUF2_ACTIVE - Current frame being stored in Buffer 2 Address
 *  0b0..Buffer 2 Address inactive
 *  0b1..Buffer 2 Address in use
 */
#define ISI_CHNL_STS_BUF2_ACTIVE(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_BUF2_ACTIVE_SHIFT)) & ISI_CHNL_STS_BUF2_ACTIVE_MASK)

#define ISI_CHNL_STS_MEM_RD_OFLOW_MASK           (0x400U)
#define ISI_CHNL_STS_MEM_RD_OFLOW_SHIFT          (10U)
/*! MEM_RD_OFLOW - Memory read FIFO overflow error status
 *  0b0..No overflow occurred during memory read
 *  0b1..FIFO overflow occurred during memory read
 */
#define ISI_CHNL_STS_MEM_RD_OFLOW(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_MEM_RD_OFLOW_SHIFT)) & ISI_CHNL_STS_MEM_RD_OFLOW_MASK)

#define ISI_CHNL_STS_RSVD1_MASK                  (0xF800U)
#define ISI_CHNL_STS_RSVD1_SHIFT                 (11U)
/*! RSVD1 - Reserved field. Reads only zeros. */
#define ISI_CHNL_STS_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_RSVD1_SHIFT)) & ISI_CHNL_STS_RSVD1_MASK)

#define ISI_CHNL_STS_LATE_VSYNC_ERR_MASK         (0x10000U)
#define ISI_CHNL_STS_LATE_VSYNC_ERR_SHIFT        (16U)
/*! LATE_VSYNC_ERR - VSYNC timing (Late) error interrupt flag
 *  0b0..No error
 *  0b1..VSYNC detected later than expected
 */
#define ISI_CHNL_STS_LATE_VSYNC_ERR(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_LATE_VSYNC_ERR_SHIFT)) & ISI_CHNL_STS_LATE_VSYNC_ERR_MASK)

#define ISI_CHNL_STS_EARLY_VSYNC_ERR_MASK        (0x20000U)
#define ISI_CHNL_STS_EARLY_VSYNC_ERR_SHIFT       (17U)
/*! EARLY_VSYNC_ERR - VSYNC timing (Early) error interrupt flag
 *  0b0..No error
 *  0b1..VSYNC detected earlier than expected
 */
#define ISI_CHNL_STS_EARLY_VSYNC_ERR(x)          (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_EARLY_VSYNC_ERR_SHIFT)) & ISI_CHNL_STS_EARLY_VSYNC_ERR_MASK)

#define ISI_CHNL_STS_OFLW_Y_BUF_MASK             (0x40000U)
#define ISI_CHNL_STS_OFLW_Y_BUF_SHIFT            (18U)
/*! OFLW_Y_BUF - Overflow in Y/RGB output buffer interrupt flag
 *  0b0..No overflow
 *  0b1..Overflow has occured in the channel
 */
#define ISI_CHNL_STS_OFLW_Y_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_Y_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_Y_BUF_MASK)

#define ISI_CHNL_STS_PANIC_Y_BUF_MASK            (0x80000U)
#define ISI_CHNL_STS_PANIC_Y_BUF_SHIFT           (19U)
/*! PANIC_Y_BUF - Y/RGB output buffer potential overflow panic alert interrupt flag
 *  0b0..Buffer has not crossed the panic threshold limit
 *  0b1..Panic threshold limit crossed. Software must take action.
 */
#define ISI_CHNL_STS_PANIC_Y_BUF(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_PANIC_Y_BUF_SHIFT)) & ISI_CHNL_STS_PANIC_Y_BUF_MASK)

#define ISI_CHNL_STS_OFLW_U_BUF_MASK             (0x100000U)
#define ISI_CHNL_STS_OFLW_U_BUF_SHIFT            (20U)
/*! OFLW_U_BUF - Overflow in U output buffer interrupt flag
 *  0b0..No overflow
 *  0b1..Overflow has occured in the channel
 */
#define ISI_CHNL_STS_OFLW_U_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_U_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_U_BUF_MASK)

#define ISI_CHNL_STS_PANIC_U_BUF_MASK            (0x200000U)
#define ISI_CHNL_STS_PANIC_U_BUF_SHIFT           (21U)
/*! PANIC_U_BUF - U output buffer potential overflow panic alert interrupt flag
 *  0b0..Buffer has not crossed the panic threshold limit
 *  0b1..Panic threshold limit crossed. Software must take action.
 */
#define ISI_CHNL_STS_PANIC_U_BUF(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_PANIC_U_BUF_SHIFT)) & ISI_CHNL_STS_PANIC_U_BUF_MASK)

#define ISI_CHNL_STS_OFLW_V_BUF_MASK             (0x400000U)
#define ISI_CHNL_STS_OFLW_V_BUF_SHIFT            (22U)
/*! OFLW_V_BUF - Overflow in U output buffer interrupt flag
 *  0b0..No overflow
 *  0b1..Overflow has occured in the channel
 */
#define ISI_CHNL_STS_OFLW_V_BUF(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_OFLW_V_BUF_SHIFT)) & ISI_CHNL_STS_OFLW_V_BUF_MASK)

#define ISI_CHNL_STS_PANIC_V_BUF_MASK            (0x800000U)
#define ISI_CHNL_STS_PANIC_V_BUF_SHIFT           (23U)
/*! PANIC_V_BUF - V output buffer potential overflow panic alert interrupt flag
 *  0b0..Buffer has not crossed the panic threshold limit
 *  0b1..Panic threshold limit crossed. Software must take action.
 */
#define ISI_CHNL_STS_PANIC_V_BUF(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_PANIC_V_BUF_SHIFT)) & ISI_CHNL_STS_PANIC_V_BUF_MASK)

#define ISI_CHNL_STS_AXI_RD_ERR_MASK             (0x2000000U)
#define ISI_CHNL_STS_AXI_RD_ERR_SHIFT            (25U)
/*! AXI_RD_ERR - AXI Bus read error interrupt flag
 *  0b0..No error
 *  0b1..Error occured during read
 */
#define ISI_CHNL_STS_AXI_RD_ERR(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_RD_ERR_SHIFT)) & ISI_CHNL_STS_AXI_RD_ERR_MASK)

#define ISI_CHNL_STS_AXI_WR_ERR_Y_MASK           (0x4000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_Y_SHIFT          (26U)
/*! AXI_WR_ERR_Y - AXI Bus write error interrupt flag for Y/RGB data buffer
 *  0b0..No error
 *  0b1..Error occured during write
 */
#define ISI_CHNL_STS_AXI_WR_ERR_Y(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_Y_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_Y_MASK)

#define ISI_CHNL_STS_AXI_WR_ERR_U_MASK           (0x8000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_U_SHIFT          (27U)
/*! AXI_WR_ERR_U - AXI Bus write error interrupt flag for U data buffer
 *  0b0..No error
 *  0b1..Error occured during write
 */
#define ISI_CHNL_STS_AXI_WR_ERR_U(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_U_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_U_MASK)

#define ISI_CHNL_STS_AXI_WR_ERR_V_MASK           (0x10000000U)
#define ISI_CHNL_STS_AXI_WR_ERR_V_SHIFT          (28U)
/*! AXI_WR_ERR_V - AXI Bus write error interrupt flag for V data buffer
 *  0b0..No error
 *  0b1..Error occured during write
 */
#define ISI_CHNL_STS_AXI_WR_ERR_V(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_AXI_WR_ERR_V_SHIFT)) & ISI_CHNL_STS_AXI_WR_ERR_V_MASK)

#define ISI_CHNL_STS_FRM_STRD_MASK               (0x20000000U)
#define ISI_CHNL_STS_FRM_STRD_SHIFT              (29U)
/*! FRM_STRD - Frame stored successfully interrupt flag
 *  0b0..No frame being received or in progress
 *  0b1..One full frame has been received and stored in memory
 */
#define ISI_CHNL_STS_FRM_STRD(x)                 (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_FRM_STRD_SHIFT)) & ISI_CHNL_STS_FRM_STRD_MASK)

#define ISI_CHNL_STS_LINE_STRD_MASK              (0x40000000U)
#define ISI_CHNL_STS_LINE_STRD_SHIFT             (30U)
/*! LINE_STRD - Line received and stored interrupt flag
 *  0b0..No new line received
 *  0b1..New line received and stored into memory
 */
#define ISI_CHNL_STS_LINE_STRD(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_LINE_STRD_SHIFT)) & ISI_CHNL_STS_LINE_STRD_MASK)

#define ISI_CHNL_STS_MEM_RD_DONE_MASK            (0x80000000U)
#define ISI_CHNL_STS_MEM_RD_DONE_SHIFT           (31U)
/*! MEM_RD_DONE - Memory read complete interrupt flag
 *  0b0..Image read from memory not complete or not started
 *  0b1..Image read from memory completed
 */
#define ISI_CHNL_STS_MEM_RD_DONE(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_STS_MEM_RD_DONE_SHIFT)) & ISI_CHNL_STS_MEM_RD_DONE_MASK)
/*! @} */

/*! @name CHNL_SCALE_FACTOR - Channel Scale Factor Register */
/*! @{ */

#define ISI_CHNL_SCALE_FACTOR_X_SCALE_MASK       (0x3FFFU)
#define ISI_CHNL_SCALE_FACTOR_X_SCALE_SHIFT      (0U)
/*! X_SCALE - Horizontal scaling factor */
#define ISI_CHNL_SCALE_FACTOR_X_SCALE(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_X_SCALE_SHIFT)) & ISI_CHNL_SCALE_FACTOR_X_SCALE_MASK)

#define ISI_CHNL_SCALE_FACTOR_RSVD1_MASK         (0xC000U)
#define ISI_CHNL_SCALE_FACTOR_RSVD1_SHIFT        (14U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_SCALE_FACTOR_RSVD1(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_RSVD1_SHIFT)) & ISI_CHNL_SCALE_FACTOR_RSVD1_MASK)

#define ISI_CHNL_SCALE_FACTOR_Y_SCALE_MASK       (0x3FFF0000U)
#define ISI_CHNL_SCALE_FACTOR_Y_SCALE_SHIFT      (16U)
/*! Y_SCALE - Vertical scaling factor */
#define ISI_CHNL_SCALE_FACTOR_Y_SCALE(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_Y_SCALE_SHIFT)) & ISI_CHNL_SCALE_FACTOR_Y_SCALE_MASK)

#define ISI_CHNL_SCALE_FACTOR_RSVD0_MASK         (0xC0000000U)
#define ISI_CHNL_SCALE_FACTOR_RSVD0_SHIFT        (30U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_SCALE_FACTOR_RSVD0(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_FACTOR_RSVD0_SHIFT)) & ISI_CHNL_SCALE_FACTOR_RSVD0_MASK)
/*! @} */

/*! @name CHNL_SCALE_OFFSET - Channel Scale Offset Register */
/*! @{ */

#define ISI_CHNL_SCALE_OFFSET_X_OFFSET_MASK      (0xFFFU)
#define ISI_CHNL_SCALE_OFFSET_X_OFFSET_SHIFT     (0U)
/*! X_OFFSET - Horizontal scaling offset */
#define ISI_CHNL_SCALE_OFFSET_X_OFFSET(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_X_OFFSET_SHIFT)) & ISI_CHNL_SCALE_OFFSET_X_OFFSET_MASK)

#define ISI_CHNL_SCALE_OFFSET_RSVD1_MASK         (0xF000U)
#define ISI_CHNL_SCALE_OFFSET_RSVD1_SHIFT        (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_SCALE_OFFSET_RSVD1(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_RSVD1_SHIFT)) & ISI_CHNL_SCALE_OFFSET_RSVD1_MASK)

#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET_MASK      (0xFFF0000U)
#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET_SHIFT     (16U)
/*! Y_OFFSET - Vertical scaling offset */
#define ISI_CHNL_SCALE_OFFSET_Y_OFFSET(x)        (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_Y_OFFSET_SHIFT)) & ISI_CHNL_SCALE_OFFSET_Y_OFFSET_MASK)

#define ISI_CHNL_SCALE_OFFSET_RSVD0_MASK         (0xF0000000U)
#define ISI_CHNL_SCALE_OFFSET_RSVD0_SHIFT        (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_SCALE_OFFSET_RSVD0(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCALE_OFFSET_RSVD0_SHIFT)) & ISI_CHNL_SCALE_OFFSET_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CROP_ULC - Channel Crop Upper Left Corner Coordinate Register */
/*! @{ */

#define ISI_CHNL_CROP_ULC_Y_MASK                 (0xFFFU)
#define ISI_CHNL_CROP_ULC_Y_SHIFT                (0U)
/*! Y - Upper Left Y-coordinate */
#define ISI_CHNL_CROP_ULC_Y(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_Y_SHIFT)) & ISI_CHNL_CROP_ULC_Y_MASK)

#define ISI_CHNL_CROP_ULC_RSVD1_MASK             (0xF000U)
#define ISI_CHNL_CROP_ULC_RSVD1_SHIFT            (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_CROP_ULC_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_RSVD1_SHIFT)) & ISI_CHNL_CROP_ULC_RSVD1_MASK)

#define ISI_CHNL_CROP_ULC_X_MASK                 (0xFFF0000U)
#define ISI_CHNL_CROP_ULC_X_SHIFT                (16U)
/*! X - Upper Left X-coordinate */
#define ISI_CHNL_CROP_ULC_X(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_X_SHIFT)) & ISI_CHNL_CROP_ULC_X_MASK)

#define ISI_CHNL_CROP_ULC_RSVD0_MASK             (0xF0000000U)
#define ISI_CHNL_CROP_ULC_RSVD0_SHIFT            (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_CROP_ULC_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_ULC_RSVD0_SHIFT)) & ISI_CHNL_CROP_ULC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CROP_LRC - Channel Crop Lower Right Corner Coordinate Register */
/*! @{ */

#define ISI_CHNL_CROP_LRC_Y_MASK                 (0xFFFU)
#define ISI_CHNL_CROP_LRC_Y_SHIFT                (0U)
/*! Y - Lower Right Y-coordinate */
#define ISI_CHNL_CROP_LRC_Y(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_Y_SHIFT)) & ISI_CHNL_CROP_LRC_Y_MASK)

#define ISI_CHNL_CROP_LRC_RSVD1_MASK             (0xF000U)
#define ISI_CHNL_CROP_LRC_RSVD1_SHIFT            (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_CROP_LRC_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_RSVD1_SHIFT)) & ISI_CHNL_CROP_LRC_RSVD1_MASK)

#define ISI_CHNL_CROP_LRC_X_MASK                 (0xFFF0000U)
#define ISI_CHNL_CROP_LRC_X_SHIFT                (16U)
/*! X - Lower Right X-coordinate */
#define ISI_CHNL_CROP_LRC_X(x)                   (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_X_SHIFT)) & ISI_CHNL_CROP_LRC_X_MASK)

#define ISI_CHNL_CROP_LRC_RSVD0_MASK             (0xF0000000U)
#define ISI_CHNL_CROP_LRC_RSVD0_SHIFT            (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_CROP_LRC_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CROP_LRC_RSVD0_SHIFT)) & ISI_CHNL_CROP_LRC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF0 - Channel Color Space Conversion Coefficient Register 0 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF0_A1_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF0_A1_SHIFT             (0U)
/*! A1 - CSC Coefficient A1 value */
#define ISI_CHNL_CSC_COEFF0_A1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_A1_SHIFT)) & ISI_CHNL_CSC_COEFF0_A1_MASK)

#define ISI_CHNL_CSC_COEFF0_RSVD1_MASK           (0xF800U)
#define ISI_CHNL_CSC_COEFF0_RSVD1_SHIFT          (11U)
/*! RSVD1 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF0_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF0_RSVD1_MASK)

#define ISI_CHNL_CSC_COEFF0_A2_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF0_A2_SHIFT             (16U)
/*! A2 - CSC Coefficient A2 value */
#define ISI_CHNL_CSC_COEFF0_A2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_A2_SHIFT)) & ISI_CHNL_CSC_COEFF0_A2_MASK)

#define ISI_CHNL_CSC_COEFF0_RSVD0_MASK           (0xF8000000U)
#define ISI_CHNL_CSC_COEFF0_RSVD0_SHIFT          (27U)
/*! RSVD0 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF0_RSVD0(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF0_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF0_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF1 - Channel Color Space Conversion Coefficient Register 1 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF1_A3_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF1_A3_SHIFT             (0U)
/*! A3 - CSC Coefficient A3 value */
#define ISI_CHNL_CSC_COEFF1_A3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_A3_SHIFT)) & ISI_CHNL_CSC_COEFF1_A3_MASK)

#define ISI_CHNL_CSC_COEFF1_RSVD1_MASK           (0xF800U)
#define ISI_CHNL_CSC_COEFF1_RSVD1_SHIFT          (11U)
/*! RSVD1 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF1_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF1_RSVD1_MASK)

#define ISI_CHNL_CSC_COEFF1_B1_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF1_B1_SHIFT             (16U)
/*! B1 - CSC Coefficient B1 value */
#define ISI_CHNL_CSC_COEFF1_B1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_B1_SHIFT)) & ISI_CHNL_CSC_COEFF1_B1_MASK)

#define ISI_CHNL_CSC_COEFF1_RSVD0_MASK           (0xF8000000U)
#define ISI_CHNL_CSC_COEFF1_RSVD0_SHIFT          (27U)
/*! RSVD0 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF1_RSVD0(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF1_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF1_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF2 - Channel Color Space Conversion Coefficient Register 2 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF2_B2_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF2_B2_SHIFT             (0U)
/*! B2 - CSC Coefficient B2 value */
#define ISI_CHNL_CSC_COEFF2_B2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_B2_SHIFT)) & ISI_CHNL_CSC_COEFF2_B2_MASK)

#define ISI_CHNL_CSC_COEFF2_RSVD1_MASK           (0xF800U)
#define ISI_CHNL_CSC_COEFF2_RSVD1_SHIFT          (11U)
/*! RSVD1 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF2_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF2_RSVD1_MASK)

#define ISI_CHNL_CSC_COEFF2_B3_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF2_B3_SHIFT             (16U)
/*! B3 - CSC Coefficient B3 value */
#define ISI_CHNL_CSC_COEFF2_B3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_B3_SHIFT)) & ISI_CHNL_CSC_COEFF2_B3_MASK)

#define ISI_CHNL_CSC_COEFF2_RSVD0_MASK           (0xF8000000U)
#define ISI_CHNL_CSC_COEFF2_RSVD0_SHIFT          (27U)
/*! RSVD0 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF2_RSVD0(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF2_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF2_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF3 - Channel Color Space Conversion Coefficient Register 3 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF3_C1_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF3_C1_SHIFT             (0U)
/*! C1 - CSC Coefficient C1 value */
#define ISI_CHNL_CSC_COEFF3_C1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_C1_SHIFT)) & ISI_CHNL_CSC_COEFF3_C1_MASK)

#define ISI_CHNL_CSC_COEFF3_RSVD1_MASK           (0xF800U)
#define ISI_CHNL_CSC_COEFF3_RSVD1_SHIFT          (11U)
/*! RSVD1 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF3_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF3_RSVD1_MASK)

#define ISI_CHNL_CSC_COEFF3_C2_MASK              (0x7FF0000U)
#define ISI_CHNL_CSC_COEFF3_C2_SHIFT             (16U)
/*! C2 - CSC Coefficient C2 value */
#define ISI_CHNL_CSC_COEFF3_C2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_C2_SHIFT)) & ISI_CHNL_CSC_COEFF3_C2_MASK)

#define ISI_CHNL_CSC_COEFF3_RSVD0_MASK           (0xF8000000U)
#define ISI_CHNL_CSC_COEFF3_RSVD0_SHIFT          (27U)
/*! RSVD0 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF3_RSVD0(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF3_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF3_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF4 - Channel Color Space Conversion Coefficient Register 4 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF4_C3_MASK              (0x7FFU)
#define ISI_CHNL_CSC_COEFF4_C3_SHIFT             (0U)
/*! C3 - CSC Coefficient C3 value */
#define ISI_CHNL_CSC_COEFF4_C3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_C3_SHIFT)) & ISI_CHNL_CSC_COEFF4_C3_MASK)

#define ISI_CHNL_CSC_COEFF4_RSVD1_MASK           (0xF800U)
#define ISI_CHNL_CSC_COEFF4_RSVD1_SHIFT          (11U)
/*! RSVD1 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF4_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF4_RSVD1_MASK)

#define ISI_CHNL_CSC_COEFF4_D1_MASK              (0x1FF0000U)
#define ISI_CHNL_CSC_COEFF4_D1_SHIFT             (16U)
/*! D1 - CSC Coefficient D1 value */
#define ISI_CHNL_CSC_COEFF4_D1(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_D1_SHIFT)) & ISI_CHNL_CSC_COEFF4_D1_MASK)

#define ISI_CHNL_CSC_COEFF4_RSVD0_MASK           (0xFE000000U)
#define ISI_CHNL_CSC_COEFF4_RSVD0_SHIFT          (25U)
/*! RSVD0 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF4_RSVD0(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF4_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF4_RSVD0_MASK)
/*! @} */

/*! @name CHNL_CSC_COEFF5 - Channel Color Space Conversion Coefficient Register 5 */
/*! @{ */

#define ISI_CHNL_CSC_COEFF5_D2_MASK              (0x1FFU)
#define ISI_CHNL_CSC_COEFF5_D2_SHIFT             (0U)
/*! D2 - CSC Coefficient D2 value */
#define ISI_CHNL_CSC_COEFF5_D2(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_D2_SHIFT)) & ISI_CHNL_CSC_COEFF5_D2_MASK)

#define ISI_CHNL_CSC_COEFF5_RSVD1_MASK           (0xFE00U)
#define ISI_CHNL_CSC_COEFF5_RSVD1_SHIFT          (9U)
/*! RSVD1 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF5_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_RSVD1_SHIFT)) & ISI_CHNL_CSC_COEFF5_RSVD1_MASK)

#define ISI_CHNL_CSC_COEFF5_D3_MASK              (0x1FF0000U)
#define ISI_CHNL_CSC_COEFF5_D3_SHIFT             (16U)
/*! D3 - CSC Coefficient D3 value */
#define ISI_CHNL_CSC_COEFF5_D3(x)                (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_D3_SHIFT)) & ISI_CHNL_CSC_COEFF5_D3_MASK)

#define ISI_CHNL_CSC_COEFF5_RSVD0_MASK           (0xFE000000U)
#define ISI_CHNL_CSC_COEFF5_RSVD0_SHIFT          (25U)
/*! RSVD0 - Reserved Field. Reads only zeros */
#define ISI_CHNL_CSC_COEFF5_RSVD0(x)             (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_CSC_COEFF5_RSVD0_SHIFT)) & ISI_CHNL_CSC_COEFF5_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_0_ALPHA - Channel Alpha Value Register for Region of Interest 0 */
/*! @{ */

#define ISI_CHNL_ROI_0_ALPHA_RSVD1_MASK          (0xFFFFU)
#define ISI_CHNL_ROI_0_ALPHA_RSVD1_SHIFT         (0U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_0_ALPHA_RSVD1(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_RSVD1_MASK)

#define ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_MASK       (0x10000U)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_SHIFT      (16U)
/*! ALPHA_EN - Alpha value insertion enable
 *  0b0..Alpha value insertion is disabled
 *  0b1..Alpha value insertion is enabled
 */
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_EN(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_ALPHA_EN_MASK)

#define ISI_CHNL_ROI_0_ALPHA_RSVD0_MASK          (0xFE0000U)
#define ISI_CHNL_ROI_0_ALPHA_RSVD0_SHIFT         (17U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_0_ALPHA_RSVD0(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_RSVD0_MASK)

#define ISI_CHNL_ROI_0_ALPHA_ALPHA_MASK          (0xFF000000U)
#define ISI_CHNL_ROI_0_ALPHA_ALPHA_SHIFT         (24U)
/*! ALPHA - Alpha Value to be inserted with image */
#define ISI_CHNL_ROI_0_ALPHA_ALPHA(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_0_ALPHA_ALPHA_MASK)
/*! @} */

/*! @name CHNL_ROI_0_ULC - Channel Upper Left Coordinate Register for Region of Interest 0 */
/*! @{ */

#define ISI_CHNL_ROI_0_ULC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_0_ULC_Y_SHIFT               (0U)
/*! Y - Upper Left Y-coordinate */
#define ISI_CHNL_ROI_0_ULC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_Y_SHIFT)) & ISI_CHNL_ROI_0_ULC_Y_MASK)

#define ISI_CHNL_ROI_0_ULC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_0_ULC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_0_ULC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_0_ULC_RSVD1_MASK)

#define ISI_CHNL_ROI_0_ULC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_0_ULC_X_SHIFT               (16U)
/*! X - Upper Left X-coordinate */
#define ISI_CHNL_ROI_0_ULC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_X_SHIFT)) & ISI_CHNL_ROI_0_ULC_X_MASK)

#define ISI_CHNL_ROI_0_ULC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_0_ULC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_0_ULC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_0_ULC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_0_LRC - Channel Lower Right Coordinate Register for Region of Interest 0 */
/*! @{ */

#define ISI_CHNL_ROI_0_LRC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_0_LRC_Y_SHIFT               (0U)
/*! Y - Lower Right Y-coordinate */
#define ISI_CHNL_ROI_0_LRC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_Y_SHIFT)) & ISI_CHNL_ROI_0_LRC_Y_MASK)

#define ISI_CHNL_ROI_0_LRC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_0_LRC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_0_LRC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_0_LRC_RSVD1_MASK)

#define ISI_CHNL_ROI_0_LRC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_0_LRC_X_SHIFT               (16U)
/*! X - Lower Right X-coordinate */
#define ISI_CHNL_ROI_0_LRC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_X_SHIFT)) & ISI_CHNL_ROI_0_LRC_X_MASK)

#define ISI_CHNL_ROI_0_LRC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_0_LRC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_0_LRC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_0_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_0_LRC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_1_ALPHA - Channel Alpha Value Register for Region of Interest 1 */
/*! @{ */

#define ISI_CHNL_ROI_1_ALPHA_RSVD1_MASK          (0xFFFFU)
#define ISI_CHNL_ROI_1_ALPHA_RSVD1_SHIFT         (0U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_1_ALPHA_RSVD1(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_RSVD1_MASK)

#define ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_MASK       (0x10000U)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_SHIFT      (16U)
/*! ALPHA_EN - Alpha value insertion enable
 *  0b0..Alpha value insertion is disabled
 *  0b1..Alpha value insertion is enabled
 */
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_EN(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_ALPHA_EN_MASK)

#define ISI_CHNL_ROI_1_ALPHA_RSVD0_MASK          (0xFE0000U)
#define ISI_CHNL_ROI_1_ALPHA_RSVD0_SHIFT         (17U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_1_ALPHA_RSVD0(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_RSVD0_MASK)

#define ISI_CHNL_ROI_1_ALPHA_ALPHA_MASK          (0xFF000000U)
#define ISI_CHNL_ROI_1_ALPHA_ALPHA_SHIFT         (24U)
/*! ALPHA - Alpha Value to be inserted with image */
#define ISI_CHNL_ROI_1_ALPHA_ALPHA(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_1_ALPHA_ALPHA_MASK)
/*! @} */

/*! @name CHNL_ROI_1_ULC - Channel Upper Left Coordinate Register for Region of Interest 1 */
/*! @{ */

#define ISI_CHNL_ROI_1_ULC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_1_ULC_Y_SHIFT               (0U)
/*! Y - Upper Left Y-coordinate */
#define ISI_CHNL_ROI_1_ULC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_Y_SHIFT)) & ISI_CHNL_ROI_1_ULC_Y_MASK)

#define ISI_CHNL_ROI_1_ULC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_1_ULC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_1_ULC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_1_ULC_RSVD1_MASK)

#define ISI_CHNL_ROI_1_ULC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_1_ULC_X_SHIFT               (16U)
/*! X - Upper Left X-coordinate */
#define ISI_CHNL_ROI_1_ULC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_X_SHIFT)) & ISI_CHNL_ROI_1_ULC_X_MASK)

#define ISI_CHNL_ROI_1_ULC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_1_ULC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_1_ULC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_1_ULC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_1_LRC - Channel Lower Right Coordinate Register for Region of Interest 1 */
/*! @{ */

#define ISI_CHNL_ROI_1_LRC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_1_LRC_Y_SHIFT               (0U)
/*! Y - Lower Right Y-coordinate */
#define ISI_CHNL_ROI_1_LRC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_Y_SHIFT)) & ISI_CHNL_ROI_1_LRC_Y_MASK)

#define ISI_CHNL_ROI_1_LRC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_1_LRC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_1_LRC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_1_LRC_RSVD1_MASK)

#define ISI_CHNL_ROI_1_LRC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_1_LRC_X_SHIFT               (16U)
/*! X - Lower Right X-coordinate */
#define ISI_CHNL_ROI_1_LRC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_X_SHIFT)) & ISI_CHNL_ROI_1_LRC_X_MASK)

#define ISI_CHNL_ROI_1_LRC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_1_LRC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_1_LRC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_1_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_1_LRC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_2_ALPHA - Channel Alpha Value Register for Region of Interest 2 */
/*! @{ */

#define ISI_CHNL_ROI_2_ALPHA_RSVD1_MASK          (0xFFFFU)
#define ISI_CHNL_ROI_2_ALPHA_RSVD1_SHIFT         (0U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_2_ALPHA_RSVD1(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_RSVD1_MASK)

#define ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_MASK       (0x10000U)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_SHIFT      (16U)
/*! ALPHA_EN - Alpha value insertion enable
 *  0b0..Alpha value insertion is disabled
 *  0b1..Alpha value insertion is enabled
 */
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_EN(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_ALPHA_EN_MASK)

#define ISI_CHNL_ROI_2_ALPHA_RSVD0_MASK          (0xFE0000U)
#define ISI_CHNL_ROI_2_ALPHA_RSVD0_SHIFT         (17U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_2_ALPHA_RSVD0(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_RSVD0_MASK)

#define ISI_CHNL_ROI_2_ALPHA_ALPHA_MASK          (0xFF000000U)
#define ISI_CHNL_ROI_2_ALPHA_ALPHA_SHIFT         (24U)
/*! ALPHA - Alpha Value to be inserted with image */
#define ISI_CHNL_ROI_2_ALPHA_ALPHA(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_2_ALPHA_ALPHA_MASK)
/*! @} */

/*! @name CHNL_ROI_2_ULC - Channel Upper Left Coordinate Register for Region of Interest 2 */
/*! @{ */

#define ISI_CHNL_ROI_2_ULC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_2_ULC_Y_SHIFT               (0U)
/*! Y - Upper Left Y-coordinate */
#define ISI_CHNL_ROI_2_ULC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_Y_SHIFT)) & ISI_CHNL_ROI_2_ULC_Y_MASK)

#define ISI_CHNL_ROI_2_ULC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_2_ULC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_2_ULC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_2_ULC_RSVD1_MASK)

#define ISI_CHNL_ROI_2_ULC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_2_ULC_X_SHIFT               (16U)
/*! X - Upper Left X-coordinate */
#define ISI_CHNL_ROI_2_ULC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_X_SHIFT)) & ISI_CHNL_ROI_2_ULC_X_MASK)

#define ISI_CHNL_ROI_2_ULC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_2_ULC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_2_ULC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_2_ULC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_2_LRC - Channel Lower Right Coordinate Register for Region of Interest 2 */
/*! @{ */

#define ISI_CHNL_ROI_2_LRC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_2_LRC_Y_SHIFT               (0U)
/*! Y - Lower Right Y-coordinate */
#define ISI_CHNL_ROI_2_LRC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_Y_SHIFT)) & ISI_CHNL_ROI_2_LRC_Y_MASK)

#define ISI_CHNL_ROI_2_LRC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_2_LRC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_2_LRC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_2_LRC_RSVD1_MASK)

#define ISI_CHNL_ROI_2_LRC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_2_LRC_X_SHIFT               (16U)
/*! X - Lower Right X-coordinate */
#define ISI_CHNL_ROI_2_LRC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_X_SHIFT)) & ISI_CHNL_ROI_2_LRC_X_MASK)

#define ISI_CHNL_ROI_2_LRC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_2_LRC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_2_LRC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_2_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_2_LRC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_3_ALPHA - Channel Alpha Value Register for Region of Interest 3 */
/*! @{ */

#define ISI_CHNL_ROI_3_ALPHA_RSVD1_MASK          (0xFFFFU)
#define ISI_CHNL_ROI_3_ALPHA_RSVD1_SHIFT         (0U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_3_ALPHA_RSVD1(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_RSVD1_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_RSVD1_MASK)

#define ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_MASK       (0x10000U)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_SHIFT      (16U)
/*! ALPHA_EN - Alpha value insertion enable
 *  0b0..Alpha value insertion is disabled
 *  0b1..Alpha value insertion is enabled
 */
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_EN(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_ALPHA_EN_MASK)

#define ISI_CHNL_ROI_3_ALPHA_RSVD0_MASK          (0xFE0000U)
#define ISI_CHNL_ROI_3_ALPHA_RSVD0_SHIFT         (17U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_3_ALPHA_RSVD0(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_RSVD0_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_RSVD0_MASK)

#define ISI_CHNL_ROI_3_ALPHA_ALPHA_MASK          (0xFF000000U)
#define ISI_CHNL_ROI_3_ALPHA_ALPHA_SHIFT         (24U)
/*! ALPHA - Alpha Value to be inserted with image */
#define ISI_CHNL_ROI_3_ALPHA_ALPHA(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ALPHA_ALPHA_SHIFT)) & ISI_CHNL_ROI_3_ALPHA_ALPHA_MASK)
/*! @} */

/*! @name CHNL_ROI_3_ULC - Channel Upper Left Coordinate Register for Region of Interest 3 */
/*! @{ */

#define ISI_CHNL_ROI_3_ULC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_3_ULC_Y_SHIFT               (0U)
/*! Y - Upper Left Y-coordinate */
#define ISI_CHNL_ROI_3_ULC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_Y_SHIFT)) & ISI_CHNL_ROI_3_ULC_Y_MASK)

#define ISI_CHNL_ROI_3_ULC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_3_ULC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_3_ULC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_RSVD1_SHIFT)) & ISI_CHNL_ROI_3_ULC_RSVD1_MASK)

#define ISI_CHNL_ROI_3_ULC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_3_ULC_X_SHIFT               (16U)
/*! X - Upper Left X-coordinate */
#define ISI_CHNL_ROI_3_ULC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_X_SHIFT)) & ISI_CHNL_ROI_3_ULC_X_MASK)

#define ISI_CHNL_ROI_3_ULC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_3_ULC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_3_ULC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_ULC_RSVD0_SHIFT)) & ISI_CHNL_ROI_3_ULC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_ROI_3_LRC - Channel Lower Right Coordinate Register for Region of Interest 3 */
/*! @{ */

#define ISI_CHNL_ROI_3_LRC_Y_MASK                (0xFFFU)
#define ISI_CHNL_ROI_3_LRC_Y_SHIFT               (0U)
/*! Y - Lower Right Y-coordinate */
#define ISI_CHNL_ROI_3_LRC_Y(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_Y_SHIFT)) & ISI_CHNL_ROI_3_LRC_Y_MASK)

#define ISI_CHNL_ROI_3_LRC_RSVD1_MASK            (0xF000U)
#define ISI_CHNL_ROI_3_LRC_RSVD1_SHIFT           (12U)
/*! RSVD1 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_3_LRC_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_RSVD1_SHIFT)) & ISI_CHNL_ROI_3_LRC_RSVD1_MASK)

#define ISI_CHNL_ROI_3_LRC_X_MASK                (0xFFF0000U)
#define ISI_CHNL_ROI_3_LRC_X_SHIFT               (16U)
/*! X - Lower Right X-coordinate */
#define ISI_CHNL_ROI_3_LRC_X(x)                  (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_X_SHIFT)) & ISI_CHNL_ROI_3_LRC_X_MASK)

#define ISI_CHNL_ROI_3_LRC_RSVD0_MASK            (0xF0000000U)
#define ISI_CHNL_ROI_3_LRC_RSVD0_SHIFT           (28U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_ROI_3_LRC_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_ROI_3_LRC_RSVD0_SHIFT)) & ISI_CHNL_ROI_3_LRC_RSVD0_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF1_ADDR_Y - Channel RGB or Luma (Y) Output Buffer 1 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_SHIFT      (0U)
/*! ADDR - Starting address for the RGB or Y (luma) memory location */
#define ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_Y_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF1_ADDR_U - Channel Chroma (U/Cb/UV/CbCr) Output Buffer 1 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_SHIFT      (0U)
/*! ADDR - Starting address for the U/Cb or 2 plane UV/CbCr Chroma memory location */
#define ISI_CHNL_OUT_BUF1_ADDR_U_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF1_ADDR_U_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF1_ADDR_V - Channel Chroma (V/Cr) Output Buffer 1 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF1_ADDR_V_ADDR_SHIFT      (0U)
/*! ADDR - Starting address for the V/Cr memory location */
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
/*! READ_MEM - Initiate read from memory
 *  0b0..No reads from memory done
 *  0b1..Reads from memory initiated
 */
#define ISI_CHNL_MEM_RD_CTRL_READ_MEM(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_READ_MEM_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_READ_MEM_MASK)

#define ISI_CHNL_MEM_RD_CTRL_RSVD0_MASK          (0xFFFFFFEU)
#define ISI_CHNL_MEM_RD_CTRL_RSVD0_SHIFT         (1U)
/*! RSVD0 - Reserved field. Reads only zeros */
#define ISI_CHNL_MEM_RD_CTRL_RSVD0(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_RSVD0_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_RSVD0_MASK)

#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_MASK       (0xF0000000U)
#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_SHIFT      (28U)
/*! IMG_TYPE - Input image format
 *  0b0000..BGR8P - BGR format with 8-bits per color component (packed into 32-bit DWORD)
 *  0b0001..RGB8P - RGB format with 8-bits per color component (packed into 32-bit DWORD)
 *  0b0010..XRGB8 - RGB format with 8-bits per color component (unpacked and LSB aligned in 32-bit DWORD)
 *  0b0011..RGBX8 - RGB format with 8-bits per color component (unpacked and MSBalinged in 32-bit DWORD)
 *  0b0100..XBGR8 - BGR format with 8-bits per color component (unpacked and LSB aligned in 32-bit DWORD)
 *  0b0101..RGB565 - RGB format with 5-bits of R, B; 6-bits of G (packed into 32-bit DWORD)
 *  0b0110..A2BGR10 - BGR format with 2-bits alpha in MSB; 10-bits per color component
 *  0b0111..A2RGB10 - RGB format with 2-bits alpha in MSB; 10-bits per color component
 *  0b1000..YUV444_1P8P with 8-bits per color component; 1-plane, YUV interleaved packed bytes
 *  0b1001..YUV444_1P10 with 10-bits per color component; 1-plane, YUV interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b1010..YUV444_1P10P with 10-bits per color component; 1-plane, YUV interleaved packed bytes (2 MSBs waste bits in 32-bit WORD)
 *  0b1011..YUV444_1P12 with 12-bits per color component; 1-plane, YUV interleaved unpacked bytes (4 LSBs waste bits in 16-bit WORD)
 *  0b1100..YUV444_1P8 with 8-bits per color component; 1-plane YUV interleaved unpacked bytes (8 MSBs waste bits in 32-bit DWORD)
 *  0b1101..YUV422_1P8P with 8-bits per color component; 1-plane YUV interleaved packed bytes
 *  0b1110..YUV422_1P10 with 10-bits per color component; 1-plane, YUV interleaved unpacked bytes (6 LSBs waste bits in 16-bit WORD)
 *  0b1111..YUV422_1P12 with 12-bits per color component; 1-plane, YUV interleaved packed bytes (4 MSBs waste bits in 16-bit WORD)
 */
#define ISI_CHNL_MEM_RD_CTRL_IMG_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_SHIFT)) & ISI_CHNL_MEM_RD_CTRL_IMG_TYPE_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF2_ADDR_Y - Channel RGB or Luma (Y) Output Buffer 2 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_SHIFT      (0U)
/*! ADDR - Starting address for the RGB or Y (luma) memory location */
#define ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_Y_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF2_ADDR_U - Channel Chroma (U/Cb/UV/CbCr) Output Buffer 2 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_SHIFT      (0U)
/*! ADDR - Starting address for the U/Cb or 2 plane UV/CbCr Chroma memory location */
#define ISI_CHNL_OUT_BUF2_ADDR_U_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_U_ADDR_MASK)
/*! @} */

/*! @name CHNL_OUT_BUF2_ADDR_V - Channel Chroma (V/Cr) Output Buffer 2 Address */
/*! @{ */

#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_MASK       (0xFFFFFFFFU)
#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_SHIFT      (0U)
/*! ADDR - Starting address for the V/Cr memory location */
#define ISI_CHNL_OUT_BUF2_ADDR_V_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_SHIFT)) & ISI_CHNL_OUT_BUF2_ADDR_V_ADDR_MASK)
/*! @} */

/*! @name CHNL_SCL_IMG_CFG - Channel Scaled Image Configuration */
/*! @{ */

#define ISI_CHNL_SCL_IMG_CFG_WIDTH_MASK          (0x1FFFU)
#define ISI_CHNL_SCL_IMG_CFG_WIDTH_SHIFT         (0U)
/*! WIDTH - Scaled image width (pixels) */
#define ISI_CHNL_SCL_IMG_CFG_WIDTH(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_WIDTH_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_WIDTH_MASK)

#define ISI_CHNL_SCL_IMG_CFG_RSVD0_MASK          (0xE000U)
#define ISI_CHNL_SCL_IMG_CFG_RSVD0_SHIFT         (13U)
/*! RSVD0 - Reserved field. Reads only zeros. */
#define ISI_CHNL_SCL_IMG_CFG_RSVD0(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_RSVD0_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_RSVD0_MASK)

#define ISI_CHNL_SCL_IMG_CFG_HEIGHT_MASK         (0x1FFF0000U)
#define ISI_CHNL_SCL_IMG_CFG_HEIGHT_SHIFT        (16U)
/*! HEIGHT - Scaled image height (lines) */
#define ISI_CHNL_SCL_IMG_CFG_HEIGHT(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_HEIGHT_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_HEIGHT_MASK)

#define ISI_CHNL_SCL_IMG_CFG_RSVD1_MASK          (0xE0000000U)
#define ISI_CHNL_SCL_IMG_CFG_RSVD1_SHIFT         (29U)
/*! RSVD1 - Reserved field. Reads only zeros. */
#define ISI_CHNL_SCL_IMG_CFG_RSVD1(x)            (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_SCL_IMG_CFG_RSVD1_SHIFT)) & ISI_CHNL_SCL_IMG_CFG_RSVD1_MASK)
/*! @} */

/*! @name CHNL_FLOW_CTRL - Channel Flow Control Register */
/*! @{ */

#define ISI_CHNL_FLOW_CTRL_FC_DENOM_MASK         (0xFFU)
#define ISI_CHNL_FLOW_CTRL_FC_DENOM_SHIFT        (0U)
/*! FC_DENOM - Denominator value of fraction of usable bandwidth
 *  0b00000000..Invalid value. Flow control will be disabled.
 */
#define ISI_CHNL_FLOW_CTRL_FC_DENOM(x)           (((uint32_t)(((uint32_t)(x)) << ISI_CHNL_FLOW_CTRL_FC_DENOM_SHIFT)) & ISI_CHNL_FLOW_CTRL_FC_DENOM_MASK)

#define ISI_CHNL_FLOW_CTRL_FC_NUMER_MASK         (0xFF0000U)
#define ISI_CHNL_FLOW_CTRL_FC_NUMER_SHIFT        (16U)
/*! FC_NUMER - Numertor value of fraction of usable bandwidth
 *  0b00000000..Flow control is disabled.
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ISI_H_ */

