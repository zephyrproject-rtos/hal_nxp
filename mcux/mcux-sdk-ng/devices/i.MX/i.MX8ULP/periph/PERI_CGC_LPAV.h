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
**         CMSIS Peripheral Access Layer for CGC_LPAV
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
 * @file PERI_CGC_LPAV.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CGC_LPAV
 *
 * CMSIS Peripheral Access Layer for CGC_LPAV
 */

#if !defined(PERI_CGC_LPAV_H_)
#define PERI_CGC_LPAV_H_                         /**< Symbol preventing repeated inclusion */

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
   -- CGC_LPAV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGC_LPAV_Peripheral_Access_Layer CGC_LPAV Peripheral Access Layer
 * @{
 */

/** CGC_LPAV - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[16];
  __IO uint32_t HIFICLK;                           /**< Clock Selection and Dividers for the HIFI Domain, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CLKOUTCFG;                         /**< Clockout selection for LPAV Domain, offset: 0x20 */
       uint8_t RESERVED_2[24];
  __IO uint32_t NICLPAVCLK;                        /**< Clock Selection and Dividers for the HIFI Domain, offset: 0x3C */
  __IO uint32_t DDRCLK;                            /**< Clock Selection and Dividers for the DDR Domain, offset: 0x40 */
       uint8_t RESERVED_3[76];
  __IO uint32_t CLKDIVRST;                         /**< Clk Dividers Reset, offset: 0x90 */
       uint8_t RESERVED_4[116];
  __IO uint32_t SOSCDIV;                           /**< Clock Dividers for the SOSC CLK, offset: 0x108 */
       uint8_t RESERVED_5[252];
  __IO uint32_t FRODIV;                            /**< Clock Dividers for the FRO, offset: 0x208 */
       uint8_t RESERVED_6[1012];
  __IO uint32_t PLL4CSR;                           /**< PLL Control Status Register, offset: 0x600 */
  __IO uint32_t PLL4DIV_VCO;                       /**< Clock Dividers for the fractional PLL4, offset: 0x604 */
  __IO uint32_t PLL4DIV_PFD_0;                     /**< Clock Dividers for the fractional PLL4, offset: 0x608 */
  __IO uint32_t PLL4DIV_PFD_1;                     /**< Clock Dividers for the fractional PLL4, offset: 0x60C */
  __IO uint32_t PLL4CFG;                           /**< PLL4 Configuration Register, offset: 0x610 */
  __IO uint32_t PLL4PFDCFG;                        /**< PLL4 Configuration Register, offset: 0x614 */
  __IO uint32_t PLL4DENOM;                         /**< PLL Denominator Register, offset: 0x618 */
  __IO uint32_t PLL4NUM;                           /**< PLL Numerator Register, offset: 0x61C */
  __IO uint32_t PLL4SS;                            /**< PLL Spread Spectrum Register, offset: 0x620 */
  __IO uint32_t PLL4LOCK;                          /**< PLL LOCK Configuration Register, offset: 0x624 */
       uint8_t RESERVED_7[728];
  __IO uint32_t AUD_CLK2;                          /**< AUD_CLK2 source to SAI7-6, offset: 0x900 */
  __IO uint32_t SAI7_6_CLK;                        /**< SAI7-6 Clock Source Selection, offset: 0x904 */
  __IO uint32_t TPM8CLK;                           /**< Multiplexer to select the audio clock connected to the TPM clock input, offset: 0x908 */
       uint8_t RESERVED_8[4];
  __IO uint32_t SPDIFCLK;                          /**< Multiplexer to select the audio clock connected to the SPDIF clock input, offset: 0x910 */
} CGC_LPAV_Type;

/* ----------------------------------------------------------------------------
   -- CGC_LPAV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGC_LPAV_Register_Masks CGC_LPAV Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define CGC_LPAV_VERID_FEATURE_MASK              (0xFFFFU)
#define CGC_LPAV_VERID_FEATURE_SHIFT             (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000010..Master only with standard feature set.
 *  0b0000000000000011..Master and slave with standard feature set.
 */
#define CGC_LPAV_VERID_FEATURE(x)                (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_VERID_FEATURE_SHIFT)) & CGC_LPAV_VERID_FEATURE_MASK)

#define CGC_LPAV_VERID_MINOR_MASK                (0xFF0000U)
#define CGC_LPAV_VERID_MINOR_SHIFT               (16U)
/*! MINOR - Minor Version Number */
#define CGC_LPAV_VERID_MINOR(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_VERID_MINOR_SHIFT)) & CGC_LPAV_VERID_MINOR_MASK)

#define CGC_LPAV_VERID_MAJOR_MASK                (0xFF000000U)
#define CGC_LPAV_VERID_MAJOR_SHIFT               (24U)
/*! MAJOR - Major Version Number */
#define CGC_LPAV_VERID_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_VERID_MAJOR_SHIFT)) & CGC_LPAV_VERID_MAJOR_MASK)
/*! @} */

/*! @name HIFICLK - Clock Selection and Dividers for the HIFI Domain */
/*! @{ */

#define CGC_LPAV_HIFICLK_NIC_HIFI_DIVPLAT_MASK   (0xFC000U)
#define CGC_LPAV_HIFICLK_NIC_HIFI_DIVPLAT_SHIFT  (14U)
/*! NIC_HIFI_DIVPLAT - Clock Division for Platform Clock */
#define CGC_LPAV_HIFICLK_NIC_HIFI_DIVPLAT(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_HIFICLK_NIC_HIFI_DIVPLAT_SHIFT)) & CGC_LPAV_HIFICLK_NIC_HIFI_DIVPLAT_MASK)

#define CGC_LPAV_HIFICLK_HIFI_DIVCORE_MASK       (0x7E00000U)
#define CGC_LPAV_HIFICLK_HIFI_DIVCORE_SHIFT      (21U)
/*! HIFI_DIVCORE - Clock Division for Core Clock */
#define CGC_LPAV_HIFICLK_HIFI_DIVCORE(x)         (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_HIFICLK_HIFI_DIVCORE_SHIFT)) & CGC_LPAV_HIFICLK_HIFI_DIVCORE_MASK)

#define CGC_LPAV_HIFICLK_SCSW_MASK               (0x8000000U)
#define CGC_LPAV_HIFICLK_SCSW_SHIFT              (27U)
/*! SCSW - Clock switched to selected clock source */
#define CGC_LPAV_HIFICLK_SCSW(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_HIFICLK_SCSW_SHIFT)) & CGC_LPAV_HIFICLK_SCSW_MASK)

#define CGC_LPAV_HIFICLK_SCS_MASK                (0x70000000U)
#define CGC_LPAV_HIFICLK_SCS_SHIFT               (28U)
/*! SCS - Clock Selection for HIFI Domain */
#define CGC_LPAV_HIFICLK_SCS(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_HIFICLK_SCS_SHIFT)) & CGC_LPAV_HIFICLK_SCS_MASK)

#define CGC_LPAV_HIFICLK_HIFILOCKED_MASK         (0x80000000U)
#define CGC_LPAV_HIFICLK_HIFILOCKED_SHIFT        (31U)
/*! HIFILOCKED - HIFICLK Register Locked */
#define CGC_LPAV_HIFICLK_HIFILOCKED(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_HIFICLK_HIFILOCKED_SHIFT)) & CGC_LPAV_HIFICLK_HIFILOCKED_MASK)
/*! @} */

/*! @name CLKOUTCFG - Clockout selection for LPAV Domain */
/*! @{ */

#define CGC_LPAV_CLKOUTCFG_CLKOUT_DIV_MASK       (0x7E0000U)
#define CGC_LPAV_CLKOUTCFG_CLKOUT_DIV_SHIFT      (17U)
/*! CLKOUT_DIV - Select the clock division for the CLKOUT pin */
#define CGC_LPAV_CLKOUTCFG_CLKOUT_DIV(x)         (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKOUTCFG_CLKOUT_DIV_SHIFT)) & CGC_LPAV_CLKOUTCFG_CLKOUT_DIV_MASK)

#define CGC_LPAV_CLKOUTCFG_CLKOUT_SEL_MASK       (0x7800000U)
#define CGC_LPAV_CLKOUTCFG_CLKOUT_SEL_SHIFT      (23U)
/*! CLKOUT_SEL - Select the clock source redirected to CLKOUT pin */
#define CGC_LPAV_CLKOUTCFG_CLKOUT_SEL(x)         (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKOUTCFG_CLKOUT_SEL_SHIFT)) & CGC_LPAV_CLKOUTCFG_CLKOUT_SEL_MASK)

#define CGC_LPAV_CLKOUTCFG_CLKOUT_EN_MASK        (0x10000000U)
#define CGC_LPAV_CLKOUTCFG_CLKOUT_EN_SHIFT       (28U)
/*! CLKOUT_EN - Clockout Enable */
#define CGC_LPAV_CLKOUTCFG_CLKOUT_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKOUTCFG_CLKOUT_EN_SHIFT)) & CGC_LPAV_CLKOUTCFG_CLKOUT_EN_MASK)
/*! @} */

/*! @name NICLPAVCLK - Clock Selection and Dividers for the HIFI Domain */
/*! @{ */

#define CGC_LPAV_NICLPAVCLK_LPAV_BUS_CLK_MASK    (0x780U)
#define CGC_LPAV_NICLPAVCLK_LPAV_BUS_CLK_SHIFT   (7U)
/*! LPAV_BUS_CLK - Clock Division for Bus Clk */
#define CGC_LPAV_NICLPAVCLK_LPAV_BUS_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_NICLPAVCLK_LPAV_BUS_CLK_SHIFT)) & CGC_LPAV_NICLPAVCLK_LPAV_BUS_CLK_MASK)

#define CGC_LPAV_NICLPAVCLK_LPAV_AHB_CLK_MASK    (0x3C000U)
#define CGC_LPAV_NICLPAVCLK_LPAV_AHB_CLK_SHIFT   (14U)
/*! LPAV_AHB_CLK - Clock Division for AHB Clock */
#define CGC_LPAV_NICLPAVCLK_LPAV_AHB_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_NICLPAVCLK_LPAV_AHB_CLK_SHIFT)) & CGC_LPAV_NICLPAVCLK_LPAV_AHB_CLK_MASK)

#define CGC_LPAV_NICLPAVCLK_LPAV_AXI_CLK_MASK    (0x1E00000U)
#define CGC_LPAV_NICLPAVCLK_LPAV_AXI_CLK_SHIFT   (21U)
/*! LPAV_AXI_CLK - Clock Division for AXI Clock */
#define CGC_LPAV_NICLPAVCLK_LPAV_AXI_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_NICLPAVCLK_LPAV_AXI_CLK_SHIFT)) & CGC_LPAV_NICLPAVCLK_LPAV_AXI_CLK_MASK)

#define CGC_LPAV_NICLPAVCLK_SCSW_MASK            (0x8000000U)
#define CGC_LPAV_NICLPAVCLK_SCSW_SHIFT           (27U)
/*! SCSW - Clock switched to selected clock source */
#define CGC_LPAV_NICLPAVCLK_SCSW(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_NICLPAVCLK_SCSW_SHIFT)) & CGC_LPAV_NICLPAVCLK_SCSW_MASK)

#define CGC_LPAV_NICLPAVCLK_SCS_MASK             (0x30000000U)
#define CGC_LPAV_NICLPAVCLK_SCS_SHIFT            (28U)
/*! SCS - Clock Selection for HIFI domain */
#define CGC_LPAV_NICLPAVCLK_SCS(x)               (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_NICLPAVCLK_SCS_SHIFT)) & CGC_LPAV_NICLPAVCLK_SCS_MASK)

#define CGC_LPAV_NICLPAVCLK_NICLOCKED_MASK       (0x80000000U)
#define CGC_LPAV_NICLPAVCLK_NICLOCKED_SHIFT      (31U)
/*! NICLOCKED - NIC CLK Register Locked */
#define CGC_LPAV_NICLPAVCLK_NICLOCKED(x)         (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_NICLPAVCLK_NICLOCKED_SHIFT)) & CGC_LPAV_NICLPAVCLK_NICLOCKED_MASK)
/*! @} */

