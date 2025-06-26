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
**         CMSIS Peripheral Access Layer for GENFSK
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
 * @file GENFSK.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for GENFSK
 *
 * CMSIS Peripheral Access Layer for GENFSK
 */

#if !defined(GENFSK_H_)
#define GENFSK_H_                                /**< Symbol preventing repeated inclusion */

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
   -- GENFSK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GENFSK_Peripheral_Access_Layer GENFSK Peripheral Access Layer
 * @{
 */

/** GENFSK - Register Layout Typedef */
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
  __IO uint32_t RX_WATERMARK;                      /**< RECEIVE WATERMARK, offset: 0x3C */
  __O  uint32_t DSM_CTRL;                          /**< DSM CONTROL, offset: 0x40 */
  __I  uint32_t PART_ID;                           /**< PART ID, offset: 0x44 */
       uint8_t RESERVED_0[24];
  __IO uint32_t PACKET_CFG;                        /**< PACKET CONFIGURATION, offset: 0x60 */
  __IO uint32_t H0_CFG;                            /**< H0 CONFIGURATION, offset: 0x64 */
  __IO uint32_t H1_CFG;                            /**< H1 CONFIGURATION, offset: 0x68 */
  __IO uint32_t CRC_CFG;                           /**< CRC CONFIGURATION, offset: 0x6C */
  __IO uint32_t CRC_INIT;                          /**< CRC INITIALIZATION, offset: 0x70 */
  __IO uint32_t CRC_POLY;                          /**< CRC POLYNOMIAL, offset: 0x74 */
  __IO uint32_t CRC_XOR_OUT;                       /**< CRC XOR OUT, offset: 0x78 */
  __IO uint32_t WHITEN_CFG;                        /**< WHITENER CONFIGURATION, offset: 0x7C */
  __IO uint32_t WHITEN_POLY;                       /**< WHITENER POLYNOMIAL, offset: 0x80 */
  __IO uint32_t WHITEN_SZ_THR;                     /**< WHITENER SIZE THRESHOLD, offset: 0x84 */
  __IO uint32_t BITRATE;                           /**< BIT RATE, offset: 0x88 */
  __IO uint32_t PB_PARTITION;                      /**< PACKET BUFFER PARTITION POINT, offset: 0x8C */
} GENFSK_Type;

/* ----------------------------------------------------------------------------
   -- GENFSK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GENFSK_Register_Masks GENFSK Register Masks
 * @{
 */

/*! @name IRQ_CTRL - IRQ CONTROL */
/*! @{ */

#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_MASK         (0x1U)
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_SHIFT        (0U)
/*! SEQ_END_IRQ - Sequence End Interrupt
 *  0b0..Sequence End Interrupt is not asserted.
 *  0b1..Sequence End Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_SEQ_END_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_SEQ_END_IRQ_MASK)

#define GENFSK_IRQ_CTRL_TX_IRQ_MASK              (0x2U)
#define GENFSK_IRQ_CTRL_TX_IRQ_SHIFT             (1U)
/*! TX_IRQ - TX Interrupt
 *  0b0..TX Interrupt is not asserted.
 *  0b1..TX Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_TX_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TX_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_TX_IRQ_MASK)

#define GENFSK_IRQ_CTRL_RX_IRQ_MASK              (0x4U)
#define GENFSK_IRQ_CTRL_RX_IRQ_SHIFT             (2U)
/*! RX_IRQ - RX Interrupt
 *  0b0..RX Interrupt is not asserted.
 *  0b1..RX Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_RX_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_RX_IRQ_MASK)

#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_MASK         (0x8U)
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_SHIFT        (3U)
/*! NTW_ADR_IRQ - Network Address Match Interrupt
 *  0b0..Network Address Match Interrupt is not asserted.
 *  0b1..Network Address Match Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_NTW_ADR_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_NTW_ADR_IRQ_MASK)

#define GENFSK_IRQ_CTRL_T1_IRQ_MASK              (0x10U)
#define GENFSK_IRQ_CTRL_T1_IRQ_SHIFT             (4U)
/*! T1_IRQ - Timer1 (T1) Compare Interrupt
 *  0b0..Timer1 (T1) Compare Interrupt is not asserted.
 *  0b1..Timer1 (T1) Compare Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_T1_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T1_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_T1_IRQ_MASK)

#define GENFSK_IRQ_CTRL_T2_IRQ_MASK              (0x20U)
#define GENFSK_IRQ_CTRL_T2_IRQ_SHIFT             (5U)
/*! T2_IRQ - Timer2 (T2) Compare Interrupt
 *  0b0..Timer2 (T2) Compare Interrupt is not asserted.
 *  0b1..Timer2 (T2) Compare Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_T2_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T2_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_T2_IRQ_MASK)

#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_MASK      (0x40U)
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_SHIFT     (6U)
/*! PLL_UNLOCK_IRQ - PLL Unlock Interrupt
 *  0b0..PLL Unlock Interrupt is not asserted.
 *  0b1..PLL Unlock Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_MASK)

#define GENFSK_IRQ_CTRL_WAKE_IRQ_MASK            (0x80U)
#define GENFSK_IRQ_CTRL_WAKE_IRQ_SHIFT           (7U)
/*! WAKE_IRQ - Wake Interrrupt
 *  0b0..Wake Interrupt is not asserted.
 *  0b1..Wake Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_WAKE_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_WAKE_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_WAKE_IRQ_MASK)

#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_MASK    (0x100U)
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_SHIFT   (8U)
/*! RX_WATERMARK_IRQ - RX Watermark Interrupt
 *  0b0..RX Watermark Interrupt is not asserted.
 *  0b1..RX Watermark Interrupt is asserted.
 */
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_MASK)

#define GENFSK_IRQ_CTRL_TSM_IRQ_MASK             (0x200U)
#define GENFSK_IRQ_CTRL_TSM_IRQ_SHIFT            (9U)
/*! TSM_IRQ - TSM Interrupt
 *  0b0..TSM0_IRQ and TSM1_IRQ are both clear.
 *  0b1..Indicates TSM0_IRQ or TSM1_IRQ is set in XCVR_STATUS.
 */
#define GENFSK_IRQ_CTRL_TSM_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TSM_IRQ_SHIFT)) & GENFSK_IRQ_CTRL_TSM_IRQ_MASK)

