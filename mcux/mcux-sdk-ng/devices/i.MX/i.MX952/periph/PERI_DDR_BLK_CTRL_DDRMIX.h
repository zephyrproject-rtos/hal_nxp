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
**         CMSIS Peripheral Access Layer for DDR_BLK_CTRL_DDRMIX
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
 * @file PERI_DDR_BLK_CTRL_DDRMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DDR_BLK_CTRL_DDRMIX
 *
 * CMSIS Peripheral Access Layer for DDR_BLK_CTRL_DDRMIX
 */

#if !defined(PERI_DDR_BLK_CTRL_DDRMIX_H_)
#define PERI_DDR_BLK_CTRL_DDRMIX_H_              /**< Symbol preventing repeated inclusion */

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
   -- DDR_BLK_CTRL_DDRMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_BLK_CTRL_DDRMIX_Peripheral_Access_Layer DDR_BLK_CTRL_DDRMIX Peripheral Access Layer
 * @{
 */

/** DDR_BLK_CTRL_DDRMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t HWFFC_CTRL;                        /**< DDRPHY DfiClk and DflCtlClk HWFFC Control, offset: 0x0 */
  __IO uint32_t CA55_SEL_CTRL;                     /**< CA55 Arm PLL Observe Select, offset: 0x4 */
  __IO uint32_t VREF_PSW_CTRL;                     /**< DRAM_VREF Power Switch Control, offset: 0x8 */
  __IO uint32_t DDRC_STOP_CTRL;                    /**< DDRC ipg_stop Signal Software Control, offset: 0xC */
  __IO uint32_t AUTO_CG_CTRL;                      /**< DDRC Automatic Clock Gating Control, offset: 0x10 */
  __IO uint32_t SSI_PWR_CTRL;                      /**< NOC2DDR SSI Target Power Control, offset: 0x14 */
  __IO uint32_t DDRC_EXCLUSIVE_EN;                 /**< DDRC AXI Exclusive Access Monitor Enable, offset: 0x18 */
  __IO uint32_t DDRC_URGENT_EN;                    /**< DDRC real_time Read Urgent and Read Urgent Enable, offset: 0x1C */
  __IO uint32_t RT_MASTER_ID_0_1;                  /**< DDRC real_time Initiator Extend-ID Range 0 and 1, offset: 0x20 */
  __IO uint32_t RT_MASTER_ID_2_3;                  /**< DDRC real_time Initiator Extend-ID Range 2 and 3, offset: 0x24 */
  __IO uint32_t AXI_PARITY_ERR_CLR;                /**< DDRMIX AXI Parity Check Clear, offset: 0x28 */
  __IO uint32_t AXI_PARITY_ERR_INJECT;             /**< DDRMIX AXI Parity Error Injection, offset: 0x2C */
  __IO uint32_t RT_MASTER_ID_4_5;                  /**< DDRC real_time Initiator Extend-ID Range 4 and 5, offset: 0x30 */
  __IO uint32_t RT_MASTER_ID_6_7;                  /**< DDRC real_time Initiator Extend-ID Range 6 and 7, offset: 0x34 */
  __I  uint32_t FUSE_DISABLE_DDRMIX;               /**< Fuse to BLK_CTRL_DDRMIX, offset: 0x38 */
       uint8_t RESERVED_0[4];
  __IO uint32_t LPCG_FORCE_ON_OFF;                 /**< Force ON OFF Control for LPCG, offset: 0x40 */
  __IO uint32_t LPCG_FORCE_ON_OFF_SEL;             /**< Force ON OFF Select for LPCG, offset: 0x44 */
  __IO uint32_t AUTO_IPG_STOP_ACK_EN;              /**< Auto-generated DDRC ipg_stop_ack Signal, offset: 0x48 */
  __IO uint32_t CHK_FAULT_DIS;                     /**< Fault disable for safety faults, offset: 0x4C */
} DDR_BLK_CTRL_DDRMIX_Type;

