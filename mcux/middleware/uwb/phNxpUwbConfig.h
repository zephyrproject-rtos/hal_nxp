/**
 *
 *  Copyright (C) 2011-2012 Broadcom Corporation
 *  Copyright 2018-2021,2023, 2026 NXP.
 *
 *  SPDX-License-Identifier: Apache-2.0
 */

#ifndef __NXPCONFIG_H
#define __NXPCONFIG_H

#include <phNxpUciHal_CoreConfig.h>

/**
**
** Function:    GetNumValue
**
** Description: API function for getting a numerical value of a setting
**
** Returns:     TRUE, if successful
**
*/
int phNxpUciHal_GetNxpNumValue(unsigned char key, void *p_value, unsigned long len);

#if !(UWBIOT_UWBD_SR04X)
/**
**
** Function:    GetByteArrayValue()
**
** Description: Read byte array value from the config file.
**
** Parameters:
**              name    - name of the config param to read.
**              pValue  - pointer to input buffer.
**              len     - input buffer length.
**              readlen - out parameter to return the number of bytes read from
**                        config file
**                        return -1 in case bufflen is not enough.
**
** Returns:     TRUE[1] if config param name is found in the config file, else
**              FALSE[0]
**
*/
int phNxpUciHal_GetNxpByteArrayValue(unsigned char key, void **pValue, long *readlen);

/**
**
** Function:    phNxpUciHal_GetCalibCount
**
** Description: Get the number of calibration configurations
**
** Parameters:  None
**
** Returns:     Number of calibration configurations
**
*/
int phNxpUciHal_GetCalibCount();


#endif // #if !(UWBIOT_UWBD_SR04X)

/**
**
** Function:    phNxpUciHal_FormDefaultAntennaCoreConfigCmd
**
** Description: Set default antenna configuration parameters
**
** Parameters:
**              pCmdBuff - pointer to command buffer.
**              pCmdLen  - pointer to command length.
**
** Returns:     TRUE[1] if successful, else FALSE[0]
**
*/
int phNxpUciHal_FormDefaultAntennaCoreConfigCmd(uint8_t *pCmdBuff, uint16_t *pCmdLen);

/**
**
** Function:    phNxpUciHal_FormDefaultCalibConfigsCmd
**
** Description: Set default calibration configuration parameters
**
** Parameters:
**              pCmdBuff - pointer to command buffer.
**              pCmdLen  - pointer to command length.
**              calib_index - calibration configuration index.
**
** Returns:     TRUE[1] if successful, else FALSE[0]
**
*/
int phNxpUciHal_FormDefaultCalibConfigsCmd(uint8_t *pCmdBuff, uint16_t *pCmdLen, uint8_t calib_index);

/**
**
** Function:    phNxpUciHal_FormDefaultCoreConfigCmd
**
** Description: Set default core configuration parameters
**
** Parameters:
**              pCmdBuff - pointer to command buffer.
**              pCmdLen  - pointer to command length.
**
** Returns:     TRUE[1] if successful, else FALSE[0]
**
*/
int phNxpUciHal_FormDefaultCoreConfigCmd(uint8_t *pCmdBuff, uint16_t *pCmdLen);

#endif // __NXPCONFIG_H
