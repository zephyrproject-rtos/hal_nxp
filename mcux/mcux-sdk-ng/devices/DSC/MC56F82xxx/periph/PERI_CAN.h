/*
** ###################################################################
**     Processors:          MC56F82313VLC
**                          MC56F82316VLF
**                          MC56F82323VFM
**                          MC56F82623VLC
**                          MC56F82643VLC
**                          MC56F82646VLF
**                          MC56F82723VFM
**                          MC56F82723VLC
**                          MC56F82726VLF
**                          MC56F82728VLH
**                          MC56F82733MFM
**                          MC56F82733VFM
**                          MC56F82733VLC
**                          MC56F82736VLF
**                          MC56F82738VLH
**                          MC56F82743VFM
**                          MC56F82743VLC
**                          MC56F82746MLF
**                          MC56F82746VLF
**                          MC56F82748MLH
**                          MC56F82748VLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAN
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-11)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CAN.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAN
 *
 * CMSIS Peripheral Access Layer for CAN
 */

#if !defined(PERI_CAN_H_)
#define PERI_CAN_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F82313VLC))
#include "MC56F82313_COMMON.h"
#elif (defined(CPU_MC56F82316VLF))
#include "MC56F82316_COMMON.h"
#elif (defined(CPU_MC56F82323VFM))
#include "MC56F82323_COMMON.h"
#elif (defined(CPU_MC56F82623VLC))
#include "MC56F82623_COMMON.h"
#elif (defined(CPU_MC56F82643VLC))
#include "MC56F82643_COMMON.h"
#elif (defined(CPU_MC56F82646VLF))
#include "MC56F82646_COMMON.h"
#elif (defined(CPU_MC56F82723VFM) || defined(CPU_MC56F82723VLC))
#include "MC56F82723_COMMON.h"
#elif (defined(CPU_MC56F82726VLF))
#include "MC56F82726_COMMON.h"
#elif (defined(CPU_MC56F82728VLH))
#include "MC56F82728_COMMON.h"
#elif (defined(CPU_MC56F82733MFM) || defined(CPU_MC56F82733VFM) || defined(CPU_MC56F82733VLC))
#include "MC56F82733_COMMON.h"
#elif (defined(CPU_MC56F82736VLF))
#include "MC56F82736_COMMON.h"
#elif (defined(CPU_MC56F82738VLH))
#include "MC56F82738_COMMON.h"
#elif (defined(CPU_MC56F82743VFM) || defined(CPU_MC56F82743VLC))
#include "MC56F82743_COMMON.h"
#elif (defined(CPU_MC56F82746MLF) || defined(CPU_MC56F82746VLF))
#include "MC56F82746_COMMON.h"
#elif (defined(CPU_MC56F82748MLH) || defined(CPU_MC56F82748VLH))
#include "MC56F82748_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */

/** CAN - Size of Registers Arrays */
#define CAN_IDAR_BANK_0_COUNT                     4u
#define CAN_IDMR_BANK_0_COUNT                     4u
#define CAN_IDAR_BANK_1_COUNT                     4u
#define CAN_IDMR_BANK_1_COUNT                     4u
#define CAN_RXFG_DSR_COUNT                        8u
#define CAN_TXFG_DSR_COUNT                        8u

/** CAN - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTL0;                              /**< MSCAN Control Register 0, offset: 0x0 */
  __IO uint16_t CTL1;                              /**< MSCAN Control Register 1, offset: 0x1 */
  __IO uint16_t BTR0;                              /**< MSCAN Bus Timing Register 0, offset: 0x2 */
  __IO uint16_t BTR1;                              /**< MSCAN Bus Timing Register 1, offset: 0x3 */
  __IO uint16_t RFLG;                              /**< MSCAN Receiver Flag Register, offset: 0x4 */
  __IO uint16_t RIER;                              /**< MSCAN Receiver Interrupt Enable Register, offset: 0x5 */
  __IO uint16_t TFLG;                              /**< MSCAN Transmitter Flag Register, offset: 0x6 */
  __IO uint16_t TIER;                              /**< MSCAN Transmitter Interrupt Enable Register, offset: 0x7 */
  __IO uint16_t TARQ;                              /**< MSCAN Transmitter Message Abort Request Register, offset: 0x8 */
  __I  uint16_t TAAK;                              /**< MSCAN Transmitter Message Abort Acknowledge Register, offset: 0x9 */
  __IO uint16_t TBSEL;                             /**< MSCAN Transmit Buffer Selection Register, offset: 0xA */
  __IO uint16_t IDAC;                              /**< MSCAN Identifier Acceptance Control Register, offset: 0xB */
       uint16_t RESERVED_0[1];
  __IO uint16_t MISC;                              /**< MSCAN Miscellaneous Register, offset: 0xD */
  __I  uint16_t RXERR;                             /**< MSCAN Receive Error Counter Register, offset: 0xE */
  __I  uint16_t TXERR;                             /**< MSCAN Transmit Error Counter Register, offset: 0xF */
  __IO uint16_t IDAR_BANK_0[CAN_IDAR_BANK_0_COUNT]; /**< MSCAN Identifier Acceptance Registers (First Bank), array offset: 0x10, array step: 0x1 */
  __IO uint16_t IDMR_BANK_0[CAN_IDMR_BANK_0_COUNT]; /**< MSCAN Identifier Mask Registers (First Bank), array offset: 0x14, array step: 0x1 */
  __IO uint16_t IDAR_BANK_1[CAN_IDAR_BANK_1_COUNT]; /**< MSCAN Identifier Acceptance Registers (Second Bank), array offset: 0x18, array step: 0x1 */
  __IO uint16_t IDMR_BANK_1[CAN_IDMR_BANK_1_COUNT]; /**< MSCAN Identifier Mask Registers (Second Bank), array offset: 0x1C, array step: 0x1 */
  union {                                          /* offset: 0x20 */
    __IO uint16_t RXFG_IDR0_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 0 - Extended Identifer Mapping, offset: 0x20 */
    __IO uint16_t RXFG_IDR0_STD;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 0 - Standard Identifer Mapping, offset: 0x20 */
  };
  union {                                          /* offset: 0x21 */
    __IO uint16_t RXFG_IDR1_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 1 - Extended Identifer Mapping, offset: 0x21 */
    __IO uint16_t RXFG_IDR1_STD;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 1 - Standard Identifier Mapping, offset: 0x21 */
  };
  __IO uint16_t RXFG_IDR2_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 2 - Extended Identifer Mapping, offset: 0x22 */
  __IO uint16_t RXFG_IDR3_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 3 - Extended Identifier Mapping, offset: 0x23 */
  __IO uint16_t RXFG_DSR[CAN_RXFG_DSR_COUNT];      /**< Receive Buffer Data Segment Registers, array offset: 0x24, array step: 0x1 */
  __IO uint16_t RXFG_DLR;                          /**< MSCAN Receive Buffer Data Length Register, offset: 0x2C */
       uint16_t RESERVED_1[1];
  __I  uint16_t RXFG_TSRH;                         /**< Receive Buffer Time Stamp Register - High Byte, offset: 0x2E */
  __I  uint16_t RXFG_TSRL;                         /**< Receive Buffer Time Stamp Register - Low Byte, offset: 0x2F */
  union {                                          /* offset: 0x30 */
    __IO uint16_t TXFG_IDR0_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 0 - Extended Identifer Mapping, offset: 0x30 */
    __IO uint16_t TXFG_IDR0_STD;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 0 - Standard Identifer Mapping, offset: 0x30 */
  };
  union {                                          /* offset: 0x31 */
    __IO uint16_t TXFG_IDR1_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 1 - Extended Identifer Mapping, offset: 0x31 */
    __IO uint16_t TXFG_IDR1_STD;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 1 - Standard Identifier Mapping, offset: 0x31 */
  };
  __IO uint16_t TXFG_IDR2_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 2 - Extended Identifer Mapping, offset: 0x32 */
  __IO uint16_t TXFG_IDR3_EXT;                     /**< MSCAN Receive and Transmit Buffer Identifier Register 3 - Extended Identifier Mapping, offset: 0x33 */
  __IO uint16_t TXFG_DSR[CAN_TXFG_DSR_COUNT];      /**< Transmit Buffer Data Segment Registers, array offset: 0x34, array step: 0x1 */
  __IO uint16_t TXFG_DLR;                          /**< MSCAN Transmit Buffer Data Length Register, offset: 0x3C */
  __IO uint16_t TXFG_TBPR;                         /**< MSCAN Transmit Buffer Priority Register, offset: 0x3D */
  __I  uint16_t TXFG_TSRH;                         /**< Transmit Buffer Time Stamp Register - High Byte, offset: 0x3E */
  __I  uint16_t TXFG_TSRL;                         /**< Transmit Buffer Time Stamp Register - Low Byte, offset: 0x3F */
} CAN_Type;