/* ----------------------------------------------------------------------------
   -- DDR_BLK_CTRL_DDRMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_BLK_CTRL_DDRMIX_Register_Masks DDR_BLK_CTRL_DDRMIX Register Masks
 * @{
 */

/*! @name HWFFC_CTRL - DDRPHY DfiClk and DflCtlClk HWFFC Control */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT (0U)
/*! HWFFC_EN - DDRPHY DfiClk and DfiCtlClk HWFFC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT (1U)
/*! HWFFC_SEL - DDRPHY DfiClk and DfiCtlClk HWFFC Select
 *  0b0..Normal clock
 *  0b1..Div2 frequency clock
 */
#define DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT)) & DDR_BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK)
/*! @} */

/*! @name CA55_SEL_CTRL - CA55 Arm PLL Observe Select */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_SHIFT (0U)
/*! CA55_SEL - CA55 Arm PLL Select
 *  0b0..Normal DfiClk from DRAM PLL is selected
 *  0b1..CA55MIX Arm PLL is selected
 */
#define DDR_BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_SHIFT)) & DDR_BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_MASK)
/*! @} */

/*! @name VREF_PSW_CTRL - DRAM_VREF Power Switch Control */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_SHIFT (0U)
/*! VREF_PSW - DDRPHY DRAM_VREF Power Switch
 *  0b0..Power switch close. Prevent leakage.
 *  0b1..Power switch open. This is set together with DDRPHY registers .
 */
#define DDR_BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_SHIFT)) & DDR_BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_MASK)
/*! @} */

/*! @name DDRC_STOP_CTRL - DDRC ipg_stop Signal Software Control */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT (0U)
/*! DDRC_STOP - DDRC ipg_stop
 *  0b0..Clears DDRC ipg_stop signal
 *  0b1..Sets DDRC ipg_stop signal
 */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT (1U)
