/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AUDIOMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AUDIOMIX.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AUDIOMIX
 *
 * CMSIS Peripheral Access Layer for AUDIOMIX
 */

#if !defined(PERI_AUDIOMIX_H_)
#define PERI_AUDIOMIX_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- AUDIOMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIOMIX_Peripheral_Access_Layer AUDIOMIX Peripheral Access Layer
 * @{
 */

/** AUDIOMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CLKEN0;                            /**< IP Clock Enable Control Register 0, offset: 0x0 */
  __IO uint32_t CLKEN1;                            /**< IP Clock Enable Control Register 1, offset: 0x4 */
       uint8_t RESERVED_0[248];
  __I  uint32_t AUDIODSP_REG0;                     /**< AudioDSP EXPSTATE Register, offset: 0x100 */
  __IO uint32_t AUDIODSP_REG1;                     /**< AudioDSP IMPWIRE Register, offset: 0x104 */
  __IO uint32_t AUDIODSP_REG2;                     /**< AudioDSP XOCDMODE Register, offset: 0x108 */
  __IO uint32_t AUDIODSP_REG3;                     /**< AudioDSP PID Register, offset: 0x10C */
       uint8_t RESERVED_1[240];
  __IO uint32_t EARC;                              /**< EARC Control Register, offset: 0x200 */
       uint8_t RESERVED_2[252];
  __IO uint32_t SAI1_MCLK_SEL;                     /**< SAI1 MCLK SELECT Register, offset: 0x300 */
  __IO uint32_t SAI2_MCLK_SEL;                     /**< SAI2 MCLK SELECT Register, offset: 0x304 */
  __IO uint32_t SAI3_MCLK_SEL;                     /**< SAI3 MCLK SELECT Register, offset: 0x308 */
  __IO uint32_t SAI5_MCLK_SEL;                     /**< SAI5 MCLK SELECT Register, offset: 0x30C */
  __IO uint32_t SAI6_MCLK_SEL;                     /**< SAI6 MCLK SELECT Register, offset: 0x310 */
  __IO uint32_t SAI7_MCLK_SEL;                     /**< SAI7 MCLK SELECT Register, offset: 0x314 */
  __IO uint32_t PDM_CLK;                           /**< PDM Root Clock Select Register, offset: 0x318 */
       uint8_t RESERVED_3[228];
  __IO uint32_t SAI_PLL_GNRL_CTL;                  /**< SAI PLL General control Register, offset: 0x400 */
  __IO uint32_t SAI_PLL_FDIV_CTL0;                 /**< SAI PLL Frequency Divider control Register, offset: 0x404 */
  __IO uint32_t SAI_PLL_FDIV_CTL1;                 /**< SAI PLL DSM value Register, offset: 0x408 */
  __IO uint32_t SAI_PLL_SSCG_CTL;                  /**< SAI PLL SSCG control Register, offset: 0x40C */
  __IO uint32_t SAI_PLL_MNIT_CTL;                  /**< SAI PLL SSCG control Register, offset: 0x410 */
       uint8_t RESERVED_4[236];
  __IO uint32_t AUDIO_EXT_ADDR;                    /**< AUDIOMIX Extra Addr Bits Register, offset: 0x500 */
  __IO uint32_t IPG_LP_CTRL;                       /**< IPG Low Power Control Register, offset: 0x504 */
  __IO uint32_t AUDIO_AXI_LIMIT;                   /**< AUDIOMIX AXI LIMIT CTRL Register, offset: 0x508 */
} AUDIOMIX_Type;

/* ----------------------------------------------------------------------------
   -- AUDIOMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIOMIX_Register_Masks AUDIOMIX Register Masks
 * @{
 */

/*! @name CLKEN0 - IP Clock Enable Control Register 0 */
/*! @{ */

#define AUDIOMIX_CLKEN0_SAI1_MASK                (0x1U)
#define AUDIOMIX_CLKEN0_SAI1_SHIFT               (0U)
/*! SAI1 - SAI1 clock enable
 *  0b0..SAI1 sai clock disable
 *  0b1..SAI1 sai clock enable
 */
#define AUDIOMIX_CLKEN0_SAI1(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI1_SHIFT)) & AUDIOMIX_CLKEN0_SAI1_MASK)

#define AUDIOMIX_CLKEN0_SAI1_MCLK1_MASK          (0x2U)
#define AUDIOMIX_CLKEN0_SAI1_MCLK1_SHIFT         (1U)
/*! SAI1_MCLK1 - SAI1 mclk1 clock enable */
#define AUDIOMIX_CLKEN0_SAI1_MCLK1(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI1_MCLK1_SHIFT)) & AUDIOMIX_CLKEN0_SAI1_MCLK1_MASK)

#define AUDIOMIX_CLKEN0_SAI1_MCLK2_MASK          (0x4U)
#define AUDIOMIX_CLKEN0_SAI1_MCLK2_SHIFT         (2U)
/*! SAI1_MCLK2 - SAI1 mclk2 clock enable */
#define AUDIOMIX_CLKEN0_SAI1_MCLK2(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI1_MCLK2_SHIFT)) & AUDIOMIX_CLKEN0_SAI1_MCLK2_MASK)

#define AUDIOMIX_CLKEN0_SAI1_MCLK3_MASK          (0x8U)
#define AUDIOMIX_CLKEN0_SAI1_MCLK3_SHIFT         (3U)
/*! SAI1_MCLK3 - SAI1 mclk3 clock enable */
#define AUDIOMIX_CLKEN0_SAI1_MCLK3(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI1_MCLK3_SHIFT)) & AUDIOMIX_CLKEN0_SAI1_MCLK3_MASK)

#define AUDIOMIX_CLKEN0_SAI2_MASK                (0x10U)
#define AUDIOMIX_CLKEN0_SAI2_SHIFT               (4U)
/*! SAI2 - SAI2 clock enable
 *  0b0..SAI2 sai clock disable
 *  0b1..SAI2 sai clock enable
 */
#define AUDIOMIX_CLKEN0_SAI2(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI2_SHIFT)) & AUDIOMIX_CLKEN0_SAI2_MASK)

#define AUDIOMIX_CLKEN0_SAI2_MCLK1_MASK          (0x20U)
#define AUDIOMIX_CLKEN0_SAI2_MCLK1_SHIFT         (5U)
/*! SAI2_MCLK1 - SAI2 mclk1 clock enable */
#define AUDIOMIX_CLKEN0_SAI2_MCLK1(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI2_MCLK1_SHIFT)) & AUDIOMIX_CLKEN0_SAI2_MCLK1_MASK)

#define AUDIOMIX_CLKEN0_SAI2_MCLK2_MASK          (0x40U)
#define AUDIOMIX_CLKEN0_SAI2_MCLK2_SHIFT         (6U)
/*! SAI2_MCLK2 - SAI2 mclk2 clock enable */
#define AUDIOMIX_CLKEN0_SAI2_MCLK2(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI2_MCLK2_SHIFT)) & AUDIOMIX_CLKEN0_SAI2_MCLK2_MASK)

#define AUDIOMIX_CLKEN0_SAI2_MCLK3_MASK          (0x80U)
#define AUDIOMIX_CLKEN0_SAI2_MCLK3_SHIFT         (7U)
/*! SAI2_MCLK3 - SAI2 mclk3 clock enable */
#define AUDIOMIX_CLKEN0_SAI2_MCLK3(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI2_MCLK3_SHIFT)) & AUDIOMIX_CLKEN0_SAI2_MCLK3_MASK)