/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/*! @name CTL0 - MSCAN Control Register 0 */
/*! @{ */

#define CAN_CTL0_INITRQ_MASK                     (0x1U)
#define CAN_CTL0_INITRQ_SHIFT                    (0U)
/*! INITRQ - Initialization Mode Request
 *  0b0..Normal operation
 *  0b1..MSCAN in initialization mode
 */
#define CAN_CTL0_INITRQ(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_INITRQ_SHIFT)) & CAN_CTL0_INITRQ_MASK)

#define CAN_CTL0_SLPRQ_MASK                      (0x2U)
#define CAN_CTL0_SLPRQ_SHIFT                     (1U)
/*! SLPRQ - Sleep Mode Request
 *  0b0..Running - The MSCAN functions normally
 *  0b1..Sleep mode request - The MSCAN enters sleep mode when CAN bus idle
 */
#define CAN_CTL0_SLPRQ(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_SLPRQ_SHIFT)) & CAN_CTL0_SLPRQ_MASK)

#define CAN_CTL0_WUPE_MASK                       (0x4U)
#define CAN_CTL0_WUPE_SHIFT                      (2U)
/*! WUPE - Wake-Up Enable
 *  0b0..Wake-up disabled - The MSCAN ignores traffic on CAN
 *  0b1..Wake-up enabled - The MSCAN is able to restart
 */
#define CAN_CTL0_WUPE(x)                         (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_WUPE_SHIFT)) & CAN_CTL0_WUPE_MASK)

#define CAN_CTL0_TIME_MASK                       (0x8U)
#define CAN_CTL0_TIME_SHIFT                      (3U)
/*! TIME - Timer Enable
 *  0b0..Disable internal MSCAN timer
 *  0b1..Enable internal MSCAN timer
 */
#define CAN_CTL0_TIME(x)                         (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_TIME_SHIFT)) & CAN_CTL0_TIME_MASK)

#define CAN_CTL0_SYNCH_MASK                      (0x10U)
#define CAN_CTL0_SYNCH_SHIFT                     (4U)
/*! SYNCH - Synchronized Status
 *  0b0..MSCAN is not synchronized to the CAN bus
 *  0b1..MSCAN is synchronized to the CAN bus
 */
#define CAN_CTL0_SYNCH(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_SYNCH_SHIFT)) & CAN_CTL0_SYNCH_MASK)

#define CAN_CTL0_CSWAI_MASK                      (0x20U)
#define CAN_CTL0_CSWAI_SHIFT                     (5U)
/*! CSWAI - CAN Stops in Wait Mode
 *  0b0..The module is not affected during wait mode
 *  0b1..The module ceases to be clocked during wait mode
 */
#define CAN_CTL0_CSWAI(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_CSWAI_SHIFT)) & CAN_CTL0_CSWAI_MASK)

#define CAN_CTL0_RXACT_MASK                      (0x40U)
#define CAN_CTL0_RXACT_SHIFT                     (6U)
/*! RXACT - Receiver Active Status
 *  0b0..MSCAN is transmitting or idle
 *  0b1..MSCAN is receiving a message (including when arbitration is lost)
 */
#define CAN_CTL0_RXACT(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_RXACT_SHIFT)) & CAN_CTL0_RXACT_MASK)

#define CAN_CTL0_RXFRM_MASK                      (0x80U)
#define CAN_CTL0_RXFRM_SHIFT                     (7U)
/*! RXFRM - Received Frame Flag
 *  0b0..No valid message was received since last clearing this flag
 *  0b1..A valid message was received since last clearing of this flag
 */
#define CAN_CTL0_RXFRM(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_CTL0_RXFRM_SHIFT)) & CAN_CTL0_RXFRM_MASK)
/*! @} */

/*! @name CTL1 - MSCAN Control Register 1 */
/*! @{ */

#define CAN_CTL1_INITAK_MASK                     (0x1U)
#define CAN_CTL1_INITAK_SHIFT                    (0U)
/*! INITAK - Initialization Mode Acknowledge
 *  0b0..Running - The MSCAN operates normally
 *  0b1..Initialization mode active - The MSCAN has entered initialization mode
 */
#define CAN_CTL1_INITAK(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_INITAK_SHIFT)) & CAN_CTL1_INITAK_MASK)

#define CAN_CTL1_SLPAK_MASK                      (0x2U)
#define CAN_CTL1_SLPAK_SHIFT                     (1U)
/*! SLPAK - Sleep Mode Acknowledge
 *  0b0..Running - The MSCAN operates normally
 *  0b1..Sleep mode active - The MSCAN has entered sleep mode
 */
