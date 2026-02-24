/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSI_V2_HOST_MAIN
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DSI_V2_HOST_MAIN.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DSI_V2_HOST_MAIN
 *
 * CMSIS Peripheral Access Layer for DSI_V2_HOST_MAIN
 */

#if !defined(PERI_DSI_V2_HOST_MAIN_H_)
#define PERI_DSI_V2_HOST_MAIN_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- DSI_V2_HOST_MAIN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_MAIN_Peripheral_Access_Layer DSI_V2_HOST_MAIN Peripheral Access Layer
 * @{
 */

/** DSI_V2_HOST_MAIN - Register Layout Typedef */
typedef struct {
  __I  uint32_t CORE_ID;                           /**< Core Identification, offset: 0x0 */
  __I  uint32_t VERSION;                           /**< Core Version, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PWR_UP;                            /**< Power Up, offset: 0xC */
  __IO uint32_t SOFT_RESET;                        /**< Soft Reset, offset: 0x10 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MODE_CTRL;                         /**< Mode Control, offset: 0x18 */
  __I  uint32_t MODE_STATUS;                       /**< Mode Status, offset: 0x1C */
  __I  uint32_t CORE_STATUS;                       /**< Core Status, offset: 0x20 */
  __IO uint32_t MANUAL_MODE_CFG;                   /**< Manual Mode Configuration, offset: 0x24 */
  __IO uint32_t OBS_FSM_SEL;                       /**< FSM Selection, offset: 0x28 */
  __I  uint32_t OBS_FSM_STATUS;                    /**< FSM Status, offset: 0x2C */
  __IO uint32_t OBS_FSM_CTRL;                      /**< FSMs Control Options, offset: 0x30 */
  __IO uint32_t OBS_FIFO_SEL;                      /**< FIFO Selection, offset: 0x34 */
  __I  uint32_t OBS_FIFO_STATUS;                   /**< FIFO Status, offset: 0x38 */
  __IO uint32_t OBS_FIFO_CTRL;                     /**< FIFOs Control Options, offset: 0x3C */
       uint8_t RESERVED_2[8];
  __IO uint32_t TO_HSTX_CFG;                       /**< High-speed TX Timeout, offset: 0x48 */
  __IO uint32_t TO_HSTXRDY_CFG;                    /**< High-speed TX RDY Timeout, offset: 0x4C */
  __IO uint32_t TO_LPRX_CFG;                       /**< Low-power RX Timeout, offset: 0x50 */
  __IO uint32_t TO_LPTXRDY_CFG;                    /**< Low-power TX DATA Timeout, offset: 0x54 */
  __IO uint32_t TO_LPTXTRIG_CFG;                   /**< Low-power TX TRIGGER Timeout, offset: 0x58 */
  __IO uint32_t TO_LPTXULPS_CFG;                   /**< Low-power TX ULPS Entry Timeout, offset: 0x5C */
  __IO uint32_t TO_BTA_CFG;                        /**< Bus Turnaround Direction Timeout, offset: 0x60 */
} DSI_V2_HOST_MAIN_Type;

/* ----------------------------------------------------------------------------
   -- DSI_V2_HOST_MAIN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_MAIN_Register_Masks DSI_V2_HOST_MAIN Register Masks
 * @{
 */

/*! @name CORE_ID - Core Identification */
/*! @{ */

#define DSI_V2_HOST_MAIN_CORE_ID_CORE_ID_MASK    (0xFFFFFFFFU)
#define DSI_V2_HOST_MAIN_CORE_ID_CORE_ID_SHIFT   (0U)
/*! CORE_ID
 *  0b00000000000000000000000000000000..
 */
#define DSI_V2_HOST_MAIN_CORE_ID_CORE_ID(x)      (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_ID_CORE_ID_SHIFT)) & DSI_V2_HOST_MAIN_CORE_ID_CORE_ID_MASK)
/*! @} */

/*! @name VERSION - Core Version */
/*! @{ */

#define DSI_V2_HOST_MAIN_VERSION_VER_NUMBER_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_VERSION_VER_NUMBER_SHIFT (0U)
/*! VER_NUMBER
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_VERSION_VER_NUMBER(x)   (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_VERSION_VER_NUMBER_SHIFT)) & DSI_V2_HOST_MAIN_VERSION_VER_NUMBER_MASK)

#define DSI_V2_HOST_MAIN_VERSION_TYPE_NUM_MASK   (0xFF0000U)
#define DSI_V2_HOST_MAIN_VERSION_TYPE_NUM_SHIFT  (16U)
/*! TYPE_NUM
 *  0b00000000..
 */
#define DSI_V2_HOST_MAIN_VERSION_TYPE_NUM(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_VERSION_TYPE_NUM_SHIFT)) & DSI_V2_HOST_MAIN_VERSION_TYPE_NUM_MASK)

#define DSI_V2_HOST_MAIN_VERSION_PKG_NUM_MASK    (0xF000000U)
#define DSI_V2_HOST_MAIN_VERSION_PKG_NUM_SHIFT   (24U)
/*! PKG_NUM
 *  0b0000..
 */
#define DSI_V2_HOST_MAIN_VERSION_PKG_NUM(x)      (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_VERSION_PKG_NUM_SHIFT)) & DSI_V2_HOST_MAIN_VERSION_PKG_NUM_MASK)

#define DSI_V2_HOST_MAIN_VERSION_TYPE_ENUM_MASK  (0xF0000000U)
#define DSI_V2_HOST_MAIN_VERSION_TYPE_ENUM_SHIFT (28U)
/*! TYPE_ENUM
 *  0b0000..GA release
 *  0b0001..LCA release
 *  0b0010..EA release
 *  0b0011..LP release
 *  0b0100..Reserved
 *  0b0101..SOW release
 *  0b0110..EC release
 */
#define DSI_V2_HOST_MAIN_VERSION_TYPE_ENUM(x)    (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_VERSION_TYPE_ENUM_SHIFT)) & DSI_V2_HOST_MAIN_VERSION_TYPE_ENUM_MASK)
/*! @} */

/*! @name PWR_UP - Power Up */
/*! @{ */

#define DSI_V2_HOST_MAIN_PWR_UP_PWR_UP_MASK      (0x1U)
#define DSI_V2_HOST_MAIN_PWR_UP_PWR_UP_SHIFT     (0U)
/*! PWR_UP
 *  0b0..Reset
 *  0b1..Power-up
 */
#define DSI_V2_HOST_MAIN_PWR_UP_PWR_UP(x)        (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_PWR_UP_PWR_UP_SHIFT)) & DSI_V2_HOST_MAIN_PWR_UP_PWR_UP_MASK)
/*! @} */

/*! @name SOFT_RESET - Soft Reset */
/*! @{ */

#define DSI_V2_HOST_MAIN_SOFT_RESET_IPI_RSTN_MASK (0x1U)
#define DSI_V2_HOST_MAIN_SOFT_RESET_IPI_RSTN_SHIFT (0U)
/*! IPI_RSTN
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_SOFT_RESET_IPI_RSTN(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_SOFT_RESET_IPI_RSTN_SHIFT)) & DSI_V2_HOST_MAIN_SOFT_RESET_IPI_RSTN_MASK)

#define DSI_V2_HOST_MAIN_SOFT_RESET_PHY_RSTN_MASK (0x2U)
#define DSI_V2_HOST_MAIN_SOFT_RESET_PHY_RSTN_SHIFT (1U)
/*! PHY_RSTN
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_SOFT_RESET_PHY_RSTN(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_SOFT_RESET_PHY_RSTN_SHIFT)) & DSI_V2_HOST_MAIN_SOFT_RESET_PHY_RSTN_MASK)

#define DSI_V2_HOST_MAIN_SOFT_RESET_SYS_RSTN_MASK (0x4U)
#define DSI_V2_HOST_MAIN_SOFT_RESET_SYS_RSTN_SHIFT (2U)
/*! SYS_RSTN
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_SOFT_RESET_SYS_RSTN(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_SOFT_RESET_SYS_RSTN_SHIFT)) & DSI_V2_HOST_MAIN_SOFT_RESET_SYS_RSTN_MASK)
/*! @} */

/*! @name MODE_CTRL - Mode Control */
/*! @{ */

#define DSI_V2_HOST_MAIN_MODE_CTRL_MODE_CTRL_MASK (0x7U)
#define DSI_V2_HOST_MAIN_MODE_CTRL_MODE_CTRL_SHIFT (0U)
/*! MODE_CTRL - Mode Control
 *  0b000..Idle mode
 *  0b001..AutoCalculation mode
 *  0b010..Command mode
 *  0b011..Video mode
 *  0b100-0b111..
 */
#define DSI_V2_HOST_MAIN_MODE_CTRL_MODE_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_MODE_CTRL_MODE_CTRL_SHIFT)) & DSI_V2_HOST_MAIN_MODE_CTRL_MODE_CTRL_MASK)
/*! @} */

/*! @name MODE_STATUS - Mode Status */
/*! @{ */

#define DSI_V2_HOST_MAIN_MODE_STATUS_MODE_STATUS_MASK (0x7U)
#define DSI_V2_HOST_MAIN_MODE_STATUS_MODE_STATUS_SHIFT (0U)
/*! MODE_STATUS - Mode Status
 *  0b000..Idle mode
 *  0b001..AutoCalculation mode
 *  0b010..Command mode
 *  0b011..Video mode
 *  0b100-0b111..
 */
#define DSI_V2_HOST_MAIN_MODE_STATUS_MODE_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_MODE_STATUS_MODE_STATUS_SHIFT)) & DSI_V2_HOST_MAIN_MODE_STATUS_MODE_STATUS_MASK)
/*! @} */

/*! @name CORE_STATUS - Core Status */
/*! @{ */

#define DSI_V2_HOST_MAIN_CORE_STATUS_CORE_BUSY_MASK (0x1U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_CORE_BUSY_SHIFT (0U)
/*! CORE_BUSY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_CORE_BUSY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_CORE_BUSY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_CORE_BUSY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_CORE_FIFOS_NOT_EMPTY_MASK (0x2U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_CORE_FIFOS_NOT_EMPTY_SHIFT (1U)
/*! CORE_FIFOS_NOT_EMPTY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_CORE_FIFOS_NOT_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_CORE_FIFOS_NOT_EMPTY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_CORE_FIFOS_NOT_EMPTY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_IPI_BUSY_MASK (0x100U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_IPI_BUSY_SHIFT (8U)
/*! IPI_BUSY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_IPI_BUSY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_IPI_BUSY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_IPI_BUSY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_IPI_FIFOS_NOT_EMPTY_MASK (0x200U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_IPI_FIFOS_NOT_EMPTY_SHIFT (9U)
/*! IPI_FIFOS_NOT_EMPTY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_IPI_FIFOS_NOT_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_IPI_FIFOS_NOT_EMPTY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_IPI_FIFOS_NOT_EMPTY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_BUSY_MASK (0x10000U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_BUSY_SHIFT (16U)
/*! CRI_BUSY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_BUSY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_CRI_BUSY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_CRI_BUSY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_WR_FIFOS_NOT_EMPTY_MASK (0x20000U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_WR_FIFOS_NOT_EMPTY_SHIFT (17U)
/*! CRI_WR_FIFOS_NOT_EMPTY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_WR_FIFOS_NOT_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_CRI_WR_FIFOS_NOT_EMPTY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_CRI_WR_FIFOS_NOT_EMPTY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_RD_DATA_AVAIL_MASK (0x40000U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_RD_DATA_AVAIL_SHIFT (18U)
/*! CRI_RD_DATA_AVAIL
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_CRI_RD_DATA_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_CRI_RD_DATA_AVAIL_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_CRI_RD_DATA_AVAIL_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_BUSY_MASK (0x1000000U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_BUSY_SHIFT (24U)
/*! PRI_BUSY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_BUSY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_PRI_BUSY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_PRI_BUSY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_TX_FIFOS_NOT_EMPTY_MASK (0x2000000U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_TX_FIFOS_NOT_EMPTY_SHIFT (25U)
/*! PRI_TX_FIFOS_NOT_EMPTY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_TX_FIFOS_NOT_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_PRI_TX_FIFOS_NOT_EMPTY_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_PRI_TX_FIFOS_NOT_EMPTY_MASK)

#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_RX_DATA_AVAIL_MASK (0x4000000U)
#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_RX_DATA_AVAIL_SHIFT (26U)
/*! PRI_RX_DATA_AVAIL
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_CORE_STATUS_PRI_RX_DATA_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_CORE_STATUS_PRI_RX_DATA_AVAIL_SHIFT)) & DSI_V2_HOST_MAIN_CORE_STATUS_PRI_RX_DATA_AVAIL_MASK)
/*! @} */

/*! @name MANUAL_MODE_CFG - Manual Mode Configuration */
/*! @{ */

#define DSI_V2_HOST_MAIN_MANUAL_MODE_CFG_MANUAL_MODE_EN_MASK (0x1U)
#define DSI_V2_HOST_MAIN_MANUAL_MODE_CFG_MANUAL_MODE_EN_SHIFT (0U)
/*! MANUAL_MODE_EN
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_MANUAL_MODE_CFG_MANUAL_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_MANUAL_MODE_CFG_MANUAL_MODE_EN_SHIFT)) & DSI_V2_HOST_MAIN_MANUAL_MODE_CFG_MANUAL_MODE_EN_MASK)
/*! @} */

/*! @name OBS_FSM_SEL - FSM Selection */
/*! @{ */

#define DSI_V2_HOST_MAIN_OBS_FSM_SEL_FSM_SELECTOR_MASK (0xFU)
#define DSI_V2_HOST_MAIN_OBS_FSM_SEL_FSM_SELECTOR_SHIFT (0U)
/*! FSM_SELECTOR - FSM Selector */
#define DSI_V2_HOST_MAIN_OBS_FSM_SEL_FSM_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FSM_SEL_FSM_SELECTOR_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FSM_SEL_FSM_SELECTOR_MASK)
/*! @} */

/*! @name OBS_FSM_STATUS - FSM Status */
/*! @{ */

#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_MASK (0x1FU)
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_SHIFT (0U)
/*! CURRENT_STATE
 *  0b00000..
 */
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_MASK)

