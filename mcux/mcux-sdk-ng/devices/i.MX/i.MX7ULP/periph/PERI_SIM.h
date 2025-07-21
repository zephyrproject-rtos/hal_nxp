/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SIM.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(PERI_SIM_H_)
#define PERI_SIM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SOPT1;                             /**< SIM Systems Options Register 1, offset: 0x0 */
  __IO uint32_t SOPT1CFG;                          /**< SIM SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t HSIC_CAL;                          /**< HW SIM HSIC CAL Register, offset: 0xC */
       uint8_t RESERVED_1[24];
  __IO uint32_t SNVS_MISC_CTRL;                    /**< SNVS Misc Control Register, offset: 0x28 */
  __IO uint32_t GPR0;                              /**< HW SIM General Purpose Register 0, offset: 0x2C */
  __IO uint32_t GPR1;                              /**< HW SIM General Purpose Register 1, offset: 0x30 */
       uint32_t GPR2;                              /**< HW SIM General Purpose Register 2, offset: 0x34 */
       uint32_t GPR3;                              /**< HW SIM General Purpose Register 3, offset: 0x38 */
  __IO uint32_t MISC_CTRL0;                        /**< HW SIM MISC Register 0, offset: 0x3C */
       uint8_t RESERVED_2[16];
  __IO uint32_t SIM_DGO_CTRL0;                     /**< SIM DGO Control Register 0, offset: 0x50 */
  __IO uint32_t SIM_DGO_CTRL1;                     /**< SIM DGO Control Register 1, offset: 0x54 */
  __IO uint32_t SIM_DGO_GP1;                       /**< SIM DGO General Purpose Register 1, offset: 0x58 */
  __IO uint32_t SIM_DGO_GP2;                       /**< SIM DGO general Purpose Register 2, offset: 0x5C */
  __IO uint32_t SIM_DGO_GP3;                       /**< SIM DGO General Purpose Register 3, offset: 0x60 */
  __IO uint32_t SIM_DGO_GP4;                       /**< SIM DGO General Purpose Register 4, offset: 0x64 */
  __IO uint32_t SIM_DGO_GP5;                       /**< SIM DGO General Purpose Register 5, offset: 0x68 */
  __IO uint32_t SIM_DGO_GP6;                       /**< SIM DGO General Purpose Register 6, offset: 0x6C */
  __IO uint32_t SIM_DGO_GP7;                       /**< SIM DGO General Purpose Register 7, offset: 0x70 */
  __IO uint32_t SIM_DGO_GP8;                       /**< SIM DGO General Purpose Register 8, offset: 0x74 */
  __IO uint32_t SIM_DGO_GP9;                       /**< SIM DGO General Purpose Register 9, offset: 0x78 */
  __IO uint32_t SIM_DGO_GP10;                      /**< SIM DGO General Purpose Register 10, offset: 0x7C */
  __IO uint32_t SIM_DGO_GP11;                      /**< SIM DGO General Purpose Register 11, offset: 0x80 */
       uint8_t RESERVED_3[4];
  __IO uint32_t WKPU_WAKEUP_EN;                    /**< WKPU Wake-up Enable, offset: 0x88 */
  __I  uint32_t JTAG_ID_REG;                       /**< Mirror of JTAG ID Register, offset: 0x8C */
  __IO uint32_t A7_TSTMR_CMP_VAL_L;                /**< Lower A7 TS Timer compare value, offset: 0x90 */
  __IO uint32_t A7_TSTMR_CMP_VAL_H;                /**< Upper A7 TS Timer compare value, offset: 0x94 */
  __IO uint32_t COMP_CELL_OVERRIDE;                /**< Override Control for Compensation Codes, offset: 0x98 */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name SOPT1 - SIM Systems Options Register 1 */
/*! @{ */

#define SIM_SOPT1_A7_SW_RESET_MASK               (0x1U)
#define SIM_SOPT1_A7_SW_RESET_SHIFT              (0U)
/*! A7_SW_RESET - SW reset for A7 domain. */
#define SIM_SOPT1_A7_SW_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_A7_SW_RESET_SHIFT)) & SIM_SOPT1_A7_SW_RESET_MASK)

#define SIM_SOPT1_PMIC_STBY_REQ_MASK             (0x4U)
#define SIM_SOPT1_PMIC_STBY_REQ_SHIFT            (2U)
/*! PMIC_STBY_REQ - PMIC Standby Request. */
#define SIM_SOPT1_PMIC_STBY_REQ(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_PMIC_STBY_REQ_SHIFT)) & SIM_SOPT1_PMIC_STBY_REQ_MASK)

#define SIM_SOPT1_MIPI_ISO_DISABLE_MASK          (0x8U)
#define SIM_SOPT1_MIPI_ISO_DISABLE_SHIFT         (3U)
/*! MIPI_ISO_DISABLE - MIPI Isolation Disable. */
#define SIM_SOPT1_MIPI_ISO_DISABLE(x)            (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_MIPI_ISO_DISABLE_SHIFT)) & SIM_SOPT1_MIPI_ISO_DISABLE_MASK)

#define SIM_SOPT1_M4_FPU_DISABLE_MASK            (0x20U)
#define SIM_SOPT1_M4_FPU_DISABLE_SHIFT           (5U)
/*! M4_FPU_DISABLE - Disables M4 FPU unit. */
#define SIM_SOPT1_M4_FPU_DISABLE(x)              (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_M4_FPU_DISABLE_SHIFT)) & SIM_SOPT1_M4_FPU_DISABLE_MASK)

#define SIM_SOPT1_M4_MPU_DISABLE_MASK            (0x40U)
#define SIM_SOPT1_M4_MPU_DISABLE_SHIFT           (6U)
/*! M4_MPU_DISABLE - Disables M4 MPU unit. */
#define SIM_SOPT1_M4_MPU_DISABLE(x)              (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_M4_MPU_DISABLE_SHIFT)) & SIM_SOPT1_M4_MPU_DISABLE_MASK)

#define SIM_SOPT1_EN_SNVS_HARD_RST_MASK          (0x100U)
#define SIM_SOPT1_EN_SNVS_HARD_RST_SHIFT         (8U)
/*! EN_SNVS_HARD_RST - SNVS_HP system reset enable (Write Once). */
#define SIM_SOPT1_EN_SNVS_HARD_RST(x)            (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_EN_SNVS_HARD_RST_SHIFT)) & SIM_SOPT1_EN_SNVS_HARD_RST_MASK)

#define SIM_SOPT1_EN_WDG2_HARD_RST_MASK          (0x200U)
#define SIM_SOPT1_EN_WDG2_HARD_RST_SHIFT         (9U)
/*! EN_WDG2_HARD_RST - Watchdog 2 Reset Enable. */
#define SIM_SOPT1_EN_WDG2_HARD_RST(x)            (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_EN_WDG2_HARD_RST_SHIFT)) & SIM_SOPT1_EN_WDG2_HARD_RST_MASK)
/*! @} */

/*! @name SOPT1CFG - SIM SOPT1 Configuration Register */
/*! @{ */

