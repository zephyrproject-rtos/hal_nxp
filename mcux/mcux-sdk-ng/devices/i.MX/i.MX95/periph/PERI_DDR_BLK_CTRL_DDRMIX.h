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
**         CMSIS Peripheral Access Layer for DDR_BLK_CTRL_DDRMIX
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
 * @file DDR_BLK_CTRL_DDRMIX.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DDR_BLK_CTRL_DDRMIX
 *
 * CMSIS Peripheral Access Layer for DDR_BLK_CTRL_DDRMIX
 */

#if !defined(DDR_BLK_CTRL_DDRMIX_H_)
#define DDR_BLK_CTRL_DDRMIX_H_                   /**< Symbol preventing repeated inclusion */

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
   -- DDR_BLK_CTRL_DDRMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_BLK_CTRL_DDRMIX_Peripheral_Access_Layer DDR_BLK_CTRL_DDRMIX Peripheral Access Layer
 * @{
 */

/** DDR_BLK_CTRL_DDRMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t HWFFC_CTRL;                        /**< DDRPHY DfiClk, DflCtlClk HWFFC Control, offset: 0x0 */
       uint8_t RESERVED_0[8];
  __IO uint32_t DDRC_STOP_CTRL;                    /**< DDR Controller ipg_stop SW control, offset: 0xC */
  __IO uint32_t AUTO_CG_CTRL;                      /**< DDR Controller automatic clock gating control when no AXI transmit, offset: 0x10 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DDRC_EXCLUSIVE_EN;                 /**< DDRC AXI exclusive access monitor enable, offset: 0x18 */
  __IO uint32_t DDRC_URGENT_EN;                    /**< DDRC real_time read urgent and read urgent enable, offset: 0x1C */
  __IO uint32_t RT_MASTER_ID_0_1;                  /**< DDRC real_time master 6bit extend-ID range 0 and range 1, offset: 0x20 */
  __IO uint32_t RT_MASTER_ID_2_3;                  /**< DDRC real_time master 6bit extend-ID range 2 and range 3, offset: 0x24 */
       uint8_t RESERVED_2[4];
  __IO uint32_t AXI_PARITY_ERR_INJECT;             /**< DDRMIX AXI parity error injection register, offset: 0x2C */
  __IO uint32_t RT_MASTER_ID_4_5;                  /**< DDRC real_time master 6bit extend-ID range 4 and range 5, offset: 0x30 */
  __IO uint32_t RT_MASTER_ID_6_7;                  /**< DDRC real_time master 6bit extend-ID range 6 and range 7, offset: 0x34 */
} DDR_BLK_CTRL_DDRMIX_Type;

/* ----------------------------------------------------------------------------
   -- DDR_BLK_CTRL_DDRMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_BLK_CTRL_DDRMIX_Register_Masks DDR_BLK_CTRL_DDRMIX Register Masks
 * @{
 */

/*! @name HWFFC_CTRL - DDRPHY DfiClk, DflCtlClk HWFFC Control */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT (0U)
/*! HWFFC_EN - DDRPHY DfiClk, DfiCtlClk HWFFC Enable */
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT (1U)
/*! HWFFC_SEL - DDRPHY DfiClk, DfiCtlClk HWFFC Select */
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT)) & DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK)
/*! @} */

