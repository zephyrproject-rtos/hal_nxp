/*
** ###################################################################
**     Processors:          MIMXRT1041DFP6B
**                          MIMXRT1041DJM6B
**                          MIMXRT1041XFP5B
**                          MIMXRT1041XJM5B
**                          MIMXRT1042DFP6B
**                          MIMXRT1042DJM6B
**                          MIMXRT1042XFP5B
**                          MIMXRT1042XJM5B
**                          MIMXRT1043DFP6B
**                          MIMXRT1043XFP5B
**                          MIMXRT1046DFQ6B
**                          MIMXRT1046XFQ5B
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC_GPR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2021-07-20)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC_GPR.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC_GPR
 *
 * CMSIS Peripheral Access Layer for IOMUXC_GPR
 */

#if !defined(PERI_IOMUXC_GPR_H_)
#define PERI_IOMUXC_GPR_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1041DFP6B) || defined(CPU_MIMXRT1041DJM6B) || defined(CPU_MIMXRT1041XFP5B) || defined(CPU_MIMXRT1041XJM5B))
#include "MIMXRT1041_COMMON.h"
#elif (defined(CPU_MIMXRT1042DFP6B) || defined(CPU_MIMXRT1042DJM6B) || defined(CPU_MIMXRT1042XFP5B) || defined(CPU_MIMXRT1042XJM5B))
#include "MIMXRT1042_COMMON.h"
#elif (defined(CPU_MIMXRT1043DFP6B) || defined(CPU_MIMXRT1043XFP5B))
#include "MIMXRT1043_COMMON.h"
#elif (defined(CPU_MIMXRT1046DFQ6B) || defined(CPU_MIMXRT1046XFQ5B))
#include "MIMXRT1046_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Peripheral_Access_Layer IOMUXC_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_GPR - Register Layout Typedef */
typedef struct {
       uint32_t GPR0;                              /**< GPR0 General Purpose Register, offset: 0x0 */
  __IO uint32_t GPR1;                              /**< GPR1 General Purpose Register, offset: 0x4 */
  __IO uint32_t GPR2;                              /**< GPR2 General Purpose Register, offset: 0x8 */
  __IO uint32_t GPR3;                              /**< GPR3 General Purpose Register, offset: 0xC */
  __IO uint32_t GPR4;                              /**< GPR4 General Purpose Register, offset: 0x10 */
  __IO uint32_t GPR5;                              /**< GPR5 General Purpose Register, offset: 0x14 */
  __IO uint32_t GPR6;                              /**< GPR6 General Purpose Register, offset: 0x18 */
  __IO uint32_t GPR7;                              /**< GPR7 General Purpose Register, offset: 0x1C */
  __IO uint32_t GPR8;                              /**< GPR8 General Purpose Register, offset: 0x20 */
       uint32_t GPR9;                              /**< GPR9 General Purpose Register, offset: 0x24 */
  __IO uint32_t GPR10;                             /**< GPR10 General Purpose Register, offset: 0x28 */
  __IO uint32_t GPR11;                             /**< GPR11 General Purpose Register, offset: 0x2C */
  __IO uint32_t GPR12;                             /**< GPR12 General Purpose Register, offset: 0x30 */
  __IO uint32_t GPR13;                             /**< GPR13 General Purpose Register, offset: 0x34 */
  __IO uint32_t GPR14;                             /**< GPR14 General Purpose Register, offset: 0x38 */
       uint32_t GPR15;                             /**< GPR15 General Purpose Register, offset: 0x3C */
  __IO uint32_t GPR16;                             /**< GPR16 General Purpose Register, offset: 0x40 */
  __IO uint32_t GPR17;                             /**< GPR17 General Purpose Register, offset: 0x44 */
  __IO uint32_t GPR18;                             /**< GPR18 General Purpose Register, offset: 0x48 */
  __IO uint32_t GPR19;                             /**< GPR19 General Purpose Register, offset: 0x4C */
  __IO uint32_t GPR20;                             /**< GPR20 General Purpose Register, offset: 0x50 */
  __IO uint32_t GPR21;                             /**< GPR21 General Purpose Register, offset: 0x54 */
  __IO uint32_t GPR22;                             /**< GPR22 General Purpose Register, offset: 0x58 */
  __IO uint32_t GPR23;                             /**< GPR23 General Purpose Register, offset: 0x5C */
  __IO uint32_t GPR24;                             /**< GPR24 General Purpose Register, offset: 0x60 */
  __IO uint32_t GPR25;                             /**< GPR25 General Purpose Register, offset: 0x64 */
  __IO uint32_t GPR26;                             /**< GPR26 General Purpose Register, offset: 0x68 */
  __IO uint32_t GPR27;                             /**< GPR27 General Purpose Register, offset: 0x6C */
  __IO uint32_t GPR28;                             /**< GPR28 General Purpose Register, offset: 0x70 */
  __IO uint32_t GPR29;                             /**< GPR29 General Purpose Register, offset: 0x74 */
  __IO uint32_t GPR30;                             /**< GPR30 General Purpose Register, offset: 0x78 */
  __IO uint32_t GPR31;                             /**< GPR31 General Purpose Register, offset: 0x7C */
  __IO uint32_t GPR32;                             /**< GPR32 General Purpose Register, offset: 0x80 */
  __IO uint32_t GPR33;                             /**< GPR33 General Purpose Register, offset: 0x84 */
  __IO uint32_t GPR34;                             /**< GPR34 General Purpose Register, offset: 0x88 */
} IOMUXC_GPR_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Register_Masks IOMUXC_GPR Register Masks
 * @{
 */

/*! @name GPR1 - GPR1 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_MASK      (0x7U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_SHIFT     (0U)
/*! SAI1_MCLK1_SEL
 *  0b000..ccm.ssi1_clk_root
 *  0b001..ccm.ssi2_clk_root
 *  0b010..ccm.ssi3_clk_root
 *  0b011..iomux.sai1_ipg_clk_sai_mclk
 *  0b100..iomux.sai2_ipg_clk_sai_mclk
 *  0b101..iomux.sai3_ipg_clk_sai_mclk
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_MASK)

#define IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_MASK      (0x38U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_SHIFT     (3U)
/*! SAI1_MCLK2_SEL
 *  0b000..ccm.ssi1_clk_root
 *  0b001..ccm.ssi2_clk_root
 *  0b010..ccm.ssi3_clk_root
 *  0b011..iomux.sai1_ipg_clk_sai_mclk
 *  0b100..iomux.sai2_ipg_clk_sai_mclk
 *  0b101..iomux.sai3_ipg_clk_sai_mclk
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_MASK)

#define IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_MASK      (0xC0U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_SHIFT     (6U)
/*! SAI1_MCLK3_SEL
 *  0b00..ccm.spdif0_clk_root
 *  0b01..iomux.spdif_tx_clk2
 *  0b10..spdif.spdif_srclk
 *  0b11..spdif.spdif_outclock
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_MASK)

#define IOMUXC_GPR_GPR1_SAI2_MCLK3_SEL_MASK      (0x300U)
#define IOMUXC_GPR_GPR1_SAI2_MCLK3_SEL_SHIFT     (8U)
/*! SAI2_MCLK3_SEL
 *  0b00..ccm.spdif0_clk_root
 *  0b01..iomux.spdif_tx_clk2
 *  0b10..spdif.spdif_srclk
 *  0b11..spdif.spdif_outclock
 */
#define IOMUXC_GPR_GPR1_SAI2_MCLK3_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI2_MCLK3_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI2_MCLK3_SEL_MASK)

#define IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_MASK      (0xC00U)
#define IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_SHIFT     (10U)
/*! SAI3_MCLK3_SEL
 *  0b00..ccm.spdif0_clk_root
 *  0b01..iomux.spdif_tx_clk2
 *  0b10..spdif.spdif_srclk
 *  0b11..spdif.spdif_outclock
 */
#define IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_MASK)

#define IOMUXC_GPR_GPR1_GINT_MASK                (0x1000U)
#define IOMUXC_GPR_GPR1_GINT_SHIFT               (12U)
/*! GINT - Global Interrupt
 *  0b0..Global interrupt request is not asserted.
 *  0b1..Global interrupt request is asserted.
 */
#define IOMUXC_GPR_GPR1_GINT(x)                  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_GINT_SHIFT)) & IOMUXC_GPR_GPR1_GINT_MASK)

#define IOMUXC_GPR_GPR1_ENET1_CLK_SEL_MASK       (0x2000U)
#define IOMUXC_GPR_GPR1_ENET1_CLK_SEL_SHIFT      (13U)
/*! ENET1_CLK_SEL
 *  0b0..ENET1 TX reference clock driven by ref_enetpll. This clock is also output to pins via the IOMUX. ENET_REF_CLK1 function.
 *  0b1..Gets ENET1 TX reference clock from the ENET1_TX_CLK pin. In this use case, an external OSC provides the
 *       clock for both the external PHY and the internal controller.
 */
#define IOMUXC_GPR_GPR1_ENET1_CLK_SEL(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_ENET1_CLK_SEL_SHIFT)) & IOMUXC_GPR_GPR1_ENET1_CLK_SEL_MASK)

#define IOMUXC_GPR_GPR1_ENET2_CLK_SEL_MASK       (0x4000U)
#define IOMUXC_GPR_GPR1_ENET2_CLK_SEL_SHIFT      (14U)
/*! ENET2_CLK_SEL
 *  0b0..ENET2 TX reference clock driven by ref_enetpll. This clock is also output to pins via the IOMUX. ENET2_REF_CLK function.
 *  0b1..Gets ENET2 TX reference clock from the ENET2_TX_CLK pin. In this use case, an external OSC provides the
 *       clock for both the external PHY and the internal controller.
 */
#define IOMUXC_GPR_GPR1_ENET2_CLK_SEL(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_ENET2_CLK_SEL_SHIFT)) & IOMUXC_GPR_GPR1_ENET2_CLK_SEL_MASK)

#define IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR_MASK    (0x20000U)
#define IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR_SHIFT   (17U)
/*! ENET1_TX_CLK_DIR
 *  0b0..ENET1_TX_CLK output driver is disabled
 *  0b1..ENET1_TX_CLK output driver is enabled
 */
#define IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR_SHIFT)) & IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR_MASK)

#define IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR_MASK    (0x40000U)
#define IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR_SHIFT   (18U)
/*! ENET2_TX_CLK_DIR
 *  0b0..ENET2_TX_CLK output driver is disabled
 *  0b1..ENET2_TX_CLK output driver is enabled
 */
#define IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR_SHIFT)) & IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR_MASK)

#define IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK       (0x80000U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_SHIFT      (19U)
/*! SAI1_MCLK_DIR - sai1.MCLK signal direction control
 *  0b0..sai1.MCLK is input signal
 *  0b1..sai1.MCLK is output signal
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK)

#define IOMUXC_GPR_GPR1_SAI2_MCLK_DIR_MASK       (0x100000U)
#define IOMUXC_GPR_GPR1_SAI2_MCLK_DIR_SHIFT      (20U)
/*! SAI2_MCLK_DIR - sai2.MCLK signal direction control
 *  0b0..sai2.MCLK is input signal
 *  0b1..sai2.MCLK is output signal
 */
#define IOMUXC_GPR_GPR1_SAI2_MCLK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI2_MCLK_DIR_SHIFT)) & IOMUXC_GPR_GPR1_SAI2_MCLK_DIR_MASK)

#define IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_MASK       (0x200000U)
#define IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_SHIFT      (21U)
/*! SAI3_MCLK_DIR - sai3.MCLK signal direction control
 *  0b0..sai3.MCLK is input signal
 *  0b1..sai3.MCLK is output signal
 */
#define IOMUXC_GPR_GPR1_SAI3_MCLK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_SHIFT)) & IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_MASK)

#define IOMUXC_GPR_GPR1_EXC_MON_MASK             (0x400000U)
#define IOMUXC_GPR_GPR1_EXC_MON_SHIFT            (22U)
/*! EXC_MON - Exclusive monitor response select of illegal command
 *  0b0..OKAY response
 *  0b1..SLVError response (default)
 */
#define IOMUXC_GPR_GPR1_EXC_MON(x)               (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_EXC_MON_SHIFT)) & IOMUXC_GPR_GPR1_EXC_MON_MASK)

#define IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN_MASK   (0x800000U)
#define IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN_SHIFT  (23U)
/*! ENET_IPG_CLK_S_EN
 *  0b0..ipg_clk_s is gated when there is no IPS access
 *  0b1..ipg_clk_s is always on
 */
#define IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN_SHIFT)) & IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN_MASK)

#define IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_MASK   (0x80000000U)
#define IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_SHIFT  (31U)
/*! CM7_FORCE_HCLK_EN - Arm CM7 platform AHB clock enable
 *  0b0..AHB clock is not running (gated) when CM7 is sleeping and TCM is not accessible.
 *  0b1..AHB clock is running (enabled) when CM7 is sleeping and TCM is accessible.
 */
#define IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_SHIFT)) & IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_MASK)
/*! @} */

/*! @name GPR2 - GPR2 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR2_AXBS_L_AHBXL_HIGH_PRIORITY_MASK (0x1U)
#define IOMUXC_GPR_GPR2_AXBS_L_AHBXL_HIGH_PRIORITY_SHIFT (0U)
/*! AXBS_L_AHBXL_HIGH_PRIORITY
 *  0b0..AXBS_L AHBXL master does not have high priority
 *  0b1..AXBS_P AHBXL master has high priority
 */
#define IOMUXC_GPR_GPR2_AXBS_L_AHBXL_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_L_AHBXL_HIGH_PRIORITY_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_L_AHBXL_HIGH_PRIORITY_MASK)

#define IOMUXC_GPR_GPR2_AXBS_L_DMA_HIGH_PRIORITY_MASK (0x2U)
#define IOMUXC_GPR_GPR2_AXBS_L_DMA_HIGH_PRIORITY_SHIFT (1U)
/*! AXBS_L_DMA_HIGH_PRIORITY
 *  0b0..AXBS_L DMA master does not have high priority
 *  0b1..AXBS_L DMA master has high priority
 */
#define IOMUXC_GPR_GPR2_AXBS_L_DMA_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_L_DMA_HIGH_PRIORITY_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_L_DMA_HIGH_PRIORITY_MASK)

#define IOMUXC_GPR_GPR2_AXBS_L_FORCE_ROUND_ROBIN_MASK (0x4U)
#define IOMUXC_GPR_GPR2_AXBS_L_FORCE_ROUND_ROBIN_SHIFT (2U)
/*! AXBS_L_FORCE_ROUND_ROBIN
 *  0b0..AXBS_L masters are not arbitored in round robin, depending on DMA and AHBXL master priority settings.
 *  0b1..AXBS_L masters are arbitored in round robin
 */
#define IOMUXC_GPR_GPR2_AXBS_L_FORCE_ROUND_ROBIN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_L_FORCE_ROUND_ROBIN_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_L_FORCE_ROUND_ROBIN_MASK)

#define IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_MASK (0x8U)
#define IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_SHIFT (3U)
/*! AXBS_P_M0_HIGH_PRIORITY
 *  0b0..AXBS_P M0 master doesn't have high priority
 *  0b1..AXBS_P M0 master has high priority
 */
#define IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_MASK)

#define IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_MASK (0x10U)
#define IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_SHIFT (4U)
/*! AXBS_P_M1_HIGH_PRIORITY
 *  0b0..AXBS_P M1 master does not have high priority
 *  0b1..AXBS_P M1 master has high priority
 */
#define IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_MASK)

#define IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_MASK (0x20U)
#define IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_SHIFT (5U)
/*! AXBS_P_FORCE_ROUND_ROBIN
 *  0b0..AXBS_P masters are not arbitored in round robin, depending on M0/M1 master priority settings.
 *  0b1..AXBS_P masters are arbitored in round robin
 */
#define IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_MASK)

#define IOMUXC_GPR_GPR2_CANFD_FILTER_BYPASS_MASK (0x40U)
#define IOMUXC_GPR_GPR2_CANFD_FILTER_BYPASS_SHIFT (6U)
/*! CANFD_FILTER_BYPASS
 *  0b0..enable CANFD filter
 *  0b1..disable CANFD filter
 */
#define IOMUXC_GPR_GPR2_CANFD_FILTER_BYPASS(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_CANFD_FILTER_BYPASS_SHIFT)) & IOMUXC_GPR_GPR2_CANFD_FILTER_BYPASS_MASK)

#define IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_MASK (0x1000U)
#define IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_SHIFT (12U)
/*! L2_MEM_EN_POWERSAVING
 *  0b0..none memory power saving features enabled, SHUTDOWN/DEEPSLEEP/LIGHTSLEEP will have no effect
 *  0b1..memory power saving features enabled, set SHUTDOWN/DEEPSLEEP/LIGHTSLEEP (priority high to low) to enable power saving levels
 */
#define IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_SHIFT)) & IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_MASK)

#define IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_MASK (0x2000U)
#define IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_SHIFT (13U)
/*! RAM_AUTO_CLK_GATING_EN
 *  0b0..disable automatically gate off RAM clock
 *  0b1..enable automatically gate off RAM clock
 */
#define IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_SHIFT)) & IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_MASK)

#define IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_MASK    (0x4000U)
#define IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_SHIFT   (14U)
/*! L2_MEM_DEEPSLEEP
 *  0b0..no force sleep control supported, memory deep sleep mode only entered when whole system in stop mode
 *  0b1..force memory into deep sleep mode
 */
#define IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_SHIFT)) & IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_MASK)

#define IOMUXC_GPR_GPR2_MQS_CLK_DIV_MASK         (0xFF0000U)
#define IOMUXC_GPR_GPR2_MQS_CLK_DIV_SHIFT        (16U)
/*! MQS_CLK_DIV - Divider ratio control for mclk from hmclk. mclk frequency = 1/(n+1) * hmclk frequency.
 *  0b00000000..mclk frequency = 1/1 * hmclk frequency
 *  0b00000001..mclk frequency = 1/2 * hmclk frequency
 *  0b00000010..mclk frequency = 1/3 * hmclk frequency
 *  0b00000011..mclk frequency = 1/4 * hmclk frequency
 *  0b00000100..mclk frequency = 1/5 * hmclk frequency
 *  0b00000101..mclk frequency = 1/6 * hmclk frequency
 *  0b00000110..mclk frequency = 1/7 * hmclk frequency
 *  0b00000111..mclk frequency = 1/8 * hmclk frequency
 *  0b00001000..mclk frequency = 1/9 * hmclk frequency
 *  0b00001001..mclk frequency = 1/10 * hmclk frequency
 *  0b00001010..mclk frequency = 1/11 * hmclk frequency
 *  0b00001011..mclk frequency = 1/12 * hmclk frequency
 *  0b00001100..mclk frequency = 1/13 * hmclk frequency
 *  0b00001101..mclk frequency = 1/14 * hmclk frequency
 *  0b00001110..mclk frequency = 1/15 * hmclk frequency
 *  0b00001111..mclk frequency = 1/16 * hmclk frequency
 *  0b00010000..mclk frequency = 1/17 * hmclk frequency
 *  0b00010001..mclk frequency = 1/18 * hmclk frequency
 *  0b00010010..mclk frequency = 1/19 * hmclk frequency
 *  0b00010011..mclk frequency = 1/20 * hmclk frequency
 *  0b00010100..mclk frequency = 1/21 * hmclk frequency
 *  0b00010101..mclk frequency = 1/22 * hmclk frequency
 *  0b00010110..mclk frequency = 1/23 * hmclk frequency
 *  0b00010111..mclk frequency = 1/24 * hmclk frequency
 *  0b00011000..mclk frequency = 1/25 * hmclk frequency
 *  0b00011001..mclk frequency = 1/26 * hmclk frequency
 *  0b00011010..mclk frequency = 1/27 * hmclk frequency
 *  0b00011011..mclk frequency = 1/28 * hmclk frequency
 *  0b00011100..mclk frequency = 1/29 * hmclk frequency
 *  0b00011101..mclk frequency = 1/30 * hmclk frequency
 *  0b00011110..mclk frequency = 1/31 * hmclk frequency
 *  0b00011111..mclk frequency = 1/32 * hmclk frequency
 *  0b00100000..mclk frequency = 1/33 * hmclk frequency
 *  0b00100001..mclk frequency = 1/34 * hmclk frequency
 *  0b00100010..mclk frequency = 1/35 * hmclk frequency
 *  0b00100011..mclk frequency = 1/36 * hmclk frequency
 *  0b00100100..mclk frequency = 1/37 * hmclk frequency
 *  0b00100101..mclk frequency = 1/38 * hmclk frequency
 *  0b00100110..mclk frequency = 1/39 * hmclk frequency
 *  0b00100111..mclk frequency = 1/40 * hmclk frequency
 *  0b00101000..mclk frequency = 1/41 * hmclk frequency
 *  0b00101001..mclk frequency = 1/42 * hmclk frequency
 *  0b00101010..mclk frequency = 1/43 * hmclk frequency
 *  0b00101011..mclk frequency = 1/44 * hmclk frequency
 *  0b00101100..mclk frequency = 1/45 * hmclk frequency
 *  0b00101101..mclk frequency = 1/46 * hmclk frequency
 *  0b00101110..mclk frequency = 1/47 * hmclk frequency
 *  0b00101111..mclk frequency = 1/48 * hmclk frequency
 *  0b00110000..mclk frequency = 1/49 * hmclk frequency
 *  0b00110001..mclk frequency = 1/50 * hmclk frequency
 *  0b00110010..mclk frequency = 1/51 * hmclk frequency
 *  0b00110011..mclk frequency = 1/52 * hmclk frequency
 *  0b00110100..mclk frequency = 1/53 * hmclk frequency
 *  0b00110101..mclk frequency = 1/54 * hmclk frequency
 *  0b00110110..mclk frequency = 1/55 * hmclk frequency
 *  0b00110111..mclk frequency = 1/56 * hmclk frequency
 *  0b00111000..mclk frequency = 1/57 * hmclk frequency
 *  0b00111001..mclk frequency = 1/58 * hmclk frequency
 *  0b00111010..mclk frequency = 1/59 * hmclk frequency
 *  0b00111011..mclk frequency = 1/60 * hmclk frequency
 *  0b00111100..mclk frequency = 1/61 * hmclk frequency
 *  0b00111101..mclk frequency = 1/62 * hmclk frequency
 *  0b00111110..mclk frequency = 1/63 * hmclk frequency
 *  0b00111111..mclk frequency = 1/64 * hmclk frequency
 *  0b01000000..mclk frequency = 1/65 * hmclk frequency
 *  0b01000001..mclk frequency = 1/66 * hmclk frequency
 *  0b01000010..mclk frequency = 1/67 * hmclk frequency
 *  0b01000011..mclk frequency = 1/68 * hmclk frequency
 *  0b01000100..mclk frequency = 1/69 * hmclk frequency
 *  0b01000101..mclk frequency = 1/70 * hmclk frequency
 *  0b01000110..mclk frequency = 1/71 * hmclk frequency
 *  0b01000111..mclk frequency = 1/72 * hmclk frequency
 *  0b01001000..mclk frequency = 1/73 * hmclk frequency
 *  0b01001001..mclk frequency = 1/74 * hmclk frequency
 *  0b01001010..mclk frequency = 1/75 * hmclk frequency
 *  0b01001011..mclk frequency = 1/76 * hmclk frequency
 *  0b01001100..mclk frequency = 1/77 * hmclk frequency
 *  0b01001101..mclk frequency = 1/78 * hmclk frequency
 *  0b01001110..mclk frequency = 1/79 * hmclk frequency
 *  0b01001111..mclk frequency = 1/80 * hmclk frequency
 *  0b01010000..mclk frequency = 1/81 * hmclk frequency
 *  0b01010001..mclk frequency = 1/82 * hmclk frequency
 *  0b01010010..mclk frequency = 1/83 * hmclk frequency
 *  0b01010011..mclk frequency = 1/84 * hmclk frequency
 *  0b01010100..mclk frequency = 1/85 * hmclk frequency
 *  0b01010101..mclk frequency = 1/86 * hmclk frequency
 *  0b01010110..mclk frequency = 1/87 * hmclk frequency
 *  0b01010111..mclk frequency = 1/88 * hmclk frequency
 *  0b01011000..mclk frequency = 1/89 * hmclk frequency
 *  0b01011001..mclk frequency = 1/90 * hmclk frequency
 *  0b01011010..mclk frequency = 1/91 * hmclk frequency
 *  0b01011011..mclk frequency = 1/92 * hmclk frequency
 *  0b01011100..mclk frequency = 1/93 * hmclk frequency
 *  0b01011101..mclk frequency = 1/94 * hmclk frequency
 *  0b01011110..mclk frequency = 1/95 * hmclk frequency
 *  0b01011111..mclk frequency = 1/96 * hmclk frequency
 *  0b01100000..mclk frequency = 1/97 * hmclk frequency
 *  0b01100001..mclk frequency = 1/98 * hmclk frequency
 *  0b01100010..mclk frequency = 1/99 * hmclk frequency
 *  0b01100011..mclk frequency = 1/100 * hmclk frequency
 *  0b01100100..mclk frequency = 1/101 * hmclk frequency
 *  0b01100101..mclk frequency = 1/102 * hmclk frequency
 *  0b01100110..mclk frequency = 1/103 * hmclk frequency
 *  0b01100111..mclk frequency = 1/104 * hmclk frequency
 *  0b01101000..mclk frequency = 1/105 * hmclk frequency
 *  0b01101001..mclk frequency = 1/106 * hmclk frequency
 *  0b01101010..mclk frequency = 1/107 * hmclk frequency
 *  0b01101011..mclk frequency = 1/108 * hmclk frequency
 *  0b01101100..mclk frequency = 1/109 * hmclk frequency
 *  0b01101101..mclk frequency = 1/110 * hmclk frequency
 *  0b01101110..mclk frequency = 1/111 * hmclk frequency
 *  0b01101111..mclk frequency = 1/112 * hmclk frequency
 *  0b01110000..mclk frequency = 1/113 * hmclk frequency
 *  0b01110001..mclk frequency = 1/114 * hmclk frequency
 *  0b01110010..mclk frequency = 1/115 * hmclk frequency
 *  0b01110011..mclk frequency = 1/116 * hmclk frequency
 *  0b01110100..mclk frequency = 1/117 * hmclk frequency
 *  0b01110101..mclk frequency = 1/118 * hmclk frequency
 *  0b01110110..mclk frequency = 1/119 * hmclk frequency
 *  0b01110111..mclk frequency = 1/120 * hmclk frequency
 *  0b01111000..mclk frequency = 1/121 * hmclk frequency
 *  0b01111001..mclk frequency = 1/122 * hmclk frequency
 *  0b01111010..mclk frequency = 1/123 * hmclk frequency
 *  0b01111011..mclk frequency = 1/124 * hmclk frequency
 *  0b01111100..mclk frequency = 1/125 * hmclk frequency
 *  0b01111101..mclk frequency = 1/126 * hmclk frequency
 *  0b01111110..mclk frequency = 1/127 * hmclk frequency
 *  0b01111111..mclk frequency = 1/128 * hmclk frequency
 *  0b10000000..mclk frequency = 1/129 * hmclk frequency
 *  0b10000001..mclk frequency = 1/130 * hmclk frequency
 *  0b10000010..mclk frequency = 1/131 * hmclk frequency
 *  0b10000011..mclk frequency = 1/132 * hmclk frequency
 *  0b10000100..mclk frequency = 1/133 * hmclk frequency
 *  0b10000101..mclk frequency = 1/134 * hmclk frequency
 *  0b10000110..mclk frequency = 1/135 * hmclk frequency
 *  0b10000111..mclk frequency = 1/136 * hmclk frequency
 *  0b10001000..mclk frequency = 1/137 * hmclk frequency
 *  0b10001001..mclk frequency = 1/138 * hmclk frequency
 *  0b10001010..mclk frequency = 1/139 * hmclk frequency
 *  0b10001011..mclk frequency = 1/140 * hmclk frequency
 *  0b10001100..mclk frequency = 1/141 * hmclk frequency
 *  0b10001101..mclk frequency = 1/142 * hmclk frequency
 *  0b10001110..mclk frequency = 1/143 * hmclk frequency
 *  0b10001111..mclk frequency = 1/144 * hmclk frequency
 *  0b10010000..mclk frequency = 1/145 * hmclk frequency
 *  0b10010001..mclk frequency = 1/146 * hmclk frequency
 *  0b10010010..mclk frequency = 1/147 * hmclk frequency
 *  0b10010011..mclk frequency = 1/148 * hmclk frequency
 *  0b10010100..mclk frequency = 1/149 * hmclk frequency
 *  0b10010101..mclk frequency = 1/150 * hmclk frequency
 *  0b10010110..mclk frequency = 1/151 * hmclk frequency
 *  0b10010111..mclk frequency = 1/152 * hmclk frequency
 *  0b10011000..mclk frequency = 1/153 * hmclk frequency
 *  0b10011001..mclk frequency = 1/154 * hmclk frequency
 *  0b10011010..mclk frequency = 1/155 * hmclk frequency
 *  0b10011011..mclk frequency = 1/156 * hmclk frequency
 *  0b10011100..mclk frequency = 1/157 * hmclk frequency
 *  0b10011101..mclk frequency = 1/158 * hmclk frequency
 *  0b10011110..mclk frequency = 1/159 * hmclk frequency
 *  0b10011111..mclk frequency = 1/160 * hmclk frequency
 *  0b10100000..mclk frequency = 1/161 * hmclk frequency
 *  0b10100001..mclk frequency = 1/162 * hmclk frequency
 *  0b10100010..mclk frequency = 1/163 * hmclk frequency
 *  0b10100011..mclk frequency = 1/164 * hmclk frequency
 *  0b10100100..mclk frequency = 1/165 * hmclk frequency
 *  0b10100101..mclk frequency = 1/166 * hmclk frequency
 *  0b10100110..mclk frequency = 1/167 * hmclk frequency
 *  0b10100111..mclk frequency = 1/168 * hmclk frequency
 *  0b10101000..mclk frequency = 1/169 * hmclk frequency
 *  0b10101001..mclk frequency = 1/170 * hmclk frequency
 *  0b10101010..mclk frequency = 1/171 * hmclk frequency
 *  0b10101011..mclk frequency = 1/172 * hmclk frequency
 *  0b10101100..mclk frequency = 1/173 * hmclk frequency
 *  0b10101101..mclk frequency = 1/174 * hmclk frequency
 *  0b10101110..mclk frequency = 1/175 * hmclk frequency
 *  0b10101111..mclk frequency = 1/176 * hmclk frequency
 *  0b10110000..mclk frequency = 1/177 * hmclk frequency
 *  0b10110001..mclk frequency = 1/178 * hmclk frequency
 *  0b10110010..mclk frequency = 1/179 * hmclk frequency
 *  0b10110011..mclk frequency = 1/180 * hmclk frequency
 *  0b10110100..mclk frequency = 1/181 * hmclk frequency
 *  0b10110101..mclk frequency = 1/182 * hmclk frequency
 *  0b10110110..mclk frequency = 1/183 * hmclk frequency
 *  0b10110111..mclk frequency = 1/184 * hmclk frequency
 *  0b10111000..mclk frequency = 1/185 * hmclk frequency
 *  0b10111001..mclk frequency = 1/186 * hmclk frequency
 *  0b10111010..mclk frequency = 1/187 * hmclk frequency
 *  0b10111011..mclk frequency = 1/188 * hmclk frequency
 *  0b10111100..mclk frequency = 1/189 * hmclk frequency
 *  0b10111101..mclk frequency = 1/190 * hmclk frequency
 *  0b10111110..mclk frequency = 1/191 * hmclk frequency
 *  0b10111111..mclk frequency = 1/192 * hmclk frequency
 *  0b11000000..mclk frequency = 1/193 * hmclk frequency
 *  0b11000001..mclk frequency = 1/194 * hmclk frequency
 *  0b11000010..mclk frequency = 1/195 * hmclk frequency
 *  0b11000011..mclk frequency = 1/196 * hmclk frequency
 *  0b11000100..mclk frequency = 1/197 * hmclk frequency
 *  0b11000101..mclk frequency = 1/198 * hmclk frequency
 *  0b11000110..mclk frequency = 1/199 * hmclk frequency
 *  0b11000111..mclk frequency = 1/200 * hmclk frequency
 *  0b11001000..mclk frequency = 1/201 * hmclk frequency
 *  0b11001001..mclk frequency = 1/202 * hmclk frequency
 *  0b11001010..mclk frequency = 1/203 * hmclk frequency
 *  0b11001011..mclk frequency = 1/204 * hmclk frequency
 *  0b11001100..mclk frequency = 1/205 * hmclk frequency
 *  0b11001101..mclk frequency = 1/206 * hmclk frequency
 *  0b11001110..mclk frequency = 1/207 * hmclk frequency
 *  0b11001111..mclk frequency = 1/208 * hmclk frequency
 *  0b11010000..mclk frequency = 1/209 * hmclk frequency
 *  0b11010001..mclk frequency = 1/210 * hmclk frequency
 *  0b11010010..mclk frequency = 1/211 * hmclk frequency
 *  0b11010011..mclk frequency = 1/212 * hmclk frequency
 *  0b11010100..mclk frequency = 1/213 * hmclk frequency
 *  0b11010101..mclk frequency = 1/214 * hmclk frequency
 *  0b11010110..mclk frequency = 1/215 * hmclk frequency
 *  0b11010111..mclk frequency = 1/216 * hmclk frequency
 *  0b11011000..mclk frequency = 1/217 * hmclk frequency
 *  0b11011001..mclk frequency = 1/218 * hmclk frequency
 *  0b11011010..mclk frequency = 1/219 * hmclk frequency
 *  0b11011011..mclk frequency = 1/220 * hmclk frequency
 *  0b11011100..mclk frequency = 1/221 * hmclk frequency
 *  0b11011101..mclk frequency = 1/222 * hmclk frequency
 *  0b11011110..mclk frequency = 1/223 * hmclk frequency
 *  0b11011111..mclk frequency = 1/224 * hmclk frequency
 *  0b11100000..mclk frequency = 1/225 * hmclk frequency
 *  0b11100001..mclk frequency = 1/226 * hmclk frequency
 *  0b11100010..mclk frequency = 1/227 * hmclk frequency
 *  0b11100011..mclk frequency = 1/228 * hmclk frequency
 *  0b11100100..mclk frequency = 1/229 * hmclk frequency
 *  0b11100101..mclk frequency = 1/230 * hmclk frequency
 *  0b11100110..mclk frequency = 1/231 * hmclk frequency
 *  0b11100111..mclk frequency = 1/232 * hmclk frequency
 *  0b11101000..mclk frequency = 1/233 * hmclk frequency
 *  0b11101001..mclk frequency = 1/234 * hmclk frequency
 *  0b11101010..mclk frequency = 1/235 * hmclk frequency
 *  0b11101011..mclk frequency = 1/236 * hmclk frequency
 *  0b11101100..mclk frequency = 1/237 * hmclk frequency
 *  0b11101101..mclk frequency = 1/238 * hmclk frequency
 *  0b11101110..mclk frequency = 1/239 * hmclk frequency
 *  0b11101111..mclk frequency = 1/240 * hmclk frequency
 *  0b11110000..mclk frequency = 1/241 * hmclk frequency
 *  0b11110001..mclk frequency = 1/242 * hmclk frequency
 *  0b11110010..mclk frequency = 1/243 * hmclk frequency
 *  0b11110011..mclk frequency = 1/244 * hmclk frequency
 *  0b11110100..mclk frequency = 1/245 * hmclk frequency
 *  0b11110101..mclk frequency = 1/246 * hmclk frequency
 *  0b11110110..mclk frequency = 1/247 * hmclk frequency
 *  0b11110111..mclk frequency = 1/248 * hmclk frequency
 *  0b11111000..mclk frequency = 1/249 * hmclk frequency
 *  0b11111001..mclk frequency = 1/250 * hmclk frequency
 *  0b11111010..mclk frequency = 1/251 * hmclk frequency
 *  0b11111011..mclk frequency = 1/252 * hmclk frequency
 *  0b11111100..mclk frequency = 1/253 * hmclk frequency
 *  0b11111101..mclk frequency = 1/254 * hmclk frequency
 *  0b11111110..mclk frequency = 1/255 * hmclk frequency
 *  0b11111111..mclk frequency = 1/256 * hmclk frequency
 */
#define IOMUXC_GPR_GPR2_MQS_CLK_DIV(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_CLK_DIV_SHIFT)) & IOMUXC_GPR_GPR2_MQS_CLK_DIV_MASK)

#define IOMUXC_GPR_GPR2_MQS_SW_RST_MASK          (0x1000000U)
#define IOMUXC_GPR_GPR2_MQS_SW_RST_SHIFT         (24U)
/*! MQS_SW_RST
 *  0b0..Exit software reset for MQS
 *  0b1..Enable software reset for MQS
 */
#define IOMUXC_GPR_GPR2_MQS_SW_RST(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_SW_RST_SHIFT)) & IOMUXC_GPR_GPR2_MQS_SW_RST_MASK)

#define IOMUXC_GPR_GPR2_MQS_EN_MASK              (0x2000000U)
#define IOMUXC_GPR_GPR2_MQS_EN_SHIFT             (25U)
/*! MQS_EN
 *  0b0..Disable MQS
 *  0b1..Enable MQS
 */
#define IOMUXC_GPR_GPR2_MQS_EN(x)                (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_EN_SHIFT)) & IOMUXC_GPR_GPR2_MQS_EN_MASK)

#define IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_MASK      (0x4000000U)
#define IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_SHIFT     (26U)
/*! MQS_OVERSAMPLE
 *  0b0..32
 *  0b1..64
 */
#define IOMUXC_GPR_GPR2_MQS_OVERSAMPLE(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_SHIFT)) & IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_MASK)

#define IOMUXC_GPR_GPR2_QTIMER1_TMR_CNTS_FREEZE_MASK (0x10000000U)
#define IOMUXC_GPR_GPR2_QTIMER1_TMR_CNTS_FREEZE_SHIFT (28U)
/*! QTIMER1_TMR_CNTS_FREEZE
 *  0b0..timer counter work normally
 *  0b1..reset counter and ouput flags
 */
#define IOMUXC_GPR_GPR2_QTIMER1_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_QTIMER1_TMR_CNTS_FREEZE_SHIFT)) & IOMUXC_GPR_GPR2_QTIMER1_TMR_CNTS_FREEZE_MASK)

#define IOMUXC_GPR_GPR2_QTIMER2_TMR_CNTS_FREEZE_MASK (0x20000000U)
#define IOMUXC_GPR_GPR2_QTIMER2_TMR_CNTS_FREEZE_SHIFT (29U)
/*! QTIMER2_TMR_CNTS_FREEZE
 *  0b0..timer counter work normally
 *  0b1..reset counter and ouput flags
 */
#define IOMUXC_GPR_GPR2_QTIMER2_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_QTIMER2_TMR_CNTS_FREEZE_SHIFT)) & IOMUXC_GPR_GPR2_QTIMER2_TMR_CNTS_FREEZE_MASK)

#define IOMUXC_GPR_GPR2_QTIMER3_TMR_CNTS_FREEZE_MASK (0x40000000U)
#define IOMUXC_GPR_GPR2_QTIMER3_TMR_CNTS_FREEZE_SHIFT (30U)
/*! QTIMER3_TMR_CNTS_FREEZE
 *  0b0..timer counter work normally
 *  0b1..reset counter and ouput flags
 */
#define IOMUXC_GPR_GPR2_QTIMER3_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_QTIMER3_TMR_CNTS_FREEZE_SHIFT)) & IOMUXC_GPR_GPR2_QTIMER3_TMR_CNTS_FREEZE_MASK)

#define IOMUXC_GPR_GPR2_QTIMER4_TMR_CNTS_FREEZE_MASK (0x80000000U)
#define IOMUXC_GPR_GPR2_QTIMER4_TMR_CNTS_FREEZE_SHIFT (31U)
/*! QTIMER4_TMR_CNTS_FREEZE
 *  0b0..timer counter work normally
 *  0b1..reset counter and ouput flags
 */
#define IOMUXC_GPR_GPR2_QTIMER4_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_QTIMER4_TMR_CNTS_FREEZE_SHIFT)) & IOMUXC_GPR_GPR2_QTIMER4_TMR_CNTS_FREEZE_MASK)
/*! @} */

/*! @name GPR3 - GPR3 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR3_OCRAM_CTL_MASK           (0xFU)
#define IOMUXC_GPR_GPR3_OCRAM_CTL_SHIFT          (0U)
#define IOMUXC_GPR_GPR3_OCRAM_CTL(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTL_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTL_MASK)

#define IOMUXC_GPR_GPR3_DCP_KEY_SEL_MASK         (0x10U)
#define IOMUXC_GPR_GPR3_DCP_KEY_SEL_SHIFT        (4U)
/*! DCP_KEY_SEL
 *  0b0..Select [127:0] from SNVS Master Key as dcp key
 *  0b1..Select [255:128] from SNVS Master Key as dcp key
 */
#define IOMUXC_GPR_GPR3_DCP_KEY_SEL(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_DCP_KEY_SEL_SHIFT)) & IOMUXC_GPR_GPR3_DCP_KEY_SEL_MASK)

#define IOMUXC_GPR_GPR3_OCRAM2_CTL_MASK          (0xF00U)
#define IOMUXC_GPR_GPR3_OCRAM2_CTL_SHIFT         (8U)
#define IOMUXC_GPR_GPR3_OCRAM2_CTL(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM2_CTL_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM2_CTL_MASK)

#define IOMUXC_GPR_GPR3_AXBS_L_HALT_REQ_MASK     (0x8000U)
#define IOMUXC_GPR_GPR3_AXBS_L_HALT_REQ_SHIFT    (15U)
/*! AXBS_L_HALT_REQ
 *  0b0..axbs_l normal run
 *  0b1..request to halt axbs_l
 */
#define IOMUXC_GPR_GPR3_AXBS_L_HALT_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_AXBS_L_HALT_REQ_SHIFT)) & IOMUXC_GPR_GPR3_AXBS_L_HALT_REQ_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_STATUS_MASK        (0xF0000U)
#define IOMUXC_GPR_GPR3_OCRAM_STATUS_SHIFT       (16U)
#define IOMUXC_GPR_GPR3_OCRAM_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_STATUS_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_STATUS_MASK)

#define IOMUXC_GPR_GPR3_AXBS_L_HALTED_MASK       (0x80000000U)
#define IOMUXC_GPR_GPR3_AXBS_L_HALTED_SHIFT      (31U)
/*! AXBS_L_HALTED
 *  0b0..axbs_l is not halted
 *  0b1..axbs_l is in halted status
 */
#define IOMUXC_GPR_GPR3_AXBS_L_HALTED(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_AXBS_L_HALTED_SHIFT)) & IOMUXC_GPR_GPR3_AXBS_L_HALTED_MASK)
/*! @} */

/*! @name GPR4 - GPR4 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR4_EDMA_STOP_REQ_MASK       (0x1U)
#define IOMUXC_GPR_GPR4_EDMA_STOP_REQ_SHIFT      (0U)
/*! EDMA_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_EDMA_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_EDMA_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_EDMA_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_CAN1_STOP_REQ_MASK       (0x2U)
#define IOMUXC_GPR_GPR4_CAN1_STOP_REQ_SHIFT      (1U)
/*! CAN1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_CAN1_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_CAN1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_CAN1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_CAN2_STOP_REQ_MASK       (0x4U)
#define IOMUXC_GPR_GPR4_CAN2_STOP_REQ_SHIFT      (2U)
/*! CAN2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_CAN2_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_CAN2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_CAN2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_TRNG_STOP_REQ_MASK       (0x8U)
#define IOMUXC_GPR_GPR4_TRNG_STOP_REQ_SHIFT      (3U)
/*! TRNG_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_TRNG_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_TRNG_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_TRNG_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_ENET_STOP_REQ_MASK       (0x10U)
#define IOMUXC_GPR_GPR4_ENET_STOP_REQ_SHIFT      (4U)
/*! ENET_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_ENET_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_ENET_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_ENET_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_SAI1_STOP_REQ_MASK       (0x20U)
#define IOMUXC_GPR_GPR4_SAI1_STOP_REQ_SHIFT      (5U)
/*! SAI1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_SAI1_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_SAI1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_SAI2_STOP_REQ_MASK       (0x40U)
#define IOMUXC_GPR_GPR4_SAI2_STOP_REQ_SHIFT      (6U)
/*! SAI2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_SAI2_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_SAI2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_SAI3_STOP_REQ_MASK       (0x80U)
#define IOMUXC_GPR_GPR4_SAI3_STOP_REQ_SHIFT      (7U)
/*! SAI3_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_SAI3_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI3_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_SAI3_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_ENET2_STOP_REQ_MASK      (0x100U)
#define IOMUXC_GPR_GPR4_ENET2_STOP_REQ_SHIFT     (8U)
/*! ENET2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_ENET2_STOP_REQ(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_ENET2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_ENET2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_SEMC_STOP_REQ_MASK       (0x200U)
#define IOMUXC_GPR_GPR4_SEMC_STOP_REQ_SHIFT      (9U)
/*! SEMC_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_SEMC_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SEMC_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_SEMC_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_PIT_STOP_REQ_MASK        (0x400U)
#define IOMUXC_GPR_GPR4_PIT_STOP_REQ_SHIFT       (10U)
/*! PIT_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_PIT_STOP_REQ(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_PIT_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_PIT_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_MASK    (0x800U)
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_SHIFT   (11U)
/*! FLEXSPI_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_MASK    (0x1000U)
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_SHIFT   (12U)
/*! FLEXIO1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO2_STOP_REQ_MASK    (0x2000U)
#define IOMUXC_GPR_GPR4_FLEXIO2_STOP_REQ_SHIFT   (13U)
/*! FLEXIO2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_FLEXIO2_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO3_STOP_REQ_MASK    (0x4000U)
#define IOMUXC_GPR_GPR4_FLEXIO3_STOP_REQ_SHIFT   (14U)
/*! FLEXIO3_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_FLEXIO3_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO3_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO3_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_FLEXSPI2_STOP_REQ_MASK   (0x8000U)
#define IOMUXC_GPR_GPR4_FLEXSPI2_STOP_REQ_SHIFT  (15U)
/*! FLEXSPI2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_FLEXSPI2_STOP_REQ(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXSPI2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_FLEXSPI2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_EDMA_STOP_ACK_MASK       (0x10000U)
#define IOMUXC_GPR_GPR4_EDMA_STOP_ACK_SHIFT      (16U)
/*! EDMA_STOP_ACK
 *  0b0..EDMA stop acknowledge is not asserted
 *  0b1..EDMA stop acknowledge is asserted (EDMA is in STOP mode).
 */
#define IOMUXC_GPR_GPR4_EDMA_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_EDMA_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_EDMA_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_CAN1_STOP_ACK_MASK       (0x20000U)
#define IOMUXC_GPR_GPR4_CAN1_STOP_ACK_SHIFT      (17U)
/*! CAN1_STOP_ACK
 *  0b0..CAN1 stop acknowledge is not asserted
 *  0b1..CAN1 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_CAN1_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_CAN1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_CAN1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_CAN2_STOP_ACK_MASK       (0x40000U)
#define IOMUXC_GPR_GPR4_CAN2_STOP_ACK_SHIFT      (18U)
/*! CAN2_STOP_ACK
 *  0b0..CAN2 stop acknowledge is not asserted
 *  0b1..CAN2 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_CAN2_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_CAN2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_CAN2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_TRNG_STOP_ACK_MASK       (0x80000U)
#define IOMUXC_GPR_GPR4_TRNG_STOP_ACK_SHIFT      (19U)
/*! TRNG_STOP_ACK
 *  0b0..TRNG stop acknowledge is not asserted
 *  0b1..TRNG stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_TRNG_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_TRNG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_TRNG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_ENET_STOP_ACK_MASK       (0x100000U)
#define IOMUXC_GPR_GPR4_ENET_STOP_ACK_SHIFT      (20U)
/*! ENET_STOP_ACK
 *  0b0..ENET1 stop acknowledge is not asserted
 *  0b1..ENET1 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_ENET_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_ENET_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_ENET_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI1_STOP_ACK_MASK       (0x200000U)
#define IOMUXC_GPR_GPR4_SAI1_STOP_ACK_SHIFT      (21U)
/*! SAI1_STOP_ACK
 *  0b0..SAI1 stop acknowledge is not asserted
 *  0b1..SAI1 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_SAI1_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI2_STOP_ACK_MASK       (0x400000U)
#define IOMUXC_GPR_GPR4_SAI2_STOP_ACK_SHIFT      (22U)
/*! SAI2_STOP_ACK
 *  0b0..SAI2 stop acknowledge is not asserted
 *  0b1..SAI2 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_SAI2_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI3_STOP_ACK_MASK       (0x800000U)
#define IOMUXC_GPR_GPR4_SAI3_STOP_ACK_SHIFT      (23U)
/*! SAI3_STOP_ACK
 *  0b0..SAI3 stop acknowledge is not asserted
 *  0b1..SAI3 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_SAI3_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI3_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI3_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_ENET2_STOP_ACK_MASK      (0x1000000U)
#define IOMUXC_GPR_GPR4_ENET2_STOP_ACK_SHIFT     (24U)
/*! ENET2_STOP_ACK
 *  0b0..ENET2 stop acknowledge is not asserted
 *  0b1..ENET2 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_ENET2_STOP_ACK(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_ENET2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_ENET2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SEMC_STOP_ACK_MASK       (0x2000000U)
#define IOMUXC_GPR_GPR4_SEMC_STOP_ACK_SHIFT      (25U)
/*! SEMC_STOP_ACK
 *  0b0..SEMC stop acknowledge is not asserted
 *  0b1..SEMC stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_SEMC_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SEMC_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SEMC_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_PIT_STOP_ACK_MASK        (0x4000000U)
#define IOMUXC_GPR_GPR4_PIT_STOP_ACK_SHIFT       (26U)
/*! PIT_STOP_ACK
 *  0b0..PIT stop acknowledge is not asserted
 *  0b1..PIT stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_PIT_STOP_ACK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_PIT_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_PIT_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_MASK    (0x8000000U)
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_SHIFT   (27U)
/*! FLEXSPI_STOP_ACK
 *  0b0..FLEXSPI stop acknowledge is not asserted
 *  0b1..FLEXSPI stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_MASK    (0x10000000U)
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_SHIFT   (28U)
/*! FLEXIO1_STOP_ACK
 *  0b0..FLEXIO1 stop acknowledge is not asserted
 *  0b1..FLEXIO1 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO2_STOP_ACK_MASK    (0x20000000U)
#define IOMUXC_GPR_GPR4_FLEXIO2_STOP_ACK_SHIFT   (29U)
/*! FLEXIO2_STOP_ACK
 *  0b0..FLEXIO2 stop acknowledge is not asserted
 *  0b1..FLEXIO2 stop acknowledge is asserted (FLEXIO2 is in STOP mode)
 */
#define IOMUXC_GPR_GPR4_FLEXIO2_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO3_STOP_ACK_MASK    (0x40000000U)
#define IOMUXC_GPR_GPR4_FLEXIO3_STOP_ACK_SHIFT   (30U)
/*! FLEXIO3_STOP_ACK
 *  0b0..FLEXIO3 stop acknowledge is not asserted
 *  0b1..FLEXIO3 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_FLEXIO3_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO3_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO3_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_FLEXSPI2_STOP_ACK_MASK   (0x80000000U)
#define IOMUXC_GPR_GPR4_FLEXSPI2_STOP_ACK_SHIFT  (31U)
/*! FLEXSPI2_STOP_ACK
 *  0b0..FLEXSPI2 stop acknowledge is not asserted
 *  0b1..FLEXSPI2 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_FLEXSPI2_STOP_ACK(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXSPI2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_FLEXSPI2_STOP_ACK_MASK)
/*! @} */

/*! @name GPR5 - GPR5 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR5_WDOG1_MASK_MASK          (0x40U)
#define IOMUXC_GPR_GPR5_WDOG1_MASK_SHIFT         (6U)
/*! WDOG1_MASK
 *  0b0..WDOG1 Timeout behaves normally
 *  0b1..WDOG1 Timeout is masked
 */
#define IOMUXC_GPR_GPR5_WDOG1_MASK(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_WDOG1_MASK_SHIFT)) & IOMUXC_GPR_GPR5_WDOG1_MASK_MASK)

#define IOMUXC_GPR_GPR5_WDOG2_MASK_MASK          (0x80U)
#define IOMUXC_GPR_GPR5_WDOG2_MASK_SHIFT         (7U)
/*! WDOG2_MASK
 *  0b0..WDOG2 Timeout behaves normally
 *  0b1..WDOG2 Timeout is masked
 */
#define IOMUXC_GPR_GPR5_WDOG2_MASK(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_WDOG2_MASK_SHIFT)) & IOMUXC_GPR_GPR5_WDOG2_MASK_MASK)

#define IOMUXC_GPR_GPR5_GPT2_CAPIN1_SEL_MASK     (0x800000U)
#define IOMUXC_GPR_GPR5_GPT2_CAPIN1_SEL_SHIFT    (23U)
/*! GPT2_CAPIN1_SEL
 *  0b0..source from GPT2_CAPTURE1
 *  0b1..source from ENET_1588_EVENT3_OUT (chnnal 3 of IEEE 1588 timer)
 */
#define IOMUXC_GPR_GPR5_GPT2_CAPIN1_SEL(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_GPT2_CAPIN1_SEL_SHIFT)) & IOMUXC_GPR_GPR5_GPT2_CAPIN1_SEL_MASK)

#define IOMUXC_GPR_GPR5_GPT2_CAPIN2_SEL_MASK     (0x1000000U)
#define IOMUXC_GPR_GPR5_GPT2_CAPIN2_SEL_SHIFT    (24U)
/*! GPT2_CAPIN2_SEL
 *  0b0..source from GPT2_CAPTURE2
 *  0b1..source from ENET2_1588_EVENT3_OUT (chnnal 3 of IEEE 1588 timer)
 */
#define IOMUXC_GPR_GPR5_GPT2_CAPIN2_SEL(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_GPT2_CAPIN2_SEL_SHIFT)) & IOMUXC_GPR_GPR5_GPT2_CAPIN2_SEL_MASK)

#define IOMUXC_GPR_GPR5_ENET_EVENT3IN_SEL_MASK   (0x2000000U)
#define IOMUXC_GPR_GPR5_ENET_EVENT3IN_SEL_SHIFT  (25U)
/*! ENET_EVENT3IN_SEL
 *  0b0..event3 source input from ENET_1588_EVENT3_IN
 *  0b1..event3 source input from GPT2.GPT_COMPARE1
 */
#define IOMUXC_GPR_GPR5_ENET_EVENT3IN_SEL(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_ENET_EVENT3IN_SEL_SHIFT)) & IOMUXC_GPR_GPR5_ENET_EVENT3IN_SEL_MASK)

#define IOMUXC_GPR_GPR5_ENET2_EVENT3IN_SEL_MASK  (0x4000000U)
#define IOMUXC_GPR_GPR5_ENET2_EVENT3IN_SEL_SHIFT (26U)
/*! ENET2_EVENT3IN_SEL
 *  0b0..event3 source input from ENET2_1588_EVENT3_IN
 *  0b1..event3 source input from GPT2.GPT_COMPARE2
 */
#define IOMUXC_GPR_GPR5_ENET2_EVENT3IN_SEL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_ENET2_EVENT3IN_SEL_SHIFT)) & IOMUXC_GPR_GPR5_ENET2_EVENT3IN_SEL_MASK)

#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_MASK    (0x10000000U)
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_SHIFT   (28U)
/*! VREF_1M_CLK_GPT1
 *  0b0..GPT1 ipg_clk_highfreq driven by IPG_PERCLK
 *  0b1..GPT1 ipg_clk_highfreq driven by anatop 1 MHz clock
 */
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_SHIFT)) & IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_MASK)

