/*
 *
 * Copyright 2018-2020,2022-2024,2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PRINT_UTILITY_PROPRIETARY_H
#define _PRINT_UTILITY_PROPRIETARY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <UwbApi_Types_Proprietary.h>

EXTERNC void printDistance_Aoa(const phRangingData_t *pRangingData);
EXTERNC void printDebugParams(uint8_t noOfParams, const UWB_DebugParams_List_t *DebugParams_List);
EXTERNC void printDeviceInfo(const phUwbDevInfo_t *pdevInfo);
#if (UWBIOT_SESN_SNXXX)
EXTERNC void printDoBindStatus(const phSeDoBindStatus_t *pDoBindStatus);
EXTERNC void printGetBindingStatus(const phSeGetBindingStatus_t *pGetBindingStatus);
EXTERNC void printGetEseTestConnectivityStatus(const SeConnectivityStatus_t *pGetSeConnectivityStatus);
// FIXME: SID, TestLoopNtf specific to SN110?
EXTERNC void printTestLoopNtfData(const phTestLoopData_t *pTestLoopData);
#endif //(UWBIOT_SESN_SNXXX)

EXTERNC void printUwbWlanIndNtf(const UWB_Wlan_IndNtf_t *UWB_Wlan_IndNtf);
EXTERNC void printWlanUwbIndNtf(const Wlan_Uwb_IndNtf_t *pWlan_Uwb_IndNtf);
EXTERNC void printScheduleNtf(const uwb_session_scheduling_info_ntf_data_t *pSessionSchedulingInfoNtf);
#if UWBFTR_TransitProp
EXTERNC void printSetRdsParamNtf(phSetRdsParamNtf_t *pSetRdsParamNtf);
#endif // UWBFTR_TransitProp
#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif
