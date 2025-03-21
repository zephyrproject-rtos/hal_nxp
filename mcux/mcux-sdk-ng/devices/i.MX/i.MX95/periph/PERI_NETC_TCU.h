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
**         CMSIS Peripheral Access Layer for NETC_TCU
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
 * @file NETC_TCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NETC_TCU
 *
 * CMSIS Peripheral Access Layer for NETC_TCU
 */

#if !defined(NETC_TCU_H_)
#define NETC_TCU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- NETC_TCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_TCU_Peripheral_Access_Layer NETC_TCU Peripheral Access Layer
 * @{
 */

/** NETC_TCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1024];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW0;           /**< Magic KW0, offset: 0x400 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW1;           /**< Magic KW1, offset: 0x410 */
       uint8_t RESERVED_2[252];
  __IO uint32_t TCU_SCM;                           /**< SCM test mode, offset: 0x510 */
       uint8_t RESERVED_3[12];
  __IO uint32_t TCU_SCM_SEL;                       /**< SCM test sel, offset: 0x520 */
       uint8_t RESERVED_4[12];
  __IO uint32_t TCU_ENET_BS;                       /**< enet_bs test mode, offset: 0x530 */
       uint8_t RESERVED_5[44];
  __IO uint32_t TCU_DFT_DIVIDER;                   /**< observe MIX divider state and override it, offset: 0x560 */
       uint8_t RESERVED_6[764];
  __IO uint32_t TCU_ENET_REF_CLK_SEL;              /**< clock select, offset: 0x860 */
       uint8_t RESERVED_7[924];
  __IO uint32_t TCU_PLL_COUNTER;                   /**< tcu pll counter reg, offset: 0xC00 */
       uint8_t RESERVED_8[60];
  __IO uint32_t TCU_DFT_FUSE;                      /**< observe MIX fuse state and override it, offset: 0xC40 */
} NETC_TCU_Type;

/* ----------------------------------------------------------------------------
   -- NETC_TCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_TCU_Register_Masks NETC_TCU Register Masks
 * @{
 */

/*! @name TCU_MAGIC_KW__MAGIC_KW0 - Magic KW0 */
/*! @{ */

#define NETC_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK (0xFFFFFFFFU)
#define NETC_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT (0U)
/*! out - 32-Bit Magic KW0 used in conjuction with Magic KW1 to unlock the writes to test mode registers (Value is 0x12345678) */
#define NETC_TCU_TCU_MAGIC_KW__MAGIC_KW0_out(x)  (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT)) & NETC_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK)
/*! @} */

/*! @name TCU_MAGIC_KW__MAGIC_KW1 - Magic KW1 */
/*! @{ */

#define NETC_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK (0xFFFFFFFFU)
#define NETC_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT (0U)
/*! out - 32-Bit Magic KW1 used in conjuction with Magic KW0 to unlock the writes to test mode registers (Value - 0x87654321) */
#define NETC_TCU_TCU_MAGIC_KW__MAGIC_KW1_out(x)  (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT)) & NETC_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK)
/*! @} */

/*! @name TCU_SCM - SCM test mode */
/*! @{ */

#define NETC_TCU_TCU_SCM_scm_test_mode_MASK      (0x1U)
#define NETC_TCU_TCU_SCM_scm_test_mode_SHIFT     (0U)
/*! scm_test_mode - SCM test mode */
#define NETC_TCU_TCU_SCM_scm_test_mode(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_SCM_scm_test_mode_SHIFT)) & NETC_TCU_TCU_SCM_scm_test_mode_MASK)

#define NETC_TCU_TCU_SCM_scm_obst_rst_b_MASK     (0x2U)
#define NETC_TCU_TCU_SCM_scm_obst_rst_b_SHIFT    (1U)
/*! scm_obst_rst_b - SCM obst rst b */
#define NETC_TCU_TCU_SCM_scm_obst_rst_b(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_SCM_scm_obst_rst_b_SHIFT)) & NETC_TCU_TCU_SCM_scm_obst_rst_b_MASK)

#define NETC_TCU_TCU_SCM_scm_result_MASK         (0x3FFFCU)
#define NETC_TCU_TCU_SCM_scm_result_SHIFT        (2U)
/*! scm_result - SCM results */
#define NETC_TCU_TCU_SCM_scm_result(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_SCM_scm_result_SHIFT)) & NETC_TCU_TCU_SCM_scm_result_MASK)
/*! @} */

/*! @name TCU_SCM_SEL - SCM test sel */
/*! @{ */

#define NETC_TCU_TCU_SCM_SEL_scm_sel_MASK        (0xFFFFFFFFU)
#define NETC_TCU_TCU_SCM_SEL_scm_sel_SHIFT       (0U)
/*! scm_sel - SCM clock sel */
#define NETC_TCU_TCU_SCM_SEL_scm_sel(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_SCM_SEL_scm_sel_SHIFT)) & NETC_TCU_TCU_SCM_SEL_scm_sel_MASK)
/*! @} */

/*! @name TCU_ENET_BS - enet_bs test mode */
/*! @{ */

