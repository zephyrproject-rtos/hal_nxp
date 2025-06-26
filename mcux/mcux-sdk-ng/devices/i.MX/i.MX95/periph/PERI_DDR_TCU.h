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
**         CMSIS Peripheral Access Layer for DDR_TCU
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
 * @file DDR_TCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DDR_TCU
 *
 * CMSIS Peripheral Access Layer for DDR_TCU
 */

#if !defined(DDR_TCU_H_)
#define DDR_TCU_H_                               /**< Symbol preventing repeated inclusion */

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
   -- DDR_TCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_TCU_Peripheral_Access_Layer DDR_TCU Peripheral Access Layer
 * @{
 */

/** DDR_TCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1024];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW0;           /**< Magic KW0, offset: 0x400 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW1;           /**< Magic KW1, offset: 0x410 */
       uint8_t RESERVED_2[332];
  __IO uint32_t TCU_DFT_DIVIDER;                   /**< clk divider bypass control, offset: 0x560 */
       uint8_t RESERVED_3[28];
  __IO uint32_t TCU_DFT_PHY;                       /**< CRR control on TxBypassOE, offset: 0x580 */
       uint8_t RESERVED_4[1532];
  struct {                                         /* offset: 0xB80 */
    __IO uint32_t RW;                                /**< TCU DDR BSR control register, offset: 0xB80 */
    __IO uint32_t SET;                               /**< TCU DDR BSR control register, offset: 0xB84 */
    __IO uint32_t CLR;                               /**< TCU DDR BSR control register, offset: 0xB88 */
    __IO uint32_t TOG;                               /**< TCU DDR BSR control register, offset: 0xB8C */
  } TCU_DDR_BSR_CONTROL_;
       uint8_t RESERVED_5[112];
  __IO uint32_t TCU_PLL_COUNTER;                   /**< tcu pll counter reg, offset: 0xC00 */
       uint8_t RESERVED_6[60];
  __IO uint32_t TCU_DFT_FUSE;                      /**< observe MIX fuse state and override it, offset: 0xC40 */
} DDR_TCU_Type;

/* ----------------------------------------------------------------------------
   -- DDR_TCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_TCU_Register_Masks DDR_TCU Register Masks
 * @{
 */

/*! @name TCU_MAGIC_KW__MAGIC_KW0 - Magic KW0 */
/*! @{ */

#define DDR_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK (0xFFFFFFFFU)
#define DDR_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT (0U)
/*! out - 32-Bit Magic KW0 used in conjuction with Magic KW1 to unlock the writes to test mode registers (Value is 0x12345678) */
#define DDR_TCU_TCU_MAGIC_KW__MAGIC_KW0_out(x)   (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT)) & DDR_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK)
/*! @} */

/*! @name TCU_MAGIC_KW__MAGIC_KW1 - Magic KW1 */
/*! @{ */

#define DDR_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK (0xFFFFFFFFU)
#define DDR_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT (0U)
/*! out - 32-Bit Magic KW1 used in conjuction with Magic KW0 to unlock the writes to test mode registers (Value - 0x87654321) */
#define DDR_TCU_TCU_MAGIC_KW__MAGIC_KW1_out(x)   (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT)) & DDR_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK)
/*! @} */

/*! @name TCU_DFT_DIVIDER - clk divider bypass control */
/*! @{ */

#define DDR_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_MASK (0x1U)
#define DDR_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_SHIFT (0U)
/*! tcu_dft_divider_disable - dft divider disable */
#define DDR_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_SHIFT)) & DDR_TCU_TCU_DFT_DIVIDER_tcu_dft_divider_disable_MASK)
/*! @} */

/*! @name TCU_DFT_PHY - CRR control on TxBypassOE */
/*! @{ */

#define DDR_TCU_TCU_DFT_PHY_tcu_crr_txbypassoe_MASK (0x1U)
#define DDR_TCU_TCU_DFT_PHY_tcu_crr_txbypassoe_SHIFT (0U)
/*! tcu_crr_txbypassoe - dft fuse disable */
#define DDR_TCU_TCU_DFT_PHY_tcu_crr_txbypassoe(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_DFT_PHY_tcu_crr_txbypassoe_SHIFT)) & DDR_TCU_TCU_DFT_PHY_tcu_crr_txbypassoe_MASK)
/*! @} */

/*! @name TCU_DDR_BSR_CONTROL_ - TCU DDR BSR control register */
/*! @{ */

#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_mode_en_MASK (0x1U)
#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_mode_en_SHIFT (0U)
/*! ddr_io_bypass_mode_en - ddr_io_bypass_mode_en */
#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_mode_en(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_mode_en_SHIFT)) & DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_mode_en_MASK)

#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_en_MASK (0x2U)
#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_en_SHIFT (1U)
/*! ddr_io_bypass_out_en - ddr_io_bypass_out_en */
#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_en(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_en_SHIFT)) & DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_en_MASK)

#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_data_MASK (0x4U)
#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_data_SHIFT (2U)
/*! ddr_io_bypass_out_data - ddr_io_bypass_out_data */
#define DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_data(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_data_SHIFT)) & DDR_TCU_TCU_DDR_BSR_CONTROL__ddr_io_bypass_out_data_MASK)
/*! @} */

/*! @name TCU_PLL_COUNTER - tcu pll counter reg */
/*! @{ */

#define DDR_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK (0x1U)
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT (0U)
/*! pll_count_rst_n - pll count reset */
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_rst_n(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT)) & DDR_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK)

#define DDR_TCU_TCU_PLL_COUNTER_pll_count_start_MASK (0x2U)
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT (1U)
/*! pll_count_start - pll count start */
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_start(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT)) & DDR_TCU_TCU_PLL_COUNTER_pll_count_start_MASK)

#define DDR_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK (0x4U)
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT (2U)
/*! pll_count_div_en - pll count div en */
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_div_en(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT)) & DDR_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK)

#define DDR_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK (0x38U)
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT (3U)
/*! pll_count_clk_sel - pll count clk sel */
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT)) & DDR_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK)

#define DDR_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK (0xFF00U)
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT (8U)
/*! pll_count_ref_val - pll count ref val */
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_ref_val(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT)) & DDR_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK)

#define DDR_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK (0xFFFF0000U)
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT (16U)
/*! pll_count_cnt - pll count cnt */
#define DDR_TCU_TCU_PLL_COUNTER_pll_count_cnt(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT)) & DDR_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK)
/*! @} */

/*! @name TCU_DFT_FUSE - observe MIX fuse state and override it */
/*! @{ */

#define DDR_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK (0x1U)
#define DDR_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT (0U)
/*! tcu_dft_fuse_disable - dft fuse disable */
#define DDR_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable(x) (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT)) & DDR_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK)

#define DDR_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK   (0x6U)
#define DDR_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT  (1U)
/*! tcu_fuse_obs - fuse observation */
#define DDR_TCU_TCU_DFT_FUSE_tcu_fuse_obs(x)     (((uint32_t)(((uint32_t)(x)) << DDR_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT)) & DDR_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DDR_TCU_Register_Masks */


/*!
 * @}
 */ /* end of group DDR_TCU_Peripheral_Access_Layer */


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


#endif  /* DDR_TCU_H_ */

