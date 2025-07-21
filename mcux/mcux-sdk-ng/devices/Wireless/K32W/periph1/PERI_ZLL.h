/*
** ###################################################################
**     Processor:           K32W1480VFTA
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ZLL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-01-18)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ZLL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ZLL
 *
 * CMSIS Peripheral Access Layer for ZLL
 */

#if !defined(PERI_ZLL_H_)
#define PERI_ZLL_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32W1480VFTA))
#include "K32W1480_COMMON.h"
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
   -- ZLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ZLL_Peripheral_Access_Layer ZLL Peripheral Access Layer
 * @{
 */

/** ZLL - Register Layout Typedef */
typedef struct {
  __IO uint32_t IRQSTS;                            /**< INTERRUPT REQUEST STATUS, offset: 0x0 */
  __IO uint32_t PHY_CTRL;                          /**< PHY CONTROL, offset: 0x4 */
  __IO uint32_t EVENT_TMR;                         /**< EVENT TIMER, offset: 0x8 */
  __I  uint32_t TIMESTAMP;                         /**< TIMESTAMP, offset: 0xC */
  __IO uint32_t T1CMP;                             /**< T1 COMPARE, offset: 0x10 */
  __IO uint32_t T2CMP;                             /**< T2 COMPARE, offset: 0x14 */
  __IO uint32_t T2PRIMECMP;                        /**< T2 PRIME COMPARE, offset: 0x18 */
  __IO uint32_t T3CMP;                             /**< T3 COMPARE, offset: 0x1C */
  __IO uint32_t T4CMP;                             /**< T4 COMPARE, offset: 0x20 */
  __IO uint32_t PA_PWR;                            /**< PA POWER, offset: 0x24 */
  __IO uint32_t CHANNEL_NUM0;                      /**< CHANNEL NUMBER 0, offset: 0x28 */
  __I  uint32_t LQI_AND_RSSI;                      /**< LQI AND RSSI, offset: 0x2C */
  __IO uint32_t MACSHORTADDRS0;                    /**< MAC SHORT ADDRESS 0, offset: 0x30 */
  __IO uint32_t MACLONGADDRS0_LSB;                 /**< MAC LONG ADDRESS 0 LSB, offset: 0x34 */
  __IO uint32_t MACLONGADDRS0_MSB;                 /**< MAC LONG ADDRESS 0 MSB, offset: 0x38 */
  __IO uint32_t RX_FRAME_FILTER;                   /**< RECEIVE FRAME FILTER, offset: 0x3C */
  __IO uint32_t CCA_LQI_CTRL;                      /**< CCA AND LQI CONTROL, offset: 0x40 */
  __IO uint32_t CCA2_CTRL;                         /**< CCA2 CONTROL, offset: 0x44 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DSM_CTRL;                          /**< DSM CONTROL, offset: 0x4C */
       uint8_t RESERVED_1[4];
  __IO uint32_t MACSHORTADDRS1;                    /**< MAC SHORT ADDRESS FOR PAN1, offset: 0x54 */
  __IO uint32_t MACLONGADDRS1_LSB;                 /**< MAC LONG ADDRESS 1 LSB, offset: 0x58 */
  __IO uint32_t MACLONGADDRS1_MSB;                 /**< MAC LONG ADDRESS 1 MSB, offset: 0x5C */
  __IO uint32_t DUAL_PAN_CTRL;                     /**< DUAL PAN CONTROL, offset: 0x60 */
  __IO uint32_t CHANNEL_NUM1;                      /**< CHANNEL NUMBER 1, offset: 0x64 */
  __IO uint32_t SAM_CTRL;                          /**< SAM CONTROL, offset: 0x68 */
  __IO uint32_t SAM_TABLE;                         /**< SOURCE ADDRESS MANAGEMENT TABLE, offset: 0x6C */
  __I  uint32_t SAM_MATCH;                         /**< SOURCE ADDRESS MANAGEMENT MATCH, offset: 0x70 */
  __I  uint32_t SAM_FREE_IDX;                      /**< SAM FREE INDEX, offset: 0x74 */
  __IO uint32_t SEQ_CTRL_STS;                      /**< SEQUENCE CONTROL AND STATUS, offset: 0x78 */
  __IO uint32_t ACKDELAY;                          /**< ACK DELAY, offset: 0x7C */
  __IO uint32_t FILTERFAIL_CODE;                   /**< FILTER FAIL CODE, offset: 0x80 */
  __IO uint32_t RX_WTR_MARK;                       /**< RECEIVE WATER MARK, offset: 0x84 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SLOT_PRELOAD;                      /**< SLOT PRELOAD, offset: 0x8C */
  __I  uint32_t SEQ_STATE;                         /**< 802.15.4 SEQUENCE STATE, offset: 0x90 */
  __IO uint32_t TMR_PRESCALE;                      /**< TIMER PRESCALER, offset: 0x94 */
  __IO uint32_t LENIENCY_LSB;                      /**< LENIENCY LSB, offset: 0x98 */
  __IO uint32_t LENIENCY_MSB;                      /**< LENIENCY MSB, offset: 0x9C */
  __I  uint32_t PART_ID;                           /**< PART ID, offset: 0xA0 */
  __IO uint32_t COEX_CTRL;                         /**< COEXISTENCE CONTROL, offset: 0xA4 */
  __IO uint32_t COEX_PRIORITY;                     /**< COEXISTENCE PRIORITY, offset: 0xA8 */
  __IO uint32_t ENHACK_CTRL0;                      /**< ENHACK_CTRL 0, offset: 0xAC */
} ZLL_Type;

/* ----------------------------------------------------------------------------
   -- ZLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ZLL_Register_Masks ZLL Register Masks
 * @{
 */

/*! @name IRQSTS - INTERRUPT REQUEST STATUS */
/*! @{ */

#define ZLL_IRQSTS_SEQIRQ_MASK                   (0x1U)
#define ZLL_IRQSTS_SEQIRQ_SHIFT                  (0U)
/*! SEQIRQ - Sequencer IRQ
 *  0b0..A Sequencer Interrupt has not occurred
 *  0b1..A Sequencer Interrupt has occurred
 */
#define ZLL_IRQSTS_SEQIRQ(x)                     (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_SEQIRQ_SHIFT)) & ZLL_IRQSTS_SEQIRQ_MASK)

#define ZLL_IRQSTS_TXIRQ_MASK                    (0x2U)
#define ZLL_IRQSTS_TXIRQ_SHIFT                   (1U)
/*! TXIRQ - TX IRQ
 *  0b0..A TX Interrupt has not occurred
 *  0b1..A TX Interrupt has occurred
 */
#define ZLL_IRQSTS_TXIRQ(x)                      (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TXIRQ_SHIFT)) & ZLL_IRQSTS_TXIRQ_MASK)

#define ZLL_IRQSTS_RXIRQ_MASK                    (0x4U)
#define ZLL_IRQSTS_RXIRQ_SHIFT                   (2U)
/*! RXIRQ - RX IRQ
 *  0b0..A RX Interrupt has not occurred
 *  0b1..A RX Interrupt has occurred
 */
#define ZLL_IRQSTS_RXIRQ(x)                      (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RXIRQ_SHIFT)) & ZLL_IRQSTS_RXIRQ_MASK)

#define ZLL_IRQSTS_CCAIRQ_MASK                   (0x8U)
#define ZLL_IRQSTS_CCAIRQ_SHIFT                  (3U)
/*! CCAIRQ - CCA IRQ
 *  0b0..A CCA Interrupt has not occurred
 *  0b1..A CCA Interrupt has occurred
 */
#define ZLL_IRQSTS_CCAIRQ(x)                     (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_CCAIRQ_SHIFT)) & ZLL_IRQSTS_CCAIRQ_MASK)

#define ZLL_IRQSTS_RXWTRMRKIRQ_MASK              (0x10U)
#define ZLL_IRQSTS_RXWTRMRKIRQ_SHIFT             (4U)
/*! RXWTRMRKIRQ - Receive Watermark IRQ
 *  0b0..A Receive Watermark Interrupt has not occurred
 *  0b1..A Receive Watermark Interrupt has occurred
 */
#define ZLL_IRQSTS_RXWTRMRKIRQ(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RXWTRMRKIRQ_SHIFT)) & ZLL_IRQSTS_RXWTRMRKIRQ_MASK)

#define ZLL_IRQSTS_FILTERFAIL_IRQ_MASK           (0x20U)
#define ZLL_IRQSTS_FILTERFAIL_IRQ_SHIFT          (5U)
/*! FILTERFAIL_IRQ - Filter Fail IRQ
 *  0b0..A Filter Fail Interrupt has not occurred
 *  0b1..A Filter Fail Interrupt has occurred
 */
#define ZLL_IRQSTS_FILTERFAIL_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_FILTERFAIL_IRQ_SHIFT)) & ZLL_IRQSTS_FILTERFAIL_IRQ_MASK)

#define ZLL_IRQSTS_PLL_UNLOCK_IRQ_MASK           (0x40U)
#define ZLL_IRQSTS_PLL_UNLOCK_IRQ_SHIFT          (6U)
/*! PLL_UNLOCK_IRQ - PLL Unlock IRQ
 *  0b0..A PLL Unlock Interrupt has not occurred
 *  0b1..A PLL Unlock Interrupt has occurred
 */
#define ZLL_IRQSTS_PLL_UNLOCK_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_PLL_UNLOCK_IRQ_SHIFT)) & ZLL_IRQSTS_PLL_UNLOCK_IRQ_MASK)

#define ZLL_IRQSTS_RX_FRM_PEND_MASK              (0x80U)
#define ZLL_IRQSTS_RX_FRM_PEND_SHIFT             (7U)
/*! RX_FRM_PEND - RX Frame Pending */
#define ZLL_IRQSTS_RX_FRM_PEND(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RX_FRM_PEND_SHIFT)) & ZLL_IRQSTS_RX_FRM_PEND_MASK)

#define ZLL_IRQSTS_WAKE_IRQ_MASK                 (0x100U)
#define ZLL_IRQSTS_WAKE_IRQ_SHIFT                (8U)
/*! WAKE_IRQ - WAKE Interrupt Request
 *  0b0..A Wake Interrupt has not occurred
 *  0b1..A Wake Interrupt has occurred
 */
#define ZLL_IRQSTS_WAKE_IRQ(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_WAKE_IRQ_SHIFT)) & ZLL_IRQSTS_WAKE_IRQ_MASK)

#define ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_MASK (0x200U)
#define ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_SHIFT (9U)
/*! ARB_GRANT_DEASSERTION_IRQ - arb_grant Deassertion IRQ
 *  0b0..An arb_grant Deassertion Interrupt has not occurred
 *  0b1..An arb_grant Deassertion Interrupt has occurred
 */
#define ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_SHIFT)) & ZLL_IRQSTS_ARB_GRANT_DEASSERTION_IRQ_MASK)

#define ZLL_IRQSTS_TSM_IRQ_MASK                  (0x400U)
#define ZLL_IRQSTS_TSM_IRQ_SHIFT                 (10U)
/*! TSM_IRQ - TSM IRQ
 *  0b0..A TSM Interrupt has not occurred
 *  0b1..A TSM Interrupt has occurred
 */
#define ZLL_IRQSTS_TSM_IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TSM_IRQ_SHIFT)) & ZLL_IRQSTS_TSM_IRQ_MASK)

#define ZLL_IRQSTS_ENH_PKT_STATUS_MASK           (0x800U)
#define ZLL_IRQSTS_ENH_PKT_STATUS_SHIFT          (11U)
/*! ENH_PKT_STATUS - Enhanced Packet Status
 *  0b0..The last packet received was neither 4e- nor 2015-compliant
 *  0b1..The last packet received was 4e- or 2015-compliant (RX_FRAME_FILTER register should be queried for additional status bits)
 */
#define ZLL_IRQSTS_ENH_PKT_STATUS(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_ENH_PKT_STATUS_SHIFT)) & ZLL_IRQSTS_ENH_PKT_STATUS_MASK)

#define ZLL_IRQSTS_PI_MASK                       (0x1000U)
#define ZLL_IRQSTS_PI_SHIFT                      (12U)
/*! PI - Poll Indication
 *  0b0..the received packet was not a data request
 *  0b1..the received packet was a data request, regardless of whether a Source Address table match occurred, or
 *       whether Source Address Management is enabled or not
 */
#define ZLL_IRQSTS_PI(x)                         (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_PI_SHIFT)) & ZLL_IRQSTS_PI_MASK)

#define ZLL_IRQSTS_SRCADDR_MASK                  (0x2000U)
#define ZLL_IRQSTS_SRCADDR_SHIFT                 (13U)
/*! SRCADDR - Source Address Match Status */
#define ZLL_IRQSTS_SRCADDR(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_SRCADDR_SHIFT)) & ZLL_IRQSTS_SRCADDR_MASK)

#define ZLL_IRQSTS_CCA_MASK                      (0x4000U)
#define ZLL_IRQSTS_CCA_SHIFT                     (14U)
/*! CCA - CCA Status
 *  0b0..IDLE
 *  0b1..BUSY
 */
#define ZLL_IRQSTS_CCA(x)                        (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_CCA_SHIFT)) & ZLL_IRQSTS_CCA_MASK)

#define ZLL_IRQSTS_CRCVALID_MASK                 (0x8000U)
#define ZLL_IRQSTS_CRCVALID_SHIFT                (15U)
/*! CRCVALID - CRC Valid Status
 *  0b0..Rx FCS != calculated CRC (incorrect)
 *  0b1..Rx FCS = calculated CRC (correct)
 */
#define ZLL_IRQSTS_CRCVALID(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_CRCVALID_SHIFT)) & ZLL_IRQSTS_CRCVALID_MASK)

#define ZLL_IRQSTS_TMR1IRQ_MASK                  (0x10000U)
#define ZLL_IRQSTS_TMR1IRQ_SHIFT                 (16U)
/*! TMR1IRQ - Timer 1 IRQ */
#define ZLL_IRQSTS_TMR1IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR1IRQ_SHIFT)) & ZLL_IRQSTS_TMR1IRQ_MASK)

#define ZLL_IRQSTS_TMR2IRQ_MASK                  (0x20000U)
#define ZLL_IRQSTS_TMR2IRQ_SHIFT                 (17U)
/*! TMR2IRQ - Timer 2 IRQ */
#define ZLL_IRQSTS_TMR2IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR2IRQ_SHIFT)) & ZLL_IRQSTS_TMR2IRQ_MASK)

#define ZLL_IRQSTS_TMR3IRQ_MASK                  (0x40000U)
#define ZLL_IRQSTS_TMR3IRQ_SHIFT                 (18U)
/*! TMR3IRQ - Timer 3 IRQ */
#define ZLL_IRQSTS_TMR3IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR3IRQ_SHIFT)) & ZLL_IRQSTS_TMR3IRQ_MASK)

#define ZLL_IRQSTS_TMR4IRQ_MASK                  (0x80000U)
#define ZLL_IRQSTS_TMR4IRQ_SHIFT                 (19U)
/*! TMR4IRQ - Timer 4 IRQ */
#define ZLL_IRQSTS_TMR4IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR4IRQ_SHIFT)) & ZLL_IRQSTS_TMR4IRQ_MASK)

#define ZLL_IRQSTS_TMR1MSK_MASK                  (0x100000U)
#define ZLL_IRQSTS_TMR1MSK_SHIFT                 (20U)
/*! TMR1MSK - Timer Comparator 1 Interrupt Mask bit
 *  0b0..allows interrupt when comparator matches event timer count
 *  0b1..Interrupt generation is disabled, but a TMR1IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR1MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR1MSK_SHIFT)) & ZLL_IRQSTS_TMR1MSK_MASK)

#define ZLL_IRQSTS_TMR2MSK_MASK                  (0x200000U)
#define ZLL_IRQSTS_TMR2MSK_SHIFT                 (21U)
/*! TMR2MSK - Timer Comparator 2 Interrupt Mask bit
 *  0b0..allows interrupt when comparator matches event timer count
 *  0b1..Interrupt generation is disabled, but a TMR2IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR2MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR2MSK_SHIFT)) & ZLL_IRQSTS_TMR2MSK_MASK)

#define ZLL_IRQSTS_TMR3MSK_MASK                  (0x400000U)
#define ZLL_IRQSTS_TMR3MSK_SHIFT                 (22U)
/*! TMR3MSK - Timer Comparator 3 Interrupt Mask bit
 *  0b0..allows interrupt when comparator matches event timer count
 *  0b1..Interrupt generation is disabled, but a TMR3IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR3MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR3MSK_SHIFT)) & ZLL_IRQSTS_TMR3MSK_MASK)

#define ZLL_IRQSTS_TMR4MSK_MASK                  (0x800000U)
#define ZLL_IRQSTS_TMR4MSK_SHIFT                 (23U)
/*! TMR4MSK - Timer Comparator 4 Interrupt Mask bit
 *  0b0..allows interrupt when comparator matches event timer count
 *  0b1..Interrupt generation is disabled, but a TMR4IRQ flag can be set
 */
#define ZLL_IRQSTS_TMR4MSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_TMR4MSK_SHIFT)) & ZLL_IRQSTS_TMR4MSK_MASK)

#define ZLL_IRQSTS_RX_FRAME_LENGTH_MASK          (0x7F000000U)
#define ZLL_IRQSTS_RX_FRAME_LENGTH_SHIFT         (24U)
/*! RX_FRAME_LENGTH - Receive Frame Length */
#define ZLL_IRQSTS_RX_FRAME_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_IRQSTS_RX_FRAME_LENGTH_SHIFT)) & ZLL_IRQSTS_RX_FRAME_LENGTH_MASK)
/*! @} */

/*! @name PHY_CTRL - PHY CONTROL */
/*! @{ */

#define ZLL_PHY_CTRL_XCVSEQ_MASK                 (0x7U)
#define ZLL_PHY_CTRL_XCVSEQ_SHIFT                (0U)
/*! XCVSEQ - 802.15.4 Transceiver Sequence Selector
 *  0b000..I (IDLE)
 *  0b001..R (RECEIVE)
 *  0b010..T (TRANSMIT)
 *  0b011..C (CCA)
 *  0b100..TR (TRANSMIT/RECEIVE)
 *  0b101..CCCA (CONTINUOUS CCA)
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define ZLL_PHY_CTRL_XCVSEQ(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_XCVSEQ_SHIFT)) & ZLL_PHY_CTRL_XCVSEQ_MASK)

#define ZLL_PHY_CTRL_AUTOACK_MASK                (0x8U)
#define ZLL_PHY_CTRL_AUTOACK_SHIFT               (3U)
/*! AUTOACK - Auto Acknowledge Enable
 *  0b0..sequence manager will not follow a receive frame with a Tx Ack frame, under any conditions; the
 *       autosequence will terminate after the receive frame.
 *  0b1..sequence manager will follow a receive frame with an automatic hardware-generated Tx Ack frame, assuming other necessary conditions are met.
 */
#define ZLL_PHY_CTRL_AUTOACK(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_AUTOACK_SHIFT)) & ZLL_PHY_CTRL_AUTOACK_MASK)

#define ZLL_PHY_CTRL_RXACKRQD_MASK               (0x10U)
#define ZLL_PHY_CTRL_RXACKRQD_SHIFT              (4U)
/*! RXACKRQD - Receive Acknowledge Frame required
 *  0b0..An ordinary receive frame (any type of frame) follows the transmit frame.
 *  0b1..A receive Ack frame is expected to follow the transmit frame (non-Ack frames are rejected).
 */
#define ZLL_PHY_CTRL_RXACKRQD(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_RXACKRQD_SHIFT)) & ZLL_PHY_CTRL_RXACKRQD_MASK)

#define ZLL_PHY_CTRL_CCABFRTX_MASK               (0x20U)
#define ZLL_PHY_CTRL_CCABFRTX_SHIFT              (5U)
/*! CCABFRTX - CCA Before TX
 *  0b0..no CCA required, transmit operation begins immediately.
 *  0b1..at least one CCA measurement is required prior to the transmit operation (see also SLOTTED).
 */
#define ZLL_PHY_CTRL_CCABFRTX(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CCABFRTX_SHIFT)) & ZLL_PHY_CTRL_CCABFRTX_MASK)

#define ZLL_PHY_CTRL_SLOTTED_MASK                (0x40U)
#define ZLL_PHY_CTRL_SLOTTED_SHIFT               (6U)
/*! SLOTTED - Slotted Mode */
#define ZLL_PHY_CTRL_SLOTTED(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_SLOTTED_SHIFT)) & ZLL_PHY_CTRL_SLOTTED_MASK)

#define ZLL_PHY_CTRL_TMRTRIGEN_MASK              (0x80U)
#define ZLL_PHY_CTRL_TMRTRIGEN_SHIFT             (7U)
/*! TMRTRIGEN - Timer2 Trigger Enable
 *  0b0..programmed sequence initiates immediately upon write to XCVSEQ.
 *  0b1..allow timer TC2 (or TC2') to initiate a preprogrammed sequence (see XCVSEQ register).
 */
#define ZLL_PHY_CTRL_TMRTRIGEN(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMRTRIGEN_SHIFT)) & ZLL_PHY_CTRL_TMRTRIGEN_MASK)

#define ZLL_PHY_CTRL_SEQMSK_MASK                 (0x100U)
#define ZLL_PHY_CTRL_SEQMSK_SHIFT                (8U)
/*! SEQMSK - Sequencer Interrupt Mask
 *  0b0..allows completion of an autosequence to generate a zigbee interrupt
 *  0b1..Completion of an autosequence will set the SEQIRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_SEQMSK(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_SEQMSK_SHIFT)) & ZLL_PHY_CTRL_SEQMSK_MASK)

#define ZLL_PHY_CTRL_TXMSK_MASK                  (0x200U)
#define ZLL_PHY_CTRL_TXMSK_SHIFT                 (9U)
/*! TXMSK - TX Interrupt Mask
 *  0b0..allows completion of a TX operation to generate a zigbee interrupt
 *  0b1..Completion of a TX operation will set the TXIRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_TXMSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TXMSK_SHIFT)) & ZLL_PHY_CTRL_TXMSK_MASK)

#define ZLL_PHY_CTRL_RXMSK_MASK                  (0x400U)
#define ZLL_PHY_CTRL_RXMSK_SHIFT                 (10U)
/*! RXMSK - RX Interrupt Mask
 *  0b0..allows completion of a RX operation to generate a zigbee interrupt
 *  0b1..Completion of a RX operation will set the RXIRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_RXMSK(x)                    (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_RXMSK_SHIFT)) & ZLL_PHY_CTRL_RXMSK_MASK)

#define ZLL_PHY_CTRL_CCAMSK_MASK                 (0x800U)
#define ZLL_PHY_CTRL_CCAMSK_SHIFT                (11U)
/*! CCAMSK - CCA Interrupt Mask
 *  0b0..allows completion of a CCA operation to generate a zigbee interrupt
 *  0b1..Completion of a CCA operation will set the CCA status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_CCAMSK(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CCAMSK_SHIFT)) & ZLL_PHY_CTRL_CCAMSK_MASK)

#define ZLL_PHY_CTRL_RX_WMRK_MSK_MASK            (0x1000U)
#define ZLL_PHY_CTRL_RX_WMRK_MSK_SHIFT           (12U)
/*! RX_WMRK_MSK - RX Watermark Interrupt Mask
 *  0b0..allows a Received Byte Count match to the RX_WTR_MARK threshold register to generate a zigbee interrupt
 *  0b1..A Received Byte Count match to the RX_WTR_MARK threshold register will set the RXWTRMRKIRQ status bit,
 *       but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_RX_WMRK_MSK(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_RX_WMRK_MSK_SHIFT)) & ZLL_PHY_CTRL_RX_WMRK_MSK_MASK)

#define ZLL_PHY_CTRL_FILTERFAIL_MSK_MASK         (0x2000U)
#define ZLL_PHY_CTRL_FILTERFAIL_MSK_SHIFT        (13U)
/*! FILTERFAIL_MSK - FilterFail Interrupt Mask
 *  0b0..allows Packet Processor Filtering Failure to generate a zigbee interrupt
 *  0b1..A Packet Processor Filtering Failure will set the FILTERFAIL_IRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_FILTERFAIL_MSK(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_FILTERFAIL_MSK_SHIFT)) & ZLL_PHY_CTRL_FILTERFAIL_MSK_MASK)

#define ZLL_PHY_CTRL_PLL_UNLOCK_MSK_MASK         (0x4000U)
#define ZLL_PHY_CTRL_PLL_UNLOCK_MSK_SHIFT        (14U)
/*! PLL_UNLOCK_MSK - PLL Unlock Interrupt Mask
 *  0b0..allows PLL unlock event to generate a zigbee interrupt
 *  0b1..A PLL unlock event will set the PLL_UNLOCK_IRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_PLL_UNLOCK_MSK(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_PLL_UNLOCK_MSK_SHIFT)) & ZLL_PHY_CTRL_PLL_UNLOCK_MSK_MASK)

#define ZLL_PHY_CTRL_CRC_MSK_MASK                (0x8000U)
#define ZLL_PHY_CTRL_CRC_MSK_SHIFT               (15U)
/*! CRC_MSK - CRC Mask
 *  0b0..sequence manager ignores CRCVALID and considers the receive operation complete after the last octet of the frame has been received.
 *  0b1..sequence manager requires CRCVALID=1 at the end of the received frame in order for the receive operation
 *       to complete successfully; if CRCVALID=0, sequence manager will return to preamble-detect mode after the
 *       last octet of the frame has been received.
 */
#define ZLL_PHY_CTRL_CRC_MSK(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CRC_MSK_SHIFT)) & ZLL_PHY_CTRL_CRC_MSK_MASK)

#define ZLL_PHY_CTRL_WAKE_MSK_MASK               (0x10000U)
#define ZLL_PHY_CTRL_WAKE_MSK_SHIFT              (16U)
/*! WAKE_MSK - Mask wakeup from DSM
 *  0b0..Allows a wakeup from DSM to generate a zigbee interrupt
 *  0b1..Wakeup from DSM will set the WAKE_IRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_WAKE_MSK(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_WAKE_MSK_SHIFT)) & ZLL_PHY_CTRL_WAKE_MSK_MASK)

#define ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_MASK (0x20000U)
#define ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_SHIFT (17U)
/*! ARB_GRANT_DEASSERTION_MSK - arb_grant Deassertion Interrupt Mask
 *  0b0..allows arb_grant deassertion event to generate a zigbee interrupt
 *  0b1..An arb_grant deassertion event will set the ARB_GRANT_DEASSERTION_IRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK(x) (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_SHIFT)) & ZLL_PHY_CTRL_ARB_GRANT_DEASSERTION_MSK_MASK)

#define ZLL_PHY_CTRL_TSM_MSK_MASK                (0x40000U)
#define ZLL_PHY_CTRL_TSM_MSK_SHIFT               (18U)
/*! TSM_MSK - Mask generating interrupt from TSM
 *  0b0..allows assertion of a TSM interrupt to generate a zigbee interrupt
 *  0b1..Assertion of a TSM interrupt will set the TSM_IRQ status bit, but a zigbee interrupt is not generated
 */
#define ZLL_PHY_CTRL_TSM_MSK(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TSM_MSK_SHIFT)) & ZLL_PHY_CTRL_TSM_MSK_MASK)

#define ZLL_PHY_CTRL_TMR1CMP_EN_MASK             (0x100000U)
#define ZLL_PHY_CTRL_TMR1CMP_EN_SHIFT            (20U)
/*! TMR1CMP_EN - Timer 1 Compare Enable
 *  0b0..Don't allow an Event Timer Match to T1CMP to set TMR1IRQ
 *  0b1..Allow an Event Timer Match to T1CMP to set TMR1IRQ
 */
#define ZLL_PHY_CTRL_TMR1CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR1CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR1CMP_EN_MASK)

#define ZLL_PHY_CTRL_TMR2CMP_EN_MASK             (0x200000U)
#define ZLL_PHY_CTRL_TMR2CMP_EN_SHIFT            (21U)
/*! TMR2CMP_EN - Timer 2 Compare Enable
 *  0b0..Don't allow an Event Timer Match to T2CMP or T2PRIMECMP to set TMR2IRQ
 *  0b1..Allow an Event Timer Match to T2CMP or T2PRIMECMP to set TMR2IRQ
 */
#define ZLL_PHY_CTRL_TMR2CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR2CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR2CMP_EN_MASK)

#define ZLL_PHY_CTRL_TMR3CMP_EN_MASK             (0x400000U)
#define ZLL_PHY_CTRL_TMR3CMP_EN_SHIFT            (22U)
/*! TMR3CMP_EN - Timer 3 Compare Enable
 *  0b0..Don't allow an Event Timer Match to T3CMP to set TMR3IRQ
 *  0b1..Allow an Event Timer Match to T3CMP to set TMR3IRQ
 */
#define ZLL_PHY_CTRL_TMR3CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR3CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR3CMP_EN_MASK)

#define ZLL_PHY_CTRL_TMR4CMP_EN_MASK             (0x800000U)
#define ZLL_PHY_CTRL_TMR4CMP_EN_SHIFT            (23U)
/*! TMR4CMP_EN - Timer 4 Compare Enable
 *  0b0..Don't allow an Event Timer Match to T4CMP to set TMR4IRQ
 *  0b1..Allow an Event Timer Match to T4CMP to set TMR4IRQ
 */
#define ZLL_PHY_CTRL_TMR4CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TMR4CMP_EN_SHIFT)) & ZLL_PHY_CTRL_TMR4CMP_EN_MASK)

#define ZLL_PHY_CTRL_TC2PRIME_EN_MASK            (0x1000000U)
#define ZLL_PHY_CTRL_TC2PRIME_EN_SHIFT           (24U)
/*! TC2PRIME_EN - Timer 2 Prime Compare Enable
 *  0b0..Don't allow a match of the lower 16 bits of Event Timer to T2PRIMECMP to set TMR2IRQ
 *  0b1..Allow a match of the lower 16 bits of Event Timer to T2PRIMECMP to set TMR2IRQ
 */
#define ZLL_PHY_CTRL_TC2PRIME_EN(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TC2PRIME_EN_SHIFT)) & ZLL_PHY_CTRL_TC2PRIME_EN_MASK)

#define ZLL_PHY_CTRL_PROMISCUOUS_MASK            (0x2000000U)
#define ZLL_PHY_CTRL_PROMISCUOUS_SHIFT           (25U)
/*! PROMISCUOUS - Promiscuous Mode Enable
 *  0b0..normal mode
 *  0b1..all packet filtering except frame length checking (FrameLength>=5 and FrameLength<=127) is bypassed.
 */
#define ZLL_PHY_CTRL_PROMISCUOUS(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_PROMISCUOUS_SHIFT)) & ZLL_PHY_CTRL_PROMISCUOUS_MASK)

#define ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_MASK    (0x4000000U)
#define ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_SHIFT   (26U)
/*! TC3_POSTPONE_ON_SFD - Postpone TC3 Timeout On SFD Enable
 *  0b0..TC3 Abort will occur on TMR3 timeout, regardless of rx_sfd_detect
 *  0b1..TC3 Abort will be deferred on TMR3 timeout if rx_sfd_detect is asserted; otherwise the TC3 Abort will occur immediately
 */
#define ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_SHIFT)) & ZLL_PHY_CTRL_TC3_POSTPONE_ON_SFD_MASK)

#define ZLL_PHY_CTRL_CCATYPE_MASK                (0x18000000U)
#define ZLL_PHY_CTRL_CCATYPE_SHIFT               (27U)
/*! CCATYPE - Clear Channel Assessment Type
 *  0b00..ENERGY DETECT
 *  0b01..CCA MODE 1
 *  0b10..CCA MODE 2
 *  0b11..CCA MODE 3
 */
#define ZLL_PHY_CTRL_CCATYPE(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_CCATYPE_SHIFT)) & ZLL_PHY_CTRL_CCATYPE_MASK)

#define ZLL_PHY_CTRL_PANCORDNTR0_MASK            (0x20000000U)
#define ZLL_PHY_CTRL_PANCORDNTR0_SHIFT           (29U)
/*! PANCORDNTR0 - Device is a PAN Coordinator on PAN0 */
#define ZLL_PHY_CTRL_PANCORDNTR0(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_PANCORDNTR0_SHIFT)) & ZLL_PHY_CTRL_PANCORDNTR0_MASK)

#define ZLL_PHY_CTRL_TC3TMOUT_MASK               (0x40000000U)
#define ZLL_PHY_CTRL_TC3TMOUT_SHIFT              (30U)
/*! TC3TMOUT - TMR3 Timeout Enable
 *  0b0..TMR3 is a software timer only
 *  0b1..Enable TMR3 to abort Rx or CCCA operations.
 */
#define ZLL_PHY_CTRL_TC3TMOUT(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TC3TMOUT_SHIFT)) & ZLL_PHY_CTRL_TC3TMOUT_MASK)

#define ZLL_PHY_CTRL_TRCV_MSK_MASK               (0x80000000U)
#define ZLL_PHY_CTRL_TRCV_MSK_SHIFT              (31U)
/*! TRCV_MSK - Transceiver Global Interrupt Mask
 *  0b0..Enable any unmasked interrupt source to assert zigbee interrupt
 *  0b1..Mask all interrupt sources from asserting zigbee interrupt
 */
#define ZLL_PHY_CTRL_TRCV_MSK(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PHY_CTRL_TRCV_MSK_SHIFT)) & ZLL_PHY_CTRL_TRCV_MSK_MASK)
/*! @} */

/*! @name EVENT_TMR - EVENT TIMER */
/*! @{ */

#define ZLL_EVENT_TMR_EVENT_TMR_LD_MASK          (0x1U)
#define ZLL_EVENT_TMR_EVENT_TMR_LD_SHIFT         (0U)
/*! EVENT_TMR_LD - Event Timer Load Enable */
#define ZLL_EVENT_TMR_EVENT_TMR_LD(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_EVENT_TMR_EVENT_TMR_LD_SHIFT)) & ZLL_EVENT_TMR_EVENT_TMR_LD_MASK)

#define ZLL_EVENT_TMR_EVENT_TMR_ADD_MASK         (0x2U)
#define ZLL_EVENT_TMR_EVENT_TMR_ADD_SHIFT        (1U)
/*! EVENT_TMR_ADD - Event Timer Add Enable */
#define ZLL_EVENT_TMR_EVENT_TMR_ADD(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_EVENT_TMR_EVENT_TMR_ADD_SHIFT)) & ZLL_EVENT_TMR_EVENT_TMR_ADD_MASK)

#define ZLL_EVENT_TMR_EVENT_TMR_FRAC_MASK        (0xF0U)
#define ZLL_EVENT_TMR_EVENT_TMR_FRAC_SHIFT       (4U)
/*! EVENT_TMR_FRAC - Event Timer Fractional Component */
#define ZLL_EVENT_TMR_EVENT_TMR_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_EVENT_TMR_EVENT_TMR_FRAC_SHIFT)) & ZLL_EVENT_TMR_EVENT_TMR_FRAC_MASK)

#define ZLL_EVENT_TMR_EVENT_TMR_MASK             (0xFFFFFF00U)
#define ZLL_EVENT_TMR_EVENT_TMR_SHIFT            (8U)
/*! EVENT_TMR - Event Timer Integer Component */
#define ZLL_EVENT_TMR_EVENT_TMR(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_EVENT_TMR_EVENT_TMR_SHIFT)) & ZLL_EVENT_TMR_EVENT_TMR_MASK)
/*! @} */

/*! @name TIMESTAMP - TIMESTAMP */
/*! @{ */

#define ZLL_TIMESTAMP_TIMESTAMP_FRAC_MASK        (0xF0U)
#define ZLL_TIMESTAMP_TIMESTAMP_FRAC_SHIFT       (4U)
/*! TIMESTAMP_FRAC - Timestamp Fractional */
#define ZLL_TIMESTAMP_TIMESTAMP_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_TIMESTAMP_TIMESTAMP_FRAC_SHIFT)) & ZLL_TIMESTAMP_TIMESTAMP_FRAC_MASK)

#define ZLL_TIMESTAMP_TIMESTAMP_MASK             (0xFFFFFF00U)
#define ZLL_TIMESTAMP_TIMESTAMP_SHIFT            (8U)
/*! TIMESTAMP - Timestamp */
#define ZLL_TIMESTAMP_TIMESTAMP(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_TIMESTAMP_TIMESTAMP_SHIFT)) & ZLL_TIMESTAMP_TIMESTAMP_MASK)
/*! @} */

/*! @name T1CMP - T1 COMPARE */
/*! @{ */

#define ZLL_T1CMP_T1CMP_MASK                     (0xFFFFFFU)
#define ZLL_T1CMP_T1CMP_SHIFT                    (0U)
/*! T1CMP - TMR1 Compare Value */
#define ZLL_T1CMP_T1CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T1CMP_T1CMP_SHIFT)) & ZLL_T1CMP_T1CMP_MASK)
/*! @} */

/*! @name T2CMP - T2 COMPARE */
/*! @{ */

#define ZLL_T2CMP_T2CMP_MASK                     (0xFFFFFFU)
#define ZLL_T2CMP_T2CMP_SHIFT                    (0U)
/*! T2CMP - TMR2 Compare Value */
#define ZLL_T2CMP_T2CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T2CMP_T2CMP_SHIFT)) & ZLL_T2CMP_T2CMP_MASK)
/*! @} */

/*! @name T2PRIMECMP - T2 PRIME COMPARE */
/*! @{ */

#define ZLL_T2PRIMECMP_T2PRIMECMP_MASK           (0xFFFFU)
#define ZLL_T2PRIMECMP_T2PRIMECMP_SHIFT          (0U)
/*! T2PRIMECMP - TMR2 Prime Compare Value */
#define ZLL_T2PRIMECMP_T2PRIMECMP(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_T2PRIMECMP_T2PRIMECMP_SHIFT)) & ZLL_T2PRIMECMP_T2PRIMECMP_MASK)
/*! @} */

/*! @name T3CMP - T3 COMPARE */
/*! @{ */

#define ZLL_T3CMP_T3CMP_MASK                     (0xFFFFFFU)
#define ZLL_T3CMP_T3CMP_SHIFT                    (0U)
/*! T3CMP - TMR3 Compare Value */
#define ZLL_T3CMP_T3CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T3CMP_T3CMP_SHIFT)) & ZLL_T3CMP_T3CMP_MASK)
/*! @} */

/*! @name T4CMP - T4 COMPARE */
/*! @{ */

#define ZLL_T4CMP_T4CMP_MASK                     (0xFFFFFFU)
#define ZLL_T4CMP_T4CMP_SHIFT                    (0U)
/*! T4CMP - TMR4 Compare Value */
#define ZLL_T4CMP_T4CMP(x)                       (((uint32_t)(((uint32_t)(x)) << ZLL_T4CMP_T4CMP_SHIFT)) & ZLL_T4CMP_T4CMP_MASK)
/*! @} */

/*! @name PA_PWR - PA POWER */
/*! @{ */

#define ZLL_PA_PWR_PA_PWR_MASK                   (0x7FU)
#define ZLL_PA_PWR_PA_PWR_SHIFT                  (0U)
/*! PA_PWR - PA Power */
#define ZLL_PA_PWR_PA_PWR(x)                     (((uint32_t)(((uint32_t)(x)) << ZLL_PA_PWR_PA_PWR_SHIFT)) & ZLL_PA_PWR_PA_PWR_MASK)

#define ZLL_PA_PWR_EXT_PA_PWR_MASK               (0x7F0000U)
#define ZLL_PA_PWR_EXT_PA_PWR_SHIFT              (16U)
/*! EXT_PA_PWR - External PA Power */
#define ZLL_PA_PWR_EXT_PA_PWR(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_PA_PWR_EXT_PA_PWR_SHIFT)) & ZLL_PA_PWR_EXT_PA_PWR_MASK)

#define ZLL_PA_PWR_EXT_PA_PWR_CHG_MASK           (0x80000000U)
#define ZLL_PA_PWR_EXT_PA_PWR_CHG_SHIFT          (31U)
/*! EXT_PA_PWR_CHG - External PA Power Change Flag */
#define ZLL_PA_PWR_EXT_PA_PWR_CHG(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_PA_PWR_EXT_PA_PWR_CHG_SHIFT)) & ZLL_PA_PWR_EXT_PA_PWR_CHG_MASK)
/*! @} */

/*! @name CHANNEL_NUM0 - CHANNEL NUMBER 0 */
/*! @{ */

#define ZLL_CHANNEL_NUM0_CHANNEL_NUM0_MASK       (0x7FU)
#define ZLL_CHANNEL_NUM0_CHANNEL_NUM0_SHIFT      (0U)
/*! CHANNEL_NUM0 - Channel Number for PAN0 */
#define ZLL_CHANNEL_NUM0_CHANNEL_NUM0(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM0_CHANNEL_NUM0_SHIFT)) & ZLL_CHANNEL_NUM0_CHANNEL_NUM0_MASK)
/*! @} */

/*! @name LQI_AND_RSSI - LQI AND RSSI */
/*! @{ */

#define ZLL_LQI_AND_RSSI_LQI_VALUE_MASK          (0xFFU)
#define ZLL_LQI_AND_RSSI_LQI_VALUE_SHIFT         (0U)
/*! LQI_VALUE - LQI Value */
#define ZLL_LQI_AND_RSSI_LQI_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_LQI_AND_RSSI_LQI_VALUE_SHIFT)) & ZLL_LQI_AND_RSSI_LQI_VALUE_MASK)

#define ZLL_LQI_AND_RSSI_RSSI_MASK               (0xFF00U)
#define ZLL_LQI_AND_RSSI_RSSI_SHIFT              (8U)
/*! RSSI - RSSI Value */
#define ZLL_LQI_AND_RSSI_RSSI(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_LQI_AND_RSSI_RSSI_SHIFT)) & ZLL_LQI_AND_RSSI_RSSI_MASK)

#define ZLL_LQI_AND_RSSI_CCA1_ED_FNL_MASK        (0xFF0000U)
#define ZLL_LQI_AND_RSSI_CCA1_ED_FNL_SHIFT       (16U)
/*! CCA1_ED_FNL - Final Result for CCA Mode 1 and Energy Detect */
#define ZLL_LQI_AND_RSSI_CCA1_ED_FNL(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_LQI_AND_RSSI_CCA1_ED_FNL_SHIFT)) & ZLL_LQI_AND_RSSI_CCA1_ED_FNL_MASK)
/*! @} */

/*! @name MACSHORTADDRS0 - MAC SHORT ADDRESS 0 */
/*! @{ */

#define ZLL_MACSHORTADDRS0_MACPANID0_MASK        (0xFFFFU)
#define ZLL_MACSHORTADDRS0_MACPANID0_SHIFT       (0U)
/*! MACPANID0 - MAC PAN ID for PAN0 */
#define ZLL_MACSHORTADDRS0_MACPANID0(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS0_MACPANID0_SHIFT)) & ZLL_MACSHORTADDRS0_MACPANID0_MASK)

#define ZLL_MACSHORTADDRS0_MACSHORTADDRS0_MASK   (0xFFFF0000U)
#define ZLL_MACSHORTADDRS0_MACSHORTADDRS0_SHIFT  (16U)
/*! MACSHORTADDRS0 - MAC SHORT ADDRESS FOR PAN0 */
#define ZLL_MACSHORTADDRS0_MACSHORTADDRS0(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS0_MACSHORTADDRS0_SHIFT)) & ZLL_MACSHORTADDRS0_MACSHORTADDRS0_MASK)
/*! @} */

/*! @name MACLONGADDRS0_LSB - MAC LONG ADDRESS 0 LSB */
/*! @{ */

#define ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_SHIFT (0U)
/*! MACLONGADDRS0_LSB - MAC LONG ADDRESS for PAN0 LSB */
#define ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_SHIFT)) & ZLL_MACLONGADDRS0_LSB_MACLONGADDRS0_LSB_MASK)
/*! @} */

/*! @name MACLONGADDRS0_MSB - MAC LONG ADDRESS 0 MSB */
/*! @{ */

#define ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_SHIFT (0U)
/*! MACLONGADDRS0_MSB - MAC LONG ADDRESS for PAN0 MSB */
#define ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_SHIFT)) & ZLL_MACLONGADDRS0_MSB_MACLONGADDRS0_MSB_MASK)
/*! @} */

/*! @name RX_FRAME_FILTER - RECEIVE FRAME FILTER */
/*! @{ */

#define ZLL_RX_FRAME_FILTER_BEACON_FT_MASK       (0x1U)
#define ZLL_RX_FRAME_FILTER_BEACON_FT_SHIFT      (0U)
/*! BEACON_FT - Beacon Frame Type Enable
 *  0b0..reject all Beacon frames
 *  0b1..Beacon frame type enabled.
 */
#define ZLL_RX_FRAME_FILTER_BEACON_FT(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_BEACON_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_BEACON_FT_MASK)

#define ZLL_RX_FRAME_FILTER_DATA_FT_MASK         (0x2U)
#define ZLL_RX_FRAME_FILTER_DATA_FT_SHIFT        (1U)
/*! DATA_FT - Data Frame Type Enable
 *  0b0..reject all Beacon frames
 *  0b1..Data frame type enabled.
 */
#define ZLL_RX_FRAME_FILTER_DATA_FT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_DATA_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_DATA_FT_MASK)

#define ZLL_RX_FRAME_FILTER_ACK_FT_MASK          (0x4U)
#define ZLL_RX_FRAME_FILTER_ACK_FT_SHIFT         (2U)
/*! ACK_FT - Ack Frame Type Enable
 *  0b0..reject all Acknowledge frames
 *  0b1..Acknowledge frame type enabled.
 */
#define ZLL_RX_FRAME_FILTER_ACK_FT(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_ACK_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_ACK_FT_MASK)

#define ZLL_RX_FRAME_FILTER_CMD_FT_MASK          (0x8U)
#define ZLL_RX_FRAME_FILTER_CMD_FT_SHIFT         (3U)
/*! CMD_FT - MAC Command Frame Type Enable
 *  0b0..reject all MAC Command frames
 *  0b1..MAC Command frame type enabled.
 */
#define ZLL_RX_FRAME_FILTER_CMD_FT(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_CMD_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_CMD_FT_MASK)

#define ZLL_RX_FRAME_FILTER_LLDN_FT_MASK         (0x10U)
#define ZLL_RX_FRAME_FILTER_LLDN_FT_SHIFT        (4U)
/*! LLDN_FT - LLDN Frame Type Enable
 *  0b0..reject all LLDN frames
 *  0b1..LLDN frame type enabled (Frame Type 4).
 */
#define ZLL_RX_FRAME_FILTER_LLDN_FT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_LLDN_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_LLDN_FT_MASK)

#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_MASK (0x20U)
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_SHIFT (5U)
/*! MULTIPURPOSE_FT - Multipurpose Frame Type Enable
 *  0b0..reject all Multipurpose frames
 *  0b1..Multipurpose frame type enabled (Frame Type 5).
 */
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_MULTIPURPOSE_FT_MASK)

#define ZLL_RX_FRAME_FILTER_NS_FT_MASK           (0x40U)
#define ZLL_RX_FRAME_FILTER_NS_FT_SHIFT          (6U)
/*! NS_FT - "Not Specified" Frame Type Enable
 *  0b0..reject all "Not Specified" frames
 *  0b1..Not-specified (reserved) frame type enabled. Applies to Frame Type 6. No packet filtering is performed,
 *       except for frame length checking (FrameLength>=5 and FrameLength<=127). No AUTOACK is transmitted for this
 *       Frame Type
 */
#define ZLL_RX_FRAME_FILTER_NS_FT(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_NS_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_NS_FT_MASK)

#define ZLL_RX_FRAME_FILTER_EXTENDED_FT_MASK     (0x80U)
#define ZLL_RX_FRAME_FILTER_EXTENDED_FT_SHIFT    (7U)
/*! EXTENDED_FT - Extended Frame Type Enable
 *  0b0..reject all Extended frames
 *  0b1..Extended frame type enabled (Frame Type 7).
 */
#define ZLL_RX_FRAME_FILTER_EXTENDED_FT(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_EXTENDED_FT_SHIFT)) & ZLL_RX_FRAME_FILTER_EXTENDED_FT_MASK)

#define ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_MASK  (0xF00U)
#define ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_SHIFT (8U)
/*! FRM_VER_FILTER - Frame Version selector. */
#define ZLL_RX_FRAME_FILTER_FRM_VER_FILTER(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_SHIFT)) & ZLL_RX_FRAME_FILTER_FRM_VER_FILTER_MASK)

#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_MASK (0x4000U)
#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_SHIFT (14U)
/*! ACTIVE_PROMISCUOUS - Active Promiscuous
 *  0b0..normal operation
 *  0b1..Provide Data Indication on all received packets under the same rules which apply in PROMISCUOUS mode,
 *       however acknowledge those packets under rules which apply in non-PROMISCUOUS mode
 */
#define ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS(x) (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_SHIFT)) & ZLL_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS_MASK)

#define ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_MASK (0x8000U)
#define ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_SHIFT (15U)
/*! EXTENDED_FCS_CHK - Verify FCS on Frame Type Extended
 *  0b0..Packet Processor will not check FCS for Frame Type EXTENDED (default)
 *  0b1..Packet Processor will check FCS at end-of-packet based on packet length derived from PHR, for Frame Type EXTENDED
 */
#define ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_SHIFT)) & ZLL_RX_FRAME_FILTER_EXTENDED_FCS_CHK_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_MASK (0x10000U)
#define ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_SHIFT (16U)
/*! FV2_BEACON_RECD - Frame Version 2 Beacon Packet Received
 *  0b0..The last packet received was not Frame Type Beacon with Frame Version 2
 *  0b1..The last packet received was Frame Type Beacon with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_BEACON_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_MASK   (0x20000U)
#define ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_SHIFT  (17U)
/*! FV2_DATA_RECD - Frame Version 2 Data Packet Received
 *  0b0..The last packet received was not Frame Type Data with Frame Version 2
 *  0b1..The last packet received was Frame Type Data with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_DATA_RECD(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_DATA_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_MASK    (0x40000U)
#define ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_SHIFT   (18U)
/*! FV2_ACK_RECD - Frame Version 2 Acknowledge Packet Received
 *  0b0..The last packet received was not Frame Type Ack with Frame Version 2
 *  0b1..The last packet received was Frame Type Ack with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_ACK_RECD(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_ACK_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_MASK    (0x80000U)
#define ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_SHIFT   (19U)
/*! FV2_CMD_RECD - Frame Version 2 MAC Command Packet Received
 *  0b0..The last packet received was not Frame Type MAC Command with Frame Version 2
 *  0b1..The last packet received was Frame Type MAC Command with Frame Version 2, and FRM_VER_FILTER[2]=1 to allow such packets
 */
#define ZLL_RX_FRAME_FILTER_FV2_CMD_RECD(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_FV2_CMD_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_LLDN_RECD_MASK       (0x100000U)
#define ZLL_RX_FRAME_FILTER_LLDN_RECD_SHIFT      (20U)
/*! LLDN_RECD - LLDN Packet Received
 *  0b0..The last packet received was not Frame Type LLDN
 *  0b1..The last packet received was Frame Type LLDN, and LLDN_FT=1 to allow such packets.
 */
#define ZLL_RX_FRAME_FILTER_LLDN_RECD(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_LLDN_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_LLDN_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_MASK (0x200000U)
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_SHIFT (21U)
/*! MULTIPURPOSE_RECD - Multipurpose Packet Received
 *  0b0..last packet received was not Frame Type MULTIPURPOSE
 *  0b1..The last packet received was Frame Type MULTIPURPOSE, and MULTIPURPOSE_FT=1 to allow such packets.
 */
#define ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD(x) (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_MULTIPURPOSE_RECD_MASK)

#define ZLL_RX_FRAME_FILTER_EXTENDED_RECD_MASK   (0x800000U)
#define ZLL_RX_FRAME_FILTER_EXTENDED_RECD_SHIFT  (23U)
/*! EXTENDED_RECD - Extended Packet Received
 *  0b0..The last packet received was not Frame Type EXTENDED
 *  0b1..The last packet received was Frame Type EXTENDED, and EXTENDED_FT=1 to allow such packets.
 */
#define ZLL_RX_FRAME_FILTER_EXTENDED_RECD(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_RX_FRAME_FILTER_EXTENDED_RECD_SHIFT)) & ZLL_RX_FRAME_FILTER_EXTENDED_RECD_MASK)
/*! @} */

/*! @name CCA_LQI_CTRL - CCA AND LQI CONTROL */
/*! @{ */

#define ZLL_CCA_LQI_CTRL_CCA1_THRESH_MASK        (0xFFU)
#define ZLL_CCA_LQI_CTRL_CCA1_THRESH_SHIFT       (0U)
/*! CCA1_THRESH - CCA Mode 1 Threshold */
#define ZLL_CCA_LQI_CTRL_CCA1_THRESH(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_CCA1_THRESH_SHIFT)) & ZLL_CCA_LQI_CTRL_CCA1_THRESH_MASK)

#define ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_MASK    (0xFF0000U)
#define ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_SHIFT   (16U)
/*! LQI_OFFSET_COMP - LQI Offset Compensation */
#define ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_SHIFT)) & ZLL_CCA_LQI_CTRL_LQI_OFFSET_COMP_MASK)

#define ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_MASK       (0x1000000U)
#define ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_SHIFT      (24U)
/*! SIMUL_CCA_RX - Simultaneous CCA and Receive Enable
 *  0b0..Packets can't be received during CCA measurement
 *  0b1..Packet reception is enabled during CCA measurement if preamble and SFD are detected
 */
#define ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_SHIFT)) & ZLL_CCA_LQI_CTRL_SIMUL_CCA_RX_MASK)

#define ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_MASK    (0x8000000U)
#define ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_SHIFT   (27U)
/*! CCA3_AND_NOT_OR - CCA Mode 3 AND not OR
 *  0b0..CCA1 or CCA2
 *  0b1..CCA1 and CCA2
 */
#define ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_SHIFT)) & ZLL_CCA_LQI_CTRL_CCA3_AND_NOT_OR_MASK)
/*! @} */

/*! @name CCA2_CTRL - CCA2 CONTROL */
/*! @{ */

#define ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_MASK   (0xFU)
#define ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_SHIFT  (0U)
/*! CCA2_NUM_CORR_PEAKS - CCA Mode 2 Number of Correlation Peaks Detected */
#define ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_SHIFT)) & ZLL_CCA2_CTRL_CCA2_NUM_CORR_PEAKS_MASK)

#define ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_MASK  (0x70U)
#define ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_SHIFT (4U)
/*! CCA2_MIN_NUM_CORR_TH - CCA Mode 2 Threshold Number of Correlation Peaks */
#define ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_SHIFT)) & ZLL_CCA2_CTRL_CCA2_MIN_NUM_CORR_TH_MASK)

#define ZLL_CCA2_CTRL_CCA2_CORR_THRESH_MASK      (0xFF00U)
#define ZLL_CCA2_CTRL_CCA2_CORR_THRESH_SHIFT     (8U)
/*! CCA2_CORR_THRESH - CCA Mode 2 Correlation Threshold */
#define ZLL_CCA2_CTRL_CCA2_CORR_THRESH(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_CCA2_CTRL_CCA2_CORR_THRESH_SHIFT)) & ZLL_CCA2_CTRL_CCA2_CORR_THRESH_MASK)
/*! @} */

/*! @name DSM_CTRL - DSM CONTROL */
/*! @{ */

#define ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_MASK   (0x1U)
#define ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_SHIFT  (0U)
/*! ZIGBEE_SLEEP_REQUEST - 802.15.4 Deep Sleep Mode Request for Manual DSM */
#define ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_SHIFT)) & ZLL_DSM_CTRL_ZIGBEE_SLEEP_REQUEST_MASK)
/*! @} */

/*! @name MACSHORTADDRS1 - MAC SHORT ADDRESS FOR PAN1 */
/*! @{ */

#define ZLL_MACSHORTADDRS1_MACPANID1_MASK        (0xFFFFU)
#define ZLL_MACSHORTADDRS1_MACPANID1_SHIFT       (0U)
/*! MACPANID1 - MAC PAN ID for PAN1 */
#define ZLL_MACSHORTADDRS1_MACPANID1(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS1_MACPANID1_SHIFT)) & ZLL_MACSHORTADDRS1_MACPANID1_MASK)

#define ZLL_MACSHORTADDRS1_MACSHORTADDRS1_MASK   (0xFFFF0000U)
#define ZLL_MACSHORTADDRS1_MACSHORTADDRS1_SHIFT  (16U)
/*! MACSHORTADDRS1 - MAC SHORT ADDRESS for PAN1 */
#define ZLL_MACSHORTADDRS1_MACSHORTADDRS1(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_MACSHORTADDRS1_MACSHORTADDRS1_SHIFT)) & ZLL_MACSHORTADDRS1_MACSHORTADDRS1_MASK)
/*! @} */

/*! @name MACLONGADDRS1_LSB - MAC LONG ADDRESS 1 LSB */
/*! @{ */

#define ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_SHIFT (0U)
/*! MACLONGADDRS1_LSB - MAC LONG ADDRESS for PAN1 LSB */
#define ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_SHIFT)) & ZLL_MACLONGADDRS1_LSB_MACLONGADDRS1_LSB_MASK)
/*! @} */

/*! @name MACLONGADDRS1_MSB - MAC LONG ADDRESS 1 MSB */
/*! @{ */

#define ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_MASK (0xFFFFFFFFU)
#define ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_SHIFT (0U)
/*! MACLONGADDRS1_MSB - MAC LONG ADDRESS for PAN1 MSB */
#define ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB(x) (((uint32_t)(((uint32_t)(x)) << ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_SHIFT)) & ZLL_MACLONGADDRS1_MSB_MACLONGADDRS1_MSB_MASK)
/*! @} */

/*! @name DUAL_PAN_CTRL - DUAL PAN CONTROL */
/*! @{ */

#define ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_MASK    (0x1U)
#define ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_SHIFT   (0U)
/*! ACTIVE_NETWORK - Active Network Selector
 *  0b0..Select PAN0
 *  0b1..Select PAN1
 */
#define ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_SHIFT)) & ZLL_DUAL_PAN_CTRL_ACTIVE_NETWORK_MASK)

#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_MASK     (0x2U)
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_SHIFT    (1U)
/*! DUAL_PAN_AUTO - Activates automatic Dual PAN operating mode */
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_SHIFT)) & ZLL_DUAL_PAN_CTRL_DUAL_PAN_AUTO_MASK)

#define ZLL_DUAL_PAN_CTRL_PANCORDNTR1_MASK       (0x4U)
#define ZLL_DUAL_PAN_CTRL_PANCORDNTR1_SHIFT      (2U)
/*! PANCORDNTR1 - Device is a PAN Coordinator on PAN1 */
#define ZLL_DUAL_PAN_CTRL_PANCORDNTR1(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_PANCORDNTR1_SHIFT)) & ZLL_DUAL_PAN_CTRL_PANCORDNTR1_MASK)

#define ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_MASK   (0x8U)
#define ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_SHIFT  (3U)
/*! CURRENT_NETWORK - Indicates which PAN is currently selected by hardware
 *  0b0..PAN0 is selected
 *  0b1..PAN1 is selected
 */
#define ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_SHIFT)) & ZLL_DUAL_PAN_CTRL_CURRENT_NETWORK_MASK)

#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_MASK (0x10U)
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_SHIFT (4U)
/*! ZB_DP_CHAN_OVRD_EN - Dual PAN Channel Override Enable */
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_SHIFT)) & ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_EN_MASK)

#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_MASK (0x20U)
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_SHIFT (5U)
/*! ZB_DP_CHAN_OVRD_SEL - Dual PAN Channel Override Selector */
#define ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL(x) (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_SHIFT)) & ZLL_DUAL_PAN_CTRL_ZB_DP_CHAN_OVRD_SEL_MASK)

#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_MASK    (0xFF00U)
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_SHIFT   (8U)
/*! DUAL_PAN_DWELL - Dual PAN Channel Frequency Dwell Time */
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_SHIFT)) & ZLL_DUAL_PAN_CTRL_DUAL_PAN_DWELL_MASK)

#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_MASK   (0x3F0000U)
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_SHIFT  (16U)
/*! DUAL_PAN_REMAIN - Time Remaining before next PAN switch in auto Dual PAN mode */
#define ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_SHIFT)) & ZLL_DUAL_PAN_CTRL_DUAL_PAN_REMAIN_MASK)

#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_MASK      (0x400000U)
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_SHIFT     (22U)
/*! RECD_ON_PAN0 - Last Packet was Received on PAN0 */
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECD_ON_PAN0_MASK)

#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_MASK      (0x800000U)
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_SHIFT     (23U)
/*! RECD_ON_PAN1 - Last Packet was Received on PAN1 */
#define ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_SHIFT)) & ZLL_DUAL_PAN_CTRL_RECD_ON_PAN1_MASK)
/*! @} */

/*! @name CHANNEL_NUM1 - CHANNEL NUMBER 1 */
/*! @{ */

#define ZLL_CHANNEL_NUM1_CHANNEL_NUM1_MASK       (0x7FU)
#define ZLL_CHANNEL_NUM1_CHANNEL_NUM1_SHIFT      (0U)
/*! CHANNEL_NUM1 - Channel Number for PAN1 */
#define ZLL_CHANNEL_NUM1_CHANNEL_NUM1(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_CHANNEL_NUM1_CHANNEL_NUM1_SHIFT)) & ZLL_CHANNEL_NUM1_CHANNEL_NUM1_MASK)
/*! @} */

/*! @name SAM_CTRL - SAM CONTROL */
/*! @{ */

#define ZLL_SAM_CTRL_SAP0_EN_MASK                (0x1U)
#define ZLL_SAM_CTRL_SAP0_EN_SHIFT               (0U)
/*! SAP0_EN - Enables SAP0 Partition of the SAM Table
 *  0b0..Disables SAP0 Partition
 *  0b1..Enables SAP0 Partition
 */
#define ZLL_SAM_CTRL_SAP0_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAP0_EN_SHIFT)) & ZLL_SAM_CTRL_SAP0_EN_MASK)

#define ZLL_SAM_CTRL_SAA0_EN_MASK                (0x2U)
#define ZLL_SAM_CTRL_SAA0_EN_SHIFT               (1U)
/*! SAA0_EN - Enables SAA0 Partition of the SAM Table
 *  0b0..Disables SAA0 Partition
 *  0b1..Enables SAA0 Partition
 */
#define ZLL_SAM_CTRL_SAA0_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA0_EN_SHIFT)) & ZLL_SAM_CTRL_SAA0_EN_MASK)

#define ZLL_SAM_CTRL_SAP1_EN_MASK                (0x4U)
#define ZLL_SAM_CTRL_SAP1_EN_SHIFT               (2U)
/*! SAP1_EN - Enables SAP1 Partition of the SAM Table
 *  0b0..Disables SAP1 Partition
 *  0b1..Enables SAP1 Partition
 */
#define ZLL_SAM_CTRL_SAP1_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAP1_EN_SHIFT)) & ZLL_SAM_CTRL_SAP1_EN_MASK)

#define ZLL_SAM_CTRL_SAA1_EN_MASK                (0x8U)
#define ZLL_SAM_CTRL_SAA1_EN_SHIFT               (3U)
/*! SAA1_EN - Enables SAA1 Partition of the SAM Table
 *  0b0..Disables SAA1 Partition
 *  0b1..Enables SAA1 Partition
 */
#define ZLL_SAM_CTRL_SAA1_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA1_EN_SHIFT)) & ZLL_SAM_CTRL_SAA1_EN_MASK)

#define ZLL_SAM_CTRL_SAA0_START_MASK             (0xFF00U)
#define ZLL_SAM_CTRL_SAA0_START_SHIFT            (8U)
/*! SAA0_START - First Index of SAA0 partition */
#define ZLL_SAM_CTRL_SAA0_START(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA0_START_SHIFT)) & ZLL_SAM_CTRL_SAA0_START_MASK)

#define ZLL_SAM_CTRL_SAP1_START_MASK             (0xFF0000U)
#define ZLL_SAM_CTRL_SAP1_START_SHIFT            (16U)
/*! SAP1_START - First Index of SAP1 partition */
#define ZLL_SAM_CTRL_SAP1_START(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAP1_START_SHIFT)) & ZLL_SAM_CTRL_SAP1_START_MASK)

#define ZLL_SAM_CTRL_SAA1_START_MASK             (0xFF000000U)
#define ZLL_SAM_CTRL_SAA1_START_SHIFT            (24U)
/*! SAA1_START - First Index of SAA1 partition */
#define ZLL_SAM_CTRL_SAA1_START(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_CTRL_SAA1_START_SHIFT)) & ZLL_SAM_CTRL_SAA1_START_MASK)
/*! @} */

/*! @name SAM_TABLE - SOURCE ADDRESS MANAGEMENT TABLE */
/*! @{ */

#define ZLL_SAM_TABLE_SAM_INDEX_MASK             (0x7FU)
#define ZLL_SAM_TABLE_SAM_INDEX_SHIFT            (0U)
/*! SAM_INDEX - Contains the SAM table index to be enabled or invalidated */
#define ZLL_SAM_TABLE_SAM_INDEX(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_MASK)

#define ZLL_SAM_TABLE_SAM_INDEX_WR_MASK          (0x80U)
#define ZLL_SAM_TABLE_SAM_INDEX_WR_SHIFT         (7U)
/*! SAM_INDEX_WR - Enables SAM Table Contents to be updated */
#define ZLL_SAM_TABLE_SAM_INDEX_WR(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_WR_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_WR_MASK)

#define ZLL_SAM_TABLE_SAM_CHECKSUM_MASK          (0xFFFF00U)
#define ZLL_SAM_TABLE_SAM_CHECKSUM_SHIFT         (8U)
/*! SAM_CHECKSUM - Software-computed source address checksum, to be installed into a table index */
#define ZLL_SAM_TABLE_SAM_CHECKSUM(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_CHECKSUM_SHIFT)) & ZLL_SAM_TABLE_SAM_CHECKSUM_MASK)

#define ZLL_SAM_TABLE_SAM_INDEX_INV_MASK         (0x1000000U)
#define ZLL_SAM_TABLE_SAM_INDEX_INV_SHIFT        (24U)
/*! SAM_INDEX_INV - Invalidate the SAM table index selected by SAM_INDEX */
#define ZLL_SAM_TABLE_SAM_INDEX_INV(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_INV_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_INV_MASK)

#define ZLL_SAM_TABLE_SAM_INDEX_EN_MASK          (0x2000000U)
#define ZLL_SAM_TABLE_SAM_INDEX_EN_SHIFT         (25U)
/*! SAM_INDEX_EN - Enable the SAM table index selected by SAM_INDEX */
#define ZLL_SAM_TABLE_SAM_INDEX_EN(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_INDEX_EN_SHIFT)) & ZLL_SAM_TABLE_SAM_INDEX_EN_MASK)

#define ZLL_SAM_TABLE_ACK_FRM_PND_MASK           (0x4000000U)
#define ZLL_SAM_TABLE_ACK_FRM_PND_SHIFT          (26U)
/*! ACK_FRM_PND - State of AutoTxAck FramePending field when SAM Accelleration is Disabled */
#define ZLL_SAM_TABLE_ACK_FRM_PND(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_ACK_FRM_PND_SHIFT)) & ZLL_SAM_TABLE_ACK_FRM_PND_MASK)

#define ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_MASK      (0x8000000U)
#define ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_SHIFT     (27U)
/*! ACK_FRM_PND_CTRL - Manual Control for AutoTxAck FramePending field
 *  0b0..the FramePending field of the Frame Control Field of the next automatic TX acknowledge packet is determined by hardware
 *  0b1..the FramePending field of the Frame Control Field of the next automatic TX acknowledge packet tracks ACK_FRM_PEND
 */
#define ZLL_SAM_TABLE_ACK_FRM_PND_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_SHIFT)) & ZLL_SAM_TABLE_ACK_FRM_PND_CTRL_MASK)

#define ZLL_SAM_TABLE_FIND_FREE_IDX_MASK         (0x10000000U)
#define ZLL_SAM_TABLE_FIND_FREE_IDX_SHIFT        (28U)
/*! FIND_FREE_IDX - Find First Free Index */
#define ZLL_SAM_TABLE_FIND_FREE_IDX(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_FIND_FREE_IDX_SHIFT)) & ZLL_SAM_TABLE_FIND_FREE_IDX_MASK)

#define ZLL_SAM_TABLE_INVALIDATE_ALL_MASK        (0x20000000U)
#define ZLL_SAM_TABLE_INVALIDATE_ALL_SHIFT       (29U)
/*! INVALIDATE_ALL - Invalidate Entire SAM Table */
#define ZLL_SAM_TABLE_INVALIDATE_ALL(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_INVALIDATE_ALL_SHIFT)) & ZLL_SAM_TABLE_INVALIDATE_ALL_MASK)

#define ZLL_SAM_TABLE_SAM_BUSY_MASK              (0x80000000U)
#define ZLL_SAM_TABLE_SAM_BUSY_SHIFT             (31U)
/*! SAM_BUSY - SAM Table Update Status Bit */
#define ZLL_SAM_TABLE_SAM_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_TABLE_SAM_BUSY_SHIFT)) & ZLL_SAM_TABLE_SAM_BUSY_MASK)
/*! @} */

/*! @name SAM_MATCH - SOURCE ADDRESS MANAGEMENT MATCH */
/*! @{ */

#define ZLL_SAM_MATCH_SAP0_MATCH_MASK            (0x7FU)
#define ZLL_SAM_MATCH_SAP0_MATCH_SHIFT           (0U)
/*! SAP0_MATCH - Index in the SAP0 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAP0_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAP0_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAP0_MATCH_MASK)

#define ZLL_SAM_MATCH_SAP0_ADDR_PRESENT_MASK     (0x80U)
#define ZLL_SAM_MATCH_SAP0_ADDR_PRESENT_SHIFT    (7U)
/*! SAP0_ADDR_PRESENT - A Checksum Match is Present in the SAP0 Partition of the SAM Table */
#define ZLL_SAM_MATCH_SAP0_ADDR_PRESENT(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAP0_ADDR_PRESENT_SHIFT)) & ZLL_SAM_MATCH_SAP0_ADDR_PRESENT_MASK)

#define ZLL_SAM_MATCH_SAA0_MATCH_MASK            (0x7F00U)
#define ZLL_SAM_MATCH_SAA0_MATCH_SHIFT           (8U)
/*! SAA0_MATCH - Index in the SAA0 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAA0_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAA0_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAA0_MATCH_MASK)

#define ZLL_SAM_MATCH_SAA0_ADDR_ABSENT_MASK      (0x8000U)
#define ZLL_SAM_MATCH_SAA0_ADDR_ABSENT_SHIFT     (15U)
/*! SAA0_ADDR_ABSENT - A Checksum Match is Absent in the SAA0 Partition of the SAM Table */
#define ZLL_SAM_MATCH_SAA0_ADDR_ABSENT(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAA0_ADDR_ABSENT_SHIFT)) & ZLL_SAM_MATCH_SAA0_ADDR_ABSENT_MASK)

#define ZLL_SAM_MATCH_SAP1_MATCH_MASK            (0x7F0000U)
#define ZLL_SAM_MATCH_SAP1_MATCH_SHIFT           (16U)
/*! SAP1_MATCH - Index in the SAP1 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAP1_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAP1_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAP1_MATCH_MASK)

#define ZLL_SAM_MATCH_SAP1_ADDR_PRESENT_MASK     (0x800000U)
#define ZLL_SAM_MATCH_SAP1_ADDR_PRESENT_SHIFT    (23U)
/*! SAP1_ADDR_PRESENT - A Checksum Match is Present in the SAP1 Partition of the SAM Table */
#define ZLL_SAM_MATCH_SAP1_ADDR_PRESENT(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAP1_ADDR_PRESENT_SHIFT)) & ZLL_SAM_MATCH_SAP1_ADDR_PRESENT_MASK)

#define ZLL_SAM_MATCH_SAA1_MATCH_MASK            (0x7F000000U)
#define ZLL_SAM_MATCH_SAA1_MATCH_SHIFT           (24U)
/*! SAA1_MATCH - Index in the SAA1 Partition of the SAM Table corresponding to the first checksum match */
#define ZLL_SAM_MATCH_SAA1_MATCH(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAA1_MATCH_SHIFT)) & ZLL_SAM_MATCH_SAA1_MATCH_MASK)

#define ZLL_SAM_MATCH_SAA1_ADDR_ABSENT_MASK      (0x80000000U)
#define ZLL_SAM_MATCH_SAA1_ADDR_ABSENT_SHIFT     (31U)
/*! SAA1_ADDR_ABSENT - A Checksum Match is Absent in the SAP1 Partition of the SAM Table */
#define ZLL_SAM_MATCH_SAA1_ADDR_ABSENT(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_MATCH_SAA1_ADDR_ABSENT_SHIFT)) & ZLL_SAM_MATCH_SAA1_ADDR_ABSENT_MASK)
/*! @} */

/*! @name SAM_FREE_IDX - SAM FREE INDEX */
/*! @{ */

#define ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_MASK  (0xFFU)
#define ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_SHIFT (0U)
/*! SAP0_1ST_FREE_IDX - First non-enabled (invalid) index in the SAP0 partition */
#define ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAP0_1ST_FREE_IDX_MASK)

#define ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_MASK  (0xFF00U)
#define ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_SHIFT (8U)
/*! SAA0_1ST_FREE_IDX - First non-enabled (invalid) index in the SAA0 partition */
#define ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAA0_1ST_FREE_IDX_MASK)

#define ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_MASK  (0xFF0000U)
#define ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_SHIFT (16U)
/*! SAP1_1ST_FREE_IDX - First non-enabled (invalid) index in the SAP1 partition */
#define ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAP1_1ST_FREE_IDX_MASK)

#define ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_MASK  (0xFF000000U)
#define ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_SHIFT (24U)
/*! SAA1_1ST_FREE_IDX - First non-enabled (invalid) index in the SAA1 partition */
#define ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_SHIFT)) & ZLL_SAM_FREE_IDX_SAA1_1ST_FREE_IDX_MASK)
/*! @} */

/*! @name SEQ_CTRL_STS - SEQUENCE CONTROL AND STATUS */
/*! @{ */

#define ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_MASK       (0x2U)
#define ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_SHIFT      (1U)
/*! FORCE_CLK_ON - Force On 802.15.4 phy_gck
 *  0b0..Allow TSM to control 802.15.4 phy_gck, for minimum power consumption (default)
 *  0b1..Force on 802.15.4 phy_gclk at all times, for debug purposes only
 */
#define ZLL_SEQ_CTRL_STS_FORCE_CLK_ON(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_SHIFT)) & ZLL_SEQ_CTRL_STS_FORCE_CLK_ON_MASK)

#define ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_MASK (0x4U)
#define ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_SHIFT (2U)
/*! CLR_NEW_SEQ_INHIBIT - Overrides the automatic hardware locking of the programmed XCVSEQ while an autosequence is underway */
#define ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_SHIFT)) & ZLL_SEQ_CTRL_STS_CLR_NEW_SEQ_INHIBIT_MASK)

#define ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_MASK (0x8U)
#define ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_SHIFT (3U)
/*! EVENT_TMR_DO_NOT_LATCH - Overrides the automatic hardware latching of the Event Timer */
#define ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_SHIFT)) & ZLL_SEQ_CTRL_STS_EVENT_TMR_DO_NOT_LATCH_MASK)

#define ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_MASK     (0x10U)
#define ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_SHIFT    (4U)
/*! LATCH_PREAMBLE - Stickiness Control for Preamble Detection
 *  0b0..Don't make PREAMBLE_DET and SFD_DET bits of PHY_STS (SEQ_STATE) Register "sticky", i.e, these status bits
 *       reflect the realtime, dynamic state of preamble_detect and sfd_detect
 *  0b1..Make PREAMBLE_DET and SFD_DET bits of PHY_STS (SEQ_STATE) Register "sticky", i.e., occurrences of
 *       preamble and SFD detection are latched and held until the start of the next autosequence
 */
#define ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_SHIFT)) & ZLL_SEQ_CTRL_STS_LATCH_PREAMBLE_MASK)

#define ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_MASK      (0x20U)
#define ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_SHIFT     (5U)
/*! NO_RX_RECYCLE - Disable Automatic RX Sequence Recycling */
#define ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_SHIFT)) & ZLL_SEQ_CTRL_STS_NO_RX_RECYCLE_MASK)

#define ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_MASK    (0x40U)
#define ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_SHIFT   (6U)
/*! FORCE_CRC_ERROR - Induce a CRC Error in Transmitted Packets
 *  0b0..normal operation
 *  0b1..Force the next transmitted packet to have a CRC error
 */
#define ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_SHIFT)) & ZLL_SEQ_CTRL_STS_FORCE_CRC_ERROR_MASK)

#define ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_MASK      (0x80U)
#define ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_SHIFT     (7U)
/*! CONTINUOUS_EN - Enable Continuous TX or RX Mode
 *  0b0..normal operation
 *  0b1..Continuous TX or RX mode is enabled (depending on XCVSEQ setting).
 */
#define ZLL_SEQ_CTRL_STS_CONTINUOUS_EN(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_SHIFT)) & ZLL_SEQ_CTRL_STS_CONTINUOUS_EN_MASK)

#define ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_MASK      (0x700U)
#define ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_SHIFT     (8U)
/*! XCVSEQ_ACTUAL - Indicates the programmed sequence that has been recognized by the ZSM Sequence Manager */
#define ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_SHIFT)) & ZLL_SEQ_CTRL_STS_XCVSEQ_ACTUAL_MASK)

#define ZLL_SEQ_CTRL_STS_SEQ_IDLE_MASK           (0x800U)
#define ZLL_SEQ_CTRL_STS_SEQ_IDLE_SHIFT          (11U)
/*! SEQ_IDLE - ZSM Sequence Idle Indicator */
#define ZLL_SEQ_CTRL_STS_SEQ_IDLE(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_SEQ_IDLE_SHIFT)) & ZLL_SEQ_CTRL_STS_SEQ_IDLE_MASK)

#define ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_MASK    (0x1000U)
#define ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_SHIFT   (12U)
/*! NEW_SEQ_INHIBIT - New Sequence Inhibit */
#define ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_SHIFT)) & ZLL_SEQ_CTRL_STS_NEW_SEQ_INHIBIT_MASK)

#define ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_MASK (0x2000U)
#define ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_SHIFT (13U)
/*! RX_TIMEOUT_PENDING - Indicates a TMR3 RX Timeout is Pending */
#define ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_SHIFT)) & ZLL_SEQ_CTRL_STS_RX_TIMEOUT_PENDING_MASK)

#define ZLL_SEQ_CTRL_STS_RX_MODE_MASK            (0x4000U)
#define ZLL_SEQ_CTRL_STS_RX_MODE_SHIFT           (14U)
/*! RX_MODE - RX Operation in Progress */
#define ZLL_SEQ_CTRL_STS_RX_MODE(x)              (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_RX_MODE_SHIFT)) & ZLL_SEQ_CTRL_STS_RX_MODE_MASK)

#define ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_MASK (0x8000U)
#define ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_SHIFT (15U)
/*! TMR2_SEQ_TRIG_ARMED - indicates that TMR2 has been programmed and is armed to trigger a new autosequence */
#define ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_SHIFT)) & ZLL_SEQ_CTRL_STS_TMR2_SEQ_TRIG_ARMED_MASK)

#define ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_MASK       (0x3F0000U)
#define ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_SHIFT      (16U)
/*! SEQ_T_STATUS - Status of the just-completed or ongoing Sequence T or Sequence TR */
#define ZLL_SEQ_CTRL_STS_SEQ_T_STATUS(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_SHIFT)) & ZLL_SEQ_CTRL_STS_SEQ_T_STATUS_MASK)

#define ZLL_SEQ_CTRL_STS_SW_ABORTED_MASK         (0x1000000U)
#define ZLL_SEQ_CTRL_STS_SW_ABORTED_SHIFT        (24U)
/*! SW_ABORTED - Autosequence has terminated due to a Software abort. */
#define ZLL_SEQ_CTRL_STS_SW_ABORTED(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_SW_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_SW_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_TC3_ABORTED_MASK        (0x2000000U)
#define ZLL_SEQ_CTRL_STS_TC3_ABORTED_SHIFT       (25U)
/*! TC3_ABORTED - autosequence has terminated due to an TMR3 timeout */
#define ZLL_SEQ_CTRL_STS_TC3_ABORTED(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_TC3_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_TC3_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_PLL_ABORTED_MASK        (0x4000000U)
#define ZLL_SEQ_CTRL_STS_PLL_ABORTED_SHIFT       (26U)
/*! PLL_ABORTED - Autosequence has terminated due to an PLL unlock event */
#define ZLL_SEQ_CTRL_STS_PLL_ABORTED(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_PLL_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_PLL_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_EXT_ABORTED_MASK        (0x8000000U)
#define ZLL_SEQ_CTRL_STS_EXT_ABORTED_SHIFT       (27U)
/*! EXT_ABORTED - Autosequence has terminated due to a Wake-On-Radio command */
#define ZLL_SEQ_CTRL_STS_EXT_ABORTED(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_EXT_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_EXT_ABORTED_MASK)

#define ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_MASK (0x10000000U)
#define ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_SHIFT (28U)
/*! ARB_GRANT_DEASSERTION_ABORTED - Autosequence has terminated due to an arb_grant deassertion event */
#define ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED(x) (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_SHIFT)) & ZLL_SEQ_CTRL_STS_ARB_GRANT_DEASSERTION_ABORTED_MASK)
/*! @} */

/*! @name ACKDELAY - ACK DELAY */
/*! @{ */

#define ZLL_ACKDELAY_ACKDELAY_MASK               (0x7FU)
#define ZLL_ACKDELAY_ACKDELAY_SHIFT              (0U)
/*! ACKDELAY - ACK Delay */
#define ZLL_ACKDELAY_ACKDELAY(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_ACKDELAY_SHIFT)) & ZLL_ACKDELAY_ACKDELAY_MASK)

#define ZLL_ACKDELAY_TXDELAY_MASK                (0x3F00U)
#define ZLL_ACKDELAY_TXDELAY_SHIFT               (8U)
/*! TXDELAY - TX Delay */
#define ZLL_ACKDELAY_TXDELAY(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_TXDELAY_SHIFT)) & ZLL_ACKDELAY_TXDELAY_MASK)

#define ZLL_ACKDELAY_RXDELAY_MASK                (0x3F0000U)
#define ZLL_ACKDELAY_RXDELAY_SHIFT               (16U)
/*! RXDELAY - RX Delay */
#define ZLL_ACKDELAY_RXDELAY(x)                  (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_RXDELAY_SHIFT)) & ZLL_ACKDELAY_RXDELAY_MASK)

#define ZLL_ACKDELAY_FAST_TX_WD_EN_MASK          (0x1000000U)
#define ZLL_ACKDELAY_FAST_TX_WD_EN_SHIFT         (24U)
/*! FAST_TX_WD_EN - Fast TX_WD enable/disable
 *  0b0..Disable fast Tx warmdown sequence.
 *  0b1..Enable fast Tx warmdown sequence.
 */
#define ZLL_ACKDELAY_FAST_TX_WD_EN(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_FAST_TX_WD_EN_SHIFT)) & ZLL_ACKDELAY_FAST_TX_WD_EN_MASK)

#define ZLL_ACKDELAY_FAST_TX_WD_DELAY_MASK       (0x6000000U)
#define ZLL_ACKDELAY_FAST_TX_WD_DELAY_SHIFT      (25U)
/*! FAST_TX_WD_DELAY - FAST_TX_WD_DELAY */
#define ZLL_ACKDELAY_FAST_TX_WD_DELAY(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_ACKDELAY_FAST_TX_WD_DELAY_SHIFT)) & ZLL_ACKDELAY_FAST_TX_WD_DELAY_MASK)
/*! @} */

/*! @name FILTERFAIL_CODE - FILTER FAIL CODE */
/*! @{ */

#define ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_MASK (0x3FFU)
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_SHIFT (0U)
/*! FILTERFAIL_CODE - Filter Fail Code */
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_SHIFT)) & ZLL_FILTERFAIL_CODE_FILTERFAIL_CODE_MASK)

#define ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_MASK (0x8000U)
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_SHIFT (15U)
/*! FILTERFAIL_PAN_SEL - PAN Selector for Filter Fail Code
 *  0b0..FILTERFAIL_CODE[9:0] will report the FILTERFAIL status of PAN0
 *  0b1..FILTERFAIL_CODE[9:0] will report the FILTERFAIL status of PAN1
 */
#define ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL(x) (((uint32_t)(((uint32_t)(x)) << ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_SHIFT)) & ZLL_FILTERFAIL_CODE_FILTERFAIL_PAN_SEL_MASK)
/*! @} */

/*! @name RX_WTR_MARK - RECEIVE WATER MARK */
/*! @{ */

#define ZLL_RX_WTR_MARK_RX_WTR_MARK_MASK         (0xFFU)
#define ZLL_RX_WTR_MARK_RX_WTR_MARK_SHIFT        (0U)
/*! RX_WTR_MARK - RECEIVE WATER MARK */
#define ZLL_RX_WTR_MARK_RX_WTR_MARK(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_RX_WTR_MARK_RX_WTR_MARK_SHIFT)) & ZLL_RX_WTR_MARK_RX_WTR_MARK_MASK)
/*! @} */

/*! @name SLOT_PRELOAD - SLOT PRELOAD */
/*! @{ */

#define ZLL_SLOT_PRELOAD_SLOT_PRELOAD_MASK       (0xFFU)
#define ZLL_SLOT_PRELOAD_SLOT_PRELOAD_SHIFT      (0U)
/*! SLOT_PRELOAD - Slotted Mode Preload */
#define ZLL_SLOT_PRELOAD_SLOT_PRELOAD(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_SLOT_PRELOAD_SLOT_PRELOAD_SHIFT)) & ZLL_SLOT_PRELOAD_SLOT_PRELOAD_MASK)
/*! @} */

/*! @name SEQ_STATE - 802.15.4 SEQUENCE STATE */
/*! @{ */

#define ZLL_SEQ_STATE_SEQ_STATE_MASK             (0x1FU)
#define ZLL_SEQ_STATE_SEQ_STATE_SHIFT            (0U)
/*! SEQ_STATE - ZSM Sequence State */
#define ZLL_SEQ_STATE_SEQ_STATE(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_SEQ_STATE_SHIFT)) & ZLL_SEQ_STATE_SEQ_STATE_MASK)

#define ZLL_SEQ_STATE_PREAMBLE_DET_MASK          (0x100U)
#define ZLL_SEQ_STATE_PREAMBLE_DET_SHIFT         (8U)
/*! PREAMBLE_DET - Preamble Detected */
#define ZLL_SEQ_STATE_PREAMBLE_DET(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_PREAMBLE_DET_SHIFT)) & ZLL_SEQ_STATE_PREAMBLE_DET_MASK)

#define ZLL_SEQ_STATE_SFD_DET_MASK               (0x200U)
#define ZLL_SEQ_STATE_SFD_DET_SHIFT              (9U)
/*! SFD_DET - SFD Detected */
#define ZLL_SEQ_STATE_SFD_DET(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_SFD_DET_SHIFT)) & ZLL_SEQ_STATE_SFD_DET_MASK)

#define ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_MASK   (0x400U)
#define ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_SHIFT  (10U)
/*! FILTERFAIL_FLAG_SEL - Consolidated Filter Fail Flag */
#define ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_SHIFT)) & ZLL_SEQ_STATE_FILTERFAIL_FLAG_SEL_MASK)

#define ZLL_SEQ_STATE_CRCVALID_MASK              (0x800U)
#define ZLL_SEQ_STATE_CRCVALID_SHIFT             (11U)
/*! CRCVALID - CRC Valid Indicator
 *  0b0..Rx FCS != calculated CRC (incorrect)
 *  0b1..Rx FCS = calculated CRC (correct)
 */
#define ZLL_SEQ_STATE_CRCVALID(x)                (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_CRCVALID_SHIFT)) & ZLL_SEQ_STATE_CRCVALID_MASK)

#define ZLL_SEQ_STATE_PLL_ABORT_MASK             (0x1000U)
#define ZLL_SEQ_STATE_PLL_ABORT_SHIFT            (12U)
/*! PLL_ABORT - Raw PLL Abort Signal */
#define ZLL_SEQ_STATE_PLL_ABORT(x)               (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_PLL_ABORT_SHIFT)) & ZLL_SEQ_STATE_PLL_ABORT_MASK)

#define ZLL_SEQ_STATE_PLL_ABORTED_MASK           (0x2000U)
#define ZLL_SEQ_STATE_PLL_ABORTED_SHIFT          (13U)
/*! PLL_ABORTED - Autosequence has terminated due to an PLL unlock event */
#define ZLL_SEQ_STATE_PLL_ABORTED(x)             (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_PLL_ABORTED_SHIFT)) & ZLL_SEQ_STATE_PLL_ABORTED_MASK)

#define ZLL_SEQ_STATE_RX_BYTE_COUNT_MASK         (0xFF0000U)
#define ZLL_SEQ_STATE_RX_BYTE_COUNT_SHIFT        (16U)
/*! RX_BYTE_COUNT - Realtime Received Byte Count */
#define ZLL_SEQ_STATE_RX_BYTE_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_RX_BYTE_COUNT_SHIFT)) & ZLL_SEQ_STATE_RX_BYTE_COUNT_MASK)

#define ZLL_SEQ_STATE_CCCA_BUSY_CNT_MASK         (0x3F000000U)
#define ZLL_SEQ_STATE_CCCA_BUSY_CNT_SHIFT        (24U)
/*! CCCA_BUSY_CNT - Number of CCA Measurements resulting in Busy Channel */
#define ZLL_SEQ_STATE_CCCA_BUSY_CNT(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_SEQ_STATE_CCCA_BUSY_CNT_SHIFT)) & ZLL_SEQ_STATE_CCCA_BUSY_CNT_MASK)
/*! @} */

/*! @name TMR_PRESCALE - TIMER PRESCALER */
/*! @{ */

#define ZLL_TMR_PRESCALE_TMR_PRESCALE_MASK       (0x7U)
#define ZLL_TMR_PRESCALE_TMR_PRESCALE_SHIFT      (0U)
/*! TMR_PRESCALE - Timer Prescaler
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b010..500kHz (33.55 S)
 *  0b011..250kHz (67.11 S)
 *  0b100..125kHz (134.22 S)
 *  0b101..62.5kHz (268.44 S) -- default
 *  0b110..31.25kHz (536.87 S)
 *  0b111..15.625kHz (1073.74 S)
 */
#define ZLL_TMR_PRESCALE_TMR_PRESCALE(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_TMR_PRESCALE_TMR_PRESCALE_SHIFT)) & ZLL_TMR_PRESCALE_TMR_PRESCALE_MASK)
/*! @} */

/*! @name LENIENCY_LSB - LENIENCY LSB */
/*! @{ */

#define ZLL_LENIENCY_LSB_LENIENCY_LSB_MASK       (0xFFFFFFFFU)
#define ZLL_LENIENCY_LSB_LENIENCY_LSB_SHIFT      (0U)
/*! LENIENCY_LSB - Leniency LSB Register */
#define ZLL_LENIENCY_LSB_LENIENCY_LSB(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_LENIENCY_LSB_LENIENCY_LSB_SHIFT)) & ZLL_LENIENCY_LSB_LENIENCY_LSB_MASK)
/*! @} */

/*! @name LENIENCY_MSB - LENIENCY MSB */
/*! @{ */

#define ZLL_LENIENCY_MSB_LENIENCY_MSB_MASK       (0x7FFU)
#define ZLL_LENIENCY_MSB_LENIENCY_MSB_SHIFT      (0U)
/*! LENIENCY_MSB - Leniency MSB Register */
#define ZLL_LENIENCY_MSB_LENIENCY_MSB(x)         (((uint32_t)(((uint32_t)(x)) << ZLL_LENIENCY_MSB_LENIENCY_MSB_SHIFT)) & ZLL_LENIENCY_MSB_LENIENCY_MSB_MASK)
/*! @} */

