/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
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
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SPDIF.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPDIF
 *
 * CMSIS Peripheral Access Layer for SPDIF
 */

#if !defined(PERI_SPDIF_H_)
#define PERI_SPDIF_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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

#define SPDIF_SCR_USrc_Sel_MASK                  (0x3U)
#define SPDIF_SCR_USrc_Sel_SHIFT                 (0U)
/*! USrc_Sel - USrc_Sel
 *  0b00..No embedded U channel
 *  0b01..U channel from SPDIF receive block (CD mode)
 *  0b10..Reserved
 *  0b11..U channel from on chip transmitter
 */
#define SPDIF_SCR_USrc_Sel(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_USrc_Sel_SHIFT)) & SPDIF_SCR_USrc_Sel_MASK)

#define SPDIF_SCR_TxSel_MASK                     (0x1CU)
#define SPDIF_SCR_TxSel_SHIFT                    (2U)
/*! TxSel - TxSel
 *  0b000..Off and output 0
 *  0b001..Feed-through SPDIFIN
 *  0b101..Tx Normal operation
 */
#define SPDIF_SCR_TxSel(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TxSel_SHIFT)) & SPDIF_SCR_TxSel_MASK)

#define SPDIF_SCR_ValCtrl_MASK                   (0x20U)
#define SPDIF_SCR_ValCtrl_SHIFT                  (5U)
/*! ValCtrl - ValCtrl
 *  0b0..Outgoing Validity always set
 *  0b1..Outgoing Validity always clear
 */
#define SPDIF_SCR_ValCtrl(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_ValCtrl_SHIFT)) & SPDIF_SCR_ValCtrl_MASK)

#define SPDIF_SCR_DMA_TX_En_MASK                 (0x100U)
#define SPDIF_SCR_DMA_TX_En_SHIFT                (8U)
/*! DMA_TX_En - DMA_TX_En */
#define SPDIF_SCR_DMA_TX_En(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_DMA_TX_En_SHIFT)) & SPDIF_SCR_DMA_TX_En_MASK)

#define SPDIF_SCR_DMA_Rx_En_MASK                 (0x200U)
#define SPDIF_SCR_DMA_Rx_En_SHIFT                (9U)
/*! DMA_Rx_En - DMA_Rx_En */
#define SPDIF_SCR_DMA_Rx_En(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_DMA_Rx_En_SHIFT)) & SPDIF_SCR_DMA_Rx_En_MASK)

#define SPDIF_SCR_TxFIFO_Ctrl_MASK               (0xC00U)
#define SPDIF_SCR_TxFIFO_Ctrl_SHIFT              (10U)
/*! TxFIFO_Ctrl - TxFIFO_Ctrl
 *  0b00..Send out digital zero on SPDIF Tx
 *  0b01..Tx Normal operation
 *  0b10..Reset to 1 sample remaining
 *  0b11..Reserved
 */
#define SPDIF_SCR_TxFIFO_Ctrl(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TxFIFO_Ctrl_SHIFT)) & SPDIF_SCR_TxFIFO_Ctrl_MASK)

#define SPDIF_SCR_soft_reset_MASK                (0x1000U)
#define SPDIF_SCR_soft_reset_SHIFT               (12U)
/*! soft_reset - soft_reset */
#define SPDIF_SCR_soft_reset(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_soft_reset_SHIFT)) & SPDIF_SCR_soft_reset_MASK)

#define SPDIF_SCR_LOW_POWER_MASK                 (0x2000U)
#define SPDIF_SCR_LOW_POWER_SHIFT                (13U)
/*! LOW_POWER - LOW_POWER */
#define SPDIF_SCR_LOW_POWER(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_LOW_POWER_SHIFT)) & SPDIF_SCR_LOW_POWER_MASK)

#define SPDIF_SCR_RAW_CAPTURE_MODE_MASK          (0x4000U)
#define SPDIF_SCR_RAW_CAPTURE_MODE_SHIFT         (14U)
/*! RAW_CAPTURE_MODE - RAW_CAPTURE_MODE */
#define SPDIF_SCR_RAW_CAPTURE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RAW_CAPTURE_MODE_SHIFT)) & SPDIF_SCR_RAW_CAPTURE_MODE_MASK)

#define SPDIF_SCR_TxFIFOEmpty_Sel_MASK           (0x18000U)
#define SPDIF_SCR_TxFIFOEmpty_Sel_SHIFT          (15U)
/*! TxFIFOEmpty_Sel - TxFIFOEmpty_Sel
 *  0b00..Empty interrupt if 0 sample in Tx left and right FIFOs
 *  0b01..Empty interrupt if at most 4 sample in Tx left and right FIFOs
 *  0b10..Empty interrupt if at most 8 sample in Tx left and right FIFOs
 *  0b11..Empty interrupt if at most 12 sample in Tx left and right FIFOs
 */
#define SPDIF_SCR_TxFIFOEmpty_Sel(x)             (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TxFIFOEmpty_Sel_SHIFT)) & SPDIF_SCR_TxFIFOEmpty_Sel_MASK)

#define SPDIF_SCR_TxAutoSync_MASK                (0x20000U)
#define SPDIF_SCR_TxAutoSync_SHIFT               (17U)
/*! TxAutoSync - TxAutoSync
 *  0b0..Tx FIFO auto sync off
 *  0b1..Tx FIFO auto sync on
 */
#define SPDIF_SCR_TxAutoSync(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_TxAutoSync_SHIFT)) & SPDIF_SCR_TxAutoSync_MASK)

#define SPDIF_SCR_RxAutoSync_MASK                (0x40000U)
#define SPDIF_SCR_RxAutoSync_SHIFT               (18U)
/*! RxAutoSync - RxAutoSync
 *  0b0..Rx FIFO auto sync off
 *  0b1..RxFIFO auto sync on
 */
#define SPDIF_SCR_RxAutoSync(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RxAutoSync_SHIFT)) & SPDIF_SCR_RxAutoSync_MASK)

#define SPDIF_SCR_RxFIFOFull_Sel_MASK            (0x180000U)
#define SPDIF_SCR_RxFIFOFull_Sel_SHIFT           (19U)
/*! RxFIFOFull_Sel - RxFIFOFull_Sel
 *  0b00..Full interrupt if at least 1 sample in Rx left and right FIFOs
 *  0b01..Full interrupt if at least 4 sample in Rx left and right FIFOs
 *  0b10..Full interrupt if at least 8 sample in Rx left and right FIFOs
 *  0b11..Full interrupt if at least 16 sample in Rx left and right FIFO
 */
#define SPDIF_SCR_RxFIFOFull_Sel(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RxFIFOFull_Sel_SHIFT)) & SPDIF_SCR_RxFIFOFull_Sel_MASK)

#define SPDIF_SCR_RxFIFO_Rst_MASK                (0x200000U)
#define SPDIF_SCR_RxFIFO_Rst_SHIFT               (21U)
/*! RxFIFO_Rst - RxFIFO_Rst
 *  0b0..Normal operation
 *  0b1..Reset register to 1 sample remaining
 */
#define SPDIF_SCR_RxFIFO_Rst(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RxFIFO_Rst_SHIFT)) & SPDIF_SCR_RxFIFO_Rst_MASK)

#define SPDIF_SCR_RxFIFO_Off_On_MASK             (0x400000U)
#define SPDIF_SCR_RxFIFO_Off_On_SHIFT            (22U)
/*! RxFIFO_Off_On - RxFIFO_Off_On
 *  0b0..SPDIF Rx FIFO is on
 *  0b1..SPDIF Rx FIFO is off. Does not accept data from interface
 */
#define SPDIF_SCR_RxFIFO_Off_On(x)               (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RxFIFO_Off_On_SHIFT)) & SPDIF_SCR_RxFIFO_Off_On_MASK)

#define SPDIF_SCR_RxFIFO_Ctrl_MASK               (0x800000U)
#define SPDIF_SCR_RxFIFO_Ctrl_SHIFT              (23U)
/*! RxFIFO_Ctrl - RxFIFO_Ctrl
 *  0b0..Normal operation
 *  0b1..Always read zero from Rx data register
 */
#define SPDIF_SCR_RxFIFO_Ctrl(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SCR_RxFIFO_Ctrl_SHIFT)) & SPDIF_SCR_RxFIFO_Ctrl_MASK)
/*! @} */

/*! @name SRCD - CDText Control Register */
/*! @{ */

#define SPDIF_SRCD_USyncMode_MASK                (0x2U)
#define SPDIF_SRCD_USyncMode_SHIFT               (1U)
/*! USyncMode - USyncMode
 *  0b0..Non-CD data
 *  0b1..CD user channel subcode
 */
#define SPDIF_SRCD_USyncMode(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCD_USyncMode_SHIFT)) & SPDIF_SRCD_USyncMode_MASK)
/*! @} */

/*! @name SRPC - PhaseConfig Register */
/*! @{ */

#define SPDIF_SRPC_GainSel_MASK                  (0x38U)
#define SPDIF_SRPC_GainSel_SHIFT                 (3U)
/*! GainSel - GainSel
 *  0b000..24*(2**10)
 *  0b001..16*(2**10)
 *  0b010..12*(2**10)
 *  0b011..8*(2**10)
 *  0b100..6*(2**10)
 *  0b101..4*(2**10)
 *  0b110..3*(2**10)
 */
#define SPDIF_SRPC_GainSel(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_GainSel_SHIFT)) & SPDIF_SRPC_GainSel_MASK)

#define SPDIF_SRPC_LOCK_MASK                     (0x40U)
#define SPDIF_SRPC_LOCK_SHIFT                    (6U)
/*! LOCK - LOCK */
#define SPDIF_SRPC_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_LOCK_SHIFT)) & SPDIF_SRPC_LOCK_MASK)

#define SPDIF_SRPC_ClkSrc_Sel_MASK               (0x780U)
#define SPDIF_SRPC_ClkSrc_Sel_SHIFT              (7U)
/*! ClkSrc_Sel - ClkSrc_Sel
 *  0b0000..Clock Selection from Audio Clock Mux (ACM)
 */
#define SPDIF_SRPC_ClkSrc_Sel(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SRPC_ClkSrc_Sel_SHIFT)) & SPDIF_SRPC_ClkSrc_Sel_MASK)
/*! @} */

/*! @name SIE - InterruptEn Register */
/*! @{ */

#define SPDIF_SIE_RxFIFOFul_MASK                 (0x1U)
#define SPDIF_SIE_RxFIFOFul_SHIFT                (0U)
/*! RxFIFOFul - RxFIFOFul */
#define SPDIF_SIE_RxFIFOFul(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RxFIFOFul_SHIFT)) & SPDIF_SIE_RxFIFOFul_MASK)

#define SPDIF_SIE_TxEm_MASK                      (0x2U)
#define SPDIF_SIE_TxEm_SHIFT                     (1U)
/*! TxEm - TxEm */
#define SPDIF_SIE_TxEm(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TxEm_SHIFT)) & SPDIF_SIE_TxEm_MASK)

#define SPDIF_SIE_LockLoss_MASK                  (0x4U)
#define SPDIF_SIE_LockLoss_SHIFT                 (2U)
/*! LockLoss - LockLoss */
#define SPDIF_SIE_LockLoss(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_LockLoss_SHIFT)) & SPDIF_SIE_LockLoss_MASK)

#define SPDIF_SIE_RxFIFOResyn_MASK               (0x8U)
#define SPDIF_SIE_RxFIFOResyn_SHIFT              (3U)
/*! RxFIFOResyn - RxFIFOResyn */
#define SPDIF_SIE_RxFIFOResyn(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RxFIFOResyn_SHIFT)) & SPDIF_SIE_RxFIFOResyn_MASK)

#define SPDIF_SIE_RxFIFOUnOv_MASK                (0x10U)
#define SPDIF_SIE_RxFIFOUnOv_SHIFT               (4U)
/*! RxFIFOUnOv - RxFIFOUnOv */
#define SPDIF_SIE_RxFIFOUnOv(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_RxFIFOUnOv_SHIFT)) & SPDIF_SIE_RxFIFOUnOv_MASK)

#define SPDIF_SIE_UQErr_MASK                     (0x20U)
#define SPDIF_SIE_UQErr_SHIFT                    (5U)
/*! UQErr - UQErr */
#define SPDIF_SIE_UQErr(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_UQErr_SHIFT)) & SPDIF_SIE_UQErr_MASK)

#define SPDIF_SIE_UQSync_MASK                    (0x40U)
#define SPDIF_SIE_UQSync_SHIFT                   (6U)
/*! UQSync - UQSync */
#define SPDIF_SIE_UQSync(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_UQSync_SHIFT)) & SPDIF_SIE_UQSync_MASK)

#define SPDIF_SIE_QRxOv_MASK                     (0x80U)
#define SPDIF_SIE_QRxOv_SHIFT                    (7U)
/*! QRxOv - QRxOv */
#define SPDIF_SIE_QRxOv(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_QRxOv_SHIFT)) & SPDIF_SIE_QRxOv_MASK)

