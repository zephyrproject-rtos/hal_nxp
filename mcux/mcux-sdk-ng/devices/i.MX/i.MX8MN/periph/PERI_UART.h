/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for UART
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_UART.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for UART
 *
 * CMSIS Peripheral Access Layer for UART
 */

#if !defined(PERI_UART_H_)
#define PERI_UART_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __I  uint32_t URXD;                              /**< UART Receiver Register, offset: 0x0 */
       uint8_t RESERVED_0[60];
  __O  uint32_t UTXD;                              /**< UART Transmitter Register, offset: 0x40 */
       uint8_t RESERVED_1[60];
  __IO uint32_t UCR1;                              /**< UART Control Register 1, offset: 0x80 */
  __IO uint32_t UCR2;                              /**< UART Control Register 2, offset: 0x84 */
  __IO uint32_t UCR3;                              /**< UART Control Register 3, offset: 0x88 */
  __IO uint32_t UCR4;                              /**< UART Control Register 4, offset: 0x8C */
  __IO uint32_t UFCR;                              /**< UART FIFO Control Register, offset: 0x90 */
  __IO uint32_t USR1;                              /**< UART Status Register 1, offset: 0x94 */
  __IO uint32_t USR2;                              /**< UART Status Register 2, offset: 0x98 */
  __IO uint32_t UESC;                              /**< UART Escape Character Register, offset: 0x9C */
  __IO uint32_t UTIM;                              /**< UART Escape Timer Register, offset: 0xA0 */
  __IO uint32_t UBIR;                              /**< UART BRM Incremental Register, offset: 0xA4 */
  __IO uint32_t UBMR;                              /**< UART BRM Modulator Register, offset: 0xA8 */
  __I  uint32_t UBRC;                              /**< UART Baud Rate Count Register, offset: 0xAC */
  __IO uint32_t ONEMS;                             /**< UART One Millisecond Register, offset: 0xB0 */
  __IO uint32_t UTS;                               /**< UART Test Register, offset: 0xB4 */
  __IO uint32_t UMCR;                              /**< UART RS-485 Mode Control Register, offset: 0xB8 */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/*! @name URXD - UART Receiver Register */
/*! @{ */

#define UART_URXD_RX_DATA_MASK                   (0xFFU)
#define UART_URXD_RX_DATA_SHIFT                  (0U)
#define UART_URXD_RX_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << UART_URXD_RX_DATA_SHIFT)) & UART_URXD_RX_DATA_MASK)

#define UART_URXD_PRERR_MASK                     (0x400U)
#define UART_URXD_PRERR_SHIFT                    (10U)
/*! PRERR
 *  0b0..= No parity error was detected for data in the RX_DATA field
 *  0b1..= A parity error was detected for data in the RX_DATA field
 */
#define UART_URXD_PRERR(x)                       (((uint32_t)(((uint32_t)(x)) << UART_URXD_PRERR_SHIFT)) & UART_URXD_PRERR_MASK)

#define UART_URXD_BRK_MASK                       (0x800U)
#define UART_URXD_BRK_SHIFT                      (11U)
/*! BRK
 *  0b0..The current character is not a BREAK character
 *  0b1..The current character is a BREAK character
 */
#define UART_URXD_BRK(x)                         (((uint32_t)(((uint32_t)(x)) << UART_URXD_BRK_SHIFT)) & UART_URXD_BRK_MASK)

#define UART_URXD_FRMERR_MASK                    (0x1000U)
#define UART_URXD_FRMERR_SHIFT                   (12U)
/*! FRMERR
 *  0b0..The current character has no framing error
 *  0b1..The current character has a framing error
 */
#define UART_URXD_FRMERR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_URXD_FRMERR_SHIFT)) & UART_URXD_FRMERR_MASK)

#define UART_URXD_OVRRUN_MASK                    (0x2000U)
#define UART_URXD_OVRRUN_SHIFT                   (13U)
/*! OVRRUN
 *  0b0..No RxFIFO overrun was detected
 *  0b1..A RxFIFO overrun was detected
 */
#define UART_URXD_OVRRUN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_URXD_OVRRUN_SHIFT)) & UART_URXD_OVRRUN_MASK)

#define UART_URXD_ERR_MASK                       (0x4000U)
#define UART_URXD_ERR_SHIFT                      (14U)
/*! ERR
 *  0b0..No error status was detected
 *  0b1..An error status was detected
 */
#define UART_URXD_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_URXD_ERR_SHIFT)) & UART_URXD_ERR_MASK)

#define UART_URXD_CHARRDY_MASK                   (0x8000U)
#define UART_URXD_CHARRDY_SHIFT                  (15U)
/*! CHARRDY
 *  0b0..Character in RX_DATA field and associated flags are invalid.
 *  0b1..Character in RX_DATA field and associated flags valid and ready for reading.
 */
#define UART_URXD_CHARRDY(x)                     (((uint32_t)(((uint32_t)(x)) << UART_URXD_CHARRDY_SHIFT)) & UART_URXD_CHARRDY_MASK)
/*! @} */

/*! @name UTXD - UART Transmitter Register */
/*! @{ */

#define UART_UTXD_TX_DATA_MASK                   (0xFFU)
#define UART_UTXD_TX_DATA_SHIFT                  (0U)
#define UART_UTXD_TX_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UTXD_TX_DATA_SHIFT)) & UART_UTXD_TX_DATA_MASK)
/*! @} */

/*! @name UCR1 - UART Control Register 1 */
/*! @{ */

#define UART_UCR1_UARTEN_MASK                    (0x1U)
#define UART_UCR1_UARTEN_SHIFT                   (0U)
/*! UARTEN
 *  0b0..Disable the UART
 *  0b1..Enable the UART
 */
#define UART_UCR1_UARTEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_UARTEN_SHIFT)) & UART_UCR1_UARTEN_MASK)

#define UART_UCR1_DOZE_MASK                      (0x2U)
#define UART_UCR1_DOZE_SHIFT                     (1U)
/*! DOZE
 *  0b0..The UART is enabled when in DOZE state
 *  0b1..The UART is disabled when in DOZE state
 */
