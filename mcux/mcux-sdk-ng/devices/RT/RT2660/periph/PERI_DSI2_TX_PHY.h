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
**         CMSIS Peripheral Access Layer for DSI2_TX_PHY
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
 * @file PERI_DSI2_TX_PHY.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DSI2_TX_PHY
 *
 * CMSIS Peripheral Access Layer for DSI2_TX_PHY
 */

#if !defined(PERI_DSI2_TX_PHY_H_)
#define PERI_DSI2_TX_PHY_H_                      /**< Symbol preventing repeated inclusion */

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
   -- DSI2_TX_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_TX_PHY_Peripheral_Access_Layer DSI2_TX_PHY Peripheral Access Layer
 * @{
 */

/** DSI2_TX_PHY - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_MIXEL_PLL;                     /**< PLL, offset: 0x0 */
  __IO uint32_t CFG_MIXEL_LANE_SEL;                /**< Lane Select, offset: 0x4 */
  __IO uint32_t CFG_MIXEL_ULPS_PLL_CTRL;           /**< ULPS PLL Control, offset: 0x8 */
  __IO uint32_t CFG_MIXEL_ULPS_PHY_CTRL;           /**< ULPS PHY Control, offset: 0xC */
  __IO uint32_t CFG_MIXEL_AUTO_PD_EN;              /**< Auto Power-Down Enable, offset: 0x10 */
  __IO uint32_t CFG_MIXEL_U_PRG_HS_ZERO;           /**< Data Lane High-Speed Zero Timer, offset: 0x14 */
  __IO uint32_t CFG_MIXEL_UC_PRG_HS_ZERO;          /**< Clock Lane High-Speed Zero Timer, offset: 0x18 */
  __IO uint32_t CFG_MIXEL_U_PRG_HS_TRAIL;          /**< Data Lane High-Speed Trail Timer, offset: 0x1C */
  __IO uint32_t CFG_MIXEL_UC_PRG_HS_TRAIL;         /**< Clock Lane High-Speed Trail Timer, offset: 0x20 */
  __IO uint32_t CFG_MIXEL_U_PRG_HS_PREPARE;        /**< Data Lane High-Speed Prepare Timer, offset: 0x24 */
  __IO uint32_t CFG_MIXEL_UC_PRG_HS_PREPARE;       /**< Clock Lane High-Speed Prepare Timer, offset: 0x28 */
  __IO uint32_t CFG_MIXEL_UC_PRG_RXHS_SETTLE;      /**< Clock Lane High-Speed Settle Timer, offset: 0x2C */
  __IO uint32_t CFG_MIXEL_U_PRG_RXHS_SETTLE;       /**< Data Lane High-Speed Settle Timer, offset: 0x30 */
  __IO uint32_t CFG_MIXEL_PD_PHY;                  /**< PHY Power-Down, offset: 0x34 */
  __IO uint32_t CFG_MIXEL_PNCH;                    /**< Polarity Change, offset: 0x38 */
  __IO uint32_t CFG_MIXEL_NUM_LANES;               /**< Number of Lanes, offset: 0x3C */
  __I  uint32_t MIXEL_PHY_INIT_DONE;               /**< PHY Initialization Done, offset: 0x40 */
} DSI2_TX_PHY_Type;

/* ----------------------------------------------------------------------------
   -- DSI2_TX_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_TX_PHY_Register_Masks DSI2_TX_PHY Register Masks
 * @{
 */

