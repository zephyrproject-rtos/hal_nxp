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
**         CMSIS Peripheral Access Layer for DSI2_HOST_APB_PKT_IF
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
 * @file PERI_DSI2_HOST_APB_PKT_IF.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DSI2_HOST_APB_PKT_IF
 *
 * CMSIS Peripheral Access Layer for DSI2_HOST_APB_PKT_IF
 */

#if !defined(PERI_DSI2_HOST_APB_PKT_IF_H_)
#define PERI_DSI2_HOST_APB_PKT_IF_H_             /**< Symbol preventing repeated inclusion */

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
   -- DSI2_HOST_APB_PKT_IF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_APB_PKT_IF_Peripheral_Access_Layer DSI2_HOST_APB_PKT_IF Peripheral Access Layer
 * @{
 */

/** DSI2_HOST_APB_PKT_IF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_TX_PAYLOAD;                    /**< Transmit Payload, offset: 0x0 */
  __IO uint32_t CFG_PKT_CONTROL;                   /**< Packet Control, offset: 0x4 */
  __IO uint32_t CFG_SEND_PACKET;                   /**< Send Packet, offset: 0x8 */
  __I  uint32_t CFG_PKT_STATUS;                    /**< Packet Status, offset: 0xC */
  __I  uint32_t CFG_PKT_FIFO_WR_LEVEL;             /**< Packet FIFO Write Level, offset: 0x10 */
  __I  uint32_t CFG_PKT_FIFO_RD_LEVEL;             /**< Packet FIFO Read Level, offset: 0x14 */
  __I  uint32_t CFG_PKT_RX_PAYLOAD;                /**< Packet Receive Payload, offset: 0x18 */
  __I  uint32_t CFG_PKT_RX_PKT_HEADER;             /**< Packet Receive Packet Header, offset: 0x1C */
  __IO uint32_t CFG_APB_IRQ_STATUS;                /**< APB Interrupt Request Status, offset: 0x20 */
  __IO uint32_t CFG_APB_IRQ_MASK;                  /**< APB Interrupt Request Mask, offset: 0x24 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CFG_INTERFACE_PRIORITY_SEL;        /**< Interface Priority Select, offset: 0x30 */
} DSI2_HOST_APB_PKT_IF_Type;

/* ----------------------------------------------------------------------------
   -- DSI2_HOST_APB_PKT_IF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_APB_PKT_IF_Register_Masks DSI2_HOST_APB_PKT_IF Register Masks
 * @{
 */

/*! @name CFG_TX_PAYLOAD - Transmit Payload */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_TX_PAYLOAD_CFG_TX_PAYLOAD_MASK (0xFFFFFFFFU)
#define DSI2_HOST_APB_PKT_IF_CFG_TX_PAYLOAD_CFG_TX_PAYLOAD_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_TX_PAYLOAD_CFG_TX_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_TX_PAYLOAD_CFG_TX_PAYLOAD_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_TX_PAYLOAD_CFG_TX_PAYLOAD_MASK)
/*! @} */

/*! @name CFG_PKT_CONTROL - Packet Control */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_PKT_CONTROL_CFG_PKT_CONTROL_MASK (0x7FFFFFFU)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_CONTROL_CFG_PKT_CONTROL_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_CONTROL_CFG_PKT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_PKT_CONTROL_CFG_PKT_CONTROL_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_PKT_CONTROL_CFG_PKT_CONTROL_MASK)
/*! @} */

/*! @name CFG_SEND_PACKET - Send Packet */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_SEND_PACKET_CFG_SEND_PACKET_MASK (0x1U)
#define DSI2_HOST_APB_PKT_IF_CFG_SEND_PACKET_CFG_SEND_PACKET_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_SEND_PACKET_CFG_SEND_PACKET(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_SEND_PACKET_CFG_SEND_PACKET_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_SEND_PACKET_CFG_SEND_PACKET_MASK)
/*! @} */

/*! @name CFG_PKT_STATUS - Packet Status */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_PKT_STATUS_CFG_PKT_STATUS_MASK (0x1FFU)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_STATUS_CFG_PKT_STATUS_SHIFT (0U)
/*! cfg_pkt_status
 *  0b1xxxxxxxx..all rx packet payload data has been received
 *  0bx1xxxxxxx..rx packet header has been received
 *  0bxx1xxxxxx..rx fifo underflow
 *  0bxxx1xxxxx..rx fifo overflow
 *  0bxxxx1xxxx..tx fifo underflow
 *  0bxxxxx1xxx..tx fifo overflow
 *  0bxxxxxx0xx..dphy direction - tx had control
 *  0bxxxxxx1xx..dphy direction - rx has control
 *  0bxxxxxxx1x..Tx packet done
 *  0bxxxxxxxx1..state machine not idle
 */
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_STATUS_CFG_PKT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_PKT_STATUS_CFG_PKT_STATUS_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_PKT_STATUS_CFG_PKT_STATUS_MASK)
/*! @} */

/*! @name CFG_PKT_FIFO_WR_LEVEL - Packet FIFO Write Level */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_WR_LEVEL_CFG_PKT_FIFO_WR_LEVEL_MASK (0xFFFFU)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_WR_LEVEL_CFG_PKT_FIFO_WR_LEVEL_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_WR_LEVEL_CFG_PKT_FIFO_WR_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_WR_LEVEL_CFG_PKT_FIFO_WR_LEVEL_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_WR_LEVEL_CFG_PKT_FIFO_WR_LEVEL_MASK)
/*! @} */

