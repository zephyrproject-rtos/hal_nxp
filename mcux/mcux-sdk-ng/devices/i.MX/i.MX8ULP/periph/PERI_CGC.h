/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CGC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CGC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CGC
 *
 * CMSIS Peripheral Access Layer for CGC
 */

#if !defined(PERI_CGC_H_)
#define PERI_CGC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CGC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGC_Peripheral_Access_Layer CGC Peripheral Access Layer
 * @{
 */

/** CGC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CM33CLK;                           /**< Clock Selection and Dividers for the M33 Domain, offset: 0x10 */
       uint8_t RESERVED_1[8];
  __IO uint32_t FUSIONCLK;                         /**< Clock Selection and Dividers for the Fusion DSP Domain, offset: 0x1C */
  __IO uint32_t CLKOUTCFG;                         /**< Clockout selection for Real Time Domain, offset: 0x20 */
       uint8_t RESERVED_2[108];
  __IO uint32_t CLKDIVRST;                         /**< Clk Dividers Reset, offset: 0x90 */
       uint8_t RESERVED_3[112];
  __IO uint32_t SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x104 */
  __IO uint32_t SOSCDIV;                           /**< Clock Dividers for the SYS OSC Oscillator, offset: 0x108 */
  __IO uint32_t SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x10C */
       uint8_t RESERVED_4[240];
  __IO uint32_t FROCSR;                            /**< FRO Control Status Register, offset: 0x200 */
  __IO uint32_t FROCTRL;                           /**< FRO Control Register, offset: 0x204 */
  __I  uint32_t FROCAPVAL;                         /**< FRO Cap Val Register, offset: 0x208 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FRORDTRIM;                         /**< RD Trim Values for FRO, offset: 0x210 */
  __IO uint32_t FROSCTRIM;                         /**< SC TRIM value for FRO, offset: 0x214 */
       uint8_t RESERVED_6[8];
  __IO uint32_t FRODIV;                            /**< Clock Dividers for the FFRO 192 MHz Oscillator, offset: 0x220 */
       uint8_t RESERVED_7[12];
  __I  uint32_t FRORDTRIM_FUSE;                    /**< Trim values loaded from fuses, offset: 0x230 */
       uint8_t RESERVED_8[12];
  __I  uint32_t FROSCTRIM_FUSE;                    /**< SC Trim Values loaded from fuses, offset: 0x240 */
       uint8_t RESERVED_9[188];
  __IO uint32_t LPOSCCSR;                          /**< Low Power OSC Control Status Register, offset: 0x300 */
  __IO uint32_t LPOSCCTRL;                         /**< LPO Oscillator Control Register, offset: 0x304 */
       uint8_t RESERVED_10[252];
  __IO uint32_t ROSCCTRL;                          /**< ROSCCSR, offset: 0x404 */
       uint8_t RESERVED_11[248];
  __IO uint32_t PLL0CSR;                           /**< System OSC Control Status Register, offset: 0x500 */
  __IO uint32_t PLL0DIV_VCO;                       /**< Clock Dividers for the fractional PLL0, offset: 0x504 */
  __IO uint32_t PLL0DIV_PFD_0;                     /**< Clock Dividers for the fractional PLL0, offset: 0x508 */
       uint8_t RESERVED_12[4];
  __IO uint32_t PLL0CFG;                           /**< PLL0 Register Enable, offset: 0x510 */
  __IO uint32_t PLL0PFDCFG;                        /**< PLL0 Configuration Register, offset: 0x514 */
       uint8_t RESERVED_13[12];
  __IO uint32_t PLL0LOCK;                          /**< PLL LOCK Configuration Register, offset: 0x524 */
       uint8_t RESERVED_14[216];
  __IO uint32_t PLL1CSR;                           /**< PLL1 Control Status Register, offset: 0x600 */
  __IO uint32_t PLL1DIV_VCO;                       /**< Clock Dividers for the fractional PLL1, offset: 0x604 */
  __IO uint32_t PLL1DIV_PFD_0;                     /**< Clock Dividers for the fractional PLL1, offset: 0x608 */
       uint8_t RESERVED_15[4];
  __IO uint32_t PLL1CFG;                           /**< PLL1 Configuration Register, offset: 0x610 */
  __IO uint32_t PLL1PFDCFG;                        /**< PLL1 Configuration Register, offset: 0x614 */
  __IO uint32_t PLL1DENOM;                         /**< PLL Denominator Register, offset: 0x618 */
  __IO uint32_t PLL1NUM;                           /**< PLL Numerator Register, offset: 0x61C */
  __IO uint32_t PLL1SS;                            /**< PLL Spread Spectrum Register, offset: 0x620 */
  __IO uint32_t PLL1LOCK;                          /**< PLL LOCK Configuration Register, offset: 0x624 */
       uint8_t RESERVED_16[480];
  __IO uint32_t RTCDIV;                            /**< Clock Dividers for the RTC Oscillator, offset: 0x808 */
       uint8_t RESERVED_17[244];
  __IO uint32_t AUD_CLK0;                          /**< AUD_CLK0 source to SAI0-3, offset: 0x900 */
  __IO uint32_t SAI3_0_CLK;                        /**< SAI3-0 Clock Source Selection, offset: 0x904 */
  __IO uint32_t TPM3_2CLK;                         /**< Multiplexer to select the audio clock connected to the TPM clock input, offset: 0x908 */
  __IO uint32_t MQS0CLK;                           /**< Multiplexer to select the audio clock connected to the MQS clock input, offset: 0x90C */
       uint8_t RESERVED_18[4];
  __IO uint32_t EMICFIL;                           /**< Multiplexer to select the eMICFIL clock source, offset: 0x914 */
} CGC_Type;

/* ----------------------------------------------------------------------------
   -- CGC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGC_Register_Masks CGC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define CGC_VERID_FEATURE_MASK                   (0xFFFFU)
#define CGC_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number */
#define CGC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_VERID_FEATURE_SHIFT)) & CGC_VERID_FEATURE_MASK)

#define CGC_VERID_MINOR_MASK                     (0xFF0000U)
#define CGC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define CGC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_VERID_MINOR_SHIFT)) & CGC_VERID_MINOR_MASK)

#define CGC_VERID_MAJOR_MASK                     (0xFF000000U)
#define CGC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define CGC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_VERID_MAJOR_SHIFT)) & CGC_VERID_MAJOR_MASK)
/*! @} */

/*! @name CM33CLK - Clock Selection and Dividers for the M33 Domain */
/*! @{ */

#define CGC_CM33CLK_DIVSLOW_MASK                 (0x3FU)
#define CGC_CM33CLK_DIVSLOW_SHIFT                (0U)
/*! DIVSLOW - Clock Division for Slow Clock */
#define CGC_CM33CLK_DIVSLOW(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_CM33CLK_DIVSLOW_SHIFT)) & CGC_CM33CLK_DIVSLOW_MASK)

#define CGC_CM33CLK_DIVBUS_MASK                  (0x1F80U)
#define CGC_CM33CLK_DIVBUS_SHIFT                 (7U)
/*! DIVBUS - Clock Division for Bus Clk */
#define CGC_CM33CLK_DIVBUS(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_CM33CLK_DIVBUS_SHIFT)) & CGC_CM33CLK_DIVBUS_MASK)

#define CGC_CM33CLK_DIVCORE_MASK                 (0x7E00000U)
#define CGC_CM33CLK_DIVCORE_SHIFT                (21U)
/*! DIVCORE - Clock Division for Core Clock */
#define CGC_CM33CLK_DIVCORE(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_CM33CLK_DIVCORE_SHIFT)) & CGC_CM33CLK_DIVCORE_MASK)

#define CGC_CM33CLK_SCSW_MASK                    (0x8000000U)
#define CGC_CM33CLK_SCSW_SHIFT                   (27U)
/*! SCSW - Clock switched to selected clock source */
#define CGC_CM33CLK_SCSW(x)                      (((uint32_t)(((uint32_t)(x)) << CGC_CM33CLK_SCSW_SHIFT)) & CGC_CM33CLK_SCSW_MASK)

#define CGC_CM33CLK_SCS_MASK                     (0x70000000U)
#define CGC_CM33CLK_SCS_SHIFT                    (28U)
/*! SCS - Clock Selection for M33 Domain */
#define CGC_CM33CLK_SCS(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_CM33CLK_SCS_SHIFT)) & CGC_CM33CLK_SCS_MASK)

#define CGC_CM33CLK_CM33LOCKED_MASK              (0x80000000U)
#define CGC_CM33CLK_CM33LOCKED_SHIFT             (31U)
/*! CM33LOCKED - CM33 CLK Register Locked */
#define CGC_CM33CLK_CM33LOCKED(x)                (((uint32_t)(((uint32_t)(x)) << CGC_CM33CLK_CM33LOCKED_SHIFT)) & CGC_CM33CLK_CM33LOCKED_MASK)
/*! @} */

/*! @name FUSIONCLK - Clock Selection and Dividers for the Fusion DSP Domain */
/*! @{ */

#define CGC_FUSIONCLK_DIVSLOW_MASK               (0x3FU)
#define CGC_FUSIONCLK_DIVSLOW_SHIFT              (0U)
/*! DIVSLOW - Clock Division for Slow Clock */
#define CGC_FUSIONCLK_DIVSLOW(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_FUSIONCLK_DIVSLOW_SHIFT)) & CGC_FUSIONCLK_DIVSLOW_MASK)

#define CGC_FUSIONCLK_DIVBUS_MASK                (0x1F80U)
#define CGC_FUSIONCLK_DIVBUS_SHIFT               (7U)
/*! DIVBUS - Clock Division for Bus Clk */
#define CGC_FUSIONCLK_DIVBUS(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_FUSIONCLK_DIVBUS_SHIFT)) & CGC_FUSIONCLK_DIVBUS_MASK)