/*! @name DDRCLK - Clock Selection and Dividers for the DDR Domain */
/*! @{ */

#define CGC_LPAV_DDRCLK_DDR_DIV_MASK             (0x7E00000U)
#define CGC_LPAV_DDRCLK_DDR_DIV_SHIFT            (21U)
/*! DDR_DIV - Clock Division for DDR Clock */
#define CGC_LPAV_DDRCLK_DDR_DIV(x)               (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_DDRCLK_DDR_DIV_SHIFT)) & CGC_LPAV_DDRCLK_DDR_DIV_MASK)

#define CGC_LPAV_DDRCLK_SCSW_MASK                (0x8000000U)
#define CGC_LPAV_DDRCLK_SCSW_SHIFT               (27U)
/*! SCSW - Clock switched to selected clock source */
#define CGC_LPAV_DDRCLK_SCSW(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_DDRCLK_SCSW_SHIFT)) & CGC_LPAV_DDRCLK_SCSW_MASK)

#define CGC_LPAV_DDRCLK_SCS_MASK                 (0x70000000U)
#define CGC_LPAV_DDRCLK_SCS_SHIFT                (28U)
/*! SCS - Clock Selection for DDR Clock */
#define CGC_LPAV_DDRCLK_SCS(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_DDRCLK_SCS_SHIFT)) & CGC_LPAV_DDRCLK_SCS_MASK)

#define CGC_LPAV_DDRCLK_DDRLOCKED_MASK           (0x80000000U)
#define CGC_LPAV_DDRCLK_DDRLOCKED_SHIFT          (31U)
/*! DDRLOCKED - DDR CLK Register Locked */
#define CGC_LPAV_DDRCLK_DDRLOCKED(x)             (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_DDRCLK_DDRLOCKED_SHIFT)) & CGC_LPAV_DDRCLK_DDRLOCKED_MASK)
/*! @} */

/*! @name CLKDIVRST - Clk Dividers Reset */
/*! @{ */

#define CGC_LPAV_CLKDIVRST_NICLPAV_OUT_OF_PHASE_MASK (0x1U)
#define CGC_LPAV_CLKDIVRST_NICLPAV_OUT_OF_PHASE_SHIFT (0U)
/*! NICLPAV_OUT_OF_PHASE - NIC clocks dividers reset */
#define CGC_LPAV_CLKDIVRST_NICLPAV_OUT_OF_PHASE(x) (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_NICLPAV_OUT_OF_PHASE_SHIFT)) & CGC_LPAV_CLKDIVRST_NICLPAV_OUT_OF_PHASE_MASK)

#define CGC_LPAV_CLKDIVRST_NICLPAV_RST_DIVIDERS_EN_MASK (0x2U)
#define CGC_LPAV_CLKDIVRST_NICLPAV_RST_DIVIDERS_EN_SHIFT (1U)
/*! NICLPAV_RST_DIVIDERS_EN - NIC clocks dividers out of phase interrupt */
#define CGC_LPAV_CLKDIVRST_NICLPAV_RST_DIVIDERS_EN(x) (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_NICLPAV_RST_DIVIDERS_EN_SHIFT)) & CGC_LPAV_CLKDIVRST_NICLPAV_RST_DIVIDERS_EN_MASK)

#define CGC_LPAV_CLKDIVRST_NICLPAV_INTERRUPT_EN_MASK (0x4U)
#define CGC_LPAV_CLKDIVRST_NICLPAV_INTERRUPT_EN_SHIFT (2U)
/*! NICLPAV_INTERRUPT_EN - Selection between interrupt generation or clock dividers reset when nic clocks are out of phase */
#define CGC_LPAV_CLKDIVRST_NICLPAV_INTERRUPT_EN(x) (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_NICLPAV_INTERRUPT_EN_SHIFT)) & CGC_LPAV_CLKDIVRST_NICLPAV_INTERRUPT_EN_MASK)

#define CGC_LPAV_CLKDIVRST_NICLPAV_RESET_EN_MASK (0x8U)
#define CGC_LPAV_CLKDIVRST_NICLPAV_RESET_EN_SHIFT (3U)
#define CGC_LPAV_CLKDIVRST_NICLPAV_RESET_EN(x)   (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_NICLPAV_RESET_EN_SHIFT)) & CGC_LPAV_CLKDIVRST_NICLPAV_RESET_EN_MASK)

#define CGC_LPAV_CLKDIVRST_HIFI_OUT_OF_PHASE_MASK (0x10000U)
#define CGC_LPAV_CLKDIVRST_HIFI_OUT_OF_PHASE_SHIFT (16U)
/*! HIFI_OUT_OF_PHASE - HIFI4 clocks dividers reset */
#define CGC_LPAV_CLKDIVRST_HIFI_OUT_OF_PHASE(x)  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_HIFI_OUT_OF_PHASE_SHIFT)) & CGC_LPAV_CLKDIVRST_HIFI_OUT_OF_PHASE_MASK)

#define CGC_LPAV_CLKDIVRST_HIFI_RST_DIVIDERS_EN_MASK (0x20000U)
#define CGC_LPAV_CLKDIVRST_HIFI_RST_DIVIDERS_EN_SHIFT (17U)
/*! HIFI_RST_DIVIDERS_EN - HIFI4 clocks dividers out of phase interrupt */
#define CGC_LPAV_CLKDIVRST_HIFI_RST_DIVIDERS_EN(x) (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_HIFI_RST_DIVIDERS_EN_SHIFT)) & CGC_LPAV_CLKDIVRST_HIFI_RST_DIVIDERS_EN_MASK)

#define CGC_LPAV_CLKDIVRST_HIFI_INTERRUPT_EN_MASK (0x40000U)
#define CGC_LPAV_CLKDIVRST_HIFI_INTERRUPT_EN_SHIFT (18U)
/*! HIFI_INTERRUPT_EN - Selection between interrupt generation or clock dividers reset when hifi4 clocks are out of phase */
#define CGC_LPAV_CLKDIVRST_HIFI_INTERRUPT_EN(x)  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_HIFI_INTERRUPT_EN_SHIFT)) & CGC_LPAV_CLKDIVRST_HIFI_INTERRUPT_EN_MASK)

