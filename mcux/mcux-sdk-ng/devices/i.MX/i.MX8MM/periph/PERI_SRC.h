/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SRC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC
 *
 * CMSIS Peripheral Access Layer for SRC
 */

#if !defined(PERI_SRC_H_)
#define PERI_SRC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- SRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_Peripheral_Access_Layer SRC Peripheral Access Layer
 * @{
 */

/** SRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCR;                               /**< SRC Reset Control Register, offset: 0x0 */
  __IO uint32_t A53RCR0;                           /**< A53 Reset Control Register, offset: 0x4 */
  __IO uint32_t A53RCR1;                           /**< A53 Reset Control Register, offset: 0x8 */
  __IO uint32_t M4RCR;                             /**< M4 Reset Control Register, offset: 0xC */
       uint8_t RESERVED_0[16];
  __IO uint32_t USBOPHY1_RCR;                      /**< USB OTG PHY1 Reset Control Register, offset: 0x20 */
  __IO uint32_t USBOPHY2_RCR;                      /**< USB OTG PHY2 Reset Control Register, offset: 0x24 */
  __IO uint32_t MIPIPHY_RCR;                       /**< MIPI PHY Reset Control Register, offset: 0x28 */
  __IO uint32_t PCIEPHY_RCR;                       /**< PCIE PHY Reset Control Register, offset: 0x2C */
       uint8_t RESERVED_1[4];
  __IO uint32_t DISP_RCR;                          /**< DISPLAY Reset Control Register, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t GPU_RCR;                           /**< GPU Reset Control Register, offset: 0x40 */
  __IO uint32_t VPU_RCR;                           /**< VPU Reset Control Register, offset: 0x44 */
       uint8_t RESERVED_3[16];
  __I  uint32_t SBMR1;                             /**< SRC Boot Mode Register 1, offset: 0x58 */
  __IO uint32_t SRSR;                              /**< SRC Reset Status Register, offset: 0x5C */
       uint8_t RESERVED_4[8];
  __IO uint32_t SISR;                              /**< SRC Interrupt Status Register, offset: 0x68 */
  __IO uint32_t SIMR;                              /**< SRC Interrupt Mask Register, offset: 0x6C */
  __I  uint32_t SBMR2;                             /**< SRC Boot Mode Register 2, offset: 0x70 */
  __IO uint32_t GPR1;                              /**< SRC General Purpose Register 1, offset: 0x74 */
  __IO uint32_t GPR2;                              /**< SRC General Purpose Register 2, offset: 0x78 */
  __IO uint32_t GPR3;                              /**< SRC General Purpose Register 3, offset: 0x7C */
  __IO uint32_t GPR4;                              /**< SRC General Purpose Register 4, offset: 0x80 */
  __IO uint32_t GPR5;                              /**< SRC General Purpose Register 5, offset: 0x84 */
  __IO uint32_t GPR6;                              /**< SRC General Purpose Register 6, offset: 0x88 */
  __IO uint32_t GPR7;                              /**< SRC General Purpose Register 7, offset: 0x8C */
  __IO uint32_t GPR8;                              /**< SRC General Purpose Register 8, offset: 0x90 */
  __IO uint32_t GPR9;                              /**< SRC General Purpose Register 9, offset: 0x94 */
  __IO uint32_t GPR10;                             /**< SRC General Purpose Register 10, offset: 0x98 */
       uint8_t RESERVED_5[3940];
  __IO uint32_t DDRC_RCR;                          /**< SRC DDR Controller Reset Control Register, offset: 0x1000 */
} SRC_Type;

/* ----------------------------------------------------------------------------
   -- SRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_Register_Masks SRC Register Masks
 * @{
 */

/*! @name SCR - SRC Reset Control Register */
/*! @{ */

#define SRC_SCR_MASK_TEMPSENSE_RESET_MASK        (0xF0U)
#define SRC_SCR_MASK_TEMPSENSE_RESET_SHIFT       (4U)
/*! MASK_TEMPSENSE_RESET
 *  0b0101..tempsense_reset is masked
 *  0b1010..tempsense_reset is not masked
 */
#define SRC_SCR_MASK_TEMPSENSE_RESET(x)          (((uint32_t)(((uint32_t)(x)) << SRC_SCR_MASK_TEMPSENSE_RESET_SHIFT)) & SRC_SCR_MASK_TEMPSENSE_RESET_MASK)

#define SRC_SCR_DOMAIN0_MASK                     (0x1000000U)
#define SRC_SCR_DOMAIN0_SHIFT                    (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_SCR_DOMAIN0(x)                       (((uint32_t)(((uint32_t)(x)) << SRC_SCR_DOMAIN0_SHIFT)) & SRC_SCR_DOMAIN0_MASK)

#define SRC_SCR_DOMAIN1_MASK                     (0x2000000U)
#define SRC_SCR_DOMAIN1_SHIFT                    (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_SCR_DOMAIN1(x)                       (((uint32_t)(((uint32_t)(x)) << SRC_SCR_DOMAIN1_SHIFT)) & SRC_SCR_DOMAIN1_MASK)

#define SRC_SCR_DOMAIN2_MASK                     (0x4000000U)
#define SRC_SCR_DOMAIN2_SHIFT                    (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_SCR_DOMAIN2(x)                       (((uint32_t)(((uint32_t)(x)) << SRC_SCR_DOMAIN2_SHIFT)) & SRC_SCR_DOMAIN2_MASK)

#define SRC_SCR_DOMAIN3_MASK                     (0x8000000U)
#define SRC_SCR_DOMAIN3_SHIFT                    (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_SCR_DOMAIN3(x)                       (((uint32_t)(((uint32_t)(x)) << SRC_SCR_DOMAIN3_SHIFT)) & SRC_SCR_DOMAIN3_MASK)

#define SRC_SCR_LOCK_MASK                        (0x40000000U)
#define SRC_SCR_LOCK_SHIFT                       (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_SCR_LOCK(x)                          (((uint32_t)(((uint32_t)(x)) << SRC_SCR_LOCK_SHIFT)) & SRC_SCR_LOCK_MASK)

#define SRC_SCR_DOM_EN_MASK                      (0x80000000U)
#define SRC_SCR_DOM_EN_SHIFT                     (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_SCR_DOM_EN(x)                        (((uint32_t)(((uint32_t)(x)) << SRC_SCR_DOM_EN_SHIFT)) & SRC_SCR_DOM_EN_MASK)
/*! @} */

/*! @name A53RCR0 - A53 Reset Control Register */
/*! @{ */

#define SRC_A53RCR0_A53_CORE_POR_RESET0_MASK     (0x1U)
#define SRC_A53RCR0_A53_CORE_POR_RESET0_SHIFT    (0U)
/*! A53_CORE_POR_RESET0
 *  0b0..do not assert core0 reset
 *  0b1..assert core0 reset
 */
#define SRC_A53RCR0_A53_CORE_POR_RESET0(x)       (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_POR_RESET0_SHIFT)) & SRC_A53RCR0_A53_CORE_POR_RESET0_MASK)

#define SRC_A53RCR0_A53_CORE_POR_RESET1_MASK     (0x2U)
#define SRC_A53RCR0_A53_CORE_POR_RESET1_SHIFT    (1U)
/*! A53_CORE_POR_RESET1
 *  0b0..do not assert core1 reset
 *  0b1..assert core1 reset
 */
#define SRC_A53RCR0_A53_CORE_POR_RESET1(x)       (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_POR_RESET1_SHIFT)) & SRC_A53RCR0_A53_CORE_POR_RESET1_MASK)

#define SRC_A53RCR0_A53_CORE_POR_RESET2_MASK     (0x4U)
#define SRC_A53RCR0_A53_CORE_POR_RESET2_SHIFT    (2U)
/*! A53_CORE_POR_RESET2
 *  0b0..do not assert core2 reset
 *  0b1..assert core2 reset
 */
#define SRC_A53RCR0_A53_CORE_POR_RESET2(x)       (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_POR_RESET2_SHIFT)) & SRC_A53RCR0_A53_CORE_POR_RESET2_MASK)

#define SRC_A53RCR0_A53_CORE_POR_RESET3_MASK     (0x8U)
#define SRC_A53RCR0_A53_CORE_POR_RESET3_SHIFT    (3U)
/*! A53_CORE_POR_RESET3
 *  0b0..do not assert core3 reset
 *  0b1..assert core3 reset
 */
#define SRC_A53RCR0_A53_CORE_POR_RESET3(x)       (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_POR_RESET3_SHIFT)) & SRC_A53RCR0_A53_CORE_POR_RESET3_MASK)

#define SRC_A53RCR0_A53_CORE_RESET0_MASK         (0x10U)
#define SRC_A53RCR0_A53_CORE_RESET0_SHIFT        (4U)
/*! A53_CORE_RESET0
 *  0b0..do not assert core0 reset
 *  0b1..assert core0 reset
 */
#define SRC_A53RCR0_A53_CORE_RESET0(x)           (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_RESET0_SHIFT)) & SRC_A53RCR0_A53_CORE_RESET0_MASK)

#define SRC_A53RCR0_A53_CORE_RESET1_MASK         (0x20U)
#define SRC_A53RCR0_A53_CORE_RESET1_SHIFT        (5U)
/*! A53_CORE_RESET1
 *  0b0..do not assert core1 reset
 *  0b1..assert core1 reset
 */
#define SRC_A53RCR0_A53_CORE_RESET1(x)           (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_RESET1_SHIFT)) & SRC_A53RCR0_A53_CORE_RESET1_MASK)

#define SRC_A53RCR0_A53_CORE_RESET2_MASK         (0x40U)
#define SRC_A53RCR0_A53_CORE_RESET2_SHIFT        (6U)
/*! A53_CORE_RESET2
 *  0b0..do not assert core2 reset
 *  0b1..assert core2 reset
 */
#define SRC_A53RCR0_A53_CORE_RESET2(x)           (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_RESET2_SHIFT)) & SRC_A53RCR0_A53_CORE_RESET2_MASK)

#define SRC_A53RCR0_A53_CORE_RESET3_MASK         (0x80U)
#define SRC_A53RCR0_A53_CORE_RESET3_SHIFT        (7U)
/*! A53_CORE_RESET3
 *  0b0..do not assert core3 reset
 *  0b1..assert core3 reset
 */
#define SRC_A53RCR0_A53_CORE_RESET3(x)           (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_CORE_RESET3_SHIFT)) & SRC_A53RCR0_A53_CORE_RESET3_MASK)

#define SRC_A53RCR0_A53_DBG_RESET0_MASK          (0x100U)
#define SRC_A53RCR0_A53_DBG_RESET0_SHIFT         (8U)
/*! A53_DBG_RESET0
 *  0b0..do not assert core0 debug reset
 *  0b1..assert core0 debug reset
 */
#define SRC_A53RCR0_A53_DBG_RESET0(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_DBG_RESET0_SHIFT)) & SRC_A53RCR0_A53_DBG_RESET0_MASK)

#define SRC_A53RCR0_A53_DBG_RESET1_MASK          (0x200U)
#define SRC_A53RCR0_A53_DBG_RESET1_SHIFT         (9U)
/*! A53_DBG_RESET1
 *  0b0..do not assert core1 debug reset
 *  0b1..assert core1 debug reset
 */
#define SRC_A53RCR0_A53_DBG_RESET1(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_DBG_RESET1_SHIFT)) & SRC_A53RCR0_A53_DBG_RESET1_MASK)

#define SRC_A53RCR0_A53_DBG_RESET2_MASK          (0x400U)
#define SRC_A53RCR0_A53_DBG_RESET2_SHIFT         (10U)
/*! A53_DBG_RESET2
 *  0b0..do not assert core2 debug reset
 *  0b1..assert core2 debug reset
 */
#define SRC_A53RCR0_A53_DBG_RESET2(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_DBG_RESET2_SHIFT)) & SRC_A53RCR0_A53_DBG_RESET2_MASK)

#define SRC_A53RCR0_A53_DBG_RESET3_MASK          (0x800U)
#define SRC_A53RCR0_A53_DBG_RESET3_SHIFT         (11U)
/*! A53_DBG_RESET3
 *  0b0..do not assert core3 debug reset
 *  0b1..assert core3 debug reset
 */
#define SRC_A53RCR0_A53_DBG_RESET3(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_DBG_RESET3_SHIFT)) & SRC_A53RCR0_A53_DBG_RESET3_MASK)

#define SRC_A53RCR0_A53_ETM_RESET0_MASK          (0x1000U)
#define SRC_A53RCR0_A53_ETM_RESET0_SHIFT         (12U)
/*! A53_ETM_RESET0
 *  0b0..do not assert core0 ETM reset
 *  0b1..assert core0 ETM reset
 */
#define SRC_A53RCR0_A53_ETM_RESET0(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_ETM_RESET0_SHIFT)) & SRC_A53RCR0_A53_ETM_RESET0_MASK)

#define SRC_A53RCR0_A53_ETM_RESET1_MASK          (0x2000U)
#define SRC_A53RCR0_A53_ETM_RESET1_SHIFT         (13U)
/*! A53_ETM_RESET1
 *  0b0..do not assert core1 ETM reset
 *  0b1..assert core1 ETM reset
 */
#define SRC_A53RCR0_A53_ETM_RESET1(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_ETM_RESET1_SHIFT)) & SRC_A53RCR0_A53_ETM_RESET1_MASK)

#define SRC_A53RCR0_A53_ETM_RESET2_MASK          (0x4000U)
#define SRC_A53RCR0_A53_ETM_RESET2_SHIFT         (14U)
/*! A53_ETM_RESET2
 *  0b0..do not assert core2 ETM reset
 *  0b1..assert core2 ETM reset
 */
#define SRC_A53RCR0_A53_ETM_RESET2(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_ETM_RESET2_SHIFT)) & SRC_A53RCR0_A53_ETM_RESET2_MASK)

#define SRC_A53RCR0_A53_ETM_RESET3_MASK          (0x8000U)
#define SRC_A53RCR0_A53_ETM_RESET3_SHIFT         (15U)
/*! A53_ETM_RESET3
 *  0b0..do not assert core3 ETM reset
 *  0b1..assert core3 ETM reset
 */
#define SRC_A53RCR0_A53_ETM_RESET3(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_ETM_RESET3_SHIFT)) & SRC_A53RCR0_A53_ETM_RESET3_MASK)

#define SRC_A53RCR0_MASK_WDOG1_RST_MASK          (0xF0000U)
#define SRC_A53RCR0_MASK_WDOG1_RST_SHIFT         (16U)
/*! MASK_WDOG1_RST
 *  0b0101..wdog1_rst_b is masked
 *  0b1010..wdog1_rst_b is not masked
 */
#define SRC_A53RCR0_MASK_WDOG1_RST(x)            (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_MASK_WDOG1_RST_SHIFT)) & SRC_A53RCR0_MASK_WDOG1_RST_MASK)

#define SRC_A53RCR0_A53_SOC_DBG_RESET_MASK       (0x100000U)
#define SRC_A53RCR0_A53_SOC_DBG_RESET_SHIFT      (20U)
/*! A53_SOC_DBG_RESET
 *  0b0..do not assert system level debug reset
 *  0b1..assert system level debug reset
 */
#define SRC_A53RCR0_A53_SOC_DBG_RESET(x)         (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_SOC_DBG_RESET_SHIFT)) & SRC_A53RCR0_A53_SOC_DBG_RESET_MASK)

#define SRC_A53RCR0_A53_L2RESET_MASK             (0x200000U)
#define SRC_A53RCR0_A53_L2RESET_SHIFT            (21U)
/*! A53_L2RESET
 *  0b0..do not assert SCU reset
 *  0b1..assert SCU reset
 */
#define SRC_A53RCR0_A53_L2RESET(x)               (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_A53_L2RESET_SHIFT)) & SRC_A53RCR0_A53_L2RESET_MASK)

#define SRC_A53RCR0_DOMAIN0_MASK                 (0x1000000U)
#define SRC_A53RCR0_DOMAIN0_SHIFT                (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_A53RCR0_DOMAIN0(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_DOMAIN0_SHIFT)) & SRC_A53RCR0_DOMAIN0_MASK)

#define SRC_A53RCR0_DOMAIN1_MASK                 (0x2000000U)
#define SRC_A53RCR0_DOMAIN1_SHIFT                (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_A53RCR0_DOMAIN1(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_DOMAIN1_SHIFT)) & SRC_A53RCR0_DOMAIN1_MASK)

#define SRC_A53RCR0_DOMAIN2_MASK                 (0x4000000U)
#define SRC_A53RCR0_DOMAIN2_SHIFT                (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_A53RCR0_DOMAIN2(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_DOMAIN2_SHIFT)) & SRC_A53RCR0_DOMAIN2_MASK)

#define SRC_A53RCR0_DOMAIN3_MASK                 (0x8000000U)
#define SRC_A53RCR0_DOMAIN3_SHIFT                (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_A53RCR0_DOMAIN3(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_DOMAIN3_SHIFT)) & SRC_A53RCR0_DOMAIN3_MASK)

#define SRC_A53RCR0_LOCK_MASK                    (0x40000000U)
#define SRC_A53RCR0_LOCK_SHIFT                   (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_A53RCR0_LOCK(x)                      (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_LOCK_SHIFT)) & SRC_A53RCR0_LOCK_MASK)

#define SRC_A53RCR0_DOM_EN_MASK                  (0x80000000U)
#define SRC_A53RCR0_DOM_EN_SHIFT                 (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_A53RCR0_DOM_EN(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR0_DOM_EN_SHIFT)) & SRC_A53RCR0_DOM_EN_MASK)
/*! @} */

/*! @name A53RCR1 - A53 Reset Control Register */
/*! @{ */

#define SRC_A53RCR1_A53_CORE0_ENABLE_MASK        (0x1U)
#define SRC_A53RCR1_A53_CORE0_ENABLE_SHIFT       (0U)
#define SRC_A53RCR1_A53_CORE0_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_A53_CORE0_ENABLE_SHIFT)) & SRC_A53RCR1_A53_CORE0_ENABLE_MASK)

#define SRC_A53RCR1_A53_CORE1_ENABLE_MASK        (0x2U)
#define SRC_A53RCR1_A53_CORE1_ENABLE_SHIFT       (1U)
/*! A53_CORE1_ENABLE
 *  0b0..core1 is disabled
 *  0b1..core1 is enabled
 */
#define SRC_A53RCR1_A53_CORE1_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_A53_CORE1_ENABLE_SHIFT)) & SRC_A53RCR1_A53_CORE1_ENABLE_MASK)

#define SRC_A53RCR1_A53_CORE2_ENABLE_MASK        (0x4U)
#define SRC_A53RCR1_A53_CORE2_ENABLE_SHIFT       (2U)
/*! A53_CORE2_ENABLE
 *  0b0..core2 is disabled
 *  0b1..core2 is enabled
 */
#define SRC_A53RCR1_A53_CORE2_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_A53_CORE2_ENABLE_SHIFT)) & SRC_A53RCR1_A53_CORE2_ENABLE_MASK)

