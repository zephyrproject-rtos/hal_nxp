/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIPI_DSI_HOST_APB_PKT_IF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_DSI_HOST_APB_PKT_IF.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI_HOST_APB_PKT_IF
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI_HOST_APB_PKT_IF
 */

#if !defined(PERI_MIPI_DSI_HOST_APB_PKT_IF_H_)
#define PERI_MIPI_DSI_HOST_APB_PKT_IF_H_         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- MIPI_DSI_HOST_APB_PKT_IF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_APB_PKT_IF_Peripheral_Access_Layer MIPI_DSI_HOST_APB_PKT_IF Peripheral Access Layer
 * @{
 */

/** MIPI_DSI_HOST_APB_PKT_IF - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_HOST_TX_PAYLOAD;               /**< offset: 0x0 */
  __IO uint32_t DSI_HOST_PKT_CONTROL;              /**< offset: 0x4 */
  __IO uint32_t DSI_HOST_SEND_PACKET;              /**< offset: 0x8 */
  __I  uint32_t DSI_HOST_PKT_STATUS;               /**< offset: 0xC */
  __I  uint32_t DSI_HOST_PKT_FIFO_WR_LEVEL;        /**< offset: 0x10 */
  __I  uint32_t DSI_HOST_PKT_FIFO_RD_LEVEL;        /**< offset: 0x14 */
  __I  uint32_t DSI_HOST_PKT_RX_PAYLOAD;           /**< offset: 0x18 */
  __I  uint32_t DSI_HOST_PKT_RX_PKT_HEADER;        /**< offset: 0x1C */
  __I  uint32_t DSI_HOST_IRQ_STATUS;               /**< offset: 0x20 */
  __I  uint32_t DSI_HOST_IRQ_STATUS2;              /**< offset: 0x24 */
  __IO uint32_t DSI_HOST_IRQ_MASK;                 /**< offset: 0x28 */
  __IO uint32_t DSI_HOST_IRQ_MASK2;                /**< offset: 0x2C */
} MIPI_DSI_HOST_APB_PKT_IF_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI_HOST_APB_PKT_IF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_APB_PKT_IF_Register_Masks MIPI_DSI_HOST_APB_PKT_IF Register Masks
 * @{
 */

/*! @name DSI_HOST_TX_PAYLOAD -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_TX_PAYLOAD_dsi_host_tx_payload_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_TX_PAYLOAD_dsi_host_tx_payload_SHIFT (0U)
/*! dsi_host_tx_payload - Tx Payload data write register. Writes to this registers load the payload fifo with 32 bit values. */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_TX_PAYLOAD_dsi_host_tx_payload(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_TX_PAYLOAD_dsi_host_tx_payload_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_TX_PAYLOAD_dsi_host_tx_payload_MASK)
/*! @} */

/*! @name DSI_HOST_PKT_CONTROL -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_CONTROL_dsi_host_pkt_control_MASK (0x7FFFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_CONTROL_dsi_host_pkt_control_SHIFT (0U)
/*! dsi_host_pkt_control - Tx packet control register. [15:0] - Packet word count [17:16] - Packet
 *    Virtual Channel [23:18] - Packet Header DSI Data Type [24] - Lp or HS select. 0 - LP mode, 1 -
 *    HS mode [25] - perform BTA after packet is sent [26] - perform BTA only, no packet tx
 */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_CONTROL_dsi_host_pkt_control(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_CONTROL_dsi_host_pkt_control_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_CONTROL_dsi_host_pkt_control_MASK)
/*! @} */

/*! @name DSI_HOST_SEND_PACKET -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_SEND_PACKET_dsi_host_send_packet_MASK (0x1U)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_SEND_PACKET_dsi_host_send_packet_SHIFT (0U)
/*! dsi_host_send_packet - Tx send packet. Writing to this register causes the packet described in dsi_host_pkt_control to be sent. */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_SEND_PACKET_dsi_host_send_packet(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_SEND_PACKET_dsi_host_send_packet_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_SEND_PACKET_dsi_host_send_packet_MASK)
/*! @} */

/*! @name DSI_HOST_PKT_STATUS -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_STATUS_dsi_host_pkt_status_MASK (0x1FFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_STATUS_dsi_host_pkt_status_SHIFT (0U)
/*! dsi_host_pkt_status - Status of APB to packet interface [0] - state machine not idle [1] - Tx
 *    packet done [2] - dphy direction 0 - tx had control, 1 - rx has control [3] - tx fifo overflow
 *    [4] - tx fifo underflow [5] - rx fifo overflow [6] - rx fifo underflow [7] - rx packet header
 *    has been received [8] - all rx packet payload data has been receive d
 */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_STATUS_dsi_host_pkt_status(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_STATUS_dsi_host_pkt_status_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_STATUS_dsi_host_pkt_status_MASK)
/*! @} */

/*! @name DSI_HOST_PKT_FIFO_WR_LEVEL -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_WR_LEVEL_dsi_host_pkt_fifo_wr_level_MASK (0xFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_WR_LEVEL_dsi_host_pkt_fifo_wr_level_SHIFT (0U)
/*! dsi_host_pkt_fifo_wr_level - Write level of APB to pkt interface fifo */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_WR_LEVEL_dsi_host_pkt_fifo_wr_level(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_WR_LEVEL_dsi_host_pkt_fifo_wr_level_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_WR_LEVEL_dsi_host_pkt_fifo_wr_level_MASK)
/*! @} */

/*! @name DSI_HOST_PKT_FIFO_RD_LEVEL -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_RD_LEVEL_dsi_host_pkt_fifo_rd_level_MASK (0xFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_RD_LEVEL_dsi_host_pkt_fifo_rd_level_SHIFT (0U)
/*! dsi_host_pkt_fifo_rd_level - Read level of APB to pkt interface fifo */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_RD_LEVEL_dsi_host_pkt_fifo_rd_level(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_RD_LEVEL_dsi_host_pkt_fifo_rd_level_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_FIFO_RD_LEVEL_dsi_host_pkt_fifo_rd_level_MASK)
/*! @} */

/*! @name DSI_HOST_PKT_RX_PAYLOAD -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PAYLOAD_dsi_host_pkt_rx_payload_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PAYLOAD_dsi_host_pkt_rx_payload_SHIFT (0U)
/*! dsi_host_pkt_rx_payload - APB to pkt interface rx payload read */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PAYLOAD_dsi_host_pkt_rx_payload(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PAYLOAD_dsi_host_pkt_rx_payload_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PAYLOAD_dsi_host_pkt_rx_payload_MASK)
/*! @} */

/*! @name DSI_HOST_PKT_RX_PKT_HEADER -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PKT_HEADER_dsi_host_pkt_rx_pkt_header_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PKT_HEADER_dsi_host_pkt_rx_pkt_header_SHIFT (0U)
/*! dsi_host_pkt_rx_pkt_header - APB to pkt interface rx packet header [15:0] word count [21:16] data type [23:22] Virtual Channel */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PKT_HEADER_dsi_host_pkt_rx_pkt_header(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PKT_HEADER_dsi_host_pkt_rx_pkt_header_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_PKT_RX_PKT_HEADER_dsi_host_pkt_rx_pkt_header_MASK)
/*! @} */

/*! @name DSI_HOST_IRQ_STATUS -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS_dsi_host_irq_status_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS_dsi_host_irq_status_SHIFT (0U)
/*! dsi_host_irq_status - Status of APB to packet interface [0] - state machine not idle [1] - Tx
 *    packet done [2] - dphy direction 0 - tx had control, 1 - rx has control [3] - tx fifo overflow
 *    [4] - tx fifo underflow [5] - rx fifo overflow [6] - rx fifo underflow [7] - rx packet header
 *    has been received [8] - all rx packet payload data has been received [28:9] - map directory to
 *    dsi host controller status_out port bit descriptions [29] - host bta timeout, host controller
 *    host_bta_timeout port [30] - low power rx timeout, host controller lp_rx_timeout port [31] -
 *    high speed tx timeout, host controller hs_tx_timeout port
 */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS_dsi_host_irq_status(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS_dsi_host_irq_status_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS_dsi_host_irq_status_MASK)
/*! @} */

/*! @name DSI_HOST_IRQ_STATUS2 -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS2_dsi_host_irq_status2_MASK (0x7U)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS2_dsi_host_irq_status2_SHIFT (0U)
/*! dsi_host_irq_status2 - Status of APB to packet interface part 2. Read part 2 first then
 *    dsi_host_irq_status. Reading dsi_host_irq_status will clear both status and status 2. [0] - single bit
 *    ecc error [1] - multi bit ecc error [2] - crc error
 */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS2_dsi_host_irq_status2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS2_dsi_host_irq_status2_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_STATUS2_dsi_host_irq_status2_MASK)
