/*
 * Copyright 2012-2020,2022,2023 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PHNXPUCIHAL_H_
#define _PHNXPUCIHAL_H_


#include "zephyr/uwb/uwb_types.h"
#include "phUwbTypes.h"
#include <zephyr/kernel.h>
#include <zephyr/uwb/uci.h>
#include <stdbool.h>

/**
**
** Function:    UwbDeviceInit
**
** Description: Download firmware patch files and apply device configs.
**
** Returns:     None.
**
*/
uint8_t UwbDeviceInit(bool recovery);

#if !(UWBIOT_UWBD_SR040)

/**
 * Function         phNxpUciHal_set_board_config
 *
 * Description      This function is called to set the board variant config
 * Returns          return 0 on success and -1 on fail, On success
 *                  update the actual state of operation in arg pointer
 *
 */
int phNxpUciHal_set_board_config();


#if UWBIOT_UWBD_SR1XXT_SR2XXT

/**
 * Function         phNxpUciHal_SerializeCalibConfig
 *
 * Description      Serialize calibration configuration parameters into UCI command buffer
 *
 * Parameters       pCalibConfig - Array of calibration config structure
 *                  pCmdBuff - Output buffer for UCI command
 *                  pCmdLen - Output parameter for command length
 *
 * Returns          TRUE, if serialization successful, FALSE otherwise
 *
 */
int phNxpUciHal_SerializeCalibConfig(const phUwbCalibConfig_t *pCalibConfig, uint8_t *pCmdBuff, uint16_t *pCmdLen);
#endif /* UWBIOT_UWBD_SR1XXT_SR2XXT */

#endif //!(UWBIOT_UWBD_SR04X)
/**
 * Function         phNxpUciHal_SerializeCoreDevConfig
 *
 * Description      Serialize core device configuration parameters into UCI command buffer
 *
 * Parameters       pCoreDevConfig - Array of device config structures
 *                  numConfigs - Number of configurations in the array
 *                  pCmdBuff - Output buffer for UCI command
 *                  pCmdLen - Output parameter for command length
 *
 * Returns          TRUE, if serialization successful, FALSE otherwise
 *
 */
int phNxpUciHal_SerializeCoreDevConfig(const phUwbCoreDevConfig_t *pCoreDevConfig, uint8_t numConfigs, uint8_t *pCmdBuff, uint16_t *pCmdLen);

#endif /* _PHNXPUCIHAL_H_ */
