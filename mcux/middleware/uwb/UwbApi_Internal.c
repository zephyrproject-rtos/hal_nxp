/*
 * Copyright 2018-2020,2022-2026 NXP.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "UwbApi_Internal.h"
#include "UwbApi.h"
#include "PrintUtility.h"
#include "zephyr/kernel.h"
#include "phNxpUciHal.h"
#include "zephyr/uwb/uci.h"
#include "uci_ext_defs.h"
#include "uci_test_defs.h"
#include "zephyr/uwb/uwb_types.h"
#include "UwbApi_Proprietary_Internal.h"
#include "AppConfigParams.h"
#include <UwbApi_Types.h>
#include "zephyr/uwb/tml.h"
#include "zephyr/uwb/uwb_core.h"
#include "uwbiot_ver.h"
#include "uwb_uwbs_common_config.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_uwb_api_internal, LOG_LEVEL_INF);

#if UWBIOT_UWBD_SR1XXT
#include "UwbApi_RfTest.h"
#endif
#include "UwbApi_Utility.h"
/* Context variable */
#include "zephyr/uwb/uci.h"
phUwbApiContext_t uwbContext;

/** Local functions prototypes */
static BOOLEAN parseExtraCapabilityInfo(phUwbCapInfo_t *pDevCap, uint8_t *capsInfoData, uint16_t capsInfoLen);
#if !(UWBIOT_UWBD_SR04X)
tUWBAPI_STATUS recoverUWBS(void)
{
    LOG_DBG("%s: Enter", __FUNCTION__);
    uwb_uci_callback_t *p_cb = NULL;
    if (0 != uwb_uci_get_registered_callback(&p_cb)) {
        LOG_ERR("Could not fetch registered callback");
    }
    uwb_api_deinitialize();
    uwb_status_code_t status = uwb_api_initialize(p_cb);
    return status;
}
#endif // !(UWBIOT_UWBD_SR04X)

void cleanUp()
{
    memset(&uwbContext, 0x00, sizeof(phUwbApiContext_t));
}

int uwbInit()
{
    int status                = UWBAPI_STATUS_FAILED;
    // const tHAL_UWB_ENTRY *halFuncEntries = NULL;
    LOG_DBG("%s: enter", __FUNCTION__);
    if (uwbContext.isUfaEnabled) {
        return 0;
    }
    uwbContext.sessionInfo.state = UWBAPI_SESSION_ERROR;
    uwbContext.receivedEventId   = DEFAULT_EVENT_TYPE;

#if UWBIOT_SESN_SNXXX
    if (k_sem_init(&uwbContext.uwb_binding_status_ntf_wait, 0, 1) != UWB_STATUS_CODE_SUCCESS) {
        LOG_ERR("%s : CreateSemaphore Failed for binding_status_ntf ", __FUNCTION__);
        return status;
    }
#endif // UWBIOT_SESN_SNXXX

    LOG_DBG("UfaEnable");

    status = (uint8_t)UwbDeviceInit(FALSE);
    LOG_DBG("%s: DownloadFirmware status: %d", __FUNCTION__, status);
    /* Set operating mode */
    if (status == UWBAPI_STATUS_OK) {
        status = setDefaultCoreConfigs();
        if (status != UWBAPI_STATUS_OK) {
            goto Error;
        }

#if !(UWBIOT_UWBD_SR04X)
        if (setVendorConfigs() != UWBAPI_STATUS_OK) {
            LOG_ERR("%s : setVendorConfigs Failed", __FUNCTION__);
            goto Error;
        }
#endif // !(UWBIOT_UWBD_SR04X)

#if UWBFTR_DataTransfer
        // Update UWBS capability info
        phUwbCapInfo_t dev_capabilities = {0};
        status = getCapsInfo(&dev_capabilities);
        if (status == UWBAPI_STATUS_OK) {
            uwb_uci_configure_max_data_payload(dev_capabilities.maxDataPacketPayloadSize);
        }
        else {
            goto Error;
        }
#endif // UWBFTR_DataTransfer
    }
    else {
        goto Error;
    }
#if UWBIOT_SESN_SNXXX
    if (uwbContext.fwMode == MAINLINE_FW) {
        /** Wait for the BINDING_STATUS_NTF */
        if (k_sem_take(&
                uwbContext.uwb_binding_status_ntf_wait, Z_TIMEOUT_MS(UWBD_BINDING_STATUS_NTF_TIMEOUT)) == UWB_STATUS_CODE_SUCCESS) {
            LOG_INF("BINDING_STATUS_NTF received");
            // Delete the Semaphore on it's completion.
            k_sem_reset(&uwbContext.uwb_binding_status_ntf_wait);
        }
        else {
            LOG_WRN("%s:BINDING_STATUS_NTF timed out", __FUNCTION__);
            status = UWBAPI_STATUS_TIMEOUT;
            goto Error;
        }
    }
#endif // UWBIOT_SESN_SNXXX

#if UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S
    status = demo_configure_otp_calibration(CHANNEL_5);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("demo_configure_otp_calibration(CHANNEL_5) Failed");
        goto Error;
    }

    status = demo_configure_otp_calibration(CHANNEL_9);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("demo_configure_otp_calibration(CHANNEL_9) Failed");
        goto Error;
    }
#endif // UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S

    uwbContext.isUfaEnabled = true;
    return status;
Error:
#if UWBIOT_SESN_SNXXX
    // Delete the Semaphore on it's completion.
    k_sem_reset(&uwbContext.uwb_binding_status_ntf_wait);
#endif // UWBIOT_SESN_SNXXX
    // cleanUp();
    LOG_DBG("%s: exit with status %d", __FUNCTION__, status);
    return status;
}

