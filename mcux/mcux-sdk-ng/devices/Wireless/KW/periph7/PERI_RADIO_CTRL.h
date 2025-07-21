/*
** ###################################################################
**     Processors:          KW45B41Z52AFPA
**                          KW45B41Z52AFTA
**                          KW45B41Z53AFPA
**                          KW45B41Z53AFTA
**                          KW45B41Z82AFPA
**                          KW45B41Z82AFTA
**                          KW45B41Z83AFPA
**                          KW45B41Z83AFPA_NBU
**                          KW45B41Z83AFTA
**                          KW45B41Z83AFTA_NBU
**                          KW45Z41052AFPA
**                          KW45Z41052AFTA
**                          KW45Z41053AFPA
**                          KW45Z41053AFTA
**                          KW45Z41082AFPA
**                          KW45Z41082AFTA
**                          KW45Z41083AFPA
**                          KW45Z41083AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RADIO_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RADIO_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RADIO_CTRL
 *
 * CMSIS Peripheral Access Layer for RADIO_CTRL
 */

#if !defined(PERI_RADIO_CTRL_H_)
#define PERI_RADIO_CTRL_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA))
#include "KW45B41Z52_COMMON.h"
#elif (defined(CPU_KW45B41Z53AFPA) || defined(CPU_KW45B41Z53AFTA))
#include "KW45B41Z53_COMMON.h"
#elif (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA))
#include "KW45B41Z82_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA) || defined(CPU_KW45B41Z83AFTA))
#include "KW45B41Z83_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA_NBU) || defined(CPU_KW45B41Z83AFTA_NBU))
#include "KW45B41Z83_NBU_COMMON.h"
#elif (defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA))
#include "KW45Z41052_COMMON.h"
#elif (defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
#include "KW45Z41053_COMMON.h"
#elif (defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA))
#include "KW45Z41082_COMMON.h"
#elif (defined(CPU_KW45Z41083AFPA) || defined(CPU_KW45Z41083AFTA))
#include "KW45Z41083_COMMON.h"
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
   -- RADIO_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RADIO_CTRL_Peripheral_Access_Layer RADIO_CTRL Peripheral Access Layer
 * @{
 */

/** RADIO_CTRL - Register Layout Typedef */
typedef struct {
  __I  uint32_t LL_STATUS;                         /**< LL Status Register, offset: 0x0 */
  __IO uint32_t LL_CTRL;                           /**< LL Control Register, offset: 0x4 */
  __IO uint32_t RF_CTRL;                           /**< Radio Control Register, offset: 0x8 */
  __IO uint32_t RF_CLK_CTRL;                       /**< Radio Clock Control Register, offset: 0xC */
  __IO uint32_t COEX_CTRL;                         /**< COEXISTENCE CONTROL, offset: 0x10 */
  __I  uint32_t UID_MSB;                           /**< Radio Control Register, offset: 0x14 */
  __I  uint32_t UID_LSB;                           /**< Radio Control Register, offset: 0x18 */
  __IO uint32_t PACKET_RAM_CTRL;                   /**< PACKET RAM Control Register, offset: 0x1C */
  __IO uint32_t BLE_PHY_CTRL;                      /**< BLE PHY Interface Control Register, offset: 0x20 */
  __IO uint32_t DTEST_CTRL;                        /**< DTEST Control register, offset: 0x24 */
       uint8_t RESERVED_0[8];
  __IO uint32_t DTEST_PIN_CTRL2;                   /**< DTEST PIN Control 2 register, offset: 0x30 */
} RADIO_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- RADIO_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RADIO_CTRL_Register_Masks RADIO_CTRL Register Masks
 * @{
 */

/*! @name LL_STATUS - LL Status Register */
/*! @{ */

#define RADIO_CTRL_LL_STATUS_LL_PRESENT_MASK     (0x3FU)
#define RADIO_CTRL_LL_STATUS_LL_PRESENT_SHIFT    (0U)
/*! LL_PRESENT - LL present status */
#define RADIO_CTRL_LL_STATUS_LL_PRESENT(x)       (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_LL_STATUS_LL_PRESENT_SHIFT)) & RADIO_CTRL_LL_STATUS_LL_PRESENT_MASK)

#define RADIO_CTRL_LL_STATUS_BLE_VERSION_MASK    (0xF00U)
#define RADIO_CTRL_LL_STATUS_BLE_VERSION_SHIFT   (8U)
/*! BLE_VERSION - Bluetooth LE Version
 *  0b0000..No Bluetooth LE
 *  0b0001..Bluetooth LE 5.1
 *  0b0010..Bluetooth LE 5.2
 *  0b0011..Bluetooth LE 5.3
 *  0b0100-0b1110..Reserved
 *  0b1111..Bluetooth LE Upgrade
 */
#define RADIO_CTRL_LL_STATUS_BLE_VERSION(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_LL_STATUS_BLE_VERSION_SHIFT)) & RADIO_CTRL_LL_STATUS_BLE_VERSION_MASK)
/*! @} */

/*! @name LL_CTRL - LL Control Register */
/*! @{ */

#define RADIO_CTRL_LL_CTRL_ACTIVE_LL_MASK        (0x3U)
#define RADIO_CTRL_LL_CTRL_ACTIVE_LL_SHIFT       (0U)
/*! ACTIVE_LL - link layer control register
 *  0b00..Bluetooth LE LL is selected
 *  0b10..GENERIC LL is selected
 *  0b11..Disabled (default)
 */
#define RADIO_CTRL_LL_CTRL_ACTIVE_LL(x)          (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_LL_CTRL_ACTIVE_LL_SHIFT)) & RADIO_CTRL_LL_CTRL_ACTIVE_LL_MASK)
/*! @} */

/*! @name RF_CTRL - Radio Control Register */
/*! @{ */

#define RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_EN_MASK (0x1U)
#define RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_EN_SHIFT (0U)
/*! RBME_MODE_OVRD_EN - RBME Mode Override Enable
 *  0b0..RBME Mode Override Disable
 *  0b1..RBME Mode Override Enable
 */
#define RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_EN_MASK)

#define RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_MASK   (0xEU)
#define RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_SHIFT  (1U)
/*! RBME_MODE_OVRD - RBME Mode Override */
#define RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_SHIFT)) & RADIO_CTRL_RF_CTRL_RBME_MODE_OVRD_MASK)

#define RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_EN_MASK (0x10U)
#define RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_EN_SHIFT (4U)
/*! RX_CON_EN_OVRD_EN - rx_con_en Override Enable
 *  0b0..rx_con_en Override Disable
 *  0b1..rx_con_en Override Enable
 */
#define RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_EN_MASK)

#define RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_MASK   (0x20U)
#define RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_SHIFT  (5U)
/*! RX_CON_EN_OVRD - rx_con_en Override */
#define RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_SHIFT)) & RADIO_CTRL_RF_CTRL_RX_CON_EN_OVRD_MASK)

#define RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_EN_MASK (0x40U)
#define RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_EN_SHIFT (6U)
/*! BLE_LR_EN_OVRD_EN - ble_lr_en Override Enable
 *  0b0..ble_lr_en Override Disable
 *  0b1..ble_lr_en Override Enable
 */
#define RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_EN_MASK)

#define RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_MASK   (0x80U)
#define RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_SHIFT  (7U)
/*! BLE_LR_EN_OVRD - ble_lr_en Override */
#define RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_SHIFT)) & RADIO_CTRL_RF_CTRL_BLE_LR_EN_OVRD_MASK)

#define RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_EN_MASK (0x100U)
#define RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_EN_SHIFT (8U)
/*! RIF_SEL_2MBPS_OVRD_EN - rif_sel_2mbps Override Enable
 *  0b0..rif_sel_2mbps Override Disable
 *  0b1..rif_sel_2mbps Override Enable
 */
#define RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_EN_MASK)

#define RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_MASK (0x200U)
#define RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_SHIFT (9U)
/*! RIF_SEL_2MBPS_OVRD - rif_sel_2mbps Override */
#define RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_SHIFT)) & RADIO_CTRL_RF_CTRL_RIF_SEL_2MBPS_OVRD_MASK)

#define RADIO_CTRL_RF_CTRL_WOR_RX_FAIL_WAKEUP_EN_MASK (0x10000000U)
#define RADIO_CTRL_RF_CTRL_WOR_RX_FAIL_WAKEUP_EN_SHIFT (28U)
/*! WOR_RX_FAIL_WAKEUP_EN - WOR RX Fail Wakeup Enable
 *  0b0..The wor_rx_fail interrupt doesn't assert rfmc_wakeup.
 *  0b1..The wor_rx_fail interrupt asserts rfmc_wakeup.
 */
#define RADIO_CTRL_RF_CTRL_WOR_RX_FAIL_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_WOR_RX_FAIL_WAKEUP_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_WOR_RX_FAIL_WAKEUP_EN_MASK)

#define RADIO_CTRL_RF_CTRL_BRIC_WAKEUP_EN_MASK   (0x20000000U)
#define RADIO_CTRL_RF_CTRL_BRIC_WAKEUP_EN_SHIFT  (29U)
/*! BRIC_WAKEUP_EN - BRIC Wakeup Enable
 *  0b0..The BRIC interrupt doesn't assert rfmc_wakeup.
 *  0b1..The BRIC interrupt asserts rfmc_wakeup.
 */
#define RADIO_CTRL_RF_CTRL_BRIC_WAKEUP_EN(x)     (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_BRIC_WAKEUP_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_BRIC_WAKEUP_EN_MASK)

#define RADIO_CTRL_RF_CTRL_GENERIC_WAKEUP_EN_MASK (0x40000000U)
#define RADIO_CTRL_RF_CTRL_GENERIC_WAKEUP_EN_SHIFT (30U)
/*! GENERIC_WAKEUP_EN - Generic LL Wakeup Enable
 *  0b0..The Generic LL interrupt doesn't assert rfmc_wakeup.
 *  0b1..The Genecir LL interrupt asserts rfmc_wakeup.
 */
#define RADIO_CTRL_RF_CTRL_GENERIC_WAKEUP_EN(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_GENERIC_WAKEUP_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_GENERIC_WAKEUP_EN_MASK)

#define RADIO_CTRL_RF_CTRL_ZIGBEE_WAKEUP_EN_MASK (0x80000000U)
#define RADIO_CTRL_RF_CTRL_ZIGBEE_WAKEUP_EN_SHIFT (31U)
/*! ZIGBEE_WAKEUP_EN - Zigbee LL Wakeup Enable
 *  0b0..The Zigbee LL interrupt doesn't assert rfmc_wakeup.
 *  0b1..The Zigbee LL interrupt asserts rfmc_wakeup.
 */
#define RADIO_CTRL_RF_CTRL_ZIGBEE_WAKEUP_EN(x)   (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CTRL_ZIGBEE_WAKEUP_EN_SHIFT)) & RADIO_CTRL_RF_CTRL_ZIGBEE_WAKEUP_EN_MASK)
/*! @} */

/*! @name RF_CLK_CTRL - Radio Clock Control Register */
/*! @{ */

#define RADIO_CTRL_RF_CLK_CTRL_ZBLL_CLK_EN_OVRD_MASK (0x1U)
#define RADIO_CTRL_RF_CLK_CTRL_ZBLL_CLK_EN_OVRD_SHIFT (0U)
/*! ZBLL_CLK_EN_OVRD - ZBLL Clock Enable Override
 *  0b0..ZBLL clock force on is disabled.
 *  0b1..ZBLL clock force on is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_ZBLL_CLK_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_ZBLL_CLK_EN_OVRD_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_ZBLL_CLK_EN_OVRD_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_GENLL_CLK_EN_OVRD_MASK (0x2U)
#define RADIO_CTRL_RF_CLK_CTRL_GENLL_CLK_EN_OVRD_SHIFT (1U)
/*! GENLL_CLK_EN_OVRD - GENLL Clock Enable Override
 *  0b0..GENLL clock force on is disabled.
 *  0b1..GENLL clock force on is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_GENLL_CLK_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_GENLL_CLK_EN_OVRD_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_GENLL_CLK_EN_OVRD_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BTLL_CLK_EN_OVRD_MASK (0x4U)
#define RADIO_CTRL_RF_CLK_CTRL_BTLL_CLK_EN_OVRD_SHIFT (2U)
/*! BTLL_CLK_EN_OVRD - BTLL Clock Enable Override
 *  0b0..BTLL clock force on is disabled.
 *  0b1..BTLL clock force on is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BTLL_CLK_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BTLL_CLK_EN_OVRD_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BTLL_CLK_EN_OVRD_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BTU_EBRAM_CLK_ON_OVRD_MASK (0x8U)
#define RADIO_CTRL_RF_CLK_CTRL_BTU_EBRAM_CLK_ON_OVRD_SHIFT (3U)
/*! BTU_EBRAM_CLK_ON_OVRD - BTU EBRAM Clock Enable Override
 *  0b0..btu_ebram_clk is not forced on.
 *  0b1..btu_ebram_clk is forced on.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BTU_EBRAM_CLK_ON_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BTU_EBRAM_CLK_ON_OVRD_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BTU_EBRAM_CLK_ON_OVRD_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_DIV_MASK  (0x10U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_DIV_SHIFT (4U)
/*! BT_ECLK_DIV - BE_ECLK Divider
 *  0b0..ref_clk is not divided as bt_eclk.
 *  0b1..ref_clk is divided by 2 as bt_eclk.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_DIV(x)    (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_DIV_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_DIV_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_NBU_HCLK_EN_MASK  (0x100U)
#define RADIO_CTRL_RF_CLK_CTRL_NBU_HCLK_EN_SHIFT (8U)
/*! NBU_HCLK_EN - NBU HCLK Enable
 *  0b0..nbu hclk/cpu_hclk are disabled.
 *  0b1..nbu hclk/cpu_hclk are enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_NBU_HCLK_EN(x)    (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_NBU_HCLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_NBU_HCLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_CM3_HCLK_EN_MASK  (0x200U)
#define RADIO_CTRL_RF_CLK_CTRL_CM3_HCLK_EN_SHIFT (9U)
/*! CM3_HCLK_EN - CM3 HCLK Enable
 *  0b0..cm3_hclk is disabled.
 *  0b1..cm3_hclk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_CM3_HCLK_EN(x)    (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_CM3_HCLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_CM3_HCLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BLE_AHB_CLK_EN_MASK (0x400U)
#define RADIO_CTRL_RF_CLK_CTRL_BLE_AHB_CLK_EN_SHIFT (10U)
/*! BLE_AHB_CLK_EN - BLE_AHB CLOCK Enable
 *  0b0..ble_ahb_clk is disabled.
 *  0b1..ble_ahb_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BLE_AHB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BLE_AHB_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BLE_AHB_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_NBU_PKB_CLK_EN_MASK (0x800U)
#define RADIO_CTRL_RF_CLK_CTRL_NBU_PKB_CLK_EN_SHIFT (11U)
/*! NBU_PKB_CLK_EN - NBU PKB Clock Enable
 *  0b0..nbu_pkb_clk is disabled.
 *  0b1..nbu_pkb_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_NBU_PKB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_NBU_PKB_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_NBU_PKB_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_16M_CLK_EN_MASK (0x1000U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_16M_CLK_EN_SHIFT (12U)
/*! BT_16M_CLK_EN - BT 16M Clock Enable
 *  0b0..bt_16m_clk is disabled.
 *  0b1..bt_16m_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_16M_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_16M_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_16M_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_RTU_CLK_EN_MASK   (0x2000U)
#define RADIO_CTRL_RF_CLK_CTRL_RTU_CLK_EN_SHIFT  (13U)
/*! RTU_CLK_EN - RTU Clock Enable
 *  0b0..rtu_clk is disabled.
 *  0b1..rtu_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_RTU_CLK_EN(x)     (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_RTU_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_RTU_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_4M_CLK_EN_MASK (0x4000U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_4M_CLK_EN_SHIFT (14U)
/*! BT_4M_CLK_EN - BT 4M Clock Enable
 *  0b0..bt_4m_clk is disabled.
 *  0b1..bt_4m_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_4M_CLK_EN(x)   (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_4M_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_4M_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_REF_4M_CLK_EN_MASK (0x8000U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_REF_4M_CLK_EN_SHIFT (15U)
/*! BT_REF_4M_CLK_EN - BT REF 4M Clock Enable
 *  0b0..bt_ref_4m_clk is disabled.
 *  0b1..bt_ref_4m_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_REF_4M_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_REF_4M_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_REF_4M_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_4M_CLK_EN_MASK (0x10000U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_4M_CLK_EN_SHIFT (16U)
/*! BT_XCVR_4M_CLK_EN - BT XCVR 4M Clock Enable
 *  0b0..bt_xcvr_4m_clk is disabled.
 *  0b1..bt_xcvr_4m_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_4M_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_4M_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_4M_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_32M_CLK_EN_MASK (0x20000U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_32M_CLK_EN_SHIFT (17U)
/*! BT_XCVR_32M_CLK_EN - BT XCVR 32M Clock Enable
 *  0b0..bt_xcvr_32m_clk is disabled.
 *  0b1..bt_xcvr_32m_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_32M_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_32M_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_XCVR_32M_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_EN_MASK   (0x40000U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_EN_SHIFT  (18U)
/*! BT_ECLK_EN - BT_ECLK Enable
 *  0b0..bt_eclk is disabled.
 *  0b1..bt_eclk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_EN(x)     (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_ECLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BLE_AES_CLK_EN_MASK (0x80000U)
#define RADIO_CTRL_RF_CLK_CTRL_BLE_AES_CLK_EN_SHIFT (19U)
/*! BLE_AES_CLK_EN - BLE_AES_CLK Enable
 *  0b0..bt_aes_clk is disabled.
 *  0b1..bt_aes_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BLE_AES_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BLE_AES_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BLE_AES_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_UART_CLK_EN_MASK  (0x100000U)
#define RADIO_CTRL_RF_CLK_CTRL_UART_CLK_EN_SHIFT (20U)
/*! UART_CLK_EN - UART Clock Enable
 *  0b0..uart_clk is disabled.
 *  0b1..uart_clk is enabled.
 */
#define RADIO_CTRL_RF_CLK_CTRL_UART_CLK_EN(x)    (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_UART_CLK_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_UART_CLK_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_MAN_DS_EN_MASK    (0x20000000U)
#define RADIO_CTRL_RF_CLK_CTRL_MAN_DS_EN_SHIFT   (29U)
/*! MAN_DS_EN - Manual deep sleep control enable
 *  0b0..Disable the control of rfmc_man_deep_sleep_enable for nbu_hclk.
 *  0b1..Enable the control of rfmc_man_deep_sleep_enable for nbu_hclk.
 */
#define RADIO_CTRL_RF_CLK_CTRL_MAN_DS_EN(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_MAN_DS_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_MAN_DS_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_WOR_DS_EN_MASK    (0x40000000U)
#define RADIO_CTRL_RF_CLK_CTRL_WOR_DS_EN_SHIFT   (30U)
/*! WOR_DS_EN - WOR deep sleep control enable
 *  0b0..Disable the control of rfmc_wor_deep_sleep_enable for nbu_hclk.
 *  0b1..Enable the control of rfmc_wor_deep_sleep_enable for nbu_hclk.
 */
#define RADIO_CTRL_RF_CLK_CTRL_WOR_DS_EN(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_WOR_DS_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_WOR_DS_EN_MASK)

#define RADIO_CTRL_RF_CLK_CTRL_BT_CLK_REQ_EN_MASK (0x80000000U)
#define RADIO_CTRL_RF_CLK_CTRL_BT_CLK_REQ_EN_SHIFT (31U)
/*! BT_CLK_REQ_EN - BT_CLK_REQ control enable
 *  0b0..Disable the control of bt_clk_req for nbu_hclk.
 *  0b1..Enable the control of bt_clk_req for nbu_hclk.
 */
#define RADIO_CTRL_RF_CLK_CTRL_BT_CLK_REQ_EN(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_RF_CLK_CTRL_BT_CLK_REQ_EN_SHIFT)) & RADIO_CTRL_RF_CLK_CTRL_BT_CLK_REQ_EN_MASK)
/*! @} */

/*! @name COEX_CTRL - COEXISTENCE CONTROL */
/*! @{ */

#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_EN_MASK (0xFU)
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_EN_SHIFT (0U)
/*! RF_NOT_ALLOWED_EN - RF_NOT_ALLOWED PER-LINK-LAYER ENABLE */
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_EN_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_EN_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_ASSERTED_MASK (0x10U)
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_ASSERTED_SHIFT (4U)
/*! RF_NOT_ALLOWED_ASSERTED - RF_NOT_ALLOWED_ASSERTED
 *  0b0..Assertion on RF_NOT_ALLOWED has not occurred
 *  0b1..Assertion on RF_NOT_ALLOWED has occurred since the last time this bit was cleared
 */
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_ASSERTED(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_ASSERTED_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_ASSERTED_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_MASK (0x20U)
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_SHIFT (5U)
/*! RF_NOT_ALLOWED - RF_NOT_ALLOWED */
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED(x)   (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_MASK (0x40U)
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_SHIFT (6U)
/*! RF_NOT_ALLOWED_OVRD - RF_NOT_ALLOWED Override */
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_EN_MASK (0x80U)
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_EN_SHIFT (7U)
/*! RF_NOT_ALLOWED_OVRD_EN - RF_NOT_ALLOWED Override Enable
 *  0b0..RF_NALLOWED Override Disable
 *  0b1..RF_NALLOWED Override Enable
 */
#define RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_EN_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_NOT_ALLOWED_OVRD_EN_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_NALLOWED_INV_MASK (0x100U)
#define RADIO_CTRL_COEX_CTRL_RF_NALLOWED_INV_SHIFT (8U)
/*! RF_NALLOWED_INV - RF_NALLOWED Invert
 *  0b0..rf_nallowed is not inverted.
 *  0b1..rf_nallowed is inverted.
 */
#define RADIO_CTRL_COEX_CTRL_RF_NALLOWED_INV(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_NALLOWED_INV_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_NALLOWED_INV_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_ACTIVE_INV_MASK  (0x200U)
#define RADIO_CTRL_COEX_CTRL_RF_ACTIVE_INV_SHIFT (9U)
/*! RF_ACTIVE_INV - RF_ACTIVE Invert
 *  0b0..rf_active is not inverted.
 *  0b1..rf_active is inverted.
 */
#define RADIO_CTRL_COEX_CTRL_RF_ACTIVE_INV(x)    (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_ACTIVE_INV_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_ACTIVE_INV_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_PRIORITY_INV_MASK (0xC00U)
#define RADIO_CTRL_COEX_CTRL_RF_PRIORITY_INV_SHIFT (10U)
/*! RF_PRIORITY_INV - RF_PRIORITY Invert
 *  0b0x..rf_priority[1] is not inverted.
 *  0b1x..rf_priority[1] is inverted.
 *  0bx0..rf_priority[0] is not inverted.
 *  0bx1..rf_priority[0] is inverted.
 */
#define RADIO_CTRL_COEX_CTRL_RF_PRIORITY_INV(x)  (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_PRIORITY_INV_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_PRIORITY_INV_MASK)

#define RADIO_CTRL_COEX_CTRL_RF_STATUS_INV_MASK  (0x1000U)
#define RADIO_CTRL_COEX_CTRL_RF_STATUS_INV_SHIFT (12U)
/*! RF_STATUS_INV - RF_STATUS Invert
 *  0b0..rf_status is not inverted.
 *  0b1..rf_status is inverted.
 */
#define RADIO_CTRL_COEX_CTRL_RF_STATUS_INV(x)    (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_RF_STATUS_INV_SHIFT)) & RADIO_CTRL_COEX_CTRL_RF_STATUS_INV_MASK)

#define RADIO_CTRL_COEX_CTRL_COEX_SEL_MASK       (0x2000U)
#define RADIO_CTRL_COEX_CTRL_COEX_SEL_SHIFT      (13U)
/*! COEX_SEL - COEX_SEL
 *  0b0..Select coexistence signals from LL.
 *  0b1..Select coexistence signals from TSM.
 */
#define RADIO_CTRL_COEX_CTRL_COEX_SEL(x)         (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_COEX_CTRL_COEX_SEL_SHIFT)) & RADIO_CTRL_COEX_CTRL_COEX_SEL_MASK)
/*! @} */

/*! @name UID_MSB - Radio Control Register */
/*! @{ */

#define RADIO_CTRL_UID_MSB_RADIO_UID_MSB_MASK    (0xFFU)
#define RADIO_CTRL_UID_MSB_RADIO_UID_MSB_SHIFT   (0U)
/*! RADIO_UID_MSB - The most signficant 8bits of the 40bit Radio UID. */
#define RADIO_CTRL_UID_MSB_RADIO_UID_MSB(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_UID_MSB_RADIO_UID_MSB_SHIFT)) & RADIO_CTRL_UID_MSB_RADIO_UID_MSB_MASK)
/*! @} */

/*! @name UID_LSB - Radio Control Register */
/*! @{ */

#define RADIO_CTRL_UID_LSB_RADIO_UID_LSB_MASK    (0xFFFFFFFFU)
#define RADIO_CTRL_UID_LSB_RADIO_UID_LSB_SHIFT   (0U)
/*! RADIO_UID_LSB - The least signficant 32bits of the 40bit Radio UID. */
#define RADIO_CTRL_UID_LSB_RADIO_UID_LSB(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_UID_LSB_RADIO_UID_LSB_SHIFT)) & RADIO_CTRL_UID_LSB_RADIO_UID_LSB_MASK)
/*! @} */

/*! @name PACKET_RAM_CTRL - PACKET RAM Control Register */
/*! @{ */

#define RADIO_CTRL_PACKET_RAM_CTRL_PB_PROTECT_MASK (0x1U)
#define RADIO_CTRL_PACKET_RAM_CTRL_PB_PROTECT_SHIFT (0U)
/*! PB_PROTECT - PB_PROTECT
 *  0b0..Incoming receive data can overwrite the existing contents of the RX section of the Packet Buffer.
 *  0b1..Incoming receive data is been blocked from overwriting the existing contents of the RX section of the Packet Buffer.
 */
#define RADIO_CTRL_PACKET_RAM_CTRL_PB_PROTECT(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_PACKET_RAM_CTRL_PB_PROTECT_SHIFT)) & RADIO_CTRL_PACKET_RAM_CTRL_PB_PROTECT_MASK)
/*! @} */

/*! @name BLE_PHY_CTRL - BLE PHY Interface Control Register */
/*! @{ */

#define RADIO_CTRL_BLE_PHY_CTRL_CTE_AVG_SAMP_SEL_MASK (0x3U)
#define RADIO_CTRL_BLE_PHY_CTRL_CTE_AVG_SAMP_SEL_SHIFT (0U)
/*! CTE_AVG_SAMP_SEL - Sampling select */
#define RADIO_CTRL_BLE_PHY_CTRL_CTE_AVG_SAMP_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_CTE_AVG_SAMP_SEL_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_CTE_AVG_SAMP_SEL_MASK)

#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_1M_MASK (0xF0U)
#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_1M_SHIFT (4U)
/*! READ_START_OFFSET_1M - Start sending Rx data to NBU after a programmable number of symbols are received from PHY - 1M */
#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_1M(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_1M_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_1M_MASK)

#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_2M_MASK (0xF00U)
#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_2M_SHIFT (8U)
/*! READ_START_OFFSET_2M - Start sending Rx data to NBU after a programmable number of symbols are received from PHY - 2M */
#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_2M(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_2M_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_2M_MASK)

#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_LR_MASK (0xF000U)
#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_LR_SHIFT (12U)
/*! READ_START_OFFSET_LR - Start sending Rx data to NBU after a programmable number of symbols are received from PHY - LR */
#define RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_LR(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_LR_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_READ_START_OFFSET_LR_MASK)

#define RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_1M_MASK (0xFF0000U)
#define RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_1M_SHIFT (16U)
/*! GUARD_TIME_1M - Guard time offset for 1M */
#define RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_1M(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_1M_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_1M_MASK)

#define RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_2M_MASK (0x3F000000U)
#define RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_2M_SHIFT (24U)
/*! GUARD_TIME_2M - Guard time offset for 2M */
#define RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_2M(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_2M_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_GUARD_TIME_2M_MASK)

#define RADIO_CTRL_BLE_PHY_CTRL_AVG_IQ_DISABLE_MASK (0x40000000U)
#define RADIO_CTRL_BLE_PHY_CTRL_AVG_IQ_DISABLE_SHIFT (30U)
/*! AVG_IQ_DISABLE - Disable IQ sample averaging */
#define RADIO_CTRL_BLE_PHY_CTRL_AVG_IQ_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_AVG_IQ_DISABLE_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_AVG_IQ_DISABLE_MASK)

#define RADIO_CTRL_BLE_PHY_CTRL_CTE_SINGLE_BUF_MASK (0x80000000U)
#define RADIO_CTRL_BLE_PHY_CTRL_CTE_SINGLE_BUF_SHIFT (31U)
/*! CTE_SINGLE_BUF - Config for using single buffer for Rx data and CTE samples */
#define RADIO_CTRL_BLE_PHY_CTRL_CTE_SINGLE_BUF(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_BLE_PHY_CTRL_CTE_SINGLE_BUF_SHIFT)) & RADIO_CTRL_BLE_PHY_CTRL_CTE_SINGLE_BUF_MASK)
/*! @} */

/*! @name DTEST_CTRL - DTEST Control register */
/*! @{ */

#define RADIO_CTRL_DTEST_CTRL_DTEST_PAGE_MASK    (0x7FU)
#define RADIO_CTRL_DTEST_CTRL_DTEST_PAGE_SHIFT   (0U)
/*! DTEST_PAGE - DTEST PAGE Number */
#define RADIO_CTRL_DTEST_CTRL_DTEST_PAGE(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_CTRL_DTEST_PAGE_SHIFT)) & RADIO_CTRL_DTEST_CTRL_DTEST_PAGE_MASK)

#define RADIO_CTRL_DTEST_CTRL_DTEST_EN_MASK      (0x80U)
#define RADIO_CTRL_DTEST_CTRL_DTEST_EN_SHIFT     (7U)
/*! DTEST_EN - DTEST_EN control
 *  0b0..disable dtest feature
 *  0b1..enable dtest feature
 */
#define RADIO_CTRL_DTEST_CTRL_DTEST_EN(x)        (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_CTRL_DTEST_EN_SHIFT)) & RADIO_CTRL_DTEST_CTRL_DTEST_EN_MASK)

#define RADIO_CTRL_DTEST_CTRL_DTEST_OUT_REG_EN_MASK (0x100U)
#define RADIO_CTRL_DTEST_CTRL_DTEST_OUT_REG_EN_SHIFT (8U)
/*! DTEST_OUT_REG_EN - Enable/Disable register dtest signal
 *  0b0..output dtest signal directly
 *  0b1..output dtest signal after registered
 */
#define RADIO_CTRL_DTEST_CTRL_DTEST_OUT_REG_EN(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_CTRL_DTEST_OUT_REG_EN_SHIFT)) & RADIO_CTRL_DTEST_CTRL_DTEST_OUT_REG_EN_MASK)

#define RADIO_CTRL_DTEST_CTRL_RAW_MODE_I_MASK    (0x200U)
#define RADIO_CTRL_DTEST_CTRL_RAW_MODE_I_SHIFT   (9U)
/*! RAW_MODE_I - Select rx_dig_i as DTEST RX_IQ page */
#define RADIO_CTRL_DTEST_CTRL_RAW_MODE_I(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_CTRL_RAW_MODE_I_SHIFT)) & RADIO_CTRL_DTEST_CTRL_RAW_MODE_I_MASK)

#define RADIO_CTRL_DTEST_CTRL_RAW_MODE_Q_MASK    (0x400U)
#define RADIO_CTRL_DTEST_CTRL_RAW_MODE_Q_SHIFT   (10U)
/*! RAW_MODE_Q - Select rx_dig_q as DTEST RX_IQ page */
#define RADIO_CTRL_DTEST_CTRL_RAW_MODE_Q(x)      (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_CTRL_RAW_MODE_Q_SHIFT)) & RADIO_CTRL_DTEST_CTRL_RAW_MODE_Q_MASK)

#define RADIO_CTRL_DTEST_CTRL_DTEST_SHIFT_MASK   (0x3800U)
#define RADIO_CTRL_DTEST_CTRL_DTEST_SHIFT_SHIFT  (11U)
/*! DTEST_SHIFT - DTEST shift control */
#define RADIO_CTRL_DTEST_CTRL_DTEST_SHIFT(x)     (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_CTRL_DTEST_SHIFT_SHIFT)) & RADIO_CTRL_DTEST_CTRL_DTEST_SHIFT_MASK)
/*! @} */

/*! @name DTEST_PIN_CTRL2 - DTEST PIN Control 2 register */
/*! @{ */

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_MUX_SEL_MASK (0xFU)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_MUX_SEL_SHIFT (0U)
/*! DTEST_PIN8_MUX_SEL - DTEST_PIN8_MUX_SEL */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_MUX_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_MUX_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_MUX_SEL_MASK)

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_OVRD_SEL_MASK (0xF0U)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_OVRD_SEL_SHIFT (4U)
/*! DTEST_PIN8_OVRD_SEL - DTEST_PIN8_OVRD_SEL
 *  0b0000..override is disabled
 *  0b0001..aa_sfd_matched
 *  0b0010..rx_pd_fnd
 *  0b0011..agc_gain_change
 *  0b0100..tsm_combined_tx_en
 *  0b0101..tsm_combined_rx_en
 *  0b0110..crc_fail
 *  0b0111..decode_data_out
 *  0b1000..tx_data_out
 *  0b1001..nbu_testbus[14]
 *  0b1010..nbu_testbus[15]
 *  0b1011-0b1111..reserved
 */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_OVRD_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_OVRD_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN8_OVRD_SEL_MASK)

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_MUX_SEL_MASK (0xF00U)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_MUX_SEL_SHIFT (8U)
/*! DTEST_PIN9_MUX_SEL - DTEST_PIN9_MUX_SEL */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_MUX_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_MUX_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_MUX_SEL_MASK)

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_OVRD_SEL_MASK (0xF000U)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_OVRD_SEL_SHIFT (12U)
/*! DTEST_PIN9_OVRD_SEL - DTEST_PIN9_OVRD_SEL
 *  0b0000..override is disabled
 *  0b0001..aa_sfd_matched
 *  0b0010..rx_pd_fnd
 *  0b0011..agc_gain_change
 *  0b0100..tsm_combined_tx_en
 *  0b0101..tsm_combined_rx_en
 *  0b0110..crc_fail
 *  0b0111..decode_data_out
 *  0b1000..tx_data_out
 *  0b1001..nbu_testbus[14]
 *  0b1010..nbu_testbus[15]
 *  0b1011-0b1111..reserved
 */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_OVRD_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_OVRD_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN9_OVRD_SEL_MASK)

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_MUX_SEL_MASK (0xF0000U)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_MUX_SEL_SHIFT (16U)
/*! DTEST_PIN10_MUX_SEL - DTEST_PIN10_MUX_SEL */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_MUX_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_MUX_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_MUX_SEL_MASK)

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_OVRD_SEL_MASK (0xF00000U)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_OVRD_SEL_SHIFT (20U)
/*! DTEST_PIN10_OVRD_SEL - DTEST_PIN10_OVRD_SEL
 *  0b0000..override is disabled
 *  0b0001..aa_sfd_matched
 *  0b0010..rx_pd_fnd
 *  0b0011..agc_gain_change
 *  0b0100..tsm_combined_tx_en
 *  0b0101..tsm_combined_rx_en
 *  0b0110..crc_fail
 *  0b0111..decode_data_out
 *  0b1000..tx_data_out
 *  0b1001..nbu_testbus[14]
 *  0b1010..nbu_testbus[15]
 *  0b1011-0b1111..reserved
 */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_OVRD_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_OVRD_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_OVRD_SEL_MASK)

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_MUX_SEL_MASK (0xF000000U)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_MUX_SEL_SHIFT (24U)
/*! DTEST_PIN11_MUX_SEL - DTEST_PIN11_MUX_SEL */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_MUX_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_MUX_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_MUX_SEL_MASK)

#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_OVRD_SEL_MASK (0xF0000000U)
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_OVRD_SEL_SHIFT (28U)
/*! DTEST_PIN11_OVRD_SEL - DTEST_PIN11_OVRD_SEL
 *  0b0000..override is disabled
 *  0b0001..aa_sfd_matched
 *  0b0010..rx_pd_fnd
 *  0b0011..agc_gain_change
 *  0b0100..tsm_combined_tx_en
 *  0b0101..tsm_combined_rx_en
 *  0b0110..crc_fail
 *  0b0111..decode_data_out
 *  0b1000..tx_data_out
 *  0b1001..nbu_testbus[14]
 *  0b1010..nbu_testbus[15]
 *  0b1011-0b1111..reserved
 */
#define RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_OVRD_SEL(x) (((uint32_t)(((uint32_t)(x)) << RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_OVRD_SEL_SHIFT)) & RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_OVRD_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RADIO_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group RADIO_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_RADIO_CTRL_H_ */

