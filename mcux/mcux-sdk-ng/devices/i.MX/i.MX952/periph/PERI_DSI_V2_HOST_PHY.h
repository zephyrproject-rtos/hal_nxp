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
**         CMSIS Peripheral Access Layer for DSI_V2_HOST_PHY
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
 * @file PERI_DSI_V2_HOST_PHY.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DSI_V2_HOST_PHY
 *
 * CMSIS Peripheral Access Layer for DSI_V2_HOST_PHY
 */

#if !defined(PERI_DSI_V2_HOST_PHY_H_)
#define PERI_DSI_V2_HOST_PHY_H_                  /**< Symbol preventing repeated inclusion */

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
   -- DSI_V2_HOST_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_PHY_Peripheral_Access_Layer DSI_V2_HOST_PHY Peripheral Access Layer
 * @{
 */

/** DSI_V2_HOST_PHY - Register Layout Typedef */
typedef struct {
  __IO uint32_t PHY_MODE_CFG;                      /**< PHY Mode, offset: 0x0 */
  __IO uint32_t PHY_CLK_CFG;                       /**< PHY Clock Configuration, offset: 0x4 */
  __I  uint32_t PHY_STATUS;                        /**< PHY Status, offset: 0x8 */
  __IO uint32_t PHY_LP2HS_MAN_CFG;                 /**< PHY Time from Low-power to High-speed (Manual), offset: 0xC */
  __I  uint32_t PHY_LP2HS_AUTO;                    /**< PHY Time from Low-power to High-speed (Auto-mode), offset: 0x10 */
  __IO uint32_t PHY_HS2LP_MAN_CFG;                 /**< PHY Time from High-speed to Low-power (Manual), offset: 0x14 */
  __I  uint32_t PHY_HS2LP_AUTO;                    /**< PHY Time from High-speed to Low-power (Auto-mode), offset: 0x18 */
  __IO uint32_t PHY_MAX_RD_T_MAN_CFG;              /**< Maximum Read Time (Manual), offset: 0x1C */
  __I  uint32_t PHY_MAX_RD_T_AUTO;                 /**< Maximum Read Time (Auto-mode), offset: 0x20 */
  __IO uint32_t PHY_ESC_CMD_T_MAN_CFG;             /**< PHY Trigger Time (Manual), offset: 0x24 */
  __I  uint32_t PHY_ESC_CMD_T_AUTO;                /**< PHY Trigger Time (Auto-mode), offset: 0x28 */
  __IO uint32_t PHY_ESC_BYTE_T_MAN_CFG;            /**< Byte Time for Low-power TX (Manual), offset: 0x2C */
  __I  uint32_t PHY_ESC_BYTE_T_AUTO;               /**< Byte Time for Low-power TX (Auto-mode), offset: 0x30 */
  __IO uint32_t PHY_IPI_RATIO_MAN_CFG;             /**< Ratio of Frequencies phy_hstx_clk / ipi_clk (Manual), offset: 0x34 */
  __I  uint32_t PHY_IPI_RATIO_AUTO;                /**< Ratio of Frequencies phy_hstx_clk / ipi_clk (Auto-mode), offset: 0x38 */
  __IO uint32_t PHY_SYS_RATIO_MAN_CFG;             /**< Ratio of Frequencies phy_hstx_clk / sys_clk (Manual), offset: 0x3C */
  __I  uint32_t PHY_SYS_RATIO_AUTO;                /**< Ratio of Frequencies phy_hstx_clk / sys_clk (Auto-mode), offset: 0x40 */
  __IO uint32_t PHY_TOLERANCE_CFG;                 /**< Configuration of PHY Tolerance, offset: 0x44 */
  __IO uint32_t PHY_LANES_CFG;                     /**< Configuration of PHY Lanes, offset: 0x48 */
       uint8_t RESERVED_0[116];
  __IO uint32_t PRI_TX_CMD;                        /**< PRI TX Command Requests, offset: 0xC0 */
  __I  uint32_t PRI_RX_CMD;                        /**< PRI RX Notifications, offset: 0xC4 */
  __IO uint32_t PRI_CAL_CTRL;                      /**< PRI Calibration Time, offset: 0xC8 */
  __IO uint32_t PRI_ULPS_CTRL;                     /**< ULPS Requests Activation, offset: 0xCC */
} DSI_V2_HOST_PHY_Type;

/* ----------------------------------------------------------------------------
   -- DSI_V2_HOST_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_PHY_Register_Masks DSI_V2_HOST_PHY Register Masks
 * @{
 */

/*! @name PHY_MODE_CFG - PHY Mode */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_TYPE_MASK (0x1U)
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_TYPE_SHIFT (0U)
/*! PHY_TYPE - PHY Type
 *  0b0..D-PHY
 *  0b1..C-PHY (Not available on this chip.)
 */
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_TYPE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_TYPE_SHIFT)) & DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_TYPE_MASK)