#define SPDIF_SIE_QRxFul_MASK                    (0x100U)
#define SPDIF_SIE_QRxFul_SHIFT                   (8U)
/*! QRxFul - QRxFul */
#define SPDIF_SIE_QRxFul(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_QRxFul_SHIFT)) & SPDIF_SIE_QRxFul_MASK)

#define SPDIF_SIE_URxOv_MASK                     (0x200U)
#define SPDIF_SIE_URxOv_SHIFT                    (9U)
/*! URxOv - URxOv */
#define SPDIF_SIE_URxOv(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_URxOv_SHIFT)) & SPDIF_SIE_URxOv_MASK)

#define SPDIF_SIE_URxFul_MASK                    (0x400U)
#define SPDIF_SIE_URxFul_SHIFT                   (10U)
/*! URxFul - URxFul */
#define SPDIF_SIE_URxFul(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_URxFul_SHIFT)) & SPDIF_SIE_URxFul_MASK)

#define SPDIF_SIE_BitErr_MASK                    (0x4000U)
#define SPDIF_SIE_BitErr_SHIFT                   (14U)
/*! BitErr - BitErr */
#define SPDIF_SIE_BitErr(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_BitErr_SHIFT)) & SPDIF_SIE_BitErr_MASK)

#define SPDIF_SIE_SymErr_MASK                    (0x8000U)
#define SPDIF_SIE_SymErr_SHIFT                   (15U)
/*! SymErr - SymErr */
#define SPDIF_SIE_SymErr(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_SymErr_SHIFT)) & SPDIF_SIE_SymErr_MASK)

#define SPDIF_SIE_ValNoGood_MASK                 (0x10000U)
#define SPDIF_SIE_ValNoGood_SHIFT                (16U)
/*! ValNoGood - ValNoGood */
#define SPDIF_SIE_ValNoGood(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_ValNoGood_SHIFT)) & SPDIF_SIE_ValNoGood_MASK)

#define SPDIF_SIE_CNew_MASK                      (0x20000U)
#define SPDIF_SIE_CNew_SHIFT                     (17U)
/*! CNew - CNew */
#define SPDIF_SIE_CNew(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_CNew_SHIFT)) & SPDIF_SIE_CNew_MASK)

#define SPDIF_SIE_TxResyn_MASK                   (0x40000U)
#define SPDIF_SIE_TxResyn_SHIFT                  (18U)
/*! TxResyn - TxResyn */
#define SPDIF_SIE_TxResyn(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TxResyn_SHIFT)) & SPDIF_SIE_TxResyn_MASK)

#define SPDIF_SIE_TxUnOv_MASK                    (0x80000U)
#define SPDIF_SIE_TxUnOv_SHIFT                   (19U)
/*! TxUnOv - TxUnOv */
#define SPDIF_SIE_TxUnOv(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_TxUnOv_SHIFT)) & SPDIF_SIE_TxUnOv_MASK)

#define SPDIF_SIE_Lock_MASK                      (0x100000U)
#define SPDIF_SIE_Lock_SHIFT                     (20U)
/*! Lock - Lock */
#define SPDIF_SIE_Lock(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIE_Lock_SHIFT)) & SPDIF_SIE_Lock_MASK)
/*! @} */

/*! @name SIC - InterruptClear Register */
/*! @{ */

#define SPDIF_SIC_LockLoss_MASK                  (0x4U)
#define SPDIF_SIC_LockLoss_SHIFT                 (2U)
/*! LockLoss - LockLoss */
#define SPDIF_SIC_LockLoss(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_LockLoss_SHIFT)) & SPDIF_SIC_LockLoss_MASK)

#define SPDIF_SIC_RxFIFOResyn_MASK               (0x8U)
#define SPDIF_SIC_RxFIFOResyn_SHIFT              (3U)
/*! RxFIFOResyn - RxFIFOResyn */
#define SPDIF_SIC_RxFIFOResyn(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_RxFIFOResyn_SHIFT)) & SPDIF_SIC_RxFIFOResyn_MASK)

#define SPDIF_SIC_RxFIFOUnOv_MASK                (0x10U)
#define SPDIF_SIC_RxFIFOUnOv_SHIFT               (4U)
/*! RxFIFOUnOv - RxFIFOUnOv */
#define SPDIF_SIC_RxFIFOUnOv(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_RxFIFOUnOv_SHIFT)) & SPDIF_SIC_RxFIFOUnOv_MASK)