/*! @} */

/*! @name DSI_HOST_IRQ_MASK -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK_dsi_host_irq_mask_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK_dsi_host_irq_mask_SHIFT (0U)
/*! dsi_host_irq_mask - irq mask [0] - state machine not idle [1] - Tx packet done [2] - dphy
 *    direction 0 - tx had control, 1 - rx has control [3] - tx fifo overflow [4] - tx fifo underflow [5]
 *    - rx fifo overflow [6] - rx fifo underflow [7] - rx packet header has been received [8] - all
 *    rx packet payload data has been received [28:9] - map directory to dsi host controller
 *    status_out port bit descriptions [29] - host bta timeout, host controller host_bta_timeout port [30]
 *    - low power rx timeout, host controller lp_rx_timeout port [31] - high speed tx timeout, host
 *    controller hs_tx_timeout port
 */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK_dsi_host_irq_mask(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK_dsi_host_irq_mask_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK_dsi_host_irq_mask_MASK)
/*! @} */

/*! @name DSI_HOST_IRQ_MASK2 -  */
/*! @{ */

#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK2_dsi_host_irq_mask2_MASK (0x7U)
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK2_dsi_host_irq_mask2_SHIFT (0U)
/*! dsi_host_irq_mask2 - irq mask 2 [0] - single bit ecc error [1] - multi bit ecc error [2] - crc error */
#define MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK2_dsi_host_irq_mask2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK2_dsi_host_irq_mask2_SHIFT)) & MIPI_DSI_HOST_APB_PKT_IF_DSI_HOST_IRQ_MASK2_dsi_host_irq_mask2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_APB_PKT_IF_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_APB_PKT_IF_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_DSI_HOST_APB_PKT_IF_H_ */