#define UART_UCR1_DOZE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_DOZE_SHIFT)) & UART_UCR1_DOZE_MASK)

#define UART_UCR1_ATDMAEN_MASK                   (0x4U)
#define UART_UCR1_ATDMAEN_SHIFT                  (2U)
/*! ATDMAEN
 *  0b0..Disable AGTIM DMA request
 *  0b1..Enable AGTIM DMA request
 */
#define UART_UCR1_ATDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ATDMAEN_SHIFT)) & UART_UCR1_ATDMAEN_MASK)

#define UART_UCR1_TXDMAEN_MASK                   (0x8U)
#define UART_UCR1_TXDMAEN_SHIFT                  (3U)
/*! TXDMAEN
 *  0b0..Disable transmit DMA request
 *  0b1..Enable transmit DMA request
 */
#define UART_UCR1_TXDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TXDMAEN_SHIFT)) & UART_UCR1_TXDMAEN_MASK)

#define UART_UCR1_SNDBRK_MASK                    (0x10U)
#define UART_UCR1_SNDBRK_SHIFT                   (4U)
/*! SNDBRK
 *  0b0..Do not send a BREAK character
 *  0b1..Send a BREAK character (continuous 0s)
 */
#define UART_UCR1_SNDBRK(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_SNDBRK_SHIFT)) & UART_UCR1_SNDBRK_MASK)

#define UART_UCR1_RTSDEN_MASK                    (0x20U)
#define UART_UCR1_RTSDEN_SHIFT                   (5U)
/*! RTSDEN
 *  0b0..Disable RTSD interrupt
 *  0b1..Enable RTSD interrupt
 */
#define UART_UCR1_RTSDEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RTSDEN_SHIFT)) & UART_UCR1_RTSDEN_MASK)

#define UART_UCR1_TXMPTYEN_MASK                  (0x40U)
#define UART_UCR1_TXMPTYEN_SHIFT                 (6U)
/*! TXMPTYEN
 *  0b0..Disable the transmitter FIFO empty interrupt
 *  0b1..Enable the transmitter FIFO empty interrupt
 */
#define UART_UCR1_TXMPTYEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TXMPTYEN_SHIFT)) & UART_UCR1_TXMPTYEN_MASK)

#define UART_UCR1_IREN_MASK                      (0x80U)
#define UART_UCR1_IREN_SHIFT                     (7U)
/*! IREN
 *  0b0..Disable the IR interface
 *  0b1..Enable the IR interface
 */
#define UART_UCR1_IREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_IREN_SHIFT)) & UART_UCR1_IREN_MASK)

#define UART_UCR1_RXDMAEN_MASK                   (0x100U)
#define UART_UCR1_RXDMAEN_SHIFT                  (8U)
/*! RXDMAEN
 *  0b0..Disable DMA request
 *  0b1..Enable DMA request
 */
#define UART_UCR1_RXDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RXDMAEN_SHIFT)) & UART_UCR1_RXDMAEN_MASK)

#define UART_UCR1_RRDYEN_MASK                    (0x200U)
#define UART_UCR1_RRDYEN_SHIFT                   (9U)
/*! RRDYEN
 *  0b0..Disables the RRDY interrupt
 *  0b1..Enables the RRDY interrupt
 */
#define UART_UCR1_RRDYEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RRDYEN_SHIFT)) & UART_UCR1_RRDYEN_MASK)

#define UART_UCR1_ICD_MASK                       (0xC00U)
#define UART_UCR1_ICD_SHIFT                      (10U)
/*! ICD
 *  0b00..Idle for more than 4 frames
 *  0b01..Idle for more than 8 frames
 *  0b10..Idle for more than 16 frames
 *  0b11..Idle for more than 32 frames
 */
#define UART_UCR1_ICD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ICD_SHIFT)) & UART_UCR1_ICD_MASK)

#define UART_UCR1_IDEN_MASK                      (0x1000U)
#define UART_UCR1_IDEN_SHIFT                     (12U)
/*! IDEN
 *  0b0..Disable the IDLE interrupt
 *  0b1..Enable the IDLE interrupt
 */
#define UART_UCR1_IDEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_IDEN_SHIFT)) & UART_UCR1_IDEN_MASK)

#define UART_UCR1_TRDYEN_MASK                    (0x2000U)
#define UART_UCR1_TRDYEN_SHIFT                   (13U)
/*! TRDYEN
 *  0b0..Disable the transmitter ready interrupt
 *  0b1..Enable the transmitter ready interrupt
 */
#define UART_UCR1_TRDYEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TRDYEN_SHIFT)) & UART_UCR1_TRDYEN_MASK)

#define UART_UCR1_ADBR_MASK                      (0x4000U)
#define UART_UCR1_ADBR_SHIFT                     (14U)
/*! ADBR
 *  0b0..Disable automatic detection of baud rate
 *  0b1..Enable automatic detection of baud rate
 */
#define UART_UCR1_ADBR(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ADBR_SHIFT)) & UART_UCR1_ADBR_MASK)

#define UART_UCR1_ADEN_MASK                      (0x8000U)
#define UART_UCR1_ADEN_SHIFT                     (15U)
/*! ADEN
 *  0b0..Disable the automatic baud rate detection interrupt
 *  0b1..Enable the automatic baud rate detection interrupt
 */
#define UART_UCR1_ADEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ADEN_SHIFT)) & UART_UCR1_ADEN_MASK)
/*! @} */

/*! @name UCR2 - UART Control Register 2 */
/*! @{ */

#define UART_UCR2_SRST_MASK                      (0x1U)
#define UART_UCR2_SRST_SHIFT                     (0U)
/*! SRST
 *  0b0..Reset the transmit and receive state machines, all FIFOs and register USR1, USR2, UBIR, UBMR, UBRC , URXD, UTXD and UTS[6-3].
 *  0b1..No reset
 */
#define UART_UCR2_SRST(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_SRST_SHIFT)) & UART_UCR2_SRST_MASK)