#define CGC_FUSIONCLK_DIVCORE_MASK               (0x7E00000U)
#define CGC_FUSIONCLK_DIVCORE_SHIFT              (21U)
/*! DIVCORE - Clock Division for Core Clock */
#define CGC_FUSIONCLK_DIVCORE(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_FUSIONCLK_DIVCORE_SHIFT)) & CGC_FUSIONCLK_DIVCORE_MASK)

#define CGC_FUSIONCLK_SCSW_MASK                  (0x8000000U)
#define CGC_FUSIONCLK_SCSW_SHIFT                 (27U)
/*! SCSW - Clock switched to selected clock source */
#define CGC_FUSIONCLK_SCSW(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_FUSIONCLK_SCSW_SHIFT)) & CGC_FUSIONCLK_SCSW_MASK)

#define CGC_FUSIONCLK_SCS_MASK                   (0x70000000U)
#define CGC_FUSIONCLK_SCS_SHIFT                  (28U)
/*! SCS - Clock Selection for DSP Domain */
#define CGC_FUSIONCLK_SCS(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_FUSIONCLK_SCS_SHIFT)) & CGC_FUSIONCLK_SCS_MASK)

#define CGC_FUSIONCLK_FUSIONLOCKED_MASK          (0x80000000U)
#define CGC_FUSIONCLK_FUSIONLOCKED_SHIFT         (31U)
/*! FUSIONLOCKED - FUSION CLK Register Locked */
#define CGC_FUSIONCLK_FUSIONLOCKED(x)            (((uint32_t)(((uint32_t)(x)) << CGC_FUSIONCLK_FUSIONLOCKED_SHIFT)) & CGC_FUSIONCLK_FUSIONLOCKED_MASK)
/*! @} */

/*! @name CLKOUTCFG - Clockout selection for Real Time Domain */
/*! @{ */

#define CGC_CLKOUTCFG_CLKOUT_DIV_MASK            (0x7E0000U)
#define CGC_CLKOUTCFG_CLKOUT_DIV_SHIFT           (17U)
/*! CLKOUT_DIV - Select the clock division for the CLKOUT pin */
#define CGC_CLKOUTCFG_CLKOUT_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CGC_CLKOUTCFG_CLKOUT_DIV_SHIFT)) & CGC_CLKOUTCFG_CLKOUT_DIV_MASK)

#define CGC_CLKOUTCFG_CLKOUT_SEL_MASK            (0xF800000U)
#define CGC_CLKOUTCFG_CLKOUT_SEL_SHIFT           (23U)
/*! CLKOUT_SEL - Select the clock source redirected to CLKOUT pin */
#define CGC_CLKOUTCFG_CLKOUT_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CGC_CLKOUTCFG_CLKOUT_SEL_SHIFT)) & CGC_CLKOUTCFG_CLKOUT_SEL_MASK)

#define CGC_CLKOUTCFG_CLKOUT_EN_MASK             (0x10000000U)
#define CGC_CLKOUTCFG_CLKOUT_EN_SHIFT            (28U)
/*! CLKOUT_EN - Clockout Enable */
#define CGC_CLKOUTCFG_CLKOUT_EN(x)               (((uint32_t)(((uint32_t)(x)) << CGC_CLKOUTCFG_CLKOUT_EN_SHIFT)) & CGC_CLKOUTCFG_CLKOUT_EN_MASK)
/*! @} */

/*! @name CLKDIVRST - Clk Dividers Reset */
/*! @{ */

#define CGC_CLKDIVRST_FUSION_OUT_OF_PHASE_MASK   (0x1U)
#define CGC_CLKDIVRST_FUSION_OUT_OF_PHASE_SHIFT  (0U)
/*! FUSION_OUT_OF_PHASE - Fusion system clocks dividers reset */
#define CGC_CLKDIVRST_FUSION_OUT_OF_PHASE(x)     (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_FUSION_OUT_OF_PHASE_SHIFT)) & CGC_CLKDIVRST_FUSION_OUT_OF_PHASE_MASK)

#define CGC_CLKDIVRST_FUSION_RST_DIVIDERS_EN_MASK (0x2U)
#define CGC_CLKDIVRST_FUSION_RST_DIVIDERS_EN_SHIFT (1U)
/*! FUSION_RST_DIVIDERS_EN - Fusion system clocks dividers out of phase interrupt */
#define CGC_CLKDIVRST_FUSION_RST_DIVIDERS_EN(x)  (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_FUSION_RST_DIVIDERS_EN_SHIFT)) & CGC_CLKDIVRST_FUSION_RST_DIVIDERS_EN_MASK)

#define CGC_CLKDIVRST_FUSION_INTERRUPT_EN_MASK   (0x4U)
#define CGC_CLKDIVRST_FUSION_INTERRUPT_EN_SHIFT  (2U)
/*! FUSION_INTERRUPT_EN - Selection between interrupt generation or clock dividers reset when fusion system clocks are out of phase */
#define CGC_CLKDIVRST_FUSION_INTERRUPT_EN(x)     (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_FUSION_INTERRUPT_EN_SHIFT)) & CGC_CLKDIVRST_FUSION_INTERRUPT_EN_MASK)

#define CGC_CLKDIVRST_FUSION_RESET_EN_MASK       (0x8U)
#define CGC_CLKDIVRST_FUSION_RESET_EN_SHIFT      (3U)
/*! FUSION_RESET_EN - Enable of reset generation when fusion system clocks are out of phase */
#define CGC_CLKDIVRST_FUSION_RESET_EN(x)         (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_FUSION_RESET_EN_SHIFT)) & CGC_CLKDIVRST_FUSION_RESET_EN_MASK)

#define CGC_CLKDIVRST_CM33_OUT_OF_PHASE_MASK     (0x10000U)
#define CGC_CLKDIVRST_CM33_OUT_OF_PHASE_SHIFT    (16U)
/*! CM33_OUT_OF_PHASE - CM33 system clocks dividers reset */
#define CGC_CLKDIVRST_CM33_OUT_OF_PHASE(x)       (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_CM33_OUT_OF_PHASE_SHIFT)) & CGC_CLKDIVRST_CM33_OUT_OF_PHASE_MASK)

#define CGC_CLKDIVRST_CM33_RST_DIVIDERS_EN_MASK  (0x20000U)
#define CGC_CLKDIVRST_CM33_RST_DIVIDERS_EN_SHIFT (17U)
/*! CM33_RST_DIVIDERS_EN - CM33 system clocks dividers out of phase interrupt */
#define CGC_CLKDIVRST_CM33_RST_DIVIDERS_EN(x)    (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_CM33_RST_DIVIDERS_EN_SHIFT)) & CGC_CLKDIVRST_CM33_RST_DIVIDERS_EN_MASK)

#define CGC_CLKDIVRST_CM33_INTERRUPT_EN_MASK     (0x40000U)
#define CGC_CLKDIVRST_CM33_INTERRUPT_EN_SHIFT    (18U)
/*! CM33_INTERRUPT_EN - Selection between interrupt generation or clock dividers reset when cm33 system clocks are out of phase */
#define CGC_CLKDIVRST_CM33_INTERRUPT_EN(x)       (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_CM33_INTERRUPT_EN_SHIFT)) & CGC_CLKDIVRST_CM33_INTERRUPT_EN_MASK)

#define CGC_CLKDIVRST_CM33_RESET_EN_MASK         (0x80000U)
#define CGC_CLKDIVRST_CM33_RESET_EN_SHIFT        (19U)
/*! CM33_RESET_EN - Enable of reset generation when CM33 system clocks are out of phase */
#define CGC_CLKDIVRST_CM33_RESET_EN(x)           (((uint32_t)(((uint32_t)(x)) << CGC_CLKDIVRST_CM33_RESET_EN_SHIFT)) & CGC_CLKDIVRST_CM33_RESET_EN_MASK)
/*! @} */

/*! @name SOSCCSR - System OSC Control Status Register */
/*! @{ */

#define CGC_SOSCCSR_SOSCEN_MASK                  (0x1U)
#define CGC_SOSCCSR_SOSCEN_SHIFT                 (0U)
/*! SOSCEN - System OSC Enable */
#define CGC_SOSCCSR_SOSCEN(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCEN_SHIFT)) & CGC_SOSCCSR_SOSCEN_MASK)

#define CGC_SOSCCSR_SOSCDSEN_MASK                (0x2U)
#define CGC_SOSCCSR_SOSCDSEN_SHIFT               (1U)
/*! SOSCDSEN - System OSC Enable in Deep Sleep */
#define CGC_SOSCCSR_SOSCDSEN(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCDSEN_SHIFT)) & CGC_SOSCCSR_SOSCDSEN_MASK)

#define CGC_SOSCCSR_SOSCPDEN_MASK                (0x4U)
#define CGC_SOSCCSR_SOSCPDEN_SHIFT               (2U)
/*! SOSCPDEN - System OSC Enable in Power Down */
#define CGC_SOSCCSR_SOSCPDEN(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCPDEN_SHIFT)) & CGC_SOSCCSR_SOSCPDEN_MASK)

#define CGC_SOSCCSR_SOSCCM_MASK                  (0x10000U)
#define CGC_SOSCCSR_SOSCCM_SHIFT                 (16U)
/*! SOSCCM - System OSC Clock Monitor */
#define CGC_SOSCCSR_SOSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCCM_SHIFT)) & CGC_SOSCCSR_SOSCCM_MASK)

#define CGC_SOSCCSR_SOSCCMRE_MASK                (0x20000U)
#define CGC_SOSCCSR_SOSCCMRE_SHIFT               (17U)
/*! SOSCCMRE - System OSC Clock Monitor Reset Enable */
#define CGC_SOSCCSR_SOSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCCMRE_SHIFT)) & CGC_SOSCCSR_SOSCCMRE_MASK)

#define CGC_SOSCCSR_LK_MASK                      (0x800000U)
#define CGC_SOSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register */
#define CGC_SOSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_LK_SHIFT)) & CGC_SOSCCSR_LK_MASK)