#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_STUCK_MASK (0x20U)
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_STUCK_SHIFT (5U)
/*! STUCK
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_STUCK(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FSM_STATUS_STUCK_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FSM_STATUS_STUCK_MASK)

#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_PREVIOUS_STATE_MASK (0x1F00U)
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_PREVIOUS_STATE_SHIFT (8U)
/*! PREVIOUS_STATE
 *  0b00000..
 */
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_PREVIOUS_STATE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FSM_STATUS_PREVIOUS_STATE_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FSM_STATUS_PREVIOUS_STATE_MASK)

#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_CNT_MASK (0xFFFF0000U)
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_CNT_SHIFT (16U)
/*! CURRENT_STATE_CNT
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_CNT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_CNT_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FSM_STATUS_CURRENT_STATE_CNT_MASK)
/*! @} */

/*! @name OBS_FSM_CTRL - FSMs Control Options */
/*! @{ */

#define DSI_V2_HOST_MAIN_OBS_FSM_CTRL_FSM_MANUAL_INIT_MASK (0x1U)
#define DSI_V2_HOST_MAIN_OBS_FSM_CTRL_FSM_MANUAL_INIT_SHIFT (0U)
/*! FSM_MANUAL_INIT
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FSM_CTRL_FSM_MANUAL_INIT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FSM_CTRL_FSM_MANUAL_INIT_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FSM_CTRL_FSM_MANUAL_INIT_MASK)
/*! @} */