#define AUDIOMIX_CLKEN0_SAI3_MASK                (0x100U)
#define AUDIOMIX_CLKEN0_SAI3_SHIFT               (8U)
/*! SAI3 - SAI3 clock enable
 *  0b0..SAI3 sai clock disable
 *  0b1..SAI3 sai clock enable
 */
#define AUDIOMIX_CLKEN0_SAI3(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI3_SHIFT)) & AUDIOMIX_CLKEN0_SAI3_MASK)

#define AUDIOMIX_CLKEN0_SAI3_MCLK1_MASK          (0x200U)
#define AUDIOMIX_CLKEN0_SAI3_MCLK1_SHIFT         (9U)
/*! SAI3_MCLK1 - SAI3 mclk1 clock enable */
#define AUDIOMIX_CLKEN0_SAI3_MCLK1(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI3_MCLK1_SHIFT)) & AUDIOMIX_CLKEN0_SAI3_MCLK1_MASK)

#define AUDIOMIX_CLKEN0_SAI3_MCLK2_MASK          (0x400U)
#define AUDIOMIX_CLKEN0_SAI3_MCLK2_SHIFT         (10U)
/*! SAI3_MCLK2 - SAI3 mclk2 clock enable */
#define AUDIOMIX_CLKEN0_SAI3_MCLK2(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI3_MCLK2_SHIFT)) & AUDIOMIX_CLKEN0_SAI3_MCLK2_MASK)

#define AUDIOMIX_CLKEN0_SAI3_MCLK3_MASK          (0x800U)
#define AUDIOMIX_CLKEN0_SAI3_MCLK3_SHIFT         (11U)
/*! SAI3_MCLK3 - SAI3 mclk3 clock enable */
#define AUDIOMIX_CLKEN0_SAI3_MCLK3(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI3_MCLK3_SHIFT)) & AUDIOMIX_CLKEN0_SAI3_MCLK3_MASK)

#define AUDIOMIX_CLKEN0_SAI5_MASK                (0x1000U)
#define AUDIOMIX_CLKEN0_SAI5_SHIFT               (12U)
/*! SAI5 - SAI5 clock enable
 *  0b0..SAI5 sai clock disable
 *  0b1..SAI5 sai clock enable
 */
#define AUDIOMIX_CLKEN0_SAI5(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI5_SHIFT)) & AUDIOMIX_CLKEN0_SAI5_MASK)

#define AUDIOMIX_CLKEN0_SAI5_MCLK1_MASK          (0x2000U)
#define AUDIOMIX_CLKEN0_SAI5_MCLK1_SHIFT         (13U)
/*! SAI5_MCLK1 - SAI5 mclk1 clock enable */
#define AUDIOMIX_CLKEN0_SAI5_MCLK1(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI5_MCLK1_SHIFT)) & AUDIOMIX_CLKEN0_SAI5_MCLK1_MASK)

#define AUDIOMIX_CLKEN0_SAI5_MCLK2_MASK          (0x4000U)
#define AUDIOMIX_CLKEN0_SAI5_MCLK2_SHIFT         (14U)
/*! SAI5_MCLK2 - SAI5 mclk2 clock enable */
#define AUDIOMIX_CLKEN0_SAI5_MCLK2(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI5_MCLK2_SHIFT)) & AUDIOMIX_CLKEN0_SAI5_MCLK2_MASK)

#define AUDIOMIX_CLKEN0_SAI5_MCLK3_MASK          (0x8000U)
#define AUDIOMIX_CLKEN0_SAI5_MCLK3_SHIFT         (15U)
/*! SAI5_MCLK3 - SAI5 mclk3 clock enable */
#define AUDIOMIX_CLKEN0_SAI5_MCLK3(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI5_MCLK3_SHIFT)) & AUDIOMIX_CLKEN0_SAI5_MCLK3_MASK)

#define AUDIOMIX_CLKEN0_SAI6_MASK                (0x10000U)
#define AUDIOMIX_CLKEN0_SAI6_SHIFT               (16U)
/*! SAI6 - SAI6 clock enable
 *  0b0..SAI6 IPG clock disable
 *  0b1..SAI6 IPG clock enable
 */
#define AUDIOMIX_CLKEN0_SAI6(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI6_SHIFT)) & AUDIOMIX_CLKEN0_SAI6_MASK)

#define AUDIOMIX_CLKEN0_SAI6_MCLK1_MASK          (0x20000U)
#define AUDIOMIX_CLKEN0_SAI6_MCLK1_SHIFT         (17U)
/*! SAI6_MCLK1 - SAI6 mclk1 clock enable */
#define AUDIOMIX_CLKEN0_SAI6_MCLK1(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI6_MCLK1_SHIFT)) & AUDIOMIX_CLKEN0_SAI6_MCLK1_MASK)

#define AUDIOMIX_CLKEN0_SAI6_MCLK2_MASK          (0x40000U)
#define AUDIOMIX_CLKEN0_SAI6_MCLK2_SHIFT         (18U)
/*! SAI6_MCLK2 - SAI6 mclk2 clock enable */
#define AUDIOMIX_CLKEN0_SAI6_MCLK2(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI6_MCLK2_SHIFT)) & AUDIOMIX_CLKEN0_SAI6_MCLK2_MASK)

#define AUDIOMIX_CLKEN0_SAI6_MCLK3_MASK          (0x80000U)
#define AUDIOMIX_CLKEN0_SAI6_MCLK3_SHIFT         (19U)
/*! SAI6_MCLK3 - SAI6 mclk3 clock enable */
#define AUDIOMIX_CLKEN0_SAI6_MCLK3(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI6_MCLK3_SHIFT)) & AUDIOMIX_CLKEN0_SAI6_MCLK3_MASK)

#define AUDIOMIX_CLKEN0_SAI7_MASK                (0x100000U)
#define AUDIOMIX_CLKEN0_SAI7_SHIFT               (20U)
/*! SAI7 - SAI7 clock enable
 *  0b0..SAI7 sai clock disable
 *  0b1..SAI7 sai clock enable
 */
#define AUDIOMIX_CLKEN0_SAI7(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI7_SHIFT)) & AUDIOMIX_CLKEN0_SAI7_MASK)

#define AUDIOMIX_CLKEN0_SAI7_MCLK1_MASK          (0x200000U)
#define AUDIOMIX_CLKEN0_SAI7_MCLK1_SHIFT         (21U)
/*! SAI7_MCLK1 - SAI7 mclk1 clock enable */
#define AUDIOMIX_CLKEN0_SAI7_MCLK1(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI7_MCLK1_SHIFT)) & AUDIOMIX_CLKEN0_SAI7_MCLK1_MASK)

#define AUDIOMIX_CLKEN0_SAI7_MCLK2_MASK          (0x400000U)
#define AUDIOMIX_CLKEN0_SAI7_MCLK2_SHIFT         (22U)
/*! SAI7_MCLK2 - SAI7 mclk2 clock enable */
#define AUDIOMIX_CLKEN0_SAI7_MCLK2(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI7_MCLK2_SHIFT)) & AUDIOMIX_CLKEN0_SAI7_MCLK2_MASK)

