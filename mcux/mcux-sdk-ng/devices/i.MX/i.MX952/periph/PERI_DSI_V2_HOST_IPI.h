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
**         CMSIS Peripheral Access Layer for DSI_V2_HOST_IPI
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
 * @file PERI_DSI_V2_HOST_IPI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DSI_V2_HOST_IPI
 *
 * CMSIS Peripheral Access Layer for DSI_V2_HOST_IPI
 */

#if !defined(PERI_DSI_V2_HOST_IPI_H_)
#define PERI_DSI_V2_HOST_IPI_H_                  /**< Symbol preventing repeated inclusion */

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
   -- DSI_V2_HOST_IPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_IPI_Peripheral_Access_Layer DSI_V2_HOST_IPI Peripheral Access Layer
 * @{
 */

/** DSI_V2_HOST_IPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t IPI_COLOR_MAN_CFG;                 /**< IPI Color Coding, offset: 0x0 */
  __IO uint32_t IPI_VID_HSA_MAN_CFG;               /**< HSA Timing (Manual), offset: 0x4 */
  __I  uint32_t IPI_VID_HSA_AUTO;                  /**< HSA Timing (Auto-mode), offset: 0x8 */
  __IO uint32_t IPI_VID_HBP_MAN_CFG;               /**< HBP Timing (Manual), offset: 0xC */
  __I  uint32_t IPI_VID_HBP_AUTO;                  /**< HBP Timing (Auto-mode), offset: 0x10 */
  __IO uint32_t IPI_VID_HACT_MAN_CFG;              /**< HACT Timing (Manual), offset: 0x14 */
  __I  uint32_t IPI_VID_HACT_AUTO;                 /**< HACT Timing (Auto-mode), offset: 0x18 */
  __IO uint32_t IPI_VID_HLINE_MAN_CFG;             /**< HLINE Timing (Manual), offset: 0x1C */
  __I  uint32_t IPI_VID_HLINE_AUTO;                /**< HLINE Timing (Auto-mode), offset: 0x20 */
  __IO uint32_t IPI_VID_VSA_MAN_CFG;               /**< VSA Timing (Manual), offset: 0x24 */
  __I  uint32_t IPI_VID_VSA_AUTO;                  /**< VSA Timing (Auto-mode), offset: 0x28 */
  __IO uint32_t IPI_VID_VBP_MAN_CFG;               /**< VBP Timing (Manual), offset: 0x2C */
  __I  uint32_t IPI_VID_VBP_AUTO;                  /**< VBP Timing (Auto-mode), offset: 0x30 */
  __IO uint32_t IPI_VID_VACT_MAN_CFG;              /**< VACT Timing (Manual), offset: 0x34 */
  __I  uint32_t IPI_VID_VACT_AUTO;                 /**< VACT Timing (Auto-mode), offset: 0x38 */
  __IO uint32_t IPI_VID_VFP_MAN_CFG;               /**< VFP Timing (Manual), offset: 0x3C */
  __I  uint32_t IPI_VID_VFP_AUTO;                  /**< VFP Timing (Auto-mode), offset: 0x40 */
  __IO uint32_t IPI_PIX_PKT_CFG;                   /**< Number of Pixels per Packet, offset: 0x44 */
  __IO uint32_t IPI_HIBERNATE_CFG;                 /**< Configuration for IPI Hibernate Feature, offset: 0x48 */
  __IO uint32_t IPI_LANES_MAN_CFG;                 /**< Configuration for IPI Lane Feature, offset: 0x4C */
       uint8_t RESERVED_0[112];
  __IO uint32_t IPI_FIFO_DEPTH_CFG;                /**< IPI External FIFO Depth Configuration, offset: 0xC0 */
  __IO uint32_t IPI_MAPPING_CFG;                   /**< IPI Mapping Configuration, offset: 0xC4 */
} DSI_V2_HOST_IPI_Type;

/* ----------------------------------------------------------------------------
   -- DSI_V2_HOST_IPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_IPI_Register_Masks DSI_V2_HOST_IPI Register Masks
 * @{
 */

/*! @name IPI_COLOR_MAN_CFG - IPI Color Coding */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_FORMAT_MASK (0xFU)
#define DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_FORMAT_SHIFT (0U)
/*! IPI_FORMAT
 *  0b0000..RGB
 *  0b0001..YCbCr 4:2:2
 *  0b0011..YCbCr 4:2:0
 *  0b0100..YCbCr 4:2:2 Loosely
 *  0b0101..RGB Loosely
 *  0b1011..Compressed Data
 */
