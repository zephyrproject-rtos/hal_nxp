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
 * @brief This function poweroff the PHY module.
 *
 * @param base CSI2RX peripheral address.
 */
void DWC_DPHY_PowerOff(PRIMARY_CSI2_CONTROLLER_Type *base);

/*!
 * @brief This function reset the PHY module.
 *
 * @param base CSI2RX peripheral address.
 */
void DWC_DPHY_Reset(PRIMARY_CSI2_CONTROLLER_Type *base);

/*!
 * @brief This function reset the PHY module configure test code.
 *
 * @param base CSI2RX peripheral address.
 */
void DWC_DPHY_TestCodeReset(PRIMARY_CSI2_CONTROLLER_Type *base);

/*!
 * @brief This function configure the PHY module register.
 *
 * @param base CSI2RX peripheral address.
 * @param address set by PHY module.
 * @param values change characteristics by writing this value to the PHY address.
 */
void DWC_DPHY_SetTestConfigure(PRIMARY_CSI2_CONTROLLER_Type *base, uint32_t address, uint8_t values);

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
void DWC_DPHY_TestCodeConfig(PRIMARY_CSI2_CONTROLLER_Type *base, csi2rx_config_t *config);

/*!
 * @brief This function init the PHY module..
 *
 * @param csibase CSI2RX peripheral address.
 * @param phybase PHY module periperal address.
 * @param config CSI2RX module configuration structure.
 */
status_t DWC_DPHY_Init(PRIMARY_CSI2_CONTROLLER_Type *csibase, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif
