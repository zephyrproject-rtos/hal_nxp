/*
 *
 * Copyright 2018-2020,2022-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "UwbApi.h"
#include "AppConfigParams.h"
#include "uci_ext_defs.h"
#include "zephyr/kernel.h"
#include "phNxpUwbConfig.h"
#include "zephyr/uwb/tml.h"
#if (UWBFTR_SE_SE051W)
#include "SE_Wrapper.h"
#endif

#include "UwbApi_Utility.h"
#include "UwbApi_Internal.h"
#include "UwbApi_Proprietary_Internal.h"
#include "zephyr/uwb/uwb_core.h"
#include "zephyr/uwb/uwb.h"

#if UWBIOT_UWBD_SR1XXT
#include <Mainline_Firmware.h>
#endif // UWBIOT_UWBD_SR1XXT
#if UWBIOT_UWBD_SR1XXT_SR2XXT
#include "uwb_fwdl_provider.h"
#endif // UWBIOT_UWBD_SR1XXT_SR2XXT
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_uwb_api, LOG_LEVEL_INF);

#define MAX_SUPPORTED_TDOA_REPORT_FREQ 22
#define MIN_TRNG_SIZE                  0x01
#define MAX_TRNG_SIZE                  0x10
#define CHANNEL_5                      5
#define CHANNEL_6                      6
#define CHANNEL_8                      8
#define CHANNEL_9                      9
#define SEND_DATA_HEADER_LEN           16 // 4(Session Handle) + 8(mac address) + 1(dst endpoint) + 1(seq no) + 2(data size)

/* Minimum number of controlees for time based ranging is 1*/
/*In case of contention based ranging, this could be 0*/
#define MIN_NUM_OF_CONTROLEES 1

struct k_sem g_uwb_nxp_semaphore;
static bool g_uwb_nxp_is_initialized = false;