#define DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_FORMAT_SHIFT)) & DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_FORMAT_MASK)

#define DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_DEPTH_MASK (0xF0U)
#define DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_DEPTH_SHIFT (4U)
/*! IPI_DEPTH
 *  0b0010..5-6-5 bits
 *  0b0011..6 bits
 *  0b0101..8 bits
 *  0b0110..10 bits
 *  0b0111..12 bits
 *  0b1001..16 bits
 */
#define DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_DEPTH(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_DEPTH_SHIFT)) & DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_DEPTH_MASK)
/*! @} */

/*! @name IPI_VID_HSA_MAN_CFG - HSA Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HSA_MAN_CFG_VID_HSA_TIME_MASK (0x3FFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HSA_MAN_CFG_VID_HSA_TIME_SHIFT (0U)
/*! VID_HSA_TIME
 *  0b000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HSA_MAN_CFG_VID_HSA_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HSA_MAN_CFG_VID_HSA_TIME_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HSA_MAN_CFG_VID_HSA_TIME_MASK)
/*! @} */

/*! @name IPI_VID_HSA_AUTO - HSA Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HSA_AUTO_VID_HSA_TIME_AUTO_MASK (0x3FFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HSA_AUTO_VID_HSA_TIME_AUTO_SHIFT (0U)
/*! VID_HSA_TIME_AUTO
 *  0b000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HSA_AUTO_VID_HSA_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HSA_AUTO_VID_HSA_TIME_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HSA_AUTO_VID_HSA_TIME_AUTO_MASK)
/*! @} */

/*! @name IPI_VID_HBP_MAN_CFG - HBP Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HBP_MAN_CFG_VID_HBP_TIME_MASK (0x3FFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HBP_MAN_CFG_VID_HBP_TIME_SHIFT (0U)
/*! VID_HBP_TIME
 *  0b000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HBP_MAN_CFG_VID_HBP_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HBP_MAN_CFG_VID_HBP_TIME_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HBP_MAN_CFG_VID_HBP_TIME_MASK)
/*! @} */

/*! @name IPI_VID_HBP_AUTO - HBP Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HBP_AUTO_VID_HBP_TIME_AUTO_MASK (0x3FFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HBP_AUTO_VID_HBP_TIME_AUTO_SHIFT (0U)
/*! VID_HBP_TIME_AUTO
 *  0b000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HBP_AUTO_VID_HBP_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HBP_AUTO_VID_HBP_TIME_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HBP_AUTO_VID_HBP_TIME_AUTO_MASK)
/*! @} */

/*! @name IPI_VID_HACT_MAN_CFG - HACT Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HACT_MAN_CFG_VID_HACT_TIME_MASK (0x3FFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HACT_MAN_CFG_VID_HACT_TIME_SHIFT (0U)
/*! VID_HACT_TIME
 *  0b000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HACT_MAN_CFG_VID_HACT_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HACT_MAN_CFG_VID_HACT_TIME_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HACT_MAN_CFG_VID_HACT_TIME_MASK)
/*! @} */

/*! @name IPI_VID_HACT_AUTO - HACT Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HACT_AUTO_VID_HACT_TIME_AUTO_MASK (0x3FFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HACT_AUTO_VID_HACT_TIME_AUTO_SHIFT (0U)
/*! VID_HACT_TIME_AUTO
 *  0b000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HACT_AUTO_VID_HACT_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HACT_AUTO_VID_HACT_TIME_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HACT_AUTO_VID_HACT_TIME_AUTO_MASK)
/*! @} */

/*! @name IPI_VID_HLINE_MAN_CFG - HLINE Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HLINE_MAN_CFG_VID_HLINE_TIME_MASK (0xFFFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HLINE_MAN_CFG_VID_HLINE_TIME_SHIFT (0U)
/*! VID_HLINE_TIME
 *  0b00000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HLINE_MAN_CFG_VID_HLINE_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HLINE_MAN_CFG_VID_HLINE_TIME_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HLINE_MAN_CFG_VID_HLINE_TIME_MASK)
/*! @} */

/*! @name IPI_VID_HLINE_AUTO - HLINE Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_HLINE_AUTO_VID_HLINE_TIME_AUTO_MASK (0xFFFFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_HLINE_AUTO_VID_HLINE_TIME_AUTO_SHIFT (0U)
/*! VID_HLINE_TIME_AUTO
 *  0b00000000000000000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_HLINE_AUTO_VID_HLINE_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_HLINE_AUTO_VID_HLINE_TIME_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_HLINE_AUTO_VID_HLINE_TIME_AUTO_MASK)
/*! @} */

