/*
 *
 * Copyright 2021-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */
#include "uci_prop_defs.h"
#include "uci_ext_defs.h"
#include "UwbApi_Utility.h"
#include "zephyr/kernel.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_uwb_api_util, LOG_LEVEL_INF);

#if UWBFTR_TWR
static void parseTwoWayRangingNtf(uint8_t *p, uint16_t len, phRangingData_t *pRngData);
#endif // UWBFTR_TWR

#if UWBFTR_DL_TDoA_Tag
static void parseDlTDoARangingNtfV1(uint8_t *p, uint16_t len, phRangingData_t *pRngData);
static void parseDlTDoARangingNtfV2(uint8_t *p, uint16_t len, phRangingData_t *pRngData);
#endif // UWBFTR_DL_TDoA_Tag

#if UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)
static void parseOneWayRangingNtf(uint8_t *p, uint16_t len, phRangingData_t *pRngData);
#endif // UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
static void parseOwrWithAoaNtf(uint8_t *p, uint16_t len, phRangingData_t *pRngData);
#endif // (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)

#if UWBFTR_Radar
static void parseRadarCirNtf(uint8_t *p, uint16_t len, phUwbRadarNtf_t *pRadarNtf);
static void parseRadarTestNtf(uint8_t *p, uint16_t len, phUwbRadarNtf_t *pRadarNtf);
static void parseRadarPresence_detection_Ntf(uint8_t *p, uint16_t len, phUwbRadarNtf_t *pRadarNtf);
#endif // UWBFTR_Radar

tUWBAPI_STATUS sendUciCommandAndWait(uint16_t event, uint16_t cmdLen, uint8_t *pCmd)
{
    tUWBAPI_STATUS status = UWBAPI_STATUS_OK;

    // status = UWA_SendUciCommand(event, cmdLen, pCmd, 0);

    // if (UWBAPI_STATUS_OK == status) {
    //     if (k_sem_take(&uwbContext.devMgmtSem, UWB_MAX_DEV_MGMT_RSP_TIMEOUT) !=
    //         UWB_STATUS_CODE_SUCCESS) {
    //         LOG_ERR("%s : event timedout", __FUNCTION__);
    //         return UWBAPI_STATUS_TIMEOUT;
    //     }
    //     status = uwbContext.wstatus;
    // }
    return status;
}

tUWBAPI_STATUS sendUciCommand(uint16_t event, uint16_t cmdLen, uint8_t *pCmd, uint8_t pbf)
{
    tUWBAPI_STATUS status = UWBAPI_STATUS_OK;

    // // status = UWA_SendUciCommand(event, cmdLen, pCmd, pbf);
    // if (UWBAPI_STATUS_OK == status) {
    //     status = uwbContext.wstatus;
    // }
    return status;
}

#if !(UWBIOT_UWBD_SR04X)
uint16_t serializeTestDataPayload(uint16_t psduLen, uint8_t psduData[], uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL || psduData == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
    UWB_ARRAY_TO_STREAM(pCmdBuf, psduData, psduLen, offset);
    return offset;
}
#endif //!(UWBIOT_UWBD_SR04X)

#if !(UWBIOT_UWBD_SR04X)
uint16_t serializeDoChipCalibPayload(uint8_t channel, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
    UWB_UINT8_TO_STREAM(pCmdBuf, channel, offset);
    return offset;
}

uint16_t serializeSetCalibPayload(
    uint8_t channel, eCalibParam paramId, uint8_t *calibrationValue, uint16_t length, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL || calibrationValue == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
    UWB_UINT8_TO_STREAM(pCmdBuf, channel, offset);

    if (((paramId >> 8) & 0xFF) != EXTENTED_CALIB_PARAM_ID) {
        UWB_UINT8_TO_STREAM(pCmdBuf, paramId, offset);
        UWB_UINT8_TO_STREAM(pCmdBuf, length, offset);
    }
    else {
        UWB_UINT8_TO_STREAM(pCmdBuf, (paramId >> 8), offset);
        UWB_UINT8_TO_STREAM(pCmdBuf, (paramId & 0x00FF), offset);
        UWB_UINT16_TO_STREAM(pCmdBuf, length, offset);
    }

    UWB_ARRAY_TO_STREAM(pCmdBuf, calibrationValue, length, offset);
    return offset;
}

uint16_t serializeGetCalibPayload(phGetCalibInputParams_t *pCalibInput, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;

    if (pCmdBuf == NULL || pCalibInput == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }

    UWB_UINT8_TO_STREAM(pCmdBuf, pCalibInput->channel, offset);

    if (((pCalibInput->paramId >> 8) & 0xFF) != EXTENTED_CALIB_PARAM_ID) {
        UWB_UINT8_TO_STREAM(pCmdBuf, pCalibInput->paramId, offset);
    }
    else {
        /**
         * In case of AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT the Calibration Param Id is of 2 bytes
         * 1 Byte of Param Id (EXTENTED_CALIB_PARAM_ID)
         * 1 byte of sub Param Id (AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT)
         */
        UWB_UINT16_TO_BE_STREAM(pCmdBuf, pCalibInput->paramId, offset);
    }

#if UWBFTR_AoA_FoV
    /** rxAntennaPairID to be considered only in case of AOA_ANTENNAS_PDOA_CALIB and
     * AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT */
    if ((AOA_ANTENNAS_PDOA_CALIB == pCalibInput->paramId) ||
        (AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT == pCalibInput->paramId)) {
        UWB_UINT8_TO_STREAM(pCmdBuf, pCalibInput->rxAntennaPairID, offset);
    }
#endif // UWBFTR_AoA_FoV

#if UWBFTR_Radar
    // radarMode to be considered only in case of RADAR_LO_GATING
    if (RADAR_LO_GATING == pCalibInput->paramId) {
        UWB_UINT8_TO_STREAM(pCmdBuf, pCalibInput->radarMode, offset);
    }
#endif // UWBFTR_Radar


    return offset;
}

#if (UWBIOT_SESN_SNXXX)
uint16_t serializeSeLoopTestPayload(uint16_t loopCnt, uint16_t timeInterval, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    UWB_UINT16_TO_STREAM(pCmdBuf, loopCnt, offset);
    UWB_UINT16_TO_STREAM(pCmdBuf, timeInterval, offset);
    return offset;
}
#endif //(UWBIOT_SESN_SNXXX)
#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR100S)
uint16_t serializecalibIntegrityProtectionPayload(eCalibTagOption tagOption, uint16_t calibBitMask, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    UWB_UINT8_TO_STREAM(pCmdBuf, tagOption, offset);
    UWB_UINT16_TO_STREAM(pCmdBuf, calibBitMask, offset);
    return offset;
}

uint16_t serializeVerifyCalibDataPayload(uint8_t *pCmacTag, uint8_t tagOption, uint16_t tagVersion, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    UWB_ARRAY_TO_STREAM(pCmdBuf, pCmacTag, UCI_TAG_CMAC_LENGTH, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, tagOption, offset);
    UWB_UINT16_TO_STREAM(pCmdBuf, tagVersion, offset);
    return offset;
}

uint16_t serializeConfigureAuthTagOptionsPayload(
    uint8_t deviceTag, uint8_t modelTag, uint16_t labelValue, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    UWB_UINT8_TO_STREAM(pCmdBuf, deviceTag, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, modelTag, offset);
    UWB_UINT16_TO_STREAM(pCmdBuf, labelValue, offset);

    return offset;
}

uint16_t serializeConfigureAuthTagVersionPayload(uint16_t labelValue, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    UWB_UINT16_TO_STREAM(pCmdBuf, labelValue, offset);
    return offset;
}
#endif //UWBIOT_UWBD_SR100T  || UWBIOT_UWBD_SR100S
#if (UWBIOT_SESN_SNXXX)
uint16_t serializeUrskDeletionRequestPayload(uint8_t noOfSessionIds, uint32_t *pSessionIdList, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;

    UWB_UINT8_TO_STREAM(pCmdBuf, noOfSessionIds, offset);

    for (int i = 0; i < noOfSessionIds; i++) {
        UWB_UINT32_TO_STREAM(pCmdBuf, pSessionIdList[i], offset);
    }

    return offset;
}
#endif //(UWBIOT_SESN_SNXXX)

#if UWBIOT_UWBD_SR1XXT

uint16_t serializeWriteOtpCalibDataPayload(
    uint8_t channel, uint8_t writeOption, uint8_t writeDataLen, uint8_t *writeData, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    UWB_UINT8_TO_STREAM(pCmdBuf, channel, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, writeOption, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, writeDataLen, offset);
    UWB_ARRAY_TO_STREAM(pCmdBuf, writeData, writeDataLen, offset);

    return offset;
}

uint16_t serializeReadOtpCalibDataPayload(
    uint8_t channel, uint8_t readOption, eOtpCalibParam calibParam, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    UWB_UINT8_TO_STREAM(pCmdBuf, channel, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, readOption, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, calibParam, offset);

    return offset;
}
#endif // UWBIOT_UWBD_SR1XXT

#endif //!(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR04X)
uint16_t serializeSessionNvmPayload(esessionNvmManage sesNvmManageTag, uint32_t sessionHandle, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;

    switch (sesNvmManageTag) {
    case SESSION_NVM_MANAGE_PERSIST:
#if 0
    case SESSION_NVM_MANAGE_DELETE: /* Not available */
#endif

        UWB_UINT8_TO_STREAM(pCmdBuf, sesNvmManageTag, offset);
        UWB_UINT32_TO_STREAM(pCmdBuf, sessionHandle, offset);
        break;
    case SESSION_NVM_MANAGE_DELETE_ALL:
        UWB_UINT8_TO_STREAM(pCmdBuf, sesNvmManageTag, offset);
        break;
    default:
        return offset;
    }

    return offset;
}

#endif /* (UWBIOT_UWBD_SR04X) */

uint16_t serializeTrngtPayload(uint8_t trng_size, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
    UWB_UINT8_TO_STREAM(pCmdBuf, trng_size, offset);
    return offset;
}

#if (UWBFTR_BlobParser)
uint16_t serializeSetProfileParamsPayload(
    phUwbProfileInfo_t *pProfileInfo, uint16_t blobSize, uint8_t *pProfileBlob, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL || pProfileInfo == NULL || pProfileBlob == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
    UWB_UINT8_TO_STREAM(pCmdBuf, pProfileInfo->profileId, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, pProfileInfo->deviceType, offset);
    UWB_ARRAY_TO_STREAM(pCmdBuf, pProfileInfo->mac_addr, SHORT_MAC_ADDR_LEN, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, pProfileInfo->deviceRole, offset);
    UWB_ARRAY_TO_STREAM(pCmdBuf, pProfileBlob, blobSize, offset);
    return offset;
}

