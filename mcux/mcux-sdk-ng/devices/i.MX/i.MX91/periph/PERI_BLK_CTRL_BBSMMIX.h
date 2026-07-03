/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_BBSMMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_BBSMMIX.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_BBSMMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_BBSMMIX
 */

#if !defined(PERI_BLK_CTRL_BBSMMIX_H_)
#define PERI_BLK_CTRL_BBSMMIX_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- BLK_CTRL_BBSMMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_BBSMMIX_Peripheral_Access_Layer BLK_CTRL_BBSMMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_BBSMMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t SXOSC_CTRL;                        /**< SXOSC Control Register, offset: 0x0 */
  __IO uint32_t SNVS_CLKRST_CTRL;                  /**< snvs_clkrst Control Register, offset: 0x4 */
} BLK_CTRL_BBSMMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_BBSMMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_BBSMMIX_Register_Masks BLK_CTRL_BBSMMIX Register Masks
 * @{
 */

/*! @name SXOSC_CTRL - SXOSC Control Register */
/*! @{ */

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_cosc_en_lv_MASK (0x1U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_cosc_en_lv_SHIFT (0U)
/*! cosc_en_lv - Software Reset
 *  0b0..No reset
 *  0b1..Reset
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_cosc_en_lv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_cosc_en_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_cosc_en_lv_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_cur_prg_MASK (0xEU)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_cur_prg_SHIFT (1U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_cur_prg(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_cur_prg_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_cur_prg_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_sel_lv_MASK (0x70U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_sel_lv_SHIFT (4U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_sel_lv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_sel_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_sel_lv_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_test_sel_lv_MASK (0x80U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_test_sel_lv_SHIFT (7U)
/*! gm_test_sel_lv - Enables gm testing in bench */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_test_sel_lv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_test_sel_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_gm_test_sel_lv_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl0_in_lv_MASK (0x100U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl0_in_lv_SHIFT (8U)
/*! misc_ctrl0_in_lv - Miscellaneous control input */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl0_in_lv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl0_in_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl0_in_lv_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl1_in_lv_MASK (0x200U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl1_in_lv_SHIFT (9U)
/*! misc_ctrl1_in_lv - Miscellaneous control input */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl1_in_lv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl1_in_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_ctrl1_in_lv_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test0_in_lv_MASK (0x400U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test0_in_lv_SHIFT (10U)
/*! misc_test0_in_lv - Miscellaneous test input */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test0_in_lv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test0_in_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test0_in_lv_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test1_in_lv_MASK (0x800U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test1_in_lv_SHIFT (11U)
/*! misc_test1_in_lv - Miscellaneous test input */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test1_in_lv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test1_in_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_misc_test1_in_lv_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_en_MASK (0x1000U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_en_SHIFT (12U)
/*! osc_test_mux_en - osc test mux input */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_en_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_en_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_sel_MASK (0xE000U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_sel_SHIFT (13U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_sel_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_osc_test_mux_sel_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_MASK  (0x10000U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_SHIFT (16U)
/*! pwd_lv - Power down/enable signal */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_MASK)
/*! @} */

/*! @name SNVS_CLKRST_CTRL - snvs_clkrst Control Register */
/*! @{ */

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_clk_trim_MASK (0xFU)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_clk_trim_SHIFT (0U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_clk_trim(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_clk_trim_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_clk_trim_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_MASK (0xF0U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_SHIFT (4U)
/*! test_sel - test select inputs */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_enb_MASK (0x100U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_enb_SHIFT (8U)
/*! vreg_enb - SNVS core regulator control */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_enb(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_enb_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_enb_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_trim_MASK (0x1E00U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_trim_SHIFT (9U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_trim(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_trim_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_vreg_trim_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_MASK (0x2000U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_SHIFT (13U)
/*! tst_xtal_fast - indicates fast external xtal crystal */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_MASK (0x4000U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_SHIFT (14U)
/*! tst_xtal_slow - indicates slow external xtal crystal */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_MASK (0x8000U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_SHIFT (15U)
/*! xtal_ok - indicates xtal clock is in freq range and source of 32KHz clock */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_BBSMMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_BBSMMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_BBSMMIX_H_ */