/*! @name OBS_FIFO_SEL - FIFO Selection */
/*! @{ */

#define DSI_V2_HOST_MAIN_OBS_FIFO_SEL_FIFO_SELECTOR_MASK (0xFU)
#define DSI_V2_HOST_MAIN_OBS_FIFO_SEL_FIFO_SELECTOR_SHIFT (0U)
/*! FIFO_SELECTOR
 *  0b0000..cmd_rd_pld_fifo
 *  0b0001..cmd_wr_hdr_fifo
 *  0b0010..cmd_wr_pld_fifo
 *  0b0011..ipi_pixel_fifo
 *  0b0100..ipi_event_fifo
 *  0b0101..phy_txhs_fifo
 *  0b0110..sys_ipi_cmd
 *  0b0111..sys_hs_hdr_buffer
 *  0b1000..sys_lp_header_buffer
 *  0b1001..sys_lpdt_byte_buf
 *  0b1010..sys_pri_req
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_SEL_FIFO_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_SEL_FIFO_SELECTOR_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_SEL_FIFO_SELECTOR_MASK)
/*! @} */

/*! @name OBS_FIFO_STATUS - FIFO Status */
/*! @{ */

#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_EMPTY_MASK (0x1U)
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_EMPTY_SHIFT (0U)
/*! EMPTY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_EMPTY_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_EMPTY_MASK)

#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_EMPTY_MASK (0x2U)
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_EMPTY_SHIFT (1U)
/*! ALMOST_EMPTY
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_EMPTY_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_EMPTY_MASK)

#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_HALF_FULL_MASK (0x4U)
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_HALF_FULL_SHIFT (2U)
/*! HALF_FULL
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_HALF_FULL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_HALF_FULL_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_HALF_FULL_MASK)

#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_FULL_MASK (0x8U)
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_FULL_SHIFT (3U)
/*! ALMOST_FULL
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_FULL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_FULL_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_FULL_MASK)

#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_FULL_MASK (0x10U)
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_FULL_SHIFT (4U)
/*! FULL
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_FULL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_FULL_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_FULL_MASK)

#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_CURRENT_WORD_COUNT_MASK (0xFFFF0000U)
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_CURRENT_WORD_COUNT_SHIFT (16U)
/*! CURRENT_WORD_COUNT
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_CURRENT_WORD_COUNT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_CURRENT_WORD_COUNT_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_CURRENT_WORD_COUNT_MASK)
/*! @} */