#define CAN_CTL1_SLPAK(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_SLPAK_SHIFT)) & CAN_CTL1_SLPAK_MASK)

#define CAN_CTL1_WUPM_MASK                       (0x4U)
#define CAN_CTL1_WUPM_SHIFT                      (2U)
/*! WUPM - Wake-Up Mode
 *  0b0..MSCAN wakes up on any dominant level on the CAN bus
 *  0b1..MSCAN wakes up only in case of a dominant pulse on the CAN bus that has a length of T WAKEUP
 */
#define CAN_CTL1_WUPM(x)                         (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_WUPM_SHIFT)) & CAN_CTL1_WUPM_MASK)

#define CAN_CTL1_BORM_MASK                       (0x8U)
#define CAN_CTL1_BORM_SHIFT                      (3U)
/*! BORM - Bus-Off Recovery Mode
 *  0b0..Automatic bus-off recovery (see Bosch CAN 2.0A/B protocol specification)
 *  0b1..Bus-off recovery upon user request
 */
#define CAN_CTL1_BORM(x)                         (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_BORM_SHIFT)) & CAN_CTL1_BORM_MASK)

#define CAN_CTL1_LISTEN_MASK                     (0x10U)
#define CAN_CTL1_LISTEN_SHIFT                    (4U)
/*! LISTEN - Listen Only Mode
 *  0b0..Normal operation
 *  0b1..Listen only mode activated
 */
#define CAN_CTL1_LISTEN(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_LISTEN_SHIFT)) & CAN_CTL1_LISTEN_MASK)

#define CAN_CTL1_LOOPB_MASK                      (0x20U)
#define CAN_CTL1_LOOPB_SHIFT                     (5U)
/*! LOOPB - Loop Back Self Test Mode
 *  0b0..Loopback self test disabled
 *  0b1..Loopback self test enabled
 */
#define CAN_CTL1_LOOPB(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_LOOPB_SHIFT)) & CAN_CTL1_LOOPB_MASK)

#define CAN_CTL1_CLKSRC_MASK                     (0x40U)
#define CAN_CTL1_CLKSRC_SHIFT                    (6U)
/*! CLKSRC - MSCAN Clock Source
 *  0b0..MSCAN clock source is the oscillator clock
 *  0b1..MSCAN clock source is the bus clock
 */
#define CAN_CTL1_CLKSRC(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_CLKSRC_SHIFT)) & CAN_CTL1_CLKSRC_MASK)

#define CAN_CTL1_CANE_MASK                       (0x80U)
#define CAN_CTL1_CANE_SHIFT                      (7U)
/*! CANE - CAN Enable
 *  0b0..MSCAN module is disabled
 *  0b1..MSCAN module is enabled
 */
#define CAN_CTL1_CANE(x)                         (((uint16_t)(((uint16_t)(x)) << CAN_CTL1_CANE_SHIFT)) & CAN_CTL1_CANE_MASK)
/*! @} */

/*! @name BTR0 - MSCAN Bus Timing Register 0 */
/*! @{ */

#define CAN_BTR0_BRP_MASK                        (0x3FU)
#define CAN_BTR0_BRP_SHIFT                       (0U)
/*! BRP - Baud Rate Prescaler */
#define CAN_BTR0_BRP(x)                          (((uint16_t)(((uint16_t)(x)) << CAN_BTR0_BRP_SHIFT)) & CAN_BTR0_BRP_MASK)

#define CAN_BTR0_SJW_MASK                        (0xC0U)
#define CAN_BTR0_SJW_SHIFT                       (6U)
/*! SJW - Synchronization Jump Width
 *  0b00..Synchronization Jump Width 1 Tq Clock Cycle
 *  0b01..Synchronization Jump Width 2 Tq Clock Cycle
 *  0b10..Synchronization Jump Width 3 Tq Clock Cycle
 *  0b11..Synchronization Jump Width 4 Tq Clock Cycle
 */
#define CAN_BTR0_SJW(x)                          (((uint16_t)(((uint16_t)(x)) << CAN_BTR0_SJW_SHIFT)) & CAN_BTR0_SJW_MASK)
/*! @} */

/*! @name BTR1 - MSCAN Bus Timing Register 1 */
/*! @{ */

#define CAN_BTR1_TSEG1_MASK                      (0xFU)
#define CAN_BTR1_TSEG1_SHIFT                     (0U)
/*! TSEG1 - Time Segment 1
 *  0b0000..1 Tq clock cycles (This setting is not valid)
 *  0b0001..2 Tq clock cycles (This setting is not valid)
 *  0b0010..3 Tq clock cycles (This setting is not valid)
 *  0b0011..4 Tq clock cycles
 *  0b0100..5 Tq clock cycles
 *  0b0101..6 Tq clock cycles
 *  0b0110..7 Tq clock cycles
 *  0b0111..8 Tq clock cycles
 *  0b1000..9 Tq clock cycles
 *  0b1001..10 Tq clock cycles
 *  0b1010..11 Tq clock cycles
 *  0b1011..12 Tq clock cycles
 *  0b1100..13 Tq clock cycles
 *  0b1101..14 Tq clock cycles
 *  0b1110..15 Tq clock cycles
 *  0b1111..16 Tq clock cycles
 */
#define CAN_BTR1_TSEG1(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_BTR1_TSEG1_SHIFT)) & CAN_BTR1_TSEG1_MASK)

#define CAN_BTR1_TSEG2_MASK                      (0x70U)
#define CAN_BTR1_TSEG2_SHIFT                     (4U)
/*! TSEG2 - Time Segment 2
 *  0b000..1 Tq clock cycle (This setting is not valid)
 *  0b001..2 Tq clock cycles
 *  0b010..3 Tq clock cycles
 *  0b011..4 Tq clock cycles
 *  0b100..5 Tq clock cycles
 *  0b101..6 Tq clock cycles
 *  0b110..7 Tq clock cycles
 *  0b111..8 Tq clock cycles
 */
#define CAN_BTR1_TSEG2(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_BTR1_TSEG2_SHIFT)) & CAN_BTR1_TSEG2_MASK)

#define CAN_BTR1_SAMP_MASK                       (0x80U)
#define CAN_BTR1_SAMP_SHIFT                      (7U)
/*! SAMP - Sampling
 *  0b0..One sample per bit. The resulting bit value is equal to the value of the single bit positioned at the sample point.
 *  0b1..Three samples per bit. In this case, PHASE_SEG1 must be at least 2 time quanta (Tq). The resulting bit
 *       value is determined by using majority rule on the three total samples. For higher bit rates, it is
 *       recommended that only one sample is taken per bit time (SAMP=0)
 */