#define SPDIF_SIC_UQErr_MASK                     (0x20U)
#define SPDIF_SIC_UQErr_SHIFT                    (5U)
/*! UQErr - UQErr */
#define SPDIF_SIC_UQErr(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_UQErr_SHIFT)) & SPDIF_SIC_UQErr_MASK)

#define SPDIF_SIC_UQSync_MASK                    (0x40U)
#define SPDIF_SIC_UQSync_SHIFT                   (6U)
/*! UQSync - UQSync */
#define SPDIF_SIC_UQSync(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_UQSync_SHIFT)) & SPDIF_SIC_UQSync_MASK)

#define SPDIF_SIC_QRxOv_MASK                     (0x80U)
#define SPDIF_SIC_QRxOv_SHIFT                    (7U)
/*! QRxOv - QRxOv */
#define SPDIF_SIC_QRxOv(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_QRxOv_SHIFT)) & SPDIF_SIC_QRxOv_MASK)

#define SPDIF_SIC_URxOv_MASK                     (0x200U)
#define SPDIF_SIC_URxOv_SHIFT                    (9U)
/*! URxOv - URxOv */
#define SPDIF_SIC_URxOv(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_URxOv_SHIFT)) & SPDIF_SIC_URxOv_MASK)

#define SPDIF_SIC_BitErr_MASK                    (0x4000U)
#define SPDIF_SIC_BitErr_SHIFT                   (14U)
/*! BitErr - BitErr */
#define SPDIF_SIC_BitErr(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_BitErr_SHIFT)) & SPDIF_SIC_BitErr_MASK)

#define SPDIF_SIC_SymErr_MASK                    (0x8000U)
#define SPDIF_SIC_SymErr_SHIFT                   (15U)
/*! SymErr - SymErr */
#define SPDIF_SIC_SymErr(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_SymErr_SHIFT)) & SPDIF_SIC_SymErr_MASK)

#define SPDIF_SIC_ValNoGood_MASK                 (0x10000U)
#define SPDIF_SIC_ValNoGood_SHIFT                (16U)
/*! ValNoGood - ValNoGood */
#define SPDIF_SIC_ValNoGood(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_ValNoGood_SHIFT)) & SPDIF_SIC_ValNoGood_MASK)

#define SPDIF_SIC_CNew_MASK                      (0x20000U)
#define SPDIF_SIC_CNew_SHIFT                     (17U)
/*! CNew - CNew */
#define SPDIF_SIC_CNew(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_CNew_SHIFT)) & SPDIF_SIC_CNew_MASK)

#define SPDIF_SIC_TxResyn_MASK                   (0x40000U)
#define SPDIF_SIC_TxResyn_SHIFT                  (18U)
/*! TxResyn - TxResyn */
#define SPDIF_SIC_TxResyn(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_TxResyn_SHIFT)) & SPDIF_SIC_TxResyn_MASK)

#define SPDIF_SIC_TxUnOv_MASK                    (0x80000U)
#define SPDIF_SIC_TxUnOv_SHIFT                   (19U)
/*! TxUnOv - TxUnOv */
#define SPDIF_SIC_TxUnOv(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_TxUnOv_SHIFT)) & SPDIF_SIC_TxUnOv_MASK)

#define SPDIF_SIC_Lock_MASK                      (0x100000U)
#define SPDIF_SIC_Lock_SHIFT                     (20U)
/*! Lock - Lock */
#define SPDIF_SIC_Lock(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIC_Lock_SHIFT)) & SPDIF_SIC_Lock_MASK)
/*! @} */

/*! @name SIS - InterruptStat Register */
/*! @{ */

#define SPDIF_SIS_RxFIFOFul_MASK                 (0x1U)
#define SPDIF_SIS_RxFIFOFul_SHIFT                (0U)
/*! RxFIFOFul - RxFIFOFul */
#define SPDIF_SIS_RxFIFOFul(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RxFIFOFul_SHIFT)) & SPDIF_SIS_RxFIFOFul_MASK)

#define SPDIF_SIS_TxEm_MASK                      (0x2U)
#define SPDIF_SIS_TxEm_SHIFT                     (1U)
/*! TxEm - TxEm */
#define SPDIF_SIS_TxEm(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TxEm_SHIFT)) & SPDIF_SIS_TxEm_MASK)

