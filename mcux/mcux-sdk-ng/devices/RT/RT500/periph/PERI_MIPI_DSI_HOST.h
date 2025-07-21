/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_DSI_HOST.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 */

#if !defined(PERI_MIPI_DSI_HOST_H_)
#define PERI_MIPI_DSI_HOST_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
  __IO uint32_t CFG_NUM_LANES;                     /**< Configure number of lanes, offset: 0x0 */
  __IO uint32_t CFG_NONCONTINUOUS_CLK;             /**< Configure non-continuous clock, offset: 0x4 */
  __IO uint32_t CFG_T_PRE;                         /**< Configure pre clock periods, offset: 0x8 */
  __IO uint32_t CFG_T_POST;                        /**< Configure post clock periods, offset: 0xC */
  __IO uint32_t CFG_TX_GAP;                        /**< Configure gap clock periods, offset: 0x10 */
  __IO uint32_t CFG_AUTOINSERT_EOTP;               /**< Configure autoinsert EOTP, offset: 0x14 */
  __IO uint32_t CFG_EXTRA_CMDS_AFTER_EOTP;         /**< Configure extra commands after EOTP, offset: 0x18 */
  __IO uint32_t CFG_HTX_TO_COUNT;                  /**< Configure high speed Tx timout count, offset: 0x1C */
  __IO uint32_t CFG_LRX_H_TO_COUNT;                /**< Configure low power Rx timout count, offset: 0x20 */
  __IO uint32_t CFG_BTA_H_TO_COUNT;                /**< Configure bus turn around timout count, offset: 0x24 */
  __IO uint32_t CFG_TWAKEUP;                       /**< Configure Twakeup, offset: 0x28 */
  __I  uint32_t CFG_STATUS_OUT;                    /**< Configure status register, offset: 0x2C */
  __I  uint32_t RX_ERROR_STATUS;                   /**< Status register to receive error, offset: 0x30 */
       uint8_t RESERVED_0[204];
  __IO uint32_t CFG_DBI_PIXEL_PAYLOAD_SIZE;        /**< Pixel payload size, offset: 0x100 */
  __IO uint32_t CFG_DBI_PIXEL_FIFO_SEND_LEVEL;     /**< Configure DBI pixel FIFO send level, offset: 0x104 */
       uint8_t RESERVED_1[248];
  __IO uint32_t CFG_DPI_PIXEL_PAYLOAD_SIZE;        /**< Configure DPI pixel payload size, offset: 0x200 */
  __IO uint32_t CFG_DPI_PIXEL_FIFO_SEND_LEVEL;     /**< Configure DPI pixel FIFO send level, offset: 0x204 */
  __IO uint32_t CFG_DPI_INTERFACE_COLOR_CODING;    /**< Configure DPI interface color coding, offset: 0x208 */
  __IO uint32_t CFG_DPI_PIXEL_FORMAT;              /**< Configure DPI pixel format, offset: 0x20C */
  __IO uint32_t CFG_DPI_VSYNC_POLARITY;            /**< Configure DPI vsync polarity, offset: 0x210 */
  __IO uint32_t CFG_DPI_HSYNC_POLARITY;            /**< Configure DPI hsync polarity, offset: 0x214 */
  __IO uint32_t CFG_DPI_VIDEO_MODE;                /**< Configure DPI video mode, offset: 0x218 */
  __IO uint32_t CFG_DPI_HFP;                       /**< Configure DPI horizontal front porch, offset: 0x21C */
  __IO uint32_t CFG_DPI_HBP;                       /**< Configure DPI horizontal back porch, offset: 0x220 */
  __IO uint32_t CFG_DPI_HSA;                       /**< Configure DPI horizontal sync width, offset: 0x224 */
  __IO uint32_t CFG_DPI_ENABLE_MULT_PKTS;          /**< Enable multiple packtes, offset: 0x228 */
  __IO uint32_t CFG_DPI_VBP;                       /**< Configure DPI vertical back porch, offset: 0x22C */
  __IO uint32_t CFG_DPI_VFP;                       /**< Configure DPI vertical front porch, offset: 0x230 */
  __IO uint32_t CFG_DPI_BLLP_MODE;                 /**< Configure DPI BLLP mode, offset: 0x234 */
  __IO uint32_t CFG_DPI_USE_NULL_PKT_BLLP;         /**< Configure DPI blank packet in BLLP, offset: 0x238 */
  __IO uint32_t CFG_DPI_VACTIVE;                   /**< Configure DPI vertical active, offset: 0x23C */
  __IO uint32_t CFG_DPI_VC;                        /**< Configure DPI virtual channel, offset: 0x240 */
       uint8_t RESERVED_2[60];
  __IO uint32_t TX_PAYLOAD;                        /**< Transmit payload, offset: 0x280 */
  __IO uint32_t PKT_CONTROL;                       /**< Packet control, offset: 0x284 */
  __IO uint32_t SEND_PACKET;                       /**< Send packet, offset: 0x288 */
  __I  uint32_t PKT_STATUS;                        /**< Packet status, offset: 0x28C */
  __I  uint32_t PKT_FIFO_WR_LEVEL;                 /**< Packet FIFO write, offset: 0x290 */
  __I  uint32_t PKT_FIFO_RD_LEVEL;                 /**< Packet FIFO read, offset: 0x294 */
  __I  uint32_t PKT_RX_PAYLOAD;                    /**< Packet Rx payload, offset: 0x298 */
  __I  uint32_t PKT_RX_PKT_HEADER;                 /**< Packet Rx packet header, offset: 0x29C */
  __I  uint32_t IRQ_STATUS;                        /**< Interrupt status, offset: 0x2A0 */
  __I  uint32_t IRQ_STATUS2;                       /**< Interrupt status 2, offset: 0x2A4 */
  __IO uint32_t IRQ_MASK;                          /**< Mask interrupt, offset: 0x2A8 */
  __IO uint32_t IRQ_MASK2;                         /**< Interrupt mask 2, offset: 0x2AC */
       uint8_t RESERVED_3[80];
  __IO uint32_t PD_DPHY;                           /**< DPHY power down, offset: 0x300 */
  __IO uint32_t M_PRG_HS_PREPARE;                  /**< Program T_HS_PREPARE, offset: 0x304 */
  __IO uint32_t MC_PRG_HS_PREPARE;                 /**< Program HS T_CLK_PREPARE, offset: 0x308 */
  __IO uint32_t M_PRG_HS_ZERO;                     /**< Program T_HS_ZERO, offset: 0x30C */
  __IO uint32_t MC_PRG_HS_ZERO;                    /**< Program T_CLK_ZERO, offset: 0x310 */
  __IO uint32_t M_PRG_HS_TRAIL;                    /**< Program T_HS_TRAIL, offset: 0x314 */
  __IO uint32_t MC_PRG_HS_TRAIL;                   /**< Program T_CLK_TRAIL, offset: 0x318 */
  __IO uint32_t TST;                               /**< DPHY TST input, offset: 0x31C */
  __IO uint32_t RTERM_SEL;                         /**< RTERM select, offset: 0x320 */
  __IO uint32_t AUTO_PD_EN;                        /**< Power down auto enable, offset: 0x324 */
  __IO uint32_t RXLPRP;                            /**< DPHY RXLPRP input, offset: 0x328 */
  __IO uint32_t RXCDRP;                            /**< DPHY RXCDRP input, offset: 0x32C */
} MIPI_DSI_HOST_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI_HOST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_Register_Masks MIPI_DSI_HOST Register Masks
 * @{
 */

/*! @name CFG_NUM_LANES - Configure number of lanes */
/*! @{ */

#define MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_SHIFT (0U)
/*! CFG_NUM_LANES - Sets the number of active lanes that are to be used for transmitting data.
 *  0b00..2'b00 - 1 Lane
 *  0b01..2'b01 - 2 Lanes
 *  0b10..2'b10 - 3 Lanes
 *  0b11..2'b11 - 4 Lanes
 */
#define MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_SHIFT)) & MIPI_DSI_HOST_CFG_NUM_LANES_CFG_NUM_LANES_MASK)
/*! @} */

/*! @name CFG_NONCONTINUOUS_CLK - Configure non-continuous clock */
/*! @{ */

#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_SHIFT (0U)
/*! CFG_NONCONTINUOUS_CLK - Sets the Host Controller into non-continuous MIPI clock mode.
 *  0b0..1'b0 - Continuous high speed clock
 *  0b1..1'b1 - Non-Continuous high speed clock
 */
#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_SHIFT)) & MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CFG_NONCONTINUOUS_CLK_MASK)
/*! @} */

/*! @name CFG_T_PRE - Configure pre clock periods */
/*! @{ */

#define MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_MASK   (0x7FU)
#define MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_SHIFT  (0U)
/*! CFG_T_PRE - Sets the number of byte clock periods ('clk_byte' input) that the controller will
 *    wait after enabling the clock lane for HS operation before enabling the data lanes for HS
 *    operation.
 */
#define MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_SHIFT)) & MIPI_DSI_HOST_CFG_T_PRE_CFG_T_PRE_MASK)
/*! @} */

/*! @name CFG_T_POST - Configure post clock periods */
/*! @{ */

#define MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_MASK (0x7FU)
#define MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_SHIFT (0U)
/*! CFG_T_POST - Sets the number of byte clock periods ('clk_byte' input) to wait before putting the
 *    clock lane into LP mode after the data lanes have been detected to be in Stop State.
 */
#define MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_SHIFT)) & MIPI_DSI_HOST_CFG_T_POST_CFG_T_POST_MASK)
/*! @} */

/*! @name CFG_TX_GAP - Configure gap clock periods */
/*! @{ */

#define MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_MASK (0x7FU)
#define MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_SHIFT (0U)
/*! CFG_TX_GAP - Sets the number of byte clock periods ('clk_byte' input) that the controller will
 *    wait after the clock lane has been put into LP mode before enabling the clock lane for HS mode
 *    again.
 */
#define MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_SHIFT)) & MIPI_DSI_HOST_CFG_TX_GAP_CFG_TX_GAP_MASK)
/*! @} */

/*! @name CFG_AUTOINSERT_EOTP - Configure autoinsert EOTP */
/*! @{ */

#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_SHIFT (0U)
/*! CFG_AUTOINSERT_EOTP - Enables the Host Controller to automatically insert an EOTP short packet when switching from HS to LP mode.
 *  0b0..1'b0 - EOTP is not automatically inserted
 *  0b1..1'b1 - EOTP is automatically inserted
 */
#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_SHIFT)) & MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_CFG_AUTOINSERT_EOTP_MASK)
/*! @} */

/*! @name CFG_EXTRA_CMDS_AFTER_EOTP - Configure extra commands after EOTP */
/*! @{ */

#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_SHIFT (0U)
/*! CFG_EXTRA_CMDS_AFTER_EOTP - Configures the DSI Host Controller to send extra End Of Transmission Packets after the end of a packet. */
#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_SHIFT)) & MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_CFG_EXTRA_CMDS_AFTER_EOTP_MASK)
/*! @} */

/*! @name CFG_HTX_TO_COUNT - Configure high speed Tx timout count */
/*! @{ */

#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_SHIFT (0U)
/*! CFG_HTX_TO_COUNT - Sets the value of the DSI Host High Speed TX timeout count in clk_byte clock
 *    periods that once reached will initiate a timeout error and follow the recovery procedure
 *    documented in the DSI specification.
 */
#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_LRX_H_TO_COUNT - Configure low power Rx timout count */
/*! @{ */

#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_SHIFT (0U)
/*! CFG_LRX_H_TO_COUNT - Sets the value of the DSI Host low power Rx timeout count in clk_byte clock
 *    periods that once reached will initiate a timeout error and follow the recovery procedure
 *    documented in the DSI specification.
 */
#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_BTA_H_TO_COUNT - Configure bus turn around timout count */
/*! @{ */

#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_SHIFT (0U)
/*! CFG_BTA_H_TO_COUNT - Sets the value of the DSI Host Bus Turn Around (BTA) timeout in clk_byte
 *    clock periods that once reached will initiate a timeout error.
 */
#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_TWAKEUP - Configure Twakeup */
/*! @{ */

#define MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_MASK (0x7FFFFU)
#define MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_SHIFT (0U)
/*! CFG_TWAKEUP - DPHY Twakeup timing parameter. */
#define MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_SHIFT)) & MIPI_DSI_HOST_CFG_TWAKEUP_CFG_TWAKEUP_MASK)
/*! @} */

/*! @name CFG_STATUS_OUT - Configure status register */
/*! @{ */

#define MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_SHIFT (0U)
/*! CFG_STATUS_OUT - Status Register */
#define MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_SHIFT)) & MIPI_DSI_HOST_CFG_STATUS_OUT_CFG_STATUS_OUT_MASK)
/*! @} */

/*! @name RX_ERROR_STATUS - Status register to receive error */
/*! @{ */

#define MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_MASK (0x7FFU)
#define MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_SHIFT (0U)
/*! RX_ERROR_STATUS - Status Register for Host receive error detection, ECC errors, CRC errors and
 *    for timeout indicators [0] ECC single bit error detected [1] ECC multi bit error detected [6:2]
 *    Errored bit position for single bit ECC error [7] CRC error detected [8] High Speed forward
 *    TX timeout detected [9] Reverse Low power data receive timeout detected [10] BTA timeout
 *    detected
 */
#define MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_SHIFT)) & MIPI_DSI_HOST_RX_ERROR_STATUS_RX_ERROR_STATUS_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_PAYLOAD_SIZE - Pixel payload size */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_SHIFT (0U)
/*! CFG_DBI_PIXEL_PAYLOAD_SIZE - Maximum number of pixels that should be sent as one DSI packet. */
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_FIFO_SEND_LEVEL - Configure DBI pixel FIFO send level */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! CFG_DBI_PIXEL_FIFO_SEND_LEVEL - In order to optimize DSI utility, the DBI bridge buffers a certain number of DBI pixels before initiating a DSI packet. */
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_SHIFT)) & MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_PAYLOAD_SIZE - Configure DPI pixel payload size */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_SHIFT (0U)
/*! CFG_DPI_PIXEL_PAYLOAD_SIZE - Maximum number of pixels that should be sent as one DSI packet. */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_CFG_DPI_PIXEL_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_FIFO_SEND_LEVEL - Configure DPI pixel FIFO send level */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! CFG_DPI_PIXEL_FIFO_SEND_LEVEL - In order to optimize DSI utility, the DPI bridge buffers a cerntain number of DPI pixels before initiating a DSI packet. */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name CFG_DPI_INTERFACE_COLOR_CODING - Configure DPI interface color coding */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_MASK (0x7U)
#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_SHIFT (0U)
/*! CFG_DPI_INTERFACE_COLOR_CODING - Sets the distribution of RGB bits within the 24-bit d bus, as specified by the DPI specification. */
#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_CFG_DPI_INTERFACE_COLOR_CODING_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_FORMAT - Configure DPI pixel format */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_SHIFT (0U)
/*! CFG_DPI_PIXEL_FORMAT - Sets the DSI packet type of the pixels. */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_CFG_DPI_PIXEL_FORMAT_MASK)
/*! @} */

