/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIPI_DSI_HOST
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_DSI_HOST.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 */

#if !defined(PERI_MIPI_DSI_HOST_H_)
#define PERI_MIPI_DSI_HOST_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- MIPI_DSI_HOST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_Peripheral_Access_Layer MIPI_DSI_HOST Peripheral Access Layer
 * @{
 */

/** MIPI_DSI_HOST - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_NUM_LANES;                     /**< Configure Number of Lanes, offset: 0x0 */
  __IO uint32_t CFG_NONCONTINUOUS_CLK;             /**< Configure Non-continuous Clock, offset: 0x4 */
  __IO uint32_t CFG_T_PRE;                         /**< Configure Pre Clock Periods, offset: 0x8 */
  __IO uint32_t CFG_T_POST;                        /**< Configure Post Clock Periods, offset: 0xC */
  __IO uint32_t CFG_TX_GAP;                        /**< Configure Gap Clock Periods, offset: 0x10 */
  __IO uint32_t CFG_AUTOINSERT_EOTP;               /**< Configure Autoinsert EOTP, offset: 0x14 */
  __IO uint32_t CFG_EXTRA_CMDS_AFTER_EOTP;         /**< Configure Extra Commands after EOTP, offset: 0x18 */
  __IO uint32_t CFG_HTX_TO_COUNT;                  /**< Configure High Speed Tx Timeout Count, offset: 0x1C */
  __IO uint32_t CFG_LRX_H_TO_COUNT;                /**< Configure Low Power Rx Timeout Count, offset: 0x20 */
  __IO uint32_t CFG_BTA_H_TO_COUNT;                /**< Configure Bus Turn Around Timeout Count, offset: 0x24 */
  __IO uint32_t CFG_TWAKEUP;                       /**< Configure Twakeup, offset: 0x28 */
  __I  uint32_t CFG_STATUS_OUT;                    /**< Configure Status Out, offset: 0x2C */
  __I  uint32_t RX_ERROR_STATUS;                   /**< Receive Error Status, offset: 0x30 */
  __IO uint32_t ULPS_ENABLE;                       /**< ULPS Enable, offset: 0x34 */
  __I  uint32_t ULPS_ACTIVE;                       /**< ULPS Active, offset: 0x38 */
  __IO uint32_t HS_MODE_ENABLE;                    /**< High Speed Mode Enable, offset: 0x3C */
  __IO uint32_t HOST_TURNAROUND;                   /**< Host Turnaround, offset: 0x40 */
  __I  uint32_t PHY_DIRECTION;                     /**< PHY Direction, offset: 0x44 */
  __I  uint32_t PHY_RDY;                           /**< PHY Ready, offset: 0x48 */
       uint8_t RESERVED_0[180];
  __IO uint32_t CFG_DBI_PIXEL_PAYLOAD_SIZE;        /**< Pixel Payload Size, offset: 0x100 */
  __IO uint32_t CFG_DBI_PIXEL_FIFO_SEND_LEVEL;     /**< Configure DBI Pixel FIFO Send Level, offset: 0x104 */
  __IO uint32_t CFG_DBI_PIXEL_FORMAT;              /**< DBI Pixel Format, offset: 0x108 */
  __I  uint32_t DBI_UNDERRUN_ERR;                  /**< DBI Underrun Error, offset: 0x10C */
  __I  uint32_t DBI_OVERFLOW_ERR;                  /**< DBI Overflow Error, offset: 0x110 */
       uint8_t RESERVED_1[236];
  __IO uint32_t CFG_DPI_PIXEL_PAYLOAD_SIZE;        /**< Configure DPI Pixel Payload Size, offset: 0x200 */
  __IO uint32_t CFG_DPI_PIXEL_FIFO_SEND_LEVEL;     /**< Configure DPI Pixel FIFO Send Level, offset: 0x204 */
  __IO uint32_t CFG_DPI_INTERFACE_COLOR_CODING;    /**< Configure DPI Interface Color Coding, offset: 0x208 */
  __IO uint32_t CFG_DPI_PIXEL_FORMAT;              /**< Configure DPI Pixel Format, offset: 0x20C */
  __IO uint32_t CFG_DPI_VSYNC_POLARITY;            /**< Configure DPI vsync Polarity, offset: 0x210 */
  __IO uint32_t CFG_DPI_HSYNC_POLARITY;            /**< Configure DPI hsync Polarity, offset: 0x214 */
  __IO uint32_t CFG_DPI_VIDEO_MODE;                /**< Configure DPI Video Mode, offset: 0x218 */
  __IO uint32_t CFG_DPI_HFP;                       /**< Configure DPI horizontal front porch, offset: 0x21C */
  __IO uint32_t CFG_DPI_HBP;                       /**< Configure DPI Horizontal Back Porch, offset: 0x220 */
  __IO uint32_t CFG_DPI_HSA;                       /**< Configure DPI Horizontal Sync Width, offset: 0x224 */
  __IO uint32_t CFG_DPI_ENABLE_MULT_PKTS;          /**< Enable Multiple Packets, offset: 0x228 */
  __IO uint32_t CFG_DPI_VBP;                       /**< Configure DPI Vertical Back Porch, offset: 0x22C */
  __IO uint32_t CFG_DPI_VFP;                       /**< Configure DPI Vertical Front Porch, offset: 0x230 */
  __IO uint32_t CFG_DPI_BLLP_MODE;                 /**< Configure DPI BLLP Mode, offset: 0x234 */
  __IO uint32_t CFG_DPI_USE_NULL_PKT_BLLP;         /**< Configure DPI Blank Packet in BLLP, offset: 0x238 */
  __IO uint32_t CFG_DPI_VACTIVE;                   /**< Configure DPI Vertical Active, offset: 0x23C */
  __IO uint32_t CFG_DPI_VC;                        /**< Configure DPI Virtual Channel, offset: 0x240 */
  __I  uint32_t DPI_UNDERRUN_ERR;                  /**< DPI Underrun Error, offset: 0x244 */
       uint8_t RESERVED_2[56];
  __IO uint32_t TX_PAYLOAD;                        /**< Transmit Payload, offset: 0x280 */
  __IO uint32_t PKT_CONTROL;                       /**< Packet Control, offset: 0x284 */
  __IO uint32_t SEND_PACKET;                       /**< Send Packet, offset: 0x288 */
  __I  uint32_t PKT_STATUS;                        /**< Packet Status, offset: 0x28C */
  __I  uint32_t PKT_FIFO_WR_LEVEL;                 /**< Packet FIFO Write, offset: 0x290 */
  __I  uint32_t PKT_FIFO_RD_LEVEL;                 /**< Packet FIFO Read, offset: 0x294 */
  __I  uint32_t PKT_RX_PAYLOAD;                    /**< Packet Rx Payload, offset: 0x298 */
  __I  uint32_t PKT_RX_PKT_HEADER;                 /**< Packet Rx Packet Header, offset: 0x29C */
  __I  uint32_t IRQ_STATUS;                        /**< Interrupt Status, offset: 0x2A0 */
  __I  uint32_t IRQ_STATUS2;                       /**< Interrupt Status 2, offset: 0x2A4 */
  __IO uint32_t IRQ_MASK;                          /**< Mask Interrupt, offset: 0x2A8 */
  __IO uint32_t IRQ_MASK2;                         /**< Interrupt Mask 2, offset: 0x2AC */
       uint8_t RESERVED_3[80];
  __IO uint32_t PD_DPHY;                           /**< DPHY Power Down, offset: 0x300 */
  __IO uint32_t M_PRG_HS_PREPARE;                  /**< Program T_HS_PREPARE, offset: 0x304 */
  __IO uint32_t MC_PRG_HS_PREPARE;                 /**< Program HS T_CLK_PREPARE, offset: 0x308 */
  __IO uint32_t M_PRG_HS_ZERO;                     /**< Program T_HS_ZERO, offset: 0x30C */
  __IO uint32_t MC_PRG_HS_ZERO;                    /**< Program T_CLK_ZERO, offset: 0x310 */
  __IO uint32_t M_PRG_HS_TRAIL;                    /**< Program T_HS_TRAIL, offset: 0x314 */
  __IO uint32_t MC_PRG_HS_TRAIL;                   /**< Program T_CLK_TRAIL, offset: 0x318 */
  __IO uint32_t TST;                               /**< DPHY TST Input, offset: 0x31C */
  __IO uint32_t RTERM_SEL;                         /**< RTERM Select, offset: 0x320 */
  __IO uint32_t AUTO_PD_EN;                        /**< Power Down Auto Enable, offset: 0x324 */
  __IO uint32_t RXLPRP;                            /**< DPHY RXLPRP Input, offset: 0x328 */
  __IO uint32_t RXCDRP;                            /**< DPHY RXCDRP Input, offset: 0x32C */
} MIPI_DSI_HOST_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI_HOST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_Register_Masks MIPI_DSI_HOST Register Masks
 * @{
 */

/*! @name CFG_NUM_LANES - Configure Number of Lanes */
/*! @{ */

#define MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_SHIFT (0U)
/*! CFG_NUM_LANES - Configure Number of Lanes
 *  0b00..1 Lane
 *  0b01..2 Lanes
 *  0b10..3 Lanes
 *  0b11..4 Lanes
 */
#define MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_SHIFT)) & MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_MASK)
/*! @} */

/*! @name CFG_NONCONTINUOUS_CLK - Configure Non-continuous Clock */
/*! @{ */

#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_SHIFT (0U)
/*! CFG_NONCONTINUOUS_CLK - Configure Non-continuous Clock
 *  0b0..Continuous high speed clock
 *  0b1..Non-Continuous high speed clock
 */
#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_SHIFT)) & MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_MASK)
/*! @} */

/*! @name CFG_T_PRE - Configure Pre Clock Periods */
/*! @{ */

#define MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_MASK   (0xFFU)
#define MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_SHIFT  (0U)
/*! CFG_T_PRE - Configure Pre Clock Periods */
#define MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_SHIFT)) & MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_MASK)
/*! @} */

/*! @name CFG_T_POST - Configure Post Clock Periods */
/*! @{ */

#define MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_SHIFT (0U)
/*! CFG_T_POST - Configure Post Clock Periods */
#define MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_SHIFT)) & MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_MASK)
/*! @} */

/*! @name CFG_TX_GAP - Configure Gap Clock Periods */
/*! @{ */

#define MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_SHIFT (0U)
/*! CFG_TX_GAP - Configure Gap Clock Periods */
#define MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_SHIFT)) & MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_MASK)
/*! @} */

/*! @name CFG_AUTOINSERT_EOTP - Configure Autoinsert EOTP */
/*! @{ */

#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_SHIFT (0U)
/*! CFG_AUTOINSERT_EOTP - Configure Autoinsert EOTP
 *  0b0..EOTP is not automatically inserted
 *  0b1..EOTP is automatically inserted
 */
#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_SHIFT)) & MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_MASK)
/*! @} */

/*! @name CFG_EXTRA_CMDS_AFTER_EOTP - Configure Extra Commands after EOTP */
/*! @{ */

#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_SHIFT (0U)
/*! CFG_EXTRA_CMDS_AFTER_EOTP - Configure Extra Commands after EOTP */
#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_SHIFT)) & MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_MASK)
/*! @} */

/*! @name CFG_HTX_TO_COUNT - Configure High Speed Tx Timeout Count */
/*! @{ */

#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_SHIFT (0U)
/*! CFG_HTX_TO_COUNT - Configure High Speed Tx Timeout Count */
#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_LRX_H_TO_COUNT - Configure Low Power Rx Timeout Count */
/*! @{ */

#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_SHIFT (0U)
/*! CFG_LRX_H_TO_COUNT - Configure Low Power Rx Timeout Count */
#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_BTA_H_TO_COUNT - Configure Bus Turn Around Timeout Count */
/*! @{ */

#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_SHIFT (0U)
/*! CFG_BTA_H_TO_COUNT - Configure Bus Turn Around Timeout Count */
#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_TWAKEUP - Configure Twakeup */
/*! @{ */

#define MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_MASK (0x7FFFFU)
#define MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_SHIFT (0U)
/*! CFG_TWAKEUP - DPHY Twakeup Timing Parameter */
#define MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_SHIFT)) & MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_MASK)
/*! @} */

/*! @name CFG_STATUS_OUT - Configure Status Out */
/*! @{ */

#define MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_SHIFT (0U)
/*! CFG_STATUS_OUT - Configure Status Out */
#define MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_SHIFT)) & MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_MASK)
/*! @} */

/*! @name RX_ERROR_STATUS - Receive Error Status */
/*! @{ */

#define MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_MASK (0x7FFU)
#define MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_SHIFT (0U)
/*! RX_ERROR_STATUS - Receive Error Status */
#define MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_SHIFT)) & MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_MASK)
/*! @} */

/*! @name ULPS_ENABLE - ULPS Enable */
/*! @{ */

#define MIPI_DSI_HOST_ULPS_ENABLE_EN0_MASK       (0x1U)
#define MIPI_DSI_HOST_ULPS_ENABLE_EN0_SHIFT      (0U)
/*! EN0 - Enable Clock Lane
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_HOST_ULPS_ENABLE_EN0(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ENABLE_EN0_SHIFT)) & MIPI_DSI_HOST_ULPS_ENABLE_EN0_MASK)

#define MIPI_DSI_HOST_ULPS_ENABLE_EN1_MASK       (0x2U)
#define MIPI_DSI_HOST_ULPS_ENABLE_EN1_SHIFT      (1U)
/*! EN1 - Enable Data Lane 0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_HOST_ULPS_ENABLE_EN1(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ENABLE_EN1_SHIFT)) & MIPI_DSI_HOST_ULPS_ENABLE_EN1_MASK)

#define MIPI_DSI_HOST_ULPS_ENABLE_EN2_MASK       (0x4U)
#define MIPI_DSI_HOST_ULPS_ENABLE_EN2_SHIFT      (2U)
/*! EN2 - Enable Data Lane 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_HOST_ULPS_ENABLE_EN2(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ENABLE_EN2_SHIFT)) & MIPI_DSI_HOST_ULPS_ENABLE_EN2_MASK)

#define MIPI_DSI_HOST_ULPS_ENABLE_EN3_MASK       (0x8U)
#define MIPI_DSI_HOST_ULPS_ENABLE_EN3_SHIFT      (3U)
/*! EN3 - Enable Data Lane 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_HOST_ULPS_ENABLE_EN3(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ENABLE_EN3_SHIFT)) & MIPI_DSI_HOST_ULPS_ENABLE_EN3_MASK)

#define MIPI_DSI_HOST_ULPS_ENABLE_EN4_MASK       (0x10U)
#define MIPI_DSI_HOST_ULPS_ENABLE_EN4_SHIFT      (4U)
/*! EN4 - Enable Data Lane 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_HOST_ULPS_ENABLE_EN4(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ENABLE_EN4_SHIFT)) & MIPI_DSI_HOST_ULPS_ENABLE_EN4_MASK)
/*! @} */

/*! @name ULPS_ACTIVE - ULPS Active */
/*! @{ */

#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE0_MASK   (0x1U)
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE0_SHIFT  (0U)
/*! ACTIVE0 - Clock Lane ULPS Active
 *  0b0..ULPS inactive
 *  0b1..ULPS active
 */
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE0(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE0_SHIFT)) & MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE0_MASK)