#define AUDIOMIX_CLKEN0_SAI7_MCLK3_MASK          (0x800000U)
#define AUDIOMIX_CLKEN0_SAI7_MCLK3_SHIFT         (23U)
/*! SAI7_MCLK3 - SAI7 mclk3 clock enable */
#define AUDIOMIX_CLKEN0_SAI7_MCLK3(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SAI7_MCLK3_SHIFT)) & AUDIOMIX_CLKEN0_SAI7_MCLK3_MASK)

#define AUDIOMIX_CLKEN0_ASRC_MASK                (0x1000000U)
#define AUDIOMIX_CLKEN0_ASRC_SHIFT               (24U)
/*! ASRC - ASRC clock enable */
#define AUDIOMIX_CLKEN0_ASRC(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_ASRC_SHIFT)) & AUDIOMIX_CLKEN0_ASRC_MASK)

#define AUDIOMIX_CLKEN0_PDM_MASK                 (0x2000000U)
#define AUDIOMIX_CLKEN0_PDM_SHIFT                (25U)
/*! PDM - PDM clock enable */
#define AUDIOMIX_CLKEN0_PDM(x)                   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_PDM_SHIFT)) & AUDIOMIX_CLKEN0_PDM_MASK)

#define AUDIOMIX_CLKEN0_SDMA2_MASK               (0x4000000U)
#define AUDIOMIX_CLKEN0_SDMA2_SHIFT              (26U)
/*! SDMA2 - SDMA2 clock enable */
#define AUDIOMIX_CLKEN0_SDMA2(x)                 (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SDMA2_SHIFT)) & AUDIOMIX_CLKEN0_SDMA2_MASK)

#define AUDIOMIX_CLKEN0_SDMA3_MASK               (0x8000000U)
#define AUDIOMIX_CLKEN0_SDMA3_SHIFT              (27U)
/*! SDMA3 - SDMA3 clock enable */
#define AUDIOMIX_CLKEN0_SDMA3(x)                 (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SDMA3_SHIFT)) & AUDIOMIX_CLKEN0_SDMA3_MASK)

#define AUDIOMIX_CLKEN0_SPBA2_MASK               (0x10000000U)
#define AUDIOMIX_CLKEN0_SPBA2_SHIFT              (28U)
/*! SPBA2 - SPBA2 clock enable */
#define AUDIOMIX_CLKEN0_SPBA2(x)                 (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_SPBA2_SHIFT)) & AUDIOMIX_CLKEN0_SPBA2_MASK)

#define AUDIOMIX_CLKEN0_AUDIODSP_MASK            (0x20000000U)
#define AUDIOMIX_CLKEN0_AUDIODSP_SHIFT           (29U)
/*! AudioDSP - AudioDSP core clock enable */
#define AUDIOMIX_CLKEN0_AUDIODSP(x)              (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_AUDIODSP_SHIFT)) & AUDIOMIX_CLKEN0_AUDIODSP_MASK)

#define AUDIOMIX_CLKEN0_AUDIODSP_DEBUG_MASK      (0x40000000U)
#define AUDIOMIX_CLKEN0_AUDIODSP_DEBUG_SHIFT     (30U)
/*! AudioDSP_DEBUG - AudioDSP DEBUG clock enable */
#define AUDIOMIX_CLKEN0_AUDIODSP_DEBUG(x)        (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_AUDIODSP_DEBUG_SHIFT)) & AUDIOMIX_CLKEN0_AUDIODSP_DEBUG_MASK)

#define AUDIOMIX_CLKEN0_EARC_MASK                (0x80000000U)
#define AUDIOMIX_CLKEN0_EARC_SHIFT               (31U)
/*! EARC - EARC clock enable */
#define AUDIOMIX_CLKEN0_EARC(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN0_EARC_SHIFT)) & AUDIOMIX_CLKEN0_EARC_MASK)
/*! @} */

/*! @name CLKEN1 - IP Clock Enable Control Register 1 */
/*! @{ */

#define AUDIOMIX_CLKEN1_OCRAM_A_MASK             (0x1U)
#define AUDIOMIX_CLKEN1_OCRAM_A_SHIFT            (0U)
/*! OCRAM_A - OCRAM_A clock enable */
#define AUDIOMIX_CLKEN1_OCRAM_A(x)               (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN1_OCRAM_A_SHIFT)) & AUDIOMIX_CLKEN1_OCRAM_A_MASK)

#define AUDIOMIX_CLKEN1_AUD2HTX_MASK             (0x2U)
#define AUDIOMIX_CLKEN1_AUD2HTX_SHIFT            (1U)
/*! AUD2HTX - AUDIO LINK MASTER clock enable */
#define AUDIOMIX_CLKEN1_AUD2HTX(x)               (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN1_AUD2HTX_SHIFT)) & AUDIOMIX_CLKEN1_AUD2HTX_MASK)

#define AUDIOMIX_CLKEN1_EDMA_MASK                (0x4U)
#define AUDIOMIX_CLKEN1_EDMA_SHIFT               (2U)
/*! EDMA - EDMA clock enable */
#define AUDIOMIX_CLKEN1_EDMA(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN1_EDMA_SHIFT)) & AUDIOMIX_CLKEN1_EDMA_MASK)

#define AUDIOMIX_CLKEN1_PLL_MASK                 (0x8U)
#define AUDIOMIX_CLKEN1_PLL_SHIFT                (3U)
/*! PLL - PLL clock enable */
#define AUDIOMIX_CLKEN1_PLL(x)                   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN1_PLL_SHIFT)) & AUDIOMIX_CLKEN1_PLL_MASK)

#define AUDIOMIX_CLKEN1_MU2_MASK                 (0x10U)
#define AUDIOMIX_CLKEN1_MU2_SHIFT                (4U)
/*! MU2 - MU2 clock enable */
#define AUDIOMIX_CLKEN1_MU2(x)                   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN1_MU2_SHIFT)) & AUDIOMIX_CLKEN1_MU2_MASK)

#define AUDIOMIX_CLKEN1_MU3_MASK                 (0x20U)
#define AUDIOMIX_CLKEN1_MU3_SHIFT                (5U)
/*! MU3 - MU3 clock enable */
#define AUDIOMIX_CLKEN1_MU3(x)                   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN1_MU3_SHIFT)) & AUDIOMIX_CLKEN1_MU3_MASK)

#define AUDIOMIX_CLKEN1_EARC_PHY_MASK            (0x40U)
#define AUDIOMIX_CLKEN1_EARC_PHY_SHIFT           (6U)
/*! EARC_PHY - EARC PHY audio ss clock enable */
#define AUDIOMIX_CLKEN1_EARC_PHY(x)              (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_CLKEN1_EARC_PHY_SHIFT)) & AUDIOMIX_CLKEN1_EARC_PHY_MASK)
/*! @} */

/*! @name AUDIODSP_REG0 - AudioDSP EXPSTATE Register */
/*! @{ */

#define AUDIOMIX_AUDIODSP_REG0_EXPSTATE_MASK     (0xFFFFFFFFU)
#define AUDIOMIX_AUDIODSP_REG0_EXPSTATE_SHIFT    (0U)
/*! EXPSTATE - TIE_EXPSTATE output port of the AudioDSP */
#define AUDIOMIX_AUDIODSP_REG0_EXPSTATE(x)       (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG0_EXPSTATE_SHIFT)) & AUDIOMIX_AUDIODSP_REG0_EXPSTATE_MASK)
/*! @} */

