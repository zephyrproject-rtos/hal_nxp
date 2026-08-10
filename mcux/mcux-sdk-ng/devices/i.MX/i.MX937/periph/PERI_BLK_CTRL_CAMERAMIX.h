/*
** ###################################################################
**     Processors:          MIMX9371xxVTx_ca55
**                          MIMX9371xxVTx_cm33
**                          MIMX9371xxVTx_cm7
**                          MIMX9373xxVTx_ca55
**                          MIMX9373xxVTx_cm33
**                          MIMX9373xxVTx_cm7
**                          MIMX9373xxVZx_ca55
**                          MIMX9373xxVZx_cm33
**                          MIMX9373xxVZx_cm7
**                          MIMX9375xxVTx_ca55
**                          MIMX9375xxVTx_cm33
**                          MIMX9375xxVTx_cm7
**                          MIMX9375xxVZx_ca55
**                          MIMX9375xxVZx_cm33
**                          MIMX9375xxVZx_cm7
**
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260624
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_CAMERAMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_CAMERAMIX.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_CAMERAMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_CAMERAMIX
 */

#if !defined(PERI_BLK_CTRL_CAMERAMIX_H_)
#define PERI_BLK_CTRL_CAMERAMIX_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9371xxVTx_ca55))
#include "MIMX9371_ca55_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm33))
#include "MIMX9371_cm33_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm7))
#include "MIMX9371_cm7_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_ca55) || defined(CPU_MIMX9373xxVZx_ca55))
#include "MIMX9373_ca55_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm33) || defined(CPU_MIMX9373xxVZx_cm33))
#include "MIMX9373_cm33_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm7) || defined(CPU_MIMX9373xxVZx_cm7))
#include "MIMX9373_cm7_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7_COMMON.h"
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
   -- BLK_CTRL_CAMERAMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_CAMERAMIX_Peripheral_Access_Layer BLK_CTRL_CAMERAMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_CAMERAMIX - Size of Registers Arrays */
#define BLK_CTRL_CAMERAMIX_CSI0_VCN_INTERLACED_LINE_COUNT_SET_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VCN_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VCN_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VCN_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VCN_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VCN_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI1_VCN_INTERLACED_LINE_COUNT_SET_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VCN_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_VC_COUNT 8u
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_ERR_VC_COUNT 8u

/** BLK_CTRL_CAMERAMIX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12];
  __IO uint32_t ISI_AXCACHE_CONTROL;               /**< ISI AxCache Control, offset: 0xC */
  __IO uint32_t ISI_QOS_SETTING;                   /**< ISI QoS Setting, offset: 0x10 */
  __IO uint32_t PANIC_QOS;                         /**< Panic QoS Setting, offset: 0x14 */
  __I  uint32_t INIT_PENDING_TX;                   /**< Camera NOC Pending Transaction Status, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CSI0_VC_INTERLACED_LINE_COUNT_SET[BLK_CTRL_CAMERAMIX_CSI0_VCN_INTERLACED_LINE_COUNT_SET_COUNT]; /**< CSI0 VC Interlaced Line Count, array offset: 0x20, array step: 0x4 */
  __IO uint32_t CSI0_VC_INTERLACED_CTRL;           /**< CSI0 VC Interlaced Control, offset: 0x40 */
  __IO uint32_t CSI0_VC_INTERLACED_ERROR;          /**< CSI0 VC Interlaced Error, offset: 0x44 */
  __IO uint32_t CSI0_YUV420_FIRST_LINE_EVEN;       /**< CSI0 YUV420 First Line Even, offset: 0x48 */
       uint8_t RESERVED_2[4];
  __IO uint32_t CSI0_RAW32_CTR;                    /**< CSI0 RAW32 Control, offset: 0x50 */
  __IO uint32_t CSI0_STREAM_FENCING_CTRL;          /**< CSI0 Stream Fencing Control, offset: 0x54 */
  __I  uint32_t CSI0_STREAM_FENCING_STATUS;        /**< CSI0 Stream Fencing Status, offset: 0x58 */
       uint8_t RESERVED_3[4];
  __IO uint32_t CSI0_NP_DATA_TYPE_VC[BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_COUNT]; /**< CSI0 VC0 Non-Pixel Data Type..CSI0 VC7 Non-Pixel Data Type, array offset: 0x60, array step: 0x4 */
  __IO uint32_t CSI0_PIXEL_DATA_CTRL_VC[BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VCN_COUNT]; /**< CSI0 Pixel Data Control VC, array offset: 0x80, array step: 0x4 */
  __IO uint32_t CSI0_ROUTE_PIXEL_DATA_TYPE_VC[BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VCN_COUNT]; /**< CSI0 Route Pixel Data Type VC, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t CSI0_NON_PIXEL_DATA_CTRL_VC[BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VCN_COUNT]; /**< CSI0 Non-Pixel Data Control VC, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t CSI0_PIXEL_DATA_TYPE_VC[BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VCN_COUNT]; /**< CSI0 Pixel Data Type VC, array offset: 0xE0, array step: 0x4 */
  __IO uint32_t CSI0_PIXEL_DATA_TYPE_ERR_VC[BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VCN_COUNT]; /**< CSI0 Pixel Data Type Error VC, array offset: 0x100, array step: 0x4 */
  __IO uint32_t CSI1_VC_INTERLACED_LINE_COUNT_SET[BLK_CTRL_CAMERAMIX_CSI1_VCN_INTERLACED_LINE_COUNT_SET_COUNT]; /**< CSI1 VCn Interlaced Line Count, array offset: 0x120, array step: 0x4 */
  __IO uint32_t CSI1_VC_INTERLACED_CTRL;           /**< CSI1 VC Interlaced Control, offset: 0x140 */
  __IO uint32_t CSI1_VC_INTERLACED_ERROR;          /**< CSI1 VC Interlaced Error, offset: 0x144 */
  __IO uint32_t CSI1_YUV420_FIRST_LINE_EVEN;       /**< CSI1 YUV420 First Line Even, offset: 0x148 */
       uint8_t RESERVED_4[4];
  __IO uint32_t CSI1_RAW32_CTR;                    /**< CSI1 RAW32 Control, offset: 0x150 */
  __IO uint32_t CSI1_STREAM_FENCING_CTRL;          /**< Stream Fencing Control, offset: 0x154 */
  __I  uint32_t CSI1_STREAM_FENCING_STATUS;        /**< Stream Fencing Status, offset: 0x158 */
       uint8_t RESERVED_5[4];
  __IO uint32_t CSI1_NP_DATA_TYPE_VC[BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_COUNT]; /**< CSI1 VC0 Non-Pixel Data Type..CSI1 VC7 Non-Pixel Data Type, array offset: 0x160, array step: 0x4 */
  __IO uint32_t CSI1_PIXEL_DATA_CTRL_VC[BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VCN_COUNT]; /**< CSI1 Pixel Data Control VC, array offset: 0x180, array step: 0x4 */
  __IO uint32_t CSI1_ROUTE_PIXEL_DATA_TYPE_VC[BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_COUNT]; /**< CSI1 Route Pixel Data Type VC, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t CSI1_NON_PIXEL_DATA_CTRL_VC[BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_COUNT]; /**< CSI1 Non-Pixel Data Control VC, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t CSI1_PIXEL_DATA_TYPE_VC[BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_VC_COUNT]; /**< CSI1 Pixel Data Type VC, array offset: 0x1E0, array step: 0x4 */
  __IO uint32_t CSI1_PIXEL_DATA_TYPE_ERR_VC[BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_ERR_VC_COUNT]; /**< CSI1 Pixel Data Type Error VC, array offset: 0x200, array step: 0x4 */
  __IO uint32_t CSI0_PIXEL_LINK_RAW10_FORMAT;      /**< Pixel Link RAW10 Format, offset: 0x220 */
  __IO uint32_t CSI1_PIXEL_LINK_RAW10_FORMAT;      /**< Pixel Link RAW10 Format, offset: 0x224 */
  __IO uint32_t CSI0_BUFFER_OVERFLOW;              /**< Buffer Overflow, offset: 0x228 */
  __IO uint32_t CSI1_BUFFER_OVERFLOW;              /**< Buffer Overflow, offset: 0x22C */
  __IO uint32_t PIXEL_FORMATTER_RST_CTRL;          /**< Reset control for pixel formatter0 and pixel formatter1, offset: 0x230 */
       uint8_t RESERVED_6[240];
  __IO uint32_t DISPLAY_PIXEL_LINK_SLV_CG;         /**< ISI Clock Gating Control for Display Pixel Link Target, offset: 0x324 */
  __IO uint32_t IPC_CLK_ON_OFF_CTRL_REG0;          /**< IPC Clock Alternative Force ON/OFF Control, offset: 0x328 */
} BLK_CTRL_CAMERAMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_CAMERAMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_CAMERAMIX_Register_Masks BLK_CTRL_CAMERAMIX Register Masks
 * @{
 */

/*! @name ISI_AXCACHE_CONTROL - ISI AxCache Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_ARCACHE_MASK (0xFU)
#define BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_ARCACHE_SHIFT (0U)
/*! ArCache - AXI ArCache Signal for AXI Read Initiator Ports */
#define BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_ARCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_ARCACHE_SHIFT)) & BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_ARCACHE_MASK)

#define BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_AWCACHE_MASK (0xF00U)
#define BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_AWCACHE_SHIFT (8U)
/*! AwCache - AXI AwCache Signal for AXI Write Initiator Ports */
#define BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_AWCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_AWCACHE_SHIFT)) & BLK_CTRL_CAMERAMIX_ISI_AXCACHE_CONTROL_AWCACHE_MASK)
/*! @} */

/*! @name ISI_QOS_SETTING - ISI QoS Setting */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_ISI_QOS_SETTING_AWQOS_MASK (0x7U)
#define BLK_CTRL_CAMERAMIX_ISI_QOS_SETTING_AWQOS_SHIFT (0U)
/*! AwQoS - AXI AwQoS Signal for ISI AXI Read and Write Ports */
#define BLK_CTRL_CAMERAMIX_ISI_QOS_SETTING_AWQOS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_ISI_QOS_SETTING_AWQOS_SHIFT)) & BLK_CTRL_CAMERAMIX_ISI_QOS_SETTING_AWQOS_MASK)
/*! @} */

/*! @name PANIC_QOS - Panic QoS Setting */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_PANIC_QOS_PANIC_QOS_MASK (0x7U)
#define BLK_CTRL_CAMERAMIX_PANIC_QOS_PANIC_QOS_SHIFT (0U)
/*! Panic_QoS - ISI Panic QoS Setting */
#define BLK_CTRL_CAMERAMIX_PANIC_QOS_PANIC_QOS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_PANIC_QOS_PANIC_QOS_SHIFT)) & BLK_CTRL_CAMERAMIX_PANIC_QOS_PANIC_QOS_MASK)
/*! @} */

/*! @name INIT_PENDING_TX - Camera NOC Pending Transaction Status */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_READ_ISI_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_READ_ISI_SHIFT (4U)
/*! Read_ISI - Read_ISI Pending Transaction
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_READ_ISI(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_READ_ISI_SHIFT)) & BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_READ_ISI_MASK)

#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_Y_ISI_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_Y_ISI_SHIFT (5U)
/*! Write_Y_ISI - Write_Y_ISI Pending Transaction
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_Y_ISI(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_Y_ISI_SHIFT)) & BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_Y_ISI_MASK)

#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_U_ISI_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_U_ISI_SHIFT (6U)
/*! Write_U_ISI - Write_U_ISI Pending Transaction
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_U_ISI(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_U_ISI_SHIFT)) & BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_U_ISI_MASK)

#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_V_ISI_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_V_ISI_SHIFT (7U)
/*! Write_V_ISI - Write_V_ISI Pending Transaction
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_V_ISI(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_V_ISI_SHIFT)) & BLK_CTRL_CAMERAMIX_INIT_PENDING_TX_WRITE_V_ISI_MASK)
/*! @} */

/*! @name CSI0_VC_INTERLACED_LINE_COUNT_SET - CSI0 VC Interlaced Line Count */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_MASK (0x3FFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_SHIFT (0U)
/*! Odd_line_count - Odd Line Count */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_MASK (0x3FFF0000U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_SHIFT (16U)
/*! Even_line_count - Even Line Count */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_LINE_COUNT_SET_COUNT (8U)

/*! @name CSI0_VC_INTERLACED_CTRL - CSI0 VC Interlaced Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC0_INTERLACE_MODE_MASK (0x3U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC0_INTERLACE_MODE_SHIFT (0U)
/*! CSI0_VC0_interlace_mode - CSI0 VC0 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC0_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC0_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC0_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC1_INTERLACE_MODE_MASK (0xCU)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC1_INTERLACE_MODE_SHIFT (2U)
/*! CSI0_VC1_interlace_mode - CSI0 VC1 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC1_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC1_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC1_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC2_INTERLACE_MODE_MASK (0x30U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC2_INTERLACE_MODE_SHIFT (4U)
/*! CSI0_VC2_interlace_mode - CSI0 VC2 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC2_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC2_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC2_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC3_INTERLACE_MODE_MASK (0xC0U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC3_INTERLACE_MODE_SHIFT (6U)
/*! CSI0_VC3_interlace_mode - CSI0 VC3 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC3_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC3_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC3_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC4_INTERLACE_MODE_MASK (0x300U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC4_INTERLACE_MODE_SHIFT (8U)
/*! CSI0_VC4_interlace_mode - CSI0 VC4 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC4_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC4_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC4_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC5_INTERLACE_MODE_MASK (0xC00U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC5_INTERLACE_MODE_SHIFT (10U)
/*! CSI0_VC5_interlace_mode - CSI0 VC5 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC5_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC5_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC5_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC6_INTERLACE_MODE_MASK (0x3000U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC6_INTERLACE_MODE_SHIFT (12U)
/*! CSI0_VC6_interlace_mode - CSI0 VC6 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC6_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC6_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC6_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC7_INTERLACE_MODE_MASK (0xC000U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC7_INTERLACE_MODE_SHIFT (14U)
/*! CSI0_VC7_interlace_mode - CSI0 VC7 Interlace Mode Select
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC7_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC7_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_CTRL_CSI0_VC7_INTERLACE_MODE_MASK)
/*! @} */

/*! @name CSI0_VC_INTERLACED_ERROR - CSI0 VC Interlaced Error */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC0_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC0_SHIFT (0U)
/*! CSI0_VC0 - CSI0 VC0 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC0_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC0_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC1_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC1_SHIFT (1U)
/*! CSI0_VC1 - CSI0 VC1 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC1_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC1_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC2_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC2_SHIFT (2U)
/*! CSI0_VC2 - CSI0 VC2 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC2_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC2_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC3_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC3_SHIFT (3U)
/*! CSI0_VC3 - CSI0 VC3 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC3_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC3_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC4_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC4_SHIFT (4U)
/*! CSI0_VC4 - CSI0 VC4 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC4_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC4_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC5_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC5_SHIFT (5U)
/*! CSI0_VC5 - CSI0 VC5 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC5_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC5_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC6_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC6_SHIFT (6U)
/*! CSI0_VC6 - CSI0 VC6 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC6_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC6_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC7_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC7_SHIFT (7U)
/*! CSI0_VC7 - CSI0 VC7 Line Count Mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC7_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_VC_INTERLACED_ERROR_CSI0_VC7_MASK)
/*! @} */

/*! @name CSI0_YUV420_FIRST_LINE_EVEN - CSI0 YUV420 First Line Even */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC0_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC0_SHIFT (0U)
/*! VC0 - CSI0 VC0 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC0_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC0_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC1_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC1_SHIFT (1U)
/*! VC1 - CSI0 VC1 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC1_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC1_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC2_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC2_SHIFT (2U)
/*! VC2 - CSI0 VC2 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC2_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC2_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC3_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC3_SHIFT (3U)
/*! VC3 - CSI0 VC3 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC3_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC3_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC4_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC4_SHIFT (4U)
/*! VC4 - CSI0 VC4 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC4_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC4_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC5_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC5_SHIFT (5U)
/*! VC5 - CSI0 VC5 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC5_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC5_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC6_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC6_SHIFT (6U)
/*! VC6 - CSI0 VC6 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC6_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC6_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC7_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC7_SHIFT (7U)
/*! VC7 - CSI0 VC7 First Line Even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC7_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_YUV420_FIRST_LINE_EVEN_VC7_MASK)
/*! @} */

/*! @name CSI0_RAW32_CTR - CSI0 RAW32 Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC0_RAW32_MODE_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC0_RAW32_MODE_SHIFT (0U)
/*! CSI0_VC0_RAW32_MODE - CSI0 VC0 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC0_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC0_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC0_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC1_RAW32_MODE_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC1_RAW32_MODE_SHIFT (1U)
/*! CSI0_VC1_RAW32_MODE - CSI0 VC1 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC1_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC1_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC1_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC2_RAW32_MODE_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC2_RAW32_MODE_SHIFT (2U)
/*! CSI0_VC2_RAW32_MODE - CSI0 VC2 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC2_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC2_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC2_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC3_RAW32_MODE_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC3_RAW32_MODE_SHIFT (3U)
/*! CSI0_VC3_RAW32_MODE - CSI0 VC3 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC3_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC3_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC3_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC4_RAW32_MODE_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC4_RAW32_MODE_SHIFT (4U)
/*! CSI0_VC4_RAW32_MODE - CSI0 VC4 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC4_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC4_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC4_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC5_RAW32_MODE_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC5_RAW32_MODE_SHIFT (5U)
/*! CSI0_VC5_RAW32_MODE - CSI0 VC5 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC5_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC5_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC5_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC6_RAW32_MODE_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC6_RAW32_MODE_SHIFT (6U)
/*! CSI0_VC6_RAW32_MODE - CSI0 VC6 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC6_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC6_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC6_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC7_RAW32_MODE_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC7_RAW32_MODE_SHIFT (7U)
/*! CSI0_VC7_RAW32_MODE - CSI0 VC7 RAW32 Mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC7_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC7_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_VC7_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_RAW_SWAP_MODE_MASK (0xFF00U)
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_RAW_SWAP_MODE_SHIFT (8U)
/*! CSI0_RAW_SWAP_MODE - CSI0 RAW Swap Mode */
#define BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_RAW_SWAP_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_RAW_SWAP_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_RAW32_CTR_CSI0_RAW_SWAP_MODE_MASK)
/*! @} */

/*! @name CSI0_STREAM_FENCING_CTRL - CSI0 Stream Fencing Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_FENCING_CONTROL_MASK (0xFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_FENCING_CONTROL_SHIFT (0U)
/*! CSI0_Fencing_Control - CSI0 Fencing Control */
#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_FENCING_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_FENCING_CONTROL_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_FENCING_CONTROL_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_RESET_FENCING_SM_MASK (0xFF00U)
#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_RESET_FENCING_SM_SHIFT (8U)
/*! CSI0_Reset_Fencing_SM - CSI0 Software Reset Fencing State Machine */
#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_RESET_FENCING_SM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_RESET_FENCING_SM_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_CTRL_CSI0_RESET_FENCING_SM_MASK)
/*! @} */

/*! @name CSI0_STREAM_FENCING_STATUS - CSI0 Stream Fencing Status */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_STATUS_CSI0_FENCING_STATUS_MASK (0xFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_STATUS_CSI0_FENCING_STATUS_SHIFT (0U)
/*! CSI0_Fencing_Status - CSI0 Fencing Status */
#define BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_STATUS_CSI0_FENCING_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_STATUS_CSI0_FENCING_STATUS_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_STREAM_FENCING_STATUS_CSI0_FENCING_STATUS_MASK)
/*! @} */

/*! @name CSI0_NP_DATA_TYPE_VC - CSI0 VC0 Non-Pixel Data Type..CSI0 VC7 Non-Pixel Data Type */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC0_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC0_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC0_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC0_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC0_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC0_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC1_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC1_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC1_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC1_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC1_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC1_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC2_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC2_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC2_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC2_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC2_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC2_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC3_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC3_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC3_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC3_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC3_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC3_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC4_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC4_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC4_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC4_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC4_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC4_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC5_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC5_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC5_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC5_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC5_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC5_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC6_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC6_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC6_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC6_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC6_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC6_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC7_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC7_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI0_VC7_NP_data_type_en - Enables transport of non-pixel data on pixel link. */
#define BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC7_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC7_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NP_DATA_TYPE_VC_CSI0_VC7_NP_DATA_TYPE_EN_MASK)
/*! @} */

/*! @name CSI0_PIXEL_DATA_CTRL_VC - CSI0 Pixel Data Control VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT (0U)
/*! Reroute_VC - Defines if the pixel data are routed to another VC or not
 *  0b0..Pixel data are not re-routed.
 *  0b1..Pixel are routed to VC defined by New_VC.
 */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_REROUTE_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_NEW_VC_MASK (0xEU)
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT (1U)
/*! New_VC - Defines the virtual channel on which the pixel data are transported */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_NEW_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_NEW_VC_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_CTRL_VC_COUNT (8U)

/*! @name CSI0_ROUTE_PIXEL_DATA_TYPE_VC - CSI0 Route Pixel Data Type VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_MASK (0x1FFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_SHIFT (0U)
/*! Others - Route other pixel data type enable */
#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_RAW_MASK (0xFF8000U)
#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_RAW_SHIFT (15U)
/*! RAW - Route RAW pixel data type enable */
#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_RAW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_RAW_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_RAW_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC */
#define BLK_CTRL_CAMERAMIX_CSI0_ROUTE_PIXEL_DATA_TYPE_VC_COUNT (8U)

/*! @name CSI0_NON_PIXEL_DATA_CTRL_VC - CSI0 Non-Pixel Data Control VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT (0U)
/*! Reroute_VC - Defines if the non-pixel data are routed to another VC or not
 *  0b0..Non-pixel data are not re-routed.
 *  0b1..Non-pixel data are routed to VC defined by New_VC.
 */
#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK)

#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_NEW_VC_MASK (0xEU)
#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT (1U)
/*! New_VC - Defines the virtual channel on which the non-pixel data are transported */
#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_NEW_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_NEW_VC_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC */
#define BLK_CTRL_CAMERAMIX_CSI0_NON_PIXEL_DATA_CTRL_VC_COUNT (8U)

/*! @name CSI0_PIXEL_DATA_TYPE_VC - CSI0 Pixel Data Type VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_MASK (0xFFFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_SHIFT (0U)
/*! type_enable - Pixel data type enable */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VC_TYPE_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VC */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_VC_COUNT (8U)

/*! @name CSI0_PIXEL_DATA_TYPE_ERR_VC - CSI0 Pixel Data Type Error VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_MASK (0xFFFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_SHIFT (0U)
/*! type_error - Pixel data type error */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VC */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_DATA_TYPE_ERR_VC_COUNT (8U)

/*! @name CSI1_VC_INTERLACED_LINE_COUNT_SET - CSI1 VCn Interlaced Line Count */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_MASK (0x3FFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_SHIFT (0U)
/*! Odd_line_count - Odd line count */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_ODD_LINE_COUNT_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_MASK (0x3FFF0000U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_SHIFT (16U)
/*! Even_line_count - Even line count */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_EVEN_LINE_COUNT_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_LINE_COUNT_SET_COUNT (8U)

/*! @name CSI1_VC_INTERLACED_CTRL - CSI1 VC Interlaced Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC0_INTERLACE_MODE_MASK (0x3U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC0_INTERLACE_MODE_SHIFT (0U)
/*! CSI1_VC0_interlace_mode - CSI1 VC0 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC0_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC0_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC0_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC1_INTERLACE_MODE_MASK (0xCU)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC1_INTERLACE_MODE_SHIFT (2U)
/*! CSI1_VC1_interlace_mode - CSI1 VC1 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC1_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC1_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC1_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC2_INTERLACE_MODE_MASK (0x30U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC2_INTERLACE_MODE_SHIFT (4U)
/*! CSI1_VC2_interlace_mode - CSI1 VC2 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC2_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC2_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC2_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC3_INTERLACE_MODE_MASK (0xC0U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC3_INTERLACE_MODE_SHIFT (6U)
/*! CSI1_VC3_interlace_mode - CSI1 VC3 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC3_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC3_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC3_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC4_INTERLACE_MODE_MASK (0x300U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC4_INTERLACE_MODE_SHIFT (8U)
/*! CSI1_VC4_interlace_mode - CSI1 VC4 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC4_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC4_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC4_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC5_INTERLACE_MODE_MASK (0xC00U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC5_INTERLACE_MODE_SHIFT (10U)
/*! CSI1_VC5_interlace_mode - CSI1 VC5 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC5_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC5_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC5_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC6_INTERLACE_MODE_MASK (0x3000U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC6_INTERLACE_MODE_SHIFT (12U)
/*! CSI1_VC6_interlace_mode - CSI1 VC6 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC6_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC6_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC6_INTERLACE_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC7_INTERLACE_MODE_MASK (0xC000U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC7_INTERLACE_MODE_SHIFT (14U)
/*! CSI1_VC7_interlace_mode - CSI1 VC7 interlace mode
 *  0b00..Virtual channel is not interlaced: Pixel Link Interlaced/not control field is set 00b
 *  0b01..Virtual channel is interlaced and generation done according to the CSI2 frame number
 *  0b10..Virtual channel is interlaced and generation done according to the number of lines received during one frame
 *  0b11..Virtual channel is interlaced and first received frame is considered as ODD
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC7_INTERLACE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC7_INTERLACE_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_CTRL_CSI1_VC7_INTERLACE_MODE_MASK)
/*! @} */

/*! @name CSI1_VC_INTERLACED_ERROR - CSI1 VC Interlaced Error */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC0_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC0_SHIFT (0U)
/*! CSI1_VC0 - CSI1 VC0 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC0_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC0_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC1_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC1_SHIFT (1U)
/*! CSI1_VC1 - CSI1 VC1 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC1_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC1_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC2_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC2_SHIFT (2U)
/*! CSI1_VC2 - CSI1 VC2 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC2_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC2_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC3_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC3_SHIFT (3U)
/*! CSI1_VC3 - CSI1 VC3 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC3_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC3_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC4_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC4_SHIFT (4U)
/*! CSI1_VC4 - CSI1 VC4 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC4_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC4_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC5_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC5_SHIFT (5U)
/*! CSI1_VC5 - CSI1 VC5 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC5_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC5_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC6_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC6_SHIFT (6U)
/*! CSI1_VC6 - CSI1 VC6 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC6_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC6_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC7_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC7_SHIFT (7U)
/*! CSI1_VC7 - CSI1 VC7 Line count mismatch
 *  0b0..No line count mismatch error
 *  0b1..Line count mismatch error
 */
#define BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC7_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_VC_INTERLACED_ERROR_CSI1_VC7_MASK)
/*! @} */

/*! @name CSI1_YUV420_FIRST_LINE_EVEN - CSI1 YUV420 First Line Even */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC0_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC0_SHIFT (0U)
/*! VC0 - CSI1 VC0 first line even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC0_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC0_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC1_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC1_SHIFT (1U)
/*! VC1 - CSI1 VC1 first line even */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC1_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC1_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC2_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC2_SHIFT (2U)
/*! VC2 - CSI1 VC2 first line even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC2_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC2_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC3_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC3_SHIFT (3U)
/*! VC3 - CSI1 VC3 first line even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC3_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC3_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC4_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC4_SHIFT (4U)
/*! VC4 - CSI1 VC4 first line even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC4_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC4_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC5_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC5_SHIFT (5U)
/*! VC5 - CSI1 VC5 first line even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC5_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC5_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC6_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC6_SHIFT (6U)
/*! VC6 - CSI1 VC6 first line even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC6_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC6_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC7_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC7_SHIFT (7U)
/*! VC7 - CSI1 VC7 first line even
 *  0b0..First line is odd
 *  0b1..First line is even
 */
#define BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC7_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_YUV420_FIRST_LINE_EVEN_VC7_MASK)
/*! @} */

/*! @name CSI1_RAW32_CTR - CSI1 RAW32 Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC0_RAW32_MODE_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC0_RAW32_MODE_SHIFT (0U)
/*! CSI1_VC0_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC0_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC0_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC0_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC1_RAW32_MODE_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC1_RAW32_MODE_SHIFT (1U)
/*! CSI1_VC1_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC1_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC1_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC1_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC2_RAW32_MODE_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC2_RAW32_MODE_SHIFT (2U)
/*! CSI1_VC2_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC2_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC2_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC2_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC3_RAW32_MODE_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC3_RAW32_MODE_SHIFT (3U)
/*! CSI1_VC3_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC3_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC3_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC3_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC4_RAW32_MODE_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC4_RAW32_MODE_SHIFT (4U)
/*! CSI1_VC4_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC4_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC4_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC4_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC5_RAW32_MODE_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC5_RAW32_MODE_SHIFT (5U)
/*! CSI1_VC5_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC5_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC5_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC5_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC6_RAW32_MODE_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC6_RAW32_MODE_SHIFT (6U)
/*! CSI1_VC6_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC6_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC6_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC6_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC7_RAW32_MODE_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC7_RAW32_MODE_SHIFT (7U)
/*! CSI1_VC7_RAW32_MODE - Defines if a virtual channel is set in RAW32 mode
 *  0b0..Not set
 *  0b1..Set
 */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC7_RAW32_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC7_RAW32_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_VC7_RAW32_MODE_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_RAW_SWAP_MODE_MASK (0xFF00U)
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_RAW_SWAP_MODE_SHIFT (8U)
/*! CSI1_RAW_SWAP_MODE - Defines if a virtual channel is set in RAW SWAP mode when index corresponding to the virtual channel is set to '1'. */
#define BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_RAW_SWAP_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_RAW_SWAP_MODE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_RAW32_CTR_CSI1_RAW_SWAP_MODE_MASK)
/*! @} */

/*! @name CSI1_STREAM_FENCING_CTRL - Stream Fencing Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_FENCING_CONTROL_MASK (0xFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_FENCING_CONTROL_SHIFT (0U)
/*! CSI1_Fencing_Control - [0] Fence VC0...[7] Fence VC7 */
#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_FENCING_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_FENCING_CONTROL_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_FENCING_CONTROL_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_RESET_FENCING_SM_MASK (0xFF00U)
#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_RESET_FENCING_SM_SHIFT (8U)
/*! CSI1_Reset_Fencing_SM - SW reset of Fencing state machine. One per Virtual channel.[8] : Virtual channel 0...[15]: Virtual channel 7 */
#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_RESET_FENCING_SM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_RESET_FENCING_SM_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_CTRL_CSI1_RESET_FENCING_SM_MASK)
/*! @} */

/*! @name CSI1_STREAM_FENCING_STATUS - Stream Fencing Status */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_STATUS_CSI1_FENCING_STATUS_MASK (0xFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_STATUS_CSI1_FENCING_STATUS_SHIFT (0U)
/*! CSI1_Fencing_Status - Indicates when a virtual channel is fenced when set to '1'. [0] VC0 is fenced...[7] VC7 is fenced */
#define BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_STATUS_CSI1_FENCING_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_STATUS_CSI1_FENCING_STATUS_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_STREAM_FENCING_STATUS_CSI1_FENCING_STATUS_MASK)
/*! @} */

/*! @name CSI1_NP_DATA_TYPE_VC - CSI1 VC0 Non-Pixel Data Type..CSI1 VC7 Non-Pixel Data Type */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC0_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC0_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC0_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC0_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC0_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC0_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC1_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC1_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC1_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC1_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC1_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC1_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC2_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC2_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC2_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC2_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC2_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC2_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC3_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC3_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC3_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC3_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC3_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC3_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC4_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC4_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC4_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC4_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC4_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC4_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC5_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC5_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC5_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC5_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC5_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC5_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC6_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC6_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC6_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC6_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC6_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC6_NP_DATA_TYPE_EN_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC7_NP_DATA_TYPE_EN_MASK (0x3FFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC7_NP_DATA_TYPE_EN_SHIFT (0U)
/*! CSI1_VC7_NP_data_type_en - Enables transport of non-pixel data on pixel link */
#define BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC7_NP_DATA_TYPE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC7_NP_DATA_TYPE_EN_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NP_DATA_TYPE_VC_CSI1_VC7_NP_DATA_TYPE_EN_MASK)
/*! @} */

/*! @name CSI1_PIXEL_DATA_CTRL_VC - CSI1 Pixel Data Control VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT (0U)
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_REROUTE_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_NEW_VC_MASK (0xEU)
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT (1U)
/*! New_VC - Defines the virtual channel on which the pixel data are transported */
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_NEW_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_NEW_VC_MASK)
/*! @} */

/* The count of BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC */
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_CTRL_VC_COUNT (8U)

/*! @name CSI1_ROUTE_PIXEL_DATA_TYPE_VC - CSI1 Route Pixel Data Type VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_MASK (0x1FFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_SHIFT (0U)
/*! Others - Route RAW pixel data type enable */
#define BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_OTHERS_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_RAW_MASK (0xFF8000U)
#define BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_RAW_SHIFT (15U)
/*! RAW - Route RAW pixel data type enable */
#define BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_RAW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_RAW_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_ROUTE_PIXEL_DATA_TYPE_VC_RAW_MASK)
/*! @} */

/*! @name CSI1_NON_PIXEL_DATA_CTRL_VC - CSI1 Non-Pixel Data Control VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT (0U)
/*! Reroute_VC - Defines if the non-pixel data are routed to another VC or not
 *  0b0..Non-pixel data are not re-routed.
 *  0b1..Non-pixel data are routed to VC defined by New_VC.
 */
#define BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_REROUTE_VC_MASK)

#define BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_NEW_VC_MASK (0xEU)
#define BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT (1U)
/*! New_VC - Defines the virtual channel on which the non-pixel data are transported */
#define BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_NEW_VC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_NEW_VC_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_NON_PIXEL_DATA_CTRL_VC_NEW_VC_MASK)
/*! @} */

/*! @name CSI1_PIXEL_DATA_TYPE_VC - CSI1 Pixel Data Type VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_MASK (0xFFFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_SHIFT (0U)
/*! type_enable - Pixel data type enable */
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_VC_TYPE_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_VC_TYPE_ENABLE_MASK)
/*! @} */

/*! @name CSI1_PIXEL_DATA_TYPE_ERR_VC - CSI1 Pixel Data Type Error VC */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_MASK (0xFFFFFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_SHIFT (0U)
/*! type_error - Pixel data type error */
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_PIXEL_DATA_TYPE_ERR_VC_TYPE_ERROR_MASK)
/*! @} */

/*! @name CSI0_PIXEL_LINK_RAW10_FORMAT - Pixel Link RAW10 Format */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_LINK_RAW10_FORMAT_RAW10P_MASK (0xFFU)
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_LINK_RAW10_FORMAT_RAW10P_SHIFT (0U)
/*! RAW10P - RAW10P */
#define BLK_CTRL_CAMERAMIX_CSI0_PIXEL_LINK_RAW10_FORMAT_RAW10P(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_PIXEL_LINK_RAW10_FORMAT_RAW10P_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_PIXEL_LINK_RAW10_FORMAT_RAW10P_MASK)
/*! @} */

/*! @name CSI1_PIXEL_LINK_RAW10_FORMAT - Pixel Link RAW10 Format */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_LINK_RAW10_FORMAT_RAW10P_MASK (0xFFU)
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_LINK_RAW10_FORMAT_RAW10P_SHIFT (0U)
/*! RAW10P - RAW10P */
#define BLK_CTRL_CAMERAMIX_CSI1_PIXEL_LINK_RAW10_FORMAT_RAW10P(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_PIXEL_LINK_RAW10_FORMAT_RAW10P_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_PIXEL_LINK_RAW10_FORMAT_RAW10P_MASK)
/*! @} */

/*! @name CSI0_BUFFER_OVERFLOW - Buffer Overflow */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI0_BUFFER_OVERFLOW_BUFFER_OVERFLOW_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI0_BUFFER_OVERFLOW_BUFFER_OVERFLOW_SHIFT (0U)
/*! Buffer_Overflow - Set when the rate adaptation buffer overflows */
#define BLK_CTRL_CAMERAMIX_CSI0_BUFFER_OVERFLOW_BUFFER_OVERFLOW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI0_BUFFER_OVERFLOW_BUFFER_OVERFLOW_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI0_BUFFER_OVERFLOW_BUFFER_OVERFLOW_MASK)
/*! @} */

/*! @name CSI1_BUFFER_OVERFLOW - Buffer Overflow */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_CSI1_BUFFER_OVERFLOW_BUFFER_OVERFLOW_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_CSI1_BUFFER_OVERFLOW_BUFFER_OVERFLOW_SHIFT (0U)
/*! Buffer_Overflow - Set when the rate adaptation buffer overflows */
#define BLK_CTRL_CAMERAMIX_CSI1_BUFFER_OVERFLOW_BUFFER_OVERFLOW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_CSI1_BUFFER_OVERFLOW_BUFFER_OVERFLOW_SHIFT)) & BLK_CTRL_CAMERAMIX_CSI1_BUFFER_OVERFLOW_BUFFER_OVERFLOW_MASK)
/*! @} */

/*! @name PIXEL_FORMATTER_RST_CTRL - Reset control for pixel formatter0 and pixel formatter1 */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL0_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL0_SHIFT (0U)
/*! RST_SEL0 - Reset select for pixel formatter0
 *  0b0..IDI_RST and PL_RST of pixel_formatter0 are driven by cameramix_func_rst
 *  0b1..IDI_RST and PL_RST of pixel_formatter0 are driven by PIXEL_FORMATTER_RST_CTRL[1]
 */
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL0_SHIFT)) & BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL0_MASK)

#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST0_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST0_SHIFT (1U)
/*! SW_RST0 - Software reset for pixel formatter0.
 *  0b0..Software reset is asserted.
 *  0b1..Software reset is deasserted.
 */
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST0_SHIFT)) & BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST0_MASK)

