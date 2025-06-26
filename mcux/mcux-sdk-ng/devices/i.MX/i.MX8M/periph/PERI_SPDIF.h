/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 4.0, 2018-01-26
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SPDIF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**
** ###################################################################
*/

/*!
 * @file SPDIF.h
 * @version 4.0
 * @date 2018-01-26
 * @brief CMSIS Peripheral Access Layer for SPDIF
 *
 * CMSIS Peripheral Access Layer for SPDIF
 */

#if !defined(SPDIF_H_)
#define SPDIF_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- SPDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPDIF_Peripheral_Access_Layer SPDIF Peripheral Access Layer
 * @{
 */

/** SPDIF - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCR;                               /**< SPDIF Configuration Register, offset: 0x0 */
  __IO uint32_t SRCD;                              /**< CDText Control Register, offset: 0x4 */
  __IO uint32_t SRPC;                              /**< PhaseConfig Register, offset: 0x8 */
  __IO uint32_t SIE;                               /**< InterruptEn Register, offset: 0xC */
  union {                                          /* offset: 0x10 */
    __O  uint32_t SIC;                               /**< InterruptClear Register, offset: 0x10 */
    __I  uint32_t SIS;                               /**< InterruptStat Register, offset: 0x10 */
  };
  __I  uint32_t SRL;                               /**< SPDIFRxLeft Register, offset: 0x14 */
  __I  uint32_t SRR;                               /**< SPDIFRxRight Register, offset: 0x18 */
  __I  uint32_t SRCSH;                             /**< SPDIFRxCChannel_h Register, offset: 0x1C */
  __I  uint32_t SRCSL;                             /**< SPDIFRxCChannel_l Register, offset: 0x20 */
  __I  uint32_t SRU;                               /**< UchannelRx Register, offset: 0x24 */
  __I  uint32_t SRQ;                               /**< QchannelRx Register, offset: 0x28 */
  __O  uint32_t STL;                               /**< SPDIFTxLeft Register, offset: 0x2C */
  __O  uint32_t STR;                               /**< SPDIFTxRight Register, offset: 0x30 */
  __IO uint32_t STCSCH;                            /**< SPDIFTxCChannelCons_h Register, offset: 0x34 */
  __IO uint32_t STCSCL;                            /**< SPDIFTxCChannelCons_l Register, offset: 0x38 */
       uint8_t RESERVED_0[8];
  __I  uint32_t SRFM;                              /**< FreqMeas Register, offset: 0x44 */
       uint8_t RESERVED_1[8];
  __IO uint32_t STC;                               /**< SPDIFTxClk Register, offset: 0x50 */
} SPDIF_Type;

/* ----------------------------------------------------------------------------
   -- SPDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPDIF_Register_Masks SPDIF Register Masks
 * @{
 */

/*! @name SCR - SPDIF Configuration Register */
/*! @{ */

#define SPDIF_SCR_USRC_SEL_MASK                  (0x3U)
#define SPDIF_SCR_USRC_SEL_SHIFT                 (0U)
/*! USrc_Sel
 *  0b00..No embedded U channel
 *  0b01..U channel from SPDIF receive block (CD mode)
 *  0b10..Reserved
 *  0b11..U channel from on chip transmitter
 */
#define SPDIF_SCR_USRC_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_USRC_SEL_SHIFT)) & SPDIF_SCR_USRC_SEL_MASK)

#define SPDIF_SCR_TXSEL_MASK                     (0x1CU)
#define SPDIF_SCR_TXSEL_SHIFT                    (2U)
/*! TxSel
 *  0b000..Off and output 0
 *  0b001..Feed-through SPDIFIN
 *  0b101..Tx Normal operation
 */
#define SPDIF_SCR_TXSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXSEL_SHIFT)) & SPDIF_SCR_TXSEL_MASK)

#define SPDIF_SCR_VALCTRL_MASK                   (0x20U)
#define SPDIF_SCR_VALCTRL_SHIFT                  (5U)
/*! ValCtrl
 *  0b0..Outgoing Validity always set
 *  0b1..Outgoing Validity always clear
 */
#define SPDIF_SCR_VALCTRL(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_VALCTRL_SHIFT)) & SPDIF_SCR_VALCTRL_MASK)

#define SPDIF_SCR_DMA_TX_EN_MASK                 (0x100U)
#define SPDIF_SCR_DMA_TX_EN_SHIFT                (8U)
#define SPDIF_SCR_DMA_TX_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_DMA_TX_EN_SHIFT)) & SPDIF_SCR_DMA_TX_EN_MASK)

