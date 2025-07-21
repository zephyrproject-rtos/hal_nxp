/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EARC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_EARC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EARC
 *
 * CMSIS Peripheral Access Layer for EARC
 */

#if !defined(PERI_EARC_H_)
#define PERI_EARC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- EARC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EARC_Peripheral_Access_Layer EARC Peripheral Access Layer
 * @{
 */

/** EARC - Size of Registers Arrays */
#define EARC_RX_CS_DATA_BITS_COUNT                6u
#define EARC_RX_USER_DATA_BITS_COUNT              6u
#define EARC_TX_CS_DATA_BITS_COUNT                6u
#define EARC_TX_USER_DATA_BITS_COUNT              6u

/** EARC - Register Layout Typedef */
typedef struct {
  __IO uint32_t VERSION;                           /**< Version control register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< External control register, offset: 0x10 */
    __IO uint32_t SET;                               /**< External control register, offset: 0x14 */
    __IO uint32_t CLR;                               /**< External control register, offset: 0x18 */
    __IO uint32_t TOG;                               /**< External control register, offset: 0x1C */
  } EXT_CTRL;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< External Status register, offset: 0x20 */
    __IO uint32_t SET;                               /**< External Status register, offset: 0x24 */
    __IO uint32_t CLR;                               /**< External Status register, offset: 0x28 */
    __IO uint32_t TOG;                               /**< External Status register, offset: 0x2C */
  } EXT_STATUS;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Interrupt enables for interrupt 0, offset: 0x30 */
    __IO uint32_t SET;                               /**< Interrupt enables for interrupt 0, offset: 0x34 */
    __IO uint32_t CLR;                               /**< Interrupt enables for interrupt 0, offset: 0x38 */
    __IO uint32_t TOG;                               /**< Interrupt enables for interrupt 0, offset: 0x3C */
  } EXT_IER0;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< Interrupt enables for interrupt 1, offset: 0x40 */
    __IO uint32_t SET;                               /**< Interrupt enables for interrupt 1, offset: 0x44 */
    __IO uint32_t CLR;                               /**< Interrupt enables for interrupt 1, offset: 0x48 */
    __IO uint32_t TOG;                               /**< Interrupt enables for interrupt 1, offset: 0x4C */
  } EXT_IER1;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< External Interrupt Status register, offset: 0x50 */
    __IO uint32_t SET;                               /**< External Interrupt Status register, offset: 0x54 */
    __IO uint32_t CLR;                               /**< External Interrupt Status register, offset: 0x58 */
    __IO uint32_t TOG;                               /**< External Interrupt Status register, offset: 0x5C */
  } EXT_ISR;
       uint8_t RESERVED_1[16];
  struct {                                         /* offset: 0x70 */
    __IO uint32_t RW;                                /**< Interrupt enable register for M0+, offset: 0x70 */
    __IO uint32_t SET;                               /**< Interrupt enable register for M0+, offset: 0x74 */
    __IO uint32_t CLR;                               /**< Interrupt enable register for M0+, offset: 0x78 */
    __IO uint32_t TOG;                               /**< Interrupt enable register for M0+, offset: 0x7C */
  } IER;
  struct {                                         /* offset: 0x80 */
    __IO uint32_t RW;                                /**< Interrupt status register, offset: 0x80 */
    __IO uint32_t SET;                               /**< Interrupt status register, offset: 0x84 */
    __IO uint32_t CLR;                               /**< Interrupt status register, offset: 0x88 */
    __IO uint32_t TOG;                               /**< Interrupt status register, offset: 0x8C */
  } ISR;
  struct {                                         /* offset: 0x90 */
    __IO uint32_t RW;                                /**< AI interface control register, offset: 0x90 */
    __IO uint32_t SET;                               /**< AI interface control register, offset: 0x94 */
    __IO uint32_t CLR;                               /**< AI interface control register, offset: 0x98 */
    __IO uint32_t TOG;                               /**< AI interface control register, offset: 0x9C */
  } PHY_AI_CTRL;
  __IO uint32_t PHY_AI_WDATA;                      /**< AI interface WDATA register, offset: 0xA0 */
  __I  uint32_t PHY_AI_RDATA;                      /**< AI interface RDATA register, offset: 0xA4 */
  __I  uint32_t DPATH_STATUS;                      /**< Audio XCVR datapath status, offset: 0xA8 */
       uint8_t RESERVED_2[20];
  struct {                                         /* offset: 0xC0 */
    __IO uint32_t RW;                                /**< CMDC receiver control register, offset: 0xC0 */
    __IO uint32_t SET;                               /**< CMDC receiver control register, offset: 0xC4 */
    __IO uint32_t CLR;                               /**< CMDC receiver control register, offset: 0xC8 */
    __IO uint32_t TOG;                               /**< CMDC receiver control register, offset: 0xCC */
  } RX_CMDC_CTRL;
  __I  uint32_t RX_CMDC_STATUS;                    /**< eARC receiver CMDC status, offset: 0xD0 */
       uint8_t RESERVED_3[12];
  __IO uint32_t RX_CMDC_TX_DATA;                   /**< CMDC transmit data register, offset: 0xE0 */
       uint8_t RESERVED_4[12];
  __I  uint32_t RX_CMDC_RX_DATA;                   /**< CMDC receive data register, offset: 0xF0 */
       uint8_t RESERVED_5[140];
  struct {                                         /* offset: 0x180 */
    __IO uint32_t RW;                                /**< Data path control register, offset: 0x180 */
    __IO uint32_t SET;                               /**< Data path control register, offset: 0x184 */
    __IO uint32_t CLR;                               /**< Data path control register, offset: 0x188 */
    __IO uint32_t TOG;                               /**< Data path control register, offset: 0x18C */
  } RX_DATAPATH_CTRL;
  __I  uint32_t RX_CS_DATA_BITS[EARC_RX_CS_DATA_BITS_COUNT]; /**< Channel staus bits, array offset: 0x190, array step: 0x4 */
  __I  uint32_t RX_USER_DATA_BITS[EARC_RX_USER_DATA_BITS_COUNT]; /**< User data bits, array offset: 0x1A8, array step: 0x4 */
  struct {                                         /* offset: 0x1C0 */
    __IO uint32_t RW;                                /**< DMAC counter control register, offset: 0x1C0 */
    __IO uint32_t SET;                               /**< DMAC counter control register, offset: 0x1C4 */
    __IO uint32_t CLR;                               /**< DMAC counter control register, offset: 0x1C8 */
    __IO uint32_t TOG;                               /**< DMAC counter control register, offset: 0x1CC */
  } RX_DPATH_CNTR_CTRL;
  __I  uint32_t RX_DPATH_TSCR;                     /**< Receive Datapath Timestamp Counter Register, offset: 0x1D0 */
  __I  uint32_t RX_DPATH_BCR;                      /**< Receive Datapath Bit counter register, offset: 0x1D4 */
  __I  uint32_t RX_DPATH_BCTR;                     /**< Receive datapath Bit count timestamp register., offset: 0x1D8 */
  __I  uint32_t RX_DPATH_BCRR;                     /**< Receive datapath Bit read timestamp register., offset: 0x1DC */
  struct {                                         /* offset: 0x1E0 */
    __IO uint32_t RW;                                /**< Preamble match value register, offset: 0x1E0 */
    __IO uint32_t SET;                               /**< Preamble match value register, offset: 0x1E4 */
    __IO uint32_t CLR;                               /**< Preamble match value register, offset: 0x1E8 */
    __IO uint32_t TOG;                               /**< Preamble match value register, offset: 0x1EC */
  } DMAC_PRE_MATCH_VAL;
  struct {                                         /* offset: 0x1F0 */
    __IO uint32_t RW;                                /**< Preamble match value register, offset: 0x1F0 */
    __IO uint32_t SET;                               /**< Preamble match value register, offset: 0x1F4 */
    __IO uint32_t CLR;                               /**< Preamble match value register, offset: 0x1F8 */
    __IO uint32_t TOG;                               /**< Preamble match value register, offset: 0x1FC */
  } DMAC_DTS_PRE_MATCH_VAL;
  __IO uint32_t RX_DPATH_PRE_ERR;                  /**< Error count for IEC60958-1 Block Synchronization., offset: 0x200 */
  __IO uint32_t RX_DPATH_PARITY_ERR;               /**< Parity Error count for IEC60958-1 Blocks., offset: 0x204 */
       uint8_t RESERVED_6[8];
  __I  uint32_t RX_DPATH_PKT_CNT;                  /**< Receive Data packet count., offset: 0x210 */
  __I  uint32_t RX_DPATH_ONE_BIT_ERR_CNT;          /**< Receive Data packet Corrected error count., offset: 0x214 */
  __I  uint32_t DMAC_PRE_MATCH_OFFSET;             /**< Preamble match offset value register, offset: 0x218 */
       uint8_t RESERVED_7[4];
  struct {                                         /* offset: 0x220 */
    __IO uint32_t RW;                                /**< Transmit Data path control register, offset: 0x220 */
    __IO uint32_t SET;                               /**< Transmit Data path control register, offset: 0x224 */
    __IO uint32_t CLR;                               /**< Transmit Data path control register, offset: 0x228 */
    __IO uint32_t TOG;                               /**< Transmit Data path control register, offset: 0x22C */
  } TX_DATAPATH_CTRL;
  __IO uint32_t TX_CS_DATA_BITS[EARC_TX_CS_DATA_BITS_COUNT]; /**< Channel staus bits, array offset: 0x230, array step: 0x4 */
  __IO uint32_t TX_USER_DATA_BITS[EARC_TX_USER_DATA_BITS_COUNT]; /**< User data bits, array offset: 0x248, array step: 0x4 */
  struct {                                         /* offset: 0x260 */
    __IO uint32_t RW;                                /**< DMAC counter control register, offset: 0x260 */
    __IO uint32_t SET;                               /**< DMAC counter control register, offset: 0x264 */
    __IO uint32_t CLR;                               /**< DMAC counter control register, offset: 0x268 */
    __IO uint32_t TOG;                               /**< DMAC counter control register, offset: 0x26C */
  } TX_DPATH_CNTR_CTRL;
  __I  uint32_t TX_DPATH_TSCR;                     /**< Transmit Datapath Timestamp Counter Register, offset: 0x270 */
  __I  uint32_t TX_DPATH_BCR;                      /**< Transmit Datapath Bit counter register, offset: 0x274 */
  __I  uint32_t TX_DPATH_BCTR;                     /**< Transmit datapath Bit count timestamp register., offset: 0x278 */
  __I  uint32_t TX_DPATH_BCRR;                     /**< Transmmit datapath Bit read timestamp register., offset: 0x27C */
       uint8_t RESERVED_8[32];
  struct {                                         /* offset: 0x2A0 */
    __IO uint32_t RW;                                /**< HPD Debounce Control Register, offset: 0x2A0 */
    __IO uint32_t SET;                               /**< HPD Debounce Control Register, offset: 0x2A4 */
    __IO uint32_t CLR;                               /**< HPD Debounce Control Register, offset: 0x2A8 */
    __IO uint32_t TOG;                               /**< HPD Debounce Control Register, offset: 0x2AC */
  } HPD_DBNC_CTRL;
       uint8_t RESERVED_9[32];
  __IO uint32_t TEMPERATURE;                       /**< Chip Temperature for eARC PHY, offset: 0x2D0 */
} EARC_Type;

/* ----------------------------------------------------------------------------
   -- EARC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EARC_Register_Masks EARC Register Masks
 * @{
 */

/*! @name VERSION - Version control register */
/*! @{ */

#define EARC_VERSION_VERID_MASK                  (0xFFFFFFFFU)
#define EARC_VERSION_VERID_SHIFT                 (0U)
/*! VERID - Version ID */
#define EARC_VERSION_VERID(x)                    (((uint32_t)(((uint32_t)(x)) << EARC_VERSION_VERID_SHIFT)) & EARC_VERSION_VERID_MASK)
/*! @} */

/*! @name EXT_CTRL - External control register */
/*! @{ */

#define EARC_EXT_CTRL_TX_FIFO_WMARK_MASK         (0x7FU)
#define EARC_EXT_CTRL_TX_FIFO_WMARK_SHIFT        (0U)
/*! TX_FIFO_WMARK - Audio Transmit FIFO Watermark Level */
#define EARC_EXT_CTRL_TX_FIFO_WMARK(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_TX_FIFO_WMARK_SHIFT)) & EARC_EXT_CTRL_TX_FIFO_WMARK_MASK)

#define EARC_EXT_CTRL_RX_FIFO_WMARK_MASK         (0x7F00U)
#define EARC_EXT_CTRL_RX_FIFO_WMARK_SHIFT        (8U)
/*! RX_FIFO_WMARK - Audio Receive FIFO Watermark Level */
#define EARC_EXT_CTRL_RX_FIFO_WMARK(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_RX_FIFO_WMARK_SHIFT)) & EARC_EXT_CTRL_RX_FIFO_WMARK_MASK)

#define EARC_EXT_CTRL_FABRIC_RR_SEL_MASK         (0x8000U)
#define EARC_EXT_CTRL_FABRIC_RR_SEL_SHIFT        (15U)
/*! FABRIC_RR_SEL - Selects Arbitration mode of crossbar switch. */
#define EARC_EXT_CTRL_FABRIC_RR_SEL(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_FABRIC_RR_SEL_SHIFT)) & EARC_EXT_CTRL_FABRIC_RR_SEL_MASK)

#define EARC_EXT_CTRL_PAGE_MASK                  (0xF0000U)
#define EARC_EXT_CTRL_PAGE_SHIFT                 (16U)
/*! PAGE - Page Select. */
#define EARC_EXT_CTRL_PAGE(x)                    (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_PAGE_SHIFT)) & EARC_EXT_CTRL_PAGE_MASK)

#define EARC_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_MASK (0x200000U)
#define EARC_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_SHIFT (21U)
/*! CORE_SLEEP_HOLD_REQ_B - Hold core from going to sleep mode when 0. */
#define EARC_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B(x)   (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_SHIFT)) & EARC_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_MASK)

#define EARC_EXT_CTRL_CORE_WAIT_MASK             (0x400000U)
#define EARC_EXT_CTRL_CORE_WAIT_SHIFT            (22U)
/*! CORE_WAIT - Stop executing code */
#define EARC_EXT_CTRL_CORE_WAIT(x)               (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_CORE_WAIT_SHIFT)) & EARC_EXT_CTRL_CORE_WAIT_MASK)

