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
**         CMSIS Peripheral Access Layer for DSI_HOST_APB_PKT_IF
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
 * @file PERI_DSI_HOST_APB_PKT_IF.h
 * @version 0.2
 * @date 2026-02-26
 * @brief CMSIS Peripheral Access Layer for DSI_HOST_APB_PKT_IF
 *
 * CMSIS Peripheral Access Layer for DSI_HOST_APB_PKT_IF
 */

#if !defined(PERI_DSI_HOST_APB_PKT_IF_H_)
#define PERI_DSI_HOST_APB_PKT_IF_H_              /**< Symbol preventing repeated inclusion */

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
   -- DSI_HOST_APB_PKT_IF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_APB_PKT_IF_Peripheral_Access_Layer DSI_HOST_APB_PKT_IF Peripheral Access Layer
 * @{
 */

/** DSI_HOST_APB_PKT_IF - Register Layout Typedef */
typedef struct {
  __IO uint32_t TX_PAYLOAD;                        /**< Transmit Payload Data Write, offset: 0x0 */
  __IO uint32_t PKT_CONTROL;                       /**< Packet Control, offset: 0x4 */
  __IO uint32_t SEND_PACKET;                       /**< Send Packet, offset: 0x8 */
  __I  uint32_t PKT_STATUS;                        /**< Packet Status, offset: 0xC */
  __I  uint32_t PKT_FIFO_WR_LEVEL;                 /**< Packet FIFO Write Level, offset: 0x10 */
  __I  uint32_t PKT_FIFO_RD_LEVEL;                 /**< Packet FIFO Read Level, offset: 0x14 */
  __I  uint32_t PKT_RX_PAYLOAD;                    /**< Packet Receive Payload, offset: 0x18 */
  __I  uint32_t PKT_RX_PKT_HEADER;                 /**< Packet Receive Packet Header, offset: 0x1C */
  __I  uint32_t IRQ_STATUS;                        /**< Interrupt Status, offset: 0x20 */
  __I  uint32_t IRQ_STATUS2;                       /**< Interrupt Status 2, offset: 0x24 */
  __IO uint32_t IRQ_MASK;                          /**< Interrupt Mask, offset: 0x28 */
  __IO uint32_t IRQ_MASK2;                         /**< Interrupt Mask 2, offset: 0x2C */
} DSI_HOST_APB_PKT_IF_Type;

/* ----------------------------------------------------------------------------
   -- DSI_HOST_APB_PKT_IF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_APB_PKT_IF_Register_Masks DSI_HOST_APB_PKT_IF Register Masks
 * @{
 */

/*! @name TX_PAYLOAD - Transmit Payload Data Write */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_MASK (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_SHIFT (0U)
/*! PAYLOAD - Payload */
#define DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_SHIFT)) & DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_CONTROL - Packet Control */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_MASK (0x7FFFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_SHIFT (0U)
/*! CTRL - Control */
#define DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_MASK)
/*! @} */

/*! @name SEND_PACKET - Send Packet */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_MASK (0x1U)
#define DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_SHIFT (0U)
/*! TX_SEND - Transmit send packet
 *  0b0..Packet not sent
 *  0b1..Packet is sent
 */
#define DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_SHIFT)) & DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_MASK)
/*! @} */

/*! @name PKT_STATUS - Packet Status */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_MASK (0x1FFU)
#define DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_SHIFT (0U)
/*! STATUS - Status */
#define DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_MASK)
/*! @} */

/*! @name PKT_FIFO_WR_LEVEL - Packet FIFO Write Level */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_MASK (0xFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_SHIFT (0U)
/*! WR - Write level */
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_MASK)
/*! @} */

/*! @name PKT_FIFO_RD_LEVEL - Packet FIFO Read Level */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_MASK (0xFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_SHIFT (0U)
/*! RD - Read level */
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_MASK)
/*! @} */

/*! @name PKT_RX_PAYLOAD - Packet Receive Payload */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_MASK (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_SHIFT (0U)
/*! PAYLOAD - Payload */
#define DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_RX_PKT_HEADER - Packet Receive Packet Header */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_MASK (0xFFFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_SHIFT (0U)
/*! HEADER - Header */
#define DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_MASK)
/*! @} */

/*! @name IRQ_STATUS - Interrupt Status */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_MASK (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_SHIFT (0U)
/*! STATUS - Status */
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_SHIFT)) & DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_MASK)
/*! @} */

/*! @name IRQ_STATUS2 - Interrupt Status 2 */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_MASK (0x7U)
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_SHIFT (0U)
/*! STATUS2 - Status 2 */
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_SHIFT)) & DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_MASK)
/*! @} */

/*! @name IRQ_MASK - Interrupt Mask */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_MASK   (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_SHIFT  (0U)
/*! MASK - IRQ Mask */
#define DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK(x)     (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_SHIFT)) & DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_MASK)
/*! @} */

/*! @name IRQ_MASK2 - Interrupt Mask 2 */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_MASK2_MASK2_MASK (0x7U)
#define DSI_HOST_APB_PKT_IF_IRQ_MASK2_MASK2_SHIFT (0U)
/*! MASK2 - IRQ Mask 2 */
#define DSI_HOST_APB_PKT_IF_IRQ_MASK2_MASK2(x)   (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_IRQ_MASK2_MASK2_SHIFT)) & DSI_HOST_APB_PKT_IF_IRQ_MASK2_MASK2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI_HOST_APB_PKT_IF_Register_Masks */


/*!
 * @}
 */ /* end of group DSI_HOST_APB_PKT_IF_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI_HOST_APB_PKT_IF_H_ */

