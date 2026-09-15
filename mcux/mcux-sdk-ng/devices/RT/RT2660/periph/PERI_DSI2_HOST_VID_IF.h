/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSI2_HOST_VID_IF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DSI2_HOST_VID_IF.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DSI2_HOST_VID_IF
 *
 * CMSIS Peripheral Access Layer for DSI2_HOST_VID_IF
 */

#if !defined(PERI_DSI2_HOST_VID_IF_H_)
#define PERI_DSI2_HOST_VID_IF_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- DSI2_HOST_VID_IF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_VID_IF_Peripheral_Access_Layer DSI2_HOST_VID_IF Peripheral Access Layer
 * @{
 */

/** DSI2_HOST_VID_IF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_VID_MODE;                      /**< Video Mode, offset: 0x0 */
  __IO uint32_t CFG_VID_PIXELS_PER_PACKET;         /**< Video Pixels Per Packet, offset: 0x4 */
  __IO uint32_t CFG_VID_PIXEL_PAYLOAD_SIZE;        /**< Video Pixel Payload Size, offset: 0x8 */
  __IO uint32_t CFG_VID_START_DELAY;               /**< Video Start Delay, offset: 0xC */
  __IO uint32_t CFG_VID_HFP;                       /**< Video Horizontal Sync Front Porch Time, offset: 0x10 */
  __IO uint32_t CFG_VID_HBP;                       /**< Video Horizontal Sync Back Porch Time, offset: 0x14 */
  __IO uint32_t CFG_VID_HSA;                       /**< Video Horizontal Sync Active Time, offset: 0x18 */
  __IO uint32_t CFG_VID_VBP;                       /**< Video Vertical Sync Back Porch Time, offset: 0x1C */
  __IO uint32_t CFG_VID_VFP;                       /**< Video Vertical Sync Front Porch Time, offset: 0x20 */
  __IO uint32_t CFG_VID_VACTIVE;                   /**< Video Vertical Sync Active Time, offset: 0x24 */
  __IO uint32_t CFG_VID_VSS_PAYLOAD;               /**< Video Vertical Sync Start Payload, offset: 0x28 */
  __IO uint32_t CFG_VID_PAYLOAD_PER_PACKET;        /**< Video Payload Per Packet, offset: 0x2C */
       uint8_t RESERVED_0[4];
  __IO uint32_t VID_IRQ_STATUS;                    /**< Video Interrupt Request Status, offset: 0x34 */
  __IO uint32_t VID_IRQ_MASK;                      /**< Video Interrupt Request Mask, offset: 0x38 */
#if 1 /*Header File Update Workaround*/
       uint8_t RESERVED_1[4];
  __IO uint32_t CFG_VID_SAFE_MODE;                 /**< Video Safe Mode, offset: 0x40 */
#endif
} DSI2_HOST_VID_IF_Type;

/* ----------------------------------------------------------------------------
   -- DSI2_HOST_VID_IF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_VID_IF_Register_Masks DSI2_HOST_VID_IF Register Masks
 * @{
 */