/*! @name CFG_MIXEL_PLL - PLL */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CO_MASK (0x7U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CO_SHIFT (0U)
/*! cfg_mixel_co - PHY PLL Control O Divider */
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CO(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CO_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CO_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CN_MASK (0x1F00U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CN_SHIFT (8U)
/*! cfg_mixel_cn - PHY PLL Control N Divider */
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CN(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CN_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CN_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CM_MASK (0xFF0000U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CM_SHIFT (16U)
/*! cfg_mixel_cm - PHY PLL Control M Divider */
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CM(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CM_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_CM_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_BYPASS_PLL_MASK (0x1000000U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_BYPASS_PLL_SHIFT (24U)
/*! cfg_mixel_bypass_pll - PHY Bypass PLL */
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_BYPASS_PLL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_BYPASS_PLL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_BYPASS_PLL_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_LATCH_MASK (0x2000000U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_LATCH_SHIFT (25U)
/*! cfg_mixel_lock_latch - PHY Lock Latch */
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_LATCH(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_LATCH_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_LATCH_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_BYP_MASK (0x4000000U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_BYP_SHIFT (26U)
/*! cfg_mixel_lock_byp - Lock Bypass */
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_BYP(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_BYP_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_LOCK_BYP_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_PD_PLL_MASK (0x8000000U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_PD_PLL_SHIFT (27U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_PD_PLL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_PD_PLL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_CFG_MIXEL_PD_PLL_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_PLL_MIXEL_LOCK_MASK (0x80000000U)
#define DSI2_TX_PHY_CFG_MIXEL_PLL_MIXEL_LOCK_SHIFT (31U)
/*! mixel_lock - PHY PLL Lock Signal (read only) */
#define DSI2_TX_PHY_CFG_MIXEL_PLL_MIXEL_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PLL_MIXEL_LOCK_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PLL_MIXEL_LOCK_MASK)
/*! @} */

/*! @name CFG_MIXEL_LANE_SEL - Lane Select */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE0_SEL_MASK (0x1U)
#define DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE0_SEL_SHIFT (0U)
/*! cfg_mixel_lane0_sel - PHY LANE0_SEL Setting */
#define DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE0_SEL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE0_SEL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE0_SEL_MASK)

#define DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE1_SEL_MASK (0x2U)
#define DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE1_SEL_SHIFT (1U)
/*! cfg_mixel_lane1_sel - PHY LANE1_SEL Setting */
#define DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE1_SEL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE1_SEL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_LANE_SEL_CFG_MIXEL_LANE1_SEL_MASK)
/*! @} */

/*! @name CFG_MIXEL_ULPS_PLL_CTRL - ULPS PLL Control */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_ULPS_PLL_CTRL_CFG_MIXEL_ULPS_PLL_CTRL_MASK (0x1U)
#define DSI2_TX_PHY_CFG_MIXEL_ULPS_PLL_CTRL_CFG_MIXEL_ULPS_PLL_CTRL_SHIFT (0U)
/*! cfg_mixel_ulps_pll_ctrl
 *  0b0..Select Auto shutdown PLL disable
 *  0b1..Select Auto shutdown PLL enable (default)
 */
#define DSI2_TX_PHY_CFG_MIXEL_ULPS_PLL_CTRL_CFG_MIXEL_ULPS_PLL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_ULPS_PLL_CTRL_CFG_MIXEL_ULPS_PLL_CTRL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_ULPS_PLL_CTRL_CFG_MIXEL_ULPS_PLL_CTRL_MASK)
/*! @} */

/*! @name CFG_MIXEL_ULPS_PHY_CTRL - ULPS PHY Control */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_ULPS_PHY_CTRL_CFG_MIXEL_ULPS_PHY_CTRL_MASK (0x1U)
#define DSI2_TX_PHY_CFG_MIXEL_ULPS_PHY_CTRL_CFG_MIXEL_ULPS_PHY_CTRL_SHIFT (0U)
/*! cfg_mixel_ulps_phy_ctrl - Select Auto Shutdown PHY when in ULPS
 *  0b0..Select Auto shutdown PHY disable
 *  0b1..Select Auto shutdown PHY enable (default)
 */
#define DSI2_TX_PHY_CFG_MIXEL_ULPS_PHY_CTRL_CFG_MIXEL_ULPS_PHY_CTRL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_ULPS_PHY_CTRL_CFG_MIXEL_ULPS_PHY_CTRL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_ULPS_PHY_CTRL_CFG_MIXEL_ULPS_PHY_CTRL_MASK)
/*! @} */

/*! @name CFG_MIXEL_AUTO_PD_EN - Auto Power-Down Enable */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_AUTO_PD_EN_CFG_MIXEL_AUTO_PD_EN_MASK (0x1U)
#define DSI2_TX_PHY_CFG_MIXEL_AUTO_PD_EN_CFG_MIXEL_AUTO_PD_EN_SHIFT (0U)
/*! cfg_mixel_auto_pd_en - Automatic Powerdown Unused Lane
 *  0b0..Select Auto Powerdown disable
 *  0b1..Select Auto Powerdown enable (default)
 */
#define DSI2_TX_PHY_CFG_MIXEL_AUTO_PD_EN_CFG_MIXEL_AUTO_PD_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_AUTO_PD_EN_CFG_MIXEL_AUTO_PD_EN_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_AUTO_PD_EN_CFG_MIXEL_AUTO_PD_EN_MASK)
/*! @} */

/*! @name CFG_MIXEL_U_PRG_HS_ZERO - Data Lane High-Speed Zero Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_ZERO_CFG_MIXEL_U_PRG_HS_ZERO_MASK (0xFFU)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_ZERO_CFG_MIXEL_U_PRG_HS_ZERO_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_ZERO_CFG_MIXEL_U_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_ZERO_CFG_MIXEL_U_PRG_HS_ZERO_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_ZERO_CFG_MIXEL_U_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name CFG_MIXEL_UC_PRG_HS_ZERO - Clock Lane High-Speed Zero Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_ZERO_CFG_MIXEL_UC_PRG_HS_ZERO_MASK (0x7FU)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_ZERO_CFG_MIXEL_UC_PRG_HS_ZERO_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_ZERO_CFG_MIXEL_UC_PRG_HS_ZERO(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_ZERO_CFG_MIXEL_UC_PRG_HS_ZERO_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_ZERO_CFG_MIXEL_UC_PRG_HS_ZERO_MASK)
/*! @} */

/*! @name CFG_MIXEL_U_PRG_HS_TRAIL - Data Lane High-Speed Trail Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_TRAIL_CFG_MIXEL_U_PRG_HS_TRAIL_MASK (0x3FU)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_TRAIL_CFG_MIXEL_U_PRG_HS_TRAIL_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_TRAIL_CFG_MIXEL_U_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_TRAIL_CFG_MIXEL_U_PRG_HS_TRAIL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_TRAIL_CFG_MIXEL_U_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name CFG_MIXEL_UC_PRG_HS_TRAIL - Clock Lane High-Speed Trail Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_TRAIL_CFG_MIXEL_UC_PRG_HS_TRAIL_MASK (0x1FU)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_TRAIL_CFG_MIXEL_UC_PRG_HS_TRAIL_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_TRAIL_CFG_MIXEL_UC_PRG_HS_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_TRAIL_CFG_MIXEL_UC_PRG_HS_TRAIL_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_TRAIL_CFG_MIXEL_UC_PRG_HS_TRAIL_MASK)
/*! @} */

/*! @name CFG_MIXEL_U_PRG_HS_PREPARE - Data Lane High-Speed Prepare Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_PREPARE_CFG_MIXEL_U_PRG_HS_PREPARE_MASK (0x3U)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_PREPARE_CFG_MIXEL_U_PRG_HS_PREPARE_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_PREPARE_CFG_MIXEL_U_PRG_HS_PREPARE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_PREPARE_CFG_MIXEL_U_PRG_HS_PREPARE_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_U_PRG_HS_PREPARE_CFG_MIXEL_U_PRG_HS_PREPARE_MASK)
/*! @} */

/*! @name CFG_MIXEL_UC_PRG_HS_PREPARE - Clock Lane High-Speed Prepare Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_PREPARE_CFG_MIXEL_UC_PRG_HS_PREPARE_MASK (0x3U)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_PREPARE_CFG_MIXEL_UC_PRG_HS_PREPARE_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_PREPARE_CFG_MIXEL_UC_PRG_HS_PREPARE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_PREPARE_CFG_MIXEL_UC_PRG_HS_PREPARE_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_UC_PRG_HS_PREPARE_CFG_MIXEL_UC_PRG_HS_PREPARE_MASK)
/*! @} */

/*! @name CFG_MIXEL_UC_PRG_RXHS_SETTLE - Clock Lane High-Speed Settle Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_RXHS_SETTLE_CFG_MIXEL_UC_PRG_RXHS_SETTLE_MASK (0x7FU)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_RXHS_SETTLE_CFG_MIXEL_UC_PRG_RXHS_SETTLE_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_UC_PRG_RXHS_SETTLE_CFG_MIXEL_UC_PRG_RXHS_SETTLE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_UC_PRG_RXHS_SETTLE_CFG_MIXEL_UC_PRG_RXHS_SETTLE_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_UC_PRG_RXHS_SETTLE_CFG_MIXEL_UC_PRG_RXHS_SETTLE_MASK)
/*! @} */

/*! @name CFG_MIXEL_U_PRG_RXHS_SETTLE - Data Lane High-Speed Settle Timer */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_RXHS_SETTLE_CFG_MIXEL_U_PRG_RXHS_SETTLE_MASK (0x3FU)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_RXHS_SETTLE_CFG_MIXEL_U_PRG_RXHS_SETTLE_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_U_PRG_RXHS_SETTLE_CFG_MIXEL_U_PRG_RXHS_SETTLE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_U_PRG_RXHS_SETTLE_CFG_MIXEL_U_PRG_RXHS_SETTLE_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_U_PRG_RXHS_SETTLE_CFG_MIXEL_U_PRG_RXHS_SETTLE_MASK)
/*! @} */

/*! @name CFG_MIXEL_PD_PHY - PHY Power-Down */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_PD_PHY_CFG_MIXEL_PD_PHY_MASK (0x1U)
#define DSI2_TX_PHY_CFG_MIXEL_PD_PHY_CFG_MIXEL_PD_PHY_SHIFT (0U)
#define DSI2_TX_PHY_CFG_MIXEL_PD_PHY_CFG_MIXEL_PD_PHY(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PD_PHY_CFG_MIXEL_PD_PHY_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PD_PHY_CFG_MIXEL_PD_PHY_MASK)
/*! @} */

/*! @name CFG_MIXEL_PNCH - Polarity Change */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_PNCH_CFG_MIXEL_PNCH_MASK (0x7U)
#define DSI2_TX_PHY_CFG_MIXEL_PNCH_CFG_MIXEL_PNCH_SHIFT (0U)
/*! cfg_mixel_pnch
 *  0b1xx..PHY D1_PNCH setting
 *  0bx1x..PHY D0_PNCH setting
 *  0bxx1..PHY CLK_PNCH setting
 */
#define DSI2_TX_PHY_CFG_MIXEL_PNCH_CFG_MIXEL_PNCH(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_PNCH_CFG_MIXEL_PNCH_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_PNCH_CFG_MIXEL_PNCH_MASK)
/*! @} */

/*! @name CFG_MIXEL_NUM_LANES - Number of Lanes */
/*! @{ */

#define DSI2_TX_PHY_CFG_MIXEL_NUM_LANES_CFG_MIXEL_NUM_LANES_MASK (0x1U)
#define DSI2_TX_PHY_CFG_MIXEL_NUM_LANES_CFG_MIXEL_NUM_LANES_SHIFT (0U)
/*! cfg_mixel_num_lanes
 *  0b0..1 lane
 *  0b1..2 lanes
 */
#define DSI2_TX_PHY_CFG_MIXEL_NUM_LANES_CFG_MIXEL_NUM_LANES(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_CFG_MIXEL_NUM_LANES_CFG_MIXEL_NUM_LANES_SHIFT)) & DSI2_TX_PHY_CFG_MIXEL_NUM_LANES_CFG_MIXEL_NUM_LANES_MASK)
/*! @} */

/*! @name MIXEL_PHY_INIT_DONE - PHY Initialization Done */
/*! @{ */

#define DSI2_TX_PHY_MIXEL_PHY_INIT_DONE_MIXEL_PHY_INIT_DONE_MASK (0x1U)
#define DSI2_TX_PHY_MIXEL_PHY_INIT_DONE_MIXEL_PHY_INIT_DONE_SHIFT (0U)
/*! mixel_phy_init_done - PHY Init Done Status */
#define DSI2_TX_PHY_MIXEL_PHY_INIT_DONE_MIXEL_PHY_INIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_TX_PHY_MIXEL_PHY_INIT_DONE_MIXEL_PHY_INIT_DONE_SHIFT)) & DSI2_TX_PHY_MIXEL_PHY_INIT_DONE_MIXEL_PHY_INIT_DONE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI2_TX_PHY_Register_Masks */


/*!
 * @}
 */ /* end of group DSI2_TX_PHY_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI2_TX_PHY_H_ */