/*! @name AUDIODSP_REG1 - AudioDSP IMPWIRE Register */
/*! @{ */

#define AUDIOMIX_AUDIODSP_REG1_IMPWIRE_MASK      (0xFFFFFFFFU)
#define AUDIOMIX_AUDIODSP_REG1_IMPWIRE_SHIFT     (0U)
/*! IMPWIRE - TIE_IMPWIRE input port of the AudioDSP */
#define AUDIOMIX_AUDIODSP_REG1_IMPWIRE(x)        (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG1_IMPWIRE_SHIFT)) & AUDIOMIX_AUDIODSP_REG1_IMPWIRE_MASK)
/*! @} */

/*! @name AUDIODSP_REG2 - AudioDSP XOCDMODE Register */
/*! @{ */

#define AUDIOMIX_AUDIODSP_REG2_XOCDMODE_MASK     (0x1U)
#define AUDIOMIX_AUDIODSP_REG2_XOCDMODE_SHIFT    (0U)
/*! XOCDMODE - Indicates that the AudioDSP is in OCD halt mode */
#define AUDIOMIX_AUDIODSP_REG2_XOCDMODE(x)       (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_XOCDMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_XOCDMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_PWAITMODE_MASK    (0x2U)
#define AUDIOMIX_AUDIODSP_REG2_PWAITMODE_SHIFT   (1U)
/*! PWAITMODE - Indicates that the AudioDSP is in sleep mode. The processor asserts this signal when
 *    it has executed a WAITI instruction and is waiting for an interrupt.
 */
#define AUDIOMIX_AUDIODSP_REG2_PWAITMODE(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_PWAITMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_PWAITMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_OCDHALTONRESET_MASK (0x10U)
#define AUDIOMIX_AUDIODSP_REG2_OCDHALTONRESET_SHIFT (4U)
/*! OCDHALTONRESET - AudioDSP enters OCDHaltMode if this signal is samped asserted on reset. */
#define AUDIOMIX_AUDIODSP_REG2_OCDHALTONRESET(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_OCDHALTONRESET_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_OCDHALTONRESET_MASK)

#define AUDIOMIX_AUDIODSP_REG2_RUNSTALL_MASK     (0x20U)
#define AUDIOMIX_AUDIODSP_REG2_RUNSTALL_SHIFT    (5U)
/*! RunStall - AudioDSP RunStall control bit.
 *  0b1..stalls the processor
 */
#define AUDIOMIX_AUDIODSP_REG2_RUNSTALL(x)       (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_RUNSTALL_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_RUNSTALL_MASK)

#define AUDIOMIX_AUDIODSP_REG2_STATVECTORSEL_MASK (0x40U)
#define AUDIOMIX_AUDIODSP_REG2_STATVECTORSEL_SHIFT (6U)
/*! StatVectorSel - Selects between one of two stationary vector bases
 *  0b0..default
 *  0b1..alternative
 */
#define AUDIOMIX_AUDIODSP_REG2_STATVECTORSEL(x)  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_STATVECTORSEL_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_STATVECTORSEL_MASK)

#define AUDIOMIX_AUDIODSP_REG2_ADDRMODE_MASK     (0x100U)
#define AUDIOMIX_AUDIODSP_REG2_ADDRMODE_SHIFT    (8U)
#define AUDIOMIX_AUDIODSP_REG2_ADDRMODE(x)       (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_ADDRMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_ADDRMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_DSMMODE_MASK      (0x200U)
#define AUDIOMIX_AUDIODSP_REG2_DSMMODE_SHIFT     (9U)
/*! DsmMode - AudioDSP in DSM Mode for MU
 *  0b0..not in DSM mode
 *  0b1..in DSM mode
 */
#define AUDIOMIX_AUDIODSP_REG2_DSMMODE(x)        (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_DSMMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_DSMMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_WAITMODE_MASK     (0x400U)
#define AUDIOMIX_AUDIODSP_REG2_WAITMODE_SHIFT    (10U)
/*! WaitMode - AudioDSP in Wait Mode for MU
 *  0b0..not in wait mode
 *  0b1..in wait mode
 */
#define AUDIOMIX_AUDIODSP_REG2_WAITMODE(x)       (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_WAITMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_WAITMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_M7DSMMODE_MASK    (0x800U)
#define AUDIOMIX_AUDIODSP_REG2_M7DSMMODE_SHIFT   (11U)
/*! m7DsmMode - M7 in DSM Mode for MU3
 *  0b0..not in DSM mode
 *  0b1..in DSM mode
 */
#define AUDIOMIX_AUDIODSP_REG2_M7DSMMODE(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_M7DSMMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_M7DSMMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_M7WAITMODE_MASK   (0x1000U)
#define AUDIOMIX_AUDIODSP_REG2_M7WAITMODE_SHIFT  (12U)
/*! m7WaitMode - M7 in Wait Mode for MU3
 *  0b0..not in wait mode
 *  0b1..in wait mode
 */
#define AUDIOMIX_AUDIODSP_REG2_M7WAITMODE(x)     (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_M7WAITMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_M7WAITMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_A53DSMMODE_MASK   (0x2000U)
#define AUDIOMIX_AUDIODSP_REG2_A53DSMMODE_SHIFT  (13U)
/*! a53DsmMode - CA53 in DSM Mode for MU2
 *  0b0..not in DSM mode
 *  0b1..in DSM mode
 */
#define AUDIOMIX_AUDIODSP_REG2_A53DSMMODE(x)     (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_A53DSMMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_A53DSMMODE_MASK)

#define AUDIOMIX_AUDIODSP_REG2_A53WAITMODE_MASK  (0x4000U)
#define AUDIOMIX_AUDIODSP_REG2_A53WAITMODE_SHIFT (14U)
/*! a53WaitMode - CA53 in Wait Mode for MU2
 *  0b0..not in wait mode
 *  0b1..in wait mode
 */
#define AUDIOMIX_AUDIODSP_REG2_A53WAITMODE(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG2_A53WAITMODE_SHIFT)) & AUDIOMIX_AUDIODSP_REG2_A53WAITMODE_MASK)
/*! @} */

/*! @name AUDIODSP_REG3 - AudioDSP PID Register */
/*! @{ */

#define AUDIOMIX_AUDIODSP_REG3_PID_MASK          (0xFFFFU)
#define AUDIOMIX_AUDIODSP_REG3_PID_SHIFT         (0U)
/*! PID - AudioDSP PID Register. Input to the AudioDSP, latched at reset into the low-order bits of
 *    the PRID(processor ID) special register.
 */
#define AUDIOMIX_AUDIODSP_REG3_PID(x)            (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIODSP_REG3_PID_SHIFT)) & AUDIOMIX_AUDIODSP_REG3_PID_MASK)
/*! @} */

/*! @name EARC - EARC Control Register */
/*! @{ */

#define AUDIOMIX_EARC_RESETB_MASK                (0x1U)
#define AUDIOMIX_EARC_RESETB_SHIFT               (0U)
/*! RESETB - Earc Software Reset.
 *  0b0..provide a software reset for EARC controller
 *  0b1..return from reset
 */
#define AUDIOMIX_EARC_RESETB(x)                  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_EARC_RESETB_SHIFT)) & AUDIOMIX_EARC_RESETB_MASK)