void parseRangingParams(uint8_t *rspPtr, uint8_t noOfParams, phRangingParams_t *pRangingParams)
{
    uint8_t paramId;
    uint8_t length;
    uint32_t index = 0;

    for (int i = 0; i < noOfParams; i++) {
        UWB_STREAM_TO_UINT8(paramId, rspPtr, index);
        UWB_STREAM_TO_UINT8(length, rspPtr, index);
        switch (paramId) {
        case UCI_PARAM_ID_DEVICE_ROLE:
            /*  Device Role */
            UWB_STREAM_TO_UINT8(pRangingParams->deviceRole, rspPtr, index);
            break;
        case UCI_PARAM_ID_MULTI_NODE_MODE:
            /*  Multi Node Mode */
            UWB_STREAM_TO_UINT8(pRangingParams->multiNodeMode, rspPtr, index);
            break;
        case UCI_PARAM_ID_MAC_ADDRESS_MODE:
            /*  Mac addr mode */
            UWB_STREAM_TO_UINT8(pRangingParams->macAddrMode, rspPtr, index);
            break;
#if !(UWBIOT_UWBD_SR040)
        case UCI_PARAM_ID_SCHEDULED_MODE:
            /*  Scheduled Mode */
            UWB_STREAM_TO_UINT8(pRangingParams->scheduledMode, rspPtr, index);
            break;
#endif // !(UWBIOT_UWBD_SR040)
        case UCI_PARAM_ID_RANGING_ROUND_USAGE:
            /* Ranging Round Usage */
            UWB_STREAM_TO_UINT8(pRangingParams->rangingRoundUsage, rspPtr, index);
            break;
        case UCI_PARAM_ID_DEVICE_MAC_ADDRESS:
            /*  Device Mac Address */
            UWB_STREAM_TO_ARRAY(&pRangingParams->deviceMacAddr[0], rspPtr, length, index);
            break;
        case UCI_PARAM_ID_DEVICE_TYPE:
            /*  Device Type */
            UWB_STREAM_TO_UINT8(pRangingParams->deviceType, rspPtr, index);
            break;
        default:
            break;
        }
    }
}

tUWBAPI_STATUS sendRawUci2(uint8_t *p_cmd_params, uint16_t cmd_params_len, uint8_t *response, uint32_t *response_len)
{
    if (p_cmd_params == NULL || cmd_params_len < UCI_HEADER_SIZE || response == NULL ||
        response_len == NULL) {
        LOG_ERR("%s: invalid params", __FUNCTION__);
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    uci_control_packet_header_t *header = (uci_control_packet_header_t *)p_cmd_params;
    int ret;

    if (header->mt == UCI_MT_DATA) {
        /* Data packet: route through data transceive path which preserves MT=0x00 and
         * uses the DPF field (stored in header->gid for data packets).
         * No synchronous response is expected for data transfer commands. */
        LOG_WRN("%s: For data transfer command no need to wait for response", __FUNCTION__);
        ret = uwb_uci_transceive_data_packet(header->gid, p_cmd_params + UCI_HEADER_SIZE,
                             cmd_params_len - UCI_HEADER_SIZE, response,
                             response_len);
    } else {
        /* Control packet: route through control transceive path */
        ret = uwb_uci_transceive_control_packet(
            header->gid, header->oid, p_cmd_params + UCI_HEADER_SIZE,
            cmd_params_len - UCI_HEADER_SIZE, response, response_len);
    }

    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    return UWBAPI_STATUS_OK;
}

uint8_t getAppConfigTLVBuffer(uint8_t paramId, uint8_t paramLen, void *paramValue, uint8_t *tlvBuffer)
{
    uint8_t length = 0;

    tlvBuffer[length++] = paramId;

     if (paramLen > (MAX_UCI_PACKET_SIZE - 2 /* 1 byte of paramId + 1 byte of param_len */)) {
        LOG_ERR("%s, app config value len is greater than max uci payload size", __FUNCTION__);
        length = 0;
        return length;
    }

    switch (paramId) {
        /* Length 1 Byte */
    case UCI_PARAM_ID_DEVICE_ROLE:
    case UCI_PARAM_ID_RANGING_ROUND_USAGE:
    case UCI_PARAM_ID_STS_CONFIG:
    case UCI_PARAM_ID_MULTI_NODE_MODE:
    case UCI_PARAM_ID_CHANNEL_NUMBER:
    case UCI_PARAM_ID_NO_OF_CONTROLEES:
    case UCI_PARAM_ID_SESSION_INFO_NTF:
    case UCI_PARAM_ID_DEVICE_TYPE:
    case UCI_PARAM_ID_MAC_FCS_TYPE:
    case UCI_PARAM_ID_RANGING_ROUND_CONTROL:
    case UCI_PARAM_ID_AOA_RESULT_REQ:
    case UCI_PARAM_ID_RFRAME_CONFIG:
    case UCI_PARAM_ID_RSSI_REPORTING:
    case UCI_PARAM_ID_PREAMBLE_CODE_INDEX:
    case UCI_PARAM_ID_SFD_ID:
    case UCI_PARAM_ID_PSDU_DATA_RATE:
    case UCI_PARAM_ID_PREAMBLE_DURATION:
    case UCI_PARAM_ID_RANGING_TIME_STRUCT:
    case UCI_PARAM_ID_SLOTS_PER_RR:
#if (UWBIOT_UWBD_SR04X)
    case UCI_PARAM_ID_TX_ADAPTIVE_PAYLOAD_POWER:
#endif /* (UWBIOT_UWBD_SR04X) */
    case UCI_PARAM_ID_PRF_MODE:
    case UCI_PARAM_ID_SCHEDULED_MODE:
    case UCI_PARAM_ID_KEY_ROTATION:
    case UCI_PARAM_ID_KEY_ROTATION_RATE:
    case UCI_PARAM_ID_SESSION_PRIORITY:
    case UCI_PARAM_ID_MAC_ADDRESS_MODE:
    case UCI_PARAM_ID_NUMBER_OF_STS_SEGMENTS:
    case UCI_PARAM_ID_HOPPING_MODE:
    case UCI_PARAM_ID_IN_BAND_TERMINATION_ATTEMPT_COUNT:
    case UCI_PARAM_ID_RESULT_REPORT_CONFIG:
    case UCI_PARAM_ID_STS_LENGTH:
    case UCI_PARAM_ID_UL_TDOA_TX_TIMESTAMP:
    case UCI_PARAM_ID_BPRF_PHR_DATA_RATE:
    case UCI_PARAM_ID_BLOCK_STRIDING:
    case UCI_PARAM_ID_DLTDOA_RANGING_METHOD:
    case UCI_PARAM_ID_DLTDOA_TX_TIMESTAMP_CONF:
    case UCI_PARAM_ID_DLTDOA_INTER_CLUSTER_SYNC_PERIOD:
    case UCI_PARAM_ID_DLTDOA_ANCHOR_CFO:
    case UCI_PARAM_ID_DLTDOA_TX_ACTIVE_RANGING_ROUNDS:
    case UCI_PARAM_ID_DL_TDOA_BLOCK_SKIPPING:
    case UCI_PARAM_ID_DL_TDOA_SUPERCLUSTER_ID:
#if UWBFTR_CCC
    case UCI_PARAM_ID_PULSESHAPE_COMBO:
    case UCI_PARAM_ID_RESPONDER_LISTEN_ONLY:
    case UCI_PARAM_ID_RESPONDER_SLOT_INDEX:
#endif // UWBFTR_CCC
#if UWBFTR_CSA
    case UCI_PARAM_ID_ALIRO_MAC_MODE:
#endif // UWBFTR_CSA
    case UCI_PARAM_ID_SUSPEND_RANGING_ROUNDS:
    case UCI_PARAM_ID_DLTDOA_TIME_REF_ANCHOR:
    case UCI_PARAM_ID_APPLICATION_DATA_ENDPOINT:
    case UCI_PARAM_ID_DLTDOA_MEASUREMENT_NTF_V2:
    case UCI_PARAM_ID_DL_TDOA_RESPONDER_TOF:
    case UCI_PARAM_ID_DATA_TRANSFER_STATUS_NTF_CONFIG:
    case UCI_PARAM_ID_SECURE_RANGING_NEFA_LEVEL:
    case UCI_PARAM_ID_SECURE_RANGING_CSW_LENGTH:
#if UWBFTR_DataTransfer
    case UCI_PARAM_ID_LINK_LAYER_MODE:
    case UCI_PARAM_ID_DATA_REPETITION_COUNT:
#endif // UWBFTR_DataTransfer
    case UCI_PARAM_ID_MIN_FRAMES_PER_RR:
    case UCI_PARAM_ID_INTER_FRAME_INTERVAL: {
        tlvBuffer[length++] = 1; // Param len
        uint8_t value       = *((uint8_t *)paramValue);
        tlvBuffer[length++] = value;
    } break;

    /* Length 2 Bytes */
    case UCI_PARAM_ID_CAP_SIZE_RANGE: // Contention based ranging.
    case UCI_PARAM_ID_NEAR_PROXIMITY_CONFIG:
    case UCI_PARAM_ID_FAR_PROXIMITY_CONFIG:
    case UCI_PARAM_ID_SLOT_DURATION:
    case UCI_PARAM_ID_MAX_RR_RETRY:
    case UCI_PARAM_ID_VENDOR_ID:
#if UWBFTR_CCC
    case UCI_PARAM_ID_RANGING_PROTOCOL_VER:
    case UCI_PARAM_ID_UWB_CONFIG_ID:
    case UCI_PARAM_ID_URSK_TTL:
#endif // UWBFTR_CCC
    case UCI_PARAM_ID_MAX_NUMBER_OF_MEASUREMENTS:
    case UCI_PARAM_ID_MTU_SIZE: {
        tlvBuffer[length++] = 2; // Param len
        uint16_t value      = *((uint16_t *)paramValue);
        tlvBuffer[length++] = (uint8_t)(value);
        tlvBuffer[length++] = (uint8_t)(value >> 8);
    } break;

    /* Length 4 Byte */
    case UCI_PARAM_ID_UL_TDOA_TX_INTERVAL:
    case UCI_PARAM_ID_UL_TDOA_RANDOM_WINDOW:
    case UCI_PARAM_ID_STS_INDEX:
#if UWBFTR_CCC
    case UCI_PARAM_ID_LAST_STS_INDEX_USED:
    case UCI_PARAM_ID_HOP_MODE_KEY:
#endif // UWBFTR_CCC
    case UCI_PARAM_ID_SUB_SESSION_ID:
    case UCI_PARAM_ID_RANGING_DURATION: {
        tlvBuffer[length++] = 4; // Param len
        uint32_t value      = *((uint32_t *)paramValue);
        tlvBuffer[length++] = (uint8_t)(value);
        tlvBuffer[length++] = (uint8_t)(value >> 8);
        tlvBuffer[length++] = (uint8_t)(value >> 16);
        tlvBuffer[length++] = (uint8_t)(value >> 24);
    } break;

    /* Length Array of 1 Bytes */
#if !(UWBIOT_UWBD_SR04X)
    case UCI_PARAM_ID_SESSION_TIME_BASE:
#endif
    case UCI_PARAM_ID_UL_TDOA_NTF_REPORT_CONFIG:
    case UCI_PARAM_ID_UL_TDOA_DEVICE_ID:
    case UCI_PARAM_ID_STATIC_STS_IV:
    case UCI_PARAM_ID_DEVICE_MAC_ADDRESS:
    case UCI_PARAM_ID_DST_MAC_ADDRESS:
    case UCI_PARAM_ID_UWB_INITIATION_TIME:
    case UCI_PARAM_ID_DLTDOA_ANCHOR_LOCATION:
    case UCI_PARAM_ID_DLTDOA_ANCHOR_LOCATION_V2:
    case UCI_PARAM_ID_SESSION_KEY:
    case UCI_PARAM_ID_SUB_SESSION_KEY:
    case UCI_PARAM_ID_AOA_BOUND_CONFIG: {
        uint8_t *value      = (uint8_t *)paramValue;
        tlvBuffer[length++] = paramLen; // Param len
        for (uint8_t i = 0; i < (paramLen / sizeof(uint8_t)); i++) {
            tlvBuffer[length++] = value[i];
        }
    } break;
    default:
        LOG_ERR("%s: Unknown param ID 0x%02X\n", __FUNCTION__, paramId);
        length = 0;
        break;
    }

    return length;
}

#if !(UWBIOT_UWBD_SR04X)

uint8_t getTestConfigTLVBuffer(uint8_t paramId, uint8_t paramLen, void *paramValue, uint8_t *tlvBuffer)
{
    uint8_t length = 0;

    tlvBuffer[length++] = paramId;

    switch (paramId) {
    /* Length 1 Byte */
    case UCI_TEST_PARAM_ID_RANDOMIZE_PSDU:
    case UCI_TEST_PARAM_ID_STS_INDEX_AUTO_INCR:
    case UCI_TEST_PARAM_ID_PHR_RANGING_BIT:
    case UCI_TEST_PARAM_ID_STS_DETECT_BITMAP_EN: {
        tlvBuffer[length++] = 1; // Param len
        uint8_t value       = *((uint8_t *)paramValue);
        tlvBuffer[length++] = value;
    } break;

    /* Length 4 Byte */
    case UCI_TEST_PARAM_ID_NUM_PACKETS:
    case UCI_TEST_PARAM_ID_T_GAP:
    case UCI_TEST_PARAM_ID_T_START:
    case UCI_TEST_PARAM_ID_T_WIN:
    case UCI_TEST_PARAM_ID_RMARKER_TX_START:
    case UCI_TEST_PARAM_ID_RMARKER_RX_START: {
        tlvBuffer[length++] = 4; // Param len
        uint32_t value      = *((uint32_t *)paramValue);
        tlvBuffer[length++] = (uint8_t)(value);
        tlvBuffer[length++] = (uint8_t)(value >> 8);
        tlvBuffer[length++] = (uint8_t)(value >> 16);
        tlvBuffer[length++] = (uint8_t)(value >> 24);
    } break;
    default:
        LOG_WRN("%s : unhandled parameter: 0x%02X", __FUNCTION__, paramId);
        length = 0;
        break;
    }
    return length;
}
#endif // !(UWBIOT_UWBD_SR04X)

uint8_t getCoreDeviceConfigTLVBuffer(uint8_t paramId, uint8_t paramLen, void *paramValue, uint8_t *tlvBuffer)
{
    uint8_t length = 0;
    if (paramValue == NULL || tlvBuffer == 0) {
        LOG_ERR("%s: Buffer is NULL", __FUNCTION__);
        return 0;
    }
    tlvBuffer[length++] = paramId;

    switch (paramId) {
    case UCI_PARAM_ID_DEVICE_STATE:
    case UCI_PARAM_ID_LOW_POWER_MODE:
#if (UWBIOT_UWBD_SR04X)
    case UCI_EXT_PARAM_ID_MHR_IN_CCM:
    case UCI_EXT_PARAM_ID_DDFS_TONE_CONFIG_ENABLE:
#endif
    {
        tlvBuffer[length++] = 1; // Param len
        uint8_t value       = *((uint8_t *)paramValue);
        if (value != ENABLED && value != DISABLED) {
            return 0;
        }
        tlvBuffer[length++] = value;
    } break;
#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    case UCI_PARAM_ID_UCI_WIFI_COEX_FEATURE: {
        UWB_WiFiCoEx_Ftr_t *wifiCoExFtr = (UWB_WiFiCoEx_Ftr_t *)paramValue;
        tlvBuffer[length++] = paramLen; // Param len
        tlvBuffer[length++] = wifiCoExFtr->UWB_WiFiCoEx_Enable;
		tlvBuffer[length++] = wifiCoExFtr->UWB_WiFiCoEx_noOfChannels;

        for (uint8_t i = 0; i < wifiCoExFtr->UWB_WiFiCoEx_noOfChannels; i++) {
            tlvBuffer[length++] = wifiCoExFtr->wifiCoexFtrList[i].UWB_WiFiCoEx_channel_Id;
            tlvBuffer[length++] = wifiCoExFtr->wifiCoexFtrList[i].UWB_WiFiCoEx_MinGuardDuration;
            tlvBuffer[length++] = wifiCoExFtr->wifiCoexFtrList[i].UWB_WiFiCoEx_MaxGrantDuration;
            tlvBuffer[length++] = wifiCoExFtr->wifiCoexFtrList[i].UWB_WiFiCoEx_AdvacnedGrantDuration;
        }
    } break;
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    default:
        LOG_WRN("%s : unhandled parameter: 0x%02X", __FUNCTION__, paramId);
        length = 0;
        break;
    }
    return length;
}

