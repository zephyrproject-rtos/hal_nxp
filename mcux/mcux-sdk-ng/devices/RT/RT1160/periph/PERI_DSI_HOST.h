/*
** ###################################################################
**     Processors:          MIMXRT1165CVM5A_cm4
**                          MIMXRT1165CVM5A_cm7
**                          MIMXRT1165DVM6A_cm4
**                          MIMXRT1165DVM6A_cm7
**                          MIMXRT1165XVM5A_cm4
**                          MIMXRT1165XVM5A_cm7
**                          MIMXRT1166CVM5A_cm4
**                          MIMXRT1166CVM5A_cm7
**                          MIMXRT1166DVM6A_cm4
**                          MIMXRT1166DVM6A_cm7
**                          MIMXRT1166XVM5A_cm4
**                          MIMXRT1166XVM5A_cm7
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSI_HOST
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-29)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DSI_HOST.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DSI_HOST
 *
 * CMSIS Peripheral Access Layer for DSI_HOST
 */

#if !defined(PERI_DSI_HOST_H_)
#define PERI_DSI_HOST_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1165CVM5A_cm4) || defined(CPU_MIMXRT1165DVM6A_cm4) || defined(CPU_MIMXRT1165XVM5A_cm4))
#include "MIMXRT1165_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1165CVM5A_cm7) || defined(CPU_MIMXRT1165DVM6A_cm7) || defined(CPU_MIMXRT1165XVM5A_cm7))
#include "MIMXRT1165_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm4) || defined(CPU_MIMXRT1166DVM6A_cm4) || defined(CPU_MIMXRT1166XVM5A_cm4))
#include "MIMXRT1166_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm7) || defined(CPU_MIMXRT1166DVM6A_cm7) || defined(CPU_MIMXRT1166XVM5A_cm7))
#include "MIMXRT1166_cm7_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DSI_HOST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_Peripheral_Access_Layer DSI_HOST Peripheral Access Layer
 * @{
 */

/** DSI_HOST - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_NUM_LANES;                     /**< CFG_NUM_LANES, offset: 0x0 */
  __IO uint32_t CFG_NONCONTINUOUS_CLK;             /**< CFG_NONCONTINUOUS_CLK, offset: 0x4 */
  __IO uint32_t CFG_T_PRE;                         /**< CFG_T_PRE, offset: 0x8 */
  __IO uint32_t CFG_T_POST;                        /**< CFG_T_POST, offset: 0xC */
  __IO uint32_t CFG_TX_GAP;                        /**< CFG_TX_GAP, offset: 0x10 */
  __IO uint32_t CFG_AUTOINSERT_EOTP;               /**< CFG_AUTOINSERT_ETOP, offset: 0x14 */
  __IO uint32_t CFG_EXTRA_CMDS_AFTER_EOTP;         /**< CFG_EXTRA_CMDS_AFTER_ETOP, offset: 0x18 */
  __IO uint32_t CFG_HTX_TO_COUNT;                  /**< CFG_HTX_TO_COUNT, offset: 0x1C */
  __IO uint32_t CFG_LRX_H_TO_COUNT;                /**< CFG_LRX_H_TO_COUNT, offset: 0x20 */
  __IO uint32_t CFG_BTA_H_TO_COUNT;                /**< CFG_BTA_H_TO_COUNT, offset: 0x24 */
  __IO uint32_t CFG_TWAKEUP;                       /**< CFG_TWAKEUP, offset: 0x28 */
  __I  uint32_t CFG_STATUS_OUT;                    /**< CFG_STATUS_OUT, offset: 0x2C */
  __I  uint32_t RX_ERROR_STATUS;                   /**< RX_ERROR_STATUS, offset: 0x30 */
} DSI_HOST_Type;

/* ----------------------------------------------------------------------------
   -- DSI_HOST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_HOST_Register_Masks DSI_HOST Register Masks
 * @{
 */

/*! @name CFG_NUM_LANES - CFG_NUM_LANES */
/*! @{ */

#define DSI_HOST_CFG_NUM_LANES_NUM_LANES_MASK    (0x3U)
#define DSI_HOST_CFG_NUM_LANES_NUM_LANES_SHIFT   (0U)
/*! NUM_LANES - Sets the number of active lanes that are to be used for transmitting data.
 *  0b00..1 lane
 *  0b01..2 lanes
 */
