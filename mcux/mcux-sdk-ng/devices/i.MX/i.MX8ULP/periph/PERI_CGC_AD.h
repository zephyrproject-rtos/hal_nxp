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
**         CMSIS Peripheral Access Layer for CGC_AD
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
 * @file PERI_CGC_AD.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CGC_AD
 *
 * CMSIS Peripheral Access Layer for CGC_AD
 */

#if !defined(PERI_CGC_AD_H_)
#define PERI_CGC_AD_H_                           /**< Symbol preventing repeated inclusion */

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
   -- CGC_AD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGC_AD_Peripheral_Access_Layer CGC_AD Peripheral Access Layer
 * @{
 */

/** CGC_AD - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[16];
  __IO uint32_t CA35CLK;                           /**< Clock Selection and Dividers for the CA35 Domain, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CLKOUTCFG;                         /**< Clockout selection for Application Domain, offset: 0x20 */
       uint8_t RESERVED_2[16];
  __IO uint32_t NICCLK;                            /**< Clock Selection and Dividers for the NIC/XBAR Domain, offset: 0x34 */
  __IO uint32_t XBARCLK;                           /**< Clock Selection and Dividers for the NIC/XBAR Domain, offset: 0x38 */
       uint8_t RESERVED_3[84];
  __IO uint32_t CLKDIVRST;                         /**< Clk Dividers Reset, offset: 0x90 */
       uint8_t RESERVED_4[116];
  __IO uint32_t SOSCDIV;                           /**< Clock Dividers for the SYS OSC Oscillator, offset: 0x108 */
       uint8_t RESERVED_5[252];
  __IO uint32_t FRODIV;                            /**< Clock Dividers for the FFRO 192 MHz Oscillator, offset: 0x208 */
       uint8_t RESERVED_6[756];
  __IO uint32_t PLL2CSR;                           /**< PLL2 Control Status Register, offset: 0x500 */
       uint8_t RESERVED_7[12];
  __IO uint32_t PLL2CFG;                           /**< PLL2 Configuration Register, offset: 0x510 */
       uint8_t RESERVED_8[4];
  __IO uint32_t PLL2DENOM;                         /**< Fractional PLL2 Denominator Control Register, offset: 0x518 */
  __IO uint32_t PLL2NUM;                           /**< Fractional PLL2 Numerator Control Register, offset: 0x51C */
  __IO uint32_t PLL2SS;                            /**< Fractional PLL2 Spread Spectrum Control Register, offset: 0x520 */
       uint8_t RESERVED_9[220];
  __IO uint32_t PLL3CSR;                           /**< PLL3 Control Status Register, offset: 0x600 */
  __IO uint32_t PLL3DIV_VCO;                       /**< Clock Dividers for the fractional PLL3, offset: 0x604 */
  __IO uint32_t PLL3DIV_PFD_0;                     /**< Clock Dividers for the fractional PLL3, offset: 0x608 */
  __IO uint32_t PLL3DIV_PFD_1;                     /**< Clock Dividers for the fractional PLL3, offset: 0x60C */
  __IO uint32_t PLL3CFG;                           /**< PLL3 Configuration Register, offset: 0x610 */
  __IO uint32_t PLL3PFDCFG;                        /**< PLL3 Configuration Register, offset: 0x614 */
  __IO uint32_t PLL3DENOM;                         /**< PLL3 Denominator Register, offset: 0x618 */
  __IO uint32_t PLL3NUM;                           /**< PLL3 Numerator Register, offset: 0x61C */
  __IO uint32_t PLL3SS;                            /**< PLL3 Spread Spectrum Register, offset: 0x620 */
  __IO uint32_t PLL3LOCK;                          /**< PLL3 LOCK Configuration Register, offset: 0x624 */
       uint8_t RESERVED_10[216];
  __IO uint32_t ENETSTAMP;                         /**< Clock Selection for Ethernet Time Stamp, offset: 0x700 */
       uint8_t RESERVED_11[268];
  __IO uint32_t PLLUSBCFG;                         /**< PLLUSB Register Enable, offset: 0x810 */
       uint8_t RESERVED_12[236];
  __IO uint32_t AUD_CLK1;                          /**< AUD_CLK1 source to SAI4-5, offset: 0x900 */
  __IO uint32_t SAI5_4_CLK;                        /**< SAI5-4 Clock Source Selection, offset: 0x904 */
  __IO uint32_t TPM6_7CLK;                         /**< Multiplexer to select the audio clock connected to the TPM clock input, offset: 0x908 */
  __IO uint32_t MQS1CLK;                           /**< Multiplexer to select the audio clock connected to the MQS clock input, offset: 0x90C */
} CGC_AD_Type;

/* ----------------------------------------------------------------------------
   -- CGC_AD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGC_AD_Register_Masks CGC_AD Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define CGC_AD_VERID_FEATURE_MASK                (0xFFFFU)
#define CGC_AD_VERID_FEATURE_SHIFT               (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000010..Master only with standard feature set.
 *  0b0000000000000011..Master and slave with standard feature set.
 */
#define CGC_AD_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_AD_VERID_FEATURE_SHIFT)) & CGC_AD_VERID_FEATURE_MASK)

#define CGC_AD_VERID_MINOR_MASK                  (0xFF0000U)
#define CGC_AD_VERID_MINOR_SHIFT                 (16U)
/*! MINOR - Minor Version Number */
#define CGC_AD_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_VERID_MINOR_SHIFT)) & CGC_AD_VERID_MINOR_MASK)

#define CGC_AD_VERID_MAJOR_MASK                  (0xFF000000U)
#define CGC_AD_VERID_MAJOR_SHIFT                 (24U)
/*! MAJOR - Major Version Number */
#define CGC_AD_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_VERID_MAJOR_SHIFT)) & CGC_AD_VERID_MAJOR_MASK)
/*! @} */

/*! @name CA35CLK - Clock Selection and Dividers for the CA35 Domain */
/*! @{ */

#define CGC_AD_CA35CLK_DIVCORE_MASK              (0x7E00000U)
#define CGC_AD_CA35CLK_DIVCORE_SHIFT             (21U)
/*! DIVCORE - Clock Division for Core Clock */
#define CGC_AD_CA35CLK_DIVCORE(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_CA35CLK_DIVCORE_SHIFT)) & CGC_AD_CA35CLK_DIVCORE_MASK)

#define CGC_AD_CA35CLK_SCSW_MASK                 (0x8000000U)
#define CGC_AD_CA35CLK_SCSW_SHIFT                (27U)
/*! SCSW - Clock switched to selected clock source */
#define CGC_AD_CA35CLK_SCSW(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_AD_CA35CLK_SCSW_SHIFT)) & CGC_AD_CA35CLK_SCSW_MASK)