#define CGC_LPAV_CLKDIVRST_HIFI_RESET_EN_MASK    (0x80000U)
#define CGC_LPAV_CLKDIVRST_HIFI_RESET_EN_SHIFT   (19U)
#define CGC_LPAV_CLKDIVRST_HIFI_RESET_EN(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_CLKDIVRST_HIFI_RESET_EN_SHIFT)) & CGC_LPAV_CLKDIVRST_HIFI_RESET_EN_MASK)
/*! @} */

/*! @name SOSCDIV - Clock Dividers for the SOSC CLK */
/*! @{ */

#define CGC_LPAV_SOSCDIV_DIV1_MASK               (0x3FU)
#define CGC_LPAV_SOSCDIV_DIV1_SHIFT              (0U)
/*! DIV1 - Clock Division for Slow Clock */
#define CGC_LPAV_SOSCDIV_DIV1(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV1_SHIFT)) & CGC_LPAV_SOSCDIV_DIV1_MASK)

#define CGC_LPAV_SOSCDIV_DIV1LOCKED_MASK         (0x40U)
#define CGC_LPAV_SOSCDIV_DIV1LOCKED_SHIFT        (6U)
/*! DIV1LOCKED - Write to DIV1 Locked */
#define CGC_LPAV_SOSCDIV_DIV1LOCKED(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV1LOCKED_SHIFT)) & CGC_LPAV_SOSCDIV_DIV1LOCKED_MASK)

#define CGC_LPAV_SOSCDIV_DIV1HALT_MASK           (0x80U)
#define CGC_LPAV_SOSCDIV_DIV1HALT_SHIFT          (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_LPAV_SOSCDIV_DIV1HALT(x)             (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV1HALT_SHIFT)) & CGC_LPAV_SOSCDIV_DIV1HALT_MASK)

#define CGC_LPAV_SOSCDIV_DIV2_MASK               (0x3F00U)
#define CGC_LPAV_SOSCDIV_DIV2_SHIFT              (8U)
/*! DIV2 - Clock Division for Bus Clock */
#define CGC_LPAV_SOSCDIV_DIV2(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV2_SHIFT)) & CGC_LPAV_SOSCDIV_DIV2_MASK)

#define CGC_LPAV_SOSCDIV_DIV2LOCKED_MASK         (0x4000U)
#define CGC_LPAV_SOSCDIV_DIV2LOCKED_SHIFT        (14U)
/*! DIV2LOCKED - Write to DIV2 Locked */
#define CGC_LPAV_SOSCDIV_DIV2LOCKED(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV2LOCKED_SHIFT)) & CGC_LPAV_SOSCDIV_DIV2LOCKED_MASK)

#define CGC_LPAV_SOSCDIV_DIV2HALT_MASK           (0x8000U)
#define CGC_LPAV_SOSCDIV_DIV2HALT_SHIFT          (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_LPAV_SOSCDIV_DIV2HALT(x)             (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV2HALT_SHIFT)) & CGC_LPAV_SOSCDIV_DIV2HALT_MASK)

#define CGC_LPAV_SOSCDIV_DIV3_MASK               (0x3F0000U)
#define CGC_LPAV_SOSCDIV_DIV3_SHIFT              (16U)
/*! DIV3 - Clock Division for Platform Clock */
#define CGC_LPAV_SOSCDIV_DIV3(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV3_SHIFT)) & CGC_LPAV_SOSCDIV_DIV3_MASK)

#define CGC_LPAV_SOSCDIV_DIV3LOCKED_MASK         (0x400000U)
#define CGC_LPAV_SOSCDIV_DIV3LOCKED_SHIFT        (22U)
/*! DIV3LOCKED - Write to DIV3 Locked */
#define CGC_LPAV_SOSCDIV_DIV3LOCKED(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV3LOCKED_SHIFT)) & CGC_LPAV_SOSCDIV_DIV3LOCKED_MASK)

#define CGC_LPAV_SOSCDIV_DIV3HALT_MASK           (0x800000U)
#define CGC_LPAV_SOSCDIV_DIV3HALT_SHIFT          (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_LPAV_SOSCDIV_DIV3HALT(x)             (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SOSCDIV_DIV3HALT_SHIFT)) & CGC_LPAV_SOSCDIV_DIV3HALT_MASK)
/*! @} */

/*! @name FRODIV - Clock Dividers for the FRO */
/*! @{ */

#define CGC_LPAV_FRODIV_DIV1_MASK                (0x3FU)
#define CGC_LPAV_FRODIV_DIV1_SHIFT               (0U)
/*! DIV1 - Clock Division for Slow Clock */
#define CGC_LPAV_FRODIV_DIV1(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV1_SHIFT)) & CGC_LPAV_FRODIV_DIV1_MASK)

#define CGC_LPAV_FRODIV_DIV1LOCKED_MASK          (0x40U)
#define CGC_LPAV_FRODIV_DIV1LOCKED_SHIFT         (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_LPAV_FRODIV_DIV1LOCKED(x)            (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV1LOCKED_SHIFT)) & CGC_LPAV_FRODIV_DIV1LOCKED_MASK)

#define CGC_LPAV_FRODIV_DIV1HALT_MASK            (0x80U)
#define CGC_LPAV_FRODIV_DIV1HALT_SHIFT           (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_LPAV_FRODIV_DIV1HALT(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV1HALT_SHIFT)) & CGC_LPAV_FRODIV_DIV1HALT_MASK)

#define CGC_LPAV_FRODIV_DIV2_MASK                (0x3F00U)
#define CGC_LPAV_FRODIV_DIV2_SHIFT               (8U)
/*! DIV2 - Clock Division for Bus Clock */
#define CGC_LPAV_FRODIV_DIV2(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV2_SHIFT)) & CGC_LPAV_FRODIV_DIV2_MASK)

#define CGC_LPAV_FRODIV_DIV2LOCKED_MASK          (0x4000U)
#define CGC_LPAV_FRODIV_DIV2LOCKED_SHIFT         (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_LPAV_FRODIV_DIV2LOCKED(x)            (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV2LOCKED_SHIFT)) & CGC_LPAV_FRODIV_DIV2LOCKED_MASK)

