/*
** ###################################################################
**     Processors:          MC56F83663VLH
**                          MC56F83683VLH
**                          MC56F83686VLK
**                          MC56F83689VLL
**                          MC56F83763AVLH
**                          MC56F83763VLH
**                          MC56F83766VLK
**                          MC56F83769AVLL
**                          MC56F83769VLL
**                          MC56F83783AVLH
**                          MC56F83783VLH
**                          MC56F83786VLK
**                          MC56F83789AVLL
**                          MC56F83789VLL
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for QSCI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-09-23)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_QSCI.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for QSCI
 *
 * CMSIS Peripheral Access Layer for QSCI
 */

#if !defined(PERI_QSCI_H_)
#define PERI_QSCI_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F83663VLH))
#include "MC56F83663_COMMON.h"
#elif (defined(CPU_MC56F83683VLH))
#include "MC56F83683_COMMON.h"
#elif (defined(CPU_MC56F83686VLK))
#include "MC56F83686_COMMON.h"
#elif (defined(CPU_MC56F83689VLL))
#include "MC56F83689_COMMON.h"
#elif (defined(CPU_MC56F83763AVLH) || defined(CPU_MC56F83763VLH))
#include "MC56F83763_COMMON.h"
#elif (defined(CPU_MC56F83766VLK))
#include "MC56F83766_COMMON.h"
#elif (defined(CPU_MC56F83769AVLL) || defined(CPU_MC56F83769VLL))
#include "MC56F83769_COMMON.h"
#elif (defined(CPU_MC56F83783AVLH) || defined(CPU_MC56F83783VLH))
#include "MC56F83783_COMMON.h"
#elif (defined(CPU_MC56F83786VLK))
#include "MC56F83786_COMMON.h"
#elif (defined(CPU_MC56F83789AVLL) || defined(CPU_MC56F83789VLL))
#include "MC56F83789_COMMON.h"
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
   -- QSCI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QSCI_Peripheral_Access_Layer QSCI Peripheral Access Layer
 * @{
 */

/** QSCI - Register Layout Typedef */
typedef struct {
  __IO uint16_t RATE;                              /**< QSCI Baud Rate Register, offset: 0x0 */
  __IO uint16_t CTRL1;                             /**< QSCI Control Register 1, offset: 0x1 */
  __IO uint16_t CTRL2;                             /**< QSCI Control Register 2, offset: 0x2 */
  __IO uint16_t STAT;                              /**< QSCI Status Register, offset: 0x3 */
  __IO uint16_t DATA;                              /**< QSCI Data Register, offset: 0x4 */
  __IO uint16_t CTRL3;                             /**< QSCI Control Register 3, offset: 0x5 */
} QSCI_Type;

/* ----------------------------------------------------------------------------
   -- QSCI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QSCI_Register_Masks QSCI Register Masks
 * @{
 */

/*! @name RATE - QSCI Baud Rate Register */
/*! @{ */

#define QSCI_RATE_FRAC_SBR_MASK                  (0x7U)
#define QSCI_RATE_FRAC_SBR_SHIFT                 (0U)
/*! FRAC_SBR - Fractional SCI Baud Rate divider, a value from 0 to 7 that is divided by 8 */
#define QSCI_RATE_FRAC_SBR(x)                    (((uint16_t)(((uint16_t)(x)) << QSCI_RATE_FRAC_SBR_SHIFT)) & QSCI_RATE_FRAC_SBR_MASK)

#define QSCI_RATE_SBRL_MASK                      (0xFFF8U)
#define QSCI_RATE_SBRL_SHIFT                     (3U)
/*! SBRL - Low order bits of SCI Baud Rate divider, which combine with the CTRL3[SBRH] field to form a value from 1 to 65535 */
#define QSCI_RATE_SBRL(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_RATE_SBRL_SHIFT)) & QSCI_RATE_SBRL_MASK)
/*! @} */

/*! @name CTRL1 - QSCI Control Register 1 */
/*! @{ */

#define QSCI_CTRL1_SBK_MASK                      (0x1U)
#define QSCI_CTRL1_SBK_SHIFT                     (0U)
/*! SBK - Send Break
 *  0b0..No break characters
 *  0b1..Transmit break characters
 */
#define QSCI_CTRL1_SBK(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_SBK_SHIFT)) & QSCI_CTRL1_SBK_MASK)

#define QSCI_CTRL1_RWU_MASK                      (0x2U)
#define QSCI_CTRL1_RWU_SHIFT                     (1U)
/*! RWU - Receiver Wake-up
 *  0b0..Normal operation
 *  0b1..Standby state
 */
#define QSCI_CTRL1_RWU(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_RWU_SHIFT)) & QSCI_CTRL1_RWU_MASK)

#define QSCI_CTRL1_RE_MASK                       (0x4U)
#define QSCI_CTRL1_RE_SHIFT                      (2U)
/*! RE - Receiver Enable
 *  0b0..Receiver disabled
 *  0b1..Receiver enabled
 */
#define QSCI_CTRL1_RE(x)                         (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_RE_SHIFT)) & QSCI_CTRL1_RE_MASK)

#define QSCI_CTRL1_TE_MASK                       (0x8U)
#define QSCI_CTRL1_TE_SHIFT                      (3U)
/*! TE - Transmitter Enable
 *  0b0..Transmitter disabled
 *  0b1..Transmitter enabled
 */
#define QSCI_CTRL1_TE(x)                         (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_TE_SHIFT)) & QSCI_CTRL1_TE_MASK)

#define QSCI_CTRL1_REIE_MASK                     (0x10U)
#define QSCI_CTRL1_REIE_SHIFT                    (4U)
/*! REIE - Receive Error Interrupt Enable
 *  0b0..Error interrupt requests disabled
 *  0b1..Error interrupt requests enabled
 */
#define QSCI_CTRL1_REIE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_REIE_SHIFT)) & QSCI_CTRL1_REIE_MASK)

#define QSCI_CTRL1_RFIE_MASK                     (0x20U)
#define QSCI_CTRL1_RFIE_SHIFT                    (5U)
/*! RFIE - Receiver Full Interrupt Enable
 *  0b0..STAT[RDRF] and STAT[OR] interrupt requests disabled
 *  0b1..STAT[RDRF] and STAT[OR] interrupt requests enabled
 */
#define QSCI_CTRL1_RFIE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_RFIE_SHIFT)) & QSCI_CTRL1_RFIE_MASK)

#define QSCI_CTRL1_TIIE_MASK                     (0x40U)
#define QSCI_CTRL1_TIIE_SHIFT                    (6U)
/*! TIIE - Transmitter Idle Interrupt Enable
 *  0b0..STAT[TIDLE] interrupt requests disabled
 *  0b1..STAT[TIDLE] interrupt requests enabled
 */
#define QSCI_CTRL1_TIIE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_TIIE_SHIFT)) & QSCI_CTRL1_TIIE_MASK)

#define QSCI_CTRL1_TEIE_MASK                     (0x80U)
#define QSCI_CTRL1_TEIE_SHIFT                    (7U)
/*! TEIE - Transmitter Empty Interrupt Enable
 *  0b0..STAT[TDRE] interrupt requests disabled
 *  0b1..STAT[TDRE] interrupt requests enabled
 */
#define QSCI_CTRL1_TEIE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_TEIE_SHIFT)) & QSCI_CTRL1_TEIE_MASK)

#define QSCI_CTRL1_PT_MASK                       (0x100U)
#define QSCI_CTRL1_PT_SHIFT                      (8U)
/*! PT - Parity Type
 *  0b0..Even parity
 *  0b1..Odd parity
 */
#define QSCI_CTRL1_PT(x)                         (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_PT_SHIFT)) & QSCI_CTRL1_PT_MASK)

#define QSCI_CTRL1_PE_MASK                       (0x200U)
#define QSCI_CTRL1_PE_SHIFT                      (9U)
/*! PE - Parity Enable
 *  0b0..Parity function disabled
 *  0b1..Parity function enabled
 */
#define QSCI_CTRL1_PE(x)                         (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_PE_SHIFT)) & QSCI_CTRL1_PE_MASK)

#define QSCI_CTRL1_POL_MASK                      (0x400U)
#define QSCI_CTRL1_POL_SHIFT                     (10U)
/*! POL - Polarity
 *  0b0..Don't invert transmit and receive data bits (normal mode)
 *  0b1..Invert transmit and receive data bits (inverted mode)
 */
#define QSCI_CTRL1_POL(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_POL_SHIFT)) & QSCI_CTRL1_POL_MASK)

#define QSCI_CTRL1_WAKE_MASK                     (0x800U)
#define QSCI_CTRL1_WAKE_SHIFT                    (11U)
/*! WAKE - Wake-up Condition
 *  0b0..Idle line wake-up
 *  0b1..Address mark wake-up
 */
#define QSCI_CTRL1_WAKE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_WAKE_SHIFT)) & QSCI_CTRL1_WAKE_MASK)

#define QSCI_CTRL1_M_MASK                        (0x1000U)
#define QSCI_CTRL1_M_SHIFT                       (12U)
/*! M - Data Format Mode
 *  0b0..One start bit, eight data bits, one stop bit
 *  0b1..One start bit, nine data bits, one stop bit
 */
#define QSCI_CTRL1_M(x)                          (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_M_SHIFT)) & QSCI_CTRL1_M_MASK)

#define QSCI_CTRL1_RSRC_MASK                     (0x2000U)
#define QSCI_CTRL1_RSRC_SHIFT                    (13U)
/*! RSRC - Receiver Source
 *  0b0..Receiver input internally connected to transmitter output
 *  0b1..Receiver input connected to TXD pin
 */
#define QSCI_CTRL1_RSRC(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_RSRC_SHIFT)) & QSCI_CTRL1_RSRC_MASK)

#define QSCI_CTRL1_SWAI_MASK                     (0x4000U)
#define QSCI_CTRL1_SWAI_SHIFT                    (14U)
/*! SWAI - Stop in Wait Mode
 *  0b0..SCI enabled in wait mode
 *  0b1..SCI disabled in wait mode
 */
#define QSCI_CTRL1_SWAI(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_SWAI_SHIFT)) & QSCI_CTRL1_SWAI_MASK)

#define QSCI_CTRL1_LOOP_MASK                     (0x8000U)
#define QSCI_CTRL1_LOOP_SHIFT                    (15U)
/*! LOOP - Loop Select
 *  0b0..Normal operation, regardless of the value of RSRC
 *  0b1..When RSRC = 0: Loop mode with internal TXD fed back to RXD
 *  0b1..When RSRC = 1: Single-wire mode with TXD output fed back to RXD
 */
#define QSCI_CTRL1_LOOP(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL1_LOOP_SHIFT)) & QSCI_CTRL1_LOOP_MASK)
/*! @} */

/*! @name CTRL2 - QSCI Control Register 2 */
/*! @{ */

#define QSCI_CTRL2_RDE_MASK                      (0x1U)
#define QSCI_CTRL2_RDE_SHIFT                     (0U)
/*! RDE - Receiver DMA Enable
 *  0b0..Receive DMA disabled
 *  0b1..Receive DMA enabled
 */
#define QSCI_CTRL2_RDE(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_RDE_SHIFT)) & QSCI_CTRL2_RDE_MASK)

#define QSCI_CTRL2_TDE_MASK                      (0x2U)
#define QSCI_CTRL2_TDE_SHIFT                     (1U)
/*! TDE - Transmitter DMA Enable
 *  0b0..Transmit DMA disabled
 *  0b1..Transmit DMA enabled
 */
#define QSCI_CTRL2_TDE(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_TDE_SHIFT)) & QSCI_CTRL2_TDE_MASK)

#define QSCI_CTRL2_RIIE_MASK                     (0x4U)
#define QSCI_CTRL2_RIIE_SHIFT                    (2U)
/*! RIIE - Receiver Idle Interrupt Enable */
#define QSCI_CTRL2_RIIE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_RIIE_SHIFT)) & QSCI_CTRL2_RIIE_MASK)

#define QSCI_CTRL2_LINMODE_MASK                  (0x8U)
#define QSCI_CTRL2_LINMODE_SHIFT                 (3U)
/*! LINMODE - Enable LIN Slave Mode
 *  0b0..The LIN auto baud feature is disabled and the RATE register maintains whatever value the processor writes to it.
 *  0b1..Enable LIN slave functionality. This includes a search for the break character followed by a sync
 *       character (0x55) from the master LIN device. When the break is detected (11 consecutive samples of zero), the
 *       subsequent sync character is used to measure the baud rate of the transmitting master, and the RATE register
 *       is automatically reloaded with the value needed to "match" that baud rate.
 */
#define QSCI_CTRL2_LINMODE(x)                    (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_LINMODE_SHIFT)) & QSCI_CTRL2_LINMODE_MASK)

#define QSCI_CTRL2_RIEIE_MASK                    (0x10U)
#define QSCI_CTRL2_RIEIE_SHIFT                   (4U)
/*! RIEIE - Receiver Input Edge Interrupt Enable
 *  0b0..Receiver input edge interrupt request disabled.
 *  0b1..Receiver input edge interrupt request enabled.
 */
#define QSCI_CTRL2_RIEIE(x)                      (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_RIEIE_SHIFT)) & QSCI_CTRL2_RIEIE_MASK)

#define QSCI_CTRL2_FIFO_EN_MASK                  (0x20U)
#define QSCI_CTRL2_FIFO_EN_SHIFT                 (5U)
/*! FIFO_EN - FIFO Enable
 *  0b0..FIFOs are disabled.
 *  0b1..FIFOs are enabled.
 */
#define QSCI_CTRL2_FIFO_EN(x)                    (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_FIFO_EN_SHIFT)) & QSCI_CTRL2_FIFO_EN_MASK)

#define QSCI_CTRL2_RFWM_MASK                     (0xC0U)
#define QSCI_CTRL2_RFWM_SHIFT                    (6U)
/*! RFWM - Receive FIFO Full Water Mark
 *  0b00..RDRF is set when at least 1 word is in the FIFO
 *  0b01..RDRF is set when at least 2 words are in the FIFO
 *  0b10..RDRF is set when at least 3 words are in the FIFO
 *  0b11..RDRF is set when at least 4 words are in the FIFO
 */
#define QSCI_CTRL2_RFWM(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_RFWM_SHIFT)) & QSCI_CTRL2_RFWM_MASK)

#define QSCI_CTRL2_RFCNT_MASK                    (0x700U)
#define QSCI_CTRL2_RFCNT_SHIFT                   (8U)
/*! RFCNT - Receive FIFO Count
 *  0b000..0 words in RX FIFO
 *  0b001..1 word in RX FIFO
 *  0b010..2 words in RX FIFO
 *  0b011..3 words in RX FIFO
 *  0b100..4 words in RX FIFO
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define QSCI_CTRL2_RFCNT(x)                      (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_RFCNT_SHIFT)) & QSCI_CTRL2_RFCNT_MASK)

#define QSCI_CTRL2_TFWM_MASK                     (0x1800U)
#define QSCI_CTRL2_TFWM_SHIFT                    (11U)
/*! TFWM - Transmit FIFO Empty Water Mark
 *  0b00..TDRE is set when 0 words are in the FIFO
 *  0b01..TDRE is set when 1 or fewer words are in the FIFO
 *  0b10..TDRE is set when 2 or fewer words are in the FIFO
 *  0b11..TDRE is set when 3 or fewer words are in the FIFO
 */
#define QSCI_CTRL2_TFWM(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_TFWM_SHIFT)) & QSCI_CTRL2_TFWM_MASK)

#define QSCI_CTRL2_TFCNT_MASK                    (0xE000U)
#define QSCI_CTRL2_TFCNT_SHIFT                   (13U)
/*! TFCNT - Transmit FIFO Count
 *  0b000..0 words in Tx FIFO
 *  0b001..1 word in Tx FIFO
 *  0b010..2 words in Tx FIFO
 *  0b011..3 words in Tx FIFO
 *  0b100..4 words in Tx FIFO
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define QSCI_CTRL2_TFCNT(x)                      (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL2_TFCNT_SHIFT)) & QSCI_CTRL2_TFCNT_MASK)
/*! @} */

/*! @name STAT - QSCI Status Register */
/*! @{ */

#define QSCI_STAT_RAF_MASK                       (0x1U)
#define QSCI_STAT_RAF_SHIFT                      (0U)
/*! RAF - Receiver Active Flag
 *  0b0..No reception in progress
 *  0b1..Reception in progress
 */
#define QSCI_STAT_RAF(x)                         (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_RAF_SHIFT)) & QSCI_STAT_RAF_MASK)

#define QSCI_STAT_RDMA_MASK                      (0x2U)
#define QSCI_STAT_RDMA_SHIFT                     (1U)
/*! RDMA - Receive DMA Request
 *  0b0..Either CTRL2[RDE] is cleared or CTRL2[RDE] is set and CTRL2[RFCNT] is 0.
 *  0b1..CTRL2[RDE] is set and CTRL2[RFCNT] is currently above 0.
 */
#define QSCI_STAT_RDMA(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_RDMA_SHIFT)) & QSCI_STAT_RDMA_MASK)

#define QSCI_STAT_TDMA_MASK                      (0x4U)
#define QSCI_STAT_TDMA_SHIFT                     (2U)
/*! TDMA - Transmit DMA Request
 *  0b0..Either CTRL2[TDE] is cleared or CTRL2[TDE] is set and CTRL2[TFCNT] is at its maximum value.
 *  0b1..CTRL2[TDE] is set and CTRL2[TFCNT] is currently below its maximum value.
 */
#define QSCI_STAT_TDMA(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_TDMA_SHIFT)) & QSCI_STAT_TDMA_MASK)

#define QSCI_STAT_LSE_MASK                       (0x8U)
#define QSCI_STAT_LSE_SHIFT                      (3U)
/*! LSE - LIN Sync Error
 *  0b0..No error occurred since CTRL2[LINMODE] was enabled or the bit was last cleared
 *  0b1..A sync error prevented loading of the RATE register with a revised value after the break was detected.
 */
#define QSCI_STAT_LSE(x)                         (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_LSE_SHIFT)) & QSCI_STAT_LSE_MASK)

#define QSCI_STAT_RIEF_MASK                      (0x10U)
#define QSCI_STAT_RIEF_SHIFT                     (4U)
/*! RIEF - Receiver Input Edge Flag
 *  0b0..No active edge on the receive pin has occured.
 *  0b1..An active edge on the receive pin has occured.
 */
#define QSCI_STAT_RIEF(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_RIEF_SHIFT)) & QSCI_STAT_RIEF_MASK)

#define QSCI_STAT_PF_MASK                        (0x100U)
#define QSCI_STAT_PF_SHIFT                       (8U)
/*! PF - Parity Error Flag
 *  0b0..No parity error
 *  0b1..Parity error
 */
#define QSCI_STAT_PF(x)                          (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_PF_SHIFT)) & QSCI_STAT_PF_MASK)

#define QSCI_STAT_FE_MASK                        (0x200U)
#define QSCI_STAT_FE_SHIFT                       (9U)
/*! FE - Framing Error Flag
 *  0b0..No framing error
 *  0b1..Framing error
 */
#define QSCI_STAT_FE(x)                          (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_FE_SHIFT)) & QSCI_STAT_FE_MASK)

#define QSCI_STAT_NF_MASK                        (0x400U)
#define QSCI_STAT_NF_SHIFT                       (10U)
/*! NF - Noise Flag
 *  0b0..No noise
 *  0b1..Noise
 */
#define QSCI_STAT_NF(x)                          (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_NF_SHIFT)) & QSCI_STAT_NF_MASK)

#define QSCI_STAT_OR_MASK                        (0x800U)
#define QSCI_STAT_OR_SHIFT                       (11U)
/*! OR - Overrun Flag
 *  0b0..No overrun
 *  0b1..Overrun
 */
#define QSCI_STAT_OR(x)                          (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_OR_SHIFT)) & QSCI_STAT_OR_MASK)

#define QSCI_STAT_RIDLE_MASK                     (0x1000U)
#define QSCI_STAT_RIDLE_SHIFT                    (12U)
/*! RIDLE - Receiver Idle Line Flag
 *  0b0..Receiver input is either active now or has never become active since RIDLE was last cleared
 *  0b1..Receiver input has become idle (after receiving a valid frame)
 */
#define QSCI_STAT_RIDLE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_RIDLE_SHIFT)) & QSCI_STAT_RIDLE_MASK)

#define QSCI_STAT_RDRF_MASK                      (0x2000U)
#define QSCI_STAT_RDRF_SHIFT                     (13U)
/*! RDRF - Receive Data Register Full Flag
 *  0b0..RX FIFO word count is at or below watermark
 *  0b1..RX FIFO word count is above watermark
 */
#define QSCI_STAT_RDRF(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_RDRF_SHIFT)) & QSCI_STAT_RDRF_MASK)

#define QSCI_STAT_TIDLE_MASK                     (0x4000U)
#define QSCI_STAT_TIDLE_SHIFT                    (14U)
/*! TIDLE - Transmitter Idle Flag
 *  0b0..Transmission in progress
 *  0b1..No transmission in progress
 */
#define QSCI_STAT_TIDLE(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_TIDLE_SHIFT)) & QSCI_STAT_TIDLE_MASK)

#define QSCI_STAT_TDRE_MASK                      (0x8000U)
#define QSCI_STAT_TDRE_SHIFT                     (15U)
/*! TDRE - Transmit Data Register Empty Flag
 *  0b0..TX FIFO word count is above watermark
 *  0b1..TX FIFO word count is at or below watermark
 */
#define QSCI_STAT_TDRE(x)                        (((uint16_t)(((uint16_t)(x)) << QSCI_STAT_TDRE_SHIFT)) & QSCI_STAT_TDRE_MASK)
/*! @} */

/*! @name DATA - QSCI Data Register */
/*! @{ */

#define QSCI_DATA_RECEIVE_TRANSMIT_DATA_MASK     (0x1FFU)
#define QSCI_DATA_RECEIVE_TRANSMIT_DATA_SHIFT    (0U)
#define QSCI_DATA_RECEIVE_TRANSMIT_DATA(x)       (((uint16_t)(((uint16_t)(x)) << QSCI_DATA_RECEIVE_TRANSMIT_DATA_SHIFT)) & QSCI_DATA_RECEIVE_TRANSMIT_DATA_MASK)
/*! @} */

/*! @name CTRL3 - QSCI Control Register 3 */
/*! @{ */

#define QSCI_CTRL3_SHEN_MASK                     (0x1U)
#define QSCI_CTRL3_SHEN_SHIFT                    (0U)
/*! SHEN - Stop mode entry hold off
 *  0b0..Stop mode hold off is disabled.
 *  0b1..Stop mode holdoff is enabled.
 */
#define QSCI_CTRL3_SHEN(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL3_SHEN_SHIFT)) & QSCI_CTRL3_SHEN_MASK)

#define QSCI_CTRL3_SBRH_MASK                     (0xE000U)
#define QSCI_CTRL3_SBRH_SHIFT                    (13U)
/*! SBRH - High order bits of SCI Baud Rate divider, which combine with the RATE[SBRL] field to form a value from 1 to 65535 */
#define QSCI_CTRL3_SBRH(x)                       (((uint16_t)(((uint16_t)(x)) << QSCI_CTRL3_SBRH_SHIFT)) & QSCI_CTRL3_SBRH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group QSCI_Register_Masks */


/*!
 * @}
 */ /* end of group QSCI_Peripheral_Access_Layer */


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


#endif  /* PERI_QSCI_H_ */