#define CGC_AD_CA35CLK_SCS_MASK                  (0x30000000U)
#define CGC_AD_CA35CLK_SCS_SHIFT                 (28U)
/*! SCS - Clock Selection for CA35 Domain */
#define CGC_AD_CA35CLK_SCS(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_CA35CLK_SCS_SHIFT)) & CGC_AD_CA35CLK_SCS_MASK)

#define CGC_AD_CA35CLK_CA35LOCKED_MASK           (0x80000000U)
#define CGC_AD_CA35CLK_CA35LOCKED_SHIFT          (31U)
/*! CA35LOCKED - CA35CLK Register Locked */
#define CGC_AD_CA35CLK_CA35LOCKED(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_CA35CLK_CA35LOCKED_SHIFT)) & CGC_AD_CA35CLK_CA35LOCKED_MASK)
/*! @} */

/*! @name CLKOUTCFG - Clockout selection for Application Domain */
/*! @{ */

#define CGC_AD_CLKOUTCFG_CLKOUT_DIV_MASK         (0x7E0000U)
#define CGC_AD_CLKOUTCFG_CLKOUT_DIV_SHIFT        (17U)
/*! CLKOUT_DIV - Select the clock division for the CLKOUT pin */
#define CGC_AD_CLKOUTCFG_CLKOUT_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CGC_AD_CLKOUTCFG_CLKOUT_DIV_SHIFT)) & CGC_AD_CLKOUTCFG_CLKOUT_DIV_MASK)

#define CGC_AD_CLKOUTCFG_CLKOUT_SEL_MASK         (0x7800000U)
#define CGC_AD_CLKOUTCFG_CLKOUT_SEL_SHIFT        (23U)
/*! CLKOUT_SEL - Select the clock source redirected to CLKOUT pin */
#define CGC_AD_CLKOUTCFG_CLKOUT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CGC_AD_CLKOUTCFG_CLKOUT_SEL_SHIFT)) & CGC_AD_CLKOUTCFG_CLKOUT_SEL_MASK)

#define CGC_AD_CLKOUTCFG_CLKOUT_EN_MASK          (0x10000000U)
#define CGC_AD_CLKOUTCFG_CLKOUT_EN_SHIFT         (28U)
/*! CLKOUT_EN - Clockout Enable */
#define CGC_AD_CLKOUTCFG_CLKOUT_EN(x)            (((uint32_t)(((uint32_t)(x)) << CGC_AD_CLKOUTCFG_CLKOUT_EN_SHIFT)) & CGC_AD_CLKOUTCFG_CLKOUT_EN_MASK)
/*! @} */

/*! @name NICCLK - Clock Selection and Dividers for the NIC/XBAR Domain */
/*! @{ */

#define CGC_AD_NICCLK_NIC_PER_DIVPLAT_MASK       (0xFC000U)
#define CGC_AD_NICCLK_NIC_PER_DIVPLAT_SHIFT      (14U)
/*! NIC_PER_DIVPLAT - Clock Division for Core Clock */
#define CGC_AD_NICCLK_NIC_PER_DIVPLAT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_NICCLK_NIC_PER_DIVPLAT_SHIFT)) & CGC_AD_NICCLK_NIC_PER_DIVPLAT_MASK)

#define CGC_AD_NICCLK_NIC_AD_DIVPLAT_MASK        (0x7E00000U)
#define CGC_AD_NICCLK_NIC_AD_DIVPLAT_SHIFT       (21U)
/*! NIC_AD_DIVPLAT - Clock Division for Platform Clock */
#define CGC_AD_NICCLK_NIC_AD_DIVPLAT(x)          (((uint32_t)(((uint32_t)(x)) << CGC_AD_NICCLK_NIC_AD_DIVPLAT_SHIFT)) & CGC_AD_NICCLK_NIC_AD_DIVPLAT_MASK)

#define CGC_AD_NICCLK_SCSW_MASK                  (0x8000000U)
#define CGC_AD_NICCLK_SCSW_SHIFT                 (27U)
/*! SCSW - Clock switched to selected clock source */
#define CGC_AD_NICCLK_SCSW(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_NICCLK_SCSW_SHIFT)) & CGC_AD_NICCLK_SCSW_MASK)

#define CGC_AD_NICCLK_SCS_MASK                   (0x30000000U)
#define CGC_AD_NICCLK_SCS_SHIFT                  (28U)
/*! SCS - Clock Selection for NIC Domain */
#define CGC_AD_NICCLK_SCS(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_AD_NICCLK_SCS_SHIFT)) & CGC_AD_NICCLK_SCS_MASK)

#define CGC_AD_NICCLK_NICLOCKED_MASK             (0x80000000U)
#define CGC_AD_NICCLK_NICLOCKED_SHIFT            (31U)
/*! NICLOCKED - NICCLK Register Locked */
#define CGC_AD_NICCLK_NICLOCKED(x)               (((uint32_t)(((uint32_t)(x)) << CGC_AD_NICCLK_NICLOCKED_SHIFT)) & CGC_AD_NICCLK_NICLOCKED_MASK)
/*! @} */

/*! @name XBARCLK - Clock Selection and Dividers for the NIC/XBAR Domain */
/*! @{ */

#define CGC_AD_XBARCLK_AD_SLOW_MASK              (0x3FU)
#define CGC_AD_XBARCLK_AD_SLOW_SHIFT             (0U)
/*! AD_SLOW - Clock Division for Slow Clock */
#define CGC_AD_XBARCLK_AD_SLOW(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_XBARCLK_AD_SLOW_SHIFT)) & CGC_AD_XBARCLK_AD_SLOW_MASK)

#define CGC_AD_XBARCLK_XBAR_DIVBUS_MASK          (0x1F80U)
#define CGC_AD_XBARCLK_XBAR_DIVBUS_SHIFT         (7U)
/*! XBAR_DIVBUS - Clock Division for Bus Clock */
#define CGC_AD_XBARCLK_XBAR_DIVBUS(x)            (((uint32_t)(((uint32_t)(x)) << CGC_AD_XBARCLK_XBAR_DIVBUS_SHIFT)) & CGC_AD_XBARCLK_XBAR_DIVBUS_MASK)

#define CGC_AD_XBARCLK_XBAR_AD_DIVPLAT_MASK      (0xFC000U)
#define CGC_AD_XBARCLK_XBAR_AD_DIVPLAT_SHIFT     (14U)
/*! XBAR_AD_DIVPLAT - Clock Division for Plat Clk */
#define CGC_AD_XBARCLK_XBAR_AD_DIVPLAT(x)        (((uint32_t)(((uint32_t)(x)) << CGC_AD_XBARCLK_XBAR_AD_DIVPLAT_SHIFT)) & CGC_AD_XBARCLK_XBAR_AD_DIVPLAT_MASK)