#define SPDIF_SIS_LockLoss_MASK                  (0x4U)
#define SPDIF_SIS_LockLoss_SHIFT                 (2U)
/*! LockLoss - LockLoss */
#define SPDIF_SIS_LockLoss(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_LockLoss_SHIFT)) & SPDIF_SIS_LockLoss_MASK)

#define SPDIF_SIS_RxFIFOResyn_MASK               (0x8U)
#define SPDIF_SIS_RxFIFOResyn_SHIFT              (3U)
/*! RxFIFOResyn - RxFIFOResyn */
#define SPDIF_SIS_RxFIFOResyn(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RxFIFOResyn_SHIFT)) & SPDIF_SIS_RxFIFOResyn_MASK)

#define SPDIF_SIS_RxFIFOUnOv_MASK                (0x10U)
#define SPDIF_SIS_RxFIFOUnOv_SHIFT               (4U)
/*! RxFIFOUnOv - RxFIFOUnOv */
#define SPDIF_SIS_RxFIFOUnOv(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_RxFIFOUnOv_SHIFT)) & SPDIF_SIS_RxFIFOUnOv_MASK)

#define SPDIF_SIS_UQErr_MASK                     (0x20U)
#define SPDIF_SIS_UQErr_SHIFT                    (5U)
/*! UQErr - UQErr */
#define SPDIF_SIS_UQErr(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_UQErr_SHIFT)) & SPDIF_SIS_UQErr_MASK)

#define SPDIF_SIS_UQSync_MASK                    (0x40U)
#define SPDIF_SIS_UQSync_SHIFT                   (6U)
/*! UQSync - UQSync */
#define SPDIF_SIS_UQSync(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_UQSync_SHIFT)) & SPDIF_SIS_UQSync_MASK)

#define SPDIF_SIS_QRxOv_MASK                     (0x80U)
#define SPDIF_SIS_QRxOv_SHIFT                    (7U)
/*! QRxOv - QRxOv */
#define SPDIF_SIS_QRxOv(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_QRxOv_SHIFT)) & SPDIF_SIS_QRxOv_MASK)

#define SPDIF_SIS_QRxFul_MASK                    (0x100U)
#define SPDIF_SIS_QRxFul_SHIFT                   (8U)
/*! QRxFul - QRxFul */
#define SPDIF_SIS_QRxFul(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_QRxFul_SHIFT)) & SPDIF_SIS_QRxFul_MASK)

#define SPDIF_SIS_URxOv_MASK                     (0x200U)
#define SPDIF_SIS_URxOv_SHIFT                    (9U)
/*! URxOv - URxOv */
#define SPDIF_SIS_URxOv(x)                       (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_URxOv_SHIFT)) & SPDIF_SIS_URxOv_MASK)

#define SPDIF_SIS_URxFul_MASK                    (0x400U)
#define SPDIF_SIS_URxFul_SHIFT                   (10U)
/*! URxFul - URxFul */
#define SPDIF_SIS_URxFul(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_URxFul_SHIFT)) & SPDIF_SIS_URxFul_MASK)

#define SPDIF_SIS_BitErr_MASK                    (0x4000U)
#define SPDIF_SIS_BitErr_SHIFT                   (14U)
/*! BitErr - BitErr */
#define SPDIF_SIS_BitErr(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_BitErr_SHIFT)) & SPDIF_SIS_BitErr_MASK)

#define SPDIF_SIS_SymErr_MASK                    (0x8000U)
#define SPDIF_SIS_SymErr_SHIFT                   (15U)
/*! SymErr - SymErr */
#define SPDIF_SIS_SymErr(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_SymErr_SHIFT)) & SPDIF_SIS_SymErr_MASK)

#define SPDIF_SIS_ValNoGood_MASK                 (0x10000U)
#define SPDIF_SIS_ValNoGood_SHIFT                (16U)
/*! ValNoGood - ValNoGood */
#define SPDIF_SIS_ValNoGood(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_ValNoGood_SHIFT)) & SPDIF_SIS_ValNoGood_MASK)

#define SPDIF_SIS_CNew_MASK                      (0x20000U)
#define SPDIF_SIS_CNew_SHIFT                     (17U)
/*! CNew - CNew */
#define SPDIF_SIS_CNew(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_CNew_SHIFT)) & SPDIF_SIS_CNew_MASK)