/*! @name IPI_VID_VSA_MAN_CFG - VSA Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VSA_MAN_CFG_VID_VSA_LINES_MASK (0x3FFU)
#define DSI_V2_HOST_IPI_IPI_VID_VSA_MAN_CFG_VID_VSA_LINES_SHIFT (0U)
/*! VID_VSA_LINES
 *  0b0000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VSA_MAN_CFG_VID_VSA_LINES(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VSA_MAN_CFG_VID_VSA_LINES_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VSA_MAN_CFG_VID_VSA_LINES_MASK)
/*! @} */

/*! @name IPI_VID_VSA_AUTO - VSA Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VSA_AUTO_VID_VSA_LINES_AUTO_MASK (0x3FFU)
#define DSI_V2_HOST_IPI_IPI_VID_VSA_AUTO_VID_VSA_LINES_AUTO_SHIFT (0U)
/*! VID_VSA_LINES_AUTO
 *  0b0000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VSA_AUTO_VID_VSA_LINES_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VSA_AUTO_VID_VSA_LINES_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VSA_AUTO_VID_VSA_LINES_AUTO_MASK)
/*! @} */

/*! @name IPI_VID_VBP_MAN_CFG - VBP Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VBP_MAN_CFG_VID_VBP_LINES_MASK (0x3FFU)
#define DSI_V2_HOST_IPI_IPI_VID_VBP_MAN_CFG_VID_VBP_LINES_SHIFT (0U)
/*! VID_VBP_LINES
 *  0b0000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VBP_MAN_CFG_VID_VBP_LINES(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VBP_MAN_CFG_VID_VBP_LINES_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VBP_MAN_CFG_VID_VBP_LINES_MASK)
/*! @} */

/*! @name IPI_VID_VBP_AUTO - VBP Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VBP_AUTO_VID_VBP_LINES_AUTO_MASK (0x3FFU)
#define DSI_V2_HOST_IPI_IPI_VID_VBP_AUTO_VID_VBP_LINES_AUTO_SHIFT (0U)
/*! VID_VBP_LINES_AUTO
 *  0b0000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VBP_AUTO_VID_VBP_LINES_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VBP_AUTO_VID_VBP_LINES_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VBP_AUTO_VID_VBP_LINES_AUTO_MASK)
/*! @} */

/*! @name IPI_VID_VACT_MAN_CFG - VACT Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VACT_MAN_CFG_VID_VACT_LINES_MASK (0x3FFFU)
#define DSI_V2_HOST_IPI_IPI_VID_VACT_MAN_CFG_VID_VACT_LINES_SHIFT (0U)
/*! VID_VACT_LINES
 *  0b00000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VACT_MAN_CFG_VID_VACT_LINES(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VACT_MAN_CFG_VID_VACT_LINES_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VACT_MAN_CFG_VID_VACT_LINES_MASK)
/*! @} */

/*! @name IPI_VID_VACT_AUTO - VACT Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VACT_AUTO_VID_VACT_LINES_AUTO_MASK (0x3FFFU)
#define DSI_V2_HOST_IPI_IPI_VID_VACT_AUTO_VID_VACT_LINES_AUTO_SHIFT (0U)
/*! VID_VACT_LINES_AUTO
 *  0b00000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VACT_AUTO_VID_VACT_LINES_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VACT_AUTO_VID_VACT_LINES_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VACT_AUTO_VID_VACT_LINES_AUTO_MASK)
/*! @} */

/*! @name IPI_VID_VFP_MAN_CFG - VFP Timing (Manual) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VFP_MAN_CFG_VID_VFP_LINES_MASK (0xFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_VFP_MAN_CFG_VID_VFP_LINES_SHIFT (0U)
/*! VID_VFP_LINES
 *  0b00000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VFP_MAN_CFG_VID_VFP_LINES(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VFP_MAN_CFG_VID_VFP_LINES_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VFP_MAN_CFG_VID_VFP_LINES_MASK)
/*! @} */

/*! @name IPI_VID_VFP_AUTO - VFP Timing (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_VID_VFP_AUTO_VID_VFP_LINES_AUTO_MASK (0xFFFFFU)
#define DSI_V2_HOST_IPI_IPI_VID_VFP_AUTO_VID_VFP_LINES_AUTO_SHIFT (0U)
/*! VID_VFP_LINES_AUTO
 *  0b00000000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_VID_VFP_AUTO_VID_VFP_LINES_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_VID_VFP_AUTO_VID_VFP_LINES_AUTO_SHIFT)) & DSI_V2_HOST_IPI_IPI_VID_VFP_AUTO_VID_VFP_LINES_AUTO_MASK)
/*! @} */