#define AUDIOMIX_EARC_PHY_RESETB_MASK            (0x2U)
#define AUDIOMIX_EARC_PHY_RESETB_SHIFT           (1U)
/*! PHY_RESETB - Earc PHY Software Reset.
 *  0b0..provide a software reset for EARC PHY
 *  0b1..return from reset
 */
#define AUDIOMIX_EARC_PHY_RESETB(x)              (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_EARC_PHY_RESETB_SHIFT)) & AUDIOMIX_EARC_PHY_RESETB_MASK)
/*! @} */

/*! @name SAI1_MCLK_SEL - SAI1 MCLK SELECT Register */
/*! @{ */

#define AUDIOMIX_SAI1_MCLK_SEL_MCLK1_SEL_MASK    (0x1U)
#define AUDIOMIX_SAI1_MCLK_SEL_MCLK1_SEL_SHIFT   (0U)
/*! MCLK1_SEL
 *  0b0..SAI1_CLK_ROOT is selected
 *  0b1..SAI1.MCLK is selected
 */
#define AUDIOMIX_SAI1_MCLK_SEL_MCLK1_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI1_MCLK_SEL_MCLK1_SEL_SHIFT)) & AUDIOMIX_SAI1_MCLK_SEL_MCLK1_SEL_MASK)

#define AUDIOMIX_SAI1_MCLK_SEL_MCLK2_SEL_MASK    (0x1EU)
#define AUDIOMIX_SAI1_MCLK_SEL_MCLK2_SEL_SHIFT   (1U)
/*! MCLK2_SEL
 *  0b0000..SAI1_CLK_ROOT is selected
 *  0b0001..SAI2_CLK_ROOT is selected
 *  0b0010..SAI3_CLK_ROOT is selected
 *  0b0011..Reserved, MCLK2 is 0
 *  0b0100..SAI5_CLK_ROOT is selected
 *  0b0101..SAI6_CLK_ROOT is selected
 *  0b0110..SAI7_CLK_ROOT is selected
 *  0b0111..SAI1.MCLK is selected
 *  0b1000..SAI2.MCLK is selected
 *  0b1001..SAI3.MCLK is selected
 *  0b1010..Reserved, MCLK2 is 0
 *  0b1011..SAI5.MCLK is selected
 *  0b1100..SAI6.MCLK is selected
 *  0b1101..SAI7.MCLK is selected
 *  0b1110..SPDIF.ETXCLK is selected
 */
#define AUDIOMIX_SAI1_MCLK_SEL_MCLK2_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI1_MCLK_SEL_MCLK2_SEL_SHIFT)) & AUDIOMIX_SAI1_MCLK_SEL_MCLK2_SEL_MASK)
/*! @} */

/*! @name SAI2_MCLK_SEL - SAI2 MCLK SELECT Register */
/*! @{ */

#define AUDIOMIX_SAI2_MCLK_SEL_MCLK1_SEL_MASK    (0x1U)
#define AUDIOMIX_SAI2_MCLK_SEL_MCLK1_SEL_SHIFT   (0U)
/*! MCLK1_SEL
 *  0b0..SAI2_CLK_ROOT is selected
 *  0b1..SAI2.MCLK is selected
 */
#define AUDIOMIX_SAI2_MCLK_SEL_MCLK1_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI2_MCLK_SEL_MCLK1_SEL_SHIFT)) & AUDIOMIX_SAI2_MCLK_SEL_MCLK1_SEL_MASK)

#define AUDIOMIX_SAI2_MCLK_SEL_MCLK2_SEL_MASK    (0x1EU)
#define AUDIOMIX_SAI2_MCLK_SEL_MCLK2_SEL_SHIFT   (1U)
/*! MCLK2_SEL
 *  0b0000..SAI1_CLK_ROOT is selected
 *  0b0001..SAI2_CLK_ROOT is selected
 *  0b0010..SAI3_CLK_ROOT is selected
 *  0b0011..Reserved, MCLK2 is 0
 *  0b0100..SAI5_CLK_ROOT is selected
 *  0b0101..SAI6_CLK_ROOT is selected
 *  0b0110..SAI7_CLK_ROOT is selected
 *  0b0111..SAI1.MCLK is selected
 *  0b1000..SAI2.MCLK is selected
 *  0b1001..SAI3.MCLK is selected
 *  0b1010..Reserved, MCLK is 0
 *  0b1011..SAI5.MCLK is selected
 *  0b1100..SAI6.MCLK is selected
 *  0b1101..SAI7.MCLK is selected
 *  0b1110..SPDIF.ETXCLK is selected
 */
#define AUDIOMIX_SAI2_MCLK_SEL_MCLK2_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI2_MCLK_SEL_MCLK2_SEL_SHIFT)) & AUDIOMIX_SAI2_MCLK_SEL_MCLK2_SEL_MASK)
/*! @} */

/*! @name SAI3_MCLK_SEL - SAI3 MCLK SELECT Register */
/*! @{ */

#define AUDIOMIX_SAI3_MCLK_SEL_MCLK1_SEL_MASK    (0x1U)
#define AUDIOMIX_SAI3_MCLK_SEL_MCLK1_SEL_SHIFT   (0U)
/*! MCLK1_SEL - MCLK1 Select Register
 *  0b0..SAI3_CLK_ROOT is selected
 *  0b1..SAI3.MCLK is selected
 */
#define AUDIOMIX_SAI3_MCLK_SEL_MCLK1_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI3_MCLK_SEL_MCLK1_SEL_SHIFT)) & AUDIOMIX_SAI3_MCLK_SEL_MCLK1_SEL_MASK)

#define AUDIOMIX_SAI3_MCLK_SEL_MCLK2_SEL_MASK    (0x1EU)
#define AUDIOMIX_SAI3_MCLK_SEL_MCLK2_SEL_SHIFT   (1U)
/*! MCLK2_SEL - MCLK2 Select Register
 *  0b0000..SAI1_CLK_ROOT is selected
 *  0b0001..SAI2_CLK_ROOT is selected
 *  0b0010..SAI3_CLK_ROOT is selected
 *  0b0011..Reserved, MCLK2 is 0
 *  0b0100..SAI5_CLK_ROOT is selected
 *  0b0101..SAI6_CLK_ROOT is selected
 *  0b0110..SAI7_CLK_ROOT is selected
 *  0b0111..SAI1.MCLK is selected
 *  0b1000..SAI2.MCLK is selected
 *  0b1001..SAI3.MCLK is selected
 *  0b1010..Reserved, MCLK is 0
 *  0b1011..SAI5.MCLK is selected
 *  0b1100..SAI6.MCLK is selected
 *  0b1101..SAI7.MCLK is selected
 *  0b1110..SPDIF.ETXCLK is selected
 */
#define AUDIOMIX_SAI3_MCLK_SEL_MCLK2_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI3_MCLK_SEL_MCLK2_SEL_SHIFT)) & AUDIOMIX_SAI3_MCLK_SEL_MCLK2_SEL_MASK)
/*! @} */

/*! @name SAI5_MCLK_SEL - SAI5 MCLK SELECT Register */
/*! @{ */

#define AUDIOMIX_SAI5_MCLK_SEL_MCLK1_SEL_MASK    (0x1U)
#define AUDIOMIX_SAI5_MCLK_SEL_MCLK1_SEL_SHIFT   (0U)
/*! MCLK1_SEL - MCLK1 Select Register
 *  0b0..SAI5_CLK_ROOT is selected
 *  0b1..SAI5.MCLK is selected
 */
