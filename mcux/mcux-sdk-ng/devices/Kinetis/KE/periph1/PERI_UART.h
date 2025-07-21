/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_UART.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for UART
 *
 * CMSIS Peripheral Access Layer for UART
 */

#if !defined(PERI_UART_H_)
#define PERI_UART_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Register: High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Register: Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __I  uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/*! @name BDH - UART Baud Rate Register: High */
/*! @{ */

#define UART_BDH_SBR_MASK                        (0x1FU)
#define UART_BDH_SBR_SHIFT                       (0U)
/*! SBR - Baud Rate Modulo Divisor. */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBR_SHIFT)) & UART_BDH_SBR_MASK)

#define UART_BDH_SBNS_MASK                       (0x20U)
#define UART_BDH_SBNS_SHIFT                      (5U)
/*! SBNS - Stop Bit Number Select
 *  0b0..One stop bit.
 *  0b1..Two stop bit.
 */
#define UART_BDH_SBNS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBNS_SHIFT)) & UART_BDH_SBNS_MASK)

#define UART_BDH_RXEDGIE_MASK                    (0x40U)
#define UART_BDH_RXEDGIE_SHIFT                   (6U)
/*! RXEDGIE - RxD Input Active Edge Interrupt Enable (for RXEDGIF)
 *  0b0..Hardware interrupts from UART_S2[RXEDGIF] disabled (use polling).
 *  0b1..Hardware interrupt requested when UART_S2[RXEDGIF] flag is 1.
 */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_BDH_RXEDGIE_SHIFT)) & UART_BDH_RXEDGIE_MASK)

#define UART_BDH_LBKDIE_MASK                     (0x80U)
#define UART_BDH_LBKDIE_SHIFT                    (7U)
/*! LBKDIE - LIN Break Detect Interrupt Enable (for LBKDIF)
 *  0b0..Hardware interrupts from UART_S2[LBKDIF] disabled (use polling).
 *  0b1..Hardware interrupt requested when UART_S2[LBKDIF] flag is 1.
 */
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x)) << UART_BDH_LBKDIE_SHIFT)) & UART_BDH_LBKDIE_MASK)
/*! @} */

/*! @name BDL - UART Baud Rate Register: Low */
/*! @{ */

#define UART_BDL_SBR_MASK                        (0xFFU)
#define UART_BDL_SBR_SHIFT                       (0U)
/*! SBR - Baud Rate Modulo Divisor */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x)) << UART_BDL_SBR_SHIFT)) & UART_BDL_SBR_MASK)
/*! @} */

/*! @name C1 - UART Control Register 1 */
/*! @{ */

#define UART_C1_PT_MASK                          (0x1U)
#define UART_C1_PT_SHIFT                         (0U)
/*! PT - Parity Type
 *  0b0..Even parity.
 *  0b1..Odd parity.
 */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C1_PT_SHIFT)) & UART_C1_PT_MASK)

#define UART_C1_PE_MASK                          (0x2U)
#define UART_C1_PE_SHIFT                         (1U)
/*! PE - Parity Enable
 *  0b0..No hardware parity generation or checking.
 *  0b1..Parity enabled.
 */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C1_PE_SHIFT)) & UART_C1_PE_MASK)

#define UART_C1_ILT_MASK                         (0x4U)
#define UART_C1_ILT_SHIFT                        (2U)
/*! ILT - Idle Line Type Select
 *  0b0..Idle character bit count starts after start bit.
 *  0b1..Idle character bit count starts after stop bit.
 */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C1_ILT_SHIFT)) & UART_C1_ILT_MASK)

#define UART_C1_WAKE_MASK                        (0x8U)
#define UART_C1_WAKE_SHIFT                       (3U)
/*! WAKE - Receiver Wakeup Method Select
 *  0b0..Idle-line wake-up.
 *  0b1..Address-mark wake-up.
 */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C1_WAKE_SHIFT)) & UART_C1_WAKE_MASK)