#define CGC_AD_XBARCLK_XBARLOCKED_MASK           (0x80000000U)
#define CGC_AD_XBARCLK_XBARLOCKED_SHIFT          (31U)
/*! XBARLOCKED - XBARCLK Register Locked */
#define CGC_AD_XBARCLK_XBARLOCKED(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_XBARCLK_XBARLOCKED_SHIFT)) & CGC_AD_XBARCLK_XBARLOCKED_MASK)
/*! @} */

/*! @name CLKDIVRST - Clk Dividers Reset */
/*! @{ */

#define CGC_AD_CLKDIVRST_NIC_OUT_OF_PHASE_MASK   (0x10000U)
#define CGC_AD_CLKDIVRST_NIC_OUT_OF_PHASE_SHIFT  (16U)
/*! NIC_OUT_OF_PHASE - NIC clocks dividers reset */
#define CGC_AD_CLKDIVRST_NIC_OUT_OF_PHASE(x)     (((uint32_t)(((uint32_t)(x)) << CGC_AD_CLKDIVRST_NIC_OUT_OF_PHASE_SHIFT)) & CGC_AD_CLKDIVRST_NIC_OUT_OF_PHASE_MASK)

#define CGC_AD_CLKDIVRST_NIC_RST_DIVIDERS_EN_MASK (0x20000U)
#define CGC_AD_CLKDIVRST_NIC_RST_DIVIDERS_EN_SHIFT (17U)
/*! NIC_RST_DIVIDERS_EN - NIC clocks dividers out of phase interrupt */
#define CGC_AD_CLKDIVRST_NIC_RST_DIVIDERS_EN(x)  (((uint32_t)(((uint32_t)(x)) << CGC_AD_CLKDIVRST_NIC_RST_DIVIDERS_EN_SHIFT)) & CGC_AD_CLKDIVRST_NIC_RST_DIVIDERS_EN_MASK)

#define CGC_AD_CLKDIVRST_NIC_INTERRUPT_EN_MASK   (0x40000U)
#define CGC_AD_CLKDIVRST_NIC_INTERRUPT_EN_SHIFT  (18U)
/*! NIC_INTERRUPT_EN - Selection between interrupt generation or clock dividers reset when NIC clocks are out of phase */
#define CGC_AD_CLKDIVRST_NIC_INTERRUPT_EN(x)     (((uint32_t)(((uint32_t)(x)) << CGC_AD_CLKDIVRST_NIC_INTERRUPT_EN_SHIFT)) & CGC_AD_CLKDIVRST_NIC_INTERRUPT_EN_MASK)

#define CGC_AD_CLKDIVRST_NIC_RESET_EN_MASK       (0x80000U)
#define CGC_AD_CLKDIVRST_NIC_RESET_EN_SHIFT      (19U)
#define CGC_AD_CLKDIVRST_NIC_RESET_EN(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_CLKDIVRST_NIC_RESET_EN_SHIFT)) & CGC_AD_CLKDIVRST_NIC_RESET_EN_MASK)
/*! @} */

/*! @name SOSCDIV - Clock Dividers for the SYS OSC Oscillator */
/*! @{ */

#define CGC_AD_SOSCDIV_DIV1_MASK                 (0x3FU)
#define CGC_AD_SOSCDIV_DIV1_SHIFT                (0U)
/*! DIV1 - Clock Division for Slow Clock */
#define CGC_AD_SOSCDIV_DIV1(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV1_SHIFT)) & CGC_AD_SOSCDIV_DIV1_MASK)

#define CGC_AD_SOSCDIV_DIV1LOCKED_MASK           (0x40U)
#define CGC_AD_SOSCDIV_DIV1LOCKED_SHIFT          (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_AD_SOSCDIV_DIV1LOCKED(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV1LOCKED_SHIFT)) & CGC_AD_SOSCDIV_DIV1LOCKED_MASK)

#define CGC_AD_SOSCDIV_DIV1HALT_MASK             (0x80U)
#define CGC_AD_SOSCDIV_DIV1HALT_SHIFT            (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_AD_SOSCDIV_DIV1HALT(x)               (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV1HALT_SHIFT)) & CGC_AD_SOSCDIV_DIV1HALT_MASK)

#define CGC_AD_SOSCDIV_DIV2_MASK                 (0x3F00U)
#define CGC_AD_SOSCDIV_DIV2_SHIFT                (8U)
/*! DIV2 - Clock Division for Bus Clock */
#define CGC_AD_SOSCDIV_DIV2(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV2_SHIFT)) & CGC_AD_SOSCDIV_DIV2_MASK)

#define CGC_AD_SOSCDIV_DIV2LOCKED_MASK           (0x4000U)
#define CGC_AD_SOSCDIV_DIV2LOCKED_SHIFT          (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_AD_SOSCDIV_DIV2LOCKED(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV2LOCKED_SHIFT)) & CGC_AD_SOSCDIV_DIV2LOCKED_MASK)

#define CGC_AD_SOSCDIV_DIV2HALT_MASK             (0x8000U)
#define CGC_AD_SOSCDIV_DIV2HALT_SHIFT            (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_AD_SOSCDIV_DIV2HALT(x)               (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV2HALT_SHIFT)) & CGC_AD_SOSCDIV_DIV2HALT_MASK)

#define CGC_AD_SOSCDIV_DIV3_MASK                 (0x3F0000U)
#define CGC_AD_SOSCDIV_DIV3_SHIFT                (16U)
/*! DIV3 - Clock Division for Platform Clock */
#define CGC_AD_SOSCDIV_DIV3(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV3_SHIFT)) & CGC_AD_SOSCDIV_DIV3_MASK)

#define CGC_AD_SOSCDIV_DIV3LOCKED_MASK           (0x400000U)
#define CGC_AD_SOSCDIV_DIV3LOCKED_SHIFT          (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked */
#define CGC_AD_SOSCDIV_DIV3LOCKED(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV3LOCKED_SHIFT)) & CGC_AD_SOSCDIV_DIV3LOCKED_MASK)

#define CGC_AD_SOSCDIV_DIV3HALT_MASK             (0x800000U)
#define CGC_AD_SOSCDIV_DIV3HALT_SHIFT            (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_AD_SOSCDIV_DIV3HALT(x)               (((uint32_t)(((uint32_t)(x)) << CGC_AD_SOSCDIV_DIV3HALT_SHIFT)) & CGC_AD_SOSCDIV_DIV3HALT_MASK)
/*! @} */

/*! @name FRODIV - Clock Dividers for the FFRO 192 MHz Oscillator */
/*! @{ */

#define CGC_AD_FRODIV_DIV1_MASK                  (0x3FU)
#define CGC_AD_FRODIV_DIV1_SHIFT                 (0U)
/*! DIV1 - Clock Division for FFRO Clock */
#define CGC_AD_FRODIV_DIV1(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV1_SHIFT)) & CGC_AD_FRODIV_DIV1_MASK)