#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_MASK    (0x20000000U)
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_SHIFT   (29U)
/*! VREF_1M_CLK_GPT2
 *  0b0..GPT2 ipg_clk_highfreq driven by IPG_PERCLK
 *  0b1..GPT2 ipg_clk_highfreq driven by anatop 1 MHz clock
 */
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_SHIFT)) & IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_MASK)
/*! @} */

/*! @name GPR6 - GPR6 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL_MASK (0x1U)
#define IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL_SHIFT (0U)
/*! QTIMER1_TRM0_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL_MASK (0x2U)
#define IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL_SHIFT (1U)
/*! QTIMER1_TRM1_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER1_TRM2_INPUT_SEL_MASK (0x4U)
#define IOMUXC_GPR_GPR6_QTIMER1_TRM2_INPUT_SEL_SHIFT (2U)
/*! QTIMER1_TRM2_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER1_TRM2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER1_TRM2_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER1_TRM2_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER1_TRM3_INPUT_SEL_MASK (0x8U)
#define IOMUXC_GPR_GPR6_QTIMER1_TRM3_INPUT_SEL_SHIFT (3U)
/*! QTIMER1_TRM3_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER1_TRM3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER1_TRM3_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER1_TRM3_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER2_TRM0_INPUT_SEL_MASK (0x10U)
#define IOMUXC_GPR_GPR6_QTIMER2_TRM0_INPUT_SEL_SHIFT (4U)
/*! QTIMER2_TRM0_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER2_TRM0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER2_TRM0_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER2_TRM0_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER2_TRM1_INPUT_SEL_MASK (0x20U)
#define IOMUXC_GPR_GPR6_QTIMER2_TRM1_INPUT_SEL_SHIFT (5U)
/*! QTIMER2_TRM1_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER2_TRM1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER2_TRM1_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER2_TRM1_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER2_TRM2_INPUT_SEL_MASK (0x40U)
#define IOMUXC_GPR_GPR6_QTIMER2_TRM2_INPUT_SEL_SHIFT (6U)
/*! QTIMER2_TRM2_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER2_TRM2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER2_TRM2_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER2_TRM2_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER2_TRM3_INPUT_SEL_MASK (0x80U)
#define IOMUXC_GPR_GPR6_QTIMER2_TRM3_INPUT_SEL_SHIFT (7U)
/*! QTIMER2_TRM3_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER2_TRM3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER2_TRM3_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER2_TRM3_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER3_TRM0_INPUT_SEL_MASK (0x100U)
#define IOMUXC_GPR_GPR6_QTIMER3_TRM0_INPUT_SEL_SHIFT (8U)
/*! QTIMER3_TRM0_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER3_TRM0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER3_TRM0_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER3_TRM0_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER3_TRM1_INPUT_SEL_MASK (0x200U)
#define IOMUXC_GPR_GPR6_QTIMER3_TRM1_INPUT_SEL_SHIFT (9U)
/*! QTIMER3_TRM1_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER3_TRM1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER3_TRM1_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER3_TRM1_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER3_TRM2_INPUT_SEL_MASK (0x400U)
#define IOMUXC_GPR_GPR6_QTIMER3_TRM2_INPUT_SEL_SHIFT (10U)
/*! QTIMER3_TRM2_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER3_TRM2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER3_TRM2_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER3_TRM2_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER3_TRM3_INPUT_SEL_MASK (0x800U)
#define IOMUXC_GPR_GPR6_QTIMER3_TRM3_INPUT_SEL_SHIFT (11U)
/*! QTIMER3_TRM3_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER3_TRM3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER3_TRM3_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER3_TRM3_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER4_TRM0_INPUT_SEL_MASK (0x1000U)
#define IOMUXC_GPR_GPR6_QTIMER4_TRM0_INPUT_SEL_SHIFT (12U)
/*! QTIMER4_TRM0_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER4_TRM0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER4_TRM0_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER4_TRM0_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER4_TRM1_INPUT_SEL_MASK (0x2000U)
#define IOMUXC_GPR_GPR6_QTIMER4_TRM1_INPUT_SEL_SHIFT (13U)
/*! QTIMER4_TRM1_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER4_TRM1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER4_TRM1_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER4_TRM1_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER4_TRM2_INPUT_SEL_MASK (0x4000U)
#define IOMUXC_GPR_GPR6_QTIMER4_TRM2_INPUT_SEL_SHIFT (14U)
/*! QTIMER4_TRM2_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER4_TRM2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER4_TRM2_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER4_TRM2_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_QTIMER4_TRM3_INPUT_SEL_MASK (0x8000U)
#define IOMUXC_GPR_GPR6_QTIMER4_TRM3_INPUT_SEL_SHIFT (15U)
/*! QTIMER4_TRM3_INPUT_SEL
 *  0b0..input from IOMUX
 *  0b1..input from XBAR
 */