#define AUDIOMIX_SAI5_MCLK_SEL_MCLK1_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI5_MCLK_SEL_MCLK1_SEL_SHIFT)) & AUDIOMIX_SAI5_MCLK_SEL_MCLK1_SEL_MASK)

#define AUDIOMIX_SAI5_MCLK_SEL_MCLK2_SEL_MASK    (0x1EU)
#define AUDIOMIX_SAI5_MCLK_SEL_MCLK2_SEL_SHIFT   (1U)
/*! MCLK2_SEL - MCLK2 Select Register
 *  0b0000..SAI1_CLK_ROOT is selected
 *  0b0001..SAI2_CLK_ROOT is selected
 *  0b0010..SAI3_CLK_ROOT is selected
 *  0b0011..Reserved, MCLK2 is 0
 *  0b0100..SAI5_CLK_ROOT is selected
 *  0b0101..SAI6_CLK_ROOT is selected
 *  0b0110..SAI7_CLK_ROOT is selected
 *  0b0111..SAI1.MCLK is selected
 *  0b1000..SAI2.MCLK is selected
 *  0b1001..SAI3.MCLK is selected
 *  0b1010..Reserved, MCLK is 0
 *  0b1011..SAI5.MCLK is selected
 *  0b1100..SAI6.MCLK is selected
 *  0b1101..SAI7.MCLK is selected
 *  0b1110..SPDIF.ETXCLK is selected
 */
#define AUDIOMIX_SAI5_MCLK_SEL_MCLK2_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI5_MCLK_SEL_MCLK2_SEL_SHIFT)) & AUDIOMIX_SAI5_MCLK_SEL_MCLK2_SEL_MASK)
/*! @} */

/*! @name SAI6_MCLK_SEL - SAI6 MCLK SELECT Register */
/*! @{ */

#define AUDIOMIX_SAI6_MCLK_SEL_MCLK1_SEL_MASK    (0x1U)
#define AUDIOMIX_SAI6_MCLK_SEL_MCLK1_SEL_SHIFT   (0U)
/*! MCLK1_SEL - MCLK1 Select Register
 *  0b0..SAI6_CLK_ROOT is selected
 *  0b1..SAI6.MCLK is selected
 */
#define AUDIOMIX_SAI6_MCLK_SEL_MCLK1_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI6_MCLK_SEL_MCLK1_SEL_SHIFT)) & AUDIOMIX_SAI6_MCLK_SEL_MCLK1_SEL_MASK)

#define AUDIOMIX_SAI6_MCLK_SEL_MCLK2_SEL_MASK    (0x1EU)
#define AUDIOMIX_SAI6_MCLK_SEL_MCLK2_SEL_SHIFT   (1U)
/*! MCLK2_SEL - MCLK2 Select Register
 *  0b0000..SAI1_CLK_ROOT is selected
 *  0b0001..SAI2_CLK_ROOT is selected
 *  0b0010..SAI3_CLK_ROOT is selected
 *  0b0011..Reserved, MCLK2 is 0
 *  0b0100..SAI5_CLK_ROOT is selected
 *  0b0101..SAI6_CLK_ROOT is selected
 *  0b0110..SAI7_CLK_ROOT is selected
 *  0b0111..SAI1.MCLK is selected
 *  0b1000..SAI2.MCLK is selected
 *  0b1001..SAI3.MCLK is selected
 *  0b1010..Reserved, MCLK is 0
 *  0b1011..SAI5.MCLK is selected
 *  0b1100..SAI6.MCLK is selected
 *  0b1101..SAI7.MCLK is selected
 *  0b1110..SPDIF.ETXCLK is selected
 */
#define AUDIOMIX_SAI6_MCLK_SEL_MCLK2_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI6_MCLK_SEL_MCLK2_SEL_SHIFT)) & AUDIOMIX_SAI6_MCLK_SEL_MCLK2_SEL_MASK)
/*! @} */

/*! @name SAI7_MCLK_SEL - SAI7 MCLK SELECT Register */
/*! @{ */

#define AUDIOMIX_SAI7_MCLK_SEL_MCLK1_SEL_MASK    (0x1U)
#define AUDIOMIX_SAI7_MCLK_SEL_MCLK1_SEL_SHIFT   (0U)
/*! MCLK1_SEL - MCLK1 Select Register
 *  0b0..SAI7_CLK_ROOT is selected
 *  0b1..SAI7.MCLK is selected
 */
#define AUDIOMIX_SAI7_MCLK_SEL_MCLK1_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI7_MCLK_SEL_MCLK1_SEL_SHIFT)) & AUDIOMIX_SAI7_MCLK_SEL_MCLK1_SEL_MASK)

#define AUDIOMIX_SAI7_MCLK_SEL_MCLK2_SEL_MASK    (0x1EU)
#define AUDIOMIX_SAI7_MCLK_SEL_MCLK2_SEL_SHIFT   (1U)
/*! MCLK2_SEL - MCLK2 Select Register
 *  0b0000..SAI1_CLK_ROOT is selected
 *  0b0001..SAI2_CLK_ROOT is selected
 *  0b0010..SAI3_CLK_ROOT is selected
 *  0b0011..Reserved, MCLK2 is 0
 *  0b0100..SAI5_CLK_ROOT is selected
 *  0b0101..SAI6_CLK_ROOT is selected
 *  0b0110..SAI7_CLK_ROOT is selected
 *  0b0111..SAI1.MCLK is selected
 *  0b1000..SAI2.MCLK is selected
 *  0b1001..SAI3.MCLK is selected
 *  0b1010..Reserved, MCLK is 0
 *  0b1011..SAI5.MCLK is selected
 *  0b1100..SAI6.MCLK is selected
 *  0b1101..SAI7.MCLK is selected
 *  0b1110..SPDIF.ETXCLK is selected
 */
#define AUDIOMIX_SAI7_MCLK_SEL_MCLK2_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI7_MCLK_SEL_MCLK2_SEL_SHIFT)) & AUDIOMIX_SAI7_MCLK_SEL_MCLK2_SEL_MASK)
/*! @} */

/*! @name PDM_CLK - PDM Root Clock Select Register */
/*! @{ */

#define AUDIOMIX_PDM_CLK_SELECT_MASK             (0x3U)
#define AUDIOMIX_PDM_CLK_SELECT_SHIFT            (0U)
/*! select - PDM Root Clock Select Bits
 *  0b00..ccm pdm clock is selected
 *  0b01..sai_pll div2 is selected
 *  0b10..SAI1_MCLK is selected
 *  0b11..reserved.
 */
#define AUDIOMIX_PDM_CLK_SELECT(x)               (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_PDM_CLK_SELECT_SHIFT)) & AUDIOMIX_PDM_CLK_SELECT_MASK)
/*! @} */

/*! @name SAI_PLL_GNRL_CTL - SAI PLL General control Register */
/*! @{ */