#define CAN_BTR1_SAMP(x)                         (((uint16_t)(((uint16_t)(x)) << CAN_BTR1_SAMP_SHIFT)) & CAN_BTR1_SAMP_MASK)
/*! @} */

/*! @name RFLG - MSCAN Receiver Flag Register */
/*! @{ */

#define CAN_RFLG_RXF_MASK                        (0x1U)
#define CAN_RFLG_RXF_SHIFT                       (0U)
/*! RXF - Receive Buffer Full Flag
 *  0b0..No new message available within the RxFG
 *  0b1..The receiver FIFO is not empty. A new message is available in the RxFG
 */
#define CAN_RFLG_RXF(x)                          (((uint16_t)(((uint16_t)(x)) << CAN_RFLG_RXF_SHIFT)) & CAN_RFLG_RXF_MASK)

#define CAN_RFLG_OVRIF_MASK                      (0x2U)
#define CAN_RFLG_OVRIF_SHIFT                     (1U)
/*! OVRIF - Overrun Interrupt Flag
 *  0b0..No data overrun condition
 *  0b1..A data overrun detected
 */
#define CAN_RFLG_OVRIF(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RFLG_OVRIF_SHIFT)) & CAN_RFLG_OVRIF_MASK)

#define CAN_RFLG_TSTAT_MASK                      (0xCU)
#define CAN_RFLG_TSTAT_SHIFT                     (2U)
/*! TSTAT - Transmitter Status Bits
 *  0b00..TxOK: 0 <= transmit error counter <= 96
 *  0b01..TxWRN: 96 < transmit error counter <= 127
 *  0b10..TxERR: 127 < transmit error counter <= 255
 *  0b11..Bus-Off: transmit error counter > 255
 */
#define CAN_RFLG_TSTAT(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RFLG_TSTAT_SHIFT)) & CAN_RFLG_TSTAT_MASK)

#define CAN_RFLG_RSTAT_MASK                      (0x30U)
#define CAN_RFLG_RSTAT_SHIFT                     (4U)
/*! RSTAT - Receiver Status Bits
 *  0b00..RxOK: 0 <= receiver error counter <= 96
 *  0b01..RxWRN: 96 < receiver error counter <= 127
 *  0b10..RxERR: 127 < receiver error counter <= 255
 *  0b11..Bus-Off: receiver error counter > 255
 */
#define CAN_RFLG_RSTAT(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RFLG_RSTAT_SHIFT)) & CAN_RFLG_RSTAT_MASK)

#define CAN_RFLG_CSCIF_MASK                      (0x40U)
#define CAN_RFLG_CSCIF_SHIFT                     (6U)
/*! CSCIF - CAN Status Change Interrupt Flag
 *  0b0..No change in CAN bus status occurred since last interrupt
 *  0b1..MSCAN changed current CAN bus status
 */
#define CAN_RFLG_CSCIF(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RFLG_CSCIF_SHIFT)) & CAN_RFLG_CSCIF_MASK)

#define CAN_RFLG_WUPIF_MASK                      (0x80U)
#define CAN_RFLG_WUPIF_SHIFT                     (7U)
/*! WUPIF - Wake-up Interrupt Flag
 *  0b0..No wakeup activity observed while in sleep mode
 *  0b1..MSCAN detected activity on the CAN bus and requested wakeup
 */
#define CAN_RFLG_WUPIF(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RFLG_WUPIF_SHIFT)) & CAN_RFLG_WUPIF_MASK)
/*! @} */

/*! @name RIER - MSCAN Receiver Interrupt Enable Register */
/*! @{ */

#define CAN_RIER_RXFIE_MASK                      (0x1U)
#define CAN_RIER_RXFIE_SHIFT                     (0U)
/*! RXFIE - Receiver Full Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..A receive buffer full (successful message reception) event causes a receiver interrupt request.
 */
#define CAN_RIER_RXFIE(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RIER_RXFIE_SHIFT)) & CAN_RIER_RXFIE_MASK)

#define CAN_RIER_OVRIE_MASK                      (0x2U)
#define CAN_RIER_OVRIE_SHIFT                     (1U)
/*! OVRIE - Overrun Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..An overrun event causes an error interrupt request.
 */
#define CAN_RIER_OVRIE(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RIER_OVRIE_SHIFT)) & CAN_RIER_OVRIE_MASK)

#define CAN_RIER_TSTATE_MASK                     (0xCU)
#define CAN_RIER_TSTATE_SHIFT                    (2U)
/*! TSTATE - Transmitter Status Change Enable
 *  0b00..Do not generate any CSCIF interrupt caused by transmitter state changes.
 *  0b01..Generate CSCIF interrupt only if the transmitter enters or leaves "bus-off" state. Discard other
 *        transmitter state changes for generating CSCIF interrupt.
 *  0b10..Generate CSCIF interrupt only if the transmitter enters or leaves "TxErr" or "bus-off" state. Discard
 *        other transmitter state changes for generating CSCIF interrupt.
 *  0b11..Generate CSCIF interrupt on all state changes.
 */
#define CAN_RIER_TSTATE(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_RIER_TSTATE_SHIFT)) & CAN_RIER_TSTATE_MASK)

#define CAN_RIER_RSTATE_MASK                     (0x30U)
#define CAN_RIER_RSTATE_SHIFT                    (4U)
/*! RSTATE - Receiver Status Change Enable
 *  0b00..Do not generate any CSCIF interrupt caused by transmitter state changes.
 *  0b01..Generate CSCIF interrupt only if the transmitter enters or leaves "bus-off" state. Discard other
 *        transmitter state changes for generating CSCIF interrupt.
 *  0b10..Generate CSCIF interrupt only if the transmitter enters or leaves "TxErr" or "bus-off" state. Discard
 *        other transmitter state changes for generating CSCIF interrupt.
 *  0b11..Generate CSCIF interrupt on all state changes.
 */
#define CAN_RIER_RSTATE(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_RIER_RSTATE_SHIFT)) & CAN_RIER_RSTATE_MASK)

#define CAN_RIER_CSCIE_MASK                      (0x40U)
#define CAN_RIER_CSCIE_SHIFT                     (6U)
/*! CSCIE - CAN Status Change Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..A CAN status change event causes an error interrupt request.
 */
#define CAN_RIER_CSCIE(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RIER_CSCIE_SHIFT)) & CAN_RIER_CSCIE_MASK)

#define CAN_RIER_WUPIE_MASK                      (0x80U)
#define CAN_RIER_WUPIE_SHIFT                     (7U)
/*! WUPIE - Wake-up Interrupt Enable
 *  0b0..No interrupt request is generated from this event.
 *  0b1..A wake-up event causes a Wake-Up interrupt request.
 */
#define CAN_RIER_WUPIE(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_RIER_WUPIE_SHIFT)) & CAN_RIER_WUPIE_MASK)
/*! @} */

/*! @name TFLG - MSCAN Transmitter Flag Register */
/*! @{ */

#define CAN_TFLG_TXE_MASK                        (0x7U)
#define CAN_TFLG_TXE_SHIFT                       (0U)
/*! TXE - Transmitter Buffer Empty
 *  0b000..The associated message buffer is full (loaded with a message due for transmission)
 *  0b001..The associated message buffer is empty (not scheduled)
 */
#define CAN_TFLG_TXE(x)                          (((uint16_t)(((uint16_t)(x)) << CAN_TFLG_TXE_SHIFT)) & CAN_TFLG_TXE_MASK)
/*! @} */

/*! @name TIER - MSCAN Transmitter Interrupt Enable Register */
/*! @{ */

#define CAN_TIER_TXEIE_MASK                      (0x7U)
#define CAN_TIER_TXEIE_SHIFT                     (0U)
/*! TXEIE - Transmitter Empty Interrupt Enable
 *  0b000..No interrupt request is generated from this event.
 *  0b001..A transmitter empty (transmit buffer available for transmission) event causes a transmitter empty interrupt request.
 */
#define CAN_TIER_TXEIE(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_TIER_TXEIE_SHIFT)) & CAN_TIER_TXEIE_MASK)
/*! @} */

/*! @name TARQ - MSCAN Transmitter Message Abort Request Register */
/*! @{ */

#define CAN_TARQ_ABTRQ_MASK                      (0x7U)
#define CAN_TARQ_ABTRQ_SHIFT                     (0U)
/*! ABTRQ - Abort Request
 *  0b000..No abort request
 *  0b001..Abort request pending
 */
#define CAN_TARQ_ABTRQ(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_TARQ_ABTRQ_SHIFT)) & CAN_TARQ_ABTRQ_MASK)
/*! @} */

/*! @name TAAK - MSCAN Transmitter Message Abort Acknowledge Register */
/*! @{ */

#define CAN_TAAK_ABTAK_MASK                      (0x7U)
#define CAN_TAAK_ABTAK_SHIFT                     (0U)
/*! ABTAK - Abort Acknowledge
 *  0b000..The message was not aborted.
 *  0b001..The message was aborted.
 */
#define CAN_TAAK_ABTAK(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_TAAK_ABTAK_SHIFT)) & CAN_TAAK_ABTAK_MASK)
/*! @} */

/*! @name TBSEL - MSCAN Transmit Buffer Selection Register */
/*! @{ */

#define CAN_TBSEL_TX_MASK                        (0x7U)
#define CAN_TBSEL_TX_SHIFT                       (0U)
/*! TX - Transmit Buffer Select
 *  0b000..The associated message buffer is deselected
 *  0b001..The associated message buffer is selected, if lowest numbered bit
 */
#define CAN_TBSEL_TX(x)                          (((uint16_t)(((uint16_t)(x)) << CAN_TBSEL_TX_SHIFT)) & CAN_TBSEL_TX_MASK)
/*! @} */

/*! @name IDAC - MSCAN Identifier Acceptance Control Register */
/*! @{ */

#define CAN_IDAC_IDHIT_MASK                      (0x7U)
#define CAN_IDAC_IDHIT_SHIFT                     (0U)
/*! IDHIT - Identifier Acceptance Hit Indicator
 *  0b000..Filter 0 Hit
 *  0b001..Filter 1 Hit
 *  0b010..Filter 2 Hit
 *  0b011..Filter 3 Hit
 *  0b100..Filter 4 Hit
 *  0b101..Filter 5 Hit
 *  0b110..Filter 6 Hit
 *  0b111..Filter 7 Hit
 */
#define CAN_IDAC_IDHIT(x)                        (((uint16_t)(((uint16_t)(x)) << CAN_IDAC_IDHIT_SHIFT)) & CAN_IDAC_IDHIT_MASK)

#define CAN_IDAC_IDAM_MASK                       (0x30U)
#define CAN_IDAC_IDAM_SHIFT                      (4U)
/*! IDAM - ID Acceptance Mode
 *  0b00..Two 32-Bit Acceptance Filters
 *  0b01..Four 16-Bit Acceptance Filters
 *  0b10..Eight 8-Bit Acceptance Filters
 *  0b11..Filter Closed
 */
#define CAN_IDAC_IDAM(x)                         (((uint16_t)(((uint16_t)(x)) << CAN_IDAC_IDAM_SHIFT)) & CAN_IDAC_IDAM_MASK)
/*! @} */

/*! @name MISC - MSCAN Miscellaneous Register */
/*! @{ */

#define CAN_MISC_BOHOLD_MASK                     (0x1U)
#define CAN_MISC_BOHOLD_SHIFT                    (0U)
/*! BOHOLD - Bus-off State Hold Until User Request
 *  0b0..Module is not in bus-off state, or recovery has been requested by user in bus-off state
 *  0b1..Module is in bus-off state and holds this state until user requests recovery
 */
#define CAN_MISC_BOHOLD(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_MISC_BOHOLD_SHIFT)) & CAN_MISC_BOHOLD_MASK)
/*! @} */

/*! @name RXERR - MSCAN Receive Error Counter Register */
/*! @{ */

#define CAN_RXERR_RXERR_MASK                     (0xFFU)
#define CAN_RXERR_RXERR_SHIFT                    (0U)
/*! RXERR - MSCAN Receive Error Counter Bits */
#define CAN_RXERR_RXERR(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_RXERR_RXERR_SHIFT)) & CAN_RXERR_RXERR_MASK)
/*! @} */

/*! @name TXERR - MSCAN Transmit Error Counter Register */
/*! @{ */

#define CAN_TXERR_TXERR_MASK                     (0xFFU)
#define CAN_TXERR_TXERR_SHIFT                    (0U)
/*! TXERR - MSCAN Transmit Error Counter Bits */
#define CAN_TXERR_TXERR(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_TXERR_TXERR_SHIFT)) & CAN_TXERR_TXERR_MASK)
/*! @} */

/*! @name IDAR_BANK_0 - MSCAN Identifier Acceptance Registers (First Bank) */
/*! @{ */

#define CAN_IDAR_BANK_0_AC_MASK                  (0xFFU)
#define CAN_IDAR_BANK_0_AC_SHIFT                 (0U)
/*! AC - Acceptance Code Bits */
#define CAN_IDAR_BANK_0_AC(x)                    (((uint16_t)(((uint16_t)(x)) << CAN_IDAR_BANK_0_AC_SHIFT)) & CAN_IDAR_BANK_0_AC_MASK)
/*! @} */