/*! @name OBS_FIFO_CTRL - FIFOs Control Options */
/*! @{ */

#define DSI_V2_HOST_MAIN_OBS_FIFO_CTRL_FIFO_MANUAL_INIT_MASK (0x1U)
#define DSI_V2_HOST_MAIN_OBS_FIFO_CTRL_FIFO_MANUAL_INIT_SHIFT (0U)
/*! FIFO_MANUAL_INIT
 *  0b0..
 */
#define DSI_V2_HOST_MAIN_OBS_FIFO_CTRL_FIFO_MANUAL_INIT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_OBS_FIFO_CTRL_FIFO_MANUAL_INIT_SHIFT)) & DSI_V2_HOST_MAIN_OBS_FIFO_CTRL_FIFO_MANUAL_INIT_MASK)
/*! @} */

/*! @name TO_HSTX_CFG - High-speed TX Timeout */
/*! @{ */

#define DSI_V2_HOST_MAIN_TO_HSTX_CFG_TO_HSTX_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_TO_HSTX_CFG_TO_HSTX_VALUE_SHIFT (0U)
/*! TO_HSTX_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_TO_HSTX_CFG_TO_HSTX_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_TO_HSTX_CFG_TO_HSTX_VALUE_SHIFT)) & DSI_V2_HOST_MAIN_TO_HSTX_CFG_TO_HSTX_VALUE_MASK)
/*! @} */