/*! @name CFG_VID_MODE - Video Mode */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_FORMAT_MASK (0x3FU)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_FORMAT_SHIFT (0U)
/*! cfg_vid_pixel_format
 *  0b001011..COMPRESSED
 *  0b001100..YCBCR_20BIT_LP
 *  0b001101..RGB_101010_30BIT
 *  0b001110..RGB_565_16BIT
 *  0b011100..YCBCR_24BIT
 *  0b011101..RGB_121212_36BIT
 *  0b011110..RGB_666_18BIT
 *  0b101100..YCBCR_16BIT
 *  0b101110..RGB_666_18BIT_LP
 *  0b111100..YCBCR_20BIT
 *  0b111101..YCBCR_12BIT
 *  0b111110..RGB_888_24BIT
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_FORMAT_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_FORMAT_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VC_MASK (0xC0U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VC_SHIFT (6U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VC(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VC_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VC_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_EXT_PKT_EN_MASK (0xF00U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_EXT_PKT_EN_SHIFT (8U)
/*! cfg_vid_ext_pkt_en
 *  0b1xxx..external packets are allowed during vertical front porch
 *  0bx1xx..external packets are allowed during active video lines
 *  0bxx1x..external packets are allowed during vertical back porch
 *  0bxxx1..external packets are allowed during vertical sync
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_EXT_PKT_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_EXT_PKT_EN_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_EXT_PKT_EN_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PACKETS_PER_LINE_MASK (0xF000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PACKETS_PER_LINE_SHIFT (12U)
/*! cfg_vid_packets_per_line
 *  0b0001..1 packet sent per video line
 *  0b0010..2 packets sent
 *  0b0011..3 packets sent
 *  0b0100..4 packets sent
 *  0b0101..5 packets sent
 *  0b0110..6 packets sent
 *  0b0111..7 packets sent
 *  0b1000..8 packets sent
 *  0b1001..15 not supported
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PACKETS_PER_LINE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PACKETS_PER_LINE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PACKETS_PER_LINE_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VIDEO_MODE_MASK (0x30000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VIDEO_MODE_SHIFT (16U)
/*! cfg_vid_video_mode
 *  0b00..Non-Burst mode with Sync Pulses
 *  0b01..Non-Burst mode with Sync Events
 *  0b10..Burst mode
 *  0b11..
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VIDEO_MODE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VIDEO_MODE_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_HSYNC_POLARITY_MASK (0x40000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_HSYNC_POLARITY_SHIFT (18U)
/*! cfg_vid_hsync_polarity
 *  0b0..active low
 *  0b1..active high
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_HSYNC_POLARITY_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_HSYNC_POLARITY_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VSYNC_POLARITY_MASK (0x80000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VSYNC_POLARITY_SHIFT (19U)
/*! cfg_vid_vsync_polarity
 *  0b0..active low
 *  0b1..active high
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VSYNC_POLARITY_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_VSYNC_POLARITY_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_USE_NULL_PKT_BLLP_MASK (0x100000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_USE_NULL_PKT_BLLP_SHIFT (20U)
/*! cfg_vid_use_null_pkt_bllp
 *  0b0..Blanking packet used in bllp region
 *  0b1..Null packet used in bllp region
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_USE_NULL_PKT_BLLP(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_USE_NULL_PKT_BLLP_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_USE_NULL_PKT_BLLP_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_V_BLLP_MODE_MASK (0x200000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_V_BLLP_MODE_SHIFT (21U)
/*! cfg_vid_v_bllp_mode
 *  0b0..blanking packets are sent during vertical BLLP periods
 *  0b1..LP mode is used for vertical BLLP periods
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_V_BLLP_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_V_BLLP_MODE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_V_BLLP_MODE_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_H_BLLP_MODE_MASK (0x400000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_H_BLLP_MODE_SHIFT (22U)
/*! cfg_vid_h_bllp_mode
 *  0b0..blanking packets are sent during horizontal BLLP periods
 *  0b1..LP mode is used for horizontal BLLP periods
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_H_BLLP_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_H_BLLP_MODE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_H_BLLP_MODE_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_OVERRIDE_MASK (0x800000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_OVERRIDE_SHIFT (23U)
/*! cfg_vid_override
 *  0b0..auto mode - first video frame is used to calibrate
 *  0b1..override mode - cfg_vid_* values are used
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_OVERRIDE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_OVERRIDE_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_ALIGNMENT_MASK (0x1000000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_ALIGNMENT_SHIFT (24U)
/*! cfg_vid_pixel_alignment
 *  0b0..LSB alignment (00000PPP)
 *  0b1..MSB alignment (PPP00000)
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_ALIGNMENT(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_ALIGNMENT_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_PIXEL_ALIGNMENT_MASK)

#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_ENABLE_MASK (0x80000000U)
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_ENABLE_SHIFT (31U)
/*! cfg_vid_enable
 *  0b0..video interface off, no packets from the video interface are sent
 *  0b1..video interface on, video on the video interface generate packets
 */
#define DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_ENABLE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_MODE_CFG_VID_ENABLE_MASK)
/*! @} */