#define UART_C1_M_MASK                           (0x10U)
#define UART_C1_M_SHIFT                          (4U)
/*! M - 9-Bit or 8-Bit Mode Select
 *  0b0..Normal - start + 8 data bits (lsb first) + stop.
 *  0b1..Receiver and transmitter use 9-bit data characters start + 8 data bits (lsb first) + 9th data bit + stop.
 */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x)) << UART_C1_M_SHIFT)) & UART_C1_M_MASK)

#define UART_C1_RSRC_MASK                        (0x20U)
#define UART_C1_RSRC_SHIFT                       (5U)
/*! RSRC - Receiver Source Select
 *  0b0..Provided LOOPS is set, RSRC is cleared, selects internal loop back mode and the UART does not use the RxD pins.
 *  0b1..Single-wire UART mode where the TxD pin is connected to the transmitter output and receiver input.
 */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C1_RSRC_SHIFT)) & UART_C1_RSRC_MASK)

#define UART_C1_UARTSWAI_MASK                    (0x40U)
#define UART_C1_UARTSWAI_SHIFT                   (6U)
/*! UARTSWAI - UART Stops in Wait Mode
 *  0b0..UART clocks continue to run in Wait mode so the UART can be the source of an interrupt that wakes up the CPU.
 *  0b1..UART clocks freeze while CPU is in Wait mode.
 */
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x)) << UART_C1_UARTSWAI_SHIFT)) & UART_C1_UARTSWAI_MASK)

#define UART_C1_LOOPS_MASK                       (0x80U)
#define UART_C1_LOOPS_SHIFT                      (7U)
/*! LOOPS - Loop Mode Select
 *  0b0..Normal operation - RxD and TxD use separate pins.
 *  0b1..Loop mode or single-wire mode where transmitter outputs are internally connected to receiver input. (See
 *       RSRC bit.) RxD pin is not used by UART.
 */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C1_LOOPS_SHIFT)) & UART_C1_LOOPS_MASK)
/*! @} */

/*! @name C2 - UART Control Register 2 */
/*! @{ */

#define UART_C2_SBK_MASK                         (0x1U)
#define UART_C2_SBK_SHIFT                        (0U)
/*! SBK - Send Break
 *  0b0..Normal transmitter operation.
 *  0b1..Queue break character(s) to be sent.
 */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_SBK_SHIFT)) & UART_C2_SBK_MASK)

#define UART_C2_RWU_MASK                         (0x2U)
#define UART_C2_RWU_SHIFT                        (1U)
/*! RWU - Receiver Wakeup Control
 *  0b0..Normal UART receiver operation.
 *  0b1..UART receiver in standby waiting for wake-up condition.
 */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_RWU_SHIFT)) & UART_C2_RWU_MASK)

#define UART_C2_RE_MASK                          (0x4U)
#define UART_C2_RE_SHIFT                         (2U)
/*! RE - Receiver Enable
 *  0b0..Receiver off.
 *  0b1..Receiver on.
 */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C2_RE_SHIFT)) & UART_C2_RE_MASK)

#define UART_C2_TE_MASK                          (0x8U)
#define UART_C2_TE_SHIFT                         (3U)
/*! TE - Transmitter Enable
 *  0b0..Transmitter off.
 *  0b1..Transmitter on.
 */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C2_TE_SHIFT)) & UART_C2_TE_MASK)

#define UART_C2_ILIE_MASK                        (0x10U)
#define UART_C2_ILIE_SHIFT                       (4U)
/*! ILIE - Idle Line Interrupt Enable for IDLE
 *  0b0..Hardware interrupts from S1[IDLE] disabled; use polling.
 *  0b1..Hardware interrupt requested when S1[IDLE] flag is 1.
 */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C2_ILIE_SHIFT)) & UART_C2_ILIE_MASK)

#define UART_C2_RIE_MASK                         (0x20U)
#define UART_C2_RIE_SHIFT                        (5U)
/*! RIE - Receiver Interrupt Enable for RDRF
 *  0b0..Hardware interrupts from S1[RDRF] disabled; use polling.
 *  0b1..Hardware interrupt requested when S1[RDRF] flag is 1.
 */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_RIE_SHIFT)) & UART_C2_RIE_MASK)

#define UART_C2_TCIE_MASK                        (0x40U)
#define UART_C2_TCIE_SHIFT                       (6U)
/*! TCIE - Transmission Complete Interrupt Enable for TC
 *  0b0..Hardware interrupts from TC disabled; use polling.
 *  0b1..Hardware interrupt requested when TC flag is 1.
 */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C2_TCIE_SHIFT)) & UART_C2_TCIE_MASK)

#define UART_C2_TIE_MASK                         (0x80U)
#define UART_C2_TIE_SHIFT                        (7U)
/*! TIE - Transmit Interrupt Enable for TDRE
 *  0b0..Hardware interrupts from TDRE disabled; use polling.
 *  0b1..Hardware interrupt requested when TDRE flag is 1.
 */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_TIE_SHIFT)) & UART_C2_TIE_MASK)
/*! @} */

/*! @name S1 - UART Status Register 1 */
/*! @{ */

#define UART_S1_PF_MASK                          (0x1U)
#define UART_S1_PF_SHIFT                         (0U)
/*! PF - Parity Error Flag
 *  0b0..No parity error.
 *  0b1..Parity error.
 */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_PF_SHIFT)) & UART_S1_PF_MASK)

#define UART_S1_FE_MASK                          (0x2U)
#define UART_S1_FE_SHIFT                         (1U)
/*! FE - Framing Error Flag
 *  0b0..No framing error detected. This does not guarantee the framing is correct.
 *  0b1..Framing error.
 */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_FE_SHIFT)) & UART_S1_FE_MASK)

#define UART_S1_NF_MASK                          (0x4U)
#define UART_S1_NF_SHIFT                         (2U)
/*! NF - Noise Flag
 *  0b0..No noise detected.
 *  0b1..Noise detected in the received character in UART_D.
 */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_NF_SHIFT)) & UART_S1_NF_MASK)

#define UART_S1_OR_MASK                          (0x8U)
#define UART_S1_OR_SHIFT                         (3U)
/*! OR - Receiver Overrun Flag
 *  0b0..No overrun.
 *  0b1..Receive overrun (new UART data lost).
 */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_OR_SHIFT)) & UART_S1_OR_MASK)

#define UART_S1_IDLE_MASK                        (0x10U)
#define UART_S1_IDLE_SHIFT                       (4U)
/*! IDLE - Idle Line Flag
 *  0b0..No idle line detected.
 *  0b1..Idle line was detected.
 */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_IDLE_SHIFT)) & UART_S1_IDLE_MASK)

#define UART_S1_RDRF_MASK                        (0x20U)
#define UART_S1_RDRF_SHIFT                       (5U)
/*! RDRF - Receive Data Register Full Flag
 *  0b0..Receive data register empty.
 *  0b1..Receive data register full.
 */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_RDRF_SHIFT)) & UART_S1_RDRF_MASK)

#define UART_S1_TC_MASK                          (0x40U)
#define UART_S1_TC_SHIFT                         (6U)
/*! TC - Transmission Complete Flag
 *  0b0..Transmitter active (sending data, a preamble, or a break).
 *  0b1..Transmitter idle (transmission activity complete).
 */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_TC_SHIFT)) & UART_S1_TC_MASK)

#define UART_S1_TDRE_MASK                        (0x80U)
#define UART_S1_TDRE_SHIFT                       (7U)
/*! TDRE - Transmit Data Register Empty Flag
 *  0b0..Transmit data register (buffer) full.
 *  0b1..Transmit data register (buffer) empty.
 */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_TDRE_SHIFT)) & UART_S1_TDRE_MASK)
/*! @} */

/*! @name S2 - UART Status Register 2 */
/*! @{ */

#define UART_S2_RAF_MASK                         (0x1U)
#define UART_S2_RAF_SHIFT                        (0U)
/*! RAF - Receiver Active Flag
 *  0b0..UART receiver idle waiting for a start bit.
 *  0b1..UART receiver active (RxD input not idle).
 */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x)) << UART_S2_RAF_SHIFT)) & UART_S2_RAF_MASK)