#define SIM_SOPT1CFG_MASK_DPM_PANIC_OUT_MASK     (0x1U)
#define SIM_SOPT1CFG_MASK_DPM_PANIC_OUT_SHIFT    (0U)
/*! MASK_DPM_PANIC_OUT - DPM Panic Out Mask (Write Once). */
#define SIM_SOPT1CFG_MASK_DPM_PANIC_OUT(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_MASK_DPM_PANIC_OUT_SHIFT)) & SIM_SOPT1CFG_MASK_DPM_PANIC_OUT_MASK)

#define SIM_SOPT1CFG_MASK_DPM_PANIC_IN_MASK      (0x2U)
#define SIM_SOPT1CFG_MASK_DPM_PANIC_IN_SHIFT     (1U)
/*! MASK_DPM_PANIC_IN - DPM Panic In Mask (Write Once). */
#define SIM_SOPT1CFG_MASK_DPM_PANIC_IN(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_MASK_DPM_PANIC_IN_SHIFT)) & SIM_SOPT1CFG_MASK_DPM_PANIC_IN_MASK)

#define SIM_SOPT1CFG_DSI_PLL_EN_MASK             (0x80U)
#define SIM_SOPT1CFG_DSI_PLL_EN_SHIFT            (7U)
/*! DSI_PLL_EN - DSI PLL Enable. */
#define SIM_SOPT1CFG_DSI_PLL_EN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_DSI_PLL_EN_SHIFT)) & SIM_SOPT1CFG_DSI_PLL_EN_MASK)

#define SIM_SOPT1CFG_DSI_CM_MASK                 (0x100U)
#define SIM_SOPT1CFG_DSI_CM_SHIFT                (8U)
/*! DSI_CM - DSI Color Mode Control. */
#define SIM_SOPT1CFG_DSI_CM(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_DSI_CM_SHIFT)) & SIM_SOPT1CFG_DSI_CM_MASK)

#define SIM_SOPT1CFG_DSI_SD_MASK                 (0x200U)
#define SIM_SOPT1CFG_DSI_SD_SHIFT                (9U)
/*! DSI_SD - DSI Shutdown Control. */
#define SIM_SOPT1CFG_DSI_SD(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_DSI_SD_SHIFT)) & SIM_SOPT1CFG_DSI_SD_MASK)

#define SIM_SOPT1CFG_QSPI_PULL_TIM_RELAX_B_MASK  (0x400U)
#define SIM_SOPT1CFG_QSPI_PULL_TIM_RELAX_B_SHIFT (10U)
/*! QSPI_PULL_TIM_RELAX_b - QSPI OBE Assertion Control. */
#define SIM_SOPT1CFG_QSPI_PULL_TIM_RELAX_B(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_QSPI_PULL_TIM_RELAX_B_SHIFT)) & SIM_SOPT1CFG_QSPI_PULL_TIM_RELAX_B_MASK)

#define SIM_SOPT1CFG_DSI_RST_BYTE_N_MASK         (0x20000000U)
#define SIM_SOPT1CFG_DSI_RST_BYTE_N_SHIFT        (29U)
/*! DSI_RST_BYTE_N - DSI Reset Byte Control. */
#define SIM_SOPT1CFG_DSI_RST_BYTE_N(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_DSI_RST_BYTE_N_SHIFT)) & SIM_SOPT1CFG_DSI_RST_BYTE_N_MASK)

#define SIM_SOPT1CFG_DSI_RST_ESC_N_MASK          (0x40000000U)
#define SIM_SOPT1CFG_DSI_RST_ESC_N_SHIFT         (30U)
/*! DSI_RST_ESC_N - DSI Reset Escape Control. */
#define SIM_SOPT1CFG_DSI_RST_ESC_N(x)            (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_DSI_RST_ESC_N_SHIFT)) & SIM_SOPT1CFG_DSI_RST_ESC_N_MASK)

#define SIM_SOPT1CFG_DSI_RST_DPI_N_MASK          (0x80000000U)
#define SIM_SOPT1CFG_DSI_RST_DPI_N_SHIFT         (31U)
/*! DSI_RST_DPI_N - DSI Reset DPI Control. */
#define SIM_SOPT1CFG_DSI_RST_DPI_N(x)            (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_DSI_RST_DPI_N_SHIFT)) & SIM_SOPT1CFG_DSI_RST_DPI_N_MASK)
/*! @} */

/*! @name HSIC_CAL - HW SIM HSIC CAL Register */
/*! @{ */

#define SIM_HSIC_CAL_HSIC_ZQ_VOH_MASK            (0x1FU)
#define SIM_HSIC_CAL_HSIC_ZQ_VOH_SHIFT           (0U)
/*! HSIC_ZQ_VOH - HSIC ZQ pull-up resistance. */
#define SIM_HSIC_CAL_HSIC_ZQ_VOH(x)              (((uint32_t)(((uint32_t)(x)) << SIM_HSIC_CAL_HSIC_ZQ_VOH_SHIFT)) & SIM_HSIC_CAL_HSIC_ZQ_VOH_MASK)

#define SIM_HSIC_CAL_HSIC_ZQ_COMPARE_MASK        (0x20U)
#define SIM_HSIC_CAL_HSIC_ZQ_COMPARE_SHIFT       (5U)
/*! HSIC_ZQ_COMPARE - HSIC ZQ Compare. */
#define SIM_HSIC_CAL_HSIC_ZQ_COMPARE(x)          (((uint32_t)(((uint32_t)(x)) << SIM_HSIC_CAL_HSIC_ZQ_COMPARE_SHIFT)) & SIM_HSIC_CAL_HSIC_ZQ_COMPARE_MASK)

#define SIM_HSIC_CAL_HSIC_ZQ_CAL_EN_MASK         (0x80U)
#define SIM_HSIC_CAL_HSIC_ZQ_CAL_EN_SHIFT        (7U)
/*! HSIC_ZQ_CAL_EN - HSIC ZQ compare enable. */
#define SIM_HSIC_CAL_HSIC_ZQ_CAL_EN(x)           (((uint32_t)(((uint32_t)(x)) << SIM_HSIC_CAL_HSIC_ZQ_CAL_EN_SHIFT)) & SIM_HSIC_CAL_HSIC_ZQ_CAL_EN_MASK)

#define SIM_HSIC_CAL_HSIC_ZQ_VOH_M1_MASK         (0x1F00U)
#define SIM_HSIC_CAL_HSIC_ZQ_VOH_M1_SHIFT        (8U)
/*! HSIC_ZQ_VOH_M1 - HSIC ZQ pull-up resistance incremented. */
#define SIM_HSIC_CAL_HSIC_ZQ_VOH_M1(x)           (((uint32_t)(((uint32_t)(x)) << SIM_HSIC_CAL_HSIC_ZQ_VOH_M1_SHIFT)) & SIM_HSIC_CAL_HSIC_ZQ_VOH_M1_MASK)

