/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MIPI_DWC_PHY__
#define FSL_MIPI_DWC_PHY__

#include "fsl_common.h"
#include "fsl_dwc_mipi_csi2rx.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
#define DWC_DPHY_TESTCODE_X_REG					(0x0U)

#define DWC_DPHY_RX_SYS_0					(0x1U)
#define DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_MASK			(0x40U)
#define DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_SHIFT			(6U)
#define DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL(x)			(((uint8_t)(((uint8_t)(x)) << DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_SHIFT)) & DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_MASK)
#define DWC_DPHY_RX_SYS_1					(0x2U)
#define DWC_DPHY_RX_SYS_3					(0x4U)
#define DWC_DPHY_RX_SYS_3_HSDIRECT_MASK				(0x08U)
#define DWC_DPHY_RX_SYS_3_HSDIRECT_SHIFT			(3U)
#define DWC_DPHY_RX_SYS_3_HSDIRECT(x)				(((uint8_t)(((uint8_t)(x)) << DWC_DPHY_RX_SYS_3_HSDIRECT_SHIFT)) & DWC_DPHY_RX_SYS_3_HSDIRECT_MASK)
#define DWC_DPHY_RX_SYS_4					(0x5U)
#define DWC_DPHY_RX_SYS_5					(0x6U)
#define DWC_DPHY_RX_SYS_6					(0x7U)
#define DWC_DPHY_RX_SYS_7					(0x8U)
#define DWC_DPHY_RX_SYS_9					(0xAU)
#define DWC_DPHY_RX_STARTUP_OVR_0				(0xE0U)
#define DWC_DPHY_RX_STARTUP_OVR_0_BYPASS_SKEW_MACHINE_MASK	(0x40U)
#define DWC_DPHY_RX_STARTUP_OVR_0_BYPASS_DDL_TUNING_MASK	(0x08U)
#define DWC_DPHY_RX_STARTUP_OVR_0_BYPASS_OFFSET_MACHINE_MASK	(0x04U)
#define DWC_DPHY_RX_STARTUP_OVR_0_CLK_EN_LNS_TESTER_MASK	(0x02U)
#define DWC_DPHY_RX_STARTUP_OVR_0_CLK_EN_LNS_BYPASS_MASK	(0x01U)
#define DWC_DPHY_RX_STARTUP_OVR_1				(0xE1U)
#define DWC_DPHY_RX_STARTUP_OVR_1_DESKEW_LEGACY_OVR_EN_MASK	(0x20U)
#define DWC_DPHY_RX_STARTUP_OVR_1_DESKEW_LEGACY_OVR_MASK	(0x10U)
#define DWC_DPHY_RX_STARTUP_OVR_1_ENABLE_LNS_OVR_MASK		(0x08U)
#define DWC_DPHY_RX_STARTUP_OVR_1_ENABLE_LNS_OVR_EN_MASK	(0x04U)
#define DWC_DPHY_RX_STARTUP_OVR_1_RXCLK_DDR_CLK_EN_BYPASS_MASK	(0x02U)
#define DWC_DPHY_RX_STARTUP_OVR_1_RX_COMPAT_MODE_OVR_MASK	(0x01U)
#define DWC_DPHY_RX_STARTUP_OVR_2				(0xE2U)
#define DWC_DPHY_RX_STARTUP_OVR_3				(0xE3U)
#define DWC_DPHY_RX_STARTUP_OVR_4				(0xE4U)
#define DWC_DPHY_RX_STARTUP_OVR_4_DDL_OSC_FREQ_OVR_EN_MASK	(0x01U)
#define DWC_DPHY_RX_STARTUP_OVR_4_RX_GMODE_OVR_EN_MASK		(0x02U)
#define DWC_DPHY_RX_STARTUP_OVR_5				(0xE5U)
#define DWC_DPHY_RX_STARTUP_OVR_5_COUNTER_BYPASS_MASK		(0x01U)
#define DWC_DPHY_TESTCODE_X_VAL_0				(0x0U)
#define DWC_DPHY_TESTCODE_X_VAL_1				(0x1U)
#define DWC_DPHY_TESTCODE_X_VAL_3				(0x3U)
#define DWC_DPHY_TESTCODE_X_VAL_5				(0x5U)
#define DWC_DPHY_TESTCODE_X_VAL_7				(0x7U)
#define DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_ENABLE		(0x20U)

/*!
 * @addtogroup dwc_mipi_dphy
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief This function reset the PHY module.
 *
 * @param csi1 CSI2RX primary peripheral address.
 * @param csi2 CSI2RX secondary peripheral address.
 * @param config CSI2RX module configuration structure.
 */
void DWC_DPHY_Reset(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, const csi2rx_config_t *config);

/*!
 * @brief This function resets the PHY module configuration test code.
 *
 * @param csi1 CSI2RX primary peripheral address.
 * @param csi2 CSI2RX secondary peripheral address.
 * @param config CSI2RX module configuration structure.
 */
void DWC_DPHY_TestCodeReset(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, const csi2rx_config_t *config);

/*!
 * @brief This function configures the PHY module register.
 *
 * @param csi1 CSI2RX peripheral address.
 * @param address Address in the PHY module to configure.
 * @param values Configuration value to write to the specified PHY address.
 */
void DWC_DPHY_SetTestConfigureCSI1(PRIMARY_CSI2_CONTROLLER_Type *csi1, uint32_t address, uint8_t values);

/*!
 * @brief This function configure the PHY module register.
 *
 * @param csi2 CSI2RX peripheral address.
 * @param address set by PHY module.
 * @param values change characteristics by writing this value to the PHY address.
 */
void DWC_DPHY_SetTestConfigureCSI2(SECONDARY_CSI2_CONTROLLER_Type *csi2, uint32_t address, uint8_t values);

/*!
 * @brief This function read the PHY module register.
 *
 * @param base CSI2RX peripheral address.
 * @param address read by phy module.
 */
uint32_t DWC_DPHY_ReadTestConfigure(PRIMARY_CSI2_CONTROLLER_Type *base, uint8_t address);

/*!
 * @brief This function configure PHY module hsfreqrange and cfgclkfreqrange.
 *
 * @param base CSI2RX peripheral address.
 * @param config CSI2RX module configuration structure.
 */
void DWC_DPHY_TestCodeConfig(PRIMARY_CSI2_CONTROLLER_Type *base, const csi2rx_config_t *config);

/*!
 * @brief This function init the PHY module as normal mode.
 *
 * @param csi1 CSI2RX primary peripheral address.
 * @param csi2 CSI2RX secondary peripheral address.
 * @param phybase PHY module peripheral address.
 * @param config CSI2RX module configuration structure.
 */
void DWC_DPHY_InitNormal(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config);

/*!
 * @brief This function init the PHY module as aggregate mode.
 *
 * @param csi1 CSI2RX primary peripheral address.
 * @param csi2 CSI2RX secondary peripheral address.
 * @param phybase PHY module peripheral address.
 * @param config CSI2RX module configuration structure.
 */
void DWC_DPHY_InitAggr(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif
