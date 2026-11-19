/*
 *
 * Copyright 2018-2020,2022-2024,2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "PrintUtility.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_print_util_prop, LOG_LEVEL_INF);

EXTERNC void printDeviceInfo(const phUwbDevInfo_t *pdevInfo)
{
    if (pdevInfo != NULL) {
        LOG_DBG("UCI Generic Version            : %02X.%02X\n",
            pdevInfo->uciGenericMajor,
            pdevInfo->uciGenericMinorMaintenanceVersion);
        LOG_DBG("MAC Version                    : %02X.%02X\n",
            pdevInfo->macMajorVersion,
            pdevInfo->macMinorMaintenanceVersion);
        LOG_DBG("PHY Version                    : %02X.%02X\n",
            pdevInfo->phyMajorVersion,
            pdevInfo->phyMinorMaintenanceVersion);
        LOG_DBG("Device Name Length             : %d\n", pdevInfo->devNameLen);
        LOG_INF("Device Name                    : %s\n", pdevInfo->devName);
        LOG_INF(
            "Firmware Version               : %02X.%02X.%02X\n", pdevInfo->fwMajor, pdevInfo->fwMinor, pdevInfo->fwRc);
        LOG_DBG("Vendor UCI Version             : %02X.%02X.%02x\n",
            pdevInfo->vendorUciMajor,
            pdevInfo->vendorUciMinor,
            pdevInfo->vendorUciPatch);
        LOG_DBG("UWB Chip ID                    : %s\n", pdevInfo->uwbChipId);

        LOG_DBG(
            "Middleware Version             : %02X.%02X.%02X\n", pdevInfo->mwMajor, pdevInfo->mwMinor, pdevInfo->mwRc);

        LOG_DBG("Max PPM Value                  : %d\n", pdevInfo->maxPpmValue);

        LOG_DBG("TX Power Value                 : %d\n", pdevInfo->txPowerValue);

        LOG_DBG("FW Boot Mode                   : %d\n", pdevInfo->fwBootMode);

        LOG_DBG("Vendor UCI Test Version        : %02X.%02X.%02X\n",
            pdevInfo->uciTestMajor,
            pdevInfo->uciTestMinor,
            pdevInfo->uciTestPatch);

#if (UWBFTR_CCC)
        LOG_DBG("UCI CCC Version                    : %02x.%02x\n",
            pdevInfo->uciCccVersion[0],
            pdevInfo->uciCccVersion[1]);

        LOG_DBG("CCC Version                        : %s \n", pdevInfo->cccVersion);
#endif // (UWBFTR_CCC)
#if UWBFTR_CSA
        LOG_DBG("Aliro Spec Version                 : %s \n", pdevInfo->aliroSpecVersion);
#endif // UWBFTR_CSA

#if UWBIOT_UWBD_SR2XXT
        LOG_DBG("lifecycle                      : %x\n", pdevInfo->lifecycle);

        LOG_DBG("fwGitHash                      : %s\n", pdevInfo->fwGitHash);

#endif // UWBIOT_UWBD_SR2XXT
    }
}

#if (UWBIOT_SESN_SNXXX)
EXTERNC void printDoBindStatus(const phSeDoBindStatus_t *pDoBindStatus)
{
    if (pDoBindStatus != NULL) {
        LOG_DBG("pDoBindStatus->status                : 0x%0x \n", pDoBindStatus->status);
        LOG_DBG("pDoBindStatus->count_remaining       : 0x%0x \n", pDoBindStatus->count_remaining);
        LOG_DBG("pDoBindStatus->binding_state         : 0x%0x \n", pDoBindStatus->binding_state);
        LOG_DBG("pDoBindStatus->se_instruction_code   : 0x%0x \n", pDoBindStatus->se_instruction_code);
        LOG_DBG("pDoBindStatus->se_error_status       : 0x%0x \n", pDoBindStatus->se_error_status);
    }
    else {
        LOG_ERR("pDoBindStatus is NULL");
    }
}

EXTERNC void printGetBindingStatus(const phSeGetBindingStatus_t *pGetBindingStatus)
{
    if (pGetBindingStatus != NULL) {
        LOG_DBG("pGetBindingStatus->status                 : 0x%0x \n", pGetBindingStatus->status);
        LOG_DBG("pGetBindingStatus->se_binding_count       : 0x%0x \n", pGetBindingStatus->se_binding_count);
        LOG_DBG("pGetBindingStatus->uwbd_binding_count     : 0x%0x \n", pGetBindingStatus->uwbd_binding_count);
        LOG_DBG("pGetBindingStatus->se_instruction_code    : 0x%0x \n", pGetBindingStatus->se_instruction_code);
        LOG_DBG("pGetBindingStatus->se_error_status        : 0x%0x \n", pGetBindingStatus->se_error_status);
    }
    else {
        LOG_ERR("printGetBindingStatus is NULL");
    }
}

EXTERNC void printGetEseTestConnectivityStatus(const SeConnectivityStatus_t *pGetSeConnectivityStatus)
{
    if (pGetSeConnectivityStatus != NULL) {
        LOG_DBG("pGetSeConnectivityStatus->status                 : 0x%0x \n", pGetSeConnectivityStatus->status);
        LOG_DBG("pGetSeConnectivityStatus->se_instruction_code    : 0x%0x \n",
            pGetSeConnectivityStatus->se_instruction_code);
        LOG_DBG(
            "pGetSeConnectivityStatus->se_error_status        : 0x%0x \n", pGetSeConnectivityStatus->se_error_status);
    }
    else {
        LOG_ERR("printGetEseTestConnectivityStatus is NULL");
    }
}

#endif //(UWBIOT_SESN_SNXXX)

EXTERNC void printDistance_Aoa(const phRangingData_t *pRangingData)
{
    if (pRangingData != NULL) {
        LOG_DBG("--------------Received Range Data--------------\n");
        LOG_DBG("pRangingData->sessionHandle                     : %" PRIu32 " \n", pRangingData->sessionHandle);
        for (uint8_t i = 0; i < pRangingData->no_of_measurements; i++) {
#if UWBFTR_TWR // support only for DSTWR
            LOG_DBG("pRangingData->range_meas[%" PRIu8 "].status          : %" PRIu8 " \n",
                i,
                pRangingData->ranging_meas.range_meas_twr[i].status);
            if (pRangingData->ranging_meas.range_meas_twr[i].status == UWBAPI_STATUS_OK) {
                LOG_DBG("pRangingData->range_meas[%" PRIu16 "].distance        : %" PRIu16 " \n",
                    i,
                    pRangingData->ranging_meas.range_meas_twr[i].distance);
                LOG_DBG("pRangingData->range_meas[%" PRIu16 "].aoaFirst             : %" PRIu16 " \n",
                    i,
                    pRangingData->ranging_meas.range_meas_twr[i].aoa_elevation_FOM);
            }
#endif // UWBFTR_TWR // support only for DSTWR
        }
    }
    else {
        LOG_DBG("pRangingData is NULL");
    }
}

EXTERNC void printDebugParams(uint8_t noOfParams, const UWB_DebugParams_List_t *DebugParams_List)
{
    if (DebugParams_List != NULL) {
        for (uint8_t LoopCnt = 0; LoopCnt < noOfParams; LoopCnt++) {
            switch (DebugParams_List[LoopCnt].param_id) {
#if UWBIOT_UWBD_SR2XXT
            case kUWB_DBG_CFG_DATA_LOGGER_NTF:{
                LOG_HEXDUMP_DBG(DebugParams_List[LoopCnt].param_value.param.param_value,
                    DebugParams_List[LoopCnt].param_value.param.param_len,
                    "DebugParams_List->kUWB_DBG_CFG_DATA_LOGGER_NTF");
            } break;
#endif
            case kUWB_DBG_CFG_TEST_CONTENTION_RANGING_FEATURE:
                LOG_DBG("DebugParams_List->kUWB_DBG_CFG_TEST_CONTENTION_RANGING_FEATURE: 0x%02X",
                    DebugParams_List[LoopCnt].param_value.vu16);
                break;
            case kUWB_DBG_CFG_CIR_CAPTURE_WINDOW:
                LOG_DBG("DebugParams_List->kUWB_DBG_CFG_CIR_CAPTURE_WINDOW: 0x%04X",
                    DebugParams_List[LoopCnt].param_value.vu32);
                break;
            case kUWB_DBG_CFG_RANGING_TIMESTAMP_NTF:
                LOG_DBG("DebugParams_List->kUWB_DBG_CFG_RANGING_TIMESTAMP_NTF: 0x%02X",
                    DebugParams_List[LoopCnt].param_value.vu16);
                break;
            default:
                break;
            }
        }
    }
    else {
        LOG_DBG("DebugParams_List is NULL");
    }
}

#if UWBIOT_SESN_SNXXX

EXTERNC void printTestLoopNtfData(const phTestLoopData_t *pTestLoopData)
{
    if (pTestLoopData != NULL) {
        LOG_DBG("Status                        : %" PRIu8 " \n", pTestLoopData->status);
        LOG_DBG("Loop Count                    : %" PRIu8 " \n", pTestLoopData->loop_cnt);
        LOG_DBG("Loop Pass Count               : %" PRIu8 " \n", pTestLoopData->loop_pass_count);
    }
    else {
        LOG_DBG("pTestLoopData is NULL");
    }
}

#endif // UWBIOT_SESN_SNXXX

EXTERNC void printUwbWlanIndNtf(const UWB_Wlan_IndNtf_t *UWB_Wlan_IndNtf)
{
    if (UWB_Wlan_IndNtf != NULL) {
        LOG_DBG(
            "UWB_Wlan_IndNtf->.UWB_Wlan_IndNtf_status                : %x\n", UWB_Wlan_IndNtf->UWB_Wlan_IndNtf_status);
        LOG_DBG("UWB_Wlan_IndNtf_time_index            : %x\n", UWB_Wlan_IndNtf->UWB_Wlan_IndNtf_time_index);
        LOG_DBG(
            "UWB_Wlan_IndNtf_sessionHandle             : %x\n", UWB_Wlan_IndNtf->UWB_Wlan_IndNtf_sessionHandle);
    }
}

#if !(UWBIOT_UWBD_SR250 || UWBIOT_UWBD_SR150)
EXTERNC void printWlanUwbIndNtf(const Wlan_Uwb_IndNtf_t *pWlan_Uwb_IndNtf)
{
    if (pWlan_Uwb_IndNtf != NULL) {
        LOG_DBG("pWlan_Uwb_IndNtf->status     : %X", pWlan_Uwb_IndNtf->Wlan_Uwb_IndNtf_status);
        LOG_DBG("pWlan_Uwb_IndNtf->Wlan_Uwb_IndNtf_time_index : %X", pWlan_Uwb_IndNtf->Wlan_Uwb_IndNtf_time_index);
    }
}
#endif // !(UWBIOT_UWBD_SR250 || UWBIOT_UWBD_SR150)

 EXTERNC void printScheduleNtf(const uwb_session_scheduling_info_ntf_data_t *pSessionSchedulingInfoNtf)
 {
    if (pSessionSchedulingInfoNtf == NULL) {
        LOG_ERR("%s : pSessionSchedulingInfoNtf is NULL", __FUNCTION__);
        return;
    }

    LOG_DBG("Number of Reports : %u", pSessionSchedulingInfoNtf->uwb_number_of_reports);

    for (uint8_t i = 0; i < pSessionSchedulingInfoNtf->uwb_number_of_reports && i < MAX_SCHED_NTF_REPORTS; i++) {
        const uwb_session_scheduling_info_ntf_report_t *r = &pSessionSchedulingInfoNtf->reports[i];

        LOG_DBG("SessionHandle : 0x%X  SeqNum : 0x%X  Occupancy : %u",
            r->uwb_session_handle, r->uwb_sequence_number, r->uwb_occupancy_status);
        LOG_HEXDUMP_DBG(r->uwb_first_slot_start_time, 8, "    FirstSlotStart :");
        LOG_HEXDUMP_DBG(r->uwb_last_slot_end_time,    8, "    LastSlotEnd    :");
    }
 }

#if UWBFTR_TransitProp
EXTERNC void printSetRdsParamNtf(phSetRdsParamNtf_t *pSetRdsParamNtf)
{
    if (pSetRdsParamNtf != NULL) {
        LOG_DBG("Secure SessionId              : 0x%X", pSetRdsParamNtf->secureSessionId);
        LOG_DBG("Status                        : 0x%X", pSetRdsParamNtf->status);
    }
    else {
        LOG_ERR("%s : pSetRdsParamNtf is NULL", __FUNCTION__);
    }
}
#endif // UWBFTR_TransitProp