#define SRC_A53RCR1_A53_CORE3_ENABLE_MASK        (0x8U)
#define SRC_A53RCR1_A53_CORE3_ENABLE_SHIFT       (3U)
/*! A53_CORE3_ENABLE
 *  0b0..core3 is disabled
 *  0b1..core3 is enabled
 */
#define SRC_A53RCR1_A53_CORE3_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_A53_CORE3_ENABLE_SHIFT)) & SRC_A53RCR1_A53_CORE3_ENABLE_MASK)

#define SRC_A53RCR1_A53_RST_SLOW_MASK            (0x70U)
#define SRC_A53RCR1_A53_RST_SLOW_SHIFT           (4U)
/*! A53_RST_SLOW - A53_RST_SLOW */
#define SRC_A53RCR1_A53_RST_SLOW(x)              (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_A53_RST_SLOW_SHIFT)) & SRC_A53RCR1_A53_RST_SLOW_MASK)

#define SRC_A53RCR1_DOMAIN0_MASK                 (0x1000000U)
#define SRC_A53RCR1_DOMAIN0_SHIFT                (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_A53RCR1_DOMAIN0(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_DOMAIN0_SHIFT)) & SRC_A53RCR1_DOMAIN0_MASK)

#define SRC_A53RCR1_DOMAIN1_MASK                 (0x2000000U)
#define SRC_A53RCR1_DOMAIN1_SHIFT                (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_A53RCR1_DOMAIN1(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_DOMAIN1_SHIFT)) & SRC_A53RCR1_DOMAIN1_MASK)

#define SRC_A53RCR1_DOMAIN2_MASK                 (0x4000000U)
#define SRC_A53RCR1_DOMAIN2_SHIFT                (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_A53RCR1_DOMAIN2(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_DOMAIN2_SHIFT)) & SRC_A53RCR1_DOMAIN2_MASK)

#define SRC_A53RCR1_DOMAIN3_MASK                 (0x8000000U)
#define SRC_A53RCR1_DOMAIN3_SHIFT                (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_A53RCR1_DOMAIN3(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_DOMAIN3_SHIFT)) & SRC_A53RCR1_DOMAIN3_MASK)

#define SRC_A53RCR1_LOCK_MASK                    (0x40000000U)
#define SRC_A53RCR1_LOCK_SHIFT                   (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_A53RCR1_LOCK(x)                      (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_LOCK_SHIFT)) & SRC_A53RCR1_LOCK_MASK)

#define SRC_A53RCR1_DOM_EN_MASK                  (0x80000000U)
#define SRC_A53RCR1_DOM_EN_SHIFT                 (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_A53RCR1_DOM_EN(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_A53RCR1_DOM_EN_SHIFT)) & SRC_A53RCR1_DOM_EN_MASK)
/*! @} */

/*! @name M4RCR - M4 Reset Control Register */
/*! @{ */

#define SRC_M4RCR_SW_M4C_NON_SCLR_RST_MASK       (0x1U)
#define SRC_M4RCR_SW_M4C_NON_SCLR_RST_SHIFT      (0U)
/*! SW_M4C_NON_SCLR_RST
 *  0b0..do not assert M4 core reset
 *  0b1..assert M4 core reset
 */
#define SRC_M4RCR_SW_M4C_NON_SCLR_RST(x)         (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_SW_M4C_NON_SCLR_RST_SHIFT)) & SRC_M4RCR_SW_M4C_NON_SCLR_RST_MASK)

#define SRC_M4RCR_SW_M4C_RST_MASK                (0x2U)
#define SRC_M4RCR_SW_M4C_RST_SHIFT               (1U)
/*! SW_M4C_RST
 *  0b0..do not assert M4 core reset
 *  0b1..assert M4 core reset
 */
#define SRC_M4RCR_SW_M4C_RST(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_SW_M4C_RST_SHIFT)) & SRC_M4RCR_SW_M4C_RST_MASK)

#define SRC_M4RCR_SW_M4P_RST_MASK                (0x4U)
#define SRC_M4RCR_SW_M4P_RST_SHIFT               (2U)
/*! SW_M4P_RST
 *  0b0..do not assert M4 platform reset
 *  0b1..assert M4 platform reset
 */
#define SRC_M4RCR_SW_M4P_RST(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_SW_M4P_RST_SHIFT)) & SRC_M4RCR_SW_M4P_RST_MASK)

#define SRC_M4RCR_ENABLE_M4_MASK                 (0x8U)
#define SRC_M4RCR_ENABLE_M4_SHIFT                (3U)
/*! ENABLE_M4
 *  0b0..M4 is disabled
 *  0b1..M4 is enabled
 */
#define SRC_M4RCR_ENABLE_M4(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_ENABLE_M4_SHIFT)) & SRC_M4RCR_ENABLE_M4_MASK)

#define SRC_M4RCR_MASK_WDOG3_RST_MASK            (0xF0U)
#define SRC_M4RCR_MASK_WDOG3_RST_SHIFT           (4U)
/*! MASK_WDOG3_RST
 *  0b0101..wdog3_rst_b is masked
 *  0b1010..wdog3_rst_b is not masked
 */
#define SRC_M4RCR_MASK_WDOG3_RST(x)              (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_MASK_WDOG3_RST_SHIFT)) & SRC_M4RCR_MASK_WDOG3_RST_MASK)

#define SRC_M4RCR_WDOG3_RST_OPTION_M4_MASK       (0x100U)
#define SRC_M4RCR_WDOG3_RST_OPTION_M4_SHIFT      (8U)
/*! WDOG3_RST_OPTION_M4
 *  0b0..wdgo3_rst_b Reset M4 core only
 *  0b1..Reset both M4 core and platform
 */
#define SRC_M4RCR_WDOG3_RST_OPTION_M4(x)         (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_WDOG3_RST_OPTION_M4_SHIFT)) & SRC_M4RCR_WDOG3_RST_OPTION_M4_MASK)

#define SRC_M4RCR_WDOG3_RST_OPTION_MASK          (0x200U)
#define SRC_M4RCR_WDOG3_RST_OPTION_SHIFT         (9U)
/*! WDOG3_RST_OPTION
 *  0b0..Wdog3_rst_b asserts M4 reset
 *  0b1..Wdog3_rst_b asserts global reset
 */
#define SRC_M4RCR_WDOG3_RST_OPTION(x)            (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_WDOG3_RST_OPTION_SHIFT)) & SRC_M4RCR_WDOG3_RST_OPTION_MASK)

#define SRC_M4RCR_DOMAIN0_MASK                   (0x1000000U)
#define SRC_M4RCR_DOMAIN0_SHIFT                  (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_M4RCR_DOMAIN0(x)                     (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_DOMAIN0_SHIFT)) & SRC_M4RCR_DOMAIN0_MASK)

#define SRC_M4RCR_DOMAIN1_MASK                   (0x2000000U)
#define SRC_M4RCR_DOMAIN1_SHIFT                  (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_M4RCR_DOMAIN1(x)                     (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_DOMAIN1_SHIFT)) & SRC_M4RCR_DOMAIN1_MASK)

#define SRC_M4RCR_DOMAIN2_MASK                   (0x4000000U)
#define SRC_M4RCR_DOMAIN2_SHIFT                  (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_M4RCR_DOMAIN2(x)                     (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_DOMAIN2_SHIFT)) & SRC_M4RCR_DOMAIN2_MASK)

#define SRC_M4RCR_DOMAIN3_MASK                   (0x8000000U)
#define SRC_M4RCR_DOMAIN3_SHIFT                  (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_M4RCR_DOMAIN3(x)                     (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_DOMAIN3_SHIFT)) & SRC_M4RCR_DOMAIN3_MASK)

#define SRC_M4RCR_LOCK_MASK                      (0x40000000U)
#define SRC_M4RCR_LOCK_SHIFT                     (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_M4RCR_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_LOCK_SHIFT)) & SRC_M4RCR_LOCK_MASK)

#define SRC_M4RCR_DOM_EN_MASK                    (0x80000000U)
#define SRC_M4RCR_DOM_EN_SHIFT                   (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_M4RCR_DOM_EN(x)                      (((uint32_t)(((uint32_t)(x)) << SRC_M4RCR_DOM_EN_SHIFT)) & SRC_M4RCR_DOM_EN_MASK)
/*! @} */

/*! @name USBOPHY1_RCR - USB OTG PHY1 Reset Control Register */
/*! @{ */

#define SRC_USBOPHY1_RCR_OTG1_PHY_RESET_MASK     (0x1U)
#define SRC_USBOPHY1_RCR_OTG1_PHY_RESET_SHIFT    (0U)
/*! OTG1_PHY_RESET
 *  0b0..Don't reset USB OTG1 PHY
 *  0b1..Reset USB OTG1 PHY
 */
#define SRC_USBOPHY1_RCR_OTG1_PHY_RESET(x)       (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY1_RCR_OTG1_PHY_RESET_SHIFT)) & SRC_USBOPHY1_RCR_OTG1_PHY_RESET_MASK)

#define SRC_USBOPHY1_RCR_DOMAIN0_MASK            (0x1000000U)
#define SRC_USBOPHY1_RCR_DOMAIN0_SHIFT           (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_USBOPHY1_RCR_DOMAIN0(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY1_RCR_DOMAIN0_SHIFT)) & SRC_USBOPHY1_RCR_DOMAIN0_MASK)

