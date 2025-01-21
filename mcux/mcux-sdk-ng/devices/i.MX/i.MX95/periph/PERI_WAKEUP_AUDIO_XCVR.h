/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WAKEUP_AUDIO_XCVR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file WAKEUP_AUDIO_XCVR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for WAKEUP_AUDIO_XCVR
 *
 * CMSIS Peripheral Access Layer for WAKEUP_AUDIO_XCVR
 */

#if !defined(WAKEUP_AUDIO_XCVR_H_)
#define WAKEUP_AUDIO_XCVR_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- WAKEUP_AUDIO_XCVR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AUDIO_XCVR_Peripheral_Access_Layer WAKEUP_AUDIO_XCVR Peripheral Access Layer
 * @{
 */

/** WAKEUP_AUDIO_XCVR - Size of Registers Arrays */
#define WAKEUP_AUDIO_XCVR_RX_CS_DATA_BITS_COUNT   6u
#define WAKEUP_AUDIO_XCVR_RX_USER_DATA_BITS_COUNT 6u
#define WAKEUP_AUDIO_XCVR_TX_CS_DATA_BITS_COUNT   6u
#define WAKEUP_AUDIO_XCVR_TX_USER_DATA_BITS_COUNT 6u

/** WAKEUP_AUDIO_XCVR - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __IO uint32_t VERSION;                           /**< Version control register, offset: 0x800 */
       uint8_t RESERVED_1[12];
  struct {                                         /* offset: 0x810 */
    __IO uint32_t RW;                                /**< External control register, offset: 0x810 */
    __IO uint32_t SET;                               /**< External control register, offset: 0x814 */
    __IO uint32_t CLR;                               /**< External control register, offset: 0x818 */
    __IO uint32_t TOG;                               /**< External control register, offset: 0x81C */
  } EXT_CTRL;
  struct {                                         /* offset: 0x820 */
    __IO uint32_t RW;                                /**< External Status register, offset: 0x820 */
    __IO uint32_t SET;                               /**< External Status register, offset: 0x824 */
    __IO uint32_t CLR;                               /**< External Status register, offset: 0x828 */
    __IO uint32_t TOG;                               /**< External Status register, offset: 0x82C */
  } EXT_STATUS;
  struct {                                         /* offset: 0x830 */
    __IO uint32_t RW;                                /**< Interrupt enables for interrupt 0, offset: 0x830 */
    __IO uint32_t SET;                               /**< Interrupt enables for interrupt 0, offset: 0x834 */
    __IO uint32_t CLR;                               /**< Interrupt enables for interrupt 0, offset: 0x838 */
    __IO uint32_t TOG;                               /**< Interrupt enables for interrupt 0, offset: 0x83C */
  } EXT_IER0;
  struct {                                         /* offset: 0x840 */
    __IO uint32_t RW;                                /**< Interrupt enables for interrupt 1, offset: 0x840 */
    __IO uint32_t SET;                               /**< Interrupt enables for interrupt 1, offset: 0x844 */
    __IO uint32_t CLR;                               /**< Interrupt enables for interrupt 1, offset: 0x848 */
    __IO uint32_t TOG;                               /**< Interrupt enables for interrupt 1, offset: 0x84C */
  } EXT_IER1;
  struct {                                         /* offset: 0x850 */
    __IO uint32_t RW;                                /**< External Interrupt Status register, offset: 0x850 */
    __IO uint32_t SET;                               /**< External Interrupt Status register, offset: 0x854 */
    __IO uint32_t CLR;                               /**< External Interrupt Status register, offset: 0x858 */
    __IO uint32_t TOG;                               /**< External Interrupt Status register, offset: 0x85C */
  } EXT_ISR;
       uint8_t RESERVED_2[16];
  struct {                                         /* offset: 0x870 */
    __IO uint32_t RW;                                /**< Interrupt enable register for M0++, offset: 0x870 */
    __IO uint32_t SET;                               /**< Interrupt enable register for M0++, offset: 0x874 */
    __IO uint32_t CLR;                               /**< Interrupt enable register for M0++, offset: 0x878 */
    __IO uint32_t TOG;                               /**< Interrupt enable register for M0++, offset: 0x87C */
  } IER;
  struct {                                         /* offset: 0x880 */
    __IO uint32_t RW;                                /**< Interrupt status register, offset: 0x880 */
    __IO uint32_t SET;                               /**< Interrupt status register, offset: 0x884 */
    __IO uint32_t CLR;                               /**< Interrupt status register, offset: 0x888 */
    __IO uint32_t TOG;                               /**< Interrupt status register, offset: 0x88C */
  } ISR;
  struct {                                         /* offset: 0x890 */
    __IO uint32_t RW;                                /**< AI interface control register, offset: 0x890 */
    __IO uint32_t SET;                               /**< AI interface control register, offset: 0x894 */
    __IO uint32_t CLR;                               /**< AI interface control register, offset: 0x898 */
    __IO uint32_t TOG;                               /**< AI interface control register, offset: 0x89C */
  } PHY_AI_CTRL;
  __IO uint32_t PHY_AI_WDATA;                      /**< AI interface WDATA register, offset: 0x8A0 */
  __I  uint32_t PHY_AI_RDATA;                      /**< AI interface RDATA register, offset: 0x8A4 */
  __I  uint32_t DPATH_STATUS;                      /**< AUDIO XCVR datapath status, offset: 0x8A8 */
       uint8_t RESERVED_3[20];
  struct {                                         /* offset: 0x8C0 */
    __IO uint32_t RW;                                /**< CMDC receiver control register, offset: 0x8C0 */
    __IO uint32_t SET;                               /**< CMDC receiver control register, offset: 0x8C4 */
    __IO uint32_t CLR;                               /**< CMDC receiver control register, offset: 0x8C8 */
    __IO uint32_t TOG;                               /**< CMDC receiver control register, offset: 0x8CC */
  } RX_CMDC_CTRL;
  __I  uint32_t RX_CMDC_STATUS;                    /**< AUDIO_XCVR CMDC status, offset: 0x8D0 */
       uint8_t RESERVED_4[12];
  __IO uint32_t RX_CMDC_TX_DATA;                   /**< CMDC transmit data register, offset: 0x8E0 */
       uint8_t RESERVED_5[12];
  __IO uint32_t RX_CMDC_RX_DATA;                   /**< CMDC receive data register, offset: 0x8F0 */
       uint8_t RESERVED_6[140];
  struct {                                         /* offset: 0x980 */
    __IO uint32_t RW;                                /**< Data path control register, offset: 0x980 */
    __IO uint32_t SET;                               /**< Data path control register, offset: 0x984 */
    __IO uint32_t CLR;                               /**< Data path control register, offset: 0x988 */
    __IO uint32_t TOG;                               /**< Data path control register, offset: 0x98C */
  } RX_DATAPATH_CTRL;
  __I  uint32_t RX_CS_DATA_BITS[WAKEUP_AUDIO_XCVR_RX_CS_DATA_BITS_COUNT]; /**< Channel status bits, array offset: 0x990, array step: 0x4 */
  __I  uint32_t RX_USER_DATA_BITS[WAKEUP_AUDIO_XCVR_RX_USER_DATA_BITS_COUNT]; /**< User data bits, array offset: 0x9A8, array step: 0x4 */
  struct {                                         /* offset: 0x9C0 */
    __IO uint32_t RW;                                /**< DMAC counter control register, offset: 0x9C0 */
    __IO uint32_t SET;                               /**< DMAC counter control register, offset: 0x9C4 */
    __IO uint32_t CLR;                               /**< DMAC counter control register, offset: 0x9C8 */
    __IO uint32_t TOG;                               /**< DMAC counter control register, offset: 0x9CC */
  } RX_DPATH_CNTR_CTRL;
  __I  uint32_t RX_DPATH_TSCR;                     /**< Receive Datapath Timestamp Counter Register, offset: 0x9D0 */
  __I  uint32_t RX_DPATH_BCR;                      /**< Receive Datapath Bit counter register, offset: 0x9D4 */
  __I  uint32_t RX_DPATH_BCTR;                     /**< Receive datapath Bit count timestamp register., offset: 0x9D8 */
  __I  uint32_t RX_DPATH_BCRR;                     /**< Receive datapath Bit read timestamp register., offset: 0x9DC */
  struct {                                         /* offset: 0x9E0 */
    __IO uint32_t RW;                                /**< Preamble match value register, offset: 0x9E0 */
    __IO uint32_t SET;                               /**< Preamble match value register, offset: 0x9E4 */
    __IO uint32_t CLR;                               /**< Preamble match value register, offset: 0x9E8 */
    __IO uint32_t TOG;                               /**< Preamble match value register, offset: 0x9EC */
  } DMAC_PRE_MATCH_VAL;
  struct {                                         /* offset: 0x9F0 */
    __IO uint32_t RW;                                /**< Preamble match value register, offset: 0x9F0 */
    __IO uint32_t SET;                               /**< Preamble match value register, offset: 0x9F4 */
    __IO uint32_t CLR;                               /**< Preamble match value register, offset: 0x9F8 */
    __IO uint32_t TOG;                               /**< Preamble match value register, offset: 0x9FC */
  } DMAC_DTS_PRE_MATCH_VAL;
  __IO uint32_t RX_DPATH_PRE_ERR;                  /**< Error count for IEC60958-1 Block Synchronization., offset: 0xA00 */
  __IO uint32_t RX_DPATH_PARITY_ERR;               /**< Parity Error count for IEC60958-1 Blocks., offset: 0xA04 */
       uint8_t RESERVED_7[8];
  __I  uint32_t RX_DPATH_PKT_CNT;                  /**< Receive Data packet count., offset: 0xA10 */
  __I  uint32_t RX_DPATH_ONE_BIT_ERR_CNT;          /**< Receive Data packet Corrected error count., offset: 0xA14 */
  __I  uint32_t DMAC_PRE_MATCH_OFFSET;             /**< Preamble match offset value register, offset: 0xA18 */
       uint8_t RESERVED_8[4];
  struct {                                         /* offset: 0xA20 */
    __IO uint32_t RW;                                /**< Transmit Data path control register, offset: 0xA20 */
    __IO uint32_t SET;                               /**< Transmit Data path control register, offset: 0xA24 */
    __IO uint32_t CLR;                               /**< Transmit Data path control register, offset: 0xA28 */
    __IO uint32_t TOG;                               /**< Transmit Data path control register, offset: 0xA2C */
  } TX_DATAPATH_CTRL;
  __IO uint32_t TX_CS_DATA_BITS[WAKEUP_AUDIO_XCVR_TX_CS_DATA_BITS_COUNT]; /**< Channel status bits, array offset: 0xA30, array step: 0x4 */
  __IO uint32_t TX_USER_DATA_BITS[WAKEUP_AUDIO_XCVR_TX_USER_DATA_BITS_COUNT]; /**< User data bits, array offset: 0xA48, array step: 0x4 */
  struct {                                         /* offset: 0xA60 */
    __IO uint32_t RW;                                /**< DMAC counter control register, offset: 0xA60 */
    __IO uint32_t SET;                               /**< DMAC counter control register, offset: 0xA64 */
    __IO uint32_t CLR;                               /**< DMAC counter control register, offset: 0xA68 */
    __IO uint32_t TOG;                               /**< DMAC counter control register, offset: 0xA6C */
  } TX_DPATH_CNTR_CTRL;
  __I  uint32_t TX_DPATH_TSCR;                     /**< Transmit Datapath Timestamp Counter Register, offset: 0xA70 */
  __I  uint32_t TX_DPATH_BCR;                      /**< Transmit Datapath Bit counter register, offset: 0xA74 */
  __I  uint32_t TX_DPATH_BCTR;                     /**< Transmit datapath Bit count timestamp register., offset: 0xA78 */
  __I  uint32_t TX_DPATH_BCRR;                     /**< Transmit datapath Bit read timestamp register., offset: 0xA7C */
       uint8_t RESERVED_9[32];
  struct {                                         /* offset: 0xAA0 */
    __IO uint32_t RW;                                /**< HPD Debounce Control Register, offset: 0xAA0 */
    __IO uint32_t SET;                               /**< HPD Debounce Control Register, offset: 0xAA4 */
    __IO uint32_t CLR;                               /**< HPD Debounce Control Register, offset: 0xAA8 */
    __IO uint32_t TOG;                               /**< HPD Debounce Control Register, offset: 0xAAC */
  } HPD_DBNC_CTRL;
} WAKEUP_AUDIO_XCVR_Type;