#define UART_S2_LBKDE_MASK                       (0x2U)
#define UART_S2_LBKDE_SHIFT                      (1U)
/*! LBKDE - LIN Break Detection Enable
 *  0b0..Break detection is disabled.
 *  0b1..Break detection is enabled (Break character is detected at length 11 bit times (if C1[M] = 0, BDH[SBNS] =
 *       0) or 12 (if C1[M] = 1, BDH[SBNS] = 0 or C1[M] = 0, BDH[SBNS] = 1) or 13 (if C1[M] = 1, BDH[SBNS] = 1)).
 */
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDE_SHIFT)) & UART_S2_LBKDE_MASK)

#define UART_S2_BRK13_MASK                       (0x4U)
#define UART_S2_BRK13_SHIFT                      (2U)
/*! BRK13 - Break Character Generation Length
 *  0b0..Break character is transmitted with length of 10 bit times (if M = 0, SBNS = 0) or 11 (if M = 1, SBNS = 0
 *       or M = 0, SBNS = 1) or 12 (if M = 1, SBNS = 1).
 *  0b1..Break character is transmitted with length of 13 bit times (if M = 0, SBNS = 0) or 14 (if M = 1, SBNS = 0
 *       or M = 0, SBNS = 1) or 15 (if M = 1, SBNS = 1).
 */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_BRK13_SHIFT)) & UART_S2_BRK13_MASK)

#define UART_S2_RWUID_MASK                       (0x8U)
#define UART_S2_RWUID_SHIFT                      (3U)
/*! RWUID - Receive Wake Up Idle Detect
 *  0b0..During receive standby state (RWU = 1), S1[IDLE] does not get set upon detection of an idle character.
 *  0b1..During receive standby state (RWU = 1), S1[IDLE] gets set upon detection of an idle character.
 */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_RWUID_SHIFT)) & UART_S2_RWUID_MASK)

#define UART_S2_RXINV_MASK                       (0x10U)
#define UART_S2_RXINV_SHIFT                      (4U)
/*! RXINV - Receive Data Inversion
 *  0b0..Receive data not inverted.
 *  0b1..Receive data inverted.
 */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_RXINV_SHIFT)) & UART_S2_RXINV_MASK)

#define UART_S2_RXEDGIF_MASK                     (0x40U)
#define UART_S2_RXEDGIF_SHIFT                    (6U)
/*! RXEDGIF - RxD Pin Active Edge Interrupt Flag
 *  0b0..No active edge on the receive pin has occurred.
 *  0b1..An active edge on the receive pin has occurred.
 */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x)) << UART_S2_RXEDGIF_SHIFT)) & UART_S2_RXEDGIF_MASK)

#define UART_S2_LBKDIF_MASK                      (0x80U)
#define UART_S2_LBKDIF_SHIFT                     (7U)
/*! LBKDIF - LIN Break Detect Interrupt Flag
 *  0b0..No LIN break character has been detected.
 *  0b1..LIN break character has been detected.
 */
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDIF_SHIFT)) & UART_S2_LBKDIF_MASK)
/*! @} */

/*! @name C3 - UART Control Register 3 */
/*! @{ */

#define UART_C3_PEIE_MASK                        (0x1U)
#define UART_C3_PEIE_SHIFT                       (0U)
/*! PEIE - Parity Error Interrupt Enable
 *  0b0..PF interrupts disabled; use polling).
 *  0b1..Hardware interrupt requested when PF is set.
 */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_PEIE_SHIFT)) & UART_C3_PEIE_MASK)

#define UART_C3_FEIE_MASK                        (0x2U)
#define UART_C3_FEIE_SHIFT                       (1U)
/*! FEIE - Framing Error Interrupt Enable
 *  0b0..FE interrupts disabled; use polling).
 *  0b1..Hardware interrupt requested when FE is set.
 */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_FEIE_SHIFT)) & UART_C3_FEIE_MASK)

