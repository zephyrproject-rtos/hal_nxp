/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SPDIF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SPDIF.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPDIF
 *
 * CMSIS Peripheral Access Layer for SPDIF
 */

#if !defined(PERI_SPDIF_H_)
#define PERI_SPDIF_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SPDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPDIF_Peripheral_Access_Layer SPDIF Peripheral Access Layer
 * @{
 */

/** SPDIF - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCR;                               /**< SPDIF Configuration, offset: 0x0 */
  __IO uint32_t SRCD;                              /**< CD Text Control, offset: 0x4 */
  __IO uint32_t SRPC;                              /**< Phase Configuration, offset: 0x8 */
  __IO uint32_t SIE;                               /**< Interrupt Enable, offset: 0xC */
  __IO uint32_t SIS;                               /**< Interrupt Status, offset: 0x10 */
  __I  uint32_t SRL;                               /**< SPDIF Receive Left, offset: 0x14 */
  __I  uint32_t SRR;                               /**< SPDIF Receive Right, offset: 0x18 */
  __I  uint32_t SRCSH;                             /**< SPDIF Receive C-Channel High, offset: 0x1C */
  __I  uint32_t SRCSL;                             /**< SPDIF Receive C-Channel Low, offset: 0x20 */
  __I  uint32_t SRU;                               /**< U-Channel Receive, offset: 0x24 */
  __I  uint32_t SRQ;                               /**< Q-Channel Receive, offset: 0x28 */
  __O  uint32_t STL;                               /**< SPDIF Transmit Left, offset: 0x2C */
  __O  uint32_t STR;                               /**< SPDIF Transmit Right, offset: 0x30 */
  __IO uint32_t STCSCH;                            /**< SPDIF Transmit C-Channel Cons High, offset: 0x34 */
  __IO uint32_t STCSCL;                            /**< SPDIF Transmit C-Channel Cons Low, offset: 0x38 */
       uint8_t RESERVED_0[8];
  __I  uint32_t SRFM;                              /**< Frequency Measurement, offset: 0x44 */
       uint8_t RESERVED_1[8];
  __IO uint32_t STC;                               /**< SPDIF Transmit Clock, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __I  uint32_t SPDIFRXCCHANNEL_ADDR_31_0;         /**< SPDIF Receive C-Channel Bits 31-0, offset: 0x60 */
  __I  uint32_t SPDIFRXCCHANNEL_ADDR_63_32;        /**< SPDIF Receive C-Channel Bits 63-32, offset: 0x64 */
  __I  uint32_t SPDIFRXCCHANNEL_ADDR_95_64;        /**< SPDIF Receive C-Channel Bits 95-64, offset: 0x68 */
  __I  uint32_t SPDIFRXCCHANNEL_ADDR_127_96;       /**< SPDIF Receive C-Channel Bits 127-96, offset: 0x6C */
  __I  uint32_t SPDIFRXCCHANNEL_ADDR_159_128;      /**< SPDIF Receive C-Channel Bits 159-128, offset: 0x70 */
  __I  uint32_t SPDIFRXCCHANNEL_ADDR_191_160;      /**< SPDIF Receive C-Channel Bits 191-160, offset: 0x74 */
} SPDIF_Type;

/* ----------------------------------------------------------------------------
   -- SPDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPDIF_Register_Masks SPDIF Register Masks
 * @{
 */

/*! @name SCR - SPDIF Configuration */
/*! @{ */

#define SPDIF_SCR_USRC_SEL_MASK                  (0x3U)
#define SPDIF_SCR_USRC_SEL_SHIFT                 (0U)
/*! USrc_Sel - U-Channel Source Select
 *  0b00..No embedded U channel
 *  0b01..U-channel from SPDIF receive block (CD mode)
 *  0b10..Reserved
 *  0b11..U-channel from on chip transmitter
 */
#define SPDIF_SCR_USRC_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_USRC_SEL_SHIFT)) & SPDIF_SCR_USRC_SEL_MASK)

#define SPDIF_SCR_TXSEL_MASK                     (0x1CU)
#define SPDIF_SCR_TXSEL_SHIFT                    (2U)
/*! TxSel - Transmit Select
 *  0b000..Off and output 0
 *  0b001..Feed-through spdif_in1
 *  0b010..Feed-through spdif_in2
 *  0b011..Feed-through spdif_in3
 *  0b100..Feed-through spdif_in4
 *  0b101..Transmit Normal operation - From SPDIF Transmit Block
 *  0b110, 0b111..Reserved
 */
#define SPDIF_SCR_TXSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXSEL_SHIFT)) & SPDIF_SCR_TXSEL_MASK)

#define SPDIF_SCR_VALCTRL_MASK                   (0x20U)
#define SPDIF_SCR_VALCTRL_SHIFT                  (5U)
/*! ValCtrl - Validity Control
 *  0b0..Outgoing Validity always set
 *  0b1..Outgoing Validity always clear
 */
#define SPDIF_SCR_VALCTRL(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_VALCTRL_SHIFT)) & SPDIF_SCR_VALCTRL_MASK)

#define SPDIF_SCR_INPUTSRCSEL_MASK               (0xC0U)
#define SPDIF_SCR_INPUTSRCSEL_SHIFT              (6U)
/*! InputSrcSel - Input Source Select
 *  0b00..spdif_in1
 *  0b01..spdif_in2
 *  0b10..spdif_in3
 *  0b11..spdif_in4
 */
#define SPDIF_SCR_INPUTSRCSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_INPUTSRCSEL_SHIFT)) & SPDIF_SCR_INPUTSRCSEL_MASK)

#define SPDIF_SCR_DMA_TX_EN_MASK                 (0x100U)
#define SPDIF_SCR_DMA_TX_EN_SHIFT                (8U)
/*! DMA_TX_En - DMA Transmit Request Enable */
#define SPDIF_SCR_DMA_TX_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_DMA_TX_EN_SHIFT)) & SPDIF_SCR_DMA_TX_EN_MASK)

#define SPDIF_SCR_DMA_RX_EN_MASK                 (0x200U)
#define SPDIF_SCR_DMA_RX_EN_SHIFT                (9U)
/*! DMA_Rx_En - DMA Receive Request Enable */
#define SPDIF_SCR_DMA_RX_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_DMA_RX_EN_SHIFT)) & SPDIF_SCR_DMA_RX_EN_MASK)

#define SPDIF_SCR_TXFIFO_CTRL_MASK               (0xC00U)
#define SPDIF_SCR_TXFIFO_CTRL_SHIFT              (10U)
/*! TxFIFO_Ctrl - Transmit FIFO Control
 *  0b00..Send out digital zero on SPDIF transmitter
 *  0b01..Transmit Normal operation
 *  0b10..Reset to 1 sample remaining
 *  0b11..Reserved
 */
#define SPDIF_SCR_TXFIFO_CTRL(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXFIFO_CTRL_SHIFT)) & SPDIF_SCR_TXFIFO_CTRL_MASK)

#define SPDIF_SCR_SOFT_RESET_MASK                (0x1000U)
#define SPDIF_SCR_SOFT_RESET_SHIFT               (12U)
/*! soft_reset - Soft Reset */
#define SPDIF_SCR_SOFT_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_SOFT_RESET_SHIFT)) & SPDIF_SCR_SOFT_RESET_MASK)

#define SPDIF_SCR_LOW_POWER_MASK                 (0x2000U)
#define SPDIF_SCR_LOW_POWER_SHIFT                (13U)
/*! LOW_POWER - Low Power */
#define SPDIF_SCR_LOW_POWER(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_LOW_POWER_SHIFT)) & SPDIF_SCR_LOW_POWER_MASK)

#define SPDIF_SCR_RAW_CAPTURE_MODE_MASK          (0x4000U)
#define SPDIF_SCR_RAW_CAPTURE_MODE_SHIFT         (14U)
/*! RAW_CAPTURE_MODE - Raw Capture Mode
 *  0b0..SPDIF receiver will work in normal mode
 *  0b1..SPDIF receiver will work in raw capture mode
 */
#define SPDIF_SCR_RAW_CAPTURE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RAW_CAPTURE_MODE_SHIFT)) & SPDIF_SCR_RAW_CAPTURE_MODE_MASK)

#define SPDIF_SCR_TXFIFOEMPTY_SEL_MASK           (0x18000U)
#define SPDIF_SCR_TXFIFOEMPTY_SEL_SHIFT          (15U)
/*! TxFIFOEmpty_Sel - Transmit FIFO Empty Select
 *  0b00..Empty interrupt if 0 sample in transmitter left and right FIFOs
 *  0b01..Empty interrupt if at most 4 sample in transmitter left and right FIFOs
 *  0b10..Empty interrupt if at most 8 sample in transmitter left and right FIFOs
 *  0b11..Empty interrupt if at most 12 sample in transmitter left and right FIFOs
 */
#define SPDIF_SCR_TXFIFOEMPTY_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXFIFOEMPTY_SEL_SHIFT)) & SPDIF_SCR_TXFIFOEMPTY_SEL_MASK)

#define SPDIF_SCR_TXAUTOSYNC_MASK                (0x20000U)
#define SPDIF_SCR_TXAUTOSYNC_SHIFT               (17U)
/*! TxAutoSync - Transmit Auto-Sync
 *  0b0..Transmit FIFO auto-sync off
 *  0b1..Transmit FIFO auto-sync on
 */
#define SPDIF_SCR_TXAUTOSYNC(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXAUTOSYNC_SHIFT)) & SPDIF_SCR_TXAUTOSYNC_MASK)

#define SPDIF_SCR_RXAUTOSYNC_MASK                (0x40000U)
#define SPDIF_SCR_RXAUTOSYNC_SHIFT               (18U)
/*! RxAutoSync - Receive Auto-Sync
 *  0b0..Receive FIFO auto-sync off
 *  0b1..Receive FIFO auto-sync on
 */
#define SPDIF_SCR_RXAUTOSYNC(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXAUTOSYNC_SHIFT)) & SPDIF_SCR_RXAUTOSYNC_MASK)

#define SPDIF_SCR_RXFIFOFULL_SEL_MASK            (0x180000U)
#define SPDIF_SCR_RXFIFOFULL_SEL_SHIFT           (19U)
/*! RxFIFOFull_Sel - Receive FIFO Full Select
 *  0b00..Full interrupt if at least 1 sample in receiver left and right FIFOs
 *  0b01..Full interrupt if at least 4 sample in receiver left and right FIFOs
 *  0b10..Full interrupt if at least 8 sample in receiver left and right FIFOs
 *  0b11..Full interrupt if at least 16 sample in receiver left and right FIFO
 */
#define SPDIF_SCR_RXFIFOFULL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFOFULL_SEL_SHIFT)) & SPDIF_SCR_RXFIFOFULL_SEL_MASK)

#define SPDIF_SCR_RXFIFO_RST_MASK                (0x200000U)
#define SPDIF_SCR_RXFIFO_RST_SHIFT               (21U)
/*! RxFIFO_Rst - Receive FIFO Reset
 *  0b0..Normal operation
 *  0b1..Reset register to 1 sample remaining
 */
#define SPDIF_SCR_RXFIFO_RST(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFO_RST_SHIFT)) & SPDIF_SCR_RXFIFO_RST_MASK)

#define SPDIF_SCR_RXFIFO_OFF_ON_MASK             (0x400000U)
#define SPDIF_SCR_RXFIFO_OFF_ON_SHIFT            (22U)
/*! RxFIFO_Off_On - Receive FIFO Off/On
 *  0b0..SPDIF receiver FIFO is on
 *  0b1..SPDIF receiver FIFO is off. Does not accept data from interface
 */
#define SPDIF_SCR_RXFIFO_OFF_ON(x)               (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFO_OFF_ON_SHIFT)) & SPDIF_SCR_RXFIFO_OFF_ON_MASK)

#define SPDIF_SCR_RXFIFO_CTRL_MASK               (0x800000U)
#define SPDIF_SCR_RXFIFO_CTRL_SHIFT              (23U)
/*! RxFIFO_Ctrl - Receive FIFO Control
 *  0b0..Normal operation
 *  0b1..Always read zero from receiver data register
 */
#define SPDIF_SCR_RXFIFO_CTRL(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFO_CTRL_SHIFT)) & SPDIF_SCR_RXFIFO_CTRL_MASK)

#define SPDIF_SCR_RXCCHANNEL_192B_EN_MASK        (0x2000000U)
#define SPDIF_SCR_RXCCHANNEL_192B_EN_SHIFT       (25U)
/*! RXCChannel_192b_en - Receive C-Channel 192-bit Enable
 *  0b0..SPDIF receives only 48 bits of 192 C bits from input audio stream
 *  0b1..SPDIF receives 192 bits of C in audio stream
 */
#define SPDIF_SCR_RXCCHANNEL_192B_EN(x)          (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXCCHANNEL_192B_EN_SHIFT)) & SPDIF_SCR_RXCCHANNEL_192B_EN_MASK)
/*! @} */

/*! @name SRCD - CD Text Control */
/*! @{ */

#define SPDIF_SRCD_USYNCMODE_MASK                (0x2U)
#define SPDIF_SRCD_USYNCMODE_SHIFT               (1U)
/*! USyncMode - U-Sync Mode
 *  0b0..Non-CD data
 *  0b1..CD user-channel subcode
 */
#define SPDIF_SRCD_USYNCMODE(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCD_USYNCMODE_SHIFT)) & SPDIF_SRCD_USYNCMODE_MASK)
/*! @} */

/*! @name SRPC - Phase Configuration */
/*! @{ */

#define SPDIF_SRPC_GAINSEL_MASK                  (0x38U)
#define SPDIF_SRPC_GAINSEL_SHIFT                 (3U)
/*! GainSel - Gain Select
 *  0b000..24*(2**10)
 *  0b001..16*(2**10)
 *  0b010..12*(2**10)
 *  0b011..8*(2**10)
 *  0b100..6*(2**10)
 *  0b101..4*(2**10)
 *  0b110..3*(2**10)
 *  0b111..Reserved
 */
#define SPDIF_SRPC_GAINSEL(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_GAINSEL_SHIFT)) & SPDIF_SRPC_GAINSEL_MASK)

#define SPDIF_SRPC_LOCK_MASK                     (0x40U)
#define SPDIF_SRPC_LOCK_SHIFT                    (6U)
/*! LOCK - LOCK */
#define SPDIF_SRPC_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_LOCK_SHIFT)) & SPDIF_SRPC_LOCK_MASK)

#define SPDIF_SRPC_CLKSRC_SEL_MASK               (0x780U)
#define SPDIF_SRPC_CLKSRC_SEL_SHIFT              (7U)
/*! ClkSrc_Sel - Clock Source Select
 *  0b0000..If (DPLL Locked) SPDIF_RxClk else REF_CLK_32K (XTALOSC)
 *  0b0001..If (DPLL Locked) SPDIF_RxClk else tx_clk (SPDIF0_CLK_ROOT)
 *  0b0011..If (DPLL Locked) SPDIF_RxClk else extal_clk
 *  0b0101..REF_CLK_32K (XTALOSC)
 *  0b0110..tx_clk (SPDIF0_CLK_ROOT)
 *  0b1000..extal_clk
 */
#define SPDIF_SRPC_CLKSRC_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_CLKSRC_SEL_SHIFT)) & SPDIF_SRPC_CLKSRC_SEL_MASK)
/*! @} */

/*! @name SIE - Interrupt Enable */
/*! @{ */

#define SPDIF_SIE_RXFIFOFUL_MASK                 (0x1U)
#define SPDIF_SIE_RXFIFOFUL_SHIFT                (0U)
/*! RxFIFOFul - Receive FIFO Full */
#define SPDIF_SIE_RXFIFOFUL(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RXFIFOFUL_SHIFT)) & SPDIF_SIE_RXFIFOFUL_MASK)