#define IOMUXC_GPR_GPR6_QTIMER4_TRM3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_QTIMER4_TRM3_INPUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_QTIMER4_TRM3_INPUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_4_MASK (0x10000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_4_SHIFT (16U)
/*! IOMUXC_XBAR_DIR_SEL_4
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_4(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_4_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_4_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_5_MASK (0x20000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_5_SHIFT (17U)
/*! IOMUXC_XBAR_DIR_SEL_5
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_5(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_5_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_5_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_6_MASK (0x40000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_6_SHIFT (18U)
/*! IOMUXC_XBAR_DIR_SEL_6
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_6(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_6_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_6_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7_MASK (0x80000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7_SHIFT (19U)
/*! IOMUXC_XBAR_DIR_SEL_7
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_8_MASK (0x100000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_8_SHIFT (20U)
/*! IOMUXC_XBAR_DIR_SEL_8
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_8(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_8_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_8_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9_MASK (0x200000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9_SHIFT (21U)
/*! IOMUXC_XBAR_DIR_SEL_9
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_10_MASK (0x400000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_10_SHIFT (22U)
/*! IOMUXC_XBAR_DIR_SEL_10
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_10(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_10_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_10_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_11_MASK (0x800000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_11_SHIFT (23U)
/*! IOMUXC_XBAR_DIR_SEL_11
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_11(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_11_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_11_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_12_MASK (0x1000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_12_SHIFT (24U)
/*! IOMUXC_XBAR_DIR_SEL_12
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_12(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_12_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_12_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_13_MASK (0x2000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_13_SHIFT (25U)
/*! IOMUXC_XBAR_DIR_SEL_13
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_13(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_13_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_13_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_14_MASK (0x4000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_14_SHIFT (26U)
/*! IOMUXC_XBAR_DIR_SEL_14
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_14(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_14_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_14_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_15_MASK (0x8000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_15_SHIFT (27U)
/*! IOMUXC_XBAR_DIR_SEL_15
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_15(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_15_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_15_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_16_MASK (0x10000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_16_SHIFT (28U)
/*! IOMUXC_XBAR_DIR_SEL_16
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_16(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_16_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_16_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_17_MASK (0x20000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_17_SHIFT (29U)
/*! IOMUXC_XBAR_DIR_SEL_17
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_17(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_17_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_17_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18_MASK (0x40000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18_SHIFT (30U)
/*! IOMUXC_XBAR_DIR_SEL_18
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_19_MASK (0x80000000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_19_SHIFT (31U)
/*! IOMUXC_XBAR_DIR_SEL_19
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_19(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_19_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_19_MASK)
/*! @} */

