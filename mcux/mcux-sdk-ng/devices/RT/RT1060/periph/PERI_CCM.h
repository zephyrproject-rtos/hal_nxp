/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CCM
 *
 * CMSIS Peripheral Access Layer for CCM
 */

#if !defined(PERI_CCM_H_)
#define PERI_CCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CCR;                               /**< CCM Control Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t CSR;                               /**< CCM Status Register, offset: 0x8 */
  __IO uint32_t CCSR;                              /**< CCM Clock Switcher Register, offset: 0xC */
  __IO uint32_t CACRR;                             /**< CCM Arm Clock Root Register, offset: 0x10 */
  __IO uint32_t CBCDR;                             /**< CCM Bus Clock Divider Register, offset: 0x14 */
  __IO uint32_t CBCMR;                             /**< CCM Bus Clock Multiplexer Register, offset: 0x18 */
  __IO uint32_t CSCMR1;                            /**< CCM Serial Clock Multiplexer Register 1, offset: 0x1C */
  __IO uint32_t CSCMR2;                            /**< CCM Serial Clock Multiplexer Register 2, offset: 0x20 */
  __IO uint32_t CSCDR1;                            /**< CCM Serial Clock Divider Register 1, offset: 0x24 */
  __IO uint32_t CS1CDR;                            /**< CCM Clock Divider Register, offset: 0x28 */
  __IO uint32_t CS2CDR;                            /**< CCM Clock Divider Register, offset: 0x2C */
  __IO uint32_t CDCDR;                             /**< CCM D1 Clock Divider Register, offset: 0x30 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CSCDR2;                            /**< CCM Serial Clock Divider Register 2, offset: 0x38 */
  __IO uint32_t CSCDR3;                            /**< CCM Serial Clock Divider Register 3, offset: 0x3C */
       uint8_t RESERVED_2[8];
  __I  uint32_t CDHIPR;                            /**< CCM Divider Handshake In-Process Register, offset: 0x48 */
       uint8_t RESERVED_3[8];
  __IO uint32_t CLPCR;                             /**< CCM Low Power Control Register, offset: 0x54 */
  __IO uint32_t CISR;                              /**< CCM Interrupt Status Register, offset: 0x58 */
  __IO uint32_t CIMR;                              /**< CCM Interrupt Mask Register, offset: 0x5C */
  __IO uint32_t CCOSR;                             /**< CCM Clock Output Source Register, offset: 0x60 */
  __IO uint32_t CGPR;                              /**< CCM General Purpose Register, offset: 0x64 */
  __IO uint32_t CCGR0;                             /**< CCM Clock Gating Register 0, offset: 0x68 */
  __IO uint32_t CCGR1;                             /**< CCM Clock Gating Register 1, offset: 0x6C */
  __IO uint32_t CCGR2;                             /**< CCM Clock Gating Register 2, offset: 0x70 */
  __IO uint32_t CCGR3;                             /**< CCM Clock Gating Register 3, offset: 0x74 */
  __IO uint32_t CCGR4;                             /**< CCM Clock Gating Register 4, offset: 0x78 */
  __IO uint32_t CCGR5;                             /**< CCM Clock Gating Register 5, offset: 0x7C */
  __IO uint32_t CCGR6;                             /**< CCM Clock Gating Register 6, offset: 0x80 */
  __IO uint32_t CCGR7;                             /**< CCM Clock Gating Register 7, offset: 0x84 */
  __IO uint32_t CMEOR;                             /**< CCM Module Enable Overide Register, offset: 0x88 */
} CCM_Type;

/* ----------------------------------------------------------------------------
   -- CCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Register_Masks CCM Register Masks
 * @{
 */

/*! @name CCR - CCM Control Register */
/*! @{ */

#define CCM_CCR_OSCNT_MASK                       (0xFFU)
#define CCM_CCR_OSCNT_SHIFT                      (0U)
/*! OSCNT - Oscillator ready counter value. These bits define value of 32KHz counter, that serve as
 *    counter for oscillator lock time (count to n+1 ckil's). This is used for oscillator lock time.
 *    Current estimation is ~5ms. This counter will be used in ignition sequence and in wake from
 *    stop sequence if sbyos bit was defined, to notify that on chip oscillator output is ready for
 *    the dpll_ip to use and only then the gate in dpll_ip can be opened.
 */
#define CCM_CCR_OSCNT(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCR_OSCNT_SHIFT)) & CCM_CCR_OSCNT_MASK)

#define CCM_CCR_COSC_EN_MASK                     (0x1000U)
#define CCM_CCR_COSC_EN_SHIFT                    (12U)
/*! COSC_EN
 *  0b0..disable on chip oscillator
 *  0b1..enable on chip oscillator
 */
#define CCM_CCR_COSC_EN(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_CCR_COSC_EN_SHIFT)) & CCM_CCR_COSC_EN_MASK)

#define CCM_CCR_REG_BYPASS_COUNT_MASK            (0x7E00000U)
#define CCM_CCR_REG_BYPASS_COUNT_SHIFT           (21U)
/*! REG_BYPASS_COUNT
 *  0b000000..no delay
 *  0b000001..1 CKIL clock period delay
 *  0b111111..63 CKIL clock periods delay
 */
#define CCM_CCR_REG_BYPASS_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CCR_REG_BYPASS_COUNT_SHIFT)) & CCM_CCR_REG_BYPASS_COUNT_MASK)

#define CCM_CCR_RBC_EN_MASK                      (0x8000000U)
#define CCM_CCR_RBC_EN_SHIFT                     (27U)
/*! RBC_EN
 *  0b0..REG_BYPASS_COUNTER disabled
 *  0b1..REG_BYPASS_COUNTER enabled.
 */
#define CCM_CCR_RBC_EN(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCR_RBC_EN_SHIFT)) & CCM_CCR_RBC_EN_MASK)
/*! @} */

/*! @name CSR - CCM Status Register */
/*! @{ */

#define CCM_CSR_REF_EN_B_MASK                    (0x1U)
#define CCM_CSR_REF_EN_B_SHIFT                   (0U)
/*! REF_EN_B
 *  0b0..value of CCM_REF_EN_B is '0'
 *  0b1..value of CCM_REF_EN_B is '1'
 */
#define CCM_CSR_REF_EN_B(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_CSR_REF_EN_B_SHIFT)) & CCM_CSR_REF_EN_B_MASK)

#define CCM_CSR_CAMP2_READY_MASK                 (0x8U)
#define CCM_CSR_CAMP2_READY_SHIFT                (3U)
/*! CAMP2_READY
 *  0b0..CAMP2 is not ready.
 *  0b1..CAMP2 is ready.
 */
#define CCM_CSR_CAMP2_READY(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CSR_CAMP2_READY_SHIFT)) & CCM_CSR_CAMP2_READY_MASK)

#define CCM_CSR_COSC_READY_MASK                  (0x20U)
#define CCM_CSR_COSC_READY_SHIFT                 (5U)
/*! COSC_READY
 *  0b0..on board oscillator is not ready.
 *  0b1..on board oscillator is ready.
 */
#define CCM_CSR_COSC_READY(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CSR_COSC_READY_SHIFT)) & CCM_CSR_COSC_READY_MASK)
/*! @} */

/*! @name CCSR - CCM Clock Switcher Register */
/*! @{ */

#define CCM_CCSR_PLL3_SW_CLK_SEL_MASK            (0x1U)
#define CCM_CCSR_PLL3_SW_CLK_SEL_SHIFT           (0U)
/*! PLL3_SW_CLK_SEL
 *  0b0..pll3_main_clk
 *  0b1..pll3 bypass clock
 */
#define CCM_CCSR_PLL3_SW_CLK_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CCSR_PLL3_SW_CLK_SEL_SHIFT)) & CCM_CCSR_PLL3_SW_CLK_SEL_MASK)
/*! @} */

/*! @name CACRR - CCM Arm Clock Root Register */
/*! @{ */

#define CCM_CACRR_ARM_PODF_MASK                  (0x7U)
#define CCM_CACRR_ARM_PODF_SHIFT                 (0U)
/*! ARM_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CACRR_ARM_PODF(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CACRR_ARM_PODF_SHIFT)) & CCM_CACRR_ARM_PODF_MASK)
/*! @} */

/*! @name CBCDR - CCM Bus Clock Divider Register */
/*! @{ */

#define CCM_CBCDR_SEMC_CLK_SEL_MASK              (0x40U)
#define CCM_CBCDR_SEMC_CLK_SEL_SHIFT             (6U)
/*! SEMC_CLK_SEL
 *  0b0..Periph_clk output will be used as SEMC clock root
 *  0b1..SEMC alternative clock will be used as SEMC clock root
 */
#define CCM_CBCDR_SEMC_CLK_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CBCDR_SEMC_CLK_SEL_SHIFT)) & CCM_CBCDR_SEMC_CLK_SEL_MASK)

#define CCM_CBCDR_SEMC_ALT_CLK_SEL_MASK          (0x80U)
#define CCM_CBCDR_SEMC_ALT_CLK_SEL_SHIFT         (7U)
/*! SEMC_ALT_CLK_SEL
 *  0b0..PLL2 PFD2 will be selected as alternative clock for SEMC root clock
 *  0b1..PLL3 PFD1 will be selected as alternative clock for SEMC root clock
 */
#define CCM_CBCDR_SEMC_ALT_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CBCDR_SEMC_ALT_CLK_SEL_SHIFT)) & CCM_CBCDR_SEMC_ALT_CLK_SEL_MASK)

#define CCM_CBCDR_IPG_PODF_MASK                  (0x300U)
#define CCM_CBCDR_IPG_PODF_SHIFT                 (8U)
/*! IPG_PODF
 *  0b00..divide by 1
 *  0b01..divide by 2
 *  0b10..divide by 3
 *  0b11..divide by 4
 */
#define CCM_CBCDR_IPG_PODF(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CBCDR_IPG_PODF_SHIFT)) & CCM_CBCDR_IPG_PODF_MASK)

#define CCM_CBCDR_AHB_PODF_MASK                  (0x1C00U)
#define CCM_CBCDR_AHB_PODF_SHIFT                 (10U)
/*! AHB_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CBCDR_AHB_PODF(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CBCDR_AHB_PODF_SHIFT)) & CCM_CBCDR_AHB_PODF_MASK)

#define CCM_CBCDR_SEMC_PODF_MASK                 (0x70000U)
#define CCM_CBCDR_SEMC_PODF_SHIFT                (16U)
/*! SEMC_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CBCDR_SEMC_PODF(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CBCDR_SEMC_PODF_SHIFT)) & CCM_CBCDR_SEMC_PODF_MASK)

#define CCM_CBCDR_PERIPH_CLK_SEL_MASK            (0x2000000U)
#define CCM_CBCDR_PERIPH_CLK_SEL_SHIFT           (25U)
/*! PERIPH_CLK_SEL
 *  0b0..derive clock from pre_periph_clk_sel
 *  0b1..derive clock from periph_clk2_clk_divided
 */
#define CCM_CBCDR_PERIPH_CLK_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CBCDR_PERIPH_CLK_SEL_SHIFT)) & CCM_CBCDR_PERIPH_CLK_SEL_MASK)

#define CCM_CBCDR_PERIPH_CLK2_PODF_MASK          (0x38000000U)
#define CCM_CBCDR_PERIPH_CLK2_PODF_SHIFT         (27U)
/*! PERIPH_CLK2_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CBCDR_PERIPH_CLK2_PODF(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CBCDR_PERIPH_CLK2_PODF_SHIFT)) & CCM_CBCDR_PERIPH_CLK2_PODF_MASK)
/*! @} */

/*! @name CBCMR - CCM Bus Clock Multiplexer Register */
/*! @{ */

#define CCM_CBCMR_LPSPI_CLK_SEL_MASK             (0x30U)
#define CCM_CBCMR_LPSPI_CLK_SEL_SHIFT            (4U)
/*! LPSPI_CLK_SEL
 *  0b00..derive clock from PLL3 PFD1 clk
 *  0b01..derive clock from PLL3 PFD0
 *  0b10..derive clock from PLL2
 *  0b11..derive clock from PLL2 PFD2
 */
#define CCM_CBCMR_LPSPI_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_LPSPI_CLK_SEL_SHIFT)) & CCM_CBCMR_LPSPI_CLK_SEL_MASK)

#define CCM_CBCMR_FLEXSPI2_CLK_SEL_MASK          (0x300U)
#define CCM_CBCMR_FLEXSPI2_CLK_SEL_SHIFT         (8U)
/*! FLEXSPI2_CLK_SEL
 *  0b00..derive clock from PLL2 PFD2
 *  0b01..derive clock from PLL3 PFD0
 *  0b10..derive clock from PLL3 PFD1
 *  0b11..derive clock from PLL2 (pll2_main_clk)
 */
#define CCM_CBCMR_FLEXSPI2_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_FLEXSPI2_CLK_SEL_SHIFT)) & CCM_CBCMR_FLEXSPI2_CLK_SEL_MASK)

#define CCM_CBCMR_PERIPH_CLK2_SEL_MASK           (0x3000U)
#define CCM_CBCMR_PERIPH_CLK2_SEL_SHIFT          (12U)
/*! PERIPH_CLK2_SEL
 *  0b00..derive clock from pll3_sw_clk
 *  0b01..derive clock from osc_clk (pll1_ref_clk)
 *  0b10..derive clock from pll2_bypass_clk
 *  0b11..reserved
 */
#define CCM_CBCMR_PERIPH_CLK2_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_PERIPH_CLK2_SEL_SHIFT)) & CCM_CBCMR_PERIPH_CLK2_SEL_MASK)

#define CCM_CBCMR_TRACE_CLK_SEL_MASK             (0xC000U)
#define CCM_CBCMR_TRACE_CLK_SEL_SHIFT            (14U)
/*! TRACE_CLK_SEL
 *  0b00..derive clock from PLL2
 *  0b01..derive clock from PLL2 PFD2
 *  0b10..derive clock from PLL2 PFD0
 *  0b11..derive clock from PLL2 PFD1
 */
#define CCM_CBCMR_TRACE_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_TRACE_CLK_SEL_SHIFT)) & CCM_CBCMR_TRACE_CLK_SEL_MASK)

#define CCM_CBCMR_PRE_PERIPH_CLK_SEL_MASK        (0xC0000U)
#define CCM_CBCMR_PRE_PERIPH_CLK_SEL_SHIFT       (18U)
/*! PRE_PERIPH_CLK_SEL
 *  0b00..derive clock from PLL2
 *  0b01..derive clock from PLL2 PFD2
 *  0b10..derive clock from PLL2 PFD0
 *  0b11..derive clock from divided PLL1
 */
#define CCM_CBCMR_PRE_PERIPH_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_PRE_PERIPH_CLK_SEL_SHIFT)) & CCM_CBCMR_PRE_PERIPH_CLK_SEL_MASK)

#define CCM_CBCMR_LCDIF_PODF_MASK                (0x3800000U)
#define CCM_CBCMR_LCDIF_PODF_SHIFT               (23U)
/*! LCDIF_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CBCMR_LCDIF_PODF(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_LCDIF_PODF_SHIFT)) & CCM_CBCMR_LCDIF_PODF_MASK)

#define CCM_CBCMR_LPSPI_PODF_MASK                (0x1C000000U)
#define CCM_CBCMR_LPSPI_PODF_SHIFT               (26U)
/*! LPSPI_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CBCMR_LPSPI_PODF(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_LPSPI_PODF_SHIFT)) & CCM_CBCMR_LPSPI_PODF_MASK)

#define CCM_CBCMR_FLEXSPI2_PODF_MASK             (0xE0000000U)
#define CCM_CBCMR_FLEXSPI2_PODF_SHIFT            (29U)
/*! FLEXSPI2_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CBCMR_FLEXSPI2_PODF(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CBCMR_FLEXSPI2_PODF_SHIFT)) & CCM_CBCMR_FLEXSPI2_PODF_MASK)
/*! @} */

/*! @name CSCMR1 - CCM Serial Clock Multiplexer Register 1 */
/*! @{ */

#define CCM_CSCMR1_PERCLK_PODF_MASK              (0x3FU)
#define CCM_CSCMR1_PERCLK_PODF_SHIFT             (0U)
/*! PERCLK_PODF - Divider for perclk podf.
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b000110..Divide by 7
 *  0b000111..Divide by 8
 *  0b001000..Divide by 9
 *  0b001001..Divide by 10
 *  0b001010..Divide by 11
 *  0b001011..Divide by 12
 *  0b001100..Divide by 13
 *  0b001101..Divide by 14
 *  0b001110..Divide by 15
 *  0b001111..Divide by 16
 *  0b010000..Divide by 17
 *  0b010001..Divide by 18
 *  0b010010..Divide by 19
 *  0b010011..Divide by 20
 *  0b010100..Divide by 21
 *  0b010101..Divide by 22
 *  0b010110..Divide by 23
 *  0b010111..Divide by 24
 *  0b011000..Divide by 25
 *  0b011001..Divide by 26
 *  0b011010..Divide by 27
 *  0b011011..Divide by 28
 *  0b011100..Divide by 29
 *  0b011101..Divide by 30
 *  0b011110..Divide by 31
 *  0b011111..Divide by 32
 *  0b100000..Divide by 33
 *  0b100001..Divide by 34
 *  0b100010..Divide by 35
 *  0b100011..Divide by 36
 *  0b100100..Divide by 37
 *  0b100101..Divide by 38
 *  0b100110..Divide by 39
 *  0b100111..Divide by 40
 *  0b101000..Divide by 41
 *  0b101001..Divide by 42
 *  0b101010..Divide by 43
 *  0b101011..Divide by 44
 *  0b101100..Divide by 45
 *  0b101101..Divide by 46
 *  0b101110..Divide by 47
 *  0b101111..Divide by 48
 *  0b110000..Divide by 49
 *  0b110001..Divide by 50
 *  0b110010..Divide by 51
 *  0b110011..Divide by 52
 *  0b110100..Divide by 53
 *  0b110101..Divide by 54
 *  0b110110..Divide by 55
 *  0b110111..Divide by 56
 *  0b111000..Divide by 57
 *  0b111001..Divide by 58
 *  0b111010..Divide by 59
 *  0b111011..Divide by 60
 *  0b111100..Divide by 61
 *  0b111101..Divide by 62
 *  0b111110..Divide by 63
 *  0b111111..Divide by 64
 */
#define CCM_CSCMR1_PERCLK_PODF(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_PERCLK_PODF_SHIFT)) & CCM_CSCMR1_PERCLK_PODF_MASK)

#define CCM_CSCMR1_PERCLK_CLK_SEL_MASK           (0x40U)
#define CCM_CSCMR1_PERCLK_CLK_SEL_SHIFT          (6U)
/*! PERCLK_CLK_SEL
 *  0b0..derive clock from ipg clk root
 *  0b1..derive clock from osc_clk
 */
#define CCM_CSCMR1_PERCLK_CLK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_PERCLK_CLK_SEL_SHIFT)) & CCM_CSCMR1_PERCLK_CLK_SEL_MASK)

#define CCM_CSCMR1_SAI1_CLK_SEL_MASK             (0xC00U)
#define CCM_CSCMR1_SAI1_CLK_SEL_SHIFT            (10U)
/*! SAI1_CLK_SEL
 *  0b00..derive clock from PLL3 PFD2
 *  0b01..derive clock from PLL5
 *  0b10..derive clock from PLL4
 *  0b11..Reserved
 */
#define CCM_CSCMR1_SAI1_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_SAI1_CLK_SEL_SHIFT)) & CCM_CSCMR1_SAI1_CLK_SEL_MASK)

#define CCM_CSCMR1_SAI2_CLK_SEL_MASK             (0x3000U)
#define CCM_CSCMR1_SAI2_CLK_SEL_SHIFT            (12U)
/*! SAI2_CLK_SEL
 *  0b00..derive clock from PLL3 PFD2
 *  0b01..derive clock from PLL5
 *  0b10..derive clock from PLL4
 *  0b11..Reserved
 */
#define CCM_CSCMR1_SAI2_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_SAI2_CLK_SEL_SHIFT)) & CCM_CSCMR1_SAI2_CLK_SEL_MASK)

#define CCM_CSCMR1_SAI3_CLK_SEL_MASK             (0xC000U)
#define CCM_CSCMR1_SAI3_CLK_SEL_SHIFT            (14U)
/*! SAI3_CLK_SEL
 *  0b00..derive clock from PLL3 PFD2
 *  0b01..derive clock from PLL5
 *  0b10..derive clock from PLL4
 *  0b11..Reserved
 */
#define CCM_CSCMR1_SAI3_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_SAI3_CLK_SEL_SHIFT)) & CCM_CSCMR1_SAI3_CLK_SEL_MASK)

#define CCM_CSCMR1_USDHC1_CLK_SEL_MASK           (0x10000U)
#define CCM_CSCMR1_USDHC1_CLK_SEL_SHIFT          (16U)
/*! USDHC1_CLK_SEL
 *  0b0..derive clock from PLL2 PFD2
 *  0b1..derive clock from PLL2 PFD0
 */
#define CCM_CSCMR1_USDHC1_CLK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_USDHC1_CLK_SEL_SHIFT)) & CCM_CSCMR1_USDHC1_CLK_SEL_MASK)

#define CCM_CSCMR1_USDHC2_CLK_SEL_MASK           (0x20000U)
#define CCM_CSCMR1_USDHC2_CLK_SEL_SHIFT          (17U)
/*! USDHC2_CLK_SEL
 *  0b0..derive clock from PLL2 PFD2
 *  0b1..derive clock from PLL2 PFD0
 */
#define CCM_CSCMR1_USDHC2_CLK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_USDHC2_CLK_SEL_SHIFT)) & CCM_CSCMR1_USDHC2_CLK_SEL_MASK)

#define CCM_CSCMR1_FLEXSPI_PODF_MASK             (0x3800000U)
#define CCM_CSCMR1_FLEXSPI_PODF_SHIFT            (23U)
/*! FLEXSPI_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CSCMR1_FLEXSPI_PODF(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_FLEXSPI_PODF_SHIFT)) & CCM_CSCMR1_FLEXSPI_PODF_MASK)

#define CCM_CSCMR1_FLEXSPI_CLK_SEL_MASK          (0x60000000U)
#define CCM_CSCMR1_FLEXSPI_CLK_SEL_SHIFT         (29U)
/*! FLEXSPI_CLK_SEL
 *  0b00..derive clock from semc_clk_root_pre
 *  0b01..derive clock from pll3_sw_clk
 *  0b10..derive clock from PLL2 PFD2
 *  0b11..derive clock from PLL3 PFD0
 */
#define CCM_CSCMR1_FLEXSPI_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR1_FLEXSPI_CLK_SEL_SHIFT)) & CCM_CSCMR1_FLEXSPI_CLK_SEL_MASK)
/*! @} */

/*! @name CSCMR2 - CCM Serial Clock Multiplexer Register 2 */
/*! @{ */

#define CCM_CSCMR2_CAN_CLK_PODF_MASK             (0xFCU)
#define CCM_CSCMR2_CAN_CLK_PODF_SHIFT            (2U)
/*! CAN_CLK_PODF - Divider for CAN/CANFD clock podf.
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b000110..Divide by 7
 *  0b000111..Divide by 8
 *  0b001000..Divide by 9
 *  0b001001..Divide by 10
 *  0b001010..Divide by 11
 *  0b001011..Divide by 12
 *  0b001100..Divide by 13
 *  0b001101..Divide by 14
 *  0b001110..Divide by 15
 *  0b001111..Divide by 16
 *  0b010000..Divide by 17
 *  0b010001..Divide by 18
 *  0b010010..Divide by 19
 *  0b010011..Divide by 20
 *  0b010100..Divide by 21
 *  0b010101..Divide by 22
 *  0b010110..Divide by 23
 *  0b010111..Divide by 24
 *  0b011000..Divide by 25
 *  0b011001..Divide by 26
 *  0b011010..Divide by 27
 *  0b011011..Divide by 28
 *  0b011100..Divide by 29
 *  0b011101..Divide by 30
 *  0b011110..Divide by 31
 *  0b011111..Divide by 32
 *  0b100000..Divide by 33
 *  0b100001..Divide by 34
 *  0b100010..Divide by 35
 *  0b100011..Divide by 36
 *  0b100100..Divide by 37
 *  0b100101..Divide by 38
 *  0b100110..Divide by 39
 *  0b100111..Divide by 40
 *  0b101000..Divide by 41
 *  0b101001..Divide by 42
 *  0b101010..Divide by 43
 *  0b101011..Divide by 44
 *  0b101100..Divide by 45
 *  0b101101..Divide by 46
 *  0b101110..Divide by 47
 *  0b101111..Divide by 48
 *  0b110000..Divide by 49
 *  0b110001..Divide by 50
 *  0b110010..Divide by 51
 *  0b110011..Divide by 52
 *  0b110100..Divide by 53
 *  0b110101..Divide by 54
 *  0b110110..Divide by 55
 *  0b110111..Divide by 56
 *  0b111000..Divide by 57
 *  0b111001..Divide by 58
 *  0b111010..Divide by 59
 *  0b111011..Divide by 60
 *  0b111100..Divide by 61
 *  0b111101..Divide by 62
 *  0b111110..Divide by 63
 *  0b111111..Divide by 64
 */
#define CCM_CSCMR2_CAN_CLK_PODF(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR2_CAN_CLK_PODF_SHIFT)) & CCM_CSCMR2_CAN_CLK_PODF_MASK)

#define CCM_CSCMR2_CAN_CLK_SEL_MASK              (0x300U)
#define CCM_CSCMR2_CAN_CLK_SEL_SHIFT             (8U)
/*! CAN_CLK_SEL
 *  0b00..derive clock from pll3_sw_clk divided clock (60M)
 *  0b01..derive clock from osc_clk (24M)
 *  0b10..derive clock from pll3_sw_clk divided clock (80M)
 *  0b11..Disable FlexCAN clock
 */
#define CCM_CSCMR2_CAN_CLK_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR2_CAN_CLK_SEL_SHIFT)) & CCM_CSCMR2_CAN_CLK_SEL_MASK)

#define CCM_CSCMR2_FLEXIO2_CLK_SEL_MASK          (0x180000U)
#define CCM_CSCMR2_FLEXIO2_CLK_SEL_SHIFT         (19U)
/*! FLEXIO2_CLK_SEL
 *  0b00..derive clock from PLL4 divided clock
 *  0b01..derive clock from PLL3 PFD2 clock
 *  0b10..derive clock from PLL5 clock
 *  0b11..derive clock from pll3_sw_clk
 */
#define CCM_CSCMR2_FLEXIO2_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CSCMR2_FLEXIO2_CLK_SEL_SHIFT)) & CCM_CSCMR2_FLEXIO2_CLK_SEL_MASK)
/*! @} */

/*! @name CSCDR1 - CCM Serial Clock Divider Register 1 */
/*! @{ */

