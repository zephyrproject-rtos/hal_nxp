/*
** ###################################################################
**     Processors:          MIMXRT1151DHM8B
**                          MIMXRT1151DVM8B
**                          MIMXRT1151XHM8B
**                          MIMXRT1151XVM8B
**                          MIMXRT1152AHM6B
**                          MIMXRT1152AVM6B
**                          MIMXRT1152DHM8B
**                          MIMXRT1152DVM8B
**                          MIMXRT1152XHM8B
**                          MIMXRT1152XVM8B
**
**     Version:             rev. 0.2, 2026-02-26
**     Build:               b260622
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSI_HOST_DPI_INTFC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2026-01-09)
**         Initial version.
**     - rev. 0.2 (2026-02-26)
**         Update header file based on RM Rev1.
**
** ###################################################################
*/

/*!
 * @file PERI_DSI_HOST_DPI_INTFC.h
 * @version 0.2
 * @date 2026-02-26
 * @brief CMSIS Peripheral Access Layer for DSI_HOST_DPI_INTFC
 *
 * CMSIS Peripheral Access Layer for DSI_HOST_DPI_INTFC
 */

#if !defined(PERI_DSI_HOST_DPI_INTFC_H_)
#define PERI_DSI_HOST_DPI_INTFC_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1151DHM8B) || defined(CPU_MIMXRT1151DVM8B) || defined(CPU_MIMXRT1151XHM8B) || defined(CPU_MIMXRT1151XVM8B))
#include "MIMXRT1151_COMMON.h"
#elif (defined(CPU_MIMXRT1152AHM6B) || defined(CPU_MIMXRT1152AVM6B) || defined(CPU_MIMXRT1152DHM8B) || defined(CPU_MIMXRT1152DVM8B) || defined(CPU_MIMXRT1152XHM8B) || defined(CPU_MIMXRT1152XVM8B))
#include "MIMXRT1152_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DSI_HOST_DPI_INTFC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_DPI_INTFC_Peripheral_Access_Layer DSI_HOST_DPI_INTFC Peripheral Access Layer
 * @{
 */

/** DSI_HOST_DPI_INTFC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIXEL_PAYLOAD_SIZE;                /**< Pixel Payload Size, offset: 0x0 */
  __IO uint32_t PIXEL_FIFO_SEND_LEVEL;             /**< Pixel FIFO Send Level, offset: 0x4 */
  __IO uint32_t INTERFACE_COLOR_CODING;            /**< Interface Color Coding, offset: 0x8 */
  __IO uint32_t PIXEL_FORMAT;                      /**< Pixel Format, offset: 0xC */
  __IO uint32_t VSYNC_POLARITY;                    /**< Vertical Sync Polarity, offset: 0x10 */
  __IO uint32_t HSYNC_POLARITY;                    /**< Horizontal Polarity, offset: 0x14 */
  __IO uint32_t VIDEO_MODE;                        /**< Video Mode, offset: 0x18 */
  __IO uint32_t HFP;                               /**< Horizontal Front Porch, offset: 0x1C */
  __IO uint32_t HBP;                               /**< Vertical Front Porch, offset: 0x20 */
  __IO uint32_t HSA;                               /**< Horizontal SYNC Blanking Packet Size, offset: 0x24 */
  __IO uint32_t ENABLE_MULT_PKTS;                  /**< Enable Multiple Packets, offset: 0x28 */
  __IO uint32_t VBP;                               /**< Vertical Back Porch, offset: 0x2C */
  __IO uint32_t VFP;                               /**< Vertical Front Porch, offset: 0x30 */
  __IO uint32_t BLLP_MODE;                         /**< BLLP Mode, offset: 0x34 */
  __IO uint32_t USE_NULL_PKT_BLLP;                 /**< Use Null Packet BLLP, offset: 0x38 */
  __IO uint32_t VACTIVE;                           /**< Vertical Active, offset: 0x3C */
} DSI_HOST_DPI_INTFC_Type;

/* ----------------------------------------------------------------------------
   -- DSI_HOST_DPI_INTFC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_DPI_INTFC_Register_Masks DSI_HOST_DPI_INTFC Register Masks
 * @{
 */

/*! @name PIXEL_PAYLOAD_SIZE - Pixel Payload Size */
/*! @{ */

#define DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Payload Size (in pixels). */
#define DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name PIXEL_FIFO_SEND_LEVEL - Pixel FIFO Send Level */
/*! @{ */

#define DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! FIFO_SEND_LEVEL - FIFO Send Level */
#define DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT)) & DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name INTERFACE_COLOR_CODING - Interface Color Coding */
/*! @{ */

#define DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_MASK (0x7U)
#define DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_SHIFT (0U)
/*! RGB_CONFIG - RGB Bit Configuration.
 *  0b000..16-bit Configuration 1
 *  0b001..16-bit Configuration 2
 *  0b010..16-bit Configuration 3
 *  0b011..18-bit Configuration 1
 *  0b100..18-bit Configuration 2
 *  0b101..24-bit
 *  0b110, 0b111..
 */