#define CGC_SOSCCSR_SOSCVLD_MASK                 (0x1000000U)
#define CGC_SOSCCSR_SOSCVLD_SHIFT                (24U)
/*! SOSCVLD - System OSC Valid */
#define CGC_SOSCCSR_SOSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCVLD_SHIFT)) & CGC_SOSCCSR_SOSCVLD_MASK)

#define CGC_SOSCCSR_SOSCSEL_MASK                 (0x2000000U)
#define CGC_SOSCCSR_SOSCSEL_SHIFT                (25U)
/*! SOSCSEL - System OSC Selected */
#define CGC_SOSCCSR_SOSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCSEL_SHIFT)) & CGC_SOSCCSR_SOSCSEL_MASK)

#define CGC_SOSCCSR_SOSCERR_MASK                 (0x4000000U)
#define CGC_SOSCCSR_SOSCERR_SHIFT                (26U)
/*! SOSCERR - System OSC Clock Error */
#define CGC_SOSCCSR_SOSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCSR_SOSCERR_SHIFT)) & CGC_SOSCCSR_SOSCERR_MASK)
/*! @} */

/*! @name SOSCDIV - Clock Dividers for the SYS OSC Oscillator */
/*! @{ */

#define CGC_SOSCDIV_DIV1_MASK                    (0x3FU)
#define CGC_SOSCDIV_DIV1_SHIFT                   (0U)
/*! DIV1 - Clock Division for Slow Clock */
#define CGC_SOSCDIV_DIV1(x)                      (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV1_SHIFT)) & CGC_SOSCDIV_DIV1_MASK)

#define CGC_SOSCDIV_DIV1LOCKED_MASK              (0x40U)
#define CGC_SOSCDIV_DIV1LOCKED_SHIFT             (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_SOSCDIV_DIV1LOCKED(x)                (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV1LOCKED_SHIFT)) & CGC_SOSCDIV_DIV1LOCKED_MASK)

#define CGC_SOSCDIV_DIV1HALT_MASK                (0x80U)
#define CGC_SOSCDIV_DIV1HALT_SHIFT               (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_SOSCDIV_DIV1HALT(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV1HALT_SHIFT)) & CGC_SOSCDIV_DIV1HALT_MASK)

#define CGC_SOSCDIV_DIV2_MASK                    (0x3F00U)
#define CGC_SOSCDIV_DIV2_SHIFT                   (8U)
/*! DIV2 - Clock Division for Bus Clock */
#define CGC_SOSCDIV_DIV2(x)                      (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV2_SHIFT)) & CGC_SOSCDIV_DIV2_MASK)

#define CGC_SOSCDIV_DIV2LOCKED_MASK              (0x4000U)
#define CGC_SOSCDIV_DIV2LOCKED_SHIFT             (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked. */
#define CGC_SOSCDIV_DIV2LOCKED(x)                (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV2LOCKED_SHIFT)) & CGC_SOSCDIV_DIV2LOCKED_MASK)

#define CGC_SOSCDIV_DIV2HALT_MASK                (0x8000U)
#define CGC_SOSCDIV_DIV2HALT_SHIFT               (15U)
/*! DIV2HALT - Divider 1 Halted */
#define CGC_SOSCDIV_DIV2HALT(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV2HALT_SHIFT)) & CGC_SOSCDIV_DIV2HALT_MASK)

#define CGC_SOSCDIV_DIV3_MASK                    (0x3F0000U)
#define CGC_SOSCDIV_DIV3_SHIFT                   (16U)
/*! DIV3 - Clock Division for Platform Clock */
#define CGC_SOSCDIV_DIV3(x)                      (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV3_SHIFT)) & CGC_SOSCDIV_DIV3_MASK)

#define CGC_SOSCDIV_DIV3LOCKED_MASK              (0x400000U)
#define CGC_SOSCDIV_DIV3LOCKED_SHIFT             (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked. */
#define CGC_SOSCDIV_DIV3LOCKED(x)                (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV3LOCKED_SHIFT)) & CGC_SOSCDIV_DIV3LOCKED_MASK)

#define CGC_SOSCDIV_DIV3HALT_MASK                (0x800000U)
#define CGC_SOSCDIV_DIV3HALT_SHIFT               (23U)
/*! DIV3HALT - Divider 1 Halted */
#define CGC_SOSCDIV_DIV3HALT(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_SOSCDIV_DIV3HALT_SHIFT)) & CGC_SOSCDIV_DIV3HALT_MASK)
/*! @} */

/*! @name SOSCCFG - System Oscillator Configuration Register */
/*! @{ */

#define CGC_SOSCCFG_SYSOSC_BYPASS_EN_MASK        (0x4U)
#define CGC_SOSCCFG_SYSOSC_BYPASS_EN_SHIFT       (2U)
/*! SYSOSC_BYPASS_EN - System Oscillator Bypass Enable */
#define CGC_SOSCCFG_SYSOSC_BYPASS_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCFG_SYSOSC_BYPASS_EN_SHIFT)) & CGC_SOSCCFG_SYSOSC_BYPASS_EN_MASK)

#define CGC_SOSCCFG_HGO_MASK                     (0x8U)
#define CGC_SOSCCFG_HGO_SHIFT                    (3U)
/*! HGO - High Gain Oscillator Select */
#define CGC_SOSCCFG_HGO(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_SOSCCFG_HGO_SHIFT)) & CGC_SOSCCFG_HGO_MASK)
/*! @} */

/*! @name FROCSR - FRO Control Status Register */
/*! @{ */

#define CGC_FROCSR_FRODSEN_MASK                  (0x2U)
#define CGC_FROCSR_FRODSEN_SHIFT                 (1U)
/*! FRODSEN - FRO Enable in Sleep Mode */
#define CGC_FROCSR_FRODSEN(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_FROCSR_FRODSEN_SHIFT)) & CGC_FROCSR_FRODSEN_MASK)

#define CGC_FROCSR_LK_MASK                       (0x800000U)
#define CGC_FROCSR_LK_SHIFT                      (23U)
/*! LK - Lock Register */
#define CGC_FROCSR_LK(x)                         (((uint32_t)(((uint32_t)(x)) << CGC_FROCSR_LK_SHIFT)) & CGC_FROCSR_LK_MASK)

#define CGC_FROCSR_FROVLD_MASK                   (0x1000000U)
#define CGC_FROCSR_FROVLD_SHIFT                  (24U)
/*! FROVLD - FRO Valid */
#define CGC_FROCSR_FROVLD(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_FROCSR_FROVLD_SHIFT)) & CGC_FROCSR_FROVLD_MASK)

#define CGC_FROCSR_FROSEL_MASK                   (0x2000000U)
#define CGC_FROCSR_FROSEL_SHIFT                  (25U)
/*! FROSEL - FRO Selected */
#define CGC_FROCSR_FROSEL(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_FROCSR_FROSEL_SHIFT)) & CGC_FROCSR_FROSEL_MASK)
/*! @} */

/*! @name FROCTRL - FRO Control Register */
/*! @{ */

#define CGC_FROCTRL_EXP_COUNT_MASK               (0xFFFFU)
#define CGC_FROCTRL_EXP_COUNT_SHIFT              (0U)
/*! EXP_COUNT - Expected Count */
#define CGC_FROCTRL_EXP_COUNT(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_FROCTRL_EXP_COUNT_SHIFT)) & CGC_FROCTRL_EXP_COUNT_MASK)

#define CGC_FROCTRL_THRESH_RANGE_UP_MASK         (0x1F0000U)
#define CGC_FROCTRL_THRESH_RANGE_UP_SHIFT        (16U)
/*! THRESH_RANGE_UP - Threshold Range Upper Limit */
#define CGC_FROCTRL_THRESH_RANGE_UP(x)           (((uint32_t)(((uint32_t)(x)) << CGC_FROCTRL_THRESH_RANGE_UP_SHIFT)) & CGC_FROCTRL_THRESH_RANGE_UP_MASK)

#define CGC_FROCTRL_THRESH_RANGE_LOW_MASK        (0x3E00000U)
#define CGC_FROCTRL_THRESH_RANGE_LOW_SHIFT       (21U)
/*! THRESH_RANGE_LOW - Threshold Range Lower Limit */
#define CGC_FROCTRL_THRESH_RANGE_LOW(x)          (((uint32_t)(((uint32_t)(x)) << CGC_FROCTRL_THRESH_RANGE_LOW_SHIFT)) & CGC_FROCTRL_THRESH_RANGE_LOW_MASK)

#define CGC_FROCTRL_ENA_TUNE_MASK                (0x80000000U)
#define CGC_FROCTRL_ENA_TUNE_SHIFT               (31U)
/*! ENA_TUNE - Enable Tuning */
#define CGC_FROCTRL_ENA_TUNE(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_FROCTRL_ENA_TUNE_SHIFT)) & CGC_FROCTRL_ENA_TUNE_MASK)
/*! @} */

/*! @name FROCAPVAL - FRO Cap Val Register */
/*! @{ */

#define CGC_FROCAPVAL_CAPVAL_MASK                (0xFFFFU)
#define CGC_FROCAPVAL_CAPVAL_SHIFT               (0U)
/*! CAPVAL - Captured Value */
#define CGC_FROCAPVAL_CAPVAL(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_FROCAPVAL_CAPVAL_SHIFT)) & CGC_FROCAPVAL_CAPVAL_MASK)

#define CGC_FROCAPVAL_DATA_VALID_MASK            (0x80000000U)
#define CGC_FROCAPVAL_DATA_VALID_SHIFT           (31U)
/*! DATA_VALID - Data Valid */
#define CGC_FROCAPVAL_DATA_VALID(x)              (((uint32_t)(((uint32_t)(x)) << CGC_FROCAPVAL_DATA_VALID_SHIFT)) & CGC_FROCAPVAL_DATA_VALID_MASK)
/*! @} */

/*! @name FRORDTRIM - RD Trim Values for FRO */
/*! @{ */

