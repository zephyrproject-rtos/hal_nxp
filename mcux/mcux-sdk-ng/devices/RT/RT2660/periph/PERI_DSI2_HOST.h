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
**         CMSIS Peripheral Access Layer for DSI2_HOST
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
 * @file PERI_DSI2_HOST.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DSI2_HOST
 *
 * CMSIS Peripheral Access Layer for DSI2_HOST
 */

#if !defined(PERI_DSI2_HOST_H_)
#define PERI_DSI2_HOST_H_                        /**< Symbol preventing repeated inclusion */

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
   -- DSI2_HOST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_Peripheral_Access_Layer DSI2_HOST Peripheral Access Layer
 * @{
 */

/** DSI2_HOST - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_MODE;                          /**< Mode, offset: 0x0 */
  __IO uint32_t CFG_TIMING;                        /**< Timing, offset: 0x4 */
  __IO uint32_t CFG_HTX_TO_COUNT;                  /**< High-Speed Transmit Timeout Count, offset: 0x8 */
  __IO uint32_t CFG_LRX_H_TO_COUNT;                /**< Low-Power Receive Timeout Count, offset: 0xC */
  __IO uint32_t CFG_BTA_H_TO_COUNT;                /**< Bus Turn-Around Timeout Count, offset: 0x10 */
  __IO uint32_t CFG_TWAKEUP;                       /**< Wakeup Timer, offset: 0x14 */
  __IO uint32_t CFG_HOST_WATCHDOG;                 /**< Host Watchdog, offset: 0x18 */
  __IO uint32_t SKEWCAL_CONTROL;                   /**< Skew Calibration, offset: 0x1C */
  __IO uint32_t CFG_SKEWCAL_TIME_I;                /**< Skew Calibration Time Initial, offset: 0x20 */
  __IO uint32_t CFG_SKEWCAL_TIME_P;                /**< Skew Calibration Time Periodic, offset: 0x24 */
  __IO uint32_t CFG_ALTCAL_TIME;                   /**< Alternate Calibration Time, offset: 0x28 */
  __IO uint32_t CLOCK_LANE;                        /**< Clock Lane, offset: 0x2C */
  __IO uint32_t LANE_0;                            /**< Lane 0, offset: 0x30 */
  __IO uint32_t LANE_1;                            /**< Lane 1, offset: 0x34 */
       uint8_t RESERVED_0[12];
  __IO uint32_t IRQ_STATUS;                        /**< Interrupt Request Status, offset: 0x44 */
  __IO uint32_t IRQ_MASK;                          /**< Interrupt Request Mask, offset: 0x48 */
       uint8_t RESERVED_1[4];
  __IO uint32_t PERIPH_IRQ_STATUS;                 /**< Peripheral Interrupt Request Status, offset: 0x50 */
  __IO uint32_t PERIPH_IRQ_MASK;                   /**< Peripheral Interrupt Request Mask, offset: 0x54 */
       uint8_t RESERVED_2[4];
  __I  uint32_t CFG_RX_ERROR_STATUS;               /**< Receive Error Status, offset: 0x5C */
  __IO uint32_t CFG_DBG_CTRL;                      /**< Debug Control, offset: 0x60 */
  __I  uint32_t CFG_DBG_DATA;                      /**< Debug Data, offset: 0x64 */
} DSI2_HOST_Type;

/* ----------------------------------------------------------------------------
   -- DSI2_HOST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_Register_Masks DSI2_HOST Register Masks
 * @{
 */

/*! @name CFG_MODE - Mode */
/*! @{ */

#define DSI2_HOST_CFG_MODE_CFG_NUM_LANES_MASK    (0xFU)
#define DSI2_HOST_CFG_MODE_CFG_NUM_LANES_SHIFT   (0U)
/*! cfg_num_lanes
 *  0b0000..No active lanes (reset default)
 *  0b0001..1 Active Lanes
 *  0b0010..2 Active Lanes
 */
#define DSI2_HOST_CFG_MODE_CFG_NUM_LANES(x)      (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_NUM_LANES_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_NUM_LANES_MASK)