#define CGC_AD_FRODIV_DIV1LOCKED_MASK            (0x40U)
#define CGC_AD_FRODIV_DIV1LOCKED_SHIFT           (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_AD_FRODIV_DIV1LOCKED(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV1LOCKED_SHIFT)) & CGC_AD_FRODIV_DIV1LOCKED_MASK)

#define CGC_AD_FRODIV_DIV1HALT_MASK              (0x80U)
#define CGC_AD_FRODIV_DIV1HALT_SHIFT             (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_AD_FRODIV_DIV1HALT(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV1HALT_SHIFT)) & CGC_AD_FRODIV_DIV1HALT_MASK)

#define CGC_AD_FRODIV_DIV2_MASK                  (0x3F00U)
#define CGC_AD_FRODIV_DIV2_SHIFT                 (8U)
/*! DIV2 - Clock Division for FFRO Clock */
#define CGC_AD_FRODIV_DIV2(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV2_SHIFT)) & CGC_AD_FRODIV_DIV2_MASK)

#define CGC_AD_FRODIV_DIV2LOCKED_MASK            (0x4000U)
#define CGC_AD_FRODIV_DIV2LOCKED_SHIFT           (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_AD_FRODIV_DIV2LOCKED(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV2LOCKED_SHIFT)) & CGC_AD_FRODIV_DIV2LOCKED_MASK)

#define CGC_AD_FRODIV_DIV2HALT_MASK              (0x8000U)
#define CGC_AD_FRODIV_DIV2HALT_SHIFT             (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_AD_FRODIV_DIV2HALT(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV2HALT_SHIFT)) & CGC_AD_FRODIV_DIV2HALT_MASK)

#define CGC_AD_FRODIV_DIV3_MASK                  (0x3F0000U)
#define CGC_AD_FRODIV_DIV3_SHIFT                 (16U)
/*! DIV3 - Clock Division for FFRO Clock */
#define CGC_AD_FRODIV_DIV3(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV3_SHIFT)) & CGC_AD_FRODIV_DIV3_MASK)

#define CGC_AD_FRODIV_DIV3LOCKED_MASK            (0x400000U)
#define CGC_AD_FRODIV_DIV3LOCKED_SHIFT           (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked */
#define CGC_AD_FRODIV_DIV3LOCKED(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV3LOCKED_SHIFT)) & CGC_AD_FRODIV_DIV3LOCKED_MASK)

#define CGC_AD_FRODIV_DIV3HALT_MASK              (0x800000U)
#define CGC_AD_FRODIV_DIV3HALT_SHIFT             (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_AD_FRODIV_DIV3HALT(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_FRODIV_DIV3HALT_SHIFT)) & CGC_AD_FRODIV_DIV3HALT_MASK)
/*! @} */

/*! @name PLL2CSR - PLL2 Control Status Register */
/*! @{ */

#define CGC_AD_PLL2CSR_PLLEN_MASK                (0x1U)
#define CGC_AD_PLL2CSR_PLLEN_SHIFT               (0U)
/*! PLLEN - PLL Enable */
#define CGC_AD_PLL2CSR_PLLEN(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2CSR_PLLEN_SHIFT)) & CGC_AD_PLL2CSR_PLLEN_MASK)

#define CGC_AD_PLL2CSR_PLLDSEN_MASK              (0x2U)
#define CGC_AD_PLL2CSR_PLLDSEN_SHIFT             (1U)
/*! PLLDSEN - PLL2 Enable in Deep Sleep */
#define CGC_AD_PLL2CSR_PLLDSEN(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2CSR_PLLDSEN_SHIFT)) & CGC_AD_PLL2CSR_PLLDSEN_MASK)

#define CGC_AD_PLL2CSR_LK_MASK                   (0x800000U)
#define CGC_AD_PLL2CSR_LK_SHIFT                  (23U)
/*! LK - Lock Register */
#define CGC_AD_PLL2CSR_LK(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2CSR_LK_SHIFT)) & CGC_AD_PLL2CSR_LK_MASK)

#define CGC_AD_PLL2CSR_PLLVLD_MASK               (0x1000000U)
#define CGC_AD_PLL2CSR_PLLVLD_SHIFT              (24U)
/*! PLLVLD - PLL Valid */
#define CGC_AD_PLL2CSR_PLLVLD(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2CSR_PLLVLD_SHIFT)) & CGC_AD_PLL2CSR_PLLVLD_MASK)

#define CGC_AD_PLL2CSR_PLLSEL_MASK               (0x2000000U)
#define CGC_AD_PLL2CSR_PLLSEL_SHIFT              (25U)
/*! PLLSEL - PLL Selected */
#define CGC_AD_PLL2CSR_PLLSEL(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2CSR_PLLSEL_SHIFT)) & CGC_AD_PLL2CSR_PLLSEL_MASK)
/*! @} */

/*! @name PLL2CFG - PLL2 Configuration Register */
/*! @{ */

#define CGC_AD_PLL2CFG_SOURCE_MASK               (0x1U)
#define CGC_AD_PLL2CFG_SOURCE_SHIFT              (0U)
/*! SOURCE - Clock Source */
#define CGC_AD_PLL2CFG_SOURCE(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2CFG_SOURCE_SHIFT)) & CGC_AD_PLL2CFG_SOURCE_MASK)

#define CGC_AD_PLL2CFG_MULT_MASK                 (0x7F0000U)
#define CGC_AD_PLL2CFG_MULT_SHIFT                (16U)
/*! MULT - System PLL Multiplier */
#define CGC_AD_PLL2CFG_MULT(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2CFG_MULT_SHIFT)) & CGC_AD_PLL2CFG_MULT_MASK)
/*! @} */

/*! @name PLL2DENOM - Fractional PLL2 Denominator Control Register */
/*! @{ */

#define CGC_AD_PLL2DENOM_DENOM_MASK              (0x3FFFFFFFU)
#define CGC_AD_PLL2DENOM_DENOM_SHIFT             (0U)
/*! DENOM - Denominator */
#define CGC_AD_PLL2DENOM_DENOM(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2DENOM_DENOM_SHIFT)) & CGC_AD_PLL2DENOM_DENOM_MASK)
/*! @} */

/*! @name PLL2NUM - Fractional PLL2 Numerator Control Register */
/*! @{ */

#define CGC_AD_PLL2NUM_NUM_MASK                  (0x3FFFFFFFU)
#define CGC_AD_PLL2NUM_NUM_SHIFT                 (0U)
/*! NUM - Numerator */
#define CGC_AD_PLL2NUM_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2NUM_NUM_SHIFT)) & CGC_AD_PLL2NUM_NUM_MASK)
/*! @} */

/*! @name PLL2SS - Fractional PLL2 Spread Spectrum Control Register */
/*! @{ */

#define CGC_AD_PLL2SS_STEP_MASK                  (0x7FFFU)
#define CGC_AD_PLL2SS_STEP_SHIFT                 (0U)
/*! STEP - Step */
#define CGC_AD_PLL2SS_STEP(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2SS_STEP_SHIFT)) & CGC_AD_PLL2SS_STEP_MASK)

#define CGC_AD_PLL2SS_ENABLE_MASK                (0x8000U)
#define CGC_AD_PLL2SS_ENABLE_SHIFT               (15U)
/*! ENABLE - Enable */
#define CGC_AD_PLL2SS_ENABLE(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2SS_ENABLE_SHIFT)) & CGC_AD_PLL2SS_ENABLE_MASK)

#define CGC_AD_PLL2SS_STOP_MASK                  (0xFFFF0000U)
#define CGC_AD_PLL2SS_STOP_SHIFT                 (16U)
/*! STOP - Stop */
#define CGC_AD_PLL2SS_STOP(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL2SS_STOP_SHIFT)) & CGC_AD_PLL2SS_STOP_MASK)
/*! @} */

/*! @name PLL3CSR - PLL3 Control Status Register */
/*! @{ */

#define CGC_AD_PLL3CSR_PLLEN_MASK                (0x1U)
#define CGC_AD_PLL3CSR_PLLEN_SHIFT               (0U)
/*! PLLEN - PLL Enable */
#define CGC_AD_PLL3CSR_PLLEN(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CSR_PLLEN_SHIFT)) & CGC_AD_PLL3CSR_PLLEN_MASK)

#define CGC_AD_PLL3CSR_PLLDSEN_MASK              (0x2U)
#define CGC_AD_PLL3CSR_PLLDSEN_SHIFT             (1U)
/*! PLLDSEN - PLL3 Enable in Deep Sleep */
#define CGC_AD_PLL3CSR_PLLDSEN(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CSR_PLLDSEN_SHIFT)) & CGC_AD_PLL3CSR_PLLDSEN_MASK)

#define CGC_AD_PLL3CSR_LK_MASK                   (0x800000U)
#define CGC_AD_PLL3CSR_LK_SHIFT                  (23U)
/*! LK - Lock Register */
#define CGC_AD_PLL3CSR_LK(x)                     (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CSR_LK_SHIFT)) & CGC_AD_PLL3CSR_LK_MASK)

#define CGC_AD_PLL3CSR_PLLVLD_MASK               (0x1000000U)
#define CGC_AD_PLL3CSR_PLLVLD_SHIFT              (24U)
/*! PLLVLD - PLL Valid */
#define CGC_AD_PLL3CSR_PLLVLD(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CSR_PLLVLD_SHIFT)) & CGC_AD_PLL3CSR_PLLVLD_MASK)

#define CGC_AD_PLL3CSR_PLLSEL_MASK               (0x2000000U)
#define CGC_AD_PLL3CSR_PLLSEL_SHIFT              (25U)
/*! PLLSEL - PLL Selected */
#define CGC_AD_PLL3CSR_PLLSEL(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CSR_PLLSEL_SHIFT)) & CGC_AD_PLL3CSR_PLLSEL_MASK)
/*! @} */

/*! @name PLL3DIV_VCO - Clock Dividers for the fractional PLL3 */
/*! @{ */

#define CGC_AD_PLL3DIV_VCO_DIV1_MASK             (0x3FU)
#define CGC_AD_PLL3DIV_VCO_DIV1_SHIFT            (0U)
/*! DIV1 - Clock Division for PLL3 VCO Clock */
#define CGC_AD_PLL3DIV_VCO_DIV1(x)               (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_VCO_DIV1_SHIFT)) & CGC_AD_PLL3DIV_VCO_DIV1_MASK)

#define CGC_AD_PLL3DIV_VCO_DIV1LOCKED_MASK       (0x40U)
#define CGC_AD_PLL3DIV_VCO_DIV1LOCKED_SHIFT      (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_AD_PLL3DIV_VCO_DIV1LOCKED(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_VCO_DIV1LOCKED_SHIFT)) & CGC_AD_PLL3DIV_VCO_DIV1LOCKED_MASK)

#define CGC_AD_PLL3DIV_VCO_DIV1HALT_MASK         (0x80U)
#define CGC_AD_PLL3DIV_VCO_DIV1HALT_SHIFT        (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_AD_PLL3DIV_VCO_DIV1HALT(x)           (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_VCO_DIV1HALT_SHIFT)) & CGC_AD_PLL3DIV_VCO_DIV1HALT_MASK)
/*! @} */

/*! @name PLL3DIV_PFD_0 - Clock Dividers for the fractional PLL3 */
/*! @{ */

#define CGC_AD_PLL3DIV_PFD_0_DIV1_MASK           (0x3FU)
#define CGC_AD_PLL3DIV_PFD_0_DIV1_SHIFT          (0U)
/*! DIV1 - Clock Division for PLL3 PFD0 Clock */
#define CGC_AD_PLL3DIV_PFD_0_DIV1(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV1_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV1_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV1LOCKED_MASK     (0x40U)
#define CGC_AD_PLL3DIV_PFD_0_DIV1LOCKED_SHIFT    (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_AD_PLL3DIV_PFD_0_DIV1LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV1LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV1LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV1HALT_MASK       (0x80U)
#define CGC_AD_PLL3DIV_PFD_0_DIV1HALT_SHIFT      (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_AD_PLL3DIV_PFD_0_DIV1HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV1HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV1HALT_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV2_MASK           (0x3F00U)
#define CGC_AD_PLL3DIV_PFD_0_DIV2_SHIFT          (8U)
/*! DIV2 - Clock Division for PLL3 PFD0 Clock */
#define CGC_AD_PLL3DIV_PFD_0_DIV2(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV2_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV2_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV2LOCKED_MASK     (0x4000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV2LOCKED_SHIFT    (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_AD_PLL3DIV_PFD_0_DIV2LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV2LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV2LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV2HALT_MASK       (0x8000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV2HALT_SHIFT      (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_AD_PLL3DIV_PFD_0_DIV2HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV2HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV2HALT_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV3_MASK           (0x3F0000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV3_SHIFT          (16U)
/*! DIV3 - Clock Division for PLL3 PFD1 Clock */
#define CGC_AD_PLL3DIV_PFD_0_DIV3(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV3_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV3_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV3LOCKED_MASK     (0x400000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV3LOCKED_SHIFT    (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked */
#define CGC_AD_PLL3DIV_PFD_0_DIV3LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV3LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV3LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV3HALT_MASK       (0x800000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV3HALT_SHIFT      (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_AD_PLL3DIV_PFD_0_DIV3HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV3HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV3HALT_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV4_MASK           (0x3F000000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV4_SHIFT          (24U)
/*! DIV4 - Clock Division for PLL3 PFD1 Clock */
#define CGC_AD_PLL3DIV_PFD_0_DIV4(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV4_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV4_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV4LOCKED_MASK     (0x40000000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV4LOCKED_SHIFT    (30U)
/*! DIV4LOCKED - The value of clock division was changed and access to DIV4 is locked */
#define CGC_AD_PLL3DIV_PFD_0_DIV4LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV4LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV4LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_0_DIV4HALT_MASK       (0x80000000U)
#define CGC_AD_PLL3DIV_PFD_0_DIV4HALT_SHIFT      (31U)
/*! DIV4HALT - Divider 4 Halted */
#define CGC_AD_PLL3DIV_PFD_0_DIV4HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_0_DIV4HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_0_DIV4HALT_MASK)
/*! @} */

