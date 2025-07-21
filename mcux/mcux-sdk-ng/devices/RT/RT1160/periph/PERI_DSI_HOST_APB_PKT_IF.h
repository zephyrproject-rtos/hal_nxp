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
**         CMSIS Peripheral Access Layer for DSI_HOST_APB_PKT_IF
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
 * @file PERI_DSI_HOST_APB_PKT_IF.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DSI_HOST_APB_PKT_IF
 *
 * CMSIS Peripheral Access Layer for DSI_HOST_APB_PKT_IF
 */

#if !defined(PERI_DSI_HOST_APB_PKT_IF_H_)
#define PERI_DSI_HOST_APB_PKT_IF_H_              /**< Symbol preventing repeated inclusion */

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
   -- DSI_HOST_APB_PKT_IF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_APB_PKT_IF_Peripheral_Access_Layer DSI_HOST_APB_PKT_IF Peripheral Access Layer
 * @{
 */

/** DSI_HOST_APB_PKT_IF - Register Layout Typedef */
typedef struct {
  __IO uint32_t TX_PAYLOAD;                        /**< TX_PAYLOAD, offset: 0x0 */
  __IO uint32_t PKT_CONTROL;                       /**< PKT_CONTROL, offset: 0x4 */
  __IO uint32_t SEND_PACKET;                       /**< SEND_PACKET, offset: 0x8 */
  __I  uint32_t PKT_STATUS;                        /**< PKT_STATUS, offset: 0xC */
  __I  uint32_t PKT_FIFO_WR_LEVEL;                 /**< PKT_FIFO_WR_LEVEL, offset: 0x10 */
  __I  uint32_t PKT_FIFO_RD_LEVEL;                 /**< PKT_FIFO_RD_LEVEL, offset: 0x14 */
  __I  uint32_t PKT_RX_PAYLOAD;                    /**< PKT_RX_PAYLOAD, offset: 0x18 */
  __I  uint32_t PKT_RX_PKT_HEADER;                 /**< PKT_RX_PKT_HEADER, offset: 0x1C */
  __I  uint32_t IRQ_STATUS;                        /**< IRQ_STATUS, offset: 0x20 */
  __I  uint32_t IRQ_STATUS2;                       /**< IRQ_STATUS2, offset: 0x24 */
  __IO uint32_t IRQ_MASK;                          /**< IRQ_MASK, offset: 0x28 */
  __IO uint32_t IRQ_MASK2;                         /**< IRQ_MASK2, offset: 0x2C */
} DSI_HOST_APB_PKT_IF_Type;

/* ----------------------------------------------------------------------------
   -- DSI_HOST_APB_PKT_IF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_APB_PKT_IF_Register_Masks DSI_HOST_APB_PKT_IF Register Masks
 * @{
 */

/*! @name TX_PAYLOAD - TX_PAYLOAD */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_MASK (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_SHIFT (0U)
/*! PAYLOAD - Tx Payload data write register. Write to this register loads the payload FIFO with 32 bit values. */
#define DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_SHIFT)) & DSI_HOST_APB_PKT_IF_TX_PAYLOAD_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_CONTROL - PKT_CONTROL */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_MASK (0x7FFFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_SHIFT (0U)
/*! CTRL - Tx packet control */
#define DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_CONTROL_CTRL_MASK)
/*! @} */

/*! @name SEND_PACKET - SEND_PACKET */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_MASK (0x1U)
#define DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_SHIFT (0U)
/*! TX_SEND - Tx send packet, writing to this register causes the packet described in dsi_host_pkt_control to be sent.
 *  0b0..Packet not sent
 *  0b1..Packet is sent
 */
#define DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_SHIFT)) & DSI_HOST_APB_PKT_IF_SEND_PACKET_TX_SEND_MASK)
/*! @} */

/*! @name PKT_STATUS - PKT_STATUS */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_MASK (0x1FFU)
#define DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_SHIFT (0U)
/*! STATUS - Status of APB to packet interface. */
#define DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_STATUS_STATUS_MASK)
/*! @} */

/*! @name PKT_FIFO_WR_LEVEL - PKT_FIFO_WR_LEVEL */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_MASK (0xFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_SHIFT (0U)
/*! WR - Write level of APB to pkt interface FIFO */
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_FIFO_WR_LEVEL_WR_MASK)
/*! @} */

/*! @name PKT_FIFO_RD_LEVEL - PKT_FIFO_RD_LEVEL */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_MASK (0xFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_SHIFT (0U)
/*! RD - Read level of APB to pkt interface FIFO */
#define DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_FIFO_RD_LEVEL_RD_MASK)
/*! @} */

/*! @name PKT_RX_PAYLOAD - PKT_RX_PAYLOAD */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_MASK (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_SHIFT (0U)
/*! PAYLOAD - APB to pkt interface Rx payload read */
#define DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_RX_PAYLOAD_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_RX_PKT_HEADER - PKT_RX_PKT_HEADER */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_MASK (0xFFFFFFU)
#define DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_SHIFT (0U)
/*! HEADER - APB to pkt interface Rx packet header */
#define DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_SHIFT)) & DSI_HOST_APB_PKT_IF_PKT_RX_PKT_HEADER_HEADER_MASK)
/*! @} */

/*! @name IRQ_STATUS - IRQ_STATUS */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_MASK (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_SHIFT (0U)
/*! STATUS - Status of APB to packet interface. */
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_SHIFT)) & DSI_HOST_APB_PKT_IF_IRQ_STATUS_STATUS_MASK)
/*! @} */

/*! @name IRQ_STATUS2 - IRQ_STATUS2 */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_MASK (0x7U)
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_SHIFT (0U)
/*! STATUS2 - Status of APB to packet interface part 2, read part 2 first then dsi_host_irq_status.
 *    Reading dsi_host_irq_status will clear both status and status2.
 */
#define DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_SHIFT)) & DSI_HOST_APB_PKT_IF_IRQ_STATUS2_STATUS2_MASK)
/*! @} */

/*! @name IRQ_MASK - IRQ_MASK */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_MASK   (0xFFFFFFFFU)
#define DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_SHIFT  (0U)
/*! MASK - IRQ Mask */
#define DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK(x)     (((uint32_t)(((uint32_t)(x)) << DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_SHIFT)) & DSI_HOST_APB_PKT_IF_IRQ_MASK_MASK_MASK)
/*! @} */

/*! @name IRQ_MASK2 - IRQ_MASK2 */
/*! @{ */

#define DSI_HOST_APB_PKT_IF_IRQ_MASK2_MASK2_MASK (0x7U)
#define DSI_HOST_APB_PKT_IF_IRQ_MASK2_MASK2_SHIFT (0U)
/*! MASK2 - IRQ mask 2 */
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