void parseCoreGetDeviceConfigResponse(uint8_t *tlvBuffer, phDeviceConfigData_t *devConfig)
{
    uint16_t paramId;
    uint32_t index = 0;
    UWB_STREAM_TO_UINT8(paramId, tlvBuffer, index);
    index++; // skipping the length
    switch (paramId) {
    /* 1 byte len */
    case UCI_PARAM_ID_LOW_POWER_MODE: {
        UWB_STREAM_TO_UINT8(devConfig->lowPowerMode, tlvBuffer, index);
    } break;
#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    case UCI_PARAM_ID_UCI_WIFI_COEX_FEATURE: {
        UWB_STREAM_TO_UINT8(devConfig->wifiCoExFtr.UWB_WiFiCoEx_Enable, tlvBuffer, index);
        UWB_STREAM_TO_UINT8(devConfig->wifiCoExFtr.UWB_WiFiCoEx_noOfChannels, tlvBuffer, index);

        for (uint8_t i = 0; i < devConfig->wifiCoExFtr.UWB_WiFiCoEx_noOfChannels; i++) {
            UWB_STREAM_TO_UINT8(devConfig->wifiCoExFtr.wifiCoexFtrList[i].UWB_WiFiCoEx_channel_Id, tlvBuffer, index);
            UWB_STREAM_TO_UINT8(
                devConfig->wifiCoExFtr.wifiCoexFtrList[i].UWB_WiFiCoEx_MinGuardDuration, tlvBuffer, index);
            UWB_STREAM_TO_UINT8(
                devConfig->wifiCoExFtr.wifiCoexFtrList[i].UWB_WiFiCoEx_MaxGrantDuration, tlvBuffer, index);
            UWB_STREAM_TO_UINT8(
                devConfig->wifiCoExFtr.wifiCoexFtrList[i].UWB_WiFiCoEx_AdvacnedGrantDuration, tlvBuffer, index);
        }
    } break;
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    default :
        LOG_ERR("%s ParmId is invalid %d ", __FUNCTION__, paramId);
    }
}