#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL1_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL1_SHIFT (2U)
/*! RST_SEL1 - Reset select for pixel formatter1
 *  0b0..IDI_RST and PL_RST of pixel_formatter1 are driven by cameramix_func_rst
 *  0b1..IDI_RST and PL_RST of pixel_formatter1 are driven by PIXEL_FORMATTER_RST_CTRL[3]
 */
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL1_SHIFT)) & BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_RST_SEL1_MASK)

#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST1_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST1_SHIFT (3U)
/*! SW_RST1 - Software reset for pixel formatter1.
 *  0b0..Software reset is asserted.
 *  0b1..Software reset is deasserted.
 */
#define BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST1_SHIFT)) & BLK_CTRL_CAMERAMIX_PIXEL_FORMATTER_RST_CTRL_SW_RST1_MASK)
/*! @} */

/*! @name DISPLAY_PIXEL_LINK_SLV_CG - ISI Clock Gating Control for Display Pixel Link Target */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV0_CG_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV0_CG_SHIFT (0U)
/*! Pixel_Link_Slv0_CG - ISI Clock gating for Display Pixel Link Slv0
 *  0b0..Do not gate the ISI clock of Display Pixel Link Slv0
 *  0b1..Gate the ISI clock of Display Pixel Link Slv0
 */
