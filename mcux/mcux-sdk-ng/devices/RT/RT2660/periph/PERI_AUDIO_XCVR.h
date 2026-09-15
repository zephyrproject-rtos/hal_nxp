/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AUDIO_XCVR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_AUDIO_XCVR.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for AUDIO_XCVR
 *
 * CMSIS Peripheral Access Layer for AUDIO_XCVR
 */

#if !defined(PERI_AUDIO_XCVR_H_)
#define PERI_AUDIO_XCVR_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- AUDIO_XCVR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIO_XCVR_Peripheral_Access_Layer AUDIO_XCVR Peripheral Access Layer
 * @{
 */

/** AUDIO_XCVR - Size of Registers Arrays */
#define AUDIO_XCVR_RX_CS_DATA_BITS_COUNT          6u
#define AUDIO_XCVR_RX_USER_DATA_BITS_COUNT        6u
#define AUDIO_XCVR_TX_CS_DATA_BITS_COUNT          6u
#define AUDIO_XCVR_TX_USER_DATA_BITS_COUNT        6u

/** AUDIO_XCVR - Register Layout Typedef */
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
       uint8_t RESERVED_1[72];
  __I  uint32_t DPATH_STATUS;                      /**< Audio XCVR datapath status, offset: 0xA8 */
       uint8_t RESERVED_2[4];
  __IO uint32_t CLK_CTRL;                          /**< Clock control register, offset: 0xB0 */
       uint8_t RESERVED_3[204];
  struct {                                         /* offset: 0x180 */
    __IO uint32_t RW;                                /**< Data path control register, offset: 0x180 */
    __IO uint32_t SET;                               /**< Data path control register, offset: 0x184 */
    __IO uint32_t CLR;                               /**< Data path control register, offset: 0x188 */
    __IO uint32_t TOG;                               /**< Data path control register, offset: 0x18C */
  } RX_DATAPATH_CTRL;
  __I  uint32_t RX_CS_DATA_BITS[AUDIO_XCVR_RX_CS_DATA_BITS_COUNT]; /**< Channel staus bits, array offset: 0x190, array step: 0x4 */
  __I  uint32_t RX_USER_DATA_BITS[AUDIO_XCVR_RX_USER_DATA_BITS_COUNT]; /**< User data bits, array offset: 0x1A8, array step: 0x4 */
  struct {                                         /* offset: 0x1C0 */
    __IO uint32_t RW;                                /**< Receive Datapath counter control register, offset: 0x1C0 */
    __IO uint32_t SET;                               /**< Receive Datapath counter control register, offset: 0x1C4 */
    __IO uint32_t CLR;                               /**< Receive Datapath counter control register, offset: 0x1C8 */
    __IO uint32_t TOG;                               /**< Receive Datapath counter control register, offset: 0x1CC */
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
  } PRE_MATCH_VAL;
  struct {                                         /* offset: 0x1F0 */
    __IO uint32_t RW;                                /**< Preamble match value register, offset: 0x1F0 */
    __IO uint32_t SET;                               /**< Preamble match value register, offset: 0x1F4 */
    __IO uint32_t CLR;                               /**< Preamble match value register, offset: 0x1F8 */
    __IO uint32_t TOG;                               /**< Preamble match value register, offset: 0x1FC */
  } DTS_PRE_MATCH_VAL;
  __IO uint32_t RX_DPATH_PRE_ERR;                  /**< Error count for IEC60958-1 Block Synchronization., offset: 0x200 */
  __IO uint32_t RX_DPATH_PARITY_ERR;               /**< Parity Error count for IEC60958-1 Blocks., offset: 0x204 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RX_DPATH_PKT_CNT;                  /**< Receive Data packet count., offset: 0x210 */
       uint8_t RESERVED_5[4];
  __I  uint32_t PRE_MATCH_OFFSET;                  /**< Preamble match offset value register, offset: 0x218 */
       uint8_t RESERVED_6[4];
  struct {                                         /* offset: 0x220 */
    __IO uint32_t RW;                                /**< Transmit Data path control register, offset: 0x220 */
    __IO uint32_t SET;                               /**< Transmit Data path control register, offset: 0x224 */
    __IO uint32_t CLR;                               /**< Transmit Data path control register, offset: 0x228 */
    __IO uint32_t TOG;                               /**< Transmit Data path control register, offset: 0x22C */
  } TX_DATAPATH_CTRL;
  __IO uint32_t TX_CS_DATA_BITS[AUDIO_XCVR_TX_CS_DATA_BITS_COUNT]; /**< Channel staus bits, array offset: 0x230, array step: 0x4 */
  __IO uint32_t TX_USER_DATA_BITS[AUDIO_XCVR_TX_USER_DATA_BITS_COUNT]; /**< User data bits, array offset: 0x248, array step: 0x4 */
  struct {                                         /* offset: 0x260 */
    __IO uint32_t RW;                                /**< Transmit datapath counter control register, offset: 0x260 */
    __IO uint32_t SET;                               /**< Transmit datapath counter control register, offset: 0x264 */
    __IO uint32_t CLR;                               /**< Transmit datapath counter control register, offset: 0x268 */
    __IO uint32_t TOG;                               /**< Transmit datapath counter control register, offset: 0x26C */
  } TX_DPATH_CNTR_CTRL;
  __I  uint32_t TX_DPATH_TSCR;                     /**< Transmit Datapath Timestamp Counter Register, offset: 0x270 */
  __I  uint32_t TX_DPATH_BCR;                      /**< Transmit Datapath Bit counter register, offset: 0x274 */
  __I  uint32_t TX_DPATH_BCTR;                     /**< Transmit datapath Bit count timestamp register., offset: 0x278 */
  __I  uint32_t TX_DPATH_BCRR;                     /**< Transmmit datapath Bit read timestamp register., offset: 0x27C */
} AUDIO_XCVR_Type;

