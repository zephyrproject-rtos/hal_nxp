/*
** ###################################################################
**     Processors:          MKE14Z32VFP4
**                          MKE14Z32VLD4
**                          MKE14Z32VLF4
**                          MKE14Z64VFP4
**                          MKE14Z64VLD4
**                          MKE14Z64VLF4
**                          MKE15Z32VFP4
**                          MKE15Z32VLD4
**                          MKE15Z32VLF4
**                          MKE15Z64VFP4
**                          MKE15Z64VLD4
**                          MKE15Z64VLF4
**                          MKE16Z32VLD4
**                          MKE16Z32VLF4
**                          MKE16Z64VLD4
**                          MKE16Z64VLF4
**
**     Version:             rev. 4.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MSCAN
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-05-09)
**         Initial version.
**     - rev. 2.0 (2018-09-17)
**         Based on rev1 RM.
**     - rev. 3.0 (2020-01-22)
**         Add 40 pins part numbers.
**     - rev. 4.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MSCAN.h
 * @version 4.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MSCAN
 *
 * CMSIS Peripheral Access Layer for MSCAN
 */

#if !defined(PERI_MSCAN_H_)
#define PERI_MSCAN_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z32VFP4) || defined(CPU_MKE14Z32VLD4) || defined(CPU_MKE14Z32VLF4) || defined(CPU_MKE14Z64VFP4) || defined(CPU_MKE14Z64VLD4) || defined(CPU_MKE14Z64VLF4))
#include "MKE14Z4_COMMON.h"
#elif (defined(CPU_MKE15Z32VFP4) || defined(CPU_MKE15Z32VLD4) || defined(CPU_MKE15Z32VLF4) || defined(CPU_MKE15Z64VFP4) || defined(CPU_MKE15Z64VLD4) || defined(CPU_MKE15Z64VLF4))
#include "MKE15Z4_COMMON.h"
#elif (defined(CPU_MKE16Z32VLD4) || defined(CPU_MKE16Z32VLF4) || defined(CPU_MKE16Z64VLD4) || defined(CPU_MKE16Z64VLF4))
#include "MKE16Z4_COMMON.h"
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
   -- MSCAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCAN_Peripheral_Access_Layer MSCAN Peripheral Access Layer
 * @{
 */

/** MSCAN - Size of Registers Arrays */
#define MSCAN_CANIDAR_BANK_1_COUNT                4u
#define MSCAN_CANIDMR_BANK_1_COUNT                4u
#define MSCAN_CANIDAR_BANK_2_COUNT                4u
#define MSCAN_CANIDMR_BANK_2_COUNT                4u
#define MSCAN_REDSR_COUNT                         8u
#define MSCAN_TEDSR_COUNT                         8u

/** MSCAN - Register Layout Typedef */
typedef struct {
  __IO uint8_t CANCTL0;                            /**< MSCAN Control Register 0, offset: 0x0 */
  __IO uint8_t CANCTL1;                            /**< MSCAN Control Register 1, offset: 0x1 */
  __IO uint8_t CANBTR0;                            /**< MSCAN Bus Timing Register 0, offset: 0x2 */
  __IO uint8_t CANBTR1;                            /**< MSCAN Bus Timing Register 1, offset: 0x3 */
  __IO uint8_t CANRFLG;                            /**< MSCAN Receiver Flag Register, offset: 0x4 */
  __IO uint8_t CANRIER;                            /**< MSCAN Receiver Interrupt Enable Register, offset: 0x5 */
  __IO uint8_t CANTFLG;                            /**< MSCAN Transmitter Flag Register, offset: 0x6 */
  __IO uint8_t CANTIER;                            /**< MSCAN Transmitter Interrupt Enable Register, offset: 0x7 */
  __IO uint8_t CANTARQ;                            /**< MSCAN Transmitter Message Abort Request Register, offset: 0x8 */
  __I  uint8_t CANTAAK;                            /**< MSCAN Transmitter Message Abort Acknowledge Register, offset: 0x9 */
  __IO uint8_t CANTBSEL;                           /**< MSCAN Transmit Buffer Selection Register, offset: 0xA */
  __IO uint8_t CANIDAC;                            /**< MSCAN Identifier Acceptance Control Register, offset: 0xB */
       uint8_t RESERVED_0[1];
  __IO uint8_t CANMISC;                            /**< MSCAN Miscellaneous Register, offset: 0xD */
  __I  uint8_t CANRXERR;                           /**< MSCAN Receive Error Counter, offset: 0xE */
  __I  uint8_t CANTXERR;                           /**< MSCAN Transmit Error Counter, offset: 0xF */
  __IO uint8_t CANIDAR_BANK_1[MSCAN_CANIDAR_BANK_1_COUNT]; /**< MSCAN Identifier Acceptance Register n of First Bank, array offset: 0x10, array step: 0x1 */
  __IO uint8_t CANIDMR_BANK_1[MSCAN_CANIDMR_BANK_1_COUNT]; /**< MSCAN Identifier Mask Register n of First Bank, array offset: 0x14, array step: 0x1 */
  __IO uint8_t CANIDAR_BANK_2[MSCAN_CANIDAR_BANK_2_COUNT]; /**< MSCAN Identifier Acceptance Register n of Second Bank, array offset: 0x18, array step: 0x1 */
  __IO uint8_t CANIDMR_BANK_2[MSCAN_CANIDMR_BANK_2_COUNT]; /**< MSCAN Identifier Mask Register n of Second Bank, array offset: 0x1C, array step: 0x1 */
  union {                                          /* offset: 0x20 */
    __I  uint8_t REIDR0;                             /**< Receive Extended Identifier Register 0, offset: 0x20 */
    __I  uint8_t RSIDR0;                             /**< Receive Standard Identifier Register 0, offset: 0x20 */
  };
  union {                                          /* offset: 0x21 */
    __I  uint8_t REIDR1;                             /**< Receive Extended Identifier Register 1, offset: 0x21 */
    __I  uint8_t RSIDR1;                             /**< Receive Standard Identifier Register 1, offset: 0x21 */
  };
  __I  uint8_t REIDR2;                             /**< Receive Extended Identifier Register 2, offset: 0x22 */
  __I  uint8_t REIDR3;                             /**< Receive Extended Identifier Register 3, offset: 0x23 */
  __I  uint8_t REDSR[MSCAN_REDSR_COUNT];           /**< Receive Extended Data Segment Register N, array offset: 0x24, array step: 0x1 */
  __I  uint8_t RDLR;                               /**< Receive Data Length Register, offset: 0x2C */
       uint8_t RESERVED_1[1];
  __I  uint8_t RTSRH;                              /**< Receive Time Stamp Register High, offset: 0x2E */
  __I  uint8_t RTSRL;                              /**< Receive Time Stamp Register Low, offset: 0x2F */
  union {                                          /* offset: 0x30 */
    __IO uint8_t TEIDR0;                             /**< Transmit Extended Identifier Register 0, offset: 0x30 */
    __IO uint8_t TSIDR0;                             /**< Transmit Standard Identifier Register 0, offset: 0x30 */
  };
  union {                                          /* offset: 0x31 */
    __IO uint8_t TEIDR1;                             /**< Transmit Extended Identifier Register 1, offset: 0x31 */
    __IO uint8_t TSIDR1;                             /**< Transmit Standard Identifier Register 1, offset: 0x31 */
  };
  __IO uint8_t TEIDR2;                             /**< Transmit Extended Identifier Register 2, offset: 0x32 */
  __IO uint8_t TEIDR3;                             /**< Transmit Extended Identifier Register 3, offset: 0x33 */
  __IO uint8_t TEDSR[MSCAN_TEDSR_COUNT];           /**< Transmit Extended Data Segment Register N, array offset: 0x34, array step: 0x1 */
  __IO uint8_t TDLR;                               /**< Transmit Data Length Register, offset: 0x3C */
  __IO uint8_t TBPR;                               /**< Transmit Buffer Priority Register, offset: 0x3D */
  __I  uint8_t TTSRH;                              /**< Transmit Time Stamp Register High, offset: 0x3E */
  __I  uint8_t TTSRL;                              /**< Transmit Time Stamp Register Low, offset: 0x3F */
} MSCAN_Type;

/* ----------------------------------------------------------------------------
   -- MSCAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCAN_Register_Masks MSCAN Register Masks
 * @{
 */

/*! @name CANCTL0 - MSCAN Control Register 0 */
/*! @{ */

#define MSCAN_CANCTL0_INITRQ_MASK                (0x1U)
#define MSCAN_CANCTL0_INITRQ_SHIFT               (0U)
/*! INITRQ - Initialization Mode Request
 *  0b0..Normal operation.
 *  0b1..MSCAN in initialization mode.
 */
#define MSCAN_CANCTL0_INITRQ(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_INITRQ_SHIFT)) & MSCAN_CANCTL0_INITRQ_MASK)

#define MSCAN_CANCTL0_SLPRQ_MASK                 (0x2U)
#define MSCAN_CANCTL0_SLPRQ_SHIFT                (1U)
/*! SLPRQ - Sleep Mode Request
 *  0b0..Running - The MSCAN functions normally.
 *  0b1..Sleep mode request - The MSCAN enters sleep mode when CAN bus idle.
 */
#define MSCAN_CANCTL0_SLPRQ(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_SLPRQ_SHIFT)) & MSCAN_CANCTL0_SLPRQ_MASK)

#define MSCAN_CANCTL0_WUPE_MASK                  (0x4U)
#define MSCAN_CANCTL0_WUPE_SHIFT                 (2U)
/*! WUPE - WakeUp Enable
 *  0b0..Wakeup disabled - The MSCAN ignores traffic on CAN.
 *  0b1..Wakeup enabled - The MSCAN is able to restart.
 */
#define MSCAN_CANCTL0_WUPE(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_WUPE_SHIFT)) & MSCAN_CANCTL0_WUPE_MASK)

#define MSCAN_CANCTL0_TIME_MASK                  (0x8U)
#define MSCAN_CANCTL0_TIME_SHIFT                 (3U)
/*! TIME - Timer Enable
 *  0b0..Disable internal MSCAN timer.
 *  0b1..Enable internal MSCAN timer.
 */
#define MSCAN_CANCTL0_TIME(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_TIME_SHIFT)) & MSCAN_CANCTL0_TIME_MASK)

#define MSCAN_CANCTL0_SYNCH_MASK                 (0x10U)
#define MSCAN_CANCTL0_SYNCH_SHIFT                (4U)
/*! SYNCH - Synchronized Status
 *  0b0..MSCAN is not synchronized to the CAN bus.
 *  0b1..MSCAN is synchronized to the CAN bus.
 */
#define MSCAN_CANCTL0_SYNCH(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_SYNCH_SHIFT)) & MSCAN_CANCTL0_SYNCH_MASK)

#define MSCAN_CANCTL0_CSWAI_MASK                 (0x20U)
#define MSCAN_CANCTL0_CSWAI_SHIFT                (5U)
/*! CSWAI - CAN Stops in Wait Mode
 *  0b0..The module is not affected during wait mode.
 *  0b1..The module ceases to be clocked during wait mode.
 */
#define MSCAN_CANCTL0_CSWAI(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_CSWAI_SHIFT)) & MSCAN_CANCTL0_CSWAI_MASK)

#define MSCAN_CANCTL0_RXACT_MASK                 (0x40U)
#define MSCAN_CANCTL0_RXACT_SHIFT                (6U)
/*! RXACT - Receiver Active Status
 *  0b0..MSCAN is transmitting or idle.
 *  0b1..MSCAN is receiving a message, including when arbitration is lost.
 */
#define MSCAN_CANCTL0_RXACT(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_RXACT_SHIFT)) & MSCAN_CANCTL0_RXACT_MASK)

#define MSCAN_CANCTL0_RXFRM_MASK                 (0x80U)
#define MSCAN_CANCTL0_RXFRM_SHIFT                (7U)
/*! RXFRM - Received Frame Flag
 *  0b0..No valid message was received since last clearing this flag.
 *  0b1..A valid message was received since last clearing of this flag.
 */
#define MSCAN_CANCTL0_RXFRM(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL0_RXFRM_SHIFT)) & MSCAN_CANCTL0_RXFRM_MASK)
/*! @} */

/*! @name CANCTL1 - MSCAN Control Register 1 */
/*! @{ */

#define MSCAN_CANCTL1_INITAK_MASK                (0x1U)
#define MSCAN_CANCTL1_INITAK_SHIFT               (0U)
/*! INITAK - Initialization Mode Acknowledge
 *  0b0..Running - The MSCAN operates normally.
 *  0b1..Initialization mode active - The MSCAN has entered initialization mode.
 */
#define MSCAN_CANCTL1_INITAK(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_INITAK_SHIFT)) & MSCAN_CANCTL1_INITAK_MASK)

#define MSCAN_CANCTL1_SLPAK_MASK                 (0x2U)
#define MSCAN_CANCTL1_SLPAK_SHIFT                (1U)
/*! SLPAK - Sleep Mode Acknowledge
 *  0b0..Running - The MSCAN operates normally.
 *  0b1..Sleep mode active - The MSCAN has entered sleep mode.
 */
#define MSCAN_CANCTL1_SLPAK(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_SLPAK_SHIFT)) & MSCAN_CANCTL1_SLPAK_MASK)

#define MSCAN_CANCTL1_WUPM_MASK                  (0x4U)
#define MSCAN_CANCTL1_WUPM_SHIFT                 (2U)
/*! WUPM - WakeUp Mode
 *  0b0..MSCAN wakes on any dominant level on the CAN bus.
 *  0b1..MSCAN wakes only in case of a dominant pulse on the CAN bus that has a length of Twup.
 */
#define MSCAN_CANCTL1_WUPM(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_WUPM_SHIFT)) & MSCAN_CANCTL1_WUPM_MASK)

#define MSCAN_CANCTL1_BORM_MASK                  (0x8U)
#define MSCAN_CANCTL1_BORM_SHIFT                 (3U)
/*! BORM - Bus-Off Recovery Mode
 *  0b0..Automatic bus-off recovery (see Bosch CAN 2.0A/B protocol specification).
 *  0b1..Bus-off recovery upon user request.
 */
#define MSCAN_CANCTL1_BORM(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_BORM_SHIFT)) & MSCAN_CANCTL1_BORM_MASK)

#define MSCAN_CANCTL1_LISTEN_MASK                (0x10U)
#define MSCAN_CANCTL1_LISTEN_SHIFT               (4U)
/*! LISTEN - Listen Only Mode
 *  0b0..Normal operation.
 *  0b1..Listen only mode activated.
 */
#define MSCAN_CANCTL1_LISTEN(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_LISTEN_SHIFT)) & MSCAN_CANCTL1_LISTEN_MASK)

#define MSCAN_CANCTL1_LOOPB_MASK                 (0x20U)
#define MSCAN_CANCTL1_LOOPB_SHIFT                (5U)
/*! LOOPB - Loopback Self Test Mode
 *  0b0..Loopback self test disabled.
 *  0b1..Loopback self test enabled.
 */
#define MSCAN_CANCTL1_LOOPB(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_LOOPB_SHIFT)) & MSCAN_CANCTL1_LOOPB_MASK)

#define MSCAN_CANCTL1_CLKSRC_MASK                (0x40U)
#define MSCAN_CANCTL1_CLKSRC_SHIFT               (6U)
/*! CLKSRC - MSCAN Clock Source
 *  0b0..MSCAN clock source is the oscillator clock.
 *  0b1..MSCAN clock source is the bus clock.
 */
#define MSCAN_CANCTL1_CLKSRC(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_CLKSRC_SHIFT)) & MSCAN_CANCTL1_CLKSRC_MASK)

#define MSCAN_CANCTL1_CANE_MASK                  (0x80U)
#define MSCAN_CANCTL1_CANE_SHIFT                 (7U)
/*! CANE - MSCAN Enable
 *  0b0..MSCAN module is disabled.
 *  0b1..MSCAN module is enabled.
 */
#define MSCAN_CANCTL1_CANE(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_CANCTL1_CANE_SHIFT)) & MSCAN_CANCTL1_CANE_MASK)
/*! @} */

/*! @name CANBTR0 - MSCAN Bus Timing Register 0 */
/*! @{ */

#define MSCAN_CANBTR0_BRP_MASK                   (0x3FU)
#define MSCAN_CANBTR0_BRP_SHIFT                  (0U)
/*! BRP - Baud Rate Prescaler
 *  0b000000..1
 *  0b000001..2
 *  0b000010........
 *  0b000011........
 *  0b111110..63
 *  0b111111..64
 */
#define MSCAN_CANBTR0_BRP(x)                     (((uint8_t)(((uint8_t)(x)) << MSCAN_CANBTR0_BRP_SHIFT)) & MSCAN_CANBTR0_BRP_MASK)

#define MSCAN_CANBTR0_SJW_MASK                   (0xC0U)
#define MSCAN_CANBTR0_SJW_SHIFT                  (6U)
/*! SJW - Synchronization Jump Width
 *  0b00..1 Tq clock cycle.
 *  0b01..2 Tq clock cycles.
 *  0b10..3 Tq clock cycle.
 *  0b11..4 Tq clock cycles.
 */
#define MSCAN_CANBTR0_SJW(x)                     (((uint8_t)(((uint8_t)(x)) << MSCAN_CANBTR0_SJW_SHIFT)) & MSCAN_CANBTR0_SJW_MASK)
/*! @} */

/*! @name CANBTR1 - MSCAN Bus Timing Register 1 */
/*! @{ */

#define MSCAN_CANBTR1_TSEG1_MASK                 (0xFU)
#define MSCAN_CANBTR1_TSEG1_SHIFT                (0U)
/*! TSEG1 - Time Segment 1
 *  0b0000..1 Tq clock cycle (not valid)
 *  0b0001..2 Tq clock cycles (not valid)
 *  0b0010..3 Tq clock cycles (not valid)
 *  0b0011..4 Tq clock cycles
 *  0b1110..15 Tq clock cycles
 *  0b1111..16 Tq clock cycles
 */
#define MSCAN_CANBTR1_TSEG1(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANBTR1_TSEG1_SHIFT)) & MSCAN_CANBTR1_TSEG1_MASK)

#define MSCAN_CANBTR1_TSEG2_MASK                 (0x70U)
#define MSCAN_CANBTR1_TSEG2_SHIFT                (4U)
/*! TSEG2 - Time Segment 2
 *  0b000..1 Tq clock cycle (not valid)
 *  0b001..2 Tq clock cycles
 *  0b010..3 Tq clock cycles
 *  0b011..4 Tq clock cycles
 *  0b100..5 Tq clock cycles
 *  0b101..6 Tq clock cycles
 *  0b110..7 Tq clock cycles
 *  0b111..8 Tq clock cycles
 */
#define MSCAN_CANBTR1_TSEG2(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANBTR1_TSEG2_SHIFT)) & MSCAN_CANBTR1_TSEG2_MASK)

#define MSCAN_CANBTR1_SAMP_MASK                  (0x80U)
#define MSCAN_CANBTR1_SAMP_SHIFT                 (7U)
/*! SAMP - Sampling
 *  0b0..One sample per bit.
 *  0b1..Three samples per bit. In this case, PHASE_SEG1 must be at least 2 time quanta (Tq).
 */
#define MSCAN_CANBTR1_SAMP(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_CANBTR1_SAMP_SHIFT)) & MSCAN_CANBTR1_SAMP_MASK)
/*! @} */

/*! @name CANRFLG - MSCAN Receiver Flag Register */
/*! @{ */

#define MSCAN_CANRFLG_RXF_MASK                   (0x1U)
#define MSCAN_CANRFLG_RXF_SHIFT                  (0U)
/*! RXF - Receive Buffer Full Flag
 *  0b0..No new message available within the RxFG.
 *  0b1..The receiver FIFO is not empty. A new message is available in the RxFG.
 */
#define MSCAN_CANRFLG_RXF(x)                     (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRFLG_RXF_SHIFT)) & MSCAN_CANRFLG_RXF_MASK)

#define MSCAN_CANRFLG_OVRIF_MASK                 (0x2U)
#define MSCAN_CANRFLG_OVRIF_SHIFT                (1U)
/*! OVRIF - Overrun Interrupt Flag
 *  0b0..No data overrun condition.
 *  0b1..A data overrun detected.
 */
#define MSCAN_CANRFLG_OVRIF(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRFLG_OVRIF_SHIFT)) & MSCAN_CANRFLG_OVRIF_MASK)

#define MSCAN_CANRFLG_TSTAT_MASK                 (0xCU)
#define MSCAN_CANRFLG_TSTAT_SHIFT                (2U)
/*! TSTAT - Transmitter Status
 *  0b00..TxOK: 0<=transmit error counter<96
 *  0b01..TxWRN: 96<=transmit error counter<128
 *  0b10..TxERR: 128<=transmit error counter<256
 *  0b11..Bus-off: 256<=transmit error counter
 */
#define MSCAN_CANRFLG_TSTAT(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRFLG_TSTAT_SHIFT)) & MSCAN_CANRFLG_TSTAT_MASK)

#define MSCAN_CANRFLG_RSTAT_MASK                 (0x30U)
#define MSCAN_CANRFLG_RSTAT_SHIFT                (4U)
/*! RSTAT - Receiver Status
 *  0b00..RxOK: 0<=receive error counter<96
 *  0b01..RxWRN: 96<=receive error counter<128
 *  0b10..RxERR: 128<=receive error counter
 *  0b11..Bus-off: 256<=transmit error counter (Redundant Information for the most critical CAN bus status which
 *        is "bus-off". This only occurs if the Tx error counter exceeds a number of 255 errors. Bus-off affects the
 *        receiver state. As soon as the transmitter leaves its bus-off state the receiver state skips to RxOK
 *        too. Refer also to TSTAT[1:0] coding in this register. )
 */
#define MSCAN_CANRFLG_RSTAT(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRFLG_RSTAT_SHIFT)) & MSCAN_CANRFLG_RSTAT_MASK)

#define MSCAN_CANRFLG_CSCIF_MASK                 (0x40U)
#define MSCAN_CANRFLG_CSCIF_SHIFT                (6U)
/*! CSCIF - CAN Status Change Interrupt Flag
 *  0b0..No change in CAN bus status occurred since last interrupt.
 *  0b1..MSCAN changed current CAN bus status.
 */
#define MSCAN_CANRFLG_CSCIF(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRFLG_CSCIF_SHIFT)) & MSCAN_CANRFLG_CSCIF_MASK)

#define MSCAN_CANRFLG_WUPIF_MASK                 (0x80U)
#define MSCAN_CANRFLG_WUPIF_SHIFT                (7U)
/*! WUPIF - Wake-Up Interrupt Flag
 *  0b0..No wakeup activity observed while in sleep mode.
 *  0b1..MSCAN detected activity on the CAN bus and requested wakeup.
 */
#define MSCAN_CANRFLG_WUPIF(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRFLG_WUPIF_SHIFT)) & MSCAN_CANRFLG_WUPIF_MASK)
/*! @} */

/*! @name CANRIER - MSCAN Receiver Interrupt Enable Register */
/*! @{ */

#define MSCAN_CANRIER_RXFIE_MASK                 (0x1U)
#define MSCAN_CANRIER_RXFIE_SHIFT                (0U)
/*! RXFIE - Receiver Full Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..A receive buffer full (successful message reception) event causes a receiver interrupt request.
 */
#define MSCAN_CANRIER_RXFIE(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRIER_RXFIE_SHIFT)) & MSCAN_CANRIER_RXFIE_MASK)

#define MSCAN_CANRIER_OVRIE_MASK                 (0x2U)
#define MSCAN_CANRIER_OVRIE_SHIFT                (1U)
/*! OVRIE - Overrun Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..An overrun event causes an error interrupt request.
 */
#define MSCAN_CANRIER_OVRIE(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRIER_OVRIE_SHIFT)) & MSCAN_CANRIER_OVRIE_MASK)

#define MSCAN_CANRIER_TSTATE_MASK                (0xCU)
#define MSCAN_CANRIER_TSTATE_SHIFT               (2U)
/*! TSTATE - Transmitter Status Change Enable
 *  0b00..Do not generate any CSCIF interrupt caused by transmitter state changes.
 *  0b01..Generate CSCIF interrupt only if the transmitter enters or leaves "bus-off" state. Discard other
 *        transmitter state changes for generating CSCIF interrupt.
 *  0b10..Generate CSCIF interrupt only if the transmitter enters or leaves "TxErr" or "bus-off" state. Discard
 *        other transmitter state changes for generating CSCIF interrupt.
 *  0b11..Generate CSCIF interrupt on all state changes.
 */
#define MSCAN_CANRIER_TSTATE(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRIER_TSTATE_SHIFT)) & MSCAN_CANRIER_TSTATE_MASK)

#define MSCAN_CANRIER_RSTATE_MASK                (0x30U)
#define MSCAN_CANRIER_RSTATE_SHIFT               (4U)
/*! RSTATE - Receiver Status Change Enable
 *  0b00..Do not generate any CSCIF interrupt caused by receiver state changes.
 *  0b01..Generate CSCIF interrupt only if the receiver enters or leaves "bus-off" state. Discard other receiver
 *        state changes for generating CSCIF interrupt.
 *  0b10..Generate CSCIF interrupt only if the receiver enters or leaves "RxErr" or "bus-off"Bus-off state is only
 *        defined for transmitters by the CAN standard (see Bosch CAN 2.0A/B protocol specification). Because the
 *        only possible state change for the transmitter from bus-off to TxOK also forces the receiver to skip its
 *        current state to RxOK, the coding of the RXSTAT[1:0] flags define an additional bus-off state for the
 *        receiver state. Discard other receiver state changes for generating CSCIF interrupt.
 *  0b11..Generate CSCIF interrupt on all state changes.
 */
#define MSCAN_CANRIER_RSTATE(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRIER_RSTATE_SHIFT)) & MSCAN_CANRIER_RSTATE_MASK)

#define MSCAN_CANRIER_CSCIE_MASK                 (0x40U)
#define MSCAN_CANRIER_CSCIE_SHIFT                (6U)
/*! CSCIE - CAN Status Change Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..A CAN Status Change event causes an error interrupt request.
 */
#define MSCAN_CANRIER_CSCIE(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRIER_CSCIE_SHIFT)) & MSCAN_CANRIER_CSCIE_MASK)

#define MSCAN_CANRIER_WUPIE_MASK                 (0x80U)
#define MSCAN_CANRIER_WUPIE_SHIFT                (7U)
/*! WUPIE - WakeUp Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..A wake-up event causes a Wake-Up interrupt request.
 */
#define MSCAN_CANRIER_WUPIE(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRIER_WUPIE_SHIFT)) & MSCAN_CANRIER_WUPIE_MASK)
/*! @} */

/*! @name CANTFLG - MSCAN Transmitter Flag Register */
/*! @{ */

#define MSCAN_CANTFLG_TXE_MASK                   (0x7U)
#define MSCAN_CANTFLG_TXE_SHIFT                  (0U)
/*! TXE - Transmitter Buffer Empty
 *  0b000..The associated message buffer is full (loaded with a message due for transmission).
 *  0b001..The associated message buffer is empty (not scheduled).
 */
#define MSCAN_CANTFLG_TXE(x)                     (((uint8_t)(((uint8_t)(x)) << MSCAN_CANTFLG_TXE_SHIFT)) & MSCAN_CANTFLG_TXE_MASK)
/*! @} */

/*! @name CANTIER - MSCAN Transmitter Interrupt Enable Register */
/*! @{ */

#define MSCAN_CANTIER_TXEIE_MASK                 (0x7U)
#define MSCAN_CANTIER_TXEIE_SHIFT                (0U)
/*! TXEIE - Transmitter Empty Interrupt Enable
 *  0b000..No interrupt request is generated from this event.
 *  0b001..A transmitter empty (transmit buffer available for transmission) event causes a transmitter empty interrupt request.
 */
#define MSCAN_CANTIER_TXEIE(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANTIER_TXEIE_SHIFT)) & MSCAN_CANTIER_TXEIE_MASK)
/*! @} */

/*! @name CANTARQ - MSCAN Transmitter Message Abort Request Register */
/*! @{ */

#define MSCAN_CANTARQ_ABTRQ_MASK                 (0x7U)
#define MSCAN_CANTARQ_ABTRQ_SHIFT                (0U)
/*! ABTRQ - Abort Request
 *  0b000..No abort request.
 *  0b001..Abort request pending.
 */
#define MSCAN_CANTARQ_ABTRQ(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANTARQ_ABTRQ_SHIFT)) & MSCAN_CANTARQ_ABTRQ_MASK)
/*! @} */

/*! @name CANTAAK - MSCAN Transmitter Message Abort Acknowledge Register */
/*! @{ */

#define MSCAN_CANTAAK_ABTAK_MASK                 (0x7U)
#define MSCAN_CANTAAK_ABTAK_SHIFT                (0U)
/*! ABTAK - Abort Acknowledge
 *  0b000..The message was not aborted.
 *  0b001..The message was aborted.
 */
#define MSCAN_CANTAAK_ABTAK(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANTAAK_ABTAK_SHIFT)) & MSCAN_CANTAAK_ABTAK_MASK)
/*! @} */

/*! @name CANTBSEL - MSCAN Transmit Buffer Selection Register */
/*! @{ */

#define MSCAN_CANTBSEL_TX_MASK                   (0x7U)
#define MSCAN_CANTBSEL_TX_SHIFT                  (0U)
/*! TX - Transmit Buffer Select
 *  0b000..The associated message buffer is deselected.
 *  0b001..The associated message buffer is selected, if lowest numbered bit.
 */
#define MSCAN_CANTBSEL_TX(x)                     (((uint8_t)(((uint8_t)(x)) << MSCAN_CANTBSEL_TX_SHIFT)) & MSCAN_CANTBSEL_TX_MASK)
/*! @} */

/*! @name CANIDAC - MSCAN Identifier Acceptance Control Register */
/*! @{ */

#define MSCAN_CANIDAC_IDHIT_MASK                 (0x7U)
#define MSCAN_CANIDAC_IDHIT_SHIFT                (0U)
/*! IDHIT - Identifier Acceptance Hit Indicator
 *  0b000..Filter 0 hit.
 *  0b001..Filter 1 hit.
 *  0b010..Filter 2 hit.
 *  0b011..Filter 3 hit.
 *  0b100..Filter 4 hit.
 *  0b101..Filter 5 hit.
 *  0b110..Filter 6 hit.
 *  0b111..Filter 7 hit.
 */
#define MSCAN_CANIDAC_IDHIT(x)                   (((uint8_t)(((uint8_t)(x)) << MSCAN_CANIDAC_IDHIT_SHIFT)) & MSCAN_CANIDAC_IDHIT_MASK)

#define MSCAN_CANIDAC_IDAM_MASK                  (0x30U)
#define MSCAN_CANIDAC_IDAM_SHIFT                 (4U)
/*! IDAM - Identifier Acceptance Mode
 *  0b00..Two 32-bit acceptance filters.
 *  0b01..Four 16-bit acceptance filters.
 *  0b10..Eight 8-bit acceptance filters.
 *  0b11..Filter closed.
 */
#define MSCAN_CANIDAC_IDAM(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_CANIDAC_IDAM_SHIFT)) & MSCAN_CANIDAC_IDAM_MASK)
/*! @} */

/*! @name CANMISC - MSCAN Miscellaneous Register */
/*! @{ */

#define MSCAN_CANMISC_BOHOLD_MASK                (0x1U)
#define MSCAN_CANMISC_BOHOLD_SHIFT               (0U)
/*! BOHOLD - Bus-off State Hold Until User Request
 *  0b0..Module is not bus-off or recovery has been requested by user in bus-off state.
 *  0b1..Module is bus-off and holds this state until user request.
 */
#define MSCAN_CANMISC_BOHOLD(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANMISC_BOHOLD_SHIFT)) & MSCAN_CANMISC_BOHOLD_MASK)
/*! @} */

/*! @name CANRXERR - MSCAN Receive Error Counter */
/*! @{ */

#define MSCAN_CANRXERR_RXERR_MASK                (0xFFU)
#define MSCAN_CANRXERR_RXERR_SHIFT               (0U)
/*! RXERR - Receive Error Counter */
#define MSCAN_CANRXERR_RXERR(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANRXERR_RXERR_SHIFT)) & MSCAN_CANRXERR_RXERR_MASK)
/*! @} */

/*! @name CANTXERR - MSCAN Transmit Error Counter */
/*! @{ */

#define MSCAN_CANTXERR_TXERR_MASK                (0xFFU)
#define MSCAN_CANTXERR_TXERR_SHIFT               (0U)
/*! TXERR - Transmit Error Counter */
#define MSCAN_CANTXERR_TXERR(x)                  (((uint8_t)(((uint8_t)(x)) << MSCAN_CANTXERR_TXERR_SHIFT)) & MSCAN_CANTXERR_TXERR_MASK)
/*! @} */

/*! @name CANIDAR_BANK_1 - MSCAN Identifier Acceptance Register n of First Bank */
/*! @{ */

#define MSCAN_CANIDAR_BANK_1_AC_MASK             (0xFFU)
#define MSCAN_CANIDAR_BANK_1_AC_SHIFT            (0U)
/*! AC - Acceptance Code Bits */
#define MSCAN_CANIDAR_BANK_1_AC(x)               (((uint8_t)(((uint8_t)(x)) << MSCAN_CANIDAR_BANK_1_AC_SHIFT)) & MSCAN_CANIDAR_BANK_1_AC_MASK)
/*! @} */

/*! @name CANIDMR_BANK_1 - MSCAN Identifier Mask Register n of First Bank */
/*! @{ */

#define MSCAN_CANIDMR_BANK_1_AM_MASK             (0xFFU)
#define MSCAN_CANIDMR_BANK_1_AM_SHIFT            (0U)
/*! AM - Acceptance Mask Bits
 *  0b00000000..Match corresponding acceptance code register and identifier bits.
 *  0b00000001..Ignore corresponding acceptance code register bit.
 */
#define MSCAN_CANIDMR_BANK_1_AM(x)               (((uint8_t)(((uint8_t)(x)) << MSCAN_CANIDMR_BANK_1_AM_SHIFT)) & MSCAN_CANIDMR_BANK_1_AM_MASK)
/*! @} */

/*! @name CANIDAR_BANK_2 - MSCAN Identifier Acceptance Register n of Second Bank */
/*! @{ */

#define MSCAN_CANIDAR_BANK_2_AC_MASK             (0xFFU)
#define MSCAN_CANIDAR_BANK_2_AC_SHIFT            (0U)
/*! AC - Acceptance Code Bits */
#define MSCAN_CANIDAR_BANK_2_AC(x)               (((uint8_t)(((uint8_t)(x)) << MSCAN_CANIDAR_BANK_2_AC_SHIFT)) & MSCAN_CANIDAR_BANK_2_AC_MASK)
/*! @} */

/*! @name CANIDMR_BANK_2 - MSCAN Identifier Mask Register n of Second Bank */
/*! @{ */

#define MSCAN_CANIDMR_BANK_2_AM_MASK             (0xFFU)
#define MSCAN_CANIDMR_BANK_2_AM_SHIFT            (0U)
/*! AM - Acceptance Mask Bits
 *  0b00000000..Match corresponding acceptance code register and identifier bits.
 *  0b00000001..Ignore corresponding acceptance code register bit.
 */
#define MSCAN_CANIDMR_BANK_2_AM(x)               (((uint8_t)(((uint8_t)(x)) << MSCAN_CANIDMR_BANK_2_AM_SHIFT)) & MSCAN_CANIDMR_BANK_2_AM_MASK)
/*! @} */

/*! @name REIDR0 - Receive Extended Identifier Register 0 */
/*! @{ */

#define MSCAN_REIDR0_REID28_REID21_MASK          (0xFFU)
#define MSCAN_REIDR0_REID28_REID21_SHIFT         (0U)
/*! REID28_REID21 - Extended Format Identifier */
#define MSCAN_REIDR0_REID28_REID21(x)            (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR0_REID28_REID21_SHIFT)) & MSCAN_REIDR0_REID28_REID21_MASK)
/*! @} */

/*! @name RSIDR0 - Receive Standard Identifier Register 0 */
/*! @{ */

#define MSCAN_RSIDR0_RSID10_RSID3_MASK           (0xFFU)
#define MSCAN_RSIDR0_RSID10_RSID3_SHIFT          (0U)
/*! RSID10_RSID3 - Standard Format Identifier */
#define MSCAN_RSIDR0_RSID10_RSID3(x)             (((uint8_t)(((uint8_t)(x)) << MSCAN_RSIDR0_RSID10_RSID3_SHIFT)) & MSCAN_RSIDR0_RSID10_RSID3_MASK)
/*! @} */

/*! @name REIDR1 - Receive Extended Identifier Register 1 */
/*! @{ */

#define MSCAN_REIDR1_REID17_REID15_MASK          (0x7U)
#define MSCAN_REIDR1_REID17_REID15_SHIFT         (0U)
/*! REID17_REID15 - Extended Format Identifier 17-15 */
#define MSCAN_REIDR1_REID17_REID15(x)            (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR1_REID17_REID15_SHIFT)) & MSCAN_REIDR1_REID17_REID15_MASK)

#define MSCAN_REIDR1_REIDE_MASK                  (0x8U)
#define MSCAN_REIDR1_REIDE_SHIFT                 (3U)
/*! REIDE - ID Extended
 *  0b0..Standard format (11 bit).
 *  0b1..Extended format (29 bit).
 */
#define MSCAN_REIDR1_REIDE(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR1_REIDE_SHIFT)) & MSCAN_REIDR1_REIDE_MASK)

#define MSCAN_REIDR1_RSRR_MASK                   (0x10U)
#define MSCAN_REIDR1_RSRR_SHIFT                  (4U)
/*! RSRR - Substitute Remote Request */
#define MSCAN_REIDR1_RSRR(x)                     (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR1_RSRR_SHIFT)) & MSCAN_REIDR1_RSRR_MASK)

#define MSCAN_REIDR1_REID20_REID18_MASK          (0xE0U)
#define MSCAN_REIDR1_REID20_REID18_SHIFT         (5U)
/*! REID20_REID18 - Extended Format Identifier 20-18 */
#define MSCAN_REIDR1_REID20_REID18(x)            (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR1_REID20_REID18_SHIFT)) & MSCAN_REIDR1_REID20_REID18_MASK)
/*! @} */

/*! @name RSIDR1 - Receive Standard Identifier Register 1 */
/*! @{ */

#define MSCAN_RSIDR1_RSIDE_MASK                  (0x8U)
#define MSCAN_RSIDR1_RSIDE_SHIFT                 (3U)
/*! RSIDE - ID Extended
 *  0b0..Standard format (11 bit).
 *  0b1..Extended format (29 bit).
 */
#define MSCAN_RSIDR1_RSIDE(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_RSIDR1_RSIDE_SHIFT)) & MSCAN_RSIDR1_RSIDE_MASK)

#define MSCAN_RSIDR1_RSRTR_MASK                  (0x10U)
#define MSCAN_RSIDR1_RSRTR_SHIFT                 (4U)
/*! RSRTR - Remote Transmission Request
 *  0b0..Data frame.
 *  0b1..Remote frame.
 */
#define MSCAN_RSIDR1_RSRTR(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_RSIDR1_RSRTR_SHIFT)) & MSCAN_RSIDR1_RSRTR_MASK)

#define MSCAN_RSIDR1_RSID2_RSID0_MASK            (0xE0U)
#define MSCAN_RSIDR1_RSID2_RSID0_SHIFT           (5U)
/*! RSID2_RSID0 - Standard Format Identifier 2-0 */
#define MSCAN_RSIDR1_RSID2_RSID0(x)              (((uint8_t)(((uint8_t)(x)) << MSCAN_RSIDR1_RSID2_RSID0_SHIFT)) & MSCAN_RSIDR1_RSID2_RSID0_MASK)
/*! @} */

/*! @name REIDR2 - Receive Extended Identifier Register 2 */
/*! @{ */

#define MSCAN_REIDR2_REID14_REID7_MASK           (0xFFU)
#define MSCAN_REIDR2_REID14_REID7_SHIFT          (0U)
/*! REID14_REID7 - Extended Format Identifier 14-7 */
#define MSCAN_REIDR2_REID14_REID7(x)             (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR2_REID14_REID7_SHIFT)) & MSCAN_REIDR2_REID14_REID7_MASK)
/*! @} */

/*! @name REIDR3 - Receive Extended Identifier Register 3 */
/*! @{ */

#define MSCAN_REIDR3_RERTR_MASK                  (0x1U)
#define MSCAN_REIDR3_RERTR_SHIFT                 (0U)
/*! RERTR - Remote Transmission Request
 *  0b0..Data frame.
 *  0b1..Remote frame.
 */
#define MSCAN_REIDR3_RERTR(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR3_RERTR_SHIFT)) & MSCAN_REIDR3_RERTR_MASK)

#define MSCAN_REIDR3_REID6_REID0_MASK            (0xFEU)
#define MSCAN_REIDR3_REID6_REID0_SHIFT           (1U)
/*! REID6_REID0 - Extended Format Identifier 6-0 */
#define MSCAN_REIDR3_REID6_REID0(x)              (((uint8_t)(((uint8_t)(x)) << MSCAN_REIDR3_REID6_REID0_SHIFT)) & MSCAN_REIDR3_REID6_REID0_MASK)
/*! @} */

/*! @name REDSR - Receive Extended Data Segment Register N */
/*! @{ */

#define MSCAN_REDSR_RDB_MASK                     (0xFFU)
#define MSCAN_REDSR_RDB_SHIFT                    (0U)
/*! RDB - Data Bits */
#define MSCAN_REDSR_RDB(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_REDSR_RDB_SHIFT)) & MSCAN_REDSR_RDB_MASK)
/*! @} */

/*! @name RDLR - Receive Data Length Register */
/*! @{ */

#define MSCAN_RDLR_RDLC_MASK                     (0xFU)
#define MSCAN_RDLR_RDLC_SHIFT                    (0U)
/*! RDLC - Data Length Code Bits
 *  0b0000..0
 *  0b0001..1
 *  0b0010..2
 *  0b0011..3
 *  0b0100..4
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 */
#define MSCAN_RDLR_RDLC(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_RDLR_RDLC_SHIFT)) & MSCAN_RDLR_RDLC_MASK)
/*! @} */

/*! @name RTSRH - Receive Time Stamp Register High */
/*! @{ */

#define MSCAN_RTSRH_RTS_MASK                     (0xFFU)
#define MSCAN_RTSRH_RTS_SHIFT                    (0U)
/*! RTS - Time Stamp */
#define MSCAN_RTSRH_RTS(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_RTSRH_RTS_SHIFT)) & MSCAN_RTSRH_RTS_MASK)
/*! @} */

/*! @name RTSRL - Receive Time Stamp Register Low */
/*! @{ */

#define MSCAN_RTSRL_RTS_MASK                     (0xFFU)
#define MSCAN_RTSRL_RTS_SHIFT                    (0U)
/*! RTS - Time Stamp */
#define MSCAN_RTSRL_RTS(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_RTSRL_RTS_SHIFT)) & MSCAN_RTSRL_RTS_MASK)
/*! @} */

/*! @name TEIDR0 - Transmit Extended Identifier Register 0 */
/*! @{ */

#define MSCAN_TEIDR0_TEID28_TEID21_MASK          (0xFFU)
#define MSCAN_TEIDR0_TEID28_TEID21_SHIFT         (0U)
/*! TEID28_TEID21 - Extended Format Identifier */
#define MSCAN_TEIDR0_TEID28_TEID21(x)            (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR0_TEID28_TEID21_SHIFT)) & MSCAN_TEIDR0_TEID28_TEID21_MASK)
/*! @} */

/*! @name TSIDR0 - Transmit Standard Identifier Register 0 */
/*! @{ */

#define MSCAN_TSIDR0_TSID10_TSID3_MASK           (0xFFU)
#define MSCAN_TSIDR0_TSID10_TSID3_SHIFT          (0U)
/*! TSID10_TSID3 - Standard Format Identifier */
#define MSCAN_TSIDR0_TSID10_TSID3(x)             (((uint8_t)(((uint8_t)(x)) << MSCAN_TSIDR0_TSID10_TSID3_SHIFT)) & MSCAN_TSIDR0_TSID10_TSID3_MASK)
/*! @} */

/*! @name TEIDR1 - Transmit Extended Identifier Register 1 */
/*! @{ */

#define MSCAN_TEIDR1_TEID17_TEID15_MASK          (0x7U)
#define MSCAN_TEIDR1_TEID17_TEID15_SHIFT         (0U)
/*! TEID17_TEID15 - Extended Format Identifier 17-15 */
#define MSCAN_TEIDR1_TEID17_TEID15(x)            (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR1_TEID17_TEID15_SHIFT)) & MSCAN_TEIDR1_TEID17_TEID15_MASK)

#define MSCAN_TEIDR1_TEIDE_MASK                  (0x8U)
#define MSCAN_TEIDR1_TEIDE_SHIFT                 (3U)
/*! TEIDE - ID Extended
 *  0b0..Standard format (11 bit).
 *  0b1..Extended format (29 bit).
 */
#define MSCAN_TEIDR1_TEIDE(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR1_TEIDE_SHIFT)) & MSCAN_TEIDR1_TEIDE_MASK)

#define MSCAN_TEIDR1_TSRR_MASK                   (0x10U)
#define MSCAN_TEIDR1_TSRR_SHIFT                  (4U)
/*! TSRR - Substitute Remote Request */
#define MSCAN_TEIDR1_TSRR(x)                     (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR1_TSRR_SHIFT)) & MSCAN_TEIDR1_TSRR_MASK)

#define MSCAN_TEIDR1_TEID20_TEID18_MASK          (0xE0U)
#define MSCAN_TEIDR1_TEID20_TEID18_SHIFT         (5U)
/*! TEID20_TEID18 - Extended Format Identifier 20-18 */
#define MSCAN_TEIDR1_TEID20_TEID18(x)            (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR1_TEID20_TEID18_SHIFT)) & MSCAN_TEIDR1_TEID20_TEID18_MASK)
/*! @} */

/*! @name TSIDR1 - Transmit Standard Identifier Register 1 */
/*! @{ */

#define MSCAN_TSIDR1_TSIDE_MASK                  (0x8U)
#define MSCAN_TSIDR1_TSIDE_SHIFT                 (3U)
/*! TSIDE - ID Extended
 *  0b0..Standard format (11 bit).
 *  0b1..Extended format (29 bit).
 */
#define MSCAN_TSIDR1_TSIDE(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_TSIDR1_TSIDE_SHIFT)) & MSCAN_TSIDR1_TSIDE_MASK)

#define MSCAN_TSIDR1_TSRTR_MASK                  (0x10U)
#define MSCAN_TSIDR1_TSRTR_SHIFT                 (4U)
/*! TSRTR - Remote Transmission Request
 *  0b0..Data frame.
 *  0b1..Remote frame.
 */
#define MSCAN_TSIDR1_TSRTR(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_TSIDR1_TSRTR_SHIFT)) & MSCAN_TSIDR1_TSRTR_MASK)

#define MSCAN_TSIDR1_TSID2_TSID0_MASK            (0xE0U)
#define MSCAN_TSIDR1_TSID2_TSID0_SHIFT           (5U)
/*! TSID2_TSID0 - Standard Format Identifier 2-0 */
#define MSCAN_TSIDR1_TSID2_TSID0(x)              (((uint8_t)(((uint8_t)(x)) << MSCAN_TSIDR1_TSID2_TSID0_SHIFT)) & MSCAN_TSIDR1_TSID2_TSID0_MASK)
/*! @} */

/*! @name TEIDR2 - Transmit Extended Identifier Register 2 */
/*! @{ */

#define MSCAN_TEIDR2_TEID14_TEID7_MASK           (0xFFU)
#define MSCAN_TEIDR2_TEID14_TEID7_SHIFT          (0U)
/*! TEID14_TEID7 - Extended Format Identifier 14-7 */
#define MSCAN_TEIDR2_TEID14_TEID7(x)             (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR2_TEID14_TEID7_SHIFT)) & MSCAN_TEIDR2_TEID14_TEID7_MASK)
/*! @} */

/*! @name TEIDR3 - Transmit Extended Identifier Register 3 */
/*! @{ */

#define MSCAN_TEIDR3_TERTR_MASK                  (0x1U)
#define MSCAN_TEIDR3_TERTR_SHIFT                 (0U)
/*! TERTR - Remote Transmission Request
 *  0b0..Data frame.
 *  0b1..Remote frame.
 */
#define MSCAN_TEIDR3_TERTR(x)                    (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR3_TERTR_SHIFT)) & MSCAN_TEIDR3_TERTR_MASK)

#define MSCAN_TEIDR3_TEID6_TEID0_MASK            (0xFEU)
#define MSCAN_TEIDR3_TEID6_TEID0_SHIFT           (1U)
/*! TEID6_TEID0 - Extended Format Identifier 6-0 */
#define MSCAN_TEIDR3_TEID6_TEID0(x)              (((uint8_t)(((uint8_t)(x)) << MSCAN_TEIDR3_TEID6_TEID0_SHIFT)) & MSCAN_TEIDR3_TEID6_TEID0_MASK)
/*! @} */

/*! @name TEDSR - Transmit Extended Data Segment Register N */
/*! @{ */

#define MSCAN_TEDSR_TDB_MASK                     (0xFFU)
#define MSCAN_TEDSR_TDB_SHIFT                    (0U)
/*! TDB - Data Bits */
#define MSCAN_TEDSR_TDB(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_TEDSR_TDB_SHIFT)) & MSCAN_TEDSR_TDB_MASK)
/*! @} */

/*! @name TDLR - Transmit Data Length Register */
/*! @{ */

#define MSCAN_TDLR_TDLC_MASK                     (0xFU)
#define MSCAN_TDLR_TDLC_SHIFT                    (0U)
/*! TDLC - Data Length Code Bits
 *  0b0000..0
 *  0b0001..1
 *  0b0010..2
 *  0b0011..3
 *  0b0100..4
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 */
#define MSCAN_TDLR_TDLC(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_TDLR_TDLC_SHIFT)) & MSCAN_TDLR_TDLC_MASK)
/*! @} */

/*! @name TBPR - Transmit Buffer Priority Register */
/*! @{ */

#define MSCAN_TBPR_PRIO_MASK                     (0xFFU)
#define MSCAN_TBPR_PRIO_SHIFT                    (0U)
/*! PRIO - Priority */
#define MSCAN_TBPR_PRIO(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_TBPR_PRIO_SHIFT)) & MSCAN_TBPR_PRIO_MASK)
/*! @} */

/*! @name TTSRH - Transmit Time Stamp Register High */
/*! @{ */

#define MSCAN_TTSRH_TTS_MASK                     (0xFFU)
#define MSCAN_TTSRH_TTS_SHIFT                    (0U)
/*! TTS - Time Stamp */
#define MSCAN_TTSRH_TTS(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_TTSRH_TTS_SHIFT)) & MSCAN_TTSRH_TTS_MASK)
/*! @} */

/*! @name TTSRL - Transmit Time Stamp Register Low */
/*! @{ */

#define MSCAN_TTSRL_TTS_MASK                     (0xFFU)
#define MSCAN_TTSRL_TTS_SHIFT                    (0U)
/*! TTS - Time Stamp */
#define MSCAN_TTSRL_TTS(x)                       (((uint8_t)(((uint8_t)(x)) << MSCAN_TTSRL_TTS_SHIFT)) & MSCAN_TTSRL_TTS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MSCAN_Register_Masks */


/*!
 * @}
 */ /* end of group MSCAN_Peripheral_Access_Layer */


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


#endif  /* PERI_MSCAN_H_ */