/*! @name CFG_DPI_VSYNC_POLARITY - Configure DPI vsync polarity */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_SHIFT (0U)
/*! CFG_DPI_VSYNC_POLARITY - Sets polarity of dpi_vsync_input 0 - active low 1 - active high */
#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_CFG_DPI_VSYNC_POLARITY_MASK)
/*! @} */

/*! @name CFG_DPI_HSYNC_POLARITY - Configure DPI hsync polarity */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_SHIFT (0U)
/*! CFG_DPI_HSYNC_POLARITY - Sets polarity of dpi_hsync_input 0 - active low 1 - active high */
#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_CFG_DPI_HSYNC_POLARITY_MASK)
/*! @} */

/*! @name CFG_DPI_VIDEO_MODE - Configure DPI video mode */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_SHIFT (0U)
/*! CFG_DPI_VIDEO_MODE - Select DSI video mode that the host DPI module should generate packets for. */
#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_CFG_DPI_VIDEO_MODE_MASK)
/*! @} */

/*! @name CFG_DPI_HFP - Configure DPI horizontal front porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_SHIFT (0U)
/*! CFG_DPI_HFP - Sets the DSI packet payload size, in bytes, of the horizontal front porch blanking packet. */
#define MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HFP_CFG_DPI_HFP_MASK)
/*! @} */

