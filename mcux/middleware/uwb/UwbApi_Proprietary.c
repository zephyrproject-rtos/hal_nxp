/*
 *
 * Copyright 2018-2020,2022-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "UwbApi_Internal.h"
#include "UwbApi_Proprietary_Internal.h"
#include "zephyr/kernel.h"
#include "uci_prop_defs.h"
#include "uci_ext_defs.h"
#include "AppConfigParams.h"
#include "PrintUtility.h"
#include "UwbApi_Utility.h"
#include "UwbApi.h"
#include "uwbiot_ver.h"
#include "phNxpUwbConfig.h"
#if UWBIOT_UWBD_SR1XXT_SR2XXT
#include "phNxpUciHal_fwd.h"
#include "uwb_tml_transport.h"
#include "uwb_fwdl_provider.h"
#endif // UWBIOT_UWBD_SR1XXT_SR2XXT
#include "zephyr/uwb/uwb.h"

#if (UWBFTR_SE_SE051W)
#include "StateMachine.h"
#endif
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_uwb_api_prop, LOG_LEVEL_INF);

extern struct k_sem g_uwb_nxp_semaphore;

EXTERNC tUWBAPI_STATUS UwbApi_GetDeviceInfo(phUwbDevInfo_t *pdevInfo)
{
    tUWBAPI_STATUS status;
    LOG_DBG("%s: enter; ", __FUNCTION__);


    if (pdevInfo == NULL) {
        LOG_ERR("%s: pdevInfo is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    status = getDeviceInfo(pdevInfo);

    if (status == UWBAPI_STATUS_OK) {
        // if (parseDeviceInfo(pdevInfo, uwbContext.rsp_data, uwbContext.rsp_len) == FALSE) {
        //     LOG_ERR("%s: Parsing Device Information Failed", __FUNCTION__);
        //     status = UWBAPI_STATUS_FAILED;
        // }
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Parsing Device Information Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR("%s: Parsing Device Information failed with status %s (0x%x)",
            __FUNCTION__,
            getStatusString(status),
            status);
        status = UWBAPI_STATUS_FAILED;
    }
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_DoChipCalibration(uint8_t channel, phDoCalibNtfStatus_t *pDoCalibStatus)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen         = 0;
    uint32_t index          = 0;
    uint8_t response[20]    = {0};
    uint32_t response_len   = sizeof(response);
    const k_timeout_t uwb_ntf_timeout = Z_TIMEOUT_MS(UWBD_DO_CALIB_NTF_TIMEOUT);

    LOG_DBG("%s: Enter", __FUNCTION__);

    if (pDoCalibStatus == NULL) {
        LOG_ERR("%s: pDoCalibStatus is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    cmdLen = serializeDoChipCalibPayload(channel, &uwbContext.snd_data[0]);

    // Schedule notification read BEFORE sending the command
    uint8_t calib_ntf[10];
    memset(calib_ntf, 0xFF, sizeof(calib_ntf));
    uint32_t calib_ntf_len = sizeof(calib_ntf);

    void *scheduled_ntf = uwb_uci_schedule_packet_read(
        UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_DO_CHIP_CALIBRATION,
        calib_ntf, &calib_ntf_len, &g_uwb_nxp_semaphore);
    if (NULL == scheduled_ntf) {
        LOG_ERR("Could not schedule packet read");
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    // Send the command
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_DO_CHIP_CALIBRATION,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("%s: Do Chip Calibration failed with status %s (0x%x)",
                __FUNCTION__, getStatusString(status), status);
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
        return status;
    }

    // Wait for notification
    if (kUwb_StatusCode_Success != k_sem_take(&g_uwb_nxp_semaphore, uwb_ntf_timeout)) {
        LOG_ERR("%s: Do Chip Calibration notification time out", __FUNCTION__);
        status = UWBAPI_STATUS_TIMEOUT;
    } else {
        status = UWBAPI_STATUS_OK;
        if (calib_ntf_len > UCI_HEADER_SIZE) {
            uint8_t *p = &calib_ntf[UCI_HEADER_SIZE];
            index = 0;
            UWB_STREAM_TO_UINT8(pDoCalibStatus->calibNtfStatus, p, index);
            if (pDoCalibStatus->calibNtfStatus == UWBAPI_STATUS_OK) {
                UWB_STREAM_TO_UINT16(pDoCalibStatus->calibNtfValue, p, index);
                LOG_DBG("%s: Do Chip Calibration notification successful", __FUNCTION__);
            } else {
                status = pDoCalibStatus->calibNtfStatus;
                LOG_ERR("%s: Do Chip Calibration notification failed", __FUNCTION__);
            }
        } else {
            status = UWBAPI_STATUS_FAILED;
            LOG_ERR("%s: Do Chip Calib ntf Invalid length", __FUNCTION__);
        }
    }

    uwb_uci_remove_scheduled_packet(scheduled_ntf);
    k_sem_reset(&g_uwb_nxp_semaphore);

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;

}
EXTERNC tUWBAPI_STATUS UwbApi_SetCalibration(
    uint8_t channel, eCalibParam paramId, uint8_t *calibrationValue, uint16_t length)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);

    LOG_DBG("%s: Enter", __FUNCTION__);

    switch (paramId) {
    case CHIP_CALIBRATION:
    case RF_CLK_ACCURACY_CALIB:
    case RX_ANT_DELAY_CALIB:
#if UWBFTR_AoA_FoV
    case PDOA_OFFSET_CALIB:
#endif // UWBFTR_AoA_FoV
    case TX_POWER_PER_ANTENNA:
    case MANUAL_TX_POW_CTRL:
#if UWBFTR_AoA_FoV
    case AOA_ANTENNAS_PDOA_CALIB:
    case PDOA_MANUFACT_ZERO_OFFSET_CALIB:
    case AOA_THRESHOLD_PDOA:
#endif // UWBFTR_AoA_FoV
    case TX_TEMPERATURE_COMP_PER_ANTENNA:
    case RSSI_CALIB_CONSTANT_PER_ANTENNA:
#if UWBIOT_UWBD_SR1XXT
    case PA_PPA_CALIB_CTRL:
#endif // UWBIOT_UWBD_SR1XXT
#if UWBFTR_AoA_FoV
#if UWBIOT_UWBD_SR1XXT
    case AOA_ANTENNAS_MULTIPOINT_CALIB:
#endif // UWBIOT_UWBD_SR1XXT
    case AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT:
#endif // UWBFTR_AoA_FoV
#if UWBIOT_UWBD_SR2XXT
    case AOA_PHASEFLIP_ANTSPACING:
    case PLATFORM_ID:
    case CONFIG_VERSION:
    case TX_ANT_DELAY_CALIB:
    case TRA2_LOFT_CALIB:
    case TRA1_LOFT_CALIB:
    case FOM_ANGLE_CUTOFF:
    case RADAR_LO_GATING:
#endif // UWBIOT_UWBD_SR2XXT
        break;
    default:
        LOG_ERR("%s: Invalid calibration parameter %0X ", __FUNCTION__, paramId);
        return kUwb_StatusCode_InvalidArgument;
    }

    if (calibrationValue == NULL || length == 0) {
        LOG_ERR("%s: data is invalid", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    if (length > (MAX_CMD_BUFFER_DATA_TRANSFER - 3)) { // channel +  T(ag)calibParam + L(ength) + V(alue)calib data
        LOG_ERR("%s: calibration data is more that MAX_CMD_BUFFER_TRANSFER", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    cmdLen = serializeSetCalibPayload(channel, paramId, calibrationValue, length, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_API_VENDOR_SET_DEVICE_CALIBRATION, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SET_DEVICE_CALIBRATION,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: Set Calibration successful", __FUNCTION__);
    }
    else {
        LOG_ERR(
            "%s: Set Calibration failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetCalibration(phGetCalibInputParams_t *pCalibInput, phCalibRespStatus_t *pCalibResp)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint32_t response_len = sizeof(uwbContext.rsp_data);
    uint8_t index = 0;

    LOG_DBG("%s: Enter", __FUNCTION__);



    if ((NULL == pCalibInput) || (NULL == pCalibResp)) {
        LOG_ERR(
            "%s: Invalid parameter => pCalibInput: 0x%p pCalibResp : 0x%p", __FUNCTION__, pCalibInput, pCalibResp);
        return kUwb_StatusCode_InvalidArgument;
    }

    if (NULL == pCalibResp->pCalibrationValue) {
        LOG_ERR("%s: Invalid parameter => pCalibrationValue is NULL ", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    switch (pCalibInput->paramId) {
    case CHIP_CALIBRATION:
    case RF_CLK_ACCURACY_CALIB:
    case RX_ANT_DELAY_CALIB:
#if UWBFTR_AoA_FoV
    case PDOA_OFFSET_CALIB:
#endif // UWBFTR_AoA_FoV
    case TX_POWER_PER_ANTENNA:
    case MANUAL_TX_POW_CTRL:
#if UWBFTR_AoA_FoV
    case AOA_ANTENNAS_PDOA_CALIB:
    case PDOA_MANUFACT_ZERO_OFFSET_CALIB:
    case AOA_THRESHOLD_PDOA:
#endif // UWBFTR_AoA_FoV
    case TX_TEMPERATURE_COMP_PER_ANTENNA:
    case RSSI_CALIB_CONSTANT_PER_ANTENNA:
#if UWBIOT_UWBD_SR1XXT
    case PA_PPA_CALIB_CTRL:
#endif // UWBIOT_UWBD_SR1XXT
#if UWBFTR_AoA_FoV
    case AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT:
#if UWBIOT_UWBD_SR1XXT
    case AOA_ANTENNAS_MULTIPOINT_CALIB:
#endif // UWBIOT_UWBD_SR1XXT
#endif // UWBFTR_AoA_FoV
#if UWBIOT_UWBD_SR2XXT
    case AOA_PHASEFLIP_ANTSPACING:
    case PLATFORM_ID:
    case CONFIG_VERSION:
    case TX_ANT_DELAY_CALIB:
    case TRA2_LOFT_CALIB:
    case TRA1_LOFT_CALIB:
    case RADAR_LO_GATING:
    case CHIP_CALIBRATION_STATE:
    case FOM_ANGLE_CUTOFF:
#endif // UWBIOT_UWBD_SR2XXT
        break;
    default:
        LOG_ERR("%s: Invalid calibration parameter ", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    cmdLen = serializeGetCalibPayload(pCalibInput, &uwbContext.snd_data[0]);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_GET_DEVICE_CALIBRATION,
                        uwbContext.snd_data, cmdLen,
                        uwbContext.rsp_data, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    uint8_t *rspData = &uwbContext.rsp_data[UCI_HEADER_SIZE];
    UWB_STREAM_TO_UINT8(status, rspData, index);
    if ((status == UWBAPI_STATUS_OK) && (response_len > UCI_HEADER_SIZE)) {
        deserializeGetCalibResp(pCalibResp, rspData);
    }
    else {
        LOG_ERR(
            "%s: Get Calibration value failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
    }
    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_SetDebugParams(
    uint32_t sessionHandle, uint8_t noOfparams, const UWB_DebugParams_List_t *DebugParams_List)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen                  = 0;
    uint8_t paramLen                 = 0;
    uint8_t singleParamLen                   = 0;
    uint8_t flag_for_data_logger_ntf = false;
    uint8_t response[20]             = {0};
    uint32_t response_len            = sizeof(response);
    UWB_DBG_CFG_t paramId;
    uint8_t payloadOffset = SES_ID_AND_NO_OF_PARAMS_OFFSET;


    /* Check if the device is initialized or not */
    LOG_DBG("%s: enter", __FUNCTION__);


    /* Check if the passed list is having parameters or not */
    if ((DebugParams_List == NULL) || ((noOfparams == 0))) {
        LOG_ERR("%s: Parameter value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    for (uint32_t LoopCnt = 0; LoopCnt < noOfparams; ++LoopCnt) {
        void *pParamValue = NULL;
        paramId = DebugParams_List[LoopCnt].param_id;

        if (paramId >= END_OF_SUPPORTED_EXT_DEBUG_CONFIGS) {
            LOG_ERR("%s: Invalid Parameter value", __FUNCTION__);
            return kUwb_StatusCode_InvalidArgument;
        }
#if UWBIOT_UWBD_SR2XXT
        if (paramId == kUWB_DBG_CFG_DATA_LOGGER_NTF) {
            flag_for_data_logger_ntf = true;
        }
#endif // UWBIOT_UWBD_SR2XXT

        if(DebugParams_List[LoopCnt].param_type == kUWB_DEBUGPARAMS_Type_u32){
            singleParamLen = 4;
            pParamValue = (void *)(&DebugParams_List[LoopCnt].param_value.vu32);
        }
        else{
            singleParamLen = DebugParams_List[LoopCnt].param_value.param.param_len;
            pParamValue = (void *)(DebugParams_List[LoopCnt].param_value.param.param_value);
        }

        // we have only extended debug configs
        paramLen = (uint16_t)(paramLen + getVendorDebugConfigTLVBuffer(paramId,
                                             pParamValue,
                                             singleParamLen,
                                             &uwbContext.rsp_data[payloadOffset + paramLen]));
    }

    if (paramLen == 0) {
        LOG_ERR("%s: getVendorDebugConfigTLVBuffer() failed", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfparams, paramLen, uwbContext.rsp_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SET_VENDOR_APP_CONFIG_CMD,
                        uwbContext.rsp_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if ((status == UWBAPI_STATUS_OK) && flag_for_data_logger_ntf) {
        // InputOutputData_t ioData = {
        //     .enableFwDump = TRUE,
        //     .enableCirDump = FALSE
        // };

        // const tHAL_UWB_ENTRY *halFuncEntries = GetHalEntryFuncs();
        // if (halFuncEntries) {
        //     tHAL_UWB_IOCTL ioCtl = {
        //         .pIoData = &ioData
        //     };
        //     halFuncEntries->ioctl(HAL_UWB_IOCTL_DUMP_FW_LOG, &ioCtl);
        // }
    }
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetDebugParams(
    uint32_t sessionHandle, uint8_t noOfparams, UWB_DebugParams_List_t *DebugParams_List)
{
    tUWBAPI_STATUS status;
    uint8_t i = 0;
    UWB_DBG_CFG_t paramId;
    uint8_t *pConfigCommand = NULL;
    uint8_t payloadOffset   = SES_ID_AND_NO_OF_PARAMS_OFFSET;
    uint16_t cmdLen         = 0;
    uint8_t response[20]    = {0};
    uint32_t response_len   = sizeof(response);
    uint8_t index           = 0;

    LOG_DBG("%s: enter", __FUNCTION__);


    if ((DebugParams_List == NULL) || (noOfparams == 0)) {
        LOG_ERR("%s: Parameter value is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    pConfigCommand = &uwbContext.snd_data[payloadOffset];
    for (i = 0; i < noOfparams; i++) {
        paramId = DebugParams_List[i].param_id;

        if (paramId >= END_OF_SUPPORTED_EXT_DEBUG_CONFIGS) {
            return kUwb_StatusCode_InvalidArgument;
        }

        // we have only extended debug configs
        pConfigCommand[cmdLen++] = (uint8_t)(paramId & 0xFF);
    }

    cmdLen = uwb_serialize_app_config_payload(sessionHandle, noOfparams, cmdLen, uwbContext.snd_data);
    // status = sendUciCommandAndWait(UWA_DM_API_SESSION_GET_VENDOR_APP_CONFIG_EVT, cmdLen, uwbContext.snd_data);

    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_GET_VENDOR_APP_CONFIG_CMD,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    uint8_t *rspData = &response[UCI_HEADER_SIZE];
    UWB_STREAM_TO_UINT8(status, rspData, index);

    if (UWBAPI_STATUS_OK != status) {
        LOG_ERR("GetDebugParams is failed with status 0x%02x", status);
        return status;
    }
    rspData++; // Skip status byte
    parseDebugParams(rspData, noOfparams, DebugParams_List);
    return status;
}

#if UWBIOT_SESN_SNXXX
EXTERNC tUWBAPI_STATUS UwbApi_PerformBinding(phSeDoBindStatus_t *doBindStatus)
{
    tUWBAPI_STATUS status;
    uint32_t index = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);


    if (doBindStatus == NULL) {
        LOG_ERR("%s: doBindStatus is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    // status = sendUciCommandAndWait(UWA_DM_API_PROP_DO_BIND, 0, NULL);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SE_DO_BIND,
                    NULL, 0,
                    response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        uint8_t notification[11] = {0};
        uint32_t notification_len = sizeof(notification);
        const k_timeout_t se_ntf_timeout  = Z_TIMEOUT_MS(UWBD_SE_TIMEOUT);

        ret = uwb_uci_wait_for_packet(UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SE_DO_BIND, notification, &notification_len, se_ntf_timeout);
        if (0 != ret) {
            LOG_ERR("Could not get notification");
            status = UWBAPI_STATUS_FAILED;
        }
        uint8_t *p = &notification[UCI_HEADER_SIZE];
        UWB_STREAM_TO_UINT8(doBindStatus->status, p, index);
        if (doBindStatus->status != UWBAPI_STATUS_OK) {
            status = UWBAPI_STATUS_FAILED;
            LOG_WRN(
                "%s: Get doBindStatus is not success, status is %0x", __FUNCTION__, doBindStatus->status);
        }
        UWB_STREAM_TO_UINT8(doBindStatus->count_remaining, p, index);
        UWB_STREAM_TO_UINT8(doBindStatus->binding_state, p, index);
        UWB_STREAM_TO_UINT16(doBindStatus->se_instruction_code, p, index);
        UWB_STREAM_TO_UINT16(doBindStatus->se_error_status, p, index);
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Do Binding Command Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR("%s: Binding is failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
        status = UWBAPI_STATUS_FAILED;
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}
#endif //(UWBIOT_SESN_SNXXX)

#if (UWBFTR_SE_SE051W)
EXTERNC tUWBAPI_STATUS UwbApi_PerformBinding(void)
{

    return Binding_Process();
}

EXTERNC tUWBAPI_STATUS UwbApi_PerformLocking(void)
{

    return locking_Process();
}
#endif // UWBFTR_SE_SE051W

#if (UWBIOT_UWBD_SR250 || UWBIOT_UWBD_SR150)
EXTERNC tUWBAPI_STATUS UwbApi_SetAppConfigWrappedRDS(uint32_t sessionHandle, uint8_t *pWrappedRds, size_t WrappedRdsLen)
{
    tUWBAPI_STATUS status = UWBAPI_STATUS_FAILED;
    uint16_t cmdLen       = 0;
    uint8_t payloadOffset = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);

    uint32_t WrappedRdsLenU32 = (uint32_t)WrappedRdsLen;

    if (uwbContext.isUfaEnabled == FALSE) {
        LOG_ERR("%s: UWB device is not initialized", __FUNCTION__);
        status = UWBAPI_STATUS_NOT_INITIALIZED;
        goto exit;
    }

    if (pWrappedRds == NULL) {
        LOG_ERR("%s: pWrappedRds is NULL", __FUNCTION__);
        status = kUwb_StatusCode_InvalidArgument;
        goto exit;
    }

    cmdLen                        = uwb_serialize_app_config_payload(sessionHandle, 1, payloadOffset, uwbContext.snd_data);
    uwbContext.snd_data[cmdLen++] = UCI_VENDOR_PARAM_ID_WRAPPED_RDS;
    uwbContext.snd_data[cmdLen++] = (uint8_t)WrappedRdsLen;
    memcpy(&uwbContext.snd_data[cmdLen], (void *)pWrappedRds, WrappedRdsLenU32);
    cmdLen += (uint16_t)WrappedRdsLen;

    // status = sendUciCommandAndWait(UWA_DM_API_SESSION_SET_VENDOR_APP_CONFIG_EVT, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SET_VENDOR_APP_CONFIG_CMD,
                        uwbContext.snd_data,cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (UWBAPI_STATUS_OK != status) {
        LOG_ERR("UwbApi_SetAppConfigWrappedRDS is failed with status 0x%02x", status);
        return status;
    }
exit:
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_ReadModuleMakerInfo(uint16_t *pModuleMakerInfo)
{
    tUWBAPI_STATUS status;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    uint8_t index = 0;

    LOG_DBG("%s: Enter", __FUNCTION__);



    if (pModuleMakerInfo == NULL) {
        LOG_ERR("%s: output params is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    // status = sendUciCommandAndWait(UWA_DM_API_READ_MODULE_MAKER_EVT, 0, NULL);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY, EXT_UCI_MSG_READ_MODULE_MAKER_ID,
                        NULL, 0,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    uint8_t *rspData = &response[UCI_HEADER_SIZE];
    UWB_STREAM_TO_UINT8(status, rspData, index);
    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: Read module maker info command successful", __FUNCTION__);
        if (response_len > UCI_HEADER_SIZE) {
            *pModuleMakerInfo = (rspData[1] << 0) | (rspData[2] << 8);
        }
        else {
            LOG_ERR("%s: Received wrong data ", __FUNCTION__);
            status = UWBAPI_STATUS_FAILED;
        }
    }
    else {
        LOG_ERR(
            "%s: Read module maker Command failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
    }
    return status;
}
#endif // (UWBIOT_UWBD_SR250 || UWBIOT_UWBD_SR150)


#if (UWBIOT_UWBD_SR150 && UWBFTR_FactoryMode) || (UWBIOT_UWBD_SR250)
EXTERNC tUWBAPI_STATUS UwbApi_WriteModuleMakerInfo(uint16_t ModuleMakerInfo)
{
    tUWBAPI_STATUS status;
    uint8_t offset = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);


    LOG_DBG("%s: Enter", __FUNCTION__);



    UWB_UINT16_TO_STREAM(uwbContext.snd_data, ModuleMakerInfo, offset);

    // status = sendUciCommandAndWait(UWA_DM_API_WRITE_MODULE_MAKER_EVT, offset, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY, EXT_UCI_MSG_WRITE_MODULE_MAKER_ID,
                        uwbContext.snd_data, offset,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: Write module maker Command successful", __FUNCTION__);
    }
    else {
        LOG_ERR(
            "%s: Write module maker Command failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
    }
    return status;
}
#endif // (UWBIOT_UWBD_SR150 && UWBFTR_FactoryMode) || (UWBIOT_UWBD_SR250)

EXTERNC tUWBAPI_STATUS UwbApi_GetBindingCount(phSeGetBindingCount_t *getBindingCount)
{
    tUWBAPI_STATUS status;
    LOG_DBG("%s: Enter", __FUNCTION__);
    uint32_t index = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);



    if (getBindingCount == NULL) {
        LOG_ERR("%s: getBindingCount is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    // status = sendUciCommandAndWait(UWA_DM_API_PROP_GET_BINDING_COUNT, 0, NULL);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_SE_GET_BINDING_COUNT,
                        NULL, 0,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    /* response contains complete rsp, we have to skip Header */
    uint8_t *rspData = &response[UCI_HEADER_SIZE];
    UWB_STREAM_TO_UINT8(status, rspData, index);

    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: Binding Count is successful", __FUNCTION__);
        UWB_STREAM_TO_UINT8(getBindingCount->bindingStatus, rspData, index);
        UWB_STREAM_TO_UINT8(getBindingCount->uwbdBindingCount, rspData, index);
        UWB_STREAM_TO_UINT8(getBindingCount->seBindingCount, rspData, index);

    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Get Binding Count Command Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR(
            "%s: Binding Count is failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
        status = UWBAPI_STATUS_FAILED;
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

#if (UWBIOT_SESN_SNXXX)
EXTERNC tUWBAPI_STATUS UwbApi_TestConnectivity(SeConnectivityStatus_t *ConnectivityStatus)
{
    tUWBAPI_STATUS status;
    LOG_DBG("%s: Enter", __FUNCTION__);
    uint32_t index = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);



    if (ConnectivityStatus == NULL) {
        LOG_ERR("%s: ConnectivityStatus is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }



    // status = sendUciCommandAndWait(UWA_DM_API_PROP_TEST_CONNECTIVITY, 0, NULL);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SE_DO_TEST_CONNECTIVITY,
                        NULL, 0,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {

        uint8_t test_connectivity_ntf[10] = {0};
        uint32_t test_connectivity_ntf_len = sizeof(test_connectivity_ntf);

        void *scheduled_ntf = uwb_uci_schedule_packet_read(
            UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SE_DO_TEST_CONNECTIVITY, test_connectivity_ntf, &test_connectivity_ntf_len, &g_uwb_nxp_semaphore);
        if (NULL == scheduled_ntf) {
            LOG_ERR("Could not schedule packet read");
            k_sem_reset(&g_uwb_nxp_semaphore);
            return UWBAPI_STATUS_FAILED;
        }
        if (status == UWBAPI_STATUS_OK) {
            uint8_t *p = &response[UCI_HEADER_SIZE];
            UWB_STREAM_TO_UINT8(ConnectivityStatus->status, p, index);
            if (ConnectivityStatus->status != UWBAPI_STATUS_OK) {
                status = UWBAPI_STATUS_FAILED;
                LOG_WRN(
                    "%s: Get ConnectivityStatus is not success %0x", __FUNCTION__, ConnectivityStatus->status);
            }
            UWB_STREAM_TO_UINT16(ConnectivityStatus->se_instruction_code, p, index);
            UWB_STREAM_TO_UINT16(ConnectivityStatus->se_error_status, p, index);
            LOG_DBG("%s: Get ESE Test cmd passed", __FUNCTION__);
        }
        else {
            LOG_ERR("%s: Get  ESE Test cmd failed", __FUNCTION__);
            status = UWBAPI_STATUS_FAILED;
        }
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Connectivity test Command Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR("%s: Connectivity test response is failed with status %s (0x%x)",
            __FUNCTION__,
            getStatusString(status),
            status);
        status = UWBAPI_STATUS_FAILED;
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_SeTestLoop(uint16_t loopCnt, uint16_t timeInterval, phTestLoopData_t *testLoopData)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint32_t index = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);



    if (testLoopData == NULL) {
        LOG_ERR("%s: testLoopData is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }


    cmdLen = serializeSeLoopTestPayload(loopCnt, timeInterval, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_API_PROP_TEST_SE_LOOP, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_SE_DO_TEST_LOOP,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
            // status = waitforNotification(
            //     UWA_DM_PROP_SE_TEST_LOOP_NTF_EVT, (uint32_t)((uint32_t)(loopCnt * timeInterval) + UWBD_SE_TIMEOUT));

        uint8_t se_test_loop_ntf[10] = {0};
        uint32_t se_test_loop_ntf_len = sizeof(se_test_loop_ntf);

        void *scheduled_ntf = uwb_uci_schedule_packet_read(
            UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_2, EXT_UCI_MSG_SE_DO_TEST_LOOP, se_test_loop_ntf, &se_test_loop_ntf_len, &g_uwb_nxp_semaphore);
        if (NULL == scheduled_ntf) {
            LOG_ERR("Could not schedule packet read");
            k_sem_reset(&g_uwb_nxp_semaphore);
            return UWBAPI_STATUS_FAILED;
        }
            /*
         * Increasing the delay as it is not sufficient to get the notification.
         */
        if (status == UWBAPI_STATUS_OK) {
            uint8_t *p = &response[UCI_HEADER_SIZE];
            UWB_STREAM_TO_UINT8(testLoopData->status, p, index);
            if (testLoopData->status == UWBAPI_STATUS_OK) {
                status = UWBAPI_STATUS_OK;
                UWB_STREAM_TO_UINT16(testLoopData->loop_cnt, p, index);
                UWB_STREAM_TO_UINT16(testLoopData->loop_pass_count, p, index);
                LOG_DBG("%s: Loop test is successful", __FUNCTION__);
            }
            else {
                LOG_ERR("%s: Loop test is failed", __FUNCTION__);
                status = UWBAPI_STATUS_FAILED;
            }
        }
        else {
            testLoopData->status = 0xFF;
            LOG_ERR("%s: Loop test is failed", __FUNCTION__);
            status = UWBAPI_STATUS_FAILED;
        }
        k_sem_reset(&g_uwb_nxp_semaphore);
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Loop test Command Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR("%s: Loop test is failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
        status = UWBAPI_STATUS_FAILED;
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_GetBindingStatus(phSeGetBindingStatus_t *getBindingStatus)
{
    tUWBAPI_STATUS status;
    uint32_t index = 0;
     uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);



    if (getBindingStatus == NULL) {
        LOG_ERR("%s: getBindingStatus is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    // status = sendUciCommandAndWait(UWA_DM_API_PROP_GET_BINDING_STATUS, 0, NULL);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_ESE_BINDING_CHECK_CMD,
                        NULL, 0,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];

    if (status == UWBAPI_STATUS_OK) {
        // status = waitforNotification(UWA_DM_VENDOR_ESE_BINDING_CHECK_NTF_EVT, UWBD_SE_TIMEOUT);

        uint8_t binding_status_ntf[10] = {0};
        uint32_t binding_status_ntf_len = sizeof(binding_status_ntf);

        void *scheduled_ntf = uwb_uci_schedule_packet_read(
            UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_ESE_BINDING_CHECK_CMD, binding_status_ntf, &binding_status_ntf_len, &g_uwb_nxp_semaphore);
        if (NULL == scheduled_ntf) {
            LOG_ERR("Could not schedule packet read");
            k_sem_reset(&g_uwb_nxp_semaphore);
            return UWBAPI_STATUS_FAILED;
        }
        if (status == UWBAPI_STATUS_OK) {
            uint8_t *p = &response[UCI_HEADER_SIZE];
            UWB_STREAM_TO_UINT8(getBindingStatus->status, p, index);
            if (getBindingStatus->status != 0x02) {
                status = UWBAPI_STATUS_FAILED;
                LOG_WRN(
                    "Get binding status is NOT bound and Unlocked , status is %0x", getBindingStatus->status);
            }
            UWB_STREAM_TO_UINT8(getBindingStatus->se_binding_count, p, index);
            UWB_STREAM_TO_UINT8(getBindingStatus->uwbd_binding_count, p, index);
            UWB_STREAM_TO_UINT16(getBindingStatus->se_instruction_code, p, index);
            UWB_STREAM_TO_UINT16(getBindingStatus->se_error_status, p, index);
        }
        else {
            LOG_ERR("%s: Get binding status cmd failed", __FUNCTION__);
            status = UWBAPI_STATUS_FAILED;
        }
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Get binding status Command Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR(
            "%s: Get binding status cmd failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
        status = UWBAPI_STATUS_FAILED;
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

EXTERNC tUWBAPI_STATUS UwbApi_URSKdeletionRequest(
    uint8_t noOfSessionIds, uint32_t *pSessionIdList, phUrskDeletionRequestStatus_t *pUrskDeletionStatus)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint32_t index = 0;
     uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);



    if (noOfSessionIds == 0) {
        LOG_ERR("%s: noOfSessionIds is 0", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }
    if (pSessionIdList == NULL || pUrskDeletionStatus == NULL) {
        LOG_ERR(
            "%s: pSessionIdList = 0x%p and pUrskDeletionStatus = 0x%p", __FUNCTION__, pSessionIdList, pUrskDeletionStatus);
        return kUwb_StatusCode_InvalidArgument;
    }

    cmdLen = serializeUrskDeletionRequestPayload(noOfSessionIds, pSessionIdList, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_API_PROP_URSK_DELETION_REQUEST, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_URSK_DELETION_REQ,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        uint8_t ursk_deletion_req_ntf[10] = {0};
        uint32_t ursk_deletion_req_ntf_len = sizeof(ursk_deletion_req_ntf);

        void *scheduled_ntf = uwb_uci_schedule_packet_read(
            UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_URSK_DELETION_REQ, ursk_deletion_req_ntf, &ursk_deletion_req_ntf_len, &g_uwb_nxp_semaphore);
        if (NULL == scheduled_ntf) {
            LOG_ERR("Could not schedule packet read");
            k_sem_reset(&g_uwb_nxp_semaphore);
            return UWBAPI_STATUS_FAILED;
        }
        if (status == UWBAPI_STATUS_OK) {
            uint8_t *p = &response[UCI_HEADER_SIZE];
            UWB_STREAM_TO_UINT8(pUrskDeletionStatus->status, p, index);
            if (pUrskDeletionStatus->status == UWBAPI_STATUS_OK) {
                status = UWBAPI_STATUS_OK;
                UWB_STREAM_TO_UINT8(pUrskDeletionStatus->noOfSessionIds, p, index);
                for (int i = 0; i < pUrskDeletionStatus->noOfSessionIds; i++) {
                    UWB_STREAM_TO_UINT32(pUrskDeletionStatus->sessionIdList[i].sessionId, p, index);
                    UWB_STREAM_TO_UINT8(pUrskDeletionStatus->sessionIdList[i].status, p, index);
                }
            }
            else {
                pUrskDeletionStatus->status = 0xFF;
                LOG_ERR("%s: URSK deletion request ntf is failed", __FUNCTION__);
                status = UWBAPI_STATUS_FAILED;
            }
        }
        else {
            pUrskDeletionStatus->status = 0xFF;
            LOG_ERR("%s: URSK deletion request ntf not received", __FUNCTION__);
            status = UWBAPI_STATUS_FAILED;
        }
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: URSK deletion request Command Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR(
            "%s: URSK deletion request is failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
        status = UWBAPI_STATUS_FAILED;
    }
    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}
#endif //(UWBIOT_SESN_SNXXX)

#if !(UWBIOT_UWBD_SR04X)
EXTERNC tUWBAPI_STATUS UwbApi_QueryTemperature(uint8_t *pTemperatureValue)
{
    tUWBAPI_STATUS status;
    uint32_t index = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);



    if (pTemperatureValue == NULL) {
        LOG_ERR("%s: pTemperatureValue is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    // status = sendUciCommandAndWait(UWA_DM_API_PROP_QUERY_TEMP, 0, NULL);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_QUERY_TEMPERATURE,
                        NULL, 0,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s :Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    /* response contains complete rsp, we have to skip Header */
    uint8_t *rspData = &response[UCI_HEADER_SIZE];
    UWB_STREAM_TO_UINT8(status, rspData, index);
    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: Query temperature cmd successful", __FUNCTION__);
        UWB_STREAM_TO_UINT8(*pTemperatureValue, rspData, index);
    }
    else if (status == UWBAPI_STATUS_TIMEOUT) {
        LOG_ERR("%s: Query temperature cmd Timed Out", __FUNCTION__);
    }
    else {
        LOG_ERR(
            "%s: Query temperature cmd failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
        status = UWBAPI_STATUS_FAILED;
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}
#endif //!(UWBIOT_UWBD_SR04X)

#if (UWBIOT_UWBD_SR100T)
tUWBAPI_STATUS UwbApi_CalibrationIntegrityProtection(eCalibTagOption tagOption, uint16_t calibBitMask)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);

    LOG_DBG("%s: Enter", __FUNCTION__);



    cmdLen = serializecalibIntegrityProtectionPayload(tagOption, calibBitMask, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_API_PROP_CALIB_INTEGRITY_PROTECTION, cmdLen, uwbContext.snd_data);

    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_CALIBRATION_INTEGRITY_PROTECTION,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s :Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: Calibration Integrity Protection command successful", __FUNCTION__);
    }
    else {
        LOG_ERR("%s: Calibration Integrity Protection Command failed with status %s (0x%x)",
            __FUNCTION__,
            getStatusString(status),
            status);
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

tUWBAPI_STATUS UwbApi_VerifyCalibData(uint8_t *pCmacTag, uint8_t tagOption, uint16_t tagVersion)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);



    if (pCmacTag == NULL) {
        LOG_ERR("%s: data is invalid", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    cmdLen = serializeVerifyCalibDataPayload(pCmacTag, tagOption, tagVersion, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_API_PROP_VERIFY_CALIB_DATA, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_VERIFY_CALIB_DATA,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s :Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        /** TODO: Need to handle in secure calibration implementation of SR250*/
        // status = waitforNotification(EXT_UCI_MSG_VERIFY_CALIB_DATA, UWBD_GENERATE_TAG_NTF_TIMEOUT);
        uint8_t ursk_deletion_req_ntf[10] = {0};
        uint32_t ursk_deletion_req_ntf_len = sizeof(ursk_deletion_req_ntf);

        void *scheduled_ntf = uwb_uci_schedule_packet_read(
            UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_VERIFY_CALIB_DATA, ursk_deletion_req_ntf, &ursk_deletion_req_ntf_len, &g_uwb_nxp_semaphore);
        if (NULL == scheduled_ntf) {
            LOG_ERR("Could not schedule packet read");
            k_sem_reset(&g_uwb_nxp_semaphore);
            return UWBAPI_STATUS_FAILED;
        }
        if (status == UWBAPI_STATUS_OK) {
            status = uwbContext.wstatus;
            if (status == UWBAPI_STATUS_OK) {
                LOG_DBG("%s: Verify Calib Data successful", __FUNCTION__);
            }
            else {
                LOG_ERR("%s: Verify Calib Data failed", __FUNCTION__);
            }
        }
        else {
            LOG_ERR("%s: Verify Calib Data notification time out", __FUNCTION__);
        }
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
    }
    else {
        LOG_ERR("%s: Verify Calib Data Command failed with status %s (0x%x)",
            __FUNCTION__,
            getStatusString(status),
            status);
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}
#endif // UWBIOT_UWBD_SR100T
EXTERNC tUWBAPI_STATUS UwbApi_QueryUwbTimestamp(uint8_t len, uint8_t pTimestampValue[])
{
    LOG_DBG("%s: Enter", __FUNCTION__);



    if ((len < 8) || (pTimestampValue == NULL)) {
        LOG_ERR("%s: pTimestampValue is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    uwb_status_code_t uwb_status = uwb_api_core_query_uwbs_timestamp(pTimestampValue, len);
    if (kUwb_StatusCode_Success != uwb_status) {
        return UWBAPI_STATUS_FAILED;
    }

    return UWBAPI_STATUS_OK;
}

#if UWBFTR_DL_TDoA_Anchor
tUWBAPI_STATUS UwbApi_UpdateActiveRoundsAnchor(uint32_t sessionHandle,
    uint8_t nActiveRounds,
    UWB_MacAddressMode_t macAddressingMode,
    const phActiveRoundsConfig_t roundConfigList[],
    phNotActivatedRounds_t *pNotActivatedRound)
{
    uwb_status_code_t uwb_status = uwb_api_update_dt_anchor_ranging_round(sessionHandle,
        nActiveRounds,
        (const uwb_mac_addr_mode_t) macAddressingMode,
        (const uwb_active_rounds_config_t *) roundConfigList,
        pNotActivatedRound->indexList,
        &pNotActivatedRound->noOfIndex);

    if (kUwb_StatusCode_Success != uwb_status) {
         return uwb_status;
    }
    return UWBAPI_STATUS_OK;
}
#endif // UWBFTR_DL_TDoA_Anchor

#if UWBFTR_DL_TDoA_Tag
tUWBAPI_STATUS UwbApi_UpdateActiveRoundsReceiver(uint32_t sessionHandle,
    uint8_t nActiveRounds,
    const uint8_t RangingroundIndexList[],
    phNotActivatedRounds_t *pNotActivatedRound)
{
    uwb_status_code_t uwb_status = uwb_api_update_dt_tag_ranging_round(sessionHandle,
        nActiveRounds,
        RangingroundIndexList,
        pNotActivatedRound->indexList,
        &pNotActivatedRound->noOfIndex);
    if (kUwb_StatusCode_Success != uwb_status) {
        return uwb_status;
    }
    return UWBAPI_STATUS_OK;
}
#endif // UWBFTR_DL_TDoA_Tag

tUWBAPI_STATUS UwbApi_GetFwCrashLog(phFwCrashLogInfo_t *pLogInfo)
{
    // tHAL_UWB_IOCTL ioCtl;
    // const tHAL_UWB_ENTRY *halFuncEntries = NULL;

    if (pLogInfo == NULL) {
        LOG_ERR("%s: pLogInfo is null ", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }
    if (pLogInfo->pLog == NULL || 0 == pLogInfo->logLen) {
        LOG_ERR("%s: Invalid input arguments ", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_DBG_GET_ERROR_LOG,
                        NULL, 0,
                        pLogInfo->pLog, &pLogInfo->logLen);
    if (0 != ret) {
        LOG_ERR("Failed to transceive UCI packet");
        return kUwb_StatusCode_Failed;
    }

    return kUwb_StatusCode_Success;
}

tUWBAPI_STATUS UwbApi_SetDefaultCoreConfigs()
{
    return setDefaultCoreConfigs();
}

#if UWBFTR_TransitProp
/**
 * \brief Host shall use this API to set the RDS parameters for given UWB session.
 *
 * \param[in]   pRdsParam                    pointer to the RDS parameter structure.
 * \param[out]  pLastPhyStsIndex             pointer to the last PHY STS index.
 * \param[in]   rdsNtf_timeoutMs             Notification Timeout preiod in Milliseconds.
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #kUwb_StatusCode_InvalidArgument      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 * \note On sending SESSION_SET_RDS_PARAM_CMD, The API waits for the SESSION_SET_RDS_PARAM_NTF, for the given \p rdsNtf_timeoutMs.
 * \note If \p rdsNtf_timeoutMs is set to 0 then the API will not wait for the notification.
 */
tUWBAPI_STATUS UwbApi_SetRdsParam(phSetRdsPramCmd_t *pRdsParam, uint32_t *pLastPhyStsIndex, uint32_t rdsNtf_timeoutMs)
{
    tUWBAPI_STATUS status;
    LOG_DBG("%s: Enter", __FUNCTION__);
    uint16_t cmdLen = 0;
    uint32_t index = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    uint32_t payload_len = 0;

    if (pRdsParam == NULL || pLastPhyStsIndex == NULL) {
        LOG_ERR("%s: pRdsParam or pLastPhyStsIndex is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }
    /** Initializing the lastPhyStsIndex with the default value, To be overwritten by the Responce */
    *pLastPhyStsIndex = 0xFFFFFFFF;

    for (uint8_t i = 0; i < pRdsParam->rdsParamListSize; i++) {
        if (pRdsParam->rdsParamList[i].rdsLength == 0 || pRdsParam->rdsParamList[i].rdsLength > WRAPPED_RDS_LEN) {
            LOG_ERR("%s : Invalid RDS Length :%d", __FUNCTION__, pRdsParam->rdsParamList[i].rdsLength);
            status = kUwb_StatusCode_InvalidArgument;
            goto exit;
        }
    }

    cmdLen = serializeSessionSetRdsParam(pRdsParam, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_SESSION_SET_RDS_PARAM_EVT, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_PARAM_ID_SESSION_SET_RDS_PARAM_CMD_NTF,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    uint8_t *rspData = &response[UCI_HEADER_SIZE];
    payload_len = response_len - UCI_HEADER_SIZE;
    UWB_STREAM_TO_UINT8(status, rspData, index);
    if (status == UWBAPI_STATUS_OK) {
        if (payload_len == MAX_LAST_PHY_STS_INDEX_SZ + 1 /*status*/) {
            UWB_STREAM_TO_UINT32(*pLastPhyStsIndex, rspData, index);
        }
        else {
            LOG_ERR("%s: Set RDS Param Rsp - Invalid Length : %d", __FUNCTION__, payload_len);
            status = UWBAPI_STATUS_FAILED;
            goto exit;
        }

        /** Skip the wait for the notification if rdsNtf_timeoutMs is set to 0 */
        if (rdsNtf_timeoutMs != 0) {
            // status = waitforNotification(UWA_DM_PROP_SET_RDS_PARAM_NTF_EVT, rdsNtf_timeoutMs);
            uint8_t rds_param_ntf[10] = {0};
            uint32_t rds_param_ntf_len = sizeof(rds_param_ntf);

            void *scheduled_ntf = uwb_uci_schedule_packet_read(
                UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_PARAM_ID_SESSION_SET_RDS_PARAM_CMD_NTF, rds_param_ntf, &rds_param_ntf_len, &g_uwb_nxp_semaphore);
            if (NULL == scheduled_ntf) {
                LOG_ERR("Could not schedule packet read");
                k_sem_reset(&g_uwb_nxp_semaphore);
                return UWBAPI_STATUS_FAILED;
            }
            if (status != UWBAPI_STATUS_OK) {
                LOG_ERR("%s: Set RDS Param Notification time out", __FUNCTION__);
            }
            uwb_uci_remove_scheduled_packet(scheduled_ntf);
            k_sem_reset(&g_uwb_nxp_semaphore);
        }
    }
    else {
        LOG_ERR("%s: Set RDS Param Command failed status = 0x%X", __FUNCTION__, status);
    }

exit:
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

#endif // UWBFTR_TransitProp

#if UWBFTR_BlobParser

tUWBAPI_STATUS UwbApi_ConfigureData_iOS(uint8_t *pShareableData,
    uint16_t ShareableDataLength,
    phUwbProfileInfo_t *pProfileInfo,
    uint8_t noOfVendorAppParams,
    const UWB_VendorAppParams_List_t *VendorAppParams_List,
    uint8_t noOfDebugParams,
    const UWB_DebugParams_List_t *DebugParams_List)
{
    LOG_DBG("%s: enter", __FUNCTION__);
    tUWBAPI_STATUS status;

    if (pProfileInfo == NULL) {
        LOG_ERR("%s: pProfileInfo is invalid", __FUNCTION__);
        status = kUwb_StatusCode_InvalidArgument;
        goto exit;
    }
    if (pShareableData == NULL) {
        LOG_ERR("%s: pShareableData is invalid", __FUNCTION__);
        status = kUwb_StatusCode_InvalidArgument;
        goto exit;
    }

    if ((ShareableDataLength != TOTAL_PROFILE_BLOB_SIZE_v1_1) &&
        (ShareableDataLength != TOTAL_PROFILE_BLOB_SIZE_v1_0)) {
        LOG_ERR("%s: profile blob size should be %d or %d bytes",
            __FUNCTION__,
            TOTAL_PROFILE_BLOB_SIZE_v1_0,
            TOTAL_PROFILE_BLOB_SIZE_v1_1);
        status = kUwb_StatusCode_InvalidArgument;
        goto exit;
    }

    pProfileInfo->profileId = kUWB_Profile_1;

    status = UwbApi_SetProfileParams(pShareableData, ShareableDataLength, pProfileInfo);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_SetProfileParams failed");
        goto exit;
    }

    if ((noOfVendorAppParams != 0) && (VendorAppParams_List != NULL)) {
        status = UwbApi_SetVendorAppConfigs(pProfileInfo->sessionHandle, noOfVendorAppParams, VendorAppParams_List);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_SetVendorAppConfigs failed");
            goto exit;
        }
    }
    if ((noOfDebugParams != 0) && (DebugParams_List != NULL)) {
        status = UwbApi_SetDebugParams(pProfileInfo->sessionHandle, noOfDebugParams, DebugParams_List);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_SetDebugParams failed");
            goto exit;
        }
    }

    status = UwbApi_StartRangingSession(pProfileInfo->sessionHandle);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_StartRangingSession() Failed");
        goto exit;
    }
exit:
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

tUWBAPI_STATUS UwbApi_ConfigureData_Android(uint8_t *pUwbPhoneConfigData,
    uint16_t UwbPhoneConfigDataLen,
    phUwbProfileInfo_t *pProfileInfo,
    uint8_t noOfVendorAppParams,
    const UWB_VendorAppParams_List_t *VendorAppParams_List,
    uint8_t noOfDebugParams,
    const UWB_DebugParams_List_t *DebugParams_List)
{
    LOG_DBG("%s: enter", __FUNCTION__);
    tUWBAPI_STATUS status;
    uint32_t sessionHandle = 0;

    const uint8_t stsStatic[] = UWB_ANDROID_STATIC_STS;
    const uint8_t vendorId[]  = UWB_ANDROID_VENDOR_ID;

    phRangingParams_t inRangingParams = {0};
    UwbPhoneConfigData_t UwbPhoneConfig;
    UWB_AppParams_List_t SetAppParamsList[MAX_CONFIG_ID_NUM_CONFIGS];

    if (pUwbPhoneConfigData == NULL || pProfileInfo == NULL) {
        LOG_ERR("%s: Phone Config Data or profile info is invalid", __FUNCTION__);
        status = kUwb_StatusCode_InvalidArgument;
        goto exit;
    }

    if (UwbPhoneConfigDataLen == SHAREABLE_DATA_HEADER_LENGTH_ANDROID) {
        serializeUwbPhoneConfigData(&UwbPhoneConfig, pUwbPhoneConfigData);
    }
    else {
        LOG_ERR("%s: Phone Config Data length is invalid : %d", __FUNCTION__, UwbPhoneConfigDataLen);
        status = kUwb_StatusCode_InvalidArgument;
        goto exit;
    }

    status = UwbApi_SessionInit(UwbPhoneConfig.session_id, kUwb_SessionType_Ranging, &sessionHandle);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_SessionInit() Failed");
        goto exit;
    }

    pProfileInfo->sessionHandle = sessionHandle;
    LOG_WRN("CONFIG_ID_%d", UwbPhoneConfig.config_id);
    switch (UwbPhoneConfig.config_id) {
    case UWB_CONFIG_ID_1: {
        /**
         * +----------------------+------------------------------------+
         * | UWB Params           | CONFIG_ID_1 (0x01)                 |
         * +======================+====================================+
         * | Multinode Mode       | Unicast                            |
         * | STS                  | Static                             |
         * | Ranging Method       | DS-TWR Deferred mode               |
         * | Ranging Interval     | 240ms                              |
         * | AOA_RESULT_REQ       | 0x01 (Enabled)                     |
         * | Slot Duration        | 2400                               |
         * | Slots per RR         | 10                                 |
         * | STS IV               | 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 |
         * | Vendor ID            | 0x08, 0x07                         |
         * | Number of Controlees | 1                                  |
         * +----------------------+------------------------------------+
         */
        inRangingParams.multiNodeMode = kUWB_MultiNodeMode_UniCast;

        SetAppParamsList[0] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(RANGING_DURATION, 240);
        SetAppParamsList[1] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(AOA_RESULT_REQ, ENABLED);
        SetAppParamsList[2] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(SLOTS_PER_RR, 10);

    } break;

    case UWB_CONFIG_ID_2: {
        /**
         * +----------------------+------------------------------------+
         * | UWB Params           | CONFIG_ID_2 (0x02)                 |
         * +======================+====================================+
         * | Multinode Mode       | One to many                        |
         * | STS                  | Static                             |
         * | Ranging Method       | DS-TWR Deferred mode               |
         * | Ranging Interval     | 200ms                              |
         * | AOA_RESULT_REQ       | 0x01 (Enabled)                     |
         * | Slot Duration        | 2400                               |
         * | Slots per RR         | 10                                 |
         * | STS IV               | 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 |
         * | Vendor ID            | 0x08, 0x07                         |
         * | Number of Controlees | 1                                  |
         * +----------------------+------------------------------------+
         */
        inRangingParams.multiNodeMode = kUWB_MultiNodeMode_OnetoMany;

        SetAppParamsList[0] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(RANGING_DURATION, 200);
        SetAppParamsList[1] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(AOA_RESULT_REQ, ENABLED);
        SetAppParamsList[2] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(SLOTS_PER_RR, 10);

    } break;

    case UWB_CONFIG_ID_3: {
        /**
         * +----------------------+------------------------------------+
         * | UWB Params           | CONFIG_ID_3(0x03)                  |
         * +======================+====================================+
         * | Multinode Mode       | Unicast                            |
         * | STS                  | Static                             |
         * | Ranging Method       | DS-TWR Deferred mode               |
         * | Ranging Interval     | 240ms                              |
         * | AOA_RESULT_REQ       | 0x00 (Disabled)                    |
         * | Slot Duration        | 2400                               |
         * | Slots per RR         | 10                                 |
         * | STS IV               | 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 |
         * | Vendor ID            | 0x08, 0x07                         |
         * | Number of Controlees | 1                                  |
         * +----------------------+------------------------------------+
         */
        inRangingParams.multiNodeMode = kUWB_MultiNodeMode_UniCast;

        SetAppParamsList[0] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(RANGING_DURATION, 240);
        SetAppParamsList[1] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(AOA_RESULT_REQ, DISABLED);
        SetAppParamsList[2] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(SLOTS_PER_RR, 10);

    } break;

    default: {
        LOG_ERR("Config ID %d not supported", UwbPhoneConfig.config_id);
        status = UWBAPI_STATUS_FAILED;
        goto exit;
    } break;
    }

    /* Common configs across config IDs 1, 2 and 3*/
    SetAppParamsList[3] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(SLOT_DURATION, 2400);
    SetAppParamsList[4] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_ARRAY(STATIC_STS_IV, &stsStatic[0], sizeof(stsStatic)); // Android shows [1, 2, 3, 4, 5, 6]
    SetAppParamsList[5] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_ARRAY(VENDOR_ID, &vendorId[0], sizeof(vendorId)); // Android shows [7, 8]
    SetAppParamsList[6] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(PREAMBLE_CODE_INDEX, UwbPhoneConfig.preamble_id);
    SetAppParamsList[7] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(CHANNEL_NUMBER, UwbPhoneConfig.channel_number);
    SetAppParamsList[8] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_VALUE(NO_OF_CONTROLEES, 1);
    SetAppParamsList[9] = (UWB_AppParams_List_t)UWB_SET_APP_PARAM_ARRAY(DST_MAC_ADDRESS, UwbPhoneConfig.phone_mac_address, SHORT_MAC_ADDR_LEN);


    /* Set the Config_Id Parameters */
    status = UwbApi_SetAppConfigMultipleParams(
        pProfileInfo->sessionHandle, sizeof(SetAppParamsList) / sizeof(SetAppParamsList[0]), &SetAppParamsList[0]);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_SetAppConfigMultipleParams() Failed");
        goto exit;
    }

    switch (UwbPhoneConfig.device_ranging_role) {
    case UWB_DEVICE_CONTROLLER: {
        inRangingParams.deviceRole = kUWB_DeviceRole_Initiator;
        inRangingParams.deviceType = kUWB_DeviceType_Controller;
    } break;

    case UWB_DEVICE_CONTROLEE: {
        inRangingParams.deviceRole = kUWB_DeviceRole_Responder;
        inRangingParams.deviceType = kUWB_DeviceType_Controlee;
    } break;

    default: {
        LOG_ERR("Role not supported");
        status = UWBAPI_STATUS_FAILED;
        goto exit;
    } break;
    }

    inRangingParams.deviceMacAddr[0] = pProfileInfo->mac_addr[0];
    inRangingParams.deviceMacAddr[1] = pProfileInfo->mac_addr[1];

    inRangingParams.scheduledMode     = kUWB_ScheduledMode_TimeScheduled;
    inRangingParams.rangingRoundUsage = kUWB_RangingRoundUsage_DS_TWR;

    status = UwbApi_SetRangingParams(pProfileInfo->sessionHandle, &inRangingParams);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_SetRangingParams() Failed");
        goto exit;
    }

    if ((noOfVendorAppParams != 0) && (VendorAppParams_List != NULL)) {
        status = UwbApi_SetVendorAppConfigs(pProfileInfo->sessionHandle, noOfVendorAppParams, VendorAppParams_List);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_SetVendorAppConfigs failed");
            goto exit;
        }
    }

    if ((noOfDebugParams != 0) && (DebugParams_List != NULL)) {
        status = UwbApi_SetDebugParams(pProfileInfo->sessionHandle, noOfDebugParams, DebugParams_List);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("UwbApi_SetDebugParams failed");
            goto exit;
        }
    }

    status = UwbApi_StartRangingSession(pProfileInfo->sessionHandle);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_StartRangingSession() Failed");
        goto exit;
    }
exit:
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}

#endif // UWBFTR_BlobParser

#if UWBIOT_UWBD_SR2XXT

EXTERNC tUWBAPI_STATUS UwbApi_SetSecureCalibration(phSecureCalibParams_t *pSecureCalibParams)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen = 0;
    uint8_t response[20] = {0};
    uint32_t response_len = sizeof(response);


    LOG_DBG("%s: Enter", __FUNCTION__);

    if (NULL == pSecureCalibParams) {
        LOG_ERR("%s: pSecureCalibParams is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    if (FALSE == validateSecureCalibParamId(pSecureCalibParams->calibParamId)) {
        LOG_ERR("%s: Caliberation parameter is invalid", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    if (pSecureCalibParams->calibrationValue == NULL || pSecureCalibParams->length == 0) {
        LOG_ERR("%s: calibrationValue is 0x%p and length is %d", __FUNCTION__, pSecureCalibParams->calibrationValue, pSecureCalibParams->length);
        return kUwb_StatusCode_InvalidArgument;
    }

    cmdLen = serializeSetSecureCalibPayload(pSecureCalibParams, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_API_VENDOR_SET_SECURE_CALIBRATION, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_2, VENDOR_UCI_MSG_SET_SECURE_CALIBRATION,
                        uwbContext.snd_data, cmdLen, response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status == UWBAPI_STATUS_OK) {
        LOG_DBG("%s: Set Calibration successful", __FUNCTION__);
    }
    else {
        LOG_ERR(
            "%s: Set Calibration failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
    }

    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}
#endif // UWBIOT_UWBD_SR2XXT

#if UWBFTR_CSA
tUWBAPI_STATUS UwbApi_SessionSetLocZone(phSessionSetLocZone_t *pSetLocZone)
{
    tUWBAPI_STATUS status;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);
    uint16_t cmdLen = 0;

    if (NULL == pSetLocZone) {
        LOG_ERR("%s: pSetLocZone is NULL", __FUNCTION__);
        status = kUwb_StatusCode_InvalidArgument;
        goto exit;
    }

    cmdLen = serializeSessionSetLocZoneCmd(pSetLocZone, &uwbContext.snd_data[0]);
    // status = sendUciCommandAndWait(UWA_DM_API_SESSION_SET_LOCALIZATION_ZONE_EVT, cmdLen, uwbContext.snd_data);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY, EXT_UCI_MSG_SESSION_SET_LOCALIZATION_ZONE_CMD,
                        uwbContext.snd_data, cmdLen,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    status = response[UCI_HEADER_SIZE];
    if (UWBAPI_STATUS_OK != status) {
        LOG_ERR("%s: Session Set Localization Zone Failed!", __FUNCTION__);
        goto exit;
    }

exit:
    LOG_DBG("%s: Exit", __FUNCTION__);
    return status;
}

#endif // UWBFTR_CSA

#if UWBIOT_SESN_SNXXX
tUWBAPI_STATUS UwbApi_Se_GetSessionIdList(pSeGetSessionIdList_t *pSeGetSessionIdList)
{
    tUWBAPI_STATUS status;
    uint32_t index = 0;
    uint8_t response[20]  = {0};
    uint32_t response_len = sizeof(response);
    LOG_DBG("%s: Enter", __FUNCTION__);

    if (pSeGetSessionIdList == NULL) {
        LOG_ERR("%s: pSeGetSessionIdList is NULL", __FUNCTION__);
        return kUwb_StatusCode_InvalidArgument;
    }

    // status = sendUciCommandAndWait(UWA_DM_API_GET_ESE_SESSION_ID_LIST_EVT, 0, NULL);
    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_ESE_GET_SESSION_ID_LIST,
                        NULL, 0,
                        response, &response_len);
    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }
    uint8_t *rspData = &response[UCI_HEADER_SIZE];
    UWB_STREAM_TO_UINT8(status, rspData, index);

    if (status == UWBAPI_STATUS_OK) {
        uint8_t ese_session_id_list_ntf[10] = {0};
        uint32_t ese_session_id_list_ntf_len = sizeof(ese_session_id_list_ntf);

        void *scheduled_ntf = uwb_uci_schedule_packet_read(
            UCI_MT_NTF, UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_ESE_GET_SESSION_ID_LIST, ese_session_id_list_ntf, &ese_session_id_list_ntf_len, &g_uwb_nxp_semaphore);
        if (NULL == scheduled_ntf) {
            LOG_ERR("Could not schedule packet read");
            k_sem_reset(&g_uwb_nxp_semaphore);
            return UWBAPI_STATUS_FAILED;
        }
            if (status == UWBAPI_STATUS_OK) {
                /* Copy the number of Session Ids */
                UWB_STREAM_TO_UINT8(pSeGetSessionIdList->numberOfSessionIds, rspData, index)
                /* Check if the received number of session IDs can be accomodated the list of sessionIds */
                if (pSeGetSessionIdList->numberOfSessionIds <= MAX_SESSION_ID_LIST) {
                    /* Copy the List of SessionIds */
                    UWB_STREAM_TO_ARRAY(pSeGetSessionIdList->SessionIdList,
                        rspData,
                        (pSeGetSessionIdList->numberOfSessionIds * sizeof(uint32_t)),
                        index);
                }
                else {
                    LOG_ERR("%s Number of SessionIDs exceeds MAX_SESSION_ID_LIST : %d",
                        __FUNCTION__,
                        pSeGetSessionIdList->numberOfSessionIds);
                    status = UWBAPI_STATUS_FAILED;
                    uwb_uci_remove_scheduled_packet(scheduled_ntf);
                    k_sem_reset(&g_uwb_nxp_semaphore);
                    goto exit;
                }
            }
            else {
                LOG_ERR("%s GET_ESE_SESSION_ID_LIST_NTF Failed with status : 0x%X", __FUNCTION__, status);
                uwb_uci_remove_scheduled_packet(scheduled_ntf);
                k_sem_reset(&g_uwb_nxp_semaphore);
                goto exit;
            }
        uwb_uci_remove_scheduled_packet(scheduled_ntf);
        k_sem_reset(&g_uwb_nxp_semaphore);
    }
    else {
        LOG_ERR(
            "%s: sendUciCommandAndWait failed with status %s (0x%x)", __FUNCTION__, getStatusString(status), status);
        goto exit;
    }
exit:
    LOG_DBG("%s: exit status %d", __FUNCTION__, status);
    return status;
}
#endif // UWBIOT_SESN_SNXXX


tUWBAPI_STATUS UwbApi_EnableSessionSchedulingInfoNtf(
    uwb_session_scheduling_info_ntf_t *pSessionSchedulingInfoNtf)
{
    tUWBAPI_STATUS status;
    uint16_t cmdLen       = 0;
    uint8_t response[10]  = {0};
    uint32_t response_len = sizeof(response);

    LOG_DBG("%s: Enter", __FUNCTION__);

    if (uwbContext.isUfaEnabled == FALSE) {
        return UWBAPI_STATUS_NOT_INITIALIZED;
    }
    if (pSessionSchedulingInfoNtf == NULL) {
        return UWBAPI_STATUS_INVALID_PARAM;
    }

    cmdLen = serializeSessionEnableSessionSchedulingInfoNtf(
        pSessionSchedulingInfoNtf, &uwbContext.snd_data[0]);

    int ret = uwb_uci_transceive_control_packet(
        UCI_GID_PROPRIETARY_CUSTOM_2,
        VENDOR_UCI_MSG_ENABLE_SESSION_SCHEDULING_INFO_NTF_REQ_CMD,
        uwbContext.snd_data, cmdLen,
        response, &response_len);

    if (0 != ret) {
        LOG_ERR("%s: Could not transceive UCI packet", __FUNCTION__);
        return UWBAPI_STATUS_FAILED;
    }

    status = response[UCI_HEADER_SIZE];
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("%s: Enable Session Scheduling Info NTF REQ failed 0x%x",
            __FUNCTION__, status);
        return status;
    }

    LOG_DBG("%s: Exit status %d", __FUNCTION__, status);
    return status;
}
