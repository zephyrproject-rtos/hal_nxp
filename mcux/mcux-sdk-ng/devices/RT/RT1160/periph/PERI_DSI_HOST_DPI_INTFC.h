/*
** ###################################################################
**     Processors:          MIMXRT1165CVM5A_cm4
**                          MIMXRT1165CVM5A_cm7
**                          MIMXRT1165DVM6A_cm4
**                          MIMXRT1165DVM6A_cm7
**                          MIMXRT1165XVM5A_cm4
**                          MIMXRT1165XVM5A_cm7
**                          MIMXRT1166CVM5A_cm4
**                          MIMXRT1166CVM5A_cm7
**                          MIMXRT1166DVM6A_cm4
**                          MIMXRT1166DVM6A_cm7
**                          MIMXRT1166XVM5A_cm4
**                          MIMXRT1166XVM5A_cm7
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSI_HOST_DPI_INTFC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-29)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DSI_HOST_DPI_INTFC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DSI_HOST_DPI_INTFC
 *
 * CMSIS Peripheral Access Layer for DSI_HOST_DPI_INTFC
 */

#if !defined(PERI_DSI_HOST_DPI_INTFC_H_)
#define PERI_DSI_HOST_DPI_INTFC_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1165CVM5A_cm4) || defined(CPU_MIMXRT1165DVM6A_cm4) || defined(CPU_MIMXRT1165XVM5A_cm4))
#include "MIMXRT1165_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1165CVM5A_cm7) || defined(CPU_MIMXRT1165DVM6A_cm7) || defined(CPU_MIMXRT1165XVM5A_cm7))
#include "MIMXRT1165_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm4) || defined(CPU_MIMXRT1166DVM6A_cm4) || defined(CPU_MIMXRT1166XVM5A_cm4))
#include "MIMXRT1166_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm7) || defined(CPU_MIMXRT1166DVM6A_cm7) || defined(CPU_MIMXRT1166XVM5A_cm7))
#include "MIMXRT1166_cm7_COMMON.h"
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
  __IO uint32_t PIXEL_PAYLOAD_SIZE;                /**< PEXEL_PAYLOAD_SIZE, offset: 0x0 */
  __IO uint32_t PIXEL_FIFO_SEND_LEVEL;             /**< PIXEL_FIFO_SEND_LEVEL, offset: 0x4 */
  __IO uint32_t INTERFACE_COLOR_CODING;            /**< INTERFACE_COLOR_CODING, offset: 0x8 */
  __IO uint32_t PIXEL_FORMAT;                      /**< PIXEL_FORMAT, offset: 0xC */
  __IO uint32_t VSYNC_POLARITY;                    /**< VSYNC_POLARITY, offset: 0x10 */
  __IO uint32_t HSYNC_POLARITY;                    /**< HSYNC_POLARITY, offset: 0x14 */
  __IO uint32_t VIDEO_MODE;                        /**< VIDEO_MODE, offset: 0x18 */
  __IO uint32_t HFP;                               /**< HFP, offset: 0x1C */
  __IO uint32_t HBP;                               /**< HBP, offset: 0x20 */
  __IO uint32_t HSA;                               /**< HSA, offset: 0x24 */
  __IO uint32_t ENABLE_MULT_PKTS;                  /**< ENABLE_MULT_PKTS, offset: 0x28 */
  __IO uint32_t VBP;                               /**< VBP, offset: 0x2C */
  __IO uint32_t VFP;                               /**< VFP, offset: 0x30 */
  __IO uint32_t BLLP_MODE;                         /**< BLLP_MODE, offset: 0x34 */
  __IO uint32_t USE_NULL_PKT_BLLP;                 /**< USE_NULL_PKT_BLLP, offset: 0x38 */
  __IO uint32_t VACTIVE;                           /**< VACTIVE, offset: 0x3C */
} DSI_HOST_DPI_INTFC_Type;

/* ----------------------------------------------------------------------------
   -- DSI_HOST_DPI_INTFC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_DPI_INTFC_Register_Masks DSI_HOST_DPI_INTFC Register Masks
 * @{
 */

/*! @name PIXEL_PAYLOAD_SIZE - PEXEL_PAYLOAD_SIZE */
/*! @{ */

#define DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Maximum number of pixels that should be sent as one DSI packet. Recommended to be
 *    evenly divisible by the line size (in pixels).
 */
#define DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name PIXEL_FIFO_SEND_LEVEL - PIXEL_FIFO_SEND_LEVEL */
/*! @{ */

#define DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! FIFO_SEND_LEVEL - In order to optimize DSI utility, the DPI bridge buffers a certain number of
 *    DPI pixels before initiating a DSI packet. This configuration port controls the level at which
 *    the DPI Host bridge begins sending pixels.
 */
#define DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT)) & DSI_HOST_DPI_INTFC_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name INTERFACE_COLOR_CODING - INTERFACE_COLOR_CODING */
/*! @{ */

#define DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_MASK (0x7U)
#define DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_SHIFT (0U)
/*! RGB_CONFIG - Sets the distribution of RGB bits within the 24-bit d bus, as specified by the DPI specification.
 *  0b000..16-bit Configuration 1
 *  0b001..16-bit Configuration 2
 *  0b010..16-bit Configuration 3
 *  0b011..18-bit Configuration 1
 *  0b100..18-bit Configuration 2
 *  0b101..24-bit
 *  0b110, 0b111..Reserved
 */
#define DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_SHIFT)) & DSI_HOST_DPI_INTFC_INTERFACE_COLOR_CODING_RGB_CONFIG_MASK)
/*! @} */

/*! @name PIXEL_FORMAT - PIXEL_FORMAT */
/*! @{ */