#define CCM_CSCDR1_UART_CLK_PODF_MASK            (0x3FU)
#define CCM_CSCDR1_UART_CLK_PODF_SHIFT           (0U)
/*! UART_CLK_PODF - Divider for uart clock podf.
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b000110..Divide by 7
 *  0b000111..Divide by 8
 *  0b001000..Divide by 9
 *  0b001001..Divide by 10
 *  0b001010..Divide by 11
 *  0b001011..Divide by 12
 *  0b001100..Divide by 13
 *  0b001101..Divide by 14
 *  0b001110..Divide by 15
 *  0b001111..Divide by 16
 *  0b010000..Divide by 17
 *  0b010001..Divide by 18
 *  0b010010..Divide by 19
 *  0b010011..Divide by 20
 *  0b010100..Divide by 21
 *  0b010101..Divide by 22
 *  0b010110..Divide by 23
 *  0b010111..Divide by 24
 *  0b011000..Divide by 25
 *  0b011001..Divide by 26
 *  0b011010..Divide by 27
 *  0b011011..Divide by 28
 *  0b011100..Divide by 29
 *  0b011101..Divide by 30
 *  0b011110..Divide by 31
 *  0b011111..Divide by 32
 *  0b100000..Divide by 33
 *  0b100001..Divide by 34
 *  0b100010..Divide by 35
 *  0b100011..Divide by 36
 *  0b100100..Divide by 37
 *  0b100101..Divide by 38
 *  0b100110..Divide by 39
 *  0b100111..Divide by 40
 *  0b101000..Divide by 41
 *  0b101001..Divide by 42
 *  0b101010..Divide by 43
 *  0b101011..Divide by 44
 *  0b101100..Divide by 45
 *  0b101101..Divide by 46
 *  0b101110..Divide by 47
 *  0b101111..Divide by 48
 *  0b110000..Divide by 49
 *  0b110001..Divide by 50
 *  0b110010..Divide by 51
 *  0b110011..Divide by 52
 *  0b110100..Divide by 53
 *  0b110101..Divide by 54
 *  0b110110..Divide by 55
 *  0b110111..Divide by 56
 *  0b111000..Divide by 57
 *  0b111001..Divide by 58
 *  0b111010..Divide by 59
 *  0b111011..Divide by 60
 *  0b111100..Divide by 61
 *  0b111101..Divide by 62
 *  0b111110..Divide by 63
 *  0b111111..Divide by 64
 */
#define CCM_CSCDR1_UART_CLK_PODF(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR1_UART_CLK_PODF_SHIFT)) & CCM_CSCDR1_UART_CLK_PODF_MASK)

#define CCM_CSCDR1_UART_CLK_SEL_MASK             (0x40U)
#define CCM_CSCDR1_UART_CLK_SEL_SHIFT            (6U)
/*! UART_CLK_SEL
 *  0b0..derive clock from pll3_80m
 *  0b1..derive clock from osc_clk
 */
#define CCM_CSCDR1_UART_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR1_UART_CLK_SEL_SHIFT)) & CCM_CSCDR1_UART_CLK_SEL_MASK)

#define CCM_CSCDR1_USDHC1_PODF_MASK              (0x3800U)
#define CCM_CSCDR1_USDHC1_PODF_SHIFT             (11U)
/*! USDHC1_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CSCDR1_USDHC1_PODF(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR1_USDHC1_PODF_SHIFT)) & CCM_CSCDR1_USDHC1_PODF_MASK)

#define CCM_CSCDR1_USDHC2_PODF_MASK              (0x70000U)
#define CCM_CSCDR1_USDHC2_PODF_SHIFT             (16U)
/*! USDHC2_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CSCDR1_USDHC2_PODF(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR1_USDHC2_PODF_SHIFT)) & CCM_CSCDR1_USDHC2_PODF_MASK)

#define CCM_CSCDR1_TRACE_PODF_MASK               (0x6000000U)
#define CCM_CSCDR1_TRACE_PODF_SHIFT              (25U)
/*! TRACE_PODF
 *  0b00..divide by 1
 *  0b01..divide by 2
 *  0b10..divide by 3
 *  0b11..divide by 4
 */
#define CCM_CSCDR1_TRACE_PODF(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR1_TRACE_PODF_SHIFT)) & CCM_CSCDR1_TRACE_PODF_MASK)
/*! @} */

/*! @name CS1CDR - CCM Clock Divider Register */
/*! @{ */

#define CCM_CS1CDR_SAI1_CLK_PODF_MASK            (0x3FU)
#define CCM_CS1CDR_SAI1_CLK_PODF_SHIFT           (0U)
/*! SAI1_CLK_PODF - Divider for sai1 clock podf. The input clock to this divider should be lower
 *    than 300Mhz, the predivider can be used to achieve this.
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b000110..Divide by 7
 *  0b000111..Divide by 8
 *  0b001000..Divide by 9
 *  0b001001..Divide by 10
 *  0b001010..Divide by 11
 *  0b001011..Divide by 12
 *  0b001100..Divide by 13
 *  0b001101..Divide by 14
 *  0b001110..Divide by 15
 *  0b001111..Divide by 16
 *  0b010000..Divide by 17
 *  0b010001..Divide by 18
 *  0b010010..Divide by 19
 *  0b010011..Divide by 20
 *  0b010100..Divide by 21
 *  0b010101..Divide by 22
 *  0b010110..Divide by 23
 *  0b010111..Divide by 24
 *  0b011000..Divide by 25
 *  0b011001..Divide by 26
 *  0b011010..Divide by 27
 *  0b011011..Divide by 28
 *  0b011100..Divide by 29
 *  0b011101..Divide by 30
 *  0b011110..Divide by 31
 *  0b011111..Divide by 32
 *  0b100000..Divide by 33
 *  0b100001..Divide by 34
 *  0b100010..Divide by 35
 *  0b100011..Divide by 36
 *  0b100100..Divide by 37
 *  0b100101..Divide by 38
 *  0b100110..Divide by 39
 *  0b100111..Divide by 40
 *  0b101000..Divide by 41
 *  0b101001..Divide by 42
 *  0b101010..Divide by 43
 *  0b101011..Divide by 44
 *  0b101100..Divide by 45
 *  0b101101..Divide by 46
 *  0b101110..Divide by 47
 *  0b101111..Divide by 48
 *  0b110000..Divide by 49
 *  0b110001..Divide by 50
 *  0b110010..Divide by 51
 *  0b110011..Divide by 52
 *  0b110100..Divide by 53
 *  0b110101..Divide by 54
 *  0b110110..Divide by 55
 *  0b110111..Divide by 56
 *  0b111000..Divide by 57
 *  0b111001..Divide by 58
 *  0b111010..Divide by 59
 *  0b111011..Divide by 60
 *  0b111100..Divide by 61
 *  0b111101..Divide by 62
 *  0b111110..Divide by 63
 *  0b111111..Divide by 64
 */
#define CCM_CS1CDR_SAI1_CLK_PODF(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CS1CDR_SAI1_CLK_PODF_SHIFT)) & CCM_CS1CDR_SAI1_CLK_PODF_MASK)

#define CCM_CS1CDR_SAI1_CLK_PRED_MASK            (0x1C0U)
#define CCM_CS1CDR_SAI1_CLK_PRED_SHIFT           (6U)
/*! SAI1_CLK_PRED
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CS1CDR_SAI1_CLK_PRED(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CS1CDR_SAI1_CLK_PRED_SHIFT)) & CCM_CS1CDR_SAI1_CLK_PRED_MASK)

#define CCM_CS1CDR_FLEXIO2_CLK_PRED_MASK         (0xE00U)
#define CCM_CS1CDR_FLEXIO2_CLK_PRED_SHIFT        (9U)
/*! FLEXIO2_CLK_PRED
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CS1CDR_FLEXIO2_CLK_PRED(x)           (((uint32_t)(((uint32_t)(x)) << CCM_CS1CDR_FLEXIO2_CLK_PRED_SHIFT)) & CCM_CS1CDR_FLEXIO2_CLK_PRED_MASK)

#define CCM_CS1CDR_SAI3_CLK_PODF_MASK            (0x3F0000U)
#define CCM_CS1CDR_SAI3_CLK_PODF_SHIFT           (16U)
/*! SAI3_CLK_PODF - Divider for sai3 clock podf. The input clock to this divider should be lower
 *    than 300Mhz, the predivider can be used to achieve this.
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b000110..Divide by 7
 *  0b000111..Divide by 8
 *  0b001000..Divide by 9
 *  0b001001..Divide by 10
 *  0b001010..Divide by 11
 *  0b001011..Divide by 12
 *  0b001100..Divide by 13
 *  0b001101..Divide by 14
 *  0b001110..Divide by 15
 *  0b001111..Divide by 16
 *  0b010000..Divide by 17
 *  0b010001..Divide by 18
 *  0b010010..Divide by 19
 *  0b010011..Divide by 20
 *  0b010100..Divide by 21
 *  0b010101..Divide by 22
 *  0b010110..Divide by 23
 *  0b010111..Divide by 24
 *  0b011000..Divide by 25
 *  0b011001..Divide by 26
 *  0b011010..Divide by 27
 *  0b011011..Divide by 28
 *  0b011100..Divide by 29
 *  0b011101..Divide by 30
 *  0b011110..Divide by 31
 *  0b011111..Divide by 32
 *  0b100000..Divide by 33
 *  0b100001..Divide by 34
 *  0b100010..Divide by 35
 *  0b100011..Divide by 36
 *  0b100100..Divide by 37
 *  0b100101..Divide by 38
 *  0b100110..Divide by 39
 *  0b100111..Divide by 40
 *  0b101000..Divide by 41
 *  0b101001..Divide by 42
 *  0b101010..Divide by 43
 *  0b101011..Divide by 44
 *  0b101100..Divide by 45
 *  0b101101..Divide by 46
 *  0b101110..Divide by 47
 *  0b101111..Divide by 48
 *  0b110000..Divide by 49
 *  0b110001..Divide by 50
 *  0b110010..Divide by 51
 *  0b110011..Divide by 52
 *  0b110100..Divide by 53
 *  0b110101..Divide by 54
 *  0b110110..Divide by 55
 *  0b110111..Divide by 56
 *  0b111000..Divide by 57
 *  0b111001..Divide by 58
 *  0b111010..Divide by 59
 *  0b111011..Divide by 60
 *  0b111100..Divide by 61
 *  0b111101..Divide by 62
 *  0b111110..Divide by 63
 *  0b111111..Divide by 64
 */
#define CCM_CS1CDR_SAI3_CLK_PODF(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CS1CDR_SAI3_CLK_PODF_SHIFT)) & CCM_CS1CDR_SAI3_CLK_PODF_MASK)

#define CCM_CS1CDR_SAI3_CLK_PRED_MASK            (0x1C00000U)
#define CCM_CS1CDR_SAI3_CLK_PRED_SHIFT           (22U)
/*! SAI3_CLK_PRED
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CS1CDR_SAI3_CLK_PRED(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CS1CDR_SAI3_CLK_PRED_SHIFT)) & CCM_CS1CDR_SAI3_CLK_PRED_MASK)

#define CCM_CS1CDR_FLEXIO2_CLK_PODF_MASK         (0xE000000U)
#define CCM_CS1CDR_FLEXIO2_CLK_PODF_SHIFT        (25U)
/*! FLEXIO2_CLK_PODF - Divider for flexio2/flexio3 clock. Divider should be updated when output clock is gated.
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_CS1CDR_FLEXIO2_CLK_PODF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_CS1CDR_FLEXIO2_CLK_PODF_SHIFT)) & CCM_CS1CDR_FLEXIO2_CLK_PODF_MASK)
/*! @} */

/*! @name CS2CDR - CCM Clock Divider Register */
/*! @{ */

#define CCM_CS2CDR_SAI2_CLK_PODF_MASK            (0x3FU)
#define CCM_CS2CDR_SAI2_CLK_PODF_SHIFT           (0U)
/*! SAI2_CLK_PODF - Divider for sai2 clock podf. The input clock to this divider should be lower
 *    than 300Mhz, the predivider can be used to achieve this.
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b000110..Divide by 7
 *  0b000111..Divide by 8
 *  0b001000..Divide by 9
 *  0b001001..Divide by 10
 *  0b001010..Divide by 11
 *  0b001011..Divide by 12
 *  0b001100..Divide by 13
 *  0b001101..Divide by 14
 *  0b001110..Divide by 15
 *  0b001111..Divide by 16
 *  0b010000..Divide by 17
 *  0b010001..Divide by 18
 *  0b010010..Divide by 19
 *  0b010011..Divide by 20
 *  0b010100..Divide by 21
 *  0b010101..Divide by 22
 *  0b010110..Divide by 23
 *  0b010111..Divide by 24
 *  0b011000..Divide by 25
 *  0b011001..Divide by 26
 *  0b011010..Divide by 27
 *  0b011011..Divide by 28
 *  0b011100..Divide by 29
 *  0b011101..Divide by 30
 *  0b011110..Divide by 31
 *  0b011111..Divide by 32
 *  0b100000..Divide by 33
 *  0b100001..Divide by 34
 *  0b100010..Divide by 35
 *  0b100011..Divide by 36
 *  0b100100..Divide by 37
 *  0b100101..Divide by 38
 *  0b100110..Divide by 39
 *  0b100111..Divide by 40
 *  0b101000..Divide by 41
 *  0b101001..Divide by 42
 *  0b101010..Divide by 43
 *  0b101011..Divide by 44
 *  0b101100..Divide by 45
 *  0b101101..Divide by 46
 *  0b101110..Divide by 47
 *  0b101111..Divide by 48
 *  0b110000..Divide by 49
 *  0b110001..Divide by 50
 *  0b110010..Divide by 51
 *  0b110011..Divide by 52
 *  0b110100..Divide by 53
 *  0b110101..Divide by 54
 *  0b110110..Divide by 55
 *  0b110111..Divide by 56
 *  0b111000..Divide by 57
 *  0b111001..Divide by 58
 *  0b111010..Divide by 59
 *  0b111011..Divide by 60
 *  0b111100..Divide by 61
 *  0b111101..Divide by 62
 *  0b111110..Divide by 63
 *  0b111111..Divide by 64
 */
#define CCM_CS2CDR_SAI2_CLK_PODF(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CS2CDR_SAI2_CLK_PODF_SHIFT)) & CCM_CS2CDR_SAI2_CLK_PODF_MASK)

#define CCM_CS2CDR_SAI2_CLK_PRED_MASK            (0x1C0U)
#define CCM_CS2CDR_SAI2_CLK_PRED_SHIFT           (6U)
/*! SAI2_CLK_PRED
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CS2CDR_SAI2_CLK_PRED(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CS2CDR_SAI2_CLK_PRED_SHIFT)) & CCM_CS2CDR_SAI2_CLK_PRED_MASK)
/*! @} */