#define SPDIF_SIE_TXEM_MASK                      (0x2U)
#define SPDIF_SIE_TXEM_SHIFT                     (1U)
/*! TxEm - Transmit Empty */
#define SPDIF_SIE_TXEM(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TXEM_SHIFT)) & SPDIF_SIE_TXEM_MASK)

#define SPDIF_SIE_LOCKLOSS_MASK                  (0x4U)
#define SPDIF_SIE_LOCKLOSS_SHIFT                 (2U)
/*! LockLoss - Lock Loss */
#define SPDIF_SIE_LOCKLOSS(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_LOCKLOSS_SHIFT)) & SPDIF_SIE_LOCKLOSS_MASK)

#define SPDIF_SIE_RXFIFORESYN_MASK               (0x8U)
#define SPDIF_SIE_RXFIFORESYN_SHIFT              (3U)
/*! RxFIFOResyn - Receive FIFO Resync */
#define SPDIF_SIE_RXFIFORESYN(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RXFIFORESYN_SHIFT)) & SPDIF_SIE_RXFIFORESYN_MASK)

#define SPDIF_SIE_RXFIFOUNOV_MASK                (0x10U)
#define SPDIF_SIE_RXFIFOUNOV_SHIFT               (4U)
/*! RxFIFOUnOv - Receive FIFO Underrun/Overrun */
#define SPDIF_SIE_RXFIFOUNOV(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RXFIFOUNOV_SHIFT)) & SPDIF_SIE_RXFIFOUNOV_MASK)

#define SPDIF_SIE_UQERR_MASK                     (0x20U)
#define SPDIF_SIE_UQERR_SHIFT                    (5U)
/*! UQErr - U/Q-Channel Framing Error */
#define SPDIF_SIE_UQERR(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_UQERR_SHIFT)) & SPDIF_SIE_UQERR_MASK)

#define SPDIF_SIE_UQSYNC_MASK                    (0x40U)
#define SPDIF_SIE_UQSYNC_SHIFT                   (6U)
/*! UQSync - U/Q-Channel Sync Found */
#define SPDIF_SIE_UQSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_UQSYNC_SHIFT)) & SPDIF_SIE_UQSYNC_MASK)

#define SPDIF_SIE_QRXOV_MASK                     (0x80U)
#define SPDIF_SIE_QRXOV_SHIFT                    (7U)
/*! QRxOv - Q-Channel Receive Register Overrun */
#define SPDIF_SIE_QRXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_QRXOV_SHIFT)) & SPDIF_SIE_QRXOV_MASK)

#define SPDIF_SIE_QRXFUL_MASK                    (0x100U)
#define SPDIF_SIE_QRXFUL_SHIFT                   (8U)
/*! QRxFul - Q-Channel Receive Register Full */
#define SPDIF_SIE_QRXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_QRXFUL_SHIFT)) & SPDIF_SIE_QRXFUL_MASK)

#define SPDIF_SIE_URXOV_MASK                     (0x200U)
#define SPDIF_SIE_URXOV_SHIFT                    (9U)
/*! URxOv - U-Channel Receive Register Overrun */
#define SPDIF_SIE_URXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_URXOV_SHIFT)) & SPDIF_SIE_URXOV_MASK)

#define SPDIF_SIE_URXFUL_MASK                    (0x400U)
#define SPDIF_SIE_URXFUL_SHIFT                   (10U)
/*! URxFul - U-Channel Receive Register Full */
#define SPDIF_SIE_URXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_URXFUL_SHIFT)) & SPDIF_SIE_URXFUL_MASK)

#define SPDIF_SIE_BITERR_MASK                    (0x4000U)
#define SPDIF_SIE_BITERR_SHIFT                   (14U)
/*! BitErr - Bit Error */
#define SPDIF_SIE_BITERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_BITERR_SHIFT)) & SPDIF_SIE_BITERR_MASK)

#define SPDIF_SIE_SYMERR_MASK                    (0x8000U)
#define SPDIF_SIE_SYMERR_SHIFT                   (15U)
/*! SymErr - Symbol Error */
#define SPDIF_SIE_SYMERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_SYMERR_SHIFT)) & SPDIF_SIE_SYMERR_MASK)

#define SPDIF_SIE_VALNOGOOD_MASK                 (0x10000U)
#define SPDIF_SIE_VALNOGOOD_SHIFT                (16U)
/*! ValNoGood - Validity Flag No Good */
#define SPDIF_SIE_VALNOGOOD(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_VALNOGOOD_SHIFT)) & SPDIF_SIE_VALNOGOOD_MASK)

#define SPDIF_SIE_CNEW_MASK                      (0x20000U)
#define SPDIF_SIE_CNEW_SHIFT                     (17U)
/*! CNew - C New */
#define SPDIF_SIE_CNEW(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_CNEW_SHIFT)) & SPDIF_SIE_CNEW_MASK)

#define SPDIF_SIE_TXRESYN_MASK                   (0x40000U)
#define SPDIF_SIE_TXRESYN_SHIFT                  (18U)
/*! TxResyn - Transmit FIFO Resync */
#define SPDIF_SIE_TXRESYN(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TXRESYN_SHIFT)) & SPDIF_SIE_TXRESYN_MASK)

