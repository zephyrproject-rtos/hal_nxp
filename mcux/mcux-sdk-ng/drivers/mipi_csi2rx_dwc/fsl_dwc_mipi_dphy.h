/*
 * Copyright 2023 NXP
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
/* DPHY module control registers, for details, refer to MIPI D-PHY v1.2 Rx 4L for TSMC 16-nm FFC/1.8V Databook */
/* System configuration 0 */
#define DPHY_RX_SYS_0                                   0x01
#define HSFREQRANGE_OVR_EN_RW                           0x20

/* System configuration 1 */
#define DPHY_RX_SYS_1                                   0x02
#define HSFREQRANGE_OVR_RW(x)                           ((x) & 0x7F)
#define TIMEBASE_OVR_EN_RW                              0x10

/* System configuration 2 */
#define DPHY_RX_SYS_2                                   0x03
#define TIMEBASE_OVR_RW(x)                              ((x) & 0xFF)

#define DWC_DPHY_DATALANE1              (0x1U)
#define DWC_DPHY_DATALANE2              (0x2U)
#define DWC_DPHY_DATALANE3              (0x4U)
#define DWC_DPHY_DATALANE4              (0x8U)

/*! @name Driver version */
/*@{*/
/*! @brief DWC PHY driver version. */
#define FSL_DWC_PHY_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @addtogroup
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief introduce function DWC_DPHY_PowerOff.
 * This function poweroff the PHY module.
 *
 * @param base CSI2RX peripheral address.
 */
void DWC_DPHY_PowerOff(CAMERA_MIPI_CSI2_Type *base);

/*!
 * @brief introduce function DWC_DPHY_Reset.
 * This function reset the PHY module.
 *
 * @param base CSI2RX peripheral address.
 */
void DWC_DPHY_Reset(CAMERA_MIPI_CSI2_Type *base);

/*!
 * @brief introduce function DWC_DPHY_TestCodeReset.
 * This function reset the PHY module configure test code.
 *
 * @param base CSI2RX peripheral address.
 */
void DWC_DPHY_TestCodeReset(CAMERA_MIPI_CSI2_Type *base);

/*!
 * @brief introduce function DWC_DPHY_SetTestConfigure.
 * This function configure the PHY module register.
 *
 * @param base CSI2RX peripheral address.
 * @param address set by PHY module.
 * @param values change characteristics by writing this value to the PHY address.
 */
void DWC_DPHY_SetTestConfigure(CAMERA_MIPI_CSI2_Type *base, uint32_t address, uint8_t values);

/*!
 * @brief introduce function DWC_DPHY_ReadTestConfigure.
 * This function read the PHY module register.
 *
 * @param base CSI2RX peripheral address.
 * @param address read by phy module.
 */
uint32_t DWC_DPHY_ReadTestConfigure(CAMERA_MIPI_CSI2_Type *base, uint8_t address);

/*!
 * @brief introduce function DWC_DPHY_TestCodeConfig.
 * This function configure PHY module hsfreqrange and cfgclkfreqrange.
 *
 * @param base CSI2RX peripheral address.
 * @param config CSI2RX module configuration structure.
 */
void DWC_DPHY_TestCodeConfig(CAMERA_MIPI_CSI2_Type *base, csi2rx_config_t *config);

/*!
 * @brief introduce function DWC_DPHY_Init.
 * This function deal with PHY module initialization.
 *
 * @param csibase CSI2RX peripheral address.
 * @param phybase PHY module periperal address.
 * @param config CSI2RX module configuration structure.
 */
status_t DWC_DPHY_Init(CAMERA_MIPI_CSI2_Type *csibase, CAMERA_DSI_OR_CSI_PHY_CSR_Type *phybase, csi2rx_config_t *config);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