#define EARC_EXT_CTRL_SPDIF_MODE_MASK            (0x800000U)
#define EARC_EXT_CTRL_SPDIF_MODE_SHIFT           (23U)
/*! SPDIF_MODE - Indicates SPDIF output mode. */
#define EARC_EXT_CTRL_SPDIF_MODE(x)              (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_SPDIF_MODE_SHIFT)) & EARC_EXT_CTRL_SPDIF_MODE_MASK)

#define EARC_EXT_CTRL_SDMA_WR_REQ_DIS_MASK       (0x1000000U)
#define EARC_EXT_CTRL_SDMA_WR_REQ_DIS_SHIFT      (24U)
/*! SDMA_WR_REQ_DIS - SDMA WR REQ disable */
#define EARC_EXT_CTRL_SDMA_WR_REQ_DIS(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_SDMA_WR_REQ_DIS_SHIFT)) & EARC_EXT_CTRL_SDMA_WR_REQ_DIS_MASK)

#define EARC_EXT_CTRL_SDMA_RD_REQ_DIS_MASK       (0x2000000U)
#define EARC_EXT_CTRL_SDMA_RD_REQ_DIS_SHIFT      (25U)
/*! SDMA_RD_REQ_DIS - SDMA RD REQ disable */
#define EARC_EXT_CTRL_SDMA_RD_REQ_DIS(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_SDMA_RD_REQ_DIS_SHIFT)) & EARC_EXT_CTRL_SDMA_RD_REQ_DIS_MASK)

#define EARC_EXT_CTRL_TX_DPATH_RESET_MASK        (0x8000000U)
#define EARC_EXT_CTRL_TX_DPATH_RESET_SHIFT       (27U)
/*! TX_DPATH_RESET - Soft reset to the Datapath for Transmit */
#define EARC_EXT_CTRL_TX_DPATH_RESET(x)          (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_TX_DPATH_RESET_SHIFT)) & EARC_EXT_CTRL_TX_DPATH_RESET_MASK)

#define EARC_EXT_CTRL_RX_DPATH_RESET_MASK        (0x10000000U)
#define EARC_EXT_CTRL_RX_DPATH_RESET_SHIFT       (28U)
/*! RX_DPATH_RESET - Soft reset to the eARC Differential data Receiver */
#define EARC_EXT_CTRL_RX_DPATH_RESET(x)          (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_RX_DPATH_RESET_SHIFT)) & EARC_EXT_CTRL_RX_DPATH_RESET_MASK)

#define EARC_EXT_CTRL_TX_CMDC_RESET_MASK         (0x20000000U)
#define EARC_EXT_CTRL_TX_CMDC_RESET_SHIFT        (29U)
/*! TX_CMDC_RESET - Soft reset to the eARC Common mode Transmitter */
#define EARC_EXT_CTRL_TX_CMDC_RESET(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_TX_CMDC_RESET_SHIFT)) & EARC_EXT_CTRL_TX_CMDC_RESET_MASK)

#define EARC_EXT_CTRL_RX_CMDC_RESET_MASK         (0x40000000U)
#define EARC_EXT_CTRL_RX_CMDC_RESET_SHIFT        (30U)
/*! RX_CMDC_RESET - Soft reset to the eARC Common mode Receiver */
#define EARC_EXT_CTRL_RX_CMDC_RESET(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_RX_CMDC_RESET_SHIFT)) & EARC_EXT_CTRL_RX_CMDC_RESET_MASK)

#define EARC_EXT_CTRL_CORE_RESET_MASK            (0x80000000U)
#define EARC_EXT_CTRL_CORE_RESET_SHIFT           (31U)
/*! CORE_RESET - M0+ Reset */
#define EARC_EXT_CTRL_CORE_RESET(x)              (((uint32_t)(((uint32_t)(x)) << EARC_EXT_CTRL_CORE_RESET_SHIFT)) & EARC_EXT_CTRL_CORE_RESET_MASK)
/*! @} */

/*! @name EXT_STATUS - External Status register */
/*! @{ */

#define EARC_EXT_STATUS_NO_TX_FIFO_ENTRIES_MASK  (0xFFU)
#define EARC_EXT_STATUS_NO_TX_FIFO_ENTRIES_SHIFT (0U)
/*! NO_TX_FIFO_ENTRIES - TX FIFO entries */
#define EARC_EXT_STATUS_NO_TX_FIFO_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_NO_TX_FIFO_ENTRIES_SHIFT)) & EARC_EXT_STATUS_NO_TX_FIFO_ENTRIES_MASK)

#define EARC_EXT_STATUS_NO_RX_FIFO_ENTRIES_MASK  (0xFF00U)
#define EARC_EXT_STATUS_NO_RX_FIFO_ENTRIES_SHIFT (8U)
/*! NO_RX_FIFO_ENTRIES - RX FIFO entries */
#define EARC_EXT_STATUS_NO_RX_FIFO_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_NO_RX_FIFO_ENTRIES_SHIFT)) & EARC_EXT_STATUS_NO_RX_FIFO_ENTRIES_MASK)

#define EARC_EXT_STATUS_CM0_SLEEPING_MASK        (0x10000U)
#define EARC_EXT_STATUS_CM0_SLEEPING_SHIFT       (16U)
/*! CM0_SLEEPING - CM0 is in Sleep mode. */
#define EARC_EXT_STATUS_CM0_SLEEPING(x)          (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_CM0_SLEEPING_SHIFT)) & EARC_EXT_STATUS_CM0_SLEEPING_MASK)

#define EARC_EXT_STATUS_CM0_DEEP_SLEEP_MASK      (0x20000U)
#define EARC_EXT_STATUS_CM0_DEEP_SLEEP_SHIFT     (17U)
/*! CM0_DEEP_SLEEP - CM0 is in deep sleep mode. */
#define EARC_EXT_STATUS_CM0_DEEP_SLEEP(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_CM0_DEEP_SLEEP_SHIFT)) & EARC_EXT_STATUS_CM0_DEEP_SLEEP_MASK)

#define EARC_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_MASK (0x40000U)
#define EARC_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_SHIFT (18U)
/*! CM0_SLEEP_HOLD_ACK_B - Sleep extension acknowledge. */
#define EARC_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B(x)  (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_SHIFT)) & EARC_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_MASK)

#define EARC_EXT_STATUS_TX_PIPE_EMPTY_MASK       (0x200000U)
#define EARC_EXT_STATUS_TX_PIPE_EMPTY_SHIFT      (21U)
/*! TX_PIPE_EMPTY - Indicates TX pipe status. */
#define EARC_EXT_STATUS_TX_PIPE_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_TX_PIPE_EMPTY_SHIFT)) & EARC_EXT_STATUS_TX_PIPE_EMPTY_MASK)

#define EARC_EXT_STATUS_RX_CMDC_RESP_TO_MASK     (0x800000U)
#define EARC_EXT_STATUS_RX_CMDC_RESP_TO_SHIFT    (23U)
/*! RX_CMDC_RESP_TO - CMDC Response not sent in programmed time */
#define EARC_EXT_STATUS_RX_CMDC_RESP_TO(x)       (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_RX_CMDC_RESP_TO_SHIFT)) & EARC_EXT_STATUS_RX_CMDC_RESP_TO_MASK)

#define EARC_EXT_STATUS_RX_CMDC_COMMA_TO_MASK    (0x2000000U)
#define EARC_EXT_STATUS_RX_CMDC_COMMA_TO_SHIFT   (25U)
/*! RX_CMDC_COMMA_TO - Receiver CMDC comma timeout Interrupt */
#define EARC_EXT_STATUS_RX_CMDC_COMMA_TO(x)      (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_RX_CMDC_COMMA_TO_SHIFT)) & EARC_EXT_STATUS_RX_CMDC_COMMA_TO_MASK)

#define EARC_EXT_STATUS_HEARTBEAT_STATUS_MASK    (0x8000000U)
#define EARC_EXT_STATUS_HEARTBEAT_STATUS_SHIFT   (27U)
/*! HEARTBEAT_STATUS - Earc Connection Status */
#define EARC_EXT_STATUS_HEARTBEAT_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_HEARTBEAT_STATUS_SHIFT)) & EARC_EXT_STATUS_HEARTBEAT_STATUS_MASK)

#define EARC_EXT_STATUS_NEW_UD4_REC_MASK         (0x10000000U)
#define EARC_EXT_STATUS_NEW_UD4_REC_SHIFT        (28U)
/*! NEW_UD4_REC - New user data */
#define EARC_EXT_STATUS_NEW_UD4_REC(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_NEW_UD4_REC_SHIFT)) & EARC_EXT_STATUS_NEW_UD4_REC_MASK)

#define EARC_EXT_STATUS_NEW_UD5_REC_MASK         (0x20000000U)
#define EARC_EXT_STATUS_NEW_UD5_REC_SHIFT        (29U)
/*! NEW_UD5_REC - New user data */
#define EARC_EXT_STATUS_NEW_UD5_REC(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_NEW_UD5_REC_SHIFT)) & EARC_EXT_STATUS_NEW_UD5_REC_MASK)

#define EARC_EXT_STATUS_NEW_UD6_REC_MASK         (0x40000000U)
#define EARC_EXT_STATUS_NEW_UD6_REC_SHIFT        (30U)
/*! NEW_UD6_REC - New user data */
#define EARC_EXT_STATUS_NEW_UD6_REC(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_NEW_UD6_REC_SHIFT)) & EARC_EXT_STATUS_NEW_UD6_REC_MASK)

#define EARC_EXT_STATUS_HPD_I_MASK               (0x80000000U)
#define EARC_EXT_STATUS_HPD_I_SHIFT              (31U)
/*! HPD_I - HPD Input status */
#define EARC_EXT_STATUS_HPD_I(x)                 (((uint32_t)(((uint32_t)(x)) << EARC_EXT_STATUS_HPD_I_SHIFT)) & EARC_EXT_STATUS_HPD_I_MASK)
/*! @} */

/*! @name EXT_IER0 - Interrupt enables for interrupt 0 */
/*! @{ */

#define EARC_EXT_IER0_NEW_CS_IE_0_MASK           (0x1U)
#define EARC_EXT_IER0_NEW_CS_IE_0_SHIFT          (0U)
/*! NEW_CS_IE_0 - Enable for New channel status block received interrupt */
#define EARC_EXT_IER0_NEW_CS_IE_0(x)             (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_NEW_CS_IE_0_SHIFT)) & EARC_EXT_IER0_NEW_CS_IE_0_MASK)

#define EARC_EXT_IER0_NEW_UD_IE_0_MASK           (0x2U)
#define EARC_EXT_IER0_NEW_UD_IE_0_SHIFT          (1U)
/*! NEW_UD_IE_0 - Enable for new user data received interrupt */
#define EARC_EXT_IER0_NEW_UD_IE_0(x)             (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_NEW_UD_IE_0_SHIFT)) & EARC_EXT_IER0_NEW_UD_IE_0_MASK)

#define EARC_EXT_IER0_MUTE_IE_0_MASK             (0x4U)
#define EARC_EXT_IER0_MUTE_IE_0_SHIFT            (2U)
/*! MUTE_IE_0 - Enable for Mute detected interrupt */
#define EARC_EXT_IER0_MUTE_IE_0(x)               (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_MUTE_IE_0_SHIFT)) & EARC_EXT_IER0_MUTE_IE_0_MASK)

#define EARC_EXT_IER0_CMDC_RESP_TO_IE_0_MASK     (0x8U)
#define EARC_EXT_IER0_CMDC_RESP_TO_IE_0_SHIFT    (3U)
/*! CMDC_RESP_TO_IE_0 - Receiver CMDC data response timeout interrupt enable */
#define EARC_EXT_IER0_CMDC_RESP_TO_IE_0(x)       (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_CMDC_RESP_TO_IE_0_SHIFT)) & EARC_EXT_IER0_CMDC_RESP_TO_IE_0_MASK)

#define EARC_EXT_IER0_ECC_ERR_IE_0_MASK          (0x10U)
#define EARC_EXT_IER0_ECC_ERR_IE_0_SHIFT         (4U)
/*! ECC_ERR_IE_0 - 60958 Compressed data uncorrectable error interrupt enable */
#define EARC_EXT_IER0_ECC_ERR_IE_0(x)            (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_ECC_ERR_IE_0_SHIFT)) & EARC_EXT_IER0_ECC_ERR_IE_0_MASK)

#define EARC_EXT_IER0_PREAMBLE_MISMATCH_IE_0_MASK (0x20U)
#define EARC_EXT_IER0_PREAMBLE_MISMATCH_IE_0_SHIFT (5U)
/*! PREAMBLE_MISMATCH_IE_0 - Preamble mismatch interrupt enable. */
#define EARC_EXT_IER0_PREAMBLE_MISMATCH_IE_0(x)  (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_PREAMBLE_MISMATCH_IE_0_SHIFT)) & EARC_EXT_IER0_PREAMBLE_MISMATCH_IE_0_MASK)

#define EARC_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_MASK (0x40U)
#define EARC_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR_IE_0 - Receive FIFO overflow error interrupt enable. */
#define EARC_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0(x) (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_SHIFT)) & EARC_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_MASK)

#define EARC_EXT_IER0_HOST_WAKEUP_IE_0_MASK      (0x80U)
#define EARC_EXT_IER0_HOST_WAKEUP_IE_0_SHIFT     (7U)
/*! HOST_WAKEUP_IE_0 - Host wakeup on CEC match interrupt enable. */
#define EARC_EXT_IER0_HOST_WAKEUP_IE_0(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_HOST_WAKEUP_IE_0_SHIFT)) & EARC_EXT_IER0_HOST_WAKEUP_IE_0_MASK)

#define EARC_EXT_IER0_OHPD_IE_0_MASK             (0x100U)
#define EARC_EXT_IER0_OHPD_IE_0_SHIFT            (8U)
/*! OHPD_IE_0 - Output HPD interrupt enable. */
#define EARC_EXT_IER0_OHPD_IE_0(x)               (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_OHPD_IE_0_SHIFT)) & EARC_EXT_IER0_OHPD_IE_0_MASK)

#define EARC_EXT_IER0_DMAC_NO_DATA_REC_IE_0_MASK (0x200U)
#define EARC_EXT_IER0_DMAC_NO_DATA_REC_IE_0_SHIFT (9U)
/*! DMAC_NO_DATA_REC_IE_0 - Indicates no DMAC data is received. */
#define EARC_EXT_IER0_DMAC_NO_DATA_REC_IE_0(x)   (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_DMAC_NO_DATA_REC_IE_0_SHIFT)) & EARC_EXT_IER0_DMAC_NO_DATA_REC_IE_0_MASK)