/*! @name GPR7 - GPR7 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_MASK     (0x1U)
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_SHIFT    (0U)
/*! LPI2C1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_MASK     (0x2U)
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_SHIFT    (1U)
/*! LPI2C2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPI2C3_STOP_REQ_MASK     (0x4U)
#define IOMUXC_GPR_GPR7_LPI2C3_STOP_REQ_SHIFT    (2U)
/*! LPI2C3_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPI2C3_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C3_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C3_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPI2C4_STOP_REQ_MASK     (0x8U)
#define IOMUXC_GPR_GPR7_LPI2C4_STOP_REQ_SHIFT    (3U)
/*! LPI2C4_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPI2C4_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C4_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C4_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_MASK     (0x10U)
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_SHIFT    (4U)
/*! LPSPI1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_MASK     (0x20U)
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_SHIFT    (5U)
/*! LPSPI2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPSPI4_STOP_REQ_MASK     (0x40U)
#define IOMUXC_GPR_GPR7_LPSPI4_STOP_REQ_SHIFT    (6U)
/*! LPSPI4_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPSPI4_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI4_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI4_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPSPI3_STOP_REQ_MASK     (0x80U)
#define IOMUXC_GPR_GPR7_LPSPI3_STOP_REQ_SHIFT    (7U)
/*! LPSPI3_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPSPI3_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI3_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI3_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_MASK    (0x100U)
#define IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_SHIFT   (8U)
/*! LPUART1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART1_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_MASK    (0x200U)
#define IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_SHIFT   (9U)
/*! LPUART2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART2_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_MASK    (0x400U)
#define IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_SHIFT   (10U)
/*! LPUART3_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART3_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_MASK    (0x800U)
#define IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_SHIFT   (11U)
/*! LPUART4_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART4_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART5_STOP_REQ_MASK    (0x1000U)
#define IOMUXC_GPR_GPR7_LPUART5_STOP_REQ_SHIFT   (12U)
/*! LPUART5_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART5_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART5_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART5_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART6_STOP_REQ_MASK    (0x2000U)
#define IOMUXC_GPR_GPR7_LPUART6_STOP_REQ_SHIFT   (13U)
/*! LPUART6_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART6_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART6_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART6_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART7_STOP_REQ_MASK    (0x4000U)
#define IOMUXC_GPR_GPR7_LPUART7_STOP_REQ_SHIFT   (14U)
/*! LPUART7_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART7_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART7_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART7_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART8_STOP_REQ_MASK    (0x8000U)
#define IOMUXC_GPR_GPR7_LPUART8_STOP_REQ_SHIFT   (15U)
/*! LPUART8_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART8_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART8_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART8_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_MASK     (0x10000U)
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_SHIFT    (16U)
/*! LPI2C1_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted (the module is in Stop mode)
 */
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_MASK     (0x20000U)
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_SHIFT    (17U)
/*! LPI2C2_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPI2C3_STOP_ACK_MASK     (0x40000U)
#define IOMUXC_GPR_GPR7_LPI2C3_STOP_ACK_SHIFT    (18U)
/*! LPI2C3_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPI2C3_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C3_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C3_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPI2C4_STOP_ACK_MASK     (0x80000U)
#define IOMUXC_GPR_GPR7_LPI2C4_STOP_ACK_SHIFT    (19U)
/*! LPI2C4_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPI2C4_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C4_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C4_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_MASK     (0x100000U)
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_SHIFT    (20U)
/*! LPSPI1_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_MASK     (0x200000U)
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_SHIFT    (21U)
/*! LPSPI2_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPSPI4_STOP_ACK_MASK     (0x400000U)
#define IOMUXC_GPR_GPR7_LPSPI4_STOP_ACK_SHIFT    (22U)
/*! LPSPI4_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPSPI4_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI4_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI4_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPSPI3_STOP_ACK_MASK     (0x800000U)
#define IOMUXC_GPR_GPR7_LPSPI3_STOP_ACK_SHIFT    (23U)
/*! LPSPI3_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPSPI3_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI3_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI3_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_MASK    (0x1000000U)
#define IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_SHIFT   (24U)
/*! LPUART1_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART1_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_MASK    (0x2000000U)
#define IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_SHIFT   (25U)
/*! LPUART2_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART2_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_MASK    (0x4000000U)
#define IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_SHIFT   (26U)
/*! LPUART3_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART3_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_MASK    (0x8000000U)
#define IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_SHIFT   (27U)
/*! LPUART4_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART4_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART5_STOP_ACK_MASK    (0x10000000U)
#define IOMUXC_GPR_GPR7_LPUART5_STOP_ACK_SHIFT   (28U)
/*! LPUART5_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART5_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART5_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART5_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART6_STOP_ACK_MASK    (0x20000000U)
#define IOMUXC_GPR_GPR7_LPUART6_STOP_ACK_SHIFT   (29U)
/*! LPUART6_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART6_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART6_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART6_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART7_STOP_ACK_MASK    (0x40000000U)
#define IOMUXC_GPR_GPR7_LPUART7_STOP_ACK_SHIFT   (30U)
/*! LPUART7_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART7_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART7_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART7_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART8_STOP_ACK_MASK    (0x80000000U)
#define IOMUXC_GPR_GPR7_LPUART8_STOP_ACK_SHIFT   (31U)
/*! LPUART8_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted (the module is in Stop mode)
 */
