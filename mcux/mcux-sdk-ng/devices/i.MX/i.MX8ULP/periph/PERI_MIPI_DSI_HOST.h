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
**         CMSIS Peripheral Access Layer for MIPI_DSI_HOST
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
 * @file PERI_MIPI_DSI_HOST.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 */

#if !defined(PERI_MIPI_DSI_HOST_H_)
#define PERI_MIPI_DSI_HOST_H_                    /**< Symbol preventing repeated inclusion */

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
   -- MIPI_DSI_HOST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_Peripheral_Access_Layer MIPI_DSI_HOST Peripheral Access Layer
 * @{
 */

/** MIPI_DSI_HOST - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_NUM_LANES;                     /**< offset: 0x0 */
  __IO uint32_t CFG_NONCONTINUOUS_CLK;             /**< offset: 0x4 */
  __IO uint32_t CFG_T_PRE;                         /**< offset: 0x8 */
  __IO uint32_t CFG_T_POST;                        /**< offset: 0xC */
  __IO uint32_t CFG_TX_GAP;                        /**< offset: 0x10 */
  __IO uint32_t CFG_AUTOINSERT_EOTP;               /**< offset: 0x14 */
  __IO uint32_t CFG_EXTRA_CMDS_AFTER_EOTP;         /**< offset: 0x18 */
  __IO uint32_t CFG_HTX_TO_COUNT;                  /**< offset: 0x1C */
  __IO uint32_t CFG_LRX_H_TO_COUNT;                /**< offset: 0x20 */
  __IO uint32_t CFG_BTA_H_TO_COUNT;                /**< offset: 0x24 */
  __IO uint32_t CFG_TWAKEUP;                       /**< offset: 0x28 */
  __I  uint32_t CFG_STATUS_OUT;                    /**< offset: 0x2C */
  __I  uint32_t RX_ERROR_STATUS;                   /**< offset: 0x30 */
       uint8_t RESERVED_0[204];
  __IO uint32_t CFG_DBI_PIXEL_PAYLOAD_SIZE;        /**< offset: 0x100 */
  __IO uint32_t CFG_DBI_PIXEL_FIFO_SEND_LEVEL;     /**< offset: 0x104 */
       uint8_t RESERVED_1[248];
  __IO uint32_t CFG_DPI_PIXEL_PAYLOAD_SIZE;        /**< offset: 0x200 */
  __IO uint32_t CFG_DPI_PIXEL_FIFO_SEND_LEVEL;     /**< offset: 0x204 */
  __IO uint32_t CFG_DPI_INTERFACE_COLOR_CODING;    /**< offset: 0x208 */
  __IO uint32_t CFG_DPI_PIXEL_FORMAT;              /**< offset: 0x20C */
  __IO uint32_t CFG_DPI_VSYNC_POLARITY;            /**< offset: 0x210 */
  __IO uint32_t CFG_DPI_HSYNC_POLARITY;            /**< offset: 0x214 */
  __IO uint32_t CFG_DPI_VIDEO_MODE;                /**< offset: 0x218 */
  __IO uint32_t CFG_DPI_HFP;                       /**< offset: 0x21C */
  __IO uint32_t CFG_DPI_HBP;                       /**< offset: 0x220 */
  __IO uint32_t CFG_DPI_HSA;                       /**< offset: 0x224 */
  __IO uint32_t CFG_DPI_ENABLE_MULT_PKTS;          /**< offset: 0x228 */
  __IO uint32_t CFG_DPI_VBP;                       /**< offset: 0x22C */
  __IO uint32_t CFG_DPI_VFP;                       /**< offset: 0x230 */
  __IO uint32_t CFG_DPI_BLLP_MODE;                 /**< offset: 0x234 */
  __IO uint32_t CFG_DPI_USE_NULL_PKT_BLLP;         /**< offset: 0x238 */
  __IO uint32_t CFG_DPI_VACTIVE;                   /**< offset: 0x23C */
  __IO uint32_t CFG_DPI_VC;                        /**< offset: 0x240 */
       uint8_t RESERVED_2[60];
  __IO uint32_t TX_PAYLOAD;                        /**< offset: 0x280 */
  __IO uint32_t PKT_CONTROL;                       /**< offset: 0x284 */
  __IO uint32_t SEND_PACKET;                       /**< offset: 0x288 */
  __I  uint32_t PKT_STATUS;                        /**< offset: 0x28C */
  __I  uint32_t PKT_FIFO_WR_LEVEL;                 /**< offset: 0x290 */
  __I  uint32_t PKT_FIFO_RD_LEVEL;                 /**< offset: 0x294 */
  __I  uint32_t PKT_RX_PAYLOAD;                    /**< offset: 0x298 */
  __I  uint32_t PKT_RX_PKT_HEADER;                 /**< offset: 0x29C */
  __I  uint32_t IRQ_STATUS;                        /**< offset: 0x2A0 */
  __I  uint32_t IRQ_STATUS2;                       /**< offset: 0x2A4 */
  __IO uint32_t IRQ_MASK;                          /**< offset: 0x2A8 */
  __IO uint32_t IRQ_MASK2;                         /**< offset: 0x2AC */
       uint8_t RESERVED_3[80];
  __IO uint32_t PD_DPHY;                           /**< offset: 0x300 */
  __IO uint32_t M_PRG_HS_PREPARE;                  /**< offset: 0x304 */
  __IO uint32_t MC_PRG_HS_PREPARE;                 /**< offset: 0x308 */
  __IO uint32_t M_PRG_HS_ZERO;                     /**< offset: 0x30C */
  __IO uint32_t MC_PRG_HS_ZERO;                    /**< offset: 0x310 */
  __IO uint32_t M_PRG_HS_TRAIL;                    /**< offset: 0x314 */
  __IO uint32_t MC_PRG_HS_TRAIL;                   /**< offset: 0x318 */
  __IO uint32_t MC_PRG_RXHS_SETTLE;                /**< offset: 0x31C */
  __IO uint32_t M_PRG_RXHS_SETTLE;                 /**< offset: 0x320 */
  __IO uint32_t PD_PLL;                            /**< offset: 0x324 */
  __IO uint32_t TST;                               /**< offset: 0x328 */
  __IO uint32_t CN;                                /**< offset: 0x32C */
  __IO uint32_t CM;                                /**< offset: 0x330 */
  __IO uint32_t CO;                                /**< offset: 0x334 */
  __I  uint32_t LOCK;                              /**< offset: 0x338 */
  __IO uint32_t LOCK_BYP;                          /**< offset: 0x33C */
  __IO uint32_t AUTO_PD_EN;                        /**< offset: 0x340 */
  __IO uint32_t RXLPRP;                            /**< offset: 0x344 */
  __IO uint32_t RXCDRP;                            /**< offset: 0x348 */
} MIPI_DSI_HOST_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI_HOST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_Register_Masks MIPI_DSI_HOST Register Masks
 * @{
 */

/*! @name CFG_NUM_LANES -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_NUM_LANES_NUM_LANES_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_NUM_LANES_NUM_LANES_SHIFT (0U)
/*! NUM_LANES - Sets the number of active lanes that are to be used for transmitting data. */
#define MIPI_DSI_HOST_CFG_NUM_LANES_NUM_LANES(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_NUM_LANES_NUM_LANES_SHIFT)) & MIPI_DSI_HOST_CFG_NUM_LANES_NUM_LANES_MASK)
/*! @} */

/*! @name CFG_NONCONTINUOUS_CLK -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_SHIFT (0U)
/*! CLK_MODE - Sets the Host Controller into non-continuous MIPI clock mode. */
#define MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_SHIFT)) & MIPI_DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_MASK)
/*! @} */

/*! @name CFG_T_PRE -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_T_PRE_NUM_PERIODS_MASK (0x7FU)
#define MIPI_DSI_HOST_CFG_T_PRE_NUM_PERIODS_SHIFT (0U)
#define MIPI_DSI_HOST_CFG_T_PRE_NUM_PERIODS(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_T_PRE_NUM_PERIODS_SHIFT)) & MIPI_DSI_HOST_CFG_T_PRE_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_T_POST -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_T_POST_NUM_PERIODS_MASK (0x7FU)
#define MIPI_DSI_HOST_CFG_T_POST_NUM_PERIODS_SHIFT (0U)
#define MIPI_DSI_HOST_CFG_T_POST_NUM_PERIODS(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_T_POST_NUM_PERIODS_SHIFT)) & MIPI_DSI_HOST_CFG_T_POST_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_TX_GAP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_TX_GAP_NUM_PERIODS_MASK (0x7FU)
#define MIPI_DSI_HOST_CFG_TX_GAP_NUM_PERIODS_SHIFT (0U)
#define MIPI_DSI_HOST_CFG_TX_GAP_NUM_PERIODS(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_TX_GAP_NUM_PERIODS_SHIFT)) & MIPI_DSI_HOST_CFG_TX_GAP_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_AUTOINSERT_EOTP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_SHIFT (0U)
#define MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_SHIFT)) & MIPI_DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_MASK)
/*! @} */

/*! @name CFG_EXTRA_CMDS_AFTER_EOTP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_SHIFT (0U)
/*! EXTRA_EOTP - Configures the DSI Host Controller to send extra End Of Transmission Packets after the end of a packet. */
#define MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_SHIFT)) & MIPI_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_MASK)
/*! @} */

/*! @name CFG_HTX_TO_COUNT -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_COUNT_SHIFT (0U)
#define MIPI_DSI_HOST_CFG_HTX_TO_COUNT_COUNT(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_HTX_TO_COUNT_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_HTX_TO_COUNT_COUNT_MASK)
/*! @} */

/*! @name CFG_LRX_H_TO_COUNT -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_SHIFT (0U)
#define MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_MASK)
/*! @} */

/*! @name CFG_BTA_H_TO_COUNT -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_SHIFT (0U)
/*! COUNT - Sets the value of the DSI Host Bus Turn Around (BTA) timeout in clk_byte clock periods
 *    that once reached will initiate a timeout error.
 */
#define MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_SHIFT)) & MIPI_DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_MASK)
/*! @} */

/*! @name CFG_TWAKEUP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_MASK (0x7FFFFU)
#define MIPI_DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_SHIFT (0U)
/*! NUM_PERIODS - DPHY Twakeup timing parameter. */
#define MIPI_DSI_HOST_CFG_TWAKEUP_NUM_PERIODS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_SHIFT)) & MIPI_DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_STATUS_OUT -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_STATUS_OUT_STATUS_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_CFG_STATUS_OUT_STATUS_SHIFT (0U)
/*! STATUS - Status Register */
#define MIPI_DSI_HOST_CFG_STATUS_OUT_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_STATUS_OUT_STATUS_SHIFT)) & MIPI_DSI_HOST_CFG_STATUS_OUT_STATUS_MASK)
/*! @} */

/*! @name RX_ERROR_STATUS -  */
/*! @{ */

#define MIPI_DSI_HOST_RX_ERROR_STATUS_STATUS_MASK (0x7FFU)
#define MIPI_DSI_HOST_RX_ERROR_STATUS_STATUS_SHIFT (0U)
/*! STATUS - Status Register for Host receive error detection, ECC errors, CRC errors and for timeout indicators */
#define MIPI_DSI_HOST_RX_ERROR_STATUS_STATUS(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RX_ERROR_STATUS_STATUS_SHIFT)) & MIPI_DSI_HOST_RX_ERROR_STATUS_STATUS_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_PAYLOAD_SIZE -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Maximum number of pixels that should be sent as one DSI packet. */
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DBI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_FIFO_SEND_LEVEL -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! FIFO_SEND_LEVEL - In order to optimize DSI utility, the DBI bridge buffers a certain number of DBI pixels before initiating a DSI packet. */
#define MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT)) & MIPI_DSI_HOST_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_PAYLOAD_SIZE -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Maximum number of pixels that should be sent as one DSI packet. */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_PAYLOAD_SIZE_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_FIFO_SEND_LEVEL -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT (0U)
/*! FIFO_SEND_LEVEL - In order to optimize DSI utility, the DPI bridge buffers a cerntain number of DPI pixels before initiating a DSI packet. */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_FIFO_SEND_LEVEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name CFG_DPI_INTERFACE_COLOR_CODING -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_RGB_CONFIG_MASK (0x7U)
#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_RGB_CONFIG_SHIFT (0U)
/*! RGB_CONFIG - Sets the distribution of RGB bits within the 24-bit d bus, as specified by the DPI specification.
 *  0b000..16-bit Configuration 1
 *  0b001..16-bit Configuration 2
 *  0b010..16-bit Configuration 3
 *  0b011..18-bit Configuration 1
 *  0b100..18-bit Configuration 2
 *  0b101..24-bit
 */
#define MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_RGB_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_RGB_CONFIG_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_INTERFACE_COLOR_CODING_RGB_CONFIG_MASK)
/*! @} */

/*! @name CFG_DPI_PIXEL_FORMAT -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_PIXEL_FORMAT_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_PIXEL_FORMAT_SHIFT (0U)
/*! PIXEL_FORMAT - Sets the DSI packet type of the pixels.
 *  0b00..16 bit
 *  0b01..18 bit
 *  0b10..18 bit loosely packed
 *  0b11..24 bit
 */
#define MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_PIXEL_FORMAT_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_PIXEL_FORMAT_PIXEL_FORMAT_MASK)
/*! @} */

/*! @name CFG_DPI_VSYNC_POLARITY -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_VSYNC_POLARITY_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_VSYNC_POLARITY_SHIFT (0U)
/*! VSYNC_POLARITY - Sets polarity of dpi_vsync_input
 *  0b0..active low
 *  0b1..active high
 */
#define MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_VSYNC_POLARITY_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VSYNC_POLARITY_VSYNC_POLARITY_MASK)
/*! @} */

/*! @name CFG_DPI_HSYNC_POLARITY -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_HSYNC_POLARITY_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_HSYNC_POLARITY_SHIFT (0U)
/*! HSYNC_POLARITY - Sets polarity of dpi_hsync_input
 *  0b0..active low
 *  0b1..active high
 */
#define MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_HSYNC_POLARITY_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HSYNC_POLARITY_HSYNC_POLARITY_MASK)
/*! @} */

/*! @name CFG_DPI_VIDEO_MODE -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_VIDEO_MODE_MASK (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_VIDEO_MODE_SHIFT (0U)
/*! VIDEO_MODE - Select DSI video mode that the host DPI module should generate packets for.
 *  0b00..Non-Burst mode with Sync Pulses
 *  0b01..Non-Burst mode with Sync Events
 *  0b10..Burst mode
 *  0b11..Reserved, not valid
 */
#define MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_VIDEO_MODE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VIDEO_MODE_VIDEO_MODE_MASK)
/*! @} */

/*! @name CFG_DPI_HFP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HFP_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HFP_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Sets the DSI packet payload size, in bytes, of the horizontal front porch blanking packet. */
#define MIPI_DSI_HOST_CFG_DPI_HFP_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HFP_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HFP_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DPI_HBP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HBP_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HBP_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Sets the DSI packet payload size, in bytes, of the horizontal back porch blanking packet. */
#define MIPI_DSI_HOST_CFG_DPI_HBP_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HBP_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HBP_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DPI_HSA -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_HSA_PAYLOAD_SIZE_MASK (0xFFFFU)
#define MIPI_DSI_HOST_CFG_DPI_HSA_PAYLOAD_SIZE_SHIFT (0U)
/*! PAYLOAD_SIZE - Sets the DSI packet payload size, in bytes, of the horizontal sync width filler blanking packet. */
#define MIPI_DSI_HOST_CFG_DPI_HSA_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_HSA_PAYLOAD_SIZE_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_HSA_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DPI_ENABLE_MULT_PKTS -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_SHIFT (0U)
/*! ENABLE_MULT_PKTS - Enable Multiple packets per video line.
 *  0b0..Video Line is sent in a single packet
 *  0b1..Video Line is sent in two packets
 */
#define MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_ENABLE_MULT_PKTS_ENABLE_MULT_PKTS_MASK)
/*! @} */

/*! @name CFG_DPI_VBP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VBP_NUM_LINES_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_DPI_VBP_NUM_LINES_SHIFT (0U)
/*! NUM_LINES - Sets the number of lines in the vertical back porch. */
#define MIPI_DSI_HOST_CFG_DPI_VBP_NUM_LINES(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VBP_NUM_LINES_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VBP_NUM_LINES_MASK)
/*! @} */

/*! @name CFG_DPI_VFP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VFP_NUM_LINES_MASK (0xFFU)
#define MIPI_DSI_HOST_CFG_DPI_VFP_NUM_LINES_SHIFT (0U)
/*! NUM_LINES - Sets the number of lines in the vertical front porch. */
#define MIPI_DSI_HOST_CFG_DPI_VFP_NUM_LINES(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VFP_NUM_LINES_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VFP_NUM_LINES_MASK)
/*! @} */

/*! @name CFG_DPI_BLLP_MODE -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_LP_MASK  (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_LP_SHIFT (0U)
/*! LP - Optimize bllp periods to Low Power mode when possible
 *  0b0..Blanking packets are sent during BLLP periods
 *  0b1..LP mode is used for BLLP periods
 */
#define MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_LP(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_LP_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_BLLP_MODE_LP_MASK)
/*! @} */

/*! @name CFG_DPI_USE_NULL_PKT_BLLP -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_NULL_MASK (0x1U)
#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_NULL_SHIFT (0U)
/*! NULL - Selects type of blanking packet to be sent during bllp region
 *  0b0..Blanking packet used in bllp region
 *  0b1..Null packet used in bllp region
 */
#define MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_NULL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_NULL_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_USE_NULL_PKT_BLLP_NULL_MASK)
/*! @} */

/*! @name CFG_DPI_VACTIVE -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_NUM_LINES_MASK (0x3FFFU)
#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_NUM_LINES_SHIFT (0U)
/*! NUM_LINES - Sets the number of lines in the vertical active aread. */
#define MIPI_DSI_HOST_CFG_DPI_VACTIVE_NUM_LINES(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VACTIVE_NUM_LINES_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VACTIVE_NUM_LINES_MASK)
/*! @} */

/*! @name CFG_DPI_VC -  */
/*! @{ */

#define MIPI_DSI_HOST_CFG_DPI_VC_SET_VC_MASK     (0x3U)
#define MIPI_DSI_HOST_CFG_DPI_VC_SET_VC_SHIFT    (0U)
/*! SET_VC - Sets the Virtual Channel (VC) of packets that will be sent to the receive packet interface. */
#define MIPI_DSI_HOST_CFG_DPI_VC_SET_VC(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CFG_DPI_VC_SET_VC_SHIFT)) & MIPI_DSI_HOST_CFG_DPI_VC_SET_VC_MASK)
/*! @} */

/*! @name TX_PAYLOAD -  */
/*! @{ */

#define MIPI_DSI_HOST_TX_PAYLOAD_PAYLOAD_MASK    (0xFFFFFFFFU)
#define MIPI_DSI_HOST_TX_PAYLOAD_PAYLOAD_SHIFT   (0U)
/*! PAYLOAD - Tx Payload data write register. */
#define MIPI_DSI_HOST_TX_PAYLOAD_PAYLOAD(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_TX_PAYLOAD_PAYLOAD_SHIFT)) & MIPI_DSI_HOST_TX_PAYLOAD_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_CONTROL -  */
/*! @{ */

#define MIPI_DSI_HOST_PKT_CONTROL_CTRL_MASK      (0x7FFFFFFU)
#define MIPI_DSI_HOST_PKT_CONTROL_CTRL_SHIFT     (0U)
/*! CTRL - Tx packet control register. */
#define MIPI_DSI_HOST_PKT_CONTROL_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_CONTROL_CTRL_SHIFT)) & MIPI_DSI_HOST_PKT_CONTROL_CTRL_MASK)
/*! @} */

/*! @name SEND_PACKET -  */
/*! @{ */

#define MIPI_DSI_HOST_SEND_PACKET_TX_SEND_MASK   (0x1U)
#define MIPI_DSI_HOST_SEND_PACKET_TX_SEND_SHIFT  (0U)
/*! TX_SEND - Tx send packet, writing to this register causes the packet described in dsi_host_pkt_control to be sent. */
#define MIPI_DSI_HOST_SEND_PACKET_TX_SEND(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_SEND_PACKET_TX_SEND_SHIFT)) & MIPI_DSI_HOST_SEND_PACKET_TX_SEND_MASK)
/*! @} */

/*! @name PKT_STATUS -  */
/*! @{ */

#define MIPI_DSI_HOST_PKT_STATUS_STATUS_MASK     (0x1FFU)
#define MIPI_DSI_HOST_PKT_STATUS_STATUS_SHIFT    (0U)
/*! STATUS - Status of APB to packet interface */
#define MIPI_DSI_HOST_PKT_STATUS_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_STATUS_STATUS_SHIFT)) & MIPI_DSI_HOST_PKT_STATUS_STATUS_MASK)
/*! @} */

/*! @name PKT_FIFO_WR_LEVEL -  */
/*! @{ */

#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_WR_MASK  (0xFFFFU)
#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_WR_SHIFT (0U)
/*! WR - Write level of APB to pkt interface fifo */
#define MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_WR(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_WR_SHIFT)) & MIPI_DSI_HOST_PKT_FIFO_WR_LEVEL_WR_MASK)
/*! @} */

/*! @name PKT_FIFO_RD_LEVEL -  */
/*! @{ */

#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_RD_MASK  (0xFFFFU)
#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_RD_SHIFT (0U)
/*! RD - Read level of APB to pkt interface fifo */
#define MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_RD(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_RD_SHIFT)) & MIPI_DSI_HOST_PKT_FIFO_RD_LEVEL_RD_MASK)
/*! @} */

/*! @name PKT_RX_PAYLOAD -  */
/*! @{ */

#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PAYLOAD_MASK (0xFFFFFFFFU)
#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PAYLOAD_SHIFT (0U)
/*! PAYLOAD - APB to pkt interface rx payload read */
#define MIPI_DSI_HOST_PKT_RX_PAYLOAD_PAYLOAD(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_RX_PAYLOAD_PAYLOAD_SHIFT)) & MIPI_DSI_HOST_PKT_RX_PAYLOAD_PAYLOAD_MASK)
/*! @} */

/*! @name PKT_RX_PKT_HEADER -  */
/*! @{ */

#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_HEADER_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_HEADER_SHIFT (0U)
/*! HEADER - APB to pkt interface rx packet header [15:0] word count [21:16] data type [23:22] Virtual Channel */
#define MIPI_DSI_HOST_PKT_RX_PKT_HEADER_HEADER(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PKT_RX_PKT_HEADER_HEADER_SHIFT)) & MIPI_DSI_HOST_PKT_RX_PKT_HEADER_HEADER_MASK)
/*! @} */

/*! @name IRQ_STATUS -  */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_STATUS_STATUS_MASK     (0xFFFFFFFFU)
#define MIPI_DSI_HOST_IRQ_STATUS_STATUS_SHIFT    (0U)
#define MIPI_DSI_HOST_IRQ_STATUS_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_STATUS_STATUS_SHIFT)) & MIPI_DSI_HOST_IRQ_STATUS_STATUS_MASK)
/*! @} */

/*! @name IRQ_STATUS2 -  */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_STATUS2_STATUS2_MASK   (0x7U)
#define MIPI_DSI_HOST_IRQ_STATUS2_STATUS2_SHIFT  (0U)
/*! STATUS2 - Status of APB to packet interface part 2, read part 2 first then dsi_host_irq_status. */
#define MIPI_DSI_HOST_IRQ_STATUS2_STATUS2(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_STATUS2_STATUS2_SHIFT)) & MIPI_DSI_HOST_IRQ_STATUS2_STATUS2_MASK)
/*! @} */

/*! @name IRQ_MASK -  */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_MASK_MASK_MASK         (0xFFFFFFFFU)
#define MIPI_DSI_HOST_IRQ_MASK_MASK_SHIFT        (0U)
/*! MASK - IRQ Mask */
#define MIPI_DSI_HOST_IRQ_MASK_MASK(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_MASK_MASK_SHIFT)) & MIPI_DSI_HOST_IRQ_MASK_MASK_MASK)
/*! @} */

/*! @name IRQ_MASK2 -  */
/*! @{ */

#define MIPI_DSI_HOST_IRQ_MASK2_MASK2_MASK       (0x7U)
#define MIPI_DSI_HOST_IRQ_MASK2_MASK2_SHIFT      (0U)
/*! MASK2 - IRQ Mask 2 */
#define MIPI_DSI_HOST_IRQ_MASK2_MASK2(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_IRQ_MASK2_MASK2_SHIFT)) & MIPI_DSI_HOST_IRQ_MASK2_MASK2_MASK)
/*! @} */

/*! @name PD_DPHY -  */
/*! @{ */

#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY_MASK       (0x1U)
#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY_SHIFT      (0U)
/*! PD_DPHY - Power Down input for PHY. When high, all PHY blocks are powered down. */
#define MIPI_DSI_HOST_PD_DPHY_PD_DPHY(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PD_DPHY_PD_DPHY_SHIFT)) & MIPI_DSI_HOST_PD_DPHY_PD_DPHY_MASK)
/*! @} */

/*! @name M_PRG_HS_PREPARE -  */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_MASK (0x3U)
#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_SHIFT (0U)
#define MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_PREPARE_M_PRG_HS_PREPARE_MASK)
/*! @} */

/*! @name MC_PRG_HS_PREPARE -  */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_MASK (0x1U)
#define MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_SHIFT (0U)
#define MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_PREPARE_MC_PRG_HS_PREPARE_MASK)
/*! @} */

/*! @name M_PRG_HS_ZERO -  */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_MASK (0x3FU)
#define MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_SHIFT (0U)
#define MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_ZERO_M_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name MC_PRG_HS_ZERO -  */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_MASK (0x7FU)
#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_SHIFT (0U)
#define MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_ZERO_MC_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name M_PRG_HS_TRAIL -  */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_MASK (0x1FU)
#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_SHIFT (0U)
#define MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_SHIFT)) & MIPI_DSI_HOST_M_PRG_HS_TRAIL_M_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name MC_PRG_HS_TRAIL -  */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_MASK (0x1FU)
#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_SHIFT (0U)
#define MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_SHIFT)) & MIPI_DSI_HOST_MC_PRG_HS_TRAIL_MC_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name MC_PRG_RXHS_SETTLE -  */
/*! @{ */

#define MIPI_DSI_HOST_MC_PRG_RXHS_SETTLE_MC_PRG_RXHS_SETTLE_MASK (0x3FU)
#define MIPI_DSI_HOST_MC_PRG_RXHS_SETTLE_MC_PRG_RXHS_SETTLE_SHIFT (0U)
#define MIPI_DSI_HOST_MC_PRG_RXHS_SETTLE_MC_PRG_RXHS_SETTLE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_MC_PRG_RXHS_SETTLE_MC_PRG_RXHS_SETTLE_SHIFT)) & MIPI_DSI_HOST_MC_PRG_RXHS_SETTLE_MC_PRG_RXHS_SETTLE_MASK)
/*! @} */

/*! @name M_PRG_RXHS_SETTLE -  */
/*! @{ */

#define MIPI_DSI_HOST_M_PRG_RXHS_SETTLE_M_PRG_RXHS_SETTLE_MASK (0x3FU)
#define MIPI_DSI_HOST_M_PRG_RXHS_SETTLE_M_PRG_RXHS_SETTLE_SHIFT (0U)
#define MIPI_DSI_HOST_M_PRG_RXHS_SETTLE_M_PRG_RXHS_SETTLE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_M_PRG_RXHS_SETTLE_M_PRG_RXHS_SETTLE_SHIFT)) & MIPI_DSI_HOST_M_PRG_RXHS_SETTLE_M_PRG_RXHS_SETTLE_MASK)
/*! @} */

/*! @name PD_PLL -  */
/*! @{ */

#define MIPI_DSI_HOST_PD_PLL_PD_PLL_MASK         (0x1U)
#define MIPI_DSI_HOST_PD_PLL_PD_PLL_SHIFT        (0U)
/*! PD_PLL - Power-down signal. When high, the PLL is powered down. */
#define MIPI_DSI_HOST_PD_PLL_PD_PLL(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_PD_PLL_PD_PLL_SHIFT)) & MIPI_DSI_HOST_PD_PLL_PD_PLL_MASK)
/*! @} */

/*! @name TST -  */
/*! @{ */

#define MIPI_DSI_HOST_TST_TST_MASK               (0x3FU)
#define MIPI_DSI_HOST_TST_TST_SHIFT              (0U)
/*! TST - Test Pins */
#define MIPI_DSI_HOST_TST_TST(x)                 (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_TST_TST_SHIFT)) & MIPI_DSI_HOST_TST_TST_MASK)
/*! @} */

/*! @name CN -  */
/*! @{ */

#define MIPI_DSI_HOST_CN_CN_MASK                 (0x1FU)
#define MIPI_DSI_HOST_CN_CN_SHIFT                (0U)
/*! CN - Control N divider */
#define MIPI_DSI_HOST_CN_CN(x)                   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CN_CN_SHIFT)) & MIPI_DSI_HOST_CN_CN_MASK)
/*! @} */

/*! @name CM -  */
/*! @{ */

#define MIPI_DSI_HOST_CM_CM_MASK                 (0xFFU)
#define MIPI_DSI_HOST_CM_CM_SHIFT                (0U)
/*! CM - Control M divider */
#define MIPI_DSI_HOST_CM_CM(x)                   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CM_CM_SHIFT)) & MIPI_DSI_HOST_CM_CM_MASK)
/*! @} */

/*! @name CO -  */
/*! @{ */

#define MIPI_DSI_HOST_CO_CO_MASK                 (0x3U)
#define MIPI_DSI_HOST_CO_CO_SHIFT                (0U)
/*! CO - Control O divider
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 4
 *  0b11..Divide by 8
 */
#define MIPI_DSI_HOST_CO_CO(x)                   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_CO_CO_SHIFT)) & MIPI_DSI_HOST_CO_CO_MASK)
/*! @} */

/*! @name LOCK -  */
/*! @{ */

#define MIPI_DSI_HOST_LOCK_LOCK_MASK             (0x1U)
#define MIPI_DSI_HOST_LOCK_LOCK_SHIFT            (0U)
/*! LOCK - Lock Detect output. Asserted when the PLL has achieved frequency lock. */
#define MIPI_DSI_HOST_LOCK_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_LOCK_LOCK_SHIFT)) & MIPI_DSI_HOST_LOCK_LOCK_MASK)
/*! @} */

/*! @name LOCK_BYP -  */
/*! @{ */

#define MIPI_DSI_HOST_LOCK_BYP_LOCK_BYP_MASK     (0x1U)
#define MIPI_DSI_HOST_LOCK_BYP_LOCK_BYP_SHIFT    (0U)
/*! LOCK_BYP - When clock lane exits from ULPS, this input determines if the PLL LOCK signal will be used to gate the TxByteClkHS
 *  0b0..PLL LOCK signal will gate TxByteClkHS clock [Default]
 *  0b1..PLL LOCK signal will not gate TxByteClkHS clock, CIL based counter will be used to gate the TxByteClkHS.
 */
#define MIPI_DSI_HOST_LOCK_BYP_LOCK_BYP(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_LOCK_BYP_LOCK_BYP_SHIFT)) & MIPI_DSI_HOST_LOCK_BYP_LOCK_BYP_MASK)
/*! @} */

/*! @name AUTO_PD_EN -  */
/*! @{ */

#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_MASK (0x1U)
#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_SHIFT (0U)
/*! AUTO_PD_EN - Powers down inactive lanes reported by CFG_NUM_LANES input bus
 *  0b0..Inactive lanes are powered up and driving LP11.
 *  0b1..Inactive lanes are powered down [Default].
 */
#define MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_SHIFT)) & MIPI_DSI_HOST_AUTO_PD_EN_AUTO_PD_EN_MASK)
/*! @} */

/*! @name RXLPRP -  */
/*! @{ */

#define MIPI_DSI_HOST_RXLPRP_RXLPRP_MASK         (0x3U)
#define MIPI_DSI_HOST_RXLPRP_RXLPRP_SHIFT        (0U)
/*! RXLPRP - This field adjusts the threshold voltage and hysteresis of LP-RX. Default value 2'b01. */
#define MIPI_DSI_HOST_RXLPRP_RXLPRP(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RXLPRP_RXLPRP_SHIFT)) & MIPI_DSI_HOST_RXLPRP_RXLPRP_MASK)
/*! @} */

/*! @name RXCDRP -  */
/*! @{ */

#define MIPI_DSI_HOST_RXCDRP_RXCDRP_MASK         (0x3U)
#define MIPI_DSI_HOST_RXCDRP_RXCDRP_SHIFT        (0U)
/*! RXCDRP - This field adjusts the threshold voltage of LP-CD. Default value 2'b01. */
#define MIPI_DSI_HOST_RXCDRP_RXCDRP(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_RXCDRP_RXCDRP_SHIFT)) & MIPI_DSI_HOST_RXCDRP_RXCDRP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_DSI_HOST_H_ */