uint16_t serializeUwbDeviceConfigData(UwbDeviceConfigData_t *pUwbDeviceConfig, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL || pUwbDeviceConfig == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
#if (UWBIOT_UWBD_SR04X)
    if (pUwbDeviceConfig->isFindhubEnabled == false) {
        UWB_ARRAY_TO_STREAM(
            pCmdBuf, pUwbDeviceConfig->spec_ver_major, sizeof(pUwbDeviceConfig->spec_ver_major), offset);
        UWB_ARRAY_TO_STREAM(
            pCmdBuf, pUwbDeviceConfig->spec_ver_minor, sizeof(pUwbDeviceConfig->spec_ver_minor), offset);
        UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->chip_id, sizeof(pUwbDeviceConfig->chip_id), offset);
        UWB_ARRAY_TO_STREAM(
            pCmdBuf, pUwbDeviceConfig->chip_fw_version, sizeof(pUwbDeviceConfig->chip_fw_version), offset);
        UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->mw_version, sizeof(pUwbDeviceConfig->mw_version), offset);
        UWB_UINT32_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->supported_config_ids, offset);
        UWB_UINT8_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->ranging_role, offset);
        UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->device_mac_addr, SHORT_MAC_ADDR_LEN, offset);
    }
    else {
        UWB_UINT8_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->ranging_technology_role, offset);
        UWB_UINT8_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->payload_size, offset);
        UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->device_mac_addr, SHORT_MAC_ADDR_LEN, offset);
        UWB_UINT32_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->supported_channels, offset);
        UWB_UINT32_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->preamble_index, offset);
        UWB_UINT32_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->supported_config_ids, offset);
        UWB_UINT16_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->ranging_interval, offset);
        UWB_UINT8_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->slot_duration, offset);
        UWB_UINT8_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->ranging_role, offset);
    }
#endif //UWBIOT_UWBD_SR04X
#if (UWBIOT_UWBD_SR1XXT_SR2XXT)
    UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->spec_ver_major, sizeof(pUwbDeviceConfig->spec_ver_major), offset);
    UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->spec_ver_minor, sizeof(pUwbDeviceConfig->spec_ver_minor), offset);
    UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->chip_id, sizeof(pUwbDeviceConfig->chip_id), offset);
    UWB_ARRAY_TO_STREAM(
        pCmdBuf, pUwbDeviceConfig->chip_fw_version, sizeof(pUwbDeviceConfig->chip_fw_version), offset);
    UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->mw_version, sizeof(pUwbDeviceConfig->mw_version), offset);
    UWB_UINT32_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->supported_config_ids, offset);
    UWB_UINT8_TO_BE_STREAM(pCmdBuf, pUwbDeviceConfig->ranging_role, offset);
    UWB_ARRAY_TO_STREAM(pCmdBuf, pUwbDeviceConfig->device_mac_addr, SHORT_MAC_ADDR_LEN, offset);
#endif //UWBIOT_UWBD_SR1XXT_SR2XXT
    return offset;
}
void serializeUwbPhoneConfigData(UwbPhoneConfigData_t *pUwbPhoneConfig, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
#if (UWBIOT_UWBD_SR04X)
    if (pUwbPhoneConfig->isFindhubEnabled == false) {
        // Legacy parsing
        UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->spec_ver_major[0], MAX_SPEC_VER_LEN, offset);
        UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->spec_ver_minor[0], MAX_SPEC_VER_LEN, offset);
        UWB_BE_STREAM_TO_UINT32(pUwbPhoneConfig->session_id, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->preamble_id, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->channel_number, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->config_id, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->device_ranging_role, pCmdBuf, offset);
        UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->phone_mac_address[0], SHORT_MAC_ADDR_LEN, offset);
        pUwbPhoneConfig->session_key_len = 0; // No session key in legacy
        memset(pUwbPhoneConfig->session_key, 0, sizeof(pUwbPhoneConfig->session_key));
    }
    else {
        // New flow parsing
        offset += 2; // Skip UWB byte and length byte
        UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->phone_mac_address[0], SHORT_MAC_ADDR_LEN, offset);
        UWB_BE_STREAM_TO_UINT32(pUwbPhoneConfig->session_id, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->config_id, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->channel_number, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->preamble_id, pCmdBuf, offset);
        UWB_BE_STREAM_TO_UINT16(pUwbPhoneConfig->ranging_interval, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->slot_duration, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->session_key_len, pCmdBuf, offset);
        bool isSessionKeyExpected =
            ((pUwbPhoneConfig->config_id == UWB_CONFIG_ID_4) || (pUwbPhoneConfig->config_id == UWB_CONFIG_ID_5) ||
                (pUwbPhoneConfig->config_id == UWB_CONFIG_ID_6));
        if (isSessionKeyExpected) {
            if ((pUwbPhoneConfig->session_key_len == RANGING_SESSION_KEY_LEN_16) ||
                (pUwbPhoneConfig->session_key_len == RANGING_SESSION_KEY_LEN_32)) {
                UWB_STREAM_TO_ARRAY(pCmdBuf, pUwbPhoneConfig->session_key, pUwbPhoneConfig->session_key_len, offset);
            }
            else {
                LOG_ERR("%s: Expected session key for config_id %d but got invalid length %d",
                    __FUNCTION__,
                    pUwbPhoneConfig->config_id,
                    pUwbPhoneConfig->session_key_len);
                memset(pUwbPhoneConfig->session_key, 0, sizeof(pUwbPhoneConfig->session_key));
                pUwbPhoneConfig->session_key_len = 0;
                UWB_STREAM_TO_ARRAY(pCmdBuf, pUwbPhoneConfig->session_key, pUwbPhoneConfig->session_key_len, offset);
            }
        }
        else {
            // Static STS case
            if (pUwbPhoneConfig->session_key_len > 8) {
                LOG_ERR("%s: Expected session key for config_id %d is 8 but got invalid length %d",
                    __FUNCTION__,
                    pUwbPhoneConfig->config_id,
                    pUwbPhoneConfig->session_key_len);
                memset(pUwbPhoneConfig->session_key, 0, sizeof(pUwbPhoneConfig->session_key));
                pUwbPhoneConfig->session_key_len = 0;
            }
            UWB_STREAM_TO_ARRAY(pCmdBuf, pUwbPhoneConfig->session_key, pUwbPhoneConfig->session_key_len, offset);
        }

        UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->country_code[0], SHORT_MAC_ADDR_LEN, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->device_mode, pCmdBuf, offset);
        UWB_STREAM_TO_UINT8(pUwbPhoneConfig->device_ranging_role, pCmdBuf, offset);
    }
#endif //UWBIOT_UWBD_SR04X
#if (UWBIOT_UWBD_SR1XXT_SR2XXT)
    UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->spec_ver_major[0], MAX_SPEC_VER_LEN, offset);
    UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->spec_ver_minor[0], MAX_SPEC_VER_LEN, offset);
    UWB_BE_STREAM_TO_UINT32(pUwbPhoneConfig->session_id, pCmdBuf, offset);
    UWB_STREAM_TO_UINT8(pUwbPhoneConfig->preamble_id, pCmdBuf, offset);
    UWB_STREAM_TO_UINT8(pUwbPhoneConfig->channel_number, pCmdBuf, offset);
    UWB_STREAM_TO_UINT8(pUwbPhoneConfig->config_id, pCmdBuf, offset);
    UWB_STREAM_TO_UINT8(pUwbPhoneConfig->device_ranging_role, pCmdBuf, offset);
    UWB_STREAM_TO_ARRAY(pCmdBuf, &pUwbPhoneConfig->phone_mac_address[0], SHORT_MAC_ADDR_LEN, offset);
#endif //(UWBIOT_UWBD_SR1XXT_SR2XXT || UWBIOT_UWBD_SR04X)
}
#endif // (UWBFTR_BlobParser




#if UWBFTR_TWR // support only for DSTWR
/**
 *
 * Function:        parseTwoWayRangingNtf
 *
 * Description:     Extracts Ranging Params from the given byte array for two way ranging
 *
 * Returns:         None
 *
 */