#define SIM_HSIC_CAL_HSIC_ZQ_VOL_MASK            (0x1F0000U)
#define SIM_HSIC_CAL_HSIC_ZQ_VOL_SHIFT           (16U)
/*! HSIC_ZQ_VOL - HSIC ZQ pull-down resistance. */
#define SIM_HSIC_CAL_HSIC_ZQ_VOL(x)              (((uint32_t)(((uint32_t)(x)) << SIM_HSIC_CAL_HSIC_ZQ_VOL_SHIFT)) & SIM_HSIC_CAL_HSIC_ZQ_VOL_MASK)

#define SIM_HSIC_CAL_HSIC_ZQ_VOL_M1_MASK         (0x1F000000U)
#define SIM_HSIC_CAL_HSIC_ZQ_VOL_M1_SHIFT        (24U)
/*! HSIC_ZQ_VOL_M1 - HSIC ZQ pull-down resistance incremented. */
#define SIM_HSIC_CAL_HSIC_ZQ_VOL_M1(x)           (((uint32_t)(((uint32_t)(x)) << SIM_HSIC_CAL_HSIC_ZQ_VOL_M1_SHIFT)) & SIM_HSIC_CAL_HSIC_ZQ_VOL_M1_MASK)
/*! @} */

/*! @name SNVS_MISC_CTRL - SNVS Misc Control Register */
/*! @{ */

#define SIM_SNVS_MISC_CTRL_OSC_CAP_TRIM_MASK     (0xFU)
#define SIM_SNVS_MISC_CTRL_OSC_CAP_TRIM_SHIFT    (0U)
/*! OSC_CAP_TRIM - Trims to control the CAP on 32K Oscillator. */
#define SIM_SNVS_MISC_CTRL_OSC_CAP_TRIM(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SNVS_MISC_CTRL_OSC_CAP_TRIM_SHIFT)) & SIM_SNVS_MISC_CTRL_OSC_CAP_TRIM_MASK)

#define SIM_SNVS_MISC_CTRL_COIN_CELL_CHARGE_EN_MASK (0x80000000U)
#define SIM_SNVS_MISC_CTRL_COIN_CELL_CHARGE_EN_SHIFT (31U)
/*! COIN_CELL_CHARGE_EN - Enables Signal Isolation on SNVS Software Trims and Pull controls
 *    (PUS/PUE) until the software writes "1" to this register field. This ensures trim values are held
 *    until registers get updated by software after boot up.
 */
#define SIM_SNVS_MISC_CTRL_COIN_CELL_CHARGE_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_SNVS_MISC_CTRL_COIN_CELL_CHARGE_EN_SHIFT)) & SIM_SNVS_MISC_CTRL_COIN_CELL_CHARGE_EN_MASK)
/*! @} */

/*! @name GPR0 - HW SIM General Purpose Register 0 */
/*! @{ */

#define SIM_GPR0_MTR_CLK_DIS_MASK                (0x1U)
#define SIM_GPR0_MTR_CLK_DIS_SHIFT               (0U)
/*! MTR_CLK_DIS - MBIST clocks disable. */
#define SIM_GPR0_MTR_CLK_DIS(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_GPR0_MTR_CLK_DIS_SHIFT)) & SIM_GPR0_MTR_CLK_DIS_MASK)

#define SIM_GPR0_OCOTP_CLK_DIS_MASK              (0x2U)
#define SIM_GPR0_OCOTP_CLK_DIS_SHIFT             (1U)
/*! OCOTP_CLK_DIS - OCOTP clocks disable. */
#define SIM_GPR0_OCOTP_CLK_DIS(x)                (((uint32_t)(((uint32_t)(x)) << SIM_GPR0_OCOTP_CLK_DIS_SHIFT)) & SIM_GPR0_OCOTP_CLK_DIS_MASK)
/*! @} */

/*! @name GPR1 - HW SIM General Purpose Register 1 */
/*! @{ */

#define SIM_GPR1_USB_PHY_WAKEUP_ISO_DISABLE_MASK (0x1U)
#define SIM_GPR1_USB_PHY_WAKEUP_ISO_DISABLE_SHIFT (0U)
/*! USB_PHY_WAKEUP_ISO_DISABLE - USB PHY wakeup ISO disable. */
#define SIM_GPR1_USB_PHY_WAKEUP_ISO_DISABLE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_GPR1_USB_PHY_WAKEUP_ISO_DISABLE_SHIFT)) & SIM_GPR1_USB_PHY_WAKEUP_ISO_DISABLE_MASK)

#define SIM_GPR1_USB_PHY_NON_VLLS_WAKEUP_EN_MASK (0x2U)
#define SIM_GPR1_USB_PHY_NON_VLLS_WAKEUP_EN_SHIFT (1U)
/*! USB_PHY_NON_VLLS_WAKEUP_EN - USB PHY non VLLS wakeup enable. */
#define SIM_GPR1_USB_PHY_NON_VLLS_WAKEUP_EN(x)   (((uint32_t)(((uint32_t)(x)) << SIM_GPR1_USB_PHY_NON_VLLS_WAKEUP_EN_SHIFT)) & SIM_GPR1_USB_PHY_NON_VLLS_WAKEUP_EN_MASK)
/*! @} */

/*! @name MISC_CTRL0 - HW SIM MISC Register 0 */
/*! @{ */

#define SIM_MISC_CTRL0_FB_DELAY_OE_EXTS_MASK     (0x1U)
#define SIM_MISC_CTRL0_FB_DELAY_OE_EXTS_SHIFT    (0U)
/*! FB_DELAY_OE_EXTS - Flexbus control of FB_OE_b signal delay when CSCR[EXTS] is enabled. */
#define SIM_MISC_CTRL0_FB_DELAY_OE_EXTS(x)       (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_FB_DELAY_OE_EXTS_SHIFT)) & SIM_MISC_CTRL0_FB_DELAY_OE_EXTS_MASK)

#define SIM_MISC_CTRL0_OBS_CLK_ENABLE_MASK       (0x10U)
#define SIM_MISC_CTRL0_OBS_CLK_ENABLE_SHIFT      (4U)
/*! OBS_CLK_ENABLE - Enable that clocks can be observed at M4 CLKOUT, A7 CLKOUT and LVDS clock pads. */
#define SIM_MISC_CTRL0_OBS_CLK_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_OBS_CLK_ENABLE_SHIFT)) & SIM_MISC_CTRL0_OBS_CLK_ENABLE_MASK)

#define SIM_MISC_CTRL0_M4_OBS_CLK_SRC_SEL_MASK   (0x3C0U)
#define SIM_MISC_CTRL0_M4_OBS_CLK_SRC_SEL_SHIFT  (6U)
/*! M4_OBS_CLK_SRC_SEL - Selects the clock to be observed on M4 domain. */
#define SIM_MISC_CTRL0_M4_OBS_CLK_SRC_SEL(x)     (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_M4_OBS_CLK_SRC_SEL_SHIFT)) & SIM_MISC_CTRL0_M4_OBS_CLK_SRC_SEL_MASK)