#define CGC_FRORDTRIM_TRIM_MASK                  (0x7FFU)
#define CGC_FRORDTRIM_TRIM_SHIFT                 (0U)
/*! TRIM - Trim */
#define CGC_FRORDTRIM_TRIM(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_FRORDTRIM_TRIM_SHIFT)) & CGC_FRORDTRIM_TRIM_MASK)
/*! @} */

/*! @name FROSCTRIM - SC TRIM value for FRO */
/*! @{ */

#define CGC_FROSCTRIM_TRIM_MASK                  (0x3FU)
#define CGC_FROSCTRIM_TRIM_SHIFT                 (0U)
/*! TRIM - Switched Capacitor TRIM Value for FRO */
#define CGC_FROSCTRIM_TRIM(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_FROSCTRIM_TRIM_SHIFT)) & CGC_FROSCTRIM_TRIM_MASK)
/*! @} */

/*! @name FRODIV - Clock Dividers for the FFRO 192 MHz Oscillator */
/*! @{ */

#define CGC_FRODIV_DIV1_MASK                     (0x3FU)
#define CGC_FRODIV_DIV1_SHIFT                    (0U)
/*! DIV1 - Clock Division for Slow Clock */
#define CGC_FRODIV_DIV1(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV1_SHIFT)) & CGC_FRODIV_DIV1_MASK)

#define CGC_FRODIV_DIV1LOCKED_MASK               (0x40U)
#define CGC_FRODIV_DIV1LOCKED_SHIFT              (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked. */
#define CGC_FRODIV_DIV1LOCKED(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV1LOCKED_SHIFT)) & CGC_FRODIV_DIV1LOCKED_MASK)

#define CGC_FRODIV_DIV1HALT_MASK                 (0x80U)
#define CGC_FRODIV_DIV1HALT_SHIFT                (7U)
/*! DIV1HALT - Divider 1 Halted. */
#define CGC_FRODIV_DIV1HALT(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV1HALT_SHIFT)) & CGC_FRODIV_DIV1HALT_MASK)

#define CGC_FRODIV_DIV2_MASK                     (0x3F00U)
#define CGC_FRODIV_DIV2_SHIFT                    (8U)
/*! DIV2 - Clock Division for Bus Clock */
#define CGC_FRODIV_DIV2(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV2_SHIFT)) & CGC_FRODIV_DIV2_MASK)

#define CGC_FRODIV_DIV2LOCKED_MASK               (0x4000U)
#define CGC_FRODIV_DIV2LOCKED_SHIFT              (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked. */
#define CGC_FRODIV_DIV2LOCKED(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV2LOCKED_SHIFT)) & CGC_FRODIV_DIV2LOCKED_MASK)

#define CGC_FRODIV_DIV2HALT_MASK                 (0x8000U)
#define CGC_FRODIV_DIV2HALT_SHIFT                (15U)
/*! DIV2HALT - Divider 2 Halted. */
#define CGC_FRODIV_DIV2HALT(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV2HALT_SHIFT)) & CGC_FRODIV_DIV2HALT_MASK)

#define CGC_FRODIV_DIV3_MASK                     (0x3F0000U)
#define CGC_FRODIV_DIV3_SHIFT                    (16U)
/*! DIV3 - Clock Division for Platform Clock. */
#define CGC_FRODIV_DIV3(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV3_SHIFT)) & CGC_FRODIV_DIV3_MASK)

#define CGC_FRODIV_DIV3LOCKED_MASK               (0x400000U)
#define CGC_FRODIV_DIV3LOCKED_SHIFT              (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked. */
#define CGC_FRODIV_DIV3LOCKED(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV3LOCKED_SHIFT)) & CGC_FRODIV_DIV3LOCKED_MASK)

#define CGC_FRODIV_DIV3HALT_MASK                 (0x800000U)
#define CGC_FRODIV_DIV3HALT_SHIFT                (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_FRODIV_DIV3HALT(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_FRODIV_DIV3HALT_SHIFT)) & CGC_FRODIV_DIV3HALT_MASK)
/*! @} */

/*! @name FRORDTRIM_FUSE - Trim values loaded from fuses */
/*! @{ */

#define CGC_FRORDTRIM_FUSE_RD_TRIM_FROM_FUSES_MASK (0x7FFU)
#define CGC_FRORDTRIM_FUSE_RD_TRIM_FROM_FUSES_SHIFT (0U)
/*! RD_TRIM_FROM_FUSES - This register captures the value of FRO trim that were defined by fuses. */
#define CGC_FRORDTRIM_FUSE_RD_TRIM_FROM_FUSES(x) (((uint32_t)(((uint32_t)(x)) << CGC_FRORDTRIM_FUSE_RD_TRIM_FROM_FUSES_SHIFT)) & CGC_FRORDTRIM_FUSE_RD_TRIM_FROM_FUSES_MASK)
/*! @} */

/*! @name FROSCTRIM_FUSE - SC Trim Values loaded from fuses */
/*! @{ */

#define CGC_FROSCTRIM_FUSE_SC_TRIM_FROM_FUSES_MASK (0x3FU)
#define CGC_FROSCTRIM_FUSE_SC_TRIM_FROM_FUSES_SHIFT (0U)
/*! SC_TRIM_FROM_FUSES - SC TRIM Values loaded from fuses */
#define CGC_FROSCTRIM_FUSE_SC_TRIM_FROM_FUSES(x) (((uint32_t)(((uint32_t)(x)) << CGC_FROSCTRIM_FUSE_SC_TRIM_FROM_FUSES_SHIFT)) & CGC_FROSCTRIM_FUSE_SC_TRIM_FROM_FUSES_MASK)
/*! @} */

/*! @name LPOSCCSR - Low Power OSC Control Status Register */
/*! @{ */

#define CGC_LPOSCCSR_LPOSCEN_MASK                (0x1U)
#define CGC_LPOSCCSR_LPOSCEN_SHIFT               (0U)
/*! LPOSCEN - Low Power OSC Enable */
#define CGC_LPOSCCSR_LPOSCEN(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCSR_LPOSCEN_SHIFT)) & CGC_LPOSCCSR_LPOSCEN_MASK)

#define CGC_LPOSCCSR_LPOSCDSEN_MASK              (0x2U)
#define CGC_LPOSCCSR_LPOSCDSEN_SHIFT             (1U)
/*! LPOSCDSEN - Low Power OSC Enable in Deep Sleep */
#define CGC_LPOSCCSR_LPOSCDSEN(x)                (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCSR_LPOSCDSEN_SHIFT)) & CGC_LPOSCCSR_LPOSCDSEN_MASK)

#define CGC_LPOSCCSR_LPOSCPDEN_MASK              (0x4U)
#define CGC_LPOSCCSR_LPOSCPDEN_SHIFT             (2U)
/*! LPOSCPDEN - Low Power Oscilator Enable in Power Down */
#define CGC_LPOSCCSR_LPOSCPDEN(x)                (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCSR_LPOSCPDEN_SHIFT)) & CGC_LPOSCCSR_LPOSCPDEN_MASK)

#define CGC_LPOSCCSR_LK_MASK                     (0x800000U)
#define CGC_LPOSCCSR_LK_SHIFT                    (23U)
/*! LK - Lock Register */
#define CGC_LPOSCCSR_LK(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCSR_LK_SHIFT)) & CGC_LPOSCCSR_LK_MASK)

#define CGC_LPOSCCSR_LPOSCVLD_MASK               (0x1000000U)
#define CGC_LPOSCCSR_LPOSCVLD_SHIFT              (24U)
/*! LPOSCVLD - Low Power OSC Valid */
#define CGC_LPOSCCSR_LPOSCVLD(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCSR_LPOSCVLD_SHIFT)) & CGC_LPOSCCSR_LPOSCVLD_MASK)
/*! @} */

/*! @name LPOSCCTRL - LPO Oscillator Control Register */
/*! @{ */

#define CGC_LPOSCCTRL_BIASCURRENT_MASK           (0xFFU)
#define CGC_LPOSCCTRL_BIASCURRENT_SHIFT          (0U)
/*! BIASCURRENT - BIASCURRENT */
#define CGC_LPOSCCTRL_BIASCURRENT(x)             (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCTRL_BIASCURRENT_SHIFT)) & CGC_LPOSCCTRL_BIASCURRENT_MASK)

#define CGC_LPOSCCTRL_PTAT_MASK                  (0x3F00U)
#define CGC_LPOSCCTRL_PTAT_SHIFT                 (8U)
/*! PTAT - PTAT */
#define CGC_LPOSCCTRL_PTAT(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCTRL_PTAT_SHIFT)) & CGC_LPOSCCTRL_PTAT_MASK)

#define CGC_LPOSCCTRL_ZTC_MASK                   (0x3FC000U)
#define CGC_LPOSCCTRL_ZTC_SHIFT                  (14U)
/*! ZTC - ZTC */
#define CGC_LPOSCCTRL_ZTC(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCTRL_ZTC_SHIFT)) & CGC_LPOSCCTRL_ZTC_MASK)

#define CGC_LPOSCCTRL_DIS_ZTC_MASK               (0x400000U)
#define CGC_LPOSCCTRL_DIS_ZTC_SHIFT              (22U)
/*! DIS_ZTC - Disable ZTC */
#define CGC_LPOSCCTRL_DIS_ZTC(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_LPOSCCTRL_DIS_ZTC_SHIFT)) & CGC_LPOSCCTRL_DIS_ZTC_MASK)
/*! @} */

/*! @name ROSCCTRL - ROSCCSR */
/*! @{ */

#define CGC_ROSCCTRL_ROSCCM_MASK                 (0x10000U)
#define CGC_ROSCCTRL_ROSCCM_SHIFT                (16U)
/*! ROSCCM - RTC OSC Clock Monitor */
#define CGC_ROSCCTRL_ROSCCM(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_ROSCCTRL_ROSCCM_SHIFT)) & CGC_ROSCCTRL_ROSCCM_MASK)