#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_MASK      (0x10000U)
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_SHIFT     (16U)
/*! SEQ_END_IRQ_EN - SEQ_END_IRQ Enable
 *  0b0..Sequence End Interrupt is not enabled.
 *  0b1..Sequence End Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_SEQ_END_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_TX_IRQ_EN_MASK           (0x20000U)
#define GENFSK_IRQ_CTRL_TX_IRQ_EN_SHIFT          (17U)
/*! TX_IRQ_EN - TX_IRQ Enable
 *  0b0..TX Interrupt is not enabled.
 *  0b1..TX Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_TX_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TX_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_TX_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_RX_IRQ_EN_MASK           (0x40000U)
#define GENFSK_IRQ_CTRL_RX_IRQ_EN_SHIFT          (18U)
/*! RX_IRQ_EN - RX_IRQ Enable
 *  0b0..RX Interrupt is not enabled.
 *  0b1..RX Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_RX_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_RX_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_MASK      (0x80000U)
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_SHIFT     (19U)
/*! NTW_ADR_IRQ_EN - NTW_ADR_IRQ Enable
 *  0b0..Network Address Match Interrupt is not enabled.
 *  0b1..Network Address Match Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_NTW_ADR_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_T1_IRQ_EN_MASK           (0x100000U)
#define GENFSK_IRQ_CTRL_T1_IRQ_EN_SHIFT          (20U)
/*! T1_IRQ_EN - T1_IRQ Enable
 *  0b0..Timer1 (T1) Compare Interrupt is not enabled.
 *  0b1..Timer1 (T1) Compare Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_T1_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T1_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_T1_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_T2_IRQ_EN_MASK           (0x200000U)
#define GENFSK_IRQ_CTRL_T2_IRQ_EN_SHIFT          (21U)
/*! T2_IRQ_EN - T2_IRQ Enable
 *  0b0..Timer1 (T2) Compare Interrupt is not enabled.
 *  0b1..Timer1 (T2) Compare Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_T2_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_T2_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_T2_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_MASK   (0x400000U)
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT  (22U)
/*! PLL_UNLOCK_IRQ_EN - PLL_UNLOCK_IRQ Enable
 *  0b0..PLL Unlock Interrupt is not enabled.
 *  0b1..PLL Unlock Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_PLL_UNLOCK_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_WAKE_IRQ_EN_MASK         (0x800000U)
#define GENFSK_IRQ_CTRL_WAKE_IRQ_EN_SHIFT        (23U)
/*! WAKE_IRQ_EN - WAKE_IRQ Enable
 *  0b0..Wake Interrupt is not enabled.
 *  0b1..Wake Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_WAKE_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_WAKE_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_WAKE_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_MASK (0x1000000U)
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_SHIFT (24U)
/*! RX_WATERMARK_IRQ_EN - RX_WATERMARK_IRQ Enable
 *  0b0..RX Watermark Interrupt is not enabled.
 *  0b1..RX Watermark Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_RX_WATERMARK_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_TSM_IRQ_EN_MASK          (0x2000000U)
#define GENFSK_IRQ_CTRL_TSM_IRQ_EN_SHIFT         (25U)
/*! TSM_IRQ_EN - TSM_IRQ Enable
 *  0b0..TSM Interrupt is not enabled.
 *  0b1..TSM Interrupt is enabled.
 */
#define GENFSK_IRQ_CTRL_TSM_IRQ_EN(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_TSM_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_TSM_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_MASK  (0x4000000U)
#define GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_SHIFT (26U)
/*! GENERIC_FSK_IRQ_EN - GENERIC_FSK_IRQ Master Enable
 *  0b0..All GENERIC_FSK Interrupts are disabled.
 *  0b1..All GENERIC_FSK Interrupts can be enabled.
 */
#define GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_SHIFT)) & GENFSK_IRQ_CTRL_GENERIC_FSK_IRQ_EN_MASK)

#define GENFSK_IRQ_CTRL_CRC_IGNORE_MASK          (0x8000000U)
#define GENFSK_IRQ_CTRL_CRC_IGNORE_SHIFT         (27U)
/*! CRC_IGNORE - CRC Ignore
 *  0b0..RX_IRQ will not be asserted for a received packet which fails CRC verification.
 *  0b1..RX_IRQ will be asserted even for a received packet which fails CRC verification.
 */
#define GENFSK_IRQ_CTRL_CRC_IGNORE(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_CRC_IGNORE_SHIFT)) & GENFSK_IRQ_CTRL_CRC_IGNORE_MASK)

#define GENFSK_IRQ_CTRL_CRC_VALID_MASK           (0x80000000U)
#define GENFSK_IRQ_CTRL_CRC_VALID_SHIFT          (31U)
/*! CRC_VALID - CRC Valid
 *  0b0..CRC of RX packet is not valid.
 *  0b1..CRC of RX packet is valid.
 */
#define GENFSK_IRQ_CTRL_CRC_VALID(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_IRQ_CTRL_CRC_VALID_SHIFT)) & GENFSK_IRQ_CTRL_CRC_VALID_MASK)
/*! @} */

/*! @name EVENT_TMR - EVENT TIMER */
/*! @{ */

#define GENFSK_EVENT_TMR_EVENT_TMR_MASK          (0xFFFFFFU)
#define GENFSK_EVENT_TMR_EVENT_TMR_SHIFT         (0U)
/*! EVENT_TMR - Event Timer */
#define GENFSK_EVENT_TMR_EVENT_TMR(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_EVENT_TMR_EVENT_TMR_SHIFT)) & GENFSK_EVENT_TMR_EVENT_TMR_MASK)

#define GENFSK_EVENT_TMR_EVENT_TMR_LD_MASK       (0x1000000U)
#define GENFSK_EVENT_TMR_EVENT_TMR_LD_SHIFT      (24U)
/*! EVENT_TMR_LD - Event Timer Load */
#define GENFSK_EVENT_TMR_EVENT_TMR_LD(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_EVENT_TMR_EVENT_TMR_LD_SHIFT)) & GENFSK_EVENT_TMR_EVENT_TMR_LD_MASK)

#define GENFSK_EVENT_TMR_EVENT_TMR_ADD_MASK      (0x2000000U)
#define GENFSK_EVENT_TMR_EVENT_TMR_ADD_SHIFT     (25U)
/*! EVENT_TMR_ADD - Event Timer Add */
#define GENFSK_EVENT_TMR_EVENT_TMR_ADD(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_EVENT_TMR_EVENT_TMR_ADD_SHIFT)) & GENFSK_EVENT_TMR_EVENT_TMR_ADD_MASK)
/*! @} */

/*! @name T1_CMP - T1 COMPARE */
/*! @{ */

#define GENFSK_T1_CMP_T1_CMP_MASK                (0xFFFFFFU)
#define GENFSK_T1_CMP_T1_CMP_SHIFT               (0U)
/*! T1_CMP - Timer1 (T1) Compare Value */
#define GENFSK_T1_CMP_T1_CMP(x)                  (((uint32_t)(((uint32_t)(x)) << GENFSK_T1_CMP_T1_CMP_SHIFT)) & GENFSK_T1_CMP_T1_CMP_MASK)

#define GENFSK_T1_CMP_T1_CMP_EN_MASK             (0x1000000U)
#define GENFSK_T1_CMP_T1_CMP_EN_SHIFT            (24U)
/*! T1_CMP_EN - Timer1 (T1) Compare Enable */
#define GENFSK_T1_CMP_T1_CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_T1_CMP_T1_CMP_EN_SHIFT)) & GENFSK_T1_CMP_T1_CMP_EN_MASK)
/*! @} */

/*! @name T2_CMP - T2 COMPARE */
/*! @{ */

#define GENFSK_T2_CMP_T2_CMP_MASK                (0xFFFFFFU)
#define GENFSK_T2_CMP_T2_CMP_SHIFT               (0U)
/*! T2_CMP - Timer2 (T2) Compare Value */
#define GENFSK_T2_CMP_T2_CMP(x)                  (((uint32_t)(((uint32_t)(x)) << GENFSK_T2_CMP_T2_CMP_SHIFT)) & GENFSK_T2_CMP_T2_CMP_MASK)