/*! @name CDCDR - CCM D1 Clock Divider Register */
/*! @{ */

#define CCM_CDCDR_FLEXIO1_CLK_SEL_MASK           (0x180U)
#define CCM_CDCDR_FLEXIO1_CLK_SEL_SHIFT          (7U)
/*! FLEXIO1_CLK_SEL
 *  0b00..derive clock from PLL4
 *  0b01..derive clock from PLL3 PFD2
 *  0b10..derive clock from PLL5
 *  0b11..derive clock from pll3_sw_clk
 */
#define CCM_CDCDR_FLEXIO1_CLK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CDCDR_FLEXIO1_CLK_SEL_SHIFT)) & CCM_CDCDR_FLEXIO1_CLK_SEL_MASK)

#define CCM_CDCDR_FLEXIO1_CLK_PODF_MASK          (0xE00U)
#define CCM_CDCDR_FLEXIO1_CLK_PODF_SHIFT         (9U)
/*! FLEXIO1_CLK_PODF - Divider for flexio1 clock podf. Divider should be updated when output clock is gated.
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_CDCDR_FLEXIO1_CLK_PODF(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CDCDR_FLEXIO1_CLK_PODF_SHIFT)) & CCM_CDCDR_FLEXIO1_CLK_PODF_MASK)

#define CCM_CDCDR_FLEXIO1_CLK_PRED_MASK          (0x7000U)
#define CCM_CDCDR_FLEXIO1_CLK_PRED_SHIFT         (12U)
/*! FLEXIO1_CLK_PRED - Divider for flexio1 clock pred. Divider should be updated when output clock is gated.
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_CDCDR_FLEXIO1_CLK_PRED(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CDCDR_FLEXIO1_CLK_PRED_SHIFT)) & CCM_CDCDR_FLEXIO1_CLK_PRED_MASK)

#define CCM_CDCDR_SPDIF0_CLK_SEL_MASK            (0x300000U)
#define CCM_CDCDR_SPDIF0_CLK_SEL_SHIFT           (20U)
/*! SPDIF0_CLK_SEL
 *  0b00..derive clock from PLL4
 *  0b01..derive clock from PLL3 PFD2
 *  0b10..derive clock from PLL5
 *  0b11..derive clock from pll3_sw_clk
 */
#define CCM_CDCDR_SPDIF0_CLK_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CDCDR_SPDIF0_CLK_SEL_SHIFT)) & CCM_CDCDR_SPDIF0_CLK_SEL_MASK)

#define CCM_CDCDR_SPDIF0_CLK_PODF_MASK           (0x1C00000U)
#define CCM_CDCDR_SPDIF0_CLK_PODF_SHIFT          (22U)
/*! SPDIF0_CLK_PODF - Divider for spdif0 clock podf. Divider should be updated when output clock is gated.
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_CDCDR_SPDIF0_CLK_PODF(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CDCDR_SPDIF0_CLK_PODF_SHIFT)) & CCM_CDCDR_SPDIF0_CLK_PODF_MASK)

#define CCM_CDCDR_SPDIF0_CLK_PRED_MASK           (0xE000000U)
#define CCM_CDCDR_SPDIF0_CLK_PRED_SHIFT          (25U)
/*! SPDIF0_CLK_PRED - Divider for spdif0 clock pred. Divider should be updated when output clock is gated.
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_CDCDR_SPDIF0_CLK_PRED(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CDCDR_SPDIF0_CLK_PRED_SHIFT)) & CCM_CDCDR_SPDIF0_CLK_PRED_MASK)
/*! @} */

/*! @name CSCDR2 - CCM Serial Clock Divider Register 2 */
/*! @{ */

#define CCM_CSCDR2_LCDIF_PRED_MASK               (0x7000U)
#define CCM_CSCDR2_LCDIF_PRED_SHIFT              (12U)
/*! LCDIF_PRED
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CSCDR2_LCDIF_PRED(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR2_LCDIF_PRED_SHIFT)) & CCM_CSCDR2_LCDIF_PRED_MASK)

#define CCM_CSCDR2_LCDIF_PRE_CLK_SEL_MASK        (0x38000U)
#define CCM_CSCDR2_LCDIF_PRE_CLK_SEL_SHIFT       (15U)
/*! LCDIF_PRE_CLK_SEL
 *  0b000..derive clock from PLL2
 *  0b001..derive clock from PLL3 PFD3
 *  0b010..derive clock from PLL5
 *  0b011..derive clock from PLL2 PFD0
 *  0b100..derive clock from PLL2 PFD1
 *  0b101..derive clock from PLL3 PFD1
 *  0b110-0b111..Reserved
 */
#define CCM_CSCDR2_LCDIF_PRE_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR2_LCDIF_PRE_CLK_SEL_SHIFT)) & CCM_CSCDR2_LCDIF_PRE_CLK_SEL_MASK)

#define CCM_CSCDR2_LPI2C_CLK_SEL_MASK            (0x40000U)
#define CCM_CSCDR2_LPI2C_CLK_SEL_SHIFT           (18U)
/*! LPI2C_CLK_SEL
 *  0b0..derive clock from pll3_60m
 *  0b1..derive clock from osc_clk
 */
#define CCM_CSCDR2_LPI2C_CLK_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR2_LPI2C_CLK_SEL_SHIFT)) & CCM_CSCDR2_LPI2C_CLK_SEL_MASK)

#define CCM_CSCDR2_LPI2C_CLK_PODF_MASK           (0x1F80000U)
#define CCM_CSCDR2_LPI2C_CLK_PODF_SHIFT          (19U)
/*! LPI2C_CLK_PODF - Divider for lpi2c clock podf. Divider should be updated when output clock is
 *    gated. The input clock to this divider should be lower than 300Mhz, the predivider can be used
 *    to achieve this.
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b000110..Divide by 7
 *  0b000111..Divide by 8
 *  0b001000..Divide by 9
 *  0b001001..Divide by 10
 *  0b001010..Divide by 11
 *  0b001011..Divide by 12
 *  0b001100..Divide by 13
 *  0b001101..Divide by 14
 *  0b001110..Divide by 15
 *  0b001111..Divide by 16
 *  0b010000..Divide by 17
 *  0b010001..Divide by 18
 *  0b010010..Divide by 19
 *  0b010011..Divide by 20
 *  0b010100..Divide by 21
 *  0b010101..Divide by 22
 *  0b010110..Divide by 23
 *  0b010111..Divide by 24
 *  0b011000..Divide by 25
 *  0b011001..Divide by 26
 *  0b011010..Divide by 27
 *  0b011011..Divide by 28
 *  0b011100..Divide by 29
 *  0b011101..Divide by 30
 *  0b011110..Divide by 31
 *  0b011111..Divide by 32
 *  0b100000..Divide by 33
 *  0b100001..Divide by 34
 *  0b100010..Divide by 35
 *  0b100011..Divide by 36
 *  0b100100..Divide by 37
 *  0b100101..Divide by 38
 *  0b100110..Divide by 39
 *  0b100111..Divide by 40
 *  0b101000..Divide by 41
 *  0b101001..Divide by 42
 *  0b101010..Divide by 43
 *  0b101011..Divide by 44
 *  0b101100..Divide by 45
 *  0b101101..Divide by 46
 *  0b101110..Divide by 47
 *  0b101111..Divide by 48
 *  0b110000..Divide by 49
 *  0b110001..Divide by 50
 *  0b110010..Divide by 51
 *  0b110011..Divide by 52
 *  0b110100..Divide by 53
 *  0b110101..Divide by 54
 *  0b110110..Divide by 55
 *  0b110111..Divide by 56
 *  0b111000..Divide by 57
 *  0b111001..Divide by 58
 *  0b111010..Divide by 59
 *  0b111011..Divide by 60
 *  0b111100..Divide by 61
 *  0b111101..Divide by 62
 *  0b111110..Divide by 63
 *  0b111111..Divide by 64
 */
#define CCM_CSCDR2_LPI2C_CLK_PODF(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR2_LPI2C_CLK_PODF_SHIFT)) & CCM_CSCDR2_LPI2C_CLK_PODF_MASK)
/*! @} */

/*! @name CSCDR3 - CCM Serial Clock Divider Register 3 */
/*! @{ */

#define CCM_CSCDR3_CSI_CLK_SEL_MASK              (0x600U)
#define CCM_CSCDR3_CSI_CLK_SEL_SHIFT             (9U)
/*! CSI_CLK_SEL
 *  0b00..derive clock from osc_clk (24M)
 *  0b01..derive clock from PLL2 PFD2
 *  0b10..derive clock from pll3_120M
 *  0b11..derive clock from PLL3 PFD1
 */
#define CCM_CSCDR3_CSI_CLK_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR3_CSI_CLK_SEL_SHIFT)) & CCM_CSCDR3_CSI_CLK_SEL_MASK)

#define CCM_CSCDR3_CSI_PODF_MASK                 (0x3800U)
#define CCM_CSCDR3_CSI_PODF_SHIFT                (11U)
/*! CSI_PODF
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CSCDR3_CSI_PODF(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CSCDR3_CSI_PODF_SHIFT)) & CCM_CSCDR3_CSI_PODF_MASK)
/*! @} */

/*! @name CDHIPR - CCM Divider Handshake In-Process Register */
/*! @{ */

#define CCM_CDHIPR_SEMC_PODF_BUSY_MASK           (0x1U)
#define CCM_CDHIPR_SEMC_PODF_BUSY_SHIFT          (0U)
/*! SEMC_PODF_BUSY
 *  0b0..divider is not busy and its value represents the actual division.
 *  0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
 *       value of the division factor, and after the handshake the written value of the semc_podf will be applied.
 */
#define CCM_CDHIPR_SEMC_PODF_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CDHIPR_SEMC_PODF_BUSY_SHIFT)) & CCM_CDHIPR_SEMC_PODF_BUSY_MASK)

#define CCM_CDHIPR_AHB_PODF_BUSY_MASK            (0x2U)
#define CCM_CDHIPR_AHB_PODF_BUSY_SHIFT           (1U)
/*! AHB_PODF_BUSY
 *  0b0..divider is not busy and its value represents the actual division.
 *  0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
 *       value of the division factor, and after the handshake the written value of the ahb_podf will be applied.
 */
#define CCM_CDHIPR_AHB_PODF_BUSY(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CDHIPR_AHB_PODF_BUSY_SHIFT)) & CCM_CDHIPR_AHB_PODF_BUSY_MASK)

#define CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY_MASK     (0x8U)
#define CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY_SHIFT    (3U)
/*! PERIPH2_CLK_SEL_BUSY
 *  0b0..mux is not busy and its value represents the actual division.
 *  0b1..mux is busy with handshake process with module. The value read in the periph2_clk_sel represents the
 *       previous value of select, and after the handshake periph2_clk_sel value will be applied.
 */
#define CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY_SHIFT)) & CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY_MASK)

#define CCM_CDHIPR_PERIPH_CLK_SEL_BUSY_MASK      (0x20U)
#define CCM_CDHIPR_PERIPH_CLK_SEL_BUSY_SHIFT     (5U)
/*! PERIPH_CLK_SEL_BUSY
 *  0b0..mux is not busy and its value represents the actual division.
 *  0b1..mux is busy with handshake process with module. The value read in the periph_clk_sel represents the
 *       previous value of select, and after the handshake periph_clk_sel value will be applied.
 */
#define CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CDHIPR_PERIPH_CLK_SEL_BUSY_SHIFT)) & CCM_CDHIPR_PERIPH_CLK_SEL_BUSY_MASK)

#define CCM_CDHIPR_ARM_PODF_BUSY_MASK            (0x10000U)
#define CCM_CDHIPR_ARM_PODF_BUSY_SHIFT           (16U)
/*! ARM_PODF_BUSY
 *  0b0..divider is not busy and its value represents the actual division.
 *  0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
 *       value of the division factor, and after the handshake the written value of the arm_podf will be applied.
 */
#define CCM_CDHIPR_ARM_PODF_BUSY(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CDHIPR_ARM_PODF_BUSY_SHIFT)) & CCM_CDHIPR_ARM_PODF_BUSY_MASK)
/*! @} */

/*! @name CLPCR - CCM Low Power Control Register */
/*! @{ */

#define CCM_CLPCR_LPM_MASK                       (0x3U)
#define CCM_CLPCR_LPM_SHIFT                      (0U)
/*! LPM
 *  0b00..Remain in run mode
 *  0b01..Transfer to wait mode
 *  0b10..Transfer to stop mode
 *  0b11..Reserved
 */
#define CCM_CLPCR_LPM(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_LPM_SHIFT)) & CCM_CLPCR_LPM_MASK)

#define CCM_CLPCR_ARM_CLK_DIS_ON_LPM_MASK        (0x20U)
#define CCM_CLPCR_ARM_CLK_DIS_ON_LPM_SHIFT       (5U)
/*! ARM_CLK_DIS_ON_LPM
 *  0b0..Arm clock enabled on wait mode.
 *  0b1..Arm clock disabled on wait mode. .
 */
#define CCM_CLPCR_ARM_CLK_DIS_ON_LPM(x)          (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_ARM_CLK_DIS_ON_LPM_SHIFT)) & CCM_CLPCR_ARM_CLK_DIS_ON_LPM_MASK)

#define CCM_CLPCR_SBYOS_MASK                     (0x40U)
#define CCM_CLPCR_SBYOS_SHIFT                    (6U)
/*! SBYOS
 *  0b0..On-chip oscillator will not be powered down, after next entrance to STOP mode. (CCM_REF_EN_B will remain
 *       asserted - '0' and cosc_pwrdown will remain de asserted - '0')
 *  0b1..On-chip oscillator will be powered down, after next entrance to STOP mode. (CCM_REF_EN_B will be
 *       deasserted - '1' and cosc_pwrdown will be asserted - '1'). When returning from STOP mode, external oscillator will
 *       be enabled again, on-chip oscillator will return to oscillator mode, and after oscnt count, CCM will
 *       continue with the exit from the STOP mode process.
 */
