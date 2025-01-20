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
**         CMSIS Peripheral Access Layer for CAMERA_TCU
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
 * @file CAMERA_TCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for CAMERA_TCU
 *
 * CMSIS Peripheral Access Layer for CAMERA_TCU
 */

#if !defined(CAMERA_TCU_H_)
#define CAMERA_TCU_H_                            /**< Symbol preventing repeated inclusion */

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
   -- CAMERA_TCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_TCU_Peripheral_Access_Layer CAMERA_TCU Peripheral Access Layer
 * @{
 */

/** CAMERA_TCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1024];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW0;           /**< Magic KW0, offset: 0x400 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW1;           /**< Magic KW1, offset: 0x410 */
       uint8_t RESERVED_2[1036];
  __IO uint32_t TCU_PIXEL_SLV_TEST_MODE;           /**< PIXEL LINK slave test mode, offset: 0x820 */
  __IO uint32_t TCU_PIXEL_SLV_TEST_INPUT_;         /**< PIXEL LINK slave test input, offset: 0x824 */
  __I  uint32_t TCU_PIXEL_SLV_TEST_ERROR_BIT;      /**< PIXEL LINK slave test error bits, offset: 0x828 */
       uint8_t RESERVED_3[20];
  __IO uint32_t TCU_DFT_PHY_BURNIN;                /**< Controls PHY burnin test, offset: 0x840 */
       uint8_t RESERVED_4[956];
  __IO uint32_t TCU_PLL_COUNTER;                   /**< tcu pll counter reg, offset: 0xC00 */
       uint8_t RESERVED_5[60];
  __IO uint32_t TCU_DFT_FUSE;                      /**< observe MIX fuse state and override it, offset: 0xC40 */
} CAMERA_TCU_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_TCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_TCU_Register_Masks CAMERA_TCU Register Masks
 * @{
 */

/*! @name TCU_MAGIC_KW__MAGIC_KW0 - Magic KW0 */
/*! @{ */

#define CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK (0xFFFFFFFFU)
#define CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT (0U)
/*! out - 32-Bit Magic KW0 used in conjuction with Magic KW1 to unlock the writes to test mode registers (Value is 0x12345678) */
#define CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW0_out(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT)) & CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK)
/*! @} */

/*! @name TCU_MAGIC_KW__MAGIC_KW1 - Magic KW1 */
/*! @{ */

#define CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK (0xFFFFFFFFU)
#define CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT (0U)
/*! out - 32-Bit Magic KW1 used in conjuction with Magic KW0 to unlock the writes to test mode registers (Value - 0x87654321) */
#define CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW1_out(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT)) & CAMERA_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK)
/*! @} */

/*! @name TCU_PIXEL_SLV_TEST_MODE - PIXEL LINK slave test mode */
/*! @{ */

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_mode_MASK (0x1U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_mode_SHIFT (0U)
/*! pixel_slv0_test_mode - pixel loop test production mode */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_mode(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_mode_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_mode_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_done_MASK (0x2U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_done_SHIFT (1U)
/*! pixel_slv0_test_done - pixel loop test done indication */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_done(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_done_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_done_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_pass_fail_b_MASK (0x4U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_pass_fail_b_SHIFT (2U)
/*! pixel_slv0_test_pass_fail_b - pixel loop test pass/fail indication */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_pass_fail_b(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_pass_fail_b_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv0_test_pass_fail_b_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_mode_MASK (0x8U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_mode_SHIFT (3U)
/*! pixel_slv1_test_mode - pixel loop test production mode */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_mode(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_mode_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_mode_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_done_MASK (0x10U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_done_SHIFT (4U)
/*! pixel_slv1_test_done - pixel loop test done indication */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_done(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_done_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_done_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_pass_fail_b_MASK (0x20U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_pass_fail_b_SHIFT (5U)
/*! pixel_slv1_test_pass_fail_b - pixel loop test pass/fail indication */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_pass_fail_b(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_pass_fail_b_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv1_test_pass_fail_b_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_mode_MASK (0x40U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_mode_SHIFT (6U)
/*! pixel_slv2_test_mode - pixel_slv2_test_mode */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_mode(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_mode_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_mode_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_done_MASK (0x80U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_done_SHIFT (7U)
/*! pixel_slv2_test_done - pixel_slv2_test_done */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_done(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_done_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_done_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_pass_fail_b_MASK (0x100U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_pass_fail_b_SHIFT (8U)
/*! pixel_slv2_test_pass_fail_b - pixel_slv2_test_pass_fail_b */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_pass_fail_b(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_pass_fail_b_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv2_test_pass_fail_b_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_mode_MASK (0x200U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_mode_SHIFT (9U)
/*! pixel_slv3_test_mode - pixel_slv3_test_mode */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_mode(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_mode_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_mode_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_done_MASK (0x400U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_done_SHIFT (10U)
/*! pixel_slv3_test_done - pixel_slv3_test_done */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_done(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_done_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_done_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_pass_fail_b_MASK (0x800U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_pass_fail_b_SHIFT (11U)
/*! pixel_slv3_test_pass_fail_b - pixel_slv3_test_pass_fail_b */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_pass_fail_b(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_pass_fail_b_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv3_test_pass_fail_b_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_start_MASK (0x1000U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_start_SHIFT (12U)
/*! pixel_slv_test_start - PIXEL SLV TEST START */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_start(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_start_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_start_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_load_MASK (0x2000U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_load_SHIFT (13U)
/*! pixel_slv_test_load - PIXEL SLV TEST LOAD */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_load(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_load_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_load_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_error_valid_MASK (0x4000U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_error_valid_SHIFT (14U)
/*! pixel_slv_test_error_valid - pixel loop test error valid */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_error_valid(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_error_valid_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_error_valid_MASK)

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_unpause_MASK (0x8000U)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_unpause_SHIFT (15U)
/*! pixel_slv_test_unpause - To drive pixel_slv_test_unpause signal */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_unpause(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_unpause_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_MODE_pixel_slv_test_unpause_MASK)
/*! @} */

/*! @name TCU_PIXEL_SLV_TEST_INPUT_ - PIXEL LINK slave test input */
/*! @{ */

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_INPUT__pixel_slv_test_input_MASK (0xFFFFFFFFU)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_INPUT__pixel_slv_test_input_SHIFT (0U)
/*! pixel_slv_test_input - pixel link test inputs */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_INPUT__pixel_slv_test_input(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_INPUT__pixel_slv_test_input_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_INPUT__pixel_slv_test_input_MASK)
/*! @} */

/*! @name TCU_PIXEL_SLV_TEST_ERROR_BIT - PIXEL LINK slave test error bits */
/*! @{ */

#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_ERROR_BIT_pixel_slv_test_error_bit_MASK (0xFFFFFFFFU)
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_ERROR_BIT_pixel_slv_test_error_bit_SHIFT (0U)
/*! pixel_slv_test_error_bit - test error bits observation */
#define CAMERA_TCU_TCU_PIXEL_SLV_TEST_ERROR_BIT_pixel_slv_test_error_bit(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PIXEL_SLV_TEST_ERROR_BIT_pixel_slv_test_error_bit_SHIFT)) & CAMERA_TCU_TCU_PIXEL_SLV_TEST_ERROR_BIT_pixel_slv_test_error_bit_MASK)
/*! @} */

/*! @name TCU_DFT_PHY_BURNIN - Controls PHY burnin test */
/*! @{ */

#define CAMERA_TCU_TCU_DFT_PHY_BURNIN_tcu_crr_dft_phy_bi_mon_en_MASK (0x7U)
#define CAMERA_TCU_TCU_DFT_PHY_BURNIN_tcu_crr_dft_phy_bi_mon_en_SHIFT (0U)
/*! tcu_crr_dft_phy_bi_mon_en - Control PHY mux for phy burnin test on the csi_complex */
#define CAMERA_TCU_TCU_DFT_PHY_BURNIN_tcu_crr_dft_phy_bi_mon_en(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_DFT_PHY_BURNIN_tcu_crr_dft_phy_bi_mon_en_SHIFT)) & CAMERA_TCU_TCU_DFT_PHY_BURNIN_tcu_crr_dft_phy_bi_mon_en_MASK)
/*! @} */

/*! @name TCU_PLL_COUNTER - tcu pll counter reg */
/*! @{ */

#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK (0x1U)
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT (0U)
/*! pll_count_rst_n - pll count reset */
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_rst_n(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT)) & CAMERA_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK)

#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_start_MASK (0x2U)
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT (1U)
/*! pll_count_start - pll count start */
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_start(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT)) & CAMERA_TCU_TCU_PLL_COUNTER_pll_count_start_MASK)

#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK (0x4U)
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT (2U)
/*! pll_count_div_en - pll count div en */
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_div_en(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT)) & CAMERA_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK)

#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK (0x38U)
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT (3U)
/*! pll_count_clk_sel - pll count clk sel */
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT)) & CAMERA_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK)

#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK (0xFF00U)
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT (8U)
/*! pll_count_ref_val - pll count ref val */
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_ref_val(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT)) & CAMERA_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK)

#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK (0xFFFF0000U)
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT (16U)
/*! pll_count_cnt - pll count cnt */
#define CAMERA_TCU_TCU_PLL_COUNTER_pll_count_cnt(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT)) & CAMERA_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK)
/*! @} */

/*! @name TCU_DFT_FUSE - observe MIX fuse state and override it */
/*! @{ */

#define CAMERA_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK (0x1U)
#define CAMERA_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT (0U)
/*! tcu_dft_fuse_disable - dft fuse disable */
#define CAMERA_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT)) & CAMERA_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK)

#define CAMERA_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK (0x1EU)
#define CAMERA_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT (1U)
/*! tcu_fuse_obs - fuse observation */
#define CAMERA_TCU_TCU_DFT_FUSE_tcu_fuse_obs(x)  (((uint32_t)(((uint32_t)(x)) << CAMERA_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT)) & CAMERA_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAMERA_TCU_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_TCU_Peripheral_Access_Layer */


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


#endif  /* CAMERA_TCU_H_ */