/*! @name IDMR_BANK_0 - MSCAN Identifier Mask Registers (First Bank) */
/*! @{ */

#define CAN_IDMR_BANK_0_AM_MASK                  (0xFFU)
#define CAN_IDMR_BANK_0_AM_SHIFT                 (0U)
/*! AM - Acceptance Mask Bits
 *  0b00000000..Match corresponding acceptance code register and identifier bits
 *  0b00000001..Ignore corresponding acceptance code register bit
 */
#define CAN_IDMR_BANK_0_AM(x)                    (((uint16_t)(((uint16_t)(x)) << CAN_IDMR_BANK_0_AM_SHIFT)) & CAN_IDMR_BANK_0_AM_MASK)
/*! @} */

/*! @name IDAR_BANK_1 - MSCAN Identifier Acceptance Registers (Second Bank) */
/*! @{ */

#define CAN_IDAR_BANK_1_AC_MASK                  (0xFFU)
#define CAN_IDAR_BANK_1_AC_SHIFT                 (0U)
/*! AC - Acceptance Code Bits */
#define CAN_IDAR_BANK_1_AC(x)                    (((uint16_t)(((uint16_t)(x)) << CAN_IDAR_BANK_1_AC_SHIFT)) & CAN_IDAR_BANK_1_AC_MASK)
/*! @} */

/*! @name IDMR_BANK_1 - MSCAN Identifier Mask Registers (Second Bank) */
/*! @{ */

#define CAN_IDMR_BANK_1_AM_MASK                  (0xFFU)
#define CAN_IDMR_BANK_1_AM_SHIFT                 (0U)
/*! AM - Acceptance Mask Bits
 *  0b00000000..Match corresponding acceptance code register and identifier bits
 *  0b00000001..Ignore corresponding acceptance code register bit
 */
#define CAN_IDMR_BANK_1_AM(x)                    (((uint16_t)(((uint16_t)(x)) << CAN_IDMR_BANK_1_AM_SHIFT)) & CAN_IDMR_BANK_1_AM_MASK)
/*! @} */

/*! @name RXFG_IDR0_EXT - MSCAN Receive and Transmit Buffer Identifier Register 0 - Extended Identifer Mapping */
/*! @{ */

#define CAN_RXFG_IDR0_EXT_ID_MASK                (0xFFU)
#define CAN_RXFG_IDR0_EXT_ID_SHIFT               (0U)
/*! ID - Extended Format Identifier */
#define CAN_RXFG_IDR0_EXT_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR0_EXT_ID_SHIFT)) & CAN_RXFG_IDR0_EXT_ID_MASK)
/*! @} */

/*! @name RXFG_IDR0_STD - MSCAN Receive and Transmit Buffer Identifier Register 0 - Standard Identifer Mapping */
/*! @{ */

#define CAN_RXFG_IDR0_STD_ID_MASK                (0xFFU)
#define CAN_RXFG_IDR0_STD_ID_SHIFT               (0U)
/*! ID - Standard Format Identifier */
#define CAN_RXFG_IDR0_STD_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR0_STD_ID_SHIFT)) & CAN_RXFG_IDR0_STD_ID_MASK)
/*! @} */

/*! @name RXFG_IDR1_EXT - MSCAN Receive and Transmit Buffer Identifier Register 1 - Extended Identifer Mapping */
/*! @{ */

#define CAN_RXFG_IDR1_EXT_ID_17_15_MASK          (0x7U)
#define CAN_RXFG_IDR1_EXT_ID_17_15_SHIFT         (0U)
/*! ID_17_15 - Extended Format Identifier */
#define CAN_RXFG_IDR1_EXT_ID_17_15(x)            (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR1_EXT_ID_17_15_SHIFT)) & CAN_RXFG_IDR1_EXT_ID_17_15_MASK)

#define CAN_RXFG_IDR1_EXT_IDE_MASK               (0x8U)
#define CAN_RXFG_IDR1_EXT_IDE_SHIFT              (3U)
/*! IDE - ID Extended (set to 1)
 *  0b0..Standard format (11 bit)
 *  0b1..Extended format (29 bit)
 */
#define CAN_RXFG_IDR1_EXT_IDE(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR1_EXT_IDE_SHIFT)) & CAN_RXFG_IDR1_EXT_IDE_MASK)

#define CAN_RXFG_IDR1_EXT_SRR_MASK               (0x10U)
#define CAN_RXFG_IDR1_EXT_SRR_SHIFT              (4U)
/*! SRR - Substitute Remote Request (set to 1) */
#define CAN_RXFG_IDR1_EXT_SRR(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR1_EXT_SRR_SHIFT)) & CAN_RXFG_IDR1_EXT_SRR_MASK)

#define CAN_RXFG_IDR1_EXT_ID_20_18_MASK          (0xE0U)
#define CAN_RXFG_IDR1_EXT_ID_20_18_SHIFT         (5U)
/*! ID_20_18 - Extended Format Identifier */
#define CAN_RXFG_IDR1_EXT_ID_20_18(x)            (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR1_EXT_ID_20_18_SHIFT)) & CAN_RXFG_IDR1_EXT_ID_20_18_MASK)
/*! @} */

/*! @name RXFG_IDR1_STD - MSCAN Receive and Transmit Buffer Identifier Register 1 - Standard Identifier Mapping */
/*! @{ */

#define CAN_RXFG_IDR1_STD_IDE_MASK               (0x8U)
#define CAN_RXFG_IDR1_STD_IDE_SHIFT              (3U)
/*! IDE - ID Extended (set to 0)
 *  0b0..Standard format (11 bit)
 *  0b1..Extended format (29 bit)
 */
#define CAN_RXFG_IDR1_STD_IDE(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR1_STD_IDE_SHIFT)) & CAN_RXFG_IDR1_STD_IDE_MASK)

#define CAN_RXFG_IDR1_STD_RTR_MASK               (0x10U)
#define CAN_RXFG_IDR1_STD_RTR_SHIFT              (4U)
/*! RTR - Remote Transmission Request
 *  0b0..Data frame
 *  0b1..Remote frame
 */
#define CAN_RXFG_IDR1_STD_RTR(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR1_STD_RTR_SHIFT)) & CAN_RXFG_IDR1_STD_RTR_MASK)

#define CAN_RXFG_IDR1_STD_ID_MASK                (0xE0U)
#define CAN_RXFG_IDR1_STD_ID_SHIFT               (5U)
/*! ID - Standard Format Identifier */
#define CAN_RXFG_IDR1_STD_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR1_STD_ID_SHIFT)) & CAN_RXFG_IDR1_STD_ID_MASK)
/*! @} */