#define IOMUXC_GPR_GPR7_LPUART8_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART8_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART8_STOP_ACK_MASK)
/*! @} */

/*! @name GPR8 - GPR8 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_MASK (0x1U)
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_SHIFT (0U)
/*! LPI2C1_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_MASK     (0x2U)
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_SHIFT    (1U)
/*! LPI2C1_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_MASK (0x4U)
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_SHIFT (2U)
/*! LPI2C2_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_MASK     (0x8U)
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_SHIFT    (3U)
/*! LPI2C2_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C3_IPG_STOP_MODE_MASK (0x10U)
#define IOMUXC_GPR_GPR8_LPI2C3_IPG_STOP_MODE_SHIFT (4U)
/*! LPI2C3_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPI2C3_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C3_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C3_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C3_IPG_DOZE_MASK     (0x20U)
#define IOMUXC_GPR_GPR8_LPI2C3_IPG_DOZE_SHIFT    (5U)
/*! LPI2C3_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPI2C3_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C3_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C3_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C4_IPG_STOP_MODE_MASK (0x40U)
#define IOMUXC_GPR_GPR8_LPI2C4_IPG_STOP_MODE_SHIFT (6U)
/*! LPI2C4_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPI2C4_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C4_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C4_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C4_IPG_DOZE_MASK     (0x80U)
#define IOMUXC_GPR_GPR8_LPI2C4_IPG_DOZE_SHIFT    (7U)
/*! LPI2C4_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPI2C4_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C4_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C4_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_MASK (0x100U)
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_SHIFT (8U)
/*! LPSPI1_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_MASK     (0x200U)
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_SHIFT    (9U)
/*! LPSPI1_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_MASK (0x400U)
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_SHIFT (10U)
/*! LPSPI2_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_MASK     (0x800U)
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_SHIFT    (11U)
/*! LPSPI2_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI4_IPG_STOP_MODE_MASK (0x1000U)
#define IOMUXC_GPR_GPR8_LPSPI4_IPG_STOP_MODE_SHIFT (12U)
/*! LPSPI4_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPSPI4_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI4_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI4_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI4_IPG_DOZE_MASK     (0x2000U)
#define IOMUXC_GPR_GPR8_LPSPI4_IPG_DOZE_SHIFT    (13U)
/*! LPSPI4_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPSPI4_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI4_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI4_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI3_IPG_STOP_MODE_MASK (0x4000U)
#define IOMUXC_GPR_GPR8_LPSPI3_IPG_STOP_MODE_SHIFT (14U)
/*! LPSPI3_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPSPI3_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI3_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI3_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI3_IPG_DOZE_MASK     (0x8000U)
#define IOMUXC_GPR_GPR8_LPSPI3_IPG_DOZE_SHIFT    (15U)
/*! LPSPI3_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPSPI3_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI3_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI3_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_MASK (0x10000U)
#define IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_SHIFT (16U)
/*! LPUART1_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_MASK    (0x20000U)
#define IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_SHIFT   (17U)
/*! LPUART1_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_MASK (0x40000U)
#define IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_SHIFT (18U)
/*! LPUART2_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_MASK    (0x80000U)
#define IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_SHIFT   (19U)
/*! LPUART2_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_MASK (0x100000U)
#define IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_SHIFT (20U)
/*! LPUART3_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_MASK    (0x200000U)
#define IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_SHIFT   (21U)
/*! LPUART3_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_MASK (0x400000U)
#define IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_SHIFT (22U)
/*! LPUART4_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_MASK    (0x800000U)
#define IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_SHIFT   (23U)
/*! LPUART4_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART5_IPG_STOP_MODE_MASK (0x1000000U)
#define IOMUXC_GPR_GPR8_LPUART5_IPG_STOP_MODE_SHIFT (24U)
/*! LPUART5_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART5_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART5_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART5_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART5_IPG_DOZE_MASK    (0x2000000U)
#define IOMUXC_GPR_GPR8_LPUART5_IPG_DOZE_SHIFT   (25U)
/*! LPUART5_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART5_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART5_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART5_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART6_IPG_STOP_MODE_MASK (0x4000000U)
#define IOMUXC_GPR_GPR8_LPUART6_IPG_STOP_MODE_SHIFT (26U)
/*! LPUART6_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART6_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART6_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART6_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART6_IPG_DOZE_MASK    (0x8000000U)
#define IOMUXC_GPR_GPR8_LPUART6_IPG_DOZE_SHIFT   (27U)
/*! LPUART6_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART6_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART6_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART6_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART7_IPG_STOP_MODE_MASK (0x10000000U)
#define IOMUXC_GPR_GPR8_LPUART7_IPG_STOP_MODE_SHIFT (28U)
/*! LPUART7_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART7_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART7_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART7_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART7_IPG_DOZE_MASK    (0x20000000U)
#define IOMUXC_GPR_GPR8_LPUART7_IPG_DOZE_SHIFT   (29U)
/*! LPUART7_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART7_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART7_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART7_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART8_IPG_STOP_MODE_MASK (0x40000000U)
#define IOMUXC_GPR_GPR8_LPUART8_IPG_STOP_MODE_SHIFT (30U)
/*! LPUART8_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART8_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART8_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART8_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART8_IPG_DOZE_MASK    (0x80000000U)
#define IOMUXC_GPR_GPR8_LPUART8_IPG_DOZE_SHIFT   (31U)
/*! LPUART8_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART8_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART8_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART8_IPG_DOZE_MASK)
/*! @} */