static void parseTwoWayRangingNtf(uint8_t *p, uint16_t len, phRangingData_t *pRngData)
{
    uint8_t i       = 0;
    uint32_t offset = 0;
    if (pRngData->no_of_measurements > MAX_NUM_RESPONDERS) {
        LOG_ERR("%s: Wrong number of measurements received:%d", __FUNCTION__, pRngData->no_of_measurements);
        return;
    }
    for (i = 0; i < pRngData->no_of_measurements; i++) {
        if (pRngData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(&pRngData->ranging_meas.range_meas_twr[i].mac_addr[0], p, SHORT_MAC_ADDR_LEN, offset);
        }
        else if (pRngData->mac_addr_mode_indicator == EXTENDED_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(&pRngData->ranging_meas.range_meas_twr[i].mac_addr[0], p, UWB_EXTENDED_MAC_ADDRESS_LEN, offset);
        }
        else {
            LOG_ERR("%s: Invalid mac addressing indicator", __FUNCTION__);
            return;
        }
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].status, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].nLos, p, offset);
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_twr[i].distance, p, offset);
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_twr[i].aoa_azimuth, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].aoa_azimuth_FOM, p, offset);
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_twr[i].aoa_elevation, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].aoa_elevation_FOM, p, offset);
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_twr[i].aoa_dest_azimuth, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].aoa_dest_azimuth_FOM, p, offset);
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_twr[i].aoa_dest_elevation, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].aoa_dest_elevation_FOM, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].slot_index, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_twr[i].rssi, p, offset);
        /** Skip the RFU bytes
         * if mac address format is short, then skip 11 bytes
         * if mac address format is extended, then skip 5 bytes */
        if (pRngData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE) {
            offset = offset + RFU_SHORT_MAC_ADD;
        }
        else {
            offset = offset + RFU_EXT_MAC_ADD;
        }
        /* Update the received notification length */
        len = (uint16_t)(len - MAX_TWR_RNG_DATA_NTF_OFFSET);
    }
    /*check whether vendor specific data is received  or not*/
    if (len > 0U) {
#if UWBIOT_UWBD_SR04X
        UWB_STREAM_TO_UINT16(pRngData->vs_length, p, offset);
        if (pRngData->vs_length > 0) {
            UWB_STREAM_TO_UINT8(pRngData->antenna_info, p, offset);
            UWB_STREAM_TO_UINT8(pRngData->rssi, p, offset);
            // Future parameters can be added here
        }
        else {
            LOG_WRN("%s %d: Vendor specific data length is %d ", __FUNCTION__,pRngData->vs_length);
        }
#endif //#if (UWBIOT_UWBD_SR04X)
#if !(UWBIOT_UWBD_SR04X)
        // vendor specific data length
        UWB_STREAM_TO_UINT16(pRngData->vs_length, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        /*check whether vendor specific data is received  or not*/
        if ((pRngData->vs_length <= sizeof(VENDORSPECIFIC_MEAS)) && (pRngData->vs_length > 0U)) {
            // vendor specific data type
            UWB_STREAM_TO_UINT8(pRngData->vs_data_type, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));

            if (pRngData->vs_data_type == NXP_SPECIFIC_DATA_TYPE_WITH_MSG_CNTRL) {
                UWB_STREAM_TO_UINT32(pRngData->message_control, p, offset);
                len = (uint16_t)(len - sizeof(pRngData->message_control));
            }
            // Parse bit b0 of 0th octet of message_control
            pRngData->vs_data.twr.isTxAntInfoPreset = (bool)(pRngData->message_control & BIT(0));

            // Parse bit b0 of 2nd octet of message_control
            pRngData->vs_data.twr.isDistanceMmPresent = (bool)((pRngData->message_control >> 16) & BIT(0));

            // Parse bit b1 of 2nd octet of message_control
            pRngData->vs_data.twr.isRxAntDebugInfoPresent = (bool)((pRngData->message_control >> 16) & BIT(1));

            // If b0 of 0th octet of message_control is set then TX_ANTENNA_INFO is present
            if (pRngData->vs_data.twr.isTxAntInfoPreset) {
                LOG_DBG("TX_ANTENNA_INFO is present in message control!!");
                UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.txAntennaInfo, p, offset);
                len = (uint16_t)(len - sizeof(uint8_t));
            }
            else {
                LOG_DBG("TX_ANTENNA_INFO is not present in message control");
            }

            /** NXP Specific Data (FIXED PART)*/
            UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.wifiCoExStatus, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.rxInfoMesr_twr.rxMode, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            UWB_STREAM_TO_ARRAY(&pRngData->vs_data.twr.rxInfoMesr_twr.rx_antennaIdRxInfo[0],
                p,
                pRngData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo,
                offset);
            len = (uint16_t)(len - (sizeof(uint8_t)) * pRngData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo);

            /* Rx Antenna Info For Debug Notifications */
            if (pRngData->vs_data.twr.isRxAntDebugInfoPresent) {
                UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.rxInfoDebugNtf_twr.numOfRframes, p, offset);
            }
            else {
                UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.rxInfoDebugNtf_twr.rxModeDebugNtf, p, offset);
            }
            len = (uint16_t)(len - sizeof(uint8_t));
            UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            UWB_STREAM_TO_ARRAY(&pRngData->vs_data.twr.rxInfoDebugNtf_twr.rx_antennaIdDebugNtf[0],
                p,
                pRngData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf,
                offset);
            len = (uint16_t)(
                len - (sizeof(uint8_t)) * pRngData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf);

            /** Repetition part (These fields are repeated for each responder)*/
            for (i = 0; i < pRngData->no_of_measurements; i++) {
                for (int j = 0; j < pRngData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo; j++) {
                    /** AoA / PDoA measurements per RX entry*/
                    UWB_STREAM_TO_INT16(pRngData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].angleOfArrival, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                    UWB_STREAM_TO_INT16(pRngData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].pdoa, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                    UWB_STREAM_TO_UINT16(pRngData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].pdoaIndex, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
#if UWBFTR_AoA_FoV
                    /** FoV Specific Data */
                    if (pRngData->vs_data_type == FOV_SPECIFIC_DATA_TYPE) {
                        UWB_STREAM_TO_UINT8(pRngData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].aoaFovFlag, p, offset);
                        len = (uint16_t)(len - sizeof(uint8_t));
                    }
#endif // UWBFTR_AoA_FoV
                }
                for (int k = 0; k < pRngData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf; k++) {
                    /** SNRFirst / SNRMain / FirstIndex / Main Index : measurements per RX entry*/
                    UWB_STREAM_TO_UINT8(
                        pRngData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rxSnrFirstPath, p, offset);
                    len = (uint16_t)(len - sizeof(uint8_t));
                    UWB_STREAM_TO_UINT8(
                        pRngData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rxSnrMainPath, p, offset);
                    len = (uint16_t)(len - sizeof(uint8_t));
                    UWB_STREAM_TO_INT16(
                        pRngData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rx_FirstPathIndex, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                    UWB_STREAM_TO_INT16(
                        pRngData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rx_MainPathIndex, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                    if (pRngData->vs_data.twr.isRxAntDebugInfoPresent) {
                        /** SNRTotal / RSSI : measurements per RX entry if Rx Antenna Debug Info reported for all RFrames*/
                        UWB_STREAM_TO_INT16(
                            pRngData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].snrTotal, p, offset);
                        len = (uint16_t)(len - sizeof(uint16_t));
                        UWB_STREAM_TO_INT16(pRngData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rssi, p, offset);
                        len = (uint16_t)(len - sizeof(uint16_t));
                    }
                }

                if ((pRngData->vs_data.twr.rxInfoMesr_twr.rxMode == kUWBAntCfgRxMode_ToA_Rfm_Mode) ||
                    (pRngData->vs_data.twr.rxInfoMesr_twr.rxMode == kUWBAntCfgRxMode_AoA_Rfm_Mode)) {
                    UWB_STREAM_TO_UINT16(pRngData->vs_data.twr.vsMesr[i].distance_2, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                }
                if (pRngData->vs_data.twr.isDistanceMmPresent) {
                    UWB_STREAM_TO_UINT32(pRngData->vs_data.twr.vsMesr[i].distance_mm, p, offset);
                    len = (uint16_t)(len - sizeof(uint32_t));
                }
            }
        }
        else {
            LOG_ERR(
                "%s: session info ntf vendor specific length exceeds the buffer limit value %d : received length "
                "%d",
                __FUNCTION__,
                sizeof(VENDORSPECIFIC_MEAS),
                pRngData->vs_length);
            return;
        }
        /** TODO: Need to handle as mandatory field in future*/
        if (len >= sizeof(uint8_t)) {
            UWB_STREAM_TO_UINT8(pRngData->authInfoPrsen, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            if (pRngData->authInfoPrsen != 0) {
                UWB_STREAM_TO_ARRAY(&pRngData->authenticationTag[0], p, AUTH_TAG_IN_16BYTES, offset);
                len = (uint16_t)(len - AUTH_TAG_IN_16BYTES);
            }
        }
#endif // !(UWBIOT_UWBD_SR04X)
    }
}
#endif // UWBFTR_TWR

#if UWBFTR_DL_TDoA_Tag
/**
 *
 * Function:        parseDlTDoARangingNtfV1
 *
 * Description:     Extracts Ranging Params from the given byte array for Dl TDOA ranging for Version 1
 *
 * Returns:         None
 *
 */
static void parseDlTDoARangingNtfV1(uint8_t *p, uint16_t len, phRangingData_t *pRngData)
{
    uint16_t actRngRounds = 0x00; /** Number of active ranging */
    uint32_t offset       = 0;

    for (uint8_t i = 0; i < pRngData->no_of_measurements; i++) {
        if (pRngData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa[i].mac_addr[0], p, SHORT_MAC_ADDR_LEN, offset);
            len = (uint16_t)(len - SHORT_MAC_ADDR_LEN);
        }
        else if (pRngData->mac_addr_mode_indicator == EXTENDED_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(&pRngData->ranging_meas.range_meas_dltdoa[i].mac_addr[0], p, UWB_EXTENDED_MAC_ADDRESS_LEN, offset);
            len = (uint16_t)(len - UWB_EXTENDED_MAC_ADDRESS_LEN);
        }
        else {
            LOG_ERR("%s: Invalid mac addressing indicator", __FUNCTION__);
            return;
        }
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa[i].status, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa[i].message_type, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_dltdoa[i].message_control, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_dltdoa[i].block_index, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa[i].round_index, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa[i].nLoS, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa[i].aoa_azimuth, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa[i].aoa_azimuth_fom, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa[i].aoa_elevation, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa[i].aoa_elevation_fom, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa[i].rssi, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        /** 64-bit TX timestamp */
        if ((pRngData->ranging_meas.range_meas_dltdoa[i].message_control & TX_TIMESTAMP_LEN) == TX_TIMESTAMP_LEN) {
            /* 8 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa[i].tx_timestamp[0], p, MAX_RX_TX_TIMESTAMP, offset);
            len = (uint16_t)(len - MAX_RX_TX_TIMESTAMP);
        }
        /** 40-bit TX timestamp */
        else if ((pRngData->ranging_meas.range_meas_dltdoa[i].message_control & TX_TIMESTAMP_LEN) == 0) {
            /* 5 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa[i].tx_timestamp[0], p, MAX_RX_TX_TIMESTAMP - 3, offset);
            len = (uint16_t)(len - (MAX_RX_TX_TIMESTAMP - 3));
        }
        /** 64-bit RX timestamp */
        if ((pRngData->ranging_meas.range_meas_dltdoa[i].message_control & RX_TIMESTAMP_LEN) == RX_TIMESTAMP_LEN) {
            /* 8 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa[i].rx_timestamp[0], p, MAX_RX_TX_TIMESTAMP, offset);
            len = (uint16_t)(len - MAX_RX_TX_TIMESTAMP);
        }
        /** 40-bit RX timestamp */
        else if ((pRngData->ranging_meas.range_meas_dltdoa[i].message_control & RX_TIMESTAMP_LEN) == 0) {
            /* 5 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa[i].rx_timestamp[0], p, MAX_RX_TX_TIMESTAMP - 3, offset);
            len = (uint16_t)(len - (MAX_RX_TX_TIMESTAMP - 3));
        }

        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa[i].cfo_anchor, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa[i].cfo, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT32(pRngData->ranging_meas.range_meas_dltdoa[i].reply_time_initiator, p, offset);
        len = (uint16_t)(len - sizeof(uint32_t));
        UWB_STREAM_TO_UINT32(pRngData->ranging_meas.range_meas_dltdoa[i].reply_time_responder, p, offset);
        len = (uint16_t)(len - sizeof(uint32_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_dltdoa[i].initiator_responder_tof, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));

        if ((pRngData->ranging_meas.range_meas_dltdoa[i].message_control & ANCHOR_LOCATION_WGS84) ==
            ANCHOR_LOCATION_WGS84) {
            /** DT-Anchor location is included in WGS-84 coordinate system - 12 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa[i].anchor_location[0], p, MAX_ANCHOR_LOCATIONS, offset);
            len = (uint16_t)(len - MAX_ANCHOR_LOCATIONS);
        }
        else if ((pRngData->ranging_meas.range_meas_dltdoa[i].message_control & ANCHOR_LOCATION_REL) ==
                 ANCHOR_LOCATION_REL) {
            /** DT-Anchor location is included in a relative coordinate system - 10 Octets*/
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa[i].anchor_location[0], p, (MAX_ANCHOR_LOCATIONS - 2), offset);
            len = (uint16_t)(len - (MAX_ANCHOR_LOCATIONS - 2));
        }
        else if ((pRngData->ranging_meas.range_meas_dltdoa[i].message_control & ANCHOR_LOCATION_WGS84) == 0) {
            /** DT-Anchor location is not included - 0 Octets */
        }
        actRngRounds = (pRngData->ranging_meas.range_meas_dltdoa[i].message_control >> ACTIVE_RR_OFSET) & MAX_ACTIVE_RR;
        UWB_STREAM_TO_ARRAY(
            &pRngData->ranging_meas.range_meas_dltdoa[i].active_ranging_rounds[0], p, actRngRounds, offset);
        len = (uint16_t)(len - actRngRounds);
    }
#if !(UWBIOT_UWBD_SR04X)
    /*check whether data is present or not*/
    /** TODO: Need to handle as mandatory field in future*/
    if (len >= sizeof(uint32_t)) {
        /** Antenna Rx Configuration information used in current ranging round*/
        UWB_STREAM_TO_UINT32(pRngData->antenna_pairInfo, p, offset);
        len = (uint16_t)(len - sizeof(uint32_t));
    }
    if (len >= sizeof(uint8_t)) {
        /** Status code for WLAN during ranging RR*/
        UWB_STREAM_TO_UINT8(pRngData->wifiCoExStatusCode, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
    }
    if (len >= sizeof(uint8_t)) {
        /** Indicator for presence of Authentication Tag*/
        UWB_STREAM_TO_UINT8(pRngData->authInfoPrsen, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        if (pRngData->authInfoPrsen != 0) {
            /**Authentication Tag*/
            UWB_STREAM_TO_ARRAY(&pRngData->authenticationTag[0], p, AUTH_TAG_IN_16BYTES, offset);
            len = (uint16_t)(len - AUTH_TAG_IN_16BYTES);
        }
    }
#endif // !(UWBIOT_UWBD_SR04X)
}

/**
 *
 * Function:        parseDlTDoARangingNtfV2
 *
 * Description:     Extracts Ranging Params from the given byte array for Dl TDOA ranging for Measurement Type 2
 *
 * Returns:         None
 *
 */
static void parseDlTDoARangingNtfV2(uint8_t *p, uint16_t len, phRangingData_t *pRngData)
{
    uint16_t actRngRounds = 0x00; /** Number of active ranging */
    uint32_t offset       = 0;
    uint8_t timestamp_len = 0;

    for (uint8_t i = 0; i < pRngData->no_of_measurements; i++) {
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_dltdoa_v2[i].measurement_size, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        if (pRngData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa_v2[i].mac_addr[0], p, SHORT_MAC_ADDR_LEN, offset);
            len = (uint16_t)(len - SHORT_MAC_ADDR_LEN);
        }
        else if (pRngData->mac_addr_mode_indicator == EXTENDED_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(&pRngData->ranging_meas.range_meas_dltdoa_v2[i].mac_addr[0], p, EXT_MAC_ADDR_LEN, offset);
            len = (uint16_t)(len - EXT_MAC_ADDR_LEN);
        }
        else {
            LOG_ERR("%s: Invalid mac addressing indicator", __FUNCTION__);
            return;
        }
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].status, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].message_type, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_dltdoa_v2[i].block_index, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].round_index, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].nLoS, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa_v2[i].aoa_azimuth, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].aoa_azimuth_fom, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa_v2[i].aoa_elevation, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].aoa_elevation_fom, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].rssi, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa_v2[i].cfo_anchor, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_INT16(pRngData->ranging_meas.range_meas_dltdoa_v2[i].cfo, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT32(pRngData->ranging_meas.range_meas_dltdoa_v2[i].reply_time_initiator, p, offset);
        len = (uint16_t)(len - sizeof(uint32_t));
        UWB_STREAM_TO_UINT32(pRngData->ranging_meas.range_meas_dltdoa_v2[i].reply_time_responder, p, offset);
        len = (uint16_t)(len - sizeof(uint32_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_dltdoa_v2[i].initiator_responder_tof, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].rx_timestamp_length, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        timestamp_len = pRngData->ranging_meas.range_meas_dltdoa_v2[i].rx_timestamp_length;
        UWB_STREAM_TO_ARRAY(
            &pRngData->ranging_meas.range_meas_dltdoa_v2[i].rx_timestamp[0], p, timestamp_len, offset);
        len = (uint16_t)(len - timestamp_len);
        UWB_STREAM_TO_UINT32(pRngData->ranging_meas.range_meas_dltdoa_v2[i].message_control, p, offset);
        len = (uint16_t)(len - sizeof(uint32_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].tx_timestamp_length, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        timestamp_len = pRngData->ranging_meas.range_meas_dltdoa_v2[i].tx_timestamp_length;
        UWB_STREAM_TO_ARRAY(
            &pRngData->ranging_meas.range_meas_dltdoa_v2[i].tx_timestamp[0], p, timestamp_len, offset);
        len = (uint16_t)(len - timestamp_len);
        pRngData->ranging_meas.range_meas_dltdoa_v2[i].active_ranging_rounds_length = 0;
        if ((pRngData->ranging_meas.range_meas_dltdoa_v2[i].message_control & ACTIVE_RANGING_ROUNDS_MASK) != 0) {
            UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].active_ranging_rounds_length, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            actRngRounds = pRngData->ranging_meas.range_meas_dltdoa_v2[i].active_ranging_rounds_length;
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa_v2[i].active_ranging_rounds[0], p, actRngRounds, offset);
            len = (uint16_t)(len - actRngRounds);
        }
        pRngData->ranging_meas.range_meas_dltdoa_v2[i].anchor_location_length = 0;
        if ((pRngData->ranging_meas.range_meas_dltdoa_v2[i].message_control & ACTIVE_LOCATION_MASK) != 0) {
            UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].anchor_location_length, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            actRngRounds = pRngData->ranging_meas.range_meas_dltdoa_v2[i].anchor_location_length;
            if (actRngRounds > MAX_ANCHOR_LOCATIONS_V2) {
                LOG_ERR("%s: Anchor location length exceeds max: %d > %d",
                    __FUNCTION__, actRngRounds, MAX_ANCHOR_LOCATIONS_V2);
                return;
            }
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_dltdoa_v2[i].anchor_location[0], p, actRngRounds, offset);
            len = (uint16_t)(len - actRngRounds);
        }
        if ((pRngData->ranging_meas.range_meas_dltdoa_v2[i].message_control & SUPERCLUSTER_MASK) != 0) {
            UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_dltdoa_v2[i].supercluster_id, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
        }
    }
}
#endif // UWBFTR_DL_TDoA_Tag