#define CCM_CLPCR_SBYOS(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_SBYOS_SHIFT)) & CCM_CLPCR_SBYOS_MASK)

#define CCM_CLPCR_DIS_REF_OSC_MASK               (0x80U)
#define CCM_CLPCR_DIS_REF_OSC_SHIFT              (7U)
/*! DIS_REF_OSC
 *  0b0..external high frequency oscillator will be enabled, i.e. CCM_REF_EN_B = '0'.
 *  0b1..external high frequency oscillator will be disabled, i.e. CCM_REF_EN_B = '1'
 */
#define CCM_CLPCR_DIS_REF_OSC(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_DIS_REF_OSC_SHIFT)) & CCM_CLPCR_DIS_REF_OSC_MASK)

#define CCM_CLPCR_VSTBY_MASK                     (0x100U)
#define CCM_CLPCR_VSTBY_SHIFT                    (8U)
/*! VSTBY
 *  0b0..Voltage will not be changed to standby voltage after next entrance to STOP mode. ( PMIC_STBY_REQ will remain negated - '0')
 *  0b1..Voltage will be requested to change to standby voltage after next entrance to stop mode. ( PMIC_STBY_REQ will be asserted - '1').
 */
#define CCM_CLPCR_VSTBY(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_VSTBY_SHIFT)) & CCM_CLPCR_VSTBY_MASK)

#define CCM_CLPCR_STBY_COUNT_MASK                (0x600U)
#define CCM_CLPCR_STBY_COUNT_SHIFT               (9U)
/*! STBY_COUNT
 *  0b00..CCM will wait (1*pmic_delay_scaler)+1 ckil clock cycles
 *  0b01..CCM will wait (3*pmic_delay_scaler)+1 ckil clock cycles
 *  0b10..CCM will wait (7*pmic_delay_scaler)+1 ckil clock cycles
 *  0b11..CCM will wait (15*pmic_delay_scaler)+1 ckil clock cycles
 */
#define CCM_CLPCR_STBY_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_STBY_COUNT_SHIFT)) & CCM_CLPCR_STBY_COUNT_MASK)

#define CCM_CLPCR_COSC_PWRDOWN_MASK              (0x800U)
#define CCM_CLPCR_COSC_PWRDOWN_SHIFT             (11U)
/*! COSC_PWRDOWN
 *  0b0..On chip oscillator will not be powered down, i.e. cosc_pwrdown = '0'.
 *  0b1..On chip oscillator will be powered down, i.e. cosc_pwrdown = '1'.
 */
#define CCM_CLPCR_COSC_PWRDOWN(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_COSC_PWRDOWN_SHIFT)) & CCM_CLPCR_COSC_PWRDOWN_MASK)

#define CCM_CLPCR_BYPASS_LPM_HS1_MASK            (0x80000U)
#define CCM_CLPCR_BYPASS_LPM_HS1_SHIFT           (19U)
#define CCM_CLPCR_BYPASS_LPM_HS1(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_BYPASS_LPM_HS1_SHIFT)) & CCM_CLPCR_BYPASS_LPM_HS1_MASK)

#define CCM_CLPCR_BYPASS_LPM_HS0_MASK            (0x200000U)
#define CCM_CLPCR_BYPASS_LPM_HS0_SHIFT           (21U)
#define CCM_CLPCR_BYPASS_LPM_HS0(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_BYPASS_LPM_HS0_SHIFT)) & CCM_CLPCR_BYPASS_LPM_HS0_MASK)

#define CCM_CLPCR_MASK_CORE0_WFI_MASK            (0x400000U)
#define CCM_CLPCR_MASK_CORE0_WFI_SHIFT           (22U)
/*! MASK_CORE0_WFI
 *  0b0..WFI of core0 is not masked
 *  0b1..WFI of core0 is masked
 */
#define CCM_CLPCR_MASK_CORE0_WFI(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_MASK_CORE0_WFI_SHIFT)) & CCM_CLPCR_MASK_CORE0_WFI_MASK)

#define CCM_CLPCR_MASK_SCU_IDLE_MASK             (0x4000000U)
#define CCM_CLPCR_MASK_SCU_IDLE_SHIFT            (26U)
/*! MASK_SCU_IDLE
 *  0b0..SCU IDLE is not masked
 *  0b1..SCU IDLE is masked
 */
#define CCM_CLPCR_MASK_SCU_IDLE(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_MASK_SCU_IDLE_SHIFT)) & CCM_CLPCR_MASK_SCU_IDLE_MASK)

#define CCM_CLPCR_MASK_L2CC_IDLE_MASK            (0x8000000U)
#define CCM_CLPCR_MASK_L2CC_IDLE_SHIFT           (27U)
/*! MASK_L2CC_IDLE
 *  0b0..L2CC IDLE is not masked
 *  0b1..L2CC IDLE is masked
 */
#define CCM_CLPCR_MASK_L2CC_IDLE(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CLPCR_MASK_L2CC_IDLE_SHIFT)) & CCM_CLPCR_MASK_L2CC_IDLE_MASK)
/*! @} */

/*! @name CISR - CCM Interrupt Status Register */
/*! @{ */

#define CCM_CISR_LRF_PLL_MASK                    (0x1U)
#define CCM_CISR_LRF_PLL_SHIFT                   (0U)
/*! LRF_PLL
 *  0b0..interrupt is not generated due to lock ready of all enabled and not bypaseed PLLs
 *  0b1..interrupt generated due to lock ready of all enabled and not bypaseed PLLs
 */
#define CCM_CISR_LRF_PLL(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_CISR_LRF_PLL_SHIFT)) & CCM_CISR_LRF_PLL_MASK)

#define CCM_CISR_COSC_READY_MASK                 (0x40U)
#define CCM_CISR_COSC_READY_SHIFT                (6U)
/*! COSC_READY
 *  0b0..interrupt is not generated due to on board oscillator ready
 *  0b1..interrupt generated due to on board oscillator ready
 */
#define CCM_CISR_COSC_READY(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CISR_COSC_READY_SHIFT)) & CCM_CISR_COSC_READY_MASK)

#define CCM_CISR_SEMC_PODF_LOADED_MASK           (0x20000U)
#define CCM_CISR_SEMC_PODF_LOADED_SHIFT          (17U)
/*! SEMC_PODF_LOADED
 *  0b0..interrupt is not generated due to frequency change of semc_podf
 *  0b1..interrupt generated due to frequency change of semc_podf
 */
#define CCM_CISR_SEMC_PODF_LOADED(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CISR_SEMC_PODF_LOADED_SHIFT)) & CCM_CISR_SEMC_PODF_LOADED_MASK)

#define CCM_CISR_PERIPH2_CLK_SEL_LOADED_MASK     (0x80000U)
#define CCM_CISR_PERIPH2_CLK_SEL_LOADED_SHIFT    (19U)
/*! PERIPH2_CLK_SEL_LOADED
 *  0b0..interrupt is not generated due to frequency change of periph2_clk_sel
 *  0b1..interrupt generated due to frequency change of periph2_clk_sel
 */
#define CCM_CISR_PERIPH2_CLK_SEL_LOADED(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CISR_PERIPH2_CLK_SEL_LOADED_SHIFT)) & CCM_CISR_PERIPH2_CLK_SEL_LOADED_MASK)

#define CCM_CISR_AHB_PODF_LOADED_MASK            (0x100000U)
#define CCM_CISR_AHB_PODF_LOADED_SHIFT           (20U)
/*! AHB_PODF_LOADED
 *  0b0..interrupt is not generated due to frequency change of ahb_podf
 *  0b1..interrupt generated due to frequency change of ahb_podf
 */
#define CCM_CISR_AHB_PODF_LOADED(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CISR_AHB_PODF_LOADED_SHIFT)) & CCM_CISR_AHB_PODF_LOADED_MASK)

#define CCM_CISR_PERIPH_CLK_SEL_LOADED_MASK      (0x400000U)
#define CCM_CISR_PERIPH_CLK_SEL_LOADED_SHIFT     (22U)
/*! PERIPH_CLK_SEL_LOADED
 *  0b0..interrupt is not generated due to update of periph_clk_sel.
 *  0b1..interrupt generated due to update of periph_clk_sel.
 */
#define CCM_CISR_PERIPH_CLK_SEL_LOADED(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CISR_PERIPH_CLK_SEL_LOADED_SHIFT)) & CCM_CISR_PERIPH_CLK_SEL_LOADED_MASK)

#define CCM_CISR_ARM_PODF_LOADED_MASK            (0x4000000U)
#define CCM_CISR_ARM_PODF_LOADED_SHIFT           (26U)
/*! ARM_PODF_LOADED
 *  0b0..interrupt is not generated due to frequency change of arm_podf
 *  0b1..interrupt generated due to frequency change of arm_podf
 */
#define CCM_CISR_ARM_PODF_LOADED(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CISR_ARM_PODF_LOADED_SHIFT)) & CCM_CISR_ARM_PODF_LOADED_MASK)
/*! @} */

/*! @name CIMR - CCM Interrupt Mask Register */
/*! @{ */

#define CCM_CIMR_MASK_LRF_PLL_MASK               (0x1U)
#define CCM_CIMR_MASK_LRF_PLL_SHIFT              (0U)
/*! MASK_LRF_PLL
 *  0b0..don't mask interrupt due to lrf of PLLs - interrupt will be created
 *  0b1..mask interrupt due to lrf of PLLs
 */
#define CCM_CIMR_MASK_LRF_PLL(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CIMR_MASK_LRF_PLL_SHIFT)) & CCM_CIMR_MASK_LRF_PLL_MASK)

#define CCM_CIMR_MASK_COSC_READY_MASK            (0x40U)
#define CCM_CIMR_MASK_COSC_READY_SHIFT           (6U)
/*! MASK_COSC_READY
 *  0b0..don't mask interrupt due to on board oscillator ready - interrupt will be created
 *  0b1..mask interrupt due to on board oscillator ready
 */
#define CCM_CIMR_MASK_COSC_READY(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CIMR_MASK_COSC_READY_SHIFT)) & CCM_CIMR_MASK_COSC_READY_MASK)

#define CCM_CIMR_MASK_SEMC_PODF_LOADED_MASK      (0x20000U)
#define CCM_CIMR_MASK_SEMC_PODF_LOADED_SHIFT     (17U)
/*! MASK_SEMC_PODF_LOADED
 *  0b0..don't mask interrupt due to frequency change of semc_podf - interrupt will be created
 *  0b1..mask interrupt due to frequency change of semc_podf
 */
#define CCM_CIMR_MASK_SEMC_PODF_LOADED(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CIMR_MASK_SEMC_PODF_LOADED_SHIFT)) & CCM_CIMR_MASK_SEMC_PODF_LOADED_MASK)

#define CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED_MASK (0x80000U)
#define CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED_SHIFT (19U)
/*! MASK_PERIPH2_CLK_SEL_LOADED
 *  0b0..don't mask interrupt due to update of periph2_clk_sel - interrupt will be created
 *  0b1..mask interrupt due to update of periph2_clk_sel
 */
#define CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(x)  (((uint32_t)(((uint32_t)(x)) << CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED_SHIFT)) & CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED_MASK)

#define CCM_CIMR_MASK_AHB_PODF_LOADED_MASK       (0x100000U)
#define CCM_CIMR_MASK_AHB_PODF_LOADED_SHIFT      (20U)
/*! MASK_AHB_PODF_LOADED
 *  0b0..don't mask interrupt due to frequency change of ahb_podf - interrupt will be created
 *  0b1..mask interrupt due to frequency change of ahb_podf
 */
#define CCM_CIMR_MASK_AHB_PODF_LOADED(x)         (((uint32_t)(((uint32_t)(x)) << CCM_CIMR_MASK_AHB_PODF_LOADED_SHIFT)) & CCM_CIMR_MASK_AHB_PODF_LOADED_MASK)

#define CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED_MASK (0x400000U)
#define CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED_SHIFT (22U)
/*! MASK_PERIPH_CLK_SEL_LOADED
 *  0b0..don't mask interrupt due to update of periph_clk_sel - interrupt will be created
 *  0b1..mask interrupt due to update of periph_clk_sel
 */
#define CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(x)   (((uint32_t)(((uint32_t)(x)) << CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED_SHIFT)) & CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED_MASK)

#define CCM_CIMR_ARM_PODF_LOADED_MASK            (0x4000000U)
#define CCM_CIMR_ARM_PODF_LOADED_SHIFT           (26U)
/*! ARM_PODF_LOADED
 *  0b0..don't mask interrupt due to frequency change of arm_podf - interrupt will be created
 *  0b1..mask interrupt due to frequency change of arm_podf
 */
#define CCM_CIMR_ARM_PODF_LOADED(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CIMR_ARM_PODF_LOADED_SHIFT)) & CCM_CIMR_ARM_PODF_LOADED_MASK)
/*! @} */

/*! @name CCOSR - CCM Clock Output Source Register */
/*! @{ */

#define CCM_CCOSR_CLKO1_SEL_MASK                 (0xFU)
#define CCM_CCOSR_CLKO1_SEL_SHIFT                (0U)
/*! CLKO1_SEL
 *  0b0000..USB1 PLL clock (divided by 2)
 *  0b0001..SYS PLL clock (divided by 2)
 *  0b0011..VIDEO PLL clock (divided by 2)
 *  0b0101..semc_clk_root
 *  0b0110..Reserved
 *  0b1010..lcdif_pix_clk_root
 *  0b1011..ahb_clk_root
 *  0b1100..ipg_clk_root
 *  0b1101..perclk_root
 *  0b1110..ckil_sync_clk_root
 *  0b1111..pll4_main_clk
 */
#define CCM_CCOSR_CLKO1_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CCOSR_CLKO1_SEL_SHIFT)) & CCM_CCOSR_CLKO1_SEL_MASK)