/* ----------------------------------------------------------------------------
   -- WAKEUP_AUDIO_XCVR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AUDIO_XCVR_Register_Masks WAKEUP_AUDIO_XCVR Register Masks
 * @{
 */

/*! @name VERSION - Version control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_VERSION_VERID_MASK     (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_VERSION_VERID_SHIFT    (0U)
/*! VERID - Version ID */
#define WAKEUP_AUDIO_XCVR_VERSION_VERID(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_VERSION_VERID_SHIFT)) & WAKEUP_AUDIO_XCVR_VERSION_VERID_MASK)
/*! @} */

/*! @name EXT_CTRL - External control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_MASK (0x7FU)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_SHIFT (0U)
/*! TX_FIFO_WMARK - Audio Transmit FIFO Watermark Level */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_MASK (0x7F00U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_SHIFT (8U)
/*! RX_FIFO_WMARK - Audio Receive FIFO Watermark Level */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_FABRIC_RR_SEL_MASK (0x8000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_FABRIC_RR_SEL_SHIFT (15U)
/*! FABRIC_RR_SEL - Selects Arbitration mode of crossbar switch. */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_FABRIC_RR_SEL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_FABRIC_RR_SEL_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_FABRIC_RR_SEL_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_PAGE_MASK     (0xF0000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_PAGE_SHIFT    (16U)
/*! PAGE - Page Select. */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_PAGE(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_PAGE_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_PAGE_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_MASK (0x200000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_SHIFT (21U)
/*! CORE_SLEEP_HOLD_REQ_B - Hold core from going to sleep mode when 0. */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_SLEEP_HOLD_REQ_B_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_WAIT_MASK (0x400000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_WAIT_SHIFT (22U)
/*! CORE_WAIT - Stop executing code */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_WAIT(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_WAIT_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_WAIT_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SPDIF_MODE_MASK (0x800000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SPDIF_MODE_SHIFT (23U)
/*! SPDIF_MODE - Indicates SPDIF output mode. */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SPDIF_MODE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_SPDIF_MODE_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_SPDIF_MODE_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_MASK (0x1000000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_SHIFT (24U)
/*! SDMA_WR_REQ_DIS - SDMA WR REQ disable */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_MASK (0x2000000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_SHIFT (25U)
/*! SDMA_RD_REQ_DIS - SDMA RD REQ disable */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_MASK (0x8000000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_SHIFT (27U)
/*! TX_DPATH_RESET - Soft reset to the Datapath for Transmit */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_MASK (0x10000000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_SHIFT (28U)
/*! RX_DPATH_RESET - Soft reset to the AUDIO_XCVR Differential data Receiver */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_CMDC_RESET_MASK (0x20000000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_CMDC_RESET_SHIFT (29U)
/*! TX_CMDC_RESET - Soft reset to the AUDIO_XCVR Common mode Transmitter */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_CMDC_RESET(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_CMDC_RESET_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_TX_CMDC_RESET_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_CMDC_RESET_MASK (0x40000000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_CMDC_RESET_SHIFT (30U)
/*! RX_CMDC_RESET - Soft reset to the AUDIO_XCVR Common mode Receiver */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_CMDC_RESET(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_CMDC_RESET_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_RX_CMDC_RESET_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_RESET_MASK (0x80000000U)
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_RESET_SHIFT (31U)
/*! CORE_RESET - M0+ Reset */
#define WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_RESET(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_RESET_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_CTRL_CORE_RESET_MASK)
/*! @} */

/*! @name EXT_STATUS - External Status register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_MASK (0xFFU)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_SHIFT (0U)
/*! NO_TX_FIFO_ENTRIES - TX FIFO entries */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_MASK (0xFF00U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_SHIFT (8U)
/*! NO_RX_FIFO_ENTRIES - RX FIFO entries */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEPING_MASK (0x10000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEPING_SHIFT (16U)
/*! CM0_SLEEPING - CM0 is in Sleep mode. */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEPING(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEPING_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEPING_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_DEEP_SLEEP_MASK (0x20000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_DEEP_SLEEP_SHIFT (17U)
/*! CM0_DEEP_SLEEP - CM0 is in deep sleep mode. */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_DEEP_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_DEEP_SLEEP_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_DEEP_SLEEP_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_MASK (0x40000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_SHIFT (18U)
/*! CM0_SLEEP_HOLD_ACK_B - Sleep extension acknowledge. */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_CM0_SLEEP_HOLD_ACK_B_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_MASK (0x200000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_SHIFT (21U)
/*! TX_PIPE_EMPTY - Indicates TX pipe status. */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_RESP_TO_MASK (0x800000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_RESP_TO_SHIFT (23U)
/*! RX_CMDC_RESP_TO - CMDC Response not sent in programmed time */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_RESP_TO(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_RESP_TO_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_RESP_TO_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_COMMA_TO_MASK (0x2000000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_COMMA_TO_SHIFT (25U)
/*! RX_CMDC_COMMA_TO - Receiver CMDC comma timeout Interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_COMMA_TO(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_COMMA_TO_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_RX_CMDC_COMMA_TO_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_HEARTBEAT_STATUS_MASK (0x8000000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_HEARTBEAT_STATUS_SHIFT (27U)
/*! HEARTBEAT_STATUS - AUDIO_XCVR Connection Status */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_HEARTBEAT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_HEARTBEAT_STATUS_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_HEARTBEAT_STATUS_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD4_REC_MASK (0x10000000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD4_REC_SHIFT (28U)
/*! NEW_UD4_REC - New user data */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD4_REC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD4_REC_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD4_REC_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD5_REC_MASK (0x20000000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD5_REC_SHIFT (29U)
/*! NEW_UD5_REC - New user data */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD5_REC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD5_REC_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD5_REC_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD6_REC_MASK (0x40000000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD6_REC_SHIFT (30U)
/*! NEW_UD6_REC - New user data */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD6_REC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD6_REC_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_NEW_UD6_REC_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_STATUS_HPD_I_MASK  (0x80000000U)
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_HPD_I_SHIFT (31U)
/*! HPD_I - HPD Input status */
#define WAKEUP_AUDIO_XCVR_EXT_STATUS_HPD_I(x)    (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_STATUS_HPD_I_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_STATUS_HPD_I_MASK)
/*! @} */

/*! @name EXT_IER0 - Interrupt enables for interrupt 0 */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_MASK (0x1U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_SHIFT (0U)
/*! NEW_CS_IE_0 - Enable for New channel status block received interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_UD_IE_0_MASK (0x2U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_UD_IE_0_SHIFT (1U)
/*! NEW_UD_IE_0 - Enable for new user data received interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_UD_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_UD_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_UD_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_MUTE_IE_0_MASK (0x4U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_MUTE_IE_0_SHIFT (2U)
/*! MUTE_IE_0 - Enable for Mute detected interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_MUTE_IE_0(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_MUTE_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_MUTE_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_RESP_TO_IE_0_MASK (0x8U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_RESP_TO_IE_0_SHIFT (3U)
/*! CMDC_RESP_TO_IE_0 - Receiver CMDC data response timeout interrupt enable */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_RESP_TO_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_RESP_TO_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_RESP_TO_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_ECC_ERR_IE_0_MASK (0x10U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_ECC_ERR_IE_0_SHIFT (4U)
/*! ECC_ERR_IE_0 - 60958 Compressed data uncorrectable error interrupt enable */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_ECC_ERR_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_ECC_ERR_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_ECC_ERR_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_MASK (0x20U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_SHIFT (5U)
/*! PREAMBLE_MISMATCH_IE_0 - Preamble mismatch interrupt enable. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_MASK (0x40U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR_IE_0 - Receive FIFO overflow error interrupt enable. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_OHPD_IE_0_MASK (0x100U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_OHPD_IE_0_SHIFT (8U)
/*! OHPD_IE_0 - Output HPD interrupt enable. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_OHPD_IE_0(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_OHPD_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_OHPD_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_NO_DATA_REC_IE_0_MASK (0x200U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_NO_DATA_REC_IE_0_SHIFT (9U)
/*! DMAC_NO_DATA_REC_IE_0 - Indicates no DMAC data is received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_NO_DATA_REC_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_NO_DATA_REC_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_NO_DATA_REC_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_MASK (0x400U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_SHIFT (10U)
/*! DMAC_FMT_CHG_DET_IE_0 - Indicates DMAC format change was detected */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_FMT_CHG_DET_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_FMT_CHG_DET_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_HB_STATE_CHG_IE_0_MASK (0x800U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_HB_STATE_CHG_IE_0_SHIFT (11U)
/*! HB_STATE_CHG_IE_0 - Interrupt enable for Heartbeat status change */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_HB_STATE_CHG_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_HB_STATE_CHG_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_HB_STATE_CHG_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_MASK (0x1000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_SHIFT (12U)
/*! CMDC_STATUS_UPDATE_IE_0 - Interrupt enable for CMDC status register update. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_STATUS_UPDATE_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_CMDC_STATUS_UPDATE_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_TEMP_UPDATE_IE_0_MASK (0x2000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_TEMP_UPDATE_IE_0_SHIFT (13U)
/*! TEMP_UPDATE_IE_0 - Update request for chip temperature value. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_TEMP_UPDATE_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_TEMP_UPDATE_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_TEMP_UPDATE_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_MASK (0x4000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_SHIFT (14U)
/*! DMA_RD_REQ_IE_0 - Request to read data from FIFO. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_MASK (0x8000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_SHIFT (15U)
/*! DMA_WR_REQ_IE_0 - Request to write data to FIFO. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_RX_BME_ERR_IE_0_MASK (0x10000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_RX_BME_ERR_IE_0_SHIFT (16U)
/*! DMAC_RX_BME_ERR_IE_0 - Bi-phase mark encoding error */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_RX_BME_ERR_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_RX_BME_ERR_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_DMAC_RX_BME_ERR_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_MASK (0x20000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_SHIFT (17U)
/*! PREAMBLE_MATCH_IE_0 - Interrupt enable for preamble match received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_MASK (0x40000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_SHIFT (18U)
/*! M_W_PRE_MISMATCH_IE_0 - Interrupt enable for sub-frame M/W preamble mismatch received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_MASK (0x80000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_SHIFT (19U)
/*! B_PRE_MISMATCH_IE_0 - Interrupt enable for sub-frame B preamble mismatch received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_MASK (0x100000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_SHIFT (20U)
/*! UNEXP_PRE_REC_IE_0 - Interrupt enable for unexpected preamble received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_CH_UD_OFLOW_IE_0_MASK (0x400000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_CH_UD_OFLOW_IE_0_SHIFT (22U)
/*! CH_UD_OFLOW_IE_0 - Channel status or used data could not be stored. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_CH_UD_OFLOW_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_CH_UD_OFLOW_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_CH_UD_OFLOW_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_MASK (0x800000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_SHIFT (23U)
/*! NEW_BLK_RCVD_IE_0 - New block of data was received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER0_SPARE_IE_0_MASK (0xFF000000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER0_SPARE_IE_0_SHIFT (24U)
/*! SPARE_IE_0 - Spare interrupts */
#define WAKEUP_AUDIO_XCVR_EXT_IER0_SPARE_IE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER0_SPARE_IE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER0_SPARE_IE_0_MASK)
/*! @} */

/*! @name EXT_IER1 - Interrupt enables for interrupt 1 */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_MASK (0x1U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_SHIFT (0U)
/*! NEW_CS_IE_1 - Enable for New channel status block received interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_UD_IE_1_MASK (0x2U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_UD_IE_1_SHIFT (1U)
/*! NEW_UD_IE_1 - Enable for new user data received interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_UD_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_UD_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_UD_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_MUTE_IE_1_MASK (0x4U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_MUTE_IE_1_SHIFT (2U)
/*! MUTE_IE_1 - Enable for Mute detected interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_MUTE_IE_1(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_MUTE_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_MUTE_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_RESP_TO_IE_1_MASK (0x8U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_RESP_TO_IE_1_SHIFT (3U)
/*! CMDC_RESP_TO_IE_1 - Receiver CMDC data response timeout interrupt enable */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_RESP_TO_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_RESP_TO_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_RESP_TO_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_ECC_ERR_IE_1_MASK (0x10U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_ECC_ERR_IE_1_SHIFT (4U)
/*! ECC_ERR_IE_1 - 60958 Compressed data uncorrectable error interrupt enable */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_ECC_ERR_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_ECC_ERR_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_ECC_ERR_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_MASK (0x20U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_SHIFT (5U)
/*! PREAMBLE_MISMATCH_IE_1 - Preamble mismatch interrupt enable. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_MASK (0x40U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR_IE_1 - Receive FIFO overflow error interrupt enable. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_OHPD_IE_1_MASK (0x100U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_OHPD_IE_1_SHIFT (8U)
/*! OHPD_IE_1 - Output HPD interrupt enable. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_OHPD_IE_1(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_OHPD_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_OHPD_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_NO_DATA_REC_IE_1_MASK (0x200U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_NO_DATA_REC_IE_1_SHIFT (9U)
/*! DMAC_NO_DATA_REC_IE_1 - Indicates no DMAC data is received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_NO_DATA_REC_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_NO_DATA_REC_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_NO_DATA_REC_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_MASK (0x400U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_SHIFT (10U)
/*! DMAC_FMT_CHG_DET_IE_1 - Indicates DMAC format change was detected */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_FMT_CHG_DET_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_FMT_CHG_DET_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_HB_STATE_CHG_IE_1_MASK (0x800U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_HB_STATE_CHG_IE_1_SHIFT (11U)
/*! HB_STATE_CHG_IE_1 - Interrupt enable for Heartbeat status change */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_HB_STATE_CHG_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_HB_STATE_CHG_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_HB_STATE_CHG_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_MASK (0x1000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_SHIFT (12U)
/*! CMDC_STATUS_UPDATE_IE_1 - Interrupt enable for CMDC status register update. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_STATUS_UPDATE_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_CMDC_STATUS_UPDATE_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_TEMP_UPDATE_IE_1_MASK (0x2000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_TEMP_UPDATE_IE_1_SHIFT (13U)
/*! TEMP_UPDATE_IE_1 - Update request for chip temperature value. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_TEMP_UPDATE_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_TEMP_UPDATE_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_TEMP_UPDATE_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_MASK (0x4000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_SHIFT (14U)
/*! DMA_RD_REQ_IE_1 - Request to read data from FIFO. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_MASK (0x8000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_SHIFT (15U)
/*! DMA_WR_REQ_IE_1 - Request to write data to FIFO. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_RX_BME_ERR_IE_1_MASK (0x10000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_RX_BME_ERR_IE_1_SHIFT (16U)
/*! DMAC_RX_BME_ERR_IE_1 - Bi-phase mark encoding error */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_RX_BME_ERR_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_RX_BME_ERR_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_DMAC_RX_BME_ERR_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_MASK (0x20000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_SHIFT (17U)
/*! PREAMBLE_MATCH_IE_1 - Interrupt enable for preamble match received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_MASK (0x40000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_SHIFT (18U)
/*! M_W_PRE_MISMATCH_IE_1 - Interrupt enable for sub-frame M/W preamble mismatch received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_MASK (0x80000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_SHIFT (19U)
/*! B_PRE_MISMATCH_IE_1 - Interrupt enable for sub-frame B preamble mismatch received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_MASK (0x100000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_SHIFT (20U)
/*! UNEXP_PRE_REC_IE_1 - Interrupt enable for Unexpected preamble received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_CH_UD_OFLOW_IE_1_MASK (0x400000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_CH_UD_OFLOW_IE_1_SHIFT (22U)
/*! CH_UD_OFLOW_IE_1 - Channel status or used data could not be stored. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_CH_UD_OFLOW_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_CH_UD_OFLOW_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_CH_UD_OFLOW_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_MASK (0x800000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_SHIFT (23U)
/*! NEW_BLK_RCVD_IE_1 - New block of data was received. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_IER1_SPARE_IE_1_MASK (0xFF000000U)
#define WAKEUP_AUDIO_XCVR_EXT_IER1_SPARE_IE_1_SHIFT (24U)
/*! SPARE_IE_1 - Spare interrupt enables. */
#define WAKEUP_AUDIO_XCVR_EXT_IER1_SPARE_IE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_IER1_SPARE_IE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_IER1_SPARE_IE_1_MASK)
/*! @} */

/*! @name EXT_ISR - External Interrupt Status register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_MASK (0x1U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_SHIFT (0U)
/*! RX_NEW_CH_STAT - Received new channel status block */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_USR_DATA_MASK (0x2U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_USR_DATA_SHIFT (1U)
/*! RX_NEW_USR_DATA - Received new User data Information */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_USR_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_USR_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_RX_NEW_USR_DATA_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_MUTE_DET_MASK  (0x4U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_MUTE_DET_SHIFT (2U)
/*! MUTE_DET - Interrupt to indicate HW mute bit was detected. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_MUTE_DET(x)    (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_MUTE_DET_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_MUTE_DET_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_RESP_TO_ERR_MASK (0x8U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_RESP_TO_ERR_SHIFT (3U)
/*! CMDC_RESP_TO_ERR - CMDC response timeout interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_RESP_TO_ERR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_RESP_TO_ERR_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_RESP_TO_ERR_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_ECC_ERR_MASK   (0x10U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_ECC_ERR_SHIFT  (4U)
/*! ECC_ERR - 60958 Compressed data uncorrectable error interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_ECC_ERR(x)     (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_ECC_ERR_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_ECC_ERR_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_MASK (0x20U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_SHIFT (5U)
/*! PREAMBLE_MISMATCH - Preamble mismatch interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_MASK (0x40U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR - Receive FIFO overflow error interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_OHPD_MASK      (0x100U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_OHPD_SHIFT     (8U)
/*! OHPD - HPD output driver */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_OHPD(x)        (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_OHPD_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_OHPD_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMAC_NO_DATA_REC_MASK (0x200U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMAC_NO_DATA_REC_SHIFT (9U)
/*! DMAC_NO_DATA_REC - No DMAC data is received for 1us. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMAC_NO_DATA_REC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_DMAC_NO_DATA_REC_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_DMAC_NO_DATA_REC_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_FMT_CHG_DET_MASK (0x400U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_FMT_CHG_DET_SHIFT (10U)
/*! FMT_CHG_DET - Format change detect interrupt */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_FMT_CHG_DET(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_FMT_CHG_DET_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_FMT_CHG_DET_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_HB_STATE_CHG_MASK (0x800U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_HB_STATE_CHG_SHIFT (11U)
/*! HB_STATE_CHG - Interrupt enable for Heartbeat status change */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_HB_STATE_CHG(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_HB_STATE_CHG_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_HB_STATE_CHG_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_STATUS_UPDATE_MASK (0x1000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_STATUS_UPDATE_SHIFT (12U)
/*! CMDC_STATUS_UPDATE - Interrupt enable for CMDC status register update. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_STATUS_UPDATE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_STATUS_UPDATE_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_CMDC_STATUS_UPDATE_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_TEMP_UPDATE_INT_MASK (0x2000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_TEMP_UPDATE_INT_SHIFT (13U)
/*! TEMP_UPDATE_INT - Interrupt to get the new temperature value. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_TEMP_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_TEMP_UPDATE_INT_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_TEMP_UPDATE_INT_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_MASK (0x4000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_SHIFT (14U)
/*! DMA_RD_REQ - Set when DMA read request is asserted. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_RD_REQ(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_MASK (0x8000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_SHIFT (15U)
/*! DMA_WR_REQ - Set when DMA write request is asserted. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_WR_REQ(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_MASK (0x10000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_SHIFT (16U)
/*! RX_BME_BIT_ERR - Set when DMAC BME data has an error. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_MASK (0x20000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_SHIFT (17U)
/*! PREAMBLE_MATCH_INT - Interrupt to indicate PA PB / DTC CD preamble match was detected. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_MASK (0x40000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_SHIFT (18U)
/*! M_W_PRE_MISMATCH - Set when DMAC preamble of M/W has an error. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_MASK (0x80000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_SHIFT (19U)
/*! B_PRE_MISMATCH - Set when DMAC preamble of B has an error. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_MASK (0x100000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_SHIFT (20U)
/*! UNEXP_PRE_REC - Set when DMAC preamble was received after unexpected number of input bits. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_MASK (0x400000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_SHIFT (22U)
/*! CS_OR_UD_OFLOW - Channel status or used data could not be stored. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_MASK (0x800000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_SHIFT (23U)
/*! NEW_BLK_RCVD - New block of data was received. */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_MASK)

#define WAKEUP_AUDIO_XCVR_EXT_ISR_SPARE_INT_MASK (0xFF000000U)
#define WAKEUP_AUDIO_XCVR_EXT_ISR_SPARE_INT_SHIFT (24U)
/*! SPARE_INT - Extra interrupt. Currently not driven. Can be set by M0+ */
#define WAKEUP_AUDIO_XCVR_EXT_ISR_SPARE_INT(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_EXT_ISR_SPARE_INT_SHIFT)) & WAKEUP_AUDIO_XCVR_EXT_ISR_SPARE_INT_MASK)
/*! @} */

/*! @name IER - Interrupt enable register for M0++ */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_IER_HPD_TGL_IE_MASK    (0x8000U)
#define WAKEUP_AUDIO_XCVR_IER_HPD_TGL_IE_SHIFT   (15U)
/*! HPD_TGL_IE - HPD pin level change interrupt enable */
#define WAKEUP_AUDIO_XCVR_IER_HPD_TGL_IE(x)      (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_IER_HPD_TGL_IE_SHIFT)) & WAKEUP_AUDIO_XCVR_IER_HPD_TGL_IE_MASK)

#define WAKEUP_AUDIO_XCVR_IER_FMT_CHG_IE_MASK    (0x40000U)
#define WAKEUP_AUDIO_XCVR_IER_FMT_CHG_IE_SHIFT   (18U)
/*! FMT_CHG_IE - Format Change interrupt. */
#define WAKEUP_AUDIO_XCVR_IER_FMT_CHG_IE(x)      (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_IER_FMT_CHG_IE_SHIFT)) & WAKEUP_AUDIO_XCVR_IER_FMT_CHG_IE_MASK)

#define WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_RX_IE_MASK (0x100000U)
#define WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_RX_IE_SHIFT (20U)
/*! SET_SPDIF_RX_IE - Interrupt enable to set up SPDIF RX mode */
#define WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_RX_IE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_RX_IE_SHIFT)) & WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_RX_IE_MASK)

#define WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_TX_IE_MASK (0x200000U)
#define WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_TX_IE_SHIFT (21U)
/*! SET_SPDIF_TX_IE - Interrupt enable to set up SPDIF TX mode */
#define WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_TX_IE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_TX_IE_SHIFT)) & WAKEUP_AUDIO_XCVR_IER_SET_SPDIF_TX_IE_MASK)

#define WAKEUP_AUDIO_XCVR_IER_SW_HPD_TGL_IE_MASK (0x1000000U)
#define WAKEUP_AUDIO_XCVR_IER_SW_HPD_TGL_IE_SHIFT (24U)
/*! SW_HPD_TGL_IE - Interrupt enable to allow SW to assert HPD. */
#define WAKEUP_AUDIO_XCVR_IER_SW_HPD_TGL_IE(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_IER_SW_HPD_TGL_IE_SHIFT)) & WAKEUP_AUDIO_XCVR_IER_SW_HPD_TGL_IE_MASK)
/*! @} */

/*! @name ISR - Interrupt status register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_ISR_HPD_TGL_MASK       (0x8000U)
#define WAKEUP_AUDIO_XCVR_ISR_HPD_TGL_SHIFT      (15U)
/*! HPD_TGL - HPD pin level change interrupt */
#define WAKEUP_AUDIO_XCVR_ISR_HPD_TGL(x)         (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_ISR_HPD_TGL_SHIFT)) & WAKEUP_AUDIO_XCVR_ISR_HPD_TGL_MASK)

#define WAKEUP_AUDIO_XCVR_ISR_FMT_CHG_INT_MASK   (0x40000U)
#define WAKEUP_AUDIO_XCVR_ISR_FMT_CHG_INT_SHIFT  (18U)
/*! FMT_CHG_INT - Format Change interrupt. */
#define WAKEUP_AUDIO_XCVR_ISR_FMT_CHG_INT(x)     (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_ISR_FMT_CHG_INT_SHIFT)) & WAKEUP_AUDIO_XCVR_ISR_FMT_CHG_INT_MASK)

#define WAKEUP_AUDIO_XCVR_ISR_SET_SPDIF_RX_MODE_MASK (0x100000U)
#define WAKEUP_AUDIO_XCVR_ISR_SET_SPDIF_RX_MODE_SHIFT (20U)
/*! SET_SPDIF_RX_MODE - Interrupt to set up PHY and controller in SPDIF RX mode. */
#define WAKEUP_AUDIO_XCVR_ISR_SET_SPDIF_RX_MODE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_ISR_SET_SPDIF_RX_MODE_SHIFT)) & WAKEUP_AUDIO_XCVR_ISR_SET_SPDIF_RX_MODE_MASK)
/*! @} */

/*! @name PHY_AI_CTRL - AI interface control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_ADDR_MASK (0xFFU)
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_ADDR_SHIFT (0U)
/*! AI_ADDR - AI ADDR value */
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_ADDR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_ADDR_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_ADDR_MASK)

#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RESETN_MASK (0x8000U)
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RESETN_SHIFT (15U)
/*! AI_RESETN - AI reset bit */
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RESETN(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RESETN_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RESETN_MASK)

#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_0_MASK (0x1000000U)
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_0_SHIFT (24U)
/*! TOG_0 - AI toggle bit */
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_0(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_0_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_0_MASK)

#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_0_MASK (0x2000000U)
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_0_SHIFT (25U)
/*! TOG_DONE_0 - AI toggle done bit */
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_0(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_0_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_0_MASK)

#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_1_MASK (0x4000000U)
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_1_SHIFT (26U)
/*! TOG_1 - AI toggle bit */
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_1(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_1_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_1_MASK)

#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_1_MASK (0x8000000U)
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_1_SHIFT (27U)
/*! TOG_DONE_1 - AI toggle done bit */
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_1(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_1_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_TOG_DONE_1_MASK)

#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RWB_MASK (0x80000000U)
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RWB_SHIFT (31U)
/*! AI_RWB - AI Read / write control bit */
#define WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RWB(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RWB_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_CTRL_AI_RWB_MASK)
/*! @} */

/*! @name PHY_AI_WDATA - AI interface WDATA register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_PHY_AI_WDATA_WDATA_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_PHY_AI_WDATA_WDATA_SHIFT (0U)
/*! WDATA - Write data */
#define WAKEUP_AUDIO_XCVR_PHY_AI_WDATA_WDATA(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_WDATA_WDATA_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_WDATA_WDATA_MASK)
/*! @} */

/*! @name PHY_AI_RDATA - AI interface RDATA register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_PHY_AI_RDATA_RDATA_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_PHY_AI_RDATA_RDATA_SHIFT (0U)
/*! RDATA - Read data */
#define WAKEUP_AUDIO_XCVR_PHY_AI_RDATA_RDATA(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_PHY_AI_RDATA_RDATA_SHIFT)) & WAKEUP_AUDIO_XCVR_PHY_AI_RDATA_RDATA_MASK)
/*! @} */

/*! @name DPATH_STATUS - AUDIO XCVR datapath status */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_MASK (0xFFU)
#define WAKEUP_AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_SHIFT (0U)
/*! RX_FRM_CNT - Count of received frames in a block */
#define WAKEUP_AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_SHIFT)) & WAKEUP_AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_MASK)

#define WAKEUP_AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_MASK (0xFF00U)
#define WAKEUP_AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_SHIFT (8U)
/*! TX_FRM_CNT - Count of transmitted frames in a block */
#define WAKEUP_AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_SHIFT)) & WAKEUP_AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_MASK)
/*! @} */

/*! @name RX_CMDC_CTRL - CMDC receiver control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_BITS_MASK (0x1FU)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_BITS_SHIFT (0U)
/*! COMMA_BITS - Number of repeating bits in COMMA pattern */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_BITS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_BITS_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_BITS_MASK)

#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_EN_MASK (0x80U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_EN_SHIFT (7U)
/*! COMMA_EN - Enables COMMA pattern generation */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_EN(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_EN_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_COMMA_EN_MASK)

#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_RESPONSE_TIME_MASK (0x1F00U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_RESPONSE_TIME_SHIFT (8U)
/*! RESPONSE_TIME - Transmitter response timeout to a received message */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_RESPONSE_TIME(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_RESPONSE_TIME_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_RESPONSE_TIME_MASK)

#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TURNOVER_TIME_MASK (0xF0000U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TURNOVER_TIME_SHIFT (16U)
/*! TURNOVER_TIME - Minimum time before a response is generated */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TURNOVER_TIME(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TURNOVER_TIME_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TURNOVER_TIME_MASK)

#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TX_DRIVE_STOP_MASK (0x700000U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TX_DRIVE_STOP_SHIFT (20U)
/*! TX_DRIVE_STOP - Transmitter bus release time */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TX_DRIVE_STOP(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TX_DRIVE_STOP_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_TX_DRIVE_STOP_MASK)

#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_LBACK_EN_MASK (0x80000000U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_LBACK_EN_SHIFT (31U)
/*! LBACK_EN - Loopback enable */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_LBACK_EN(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_LBACK_EN_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_CTRL_LBACK_EN_MASK)
/*! @} */

/*! @name RX_CMDC_STATUS - AUDIO_XCVR CMDC status */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_CMDC_STATUS_CMDC_STATE_MASK (0xF0000U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_STATUS_CMDC_STATE_SHIFT (16U)
/*! CMDC_STATE - Current state of the RX CDMC control state machine */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_STATUS_CMDC_STATE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_STATUS_CMDC_STATE_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_STATUS_CMDC_STATE_MASK)
/*! @} */

/*! @name RX_CMDC_TX_DATA - CMDC transmit data register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_TX_DATA_MASK (0x3FFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_TX_DATA_SHIFT (0U)
/*! TX_DATA - Transmit data */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_TX_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_TX_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_TX_DATA_MASK)

#define WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_DATA_VALID_MASK (0x80000000U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_DATA_VALID_SHIFT (31U)
/*! DATA_VALID - Transmit Data Valid */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_DATA_VALID(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_DATA_VALID_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_TX_DATA_DATA_VALID_MASK)
/*! @} */

/*! @name RX_CMDC_RX_DATA - CMDC receive data register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_RX_DATA_MASK (0x3FFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_RX_DATA_SHIFT (0U)
/*! RX_DATA - Receive data */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_RX_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_RX_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_RX_DATA_MASK)

#define WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_CLR_RX_DATA_MASK (0x80000000U)
#define WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_CLR_RX_DATA_SHIFT (31U)
/*! CLR_RX_DATA - Clear RX data field and */
#define WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_CLR_RX_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_CLR_RX_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CMDC_RX_DATA_CLR_RX_DATA_MASK)
/*! @} */

/*! @name RX_DATAPATH_CTRL - Data path control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_MASK (0x1U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_SHIFT (0U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_MASK (0x8U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_SHIFT (3U)
/*! ECC_VUC_BITS_EN - RX_DATAPATH: Enable VUC bit replacement after ECC correction. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_ECC_VUC_BITS_EN_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_MASK (0x10U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_SHIFT (4U)
/*! EN_COMP_PARITY_CALC - RX_DATAPATH: Enable Compressed mode Parity calculation. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_COMP_PARITY_CALC_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_MASK (0x20U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_SHIFT (5U)
/*! RST_PKT_CNT_FIFO - Resets the packet count fifo. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_MASK (0x40U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_SHIFT (6U)
/*! STORE_FMT - Receive Data store format. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_MASK (0x80U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_SHIFT (7U)
/*! EN_PARITY_CALC - Enable Parity calculation. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_MASK (0x100U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_SHIFT (8U)
/*! UDR - User data reset */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_MASK (0x200U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_SHIFT (9U)
/*! CSR - Channel Status reset */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_MASK (0x400U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_SHIFT (10U)
/*! UDA - User Data Acknowledge */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_MASK (0x800U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_SHIFT (11U)
/*! CSA - Channel Status Acknowledge */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK (0x1000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_SHIFT (12U)
/*! CLR_RX_FIFO - Clear Receive FIFO */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DIS_B_PRE_ERR_CHK_MASK (0x2000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DIS_B_PRE_ERR_CHK_SHIFT (13U)
/*! DIS_B_PRE_ERR_CHK - RX_DATAPATH: Disable B preamble error check. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DIS_B_PRE_ERR_CHK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DIS_B_PRE_ERR_CHK_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DIS_B_PRE_ERR_CHK_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_MASK (0xC000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_SHIFT (14U)
/*! RX_DATA_FMT - Indicates format of data stored in memory. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_MASK (0x80000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_SHIFT (19U)
/*! PABS - Enable preamble search */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PABS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_MASK (0x100000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_SHIFT (20U)
/*! DTS_CDS - Enable DTS CD 14 preamble search */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_BLKC_MASK (0x200000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_BLKC_SHIFT (21U)
/*! BLKC - Block Compressed data */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_BLKC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_BLKC_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_BLKC_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_MASK (0x400000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_SHIFT (22U)
/*! MUTE_CTRL - M0+ mute request */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_MASK (0x800000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_SHIFT (23U)
/*! MUTE_MODE - Mute mode control */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_CTRL_MASK (0x1000000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_CTRL_SHIFT (24U)
/*! FMT_CHG_CTRL - Format Change detection control. */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_CTRL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_CTRL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_CTRL_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_MODE_MASK (0x2000000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_MODE_SHIFT (25U)
/*! FMT_CHG_MODE - Format change detected. Reset HW for next frame */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_MODE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_MODE_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FMT_CHG_MODE_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_CTRL_MASK (0x4000000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_CTRL_SHIFT (26U)
/*! LAYB_CTRL - Layout B mode control */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_CTRL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_CTRL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_CTRL_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_MODE_MASK (0x8000000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_MODE_SHIFT (27U)
/*! LAYB_MODE - Layout B */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_MODE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_MODE_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_LAYB_MODE_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PRC_MASK (0x10000000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PRC_SHIFT (28U)
/*! PRC - Process Compressed */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PRC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PRC_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_PRC_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_COMP_MASK (0x20000000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_COMP_SHIFT (29U)
/*! COMP - Compressed data search mode */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_COMP(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_COMP_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_COMP_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_MASK (0xC0000000U)
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_SHIFT (30U)
/*! FSM - IEC60958-1 Frame Synchronization Mode */
#define WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FSM(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_MASK)
/*! @} */

/*! @name RX_CS_DATA_BITS - Channel status bits */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_SHIFT (0U)
/*! CS_DATA - Channel Status bits */
#define WAKEUP_AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_MASK)
/*! @} */

/*! @name RX_USER_DATA_BITS - User data bits */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_SHIFT (0U)
/*! U_DATA - User data bits */
#define WAKEUP_AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_MASK)
/*! @} */

/*! @name RX_DPATH_CNTR_CTRL - DMAC counter control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_MASK (0x1U)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_SHIFT (0U)
/*! TS_EN - Timestamp counter enable */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_MASK (0x2U)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_SHIFT (1U)
/*! TS_INC - Timestamp Increment */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK (0x100U)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT (8U)
/*! RST_BIT_CNTR - Reset bit counter. */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK (0x200U)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT (9U)
/*! RST_TS_CNTR - Reset timestamp counter. */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK)
/*! @} */

/*! @name RX_DPATH_TSCR - Receive Datapath Timestamp Counter Register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_TSCR_CVAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_TSCR_CVAL_SHIFT (0U)
/*! CVAL - Timestamp counter value */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_TSCR_CVAL(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_TSCR_CVAL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_TSCR_CVAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCR - Receive Datapath Bit counter register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCR_CVAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCR_CVAL_SHIFT (0U)
/*! CVAL - Bit count value */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCR_CVAL(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_BCR_CVAL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_BCR_CVAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCTR - Receive datapath Bit count timestamp register. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_SHIFT (0U)
/*! BCT_VAL - Bit count timestamp value */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCRR - Receive datapath Bit read timestamp register. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_SHIFT (0U)
/*! BCT_VAL - Bit count timestamp value */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_MASK)
/*! @} */

/*! @name DMAC_PRE_MATCH_VAL - Preamble match value register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PB_VAL_MASK (0xFFFFU)
#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PB_VAL_SHIFT (0U)
/*! PB_VAL - Preamble PB value */
#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PB_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PB_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PB_VAL_MASK)

#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PA_VAL_MASK (0xFFFF0000U)
#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PA_VAL_SHIFT (16U)
/*! PA_VAL - Preamble PA value */
#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PA_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PA_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_VAL_PA_VAL_MASK)
/*! @} */

/*! @name DMAC_DTS_PRE_MATCH_VAL - Preamble match value register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_MASK (0xFFFFU)
#define WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_SHIFT (0U)
/*! DTS_PB_VAL - Preamble PB value */
#define WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PB_VAL_MASK)

#define WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_MASK (0xFFFF0000U)
#define WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_SHIFT (16U)
/*! DTS_PA_VAL - Preamble PA value */
#define WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_DMAC_DTS_PRE_MATCH_VAL_DTS_PA_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_PRE_ERR - Error count for IEC60958-1 Block Synchronization. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_MASK (0xFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_SHIFT (0U)
/*! PRE_ERRS - Preamble Error counter */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_MASK (0x80000000U)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_SHIFT (31U)
/*! CLEAR - Clear bit for error counter. */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_MASK)
/*! @} */

/*! @name RX_DPATH_PARITY_ERR - Parity Error count for IEC60958-1 Blocks. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_MASK (0xFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_SHIFT (0U)
/*! PRE_ERRS - Preamble Error counter */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_MASK)

#define WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_MASK (0x80000000U)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_SHIFT (31U)
/*! CLEAR - Clear bit for error counter. */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_MASK)
/*! @} */

/*! @name RX_DPATH_PKT_CNT - Receive Data packet count. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_MASK (0x7FFFFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_SHIFT (0U)
/*! VAL - Data packet counter */
#define WAKEUP_AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_ONE_BIT_ERR_CNT - Receive Data packet Corrected error count. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_RX_DPATH_ONE_BIT_ERR_CNT_VAL_MASK (0xFFFFU)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_ONE_BIT_ERR_CNT_VAL_SHIFT (0U)
#define WAKEUP_AUDIO_XCVR_RX_DPATH_ONE_BIT_ERR_CNT_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_RX_DPATH_ONE_BIT_ERR_CNT_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_RX_DPATH_ONE_BIT_ERR_CNT_VAL_MASK)
/*! @} */

/*! @name DMAC_PRE_MATCH_OFFSET - Preamble match offset value register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_SHIFT (0U)
/*! PA_OFFSET - Sample count value for PA offset match */
#define WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_OFFSET_PA_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_SHIFT)) & WAKEUP_AUDIO_XCVR_DMAC_PRE_MATCH_OFFSET_PA_OFFSET_MASK)
/*! @} */

/*! @name TX_DATAPATH_CTRL - Transmit Data path control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_MASK (0x1U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_SHIFT (0U)
/*! CS_ACK - Channel Status ACK */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_MASK (0x2U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_SHIFT (1U)
/*! UD_ACK - User Data ACK */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_MASK (0x4U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_SHIFT (2U)
/*! CS_MOD - Enable Channel Status insertion */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_MASK (0x8U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_SHIFT (3U)
/*! UD_MOD - Enable User Data insertion */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_MASK (0x10U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_SHIFT (4U)
/*! VLD_MOD - Enable Valid bit insertion */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_MASK (0x20U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_SHIFT (5U)
/*! FRM_VLD - Valid bit value */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_MASK (0x40U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_SHIFT (6U)
/*! EN_PARITY - Enable parity insertion */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_MASK (0x80U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_SHIFT (7U)
/*! EN_PREAMBLE - Enable preamble insertion */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_BYPASS_FEM_MASK (0x400U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_BYPASS_FEM_SHIFT (10U)
/*! BYPASS_FEM - Control the TX clock rate */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_BYPASS_FEM(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_BYPASS_FEM_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_BYPASS_FEM_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_MASK (0x800U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_SHIFT (11U)
/*! FRM_FMT - Frame format of input data */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_MASK (0x3000U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_SHIFT (12U)
/*! TX_FORMAT - Transmit data format */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK (0x4000U)
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_SHIFT (14U)
/*! STRT_DATA_TX - Once Comma pattern is successively received, and heartbeat is detected, start TX of DMAC data. */
#define WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK)
/*! @} */

/*! @name TX_CS_DATA_BITS - Channel status bits */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_SHIFT (0U)
/*! CS_DATA - Channel Status bits / block */
#define WAKEUP_AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_MASK)
/*! @} */

/*! @name TX_USER_DATA_BITS - User data bits */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_SHIFT (0U)
/*! U_DATA - User data bits/block */
#define WAKEUP_AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_MASK)
/*! @} */

/*! @name TX_DPATH_CNTR_CTRL - DMAC counter control register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_MASK (0x1U)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_SHIFT (0U)
/*! TS_EN - Timestamp counter enable */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_MASK (0x2U)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_SHIFT (1U)
/*! TS_INC - Timestamp Increment */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK (0x100U)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT (8U)
/*! RST_BIT_CNTR - Reset bit counter. */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK)

#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK (0x200U)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT (9U)
/*! RST_TS_CNTR - Reset timestamp counter. */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK)
/*! @} */

/*! @name TX_DPATH_TSCR - Transmit Datapath Timestamp Counter Register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_DPATH_TSCR_CVAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_TSCR_CVAL_SHIFT (0U)
/*! CVAL - Timestamp counter value */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_TSCR_CVAL(x)  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_TSCR_CVAL_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_TSCR_CVAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCR - Transmit Datapath Bit counter register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCR_CVAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCR_CVAL_SHIFT (0U)
/*! CVAL - Bit count value */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCR_CVAL(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_BCR_CVAL_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_BCR_CVAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCTR - Transmit datapath Bit count timestamp register. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_SHIFT (0U)
/*! BCT_VAL - Bit count timestamp value */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCRR - Transmit datapath Bit read timestamp register. */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_SHIFT (0U)
/*! BCT_VAL - Bit count timestamp value */
#define WAKEUP_AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_MASK)
/*! @} */

/*! @name HPD_DBNC_CTRL - HPD Debounce Control Register */
/*! @{ */

#define WAKEUP_AUDIO_XCVR_HPD_DBNC_CTRL_VAL_MASK (0xFFFFFFFFU)
#define WAKEUP_AUDIO_XCVR_HPD_DBNC_CTRL_VAL_SHIFT (0U)
/*! VAL - HDP pin debounce interval */
#define WAKEUP_AUDIO_XCVR_HPD_DBNC_CTRL_VAL(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDIO_XCVR_HPD_DBNC_CTRL_VAL_SHIFT)) & WAKEUP_AUDIO_XCVR_HPD_DBNC_CTRL_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WAKEUP_AUDIO_XCVR_Register_Masks */


/*!
 * @}
 */ /* end of group WAKEUP_AUDIO_XCVR_Peripheral_Access_Layer */


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


#endif  /* WAKEUP_AUDIO_XCVR_H_ */