#define EARC_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_MASK (0x400U)
#define EARC_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_SHIFT (10U)
/*! DMAC_FMT_CHG_DET_IE_0 - Indicates DMAC format change was detected */
#define EARC_EXT_IER0_DMAC_FMT_CHG_DET_IE_0(x)   (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_SHIFT)) & EARC_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_MASK)

#define EARC_EXT_IER0_HB_STATE_CHG_IE_0_MASK     (0x800U)
#define EARC_EXT_IER0_HB_STATE_CHG_IE_0_SHIFT    (11U)
/*! HB_STATE_CHG_IE_0 - Interrupt enable for Heartbeat status change */
#define EARC_EXT_IER0_HB_STATE_CHG_IE_0(x)       (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_HB_STATE_CHG_IE_0_SHIFT)) & EARC_EXT_IER0_HB_STATE_CHG_IE_0_MASK)

#define EARC_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_MASK (0x1000U)
#define EARC_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_SHIFT (12U)
/*! CMDC_STATUS_UPDATE_IE_0 - Interrupt enable for CMDC status register update. */
#define EARC_EXT_IER0_CMDC_STATUS_UPDATE_IE_0(x) (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_SHIFT)) & EARC_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_MASK)

#define EARC_EXT_IER0_TEMP_UPDATE_IE_0_MASK      (0x2000U)
#define EARC_EXT_IER0_TEMP_UPDATE_IE_0_SHIFT     (13U)
/*! TEMP_UPDATE_IE_0 - Update request for chip temperature value. */
#define EARC_EXT_IER0_TEMP_UPDATE_IE_0(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_TEMP_UPDATE_IE_0_SHIFT)) & EARC_EXT_IER0_TEMP_UPDATE_IE_0_MASK)

#define EARC_EXT_IER0_DMA_RD_REQ_IE_0_MASK       (0x4000U)
#define EARC_EXT_IER0_DMA_RD_REQ_IE_0_SHIFT      (14U)
/*! DMA_RD_REQ_IE_0 - Request to read data from FIFO. */
#define EARC_EXT_IER0_DMA_RD_REQ_IE_0(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_DMA_RD_REQ_IE_0_SHIFT)) & EARC_EXT_IER0_DMA_RD_REQ_IE_0_MASK)

#define EARC_EXT_IER0_DMA_WR_REQ_IE_0_MASK       (0x8000U)
#define EARC_EXT_IER0_DMA_WR_REQ_IE_0_SHIFT      (15U)
/*! DMA_WR_REQ_IE_0 - Request to write data to FIFO. */
#define EARC_EXT_IER0_DMA_WR_REQ_IE_0(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_DMA_WR_REQ_IE_0_SHIFT)) & EARC_EXT_IER0_DMA_WR_REQ_IE_0_MASK)

#define EARC_EXT_IER0_DMAC_RX_BME_ERR_IE_0_MASK  (0x10000U)
#define EARC_EXT_IER0_DMAC_RX_BME_ERR_IE_0_SHIFT (16U)
/*! DMAC_RX_BME_ERR_IE_0 - Bi-phase mark encoding error */
#define EARC_EXT_IER0_DMAC_RX_BME_ERR_IE_0(x)    (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_DMAC_RX_BME_ERR_IE_0_SHIFT)) & EARC_EXT_IER0_DMAC_RX_BME_ERR_IE_0_MASK)

#define EARC_EXT_IER0_PREAMBLE_MATCH_IE_0_MASK   (0x20000U)
#define EARC_EXT_IER0_PREAMBLE_MATCH_IE_0_SHIFT  (17U)
/*! PREAMBLE_MATCH_IE_0 - Interrupt enable for preamble match received. */
#define EARC_EXT_IER0_PREAMBLE_MATCH_IE_0(x)     (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_PREAMBLE_MATCH_IE_0_SHIFT)) & EARC_EXT_IER0_PREAMBLE_MATCH_IE_0_MASK)

#define EARC_EXT_IER0_M_W_PRE_MISMATCH_IE_0_MASK (0x40000U)
#define EARC_EXT_IER0_M_W_PRE_MISMATCH_IE_0_SHIFT (18U)
/*! M_W_PRE_MISMATCH_IE_0 - Interrupt enable for sub-frame M/W preamble mismatch received. */
#define EARC_EXT_IER0_M_W_PRE_MISMATCH_IE_0(x)   (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_M_W_PRE_MISMATCH_IE_0_SHIFT)) & EARC_EXT_IER0_M_W_PRE_MISMATCH_IE_0_MASK)

#define EARC_EXT_IER0_B_PRE_MISMATCH_IE_0_MASK   (0x80000U)
#define EARC_EXT_IER0_B_PRE_MISMATCH_IE_0_SHIFT  (19U)
/*! B_PRE_MISMATCH_IE_0 - Interrupt enable for sub-frame B preamble mismatch received. */
#define EARC_EXT_IER0_B_PRE_MISMATCH_IE_0(x)     (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_B_PRE_MISMATCH_IE_0_SHIFT)) & EARC_EXT_IER0_B_PRE_MISMATCH_IE_0_MASK)

#define EARC_EXT_IER0_UNEXP_PRE_REC_IE_0_MASK    (0x100000U)
#define EARC_EXT_IER0_UNEXP_PRE_REC_IE_0_SHIFT   (20U)
/*! UNEXP_PRE_REC_IE_0 - Interrupt enable for Unexpected preamble received. */
#define EARC_EXT_IER0_UNEXP_PRE_REC_IE_0(x)      (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_UNEXP_PRE_REC_IE_0_SHIFT)) & EARC_EXT_IER0_UNEXP_PRE_REC_IE_0_MASK)

#define EARC_EXT_IER0_ARC_MODE_IE_0_MASK         (0x200000U)
#define EARC_EXT_IER0_ARC_MODE_IE_0_SHIFT        (21U)
/*! ARC_MODE_IE_0 - Interrupt to indicate ARC mode setup. */
#define EARC_EXT_IER0_ARC_MODE_IE_0(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_ARC_MODE_IE_0_SHIFT)) & EARC_EXT_IER0_ARC_MODE_IE_0_MASK)

#define EARC_EXT_IER0_CH_UD_OFLOW_IE_0_MASK      (0x400000U)
#define EARC_EXT_IER0_CH_UD_OFLOW_IE_0_SHIFT     (22U)
/*! CH_UD_OFLOW_IE_0 - Channel status or used data could not be stored. */
#define EARC_EXT_IER0_CH_UD_OFLOW_IE_0(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_CH_UD_OFLOW_IE_0_SHIFT)) & EARC_EXT_IER0_CH_UD_OFLOW_IE_0_MASK)

#define EARC_EXT_IER0_SPARE_IE_0_MASK            (0xFF800000U)
#define EARC_EXT_IER0_SPARE_IE_0_SHIFT           (23U)
/*! SPARE_IE_0 - Spare interrupts */
#define EARC_EXT_IER0_SPARE_IE_0(x)              (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER0_SPARE_IE_0_SHIFT)) & EARC_EXT_IER0_SPARE_IE_0_MASK)
/*! @} */

/*! @name EXT_IER1 - Interrupt enables for interrupt 1 */
/*! @{ */

#define EARC_EXT_IER1_NEW_CS_IE_1_MASK           (0x1U)
#define EARC_EXT_IER1_NEW_CS_IE_1_SHIFT          (0U)
/*! NEW_CS_IE_1 - Enable for New channel status block received interrupt */
#define EARC_EXT_IER1_NEW_CS_IE_1(x)             (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_NEW_CS_IE_1_SHIFT)) & EARC_EXT_IER1_NEW_CS_IE_1_MASK)

#define EARC_EXT_IER1_NEW_UD_IE_1_MASK           (0x2U)
#define EARC_EXT_IER1_NEW_UD_IE_1_SHIFT          (1U)
/*! NEW_UD_IE_1 - Enable for new user data received interrupt */
#define EARC_EXT_IER1_NEW_UD_IE_1(x)             (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_NEW_UD_IE_1_SHIFT)) & EARC_EXT_IER1_NEW_UD_IE_1_MASK)

#define EARC_EXT_IER1_MUTE_IE_1_MASK             (0x4U)
#define EARC_EXT_IER1_MUTE_IE_1_SHIFT            (2U)
/*! MUTE_IE_1 - Enable for Mute detected interrupt */
#define EARC_EXT_IER1_MUTE_IE_1(x)               (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_MUTE_IE_1_SHIFT)) & EARC_EXT_IER1_MUTE_IE_1_MASK)

#define EARC_EXT_IER1_CMDC_RESP_TO_IE_1_MASK     (0x8U)
#define EARC_EXT_IER1_CMDC_RESP_TO_IE_1_SHIFT    (3U)
/*! CMDC_RESP_TO_IE_1 - Receiver CMDC data response timeout interrupt enable */
#define EARC_EXT_IER1_CMDC_RESP_TO_IE_1(x)       (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_CMDC_RESP_TO_IE_1_SHIFT)) & EARC_EXT_IER1_CMDC_RESP_TO_IE_1_MASK)

#define EARC_EXT_IER1_ECC_ERR_IE_1_MASK          (0x10U)
#define EARC_EXT_IER1_ECC_ERR_IE_1_SHIFT         (4U)
/*! ECC_ERR_IE_1 - 60958 Compressed data uncorrectable error interrupt enable */
#define EARC_EXT_IER1_ECC_ERR_IE_1(x)            (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_ECC_ERR_IE_1_SHIFT)) & EARC_EXT_IER1_ECC_ERR_IE_1_MASK)

#define EARC_EXT_IER1_PREAMBLE_MISMATCH_IE_1_MASK (0x20U)
#define EARC_EXT_IER1_PREAMBLE_MISMATCH_IE_1_SHIFT (5U)
/*! PREAMBLE_MISMATCH_IE_1 - Preamble mismatch interrupt enable. */
#define EARC_EXT_IER1_PREAMBLE_MISMATCH_IE_1(x)  (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_PREAMBLE_MISMATCH_IE_1_SHIFT)) & EARC_EXT_IER1_PREAMBLE_MISMATCH_IE_1_MASK)

#define EARC_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_MASK (0x40U)
#define EARC_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR_IE_1 - Receive FIFO overflow error interrupt enable. */
#define EARC_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1(x) (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_SHIFT)) & EARC_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_MASK)

#define EARC_EXT_IER1_HOST_WAKEUP_IE_1_MASK      (0x80U)
#define EARC_EXT_IER1_HOST_WAKEUP_IE_1_SHIFT     (7U)
/*! HOST_WAKEUP_IE_1 - Host wakeup on CEC match interrupt enable. */
#define EARC_EXT_IER1_HOST_WAKEUP_IE_1(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_HOST_WAKEUP_IE_1_SHIFT)) & EARC_EXT_IER1_HOST_WAKEUP_IE_1_MASK)

#define EARC_EXT_IER1_OHPD_IE_1_MASK             (0x100U)
#define EARC_EXT_IER1_OHPD_IE_1_SHIFT            (8U)
/*! OHPD_IE_1 - Output HPD interrupt enable. */
#define EARC_EXT_IER1_OHPD_IE_1(x)               (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_OHPD_IE_1_SHIFT)) & EARC_EXT_IER1_OHPD_IE_1_MASK)

#define EARC_EXT_IER1_DMAC_NO_DATA_REC_IE_1_MASK (0x200U)
#define EARC_EXT_IER1_DMAC_NO_DATA_REC_IE_1_SHIFT (9U)
/*! DMAC_NO_DATA_REC_IE_1 - Indicates no DMAC data is received. */
#define EARC_EXT_IER1_DMAC_NO_DATA_REC_IE_1(x)   (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_DMAC_NO_DATA_REC_IE_1_SHIFT)) & EARC_EXT_IER1_DMAC_NO_DATA_REC_IE_1_MASK)

#define EARC_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_MASK (0x400U)
#define EARC_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_SHIFT (10U)
/*! DMAC_FMT_CHG_DET_IE_1 - Indicates DMAC format change was detected */
#define EARC_EXT_IER1_DMAC_FMT_CHG_DET_IE_1(x)   (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_SHIFT)) & EARC_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_MASK)

#define EARC_EXT_IER1_HB_STATE_CHG_IE_1_MASK     (0x800U)
#define EARC_EXT_IER1_HB_STATE_CHG_IE_1_SHIFT    (11U)
/*! HB_STATE_CHG_IE_1 - Interrupt enable for Heartbeat status change */
#define EARC_EXT_IER1_HB_STATE_CHG_IE_1(x)       (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_HB_STATE_CHG_IE_1_SHIFT)) & EARC_EXT_IER1_HB_STATE_CHG_IE_1_MASK)

#define EARC_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_MASK (0x1000U)
#define EARC_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_SHIFT (12U)
/*! CMDC_STATUS_UPDATE_IE_1 - Interrupt enable for CMDC status register update. */
#define EARC_EXT_IER1_CMDC_STATUS_UPDATE_IE_1(x) (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_SHIFT)) & EARC_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_MASK)

#define EARC_EXT_IER1_TEMP_UPDATE_IE_1_MASK      (0x2000U)
#define EARC_EXT_IER1_TEMP_UPDATE_IE_1_SHIFT     (13U)
/*! TEMP_UPDATE_IE_1 - Update request for chip temperature value. */
#define EARC_EXT_IER1_TEMP_UPDATE_IE_1(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_TEMP_UPDATE_IE_1_SHIFT)) & EARC_EXT_IER1_TEMP_UPDATE_IE_1_MASK)

#define EARC_EXT_IER1_DMA_RD_REQ_IE_1_MASK       (0x4000U)
#define EARC_EXT_IER1_DMA_RD_REQ_IE_1_SHIFT      (14U)
/*! DMA_RD_REQ_IE_1 - Request to read data from FIFO. */
#define EARC_EXT_IER1_DMA_RD_REQ_IE_1(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_DMA_RD_REQ_IE_1_SHIFT)) & EARC_EXT_IER1_DMA_RD_REQ_IE_1_MASK)

#define EARC_EXT_IER1_DMA_WR_REQ_IE_1_MASK       (0x8000U)
#define EARC_EXT_IER1_DMA_WR_REQ_IE_1_SHIFT      (15U)
/*! DMA_WR_REQ_IE_1 - Request to write data to FIFO. */
#define EARC_EXT_IER1_DMA_WR_REQ_IE_1(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_DMA_WR_REQ_IE_1_SHIFT)) & EARC_EXT_IER1_DMA_WR_REQ_IE_1_MASK)