#define GENFSK_T2_CMP_T2_CMP_EN_MASK             (0x1000000U)
#define GENFSK_T2_CMP_T2_CMP_EN_SHIFT            (24U)
/*! T2_CMP_EN - Timer2 (T2) Compare Enable */
#define GENFSK_T2_CMP_T2_CMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_T2_CMP_T2_CMP_EN_SHIFT)) & GENFSK_T2_CMP_T2_CMP_EN_MASK)
/*! @} */

/*! @name TIMESTAMP - TIMESTAMP */
/*! @{ */

#define GENFSK_TIMESTAMP_TIMESTAMP_MASK          (0xFFFFFFU)
#define GENFSK_TIMESTAMP_TIMESTAMP_SHIFT         (0U)
/*! TIMESTAMP - Received Packet Timestamp */
#define GENFSK_TIMESTAMP_TIMESTAMP(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_TIMESTAMP_TIMESTAMP_SHIFT)) & GENFSK_TIMESTAMP_TIMESTAMP_MASK)
/*! @} */

/*! @name XCVR_CTRL - TRANSCEIVER CONTROL */
/*! @{ */

#define GENFSK_XCVR_CTRL_SEQCMD_MASK             (0xFU)
#define GENFSK_XCVR_CTRL_SEQCMD_SHIFT            (0U)
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
#define GENFSK_XCVR_CTRL_SEQCMD(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CTRL_SEQCMD_SHIFT)) & GENFSK_XCVR_CTRL_SEQCMD_MASK)

#define GENFSK_XCVR_CTRL_CMDDEC_CS_MASK          (0x7000000U)
#define GENFSK_XCVR_CTRL_CMDDEC_CS_SHIFT         (24U)
/*! CMDDEC_CS - Command Decode */
#define GENFSK_XCVR_CTRL_CMDDEC_CS(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CTRL_CMDDEC_CS_SHIFT)) & GENFSK_XCVR_CTRL_CMDDEC_CS_MASK)

#define GENFSK_XCVR_CTRL_XCVR_BUSY_MASK          (0x80000000U)
#define GENFSK_XCVR_CTRL_XCVR_BUSY_SHIFT         (31U)
/*! XCVR_BUSY - Transceiver Busy
 *  0b0..IDLE
 *  0b1..BUSY
 */
#define GENFSK_XCVR_CTRL_XCVR_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CTRL_XCVR_BUSY_SHIFT)) & GENFSK_XCVR_CTRL_XCVR_BUSY_MASK)
/*! @} */

/*! @name XCVR_STS - TRANSCEIVER STATUS */
/*! @{ */

#define GENFSK_XCVR_STS_TX_START_T1_PEND_MASK    (0x1U)
#define GENFSK_XCVR_STS_TX_START_T1_PEND_SHIFT   (0U)
/*! TX_START_T1_PEND - TX T1 Start Pending Status */
#define GENFSK_XCVR_STS_TX_START_T1_PEND(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_TX_START_T1_PEND_SHIFT)) & GENFSK_XCVR_STS_TX_START_T1_PEND_MASK)

#define GENFSK_XCVR_STS_TX_START_T2_PEND_MASK    (0x2U)
#define GENFSK_XCVR_STS_TX_START_T2_PEND_SHIFT   (1U)
/*! TX_START_T2_PEND - TX T2 Start Pending Status */
#define GENFSK_XCVR_STS_TX_START_T2_PEND(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_TX_START_T2_PEND_SHIFT)) & GENFSK_XCVR_STS_TX_START_T2_PEND_MASK)

#define GENFSK_XCVR_STS_TX_IN_WARMUP_MASK        (0x4U)
#define GENFSK_XCVR_STS_TX_IN_WARMUP_SHIFT       (2U)
/*! TX_IN_WARMUP - TX Warmup Status */
#define GENFSK_XCVR_STS_TX_IN_WARMUP(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_TX_IN_WARMUP_SHIFT)) & GENFSK_XCVR_STS_TX_IN_WARMUP_MASK)

#define GENFSK_XCVR_STS_TX_IN_PROGRESS_MASK      (0x8U)
#define GENFSK_XCVR_STS_TX_IN_PROGRESS_SHIFT     (3U)
/*! TX_IN_PROGRESS - TX in Progress Status */
#define GENFSK_XCVR_STS_TX_IN_PROGRESS(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_TX_IN_PROGRESS_SHIFT)) & GENFSK_XCVR_STS_TX_IN_PROGRESS_MASK)

#define GENFSK_XCVR_STS_TX_IN_WARMDN_MASK        (0x10U)
#define GENFSK_XCVR_STS_TX_IN_WARMDN_SHIFT       (4U)
/*! TX_IN_WARMDN - TX Warmdown Status */
#define GENFSK_XCVR_STS_TX_IN_WARMDN(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_TX_IN_WARMDN_SHIFT)) & GENFSK_XCVR_STS_TX_IN_WARMDN_MASK)

#define GENFSK_XCVR_STS_RX_START_T1_PEND_MASK    (0x20U)
#define GENFSK_XCVR_STS_RX_START_T1_PEND_SHIFT   (5U)
/*! RX_START_T1_PEND - RX T1 Start Pending Status */
#define GENFSK_XCVR_STS_RX_START_T1_PEND(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_START_T1_PEND_SHIFT)) & GENFSK_XCVR_STS_RX_START_T1_PEND_MASK)

#define GENFSK_XCVR_STS_RX_START_T2_PEND_MASK    (0x40U)
#define GENFSK_XCVR_STS_RX_START_T2_PEND_SHIFT   (6U)
/*! RX_START_T2_PEND - RX T2 Start Pending Status */
#define GENFSK_XCVR_STS_RX_START_T2_PEND(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_START_T2_PEND_SHIFT)) & GENFSK_XCVR_STS_RX_START_T2_PEND_MASK)

#define GENFSK_XCVR_STS_RX_STOP_T1_PEND_MASK     (0x80U)
#define GENFSK_XCVR_STS_RX_STOP_T1_PEND_SHIFT    (7U)
/*! RX_STOP_T1_PEND - RX T1 Stop Pending Status */
#define GENFSK_XCVR_STS_RX_STOP_T1_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_STOP_T1_PEND_SHIFT)) & GENFSK_XCVR_STS_RX_STOP_T1_PEND_MASK)

#define GENFSK_XCVR_STS_RX_STOP_T2_PEND_MASK     (0x100U)
#define GENFSK_XCVR_STS_RX_STOP_T2_PEND_SHIFT    (8U)
/*! RX_STOP_T2_PEND - RX T2 Start Pending Status */
#define GENFSK_XCVR_STS_RX_STOP_T2_PEND(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_STOP_T2_PEND_SHIFT)) & GENFSK_XCVR_STS_RX_STOP_T2_PEND_MASK)

#define GENFSK_XCVR_STS_RX_IN_WARMUP_MASK        (0x200U)
#define GENFSK_XCVR_STS_RX_IN_WARMUP_SHIFT       (9U)
/*! RX_IN_WARMUP - RX Warmup Status */
#define GENFSK_XCVR_STS_RX_IN_WARMUP(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_IN_WARMUP_SHIFT)) & GENFSK_XCVR_STS_RX_IN_WARMUP_MASK)

#define GENFSK_XCVR_STS_RX_IN_SEARCH_MASK        (0x400U)
#define GENFSK_XCVR_STS_RX_IN_SEARCH_SHIFT       (10U)
/*! RX_IN_SEARCH - RX Search Status */
#define GENFSK_XCVR_STS_RX_IN_SEARCH(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_IN_SEARCH_SHIFT)) & GENFSK_XCVR_STS_RX_IN_SEARCH_MASK)

#define GENFSK_XCVR_STS_RX_IN_PROGRESS_MASK      (0x800U)
#define GENFSK_XCVR_STS_RX_IN_PROGRESS_SHIFT     (11U)
/*! RX_IN_PROGRESS - RX in Progress Status */
#define GENFSK_XCVR_STS_RX_IN_PROGRESS(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_IN_PROGRESS_SHIFT)) & GENFSK_XCVR_STS_RX_IN_PROGRESS_MASK)

#define GENFSK_XCVR_STS_RX_IN_WARMDN_MASK        (0x1000U)
#define GENFSK_XCVR_STS_RX_IN_WARMDN_SHIFT       (12U)
/*! RX_IN_WARMDN - RX Warmdown Status */
#define GENFSK_XCVR_STS_RX_IN_WARMDN(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RX_IN_WARMDN_SHIFT)) & GENFSK_XCVR_STS_RX_IN_WARMDN_MASK)

#define GENFSK_XCVR_STS_LQI_VALID_MASK           (0x4000U)
#define GENFSK_XCVR_STS_LQI_VALID_SHIFT          (14U)
/*! LQI_VALID - LQI Valid Indicator
 *  0b0..LQI is not yet valid for RX packet.
 *  0b1..LQI is valid for RX packet.
 */
#define GENFSK_XCVR_STS_LQI_VALID(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_LQI_VALID_SHIFT)) & GENFSK_XCVR_STS_LQI_VALID_MASK)

#define GENFSK_XCVR_STS_CRC_VALID_MASK           (0x8000U)
#define GENFSK_XCVR_STS_CRC_VALID_SHIFT          (15U)
/*! CRC_VALID - CRC Valid Indicator
 *  0b0..CRC is not valid for RX packet.
 *  0b1..CRC is valid for RX packet.
 */
#define GENFSK_XCVR_STS_CRC_VALID(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_CRC_VALID_SHIFT)) & GENFSK_XCVR_STS_CRC_VALID_MASK)

#define GENFSK_XCVR_STS_RSSI_MASK                (0xFF0000U)
#define GENFSK_XCVR_STS_RSSI_SHIFT               (16U)
/*! RSSI - Received Signal Stength Indicator, in dBm */
#define GENFSK_XCVR_STS_RSSI(x)                  (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_RSSI_SHIFT)) & GENFSK_XCVR_STS_RSSI_MASK)

#define GENFSK_XCVR_STS_LQI_MASK                 (0xFF000000U)
#define GENFSK_XCVR_STS_LQI_SHIFT                (24U)
/*! LQI - Link Quality Indicator */
#define GENFSK_XCVR_STS_LQI(x)                   (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_STS_LQI_SHIFT)) & GENFSK_XCVR_STS_LQI_MASK)
/*! @} */

/*! @name XCVR_CFG - TRANSCEIVER CONFIGURATION */
/*! @{ */

#define GENFSK_XCVR_CFG_TX_WHITEN_DIS_MASK       (0x1U)
#define GENFSK_XCVR_CFG_TX_WHITEN_DIS_SHIFT      (0U)
/*! TX_WHITEN_DIS - TX Whitening Disable */
#define GENFSK_XCVR_CFG_TX_WHITEN_DIS(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_TX_WHITEN_DIS_SHIFT)) & GENFSK_XCVR_CFG_TX_WHITEN_DIS_MASK)

#define GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_MASK     (0x2U)
#define GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_SHIFT    (1U)
/*! RX_DEWHITEN_DIS - RX De-Whitening Disable */
#define GENFSK_XCVR_CFG_RX_DEWHITEN_DIS(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_SHIFT)) & GENFSK_XCVR_CFG_RX_DEWHITEN_DIS_MASK)

#define GENFSK_XCVR_CFG_SW_CRC_EN_MASK           (0x4U)
#define GENFSK_XCVR_CFG_SW_CRC_EN_SHIFT          (2U)
/*! SW_CRC_EN - Software CRC Enable */
#define GENFSK_XCVR_CFG_SW_CRC_EN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_SW_CRC_EN_SHIFT)) & GENFSK_XCVR_CFG_SW_CRC_EN_MASK)

#define GENFSK_XCVR_CFG_PREAMBLE_SZ_MASK         (0x70U)
#define GENFSK_XCVR_CFG_PREAMBLE_SZ_SHIFT        (4U)
/*! PREAMBLE_SZ - Preamble Size */
#define GENFSK_XCVR_CFG_PREAMBLE_SZ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_PREAMBLE_SZ_SHIFT)) & GENFSK_XCVR_CFG_PREAMBLE_SZ_MASK)

#define GENFSK_XCVR_CFG_TX_WARMUP_MASK           (0xFF00U)
#define GENFSK_XCVR_CFG_TX_WARMUP_SHIFT          (8U)
/*! TX_WARMUP - Transmit Warmup Time */
#define GENFSK_XCVR_CFG_TX_WARMUP(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_TX_WARMUP_SHIFT)) & GENFSK_XCVR_CFG_TX_WARMUP_MASK)

#define GENFSK_XCVR_CFG_RX_WARMUP_MASK           (0xFF0000U)
#define GENFSK_XCVR_CFG_RX_WARMUP_SHIFT          (16U)
/*! RX_WARMUP - Receive Warmup Time */
#define GENFSK_XCVR_CFG_RX_WARMUP(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_XCVR_CFG_RX_WARMUP_SHIFT)) & GENFSK_XCVR_CFG_RX_WARMUP_MASK)
/*! @} */

/*! @name CHANNEL_NUM - CHANNEL NUMBER */
/*! @{ */

#define GENFSK_CHANNEL_NUM_CHANNEL_NUM_MASK      (0x7FU)
#define GENFSK_CHANNEL_NUM_CHANNEL_NUM_SHIFT     (0U)
/*! CHANNEL_NUM - Channel Number */
#define GENFSK_CHANNEL_NUM_CHANNEL_NUM(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_CHANNEL_NUM_CHANNEL_NUM_SHIFT)) & GENFSK_CHANNEL_NUM_CHANNEL_NUM_MASK)
/*! @} */

/*! @name TX_POWER - TRANSMIT POWER */
/*! @{ */

#define GENFSK_TX_POWER_TX_POWER_MASK            (0x3FU)
#define GENFSK_TX_POWER_TX_POWER_SHIFT           (0U)
/*! TX_POWER - Transmit Power */
#define GENFSK_TX_POWER_TX_POWER(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_TX_POWER_TX_POWER_SHIFT)) & GENFSK_TX_POWER_TX_POWER_MASK)
/*! @} */