/*! @name CFG_DPI_HBP - Configure DPI horizontal back porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_SHIFT (0U)
/*! CFG_DPI_HBP - Sets the DSI packet payload size, in bytes, of the horizontal back porch blanking packet. */
#define MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HBP_CFG_DPI_HBP_MASK)
/*! @} */

/*! @name CFG_DPI_HSA - Configure DPI horizontal sync width */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_SHIFT (0U)
/*! CFG_DPI_HSA - Sets the DSI packet payload size, in bytes, of the horizontal sync width filler blanking packet. */
#define MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HSA_CFG_DPI_HSA_MASK)
/*! @} */

/*! @name CFG_DPI_ENABLE_MULT_PKTS - Enable multiple packtes */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_SHIFT (0U)
/*! CFG_DPI_ENABLE_MULT_PKTS - Enable Multiple packets per video line. */
#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_CFG_DPI_ENABLE_MULT_PKTS_MASK)
/*! @} */

/*! @name CFG_DPI_VBP - Configure DPI vertical back porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_SHIFT (0U)
/*! CFG_DPI_VBP - Sets the number of lines in the vertical back porch. */
#define MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VBP_CFG_DPI_VBP_MASK)
/*! @} */

/*! @name CFG_DPI_VFP - Configure DPI vertical front porch */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_SHIFT (0U)
/*! CFG_DPI_VFP - Sets the number of lines in the vertical front porch. */
#define MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VFP_CFG_DPI_VFP_MASK)
/*! @} */