#define CGC_ROSCCTRL_ROSCCMRE_MASK               (0x20000U)
#define CGC_ROSCCTRL_ROSCCMRE_SHIFT              (17U)
/*! ROSCCMRE - RTC OSC Clock Monitor Reset Enable */
#define CGC_ROSCCTRL_ROSCCMRE(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_ROSCCTRL_ROSCCMRE_SHIFT)) & CGC_ROSCCTRL_ROSCCMRE_MASK)

#define CGC_ROSCCTRL_LK_MASK                     (0x800000U)
#define CGC_ROSCCTRL_LK_SHIFT                    (23U)
/*! LK - Lock Register */
#define CGC_ROSCCTRL_LK(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_ROSCCTRL_LK_SHIFT)) & CGC_ROSCCTRL_LK_MASK)

#define CGC_ROSCCTRL_ROSCVLD_MASK                (0x1000000U)
#define CGC_ROSCCTRL_ROSCVLD_SHIFT               (24U)
/*! ROSCVLD - RTC OSC Valid */
#define CGC_ROSCCTRL_ROSCVLD(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_ROSCCTRL_ROSCVLD_SHIFT)) & CGC_ROSCCTRL_ROSCVLD_MASK)

#define CGC_ROSCCTRL_ROSCSEL_MASK                (0x2000000U)
#define CGC_ROSCCTRL_ROSCSEL_SHIFT               (25U)
/*! ROSCSEL - RTC OSC Selected */
#define CGC_ROSCCTRL_ROSCSEL(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_ROSCCTRL_ROSCSEL_SHIFT)) & CGC_ROSCCTRL_ROSCSEL_MASK)

#define CGC_ROSCCTRL_ROSCERR_MASK                (0x4000000U)
#define CGC_ROSCCTRL_ROSCERR_SHIFT               (26U)
/*! ROSCERR - RTC OSC Clock Error */
#define CGC_ROSCCTRL_ROSCERR(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_ROSCCTRL_ROSCERR_SHIFT)) & CGC_ROSCCTRL_ROSCERR_MASK)
/*! @} */

/*! @name PLL0CSR - System OSC Control Status Register */
/*! @{ */

#define CGC_PLL0CSR_PLL0EN_MASK                  (0x1U)
#define CGC_PLL0CSR_PLL0EN_SHIFT                 (0U)
/*! PLL0EN - PLL0 Enable */
#define CGC_PLL0CSR_PLL0EN(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CSR_PLL0EN_SHIFT)) & CGC_PLL0CSR_PLL0EN_MASK)

#define CGC_PLL0CSR_PLL0DSEN_MASK                (0x2U)
#define CGC_PLL0CSR_PLL0DSEN_SHIFT               (1U)
/*! PLL0DSEN - PLL0 Enable in Deep Sleep */
#define CGC_PLL0CSR_PLL0DSEN(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CSR_PLL0DSEN_SHIFT)) & CGC_PLL0CSR_PLL0DSEN_MASK)

#define CGC_PLL0CSR_LK_MASK                      (0x800000U)
#define CGC_PLL0CSR_LK_SHIFT                     (23U)
/*! LK - Lock Register */
#define CGC_PLL0CSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CSR_LK_SHIFT)) & CGC_PLL0CSR_LK_MASK)

#define CGC_PLL0CSR_PLLVLD_MASK                  (0x1000000U)
#define CGC_PLL0CSR_PLLVLD_SHIFT                 (24U)
/*! PLLVLD - PLL0 Valid */
#define CGC_PLL0CSR_PLLVLD(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CSR_PLLVLD_SHIFT)) & CGC_PLL0CSR_PLLVLD_MASK)

#define CGC_PLL0CSR_PLLSEL_MASK                  (0x2000000U)
#define CGC_PLL0CSR_PLLSEL_SHIFT                 (25U)
/*! PLLSEL - PLL0 Selected */
#define CGC_PLL0CSR_PLLSEL(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CSR_PLLSEL_SHIFT)) & CGC_PLL0CSR_PLLSEL_MASK)
/*! @} */

/*! @name PLL0DIV_VCO - Clock Dividers for the fractional PLL0 */
/*! @{ */

#define CGC_PLL0DIV_VCO_DIV1_MASK                (0x3FU)
#define CGC_PLL0DIV_VCO_DIV1_SHIFT               (0U)
/*! DIV1 - Clock Division for PLL0 VCO Clock */
#define CGC_PLL0DIV_VCO_DIV1(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_VCO_DIV1_SHIFT)) & CGC_PLL0DIV_VCO_DIV1_MASK)

#define CGC_PLL0DIV_VCO_DIV1LOCKED_MASK          (0x40U)
#define CGC_PLL0DIV_VCO_DIV1LOCKED_SHIFT         (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_PLL0DIV_VCO_DIV1LOCKED(x)            (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_VCO_DIV1LOCKED_SHIFT)) & CGC_PLL0DIV_VCO_DIV1LOCKED_MASK)

#define CGC_PLL0DIV_VCO_DIV1HALT_MASK            (0x80U)
#define CGC_PLL0DIV_VCO_DIV1HALT_SHIFT           (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_PLL0DIV_VCO_DIV1HALT(x)              (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_VCO_DIV1HALT_SHIFT)) & CGC_PLL0DIV_VCO_DIV1HALT_MASK)
/*! @} */

/*! @name PLL0DIV_PFD_0 - Clock Dividers for the fractional PLL0 */
/*! @{ */

#define CGC_PLL0DIV_PFD_0_DIV1_MASK              (0x3FU)
#define CGC_PLL0DIV_PFD_0_DIV1_SHIFT             (0U)
/*! DIV1 - Clock Division for PLL0 PFD1 Clock */
#define CGC_PLL0DIV_PFD_0_DIV1(x)                (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_PFD_0_DIV1_SHIFT)) & CGC_PLL0DIV_PFD_0_DIV1_MASK)

#define CGC_PLL0DIV_PFD_0_DIV1LOCKED_MASK        (0x40U)
#define CGC_PLL0DIV_PFD_0_DIV1LOCKED_SHIFT       (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_PLL0DIV_PFD_0_DIV1LOCKED(x)          (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_PFD_0_DIV1LOCKED_SHIFT)) & CGC_PLL0DIV_PFD_0_DIV1LOCKED_MASK)

#define CGC_PLL0DIV_PFD_0_DIV1HALT_MASK          (0x80U)
#define CGC_PLL0DIV_PFD_0_DIV1HALT_SHIFT         (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_PLL0DIV_PFD_0_DIV1HALT(x)            (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_PFD_0_DIV1HALT_SHIFT)) & CGC_PLL0DIV_PFD_0_DIV1HALT_MASK)

#define CGC_PLL0DIV_PFD_0_DIV2_MASK              (0x3F00U)
#define CGC_PLL0DIV_PFD_0_DIV2_SHIFT             (8U)
/*! DIV2 - Clock Division for PLL0 PFD2 Clock */
#define CGC_PLL0DIV_PFD_0_DIV2(x)                (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_PFD_0_DIV2_SHIFT)) & CGC_PLL0DIV_PFD_0_DIV2_MASK)

#define CGC_PLL0DIV_PFD_0_DIV2LOCKED_MASK        (0x4000U)
#define CGC_PLL0DIV_PFD_0_DIV2LOCKED_SHIFT       (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_PLL0DIV_PFD_0_DIV2LOCKED(x)          (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_PFD_0_DIV2LOCKED_SHIFT)) & CGC_PLL0DIV_PFD_0_DIV2LOCKED_MASK)

#define CGC_PLL0DIV_PFD_0_DIV2HALT_MASK          (0x8000U)
#define CGC_PLL0DIV_PFD_0_DIV2HALT_SHIFT         (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_PLL0DIV_PFD_0_DIV2HALT(x)            (((uint32_t)(((uint32_t)(x)) << CGC_PLL0DIV_PFD_0_DIV2HALT_SHIFT)) & CGC_PLL0DIV_PFD_0_DIV2HALT_MASK)
/*! @} */

/*! @name PLL0CFG - PLL0 Register Enable */
/*! @{ */

#define CGC_PLL0CFG_SOURCE_MASK                  (0x1U)
#define CGC_PLL0CFG_SOURCE_SHIFT                 (0U)
/*! SOURCE - Clock Source */
#define CGC_PLL0CFG_SOURCE(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CFG_SOURCE_SHIFT)) & CGC_PLL0CFG_SOURCE_MASK)

#define CGC_PLL0CFG_HALF_LR_R_MASK               (0x8U)
#define CGC_PLL0CFG_HALF_LR_R_SHIFT              (3U)
/*! HALF_LR_R - Half Resistor in Low Pass Filter */
#define CGC_PLL0CFG_HALF_LR_R(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CFG_HALF_LR_R_SHIFT)) & CGC_PLL0CFG_HALF_LR_R_MASK)

#define CGC_PLL0CFG_HALF_CP_CURRENT_MASK         (0x10U)
#define CGC_PLL0CFG_HALF_CP_CURRENT_SHIFT        (4U)
/*! HALF_CP_CURRENT - Half Charge Pump Current */
#define CGC_PLL0CFG_HALF_CP_CURRENT(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CFG_HALF_CP_CURRENT_SHIFT)) & CGC_PLL0CFG_HALF_CP_CURRENT_MASK)

#define CGC_PLL0CFG_DOUBLE_LF_R_MASK             (0x20U)
#define CGC_PLL0CFG_DOUBLE_LF_R_SHIFT            (5U)
/*! DOUBLE_LF_R - Double Resistor in Low Pass Filter */
#define CGC_PLL0CFG_DOUBLE_LF_R(x)               (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CFG_DOUBLE_LF_R_SHIFT)) & CGC_PLL0CFG_DOUBLE_LF_R_MASK)