#define UART_UCR2_RXEN_MASK                      (0x2U)
#define UART_UCR2_RXEN_SHIFT                     (1U)
/*! RXEN
 *  0b0..Disable the receiver
 *  0b1..Enable the receiver
 */
#define UART_UCR2_RXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RXEN_SHIFT)) & UART_UCR2_RXEN_MASK)

#define UART_UCR2_TXEN_MASK                      (0x4U)
#define UART_UCR2_TXEN_SHIFT                     (2U)
/*! TXEN
 *  0b0..Disable the transmitter
 *  0b1..Enable the transmitter
 */
#define UART_UCR2_TXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_TXEN_SHIFT)) & UART_UCR2_TXEN_MASK)

#define UART_UCR2_ATEN_MASK                      (0x8U)
#define UART_UCR2_ATEN_SHIFT                     (3U)
/*! ATEN
 *  0b0..AGTIM interrupt disabled
 *  0b1..AGTIM interrupt enabled
 */
#define UART_UCR2_ATEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ATEN_SHIFT)) & UART_UCR2_ATEN_MASK)

#define UART_UCR2_RTSEN_MASK                     (0x10U)
#define UART_UCR2_RTSEN_SHIFT                    (4U)
/*! RTSEN
 *  0b0..Disable request to send interrupt
 *  0b1..Enable request to send interrupt
 */
#define UART_UCR2_RTSEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RTSEN_SHIFT)) & UART_UCR2_RTSEN_MASK)

#define UART_UCR2_WS_MASK                        (0x20U)
#define UART_UCR2_WS_SHIFT                       (5U)
/*! WS
 *  0b0..7-bit transmit and receive character length (not including START, STOP or PARITY bits)
 *  0b1..8-bit transmit and receive character length (not including START, STOP or PARITY bits)
 */
#define UART_UCR2_WS(x)                          (((uint32_t)(((uint32_t)(x)) << UART_UCR2_WS_SHIFT)) & UART_UCR2_WS_MASK)

#define UART_UCR2_STPB_MASK                      (0x40U)
#define UART_UCR2_STPB_SHIFT                     (6U)
/*! STPB
 *  0b0..The transmitter sends 1 stop bit. The receiver expects 1 or more stop bits.
 *  0b1..The transmitter sends 2 stop bits. The receiver expects 2 or more stop bits.
 */
#define UART_UCR2_STPB(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_STPB_SHIFT)) & UART_UCR2_STPB_MASK)

#define UART_UCR2_PROE_MASK                      (0x80U)
#define UART_UCR2_PROE_SHIFT                     (7U)
/*! PROE
 *  0b0..Even parity
 *  0b1..Odd parity
 */
#define UART_UCR2_PROE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_PROE_SHIFT)) & UART_UCR2_PROE_MASK)

#define UART_UCR2_PREN_MASK                      (0x100U)
#define UART_UCR2_PREN_SHIFT                     (8U)
/*! PREN
 *  0b0..Disable parity generator and checker
 *  0b1..Enable parity generator and checker
 */
#define UART_UCR2_PREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_PREN_SHIFT)) & UART_UCR2_PREN_MASK)

#define UART_UCR2_RTEC_MASK                      (0x600U)
#define UART_UCR2_RTEC_SHIFT                     (9U)
/*! RTEC
 *  0b00..Trigger interrupt on a rising edge
 *  0b01..Trigger interrupt on a falling edge
 *  0b1x..Trigger interrupt on any edge
 */
#define UART_UCR2_RTEC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RTEC_SHIFT)) & UART_UCR2_RTEC_MASK)

#define UART_UCR2_ESCEN_MASK                     (0x800U)
#define UART_UCR2_ESCEN_SHIFT                    (11U)
/*! ESCEN
 *  0b0..Disable escape sequence detection
 *  0b1..Enable escape sequence detection
 */
#define UART_UCR2_ESCEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ESCEN_SHIFT)) & UART_UCR2_ESCEN_MASK)

#define UART_UCR2_CTS_MASK                       (0x1000U)
#define UART_UCR2_CTS_SHIFT                      (12U)
/*! CTS
 *  0b0..The CTS_B pin is high (inactive)
 *  0b1..The CTS_B pin is low (active)
 */
#define UART_UCR2_CTS(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR2_CTS_SHIFT)) & UART_UCR2_CTS_MASK)

#define UART_UCR2_CTSC_MASK                      (0x2000U)
#define UART_UCR2_CTSC_SHIFT                     (13U)
/*! CTSC
 *  0b0..The CTS_B pin is controlled by the CTS bit
 *  0b1..The CTS_B pin is controlled by the receiver
 */
#define UART_UCR2_CTSC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_CTSC_SHIFT)) & UART_UCR2_CTSC_MASK)

#define UART_UCR2_IRTS_MASK                      (0x4000U)
#define UART_UCR2_IRTS_SHIFT                     (14U)
/*! IRTS
 *  0b0..Transmit only when the RTS pin is asserted
 *  0b1..Ignore the RTS pin
 */
#define UART_UCR2_IRTS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_IRTS_SHIFT)) & UART_UCR2_IRTS_MASK)

#define UART_UCR2_ESCI_MASK                      (0x8000U)
#define UART_UCR2_ESCI_SHIFT                     (15U)
/*! ESCI
 *  0b0..Disable the escape sequence interrupt
 *  0b1..Enable the escape sequence interrupt
 */
#define UART_UCR2_ESCI(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ESCI_SHIFT)) & UART_UCR2_ESCI_MASK)
/*! @} */

/*! @name UCR3 - UART Control Register 3 */
/*! @{ */

#define UART_UCR3_ACIEN_MASK                     (0x1U)
#define UART_UCR3_ACIEN_SHIFT                    (0U)
/*! ACIEN
 *  0b0..ACST interrupt disabled
 *  0b1..ACST interrupt enabled
 */
#define UART_UCR3_ACIEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR3_ACIEN_SHIFT)) & UART_UCR3_ACIEN_MASK)