/*! @name PLL3DIV_PFD_1 - Clock Dividers for the fractional PLL3 */
/*! @{ */

#define CGC_AD_PLL3DIV_PFD_1_DIV1_MASK           (0x3FU)
#define CGC_AD_PLL3DIV_PFD_1_DIV1_SHIFT          (0U)
/*! DIV1 - Clock Division for PLL3 PFD2 Clock */
#define CGC_AD_PLL3DIV_PFD_1_DIV1(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV1_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV1_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV1LOCKED_MASK     (0x40U)
#define CGC_AD_PLL3DIV_PFD_1_DIV1LOCKED_SHIFT    (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_AD_PLL3DIV_PFD_1_DIV1LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV1LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV1LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV1HALT_MASK       (0x80U)
#define CGC_AD_PLL3DIV_PFD_1_DIV1HALT_SHIFT      (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_AD_PLL3DIV_PFD_1_DIV1HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV1HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV1HALT_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV2_MASK           (0x3F00U)
#define CGC_AD_PLL3DIV_PFD_1_DIV2_SHIFT          (8U)
/*! DIV2 - Clock Division for PLL3 PFD2 Clock */
#define CGC_AD_PLL3DIV_PFD_1_DIV2(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV2_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV2_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV2LOCKED_MASK     (0x4000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV2LOCKED_SHIFT    (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_AD_PLL3DIV_PFD_1_DIV2LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV2LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV2LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV2HALT_MASK       (0x8000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV2HALT_SHIFT      (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_AD_PLL3DIV_PFD_1_DIV2HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV2HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV2HALT_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV3_MASK           (0x3F0000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV3_SHIFT          (16U)
/*! DIV3 - Clock Division for PLL3 PFD3 Clock */
#define CGC_AD_PLL3DIV_PFD_1_DIV3(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV3_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV3_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV3LOCKED_MASK     (0x400000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV3LOCKED_SHIFT    (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked */
#define CGC_AD_PLL3DIV_PFD_1_DIV3LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV3LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV3LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV3HALT_MASK       (0x800000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV3HALT_SHIFT      (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_AD_PLL3DIV_PFD_1_DIV3HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV3HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV3HALT_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV4_MASK           (0x3F000000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV4_SHIFT          (24U)
/*! DIV4 - Clock Division for PLL3 PFD3 Clock */
#define CGC_AD_PLL3DIV_PFD_1_DIV4(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV4_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV4_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV4LOCKED_MASK     (0x40000000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV4LOCKED_SHIFT    (30U)
/*! DIV4LOCKED - The value of clock division was changed and access to DIV4 is locked */
#define CGC_AD_PLL3DIV_PFD_1_DIV4LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV4LOCKED_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV4LOCKED_MASK)

#define CGC_AD_PLL3DIV_PFD_1_DIV4HALT_MASK       (0x80000000U)
#define CGC_AD_PLL3DIV_PFD_1_DIV4HALT_SHIFT      (31U)
/*! DIV4HALT - Divider 4 Halted */
#define CGC_AD_PLL3DIV_PFD_1_DIV4HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DIV_PFD_1_DIV4HALT_SHIFT)) & CGC_AD_PLL3DIV_PFD_1_DIV4HALT_MASK)
/*! @} */

/*! @name PLL3CFG - PLL3 Configuration Register */
/*! @{ */

#define CGC_AD_PLL3CFG_SOURCE_MASK               (0x1U)
#define CGC_AD_PLL3CFG_SOURCE_SHIFT              (0U)
/*! SOURCE - Clock Source */
#define CGC_AD_PLL3CFG_SOURCE(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_SOURCE_SHIFT)) & CGC_AD_PLL3CFG_SOURCE_MASK)

#define CGC_AD_PLL3CFG_HALF_LR_R_MASK            (0x8U)
#define CGC_AD_PLL3CFG_HALF_LR_R_SHIFT           (3U)
/*! HALF_LR_R - HALF_LR_R */
#define CGC_AD_PLL3CFG_HALF_LR_R(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_HALF_LR_R_SHIFT)) & CGC_AD_PLL3CFG_HALF_LR_R_MASK)

#define CGC_AD_PLL3CFG_HALF_CP_CURRENT_MASK      (0x10U)
#define CGC_AD_PLL3CFG_HALF_CP_CURRENT_SHIFT     (4U)
/*! HALF_CP_CURRENT - HALF_CP_CURRENT */
#define CGC_AD_PLL3CFG_HALF_CP_CURRENT(x)        (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_HALF_CP_CURRENT_SHIFT)) & CGC_AD_PLL3CFG_HALF_CP_CURRENT_MASK)

#define CGC_AD_PLL3CFG_DOUBLE_LF_R_MASK          (0x20U)
#define CGC_AD_PLL3CFG_DOUBLE_LF_R_SHIFT         (5U)
/*! DOUBLE_LF_R - DOUBLE_LF_R */
#define CGC_AD_PLL3CFG_DOUBLE_LF_R(x)            (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_DOUBLE_LF_R_SHIFT)) & CGC_AD_PLL3CFG_DOUBLE_LF_R_MASK)

#define CGC_AD_PLL3CFG_DOUBLE_CP_CURRENT_MASK    (0x40U)
#define CGC_AD_PLL3CFG_DOUBLE_CP_CURRENT_SHIFT   (6U)
/*! DOUBLE_CP_CURRENT - DOUBLE_CP_CURRENT */
#define CGC_AD_PLL3CFG_DOUBLE_CP_CURRENT(x)      (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_DOUBLE_CP_CURRENT_SHIFT)) & CGC_AD_PLL3CFG_DOUBLE_CP_CURRENT_MASK)

#define CGC_AD_PLL3CFG_DITHER_EN_MASK            (0x800U)
#define CGC_AD_PLL3CFG_DITHER_EN_SHIFT           (11U)
/*! DITHER_EN - DITHER_EN */
#define CGC_AD_PLL3CFG_DITHER_EN(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_DITHER_EN_SHIFT)) & CGC_AD_PLL3CFG_DITHER_EN_MASK)

