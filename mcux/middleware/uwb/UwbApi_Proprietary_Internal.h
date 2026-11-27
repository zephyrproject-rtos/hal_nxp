/*
 *
 * Copyright 2018-2020,2022,2024,2025 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UWBAPI_PROPRIETARY_INTERNAL_SRXXX_H
#define UWBAPI_PROPRIETARY_INTERNAL_SRXXX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "phUwbTypes.h"
#include "UwbApi_Types.h"
#include "UwbApi_Internal.h"
#include <UwbApi_Types_Proprietary.h>

#if UWBIOT_SESN_SNXXX && !(UWBIOT_SESN_P71)
#include "UwbSeApi.h"

/**
 **
 ** Function         reset_se_on_error
 **
 ** Description      This function is called to cold reset the SE.
 **
 ** Returns          void
 **
 */
EXTERNC void reset_se_on_error(void);
#endif // UWBIOT_SESN_SNXXX

/**
 **
 ** Function         processProprietaryNtf
 **
 ** Description      Process UCI NTFs in the proprietary group
 **
 ** Returns          associated event id
 **
 */
eResponse_Ext_Ntf_Event processProprietaryNtf(uint8_t oid, uint16_t responsePayloadLen, uint8_t *responsePayloadPtr);

/**
 **
 ** Function         processVendorNtf
 **
 ** Description      Process UCI NTFs in the vendor group
 **
 ** Returns          associated event id
 **
 */
eResponse_Ext_Ntf_Event processVendorNtf(uint8_t oid, uint16_t responsePayloadLen, uint8_t *responsePayloadPtr);

#if UWBIOT_UWBD_SR1XXT
/**
 **
 ** Function         processProprietarySeNtf
 **
 ** Description      Process UCI NTFs in the proprietary SE group
 **
 ** Returns          associated event id
 **
 */
eResponse_Ext_Ntf_Event processProprietarySeNtf(uint8_t oid, uint16_t responsePayloadLen, uint8_t *responsePayloadPtr);
#endif // UWBIOT_UWBD_SR1XXT

/**
 **
 ** Function         processInternalNtf
 **
 ** Description      Process UCI NTFs in the Internal group
 **
 ** Returns          void
 **
 */
eResponse_Ext_Ntf_Event processInternalNtf(uint8_t oid, uint16_t responsePayloadLen, uint8_t *responsePayloadPtr);
/**
 **
 ** Function:        extDeviceManagementCallback
 **
 ** Description      Process UCI NTFs in the proprietary group
 **
 ** Returns          void
 **
 */
EXTERNC void extDeviceManagementCallback(uint8_t gid, uint8_t oid, uint16_t paramLength, uint8_t *pResponseBuffer);
/**
 **
 ** Function:        getVendorAppConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for extended application related configs.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getVendorAppConfigTLVBuffer(
    uint8_t paramId, void *paramValue, uint16_t paramValueLen, uint8_t *tlvBuffer);

/**
 **
 ** Function:        getVendorDebugConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for Extended Debug Configs only.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getVendorDebugConfigTLVBuffer(
    uint16_t paramId, void *paramValue, uint16_t paramValueLen, uint8_t *tlvBuffer);

/**
 **
 ** Function:        getExtTestConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for extended test related configs.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getExtDeviceConfigTLVBuffer(uint8_t paramId, void *paramValue, uint8_t *tlvBuffer);

/**
 **
 ** Function:        getExtTestConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for extended test related configs.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getExtTestConfigTLVBuffer(uint16_t paramId, void *paramValue, uint8_t *tlvBuffer);

/**
 **
 ** Function:        parseDebugParams
 **
 ** Description:     Extracts Debug Params from the given byte array and updates
 *the structure
 **
 ** Returns:         None
 **
 */
EXTERNC void parseDebugParams(uint8_t *rspPtr, uint8_t noOfParams, UWB_DebugParams_List_t *DebugParams_List);

/**
 **
 ** Function:        DebugConfig_TlvParser
 **
 ** Description:     Debug configuration Tlv parser
 **
 ** Returns:         status
 **
 */
EXTERNC tUWBAPI_STATUS DebugConfig_TlvParser(
    const UWB_DebugParams_List_t *pDebugParams_List, UWB_Debug_Params_value_t *pOutput_param_value);

/**
* @brief Parse Device Information
* \param[out] pdevInfo           Pointer to structure of device information data
* \param[in]  deviceInfoData   Pointer to Device Information data buffer
* \param[in]  deviceInfoLength Length of Device Information data buffer
*
* \retval #TRUE   Parse success
* \retval #FALSE  Parse failure
*/
EXTERNC BOOLEAN parseDeviceInfo(phUwbDevInfo_t *pdevInfo, uint8_t *deviceInfoData, uint16_t deviceInfoLength);

/**
 ** Function:        getExtCoreDeviceConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for Ext Core Device configs.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getExtCoreDeviceConfigTLVBuffer(
    uint16_t paramId, uint8_t paramLen, void *paramValue, uint8_t *tlvBuffer);

/**
 **
 ** Function:        parseExtGetDeviceConfigResponse
 **
 ** Description:     Convert received UCI response to deviceConfig object
 **
 ** Returns:         None
 **
 */
EXTERNC void parseExtGetDeviceConfigResponse(uint8_t *tlvBuffer, phDeviceConfigData_t *devConfig);

/**
 **
 ** Function:        setDefaultCoreConfigs
 **
 ** Description:     Sets all core configs. Default values are picked from
 **                  config file(phNxpUciHal_RhodesConfig.h)
 **
 ** Returns:         Status
 **
 */
EXTERNC tUWBAPI_STATUS setDefaultCoreConfigs(void);

/**
 *  Function         setVendorConfigs
 *
 * Description      This function is called during init process to
 *                  apply vendor configs from the config file
 *
 * Returns          status , success or failure
 *
 */
EXTERNC tUWBAPI_STATUS setVendorConfigs(void);


/**
 * Function     :    recoverUWBS
 *
 * Description  :    function to recover from crash, cmd timeout.
 *
 * Returns      :    status
 *
 *
 */
EXTERNC tUWBAPI_STATUS recoverUWBS(void);

/**
 **
 ** Function:        getTestConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for test configs.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getTestConfigTLVBuffer(uint8_t paramId, uint8_t paramLen, void *paramValue, uint8_t *tlvBuffer);

EXTERNC BOOLEAN doParseManufacturerDevInfo(phUwbDevInfo_t *pdevInfo, uint8_t *manufacturerData, uint16_t manufacturerLength);

#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif // UWBAPI_PROPRIETARY_INTERNAL_SRXXX_H