#define UART_UCR3_INVT_MASK                      (0x2U)
#define UART_UCR3_INVT_SHIFT                     (1U)
/*! INVT
 *  0b0..TXD Active low transmission
 *  0b0..TXD is not inverted
 *  0b1..TXD Active high transmission
 *  0b1..TXD is inverted
 */
#define UART_UCR3_INVT(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR3_INVT_SHIFT)) & UART_UCR3_INVT_MASK)

#define UART_UCR3_RXDMUXSEL_MASK                 (0x4U)
#define UART_UCR3_RXDMUXSEL_SHIFT                (2U)
#define UART_UCR3_RXDMUXSEL(x)                   (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RXDMUXSEL_SHIFT)) & UART_UCR3_RXDMUXSEL_MASK)

#define UART_UCR3_DTRDEN_MASK                    (0x8U)
#define UART_UCR3_DTRDEN_SHIFT                   (3U)
#define UART_UCR3_DTRDEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DTRDEN_SHIFT)) & UART_UCR3_DTRDEN_MASK)

#define UART_UCR3_AWAKEN_MASK                    (0x10U)
#define UART_UCR3_AWAKEN_SHIFT                   (4U)
/*! AWAKEN
 *  0b0..Disable the AWAKE interrupt
 *  0b1..Enable the AWAKE interrupt
 */
#define UART_UCR3_AWAKEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_AWAKEN_SHIFT)) & UART_UCR3_AWAKEN_MASK)

#define UART_UCR3_AIRINTEN_MASK                  (0x20U)
#define UART_UCR3_AIRINTEN_SHIFT                 (5U)
/*! AIRINTEN
 *  0b0..Disable the AIRINT interrupt
 *  0b1..Enable the AIRINT interrupt
 */
#define UART_UCR3_AIRINTEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_AIRINTEN_SHIFT)) & UART_UCR3_AIRINTEN_MASK)

#define UART_UCR3_RXDSEN_MASK                    (0x40U)
#define UART_UCR3_RXDSEN_SHIFT                   (6U)
/*! RXDSEN
 *  0b0..Disable the RXDS interrupt
 *  0b1..Enable the RXDS interrupt
 */
#define UART_UCR3_RXDSEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RXDSEN_SHIFT)) & UART_UCR3_RXDSEN_MASK)

#define UART_UCR3_ADNIMP_MASK                    (0x80U)
#define UART_UCR3_ADNIMP_SHIFT                   (7U)
/*! ADNIMP
 *  0b0..Autobaud detection new features selected
 *  0b1..Keep old autobaud detection mechanism
 */
#define UART_UCR3_ADNIMP(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_ADNIMP_SHIFT)) & UART_UCR3_ADNIMP_MASK)

#define UART_UCR3_RI_MASK                        (0x100U)
#define UART_UCR3_RI_SHIFT                       (8U)
#define UART_UCR3_RI(x)                          (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RI_SHIFT)) & UART_UCR3_RI_MASK)

#define UART_UCR3_DCD_MASK                       (0x200U)
#define UART_UCR3_DCD_SHIFT                      (9U)
#define UART_UCR3_DCD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DCD_SHIFT)) & UART_UCR3_DCD_MASK)

#define UART_UCR3_DSR_MASK                       (0x400U)
#define UART_UCR3_DSR_SHIFT                      (10U)
#define UART_UCR3_DSR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DSR_SHIFT)) & UART_UCR3_DSR_MASK)

#define UART_UCR3_FRAERREN_MASK                  (0x800U)
#define UART_UCR3_FRAERREN_SHIFT                 (11U)
/*! FRAERREN
 *  0b0..Disable the frame error interrupt
 *  0b1..Enable the frame error interrupt
 */
#define UART_UCR3_FRAERREN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_FRAERREN_SHIFT)) & UART_UCR3_FRAERREN_MASK)

#define UART_UCR3_PARERREN_MASK                  (0x1000U)
#define UART_UCR3_PARERREN_SHIFT                 (12U)
/*! PARERREN
 *  0b0..Disable the parity error interrupt
 *  0b1..Enable the parity error interrupt
 */
#define UART_UCR3_PARERREN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_PARERREN_SHIFT)) & UART_UCR3_PARERREN_MASK)

#define UART_UCR3_DTREN_MASK                     (0x2000U)
#define UART_UCR3_DTREN_SHIFT                    (13U)
#define UART_UCR3_DTREN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DTREN_SHIFT)) & UART_UCR3_DTREN_MASK)

#define UART_UCR3_DPEC_MASK                      (0xC000U)
#define UART_UCR3_DPEC_SHIFT                     (14U)
#define UART_UCR3_DPEC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DPEC_SHIFT)) & UART_UCR3_DPEC_MASK)
/*! @} */

/*! @name UCR4 - UART Control Register 4 */
/*! @{ */

#define UART_UCR4_DREN_MASK                      (0x1U)
#define UART_UCR4_DREN_SHIFT                     (0U)
/*! DREN
 *  0b0..Disable RDR interrupt
 *  0b1..Enable RDR interrupt
 */
#define UART_UCR4_DREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_DREN_SHIFT)) & UART_UCR4_DREN_MASK)

#define UART_UCR4_OREN_MASK                      (0x2U)
#define UART_UCR4_OREN_SHIFT                     (1U)
/*! OREN
 *  0b0..Disable ORE interrupt
 *  0b1..Enable ORE interrupt
 */
#define UART_UCR4_OREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_OREN_SHIFT)) & UART_UCR4_OREN_MASK)

#define UART_UCR4_BKEN_MASK                      (0x4U)
#define UART_UCR4_BKEN_SHIFT                     (2U)
/*! BKEN
 *  0b0..Disable the BRCD interrupt
 *  0b1..Enable the BRCD interrupt
 */
#define UART_UCR4_BKEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_BKEN_SHIFT)) & UART_UCR4_BKEN_MASK)

#define UART_UCR4_TCEN_MASK                      (0x8U)
#define UART_UCR4_TCEN_SHIFT                     (3U)
/*! TCEN
 *  0b0..Disable TXDC interrupt
 *  0b1..Enable TXDC interrupt
 */