#define CGC_AD_PLL3CFG_PFD_OFFSET_EN_MASK        (0x1000U)
#define CGC_AD_PLL3CFG_PFD_OFFSET_EN_SHIFT       (12U)
/*! PFD_OFFSET_EN - PFD_OFFSET_EN */
#define CGC_AD_PLL3CFG_PFD_OFFSET_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_PFD_OFFSET_EN_SHIFT)) & CGC_AD_PLL3CFG_PFD_OFFSET_EN_MASK)

#define CGC_AD_PLL3CFG_HOLDRING_OFF_MASK         (0x2000U)
#define CGC_AD_PLL3CFG_HOLDRING_OFF_SHIFT        (13U)
/*! HOLDRING_OFF - HOLDRING_OFF */
#define CGC_AD_PLL3CFG_HOLDRING_OFF(x)           (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_HOLDRING_OFF_SHIFT)) & CGC_AD_PLL3CFG_HOLDRING_OFF_MASK)

#define CGC_AD_PLL3CFG_MULT_MASK                 (0x7F0000U)
#define CGC_AD_PLL3CFG_MULT_SHIFT                (16U)
/*! MULT - System PLL Multiplier */
#define CGC_AD_PLL3CFG_MULT(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3CFG_MULT_SHIFT)) & CGC_AD_PLL3CFG_MULT_MASK)
/*! @} */

/*! @name PLL3PFDCFG - PLL3 Configuration Register */
/*! @{ */

#define CGC_AD_PLL3PFDCFG_PFD0_MASK              (0x3FU)
#define CGC_AD_PLL3PFDCFG_PFD0_SHIFT             (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CGC_AD_PLL3PFDCFG_PFD0(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD0_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD0_MASK)

#define CGC_AD_PLL3PFDCFG_PFD0_VALID_MASK        (0x40U)
#define CGC_AD_PLL3PFDCFG_PFD0_VALID_SHIFT       (6U)
/*! PFD0_VALID - PFD0_VALID */
#define CGC_AD_PLL3PFDCFG_PFD0_VALID(x)          (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD0_VALID_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD0_VALID_MASK)

#define CGC_AD_PLL3PFDCFG_PFD0_CLKGATE_MASK      (0x80U)
#define CGC_AD_PLL3PFDCFG_PFD0_CLKGATE_SHIFT     (7U)
/*! PFD0_CLKGATE - Clock gate of PFD0 */
#define CGC_AD_PLL3PFDCFG_PFD0_CLKGATE(x)        (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD0_CLKGATE_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD0_CLKGATE_MASK)

#define CGC_AD_PLL3PFDCFG_PFD1_MASK              (0x3F00U)
#define CGC_AD_PLL3PFDCFG_PFD1_SHIFT             (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CGC_AD_PLL3PFDCFG_PFD1(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD1_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD1_MASK)

#define CGC_AD_PLL3PFDCFG_PFD1_VALID_MASK        (0x4000U)
#define CGC_AD_PLL3PFDCFG_PFD1_VALID_SHIFT       (14U)
/*! PFD1_VALID - PFD1_VALID */
#define CGC_AD_PLL3PFDCFG_PFD1_VALID(x)          (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD1_VALID_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD1_VALID_MASK)

#define CGC_AD_PLL3PFDCFG_PFD1_CLKGATE_MASK      (0x8000U)
#define CGC_AD_PLL3PFDCFG_PFD1_CLKGATE_SHIFT     (15U)
/*! PFD1_CLKGATE - Clock gate of PFD1 */
#define CGC_AD_PLL3PFDCFG_PFD1_CLKGATE(x)        (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD1_CLKGATE_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD1_CLKGATE_MASK)

#define CGC_AD_PLL3PFDCFG_PFD2_MASK              (0x3F0000U)
#define CGC_AD_PLL3PFDCFG_PFD2_SHIFT             (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CGC_AD_PLL3PFDCFG_PFD2(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD2_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD2_MASK)

#define CGC_AD_PLL3PFDCFG_PFD2_VALID_MASK        (0x400000U)
#define CGC_AD_PLL3PFDCFG_PFD2_VALID_SHIFT       (22U)
/*! PFD2_VALID - PFD2_VALID */
#define CGC_AD_PLL3PFDCFG_PFD2_VALID(x)          (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD2_VALID_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD2_VALID_MASK)

#define CGC_AD_PLL3PFDCFG_PFD2_CLKGATE_MASK      (0x800000U)
#define CGC_AD_PLL3PFDCFG_PFD2_CLKGATE_SHIFT     (23U)
/*! PFD2_CLKGATE - Clock gate of PFD2 */
#define CGC_AD_PLL3PFDCFG_PFD2_CLKGATE(x)        (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD2_CLKGATE_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD2_CLKGATE_MASK)

#define CGC_AD_PLL3PFDCFG_PFD3_MASK              (0x3F000000U)
#define CGC_AD_PLL3PFDCFG_PFD3_SHIFT             (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CGC_AD_PLL3PFDCFG_PFD3(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD3_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD3_MASK)

#define CGC_AD_PLL3PFDCFG_PFD3_VALID_MASK        (0x40000000U)
#define CGC_AD_PLL3PFDCFG_PFD3_VALID_SHIFT       (30U)
/*! PFD3_VALID - PFD3_VALID */
#define CGC_AD_PLL3PFDCFG_PFD3_VALID(x)          (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD3_VALID_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD3_VALID_MASK)

#define CGC_AD_PLL3PFDCFG_PFD3_CLKGATE_MASK      (0x80000000U)
#define CGC_AD_PLL3PFDCFG_PFD3_CLKGATE_SHIFT     (31U)
/*! PFD3_CLKGATE - Clock gate of PFD3 */
#define CGC_AD_PLL3PFDCFG_PFD3_CLKGATE(x)        (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3PFDCFG_PFD3_CLKGATE_SHIFT)) & CGC_AD_PLL3PFDCFG_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PLL3DENOM - PLL3 Denominator Register */
/*! @{ */

#define CGC_AD_PLL3DENOM_DENOM_MASK              (0x3FFFFFFFU)
#define CGC_AD_PLL3DENOM_DENOM_SHIFT             (0U)
/*! DENOM - PLL Denominator Register */
#define CGC_AD_PLL3DENOM_DENOM(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3DENOM_DENOM_SHIFT)) & CGC_AD_PLL3DENOM_DENOM_MASK)
/*! @} */

/*! @name PLL3NUM - PLL3 Numerator Register */
/*! @{ */

#define CGC_AD_PLL3NUM_NUM_MASK                  (0x3FFFFFFFU)
#define CGC_AD_PLL3NUM_NUM_SHIFT                 (0U)
/*! NUM - PLL Numerator Register */
#define CGC_AD_PLL3NUM_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3NUM_NUM_SHIFT)) & CGC_AD_PLL3NUM_NUM_MASK)
/*! @} */