/*! @name TO_HSTXRDY_CFG - High-speed TX RDY Timeout */
/*! @{ */

#define DSI_V2_HOST_MAIN_TO_HSTXRDY_CFG_TO_HSTXRDY_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_TO_HSTXRDY_CFG_TO_HSTXRDY_VALUE_SHIFT (0U)
/*! TO_HSTXRDY_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_TO_HSTXRDY_CFG_TO_HSTXRDY_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_TO_HSTXRDY_CFG_TO_HSTXRDY_VALUE_SHIFT)) & DSI_V2_HOST_MAIN_TO_HSTXRDY_CFG_TO_HSTXRDY_VALUE_MASK)
/*! @} */

/*! @name TO_LPRX_CFG - Low-power RX Timeout */
/*! @{ */

#define DSI_V2_HOST_MAIN_TO_LPRX_CFG_TO_LPRX_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_TO_LPRX_CFG_TO_LPRX_VALUE_SHIFT (0U)
/*! TO_LPRX_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_TO_LPRX_CFG_TO_LPRX_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_TO_LPRX_CFG_TO_LPRX_VALUE_SHIFT)) & DSI_V2_HOST_MAIN_TO_LPRX_CFG_TO_LPRX_VALUE_MASK)
/*! @} */

/*! @name TO_LPTXRDY_CFG - Low-power TX DATA Timeout */
/*! @{ */