#define SPDIF_SIS_TxResyn_MASK                   (0x40000U)
#define SPDIF_SIS_TxResyn_SHIFT                  (18U)
/*! TxResyn - TxResyn */
#define SPDIF_SIS_TxResyn(x)                     (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TxResyn_SHIFT)) & SPDIF_SIS_TxResyn_MASK)

#define SPDIF_SIS_TxUnOv_MASK                    (0x80000U)
#define SPDIF_SIS_TxUnOv_SHIFT                   (19U)
/*! TxUnOv - TxUnOv */
#define SPDIF_SIS_TxUnOv(x)                      (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_TxUnOv_SHIFT)) & SPDIF_SIS_TxUnOv_MASK)

#define SPDIF_SIS_Lock_MASK                      (0x100000U)
#define SPDIF_SIS_Lock_SHIFT                     (20U)
/*! Lock - Lock */
#define SPDIF_SIS_Lock(x)                        (((uint32_t)(((uint32_t)(x)) << SPDIF_SIS_Lock_SHIFT)) & SPDIF_SIS_Lock_MASK)
/*! @} */

/*! @name SRL - SPDIFRxLeft Register */
/*! @{ */

#define SPDIF_SRL_RxDataLeft_MASK                (0xFFFFFFU)
#define SPDIF_SRL_RxDataLeft_SHIFT               (0U)
/*! RxDataLeft - RxDataLeft */
#define SPDIF_SRL_RxDataLeft(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRL_RxDataLeft_SHIFT)) & SPDIF_SRL_RxDataLeft_MASK)
/*! @} */

/*! @name SRR - SPDIFRxRight Register */
/*! @{ */

#define SPDIF_SRR_RxDataRight_MASK               (0xFFFFFFU)
#define SPDIF_SRR_RxDataRight_SHIFT              (0U)
/*! RxDataRight - RxDataRight */
#define SPDIF_SRR_RxDataRight(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_SRR_RxDataRight_SHIFT)) & SPDIF_SRR_RxDataRight_MASK)
/*! @} */

/*! @name SRCSH - SPDIFRxCChannel_h Register */
/*! @{ */

#define SPDIF_SRCSH_RxCChannel_h_MASK            (0xFFFFFFU)
#define SPDIF_SRCSH_RxCChannel_h_SHIFT           (0U)
/*! RxCChannel_h - RxCChannel_h */
#define SPDIF_SRCSH_RxCChannel_h(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCSH_RxCChannel_h_SHIFT)) & SPDIF_SRCSH_RxCChannel_h_MASK)
/*! @} */

/*! @name SRCSL - SPDIFRxCChannel_l Register */
/*! @{ */

#define SPDIF_SRCSL_RxCChannel_l_MASK            (0xFFFFFFU)
#define SPDIF_SRCSL_RxCChannel_l_SHIFT           (0U)
/*! RxCChannel_l - RxCChannel_l */
#define SPDIF_SRCSL_RxCChannel_l(x)              (((uint32_t)(((uint32_t)(x)) << SPDIF_SRCSL_RxCChannel_l_SHIFT)) & SPDIF_SRCSL_RxCChannel_l_MASK)
/*! @} */

/*! @name SRU - UchannelRx Register */
/*! @{ */

#define SPDIF_SRU_RxUChannel_MASK                (0xFFFFFFU)
#define SPDIF_SRU_RxUChannel_SHIFT               (0U)
/*! RxUChannel - RxUChannel */
#define SPDIF_SRU_RxUChannel(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRU_RxUChannel_SHIFT)) & SPDIF_SRU_RxUChannel_MASK)
/*! @} */

/*! @name SRQ - QchannelRx Register */
/*! @{ */

#define SPDIF_SRQ_RxQChannel_MASK                (0xFFFFFFU)
#define SPDIF_SRQ_RxQChannel_SHIFT               (0U)
/*! RxQChannel - RxQChannel */
#define SPDIF_SRQ_RxQChannel(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_SRQ_RxQChannel_SHIFT)) & SPDIF_SRQ_RxQChannel_MASK)
/*! @} */

/*! @name STL - SPDIFTxLeft Register */
/*! @{ */

#define SPDIF_STL_TxDataLeft_MASK                (0xFFFFFFU)
#define SPDIF_STL_TxDataLeft_SHIFT               (0U)
/*! TxDataLeft - TxDataLeft */
#define SPDIF_STL_TxDataLeft(x)                  (((uint32_t)(((uint32_t)(x)) << SPDIF_STL_TxDataLeft_SHIFT)) & SPDIF_STL_TxDataLeft_MASK)
/*! @} */

