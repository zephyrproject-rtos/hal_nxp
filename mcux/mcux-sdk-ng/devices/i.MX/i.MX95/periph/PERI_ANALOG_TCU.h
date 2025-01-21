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
**         CMSIS Peripheral Access Layer for ANALOG_TCU
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
 * @file ANALOG_TCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ANALOG_TCU
 *
 * CMSIS Peripheral Access Layer for ANALOG_TCU
 */

#if !defined(ANALOG_TCU_H_)
#define ANALOG_TCU_H_                            /**< Symbol preventing repeated inclusion */

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
   -- ANALOG_TCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_TCU_Peripheral_Access_Layer ANALOG_TCU Peripheral Access Layer
 * @{
 */

/** ANALOG_TCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1024];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW0;           /**< Magic KW0, offset: 0x400 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TCU_MAGIC_KW__MAGIC_KW1;           /**< Magic KW1, offset: 0x410 */
       uint8_t RESERVED_2[236];
  __I  uint32_t TCU_TEMPSENSER_MODE;               /**< tempsenser expose test mode, offset: 0x500 */
       uint8_t RESERVED_3[60];
  __IO uint32_t TCU_CLK_MUXSEL;                    /**< clock sel, offset: 0x540 */
       uint8_t RESERVED_4[12];
  __IO uint32_t TCU_EXPOSE;                        /**< expose mode enable, offset: 0x550 */
       uint8_t RESERVED_5[60];
  __IO uint32_t TCU_ATX_SENSE_BUS_EN;              /**< ATX sense bus enable, offset: 0x590 */
       uint8_t RESERVED_6[1212];
  struct {                                         /* offset: 0xA50 */
    __IO uint32_t RW;                                /**< ADC control register, offset: 0xA50 */
    __IO uint32_t SET;                               /**< ADC control register, offset: 0xA54 */
    __IO uint32_t CLR;                               /**< ADC control register, offset: 0xA58 */
    __IO uint32_t TOG;                               /**< ADC control register, offset: 0xA5C */
  } TCU_ADC_CONTROL_;
       uint8_t RESERVED_7[416];
  __IO uint32_t TCU_PLL_COUNTER;                   /**< tcu pll counter reg, offset: 0xC00 */
       uint8_t RESERVED_8[60];
  __IO uint32_t TCU_DFT_FUSE;                      /**< observe MIX fuse state and override it, offset: 0xC40 */
} ANALOG_TCU_Type;

/* ----------------------------------------------------------------------------
   -- ANALOG_TCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_TCU_Register_Masks ANALOG_TCU Register Masks
 * @{
 */

/*! @name TCU_MAGIC_KW__MAGIC_KW0 - Magic KW0 */
/*! @{ */

#define ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK (0xFFFFFFFFU)
#define ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT (0U)
/*! out - 32-Bit Magic KW0 used in conjuction with Magic KW1 to unlock the writes to test mode registers (Value is 0x12345678) */
#define ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW0_out(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_SHIFT)) & ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW0_out_MASK)
/*! @} */

/*! @name TCU_MAGIC_KW__MAGIC_KW1 - Magic KW1 */
/*! @{ */

#define ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK (0xFFFFFFFFU)
#define ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT (0U)
/*! out - 32-Bit Magic KW1 used in conjuction with Magic KW0 to unlock the writes to test mode registers (Value - 0x87654321) */
#define ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW1_out(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_SHIFT)) & ANALOG_TCU_TCU_MAGIC_KW__MAGIC_KW1_out_MASK)
/*! @} */

/*! @name TCU_TEMPSENSER_MODE - tempsenser expose test mode */
/*! @{ */

#define ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_data_MASK (0xFFFFU)
#define ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_data_SHIFT (0U)
/*! ipt_temp_data - temperature data observation */
#define ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_data(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_data_SHIFT)) & ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_data_MASK)

#define ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_valid_MASK (0x10000U)
#define ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_valid_SHIFT (16U)
/*! ipt_temp_valid - temperature data valid observation */
#define ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_valid(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_valid_SHIFT)) & ANALOG_TCU_TCU_TEMPSENSER_MODE_ipt_temp_valid_MASK)
/*! @} */

/*! @name TCU_CLK_MUXSEL - clock sel */
/*! @{ */

#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_clk_src_mux_sel_MASK (0xFU)
#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_clk_src_mux_sel_SHIFT (0U)
/*! ipt_clk_src_mux_sel - clock source sel */
#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_clk_src_mux_sel(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_CLK_MUXSEL_ipt_clk_src_mux_sel_SHIFT)) & ANALOG_TCU_TCU_CLK_MUXSEL_ipt_clk_src_mux_sel_MASK)

#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel1_MASK (0x30U)
#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel1_SHIFT (4U)
/*! ipt_osc_clkin_mux_sel1 - osc clkin1 sel */
#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel1(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel1_SHIFT)) & ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel1_MASK)

#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel0_MASK (0xC0U)
#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel0_SHIFT (6U)
/*! ipt_osc_clkin_mux_sel0 - osc clkin0 sel */
#define ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel0(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel0_SHIFT)) & ANALOG_TCU_TCU_CLK_MUXSEL_ipt_osc_clkin_mux_sel0_MASK)
/*! @} */

/*! @name TCU_EXPOSE - expose mode enable */
/*! @{ */

#define ANALOG_TCU_TCU_EXPOSE_tcu_expose_mode_MASK (0x1U)
#define ANALOG_TCU_TCU_EXPOSE_tcu_expose_mode_SHIFT (0U)
/*! tcu_expose_mode - dft fuse disable */
#define ANALOG_TCU_TCU_EXPOSE_tcu_expose_mode(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_EXPOSE_tcu_expose_mode_SHIFT)) & ANALOG_TCU_TCU_EXPOSE_tcu_expose_mode_MASK)
/*! @} */