#define SRC_USBOPHY1_RCR_DOMAIN1_MASK            (0x2000000U)
#define SRC_USBOPHY1_RCR_DOMAIN1_SHIFT           (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_USBOPHY1_RCR_DOMAIN1(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY1_RCR_DOMAIN1_SHIFT)) & SRC_USBOPHY1_RCR_DOMAIN1_MASK)

#define SRC_USBOPHY1_RCR_DOMAIN2_MASK            (0x4000000U)
#define SRC_USBOPHY1_RCR_DOMAIN2_SHIFT           (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_USBOPHY1_RCR_DOMAIN2(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY1_RCR_DOMAIN2_SHIFT)) & SRC_USBOPHY1_RCR_DOMAIN2_MASK)

#define SRC_USBOPHY1_RCR_DOMAIN3_MASK            (0x8000000U)
#define SRC_USBOPHY1_RCR_DOMAIN3_SHIFT           (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_USBOPHY1_RCR_DOMAIN3(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY1_RCR_DOMAIN3_SHIFT)) & SRC_USBOPHY1_RCR_DOMAIN3_MASK)

#define SRC_USBOPHY1_RCR_LOCK_MASK               (0x40000000U)
#define SRC_USBOPHY1_RCR_LOCK_SHIFT              (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_USBOPHY1_RCR_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY1_RCR_LOCK_SHIFT)) & SRC_USBOPHY1_RCR_LOCK_MASK)

#define SRC_USBOPHY1_RCR_DOM_EN_MASK             (0x80000000U)
#define SRC_USBOPHY1_RCR_DOM_EN_SHIFT            (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_USBOPHY1_RCR_DOM_EN(x)               (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY1_RCR_DOM_EN_SHIFT)) & SRC_USBOPHY1_RCR_DOM_EN_MASK)
/*! @} */

/*! @name USBOPHY2_RCR - USB OTG PHY2 Reset Control Register */
/*! @{ */

#define SRC_USBOPHY2_RCR_OTG2_PHY_RESET_MASK     (0x1U)
#define SRC_USBOPHY2_RCR_OTG2_PHY_RESET_SHIFT    (0U)
/*! OTG2_PHY_RESET
 *  0b0..Don't reset USB OTG2 PHY
 *  0b1..Reset USB OTG2 PHY
 */
#define SRC_USBOPHY2_RCR_OTG2_PHY_RESET(x)       (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY2_RCR_OTG2_PHY_RESET_SHIFT)) & SRC_USBOPHY2_RCR_OTG2_PHY_RESET_MASK)

#define SRC_USBOPHY2_RCR_DOMAIN0_MASK            (0x1000000U)
#define SRC_USBOPHY2_RCR_DOMAIN0_SHIFT           (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_USBOPHY2_RCR_DOMAIN0(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY2_RCR_DOMAIN0_SHIFT)) & SRC_USBOPHY2_RCR_DOMAIN0_MASK)

#define SRC_USBOPHY2_RCR_DOMAIN1_MASK            (0x2000000U)
#define SRC_USBOPHY2_RCR_DOMAIN1_SHIFT           (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_USBOPHY2_RCR_DOMAIN1(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY2_RCR_DOMAIN1_SHIFT)) & SRC_USBOPHY2_RCR_DOMAIN1_MASK)

#define SRC_USBOPHY2_RCR_DOMAIN2_MASK            (0x4000000U)
#define SRC_USBOPHY2_RCR_DOMAIN2_SHIFT           (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_USBOPHY2_RCR_DOMAIN2(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY2_RCR_DOMAIN2_SHIFT)) & SRC_USBOPHY2_RCR_DOMAIN2_MASK)

#define SRC_USBOPHY2_RCR_DOMAIN3_MASK            (0x8000000U)
#define SRC_USBOPHY2_RCR_DOMAIN3_SHIFT           (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_USBOPHY2_RCR_DOMAIN3(x)              (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY2_RCR_DOMAIN3_SHIFT)) & SRC_USBOPHY2_RCR_DOMAIN3_MASK)

#define SRC_USBOPHY2_RCR_LOCK_MASK               (0x40000000U)
#define SRC_USBOPHY2_RCR_LOCK_SHIFT              (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_USBOPHY2_RCR_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY2_RCR_LOCK_SHIFT)) & SRC_USBOPHY2_RCR_LOCK_MASK)

#define SRC_USBOPHY2_RCR_DOM_EN_MASK             (0x80000000U)
#define SRC_USBOPHY2_RCR_DOM_EN_SHIFT            (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_USBOPHY2_RCR_DOM_EN(x)               (((uint32_t)(((uint32_t)(x)) << SRC_USBOPHY2_RCR_DOM_EN_SHIFT)) & SRC_USBOPHY2_RCR_DOM_EN_MASK)
/*! @} */

/*! @name MIPIPHY_RCR - MIPI PHY Reset Control Register */
/*! @{ */

#define SRC_MIPIPHY_RCR_DOMAIN0_MASK             (0x1000000U)
#define SRC_MIPIPHY_RCR_DOMAIN0_SHIFT            (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_MIPIPHY_RCR_DOMAIN0(x)               (((uint32_t)(((uint32_t)(x)) << SRC_MIPIPHY_RCR_DOMAIN0_SHIFT)) & SRC_MIPIPHY_RCR_DOMAIN0_MASK)

#define SRC_MIPIPHY_RCR_DOMAIN1_MASK             (0x2000000U)
#define SRC_MIPIPHY_RCR_DOMAIN1_SHIFT            (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_MIPIPHY_RCR_DOMAIN1(x)               (((uint32_t)(((uint32_t)(x)) << SRC_MIPIPHY_RCR_DOMAIN1_SHIFT)) & SRC_MIPIPHY_RCR_DOMAIN1_MASK)

#define SRC_MIPIPHY_RCR_DOMAIN2_MASK             (0x4000000U)
#define SRC_MIPIPHY_RCR_DOMAIN2_SHIFT            (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_MIPIPHY_RCR_DOMAIN2(x)               (((uint32_t)(((uint32_t)(x)) << SRC_MIPIPHY_RCR_DOMAIN2_SHIFT)) & SRC_MIPIPHY_RCR_DOMAIN2_MASK)

#define SRC_MIPIPHY_RCR_DOMAIN3_MASK             (0x8000000U)
#define SRC_MIPIPHY_RCR_DOMAIN3_SHIFT            (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_MIPIPHY_RCR_DOMAIN3(x)               (((uint32_t)(((uint32_t)(x)) << SRC_MIPIPHY_RCR_DOMAIN3_SHIFT)) & SRC_MIPIPHY_RCR_DOMAIN3_MASK)

#define SRC_MIPIPHY_RCR_LOCK_MASK                (0x40000000U)
#define SRC_MIPIPHY_RCR_LOCK_SHIFT               (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_MIPIPHY_RCR_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_MIPIPHY_RCR_LOCK_SHIFT)) & SRC_MIPIPHY_RCR_LOCK_MASK)

#define SRC_MIPIPHY_RCR_DOM_EN_MASK              (0x80000000U)
#define SRC_MIPIPHY_RCR_DOM_EN_SHIFT             (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_MIPIPHY_RCR_DOM_EN(x)                (((uint32_t)(((uint32_t)(x)) << SRC_MIPIPHY_RCR_DOM_EN_SHIFT)) & SRC_MIPIPHY_RCR_DOM_EN_MASK)
/*! @} */

/*! @name PCIEPHY_RCR - PCIE PHY Reset Control Register */
/*! @{ */

#define SRC_PCIEPHY_RCR_PCIE_PHY_POWER_ON_RESET_MASK (0x1U)
#define SRC_PCIEPHY_RCR_PCIE_PHY_POWER_ON_RESET_SHIFT (0U)
#define SRC_PCIEPHY_RCR_PCIE_PHY_POWER_ON_RESET(x) (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_PHY_POWER_ON_RESET_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_PHY_POWER_ON_RESET_MASK)

#define SRC_PCIEPHY_RCR_PCIEPHY_BTNRST_MASK      (0x4U)
#define SRC_PCIEPHY_RCR_PCIEPHY_BTNRST_SHIFT     (2U)
#define SRC_PCIEPHY_RCR_PCIEPHY_BTNRST(x)        (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIEPHY_BTNRST_SHIFT)) & SRC_PCIEPHY_RCR_PCIEPHY_BTNRST_MASK)

#define SRC_PCIEPHY_RCR_PCIEPHY_PERST_MASK       (0x8U)
#define SRC_PCIEPHY_RCR_PCIEPHY_PERST_SHIFT      (3U)
#define SRC_PCIEPHY_RCR_PCIEPHY_PERST(x)         (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIEPHY_PERST_SHIFT)) & SRC_PCIEPHY_RCR_PCIEPHY_PERST_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_CLK_REQ_MASK (0x10U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_CLK_REQ_SHIFT (4U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_CLK_REQ(x) (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_CLK_REQ_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_CLK_REQ_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_RST_MASK  (0x20U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_RST_SHIFT (5U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_RST(x)    (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_RST_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_RST_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN_MASK   (0x40U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN_SHIFT  (6U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN(x)     (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EN_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_READY_MASK (0x80U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_READY_SHIFT (7U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_READY(x)  (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_READY_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_READY_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_ENTER_MASK (0x100U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_ENTER_SHIFT (8U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_ENTER(x)  (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_ENTER_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_ENTER_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EXIT_MASK (0x200U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EXIT_SHIFT (9U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EXIT(x)   (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EXIT_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_EXIT_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_PME_MASK  (0x400U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_PME_SHIFT (10U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_PME(x)    (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_PME_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_PME_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_TURNOFF_MASK (0x800U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_TURNOFF_SHIFT (11U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_TURNOFF(x) (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_TURNOFF_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APPS_TURNOFF_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_CFG_L1_AUX_MASK (0x1000U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_CFG_L1_AUX_SHIFT (12U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_CFG_L1_AUX(x)  (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_CFG_L1_AUX_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_CFG_L1_AUX_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_SYS_INT_MASK   (0x4000U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_SYS_INT_SHIFT  (14U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_SYS_INT(x)     (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_SYS_INT_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_SYS_INT_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APP_UNLOCK_MSG_MASK (0x8000U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APP_UNLOCK_MSG_SHIFT (15U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APP_UNLOCK_MSG(x) (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APP_UNLOCK_MSG_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APP_UNLOCK_MSG_MASK)