#define DSI2_HOST_CFG_MODE_CFG_PPI_WIDTH_MASK    (0x60U)
#define DSI2_HOST_CFG_MODE_CFG_PPI_WIDTH_SHIFT   (5U)
/*! cfg_ppi_width
 *  0b00..PPI data width = 8 bits
 *  0b01..PPI data width = 16 bits
 *  0b10, 0b11..
 */
#define DSI2_HOST_CFG_MODE_CFG_PPI_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_PPI_WIDTH_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_PPI_WIDTH_MASK)

#define DSI2_HOST_CFG_MODE_CFG_CONTINUOUS_HS_CLK_MASK (0x100U)
#define DSI2_HOST_CFG_MODE_CFG_CONTINUOUS_HS_CLK_SHIFT (8U)
/*! cfg_continuous_hs_clk
 *  0b0..Non-Continuous high speed clock
 *  0b1..Continuous high speed clock
 */
#define DSI2_HOST_CFG_MODE_CFG_CONTINUOUS_HS_CLK(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_CONTINUOUS_HS_CLK_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_CONTINUOUS_HS_CLK_MASK)

#define DSI2_HOST_CFG_MODE_CFG_AUTOINSERT_EOTP_MASK (0x200U)
#define DSI2_HOST_CFG_MODE_CFG_AUTOINSERT_EOTP_SHIFT (9U)
/*! cfg_autoinsert_eotp
 *  0b0..EoTp is not automatically inserted
 *  0b1..EoTp is automatically inserted
 */
#define DSI2_HOST_CFG_MODE_CFG_AUTOINSERT_EOTP(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_AUTOINSERT_EOTP_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_AUTOINSERT_EOTP_MASK)

#define DSI2_HOST_CFG_MODE_CFG_DISABLE_BURST_MASK (0x800U)
#define DSI2_HOST_CFG_MODE_CFG_DISABLE_BURST_SHIFT (11U)
#define DSI2_HOST_CFG_MODE_CFG_DISABLE_BURST(x)  (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_DISABLE_BURST_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_DISABLE_BURST_MASK)

#define DSI2_HOST_CFG_MODE_CFG_DISABLE_RX_CRC_CHECK_MASK (0x1000U)
#define DSI2_HOST_CFG_MODE_CFG_DISABLE_RX_CRC_CHECK_SHIFT (12U)
/*! cfg_disable_rx_crc_check
 *  0b0..Packets are combined in a burst
 *  0b1..Each packet is sent separately with a return to LP mode in between each packet
 */
#define DSI2_HOST_CFG_MODE_CFG_DISABLE_RX_CRC_CHECK(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_DISABLE_RX_CRC_CHECK_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_DISABLE_RX_CRC_CHECK_MASK)

#define DSI2_HOST_CFG_MODE_CFG_SCRAMBLE_EN_MASK  (0x2000U)
#define DSI2_HOST_CFG_MODE_CFG_SCRAMBLE_EN_SHIFT (13U)
/*! cfg_scramble_en - Scrambling Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DSI2_HOST_CFG_MODE_CFG_SCRAMBLE_EN(x)    (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_SCRAMBLE_EN_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_SCRAMBLE_EN_MASK)

#define DSI2_HOST_CFG_MODE_CFG_ENABLE_MASK       (0x80000000U)
#define DSI2_HOST_CFG_MODE_CFG_ENABLE_SHIFT      (31U)
/*! cfg_enable - Main Enable for DSI-2 Host Controller
 *  0b0..DSI-2 Controller is disabled
 *  0b1..DSI-2 Controller is enabled
 */
#define DSI2_HOST_CFG_MODE_CFG_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_MODE_CFG_ENABLE_SHIFT)) & DSI2_HOST_CFG_MODE_CFG_ENABLE_MASK)
/*! @} */

/*! @name CFG_TIMING - Timing */
/*! @{ */

#define DSI2_HOST_CFG_TIMING_CFG_T_CLK_GAP_MASK  (0xFFU)
#define DSI2_HOST_CFG_TIMING_CFG_T_CLK_GAP_SHIFT (0U)
#define DSI2_HOST_CFG_TIMING_CFG_T_CLK_GAP(x)    (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_TIMING_CFG_T_CLK_GAP_SHIFT)) & DSI2_HOST_CFG_TIMING_CFG_T_CLK_GAP_MASK)