#define CGC_PLL0CFG_DOUBLE_CP_CURRENT_MASK       (0x40U)
#define CGC_PLL0CFG_DOUBLE_CP_CURRENT_SHIFT      (6U)
/*! DOUBLE_CP_CURRENT - Double Charge Pump Current */
#define CGC_PLL0CFG_DOUBLE_CP_CURRENT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CFG_DOUBLE_CP_CURRENT_SHIFT)) & CGC_PLL0CFG_DOUBLE_CP_CURRENT_MASK)

#define CGC_PLL0CFG_HOLDRING_OFF_MASK            (0x2000U)
#define CGC_PLL0CFG_HOLDRING_OFF_SHIFT           (13U)
/*! HOLDRING_OFF - HOLDRING_OFF */
#define CGC_PLL0CFG_HOLDRING_OFF(x)              (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CFG_HOLDRING_OFF_SHIFT)) & CGC_PLL0CFG_HOLDRING_OFF_MASK)

#define CGC_PLL0CFG_MULT_MASK                    (0x70000U)
#define CGC_PLL0CFG_MULT_SHIFT                   (16U)
/*! MULT - System PLL Multiplier */
#define CGC_PLL0CFG_MULT(x)                      (((uint32_t)(((uint32_t)(x)) << CGC_PLL0CFG_MULT_SHIFT)) & CGC_PLL0CFG_MULT_MASK)
/*! @} */

/*! @name PLL0PFDCFG - PLL0 Configuration Register */
/*! @{ */

#define CGC_PLL0PFDCFG_PFD0_MASK                 (0x3FU)
#define CGC_PLL0PFDCFG_PFD0_SHIFT                (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CGC_PLL0PFDCFG_PFD0(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD0_SHIFT)) & CGC_PLL0PFDCFG_PFD0_MASK)

#define CGC_PLL0PFDCFG_PFD0_VALID_MASK           (0x40U)
#define CGC_PLL0PFDCFG_PFD0_VALID_SHIFT          (6U)
/*! PFD0_VALID - PFD0_VALID */
#define CGC_PLL0PFDCFG_PFD0_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD0_VALID_SHIFT)) & CGC_PLL0PFDCFG_PFD0_VALID_MASK)

#define CGC_PLL0PFDCFG_PFD0_CLKGATE_MASK         (0x80U)
#define CGC_PLL0PFDCFG_PFD0_CLKGATE_SHIFT        (7U)
/*! PFD0_CLKGATE - Clock gate of PFD0 */
#define CGC_PLL0PFDCFG_PFD0_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD0_CLKGATE_SHIFT)) & CGC_PLL0PFDCFG_PFD0_CLKGATE_MASK)

#define CGC_PLL0PFDCFG_PFD1_MASK                 (0x3F00U)
#define CGC_PLL0PFDCFG_PFD1_SHIFT                (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CGC_PLL0PFDCFG_PFD1(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD1_SHIFT)) & CGC_PLL0PFDCFG_PFD1_MASK)

#define CGC_PLL0PFDCFG_PFD1_VALID_MASK           (0x4000U)
#define CGC_PLL0PFDCFG_PFD1_VALID_SHIFT          (14U)
/*! PFD1_VALID - PFD1_VALID */
#define CGC_PLL0PFDCFG_PFD1_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD1_VALID_SHIFT)) & CGC_PLL0PFDCFG_PFD1_VALID_MASK)

#define CGC_PLL0PFDCFG_PFD1_CLKGATE_MASK         (0x8000U)
#define CGC_PLL0PFDCFG_PFD1_CLKGATE_SHIFT        (15U)
/*! PFD1_CLKGATE - Clock gate of PFD1 */
#define CGC_PLL0PFDCFG_PFD1_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD1_CLKGATE_SHIFT)) & CGC_PLL0PFDCFG_PFD1_CLKGATE_MASK)

#define CGC_PLL0PFDCFG_PFD2_MASK                 (0x3F0000U)
#define CGC_PLL0PFDCFG_PFD2_SHIFT                (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CGC_PLL0PFDCFG_PFD2(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD2_SHIFT)) & CGC_PLL0PFDCFG_PFD2_MASK)

#define CGC_PLL0PFDCFG_PFD2_VALID_MASK           (0x400000U)
#define CGC_PLL0PFDCFG_PFD2_VALID_SHIFT          (22U)
/*! PFD2_VALID - PFD2_VALID */
#define CGC_PLL0PFDCFG_PFD2_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD2_VALID_SHIFT)) & CGC_PLL0PFDCFG_PFD2_VALID_MASK)

#define CGC_PLL0PFDCFG_PFD2_CLKGATE_MASK         (0x800000U)
#define CGC_PLL0PFDCFG_PFD2_CLKGATE_SHIFT        (23U)
/*! PFD2_CLKGATE - Clock gate of PFD2 */
#define CGC_PLL0PFDCFG_PFD2_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD2_CLKGATE_SHIFT)) & CGC_PLL0PFDCFG_PFD2_CLKGATE_MASK)

#define CGC_PLL0PFDCFG_PFD3_MASK                 (0x3F000000U)
#define CGC_PLL0PFDCFG_PFD3_SHIFT                (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CGC_PLL0PFDCFG_PFD3(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD3_SHIFT)) & CGC_PLL0PFDCFG_PFD3_MASK)

#define CGC_PLL0PFDCFG_PFD3_VALID_MASK           (0x40000000U)
#define CGC_PLL0PFDCFG_PFD3_VALID_SHIFT          (30U)
/*! PFD3_VALID - PFD3_VALID */
#define CGC_PLL0PFDCFG_PFD3_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD3_VALID_SHIFT)) & CGC_PLL0PFDCFG_PFD3_VALID_MASK)

#define CGC_PLL0PFDCFG_PFD3_CLKGATE_MASK         (0x80000000U)
#define CGC_PLL0PFDCFG_PFD3_CLKGATE_SHIFT        (31U)
/*! PFD3_CLKGATE - Clock gate of PFD3 */
#define CGC_PLL0PFDCFG_PFD3_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL0PFDCFG_PFD3_CLKGATE_SHIFT)) & CGC_PLL0PFDCFG_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PLL0LOCK - PLL LOCK Configuration Register */
/*! @{ */

#define CGC_PLL0LOCK_LOCK_TIME_MASK              (0xFFFFU)
#define CGC_PLL0LOCK_LOCK_TIME_SHIFT             (0U)
/*! LOCK_TIME - LOCK_TIME */
#define CGC_PLL0LOCK_LOCK_TIME(x)                (((uint32_t)(((uint32_t)(x)) << CGC_PLL0LOCK_LOCK_TIME_SHIFT)) & CGC_PLL0LOCK_LOCK_TIME_MASK)
/*! @} */

/*! @name PLL1CSR - PLL1 Control Status Register */
/*! @{ */

#define CGC_PLL1CSR_PLLEN_MASK                   (0x1U)
#define CGC_PLL1CSR_PLLEN_SHIFT                  (0U)
/*! PLLEN - PLL Enable */
#define CGC_PLL1CSR_PLLEN(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CSR_PLLEN_SHIFT)) & CGC_PLL1CSR_PLLEN_MASK)

#define CGC_PLL1CSR_PLLDSEN_MASK                 (0x2U)
#define CGC_PLL1CSR_PLLDSEN_SHIFT                (1U)
/*! PLLDSEN - PLL1 Enable in Deep Sleep */
#define CGC_PLL1CSR_PLLDSEN(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CSR_PLLDSEN_SHIFT)) & CGC_PLL1CSR_PLLDSEN_MASK)

#define CGC_PLL1CSR_LK_MASK                      (0x800000U)
#define CGC_PLL1CSR_LK_SHIFT                     (23U)
/*! LK - Lock Register */
#define CGC_PLL1CSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CSR_LK_SHIFT)) & CGC_PLL1CSR_LK_MASK)

#define CGC_PLL1CSR_PLLVLD_MASK                  (0x1000000U)
#define CGC_PLL1CSR_PLLVLD_SHIFT                 (24U)
/*! PLLVLD - PLL1 Valid */
#define CGC_PLL1CSR_PLLVLD(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CSR_PLLVLD_SHIFT)) & CGC_PLL1CSR_PLLVLD_MASK)

#define CGC_PLL1CSR_PLLSEL_MASK                  (0x2000000U)
#define CGC_PLL1CSR_PLLSEL_SHIFT                 (25U)
/*! PLLSEL - PLL1 Selected */
#define CGC_PLL1CSR_PLLSEL(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CSR_PLLSEL_SHIFT)) & CGC_PLL1CSR_PLLSEL_MASK)
/*! @} */

/*! @name PLL1DIV_VCO - Clock Dividers for the fractional PLL1 */
/*! @{ */

#define CGC_PLL1DIV_VCO_DIV1_MASK                (0x3FU)
#define CGC_PLL1DIV_VCO_DIV1_SHIFT               (0U)
/*! DIV1 - Clock Division for PLL1 VCO Clock */
#define CGC_PLL1DIV_VCO_DIV1(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_VCO_DIV1_SHIFT)) & CGC_PLL1DIV_VCO_DIV1_MASK)

#define CGC_PLL1DIV_VCO_DIV1LOCKED_MASK          (0x40U)
#define CGC_PLL1DIV_VCO_DIV1LOCKED_SHIFT         (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_PLL1DIV_VCO_DIV1LOCKED(x)            (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_VCO_DIV1LOCKED_SHIFT)) & CGC_PLL1DIV_VCO_DIV1LOCKED_MASK)

#define CGC_PLL1DIV_VCO_DIV1HALT_MASK            (0x80U)
#define CGC_PLL1DIV_VCO_DIV1HALT_SHIFT           (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_PLL1DIV_VCO_DIV1HALT(x)              (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_VCO_DIV1HALT_SHIFT)) & CGC_PLL1DIV_VCO_DIV1HALT_MASK)
/*! @} */

/*! @name PLL1DIV_PFD_0 - Clock Dividers for the fractional PLL1 */
/*! @{ */