/*! @name CFG_VID_PIXELS_PER_PACKET - Video Pixels Per Packet */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_PIXELS_PER_PACKET_CFG_VID_PIXELS_PER_PACKET_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_PIXELS_PER_PACKET_CFG_VID_PIXELS_PER_PACKET_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_PIXELS_PER_PACKET_CFG_VID_PIXELS_PER_PACKET(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_PIXELS_PER_PACKET_CFG_VID_PIXELS_PER_PACKET_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_PIXELS_PER_PACKET_CFG_VID_PIXELS_PER_PACKET_MASK)
/*! @} */

/*! @name CFG_VID_PIXEL_PAYLOAD_SIZE - Video Pixel Payload Size */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_PIXEL_PAYLOAD_SIZE_CFG_VID_PIXEL_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_PIXEL_PAYLOAD_SIZE_CFG_VID_PIXEL_PAYLOAD_SIZE_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_PIXEL_PAYLOAD_SIZE_CFG_VID_PIXEL_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_PIXEL_PAYLOAD_SIZE_CFG_VID_PIXEL_PAYLOAD_SIZE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_PIXEL_PAYLOAD_SIZE_CFG_VID_PIXEL_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_VID_START_DELAY - Video Start Delay */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_START_DELAY_CFG_VID_START_DELAY_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_START_DELAY_CFG_VID_START_DELAY_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_START_DELAY_CFG_VID_START_DELAY(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_START_DELAY_CFG_VID_START_DELAY_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_START_DELAY_CFG_VID_START_DELAY_MASK)
/*! @} */

/*! @name CFG_VID_HFP - Video Horizontal Sync Front Porch Time */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_HFP_CFG_VID_HFP_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_HFP_CFG_VID_HFP_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_HFP_CFG_VID_HFP(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_HFP_CFG_VID_HFP_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_HFP_CFG_VID_HFP_MASK)
/*! @} */

/*! @name CFG_VID_HBP - Video Horizontal Sync Back Porch Time */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_HBP_CFG_VID_HBP_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_HBP_CFG_VID_HBP_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_HBP_CFG_VID_HBP(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_HBP_CFG_VID_HBP_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_HBP_CFG_VID_HBP_MASK)
/*! @} */

/*! @name CFG_VID_HSA - Video Horizontal Sync Active Time */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_HSA_CFG_VID_HSA_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_HSA_CFG_VID_HSA_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_HSA_CFG_VID_HSA(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_HSA_CFG_VID_HSA_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_HSA_CFG_VID_HSA_MASK)
/*! @} */

/*! @name CFG_VID_VBP - Video Vertical Sync Back Porch Time */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_VBP_CFG_VID_VBP_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_VBP_CFG_VID_VBP_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_VBP_CFG_VID_VBP(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_VBP_CFG_VID_VBP_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_VBP_CFG_VID_VBP_MASK)
/*! @} */

/*! @name CFG_VID_VFP - Video Vertical Sync Front Porch Time */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_VFP_CFG_VID_VFP_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_VFP_CFG_VID_VFP_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_VFP_CFG_VID_VFP(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_VFP_CFG_VID_VFP_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_VFP_CFG_VID_VFP_MASK)
/*! @} */

/*! @name CFG_VID_VACTIVE - Video Vertical Sync Active Time */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_VACTIVE_CFG_VID_VACTIVE_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_VACTIVE_CFG_VID_VACTIVE_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_VACTIVE_CFG_VID_VACTIVE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_VACTIVE_CFG_VID_VACTIVE_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_VACTIVE_CFG_VID_VACTIVE_MASK)
/*! @} */

/*! @name CFG_VID_VSS_PAYLOAD - Video Vertical Sync Start Payload */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_VSS_PAYLOAD_CFG_VID_VSS_PAYLOAD_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_VSS_PAYLOAD_CFG_VID_VSS_PAYLOAD_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_VSS_PAYLOAD_CFG_VID_VSS_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_VSS_PAYLOAD_CFG_VID_VSS_PAYLOAD_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_VSS_PAYLOAD_CFG_VID_VSS_PAYLOAD_MASK)
/*! @} */

/*! @name CFG_VID_PAYLOAD_PER_PACKET - Video Payload Per Packet */
/*! @{ */