/*! @name RXFG_IDR2_EXT - MSCAN Receive and Transmit Buffer Identifier Register 2 - Extended Identifer Mapping */
/*! @{ */

#define CAN_RXFG_IDR2_EXT_ID_MASK                (0xFFU)
#define CAN_RXFG_IDR2_EXT_ID_SHIFT               (0U)
/*! ID - Extended Format Identifier */
#define CAN_RXFG_IDR2_EXT_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR2_EXT_ID_SHIFT)) & CAN_RXFG_IDR2_EXT_ID_MASK)
/*! @} */

/*! @name RXFG_IDR3_EXT - MSCAN Receive and Transmit Buffer Identifier Register 3 - Extended Identifier Mapping */
/*! @{ */

#define CAN_RXFG_IDR3_EXT_RTR_MASK               (0x1U)
#define CAN_RXFG_IDR3_EXT_RTR_SHIFT              (0U)
/*! RTR - Remote Transmission Request
 *  0b0..Data frame
 *  0b1..Remote frame
 */
#define CAN_RXFG_IDR3_EXT_RTR(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR3_EXT_RTR_SHIFT)) & CAN_RXFG_IDR3_EXT_RTR_MASK)

#define CAN_RXFG_IDR3_EXT_ID_MASK                (0xFEU)
#define CAN_RXFG_IDR3_EXT_ID_SHIFT               (1U)
/*! ID - Extended Format Identifier */
#define CAN_RXFG_IDR3_EXT_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_IDR3_EXT_ID_SHIFT)) & CAN_RXFG_IDR3_EXT_ID_MASK)
/*! @} */

/*! @name RXFG_DSR - Receive Buffer Data Segment Registers */
/*! @{ */

#define CAN_RXFG_DSR_DB_MASK                     (0xFFU)
#define CAN_RXFG_DSR_DB_SHIFT                    (0U)
/*! DB - Data bits 7-0 */
#define CAN_RXFG_DSR_DB(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_DSR_DB_SHIFT)) & CAN_RXFG_DSR_DB_MASK)
/*! @} */

/*! @name RXFG_DLR - MSCAN Receive Buffer Data Length Register */
/*! @{ */

#define CAN_RXFG_DLR_DLC_MASK                    (0xFU)
#define CAN_RXFG_DLR_DLC_SHIFT                   (0U)
/*! DLC - Data Length Code
 *  0b0000..Data Byte Count 0
 *  0b0001..Data Byte Count 1
 *  0b0010..Data Byte Count 2
 *  0b0011..Data Byte Count 3
 *  0b0100..Data Byte Count 4
 *  0b0101..Data Byte Count 5
 *  0b0110..Data Byte Count 6
 *  0b0111..Data Byte Count 7
 *  0b1000..Data Byte Count 8
 */
#define CAN_RXFG_DLR_DLC(x)                      (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_DLR_DLC_SHIFT)) & CAN_RXFG_DLR_DLC_MASK)
/*! @} */

/*! @name RXFG_TSRH - Receive Buffer Time Stamp Register - High Byte */
/*! @{ */

#define CAN_RXFG_TSRH_TSR_MASK                   (0xFFU)
#define CAN_RXFG_TSRH_TSR_SHIFT                  (0U)
/*! TSR - Time Stamp Register Bits 15-8 */
#define CAN_RXFG_TSRH_TSR(x)                     (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_TSRH_TSR_SHIFT)) & CAN_RXFG_TSRH_TSR_MASK)
/*! @} */

/*! @name RXFG_TSRL - Receive Buffer Time Stamp Register - Low Byte */
/*! @{ */

#define CAN_RXFG_TSRL_TSR_MASK                   (0xFFU)
#define CAN_RXFG_TSRL_TSR_SHIFT                  (0U)
/*! TSR - Time Stamp Register Bits 7-0 */
#define CAN_RXFG_TSRL_TSR(x)                     (((uint16_t)(((uint16_t)(x)) << CAN_RXFG_TSRL_TSR_SHIFT)) & CAN_RXFG_TSRL_TSR_MASK)
/*! @} */

/*! @name TXFG_IDR0_EXT - MSCAN Receive and Transmit Buffer Identifier Register 0 - Extended Identifer Mapping */
/*! @{ */

#define CAN_TXFG_IDR0_EXT_ID_MASK                (0xFFU)
#define CAN_TXFG_IDR0_EXT_ID_SHIFT               (0U)
/*! ID - Extended Format Identifier */
#define CAN_TXFG_IDR0_EXT_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR0_EXT_ID_SHIFT)) & CAN_TXFG_IDR0_EXT_ID_MASK)
/*! @} */

/*! @name TXFG_IDR0_STD - MSCAN Receive and Transmit Buffer Identifier Register 0 - Standard Identifer Mapping */
/*! @{ */

#define CAN_TXFG_IDR0_STD_ID_MASK                (0xFFU)
#define CAN_TXFG_IDR0_STD_ID_SHIFT               (0U)
/*! ID - Standard Format Identifier */
#define CAN_TXFG_IDR0_STD_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR0_STD_ID_SHIFT)) & CAN_TXFG_IDR0_STD_ID_MASK)
/*! @} */

/*! @name TXFG_IDR1_EXT - MSCAN Receive and Transmit Buffer Identifier Register 1 - Extended Identifer Mapping */
/*! @{ */

#define CAN_TXFG_IDR1_EXT_ID_17_15_MASK          (0x7U)
#define CAN_TXFG_IDR1_EXT_ID_17_15_SHIFT         (0U)
/*! ID_17_15 - Extended Format Identifier */
#define CAN_TXFG_IDR1_EXT_ID_17_15(x)            (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR1_EXT_ID_17_15_SHIFT)) & CAN_TXFG_IDR1_EXT_ID_17_15_MASK)

#define CAN_TXFG_IDR1_EXT_IDE_MASK               (0x8U)
#define CAN_TXFG_IDR1_EXT_IDE_SHIFT              (3U)
/*! IDE - ID Extended (set to 1)
 *  0b0..Standard format (11 bit)
 *  0b1..Extended format (29 bit)
 */
#define CAN_TXFG_IDR1_EXT_IDE(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR1_EXT_IDE_SHIFT)) & CAN_TXFG_IDR1_EXT_IDE_MASK)

#define CAN_TXFG_IDR1_EXT_SRR_MASK               (0x10U)
#define CAN_TXFG_IDR1_EXT_SRR_SHIFT              (4U)
/*! SRR - Substitute Remote Request (set to 1) */
#define CAN_TXFG_IDR1_EXT_SRR(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR1_EXT_SRR_SHIFT)) & CAN_TXFG_IDR1_EXT_SRR_MASK)