#define BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV0_CG(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV0_CG_SHIFT)) & BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV0_CG_MASK)

#define BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV1_CG_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV1_CG_SHIFT (1U)
/*! Pixel_Link_Slv1_CG - ISI Clock gating for Display Pixel Link Slv1
 *  0b0..Do not gate the ISI clock of Display Pixel Link Slv1
 *  0b1..Gate the ISI clock of Display Pixel Link Slv1
 */
#define BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV1_CG(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV1_CG_SHIFT)) & BLK_CTRL_CAMERAMIX_DISPLAY_PIXEL_LINK_SLV_CG_PIXEL_LINK_SLV1_CG_MASK)
/*! @} */

/*! @name IPC_CLK_ON_OFF_CTRL_REG0 - IPC Clock Alternative Force ON/OFF Control */
/*! @{ */

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_0_MASK (0x1U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_0_SHIFT (0U)
/*! FORCE_ONOFF_0 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_0_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_0_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_0_MASK (0x2U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_0_SHIFT (1U)
/*! FORCE_ONOFF_SEL_0 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_0_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_0_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_1_MASK (0x4U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_1_SHIFT (2U)
/*! FORCE_ONOFF_1 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_1_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_1_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_1_MASK (0x8U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_1_SHIFT (3U)
/*! FORCE_ONOFF_SEL_1 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_1_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_1_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_2_MASK (0x10U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_2_SHIFT (4U)
/*! FORCE_ONOFF_2 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_2_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_2_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_2_MASK (0x20U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_2_SHIFT (5U)
/*! FORCE_ONOFF_SEL_2 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_2_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_2_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_3_MASK (0x40U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_3_SHIFT (6U)
/*! FORCE_ONOFF_3 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_3_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_3_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_3_MASK (0x80U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_3_SHIFT (7U)
/*! FORCE_ONOFF_SEL_3 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_3_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_3_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_4_MASK (0x100U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_4_SHIFT (8U)
/*! FORCE_ONOFF_4 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_4_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_4_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_4_MASK (0x200U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_4_SHIFT (9U)
/*! FORCE_ONOFF_SEL_4 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_4_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_4_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_5_MASK (0x400U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_5_SHIFT (10U)
/*! FORCE_ONOFF_5 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_5_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_5_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_5_MASK (0x800U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_5_SHIFT (11U)
/*! FORCE_ONOFF_SEL_5 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_5_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_5_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_6_MASK (0x1000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_6_SHIFT (12U)
/*! FORCE_ONOFF_6 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_6_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_6_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_6_MASK (0x2000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_6_SHIFT (13U)
/*! FORCE_ONOFF_SEL_6 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_6_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_6_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_7_MASK (0x4000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_7_SHIFT (14U)
/*! FORCE_ONOFF_7 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_7_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_7_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_7_MASK (0x8000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_7_SHIFT (15U)
/*! FORCE_ONOFF_SEL_7 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_7_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_7_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_8_MASK (0x10000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_8_SHIFT (16U)
/*! FORCE_ONOFF_8 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_8_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_8_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_8_MASK (0x20000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_8_SHIFT (17U)
/*! FORCE_ONOFF_SEL_8 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_8_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_8_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_9_MASK (0x40000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_9_SHIFT (18U)
/*! FORCE_ONOFF_9 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_9_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_9_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_9_MASK (0x80000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_9_SHIFT (19U)
/*! FORCE_ONOFF_SEL_9 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_9_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_9_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_10_MASK (0x100000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_10_SHIFT (20U)
/*! FORCE_ONOFF_10 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_10_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_10_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_10_MASK (0x200000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_10_SHIFT (21U)
/*! FORCE_ONOFF_SEL_10 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_10_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_10_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_11_MASK (0x400000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_11_SHIFT (22U)
/*! FORCE_ONOFF_11 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Force ipc clk off
 *  0b1..Force ipc clk on
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_11_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_11_MASK)

#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_11_MASK (0x800000U)
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_11_SHIFT (23U)
/*! FORCE_ONOFF_SEL_11 - IPC Clock Alternative Force ON/OFF Control
 *  0b0..Disable the function of alternative force on/off control.
 *  0b1..Enable the function of alternative force on/off control.
 */
#define BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_11_SHIFT)) & BLK_CTRL_CAMERAMIX_IPC_CLK_ON_OFF_CTRL_REG0_FORCE_ONOFF_SEL_11_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_CAMERAMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_CAMERAMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_CAMERAMIX_H_ */