#define EARC_EXT_IER1_DMAC_RX_BME_ERR_IE_1_MASK  (0x10000U)
#define EARC_EXT_IER1_DMAC_RX_BME_ERR_IE_1_SHIFT (16U)
/*! DMAC_RX_BME_ERR_IE_1 - Bi-phase mark encoding error */
#define EARC_EXT_IER1_DMAC_RX_BME_ERR_IE_1(x)    (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_DMAC_RX_BME_ERR_IE_1_SHIFT)) & EARC_EXT_IER1_DMAC_RX_BME_ERR_IE_1_MASK)

#define EARC_EXT_IER1_PREAMBLE_MATCH_IE_1_MASK   (0x20000U)
#define EARC_EXT_IER1_PREAMBLE_MATCH_IE_1_SHIFT  (17U)
/*! PREAMBLE_MATCH_IE_1 - Interrupt enable for preamble match received. */
#define EARC_EXT_IER1_PREAMBLE_MATCH_IE_1(x)     (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_PREAMBLE_MATCH_IE_1_SHIFT)) & EARC_EXT_IER1_PREAMBLE_MATCH_IE_1_MASK)

#define EARC_EXT_IER1_M_W_PRE_MISMATCH_IE_1_MASK (0x40000U)
#define EARC_EXT_IER1_M_W_PRE_MISMATCH_IE_1_SHIFT (18U)
/*! M_W_PRE_MISMATCH_IE_1 - Interrupt enable for sub-frame M/W preamble mismatch received. */
#define EARC_EXT_IER1_M_W_PRE_MISMATCH_IE_1(x)   (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_M_W_PRE_MISMATCH_IE_1_SHIFT)) & EARC_EXT_IER1_M_W_PRE_MISMATCH_IE_1_MASK)

#define EARC_EXT_IER1_B_PRE_MISMATCH_IE_1_MASK   (0x80000U)
#define EARC_EXT_IER1_B_PRE_MISMATCH_IE_1_SHIFT  (19U)
/*! B_PRE_MISMATCH_IE_1 - Interrupt enable for sub-frame B preamble mismatch received. */
#define EARC_EXT_IER1_B_PRE_MISMATCH_IE_1(x)     (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_B_PRE_MISMATCH_IE_1_SHIFT)) & EARC_EXT_IER1_B_PRE_MISMATCH_IE_1_MASK)

#define EARC_EXT_IER1_UNEXP_PRE_REC_IE_1_MASK    (0x100000U)
#define EARC_EXT_IER1_UNEXP_PRE_REC_IE_1_SHIFT   (20U)
/*! UNEXP_PRE_REC_IE_1 - Interrupt enable for Unexpected preamble received. */
#define EARC_EXT_IER1_UNEXP_PRE_REC_IE_1(x)      (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_UNEXP_PRE_REC_IE_1_SHIFT)) & EARC_EXT_IER1_UNEXP_PRE_REC_IE_1_MASK)

#define EARC_EXT_IER1_ARC_MODE_IE_1_MASK         (0x200000U)
#define EARC_EXT_IER1_ARC_MODE_IE_1_SHIFT        (21U)
/*! ARC_MODE_IE_1 - Interrupt to indicate ARC mode setup. */
#define EARC_EXT_IER1_ARC_MODE_IE_1(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_ARC_MODE_IE_1_SHIFT)) & EARC_EXT_IER1_ARC_MODE_IE_1_MASK)

#define EARC_EXT_IER1_CH_UD_OFLOW_IE_1_MASK      (0x400000U)
#define EARC_EXT_IER1_CH_UD_OFLOW_IE_1_SHIFT     (22U)
/*! CH_UD_OFLOW_IE_1 - Channel status or used data could not be stored. */
#define EARC_EXT_IER1_CH_UD_OFLOW_IE_1(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_CH_UD_OFLOW_IE_1_SHIFT)) & EARC_EXT_IER1_CH_UD_OFLOW_IE_1_MASK)

#define EARC_EXT_IER1_SPARE_IE_1_MASK            (0xFF800000U)
#define EARC_EXT_IER1_SPARE_IE_1_SHIFT           (23U)
/*! SPARE_IE_1 - Spare interrupt enables. */
#define EARC_EXT_IER1_SPARE_IE_1(x)              (((uint32_t)(((uint32_t)(x)) << EARC_EXT_IER1_SPARE_IE_1_SHIFT)) & EARC_EXT_IER1_SPARE_IE_1_MASK)
/*! @} */

/*! @name EXT_ISR - External Interrupt Status register */
/*! @{ */

#define EARC_EXT_ISR_RX_NEW_CH_STAT_MASK         (0x1U)
#define EARC_EXT_ISR_RX_NEW_CH_STAT_SHIFT        (0U)
/*! RX_NEW_CH_STAT - Received new channel status block */
#define EARC_EXT_ISR_RX_NEW_CH_STAT(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_RX_NEW_CH_STAT_SHIFT)) & EARC_EXT_ISR_RX_NEW_CH_STAT_MASK)

#define EARC_EXT_ISR_RX_NEW_USR_DATA_MASK        (0x2U)
#define EARC_EXT_ISR_RX_NEW_USR_DATA_SHIFT       (1U)
/*! RX_NEW_USR_DATA - Received new User data Information */
#define EARC_EXT_ISR_RX_NEW_USR_DATA(x)          (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_RX_NEW_USR_DATA_SHIFT)) & EARC_EXT_ISR_RX_NEW_USR_DATA_MASK)

#define EARC_EXT_ISR_MUTE_DET_MASK               (0x4U)
#define EARC_EXT_ISR_MUTE_DET_SHIFT              (2U)
/*! MUTE_DET - Interrupt to indicate HW mute bit was detected. */
#define EARC_EXT_ISR_MUTE_DET(x)                 (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_MUTE_DET_SHIFT)) & EARC_EXT_ISR_MUTE_DET_MASK)

#define EARC_EXT_ISR_CMDC_RESP_TO_ERR_MASK       (0x8U)
#define EARC_EXT_ISR_CMDC_RESP_TO_ERR_SHIFT      (3U)
/*! CMDC_RESP_TO_ERR - CMDC response timeout interrupt */
#define EARC_EXT_ISR_CMDC_RESP_TO_ERR(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_CMDC_RESP_TO_ERR_SHIFT)) & EARC_EXT_ISR_CMDC_RESP_TO_ERR_MASK)

#define EARC_EXT_ISR_ECC_ERR_MASK                (0x10U)
#define EARC_EXT_ISR_ECC_ERR_SHIFT               (4U)
/*! ECC_ERR - 60958 Compressed data uncorrectable error interrupt */
#define EARC_EXT_ISR_ECC_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_ECC_ERR_SHIFT)) & EARC_EXT_ISR_ECC_ERR_MASK)

#define EARC_EXT_ISR_PREAMBLE_MISMATCH_MASK      (0x20U)
#define EARC_EXT_ISR_PREAMBLE_MISMATCH_SHIFT     (5U)
/*! PREAMBLE_MISMATCH - Preamble mismatch interrupt */
#define EARC_EXT_ISR_PREAMBLE_MISMATCH(x)        (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_PREAMBLE_MISMATCH_SHIFT)) & EARC_EXT_ISR_PREAMBLE_MISMATCH_MASK)

#define EARC_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_MASK   (0x40U)
#define EARC_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_SHIFT  (6U)
/*! FIFO_OFLOW_UFLOW_ERR - Receive FIFO overflow error interrupt */
#define EARC_EXT_ISR_FIFO_OFLOW_UFLOW_ERR(x)     (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_SHIFT)) & EARC_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_MASK)

#define EARC_EXT_ISR_HOST_WAKEUP_MASK            (0x80U)
#define EARC_EXT_ISR_HOST_WAKEUP_SHIFT           (7U)
/*! HOST_WAKEUP - Host wakeup on CEC OPCODE match interrupt. */
#define EARC_EXT_ISR_HOST_WAKEUP(x)              (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_HOST_WAKEUP_SHIFT)) & EARC_EXT_ISR_HOST_WAKEUP_MASK)

#define EARC_EXT_ISR_OHPD_MASK                   (0x100U)
#define EARC_EXT_ISR_OHPD_SHIFT                  (8U)
/*! OHPD - HPD output driver */
#define EARC_EXT_ISR_OHPD(x)                     (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_OHPD_SHIFT)) & EARC_EXT_ISR_OHPD_MASK)

#define EARC_EXT_ISR_DMAC_NO_DATA_REC_MASK       (0x200U)
#define EARC_EXT_ISR_DMAC_NO_DATA_REC_SHIFT      (9U)
/*! DMAC_NO_DATA_REC - No DMAC data is received for 1us. */
#define EARC_EXT_ISR_DMAC_NO_DATA_REC(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_DMAC_NO_DATA_REC_SHIFT)) & EARC_EXT_ISR_DMAC_NO_DATA_REC_MASK)

#define EARC_EXT_ISR_FMT_CHG_DET_MASK            (0x400U)
#define EARC_EXT_ISR_FMT_CHG_DET_SHIFT           (10U)
/*! FMT_CHG_DET - Format change detect interrupt */
#define EARC_EXT_ISR_FMT_CHG_DET(x)              (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_FMT_CHG_DET_SHIFT)) & EARC_EXT_ISR_FMT_CHG_DET_MASK)

#define EARC_EXT_ISR_HB_STATE_CHG_MASK           (0x800U)
#define EARC_EXT_ISR_HB_STATE_CHG_SHIFT          (11U)
/*! HB_STATE_CHG - Interrupt enable for Heartbeat status change */
#define EARC_EXT_ISR_HB_STATE_CHG(x)             (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_HB_STATE_CHG_SHIFT)) & EARC_EXT_ISR_HB_STATE_CHG_MASK)

#define EARC_EXT_ISR_CMDC_STATUS_UPDATE_MASK     (0x1000U)
#define EARC_EXT_ISR_CMDC_STATUS_UPDATE_SHIFT    (12U)
/*! CMDC_STATUS_UPDATE - Interrupt enable for CMDC status register update. */
#define EARC_EXT_ISR_CMDC_STATUS_UPDATE(x)       (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_CMDC_STATUS_UPDATE_SHIFT)) & EARC_EXT_ISR_CMDC_STATUS_UPDATE_MASK)

#define EARC_EXT_ISR_TEMP_UPDATE_INT_MASK        (0x2000U)
#define EARC_EXT_ISR_TEMP_UPDATE_INT_SHIFT       (13U)
/*! TEMP_UPDATE_INT - Interrupt to get the new temperature value. */
#define EARC_EXT_ISR_TEMP_UPDATE_INT(x)          (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_TEMP_UPDATE_INT_SHIFT)) & EARC_EXT_ISR_TEMP_UPDATE_INT_MASK)

#define EARC_EXT_ISR_DMA_RD_REQ_MASK             (0x4000U)
#define EARC_EXT_ISR_DMA_RD_REQ_SHIFT            (14U)
/*! DMA_RD_REQ - Set when DMA read request is asserted. */
#define EARC_EXT_ISR_DMA_RD_REQ(x)               (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_DMA_RD_REQ_SHIFT)) & EARC_EXT_ISR_DMA_RD_REQ_MASK)

#define EARC_EXT_ISR_DMA_WR_REQ_MASK             (0x8000U)
#define EARC_EXT_ISR_DMA_WR_REQ_SHIFT            (15U)
/*! DMA_WR_REQ - Set when DMA write request is asserted. */
#define EARC_EXT_ISR_DMA_WR_REQ(x)               (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_DMA_WR_REQ_SHIFT)) & EARC_EXT_ISR_DMA_WR_REQ_MASK)

#define EARC_EXT_ISR_DMAC_BME_BIT_ERR_MASK       (0x10000U)
#define EARC_EXT_ISR_DMAC_BME_BIT_ERR_SHIFT      (16U)
/*! DMAC_BME_BIT_ERR - Set when DMAC BME data has an error. */
#define EARC_EXT_ISR_DMAC_BME_BIT_ERR(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_DMAC_BME_BIT_ERR_SHIFT)) & EARC_EXT_ISR_DMAC_BME_BIT_ERR_MASK)

#define EARC_EXT_ISR_PREAMBLE_MATCH_INT_MASK     (0x20000U)
#define EARC_EXT_ISR_PREAMBLE_MATCH_INT_SHIFT    (17U)
/*! PREAMBLE_MATCH_INT - Interrupt to indicate PA PB / DTC CD preamble match was detected. */
#define EARC_EXT_ISR_PREAMBLE_MATCH_INT(x)       (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_PREAMBLE_MATCH_INT_SHIFT)) & EARC_EXT_ISR_PREAMBLE_MATCH_INT_MASK)

#define EARC_EXT_ISR_M_W_PRE_MISMATCH_MASK       (0x40000U)
#define EARC_EXT_ISR_M_W_PRE_MISMATCH_SHIFT      (18U)
/*! M_W_PRE_MISMATCH - Set when DMAC preamble of M/W has an error. */
#define EARC_EXT_ISR_M_W_PRE_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_M_W_PRE_MISMATCH_SHIFT)) & EARC_EXT_ISR_M_W_PRE_MISMATCH_MASK)

#define EARC_EXT_ISR_B_PRE_MISMATCH_MASK         (0x80000U)
#define EARC_EXT_ISR_B_PRE_MISMATCH_SHIFT        (19U)
/*! B_PRE_MISMATCH - Set when DMAC preamble of B has an error. */
#define EARC_EXT_ISR_B_PRE_MISMATCH(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_B_PRE_MISMATCH_SHIFT)) & EARC_EXT_ISR_B_PRE_MISMATCH_MASK)

#define EARC_EXT_ISR_UNEXP_PRE_REC_MASK          (0x100000U)
#define EARC_EXT_ISR_UNEXP_PRE_REC_SHIFT         (20U)
/*! UNEXP_PRE_REC - Set when DMAC preamble was received after unexpected number of input bits. */
#define EARC_EXT_ISR_UNEXP_PRE_REC(x)            (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_UNEXP_PRE_REC_SHIFT)) & EARC_EXT_ISR_UNEXP_PRE_REC_MASK)

#define EARC_EXT_ISR_SEL_ARC_MODE_MASK           (0x200000U)
#define EARC_EXT_ISR_SEL_ARC_MODE_SHIFT          (21U)
/*! SEL_ARC_MODE - Set when CMDC SM falls out of eARC mode. */
#define EARC_EXT_ISR_SEL_ARC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_SEL_ARC_MODE_SHIFT)) & EARC_EXT_ISR_SEL_ARC_MODE_MASK)