#define NETC_TCU_TCU_ENET_BS_enet_bs_tdi_MASK    (0x1U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_tdi_SHIFT   (0U)
/*! enet_bs_tdi - enet_bs tdi */
#define NETC_TCU_TCU_ENET_BS_enet_bs_tdi(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_tdi_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_tdi_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_acmode_MASK (0x2U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_acmode_SHIFT (1U)
/*! enet_bs_acmode - enet_bs_acmode */
#define NETC_TCU_TCU_ENET_BS_enet_bs_acmode(x)   (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_acmode_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_acmode_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_actest_MASK (0x4U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_actest_SHIFT (2U)
/*! enet_bs_actest - enet_bs_actest */
#define NETC_TCU_TCU_ENET_BS_enet_bs_actest(x)   (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_actest_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_actest_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_cdr_MASK    (0x8U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_cdr_SHIFT   (3U)
/*! enet_bs_cdr - enet_bs_cdr */
#define NETC_TCU_TCU_ENET_BS_enet_bs_cdr(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_cdr_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_cdr_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_udr_MASK    (0x10U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_udr_SHIFT   (4U)
/*! enet_bs_udr - enet_bs_udr */
#define NETC_TCU_TCU_ENET_BS_enet_bs_udr(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_udr_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_udr_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_ce_MASK     (0x20U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_ce_SHIFT    (5U)
/*! enet_bs_ce - enet_bs_ce */
#define NETC_TCU_TCU_ENET_BS_enet_bs_ce(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_ce_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_ce_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_init_MASK (0x40U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_init_SHIFT (6U)
/*! enet_bs_rx_init - enet_bs_rx_init */
#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_init(x)  (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_rx_init_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_rx_init_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_sdr_MASK    (0x80U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_sdr_SHIFT   (7U)
/*! enet_bs_sdr - enet_bs_sdr */
#define NETC_TCU_TCU_ENET_BS_enet_bs_sdr(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_sdr_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_sdr_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_tx_lowswing_MASK (0x100U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_tx_lowswing_SHIFT (8U)
/*! enet_bs_tx_lowswing - enet_bs_tx_lowswing */
#define NETC_TCU_TCU_ENET_BS_enet_bs_tx_lowswing(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_tx_lowswing_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_tx_lowswing_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_bigswing_MASK (0x200U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_bigswing_SHIFT (9U)
/*! enet_bs_rx_bigswing - enet_bs_rx_bigswing */
#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_bigswing(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_rx_bigswing_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_rx_bigswing_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_level_MASK (0x7C00U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_level_SHIFT (10U)
/*! enet_bs_rx_level - enet_bs_rx_level */
#define NETC_TCU_TCU_ENET_BS_enet_bs_rx_level(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_rx_level_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_rx_level_MASK)

#define NETC_TCU_TCU_ENET_BS_enet_bs_tdo_MASK    (0x80000000U)
#define NETC_TCU_TCU_ENET_BS_enet_bs_tdo_SHIFT   (31U)
/*! enet_bs_tdo - enet_bs_tdo */
#define NETC_TCU_TCU_ENET_BS_enet_bs_tdo(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_BS_enet_bs_tdo_SHIFT)) & NETC_TCU_TCU_ENET_BS_enet_bs_tdo_MASK)
/*! @} */

/*! @name TCU_DFT_DIVIDER - observe MIX divider state and override it */
/*! @{ */

#define NETC_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_MASK (0x1U)
#define NETC_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_SHIFT (0U)
/*! tcu_dft_divider_disable - dft divider disable */
#define NETC_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_SHIFT)) & NETC_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_MASK)
/*! @} */

/*! @name TCU_ENET_REF_CLK_SEL - clock select */
/*! @{ */

#define NETC_TCU_TCU_ENET_REF_CLK_SEL_enet_ref_clk_sel_MASK (0x1U)
#define NETC_TCU_TCU_ENET_REF_CLK_SEL_enet_ref_clk_sel_SHIFT (0U)
/*! enet_ref_clk_sel - clock select */
#define NETC_TCU_TCU_ENET_REF_CLK_SEL_enet_ref_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_ENET_REF_CLK_SEL_enet_ref_clk_sel_SHIFT)) & NETC_TCU_TCU_ENET_REF_CLK_SEL_enet_ref_clk_sel_MASK)
/*! @} */

/*! @name TCU_PLL_COUNTER - tcu pll counter reg */
/*! @{ */

#define NETC_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK (0x1U)
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT (0U)
/*! pll_count_rst_n - pll count reset */
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_rst_n(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT)) & NETC_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK)

#define NETC_TCU_TCU_PLL_COUNTER_pll_count_start_MASK (0x2U)
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT (1U)
/*! pll_count_start - pll count start */
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_start(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT)) & NETC_TCU_TCU_PLL_COUNTER_pll_count_start_MASK)

#define NETC_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK (0x4U)
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT (2U)
/*! pll_count_div_en - pll count div en */
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_div_en(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT)) & NETC_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK)

#define NETC_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK (0x38U)
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT (3U)
/*! pll_count_clk_sel - pll count clk sel */
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT)) & NETC_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK)

#define NETC_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK (0xFF00U)
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT (8U)
/*! pll_count_ref_val - pll count ref val */
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_ref_val(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT)) & NETC_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK)

#define NETC_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK (0xFFFF0000U)
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT (16U)
/*! pll_count_cnt - pll count cnt */
#define NETC_TCU_TCU_PLL_COUNTER_pll_count_cnt(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT)) & NETC_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK)
/*! @} */

/*! @name TCU_DFT_FUSE - observe MIX fuse state and override it */
/*! @{ */

#define NETC_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK (0x1U)
#define NETC_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT (0U)
/*! tcu_dft_fuse_disable - dft fuse disable */
#define NETC_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable(x) (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT)) & NETC_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK)

#define NETC_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_MASK (0x2U)
#define NETC_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_SHIFT (1U)
/*! tcu_fuse_obs_1 - fuse observation */
#define NETC_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1(x)  (((uint32_t)(((uint32_t)(x)) << NETC_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_SHIFT)) & NETC_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NETC_TCU_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_TCU_Peripheral_Access_Layer */


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


#endif  /* NETC_TCU_H_ */