/*! @name GPR10 - GPR10 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR10_NIDEN_MASK              (0x1U)
#define IOMUXC_GPR_GPR10_NIDEN_SHIFT             (0U)
/*! NIDEN
 *  0b0..Debug turned off.
 *  0b1..Debug enabled (default).
 */
#define IOMUXC_GPR_GPR10_NIDEN(x)                (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_NIDEN_SHIFT)) & IOMUXC_GPR_GPR10_NIDEN_MASK)

#define IOMUXC_GPR_GPR10_DBG_EN_MASK             (0x2U)
#define IOMUXC_GPR_GPR10_DBG_EN_SHIFT            (1U)
/*! DBG_EN
 *  0b0..Debug turned off.
 *  0b1..Debug enabled (default).
 */
#define IOMUXC_GPR_GPR10_DBG_EN(x)               (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_DBG_EN_SHIFT)) & IOMUXC_GPR_GPR10_DBG_EN_MASK)

#define IOMUXC_GPR_GPR10_SEC_ERR_RESP_MASK       (0x4U)
#define IOMUXC_GPR_GPR10_SEC_ERR_RESP_SHIFT      (2U)
/*! SEC_ERR_RESP
 *  0b0..OKEY response
 *  0b1..SLVError (default)
 */
#define IOMUXC_GPR_GPR10_SEC_ERR_RESP(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_SEC_ERR_RESP_SHIFT)) & IOMUXC_GPR_GPR10_SEC_ERR_RESP_MASK)

