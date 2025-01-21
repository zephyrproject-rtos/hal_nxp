/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 7.0, 2018-11-05
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIPI_DSI_HOST
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**
** ###################################################################
*/

/*!
 * @file MIPI_DSI_HOST.h
 * @version 7.0
 * @date 2018-11-05
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI_HOST
 */

#if !defined(MIPI_DSI_HOST_H_)
#define MIPI_DSI_HOST_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- MIPI_DSI_HOST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_Peripheral_Access_Layer MIPI_DSI_HOST Peripheral Access Layer
 * @{
 */

/** MIPI_DSI_HOST - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_HOST_CFG_NUM_LANES;            /**< offset: 0x0 */
  __IO uint32_t DSI_HOST_CFG_NONCONTINUOUS_CLK;    /**< offset: 0x4 */
  __IO uint32_t DSI_HOST_CFG_T_PRE;                /**< offset: 0x8 */
  __IO uint32_t DSI_HOST_CFG_T_POST;               /**< offset: 0xC */
  __IO uint32_t DSI_HOST_CFG_TX_GAP;               /**< offset: 0x10 */
  __IO uint32_t DSI_HOST_CFG_AUTOINSERT_EOTP;      /**< offset: 0x14 */
  __IO uint32_t DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP; /**< offset: 0x18 */
  __IO uint32_t DSI_HOST_CFG_HTX_TO_COUNT;         /**< offset: 0x1C */
  __IO uint32_t DSI_HOST_CFG_LRX_H_TO_COUNT;       /**< offset: 0x20 */
  __IO uint32_t DSI_HOST_CFG_BTA_H_TO_COUNT;       /**< offset: 0x24 */
       uint8_t RESERVED_0[4];
  __I  uint32_t DSI_HOST_CFG_STATUS_OUT;           /**< offset: 0x2C */
  __I  uint32_t DSI_HOST_RX_ERROR_STATUS;          /**< offset: 0x30 */
} MIPI_DSI_HOST_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI_HOST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_Register_Masks MIPI_DSI_HOST Register Masks
 * @{
 */

/*! @name DSI_HOST_CFG_NUM_LANES -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_NUM_LANES_dsi_host_cfg_num_lanes_MASK (0x3U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_NUM_LANES_dsi_host_cfg_num_lanes_SHIFT (0U)
/*! dsi_host_cfg_num_lanes - Sets the number of active lanes that are to be used for transmitting
 *    data. 2'b00 - 1 Lane 2'b01 - 2 Lanes 2'b10 - Reserved 2'b11 - Reserved
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_NUM_LANES_dsi_host_cfg_num_lanes(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_NUM_LANES_dsi_host_cfg_num_lanes_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_NUM_LANES_dsi_host_cfg_num_lanes_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_NONCONTINUOUS_CLK -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_NONCONTINUOUS_CLK_dsi_host_cfg_noncontinuous_clk_MASK (0x1U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_NONCONTINUOUS_CLK_dsi_host_cfg_noncontinuous_clk_SHIFT (0U)
/*! dsi_host_cfg_noncontinuous_clk - Sets the Host Controller into non-continuous MIPI clock mode.
 *    When in non-continuous clock mode, the high speed clock will transistion into low power mode
 *    between transmissions. 1'b0 - Continuous high speed clock 1'b1 - Non-Continuous high speed clock
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_NONCONTINUOUS_CLK_dsi_host_cfg_noncontinuous_clk(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_NONCONTINUOUS_CLK_dsi_host_cfg_noncontinuous_clk_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_NONCONTINUOUS_CLK_dsi_host_cfg_noncontinuous_clk_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_T_PRE -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_T_PRE_dsi_host_cfg_t_pre_MASK (0x7FU)
#define MIPI_DSI_HOST_DSI_HOST_CFG_T_PRE_dsi_host_cfg_t_pre_SHIFT (0U)
/*! dsi_host_cfg_t_pre - Sets the number of byte clock periods ('clk_byte' input) that the
 *    controller will wait after enabling the clock lane for HS operation before enabling the data lanes for
 *    HS operation. This setting represents the TCLK-PRE parameter. The minimum value for this port
 *    is 1.
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_T_PRE_dsi_host_cfg_t_pre(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_T_PRE_dsi_host_cfg_t_pre_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_T_PRE_dsi_host_cfg_t_pre_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_T_POST -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_T_POST_dsi_host_cfg_t_post_MASK (0x7FU)
#define MIPI_DSI_HOST_DSI_HOST_CFG_T_POST_dsi_host_cfg_t_post_SHIFT (0U)
/*! dsi_host_cfg_t_post - Sets the number of byte clock periods ('clk_byte' input) to wait before
 *    putting the clock lane into LP mode after the data lanes have been detected to be in Stop State.
 *    This setting represents the DPHY timing parameters TLPX (TxClkEsc) + TCLK-PREPARE + TCLK-ZERO
 *    + TCLK-PRE requirement for the clock lane before the data lane is allowed to change from LP11
 *    to start a high speed transmission. The minimum value for this port is 1.
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_T_POST_dsi_host_cfg_t_post(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_T_POST_dsi_host_cfg_t_post_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_T_POST_dsi_host_cfg_t_post_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_TX_GAP -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_TX_GAP_dsi_host_cfg_tx_gap_MASK (0x7FU)
#define MIPI_DSI_HOST_DSI_HOST_CFG_TX_GAP_dsi_host_cfg_tx_gap_SHIFT (0U)
/*! dsi_host_cfg_tx_gap - Sets the number of byte clock periods ('clk_byte' input) that the
 *    controller will wait after the clock lane has been put into LP mode before enabling the clock lane for
 *    HS mode again. This setting represents the THS-EXIT parameter. The minimum value for this
 *    port is 1.
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_TX_GAP_dsi_host_cfg_tx_gap(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_TX_GAP_dsi_host_cfg_tx_gap_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_TX_GAP_dsi_host_cfg_tx_gap_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_AUTOINSERT_EOTP -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_AUTOINSERT_EOTP_dsi_host_cfg_autoinsert_eotp_MASK (0x1U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_AUTOINSERT_EOTP_dsi_host_cfg_autoinsert_eotp_SHIFT (0U)
/*! dsi_host_cfg_autoinsert_eotp - Enables the Host Controller to automatically insert an EoTp short
 *    packet when switching from HS to LP mode. 1'b0 - EoTp is not automatically inserted 1'b1 -
 *    EoTp is automatically inserted
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_AUTOINSERT_EOTP_dsi_host_cfg_autoinsert_eotp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_AUTOINSERT_EOTP_dsi_host_cfg_autoinsert_eotp_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_AUTOINSERT_EOTP_dsi_host_cfg_autoinsert_eotp_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_dsi_host_cfg_extra_cmds_after_eotp_MASK (0xFFU)
#define MIPI_DSI_HOST_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_dsi_host_cfg_extra_cmds_after_eotp_SHIFT (0U)
/*! dsi_host_cfg_extra_cmds_after_eotp - Configures the DSI Host Controller to send extra End Of
 *    Transmission Packets after the end of a packet. The value is the number of extra EOTP packets
 *    sent.
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_dsi_host_cfg_extra_cmds_after_eotp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_dsi_host_cfg_extra_cmds_after_eotp_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_dsi_host_cfg_extra_cmds_after_eotp_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_HTX_TO_COUNT -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_HTX_TO_COUNT_dsi_host_cfg_htx_to_count_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_DSI_HOST_CFG_HTX_TO_COUNT_dsi_host_cfg_htx_to_count_SHIFT (0U)
/*! dsi_host_cfg_htx_to_count - Sets the value of the DSI Host High Speed TX timeout count in
 *    clk_byte clock periods that once reached will initiate a timeout error and follow the recovery
 *    procedure documented in the DSI specification. This timeout parameter should be configured to
 *    represent the time taken to transmit the biggest HS data payload. If this timeout is reached the
 *    DSI byte count is cleared and the HS transmission is aborted. This timer can be also disabled,
 *    when set to 0.
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_HTX_TO_COUNT_dsi_host_cfg_htx_to_count(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_HTX_TO_COUNT_dsi_host_cfg_htx_to_count_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_HTX_TO_COUNT_dsi_host_cfg_htx_to_count_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_LRX_H_TO_COUNT -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_LRX_H_TO_COUNT_dsi_host_cfg_lrx_h_to_count_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_DSI_HOST_CFG_LRX_H_TO_COUNT_dsi_host_cfg_lrx_h_to_count_SHIFT (0U)
/*! dsi_host_cfg_lrx_h_to_count - Sets the value of the DSI Host low power RX timeout count in
 *    clk_byte clock periods that once reached will initiate a timeout error and follow the recovery
 *    procedure documented in the DSI specification. This timeout parameter should be configured to
 *    represent the time taken to receive the biggest LP (Escape mode) data payload. If this timeout is
 *    reached, the DSI byte count is cleared and the LP reception is aborted. This timer can be also
 *    disabled, when set to 0
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_LRX_H_TO_COUNT_dsi_host_cfg_lrx_h_to_count(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_LRX_H_TO_COUNT_dsi_host_cfg_lrx_h_to_count_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_LRX_H_TO_COUNT_dsi_host_cfg_lrx_h_to_count_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_BTA_H_TO_COUNT -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_BTA_H_TO_COUNT_dsi_host_cfg_bta_h_to_count_MASK (0xFFFFFFU)
#define MIPI_DSI_HOST_DSI_HOST_CFG_BTA_H_TO_COUNT_dsi_host_cfg_bta_h_to_count_SHIFT (0U)
/*! dsi_host_cfg_bta_h_to_count - Sets the value of the DSI Host Bus Turn Around (BTA) timeout in
 *    clk_byte clock periods that once reached will initiate a timeout error.
 */
#define MIPI_DSI_HOST_DSI_HOST_CFG_BTA_H_TO_COUNT_dsi_host_cfg_bta_h_to_count(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_BTA_H_TO_COUNT_dsi_host_cfg_bta_h_to_count_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_BTA_H_TO_COUNT_dsi_host_cfg_bta_h_to_count_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_STATUS_OUT -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_ERROR_MASK (0x1U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_ERROR_SHIFT (0U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_ERROR_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_SYNC_ERROR_MASK (0x2U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_SYNC_ERROR_SHIFT (1U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_SYNC_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_SYNC_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_SOT_SYNC_ERROR_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_EOT_SYNC_ERROR_MASK (0x4U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_EOT_SYNC_ERROR_SHIFT (2U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_EOT_SYNC_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_EOT_SYNC_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_EOT_SYNC_ERROR_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ESCAPE_MODE_ENTRY_CMD_ERROR_MASK (0x8U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ESCAPE_MODE_ENTRY_CMD_ERROR_SHIFT (3U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ESCAPE_MODE_ENTRY_CMD_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ESCAPE_MODE_ENTRY_CMD_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ESCAPE_MODE_ENTRY_CMD_ERROR_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_LP_TX_SYNC_ERROR_MASK (0x10U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_LP_TX_SYNC_ERROR_SHIFT (4U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_LP_TX_SYNC_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_LP_TX_SYNC_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_LP_TX_SYNC_ERROR_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_PERIPH_TIMEOUT_ERROR_MASK (0x20U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_PERIPH_TIMEOUT_ERROR_SHIFT (5U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_PERIPH_TIMEOUT_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_PERIPH_TIMEOUT_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_PERIPH_TIMEOUT_ERROR_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_FALSE_CONTROL_ERROR_MASK (0x40U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_FALSE_CONTROL_ERROR_SHIFT (6U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_FALSE_CONTROL_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_FALSE_CONTROL_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_FALSE_CONTROL_ERROR_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CONTENTION_DETECT_MASK (0x80U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CONTENTION_DETECT_SHIFT (7U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CONTENTION_DETECT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CONTENTION_DETECT_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CONTENTION_DETECT_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_SINGLE_BIT_MASK (0x100U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_SINGLE_BIT_SHIFT (8U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_SINGLE_BIT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_SINGLE_BIT_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_SINGLE_BIT_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_MULTI_BIT_MASK (0x200U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_MULTI_BIT_SHIFT (9U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_MULTI_BIT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_MULTI_BIT_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_ECC_ERROR_MULTI_BIT_MASK)

#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CHECKSUM_ERROR_MASK (0x400U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CHECKSUM_ERROR_SHIFT (10U)
#define MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CHECKSUM_ERROR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CHECKSUM_ERROR_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_CFG_STATUS_OUT_CHECKSUM_ERROR_MASK)
/*! @} */

/*! @name DSI_HOST_RX_ERROR_STATUS -  */
/*! @{ */

#define MIPI_DSI_HOST_DSI_HOST_RX_ERROR_STATUS_dsi_host_rx_error_status_MASK (0x7FFU)
#define MIPI_DSI_HOST_DSI_HOST_RX_ERROR_STATUS_dsi_host_rx_error_status_SHIFT (0U)
/*! dsi_host_rx_error_status - Status Register for Host receive error detection, ECC errors, CRC
 *    errors and for timeout indicators [0] ECC single bit error detected [1] ECC multi bit error
 *    detected [6:2] Errored bit position for single bit ECC error [7] CRC error detected [8] High Speed
 *    forward TX timeout detected [9] Reverse Low power data receive timeout detected [10] BTA
 *    timeout detected
 */
#define MIPI_DSI_HOST_DSI_HOST_RX_ERROR_STATUS_dsi_host_rx_error_status(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_DSI_HOST_RX_ERROR_STATUS_dsi_host_rx_error_status_SHIFT)) & MIPI_DSI_HOST_DSI_HOST_RX_ERROR_STATUS_dsi_host_rx_error_status_MASK)
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* MIPI_DSI_HOST_H_ */