/*! DDRC_STOP_ACK - DDRC ipg_stop_ack
 *  0b0..DDRC ipg_stop_ack is a 0
 *  0b1..DDRC ipg_stop_ack is a 1
 */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_MASK (0x4U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_SHIFT (2U)
/*! DDRC_DRAM_SELF_REFRESH - DDRC ddrc_dram_self_refresh
 *  0b0..DDRC ddrc_dram_self_refresh is 0
 *  0b1..DDRC ddrc_dram_self_refresh is 1
 */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_MASK (0x10U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_SHIFT (4U)
/*! DDRC_STOP_HOLD_EN - DDRC ipg_stop Hold Period
 *  0b0..Disables hold of DDRC ipg_stop signal. The hardware will clear ipg_stop immediately after DDRC ipg_stop_ack.
 *  0b1..Enables hold of DDRC ipg_stop signal. The hardware will wait for a period of time before clearing DDRC ipg_stop.
 */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_MASK (0xFFFFFF00U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_SHIFT (8U)
/*! DDRC_STOP_HOLD_PERIOD - DDRC ipg_stop Hold Period */
#define DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_MASK)
/*! @} */

/*! @name AUTO_CG_CTRL - DDRC Automatic Clock Gating Control */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK (0xFFFFU)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT (0U)
/*! SSI_IDLE_STRAP - SSI Idle Cycle Count */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK (0x10000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT (16U)
/*! AUTO_CG_ENA - DDRC Automatic Clock Gating Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK (0x20000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT (17U)
/*! HWFFC_ACG_FORCE_B - DDRC HWFFC and Auto Clock Gating Send ipg_stop Signal
 *  0b0..DDRC HWFFC and auto CG cannot send ipg_stop signal
 *  0b1..DDRC HWFFC and auto CG can send ipg_stop signal
 */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_MASK (0x1000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_SHIFT (24U)
/*! GATE_DDRC_CLK - DDR Auto Clock Gating Allowed for DDRC ipg_clk_ddrc Clock
 *  0b0..DDRC Auto Clock Gating will not gate the DDRC ipg_clk_ddrc clock
 *  0b1..DDRC Auto Clock Gating will gate DDRC ipg_clk_ddrc clock inside DDRC, if there is no transaction
 */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_MASK (0x4000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_SHIFT (26U)
/*! GATE_DDRC_IPS_CLK - DDR Auto Clock Gating Allowed for DDRC IPS ips_clk_ddrc Clock
 *  0b0..DDRC Auto Clock Gating will not gate the DDRC IPS ips_clk_ddrc clock
 *  0b1..DDRC Auto Clock Gating will gate DDRC IPS ips_clk_ddrc clock inside DDRC, if there is no transaction
 */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_MASK (0x10000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_SHIFT (28U)
/*! GATE_DDRPHY_DFICLK - DDR Auto Clock Gating Allowed for DDRPHY DfiClk Clock
 *  0b0..DDRC Auto Clock Gating will not gate the DDRPHY DfiClk clock
 *  0b1..DDRC Auto Clock Gating will gate DDRPHY DfiClk clock inside DDDRPHY, if there is no transaction
 */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_MASK)

#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_MASK (0x40000000U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_SHIFT (30U)
/*! GATE_DDRPHY_APBCLK - DDR Auto Clock Gating Allowed for DDRPHY APBCLK Clock
 *  0b0..DDRC Auto Clock Gating will not gate the DDRPHY APBCLK clock
 *  0b1..DDRC Auto Clock Gating will gate DDRPHY APBCLK clock inside DDDRPHY, if there is no transaction
 */
#define DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_MASK)
/*! @} */

/*! @name SSI_PWR_CTRL - NOC2DDR SSI Target Power Control */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_POWER_CONTROL_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_POWER_CONTROL_SHIFT (0U)
/*! POWER_CONTROL - NOC2DDR SSI Target power_control Signal
 *  0b0..NOC2DDR SSI target power_control is 0
 *  0b1..NOC2DDR SSI target power_control is 1
 */
#define DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_POWER_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_POWER_CONTROL_SHIFT)) & DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_POWER_CONTROL_MASK)

#define DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_ISO_CONTROL_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_ISO_CONTROL_SHIFT (1U)
/*! ISO_CONTROL - NOC2DDR SSI Target iso_control Signal
 *  0b0..NOC2DDR SSI target iso_control is 0
 *  0b1..NOC2DDR SSI target iso_control is 1
 */
#define DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_ISO_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_ISO_CONTROL_SHIFT)) & DDR_BLK_CTRL_DDRMIX_SSI_PWR_CTRL_ISO_CONTROL_MASK)
/*! @} */

/*! @name DDRC_EXCLUSIVE_EN - DDRC AXI Exclusive Access Monitor Enable */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_SHIFT (0U)
/*! EXCLUSIVE_EN - Exclusive Access Monitor Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_MASK)
/*! @} */

/*! @name DDRC_URGENT_EN - DDRC real_time Read Urgent and Read Urgent Enable */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_SHIFT (0U)
/*! READ_URGENT_EN - DDRC ddrc_read_urgent Enable
 *  0b0..Disables. Real time initiators urgent signal will not reach DDRC read urgent.
 *  0b1..Enables. Real time initiators will sent urgent signal to DDRC read urgent.
 */
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_SHIFT (1U)
/*! AR_RT_URGENT_EN - DDRC ipa_ar_rt_urgent Enable
 *  0b0..Disables. Real time initiators urgent signal will not reach DDRC ar_rt urgent.
 *  0b1..Enables. Real time initiators will sent urgent signal to DDRC ar_rt urgent.
 */
#define DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_0_1 - DDRC real_time Initiator Extend-ID Range 0 and 1 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_SHIFT (0U)
/*! RANGE_0_ID - DDRC real_time Initiator ID Range 0 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_SHIFT (8U)
/*! RANGE_0_MASK - DDRC real_time Initiator ID Range 0 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_SHIFT (15U)
/*! RANGE_0_EN - DDRC real_time Initiator ID Range 0 Enable
 *  0b0..Disables. ID range 0 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 0 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_SHIFT (16U)
/*! RANGE_1_ID - DDRC real_time Initiator ID Range 1 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_SHIFT (24U)
/*! RANGE_1_MASK - DDRC real_time Initiator ID Range 1 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_SHIFT (31U)
/*! RANGE_1_EN - DDRC real_time Initiator ID Range 1 Enable
 *  0b0..Disables. ID range 1 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 1 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_2_3 - DDRC real_time Initiator Extend-ID Range 2 and 3 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_SHIFT (0U)
/*! RANGE_2_ID - DDRC real_time Initiator ID Range 2 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_SHIFT (8U)
/*! RANGE_2_MASK - DDRC real_time Initiator ID Range 2 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_SHIFT (15U)
/*! RANGE_2_EN - DDRC real_time Initiator ID Range 2 Enable
 *  0b0..Disables. ID range 2 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 2 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_SHIFT (16U)
/*! RANGE_3_ID - DDRC real_time Initiator ID Range 3 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_SHIFT (24U)
/*! RANGE_3_MASK - DDRC real_time Initiator ID Range 3 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_SHIFT (31U)
/*! RANGE_3_EN - DDRC real_time Initiator ID Range 3 Enable
 *  0b0..Disables. ID range 3 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 3 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_MASK)
/*! @} */

/*! @name AXI_PARITY_ERR_CLR - DDRMIX AXI Parity Check Clear */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_MST_ERR_CLR_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_MST_ERR_CLR_SHIFT (0U)
/*! MST_ERR_CLR - Initiator Error Clear
 *  0b0..Do not clear
 *  0b1..Clear
 */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_MST_ERR_CLR(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_MST_ERR_CLR_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_MST_ERR_CLR_MASK)

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_SLV_ERR_CLR_MASK (0x100U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_SLV_ERR_CLR_SHIFT (8U)
/*! SLV_ERR_CLR - Target Error Clear
 *  0b0..Do not clear
 *  0b1..Clear
 */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_SLV_ERR_CLR(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_SLV_ERR_CLR_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_SLV_ERR_CLR_MASK)

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_MASK (0x70000U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_SHIFT (16U)
/*! ERR_HOLD - Error Hold Time
 *  0b000..One
 *  0b001..Two
 *  0b010..Four
 *  0b011..Eight
 *  0b100..Sixteen
 *  0b101..Thirty Two
 *  0b110..Sixty Four
 *  0b111..One Hundred Twenty Eight
 */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_MASK)

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_EN_MASK (0x80000U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_EN_SHIFT (19U)
/*! ERR_HOLD_EN - Error Hold Enable */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_CLR_ERR_HOLD_EN_MASK)
/*! @} */

/*! @name AXI_PARITY_ERR_INJECT - DDRMIX AXI Parity Error Injection */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_SHIFT (0U)
/*! WDATA_ERR_INJ - DDRMIX AXI Parity Error Injection on wdatachk[0]
 *  0b0..No injection
 *  0b1..Injection
 */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_MASK)

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_SHIFT (1U)
/*! RDATA_ERR_INJ - DDRMIX AXI Parity Error Injection on rdatachk[0]
 *  0b0..No injection
 *  0b1..Injection
 */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_MASK)

#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_DDRC_MASK (0x4U)
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_DDRC_SHIFT (2U)
/*! RDATA_ERR_INJ_DDRC - DDRC AXI Parity Error Injection on rdatachk[0]
 *  0b0..No injection
 *  0b1..Injection
 */
#define DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_DDRC(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_DDRC_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_DDRC_MASK)
/*! @} */

/*! @name RT_MASTER_ID_4_5 - DDRC real_time Initiator Extend-ID Range 4 and 5 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_SHIFT (0U)
/*! RANGE_4_ID - DDRC real_time Initiator ID Range 4 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_SHIFT (8U)
/*! RANGE_4_MASK - DDRC real_time Initiator ID Range 4 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_SHIFT (15U)
/*! RANGE_4_EN - DDRC real_time Initiator ID Range 4 Enable
 *  0b0..Disables. ID range 4 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 4 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_SHIFT (16U)
/*! RANGE_5_ID - DDRC real_time Initiator ID Range 5 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_SHIFT (24U)
/*! RANGE_5_MASK - DDRC real_time Initiator ID Range 5 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_SHIFT (31U)
/*! RANGE_5_EN - DDRC real_time Initiator ID Range 5 Enable
 *  0b0..Disables. ID range 5 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 5 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_6_7 - DDRC real_time Initiator Extend-ID Range 6 and 7 */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_MASK (0x3FU)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_SHIFT (0U)
/*! RANGE_6_ID - DDRC real_time Initiator ID Range 6 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_MASK (0x3F00U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_SHIFT (8U)
/*! RANGE_6_MASK - DDRC real_time Initiator ID Range 6 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_MASK (0x8000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_SHIFT (15U)
/*! RANGE_6_EN - DDRC real_time Initiator ID Range 6 Enable
 *  0b0..Disables. ID range 6 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 6 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_MASK (0x3F0000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_SHIFT (16U)
/*! RANGE_7_ID - DDRC real_time Initiator ID Range 7 ID */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_MASK (0x3F000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_SHIFT (24U)
/*! RANGE_7_MASK - DDRC real_time Initiator ID Range 7 ID Mask */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_MASK)

#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_MASK (0x80000000U)
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_SHIFT (31U)
/*! RANGE_7_EN - DDRC real_time Initiator ID Range 7 Enable
 *  0b0..Disables. ID range 7 will not be used to generate ipa_ar_real_time.
 *  0b1..Enables. ID range 7 will be used to generate ipa_ar_real_time.
 */
#define DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_SHIFT)) & DDR_BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_MASK)
/*! @} */

/*! @name FUSE_DISABLE_DDRMIX - Fuse to BLK_CTRL_DDRMIX */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_FUSE_DISABLE_DDRMIX_FUSE_DISABLE_DDRMIX_MASK (0x3U)
#define DDR_BLK_CTRL_DDRMIX_FUSE_DISABLE_DDRMIX_FUSE_DISABLE_DDRMIX_SHIFT (0U)
/*! FUSE_DISABLE_DDRMIX - Fuse Mapped to BLK_CTRL_DDRMIX
 *  0b00..The value from fuse map DDRMIX_BLK_CTRL is 0
 *  0b01..The value from fuse map DDRMIX_BLK_CTRL is 1
 */
#define DDR_BLK_CTRL_DDRMIX_FUSE_DISABLE_DDRMIX_FUSE_DISABLE_DDRMIX(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_FUSE_DISABLE_DDRMIX_FUSE_DISABLE_DDRMIX_SHIFT)) & DDR_BLK_CTRL_DDRMIX_FUSE_DISABLE_DDRMIX_FUSE_DISABLE_DDRMIX_MASK)
/*! @} */

/*! @name LPCG_FORCE_ON_OFF - Force ON OFF Control for LPCG */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDR_CTRL_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDR_CTRL_SHIFT (0U)
/*! DDR_CTRL - force_on_off for DDR_CTRL Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDR_CTRL_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDR_CTRL_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SSI_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SSI_SHIFT (1U)
/*! SSI - force_on_off for SSI Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SSI(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SSI_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SSI_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_DFI_MASK (0x4U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_DFI_SHIFT (2U)
/*! DDRPHY_DFI - force_on_off for DDRPHY DFI Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_DFI(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_DFI_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_DFI_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_INFRA_MASK (0x8U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_INFRA_SHIFT (3U)
/*! INFRA - force_on_off_sel for INFRA Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_INFRA(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_INFRA_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_INFRA_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_LSTCU_MASK (0x10U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_LSTCU_SHIFT (4U)
/*! LSTCU - force_on_off for LSTCU Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_LSTCU(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_LSTCU_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_LSTCU_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_PllBypClk_MASK (0x20U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_PllBypClk_SHIFT (5U)
/*! PllBypClk - force_on_off for PllBypClk Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_PllBypClk(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_PllBypClk_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_PllBypClk_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_ALT_MASK (0x40U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_ALT_SHIFT (6U)
/*! DDRPHY_ALT - force_on_off for DDRPHY_ALT Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_ALT(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_ALT_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_DDRPHY_ALT_MASK)
/*! @} */

/*! @name LPCG_FORCE_ON_OFF_SEL - Force ON OFF Select for LPCG */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDR_CTRL_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDR_CTRL_SHIFT (0U)
/*! DDR_CTRL - force_on_off_sel for DDR_CTRL Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDR_CTRL_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDR_CTRL_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_SSI_MASK (0x2U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_SSI_SHIFT (1U)
/*! SSI - force_on_off_sel for SSI Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_SSI(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_SSI_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_SSI_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_DFI_MASK (0x4U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_DFI_SHIFT (2U)
/*! DDRPHY_DFI - force_on_off_sel for DDRPHY DFI Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_DFI(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_DFI_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_DFI_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_INFRA_MASK (0x8U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_INFRA_SHIFT (3U)
/*! INFRA - force_on_off_sel for INFRA Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_INFRA(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_INFRA_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_INFRA_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_LSTCU_MASK (0x10U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_LSTCU_SHIFT (4U)
/*! LSTCU - force_on_off_sel for LSTCU Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_LSTCU(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_LSTCU_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_LSTCU_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_PllBypClk_MASK (0x20U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_PllBypClk_SHIFT (5U)
/*! PllBypClk - force_on_off_sel for PllBypClk Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_PllBypClk(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_PllBypClk_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_PllBypClk_MASK)

#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_ALT_MASK (0x40U)
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_ALT_SHIFT (6U)
/*! DDRPHY_ALT - force_on_off_sel for DDRPHY_ALT Group */
#define DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_ALT(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_ALT_SHIFT)) & DDR_BLK_CTRL_DDRMIX_LPCG_FORCE_ON_OFF_SEL_DDRPHY_ALT_MASK)
/*! @} */

/*! @name AUTO_IPG_STOP_ACK_EN - Auto-generated DDRC ipg_stop_ack Signal */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_AUTO_IPG_STOP_ACK_EN_auto_ipg_stop_ack_en_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_AUTO_IPG_STOP_ACK_EN_auto_ipg_stop_ack_en_SHIFT (0U)
/*! auto_ipg_stop_ack_en - Auto-generated DDRC ipg_stop_ack Signal */
#define DDR_BLK_CTRL_DDRMIX_AUTO_IPG_STOP_ACK_EN_auto_ipg_stop_ack_en(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_AUTO_IPG_STOP_ACK_EN_auto_ipg_stop_ack_en_SHIFT)) & DDR_BLK_CTRL_DDRMIX_AUTO_IPG_STOP_ACK_EN_auto_ipg_stop_ack_en_MASK)
/*! @} */

/*! @name CHK_FAULT_DIS - Fault disable for safety faults */
/*! @{ */

#define DDR_BLK_CTRL_DDRMIX_CHK_FAULT_DIS_ddr_phy_intfc_chk_fault_dis_MASK (0x1U)
#define DDR_BLK_CTRL_DDRMIX_CHK_FAULT_DIS_ddr_phy_intfc_chk_fault_dis_SHIFT (0U)
/*! ddr_phy_intfc_chk_fault_dis - disable signal for ddr_phy_intfc_chk_fault
 *  0b0..ddr_phy_intfc_chk_fault is enabled
 *  0b1..ddr_phy_intfc_chk_fault is disabled
 */
#define DDR_BLK_CTRL_DDRMIX_CHK_FAULT_DIS_ddr_phy_intfc_chk_fault_dis(x) (((uint32_t)(((uint32_t)(x)) << DDR_BLK_CTRL_DDRMIX_CHK_FAULT_DIS_ddr_phy_intfc_chk_fault_dis_SHIFT)) & DDR_BLK_CTRL_DDRMIX_CHK_FAULT_DIS_ddr_phy_intfc_chk_fault_dis_MASK)
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


#endif  /* PERI_DDR_BLK_CTRL_DDRMIX_H_ */

