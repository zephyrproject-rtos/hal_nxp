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
**         CMSIS Peripheral Access Layer for CORTEXA_BLK_CTRL
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
 * @file PERI_CORTEXA_BLK_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CORTEXA_BLK_CTRL
 *
 * CMSIS Peripheral Access Layer for CORTEXA_BLK_CTRL
 */

#if !defined(PERI_CORTEXA_BLK_CTRL_H_)
#define PERI_CORTEXA_BLK_CTRL_H_                 /**< Symbol preventing repeated inclusion */

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
   -- CORTEXA_BLK_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORTEXA_BLK_CTRL_Peripheral_Access_Layer CORTEXA_BLK_CTRL Peripheral Access Layer
 * @{
 */

/** CORTEXA_BLK_CTRL - Register Layout Typedef */
typedef struct {
  __I  uint32_t STA_CLUSTER_PCH;                   /**< Cluster P-channel Protocol Bits Status, offset: 0x0 */
  __I  uint32_t STA_CORE_0_1_PCH;                  /**< Core0 and Core1 P-channel Protocol Bits Status, offset: 0x4 */
  __I  uint32_t STA_CORE_2_3_PCH;                  /**< Core2 and Core3 P-channel Protocol Bits Status, offset: 0x8 */
       uint8_t RESERVED_0[36];
  __IO uint32_t LPCG_FORCE_0;                      /**< LPCG Force ON OFF Control 0, offset: 0x30 */
  __IO uint32_t LPCG_FORCE_1;                      /**< LPCG Force ON OFFC Control 1, offset: 0x34 */
  __IO uint32_t LPCG_FORCE_SEL_0;                  /**< LPCG Force ON OFF Control Select 0, offset: 0x38 */
  __IO uint32_t LPCG_FORCE_SEL_1;                  /**< LPCG Force ON OFF Control Select 1, offset: 0x3C */
} CORTEXA_BLK_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- CORTEXA_BLK_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORTEXA_BLK_CTRL_Register_Masks CORTEXA_BLK_CTRL Register Masks
 * @{
 */

/*! @name STA_CLUSTER_PCH - Cluster P-channel Protocol Bits Status */
/*! @{ */

#define CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PACTIVE_MASK (0xFFU)
#define CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PACTIVE_SHIFT (0U)
/*! CLUSTER_PACTIVE - Cluster P-channel PACTIVE Bits Status
 *  0b00000000..Indicates the target is inactive
 *  0b00000001..Indicates the target is active
 */
#define CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PACTIVE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PACTIVE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PACTIVE_MASK)

#define CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PSTATE_MASK (0x7F00U)
#define CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PSTATE_SHIFT (8U)
/*! CLUSTER_PSTATE - Cluster P-channel PSTATE Bits Status */
#define CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PSTATE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PSTATE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CLUSTER_PCH_CLUSTER_PSTATE_MASK)
/*! @} */

/*! @name STA_CORE_0_1_PCH - Core0 and Core1 P-channel Protocol Bits Status */
/*! @{ */

#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PACTIVE_MASK (0x1FU)
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PACTIVE_SHIFT (0U)
/*! CORE0_PACTIVE - Core0 P-channel PACTIVE Bits Status
 *  0b00000..Indicates the target is inactive
 *  0b00001..Indicates the target is active
 */
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PACTIVE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PACTIVE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PACTIVE_MASK)

#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PSTATE_MASK (0x3F00U)
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PSTATE_SHIFT (8U)
/*! CORE0_PSTATE - Core0 P-channel PSTATE Bits Status */
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PSTATE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PSTATE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE0_PSTATE_MASK)

#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PACTIVE_MASK (0x1F0000U)
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PACTIVE_SHIFT (16U)
/*! CORE1_PACTIVE - Core1 P-channel PACTIVE Bits Status
 *  0b00000..Indicates the target is inactive
 *  0b00001..Indicates the target is active
 */
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PACTIVE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PACTIVE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PACTIVE_MASK)

#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PSTATE_MASK (0x3F000000U)
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PSTATE_SHIFT (24U)
/*! CORE1_PSTATE - Core1 P-channel PSTATE Bits Status */
#define CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PSTATE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PSTATE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_0_1_PCH_CORE1_PSTATE_MASK)
/*! @} */