#define SPDIF_SCR_DMA_RX_EN_MASK                 (0x200U)
#define SPDIF_SCR_DMA_RX_EN_SHIFT                (9U)
#define SPDIF_SCR_DMA_RX_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_DMA_RX_EN_SHIFT)) & SPDIF_SCR_DMA_RX_EN_MASK)

#define SPDIF_SCR_TXFIFO_CTRL_MASK               (0xC00U)
#define SPDIF_SCR_TXFIFO_CTRL_SHIFT              (10U)
/*! TxFIFO_Ctrl
 *  0b00..Send out digital zero on SPDIF Tx
 *  0b01..Tx Normal operation
 *  0b10..Reset to 1 sample remaining
 *  0b11..Reserved
 */
#define SPDIF_SCR_TXFIFO_CTRL(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXFIFO_CTRL_SHIFT)) & SPDIF_SCR_TXFIFO_CTRL_MASK)

#define SPDIF_SCR_SOFT_RESET_MASK                (0x1000U)
#define SPDIF_SCR_SOFT_RESET_SHIFT               (12U)
#define SPDIF_SCR_SOFT_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_SOFT_RESET_SHIFT)) & SPDIF_SCR_SOFT_RESET_MASK)

#define SPDIF_SCR_LOW_POWER_MASK                 (0x2000U)
#define SPDIF_SCR_LOW_POWER_SHIFT                (13U)
#define SPDIF_SCR_LOW_POWER(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_LOW_POWER_SHIFT)) & SPDIF_SCR_LOW_POWER_MASK)

#define SPDIF_SCR_TXFIFOEMPTY_SEL_MASK           (0x18000U)
#define SPDIF_SCR_TXFIFOEMPTY_SEL_SHIFT          (15U)
/*! TxFIFOEmpty_Sel
 *  0b00..Empty interrupt if 0 sample in Tx left and right FIFOs
 *  0b01..Empty interrupt if at most 4 sample in Tx left and right FIFOs
 *  0b10..Empty interrupt if at most 8 sample in Tx left and right FIFOs
 *  0b11..Empty interrupt if at most 12 sample in Tx left and right FIFOs
 */
#define SPDIF_SCR_TXFIFOEMPTY_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXFIFOEMPTY_SEL_SHIFT)) & SPDIF_SCR_TXFIFOEMPTY_SEL_MASK)

#define SPDIF_SCR_TXAUTOSYNC_MASK                (0x20000U)
#define SPDIF_SCR_TXAUTOSYNC_SHIFT               (17U)
/*! TxAutoSync
 *  0b0..Tx FIFO auto sync off
 *  0b1..Tx FIFO auto sync on
 */
#define SPDIF_SCR_TXAUTOSYNC(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TXAUTOSYNC_SHIFT)) & SPDIF_SCR_TXAUTOSYNC_MASK)

#define SPDIF_SCR_RXAUTOSYNC_MASK                (0x40000U)
#define SPDIF_SCR_RXAUTOSYNC_SHIFT               (18U)
/*! RxAutoSync
 *  0b0..Rx FIFO auto sync off
 *  0b1..RxFIFO auto sync on
 */
#define SPDIF_SCR_RXAUTOSYNC(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXAUTOSYNC_SHIFT)) & SPDIF_SCR_RXAUTOSYNC_MASK)

#define SPDIF_SCR_RXFIFOFULL_SEL_MASK            (0x180000U)
#define SPDIF_SCR_RXFIFOFULL_SEL_SHIFT           (19U)
/*! RxFIFOFull_Sel
 *  0b00..Full interrupt if at least 1 sample in Rx left and right FIFOs
 *  0b01..Full interrupt if at least 4 sample in Rx left and right FIFOs
 *  0b10..Full interrupt if at least 8 sample in Rx left and right FIFOs
 *  0b11..Full interrupt if at least 16 sample in Rx left and right FIFO
 */
#define SPDIF_SCR_RXFIFOFULL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFOFULL_SEL_SHIFT)) & SPDIF_SCR_RXFIFOFULL_SEL_MASK)

#define SPDIF_SCR_RXFIFO_RST_MASK                (0x200000U)
#define SPDIF_SCR_RXFIFO_RST_SHIFT               (21U)
/*! RxFIFO_Rst
 *  0b0..Normal operation
 *  0b1..Reset register to 1 sample remaining
 */
#define SPDIF_SCR_RXFIFO_RST(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFO_RST_SHIFT)) & SPDIF_SCR_RXFIFO_RST_MASK)

#define SPDIF_SCR_RXFIFO_OFF_ON_MASK             (0x400000U)
#define SPDIF_SCR_RXFIFO_OFF_ON_SHIFT            (22U)
/*! RxFIFO_Off_On
 *  0b0..SPDIF Rx FIFO is on
 *  0b1..SPDIF Rx FIFO is off. Does not accept data from interface
 */
#define SPDIF_SCR_RXFIFO_OFF_ON(x)               (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFO_OFF_ON_SHIFT)) & SPDIF_SCR_RXFIFO_OFF_ON_MASK)

#define SPDIF_SCR_RXFIFO_CTRL_MASK               (0x800000U)
#define SPDIF_SCR_RXFIFO_CTRL_SHIFT              (23U)
/*! RxFIFO_Ctrl
 *  0b0..Normal operation
 *  0b1..Always read zero from Rx data register
 */
#define SPDIF_SCR_RXFIFO_CTRL(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RXFIFO_CTRL_SHIFT)) & SPDIF_SCR_RXFIFO_CTRL_MASK)
/*! @} */

/*! @name SRCD - CDText Control Register */
/*! @{ */

#define SPDIF_SRCD_USYNCMODE_MASK                (0x2U)
#define SPDIF_SRCD_USYNCMODE_SHIFT               (1U)
/*! USyncMode
 *  0b0..Non-CD data
 *  0b1..CD user channel subcode
 */
#define SPDIF_SRCD_USYNCMODE(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCD_USYNCMODE_SHIFT)) & SPDIF_SRCD_USYNCMODE_MASK)
/*! @} */

/*! @name SRPC - PhaseConfig Register */
/*! @{ */

#define SPDIF_SRPC_GAINSEL_MASK                  (0x38U)
#define SPDIF_SRPC_GAINSEL_SHIFT                 (3U)
/*! GainSel
 *  0b000..24*(2**10)
 *  0b001..16*(2**10)
 *  0b010..12*(2**10)
 *  0b011..8*(2**10)
 *  0b100..6*(2**10)
 *  0b101..4*(2**10)
 *  0b110..3*(2**10)
 */
#define SPDIF_SRPC_GAINSEL(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_GAINSEL_SHIFT)) & SPDIF_SRPC_GAINSEL_MASK)

#define SPDIF_SRPC_LOCK_MASK                     (0x40U)
#define SPDIF_SRPC_LOCK_SHIFT                    (6U)
#define SPDIF_SRPC_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_LOCK_SHIFT)) & SPDIF_SRPC_LOCK_MASK)

#define SPDIF_SRPC_CLKSRC_SEL_MASK               (0x780U)
#define SPDIF_SRPC_CLKSRC_SEL_SHIFT              (7U)
/*! ClkSrc_Sel
 *  0b0000..if (DPLL Locked) SPDIF_RxClk else REF_CLK_32K (XTALOSC)
 *  0b0001..if (DPLL Locked) SPDIF_RxClk else tx_clk (SPDIF0_CLK_ROOT)
 *  0b0011..if (DPLL Locked) SPDIF_RxClk else SPDIF_EXT_CLK
 *  0b0101..REF_CLK_32K (XTALOSC)
 *  0b0110..tx_clk (SPDIF0_CLK_ROOT)
 *  0b1000..SPDIF_EXT_CLK
 */
#define SPDIF_SRPC_CLKSRC_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_CLKSRC_SEL_SHIFT)) & SPDIF_SRPC_CLKSRC_SEL_MASK)
/*! @} */

/*! @name SIE - InterruptEn Register */
/*! @{ */

#define SPDIF_SIE_RXFIFOFUL_MASK                 (0x1U)
#define SPDIF_SIE_RXFIFOFUL_SHIFT                (0U)
#define SPDIF_SIE_RXFIFOFUL(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RXFIFOFUL_SHIFT)) & SPDIF_SIE_RXFIFOFUL_MASK)

#define SPDIF_SIE_TXEM_MASK                      (0x2U)
#define SPDIF_SIE_TXEM_SHIFT                     (1U)
#define SPDIF_SIE_TXEM(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TXEM_SHIFT)) & SPDIF_SIE_TXEM_MASK)

#define SPDIF_SIE_LOCKLOSS_MASK                  (0x4U)
#define SPDIF_SIE_LOCKLOSS_SHIFT                 (2U)
#define SPDIF_SIE_LOCKLOSS(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_LOCKLOSS_SHIFT)) & SPDIF_SIE_LOCKLOSS_MASK)

#define SPDIF_SIE_RXFIFORESYN_MASK               (0x8U)
#define SPDIF_SIE_RXFIFORESYN_SHIFT              (3U)
#define SPDIF_SIE_RXFIFORESYN(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RXFIFORESYN_SHIFT)) & SPDIF_SIE_RXFIFORESYN_MASK)

#define SPDIF_SIE_RXFIFOUNOV_MASK                (0x10U)
#define SPDIF_SIE_RXFIFOUNOV_SHIFT               (4U)
#define SPDIF_SIE_RXFIFOUNOV(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RXFIFOUNOV_SHIFT)) & SPDIF_SIE_RXFIFOUNOV_MASK)

#define SPDIF_SIE_UQERR_MASK                     (0x20U)
#define SPDIF_SIE_UQERR_SHIFT                    (5U)
#define SPDIF_SIE_UQERR(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_UQERR_SHIFT)) & SPDIF_SIE_UQERR_MASK)

#define SPDIF_SIE_UQSYNC_MASK                    (0x40U)
#define SPDIF_SIE_UQSYNC_SHIFT                   (6U)
#define SPDIF_SIE_UQSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_UQSYNC_SHIFT)) & SPDIF_SIE_UQSYNC_MASK)

#define SPDIF_SIE_QRXOV_MASK                     (0x80U)
#define SPDIF_SIE_QRXOV_SHIFT                    (7U)
#define SPDIF_SIE_QRXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_QRXOV_SHIFT)) & SPDIF_SIE_QRXOV_MASK)

#define SPDIF_SIE_QRXFUL_MASK                    (0x100U)
#define SPDIF_SIE_QRXFUL_SHIFT                   (8U)
#define SPDIF_SIE_QRXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_QRXFUL_SHIFT)) & SPDIF_SIE_QRXFUL_MASK)

#define SPDIF_SIE_URXOV_MASK                     (0x200U)
#define SPDIF_SIE_URXOV_SHIFT                    (9U)
#define SPDIF_SIE_URXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_URXOV_SHIFT)) & SPDIF_SIE_URXOV_MASK)

#define SPDIF_SIE_URXFUL_MASK                    (0x400U)
#define SPDIF_SIE_URXFUL_SHIFT                   (10U)
#define SPDIF_SIE_URXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_URXFUL_SHIFT)) & SPDIF_SIE_URXFUL_MASK)

#define SPDIF_SIE_BITERR_MASK                    (0x4000U)
#define SPDIF_SIE_BITERR_SHIFT                   (14U)
#define SPDIF_SIE_BITERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_BITERR_SHIFT)) & SPDIF_SIE_BITERR_MASK)

#define SPDIF_SIE_SYMERR_MASK                    (0x8000U)
#define SPDIF_SIE_SYMERR_SHIFT                   (15U)
#define SPDIF_SIE_SYMERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_SYMERR_SHIFT)) & SPDIF_SIE_SYMERR_MASK)

#define SPDIF_SIE_VALNOGOOD_MASK                 (0x10000U)
#define SPDIF_SIE_VALNOGOOD_SHIFT                (16U)
#define SPDIF_SIE_VALNOGOOD(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_VALNOGOOD_SHIFT)) & SPDIF_SIE_VALNOGOOD_MASK)

#define SPDIF_SIE_CNEW_MASK                      (0x20000U)
#define SPDIF_SIE_CNEW_SHIFT                     (17U)
#define SPDIF_SIE_CNEW(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_CNEW_SHIFT)) & SPDIF_SIE_CNEW_MASK)

#define SPDIF_SIE_TXRESYN_MASK                   (0x40000U)
#define SPDIF_SIE_TXRESYN_SHIFT                  (18U)
#define SPDIF_SIE_TXRESYN(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TXRESYN_SHIFT)) & SPDIF_SIE_TXRESYN_MASK)

#define SPDIF_SIE_TXUNOV_MASK                    (0x80000U)
#define SPDIF_SIE_TXUNOV_SHIFT                   (19U)
#define SPDIF_SIE_TXUNOV(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TXUNOV_SHIFT)) & SPDIF_SIE_TXUNOV_MASK)

#define SPDIF_SIE_LOCK_MASK                      (0x100000U)
#define SPDIF_SIE_LOCK_SHIFT                     (20U)
#define SPDIF_SIE_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_LOCK_SHIFT)) & SPDIF_SIE_LOCK_MASK)
/*! @} */

/*! @name SIC - InterruptClear Register */
/*! @{ */

#define SPDIF_SIC_LOCKLOSS_MASK                  (0x4U)
#define SPDIF_SIC_LOCKLOSS_SHIFT                 (2U)
#define SPDIF_SIC_LOCKLOSS(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_LOCKLOSS_SHIFT)) & SPDIF_SIC_LOCKLOSS_MASK)

#define SPDIF_SIC_RXFIFORESYN_MASK               (0x8U)
#define SPDIF_SIC_RXFIFORESYN_SHIFT              (3U)
#define SPDIF_SIC_RXFIFORESYN(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_RXFIFORESYN_SHIFT)) & SPDIF_SIC_RXFIFORESYN_MASK)

#define SPDIF_SIC_RXFIFOUNOV_MASK                (0x10U)
#define SPDIF_SIC_RXFIFOUNOV_SHIFT               (4U)
#define SPDIF_SIC_RXFIFOUNOV(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_RXFIFOUNOV_SHIFT)) & SPDIF_SIC_RXFIFOUNOV_MASK)

#define SPDIF_SIC_UQERR_MASK                     (0x20U)
#define SPDIF_SIC_UQERR_SHIFT                    (5U)
#define SPDIF_SIC_UQERR(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_UQERR_SHIFT)) & SPDIF_SIC_UQERR_MASK)

#define SPDIF_SIC_UQSYNC_MASK                    (0x40U)
#define SPDIF_SIC_UQSYNC_SHIFT                   (6U)
#define SPDIF_SIC_UQSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_UQSYNC_SHIFT)) & SPDIF_SIC_UQSYNC_MASK)

#define SPDIF_SIC_QRXOV_MASK                     (0x80U)
#define SPDIF_SIC_QRXOV_SHIFT                    (7U)
#define SPDIF_SIC_QRXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_QRXOV_SHIFT)) & SPDIF_SIC_QRXOV_MASK)

#define SPDIF_SIC_URXOV_MASK                     (0x200U)
#define SPDIF_SIC_URXOV_SHIFT                    (9U)
#define SPDIF_SIC_URXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_URXOV_SHIFT)) & SPDIF_SIC_URXOV_MASK)

#define SPDIF_SIC_BITERR_MASK                    (0x4000U)
#define SPDIF_SIC_BITERR_SHIFT                   (14U)
#define SPDIF_SIC_BITERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_BITERR_SHIFT)) & SPDIF_SIC_BITERR_MASK)

#define SPDIF_SIC_SYMERR_MASK                    (0x8000U)
#define SPDIF_SIC_SYMERR_SHIFT                   (15U)
#define SPDIF_SIC_SYMERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_SYMERR_SHIFT)) & SPDIF_SIC_SYMERR_MASK)

#define SPDIF_SIC_VALNOGOOD_MASK                 (0x10000U)
#define SPDIF_SIC_VALNOGOOD_SHIFT                (16U)
#define SPDIF_SIC_VALNOGOOD(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_VALNOGOOD_SHIFT)) & SPDIF_SIC_VALNOGOOD_MASK)

#define SPDIF_SIC_CNEW_MASK                      (0x20000U)
#define SPDIF_SIC_CNEW_SHIFT                     (17U)
#define SPDIF_SIC_CNEW(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_CNEW_SHIFT)) & SPDIF_SIC_CNEW_MASK)

#define SPDIF_SIC_TXRESYN_MASK                   (0x40000U)
#define SPDIF_SIC_TXRESYN_SHIFT                  (18U)
#define SPDIF_SIC_TXRESYN(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_TXRESYN_SHIFT)) & SPDIF_SIC_TXRESYN_MASK)

#define SPDIF_SIC_TXUNOV_MASK                    (0x80000U)
#define SPDIF_SIC_TXUNOV_SHIFT                   (19U)
#define SPDIF_SIC_TXUNOV(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_TXUNOV_SHIFT)) & SPDIF_SIC_TXUNOV_MASK)

#define SPDIF_SIC_LOCK_MASK                      (0x100000U)
#define SPDIF_SIC_LOCK_SHIFT                     (20U)
#define SPDIF_SIC_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_LOCK_SHIFT)) & SPDIF_SIC_LOCK_MASK)
/*! @} */

/*! @name SIS - InterruptStat Register */
/*! @{ */

#define SPDIF_SIS_RXFIFOFUL_MASK                 (0x1U)
#define SPDIF_SIS_RXFIFOFUL_SHIFT                (0U)
#define SPDIF_SIS_RXFIFOFUL(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RXFIFOFUL_SHIFT)) & SPDIF_SIS_RXFIFOFUL_MASK)

#define SPDIF_SIS_TXEM_MASK                      (0x2U)
#define SPDIF_SIS_TXEM_SHIFT                     (1U)
#define SPDIF_SIS_TXEM(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TXEM_SHIFT)) & SPDIF_SIS_TXEM_MASK)

#define SPDIF_SIS_LOCKLOSS_MASK                  (0x4U)
#define SPDIF_SIS_LOCKLOSS_SHIFT                 (2U)
#define SPDIF_SIS_LOCKLOSS(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_LOCKLOSS_SHIFT)) & SPDIF_SIS_LOCKLOSS_MASK)

#define SPDIF_SIS_RXFIFORESYN_MASK               (0x8U)
#define SPDIF_SIS_RXFIFORESYN_SHIFT              (3U)
#define SPDIF_SIS_RXFIFORESYN(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RXFIFORESYN_SHIFT)) & SPDIF_SIS_RXFIFORESYN_MASK)

#define SPDIF_SIS_RXFIFOUNOV_MASK                (0x10U)
#define SPDIF_SIS_RXFIFOUNOV_SHIFT               (4U)
#define SPDIF_SIS_RXFIFOUNOV(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RXFIFOUNOV_SHIFT)) & SPDIF_SIS_RXFIFOUNOV_MASK)

#define SPDIF_SIS_UQERR_MASK                     (0x20U)
#define SPDIF_SIS_UQERR_SHIFT                    (5U)
#define SPDIF_SIS_UQERR(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_UQERR_SHIFT)) & SPDIF_SIS_UQERR_MASK)

#define SPDIF_SIS_UQSYNC_MASK                    (0x40U)
#define SPDIF_SIS_UQSYNC_SHIFT                   (6U)
#define SPDIF_SIS_UQSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_UQSYNC_SHIFT)) & SPDIF_SIS_UQSYNC_MASK)

#define SPDIF_SIS_QRXOV_MASK                     (0x80U)
#define SPDIF_SIS_QRXOV_SHIFT                    (7U)
#define SPDIF_SIS_QRXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_QRXOV_SHIFT)) & SPDIF_SIS_QRXOV_MASK)

#define SPDIF_SIS_QRXFUL_MASK                    (0x100U)
#define SPDIF_SIS_QRXFUL_SHIFT                   (8U)
#define SPDIF_SIS_QRXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_QRXFUL_SHIFT)) & SPDIF_SIS_QRXFUL_MASK)

#define SPDIF_SIS_URXOV_MASK                     (0x200U)
#define SPDIF_SIS_URXOV_SHIFT                    (9U)
#define SPDIF_SIS_URXOV(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_URXOV_SHIFT)) & SPDIF_SIS_URXOV_MASK)

#define SPDIF_SIS_URXFUL_MASK                    (0x400U)
#define SPDIF_SIS_URXFUL_SHIFT                   (10U)
#define SPDIF_SIS_URXFUL(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_URXFUL_SHIFT)) & SPDIF_SIS_URXFUL_MASK)

#define SPDIF_SIS_BITERR_MASK                    (0x4000U)
#define SPDIF_SIS_BITERR_SHIFT                   (14U)
#define SPDIF_SIS_BITERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_BITERR_SHIFT)) & SPDIF_SIS_BITERR_MASK)

#define SPDIF_SIS_SYMERR_MASK                    (0x8000U)
#define SPDIF_SIS_SYMERR_SHIFT                   (15U)
#define SPDIF_SIS_SYMERR(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_SYMERR_SHIFT)) & SPDIF_SIS_SYMERR_MASK)

#define SPDIF_SIS_VALNOGOOD_MASK                 (0x10000U)
#define SPDIF_SIS_VALNOGOOD_SHIFT                (16U)
#define SPDIF_SIS_VALNOGOOD(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_VALNOGOOD_SHIFT)) & SPDIF_SIS_VALNOGOOD_MASK)

#define SPDIF_SIS_CNEW_MASK                      (0x20000U)
#define SPDIF_SIS_CNEW_SHIFT                     (17U)
#define SPDIF_SIS_CNEW(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_CNEW_SHIFT)) & SPDIF_SIS_CNEW_MASK)

#define SPDIF_SIS_TXRESYN_MASK                   (0x40000U)
#define SPDIF_SIS_TXRESYN_SHIFT                  (18U)
#define SPDIF_SIS_TXRESYN(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TXRESYN_SHIFT)) & SPDIF_SIS_TXRESYN_MASK)

#define SPDIF_SIS_TXUNOV_MASK                    (0x80000U)
#define SPDIF_SIS_TXUNOV_SHIFT                   (19U)
#define SPDIF_SIS_TXUNOV(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TXUNOV_SHIFT)) & SPDIF_SIS_TXUNOV_MASK)

#define SPDIF_SIS_LOCK_MASK                      (0x100000U)
#define SPDIF_SIS_LOCK_SHIFT                     (20U)
#define SPDIF_SIS_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_LOCK_SHIFT)) & SPDIF_SIS_LOCK_MASK)
/*! @} */

/*! @name SRL - SPDIFRxLeft Register */
/*! @{ */

#define SPDIF_SRL_RXDATALEFT_MASK                (0xFFFFFFU)
#define SPDIF_SRL_RXDATALEFT_SHIFT               (0U)
#define SPDIF_SRL_RXDATALEFT(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRL_RXDATALEFT_SHIFT)) & SPDIF_SRL_RXDATALEFT_MASK)
/*! @} */

/*! @name SRR - SPDIFRxRight Register */
/*! @{ */

#define SPDIF_SRR_RXDATARIGHT_MASK               (0xFFFFFFU)
#define SPDIF_SRR_RXDATARIGHT_SHIFT              (0U)
#define SPDIF_SRR_RXDATARIGHT(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SRR_RXDATARIGHT_SHIFT)) & SPDIF_SRR_RXDATARIGHT_MASK)
/*! @} */

/*! @name SRCSH - SPDIFRxCChannel_h Register */
/*! @{ */

#define SPDIF_SRCSH_RXCCHANNEL_H_MASK            (0xFFFFFFU)
#define SPDIF_SRCSH_RXCCHANNEL_H_SHIFT           (0U)
#define SPDIF_SRCSH_RXCCHANNEL_H(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCSH_RXCCHANNEL_H_SHIFT)) & SPDIF_SRCSH_RXCCHANNEL_H_MASK)
/*! @} */

/*! @name SRCSL - SPDIFRxCChannel_l Register */
/*! @{ */

#define SPDIF_SRCSL_RXCCHANNEL_L_MASK            (0xFFFFFFU)
#define SPDIF_SRCSL_RXCCHANNEL_L_SHIFT           (0U)
#define SPDIF_SRCSL_RXCCHANNEL_L(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCSL_RXCCHANNEL_L_SHIFT)) & SPDIF_SRCSL_RXCCHANNEL_L_MASK)
/*! @} */

/*! @name SRU - UchannelRx Register */
/*! @{ */

#define SPDIF_SRU_RXUCHANNEL_MASK                (0xFFFFFFU)
#define SPDIF_SRU_RXUCHANNEL_SHIFT               (0U)
#define SPDIF_SRU_RXUCHANNEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRU_RXUCHANNEL_SHIFT)) & SPDIF_SRU_RXUCHANNEL_MASK)
/*! @} */

/*! @name SRQ - QchannelRx Register */
/*! @{ */

#define SPDIF_SRQ_RXQCHANNEL_MASK                (0xFFFFFFU)
#define SPDIF_SRQ_RXQCHANNEL_SHIFT               (0U)
#define SPDIF_SRQ_RXQCHANNEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRQ_RXQCHANNEL_SHIFT)) & SPDIF_SRQ_RXQCHANNEL_MASK)
/*! @} */

/*! @name STL - SPDIFTxLeft Register */
/*! @{ */

#define SPDIF_STL_TXDATALEFT_MASK                (0xFFFFFFU)
#define SPDIF_STL_TXDATALEFT_SHIFT               (0U)
#define SPDIF_STL_TXDATALEFT(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_STL_TXDATALEFT_SHIFT)) & SPDIF_STL_TXDATALEFT_MASK)
/*! @} */