#define UART_UCR4_TCEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_TCEN_SHIFT)) & UART_UCR4_TCEN_MASK)

#define UART_UCR4_LPBYP_MASK                     (0x10U)
#define UART_UCR4_LPBYP_SHIFT                    (4U)
/*! LPBYP
 *  0b0..Low power features enabled
 *  0b1..Low power features disabled
 */
#define UART_UCR4_LPBYP(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_LPBYP_SHIFT)) & UART_UCR4_LPBYP_MASK)

#define UART_UCR4_IRSC_MASK                      (0x20U)
#define UART_UCR4_IRSC_SHIFT                     (5U)
/*! IRSC
 *  0b0..The vote logic uses the sampling clock (16x baud rate) for normal operation
 *  0b1..The vote logic uses the UART reference clock
 */
#define UART_UCR4_IRSC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_IRSC_SHIFT)) & UART_UCR4_IRSC_MASK)

#define UART_UCR4_IDDMAEN_MASK                   (0x40U)
#define UART_UCR4_IDDMAEN_SHIFT                  (6U)
/*! IDDMAEN
 *  0b0..DMA IDLE interrupt disabled
 *  0b1..DMA IDLE interrupt enabled
 */
#define UART_UCR4_IDDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR4_IDDMAEN_SHIFT)) & UART_UCR4_IDDMAEN_MASK)

#define UART_UCR4_WKEN_MASK                      (0x80U)
#define UART_UCR4_WKEN_SHIFT                     (7U)
/*! WKEN
 *  0b0..Disable the WAKE interrupt
 *  0b1..Enable the WAKE interrupt
 */
#define UART_UCR4_WKEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_WKEN_SHIFT)) & UART_UCR4_WKEN_MASK)

#define UART_UCR4_ENIRI_MASK                     (0x100U)
#define UART_UCR4_ENIRI_SHIFT                    (8U)
/*! ENIRI
 *  0b0..Serial infrared Interrupt disabled
 *  0b1..Serial infrared Interrupt enabled
 */
#define UART_UCR4_ENIRI(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_ENIRI_SHIFT)) & UART_UCR4_ENIRI_MASK)

#define UART_UCR4_INVR_MASK                      (0x200U)
#define UART_UCR4_INVR_SHIFT                     (9U)
/*! INVR
 *  0b0..RXD active low detection
 *  0b0..RXD input is not inverted
 *  0b1..RXD active high detection
 *  0b1..RXD input is inverted
 */
#define UART_UCR4_INVR(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_INVR_SHIFT)) & UART_UCR4_INVR_MASK)

#define UART_UCR4_CTSTL_MASK                     (0xFC00U)
#define UART_UCR4_CTSTL_SHIFT                    (10U)
/*! CTSTL
 *  0b000000..0 characters received
 *  0b000001..1 characters in the RxFIFO
 *  0b100000..32 characters in the RxFIFO (maximum)
 */
#define UART_UCR4_CTSTL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_CTSTL_SHIFT)) & UART_UCR4_CTSTL_MASK)
/*! @} */

/*! @name UFCR - UART FIFO Control Register */
/*! @{ */

#define UART_UFCR_RXTL_MASK                      (0x3FU)
#define UART_UFCR_RXTL_SHIFT                     (0U)
/*! RXTL
 *  0b000000..0 characters received
 *  0b000001..RxFIFO has 1 character
 *  0b011111..RxFIFO has 31 characters
 *  0b100000..RxFIFO has 32 characters (maximum)
 */
#define UART_UFCR_RXTL(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UFCR_RXTL_SHIFT)) & UART_UFCR_RXTL_MASK)

#define UART_UFCR_DCEDTE_MASK                    (0x40U)
#define UART_UFCR_DCEDTE_SHIFT                   (6U)
/*! DCEDTE
 *  0b0..DCE mode selected
 *  0b1..DTE mode selected
 */
#define UART_UFCR_DCEDTE(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UFCR_DCEDTE_SHIFT)) & UART_UFCR_DCEDTE_MASK)

#define UART_UFCR_RFDIV_MASK                     (0x380U)
#define UART_UFCR_RFDIV_SHIFT                    (7U)
/*! RFDIV
 *  0b000..Divide input clock by 6
 *  0b001..Divide input clock by 5
 *  0b010..Divide input clock by 4
 *  0b011..Divide input clock by 3
 *  0b100..Divide input clock by 2
 *  0b101..Divide input clock by 1
 *  0b110..Divide input clock by 7
 *  0b111..Reserved
 */
#define UART_UFCR_RFDIV(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UFCR_RFDIV_SHIFT)) & UART_UFCR_RFDIV_MASK)

#define UART_UFCR_TXTL_MASK                      (0xFC00U)
#define UART_UFCR_TXTL_SHIFT                     (10U)
/*! TXTL
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..TxFIFO has 2 or fewer characters
 *  0b011111..TxFIFO has 31 or fewer characters
 *  0b100000..TxFIFO has 32 characters (maximum)
 */
#define UART_UFCR_TXTL(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UFCR_TXTL_SHIFT)) & UART_UFCR_TXTL_MASK)
/*! @} */

/*! @name USR1 - UART Status Register 1 */
/*! @{ */

#define UART_USR1_SAD_MASK                       (0x8U)
#define UART_USR1_SAD_SHIFT                      (3U)
/*! SAD
 *  0b0..No slave address detected
 *  0b1..Slave address detected
 */
#define UART_USR1_SAD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR1_SAD_SHIFT)) & UART_USR1_SAD_MASK)

#define UART_USR1_AWAKE_MASK                     (0x10U)
#define UART_USR1_AWAKE_SHIFT                    (4U)
/*! AWAKE
 *  0b0..No falling edge was detected on the RXD Serial pin
 *  0b1..A falling edge was detected on the RXD Serial pin
 */
#define UART_USR1_AWAKE(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR1_AWAKE_SHIFT)) & UART_USR1_AWAKE_MASK)