#define EARC_EXT_ISR_CS_OR_UD_OFLOW_MASK         (0x400000U)
#define EARC_EXT_ISR_CS_OR_UD_OFLOW_SHIFT        (22U)
/*! CS_OR_UD_OFLOW - Channel status or used data could not be stored. */
#define EARC_EXT_ISR_CS_OR_UD_OFLOW(x)           (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_CS_OR_UD_OFLOW_SHIFT)) & EARC_EXT_ISR_CS_OR_UD_OFLOW_MASK)

#define EARC_EXT_ISR_SPARE_INT_MASK              (0xFF800000U)
#define EARC_EXT_ISR_SPARE_INT_SHIFT             (23U)
/*! SPARE_INT - Extra interrupt. Currently not driven. Can be set by M0 */
#define EARC_EXT_ISR_SPARE_INT(x)                (((uint32_t)(((uint32_t)(x)) << EARC_EXT_ISR_SPARE_INT_SHIFT)) & EARC_EXT_ISR_SPARE_INT_MASK)
/*! @} */

/*! @name IER - Interrupt enable register for M0+ */
/*! @{ */

#define EARC_IER_RX_CMDC_RX_DATA_IE_MASK         (0x1U)
#define EARC_IER_RX_CMDC_RX_DATA_IE_SHIFT        (0U)
/*! RX_CMDC_RX_DATA_IE - RX mode CMDC Receive data interrupt enable */
#define EARC_IER_RX_CMDC_RX_DATA_IE(x)           (((uint32_t)(((uint32_t)(x)) << EARC_IER_RX_CMDC_RX_DATA_IE_SHIFT)) & EARC_IER_RX_CMDC_RX_DATA_IE_MASK)

#define EARC_IER_RX_CMDC_RESP_TO_ERR_IE_MASK     (0x4U)
#define EARC_IER_RX_CMDC_RESP_TO_ERR_IE_SHIFT    (2U)
/*! RX_CMDC_RESP_TO_ERR_IE - Recevier mode Response timeout error interrupt enable */
#define EARC_IER_RX_CMDC_RESP_TO_ERR_IE(x)       (((uint32_t)(((uint32_t)(x)) << EARC_IER_RX_CMDC_RESP_TO_ERR_IE_SHIFT)) & EARC_IER_RX_CMDC_RESP_TO_ERR_IE_MASK)

#define EARC_IER_CMDC_SPARE_IE_MASK              (0x100U)
#define EARC_IER_CMDC_SPARE_IE_SHIFT             (8U)
/*! CMDC_SPARE_IE - Spare Interrupt. Could be used for Loopback */
#define EARC_IER_CMDC_SPARE_IE(x)                (((uint32_t)(((uint32_t)(x)) << EARC_IER_CMDC_SPARE_IE_SHIFT)) & EARC_IER_CMDC_SPARE_IE_MASK)

#define EARC_IER_HPD_TGL_IE_MASK                 (0x8000U)
#define EARC_IER_HPD_TGL_IE_SHIFT                (15U)
/*! HPD_TGL_IE - HPD pin level change interrupt enable */
#define EARC_IER_HPD_TGL_IE(x)                   (((uint32_t)(((uint32_t)(x)) << EARC_IER_HPD_TGL_IE_SHIFT)) & EARC_IER_HPD_TGL_IE_MASK)

#define EARC_IER_PA_PB_DET_IE_MASK               (0x10000U)
#define EARC_IER_PA_PB_DET_IE_SHIFT              (16U)
/*! PA_PB_DET_IE - PA PB detected in Compressed mode interrupt enable */
#define EARC_IER_PA_PB_DET_IE(x)                 (((uint32_t)(((uint32_t)(x)) << EARC_IER_PA_PB_DET_IE_SHIFT)) & EARC_IER_PA_PB_DET_IE_MASK)

#define EARC_IER_DATA_BLK_REC_IE_MASK            (0x20000U)
#define EARC_IER_DATA_BLK_REC_IE_SHIFT           (17U)
/*! DATA_BLK_REC_IE - 60958 block of data received interrupt enable. */
#define EARC_IER_DATA_BLK_REC_IE(x)              (((uint32_t)(((uint32_t)(x)) << EARC_IER_DATA_BLK_REC_IE_SHIFT)) & EARC_IER_DATA_BLK_REC_IE_MASK)

#define EARC_IER_FMT_CHG_IE_MASK                 (0x40000U)
#define EARC_IER_FMT_CHG_IE_SHIFT                (18U)
/*! FMT_CHG_IE - Format Chnage interrupt. */
#define EARC_IER_FMT_CHG_IE(x)                   (((uint32_t)(((uint32_t)(x)) << EARC_IER_FMT_CHG_IE_SHIFT)) & EARC_IER_FMT_CHG_IE_MASK)

#define EARC_IER_DMAC_SPARE_IE_MASK              (0x80000U)
#define EARC_IER_DMAC_SPARE_IE_SHIFT             (19U)
/*! DMAC_SPARE_IE - Spare Interrupt. Could be used for Loopback */
#define EARC_IER_DMAC_SPARE_IE(x)                (((uint32_t)(((uint32_t)(x)) << EARC_IER_DMAC_SPARE_IE_SHIFT)) & EARC_IER_DMAC_SPARE_IE_MASK)

#define EARC_IER_SET_SPDIF_RX_IE_MASK            (0x100000U)
#define EARC_IER_SET_SPDIF_RX_IE_SHIFT           (20U)
/*! SET_SPDIF_RX_IE - Interrupt enable to set up SPDIF RX mode */
#define EARC_IER_SET_SPDIF_RX_IE(x)              (((uint32_t)(((uint32_t)(x)) << EARC_IER_SET_SPDIF_RX_IE_SHIFT)) & EARC_IER_SET_SPDIF_RX_IE_MASK)

#define EARC_IER_SET_SPDIF_TX_IE_MASK            (0x200000U)
#define EARC_IER_SET_SPDIF_TX_IE_SHIFT           (21U)
/*! SET_SPDIF_TX_IE - Interrupt enable to set up SPDIF TX mode */
#define EARC_IER_SET_SPDIF_TX_IE(x)              (((uint32_t)(((uint32_t)(x)) << EARC_IER_SET_SPDIF_TX_IE_SHIFT)) & EARC_IER_SET_SPDIF_TX_IE_MASK)

#define EARC_IER_SET_ARC_CM_IE_MASK              (0x400000U)
#define EARC_IER_SET_ARC_CM_IE_SHIFT             (22U)
/*! SET_ARC_CM_IE - Interrupt enable to set up PHY as Common mode ARC receiver */
#define EARC_IER_SET_ARC_CM_IE(x)                (((uint32_t)(((uint32_t)(x)) << EARC_IER_SET_ARC_CM_IE_SHIFT)) & EARC_IER_SET_ARC_CM_IE_MASK)

#define EARC_IER_SET_ARC_SE_IE_MASK              (0x800000U)
#define EARC_IER_SET_ARC_SE_IE_SHIFT             (23U)
/*! SET_ARC_SE_IE - Interrupt enable to set up PHY as Single ended mode ARC receiver */
#define EARC_IER_SET_ARC_SE_IE(x)                (((uint32_t)(((uint32_t)(x)) << EARC_IER_SET_ARC_SE_IE_SHIFT)) & EARC_IER_SET_ARC_SE_IE_MASK)

#define EARC_IER_SW_HPD_TGL_IE_MASK              (0x1000000U)
#define EARC_IER_SW_HPD_TGL_IE_SHIFT             (24U)
/*! SW_HPD_TGL_IE - Interrupt enable to allow SW to assert HPD. */
#define EARC_IER_SW_HPD_TGL_IE(x)                (((uint32_t)(((uint32_t)(x)) << EARC_IER_SW_HPD_TGL_IE_SHIFT)) & EARC_IER_SW_HPD_TGL_IE_MASK)

#define EARC_IER_TEMP_UPDATED_IE_MASK            (0x2000000U)
#define EARC_IER_TEMP_UPDATED_IE_SHIFT           (25U)
/*! TEMP_UPDATED_IE - Interrupt enable to allow SW to indicate new temperature value is available. */
#define EARC_IER_TEMP_UPDATED_IE(x)              (((uint32_t)(((uint32_t)(x)) << EARC_IER_TEMP_UPDATED_IE_SHIFT)) & EARC_IER_TEMP_UPDATED_IE_MASK)
/*! @} */

/*! @name ISR - Interrupt status register */
/*! @{ */

#define EARC_ISR_RX_CMDC_RX_DATA_MASK            (0x1U)
#define EARC_ISR_RX_CMDC_RX_DATA_SHIFT           (0U)
/*! RX_CMDC_RX_DATA - Receiver mode CMDC Receive data */
#define EARC_ISR_RX_CMDC_RX_DATA(x)              (((uint32_t)(((uint32_t)(x)) << EARC_ISR_RX_CMDC_RX_DATA_SHIFT)) & EARC_ISR_RX_CMDC_RX_DATA_MASK)

#define EARC_ISR_RX_CMDC_RESP_TO_ERR_MASK        (0x4U)
#define EARC_ISR_RX_CMDC_RESP_TO_ERR_SHIFT       (2U)
/*! RX_CMDC_RESP_TO_ERR - Recevier mode CMDC Response timeout error */
#define EARC_ISR_RX_CMDC_RESP_TO_ERR(x)          (((uint32_t)(((uint32_t)(x)) << EARC_ISR_RX_CMDC_RESP_TO_ERR_SHIFT)) & EARC_ISR_RX_CMDC_RESP_TO_ERR_MASK)

#define EARC_ISR_CMDC_SPARE_INT_MASK             (0x100U)
#define EARC_ISR_CMDC_SPARE_INT_SHIFT            (8U)
/*! CMDC_SPARE_INT - Spare Interrupt */
#define EARC_ISR_CMDC_SPARE_INT(x)               (((uint32_t)(((uint32_t)(x)) << EARC_ISR_CMDC_SPARE_INT_SHIFT)) & EARC_ISR_CMDC_SPARE_INT_MASK)

#define EARC_ISR_HPD_TGL_MASK                    (0x8000U)
#define EARC_ISR_HPD_TGL_SHIFT                   (15U)
/*! HPD_TGL - HPD pin level change interrupt */
#define EARC_ISR_HPD_TGL(x)                      (((uint32_t)(((uint32_t)(x)) << EARC_ISR_HPD_TGL_SHIFT)) & EARC_ISR_HPD_TGL_MASK)

#define EARC_ISR_PA_PB_DET_MASK                  (0x10000U)
#define EARC_ISR_PA_PB_DET_SHIFT                 (16U)
/*! PA_PB_DET - PA PB detected in Compressed mode */
#define EARC_ISR_PA_PB_DET(x)                    (((uint32_t)(((uint32_t)(x)) << EARC_ISR_PA_PB_DET_SHIFT)) & EARC_ISR_PA_PB_DET_MASK)

#define EARC_ISR_DATA_BLK_REC_MASK               (0x20000U)
#define EARC_ISR_DATA_BLK_REC_SHIFT              (17U)
/*! DATA_BLK_REC - 60958 block of data received interrupt. */
#define EARC_ISR_DATA_BLK_REC(x)                 (((uint32_t)(((uint32_t)(x)) << EARC_ISR_DATA_BLK_REC_SHIFT)) & EARC_ISR_DATA_BLK_REC_MASK)

#define EARC_ISR_FMT_CHG_INT_MASK                (0x40000U)
#define EARC_ISR_FMT_CHG_INT_SHIFT               (18U)
/*! FMT_CHG_INT - Format Change interrupt. */
#define EARC_ISR_FMT_CHG_INT(x)                  (((uint32_t)(((uint32_t)(x)) << EARC_ISR_FMT_CHG_INT_SHIFT)) & EARC_ISR_FMT_CHG_INT_MASK)

#define EARC_ISR_DMAC_SPARE_INT_MASK             (0x80000U)
#define EARC_ISR_DMAC_SPARE_INT_SHIFT            (19U)
/*! DMAC_SPARE_INT - Spare Interrupt */
#define EARC_ISR_DMAC_SPARE_INT(x)               (((uint32_t)(((uint32_t)(x)) << EARC_ISR_DMAC_SPARE_INT_SHIFT)) & EARC_ISR_DMAC_SPARE_INT_MASK)

#define EARC_ISR_SET_SPDIF_RX_MODE_MASK          (0x100000U)
#define EARC_ISR_SET_SPDIF_RX_MODE_SHIFT         (20U)
/*! SET_SPDIF_RX_MODE - Interrupt to set up PHY and controller in SPDIF RX mode. */
#define EARC_ISR_SET_SPDIF_RX_MODE(x)            (((uint32_t)(((uint32_t)(x)) << EARC_ISR_SET_SPDIF_RX_MODE_SHIFT)) & EARC_ISR_SET_SPDIF_RX_MODE_MASK)

#define EARC_ISR_SET_SPDIF_TX_MODE_MASK          (0x200000U)
#define EARC_ISR_SET_SPDIF_TX_MODE_SHIFT         (21U)
/*! SET_SPDIF_TX_MODE - Interrupt to set up PHY and controller in SPDIF TX mode. */
#define EARC_ISR_SET_SPDIF_TX_MODE(x)            (((uint32_t)(((uint32_t)(x)) << EARC_ISR_SET_SPDIF_TX_MODE_SHIFT)) & EARC_ISR_SET_SPDIF_TX_MODE_MASK)

#define EARC_ISR_SET_ARC_CM_INT_MASK             (0x400000U)
#define EARC_ISR_SET_ARC_CM_INT_SHIFT            (22U)
/*! SET_ARC_CM_INT - Interrupt enable to set up PHY as Common mode ARC receiver */
#define EARC_ISR_SET_ARC_CM_INT(x)               (((uint32_t)(((uint32_t)(x)) << EARC_ISR_SET_ARC_CM_INT_SHIFT)) & EARC_ISR_SET_ARC_CM_INT_MASK)

#define EARC_ISR_SET_ARC_SE_INT_MASK             (0x800000U)
#define EARC_ISR_SET_ARC_SE_INT_SHIFT            (23U)
/*! SET_ARC_SE_INT - Interrupt enable to set up PHY as Single ended mode ARC receiver */
#define EARC_ISR_SET_ARC_SE_INT(x)               (((uint32_t)(((uint32_t)(x)) << EARC_ISR_SET_ARC_SE_INT_SHIFT)) & EARC_ISR_SET_ARC_SE_INT_MASK)

#define EARC_ISR_SW_HPD_TGL_INT_MASK             (0x1000000U)
#define EARC_ISR_SW_HPD_TGL_INT_SHIFT            (24U)
/*! SW_HPD_TGL_INT - Interrupt enable to set up PHY as Single ended mode ARC receiver */
#define EARC_ISR_SW_HPD_TGL_INT(x)               (((uint32_t)(((uint32_t)(x)) << EARC_ISR_SW_HPD_TGL_INT_SHIFT)) & EARC_ISR_SW_HPD_TGL_INT_MASK)