#if UWBFTR_TransitProp
/*******************************************************************************
**
** Function         serializeSessionSetRdsParam
**
** Description      serialize Session Set RDS Param CMD
**
** Returns          Length of payload
**
*******************************************************************************/
uint16_t serializeSessionSetRdsParam(phSetRdsPramCmd_t *pRdsParam, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;

    UWB_UINT8_TO_STREAM(pCmdBuf, pRdsParam->rdsParamListSize, offset);

    for (uint8_t i = 0; i < pRdsParam->rdsParamListSize; i++) {
        UWB_UINT32_TO_STREAM(pCmdBuf, pRdsParam->rdsParamList[i].sessionHandle, offset);
        UWB_ARRAY_TO_STREAM(pCmdBuf, pRdsParam->rdsParamList[i].macAddr, SHORT_MAC_ADDR_LEN, offset);
        UWB_ARRAY_TO_STREAM(
            pCmdBuf, pRdsParam->rdsParamList[i].rangingDataSet, pRdsParam->rdsParamList[i].rdsLength, offset);
        UWB_UINT32_TO_STREAM(pCmdBuf, pRdsParam->rdsParamList[i].lastPhyStsIndex, offset);
    }

    return offset;
}

#endif // UWBFTR_TransitProp

#if UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)
/**
 *
 * Function:        parseOneWayRangingNtf
 *
 * Description:     Extracts Ranging Params from the given byte array for one way ranging
 *
 * Returns:         None
 *
 */