#define UART_C3_NEIE_MASK                        (0x4U)
#define UART_C3_NEIE_SHIFT                       (2U)
/*! NEIE - Noise Error Interrupt Enable
 *  0b0..NF interrupts disabled; use polling).
 *  0b1..Hardware interrupt requested when NF is set.
 */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_NEIE_SHIFT)) & UART_C3_NEIE_MASK)

#define UART_C3_ORIE_MASK                        (0x8U)
#define UART_C3_ORIE_SHIFT                       (3U)
/*! ORIE - Overrun Interrupt Enable
 *  0b0..OR interrupts disabled; use polling.
 *  0b1..Hardware interrupt requested when OR is set.
 */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_ORIE_SHIFT)) & UART_C3_ORIE_MASK)

#define UART_C3_TXINV_MASK                       (0x10U)
#define UART_C3_TXINV_SHIFT                      (4U)
/*! TXINV - Transmit Data Inversion
 *  0b0..Transmit data not inverted.
 *  0b1..Transmit data inverted.
 */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C3_TXINV_SHIFT)) & UART_C3_TXINV_MASK)

#define UART_C3_TXDIR_MASK                       (0x20U)
#define UART_C3_TXDIR_SHIFT                      (5U)
/*! TXDIR - TxD Pin Direction in Single-Wire Mode
 *  0b0..TxD pin is an input in single-wire mode.
 *  0b1..TxD pin is an output in single-wire mode.
 */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C3_TXDIR_SHIFT)) & UART_C3_TXDIR_MASK)

#define UART_C3_T8_MASK                          (0x40U)
#define UART_C3_T8_SHIFT                         (6U)
/*! T8 - Ninth Data Bit for Transmitter */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C3_T8_SHIFT)) & UART_C3_T8_MASK)

#define UART_C3_R8_MASK                          (0x80U)
#define UART_C3_R8_SHIFT                         (7U)
/*! R8 - Ninth Data Bit for Receiver */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C3_R8_SHIFT)) & UART_C3_R8_MASK)
/*! @} */

/*! @name D - UART Data Register */
/*! @{ */

#define UART_D_R0T0_MASK                         (0x1U)
#define UART_D_R0T0_SHIFT                        (0U)
#define UART_D_R0T0(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R0T0_SHIFT)) & UART_D_R0T0_MASK)

#define UART_D_R1T1_MASK                         (0x2U)
#define UART_D_R1T1_SHIFT                        (1U)
#define UART_D_R1T1(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R1T1_SHIFT)) & UART_D_R1T1_MASK)

#define UART_D_R2T2_MASK                         (0x4U)
#define UART_D_R2T2_SHIFT                        (2U)
#define UART_D_R2T2(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R2T2_SHIFT)) & UART_D_R2T2_MASK)

#define UART_D_R3T3_MASK                         (0x8U)
#define UART_D_R3T3_SHIFT                        (3U)
#define UART_D_R3T3(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R3T3_SHIFT)) & UART_D_R3T3_MASK)

#define UART_D_R4T4_MASK                         (0x10U)
#define UART_D_R4T4_SHIFT                        (4U)
#define UART_D_R4T4(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R4T4_SHIFT)) & UART_D_R4T4_MASK)

#define UART_D_R5T5_MASK                         (0x20U)
#define UART_D_R5T5_SHIFT                        (5U)
#define UART_D_R5T5(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R5T5_SHIFT)) & UART_D_R5T5_MASK)

#define UART_D_R6T6_MASK                         (0x40U)
#define UART_D_R6T6_SHIFT                        (6U)
#define UART_D_R6T6(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R6T6_SHIFT)) & UART_D_R6T6_MASK)

#define UART_D_R7T7_MASK                         (0x80U)
#define UART_D_R7T7_SHIFT                        (7U)
#define UART_D_R7T7(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R7T7_SHIFT)) & UART_D_R7T7_MASK)
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


#endif  /* PERI_UART_H_ */