/*! @name PART_ID - PART ID */
/*! @{ */

#define ZLL_PART_ID_PART_ID_MASK                 (0xFFU)
#define ZLL_PART_ID_PART_ID_SHIFT                (0U)
/*! PART_ID - 802.15.4 Part ID */
#define ZLL_PART_ID_PART_ID(x)                   (((uint32_t)(((uint32_t)(x)) << ZLL_PART_ID_PART_ID_SHIFT)) & ZLL_PART_ID_PART_ID_MASK)
/*! @} */

/*! @name COEX_CTRL - COEXISTENCE CONTROL */
/*! @{ */

#define ZLL_COEX_CTRL_COEX_EN_MASK               (0x1U)
#define ZLL_COEX_CTRL_COEX_EN_SHIFT              (0U)
/*! COEX_EN - Coexistence Enable
 *  0b0..Coexistence function is disabled.
 *  0b1..Coexistence function is enabled.
 */
#define ZLL_COEX_CTRL_COEX_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_EN_SHIFT)) & ZLL_COEX_CTRL_COEX_EN_MASK)

#define ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_MASK     (0x2U)
#define ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_SHIFT    (1U)
/*! COEX_REQ_DELAY_EN - Coexistence Request Delay Enable
 *  0b0..arb_request is not delayed during R sequence.
 *  0b1..arb_request is delayed until preamble is detected during R sequence.
 */
#define ZLL_COEX_CTRL_COEX_REQ_DELAY_EN(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_SHIFT)) & ZLL_COEX_CTRL_COEX_REQ_DELAY_EN_MASK)

#define ZLL_COEX_CTRL_COEX_REQ_ON_PD_MASK        (0x4U)
#define ZLL_COEX_CTRL_COEX_REQ_ON_PD_SHIFT       (2U)
/*! COEX_REQ_ON_PD - Coexistence Request on Preamble detected
 *  0b0..arb_request is delayed until SFD is detected during R sequence.
 *  0b1..arb_request is delayed until preamble is detected during R sequence.
 */
#define ZLL_COEX_CTRL_COEX_REQ_ON_PD(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_REQ_ON_PD_SHIFT)) & ZLL_COEX_CTRL_COEX_REQ_ON_PD_MASK)

#define ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_MASK      (0x40U)
#define ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_SHIFT     (6U)
/*! COEX_TIMEOUT_MSK - Coexistence Timeout Interrupt Mask bit
 *  0b0..allows interrupt when coexistence timeout
 *  0b1..Interrupt generation is disabled, but a COEX_TIMEOUT_IRQ flag can be set
 */
#define ZLL_COEX_CTRL_COEX_TIMEOUT_MSK(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_SHIFT)) & ZLL_COEX_CTRL_COEX_TIMEOUT_MSK_MASK)

#define ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_MASK      (0x80U)
#define ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_SHIFT     (7U)
/*! COEX_TIMEOUT_IRQ - Coexistence Timeout Interrupt */
#define ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_SHIFT)) & ZLL_COEX_CTRL_COEX_TIMEOUT_IRQ_MASK)

#define ZLL_COEX_CTRL_COEX_TIMEOUT_MASK          (0xFF00U)
#define ZLL_COEX_CTRL_COEX_TIMEOUT_SHIFT         (8U)
/*! COEX_TIMEOUT - Coexistence timeout value */
#define ZLL_COEX_CTRL_COEX_TIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_CTRL_COEX_TIMEOUT_SHIFT)) & ZLL_COEX_CTRL_COEX_TIMEOUT_MASK)
/*! @} */

/*! @name COEX_PRIORITY - COEXISTENCE PRIORITY */
/*! @{ */

#define ZLL_COEX_PRIORITY_PRIORITY_T_MASK        (0x3U)
#define ZLL_COEX_PRIORITY_PRIORITY_T_SHIFT       (0U)
/*! PRIORITY_T - PRIORITY_T */
#define ZLL_COEX_PRIORITY_PRIORITY_T(x)          (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_T_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_T_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_R_PRE_MASK    (0xCU)
#define ZLL_COEX_PRIORITY_PRIORITY_R_PRE_SHIFT   (2U)
/*! PRIORITY_R_PRE - PRIORITY_R_PRE */
#define ZLL_COEX_PRIORITY_PRIORITY_R_PRE(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_R_PRE_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_R_PRE_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_R_PKT_MASK    (0x30U)
#define ZLL_COEX_PRIORITY_PRIORITY_R_PKT_SHIFT   (4U)
/*! PRIORITY_R_PKT - PRIORITY_R_PKT */
#define ZLL_COEX_PRIORITY_PRIORITY_R_PKT(x)      (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_R_PKT_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_R_PKT_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_TACK_MASK     (0xC0U)
#define ZLL_COEX_PRIORITY_PRIORITY_TACK_SHIFT    (6U)
/*! PRIORITY_TACK - PRIORITY_TACK */
#define ZLL_COEX_PRIORITY_PRIORITY_TACK(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_TACK_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_TACK_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_CCA_MASK      (0x300U)
#define ZLL_COEX_PRIORITY_PRIORITY_CCA_SHIFT     (8U)
/*! PRIORITY_CCA - PRIORITY_CCA */
#define ZLL_COEX_PRIORITY_PRIORITY_CCA(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_CCA_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_CCA_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_CCCA_MASK     (0xC00U)
#define ZLL_COEX_PRIORITY_PRIORITY_CCCA_SHIFT    (10U)
/*! PRIORITY_CCCA - PRIORITY_CCCA */
#define ZLL_COEX_PRIORITY_PRIORITY_CCCA(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_CCCA_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_CCCA_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_CTX_MASK      (0x3000U)
#define ZLL_COEX_PRIORITY_PRIORITY_CTX_SHIFT     (12U)
/*! PRIORITY_CTX - PRIORITY_CT */
#define ZLL_COEX_PRIORITY_PRIORITY_CTX(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_CTX_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_CTX_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_MASK (0xC000U)
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_SHIFT (14U)
/*! PRIORITY_RACK_PRE - PRIORITY_RACK_PRE */
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_RACK_PRE_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_MASK (0x30000U)
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_SHIFT (16U)
/*! PRIORITY_RACK_PKT - PRIORITY_RACK_PKT */
#define ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT(x)   (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_RACK_PKT_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_MASK     (0x60000000U)
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_SHIFT    (29U)
/*! PRIORITY_OVRD - PRIORITY_OVRD */
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_OVRD_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_OVRD_MASK)

#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_MASK  (0x80000000U)
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_SHIFT (31U)
/*! PRIORITY_OVRD_EN - PRIORITY_OVRD_EN
 *  0b0..Disable overriding PRIORITY value.
 *  0b1..Enable overriding PRIORITY value.
 */
#define ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_SHIFT)) & ZLL_COEX_PRIORITY_PRIORITY_OVRD_EN_MASK)
/*! @} */

/*! @name ENHACK_CTRL0 - ENHACK_CTRL 0 */
/*! @{ */

#define ZLL_ENHACK_CTRL0_ENHACK_EN_MASK          (0x1U)
#define ZLL_ENHACK_CTRL0_ENHACK_EN_SHIFT         (0U)
/*! ENHACK_EN - Enhanced Acknowledgment Enable
 *  0b0..Enhanced acknowledgment is disabled.
 *  0b1..Enhanced acknowledgment is enabled.
 */
#define ZLL_ENHACK_CTRL0_ENHACK_EN(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_ENHACK_EN_SHIFT)) & ZLL_ENHACK_CTRL0_ENHACK_EN_MASK)

#define ZLL_ENHACK_CTRL0_SW_LEN_RDY_MASK         (0x2U)
#define ZLL_ENHACK_CTRL0_SW_LEN_RDY_SHIFT        (1U)
/*! SW_LEN_RDY - Software enhanced acknowledgment frame Length field ready
 *  0b0..Software enhanced acknowledgment frame Length field is not ready.
 *  0b1..Software enhanced acknowledgment frame Length field is ready in RAM
 */
#define ZLL_ENHACK_CTRL0_SW_LEN_RDY(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_SW_LEN_RDY_SHIFT)) & ZLL_ENHACK_CTRL0_SW_LEN_RDY_MASK)

#define ZLL_ENHACK_CTRL0_SW_HIE_RDY_MASK         (0x4U)
#define ZLL_ENHACK_CTRL0_SW_HIE_RDY_SHIFT        (2U)
/*! SW_HIE_RDY - Software enhanced acknowledgment frame HIE field ready
 *  0b0..Software enhanced acknowledgment frame HIE field is not ready.
 *  0b1..Software enhanced acknowledgment frame HIE field is ready in RAM
 */
#define ZLL_ENHACK_CTRL0_SW_HIE_RDY(x)           (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_SW_HIE_RDY_SHIFT)) & ZLL_ENHACK_CTRL0_SW_HIE_RDY_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_MASK (0x10U)
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_SHIFT (4U)
/*! EMPTY_SECURITY_ENABLED_OVRD - Override value of Security Enabled field in Empty Enhanced Acknowledgment */
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD(x) (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_MASK (0x60U)
#define ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_SHIFT (5U)
/*! EMPTY_SRC_ADDR_MODE - Source Address Mode field in Empty Enhanced Acknowledgment */
#define ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE(x)  (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_SRC_ADDR_MODE_MASK)

#define ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_MASK      (0xFF00U)
#define ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_SHIFT     (8U)
/*! SW_MHR_LENGTH - Software calculated MHR(excludes the HIE field) Length in bytes. */
#define ZLL_ENHACK_CTRL0_SW_MHR_LENGTH(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_SHIFT)) & ZLL_ENHACK_CTRL0_SW_MHR_LENGTH_MASK)

#define ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_MASK   (0x10000U)
#define ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_SHIFT  (16U)
/*! HW_FRAME_PENDING - Hardware calculated Frame Pending field */
#define ZLL_ENHACK_CTRL0_HW_FRAME_PENDING(x)     (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_SHIFT)) & ZLL_ENHACK_CTRL0_HW_FRAME_PENDING_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_MASK (0x40000U)
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_SHIFT (18U)
/*! EMPTY_SECURITY_ENABLED_OVRD_EN - Override enable of Security Enabled field in Empty Enhanced Acknowledgment
 *  0b0..Security Enabled field in Empty Enhanced Acknowledgment frame is 0.
 *  0b1..Security Enabled field in Empty Enhanced Acknowledgment frame is from EMPTY_SECURITY_ENABLED_OVRD.
 */
#define ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_SECURITY_ENABLED_OVRD_EN_MASK)

#define ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_MASK      (0x4000000U)
#define ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_SHIFT     (26U)
/*! ACK_ABORT_MSK - Enhanced Acknowledgment Abort IRQ Mask bit
 *  0b0..allows interrupt when HIE field is not ready by software.
 *  0b1..Interrupt generation is disabled, but a ACK_ABORT_IRQ flag can be set
 */
#define ZLL_ENHACK_CTRL0_ACK_ABORT_MSK(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_SHIFT)) & ZLL_ENHACK_CTRL0_ACK_ABORT_MSK_MASK)

#define ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_MASK      (0x8000000U)
#define ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_SHIFT     (27U)
/*! ACK_ABORT_IRQ - Enhanced Acknowledgment Abort IRQ */
#define ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_SHIFT)) & ZLL_ENHACK_CTRL0_ACK_ABORT_IRQ_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_MASK      (0x10000000U)
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_SHIFT     (28U)
/*! EMPTY_ACK_MSK - Empty Enhanced Acknowledgment IRQ Mask bit
 *  0b0..allows interrupt when Empty Enhanced Acknowledgment
 *  0b1..Interrupt generation is disabled, but a EMPTY_ACK_IRQ flag can be set
 */
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_ACK_MSK_MASK)

#define ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_MASK      (0x20000000U)
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_SHIFT     (29U)
/*! EMPTY_ACK_IRQ - Empty Enhanced Acknowledgment IRQ */
#define ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_SHIFT)) & ZLL_ENHACK_CTRL0_EMPTY_ACK_IRQ_MASK)

#define ZLL_ENHACK_CTRL0_RECYC_MSK_MASK          (0x40000000U)
#define ZLL_ENHACK_CTRL0_RECYC_MSK_SHIFT         (30U)
/*! RECYC_MSK - Recycle IRQ Mask bit
 *  0b0..allows interrupt when recycle
 *  0b1..Interrupt generation is disabled, but a RECYC_IRQ flag can be set
 */
#define ZLL_ENHACK_CTRL0_RECYC_MSK(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_RECYC_MSK_SHIFT)) & ZLL_ENHACK_CTRL0_RECYC_MSK_MASK)

#define ZLL_ENHACK_CTRL0_RECYC_IRQ_MASK          (0x80000000U)
#define ZLL_ENHACK_CTRL0_RECYC_IRQ_SHIFT         (31U)
/*! RECYC_IRQ - Recycle IRQ */
#define ZLL_ENHACK_CTRL0_RECYC_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << ZLL_ENHACK_CTRL0_RECYC_IRQ_SHIFT)) & ZLL_ENHACK_CTRL0_RECYC_IRQ_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ZLL_Register_Masks */


/*!
 * @}
 */ /* end of group ZLL_Peripheral_Access_Layer */


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


#endif  /* PERI_ZLL_H_ */