#define CGC_LPAV_FRODIV_DIV2HALT_MASK            (0x8000U)
#define CGC_LPAV_FRODIV_DIV2HALT_SHIFT           (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_LPAV_FRODIV_DIV2HALT(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV2HALT_SHIFT)) & CGC_LPAV_FRODIV_DIV2HALT_MASK)

#define CGC_LPAV_FRODIV_DIV3_MASK                (0x3F0000U)
#define CGC_LPAV_FRODIV_DIV3_SHIFT               (16U)
/*! DIV3 - Clock Division for Platform Clock */
#define CGC_LPAV_FRODIV_DIV3(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV3_SHIFT)) & CGC_LPAV_FRODIV_DIV3_MASK)

#define CGC_LPAV_FRODIV_DIV3LOCKED_MASK          (0x400000U)
#define CGC_LPAV_FRODIV_DIV3LOCKED_SHIFT         (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked */
#define CGC_LPAV_FRODIV_DIV3LOCKED(x)            (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV3LOCKED_SHIFT)) & CGC_LPAV_FRODIV_DIV3LOCKED_MASK)

#define CGC_LPAV_FRODIV_DIV3HALT_MASK            (0x800000U)
#define CGC_LPAV_FRODIV_DIV3HALT_SHIFT           (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_LPAV_FRODIV_DIV3HALT(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_FRODIV_DIV3HALT_SHIFT)) & CGC_LPAV_FRODIV_DIV3HALT_MASK)
/*! @} */

/*! @name PLL4CSR - PLL Control Status Register */
/*! @{ */

#define CGC_LPAV_PLL4CSR_PLLEN_MASK              (0x1U)
#define CGC_LPAV_PLL4CSR_PLLEN_SHIFT             (0U)
/*! PLLEN - PLL Enable */
#define CGC_LPAV_PLL4CSR_PLLEN(x)                (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CSR_PLLEN_SHIFT)) & CGC_LPAV_PLL4CSR_PLLEN_MASK)

#define CGC_LPAV_PLL4CSR_PLLDSEN_MASK            (0x2U)
#define CGC_LPAV_PLL4CSR_PLLDSEN_SHIFT           (1U)
/*! PLLDSEN - PLL4 Enable in Deep Sleep */
#define CGC_LPAV_PLL4CSR_PLLDSEN(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CSR_PLLDSEN_SHIFT)) & CGC_LPAV_PLL4CSR_PLLDSEN_MASK)

#define CGC_LPAV_PLL4CSR_LK_MASK                 (0x800000U)
#define CGC_LPAV_PLL4CSR_LK_SHIFT                (23U)
/*! LK - Lock Register */
#define CGC_LPAV_PLL4CSR_LK(x)                   (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CSR_LK_SHIFT)) & CGC_LPAV_PLL4CSR_LK_MASK)

#define CGC_LPAV_PLL4CSR_PLLVLD_MASK             (0x1000000U)
#define CGC_LPAV_PLL4CSR_PLLVLD_SHIFT            (24U)
/*! PLLVLD - PLL Valid */
#define CGC_LPAV_PLL4CSR_PLLVLD(x)               (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CSR_PLLVLD_SHIFT)) & CGC_LPAV_PLL4CSR_PLLVLD_MASK)

#define CGC_LPAV_PLL4CSR_PLLSEL_MASK             (0x2000000U)
#define CGC_LPAV_PLL4CSR_PLLSEL_SHIFT            (25U)
/*! PLLSEL - PLL Selected */
#define CGC_LPAV_PLL4CSR_PLLSEL(x)               (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CSR_PLLSEL_SHIFT)) & CGC_LPAV_PLL4CSR_PLLSEL_MASK)
/*! @} */

/*! @name PLL4DIV_VCO - Clock Dividers for the fractional PLL4 */
/*! @{ */

#define CGC_LPAV_PLL4DIV_VCO_DIV1_MASK           (0x3FU)
#define CGC_LPAV_PLL4DIV_VCO_DIV1_SHIFT          (0U)
/*! DIV1 - Clock Division for PLL4 VCO Clock */
#define CGC_LPAV_PLL4DIV_VCO_DIV1(x)             (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_VCO_DIV1_SHIFT)) & CGC_LPAV_PLL4DIV_VCO_DIV1_MASK)

#define CGC_LPAV_PLL4DIV_VCO_DIV1LOCKED_MASK     (0x40U)
#define CGC_LPAV_PLL4DIV_VCO_DIV1LOCKED_SHIFT    (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_LPAV_PLL4DIV_VCO_DIV1LOCKED(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_VCO_DIV1LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_VCO_DIV1LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_VCO_DIV1HALT_MASK       (0x80U)
#define CGC_LPAV_PLL4DIV_VCO_DIV1HALT_SHIFT      (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_LPAV_PLL4DIV_VCO_DIV1HALT(x)         (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_VCO_DIV1HALT_SHIFT)) & CGC_LPAV_PLL4DIV_VCO_DIV1HALT_MASK)
/*! @} */

/*! @name PLL4DIV_PFD_0 - Clock Dividers for the fractional PLL4 */
/*! @{ */