#define SPDIF_SIE_TXUNOV_MASK                    (0x80000U)
#define SPDIF_SIE_TXUNOV_SHIFT                   (19U)
/*! TxUnOv - Transmit FIFO Underrun/Overrun */
#define SPDIF_SIE_TXUNOV(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TXUNOV_SHIFT)) & SPDIF_SIE_TXUNOV_MASK)

#define SPDIF_SIE_LOCK_MASK                      (0x100000U)
#define SPDIF_SIE_LOCK_SHIFT                     (20U)
/*! Lock - Lock */
#define SPDIF_SIE_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_LOCK_SHIFT)) & SPDIF_SIE_LOCK_MASK)
/*! @} */

/*! @name SIS - Interrupt Status */
/*! @{ */

#define SPDIF_SIS_RXFIFOFUL_MASK                 (0x1U)
#define SPDIF_SIS_RXFIFOFUL_SHIFT                (0U)
/*! RxFIFOFul - Receive FIFO Full */
#define SPDIF_SIS_RXFIFOFUL(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RXFIFOFUL_SHIFT)) & SPDIF_SIS_RXFIFOFUL_MASK)

#define SPDIF_SIS_TXEM_MASK                      (0x2U)
#define SPDIF_SIS_TXEM_SHIFT                     (1U)
/*! TxEm - Transmit FIFO Empty */
#define SPDIF_SIS_TXEM(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TXEM_SHIFT)) & SPDIF_SIS_TXEM_MASK)

#define SPDIF_SIS_LOCKLOSS_MASK                  (0x4U)
#define SPDIF_SIS_LOCKLOSS_SHIFT                 (2U)
/*! LockLoss - Lock Loss */
#define SPDIF_SIS_LOCKLOSS(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_LOCKLOSS_SHIFT)) & SPDIF_SIS_LOCKLOSS_MASK)

#define SPDIF_SIS_RXFIFORESYN_MASK               (0x8U)
#define SPDIF_SIS_RXFIFORESYN_SHIFT              (3U)
/*! RxFIFOResyn - Receive FIFO Resync */
#define SPDIF_SIS_RXFIFORESYN(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RXFIFORESYN_SHIFT)) & SPDIF_SIS_RXFIFORESYN_MASK)

#define SPDIF_SIS_RXFIFOUNOV_MASK                (0x10U)
#define SPDIF_SIS_RXFIFOUNOV_SHIFT               (4U)
/*! RxFIFOUnOv - Receive FIFO Underrun/Overrun */
#define SPDIF_SIS_RXFIFOUNOV(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RXFIFOUNOV_SHIFT)) & SPDIF_SIS_RXFIFOUNOV_MASK)

#define SPDIF_SIS_UQERR_MASK                     (0x20U)
#define SPDIF_SIS_UQERR_SHIFT                    (5U)
/*! UQErr - U/Q-Channel Framing Error */
#define SPDIF_SIS_UQERR(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_UQERR_SHIFT)) & SPDIF_SIS_UQERR_MASK)

#define SPDIF_SIS_UQSYNC_MASK                    (0x40U)
#define SPDIF_SIS_UQSYNC_SHIFT                   (6U)
/*! UQSync - U/Q-Channel Sync Found */
#define SPDIF_SIS_UQSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_UQSYNC_SHIFT)) & SPDIF_SIS_UQSYNC_MASK)

#define SPDIF_SIS_QRXOV_MASK                     (0x80U)
#define SPDIF_SIS_QRXOV_SHIFT                    (7U)
/*! QRxOv - Q-Channel Receive Register Overrun */
#define SPDIF_SIS_QRXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_QRXOV_SHIFT)) & SPDIF_SIS_QRXOV_MASK)

#define SPDIF_SIS_QRXFUL_MASK                    (0x100U)
#define SPDIF_SIS_QRXFUL_SHIFT                   (8U)
/*! QRxFul - Q-Channel Receive Register Full */
#define SPDIF_SIS_QRXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_QRXFUL_SHIFT)) & SPDIF_SIS_QRXFUL_MASK)

#define SPDIF_SIS_URXOV_MASK                     (0x200U)
#define SPDIF_SIS_URXOV_SHIFT                    (9U)
/*! URxOv - U-Channel Receive Register Overrun */
#define SPDIF_SIS_URXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_URXOV_SHIFT)) & SPDIF_SIS_URXOV_MASK)

#define SPDIF_SIS_URXFUL_MASK                    (0x400U)
#define SPDIF_SIS_URXFUL_SHIFT                   (10U)
/*! URxFul - U-Channel Receive Register Full */
#define SPDIF_SIS_URXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_URXFUL_SHIFT)) & SPDIF_SIS_URXFUL_MASK)

#define SPDIF_SIS_BITERR_MASK                    (0x4000U)
#define SPDIF_SIS_BITERR_SHIFT                   (14U)
/*! BitErr - Bit Error */
#define SPDIF_SIS_BITERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_BITERR_SHIFT)) & SPDIF_SIS_BITERR_MASK)

#define SPDIF_SIS_SYMERR_MASK                    (0x8000U)
#define SPDIF_SIS_SYMERR_SHIFT                   (15U)
/*! SymErr - Symbol Error */
#define SPDIF_SIS_SYMERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_SYMERR_SHIFT)) & SPDIF_SIS_SYMERR_MASK)

#define SPDIF_SIS_VALNOGOOD_MASK                 (0x10000U)
#define SPDIF_SIS_VALNOGOOD_SHIFT                (16U)
/*! ValNoGood - Validity Flag No Good */
#define SPDIF_SIS_VALNOGOOD(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_VALNOGOOD_SHIFT)) & SPDIF_SIS_VALNOGOOD_MASK)

#define SPDIF_SIS_CNEW_MASK                      (0x20000U)
#define SPDIF_SIS_CNEW_SHIFT                     (17U)
/*! CNew - C New */
#define SPDIF_SIS_CNEW(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_CNEW_SHIFT)) & SPDIF_SIS_CNEW_MASK)

#define SPDIF_SIS_TXRESYN_MASK                   (0x40000U)
#define SPDIF_SIS_TXRESYN_SHIFT                  (18U)
/*! TxResyn - Transmit FIFO Resync */
#define SPDIF_SIS_TXRESYN(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TXRESYN_SHIFT)) & SPDIF_SIS_TXRESYN_MASK)

#define SPDIF_SIS_TXUNOV_MASK                    (0x80000U)
#define SPDIF_SIS_TXUNOV_SHIFT                   (19U)
/*! TxUnOv - Transmit FIFO Underrun/Overrun */
#define SPDIF_SIS_TXUNOV(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TXUNOV_SHIFT)) & SPDIF_SIS_TXUNOV_MASK)

#define SPDIF_SIS_LOCK_MASK                      (0x100000U)
#define SPDIF_SIS_LOCK_SHIFT                     (20U)
/*! Lock - Lock */
#define SPDIF_SIS_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_LOCK_SHIFT)) & SPDIF_SIS_LOCK_MASK)
/*! @} */

/*! @name SRL - SPDIF Receive Left */
/*! @{ */

#define SPDIF_SRL_RXDATALEFT_MASK                (0xFFFFFFU)
#define SPDIF_SRL_RXDATALEFT_SHIFT               (0U)
/*! RxDataLeft - Receive Data Left */
#define SPDIF_SRL_RXDATALEFT(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRL_RXDATALEFT_SHIFT)) & SPDIF_SRL_RXDATALEFT_MASK)
/*! @} */

/*! @name SRR - SPDIF Receive Right */
/*! @{ */

#define SPDIF_SRR_RXDATARIGHT_MASK               (0xFFFFFFU)
#define SPDIF_SRR_RXDATARIGHT_SHIFT              (0U)
/*! RxDataRight - Receive Data Right */
#define SPDIF_SRR_RXDATARIGHT(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SRR_RXDATARIGHT_SHIFT)) & SPDIF_SRR_RXDATARIGHT_MASK)
/*! @} */

/*! @name SRCSH - SPDIF Receive C-Channel High */
/*! @{ */

#define SPDIF_SRCSH_RXCCHANNEL_H_MASK            (0xFFFFFFU)
#define SPDIF_SRCSH_RXCCHANNEL_H_SHIFT           (0U)
/*! RxCChannel_h - Receive C-Channel High */
#define SPDIF_SRCSH_RXCCHANNEL_H(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCSH_RXCCHANNEL_H_SHIFT)) & SPDIF_SRCSH_RXCCHANNEL_H_MASK)
/*! @} */

/*! @name SRCSL - SPDIF Receive C-Channel Low */
/*! @{ */

#define SPDIF_SRCSL_RXCCHANNEL_L_MASK            (0xFFFFFFU)
#define SPDIF_SRCSL_RXCCHANNEL_L_SHIFT           (0U)
/*! RxCChannel_l - Receive C-Channel Low */
#define SPDIF_SRCSL_RXCCHANNEL_L(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCSL_RXCCHANNEL_L_SHIFT)) & SPDIF_SRCSL_RXCCHANNEL_L_MASK)
/*! @} */

/*! @name SRU - U-Channel Receive */
/*! @{ */

#define SPDIF_SRU_RXUCHANNEL_MASK                (0xFFFFFFU)
#define SPDIF_SRU_RXUCHANNEL_SHIFT               (0U)
/*! RxUChannel - Receive U Channel */
#define SPDIF_SRU_RXUCHANNEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRU_RXUCHANNEL_SHIFT)) & SPDIF_SRU_RXUCHANNEL_MASK)
/*! @} */

/*! @name SRQ - Q-Channel Receive */
/*! @{ */

#define SPDIF_SRQ_RXQCHANNEL_MASK                (0xFFFFFFU)
#define SPDIF_SRQ_RXQCHANNEL_SHIFT               (0U)
/*! RxQChannel - Receive Q Channel */
#define SPDIF_SRQ_RXQCHANNEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRQ_RXQCHANNEL_SHIFT)) & SPDIF_SRQ_RXQCHANNEL_MASK)
/*! @} */

/*! @name STL - SPDIF Transmit Left */
/*! @{ */

#define SPDIF_STL_TXDATALEFT_MASK                (0xFFFFFFU)
#define SPDIF_STL_TXDATALEFT_SHIFT               (0U)
/*! TxDataLeft - Transmit Data Left */
#define SPDIF_STL_TXDATALEFT(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_STL_TXDATALEFT_SHIFT)) & SPDIF_STL_TXDATALEFT_MASK)
/*! @} */

/*! @name STR - SPDIF Transmit Right */
/*! @{ */