#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_LANES_MASK (0x30U)
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_LANES_SHIFT (4U)
/*! PHY_LANES
 *  0b00..1 lane
 *  0b01..2 lanes
 *  0b10..3 lanes
 *  0b11..4 lanes
 */
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_LANES(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_LANES_SHIFT)) & DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_LANES_MASK)

#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PPI_WIDTH_MASK (0x300U)
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PPI_WIDTH_SHIFT (8U)
/*! PPI_WIDTH
 *  0b00..8 bits
 *  0b01..16 bits
 *  0b10..32 bits
 *  0b11..Reserved.
 */
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_PPI_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_MODE_CFG_PPI_WIDTH_SHIFT)) & DSI_V2_HOST_PHY_PHY_MODE_CFG_PPI_WIDTH_MASK)

#define DSI_V2_HOST_PHY_PHY_MODE_CFG_HS_TRANSFEREN_EN_MASK (0x1000U)
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_HS_TRANSFEREN_EN_SHIFT (12U)
/*! HS_TRANSFEREN_EN
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PHY_MODE_CFG_HS_TRANSFEREN_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_MODE_CFG_HS_TRANSFEREN_EN_SHIFT)) & DSI_V2_HOST_PHY_PHY_MODE_CFG_HS_TRANSFEREN_EN_MASK)
/*! @} */

/*! @name PHY_CLK_CFG - PHY Clock Configuration */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_CLK_CFG_CLK_TYPE_MASK (0x1U)
#define DSI_V2_HOST_PHY_PHY_CLK_CFG_CLK_TYPE_SHIFT (0U)
/*! CLK_TYPE
 *  0b0..Continuous clock
 *  0b1..Non-continuous clock
 */
#define DSI_V2_HOST_PHY_PHY_CLK_CFG_CLK_TYPE(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_CLK_CFG_CLK_TYPE_SHIFT)) & DSI_V2_HOST_PHY_PHY_CLK_CFG_CLK_TYPE_MASK)

#define DSI_V2_HOST_PHY_PHY_CLK_CFG_PHY_LPTX_CLK_DIV_MASK (0x3F00U)
#define DSI_V2_HOST_PHY_PHY_CLK_CFG_PHY_LPTX_CLK_DIV_SHIFT (8U)
/*! PHY_LPTX_CLK_DIV
 *  0b000000..
 */
#define DSI_V2_HOST_PHY_PHY_CLK_CFG_PHY_LPTX_CLK_DIV(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_CLK_CFG_PHY_LPTX_CLK_DIV_SHIFT)) & DSI_V2_HOST_PHY_PHY_CLK_CFG_PHY_LPTX_CLK_DIV_MASK)
/*! @} */