/*! @name TCU_ATX_SENSE_BUS_EN - ATX sense bus enable */
/*! @{ */

#define ANALOG_TCU_TCU_ATX_SENSE_BUS_EN_tcu_dft_atx_sense_bus_en_MASK (0x1U)
#define ANALOG_TCU_TCU_ATX_SENSE_BUS_EN_tcu_dft_atx_sense_bus_en_SHIFT (0U)
/*! tcu_dft_atx_sense_bus_en - ATX sense bus enable vdd_lv domain */
#define ANALOG_TCU_TCU_ATX_SENSE_BUS_EN_tcu_dft_atx_sense_bus_en(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_ATX_SENSE_BUS_EN_tcu_dft_atx_sense_bus_en_SHIFT)) & ANALOG_TCU_TCU_ATX_SENSE_BUS_EN_tcu_dft_atx_sense_bus_en_MASK)
/*! @} */

/*! @name TCU_ADC_CONTROL_ - ADC control register */
/*! @{ */

#define ANALOG_TCU_TCU_ADC_CONTROL__adc_muxing_en_MASK (0x1U)
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_muxing_en_SHIFT (0U)
/*! adc_muxing_en - ADC exposed mode iomux enable */
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_muxing_en(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_ADC_CONTROL__adc_muxing_en_SHIFT)) & ANALOG_TCU_TCU_ADC_CONTROL__adc_muxing_en_MASK)

#define ANALOG_TCU_TCU_ADC_CONTROL__adc_tst_wren_MASK (0x2U)
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_tst_wren_SHIFT (1U)
/*! adc_tst_wren - test mode register write enable */
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_tst_wren(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_ADC_CONTROL__adc_tst_wren_SHIFT)) & ANALOG_TCU_TCU_ADC_CONTROL__adc_tst_wren_MASK)

#define ANALOG_TCU_TCU_ADC_CONTROL__adc_all_analog_pd_MASK (0x4U)
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_all_analog_pd_SHIFT (2U)
/*! adc_all_analog_pd - Enables Powerdown cntrl by adc_adc_pd */
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_all_analog_pd(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_ADC_CONTROL__adc_all_analog_pd_SHIFT)) & ANALOG_TCU_TCU_ADC_CONTROL__adc_all_analog_pd_MASK)

#define ANALOG_TCU_TCU_ADC_CONTROL__adc_adc_pd_MASK (0x8U)
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_adc_pd_SHIFT (3U)
/*! adc_adc_pd - Used to drive powerdown signal when adc_all_analog_pd is set */
#define ANALOG_TCU_TCU_ADC_CONTROL__adc_adc_pd(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_ADC_CONTROL__adc_adc_pd_SHIFT)) & ANALOG_TCU_TCU_ADC_CONTROL__adc_adc_pd_MASK)
/*! @} */

/*! @name TCU_PLL_COUNTER - tcu pll counter reg */
/*! @{ */

#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK (0x1U)
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT (0U)
/*! pll_count_rst_n - pll count reset */
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_rst_n(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_PLL_COUNTER_pll_count_rst_n_SHIFT)) & ANALOG_TCU_TCU_PLL_COUNTER_pll_count_rst_n_MASK)

#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_start_MASK (0x2U)
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT (1U)
/*! pll_count_start - pll count start */
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_start(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_PLL_COUNTER_pll_count_start_SHIFT)) & ANALOG_TCU_TCU_PLL_COUNTER_pll_count_start_MASK)

#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK (0x4U)
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT (2U)
/*! pll_count_div_en - pll count div en */
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_div_en(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_PLL_COUNTER_pll_count_div_en_SHIFT)) & ANALOG_TCU_TCU_PLL_COUNTER_pll_count_div_en_MASK)

#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK (0x38U)
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT (3U)
/*! pll_count_clk_sel - pll count clk sel */
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_SHIFT)) & ANALOG_TCU_TCU_PLL_COUNTER_pll_count_clk_sel_MASK)

#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK (0xFF00U)
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT (8U)
/*! pll_count_ref_val - pll count ref val */
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_ref_val(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_PLL_COUNTER_pll_count_ref_val_SHIFT)) & ANALOG_TCU_TCU_PLL_COUNTER_pll_count_ref_val_MASK)

#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK (0xFFFF0000U)
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT (16U)
/*! pll_count_cnt - pll count cnt */
#define ANALOG_TCU_TCU_PLL_COUNTER_pll_count_cnt(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_PLL_COUNTER_pll_count_cnt_SHIFT)) & ANALOG_TCU_TCU_PLL_COUNTER_pll_count_cnt_MASK)
/*! @} */

/*! @name TCU_DFT_FUSE - observe MIX fuse state and override it */
/*! @{ */

#define ANALOG_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK (0x1U)
#define ANALOG_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT (0U)
/*! tcu_dft_fuse_disable - dft fuse disable */
#define ANALOG_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_SHIFT)) & ANALOG_TCU_TCU_DFT_FUSE_tcu_dft_fuse_disable_MASK)

#define ANALOG_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK (0xEU)
#define ANALOG_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT (1U)
/*! tcu_fuse_obs - fuse observation */
#define ANALOG_TCU_TCU_DFT_FUSE_tcu_fuse_obs(x)  (((uint32_t)(((uint32_t)(x)) << ANALOG_TCU_TCU_DFT_FUSE_tcu_fuse_obs_SHIFT)) & ANALOG_TCU_TCU_DFT_FUSE_tcu_fuse_obs_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANALOG_TCU_Register_Masks */


/*!
 * @}
 */ /* end of group ANALOG_TCU_Peripheral_Access_Layer */


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


#endif  /* ANALOG_TCU_H_ */