#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE1_MASK   (0x2U)
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE1_SHIFT  (1U)
/*! ACTIVE1 - Data Lane 0 ULPS ACTIVE
 *  0b0..ULPS inactive
 *  0b1..ULPS active
 */
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE1(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE1_SHIFT)) & MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE1_MASK)

#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE2_MASK   (0x4U)
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE2_SHIFT  (2U)
/*! ACTIVE2 - Data Lane 1 ULPS ACTIVE
 *  0b0..ULPS inactive
 *  0b1..ULPS active
 */
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE2(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE2_SHIFT)) & MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE2_MASK)

#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE3_MASK   (0x8U)
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE3_SHIFT  (3U)
/*! ACTIVE3 - Data Lane 2 ULPS ACTIVE
 *  0b0..ULPS inactive
 *  0b1..ULPS active
 */
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE3(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE3_SHIFT)) & MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE3_MASK)

#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE4_MASK   (0x10U)
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE4_SHIFT  (4U)
/*! ACTIVE4 - Data Lane 3 ULPS ACTIVE
 *  0b0..ULPS inactive
 *  0b1..ULPS active
 */
#define MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE4(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE4_SHIFT)) & MIPI_DSI_HOST_ULPS_ACTIVE_ACTIVE4_MASK)
/*! @} */