#define CGC_PLL1DIV_PFD_0_DIV1_MASK              (0x3FU)
#define CGC_PLL1DIV_PFD_0_DIV1_SHIFT             (0U)
/*! DIV1 - Clock Division for PLL1 PFD1 Clock */
#define CGC_PLL1DIV_PFD_0_DIV1(x)                (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_PFD_0_DIV1_SHIFT)) & CGC_PLL1DIV_PFD_0_DIV1_MASK)

#define CGC_PLL1DIV_PFD_0_DIV1LOCKED_MASK        (0x40U)
#define CGC_PLL1DIV_PFD_0_DIV1LOCKED_SHIFT       (6U)
/*! DIV1LOCKED - Write to DIV1 Locked */
#define CGC_PLL1DIV_PFD_0_DIV1LOCKED(x)          (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_PFD_0_DIV1LOCKED_SHIFT)) & CGC_PLL1DIV_PFD_0_DIV1LOCKED_MASK)

#define CGC_PLL1DIV_PFD_0_DIV1HALT_MASK          (0x80U)
#define CGC_PLL1DIV_PFD_0_DIV1HALT_SHIFT         (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_PLL1DIV_PFD_0_DIV1HALT(x)            (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_PFD_0_DIV1HALT_SHIFT)) & CGC_PLL1DIV_PFD_0_DIV1HALT_MASK)

#define CGC_PLL1DIV_PFD_0_DIV2_MASK              (0x3F00U)
#define CGC_PLL1DIV_PFD_0_DIV2_SHIFT             (8U)
/*! DIV2 - Clock Division for PLL1 PFD2 Clock */
#define CGC_PLL1DIV_PFD_0_DIV2(x)                (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_PFD_0_DIV2_SHIFT)) & CGC_PLL1DIV_PFD_0_DIV2_MASK)

#define CGC_PLL1DIV_PFD_0_DIV2LOCKED_MASK        (0x4000U)
#define CGC_PLL1DIV_PFD_0_DIV2LOCKED_SHIFT       (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked. */
#define CGC_PLL1DIV_PFD_0_DIV2LOCKED(x)          (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_PFD_0_DIV2LOCKED_SHIFT)) & CGC_PLL1DIV_PFD_0_DIV2LOCKED_MASK)

#define CGC_PLL1DIV_PFD_0_DIV2HALT_MASK          (0x8000U)
#define CGC_PLL1DIV_PFD_0_DIV2HALT_SHIFT         (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_PLL1DIV_PFD_0_DIV2HALT(x)            (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DIV_PFD_0_DIV2HALT_SHIFT)) & CGC_PLL1DIV_PFD_0_DIV2HALT_MASK)
/*! @} */

/*! @name PLL1CFG - PLL1 Configuration Register */
/*! @{ */

#define CGC_PLL1CFG_SOURCE_MASK                  (0x1U)
#define CGC_PLL1CFG_SOURCE_SHIFT                 (0U)
/*! SOURCE - Clock Source */
#define CGC_PLL1CFG_SOURCE(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_SOURCE_SHIFT)) & CGC_PLL1CFG_SOURCE_MASK)

#define CGC_PLL1CFG_HALF_LR_R_MASK               (0x8U)
#define CGC_PLL1CFG_HALF_LR_R_SHIFT              (3U)
/*! HALF_LR_R - Half Resistor in Low Pass Filter */
#define CGC_PLL1CFG_HALF_LR_R(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_HALF_LR_R_SHIFT)) & CGC_PLL1CFG_HALF_LR_R_MASK)

#define CGC_PLL1CFG_HALF_CP_CURRENT_MASK         (0x10U)
#define CGC_PLL1CFG_HALF_CP_CURRENT_SHIFT        (4U)
/*! HALF_CP_CURRENT - Half Charge Pump Current */
#define CGC_PLL1CFG_HALF_CP_CURRENT(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_HALF_CP_CURRENT_SHIFT)) & CGC_PLL1CFG_HALF_CP_CURRENT_MASK)

#define CGC_PLL1CFG_DOUBLE_LF_R_MASK             (0x20U)
#define CGC_PLL1CFG_DOUBLE_LF_R_SHIFT            (5U)
/*! DOUBLE_LF_R - Double Resistor in Low Pass Filter */
#define CGC_PLL1CFG_DOUBLE_LF_R(x)               (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_DOUBLE_LF_R_SHIFT)) & CGC_PLL1CFG_DOUBLE_LF_R_MASK)

#define CGC_PLL1CFG_DOUBLE_CP_CURRENT_MASK       (0x40U)
#define CGC_PLL1CFG_DOUBLE_CP_CURRENT_SHIFT      (6U)
/*! DOUBLE_CP_CURRENT - Double Charge Pump Current */
#define CGC_PLL1CFG_DOUBLE_CP_CURRENT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_DOUBLE_CP_CURRENT_SHIFT)) & CGC_PLL1CFG_DOUBLE_CP_CURRENT_MASK)

#define CGC_PLL1CFG_DITHER_EN_MASK               (0x800U)
#define CGC_PLL1CFG_DITHER_EN_SHIFT              (11U)
/*! DITHER_EN - DITHER_EN */
#define CGC_PLL1CFG_DITHER_EN(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_DITHER_EN_SHIFT)) & CGC_PLL1CFG_DITHER_EN_MASK)

#define CGC_PLL1CFG_PFD_OFFSET_EN_MASK           (0x1000U)
#define CGC_PLL1CFG_PFD_OFFSET_EN_SHIFT          (12U)
/*! PFD_OFFSET_EN - PFD_OFFSET_EN */
#define CGC_PLL1CFG_PFD_OFFSET_EN(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_PFD_OFFSET_EN_SHIFT)) & CGC_PLL1CFG_PFD_OFFSET_EN_MASK)

#define CGC_PLL1CFG_HOLDRING_OFF_MASK            (0x2000U)
#define CGC_PLL1CFG_HOLDRING_OFF_SHIFT           (13U)
/*! HOLDRING_OFF - Hold Ring Off Control */
#define CGC_PLL1CFG_HOLDRING_OFF(x)              (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_HOLDRING_OFF_SHIFT)) & CGC_PLL1CFG_HOLDRING_OFF_MASK)

#define CGC_PLL1CFG_MULT_MASK                    (0x7F0000U)
#define CGC_PLL1CFG_MULT_SHIFT                   (16U)
/*! MULT - System PLL Multiplier */
#define CGC_PLL1CFG_MULT(x)                      (((uint32_t)(((uint32_t)(x)) << CGC_PLL1CFG_MULT_SHIFT)) & CGC_PLL1CFG_MULT_MASK)
/*! @} */

/*! @name PLL1PFDCFG - PLL1 Configuration Register */
/*! @{ */

#define CGC_PLL1PFDCFG_PFD0_MASK                 (0x3FU)
#define CGC_PLL1PFDCFG_PFD0_SHIFT                (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CGC_PLL1PFDCFG_PFD0(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD0_SHIFT)) & CGC_PLL1PFDCFG_PFD0_MASK)

#define CGC_PLL1PFDCFG_PFD0_VALID_MASK           (0x40U)
#define CGC_PLL1PFDCFG_PFD0_VALID_SHIFT          (6U)
/*! PFD0_VALID - PFD0_VALID */
#define CGC_PLL1PFDCFG_PFD0_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD0_VALID_SHIFT)) & CGC_PLL1PFDCFG_PFD0_VALID_MASK)

#define CGC_PLL1PFDCFG_PFD0_CLKGATE_MASK         (0x80U)
#define CGC_PLL1PFDCFG_PFD0_CLKGATE_SHIFT        (7U)
/*! PFD0_CLKGATE - Clock gate of PFD0 */
#define CGC_PLL1PFDCFG_PFD0_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD0_CLKGATE_SHIFT)) & CGC_PLL1PFDCFG_PFD0_CLKGATE_MASK)

#define CGC_PLL1PFDCFG_PFD1_MASK                 (0x3F00U)
#define CGC_PLL1PFDCFG_PFD1_SHIFT                (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CGC_PLL1PFDCFG_PFD1(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD1_SHIFT)) & CGC_PLL1PFDCFG_PFD1_MASK)

#define CGC_PLL1PFDCFG_PFD1_VALID_MASK           (0x4000U)
#define CGC_PLL1PFDCFG_PFD1_VALID_SHIFT          (14U)
/*! PFD1_VALID - PFD1_VALID */
#define CGC_PLL1PFDCFG_PFD1_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD1_VALID_SHIFT)) & CGC_PLL1PFDCFG_PFD1_VALID_MASK)

#define CGC_PLL1PFDCFG_PFD1_CLKGATE_MASK         (0x8000U)
#define CGC_PLL1PFDCFG_PFD1_CLKGATE_SHIFT        (15U)
/*! PFD1_CLKGATE - Clock gate of PFD1 */
#define CGC_PLL1PFDCFG_PFD1_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD1_CLKGATE_SHIFT)) & CGC_PLL1PFDCFG_PFD1_CLKGATE_MASK)

#define CGC_PLL1PFDCFG_PFD2_MASK                 (0x3F0000U)
#define CGC_PLL1PFDCFG_PFD2_SHIFT                (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CGC_PLL1PFDCFG_PFD2(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD2_SHIFT)) & CGC_PLL1PFDCFG_PFD2_MASK)

#define CGC_PLL1PFDCFG_PFD2_VALID_MASK           (0x400000U)
#define CGC_PLL1PFDCFG_PFD2_VALID_SHIFT          (22U)
/*! PFD2_VALID - PFD2_VALID */
#define CGC_PLL1PFDCFG_PFD2_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD2_VALID_SHIFT)) & CGC_PLL1PFDCFG_PFD2_VALID_MASK)