#define EARC_ISR_TEMP_UPDATED_MASK               (0x2000000U)
#define EARC_ISR_TEMP_UPDATED_SHIFT              (25U)
/*! TEMP_UPDATED - Interrupt to indicate new temperature value is available. */
#define EARC_ISR_TEMP_UPDATED(x)                 (((uint32_t)(((uint32_t)(x)) << EARC_ISR_TEMP_UPDATED_SHIFT)) & EARC_ISR_TEMP_UPDATED_MASK)
/*! @} */

/*! @name PHY_AI_CTRL - AI interface control register */
/*! @{ */

#define EARC_PHY_AI_CTRL_AI_ADDR_MASK            (0xFFU)
#define EARC_PHY_AI_CTRL_AI_ADDR_SHIFT           (0U)
/*! AI_ADDR - AI ADDR value */
#define EARC_PHY_AI_CTRL_AI_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_CTRL_AI_ADDR_SHIFT)) & EARC_PHY_AI_CTRL_AI_ADDR_MASK)

#define EARC_PHY_AI_CTRL_AI_RESETN_MASK          (0x8000U)
#define EARC_PHY_AI_CTRL_AI_RESETN_SHIFT         (15U)
/*! AI_RESETN - AI reset bit */
#define EARC_PHY_AI_CTRL_AI_RESETN(x)            (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_CTRL_AI_RESETN_SHIFT)) & EARC_PHY_AI_CTRL_AI_RESETN_MASK)

#define EARC_PHY_AI_CTRL_TOG_0_MASK              (0x1000000U)
#define EARC_PHY_AI_CTRL_TOG_0_SHIFT             (24U)
/*! TOG_0 - AI toggle bit */
#define EARC_PHY_AI_CTRL_TOG_0(x)                (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_CTRL_TOG_0_SHIFT)) & EARC_PHY_AI_CTRL_TOG_0_MASK)

#define EARC_PHY_AI_CTRL_TOG_DONE_0_MASK         (0x2000000U)
#define EARC_PHY_AI_CTRL_TOG_DONE_0_SHIFT        (25U)
/*! TOG_DONE_0 - AI toggle done bit */
#define EARC_PHY_AI_CTRL_TOG_DONE_0(x)           (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_CTRL_TOG_DONE_0_SHIFT)) & EARC_PHY_AI_CTRL_TOG_DONE_0_MASK)

#define EARC_PHY_AI_CTRL_TOG_1_MASK              (0x4000000U)
#define EARC_PHY_AI_CTRL_TOG_1_SHIFT             (26U)
/*! TOG_1 - AI toggle bit */
#define EARC_PHY_AI_CTRL_TOG_1(x)                (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_CTRL_TOG_1_SHIFT)) & EARC_PHY_AI_CTRL_TOG_1_MASK)

#define EARC_PHY_AI_CTRL_TOG_DONE_1_MASK         (0x8000000U)
#define EARC_PHY_AI_CTRL_TOG_DONE_1_SHIFT        (27U)
/*! TOG_DONE_1 - AI toggle done bit */
#define EARC_PHY_AI_CTRL_TOG_DONE_1(x)           (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_CTRL_TOG_DONE_1_SHIFT)) & EARC_PHY_AI_CTRL_TOG_DONE_1_MASK)

#define EARC_PHY_AI_CTRL_AI_RWB_MASK             (0x80000000U)
#define EARC_PHY_AI_CTRL_AI_RWB_SHIFT            (31U)
/*! AI_RWB - AI Read / write control bit */
#define EARC_PHY_AI_CTRL_AI_RWB(x)               (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_CTRL_AI_RWB_SHIFT)) & EARC_PHY_AI_CTRL_AI_RWB_MASK)
/*! @} */

/*! @name PHY_AI_WDATA - AI interface WDATA register */
/*! @{ */

#define EARC_PHY_AI_WDATA_WDATA_MASK             (0xFFFFFFFFU)
#define EARC_PHY_AI_WDATA_WDATA_SHIFT            (0U)
/*! WDATA - Write data */
#define EARC_PHY_AI_WDATA_WDATA(x)               (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_WDATA_WDATA_SHIFT)) & EARC_PHY_AI_WDATA_WDATA_MASK)
/*! @} */

/*! @name PHY_AI_RDATA - AI interface RDATA register */
/*! @{ */

#define EARC_PHY_AI_RDATA_RDATA_MASK             (0xFFFFFFFFU)
#define EARC_PHY_AI_RDATA_RDATA_SHIFT            (0U)
/*! RDATA - Read data */
#define EARC_PHY_AI_RDATA_RDATA(x)               (((uint32_t)(((uint32_t)(x)) << EARC_PHY_AI_RDATA_RDATA_SHIFT)) & EARC_PHY_AI_RDATA_RDATA_MASK)
/*! @} */

/*! @name DPATH_STATUS - Audio XCVR datapath status */
/*! @{ */

#define EARC_DPATH_STATUS_RX_FRM_CNT_MASK        (0xFFU)
#define EARC_DPATH_STATUS_RX_FRM_CNT_SHIFT       (0U)
/*! RX_FRM_CNT - Count of received frames in a block */
#define EARC_DPATH_STATUS_RX_FRM_CNT(x)          (((uint32_t)(((uint32_t)(x)) << EARC_DPATH_STATUS_RX_FRM_CNT_SHIFT)) & EARC_DPATH_STATUS_RX_FRM_CNT_MASK)

#define EARC_DPATH_STATUS_TX_FRM_CNT_MASK        (0xFF00U)
#define EARC_DPATH_STATUS_TX_FRM_CNT_SHIFT       (8U)
/*! TX_FRM_CNT - Count of transmitted frames in a block */
#define EARC_DPATH_STATUS_TX_FRM_CNT(x)          (((uint32_t)(((uint32_t)(x)) << EARC_DPATH_STATUS_TX_FRM_CNT_SHIFT)) & EARC_DPATH_STATUS_TX_FRM_CNT_MASK)
/*! @} */

/*! @name RX_CMDC_CTRL - CMDC receiver control register */
/*! @{ */

#define EARC_RX_CMDC_CTRL_COMMA_BITS_MASK        (0x1FU)
#define EARC_RX_CMDC_CTRL_COMMA_BITS_SHIFT       (0U)
/*! COMMA_BITS - Number of repeating bits in COMMA pattern */
#define EARC_RX_CMDC_CTRL_COMMA_BITS(x)          (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_CTRL_COMMA_BITS_SHIFT)) & EARC_RX_CMDC_CTRL_COMMA_BITS_MASK)

#define EARC_RX_CMDC_CTRL_COMMA_EN_MASK          (0x80U)
#define EARC_RX_CMDC_CTRL_COMMA_EN_SHIFT         (7U)
/*! COMMA_EN - Enables COMMA pattern generation */
#define EARC_RX_CMDC_CTRL_COMMA_EN(x)            (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_CTRL_COMMA_EN_SHIFT)) & EARC_RX_CMDC_CTRL_COMMA_EN_MASK)

#define EARC_RX_CMDC_CTRL_RESPONSE_TIME_MASK     (0x1F00U)
#define EARC_RX_CMDC_CTRL_RESPONSE_TIME_SHIFT    (8U)
/*! RESPONSE_TIME - Transmitter response timeout to a received message */
#define EARC_RX_CMDC_CTRL_RESPONSE_TIME(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_CTRL_RESPONSE_TIME_SHIFT)) & EARC_RX_CMDC_CTRL_RESPONSE_TIME_MASK)

#define EARC_RX_CMDC_CTRL_TURNOVER_TIME_MASK     (0xF0000U)
#define EARC_RX_CMDC_CTRL_TURNOVER_TIME_SHIFT    (16U)
/*! TURNOVER_TIME - Minimum time before a response is generated */
#define EARC_RX_CMDC_CTRL_TURNOVER_TIME(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_CTRL_TURNOVER_TIME_SHIFT)) & EARC_RX_CMDC_CTRL_TURNOVER_TIME_MASK)

#define EARC_RX_CMDC_CTRL_TX_DRIVE_STOP_MASK     (0x700000U)
#define EARC_RX_CMDC_CTRL_TX_DRIVE_STOP_SHIFT    (20U)
/*! TX_DRIVE_STOP - Transmitter bus release time */
#define EARC_RX_CMDC_CTRL_TX_DRIVE_STOP(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_CTRL_TX_DRIVE_STOP_SHIFT)) & EARC_RX_CMDC_CTRL_TX_DRIVE_STOP_MASK)

#define EARC_RX_CMDC_CTRL_LBACK_EN_MASK          (0x80000000U)
#define EARC_RX_CMDC_CTRL_LBACK_EN_SHIFT         (31U)
/*! LBACK_EN - Loopback enable */
#define EARC_RX_CMDC_CTRL_LBACK_EN(x)            (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_CTRL_LBACK_EN_SHIFT)) & EARC_RX_CMDC_CTRL_LBACK_EN_MASK)
/*! @} */

/*! @name RX_CMDC_STATUS - eARC receiver CMDC status */
/*! @{ */

#define EARC_RX_CMDC_STATUS_CMDC_STATE_MASK      (0xF0000U)
#define EARC_RX_CMDC_STATUS_CMDC_STATE_SHIFT     (16U)
/*! CMDC_STATE - Current state of the RX CDMC control state machine */
#define EARC_RX_CMDC_STATUS_CMDC_STATE(x)        (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_STATUS_CMDC_STATE_SHIFT)) & EARC_RX_CMDC_STATUS_CMDC_STATE_MASK)
/*! @} */

/*! @name RX_CMDC_TX_DATA - CMDC transmit data register */
/*! @{ */

#define EARC_RX_CMDC_TX_DATA_TX_DATA_MASK        (0x3FFFFFFU)
#define EARC_RX_CMDC_TX_DATA_TX_DATA_SHIFT       (0U)
/*! TX_DATA - Transmit data */
#define EARC_RX_CMDC_TX_DATA_TX_DATA(x)          (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_TX_DATA_TX_DATA_SHIFT)) & EARC_RX_CMDC_TX_DATA_TX_DATA_MASK)

#define EARC_RX_CMDC_TX_DATA_DATA_VALID_MASK     (0x80000000U)
#define EARC_RX_CMDC_TX_DATA_DATA_VALID_SHIFT    (31U)
/*! DATA_VALID - Transmit Data Valid */
#define EARC_RX_CMDC_TX_DATA_DATA_VALID(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_TX_DATA_DATA_VALID_SHIFT)) & EARC_RX_CMDC_TX_DATA_DATA_VALID_MASK)
/*! @} */

/*! @name RX_CMDC_RX_DATA - CMDC receive data register */
/*! @{ */

#define EARC_RX_CMDC_RX_DATA_RX_DATA_MASK        (0x3FFFFFFU)
#define EARC_RX_CMDC_RX_DATA_RX_DATA_SHIFT       (0U)
/*! RX_DATA - Receive data */
#define EARC_RX_CMDC_RX_DATA_RX_DATA(x)          (((uint32_t)(((uint32_t)(x)) << EARC_RX_CMDC_RX_DATA_RX_DATA_SHIFT)) & EARC_RX_CMDC_RX_DATA_RX_DATA_MASK)
/*! @} */

/*! @name RX_DATAPATH_CTRL - Data path control register */
/*! @{ */

#define EARC_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_MASK (0x1U)
#define EARC_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_SHIFT (0U)
#define EARC_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS(x) (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_SHIFT)) & EARC_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_MASK)

#define EARC_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_MASK (0x8U)
#define EARC_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_SHIFT (3U)
/*! ECC_VUC_BITS_EN - RX_DATAPATH: Enable VUC bit replacement after ECC correction. */
#define EARC_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN(x) (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_SHIFT)) & EARC_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_MASK)

#define EARC_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_MASK (0x10U)
#define EARC_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_SHIFT (4U)
/*! EN_COMP_PARITY_CALC - RX_DATAPATH: Enable Compressed mode Parity calculation. */
#define EARC_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC(x) (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_SHIFT)) & EARC_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_MASK)

#define EARC_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_MASK (0x20U)
#define EARC_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_SHIFT (5U)
/*! RST_PKT_CNT_FIFO - Resets the packet count fifo. */
#define EARC_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO(x) (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_SHIFT)) & EARC_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_MASK)

#define EARC_RX_DATAPATH_CTRL_STORE_FMT_MASK     (0x40U)
#define EARC_RX_DATAPATH_CTRL_STORE_FMT_SHIFT    (6U)
/*! STORE_FMT - Receive Data store format. */
#define EARC_RX_DATAPATH_CTRL_STORE_FMT(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_STORE_FMT_SHIFT)) & EARC_RX_DATAPATH_CTRL_STORE_FMT_MASK)

#define EARC_RX_DATAPATH_CTRL_EN_PARITY_CALC_MASK (0x80U)
#define EARC_RX_DATAPATH_CTRL_EN_PARITY_CALC_SHIFT (7U)
/*! EN_PARITY_CALC - Enable Parity calculation. */
#define EARC_RX_DATAPATH_CTRL_EN_PARITY_CALC(x)  (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_EN_PARITY_CALC_SHIFT)) & EARC_RX_DATAPATH_CTRL_EN_PARITY_CALC_MASK)

#define EARC_RX_DATAPATH_CTRL_UDR_MASK           (0x100U)
#define EARC_RX_DATAPATH_CTRL_UDR_SHIFT          (8U)
/*! UDR - User data reset */
#define EARC_RX_DATAPATH_CTRL_UDR(x)             (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_UDR_SHIFT)) & EARC_RX_DATAPATH_CTRL_UDR_MASK)

#define EARC_RX_DATAPATH_CTRL_CSR_MASK           (0x200U)
#define EARC_RX_DATAPATH_CTRL_CSR_SHIFT          (9U)
/*! CSR - Channel Status reset */
#define EARC_RX_DATAPATH_CTRL_CSR(x)             (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_CSR_SHIFT)) & EARC_RX_DATAPATH_CTRL_CSR_MASK)

#define EARC_RX_DATAPATH_CTRL_UDA_MASK           (0x400U)
#define EARC_RX_DATAPATH_CTRL_UDA_SHIFT          (10U)
/*! UDA - User Data Acknowledge */
#define EARC_RX_DATAPATH_CTRL_UDA(x)             (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_UDA_SHIFT)) & EARC_RX_DATAPATH_CTRL_UDA_MASK)