static void parseOneWayRangingNtf(uint8_t *p, uint16_t len, phRangingData_t *pRngData)
{
    uint8_t message_control = 0x00;
    uint32_t offset         = 0;

    for (uint8_t i = 0; i < pRngData->no_of_measurements; i++) {
        if (pRngData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(&pRngData->ranging_meas.range_meas_tdoa[i].mac_addr[0], p, SHORT_MAC_ADDR_LEN, offset);
            len = (uint16_t)(len - SHORT_MAC_ADDR_LEN);
        }
        else if (pRngData->mac_addr_mode_indicator == EXTENDED_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(&pRngData->ranging_meas.range_meas_tdoa[i].mac_addr[0], p, UWB_EXTENDED_MAC_ADDRESS_LEN, offset);
            len = (uint16_t)(len - UWB_EXTENDED_MAC_ADDRESS_LEN);
        }
        else {
            LOG_ERR("%s: Invalid MAC addressing indicator", __FUNCTION__);
            return;
        }
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_tdoa[i].status, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_tdoa[i].message_control, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_tdoa[i].frame_type, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_tdoa[i].nLos, p, offset);
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_tdoa[i].aoa_azimuth, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_tdoa[i].aoa_azimuth_FOM, p, offset);
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_tdoa[i].aoa_elevation, p, offset);
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_tdoa[i].aoa_elevation_FOM, p, offset);
        UWB_STREAM_TO_UINT32(pRngData->ranging_meas.range_meas_tdoa[i].frame_number, p, offset);
        len = (uint16_t)(len - ONEWAY_RFU_BYTE_OFFSET);

        message_control = pRngData->ranging_meas.range_meas_tdoa[i].message_control;
        // Set initial values as 0, if not present for Tx timestamp and device ID
        memset(&pRngData->ranging_meas.range_meas_tdoa[i].tx_timestamp, 0, ULTDOA_64BIT_IN_BYTES);
        memset(&pRngData->ranging_meas.range_meas_tdoa[i].ul_tdoa_device_id, 0, ULTDOA_64BIT_IN_BYTES);

        if ((message_control & ULTDOA_64BIT_RX_TIMESTAMP_MASK) == ULTDOA_64BIT_RX_TIMESTAMP_MASK) {
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_tdoa[i].rx_timestamp[0], p, ULTDOA_64BIT_IN_BYTES, offset);
            len = (uint16_t)(len - sizeof(uint64_t));
        }
        else {
            /* 5 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_tdoa[i].rx_timestamp[0], p, ULTDOA_40BIT_IN_BYTES, offset);
            len = (uint16_t)(len - ULTDOA_40BIT_IN_BYTES);
        }

        if ((message_control & ULTDOA_DEVICE_ID_MASK) == ULTDOA_DEVICE_ID_16BIT_VALUE) {
            /* 2 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_tdoa[i].ul_tdoa_device_id[0], p, ULTDOA_16BIT_IN_BYTES, offset);
            len = (uint16_t)(len - sizeof(uint16_t));
        }
        else if ((message_control & ULTDOA_DEVICE_ID_MASK) == ULTDOA_DEVICE_ID_32BIT_VALUE) {
            /* 4 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_tdoa[i].ul_tdoa_device_id[0], p, ULTDOA_32BIT_IN_BYTES, offset);
            len = (uint16_t)(len - sizeof(uint32_t));
        }
        else if ((message_control & ULTDOA_DEVICE_ID_MASK) == ULTDOA_DEVICE_ID_64BIT_VALUE) {
            /* 8 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_tdoa[i].ul_tdoa_device_id[0], p, ULTDOA_64BIT_IN_BYTES, offset);
            len = (uint16_t)(len - sizeof(uint64_t));
        }

        if ((message_control & ULTDOA_40BIT_TX_TIMESTAMP_MASK) == ULTDOA_40BIT_TX_TIMESTAMP_MASK) {
            /* 5 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_tdoa[i].tx_timestamp[0], p, ULTDOA_40BIT_IN_BYTES, offset);
            len = (uint16_t)(len - ULTDOA_40BIT_IN_BYTES);
        }
        if ((message_control & ULTDOA_64BIT_TX_TIMESTAMP_MASK) == ULTDOA_64BIT_TX_TIMESTAMP_MASK) {
            /* 8 Octets */
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_tdoa[i].tx_timestamp[0], p, ULTDOA_64BIT_IN_BYTES, offset);
            len = (uint16_t)(len - sizeof(uint64_t));
        }
    }
    if (len > 0U) {
#if (UWBIOT_UWBD_SR04X)
        uint16_t vendor_spec_length = 0;
        /*check whether vendor specific data is received  or not*/
        UWB_STREAM_TO_UINT16(vendor_spec_length, p, offset);

        if (vendor_spec_length == sizeof(uint8_t)) {
            UWB_STREAM_TO_UINT8(pRngData->antenna_info, p, offset);
        }
#endif /* (UWBIOT_UWBD_SR04X) */
#if !(UWBIOT_UWBD_SR04X)
        // vendor specific data length
        UWB_STREAM_TO_UINT16(pRngData->vs_length, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        /*check whether vendor specific data is received or not*/
        if (pRngData->vs_length > 0U) {
            /** Vendor specific data type*/
            UWB_STREAM_TO_UINT8(pRngData->vs_data.tdoa.vendorExtLength, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            if ((pRngData->vs_data.tdoa.vendorExtLength > 0)) {
                /** NXP Specific Data (FIXED PART)*/
                UWB_STREAM_TO_INT16(pRngData->vs_data.tdoa.rssi_rx1, p, offset);
                len = (uint16_t)(len - sizeof(uint16_t));
                UWB_STREAM_TO_INT16(pRngData->vs_data.tdoa.rssi_rx2, p, offset);
                len = (uint16_t)(len - sizeof(uint16_t));
                UWB_STREAM_TO_UINT8(pRngData->vs_data.tdoa.noOfPdoaMeasures, p, offset);
                len = (uint16_t)(len - sizeof(uint8_t));
                /** Repitition part (This fields are repeated for each responder)*/
                for (uint8_t k = 0; k < pRngData->vs_data.tdoa.noOfPdoaMeasures; k++) {
                    /** AoA / PDoA measurements per RX entry*/
                    UWB_STREAM_TO_INT16(pRngData->vs_data.tdoa.pdoa[k], p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                    UWB_STREAM_TO_UINT16(pRngData->vs_data.tdoa.pdoaIndex[k], p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                }
            }
#if UWBIOT_UWBD_SR2XXT
            UWB_STREAM_TO_UINT16(pRngData->vs_data.tdoa.message_control_extension, p, offset);
            len = (uint16_t)(len - sizeof(uint16_t));
            /* Fixed part*/
            UWB_STREAM_TO_UINT8(pRngData->vs_data.tdoa.rx3_ext_info_len, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            /** Currently only 2 bytes of data for RX3 is expected, in future it might change */
            UWB_STREAM_TO_INT16(pRngData->vs_data.tdoa.rssi_rx3, p, offset);
            len = (uint16_t)(len - sizeof(uint16_t));
#endif // UWBIOT_UWBD_SR2XXT
        }
        else {
            LOG_ERR(
                "%s: session info ntf vendor specific length exceeds the buffer limit value %d : received length "
                "%d",
                __FUNCTION__,
                sizeof(VENDORSPECIFIC_MEAS),
                pRngData->vs_length);
            return;
        }
        /** TODO: Need to handle as mandatory field in future*/
        if (len >= sizeof(uint32_t)) {
            /** Antenna Rx Configuration information used in current ranging round*/
            UWB_STREAM_TO_UINT32(pRngData->antenna_pairInfo, p, offset);
            len = (uint16_t)(len - sizeof(uint32_t));
        }
        if (len >= sizeof(uint8_t)) {
            /** Status code for WLAN during ranging RR*/
            UWB_STREAM_TO_UINT8(pRngData->wifiCoExStatusCode, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
        }
        if (len >= sizeof(uint8_t)) {
            /** Indicator for presence of Authentication Tag*/
            UWB_STREAM_TO_UINT8(pRngData->authInfoPrsen, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            if (pRngData->authInfoPrsen != 0U) {
                /**Authentication Tag*/
                UWB_STREAM_TO_ARRAY(&pRngData->authenticationTag[0], p, AUTH_TAG_IN_16BYTES, offset);
                len = (uint16_t)(len - AUTH_TAG_IN_16BYTES);
            }
        }
#endif // !(UWBIOT_UWBD_SR04X)
    }
}
#endif // UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
/**
 *
 * Function:        parseOwrWithAoaNtf
 *
 * Description:     Extracts Ranging Params from the given byte array for OWR with AoA
 *
 * Returns:         None
 *
 */
static void parseOwrWithAoaNtf(uint8_t *p, uint16_t len, phRangingData_t *pRngData)
{
    uint32_t offset = 0;
    for (uint8_t i = 0; i < pRngData->no_of_measurements; i++) {
        if (pRngData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(
                &pRngData->ranging_meas.range_meas_owr_aoa[i].mac_addr[0], p, SHORT_MAC_ADDR_LEN, offset);
            len = (uint16_t)(len - SHORT_MAC_ADDR_LEN);
        }
        else if (pRngData->mac_addr_mode_indicator == EXTENDED_MAC_ADDRESS_MODE) {
            UWB_STREAM_TO_ARRAY(&pRngData->ranging_meas.range_meas_owr_aoa[i].mac_addr[0], p, UWB_EXTENDED_MAC_ADDRESS_LEN, offset);
            len = (uint16_t)(len - UWB_EXTENDED_MAC_ADDRESS_LEN);
        }
        else {
            LOG_ERR("%s: Invalid mac addressing indicator", __FUNCTION__);
            return;
        }
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_owr_aoa[i].status, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_owr_aoa[i].nLos, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_owr_aoa[i].frame_seq_num, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_owr_aoa[i].block_index, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_owr_aoa[i].aoa_azimuth, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_owr_aoa[i].aoa_azimuth_FOM, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        UWB_STREAM_TO_UINT16(pRngData->ranging_meas.range_meas_owr_aoa[i].aoa_elevation, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        UWB_STREAM_TO_UINT8(pRngData->ranging_meas.range_meas_owr_aoa[i].aoa_elevation_FOM, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
    }
    if (len > 0U) {
        /** Vendor specific data Length*/
        UWB_STREAM_TO_UINT16(pRngData->vs_length, p, offset);
        len = (uint16_t)(len - sizeof(uint16_t));
        /*check whether vendor specific data is received  or not*/
        if ((pRngData->vs_length <= sizeof(VENDORSPECIFIC_MEAS)) && (pRngData->vs_length > 0U)) {
            /** Vendor specific data type*/
            UWB_STREAM_TO_UINT8(pRngData->vs_data_type, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            /** NXP Specific Data (FIXED PART)*/
            /** Rx Antenna Info for AoA Measurements*/
            UWB_STREAM_TO_UINT8(pRngData->vs_data.owr_aoa.rxInfoMesr_owr.rxMode, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            UWB_STREAM_TO_UINT8(pRngData->vs_data.owr_aoa.rxInfoMesr_owr.num_of_rx_antennaRxInfo, p, offset);
            len = (uint16_t)(len - sizeof(uint8_t));
            UWB_STREAM_TO_ARRAY(&pRngData->vs_data.owr_aoa.rxInfoMesr_owr.rx_antennaIdRxInfo[0],
                p,
                pRngData->vs_data.owr_aoa.rxInfoMesr_owr.num_of_rx_antennaRxInfo,
                offset);
            len =
                (uint16_t)(len - (sizeof(uint8_t) * pRngData->vs_data.owr_aoa.rxInfoMesr_owr.num_of_rx_antennaRxInfo));

            for (uint8_t i = 0; i < pRngData->no_of_measurements; i++) {
                for (int j = 0; j < pRngData->vs_data.owr_aoa.rxInfoMesr_owr.num_of_rx_antennaRxInfo; j++) {
                    /** Repitition part(This fields are repeated for each responder)*/
                    /** AoA / PDoA measurements per RX entry*/
                    /** Angle of arrival*/
                    UWB_STREAM_TO_INT16(
                        pRngData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[j].angleOfArrival, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                    /** Phase difference of arrival*/
                    UWB_STREAM_TO_INT16(pRngData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[j].pdoa, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
                    /** Phase difference of arrival index in the whole CIR */
                    UWB_STREAM_TO_INT16(pRngData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[j].pdoaIndex, p, offset);
                    len = (uint16_t)(len - sizeof(uint16_t));
#if UWBFTR_AoA_FoV
                    /** FoV Specific Data */
                    if (pRngData->vs_data_type == FOV_SPECIFIC_DATA_TYPE) {
                        UWB_STREAM_TO_UINT8(
                            pRngData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[j].aoaFovFlag, p, offset);
                        len = (uint16_t)(len - sizeof(uint8_t));
                    }
#endif // UWBFTR_AoA_FoV
                }
                /**RSSI*/
                UWB_STREAM_TO_INT16(pRngData->vs_data.owr_aoa.vsMesr[i].rssi, p, offset);
                len = (uint16_t)(len - sizeof(uint16_t));
            }
        }
        else {
            LOG_ERR(
                "%s: session info ntf vendor specific length exceeds the buffer limit value %d : received length "
                "%d",
                __FUNCTION__,
                sizeof(VENDORSPECIFIC_MEAS),
                pRngData->vs_length);
            return;
        }
    }

    /*check whether data is present or not*/
    /** TODO: Need to handle as mandatory field in future*/
    if (len >= sizeof(uint8_t)) {
        UWB_STREAM_TO_UINT8(pRngData->authInfoPrsen, p, offset);
        len = (uint16_t)(len - sizeof(uint8_t));
        if (pRngData->authInfoPrsen != 0) {
            UWB_STREAM_TO_ARRAY(&pRngData->authenticationTag[0], p, AUTH_TAG_IN_16BYTES, offset);
            len = (uint16_t)(len - AUTH_TAG_IN_16BYTES);
        }
    }
}
#endif //(UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)

void parseRangingNtf(uint8_t *p, uint16_t len, phRangingData_t *pRngData)
{
    uint32_t offset = 0;
    UWB_STREAM_TO_UINT32(pRngData->seq_ctr, p, offset);
    UWB_STREAM_TO_UINT32(pRngData->sessionHandle, p, offset);
    UWB_STREAM_TO_UINT8(pRngData->rcr_indication, p, offset);
    UWB_STREAM_TO_UINT32(pRngData->curr_range_interval, p, offset);
    UWB_STREAM_TO_UINT8(pRngData->ranging_measure_type, p, offset);
    offset++; // skip rfu byte
    UWB_STREAM_TO_UINT8(pRngData->mac_addr_mode_indicator, p, offset);
    UWB_STREAM_TO_UINT32(pRngData->sessionHandle_of_primary_session, p, offset);
    offset = offset + RESERVED_LEN; // skip reserved bytes
    UWB_STREAM_TO_UINT8(pRngData->no_of_measurements, p, offset);
    len = (uint16_t)(len - MAC_ADDR_OFFSET);

    if ((pRngData->ranging_measure_type != MEASUREMENT_TYPE_TWOWAY) &&
        (pRngData->ranging_measure_type != MEASUREMENT_TYPE_ONEWAY) &&
        (pRngData->ranging_measure_type != MEASUREMENT_TYPE_DLTDOA_V1) &&
        (pRngData->ranging_measure_type != MEASUREMENT_TYPE_OWR_WITH_AOA) &&
        (pRngData->ranging_measure_type != MEASUREMENT_TYPE_DLTDOA_V2)) {
        LOG_ERR("%s: Measurement type not matched", __FUNCTION__);
    }

#if UWBFTR_TWR // support only for DSTWR
    if (pRngData->ranging_measure_type == MEASUREMENT_TYPE_TWOWAY) {
        parseTwoWayRangingNtf((p + offset), len, pRngData);
    }
#endif // UWBFTR_TWR
#if (UWBFTR_UL_TDoA_Anchor) && !(UWBIOT_UWBD_SR04X)
    if (pRngData->ranging_measure_type == MEASUREMENT_TYPE_ONEWAY) {
        parseOneWayRangingNtf((p + offset), len, pRngData);
    }
#endif // UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)
#if UWBFTR_DL_TDoA_Tag
    if (pRngData->ranging_measure_type == MEASUREMENT_TYPE_DLTDOA_V1) {
        parseDlTDoARangingNtfV1((p + offset), len, pRngData);
    }
    else if (pRngData->ranging_measure_type == MEASUREMENT_TYPE_DLTDOA_V2) {
        parseDlTDoARangingNtfV2((p + offset), len, pRngData);
    }
#endif // UWBFTR_DL_TDoA_Tag
#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
    if (pRngData->ranging_measure_type == MEASUREMENT_TYPE_OWR_WITH_AOA) {
        parseOwrWithAoaNtf((p + offset), len, pRngData);
    }
#endif //(UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
}

#if UWBFTR_CCC && !(UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
void parseCccRangingNtf(uint8_t *p, uint16_t len, phCccRangingData_t *pCccRangingData)
{
    uint32_t offset = 0;
    uint8_t iter    = 0;
    UWB_STREAM_TO_UINT32(pCccRangingData->sessionHandle, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->rangingStatus, p, offset);
    UWB_STREAM_TO_UINT32(pCccRangingData->stsIndex, p, offset);
    UWB_STREAM_TO_UINT16(pCccRangingData->rangingRoundIndex, p, offset);
    UWB_STREAM_TO_UINT16(pCccRangingData->distance, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->uncertanityAnchorFom, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->uncertanityInitiatorFom, p, offset);
    UWB_STREAM_TO_ARRAY(pCccRangingData->ccmTag, p, MAX_CCM_TAG_SIZE, offset);
    UWB_STREAM_TO_INT16(pCccRangingData->aoa_azimuth, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->aoa_azimuth_FOM, p, offset);
    UWB_STREAM_TO_INT16(pCccRangingData->aoa_elevation, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->aoa_elevation_FOM, p, offset);
    /** Antenna Pair Info*/
    UWB_STREAM_TO_UINT8(pCccRangingData->antenna_pair_info.configMode, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->antenna_pair_info.antPairId1, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->antenna_pair_info.antPairId2, p, offset);
    UWB_STREAM_TO_UINT8(pCccRangingData->antenna_pair_info.rfu, p, offset);
    /** PDoA Measurements*/
    UWB_STREAM_TO_UINT8(pCccRangingData->noOfPdoaMeasures, p, offset);
    for (iter = 0; iter < pCccRangingData->noOfPdoaMeasures; iter++) {
        UWB_STREAM_TO_INT16(pCccRangingData->pdoaMeasurements[iter].pdoa, p, offset);
        UWB_STREAM_TO_UINT16(pCccRangingData->pdoaMeasurements[iter].pdoaIndex, p, offset);
    }
    /** RSSI Measurements */
    UWB_STREAM_TO_UINT8(pCccRangingData->noOfRssiMeasurements, p, offset);
    if (pCccRangingData->noOfRssiMeasurements <= MAX_NO_OF_CCC_RSSI_MEASUREMENTS) {
        for (iter = 0; iter < pCccRangingData->noOfRssiMeasurements; iter++) {
            UWB_STREAM_TO_INT16(pCccRangingData->rssiMeasurements[iter].rssi_rx1, p, offset);
            UWB_STREAM_TO_INT16(pCccRangingData->rssiMeasurements[iter].rssi_rx2, p, offset);
        }
    }
    else {
        LOG_WRN("%s: Invalid Range of RSSI Measurements : %d, Expected was %d",
            __FUNCTION__,
            pCccRangingData->noOfRssiMeasurements,
            MAX_NO_OF_CCC_RSSI_MEASUREMENTS);
    }
    /** SNR Measurements */
    UWB_STREAM_TO_UINT8(pCccRangingData->noOfSnrMeasurements, p, offset);
    if (pCccRangingData->noOfSnrMeasurements <= MAX_NO_OF_CCC_SNR_MEASUREMENTS) {
        for (size_t i = 0; i < pCccRangingData->noOfSnrMeasurements; i++) {
            UWB_STREAM_TO_UINT8(pCccRangingData->snrMeasurements[i].slotIndexAndAntennaMap, p, offset);
            UWB_STREAM_TO_UINT8(pCccRangingData->snrMeasurements[i].snrMainPath, p, offset);
            UWB_STREAM_TO_UINT8(pCccRangingData->snrMeasurements[i].snrFirstPath, p, offset);
            UWB_STREAM_TO_UINT16(pCccRangingData->snrMeasurements[i].snrTotal, p, offset);
        }
    }
    else {
        LOG_WRN("%s: Invalid Range of SNR Measurements : %d, Expected was %d",
            __FUNCTION__,
            pCccRangingData->noOfSnrMeasurements,
            MAX_NO_OF_CCC_SNR_MEASUREMENTS);
    }
}

#endif // UWBFTR_CCC && !(UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

#if UWBFTR_CSA
void parseCsaRangingNtf(const uint8_t *const p, uint16_t len, phCsaRangingData_t *pCsaRangingData)
{
    uint32_t offset = 0;
    uint8_t iter    = 0;
    if (p == NULL || pCsaRangingData == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return;
    }
    UWB_STREAM_TO_UINT32(pCsaRangingData->sessionHandle, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->rangingStatus, p, offset);
    UWB_STREAM_TO_UINT32(pCsaRangingData->stsIndex, p, offset);
    UWB_STREAM_TO_UINT16(pCsaRangingData->rangingRoundIndex, p, offset);
    UWB_STREAM_TO_UINT16(pCsaRangingData->blockIndex, p, offset);
    UWB_STREAM_TO_UINT16(pCsaRangingData->distance, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->uncertanityAnchorFom, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->uncertanityInitiatorFom, p, offset);
    UWB_STREAM_TO_ARRAY(pCsaRangingData->ccmTag, p, MAX_CCM_TAG_SIZE, offset);
    UWB_STREAM_TO_INT16(pCsaRangingData->aoa_azimuth, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->aoa_azimuth_FOM, p, offset);
    UWB_STREAM_TO_INT16(pCsaRangingData->aoa_elevation, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->aoa_elevation_FOM, p, offset);
    /** Antenna Pair Info*/
    UWB_STREAM_TO_UINT8(pCsaRangingData->antenna_pair_info.configMode, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->antenna_pair_info.antPairId1, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->antenna_pair_info.antPairId2, p, offset);
    UWB_STREAM_TO_UINT8(pCsaRangingData->antenna_pair_info.rfu, p, offset);
    /** PDoA Measurements*/
    UWB_STREAM_TO_UINT8(pCsaRangingData->noOfPdoaMeasures, p, offset);
    for (iter = 0; iter < pCsaRangingData->noOfPdoaMeasures; iter++) {
        UWB_STREAM_TO_INT16(pCsaRangingData->pdoaMeasurements[iter].pdoa, p, offset);
        UWB_STREAM_TO_UINT16(pCsaRangingData->pdoaMeasurements[iter].pdoaIndex, p, offset);
    }
    /** RSSI Measurements */
    UWB_STREAM_TO_UINT8(pCsaRangingData->noOfRssiMeasurements, p, offset);
    if (pCsaRangingData->noOfRssiMeasurements <= MAX_NO_OF_CSA_RSSI_MEASUREMENTS) {
        for (iter = 0; iter < pCsaRangingData->noOfRssiMeasurements; iter++) {
            UWB_STREAM_TO_INT16(pCsaRangingData->rssiMeasurements[iter].rssi_rx1, p, offset);
            UWB_STREAM_TO_INT16(pCsaRangingData->rssiMeasurements[iter].rssi_rx2, p, offset);
#if UWBIOT_UWBD_SR250
            UWB_STREAM_TO_INT16(pCsaRangingData->rssiMeasurements[iter].rssi_rx3, p, offset);
#endif //UWBIOT_UWBD_SR250
        }
    }
    else {
        LOG_WRN("%s: Invalid Range of RSSI Measurements : %d, Expected was %d",
            __FUNCTION__,
            pCsaRangingData->noOfRssiMeasurements,
            MAX_NO_OF_CSA_RSSI_MEASUREMENTS);
    }
    /** SNR Measurements */
    UWB_STREAM_TO_UINT8(pCsaRangingData->noOfSnrMeasurements, p, offset);
    if (pCsaRangingData->noOfSnrMeasurements <= MAX_NO_OF_CSA_SNR_MEASUREMENTS) {
        for (size_t i = 0; i < pCsaRangingData->noOfSnrMeasurements; i++) {
            UWB_STREAM_TO_UINT8(pCsaRangingData->snrMeasurements[i].slotIndexAndAntennaMap, p, offset);
            UWB_STREAM_TO_UINT8(pCsaRangingData->snrMeasurements[i].snrMainPath, p, offset);
            UWB_STREAM_TO_UINT8(pCsaRangingData->snrMeasurements[i].snrFirstPath, p, offset);
            UWB_STREAM_TO_UINT16(pCsaRangingData->snrMeasurements[i].snrTotal, p, offset);
        }
    }
    else {
        LOG_WRN("%s: Invalid Range of SNR Measurements : %d, Expected was %d",
            __FUNCTION__,
            pCsaRangingData->noOfSnrMeasurements,
            MAX_NO_OF_CSA_SNR_MEASUREMENTS);
    }
}

#endif // UWBFTR_CSA

#if UWBFTR_Radar
/**
 *
 * Function:        parseRadarCirNtf
 *
 * Description:     Extracts Radar Params from the given byte array for Radar CIR notification structure
 *
 * Returns:         None
 *
 */
static void parseRadarCirNtf(uint8_t *p, uint16_t len, phUwbRadarNtf_t *pRadarNtf)
{
    uint32_t offset = 0;

    if (len >= RADAR_CIR_NTF_HEADER) {
        pRadarNtf->radar_ntf.radr_cir.cir_len = len - RADAR_CIR_NTF_HEADER;
    }
    else {
        LOG_ERR(
            "%s: Invalid radar CIR notification length %u, expected >= %u", __FUNCTION__, len, RADAR_CIR_NTF_HEADER);
        return;
    }
    UWB_STREAM_TO_UINT16(pRadarNtf->radar_ntf.radr_cir.num_cirs, p, offset);
    UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radr_cir.cir_taps, p, offset);
    UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radr_cir.rfu, p, offset);
    /*Application/Demo needs to allcoate the memory for CIR Data. It will not happen in the API context*/
    pRadarNtf->radar_ntf.radr_cir.cirdata = (uint8_t *)(p + offset);
}

/**
 *
 * Function:        parseRadarTestNtf
 *
 * Description:     Extracts Radar Params from the given byte array for Radar Test Isolation notification structure
 *
 * Returns:         None
 *
 */
static void parseRadarTestNtf(uint8_t *p, uint16_t len, phUwbRadarNtf_t *pRadarNtf)
{
    uint32_t offset = 0;
    UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radar_tst_ntf.antenna_tx, p, offset);
    UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radar_tst_ntf.antenna_rx, p, offset);
    UWB_STREAM_TO_UINT16(pRadarNtf->radar_ntf.radar_tst_ntf.anteena_isolation, p, offset);
}

/**
 *
 * Function:        parseRadarPresence_detection_Ntf
 *
 * Description:     Extracts Radar Params from the given byte array for Radar Presence Detction notification structure
 *
 * Returns:         None
 *
 */
static void parseRadarPresence_detection_Ntf(uint8_t *p, uint16_t len, phUwbRadarNtf_t *pRadarNtf)
{
    if (len < 4) {
        LOG_ERR("%s:insufficient data length TAP[0]%d", __FUNCTION__, len);
    }
    else {
        uint32_t offset = 0;
        // Extract TAP[0] fields
        UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radar_presence_detect_ntf.presence_detected, p, offset);
        UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radar_presence_detect_ntf.presence_detection_mode, p, offset);
        UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radar_presence_detect_ntf.number_of_detections, p, offset);
        // skip the RFU one byte
        offset += 1;
        if (pRadarNtf->radar_ntf.radar_presence_detect_ntf.number_of_detections > MAX_NUMBER_OF_PRESENCE_DETECTIONS) {
            LOG_WRN("%s: Max supported num of Presence detections are 5 Received are %d",
                __FUNCTION__,
                pRadarNtf->radar_ntf.radar_presence_detect_ntf.number_of_detections);
        }
        else {
            // Parse detection blocks (TAP[1] and TAP[2] for each count)
            for (uint8_t i = 0; i < pRadarNtf->radar_ntf.radar_presence_detect_ntf.number_of_detections; i++) {
                /**
                 * @brief
                 * The 8 + i * 8 length check in the code ensures that there is enough data available in the buffer to parse
                 * the repeated TAP blocks (TAP[1] and TAP[2]) for each detection entry.
                 * Example
                 * Case: Count = 2 (2 detection blocks)
                 * Buffer data: TAP[0] + TAP[1] + TAP[2] + TAP[1] + TAP[2]
                 * Total length required: 4 (TAP[0]) + 8 (TAP[1] + TAP[2]) + 8 (TAP[1] + TAP[2]) = 20 bytes
                 */
                if (len < (8 + i * 8)) {
                    LOG_WRN("%s: insufficient data length for detection block %d", __FUNCTION__, i);
                    break;
                }

                // Parse TAP[1]
                UWB_STREAM_TO_UINT16(pRadarNtf->radar_ntf.radar_presence_detect_ntf.detection_distance[i], p, offset);
                // Check if TAP[1] is present (based on Presence Detection Mode)
                // If reporting (Bit 1 of Presence Detection Mode) is enabled, additional AoA fields in the TAP[1] is send
                if (pRadarNtf->radar_ntf.radar_presence_detect_ntf.presence_detection_mode & BIT(1)) {
                    UWB_STREAM_TO_INT8(pRadarNtf->radar_ntf.radar_presence_detect_ntf.detection_aoa[i], p, offset);
                }
                else {
                    LOG_WRN("%s: Bit 1 of Presence Detection Mode is not detected", __FUNCTION__);
                    // Skip AoA field (1 byte) as it's not being reported
                    offset += 1;
                }
                // Parse Track ID (previously RFU)
                UWB_STREAM_TO_UINT8(pRadarNtf->radar_ntf.radar_presence_detect_ntf.detection_track_id[i], p, offset);
                // Check if TAP[2] is present (based on Presence Detection Mode).
                // if Detection trigger value (Bit 4 of Presence Detection Mode) is enabled, additional TAP[2] is send.
                if (pRadarNtf->radar_ntf.radar_presence_detect_ntf.presence_detection_mode & BIT(4)) {
                    /* Increment to TAP[2]*/
                    UWB_STREAM_TO_UINT32(pRadarNtf->radar_ntf.radar_presence_detect_ntf.detection_value[i], p, offset);
                }
                else {
                    LOG_WRN("%s: Bit 4 of Presence Detection Mode is not detected", __FUNCTION__);
                    // skip Detection value fields
                    offset += 4;
                }
            }
        }
    }
}

void parseRadarNtf(uint8_t *p, uint16_t len, phUwbRadarNtf_t *pRadarNtf, uint8_t *pRadarNtfBuff)
{
    if (!((p == NULL) || (pRadarNtf == NULL))) {
        uint32_t offset = 0;
        UWB_STREAM_TO_UINT32(pRadarNtf->sessionHandle, p, offset);
        UWB_STREAM_TO_UINT8(pRadarNtf->radar_status, p, offset);
        UWB_STREAM_TO_UINT8(pRadarNtf->radar_type, p, offset);
        if (pRadarNtf->radar_type == RADAR_MEASUREMENT_TYPE_CIR) {
            parseRadarCirNtf((p + offset), len, pRadarNtf);
        }
        else if (pRadarNtf->radar_type == RADAR_MEASUREMENT_TYPE_TEST_ISOLATION) {
            parseRadarTestNtf((p + offset), len, pRadarNtf);
        }
        else if (pRadarNtf->radar_type == RADAR_MEASUREMENT_TYPE_PRESENCE_DETECTION) {
            parseRadarPresence_detection_Ntf((p + offset), len, pRadarNtf);
        }
        else {
            LOG_ERR("%s: Measurement type not matched", __FUNCTION__);
        }

        if (NULL != pRadarNtfBuff) {
            memcpy(
                pRadarNtfBuff, pRadarNtf->radar_ntf.radr_cir.cirdata, pRadarNtf->radar_ntf.radr_cir.cir_len);
        }
    }
    else {
        LOG_ERR("%s: NULL data received", __FUNCTION__);
    }
}
#endif // UWBFTR_Radar

#if !(UWBIOT_UWBD_SR04X)
void deserializeDataFromRxPerNtf(phTestPer_Rx_Ntf_t *pRfTestRecvData, uint8_t *pRespBuf)
{
    uint32_t offset = 0;
    uint8_t iter    = 0;
    UWB_STREAM_TO_UINT32(pRfTestRecvData->attempts, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->acq_Detect, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->acq_Reject, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->rxfail, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->sync_cir_ready, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->sfd_fail, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->sfd_found, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->phr_dec_error, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->phr_bit_error, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->psdu_dec_error, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->psdu_bit_error, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->sts_found, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->eof, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->vs_data_len, pRespBuf, offset);
    if (pRfTestRecvData->vs_data_len > 0U) {
#if !(UWBIOT_UWBD_SR04X)
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data_type, pRespBuf, offset);
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data.rx_mode, pRespBuf, offset);
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data.no_of_rx_antenna, pRespBuf, offset);
        UWB_STREAM_TO_ARRAY(
            &pRfTestRecvData->vs_data.rx_antenna_id[0], pRespBuf, pRfTestRecvData->vs_data.no_of_rx_antenna, offset);
        for (iter = 0; iter < pRfTestRecvData->vs_data.no_of_rx_antenna; iter++) {
            UWB_STREAM_TO_INT16(pRfTestRecvData->vs_data.rssi_rx[iter], pRespBuf, offset);
        }
        for (iter = 0; iter < pRfTestRecvData->vs_data.no_of_rx_antenna; iter++) {
            UWB_STREAM_TO_INT16(pRfTestRecvData->vs_data.snr_rx[iter], pRespBuf, offset);
        }
        UWB_STREAM_TO_INT16(pRfTestRecvData->rx_cfo_est, pRespBuf, offset);
#endif // !(UWBIOT_UWBD_SR04X)
    }
}

void deserializeRfTestDataNtf(phRfTestData_t *pRfTestData, uint8_t *pRespBuf, uint16_t rspLen)
{
    uint32_t index = 0;
    if (pRfTestData == NULL || pRespBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return;
    }
    UWB_STREAM_TO_UINT8(pRfTestData->status, pRespBuf, index);
    if (rspLen > 0) {
        pRfTestData->dataLength = (uint16_t)rspLen - 1;
    }
    else {
        LOG_ERR("Invalid response length. rspLen=%u", rspLen);
        return;
    }
    pRfTestData->data = &pRespBuf[index];
}

void deserializeDataFromLoopbackNtf(phTest_Loopback_Ntf_t *pRfTestRecvData, uint8_t *pRespBuf, uint8_t *pPsdu)
{
    uint32_t offset = 0;
    uint8_t iter    = 0;
    if (pRfTestRecvData == NULL || pRespBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return;
    }
    UWB_STREAM_TO_UINT32(pRfTestRecvData->tx_ts_int, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->tx_ts_frac, pRespBuf, offset);
    UWB_STREAM_TO_UINT32(pRfTestRecvData->rx_ts_int, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->rx_ts_frac, pRespBuf, offset);
    UWB_STREAM_TO_INT16(pRfTestRecvData->aoa_azimuth, pRespBuf, offset);
    UWB_STREAM_TO_INT16(pRfTestRecvData->aoa_elevation, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->phr, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->psdu_len, pRespBuf, offset);
    pRfTestRecvData->pPsdu = pPsdu;
    UWB_STREAM_TO_ARRAY(&pRfTestRecvData->pPsdu[0], pRespBuf, pRfTestRecvData->psdu_len, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->vs_data_len, pRespBuf, offset);
    if (pRfTestRecvData->vs_data_len > 0U) {
#if !(UWBIOT_UWBD_SR04X)
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data_type, pRespBuf, offset);
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data.rx_mode, pRespBuf, offset);
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data.no_of_rx_antenna, pRespBuf, offset);
        UWB_STREAM_TO_ARRAY(
            &pRfTestRecvData->vs_data.rx_antenna_id[0], pRespBuf, pRfTestRecvData->vs_data.no_of_rx_antenna, offset);
        for (iter = 0; iter < pRfTestRecvData->vs_data.no_of_rx_antenna; iter++) {
            UWB_STREAM_TO_INT16(pRfTestRecvData->vs_data.rssi_rx[iter], pRespBuf, offset);
        }
        for (iter = 0; iter < pRfTestRecvData->vs_data.no_of_rx_antenna; iter++) {
            UWB_STREAM_TO_INT16(pRfTestRecvData->vs_data.snr_rx[iter], pRespBuf, offset);
        }
        UWB_STREAM_TO_INT16(pRfTestRecvData->rx_cfo_est, pRespBuf, offset);
#endif // !(UWBIOT_UWBD_SR04X)
    }
}