#define SPDIF_STR_TXDATARIGHT_MASK               (0xFFFFFFU)
#define SPDIF_STR_TXDATARIGHT_SHIFT              (0U)
/*! TxDataRight - Transmit Data Right */
#define SPDIF_STR_TXDATARIGHT(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_STR_TXDATARIGHT_SHIFT)) & SPDIF_STR_TXDATARIGHT_MASK)
/*! @} */

/*! @name STCSCH - SPDIF Transmit C-Channel Cons High */
/*! @{ */

#define SPDIF_STCSCH_TXCCHANNELCONS_H_MASK       (0xFFFFFFU)
#define SPDIF_STCSCH_TXCCHANNELCONS_H_SHIFT      (0U)
/*! TxCChannelCons_h - Transmit C-Channel Cons High */
#define SPDIF_STCSCH_TXCCHANNELCONS_H(x)         (((uint32_t)(((uint32_t)(x)) << SPDIF_STCSCH_TXCCHANNELCONS_H_SHIFT)) & SPDIF_STCSCH_TXCCHANNELCONS_H_MASK)
/*! @} */

/*! @name STCSCL - SPDIF Transmit C-Channel Cons Low */
/*! @{ */

#define SPDIF_STCSCL_TXCCHANNELCONS_L_MASK       (0xFFFFFFU)
#define SPDIF_STCSCL_TXCCHANNELCONS_L_SHIFT      (0U)
/*! TxCChannelCons_l - Transmit C-Channel Cons Low */
#define SPDIF_STCSCL_TXCCHANNELCONS_L(x)         (((uint32_t)(((uint32_t)(x)) << SPDIF_STCSCL_TXCCHANNELCONS_L_SHIFT)) & SPDIF_STCSCL_TXCCHANNELCONS_L_MASK)
/*! @} */

/*! @name SRFM - Frequency Measurement */
/*! @{ */

#define SPDIF_SRFM_FREQMEAS_MASK                 (0xFFFFFFU)
#define SPDIF_SRFM_FREQMEAS_SHIFT                (0U)
/*! FreqMeas - Frequency Measurement Data */
#define SPDIF_SRFM_FREQMEAS(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SRFM_FREQMEAS_SHIFT)) & SPDIF_SRFM_FREQMEAS_MASK)
/*! @} */

/*! @name STC - SPDIF Transmit Clock */
/*! @{ */

#define SPDIF_STC_TXCLK_DF_MASK                  (0x7FU)
#define SPDIF_STC_TXCLK_DF_SHIFT                 (0U)
/*! TxClk_DF - Transmit Clock Divider Factor (1-128)
 *  0b0000000..Divider factor is 1
 *  0b0000001..Divider factor is 2
 *  0b1111111..Divider factor is 128
 */
#define SPDIF_STC_TXCLK_DF(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TXCLK_DF_SHIFT)) & SPDIF_STC_TXCLK_DF_MASK)

#define SPDIF_STC_TX_ALL_CLK_EN_MASK             (0x80U)
#define SPDIF_STC_TX_ALL_CLK_EN_SHIFT            (7U)
/*! tx_all_clk_en - Transfer Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SPDIF_STC_TX_ALL_CLK_EN(x)               (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TX_ALL_CLK_EN_SHIFT)) & SPDIF_STC_TX_ALL_CLK_EN_MASK)

#define SPDIF_STC_TXCLK_SOURCE_MASK              (0x700U)
#define SPDIF_STC_TXCLK_SOURCE_SHIFT             (8U)
/*! TxClk_Source - Transmit Clock Source */
#define SPDIF_STC_TXCLK_SOURCE(x)                (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TXCLK_SOURCE_SHIFT)) & SPDIF_STC_TXCLK_SOURCE_MASK)

#define SPDIF_STC_SYSCLK_DF_MASK                 (0xFF800U)
#define SPDIF_STC_SYSCLK_DF_SHIFT                (11U)
/*! SYSCLK_DF - System Clock Divider Factor (2-512)
 *  0b000000000..No clock signal
 *  0b000000001..Divider factor is 2
 *  0b111111111..Divider factor is 512
 */
#define SPDIF_STC_SYSCLK_DF(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_SYSCLK_DF_SHIFT)) & SPDIF_STC_SYSCLK_DF_MASK)
/*! @} */

/*! @name SPDIFRXCCHANNEL_ADDR_31_0 - SPDIF Receive C-Channel Bits 31-0 */
/*! @{ */

#define SPDIF_SPDIFRXCCHANNEL_ADDR_31_0_RXCCHANNEL_ADDR_31_0_MASK (0xFFFFFFFFU)
#define SPDIF_SPDIFRXCCHANNEL_ADDR_31_0_RXCCHANNEL_ADDR_31_0_SHIFT (0U)
/*! RxCChannel_Addr_31_0 - Receive C-Channel Address (31-0) */
#define SPDIF_SPDIFRXCCHANNEL_ADDR_31_0_RXCCHANNEL_ADDR_31_0(x) (((uint32_t)(((uint32_t)(x)) << SPDIF_SPDIFRXCCHANNEL_ADDR_31_0_RXCCHANNEL_ADDR_31_0_SHIFT)) & SPDIF_SPDIFRXCCHANNEL_ADDR_31_0_RXCCHANNEL_ADDR_31_0_MASK)
/*! @} */