/*! @name CFG_DPI_BLLP_MODE - Configure DPI BLLP mode */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_SHIFT (0U)
/*! CFG_DPI_BLLP_MODE - Optimize bllp periods to Low Power mode when possible 0 - blanking packets
 *    are sent during BLLP periods 1 - LP mode is used for BLLP periods
 */
#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_CFG_DPI_BLLP_MODE_MASK)
/*! @} */

/*! @name CFG_DPI_USE_NULL_PKT_BLLP - Configure DPI blank packet in BLLP */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_SHIFT (0U)
/*! CFG_DPI_USE_NULL_PKT_BLLP - Selects type of blanking packet to be sent during bllp region 0 -
 *    Blanking packet used in bllp region 1 - Null packet used in bllp region
 */
#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_CFG_DPI_USE_NULL_PKT_BLLP_MASK)
/*! @} */

/*! @name CFG_DPI_VACTIVE - Configure DPI vertical active */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_MASK (0x3FFFU)
#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_SHIFT (0U)
/*! CFG_DPI_VACTIVE - Sets the number of lines in the vertical active aread. */
#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VACTIVE_CFG_DPI_VACTIVE_MASK)
/*! @} */

/*! @name CFG_DPI_VC - Configure DPI virtual channel */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_SHIFT (0U)
/*! CFG_DPI_VC - Sets the Virtual Channel (VC) of packets that will be sent to the receive packet interface. */
#define MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VC_CFG_DPI_VC_MASK)
/*! @} */