#define DSI_V2_HOST_MAIN_TO_LPTXRDY_CFG_TO_LPTXRDY_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_TO_LPTXRDY_CFG_TO_LPTXRDY_VALUE_SHIFT (0U)
/*! TO_LPTXRDY_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_TO_LPTXRDY_CFG_TO_LPTXRDY_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_TO_LPTXRDY_CFG_TO_LPTXRDY_VALUE_SHIFT)) & DSI_V2_HOST_MAIN_TO_LPTXRDY_CFG_TO_LPTXRDY_VALUE_MASK)
/*! @} */

/*! @name TO_LPTXTRIG_CFG - Low-power TX TRIGGER Timeout */
/*! @{ */

#define DSI_V2_HOST_MAIN_TO_LPTXTRIG_CFG_TO_LPTXTRIG_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_TO_LPTXTRIG_CFG_TO_LPTXTRIG_VALUE_SHIFT (0U)
/*! TO_LPTXTRIG_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_TO_LPTXTRIG_CFG_TO_LPTXTRIG_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_TO_LPTXTRIG_CFG_TO_LPTXTRIG_VALUE_SHIFT)) & DSI_V2_HOST_MAIN_TO_LPTXTRIG_CFG_TO_LPTXTRIG_VALUE_MASK)
/*! @} */

/*! @name TO_LPTXULPS_CFG - Low-power TX ULPS Entry Timeout */
/*! @{ */

#define DSI_V2_HOST_MAIN_TO_LPTXULPS_CFG_TO_LPTXULPS_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_TO_LPTXULPS_CFG_TO_LPTXULPS_VALUE_SHIFT (0U)
/*! TO_LPTXULPS_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_TO_LPTXULPS_CFG_TO_LPTXULPS_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_TO_LPTXULPS_CFG_TO_LPTXULPS_VALUE_SHIFT)) & DSI_V2_HOST_MAIN_TO_LPTXULPS_CFG_TO_LPTXULPS_VALUE_MASK)
/*! @} */

/*! @name TO_BTA_CFG - Bus Turnaround Direction Timeout */
/*! @{ */

#define DSI_V2_HOST_MAIN_TO_BTA_CFG_TO_BTA_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_MAIN_TO_BTA_CFG_TO_BTA_VALUE_SHIFT (0U)
/*! TO_BTA_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_MAIN_TO_BTA_CFG_TO_BTA_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_MAIN_TO_BTA_CFG_TO_BTA_VALUE_SHIFT)) & DSI_V2_HOST_MAIN_TO_BTA_CFG_TO_BTA_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_MAIN_Register_Masks */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_MAIN_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI_V2_HOST_MAIN_H_ */