#define CGC_LPAV_PLL4DIV_PFD_0_DIV1_MASK         (0x3FU)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV1_SHIFT        (0U)
/*! DIV1 - Clock Division for PLL4 PFD0 Clock */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV1(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV1_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV1_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV1LOCKED_MASK   (0x40U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV1LOCKED_SHIFT  (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV1LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV1LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV1LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV1HALT_MASK     (0x80U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV1HALT_SHIFT    (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV1HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV1HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV1HALT_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV2_MASK         (0x3F00U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV2_SHIFT        (8U)
/*! DIV2 - Clock Division for PLL4 PFD0 Clock */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV2(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV2_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV2_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV2LOCKED_MASK   (0x4000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV2LOCKED_SHIFT  (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV2LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV2LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV2LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV2HALT_MASK     (0x8000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV2HALT_SHIFT    (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV2HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV2HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV2HALT_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV3_MASK         (0x3F0000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV3_SHIFT        (16U)
/*! DIV3 - Clock Division for PLL4 PFD1 Clock */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV3(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV3_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV3_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV3LOCKED_MASK   (0x400000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV3LOCKED_SHIFT  (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV3LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV3LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV3LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV3HALT_MASK     (0x800000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV3HALT_SHIFT    (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV3HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV3HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV3HALT_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV4_MASK         (0x3F000000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV4_SHIFT        (24U)
/*! DIV4 - Clock Division for PLL4 PFD1 Clock */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV4(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV4_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV4_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV4LOCKED_MASK   (0x40000000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV4LOCKED_SHIFT  (30U)
/*! DIV4LOCKED - The value of clock division was changed and access to DIV4 is locked */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV4LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV4LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV4LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_0_DIV4HALT_MASK     (0x80000000U)
#define CGC_LPAV_PLL4DIV_PFD_0_DIV4HALT_SHIFT    (31U)
/*! DIV4HALT - Divider 4 Halted */
#define CGC_LPAV_PLL4DIV_PFD_0_DIV4HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_0_DIV4HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_0_DIV4HALT_MASK)
/*! @} */

/*! @name PLL4DIV_PFD_1 - Clock Dividers for the fractional PLL4 */
/*! @{ */

#define CGC_LPAV_PLL4DIV_PFD_1_DIV1_MASK         (0x3FU)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV1_SHIFT        (0U)
/*! DIV1 - Clock Division for PLL4 PFD2 Clock */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV1(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV1_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV1_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV1LOCKED_MASK   (0x40U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV1LOCKED_SHIFT  (6U)
/*! DIV1LOCKED - The value of clock division was changed and access to DIV1 is locked */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV1LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV1LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV1LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV1HALT_MASK     (0x80U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV1HALT_SHIFT    (7U)
/*! DIV1HALT - Divider 1 Halted */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV1HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV1HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV1HALT_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV2_MASK         (0x3F00U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV2_SHIFT        (8U)
/*! DIV2 - Clock Division for PLL4 PFD2 Clock */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV2(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV2_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV2_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV2LOCKED_MASK   (0x4000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV2LOCKED_SHIFT  (14U)
/*! DIV2LOCKED - The value of clock division was changed and access to DIV2 is locked */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV2LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV2LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV2LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV2HALT_MASK     (0x8000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV2HALT_SHIFT    (15U)
/*! DIV2HALT - Divider 2 Halted */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV2HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV2HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV2HALT_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV3_MASK         (0x3F0000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV3_SHIFT        (16U)
/*! DIV3 - Clock Division for PLL4 PFD3 Clock */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV3(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV3_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV3_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV3LOCKED_MASK   (0x400000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV3LOCKED_SHIFT  (22U)
/*! DIV3LOCKED - The value of clock division was changed and access to DIV3 is locked */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV3LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV3LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV3LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV3HALT_MASK     (0x800000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV3HALT_SHIFT    (23U)
/*! DIV3HALT - Divider 3 Halted */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV3HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV3HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV3HALT_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV4_MASK         (0x3F000000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV4_SHIFT        (24U)
/*! DIV4 - Clock Division for PLL4 PFD3 Clock */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV4(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV4_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV4_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV4LOCKED_MASK   (0x40000000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV4LOCKED_SHIFT  (30U)
/*! DIV4LOCKED - The value of clock division was changed and access to DIV4 is locked */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV4LOCKED(x)     (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV4LOCKED_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV4LOCKED_MASK)

#define CGC_LPAV_PLL4DIV_PFD_1_DIV4HALT_MASK     (0x80000000U)
#define CGC_LPAV_PLL4DIV_PFD_1_DIV4HALT_SHIFT    (31U)
/*! DIV4HALT - Divider 4 Halted */
#define CGC_LPAV_PLL4DIV_PFD_1_DIV4HALT(x)       (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DIV_PFD_1_DIV4HALT_SHIFT)) & CGC_LPAV_PLL4DIV_PFD_1_DIV4HALT_MASK)
/*! @} */

/*! @name PLL4CFG - PLL4 Configuration Register */
/*! @{ */

#define CGC_LPAV_PLL4CFG_SOURCE_MASK             (0x1U)
#define CGC_LPAV_PLL4CFG_SOURCE_SHIFT            (0U)
/*! SOURCE - Clock Source */
#define CGC_LPAV_PLL4CFG_SOURCE(x)               (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_SOURCE_SHIFT)) & CGC_LPAV_PLL4CFG_SOURCE_MASK)

#define CGC_LPAV_PLL4CFG_HALF_LR_R_MASK          (0x8U)
#define CGC_LPAV_PLL4CFG_HALF_LR_R_SHIFT         (3U)
/*! HALF_LR_R - HALF_LR_R */
#define CGC_LPAV_PLL4CFG_HALF_LR_R(x)            (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_HALF_LR_R_SHIFT)) & CGC_LPAV_PLL4CFG_HALF_LR_R_MASK)

#define CGC_LPAV_PLL4CFG_HALF_CP_CURRENT_MASK    (0x10U)
#define CGC_LPAV_PLL4CFG_HALF_CP_CURRENT_SHIFT   (4U)
/*! HALF_CP_CURRENT - HALF_CP_CURRENT */
#define CGC_LPAV_PLL4CFG_HALF_CP_CURRENT(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_HALF_CP_CURRENT_SHIFT)) & CGC_LPAV_PLL4CFG_HALF_CP_CURRENT_MASK)

#define CGC_LPAV_PLL4CFG_DOUBLE_LF_R_MASK        (0x20U)
#define CGC_LPAV_PLL4CFG_DOUBLE_LF_R_SHIFT       (5U)
/*! DOUBLE_LF_R - DOUBLE_LF_R */
#define CGC_LPAV_PLL4CFG_DOUBLE_LF_R(x)          (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_DOUBLE_LF_R_SHIFT)) & CGC_LPAV_PLL4CFG_DOUBLE_LF_R_MASK)

#define CGC_LPAV_PLL4CFG_DOUBLE_CP_CURRENT_MASK  (0x40U)
#define CGC_LPAV_PLL4CFG_DOUBLE_CP_CURRENT_SHIFT (6U)
/*! DOUBLE_CP_CURRENT - DOUBLE_CP_CURRENT */
#define CGC_LPAV_PLL4CFG_DOUBLE_CP_CURRENT(x)    (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_DOUBLE_CP_CURRENT_SHIFT)) & CGC_LPAV_PLL4CFG_DOUBLE_CP_CURRENT_MASK)

#define CGC_LPAV_PLL4CFG_DITHER_EN_MASK          (0x800U)
#define CGC_LPAV_PLL4CFG_DITHER_EN_SHIFT         (11U)
/*! DITHER_EN - DITHER_EN */
#define CGC_LPAV_PLL4CFG_DITHER_EN(x)            (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_DITHER_EN_SHIFT)) & CGC_LPAV_PLL4CFG_DITHER_EN_MASK)

#define CGC_LPAV_PLL4CFG_PFD_OFFSET_EN_MASK      (0x1000U)
#define CGC_LPAV_PLL4CFG_PFD_OFFSET_EN_SHIFT     (12U)
/*! PFD_OFFSET_EN - PFD_OFFSET_EN */
#define CGC_LPAV_PLL4CFG_PFD_OFFSET_EN(x)        (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_PFD_OFFSET_EN_SHIFT)) & CGC_LPAV_PLL4CFG_PFD_OFFSET_EN_MASK)

#define CGC_LPAV_PLL4CFG_HOLDRING_OFF_MASK       (0x2000U)
#define CGC_LPAV_PLL4CFG_HOLDRING_OFF_SHIFT      (13U)
/*! HOLDRING_OFF - HOLDRING_OFF */
#define CGC_LPAV_PLL4CFG_HOLDRING_OFF(x)         (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_HOLDRING_OFF_SHIFT)) & CGC_LPAV_PLL4CFG_HOLDRING_OFF_MASK)

#define CGC_LPAV_PLL4CFG_MULT_MASK               (0x7F0000U)
#define CGC_LPAV_PLL4CFG_MULT_SHIFT              (16U)
/*! MULT - System PLL Multiplier */
#define CGC_LPAV_PLL4CFG_MULT(x)                 (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4CFG_MULT_SHIFT)) & CGC_LPAV_PLL4CFG_MULT_MASK)
/*! @} */

/*! @name PLL4PFDCFG - PLL4 Configuration Register */
/*! @{ */

#define CGC_LPAV_PLL4PFDCFG_PFD0_MASK            (0x3FU)
#define CGC_LPAV_PLL4PFDCFG_PFD0_SHIFT           (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CGC_LPAV_PLL4PFDCFG_PFD0(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD0_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD0_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD0_VALID_MASK      (0x40U)
#define CGC_LPAV_PLL4PFDCFG_PFD0_VALID_SHIFT     (6U)
/*! PFD0_VALID - PFD0_VALID */
#define CGC_LPAV_PLL4PFDCFG_PFD0_VALID(x)        (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD0_VALID_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD0_VALID_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD0_CLKGATE_MASK    (0x80U)
#define CGC_LPAV_PLL4PFDCFG_PFD0_CLKGATE_SHIFT   (7U)
/*! PFD0_CLKGATE - Clock gate of PFD0 */
#define CGC_LPAV_PLL4PFDCFG_PFD0_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD0_CLKGATE_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD0_CLKGATE_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD1_MASK            (0x3F00U)
#define CGC_LPAV_PLL4PFDCFG_PFD1_SHIFT           (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CGC_LPAV_PLL4PFDCFG_PFD1(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD1_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD1_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD1_VALID_MASK      (0x4000U)
#define CGC_LPAV_PLL4PFDCFG_PFD1_VALID_SHIFT     (14U)
/*! PFD1_VALID - PFD1_VALID */
#define CGC_LPAV_PLL4PFDCFG_PFD1_VALID(x)        (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD1_VALID_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD1_VALID_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD1_CLKGATE_MASK    (0x8000U)
#define CGC_LPAV_PLL4PFDCFG_PFD1_CLKGATE_SHIFT   (15U)
/*! PFD1_CLKGATE - Clock gate of PFD1 */
#define CGC_LPAV_PLL4PFDCFG_PFD1_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD1_CLKGATE_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD1_CLKGATE_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD2_MASK            (0x3F0000U)
#define CGC_LPAV_PLL4PFDCFG_PFD2_SHIFT           (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CGC_LPAV_PLL4PFDCFG_PFD2(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD2_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD2_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD2_VALID_MASK      (0x400000U)
#define CGC_LPAV_PLL4PFDCFG_PFD2_VALID_SHIFT     (22U)
/*! PFD2_VALID - PFD2_VALID */
#define CGC_LPAV_PLL4PFDCFG_PFD2_VALID(x)        (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD2_VALID_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD2_VALID_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD2_CLKGATE_MASK    (0x800000U)
#define CGC_LPAV_PLL4PFDCFG_PFD2_CLKGATE_SHIFT   (23U)
/*! PFD2_CLKGATE - Clock gate of PFD2 */
#define CGC_LPAV_PLL4PFDCFG_PFD2_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD2_CLKGATE_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD2_CLKGATE_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD3_MASK            (0x3F000000U)
#define CGC_LPAV_PLL4PFDCFG_PFD3_SHIFT           (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CGC_LPAV_PLL4PFDCFG_PFD3(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD3_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD3_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD3_VALID_MASK      (0x40000000U)
#define CGC_LPAV_PLL4PFDCFG_PFD3_VALID_SHIFT     (30U)
/*! PFD3_VALID - PFD3_VALID */
#define CGC_LPAV_PLL4PFDCFG_PFD3_VALID(x)        (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD3_VALID_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD3_VALID_MASK)

#define CGC_LPAV_PLL4PFDCFG_PFD3_CLKGATE_MASK    (0x80000000U)
#define CGC_LPAV_PLL4PFDCFG_PFD3_CLKGATE_SHIFT   (31U)
/*! PFD3_CLKGATE - Clock gate of PFD3 */
#define CGC_LPAV_PLL4PFDCFG_PFD3_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4PFDCFG_PFD3_CLKGATE_SHIFT)) & CGC_LPAV_PLL4PFDCFG_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PLL4DENOM - PLL Denominator Register */
/*! @{ */

#define CGC_LPAV_PLL4DENOM_DENOM_MASK            (0x3FFFFFFFU)
#define CGC_LPAV_PLL4DENOM_DENOM_SHIFT           (0U)
/*! DENOM - PLL Denominator Register */
#define CGC_LPAV_PLL4DENOM_DENOM(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4DENOM_DENOM_SHIFT)) & CGC_LPAV_PLL4DENOM_DENOM_MASK)
/*! @} */

/*! @name PLL4NUM - PLL Numerator Register */
/*! @{ */

#define CGC_LPAV_PLL4NUM_NUM_MASK                (0x3FFFFFFFU)
#define CGC_LPAV_PLL4NUM_NUM_SHIFT               (0U)
/*! NUM - PLL Numerator Register */
#define CGC_LPAV_PLL4NUM_NUM(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4NUM_NUM_SHIFT)) & CGC_LPAV_PLL4NUM_NUM_MASK)
/*! @} */

/*! @name PLL4SS - PLL Spread Spectrum Register */
/*! @{ */

#define CGC_LPAV_PLL4SS_STEP_MASK                (0x7FFFU)
#define CGC_LPAV_PLL4SS_STEP_SHIFT               (0U)
/*! STEP - STEP */
#define CGC_LPAV_PLL4SS_STEP(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4SS_STEP_SHIFT)) & CGC_LPAV_PLL4SS_STEP_MASK)

#define CGC_LPAV_PLL4SS_ENABLE_MASK              (0x8000U)
#define CGC_LPAV_PLL4SS_ENABLE_SHIFT             (15U)
/*! ENABLE - ENABLE */
#define CGC_LPAV_PLL4SS_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4SS_ENABLE_SHIFT)) & CGC_LPAV_PLL4SS_ENABLE_MASK)

#define CGC_LPAV_PLL4SS_STOP_MASK                (0xFFFF0000U)
#define CGC_LPAV_PLL4SS_STOP_SHIFT               (16U)
/*! STOP - STOP */
#define CGC_LPAV_PLL4SS_STOP(x)                  (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4SS_STOP_SHIFT)) & CGC_LPAV_PLL4SS_STOP_MASK)
/*! @} */

/*! @name PLL4LOCK - PLL LOCK Configuration Register */
/*! @{ */

#define CGC_LPAV_PLL4LOCK_LOCK_TIME_MASK         (0xFFFFU)
#define CGC_LPAV_PLL4LOCK_LOCK_TIME_SHIFT        (0U)
/*! LOCK_TIME - LOCK_TIME */
#define CGC_LPAV_PLL4LOCK_LOCK_TIME(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_PLL4LOCK_LOCK_TIME_SHIFT)) & CGC_LPAV_PLL4LOCK_LOCK_TIME_MASK)
/*! @} */

/*! @name AUD_CLK2 - AUD_CLK2 source to SAI7-6 */
/*! @{ */

#define CGC_LPAV_AUD_CLK2_AUD_CLK2_MASK          (0x7U)
#define CGC_LPAV_AUD_CLK2_AUD_CLK2_SHIFT         (0U)
/*! AUD_CLK2 - AUD_CLK2 Clock Source Selection */
#define CGC_LPAV_AUD_CLK2_AUD_CLK2(x)            (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_AUD_CLK2_AUD_CLK2_SHIFT)) & CGC_LPAV_AUD_CLK2_AUD_CLK2_MASK)
/*! @} */

/*! @name SAI7_6_CLK - SAI7-6 Clock Source Selection */
/*! @{ */

#define CGC_LPAV_SAI7_6_CLK_SAI6CLK_MASK         (0x7U)
#define CGC_LPAV_SAI7_6_CLK_SAI6CLK_SHIFT        (0U)
/*! SAI6CLK - Clock Source for SAI6 */
#define CGC_LPAV_SAI7_6_CLK_SAI6CLK(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SAI7_6_CLK_SAI6CLK_SHIFT)) & CGC_LPAV_SAI7_6_CLK_SAI6CLK_MASK)

#define CGC_LPAV_SAI7_6_CLK_SAI7CLK_MASK         (0x700U)
#define CGC_LPAV_SAI7_6_CLK_SAI7CLK_SHIFT        (8U)
/*! SAI7CLK - Clock Source for SAI7 */
#define CGC_LPAV_SAI7_6_CLK_SAI7CLK(x)           (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SAI7_6_CLK_SAI7CLK_SHIFT)) & CGC_LPAV_SAI7_6_CLK_SAI7CLK_MASK)
/*! @} */

/*! @name TPM8CLK - Multiplexer to select the audio clock connected to the TPM clock input */
/*! @{ */

#define CGC_LPAV_TPM8CLK_TPM8CLK_MASK            (0x7U)
#define CGC_LPAV_TPM8CLK_TPM8CLK_SHIFT           (0U)
/*! TPM8CLK - Clock Selection for TPM8 */
#define CGC_LPAV_TPM8CLK_TPM8CLK(x)              (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_TPM8CLK_TPM8CLK_SHIFT)) & CGC_LPAV_TPM8CLK_TPM8CLK_MASK)
/*! @} */

/*! @name SPDIFCLK - Multiplexer to select the audio clock connected to the SPDIF clock input */
/*! @{ */

#define CGC_LPAV_SPDIFCLK_SPDIFCLK_MASK          (0x7U)
#define CGC_LPAV_SPDIFCLK_SPDIFCLK_SHIFT         (0U)
/*! SPDIFCLK - Clock Selection for SPDIF */
#define CGC_LPAV_SPDIFCLK_SPDIFCLK(x)            (((uint32_t)(((uint32_t)(x)) << CGC_LPAV_SPDIFCLK_SPDIFCLK_SHIFT)) & CGC_LPAV_SPDIFCLK_SPDIFCLK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CGC_LPAV_Register_Masks */


/*!
 * @}
 */ /* end of group CGC_LPAV_Peripheral_Access_Layer */


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


#endif  /* PERI_CGC_LPAV_H_ */