/*! @name IPI_PIX_PKT_CFG - Number of Pixels per Packet */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_PIX_PKT_CFG_MAX_PIX_PKT_MASK (0xFFFFU)
#define DSI_V2_HOST_IPI_IPI_PIX_PKT_CFG_MAX_PIX_PKT_SHIFT (0U)
/*! MAX_PIX_PKT - Maximum Pixels per Packet */
#define DSI_V2_HOST_IPI_IPI_PIX_PKT_CFG_MAX_PIX_PKT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_PIX_PKT_CFG_MAX_PIX_PKT_SHIFT)) & DSI_V2_HOST_IPI_IPI_PIX_PKT_CFG_MAX_PIX_PKT_MASK)
/*! @} */

/*! @name IPI_HIBERNATE_CFG - Configuration for IPI Hibernate Feature */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_TYPE_MASK (0x1U)
#define DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_TYPE_SHIFT (0U)
/*! HIB_TYPE
 *  0b0..LP11 Mode
 *  0b1..ULPS Mode
 */
#define DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_TYPE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_TYPE_SHIFT)) & DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_TYPE_MASK)

#define DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_ULPS_WAKEUP_TIME_MASK (0xFFFF0000U)
#define DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_ULPS_WAKEUP_TIME_SHIFT (16U)
/*! HIB_ULPS_WAKEUP_TIME - Hibernate ULPS Wakeup Time */
#define DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_ULPS_WAKEUP_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_ULPS_WAKEUP_TIME_SHIFT)) & DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_ULPS_WAKEUP_TIME_MASK)
/*! @} */

/*! @name IPI_LANES_MAN_CFG - Configuration for IPI Lane Feature */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_LANES_MAN_CFG_IPI_LANES_MASK (0x3U)
#define DSI_V2_HOST_IPI_IPI_LANES_MAN_CFG_IPI_LANES_SHIFT (0U)
/*! IPI_LANES - IPI Lanes
 *  0b00..4 Lanes (not available on this chip)
 *  0b01..1 Lane (must choose this option.)
 *  0b10..2 Lanes (not available on this chip)
 *  0b11..
 */
#define DSI_V2_HOST_IPI_IPI_LANES_MAN_CFG_IPI_LANES(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_LANES_MAN_CFG_IPI_LANES_SHIFT)) & DSI_V2_HOST_IPI_IPI_LANES_MAN_CFG_IPI_LANES_MASK)
/*! @} */

/*! @name IPI_FIFO_DEPTH_CFG - IPI External FIFO Depth Configuration */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_FIFO_DEPTH_CFG_IPI_FIFO_DEPTH_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_IPI_IPI_FIFO_DEPTH_CFG_IPI_FIFO_DEPTH_VALUE_SHIFT (0U)
/*! IPI_FIFO_DEPTH_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_IPI_IPI_FIFO_DEPTH_CFG_IPI_FIFO_DEPTH_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_FIFO_DEPTH_CFG_IPI_FIFO_DEPTH_VALUE_SHIFT)) & DSI_V2_HOST_IPI_IPI_FIFO_DEPTH_CFG_IPI_FIFO_DEPTH_VALUE_MASK)
/*! @} */

/*! @name IPI_MAPPING_CFG - IPI Mapping Configuration */
/*! @{ */

#define DSI_V2_HOST_IPI_IPI_MAPPING_CFG_IPI_MAPPING_MASK (0x3U)
#define DSI_V2_HOST_IPI_IPI_MAPPING_CFG_IPI_MAPPING_SHIFT (0U)
/*! IPI_MAPPING
 *  0b00..Default IPI Behavior
 *  0b01..DPI behavior, configuration 1
 *  0b10..DPI behavior, configuration 2
 *  0b11..DPI behavior, configuration 3
 */
#define DSI_V2_HOST_IPI_IPI_MAPPING_CFG_IPI_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_IPI_IPI_MAPPING_CFG_IPI_MAPPING_SHIFT)) & DSI_V2_HOST_IPI_IPI_MAPPING_CFG_IPI_MAPPING_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_IPI_Register_Masks */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_IPI_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI_V2_HOST_IPI_H_ */