#define SRC_PCIEPHY_RCR_PCIE_CTRL_APP_XFER_PENDING_MASK (0x10000U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APP_XFER_PENDING_SHIFT (16U)
#define SRC_PCIEPHY_RCR_PCIE_CTRL_APP_XFER_PENDING(x) (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_PCIE_CTRL_APP_XFER_PENDING_SHIFT)) & SRC_PCIEPHY_RCR_PCIE_CTRL_APP_XFER_PENDING_MASK)

#define SRC_PCIEPHY_RCR_DOMAIN0_MASK             (0x1000000U)
#define SRC_PCIEPHY_RCR_DOMAIN0_SHIFT            (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_PCIEPHY_RCR_DOMAIN0(x)               (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_DOMAIN0_SHIFT)) & SRC_PCIEPHY_RCR_DOMAIN0_MASK)

#define SRC_PCIEPHY_RCR_DOMAIN1_MASK             (0x2000000U)
#define SRC_PCIEPHY_RCR_DOMAIN1_SHIFT            (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_PCIEPHY_RCR_DOMAIN1(x)               (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_DOMAIN1_SHIFT)) & SRC_PCIEPHY_RCR_DOMAIN1_MASK)

#define SRC_PCIEPHY_RCR_DOMAIN2_MASK             (0x4000000U)
#define SRC_PCIEPHY_RCR_DOMAIN2_SHIFT            (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_PCIEPHY_RCR_DOMAIN2(x)               (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_DOMAIN2_SHIFT)) & SRC_PCIEPHY_RCR_DOMAIN2_MASK)

#define SRC_PCIEPHY_RCR_DOMAIN3_MASK             (0x8000000U)
#define SRC_PCIEPHY_RCR_DOMAIN3_SHIFT            (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_PCIEPHY_RCR_DOMAIN3(x)               (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_DOMAIN3_SHIFT)) & SRC_PCIEPHY_RCR_DOMAIN3_MASK)

#define SRC_PCIEPHY_RCR_LOCK_MASK                (0x40000000U)
#define SRC_PCIEPHY_RCR_LOCK_SHIFT               (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_PCIEPHY_RCR_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_LOCK_SHIFT)) & SRC_PCIEPHY_RCR_LOCK_MASK)

#define SRC_PCIEPHY_RCR_DOM_EN_MASK              (0x80000000U)
#define SRC_PCIEPHY_RCR_DOM_EN_SHIFT             (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_PCIEPHY_RCR_DOM_EN(x)                (((uint32_t)(((uint32_t)(x)) << SRC_PCIEPHY_RCR_DOM_EN_SHIFT)) & SRC_PCIEPHY_RCR_DOM_EN_MASK)
/*! @} */

/*! @name DISP_RCR - DISPLAY Reset Control Register */
/*! @{ */

#define SRC_DISP_RCR_DISP_RESET_MASK             (0x1U)
#define SRC_DISP_RCR_DISP_RESET_SHIFT            (0U)
/*! DISP_RESET
 *  0b0..Don't reset dispmix
 *  0b1..Reset dispmix
 */
#define SRC_DISP_RCR_DISP_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SRC_DISP_RCR_DISP_RESET_SHIFT)) & SRC_DISP_RCR_DISP_RESET_MASK)

#define SRC_DISP_RCR_DOMAIN0_MASK                (0x1000000U)
#define SRC_DISP_RCR_DOMAIN0_SHIFT               (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_DISP_RCR_DOMAIN0(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DISP_RCR_DOMAIN0_SHIFT)) & SRC_DISP_RCR_DOMAIN0_MASK)

#define SRC_DISP_RCR_DOMAIN1_MASK                (0x2000000U)
#define SRC_DISP_RCR_DOMAIN1_SHIFT               (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_DISP_RCR_DOMAIN1(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DISP_RCR_DOMAIN1_SHIFT)) & SRC_DISP_RCR_DOMAIN1_MASK)

#define SRC_DISP_RCR_DOMAIN2_MASK                (0x4000000U)
#define SRC_DISP_RCR_DOMAIN2_SHIFT               (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_DISP_RCR_DOMAIN2(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DISP_RCR_DOMAIN2_SHIFT)) & SRC_DISP_RCR_DOMAIN2_MASK)

#define SRC_DISP_RCR_DOMAIN3_MASK                (0x8000000U)
#define SRC_DISP_RCR_DOMAIN3_SHIFT               (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_DISP_RCR_DOMAIN3(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DISP_RCR_DOMAIN3_SHIFT)) & SRC_DISP_RCR_DOMAIN3_MASK)

#define SRC_DISP_RCR_LOCK_MASK                   (0x40000000U)
#define SRC_DISP_RCR_LOCK_SHIFT                  (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_DISP_RCR_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << SRC_DISP_RCR_LOCK_SHIFT)) & SRC_DISP_RCR_LOCK_MASK)

#define SRC_DISP_RCR_DOM_EN_MASK                 (0x80000000U)
#define SRC_DISP_RCR_DOM_EN_SHIFT                (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_DISP_RCR_DOM_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_DISP_RCR_DOM_EN_SHIFT)) & SRC_DISP_RCR_DOM_EN_MASK)
/*! @} */

/*! @name GPU_RCR - GPU Reset Control Register */
/*! @{ */

#define SRC_GPU_RCR_GPU_RESET_MASK               (0x1U)
#define SRC_GPU_RCR_GPU_RESET_SHIFT              (0U)
#define SRC_GPU_RCR_GPU_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_GPU_RCR_GPU_RESET_SHIFT)) & SRC_GPU_RCR_GPU_RESET_MASK)

#define SRC_GPU_RCR_DOMAIN0_MASK                 (0x1000000U)
#define SRC_GPU_RCR_DOMAIN0_SHIFT                (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_GPU_RCR_DOMAIN0(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_GPU_RCR_DOMAIN0_SHIFT)) & SRC_GPU_RCR_DOMAIN0_MASK)

#define SRC_GPU_RCR_DOMAIN1_MASK                 (0x2000000U)
#define SRC_GPU_RCR_DOMAIN1_SHIFT                (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_GPU_RCR_DOMAIN1(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_GPU_RCR_DOMAIN1_SHIFT)) & SRC_GPU_RCR_DOMAIN1_MASK)

#define SRC_GPU_RCR_DOMAIN2_MASK                 (0x4000000U)
#define SRC_GPU_RCR_DOMAIN2_SHIFT                (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_GPU_RCR_DOMAIN2(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_GPU_RCR_DOMAIN2_SHIFT)) & SRC_GPU_RCR_DOMAIN2_MASK)

#define SRC_GPU_RCR_DOMAIN3_MASK                 (0x8000000U)
#define SRC_GPU_RCR_DOMAIN3_SHIFT                (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_GPU_RCR_DOMAIN3(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_GPU_RCR_DOMAIN3_SHIFT)) & SRC_GPU_RCR_DOMAIN3_MASK)

#define SRC_GPU_RCR_LOCK_MASK                    (0x40000000U)
#define SRC_GPU_RCR_LOCK_SHIFT                   (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_GPU_RCR_LOCK(x)                      (((uint32_t)(((uint32_t)(x)) << SRC_GPU_RCR_LOCK_SHIFT)) & SRC_GPU_RCR_LOCK_MASK)

#define SRC_GPU_RCR_DOM_EN_MASK                  (0x80000000U)
#define SRC_GPU_RCR_DOM_EN_SHIFT                 (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_GPU_RCR_DOM_EN(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_GPU_RCR_DOM_EN_SHIFT)) & SRC_GPU_RCR_DOM_EN_MASK)
/*! @} */

/*! @name VPU_RCR - VPU Reset Control Register */
/*! @{ */

#define SRC_VPU_RCR_VPU_RESET_MASK               (0x1U)
#define SRC_VPU_RCR_VPU_RESET_SHIFT              (0U)
#define SRC_VPU_RCR_VPU_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_VPU_RCR_VPU_RESET_SHIFT)) & SRC_VPU_RCR_VPU_RESET_MASK)

#define SRC_VPU_RCR_DOMAIN0_MASK                 (0x1000000U)
#define SRC_VPU_RCR_DOMAIN0_SHIFT                (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain3 can write to this register
 */
#define SRC_VPU_RCR_DOMAIN0(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_VPU_RCR_DOMAIN0_SHIFT)) & SRC_VPU_RCR_DOMAIN0_MASK)

#define SRC_VPU_RCR_DOMAIN1_MASK                 (0x2000000U)
#define SRC_VPU_RCR_DOMAIN1_SHIFT                (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_VPU_RCR_DOMAIN1(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_VPU_RCR_DOMAIN1_SHIFT)) & SRC_VPU_RCR_DOMAIN1_MASK)