/*! @name STR - SPDIFTxRight Register */
/*! @{ */

#define SPDIF_STR_TxDataRight_MASK               (0xFFFFFFU)
#define SPDIF_STR_TxDataRight_SHIFT              (0U)
/*! TxDataRight - TxDataRight */
#define SPDIF_STR_TxDataRight(x)                 (((uint32_t)(((uint32_t)(x)) << SPDIF_STR_TxDataRight_SHIFT)) & SPDIF_STR_TxDataRight_MASK)
/*! @} */

/*! @name STCSCH - SPDIFTxCChannelCons_h Register */
/*! @{ */

#define SPDIF_STCSCH_TxCChannelCons_h_MASK       (0xFFFFFFU)
#define SPDIF_STCSCH_TxCChannelCons_h_SHIFT      (0U)
/*! TxCChannelCons_h - TxCChannelCons_h */
#define SPDIF_STCSCH_TxCChannelCons_h(x)         (((uint32_t)(((uint32_t)(x)) << SPDIF_STCSCH_TxCChannelCons_h_SHIFT)) & SPDIF_STCSCH_TxCChannelCons_h_MASK)
/*! @} */

/*! @name STCSCL - SPDIFTxCChannelCons_l Register */
/*! @{ */

#define SPDIF_STCSCL_TxCChannelCons_l_MASK       (0xFFFFFFU)
#define SPDIF_STCSCL_TxCChannelCons_l_SHIFT      (0U)
/*! TxCChannelCons_l - TxCChannelCons_l */
#define SPDIF_STCSCL_TxCChannelCons_l(x)         (((uint32_t)(((uint32_t)(x)) << SPDIF_STCSCL_TxCChannelCons_l_SHIFT)) & SPDIF_STCSCL_TxCChannelCons_l_MASK)
/*! @} */

/*! @name SRFM - FreqMeas Register */
/*! @{ */

#define SPDIF_SRFM_FreqMeas_MASK                 (0xFFFFFFU)
#define SPDIF_SRFM_FreqMeas_SHIFT                (0U)
/*! FreqMeas - FreqMeas */
#define SPDIF_SRFM_FreqMeas(x)                   (((uint32_t)(((uint32_t)(x)) << SPDIF_SRFM_FreqMeas_SHIFT)) & SPDIF_SRFM_FreqMeas_MASK)
/*! @} */

/*! @name STC - SPDIFTxClk Register */
/*! @{ */

#define SPDIF_STC_TxClk_DF_MASK                  (0x7FU)
#define SPDIF_STC_TxClk_DF_SHIFT                 (0U)
/*! TxClk_DF - TxClk_DF
 *  0b0000000..divider factor is 1
 *  0b0000001..divider factor is 2
 *  0b1111111..divider factor is 128
 */
#define SPDIF_STC_TxClk_DF(x)                    (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TxClk_DF_SHIFT)) & SPDIF_STC_TxClk_DF_MASK)

#define SPDIF_STC_tx_all_clk_en_MASK             (0x80U)
#define SPDIF_STC_tx_all_clk_en_SHIFT            (7U)
/*! tx_all_clk_en - tx_all_clk_en
 *  0b0..disable transfer clock.
 *  0b1..enable transfer clock.
 */
#define SPDIF_STC_tx_all_clk_en(x)               (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_tx_all_clk_en_SHIFT)) & SPDIF_STC_tx_all_clk_en_MASK)

#define SPDIF_STC_TxClk_Source_MASK              (0x700U)
#define SPDIF_STC_TxClk_Source_SHIFT             (8U)
/*! TxClk_Source - TxClk_Source
 *  0b000..Clock Selection from Audio Clock Mux (ACM)
 */
#define SPDIF_STC_TxClk_Source(x)                (((uint32_t)(((uint32_t)(x)) << SPDIF_STC_TxClk_Source_SHIFT)) & SPDIF_STC_TxClk_Source_MASK)

#define SPDIF_STC_SYSCLK_DF_MASK                 (0xFF800U)
#define SPDIF_STC_SYSCLK_DF_SHIFT                (11U)
/*! SYSCLK_DF - SYSCLK_DF
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


#endif  /* PERI_SPDIF_H_ */