/*! @name HS_MODE_ENABLE - High Speed Mode Enable */
/*! @{ */

#define MIPI_DSI_HOST_HS_MODE_ENABLE_ENABLE_MASK (0x1U)
#define MIPI_DSI_HOST_HS_MODE_ENABLE_ENABLE_SHIFT (0U)
/*! ENABLE - Enable
 *  0b0..All transmissions in Low Power Data transmission mode.
 *  0b1..All transmissions in High Speed mode.
 */
#define MIPI_DSI_HOST_HS_MODE_ENABLE_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_HS_MODE_ENABLE_ENABLE_SHIFT)) & MIPI_DSI_HOST_HS_MODE_ENABLE_ENABLE_MASK)
/*! @} */

/*! @name HOST_TURNAROUND - Host Turnaround */
/*! @{ */

#define MIPI_DSI_HOST_HOST_TURNAROUND_REQUEST_BTA_MASK (0x1U)
#define MIPI_DSI_HOST_HOST_TURNAROUND_REQUEST_BTA_SHIFT (0U)
/*! REQUEST_BTA - Request BTA
 *  0b0..No Request
 *  0b1..Request BTA
 */
#define MIPI_DSI_HOST_HOST_TURNAROUND_REQUEST_BTA(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_HOST_TURNAROUND_REQUEST_BTA_SHIFT)) & MIPI_DSI_HOST_HOST_TURNAROUND_REQUEST_BTA_MASK)
/*! @} */