#define CCM_CCOSR_CLKO1_DIV_MASK                 (0x70U)
#define CCM_CCOSR_CLKO1_DIV_SHIFT                (4U)
/*! CLKO1_DIV
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CCOSR_CLKO1_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CCOSR_CLKO1_DIV_SHIFT)) & CCM_CCOSR_CLKO1_DIV_MASK)

#define CCM_CCOSR_CLKO1_EN_MASK                  (0x80U)
#define CCM_CCOSR_CLKO1_EN_SHIFT                 (7U)
/*! CLKO1_EN
 *  0b0..CCM_CLKO1 disabled.
 *  0b1..CCM_CLKO1 enabled.
 */
#define CCM_CCOSR_CLKO1_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CCOSR_CLKO1_EN_SHIFT)) & CCM_CCOSR_CLKO1_EN_MASK)

#define CCM_CCOSR_CLK_OUT_SEL_MASK               (0x100U)
#define CCM_CCOSR_CLK_OUT_SEL_SHIFT              (8U)
/*! CLK_OUT_SEL
 *  0b0..CCM_CLKO1 output drives CCM_CLKO1 clock
 *  0b1..CCM_CLKO1 output drives CCM_CLKO2 clock
 */
#define CCM_CCOSR_CLK_OUT_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCOSR_CLK_OUT_SEL_SHIFT)) & CCM_CCOSR_CLK_OUT_SEL_MASK)

#define CCM_CCOSR_CLKO2_SEL_MASK                 (0x1F0000U)
#define CCM_CCOSR_CLKO2_SEL_SHIFT                (16U)
/*! CLKO2_SEL
 *  0b00011..usdhc1_clk_root
 *  0b00110..lpi2c_clk_root
 *  0b01011..csi_clk_root
 *  0b01110..osc_clk
 *  0b10001..usdhc2_clk_root
 *  0b10010..sai1_clk_root
 *  0b10011..sai2_clk_root
 *  0b10100..sai3_clk_root (shared with ADC1 and ADC2 alt_clk root)
 *  0b10111..can_clk_root (FlexCAN, shared with CANFD)
 *  0b11011..flexspi_clk_root
 *  0b11100..uart_clk_root
 *  0b11101..spdif0_clk_root
 *  0b11111..Reserved
 */
#define CCM_CCOSR_CLKO2_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CCOSR_CLKO2_SEL_SHIFT)) & CCM_CCOSR_CLKO2_SEL_MASK)

#define CCM_CCOSR_CLKO2_DIV_MASK                 (0xE00000U)
#define CCM_CCOSR_CLKO2_DIV_SHIFT                (21U)
/*! CLKO2_DIV
 *  0b000..divide by 1
 *  0b001..divide by 2
 *  0b010..divide by 3
 *  0b011..divide by 4
 *  0b100..divide by 5
 *  0b101..divide by 6
 *  0b110..divide by 7
 *  0b111..divide by 8
 */
#define CCM_CCOSR_CLKO2_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_CCOSR_CLKO2_DIV_SHIFT)) & CCM_CCOSR_CLKO2_DIV_MASK)

#define CCM_CCOSR_CLKO2_EN_MASK                  (0x1000000U)
#define CCM_CCOSR_CLKO2_EN_SHIFT                 (24U)
/*! CLKO2_EN
 *  0b0..CCM_CLKO2 disabled.
 *  0b1..CCM_CLKO2 enabled.
 */
#define CCM_CCOSR_CLKO2_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CCOSR_CLKO2_EN_SHIFT)) & CCM_CCOSR_CLKO2_EN_MASK)
/*! @} */

/*! @name CGPR - CCM General Purpose Register */
/*! @{ */

#define CCM_CGPR_PMIC_DELAY_SCALER_MASK          (0x1U)
#define CCM_CGPR_PMIC_DELAY_SCALER_SHIFT         (0U)
/*! PMIC_DELAY_SCALER
 *  0b0..clock is not divided
 *  0b1..clock is divided /8
 */
#define CCM_CGPR_PMIC_DELAY_SCALER(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CGPR_PMIC_DELAY_SCALER_SHIFT)) & CCM_CGPR_PMIC_DELAY_SCALER_MASK)

#define CCM_CGPR_EFUSE_PROG_SUPPLY_GATE_MASK     (0x10U)
#define CCM_CGPR_EFUSE_PROG_SUPPLY_GATE_SHIFT    (4U)
/*! EFUSE_PROG_SUPPLY_GATE
 *  0b0..fuse programing supply voltage is gated off to the efuse module
 *  0b1..allow fuse programing.
 */
#define CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CGPR_EFUSE_PROG_SUPPLY_GATE_SHIFT)) & CCM_CGPR_EFUSE_PROG_SUPPLY_GATE_MASK)

#define CCM_CGPR_SYS_MEM_DS_CTRL_MASK            (0xC000U)
#define CCM_CGPR_SYS_MEM_DS_CTRL_SHIFT           (14U)
/*! SYS_MEM_DS_CTRL
 *  0b00..Disable memory DS mode always
 *  0b01..Enable memory (outside Arm platform) DS mode when system STOP and PLL are disabled
 *  0b1x..enable memory (outside Arm platform) DS mode when system is in STOP mode
 */
#define CCM_CGPR_SYS_MEM_DS_CTRL(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CGPR_SYS_MEM_DS_CTRL_SHIFT)) & CCM_CGPR_SYS_MEM_DS_CTRL_MASK)

#define CCM_CGPR_FPL_MASK                        (0x10000U)
#define CCM_CGPR_FPL_SHIFT                       (16U)
/*! FPL - Fast PLL enable.
 *  0b0..Engage PLL enable default way.
 *  0b1..Engage PLL enable 3 CKIL clocks earlier at exiting low power mode (STOP). Should be used only if 24MHz OSC was active in low power mode.
 */
#define CCM_CGPR_FPL(x)                          (((uint32_t)(((uint32_t)(x)) << CCM_CGPR_FPL_SHIFT)) & CCM_CGPR_FPL_MASK)

#define CCM_CGPR_INT_MEM_CLK_LPM_MASK            (0x20000U)
#define CCM_CGPR_INT_MEM_CLK_LPM_SHIFT           (17U)
/*! INT_MEM_CLK_LPM
 *  0b0..Disable the clock to the Arm platform memories when entering Low Power Mode
 *  0b1..Keep the clocks to the Arm platform memories enabled only if an interrupt is pending when entering Low
 *       Power Modes (WAIT and STOP without power gating)
 */
#define CCM_CGPR_INT_MEM_CLK_LPM(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CGPR_INT_MEM_CLK_LPM_SHIFT)) & CCM_CGPR_INT_MEM_CLK_LPM_MASK)
/*! @} */

/*! @name CCGR0 - CCM Clock Gating Register 0 */
/*! @{ */

#define CCM_CCGR0_CG0_MASK                       (0x3U)
#define CCM_CCGR0_CG0_SHIFT                      (0U)
#define CCM_CCGR0_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG0_SHIFT)) & CCM_CCGR0_CG0_MASK)

#define CCM_CCGR0_CG1_MASK                       (0xCU)
#define CCM_CCGR0_CG1_SHIFT                      (2U)
#define CCM_CCGR0_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG1_SHIFT)) & CCM_CCGR0_CG1_MASK)

#define CCM_CCGR0_CG2_MASK                       (0x30U)
#define CCM_CCGR0_CG2_SHIFT                      (4U)
#define CCM_CCGR0_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG2_SHIFT)) & CCM_CCGR0_CG2_MASK)

#define CCM_CCGR0_CG3_MASK                       (0xC0U)
#define CCM_CCGR0_CG3_SHIFT                      (6U)
#define CCM_CCGR0_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG3_SHIFT)) & CCM_CCGR0_CG3_MASK)

#define CCM_CCGR0_CG4_MASK                       (0x300U)
#define CCM_CCGR0_CG4_SHIFT                      (8U)
#define CCM_CCGR0_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG4_SHIFT)) & CCM_CCGR0_CG4_MASK)

#define CCM_CCGR0_CG5_MASK                       (0xC00U)
#define CCM_CCGR0_CG5_SHIFT                      (10U)
#define CCM_CCGR0_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG5_SHIFT)) & CCM_CCGR0_CG5_MASK)

#define CCM_CCGR0_CG6_MASK                       (0x3000U)
#define CCM_CCGR0_CG6_SHIFT                      (12U)
#define CCM_CCGR0_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG6_SHIFT)) & CCM_CCGR0_CG6_MASK)

#define CCM_CCGR0_CG7_MASK                       (0xC000U)
#define CCM_CCGR0_CG7_SHIFT                      (14U)
#define CCM_CCGR0_CG7(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG7_SHIFT)) & CCM_CCGR0_CG7_MASK)

#define CCM_CCGR0_CG8_MASK                       (0x30000U)
#define CCM_CCGR0_CG8_SHIFT                      (16U)
#define CCM_CCGR0_CG8(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG8_SHIFT)) & CCM_CCGR0_CG8_MASK)

#define CCM_CCGR0_CG9_MASK                       (0xC0000U)
#define CCM_CCGR0_CG9_SHIFT                      (18U)
#define CCM_CCGR0_CG9(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG9_SHIFT)) & CCM_CCGR0_CG9_MASK)

#define CCM_CCGR0_CG10_MASK                      (0x300000U)
#define CCM_CCGR0_CG10_SHIFT                     (20U)
#define CCM_CCGR0_CG10(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG10_SHIFT)) & CCM_CCGR0_CG10_MASK)

#define CCM_CCGR0_CG11_MASK                      (0xC00000U)
#define CCM_CCGR0_CG11_SHIFT                     (22U)
#define CCM_CCGR0_CG11(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG11_SHIFT)) & CCM_CCGR0_CG11_MASK)

#define CCM_CCGR0_CG12_MASK                      (0x3000000U)
#define CCM_CCGR0_CG12_SHIFT                     (24U)
#define CCM_CCGR0_CG12(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG12_SHIFT)) & CCM_CCGR0_CG12_MASK)

#define CCM_CCGR0_CG13_MASK                      (0xC000000U)
#define CCM_CCGR0_CG13_SHIFT                     (26U)
#define CCM_CCGR0_CG13(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG13_SHIFT)) & CCM_CCGR0_CG13_MASK)

#define CCM_CCGR0_CG14_MASK                      (0x30000000U)
#define CCM_CCGR0_CG14_SHIFT                     (28U)
#define CCM_CCGR0_CG14(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG14_SHIFT)) & CCM_CCGR0_CG14_MASK)

#define CCM_CCGR0_CG15_MASK                      (0xC0000000U)
#define CCM_CCGR0_CG15_SHIFT                     (30U)
#define CCM_CCGR0_CG15(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR0_CG15_SHIFT)) & CCM_CCGR0_CG15_MASK)
/*! @} */

/*! @name CCGR1 - CCM Clock Gating Register 1 */
/*! @{ */

#define CCM_CCGR1_CG0_MASK                       (0x3U)
#define CCM_CCGR1_CG0_SHIFT                      (0U)
#define CCM_CCGR1_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG0_SHIFT)) & CCM_CCGR1_CG0_MASK)

#define CCM_CCGR1_CG1_MASK                       (0xCU)
#define CCM_CCGR1_CG1_SHIFT                      (2U)
#define CCM_CCGR1_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG1_SHIFT)) & CCM_CCGR1_CG1_MASK)

#define CCM_CCGR1_CG2_MASK                       (0x30U)
#define CCM_CCGR1_CG2_SHIFT                      (4U)
#define CCM_CCGR1_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG2_SHIFT)) & CCM_CCGR1_CG2_MASK)

#define CCM_CCGR1_CG3_MASK                       (0xC0U)
#define CCM_CCGR1_CG3_SHIFT                      (6U)
#define CCM_CCGR1_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG3_SHIFT)) & CCM_CCGR1_CG3_MASK)

#define CCM_CCGR1_CG4_MASK                       (0x300U)
#define CCM_CCGR1_CG4_SHIFT                      (8U)
#define CCM_CCGR1_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG4_SHIFT)) & CCM_CCGR1_CG4_MASK)

#define CCM_CCGR1_CG5_MASK                       (0xC00U)
#define CCM_CCGR1_CG5_SHIFT                      (10U)
#define CCM_CCGR1_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG5_SHIFT)) & CCM_CCGR1_CG5_MASK)

#define CCM_CCGR1_CG6_MASK                       (0x3000U)
#define CCM_CCGR1_CG6_SHIFT                      (12U)
#define CCM_CCGR1_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG6_SHIFT)) & CCM_CCGR1_CG6_MASK)

#define CCM_CCGR1_CG7_MASK                       (0xC000U)
#define CCM_CCGR1_CG7_SHIFT                      (14U)
#define CCM_CCGR1_CG7(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG7_SHIFT)) & CCM_CCGR1_CG7_MASK)

#define CCM_CCGR1_CG8_MASK                       (0x30000U)
#define CCM_CCGR1_CG8_SHIFT                      (16U)
#define CCM_CCGR1_CG8(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG8_SHIFT)) & CCM_CCGR1_CG8_MASK)

#define CCM_CCGR1_CG9_MASK                       (0xC0000U)
#define CCM_CCGR1_CG9_SHIFT                      (18U)
#define CCM_CCGR1_CG9(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG9_SHIFT)) & CCM_CCGR1_CG9_MASK)

#define CCM_CCGR1_CG10_MASK                      (0x300000U)
#define CCM_CCGR1_CG10_SHIFT                     (20U)
#define CCM_CCGR1_CG10(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG10_SHIFT)) & CCM_CCGR1_CG10_MASK)

#define CCM_CCGR1_CG11_MASK                      (0xC00000U)
#define CCM_CCGR1_CG11_SHIFT                     (22U)
#define CCM_CCGR1_CG11(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG11_SHIFT)) & CCM_CCGR1_CG11_MASK)

#define CCM_CCGR1_CG12_MASK                      (0x3000000U)
#define CCM_CCGR1_CG12_SHIFT                     (24U)
#define CCM_CCGR1_CG12(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG12_SHIFT)) & CCM_CCGR1_CG12_MASK)

#define CCM_CCGR1_CG13_MASK                      (0xC000000U)
#define CCM_CCGR1_CG13_SHIFT                     (26U)
#define CCM_CCGR1_CG13(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG13_SHIFT)) & CCM_CCGR1_CG13_MASK)

#define CCM_CCGR1_CG14_MASK                      (0x30000000U)
#define CCM_CCGR1_CG14_SHIFT                     (28U)
#define CCM_CCGR1_CG14(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG14_SHIFT)) & CCM_CCGR1_CG14_MASK)

#define CCM_CCGR1_CG15_MASK                      (0xC0000000U)
#define CCM_CCGR1_CG15_SHIFT                     (30U)
#define CCM_CCGR1_CG15(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR1_CG15_SHIFT)) & CCM_CCGR1_CG15_MASK)
/*! @} */

/*! @name CCGR2 - CCM Clock Gating Register 2 */
/*! @{ */

#define CCM_CCGR2_CG0_MASK                       (0x3U)
#define CCM_CCGR2_CG0_SHIFT                      (0U)
#define CCM_CCGR2_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG0_SHIFT)) & CCM_CCGR2_CG0_MASK)

#define CCM_CCGR2_CG1_MASK                       (0xCU)
#define CCM_CCGR2_CG1_SHIFT                      (2U)
#define CCM_CCGR2_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG1_SHIFT)) & CCM_CCGR2_CG1_MASK)

#define CCM_CCGR2_CG2_MASK                       (0x30U)
#define CCM_CCGR2_CG2_SHIFT                      (4U)
#define CCM_CCGR2_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG2_SHIFT)) & CCM_CCGR2_CG2_MASK)

#define CCM_CCGR2_CG3_MASK                       (0xC0U)
#define CCM_CCGR2_CG3_SHIFT                      (6U)
#define CCM_CCGR2_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG3_SHIFT)) & CCM_CCGR2_CG3_MASK)

#define CCM_CCGR2_CG4_MASK                       (0x300U)
#define CCM_CCGR2_CG4_SHIFT                      (8U)
#define CCM_CCGR2_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG4_SHIFT)) & CCM_CCGR2_CG4_MASK)

#define CCM_CCGR2_CG5_MASK                       (0xC00U)
#define CCM_CCGR2_CG5_SHIFT                      (10U)
#define CCM_CCGR2_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG5_SHIFT)) & CCM_CCGR2_CG5_MASK)

#define CCM_CCGR2_CG6_MASK                       (0x3000U)
#define CCM_CCGR2_CG6_SHIFT                      (12U)
#define CCM_CCGR2_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG6_SHIFT)) & CCM_CCGR2_CG6_MASK)

#define CCM_CCGR2_CG7_MASK                       (0xC000U)
#define CCM_CCGR2_CG7_SHIFT                      (14U)
#define CCM_CCGR2_CG7(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG7_SHIFT)) & CCM_CCGR2_CG7_MASK)

#define CCM_CCGR2_CG8_MASK                       (0x30000U)
#define CCM_CCGR2_CG8_SHIFT                      (16U)
#define CCM_CCGR2_CG8(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG8_SHIFT)) & CCM_CCGR2_CG8_MASK)

#define CCM_CCGR2_CG9_MASK                       (0xC0000U)
#define CCM_CCGR2_CG9_SHIFT                      (18U)
#define CCM_CCGR2_CG9(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG9_SHIFT)) & CCM_CCGR2_CG9_MASK)

#define CCM_CCGR2_CG10_MASK                      (0x300000U)
#define CCM_CCGR2_CG10_SHIFT                     (20U)
#define CCM_CCGR2_CG10(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG10_SHIFT)) & CCM_CCGR2_CG10_MASK)

#define CCM_CCGR2_CG11_MASK                      (0xC00000U)
#define CCM_CCGR2_CG11_SHIFT                     (22U)
#define CCM_CCGR2_CG11(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG11_SHIFT)) & CCM_CCGR2_CG11_MASK)

#define CCM_CCGR2_CG12_MASK                      (0x3000000U)
#define CCM_CCGR2_CG12_SHIFT                     (24U)
#define CCM_CCGR2_CG12(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG12_SHIFT)) & CCM_CCGR2_CG12_MASK)

#define CCM_CCGR2_CG13_MASK                      (0xC000000U)
#define CCM_CCGR2_CG13_SHIFT                     (26U)
#define CCM_CCGR2_CG13(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG13_SHIFT)) & CCM_CCGR2_CG13_MASK)

#define CCM_CCGR2_CG14_MASK                      (0x30000000U)
#define CCM_CCGR2_CG14_SHIFT                     (28U)
#define CCM_CCGR2_CG14(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG14_SHIFT)) & CCM_CCGR2_CG14_MASK)

#define CCM_CCGR2_CG15_MASK                      (0xC0000000U)
#define CCM_CCGR2_CG15_SHIFT                     (30U)
#define CCM_CCGR2_CG15(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR2_CG15_SHIFT)) & CCM_CCGR2_CG15_MASK)
/*! @} */

/*! @name CCGR3 - CCM Clock Gating Register 3 */
/*! @{ */

#define CCM_CCGR3_CG0_MASK                       (0x3U)
#define CCM_CCGR3_CG0_SHIFT                      (0U)
#define CCM_CCGR3_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG0_SHIFT)) & CCM_CCGR3_CG0_MASK)

#define CCM_CCGR3_CG1_MASK                       (0xCU)
#define CCM_CCGR3_CG1_SHIFT                      (2U)
#define CCM_CCGR3_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG1_SHIFT)) & CCM_CCGR3_CG1_MASK)

#define CCM_CCGR3_CG2_MASK                       (0x30U)
#define CCM_CCGR3_CG2_SHIFT                      (4U)
#define CCM_CCGR3_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG2_SHIFT)) & CCM_CCGR3_CG2_MASK)

#define CCM_CCGR3_CG3_MASK                       (0xC0U)
#define CCM_CCGR3_CG3_SHIFT                      (6U)
#define CCM_CCGR3_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG3_SHIFT)) & CCM_CCGR3_CG3_MASK)

#define CCM_CCGR3_CG4_MASK                       (0x300U)
#define CCM_CCGR3_CG4_SHIFT                      (8U)
#define CCM_CCGR3_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG4_SHIFT)) & CCM_CCGR3_CG4_MASK)

#define CCM_CCGR3_CG5_MASK                       (0xC00U)
#define CCM_CCGR3_CG5_SHIFT                      (10U)
#define CCM_CCGR3_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG5_SHIFT)) & CCM_CCGR3_CG5_MASK)

#define CCM_CCGR3_CG6_MASK                       (0x3000U)
#define CCM_CCGR3_CG6_SHIFT                      (12U)
#define CCM_CCGR3_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG6_SHIFT)) & CCM_CCGR3_CG6_MASK)

#define CCM_CCGR3_CG7_MASK                       (0xC000U)
#define CCM_CCGR3_CG7_SHIFT                      (14U)
#define CCM_CCGR3_CG7(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG7_SHIFT)) & CCM_CCGR3_CG7_MASK)

#define CCM_CCGR3_CG8_MASK                       (0x30000U)
#define CCM_CCGR3_CG8_SHIFT                      (16U)
#define CCM_CCGR3_CG8(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG8_SHIFT)) & CCM_CCGR3_CG8_MASK)

#define CCM_CCGR3_CG9_MASK                       (0xC0000U)
#define CCM_CCGR3_CG9_SHIFT                      (18U)
#define CCM_CCGR3_CG9(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG9_SHIFT)) & CCM_CCGR3_CG9_MASK)

#define CCM_CCGR3_CG10_MASK                      (0x300000U)
#define CCM_CCGR3_CG10_SHIFT                     (20U)
#define CCM_CCGR3_CG10(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG10_SHIFT)) & CCM_CCGR3_CG10_MASK)

#define CCM_CCGR3_CG11_MASK                      (0xC00000U)
#define CCM_CCGR3_CG11_SHIFT                     (22U)
#define CCM_CCGR3_CG11(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG11_SHIFT)) & CCM_CCGR3_CG11_MASK)

#define CCM_CCGR3_CG12_MASK                      (0x3000000U)
#define CCM_CCGR3_CG12_SHIFT                     (24U)
#define CCM_CCGR3_CG12(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG12_SHIFT)) & CCM_CCGR3_CG12_MASK)

#define CCM_CCGR3_CG13_MASK                      (0xC000000U)
#define CCM_CCGR3_CG13_SHIFT                     (26U)
#define CCM_CCGR3_CG13(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG13_SHIFT)) & CCM_CCGR3_CG13_MASK)

#define CCM_CCGR3_CG14_MASK                      (0x30000000U)
#define CCM_CCGR3_CG14_SHIFT                     (28U)
/*! CG14 - The OCRAM clock cannot be turned off when the CM cache is running on this device. */
#define CCM_CCGR3_CG14(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG14_SHIFT)) & CCM_CCGR3_CG14_MASK)

#define CCM_CCGR3_CG15_MASK                      (0xC0000000U)
#define CCM_CCGR3_CG15_SHIFT                     (30U)
#define CCM_CCGR3_CG15(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR3_CG15_SHIFT)) & CCM_CCGR3_CG15_MASK)
/*! @} */

/*! @name CCGR4 - CCM Clock Gating Register 4 */
/*! @{ */

#define CCM_CCGR4_CG0_MASK                       (0x3U)
#define CCM_CCGR4_CG0_SHIFT                      (0U)
#define CCM_CCGR4_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG0_SHIFT)) & CCM_CCGR4_CG0_MASK)

#define CCM_CCGR4_CG1_MASK                       (0xCU)
#define CCM_CCGR4_CG1_SHIFT                      (2U)
#define CCM_CCGR4_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG1_SHIFT)) & CCM_CCGR4_CG1_MASK)

#define CCM_CCGR4_CG2_MASK                       (0x30U)
#define CCM_CCGR4_CG2_SHIFT                      (4U)
#define CCM_CCGR4_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG2_SHIFT)) & CCM_CCGR4_CG2_MASK)

#define CCM_CCGR4_CG3_MASK                       (0xC0U)
#define CCM_CCGR4_CG3_SHIFT                      (6U)
#define CCM_CCGR4_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG3_SHIFT)) & CCM_CCGR4_CG3_MASK)

#define CCM_CCGR4_CG4_MASK                       (0x300U)
#define CCM_CCGR4_CG4_SHIFT                      (8U)
#define CCM_CCGR4_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG4_SHIFT)) & CCM_CCGR4_CG4_MASK)

#define CCM_CCGR4_CG5_MASK                       (0xC00U)
#define CCM_CCGR4_CG5_SHIFT                      (10U)
#define CCM_CCGR4_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG5_SHIFT)) & CCM_CCGR4_CG5_MASK)

#define CCM_CCGR4_CG6_MASK                       (0x3000U)
#define CCM_CCGR4_CG6_SHIFT                      (12U)
#define CCM_CCGR4_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG6_SHIFT)) & CCM_CCGR4_CG6_MASK)

#define CCM_CCGR4_CG7_MASK                       (0xC000U)
#define CCM_CCGR4_CG7_SHIFT                      (14U)
#define CCM_CCGR4_CG7(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG7_SHIFT)) & CCM_CCGR4_CG7_MASK)

#define CCM_CCGR4_CG8_MASK                       (0x30000U)
#define CCM_CCGR4_CG8_SHIFT                      (16U)
#define CCM_CCGR4_CG8(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG8_SHIFT)) & CCM_CCGR4_CG8_MASK)

#define CCM_CCGR4_CG9_MASK                       (0xC0000U)
#define CCM_CCGR4_CG9_SHIFT                      (18U)
#define CCM_CCGR4_CG9(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG9_SHIFT)) & CCM_CCGR4_CG9_MASK)

#define CCM_CCGR4_CG10_MASK                      (0x300000U)
#define CCM_CCGR4_CG10_SHIFT                     (20U)
#define CCM_CCGR4_CG10(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG10_SHIFT)) & CCM_CCGR4_CG10_MASK)

#define CCM_CCGR4_CG11_MASK                      (0xC00000U)
#define CCM_CCGR4_CG11_SHIFT                     (22U)
#define CCM_CCGR4_CG11(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG11_SHIFT)) & CCM_CCGR4_CG11_MASK)

#define CCM_CCGR4_CG12_MASK                      (0x3000000U)
#define CCM_CCGR4_CG12_SHIFT                     (24U)
#define CCM_CCGR4_CG12(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG12_SHIFT)) & CCM_CCGR4_CG12_MASK)

#define CCM_CCGR4_CG13_MASK                      (0xC000000U)
#define CCM_CCGR4_CG13_SHIFT                     (26U)
#define CCM_CCGR4_CG13(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG13_SHIFT)) & CCM_CCGR4_CG13_MASK)

#define CCM_CCGR4_CG14_MASK                      (0x30000000U)
#define CCM_CCGR4_CG14_SHIFT                     (28U)
#define CCM_CCGR4_CG14(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG14_SHIFT)) & CCM_CCGR4_CG14_MASK)

#define CCM_CCGR4_CG15_MASK                      (0xC0000000U)
#define CCM_CCGR4_CG15_SHIFT                     (30U)
#define CCM_CCGR4_CG15(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR4_CG15_SHIFT)) & CCM_CCGR4_CG15_MASK)
/*! @} */

/*! @name CCGR5 - CCM Clock Gating Register 5 */
/*! @{ */

#define CCM_CCGR5_CG0_MASK                       (0x3U)
#define CCM_CCGR5_CG0_SHIFT                      (0U)
#define CCM_CCGR5_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG0_SHIFT)) & CCM_CCGR5_CG0_MASK)

#define CCM_CCGR5_CG1_MASK                       (0xCU)
#define CCM_CCGR5_CG1_SHIFT                      (2U)
#define CCM_CCGR5_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG1_SHIFT)) & CCM_CCGR5_CG1_MASK)

