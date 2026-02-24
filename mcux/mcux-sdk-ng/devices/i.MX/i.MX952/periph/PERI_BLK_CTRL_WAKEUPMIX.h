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
**         CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
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
 * @file PERI_BLK_CTRL_WAKEUPMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 */

#if !defined(PERI_BLK_CTRL_WAKEUPMIX_H_)
#define PERI_BLK_CTRL_WAKEUPMIX_H_               /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_WAKEUPMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer BLK_CTRL_WAKEUPMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_WAKEUPMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t I3C2_SDA_IRQ;                      /**< I3C SDA IRQ Control, offset: 0x0 */
       uint8_t RESERVED_0[24];
  __IO uint32_t SAI_CLK_SEL;                       /**< SAI3~5 mclk1~3 Clock Root MUX Settings, offset: 0x1C */
  __I  uint32_t VOLT_DETECT;                       /**< Voltage Detectors Output, offset: 0x20 */
  __IO uint32_t I3C2_WAKEUP;                       /**< I3C2 WAKEUP Clear, offset: 0x24 */
  __IO uint32_t AXI_ATTR_CFG;                      /**< AXI CACHE Control, offset: 0x28 */
  __IO uint32_t IPG_DEBUG_CM33;                    /**< IPG DEBUG Mask, offset: 0x2C */
  __IO uint32_t IPG_DEBUG_CA55C0;                  /**< IPG DEBUG Mask for CA55 Core0, offset: 0x30 */
  __IO uint32_t IPG_DEBUG_CA55C1;                  /**< IPG DEBUG Mask for CA55 Core1, offset: 0x34 */
  __IO uint32_t IPG_DEBUG_CA55C2;                  /**< IPG DEBUG Mask for CA55 Core2, offset: 0x38 */
  __IO uint32_t IPG_DEBUG_CA55C3;                  /**< IPG DEBUG Mask for CA55 Core3, offset: 0x3C */
       uint8_t RESERVED_1[8];
  __IO uint32_t IPG_DEBUG_CM7;                     /**< IPG DEBUG Mask, offset: 0x48 */
  __IO uint32_t IPG_DEBUG_2_CM33;                  /**< IPG DEBUG Mask, offset: 0x4C */
  __IO uint32_t IPG_DEBUG_2_CA55C0;                /**< IPG DEBUG Mask for CA55 Core0, offset: 0x50 */
  __IO uint32_t IPG_DEBUG_2_CA55C1;                /**< IPG DEBUG Mask for CA55 Core1, offset: 0x54 */
  __IO uint32_t IPG_DEBUG_2_CA55C2;                /**< IPG DEBUG Mask for CA55 Core2, offset: 0x58 */
  __IO uint32_t IPG_DEBUG_2_CA55C3;                /**< IPG DEBUG Mask for CA55 Core3, offset: 0x5C */
       uint8_t RESERVED_2[8];
  __IO uint32_t IPG_DEBUG_2_CM7;                   /**< IPG DEBUG Mask, offset: 0x68 */
       uint8_t RESERVED_3[4];
  __IO uint32_t DBG_TRACE_CTL;                     /**< DEBUG TRACE Control, offset: 0x70 */
       uint8_t RESERVED_4[24];
  __IO uint32_t INITIATOR_TIMEOUT;                 /**< NOC Initiator Timeout Status, offset: 0x8C */
  __IO uint32_t NIU_TO_MW0;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_0, offset: 0x90 */
  __IO uint32_t NIU_TO_MW1;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_1, offset: 0x94 */
  __IO uint32_t NIU_TO_MW2;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_2, offset: 0x98 */
  __IO uint32_t NIU_TO_MW3;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_3, offset: 0x9C */
  __IO uint32_t NIU_TO_MW4;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_4, offset: 0xA0 */
  __IO uint32_t NIU_TO_MW5;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_5, offset: 0xA4 */
  __IO uint32_t NIU_TO_MW6;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_6, offset: 0xA8 */
  __IO uint32_t NIU_TO_MW7;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_7, offset: 0xAC */
  __IO uint32_t NIU_TO_MW8;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_8, offset: 0xB0 */
  __IO uint32_t NIU_TO_MW9;                        /**< Timeout Control for NOC wakeup NIU Initiator m_w_9, offset: 0xB4 */
  __IO uint32_t NIU_TO_MW10;                       /**< Timeout Control for NOC wakeup NIU Initiator m_w_10, offset: 0xB8 */
  __IO uint32_t NIU_TO_MW11;                       /**< Timeout Control for NOC wakeup NIU Initiator m_w_11, offset: 0xBC */
  __IO uint32_t QOS_CTL_0;                         /**< QoS control for wakeupmix Initiators into NOC WAKEUP, offset: 0xC0 */
  __IO uint32_t QOS_CTL_1;                         /**< QoS control for wakeupmix Initiators into NOC WAKEUP, offset: 0xC4 */
  __IO uint32_t QOS_CTL_2;                         /**< QoS control for wakeupmix Initiators into NOC WAKEUP, continued, offset: 0xC8 */
       uint8_t RESERVED_5[308];
  __IO uint32_t ATU_CONF;                          /**< ATU Configuration Control and sai6_ipp_ind_sai_rxbclk Select, offset: 0x200 */
       uint8_t RESERVED_6[168];
  __IO uint32_t FORCE_ON_OFF_1;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2AC */
  __IO uint32_t FORCE_ON_OFF_2;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2B0 */
  __IO uint32_t FORCE_ON_OFF_3;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2B4 */
  __IO uint32_t FORCE_ON_OFF_4;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2B8 */
  __IO uint32_t FORCE_ON_OFF_5;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2BC */
  __IO uint32_t FORCE_ON_OFF_6;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2C0 */
  __IO uint32_t FORCE_ON_OFF_7;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2C4 */
  __IO uint32_t FORCE_ON_OFF_8;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2C8 */
  __IO uint32_t FORCE_ON_OFF_9;                    /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2CC */
  __IO uint32_t FORCE_ON_OFF_10;                   /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2D0 */
  __IO uint32_t FORCE_ON_OFF_11;                   /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2D4 */
  __IO uint32_t FORCE_ON_OFF_12;                   /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2D8 */
  __IO uint32_t FORCE_ON_OFF_13;                   /**< ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel, offset: 0x2DC */
       uint8_t RESERVED_7[16];
  __IO uint32_t GPT_IPP_IND_CAPIN1_MUX_CTRL;       /**< GPT ipp_ind_capin1 MUX Control, offset: 0x2F0 */
  __IO uint32_t GPT_IPP_IND_CAPIN2_MUX_CTRL;       /**< GPT ipp_ind_capin2 MUX Control, offset: 0x2F4 */
  __IO uint32_t GPT2_IPP_IND_CLKIN_CLK;            /**< GPT2 IPP IND CLKIN CLK, offset: 0x2F8 */
       uint8_t RESERVED_8[4];
  __IO uint32_t GPT3_IPP_IND_CLKIN_CLK;            /**< GPT3 IPP IND CLKIN CLK, offset: 0x300 */
  __IO uint32_t GPT4_IPP_IND_CLKIN_CLK;            /**< GPT4 IPP IND CLKIN CLK, offset: 0x304 */
  __IO uint32_t GPT5_IPP_IND_CLKIN_CLK;            /**< GPT5 IPP IND CLKIN CLK, offset: 0x308 */
  __IO uint32_t GPT2_3_4_5;                        /**< GPT PIN MUX, offset: 0x30C */
  __IO uint32_t ASRC_MCLKOUT_MUX;                  /**< ASRC MCLKOUT MUX, offset: 0x310 */
  __IO uint32_t BYPASS_AUDMIX_IP_CTRL;             /**< BYPASS_AUDMIX_IP_CTRL, offset: 0x314 */
} BLK_CTRL_WAKEUPMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_WAKEUPMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Register_Masks BLK_CTRL_WAKEUPMIX Register Masks
 * @{
 */

/*! @name I3C2_SDA_IRQ - I3C SDA IRQ Control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_SHIFT (0U)
/*! enable - IRQ Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_MASK)
/*! @} */

/*! @name SAI_CLK_SEL - SAI3~5 mclk1~3 Clock Root MUX Settings */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT (0U)
/*! SAI3_MCLK1 - SAI3 Initiator Clock 1 Source Selection
 *  0b0..SAI3 root clock 1
 *  0b1..SAI3 initiator clock IO pad input
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK (0x1EU)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT (1U)
/*! SAI3_MCLK2 - SAI3 Initiator Clock 2 Source Selection
 *  0b0000..SAI1 root clock
 *  0b0001..SAI2 root clock
 *  0b0010..SAI3 root clock
 *  0b0011..SAI4 root clock
 *  0b0100..SAI5 root clock
 *  0b0111..SAI1 initiator clock IO pad input
 *  0b1000..SAI2 initiator clock IO pad input
 *  0b1001..SAI3 initiator clock IO pad input
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK (0x1E0U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT (5U)
/*! SAI3_MCLK3 - SAI3 Initiator Clock 3 Source Selection
 *  0b0000..SAI1 root clock
 *  0b0001..SAI2 root clock
 *  0b0010..SAI3 root clock
 *  0b0011..SAI4 root clock
 *  0b0100..SAI5 root clock
 *  0b0111..SAI1 initiator clock IO pad input
 *  0b1000..SAI2 initiator clock IO pad input
 *  0b1001..SAI3 initiator clock IO pad input
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_SHIFT (9U)
/*! SAI4_MCLK1 - SAI4 Initiator Clock 1 Source Selection
 *  0b0..SAI4 root clock
 *  0b1..SAI4 pad input initiator clock
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_MASK (0x3C00U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_SHIFT (10U)
/*! SAI4_MCLK2 - SAI4 Initiator Clock 2 Source Selection
 *  0b0000..SAI1 root clock
 *  0b0001..SAI2 root clock
 *  0b0010..SAI3 root clock
 *  0b0011..SAI4 root clock
 *  0b0100..SAI5 root clock
 *  0b0111..SAI1 initiator clock IO pad input
 *  0b1000..SAI2 initiator clock IO pad input
 *  0b1001..SAI3 initiator clock IO pad input
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_MASK (0x3C000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_SHIFT (14U)
/*! SAI4_MCLK3 - SAI4 Initiator Clock 3 Source Selection
 *  0b0000..SAI1 root clock
 *  0b0001..SAI2 root clock
 *  0b0010..SAI3 root clock
 *  0b0011..SAI4 root clock
 *  0b0100..SAI5 root clock
 *  0b0111..SAI1 initiator clock IO pad input
 *  0b1000..SAI2 initiator clock IO pad input
 *  0b1001..SAI3 initiator clock IO pad input
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_SHIFT (18U)
/*! SAI5_MCLK1 - SAI5 Initiator Clock 1 Source Selection
 *  0b0..SAI5 root clock
 *  0b1..SAI5 pad input initiator clock
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_MASK (0x780000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_SHIFT (19U)
/*! SAI5_MCLK2 - SAI5 Initiator Clock 2 Source Selection
 *  0b0000..SAI1 root clock
 *  0b0001..SAI2 root clock
 *  0b0010..SAI3 root clock
 *  0b0011..SAI4 root clock
 *  0b0100..SAI5 root clock
 *  0b0111..SAI1 initiator clock IO pad input
 *  0b1000..SAI2 initiator clock IO pad input
 *  0b1001..SAI3 initiator clock IO pad input
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_MASK (0x7800000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_SHIFT (23U)
/*! SAI5_MCLK3 - SAI5 Initiator Clock 3 Source Selection
 *  0b0000..SAI1 root clock
 *  0b0001..SAI2 root clock
 *  0b0010..SAI3 root clock
 *  0b0011..SAI4 root clock
 *  0b0100..SAI5 root clock
 *  0b0111..SAI1 initiator clock IO pad input
 *  0b1000..SAI2 initiator clock IO pad input
 *  0b1001..SAI3 initiator clock IO pad input
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_MASK)
/*! @} */

/*! @name VOLT_DETECT - Voltage Detectors Output */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_SHIFT (0U)
/*! supply_detector_AON - Voltage Detectors Output of AON
 *  0b0..Input voltage of the domain is 3.3V
 *  0b1..Input voltage of the domain is 1.8V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_SHIFT (1U)
/*! supply_detector_GPIO - Voltage Detectors Output of GPIO
 *  0b0..Input voltage of the domain is 3.3V
 *  0b1..Input voltage of the domain is 1.8V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_SHIFT (2U)
/*! supply_detector_SD2 - Voltage Detectors Output of SD2
 *  0b0..Input voltage of the domain is 3.3V
 *  0b1..Input voltage of the domain is 1.8V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_SHIFT (3U)
/*! supply_detector_WAKEUP - Voltage Detectors Output of WAKEUP
 *  0b0..Input voltage of the domain is 3.3V
 *  0b1..Input voltage of the domain is 1.8V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_SHIFT (4U)
/*! supply_detector_CCM_DAP - Voltage Detectors Output of CCM DAP
 *  0b0..Input voltage of the domain is 3.3V
 *  0b1..Input voltage of the domain is 1.8V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_SHIFT (5U)
/*! supply_detector_ENET - Voltage Detectors Output of ENET
 *  0b0..Input voltage of the domain is 3.3V
 *  0b1..Input voltage of the domain is 1.8V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_MASK)
/*! @} */

/*! @name I3C2_WAKEUP - I3C2 WAKEUP Clear */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_irq_clr_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_irq_clr_SHIFT (0U)
/*! irq_clr - I3C Wakeup Interrupt Clear
 *  0b0..Release clear
 *  0b1..Clear
 */
#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_irq_clr(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_irq_clr_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_irq_clr_MASK)
/*! @} */

/*! @name AXI_ATTR_CFG - AXI CACHE Control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_SHIFT (0U)
/*! arcache_usdhc1 - Static value of arcache[1] = CACHEABLE (C) for AXI Initiator usdhc1
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_SHIFT (1U)
/*! awcache_usdhc1 - Static value of awcache[1] = CACHEABLE (C) for AXI Initiator usdhc1
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_SHIFT (2U)
/*! arcache_usdhc2 - Static value of arcache[1] = CACHEABLE (C) for AXI Initiator usdhc2
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_SHIFT (3U)
/*! awcache_usdhc2 - Static value of awcache[1] = CACHEABLE (C) for AXI Initiator usdhc2
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_SHIFT (4U)
/*! arcache_usdhc3 - Static value of arcache[1] = CACHEABLE (C) for AXI Initiator usdhc3
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_SHIFT (5U)
/*! awcache_usdhc3 - Static value of awcache[1] = CACHEABLE (C) for AXI Initiator usdhc3
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM33 - IPG DEBUG Mask */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_SHIFT (31U)
/*! edma2 - eDMA5_2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C0 - IPG DEBUG Mask for CA55 Core0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_SHIFT (31U)
/*! edma2 - eDMA5_2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C1 - IPG DEBUG Mask for CA55 Core1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_SHIFT (31U)
/*! edma2 - eDMA5_2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C2 - IPG DEBUG Mask for CA55 Core2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_SHIFT (31U)
/*! edma2 - eDMA5_2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C3 - IPG DEBUG Mask for CA55 Core3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_SHIFT (31U)
/*! edma2 - eDMA5_2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM7 - IPG DEBUG Mask */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_SHIFT (31U)
/*! edma2 - eDMA5_2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM33 - IPG DEBUG Mask */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_SHIFT (0U)
/*! edma3 - eDMA5_3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C0 - IPG DEBUG Mask for CA55 Core0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_SHIFT (0U)
/*! edma3 - eDMA5_3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C1 - IPG DEBUG Mask for CA55 Core1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_SHIFT (0U)
/*! edma3 - eDMA5_3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C2 - IPG DEBUG Mask for CA55 Core2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_SHIFT (0U)
/*! edma3 - eDMA5_3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C3 - IPG DEBUG Mask for CA55 Core3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_SHIFT (0U)
/*! edma3 - eDMA5_3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM7 - IPG DEBUG Mask */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_SHIFT (0U)
/*! edma3 - eDMA5_3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_MASK)
/*! @} */

/*! @name DBG_TRACE_CTL - DEBUG TRACE Control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_SHIFT (0U)
/*! clken_csswo - Enables control of the debug/trace CSSWO clock.
 *  0b0..trace_en_swo disabled, trace port clock OFF.
 *  0b1..trace_en_swo enabled, trace port clock ON.
 */
#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_SHIFT)) & BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_MASK)
/*! @} */

/*! @name INITIATOR_TIMEOUT - NOC Initiator Timeout Status */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_SHIFT (0U)
/*! mw0r_timeout - Initiator timeout for mw0r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_SHIFT (1U)
/*! mw0w_timeout - Initiator timeout for mw0w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_SHIFT (2U)
/*! mw1_timeout - Initiator timeout for mw1_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_SHIFT (3U)
/*! mw2r_timeout - Initiator timeout for mw2r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_SHIFT (4U)
/*! mw2w_timeout - Initiator timeout for mw2w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_SHIFT (5U)
/*! mw3r_timeout - Initiator timeout for mw3r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_SHIFT (6U)
/*! mw3w_timeout - Initiator timeout for mw3w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_SHIFT (7U)
/*! mw4r_timeout - Initiator timeout for mw4r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_SHIFT (8U)
/*! mw4w_timeout - Initiator timeout for mw4w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_SHIFT (9U)
/*! mw5r_timeout - Initiator timeout for mw5r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_SHIFT (10U)
/*! mw5w_timeout - Initiator timeout for mw5w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_SHIFT (11U)
/*! mw6r_timeout - Initiator timeout for mw6r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_SHIFT (12U)
/*! mw6w_timeout - Initiator timeout for mw6w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_SHIFT (13U)
/*! mw7_timeout - Initiator timeout for mw7_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_SHIFT (14U)
/*! mw8_timeout - Initiator timeout for mw8_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_SHIFT (15U)
/*! mw9_timeout - Initiator timeout for mw9_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_SHIFT (16U)
/*! mw10r_timeout - Initiator timeout for mw10r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_SHIFT (17U)
/*! mw10w_timeout - Initiator timeout for mw10w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_SHIFT (18U)
/*! mw11_timeout - Initiator timeout for mw11_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_MASK)
/*! @} */

/*! @name NIU_TO_MW0 - Timeout Control for NOC wakeup NIU Initiator m_w_0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW1 - Timeout Control for NOC wakeup NIU Initiator m_w_1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW2 - Timeout Control for NOC wakeup NIU Initiator m_w_2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW3 - Timeout Control for NOC wakeup NIU Initiator m_w_3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW4 - Timeout Control for NOC wakeup NIU Initiator m_w_4 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW5 - Timeout Control for NOC wakeup NIU Initiator m_w_5 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW6 - Timeout Control for NOC wakeup NIU Initiator m_w_6 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW7 - Timeout Control for NOC wakeup NIU Initiator m_w_7 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW8 - Timeout Control for NOC wakeup NIU Initiator m_w_8 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW9 - Timeout Control for NOC wakeup NIU Initiator m_w_9 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW10 - Timeout Control for NOC wakeup NIU Initiator m_w_10 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_MASK  (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_SHIFT (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_MASK  (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_SHIFT (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW11 - Timeout Control for NOC wakeup NIU Initiator m_w_11 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_MASK  (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_SHIFT (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_MASK  (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_SHIFT (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_MASK)
/*! @} */

/*! @name QOS_CTL_0 - QoS control for wakeupmix Initiators into NOC WAKEUP */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_SHIFT (0U)
/*! ar_qos_default_mw2 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_SHIFT (4U)
/*! aw_qos_default_mw2 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_SHIFT (8U)
/*! ar_qos_default_mw3 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_SHIFT (12U)
/*! aw_qos_default_mw3 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw4_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw4_SHIFT (16U)
/*! ar_qos_default_mw4 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw4_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw4_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw4_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw4_SHIFT (20U)
/*! aw_qos_default_mw4 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw4_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw4_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw5_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw5_SHIFT (24U)
/*! ar_qos_default_mw5 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw5_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw5_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw5_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw5_SHIFT (28U)
/*! aw_qos_default_mw5 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw5_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw5_MASK)
/*! @} */

/*! @name QOS_CTL_1 - QoS control for wakeupmix Initiators into NOC WAKEUP */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_SHIFT (0U)
/*! ar_qos_default_mw6 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_SHIFT (4U)
/*! aw_qos_default_mw6 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw8_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw8_SHIFT (8U)
/*! ar_qos_default_mw8 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw8_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw8_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw8_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw8_SHIFT (12U)
/*! aw_qos_default_mw8 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw8_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw8_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw9_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw9_SHIFT (16U)
/*! ar_qos_default_mw9 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw9_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw9_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw9_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw9_SHIFT (20U)
/*! aw_qos_default_mw9 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw9_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw9_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_SHIFT (24U)
/*! ar_qos_default_mw11 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_SHIFT (28U)
/*! aw_qos_default_mw11 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_MASK)
/*! @} */

/*! @name QOS_CTL_2 - QoS control for wakeupmix Initiators into NOC WAKEUP, continued */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw10_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw10_SHIFT (0U)
/*! ar_qos_default_mw10 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw10_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw10_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw10_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw10_SHIFT (4U)
/*! aw_qos_default_mw10 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw10_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw10_MASK)
/*! @} */

/*! @name ATU_CONF - ATU Configuration Control and sai6_ipp_ind_sai_rxbclk Select */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_SHIFT (0U)
/*! atu_a_pm_en - ATU A PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_SHIFT (1U)
/*! atu_a_error_on_miss - ATU A Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_SHIFT (4U)
/*! atu_usdhc_1_pm_en - ATU USDHC 1 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_SHIFT (5U)
/*! atu_usdhc_1_error_on_miss - ATU USDHC 1 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_SHIFT (8U)
/*! atu_usdhc_2_pm_en - ATU USDHC 2 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_SHIFT (9U)
/*! atu_usdhc_2_error_on_miss - ATU USDHC 2 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_SHIFT (12U)
/*! atu_usdhc_3_pm_en - ATU USDHC 3 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_SHIFT (13U)
/*! atu_usdhc_3_error_on_miss - ATU USDHC 3 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_SHIFT (16U)
/*! atu_ahbap_pm_en - ATU AHBAP PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_SHIFT (17U)
/*! atu_ahbap_error_on_miss - ATU AHBAP Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_SHIFT (20U)
/*! atu_v2x_pm_en - ATU V2X PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_SHIFT (21U)
/*! atu_v2x_error_on_miss - ATU V2X Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_SHIFT (24U)
/*! atu_xspi_pm_en - SAI6 ipp_ind_sai_rxbclk MUX
 *  0b0..PAD loopback
 *  0b1..Internal lookpack
 */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_SHIFT (25U)
/*! atu_xspi_error_on_miss - ATU XSPI Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_1 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_SHIFT (0U)
/*! ipc_axi_nogate_clk - Clock Gating Override Enable of ipc_axi_nogate_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_SHIFT (1U)
/*! sel_ipc_axi_nogate_clk - Clock Gating Override Select of ipc_axi_nogate_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_safety_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_safety_SHIFT (4U)
/*! ipc_axi_nogate_clk_safety - Clock Gating Override Enable of ipc_axi_nogate_clk_safety */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_safety(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_safety_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_safety_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_safety_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_safety_SHIFT (5U)
/*! sel_ipc_axi_nogate_clk_safety - Clock Gating Override Select of ipc_axi_nogate_clk_safety */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_safety(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_safety_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_safety_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n3_SHIFT (6U)
/*! ipc_axi_nogate_clk_jtag_n3 - Clock Gating Override Enable of ipc_axi_nogate_clk_jtag_n3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n3_SHIFT (7U)
/*! sel_ipc_axi_nogate_clk_jtag_n3 - Clock Gating Override Select of ipc_axi_nogate_clk_jtag_n3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n4_SHIFT (8U)
/*! ipc_axi_nogate_clk_jtag_n4 - Clock Gating Override Enable of ipc_axi_nogate_clk_jtag_n4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_jtag_n4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n4_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n4_SHIFT (9U)
/*! sel_ipc_axi_nogate_clk_jtag_n4 - Clock Gating Override Select of ipc_axi_nogate_clk_jtag_n4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_jtag_n4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_cortexamix_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_cortexamix_SHIFT (10U)
/*! ipc_axi_nogate_clk_cortexamix - Clock Gating Override Enable of ipc_axi_nogate_clk_cortexamix */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_cortexamix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_cortexamix_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_cortexamix_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_cortexamix_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_cortexamix_SHIFT (11U)
/*! sel_ipc_axi_nogate_clk_cortexamix - Clock Gating Override Select of ipc_axi_nogate_clk_cortexamix */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_cortexamix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_cortexamix_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_cortexamix_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_gpu_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_gpu_SHIFT (12U)
/*! ipc_axi_nogate_clk_gpu - Clock Gating Override Enable of ipc_axi_nogate_clk_gpu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_gpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_gpu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_gpu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_gpu_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_gpu_SHIFT (13U)
/*! sel_ipc_axi_nogate_clk_gpu - Clock Gating Override Select of ipc_axi_nogate_clk_gpu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_gpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_gpu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_gpu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_m7_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_m7_SHIFT (14U)
/*! ipc_axi_nogate_clk_m7 - Clock Gating Override Enable of ipc_axi_nogate_clk_m7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_m7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_m7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_m7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_m7_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_m7_SHIFT (15U)
/*! sel_ipc_axi_nogate_clk_m7 - Clock Gating Override Select of ipc_axi_nogate_clk_m7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_m7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_m7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_m7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma2_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma2_SHIFT (16U)
/*! ipc_axi_nogate_clk_edma2 - Clock Gating Override Enable of ipc_axi_nogate_clk_edma2 (eDMA5_2) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma2_SHIFT (17U)
/*! sel_ipc_axi_nogate_clk_edma2 - Clock Gating Override Select of ipc_axi_nogate_clk_edma2 (eDMA5_2) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma3_SHIFT (18U)
/*! ipc_axi_nogate_clk_edma3 - Clock Gating Override Enable of ipc_axi_nogate_clk_edma3 (eDMA5_3) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma3_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma3_SHIFT (19U)
/*! sel_ipc_axi_nogate_clk_edma3 - Clock Gating Override Select of ipc_axi_nogate_clk_edma3 (eDMA5_3) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_tcu_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_tcu_SHIFT (20U)
/*! ipc_axi_nogate_clk_tcu - Clock Gating Override Enable of ipc_axi_nogate_clk_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_tcu_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_tcu_SHIFT (21U)
/*! sel_ipc_axi_nogate_clk_tcu - Clock Gating Override Select of ipc_axi_nogate_clk_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_xspi1_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_xspi1_SHIFT (22U)
/*! ipc_axi_nogate_clk_xspi1 - Clock Gating Override Enable of ipc_axi_nogate_clk_xspi1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_xspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_xspi1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_xspi1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_xspi1_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_xspi1_SHIFT (23U)
/*! sel_ipc_axi_nogate_clk_xspi1 - Clock Gating Override Select of ipc_axi_nogate_clk_xspi1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_xspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_xspi1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_xspi1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc1_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc1_SHIFT (24U)
/*! ipc_axi_nogate_clk_usdhc1 - Clock Gating Override Enable of ipc_axi_nogate_clk_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc1_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc1_SHIFT (25U)
/*! sel_ipc_axi_nogate_clk_usdhc1 - Clock Gating Override Select of ipc_axi_nogate_clk_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc2_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc2_SHIFT (26U)
/*! ipc_axi_nogate_clk_usdhc2 - Clock Gating Override Enable of ipc_axi_nogate_clk_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc2_SHIFT (27U)
/*! sel_ipc_axi_nogate_clk_usdhc2 - Clock Gating Override Select of ipc_axi_nogate_clk_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc3_SHIFT (28U)
/*! ipc_axi_nogate_clk_usdhc3 - Clock Gating Override Enable of ipc_axi_nogate_clk_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_ipc_axi_nogate_clk_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc3_SHIFT (29U)
/*! sel_ipc_axi_nogate_clk_usdhc3 - Clock Gating Override Select of ipc_axi_nogate_clk_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_1_sel_ipc_axi_nogate_clk_usdhc3_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_2 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_axi_nogate_clk_xspi_slv_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_axi_nogate_clk_xspi_slv_SHIFT (0U)
/*! ipc_axi_nogate_clk_xspi_slv - Clock Gating Override Enable of ipc_axi_nogate_clk_xspi_slv */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_axi_nogate_clk_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_axi_nogate_clk_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_axi_nogate_clk_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_axi_nogate_clk_xspi_slv_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_axi_nogate_clk_xspi_slv_SHIFT (1U)
/*! sel_ipc_axi_nogate_clk_xspi_slv - Clock Gating Override Select of ipc_axi_nogate_clk_xspi_slv */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_axi_nogate_clk_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_axi_nogate_clk_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_axi_nogate_clk_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_mst_wkup2aon_clk_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_mst_wkup2aon_clk_SHIFT (2U)
/*! ipc_ssi_mst_wkup2aon_clk - Clock Gating Override Enable of ipc_ssi_mst_wkup2aon_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_mst_wkup2aon_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_mst_wkup2aon_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_mst_wkup2aon_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_mst_wkup2aon_clk_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_mst_wkup2aon_clk_SHIFT (3U)
/*! sel_ipc_ssi_mst_wkup2aon_clk - Clock Gating Override Select of ipc_ssi_mst_wkup2aon_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_mst_wkup2aon_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_mst_wkup2aon_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_mst_wkup2aon_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_slv_aon2wkup_clk_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_slv_aon2wkup_clk_SHIFT (4U)
/*! ipc_ssi_slv_aon2wkup_clk - Clock Gating Override Enable of ipc_ssi_slv_aon2wkup_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_slv_aon2wkup_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_slv_aon2wkup_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_ipc_ssi_slv_aon2wkup_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_slv_aon2wkup_clk_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_slv_aon2wkup_clk_SHIFT (5U)
/*! sel_ipc_ssi_slv_aon2wkup_clk - Clock Gating Override Select of ipc_ssi_slv_aon2wkup_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_slv_aon2wkup_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_slv_aon2wkup_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_2_sel_ipc_ssi_slv_aon2wkup_clk_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_3 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_tcu_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_tcu_SHIFT (4U)
/*! ipc_bus_nogate_clk_tcu - Clock Gating Override Enable of ipc_bus_nogate_clk_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_tcu_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_tcu_SHIFT (5U)
/*! sel_ipc_bus_nogate_clk_tcu - Clock Gating Override Select of ipc_bus_nogate_clk_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_safety_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_safety_SHIFT (6U)
/*! ipc_bus_nogate_clk_safety - Clock Gating Override Enable of ipc_bus_nogate_clk_safety */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_safety(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_safety_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_safety_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_safety_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_safety_SHIFT (7U)
/*! sel_ipc_bus_nogate_clk_safety - Clock Gating Override Select of ipc_bus_nogate_clk_safety */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_safety(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_safety_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_safety_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n17_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n17_SHIFT (8U)
/*! ipc_bus_nogate_clk_jtag_n17 - Clock Gating Override Enable of ipc_bus_nogate_clk_jtag_n17 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n17(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n17_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n17_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n17_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n17_SHIFT (9U)
/*! sel_ipc_bus_nogate_clk_jtag_n17 - Clock Gating Override Enable of ipc_bus_nogate_clk_jtag_n17 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n17(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n17_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n17_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n28_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n28_SHIFT (10U)
/*! ipc_bus_nogate_clk_jtag_n28 - Clock Gating Override Enable of ipc_bus_nogate_clk_jtag_n28 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n28(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n28_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_jtag_n28_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n28_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n28_SHIFT (11U)
/*! sel_ipc_bus_nogate_clk_jtag_n28 - Clock Gating Override Select of ipc_bus_nogate_clk_jtag_n28 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n28(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n28_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_jtag_n28_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma2_SHIFT (12U)
/*! ipc_bus_nogate_clk_edma2 - Clock Gating Override Enable of ipc_bus_nogate_clk_edma2 (eDMA5_2) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma2_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma2_SHIFT (13U)
/*! sel_ipc_bus_nogate_clk_edma2 - Clock Gating Override Select of ipc_bus_nogate_clk_edma2 (eDMA5_2) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma3_SHIFT (14U)
/*! ipc_bus_nogate_clk_edma3 - Clock Gating Override Enable of ipc_bus_nogate_clk_edma3 (eDMA5_3) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma3_SHIFT (15U)
/*! sel_ipc_bus_nogate_clk_edma3 - Clock Gating Override Select of ipc_bus_nogate_clk_edma3 (eDMA5_3) */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio2_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio2_SHIFT (16U)
/*! ipc_bus_nogate_clk_gpio2 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpio2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio2_SHIFT (17U)
/*! sel_ipc_bus_nogate_clk_gpio2 - Clock Gating Override Select of ipc_bus_nogate_clk_gpio2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio3_SHIFT (18U)
/*! ipc_bus_nogate_clk_gpio3 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpio3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio3_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio3_SHIFT (19U)
/*! sel_ipc_bus_nogate_clk_gpio3 - Clock Gating Override Select of ipc_bus_nogate_clk_gpio3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio4_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio4_SHIFT (20U)
/*! ipc_bus_nogate_clk_gpio4 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpio4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio4_SHIFT (21U)
/*! sel_ipc_bus_nogate_clk_gpio4 - Clock Gating Override Select of ipc_bus_nogate_clk_gpio4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio5_SHIFT (22U)
/*! ipc_bus_nogate_clk_gpio5 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpio5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpio5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio5_SHIFT (23U)
/*! sel_ipc_bus_nogate_clk_gpio5 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpio5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpio5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_SHIFT (24U)
/*! ipc_bus_nogate_clk_gpt2 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_SHIFT (25U)
/*! sel_ipc_bus_nogate_clk_gpt2 - Clock Gating Override Select of ipc_bus_nogate_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_SHIFT (26U)
/*! ipc_bus_nogate_clk_gpt3 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_SHIFT (27U)
/*! sel_ipc_bus_nogate_clk_gpt3 - Clock Gating Override Select of ipc_bus_nogate_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_SHIFT (28U)
/*! ipc_bus_nogate_clk_gpt4 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_SHIFT (29U)
/*! sel_ipc_bus_nogate_clk_gpt4 - Clock Gating Override Select of ipc_bus_nogate_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_SHIFT (30U)
/*! ipc_bus_nogate_clk_gpt5 - Clock Gating Override Enable of ipc_bus_nogate_clk_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_SHIFT (31U)
/*! sel_ipc_bus_nogate_clk_gpt5 - Clock Gating Override Select of ipc_bus_nogate_clk_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_4 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio1_SHIFT (0U)
/*! ipc_bus_nogate_clk_flexio1 - Clock Gating Override Enable of ipc_bus_nogate_clk_flexio1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio1_SHIFT (1U)
/*! sel_ipc_bus_nogate_clk_flexio1 - Clock Gating Override Select of ipc_bus_nogate_clk_flexio1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio2_SHIFT (2U)
/*! ipc_bus_nogate_clk_flexio2 - Clock Gating Override Enable of ipc_bus_nogate_clk_flexio2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio2_SHIFT (3U)
/*! sel_ipc_bus_nogate_clk_flexio2 - Clock Gating Override Select of ipc_bus_nogate_clk_flexio2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_i3c2_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_i3c2_SHIFT (4U)
/*! ipc_bus_nogate_clk_i3c2 - Clock Gating Override Enable of ipc_bus_nogate_clk_i3c2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_i3c2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_i3c2_SHIFT (5U)
/*! sel_ipc_bus_nogate_clk_i3c2 - Clock Gating Override Select of ipc_bus_nogate_clk_i3c2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpit2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpit2_SHIFT (6U)
/*! ipc_bus_nogate_clk_lpit2 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpit2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpit2_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpit2_SHIFT (7U)
/*! sel_ipc_bus_nogate_clk_lpit2 - Clock Gating Override Select of ipc_bus_nogate_clk_lpit2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c3_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c3_SHIFT (8U)
/*! ipc_bus_nogate_clk_lpi2c3 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpi2c3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c3_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c3_SHIFT (9U)
/*! sel_ipc_bus_nogate_clk_lpi2c3 - Clock Gating Override Select of ipc_bus_nogate_clk_lpi2c3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c4_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c4_SHIFT (10U)
/*! ipc_bus_nogate_clk_lpi2c4 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpi2c4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c4_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c4_SHIFT (11U)
/*! sel_ipc_bus_nogate_clk_lpi2c4 - Clock Gating Override Select of ipc_bus_nogate_clk_lpi2c4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c5_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c5_SHIFT (12U)
/*! ipc_bus_nogate_clk_lpi2c5 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpi2c5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c5_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c5_SHIFT (13U)
/*! sel_ipc_bus_nogate_clk_lpi2c5 - Clock Gating Override Select of ipc_bus_nogate_clk_lpi2c5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c6_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c6_SHIFT (14U)
/*! ipc_bus_nogate_clk_lpi2c6 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpi2c6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c6_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c6_SHIFT (15U)
/*! sel_ipc_bus_nogate_clk_lpi2c6 - Clock Gating Override Select of ipc_bus_nogate_clk_lpi2c6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c7_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c7_SHIFT (16U)
/*! ipc_bus_nogate_clk_lpi2c7 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpi2c7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c7_SHIFT (17U)
/*! sel_ipc_bus_nogate_clk_lpi2c7 - Clock Gating Override Select of ipc_bus_nogate_clk_lpi2c7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c8_SHIFT (18U)
/*! ipc_bus_nogate_clk_lpi2c8 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpi2c8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c8_SHIFT (19U)
/*! sel_ipc_bus_nogate_clk_lpi2c8 - Clock Gating Override Select of ipc_bus_nogate_clk_lpi2c8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi3_SHIFT (20U)
/*! ipc_bus_nogate_clk_lpspi3 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpspi3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi3_SHIFT (21U)
/*! sel_ipc_bus_nogate_clk_lpspi3 - Clock Gating Override Select of ipc_bus_nogate_clk_lpspi3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi4_SHIFT (22U)
/*! ipc_bus_nogate_clk_lpspi4 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpspi4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi4_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi4_SHIFT (23U)
/*! sel_ipc_bus_nogate_clk_lpspi4 - Clock Gating Override Select of ipc_bus_nogate_clk_lpspi4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi5_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi5_SHIFT (24U)
/*! ipc_bus_nogate_clk_lpspi5 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpspi5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi5_SHIFT (25U)
/*! sel_ipc_bus_nogate_clk_lpspi5 - Clock Gating Override Select of ipc_bus_nogate_clk_lpspi5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi6_SHIFT (26U)
/*! ipc_bus_nogate_clk_lpspi6 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpspi6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi6_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi6_SHIFT (27U)
/*! sel_ipc_bus_nogate_clk_lpspi6 - Clock Gating Override Select of ipc_bus_nogate_clk_lpspi6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi7_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi7_SHIFT (28U)
/*! ipc_bus_nogate_clk_lpspi7 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpspi7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi7_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi7_SHIFT (29U)
/*! sel_ipc_bus_nogate_clk_lpspi7 - Clock Gating Override Select of ipc_bus_nogate_clk_lpspi7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi8_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi8_SHIFT (30U)
/*! ipc_bus_nogate_clk_lpspi8 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpspi8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_ipc_bus_nogate_clk_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi8_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi8_SHIFT (31U)
/*! sel_ipc_bus_nogate_clk_lpspi8 - Clock Gating Override Select of ipc_bus_nogate_clk_lpspi8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_4_sel_ipc_bus_nogate_clk_lpspi8_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_5 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart3_SHIFT (0U)
/*! ipc_bus_nogate_clk_lpuart3 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpuart3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart3_SHIFT (1U)
/*! sel_ipc_bus_nogate_clk_lpuart3 - Clock Gating Override Select of ipc_bus_nogate_clk_lpuart3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart4_SHIFT (2U)
/*! ipc_bus_nogate_clk_lpuart4 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpuart4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart4_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart4_SHIFT (3U)
/*! sel_ipc_bus_nogate_clk_lpuart4 - Clock Gating Override Select of ipc_bus_nogate_clk_lpuart4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart5_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart5_SHIFT (4U)
/*! ipc_bus_nogate_clk_lpuart5 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpuart5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart5_SHIFT (5U)
/*! sel_ipc_bus_nogate_clk_lpuart5 - Clock Gating Override Select of ipc_bus_nogate_clk_lpuart5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart6_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart6_SHIFT (6U)
/*! ipc_bus_nogate_clk_lpuart6 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpuart6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart6_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart6_SHIFT (7U)
/*! sel_ipc_bus_nogate_clk_lpuart6 - Clock Gating Override Select of ipc_bus_nogate_clk_lpuart6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart7_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart7_SHIFT (8U)
/*! ipc_bus_nogate_clk_lpuart7 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpuart7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart7_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart7_SHIFT (9U)
/*! sel_ipc_bus_nogate_clk_lpuart7 - Clock Gating Override Select of ipc_bus_nogate_clk_lpuart7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart8_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart8_SHIFT (10U)
/*! ipc_bus_nogate_clk_lpuart8 - Clock Gating Override Enable of ipc_bus_nogate_clk_lpuart8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lpuart8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart8_SHIFT (11U)
/*! sel_ipc_bus_nogate_clk_lpuart8 - Clock Gating Override Select of ipc_bus_nogate_clk_lpuart8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lpuart8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lptmr2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lptmr2_SHIFT (12U)
/*! ipc_bus_nogate_clk_lptmr2 - Clock Gating Override Enable of ipc_bus_nogate_clk_lptmr2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lptmr2_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lptmr2_SHIFT (13U)
/*! sel_ipc_bus_nogate_clk_lptmr2 - Clock Gating Override Select of ipc_bus_nogate_clk_lptmr2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_mu_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_mu_SHIFT (14U)
/*! ipc_bus_nogate_clk_mu - Clock Gating Override Enable of ipc_bus_nogate_clk_mu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_mu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_mu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_mu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_mu_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_mu_SHIFT (15U)
/*! sel_ipc_bus_nogate_clk_mu - Clock Gating Override Select of ipc_bus_nogate_clk_mu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_mu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_mu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_mu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_SHIFT (16U)
/*! ipc_bus_nogate_clk_sai3 - Clock Gating Override Enable of ipc_bus_nogate_clk_sai3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_SHIFT (17U)
/*! sel_ipc_bus_nogate_clk_sai3 - Clock Gating Override Select of ipc_bus_nogate_clk_sai3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_SHIFT (18U)
/*! ipc_bus_nogate_clk_sai4 - Clock Gating Override Enable of ipc_bus_nogate_clk_sai4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_SHIFT (19U)
/*! sel_ipc_bus_nogate_clk_sai4 - Clock Gating Override Select of ipc_bus_nogate_clk_sai4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_SHIFT (20U)
/*! ipc_bus_nogate_clk_sai5 - Clock Gating Override Enable of ipc_bus_nogate_clk_sai5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_SHIFT (21U)
/*! sel_ipc_bus_nogate_clk_sai5 - Clock Gating Override Select of ipc_bus_nogate_clk_sai5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sema2_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sema2_SHIFT (22U)
/*! ipc_bus_nogate_clk_sema2 - Clock Gating Override Enable of ipc_bus_nogate_clk_sema2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sema2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sema2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sema2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sema2_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sema2_SHIFT (23U)
/*! sel_ipc_bus_nogate_clk_sema2 - Clock Gating Override Select of ipc_bus_nogate_clk_sema2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sema2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sema2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sema2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm3_SHIFT (24U)
/*! ipc_bus_nogate_clk_tpm3 - Clock Gating Override Enable of ipc_bus_nogate_clk_tpm3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm3_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm3_SHIFT (25U)
/*! sel_ipc_bus_nogate_clk_tpm3 - Clock Gating Override Select of ipc_bus_nogate_clk_tpm3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm4_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm4_SHIFT (26U)
/*! ipc_bus_nogate_clk_tpm4 - Clock Gating Override Enable of ipc_bus_nogate_clk_tpm4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm4_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm4_SHIFT (27U)
/*! sel_ipc_bus_nogate_clk_tpm4 - Clock Gating Override Select of ipc_bus_nogate_clk_tpm4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm5_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm5_SHIFT (28U)
/*! ipc_bus_nogate_clk_tpm5 - Clock Gating Override Enable of ipc_bus_nogate_clk_tpm5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm5_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm5_SHIFT (29U)
/*! sel_ipc_bus_nogate_clk_tpm5 - Clock Gating Override Select of ipc_bus_nogate_clk_tpm5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm6_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm6_SHIFT (30U)
/*! ipc_bus_nogate_clk_tpm6 - Clock Gating Override Enable of ipc_bus_nogate_clk_tpm6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm6_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm6_SHIFT (31U)
/*! sel_ipc_bus_nogate_clk_tpm6 - Clock Gating Override Select of ipc_bus_nogate_clk_tpm6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_tpm6_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_6 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_tstmr2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_tstmr2_SHIFT (0U)
/*! ipc_bus_nogate_clk_tstmr2 - Clock Gating Override Enable of ipc_bus_nogate_clk_tstmr2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_tstmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_tstmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_tstmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_tstmr2_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_tstmr2_SHIFT (1U)
/*! sel_ipc_bus_nogate_clk_tstmr2 - Clock Gating Override Select of ipc_bus_nogate_clk_tstmr2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_tstmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_tstmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_tstmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc1_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc1_SHIFT (2U)
/*! ipc_bus_nogate_clk_usdhc1 - Clock Gating Override Enable of ipc_bus_nogate_clk_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc1_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc1_SHIFT (3U)
/*! sel_ipc_bus_nogate_clk_usdhc1 - Clock Gating Override Select of ipc_bus_nogate_clk_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc2_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc2_SHIFT (4U)
/*! ipc_bus_nogate_clk_usdhc2 - Clock Gating Override Enable of ipc_bus_nogate_clk_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc2_SHIFT (5U)
/*! sel_ipc_bus_nogate_clk_usdhc2 - Clock Gating Override Select of ipc_bus_nogate_clk_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc3_SHIFT (6U)
/*! ipc_bus_nogate_clk_usdhc3 - Clock Gating Override Enable of ipc_bus_nogate_clk_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc3_SHIFT (7U)
/*! sel_ipc_bus_nogate_clk_usdhc3 - Clock Gating Override Select of ipc_bus_nogate_clk_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n16_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n16_SHIFT (8U)
/*! ipc_bus_nogate_clk_wdg3_n16 - Clock Gating Override Enable of ipc_bus_nogate_clk_wdg3_n16 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n16(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n16_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n16_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n16_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n16_SHIFT (9U)
/*! sel_ipc_bus_nogate_clk_wdg3_n16 - Clock Gating Override Select of ipc_bus_nogate_clk_wdg3_n16 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n16(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n16_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n16_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n24_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n24_SHIFT (10U)
/*! ipc_bus_nogate_clk_wdg3_n24 - Clock Gating Override Enable of ipc_bus_nogate_clk_wdg3_n24 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n24(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n24_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg3_n24_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n24_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n24_SHIFT (11U)
/*! sel_ipc_bus_nogate_clk_wdg3_n24 - Clock Gating Override Select of ipc_bus_nogate_clk_wdg3_n24 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n24(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n24_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg3_n24_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n17_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n17_SHIFT (12U)
/*! ipc_bus_nogate_clk_wdg4_n17 - Clock Gating Override Enable of ipc_bus_nogate_clk_wdg4_n17 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n17(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n17_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n17_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n17_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n17_SHIFT (13U)
/*! sel_ipc_bus_nogate_clk_wdg4_n17 - Clock Gating Override Select of ipc_bus_nogate_clk_wdg4_n17 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n17(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n17_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n17_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n25_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n25_SHIFT (14U)
/*! ipc_bus_nogate_clk_wdg4_n25 - Clock Gating Override Enable of ipc_bus_nogate_clk_wdg4_n25 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n25(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n25_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg4_n25_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n25_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n25_SHIFT (15U)
/*! sel_ipc_bus_nogate_clk_wdg4_n25 - Clock Gating Override Select of ipc_bus_nogate_clk_wdg4_n25 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n25(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n25_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg4_n25_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n18_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n18_SHIFT (16U)
/*! ipc_bus_nogate_clk_wdg5_n18 - Clock Gating Override Enable of ipc_bus_nogate_clk_wdg5_n18 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n18(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n18_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n18_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n18_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n18_SHIFT (17U)
/*! sel_ipc_bus_nogate_clk_wdg5_n18 - Clock Gating Override Select of ipc_bus_nogate_clk_wdg5_n18 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n18(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n18_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n18_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n26_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n26_SHIFT (18U)
/*! ipc_bus_nogate_clk_wdg5_n26 - Clock Gating Override Enable of ipc_bus_nogate_clk_wdg5_n26 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n26(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n26_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_wdg5_n26_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n26_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n26_SHIFT (19U)
/*! sel_ipc_bus_nogate_clk_wdg5_n26 - Clock Gating Override Select of ipc_bus_nogate_clk_wdg5_n26 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n26(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n26_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_wdg5_n26_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_xspi_slv_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_xspi_slv_SHIFT (20U)
/*! ipc_bus_nogate_clk_xspi_slv - Clock Gating Override Enable of ipc_bus_nogate_clk_xspi_slv. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_bus_nogate_clk_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_xspi_slv_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_xspi_slv_SHIFT (21U)
/*! sel_ipc_bus_nogate_clk_xspi_slv - Clock Gating Override Select of ipc_bus_nogate_clk_xspi_slv. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_bus_nogate_clk_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_SHIFT (22U)
/*! ipc_can2_ipg_clk - Clock Gating Override Enable of ipc_can2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_SHIFT (23U)
/*! sel_ipc_can2_ipg_clk - Clock Gating Override Select of ipc_can2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_SHIFT (24U)
/*! ipc_can2_ipg_clk_pe_nogate - Clock Gating Override Enable of ipc_can2_ipg_clk_pe_nogate */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_SHIFT (25U)
/*! sel_ipc_can2_ipg_clk_pe_nogate - Clock Gating Override Select of ipc_can2_ipg_clk_pe_nogate */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_tcu_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_tcu_SHIFT (26U)
/*! ipc_can2_ipg_clk_pe_nogate_tcu - Clock Gating Override Enable of ipc_can2_ipg_clk_pe_nogate_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can2_ipg_clk_pe_nogate_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_tcu_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_tcu_SHIFT (27U)
/*! sel_ipc_can2_ipg_clk_pe_nogate_tcu - Clock Gating Override Select of ipc_can2_ipg_clk_pe_nogate_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can2_ipg_clk_pe_nogate_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_SHIFT (28U)
/*! ipc_can3_ipg_clk - Clock Gating Override Enable of ipc_can3_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_SHIFT (29U)
/*! sel_ipc_can3_ipg_clk - Clock Gating Override Select of ipc_can3_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_pe_nogate_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_pe_nogate_SHIFT (30U)
/*! ipc_can3_ipg_clk_pe_nogate - Clock Gating Override Enable of ipc_can3_ipg_clk_pe_nogate */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_pe_nogate(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_pe_nogate_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_ipc_can3_ipg_clk_pe_nogate_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_pe_nogate_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_pe_nogate_SHIFT (31U)
/*! sel_ipc_can3_ipg_clk_pe_nogate - Clock Gating Override Select of ipc_can3_ipg_clk_pe_nogate */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_pe_nogate(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_pe_nogate_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_6_sel_ipc_can3_ipg_clk_pe_nogate_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_7 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc1_SHIFT (0U)
/*! ipc_bus_nogate_clk_asrc1 - Clock Gating Override Enable of ipc_bus_nogate_clk_asrc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc1_SHIFT (1U)
/*! sel_ipc_bus_nogate_clk_asrc1 - Clock Gating Override Select of ipc_bus_nogate_clk_asrc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc2_SHIFT (2U)
/*! ipc_bus_nogate_clk_asrc2 - Clock Gating Override Enable of ipc_bus_nogate_clk_asrc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_bus_nogate_clk_asrc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc2_SHIFT (3U)
/*! sel_ipc_bus_nogate_clk_asrc2 - Clock Gating Override Select of ipc_bus_nogate_clk_asrc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_bus_nogate_clk_asrc2_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_8 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can2_osc_clk_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can2_osc_clk_SHIFT (0U)
/*! ipc_can2_osc_clk - Clock Gating Override Enable of ipc_can2_osc_clk.FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can2_osc_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can2_osc_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can2_osc_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can2_osc_clk_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can2_osc_clk_SHIFT (1U)
/*! sel_ipc_can2_osc_clk - Clock Gating Override Select of ipc_can2_osc_clk.FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can2_osc_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can2_osc_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can2_osc_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can3_osc_clk_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can3_osc_clk_SHIFT (2U)
/*! ipc_can3_osc_clk - Clock Gating Override Enable of ipc_can3_osc_clk.FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can3_osc_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can3_osc_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_can3_osc_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can3_osc_clk_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can3_osc_clk_SHIFT (3U)
/*! sel_ipc_can3_osc_clk - Clock Gating Override Select of ipc_can3_osc_clk.FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can3_osc_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can3_osc_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_can3_osc_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt2_SHIFT (6U)
/*! ipc_clkroot_24m_gpt2 - Clock Gating Override Enable of ipc_ipc_clkroot_24m_wakeupmix_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt2_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt2_SHIFT (7U)
/*! sel_ipc_clkroot_24m_gpt2 - Clock Gating Override Select of ipc_ipc_clkroot_24m_wakeupmix_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt3_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt3_SHIFT (8U)
/*! ipc_clkroot_24m_gpt3 - Clock Gating Override Enable of ipc_ipc_clkroot_24m_wakeupmix_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt3_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt3_SHIFT (9U)
/*! sel_ipc_clkroot_24m_gpt3 - Clock Gating Override Select of ipc_ipc_clkroot_24m_wakeupmix_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt4_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt4_SHIFT (10U)
/*! ipc_clkroot_24m_gpt4 - Clock Gating Override Enable of ipc_ipc_ipc_clkroot_24m_wakeupmix_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt4_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt4_SHIFT (11U)
/*! sel_ipc_clkroot_24m_gpt4 - Clock Gating Override Select of ipc_ipc_ipc_clkroot_24m_wakeupmix_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt5_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt5_SHIFT (12U)
/*! ipc_clkroot_24m_gpt5 - Clock Gating Override Enable of ipc_ipc_ipc_clkroot_24m_wakeupmix_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt5_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt5_SHIFT (13U)
/*! sel_ipc_clkroot_24m_gpt5 - Clock Gating Override Select of ipc_ipc_ipc_clkroot_24m_wakeupmix_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg3_SHIFT (18U)
/*! ipc_clkroot_24m_wdg3 - Clock Gating Override Enable of ipc_ipc_ipc_clkroot_24m_wakeupmix_wdg3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg3_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg3_SHIFT (19U)
/*! sel_ipc_clkroot_24m_wdg3 - Clock Gating Override Select of ipc_ipc_ipc_clkroot_24m_wakeupmix_wdg3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg4_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg4_SHIFT (20U)
/*! ipc_clkroot_24m_wdg4 - Clock Gating Override Enable of ipc_ipc_ipc_clkroot_24m_wakeupmix_wdg4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg4_SHIFT (21U)
/*! sel_ipc_clkroot_24m_wdg4 - Clock Gating Override Select of ipc_ipc_ipc_clkroot_24m_wakeupmix_wdg4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg5_SHIFT (22U)
/*! ipc_clkroot_24m_wdg5 - Clock Gating Override Enable of ipc_ipc_ipc_clkroot_24m_wakeupmix_wdg5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_clkroot_24m_wdg5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg5_SHIFT (23U)
/*! sel_ipc_clkroot_24m_wdg5 - Clock Gating Override Select of ipc_ipc_ipc_clkroot_24m_wakeupmix_wdg5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_clkroot_24m_wdg5_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_9 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt2_SHIFT (0U)
/*! ipc_clkroot_32k_gpt2 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt2_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt2_SHIFT (1U)
/*! sel_ipc_clkroot_32k_gpt2 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt3_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt3_SHIFT (2U)
/*! ipc_clkroot_32k_gpt3 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt3_SHIFT (3U)
/*! sel_ipc_clkroot_32k_gpt3 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt4_SHIFT (4U)
/*! ipc_clkroot_32k_gpt4 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt4_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt4_SHIFT (5U)
/*! sel_ipc_clkroot_32k_gpt4 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt5_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt5_SHIFT (6U)
/*! ipc_clkroot_32k_gpt5 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt5_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt5_SHIFT (7U)
/*! sel_ipc_clkroot_32k_gpt5 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_lptmr2_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_lptmr2_SHIFT (8U)
/*! ipc_clkroot_32k_lptmr2 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_lptmr2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_lptmr2_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_lptmr2_SHIFT (9U)
/*! sel_ipc_clkroot_32k_lptmr2 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_lptmr2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc1_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc1_SHIFT (10U)
/*! ipc_clkroot_32k_usdhc1 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc1_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc1_SHIFT (11U)
/*! sel_ipc_clkroot_32k_usdhc1 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc2_SHIFT (12U)
/*! ipc_clkroot_32k_usdhc2 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc2_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc2_SHIFT (13U)
/*! sel_ipc_clkroot_32k_usdhc2 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc3_SHIFT (14U)
/*! ipc_clkroot_32k_usdhc3 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc3_SHIFT (15U)
/*! sel_ipc_clkroot_32k_usdhc3 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg3_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg3_SHIFT (16U)
/*! ipc_clkroot_32k_wdg3 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_wdg3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg3_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg3_SHIFT (17U)
/*! sel_ipc_clkroot_32k_wdg3 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_wdg3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg4_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg4_SHIFT (18U)
/*! ipc_clkroot_32k_wdg4 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_wdg4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg4_SHIFT (19U)
/*! sel_ipc_clkroot_32k_wdg4 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_wdg4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg5_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg5_SHIFT (20U)
/*! ipc_clkroot_32k_wdg5 - Clock Gating Override Enable of ipc_ipc_clkroot_32k_wakeupmix_wdg5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_ipc_clkroot_32k_wdg5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg5_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg5_SHIFT (21U)
/*! sel_ipc_clkroot_32k_wdg5 - Clock Gating Override Select of ipc_ipc_clkroot_32k_wakeupmix_wdg5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_9_sel_ipc_clkroot_32k_wdg5_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_10 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio1_SHIFT (0U)
/*! ipc_ipc_clkroot_flexio1 - Clock Gating Override Enable of ipc_ipc_clkroot_flexio1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio1_SHIFT (1U)
/*! sel_ipc_ipc_clkroot_flexio1 - Clock Gating Override Select of ipc_ipc_clkroot_flexio1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio2_SHIFT (2U)
/*! ipc_ipc_clkroot_flexio2 - Clock Gating Override Enable of ipc_ipc_clkroot_flexio2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio2_SHIFT (3U)
/*! sel_ipc_ipc_clkroot_flexio2 - Clock Gating Override Select of ipc_ipc_clkroot_flexio2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt2_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt2_SHIFT (4U)
/*! ipc_ipc_clkroot_gpt2 - Clock Gating Override Enable of ipc_ipc_clkroot_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt2_SHIFT (5U)
/*! sel_ipc_ipc_clkroot_gpt2 - Clock Gating Override Select of ipc_ipc_clkroot_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt3_SHIFT (6U)
/*! ipc_ipc_clkroot_gpt3 - Clock Gating Override Enable of ipc_ipc_clkroot_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt3_SHIFT (7U)
/*! sel_ipc_ipc_clkroot_gpt3 - Clock Gating Override Select of ipc_ipc_clkroot_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt4_SHIFT (8U)
/*! ipc_ipc_clkroot_gpt4 - Clock Gating Override Enable of ipc_ipc_clkroot_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt4_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt4_SHIFT (9U)
/*! sel_ipc_ipc_clkroot_gpt4 - Clock Gating Override Select of ipc_ipc_clkroot_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt5_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt5_SHIFT (10U)
/*! ipc_ipc_clkroot_gpt5 - Clock Gating Override Enable of ipc_ipc_clkroot_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt5_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt5_SHIFT (11U)
/*! sel_ipc_ipc_clkroot_gpt5 - Clock Gating Override Select of ipc_ipc_clkroot_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c3_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c3_SHIFT (12U)
/*! ipc_ipc_clkroot_lpi2c3 - Clock Gating Override Enable of ipc_ipc_clkroot_lpi2c3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c3_SHIFT (13U)
/*! sel_ipc_ipc_clkroot_lpi2c3 - Clock Gating Override Select of ipc_ipc_clkroot_lpi2c3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c4_SHIFT (14U)
/*! ipc_ipc_clkroot_lpi2c4 - Clock Gating Override Enable of ipc_ipc_clkroot_lpi2c4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c4_SHIFT (15U)
/*! sel_ipc_ipc_clkroot_lpi2c4 - Clock Gating Override Select of ipc_ipc_clkroot_lpi2c4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c5_SHIFT (16U)
/*! ipc_ipc_clkroot_lpi2c5 - Clock Gating Override Enable of ipc_ipc_clkroot_lpi2c5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c5_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c5_SHIFT (17U)
/*! sel_ipc_ipc_clkroot_lpi2c5 - Clock Gating Override Select of ipc_ipc_clkroot_lpi2c5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c6_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c6_SHIFT (18U)
/*! ipc_ipc_clkroot_lpi2c6 - Clock Gating Override Enable of ipc_ipc_clkroot_lpi2c6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c6_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c6_SHIFT (19U)
/*! sel_ipc_ipc_clkroot_lpi2c6 - Clock Gating Override Select of ipc_ipc_clkroot_lpi2c6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c7_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c7_SHIFT (20U)
/*! ipc_ipc_clkroot_lpi2c7 - Clock Gating Override Enable of ipc_ipc_clkroot_lpi2c7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c7_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c7_SHIFT (21U)
/*! sel_ipc_ipc_clkroot_lpi2c7 - Clock Gating Override Select of ipc_ipc_clkroot_lpi2c7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c8_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c8_SHIFT (22U)
/*! ipc_ipc_clkroot_lpi2c8 - Clock Gating Override Enable of ipc_ipc_clkroot_lpi2c8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c8_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c8_SHIFT (23U)
/*! sel_ipc_ipc_clkroot_lpi2c8 - Clock Gating Override Select of ipc_ipc_clkroot_lpi2c8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi3_SHIFT (24U)
/*! ipc_ipc_clkroot_lpspi3 - Clock Gating Override Enable of ipc_ipc_clkroot_lpspi3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi3_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi3_SHIFT (25U)
/*! sel_ipc_ipc_clkroot_lpspi3 - Clock Gating Override Select of ipc_ipc_clkroot_lpspi3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi4_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi4_SHIFT (26U)
/*! ipc_ipc_clkroot_lpspi4 - Clock Gating Override Enable of ipc_ipc_clkroot_lpspi4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi4_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi4_SHIFT (27U)
/*! sel_ipc_ipc_clkroot_lpspi4 - Clock Gating Override Select of ipc_ipc_clkroot_lpspi4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi5_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi5_SHIFT (28U)
/*! ipc_ipc_clkroot_lpspi5 - Clock Gating Override Enable of ipc_ipc_clkroot_lpspi5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi5_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi5_SHIFT (29U)
/*! sel_ipc_ipc_clkroot_lpspi5 - Clock Gating Override Select of ipc_ipc_clkroot_lpspi5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi6_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi6_SHIFT (30U)
/*! ipc_ipc_clkroot_lpspi6 - Clock Gating Override Enable of ipc_ipc_clkroot_lpspi6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_ipc_ipc_clkroot_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi6_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi6_SHIFT (31U)
/*! sel_ipc_ipc_clkroot_lpspi6 - Clock Gating Override Select of ipc_ipc_clkroot_lpspi6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_10_sel_ipc_ipc_clkroot_lpspi6_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_11 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi7_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi7_SHIFT (0U)
/*! ipc_ipc_clkroot_lpspi7 - Clock Gating Override Enable of ipc_ipc_clkroot_lpspi7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi7_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi7_SHIFT (1U)
/*! sel_ipc_ipc_clkroot_lpspi7 - Clock Gating Override Select of ipc_ipc_clkroot_lpspi7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi8_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi8_SHIFT (2U)
/*! ipc_ipc_clkroot_lpspi8 - Clock Gating Override Enable of ipc_ipc_clkroot_lpspi8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi8_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi8_SHIFT (3U)
/*! sel_ipc_ipc_clkroot_lpspi8 - Clock Gating Override Select of ipc_ipc_clkroot_lpspi8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart3_SHIFT (4U)
/*! ipc_ipc_clkroot_lpuart3 - Clock Gating Override Enable of ipc_ipc_clkroot_lpuart3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart3_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart3_SHIFT (5U)
/*! sel_ipc_ipc_clkroot_lpuart3 - Clock Gating Override Select of ipc_ipc_clkroot_lpuart3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart4_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart4_SHIFT (6U)
/*! ipc_ipc_clkroot_lpuart4 - Clock Gating Override Enable of ipc_ipc_clkroot_lpuart4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart4_SHIFT (7U)
/*! sel_ipc_ipc_clkroot_lpuart4 - Clock Gating Override Select of ipc_ipc_clkroot_lpuart4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart5_SHIFT (8U)
/*! ipc_ipc_clkroot_lpuart5 - Clock Gating Override Enable of ipc_ipc_clkroot_lpuart5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart5_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart5_SHIFT (9U)
/*! sel_ipc_ipc_clkroot_lpuart5 - Clock Gating Override Select of ipc_ipc_clkroot_lpuart5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart6_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart6_SHIFT (10U)
/*! ipc_ipc_clkroot_lpuart6 - Clock Gating Override Enable of ipc_ipc_clkroot_lpuart6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart6_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart6_SHIFT (11U)
/*! sel_ipc_ipc_clkroot_lpuart6 - Clock Gating Override Select of ipc_ipc_clkroot_lpuart6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart7_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart7_SHIFT (12U)
/*! ipc_ipc_clkroot_lpuart7 - Clock Gating Override Enable of ipc_ipc_clkroot_lpuart7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart7_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart7_SHIFT (13U)
/*! sel_ipc_ipc_clkroot_lpuart7 - Clock Gating Override Select of ipc_ipc_clkroot_lpuart7 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart7_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart7_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart8_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart8_SHIFT (14U)
/*! ipc_ipc_clkroot_lpuart8 - Clock Gating Override Enable of ipc_ipc_clkroot_lpuart8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lpuart8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart8_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart8_SHIFT (15U)
/*! sel_ipc_ipc_clkroot_lpuart8 - Clock Gating Override Select of ipc_ipc_clkroot_lpuart8 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart8_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lpuart8_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lptmr2_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lptmr2_SHIFT (16U)
/*! ipc_ipc_clkroot_lptmr2 - Clock Gating Override Enable of ipc_ipc_clkroot_lptmr2. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lptmr2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lptmr2_SHIFT (17U)
/*! sel_ipc_ipc_clkroot_lptmr2 - Clock Gating Override Select of ipc_ipc_clkroot_lptmr2. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_i3c2_slow_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_i3c2_slow_SHIFT (18U)
/*! ipc_ipc_clkroot_i3c2_slow - Clock Gating Override Enable of ipc_ipc_clkroot_i3c2_slow */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_i3c2_slow(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_i3c2_slow_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_i3c2_slow_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_i3c2_slow_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_i3c2_slow_SHIFT (19U)
/*! sel_ipc_ipc_clkroot_i3c2_slow - Clock Gating Override Select of ipc_ipc_clkroot_i3c2_slow */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_i3c2_slow(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_i3c2_slow_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_i3c2_slow_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm4_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm4_SHIFT (20U)
/*! ipc_ipc_clkroot_tpm4 - Clock Gating Override Enable of ipc_ipc_clkroot_tpm4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm4_SHIFT (21U)
/*! sel_ipc_ipc_clkroot_tpm4 - Clock Gating Override Select of ipc_ipc_clkroot_tpm4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm5_SHIFT (22U)
/*! ipc_ipc_clkroot_tpm5 - Clock Gating Override Enable of ipc_ipc_clkroot_tpm5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm5_SHIFT (23U)
/*! sel_ipc_ipc_clkroot_tpm5 - Clock Gating Override Select of ipc_ipc_clkroot_tpm5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm6_SHIFT (24U)
/*! ipc_ipc_clkroot_tpm6 - Clock Gating Override Enable of ipc_ipc_clkroot_tpm6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_ipc_clkroot_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm6_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm6_SHIFT (25U)
/*! sel_ipc_ipc_clkroot_tpm6 - Clock Gating Override Select of ipc_ipc_clkroot_tpm6 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_ipc_clkroot_tpm6_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_12 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi_slv_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi_slv_SHIFT (0U)
/*! ipc_ipc_clkroot_xspi_slv - Clock Gating Override Enable of ipc_ipc_clkroot_xspi_slv */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi_slv_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi_slv_SHIFT (1U)
/*! sel_ipc_ipc_clkroot_xspi_slv - Clock Gating Override Select of ipc_ipc_clkroot_xspi_slv */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_tcu_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_tcu_SHIFT (2U)
/*! ipc_ipc_clkroot_xspi1_tcu - Clock Gating Override Enable of ipc_ipc_clkroot_xspi1_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_tcu_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_tcu_SHIFT (3U)
/*! sel_ipc_ipc_clkroot_xspi1_tcu - Clock Gating Override Select of ipc_ipc_clkroot_xspi1_tcu */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_tcu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_tcu_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_tcu_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_glue_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_glue_SHIFT (4U)
/*! ipc_ipc_clkroot_xspi1_glue - Clock Gating Override Enable of ipc_ipc_clkroot_xspi1_glue */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_glue(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_glue_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipc_clkroot_xspi1_glue_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_glue_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_glue_SHIFT (5U)
/*! sel_ipc_ipc_clkroot_xspi1_glue - Clock Gating Override Select of ipc_ipc_clkroot_xspi1_glue */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_glue(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_glue_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipc_clkroot_xspi1_glue_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt2_SHIFT (6U)
/*! ipc_ipp_clk_gpt2 - Clock Gating Override Enable of ipc_ipp_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt2_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt2_SHIFT (7U)
/*! sel_ipc_ipp_clk_gpt2 - Clock Gating Override Select of ipc_ipp_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt3_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt3_SHIFT (8U)
/*! ipc_ipp_clk_gpt3 - Clock Gating Override Enable of ipc_ipp_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt3_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt3_SHIFT (9U)
/*! sel_ipc_ipp_clk_gpt3 - Clock Gating Override Select of ipc_ipp_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt4_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt4_SHIFT (10U)
/*! ipc_ipp_clk_gpt4 - Clock Gating Override Enable of ipc_ipp_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt4_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt4_SHIFT (11U)
/*! sel_ipc_ipp_clk_gpt4 - Clock Gating Override Select of ipc_ipp_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt5_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt5_SHIFT (12U)
/*! ipc_ipp_clk_gpt5 - Clock Gating Override Enable of ipc_ipp_clk_gpt5. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_ipp_clk_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt5_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt5_SHIFT (13U)
/*! sel_ipc_ipp_clk_gpt5 - Clock Gating Override Select of ipc_ipp_clk_gpt5. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_ipp_clk_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_1_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_1_SHIFT (14U)
/*! ipc_sai3_mclk_1 - Clock Gating Override Enable of ipc_sai3_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_1_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_1_SHIFT (15U)
/*! sel_ipc_sai3_mclk_1 - Clock Gating Override Select of ipc_sai3_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_2_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_2_SHIFT (16U)
/*! ipc_sai3_mclk_2 - Clock Gating Override Enable of ipc_sai3_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_2_SHIFT (17U)
/*! sel_ipc_sai3_mclk_2 - Clock Gating Override Select of ipc_sai3_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_3_SHIFT (18U)
/*! ipc_sai3_mclk_3 - Clock Gating Override Enable of ipc_sai3_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai3_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_3_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_3_SHIFT (19U)
/*! sel_ipc_sai3_mclk_3 - Clock Gating Override Select of ipc_sai3_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai3_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_1_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_1_SHIFT (20U)
/*! ipc_sai4_mclk_1 - Clock Gating Override Enable of ipc_sai4_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_1_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_1_SHIFT (21U)
/*! sel_ipc_sai4_mclk_1 - Clock Gating Override Select of ipc_sai4_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_SHIFT (22U)
/*! ipc_sai4_mclk_2 - Clock Gating Override Enable of ipc_sai4_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_SHIFT (23U)
/*! sel_ipc_sai4_mclk_2 - Clock Gating Override Select of ipc_sai4_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_SHIFT (24U)
/*! ipc_sai4_mclk_3 - Clock Gating Override Enable of ipc_sai4_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_SHIFT (25U)
/*! sel_ipc_sai4_mclk_3 - Clock Gating Override Select of ipc_sai4_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_1_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_1_SHIFT (26U)
/*! ipc_sai5_mclk_1 - Clock Gating Override Enable of ipc_sai5_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_1_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_1_SHIFT (27U)
/*! sel_ipc_sai5_mclk_1 - Clock Gating Override Select of ipc_sai5_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_2_SHIFT (28U)
/*! ipc_sai5_mclk_2 - Clock Gating Override Enable of ipc_sai5_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_2_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_2_SHIFT (29U)
/*! sel_ipc_sai5_mclk_2 - Clock Gating Override Select of ipc_sai5_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_3_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_3_SHIFT (30U)
/*! ipc_sai5_mclk_3 - Clock Gating Override Enable of ipc_sai5_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai5_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_3_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_3_SHIFT (31U)
/*! sel_ipc_sai5_mclk_3 - Clock Gating Override Select of ipc_sai5_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai5_mclk_3_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_13 - ipc_clk clock Gating Override Controls force_on_off and force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_audmix_ipg_clk_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_audmix_ipg_clk_SHIFT (0U)
/*! ipc_audmix_ipg_clk - Clock Gating Override Enable of ipc_audmix_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_audmix_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_audmix_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_audmix_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_audmix_ipg_clk_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_audmix_ipg_clk_SHIFT (1U)
/*! sel_ipc_audmix_ipg_clk - Clock Gating Override Select of ipc_audmix_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_audmix_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_audmix_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_audmix_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll1_ipg_clk_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll1_ipg_clk_SHIFT (2U)
/*! ipc_asrc1_aud_pll1_ipg_clk - Clock Gating Override Enable of ipc_asrc1_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll1_ipg_clk_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll1_ipg_clk_SHIFT (3U)
/*! sel_ipc_asrc1_aud_pll1_ipg_clk - Clock Gating Override Select of ipc_asrc1_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll2_ipg_clk_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll2_ipg_clk_SHIFT (4U)
/*! ipc_asrc1_aud_pll2_ipg_clk - Clock Gating Override Enable of ipc_asrc1_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc1_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll2_ipg_clk_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll2_ipg_clk_SHIFT (5U)
/*! sel_ipc_asrc1_aud_pll2_ipg_clk - Clock Gating Override Select of ipc_asrc1_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc1_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll1_ipg_clk_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll1_ipg_clk_SHIFT (6U)
/*! ipc_asrc2_aud_pll1_ipg_clk - Clock Gating Override Enable of ipc_asrc2_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll1_ipg_clk_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll1_ipg_clk_SHIFT (7U)
/*! sel_ipc_asrc2_aud_pll1_ipg_clk - Clock Gating Override Select of ipc_asrc2_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll2_ipg_clk_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll2_ipg_clk_SHIFT (8U)
/*! ipc_asrc2_aud_pll2_ipg_clk - Clock Gating Override Enable of ipc_asrc2_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_asrc2_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll2_ipg_clk_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll2_ipg_clk_SHIFT (9U)
/*! sel_ipc_asrc2_aud_pll2_ipg_clk - Clock Gating Override Select of ipc_asrc2_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_asrc2_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_swo_trace_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_swo_trace_SHIFT (10U)
/*! ipc_ipc_clkroot_swo_trace - Clock Gating Override Enable of ipc_ipc_clkroot_swo_trace */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_swo_trace(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_swo_trace_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_swo_trace_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_swo_trace_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_swo_trace_SHIFT (11U)
/*! sel_ipc_ipc_clkroot_swo_trace - Clock Gating Override Select of ipc_ipc_clkroot_swo_trace */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_swo_trace(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_swo_trace_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_swo_trace_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_mipi_test_byte_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_mipi_test_byte_SHIFT (12U)
/*! ipc_ipc_clkroot_mipi_test_byte - Clock Gating Override Enable of ipc_ipc_clkroot_mipi_test_byte */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_mipi_test_byte(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_mipi_test_byte_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_mipi_test_byte_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_mipi_test_byte_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_mipi_test_byte_SHIFT (13U)
/*! sel_ipc_ipc_clkroot_mipi_test_byte - Clock Gating Override Select of ipc_ipc_clkroot_mipi_test_byte */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_mipi_test_byte(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_mipi_test_byte_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_mipi_test_byte_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc1_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc1_SHIFT (14U)
/*! ipc_ipc_clkroot_usdhc1 - Clock Gating Override Enable of ipc_ipc_clkroot_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc1_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc1_SHIFT (15U)
/*! sel_ipc_ipc_clkroot_usdhc1 - Clock Gating Override Select of ipc_ipc_clkroot_usdhc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc2_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc2_SHIFT (16U)
/*! ipc_ipc_clkroot_usdhc2 - Clock Gating Override Enable of ipc_ipc_clkroot_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc2_SHIFT (17U)
/*! sel_ipc_ipc_clkroot_usdhc2 - Clock Gating Override Select of ipc_ipc_clkroot_usdhc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc3_SHIFT (18U)
/*! ipc_ipc_clkroot_usdhc3 - Clock Gating Override Enable of ipc_ipc_clkroot_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_ipc_clkroot_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc3_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc3_SHIFT (19U)
/*! sel_ipc_ipc_clkroot_usdhc3 - Clock Gating Override Select of ipc_ipc_clkroot_usdhc3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_ipc_clkroot_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_test_50m_scan_clk_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_test_50m_scan_clk_SHIFT (20U)
/*! ipc_test_50m_scan_clk - Clock Gating Override Enable of ipc_test_50m_scan_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_test_50m_scan_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_test_50m_scan_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_ipc_test_50m_scan_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_test_50m_scan_clk_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_test_50m_scan_clk_SHIFT (21U)
/*! sel_ipc_test_50m_scan_clk - Clock Gating Override Select of ipc_test_50m_scan_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_test_50m_scan_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_test_50m_scan_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_13_sel_ipc_test_50m_scan_clk_MASK)
/*! @} */

/*! @name GPT_IPP_IND_CAPIN1_MUX_CTRL - GPT ipp_ind_capin1 MUX Control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_SHIFT (0U)
/*! gpt2 - Output Signal Select for ipp_ind_capin1 Input of GPT2
 *  0b000..tmr1_1588_alarm1
 *  0b001..tmr1_1588_alarm2
 *  0b010..tmr1_1588_pp1
 *  0b011..tmr1_1588_pp2
 *  0b100..tmr1_1588_pp3
 *  0b101..ipp_ind_gpt2_capin1
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_SHIFT (4U)
/*! gpt3 - Output Signal Select for ipp_ind_capin1 Input of GPT3
 *  0b000..tmr1_1588_alarm1
 *  0b001..tmr1_1588_alarm2
 *  0b010..tmr1_1588_pp1
 *  0b011..tmr1_1588_pp2
 *  0b100..tmr1_1588_pp3
 *  0b101..ipp_ind_gpt3_capin1
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_SHIFT (8U)
/*! gpt4 - Output Signal Select for ipp_ind_capin1 Input of GPT4
 *  0b000..tmr1_1588_alarm1
 *  0b001..tmr1_1588_alarm2
 *  0b010..tmr1_1588_pp1
 *  0b011..tmr1_1588_pp2
 *  0b100..tmr1_1588_pp3
 *  0b101..ipp_ind_gpt4_capin1
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_SHIFT (12U)
/*! gpt5 - Output Signal Select for ipp_ind_capin1 Input of GPT5
 *  0b000..tmr1_1588_alarm1
 *  0b001..tmr1_1588_alarm2
 *  0b010..tmr1_1588_pp1
 *  0b011..tmr1_1588_pp2
 *  0b100..tmr1_1588_pp3
 *  0b101..ipp_ind_gpt5_capin1
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_MASK)
/*! @} */

/*! @name GPT_IPP_IND_CAPIN2_MUX_CTRL - GPT ipp_ind_capin2 MUX Control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_SHIFT (0U)
/*! gpt2 - Output Signal Select for ipp_ind_capin2 Input of GPT2
 *  0b00..usb1_sof
 *  0b01..usb2_sof
 *  0b10..Restricted
 *  0b11..ipp_ind_gpt2_capin2
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_MASK (0xCU)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_SHIFT (2U)
/*! gpt3 - Output Signal Select for ipp_ind_capin2 Input of GPT3
 *  0b00..usb1_sof
 *  0b01..usb2_sof
 *  0b10..Restricted
 *  0b11..ipp_ind_gpt3_capin2
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_MASK (0x30U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_SHIFT (4U)
/*! gpt4 - Output Signal Select for ipp_ind_capin2 Input of GPT4
 *  0b00..usb1_sof
 *  0b01..usb2_sof
 *  0b10..Restricted
 *  0b11..ipp_ind_gpt4_capin2
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_MASK (0xC0U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_SHIFT (6U)
/*! gpt5 - Output Signal Select for ipp_ind_capin2 Input of GPT5
 *  0b00..usb1_sof
 *  0b01..usb2_sof
 *  0b10..Restricted
 *  0b11..ipp_ind_gpt5_capin2
 */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_MASK)
/*! @} */

/*! @name GPT2_IPP_IND_CLKIN_CLK - GPT2 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - Output Signal Select for clkin Pin of GPT2
 *  0b00000..SAI1_CLK_ROOT
 *  0b00001..SAI2_CLK_ROOT
 *  0b00010..SAI3_CLK_ROOT
 *  0b00011..SAI4_CLK_ROOT
 *  0b00100..SAI5_CLK_ROOT
 *  0b01000..SAI1.MCLK
 *  0b01001..SAI2.MCLK
 *  0b01010..SAI3.MCLK
 *  0b01011..SAI4.MCLK
 *  0b01100..SAI5.MCLK
 *  0b10000..SAI1.RXBCLK
 *  0b10001..SAI2.RXBCLK
 *  0b10010..SAI3.RXBCLK
 *  0b10011..SAI4.RXBCLK
 *  0b10100..SAI5.RXBCLK
 *  0b11000..SAI1.TXBCLK
 *  0b11001..SAI2.TXBCLK
 *  0b11010..SAI3.TXBCLK
 *  0b11011..SAI4.TXBCLK
 *  0b11100..SAI5.TXBCLK
 *  0b11111..IPP_IND_GPT2_CLKIN
 */
#define BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT3_IPP_IND_CLKIN_CLK - GPT3 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - Output Signal Select for clkin Pin of GPT3
 *  0b00000..SAI1_CLK_ROOT
 *  0b00001..SAI2_CLK_ROOT
 *  0b00010..SAI3_CLK_ROOT
 *  0b00011..SAI4_CLK_ROOT
 *  0b00100..SAI5_CLK_ROOT
 *  0b01000..SAI1.MCLK
 *  0b01001..SAI2.MCLK
 *  0b01010..SAI3.MCLK
 *  0b01011..SAI4.MCLK
 *  0b01100..SAI5.MCLK
 *  0b10000..SAI1.RXBCLK
 *  0b10001..SAI2.RXBCLK
 *  0b10010..SAI3.RXBCLK
 *  0b10011..SAI4.RXBCLK
 *  0b10100..SAI5.RXBCLK
 *  0b11000..SAI1.TXBCLK
 *  0b11001..SAI2.TXBCLK
 *  0b11010..SAI3.TXBCLK
 *  0b11011..SAI4.TXBCLK
 *  0b11100..SAI5.TXBCLK
 *  0b11111..IPP_IND_GPT3_CLKIN
 */
#define BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT4_IPP_IND_CLKIN_CLK - GPT4 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - Output Signal Select for clkin Pin of GPT4
 *  0b00000..SAI1_CLK_ROOT
 *  0b00001..SAI2_CLK_ROOT
 *  0b00010..SAI3_CLK_ROOT
 *  0b00011..SAI4_CLK_ROOT
 *  0b00100..SAI5_CLK_ROOT
 *  0b01000..SAI1.MCLK
 *  0b01001..SAI2.MCLK
 *  0b01010..SAI3.MCLK
 *  0b01011..SAI4.MCLK
 *  0b01100..SAI5.MCLK
 *  0b10000..SAI1.RXBCLK
 *  0b10001..SAI2.RXBCLK
 *  0b10010..SAI3.RXBCLK
 *  0b10011..SAI4.RXBCLK
 *  0b10100..SAI5.RXBCLK
 *  0b11000..SAI1.TXBCLK
 *  0b11001..SAI2.TXBCLK
 *  0b11010..SAI3.TXBCLK
 *  0b11011..SAI4.TXBCLK
 *  0b11100..SAI5.TXBCLK
 *  0b11111..IPP_IND_GPT4_CLKIN
 */
#define BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT5_IPP_IND_CLKIN_CLK - GPT5 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - Output Signal Select for clkin Pin of GPT5
 *  0b00000..SAI1_CLK_ROOT
 *  0b00001..SAI2_CLK_ROOT
 *  0b00010..SAI3_CLK_ROOT
 *  0b00011..SAI4_CLK_ROOT
 *  0b00100..SAI5_CLK_ROOT
 *  0b01000..SAI1.MCLK
 *  0b01001..SAI2.MCLK
 *  0b01010..SAI3.MCLK
 *  0b01011..SAI4.MCLK
 *  0b01100..SAI5.MCLK
 *  0b10000..SAI1.RXBCLK
 *  0b10001..SAI2.RXBCLK
 *  0b10010..SAI3.RXBCLK
 *  0b10011..SAI4.RXBCLK
 *  0b10100..SAI5.RXBCLK
 *  0b11000..SAI1.TXBCLK
 *  0b11001..SAI2.TXBCLK
 *  0b11010..SAI3.TXBCLK
 *  0b11011..SAI4.TXBCLK
 *  0b11100..SAI5.TXBCLK
 *  0b11111..IPP_IND_GPT5_CLKIN_
 */
#define BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT2_3_4_5 - GPT PIN MUX */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_MASK (0xFFFU)
#define BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_SHIFT (0U)
/*! pinmux_sel - Output Signal Select for External I/O of GPT */
#define BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_MASK)
/*! @} */

/*! @name ASRC_MCLKOUT_MUX - ASRC MCLKOUT MUX */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_0_sel_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_0_sel_SHIFT (0U)
/*! asrc1_mclkout_0_sel - Output Signal for ASRC 1 MCLKOUT 0 Select
 *  0b000..sai1_ipp_do_sai_mclk
 *  0b001..sai2_ipp_do_sai_mclk
 *  0b010..sai3_ipp_do_sai_mclk
 *  0b011..sai4_ipp_do_sai_mclk
 *  0b100..sai5_ipp_do_sai_mclk
 */
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_0_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_0_sel_SHIFT)) & BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_0_sel_MASK)

#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_1_sel_MASK (0x38U)
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_1_sel_SHIFT (3U)
/*! asrc1_mclkout_1_sel - Output Signal for ASRC 1 MCLKOUT 1 Select
 *  0b000..sai1_ipp_do_sai_mclk
 *  0b001..sai2_ipp_do_sai_mclk
 *  0b010..sai3_ipp_do_sai_mclk
 *  0b011..sai4_ipp_do_sai_mclk
 *  0b100..sai5_ipp_do_sai_mclk
 */
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_1_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_1_sel_SHIFT)) & BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc1_mclkout_1_sel_MASK)

#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_0_sel_MASK (0x1C0U)
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_0_sel_SHIFT (6U)
/*! asrc2_mclkout_0_sel - Output Signal for ASRC 2 MCLKOUT 0 Select
 *  0b000..sai1_ipp_do_sai_mclk
 *  0b001..sai2_ipp_do_sai_mclk
 *  0b010..sai3_ipp_do_sai_mclk
 *  0b011..sai4_ipp_do_sai_mclk
 *  0b100..sai5_ipp_do_sai_mclk
 */
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_0_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_0_sel_SHIFT)) & BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_0_sel_MASK)

#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_1_sel_MASK (0xE00U)
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_1_sel_SHIFT (9U)
/*! asrc2_mclkout_1_sel - Output Signal for ASRC 2 MCLKOUT 1 Select
 *  0b000..sai1_ipp_do_sai_mclk
 *  0b001..sai2_ipp_do_sai_mclk
 *  0b010..sai3_ipp_do_sai_mclk
 *  0b011..sai4_ipp_do_sai_mclk
 *  0b100..sai5_ipp_do_sai_mclk
 */
#define BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_1_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_1_sel_SHIFT)) & BLK_CTRL_WAKEUPMIX_ASRC_MCLKOUT_MUX_asrc2_mclkout_1_sel_MASK)
/*! @} */

/*! @name BYPASS_AUDMIX_IP_CTRL - BYPASS_AUDMIX_IP_CTRL */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_BYPASS_AUDMIX_IP_CTRL_audmix_mode_sel_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_BYPASS_AUDMIX_IP_CTRL_audmix_mode_sel_SHIFT (0U)
/*! audmix_mode_sel - AUDMIX Mode Select
 *  0b0..Bypass AUDMIX; sai3_ipp_do_sai_txbclk/sai3_ipp_do_sai_txsync/sai3_ipp_do_sai_txdata.
 *  0b1..AUDMIX mode; sai3_ipp_do_sai_txbclk/sai3_ipp_do_sai_txsync/sai3_ipp_do_sai_txdata.
 */
#define BLK_CTRL_WAKEUPMIX_BYPASS_AUDMIX_IP_CTRL_audmix_mode_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_BYPASS_AUDMIX_IP_CTRL_audmix_mode_sel_SHIFT)) & BLK_CTRL_WAKEUPMIX_BYPASS_AUDMIX_IP_CTRL_audmix_mode_sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_WAKEUPMIX_H_ */