void deserializeDataFromRxNtf(phTest_Rx_Ntf_t *pRfTestRecvData, uint8_t *pRespBuf, uint8_t *pPsduBuf)
{
    uint32_t offset = 0;
    uint8_t iter    = 0;
    if (pRfTestRecvData == NULL || pRespBuf == NULL || pPsduBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return;
    }
    UWB_STREAM_TO_UINT32(pRfTestRecvData->rx_done_ts_int, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->rx_done_ts_frac, pRespBuf, offset);
    UWB_STREAM_TO_INT16(pRfTestRecvData->aoa_azimuth, pRespBuf, offset);
    UWB_STREAM_TO_INT16(pRfTestRecvData->aoa_elevation, pRespBuf, offset);
    UWB_STREAM_TO_UINT8(pRfTestRecvData->toa_gap, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->phr, pRespBuf, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->psdu_len, pRespBuf, offset);
    pRfTestRecvData->pPsdu = pPsduBuf;
    UWB_STREAM_TO_ARRAY(&pRfTestRecvData->pPsdu[0], pRespBuf, pRfTestRecvData->psdu_len, offset);
    UWB_STREAM_TO_UINT16(pRfTestRecvData->vs_data_len, pRespBuf, offset);
    if (pRfTestRecvData->vs_data_len > 0U) {
#if !(UWBIOT_UWBD_SR04X)
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data_type, pRespBuf, offset);
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data.rx_mode, pRespBuf, offset);
        UWB_STREAM_TO_UINT8(pRfTestRecvData->vs_data.no_of_rx_antenna, pRespBuf, offset);
        UWB_STREAM_TO_ARRAY(
            &pRfTestRecvData->vs_data.rx_antenna_id[0], pRespBuf, pRfTestRecvData->vs_data.no_of_rx_antenna, offset);
        for (iter = 0; iter < pRfTestRecvData->vs_data.no_of_rx_antenna; iter++) {
            UWB_STREAM_TO_INT16(pRfTestRecvData->vs_data.rssi_rx[iter], pRespBuf, offset);
        }
        for (iter = 0; iter < pRfTestRecvData->vs_data.no_of_rx_antenna; iter++) {
            UWB_STREAM_TO_INT16(pRfTestRecvData->vs_data.snr_rx[iter], pRespBuf, offset);
        }