#define EARC_RX_DATAPATH_CTRL_CSA_MASK           (0x800U)
#define EARC_RX_DATAPATH_CTRL_CSA_SHIFT          (11U)
/*! CSA - Channel Status Acknowledge */
#define EARC_RX_DATAPATH_CTRL_CSA(x)             (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_CSA_SHIFT)) & EARC_RX_DATAPATH_CTRL_CSA_MASK)

#define EARC_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK   (0x1000U)
#define EARC_RX_DATAPATH_CTRL_CLR_RX_FIFO_SHIFT  (12U)
/*! CLR_RX_FIFO - Clear Receive FIFO */
#define EARC_RX_DATAPATH_CTRL_CLR_RX_FIFO(x)     (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_CLR_RX_FIFO_SHIFT)) & EARC_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK)

#define EARC_RX_DATAPATH_CTRL_RX_DATA_FMT_MASK   (0xC000U)
#define EARC_RX_DATAPATH_CTRL_RX_DATA_FMT_SHIFT  (14U)
/*! RX_DATA_FMT - Indicates format of data stored in memory. */
#define EARC_RX_DATAPATH_CTRL_RX_DATA_FMT(x)     (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_RX_DATA_FMT_SHIFT)) & EARC_RX_DATAPATH_CTRL_RX_DATA_FMT_MASK)

#define EARC_RX_DATAPATH_CTRL_PABS_MASK          (0x80000U)
#define EARC_RX_DATAPATH_CTRL_PABS_SHIFT         (19U)
/*! PABS - Enable preamble search */
#define EARC_RX_DATAPATH_CTRL_PABS(x)            (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_PABS_SHIFT)) & EARC_RX_DATAPATH_CTRL_PABS_MASK)

#define EARC_RX_DATAPATH_CTRL_DTS_CDS_MASK       (0x100000U)
#define EARC_RX_DATAPATH_CTRL_DTS_CDS_SHIFT      (20U)
/*! DTS_CDS - Enable DTS CD 14 preamble search */
#define EARC_RX_DATAPATH_CTRL_DTS_CDS(x)         (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_DTS_CDS_SHIFT)) & EARC_RX_DATAPATH_CTRL_DTS_CDS_MASK)

#define EARC_RX_DATAPATH_CTRL_BLKC_MASK          (0x200000U)
#define EARC_RX_DATAPATH_CTRL_BLKC_SHIFT         (21U)
/*! BLKC - Block Compressed data */
#define EARC_RX_DATAPATH_CTRL_BLKC(x)            (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_BLKC_SHIFT)) & EARC_RX_DATAPATH_CTRL_BLKC_MASK)

#define EARC_RX_DATAPATH_CTRL_MUTE_CTRL_MASK     (0x400000U)
#define EARC_RX_DATAPATH_CTRL_MUTE_CTRL_SHIFT    (22U)
/*! MUTE_CTRL - M0+ mute request */
#define EARC_RX_DATAPATH_CTRL_MUTE_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_MUTE_CTRL_SHIFT)) & EARC_RX_DATAPATH_CTRL_MUTE_CTRL_MASK)

#define EARC_RX_DATAPATH_CTRL_MUTE_MODE_MASK     (0x800000U)
#define EARC_RX_DATAPATH_CTRL_MUTE_MODE_SHIFT    (23U)
/*! MUTE_MODE - Mute mode control */
#define EARC_RX_DATAPATH_CTRL_MUTE_MODE(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_MUTE_MODE_SHIFT)) & EARC_RX_DATAPATH_CTRL_MUTE_MODE_MASK)

#define EARC_RX_DATAPATH_CTRL_FMT_CHG_CTRL_MASK  (0x1000000U)
#define EARC_RX_DATAPATH_CTRL_FMT_CHG_CTRL_SHIFT (24U)
/*! FMT_CHG_CTRL - Format Change detection control. */
#define EARC_RX_DATAPATH_CTRL_FMT_CHG_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_FMT_CHG_CTRL_SHIFT)) & EARC_RX_DATAPATH_CTRL_FMT_CHG_CTRL_MASK)

#define EARC_RX_DATAPATH_CTRL_FMT_CHG_MODE_MASK  (0x2000000U)
#define EARC_RX_DATAPATH_CTRL_FMT_CHG_MODE_SHIFT (25U)
/*! FMT_CHG_MODE - Format change detected. Reset HW for next frame */
#define EARC_RX_DATAPATH_CTRL_FMT_CHG_MODE(x)    (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_FMT_CHG_MODE_SHIFT)) & EARC_RX_DATAPATH_CTRL_FMT_CHG_MODE_MASK)

#define EARC_RX_DATAPATH_CTRL_LAYB_CTRL_MASK     (0x4000000U)
#define EARC_RX_DATAPATH_CTRL_LAYB_CTRL_SHIFT    (26U)
/*! LAYB_CTRL - Layout B mode control */
#define EARC_RX_DATAPATH_CTRL_LAYB_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_LAYB_CTRL_SHIFT)) & EARC_RX_DATAPATH_CTRL_LAYB_CTRL_MASK)

#define EARC_RX_DATAPATH_CTRL_LAYB_MODE_MASK     (0x8000000U)
#define EARC_RX_DATAPATH_CTRL_LAYB_MODE_SHIFT    (27U)
/*! LAYB_MODE - Layout B */
#define EARC_RX_DATAPATH_CTRL_LAYB_MODE(x)       (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_LAYB_MODE_SHIFT)) & EARC_RX_DATAPATH_CTRL_LAYB_MODE_MASK)

#define EARC_RX_DATAPATH_CTRL_PRC_MASK           (0x10000000U)
#define EARC_RX_DATAPATH_CTRL_PRC_SHIFT          (28U)
/*! PRC - Process Compressed */
#define EARC_RX_DATAPATH_CTRL_PRC(x)             (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_PRC_SHIFT)) & EARC_RX_DATAPATH_CTRL_PRC_MASK)

#define EARC_RX_DATAPATH_CTRL_COMP_MASK          (0x20000000U)
#define EARC_RX_DATAPATH_CTRL_COMP_SHIFT         (29U)
/*! COMP - Compressed data search mode */
#define EARC_RX_DATAPATH_CTRL_COMP(x)            (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_COMP_SHIFT)) & EARC_RX_DATAPATH_CTRL_COMP_MASK)

#define EARC_RX_DATAPATH_CTRL_FSM_MASK           (0xC0000000U)
#define EARC_RX_DATAPATH_CTRL_FSM_SHIFT          (30U)
/*! FSM - IEC60958-1 Frame Synchronization Mode */
#define EARC_RX_DATAPATH_CTRL_FSM(x)             (((uint32_t)(((uint32_t)(x)) << EARC_RX_DATAPATH_CTRL_FSM_SHIFT)) & EARC_RX_DATAPATH_CTRL_FSM_MASK)
/*! @} */

/*! @name RX_CS_DATA_BITS - Channel staus bits */
/*! @{ */

#define EARC_RX_CS_DATA_BITS_CS_DATA_MASK        (0xFFFFFFFFU)
#define EARC_RX_CS_DATA_BITS_CS_DATA_SHIFT       (0U)
/*! CS_DATA - Channel Status bits */
#define EARC_RX_CS_DATA_BITS_CS_DATA(x)          (((uint32_t)(((uint32_t)(x)) << EARC_RX_CS_DATA_BITS_CS_DATA_SHIFT)) & EARC_RX_CS_DATA_BITS_CS_DATA_MASK)
/*! @} */

/*! @name RX_USER_DATA_BITS - User data bits */
/*! @{ */

#define EARC_RX_USER_DATA_BITS_U_DATA_MASK       (0xFFFFFFFFU)
#define EARC_RX_USER_DATA_BITS_U_DATA_SHIFT      (0U)
/*! U_DATA - User data bits */
#define EARC_RX_USER_DATA_BITS_U_DATA(x)         (((uint32_t)(((uint32_t)(x)) << EARC_RX_USER_DATA_BITS_U_DATA_SHIFT)) & EARC_RX_USER_DATA_BITS_U_DATA_MASK)
/*! @} */

/*! @name RX_DPATH_CNTR_CTRL - DMAC counter control register */
/*! @{ */

#define EARC_RX_DPATH_CNTR_CTRL_TS_EN_MASK       (0x1U)
#define EARC_RX_DPATH_CNTR_CTRL_TS_EN_SHIFT      (0U)
/*! TS_EN - Timestamp counter enable */
#define EARC_RX_DPATH_CNTR_CTRL_TS_EN(x)         (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_CNTR_CTRL_TS_EN_SHIFT)) & EARC_RX_DPATH_CNTR_CTRL_TS_EN_MASK)

#define EARC_RX_DPATH_CNTR_CTRL_TS_INC_MASK      (0x2U)
#define EARC_RX_DPATH_CNTR_CTRL_TS_INC_SHIFT     (1U)
/*! TS_INC - Timestamp Increment */
#define EARC_RX_DPATH_CNTR_CTRL_TS_INC(x)        (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_CNTR_CTRL_TS_INC_SHIFT)) & EARC_RX_DPATH_CNTR_CTRL_TS_INC_MASK)

#define EARC_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK (0x100U)
#define EARC_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT (8U)
/*! RST_BIT_CNTR - Reset bit counter. */
#define EARC_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR(x)  (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT)) & EARC_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK)

#define EARC_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK (0x200U)
#define EARC_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT (9U)
/*! RST_TS_CNTR - Reset timestamp counter. */
#define EARC_RX_DPATH_CNTR_CTRL_RST_TS_CNTR(x)   (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT)) & EARC_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK)
/*! @} */

/*! @name RX_DPATH_TSCR - Receive Datapath Timestamp Counter Register */
/*! @{ */

#define EARC_RX_DPATH_TSCR_CVAL_MASK             (0xFFFFFFFFU)
#define EARC_RX_DPATH_TSCR_CVAL_SHIFT            (0U)
/*! CVAL - Timestamp counter value */
#define EARC_RX_DPATH_TSCR_CVAL(x)               (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_TSCR_CVAL_SHIFT)) & EARC_RX_DPATH_TSCR_CVAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCR - Receive Datapath Bit counter register */
/*! @{ */

#define EARC_RX_DPATH_BCR_CVAL_MASK              (0xFFFFFFFFU)
#define EARC_RX_DPATH_BCR_CVAL_SHIFT             (0U)
/*! CVAL - Bit count value */
#define EARC_RX_DPATH_BCR_CVAL(x)                (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_BCR_CVAL_SHIFT)) & EARC_RX_DPATH_BCR_CVAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCTR - Receive datapath Bit count timestamp register. */
/*! @{ */

#define EARC_RX_DPATH_BCTR_BCT_VAL_MASK          (0xFFFFFFFFU)
#define EARC_RX_DPATH_BCTR_BCT_VAL_SHIFT         (0U)
/*! BCT_VAL - Bit count timestamp value */
#define EARC_RX_DPATH_BCTR_BCT_VAL(x)            (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_BCTR_BCT_VAL_SHIFT)) & EARC_RX_DPATH_BCTR_BCT_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCRR - Receive datapath Bit read timestamp register. */
/*! @{ */

#define EARC_RX_DPATH_BCRR_BCT_VAL_MASK          (0xFFFFFFFFU)
#define EARC_RX_DPATH_BCRR_BCT_VAL_SHIFT         (0U)
/*! BCT_VAL - Bit count timestamp value */
#define EARC_RX_DPATH_BCRR_BCT_VAL(x)            (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_BCRR_BCT_VAL_SHIFT)) & EARC_RX_DPATH_BCRR_BCT_VAL_MASK)
/*! @} */

/*! @name DMAC_PRE_MATCH_VAL - Preamble match value register */
/*! @{ */

#define EARC_DMAC_PRE_MATCH_VAL_PB_VAL_MASK      (0xFFFFU)
#define EARC_DMAC_PRE_MATCH_VAL_PB_VAL_SHIFT     (0U)
/*! PB_VAL - Preamble PB value */
#define EARC_DMAC_PRE_MATCH_VAL_PB_VAL(x)        (((uint32_t)(((uint32_t)(x)) << EARC_DMAC_PRE_MATCH_VAL_PB_VAL_SHIFT)) & EARC_DMAC_PRE_MATCH_VAL_PB_VAL_MASK)

#define EARC_DMAC_PRE_MATCH_VAL_PA_VAL_MASK      (0xFFFF0000U)
#define EARC_DMAC_PRE_MATCH_VAL_PA_VAL_SHIFT     (16U)
/*! PA_VAL - Preamble PA value */
#define EARC_DMAC_PRE_MATCH_VAL_PA_VAL(x)        (((uint32_t)(((uint32_t)(x)) << EARC_DMAC_PRE_MATCH_VAL_PA_VAL_SHIFT)) & EARC_DMAC_PRE_MATCH_VAL_PA_VAL_MASK)
/*! @} */

/*! @name DMAC_DTS_PRE_MATCH_VAL - Preamble match value register */
/*! @{ */

#define EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_MASK (0xFFFFU)
#define EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_SHIFT (0U)
/*! DTS_PB_VAL - Preamble PB value */
#define EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL(x) (((uint32_t)(((uint32_t)(x)) << EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_SHIFT)) & EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_MASK)

#define EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_MASK (0xFFFF0000U)
#define EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_SHIFT (16U)
/*! DTS_PA_VAL - Preamble PA value */
#define EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL(x) (((uint32_t)(((uint32_t)(x)) << EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_SHIFT)) & EARC_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_PRE_ERR - Error count for IEC60958-1 Block Synchronization. */
/*! @{ */

#define EARC_RX_DPATH_PRE_ERR_PRE_ERRS_MASK      (0xFFFFU)
#define EARC_RX_DPATH_PRE_ERR_PRE_ERRS_SHIFT     (0U)
/*! PRE_ERRS - Preamble Error counter */
#define EARC_RX_DPATH_PRE_ERR_PRE_ERRS(x)        (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_PRE_ERR_PRE_ERRS_SHIFT)) & EARC_RX_DPATH_PRE_ERR_PRE_ERRS_MASK)

#define EARC_RX_DPATH_PRE_ERR_CLEAR_MASK         (0x80000000U)
#define EARC_RX_DPATH_PRE_ERR_CLEAR_SHIFT        (31U)
/*! CLEAR - Clear bit for error counter. */
#define EARC_RX_DPATH_PRE_ERR_CLEAR(x)           (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_PRE_ERR_CLEAR_SHIFT)) & EARC_RX_DPATH_PRE_ERR_CLEAR_MASK)
/*! @} */