#define DSI2_HOST_VID_IF_CFG_VID_PAYLOAD_PER_PACKET_CFG_VID_PAYLOAD_PER_PACKET_MASK (0xFFFFU)
#define DSI2_HOST_VID_IF_CFG_VID_PAYLOAD_PER_PACKET_CFG_VID_PAYLOAD_PER_PACKET_SHIFT (0U)
#define DSI2_HOST_VID_IF_CFG_VID_PAYLOAD_PER_PACKET_CFG_VID_PAYLOAD_PER_PACKET(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_CFG_VID_PAYLOAD_PER_PACKET_CFG_VID_PAYLOAD_PER_PACKET_SHIFT)) & DSI2_HOST_VID_IF_CFG_VID_PAYLOAD_PER_PACKET_CFG_VID_PAYLOAD_PER_PACKET_MASK)
/*! @} */

/*! @name VID_IRQ_STATUS - Video Interrupt Request Status */
/*! @{ */

#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_BLANKING_ERR_MASK (0x100U)
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_BLANKING_ERR_SHIFT (8U)
/*! vid_blanking_err - Blanking Error */
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_BLANKING_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_BLANKING_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_BLANKING_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_UNDERFLOW_ERR_MASK (0x200U)
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_UNDERFLOW_ERR_SHIFT (9U)
/*! vid_fifo_underflow_err - FIFO Underflow Error */
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_UNDERFLOW_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_UNDERFLOW_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_UNDERFLOW_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_OVERFLOW_ERR_MASK (0x400U)
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_OVERFLOW_ERR_SHIFT (10U)
/*! vid_fifo_overflow_err - FIFO Overflow Error */
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_OVERFLOW_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_OVERFLOW_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_FIFO_OVERFLOW_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_WHEN_ACTIVE_ERR_MASK (0x800U)
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_WHEN_ACTIVE_ERR_SHIFT (11U)
/*! vid_sync_when_active_err - Sync When Video Active Error */
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_WHEN_ACTIVE_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_WHEN_ACTIVE_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_WHEN_ACTIVE_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_PULSE_ERR_MASK (0x1000U)
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_PULSE_ERR_SHIFT (12U)
/*! vid_sync_pulse_err - Sync Pulse Error */
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_PULSE_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_PULSE_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_SYNC_PULSE_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_CSR_PARITY_ERR_MASK (0x80000000U)
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_CSR_PARITY_ERR_SHIFT (31U)
/*! vid_csr_parity_err - VID CSR Parity Error within DSI2 HOST VID IF Device */
#define DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_CSR_PARITY_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_CSR_PARITY_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_STATUS_VID_CSR_PARITY_ERR_MASK)
/*! @} */

/*! @name VID_IRQ_MASK - Video Interrupt Request Mask */
/*! @{ */

#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_BLANKING_ERR_MASK (0x100U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_BLANKING_ERR_SHIFT (8U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_BLANKING_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_BLANKING_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_BLANKING_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_UNDERFLOW_ERR_MASK (0x200U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_UNDERFLOW_ERR_SHIFT (9U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_UNDERFLOW_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_UNDERFLOW_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_UNDERFLOW_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_OVERFLOW_ERR_MASK (0x400U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_OVERFLOW_ERR_SHIFT (10U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_OVERFLOW_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_OVERFLOW_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_FIFO_OVERFLOW_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_WHEN_ACTIVE_ERR_MASK (0x800U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_WHEN_ACTIVE_ERR_SHIFT (11U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_WHEN_ACTIVE_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_WHEN_ACTIVE_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_WHEN_ACTIVE_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_PULSE_ERR_MASK (0x1000U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_PULSE_ERR_SHIFT (12U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_PULSE_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_PULSE_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_SYNC_PULSE_ERR_MASK)

#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_CSR_PARITY_ERR_MASK (0x80000000U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_CSR_PARITY_ERR_SHIFT (31U)
#define DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_CSR_PARITY_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_CSR_PARITY_ERR_SHIFT)) & DSI2_HOST_VID_IF_VID_IRQ_MASK_VID_MASK_CSR_PARITY_ERR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI2_HOST_VID_IF_Register_Masks */


/*!
 * @}
 */ /* end of group DSI2_HOST_VID_IF_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI2_HOST_VID_IF_H_ */