#define DSI_HOST_CFG_NUM_LANES_NUM_LANES(x)      (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_NUM_LANES_NUM_LANES_SHIFT)) & DSI_HOST_CFG_NUM_LANES_NUM_LANES_MASK)
/*! @} */

/*! @name CFG_NONCONTINUOUS_CLK - CFG_NONCONTINUOUS_CLK */
/*! @{ */

#define DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_MASK (0x1U)
#define DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_SHIFT (0U)
/*! CLK_MODE - Sets the Host Controller into non-continuous MIPI clock mode. When in non-continuous
 *    clock mode, the high speed clock will transition into low power mode between transmissions.
 *  0b0..Continuous high speed clock
 *  0b1..Non-Continuous high speed clock
 */
#define DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_SHIFT)) & DSI_HOST_CFG_NONCONTINUOUS_CLK_CLK_MODE_MASK)
/*! @} */

/*! @name CFG_T_PRE - CFG_T_PRE */
/*! @{ */

#define DSI_HOST_CFG_T_PRE_NUM_PERIODS_MASK      (0xFFU)
#define DSI_HOST_CFG_T_PRE_NUM_PERIODS_SHIFT     (0U)
/*! NUM_PERIODS - Sets the number of byte clock periods ('clk_byte' input) that the controller will
 *    wait after enabling the clock lane for HS operation before enabling the data lanes for HS
 *    operation. This setting represents the TCLK-PRE DPHY timing parameter. The minimum value for this
 *    port is 1.
 */
#define DSI_HOST_CFG_T_PRE_NUM_PERIODS(x)        (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_T_PRE_NUM_PERIODS_SHIFT)) & DSI_HOST_CFG_T_PRE_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_T_POST - CFG_T_POST */
/*! @{ */

#define DSI_HOST_CFG_T_POST_NUM_PERIODS_MASK     (0xFFU)
#define DSI_HOST_CFG_T_POST_NUM_PERIODS_SHIFT    (0U)
/*! NUM_PERIODS - Sets the number of byte clock periods ('clk_byte' input) to wait before putting
 *    the clock lane into LP mode after the data lanes have been detected to be in Stop State. This
 *    setting represents the DPHY timing parameters TLPX + TCLK-PREPARE + TCLK-ZERO + TCLK-PRE
 *    requirement for the clock lane before the data lane is allowed to change from LP11 to start a high
 *    speed transmission. The minimum value for this port is 1.
 */
#define DSI_HOST_CFG_T_POST_NUM_PERIODS(x)       (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_T_POST_NUM_PERIODS_SHIFT)) & DSI_HOST_CFG_T_POST_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_TX_GAP - CFG_TX_GAP */
/*! @{ */

#define DSI_HOST_CFG_TX_GAP_NUM_PERIODS_MASK     (0xFFU)
#define DSI_HOST_CFG_TX_GAP_NUM_PERIODS_SHIFT    (0U)
/*! NUM_PERIODS - Sets the number of byte clock periods ('clk_byte' input) that the controller will
 *    wait after the clock lane has been put into LP mode before enabling the clock lane for HS mode
 *    again. This setting represents the THS-EXIT DPHY timing parameter. The minimum value for this
 *    port is 1.
 */
#define DSI_HOST_CFG_TX_GAP_NUM_PERIODS(x)       (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_TX_GAP_NUM_PERIODS_SHIFT)) & DSI_HOST_CFG_TX_GAP_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_AUTOINSERT_EOTP - CFG_AUTOINSERT_ETOP */
/*! @{ */

#define DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_MASK (0x1U)
#define DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_SHIFT (0U)
/*! AUTOINSERT - Enables the Host Controller to automatically insert an EoTp short packet when switching from HS to LP mode.
 *  0b0..EoTp is not automatically inserted
 *  0b1..EoTp is automatically inserted
 */
#define DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_SHIFT)) & DSI_HOST_CFG_AUTOINSERT_EOTP_AUTOINSERT_MASK)
/*! @} */

/*! @name CFG_EXTRA_CMDS_AFTER_EOTP - CFG_EXTRA_CMDS_AFTER_ETOP */
/*! @{ */

#define DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_MASK (0xFFU)
#define DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_SHIFT (0U)
/*! EXTRA_EOTP - Configures the DSI Host Controller to send extra End Of Transmission Packets after
 *    the end of a packet. The value is the number of extra EOTP packets sent.
 */