#define UART_USR1_AIRINT_MASK                    (0x20U)
#define UART_USR1_AIRINT_SHIFT                   (5U)
/*! AIRINT
 *  0b0..No pulse was detected on the RXD IrDA pin
 *  0b1..A pulse was detected on the RXD IrDA pin
 */
#define UART_USR1_AIRINT(x)                      (((uint32_t)(((uint32_t)(x)) << UART_USR1_AIRINT_SHIFT)) & UART_USR1_AIRINT_MASK)

#define UART_USR1_RXDS_MASK                      (0x40U)
#define UART_USR1_RXDS_SHIFT                     (6U)
/*! RXDS
 *  0b0..Receive in progress
 *  0b1..Receiver is IDLE
 */
#define UART_USR1_RXDS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RXDS_SHIFT)) & UART_USR1_RXDS_MASK)

#define UART_USR1_DTRD_MASK                      (0x80U)
#define UART_USR1_DTRD_SHIFT                     (7U)
#define UART_USR1_DTRD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_DTRD_SHIFT)) & UART_USR1_DTRD_MASK)

#define UART_USR1_AGTIM_MASK                     (0x100U)
#define UART_USR1_AGTIM_SHIFT                    (8U)
/*! AGTIM
 *  0b0..AGTIM is not active
 *  0b1..AGTIM is active (write 1 to clear)
 */
#define UART_USR1_AGTIM(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR1_AGTIM_SHIFT)) & UART_USR1_AGTIM_MASK)

#define UART_USR1_RRDY_MASK                      (0x200U)
#define UART_USR1_RRDY_SHIFT                     (9U)
/*! RRDY
 *  0b0..No character ready
 *  0b1..Character(s) ready (interrupt posted)
 */
#define UART_USR1_RRDY(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RRDY_SHIFT)) & UART_USR1_RRDY_MASK)

#define UART_USR1_FRAMERR_MASK                   (0x400U)
#define UART_USR1_FRAMERR_SHIFT                  (10U)
/*! FRAMERR
 *  0b0..No frame error detected
 *  0b1..Frame error detected (write 1 to clear)
 */
#define UART_USR1_FRAMERR(x)                     (((uint32_t)(((uint32_t)(x)) << UART_USR1_FRAMERR_SHIFT)) & UART_USR1_FRAMERR_MASK)

#define UART_USR1_ESCF_MASK                      (0x800U)
#define UART_USR1_ESCF_SHIFT                     (11U)
/*! ESCF
 *  0b0..No escape sequence detected
 *  0b1..Escape sequence detected (write 1 to clear).
 */
#define UART_USR1_ESCF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_ESCF_SHIFT)) & UART_USR1_ESCF_MASK)

#define UART_USR1_RTSD_MASK                      (0x1000U)
#define UART_USR1_RTSD_SHIFT                     (12U)
/*! RTSD
 *  0b0..RTS_B pin did not change state since last cleared
 *  0b1..RTS_B pin changed state (write 1 to clear)
 */
#define UART_USR1_RTSD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RTSD_SHIFT)) & UART_USR1_RTSD_MASK)

#define UART_USR1_TRDY_MASK                      (0x2000U)
#define UART_USR1_TRDY_SHIFT                     (13U)
/*! TRDY
 *  0b0..The transmitter does not require data
 *  0b1..The transmitter requires data (interrupt posted)
 */
#define UART_USR1_TRDY(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_TRDY_SHIFT)) & UART_USR1_TRDY_MASK)

#define UART_USR1_RTSS_MASK                      (0x4000U)
#define UART_USR1_RTSS_SHIFT                     (14U)
/*! RTSS
 *  0b0..The RTS_B module input is high (inactive)
 *  0b1..The RTS_B module input is low (active)
 */
#define UART_USR1_RTSS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RTSS_SHIFT)) & UART_USR1_RTSS_MASK)

#define UART_USR1_PARITYERR_MASK                 (0x8000U)
#define UART_USR1_PARITYERR_SHIFT                (15U)
/*! PARITYERR
 *  0b0..No parity error detected
 *  0b1..Parity error detected (write 1 to clear)
 */
#define UART_USR1_PARITYERR(x)                   (((uint32_t)(((uint32_t)(x)) << UART_USR1_PARITYERR_SHIFT)) & UART_USR1_PARITYERR_MASK)
/*! @} */

/*! @name USR2 - UART Status Register 2 */
/*! @{ */

#define UART_USR2_RDR_MASK                       (0x1U)
#define UART_USR2_RDR_SHIFT                      (0U)
/*! RDR
 *  0b0..No receive data ready
 *  0b1..Receive data ready
 */
#define UART_USR2_RDR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR2_RDR_SHIFT)) & UART_USR2_RDR_MASK)

#define UART_USR2_ORE_MASK                       (0x2U)
#define UART_USR2_ORE_SHIFT                      (1U)
/*! ORE
 *  0b0..No overrun error
 *  0b1..Overrun error (write 1 to clear)
 */
#define UART_USR2_ORE(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR2_ORE_SHIFT)) & UART_USR2_ORE_MASK)

#define UART_USR2_BRCD_MASK                      (0x4U)
#define UART_USR2_BRCD_SHIFT                     (2U)
/*! BRCD
 *  0b0..No BREAK condition was detected
 *  0b1..A BREAK condition was detected (write 1 to clear)
 */
#define UART_USR2_BRCD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_BRCD_SHIFT)) & UART_USR2_BRCD_MASK)

#define UART_USR2_TXDC_MASK                      (0x8U)
#define UART_USR2_TXDC_SHIFT                     (3U)
/*! TXDC
 *  0b0..Transmit is incomplete
 *  0b1..Transmit is complete
 */
#define UART_USR2_TXDC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_TXDC_SHIFT)) & UART_USR2_TXDC_MASK)

#define UART_USR2_RTSF_MASK                      (0x10U)
#define UART_USR2_RTSF_SHIFT                     (4U)
/*! RTSF
 *  0b0..Programmed edge not detected on RTS_B
 *  0b1..Programmed edge detected on RTS_B (write 1 to clear)
 */
#define UART_USR2_RTSF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_RTSF_SHIFT)) & UART_USR2_RTSF_MASK)