/*! @name CFG_PKT_FIFO_RD_LEVEL - Packet FIFO Read Level */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_RD_LEVEL_CFG_PKT_FIFO_RD_LEVEL_MASK (0xFFFFU)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_RD_LEVEL_CFG_PKT_FIFO_RD_LEVEL_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_RD_LEVEL_CFG_PKT_FIFO_RD_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_RD_LEVEL_CFG_PKT_FIFO_RD_LEVEL_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_PKT_FIFO_RD_LEVEL_CFG_PKT_FIFO_RD_LEVEL_MASK)
/*! @} */

/*! @name CFG_PKT_RX_PAYLOAD - Packet Receive Payload */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PAYLOAD_CFG_PKT_RX_PAYLOAD_MASK (0xFFFFFFFFU)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PAYLOAD_CFG_PKT_RX_PAYLOAD_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PAYLOAD_CFG_PKT_RX_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PAYLOAD_CFG_PKT_RX_PAYLOAD_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PAYLOAD_CFG_PKT_RX_PAYLOAD_MASK)
/*! @} */

/*! @name CFG_PKT_RX_PKT_HEADER - Packet Receive Packet Header */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PKT_HEADER_CFG_PKT_RX_PKT_HEADER_MASK (0xFFFFFFU)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PKT_HEADER_CFG_PKT_RX_PKT_HEADER_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PKT_HEADER_CFG_PKT_RX_PKT_HEADER(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PKT_HEADER_CFG_PKT_RX_PKT_HEADER_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_PKT_RX_PKT_HEADER_CFG_PKT_RX_PKT_HEADER_MASK)
/*! @} */

/*! @name CFG_APB_IRQ_STATUS - APB Interrupt Request Status */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_0_MASK (0x1U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_0_SHIFT (0U)
/*! irq_apb_bit_0 - APB IRQ State Machine Not Idle */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_0(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_0_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_0_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_1_MASK (0x2U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_1_SHIFT (1U)
/*! irq_apb_bit_1 - APB IRQ TX Packet Done */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_1(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_1_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_1_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_2_MASK (0x4U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_2_SHIFT (2U)
/*! irq_apb_bit_2 - APB IRQ PHY Direction 0-TX Control 1-RX Control */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_2(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_2_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_2_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_3_MASK (0x8U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_3_SHIFT (3U)
/*! irq_apb_bit_3 - APB IRQ TX FIFO Overflow */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_3(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_3_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_3_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_4_MASK (0x10U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_4_SHIFT (4U)
/*! irq_apb_bit_4 - APB IRQ TX FIFO Underflow */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_4(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_4_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_4_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_5_MASK (0x20U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_5_SHIFT (5U)
/*! irq_apb_bit_5 - APB IRQ RX FIFO Overflow */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_5(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_5_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_5_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_6_MASK (0x40U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_6_SHIFT (6U)
/*! irq_apb_bit_6 - APB IRQ RX FIFO Underflow */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_6(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_6_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_6_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_7_MASK (0x80U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_7_SHIFT (7U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_7(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_7_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_7_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_8_MASK (0x100U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_8_SHIFT (8U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_8(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_8_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_8_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_9_MASK (0x200U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_9_SHIFT (9U)
/*! irq_apb_bit_9 - APB IRQ Host BTA Timeout */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_9(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_9_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_9_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_10_MASK (0x400U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_10_SHIFT (10U)
/*! irq_apb_bit_10 - APB IRQ Low Power RX Timeout */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_10(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_10_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_10_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_11_MASK (0x800U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_11_SHIFT (11U)
/*! irq_apb_bit_11 - APB IRQ High Speed TX Timeout */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_11(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_11_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_11_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_12_MASK (0x1000U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_12_SHIFT (12U)
/*! irq_apb_bit_12 - APB IRQ Register Parity Error */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_12(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_12_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_BIT_12_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_CSR_PARITY_ERR_MASK (0x80000000U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_CSR_PARITY_ERR_SHIFT (31U)
/*! irq_apb_csr_parity_err - APB CSR Registers Parity Error */
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_CSR_PARITY_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_CSR_PARITY_ERR_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_STATUS_IRQ_APB_CSR_PARITY_ERR_MASK)
/*! @} */

/*! @name CFG_APB_IRQ_MASK - APB Interrupt Request Mask */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_MASK (0x1FFFU)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_SHIFT (0U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_MASK)

#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_CSR_PARITY_ERR_MASK (0x80000000U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_CSR_PARITY_ERR_SHIFT (31U)
#define DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_CSR_PARITY_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_CSR_PARITY_ERR_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_APB_IRQ_MASK_IRQ_APB_MASK_CSR_PARITY_ERR_MASK)
/*! @} */

/*! @name CFG_INTERFACE_PRIORITY_SEL - Interface Priority Select */
/*! @{ */

#define DSI2_HOST_APB_PKT_IF_CFG_INTERFACE_PRIORITY_SEL_CFG_INTERFACE_PRIORITY_SEL_MASK (0x1U)
#define DSI2_HOST_APB_PKT_IF_CFG_INTERFACE_PRIORITY_SEL_CFG_INTERFACE_PRIORITY_SEL_SHIFT (0U)
/*! cfg_interface_priority_sel
 *  0b0..Host Controller Core packet interface
 *  0b1..APB packet interface
 */
#define DSI2_HOST_APB_PKT_IF_CFG_INTERFACE_PRIORITY_SEL_CFG_INTERFACE_PRIORITY_SEL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_APB_PKT_IF_CFG_INTERFACE_PRIORITY_SEL_CFG_INTERFACE_PRIORITY_SEL_SHIFT)) & DSI2_HOST_APB_PKT_IF_CFG_INTERFACE_PRIORITY_SEL_CFG_INTERFACE_PRIORITY_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI2_HOST_APB_PKT_IF_Register_Masks */


/*!
 * @}
 */ /* end of group DSI2_HOST_APB_PKT_IF_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI2_HOST_APB_PKT_IF_H_ */