#define AUDIOMIX_SAI_PLL_GNRL_CTL_REF_CLK_SEL_MASK (0x3U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_REF_CLK_SEL_SHIFT (0U)
/*! ref_clk_sel - reference clock select */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_REF_CLK_SEL_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_REF_CLK_SEL_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_PAD_CLK_SEL_MASK (0xCU)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_PAD_CLK_SEL_SHIFT (2U)
/*! pad_clk_sel - pad clock select */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_PAD_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_PAD_CLK_SEL_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_PAD_CLK_SEL_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_BYPASS_MASK    (0x10U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_BYPASS_SHIFT   (4U)
/*! bypass - pll bypass */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_BYPASS(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_BYPASS_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_BYPASS_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_OVERRIDE_MASK (0x100U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_OVERRIDE_SHIFT (8U)
/*! resetb_override - resetb override */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_OVERRIDE_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_OVERRIDE_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_MASK    (0x200U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_SHIFT   (9U)
/*! resetb - pll resetb */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_RESETB_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_OVERRIDE_MASK (0x1000U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_OVERRIDE_SHIFT (12U)
/*! cke_override - pll cke override. */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_OVERRIDE_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_OVERRIDE_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_MASK       (0x2000U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_SHIFT      (13U)
/*! cke - pll cke */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_CKE(x)         (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_CKE_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_BLK_BYPASS_MASK (0x10000U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_BLK_BYPASS_SHIFT (16U)
/*! blk_bypass - blk bypass */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_BLK_BYPASS(x)  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_BLK_BYPASS_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_BLK_BYPASS_MASK)

#define AUDIOMIX_SAI_PLL_GNRL_CTL_LOCK_MASK      (0x80000000U)
#define AUDIOMIX_SAI_PLL_GNRL_CTL_LOCK_SHIFT     (31U)
/*! lock - pll lock */
#define AUDIOMIX_SAI_PLL_GNRL_CTL_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_GNRL_CTL_LOCK_SHIFT)) & AUDIOMIX_SAI_PLL_GNRL_CTL_LOCK_MASK)
/*! @} */

/*! @name SAI_PLL_FDIV_CTL0 - SAI PLL Frequency Divider control Register */
/*! @{ */

#define AUDIOMIX_SAI_PLL_FDIV_CTL0_POST_DIV_MASK (0x7U)
#define AUDIOMIX_SAI_PLL_FDIV_CTL0_POST_DIV_SHIFT (0U)
/*! post_div - post divider value */
#define AUDIOMIX_SAI_PLL_FDIV_CTL0_POST_DIV(x)   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_FDIV_CTL0_POST_DIV_SHIFT)) & AUDIOMIX_SAI_PLL_FDIV_CTL0_POST_DIV_MASK)

#define AUDIOMIX_SAI_PLL_FDIV_CTL0_PRE_DIV_MASK  (0x3F0U)
#define AUDIOMIX_SAI_PLL_FDIV_CTL0_PRE_DIV_SHIFT (4U)
/*! pre_div - pre divider value */
#define AUDIOMIX_SAI_PLL_FDIV_CTL0_PRE_DIV(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_FDIV_CTL0_PRE_DIV_SHIFT)) & AUDIOMIX_SAI_PLL_FDIV_CTL0_PRE_DIV_MASK)

#define AUDIOMIX_SAI_PLL_FDIV_CTL0_MAIN_DIV_MASK (0x3FF000U)
#define AUDIOMIX_SAI_PLL_FDIV_CTL0_MAIN_DIV_SHIFT (12U)
/*! main_div - main divider value */
#define AUDIOMIX_SAI_PLL_FDIV_CTL0_MAIN_DIV(x)   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_FDIV_CTL0_MAIN_DIV_SHIFT)) & AUDIOMIX_SAI_PLL_FDIV_CTL0_MAIN_DIV_MASK)
/*! @} */

/*! @name SAI_PLL_FDIV_CTL1 - SAI PLL DSM value Register */
/*! @{ */

#define AUDIOMIX_SAI_PLL_FDIV_CTL1_DSM_MASK      (0xFFFFU)
#define AUDIOMIX_SAI_PLL_FDIV_CTL1_DSM_SHIFT     (0U)
/*! dsm - pll DSM(K) value */
#define AUDIOMIX_SAI_PLL_FDIV_CTL1_DSM(x)        (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_FDIV_CTL1_DSM_SHIFT)) & AUDIOMIX_SAI_PLL_FDIV_CTL1_DSM_MASK)
/*! @} */

/*! @name SAI_PLL_SSCG_CTL - SAI PLL SSCG control Register */
/*! @{ */

#define AUDIOMIX_SAI_PLL_SSCG_CTL_SEL_PF_MASK    (0x3U)
#define AUDIOMIX_SAI_PLL_SSCG_CTL_SEL_PF_SHIFT   (0U)
/*! sel_pf - pll modulation method control */
#define AUDIOMIX_SAI_PLL_SSCG_CTL_SEL_PF(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_SSCG_CTL_SEL_PF_SHIFT)) & AUDIOMIX_SAI_PLL_SSCG_CTL_SEL_PF_MASK)

#define AUDIOMIX_SAI_PLL_SSCG_CTL_MRAT_CTL_MASK  (0x3F0U)
#define AUDIOMIX_SAI_PLL_SSCG_CTL_MRAT_CTL_SHIFT (4U)
/*! mrat_ctl - pll modulation rate control */
#define AUDIOMIX_SAI_PLL_SSCG_CTL_MRAT_CTL(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_SSCG_CTL_MRAT_CTL_SHIFT)) & AUDIOMIX_SAI_PLL_SSCG_CTL_MRAT_CTL_MASK)

#define AUDIOMIX_SAI_PLL_SSCG_CTL_MFREQ_CTL_MASK (0xFF000U)
#define AUDIOMIX_SAI_PLL_SSCG_CTL_MFREQ_CTL_SHIFT (12U)
/*! mfreq_ctl - pll modulation frequency control */
#define AUDIOMIX_SAI_PLL_SSCG_CTL_MFREQ_CTL(x)   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_SSCG_CTL_MFREQ_CTL_SHIFT)) & AUDIOMIX_SAI_PLL_SSCG_CTL_MFREQ_CTL_MASK)

#define AUDIOMIX_SAI_PLL_SSCG_CTL_SSCG_EN_MASK   (0x80000000U)
#define AUDIOMIX_SAI_PLL_SSCG_CTL_SSCG_EN_SHIFT  (31U)
/*! sscg_en - SSCG Enable Bit */
#define AUDIOMIX_SAI_PLL_SSCG_CTL_SSCG_EN(x)     (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_SSCG_CTL_SSCG_EN_SHIFT)) & AUDIOMIX_SAI_PLL_SSCG_CTL_SSCG_EN_MASK)
/*! @} */

/*! @name SAI_PLL_MNIT_CTL - SAI PLL SSCG control Register */
/*! @{ */

#define AUDIOMIX_SAI_PLL_MNIT_CTL_ICP_MASK       (0x7U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_ICP_SHIFT      (0U)
/*! icp - Charge-pump current control */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_ICP(x)         (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_ICP_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_ICP_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_ENB_MASK   (0x8U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_ENB_SHIFT  (3U)
/*! afc_enb - AFC Enable control */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_ENB(x)     (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_ENB_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_ENB_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_EXTAFC_MASK    (0x1F0U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_EXTAFC_SHIFT   (4U)
/*! extafc - AFC Enable control */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_EXTAFC(x)      (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_EXTAFC_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_EXTAFC_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_FEED_EN_MASK   (0x4000U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_FEED_EN_SHIFT  (14U)
/*! feed_en - PLL FEED Enable control */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_FEED_EN(x)     (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_FEED_EN_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_FEED_EN_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_FSEL_MASK      (0x8000U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_FSEL_SHIFT     (15U)
/*! fsel - PLL FEED SEL control */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_FSEL(x)        (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_FSEL_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_FSEL_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFCINIT_SEL_MASK (0x20000U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFCINIT_SEL_SHIFT (17U)
/*! afcinit_sel - PLL AFC INIT SEL */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_AFCINIT_SEL_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_AFCINIT_SEL_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_EN_MASK (0x40000U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_EN_SHIFT (18U)
/*! pbias_ctrl_en - PLL PBIAS CTRL EN */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_EN_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_EN_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_MASK (0x80000U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_SHIFT (19U)
/*! pbias_ctrl - PLL PBIAS CTRL */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_PBIAS_CTRL_MASK)

#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_SEL_MASK   (0x100000U)
#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_SEL_SHIFT  (20U)
/*! afc_sel - PLL AFC SEL */
#define AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_SEL(x)     (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_SEL_SHIFT)) & AUDIOMIX_SAI_PLL_MNIT_CTL_AFC_SEL_MASK)
/*! @} */

/*! @name AUDIO_EXT_ADDR - AUDIOMIX Extra Addr Bits Register */
/*! @{ */

#define AUDIOMIX_AUDIO_EXT_ADDR_SDMA2_MASK       (0x3U)
#define AUDIOMIX_AUDIO_EXT_ADDR_SDMA2_SHIFT      (0U)
/*! sdma2 - SDMA2 Extra Addr Bits */
#define AUDIOMIX_AUDIO_EXT_ADDR_SDMA2(x)         (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIO_EXT_ADDR_SDMA2_SHIFT)) & AUDIOMIX_AUDIO_EXT_ADDR_SDMA2_MASK)

#define AUDIOMIX_AUDIO_EXT_ADDR_SDMA3_MASK       (0xCU)
#define AUDIOMIX_AUDIO_EXT_ADDR_SDMA3_SHIFT      (2U)
/*! sdma3 - SDMA3 Extra Addr Bits */
#define AUDIOMIX_AUDIO_EXT_ADDR_SDMA3(x)         (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIO_EXT_ADDR_SDMA3_SHIFT)) & AUDIOMIX_AUDIO_EXT_ADDR_SDMA3_MASK)

#define AUDIOMIX_AUDIO_EXT_ADDR_EDMA_MASK        (0x30U)
#define AUDIOMIX_AUDIO_EXT_ADDR_EDMA_SHIFT       (4U)
/*! edma - EDMA extra Addr Bits */
#define AUDIOMIX_AUDIO_EXT_ADDR_EDMA(x)          (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIO_EXT_ADDR_EDMA_SHIFT)) & AUDIOMIX_AUDIO_EXT_ADDR_EDMA_MASK)
/*! @} */

/*! @name IPG_LP_CTRL - IPG Low Power Control Register */
/*! @{ */

#define AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_MASK  (0x1U)
#define AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_SHIFT (0U)
/*! edma_ipg_stop - EDMA IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_MASK (0x2U)
#define AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_SHIFT (1U)
/*! sdma2_ipg_stop - SDMA2 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP(x)   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_MASK (0x4U)
#define AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_SHIFT (2U)
/*! sdma3_ipg_stop - SDMA3 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP(x)   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_MASK   (0x8U)
#define AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_SHIFT  (3U)
/*! pdm_ipg_stop - PDM IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP(x)     (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_MASK  (0x10U)
#define AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_SHIFT (4U)
/*! sai1_ipg_stop - SAI1 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_MASK  (0x20U)
#define AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_SHIFT (5U)
/*! sai2_ipg_stop - SAI2 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_MASK  (0x40U)
#define AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_SHIFT (6U)
/*! sai3_ipg_stop - SAI3 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_MASK  (0x80U)
#define AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_SHIFT (7U)
/*! sai5_ipg_stop - SAI5 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_MASK  (0x100U)
#define AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_SHIFT (8U)
/*! sai6_ipg_stop - SAI6 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_MASK  (0x200U)
#define AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_SHIFT (9U)
/*! sai7_ipg_stop - SAI1 IPG_STOP Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_MASK)

#define AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_ACK_MASK (0x400U)
#define AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_ACK_SHIFT (10U)
/*! edma_ipg_stop_ack - EDMA IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_EDMA_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_ACK_MASK (0x800U)
#define AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_ACK_SHIFT (11U)
/*! sdma2_ipg_stop_ack - SDMA2 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SDMA2_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_ACK_MASK (0x1000U)
#define AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_ACK_SHIFT (12U)
/*! sdma3_ipg_stop_ack - SDMA3 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SDMA3_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_ACK_MASK (0x2000U)
#define AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_ACK_SHIFT (13U)
/*! pdm_ipg_stop_ack - PDM IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_PDM_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_ACK_MASK (0x4000U)
#define AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_ACK_SHIFT (14U)
/*! sai1_ipg_stop_ack - SAI1 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI1_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_ACK_MASK (0x8000U)
#define AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_ACK_SHIFT (15U)
/*! sai2_ipg_stop_ack - SAI2 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI2_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_ACK_MASK (0x10000U)
#define AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_ACK_SHIFT (16U)
/*! sai3_ipg_stop_ack - SAI3 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI3_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_ACK_MASK (0x20000U)
#define AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_ACK_SHIFT (17U)
/*! sai5_ipg_stop_ack - SAI5 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI5_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_ACK_MASK (0x40000U)
#define AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_ACK_SHIFT (18U)
/*! sai6_ipg_stop_ack - SAI6 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI6_IPG_STOP_ACK_MASK)

#define AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_ACK_MASK (0x80000U)
#define AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_ACK_SHIFT (19U)
/*! sai7_ipg_stop_ack - SAI1 IPG_STOP_ACK Bit */
#define AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_ACK_SHIFT)) & AUDIOMIX_IPG_LP_CTRL_SAI7_IPG_STOP_ACK_MASK)
/*! @} */

/*! @name AUDIO_AXI_LIMIT - AUDIOMIX AXI LIMIT CTRL Register */
/*! @{ */

#define AUDIOMIX_AUDIO_AXI_LIMIT_ENABLE_MASK     (0x1U)
#define AUDIOMIX_AUDIO_AXI_LIMIT_ENABLE_SHIFT    (0U)
/*! enable - AXI Limit enable */
#define AUDIOMIX_AUDIO_AXI_LIMIT_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIO_AXI_LIMIT_ENABLE_SHIFT)) & AUDIOMIX_AUDIO_AXI_LIMIT_ENABLE_MASK)

#define AUDIOMIX_AUDIO_AXI_LIMIT_BEAT_LIMIT_MASK (0xFFFF0U)
#define AUDIOMIX_AUDIO_AXI_LIMIT_BEAT_LIMIT_SHIFT (4U)
/*! BEAT_LIMIT - Beat Limit. Limit the burst beat number from AudioDSP. */
#define AUDIOMIX_AUDIO_AXI_LIMIT_BEAT_LIMIT(x)   (((uint32_t)(((uint32_t)(x)) << AUDIOMIX_AUDIO_AXI_LIMIT_BEAT_LIMIT_SHIFT)) & AUDIOMIX_AUDIO_AXI_LIMIT_BEAT_LIMIT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AUDIOMIX_Register_Masks */


/*!
 * @}
 */ /* end of group AUDIOMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_AUDIOMIX_H_ */