/* ----------------------------------------------------------------------------
   -- AUDIO_XCVR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIO_XCVR_Register_Masks AUDIO_XCVR Register Masks
 * @{
 */

/*! @name VERSION - Version control register */
/*! @{ */

#define AUDIO_XCVR_VERSION_VERID_MASK            (0xFFFFFFFFU)
#define AUDIO_XCVR_VERSION_VERID_SHIFT           (0U)
/*! VERID - Version ID */
#define AUDIO_XCVR_VERSION_VERID(x)              (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_VERSION_VERID_SHIFT)) & AUDIO_XCVR_VERSION_VERID_MASK)
/*! @} */

/*! @name EXT_CTRL - External control register */
/*! @{ */

#define AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_MASK   (0x7FU)
#define AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_SHIFT  (0U)
/*! TX_FIFO_WMARK - Audio Transmit FIFO Watermark Level */
#define AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_SHIFT)) & AUDIO_XCVR_EXT_CTRL_TX_FIFO_WMARK_MASK)

#define AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_MASK   (0x7F00U)
#define AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_SHIFT  (8U)
/*! RX_FIFO_WMARK - Audio Receive FIFO Watermark Level */
#define AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_SHIFT)) & AUDIO_XCVR_EXT_CTRL_RX_FIFO_WMARK_MASK)

#define AUDIO_XCVR_EXT_CTRL_EN_SPDIF_WAKEUP_MASK (0x100000U)
#define AUDIO_XCVR_EXT_CTRL_EN_SPDIF_WAKEUP_SHIFT (20U)
/*! EN_SPDIF_WAKEUP - Enable SPDIF wakeup interrupt */
#define AUDIO_XCVR_EXT_CTRL_EN_SPDIF_WAKEUP(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_CTRL_EN_SPDIF_WAKEUP_SHIFT)) & AUDIO_XCVR_EXT_CTRL_EN_SPDIF_WAKEUP_MASK)

#define AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_MASK (0x1000000U)
#define AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_SHIFT (24U)
/*! SDMA_WR_REQ_DIS - SDMA WR REQ disable */
#define AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_SHIFT)) & AUDIO_XCVR_EXT_CTRL_SDMA_WR_REQ_DIS_MASK)

#define AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_MASK (0x2000000U)
#define AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_SHIFT (25U)
/*! SDMA_RD_REQ_DIS - SDMA RD REQ disable */
#define AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_SHIFT)) & AUDIO_XCVR_EXT_CTRL_SDMA_RD_REQ_DIS_MASK)

#define AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_MASK  (0x8000000U)
#define AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_SHIFT (27U)
/*! TX_DPATH_RESET - Soft reset to SPDIF Transmit datapath */
#define AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_SHIFT)) & AUDIO_XCVR_EXT_CTRL_TX_DPATH_RESET_MASK)

#define AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_MASK  (0x10000000U)
#define AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_SHIFT (28U)
/*! RX_DPATH_RESET - Soft reset to SPDIF Receive datapath */
#define AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_SHIFT)) & AUDIO_XCVR_EXT_CTRL_RX_DPATH_RESET_MASK)
/*! @} */

/*! @name EXT_STATUS - External Status register */
/*! @{ */

#define AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_MASK (0xFFU)
#define AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_SHIFT (0U)
/*! NO_TX_FIFO_ENTRIES - TX FIFO entries */
#define AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_SHIFT)) & AUDIO_XCVR_EXT_STATUS_NO_TX_FIFO_ENTRIES_MASK)

#define AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_MASK (0xFF00U)
#define AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_SHIFT (8U)
/*! NO_RX_FIFO_ENTRIES - RX FIFO entries */
#define AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_SHIFT)) & AUDIO_XCVR_EXT_STATUS_NO_RX_FIFO_ENTRIES_MASK)

#define AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_MASK (0x200000U)
#define AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_SHIFT (21U)
/*! TX_PIPE_EMPTY - Indicates TX pipe status. */
#define AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_SHIFT)) & AUDIO_XCVR_EXT_STATUS_TX_PIPE_EMPTY_MASK)

#define AUDIO_XCVR_EXT_STATUS_PREV_UD_0_MASK     (0x400000U)
#define AUDIO_XCVR_EXT_STATUS_PREV_UD_0_SHIFT    (22U)
/*! PREV_UD_0 - Last User data received was all 0 */
#define AUDIO_XCVR_EXT_STATUS_PREV_UD_0(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_STATUS_PREV_UD_0_SHIFT)) & AUDIO_XCVR_EXT_STATUS_PREV_UD_0_MASK)
/*! @} */

/*! @name EXT_IER0 - Interrupt enables for interrupt 0 */
/*! @{ */

#define AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_MASK     (0x1U)
#define AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_SHIFT    (0U)
/*! NEW_CS_IE_0 - Enable for New channel status block received interrupt */
#define AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_NEW_CS_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_UD_IE_0_MASK         (0x2U)
#define AUDIO_XCVR_EXT_IER0_UD_IE_0_SHIFT        (1U)
/*! UD_IE_0 - Enable for user data received interrupt */
#define AUDIO_XCVR_EXT_IER0_UD_IE_0(x)           (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_UD_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_UD_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_MUTE_IE_0_MASK       (0x4U)
#define AUDIO_XCVR_EXT_IER0_MUTE_IE_0_SHIFT      (2U)
/*! MUTE_IE_0 - Enable for Mute detected interrupt */
#define AUDIO_XCVR_EXT_IER0_MUTE_IE_0(x)         (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_MUTE_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_MUTE_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_MASK (0x20U)
#define AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_SHIFT (5U)
/*! PREAMBLE_MISMATCH_IE_0 - Preamble mismatch interrupt enable. */
#define AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_PREAMBLE_MISMATCH_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_MASK (0x40U)
#define AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR_IE_0 - Receive FIFO overflow error interrupt enable. */
#define AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_RX_NO_DATA_REC_IE_0_MASK (0x200U)
#define AUDIO_XCVR_EXT_IER0_RX_NO_DATA_REC_IE_0_SHIFT (9U)
/*! RX_NO_DATA_REC_IE_0 - Indicates no data is received. */
#define AUDIO_XCVR_EXT_IER0_RX_NO_DATA_REC_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_RX_NO_DATA_REC_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_RX_NO_DATA_REC_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_MASK (0x4000U)
#define AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_SHIFT (14U)
/*! DMA_RD_REQ_IE_0 - Request to read data from FIFO. */
#define AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_DMA_RD_REQ_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_MASK (0x8000U)
#define AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_SHIFT (15U)
/*! DMA_WR_REQ_IE_0 - Request to write data to FIFO. */
#define AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_DMA_WR_REQ_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_RX_DATA_BME_ERR_IE_0_MASK (0x10000U)
#define AUDIO_XCVR_EXT_IER0_RX_DATA_BME_ERR_IE_0_SHIFT (16U)
/*! RX_DATA_BME_ERR_IE_0 - Bi-phase mark encoding error */
#define AUDIO_XCVR_EXT_IER0_RX_DATA_BME_ERR_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_RX_DATA_BME_ERR_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_RX_DATA_BME_ERR_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_MASK (0x20000U)
#define AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_SHIFT (17U)
/*! PREAMBLE_MATCH_IE_0 - Interrupt enable for preamble match received. */
#define AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_PREAMBLE_MATCH_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_MASK (0x40000U)
#define AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_SHIFT (18U)
/*! M_W_PRE_MISMATCH_IE_0 - Interrupt enable for sub-frame M/W preamble mismatch received. */
#define AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_M_W_PRE_MISMATCH_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_MASK (0x80000U)
#define AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_SHIFT (19U)
/*! B_PRE_MISMATCH_IE_0 - Interrupt enable for sub-frame B preamble mismatch received. */
#define AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_B_PRE_MISMATCH_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_MASK (0x100000U)
#define AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_SHIFT (20U)
/*! UNEXP_PRE_REC_IE_0 - Interrupt enable for Unexpected preamble received. */
#define AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_UNEXP_PRE_REC_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_CS_UD_OFLOW_IE_0_MASK (0x400000U)
#define AUDIO_XCVR_EXT_IER0_CS_UD_OFLOW_IE_0_SHIFT (22U)
/*! CS_UD_OFLOW_IE_0 - Channel status or used data could not be stored. */
#define AUDIO_XCVR_EXT_IER0_CS_UD_OFLOW_IE_0(x)  (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_CS_UD_OFLOW_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_CS_UD_OFLOW_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_MASK (0x800000U)
#define AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_SHIFT (23U)
/*! NEW_BLK_RCVD_IE_0 - New block of data was received. */
#define AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_NEW_BLK_RCVD_IE_0_MASK)

#define AUDIO_XCVR_EXT_IER0_SPDIF_WAKEUP_IE_0_MASK (0x1000000U)
#define AUDIO_XCVR_EXT_IER0_SPDIF_WAKEUP_IE_0_SHIFT (24U)
/*! SPDIF_WAKEUP_IE_0 - SPDIF Wakeup interrupt enable. */
#define AUDIO_XCVR_EXT_IER0_SPDIF_WAKEUP_IE_0(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER0_SPDIF_WAKEUP_IE_0_SHIFT)) & AUDIO_XCVR_EXT_IER0_SPDIF_WAKEUP_IE_0_MASK)
/*! @} */

/*! @name EXT_IER1 - Interrupt enables for interrupt 1 */
/*! @{ */

#define AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_MASK     (0x1U)
#define AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_SHIFT    (0U)
/*! NEW_CS_IE_1 - Enable for New channel status block received interrupt */
#define AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_NEW_CS_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_UD_IE_1_MASK         (0x2U)
#define AUDIO_XCVR_EXT_IER1_UD_IE_1_SHIFT        (1U)
/*! UD_IE_1 - Enable for user data received interrupt */
#define AUDIO_XCVR_EXT_IER1_UD_IE_1(x)           (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_UD_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_UD_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_MUTE_IE_1_MASK       (0x4U)
#define AUDIO_XCVR_EXT_IER1_MUTE_IE_1_SHIFT      (2U)
/*! MUTE_IE_1 - Enable for Mute detected interrupt */
#define AUDIO_XCVR_EXT_IER1_MUTE_IE_1(x)         (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_MUTE_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_MUTE_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_MASK (0x20U)
#define AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_SHIFT (5U)
/*! PREAMBLE_MISMATCH_IE_1 - Preamble mismatch interrupt enable. */
#define AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_PREAMBLE_MISMATCH_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_MASK (0x40U)
#define AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR_IE_1 - Receive FIFO overflow error interrupt enable. */
#define AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_FIFO_OFLOW_UFLOW_ERR_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_RX_NO_DATA_REC_IE_1_MASK (0x200U)
#define AUDIO_XCVR_EXT_IER1_RX_NO_DATA_REC_IE_1_SHIFT (9U)
/*! RX_NO_DATA_REC_IE_1 - Indicates no data is received. */
#define AUDIO_XCVR_EXT_IER1_RX_NO_DATA_REC_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_RX_NO_DATA_REC_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_RX_NO_DATA_REC_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_MASK (0x4000U)
#define AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_SHIFT (14U)
/*! DMA_RD_REQ_IE_1 - Request to read data from FIFO. */
#define AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_DMA_RD_REQ_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_MASK (0x8000U)
#define AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_SHIFT (15U)
/*! DMA_WR_REQ_IE_1 - Request to write data to FIFO. */
#define AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_DMA_WR_REQ_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_RX_DATA_BME_ERR_IE_1_MASK (0x10000U)
#define AUDIO_XCVR_EXT_IER1_RX_DATA_BME_ERR_IE_1_SHIFT (16U)
/*! RX_DATA_BME_ERR_IE_1 - Bi-phase mark encoding error */
#define AUDIO_XCVR_EXT_IER1_RX_DATA_BME_ERR_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_RX_DATA_BME_ERR_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_RX_DATA_BME_ERR_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_MASK (0x20000U)
#define AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_SHIFT (17U)
/*! PREAMBLE_MATCH_IE_1 - Interrupt enable for preamble match received. */
#define AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_PREAMBLE_MATCH_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_MASK (0x40000U)
#define AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_SHIFT (18U)
/*! M_W_PRE_MISMATCH_IE_1 - Interrupt enable for sub-frame M/W preamble mismatch received. */
#define AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_M_W_PRE_MISMATCH_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_MASK (0x80000U)
#define AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_SHIFT (19U)
/*! B_PRE_MISMATCH_IE_1 - Interrupt enable for sub-frame B preamble mismatch received. */
#define AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_B_PRE_MISMATCH_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_MASK (0x100000U)
#define AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_SHIFT (20U)
/*! UNEXP_PRE_REC_IE_1 - Interrupt enable for Unexpected preamble received. */
#define AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_UNEXP_PRE_REC_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_CS_UD_OFLOW_IE_1_MASK (0x400000U)
#define AUDIO_XCVR_EXT_IER1_CS_UD_OFLOW_IE_1_SHIFT (22U)
/*! CS_UD_OFLOW_IE_1 - Channel status or used data could not be stored. */
#define AUDIO_XCVR_EXT_IER1_CS_UD_OFLOW_IE_1(x)  (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_CS_UD_OFLOW_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_CS_UD_OFLOW_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_MASK (0x800000U)
#define AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_SHIFT (23U)
/*! NEW_BLK_RCVD_IE_1 - New block of data was received. */
#define AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_NEW_BLK_RCVD_IE_1_MASK)

#define AUDIO_XCVR_EXT_IER1_SPDIF_WAKEUP_IE_1_MASK (0x1000000U)
#define AUDIO_XCVR_EXT_IER1_SPDIF_WAKEUP_IE_1_SHIFT (24U)
/*! SPDIF_WAKEUP_IE_1 - SPDIF Wakeup interrupt enable. */
#define AUDIO_XCVR_EXT_IER1_SPDIF_WAKEUP_IE_1(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_IER1_SPDIF_WAKEUP_IE_1_SHIFT)) & AUDIO_XCVR_EXT_IER1_SPDIF_WAKEUP_IE_1_MASK)
/*! @} */

/*! @name EXT_ISR - External Interrupt Status register */
/*! @{ */

#define AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_MASK   (0x1U)
#define AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_SHIFT  (0U)
/*! RX_NEW_CH_STAT - Received new channel status block */
#define AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_SHIFT)) & AUDIO_XCVR_EXT_ISR_RX_NEW_CH_STAT_MASK)

#define AUDIO_XCVR_EXT_ISR_RX_USR_DATA_MASK      (0x2U)
#define AUDIO_XCVR_EXT_ISR_RX_USR_DATA_SHIFT     (1U)
/*! RX_USR_DATA - Received User data Information */
#define AUDIO_XCVR_EXT_ISR_RX_USR_DATA(x)        (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_RX_USR_DATA_SHIFT)) & AUDIO_XCVR_EXT_ISR_RX_USR_DATA_MASK)

#define AUDIO_XCVR_EXT_ISR_MUTE_DET_MASK         (0x4U)
#define AUDIO_XCVR_EXT_ISR_MUTE_DET_SHIFT        (2U)
/*! MUTE_DET - Interrupt to indicate HW mute bit was detected. */
#define AUDIO_XCVR_EXT_ISR_MUTE_DET(x)           (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_MUTE_DET_SHIFT)) & AUDIO_XCVR_EXT_ISR_MUTE_DET_MASK)

#define AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_MASK (0x20U)
#define AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_SHIFT (5U)
/*! PREAMBLE_MISMATCH - Preamble mismatch interrupt */
#define AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH(x)  (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_SHIFT)) & AUDIO_XCVR_EXT_ISR_PREAMBLE_MISMATCH_MASK)

#define AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_MASK (0x40U)
#define AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_SHIFT (6U)
/*! FIFO_OFLOW_UFLOW_ERR - Receive FIFO overflow error interrupt */
#define AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_SHIFT)) & AUDIO_XCVR_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_MASK)

#define AUDIO_XCVR_EXT_ISR_RX_NO_DATA_REC_MASK   (0x200U)
#define AUDIO_XCVR_EXT_ISR_RX_NO_DATA_REC_SHIFT  (9U)
/*! RX_NO_DATA_REC - No data is received for 1us. */
#define AUDIO_XCVR_EXT_ISR_RX_NO_DATA_REC(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_RX_NO_DATA_REC_SHIFT)) & AUDIO_XCVR_EXT_ISR_RX_NO_DATA_REC_MASK)

#define AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_MASK       (0x4000U)
#define AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_SHIFT      (14U)
/*! DMA_RD_REQ - Set when DMA read request is asserted. */
#define AUDIO_XCVR_EXT_ISR_DMA_RD_REQ(x)         (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_SHIFT)) & AUDIO_XCVR_EXT_ISR_DMA_RD_REQ_MASK)

#define AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_MASK       (0x8000U)
#define AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_SHIFT      (15U)
/*! DMA_WR_REQ - Set when DMA write request is asserted. */
#define AUDIO_XCVR_EXT_ISR_DMA_WR_REQ(x)         (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_SHIFT)) & AUDIO_XCVR_EXT_ISR_DMA_WR_REQ_MASK)

#define AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_MASK   (0x10000U)
#define AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_SHIFT  (16U)
/*! RX_BME_BIT_ERR - Set when RX BME data has an error. */
#define AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_SHIFT)) & AUDIO_XCVR_EXT_ISR_RX_BME_BIT_ERR_MASK)

#define AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_MASK (0x20000U)
#define AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_SHIFT (17U)
/*! PREAMBLE_MATCH_INT - Interrupt to indicate PA PB / DTC CD preamble match was detected. */
#define AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_SHIFT)) & AUDIO_XCVR_EXT_ISR_PREAMBLE_MATCH_INT_MASK)

#define AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_MASK (0x40000U)
#define AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_SHIFT (18U)
/*! M_W_PRE_MISMATCH - Set when SPDIF preamble of M/W has an error. */
#define AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_SHIFT)) & AUDIO_XCVR_EXT_ISR_M_W_PRE_MISMATCH_MASK)

#define AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_MASK   (0x80000U)
#define AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_SHIFT  (19U)
/*! B_PRE_MISMATCH - Set when SPDIF B preamble has an error. */
#define AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_SHIFT)) & AUDIO_XCVR_EXT_ISR_B_PRE_MISMATCH_MASK)

#define AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_MASK    (0x100000U)
#define AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_SHIFT   (20U)
/*! UNEXP_PRE_REC - Set when SPDIF preamble was received after unexpected number of input bits. */
#define AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC(x)      (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_SHIFT)) & AUDIO_XCVR_EXT_ISR_UNEXP_PRE_REC_MASK)

#define AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_MASK   (0x400000U)
#define AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_SHIFT  (22U)
/*! CS_OR_UD_OFLOW - Channel status or used data could not be stored. */
#define AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_SHIFT)) & AUDIO_XCVR_EXT_ISR_CS_OR_UD_OFLOW_MASK)

#define AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_MASK     (0x800000U)
#define AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_SHIFT    (23U)
/*! NEW_BLK_RCVD - New block of data was received. */
#define AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_SHIFT)) & AUDIO_XCVR_EXT_ISR_NEW_BLK_RCVD_MASK)

#define AUDIO_XCVR_EXT_ISR_SPDIF_WAKEUP_REC_MASK (0x1000000U)
#define AUDIO_XCVR_EXT_ISR_SPDIF_WAKEUP_REC_SHIFT (24U)
/*! SPDIF_WAKEUP_REC - SPDIF Wakeup received. */
#define AUDIO_XCVR_EXT_ISR_SPDIF_WAKEUP_REC(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_EXT_ISR_SPDIF_WAKEUP_REC_SHIFT)) & AUDIO_XCVR_EXT_ISR_SPDIF_WAKEUP_REC_MASK)
/*! @} */

/*! @name DPATH_STATUS - Audio XCVR datapath status */
/*! @{ */

#define AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_MASK  (0xFFU)
#define AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_SHIFT (0U)
/*! RX_FRM_CNT - Count of received frames in a block */
#define AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_SHIFT)) & AUDIO_XCVR_DPATH_STATUS_RX_FRM_CNT_MASK)

#define AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_MASK  (0xFF00U)
#define AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_SHIFT (8U)
/*! TX_FRM_CNT - Count of transmitted frames in a block */
#define AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_SHIFT)) & AUDIO_XCVR_DPATH_STATUS_TX_FRM_CNT_MASK)
/*! @} */

/*! @name CLK_CTRL - Clock control register */
/*! @{ */