/*! @name PLL3SS - PLL3 Spread Spectrum Register */
/*! @{ */

#define CGC_AD_PLL3SS_STEP_MASK                  (0x7FFFU)
#define CGC_AD_PLL3SS_STEP_SHIFT                 (0U)
/*! STEP - STEP */
#define CGC_AD_PLL3SS_STEP(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3SS_STEP_SHIFT)) & CGC_AD_PLL3SS_STEP_MASK)

#define CGC_AD_PLL3SS_ENABLE_MASK                (0x8000U)
#define CGC_AD_PLL3SS_ENABLE_SHIFT               (15U)
/*! ENABLE - ENABLE */
#define CGC_AD_PLL3SS_ENABLE(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3SS_ENABLE_SHIFT)) & CGC_AD_PLL3SS_ENABLE_MASK)

#define CGC_AD_PLL3SS_STOP_MASK                  (0xFFFF0000U)
#define CGC_AD_PLL3SS_STOP_SHIFT                 (16U)
/*! STOP - STOP */
#define CGC_AD_PLL3SS_STOP(x)                    (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3SS_STOP_SHIFT)) & CGC_AD_PLL3SS_STOP_MASK)
/*! @} */

/*! @name PLL3LOCK - PLL3 LOCK Configuration Register */
/*! @{ */

#define CGC_AD_PLL3LOCK_LOCK_TIME_MASK           (0xFFFFU)
#define CGC_AD_PLL3LOCK_LOCK_TIME_SHIFT          (0U)
/*! LOCK_TIME - LOCK_TIME */
#define CGC_AD_PLL3LOCK_LOCK_TIME(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLL3LOCK_LOCK_TIME_SHIFT)) & CGC_AD_PLL3LOCK_LOCK_TIME_MASK)
/*! @} */

/*! @name ENETSTAMP - Clock Selection for Ethernet Time Stamp */
/*! @{ */

#define CGC_AD_ENETSTAMP_CLKOUT_SEL_MASK         (0x7000000U)
#define CGC_AD_ENETSTAMP_CLKOUT_SEL_SHIFT        (24U)
/*! CLKOUT_SEL - Selection of clock source used for Ethernet time stamp. */
#define CGC_AD_ENETSTAMP_CLKOUT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CGC_AD_ENETSTAMP_CLKOUT_SEL_SHIFT)) & CGC_AD_ENETSTAMP_CLKOUT_SEL_MASK)
/*! @} */

/*! @name PLLUSBCFG - PLLUSB Register Enable */
/*! @{ */

#define CGC_AD_PLLUSBCFG_SOURCE_MASK             (0x1U)
#define CGC_AD_PLLUSBCFG_SOURCE_SHIFT            (0U)
/*! SOURCE - Clock Source */
#define CGC_AD_PLLUSBCFG_SOURCE(x)               (((uint32_t)(((uint32_t)(x)) << CGC_AD_PLLUSBCFG_SOURCE_SHIFT)) & CGC_AD_PLLUSBCFG_SOURCE_MASK)
/*! @} */

/*! @name AUD_CLK1 - AUD_CLK1 source to SAI4-5 */
/*! @{ */

#define CGC_AD_AUD_CLK1_AUD_CLK1_MASK            (0x7U)
#define CGC_AD_AUD_CLK1_AUD_CLK1_SHIFT           (0U)
/*! AUD_CLK1 - AUD_CLK1 Clock Source Selection */
#define CGC_AD_AUD_CLK1_AUD_CLK1(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_AUD_CLK1_AUD_CLK1_SHIFT)) & CGC_AD_AUD_CLK1_AUD_CLK1_MASK)
/*! @} */

/*! @name SAI5_4_CLK - SAI5-4 Clock Source Selection */
/*! @{ */

#define CGC_AD_SAI5_4_CLK_SAI4CLK_MASK           (0x3U)
#define CGC_AD_SAI5_4_CLK_SAI4CLK_SHIFT          (0U)
/*! SAI4CLK - Clock Source for SAI4 */
#define CGC_AD_SAI5_4_CLK_SAI4CLK(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_SAI5_4_CLK_SAI4CLK_SHIFT)) & CGC_AD_SAI5_4_CLK_SAI4CLK_MASK)

#define CGC_AD_SAI5_4_CLK_SAI5CLK_MASK           (0x300U)
#define CGC_AD_SAI5_4_CLK_SAI5CLK_SHIFT          (8U)
/*! SAI5CLK - Clock Source for SAI5 */
#define CGC_AD_SAI5_4_CLK_SAI5CLK(x)             (((uint32_t)(((uint32_t)(x)) << CGC_AD_SAI5_4_CLK_SAI5CLK_SHIFT)) & CGC_AD_SAI5_4_CLK_SAI5CLK_MASK)
/*! @} */

/*! @name TPM6_7CLK - Multiplexer to select the audio clock connected to the TPM clock input */
/*! @{ */

#define CGC_AD_TPM6_7CLK_TPM6CLK_MASK            (0x3U)
#define CGC_AD_TPM6_7CLK_TPM6CLK_SHIFT           (0U)
/*! TPM6CLK - Clock Selection for TPM6 */
#define CGC_AD_TPM6_7CLK_TPM6CLK(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_TPM6_7CLK_TPM6CLK_SHIFT)) & CGC_AD_TPM6_7CLK_TPM6CLK_MASK)

#define CGC_AD_TPM6_7CLK_TPM7CLK_MASK            (0x300U)
#define CGC_AD_TPM6_7CLK_TPM7CLK_SHIFT           (8U)
/*! TPM7CLK - Clock Selection for TPM7 */
#define CGC_AD_TPM6_7CLK_TPM7CLK(x)              (((uint32_t)(((uint32_t)(x)) << CGC_AD_TPM6_7CLK_TPM7CLK_SHIFT)) & CGC_AD_TPM6_7CLK_TPM7CLK_MASK)
/*! @} */

/*! @name MQS1CLK - Multiplexer to select the audio clock connected to the MQS clock input */
/*! @{ */

#define CGC_AD_MQS1CLK_MQS1CLK_MASK              (0x3U)
#define CGC_AD_MQS1CLK_MQS1CLK_SHIFT             (0U)
/*! MQS1CLK - Clock Selection for MQS1 */
#define CGC_AD_MQS1CLK_MQS1CLK(x)                (((uint32_t)(((uint32_t)(x)) << CGC_AD_MQS1CLK_MQS1CLK_SHIFT)) & CGC_AD_MQS1CLK_MQS1CLK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CGC_AD_Register_Masks */


/*!
 * @}
 */ /* end of group CGC_AD_Peripheral_Access_Layer */


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


#endif  /* PERI_CGC_AD_H_ */