/*! @name STA_CORE_2_3_PCH - Core2 and Core3 P-channel Protocol Bits Status */
/*! @{ */

#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PACTIVE_MASK (0x1FU)
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PACTIVE_SHIFT (0U)
/*! CORE2_PACTIVE - Core2 P-channel PACTIVE Bits Status
 *  0b00000..Indicates the target is inactive
 *  0b00001..Indicates the target is active
 */
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PACTIVE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PACTIVE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PACTIVE_MASK)

#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PSTATE_MASK (0x3F00U)
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PSTATE_SHIFT (8U)
/*! CORE2_PSTATE - Core2 P-channel PSTATE Bits Status */
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PSTATE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PSTATE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE2_PSTATE_MASK)

#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PACTIVE_MASK (0x1F0000U)
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PACTIVE_SHIFT (16U)
/*! CORE3_PACTIVE - Core3 P-channel PACTIVE bits
 *  0b00000..Indicates the target is inactive
 *  0b00001..Indicates the target is active
 */
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PACTIVE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PACTIVE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PACTIVE_MASK)

#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PSTATE_MASK (0x3F000000U)
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PSTATE_SHIFT (24U)
/*! CORE3_PSTATE - Core3 P-channel PSTATE Bits Status */
#define CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PSTATE(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PSTATE_SHIFT)) & CORTEXA_BLK_CTRL_STA_CORE_2_3_PCH_CORE3_PSTATE_MASK)
/*! @} */

