/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PHY_CTRL_EX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PHY_CTRL_EX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PHY_CTRL_EX
 *
 * CMSIS Peripheral Access Layer for PHY_CTRL_EX
 */

#if !defined(PERI_PHY_CTRL_EX_H_)
#define PERI_PHY_CTRL_EX_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- PHY_CTRL_EX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHY_CTRL_EX_Peripheral_Access_Layer PHY_CTRL_EX Peripheral Access Layer
 * @{
 */

/** PHY_CTRL_EX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[276];
  __IO uint16_t GLOBAL_CTRL_EX_0;                  /**< PHY Global Extra Control, offset: 0x114 */
       uint8_t RESERVED_1[14];
  __IO uint16_t GLOBAL_CTRL_EX_4;                  /**< PHY Global Extra Control 4, offset: 0x124 */
       uint8_t RESERVED_2[6];
  __I  uint16_t GLOBAL_CTRL_EX_6;                  /**< PHY Global Extra Control 6, offset: 0x12C */
       uint8_t RESERVED_3[2];
  __IO uint16_t GLOBAL_CTRL_EX_7;                  /**< PHY Global Extra Control 7, offset: 0x130 */
       uint8_t RESERVED_4[2];
  __I  uint16_t GLOBAL_CTRL_EX_8;                  /**< PHY Global Extra Control 8, offset: 0x134 */
       uint8_t RESERVED_5[2];
  __I  uint16_t GLOBAL_CTRL_EX_9;                  /**< PHY Global Extra Control 9, offset: 0x138 */
       uint8_t RESERVED_6[2];
  __IO uint16_t GLOBAL_CTRL_EX_10;                 /**< PHY Global Extra Control 10, offset: 0x13C */
       uint8_t RESERVED_7[2];
  __IO uint16_t GLOBAL_CTRL_EX_11;                 /**< PHY Global Extra Control 11, offset: 0x140 */
       uint8_t RESERVED_8[130922];
  __IO uint16_t MPLLA_CTRL_EX_0;                   /**< MPLLA Extra Control, offset: 0x200AC */
       uint8_t RESERVED_9[2];
  __IO uint16_t MPLLA_CTRL_EX_1;                   /**< MPLLA Extra Control 1, offset: 0x200B0 */
       uint8_t RESERVED_10[2];
  __IO uint16_t MPLLA_CTRL_EX_2;                   /**< MPLLA Extra Control 2, offset: 0x200B4 */
       uint8_t RESERVED_11[6];
  __I  uint16_t MPLLA_CTRL_EX_4;                   /**< MPLLA Extra Control 4, offset: 0x200BC */
       uint8_t RESERVED_12[131054];
  __IO uint16_t MPLLB_CTRL_EX_0;                   /**< MPLLB Extra Control, offset: 0x400AC */
       uint8_t RESERVED_13[2];
  __IO uint16_t MPLLB_CTRL_EX_1;                   /**< MPLLB Extra Control 1, offset: 0x400B0 */
       uint8_t RESERVED_14[2];
  __IO uint16_t MPLLB_CTRL_EX_2;                   /**< MPLLB Extra Control 2, offset: 0x400B4 */
       uint8_t RESERVED_15[6];
  __I  uint16_t MPLLB_CTRL_EX_4;                   /**< MPLLB Extra Control 4, offset: 0x400BC */
       uint8_t RESERVED_16[132442];
  __IO uint16_t LANE0_CTRL_EX_4;                   /**< Lane 0 Extra Control 4, offset: 0x60618 */
       uint8_t RESERVED_17[2];
  __IO uint16_t MAC_ADAPTER_0_ERROR_EVENT;         /**< Error Event for FIFO, offset: 0x6061C */
       uint8_t RESERVED_18[2];
  __IO uint16_t LANE0_CTRL_EX_5;                   /**< Lane 0 Extra Control 5, offset: 0x60620 */
} PHY_CTRL_EX_Type;

/* ----------------------------------------------------------------------------
   -- PHY_CTRL_EX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHY_CTRL_EX_Register_Masks PHY_CTRL_EX Register Masks
 * @{
 */