/*! @name PHY_DIRECTION - PHY Direction */
/*! @{ */

#define MIPI_DSI_HOST_PHY_DIRECTION_STATUS_MASK  (0x1U)
#define MIPI_DSI_HOST_PHY_DIRECTION_STATUS_SHIFT (0U)
/*! STATUS - PHY Direction
 *  0b0..Default PHY direction
 *  0b1..Reversed PHY direction
 */
#define MIPI_DSI_HOST_PHY_DIRECTION_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PHY_DIRECTION_STATUS_SHIFT)) & MIPI_DSI_HOST_PHY_DIRECTION_STATUS_MASK)
/*! @} */

/*! @name PHY_RDY - PHY Ready */
/*! @{ */

#define MIPI_DSI_HOST_PHY_RDY_STATUS_MASK        (0x1U)
#define MIPI_DSI_HOST_PHY_RDY_STATUS_SHIFT       (0U)
/*! STATUS - PHY Ready Status
 *  0b0..DPHY not ready
 *  0b1..DPHY ready
 */
#define MIPI_DSI_HOST_PHY_RDY_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PHY_RDY_STATUS_SHIFT)) & MIPI_DSI_HOST_PHY_RDY_STATUS_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_PAYLOAD_SIZE - Pixel Payload Size */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_SHIFT (0U)
/*! CFG_DBI_PIXEL_PAYLOAD_SIZE - Pixel Payload Size */
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_FIFO_SEND_LEVEL - Configure DBI Pixel FIFO Send Level */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! CFG_DBI_PIXEL_FIFO_SEND_LEVEL - Configure DBI Pixel FIFO Send Level */
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_SHIFT)) & MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_FORMAT - DBI Pixel Format */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FORMAT_FORMAT_MASK (0x7U)
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FORMAT_FORMAT_SHIFT (0U)
/*! FORMAT - DBI Pixel Format Options
 *  0b000..Default. No pixel to byte mapping
 *  0b001..Option 1: RGB888
 *  0b010..Option 2: RGB666
 *  0b011..Option 3: RGB565
 *  0b100..Option 4: RGB444
 *  0b101..Option 5: RGB332
 *  0b110-0b111..
 */
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FORMAT_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DBI_PIXEL_FORMAT_FORMAT_SHIFT)) & MIPI_DSI_HOST_CFG_DBI_PIXEL_FORMAT_FORMAT_MASK)
/*! @} */