#endif // !(UWBIOT_UWBD_SR04X)
    }
}

void deserializeDataFromSrRxNtf(
    phTest_Test_Sr_Ntf_t *pRfTestSrRxData, uint8_t *pRespBuf, uint8_t *pPsdu, uint16_t data_len)
{
    if (pRfTestSrRxData == NULL || pRespBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return;
    }
    uint32_t offset = 0;
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_attempts, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_acq_Detect, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_acq_Reject, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_rxfail, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_sync_cir_ready, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_sfd_fail, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_sfd_found, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_sts_found, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    UWB_STREAM_TO_UINT32(pRfTestSrRxData->Test_Sr_Ntf_eof, pRespBuf, offset);
    data_len = (uint16_t)(data_len - sizeof(uint32_t));
    /**
     * Work around added for the Length.
     * Once Spec Updates , will remove the length handling.
     */
    pRfTestSrRxData->Test_Sr_Ntf_bitmap_len = data_len;
    if (pPsdu != NULL) {
        pRfTestSrRxData->Test_Sr_Ntf_bitmap = pPsdu;
        if (pRfTestSrRxData->Test_Sr_Ntf_bitmap_len != 0) {
            UWB_STREAM_TO_ARRAY(
                &pRfTestSrRxData->Test_Sr_Ntf_bitmap[0], pRespBuf, pRfTestSrRxData->Test_Sr_Ntf_bitmap_len, offset);
        }
        else {
            LOG_WRN("Test_Sr_Ntf_bitmap length is Zero, Hence No Bit Map data will be available");
        }
    }
    else {
        LOG_ERR("%s: PSDU Lenth is NULL", __FUNCTION__);
    }
}