/*! @name TX_PAYLOAD - Transmit payload */
/*! @{ */

#define MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_SHIFT (0U)
/*! TX_PAYLOAD - Tx Payload data write register. */
#define MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_SHIFT)) & MIPI_DSI_HOST_TX_PAYLOAD_TX_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_CONTROL - Packet control */
/*! @{ */

#define MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_MASK (0x7FFFFFFU)
#define MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_SHIFT (0U)
/*! PKT_CONTROL - Tx packet control register. */
#define MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_SHIFT)) & MIPI_DSI_HOST_PKT_CONTROL_PKT_CONTROL_MASK)
/*! @} */

/*! @name SEND_PACKET - Send packet */
/*! @{ */

#define MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_MASK (0x1U)
#define MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_SHIFT (0U)
/*! SEND_PACKET - Tx send packet, writing to this register causes the packet described in dsi_host_pkt_control to be sent. */
#define MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_SHIFT)) & MIPI_DSI_HOST_SEND_PACKET_SEND_PACKET_MASK)
/*! @} */

/*! @name PKT_STATUS - Packet status */
/*! @{ */

#define MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_MASK (0x1FFU)
#define MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_SHIFT (0U)
/*! PKT_STATUS - Status of APB to packet interface [0] - state machine not idle [1] - Tx packet done
 *    [2] - dphy direction 0 - tx had control, 1 - rx has control [3] - tx fifo overflow [4] - tx
 *    fifo underflow [5] - rx fifo overflow [6] - rx fifo underflow [7] - rx packet header has been
 *    received [8] - all rx packet payload data has been received
 */