#define UART_USR2_DCDIN_MASK                     (0x20U)
#define UART_USR2_DCDIN_SHIFT                    (5U)
#define UART_USR2_DCDIN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR2_DCDIN_SHIFT)) & UART_USR2_DCDIN_MASK)

#define UART_USR2_DCDDELT_MASK                   (0x40U)
#define UART_USR2_DCDDELT_SHIFT                  (6U)
#define UART_USR2_DCDDELT(x)                     (((uint32_t)(((uint32_t)(x)) << UART_USR2_DCDDELT_SHIFT)) & UART_USR2_DCDDELT_MASK)

#define UART_USR2_WAKE_MASK                      (0x80U)
#define UART_USR2_WAKE_SHIFT                     (7U)
/*! WAKE
 *  0b0..start bit not detected
 *  0b1..start bit detected (write 1 to clear)
 */
#define UART_USR2_WAKE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_WAKE_SHIFT)) & UART_USR2_WAKE_MASK)

#define UART_USR2_IRINT_MASK                     (0x100U)
#define UART_USR2_IRINT_SHIFT                    (8U)
/*! IRINT
 *  0b0..no edge detected
 *  0b1..valid edge detected (write 1 to clear)
 */
#define UART_USR2_IRINT(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR2_IRINT_SHIFT)) & UART_USR2_IRINT_MASK)

#define UART_USR2_RIIN_MASK                      (0x200U)
#define UART_USR2_RIIN_SHIFT                     (9U)
#define UART_USR2_RIIN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_RIIN_SHIFT)) & UART_USR2_RIIN_MASK)

#define UART_USR2_RIDELT_MASK                    (0x400U)
#define UART_USR2_RIDELT_SHIFT                   (10U)
#define UART_USR2_RIDELT(x)                      (((uint32_t)(((uint32_t)(x)) << UART_USR2_RIDELT_SHIFT)) & UART_USR2_RIDELT_MASK)

#define UART_USR2_ACST_MASK                      (0x800U)
#define UART_USR2_ACST_SHIFT                     (11U)
/*! ACST
 *  0b0..Measurement of bit length not finished (in autobaud)
 *  0b1..Measurement of bit length finished (in autobaud). (write 1 to clear)
 */
#define UART_USR2_ACST(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_ACST_SHIFT)) & UART_USR2_ACST_MASK)

#define UART_USR2_IDLE_MASK                      (0x1000U)
#define UART_USR2_IDLE_SHIFT                     (12U)
/*! IDLE
 *  0b0..No idle condition detected
 *  0b1..Idle condition detected (write 1 to clear)
 */
#define UART_USR2_IDLE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_IDLE_SHIFT)) & UART_USR2_IDLE_MASK)

#define UART_USR2_DTRF_MASK                      (0x2000U)
#define UART_USR2_DTRF_SHIFT                     (13U)
#define UART_USR2_DTRF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_DTRF_SHIFT)) & UART_USR2_DTRF_MASK)

#define UART_USR2_TXFE_MASK                      (0x4000U)
#define UART_USR2_TXFE_SHIFT                     (14U)
/*! TXFE
 *  0b0..The transmit buffer (TxFIFO) is not empty
 *  0b1..The transmit buffer (TxFIFO) is empty
 */
#define UART_USR2_TXFE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_TXFE_SHIFT)) & UART_USR2_TXFE_MASK)

#define UART_USR2_ADET_MASK                      (0x8000U)
#define UART_USR2_ADET_SHIFT                     (15U)
/*! ADET
 *  0b0..ASCII "A" or "a" was not received
 *  0b1..ASCII "A" or "a" was received (write 1 to clear)
 */
#define UART_USR2_ADET(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_ADET_SHIFT)) & UART_USR2_ADET_MASK)
/*! @} */

/*! @name UESC - UART Escape Character Register */
/*! @{ */

#define UART_UESC_ESC_CHAR_MASK                  (0xFFU)
#define UART_UESC_ESC_CHAR_SHIFT                 (0U)
#define UART_UESC_ESC_CHAR(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UESC_ESC_CHAR_SHIFT)) & UART_UESC_ESC_CHAR_MASK)
/*! @} */

/*! @name UTIM - UART Escape Timer Register */
/*! @{ */

#define UART_UTIM_TIM_MASK                       (0xFFFU)
#define UART_UTIM_TIM_SHIFT                      (0U)
#define UART_UTIM_TIM(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UTIM_TIM_SHIFT)) & UART_UTIM_TIM_MASK)
/*! @} */

/*! @name UBIR - UART BRM Incremental Register */
/*! @{ */

#define UART_UBIR_INC_MASK                       (0xFFFFU)
#define UART_UBIR_INC_SHIFT                      (0U)
#define UART_UBIR_INC(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UBIR_INC_SHIFT)) & UART_UBIR_INC_MASK)
/*! @} */

/*! @name UBMR - UART BRM Modulator Register */
/*! @{ */

#define UART_UBMR_MOD_MASK                       (0xFFFFU)
#define UART_UBMR_MOD_SHIFT                      (0U)
#define UART_UBMR_MOD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UBMR_MOD_SHIFT)) & UART_UBMR_MOD_MASK)
/*! @} */

/*! @name UBRC - UART Baud Rate Count Register */
/*! @{ */

#define UART_UBRC_BCNT_MASK                      (0xFFFFU)
#define UART_UBRC_BCNT_SHIFT                     (0U)
#define UART_UBRC_BCNT(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UBRC_BCNT_SHIFT)) & UART_UBRC_BCNT_MASK)
/*! @} */

/*! @name ONEMS - UART One Millisecond Register */
/*! @{ */

#define UART_ONEMS_ONEMS_MASK                    (0xFFFFFFU)
#define UART_ONEMS_ONEMS_SHIFT                   (0U)
#define UART_ONEMS_ONEMS(x)                      (((uint32_t)(((uint32_t)(x)) << UART_ONEMS_ONEMS_SHIFT)) & UART_ONEMS_ONEMS_MASK)
/*! @} */

