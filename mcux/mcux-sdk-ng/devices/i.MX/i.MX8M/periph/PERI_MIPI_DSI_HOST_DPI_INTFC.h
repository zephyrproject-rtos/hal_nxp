/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIPI_DSI_HOST_DPI_INTFC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_DSI_HOST_DPI_INTFC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI_HOST_DPI_INTFC
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI_HOST_DPI_INTFC
 */

#if !defined(PERI_MIPI_DSI_HOST_DPI_INTFC_H_)
#define PERI_MIPI_DSI_HOST_DPI_INTFC_H_          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- MIPI_DSI_HOST_DPI_INTFC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_DPI_INTFC_Peripheral_Access_Layer MIPI_DSI_HOST_DPI_INTFC Peripheral Access Layer
 * @{
 */

/** MIPI_DSI_HOST_DPI_INTFC - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE; /**< offset: 0x0 */
  __IO uint32_t DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL; /**< offset: 0x4 */
  __IO uint32_t DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING; /**< offset: 0x8 */
  __IO uint32_t DSI_HOST_CFG_DPI_PIXEL_FORMAT;     /**< offset: 0xC */
  __IO uint32_t DSI_HOST_CFG_DPI_VSYNC_POLARITY;   /**< offset: 0x10 */
  __IO uint32_t DSI_HOST_CFG_DPI_HSYNC_POLARITY;   /**< offset: 0x14 */
  __IO uint32_t DSI_HOST_CFG_DPI_VIDEO_MODE;       /**< offset: 0x18 */
  __IO uint32_t DSI_HOST_CFG_DPI_HFP;              /**< offset: 0x1C */
  __IO uint32_t DSI_HOST_CFG_DPI_HBP;              /**< offset: 0x20 */
  __IO uint32_t DSI_HOST_CFG_DPI_HSA;              /**< offset: 0x24 */
  __IO uint32_t DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS; /**< offset: 0x28 */
  __IO uint32_t DSI_HOST_CFG_DPI_VBP;              /**< offset: 0x2C */
  __IO uint32_t DSI_HOST_CFG_DPI_VFP;              /**< offset: 0x30 */
  __IO uint32_t DSI_HOST_CFG_DPI_BLLP_MODE;        /**< offset: 0x34 */
  __IO uint32_t DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP; /**< offset: 0x38 */
  __IO uint32_t DSI_HOST_CFG_DPI_VACTIVE;          /**< offset: 0x3C */
  __IO uint32_t DSI_HOST_CFG_DPI_VC;               /**< offset: 0x40 */
} MIPI_DSI_HOST_DPI_INTFC_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI_HOST_DPI_INTFC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_DPI_INTFC_Register_Masks MIPI_DSI_HOST_DPI_INTFC Register Masks
 * @{
 */

/*! @name DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_dsi_host_cfg_dpi_pixel_payload_size_MASK (0xFFFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_dsi_host_cfg_dpi_pixel_payload_size_SHIFT (0U)
/*! dsi_host_cfg_dpi_pixel_payload_size - Maximum number of pixels that should be sent as one DSI
 *    packet. Recommended that the line size (in pixels) is evenly divisible by this parameter (packet
 *    payload size in pixels).
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_dsi_host_cfg_dpi_pixel_payload_size(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_dsi_host_cfg_dpi_pixel_payload_size_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_dsi_host_cfg_dpi_pixel_payload_size_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_dsi_host_cfg_dpi_pixel_fifo_send_level_MASK (0xFFFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_dsi_host_cfg_dpi_pixel_fifo_send_level_SHIFT (0U)
/*! dsi_host_cfg_dpi_pixel_fifo_send_level - In order to optimize DSI utility, the DPI bridge
 *    buffers a cerntain number of DPI pixels before initiating a DSI packet. This configuration port
 *    controls the level at which the DPI Host bridge begins sending pixels.
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_dsi_host_cfg_dpi_pixel_fifo_send_level(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_dsi_host_cfg_dpi_pixel_fifo_send_level_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_dsi_host_cfg_dpi_pixel_fifo_send_level_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_dsi_host_cfg_dpi_interface_color_coding_MASK (0x7U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_dsi_host_cfg_dpi_interface_color_coding_SHIFT (0U)
/*! dsi_host_cfg_dpi_interface_color_coding - Sets the distribution of RGB bits within the 24-bit d
 *    bus, as specified by the DPI specification. 0= 16-bit Configuration 1 1= 16-bit Configuration
 *    2 2= 16-bit Configuration 3 3= 18-bit Configuration 1 4= 18-bit Configuration 2 5= 24-bit
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_dsi_host_cfg_dpi_interface_color_coding(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_dsi_host_cfg_dpi_interface_color_coding_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_dsi_host_cfg_dpi_interface_color_coding_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_PIXEL_FORMAT -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FORMAT_dsi_host_cfg_dpi_pixel_format_MASK (0x3U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FORMAT_dsi_host_cfg_dpi_pixel_format_SHIFT (0U)
/*! dsi_host_cfg_dpi_pixel_format - Sets the DSI packet type of the pixels. 0 - 16 bit 1 - 18 bit 2 - 18 bit loosely packed 3 - 24 bit */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FORMAT_dsi_host_cfg_dpi_pixel_format(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FORMAT_dsi_host_cfg_dpi_pixel_format_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_PIXEL_FORMAT_dsi_host_cfg_dpi_pixel_format_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_VSYNC_POLARITY -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VSYNC_POLARITY_dsi_host_cfg_dpi_vsync_polarity_MASK (0x1U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VSYNC_POLARITY_dsi_host_cfg_dpi_vsync_polarity_SHIFT (0U)
/*! dsi_host_cfg_dpi_vsync_polarity - Sets polarity of dpi_vsync_input 0 - active low 1 - active high */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VSYNC_POLARITY_dsi_host_cfg_dpi_vsync_polarity(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VSYNC_POLARITY_dsi_host_cfg_dpi_vsync_polarity_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VSYNC_POLARITY_dsi_host_cfg_dpi_vsync_polarity_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_HSYNC_POLARITY -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSYNC_POLARITY_dsi_host_cfg_dpi_hsync_polarity_MASK (0x1U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSYNC_POLARITY_dsi_host_cfg_dpi_hsync_polarity_SHIFT (0U)
/*! dsi_host_cfg_dpi_hsync_polarity - Sets polarity of dpi_hsync_input 0 - active low 1 - active high */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSYNC_POLARITY_dsi_host_cfg_dpi_hsync_polarity(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSYNC_POLARITY_dsi_host_cfg_dpi_hsync_polarity_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSYNC_POLARITY_dsi_host_cfg_dpi_hsync_polarity_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_VIDEO_MODE -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VIDEO_MODE_dsi_host_cfg_dpi_video_mode_MASK (0x3U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VIDEO_MODE_dsi_host_cfg_dpi_video_mode_SHIFT (0U)
/*! dsi_host_cfg_dpi_video_mode - Select DSI video mode that the host DPI module should generate
 *    packets for. 2'b00 - Non-Burst mode with Sync Pulses 2'b01 - Non-Burst mode with Sync Events
 *    2'b10 - Burst mode 2'b11 - Reserved, not valid
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VIDEO_MODE_dsi_host_cfg_dpi_video_mode(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VIDEO_MODE_dsi_host_cfg_dpi_video_mode_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VIDEO_MODE_dsi_host_cfg_dpi_video_mode_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_HFP -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HFP_dsi_host_cfg_dpi_hfp_MASK (0xFFFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HFP_dsi_host_cfg_dpi_hfp_SHIFT (0U)
/*! dsi_host_cfg_dpi_hfp - Sets the DSI packet payload size, in bytes, of the horizontal front porch blanking packet. */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HFP_dsi_host_cfg_dpi_hfp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HFP_dsi_host_cfg_dpi_hfp_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HFP_dsi_host_cfg_dpi_hfp_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_HBP -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HBP_dsi_host_cfg_dpi_hbp_MASK (0xFFFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HBP_dsi_host_cfg_dpi_hbp_SHIFT (0U)
/*! dsi_host_cfg_dpi_hbp - Sets the DSI packet payload size, in bytes, of the horizontal back porch blanking packet. */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HBP_dsi_host_cfg_dpi_hbp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HBP_dsi_host_cfg_dpi_hbp_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HBP_dsi_host_cfg_dpi_hbp_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_HSA -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSA_dsi_host_cfg_dpi_hsa_MASK (0xFFFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSA_dsi_host_cfg_dpi_hsa_SHIFT (0U)
/*! dsi_host_cfg_dpi_hsa - Sets the DSI packet payload size, in bytes, of the horizontal sync width filler blanking packet. */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSA_dsi_host_cfg_dpi_hsa(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSA_dsi_host_cfg_dpi_hsa_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_HSA_dsi_host_cfg_dpi_hsa_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_dsi_host_cfg_dpi_enable_mult_pkts_MASK (0x1U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_dsi_host_cfg_dpi_enable_mult_pkts_SHIFT (0U)
/*! dsi_host_cfg_dpi_enable_mult_pkts - Enable Multiple packets per video line. When enabled,
 *    cfg_dpi_pixel_payload_size must be set to exactly half the size of the video line. 0 - Video Line is
 *    sent in a single packet 1 - Video Line is sent in two packets
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_dsi_host_cfg_dpi_enable_mult_pkts(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_dsi_host_cfg_dpi_enable_mult_pkts_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_dsi_host_cfg_dpi_enable_mult_pkts_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_VBP -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VBP_dsi_host_cfg_dpi_vbp_MASK (0xFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VBP_dsi_host_cfg_dpi_vbp_SHIFT (0U)
/*! dsi_host_cfg_dpi_vbp - Sets the number of lines in the vertical back porch. */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VBP_dsi_host_cfg_dpi_vbp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VBP_dsi_host_cfg_dpi_vbp_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VBP_dsi_host_cfg_dpi_vbp_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_VFP -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VFP_dsi_host_cfg_dpi_vfp_MASK (0xFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VFP_dsi_host_cfg_dpi_vfp_SHIFT (0U)
/*! dsi_host_cfg_dpi_vfp - Sets the number of lines in the vertical front porch. */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VFP_dsi_host_cfg_dpi_vfp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VFP_dsi_host_cfg_dpi_vfp_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VFP_dsi_host_cfg_dpi_vfp_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_BLLP_MODE -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_BLLP_MODE_dsi_host_cfg_dpi_bllp_mode_MASK (0x1U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_BLLP_MODE_dsi_host_cfg_dpi_bllp_mode_SHIFT (0U)
/*! dsi_host_cfg_dpi_bllp_mode - Optimize bllp periods to Low Power mode when possible 0 - blanking
 *    packets are sent during BLLP periods 1 - LP mode is used for BLLP periods
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_BLLP_MODE_dsi_host_cfg_dpi_bllp_mode(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_BLLP_MODE_dsi_host_cfg_dpi_bllp_mode_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_BLLP_MODE_dsi_host_cfg_dpi_bllp_mode_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_dsi_host_cfg_dpi_use_null_pkt_bllp_MASK (0x1U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_dsi_host_cfg_dpi_use_null_pkt_bllp_SHIFT (0U)
/*! dsi_host_cfg_dpi_use_null_pkt_bllp - Selects type of blanking packet to be sent during bllp
 *    region 0 - Blanking packet used in bllp region 1 - Null packet used in bllp region
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_dsi_host_cfg_dpi_use_null_pkt_bllp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_dsi_host_cfg_dpi_use_null_pkt_bllp_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_dsi_host_cfg_dpi_use_null_pkt_bllp_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_VACTIVE -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VACTIVE_dsi_host_cfg_dpi_vactive_MASK (0x3FFFU)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VACTIVE_dsi_host_cfg_dpi_vactive_SHIFT (0U)
/*! dsi_host_cfg_dpi_vactive - Sets the number of lines in the vertical active area. This field is
 *    equivalent to (real vertical size) - 1. For example, for an image of size 640x480, the bit
 *    field should be set as 479.
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VACTIVE_dsi_host_cfg_dpi_vactive(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VACTIVE_dsi_host_cfg_dpi_vactive_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VACTIVE_dsi_host_cfg_dpi_vactive_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_DPI_VC -  */
/*! @{ */

#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VC_dsi_host_cfg_dpi_vc_MASK (0x3U)
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VC_dsi_host_cfg_dpi_vc_SHIFT (0U)
/*! dsi_host_cfg_dpi_vc - Sets the Virtual Channel (VC) of packets that will be sent to the receive
 *    packet interface. Packets with VC not equal to this value are discarded and the "DSI VC ID
 *    Invalid" bit (bit 12) in the DSI error report is set.
 */
#define MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VC_dsi_host_cfg_dpi_vc(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VC_dsi_host_cfg_dpi_vc_SHIFT)) & MIPI_DSI_HOST_DPI_INTFC_DSI_HOST_CFG_DPI_VC_dsi_host_cfg_dpi_vc_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_DPI_INTFC_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_DPI_INTFC_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_DSI_HOST_DPI_INTFC_H_ */