#define CAN_TXFG_IDR1_EXT_ID_20_18_MASK          (0xE0U)
#define CAN_TXFG_IDR1_EXT_ID_20_18_SHIFT         (5U)
/*! ID_20_18 - Extended Format Identifier */
#define CAN_TXFG_IDR1_EXT_ID_20_18(x)            (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR1_EXT_ID_20_18_SHIFT)) & CAN_TXFG_IDR1_EXT_ID_20_18_MASK)
/*! @} */

/*! @name TXFG_IDR1_STD - MSCAN Receive and Transmit Buffer Identifier Register 1 - Standard Identifier Mapping */
/*! @{ */

#define CAN_TXFG_IDR1_STD_IDE_MASK               (0x8U)
#define CAN_TXFG_IDR1_STD_IDE_SHIFT              (3U)
/*! IDE - ID Extended (set to 0)
 *  0b0..Standard format (11 bit)
 *  0b1..Extended format (29 bit)
 */
#define CAN_TXFG_IDR1_STD_IDE(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR1_STD_IDE_SHIFT)) & CAN_TXFG_IDR1_STD_IDE_MASK)

#define CAN_TXFG_IDR1_STD_RTR_MASK               (0x10U)
#define CAN_TXFG_IDR1_STD_RTR_SHIFT              (4U)
/*! RTR - Remote Transmission Request
 *  0b0..Data frame
 *  0b1..Remote frame
 */
#define CAN_TXFG_IDR1_STD_RTR(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR1_STD_RTR_SHIFT)) & CAN_TXFG_IDR1_STD_RTR_MASK)

#define CAN_TXFG_IDR1_STD_ID_MASK                (0xE0U)
#define CAN_TXFG_IDR1_STD_ID_SHIFT               (5U)
/*! ID - Standard Format Identifier */
#define CAN_TXFG_IDR1_STD_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR1_STD_ID_SHIFT)) & CAN_TXFG_IDR1_STD_ID_MASK)
/*! @} */

/*! @name TXFG_IDR2_EXT - MSCAN Receive and Transmit Buffer Identifier Register 2 - Extended Identifer Mapping */
/*! @{ */

#define CAN_TXFG_IDR2_EXT_ID_MASK                (0xFFU)
#define CAN_TXFG_IDR2_EXT_ID_SHIFT               (0U)
/*! ID - Extended Format Identifier */
#define CAN_TXFG_IDR2_EXT_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR2_EXT_ID_SHIFT)) & CAN_TXFG_IDR2_EXT_ID_MASK)
/*! @} */

/*! @name TXFG_IDR3_EXT - MSCAN Receive and Transmit Buffer Identifier Register 3 - Extended Identifier Mapping */
/*! @{ */

#define CAN_TXFG_IDR3_EXT_RTR_MASK               (0x1U)
#define CAN_TXFG_IDR3_EXT_RTR_SHIFT              (0U)
/*! RTR - Remote Transmission Request
 *  0b0..Data frame
 *  0b1..Remote frame
 */
#define CAN_TXFG_IDR3_EXT_RTR(x)                 (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR3_EXT_RTR_SHIFT)) & CAN_TXFG_IDR3_EXT_RTR_MASK)

#define CAN_TXFG_IDR3_EXT_ID_MASK                (0xFEU)
#define CAN_TXFG_IDR3_EXT_ID_SHIFT               (1U)
/*! ID - Extended Format Identifier */
#define CAN_TXFG_IDR3_EXT_ID(x)                  (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_IDR3_EXT_ID_SHIFT)) & CAN_TXFG_IDR3_EXT_ID_MASK)
/*! @} */

/*! @name TXFG_DSR - Transmit Buffer Data Segment Registers */
/*! @{ */

#define CAN_TXFG_DSR_DB_MASK                     (0xFFU)
#define CAN_TXFG_DSR_DB_SHIFT                    (0U)
/*! DB - Data bits 7-0 */
#define CAN_TXFG_DSR_DB(x)                       (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_DSR_DB_SHIFT)) & CAN_TXFG_DSR_DB_MASK)
/*! @} */

/*! @name TXFG_DLR - MSCAN Transmit Buffer Data Length Register */
/*! @{ */

#define CAN_TXFG_DLR_DLC_MASK                    (0xFU)
#define CAN_TXFG_DLR_DLC_SHIFT                   (0U)
/*! DLC - Data Length Code
 *  0b0000..Data Byte Count 0
 *  0b0001..Data Byte Count 1
 *  0b0010..Data Byte Count 2
 *  0b0011..Data Byte Count 3
 *  0b0100..Data Byte Count 4
 *  0b0101..Data Byte Count 5
 *  0b0110..Data Byte Count 6
 *  0b0111..Data Byte Count 7
 *  0b1000..Data Byte Count 8
 */
#define CAN_TXFG_DLR_DLC(x)                      (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_DLR_DLC_SHIFT)) & CAN_TXFG_DLR_DLC_MASK)
/*! @} */

/*! @name TXFG_TBPR - MSCAN Transmit Buffer Priority Register */
/*! @{ */

#define CAN_TXFG_TBPR_PRIO_MASK                  (0xFFU)
#define CAN_TXFG_TBPR_PRIO_SHIFT                 (0U)
/*! PRIO - Priority bits */
#define CAN_TXFG_TBPR_PRIO(x)                    (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_TBPR_PRIO_SHIFT)) & CAN_TXFG_TBPR_PRIO_MASK)
/*! @} */

/*! @name TXFG_TSRH - Transmit Buffer Time Stamp Register - High Byte */
/*! @{ */

#define CAN_TXFG_TSRH_TSR_MASK                   (0xFFU)
#define CAN_TXFG_TSRH_TSR_SHIFT                  (0U)
/*! TSR - Time Stamp Register Bits 15-8 */
#define CAN_TXFG_TSRH_TSR(x)                     (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_TSRH_TSR_SHIFT)) & CAN_TXFG_TSRH_TSR_MASK)
/*! @} */

/*! @name TXFG_TSRL - Transmit Buffer Time Stamp Register - Low Byte */
/*! @{ */

#define CAN_TXFG_TSRL_TSR_MASK                   (0xFFU)
#define CAN_TXFG_TSRL_TSR_SHIFT                  (0U)
/*! TSR - Time Stamp Register Bits 7-0 */
#define CAN_TXFG_TSRL_TSR(x)                     (((uint16_t)(((uint16_t)(x)) << CAN_TXFG_TSRL_TSR_SHIFT)) & CAN_TXFG_TSRL_TSR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAN_Register_Masks */


/*!
 * @}
 */ /* end of group CAN_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_CAN_H_ */