#define SRC_VPU_RCR_DOMAIN2_MASK                 (0x4000000U)
#define SRC_VPU_RCR_DOMAIN2_SHIFT                (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_VPU_RCR_DOMAIN2(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_VPU_RCR_DOMAIN2_SHIFT)) & SRC_VPU_RCR_DOMAIN2_MASK)

#define SRC_VPU_RCR_DOMAIN3_MASK                 (0x8000000U)
#define SRC_VPU_RCR_DOMAIN3_SHIFT                (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_VPU_RCR_DOMAIN3(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_VPU_RCR_DOMAIN3_SHIFT)) & SRC_VPU_RCR_DOMAIN3_MASK)

#define SRC_VPU_RCR_LOCK_MASK                    (0x40000000U)
#define SRC_VPU_RCR_LOCK_SHIFT                   (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_VPU_RCR_LOCK(x)                      (((uint32_t)(((uint32_t)(x)) << SRC_VPU_RCR_LOCK_SHIFT)) & SRC_VPU_RCR_LOCK_MASK)

#define SRC_VPU_RCR_DOM_EN_MASK                  (0x80000000U)
#define SRC_VPU_RCR_DOM_EN_SHIFT                 (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_VPU_RCR_DOM_EN(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_VPU_RCR_DOM_EN_SHIFT)) & SRC_VPU_RCR_DOM_EN_MASK)
/*! @} */

/*! @name SBMR1 - SRC Boot Mode Register 1 */
/*! @{ */

#define SRC_SBMR1_BOOT_CFG_MASK                  (0xFFFFFU)
#define SRC_SBMR1_BOOT_CFG_SHIFT                 (0U)
#define SRC_SBMR1_BOOT_CFG(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_SBMR1_BOOT_CFG_SHIFT)) & SRC_SBMR1_BOOT_CFG_MASK)
/*! @} */

/*! @name SRSR - SRC Reset Status Register */
/*! @{ */

#define SRC_SRSR_ipp_reset_b_MASK                (0x1U)
#define SRC_SRSR_ipp_reset_b_SHIFT               (0U)
/*! ipp_reset_b
 *  0b0..Reset is not a result of ipp_reset_b pin.
 *  0b1..Reset is a result of ipp_reset_b pin.
 */
#define SRC_SRSR_ipp_reset_b(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_ipp_reset_b_SHIFT)) & SRC_SRSR_ipp_reset_b_MASK)

#define SRC_SRSR_csu_reset_b_MASK                (0x4U)
#define SRC_SRSR_csu_reset_b_SHIFT               (2U)
/*! csu_reset_b
 *  0b0..Reset is not a result of the csu_reset_b event.
 *  0b1..Reset is a result of the csu_reset_b event.
 */
#define SRC_SRSR_csu_reset_b(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_csu_reset_b_SHIFT)) & SRC_SRSR_csu_reset_b_MASK)

#define SRC_SRSR_ipp_user_reset_b_MASK           (0x8U)
#define SRC_SRSR_ipp_user_reset_b_SHIFT          (3U)
/*! ipp_user_reset_b
 *  0b0..Reset is not a result of the ipp_user_reset_b qualified as COLD reset event.
 *  0b1..Reset is a result of the ipp_user_reset_b qualified as COLD reset event.
 */
#define SRC_SRSR_ipp_user_reset_b(x)             (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_ipp_user_reset_b_SHIFT)) & SRC_SRSR_ipp_user_reset_b_MASK)

#define SRC_SRSR_wdog1_rst_b_MASK                (0x10U)
#define SRC_SRSR_wdog1_rst_b_SHIFT               (4U)
/*! wdog1_rst_b
 *  0b0..Reset is not a result of the watchdog1 time-out event.
 *  0b1..Reset is a result of the watchdog1 time-out event.
 */
#define SRC_SRSR_wdog1_rst_b(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_wdog1_rst_b_SHIFT)) & SRC_SRSR_wdog1_rst_b_MASK)

#define SRC_SRSR_jtag_rst_b_MASK                 (0x20U)
#define SRC_SRSR_jtag_rst_b_SHIFT                (5U)
/*! jtag_rst_b
 *  0b0..Reset is not a result of HIGH-Z reset from JTAG.
 *  0b1..Reset is a result of HIGH-Z reset from JTAG.
 */
#define SRC_SRSR_jtag_rst_b(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_jtag_rst_b_SHIFT)) & SRC_SRSR_jtag_rst_b_MASK)

#define SRC_SRSR_jtag_sw_rst_MASK                (0x40U)
#define SRC_SRSR_jtag_sw_rst_SHIFT               (6U)
/*! jtag_sw_rst
 *  0b0..Reset is not a result of software reset from JTAG.
 *  0b1..Reset is a result of software reset from JTAG.
 */
#define SRC_SRSR_jtag_sw_rst(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_jtag_sw_rst_SHIFT)) & SRC_SRSR_jtag_sw_rst_MASK)

#define SRC_SRSR_wdog3_rst_b_MASK                (0x80U)
#define SRC_SRSR_wdog3_rst_b_SHIFT               (7U)
/*! wdog3_rst_b
 *  0b0..Reset is not a result of the watchdog3 time-out event.
 *  0b1..Reset is a result of the watchdog3 time-out event.
 */
#define SRC_SRSR_wdog3_rst_b(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_wdog3_rst_b_SHIFT)) & SRC_SRSR_wdog3_rst_b_MASK)

#define SRC_SRSR_wdog2_rst_b_MASK                (0x100U)
#define SRC_SRSR_wdog2_rst_b_SHIFT               (8U)
/*! wdog2_rst_b
 *  0b0..Reset is not a result of the watchdog4 time-out event.
 *  0b1..Reset is a result of the watchdog4 time-out event.
 */
#define SRC_SRSR_wdog2_rst_b(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_wdog2_rst_b_SHIFT)) & SRC_SRSR_wdog2_rst_b_MASK)

#define SRC_SRSR_tempsense_rst_b_MASK            (0x200U)
#define SRC_SRSR_tempsense_rst_b_SHIFT           (9U)
/*! tempsense_rst_b
 *  0b0..Reset is not a result of software reset from Temperature Sensor.
 *  0b1..Reset is a result of software reset from Temperature Sensor.
 */
#define SRC_SRSR_tempsense_rst_b(x)              (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_tempsense_rst_b_SHIFT)) & SRC_SRSR_tempsense_rst_b_MASK)
/*! @} */

/*! @name SISR - SRC Interrupt Status Register */
/*! @{ */

#define SRC_SISR_OTGPHY1_PASSED_RESET_MASK       (0x4U)
#define SRC_SISR_OTGPHY1_PASSED_RESET_SHIFT      (2U)
/*! OTGPHY1_PASSED_RESET
 *  0b0..Interrupt generated not due to OTG PHY1 passed reset
 *  0b1..Interrupt generated due to OTG PHY1 passed reset
 */
#define SRC_SISR_OTGPHY1_PASSED_RESET(x)         (((uint32_t)(((uint32_t)(x)) << SRC_SISR_OTGPHY1_PASSED_RESET_SHIFT)) & SRC_SISR_OTGPHY1_PASSED_RESET_MASK)

#define SRC_SISR_OTGPHY2_PASSED_RESET_MASK       (0x8U)
#define SRC_SISR_OTGPHY2_PASSED_RESET_SHIFT      (3U)
/*! OTGPHY2_PASSED_RESET
 *  0b0..Interrupt generated not due to OTG PHY2 passed reset
 *  0b1..Interrupt generated due to OTG PHY2 passed reset
 */
#define SRC_SISR_OTGPHY2_PASSED_RESET(x)         (((uint32_t)(((uint32_t)(x)) << SRC_SISR_OTGPHY2_PASSED_RESET_SHIFT)) & SRC_SISR_OTGPHY2_PASSED_RESET_MASK)

#define SRC_SISR_PCIE1_PHY_PASSED_RESET_MASK     (0x20U)
#define SRC_SISR_PCIE1_PHY_PASSED_RESET_SHIFT    (5U)
/*! PCIE1_PHY_PASSED_RESET
 *  0b0..Interrupt generated not due to PCIE1 PHY passed reset
 *  0b1..Interrupt generated due to PCIE1 PHY passed reset
 */
#define SRC_SISR_PCIE1_PHY_PASSED_RESET(x)       (((uint32_t)(((uint32_t)(x)) << SRC_SISR_PCIE1_PHY_PASSED_RESET_SHIFT)) & SRC_SISR_PCIE1_PHY_PASSED_RESET_MASK)

#define SRC_SISR_DISPLAY_PASSED_RESET_MASK       (0x80U)
#define SRC_SISR_DISPLAY_PASSED_RESET_SHIFT      (7U)
/*! DISPLAY_PASSED_RESET
 *  0b0..Interrupt generated not due to DISPLAY passed reset
 *  0b1..Interrupt generated due to DISPLAY passed reset
 */
#define SRC_SISR_DISPLAY_PASSED_RESET(x)         (((uint32_t)(((uint32_t)(x)) << SRC_SISR_DISPLAY_PASSED_RESET_SHIFT)) & SRC_SISR_DISPLAY_PASSED_RESET_MASK)

#define SRC_SISR_M4C_PASSED_RESET_MASK           (0x100U)
#define SRC_SISR_M4C_PASSED_RESET_SHIFT          (8U)
/*! M4C_PASSED_RESET
 *  0b0..interrupt generated not due to m4 core reset
 *  0b1..interrupt generated due to m4 core reset
 */
#define SRC_SISR_M4C_PASSED_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SRC_SISR_M4C_PASSED_RESET_SHIFT)) & SRC_SISR_M4C_PASSED_RESET_MASK)