/*! @name SPDIFRXCCHANNEL_ADDR_63_32 - SPDIF Receive C-Channel Bits 63-32 */
/*! @{ */

#define SPDIF_SPDIFRXCCHANNEL_ADDR_63_32_RXCCHANNEL_ADDR_63_32_MASK (0xFFFFFFFFU)
#define SPDIF_SPDIFRXCCHANNEL_ADDR_63_32_RXCCHANNEL_ADDR_63_32_SHIFT (0U)
/*! RxCChannel_Addr_63_32 - Receive C-Channel Address (63-32) */
#define SPDIF_SPDIFRXCCHANNEL_ADDR_63_32_RXCCHANNEL_ADDR_63_32(x) (((uint32_t)(((uint32_t)(x)) << SPDIF_SPDIFRXCCHANNEL_ADDR_63_32_RXCCHANNEL_ADDR_63_32_SHIFT)) & SPDIF_SPDIFRXCCHANNEL_ADDR_63_32_RXCCHANNEL_ADDR_63_32_MASK)
/*! @} */

/*! @name SPDIFRXCCHANNEL_ADDR_95_64 - SPDIF Receive C-Channel Bits 95-64 */
/*! @{ */

#define SPDIF_SPDIFRXCCHANNEL_ADDR_95_64_RXCCHANNEL_ADDR_95_64_MASK (0xFFFFFFFFU)
#define SPDIF_SPDIFRXCCHANNEL_ADDR_95_64_RXCCHANNEL_ADDR_95_64_SHIFT (0U)
/*! RxCChannel_Addr_95_64 - Receive C-Channel Address (95-64) */
#define SPDIF_SPDIFRXCCHANNEL_ADDR_95_64_RXCCHANNEL_ADDR_95_64(x) (((uint32_t)(((uint32_t)(x)) << SPDIF_SPDIFRXCCHANNEL_ADDR_95_64_RXCCHANNEL_ADDR_95_64_SHIFT)) & SPDIF_SPDIFRXCCHANNEL_ADDR_95_64_RXCCHANNEL_ADDR_95_64_MASK)
/*! @} */

/*! @name SPDIFRXCCHANNEL_ADDR_127_96 - SPDIF Receive C-Channel Bits 127-96 */
/*! @{ */

#define SPDIF_SPDIFRXCCHANNEL_ADDR_127_96_RXCCHANNEL_ADDR_127_96_MASK (0xFFFFFFFFU)
#define SPDIF_SPDIFRXCCHANNEL_ADDR_127_96_RXCCHANNEL_ADDR_127_96_SHIFT (0U)
/*! RxCChannel_Addr_127_96 - Receive C-Channel Address (127-96) */
#define SPDIF_SPDIFRXCCHANNEL_ADDR_127_96_RXCCHANNEL_ADDR_127_96(x) (((uint32_t)(((uint32_t)(x)) << SPDIF_SPDIFRXCCHANNEL_ADDR_127_96_RXCCHANNEL_ADDR_127_96_SHIFT)) & SPDIF_SPDIFRXCCHANNEL_ADDR_127_96_RXCCHANNEL_ADDR_127_96_MASK)
/*! @} */

/*! @name SPDIFRXCCHANNEL_ADDR_159_128 - SPDIF Receive C-Channel Bits 159-128 */
/*! @{ */

#define SPDIF_SPDIFRXCCHANNEL_ADDR_159_128_RXCCHANNEL_ADDR_159_128_MASK (0xFFFFFFFFU)
#define SPDIF_SPDIFRXCCHANNEL_ADDR_159_128_RXCCHANNEL_ADDR_159_128_SHIFT (0U)
/*! RxCChannel_Addr_159_128 - Receive C-Channel Address (159-128) */
#define SPDIF_SPDIFRXCCHANNEL_ADDR_159_128_RXCCHANNEL_ADDR_159_128(x) (((uint32_t)(((uint32_t)(x)) << SPDIF_SPDIFRXCCHANNEL_ADDR_159_128_RXCCHANNEL_ADDR_159_128_SHIFT)) & SPDIF_SPDIFRXCCHANNEL_ADDR_159_128_RXCCHANNEL_ADDR_159_128_MASK)
/*! @} */

/*! @name SPDIFRXCCHANNEL_ADDR_191_160 - SPDIF Receive C-Channel Bits 191-160 */
/*! @{ */

#define SPDIF_SPDIFRXCCHANNEL_ADDR_191_160_RXCCHANNEL_ADDR_191_160_MASK (0xFFFFFFFFU)
#define SPDIF_SPDIFRXCCHANNEL_ADDR_191_160_RXCCHANNEL_ADDR_191_160_SHIFT (0U)
/*! RxCChannel_Addr_191_160 - Receive C-Channel Address (191-160) */
#define SPDIF_SPDIFRXCCHANNEL_ADDR_191_160_RXCCHANNEL_ADDR_191_160(x) (((uint32_t)(((uint32_t)(x)) << SPDIF_SPDIFRXCCHANNEL_ADDR_191_160_RXCCHANNEL_ADDR_191_160_SHIFT)) & SPDIF_SPDIFRXCCHANNEL_ADDR_191_160_RXCCHANNEL_ADDR_191_160_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPDIF_Register_Masks */


/*!
 * @}
 */ /* end of group SPDIF_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SPDIF_H_ */