tUWBAPI_STATUS getDeviceInfo(phUwbDevInfo_t *pdevInfo)
{
    uwb_device_info_t uwb_device_info = {0};
    uint8_t vendor_info[UCI_MAX_CTRL_PACKET_PAYLOAD_SIZE] = {0};
    uint8_t vendor_info_len = sizeof(vendor_info);
    uwb_device_info.vendorSpecificData = vendor_info;
    uwb_device_info.vendorSpecificLength = vendor_info_len;

    uwb_status_code_t status_code = uwb_api_core_get_device_info(&uwb_device_info);
    if (UWB_STATUS_CODE_SUCCESS != status_code) {
        /** Failed */
        return UWBAPI_STATUS_FAILED;
    }

#if UWBIOT_UWBD_SR04X
    pdevInfo->uciGenericVersion = (uwb_device_info.uciVersionMajor << 8) | uwb_device_info.uciVersionMinor;
    pdevInfo->macMajorVersion = uwb_device_info.macVersionMajor;
    pdevInfo->macMinorMaintenanceVersion = uwb_device_info.macVersionMinor;
    pdevInfo->phyMajorVersion = uwb_device_info.phyVersionMajor;
    pdevInfo->phyMinorMaintenanceVersion = uwb_device_info.phyVersionMinor;
    pdevInfo->uciTestVersion = (uwb_device_info.uciExtensionVersionMajor << 8) | uwb_device_info.uciExtensionVersionMinor;
    pdevInfo->mwMajor = UWBIOTVER_STR_VER_MAJOR;
    pdevInfo->mwMinor = UWBIOTVER_STR_VER_MINOR;
#else
    /** Parse from uwb_device_info_t to phUwbDevInfo_t */
    pdevInfo->uciGenericMajor = uwb_device_info.uciVersionMajor;
    pdevInfo->uciGenericMinorMaintenanceVersion = uwb_device_info.uciVersionMinor;
    pdevInfo->macMajorVersion = uwb_device_info.macVersionMajor;
    pdevInfo->macMinorMaintenanceVersion = uwb_device_info.macVersionMinor;
    pdevInfo->phyMajorVersion = uwb_device_info.phyVersionMajor;
    pdevInfo->phyMinorMaintenanceVersion = uwb_device_info.phyVersionMinor;
    pdevInfo->mwMajor                           = UWBIOTVER_STR_VER_MAJOR;
    pdevInfo->mwMinor                           = UWBIOTVER_STR_VER_MINOR;
    pdevInfo->mwRc                              = UWBIOTVER_STR_VER_DEV;
#endif

    if (FALSE == doParseManufacturerDevInfo(pdevInfo, uwb_device_info.vendorSpecificData, uwb_device_info.vendorSpecificLength)) {
        return UWBAPI_STATUS_FAILED;
    }
    return UWBAPI_STATUS_OK;
}