#define SIM_MISC_CTRL0_M4_OBS_CLK_DIV_RATIO_MASK (0x1C00U)
#define SIM_MISC_CTRL0_M4_OBS_CLK_DIV_RATIO_SHIFT (10U)
/*! M4_OBS_CLK_DIV_RATIO - Selection of division rate (2**n) of M4 observation clock div rate = 2**n (n=0..7). */
#define SIM_MISC_CTRL0_M4_OBS_CLK_DIV_RATIO(x)   (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_M4_OBS_CLK_DIV_RATIO_SHIFT)) & SIM_MISC_CTRL0_M4_OBS_CLK_DIV_RATIO_MASK)

#define SIM_MISC_CTRL0_A7_OBS_CLK_SRC_SEL_MASK   (0x1E000U)
#define SIM_MISC_CTRL0_A7_OBS_CLK_SRC_SEL_SHIFT  (13U)
/*! A7_OBS_CLK_SRC_SEL - Selects the clock to be observed on A7 domain. */
#define SIM_MISC_CTRL0_A7_OBS_CLK_SRC_SEL(x)     (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_A7_OBS_CLK_SRC_SEL_SHIFT)) & SIM_MISC_CTRL0_A7_OBS_CLK_SRC_SEL_MASK)

#define SIM_MISC_CTRL0_A7_OBS_CLK_DIV_RATIO_MASK (0xE0000U)
#define SIM_MISC_CTRL0_A7_OBS_CLK_DIV_RATIO_SHIFT (17U)
/*! A7_OBS_CLK_DIV_RATIO - Selection of division rate (2**n) of A7 observation clock div rate = 2**n (n=0..7). */
#define SIM_MISC_CTRL0_A7_OBS_CLK_DIV_RATIO(x)   (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_A7_OBS_CLK_DIV_RATIO_SHIFT)) & SIM_MISC_CTRL0_A7_OBS_CLK_DIV_RATIO_MASK)

#define SIM_MISC_CTRL0_TESTCLK_TRIM_MASK         (0x700000U)
#define SIM_MISC_CTRL0_TESTCLK_TRIM_SHIFT        (20U)
/*! TESTCLK_TRIM - Trim Delay for LVDS TESTCLK_P/TESTCLK_N pad. */
#define SIM_MISC_CTRL0_TESTCLK_TRIM(x)           (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_TESTCLK_TRIM_SHIFT)) & SIM_MISC_CTRL0_TESTCLK_TRIM_MASK)

#define SIM_MISC_CTRL0_TESTCLK_OBE_MASK          (0x800000U)
#define SIM_MISC_CTRL0_TESTCLK_OBE_SHIFT         (23U)
/*! TESTCLK_OBE - Output Buffer Enable for LVDS TESTCLK_P/TESTCLK_N pad. */
#define SIM_MISC_CTRL0_TESTCLK_OBE(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_TESTCLK_OBE_SHIFT)) & SIM_MISC_CTRL0_TESTCLK_OBE_MASK)

#define SIM_MISC_CTRL0_DISABLE_DDR_HW_AUTO_LP_MODE_MASK (0x1000000U)
#define SIM_MISC_CTRL0_DISABLE_DDR_HW_AUTO_LP_MODE_SHIFT (24U)
/*! DISABLE_DDR_HW_AUTO_LP_MODE - Disable control to put DDR in self-refresh mode automatically by HW during low power modes. */
#define SIM_MISC_CTRL0_DISABLE_DDR_HW_AUTO_LP_MODE(x) (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_DISABLE_DDR_HW_AUTO_LP_MODE_SHIFT)) & SIM_MISC_CTRL0_DISABLE_DDR_HW_AUTO_LP_MODE_MASK)

#define SIM_MISC_CTRL0_A7_TSTMR_COMP_EN_MASK     (0x2000000U)
#define SIM_MISC_CTRL0_A7_TSTMR_COMP_EN_SHIFT    (25U)
/*! A7_TSTMR_COMP_EN - Enables the compare of A7 TS Timer versus a programmed value. */
#define SIM_MISC_CTRL0_A7_TSTMR_COMP_EN(x)       (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_A7_TSTMR_COMP_EN_SHIFT)) & SIM_MISC_CTRL0_A7_TSTMR_COMP_EN_MASK)

#define SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_CTRL_MASK (0x4000000U)
#define SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_CTRL_SHIFT (26U)
/*! A7_TO_M4_RST_IRQ_CTRL - Controls the assertion of A7 reset as IRQ/Wake-up to M4. */
#define SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_CTRL_SHIFT)) & SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_CTRL_MASK)

#define SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_EN_MASK  (0x8000000U)
#define SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_EN_SHIFT (27U)
/*! A7_TO_M4_RST_IRQ_EN - Enables the assertion of A7 reset as IRQ/Wake-up to M4. */
#define SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_EN_SHIFT)) & SIM_MISC_CTRL0_A7_TO_M4_RST_IRQ_EN_MASK)

#define SIM_MISC_CTRL0_A7_TSTMR_COMP_IRQ_CTRL_MASK (0x20000000U)
#define SIM_MISC_CTRL0_A7_TSTMR_COMP_IRQ_CTRL_SHIFT (29U)
/*! A7_TSTMR_COMP_IRQ_CTRL - Controls the compare of A7 reset as IRQ. */
#define SIM_MISC_CTRL0_A7_TSTMR_COMP_IRQ_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTRL0_A7_TSTMR_COMP_IRQ_CTRL_SHIFT)) & SIM_MISC_CTRL0_A7_TSTMR_COMP_IRQ_CTRL_MASK)
/*! @} */

/*! @name SIM_DGO_CTRL0 - SIM DGO Control Register 0 */
/*! @{ */