/*! @name STR - SPDIFTxRight Register */
/*! @{ */

#define SPDIF_STR_TXDATARIGHT_MASK               (0xFFFFFFU)
#define SPDIF_STR_TXDATARIGHT_SHIFT              (0U)
#define SPDIF_STR_TXDATARIGHT(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_STR_TXDATARIGHT_SHIFT)) & SPDIF_STR_TXDATARIGHT_MASK)
/*! @} */

/*! @name STCSCH - SPDIFTxCChannelCons_h Register */
/*! @{ */

#define SPDIF_STCSCH_TXCCHANNELCONS_H_MASK       (0xFFFFFFU)
#define SPDIF_STCSCH_TXCCHANNELCONS_H_SHIFT      (0U)
#define SPDIF_STCSCH_TXCCHANNELCONS_H(x)         (((uint32_t)(((uint32_t)(x)) << SPDIF_STCSCH_TXCCHANNELCONS_H_SHIFT)) & SPDIF_STCSCH_TXCCHANNELCONS_H_MASK)
/*! @} */

/*! @name STCSCL - SPDIFTxCChannelCons_l Register */
/*! @{ */

#define SPDIF_STCSCL_TXCCHANNELCONS_L_MASK       (0xFFFFFFU)
#define SPDIF_STCSCL_TXCCHANNELCONS_L_SHIFT      (0U)
#define SPDIF_STCSCL_TXCCHANNELCONS_L(x)         (((uint32_t)(((uint32_t)(x)) << SPDIF_STCSCL_TXCCHANNELCONS_L_SHIFT)) & SPDIF_STCSCL_TXCCHANNELCONS_L_MASK)
/*! @} */

/*! @name SRFM - FreqMeas Register */
/*! @{ */

#define SPDIF_SRFM_FREQMEAS_MASK                 (0xFFFFFFU)
#define SPDIF_SRFM_FREQMEAS_SHIFT                (0U)
#define SPDIF_SRFM_FREQMEAS(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SRFM_FREQMEAS_SHIFT)) & SPDIF_SRFM_FREQMEAS_MASK)
/*! @} */

/*! @name STC - SPDIFTxClk Register */
/*! @{ */

#define SPDIF_STC_TXCLK_DF_MASK                  (0x7FU)
#define SPDIF_STC_TXCLK_DF_SHIFT                 (0U)
/*! TxClk_DF
 *  0b0000000..divider factor is 1
 *  0b0000001..divider factor is 2
 *  0b1111111..divider factor is 128
 */
#define SPDIF_STC_TXCLK_DF(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TXCLK_DF_SHIFT)) & SPDIF_STC_TXCLK_DF_MASK)

#define SPDIF_STC_TX_ALL_CLK_EN_MASK             (0x80U)
#define SPDIF_STC_TX_ALL_CLK_EN_SHIFT            (7U)
/*! tx_all_clk_en
 *  0b0..disable transfer clock.
 *  0b1..enable transfer clock.
 */
#define SPDIF_STC_TX_ALL_CLK_EN(x)               (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TX_ALL_CLK_EN_SHIFT)) & SPDIF_STC_TX_ALL_CLK_EN_MASK)

#define SPDIF_STC_TXCLK_SOURCE_MASK              (0x700U)
#define SPDIF_STC_TXCLK_SOURCE_SHIFT             (8U)
/*! TxClk_Source
 *  0b000..REF_CLK_32K input (XTALOSC 32 kHz clock)
 *  0b001..tx_clk input (from SPDIF0_CLK_ROOT. See CCM.)
 *  0b011..SPDIF_EXT_CLK, from pads
 *  0b101..ipg_clk input (frequency divided)
 */
#define SPDIF_STC_TXCLK_SOURCE(x)                (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TXCLK_SOURCE_SHIFT)) & SPDIF_STC_TXCLK_SOURCE_MASK)

#define SPDIF_STC_SYSCLK_DF_MASK                 (0xFF800U)
#define SPDIF_STC_SYSCLK_DF_SHIFT                (11U)
/*! SYSCLK_DF
 *  0b000000000..no clock signal
 *  0b000000001..divider factor is 2
 *  0b111111111..divider factor is 512
 */
#define SPDIF_STC_SYSCLK_DF(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_SYSCLK_DF_SHIFT)) & SPDIF_STC_SYSCLK_DF_MASK)
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* SPDIF_H_ */