#define IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_MASK (0x10U)
#define IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_SHIFT (4U)
/*! DCPKEY_OCOTP_OR_KEYMUX
 *  0b0..Select key from SNVS Master Key.
 *  0b1..Select key from OCOTP (SW_GP2).
 */
#define IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_SHIFT)) & IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_MASK)

#define IOMUXC_GPR_GPR10_OCRAM_TZ_EN_MASK        (0x100U)
#define IOMUXC_GPR_GPR10_OCRAM_TZ_EN_SHIFT       (8U)
/*! OCRAM_TZ_EN
 *  0b0..The TrustZone feature is disabled. Entire OCRAM space is available for all access types (secure/non-secure/user/supervisor).
 *  0b1..The TrustZone feature is enabled. Access to address in the range specified by [ENDADDR:STARTADDR] follows
 *       the execution mode access policy described in CSU chapter.
 */
#define IOMUXC_GPR_GPR10_OCRAM_TZ_EN(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_OCRAM_TZ_EN_SHIFT)) & IOMUXC_GPR_GPR10_OCRAM_TZ_EN_MASK)

#define IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_MASK      (0xFE00U)
#define IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_SHIFT     (9U)
#define IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_SHIFT)) & IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_MASK)

#define IOMUXC_GPR_GPR10_LOCK_NIDEN_MASK         (0x10000U)
#define IOMUXC_GPR_GPR10_LOCK_NIDEN_SHIFT        (16U)
/*! LOCK_NIDEN
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_NIDEN(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_NIDEN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_NIDEN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_DBG_EN_MASK        (0x20000U)
#define IOMUXC_GPR_GPR10_LOCK_DBG_EN_SHIFT       (17U)
/*! LOCK_DBG_EN
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_DBG_EN(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_DBG_EN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_DBG_EN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_MASK  (0x40000U)
#define IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_SHIFT (18U)
/*! LOCK_SEC_ERR_RESP
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_MASK)

#define IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_MASK (0x100000U)
#define IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_SHIFT (20U)
/*! LOCK_DCPKEY_OCOTP_OR_KEYMUX
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_MASK)

#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_MASK   (0x1000000U)
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_SHIFT  (24U)
/*! LOCK_OCRAM_TZ_EN
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_MASK (0xFE000000U)
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_SHIFT (25U)
/*! LOCK_OCRAM_TZ_ADDR
 *  0b0000000..Field is not locked
 *  0b0000001..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_MASK)
/*! @} */

/*! @name GPR11 - GPR11 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_MASK  (0x3U)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_SHIFT (0U)
/*! M7_APC_AC_R0_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_MASK)

#define IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_MASK  (0xCU)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_SHIFT (2U)
/*! M7_APC_AC_R1_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_MASK)

#define IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_MASK  (0x30U)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_SHIFT (4U)
/*! M7_APC_AC_R2_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_MASK)

#define IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_MASK  (0xC0U)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_SHIFT (6U)
/*! M7_APC_AC_R3_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_MASK)

#define IOMUXC_GPR_GPR11_BEE_DE_RX_EN_MASK       (0xF00U)
#define IOMUXC_GPR_GPR11_BEE_DE_RX_EN_SHIFT      (8U)
#define IOMUXC_GPR_GPR11_BEE_DE_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_BEE_DE_RX_EN_SHIFT)) & IOMUXC_GPR_GPR11_BEE_DE_RX_EN_MASK)
/*! @} */

/*! @name GPR12 - GPR12 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_MASK (0x1U)
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_SHIFT (0U)
/*! FLEXIO1_IPG_STOP_MODE
 *  0b0..FlexIO1 is functional in Stop mode.
 *  0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO1 is not functional in Stop mode.
 */
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_MASK   (0x2U)
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_SHIFT  (1U)
/*! FLEXIO1_IPG_DOZE
 *  0b0..FLEXIO1 is not in doze mode
 *  0b1..FLEXIO1 is in doze mode
 */
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR12_FLEXIO2_IPG_STOP_MODE_MASK (0x4U)
#define IOMUXC_GPR_GPR12_FLEXIO2_IPG_STOP_MODE_SHIFT (2U)
/*! FLEXIO2_IPG_STOP_MODE
 *  0b0..FlexIO2 is functional in Stop mode.
 *  0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO2 is not functional in Stop mode.
 */
#define IOMUXC_GPR_GPR12_FLEXIO2_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO2_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO2_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR12_FLEXIO2_IPG_DOZE_MASK   (0x8U)
#define IOMUXC_GPR_GPR12_FLEXIO2_IPG_DOZE_SHIFT  (3U)
/*! FLEXIO2_IPG_DOZE
 *  0b0..FLEXIO2 is not in doze mode
 *  0b1..FLEXIO2 is in doze mode
 */
#define IOMUXC_GPR_GPR12_FLEXIO2_IPG_DOZE(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO2_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO2_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR12_ACMP_IPG_STOP_MODE_MASK (0x10U)
#define IOMUXC_GPR_GPR12_ACMP_IPG_STOP_MODE_SHIFT (4U)
/*! ACMP_IPG_STOP_MODE
 *  0b0..ACMP is functional in Stop mode.
 *  0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, ACMP is not functional in Stop mode.
 */
#define IOMUXC_GPR_GPR12_ACMP_IPG_STOP_MODE(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_ACMP_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR12_ACMP_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR12_FLEXIO3_IPG_STOP_MODE_MASK (0x20U)
#define IOMUXC_GPR_GPR12_FLEXIO3_IPG_STOP_MODE_SHIFT (5U)
/*! FLEXIO3_IPG_STOP_MODE
 *  0b0..FlexIO3 is functional in Stop mode.
 *  0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO3 is not functional in Stop mode.
 */
#define IOMUXC_GPR_GPR12_FLEXIO3_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO3_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO3_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR12_FLEXIO3_IPG_DOZE_MASK   (0x40U)
#define IOMUXC_GPR_GPR12_FLEXIO3_IPG_DOZE_SHIFT  (6U)
/*! FLEXIO3_IPG_DOZE
 *  0b0..FLEXIO3 is not in doze mode
 *  0b1..FLEXIO3 is in doze mode
 */
#define IOMUXC_GPR_GPR12_FLEXIO3_IPG_DOZE(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO3_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO3_IPG_DOZE_MASK)
/*! @} */

/*! @name GPR13 - GPR13 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR13_ARCACHE_USDHC_MASK      (0x1U)
#define IOMUXC_GPR_GPR13_ARCACHE_USDHC_SHIFT     (0U)
/*! ARCACHE_USDHC
 *  0b0..Cacheable attribute is off for read transactions.
 *  0b1..Cacheable attribute is on for read transactions.
 */
#define IOMUXC_GPR_GPR13_ARCACHE_USDHC(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_ARCACHE_USDHC_SHIFT)) & IOMUXC_GPR_GPR13_ARCACHE_USDHC_MASK)

#define IOMUXC_GPR_GPR13_AWCACHE_USDHC_MASK      (0x2U)
#define IOMUXC_GPR_GPR13_AWCACHE_USDHC_SHIFT     (1U)
/*! AWCACHE_USDHC
 *  0b0..Cacheable attribute is off for write transactions.
 *  0b1..Cacheable attribute is on for write transactions.
 */
#define IOMUXC_GPR_GPR13_AWCACHE_USDHC(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_AWCACHE_USDHC_SHIFT)) & IOMUXC_GPR_GPR13_AWCACHE_USDHC_MASK)

#define IOMUXC_GPR_GPR13_CANFD_STOP_REQ_MASK     (0x10U)
#define IOMUXC_GPR_GPR13_CANFD_STOP_REQ_SHIFT    (4U)
/*! CANFD_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR13_CANFD_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_CANFD_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR13_CANFD_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR13_CACHE_ENET_MASK         (0x80U)
#define IOMUXC_GPR_GPR13_CACHE_ENET_SHIFT        (7U)
/*! CACHE_ENET
 *  0b0..Cacheable attribute is off for read/write transactions.
 *  0b1..Cacheable attribute is on for read/write transactions.
 */
#define IOMUXC_GPR_GPR13_CACHE_ENET(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_CACHE_ENET_SHIFT)) & IOMUXC_GPR_GPR13_CACHE_ENET_MASK)

#define IOMUXC_GPR_GPR13_CACHE_USB_MASK          (0x2000U)
#define IOMUXC_GPR_GPR13_CACHE_USB_SHIFT         (13U)
/*! CACHE_USB
 *  0b0..Cacheable attribute is off for read/write transactions.
 *  0b1..Cacheable attribute is on for read/write transactions.
 */
#define IOMUXC_GPR_GPR13_CACHE_USB(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_CACHE_USB_SHIFT)) & IOMUXC_GPR_GPR13_CACHE_USB_MASK)

#define IOMUXC_GPR_GPR13_CANFD_STOP_ACK_MASK     (0x100000U)
#define IOMUXC_GPR_GPR13_CANFD_STOP_ACK_SHIFT    (20U)
/*! CANFD_STOP_ACK
 *  0b0..CANFD stop acknowledge is not asserted
 *  0b1..CANFD stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR13_CANFD_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_CANFD_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR13_CANFD_STOP_ACK_MASK)
/*! @} */

/*! @name GPR14 - GPR14 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_DN_MASK (0x1U)
#define IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_DN_SHIFT (0U)
/*! ACMP1_CMP_IGEN_TRIM_DN
 *  0b0..no reduce
 *  0b1..reduces
 */
#define IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_DN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_DN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_DN_MASK)

#define IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_DN_MASK (0x2U)
#define IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_DN_SHIFT (1U)
/*! ACMP2_CMP_IGEN_TRIM_DN
 *  0b0..no reduce
 *  0b1..reduces
 */
#define IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_DN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_DN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_DN_MASK)

#define IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_DN_MASK (0x4U)
#define IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_DN_SHIFT (2U)
/*! ACMP3_CMP_IGEN_TRIM_DN
 *  0b0..no reduce
 *  0b1..reduces
 */
#define IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_DN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_DN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_DN_MASK)