#define CGC_PLL1PFDCFG_PFD2_CLKGATE_MASK         (0x800000U)
#define CGC_PLL1PFDCFG_PFD2_CLKGATE_SHIFT        (23U)
/*! PFD2_CLKGATE - Clock gate of PFD2 */
#define CGC_PLL1PFDCFG_PFD2_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD2_CLKGATE_SHIFT)) & CGC_PLL1PFDCFG_PFD2_CLKGATE_MASK)

#define CGC_PLL1PFDCFG_PFD3_MASK                 (0x3F000000U)
#define CGC_PLL1PFDCFG_PFD3_SHIFT                (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CGC_PLL1PFDCFG_PFD3(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD3_SHIFT)) & CGC_PLL1PFDCFG_PFD3_MASK)

#define CGC_PLL1PFDCFG_PFD3_VALID_MASK           (0x40000000U)
#define CGC_PLL1PFDCFG_PFD3_VALID_SHIFT          (30U)
/*! PFD3_VALID - PFD3_VALID */
#define CGC_PLL1PFDCFG_PFD3_VALID(x)             (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD3_VALID_SHIFT)) & CGC_PLL1PFDCFG_PFD3_VALID_MASK)

#define CGC_PLL1PFDCFG_PFD3_CLKGATE_MASK         (0x80000000U)
#define CGC_PLL1PFDCFG_PFD3_CLKGATE_SHIFT        (31U)
/*! PFD3_CLKGATE - Clock gate of PFD3 */
#define CGC_PLL1PFDCFG_PFD3_CLKGATE(x)           (((uint32_t)(((uint32_t)(x)) << CGC_PLL1PFDCFG_PFD3_CLKGATE_SHIFT)) & CGC_PLL1PFDCFG_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PLL1DENOM - PLL Denominator Register */
/*! @{ */

#define CGC_PLL1DENOM_DENOM_MASK                 (0x3FFFFFFFU)
#define CGC_PLL1DENOM_DENOM_SHIFT                (0U)
/*! DENOM - PLL Denominator Register */
#define CGC_PLL1DENOM_DENOM(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_PLL1DENOM_DENOM_SHIFT)) & CGC_PLL1DENOM_DENOM_MASK)
/*! @} */

/*! @name PLL1NUM - PLL Numerator Register */
/*! @{ */

#define CGC_PLL1NUM_NUM_MASK                     (0x3FFFFFFFU)
#define CGC_PLL1NUM_NUM_SHIFT                    (0U)
/*! NUM - PLL Numerator Register */
#define CGC_PLL1NUM_NUM(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_PLL1NUM_NUM_SHIFT)) & CGC_PLL1NUM_NUM_MASK)
/*! @} */

/*! @name PLL1SS - PLL Spread Spectrum Register */
/*! @{ */

#define CGC_PLL1SS_STEP_MASK                     (0x7FFFU)
#define CGC_PLL1SS_STEP_SHIFT                    (0U)
/*! STEP - STEP */
#define CGC_PLL1SS_STEP(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_PLL1SS_STEP_SHIFT)) & CGC_PLL1SS_STEP_MASK)

#define CGC_PLL1SS_ENABLE_MASK                   (0x8000U)
#define CGC_PLL1SS_ENABLE_SHIFT                  (15U)
/*! ENABLE - ENABLE */
#define CGC_PLL1SS_ENABLE(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_PLL1SS_ENABLE_SHIFT)) & CGC_PLL1SS_ENABLE_MASK)

#define CGC_PLL1SS_STOP_MASK                     (0xFFFF0000U)
#define CGC_PLL1SS_STOP_SHIFT                    (16U)
/*! STOP - STOP */
#define CGC_PLL1SS_STOP(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_PLL1SS_STOP_SHIFT)) & CGC_PLL1SS_STOP_MASK)
/*! @} */

/*! @name PLL1LOCK - PLL LOCK Configuration Register */
/*! @{ */

#define CGC_PLL1LOCK_LOCK_TIME_MASK              (0xFFFFU)
#define CGC_PLL1LOCK_LOCK_TIME_SHIFT             (0U)
/*! LOCK_TIME - LOCK_TIME */
#define CGC_PLL1LOCK_LOCK_TIME(x)                (((uint32_t)(((uint32_t)(x)) << CGC_PLL1LOCK_LOCK_TIME_SHIFT)) & CGC_PLL1LOCK_LOCK_TIME_MASK)
/*! @} */

/*! @name RTCDIV - Clock Dividers for the RTC Oscillator */
/*! @{ */

#define CGC_RTCDIV_DIV1_MASK                     (0x3FFU)
#define CGC_RTCDIV_DIV1_SHIFT                    (0U)
/*! DIV1 - Clock Division for Slow Clock */
#define CGC_RTCDIV_DIV1(x)                       (((uint32_t)(((uint32_t)(x)) << CGC_RTCDIV_DIV1_SHIFT)) & CGC_RTCDIV_DIV1_MASK)

#define CGC_RTCDIV_HALTDIV_MASK                  (0x400U)
#define CGC_RTCDIV_HALTDIV_SHIFT                 (10U)
/*! HALTDIV - RTC Divider Halted */
#define CGC_RTCDIV_HALTDIV(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_RTCDIV_HALTDIV_SHIFT)) & CGC_RTCDIV_HALTDIV_MASK)
/*! @} */

/*! @name AUD_CLK0 - AUD_CLK0 source to SAI0-3 */
/*! @{ */

#define CGC_AUD_CLK0_AUD_CLK0_MASK               (0xFU)
#define CGC_AUD_CLK0_AUD_CLK0_SHIFT              (0U)
/*! AUD_CLK0 - AUD_CLK0 Clock Source Selection */
#define CGC_AUD_CLK0_AUD_CLK0(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_AUD_CLK0_AUD_CLK0_SHIFT)) & CGC_AUD_CLK0_AUD_CLK0_MASK)
/*! @} */

/*! @name SAI3_0_CLK - SAI3-0 Clock Source Selection */
/*! @{ */

#define CGC_SAI3_0_CLK_SAI0CLK_MASK              (0x3U)
#define CGC_SAI3_0_CLK_SAI0CLK_SHIFT             (0U)
/*! SAI0CLK - Clock Source for SAI0 */
#define CGC_SAI3_0_CLK_SAI0CLK(x)                (((uint32_t)(((uint32_t)(x)) << CGC_SAI3_0_CLK_SAI0CLK_SHIFT)) & CGC_SAI3_0_CLK_SAI0CLK_MASK)

#define CGC_SAI3_0_CLK_SAI1CLK_MASK              (0x300U)
#define CGC_SAI3_0_CLK_SAI1CLK_SHIFT             (8U)
/*! SAI1CLK - Clock Source for SAI1 */
#define CGC_SAI3_0_CLK_SAI1CLK(x)                (((uint32_t)(((uint32_t)(x)) << CGC_SAI3_0_CLK_SAI1CLK_SHIFT)) & CGC_SAI3_0_CLK_SAI1CLK_MASK)

#define CGC_SAI3_0_CLK_SAI2CLK_MASK              (0x30000U)
#define CGC_SAI3_0_CLK_SAI2CLK_SHIFT             (16U)
/*! SAI2CLK - Clock Source for SAI2 */
#define CGC_SAI3_0_CLK_SAI2CLK(x)                (((uint32_t)(((uint32_t)(x)) << CGC_SAI3_0_CLK_SAI2CLK_SHIFT)) & CGC_SAI3_0_CLK_SAI2CLK_MASK)

#define CGC_SAI3_0_CLK_SAI3CLK_MASK              (0x3000000U)
#define CGC_SAI3_0_CLK_SAI3CLK_SHIFT             (24U)
/*! SAI3CLK - Clock Source for SAI3 */
#define CGC_SAI3_0_CLK_SAI3CLK(x)                (((uint32_t)(((uint32_t)(x)) << CGC_SAI3_0_CLK_SAI3CLK_SHIFT)) & CGC_SAI3_0_CLK_SAI3CLK_MASK)
/*! @} */

/*! @name TPM3_2CLK - Multiplexer to select the audio clock connected to the TPM clock input */
/*! @{ */

#define CGC_TPM3_2CLK_TPM2CLK_MASK               (0x3U)
#define CGC_TPM3_2CLK_TPM2CLK_SHIFT              (0U)
/*! TPM2CLK - Clock Selection for TPM2 */
#define CGC_TPM3_2CLK_TPM2CLK(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_TPM3_2CLK_TPM2CLK_SHIFT)) & CGC_TPM3_2CLK_TPM2CLK_MASK)

#define CGC_TPM3_2CLK_TPM3CLK_MASK               (0x300U)
#define CGC_TPM3_2CLK_TPM3CLK_SHIFT              (8U)
/*! TPM3CLK - Clock Selection for TPM3 */
#define CGC_TPM3_2CLK_TPM3CLK(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_TPM3_2CLK_TPM3CLK_SHIFT)) & CGC_TPM3_2CLK_TPM3CLK_MASK)
/*! @} */

/*! @name MQS0CLK - Multiplexer to select the audio clock connected to the MQS clock input */
/*! @{ */

#define CGC_MQS0CLK_MQS0CLK_MASK                 (0x3U)
#define CGC_MQS0CLK_MQS0CLK_SHIFT                (0U)
/*! MQS0CLK - Clock Selection for MQS0 */
#define CGC_MQS0CLK_MQS0CLK(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_MQS0CLK_MQS0CLK_SHIFT)) & CGC_MQS0CLK_MQS0CLK_MASK)
/*! @} */

/*! @name EMICFIL - Multiplexer to select the eMICFIL clock source */
/*! @{ */

#define CGC_EMICFIL_MICFILCLK_MASK               (0x7U)
#define CGC_EMICFIL_MICFILCLK_SHIFT              (0U)
/*! MICFILCLK - Clock Source for eMICFIL */
#define CGC_EMICFIL_MICFILCLK(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_EMICFIL_MICFILCLK_SHIFT)) & CGC_EMICFIL_MICFILCLK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CGC_Register_Masks */


/*!
 * @}
 */ /* end of group CGC_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_CGC_H_ */