#define MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_SHIFT)) & MIPI_DSI_HOST_PKT_STATUS_PKT_STATUS_MASK)
/*! @} */

/*! @name PKT_FIFO_WR_LEVEL - Packet FIFO write */
/*! @{ */

#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_SHIFT (0U)
/*! PKT_FIFO_WR_LEVEL - Write level of APB to pkt interface fifo */
#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_SHIFT)) & MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_PKT_FIFO_WR_LEVEL_MASK)
/*! @} */

/*! @name PKT_FIFO_RD_LEVEL - Packet FIFO read */
/*! @{ */

#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_SHIFT (0U)
/*! PKT_FIFO_RD_LEVEL - Read level of APB to pkt interface fifo */
#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_SHIFT)) & MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_PKT_FIFO_RD_LEVEL_MASK)
/*! @} */

/*! @name PKT_RX_PAYLOAD - Packet Rx payload */
/*! @{ */

#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_SHIFT (0U)
/*! PKT_RX_PAYLOAD - APB to pkt interface rx payload read */
#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_SHIFT)) & MIPI_DSI_HOST_PKT_RX_PAYLOAD_PKT_RX_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_RX_PKT_HEADER - Packet Rx packet header */
/*! @{ */

#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_SHIFT (0U)
/*! PKT_RX_PKT_HEADER - APB to pkt interface rx packet header [15:0] word count [21:16] data type [23:22] Virtual Channel */
#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_SHIFT)) & MIPI_DSI_HOST_PKT_RX_PKT_HEADER_PKT_RX_PKT_HEADER_MASK)
/*! @} */

/*! @name IRQ_STATUS - Interrupt status */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_SHIFT (0U)
/*! IRQ_STATUS - Status of APB to packet interface [0] - state machine not idle [1] - Tx packet done
 *    [2] - dphy direction 0 - tx had control, 1 - rx has control [3] - tx fifo overflow [4] - tx
 *    fifo underflow [5] - rx fifo overflow [6] - rx fifo underflow [7] - rx packet header has been
 *    received [8] - all rx packet payload data has been received [28:9] - map directory to dsi host
 *    controller status_out port bit descriptions [29] - high speed tx timeout, host controller
 *    hs_tx_timeout port [30] - low power rx timeout, host controller lp_rx_timeout port [31] - host bta
 *    timeout, host controller host_bta_timeout port
 */
#define MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_SHIFT)) & MIPI_DSI_HOST_IRQ_STATUS_IRQ_STATUS_MASK)
/*! @} */

/*! @name IRQ_STATUS2 - Interrupt status 2 */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_MASK (0x7U)
#define MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_SHIFT (0U)
/*! IRQ_STATUS2 - Status of APB to packet interface part 2, read part 2 first then dsi_host_irq_status. */
#define MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_SHIFT)) & MIPI_DSI_HOST_IRQ_STATUS2_IRQ_STATUS2_MASK)
/*! @} */

/*! @name IRQ_MASK - Mask interrupt */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_MASK     (0xFFFFFFFFU)
#define MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_SHIFT    (0U)
/*! IRQ_MASK - irq mask [0] - state machine not idle [1] - Tx packet done [2] - dphy direction 0 -
 *    tx had control, 1 - rx has control [3] - tx fifo overflow [4] - tx fifo underflow [5] - rx fifo
 *    overflow [6] - rx fifo underflow [7] - rx packet header has been received [8] - all rx packet
 *    payload data has been received [28:9] - map directory to dsi host controller status_out port
 *    bit descriptions [29] - high speed tx timeout, host controller hs_tx_timeout port [30] - low
 *    power rx timeout, host controller lp_rx_timeout port [31] - host bta timeout, host controller
 *    host_bta_timeout port
 */
#define MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_SHIFT)) & MIPI_DSI_HOST_IRQ_MASK_IRQ_MASK_MASK)
/*! @} */

