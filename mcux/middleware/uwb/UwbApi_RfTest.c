/*
 *
 * Copyright 2018-2020,2022,2023,2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "UwbApi_RfTest.h"
#include "zephyr/uwb/uci.h"
#include "uci_test_defs.h"
#include "uci_ext_defs.h"
#include "UwbApi_Internal.h"
#include "UwbApi_Proprietary.h"
#include "UwbApi_Proprietary_Internal.h"
#include "AppConfigParams.h"
//#include "UwbAdaptation.h"
#include "UwbApi_Utility.h"
#include "zephyr/kernel.h"
#include "phUwbStatus.h"
#include "zephyr/uwb/uwb.h"

#include "zephyr/logging/log.h"
LOG_MODULE_REGISTER(uwb_api, CONFIG_UWB_LOG_LEVEL);

extern struct k_sem g_uwb_nxp_semaphore;

/** Local functions prototypes */
static void parsePerTestParams(uint8_t *rspPtr, uint8_t noOfParams, phRfTestParams_t *pRfTestParams);

/**
 **
 ** Function:        parsePerTestParams
 **
 ** Description:     Extracts PER Test config Params from the given byte array
 *and updates the structure
 **
 ** Returns:         None
 **
 */
static void parsePerTestParams(uint8_t *rspPtr, uint8_t noOfParams, phRfTestParams_t *pRfTestParams)
{
    uint8_t paramId;
    uint32_t index = 0;

    for (int i = 0; i < noOfParams; i++) {
        UWB_STREAM_TO_UINT8(paramId, rspPtr, index);
        ++index; // Skip the length field
        switch (paramId) {
        case UCI_TEST_PARAM_ID_NUM_PACKETS:
            UWB_STREAM_TO_UINT32(pRfTestParams->numOfPckts, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_T_GAP:
            UWB_STREAM_TO_UINT32(pRfTestParams->tGap, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_T_START:
            UWB_STREAM_TO_UINT32(pRfTestParams->tStart, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_T_WIN:
            UWB_STREAM_TO_UINT32(pRfTestParams->tWin, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_RANDOMIZE_PSDU:
            UWB_STREAM_TO_UINT8(pRfTestParams->randomizedSize, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_PHR_RANGING_BIT:
            UWB_STREAM_TO_UINT8(pRfTestParams->phrRangingBit, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_RMARKER_RX_START:
            UWB_STREAM_TO_UINT32(pRfTestParams->rmarkerRxStart, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_RMARKER_TX_START:
            UWB_STREAM_TO_UINT32(pRfTestParams->rmarkerTxStart, rspPtr, index);
            break;
        case UCI_TEST_PARAM_ID_STS_INDEX_AUTO_INCR:
            UWB_STREAM_TO_UINT8(pRfTestParams->stsIndexAutoIncr, rspPtr, index);
            break;
        default:
            break;
        }
    }
}

EXTERNC tUWBAPI_STATUS UwbApi_SetRfTestParams(uint32_t sessionHandle, const phRfTestParams_t *pRfTestParams)
{
    tUWBAPI_STATUS status;
    uint8_t noOfPerParams = 0;
    uint8_t paramLen      = 0;
    uint16_t cmdLen       = 0;
    size_t appConfigDataLen = 0;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    uint32_t response_len = sizeof(uwbContext.rsp_data);

    uint8_t noOfControlees   = 1;
    uint8_t deviceMacAddr[2] = {0x11, 0x11};
    uint8_t dstMacAddr[2]    = {0x22, 0x22};

    LOG_DBG("%s: enter", __FUNCTION__);

    if (pRfTestParams == NULL) {
        LOG_ERR("%s: pPerParam is NULL", __FUNCTION__);
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_NUM_PACKETS,
        sizeof(pRfTestParams->numOfPckts),
        (void *)&pRfTestParams->numOfPckts,
        &uwbContext.snd_data[payloadOffset]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_T_GAP,
        sizeof(pRfTestParams->tGap),
        (void *)&pRfTestParams->tGap,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_T_START,
        sizeof(pRfTestParams->tStart),
        (void *)&pRfTestParams->tStart,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_T_WIN,
        sizeof(pRfTestParams->tWin),
        (void *)&pRfTestParams->tWin,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_RANDOMIZE_PSDU,
        sizeof(pRfTestParams->randomizedSize),
        (void *)&pRfTestParams->randomizedSize,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_PHR_RANGING_BIT,
        sizeof(pRfTestParams->phrRangingBit),
        (void *)&pRfTestParams->phrRangingBit,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_RMARKER_TX_START,
        sizeof(pRfTestParams->rmarkerTxStart),
        (void *)&pRfTestParams->rmarkerTxStart,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_RMARKER_RX_START,
        sizeof(pRfTestParams->rmarkerRxStart),
        (void *)&pRfTestParams->rmarkerRxStart,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_STS_INDEX_AUTO_INCR,
        sizeof(pRfTestParams->stsIndexAutoIncr),
        (void *)&pRfTestParams->stsIndexAutoIncr,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }

    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getTestConfigTLVBuffer(UCI_TEST_PARAM_ID_STS_DETECT_BITMAP_EN,
        sizeof(pRfTestParams->sts_detect_bitmap_en),
        (void *)&pRfTestParams->sts_detect_bitmap_en,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }

    ++noOfPerParams; // Increment the number of debug params count

    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfPerParams, paramLen, uwbContext.snd_data);
    // status = sendUciCommandAndWait(UWA_DM_API_TEST_SET_CONFIG_EVT, cmdLen, uwbContext.snd_data);

    uint8_t ntf_buff[10] = {0};
    uint32_t ntf_buff_len = sizeof(ntf_buff);
    void *scheduled_ntf = uwb_uci_schedule_packet_read(
        UCI_MT_NTF, UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_STATUS_NTF, ntf_buff, &ntf_buff_len, &g_uwb_nxp_semaphore);
    if (NULL == scheduled_ntf) {
        LOG_ERR("Could not schedule packet read");
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    int ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_SET_CONFIG,
                    uwbContext.snd_data, cmdLen,
                    uwbContext.rsp_data, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }
    status = uwbContext.rsp_data[UCI_HEADER_SIZE];
    if (status != UCI_STATUS_CODE_OK) {
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return status;
    }

    noOfPerParams = 0;
    payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    paramLen      = 0;
    appConfigDataLen = getAppConfigTLVBuffer(UCI_PARAM_ID_NO_OF_CONTROLEES,
        UCI_PARAM_LEN_NO_OF_CONTROLEES,
        (void *)&noOfControlees,
        &uwbContext.snd_data[payloadOffset]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getAppConfigTLVBuffer(UCI_PARAM_ID_DEVICE_MAC_ADDRESS,
        UCI_PARAM_LEN_DEVICE_MAC_ADDRESS,
        (void *)&deviceMacAddr,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    appConfigDataLen = getAppConfigTLVBuffer(UCI_PARAM_ID_DST_MAC_ADDRESS,
        (uint8_t)(UCI_PARAM_LEN_DEST_MAC_ADDRESS * noOfControlees),
        (void *)&dstMacAddr,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }
    ++noOfPerParams; // Increment the number of debug params count

    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfPerParams, paramLen, uwbContext.snd_data);
    // status = sendUciCommandAndWait(UWA_DM_API_SESSION_SET_APP_CONFIG_EVT, cmdLen, uwbContext.snd_data);
    ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_SET_APP_CONFIG,
                    uwbContext.snd_data, cmdLen,
                    uwbContext.rsp_data, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = uwbContext.rsp_data[UCI_HEADER_SIZE];
    uint32_t notified_session_handle = 0;
    uint8_t notified_session_state = 0;
    uint32_t offset = UCI_HEADER_SIZE;
    const k_timeout_t timeout  = Z_TIMEOUT_MS(UWB_NTF_TIMEOUT);

    if (UWB_STATUS_CODE_SUCCESS != k_sem_take(&g_uwb_nxp_semaphore, timeout)) {
        LOG_ERR("Did not receive notification");
        status = UWB_STATUS_CODE_FAILED;
    }
    else {
        UWB_STREAM_TO_UINT32(notified_session_handle, ntf_buff, offset);
        UWB_STREAM_TO_UINT8(notified_session_state, ntf_buff, offset);
    }

    if (status == UWBAPI_STATUS_OK) {
        if (notified_session_handle != sessionHandle || notified_session_state != UWB_SESSION_STATUS_IDLE) {
            LOG_ERR("%s: Failed to get SESSION_IDLE notification", __FUNCTION__);
            status = UWBAPI_STATUS_FAILED;
        }
    }

    uwb_uci_remove_scheduled_packet(scheduled_ntf);
    k_sem_reset(&g_uwb_nxp_semaphore);

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetRfTestParams(uint32_t sessionHandle, phRfTestParams_t *pRfTestParams)
{
    tUWBAPI_STATUS status;
    uint8_t *pGetRfParamsCommand = NULL;
    uint16_t index               = 0;
    uint16_t paramId             = 0;
    uint8_t noOfParams;
    uint16_t cmdLen       = 0;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    uint8_t *response     = uwbContext.rsp_data;
    uint32_t response_len = sizeof(uwbContext.rsp_data);

    LOG_DBG("%s: Enter", __FUNCTION__);

    if (pRfTestParams == NULL) {
        LOG_ERR("%s: pPerParams is NULL", __FUNCTION__);
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    memset(uwbContext.rsp_data, 0x00, sizeof(uwbContext.rsp_data));

    /* Get Test Config */
    noOfParams          = (uint8_t)(uciRfTest_TestParamIds_len / sizeof(uint8_t));
    pGetRfParamsCommand = &uwbContext.snd_data[0];
    for (index = 0; index < noOfParams; index++) {
        paramId = uciRfTest_TestParamIds[index];
        UWB_UINT8_TO_STREAM(pGetRfParamsCommand, paramId, payloadOffset);
        LOG_DBG("%s: App ID: %02X", __FUNCTION__, paramId);
    }
    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfParams, noOfParams, uwbContext.snd_data);
    // status = sendUciCommandAndWait(UWA_DM_API_TEST_GET_CONFIG_EVT, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_GET_CONFIG,
                    uwbContext.snd_data, cmdLen,
                    response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        parsePerTestParams(response, noOfParams, pRfTestParams);
    }
    else {
        LOG_DBG("%s: Failed UWA_TestGetConfig", __FUNCTION__);
        return status;
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_SetTestConfig(uint32_t sessionHandle, eTestConfig param_id, uint32_t param_value)
{
    uint8_t paramLen      = 0;
    uint8_t noOfParams    = 1;
    uint16_t cmdLen       = 0;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    uint8_t response[10]  = {0};
    uint32_t response_len = sizeof(response);

    tUWBAPI_STATUS status;
    LOG_DBG("%s: enter", __FUNCTION__);

    if ((param_id >> 8) == EXTENDED_TEST_CONFIG_ID) {
        paramLen = getExtTestConfigTLVBuffer(param_id, (void *)&param_value, &uwbContext.snd_data[payloadOffset]);
    }
    else {
        paramLen = getTestConfigTLVBuffer(param_id, 0, (void *)&param_value, &uwbContext.snd_data[payloadOffset]);
    }

    if (paramLen == 0) {
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfParams, paramLen, uwbContext.snd_data);
    // status = sendUciCommandAndWait(UWA_DM_API_TEST_SET_CONFIG_EVT, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_SET_CONFIG,
                    uwbContext.snd_data, cmdLen,
                    response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetTestConfig(uint32_t sessionHandle, eTestConfig param_id, uint32_t *param_value)
{
    uint8_t len                    = 0;
    uint8_t offset                 = 0;
    uint8_t noOfParams             = 1;
    uint8_t paramLen               = 1;
    uint16_t cmdLen                = 0;
    uint8_t *pGetTestConfigCommand = NULL;
    uint8_t payloadOffset          = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    uint8_t *response              = uwbContext.rsp_data;
    uint32_t response_len          = sizeof(uwbContext.rsp_data);

    tUWBAPI_STATUS status;
    LOG_DBG("%s: enter", __FUNCTION__);

    if (param_value == NULL) {
        LOG_ERR("%s: param_value is NULL", __FUNCTION__);
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    memset(uwbContext.rsp_data, 0x00, sizeof(uwbContext.rsp_data));

    pGetTestConfigCommand = &uwbContext.snd_data[0];
    if ((param_id >> 8) == EXTENDED_TEST_CONFIG_ID) {
        paramLen++;
        UWB_UINT8_TO_STREAM(pGetTestConfigCommand, param_id >> 8, payloadOffset);
        UWB_UINT8_TO_STREAM(pGetTestConfigCommand, param_id, payloadOffset);
    }
    else {
        UWB_UINT8_TO_STREAM(pGetTestConfigCommand, param_id, payloadOffset);
    }
    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfParams, paramLen, uwbContext.snd_data);
    // status = sendUciCommandAndWait(UWA_DM_API_TEST_GET_CONFIG_EVT, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_GET_CONFIG,
                    uwbContext.snd_data, cmdLen,
                    response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    offset = UCI_HEADER_SIZE;
    status = response[offset++];
    if (status == UWBAPI_STATUS_OK) {
        /* no_of_params */
        offset++;
        if ((param_id >> 8) == EXTENDED_TEST_CONFIG_ID) {
            offset += 2;
        }
        else {
            offset++;
        }
        UWB_STREAM_TO_UINT8(len, response, offset);

        if (len == sizeof(uint8_t)) {
            UWB_STREAM_TO_UINT8(*param_value, response, offset);
        }
        else if (len == sizeof(uint16_t)) {
            UWB_STREAM_TO_UINT16(*param_value, response, offset);
        }
        else if (len == sizeof(uint32_t)) {
            UWB_STREAM_TO_UINT32(*param_value, response, offset);
        }
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_StartRfTest(eStartRfParam paramId, phRfStartData_t *pStartData)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = -1;
    LOG_DBG("%s: enter", __FUNCTION__);

    if ((paramId != RF_TEST_RX) && pStartData == NULL) { // for Single Rx RF test psdu data is NUL
        LOG_ERR("%s: Input data is NULL", __FUNCTION__);
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    switch (paramId) {
    case RF_START_PER_TX:
        if (((phStartPerTxData_t *)pStartData)->txData == NULL) {
            LOG_ERR("%s: Input data is NULL for RF_START_PER_TX", __FUNCTION__);
            status = UWBAPI_STATUS_INVALID_PARAM;
            break;
        }
        cmdLen = serializeTestDataPayload(((phStartPerTxData_t *)pStartData)->txDataLength,
            ((phStartPerTxData_t *)pStartData)->txData,
            uwbContext.snd_data);
        // status = sendUciCommandAndWait(UWA_DM_API_TEST_PERIODIC_TX_EVT, cmdLen, uwbContext.snd_data);
        ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_PERIODIC_TX,
                    uwbContext.snd_data, cmdLen,
                    response, &response_len);
        if (0 != ret) {
            LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
            return UWBAPI_STATUS_FAILED;
        }
        status = response[UCI_HEADER_SIZE];
        break;
    case RF_START_PER_RX:
        if (((phStartPerRxData_t *)pStartData)->rxData == NULL) {
            LOG_ERR("%s: Input data is NULL for RF_START_PER_RX", __FUNCTION__);
            status = UWBAPI_STATUS_INVALID_PARAM;
            break;
        }

        cmdLen = serializeTestDataPayload(((phStartPerRxData_t *)pStartData)->rxDataLength,
            ((phStartPerRxData_t *)pStartData)->rxData,
            uwbContext.snd_data);
        // status = sendUciCommandAndWait(UWA_DM_API_TEST_PER_RX_EVT, cmdLen, uwbContext.snd_data);
        ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_PER_RX,
                    uwbContext.snd_data, cmdLen,
                    response, &response_len);
        if (0 != ret) {
            LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
            return UWBAPI_STATUS_FAILED;
        }
        status = response[UCI_HEADER_SIZE];
        break;
    case RF_LOOPBACK_TEST:
        if (((phLoopbackTestData_t *)pStartData)->loopbackData == NULL) {
            LOG_ERR("%s: Input data is NULL for RF_LOOPBACK_TEST", __FUNCTION__);
            status = UWBAPI_STATUS_INVALID_PARAM;
            break;
        }

        cmdLen = serializeTestDataPayload(((phLoopbackTestData_t *)pStartData)->loopbackDataLength,
            ((phLoopbackTestData_t *)pStartData)->loopbackData,
            uwbContext.snd_data);
        // status = sendUciCommandAndWait(UWA_DM_API_TEST_UWB_LOOPBACK_EVT, cmdLen, uwbContext.snd_data);
        ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_LOOPBACK,
            uwbContext.snd_data, cmdLen,
            response, &response_len);
        if (0 != ret) {
            LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
            return UWBAPI_STATUS_FAILED;
        }
        status = response[UCI_HEADER_SIZE];
        break;
    case RF_TEST_RX:

        // status = sendUciCommandAndWait(UWA_DM_API_TEST_RX_EVT, 0, NULL);
        ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_RX,
            NULL, 0,
            response, &response_len);
        if (0 != ret) {
            LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
            return UWBAPI_STATUS_FAILED;
        }
        status = response[UCI_HEADER_SIZE];
        break;
    case RF_TEST_SR_RX:
        // status = sendUciCommandAndWait(UWA_DM_API_TEST_SR_RX_EVT, 0, NULL);
        ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_SR_RX,
            NULL, 0,
            response, &response_len);
        if (0 != ret) {
            LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
            return UWBAPI_STATUS_FAILED;
        }
        status = response[UCI_HEADER_SIZE];
        break;
    default:
        LOG_ERR("%s:    Invalid Param ", __FUNCTION__);
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_Stop_RfTest(void)
{
    tUWBAPI_STATUS status = UWBAPI_STATUS_FAILED;

    LOG_DBG("%s: enter", __FUNCTION__);

    uint8_t ntf_buff[10] = {0};
    uint32_t ntf_buff_len = sizeof(ntf_buff);
    const k_timeout_t timeout = Z_TIMEOUT_MS(UWB_NTF_TIMEOUT);

    void *scheduled_ntf = uwb_uci_schedule_packet_read(
        UCI_MT_NTF, UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_STATUS_NTF, ntf_buff, &ntf_buff_len, &g_uwb_nxp_semaphore);
    if (NULL == scheduled_ntf) {
        LOG_ERR("Could not schedule packet read");
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_TEST, UCI_MSG_TEST_STOP_SESSION,
                        NULL, 0, response, &response_len);
    if (0 != ret) {
        LOG_ERR("Could not transceive UCI packet");
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return status;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("Stop reset failed");
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return status;
    }

    if (UWB_STATUS_CODE_SUCCESS != k_sem_take(&g_uwb_nxp_semaphore, timeout)) {
        LOG_ERR("Did not receive SESSION_STATUS_NTF");
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    if (ntf_buff[UCI_HEADER_SIZE + UCI_SESSION_HANDLE_LENGTH] != UWB_SESSION_STATUS_IDLE) {
        LOG_ERR("Session did not transition to idle state");
        status = UWBAPI_STATUS_FAILED;
    }

    uwb_uci_remove_scheduled_packet(scheduled_ntf);
    k_sem_reset(&g_uwb_nxp_semaphore);


    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}