#define DSI2_HOST_CFG_TIMING_CFG_TX_GAP_MASK     (0xFF00U)
#define DSI2_HOST_CFG_TIMING_CFG_TX_GAP_SHIFT    (8U)
#define DSI2_HOST_CFG_TIMING_CFG_TX_GAP(x)       (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_TIMING_CFG_TX_GAP_SHIFT)) & DSI2_HOST_CFG_TIMING_CFG_TX_GAP_MASK)

#define DSI2_HOST_CFG_TIMING_CFG_T_POST_MASK     (0xFF0000U)
#define DSI2_HOST_CFG_TIMING_CFG_T_POST_SHIFT    (16U)
#define DSI2_HOST_CFG_TIMING_CFG_T_POST(x)       (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_TIMING_CFG_T_POST_SHIFT)) & DSI2_HOST_CFG_TIMING_CFG_T_POST_MASK)

#define DSI2_HOST_CFG_TIMING_CFG_T_PRE_MASK      (0xFF000000U)
#define DSI2_HOST_CFG_TIMING_CFG_T_PRE_SHIFT     (24U)
#define DSI2_HOST_CFG_TIMING_CFG_T_PRE(x)        (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_TIMING_CFG_T_PRE_SHIFT)) & DSI2_HOST_CFG_TIMING_CFG_T_PRE_MASK)
/*! @} */

/*! @name CFG_HTX_TO_COUNT - High-Speed Transmit Timeout Count */
/*! @{ */

#define DSI2_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_MASK (0xFFFFFFU)
#define DSI2_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_SHIFT (0U)
#define DSI2_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_SHIFT)) & DSI2_HOST_CFG_HTX_TO_COUNT_CFG_HTX_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_LRX_H_TO_COUNT - Low-Power Receive Timeout Count */
/*! @{ */

#define DSI2_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_MASK (0xFFFFFFU)
#define DSI2_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_SHIFT (0U)
#define DSI2_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_SHIFT)) & DSI2_HOST_CFG_LRX_H_TO_COUNT_CFG_LRX_H_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_BTA_H_TO_COUNT - Bus Turn-Around Timeout Count */
/*! @{ */

#define DSI2_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_MASK (0xFFFFFFU)
#define DSI2_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_SHIFT (0U)
#define DSI2_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_SHIFT)) & DSI2_HOST_CFG_BTA_H_TO_COUNT_CFG_BTA_H_TO_COUNT_MASK)
/*! @} */

/*! @name CFG_TWAKEUP - Wakeup Timer */
/*! @{ */

#define DSI2_HOST_CFG_TWAKEUP_CFG_TWAKEUP_MASK   (0x7FFFFU)
#define DSI2_HOST_CFG_TWAKEUP_CFG_TWAKEUP_SHIFT  (0U)
#define DSI2_HOST_CFG_TWAKEUP_CFG_TWAKEUP(x)     (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_TWAKEUP_CFG_TWAKEUP_SHIFT)) & DSI2_HOST_CFG_TWAKEUP_CFG_TWAKEUP_MASK)
/*! @} */

/*! @name CFG_HOST_WATCHDOG - Host Watchdog */
/*! @{ */

#define DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_COUNT_MASK (0x7FFFFFFFU)
#define DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_COUNT_SHIFT (0U)
#define DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_COUNT(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_COUNT_SHIFT)) & DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_COUNT_MASK)

#define DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_EN_MASK (0x80000000U)
#define DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_EN_SHIFT (31U)
#define DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_EN_SHIFT)) & DSI2_HOST_CFG_HOST_WATCHDOG_CFG_WATCHDOG_EN_MASK)
/*! @} */

/*! @name SKEWCAL_CONTROL - Skew Calibration */
/*! @{ */

#define DSI2_HOST_SKEWCAL_CONTROL_CFG_VID_SKEWCAL_LINE_MASK (0xFFU)
#define DSI2_HOST_SKEWCAL_CONTROL_CFG_VID_SKEWCAL_LINE_SHIFT (0U)
#define DSI2_HOST_SKEWCAL_CONTROL_CFG_VID_SKEWCAL_LINE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_SKEWCAL_CONTROL_CFG_VID_SKEWCAL_LINE_SHIFT)) & DSI2_HOST_SKEWCAL_CONTROL_CFG_VID_SKEWCAL_LINE_MASK)

#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_DONE_MASK (0x10000000U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_DONE_SHIFT (28U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_DONE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_DONE_SHIFT)) & DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_DONE_MASK)

#define DSI2_HOST_SKEWCAL_CONTROL_CSR_ALTCAL_MASK (0x20000000U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_ALTCAL_SHIFT (29U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_ALTCAL(x)  (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_SKEWCAL_CONTROL_CSR_ALTCAL_SHIFT)) & DSI2_HOST_SKEWCAL_CONTROL_CSR_ALTCAL_MASK)

#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_P_MASK (0x40000000U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_P_SHIFT (30U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_P(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_P_SHIFT)) & DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_P_MASK)

#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_I_MASK (0x80000000U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_I_SHIFT (31U)
#define DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_I(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_I_SHIFT)) & DSI2_HOST_SKEWCAL_CONTROL_CSR_SKEWCAL_I_MASK)
/*! @} */

/*! @name CFG_SKEWCAL_TIME_I - Skew Calibration Time Initial */
/*! @{ */

#define DSI2_HOST_CFG_SKEWCAL_TIME_I_CFG_SKEWCAL_TIME_I_MASK (0xFFFFU)
#define DSI2_HOST_CFG_SKEWCAL_TIME_I_CFG_SKEWCAL_TIME_I_SHIFT (0U)
#define DSI2_HOST_CFG_SKEWCAL_TIME_I_CFG_SKEWCAL_TIME_I(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_SKEWCAL_TIME_I_CFG_SKEWCAL_TIME_I_SHIFT)) & DSI2_HOST_CFG_SKEWCAL_TIME_I_CFG_SKEWCAL_TIME_I_MASK)
/*! @} */

/*! @name CFG_SKEWCAL_TIME_P - Skew Calibration Time Periodic */
/*! @{ */

#define DSI2_HOST_CFG_SKEWCAL_TIME_P_CFG_SKEWCAL_TIME_P_MASK (0xFFFFU)
#define DSI2_HOST_CFG_SKEWCAL_TIME_P_CFG_SKEWCAL_TIME_P_SHIFT (0U)
#define DSI2_HOST_CFG_SKEWCAL_TIME_P_CFG_SKEWCAL_TIME_P(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_SKEWCAL_TIME_P_CFG_SKEWCAL_TIME_P_SHIFT)) & DSI2_HOST_CFG_SKEWCAL_TIME_P_CFG_SKEWCAL_TIME_P_MASK)
/*! @} */

/*! @name CFG_ALTCAL_TIME - Alternate Calibration Time */
/*! @{ */

#define DSI2_HOST_CFG_ALTCAL_TIME_CFG_ALTCAL_TIME_MASK (0xFFFFU)
#define DSI2_HOST_CFG_ALTCAL_TIME_CFG_ALTCAL_TIME_SHIFT (0U)
#define DSI2_HOST_CFG_ALTCAL_TIME_CFG_ALTCAL_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_ALTCAL_TIME_CFG_ALTCAL_TIME_SHIFT)) & DSI2_HOST_CFG_ALTCAL_TIME_CFG_ALTCAL_TIME_MASK)
/*! @} */

/*! @name CLOCK_LANE - Clock Lane */
/*! @{ */

#define DSI2_HOST_CLOCK_LANE_ULPS_CLK_ACTIVE_MASK (0x1U)
#define DSI2_HOST_CLOCK_LANE_ULPS_CLK_ACTIVE_SHIFT (0U)
#define DSI2_HOST_CLOCK_LANE_ULPS_CLK_ACTIVE(x)  (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CLOCK_LANE_ULPS_CLK_ACTIVE_SHIFT)) & DSI2_HOST_CLOCK_LANE_ULPS_CLK_ACTIVE_MASK)

#define DSI2_HOST_CLOCK_LANE_STOPSTATE_STATUS_LNCLK_MASK (0x2U)
#define DSI2_HOST_CLOCK_LANE_STOPSTATE_STATUS_LNCLK_SHIFT (1U)
#define DSI2_HOST_CLOCK_LANE_STOPSTATE_STATUS_LNCLK(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CLOCK_LANE_STOPSTATE_STATUS_LNCLK_SHIFT)) & DSI2_HOST_CLOCK_LANE_STOPSTATE_STATUS_LNCLK_MASK)

#define DSI2_HOST_CLOCK_LANE_ULPS_CLK_ENABLE_MASK (0x40000000U)
#define DSI2_HOST_CLOCK_LANE_ULPS_CLK_ENABLE_SHIFT (30U)
#define DSI2_HOST_CLOCK_LANE_ULPS_CLK_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CLOCK_LANE_ULPS_CLK_ENABLE_SHIFT)) & DSI2_HOST_CLOCK_LANE_ULPS_CLK_ENABLE_MASK)

#define DSI2_HOST_CLOCK_LANE_CFG_CLK_LANE_EN_MASK (0x80000000U)
#define DSI2_HOST_CLOCK_LANE_CFG_CLK_LANE_EN_SHIFT (31U)
#define DSI2_HOST_CLOCK_LANE_CFG_CLK_LANE_EN(x)  (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CLOCK_LANE_CFG_CLK_LANE_EN_SHIFT)) & DSI2_HOST_CLOCK_LANE_CFG_CLK_LANE_EN_MASK)
/*! @} */

/*! @name LANE_0 - Lane 0 */
/*! @{ */

#define DSI2_HOST_LANE_0_ULPS_ACTIVE_LN0_MASK    (0x1U)
#define DSI2_HOST_LANE_0_ULPS_ACTIVE_LN0_SHIFT   (0U)
#define DSI2_HOST_LANE_0_ULPS_ACTIVE_LN0(x)      (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_0_ULPS_ACTIVE_LN0_SHIFT)) & DSI2_HOST_LANE_0_ULPS_ACTIVE_LN0_MASK)

#define DSI2_HOST_LANE_0_STOPSTATE_STATUS_LN0_MASK (0x2U)
#define DSI2_HOST_LANE_0_STOPSTATE_STATUS_LN0_SHIFT (1U)
#define DSI2_HOST_LANE_0_STOPSTATE_STATUS_LN0(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_0_STOPSTATE_STATUS_LN0_SHIFT)) & DSI2_HOST_LANE_0_STOPSTATE_STATUS_LN0_MASK)

#define DSI2_HOST_LANE_0_CFG_LANE0_SEL_MASK      (0x3000000U)
#define DSI2_HOST_LANE_0_CFG_LANE0_SEL_SHIFT     (24U)
/*! cfg_lane0_sel
 *  0b00..Data lane 0 on the Host Controller gets data lane 0 on the MIPI interface
 *  0b01..Data lane 0 on the Host Controller gets data lane 1 on the MIPI interface
 *  0b10..Data lane 0 on the Host Controller gets data lane 2 on the MIPI interface
 *  0b11..Data lane 0 on the Host Controller gets data lane 3 on the MIPI interface
 */
#define DSI2_HOST_LANE_0_CFG_LANE0_SEL(x)        (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_0_CFG_LANE0_SEL_SHIFT)) & DSI2_HOST_LANE_0_CFG_LANE0_SEL_MASK)

#define DSI2_HOST_LANE_0_ULPS_ENABLE_LN0_MASK    (0x40000000U)
#define DSI2_HOST_LANE_0_ULPS_ENABLE_LN0_SHIFT   (30U)
#define DSI2_HOST_LANE_0_ULPS_ENABLE_LN0(x)      (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_0_ULPS_ENABLE_LN0_SHIFT)) & DSI2_HOST_LANE_0_ULPS_ENABLE_LN0_MASK)

#define DSI2_HOST_LANE_0_CFG_DATA_LANE_EN_LN0_MASK (0x80000000U)
#define DSI2_HOST_LANE_0_CFG_DATA_LANE_EN_LN0_SHIFT (31U)
#define DSI2_HOST_LANE_0_CFG_DATA_LANE_EN_LN0(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_0_CFG_DATA_LANE_EN_LN0_SHIFT)) & DSI2_HOST_LANE_0_CFG_DATA_LANE_EN_LN0_MASK)
/*! @} */

/*! @name LANE_1 - Lane 1 */
/*! @{ */

#define DSI2_HOST_LANE_1_ULPS_ACTIVE_LN1_MASK    (0x1U)
#define DSI2_HOST_LANE_1_ULPS_ACTIVE_LN1_SHIFT   (0U)
#define DSI2_HOST_LANE_1_ULPS_ACTIVE_LN1(x)      (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_1_ULPS_ACTIVE_LN1_SHIFT)) & DSI2_HOST_LANE_1_ULPS_ACTIVE_LN1_MASK)

#define DSI2_HOST_LANE_1_STOPSTATE_STATUS_LN1_MASK (0x2U)
#define DSI2_HOST_LANE_1_STOPSTATE_STATUS_LN1_SHIFT (1U)
#define DSI2_HOST_LANE_1_STOPSTATE_STATUS_LN1(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_1_STOPSTATE_STATUS_LN1_SHIFT)) & DSI2_HOST_LANE_1_STOPSTATE_STATUS_LN1_MASK)

#define DSI2_HOST_LANE_1_CFG_LANE1_SEL_MASK      (0x3000000U)
#define DSI2_HOST_LANE_1_CFG_LANE1_SEL_SHIFT     (24U)
/*! cfg_lane1_sel
 *  0b00..Data lane 1 on the Host Controller gets data lane 0 on the MIPI interface
 *  0b01..Data lane 1 on the Host Controller gets data lane 1 on the MIPI interface
 *  0b10..Data lane 1 on the Host Controller gets data lane 2 on the MIPI interface
 *  0b11..Data lane 1 on the Host Controller gets data lane 3 on the MIPI interface
 */
#define DSI2_HOST_LANE_1_CFG_LANE1_SEL(x)        (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_1_CFG_LANE1_SEL_SHIFT)) & DSI2_HOST_LANE_1_CFG_LANE1_SEL_MASK)

#define DSI2_HOST_LANE_1_ULPS_ENABLE_LN1_MASK    (0x40000000U)
#define DSI2_HOST_LANE_1_ULPS_ENABLE_LN1_SHIFT   (30U)
#define DSI2_HOST_LANE_1_ULPS_ENABLE_LN1(x)      (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_1_ULPS_ENABLE_LN1_SHIFT)) & DSI2_HOST_LANE_1_ULPS_ENABLE_LN1_MASK)

#define DSI2_HOST_LANE_1_CFG_DATA_LANE_EN_LN1_MASK (0x80000000U)
#define DSI2_HOST_LANE_1_CFG_DATA_LANE_EN_LN1_SHIFT (31U)
#define DSI2_HOST_LANE_1_CFG_DATA_LANE_EN_LN1(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_LANE_1_CFG_DATA_LANE_EN_LN1_SHIFT)) & DSI2_HOST_LANE_1_CFG_DATA_LANE_EN_LN1_MASK)
/*! @} */

/*! @name IRQ_STATUS - Interrupt Request Status */
/*! @{ */

#define DSI2_HOST_IRQ_STATUS_CSR_PARITY_ERR_MASK (0x80000000U)
#define DSI2_HOST_IRQ_STATUS_CSR_PARITY_ERR_SHIFT (31U)
/*! csr_parity_err - CSR Parity Error within DSI2 HOST BASE Device */
#define DSI2_HOST_IRQ_STATUS_CSR_PARITY_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_IRQ_STATUS_CSR_PARITY_ERR_SHIFT)) & DSI2_HOST_IRQ_STATUS_CSR_PARITY_ERR_MASK)
/*! @} */

/*! @name IRQ_MASK - Interrupt Request Mask */
/*! @{ */

#define DSI2_HOST_IRQ_MASK_IRQ_MASK_CSR_PARITY_ERR_MASK (0x80000000U)
#define DSI2_HOST_IRQ_MASK_IRQ_MASK_CSR_PARITY_ERR_SHIFT (31U)
#define DSI2_HOST_IRQ_MASK_IRQ_MASK_CSR_PARITY_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_IRQ_MASK_IRQ_MASK_CSR_PARITY_ERR_SHIFT)) & DSI2_HOST_IRQ_MASK_IRQ_MASK_CSR_PARITY_ERR_MASK)
/*! @} */

/*! @name PERIPH_IRQ_STATUS - Peripheral Interrupt Request Status */
/*! @{ */

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_0_MASK (0x1U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_0_SHIFT (0U)
/*! irq_periph_bit_0 - SoT Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_0(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_0_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_0_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_1_MASK (0x2U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_1_SHIFT (1U)
/*! irq_periph_bit_1 - SotSync Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_1(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_1_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_1_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_2_MASK (0x4U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_2_SHIFT (2U)
/*! irq_periph_bit_2 - EoT Sync Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_2(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_2_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_2_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_3_MASK (0x8U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_3_SHIFT (3U)
/*! irq_periph_bit_3 - Esc Mode Entry Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_3(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_3_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_3_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_4_MASK (0x10U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_4_SHIFT (4U)
/*! irq_periph_bit_4 - LP Transmit Sync Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_4(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_4_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_4_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_5_MASK (0x20U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_5_SHIFT (5U)
/*! irq_periph_bit_5 - Periph Timeout Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_5(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_5_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_5_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_6_MASK (0x40U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_6_SHIFT (6U)
/*! irq_periph_bit_6 - False Control Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_6(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_6_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_6_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_7_MASK (0x80U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_7_SHIFT (7U)
/*! irq_periph_bit_7 - Contention Detected */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_7(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_7_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_7_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_8_MASK (0x100U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_8_SHIFT (8U)
/*! irq_periph_bit_8 - Single-Bit ECC Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_8(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_8_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_8_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_9_MASK (0x200U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_9_SHIFT (9U)
/*! irq_periph_bit_9 - Multi-Bit ECC Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_9(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_9_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_9_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_10_MASK (0x400U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_10_SHIFT (10U)
/*! irq_periph_bit_10 - CRC Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_10(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_10_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_10_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_11_MASK (0x800U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_11_SHIFT (11U)
/*! irq_periph_bit_11 - Data Type Not Recognized */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_11(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_11_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_11_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_12_MASK (0x1000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_12_SHIFT (12U)
/*! irq_periph_bit_12 - VC ID Invalid */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_12(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_12_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_12_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_13_MASK (0x2000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_13_SHIFT (13U)
/*! irq_periph_bit_13 - Invalid Transmission Length */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_13(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_13_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_13_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_15_MASK (0x8000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_15_SHIFT (15U)
/*! irq_periph_bit_15 - Protocol Violation */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_15(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_15_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_15_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_16_MASK (0x10000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_16_SHIFT (16U)
/*! irq_periph_bit_16 - Bit 0 of last received Trigger (Reset Trigger) */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_16(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_16_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_16_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_17_MASK (0x20000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_17_SHIFT (17U)
/*! irq_periph_bit_17 - Bit 1 of last received Trigger (TE Trigger) */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_17(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_17_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_17_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_18_MASK (0x40000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_18_SHIFT (18U)
/*! irq_periph_bit_18 - Bit 2 of last received Trigger (ACK Trigger) */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_18(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_18_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_18_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_19_MASK (0x80000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_19_SHIFT (19U)
/*! irq_periph_bit_19 - Bit 3 of last received Trigger (TE Fail Trigger) */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_19(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_19_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_19_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_20_MASK (0x100000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_20_SHIFT (20U)
/*! irq_periph_bit_20 - Host Read Single-Bit ECC Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_20(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_20_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_20_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_21_MASK (0x200000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_21_SHIFT (21U)
/*! irq_periph_bit_21 - Host Read, Multi-Bit ECC Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_21(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_21_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_21_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_22_MASK (0x400000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_22_SHIFT (22U)
/*! irq_periph_bit_22 - Host_Read, CRC Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_22(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_22_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_22_MASK)

#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_23_MASK (0x800000U)
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_23_SHIFT (23U)
/*! irq_periph_bit_23 - IRQ Register Parity Err */
#define DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_23(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_23_SHIFT)) & DSI2_HOST_PERIPH_IRQ_STATUS_IRQ_PERIPH_BIT_23_MASK)
/*! @} */

/*! @name PERIPH_IRQ_MASK - Peripheral Interrupt Request Mask */
/*! @{ */

#define DSI2_HOST_PERIPH_IRQ_MASK_IRQ_MASK_PERIPH_MASK (0xFFFFFFU)
#define DSI2_HOST_PERIPH_IRQ_MASK_IRQ_MASK_PERIPH_SHIFT (0U)
#define DSI2_HOST_PERIPH_IRQ_MASK_IRQ_MASK_PERIPH(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_PERIPH_IRQ_MASK_IRQ_MASK_PERIPH_SHIFT)) & DSI2_HOST_PERIPH_IRQ_MASK_IRQ_MASK_PERIPH_MASK)
/*! @} */

/*! @name CFG_RX_ERROR_STATUS - Receive Error Status */
/*! @{ */

#define DSI2_HOST_CFG_RX_ERROR_STATUS_CFG_RX_ERROR_STATUS_MASK (0x7FFU)
#define DSI2_HOST_CFG_RX_ERROR_STATUS_CFG_RX_ERROR_STATUS_SHIFT (0U)
/*! cfg_rx_error_status
 *  0b1xxxxxxxxxx..BTA timeout detected
 *  0bx1xxxxxxxxx..Reverse Low power data receive timeout detected
 *  0bxx1xxxxxxxx..High Speed forward TX timeout detected
 *  0bxxx1xxxxxxx..CRC error detected
 *  0bxxxx00000xx..Error bit position for single bit ECC error (min)
 *  0bxxxx11111xx..Error bit position for single bit ECC error (max)
 *  0bxxxxxxxxx1x..ECC multi bit error detected
 *  0bxxxxxxxxxx1..ECC single bit error detected
 */
#define DSI2_HOST_CFG_RX_ERROR_STATUS_CFG_RX_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_RX_ERROR_STATUS_CFG_RX_ERROR_STATUS_SHIFT)) & DSI2_HOST_CFG_RX_ERROR_STATUS_CFG_RX_ERROR_STATUS_MASK)
/*! @} */

/*! @name CFG_DBG_CTRL - Debug Control */
/*! @{ */

#define DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_SEL_MASK  (0x7U)
#define DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_SEL_SHIFT (0U)
/*! cfg_dbg_sel
 *  0b000..CMD buffer
 *  0b001..DATA buffer
 *  0b010, 0b011..
 *  0b100..VID_IF_L
 *  0b101..VID_IF_H
 *  0b110..VID_BUF_L
 *  0b111..VID_BUF_H
 */
#define DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_SEL(x)    (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_SEL_SHIFT)) & DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_SEL_MASK)

#define DSI2_HOST_CFG_DBG_CTRL_DEBUG_VALID_MASK  (0x10U)
#define DSI2_HOST_CFG_DBG_CTRL_DEBUG_VALID_SHIFT (4U)
#define DSI2_HOST_CFG_DBG_CTRL_DEBUG_VALID(x)    (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_DBG_CTRL_DEBUG_VALID_SHIFT)) & DSI2_HOST_CFG_DBG_CTRL_DEBUG_VALID_MASK)

#define DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_NEXT_MASK (0x100U)
#define DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_NEXT_SHIFT (8U)
#define DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_NEXT(x)   (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_NEXT_SHIFT)) & DSI2_HOST_CFG_DBG_CTRL_CFG_DBG_NEXT_MASK)
/*! @} */

/*! @name CFG_DBG_DATA - Debug Data */
/*! @{ */

#define DSI2_HOST_CFG_DBG_DATA_DEBUG_DATA_MASK   (0xFFFFFFFFU)
#define DSI2_HOST_CFG_DBG_DATA_DEBUG_DATA_SHIFT  (0U)
#define DSI2_HOST_CFG_DBG_DATA_DEBUG_DATA(x)     (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_CFG_DBG_DATA_DEBUG_DATA_SHIFT)) & DSI2_HOST_CFG_DBG_DATA_DEBUG_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI2_HOST_Register_Masks */


/*!
 * @}
 */ /* end of group DSI2_HOST_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI2_HOST_H_ */