tUWBAPI_STATUS getCapsInfo(phUwbCapInfo_t *pDevCapabilities)
{
    uwb_dev_caps_t uwb_device_caps = {0};
    uint8_t extraCapsBuffer[100] = {0};
    uint16_t extraCapsLength = sizeof(extraCapsBuffer);
    uwb_device_caps.extraCapsBuffer = extraCapsBuffer;
    uwb_device_caps.extraCapsLength = extraCapsLength;
    uwb_status_code_t uwb_status = uwb_api_core_get_caps_info(&uwb_device_caps);

    if (UWB_STATUS_CODE_SUCCESS != uwb_status) {
        return UWBAPI_STATUS_FAILED;
    }

    pDevCapabilities->firaPhyLowerRangeMajorVersion = uwb_device_caps.firaPhyVersionRange.versions.lowMajor;
    pDevCapabilities->firaPhyLowerRangeMinorMaintenanceVersion = uwb_device_caps.firaPhyVersionRange.versions.lowMinor;
    pDevCapabilities->firaPhyHigherRangeMajorVersion = uwb_device_caps.firaPhyVersionRange.versions.highMajor;
    pDevCapabilities->firaPhyHigherRangeMinorMaintenanceVersion = uwb_device_caps.firaPhyVersionRange.versions.highMinor;
    pDevCapabilities->firaMacLowerRangeMajorVersion = uwb_device_caps.firaMacVersionRange.versions.lowMajor;
    pDevCapabilities->firaMacLowerRangeMinorMaintenanceVersion = uwb_device_caps.firaMacVersionRange.versions.lowMinor;
    pDevCapabilities->firaMacHigherRangeMajorVersion = uwb_device_caps.firaMacVersionRange.versions.highMajor;
    pDevCapabilities->firaMacHigherRangeMinorMaintenanceVersion = uwb_device_caps.firaMacVersionRange.versions.highMinor;
    pDevCapabilities->deviceTypes = uwb_device_caps.deviceType;
    pDevCapabilities->deviceRoles = uwb_device_caps.deviceRoles;
    pDevCapabilities->rangingMethod = uwb_device_caps.rangingMethod;
    pDevCapabilities->stsConfig = uwb_device_caps.stsConfig;
    pDevCapabilities->multiNodeMode = uwb_device_caps.multiNodeMode;
    pDevCapabilities->rangingTimeStruct = uwb_device_caps.rangingTimeStruct;
    pDevCapabilities->scheduledMode = uwb_device_caps.scheduleMode;
    pDevCapabilities->hoppingMode = uwb_device_caps.hoppingMode;
    pDevCapabilities->blockStriding = uwb_device_caps.blockStriding;
    pDevCapabilities->uwbInitiationTime = uwb_device_caps.uwbInitiationTime;
    pDevCapabilities->channels = uwb_device_caps.channels;
    pDevCapabilities->rframeConfig = uwb_device_caps.rframeConfig;
    pDevCapabilities->ccConstraintLength = uwb_device_caps.ccConstraintLength;
    pDevCapabilities->bprfParameterSets = uwb_device_caps.bprfParameterSets;
    memcpy(pDevCapabilities->hprfParameterSets, uwb_device_caps.hprfParameterSets, sizeof(uwb_device_caps.hprfParameterSets));
    pDevCapabilities->aoaSupport = uwb_device_caps.aoaSupport;
    pDevCapabilities->extendedMacAddress = uwb_device_caps.extendedMacAddress;
    pDevCapabilities->sessionKeyLen = uwb_device_caps.sessionKeyLength;
    pDevCapabilities->ancorMaxRrActive = uwb_device_caps.dtAnchorMaxActiveRr;
    pDevCapabilities->tagMaxRrActive = uwb_device_caps.dtTagMaxActiveRr;
    pDevCapabilities->maxMessageSize = uwb_device_caps.maxDataMessageSize;
    pDevCapabilities->maxDataPacketPayloadSize = uwb_device_caps.maxDataPacketPayloadSize;
    pDevCapabilities->llCapabilityParam = uwb_device_caps.llCapabilityParam;
    pDevCapabilities->bypassModeSupport = uwb_device_caps.bypassModeSupport;
    pDevCapabilities->minSlotDurationSupport = uwb_device_caps.minSlotDurationSupport;
    pDevCapabilities->firaLlVersion = uwb_device_caps.firaLlVersion;
#if !(UWBIOT_UWBD_SR040)
    pDevCapabilities->tagBlockSkipping = uwb_device_caps.dtTagBlockSkipping;
    pDevCapabilities->psduLengthSupport = uwb_device_caps.psduLengthSupport;
#endif /* UWBIOT_UWBD_SR040 */

#if !(UWBIOT_UWBD_SR04X)
    // CCC capabilities (0xA0 - 0xA7)
    pDevCapabilities->slotBitmask = uwb_device_caps.ccc_slot_bitmask;
    pDevCapabilities->syncCodeIndexBitmask = uwb_device_caps.ccc_sync_code_index_bitmask;
    pDevCapabilities->hoppingConfigBitmask = uwb_device_caps.ccc_hopping_config_bitmask;
    pDevCapabilities->channelBitmask = uwb_device_caps.ccc_channel_bitmask;

    // CCC Supported Protocol Versions (0xA4)
    pDevCapabilities->numSupportedProtocolVersions = uwb_device_caps.num_ccc_supported_protocol_versions;
    if (pDevCapabilities->numSupportedProtocolVersions > NUM_SUPPORTED_PROTOCOL_VERSIONS) {
        LOG_WRN("CCC protocol versions count (%d) exceeds buffer size (%d), truncating",
                pDevCapabilities->numSupportedProtocolVersions, NUM_SUPPORTED_PROTOCOL_VERSIONS);
        pDevCapabilities->numSupportedProtocolVersions = NUM_SUPPORTED_PROTOCOL_VERSIONS;
    }
    memcpy(pDevCapabilities->supportedProtocolVersions,
           uwb_device_caps.ccc_supported_protocol_versions,
           pDevCapabilities->numSupportedProtocolVersions * sizeof(uint16_t));

    // CCC Supported UWB Config IDs (0xA5)
    pDevCapabilities->numSupportedUWBConfigIDs = uwb_device_caps.num_ccc_supported_uwb_config_id;
    if (pDevCapabilities->numSupportedUWBConfigIDs > NUM_SUPPORTED_UWB_CONFIG_ID) {
        LOG_WRN("CCC UWB config IDs count (%d) exceeds buffer size (%d), truncating",
                pDevCapabilities->numSupportedUWBConfigIDs, NUM_SUPPORTED_UWB_CONFIG_ID);
        pDevCapabilities->numSupportedUWBConfigIDs = NUM_SUPPORTED_UWB_CONFIG_ID;
    }
    memcpy(pDevCapabilities->supportedUWBConfigIDs,
           uwb_device_caps.ccc_supported_uwb_config_id,
           pDevCapabilities->numSupportedUWBConfigIDs * sizeof(uint16_t));

    // CCC Supported Pulseshape Combo (0xA6)
    uint8_t pulseshape_count = uwb_device_caps.num_ccc_supported_pulseshape_combo;
    if (pulseshape_count > DEVICE_CAPABILITY_LEN_9) {
        LOG_WRN("CCC pulseshape combo count (%d) exceeds buffer size (%d), truncating",
                pulseshape_count, DEVICE_CAPABILITY_LEN_9);
        pulseshape_count = DEVICE_CAPABILITY_LEN_9;
    }
    memcpy(pDevCapabilities->supportedPulseShapeCombo,
           uwb_device_caps.ccc_supported_pulseshape_combo,
           pulseshape_count);

    // CCC Minimum RAN Multiplier (0xA7)
    pDevCapabilities->minRanMultiplier = uwb_device_caps.ccc_minimum_ran_multiplier;
#endif // !(UWBIOT_UWBD_SR04X)

#if UWBFTR_CSA
    // Aliro capabilities (0xAC - 0xAD)
    pDevCapabilities->aliroSupportedMacMode = uwb_device_caps.aliro_supported_mac_mode;

    // Aliro Supported Protocol Versions (0xAD)
    pDevCapabilities->numAliroSupportedProtocolVersions = uwb_device_caps.num_aliro_supported_protocol_versions;
    if (pDevCapabilities->numAliroSupportedProtocolVersions > NUM_SUPPORTED_ALIRO_PROTOCOL_VERSIONS) {
        LOG_WRN("Aliro protocol versions count (%d) exceeds buffer size (%d), truncating",
                pDevCapabilities->numAliroSupportedProtocolVersions, NUM_SUPPORTED_ALIRO_PROTOCOL_VERSIONS);
        pDevCapabilities->numAliroSupportedProtocolVersions = NUM_SUPPORTED_ALIRO_PROTOCOL_VERSIONS;
    }
    memcpy(pDevCapabilities->aliroSupportedProtocolVersion,
           uwb_device_caps.aliro_supported_protocol_versions,
           pDevCapabilities->numAliroSupportedProtocolVersions * sizeof(uint16_t));
#endif /* UWBFTR_CSA */

    /** Parse extra capability params */
    if (parseExtraCapabilityInfo(pDevCapabilities, uwb_device_caps.extraCapsBuffer, uwb_device_caps.extraCapsLength) == FALSE) {
        LOG_ERR("%s: Parsing Capability Information Failed", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    return UWBAPI_STATUS_OK;
}

tUWBAPI_STATUS parseUwbSessionParams(uint8_t *rspPtr, phUwbSessionsContext_t *pUwbSessionsContext)
{
    tUWBAPI_STATUS status;
    uint32_t index = 0;
    // Validation of all the parameters needs to be added.
    const uint8_t maxAvailableCount = pUwbSessionsContext->sessioncnt;
    if (maxAvailableCount == 0) {
        LOG_WRN("pUwbSessionsContext->sessioncnt is not set");
        status = UWBAPI_STATUS_FAILED;
        goto exit;
    }
    else if (maxAvailableCount > 10) {
        LOG_WRN("Seems pUwbSessionsContext->sessioncnt is garbage");
        status = UWBAPI_STATUS_FAILED;
        goto exit;
    }
    else {
        UWB_STREAM_TO_UINT8(pUwbSessionsContext->sessioncnt, rspPtr, index);

        if (maxAvailableCount < pUwbSessionsContext->sessioncnt) {
            LOG_WRN("Param Error: Not all Values returned for session. ");
            pUwbSessionsContext->sessioncnt = maxAvailableCount;
            pUwbSessionsContext->status     = kUWBSTATUS_BUFFER_TOO_SMALL;
        }

        for (uint8_t i = 0; i < pUwbSessionsContext->sessioncnt; i++) {
            UWB_STREAM_TO_UINT32(pUwbSessionsContext->pUwbSessionData[i].sessionHandle, rspPtr, index);
            UWB_STREAM_TO_UINT8(pUwbSessionsContext->pUwbSessionData[i].session_type, rspPtr, index);
            UWB_STREAM_TO_UINT8(pUwbSessionsContext->pUwbSessionData[i].session_state, rspPtr, index);
        }
        printUwbSessionData(pUwbSessionsContext);
        status = UWBAPI_STATUS_OK;
    }
exit:
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetAllUwbSessions(phUwbSessionsContext_t *pUwbSessionsContext)
{
    tUWBAPI_STATUS status;
    uint32_t index = 0;
    uint32_t response_len = sizeof(uwbContext.rsp_data);
    LOG_DBG("%s: Enter", __FUNCTION__);

    if (pUwbSessionsContext == NULL) {
        LOG_ERR("%s: UwbSessionsContext is NULL", __FUNCTION__);
        return UWB_STATUS_CODE_INVALID_ARGUMENT;
    }

#if UWBIOT_UWBD_SR04X
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_GET_ALL_UWB_SESSIONS,
                        NULL, 0, uwbContext.rsp_data, &response_len);
#else
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_GET_ALL_UWB_SESSIONS,
                        NULL, 0, uwbContext.rsp_data, &response_len);
#endif
    uwbContext.rsp_len = response_len;
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = uwbContext.rsp_data[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: GetAllUWBSessions successful", __FUNCTION__);
        /* rsp_data contains complete rsp, we have to skip Header */
        uint8_t *rspPtr = &uwbContext.rsp_data[UCI_HEADER_SIZE];
        UWB_STREAM_TO_UINT8(pUwbSessionsContext->status, rspPtr, index);

        if (pUwbSessionsContext->status == UWBAPI_STATUS_OK) {
            /*
             * Parse all the response parameters are correct or not.
             */
            status = parseUwbSessionParams((rspPtr + index), pUwbSessionsContext);
            if (status != UWBAPI_STATUS_OK) {
                LOG_ERR("%s: parseUwbSessionParams failed", __FUNCTION__);
            }
        }
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: GetAllUWBSessions Command Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR("%s: GetAllUWBSessions failed", __FUNCTION__);
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

static BOOLEAN parseExtraCapabilityInfo(phUwbCapInfo_t *pDevCap, uint8_t *capsInfoData, uint16_t capsInfoLen)
{
    BOOLEAN status        = TRUE;
    uint16_t index        = 0;
    uint8_t extParamId    = 0;
    uint8_t length        = 0;

    if ((capsInfoLen == 0) || (capsInfoData == NULL)) {
        LOG_ERR("%s: capsInfoLen is zero or capsInfoData is NULL", __FUNCTION__);
        return FALSE;
    }

    while (index < capsInfoLen) {
        // Store Ext Param Id in case of 0xE0, 0xE1,..or Param Id in case of 0xA0, 0xA1,..0x01, 0x02,...
        extParamId = capsInfoData[index++];

        if ((extParamId & EXTENDED_PARAM_ID_MASK) == CCC_EXT_PARAM_ID) {
#if !(UWBIOT_UWBD_SR04X)
            if (extParamId == EXTENDED_CAP_INFO_ID) {
                index++; // skip the param ID
            }
#endif /** UWBIOT_UWBD_SR04X */
            length = capsInfoData[index++];
            if((length + index) > capsInfoLen) {
                LOG_ERR("%s: Invalid length for extended capability info : %d", __FUNCTION__, __LINE__);
                status = FALSE;
                break;
            }
            index = (uint8_t)(index + length);
        }
        else {
            length = capsInfoData[index++];
            if((length + index) > capsInfoLen) {
                LOG_ERR("%s: Invalid length for extended capability info : %d", __FUNCTION__, __LINE__);
                status = FALSE;
                break;
            }

            switch (extParamId) {
#if !(UWBIOT_UWBD_SR040)
            case SUSPEND_RANGING_ID: {
                if (length != DEVICE_CAPABILITY_LEN_1) {
                    return FALSE;
                }
                pDevCap->suspendRanging = capsInfoData[index++];
            } break;
#if !(UWBIOT_UWBD_SR048M)
            case UCI_EXT_PARAM_ID_UWBS_MAX_UCI_PAYLOAD_LENGTH: {
                if (length != DEVICE_CAPABILITY_LEN_2) {
                    return FALSE;
                }
                memcpy(&pDevCap->maxUciPayloadLength, &capsInfoData[index], length);
                index = (uint8_t)(index + length);
            } break;
            case UCI_EXT_PARAM_ID_UWBS_INBAND_DATA_BUFFER_BLOCK_SIZE: {
                if (length != DEVICE_CAPABILITY_LEN_1) {
                    return FALSE;
                }
                pDevCap->inbandDataBlockSize = capsInfoData[index++];
            } break;
            case UCI_EXT_PARAM_ID_UWBS_INBAND_DATA_MAX_BLOCKS: {
                if (length != DEVICE_CAPABILITY_LEN_1) {
                    return FALSE;
                }
                pDevCap->inbandDataMaxBlock = capsInfoData[index++];
            } break;
#endif //  !(UWBIOT_UWBD_SR048M)
#endif /** !(UWBIOT_UWBD_SR040) */
            default: {
                LOG_WRN("%s: Unknown capability param ID: 0x%X", __FUNCTION__, extParamId);
                index = (uint8_t)(index + length);
            } break;
            }
        }
    } // End Of While

    return status;
}

const char *getStatusString(uint8_t status)
{
    switch (status) {
    case UWBAPI_STATUS_REJECTED:
        return "UWBAPI_STATUS_REJECTED";
    case UWBAPI_STATUS_FAILED:
        return "UWBAPI_STATUS_FAILED";
    case UWBAPI_STATUS_NOT_INITIALIZED:
        return "UWBAPI_STATUS_NOT_INITIALIZED";
    case UWBAPI_STATUS_INVALID_PARAM:
        return "UWBAPI_STATUS_INVALID_PARAM";
    case UWBAPI_STATUS_INVALID_RANGE:
        return "UWBAPI_STATUS_INVALID_RANGE";
    case UWBAPI_STATUS_SESSION_NOT_EXIST:
        return "UWBAPI_STATUS_SESSION_NOT_EXIST";
    case UWBAPI_STATUS_SESSION_ACTIVE:
        return "UWBAPI_STATUS_SESSION_ACTIVE";
    case UWBAPI_STATUS_MAX_SESSIONS_EXCEEDED:
        return "UWBAPI_STATUS_MAX_SESSIONS_EXCEEDED";
    case UWBAPI_STATUS_SESSION_NOT_CONFIGURED:
        return "UWBAPI_STATUS_SESSION_NOT_CONFIGURED";
    case UWBAPI_STATUS_SESSIONS_ONGOING:
        return "UWBAPI_STATUS_SESSIONS_ONGOING";
    case UWBAPI_STATUS_MULTICAST_LIST_FULL:
        return "UWBAPI_STATUS_MULTICAST_LIST_FULL";
    case UWBAPI_STATUS_OK_NEGATIVE_DISTANCE_REPORT:
        return "UWBAPI_STATUS_OK_NEGATIVE_DISTANCE_REPORT";
    case UWBAPI_STATUS_ESE_RESET:
        return "UWBAPI_STATUS_ESE_RESET";
    case UWBAPI_STATUS_NO_CREDIT_AVAILABLE:
        return "UWBAPI_STATUS_NO_CREDIT_AVAILABLE";
    case UWBAPI_STATUS_ERROR_ROUND_INDEX_NOT_ACTIVATED:
        return "UWBAPI_STATUS_ERROR_ROUND_INDEX_NOT_ACTIVATED";
    case UWBAPI_STATUS_ERROR_NUMBER_OF_ACTIVE_RANGING_ROUNDS_EXCEEDED:
        return "UWBAPI_STATUS_ERROR_NUMBER_OF_ACTIVE_RANGING_ROUNDS_EXCEEDED";
    case UWBAPI_STATUS_ERROR_ROUND_INDEX_NOT_SET_AS_INITIATOR:
        return "UWBAPI_STATUS_ERROR_ROUND_INDEX_NOT_SET_AS_INITIATOR";
    case UWBAPI_STATUS_ROLE_ERROR:
        return "UWBAPI_STATUS_ROLE_ERROR";
    case UWBAPI_STATUS_BUFFER_OVERFLOW:
        return "UWBAPI_STATUS_BUFFER_OVERFLOW";
    case UWBAPI_STATUS_PBF_PKT_SENT:
        return "UWBAPI_STATUS_PBF_PKT_SENT";
    case UWBAPI_STATUS_HPD_WAKEUP:
        return "UWBAPI_STATUS_HPD_WAKEUP";
    case UWBAPI_STATUS_TIMEOUT:
        return "UWBAPI_STATUS_TIMEOUT";
    case UWBAPI_STATUS_ESE_ERROR:
        return "UWBAPI_STATUS_ESE_ERROR";
    case UWBAPI_STATUS_SUSPEND:
        return "UWBAPI_STATUS_SUSPEND";
    case UWBAPI_STATUS_SESSION_RSN_RADAR_RFRI_INVALID:
        return "UWBAPI_STATUS_SESSION_RSN_RADAR_RFRI_INVALID";
    case UWBAPI_STATUS_UNKNOWN:
        return "UWBAPI_STATUS_UNKNOWN";
    default:
        return "STATUS NOT AWARE";
    }
}

void uwb_generic_callback_handler(uint8_t *pData, uint32_t length)
{
    /** FIXME: To be implemented */
}