/*! @name GLOBAL_CTRL_EX_0 - PHY Global Extra Control */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_MASK (0x1U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_SHIFT (0U)
/*! PHY_SRAM_BYPASS - SRAM bypass
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_CR_PARA_SEL_OVRD_MASK (0x2U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_CR_PARA_SEL_OVRD_SHIFT (1U)
/*! CR_PARA_SEL_OVRD - Override for CR_PARA_SEL of PHY
 *  0b0..CR_PARA_SEL is driven by XPCS or from GPR_IN[0]
 *  0b1..CR_PARA_SEL is driven by top CR_PARA_SEL port
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_CR_PARA_SEL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_0_CR_PARA_SEL_OVRD_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_0_CR_PARA_SEL_OVRD_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_RESET_OVRD_MASK (0x4U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_RESET_OVRD_SHIFT (2U)
/*! PHY_RESET_OVRD - Override for PHY_RESET of PHY
 *  0b0..PHY_RESET is driven by XPCS
 *  0b1..PHY_RESET is driven by [XPCS _CTRL_PHY_RESET]
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_RESET_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_RESET_OVRD_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_RESET_OVRD_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_XPCS_CTRL_PHY_RESET_MASK (0x8U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_XPCS_CTRL_PHY_RESET_SHIFT (3U)
/*! XPCS_CTRL_PHY_RESET - Driver for PHY_RESET
 *  0b0..Drive 0 to PHY_RESET
 *  0b1..Drive 1 to PHY_RESET
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_XPCS_CTRL_PHY_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_0_XPCS_CTRL_PHY_RESET_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_0_XPCS_CTRL_PHY_RESET_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_MPLLB_SEL_MASK (0x80U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_MPLLB_SEL_SHIFT (7U)
/*! MPLLB_SEL - MPLLB Select
 *  0b0..No select
 *  0b1..Selects MPLLB
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_0_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_0_MPLLB_SEL_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_0_MPLLB_SEL_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_4 - PHY Global Extra Control 4 */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_MASK (0x400U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_SHIFT (10U)
/*! PHY_PG_MODE_EN - Power Gating Support Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_MASK (0x1000U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_SHIFT (12U)
/*! PHY_PG_RESET - Power Gated Reset
 *  0b0..No reset
 *  0b1..Reset
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_6 - PHY Global Extra Control 6 */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PMA_PWR_EN_MASK (0x1U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PMA_PWR_EN_SHIFT (0U)
/*! PHY_PMA_PWR_EN - Power Enable for PMA Power Switch
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PMA_PWR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PMA_PWR_EN_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PMA_PWR_EN_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PCS_PWR_EN_MASK (0x4U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PCS_PWR_EN_SHIFT (2U)
/*! PHY_PCS_PWR_EN - Power Enable for Raw PCS Power Switches
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PCS_PWR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PCS_PWR_EN_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_PCS_PWR_EN_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_ANA_PWR_STABLE_MASK (0x10U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_ANA_PWR_STABLE_SHIFT (4U)
/*! PHY_ANA_PWR_STABLE - Internal PMA Switch Stable
 *  0b0..Not stable
 *  0b1..Stable
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_ANA_PWR_STABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_ANA_PWR_STABLE_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_ANA_PWR_STABLE_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_REF_CLK_REQ_MASK (0x40U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_REF_CLK_REQ_SHIFT (6U)
/*! PHY_REF_CLK_REQ - Reference Clock Request
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_REF_CLK_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_REF_CLK_REQ_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_6_PHY_REF_CLK_REQ_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_7 - PHY Global Extra Control 7 */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_BIGSWING_MASK (0x1U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_BIGSWING_SHIFT (0U)
/*! PHY_BS_RX_BIGSWING - RX Boundary Scan Big-Swing
 *  0b0..Driven to 0
 *  0b1..Driven to 1
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_BIGSWING(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_BIGSWING_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_BIGSWING_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_LEVEL_MASK (0x3EU)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_LEVEL_SHIFT (1U)
/*! PHY_BS_RX_LEVEL - ACJTAG Receiver Sensitivity Level Control
 *  0b00000..Minimum level
 *  0b00001-0b11110.....
 *  0b11111..Maximum level
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_LEVEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_LEVEL_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_RX_LEVEL_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_TX_LOWSWING_MASK (0x40U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_TX_LOWSWING_SHIFT (6U)
/*! PHY_BS_TX_LOWSWING - TX Boundary Scan Low-Swing
 *  0b0..Driven to 0
 *  0b1..Driven to 1
 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_TX_LOWSWING(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_TX_LOWSWING_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_7_PHY_BS_TX_LOWSWING_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_8 - PHY Global Extra Control 8 */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_0_MASK (0x1U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_0_SHIFT (0U)
/*! GPR_I_0 - Status of CR_PARA_SEL Override via GPR */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_0(x)  (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_0_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_0_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_1_MASK (0x2U)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_1_SHIFT (1U)
/*! GPR_I_1 - Status of CR_PARA_CLK Gating Override via GPR */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_1(x)  (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_1_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_1_MASK)

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_15_2_MASK (0xFFFCU)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_15_2_SHIFT (2U)
/*! GPR_I_15_2 - General Purpose Register Input 0 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_15_2_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_8_GPR_I_15_2_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_9 - PHY Global Extra Control 9 */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_9_GPR_I_31_16_MASK (0xFFFFU)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_9_GPR_I_31_16_SHIFT (0U)
/*! GPR_I_31_16 - General Purpose Register Input 1 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_9_GPR_I_31_16(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_9_GPR_I_31_16_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_9_GPR_I_31_16_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_10 - PHY Global Extra Control 10 */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_10_GPR_O_15_0_MASK (0xFFFFU)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_10_GPR_O_15_0_SHIFT (0U)
/*! GPR_O_15_0 - General Purpose Register Output 0 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_10_GPR_O_15_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_10_GPR_O_15_0_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_10_GPR_O_15_0_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_11 - PHY Global Extra Control 11 */
/*! @{ */

#define PHY_CTRL_EX_GLOBAL_CTRL_EX_11_GPR_O_31_16_MASK (0xFFFFU)
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_11_GPR_O_31_16_SHIFT (0U)
/*! GPR_O_31_16 - General Purpose Register Output 1 */
#define PHY_CTRL_EX_GLOBAL_CTRL_EX_11_GPR_O_31_16(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_GLOBAL_CTRL_EX_11_GPR_O_31_16_SHIFT)) & PHY_CTRL_EX_GLOBAL_CTRL_EX_11_GPR_O_31_16_MASK)
/*! @} */

/*! @name MPLLA_CTRL_EX_0 - MPLLA Extra Control */
/*! @{ */

#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_MASK (0x1U)
#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_SHIFT (0U)
/*! PHY_MPLLA_FORCE_EN - MPLLA Force Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_SHIFT)) & PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_MASK)

#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_TX_CLK_DIV_MASK (0x18U)
#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_TX_CLK_DIV_SHIFT (3U)
/*! PHY_MPLLA_TX_CLK_DIV - MPLLA TX Clock Divider
 *  0b00..DIV1
 *  0b01..DIV2
 *  0b10..DIV4
 *  0b11..DIV1 (duplicate state)
 */
#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_TX_CLK_DIV_SHIFT)) & PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_TX_CLK_DIV_MASK)

#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_GND_MASK     (0xF000U)
#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_GND_SHIFT    (12U)
/*! GND - GND Field */
#define PHY_CTRL_EX_MPLLA_CTRL_EX_0_GND(x)       (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLA_CTRL_EX_0_GND_SHIFT)) & PHY_CTRL_EX_MPLLA_CTRL_EX_0_GND_MASK)
/*! @} */

/*! @name MPLLA_CTRL_EX_1 - MPLLA Extra Control 1 */
/*! @{ */

#define PHY_CTRL_EX_MPLLA_CTRL_EX_1_PHY_MPLLA_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define PHY_CTRL_EX_MPLLA_CTRL_EX_1_PHY_MPLLA_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! PHY_MPLLA_SSC_FREQ_CNT_INIT - MPLLA Spread-Spectrum Frequency Counter Initialization */
#define PHY_CTRL_EX_MPLLA_CTRL_EX_1_PHY_MPLLA_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLA_CTRL_EX_1_PHY_MPLLA_SSC_FREQ_CNT_INIT_SHIFT)) & PHY_CTRL_EX_MPLLA_CTRL_EX_1_PHY_MPLLA_SSC_FREQ_CNT_INIT_MASK)
/*! @} */

/*! @name MPLLA_CTRL_EX_2 - MPLLA Extra Control 2 */
/*! @{ */

#define PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_PEAK_MASK (0xFFU)
#define PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT (0U)
/*! PHY_MPLLA_SSC_FREQ_CNT_PEAK - MPLLA Spread-Spectrum Frequency Counter Peak */
#define PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT)) & PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_PEAK_MASK)

#define PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_OVRD_EN_MASK (0x400U)
#define PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_OVRD_EN_SHIFT (10U)
/*! PHY_MPLLA_SSC_FREQ_CNT_OVRD_EN - MPLLA Spread-Spectrum Profile Override Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_OVRD_EN_SHIFT)) & PHY_CTRL_EX_MPLLA_CTRL_EX_2_PHY_MPLLA_SSC_FREQ_CNT_OVRD_EN_MASK)
/*! @} */

/*! @name MPLLA_CTRL_EX_4 - MPLLA Extra Control 4 */
/*! @{ */

#define PHY_CTRL_EX_MPLLA_CTRL_EX_4_PHY_MPLLA_FORCE_ACK_MASK (0x1U)
#define PHY_CTRL_EX_MPLLA_CTRL_EX_4_PHY_MPLLA_FORCE_ACK_SHIFT (0U)
/*! PHY_MPLLA_FORCE_ACK - MPLLA Force acknowledge */
#define PHY_CTRL_EX_MPLLA_CTRL_EX_4_PHY_MPLLA_FORCE_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLA_CTRL_EX_4_PHY_MPLLA_FORCE_ACK_SHIFT)) & PHY_CTRL_EX_MPLLA_CTRL_EX_4_PHY_MPLLA_FORCE_ACK_MASK)
/*! @} */

/*! @name MPLLB_CTRL_EX_0 - MPLLB Extra Control */
/*! @{ */

#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_MASK (0x1U)
#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_SHIFT (0U)
/*! PHY_MPLLB_FORCE_EN - MPLLB Force Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_SHIFT)) & PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_MASK)

#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_TX_CLK_DIV_MASK (0x18U)
#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_TX_CLK_DIV_SHIFT (3U)
/*! PHY_MPLLB_TX_CLK_DIV - MPLLB TX Clock Divider
 *  0b00..DIV1
 *  0b01..DIV2
 *  0b10..DIV4
 *  0b11..DIV1 (duplicate state)
 */
#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_TX_CLK_DIV_SHIFT)) & PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_TX_CLK_DIV_MASK)

#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_GND_MASK     (0xF000U)
#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_GND_SHIFT    (12U)
/*! GND - GND Field */
#define PHY_CTRL_EX_MPLLB_CTRL_EX_0_GND(x)       (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLB_CTRL_EX_0_GND_SHIFT)) & PHY_CTRL_EX_MPLLB_CTRL_EX_0_GND_MASK)
/*! @} */

/*! @name MPLLB_CTRL_EX_1 - MPLLB Extra Control 1 */
/*! @{ */

#define PHY_CTRL_EX_MPLLB_CTRL_EX_1_PHY_MPLLB_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define PHY_CTRL_EX_MPLLB_CTRL_EX_1_PHY_MPLLB_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! PHY_MPLLB_SSC_FREQ_CNT_INIT - MPLLB Spread-Spectrum Frequency Counter Initialization */
#define PHY_CTRL_EX_MPLLB_CTRL_EX_1_PHY_MPLLB_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLB_CTRL_EX_1_PHY_MPLLB_SSC_FREQ_CNT_INIT_SHIFT)) & PHY_CTRL_EX_MPLLB_CTRL_EX_1_PHY_MPLLB_SSC_FREQ_CNT_INIT_MASK)
/*! @} */

/*! @name MPLLB_CTRL_EX_2 - MPLLB Extra Control 2 */
/*! @{ */

#define PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_PEAK_MASK (0xFFU)
#define PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT (0U)
/*! PHY_MPLLB_SSC_FREQ_CNT_PEAK - MPLLB Spread-Spectrum Frequency Counter Peak */
#define PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT)) & PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_PEAK_MASK)

#define PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_OVRD_EN_MASK (0x400U)
#define PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_OVRD_EN_SHIFT (10U)
/*! PHY_MPLLB_SSC_FREQ_CNT_OVRD_EN - MPLLB Spread-Spectrum Profile Override Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_OVRD_EN_SHIFT)) & PHY_CTRL_EX_MPLLB_CTRL_EX_2_PHY_MPLLB_SSC_FREQ_CNT_OVRD_EN_MASK)
/*! @} */

/*! @name MPLLB_CTRL_EX_4 - MPLLB Extra Control 4 */
/*! @{ */

#define PHY_CTRL_EX_MPLLB_CTRL_EX_4_PHY_MPLLB_FORCE_ACK_MASK (0x1U)
#define PHY_CTRL_EX_MPLLB_CTRL_EX_4_PHY_MPLLB_FORCE_ACK_SHIFT (0U)
/*! PHY_MPLLB_FORCE_ACK - MPLLB Force acknowledge */
#define PHY_CTRL_EX_MPLLB_CTRL_EX_4_PHY_MPLLB_FORCE_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MPLLB_CTRL_EX_4_PHY_MPLLB_FORCE_ACK_SHIFT)) & PHY_CTRL_EX_MPLLB_CTRL_EX_4_PHY_MPLLB_FORCE_ACK_MASK)
/*! @} */

/*! @name LANE0_CTRL_EX_4 - Lane 0 Extra Control 4 */
/*! @{ */

#define PHY_CTRL_EX_LANE0_CTRL_EX_4_TX0_RESET_OVRD_MASK (0x40U)
#define PHY_CTRL_EX_LANE0_CTRL_EX_4_TX0_RESET_OVRD_SHIFT (6U)
/*! TX0_RESET_OVRD - Override for TX0_RESET of XPCS
 *  0b0..TX0_RESET is driven by XPCS
 *  0b1..TX0_RESET is driven by [XPCS_CTRL_TX0_RESET]
 */
#define PHY_CTRL_EX_LANE0_CTRL_EX_4_TX0_RESET_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_LANE0_CTRL_EX_4_TX0_RESET_OVRD_SHIFT)) & PHY_CTRL_EX_LANE0_CTRL_EX_4_TX0_RESET_OVRD_MASK)

#define PHY_CTRL_EX_LANE0_CTRL_EX_4_XPCS_CTRL_TX0_RESET_MASK (0x80U)
#define PHY_CTRL_EX_LANE0_CTRL_EX_4_XPCS_CTRL_TX0_RESET_SHIFT (7U)
/*! XPCS_CTRL_TX0_RESET - Driver for Lane TX0_RESET
 *  0b0..Drive 0 to TX0_RESET
 *  0b1..Drive 1 to TX0_RESET
 */
#define PHY_CTRL_EX_LANE0_CTRL_EX_4_XPCS_CTRL_TX0_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_LANE0_CTRL_EX_4_XPCS_CTRL_TX0_RESET_SHIFT)) & PHY_CTRL_EX_LANE0_CTRL_EX_4_XPCS_CTRL_TX0_RESET_MASK)
/*! @} */

/*! @name MAC_ADAPTER_0_ERROR_EVENT - Error Event for FIFO */
/*! @{ */

#define PHY_CTRL_EX_MAC_ADAPTER_0_ERROR_EVENT_MAC_SOFT_RST_MASK (0x100U)
#define PHY_CTRL_EX_MAC_ADAPTER_0_ERROR_EVENT_MAC_SOFT_RST_SHIFT (8U)
/*! MAC_SOFT_RST - MAC Adpater Soft Reset
 *  0b0..No reset
 *  0b1..Reset
 */
#define PHY_CTRL_EX_MAC_ADAPTER_0_ERROR_EVENT_MAC_SOFT_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_MAC_ADAPTER_0_ERROR_EVENT_MAC_SOFT_RST_SHIFT)) & PHY_CTRL_EX_MAC_ADAPTER_0_ERROR_EVENT_MAC_SOFT_RST_MASK)
/*! @} */

/*! @name LANE0_CTRL_EX_5 - Lane 0 Extra Control 5 */
/*! @{ */

#define PHY_CTRL_EX_LANE0_CTRL_EX_5_RX0_RESET_OVRD_MASK (0x100U)
#define PHY_CTRL_EX_LANE0_CTRL_EX_5_RX0_RESET_OVRD_SHIFT (8U)
/*! RX0_RESET_OVRD - Override for RX0_RESET of XPCS
 *  0b0..RX0_RESET is driven by XPCS
 *  0b1..RX0_RESET is driven by [XPCS_CTRL_RX0_RESET]
 */
#define PHY_CTRL_EX_LANE0_CTRL_EX_5_RX0_RESET_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_LANE0_CTRL_EX_5_RX0_RESET_OVRD_SHIFT)) & PHY_CTRL_EX_LANE0_CTRL_EX_5_RX0_RESET_OVRD_MASK)

#define PHY_CTRL_EX_LANE0_CTRL_EX_5_XPCS_CTRL_RX0_RESET_MASK (0x200U)
#define PHY_CTRL_EX_LANE0_CTRL_EX_5_XPCS_CTRL_RX0_RESET_SHIFT (9U)
/*! XPCS_CTRL_RX0_RESET - Driver for Lane RX0_RESET
 *  0b0..Drive 0 to RX0_RESET
 *  0b1..Drive 1 to RX0_RESET
 */
#define PHY_CTRL_EX_LANE0_CTRL_EX_5_XPCS_CTRL_RX0_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_CTRL_EX_LANE0_CTRL_EX_5_XPCS_CTRL_RX0_RESET_SHIFT)) & PHY_CTRL_EX_LANE0_CTRL_EX_5_XPCS_CTRL_RX0_RESET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PHY_CTRL_EX_Register_Masks */


/*!
 * @}
 */ /* end of group PHY_CTRL_EX_Peripheral_Access_Layer */


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


#endif  /* PERI_PHY_CTRL_EX_H_ */