/*! @name LPCG_FORCE_0 - LPCG Force ON OFF Control 0 */
/*! @{ */

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_sclk_MASK (0x1U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_sclk_SHIFT (0U)
/*! ipc_clk_sclk - Force ON OFF of ipc_clk_sclk
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_sclk(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_sclk_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_sclk_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_at_MASK (0x4U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_at_SHIFT (2U)
/*! ipc_clk_arm_a55_at - Force ON OFF of ipc_clk_arm_a55_at
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_at(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_at_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_at_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_gic_MASK (0x8U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_gic_SHIFT (3U)
/*! ipc_clk_arm_a55_gic - Force ON OFF of ipc_clk_arm_a55_gic
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_gic(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_gic_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_gic_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_periph_MASK (0x10U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_periph_SHIFT (4U)
/*! ipc_clk_arm_a55_periph - Force ON OFF of ipc_clk_arm_a55_periph
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_periph(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_periph_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_periph_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_p_MASK (0x20U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_p_SHIFT (5U)
/*! ipc_clk_arm_a55_p - Force ON OFF of ipc_clk_arm_a55_p
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_p(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_p_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_arm_a55_p_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk0_MASK (0x40U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk0_SHIFT (6U)
/*! ipc_clk_coreclk0 - Force ON OFF of ipc_clk_coreclk0
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk0(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk0_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk0_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk1_MASK (0x80U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk1_SHIFT (7U)
/*! ipc_clk_coreclk1 - Force ON OFF of ipc_clk_coreclk1
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk1(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk1_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk1_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk2_MASK (0x100U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk2_SHIFT (8U)
/*! ipc_clk_coreclk2 - Force ON OFF of ipc_clk_coreclk2
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk2(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk2_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk2_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk3_MASK (0x200U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk3_SHIFT (9U)
/*! ipc_clk_coreclk3 - Force ON OFF of ipc_clk_coreclk3
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk3(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk3_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_coreclk3_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_acp_clk_MASK (0x800U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_acp_clk_SHIFT (11U)
/*! ipc_clk_ssi_acp_clk - Force ON OFF of ipc_clk_ssi_acp_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_acp_clk(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_acp_clk_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_acp_clk_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_trout_ref_MASK (0x1000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_trout_ref_SHIFT (12U)
/*! ipc_clk_trout_ref - Force ON OFF of ipc_clk_trout_ref
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_trout_ref(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_trout_ref_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_trout_ref_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_MASK (0x2000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_SHIFT (13U)
/*! ipc_clk_tsense - Force ON OFF of ipc_clk_tsense
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_periph_axi2apb_MASK (0x100000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_periph_axi2apb_SHIFT (20U)
/*! ipc_clk_periph_axi2apb - Force ON OFF of ipc_clk_periph_axi2apb
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_periph_axi2apb(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_periph_axi2apb_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_periph_axi2apb_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_axi2apb_MASK (0x400000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_axi2apb_SHIFT (22U)
/*! ipc_clk_tsense_axi2apb - Force ON OFF of ipc_clk_tsense_axi2apb
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_axi2apb(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_axi2apb_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_tsense_axi2apb_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_gic_clk_MASK (0x800000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_gic_clk_SHIFT (23U)
/*! ipc_clk_ssi_gic_clk - Force ON OFF of ipc_clk_ssi_gic_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_gic_clk(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_gic_clk_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_0_ipc_clk_ssi_gic_clk_MASK)
/*! @} */

/*! @name LPCG_FORCE_1 - LPCG Force ON OFFC Control 1 */
/*! @{ */

#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_sclk_dft_MASK (0x1U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_sclk_dft_SHIFT (0U)
/*! ipc_clk_sclk_dft - Force ON OFF of ipc_clk_sclk_dft
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_sclk_dft(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_sclk_dft_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_sclk_dft_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_apb_dft_MASK (0x2U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_apb_dft_SHIFT (1U)
/*! ipc_clk_arm_a55_apb_dft - Force ON OFF of ipc_clk_arm_a55_apb_dft
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_apb_dft(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_apb_dft_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_apb_dft_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_periph_dft_MASK (0x4U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_periph_dft_SHIFT (2U)
/*! ipc_clk_arm_a55_periph_dft - Force ON OFF of ipc_clk_arm_a55_periph_dft
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_periph_dft(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_periph_dft_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_arm_a55_periph_dft_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk0_out_MASK (0x200U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk0_out_SHIFT (9U)
/*! ipc_clk_coreclk0_out - Force ON OFF of ipc_clk_coreclk0_out
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk0_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk0_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk0_out_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk1_out_MASK (0x400U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk1_out_SHIFT (10U)
/*! ipc_clk_coreclk1_out - Force ON OFF of ipc_clk_coreclk1_out
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk1_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk1_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk1_out_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk2_out_MASK (0x800U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk2_out_SHIFT (11U)
/*! ipc_clk_coreclk2_out - Force ON OFF of ipc_clk_coreclk2_out
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk2_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk2_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk2_out_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk3_out_MASK (0x1000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk3_out_SHIFT (12U)
/*! ipc_clk_coreclk3_out - Force ON OFF of ipc_clk_coreclk3_out
 *  0b0..Disables
 *  0b1..Enables
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk3_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk3_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_1_ipc_clk_coreclk3_out_MASK)
/*! @} */

/*! @name LPCG_FORCE_SEL_0 - LPCG Force ON OFF Control Select 0 */
/*! @{ */

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_sclk_MASK (0x1U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_sclk_SHIFT (0U)
/*! ipc_clk_sclk - Force ON OFF Select of ipc_clk_sclk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_sclk(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_sclk_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_sclk_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_at_MASK (0x4U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_at_SHIFT (2U)
/*! ipc_clk_arm_a55_at - Force ON OFF Select of ipc_clk_arm_a55_at
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_at(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_at_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_at_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_gic_MASK (0x8U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_gic_SHIFT (3U)
/*! ipc_clk_arm_a55_gic - Force ON OFF Select of ipc_clk_arm_a55_gic
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_gic(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_gic_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_gic_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_periph_MASK (0x10U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_periph_SHIFT (4U)
/*! ipc_clk_arm_a55_periph - Force ON OFF Select of ipc_clk_arm_a55_periph
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_periph(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_periph_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_periph_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_p_MASK (0x20U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_p_SHIFT (5U)
/*! ipc_clk_arm_a55_p - Force ON OFF Select of ipc_clk_arm_a55_p
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_p(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_p_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_arm_a55_p_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk0_MASK (0x40U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk0_SHIFT (6U)
/*! ipc_clk_coreclk0 - Force ON OFF Select of ipc_clk_coreclk0
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk0(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk0_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk0_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk1_MASK (0x80U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk1_SHIFT (7U)
/*! ipc_clk_coreclk1 - Force ON OFF Select of ipc_clk_coreclk1
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk1(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk1_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk1_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk2_MASK (0x100U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk2_SHIFT (8U)
/*! ipc_clk_coreclk2 - Force ON OFF Select of ipc_clk_coreclk2
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk2(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk2_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk2_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk3_MASK (0x200U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk3_SHIFT (9U)
/*! ipc_clk_coreclk3 - Force ON OFF Select of ipc_clk_coreclk3
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk3(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk3_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_coreclk3_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_acp_clk_MASK (0x800U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_acp_clk_SHIFT (11U)
/*! ipc_clk_ssi_acp_clk - Force ON OFF Select of ipc_clk_ssi_acp_clk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_acp_clk(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_acp_clk_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_acp_clk_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_trout_ref_MASK (0x1000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_trout_ref_SHIFT (12U)
/*! ipc_clk_trout_ref - Force ON OFF Select of ipc_clk_trout_ref
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_trout_ref(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_trout_ref_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_trout_ref_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_MASK (0x2000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_SHIFT (13U)
/*! ipc_clk_tsense - Force ON OFF Select of ipc_clk_tsense
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_periph_axi2apb_MASK (0x100000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_periph_axi2apb_SHIFT (20U)
/*! ipc_clk_periph_axi2apb - Force ON OFF Select of ipc_clk_arm_a55_periph_axi2apb
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_periph_axi2apb(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_periph_axi2apb_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_periph_axi2apb_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_axi2apb_MASK (0x400000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_axi2apb_SHIFT (22U)
/*! ipc_clk_tsense_axi2apb - Force ON OFF Select of ipc_clk_tsense_axi2apb
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_axi2apb(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_axi2apb_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_tsense_axi2apb_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_gic_clk_MASK (0x800000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_gic_clk_SHIFT (23U)
/*! ipc_clk_ssi_gic_clk - Force ON OFF Select of ipc_clk_ssi_gic_clk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_gic_clk(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_gic_clk_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_0_ipc_clk_ssi_gic_clk_MASK)
/*! @} */

/*! @name LPCG_FORCE_SEL_1 - LPCG Force ON OFF Control Select 1 */
/*! @{ */

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_sclk_dft_MASK (0x1U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_sclk_dft_SHIFT (0U)
/*! ipc_clk_sclk_dft - Force ON OFF Select of ipc_clk_sclk_dft
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_sclk_dft(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_sclk_dft_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_sclk_dft_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_arm_a55_apb_dft_MASK (0x2U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_arm_a55_apb_dft_SHIFT (1U)
/*! ipc_clk_arm_a55_apb_dft - Force ON OFF Select of ipc_clk_arm_a55_apb_dft
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_arm_a55_apb_dft(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_arm_a55_apb_dft_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_arm_a55_apb_dft_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_periph_dft_MASK (0x4U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_periph_dft_SHIFT (2U)
/*! ipc_clk_periph_dft - Force ON OFF Select of ipc_clk_arm_a55_periph_dft
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_periph_dft(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_periph_dft_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_periph_dft_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk0_out_MASK (0x200U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk0_out_SHIFT (9U)
/*! ipc_clk_coreclk0_out - Force ON OFF Select of ipc_clk_coreclk0_out
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk0_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk0_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk0_out_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk1_out_MASK (0x400U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk1_out_SHIFT (10U)
/*! ipc_clk_coreclk1_out - Force ON OFF Select of ipc_clk_coreclk1_out
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk1_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk1_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk1_out_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk2_out_MASK (0x800U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk2_out_SHIFT (11U)
/*! ipc_clk_coreclk2_out - Force ON OFF Select of ipc_clk_coreclk2_out
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk2_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk2_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk2_out_MASK)

#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk3_out_MASK (0x1000U)
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk3_out_SHIFT (12U)
/*! ipc_clk_coreclk3_out - Force ON OFF Select of ipc_clk_coreclk3_out
 *  0b0..Not selected
 *  0b1..Selected
 */
#define CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk3_out(x) (((uint32_t)(((uint32_t)(x)) << CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk3_out_SHIFT)) & CORTEXA_BLK_CTRL_LPCG_FORCE_SEL_1_ipc_clk_coreclk3_out_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CORTEXA_BLK_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group CORTEXA_BLK_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_CORTEXA_BLK_CTRL_H_ */