#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP1_MASK    (0x1U)
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP1_SHIFT   (0U)
/*! UPDATE_DGO_GP1 - Writing 1 to this bit field indicates corresponding DGO_GP1 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP1(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP1_SHIFT)) & SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP1_MASK)

#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP2_MASK    (0x2U)
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP2_SHIFT   (1U)
/*! UPDATE_DGO_GP2 - Writing 1 to this bit field indicates corresponding DGO_GP2 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP2(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP2_SHIFT)) & SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP2_MASK)

#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP3_MASK    (0x4U)
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP3_SHIFT   (2U)
/*! UPDATE_DGO_GP3 - Writing 1 to this bit field indicates corresponding DGO_GP3 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP3(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP3_SHIFT)) & SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP3_MASK)

#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP4_MASK    (0x8U)
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP4_SHIFT   (3U)
/*! UPDATE_DGO_GP4 - Writing 1 to this bit field indicates corresponding DGO_GP4 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP4(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP4_SHIFT)) & SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP4_MASK)

#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP5_MASK    (0x10U)
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP5_SHIFT   (4U)
/*! UPDATE_DGO_GP5 - Writing 1 to this bit field indicates corresponding DGO_GP5 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP5(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP5_SHIFT)) & SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP5_MASK)

#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP6_MASK    (0x20U)
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP6_SHIFT   (5U)
/*! UPDATE_DGO_GP6 - Writing 1 to this bit field indicates corresponding DGO_GP6 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP6(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP6_SHIFT)) & SIM_SIM_DGO_CTRL0_UPDATE_DGO_GP6_MASK)

#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP1_MASK    (0x2000U)
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP1_SHIFT   (13U)
/*! WR_ACK_DGO_GP1 - This bit field is set automatically when corresponding DGO_GP1 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP1(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP1_SHIFT)) & SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP1_MASK)

#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP2_MASK    (0x4000U)
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP2_SHIFT   (14U)
/*! WR_ACK_DGO_GP2 - This bit field is set automatically when corresponding DGO_GP2 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP2(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP2_SHIFT)) & SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP2_MASK)

#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP3_MASK    (0x8000U)
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP3_SHIFT   (15U)
/*! WR_ACK_DGO_GP3 - This bit field is set automatically when corresponding DGO_GP3 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP3(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP3_SHIFT)) & SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP3_MASK)

#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP4_MASK    (0x10000U)
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP4_SHIFT   (16U)
/*! WR_ACK_DGO_GP4 - This bit field is set automatically when corresponding DGO_GP4 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP4(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP4_SHIFT)) & SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP4_MASK)

#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP5_MASK    (0x20000U)
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP5_SHIFT   (17U)
/*! WR_ACK_DGO_GP5 - This bit field is set automatically when corresponding DGO_GP5 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP5(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP5_SHIFT)) & SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP5_MASK)

#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP6_MASK    (0x40000U)
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP6_SHIFT   (18U)
/*! WR_ACK_DGO_GP6 - This bit field is set automatically when corresponding DGO_GP6 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP6(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP6_SHIFT)) & SIM_SIM_DGO_CTRL0_WR_ACK_DGO_GP6_MASK)

#define SIM_SIM_DGO_CTRL0_INT_EN_ACK1_MASK       (0x4000000U)
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK1_SHIFT      (26U)
/*! INT_EN_ACK1 - Interrupt enable for WR_ACK_DGO_GP1 bit field. */
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK1(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_INT_EN_ACK1_SHIFT)) & SIM_SIM_DGO_CTRL0_INT_EN_ACK1_MASK)

#define SIM_SIM_DGO_CTRL0_INT_EN_ACK2_MASK       (0x8000000U)
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK2_SHIFT      (27U)
/*! INT_EN_ACK2 - Interrupt enable for WR_ACK_DGO_GP2 bit field. */
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK2(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_INT_EN_ACK2_SHIFT)) & SIM_SIM_DGO_CTRL0_INT_EN_ACK2_MASK)

#define SIM_SIM_DGO_CTRL0_INT_EN_ACK3_MASK       (0x10000000U)
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK3_SHIFT      (28U)
/*! INT_EN_ACK3 - Interrupt enable for WR_ACK_DGO_GP3 bit field. */
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK3(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_INT_EN_ACK3_SHIFT)) & SIM_SIM_DGO_CTRL0_INT_EN_ACK3_MASK)

#define SIM_SIM_DGO_CTRL0_INT_EN_ACK4_MASK       (0x20000000U)
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK4_SHIFT      (29U)
/*! INT_EN_ACK4 - Interrupt enable for WR_ACK_DGO_GP4 bit field. */
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK4(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_INT_EN_ACK4_SHIFT)) & SIM_SIM_DGO_CTRL0_INT_EN_ACK4_MASK)

#define SIM_SIM_DGO_CTRL0_INT_EN_ACK5_MASK       (0x40000000U)
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK5_SHIFT      (30U)
/*! INT_EN_ACK5 - Interrupt enable for WR_ACK_DGO_GP5 bit field. */
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK5(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_INT_EN_ACK5_SHIFT)) & SIM_SIM_DGO_CTRL0_INT_EN_ACK5_MASK)

#define SIM_SIM_DGO_CTRL0_INT_EN_ACK6_MASK       (0x80000000U)
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK6_SHIFT      (31U)
/*! INT_EN_ACK6 - Interrupt enable for WR_ACK_DGO_GP6 bit field. */
#define SIM_SIM_DGO_CTRL0_INT_EN_ACK6(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL0_INT_EN_ACK6_SHIFT)) & SIM_SIM_DGO_CTRL0_INT_EN_ACK6_MASK)
/*! @} */

/*! @name SIM_DGO_CTRL1 - SIM DGO Control Register 1 */
/*! @{ */

#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP7_MASK    (0x1U)
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP7_SHIFT   (0U)
/*! UPDATE_DGO_GP7 - Writing 1 to this bit field indicates corresponding DGO_GP7 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP7(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP7_SHIFT)) & SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP7_MASK)

#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP8_MASK    (0x2U)
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP8_SHIFT   (1U)
/*! UPDATE_DGO_GP8 - Writing 1 to this bit field indicates corresponding DGO_GP8 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP8(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP8_SHIFT)) & SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP8_MASK)

#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP9_MASK    (0x4U)
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP9_SHIFT   (2U)
/*! UPDATE_DGO_GP9 - Writing 1 to this bit field indicates corresponding DGO_GP9 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP9(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP9_SHIFT)) & SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP9_MASK)

#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP10_MASK   (0x8U)
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP10_SHIFT  (3U)
/*! UPDATE_DGO_GP10 - Writing 1 to this bit field indicates corresponding DGO_GP10 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP10(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP10_SHIFT)) & SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP10_MASK)

#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP11_MASK   (0x10U)
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP11_SHIFT  (4U)
/*! UPDATE_DGO_GP11 - Writing 1 to this bit field indicates corresponding DGO_GP11 register has been updated with new values. */
#define SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP11(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP11_SHIFT)) & SIM_SIM_DGO_CTRL1_UPDATE_DGO_GP11_MASK)

#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP7_MASK    (0x2000U)
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP7_SHIFT   (13U)
/*! WR_ACK_DGO_GP7 - This bit field is set automatically when corresponding DGO_GP7 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP7(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP7_SHIFT)) & SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP7_MASK)

#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP8_MASK    (0x4000U)
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP8_SHIFT   (14U)
/*! WR_ACK_DGO_GP8 - This bit field is set automatically when corresponding DGO_GP8 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP8(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP8_SHIFT)) & SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP8_MASK)

#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP9_MASK    (0x8000U)
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP9_SHIFT   (15U)
/*! WR_ACK_DGO_GP9 - This bit field is set automatically when corresponding DGO_GP9 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP9(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP9_SHIFT)) & SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP9_MASK)

#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP10_MASK   (0x10000U)
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP10_SHIFT  (16U)
/*! WR_ACK_DGO_GP10 - This bit field is set automatically when corresponding DGO_GP10 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP10(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP10_SHIFT)) & SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP10_MASK)

#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP11_MASK   (0x20000U)
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP11_SHIFT  (17U)
/*! WR_ACK_DGO_GP11 - This bit field is set automatically when corresponding DGO_GP11 register is
 *    shadowed in DGO domain. SW needs to write "1" to clear.
 */