EXTERNC tUWBAPI_STATUS UwbApi_Initialize(phUwbappContext_t *pAppCtx)
{
    tUWBAPI_STATUS status                 = kUwb_StatusCode_InvalidArgument;
    /*By Default Operating mode Should be Default*/

    LOG_DBG("%s: Enter", __FUNCTION__);
    if (pAppCtx == NULL) {
        LOG_ERR("pAppCtx is Null");
        goto exit;
    }

    if ((pAppCtx->pCallback == NULL) && (pAppCtx->pTmlCallback == NULL)) {
        LOG_ERR("Atleast 1 appcallback should be set");
        goto exit;
    }
    if (pAppCtx->pCallback && pAppCtx->pTmlCallback) {
        LOG_ERR("Atmost one callback should be registered");
        goto exit;
    }

    uwbContext.fwMode = pAppCtx->fwImageCtx.fwMode;
    /* This check is needed, to allow FW download from external-flash, where in the fwImageCtx is NULL */
#if UWBIOT_UWBD_SR1XXT && UWB_BLD_CFG_FW_DNLD_DIRECTLY_FROM_HOST
    if (pAppCtx->fwImageCtx.fwImage == NULL || pAppCtx->fwImageCtx.fwImgSize == 0) {
        LOG_ERR("Cannot download the firmware without passing the firmware context");
        goto exit;
    }
#endif // UWBIOT_UWBD_SR1XXT && UWB_BLD_CFG_FW_DNLD_DIRECTLY_FROM_HOST

#if UWBIOT_UWBD_SR1XXT_SR2XXT
    if (uwb_fwdl_setFwImage(&pAppCtx->fwImageCtx) != kUWBSTATUS_SUCCESS) {
        LOG_ERR("uwb_fwdl_setFwImage failed");
        return UWBAPI_STATUS_FAILED;
    }
#endif // UWBIOT_UWBD_SR1XXT_SR2XXT

    if (false == g_uwb_nxp_is_initialized) {
        if (0 != k_sem_init(&g_uwb_nxp_semaphore, 0, 1)) {
            LOG_ERR("Could not create g_uwb_nxp_semaphore");
            return kUwb_StatusCode_Failed;
        }
        g_uwb_nxp_is_initialized = true;
    }

    status = uwb_api_initialize(pAppCtx->pCallback);

    /* Set the default notification timeout */
    uwbContext.ntfTimeout = DEFAULT_NTF_TIMEOUT_MS;

    // Fira Test mode is enabled
    if (pAppCtx->pTmlCallback != NULL) {
        /* Do HAL call back register only after Uwb Init */
        // HalRegisterAppCallback(pAppCtx->pTmlCallback);
    }

exit:
    LOG_DBG("%s: exit ", __FUNCTION__);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetRegisteredAppCallback(uwb_uci_callback_t **const pAppCallback)
{
    if (NULL == pAppCallback) {
        return kUwb_StatusCode_InvalidArgument;
    }

    /** Assign the function pointer for application callback */
    int ret = uwb_uci_get_registered_callback(pAppCallback);
    if (0 != ret) {
        return UWBAPI_STATUS_FAILED;
    }

    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_RegisterAppCallback(uwb_uci_callback_t *pAppCallback)
{
    if (NULL == pAppCallback) {
        return kUwb_StatusCode_InvalidArgument;
    }

    /** Assign the function pointer for application callback */
    uwbContext.pAppCallback = pAppCallback;

    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_SwitchToMCTTMode(uwb_uci_callback_t *pMcttCb)
{
    // Fira Test mode is enabled
    if (pMcttCb != NULL) {
        /* Do HAL call back register only after Uwb Init */
        int ret = uwb_uci_register_callback(pMcttCb);
        if (0 != ret) {
            LOG_ERR("UCI Register callback failed");
        }
    }
    else {
        return kUwb_StatusCode_InvalidArgument;
    }

    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_ShutDown()
{
    LOG_DBG("%s: Enter", __FUNCTION__);
    /*Cleanup done only once */
    uwb_api_deinitialize();
    return UWBAPI_STATUS_OK;
}

#if !(UWBIOT_UWBD_SR04X)
EXTERNC tUWBAPI_STATUS UwbApi_RecoverUWBS()
{
#if UWBIOT_UWBD_SR1XXT
    phUwbFWImageContext_t fwImageCtx;
    fwImageCtx.fwImage   = (uint8_t *)heliosEncryptedMainlineFwImage;
    fwImageCtx.fwImgSize = sizeof(heliosEncryptedMainlineFwImage);
    fwImageCtx.fwMode    = MAINLINE_FW;
    if (uwb_fwdl_setFwImage(&fwImageCtx) != kUWBSTATUS_SUCCESS) {
        LOG_ERR("uwb_fwdl_setFwImage failed");
        return UWBAPI_STATUS_FAILED;
    }
#endif // UWBIOT_UWBD_SR1XXT
    uwbContext.fwMode = MAINLINE_FW;

    return recoverUWBS();
}

#endif //!(UWBIOT_UWBD_SR04X)

EXTERNC tUWBAPI_STATUS UwbApi_UwbdReset(uint8_t resetConfig)
{
    LOG_DBG("%s: enter", __FUNCTION__);
    if (kUwb_StatusCode_Success == uwb_api_core_device_reset(resetConfig)) {
        return UWBAPI_STATUS_OK;
    }
    return UWBAPI_STATUS_FAILED;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetUwbDevState(uint8_t *pDeviceState)
{
    LOG_DBG("%s: Enter", __FUNCTION__);

    if (pDeviceState == NULL) {
        LOG_ERR("%s: pDeviceState is NULL\n", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    uwb_config_t config = {
        .tag = kUwb_CoreConfig_DeviceState,
        .length = 1,
        .value = pDeviceState,
        .status = 0,
    };

    uwb_status_code_t uwb_status = uwb_api_core_get_config(&config, 1);

    if ((kUwb_StatusCode_Success != uwb_status) || (0 != config.status)) {
        return uwb_status;
    }

    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_SessionInit(uint32_t sessionId, uwb_session_type_t sessionType, uint32_t *sessionHandle)
{
    uwb_status_code_t uwb_status = uwb_api_session_init(sessionId, sessionType, sessionHandle);
    return uwb_status;
}

EXTERNC tUWBAPI_STATUS UwbApi_ConfigureNtfTimeout(uint32_t timeoutMs)
{
    tUWBAPI_STATUS status = UWBAPI_STATUS_OK;
    // Check if UWB stack is initialized

    if(timeoutMs == 0 || timeoutMs == 0xFFFFFFFF){
        LOG_ERR("%s: Invalid timeout value", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }
    uwbContext.ntfTimeout = timeoutMs;
    return status;
}


EXTERNC tUWBAPI_STATUS UwbApi_SessionDeinit(uint32_t sessionHandle)
{
    uwb_status_code_t uwb_status = uwb_api_session_deinit(sessionHandle);
    return uwb_status;
}

EXTERNC tUWBAPI_STATUS UwbApi_SetRangingParams(uint32_t sessionHandle, const phRangingParams_t *pRangingParam)
{
    uint8_t paramLen          = 0;
    uint8_t addrLen           = 0;
    uint8_t noOfRangingParams = 0;
    uint16_t cmdLen           = 0;
    uint8_t payloadOffset     = SES_ID_AND_NO_OF_PARAMS_OFFSET;

    LOG_DBG("%s: enter", __FUNCTION__);


    if (pRangingParam == NULL) {
        LOG_ERR("%s: pRangingParam is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_DEVICE_ROLE,
                                        sizeof(pRangingParam->deviceRole),
                                        (void *)&pRangingParam->deviceRole,
                                        &uwbContext.snd_data[payloadOffset]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_MULTI_NODE_MODE,
                                        sizeof(pRangingParam->multiNodeMode),
                                        (void *)&pRangingParam->multiNodeMode,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_MAC_ADDRESS_MODE,
                                        sizeof(pRangingParam->macAddrMode),
                                        (void *)&pRangingParam->macAddrMode,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count

#if !(UWBIOT_UWBD_SR040) /* As SR048 follows FiRa 2.0 */
    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_SCHEDULED_MODE,
                                        sizeof(pRangingParam->scheduledMode),
                                        (void *)&pRangingParam->scheduledMode,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count
#endif /* !(UWBIOT_UWBD_SR040) */

    if (pRangingParam->macAddrMode == SHORT_MAC_ADDRESS_MODE) {
        addrLen = (uint8_t)SHORT_MAC_ADDR_LEN;
    }
    else{
#if (UWBIOT_UWBD_SR040) /* As SR048 follows FiRa 2.0 */
    if (pRangingParam->macAddrMode == EXTENDED_MAC_ADDRESS_MODE ||
             pRangingParam->macAddrMode == EXTENDED_MAC_ADDRESS_MODE_WITH_HEADER) {

        addrLen = (uint8_t)UWB_EXTENDED_MAC_ADDRESS_LEN;
    }
#endif /* (UWBIOT_UWBD_SR040) */
    }

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_DEVICE_MAC_ADDRESS,
                                        addrLen,
                                        (void *)&pRangingParam->deviceMacAddr,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_RANGING_ROUND_USAGE,
                                        sizeof(pRangingParam->rangingRoundUsage),
                                        (void *)&pRangingParam->rangingRoundUsage,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_DEVICE_TYPE,
                                        sizeof(pRangingParam->deviceType),
                                        (void *)&pRangingParam->deviceType,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfRangingParams, paramLen, uwbContext.snd_data);

    uint8_t session_state = kUwb_SessionStatus_Error;
    uwb_status_code_t status = uwb_api_session_get_state(sessionHandle, &session_state);
    if (status != kUwb_StatusCode_Success) {
        LOG_ERR("Could not get session state");
        return status;
    }
    uint8_t session_status_ntf[10] = {0};
    uint32_t session_status_ntf_len = sizeof(session_status_ntf);
    void *scheduled_ntf = NULL;
    if (kUwb_SessionStatus_Initialized == session_state) {
        /** Need to wait for session status notification */
        scheduled_ntf = uwb_uci_schedule_packet_read(
            UCI_MT_NTF, UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_STATUS_NTF, session_status_ntf,
            &session_status_ntf_len, &g_uwb_nxp_semaphore);
        if (NULL == scheduled_ntf) {
            LOG_ERR("Could not schedule packet read");
            k_sem_reset(&g_uwb_nxp_semaphore);
            return kUwb_StatusCode_Failed;
        }
    }

    uint32_t response_len = sizeof(uwbContext.rsp_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_SET_APP_CONFIG,
                        uwbContext.snd_data, cmdLen, uwbContext.rsp_data, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        if (kUwb_SessionStatus_Initialized == session_state) {
            uwb_uci_remove_scheduled_packet(scheduled_ntf);
            k_sem_reset(&g_uwb_nxp_semaphore);
        }
        return UWBAPI_STATUS_FAILED;
    }

    status = uwbContext.rsp_data[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("SetAppConfig failed");
        if (kUwb_SessionStatus_Initialized == session_state) {
            uwb_uci_remove_scheduled_packet(scheduled_ntf);
            k_sem_reset(&g_uwb_nxp_semaphore);
        }
        return status;
    }

    if (kUwb_SessionStatus_Initialized == session_state) {
        do {
            const k_timeout_t uwb_ntf_timeout = Z_TIMEOUT_MS(UWB_NTF_TIMEOUT);
            if (kUwb_StatusCode_Success != k_sem_take(&g_uwb_nxp_semaphore, uwb_ntf_timeout)) {
                LOG_ERR("Did not receive notification in time");
                status = kUwb_StatusCode_Failed;
                break;
            } else {
                status = kUwb_StatusCode_Success;

                uint32_t ntf_session_handle = 0;
                uint8_t retrieved_session_state = 0;
                uint8_t index = UCI_HEADER_SIZE;
                UWB_STREAM_TO_UINT32(ntf_session_handle, session_status_ntf, index);
                UWB_STREAM_TO_UINT8(retrieved_session_state, session_status_ntf, index);

                if (ntf_session_handle != sessionHandle) {
                    LOG_DBG("Session handle mismatch in notification");
                    status = kUwb_StatusCode_Failed;
                    continue;
                } else if (kUwb_SessionStatus_Idle != retrieved_session_state) {
                    LOG_ERR("Session not in IDLE state");
                    status = kUwb_StatusCode_Failed;
                }
                break;
            }
        } while(true);
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetRangingParams(uint32_t sessionHandle, phRangingParams_t *pRangingParams)
{
    uint8_t *pGetRangingCommand = NULL;
    uint16_t index              = 0;
    uint8_t paramId             = 0;
    uint8_t noOfParams;
    uint16_t cmdLen      = 0;
    uint8_t payloadOffet = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    LOG_DBG("%s: Enter", __FUNCTION__);



    if (pRangingParams == NULL) {
        LOG_ERR("%s: pRangingParams is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    noOfParams         = uciRangingParamIds_len / sizeof(uint8_t);
    pGetRangingCommand = &uwbContext.snd_data[0];
    for (index = 0; index < noOfParams; index++) {
        paramId = uciRangingParamIds[index];
        UWB_UINT8_TO_STREAM(pGetRangingCommand, paramId, payloadOffet);
        LOG_DBG("%s: App ID: %02X", __FUNCTION__, paramId);
    }



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfParams, noOfParams, uwbContext.snd_data);

    uint8_t response[100] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_GET_APP_CONFIG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    tUWBAPI_STATUS status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("GetAppConfig failed");
        return status;
    }

    uint8_t *rspPtr = &response[UCI_HEADER_SIZE + 1];
    parseRangingParams(rspPtr, noOfParams, pRangingParams);

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

#if UWBFTR_CCC
EXTERNC tUWBAPI_STATUS UwbApi_SetCccRangingParams(uint32_t sessionHandle, const phCccRangingParams_t *pCccRangingParam)
{
    tUWBAPI_STATUS status;
    uint8_t paramLen          = 0;
    uint8_t noOfRangingParams = 0;
    uint16_t cmdLen           = 0;
    uint8_t payloadOffset     = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    const k_timeout_t uwb_ntf_timeout  = Z_TIMEOUT_MS(UWB_NTF_TIMEOUT);

    LOG_DBG("%s: enter", __FUNCTION__);


    if (pCccRangingParam == NULL) {
        LOG_ERR("%s: pCccRangingParam is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_DEVICE_TYPE,
                                        sizeof(pCccRangingParam->deviceType),
                                        (void *)&pCccRangingParam->deviceType,
                                        &uwbContext.snd_data[payloadOffset]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_NO_OF_CONTROLEES,
                                        sizeof(pCccRangingParam->noOfControlees),
                                        (void *)&pCccRangingParam->noOfControlees,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_RESPONDER_SLOT_INDEX,
                                        sizeof(pCccRangingParam->responderSlotIndex),
                                        (void *)&pCccRangingParam->responderSlotIndex,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_SLOT_DURATION,
                                        sizeof(pCccRangingParam->slotDuration),
                                        (void *)&pCccRangingParam->slotDuration,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count

    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_HOPPING_MODE,
                                        sizeof(pCccRangingParam->hoppingMode),
                                        (void *)&pCccRangingParam->hoppingMode,
                                        &uwbContext.snd_data[payloadOffset + paramLen]));
    ++noOfRangingParams; // Increment the number of ranging params count



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfRangingParams, paramLen, uwbContext.snd_data);

    uint8_t session_status_ntf[10] = {0};
    uint32_t session_status_ntf_len = sizeof(session_status_ntf);

    void *scheduled_ntf = uwb_uci_schedule_packet_read(
        UCI_MT_NTF, UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_STATUS_NTF, session_status_ntf, &session_status_ntf_len, &g_uwb_nxp_semaphore);
    if (NULL == scheduled_ntf) {
        LOG_ERR("Could not schedule packet read");
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_SET_APP_CONFIG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("Set CccRangingParams failed");
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return status;
    }

    if (kUwb_StatusCode_Success != k_sem_take(&g_uwb_nxp_semaphore, uwb_ntf_timeout)) {
        LOG_ERR("Did not receive notification in time");
        status = UWBAPI_STATUS_FAILED;
    }
    else {
        status = UWBAPI_STATUS_OK;

        uint32_t ntf_session_handle = 0;
        uint8_t *payload = &session_status_ntf[UCI_HEADER_SIZE];
        uint8_t index = 0;
        UWB_STREAM_TO_UINT32(ntf_session_handle, payload, index);

        if (ntf_session_handle != sessionHandle) {
            LOG_ERR("Session handle mismatch in notification");
            status = UWBAPI_STATUS_FAILED;
        }
        else if (UWBAPI_SESSION_IDLE != session_status_ntf[UCI_HEADER_SIZE + index]) {
            LOG_ERR("Session not in initialized state after init");
            status = UWBAPI_STATUS_FAILED;
        }
    }
    uwb_uci_remove_scheduled_packet(scheduled_ntf);
    k_sem_reset(&g_uwb_nxp_semaphore);

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}
#endif // UWBFTR_CCC

EXTERNC tUWBAPI_STATUS UwbApi_SetAppConfig(uint32_t sessionHandle, eAppConfig param_id, uint32_t param_value)
{
    tUWBAPI_STATUS status;
    uint8_t noOfParams    = 1;
    uint8_t paramLen      = 0;
    uint16_t cmdLen       = 0;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    LOG_DBG("%s: enter", __FUNCTION__);

#if !(UWBIOT_UWBD_SR04X)
    if (!(param_id < END_OF_SUPPORTED_APP_CONFIGS)) {
        LOG_WRN("Parameter can not be set using UwbApi_SetAppConfig. Use UwbApi_SetAppConfigMultipleParams");
        return kUwb_StatusCode_InvalidArgument;
    }
    else if ((param_id == STATIC_STS_IV) || (param_id == UWB_INITIATION_TIME)) {
        return kUwb_StatusCode_InvalidArgument;
    }
#elif UWBIOT_UWBD_SR04X
    if (!((param_id >= RANGING_ROUND_USAGE && param_id < END_OF_SUPPORTED_APP_CONFIGS) ||
            ((param_id >> 4) >= EXTENDED_APP_CONFIG_ID && param_id < END_OF_SUPPORTED_EXT_CONFIGS))) {
        return kUwb_StatusCode_InvalidArgument;
    }
    else if (param_id == STATIC_STS_IV) {
        LOG_WRN(
            "STATIC_STS_IV can not be set using UwbApi_SetAppConfig. Use UwbApi_SetAppConfigMultipleParams");
        return kUwb_StatusCode_InvalidArgument;
    }
#endif /* (UWBIOT_UWBD_SR04X) */

    /* TODO: to be removed */
    if (param_id == CHANNEL_NUMBER) {
        uint8_t channel = param_value & 0xff;
        if ((channel != CHANNEL_5) && (channel != CHANNEL_6) && (channel != CHANNEL_8) && (channel != CHANNEL_9)) {
            return kUwb_StatusCode_InvalidArgument;
        }
    }
#if (UWBIOT_UWBD_SR04X)
    if ((param_id >> 4) >= EXTENDED_APP_CONFIG_ID) {
        paramLen = getExtTLVBuffer(param_id, (void *)&param_value, &uwbContext.snd_data[payloadOffset]);
    }
    else
#endif /* (UWBIOT_UWBD_SR04X) */
    {
        paramLen = getAppConfigTLVBuffer(param_id, 0, (void *)&param_value, &uwbContext.snd_data[payloadOffset]);
    }

    if (paramLen == 0) {
        return kUwb_StatusCode_InvalidArgument;
    }



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfParams, paramLen, uwbContext.snd_data);

    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_SET_APP_CONFIG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("SetAppConfig failed");
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

tUWBAPI_STATUS UwbApi_SetAppConfigMultipleParams(
    uint32_t sessionHandle, uint8_t noOfparams, const UWB_AppParams_List_t *AppParams_List)
{
    uint16_t paramLen = 0;
    uint8_t singleParamLen = 0;
    uint16_t cmdLen   = 0;
    eAppConfig paramId;
    tUWBAPI_STATUS status;

    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    LOG_DBG("%s: enter", __FUNCTION__);



    if ((AppParams_List == NULL) || (noOfparams == 0)) {
        LOG_ERR("%s: Parameter value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    for (uint32_t LoopCnt = 0; LoopCnt < noOfparams; ++LoopCnt) {
        void *pParamValue = NULL;
        paramId = AppParams_List[LoopCnt].param_id;
#if !(UWBIOT_UWBD_SR04X)
        if (!(paramId < END_OF_SUPPORTED_APP_CONFIGS)) {
            return kUwb_StatusCode_InvalidArgument;
        }
#elif UWBIOT_UWBD_SR04X
        if (!((paramId >= RANGING_ROUND_USAGE && paramId < END_OF_SUPPORTED_APP_CONFIGS) ||
                ((AppParams_List[LoopCnt].param_id >> 4) >= EXTENDED_APP_CONFIG_ID &&
                    paramId < END_OF_SUPPORTED_EXT_CONFIGS))) {
            return kUwb_StatusCode_InvalidArgument;
        }
#endif /* (UWBIOT_UWBD_SR04X) */

        if(AppParams_List[LoopCnt].param_type == kUWB_APPPARAMS_Type_u32){
            singleParamLen = 4;
            pParamValue = (void *)(&AppParams_List[LoopCnt].param_value.vu32);
        }
        else{
            singleParamLen = AppParams_List[LoopCnt].param_value.au8.param_len;
            pParamValue = (void *)(AppParams_List[LoopCnt].param_value.au8.param_value);
        }

#if !(UWBIOT_UWBD_SR04X)
        if (paramId == MAC_ADDRESS_MODE) {
            /* as pParamValue for MAC_ADDRESS_MODE is vu32 and dereferencing au8 (NULL) */
            uint8_t macMode = *((uint8_t *)pParamValue);
            if (macMode == EXTENDED_MAC_ADDRESS_MODE ||
                    macMode == EXTENDED_MAC_ADDRESS_MODE_WITH_HEADER) {
                LOG_ERR("Extended MAC Mode is not supported");
                return kUwb_StatusCode_InvalidArgument;
            }
        }
#endif // !(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR04X)
        if ((AppParams_List[LoopCnt].param_id >> 4) >= EXTENDED_APP_CONFIG_ID) {
            /* Safe check for array indexing. Coverity issue fix. */
            {
                paramLen = (uint16_t)(paramLen + getExtTLVBuffer(paramId,
                        (void *)(&AppParams_List[LoopCnt].param_value.au8.param_value),
                        &uwbContext.snd_data[payloadOffset + paramLen]));
            }
        }
        else
#endif /* (UWBIOT_UWBD_SR04X) */
        {
            paramLen = (uint16_t)(paramLen + getAppConfigTLVBuffer(
                paramId,
                singleParamLen,
                pParamValue,  // Use the correct pointer
                &uwbContext.snd_data[payloadOffset + paramLen]));

        }
    }

    if (paramLen == 0) {
        return kUwb_StatusCode_InvalidArgument;
    }



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfparams, paramLen, uwbContext.snd_data);

    uint8_t response[100] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_SET_APP_CONFIG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("SetAppConfig failed");
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

#if !(UWBIOT_UWBD_SR04X)
tUWBAPI_STATUS UwbApi_SetVendorAppConfigs(
    uint32_t sessionHandle, uint8_t noOfparams, const UWB_VendorAppParams_List_t *vendorAppParams_List)
{
    uint16_t paramLen = 0;
    uint16_t cmdLen   = 0;
    uint8_t singleParamLen = 0;
    eVendorAppConfig paramId;
    tUWBAPI_STATUS status;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    LOG_DBG("%s: enter", __FUNCTION__);



    if ((vendorAppParams_List == NULL) || (noOfparams == 0)) {
        LOG_ERR("%s: Parameter value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    for (uint32_t LoopCnt = 0; LoopCnt < noOfparams; ++LoopCnt) {
        void *pParamValue = NULL;
        paramId = vendorAppParams_List[LoopCnt].param_id;
        if(vendorAppParams_List[LoopCnt].param_type == kUWB_APPPARAMS_Type_u32){
            singleParamLen = 4;
            pParamValue = (void *)(&vendorAppParams_List[LoopCnt].param_value.vu32);
        }
        else{
            singleParamLen = vendorAppParams_List[LoopCnt].param_value.au8.param_len;
            pParamValue = (void *)(vendorAppParams_List[LoopCnt].param_value.au8.param_value);
        }
#if (UWBFTR_SE_SE051W)
        if (paramId == WRAPPED_RDS) {
            uwbContext.snd_data[paramLen++] = UCI_VENDOR_PARAM_ID_WRAPPED_RDS;
            uwbContext.snd_data[paramLen++] = vendorAppParams_List[LoopCnt].param_value.au8.param_len;
            memcpy(
                &uwbContext.snd_data[paramLen], (void *)(vendorAppParams_List[LoopCnt].param_value.au8.param_value), vendorAppParams_List[LoopCnt].param_value.au8.param_len);
            paramLen += vendorAppParams_List[LoopCnt].param_value.au8.param_len;
        }
        else
#endif // UWBFTR_SE_SE051W
        {
            paramLen = (uint16_t)(paramLen + getVendorAppConfigTLVBuffer(paramId,
                                                 pParamValue,
                                                 singleParamLen,
                                                 &uwbContext.snd_data[payloadOffset + paramLen]));
        }
    }

    if (paramLen == 0) {
        return kUwb_StatusCode_InvalidArgument;
    }



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfparams, paramLen, uwbContext.snd_data);



    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SET_VENDOR_APP_CONFIG_CMD,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("Set VendorAppConfigs failed");
        return status;
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}
#endif //!(UWBIOT_UWBD_SR04X)

EXTERNC tUWBAPI_STATUS UwbApi_GetAppConfig(uint32_t sessionHandle, eAppConfig param_id, uint32_t *param_value)
{
    if(param_value == NULL){
        return kUwb_StatusCode_InvalidArgument;
    }
    uwb_config_t config = {
        .tag = param_id,
        .length = 4,
        .value = (uint8_t *)param_value,
        .status = 0,
    };
    uwb_status_code_t uwb_status = uwb_api_get_app_configs(sessionHandle, &config, 1);
    if (kUwb_StatusCode_Success != uwb_status) {
        return uwb_status;
    }
    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetAppConfigMultipleParams(
    uint32_t sessionHandle, uint8_t noOfparams, UWB_AppParams_List_t *AppParams_List)
{
    eAppConfig paramId;
    uint8_t i = 0;
    if ((AppParams_List == NULL) || (noOfparams == 0)) {
        LOG_ERR("%s: Parameter value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    for (i = 0; i < noOfparams; i++) {
        paramId = AppParams_List[i].param_id;
        if (!(paramId >= RANGING_ROUND_USAGE && paramId < END_OF_SUPPORTED_APP_CONFIGS)) {
            return kUwb_StatusCode_InvalidArgument;
        }
    }
    // Allocate array of uwb_config_t structures
    uwb_config_t *configs = (uwb_config_t *)k_malloc(noOfparams * sizeof(uwb_config_t));
    if (configs == NULL) {
        LOG_ERR("%s: Memory allocation failed", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }
    for(uint8_t data = 0; data < noOfparams; data ++){
        configs[data].tag = AppParams_List[data].param_id;
        if (AppParams_List[data].param_type == kUWB_APPPARAMS_Type_au8) {
            configs[data].length = AppParams_List[data].param_value.au8.param_len;
            configs[data].value  = AppParams_List[data].param_value.au8.param_value;
        } else {
            configs[data].length = 4;
            configs[data].value  = (uint8_t *)&AppParams_List[data].param_value.vu32;
        }
        configs[data].status = 0;
    }
    uwb_status_code_t uwb_status = uwb_api_get_app_configs(sessionHandle, configs, noOfparams);

    // Free allocated memory
    k_free(configs);

    if (kUwb_StatusCode_Success != uwb_status) {
        return uwb_status;
    }
    return UWBAPI_STATUS_OK;
}

#if !(UWBIOT_UWBD_SR04X)

tUWBAPI_STATUS UwbApi_GetVendorAppConfigs(
    uint32_t sessionHandle, uint8_t noOfparams, UWB_VendorAppParams_List_t *vendorAppParams_List)
{
    tUWBAPI_STATUS status;
    uint8_t i = 0;
    eVendorAppConfig paramId;
    uint8_t *pConfigCommand = NULL;
    uint8_t payloadOffset   = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    uint16_t cmdLen         = 0;
    uint16_t offset          = 0;
    uint8_t *rspPtr         = NULL;
    uint16_t len            = 0;

    LOG_DBG("%s: enter", __FUNCTION__);


    if ((vendorAppParams_List == NULL) || (noOfparams == 0)) {
        LOG_ERR("%s: Parameter value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    pConfigCommand = &uwbContext.snd_data[payloadOffset];
    for (i = 0; i < noOfparams; i++) {
        paramId = vendorAppParams_List[i].param_id;

        // TODO: Add check to validate given vendor param is in list or not
        pConfigCommand[cmdLen++] = (uint8_t)(paramId & 0xFF);
    }
    // TODO: wait for GET_VENDOR_APP_CONFIG_RSP


    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfparams, cmdLen, uwbContext.snd_data);

    uint8_t response[200] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_GET_VENDOR_APP_CONFIG_CMD,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];

    if (status == UWBAPI_STATUS_OK) {
        rspPtr = &response[UCI_HEADER_SIZE + 2]; /*Skip status and no_of_params*/
        for (i = 0; i < noOfparams; i++) {
            if (offset < (UINT8_MAX - 1)) {
                offset++;
            }
            else {
                LOG_ERR("%s: Offset overflow. offset=%u", __FUNCTION__, offset);
                return UWBAPI_STATUS_FAILED;
            }

            /* Validate we can read length field */
            if (offset >= sizeof(uwbContext.rsp_data)) {
                LOG_ERR("%s: Cannot read length at offset %d", __FUNCTION__, offset);
                status = UWBAPI_STATUS_BUFFER_OVERFLOW;
                break;
            }

            UWB_STREAM_TO_UINT8(len, rspPtr, offset);

            /* Validate length won't cause overrun */
            if ((len > sizeof(uwbContext.rsp_data)) || ((offset + len) > sizeof(uwbContext.rsp_data))) {
                LOG_ERR("%s: Invalid len=%d at offset=%d", __FUNCTION__, len, offset);
                status = UWBAPI_STATUS_BUFFER_OVERFLOW;
                break;
            }
            if (vendorAppParams_List[i].param_type == kUWB_APPPARAMS_Type_u32) {
                if (len == sizeof(uint8_t)) {
                    UWB_STREAM_TO_UINT8(vendorAppParams_List[i].param_value.vu32, rspPtr, offset);
                }
                else if (len == sizeof(uint16_t)) {
                    UWB_STREAM_TO_UINT16(vendorAppParams_List[i].param_value.vu32, rspPtr, offset);
                }
                else if (len == sizeof(uint32_t)) {
                    UWB_STREAM_TO_UINT32(vendorAppParams_List[i].param_value.vu32, rspPtr, offset);
                }
            }
            else if (vendorAppParams_List[i].param_type == kUWB_APPPARAMS_Type_au8) {
                if (vendorAppParams_List[i].param_value.au8.param_len >= len) {
                    UWB_STREAM_TO_ARRAY(vendorAppParams_List[i].param_value.au8.param_value, rspPtr, len, offset);
                }
                else {
                    LOG_ERR("%s: Not enough buffer to store app config value", __FUNCTION__);
                    status = UWBAPI_STATUS_BUFFER_OVERFLOW;
                    break;
                }
                vendorAppParams_List[i].param_value.au8.param_len = len;
            }
        }
    }
    return status;
}
#endif //!(UWBIOT_UWBD_SR04X)

EXTERNC tUWBAPI_STATUS UwbApi_SetStaticSts(uint32_t sessionHandle, uint16_t vendorId, uint8_t const *const staticStsIv)
{
    tUWBAPI_STATUS status;
    uint8_t noOfParams    = 0;
    uint8_t paramLen      = 0;
    uint16_t cmdLen       = 0;
    size_t appConfigDataLen = 0;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    LOG_DBG("%s: enter", __FUNCTION__);


    if (staticStsIv == NULL) {
        LOG_ERR("%s: Static Sts Iv is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    paramLen = getAppConfigTLVBuffer(
        UCI_PARAM_ID_VENDOR_ID, UCI_PARAM_LEN_VENDOR_ID, (void *)&vendorId, &uwbContext.snd_data[payloadOffset]);

    ++noOfParams; // Increment the number of params count

    appConfigDataLen = getAppConfigTLVBuffer(UCI_PARAM_ID_STATIC_STS_IV,
        UCI_PARAM_LEN_STATIC_STS_IV,
        (void *)staticStsIv,
        &uwbContext.snd_data[payloadOffset + paramLen]);
    if (paramLen < (UINT8_MAX - appConfigDataLen)) {
        paramLen = (uint8_t)(paramLen + appConfigDataLen);
    }
    else {
        LOG_ERR("%s: Parameter length overflow. paramLen=%u", __FUNCTION__, paramLen);
        return UWBAPI_STATUS_FAILED;
    }

    ++noOfParams; // Increment the number of params count



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfParams, paramLen, uwbContext.snd_data);

    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_SET_APP_CONFIG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_SetDeviceConfig(
    eDeviceConfig param_id, uint8_t param_len, phDeviceConfigData_t *param_value)
{
    uint8_t offset = 1;
    tUWBAPI_STATUS status;
#if (UWBIOT_UWBD_SR04X)
    uint8_t ext_param_id = 0;
#endif

    LOG_DBG("%s: enter", __FUNCTION__);


    if (param_value == NULL || param_len == 0) {
        LOG_ERR("%s: Parameter value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

#if !(UWBIOT_UWBD_SR04X)
    if (((param_id >> 8) & 0xFF) == EXTENDED_DEVICE_CONFIG_ID) {
        offset = getExtCoreDeviceConfigTLVBuffer(param_id, param_len, param_value, &uwbContext.snd_data[offset]);
    }
    else {
        offset = getCoreDeviceConfigTLVBuffer(param_id, param_len, param_value, &uwbContext.snd_data[offset]);
    }
#endif // !(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR04X)
    ext_param_id = (uint8_t)(param_id >> 4);
    /* Checking for the second Nibble */
    if (ext_param_id >= EXTENDED_DEVICE_CONFIG_ID) {
        /*No Mapping need */
        offset =
            getExtCoreDeviceConfigTLVBuffer(param_id, param_len, (void *)param_value, &uwbContext.snd_data[offset]);
    }
    else {
        /*No Mapping need */
        offset = getCoreDeviceConfigTLVBuffer(param_id, param_len, param_value, &uwbContext.snd_data[offset]);
    }
#endif /* (UWBIOT_UWBD_SR04X) */

    if (offset == 0) {
        LOG_ERR("%s: offset is zero for getCoreDeviceConfigTLVBuffer", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }


    uwbContext.snd_data[0] = 1;

    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_CORE, UCI_MSG_CORE_SET_CONFIG,
                        uwbContext.snd_data, (offset + 1), response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetDeviceConfig(eDeviceConfig param_id, phDeviceConfigData_t *devConfig)
{
    uint8_t noOfParams = 1;
    uint8_t paramLen   = 1;
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;

    LOG_DBG("%s: enter", __FUNCTION__);


    if (devConfig == NULL) {
        LOG_ERR("%s: param_value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

#if !(UWBIOT_UWBD_SR040)
    if ((uint8_t)(param_id >> 8) == EXTENDED_DEVICE_CONFIG_ID) {
        paramLen++;
        param_id = (eDeviceConfig)((param_id >> 8) | (param_id << 8));
    }
#endif // !(UWBIOT_UWBD_SR04X)

    cmdLen = uwb_serialize_get_core_config_payload(noOfParams, paramLen, (uint8_t *)&param_id, uwbContext.snd_data);

    uint8_t *response = uwbContext.rsp_data;
    uint32_t response_len = sizeof(uwbContext.rsp_data);

    memset(uwbContext.rsp_data, 0x00, sizeof(uwbContext.rsp_data));

    int ret = uwb_uci_transceive_control_packet(UCI_GID_CORE, UCI_MSG_CORE_GET_CONFIG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];

    if (status == UWBAPI_STATUS_OK) {
#if !(UWBIOT_UWBD_SR04X)
/* Skipping the first two bytes of response payload (status and no_of_params)*/
        if ((uint8_t)param_id == EXTENDED_DEVICE_CONFIG_ID) {
            parseExtGetDeviceConfigResponse(&response[UCI_HEADER_SIZE + 2], devConfig);
        }
        else {
            parseCoreGetDeviceConfigResponse(&response[UCI_HEADER_SIZE + 2], devConfig);
        }
#endif // !(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR04X)
        if ((uint8_t)(param_id >> 4) >= EXTENDED_DEVICE_CONFIG_ID) {
            parseExtGetDeviceConfigResponse(&response[UCI_HEADER_SIZE + 2], devConfig);
        }
        else {
            parseCoreGetDeviceConfigResponse(&response[UCI_HEADER_SIZE + 2], devConfig);
        }
#endif /* (UWBIOT_UWBD_SR04X) */
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_StartRangingSession(uint32_t sessionHandle)
{
    return uwb_api_session_start(sessionHandle);
}

EXTERNC tUWBAPI_STATUS UwbApi_StopRangingSession(uint32_t sessionHandle)
{
    tUWBAPI_STATUS status = (tUWBAPI_STATUS) uwb_api_session_stop(sessionHandle);

#if UWBIOT_UWBD_SR040
    /* Wait for 1 more NTF, 6001000101.
     * Else there's Writer thread takes mutex of IO interface and read will always be pending, and write will always
     * fail. Cleaner handling would be to ensure writer thread is able to unblock reader thread.
     */
    k_msleep(10);
#endif
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_EnableRangingDataNtf(
    uint32_t sessionHandle, uint8_t enableRangingDataNtf, uint16_t proximityNear, uint16_t proximityFar)
{
    uint8_t noOfParam     = 1;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    uint8_t paramLen      = 0;
    uint16_t cmdLen       = 0;
    tUWBAPI_STATUS status;
    LOG_DBG("%s: enter", __FUNCTION__);


    if (enableRangingDataNtf > 2) {
        return kUwb_StatusCode_InvalidArgument;
    }
    paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_SESSION_INFO_NTF,
                                        UCI_PARAM_LEN_SESSION_INFO_NTF,
                                        &enableRangingDataNtf,
                                        &uwbContext.snd_data[payloadOffset]));

    if (enableRangingDataNtf == 2) {
        noOfParam = (uint8_t)(noOfParam + 2);
        paramLen  = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_NEAR_PROXIMITY_CONFIG,
                                            UCI_PARAM_LEN_NEAR_PROXIMITY_CONFIG,
                                            &proximityNear,
                                            &uwbContext.snd_data[payloadOffset + paramLen]));

        paramLen = (uint8_t)(paramLen + getAppConfigTLVBuffer(UCI_PARAM_ID_FAR_PROXIMITY_CONFIG,
                                            UCI_PARAM_LEN_FAR_PROXIMITY_CONFIG,
                                            &proximityFar,
                                            &uwbContext.snd_data[payloadOffset + paramLen]));
    }



    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfParam, paramLen, uwbContext.snd_data);

    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_SET_APP_CONFIG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("Enable Ranging Data Ntf failed");
        return status;
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_SendRawCommand(uint8_t data[], uint16_t data_len, uint8_t *pResp, uint16_t *pRespLen)
{

    if (pResp == NULL || pRespLen == NULL) {
        LOG_ERR("%s: pResp or pRespLen data is invalid", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    uint32_t response_len = *pRespLen;
    if (UWBAPI_STATUS_OK != sendRawUci2(data, data_len, pResp, &response_len))
    {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    *pRespLen = (uint16_t) response_len;
    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetSessionState(uint32_t sessionHandle, uint8_t *sessionState)
{
    uwb_status_code_t uwb_status = uwb_api_session_get_state(sessionHandle, sessionState);
    if (kUwb_StatusCode_Success != uwb_status) {
        return uwb_status;
    }
    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_UpdateControllerMulticastList(phMulticastControleeListContext_t *pControleeContext,
    phMulticastControleeListRspContext_t *pControleeListRspContext)
{

    if ((pControleeContext == NULL) || (NULL == pControleeListRspContext)) {
        LOG_ERR("%s: pControleeContext is 0x%p and pControleeListRspContext is 0x%p",
            __FUNCTION__, pControleeContext, pControleeListRspContext);
        return kUwb_StatusCode_InvalidArgument;
    }

    if (pControleeContext->action == MULTICAST_LIST_DEL_CONTROLEE) {
        for (uint8_t i = 0; i < pControleeContext->no_of_controlees; i++) {
            if (pControleeContext->controlee_list[i].subsession_id != 0x0) {
                return kUwb_StatusCode_InvalidArgument; // for deletion, sub Session Handle must be zero
            }
        }
    }

    uwb_multicast_controlee_list_context_t *controlee_list = (uwb_multicast_controlee_list_context_t *)k_malloc(pControleeContext->no_of_controlees * sizeof(uwb_multicast_controlee_list_context_t));
    if (NULL == controlee_list) {
        LOG_ERR("Could not allocate memory");
        return UWBAPI_STATUS_FAILED;
    }

    for (uint8_t controlee_index = 0; controlee_index < pControleeContext->no_of_controlees; controlee_index++) {
        controlee_list[controlee_index].short_address = pControleeContext->controlee_list[controlee_index].short_address;
        controlee_list[controlee_index].subsession_id = pControleeContext->controlee_list[controlee_index].subsession_id;
        memcpy(controlee_list[controlee_index].subsession_key, pControleeContext->controlee_list[controlee_index].subsession_key, sizeof(controlee_list[controlee_index].subsession_key));
        controlee_list[controlee_index].status = 0;
    }
    uwb_status_code_t uwb_status = uwb_api_update_controller_multicast_list(
        pControleeContext->sessionHandle,
        pControleeContext->action,
        controlee_list,
        pControleeContext->no_of_controlees);

    uint8_t failed_controlees = 0;

    for (uint8_t controlee_index = 0; controlee_index < pControleeContext->no_of_controlees; controlee_index++) {
        if (kUci_Status_Ok != controlee_list[controlee_index].status) {
#if UWBIOT_UWBD_SR1XXT_SR2XXT
            pControleeListRspContext->controleeStatusList[failed_controlees].controlee_mac_address = controlee_list[controlee_index].short_address;
#endif /** UWBIOT_UWBD_SR1XXT_SR2XXT */
            pControleeListRspContext->controleeStatusList[failed_controlees++].status = controlee_list[controlee_index].status;
        }
    }

    pControleeListRspContext->status = uwb_status;
    pControleeListRspContext->no_of_controlees = failed_controlees;

    k_free(controlee_list);
    if (kUwb_StatusCode_Success != uwb_status) {
        return uwb_status;
    }
    return UWBAPI_STATUS_OK;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetTrng(uint8_t trng_size, uint8_t *ptrng)
{
    tUWBAPI_STATUS status;
    uint8_t *pResponse = NULL;
    uint16_t cmdLen;
    uint32_t index = 0;
    LOG_DBG("%s: Enter", __FUNCTION__);

    if (ptrng == NULL) {
        LOG_ERR("%s: trng data is invalid", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }
    if (trng_size > MAX_TRNG_SIZE || trng_size < MIN_TRNG_SIZE) {
        LOG_ERR("%s: Trng size  is invalid it should be Between 0x01-0x10 ", __FUNCTION__);
        return UWBAPI_STATUS_INVALID_RANGE;
    }

    cmdLen = serializeTrngtPayload(trng_size, uwbContext.snd_data);

    uint8_t response[UCI_HEADER_SIZE + MAX_TRNG_SIZE + 1];
    uint32_t response_len = sizeof(response);
#if UWBIOT_UWBD_SR04X
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY, EXT_UCI_MSG_GET_TRNG_SR040,
                        uwbContext.snd_data, cmdLen, response, &response_len);
#else
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY, EXT_UCI_MSG_GET_TRNG,
                        uwbContext.snd_data, cmdLen, response, &response_len);
#endif /** UWBIOT_UWBD_SR04X */
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("Get Trng failed");
        return status;
    }

    pResponse = &response[UCI_HEADER_SIZE + 1]; // Response
    /* Fetch the TRNG bytes */
    UWB_STREAM_TO_ARRAY(ptrng, pResponse, trng_size, index);

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

#if (UWBFTR_BlobParser)
EXTERNC tUWBAPI_STATUS UwbApi_SetProfileParams(
    uint8_t *pProfileBlob, uint16_t blobSize, phUwbProfileInfo_t *pProfileInfo)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen;
    const k_timeout_t uwb_ntf_timeout  = Z_TIMEOUT_MS(UWB_NTF_TIMEOUT);

    LOG_DBG("%s: Enter", __FUNCTION__);



    if (pProfileBlob == NULL) {
        LOG_ERR("%s: profile blob buffer is invalid", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    if (pProfileInfo == NULL) {
        LOG_ERR("%s: profile info is invalid", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    if ((blobSize != TOTAL_PROFILE_BLOB_SIZE_v1_1) && (blobSize != TOTAL_PROFILE_BLOB_SIZE_v1_0)) {
        LOG_ERR("%s: profile blob size should be %d or %d bytes",
            __FUNCTION__,
            TOTAL_PROFILE_BLOB_SIZE_v1_0,
            TOTAL_PROFILE_BLOB_SIZE_v1_1);
        return kUwb_StatusCode_InvalidArgument;
    }



    cmdLen = serializeSetProfileParamsPayload(pProfileInfo, blobSize, pProfileBlob, uwbContext.snd_data);

    uint8_t session_status_ntf[10] = {0};
    uint32_t session_status_ntf_len = sizeof(session_status_ntf);

    void *scheduled_ntf = uwb_uci_schedule_packet_read(
        UCI_MT_NTF, UCI_GID_SESSION_MANAGE, UCI_MSG_SESSION_STATUS_NTF, session_status_ntf, &session_status_ntf_len, &g_uwb_nxp_semaphore);
    if (NULL == scheduled_ntf) {
        LOG_ERR("Could not schedule packet read");
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY, EXT_UCI_MSG_SET_PROFILE,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("Set Profile Params failed");
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return status;
    }

#if !(UWBIOT_UWBD_SR04X)
    /* set the sessionHandle received from the PROP_SET_PROFILE_CMD */
    if ((response_len > (UCI_HEADER_SIZE + SESSION_HANDLE_OFFSET)) && (response_len <= (UCI_HEADER_SIZE + SESSION_HANDLE_OFFSET_LEN)))
    {
        uint8_t *rspPtr = &response[UCI_HEADER_SIZE];
        uint32_t index = 0; // Declaration has to be here as the code is under feature macro
        // skip the status from response.
        index++;
        // copy the Session Handle received through response.
        UWB_STREAM_TO_UINT32(pProfileInfo->sessionHandle, rspPtr, index);
    }
#endif // !(UWBIOT_UWBD_SR04X)

    if (kUwb_StatusCode_Success != k_sem_take(&g_uwb_nxp_semaphore, uwb_ntf_timeout)) {
        LOG_ERR("Did not receive notification in time");
        status = UWBAPI_STATUS_FAILED;
    }
    else {
        status = UWBAPI_STATUS_OK;

        uint32_t ntf_session_handle = 0;
        uint8_t *payload = &session_status_ntf[UCI_HEADER_SIZE];
        uint32_t index = 0;
        UWB_STREAM_TO_UINT32(ntf_session_handle, payload, index);
        uint8_t session_state = session_status_ntf[UCI_HEADER_SIZE + index];

        if (ntf_session_handle != pProfileInfo->sessionHandle) {
            LOG_ERR("Session handle mismatch in notification");
            status = UWBAPI_STATUS_FAILED;
        }
        else if (UWBAPI_SESSION_IDLE != session_state) {
            LOG_ERR("Session not in initialized state after init");
            status = UWBAPI_STATUS_FAILED;
        }
    }
    uwb_uci_remove_scheduled_packet(scheduled_ntf);
    k_sem_reset(&g_uwb_nxp_semaphore);

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

tUWBAPI_STATUS UwbApi_GetUwbConfigData_iOS(
    UWB_DeviceRole_t device_role, AccessoryUwbConfigDataContent_t *uwb_data_content)
{
    tUWBAPI_STATUS status;
    static phUwbDevInfo_t devInfo    = {0};
    uint8_t uwb_spec_version_major[] = UWB_IOS_SPEC_VERSION_MAJOR;
    uint8_t uwb_spec_version_minor[] = UWB_IOS_SPEC_VERSION_MINOR;
    uint8_t manufacturer_id[]        = MANUFACTURER_ID;
#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    uint16_t readMMId;
#endif //(UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

    phUwbSessionData_t sessionData[MAXIMUM_SESSION_COUNT] = {0};
    phUwbSessionsContext_t uwbSessionsContext             = {0};
    uwbSessionsContext.sessioncnt                         = 5;
    uwbSessionsContext.pUwbSessionData                    = sessionData;
    uwbSessionsContext.status                             = 0;

    LOG_DBG("%s: enter", __FUNCTION__);



    if (uwb_data_content == NULL) {
        LOG_ERR("%s: uwb_data_content is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    if ((uwb_spec_version_minor[0] == 0x00) && (uwb_spec_version_minor[1] == 0x00)) {
        LOG_DBG(" Following spec 1.0");
        uwb_data_content->length =
            sizeof(AccessoryUwbConfigDataContent_t) - 1 - 2 /* clock drift not sent in spec 1.0 */;
    }
    else if ((uwb_spec_version_minor[0] == 0x01) && (uwb_spec_version_minor[1] == 0x00)) {
        LOG_DBG(" Following spec 1.1");
        uwb_data_content->length = sizeof(AccessoryUwbConfigDataContent_t) - 1;
    }
    else {
        LOG_DBG(" Unknown Spec");
        uwb_data_content->length = 0;
    }

    /* Generate mac address */
    status = UwbApi_GetTrng(SHORT_MAC_ADDR_LEN, uwb_data_content->device_mac_addr);

    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_GetTrng() Failed");
        goto exit;
    }

    /* Fill in UWB spec version */
    memcpy(uwb_data_content->uwb_spec_ver_major, uwb_spec_version_major, sizeof(uwb_spec_version_major));
    memcpy(uwb_data_content->uwb_spec_ver_minor, uwb_spec_version_minor, sizeof(uwb_spec_version_minor));

    /* Get info of all UWBsessions */
    status = UwbApi_GetAllUwbSessions(&uwbSessionsContext);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_GetAllUwbSessions Failed");
        goto exit;
    }
    /* check if there is no session present, then only call UwbApi_GetDeviceInfo() */
    if (uwbSessionsContext.sessioncnt == 0) {
        status = UwbApi_GetDeviceInfo(&devInfo);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_GetDeviceInfo failed");
            goto exit;
        }
    }
    /* Fill in the MW version*/
    uwb_data_content->mw_version[3] = devInfo.mwMajor;
    uwb_data_content->mw_version[2] = devInfo.mwMinor;
    /* First two bytes are zero default */
    uwb_data_content->mw_version[1] = 0;
    uwb_data_content->mw_version[0] = 0;
    /* Fill in the Device Model ID */
    uwb_data_content->model_id[0] = devInfo.fwMajor;

#if UWBIOT_UWBD_SR150
    /* Check the chip type */
    if (memcmp(devInfo.devName, "SR150_PROD_IOT_ROW", devInfo.devNameLen) != 0) {
        uwb_data_content->model_id[1] = 0xFF;
    }
    else {
        uwb_data_content->model_id[1] = MODELID_CHIP_TYPE;
    }
#elif UWBIOT_UWBD_SR040 /* TODO: SR048 - Needs an update? */
    /* Check the chip type */
    if (memcmp(devInfo.devName, "SR040", 5) != 0) {
        uwb_data_content->model_id[1] = 0xFF;
    }
    else {
        uwb_data_content->model_id[1] = MODELID_CHIP_TYPE;
    }
#elif UWBIOT_UWBD_SR250
    /* Check the chip type */
    if (memcmp(devInfo.devName, "SR250_A1V2_PROD", devInfo.devNameLen) != 0) {
        uwb_data_content->model_id[1] = 0xFF;
    }
    else {
        uwb_data_content->model_id[1] = MODELID_CHIP_TYPE;
    }
#endif // UWBIOT_UWBD_SR250
    /* Fill in the Manufacturer Version */
    memcpy(uwb_data_content->manufacturer_id, manufacturer_id, sizeof(manufacturer_id));

    /* Fill in the device role */
    uwb_data_content->ranging_role = device_role;

    if ((uwb_spec_version_minor[0] == 0x01) && (uwb_spec_version_minor[1] == 0x00)) {
        /* Fill in the clock drift value */
        uwb_data_content->clock_drift[0] = CLOCK_DRIFT;
        uwb_data_content->clock_drift[1] = (CLOCK_DRIFT >> 8);
    }

#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    status = UwbApi_ReadModuleMakerInfo(&readMMId);
    UWB_UINT16_TO_FIELD(&uwb_data_content->model_id[2], readMMId);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_ReadModuleMakerInfo Failed");
        goto exit;
    }
#elif UWBIOT_UWBD_SR04X
    uwb_data_content->model_id[2] = MODELID_BOARD_TYPE;
    uwb_data_content->model_id[3] = MODELID_RFU;
#endif /* (UWBIOT_UWBD_SR04X) */

exit:
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

tUWBAPI_STATUS UwbApi_GetUwbConfigData_Android(UwbDeviceConfigData_t *uwb_data_content)
{
    tUWBAPI_STATUS status;
    static phUwbDevInfo_t devInfo    = {0};
    phUwbSessionData_t sessionData[MAXIMUM_SESSION_COUNT] = {0};
    phUwbSessionsContext_t uwbSessionsContext             = {0};
    uwbSessionsContext.sessioncnt                         = 5;
    uwbSessionsContext.pUwbSessionData                    = sessionData;
    uwbSessionsContext.status                             = 0;

    LOG_DBG("%s: enter", __FUNCTION__);



    if (uwb_data_content == NULL) {
        LOG_ERR("%s: uwb_data_content is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }
#if (UWBIOT_UWBD_SR04X)
    uint32_t sessionHandle = 0;
    if(uwb_data_content->isFindhubEnabled  == false){
        uint8_t uwb_spec_version_major[] = UWB_ANDROID_SPEC_VERSION_MAJOR;
        uint8_t uwb_spec_version_minor[] = UWB_ANDROID_SPEC_VERSION_MINOR;

        /* Fill in UWB spec version */
        memcpy(uwb_data_content->spec_ver_major, uwb_spec_version_major, sizeof(uwb_spec_version_major));
        memcpy(uwb_data_content->spec_ver_minor, uwb_spec_version_minor, sizeof(uwb_spec_version_minor));

        /* Get info of all UWBsessions */
        status = UwbApi_GetAllUwbSessions(&uwbSessionsContext);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_GetAllUwbSessions Failed");
            goto exit;
        }
        /* check if there is no session present, then only call UwbApi_GetDeviceInfo() */
        if (uwbSessionsContext.sessioncnt == 0) {
            status = UwbApi_GetDeviceInfo(&devInfo);
            if (status != UWBAPI_STATUS_OK) {
                LOG_ERR("UwbApi_GetDeviceInfo failed");
                goto exit;
            }
        }
        /* Fill in UWB chip FW version */
        uwb_data_content->chip_fw_version[0] = devInfo.fwMajor;
        uwb_data_content->chip_fw_version[1] = devInfo.fwMinor;

        /* Fill in the MW version */
        uwb_data_content->mw_version[0] = devInfo.mwMajor;
        uwb_data_content->mw_version[1] = devInfo.mwMinor;
        uwb_data_content->mw_version[2] = 0x00;

    #if UWBIOT_UWBD_SR150
        /* Check the chip type */
        if (memcmp(devInfo.devName, "SR150_PROD_IOT_ROW", devInfo.devNameLen) != 0) {
            uwb_data_content->chip_id[1] = 0xFF;
        }
        else {
            uwb_data_content->chip_id[1] = MODELID_CHIP_TYPE;
        }
    #elif UWBIOT_UWBD_SR040 /* TODO: SR048 - Needs an update? */
        /* Check the chip type */
        if (memcmp(devInfo.devName, "SR040", 5) != 0) {
            uwb_data_content->chip_id[1] = 0xFF;
        }
        else {
            uwb_data_content->chip_id[1] = MODELID_CHIP_TYPE;
        }
    #elif UWBIOT_UWBD_SR250
        /* Check the chip type */
        if (memcmp(devInfo.devName, "SR250_A1V2_PROD", devInfo.devNameLen) != 0) {
            uwb_data_content->chip_id[1] = 0xFF;
        }
        else {
            uwb_data_content->chip_id[1] = MODELID_CHIP_TYPE;
        }
    #endif // UWBIOT_UWBD_SR250
        /* Fill in supported UWB profile Ids */
        uwb_data_content->supported_config_ids = UWB_SUPPORTED_CONFIG_IDS;
    }
    else{
        /* Fill in supported UWB profile Ids */
        uwb_data_content->supported_config_ids = UWB_SUPPORTED_CONFIG_IDS_FIND_HUB;
        uwb_data_content->ranging_technology_role = RANGING_TECHNOLOGY_UWB;
        status = UwbApi_SessionInit(0x11223344, kUwb_SessionType_Ranging, &sessionHandle);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_SessionInit() Failed");
            goto exit;
        }
        UWB_AppParams_List_t GetAppParamsList[] = {
            UWB_SET_GETAPP_PARAM(RANGING_DURATION),
            UWB_SET_GETAPP_PARAM(SLOT_DURATION),
            UWB_SET_GETAPP_PARAM(CHANNEL_NUMBER),
            UWB_SET_GETAPP_PARAM(PREAMBLE_CODE_INDEX),
        };

        status = UwbApi_GetAppConfigMultipleParams(sessionHandle,
            sizeof(GetAppParamsList) / sizeof(GetAppParamsList[0]),
            &GetAppParamsList[0]);
            if (status != UWBAPI_STATUS_OK) {
                LOG_ERR("UwbApi_SessionInit() Failed");
                goto exit;
            }
        uwb_data_content->ranging_interval = (uint16_t)GetAppParamsList[0].param_value.vu32;
        uwb_data_content->slot_duration = GetAppParamsList[1].param_value.vu32/1200;
        uwb_data_content->supported_channels = SET_SUPPORTED_CHANNEL(GetAppParamsList[2].param_value.vu32);
        uwb_data_content->preamble_index     = SET_PREAMBLE_INDEX(GetAppParamsList[3].param_value.vu32);
        uwb_data_content->payload_size = RANGING_CAP_RESPONSE_LENGTH_ANDROID;
        status = UwbApi_SessionDeinit(sessionHandle);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_SessionInit() Failed");
            goto exit;
        }
    }
#else
        uint8_t uwb_spec_version_major[] = UWB_ANDROID_SPEC_VERSION_MAJOR;
        uint8_t uwb_spec_version_minor[] = UWB_ANDROID_SPEC_VERSION_MINOR;

        /* Fill in UWB spec version */
        memcpy(uwb_data_content->spec_ver_major, uwb_spec_version_major, sizeof(uwb_spec_version_major));
        memcpy(uwb_data_content->spec_ver_minor, uwb_spec_version_minor, sizeof(uwb_spec_version_minor));

        /* Get info of all UWBsessions */
        status = UwbApi_GetAllUwbSessions(&uwbSessionsContext);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_GetAllUwbSessions Failed");
            goto exit;
        }
        /* check if there is no session present, then only call UwbApi_GetDeviceInfo() */
        if (uwbSessionsContext.sessioncnt == 0) {
            status = UwbApi_GetDeviceInfo(&devInfo);
            if (status != UWBAPI_STATUS_OK) {
                LOG_ERR("UwbApi_GetDeviceInfo failed");
                goto exit;
            }
        }
        /* Fill in UWB chip FW version */
        uwb_data_content->chip_fw_version[0] = devInfo.fwMajor;
        uwb_data_content->chip_fw_version[1] = devInfo.fwMinor;

        /* Fill in the MW version */
        uwb_data_content->mw_version[0] = devInfo.mwMajor;
        uwb_data_content->mw_version[1] = devInfo.mwMinor;
        uwb_data_content->mw_version[2] = 0x00;

    #if UWBIOT_UWBD_SR150
        /* Check the chip type */
        if (memcmp(devInfo.devName, "SR150_PROD_IOT_ROW", devInfo.devNameLen) != 0) {
            uwb_data_content->chip_id[1] = 0xFF;
        }
        else {
            uwb_data_content->chip_id[1] = MODELID_CHIP_TYPE;
        }
    #elif UWBIOT_UWBD_SR040 /* TODO: SR048 - Needs an update? */
        /* Check the chip type */
        if (memcmp(devInfo.devName, "SR040", 5) != 0) {
            uwb_data_content->chip_id[1] = 0xFF;
        }
        else {
            uwb_data_content->chip_id[1] = MODELID_CHIP_TYPE;
        }
    #elif UWBIOT_UWBD_SR250
        /* Check the chip type */
        if (memcmp(devInfo.devName, "SR250_A1V2_PROD", devInfo.devNameLen) != 0) {
            uwb_data_content->chip_id[1] = 0xFF;
        }
        else {
            uwb_data_content->chip_id[1] = MODELID_CHIP_TYPE;
        }
    #endif // UWBIOT_UWBD_SR250
        /* Fill in supported UWB profile Ids */
        uwb_data_content->supported_config_ids = UWB_SUPPORTED_CONFIG_IDS;
#endif/* (UWBIOT_UWBD_SR04X) */
    /* Fill in the supported uwb profile ids */
    uwb_data_content->ranging_role = UWB_SUPPORTED_DEVICE_RANGING_ROLES;

    /* Generate mac address */
    status = UwbApi_GetTrng(SHORT_MAC_ADDR_LEN, uwb_data_content->device_mac_addr);

    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_GetTrng() Failed");
        goto exit;
    }

exit:
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

#endif // (UWBFTR_BlobParser)

tUWBAPI_STATUS UwbApi_GetDeviceCapability(phUwbCapInfo_t *pDevCap)
{
    tUWBAPI_STATUS status = UWBAPI_STATUS_FAILED;

    LOG_DBG("%s: enter", __FUNCTION__);


    if (pDevCap == NULL) {
        LOG_ERR("%s: pDevCap is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    status = getCapsInfo(pDevCap);

    if (status == UWBAPI_STATUS_OK) {
        /** Good */
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Parsing Capability Information Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR("%s: Get Capability Information failed", __FUNCTION__);
        status = UWBAPI_STATUS_FAILED;
    }

    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

#if UWBFTR_DataTransfer
EXTERNC tUWBAPI_STATUS UwbApi_SendData(phUwbDataPkt_t *pSendData)
{
    if(pSendData == NULL){
        return kUwb_StatusCode_InvalidArgument;
    }

    return uwb_api_send_data(pSendData->sessionHandle, pSendData->mac_address, pSendData->sequence_number, pSendData->data, pSendData->data_size);
}

EXTERNC tUWBAPI_STATUS UwbApi_LogicalLinkSendData(uwb_ll_data_receive_notification_t *pllSendData)
{
    return uwb_api_logical_link_send_data(pllSendData->llConnectId, pllSendData->sequence_number, pllSendData->data, pllSendData->data_size);
}
#endif // UWBFTR_DataTransfer

#if !(UWBIOT_UWBD_SR04X)
tUWBAPI_STATUS UwbApi_SessionQueryDataSize(phUwbQueryDataSize_t *pQueryDataSize)
{
    if(pQueryDataSize == NULL){
        return kUwb_StatusCode_InvalidArgument;
    }
    uwb_status_code_t uwb_status = uwb_api_query_data_size_in_ranging(pQueryDataSize->connectionId, &pQueryDataSize->dataSize);
    if (kUwb_StatusCode_Success != uwb_status) {
        return uwb_status;
    }
    return UWBAPI_STATUS_OK;
}
#endif // !(UWBIOT_UWBD_SR04X)

#if !(UWBIOT_UWBD_SR04X)
EXTERNC tUWBAPI_STATUS UwbApi_SetControllerHusSession(phControllerHusSessionConfig_t *pHusSessionCfg)
{

    if (pHusSessionCfg == NULL) {
        LOG_ERR("%s: pHusSessionCfg is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }


    return uwb_api_set_controller_hus_session(
        pHusSessionCfg->sessionHandle,
        pHusSessionCfg->phase_count,
        (uwb_hus_controller_secondary_session_config_t *)pHusSessionCfg->phase_list);
}

EXTERNC tUWBAPI_STATUS UwbApi_SetControleeHusSession(phControleeHusSessionConfig_t *pHusSessionCfg)
{
    if(pHusSessionCfg == NULL){
        return kUwb_StatusCode_InvalidArgument;
    }

    if((NULL == pHusSessionCfg->phase_list) || (0 == pHusSessionCfg->phase_count))
    {
        LOG_ERR("%s: pHusSessionCfg->phase_list is 0x%p and phase count is %d",
        __FUNCTION__, pHusSessionCfg->phase_list, pHusSessionCfg->phase_count);
        return kUwb_StatusCode_InvalidArgument;
    }

    uint32_t *secondary_session_handles = (uint32_t *)k_malloc(pHusSessionCfg->phase_count * sizeof(uint32_t));
    for (uint8_t phase = 0; phase < pHusSessionCfg->phase_count; phase++) {
        secondary_session_handles[phase] = pHusSessionCfg->phase_list[phase].phase_sessionHandle;
    }
    tUWBAPI_STATUS status = (tUWBAPI_STATUS) uwb_api_set_controlee_hus_session(
        pHusSessionCfg->sessionHandle,
        pHusSessionCfg->phase_count,
        secondary_session_handles);
    k_free(secondary_session_handles);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_SessionDtpcmConfig(phDataTxPhaseConfig_t *phDataTxPhaseCfg)
{

    if (phDataTxPhaseCfg == NULL || phDataTxPhaseCfg->dtpml == NULL) {
        LOG_ERR(
            "%s: phDataTxPhaseCfg (0x%p) or phDataTxPhaseCfg->dtpml is NULL", __FUNCTION__, phDataTxPhaseCfg);
        LOG_ERR("%s: phDataTxPhaseCfg is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    return uwb_api_dtpcm_config(
        phDataTxPhaseCfg->dtpcm_SessionHandle,
        phDataTxPhaseCfg->dtpcm_Repetition,
        phDataTxPhaseCfg->dataTransferCtrl,
        phDataTxPhaseCfg->dtpml,
        phDataTxPhaseCfg->dtpml_size);
}
#endif // !(UWBIOT_UWBD_SR04X)

#if UWBFTR_DataTransfer
tUWBAPI_STATUS UwbApi_CreateLogicalLink(
    phLogicalLinkCreateCmd_t *phLogicalLinkCreateCmd, uint32_t *pLogicalLinkConnectId)
{
    return uwb_api_logical_link_create(
        phLogicalLinkCreateCmd->session_handle,
        phLogicalLinkCreateCmd->llm_selector,
        phLogicalLinkCreateCmd->dst_address,
        phLogicalLinkCreateCmd->ll_class_length,
        phLogicalLinkCreateCmd->ll_max_sdu_size_length,
        phLogicalLinkCreateCmd->ll_max_sdu_size_value,
        pLogicalLinkConnectId);
}

tUWBAPI_STATUS UwbApi_CloseLogicalLink(uint32_t LogicalLinkConnectId)
{
    return uwb_api_logical_link_close(LogicalLinkConnectId);
}

tUWBAPI_STATUS UwbApi_LogicalLinkGetParams(
    uint32_t ConnectionIdentifier, phLogicalLinkGetParamsRsp_t *phLogicalLinkGetParamsRsp)
{
    if (NULL == phLogicalLinkGetParamsRsp) {
        return UWBAPI_STATUS_FAILED;
    }
    uwb_logical_link_get_params_rsp_t ll_get_param_rsp = {0};
    uwb_status_code_t uwb_status = uwb_api_logical_link_get_param(ConnectionIdentifier, &ll_get_param_rsp);

    phLogicalLinkGetParamsRsp->status = (uint8_t) uwb_status;
    phLogicalLinkGetParamsRsp->control_field = ll_get_param_rsp.control_field;
    phLogicalLinkGetParamsRsp->ll_sdu_size = ll_get_param_rsp.max_ll_sdu_size;
    phLogicalLinkGetParamsRsp->ll_pdu_size = ll_get_param_rsp.max_ll_pdu_size;
    phLogicalLinkGetParamsRsp->Tx_window_size = ll_get_param_rsp.tx_window_size;
    phLogicalLinkGetParamsRsp->Rx_window_size = ll_get_param_rsp.rx_window_size;
    phLogicalLinkGetParamsRsp->repetition_count = ll_get_param_rsp.repetition_count_max;
    phLogicalLinkGetParamsRsp->link_to = ll_get_param_rsp.link_to;
    phLogicalLinkGetParamsRsp->port = ll_get_param_rsp.port;

    return uwb_status;
}

#endif // UWBFTR_DataTransfer