#define SRC_SISR_M4P_PASSED_RESET_MASK           (0x200U)
#define SRC_SISR_M4P_PASSED_RESET_SHIFT          (9U)
/*! M4P_PASSED_RESET
 *  0b0..interrupt generated not due to m4 platform reset
 *  0b1..interrupt generated due to m4 platform reset
 */
#define SRC_SISR_M4P_PASSED_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SRC_SISR_M4P_PASSED_RESET_SHIFT)) & SRC_SISR_M4P_PASSED_RESET_MASK)

#define SRC_SISR_GPU_PASSED_RESET_MASK           (0x400U)
#define SRC_SISR_GPU_PASSED_RESET_SHIFT          (10U)
/*! GPU_PASSED_RESET
 *  0b0..interrupt generated not due to GPU reset
 *  0b1..interrupt generated due to GPU reset
 */
#define SRC_SISR_GPU_PASSED_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SRC_SISR_GPU_PASSED_RESET_SHIFT)) & SRC_SISR_GPU_PASSED_RESET_MASK)

#define SRC_SISR_VPU_PASSED_RESET_MASK           (0x800U)
#define SRC_SISR_VPU_PASSED_RESET_SHIFT          (11U)
/*! VPU_PASSED_RESET
 *  0b0..interrupt generated not due to VPU reset
 *  0b1..interrupt generated due to VPU reset
 */
#define SRC_SISR_VPU_PASSED_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SRC_SISR_VPU_PASSED_RESET_SHIFT)) & SRC_SISR_VPU_PASSED_RESET_MASK)
/*! @} */

/*! @name SIMR - SRC Interrupt Mask Register */
/*! @{ */

#define SRC_SIMR_MASK_OTGPHY1_PASSED_RESET_MASK  (0x4U)
#define SRC_SIMR_MASK_OTGPHY1_PASSED_RESET_SHIFT (2U)
/*! MASK_OTGPHY1_PASSED_RESET
 *  0b0..do not mask interrupt due to OTG PHY1 passed reset - interrupt will be created
 *  0b1..mask interrupt due to OTG PHY1 passed reset
 */
#define SRC_SIMR_MASK_OTGPHY1_PASSED_RESET(x)    (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_OTGPHY1_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_OTGPHY1_PASSED_RESET_MASK)

#define SRC_SIMR_MASK_OTGPHY2_PASSED_RESET_MASK  (0x8U)
#define SRC_SIMR_MASK_OTGPHY2_PASSED_RESET_SHIFT (3U)
/*! MASK_OTGPHY2_PASSED_RESET
 *  0b0..do not mask interrupt due to OTG PHY2 passed reset - interrupt will be created
 *  0b1..mask interrupt due to OTG PHY2 passed reset
 */
#define SRC_SIMR_MASK_OTGPHY2_PASSED_RESET(x)    (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_OTGPHY2_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_OTGPHY2_PASSED_RESET_MASK)

#define SRC_SIMR_MASK_PCIE_PHY_PASSED_RESET_MASK (0x20U)
#define SRC_SIMR_MASK_PCIE_PHY_PASSED_RESET_SHIFT (5U)
/*! MASK_PCIE_PHY_PASSED_RESET
 *  0b0..do not mask interrupt due to PCIE PHY passed reset - interrupt will be created
 *  0b1..mask interrupt due to PCIE PHY passed reset
 */
#define SRC_SIMR_MASK_PCIE_PHY_PASSED_RESET(x)   (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_PCIE_PHY_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_PCIE_PHY_PASSED_RESET_MASK)

#define SRC_SIMR_MASK_DISPLAY_PASSED_RESET_MASK  (0x80U)
#define SRC_SIMR_MASK_DISPLAY_PASSED_RESET_SHIFT (7U)
/*! MASK_DISPLAY_PASSED_RESET
 *  0b0..do not mask interrupt due to display passed reset - interrupt will be created
 *  0b1..mask interrupt due to display passed reset
 */
#define SRC_SIMR_MASK_DISPLAY_PASSED_RESET(x)    (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_DISPLAY_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_DISPLAY_PASSED_RESET_MASK)

#define SRC_SIMR_MASK_M4C_PASSED_RESET_MASK      (0x100U)
#define SRC_SIMR_MASK_M4C_PASSED_RESET_SHIFT     (8U)
/*! MASK_M4C_PASSED_RESET
 *  0b0..do not mask interrupt due to m4 core passed reset - interrupt will be created
 *  0b1..mask interrupt due to m4 core passed reset
 */
#define SRC_SIMR_MASK_M4C_PASSED_RESET(x)        (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_M4C_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_M4C_PASSED_RESET_MASK)

#define SRC_SIMR_MASK_M4P_PASSED_RESET_MASK      (0x200U)
#define SRC_SIMR_MASK_M4P_PASSED_RESET_SHIFT     (9U)
/*! MASK_M4P_PASSED_RESET
 *  0b0..do not mask interrupt due to m4 platform passed reset - interrupt will be created
 *  0b1..mask interrupt due to m4platform passed reset
 */
#define SRC_SIMR_MASK_M4P_PASSED_RESET(x)        (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_M4P_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_M4P_PASSED_RESET_MASK)

#define SRC_SIMR_MASK_GPU_PASSED_RESET_MASK      (0x400U)
#define SRC_SIMR_MASK_GPU_PASSED_RESET_SHIFT     (10U)
/*! MASK_GPU_PASSED_RESET
 *  0b0..do not mask interrupt due to GPU passed reset - interrupt will be created
 *  0b1..mask interrupt due to GPU passed reset
 */
#define SRC_SIMR_MASK_GPU_PASSED_RESET(x)        (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_GPU_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_GPU_PASSED_RESET_MASK)

#define SRC_SIMR_MASK_VPU_PASSED_RESET_MASK      (0x800U)
#define SRC_SIMR_MASK_VPU_PASSED_RESET_SHIFT     (11U)
/*! MASK_VPU_PASSED_RESET
 *  0b0..do not mask interrupt due to VPU passed reset - interrupt will be created
 *  0b1..mask interrupt due to VPU passed reset
 */
#define SRC_SIMR_MASK_VPU_PASSED_RESET(x)        (((uint32_t)(((uint32_t)(x)) << SRC_SIMR_MASK_VPU_PASSED_RESET_SHIFT)) & SRC_SIMR_MASK_VPU_PASSED_RESET_MASK)
/*! @} */

/*! @name SBMR2 - SRC Boot Mode Register 2 */
/*! @{ */

#define SRC_SBMR2_SEC_CONFIG_MASK                (0x3U)
#define SRC_SBMR2_SEC_CONFIG_SHIFT               (0U)
#define SRC_SBMR2_SEC_CONFIG(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_SEC_CONFIG_SHIFT)) & SRC_SBMR2_SEC_CONFIG_MASK)

#define SRC_SBMR2_DIR_BT_DIS_MASK                (0x8U)
#define SRC_SBMR2_DIR_BT_DIS_SHIFT               (3U)
#define SRC_SBMR2_DIR_BT_DIS(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_DIR_BT_DIS_SHIFT)) & SRC_SBMR2_DIR_BT_DIS_MASK)

#define SRC_SBMR2_BT_FUSE_SEL_MASK               (0x10U)
#define SRC_SBMR2_BT_FUSE_SEL_SHIFT              (4U)
#define SRC_SBMR2_BT_FUSE_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_BT_FUSE_SEL_SHIFT)) & SRC_SBMR2_BT_FUSE_SEL_MASK)

#define SRC_SBMR2_FORCE_COLD_BOOT_MASK           (0xE0U)
#define SRC_SBMR2_FORCE_COLD_BOOT_SHIFT          (5U)
#define SRC_SBMR2_FORCE_COLD_BOOT(x)             (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_FORCE_COLD_BOOT_SHIFT)) & SRC_SBMR2_FORCE_COLD_BOOT_MASK)

#define SRC_SBMR2_IPP_BOOT_MODE_MASK             (0x3000000U)
#define SRC_SBMR2_IPP_BOOT_MODE_SHIFT            (24U)
#define SRC_SBMR2_IPP_BOOT_MODE(x)               (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_IPP_BOOT_MODE_SHIFT)) & SRC_SBMR2_IPP_BOOT_MODE_MASK)
/*! @} */

/*! @name GPR1 - SRC General Purpose Register 1 */
/*! @{ */

#define SRC_GPR1_C0_START_ADDRH_MASK             (0xFFFFU)
#define SRC_GPR1_C0_START_ADDRH_SHIFT            (0U)
#define SRC_GPR1_C0_START_ADDRH(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR1_C0_START_ADDRH_SHIFT)) & SRC_GPR1_C0_START_ADDRH_MASK)
/*! @} */

/*! @name GPR2 - SRC General Purpose Register 2 */
/*! @{ */

#define SRC_GPR2_C0_START_ADDRL_MASK             (0x3FFFFFU)
#define SRC_GPR2_C0_START_ADDRL_SHIFT            (0U)
#define SRC_GPR2_C0_START_ADDRL(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR2_C0_START_ADDRL_SHIFT)) & SRC_GPR2_C0_START_ADDRL_MASK)
/*! @} */

/*! @name GPR3 - SRC General Purpose Register 3 */
/*! @{ */

#define SRC_GPR3_C1_START_ADDRH_MASK             (0xFFFFU)
#define SRC_GPR3_C1_START_ADDRH_SHIFT            (0U)
#define SRC_GPR3_C1_START_ADDRH(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR3_C1_START_ADDRH_SHIFT)) & SRC_GPR3_C1_START_ADDRH_MASK)
/*! @} */

/*! @name GPR4 - SRC General Purpose Register 4 */
/*! @{ */