/*! @name RX_DPATH_PARITY_ERR - Parity Error count for IEC60958-1 Blocks. */
/*! @{ */

#define EARC_RX_DPATH_PARITY_ERR_PRE_ERRS_MASK   (0xFFFFU)
#define EARC_RX_DPATH_PARITY_ERR_PRE_ERRS_SHIFT  (0U)
/*! PRE_ERRS - Preamble Error counter */
#define EARC_RX_DPATH_PARITY_ERR_PRE_ERRS(x)     (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_PARITY_ERR_PRE_ERRS_SHIFT)) & EARC_RX_DPATH_PARITY_ERR_PRE_ERRS_MASK)

#define EARC_RX_DPATH_PARITY_ERR_CLEAR_MASK      (0x80000000U)
#define EARC_RX_DPATH_PARITY_ERR_CLEAR_SHIFT     (31U)
/*! CLEAR - Clear bit for error counter. */
#define EARC_RX_DPATH_PARITY_ERR_CLEAR(x)        (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_PARITY_ERR_CLEAR_SHIFT)) & EARC_RX_DPATH_PARITY_ERR_CLEAR_MASK)
/*! @} */

/*! @name RX_DPATH_PKT_CNT - Receive Data packet count. */
/*! @{ */

#define EARC_RX_DPATH_PKT_CNT_VAL_MASK           (0x7FFFFFFFU)
#define EARC_RX_DPATH_PKT_CNT_VAL_SHIFT          (0U)
/*! VAL - Data packet counter */
#define EARC_RX_DPATH_PKT_CNT_VAL(x)             (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_PKT_CNT_VAL_SHIFT)) & EARC_RX_DPATH_PKT_CNT_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_ONE_BIT_ERR_CNT - Receive Data packet Corrected error count. */
/*! @{ */

#define EARC_RX_DPATH_ONE_BIT_ERR_CNT_VAL_MASK   (0xFFFFU)
#define EARC_RX_DPATH_ONE_BIT_ERR_CNT_VAL_SHIFT  (0U)
#define EARC_RX_DPATH_ONE_BIT_ERR_CNT_VAL(x)     (((uint32_t)(((uint32_t)(x)) << EARC_RX_DPATH_ONE_BIT_ERR_CNT_VAL_SHIFT)) & EARC_RX_DPATH_ONE_BIT_ERR_CNT_VAL_MASK)
/*! @} */

/*! @name DMAC_PRE_MATCH_OFFSET - Preamble match offset value register */
/*! @{ */

#define EARC_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_MASK (0xFFFFFFFFU)
#define EARC_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_SHIFT (0U)
/*! PA_OFFSET - Sample count value for PA offset match */
#define EARC_DMAC_PRE_MATCH_OFFSET_PA_OFFSET(x)  (((uint32_t)(((uint32_t)(x)) << EARC_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_SHIFT)) & EARC_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_MASK)
/*! @} */

/*! @name TX_DATAPATH_CTRL - Transmit Data path control register */
/*! @{ */

#define EARC_TX_DATAPATH_CTRL_CS_ACK_MASK        (0x1U)
#define EARC_TX_DATAPATH_CTRL_CS_ACK_SHIFT       (0U)
/*! CS_ACK - Channel Status ACK */
#define EARC_TX_DATAPATH_CTRL_CS_ACK(x)          (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_CS_ACK_SHIFT)) & EARC_TX_DATAPATH_CTRL_CS_ACK_MASK)

#define EARC_TX_DATAPATH_CTRL_UD_ACK_MASK        (0x2U)
#define EARC_TX_DATAPATH_CTRL_UD_ACK_SHIFT       (1U)
/*! UD_ACK - User Data ACK */
#define EARC_TX_DATAPATH_CTRL_UD_ACK(x)          (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_UD_ACK_SHIFT)) & EARC_TX_DATAPATH_CTRL_UD_ACK_MASK)

#define EARC_TX_DATAPATH_CTRL_CS_MOD_MASK        (0x4U)
#define EARC_TX_DATAPATH_CTRL_CS_MOD_SHIFT       (2U)
/*! CS_MOD - Enable Channel Status insertion */
#define EARC_TX_DATAPATH_CTRL_CS_MOD(x)          (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_CS_MOD_SHIFT)) & EARC_TX_DATAPATH_CTRL_CS_MOD_MASK)

#define EARC_TX_DATAPATH_CTRL_UD_MOD_MASK        (0x8U)
#define EARC_TX_DATAPATH_CTRL_UD_MOD_SHIFT       (3U)
/*! UD_MOD - Enable User Data insertion */
#define EARC_TX_DATAPATH_CTRL_UD_MOD(x)          (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_UD_MOD_SHIFT)) & EARC_TX_DATAPATH_CTRL_UD_MOD_MASK)

#define EARC_TX_DATAPATH_CTRL_VLD_MOD_MASK       (0x10U)
#define EARC_TX_DATAPATH_CTRL_VLD_MOD_SHIFT      (4U)
/*! VLD_MOD - Enable Valid bit insertion */
#define EARC_TX_DATAPATH_CTRL_VLD_MOD(x)         (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_VLD_MOD_SHIFT)) & EARC_TX_DATAPATH_CTRL_VLD_MOD_MASK)

#define EARC_TX_DATAPATH_CTRL_FRM_VLD_MASK       (0x20U)
#define EARC_TX_DATAPATH_CTRL_FRM_VLD_SHIFT      (5U)
/*! FRM_VLD - Valid bit value */
#define EARC_TX_DATAPATH_CTRL_FRM_VLD(x)         (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_FRM_VLD_SHIFT)) & EARC_TX_DATAPATH_CTRL_FRM_VLD_MASK)

#define EARC_TX_DATAPATH_CTRL_EN_PARITY_MASK     (0x40U)
#define EARC_TX_DATAPATH_CTRL_EN_PARITY_SHIFT    (6U)
/*! EN_PARITY - Enable parity insertion */
#define EARC_TX_DATAPATH_CTRL_EN_PARITY(x)       (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_EN_PARITY_SHIFT)) & EARC_TX_DATAPATH_CTRL_EN_PARITY_MASK)

#define EARC_TX_DATAPATH_CTRL_EN_PREAMBLE_MASK   (0x80U)
#define EARC_TX_DATAPATH_CTRL_EN_PREAMBLE_SHIFT  (7U)
/*! EN_PREAMBLE - Enable preamble insertion */
#define EARC_TX_DATAPATH_CTRL_EN_PREAMBLE(x)     (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_EN_PREAMBLE_SHIFT)) & EARC_TX_DATAPATH_CTRL_EN_PREAMBLE_MASK)

#define EARC_TX_DATAPATH_CTRL_TX_CLK_RATE_MASK   (0x400U)
#define EARC_TX_DATAPATH_CTRL_TX_CLK_RATE_SHIFT  (10U)
/*! TX_CLK_RATE - This bit controls the TX clock rate. */
#define EARC_TX_DATAPATH_CTRL_TX_CLK_RATE(x)     (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_TX_CLK_RATE_SHIFT)) & EARC_TX_DATAPATH_CTRL_TX_CLK_RATE_MASK)

#define EARC_TX_DATAPATH_CTRL_FRM_FMT_MASK       (0x800U)
#define EARC_TX_DATAPATH_CTRL_FRM_FMT_SHIFT      (11U)
/*! FRM_FMT - Frame format of input data */
#define EARC_TX_DATAPATH_CTRL_FRM_FMT(x)         (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_FRM_FMT_SHIFT)) & EARC_TX_DATAPATH_CTRL_FRM_FMT_MASK)

#define EARC_TX_DATAPATH_CTRL_TX_FORMAT_MASK     (0x3000U)
#define EARC_TX_DATAPATH_CTRL_TX_FORMAT_SHIFT    (12U)
/*! TX_FORMAT - Transmit data format */
#define EARC_TX_DATAPATH_CTRL_TX_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_TX_FORMAT_SHIFT)) & EARC_TX_DATAPATH_CTRL_TX_FORMAT_MASK)

#define EARC_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK  (0x4000U)
#define EARC_TX_DATAPATH_CTRL_STRT_DATA_TX_SHIFT (14U)
/*! STRT_DATA_TX - Once Comma pattern is successively received, and heartbeat is detected, start TX of DMAC data. */
#define EARC_TX_DATAPATH_CTRL_STRT_DATA_TX(x)    (((uint32_t)(((uint32_t)(x)) << EARC_TX_DATAPATH_CTRL_STRT_DATA_TX_SHIFT)) & EARC_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK)
/*! @} */

/*! @name TX_CS_DATA_BITS - Channel staus bits */
/*! @{ */

#define EARC_TX_CS_DATA_BITS_CS_DATA_MASK        (0xFFFFFFFFU)
#define EARC_TX_CS_DATA_BITS_CS_DATA_SHIFT       (0U)
/*! CS_DATA - Channel Status bits / block */
#define EARC_TX_CS_DATA_BITS_CS_DATA(x)          (((uint32_t)(((uint32_t)(x)) << EARC_TX_CS_DATA_BITS_CS_DATA_SHIFT)) & EARC_TX_CS_DATA_BITS_CS_DATA_MASK)
/*! @} */

/*! @name TX_USER_DATA_BITS - User data bits */
/*! @{ */

#define EARC_TX_USER_DATA_BITS_U_DATA_MASK       (0xFFFFFFFFU)
#define EARC_TX_USER_DATA_BITS_U_DATA_SHIFT      (0U)
/*! U_DATA - User data bits/block */
#define EARC_TX_USER_DATA_BITS_U_DATA(x)         (((uint32_t)(((uint32_t)(x)) << EARC_TX_USER_DATA_BITS_U_DATA_SHIFT)) & EARC_TX_USER_DATA_BITS_U_DATA_MASK)
/*! @} */

/*! @name TX_DPATH_CNTR_CTRL - DMAC counter control register */
/*! @{ */

#define EARC_TX_DPATH_CNTR_CTRL_TS_EN_MASK       (0x1U)
#define EARC_TX_DPATH_CNTR_CTRL_TS_EN_SHIFT      (0U)
/*! TS_EN - Timestamp counter enable */
#define EARC_TX_DPATH_CNTR_CTRL_TS_EN(x)         (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_CNTR_CTRL_TS_EN_SHIFT)) & EARC_TX_DPATH_CNTR_CTRL_TS_EN_MASK)

#define EARC_TX_DPATH_CNTR_CTRL_TS_INC_MASK      (0x2U)
#define EARC_TX_DPATH_CNTR_CTRL_TS_INC_SHIFT     (1U)
/*! TS_INC - Timestamp Increment */
#define EARC_TX_DPATH_CNTR_CTRL_TS_INC(x)        (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_CNTR_CTRL_TS_INC_SHIFT)) & EARC_TX_DPATH_CNTR_CTRL_TS_INC_MASK)

#define EARC_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK (0x100U)
#define EARC_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT (8U)
/*! RST_BIT_CNTR - Reset bit counter. */
#define EARC_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR(x)  (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT)) & EARC_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK)

#define EARC_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK (0x200U)
#define EARC_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT (9U)
/*! RST_TS_CNTR - Reset timestamp counter. */
#define EARC_TX_DPATH_CNTR_CTRL_RST_TS_CNTR(x)   (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT)) & EARC_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK)
/*! @} */

/*! @name TX_DPATH_TSCR - Transmit Datapath Timestamp Counter Register */
/*! @{ */

#define EARC_TX_DPATH_TSCR_CVAL_MASK             (0xFFFFFFFFU)
#define EARC_TX_DPATH_TSCR_CVAL_SHIFT            (0U)
/*! CVAL - Timestamp counter value */
#define EARC_TX_DPATH_TSCR_CVAL(x)               (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_TSCR_CVAL_SHIFT)) & EARC_TX_DPATH_TSCR_CVAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCR - Transmit Datapath Bit counter register */
/*! @{ */

#define EARC_TX_DPATH_BCR_CVAL_MASK              (0xFFFFFFFFU)
#define EARC_TX_DPATH_BCR_CVAL_SHIFT             (0U)
/*! CVAL - Bit count value */
#define EARC_TX_DPATH_BCR_CVAL(x)                (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_BCR_CVAL_SHIFT)) & EARC_TX_DPATH_BCR_CVAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCTR - Transmit datapath Bit count timestamp register. */
/*! @{ */

#define EARC_TX_DPATH_BCTR_BCT_VAL_MASK          (0xFFFFFFFFU)
#define EARC_TX_DPATH_BCTR_BCT_VAL_SHIFT         (0U)
/*! BCT_VAL - Bit count timestamp value */
#define EARC_TX_DPATH_BCTR_BCT_VAL(x)            (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_BCTR_BCT_VAL_SHIFT)) & EARC_TX_DPATH_BCTR_BCT_VAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCRR - Transmmit datapath Bit read timestamp register. */
/*! @{ */

#define EARC_TX_DPATH_BCRR_BCT_VAL_MASK          (0xFFFFFFFFU)
#define EARC_TX_DPATH_BCRR_BCT_VAL_SHIFT         (0U)
/*! BCT_VAL - Bit count timestamp value */
#define EARC_TX_DPATH_BCRR_BCT_VAL(x)            (((uint32_t)(((uint32_t)(x)) << EARC_TX_DPATH_BCRR_BCT_VAL_SHIFT)) & EARC_TX_DPATH_BCRR_BCT_VAL_MASK)
/*! @} */

/*! @name HPD_DBNC_CTRL - HPD Debounce Control Register */
/*! @{ */

#define EARC_HPD_DBNC_CTRL_VAL_MASK              (0xFFFFFFFFU)
#define EARC_HPD_DBNC_CTRL_VAL_SHIFT             (0U)
/*! VAL - HDP pin debounce interval */
#define EARC_HPD_DBNC_CTRL_VAL(x)                (((uint32_t)(((uint32_t)(x)) << EARC_HPD_DBNC_CTRL_VAL_SHIFT)) & EARC_HPD_DBNC_CTRL_VAL_MASK)
/*! @} */

/*! @name TEMPERATURE - Chip Temperature for eARC PHY */
/*! @{ */

#define EARC_TEMPERATURE_VAL_MASK                (0xFFFFFFFFU)
#define EARC_TEMPERATURE_VAL_SHIFT               (0U)
/*! VAL - Temperature */
#define EARC_TEMPERATURE_VAL(x)                  (((uint32_t)(((uint32_t)(x)) << EARC_TEMPERATURE_VAL_SHIFT)) & EARC_TEMPERATURE_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EARC_Register_Masks */


/*!
 * @}
 */ /* end of group EARC_Peripheral_Access_Layer */


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


#endif  /* PERI_EARC_H_ */

