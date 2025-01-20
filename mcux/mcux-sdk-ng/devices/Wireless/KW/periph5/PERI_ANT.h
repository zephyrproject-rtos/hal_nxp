/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ANT.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for ANT
 *
 * CMSIS Peripheral Access Layer for ANT
 */

#if !defined(ANT_H_)
#define ANT_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- ANT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANT_Peripheral_Access_Layer ANT Peripheral Access Layer
 * @{
 */

/** ANT - Size of Registers Arrays */
#define ANT_PACKET_BUFFER_COUNT                   64u

/** ANT - Register Layout Typedef */
typedef struct {
  __IO uint32_t IRQ_CTRL;                          /**< IRQ CONTROL, offset: 0x0 */
  __IO uint32_t EVENT_TMR;                         /**< EVENT TIMER, offset: 0x4 */
  __IO uint32_t T1_CMP;                            /**< T1 COMPARE, offset: 0x8 */
  __IO uint32_t T2_CMP;                            /**< T2 COMPARE, offset: 0xC */
  __I  uint32_t TIMESTAMP;                         /**< TIMESTAMP, offset: 0x10 */
  __IO uint32_t XCVR_CTRL;                         /**< TRANSCEIVER CONTROL, offset: 0x14 */
  __I  uint32_t XCVR_STS;                          /**< TRANSCEIVER STATUS, offset: 0x18 */
  __IO uint32_t XCVR_CFG;                          /**< TRANSCEIVER CONFIGURATION, offset: 0x1C */
  __IO uint32_t CHANNEL_NUM;                       /**< CHANNEL NUMBER, offset: 0x20 */
  __IO uint32_t TX_POWER;                          /**< TRANSMIT POWER, offset: 0x24 */
  __IO uint32_t NTW_ADR_CTRL;                      /**< NETWORK ADDRESS CONTROL, offset: 0x28 */
  __IO uint32_t NTW_ADR_0;                         /**< NETWORK ADDRESS 0, offset: 0x2C */
  __IO uint32_t NTW_ADR_1;                         /**< NETWORK ADDRESS 1, offset: 0x30 */
  __IO uint32_t NTW_ADR_2;                         /**< NETWORK ADDRESS 2, offset: 0x34 */
  __IO uint32_t NTW_ADR_3;                         /**< NETWORK ADDRESS 3, offset: 0x38 */
  __IO uint32_t RX_WATERMARK;                      /**< RX WATERMARK, offset: 0x3C */
  __O  uint32_t DSM_CTRL;                          /**< DSM CONTROL, offset: 0x40 */
  __I  uint32_t PART_ID;                           /**< PART ID, offset: 0x44 */
       uint8_t RESERVED_0[184];
  __IO uint16_t PACKET_BUFFER[ANT_PACKET_BUFFER_COUNT]; /**< PACKET BUFFER, array offset: 0x100, array step: 0x2 */
} ANT_Type;

/* ----------------------------------------------------------------------------
   -- ANT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANT_Register_Masks ANT Register Masks
 * @{
 */

/*! @name IRQ_CTRL - IRQ CONTROL */
/*! @{ */

#define ANT_IRQ_CTRL_SEQ_END_IRQ_MASK            (0x1U)
#define ANT_IRQ_CTRL_SEQ_END_IRQ_SHIFT           (0U)
/*! SEQ_END_IRQ - Sequence End Interrupt
 *  0b0..Sequence End Interrupt is not asserted.
 *  0b1..Sequence End Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_SEQ_END_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_SEQ_END_IRQ_SHIFT)) & ANT_IRQ_CTRL_SEQ_END_IRQ_MASK)

#define ANT_IRQ_CTRL_TX_IRQ_MASK                 (0x2U)
#define ANT_IRQ_CTRL_TX_IRQ_SHIFT                (1U)
/*! TX_IRQ - TX Interrupt
 *  0b0..TX Interrupt is not asserted.
 *  0b1..TX Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_TX_IRQ(x)                   (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_TX_IRQ_SHIFT)) & ANT_IRQ_CTRL_TX_IRQ_MASK)

#define ANT_IRQ_CTRL_RX_IRQ_MASK                 (0x4U)
#define ANT_IRQ_CTRL_RX_IRQ_SHIFT                (2U)
/*! RX_IRQ - RX Interrupt
 *  0b0..RX Interrupt is not asserted.
 *  0b1..RX Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_RX_IRQ(x)                   (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_RX_IRQ_SHIFT)) & ANT_IRQ_CTRL_RX_IRQ_MASK)

#define ANT_IRQ_CTRL_NTW_ADR_IRQ_MASK            (0x8U)
#define ANT_IRQ_CTRL_NTW_ADR_IRQ_SHIFT           (3U)
/*! NTW_ADR_IRQ - Network Address Match Interrupt
 *  0b0..Network Address Match Interrupt is not asserted.
 *  0b1..Network Address Match Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_NTW_ADR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_NTW_ADR_IRQ_SHIFT)) & ANT_IRQ_CTRL_NTW_ADR_IRQ_MASK)

#define ANT_IRQ_CTRL_T1_IRQ_MASK                 (0x10U)
#define ANT_IRQ_CTRL_T1_IRQ_SHIFT                (4U)
/*! T1_IRQ - Timer1 (T1) Compare Interrupt
 *  0b0..Timer1 (T1) Compare Interrupt is not asserted.
 *  0b1..Timer1 (T1) Compare Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_T1_IRQ(x)                   (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_T1_IRQ_SHIFT)) & ANT_IRQ_CTRL_T1_IRQ_MASK)

#define ANT_IRQ_CTRL_T2_IRQ_MASK                 (0x20U)
#define ANT_IRQ_CTRL_T2_IRQ_SHIFT                (5U)
/*! T2_IRQ - Timer2 (T2) Compare Interrupt
 *  0b0..Timer2 (T2) Compare Interrupt is not asserted.
 *  0b1..Timer2 (T2) Compare Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_T2_IRQ(x)                   (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_T2_IRQ_SHIFT)) & ANT_IRQ_CTRL_T2_IRQ_MASK)

#define ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_MASK         (0x40U)
#define ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_SHIFT        (6U)
/*! PLL_UNLOCK_IRQ - PLL Unlock Interrupt
 *  0b0..PLL Unlock Interrupt is not asserted.
 *  0b1..PLL Unlock Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_PLL_UNLOCK_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_SHIFT)) & ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_MASK)

#define ANT_IRQ_CTRL_WAKE_IRQ_MASK               (0x80U)
#define ANT_IRQ_CTRL_WAKE_IRQ_SHIFT              (7U)
/*! WAKE_IRQ - Wake Interrrupt
 *  0b0..Wake Interrupt is not asserted.
 *  0b1..Wake Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_WAKE_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_WAKE_IRQ_SHIFT)) & ANT_IRQ_CTRL_WAKE_IRQ_MASK)

#define ANT_IRQ_CTRL_RX_WATERMARK_IRQ_MASK       (0x100U)
#define ANT_IRQ_CTRL_RX_WATERMARK_IRQ_SHIFT      (8U)
/*! RX_WATERMARK_IRQ - RX Watermark Interrupt
 *  0b0..RX Watermark Interrupt is not asserted.
 *  0b1..RX Watermark Interrupt is asserted.
 */
#define ANT_IRQ_CTRL_RX_WATERMARK_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_RX_WATERMARK_IRQ_SHIFT)) & ANT_IRQ_CTRL_RX_WATERMARK_IRQ_MASK)

#define ANT_IRQ_CTRL_TSM_IRQ_MASK                (0x200U)
#define ANT_IRQ_CTRL_TSM_IRQ_SHIFT               (9U)
/*! TSM_IRQ - TSM Interrupt
 *  0b0..TSM0_IRQ and TSM1_IRQ are both clear.
 *  0b1..Indicates TSM0_IRQ or TSM1_IRQ is set in XCVR_STATUS.
 */
#define ANT_IRQ_CTRL_TSM_IRQ(x)                  (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_TSM_IRQ_SHIFT)) & ANT_IRQ_CTRL_TSM_IRQ_MASK)

#define ANT_IRQ_CTRL_SEQ_END_IRQ_EN_MASK         (0x10000U)
#define ANT_IRQ_CTRL_SEQ_END_IRQ_EN_SHIFT        (16U)
/*! SEQ_END_IRQ_EN - SEQ_END_IRQ Enable
 *  0b0..Sequence End Interrupt is not enabled.
 *  0b1..Sequence End Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_SEQ_END_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_SEQ_END_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_SEQ_END_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_TX_IRQ_EN_MASK              (0x20000U)
#define ANT_IRQ_CTRL_TX_IRQ_EN_SHIFT             (17U)
/*! TX_IRQ_EN - TX_IRQ Enable
 *  0b0..TX Interrupt is not enabled.
 *  0b1..TX Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_TX_IRQ_EN(x)                (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_TX_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_TX_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_RX_IRQ_EN_MASK              (0x40000U)
#define ANT_IRQ_CTRL_RX_IRQ_EN_SHIFT             (18U)
/*! RX_IRQ_EN - RX_IRQ Enable
 *  0b0..RX Interrupt is not enabled.
 *  0b1..RX Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_RX_IRQ_EN(x)                (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_RX_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_RX_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_NTW_ADR_IRQ_EN_MASK         (0x80000U)
#define ANT_IRQ_CTRL_NTW_ADR_IRQ_EN_SHIFT        (19U)
/*! NTW_ADR_IRQ_EN - NTW_ADR_IRQ Enable
 *  0b0..Network Address Match Interrupt is not enabled.
 *  0b1..Network Address Match Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_NTW_ADR_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_NTW_ADR_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_NTW_ADR_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_T1_IRQ_EN_MASK              (0x100000U)
#define ANT_IRQ_CTRL_T1_IRQ_EN_SHIFT             (20U)
/*! T1_IRQ_EN - T1_IRQ Enable
 *  0b0..Timer1 (T1) Compare Interrupt is not enabled.
 *  0b1..Timer1 (T1) Compare Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_T1_IRQ_EN(x)                (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_T1_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_T1_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_T2_IRQ_EN_MASK              (0x200000U)
#define ANT_IRQ_CTRL_T2_IRQ_EN_SHIFT             (21U)
/*! T2_IRQ_EN - T2_IRQ Enable
 *  0b0..Timer1 (T2) Compare Interrupt is not enabled.
 *  0b1..Timer1 (T2) Compare Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_T2_IRQ_EN(x)                (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_T2_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_T2_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_MASK      (0x400000U)
#define ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT     (22U)
/*! PLL_UNLOCK_IRQ_EN - PLL_UNLOCK_IRQ Enable
 *  0b0..PLL Unlock Interrupt is not enabled.
 *  0b1..PLL Unlock Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_WAKE_IRQ_EN_MASK            (0x800000U)
#define ANT_IRQ_CTRL_WAKE_IRQ_EN_SHIFT           (23U)
/*! WAKE_IRQ_EN - WAKE_IRQ Enable
 *  0b0..Wake Interrupt is not enabled.
 *  0b1..Wake Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_WAKE_IRQ_EN(x)              (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_WAKE_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_WAKE_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_RX_WATERMARK_IRQ_EN_MASK    (0x1000000U)
#define ANT_IRQ_CTRL_RX_WATERMARK_IRQ_EN_SHIFT   (24U)
/*! RX_WATERMARK_IRQ_EN - RX_WATERMARK_IRQ Enable
 *  0b0..RX Watermark Interrupt is not enabled.
 *  0b1..RX Watermark Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_RX_WATERMARK_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_RX_WATERMARK_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_RX_WATERMARK_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_TSM_IRQ_EN_MASK             (0x2000000U)
#define ANT_IRQ_CTRL_TSM_IRQ_EN_SHIFT            (25U)
/*! TSM_IRQ_EN - TSM_IRQ Enable
 *  0b0..TSM Interrupt is not enabled.
 *  0b1..TSM Interrupt is enabled.
 */
#define ANT_IRQ_CTRL_TSM_IRQ_EN(x)               (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_TSM_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_TSM_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_ANT_IRQ_EN_MASK             (0x4000000U)
#define ANT_IRQ_CTRL_ANT_IRQ_EN_SHIFT            (26U)
/*! ANT_IRQ_EN - ANT_IRQ Master Enable
 *  0b0..All ANT Interrupts are disabled.
 *  0b1..All ANT Interrupts can be enabled.
 */
#define ANT_IRQ_CTRL_ANT_IRQ_EN(x)               (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_ANT_IRQ_EN_SHIFT)) & ANT_IRQ_CTRL_ANT_IRQ_EN_MASK)

#define ANT_IRQ_CTRL_CRC_IGNORE_MASK             (0x8000000U)
#define ANT_IRQ_CTRL_CRC_IGNORE_SHIFT            (27U)
/*! CRC_IGNORE - CRC Ignore
 *  0b0..RX_IRQ will not be asserted for a received packet which fails CRC verification.
 *  0b1..RX_IRQ will be asserted even for a received packet which fails CRC verification.
 */
#define ANT_IRQ_CTRL_CRC_IGNORE(x)               (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_CRC_IGNORE_SHIFT)) & ANT_IRQ_CTRL_CRC_IGNORE_MASK)

#define ANT_IRQ_CTRL_CRC_VALID_MASK              (0x80000000U)
#define ANT_IRQ_CTRL_CRC_VALID_SHIFT             (31U)
/*! CRC_VALID - CRC Valid
 *  0b0..CRC of RX packet is not valid.
 *  0b1..CRC of RX packet is valid.
 */
#define ANT_IRQ_CTRL_CRC_VALID(x)                (((uint32_t)(((uint32_t)(x)) << ANT_IRQ_CTRL_CRC_VALID_SHIFT)) & ANT_IRQ_CTRL_CRC_VALID_MASK)
/*! @} */

/*! @name EVENT_TMR - EVENT TIMER */
/*! @{ */

#define ANT_EVENT_TMR_EVENT_TMR_MASK             (0xFFFFFFU)
#define ANT_EVENT_TMR_EVENT_TMR_SHIFT            (0U)
/*! EVENT_TMR - Event Timer */
#define ANT_EVENT_TMR_EVENT_TMR(x)               (((uint32_t)(((uint32_t)(x)) << ANT_EVENT_TMR_EVENT_TMR_SHIFT)) & ANT_EVENT_TMR_EVENT_TMR_MASK)

#define ANT_EVENT_TMR_EVENT_TMR_LD_MASK          (0x1000000U)
#define ANT_EVENT_TMR_EVENT_TMR_LD_SHIFT         (24U)
/*! EVENT_TMR_LD - Event Timer Load */
#define ANT_EVENT_TMR_EVENT_TMR_LD(x)            (((uint32_t)(((uint32_t)(x)) << ANT_EVENT_TMR_EVENT_TMR_LD_SHIFT)) & ANT_EVENT_TMR_EVENT_TMR_LD_MASK)

#define ANT_EVENT_TMR_EVENT_TMR_ADD_MASK         (0x2000000U)
#define ANT_EVENT_TMR_EVENT_TMR_ADD_SHIFT        (25U)
/*! EVENT_TMR_ADD - Event Timer Add */
#define ANT_EVENT_TMR_EVENT_TMR_ADD(x)           (((uint32_t)(((uint32_t)(x)) << ANT_EVENT_TMR_EVENT_TMR_ADD_SHIFT)) & ANT_EVENT_TMR_EVENT_TMR_ADD_MASK)
/*! @} */

/*! @name T1_CMP - T1 COMPARE */
/*! @{ */

#define ANT_T1_CMP_T1_CMP_MASK                   (0xFFFFFFU)
#define ANT_T1_CMP_T1_CMP_SHIFT                  (0U)
/*! T1_CMP - Timer1 (T1) Compare Value */
#define ANT_T1_CMP_T1_CMP(x)                     (((uint32_t)(((uint32_t)(x)) << ANT_T1_CMP_T1_CMP_SHIFT)) & ANT_T1_CMP_T1_CMP_MASK)

#define ANT_T1_CMP_T1_CMP_EN_MASK                (0x1000000U)
#define ANT_T1_CMP_T1_CMP_EN_SHIFT               (24U)
/*! T1_CMP_EN - Timer1 (T1) Compare Enable */
#define ANT_T1_CMP_T1_CMP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ANT_T1_CMP_T1_CMP_EN_SHIFT)) & ANT_T1_CMP_T1_CMP_EN_MASK)
/*! @} */

/*! @name T2_CMP - T2 COMPARE */
/*! @{ */

#define ANT_T2_CMP_T2_CMP_MASK                   (0xFFFFFFU)
#define ANT_T2_CMP_T2_CMP_SHIFT                  (0U)
/*! T2_CMP - Timer2 (T2) Compare Value */
#define ANT_T2_CMP_T2_CMP(x)                     (((uint32_t)(((uint32_t)(x)) << ANT_T2_CMP_T2_CMP_SHIFT)) & ANT_T2_CMP_T2_CMP_MASK)

#define ANT_T2_CMP_T2_CMP_EN_MASK                (0x1000000U)
#define ANT_T2_CMP_T2_CMP_EN_SHIFT               (24U)
/*! T2_CMP_EN - Timer2 (T2) Compare Enable */
#define ANT_T2_CMP_T2_CMP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ANT_T2_CMP_T2_CMP_EN_SHIFT)) & ANT_T2_CMP_T2_CMP_EN_MASK)
/*! @} */

/*! @name TIMESTAMP - TIMESTAMP */
/*! @{ */

#define ANT_TIMESTAMP_TIMESTAMP_MASK             (0xFFFFFFU)
#define ANT_TIMESTAMP_TIMESTAMP_SHIFT            (0U)
/*! TIMESTAMP - Received Packet Timestamp */
#define ANT_TIMESTAMP_TIMESTAMP(x)               (((uint32_t)(((uint32_t)(x)) << ANT_TIMESTAMP_TIMESTAMP_SHIFT)) & ANT_TIMESTAMP_TIMESTAMP_MASK)
/*! @} */

/*! @name XCVR_CTRL - TRANSCEIVER CONTROL */
/*! @{ */

#define ANT_XCVR_CTRL_SEQCMD_MASK                (0xFU)
#define ANT_XCVR_CTRL_SEQCMD_SHIFT               (0U)
/*! SEQCMD - Sequence Commands
 *  0b0000..No Action
 *  0b0001..TX Start Now
 *  0b0010..TX Start @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b0011..TX Start @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b0100..TX Cancel -- Cancels pending TX events but do not abort a TX-in-progress
 *  0b0101..RX Start Now
 *  0b0110..RX Start @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b0111..RX Start @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b1000..RX Stop @ T1 Timer Compare Match (EVENT_TMR = T1_CMP)
 *  0b1001..RX Stop @ T2 Timer Compare Match (EVENT_TMR = T2_CMP)
 *  0b1010..RX Cancel -- Cancels pending RX events but do not abort a RX-in-progress
 *  0b1011..Abort All - Cancels all pending events and abort any sequence-in-progress
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define ANT_XCVR_CTRL_SEQCMD(x)                  (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CTRL_SEQCMD_SHIFT)) & ANT_XCVR_CTRL_SEQCMD_MASK)

#define ANT_XCVR_CTRL_TX_PKT_LENGTH_MASK         (0x3F00U)
#define ANT_XCVR_CTRL_TX_PKT_LENGTH_SHIFT        (8U)
/*! TX_PKT_LENGTH - Transmit Packet Length */
#define ANT_XCVR_CTRL_TX_PKT_LENGTH(x)           (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CTRL_TX_PKT_LENGTH_SHIFT)) & ANT_XCVR_CTRL_TX_PKT_LENGTH_MASK)

#define ANT_XCVR_CTRL_RX_PKT_LENGTH_MASK         (0x3F0000U)
#define ANT_XCVR_CTRL_RX_PKT_LENGTH_SHIFT        (16U)
/*! RX_PKT_LENGTH - Receive Packet Length */
#define ANT_XCVR_CTRL_RX_PKT_LENGTH(x)           (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CTRL_RX_PKT_LENGTH_SHIFT)) & ANT_XCVR_CTRL_RX_PKT_LENGTH_MASK)

#define ANT_XCVR_CTRL_CMDDEC_CS_MASK             (0x7000000U)
#define ANT_XCVR_CTRL_CMDDEC_CS_SHIFT            (24U)
/*! CMDDEC_CS - Command Decode */
#define ANT_XCVR_CTRL_CMDDEC_CS(x)               (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CTRL_CMDDEC_CS_SHIFT)) & ANT_XCVR_CTRL_CMDDEC_CS_MASK)

#define ANT_XCVR_CTRL_XCVR_BUSY_MASK             (0x80000000U)
#define ANT_XCVR_CTRL_XCVR_BUSY_SHIFT            (31U)
/*! XCVR_BUSY - Transceiver Busy
 *  0b0..IDLE
 *  0b1..BUSY
 */
#define ANT_XCVR_CTRL_XCVR_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CTRL_XCVR_BUSY_SHIFT)) & ANT_XCVR_CTRL_XCVR_BUSY_MASK)
/*! @} */

/*! @name XCVR_STS - TRANSCEIVER STATUS */
/*! @{ */

#define ANT_XCVR_STS_TX_START_T1_PEND_MASK       (0x1U)
#define ANT_XCVR_STS_TX_START_T1_PEND_SHIFT      (0U)
/*! TX_START_T1_PEND - TX T1 Start Pending Status */
#define ANT_XCVR_STS_TX_START_T1_PEND(x)         (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_TX_START_T1_PEND_SHIFT)) & ANT_XCVR_STS_TX_START_T1_PEND_MASK)

#define ANT_XCVR_STS_TX_START_T2_PEND_MASK       (0x2U)
#define ANT_XCVR_STS_TX_START_T2_PEND_SHIFT      (1U)
/*! TX_START_T2_PEND - TX T2 Start Pending Status */
#define ANT_XCVR_STS_TX_START_T2_PEND(x)         (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_TX_START_T2_PEND_SHIFT)) & ANT_XCVR_STS_TX_START_T2_PEND_MASK)

#define ANT_XCVR_STS_TX_IN_WARMUP_MASK           (0x4U)
#define ANT_XCVR_STS_TX_IN_WARMUP_SHIFT          (2U)
/*! TX_IN_WARMUP - TX Warmup Status */
#define ANT_XCVR_STS_TX_IN_WARMUP(x)             (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_TX_IN_WARMUP_SHIFT)) & ANT_XCVR_STS_TX_IN_WARMUP_MASK)

#define ANT_XCVR_STS_TX_IN_PROGRESS_MASK         (0x8U)
#define ANT_XCVR_STS_TX_IN_PROGRESS_SHIFT        (3U)
/*! TX_IN_PROGRESS - TX in Progress Status */
#define ANT_XCVR_STS_TX_IN_PROGRESS(x)           (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_TX_IN_PROGRESS_SHIFT)) & ANT_XCVR_STS_TX_IN_PROGRESS_MASK)

#define ANT_XCVR_STS_TX_IN_WARMDN_MASK           (0x10U)
#define ANT_XCVR_STS_TX_IN_WARMDN_SHIFT          (4U)
/*! TX_IN_WARMDN - TX Warmdown Status */
#define ANT_XCVR_STS_TX_IN_WARMDN(x)             (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_TX_IN_WARMDN_SHIFT)) & ANT_XCVR_STS_TX_IN_WARMDN_MASK)

#define ANT_XCVR_STS_RX_START_T1_PEND_MASK       (0x20U)
#define ANT_XCVR_STS_RX_START_T1_PEND_SHIFT      (5U)
/*! RX_START_T1_PEND - RX T1 Start Pending Status */
#define ANT_XCVR_STS_RX_START_T1_PEND(x)         (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_START_T1_PEND_SHIFT)) & ANT_XCVR_STS_RX_START_T1_PEND_MASK)

#define ANT_XCVR_STS_RX_START_T2_PEND_MASK       (0x40U)
#define ANT_XCVR_STS_RX_START_T2_PEND_SHIFT      (6U)
/*! RX_START_T2_PEND - RX T2 Start Pending Status */
#define ANT_XCVR_STS_RX_START_T2_PEND(x)         (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_START_T2_PEND_SHIFT)) & ANT_XCVR_STS_RX_START_T2_PEND_MASK)

#define ANT_XCVR_STS_RX_STOP_T1_PEND_MASK        (0x80U)
#define ANT_XCVR_STS_RX_STOP_T1_PEND_SHIFT       (7U)
/*! RX_STOP_T1_PEND - RX T1 Stop Pending Status */
#define ANT_XCVR_STS_RX_STOP_T1_PEND(x)          (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_STOP_T1_PEND_SHIFT)) & ANT_XCVR_STS_RX_STOP_T1_PEND_MASK)

#define ANT_XCVR_STS_RX_STOP_T2_PEND_MASK        (0x100U)
#define ANT_XCVR_STS_RX_STOP_T2_PEND_SHIFT       (8U)
/*! RX_STOP_T2_PEND - RX T2 Start Pending Status */
#define ANT_XCVR_STS_RX_STOP_T2_PEND(x)          (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_STOP_T2_PEND_SHIFT)) & ANT_XCVR_STS_RX_STOP_T2_PEND_MASK)

#define ANT_XCVR_STS_RX_IN_WARMUP_MASK           (0x200U)
#define ANT_XCVR_STS_RX_IN_WARMUP_SHIFT          (9U)
/*! RX_IN_WARMUP - RX Warmup Status */
#define ANT_XCVR_STS_RX_IN_WARMUP(x)             (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_IN_WARMUP_SHIFT)) & ANT_XCVR_STS_RX_IN_WARMUP_MASK)

#define ANT_XCVR_STS_RX_IN_SEARCH_MASK           (0x400U)
#define ANT_XCVR_STS_RX_IN_SEARCH_SHIFT          (10U)
/*! RX_IN_SEARCH - RX Search Status */
#define ANT_XCVR_STS_RX_IN_SEARCH(x)             (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_IN_SEARCH_SHIFT)) & ANT_XCVR_STS_RX_IN_SEARCH_MASK)

#define ANT_XCVR_STS_RX_IN_PROGRESS_MASK         (0x800U)
#define ANT_XCVR_STS_RX_IN_PROGRESS_SHIFT        (11U)
/*! RX_IN_PROGRESS - RX in Progress Status */
#define ANT_XCVR_STS_RX_IN_PROGRESS(x)           (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_IN_PROGRESS_SHIFT)) & ANT_XCVR_STS_RX_IN_PROGRESS_MASK)

#define ANT_XCVR_STS_RX_IN_WARMDN_MASK           (0x1000U)
#define ANT_XCVR_STS_RX_IN_WARMDN_SHIFT          (12U)
/*! RX_IN_WARMDN - RX Warmdown Status */
#define ANT_XCVR_STS_RX_IN_WARMDN(x)             (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RX_IN_WARMDN_SHIFT)) & ANT_XCVR_STS_RX_IN_WARMDN_MASK)

#define ANT_XCVR_STS_CRC_VALID_MASK              (0x8000U)
#define ANT_XCVR_STS_CRC_VALID_SHIFT             (15U)
/*! CRC_VALID - CRC Valid Indicator
 *  0b0..CRC is not valid for RX packet.
 *  0b1..CRC is valid for RX packet.
 */
#define ANT_XCVR_STS_CRC_VALID(x)                (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_CRC_VALID_SHIFT)) & ANT_XCVR_STS_CRC_VALID_MASK)

#define ANT_XCVR_STS_RSSI_MASK                   (0xFF0000U)
#define ANT_XCVR_STS_RSSI_SHIFT                  (16U)
/*! RSSI - Received Signal Stength Indicator */
#define ANT_XCVR_STS_RSSI(x)                     (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_STS_RSSI_SHIFT)) & ANT_XCVR_STS_RSSI_MASK)
/*! @} */

/*! @name XCVR_CFG - TRANSCEIVER CONFIGURATION */
/*! @{ */

#define ANT_XCVR_CFG_TX_WHITEN_DIS_MASK          (0x1U)
#define ANT_XCVR_CFG_TX_WHITEN_DIS_SHIFT         (0U)
/*! TX_WHITEN_DIS - TX Whitening Disable */
#define ANT_XCVR_CFG_TX_WHITEN_DIS(x)            (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CFG_TX_WHITEN_DIS_SHIFT)) & ANT_XCVR_CFG_TX_WHITEN_DIS_MASK)

#define ANT_XCVR_CFG_RX_DEWHITEN_DIS_MASK        (0x2U)
#define ANT_XCVR_CFG_RX_DEWHITEN_DIS_SHIFT       (1U)
/*! RX_DEWHITEN_DIS - RX De-Whitening Disable */
#define ANT_XCVR_CFG_RX_DEWHITEN_DIS(x)          (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CFG_RX_DEWHITEN_DIS_SHIFT)) & ANT_XCVR_CFG_RX_DEWHITEN_DIS_MASK)

#define ANT_XCVR_CFG_SW_CRC_EN_MASK              (0x4U)
#define ANT_XCVR_CFG_SW_CRC_EN_SHIFT             (2U)
/*! SW_CRC_EN - Software CRC Enable */
#define ANT_XCVR_CFG_SW_CRC_EN(x)                (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CFG_SW_CRC_EN_SHIFT)) & ANT_XCVR_CFG_SW_CRC_EN_MASK)

#define ANT_XCVR_CFG_PREAMBLE_SZ_MASK            (0x30U)
#define ANT_XCVR_CFG_PREAMBLE_SZ_SHIFT           (4U)
/*! PREAMBLE_SZ - Preamble Size */
#define ANT_XCVR_CFG_PREAMBLE_SZ(x)              (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CFG_PREAMBLE_SZ_SHIFT)) & ANT_XCVR_CFG_PREAMBLE_SZ_MASK)

#define ANT_XCVR_CFG_TX_WARMUP_MASK              (0xFF00U)
#define ANT_XCVR_CFG_TX_WARMUP_SHIFT             (8U)
/*! TX_WARMUP - Transmit Warmup Time */
#define ANT_XCVR_CFG_TX_WARMUP(x)                (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CFG_TX_WARMUP_SHIFT)) & ANT_XCVR_CFG_TX_WARMUP_MASK)

#define ANT_XCVR_CFG_RX_WARMUP_MASK              (0xFF0000U)
#define ANT_XCVR_CFG_RX_WARMUP_SHIFT             (16U)
/*! RX_WARMUP - Receive Warmup Time */
#define ANT_XCVR_CFG_RX_WARMUP(x)                (((uint32_t)(((uint32_t)(x)) << ANT_XCVR_CFG_RX_WARMUP_SHIFT)) & ANT_XCVR_CFG_RX_WARMUP_MASK)
/*! @} */

/*! @name CHANNEL_NUM - CHANNEL NUMBER */
/*! @{ */

#define ANT_CHANNEL_NUM_CHANNEL_NUM_MASK         (0x7FU)
#define ANT_CHANNEL_NUM_CHANNEL_NUM_SHIFT        (0U)
/*! CHANNEL_NUM - Channel Number */
#define ANT_CHANNEL_NUM_CHANNEL_NUM(x)           (((uint32_t)(((uint32_t)(x)) << ANT_CHANNEL_NUM_CHANNEL_NUM_SHIFT)) & ANT_CHANNEL_NUM_CHANNEL_NUM_MASK)
/*! @} */

/*! @name TX_POWER - TRANSMIT POWER */
/*! @{ */

#define ANT_TX_POWER_TX_POWER_MASK               (0x3FU)
#define ANT_TX_POWER_TX_POWER_SHIFT              (0U)
/*! TX_POWER - Transmit Power */
#define ANT_TX_POWER_TX_POWER(x)                 (((uint32_t)(((uint32_t)(x)) << ANT_TX_POWER_TX_POWER_SHIFT)) & ANT_TX_POWER_TX_POWER_MASK)
/*! @} */

/*! @name NTW_ADR_CTRL - NETWORK ADDRESS CONTROL */
/*! @{ */

#define ANT_NTW_ADR_CTRL_NTW_ADR_EN_MASK         (0xFU)
#define ANT_NTW_ADR_CTRL_NTW_ADR_EN_SHIFT        (0U)
/*! NTW_ADR_EN - Network Address Match Enable */
#define ANT_NTW_ADR_CTRL_NTW_ADR_EN(x)           (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR_EN_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR_EN_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR_MCH_MASK        (0xF0U)
#define ANT_NTW_ADR_CTRL_NTW_ADR_MCH_SHIFT       (4U)
/*! NTW_ADR_MCH - Network Address Match Status */
#define ANT_NTW_ADR_CTRL_NTW_ADR_MCH(x)          (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR_MCH_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR_MCH_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR0_SZ_MASK        (0x300U)
#define ANT_NTW_ADR_CTRL_NTW_ADR0_SZ_SHIFT       (8U)
/*! NTW_ADR0_SZ - Network Address Match Size
 *  0b00..1 octet
 *  0b01..2 octets
 *  0b10..3 octets
 *  0b11..4 octets
 */
#define ANT_NTW_ADR_CTRL_NTW_ADR0_SZ(x)          (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR0_SZ_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR0_SZ_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR1_SZ_MASK        (0xC00U)
#define ANT_NTW_ADR_CTRL_NTW_ADR1_SZ_SHIFT       (10U)
/*! NTW_ADR1_SZ - Network Address Match Size
 *  0b00..1 octet
 *  0b01..2 octets
 *  0b10..3 octets
 *  0b11..4 octets
 */
#define ANT_NTW_ADR_CTRL_NTW_ADR1_SZ(x)          (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR1_SZ_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR1_SZ_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR2_SZ_MASK        (0x3000U)
#define ANT_NTW_ADR_CTRL_NTW_ADR2_SZ_SHIFT       (12U)
/*! NTW_ADR2_SZ - Network Address Match Size
 *  0b00..1 octet
 *  0b01..2 octets
 *  0b10..3 octets
 *  0b11..4 octets
 */
#define ANT_NTW_ADR_CTRL_NTW_ADR2_SZ(x)          (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR2_SZ_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR2_SZ_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR3_SZ_MASK        (0xC000U)
#define ANT_NTW_ADR_CTRL_NTW_ADR3_SZ_SHIFT       (14U)
/*! NTW_ADR3_SZ - Network Address Match Size
 *  0b00..1 octet
 *  0b01..2 octets
 *  0b10..3 octets
 *  0b11..4 octets
 */
#define ANT_NTW_ADR_CTRL_NTW_ADR3_SZ(x)          (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR3_SZ_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR3_SZ_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR_THR0_MASK       (0x70000U)
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR0_SHIFT      (16U)
/*! NTW_ADR_THR0 - Network Address Match Bit Error Threshold 0 */
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR0(x)         (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR_THR0_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR_THR0_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR_THR1_MASK       (0x700000U)
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR1_SHIFT      (20U)
/*! NTW_ADR_THR1 - Network Address Match Bit Error Threshold 1 */
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR1(x)         (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR_THR1_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR_THR1_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR_THR2_MASK       (0x7000000U)
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR2_SHIFT      (24U)
/*! NTW_ADR_THR2 - Network Address Match Bit Error Threshold 2 */
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR2(x)         (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR_THR2_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR_THR2_MASK)

#define ANT_NTW_ADR_CTRL_NTW_ADR_THR3_MASK       (0x70000000U)
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR3_SHIFT      (28U)
/*! NTW_ADR_THR3 - Network Address Match Bit Error Threshold 3 */
#define ANT_NTW_ADR_CTRL_NTW_ADR_THR3(x)         (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_CTRL_NTW_ADR_THR3_SHIFT)) & ANT_NTW_ADR_CTRL_NTW_ADR_THR3_MASK)
/*! @} */

/*! @name NTW_ADR_0 - NETWORK ADDRESS 0 */
/*! @{ */

#define ANT_NTW_ADR_0_NTW_ADR_0_MASK             (0xFFFFFFFFU)
#define ANT_NTW_ADR_0_NTW_ADR_0_SHIFT            (0U)
/*! NTW_ADR_0 - Network Address 0 */
#define ANT_NTW_ADR_0_NTW_ADR_0(x)               (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_0_NTW_ADR_0_SHIFT)) & ANT_NTW_ADR_0_NTW_ADR_0_MASK)
/*! @} */

/*! @name NTW_ADR_1 - NETWORK ADDRESS 1 */
/*! @{ */

#define ANT_NTW_ADR_1_NTW_ADR_1_MASK             (0xFFFFFFFFU)
#define ANT_NTW_ADR_1_NTW_ADR_1_SHIFT            (0U)
/*! NTW_ADR_1 - Network Address 1 */
#define ANT_NTW_ADR_1_NTW_ADR_1(x)               (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_1_NTW_ADR_1_SHIFT)) & ANT_NTW_ADR_1_NTW_ADR_1_MASK)
/*! @} */

/*! @name NTW_ADR_2 - NETWORK ADDRESS 2 */
/*! @{ */

#define ANT_NTW_ADR_2_NTW_ADR_2_MASK             (0xFFFFFFFFU)
#define ANT_NTW_ADR_2_NTW_ADR_2_SHIFT            (0U)
/*! NTW_ADR_2 - Network Address 2 */
#define ANT_NTW_ADR_2_NTW_ADR_2(x)               (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_2_NTW_ADR_2_SHIFT)) & ANT_NTW_ADR_2_NTW_ADR_2_MASK)
/*! @} */

/*! @name NTW_ADR_3 - NETWORK ADDRESS 3 */
/*! @{ */

#define ANT_NTW_ADR_3_NTW_ADR_3_MASK             (0xFFFFFFFFU)
#define ANT_NTW_ADR_3_NTW_ADR_3_SHIFT            (0U)
/*! NTW_ADR_3 - Network Address 2 */
#define ANT_NTW_ADR_3_NTW_ADR_3(x)               (((uint32_t)(((uint32_t)(x)) << ANT_NTW_ADR_3_NTW_ADR_3_SHIFT)) & ANT_NTW_ADR_3_NTW_ADR_3_MASK)
/*! @} */

/*! @name RX_WATERMARK - RX WATERMARK */
/*! @{ */

#define ANT_RX_WATERMARK_RX_WATERMARK_MASK       (0x7FU)
#define ANT_RX_WATERMARK_RX_WATERMARK_SHIFT      (0U)
/*! RX_WATERMARK - RX Watermark */
#define ANT_RX_WATERMARK_RX_WATERMARK(x)         (((uint32_t)(((uint32_t)(x)) << ANT_RX_WATERMARK_RX_WATERMARK_SHIFT)) & ANT_RX_WATERMARK_RX_WATERMARK_MASK)

#define ANT_RX_WATERMARK_BYTE_COUNTER_MASK       (0x7F0000U)
#define ANT_RX_WATERMARK_BYTE_COUNTER_SHIFT      (16U)
/*! BYTE_COUNTER - Byte Counter
 *  0b1xxxxxx..When less than 0, Preamble byte(s), TX only
 *  0b0000000..First Byte of Network Address
 *  0b0000001..Second Byte of Network Address
 *  0b0000010-0b0111111..Etc...
 */
#define ANT_RX_WATERMARK_BYTE_COUNTER(x)         (((uint32_t)(((uint32_t)(x)) << ANT_RX_WATERMARK_BYTE_COUNTER_SHIFT)) & ANT_RX_WATERMARK_BYTE_COUNTER_MASK)
/*! @} */

/*! @name DSM_CTRL - DSM CONTROL */
/*! @{ */

#define ANT_DSM_CTRL_ANT_SLEEP_EN_MASK           (0x1U)
#define ANT_DSM_CTRL_ANT_SLEEP_EN_SHIFT          (0U)
/*! ANT_SLEEP_EN - ANT DSM Sleep Enable */
#define ANT_DSM_CTRL_ANT_SLEEP_EN(x)             (((uint32_t)(((uint32_t)(x)) << ANT_DSM_CTRL_ANT_SLEEP_EN_SHIFT)) & ANT_DSM_CTRL_ANT_SLEEP_EN_MASK)
/*! @} */

/*! @name PART_ID - PART ID */
/*! @{ */

#define ANT_PART_ID_PART_ID_MASK                 (0xFFU)
#define ANT_PART_ID_PART_ID_SHIFT                (0U)
/*! PART_ID - Part ID */
#define ANT_PART_ID_PART_ID(x)                   (((uint32_t)(((uint32_t)(x)) << ANT_PART_ID_PART_ID_SHIFT)) & ANT_PART_ID_PART_ID_MASK)
/*! @} */

/*! @name PACKET_BUFFER - PACKET BUFFER */
/*! @{ */

#define ANT_PACKET_BUFFER_PACKET_BUFFER_MASK     (0xFFFFU)
#define ANT_PACKET_BUFFER_PACKET_BUFFER_SHIFT    (0U)
/*! PACKET_BUFFER - PACKET BUFFER RAM */
#define ANT_PACKET_BUFFER_PACKET_BUFFER(x)       (((uint16_t)(((uint16_t)(x)) << ANT_PACKET_BUFFER_PACKET_BUFFER_SHIFT)) & ANT_PACKET_BUFFER_PACKET_BUFFER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANT_Register_Masks */


/*!
 * @}
 */ /* end of group ANT_Peripheral_Access_Layer */


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


#endif  /* ANT_H_ */