#define DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP(x) (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_SHIFT)) & DSI_HOST_CFG_EXTRA_CMDS_AFTER_EOTP_EXTRA_EOTP_MASK)
/*! @} */

/*! @name CFG_HTX_TO_COUNT - CFG_HTX_TO_COUNT */
/*! @{ */

#define DSI_HOST_CFG_HTX_TO_COUNT_COUNT_MASK     (0xFFFFFFU)
#define DSI_HOST_CFG_HTX_TO_COUNT_COUNT_SHIFT    (0U)
/*! COUNT - Sets the value of the DSI Host High Speed TX timeout count in clk_byte clock periods
 *    that once reached will initiate a timeout error and follow the recovery procedure documented in
 *    the DSI specification.
 */
#define DSI_HOST_CFG_HTX_TO_COUNT_COUNT(x)       (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_HTX_TO_COUNT_COUNT_SHIFT)) & DSI_HOST_CFG_HTX_TO_COUNT_COUNT_MASK)
/*! @} */

/*! @name CFG_LRX_H_TO_COUNT - CFG_LRX_H_TO_COUNT */
/*! @{ */

#define DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_MASK   (0xFFFFFFU)
#define DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_SHIFT  (0U)
/*! COUNT - Sets the value of the DSI Host low power RX timeout count in clk_byte clock periods that
 *    once reached will initiate a timeout error and follow the recovery procedure documented in
 *    the DSI specification.
 */
#define DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT(x)     (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_SHIFT)) & DSI_HOST_CFG_LRX_H_TO_COUNT_COUNT_MASK)
/*! @} */

/*! @name CFG_BTA_H_TO_COUNT - CFG_BTA_H_TO_COUNT */
/*! @{ */

#define DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_MASK   (0xFFFFFFU)
#define DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_SHIFT  (0U)
/*! COUNT - Sets the value of the DSI Host Bus Turn Around (BTA) timeout in clk_byte clock periods
 *    that once reached will initiate a timeout error.
 */
#define DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT(x)     (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_SHIFT)) & DSI_HOST_CFG_BTA_H_TO_COUNT_COUNT_MASK)
/*! @} */

/*! @name CFG_TWAKEUP - CFG_TWAKEUP */
/*! @{ */

#define DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_MASK    (0x7FFFFU)
#define DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_SHIFT   (0U)
/*! NUM_PERIODS - DPHY Twakeup timing parameter. Sets the number of clk_esc clock periods to keep a
 *    clock or data lane in Mark-1 state after exiting ULPS. The MIPI DPHY spec requires a minimum
 *    of 1ms in Mark-1 state after leaving ULPS.
 */
#define DSI_HOST_CFG_TWAKEUP_NUM_PERIODS(x)      (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_SHIFT)) & DSI_HOST_CFG_TWAKEUP_NUM_PERIODS_MASK)
/*! @} */

/*! @name CFG_STATUS_OUT - CFG_STATUS_OUT */
/*! @{ */

#define DSI_HOST_CFG_STATUS_OUT_STATUS_MASK      (0xFFFFFFFFU)
#define DSI_HOST_CFG_STATUS_OUT_STATUS_SHIFT     (0U)
/*! STATUS - Status Register */
#define DSI_HOST_CFG_STATUS_OUT_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << DSI_HOST_CFG_STATUS_OUT_STATUS_SHIFT)) & DSI_HOST_CFG_STATUS_OUT_STATUS_MASK)
/*! @} */

/*! @name RX_ERROR_STATUS - RX_ERROR_STATUS */
/*! @{ */

#define DSI_HOST_RX_ERROR_STATUS_STATUS_MASK     (0x7FFU)
#define DSI_HOST_RX_ERROR_STATUS_STATUS_SHIFT    (0U)
/*! STATUS - Status Register for Host receive error detection, ECC errors, CRC errors and for timeout indicators */
#define DSI_HOST_RX_ERROR_STATUS_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << DSI_HOST_RX_ERROR_STATUS_STATUS_SHIFT)) & DSI_HOST_RX_ERROR_STATUS_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI_HOST_Register_Masks */


/*!
 * @}
 */ /* end of group DSI_HOST_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_DSI_HOST_H_ */