#define CCM_CCGR5_CG2_MASK                       (0x30U)
#define CCM_CCGR5_CG2_SHIFT                      (4U)
#define CCM_CCGR5_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG2_SHIFT)) & CCM_CCGR5_CG2_MASK)

#define CCM_CCGR5_CG3_MASK                       (0xC0U)
#define CCM_CCGR5_CG3_SHIFT                      (6U)
#define CCM_CCGR5_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG3_SHIFT)) & CCM_CCGR5_CG3_MASK)

#define CCM_CCGR5_CG4_MASK                       (0x300U)
#define CCM_CCGR5_CG4_SHIFT                      (8U)
#define CCM_CCGR5_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG4_SHIFT)) & CCM_CCGR5_CG4_MASK)

#define CCM_CCGR5_CG5_MASK                       (0xC00U)
#define CCM_CCGR5_CG5_SHIFT                      (10U)
#define CCM_CCGR5_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG5_SHIFT)) & CCM_CCGR5_CG5_MASK)

#define CCM_CCGR5_CG6_MASK                       (0x3000U)
#define CCM_CCGR5_CG6_SHIFT                      (12U)
#define CCM_CCGR5_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG6_SHIFT)) & CCM_CCGR5_CG6_MASK)

#define CCM_CCGR5_CG7_MASK                       (0xC000U)
#define CCM_CCGR5_CG7_SHIFT                      (14U)
#define CCM_CCGR5_CG7(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG7_SHIFT)) & CCM_CCGR5_CG7_MASK)

#define CCM_CCGR5_CG8_MASK                       (0x30000U)
#define CCM_CCGR5_CG8_SHIFT                      (16U)
#define CCM_CCGR5_CG8(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG8_SHIFT)) & CCM_CCGR5_CG8_MASK)

#define CCM_CCGR5_CG9_MASK                       (0xC0000U)
#define CCM_CCGR5_CG9_SHIFT                      (18U)
#define CCM_CCGR5_CG9(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG9_SHIFT)) & CCM_CCGR5_CG9_MASK)

#define CCM_CCGR5_CG10_MASK                      (0x300000U)
#define CCM_CCGR5_CG10_SHIFT                     (20U)
#define CCM_CCGR5_CG10(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG10_SHIFT)) & CCM_CCGR5_CG10_MASK)

#define CCM_CCGR5_CG11_MASK                      (0xC00000U)
#define CCM_CCGR5_CG11_SHIFT                     (22U)
#define CCM_CCGR5_CG11(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG11_SHIFT)) & CCM_CCGR5_CG11_MASK)

#define CCM_CCGR5_CG12_MASK                      (0x3000000U)
#define CCM_CCGR5_CG12_SHIFT                     (24U)
#define CCM_CCGR5_CG12(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG12_SHIFT)) & CCM_CCGR5_CG12_MASK)

#define CCM_CCGR5_CG13_MASK                      (0xC000000U)
#define CCM_CCGR5_CG13_SHIFT                     (26U)
#define CCM_CCGR5_CG13(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG13_SHIFT)) & CCM_CCGR5_CG13_MASK)

#define CCM_CCGR5_CG14_MASK                      (0x30000000U)
#define CCM_CCGR5_CG14_SHIFT                     (28U)
#define CCM_CCGR5_CG14(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG14_SHIFT)) & CCM_CCGR5_CG14_MASK)

#define CCM_CCGR5_CG15_MASK                      (0xC0000000U)
#define CCM_CCGR5_CG15_SHIFT                     (30U)
#define CCM_CCGR5_CG15(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR5_CG15_SHIFT)) & CCM_CCGR5_CG15_MASK)
/*! @} */

/*! @name CCGR6 - CCM Clock Gating Register 6 */
/*! @{ */

#define CCM_CCGR6_CG0_MASK                       (0x3U)
#define CCM_CCGR6_CG0_SHIFT                      (0U)
#define CCM_CCGR6_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG0_SHIFT)) & CCM_CCGR6_CG0_MASK)

#define CCM_CCGR6_CG1_MASK                       (0xCU)
#define CCM_CCGR6_CG1_SHIFT                      (2U)
#define CCM_CCGR6_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG1_SHIFT)) & CCM_CCGR6_CG1_MASK)

#define CCM_CCGR6_CG2_MASK                       (0x30U)
#define CCM_CCGR6_CG2_SHIFT                      (4U)
#define CCM_CCGR6_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG2_SHIFT)) & CCM_CCGR6_CG2_MASK)

#define CCM_CCGR6_CG3_MASK                       (0xC0U)
#define CCM_CCGR6_CG3_SHIFT                      (6U)
#define CCM_CCGR6_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG3_SHIFT)) & CCM_CCGR6_CG3_MASK)

#define CCM_CCGR6_CG4_MASK                       (0x300U)
#define CCM_CCGR6_CG4_SHIFT                      (8U)
#define CCM_CCGR6_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG4_SHIFT)) & CCM_CCGR6_CG4_MASK)

#define CCM_CCGR6_CG5_MASK                       (0xC00U)
#define CCM_CCGR6_CG5_SHIFT                      (10U)
#define CCM_CCGR6_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG5_SHIFT)) & CCM_CCGR6_CG5_MASK)

#define CCM_CCGR6_CG6_MASK                       (0x3000U)
#define CCM_CCGR6_CG6_SHIFT                      (12U)
#define CCM_CCGR6_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG6_SHIFT)) & CCM_CCGR6_CG6_MASK)

#define CCM_CCGR6_CG7_MASK                       (0xC000U)
#define CCM_CCGR6_CG7_SHIFT                      (14U)
#define CCM_CCGR6_CG7(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG7_SHIFT)) & CCM_CCGR6_CG7_MASK)

#define CCM_CCGR6_CG8_MASK                       (0x30000U)
#define CCM_CCGR6_CG8_SHIFT                      (16U)
#define CCM_CCGR6_CG8(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG8_SHIFT)) & CCM_CCGR6_CG8_MASK)

#define CCM_CCGR6_CG9_MASK                       (0xC0000U)
#define CCM_CCGR6_CG9_SHIFT                      (18U)
#define CCM_CCGR6_CG9(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG9_SHIFT)) & CCM_CCGR6_CG9_MASK)

#define CCM_CCGR6_CG10_MASK                      (0x300000U)
#define CCM_CCGR6_CG10_SHIFT                     (20U)
#define CCM_CCGR6_CG10(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG10_SHIFT)) & CCM_CCGR6_CG10_MASK)

#define CCM_CCGR6_CG11_MASK                      (0xC00000U)
#define CCM_CCGR6_CG11_SHIFT                     (22U)
#define CCM_CCGR6_CG11(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG11_SHIFT)) & CCM_CCGR6_CG11_MASK)

#define CCM_CCGR6_CG12_MASK                      (0x3000000U)
#define CCM_CCGR6_CG12_SHIFT                     (24U)
#define CCM_CCGR6_CG12(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG12_SHIFT)) & CCM_CCGR6_CG12_MASK)

#define CCM_CCGR6_CG13_MASK                      (0xC000000U)
#define CCM_CCGR6_CG13_SHIFT                     (26U)
#define CCM_CCGR6_CG13(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG13_SHIFT)) & CCM_CCGR6_CG13_MASK)

#define CCM_CCGR6_CG14_MASK                      (0x30000000U)
#define CCM_CCGR6_CG14_SHIFT                     (28U)
#define CCM_CCGR6_CG14(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG14_SHIFT)) & CCM_CCGR6_CG14_MASK)

#define CCM_CCGR6_CG15_MASK                      (0xC0000000U)
#define CCM_CCGR6_CG15_SHIFT                     (30U)
#define CCM_CCGR6_CG15(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_CCGR6_CG15_SHIFT)) & CCM_CCGR6_CG15_MASK)
/*! @} */

/*! @name CCGR7 - CCM Clock Gating Register 7 */
/*! @{ */

#define CCM_CCGR7_CG0_MASK                       (0x3U)
#define CCM_CCGR7_CG0_SHIFT                      (0U)
#define CCM_CCGR7_CG0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR7_CG0_SHIFT)) & CCM_CCGR7_CG0_MASK)

#define CCM_CCGR7_CG1_MASK                       (0xCU)
#define CCM_CCGR7_CG1_SHIFT                      (2U)
#define CCM_CCGR7_CG1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR7_CG1_SHIFT)) & CCM_CCGR7_CG1_MASK)

#define CCM_CCGR7_CG2_MASK                       (0x30U)
#define CCM_CCGR7_CG2_SHIFT                      (4U)
#define CCM_CCGR7_CG2(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR7_CG2_SHIFT)) & CCM_CCGR7_CG2_MASK)

#define CCM_CCGR7_CG3_MASK                       (0xC0U)
#define CCM_CCGR7_CG3_SHIFT                      (6U)
#define CCM_CCGR7_CG3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR7_CG3_SHIFT)) & CCM_CCGR7_CG3_MASK)

#define CCM_CCGR7_CG4_MASK                       (0x300U)
#define CCM_CCGR7_CG4_SHIFT                      (8U)
#define CCM_CCGR7_CG4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR7_CG4_SHIFT)) & CCM_CCGR7_CG4_MASK)

#define CCM_CCGR7_CG5_MASK                       (0xC00U)
#define CCM_CCGR7_CG5_SHIFT                      (10U)
#define CCM_CCGR7_CG5(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR7_CG5_SHIFT)) & CCM_CCGR7_CG5_MASK)

#define CCM_CCGR7_CG6_MASK                       (0x3000U)
#define CCM_CCGR7_CG6_SHIFT                      (12U)
#define CCM_CCGR7_CG6(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_CCGR7_CG6_SHIFT)) & CCM_CCGR7_CG6_MASK)
/*! @} */

/*! @name CMEOR - CCM Module Enable Overide Register */
/*! @{ */

#define CCM_CMEOR_MOD_EN_OV_GPT_MASK             (0x20U)
#define CCM_CMEOR_MOD_EN_OV_GPT_SHIFT            (5U)
/*! MOD_EN_OV_GPT
 *  0b0..don't override module enable signal
 *  0b1..override module enable signal
 */
#define CCM_CMEOR_MOD_EN_OV_GPT(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CMEOR_MOD_EN_OV_GPT_SHIFT)) & CCM_CMEOR_MOD_EN_OV_GPT_MASK)

#define CCM_CMEOR_MOD_EN_OV_PIT_MASK             (0x40U)
#define CCM_CMEOR_MOD_EN_OV_PIT_SHIFT            (6U)
/*! MOD_EN_OV_PIT
 *  0b0..don't override module enable signal
 *  0b1..override module enable signal
 */
#define CCM_CMEOR_MOD_EN_OV_PIT(x)               (((uint32_t)(((uint32_t)(x)) << CCM_CMEOR_MOD_EN_OV_PIT_SHIFT)) & CCM_CMEOR_MOD_EN_OV_PIT_MASK)

#define CCM_CMEOR_MOD_EN_USDHC_MASK              (0x80U)
#define CCM_CMEOR_MOD_EN_USDHC_SHIFT             (7U)
/*! MOD_EN_USDHC
 *  0b0..don't override module enable signal
 *  0b1..override module enable signal
 */
#define CCM_CMEOR_MOD_EN_USDHC(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CMEOR_MOD_EN_USDHC_SHIFT)) & CCM_CMEOR_MOD_EN_USDHC_MASK)

#define CCM_CMEOR_MOD_EN_OV_TRNG_MASK            (0x200U)
#define CCM_CMEOR_MOD_EN_OV_TRNG_SHIFT           (9U)
/*! MOD_EN_OV_TRNG
 *  0b0..don't override module enable signal
 *  0b1..override module enable signal
 */
#define CCM_CMEOR_MOD_EN_OV_TRNG(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CMEOR_MOD_EN_OV_TRNG_SHIFT)) & CCM_CMEOR_MOD_EN_OV_TRNG_MASK)

#define CCM_CMEOR_MOD_EN_OV_CANFD_CPI_MASK       (0x400U)
#define CCM_CMEOR_MOD_EN_OV_CANFD_CPI_SHIFT      (10U)
/*! MOD_EN_OV_CANFD_CPI
 *  0b0..don't override module enable signal
 *  0b1..override module enable signal
 */
#define CCM_CMEOR_MOD_EN_OV_CANFD_CPI(x)         (((uint32_t)(((uint32_t)(x)) << CCM_CMEOR_MOD_EN_OV_CANFD_CPI_SHIFT)) & CCM_CMEOR_MOD_EN_OV_CANFD_CPI_MASK)

#define CCM_CMEOR_MOD_EN_OV_CAN2_CPI_MASK        (0x10000000U)
#define CCM_CMEOR_MOD_EN_OV_CAN2_CPI_SHIFT       (28U)
/*! MOD_EN_OV_CAN2_CPI
 *  0b0..don't override module enable signal
 *  0b1..override module enable signal
 */
#define CCM_CMEOR_MOD_EN_OV_CAN2_CPI(x)          (((uint32_t)(((uint32_t)(x)) << CCM_CMEOR_MOD_EN_OV_CAN2_CPI_SHIFT)) & CCM_CMEOR_MOD_EN_OV_CAN2_CPI_MASK)

#define CCM_CMEOR_MOD_EN_OV_CAN1_CPI_MASK        (0x40000000U)
#define CCM_CMEOR_MOD_EN_OV_CAN1_CPI_SHIFT       (30U)
/*! MOD_EN_OV_CAN1_CPI
 *  0b0..don't overide module enable signal
 *  0b1..overide module enable signal
 */
#define CCM_CMEOR_MOD_EN_OV_CAN1_CPI(x)          (((uint32_t)(((uint32_t)(x)) << CCM_CMEOR_MOD_EN_OV_CAN1_CPI_SHIFT)) & CCM_CMEOR_MOD_EN_OV_CAN1_CPI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CCM_Register_Masks */


/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */


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


#endif  /* PERI_CCM_H_ */