/*! @name UTS - UART Test Register */
/*! @{ */

#define UART_UTS_SOFTRST_MASK                    (0x1U)
#define UART_UTS_SOFTRST_SHIFT                   (0U)
/*! SOFTRST
 *  0b0..Software reset inactive
 *  0b1..Software reset active
 */
#define UART_UTS_SOFTRST(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_SOFTRST_SHIFT)) & UART_UTS_SOFTRST_MASK)

#define UART_UTS_RXFULL_MASK                     (0x8U)
#define UART_UTS_RXFULL_SHIFT                    (3U)
/*! RXFULL
 *  0b0..The RxFIFO is not full
 *  0b1..The RxFIFO is full
 */
#define UART_UTS_RXFULL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXFULL_SHIFT)) & UART_UTS_RXFULL_MASK)

#define UART_UTS_TXFULL_MASK                     (0x10U)
#define UART_UTS_TXFULL_SHIFT                    (4U)
/*! TXFULL
 *  0b0..The TxFIFO is not full
 *  0b1..The TxFIFO is full
 */
#define UART_UTS_TXFULL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_TXFULL_SHIFT)) & UART_UTS_TXFULL_MASK)

#define UART_UTS_RXEMPTY_MASK                    (0x20U)
#define UART_UTS_RXEMPTY_SHIFT                   (5U)
/*! RXEMPTY
 *  0b0..The RxFIFO is not empty
 *  0b1..The RxFIFO is empty
 */
#define UART_UTS_RXEMPTY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXEMPTY_SHIFT)) & UART_UTS_RXEMPTY_MASK)

#define UART_UTS_TXEMPTY_MASK                    (0x40U)
#define UART_UTS_TXEMPTY_SHIFT                   (6U)
/*! TXEMPTY
 *  0b0..The TxFIFO is not empty
 *  0b1..The TxFIFO is empty
 */
#define UART_UTS_TXEMPTY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_TXEMPTY_SHIFT)) & UART_UTS_TXEMPTY_MASK)

#define UART_UTS_RXDBG_MASK                      (0x200U)
#define UART_UTS_RXDBG_SHIFT                     (9U)
/*! RXDBG
 *  0b0..rx fifo read pointer does not increment
 *  0b1..rx_fifo read pointer increments as normal
 */
#define UART_UTS_RXDBG(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXDBG_SHIFT)) & UART_UTS_RXDBG_MASK)

#define UART_UTS_LOOPIR_MASK                     (0x400U)
#define UART_UTS_LOOPIR_SHIFT                    (10U)
/*! LOOPIR
 *  0b0..No IR loop
 *  0b1..Connect IR transmitter to IR receiver
 */
#define UART_UTS_LOOPIR(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_LOOPIR_SHIFT)) & UART_UTS_LOOPIR_MASK)

#define UART_UTS_DBGEN_MASK                      (0x800U)
#define UART_UTS_DBGEN_SHIFT                     (11U)
/*! DBGEN
 *  0b0..UART will go into debug mode when debug_req is HIGH
 *  0b1..UART will not go into debug mode even if debug_req is HIGH
 */
#define UART_UTS_DBGEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UTS_DBGEN_SHIFT)) & UART_UTS_DBGEN_MASK)

#define UART_UTS_LOOP_MASK                       (0x1000U)
#define UART_UTS_LOOP_SHIFT                      (12U)
/*! LOOP
 *  0b0..Normal receiver operation
 *  0b1..Internally connect the transmitter output to the receiver input
 */
#define UART_UTS_LOOP(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UTS_LOOP_SHIFT)) & UART_UTS_LOOP_MASK)

#define UART_UTS_FRCPERR_MASK                    (0x2000U)
#define UART_UTS_FRCPERR_SHIFT                   (13U)
/*! FRCPERR
 *  0b0..Generate normal parity
 *  0b1..Generate inverted parity (error)
 */
#define UART_UTS_FRCPERR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_FRCPERR_SHIFT)) & UART_UTS_FRCPERR_MASK)
/*! @} */

/*! @name UMCR - UART RS-485 Mode Control Register */
/*! @{ */

#define UART_UMCR_MDEN_MASK                      (0x1U)
#define UART_UMCR_MDEN_SHIFT                     (0U)
/*! MDEN
 *  0b0..Normal RS-232 or IrDA mode, see for detail.
 *  0b1..Enable RS-485 mode, see for detail
 */
#define UART_UMCR_MDEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_MDEN_SHIFT)) & UART_UMCR_MDEN_MASK)

#define UART_UMCR_SLAM_MASK                      (0x2U)
#define UART_UMCR_SLAM_SHIFT                     (1U)
/*! SLAM
 *  0b0..Select Normal Address Detect mode
 *  0b1..Select Automatic Address Detect mode
 */
#define UART_UMCR_SLAM(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SLAM_SHIFT)) & UART_UMCR_SLAM_MASK)

#define UART_UMCR_TXB8_MASK                      (0x4U)
#define UART_UMCR_TXB8_SHIFT                     (2U)
/*! TXB8
 *  0b0..0 will be transmitted as the RS485 9th data bit
 *  0b1..1 will be transmitted as the RS485 9th data bit
 */
#define UART_UMCR_TXB8(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_TXB8_SHIFT)) & UART_UMCR_TXB8_MASK)

#define UART_UMCR_SADEN_MASK                     (0x8U)
#define UART_UMCR_SADEN_SHIFT                    (3U)
/*! SADEN
 *  0b0..Disable RS-485 Slave Address Detected Interrupt
 *  0b1..Enable RS-485 Slave Address Detected Interrupt
 */
#define UART_UMCR_SADEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SADEN_SHIFT)) & UART_UMCR_SADEN_MASK)

#define UART_UMCR_SLADDR_MASK                    (0xFF00U)
#define UART_UMCR_SLADDR_SHIFT                   (8U)
#define UART_UMCR_SLADDR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SLADDR_SHIFT)) & UART_UMCR_SLADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UART_Register_Masks */


/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */


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


#endif  /* PERI_UART_H_ */