#define AUDIO_XCVR_CLK_CTRL_CLKDIV_MASK          (0x3FFU)
#define AUDIO_XCVR_CLK_CTRL_CLKDIV_SHIFT         (0U)
/*! CLKDIV - Clock divider value */
#define AUDIO_XCVR_CLK_CTRL_CLKDIV(x)            (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_CLK_CTRL_CLKDIV_SHIFT)) & AUDIO_XCVR_CLK_CTRL_CLKDIV_MASK)
/*! @} */

/*! @name RX_DATAPATH_CTRL - Data path control register */
/*! @{ */

#define AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_MASK (0x1U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_SHIFT (0U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_PAPB_FIFO_STATUS_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_MASK (0x20U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_SHIFT (5U)
/*! RST_PKT_CNT_FIFO - Resets the packet count fifo. */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_RST_PKT_CNT_FIFO_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_MASK (0x40U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_SHIFT (6U)
/*! STORE_FMT - Receive Data store format. */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_STORE_FMT_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_MASK (0x80U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_SHIFT (7U)
/*! EN_PARITY_CALC - Enable Parity calculation. */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_EN_PARITY_CALC_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_MASK     (0x100U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_SHIFT    (8U)
/*! UDR - User data reset */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_UDR(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_UDR_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_MASK     (0x200U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_SHIFT    (9U)
/*! CSR - Channel Status reset */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_CSR(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_CSR_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_MASK     (0x400U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_SHIFT    (10U)
/*! UDA - User Data Acknowledge */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_UDA(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_UDA_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_MASK     (0x800U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_SHIFT    (11U)
/*! CSA - Channel Status Acknowledge */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_CSA(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_CSA_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK (0x1000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_SHIFT (12U)
/*! CLR_RX_FIFO - Clear Receive FIFO */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_MASK (0xC000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_SHIFT (14U)
/*! RX_DATA_FMT - Indicates format of data stored in memory. */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_RX_DATA_FMT_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_SPDIF_TGL_CNT_MASK (0x70000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_SPDIF_TGL_CNT_SHIFT (16U)
/*! SPDIF_TGL_CNT - SPDIF wakeup source toggle count. */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_SPDIF_TGL_CNT(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_SPDIF_TGL_CNT_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_SPDIF_TGL_CNT_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_MASK    (0x80000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_SHIFT   (19U)
/*! PABS - Enable preamble search */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_PABS(x)      (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_PABS_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_MASK (0x100000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_SHIFT (20U)
/*! DTS_CDS - Enable DTS CD 14 preamble search */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_DTS_CDS_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_MASK (0x400000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_SHIFT (22U)
/*! MUTE_CTRL - M0+ mute request */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_CTRL_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_MASK (0x800000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_SHIFT (23U)
/*! MUTE_MODE - Mute mode control */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_MUTE_MODE_MASK)

#define AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_MASK     (0xC0000000U)
#define AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_SHIFT    (30U)
/*! FSM - IEC60958-1 Frame Synchronization Mode */
#define AUDIO_XCVR_RX_DATAPATH_CTRL_FSM(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_SHIFT)) & AUDIO_XCVR_RX_DATAPATH_CTRL_FSM_MASK)
/*! @} */

/*! @name RX_CS_DATA_BITS - Channel staus bits */
/*! @{ */

#define AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_MASK  (0xFFFFFFFFU)
#define AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_SHIFT (0U)
/*! CS_DATA - Channel Status bits */
#define AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_SHIFT)) & AUDIO_XCVR_RX_CS_DATA_BITS_CS_DATA_MASK)
/*! @} */

/*! @name RX_USER_DATA_BITS - User data bits */
/*! @{ */

#define AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_MASK (0xFFFFFFFFU)
#define AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_SHIFT (0U)
/*! U_DATA - User data bits */
#define AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_SHIFT)) & AUDIO_XCVR_RX_USER_DATA_BITS_U_DATA_MASK)
/*! @} */

/*! @name RX_DPATH_CNTR_CTRL - Receive Datapath counter control register */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_MASK (0x1U)
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_SHIFT (0U)
/*! TS_EN - Timestamp counter enable */
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_SHIFT)) & AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_EN_MASK)

#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_MASK (0x2U)
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_SHIFT (1U)
/*! TS_INC - Timestamp Increment */
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC(x)  (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_SHIFT)) & AUDIO_XCVR_RX_DPATH_CNTR_CTRL_TS_INC_MASK)

#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK (0x100U)
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT (8U)
/*! RST_BIT_CNTR - Reset bit counter. */
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT)) & AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK)

#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK (0x200U)
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT (9U)
/*! RST_TS_CNTR - Reset timestamp counter. */
#define AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT)) & AUDIO_XCVR_RX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK)
/*! @} */

/*! @name RX_DPATH_TSCR - Receive Datapath Timestamp Counter Register */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_TSCR_CVAL_MASK       (0xFFFFFFFFU)
#define AUDIO_XCVR_RX_DPATH_TSCR_CVAL_SHIFT      (0U)
/*! CVAL - Timestamp counter value */
#define AUDIO_XCVR_RX_DPATH_TSCR_CVAL(x)         (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_TSCR_CVAL_SHIFT)) & AUDIO_XCVR_RX_DPATH_TSCR_CVAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCR - Receive Datapath Bit counter register */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_BCR_CVAL_MASK        (0xFFFFFFFFU)
#define AUDIO_XCVR_RX_DPATH_BCR_CVAL_SHIFT       (0U)
/*! CVAL - Bit count value */
#define AUDIO_XCVR_RX_DPATH_BCR_CVAL(x)          (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_BCR_CVAL_SHIFT)) & AUDIO_XCVR_RX_DPATH_BCR_CVAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCTR - Receive datapath Bit count timestamp register. */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_MASK    (0xFFFFFFFFU)
#define AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_SHIFT   (0U)
/*! BCT_VAL - Bit count timestamp value */
#define AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_SHIFT)) & AUDIO_XCVR_RX_DPATH_BCTR_BCT_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_BCRR - Receive datapath Bit read timestamp register. */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_MASK    (0xFFFFFFFFU)
#define AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_SHIFT   (0U)
/*! BCT_VAL - Bit count timestamp value */
#define AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_SHIFT)) & AUDIO_XCVR_RX_DPATH_BCRR_BCT_VAL_MASK)
/*! @} */

/*! @name PRE_MATCH_VAL - Preamble match value register */
/*! @{ */

#define AUDIO_XCVR_PRE_MATCH_VAL_PB_VAL_MASK     (0xFFFFU)
#define AUDIO_XCVR_PRE_MATCH_VAL_PB_VAL_SHIFT    (0U)
/*! PB_VAL - Preamble PB value */
#define AUDIO_XCVR_PRE_MATCH_VAL_PB_VAL(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_PRE_MATCH_VAL_PB_VAL_SHIFT)) & AUDIO_XCVR_PRE_MATCH_VAL_PB_VAL_MASK)

#define AUDIO_XCVR_PRE_MATCH_VAL_PA_VAL_MASK     (0xFFFF0000U)
#define AUDIO_XCVR_PRE_MATCH_VAL_PA_VAL_SHIFT    (16U)
/*! PA_VAL - Preamble PA value */
#define AUDIO_XCVR_PRE_MATCH_VAL_PA_VAL(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_PRE_MATCH_VAL_PA_VAL_SHIFT)) & AUDIO_XCVR_PRE_MATCH_VAL_PA_VAL_MASK)
/*! @} */

/*! @name DTS_PRE_MATCH_VAL - Preamble match value register */
/*! @{ */

#define AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PB_VAL_MASK (0xFFFFU)
#define AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PB_VAL_SHIFT (0U)
/*! DTS_PB_VAL - Preamble value */
#define AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PB_VAL(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PB_VAL_SHIFT)) & AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PB_VAL_MASK)

#define AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PA_VAL_MASK (0xFFFF0000U)
#define AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PA_VAL_SHIFT (16U)
/*! DTS_PA_VAL - Preamble value */
#define AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PA_VAL(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PA_VAL_SHIFT)) & AUDIO_XCVR_DTS_PRE_MATCH_VAL_DTS_PA_VAL_MASK)
/*! @} */

/*! @name RX_DPATH_PRE_ERR - Error count for IEC60958-1 Block Synchronization. */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_MASK (0xFFFFU)
#define AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_SHIFT (0U)
/*! PRE_ERRS - Preamble Error counter */
#define AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS(x)  (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_SHIFT)) & AUDIO_XCVR_RX_DPATH_PRE_ERR_PRE_ERRS_MASK)

#define AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_MASK   (0x80000000U)
#define AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_SHIFT  (31U)
/*! CLEAR - Clear bit for error counter. */
#define AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR(x)     (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_SHIFT)) & AUDIO_XCVR_RX_DPATH_PRE_ERR_CLEAR_MASK)
/*! @} */

/*! @name RX_DPATH_PARITY_ERR - Parity Error count for IEC60958-1 Blocks. */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_MASK (0xFFFFU)
#define AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_SHIFT (0U)
/*! PRE_ERRS - Parity Error counter */
#define AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_SHIFT)) & AUDIO_XCVR_RX_DPATH_PARITY_ERR_PRE_ERRS_MASK)

#define AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_MASK (0x80000000U)
#define AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_SHIFT (31U)
/*! CLEAR - Clear bit for error counter. */
#define AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR(x)  (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_SHIFT)) & AUDIO_XCVR_RX_DPATH_PARITY_ERR_CLEAR_MASK)
/*! @} */

/*! @name RX_DPATH_PKT_CNT - Receive Data packet count. */
/*! @{ */

#define AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_MASK     (0x7FFFFFFFU)
#define AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_SHIFT    (0U)
/*! VAL - Data packet counter */
#define AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL(x)       (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_SHIFT)) & AUDIO_XCVR_RX_DPATH_PKT_CNT_VAL_MASK)
/*! @} */

/*! @name PRE_MATCH_OFFSET - Preamble match offset value register */
/*! @{ */

#define AUDIO_XCVR_PRE_MATCH_OFFSET_PA_OFFSET_MASK (0xFFFFFFFFU)
#define AUDIO_XCVR_PRE_MATCH_OFFSET_PA_OFFSET_SHIFT (0U)
/*! PA_OFFSET - Sample count value for PA offset match */
#define AUDIO_XCVR_PRE_MATCH_OFFSET_PA_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_PRE_MATCH_OFFSET_PA_OFFSET_SHIFT)) & AUDIO_XCVR_PRE_MATCH_OFFSET_PA_OFFSET_MASK)
/*! @} */

/*! @name TX_DATAPATH_CTRL - Transmit Data path control register */
/*! @{ */

#define AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_MASK  (0x1U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_SHIFT (0U)
/*! CS_ACK - Channel Status ACK */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_CS_ACK_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_MASK  (0x2U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_SHIFT (1U)
/*! UD_ACK - User Data ACK */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_UD_ACK_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_MASK  (0x4U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_SHIFT (2U)
/*! CS_MOD - Enable Channel Status insertion */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_CS_MOD_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_MASK  (0x8U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_SHIFT (3U)
/*! UD_MOD - Enable User Data insertion */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_UD_MOD_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_MASK (0x10U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_SHIFT (4U)
/*! VLD_MOD - Enable Valid bit insertion */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_VLD_MOD_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_MASK (0x20U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_SHIFT (5U)
/*! FRM_VLD - Valid bit value */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_VLD_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_MASK (0x40U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_SHIFT (6U)
/*! EN_PARITY - Enable parity insertion */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PARITY_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_MASK (0x80U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_SHIFT (7U)
/*! EN_PREAMBLE - Enable preamble insertion */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_EN_PREAMBLE_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_MASK (0x800U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_SHIFT (11U)
/*! FRM_FMT - Frame format of input data */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_FRM_FMT_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_MASK (0x3000U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_SHIFT (12U)
/*! TX_FORMAT - Transmit data format */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_TX_FORMAT_MASK)

#define AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK (0x4000U)
#define AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_SHIFT (14U)
/*! STRT_DATA_TX - Start transmit of data. */
#define AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_SHIFT)) & AUDIO_XCVR_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK)
/*! @} */

/*! @name TX_CS_DATA_BITS - Channel staus bits */
/*! @{ */

#define AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_MASK  (0xFFFFFFFFU)
#define AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_SHIFT (0U)
/*! CS_DATA - Channel Status bits / block */
#define AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA(x)    (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_SHIFT)) & AUDIO_XCVR_TX_CS_DATA_BITS_CS_DATA_MASK)
/*! @} */

/*! @name TX_USER_DATA_BITS - User data bits */
/*! @{ */

#define AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_MASK (0xFFFFFFFFU)
#define AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_SHIFT (0U)
/*! U_DATA - User data bits/block */
#define AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_SHIFT)) & AUDIO_XCVR_TX_USER_DATA_BITS_U_DATA_MASK)
/*! @} */

/*! @name TX_DPATH_CNTR_CTRL - Transmit datapath counter control register */
/*! @{ */

#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_MASK (0x1U)
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_SHIFT (0U)
/*! TS_EN - Timestamp counter enable */
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN(x)   (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_SHIFT)) & AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_EN_MASK)

#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_MASK (0x2U)
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_SHIFT (1U)
/*! TS_INC - Timestamp Increment */
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC(x)  (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_SHIFT)) & AUDIO_XCVR_TX_DPATH_CNTR_CTRL_TS_INC_MASK)

#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK (0x100U)
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT (8U)
/*! RST_BIT_CNTR - Reset bit counter. */
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_SHIFT)) & AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_BIT_CNTR_MASK)

#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK (0x200U)
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT (9U)
/*! RST_TS_CNTR - Reset timestamp counter. */
#define AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR(x) (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_SHIFT)) & AUDIO_XCVR_TX_DPATH_CNTR_CTRL_RST_TS_CNTR_MASK)
/*! @} */

/*! @name TX_DPATH_TSCR - Transmit Datapath Timestamp Counter Register */
/*! @{ */

#define AUDIO_XCVR_TX_DPATH_TSCR_CVAL_MASK       (0xFFFFFFFFU)
#define AUDIO_XCVR_TX_DPATH_TSCR_CVAL_SHIFT      (0U)
/*! CVAL - Timestamp counter value */
#define AUDIO_XCVR_TX_DPATH_TSCR_CVAL(x)         (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_TSCR_CVAL_SHIFT)) & AUDIO_XCVR_TX_DPATH_TSCR_CVAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCR - Transmit Datapath Bit counter register */
/*! @{ */

#define AUDIO_XCVR_TX_DPATH_BCR_CVAL_MASK        (0xFFFFFFFFU)
#define AUDIO_XCVR_TX_DPATH_BCR_CVAL_SHIFT       (0U)
/*! CVAL - Bit count value */
#define AUDIO_XCVR_TX_DPATH_BCR_CVAL(x)          (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_BCR_CVAL_SHIFT)) & AUDIO_XCVR_TX_DPATH_BCR_CVAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCTR - Transmit datapath Bit count timestamp register. */
/*! @{ */

#define AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_MASK    (0xFFFFFFFFU)
#define AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_SHIFT   (0U)
/*! BCT_VAL - Bit count timestamp value */
#define AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_SHIFT)) & AUDIO_XCVR_TX_DPATH_BCTR_BCT_VAL_MASK)
/*! @} */

/*! @name TX_DPATH_BCRR - Transmmit datapath Bit read timestamp register. */
/*! @{ */

#define AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_MASK    (0xFFFFFFFFU)
#define AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_SHIFT   (0U)
/*! BCT_VAL - Bit count timestamp value */
#define AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_SHIFT)) & AUDIO_XCVR_TX_DPATH_BCRR_BCT_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AUDIO_XCVR_Register_Masks */


/*!
 * @}
 */ /* end of group AUDIO_XCVR_Peripheral_Access_Layer */


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


#endif  /* PERI_AUDIO_XCVR_H_ */