/*! @name DBI_UNDERRUN_ERR - DBI Underrun Error */
/*! @{ */

#define MIPI_DSI_HOST_DBI_UNDERRUN_ERR_ERROR_MASK (0x1U)
#define MIPI_DSI_HOST_DBI_UNDERRUN_ERR_ERROR_SHIFT (0U)
/*! ERROR - Error
 *  0b0..No Error
 *  0b1..Error
 */
#define MIPI_DSI_HOST_DBI_UNDERRUN_ERR_ERROR(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DBI_UNDERRUN_ERR_ERROR_SHIFT)) & MIPI_DSI_HOST_DBI_UNDERRUN_ERR_ERROR_MASK)
/*! @} */

/*! @name DBI_OVERFLOW_ERR - DBI Overflow Error */
/*! @{ */

#define MIPI_DSI_HOST_DBI_OVERFLOW_ERR_ERROR_MASK (0x1U)
#define MIPI_DSI_HOST_DBI_OVERFLOW_ERR_ERROR_SHIFT (0U)
/*! ERROR - Error
 *  0b0..No Error
 *  0b1..Error
 */
#define MIPI_DSI_HOST_DBI_OVERFLOW_ERR_ERROR(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DBI_OVERFLOW_ERR_ERROR_SHIFT)) & MIPI_DSI_HOST_DBI_OVERFLOW_ERR_ERROR_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_PAYLOAD_SIZE - Configure DPI Pixel Payload Size */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_SHIFT (0U)
/*! CFG_DPI_PIXEL_PAYLOAD_SIZE - Configure DPI Pixel Payload */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_FIFO_SEND_LEVEL - Configure DPI Pixel FIFO Send Level */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! CFG_DPI_PIXEL_FIFO_SEND_LEVEL - Configure DPI Pixel FIFO Send Level */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name CFG_DPI_INTERFACE_COLOR_CODING - Configure DPI Interface Color Coding */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_MASK (0x7U)
#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_SHIFT (0U)
/*! CFG_DPI_INTERFACE_COLOR_CODING - Configure DPI Interface Color Coding */
#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_FORMAT - Configure DPI Pixel Format */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_SHIFT (0U)
/*! CFG_DPI_PIXEL_FORMAT - Configure DPI Pixel Format */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_MASK)
/*! @} */