/*! @name IRQ_MASK2 - Interrupt mask 2 */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_MASK   (0x7U)
#define MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_SHIFT  (0U)
/*! irq_mask2 - irq mask 2 [0] - single bit ecc error [1] - multi bit ecc error [2] - crc error */
#define MIPI_DSI_HOST_IRQ_MASK2_irq_mask2(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_SHIFT)) & MIPI_DSI_HOST_IRQ_MASK2_irq_mask2_MASK)
/*! @} */

/*! @name PD_DPHY - DPHY power down */
/*! @{ */

#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY_MASK       (0x1U)
#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY_SHIFT      (0U)
/*! PD_DPHY - Power Down input for D-PHY
 *  0b0..Power up
 *  0b1..Power down
 */
#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PD_DPHY_PD_DPHY_SHIFT)) & MIPI_DSI_HOST_PD_DPHY_PD_DPHY_MASK)
/*! @} */

/*! @name M_PRG_HS_PREPARE - Program T_HS_PREPARE */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_MASK (0x3U)
#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_SHIFT (0U)
/*! M_PRG_HS_PREPARE - DPHY m_PRG_HS_PREPARE input */
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
/*! M_PRG_HS_ZERO - DPHY m_PRG_HS_ZERO input */
#define MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name MC_PRG_HS_ZERO - Program T_CLK_ZERO */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_MASK (0x3FU)
#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_SHIFT (0U)
/*! MC_PRG_HS_ZERO - DPHY mc_PRG_HS_ZERO input */
#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name M_PRG_HS_TRAIL - Program T_HS_TRAIL */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_MASK (0xFU)
#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_SHIFT (0U)
/*! M_PRG_HS_TRAIL - DPHY m_PRG_HS_TRAIL input */
#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name MC_PRG_HS_TRAIL - Program T_CLK_TRAIL */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_MASK (0xFU)
#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_SHIFT (0U)
/*! MC_PRG_HS_TRAIL - DPHY mc_PRG_HS_TRAIL input */
#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name TST - DPHY TST input */
/*! @{ */

#define MIPI_DSI_HOST_TST_TST_MASK               (0x3FU)
#define MIPI_DSI_HOST_TST_TST_SHIFT              (0U)
/*! TST - DPHY TST input */
#define MIPI_DSI_HOST_TST_TST(x)                 (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_TST_TST_SHIFT)) & MIPI_DSI_HOST_TST_TST_MASK)
/*! @} */

/*! @name RTERM_SEL - RTERM select */
/*! @{ */

#define MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_MASK   (0x1U)
#define MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_SHIFT  (0U)
/*! RTERM_SEL - DPHY RTERM_SEL input
 *  0b0..LPCD levels enables HS termination (VIL-CD).
 *  0b1..LPRX levels enables HS terminations (LP-VIL).
 */
#define MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_SHIFT)) & MIPI_DSI_HOST_RTERM_SEL_RTERM_SEL_MASK)
/*! @} */

/*! @name AUTO_PD_EN - Power down auto enable */
/*! @{ */

#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_MASK (0x1U)
#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_SHIFT (0U)
/*! AUTO_PD_EN - DPHY AUTO_PD_EN input
 *  0b0..inactive lanes are powered up and driving LP11.
 *  0b1..inactive lanes are powered down.
 */
#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_SHIFT)) & MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_MASK)
/*! @} */

/*! @name RXLPRP - DPHY RXLPRP input */
/*! @{ */

#define MIPI_DSI_HOST_RXLPRP_RXLPRP_MASK         (0x3U)
#define MIPI_DSI_HOST_RXLPRP_RXLPRP_SHIFT        (0U)
/*! RXLPRP - DPHY RXLPRP input */
#define MIPI_DSI_HOST_RXLPRP_RXLPRP(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RXLPRP_RXLPRP_SHIFT)) & MIPI_DSI_HOST_RXLPRP_RXLPRP_MASK)
/*! @} */

/*! @name RXCDRP - DPHY RXCDRP input */
/*! @{ */

#define MIPI_DSI_HOST_RXCDRP_RXCDRP_MASK         (0x3U)
#define MIPI_DSI_HOST_RXCDRP_RXCDRP_SHIFT        (0U)
/*! RXCDRP - DPHY RXCDRP input */
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