#define SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP11(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP11_SHIFT)) & SIM_SIM_DGO_CTRL1_WR_ACK_DGO_GP11_MASK)

#define SIM_SIM_DGO_CTRL1_INT_EN_ACK7_MASK       (0x8000000U)
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK7_SHIFT      (27U)
/*! INT_EN_ACK7 - Interrupt enable for WR_ACK_DGO_GP7 bit field. */
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK7(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_INT_EN_ACK7_SHIFT)) & SIM_SIM_DGO_CTRL1_INT_EN_ACK7_MASK)

#define SIM_SIM_DGO_CTRL1_INT_EN_ACK8_MASK       (0x10000000U)
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK8_SHIFT      (28U)
/*! INT_EN_ACK8 - Interrupt enable for WR_ACK_DGO_GP8 bit field. */
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK8(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_INT_EN_ACK8_SHIFT)) & SIM_SIM_DGO_CTRL1_INT_EN_ACK8_MASK)

#define SIM_SIM_DGO_CTRL1_INT_EN_ACK9_MASK       (0x20000000U)
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK9_SHIFT      (29U)
/*! INT_EN_ACK9 - Interrupt enable for WR_ACK_DGO_GP9 bit field. */
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK9(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_INT_EN_ACK9_SHIFT)) & SIM_SIM_DGO_CTRL1_INT_EN_ACK9_MASK)

#define SIM_SIM_DGO_CTRL1_INT_EN_ACK10_MASK      (0x40000000U)
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK10_SHIFT     (30U)
/*! INT_EN_ACK10 - Interrupt enable for WR_ACK_DGO_GP10 bit field. */
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK10(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_INT_EN_ACK10_SHIFT)) & SIM_SIM_DGO_CTRL1_INT_EN_ACK10_MASK)

#define SIM_SIM_DGO_CTRL1_INT_EN_ACK11_MASK      (0x80000000U)
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK11_SHIFT     (31U)
/*! INT_EN_ACK11 - Interrupt enable for WR_ACK_DGO_GP11 bit field. */
#define SIM_SIM_DGO_CTRL1_INT_EN_ACK11(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_CTRL1_INT_EN_ACK11_SHIFT)) & SIM_SIM_DGO_CTRL1_INT_EN_ACK11_MASK)
/*! @} */

/*! @name SIM_DGO_GP1 - SIM DGO General Purpose Register 1 */
/*! @{ */

#define SIM_SIM_DGO_GP1_SIM_DGO_GP1_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP1_SIM_DGO_GP1_SHIFT        (0U)
/*! SIM_DGO_GP1 - SIM DGO General purpose register 1. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP1_SIM_DGO_GP1(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP1_SIM_DGO_GP1_SHIFT)) & SIM_SIM_DGO_GP1_SIM_DGO_GP1_MASK)
/*! @} */

/*! @name SIM_DGO_GP2 - SIM DGO general Purpose Register 2 */
/*! @{ */

#define SIM_SIM_DGO_GP2_SIM_DGO_GP2_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP2_SIM_DGO_GP2_SHIFT        (0U)
/*! SIM_DGO_GP2 - SIM DGO General purpose register 2. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP2_SIM_DGO_GP2(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP2_SIM_DGO_GP2_SHIFT)) & SIM_SIM_DGO_GP2_SIM_DGO_GP2_MASK)
/*! @} */

/*! @name SIM_DGO_GP3 - SIM DGO General Purpose Register 3 */
/*! @{ */

#define SIM_SIM_DGO_GP3_SIM_DGO_GP3_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP3_SIM_DGO_GP3_SHIFT        (0U)
/*! SIM_DGO_GP3 - SIM DGO General purpose register 3. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP3_SIM_DGO_GP3(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP3_SIM_DGO_GP3_SHIFT)) & SIM_SIM_DGO_GP3_SIM_DGO_GP3_MASK)
/*! @} */

/*! @name SIM_DGO_GP4 - SIM DGO General Purpose Register 4 */
/*! @{ */

#define SIM_SIM_DGO_GP4_SIM_DGO_GP4_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP4_SIM_DGO_GP4_SHIFT        (0U)
/*! SIM_DGO_GP4 - SIM DGO General purpose register 4. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP4_SIM_DGO_GP4(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP4_SIM_DGO_GP4_SHIFT)) & SIM_SIM_DGO_GP4_SIM_DGO_GP4_MASK)
/*! @} */

/*! @name SIM_DGO_GP5 - SIM DGO General Purpose Register 5 */
/*! @{ */

#define SIM_SIM_DGO_GP5_SIM_DGO_GP5_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP5_SIM_DGO_GP5_SHIFT        (0U)
/*! SIM_DGO_GP5 - SIM DGO General purpose register 5. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP5_SIM_DGO_GP5(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP5_SIM_DGO_GP5_SHIFT)) & SIM_SIM_DGO_GP5_SIM_DGO_GP5_MASK)
/*! @} */

/*! @name SIM_DGO_GP6 - SIM DGO General Purpose Register 6 */
/*! @{ */

#define SIM_SIM_DGO_GP6_SIM_DGO_GP6_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP6_SIM_DGO_GP6_SHIFT        (0U)
/*! SIM_DGO_GP6 - SIM DGO General purpose register 6. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP6_SIM_DGO_GP6(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP6_SIM_DGO_GP6_SHIFT)) & SIM_SIM_DGO_GP6_SIM_DGO_GP6_MASK)
/*! @} */

/*! @name SIM_DGO_GP7 - SIM DGO General Purpose Register 7 */
/*! @{ */

#define SIM_SIM_DGO_GP7_SIM_DGO_GP7_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP7_SIM_DGO_GP7_SHIFT        (0U)
/*! SIM_DGO_GP7 - SIM DGO General purpose register 7. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP7_SIM_DGO_GP7(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP7_SIM_DGO_GP7_SHIFT)) & SIM_SIM_DGO_GP7_SIM_DGO_GP7_MASK)
/*! @} */

/*! @name SIM_DGO_GP8 - SIM DGO General Purpose Register 8 */
/*! @{ */

#define SIM_SIM_DGO_GP8_SIM_DGO_GP8_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP8_SIM_DGO_GP8_SHIFT        (0U)
/*! SIM_DGO_GP8 - SIM DGO General purpose register 8. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP8_SIM_DGO_GP8(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP8_SIM_DGO_GP8_SHIFT)) & SIM_SIM_DGO_GP8_SIM_DGO_GP8_MASK)
/*! @} */

/*! @name SIM_DGO_GP9 - SIM DGO General Purpose Register 9 */
/*! @{ */

#define SIM_SIM_DGO_GP9_SIM_DGO_GP9_MASK         (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP9_SIM_DGO_GP9_SHIFT        (0U)
/*! SIM_DGO_GP9 - SIM DGO General purpose register 9. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP9_SIM_DGO_GP9(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP9_SIM_DGO_GP9_SHIFT)) & SIM_SIM_DGO_GP9_SIM_DGO_GP9_MASK)
/*! @} */