/*! @name CFG_DPI_VSYNC_POLARITY - Configure DPI vsync Polarity */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_SHIFT (0U)
/*! CFG_DPI_VSYNC_POLARITY - Configure DPI vsync Polarity */
#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_MASK)
/*! @} */

/*! @name CFG_DPI_HSYNC_POLARITY - Configure DPI hsync Polarity */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_SHIFT (0U)
/*! CFG_DPI_HSYNC_POLARITY - Configure DPI hsync Polarity */
#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_MASK)
/*! @} */

/*! @name CFG_DPI_VIDEO_MODE - Configure DPI Video Mode */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_SHIFT (0U)
/*! CFG_DPI_VIDEO_MODE - Configure DPI Video Mode */
#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_MASK)
/*! @} */

/*! @name CFG_DPI_HFP - Configure DPI horizontal front porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_SHIFT (0U)
/*! CFG_DPI_HFP - Configure DPI Horizontal Front Porch */
#define MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_MASK)
/*! @} */

/*! @name CFG_DPI_HBP - Configure DPI Horizontal Back Porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_SHIFT (0U)
/*! CFG_DPI_HBP - Configure DPI Horizontal Back Porch */
#define MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_MASK)
/*! @} */

/*! @name CFG_DPI_HSA - Configure DPI Horizontal Sync Width */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_SHIFT (0U)
/*! CFG_DPI_HSA - Configure DPI Horizontal Sync Width */
#define MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_MASK)
/*! @} */

/*! @name CFG_DPI_ENABLE_MULT_PKTS - Enable Multiple Packets */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_SHIFT (0U)
/*! CFG_DPI_ENABLE_MULT_PKTS - Enable Multiple Packets Per Video Line. */
#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_MASK)
/*! @} */

/*! @name CFG_DPI_VBP - Configure DPI Vertical Back Porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_MASK (0xFFFU)
#define MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_SHIFT (0U)
/*! CFG_DPI_VBP - Configure DPI Vertical Back Porch */
#define MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_MASK)
/*! @} */

/*! @name CFG_DPI_VFP - Configure DPI Vertical Front Porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_MASK (0xFFFU)
#define MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_SHIFT (0U)
/*! CFG_DPI_VFP - Configure DPI VPP */
#define MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_MASK)
/*! @} */

/*! @name CFG_DPI_BLLP_MODE - Configure DPI BLLP Mode */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_SHIFT (0U)
/*! CFG_DPI_BLLP_MODE - Configure DPI BLLP Mode */
#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_MASK)
/*! @} */

/*! @name CFG_DPI_USE_NULL_PKT_BLLP - Configure DPI Blank Packet in BLLP */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_SHIFT (0U)
/*! CFG_DPI_USE_NULL_PKT_BLLP - Configure DPI Blank Packet in BLLP */
#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_MASK)
/*! @} */

/*! @name CFG_DPI_VACTIVE - Configure DPI Vertical Active */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_MASK (0x3FFFU)
#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_SHIFT (0U)
/*! CFG_DPI_VACTIVE - Configure DPI Vertical Active */
#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_MASK)
/*! @} */

