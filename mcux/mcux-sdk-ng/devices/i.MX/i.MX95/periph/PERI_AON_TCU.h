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
**         CMSIS Peripheral Access Layer for AON_TCU
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
 * @file AON_TCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_TCU
 *
 * CMSIS Peripheral Access Layer for AON_TCU
 */

#if !defined(AON_TCU_H_)
#define AON_TCU_H_                               /**< Symbol preventing repeated inclusion */

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
   -- AON_TCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_TCU_Peripheral_Access_Layer AON_TCU Peripheral Access Layer
 * @{
 */

/** AON_TCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1024];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW0;           /**< Magic KW0, offset: 0x400 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW1;           /**< Magic KW1, offset: 0x410 */
       uint8_t RESERVED_2[348];
  __IO uint32_t TCU_CRR_IPT_CORE_HOLD;             /**< ipc_core_hold, offset: 0x570 */
       uint8_t RESERVED_3[140];
  __IO uint32_t TCU_MTR_MCT_ACCESS_;               /**< MCT Test Mode CTRL Reg, offset: 0x600 */
       uint8_t RESERVED_4[12];
  __IO uint32_t TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL0; /**< MCT Launch ALGOSEL0 Reg, offset: 0x610 */
  __IO uint32_t TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL1; /**< MCT Launch ALGOSEL1 Reg, offset: 0x614 */
       uint8_t RESERVED_5[8];
  __IO uint32_t TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL0; /**< MCT Launch BISTSEL0 Reg, offset: 0x620 */
  __IO uint32_t TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL1; /**< MCT Launch BISTSEL1 Reg, offset: 0x624 */
  __IO uint32_t TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL2; /**< MCT Launch BISTSEL2 Reg, offset: 0x628 */
  __IO uint32_t TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL3; /**< MCT Launch BISTSEL2 Reg, offset: 0x62C */
       uint8_t RESERVED_6[32];
  __IO uint32_t TCU_MTR_DIRECT_BIST_ACCESS_;       /**< Direct BIST Access CTRL Reg, offset: 0x650 */
       uint8_t RESERVED_7[1452];
  __IO uint32_t TCU_PLL_COUNTER;                   /**< tcu pll counter reg, offset: 0xC00 */
       uint8_t RESERVED_8[60];
  __IO uint32_t TCU_DFT_FUSE;                      /**< observe MIX fuse state and override it, offset: 0xC40 */
} AON_TCU_Type;

/* ----------------------------------------------------------------------------
   -- AON_TCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_TCU_Register_Masks AON_TCU Register Masks
 * @{
 */

/*! @name TCU_MAGIC_KW__MAGIC_KW0 - Magic KW0 */
/*! @{ */

#define AON_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT (0U)
/*! out - 32-Bit Magic KW0 used in conjuction with Magic KW1 to unlock the writes to test mode registers (Value is 0x12345678) */
#define AON_TCU_TCU_MAGIC_KW__MAGIC_KW0_out(x)   (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT)) & AON_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK)
/*! @} */

/*! @name TCU_MAGIC_KW__MAGIC_KW1 - Magic KW1 */
/*! @{ */

#define AON_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT (0U)
/*! out - 32-Bit Magic KW1 used in conjuction with Magic KW0 to unlock the writes to test mode registers (Value - 0x87654321) */
#define AON_TCU_TCU_MAGIC_KW__MAGIC_KW1_out(x)   (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT)) & AON_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK)
/*! @} */

/*! @name TCU_CRR_IPT_CORE_HOLD - ipc_core_hold */
/*! @{ */

#define AON_TCU_TCU_CRR_IPT_CORE_HOLD_ipt_core_hold_MASK (0x1U)
#define AON_TCU_TCU_CRR_IPT_CORE_HOLD_ipt_core_hold_SHIFT (0U)
/*! ipt_core_hold - ipt_core_hold */
#define AON_TCU_TCU_CRR_IPT_CORE_HOLD_ipt_core_hold(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_CRR_IPT_CORE_HOLD_ipt_core_hold_SHIFT)) & AON_TCU_TCU_CRR_IPT_CORE_HOLD_ipt_core_hold_MASK)
/*! @} */

/*! @name TCU_MTR_MCT_ACCESS_ - MCT Test Mode CTRL Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_test_mode_MASK (0x1U)
#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_test_mode_SHIFT (0U)
/*! mct_test_mode - For using MCT test mode through the TCU, this bit has to be set first which
 *    enables all the muxes related to this test mode
 */
#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_test_mode(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__mct_test_mode_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__mct_test_mode_MASK)

#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_bist_start_MASK (0x2U)
#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_bist_start_SHIFT (1U)
/*! mct_launch_bist_start - Signal in the MCT that is basically used to start all the BIST's selected through mct_launch_bistsel registers */
#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_bist_start(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_bist_start_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_bist_start_MASK)

#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_crep_MASK (0x4U)
#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_crep_SHIFT (2U)
/*! mct_launch_crep - Signal in the MCT used to calculate repair while running the BIST incase of any failure */
#define AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_crep(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_crep_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__mct_launch_crep_MASK)
/*! @} */

/*! @name TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL0 - MCT Launch ALGOSEL0 Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL0_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL0_out_SHIFT (0U)
/*! out - Select the required algorithm */
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL0_out(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL0_out_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL0_out_MASK)
/*! @} */

/*! @name TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL1 - MCT Launch ALGOSEL1 Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL1_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL1_out_SHIFT (0U)
/*! out - Select the required algorithm */
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL1_out(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL1_out_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_ALGOSEL1_out_MASK)
/*! @} */

/*! @name TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL0 - MCT Launch BISTSEL0 Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL0_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL0_out_SHIFT (0U)
/*! out - Selects BIST's [31:0] that will be run */
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL0_out(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL0_out_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL0_out_MASK)
/*! @} */

/*! @name TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL1 - MCT Launch BISTSEL1 Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL1_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL1_out_SHIFT (0U)
/*! out - Selects BIST's [63:32] that will be run */
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL1_out(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL1_out_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL1_out_MASK)
/*! @} */

/*! @name TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL2 - MCT Launch BISTSEL2 Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL2_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL2_out_SHIFT (0U)
/*! out - Selects BIST's [95:64] that will be run */
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL2_out(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL2_out_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL2_out_MASK)
/*! @} */

/*! @name TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL3 - MCT Launch BISTSEL2 Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL3_out_MASK (0xFFFFFFFFU)
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL3_out_SHIFT (0U)
/*! out - Selects BIST's [127:96] that will be run */
#define AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL3_out(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL3_out_SHIFT)) & AON_TCU_TCU_MTR_MCT_ACCESS__MCT_LAUNCH_BISTSEL3_out_MASK)
/*! @} */

/*! @name TCU_MTR_DIRECT_BIST_ACCESS_ - Direct BIST Access CTRL Reg */
/*! @{ */

#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_mode_MASK (0x1U)
#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_mode_SHIFT (0U)
/*! bist_mode - bist mode indication */
#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_mode(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_mode_SHIFT)) & AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_mode_MASK)

#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_mode_MASK (0x2U)
#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_mode_SHIFT (1U)
/*! bist_burnin_loop_mode - Test mode bit to qualify the BIST start in Burn-in mode */
#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_mode(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_mode_SHIFT)) & AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_mode_MASK)

#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_start_MASK (0x4U)
#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_start_SHIFT (2U)
/*! bist_burnin_loop_start - start burnin BIST signal */
#define AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_start(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_start_SHIFT)) & AON_TCU_TCU_MTR_DIRECT_BIST_ACCESS__bist_burnin_loop_start_MASK)
/*! @} */

/*! @name TCU_PLL_COUNTER - tcu pll counter reg */
/*! @{ */

#define AON_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK (0x1U)
#define AON_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT (0U)
/*! pll_count_rst_n - pll count reset */
#define AON_TCU_TCU_PLL_COUNTER_pll_count_rst_n(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT)) & AON_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK)

#define AON_TCU_TCU_PLL_COUNTER_pll_count_start_MASK (0x2U)
#define AON_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT (1U)
/*! pll_count_start - pll count start */
#define AON_TCU_TCU_PLL_COUNTER_pll_count_start(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT)) & AON_TCU_TCU_PLL_COUNTER_pll_count_start_MASK)

#define AON_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK (0x4U)
#define AON_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT (2U)
/*! pll_count_div_en - pll count div en */
#define AON_TCU_TCU_PLL_COUNTER_pll_count_div_en(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT)) & AON_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK)

#define AON_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK (0x38U)
#define AON_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT (3U)
/*! pll_count_clk_sel - pll count clk sel */
#define AON_TCU_TCU_PLL_COUNTER_pll_count_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT)) & AON_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK)

#define AON_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK (0xFF00U)
#define AON_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT (8U)
/*! pll_count_ref_val - pll count ref val */
#define AON_TCU_TCU_PLL_COUNTER_pll_count_ref_val(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT)) & AON_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK)

#define AON_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK (0xFFFF0000U)
#define AON_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT (16U)
/*! pll_count_cnt - pll count cnt */
#define AON_TCU_TCU_PLL_COUNTER_pll_count_cnt(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT)) & AON_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK)
/*! @} */

/*! @name TCU_DFT_FUSE - observe MIX fuse state and override it */
/*! @{ */

#define AON_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK (0x1U)
#define AON_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT (0U)
/*! tcu_dft_fuse_disable - dft fuse disable */
#define AON_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable(x) (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT)) & AON_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK)

#define AON_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK   (0x3EU)
#define AON_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT  (1U)
/*! tcu_fuse_obs - fuse observation */
#define AON_TCU_TCU_DFT_FUSE_tcu_fuse_obs(x)     (((uint32_t)(((uint32_t)(x)) << AON_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT)) & AON_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AON_TCU_Register_Masks */


/*!
 * @}
 */ /* end of group AON_TCU_Peripheral_Access_Layer */


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


#endif  /* AON_TCU_H_ */