#endif // !(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR04X)
void parseMsgLogNtf(uint8_t *p, uint16_t len, phPhyLogNtfnData_t *pTestPhyLogNtfnData)
{
    if (len != 0) {
        pTestPhyLogNtfnData->size = len;
        memcpy(&pTestPhyLogNtfnData->data[0], p, len);
    }
}

void parseExtPsduLogNtf(uint8_t *p, uint16_t len, phPhyLogNtfnData_t *pTestPhyLogNtfnData)
{
    uint16_t psduDataLen = (p[EXT_PSDU_LEN_OFFSET] | (p[EXT_PSDU_LEN_OFFSET + 1] << 8));
    if (len != 0) {
        if (psduDataLen > MAX_HPRF_PSDU_DATA_PACKET_SIZE) {
            LOG_WRN("Incomplete chained packet or wrong data received: psduData Length %ld", psduDataLen);
        }
        else {
            LOG_INF("PSDU Data Length: %ld", psduDataLen);
            pTestPhyLogNtfnData->size = psduDataLen;
            /** Recevied data = Session ID(4byes) + psdu Length (2bytes) + psdu data (1024 bytes)*/
            memcpy(&pTestPhyLogNtfnData->data[0], &p[EXT_PSDU_LEN_OFFSET + 2], psduDataLen);
        }
    }
    else {
        LOG_ERR("%s: PSDU Lenth is NULL", __FUNCTION__);
    }
}

void parseTestLoopbackData(uint8_t *p, uint16_t len, phTestLoopbackData_t *pTestLoopbackStatus)
{
    uint32_t offset             = 0;
    pTestLoopbackStatus->status = FAILURE;
    if (len != 0) {
        UWB_STREAM_TO_UINT8(pTestLoopbackStatus->status, p, offset);
        UWB_STREAM_TO_UINT32(pTestLoopbackStatus->groupDelay, p, offset);
    }
}

#endif /* (UWBIOT_UWBD_SR04X) */

#if UWBFTR_DataTransfer


uint16_t serializeLogicalSendDataPayload(uwb_ll_data_receive_notification_t *pSendData, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;

    if (pSendData == NULL || pCmdBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }

    UWB_UINT32_TO_STREAM(pCmdBuf, pSendData->llConnectId, offset);

    UWB_UINT16_TO_STREAM(pCmdBuf, pSendData->sequence_number, offset);

    UWB_UINT16_TO_STREAM(pCmdBuf, pSendData->data_size, offset);

    if (pSendData->data_size <= (MAX_UCI_HEADER_SIZE + MAX_CMD_BUFFER_DATA_TRANSFER)) {
        UWB_ARRAY_TO_STREAM(pCmdBuf, pSendData->data, pSendData->data_size, offset);
    }
    return offset;
}

#endif // UWBFTR_DataTransfer
#if !(UWBIOT_UWBD_SR04X)
void parseNewRoleChangeRcvNtf(uint8_t *p, uint16_t len, uwb_session_role_change_ntf_t *pNewRole)
{
    uint16_t offset = 0;
    if (len != 0) {
        UWB_STREAM_TO_UINT32(pNewRole->sessionHandle, p, offset);
        UWB_STREAM_TO_UINT8(pNewRole->new_role, p, offset);
    }
    else {
        LOG_ERR("%s: length for uwb_session_role_change_ntf_t is Zero", __FUNCTION__);
    }
}
void deserializeGetCalibResp(phCalibRespStatus_t *pCalibResp, uint8_t *respBuf)
{
    uint16_t offset = 0;

    UWB_STREAM_TO_UINT8(pCalibResp->status, respBuf, offset);
    UWB_STREAM_TO_UINT8(pCalibResp->calibState, respBuf, offset);

    /** In case of AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT, ParamId is of 2 octets and
     * the Length of the Calib data is of 2 octets. */
    if (*respBuf == EXTENTED_CALIB_PARAM_ID) {
        UWB_STREAM_TO_UINT16(pCalibResp->paramId, respBuf, offset);
        UWB_STREAM_TO_UINT16(pCalibResp->calibrationValuelength, respBuf, offset);
    }
    else {
        UWB_STREAM_TO_UINT8(pCalibResp->paramId, respBuf, offset);
        UWB_STREAM_TO_UINT8(pCalibResp->calibrationValuelength, respBuf, offset);
    }

    if (0U != pCalibResp->calibrationValuelength) {
        UWB_STREAM_TO_ARRAY(pCalibResp->pCalibrationValue, respBuf, pCalibResp->calibrationValuelength, offset);
    }
}
#endif // !(UWBIOT_UWBD_SR04X)

#if UWBIOT_UWBD_SR2XXT

uint16_t serializeSetSecureCalibPayload(phSecureCalibParams_t *SecureCalibParams, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL || SecureCalibParams == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
    UWB_UINT8_TO_STREAM(pCmdBuf, SecureCalibParams->channelId, offset);

    UWB_UINT8_TO_STREAM(pCmdBuf, SecureCalibParams->calibParamId, offset);

    UWB_ARRAY_TO_STREAM(pCmdBuf, SecureCalibParams->calibrationValue, SecureCalibParams->length, offset);

    UWB_UINT32_TO_STREAM(pCmdBuf, SecureCalibParams->configVersion, offset);

    UWB_ARRAY_TO_STREAM(pCmdBuf, SecureCalibParams->cryptoTag, CRYPTO_TAG_LEN, offset);
    return offset;
}

BOOLEAN validateSecureCalibParamId(uint8_t calibParamId)
{
    eCalibParamSecure eCalibParamId = (eCalibParamSecure)calibParamId;
    BOOLEAN bRetCode                = FALSE;

    switch (eCalibParamId) {
    case RF_CLK_ACCURACY_CALIB_SECURE:
    case TX_ANT_DELAY_CALIB_SECURE:
    case RX_ANT_DELAY_CALIB_SECURE:
    case PLATFORM_ID_SECURE:
    case CONFIG_VERSION_SECURE:
    case DBG_SE_DUMP_SECURE: {
        bRetCode = TRUE;
    } break;
    default: {
        LOG_ERR("%s: Invalid caliberation paramter ID", __FUNCTION__);
        bRetCode = FALSE;
    } break;
    }
    return bRetCode;
}

#endif // UWBIOT_UWBD_SR2XXT

#if UWBFTR_CSA
uint16_t serializeSessionSetLocZoneCmd(phSessionSetLocZone_t *pSetLocZone, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;

    if (pSetLocZone == NULL || pCmdBuf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }

    UWB_UINT32_TO_STREAM(pCmdBuf, pSetLocZone->setLocZone_SessionHandle, offset);
    UWB_UINT16_TO_STREAM(pCmdBuf, pSetLocZone->setLocZone_RangingBlockIndex, offset);
    UWB_UINT8_TO_STREAM(pCmdBuf, pSetLocZone->setLocZone_LocZone, offset);

    return offset;
}
#endif // UWBFTR_CSA

#if !(UWBIOT_UWBD_SR04X)
/*******************************************************************************
**
** Function         serializeSessionEnableSessionSchedulingInfoNtf
**
** Description      Serialize ENABLE_SESSION_SCHEDULING_INFO_NTF_REQ payload.
**                  Encodes the enable/disable byte as 1 octet per spec.
**
** Returns          Length of serialized payload in bytes
**
*******************************************************************************/
uint16_t serializeSessionEnableSessionSchedulingInfoNtf(
    uwb_session_scheduling_info_ntf_t *pSessionSchedulingInfoNtf, uint8_t *pCmdBuf)
{
    uint16_t offset = 0;
    if (pCmdBuf == NULL || pSessionSchedulingInfoNtf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return 0;
    }
    UWB_UINT8_TO_STREAM(pCmdBuf, pSessionSchedulingInfoNtf->uwb_enable_session_scheduling_info_ntf, offset);
    return offset;
}

void parseScheduleNtf(uint8_t *p, uint16_t len, uwb_session_scheduling_info_ntf_data_t *pNtf)
{
    uint32_t index = 0;
    if (p == NULL || pNtf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
        return;
    }
    if (len == 0 || len > MAX_UCI_PACKET_SIZE) {
        LOG_ERR("%s Invalid length %d", __FUNCTION__, len);
        return;
    }
    UWB_STREAM_TO_UINT8(pNtf->uwb_number_of_reports,     p, index);
    for (uint8_t i = 0; i < pNtf->uwb_number_of_reports && i < MAX_SCHED_NTF_REPORTS; i++) {
        UWB_STREAM_TO_UINT32(pNtf->reports[i].uwb_session_handle,     p, index);
        UWB_STREAM_TO_UINT32(pNtf->reports[i].uwb_sequence_number,    p, index);
        UWB_STREAM_TO_ARRAY(pNtf->reports[i].uwb_first_slot_start_time, p, 8, index);
        UWB_STREAM_TO_ARRAY(pNtf->reports[i].uwb_last_slot_end_time,    p, 8, index);
        UWB_STREAM_TO_UINT8(pNtf->reports[i].uwb_occupancy_status,     p, index);
    }
}
#endif

uint16_t uwb_serialize_app_config_payload(uint32_t session_handle, uint8_t no_of_params,
					  uint16_t param_len, uint8_t *p_cmd_buf)
{
	uint16_t offset = 0;
    if (p_cmd_buf == NULL) {
        LOG_ERR("%s: NULL pointer parameter", __FUNCTION__);
		return 0;
	}
	if (param_len < (UINT16_MAX - offset)) {
		UWB_UINT32_TO_STREAM(p_cmd_buf, session_handle, offset);
		UWB_UINT8_TO_STREAM(p_cmd_buf, no_of_params, offset);
		offset = (offset + param_len);
	}
	return offset;
}