/*! @name CFG_DPI_VC - Configure DPI Virtual Channel */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_SHIFT (0U)
/*! CFG_DPI_VC - Configure DPI Virtual Channel */
#define MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_MASK)
/*! @} */

/*! @name DPI_UNDERRUN_ERR - DPI Underrun Error */
/*! @{ */

#define MIPI_DSI_HOST_DPI_UNDERRUN_ERR_ERR_MASK  (0x1U)
#define MIPI_DSI_HOST_DPI_UNDERRUN_ERR_ERR_SHIFT (0U)
/*! ERR - Error detected
 *  0b0..No error
 *  0b1..Error
 */
#define MIPI_DSI_HOST_DPI_UNDERRUN_ERR_ERR(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DPI_UNDERRUN_ERR_ERR_SHIFT)) & MIPI_DSI_HOST_DPI_UNDERRUN_ERR_ERR_MASK)
/*! @} */

/*! @name TX_PAYLOAD - Transmit Payload */
/*! @{ */

#define MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_SHIFT (0U)
/*! TX_PAYLOAD - Tx Payload Data Write */
#define MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_SHIFT)) & MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_CONTROL - Packet Control */
/*! @{ */

#define MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_MASK (0x7FFFFFFU)
#define MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_SHIFT (0U)
/*! PKT_CONTROL - Tx Packet Control */
#define MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_SHIFT)) & MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_MASK)
/*! @} */

/*! @name SEND_PACKET - Send Packet */
/*! @{ */

#define MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_MASK (0x1U)
#define MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_SHIFT (0U)
/*! SEND_PACKET - Send Packet */
#define MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_SHIFT)) & MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_MASK)
/*! @} */

/*! @name PKT_STATUS - Packet Status */
/*! @{ */

#define MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_MASK (0x1FFU)
#define MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_SHIFT (0U)
/*! PKT_STATUS - Packet Status */
#define MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_SHIFT)) & MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_MASK)
/*! @} */

/*! @name PKT_FIFO_WR_LEVEL - Packet FIFO Write */
/*! @{ */

#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_SHIFT (0U)
/*! PKT_FIFO_WR_LEVEL - Packet FIFO Write Level */
#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_SHIFT)) & MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_MASK)
/*! @} */

/*! @name PKT_FIFO_RD_LEVEL - Packet FIFO Read */
/*! @{ */

#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_SHIFT (0U)
/*! PKT_FIFO_RD_LEVEL - Packet FIFO Read Level */
#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_SHIFT)) & MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_MASK)
/*! @} */

/*! @name PKT_RX_PAYLOAD - Packet Rx Payload */
/*! @{ */

#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_SHIFT (0U)
/*! PKT_RX_PAYLOAD - Packet Rx Payload */
#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_SHIFT)) & MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_RX_PKT_HEADER - Packet Rx Packet Header */
/*! @{ */

#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_SHIFT (0U)
/*! PKT_RX_PKT_HEADER - Packet Rx Packet Header */
#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_SHIFT)) & MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_MASK)
/*! @} */

/*! @name IRQ_STATUS - Interrupt Status */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_SHIFT (0U)
/*! IRQ_STATUS - Interrupt Status */
#define MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_SHIFT)) & MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_MASK)
/*! @} */

/*! @name IRQ_STATUS2 - Interrupt Status 2 */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_MASK (0x7U)
#define MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_SHIFT (0U)
/*! IRQ_STATUS2 - Interrupt Status 2 */
#define MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_SHIFT)) & MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_MASK)
/*! @} */

/*! @name IRQ_MASK - Mask Interrupt */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_MASK     (0xFFFFFFFFU)
#define MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_SHIFT    (0U)
/*! IRQ_MASK - Mask Interrupt */
#define MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_SHIFT)) & MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_MASK)
/*! @} */

/*! @name IRQ_MASK2 - Interrupt Mask 2 */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_MASK   (0x7U)
#define MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_SHIFT  (0U)
/*! irq_mask2 - Interrupt Mask 2 */
#define MIPI_DSI_HOST_IRQ_MASK2_irq_mask2(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_SHIFT)) & MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_MASK)
/*! @} */

/*! @name PD_DPHY - DPHY Power Down */
/*! @{ */

#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY_MASK       (0x1U)
#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY_SHIFT      (0U)
/*! PD_DPHY - Power Down Input for D-PHY
 *  0b0..Power up
 *  0b1..Power down
 */
#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PD_DPHY_PD_DPHY_SHIFT)) & MIPI_DSI_HOST_PD_DPHY_PD_DPHY_MASK)
/*! @} */

/*! @name M_PRG_HS_PREPARE - Program T_HS_PREPARE */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_MASK (0x3U)
#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_SHIFT (0U)
/*! M_PRG_HS_PREPARE - DPHY m_PRG_HS_PREPARE Input */
#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_MASK)
/*! @} */

/*! @name MC_PRG_HS_PREPARE - Program HS T_CLK_PREPARE */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_MASK (0x1U)
#define MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_SHIFT (0U)
/*! MC_PRG_HS_PREPARE - DPHY mc_PRG_HS_PREPARE input */
#define MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_MASK)
/*! @} */

/*! @name M_PRG_HS_ZERO - Program T_HS_ZERO */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_MASK (0x1FU)
#define MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_SHIFT (0U)
/*! M_PRG_HS_ZERO - DPHY m_PRG_HS_ZERO Input */
#define MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name MC_PRG_HS_ZERO - Program T_CLK_ZERO */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_MASK (0x3FU)
#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_SHIFT (0U)
/*! MC_PRG_HS_ZERO - DPHY mc_PRG_HS_ZERO Input */
#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name M_PRG_HS_TRAIL - Program T_HS_TRAIL */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_MASK (0xFU)
#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_SHIFT (0U)
/*! M_PRG_HS_TRAIL - DPHY m_PRG_HS_TRAIL Input */
#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name MC_PRG_HS_TRAIL - Program T_CLK_TRAIL */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_MASK (0xFU)
#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_SHIFT (0U)
/*! MC_PRG_HS_TRAIL - DPHY mc_PRG_HS_TRAIL input */
#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name TST - DPHY TST Input */
/*! @{ */

#define MIPI_DSI_HOST_TST_TST_MASK               (0x3FU)
#define MIPI_DSI_HOST_TST_TST_SHIFT              (0U)
/*! TST - DPHY TST Input */
#define MIPI_DSI_HOST_TST_TST(x)                 (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_TST_TST_SHIFT)) & MIPI_DSI_HOST_TST_TST_MASK)
/*! @} */

/*! @name RTERM_SEL - RTERM Select */
/*! @{ */

#define MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_MASK   (0x1U)
#define MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_SHIFT  (0U)
/*! RTERM_SEL - DPHY RTERM_SEL Input
 *  0b0..LPCD levels enables HS termination (VIL-CD).
 *  0b1..LPRX levels enables HS terminations (LP-VIL).
 */
#define MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_SHIFT)) & MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_MASK)
/*! @} */

/*! @name AUTO_PD_EN - Power Down Auto Enable */
/*! @{ */

#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_MASK (0x1U)
#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_SHIFT (0U)
/*! AUTO_PD_EN - Power Down Auto Enable Input
 *  0b0..Inactive lanes are powered up and driving LP11.
 *  0b1..Inactive lanes are powered down.
 */
#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_SHIFT)) & MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_MASK)
/*! @} */

/*! @name RXLPRP - DPHY RXLPRP Input */
/*! @{ */

#define MIPI_DSI_HOST_RXLPRP_RXLPRP_MASK         (0x3U)
#define MIPI_DSI_HOST_RXLPRP_RXLPRP_SHIFT        (0U)
/*! RXLPRP - DPHY RXLPRP Input */
#define MIPI_DSI_HOST_RXLPRP_RXLPRP(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RXLPRP_RXLPRP_SHIFT)) & MIPI_DSI_HOST_RXLPRP_RXLPRP_MASK)
/*! @} */

/*! @name RXCDRP - DPHY RXCDRP Input */
/*! @{ */

#define MIPI_DSI_HOST_RXCDRP_RXCDRP_MASK         (0x3U)
#define MIPI_DSI_HOST_RXCDRP_RXCDRP_SHIFT        (0U)
/*! RXCDRP - DPHY RXCDRP Input */
#define MIPI_DSI_HOST_RXCDRP_RXCDRP(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RXCDRP_RXCDRP_SHIFT)) & MIPI_DSI_HOST_RXCDRP_RXCDRP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_DSI_HOST_H_ */