#define SRC_GPR4_C1_START_ADDRL_MASK             (0x3FFFFFU)
#define SRC_GPR4_C1_START_ADDRL_SHIFT            (0U)
#define SRC_GPR4_C1_START_ADDRL(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR4_C1_START_ADDRL_SHIFT)) & SRC_GPR4_C1_START_ADDRL_MASK)
/*! @} */

/*! @name GPR5 - SRC General Purpose Register 5 */
/*! @{ */

#define SRC_GPR5_C2_START_ADDRH_MASK             (0xFFFFU)
#define SRC_GPR5_C2_START_ADDRH_SHIFT            (0U)
#define SRC_GPR5_C2_START_ADDRH(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR5_C2_START_ADDRH_SHIFT)) & SRC_GPR5_C2_START_ADDRH_MASK)
/*! @} */

/*! @name GPR6 - SRC General Purpose Register 6 */
/*! @{ */

#define SRC_GPR6_C2_START_ADDRL_MASK             (0x3FFFFFU)
#define SRC_GPR6_C2_START_ADDRL_SHIFT            (0U)
#define SRC_GPR6_C2_START_ADDRL(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR6_C2_START_ADDRL_SHIFT)) & SRC_GPR6_C2_START_ADDRL_MASK)
/*! @} */

/*! @name GPR7 - SRC General Purpose Register 7 */
/*! @{ */

#define SRC_GPR7_C3_START_ADDRH_MASK             (0xFFFFU)
#define SRC_GPR7_C3_START_ADDRH_SHIFT            (0U)
#define SRC_GPR7_C3_START_ADDRH(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR7_C3_START_ADDRH_SHIFT)) & SRC_GPR7_C3_START_ADDRH_MASK)
/*! @} */

/*! @name GPR8 - SRC General Purpose Register 8 */
/*! @{ */

#define SRC_GPR8_C3_START_ADDRL_MASK             (0x3FFFFFU)
#define SRC_GPR8_C3_START_ADDRL_SHIFT            (0U)
#define SRC_GPR8_C3_START_ADDRL(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR8_C3_START_ADDRL_SHIFT)) & SRC_GPR8_C3_START_ADDRL_MASK)
/*! @} */

/*! @name GPR9 - SRC General Purpose Register 9 */
/*! @{ */

#define SRC_GPR9_INTERNAL_USE1_MASK              (0xFFFFFFFFU)
#define SRC_GPR9_INTERNAL_USE1_SHIFT             (0U)
#define SRC_GPR9_INTERNAL_USE1(x)                (((uint32_t)(((uint32_t)(x)) << SRC_GPR9_INTERNAL_USE1_SHIFT)) & SRC_GPR9_INTERNAL_USE1_MASK)
/*! @} */

/*! @name GPR10 - SRC General Purpose Register 10 */
/*! @{ */

#define SRC_GPR10_INTERNAL_USE2_MASK             (0xFFFFFFFFU)
#define SRC_GPR10_INTERNAL_USE2_SHIFT            (0U)
#define SRC_GPR10_INTERNAL_USE2(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR10_INTERNAL_USE2_SHIFT)) & SRC_GPR10_INTERNAL_USE2_MASK)
/*! @} */

/*! @name DDRC_RCR - SRC DDR Controller Reset Control Register */
/*! @{ */

#define SRC_DDRC_RCR_DDRC1_PRST_MASK             (0x1U)
#define SRC_DDRC_RCR_DDRC1_PRST_SHIFT            (0U)
/*! DDRC1_PRST
 *  0b0..De-assert DDR Controller preset and DDR PHY reset reset
 *  0b1..Assert DDR Controller preset and DDR PHY reset
 */
#define SRC_DDRC_RCR_DDRC1_PRST(x)               (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DDRC1_PRST_SHIFT)) & SRC_DDRC_RCR_DDRC1_PRST_MASK)

#define SRC_DDRC_RCR_DDRC1_CORE_RST_MASK         (0x2U)
#define SRC_DDRC_RCR_DDRC1_CORE_RST_SHIFT        (1U)
/*! DDRC1_CORE_RST
 *  0b0..De-assert DDR controller aresetn and core_ddrc_rstn
 *  0b1..Assert DDR Controller preset and DDR PHY reset
 */
#define SRC_DDRC_RCR_DDRC1_CORE_RST(x)           (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DDRC1_CORE_RST_SHIFT)) & SRC_DDRC_RCR_DDRC1_CORE_RST_MASK)

#define SRC_DDRC_RCR_DDRC1_PHY_RESET_MASK        (0x4U)
#define SRC_DDRC_RCR_DDRC1_PHY_RESET_SHIFT       (2U)
/*! DDRC1_PHY_RESET
 *  0b0..De-assert DDR controller
 *  0b1..Assert DDR Controller
 */
#define SRC_DDRC_RCR_DDRC1_PHY_RESET(x)          (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DDRC1_PHY_RESET_SHIFT)) & SRC_DDRC_RCR_DDRC1_PHY_RESET_MASK)

#define SRC_DDRC_RCR_DDRC1_PHY_PWROKIN_MASK      (0x8U)
#define SRC_DDRC_RCR_DDRC1_PHY_PWROKIN_SHIFT     (3U)
/*! DDRC1_PHY_PWROKIN
 *  0b0..De-assert DDR controller
 *  0b1..Assert DDR Controller
 */
#define SRC_DDRC_RCR_DDRC1_PHY_PWROKIN(x)        (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DDRC1_PHY_PWROKIN_SHIFT)) & SRC_DDRC_RCR_DDRC1_PHY_PWROKIN_MASK)

#define SRC_DDRC_RCR_DDRC1_SYS_RST_MASK          (0x10U)
#define SRC_DDRC_RCR_DDRC1_SYS_RST_SHIFT         (4U)
#define SRC_DDRC_RCR_DDRC1_SYS_RST(x)            (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DDRC1_SYS_RST_SHIFT)) & SRC_DDRC_RCR_DDRC1_SYS_RST_MASK)

#define SRC_DDRC_RCR_DDRC1_PHY_WRST_MASK         (0x20U)
#define SRC_DDRC_RCR_DDRC1_PHY_WRST_SHIFT        (5U)
#define SRC_DDRC_RCR_DDRC1_PHY_WRST(x)           (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DDRC1_PHY_WRST_SHIFT)) & SRC_DDRC_RCR_DDRC1_PHY_WRST_MASK)

#define SRC_DDRC_RCR_DOMAIN0_MASK                (0x1000000U)
#define SRC_DDRC_RCR_DOMAIN0_SHIFT               (24U)
/*! DOMAIN0
 *  0b0..This register is not assigned to domain0. The master from domain0 cannot write to this register.
 *  0b1..This register is assigned to domain0. The master from domain0 can write to this register
 */
#define SRC_DDRC_RCR_DOMAIN0(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DOMAIN0_SHIFT)) & SRC_DDRC_RCR_DOMAIN0_MASK)

#define SRC_DDRC_RCR_DOMAIN1_MASK                (0x2000000U)
#define SRC_DDRC_RCR_DOMAIN1_SHIFT               (25U)
/*! DOMAIN1
 *  0b0..This register is not assigned to domain1. The master from domain1 cannot write to this register.
 *  0b1..This register is assigned to domain1. The master from domain1 can write to this register
 */
#define SRC_DDRC_RCR_DOMAIN1(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DOMAIN1_SHIFT)) & SRC_DDRC_RCR_DOMAIN1_MASK)

#define SRC_DDRC_RCR_DOMAIN2_MASK                (0x4000000U)
#define SRC_DDRC_RCR_DOMAIN2_SHIFT               (26U)
/*! DOMAIN2
 *  0b0..This register is not assigned to domain2. The master from domain2 cannot write to this register.
 *  0b1..This register is assigned to domain2. The master from domain2 can write to this register
 */
#define SRC_DDRC_RCR_DOMAIN2(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DOMAIN2_SHIFT)) & SRC_DDRC_RCR_DOMAIN2_MASK)

#define SRC_DDRC_RCR_DOMAIN3_MASK                (0x8000000U)
#define SRC_DDRC_RCR_DOMAIN3_SHIFT               (27U)
/*! DOMAIN3
 *  0b0..This register is not assigned to domain3. The master from domain3 cannot write to this register.
 *  0b1..This register is assigned to domain3. The master from domain3 can write to this register
 */
#define SRC_DDRC_RCR_DOMAIN3(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DOMAIN3_SHIFT)) & SRC_DDRC_RCR_DOMAIN3_MASK)

#define SRC_DDRC_RCR_LOCK_MASK                   (0x40000000U)
#define SRC_DDRC_RCR_LOCK_SHIFT                  (30U)
/*! LOCK
 *  0b0..[31] and [27:24] bits can be modified
 *  0b1..[31] and [27:24] bits cannot be modified
 */
#define SRC_DDRC_RCR_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_LOCK_SHIFT)) & SRC_DDRC_RCR_LOCK_MASK)

#define SRC_DDRC_RCR_DOM_EN_MASK                 (0x80000000U)
#define SRC_DDRC_RCR_DOM_EN_SHIFT                (31U)
/*! DOM_EN
 *  0b0..Disables domain control. All of this register's bits except [31:30] and [27:24] can be modified by any masters
 *  0b1..Enables domain control. All of this register's bits except [31:30] and [27:24] can only be modified by
 *       the masters from the domains specified in [27:24] area.
 */
#define SRC_DDRC_RCR_DOM_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_DDRC_RCR_DOM_EN_SHIFT)) & SRC_DDRC_RCR_DOM_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_H_ */