/*! @name PHY_STATUS - PHY Status */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_DIRECTION_MASK (0x1U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_DIRECTION_SHIFT (0U)
/*! PHY_DIRECTION
 *  0b0..Tx
 *  0b1..Rx
 */
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_DIRECTION(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_DIRECTION_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_DIRECTION_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_STOPSTATE_MASK (0x100U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_STOPSTATE_SHIFT (8U)
/*! PHY_CLK_STOPSTATE
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_STOPSTATE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_STOPSTATE_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_STOPSTATE_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_STOPSTATE_MASK (0x200U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_STOPSTATE_SHIFT (9U)
/*! PHY_L0_STOPSTATE
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_STOPSTATE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_STOPSTATE_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_STOPSTATE_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_STOPSTATE_MASK (0x400U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_STOPSTATE_SHIFT (10U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_STOPSTATE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_STOPSTATE_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_STOPSTATE_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_STOPSTATE_MASK (0x800U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_STOPSTATE_SHIFT (11U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_STOPSTATE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_STOPSTATE_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_STOPSTATE_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_STOPSTATE_MASK (0x1000U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_STOPSTATE_SHIFT (12U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_STOPSTATE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_STOPSTATE_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_STOPSTATE_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_ULPSACTIVENOT_MASK (0x10000U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_ULPSACTIVENOT_SHIFT (16U)
/*! PHY_CLK_ULPSACTIVENOT
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_ULPSACTIVENOT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_ULPSACTIVENOT_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_ULPSACTIVENOT_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_ULPSACTIVENOT_MASK (0x20000U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_ULPSACTIVENOT_SHIFT (17U)
/*! PHY_L0_ULPSACTIVENOT
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_ULPSACTIVENOT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_ULPSACTIVENOT_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L0_ULPSACTIVENOT_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_ULPSACTIVENOT_MASK (0x40000U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_ULPSACTIVENOT_SHIFT (18U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_ULPSACTIVENOT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_ULPSACTIVENOT_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L1_ULPSACTIVENOT_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_ULPSACTIVENOT_MASK (0x80000U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_ULPSACTIVENOT_SHIFT (19U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_ULPSACTIVENOT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_ULPSACTIVENOT_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L2_ULPSACTIVENOT_MASK)

#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_ULPSACTIVENOT_MASK (0x100000U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_ULPSACTIVENOT_SHIFT (20U)
#define DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_ULPSACTIVENOT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_ULPSACTIVENOT_SHIFT)) & DSI_V2_HOST_PHY_PHY_STATUS_PHY_L3_ULPSACTIVENOT_MASK)
/*! @} */

/*! @name PHY_LP2HS_MAN_CFG - PHY Time from Low-power to High-speed (Manual) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_LP2HS_MAN_CFG_PHY_LP2HS_TIME_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_LP2HS_MAN_CFG_PHY_LP2HS_TIME_SHIFT (0U)
/*! PHY_LP2HS_TIME
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_LP2HS_MAN_CFG_PHY_LP2HS_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_LP2HS_MAN_CFG_PHY_LP2HS_TIME_SHIFT)) & DSI_V2_HOST_PHY_PHY_LP2HS_MAN_CFG_PHY_LP2HS_TIME_MASK)
/*! @} */

/*! @name PHY_LP2HS_AUTO - PHY Time from Low-power to High-speed (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_LP2HS_AUTO_PHY_LP2HS_TIME_AUTO_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_LP2HS_AUTO_PHY_LP2HS_TIME_AUTO_SHIFT (0U)
/*! PHY_LP2HS_TIME_AUTO
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_LP2HS_AUTO_PHY_LP2HS_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_LP2HS_AUTO_PHY_LP2HS_TIME_AUTO_SHIFT)) & DSI_V2_HOST_PHY_PHY_LP2HS_AUTO_PHY_LP2HS_TIME_AUTO_MASK)
/*! @} */

/*! @name PHY_HS2LP_MAN_CFG - PHY Time from High-speed to Low-power (Manual) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_HS2LP_MAN_CFG_PHY_HS2LP_TIME_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_HS2LP_MAN_CFG_PHY_HS2LP_TIME_SHIFT (0U)
/*! PHY_HS2LP_TIME
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_HS2LP_MAN_CFG_PHY_HS2LP_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_HS2LP_MAN_CFG_PHY_HS2LP_TIME_SHIFT)) & DSI_V2_HOST_PHY_PHY_HS2LP_MAN_CFG_PHY_HS2LP_TIME_MASK)
/*! @} */

/*! @name PHY_HS2LP_AUTO - PHY Time from High-speed to Low-power (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_HS2LP_AUTO_PHY_HS2LP_TIME_AUTO_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_HS2LP_AUTO_PHY_HS2LP_TIME_AUTO_SHIFT (0U)
/*! PHY_HS2LP_TIME_AUTO
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_HS2LP_AUTO_PHY_HS2LP_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_HS2LP_AUTO_PHY_HS2LP_TIME_AUTO_SHIFT)) & DSI_V2_HOST_PHY_PHY_HS2LP_AUTO_PHY_HS2LP_TIME_AUTO_MASK)
/*! @} */

/*! @name PHY_MAX_RD_T_MAN_CFG - Maximum Read Time (Manual) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_MAX_RD_T_MAN_CFG_PHY_MAX_RD_TIME_MASK (0x7FFFFFFU)
#define DSI_V2_HOST_PHY_PHY_MAX_RD_T_MAN_CFG_PHY_MAX_RD_TIME_SHIFT (0U)
/*! PHY_MAX_RD_TIME
 *  0b000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_MAX_RD_T_MAN_CFG_PHY_MAX_RD_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_MAX_RD_T_MAN_CFG_PHY_MAX_RD_TIME_SHIFT)) & DSI_V2_HOST_PHY_PHY_MAX_RD_T_MAN_CFG_PHY_MAX_RD_TIME_MASK)
/*! @} */

/*! @name PHY_MAX_RD_T_AUTO - Maximum Read Time (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_MAX_RD_T_AUTO_PHY_MAX_RD_TIME_AUTO_MASK (0x7FFFFFFU)
#define DSI_V2_HOST_PHY_PHY_MAX_RD_T_AUTO_PHY_MAX_RD_TIME_AUTO_SHIFT (0U)
/*! PHY_MAX_RD_TIME_AUTO
 *  0b000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_MAX_RD_T_AUTO_PHY_MAX_RD_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_MAX_RD_T_AUTO_PHY_MAX_RD_TIME_AUTO_SHIFT)) & DSI_V2_HOST_PHY_PHY_MAX_RD_T_AUTO_PHY_MAX_RD_TIME_AUTO_MASK)
/*! @} */

/*! @name PHY_ESC_CMD_T_MAN_CFG - PHY Trigger Time (Manual) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_ESC_CMD_T_MAN_CFG_PHY_ESC_CMD_TIME_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_ESC_CMD_T_MAN_CFG_PHY_ESC_CMD_TIME_SHIFT (0U)
/*! PHY_ESC_CMD_TIME
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_ESC_CMD_T_MAN_CFG_PHY_ESC_CMD_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_ESC_CMD_T_MAN_CFG_PHY_ESC_CMD_TIME_SHIFT)) & DSI_V2_HOST_PHY_PHY_ESC_CMD_T_MAN_CFG_PHY_ESC_CMD_TIME_MASK)
/*! @} */

/*! @name PHY_ESC_CMD_T_AUTO - PHY Trigger Time (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_ESC_CMD_T_AUTO_PHY_ESC_CMD_TIME_AUTO_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_ESC_CMD_T_AUTO_PHY_ESC_CMD_TIME_AUTO_SHIFT (0U)
/*! PHY_ESC_CMD_TIME_AUTO
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_ESC_CMD_T_AUTO_PHY_ESC_CMD_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_ESC_CMD_T_AUTO_PHY_ESC_CMD_TIME_AUTO_SHIFT)) & DSI_V2_HOST_PHY_PHY_ESC_CMD_T_AUTO_PHY_ESC_CMD_TIME_AUTO_MASK)
/*! @} */

/*! @name PHY_ESC_BYTE_T_MAN_CFG - Byte Time for Low-power TX (Manual) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_MAN_CFG_PHY_ESC_BYTE_TIME_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_MAN_CFG_PHY_ESC_BYTE_TIME_SHIFT (0U)
/*! PHY_ESC_BYTE_TIME
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_MAN_CFG_PHY_ESC_BYTE_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_MAN_CFG_PHY_ESC_BYTE_TIME_SHIFT)) & DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_MAN_CFG_PHY_ESC_BYTE_TIME_MASK)
/*! @} */

/*! @name PHY_ESC_BYTE_T_AUTO - Byte Time for Low-power TX (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_AUTO_PHY_ESC_BYTE_TIME_AUTO_MASK (0x1FFFFFFFU)
#define DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_AUTO_PHY_ESC_BYTE_TIME_AUTO_SHIFT (0U)
/*! PHY_ESC_BYTE_TIME_AUTO
 *  0b00000000000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_AUTO_PHY_ESC_BYTE_TIME_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_AUTO_PHY_ESC_BYTE_TIME_AUTO_SHIFT)) & DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_AUTO_PHY_ESC_BYTE_TIME_AUTO_MASK)
/*! @} */

/*! @name PHY_IPI_RATIO_MAN_CFG - Ratio of Frequencies phy_hstx_clk / ipi_clk (Manual) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_IPI_RATIO_MAN_CFG_PHY_IPI_RATIO_MASK (0x7FFFFFU)
#define DSI_V2_HOST_PHY_PHY_IPI_RATIO_MAN_CFG_PHY_IPI_RATIO_SHIFT (0U)
/*! PHY_IPI_RATIO
 *  0b00000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_IPI_RATIO_MAN_CFG_PHY_IPI_RATIO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_IPI_RATIO_MAN_CFG_PHY_IPI_RATIO_SHIFT)) & DSI_V2_HOST_PHY_PHY_IPI_RATIO_MAN_CFG_PHY_IPI_RATIO_MASK)
/*! @} */

/*! @name PHY_IPI_RATIO_AUTO - Ratio of Frequencies phy_hstx_clk / ipi_clk (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_IPI_RATIO_AUTO_PHY_IPI_RATIO_AUTO_MASK (0x7FFFFFU)
#define DSI_V2_HOST_PHY_PHY_IPI_RATIO_AUTO_PHY_IPI_RATIO_AUTO_SHIFT (0U)
/*! PHY_IPI_RATIO_AUTO
 *  0b00000000000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_IPI_RATIO_AUTO_PHY_IPI_RATIO_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_IPI_RATIO_AUTO_PHY_IPI_RATIO_AUTO_SHIFT)) & DSI_V2_HOST_PHY_PHY_IPI_RATIO_AUTO_PHY_IPI_RATIO_AUTO_MASK)
/*! @} */

/*! @name PHY_SYS_RATIO_MAN_CFG - Ratio of Frequencies phy_hstx_clk / sys_clk (Manual) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_SYS_RATIO_MAN_CFG_PHY_SYS_RATIO_MASK (0x1FFFFU)
#define DSI_V2_HOST_PHY_PHY_SYS_RATIO_MAN_CFG_PHY_SYS_RATIO_SHIFT (0U)
/*! PHY_SYS_RATIO
 *  0b00000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_SYS_RATIO_MAN_CFG_PHY_SYS_RATIO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_SYS_RATIO_MAN_CFG_PHY_SYS_RATIO_SHIFT)) & DSI_V2_HOST_PHY_PHY_SYS_RATIO_MAN_CFG_PHY_SYS_RATIO_MASK)
/*! @} */

/*! @name PHY_SYS_RATIO_AUTO - Ratio of Frequencies phy_hstx_clk / sys_clk (Auto-mode) */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_SYS_RATIO_AUTO_PHY_SYS_RATIO_AUTO_MASK (0x1FFFFU)
#define DSI_V2_HOST_PHY_PHY_SYS_RATIO_AUTO_PHY_SYS_RATIO_AUTO_SHIFT (0U)
/*! PHY_SYS_RATIO_AUTO
 *  0b00000000000000000..
 */
#define DSI_V2_HOST_PHY_PHY_SYS_RATIO_AUTO_PHY_SYS_RATIO_AUTO(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_SYS_RATIO_AUTO_PHY_SYS_RATIO_AUTO_SHIFT)) & DSI_V2_HOST_PHY_PHY_SYS_RATIO_AUTO_PHY_SYS_RATIO_AUTO_MASK)
/*! @} */

/*! @name PHY_TOLERANCE_CFG - Configuration of PHY Tolerance */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_HS2LP_LP2HS_MARGIN_MASK (0x3FFU)
#define DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_HS2LP_LP2HS_MARGIN_SHIFT (0U)
/*! PHY_HS2LP_LP2HS_MARGIN
 *  0b0000000000..
 */
#define DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_HS2LP_LP2HS_MARGIN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_HS2LP_LP2HS_MARGIN_SHIFT)) & DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_HS2LP_LP2HS_MARGIN_MASK)

#define DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_STOPSTATE_DELAY_MASK (0xFFC00U)
#define DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_STOPSTATE_DELAY_SHIFT (10U)
/*! PHY_STOPSTATE_DELAY
 *  0b0000000000..
 */
#define DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_STOPSTATE_DELAY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_STOPSTATE_DELAY_SHIFT)) & DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_STOPSTATE_DELAY_MASK)
/*! @} */

/*! @name PHY_LANES_CFG - Configuration of PHY Lanes */
/*! @{ */

#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_1_MAPPING_MASK (0x30U)
#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_1_MAPPING_SHIFT (4U)
/*! LANE_1_MAPPING
 *  0b00..Reserved
 *  0b01..PHY Lane 1
 *  0b10..PHY Lane 2
 *  0b11..PHY Lane 3
 */
#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_1_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_1_MAPPING_SHIFT)) & DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_1_MAPPING_MASK)

#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_2_MAPPING_MASK (0x300U)
#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_2_MAPPING_SHIFT (8U)
/*! LANE_2_MAPPING
 *  0b00..Reserved
 *  0b01..PHY Lane 1
 *  0b10..PHY Lane 2
 *  0b11..PHY Lane 3
 */
#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_2_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_2_MAPPING_SHIFT)) & DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_2_MAPPING_MASK)

#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_3_MAPPING_MASK (0x3000U)
#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_3_MAPPING_SHIFT (12U)
/*! LANE_3_MAPPING
 *  0b00..Reserved
 *  0b01..PHY Lane 1
 *  0b10..PHY Lane 2
 *  0b11..PHY Lane 3
 */
#define DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_3_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_3_MAPPING_SHIFT)) & DSI_V2_HOST_PHY_PHY_LANES_CFG_LANE_3_MAPPING_MASK)
/*! @} */

/*! @name PRI_TX_CMD - PRI TX Command Requests */
/*! @{ */

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_0_MASK (0x1U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_0_SHIFT (0U)
/*! PHY_TX_TRIGGER_0
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_0(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_0_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_0_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_1_MASK (0x2U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_1_SHIFT (1U)
/*! PHY_TX_TRIGGER_1
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_1(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_1_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_1_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_2_MASK (0x4U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_2_SHIFT (2U)
/*! PHY_TX_TRIGGER_2
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_2(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_2_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_2_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_3_MASK (0x8U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_3_SHIFT (3U)
/*! PHY_TX_TRIGGER_3
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_3(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_3_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_TX_TRIGGER_3_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_DESKEWCAL_MASK (0x100U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_DESKEWCAL_SHIFT (8U)
/*! PHY_DESKEWCAL
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_DESKEWCAL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_DESKEWCAL_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_DESKEWCAL_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ALTERNATECAL_MASK (0x200U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ALTERNATECAL_SHIFT (9U)
/*! PHY_ALTERNATECAL
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ALTERNATECAL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ALTERNATECAL_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ALTERNATECAL_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_ENTRY_MASK (0x1000U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_ENTRY_SHIFT (12U)
/*! PHY_ULPS_ENTRY
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_ENTRY(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_ENTRY_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_ENTRY_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_EXIT_MASK (0x2000U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_EXIT_SHIFT (13U)
/*! PHY_ULPS_EXIT
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_EXIT(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_EXIT_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_ULPS_EXIT_MASK)

#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_BTA_MASK  (0x10000U)
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_BTA_SHIFT (16U)
/*! PHY_BTA
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_BTA(x)    (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_BTA_SHIFT)) & DSI_V2_HOST_PHY_PRI_TX_CMD_PHY_BTA_MASK)
/*! @} */

/*! @name PRI_RX_CMD - PRI RX Notifications */
/*! @{ */

#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_0_MASK (0x1U)
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_0_SHIFT (0U)
/*! PHY_RX_TRIGGER_0
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_0(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_0_SHIFT)) & DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_0_MASK)

#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_1_MASK (0x2U)
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_1_SHIFT (1U)
/*! PHY_RX_TRIGGER_1
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_1(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_1_SHIFT)) & DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_1_MASK)

#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_2_MASK (0x4U)
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_2_SHIFT (2U)
/*! PHY_RX_TRIGGER_2
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_2(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_2_SHIFT)) & DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_2_MASK)

#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_3_MASK (0x8U)
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_3_SHIFT (3U)
/*! PHY_RX_TRIGGER_3
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_3(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_3_SHIFT)) & DSI_V2_HOST_PHY_PRI_RX_CMD_PHY_RX_TRIGGER_3_MASK)
/*! @} */

/*! @name PRI_CAL_CTRL - PRI Calibration Time */
/*! @{ */

#define DSI_V2_HOST_PHY_PRI_CAL_CTRL_PHY_CAL_TIME_MASK (0x3FFFFU)
#define DSI_V2_HOST_PHY_PRI_CAL_CTRL_PHY_CAL_TIME_SHIFT (0U)
/*! PHY_CAL_TIME
 *  0b000000000000000000..
 */
#define DSI_V2_HOST_PHY_PRI_CAL_CTRL_PHY_CAL_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_CAL_CTRL_PHY_CAL_TIME_SHIFT)) & DSI_V2_HOST_PHY_PRI_CAL_CTRL_PHY_CAL_TIME_MASK)
/*! @} */

/*! @name PRI_ULPS_CTRL - ULPS Requests Activation */
/*! @{ */

#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_DATA_LANES_MASK (0x1U)
#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_DATA_LANES_SHIFT (0U)
/*! PHY_ULPS_DATA_LANES
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_DATA_LANES(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_DATA_LANES_SHIFT)) & DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_DATA_LANES_MASK)

#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_CLK_LANE_MASK (0x10U)
#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_CLK_LANE_SHIFT (4U)
/*! PHY_ULPS_CLK_LANE
 *  0b0..
 */
#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_CLK_LANE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_CLK_LANE_SHIFT)) & DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_ULPS_CLK_LANE_MASK)

#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_WAKEUP_TIME_MASK (0xFFFF0000U)
#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_WAKEUP_TIME_SHIFT (16U)
/*! PHY_WAKEUP_TIME - PHY Wakeup Time */
#define DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_WAKEUP_TIME(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_WAKEUP_TIME_SHIFT)) & DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_WAKEUP_TIME_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_PHY_Register_Masks */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_PHY_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI_V2_HOST_PHY_H_ */