#define IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_DN_MASK (0x8U)
#define IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_DN_SHIFT (3U)
/*! ACMP4_CMP_IGEN_TRIM_DN
 *  0b0..no reduce
 *  0b1..reduces
 */
#define IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_DN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_DN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_DN_MASK)

#define IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_UP_MASK (0x10U)
#define IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_UP_SHIFT (4U)
/*! ACMP1_CMP_IGEN_TRIM_UP
 *  0b0..no increase
 *  0b1..increases
 */
#define IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_UP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_UP_SHIFT)) & IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_UP_MASK)

#define IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_UP_MASK (0x20U)
#define IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_UP_SHIFT (5U)
/*! ACMP2_CMP_IGEN_TRIM_UP
 *  0b0..no increase
 *  0b1..increases
 */
#define IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_UP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_UP_SHIFT)) & IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_UP_MASK)

#define IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_UP_MASK (0x40U)
#define IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_UP_SHIFT (6U)
/*! ACMP3_CMP_IGEN_TRIM_UP
 *  0b0..no increase
 *  0b1..increases
 */
#define IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_UP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_UP_SHIFT)) & IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_UP_MASK)

#define IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_UP_MASK (0x80U)
#define IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_UP_SHIFT (7U)
/*! ACMP4_CMP_IGEN_TRIM_UP
 *  0b0..no increase
 *  0b1..increases
 */
#define IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_UP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_UP_SHIFT)) & IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_UP_MASK)

#define IOMUXC_GPR_GPR14_ACMP1_SAMPLE_SYNC_EN_MASK (0x100U)
#define IOMUXC_GPR_GPR14_ACMP1_SAMPLE_SYNC_EN_SHIFT (8U)
/*! ACMP1_SAMPLE_SYNC_EN
 *  0b0..select XBAR output
 *  0b1..select synced sample_lv
 */
#define IOMUXC_GPR_GPR14_ACMP1_SAMPLE_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP1_SAMPLE_SYNC_EN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP1_SAMPLE_SYNC_EN_MASK)

#define IOMUXC_GPR_GPR14_ACMP2_SAMPLE_SYNC_EN_MASK (0x200U)
#define IOMUXC_GPR_GPR14_ACMP2_SAMPLE_SYNC_EN_SHIFT (9U)
/*! ACMP2_SAMPLE_SYNC_EN
 *  0b0..select XBAR output
 *  0b1..select synced sample_lv
 */
#define IOMUXC_GPR_GPR14_ACMP2_SAMPLE_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP2_SAMPLE_SYNC_EN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP2_SAMPLE_SYNC_EN_MASK)

#define IOMUXC_GPR_GPR14_ACMP3_SAMPLE_SYNC_EN_MASK (0x400U)
#define IOMUXC_GPR_GPR14_ACMP3_SAMPLE_SYNC_EN_SHIFT (10U)
/*! ACMP3_SAMPLE_SYNC_EN
 *  0b0..select XBAR output
 *  0b1..select synced sample_lv
 */
#define IOMUXC_GPR_GPR14_ACMP3_SAMPLE_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP3_SAMPLE_SYNC_EN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP3_SAMPLE_SYNC_EN_MASK)

#define IOMUXC_GPR_GPR14_ACMP4_SAMPLE_SYNC_EN_MASK (0x800U)
#define IOMUXC_GPR_GPR14_ACMP4_SAMPLE_SYNC_EN_SHIFT (11U)
/*! ACMP4_SAMPLE_SYNC_EN
 *  0b0..select XBAR output
 *  0b1..select synced sample_lv
 */
#define IOMUXC_GPR_GPR14_ACMP4_SAMPLE_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_ACMP4_SAMPLE_SYNC_EN_SHIFT)) & IOMUXC_GPR_GPR14_ACMP4_SAMPLE_SYNC_EN_MASK)
/*! @} */

/*! @name GPR16 - GPR16 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_MASK (0x4U)
#define IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_SHIFT (2U)
/*! FLEXRAM_BANK_CFG_SEL
 *  0b0..use fuse value to config
 *  0b1..use FLEXRAM_BANK_CFG to config
 */
#define IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_SHIFT)) & IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_MASK)

#define IOMUXC_GPR_GPR16_CM7_INIT_VTOR_MASK      (0xFFFFFF80U)
#define IOMUXC_GPR_GPR16_CM7_INIT_VTOR_SHIFT     (7U)
#define IOMUXC_GPR_GPR16_CM7_INIT_VTOR(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR16_CM7_INIT_VTOR_SHIFT)) & IOMUXC_GPR_GPR16_CM7_INIT_VTOR_MASK)
/*! @} */

/*! @name GPR17 - GPR17 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_MASK   (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_SHIFT  (0U)
/*! FLEXRAM_BANK_CFG - FlexRAM bank config value */
#define IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_SHIFT)) & IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_MASK)
/*! @} */

/*! @name GPR18 - GPR18 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R0_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_SHIFT)) & IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_MASK)

#define IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_SHIFT)) & IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_MASK)
/*! @} */

/*! @name GPR19 - GPR19 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R0_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_SHIFT)) & IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_MASK)

#define IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_SHIFT)) & IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_MASK)
/*! @} */

/*! @name GPR20 - GPR20 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R1_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_SHIFT)) & IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_MASK)

#define IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_SHIFT)) & IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_MASK)
/*! @} */

/*! @name GPR21 - GPR21 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R1_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_SHIFT)) & IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_MASK)

#define IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_SHIFT)) & IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_MASK)
/*! @} */

/*! @name GPR22 - GPR22 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R2_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_SHIFT)) & IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_MASK)

#define IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_SHIFT)) & IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_MASK)
/*! @} */

/*! @name GPR23 - GPR23 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R2_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_SHIFT)) & IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_MASK)

#define IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_SHIFT)) & IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_MASK)
/*! @} */

/*! @name GPR24 - GPR24 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R3_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_SHIFT)) & IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_MASK)

#define IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_SHIFT)) & IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_MASK)
/*! @} */

/*! @name GPR25 - GPR25 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R3_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_SHIFT)) & IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_MASK)

#define IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_SHIFT)) & IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_MASK)
/*! @} */

/*! @name GPR26 - GPR26 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_SHIFT (0U)
/*! GPIO_MUX1_GPIO_SEL - GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function. */
#define IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_SHIFT)) & IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK)
/*! @} */

/*! @name GPR27 - GPR27 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_SHIFT (0U)
/*! GPIO_MUX2_GPIO_SEL - GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function. */
#define IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_SHIFT)) & IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK)
/*! @} */

/*! @name GPR28 - GPR28 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR28_GPIO_MUX3_GPIO_SEL_MASK (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR28_GPIO_MUX3_GPIO_SEL_SHIFT (0U)
/*! GPIO_MUX3_GPIO_SEL - GPIO3 and GPIO8 share same IO MUX function, GPIO_MUX3 selects one GPIO function. */
#define IOMUXC_GPR_GPR28_GPIO_MUX3_GPIO_SEL(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR28_GPIO_MUX3_GPIO_SEL_SHIFT)) & IOMUXC_GPR_GPR28_GPIO_MUX3_GPIO_SEL_MASK)
/*! @} */

/*! @name GPR29 - GPR29 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL_MASK (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL_SHIFT (0U)
/*! GPIO_MUX4_GPIO_SEL - GPIO4 and GPIO9 share same IO MUX function, GPIO_MUX4 selects one GPIO function. */
#define IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL_SHIFT)) & IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL_MASK)
/*! @} */

/*! @name GPR30 - GPR30 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR30_FLEXSPI_REMAP_ADDR_START_MASK (0xFFFFF000U)
#define IOMUXC_GPR_GPR30_FLEXSPI_REMAP_ADDR_START_SHIFT (12U)
#define IOMUXC_GPR_GPR30_FLEXSPI_REMAP_ADDR_START(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR30_FLEXSPI_REMAP_ADDR_START_SHIFT)) & IOMUXC_GPR_GPR30_FLEXSPI_REMAP_ADDR_START_MASK)
/*! @} */

/*! @name GPR31 - GPR31 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR31_FLEXSPI_REMAP_ADDR_END_MASK (0xFFFFF000U)
#define IOMUXC_GPR_GPR31_FLEXSPI_REMAP_ADDR_END_SHIFT (12U)
#define IOMUXC_GPR_GPR31_FLEXSPI_REMAP_ADDR_END(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR31_FLEXSPI_REMAP_ADDR_END_SHIFT)) & IOMUXC_GPR_GPR31_FLEXSPI_REMAP_ADDR_END_MASK)
/*! @} */

/*! @name GPR32 - GPR32 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR32_FLEXSPI_REMAP_ADDR_OFFSET_MASK (0xFFFFF000U)
#define IOMUXC_GPR_GPR32_FLEXSPI_REMAP_ADDR_OFFSET_SHIFT (12U)
#define IOMUXC_GPR_GPR32_FLEXSPI_REMAP_ADDR_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR32_FLEXSPI_REMAP_ADDR_OFFSET_SHIFT)) & IOMUXC_GPR_GPR32_FLEXSPI_REMAP_ADDR_OFFSET_MASK)
/*! @} */

/*! @name GPR33 - GPR33 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR33_OCRAM2_TZ_EN_MASK       (0x1U)
#define IOMUXC_GPR_GPR33_OCRAM2_TZ_EN_SHIFT      (0U)
/*! OCRAM2_TZ_EN
 *  0b0..The TrustZone feature is disabled. Entire OCRAM2 space is available for all access types (secure/non-secure/user/supervisor).
 *  0b1..The TrustZone feature is enabled. Access to address in the range specified by [ENDADDR:STARTADDR] follows
 *       the execution mode access policy described in CSU chapter.
 */
#define IOMUXC_GPR_GPR33_OCRAM2_TZ_EN(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR33_OCRAM2_TZ_EN_SHIFT)) & IOMUXC_GPR_GPR33_OCRAM2_TZ_EN_MASK)

#define IOMUXC_GPR_GPR33_OCRAM2_TZ_ADDR_MASK     (0xFEU)
#define IOMUXC_GPR_GPR33_OCRAM2_TZ_ADDR_SHIFT    (1U)
#define IOMUXC_GPR_GPR33_OCRAM2_TZ_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR33_OCRAM2_TZ_ADDR_SHIFT)) & IOMUXC_GPR_GPR33_OCRAM2_TZ_ADDR_MASK)

#define IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_EN_MASK  (0x10000U)
#define IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_EN_SHIFT (16U)
/*! LOCK_OCRAM2_TZ_EN
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_EN(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_EN_SHIFT)) & IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_EN_MASK)

#define IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_ADDR_MASK (0xFE0000U)
#define IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_ADDR_SHIFT (17U)
/*! LOCK_OCRAM2_TZ_ADDR
 *  0b0000000..Field is not locked
 *  0b0000001..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_ADDR_SHIFT)) & IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_ADDR_MASK)
/*! @} */

/*! @name GPR34 - GPR34 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR34_SIP_TEST_MUX_BOOT_PIN_SEL_MASK (0xFFU)
#define IOMUXC_GPR_GPR34_SIP_TEST_MUX_BOOT_PIN_SEL_SHIFT (0U)
/*! SIP_TEST_MUX_BOOT_PIN_SEL - Boot Pin select in SIP_TEST_MUX */
#define IOMUXC_GPR_GPR34_SIP_TEST_MUX_BOOT_PIN_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR34_SIP_TEST_MUX_BOOT_PIN_SEL_SHIFT)) & IOMUXC_GPR_GPR34_SIP_TEST_MUX_BOOT_PIN_SEL_MASK)

#define IOMUXC_GPR_GPR34_SIP_TEST_MUX_QSPI_SIP_EN_MASK (0x100U)
#define IOMUXC_GPR_GPR34_SIP_TEST_MUX_QSPI_SIP_EN_SHIFT (8U)
/*! SIP_TEST_MUX_QSPI_SIP_EN
 *  0b0..SIP_TEST_MUX is disabled
 *  0b1..SIP_TEST_MUX is enabled
 */
#define IOMUXC_GPR_GPR34_SIP_TEST_MUX_QSPI_SIP_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR34_SIP_TEST_MUX_QSPI_SIP_EN_SHIFT)) & IOMUXC_GPR_GPR34_SIP_TEST_MUX_QSPI_SIP_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_GPR_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_GPR_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_IOMUXC_GPR_H_ */