#define DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_MASK (0x3U)
#define DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_SHIFT (0U)
/*! PIXEL_FORMAT - Sets the DSI packet type of the pixels
 *  0b00..16 bit
 *  0b01..18 bit
 *  0b10..18 bit loosely packed
 *  0b11..24 bit
 */
#define DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_SHIFT)) & DSI_HOST_DPI_INTFC_PIXEL_FORMAT_PIXEL_FORMAT_MASK)
/*! @} */

/*! @name VSYNC_POLARITY - VSYNC_POLARITY */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_SHIFT (0U)
/*! VSYNC_POLARITY - Sets polarity of dpi_vsync_input
 *  0b0..active low
 *  0b1..active high
 */
#define DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_SHIFT)) & DSI_HOST_DPI_INTFC_VSYNC_POLARITY_VSYNC_POLARITY_MASK)
/*! @} */

/*! @name HSYNC_POLARITY - HSYNC_POLARITY */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_SHIFT (0U)
/*! HSYNC_POLARITY - Sets polarity of dpi_hsync_input
 *  0b0..active low
 *  0b1..active high
 */
#define DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_SHIFT)) & DSI_HOST_DPI_INTFC_HSYNC_POLARITY_HSYNC_POLARITY_MASK)
/*! @} */

/*! @name VIDEO_MODE - VIDEO_MODE */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_MASK (0x3U)
#define DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_SHIFT (0U)
/*! VIDEO_MODE - Select DSI video mode that the host DPI module should generate packets for.
 *  0b00..Non-Burst mode with Sync Pulses
 *  0b01..Non-Burst mode with Sync Events
 *  0b10..Burst mode
 *  0b11..Reserved, not valid
 */
#define DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_SHIFT)) & DSI_HOST_DPI_INTFC_VIDEO_MODE_VIDEO_MODE_MASK)
/*! @} */

/*! @name HFP - HFP */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Sets the DSI packet payload size, in bytes, of the horizontal front porch blanking packet. */
#define DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_HFP_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name HBP - HBP */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Sets the DSI packet payload size, in bytes, of the horizontal back porch blanking packet. */
#define DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_HBP_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name HSA - HSA */
/*! @{ */

#define DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Sets the DSI packet payload size, in bytes, of the horizontal sync width filler blanking packet. */
#define DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_SHIFT)) & DSI_HOST_DPI_INTFC_HSA_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name ENABLE_MULT_PKTS - ENABLE_MULT_PKTS */
/*! @{ */

#define DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_SHIFT (0U)
/*! ENABLE_MULT_PKTS - Enable Multiple packets per video line. When enabled,
 *    PIXEL_PAYLOAD_SIZE[PAYLOAD_SIZE] must be set to exactly half the size of the video line
 *  0b0..Video Line is sent in a single packet
 *  0b1..Video Line is sent in two packets
 */
#define DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_SHIFT)) & DSI_HOST_DPI_INTFC_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_MASK)
/*! @} */

/*! @name VBP - VBP */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VBP_NUM_LINES_MASK    (0xFFU)
#define DSI_HOST_DPI_INTFC_VBP_NUM_LINES_SHIFT   (0U)
/*! NUM_LINES - Sets the number of lines in the vertical back porch. */
#define DSI_HOST_DPI_INTFC_VBP_NUM_LINES(x)      (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VBP_NUM_LINES_SHIFT)) & DSI_HOST_DPI_INTFC_VBP_NUM_LINES_MASK)
/*! @} */

/*! @name VFP - VFP */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VFP_NUM_LINES_MASK    (0xFFU)
#define DSI_HOST_DPI_INTFC_VFP_NUM_LINES_SHIFT   (0U)
/*! NUM_LINES - Sets the number of lines in the vertical front porch. */
#define DSI_HOST_DPI_INTFC_VFP_NUM_LINES(x)      (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_VFP_NUM_LINES_SHIFT)) & DSI_HOST_DPI_INTFC_VFP_NUM_LINES_MASK)
/*! @} */

/*! @name BLLP_MODE - BLLP_MODE */
/*! @{ */

#define DSI_HOST_DPI_INTFC_BLLP_MODE_LP_MASK     (0x1U)
#define DSI_HOST_DPI_INTFC_BLLP_MODE_LP_SHIFT    (0U)
/*! LP - Optimize bllp periods to Low Power mode when possible
 *  0b0..Blanking packets are sent during BLLP periods
 *  0b1..LP mode is used for BLLP periods
 */
#define DSI_HOST_DPI_INTFC_BLLP_MODE_LP(x)       (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_BLLP_MODE_LP_SHIFT)) & DSI_HOST_DPI_INTFC_BLLP_MODE_LP_MASK)
/*! @} */

/*! @name USE_NULL_PKT_BLLP - USE_NULL_PKT_BLLP */
/*! @{ */

#define DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_MASK (0x1U)
#define DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_SHIFT (0U)
/*! NULL - Selects type of blanking packet to be sent during bllp
 *  0b0..Blanking packet used in bllp region 1
 *  0b1..Null packet used in bllp region
 */
#define DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_SHIFT)) & DSI_HOST_DPI_INTFC_USE_NULL_PKT_BLLP_NULL_MASK)
/*! @} */

/*! @name VACTIVE - VACTIVE */
/*! @{ */

#define DSI_HOST_DPI_INTFC_VACTIVE_NUM_LINES_MASK (0x3FFFU)
#define DSI_HOST_DPI_INTFC_VACTIVE_NUM_LINES_SHIFT (0U)
/*! NUM_LINES - Sets the number of lines in the vertical active aread. */
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