#define DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_SHIFT)) & DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_MASK)
/*! @} */

/*! @name PIXEL_FORMAT - Pixel Format */
/*! @{ */

#define DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_MASK (0x3U)
#define DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_SHIFT (0U)
/*! PIXEL_FORMAT - Pixel Format
 *  0b00..16 bit
 *  0b01..18 bit
 *  0b10..18 bit loosely packed
 *  0b11..24 bit
 */
#define DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_SHIFT)) & DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_MASK)
/*! @} */

/*! @name VSYNC_POLARITY - Vertical Sync Polarity */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_SHIFT (0U)
/*! VSYNC_POLARITY - VSYNC Polarity
 *  0b0..Active low
 *  0b1..Active high
 */
#define DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_SHIFT)) & DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_MASK)
/*! @} */

/*! @name HSYNC_POLARITY - Horizontal Polarity */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_SHIFT (0U)
/*! HSYNC_POLARITY - HSYNC Polarity
 *  0b0..Active low
 *  0b1..Active high
 */
#define DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_SHIFT)) & DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_MASK)
/*! @} */

/*! @name VIDEO_MODE - Video Mode */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_MASK (0x3U)
#define DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_SHIFT (0U)
/*! VIDEO_MODE - Video Mode
 *  0b00..Non-Burst mode with Sync Pulses
 *  0b01..Non-Burst mode with Sync Events
 *  0b10..Burst mode
 *  0b11..Reserved, not valid
 */
#define DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_SHIFT)) & DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_MASK)
/*! @} */

/*! @name HFP - Horizontal Front Porch */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Payload Size */
#define DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name HBP - Vertical Front Porch */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Payload Size */
#define DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name HSA - Horizontal SYNC Blanking Packet Size */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Payload Size */
#define DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name ENABLE_MULT_PKTS - Enable Multiple Packets */
/*! @{ */

#define DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_SHIFT (0U)
/*! ENABLE_MULT_PKTS - Enable Multiple Packets
 *  0b0..Video Line is sent in a single packet
 *  0b1..Video Line is sent in two packets
 */
#define DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_SHIFT)) & DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_MASK)
/*! @} */

/*! @name VBP - Vertical Back Porch */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VBP_NUM_LINES_MASK    (0xFFU)
#define DSI_HOST_DPI_INTFC_VBP_NUM_LINES_SHIFT   (0U)
/*! NUM_LINES - Number of Lines */
#define DSI_HOST_DPI_INTFC_VBP_NUM_LINES(x)      (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VBP_NUM_LINES_SHIFT)) & DSI_HOST_DPI_INTFC_VBP_NUM_LINES_MASK)
/*! @} */

/*! @name VFP - Vertical Front Porch */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VFP_NUM_LINES_MASK    (0xFFU)
#define DSI_HOST_DPI_INTFC_VFP_NUM_LINES_SHIFT   (0U)
/*! NUM_LINES - Number of lines */
#define DSI_HOST_DPI_INTFC_VFP_NUM_LINES(x)      (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VFP_NUM_LINES_SHIFT)) & DSI_HOST_DPI_INTFC_VFP_NUM_LINES_MASK)
/*! @} */

/*! @name BLLP_MODE - BLLP Mode */
/*! @{ */

#define DSI_HOST_DPI_INTFC_BLLP_MODE_LP_MASK     (0x1U)
#define DSI_HOST_DPI_INTFC_BLLP_MODE_LP_SHIFT    (0U)
/*! LP - Low Power mode when possible.
 *  0b0..Blanking packets are sent during BLLP periods
 *  0b1..LP mode is used for BLLP periods
 */
#define DSI_HOST_DPI_INTFC_BLLP_MODE_LP(x)       (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_BLLP_MODE_LP_SHIFT)) & DSI_HOST_DPI_INTFC_BLLP_MODE_LP_MASK)
/*! @} */

/*! @name USE_NULL_PKT_BLLP - Use Null Packet BLLP */
/*! @{ */

#define DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_SHIFT (0U)
/*! NULL - Null
 *  0b0..Blanking packet used in bllp region 1
 *  0b1..Null packet used in bllp region
 */
#define DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_SHIFT)) & DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_MASK)
/*! @} */

/*! @name VACTIVE - Vertical Active */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VACTIVE_NUM_LINES_MASK (0x3FFFU)
#define DSI_HOST_DPI_INTFC_VACTIVE_NUM_LINES_SHIFT (0U)
/*! NUM_LINES - Number of lines */
#define DSI_HOST_DPI_INTFC_VACTIVE_NUM_LINES(x)  (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VACTIVE_NUM_LINES_SHIFT)) & DSI_HOST_DPI_INTFC_VACTIVE_NUM_LINES_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI_HOST_DPI_INTFC_Register_Masks */


/*!
 * @}
 */ /* end of group DSI_HOST_DPI_INTFC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_DSI_HOST_DPI_INTFC_H_ */

