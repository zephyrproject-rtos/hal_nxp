/**
 *  Copyright (C) 2011-2012 Broadcom Corporation
 *  Copyright 2018-2022,2023, 2026 NXP.
 *
 *  SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <inttypes.h>
#include <phNxpUwbConfig.h>
#include <UWB_DeviceConfig.h>

#include "zephyr/kernel.h"
#include "phNxpUciHal.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_uwb_config, LOG_LEVEL_INF);

#define DATA_HEADER_LENGTH 4

#if !(UWBIOT_UWBD_SR04X)

/* Local functions declarations */
static const NxpParam_t *phNxpUciHal_NxpParamFind(const unsigned char key);

/**
**
** Function:    phNxpUciHal_NxpParamFind
**
** Description: search if a setting exist in the setting array
**
** Returns:     pointer to the setting object
**
*/
static const NxpParam_t *phNxpUciHal_NxpParamFind(const unsigned char key)
{
    int i;
    int listSize;

    listSize = (sizeof(phNxpUciHal_NXPConfig) / sizeof(NxpParam_t));

    if (listSize == 0)
        return NULL;

    for (i = 0; i < listSize; ++i) {
        if (phNxpUciHal_NXPConfig[i].key == key) {
            if (phNxpUciHal_NXPConfig[i].type == TYPE_DATA) {
                LOG_DBG("%s found key %d, data len = %d\n",
                    __FUNCTION__,
                    key,
                    *((unsigned char *)(phNxpUciHal_NXPConfig[i].val)));
            }
            else {
                LOG_DBG("%s found key %d = (0x%ld)",
                    __FUNCTION__,
                    key,
                    (uintptr_t)phNxpUciHal_NXPConfig[i].val);
            }
            return &(phNxpUciHal_NXPConfig[i]);
        }
    }
    return NULL;
}

int phNxpUciHal_GetNxpByteArrayValue(unsigned char key, void **pValue, long *readlen)
{
    long ucilen;
    if (!pValue) {
        return FALSE;
    }

    const NxpParam_t *pParam = phNxpUciHal_NxpParamFind(key);

    if (pParam == NULL) {
        return FALSE;
    }
    if ((pParam->type == TYPE_DATA) && (pParam->val != 0)) {
        *readlen = (long)((unsigned char *)(pParam->val))[0];
        /* If Over All Length defined in  pParam is greater than 0 then only fetch other component values */
        if (*readlen !=  0)
        {
            *pValue = &(((unsigned char *)pParam->val)[1]);
            ucilen   = (long)((unsigned char *)(pParam->val))[4];
            if (((ucilen + DATA_HEADER_LENGTH) != (*readlen)) && (*readlen != 0x00)) {
                LOG_WRN("%s, found key %d, Core Config Length Error = %ld\n", __FUNCTION__, key, ucilen);
            }
            return TRUE;
        }
    }
    else if ((pParam->type == TYPE_EXTENDED_DATA) && (pParam->val != 0)) {
        unsigned char *pBuffer = &(((unsigned char *)pParam->val)[0]);
        *readlen               = (long)(pBuffer[0]);
        /* If Over All Length defined in  pParam is greater than 0 then only fetch other component values */
        if(*readlen !=0)
        {
            *pValue                = &(pBuffer[2]);
            *readlen |= (long)((pBuffer[1] << 8) & 0xFFFF);
            return TRUE;
        }
    }
    return FALSE;
}

int phNxpUciHal_GetNxpNumValue(unsigned char key, void *pValue, unsigned long len)
{
    if (!pValue) {
        return FALSE;
    }

    const NxpParam_t *pParam = phNxpUciHal_NxpParamFind(key);

    if (pParam == NULL) {
        return FALSE;
    }

    size_t v = (size_t)pParam->val;

    switch (len) {
    case sizeof(unsigned long):
        *((unsigned long *)(pValue)) = (unsigned long)v;
        break;
    case sizeof(unsigned short):
        *((unsigned short *)(pValue)) = (unsigned short)v;
        break;
    case sizeof(unsigned char):
        *((unsigned char *)(pValue)) = (unsigned char)v;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

#endif /* UWBIOT_UWBD_SR04X */

int phNxpUciHal_FormDefaultCoreConfigCmd(uint8_t *pCmdBuff, uint16_t *pCmdLen)
{
    if ((!pCmdBuff) || (!pCmdLen)) {
        LOG_ERR("%s: Invalid parameters\n", __FUNCTION__);
        return FALSE;
    }

#if defined(UWB_DEFAULT_CORE_CONFIGS)
    if (phNxpUciHal_SerializeCoreDevConfig(
            UWB_DEFAULT_CORE_CONFIGS, GET_ARRAY_SIZE(UWB_DEFAULT_CORE_CONFIGS), pCmdBuff, pCmdLen) == FALSE) {
        LOG_ERR("%s: Failed to serialize core config\n", __FUNCTION__);
        return FALSE;
    }
#endif /* UWB_DEFAULT_CORE_CONFIGS */

    return TRUE;
}

#if UWBIOT_UWBD_SR1XXT_SR2XXT

int phNxpUciHal_FormDefaultAntennaCoreConfigCmd(uint8_t *pCmdBuff, uint16_t *pCmdLen)
{
    if ((!pCmdBuff) || (!pCmdLen)) {
        LOG_ERR("%s: Invalid parameters\n", __FUNCTION__);
        return FALSE;
    }

#if defined(UWB_DEFAULT_ANTENNA_CONFIGS)

    if (phNxpUciHal_SerializeCoreDevConfig(
            UWB_DEFAULT_ANTENNA_CONFIGS, GET_ARRAY_SIZE(UWB_DEFAULT_ANTENNA_CONFIGS), pCmdBuff, pCmdLen) == FALSE) {
        LOG_ERR("%s: Failed to serialize core config\n", __FUNCTION__);
        return FALSE;
    }

#endif /* UWB_DEFAULT_ANTENNA_CONFIGS */

    return TRUE;
}

#endif /* UWBIOT_UWBD_SR1XXT_SR2XXT */

#if UWBIOT_UWBD_SR1XXT

int phNxpUciHal_GetCalibCount(void)
{
#if defined(UWB_DEFAULT_CALIBRATION_CONFIGS)
    return GET_ARRAY_SIZE(UWB_DEFAULT_CALIBRATION_CONFIGS);
#else
    return 0;
#endif /* UWB_DEFAULT_CALIBRATION_CONFIGS */
}

int phNxpUciHal_FormDefaultCalibConfigsCmd(uint8_t *pCmdBuff, uint16_t *pCmdLen, uint8_t calib_index)
{
    if ((!pCmdBuff) || (!pCmdLen)) {
        LOG_ERR("%s: Invalid parameters\n", __FUNCTION__);
        return FALSE;
    }

#if defined(UWB_DEFAULT_CALIBRATION_CONFIGS)

    if (phNxpUciHal_GetCalibCount() == 0) {
        LOG_DBG("%s: No calibration configs available\n", __FUNCTION__);
        *pCmdLen = 0;
        /* Return success since there's nothing to configure */
        return TRUE;
    }

    if (phNxpUciHal_SerializeCalibConfig(&UWB_DEFAULT_CALIBRATION_CONFIGS[calib_index], pCmdBuff, pCmdLen) == FALSE) {
        LOG_ERR("%s: Failed to serialize calibration config\n", __FUNCTION__);
        return FALSE;
    }

#endif /* UWB_DEFAULT_CALIBRATION_CONFIGS */
    return TRUE;
}
#endif /* UWBIOT_UWBD_SR1XXT */
