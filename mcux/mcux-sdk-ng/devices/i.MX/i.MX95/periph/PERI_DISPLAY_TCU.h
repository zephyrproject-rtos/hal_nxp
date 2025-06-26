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
**         CMSIS Peripheral Access Layer for DISPLAY_TCU
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
 * @file DISPLAY_TCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DISPLAY_TCU
 *
 * CMSIS Peripheral Access Layer for DISPLAY_TCU
 */

#if !defined(DISPLAY_TCU_H_)
#define DISPLAY_TCU_H_                           /**< Symbol preventing repeated inclusion */

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
   -- DISPLAY_TCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_TCU_Peripheral_Access_Layer DISPLAY_TCU Peripheral Access Layer
 * @{
 */

/** DISPLAY_TCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1024];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW0;           /**< Magic KW0, offset: 0x400 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW1;           /**< Magic KW1, offset: 0x410 */
       uint8_t RESERVED_2[1020];
  __IO uint32_t TCU_PIXEL_MST_TEST_MODE;           /**< PIXEL LINK master test mode, offset: 0x810 */
  __IO uint32_t TCU_PIXEL_MST_TEST_INPUT_;         /**< PIXEL LINK master test input, offset: 0x814 */
       uint8_t RESERVED_3[1000];
  __IO uint32_t TCU_PLL_COUNTER;                   /**< tcu pll counter reg, offset: 0xC00 */
       uint8_t RESERVED_4[60];
  __IO uint32_t TCU_DFT_FUSE;                      /**< observe MIX fuse state and override it, offset: 0xC40 */
} DISPLAY_TCU_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_TCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_TCU_Register_Masks DISPLAY_TCU Register Masks
 * @{
 */

/*! @name TCU_MAGIC_KW__MAGIC_KW0 - Magic KW0 */
/*! @{ */

#define DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK (0xFFFFFFFFU)
#define DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT (0U)
/*! out - 32-Bit Magic KW0 used in conjuction with Magic KW1 to unlock the writes to test mode registers (Value is 0x12345678) */
#define DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW0_out(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT)) & DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK)
/*! @} */

/*! @name TCU_MAGIC_KW__MAGIC_KW1 - Magic KW1 */
/*! @{ */

#define DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK (0xFFFFFFFFU)
#define DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT (0U)
/*! out - 32-Bit Magic KW1 used in conjuction with Magic KW0 to unlock the writes to test mode registers (Value - 0x87654321) */
#define DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW1_out(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT)) & DISPLAY_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK)
/*! @} */

/*! @name TCU_PIXEL_MST_TEST_MODE - PIXEL LINK master test mode */
/*! @{ */

#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst0_test_mode_MASK (0x1U)
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst0_test_mode_SHIFT (0U)
/*! pixel_mst0_test_mode - pixel loop test production mode */
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst0_test_mode(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst0_test_mode_SHIFT)) & DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst0_test_mode_MASK)

#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst1_test_mode_MASK (0x2U)
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst1_test_mode_SHIFT (1U)
/*! pixel_mst1_test_mode - pixel loop test production mode */
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst1_test_mode(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst1_test_mode_SHIFT)) & DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst1_test_mode_MASK)

#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_start_MASK (0x4U)
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_start_SHIFT (2U)
/*! pixel_mst_test_start - pixel link test start */
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_start(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_start_SHIFT)) & DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_start_MASK)

#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_load_MASK (0x8U)
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_load_SHIFT (3U)
/*! pixel_mst_test_load - pixel link test load */
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_load(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_load_SHIFT)) & DISPLAY_TCU_TCU_PIXEL_MST_TEST_MODE_pixel_mst_test_load_MASK)
/*! @} */

/*! @name TCU_PIXEL_MST_TEST_INPUT_ - PIXEL LINK master test input */
/*! @{ */

#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_INPUT__pixel_mst_test_input_MASK (0xFFFFFFFFU)
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_INPUT__pixel_mst_test_input_SHIFT (0U)
/*! pixel_mst_test_input - pixel link test inputs */
#define DISPLAY_TCU_TCU_PIXEL_MST_TEST_INPUT__pixel_mst_test_input(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PIXEL_MST_TEST_INPUT__pixel_mst_test_input_SHIFT)) & DISPLAY_TCU_TCU_PIXEL_MST_TEST_INPUT__pixel_mst_test_input_MASK)
/*! @} */

/*! @name TCU_PLL_COUNTER - tcu pll counter reg */
/*! @{ */

#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK (0x1U)
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT (0U)
/*! pll_count_rst_n - pll count reset */
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_rst_n(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT)) & DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK)

#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_start_MASK (0x2U)
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT (1U)
/*! pll_count_start - pll count start */
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_start(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT)) & DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_start_MASK)

#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK (0x4U)
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT (2U)
/*! pll_count_div_en - pll count div en */
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_div_en(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT)) & DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK)

#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK (0x38U)
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT (3U)
/*! pll_count_clk_sel - pll count clk sel */
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT)) & DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK)

#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK (0xFF00U)
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT (8U)
/*! pll_count_ref_val - pll count ref val */
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_ref_val(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT)) & DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK)

#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK (0xFFFF0000U)
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT (16U)
/*! pll_count_cnt - pll count cnt */
#define DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_cnt(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT)) & DISPLAY_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK)
/*! @} */

/*! @name TCU_DFT_FUSE - observe MIX fuse state and override it */
/*! @{ */

#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK (0x1U)
#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT (0U)
/*! tcu_dft_fuse_disable - dft fuse disable */
#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT)) & DISPLAY_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK)

#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_MASK (0x2U)
#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_SHIFT (1U)
/*! tcu_fuse_obs_1 - fuse observation */
#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_SHIFT)) & DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_1_MASK)

#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_2_MASK (0x4U)
#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_2_SHIFT (2U)
/*! tcu_fuse_obs_2 - fuse observation */
#define DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_2_SHIFT)) & DISPLAY_TCU_TCU_DFT_FUSE_tcu_fuse_obs_2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_TCU_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_TCU_Peripheral_Access_Layer */


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


#endif  /* DISPLAY_TCU_H_ */