/*! @name SIM_DGO_GP10 - SIM DGO General Purpose Register 10 */
/*! @{ */

#define SIM_SIM_DGO_GP10_SIM_DGO_GP10_MASK       (0xFFFFFFFFU)
#define SIM_SIM_DGO_GP10_SIM_DGO_GP10_SHIFT      (0U)
/*! SIM_DGO_GP10 - SIM DGO General purpose register 10. Contents are retained between power cycles */
#define SIM_SIM_DGO_GP10_SIM_DGO_GP10(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP10_SIM_DGO_GP10_SHIFT)) & SIM_SIM_DGO_GP10_SIM_DGO_GP10_MASK)
/*! @} */

/*! @name SIM_DGO_GP11 - SIM DGO General Purpose Register 11 */
/*! @{ */

#define SIM_SIM_DGO_GP11_DBG_SPIDEN_SPNIDEN_MASK (0x1U)
#define SIM_SIM_DGO_GP11_DBG_SPIDEN_SPNIDEN_SHIFT (0U)
/*! DBG_SPIDEN_SPNIDEN - Debug secured access enable. */
#define SIM_SIM_DGO_GP11_DBG_SPIDEN_SPNIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_DBG_SPIDEN_SPNIDEN_SHIFT)) & SIM_SIM_DGO_GP11_DBG_SPIDEN_SPNIDEN_MASK)

#define SIM_SIM_DGO_GP11_NMI_VLLS_WAKEUP_EN_MASK (0x80U)
#define SIM_SIM_DGO_GP11_NMI_VLLS_WAKEUP_EN_SHIFT (7U)
/*! NMI_VLLS_WAKEUP_EN - Enables NMI pin as VLLS wakeup source (not necessary for non-VLLS modes). */
#define SIM_SIM_DGO_GP11_NMI_VLLS_WAKEUP_EN(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_NMI_VLLS_WAKEUP_EN_SHIFT)) & SIM_SIM_DGO_GP11_NMI_VLLS_WAKEUP_EN_MASK)

#define SIM_SIM_DGO_GP11_USB_PHY_VLLS_WAKEUP_EN_MASK (0x1000U)
#define SIM_SIM_DGO_GP11_USB_PHY_VLLS_WAKEUP_EN_SHIFT (12U)
/*! USB_PHY_VLLS_WAKEUP_EN - USB PHY VLLS wakeup enable. */
#define SIM_SIM_DGO_GP11_USB_PHY_VLLS_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_USB_PHY_VLLS_WAKEUP_EN_SHIFT)) & SIM_SIM_DGO_GP11_USB_PHY_VLLS_WAKEUP_EN_MASK)

#define SIM_SIM_DGO_GP11_PTA_RANGE_CTRL_MASK     (0x30000U)
#define SIM_SIM_DGO_GP11_PTA_RANGE_CTRL_SHIFT    (16U)
/*! PTA_RANGE_CTRL - PTA Range Control. */
#define SIM_SIM_DGO_GP11_PTA_RANGE_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_PTA_RANGE_CTRL_SHIFT)) & SIM_SIM_DGO_GP11_PTA_RANGE_CTRL_MASK)

#define SIM_SIM_DGO_GP11_PTB_RANGE_CTRL_MASK     (0xC0000U)
#define SIM_SIM_DGO_GP11_PTB_RANGE_CTRL_SHIFT    (18U)
/*! PTB_RANGE_CTRL - PTB Range Control. */
#define SIM_SIM_DGO_GP11_PTB_RANGE_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_PTB_RANGE_CTRL_SHIFT)) & SIM_SIM_DGO_GP11_PTB_RANGE_CTRL_MASK)

#define SIM_SIM_DGO_GP11_PTC_RANGE_CTRL_MASK     (0x300000U)
#define SIM_SIM_DGO_GP11_PTC_RANGE_CTRL_SHIFT    (20U)
/*! PTC_RANGE_CTRL - PTC Range Control. */
#define SIM_SIM_DGO_GP11_PTC_RANGE_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_PTC_RANGE_CTRL_SHIFT)) & SIM_SIM_DGO_GP11_PTC_RANGE_CTRL_MASK)

#define SIM_SIM_DGO_GP11_PTE_RANGE_CTRL_MASK     (0xC00000U)
#define SIM_SIM_DGO_GP11_PTE_RANGE_CTRL_SHIFT    (22U)
/*! PTE_RANGE_CTRL - PTE Range Control. */
#define SIM_SIM_DGO_GP11_PTE_RANGE_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_PTE_RANGE_CTRL_SHIFT)) & SIM_SIM_DGO_GP11_PTE_RANGE_CTRL_MASK)

#define SIM_SIM_DGO_GP11_PTF_RANGE_CTRL_MASK     (0x3000000U)
#define SIM_SIM_DGO_GP11_PTF_RANGE_CTRL_SHIFT    (24U)
/*! PTF_RANGE_CTRL - PTF Range Control. */
#define SIM_SIM_DGO_GP11_PTF_RANGE_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SIM_DGO_GP11_PTF_RANGE_CTRL_SHIFT)) & SIM_SIM_DGO_GP11_PTF_RANGE_CTRL_MASK)
/*! @} */

/*! @name WKPU_WAKEUP_EN - WKPU Wake-up Enable */
/*! @{ */

#define SIM_WKPU_WAKEUP_EN_WKPU_CH_WAKEUP_EN_MASK (0xFFFFFFFFU)
#define SIM_WKPU_WAKEUP_EN_WKPU_CH_WAKEUP_EN_SHIFT (0U)
/*! WKPU_CH_WAKEUP_EN - Bit used to disable wake-up events through this channel. Each channel may
 *    have one or multiple wake-up sources associated to it.
 */
#define SIM_WKPU_WAKEUP_EN_WKPU_CH_WAKEUP_EN(x)  (((uint32_t)(((uint32_t)(x)) << SIM_WKPU_WAKEUP_EN_WKPU_CH_WAKEUP_EN_SHIFT)) & SIM_WKPU_WAKEUP_EN_WKPU_CH_WAKEUP_EN_MASK)
/*! @} */

/*! @name JTAG_ID_REG - Mirror of JTAG ID Register */
/*! @{ */

#define SIM_JTAG_ID_REG_JTAG_INIT_BIT_MASK       (0x1U)
#define SIM_JTAG_ID_REG_JTAG_INIT_BIT_SHIFT      (0U)
/*! JTAG_INIT_BIT - JTAG ID initial bit. */
#define SIM_JTAG_ID_REG_JTAG_INIT_BIT(x)         (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_JTAG_INIT_BIT_SHIFT)) & SIM_JTAG_ID_REG_JTAG_INIT_BIT_MASK)

#define SIM_JTAG_ID_REG_COMPANY_IDCODE_MASK      (0xFFEU)
#define SIM_JTAG_ID_REG_COMPANY_IDCODE_SHIFT     (1U)
/*! COMPANY_IDCODE - Company ID Code. */
#define SIM_JTAG_ID_REG_COMPANY_IDCODE(x)        (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_COMPANY_IDCODE_SHIFT)) & SIM_JTAG_ID_REG_COMPANY_IDCODE_MASK)