/*! @name NTW_ADR_CTRL - NETWORK ADDRESS CONTROL */
/*! @{ */

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_MASK      (0xFU)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_SHIFT     (0U)
/*! NTW_ADR_EN - Network Address Enable
 *  0b0001..Enable Network Address 0 for correlation
 *  0b0010..Enable Network Address 1 for correlation
 *  0b0100..Enable Network Address 2 for correlation
 *  0b1000..Enable Network Address 3 for correlation
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_EN(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_EN_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_MASK     (0xF0U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_SHIFT    (4U)
/*! NTW_ADR_MCH - Network Address Match
 *  0b0001..Network Address 0 has matched
 *  0b0010..Network Address 1 has matched
 *  0b0100..Network Address 2 has matched
 *  0b1000..Network Address 3 has matched
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_MCH_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR0_SZ_MASK     (0x300U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR0_SZ_SHIFT    (8U)
/*! NTW_ADR0_SZ - Network Address 0 Size
 *  0b00..Network Address 0 requires a 8-bit correlation
 *  0b01..Network Address 0 requires a 16-bit correlation
 *  0b10..Network Address 0 requires a 24-bit correlation
 *  0b11..Network Address 0 requires a 32-bit correlation
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR0_SZ(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR0_SZ_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR0_SZ_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR1_SZ_MASK     (0xC00U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR1_SZ_SHIFT    (10U)
/*! NTW_ADR1_SZ - Network Address 1 Size
 *  0b00..Network Address 1 requires a 8-bit correlation
 *  0b01..Network Address 1 requires a 16-bit correlation
 *  0b10..Network Address 1 requires a 24-bit correlation
 *  0b11..Network Address 1 requires a 32-bit correlation
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR1_SZ(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR1_SZ_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR1_SZ_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR2_SZ_MASK     (0x3000U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR2_SZ_SHIFT    (12U)
/*! NTW_ADR2_SZ - Network Address 2 Size
 *  0b00..Network Address 2 requires a 8-bit correlation
 *  0b01..Network Address 2 requires a 16-bit correlation
 *  0b10..Network Address 2 requires a 24-bit correlation
 *  0b11..Network Address 2 requires a 32-bit correlation
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR2_SZ(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR2_SZ_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR2_SZ_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR3_SZ_MASK     (0xC000U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR3_SZ_SHIFT    (14U)
/*! NTW_ADR3_SZ - Network Address 3 Size
 *  0b00..Network Address 3 requires a 8-bit correlation
 *  0b01..Network Address 3 requires a 16-bit correlation
 *  0b10..Network Address 3 requires a 24-bit correlation
 *  0b11..Network Address 3 requires a 32-bit correlation
 */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR3_SZ(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR3_SZ_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR3_SZ_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR0_MASK    (0x70000U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR0_SHIFT   (16U)
/*! NTW_ADR_THR0 - Network Address 0 Threshold */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR0(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_THR0_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_THR0_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR1_MASK    (0x700000U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR1_SHIFT   (20U)
/*! NTW_ADR_THR1 - Network Address 1 Threshold */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR1(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_THR1_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_THR1_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR2_MASK    (0x7000000U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR2_SHIFT   (24U)
/*! NTW_ADR_THR2 - Network Address 2 Threshold */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR2(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_THR2_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_THR2_MASK)

#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR3_MASK    (0x70000000U)
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR3_SHIFT   (28U)
/*! NTW_ADR_THR3 - Network Address 3 Threshold */
#define GENFSK_NTW_ADR_CTRL_NTW_ADR_THR3(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_CTRL_NTW_ADR_THR3_SHIFT)) & GENFSK_NTW_ADR_CTRL_NTW_ADR_THR3_MASK)
/*! @} */

/*! @name NTW_ADR_0 - NETWORK ADDRESS 0 */
/*! @{ */

#define GENFSK_NTW_ADR_0_NTW_ADR_0_MASK          (0xFFFFFFFFU)
#define GENFSK_NTW_ADR_0_NTW_ADR_0_SHIFT         (0U)
/*! NTW_ADR_0 - Network Address 0 */
#define GENFSK_NTW_ADR_0_NTW_ADR_0(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_0_NTW_ADR_0_SHIFT)) & GENFSK_NTW_ADR_0_NTW_ADR_0_MASK)
/*! @} */

/*! @name NTW_ADR_1 - NETWORK ADDRESS 1 */
/*! @{ */

#define GENFSK_NTW_ADR_1_NTW_ADR_1_MASK          (0xFFFFFFFFU)
#define GENFSK_NTW_ADR_1_NTW_ADR_1_SHIFT         (0U)
/*! NTW_ADR_1 - Network Address 1 */
#define GENFSK_NTW_ADR_1_NTW_ADR_1(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_1_NTW_ADR_1_SHIFT)) & GENFSK_NTW_ADR_1_NTW_ADR_1_MASK)
/*! @} */

/*! @name NTW_ADR_2 - NETWORK ADDRESS 2 */
/*! @{ */

#define GENFSK_NTW_ADR_2_NTW_ADR_2_MASK          (0xFFFFFFFFU)
#define GENFSK_NTW_ADR_2_NTW_ADR_2_SHIFT         (0U)
/*! NTW_ADR_2 - Network Address 2 */
#define GENFSK_NTW_ADR_2_NTW_ADR_2(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_2_NTW_ADR_2_SHIFT)) & GENFSK_NTW_ADR_2_NTW_ADR_2_MASK)
/*! @} */

/*! @name NTW_ADR_3 - NETWORK ADDRESS 3 */
/*! @{ */

#define GENFSK_NTW_ADR_3_NTW_ADR_3_MASK          (0xFFFFFFFFU)
#define GENFSK_NTW_ADR_3_NTW_ADR_3_SHIFT         (0U)
/*! NTW_ADR_3 - Network Address 2 */
#define GENFSK_NTW_ADR_3_NTW_ADR_3(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_NTW_ADR_3_NTW_ADR_3_SHIFT)) & GENFSK_NTW_ADR_3_NTW_ADR_3_MASK)
/*! @} */

/*! @name RX_WATERMARK - RECEIVE WATERMARK */
/*! @{ */

#define GENFSK_RX_WATERMARK_RX_WATERMARK_MASK    (0x1FFFU)
#define GENFSK_RX_WATERMARK_RX_WATERMARK_SHIFT   (0U)
/*! RX_WATERMARK - Receive Watermark */
#define GENFSK_RX_WATERMARK_RX_WATERMARK(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_WATERMARK_RX_WATERMARK_SHIFT)) & GENFSK_RX_WATERMARK_RX_WATERMARK_MASK)

#define GENFSK_RX_WATERMARK_BYTE_COUNTER_MASK    (0x1FFF0000U)
#define GENFSK_RX_WATERMARK_BYTE_COUNTER_SHIFT   (16U)
/*! BYTE_COUNTER - Byte Counter */
#define GENFSK_RX_WATERMARK_BYTE_COUNTER(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_RX_WATERMARK_BYTE_COUNTER_SHIFT)) & GENFSK_RX_WATERMARK_BYTE_COUNTER_MASK)
/*! @} */

/*! @name DSM_CTRL - DSM CONTROL */
/*! @{ */

#define GENFSK_DSM_CTRL_GENERIC_FSK_SLEEP_EN_MASK (0x1U)
#define GENFSK_DSM_CTRL_GENERIC_FSK_SLEEP_EN_SHIFT (0U)
/*! GENERIC_FSK_SLEEP_EN - GENERIC_FSK DSM Sleep Enable */
#define GENFSK_DSM_CTRL_GENERIC_FSK_SLEEP_EN(x)  (((uint32_t)(((uint32_t)(x)) << GENFSK_DSM_CTRL_GENERIC_FSK_SLEEP_EN_SHIFT)) & GENFSK_DSM_CTRL_GENERIC_FSK_SLEEP_EN_MASK)
/*! @} */

/*! @name PART_ID - PART ID */
/*! @{ */

#define GENFSK_PART_ID_PART_ID_MASK              (0xFFU)
#define GENFSK_PART_ID_PART_ID_SHIFT             (0U)
/*! PART_ID - Part ID */
#define GENFSK_PART_ID_PART_ID(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_PART_ID_PART_ID_SHIFT)) & GENFSK_PART_ID_PART_ID_MASK)
/*! @} */

/*! @name PACKET_CFG - PACKET CONFIGURATION */
/*! @{ */

#define GENFSK_PACKET_CFG_LENGTH_SZ_MASK         (0x1FU)
#define GENFSK_PACKET_CFG_LENGTH_SZ_SHIFT        (0U)
/*! LENGTH_SZ - LENGTH Size */
#define GENFSK_PACKET_CFG_LENGTH_SZ(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LENGTH_SZ_SHIFT)) & GENFSK_PACKET_CFG_LENGTH_SZ_MASK)

#define GENFSK_PACKET_CFG_LENGTH_BIT_ORD_MASK    (0x20U)
#define GENFSK_PACKET_CFG_LENGTH_BIT_ORD_SHIFT   (5U)
/*! LENGTH_BIT_ORD - LENGTH Bit Order
 *  0b0..LS Bit First
 *  0b1..MS Bit First
 */
#define GENFSK_PACKET_CFG_LENGTH_BIT_ORD(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LENGTH_BIT_ORD_SHIFT)) & GENFSK_PACKET_CFG_LENGTH_BIT_ORD_MASK)

#define GENFSK_PACKET_CFG_SYNC_ADDR_SZ_MASK      (0xC0U)
#define GENFSK_PACKET_CFG_SYNC_ADDR_SZ_SHIFT     (6U)
/*! SYNC_ADDR_SZ - Sync Address Size */
#define GENFSK_PACKET_CFG_SYNC_ADDR_SZ(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_SYNC_ADDR_SZ_SHIFT)) & GENFSK_PACKET_CFG_SYNC_ADDR_SZ_MASK)

#define GENFSK_PACKET_CFG_LENGTH_ADJ_MASK        (0x3F00U)
#define GENFSK_PACKET_CFG_LENGTH_ADJ_SHIFT       (8U)
/*! LENGTH_ADJ - Length Adjustment */
#define GENFSK_PACKET_CFG_LENGTH_ADJ(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LENGTH_ADJ_SHIFT)) & GENFSK_PACKET_CFG_LENGTH_ADJ_MASK)

#define GENFSK_PACKET_CFG_LENGTH_FAIL_MASK       (0x8000U)
#define GENFSK_PACKET_CFG_LENGTH_FAIL_SHIFT      (15U)
/*! LENGTH_FAIL - Maximum Length Violated Status Bit */
#define GENFSK_PACKET_CFG_LENGTH_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_LENGTH_FAIL_SHIFT)) & GENFSK_PACKET_CFG_LENGTH_FAIL_MASK)

#define GENFSK_PACKET_CFG_H0_SZ_MASK             (0x1F0000U)
#define GENFSK_PACKET_CFG_H0_SZ_SHIFT            (16U)
/*! H0_SZ - H0 Size */
#define GENFSK_PACKET_CFG_H0_SZ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H0_SZ_SHIFT)) & GENFSK_PACKET_CFG_H0_SZ_MASK)

#define GENFSK_PACKET_CFG_H0_FAIL_MASK           (0x800000U)
#define GENFSK_PACKET_CFG_H0_FAIL_SHIFT          (23U)
/*! H0_FAIL - H0 Violated Status Bit */
#define GENFSK_PACKET_CFG_H0_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H0_FAIL_SHIFT)) & GENFSK_PACKET_CFG_H0_FAIL_MASK)

#define GENFSK_PACKET_CFG_H1_SZ_MASK             (0x1F000000U)
#define GENFSK_PACKET_CFG_H1_SZ_SHIFT            (24U)
/*! H1_SZ - H1 Size */
#define GENFSK_PACKET_CFG_H1_SZ(x)               (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H1_SZ_SHIFT)) & GENFSK_PACKET_CFG_H1_SZ_MASK)

#define GENFSK_PACKET_CFG_H1_FAIL_MASK           (0x80000000U)
#define GENFSK_PACKET_CFG_H1_FAIL_SHIFT          (31U)
/*! H1_FAIL - H1 Violated Status Bit */
#define GENFSK_PACKET_CFG_H1_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_PACKET_CFG_H1_FAIL_SHIFT)) & GENFSK_PACKET_CFG_H1_FAIL_MASK)
/*! @} */

/*! @name H0_CFG - H0 CONFIGURATION */
/*! @{ */

#define GENFSK_H0_CFG_H0_MATCH_MASK              (0xFFFFU)
#define GENFSK_H0_CFG_H0_MATCH_SHIFT             (0U)
/*! H0_MATCH - H0 Match Register */
#define GENFSK_H0_CFG_H0_MATCH(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_H0_CFG_H0_MATCH_SHIFT)) & GENFSK_H0_CFG_H0_MATCH_MASK)

#define GENFSK_H0_CFG_H0_MASK_MASK               (0xFFFF0000U)
#define GENFSK_H0_CFG_H0_MASK_SHIFT              (16U)
/*! H0_MASK - H0 Mask Register */
#define GENFSK_H0_CFG_H0_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << GENFSK_H0_CFG_H0_MASK_SHIFT)) & GENFSK_H0_CFG_H0_MASK_MASK)
/*! @} */

/*! @name H1_CFG - H1 CONFIGURATION */
/*! @{ */

#define GENFSK_H1_CFG_H1_MATCH_MASK              (0xFFFFU)
#define GENFSK_H1_CFG_H1_MATCH_SHIFT             (0U)
/*! H1_MATCH - H1 Match Register */
#define GENFSK_H1_CFG_H1_MATCH(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_H1_CFG_H1_MATCH_SHIFT)) & GENFSK_H1_CFG_H1_MATCH_MASK)

#define GENFSK_H1_CFG_H1_MASK_MASK               (0xFFFF0000U)
#define GENFSK_H1_CFG_H1_MASK_SHIFT              (16U)
/*! H1_MASK - H1 Mask Register */
#define GENFSK_H1_CFG_H1_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << GENFSK_H1_CFG_H1_MASK_SHIFT)) & GENFSK_H1_CFG_H1_MASK_MASK)
/*! @} */

/*! @name CRC_CFG - CRC CONFIGURATION */
/*! @{ */

#define GENFSK_CRC_CFG_CRC_SZ_MASK               (0x7U)
#define GENFSK_CRC_CFG_CRC_SZ_SHIFT              (0U)
/*! CRC_SZ - CRC Size (in octets) */
#define GENFSK_CRC_CFG_CRC_SZ(x)                 (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_CFG_CRC_SZ_SHIFT)) & GENFSK_CRC_CFG_CRC_SZ_MASK)

#define GENFSK_CRC_CFG_CRC_START_BYTE_MASK       (0xF00U)
#define GENFSK_CRC_CFG_CRC_START_BYTE_SHIFT      (8U)
/*! CRC_START_BYTE - Configure CRC Start Point */
#define GENFSK_CRC_CFG_CRC_START_BYTE(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_CFG_CRC_START_BYTE_SHIFT)) & GENFSK_CRC_CFG_CRC_START_BYTE_MASK)

#define GENFSK_CRC_CFG_CRC_REF_IN_MASK           (0x10000U)
#define GENFSK_CRC_CFG_CRC_REF_IN_SHIFT          (16U)
/*! CRC_REF_IN - CRC Reflect In
 *  0b0..do not manipulate input data stream
 *  0b1..reflect each byte in the input stream bitwise
 */
#define GENFSK_CRC_CFG_CRC_REF_IN(x)             (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_CFG_CRC_REF_IN_SHIFT)) & GENFSK_CRC_CFG_CRC_REF_IN_MASK)

#define GENFSK_CRC_CFG_CRC_REF_OUT_MASK          (0x20000U)
#define GENFSK_CRC_CFG_CRC_REF_OUT_SHIFT         (17U)
/*! CRC_REF_OUT - CRC Reflect Out
 *  0b0..do not manipulate CRC result
 *  0b1..CRC result is to be reflected bitwise (operated on entire word)
 */
#define GENFSK_CRC_CFG_CRC_REF_OUT(x)            (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_CFG_CRC_REF_OUT_SHIFT)) & GENFSK_CRC_CFG_CRC_REF_OUT_MASK)

#define GENFSK_CRC_CFG_CRC_BYTE_ORD_MASK         (0x40000U)
#define GENFSK_CRC_CFG_CRC_BYTE_ORD_SHIFT        (18U)
/*! CRC_BYTE_ORD - CRC Byte Order
 *  0b0..LS Byte First
 *  0b1..MS Byte First
 */
#define GENFSK_CRC_CFG_CRC_BYTE_ORD(x)           (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_CFG_CRC_BYTE_ORD_SHIFT)) & GENFSK_CRC_CFG_CRC_BYTE_ORD_MASK)
/*! @} */

/*! @name CRC_INIT - CRC INITIALIZATION */
/*! @{ */

#define GENFSK_CRC_INIT_CRC_SEED_MASK            (0xFFFFFFFFU)
#define GENFSK_CRC_INIT_CRC_SEED_SHIFT           (0U)
/*! CRC_SEED - CRC Seed Value */
#define GENFSK_CRC_INIT_CRC_SEED(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_INIT_CRC_SEED_SHIFT)) & GENFSK_CRC_INIT_CRC_SEED_MASK)
/*! @} */

/*! @name CRC_POLY - CRC POLYNOMIAL */
/*! @{ */

#define GENFSK_CRC_POLY_CRC_POLY_MASK            (0xFFFFFFFFU)
#define GENFSK_CRC_POLY_CRC_POLY_SHIFT           (0U)
/*! CRC_POLY - CRC Polynomial. */
#define GENFSK_CRC_POLY_CRC_POLY(x)              (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_POLY_CRC_POLY_SHIFT)) & GENFSK_CRC_POLY_CRC_POLY_MASK)
/*! @} */

/*! @name CRC_XOR_OUT - CRC XOR OUT */
/*! @{ */

#define GENFSK_CRC_XOR_OUT_CRC_XOR_OUT_MASK      (0xFFFFFFFFU)
#define GENFSK_CRC_XOR_OUT_CRC_XOR_OUT_SHIFT     (0U)
/*! CRC_XOR_OUT - CRC XOR OUT Register */
#define GENFSK_CRC_XOR_OUT_CRC_XOR_OUT(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_CRC_XOR_OUT_CRC_XOR_OUT_SHIFT)) & GENFSK_CRC_XOR_OUT_CRC_XOR_OUT_MASK)
/*! @} */

/*! @name WHITEN_CFG - WHITENER CONFIGURATION */
/*! @{ */

#define GENFSK_WHITEN_CFG_WHITEN_START_MASK      (0x3U)
#define GENFSK_WHITEN_CFG_WHITEN_START_SHIFT     (0U)
/*! WHITEN_START - Configure Whitener Start Point
 *  0b00..no whitening
 *  0b01..start whitening at start-of-H0
 *  0b10..start whitening at start-of-H1 but only if LENGTH > WHITEN_SZ_THR
 *  0b11..start whitening at start-of-payload but only if LENGTH > WHITEN_SZ_THR
 */
#define GENFSK_WHITEN_CFG_WHITEN_START(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_START_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_START_MASK)

#define GENFSK_WHITEN_CFG_WHITEN_END_MASK        (0x4U)
#define GENFSK_WHITEN_CFG_WHITEN_END_SHIFT       (2U)
/*! WHITEN_END - Configure end-of-whitening
 *  0b0..end whiten at end-of-payload
 *  0b1..end whiten at end-of-crc
 */
#define GENFSK_WHITEN_CFG_WHITEN_END(x)          (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_END_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_END_MASK)

#define GENFSK_WHITEN_CFG_WHITEN_B4_CRC_MASK     (0x8U)
#define GENFSK_WHITEN_CFG_WHITEN_B4_CRC_SHIFT    (3U)
/*! WHITEN_B4_CRC - Congifure for Whitening-before-CRC
 *  0b0..CRC before whiten/de-whiten
 *  0b1..Whiten/de-whiten before CRC
 */
#define GENFSK_WHITEN_CFG_WHITEN_B4_CRC(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_B4_CRC_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_B4_CRC_MASK)

#define GENFSK_WHITEN_CFG_WHITEN_POLY_TYPE_MASK  (0x10U)
#define GENFSK_WHITEN_CFG_WHITEN_POLY_TYPE_SHIFT (4U)
/*! WHITEN_POLY_TYPE - Whiten Polynomial Type */
#define GENFSK_WHITEN_CFG_WHITEN_POLY_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_POLY_TYPE_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_POLY_TYPE_MASK)

#define GENFSK_WHITEN_CFG_WHITEN_REF_IN_MASK     (0x20U)
#define GENFSK_WHITEN_CFG_WHITEN_REF_IN_SHIFT    (5U)
/*! WHITEN_REF_IN - Whiten Reflect Input */
#define GENFSK_WHITEN_CFG_WHITEN_REF_IN(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_REF_IN_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_REF_IN_MASK)

#define GENFSK_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_MASK (0x40U)
#define GENFSK_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_SHIFT (6U)
/*! WHITEN_PAYLOAD_REINIT - Configure for Whitener re-initialization
 *  0b0..Don't re-initialize Whitener LFSR at start-of-payload
 *  0b1..Re-initialize Whitener LFSR at start-of-payload
 */
#define GENFSK_WHITEN_CFG_WHITEN_PAYLOAD_REINIT(x) (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_PAYLOAD_REINIT_MASK)

#define GENFSK_WHITEN_CFG_WHITEN_SIZE_MASK       (0xF00U)
#define GENFSK_WHITEN_CFG_WHITEN_SIZE_SHIFT      (8U)
/*! WHITEN_SIZE - Length of Whitener LFSR */
#define GENFSK_WHITEN_CFG_WHITEN_SIZE(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_SIZE_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_SIZE_MASK)

#define GENFSK_WHITEN_CFG_MANCHESTER_EN_MASK     (0x1000U)
#define GENFSK_WHITEN_CFG_MANCHESTER_EN_SHIFT    (12U)
/*! MANCHESTER_EN - Configure for Manchester Encoding/Decoding
 *  0b0..Disable Manchester encoding (TX) and decoding (RX)
 *  0b1..Enable Manchester encoding (TX) and decoding (RX)
 */
#define GENFSK_WHITEN_CFG_MANCHESTER_EN(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_MANCHESTER_EN_SHIFT)) & GENFSK_WHITEN_CFG_MANCHESTER_EN_MASK)

#define GENFSK_WHITEN_CFG_MANCHESTER_INV_MASK    (0x2000U)
#define GENFSK_WHITEN_CFG_MANCHESTER_INV_SHIFT   (13U)
/*! MANCHESTER_INV - Configure for Inverted Manchester Encoding
 *  0b0..Manchester coding as per 802.3
 *  0b1..Manchester coding as per 802.3 but with the encoding signal inverted
 */
#define GENFSK_WHITEN_CFG_MANCHESTER_INV(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_MANCHESTER_INV_SHIFT)) & GENFSK_WHITEN_CFG_MANCHESTER_INV_MASK)

#define GENFSK_WHITEN_CFG_MANCHESTER_START_MASK  (0x4000U)
#define GENFSK_WHITEN_CFG_MANCHESTER_START_SHIFT (14U)
/*! MANCHESTER_START - Configure Manchester Encoding Start Point
 *  0b0..Start Manchester coding at start-of-payload
 *  0b1..Start Manchester coding at start-of-header
 */
#define GENFSK_WHITEN_CFG_MANCHESTER_START(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_MANCHESTER_START_SHIFT)) & GENFSK_WHITEN_CFG_MANCHESTER_START_MASK)

#define GENFSK_WHITEN_CFG_WHITEN_INIT_MASK       (0x1FF0000U)
#define GENFSK_WHITEN_CFG_WHITEN_INIT_SHIFT      (16U)
/*! WHITEN_INIT - Initialization Value for Whitening/De-whitening */
#define GENFSK_WHITEN_CFG_WHITEN_INIT(x)         (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_CFG_WHITEN_INIT_SHIFT)) & GENFSK_WHITEN_CFG_WHITEN_INIT_MASK)
/*! @} */

/*! @name WHITEN_POLY - WHITENER POLYNOMIAL */
/*! @{ */

#define GENFSK_WHITEN_POLY_WHITEN_POLY_MASK      (0x1FFU)
#define GENFSK_WHITEN_POLY_WHITEN_POLY_SHIFT     (0U)
/*! WHITEN_POLY - Whitener Polynomial */
#define GENFSK_WHITEN_POLY_WHITEN_POLY(x)        (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_POLY_WHITEN_POLY_SHIFT)) & GENFSK_WHITEN_POLY_WHITEN_POLY_MASK)
/*! @} */

/*! @name WHITEN_SZ_THR - WHITENER SIZE THRESHOLD */
/*! @{ */

#define GENFSK_WHITEN_SZ_THR_WHITEN_SZ_THR_MASK  (0xFFFU)
#define GENFSK_WHITEN_SZ_THR_WHITEN_SZ_THR_SHIFT (0U)
/*! WHITEN_SZ_THR - Whitener Size Threshold */
#define GENFSK_WHITEN_SZ_THR_WHITEN_SZ_THR(x)    (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_SZ_THR_WHITEN_SZ_THR_SHIFT)) & GENFSK_WHITEN_SZ_THR_WHITEN_SZ_THR_MASK)

#define GENFSK_WHITEN_SZ_THR_LENGTH_MAX_MASK     (0x7F0000U)
#define GENFSK_WHITEN_SZ_THR_LENGTH_MAX_SHIFT    (16U)
/*! LENGTH_MAX - Maximum Length for Received Packets */
#define GENFSK_WHITEN_SZ_THR_LENGTH_MAX(x)       (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_SZ_THR_LENGTH_MAX_SHIFT)) & GENFSK_WHITEN_SZ_THR_LENGTH_MAX_MASK)

#define GENFSK_WHITEN_SZ_THR_REC_BAD_PKT_MASK    (0x800000U)
#define GENFSK_WHITEN_SZ_THR_REC_BAD_PKT_SHIFT   (23U)
/*! REC_BAD_PKT - Receive Bad Packets
 *  0b0..packets which fail H0, H1, or LENGTH_MAX result in an automatic recycle after the header is received and parsed
 *  0b1..packets which fail H0, H1, or LENGTH_MAX are received in their entirety
 */
#define GENFSK_WHITEN_SZ_THR_REC_BAD_PKT(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_WHITEN_SZ_THR_REC_BAD_PKT_SHIFT)) & GENFSK_WHITEN_SZ_THR_REC_BAD_PKT_MASK)
/*! @} */

/*! @name BITRATE - BIT RATE */
/*! @{ */

#define GENFSK_BITRATE_BITRATE_MASK              (0x3U)
#define GENFSK_BITRATE_BITRATE_SHIFT             (0U)
/*! BITRATE - Bit Rate
 *  0b00..1Mbit/sec
 *  0b01..500Kbit/sec
 *  0b10..250Kbit/sec (not supported if WHITEN_CFG[MANCHESTER_EN]=1
 *  0b11..Reserved
 */
#define GENFSK_BITRATE_BITRATE(x)                (((uint32_t)(((uint32_t)(x)) << GENFSK_BITRATE_BITRATE_SHIFT)) & GENFSK_BITRATE_BITRATE_MASK)
/*! @} */

/*! @name PB_PARTITION - PACKET BUFFER PARTITION POINT */
/*! @{ */

#define GENFSK_PB_PARTITION_PB_PARTITION_MASK    (0x7FFU)
#define GENFSK_PB_PARTITION_PB_PARTITION_SHIFT   (0U)
/*! PB_PARTITION - Packet Buffer Partition Point */
#define GENFSK_PB_PARTITION_PB_PARTITION(x)      (((uint32_t)(((uint32_t)(x)) << GENFSK_PB_PARTITION_PB_PARTITION_SHIFT)) & GENFSK_PB_PARTITION_PB_PARTITION_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GENFSK_Register_Masks */


/*!
 * @}
 */ /* end of group GENFSK_Peripheral_Access_Layer */


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


#endif  /* GENFSK_H_ */