/*! @name DDRC_STOP_CTRL - DDR Controller ipg_stop SW control */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT (0U)
/*! DDRC_STOP - DDR Controller ipg_stop. */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT (1U)
/*! DDRC_STOP_ACK - DDR Controller ipg_stop_ack. */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_MASK (0x4U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_SHIFT (2U)
/*! DDRC_DRAM_SELF_REFRESH - DDR Controller ddrc_dram_self_refresh. */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_MASK (0x10U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_SHIFT (4U)
/*! DDRC_STOP_HOLD_EN - DDR Controller ipg_stop holds for a period of time before clearing. */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_MASK (0xFFFFFF00U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_SHIFT (8U)
/*! DDRC_STOP_HOLD_PERIOD - DDR Controller ipg_stop hold period before clearing. */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_MASK)
/*! @} */

/*! @name AUTO_CG_CTRL - DDR Controller automatic clock gating control when no AXI transmit */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK (0xFFFFU)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT (0U)
/*! SSI_IDLE_STRAP - Number of cycles for SSI being idle before DDRC clock gating. */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK (0x10000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT (16U)
/*! AUTO_CG_ENA - DDR Controller automatic clock gating enable bit. */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK (0x20000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT (17U)
/*! HWFFC_ACG_FORCE_B - DDR Controller hwffc and auto CG send ipg_stop allow bit. Can only programmed once. */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_MASK (0x1000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_SHIFT (24U)
/*! GATE_DDRC_CLK - DDR Auto Clock Gating is allowed for DDR Controller clock ipg_clk_ddrc. */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_MASK (0x4000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_SHIFT (26U)
/*! GATE_DDRC_IPS_CLK - DDR Auto Clock Gating is allowed for DDR Controller IPS clock ips_clk_ddrc. */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_MASK (0x10000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_SHIFT (28U)
/*! GATE_DDRPHY_DFICLK - DDR Auto Clock Gating is allowed for DDRPHY DfiClk clock. */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_MASK (0x40000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_SHIFT (30U)
/*! GATE_DDRPHY_APBCLK - DDR Auto Clock Gating is allowed for DDRPHY APBCLK clock. */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_MASK)
/*! @} */

/*! @name DDRC_EXCLUSIVE_EN - DDRC AXI exclusive access monitor enable */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_SHIFT (0U)
/*! EXCLUSIVE_EN - DDRC AXI exclusive access monitor enable */
#define DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_MASK)
/*! @} */

/*! @name DDRC_URGENT_EN - DDRC real_time read urgent and read urgent enable */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_SHIFT (0U)
/*! READ_URGENT_EN - DDRC ddrc_read_urgent is enabled */
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_SHIFT (1U)
/*! AR_RT_URGENT_EN - DDRC ipa_ar_rt_urgent is enabled */
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_0_1 - DDRC real_time master 6bit extend-ID range 0 and range 1 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_SHIFT (0U)
/*! RANGE_0_ID - DDRC real_time master ID range 0 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_SHIFT (8U)
/*! RANGE_0_MASK - DDRC real_time master ID range 0 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_SHIFT (15U)
/*! RANGE_0_EN - DDRC real_time master ID range 0 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_SHIFT (16U)
/*! RANGE_1_ID - DDRC real_time master ID range 1 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_SHIFT (24U)
/*! RANGE_1_MASK - DDRC real_time master ID range 1 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_SHIFT (31U)
/*! RANGE_1_EN - DDRC real_time master ID range 1 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_2_3 - DDRC real_time master 6bit extend-ID range 2 and range 3 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_SHIFT (0U)
/*! RANGE_2_ID - DDRC real_time master ID range 2 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_SHIFT (8U)
/*! RANGE_2_MASK - DDRC real_time master ID range 2 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_SHIFT (15U)
/*! RANGE_2_EN - DDRC real_time master ID range 2 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_SHIFT (16U)
/*! RANGE_3_ID - DDRC real_time master ID range 3 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_SHIFT (24U)
/*! RANGE_3_MASK - DDRC real_time master ID range 3 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_SHIFT (31U)
/*! RANGE_3_EN - DDRC real_time master ID range 3 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_MASK)
/*! @} */

/*! @name AXI_PARITY_ERR_INJECT - DDRMIX AXI parity error injection register */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_SHIFT (0U)
/*! WDATA_ERR_INJ - DDRMIX AXI parity error injection on wdatachk[0] */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_MASK)

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_MASK (0x10000U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_SHIFT (16U)
/*! RDATA_ERR_INJ - DDRMIX AXI parity error injection on rdatachk[0] */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_MASK)
/*! @} */

/*! @name RT_MASTER_ID_4_5 - DDRC real_time master 6bit extend-ID range 4 and range 5 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_SHIFT (0U)
/*! RANGE_4_ID - DDRC real_time master ID range 4 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_SHIFT (8U)
/*! RANGE_4_MASK - DDRC real_time master ID range 4 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_SHIFT (15U)
/*! RANGE_4_EN - DDRC real_time master ID range 4 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_SHIFT (16U)
/*! RANGE_5_ID - DDRC real_time master ID range 5 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_SHIFT (24U)
/*! RANGE_5_MASK - DDRC real_time master ID range 5 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_SHIFT (31U)
/*! RANGE_5_EN - DDRC real_time master ID range 5 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_6_7 - DDRC real_time master 6bit extend-ID range 6 and range 7 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_SHIFT (0U)
/*! RANGE_6_ID - DDRC real_time master ID range 6 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_SHIFT (8U)
/*! RANGE_6_MASK - DDRC real_time master ID range 6 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_SHIFT (15U)
/*! RANGE_6_EN - DDRC real_time master ID range 6 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_SHIFT (16U)
/*! RANGE_7_ID - DDRC real_time master ID range 7 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_SHIFT (24U)
/*! RANGE_7_MASK - DDRC real_time master ID range 7 ID mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_SHIFT (31U)
/*! RANGE_7_EN - DDRC real_time master ID range 7 enable */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DDR_BLK_CTRL_DDRMIX_Register_Masks */


/*!
 * @}
 */ /* end of group DDR_BLK_CTRL_DDRMIX_Peripheral_Access_Layer */


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


#endif  /* DDR_BLK_CTRL_DDRMIX_H_ */