#define SIM_JTAG_ID_REG_PIN_PLUG_MASK            (0x3FF000U)
#define SIM_JTAG_ID_REG_PIN_PLUG_SHIFT           (12U)
/*! PIN_PLUG - Part Identification Number. */
#define SIM_JTAG_ID_REG_PIN_PLUG(x)              (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_PIN_PLUG_SHIFT)) & SIM_JTAG_ID_REG_PIN_PLUG_MASK)

#define SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_MASK (0xFC00000U)
#define SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_SHIFT (22U)
/*! DESIGN_CENTER_IDCODE - Design Center ID Code. */
#define SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE(x)  (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_SHIFT)) & SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_MASK)

#define SIM_JTAG_ID_REG_PRN_PLUG_MASK            (0xF0000000U)
#define SIM_JTAG_ID_REG_PRN_PLUG_SHIFT           (28U)
/*! PRN_PLUG - Part Revision Number. */
#define SIM_JTAG_ID_REG_PRN_PLUG(x)              (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_PRN_PLUG_SHIFT)) & SIM_JTAG_ID_REG_PRN_PLUG_MASK)
/*! @} */

/*! @name A7_TSTMR_CMP_VAL_L - Lower A7 TS Timer compare value */
/*! @{ */

#define SIM_A7_TSTMR_CMP_VAL_L_A7_TSTMR_CMP_VAL_L_MASK (0xFFFFFFFFU)
#define SIM_A7_TSTMR_CMP_VAL_L_A7_TSTMR_CMP_VAL_L_SHIFT (0U)
/*! A7_TSTMR_CMP_VAL_L - Lower A7 TS Timer compare value. */
#define SIM_A7_TSTMR_CMP_VAL_L_A7_TSTMR_CMP_VAL_L(x) (((uint32_t)(((uint32_t)(x)) << SIM_A7_TSTMR_CMP_VAL_L_A7_TSTMR_CMP_VAL_L_SHIFT)) & SIM_A7_TSTMR_CMP_VAL_L_A7_TSTMR_CMP_VAL_L_MASK)
/*! @} */

/*! @name A7_TSTMR_CMP_VAL_H - Upper A7 TS Timer compare value */
/*! @{ */

#define SIM_A7_TSTMR_CMP_VAL_H_A7_TSTMR_CMP_VAL_H_MASK (0xFFFFFFFFU)
#define SIM_A7_TSTMR_CMP_VAL_H_A7_TSTMR_CMP_VAL_H_SHIFT (0U)
/*! A7_TSTMR_CMP_VAL_H - Upper A7 TS Timer compare value. */
#define SIM_A7_TSTMR_CMP_VAL_H_A7_TSTMR_CMP_VAL_H(x) (((uint32_t)(((uint32_t)(x)) << SIM_A7_TSTMR_CMP_VAL_H_A7_TSTMR_CMP_VAL_H_SHIFT)) & SIM_A7_TSTMR_CMP_VAL_H_A7_TSTMR_CMP_VAL_H_MASK)
/*! @} */

/*! @name COMP_CELL_OVERRIDE - Override Control for Compensation Codes */
/*! @{ */

#define SIM_COMP_CELL_OVERRIDE_RASRCN_MASK       (0xFU)
#define SIM_COMP_CELL_OVERRIDE_RASRCN_SHIFT      (0U)
/*! RASRCN - 4-bit NMOS compensation codes. */
#define SIM_COMP_CELL_OVERRIDE_RASRCN(x)         (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_RASRCN_SHIFT)) & SIM_COMP_CELL_OVERRIDE_RASRCN_MASK)

#define SIM_COMP_CELL_OVERRIDE_RASRCP_MASK       (0xF0U)
#define SIM_COMP_CELL_OVERRIDE_RASRCP_SHIFT      (4U)
/*! RASRCP - 4-bit PMOS compensation codes. */
#define SIM_COMP_CELL_OVERRIDE_RASRCP(x)         (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_RASRCP_SHIFT)) & SIM_COMP_CELL_OVERRIDE_RASRCP_MASK)

#define SIM_COMP_CELL_OVERRIDE_READ_MODE_MASK    (0x100U)
#define SIM_COMP_CELL_OVERRIDE_READ_MODE_SHIFT   (8U)
/*! READ_MODE - Read Mode. */
#define SIM_COMP_CELL_OVERRIDE_READ_MODE(x)      (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_READ_MODE_SHIFT)) & SIM_COMP_CELL_OVERRIDE_READ_MODE_MASK)

#define SIM_COMP_CELL_OVERRIDE_FASTFREEZE_MASK   (0x200U)
#define SIM_COMP_CELL_OVERRIDE_FASTFREEZE_SHIFT  (9U)
/*! FASTFREEZE - Fast-Freeze. */
#define SIM_COMP_CELL_OVERRIDE_FASTFREEZE(x)     (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_FASTFREEZE_SHIFT)) & SIM_COMP_CELL_OVERRIDE_FASTFREEZE_MASK)

#define SIM_COMP_CELL_OVERRIDE_FREEZE_MASK       (0x400U)
#define SIM_COMP_CELL_OVERRIDE_FREEZE_SHIFT      (10U)
/*! FREEZE - Freeze. */
#define SIM_COMP_CELL_OVERRIDE_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_FREEZE_SHIFT)) & SIM_COMP_CELL_OVERRIDE_FREEZE_MASK)

#define SIM_COMP_CELL_OVERRIDE_NASRCN_MASK       (0xF0000U)
#define SIM_COMP_CELL_OVERRIDE_NASRCN_SHIFT      (16U)
/*! NASRCN - 4-bit NMOS compensation measured/generated codes. */
#define SIM_COMP_CELL_OVERRIDE_NASRCN(x)         (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_NASRCN_SHIFT)) & SIM_COMP_CELL_OVERRIDE_NASRCN_MASK)

#define SIM_COMP_CELL_OVERRIDE_NASRCP_MASK       (0xF00000U)
#define SIM_COMP_CELL_OVERRIDE_NASRCP_SHIFT      (20U)
/*! NASRCP - 4-bit PMOS compensation measured/generated codes. */
#define SIM_COMP_CELL_OVERRIDE_NASRCP(x)         (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_NASRCP_SHIFT)) & SIM_COMP_CELL_OVERRIDE_NASRCP_MASK)

#define SIM_COMP_CELL_OVERRIDE_COMPOK_MASK       (0x1000000U)
#define SIM_COMP_CELL_OVERRIDE_COMPOK_SHIFT      (24U)
/*! COMPOK - Compensation OK. */
#define SIM_COMP_CELL_OVERRIDE_COMPOK(x)         (((uint32_t)(((uint32_t)(x)) << SIM_COMP_CELL_OVERRIDE_COMPOK_SHIFT)) & SIM_COMP_CELL_OVERRIDE_COMPOK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


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


#endif  /* PERI_SIM_H_ */

