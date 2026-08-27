/*
 *
 * Copyright 2018-2020,2023-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "PrintUtility.h"
#include "zephyr/uwb/uwb_types.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_print_util, LOG_LEVEL_INF);

EXTERNC void printGenericErrorStatus(const phGenericError_t *pGenericError)
{
    if (pGenericError != NULL) {
        LOG_INF("Status                        : %hu", pGenericError->status);
    }
}

EXTERNC void printUwbSessionData(const phUwbSessionsContext_t *pUwbSessionsContext)
{
    if (pUwbSessionsContext != NULL) {
        LOG_INF("Status                        : %" PRIu32 " ", pUwbSessionsContext->status);
        LOG_INF("Session Counter               : %d ", pUwbSessionsContext->sessioncnt);
        for (uint8_t i = 0; i < pUwbSessionsContext->sessioncnt; i++) {
            LOG_INF(
                "Session %d ID             : %" PRIu32 " ", i, pUwbSessionsContext->pUwbSessionData[i].sessionHandle);
            LOG_INF("Session %d Type           : %hu", i, pUwbSessionsContext->pUwbSessionData[i].session_type);
            LOG_INF("Session %d State          : %hu", i, pUwbSessionsContext->pUwbSessionData[i].session_state);
        }
    }
    else {
        LOG_ERR("pUwbSessionsContext is NULL");
    }
}

EXTERNC void printRangingParams(const phRangingParams_t *pRangingParams)
{
    if (pRangingParams != NULL) {
        LOG_DBG("pRangingParams->deviceType                    : %hu", pRangingParams->deviceType);
        LOG_DBG("pRangingParams->deviceRole                    : %hu", pRangingParams->deviceRole);
        LOG_DBG("pRangingParams->multiNodeMode                 : %hu", pRangingParams->multiNodeMode);
        LOG_DBG("pRangingParams->macAddrMode                   : %hu", pRangingParams->macAddrMode);
        LOG_DBG("pRangingParams->scheduledMode                 : %hu", pRangingParams->scheduledMode);
        LOG_DBG("pRangingParams->rangingRoundUsage             : %hu", pRangingParams->rangingRoundUsage);

        uint8_t addrLen = SHORT_MAC_ADDR_LEN;
        if (pRangingParams->macAddrMode != SHORT_MAC_ADDRESS_MODE) { // mac addr is of 2 or 8 bytes.
            addrLen = UWB_EXTENDED_MAC_ADDRESS_LEN;
        }
        LOG_HEXDUMP_DBG(pRangingParams->deviceMacAddr, addrLen, "pRangingParams->deviceMacAddr                 : ");
    }
    else {
        LOG_ERR("pRangingParams is NULL");
    }
}
/* clang-format off */
EXTERNC void printRangingData(const phRangingData_t *pRangingData)
{
    if (pRangingData != NULL) {
        LOG_DBG("--------------Received Range Data--------------");
        LOG_DBG("pRangingData->seq_ctr                             : %" PRIu32 " ", pRangingData->seq_ctr);
        LOG_DBG("pRangingData->sessionHandle                       : 0x%08X ", pRangingData->sessionHandle);
        LOG_DBG("pRangingData->rcr_indication                      : %hu", pRangingData->rcr_indication);
        LOG_DBG("pRangingData->curr_range_interval                 : %" PRIu32 " ", pRangingData->curr_range_interval);
        LOG_DBG("pRangingData->ranging_measure_type                : %hu", pRangingData->ranging_measure_type);
        LOG_DBG("pRangingData->mac_addr_mode_indicator             : %hu", pRangingData->mac_addr_mode_indicator);
        LOG_DBG("pRangingData->sessionHandle_of_primary_session    : 0x%x", pRangingData->sessionHandle_of_primary_session);
        LOG_DBG("pRangingData->no_of_measurements                  : %hu", pRangingData->no_of_measurements);
#if UWBIOT_UWBD_SR04X
        LOG_DBG("pRangingData->vs_length                  : %hu", pRangingData->vs_length);
        if (pRangingData->vs_length > 0) {
            LOG_DBG("pRangingData->antenna_info                    : %hu", pRangingData->antenna_info);
            LOG_DBG("pRangingData->rssi                            : %d.%d dBm", TO_Q_7_1(pRangingData->rssi) * 5);
            // Future parameters can be printed here
        }
#endif /* UWBIOT_UWBD_SR04X */

#if UWBFTR_TWR // support only for DSTWR
        if (pRangingData->ranging_measure_type == MEASUREMENT_TYPE_TWOWAY) {
            for (uint8_t i = 0; i < pRangingData->no_of_measurements; i++) {
                LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_twr[i].mac_addr,(pRangingData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE ? SHORT_MAC_ADDR_LEN : UWB_EXTENDED_MAC_ADDRESS_LEN), "pRangingData->range_meas.mac_addr           ");
                LOG_DBG("TWR[%d].status                            : 0x%x ", i, pRangingData->ranging_meas.range_meas_twr[i].status);
                if ((pRangingData->ranging_meas.range_meas_twr[i].status == UWBAPI_STATUS_OK) || (pRangingData->ranging_meas.range_meas_twr[i].status == UWBAPI_STATUS_OK_NEGATIVE_DISTANCE_REPORT)) {
                    LOG_DBG("TWR[%d].nLos                              : %hu", i, pRangingData->ranging_meas.range_meas_twr[i].nLos);

                    /* This is a good thing to report... so keep it under INFO Tag. */
                    LOG_INF("TWR[%" PRIu16 "].distance                          : %" PRIu16 "", i, pRangingData->ranging_meas.range_meas_twr[i].distance);
                    if (pRangingData->ranging_meas.range_meas_twr[i].status == UWBAPI_STATUS_OK_NEGATIVE_DISTANCE_REPORT) {
                        LOG_INF("TWR[%" PRIu16 "]  Negative Distance Reported", i);
                    }

                    LOG_DBG("TWR[%d].aoa_azimuth                       : %d.%d", i, TO_Q_9_7(pRangingData->ranging_meas.range_meas_twr[i].aoa_azimuth));
                    LOG_DBG("TWR[%d].aoa_azimuth_FOM                   : %d", i, pRangingData->ranging_meas.range_meas_twr[i].aoa_azimuth_FOM);
                    LOG_DBG("TWR[%d].aoa_elevation                     : %d.%d", i, TO_Q_9_7(pRangingData->ranging_meas.range_meas_twr[i].aoa_elevation));
                    LOG_DBG("TWR[%d].aoa_elevation_FOM                 : %d", i, pRangingData->ranging_meas.range_meas_twr[i].aoa_elevation_FOM);
                    LOG_DBG("TWR[%d].aoa_dest_azimuth                  : %d.%d", i, TO_Q_9_7(pRangingData->ranging_meas.range_meas_twr[i].aoa_dest_azimuth));
                    LOG_DBG("TWR[%d].aoa_dest_azimuth_FOM              : %d", i, pRangingData->ranging_meas.range_meas_twr[i].aoa_dest_azimuth_FOM);
                    LOG_DBG("TWR[%d].aoa_dest_elevation                : %d.%d", i, TO_Q_9_7(pRangingData->ranging_meas.range_meas_twr[i].aoa_dest_elevation));
                    LOG_DBG("TWR[%d].aoa_dest_elevation_FOM            : %d", i, pRangingData->ranging_meas.range_meas_twr[i].aoa_dest_elevation_FOM);
                    LOG_DBG("TWR[%d].slot_index                        : %d", i, pRangingData->ranging_meas.range_meas_twr[i].slot_index);
                    LOG_DBG("TWR[%d].rssi                              : %d.%d dBm", i, TO_Q_7_1(pRangingData->ranging_meas.range_meas_twr[i].rssi) * 5);
                }
            }
#if !(UWBIOT_UWBD_SR04X)
            if (pRangingData->vs_length != FALSE) {
                LOG_DBG("TWR.vs_length                            : %d ", pRangingData->vs_length);
                LOG_DBG("TWR.vs_data_type                         : %x ", pRangingData->vs_data_type);
                if(pRangingData->vs_data_type == NXP_SPECIFIC_DATA_TYPE_WITH_MSG_CNTRL){
                    LOG_DBG("TWR.Message control                   : 0x%08x",pRangingData->message_control);
                }
                LOG_DBG("TWR.wifiCoExStatus                       : %d", pRangingData->vs_data.twr.wifiCoExStatus);
                if(pRangingData->vs_data.twr.isTxAntInfoPreset){
                    LOG_DBG("TWR.txAntennaInfo                    : %d", pRangingData->vs_data.twr.txAntennaInfo);
                }
                LOG_DBG("TWR.rxMode                               : %d", pRangingData->vs_data.twr.rxInfoMesr_twr.rxMode);
                LOG_DBG("TWR.num_of_rx_antennaRxInfo              : %d", pRangingData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo);
                if(pRangingData->vs_data.twr.isRxAntDebugInfoPresent){
                    LOG_DBG("TWR.numOfRframes                         : %d",pRangingData->vs_data.twr.rxInfoDebugNtf_twr.numOfRframes);
                }
                else{
                    LOG_DBG("TWR.rxModeDebugNtf                   : %d",pRangingData->vs_data.twr.rxInfoDebugNtf_twr.rxModeDebugNtf);
                }
                LOG_DBG("TWR.num_of_rx_antennaDebugNtf            : %d",pRangingData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf);
                if (pRangingData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo != FALSE) {
                    for (int j = 0; j < pRangingData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo; j++) {
                        LOG_DBG("TWR.rx_antennaIdRxInfo                   : %d", pRangingData->vs_data.twr.rxInfoMesr_twr.rx_antennaIdRxInfo[j]);
                    }
                }
                if (pRangingData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf != FALSE) {
                    for (int k = 0; k < pRangingData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf; k++) {
                        LOG_DBG("TWR.rx_antennaIdDebugNtf[%d]              : %d", k, pRangingData->vs_data.twr.rxInfoDebugNtf_twr.rx_antennaIdDebugNtf[k]);
                    }
                }
                for (uint8_t i = 0; i < pRangingData->no_of_measurements; i++) {
                    LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_twr[i].mac_addr,(pRangingData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE ? SHORT_MAC_ADDR_LEN : UWB_EXTENDED_MAC_ADDRESS_LEN), "Vendor Specific info for responder.mac_addr ");
                    if (pRangingData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf != FALSE) {
                        for (int j = 0; j < pRangingData->vs_data.twr.rxInfoMesr_twr.num_of_rx_antennaRxInfo; j++) {
                            LOG_DBG("TWR[%d].angleOfArrival[%d]                 : %d.%d", i, j, TO_Q_9_7(pRangingData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].angleOfArrival));
                            LOG_DBG("TWR[%d].pdoa[%d]                           : %d.%d", i, j, TO_Q_9_7(pRangingData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].pdoa));
                            LOG_DBG("TWR[%d].pdoaIndex[%d]                      : %d",i, j, pRangingData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].pdoaIndex);
#if UWBFTR_AoA_FoV
                            if(pRangingData->vs_data_type == FOV_SPECIFIC_DATA_TYPE)
                            {
                                LOG_DBG("TWR[%d].aoaFovFlag[%d]                    : %d ",i, j, pRangingData->vs_data.twr.vsMesr[i].aoaPdoaMesr_twr[j].aoaFovFlag);
                            }
#endif // UWBFTR_AoA_FoV
                        }
                    }
                    if (pRangingData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf != FALSE) {
                        for (int k = 0; k < pRangingData->vs_data.twr.rxInfoDebugNtf_twr.num_of_rx_antennaDebugNtf; k++) {
                            LOG_DBG("TWR[%d].rxSnrFirstPath[%d]                 : %d", i, k, pRangingData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rxSnrFirstPath);
                            LOG_DBG("TWR[%d].rxSnrMainPath[%d]                  : %d", i, k, pRangingData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rxSnrMainPath);
                            LOG_DBG("TWR[%d].rx_FirstPathIndex[%d]              : %d.%d", i, k, TO_Q_6_10(pRangingData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rx_FirstPathIndex));
                            LOG_DBG("TWR[%d].rx_MainPathIndex[%d]               : %d.%d", i, k, TO_Q_6_10(pRangingData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rx_MainPathIndex));
                        if(pRangingData->vs_data.twr.isRxAntDebugInfoPresent){
                            LOG_DBG("TWR[%d].snrTotal[%d]                       : %d.%d", i, k, TO_Q_8_8(pRangingData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].snrTotal));
                            LOG_DBG("TWR[%d].rssi[%d]                           : %d.%d", i, k, TO_Q_8_8(pRangingData->vs_data.twr.vsMesr[i].snrPathIndexMesr_twr[k].rssi));
                        }
                        }
                    }
                    if ((pRangingData->vs_data.twr.rxInfoMesr_twr.rxMode == kUWBAntCfgRxMode_ToA_Rfm_Mode) || (pRangingData->vs_data.twr.rxInfoMesr_twr.rxMode == kUWBAntCfgRxMode_AoA_Rfm_Mode)) {
                        LOG_DBG("TWR[%d].distance_2                        : %d", i, pRangingData->vs_data.twr.vsMesr[i].distance_2);
                    }
                    if(pRangingData->vs_data.twr.isDistanceMmPresent){
                        LOG_DBG("TWR[%d].distance_mm                        : %d", i, pRangingData->vs_data.twr.vsMesr[i].distance_mm);
                    }
                }
            }
#endif //!(UWBIOT_UWBD_SR04X)
        }
#endif //UWBFTR_TWR

#if UWBFTR_UL_TDoA_Anchor
        if (pRangingData->ranging_measure_type == MEASUREMENT_TYPE_ONEWAY) {
            for (int i = 0; i < pRangingData->no_of_measurements; i++) {
                LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_tdoa[i].mac_addr, (pRangingData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE ? SHORT_MAC_ADDR_LEN : UWB_EXTENDED_MAC_ADDRESS_LEN), "pRangingData->range_meas.mac_addr       ");
                LOG_DBG("TDoA[%d].status                       : %d", i, pRangingData->ranging_meas.range_meas_tdoa[i].status);
                LOG_DBG("TDoA[%d].message_control              : %d",
                    i,
                    pRangingData->ranging_meas.range_meas_tdoa[i].message_control);
                LOG_DBG(
                    "TDoA[%d].frame_type                   : %s", i, (pRangingData->ranging_meas.range_meas_tdoa[i].frame_type == 1) ? "sync" : "blink");
                LOG_DBG(
                    "TDoA[%d].nLos                         : %d", i, pRangingData->ranging_meas.range_meas_tdoa[i].nLos);
                LOG_DBG("TDoA[%" PRIi16 "].aoa_azimuth         : %d.%d",
                    i,
                    TO_Q_9_7(pRangingData->ranging_meas.range_meas_tdoa[i].aoa_azimuth));
                LOG_DBG("TDoA[%d].aoa_azimuth_FOM              : %d",
                    i,
                    pRangingData->ranging_meas.range_meas_tdoa[i].aoa_azimuth_FOM);
                LOG_DBG("TDoA[%" PRIi16 "].aoa_elevation       : %d.%d",
                    i,
                    TO_Q_9_7(pRangingData->ranging_meas.range_meas_tdoa[i].aoa_elevation));
                LOG_DBG("TDoA[%d].aoa_elevation_FOM            : %d",
                    i,
                    pRangingData->ranging_meas.range_meas_tdoa[i].aoa_elevation_FOM);
                LOG_DBG("TDoA[%d].frame_number                 : %" PRIu32 " ",
                    i,
                    pRangingData->ranging_meas.range_meas_tdoa[i].frame_number);
                LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_tdoa[i].rx_timestamp, ULTDOA_64BIT_IN_BYTES, "TDoA.rx_timestamp                       :");
                LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_tdoa[i].ul_tdoa_device_id, ULTDOA_64BIT_IN_BYTES, "TDoA.ul_tdoa_device_id                  :");
                LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_tdoa[i].tx_timestamp, ULTDOA_64BIT_IN_BYTES, "TDoA.tx_timestamp                       :");
            }
#if !(UWBIOT_UWBD_SR04X)
            if (pRangingData->vs_length != FALSE) {
                LOG_DBG("TDoA.vs_length                    : %d ", pRangingData->vs_length);
                LOG_DBG("TDoA.vendorExtLength              : %d ", pRangingData->vs_data.tdoa.vendorExtLength);
                LOG_DBG("TDoA.rssi_rx1                     : %d.%d", TO_Q_8_8(pRangingData->vs_data.tdoa.rssi_rx1));
                LOG_DBG("TDoA.rssi_rx2                     : %d.%d", TO_Q_8_8(pRangingData->vs_data.tdoa.rssi_rx2));
                LOG_DBG("TDoA.noOfPdoaMeasures             : %d", pRangingData->vs_data.tdoa.noOfPdoaMeasures);
                if (pRangingData->vs_data.tdoa.noOfPdoaMeasures != FALSE) {
                    for (uint8_t j = 0; j < pRangingData->vs_data.tdoa.noOfPdoaMeasures; j++) {
                        LOG_DBG("TDoA.pdoaFirst[%d]                : %d.%d", j, TO_Q_9_7(pRangingData->vs_data.tdoa.pdoa[j]));
                    }
                }
                if (pRangingData->vs_data.tdoa.noOfPdoaMeasures != FALSE) {
                    for (int j = 0; j < pRangingData->vs_data.tdoa.noOfPdoaMeasures; j++) {
                        LOG_DBG("TDoA.pdoaFirstIndex[%d]           : %d", j, pRangingData->vs_data.tdoa.pdoaIndex[j]);
                    }
                }
#if UWBIOT_UWBD_SR2XXT
                LOG_DBG("TDoA.message_control_extension    : %d ", pRangingData->vs_data.tdoa.message_control_extension);
                LOG_DBG("TDoA.rx3_ext_info_len             : %d", pRangingData->vs_data.tdoa.rx3_ext_info_len);
                LOG_DBG("TDoA.rssi_rx3                     : %d.%d", TO_Q_8_8(pRangingData->vs_data.tdoa.rssi_rx3));
#endif //UWBIOT_UWBD_SR2XXT
            LOG_DBG("pRangingData->antenna_pairInfo    : 0x%X ", pRangingData->antenna_pairInfo);
            LOG_DBG("pRangingData->wifiCoExStatusCode  : %d", pRangingData->wifiCoExStatusCode);
            }
#endif //!(UWBIOT_UWBD_SR04X)
        }

#endif //UWBFTR_UL_TDoA_Anchor
#if UWBFTR_DL_TDoA_Tag
        if (pRangingData->ranging_measure_type == MEASUREMENT_TYPE_DLTDOA_V1) {
            for (uint8_t i = 0; i < pRangingData->no_of_measurements; i++) {
                if (pRangingData->ranging_meas.range_meas_dltdoa[i].status == kUci_Status_Ok) {
                    LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_dltdoa[i].mac_addr,
                        (pRangingData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE ? SHORT_MAC_ADDR_LEN : UWB_EXTENDED_MAC_ADDRESS_LEN),
                        "pRangingData->range_meas.mac_addr        :");

                    LOG_DBG("DLTDoA[%d].status              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].status);

                    LOG_DBG("DLTDoA[%d].message_type              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].message_type);

                    LOG_DBG("DLTDoA[%d].message_control              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].message_control);

                    LOG_DBG("DLTDoA[%d].block_index              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].block_index);

                    LOG_DBG("DLTDoA[%d].round_index              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].round_index);

                    LOG_DBG(
                        "DLTDoA[%d].nLoS              : 0x%x\n", i, pRangingData->ranging_meas.range_meas_dltdoa[i].nLoS);

                    LOG_DBG("DLTDoA[%d].aoa_azimuth             : %d.%d\n",
                        i,
                        TO_Q_9_7(pRangingData->ranging_meas.range_meas_dltdoa[i].aoa_azimuth));

                    LOG_DBG("DLTDoA[%d].aoa_azimuth_fom             : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].aoa_azimuth_fom);

                    LOG_DBG("DLTDoA[%d].aoa_elevation            : %d.%d\n",
                        i,
                        TO_Q_9_7(pRangingData->ranging_meas.range_meas_dltdoa[i].aoa_elevation));

                    LOG_DBG("DLTDoA[%d].aoa_elevation_fom            : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].aoa_elevation_fom);

                    LOG_DBG(
                        "DLTDoA[%d].rssi              : 0x%d.%d dBm\n", i, TO_Q_7_1(pRangingData->ranging_meas.range_meas_dltdoa[i].rssi) * 5);

                    LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_dltdoa[i].tx_timestamp,
                        MAX_RX_TX_TIMESTAMP, "pRangingData->range_meas.tx_timestamp        :");

                    LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_dltdoa[i].rx_timestamp,
                        MAX_RX_TX_TIMESTAMP, "pRangingData->range_meas.rx_timestamp        :");

                    LOG_DBG("DLTDoA[%d].cfo_anchor              : %d.%d\n",
                        i,
                        TO_Q_6_10(pRangingData->ranging_meas.range_meas_dltdoa[i].cfo_anchor));

                    LOG_DBG("DLTDoA[%d].cfo              : %d.%d\n",
                        i,
                        TO_Q_6_10(pRangingData->ranging_meas.range_meas_dltdoa[i].cfo));

                    LOG_DBG("DLTDoA[%d].reply_time_initiator              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].reply_time_initiator);

                    LOG_DBG("DLTDoA[%d].reply_time_responder              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].reply_time_responder);

                    LOG_DBG("DLTDoA[%d].initiator_responder_tof              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa[i].initiator_responder_tof);
                }
            }
            LOG_DBG("pRangingData->wifiCoExStatusCode                    : %d ", pRangingData->wifiCoExStatusCode);
            LOG_DBG("pRangingData->antenna_pairInfo                    : %" PRIu32 " ", pRangingData->antenna_pairInfo);
        }

        if (pRangingData->ranging_measure_type == MEASUREMENT_TYPE_DLTDOA_V2) {
            for (uint8_t i = 0; i < pRangingData->no_of_measurements; i++) {
                if (pRangingData->ranging_meas.range_meas_dltdoa_v2[i].status == kUci_Status_Ok) {
                    LOG_DBG("DLTDoA[%d].measurement_size              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].measurement_size);

                    LOG_MAU8_D("pRangingData->range_meas.mac_addr        :",
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].mac_addr,
                        (pRangingData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE ? SHORT_MAC_ADDR_LEN : EXT_MAC_ADDR_LEN));

                    LOG_DBG("DLTDoA[%d].status              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].status);

                    LOG_DBG("DLTDoA[%d].message_type              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].message_type);

                    LOG_DBG("DLTDoA[%d].block_index              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].block_index);

                    LOG_DBG("DLTDoA[%d].round_index              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].round_index);

                    LOG_DBG(
                        "DLTDoA[%d].nLoS              : 0x%x\n", i, pRangingData->ranging_meas.range_meas_dltdoa_v2[i].nLoS);

                    LOG_DBG("DLTDoA[%d].aoa_azimuth             : %d.%d\n",
                        i,
                        TO_Q_9_7(pRangingData->ranging_meas.range_meas_dltdoa_v2[i].aoa_azimuth));

                    LOG_DBG("DLTDoA[%d].aoa_azimuth_fom             : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].aoa_azimuth_fom);

                    LOG_DBG("DLTDoA[%d].aoa_elevation            : %d.%d\n",
                        i,
                        TO_Q_9_7(pRangingData->ranging_meas.range_meas_dltdoa_v2[i].aoa_elevation));

                    LOG_DBG("DLTDoA[%d].aoa_elevation_fom            : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].aoa_elevation_fom);

                    LOG_DBG(
                        "DLTDoA[%d].rssi              : 0x%d.%d dBm\n", i, TO_Q_7_1(pRangingData->ranging_meas.range_meas_dltdoa_v2[i].rssi) * 5);


                    LOG_DBG("DLTDoA[%d].cfo_anchor              : %d.%d\n",
                        i,
                        TO_Q_6_10(pRangingData->ranging_meas.range_meas_dltdoa_v2[i].cfo_anchor));

                    LOG_DBG("DLTDoA[%d].cfo              : %d.%d\n",
                        i,
                        TO_Q_6_10(pRangingData->ranging_meas.range_meas_dltdoa_v2[i].cfo));

                    LOG_DBG("DLTDoA[%d].reply_time_initiator              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].reply_time_initiator);

                    LOG_DBG("DLTDoA[%d].reply_time_responder              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].reply_time_responder);

                    LOG_DBG("DLTDoA[%d].initiator_responder_tof              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].initiator_responder_tof);

                    LOG_DBG("DLTDoA[%d].rx_timestamp_length              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].rx_timestamp_length);

                    LOG_MAU8_D("pRangingData->range_meas.rx_timestamp        :",
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].rx_timestamp,
                        MAX_RX_TX_TIMESTAMP);

                    LOG_DBG("DLTDoA[%d].message_control              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].message_control);

                    LOG_DBG("DLTDoA[%d].tx_timestamp_length              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].tx_timestamp_length);

                    LOG_MAU8_D("pRangingData->range_meas.tx_timestamp        :",
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].tx_timestamp,
                        MAX_RX_TX_TIMESTAMP);

                    LOG_DBG("DLTDoA[%d].active_ranging_rounds_length              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].active_ranging_rounds_length);

                    LOG_MAU8_D("pRangingData->range_meas.active_ranging_rounds        :",
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].active_ranging_rounds,
                        MAX_ACTIVE_RR_V2);

                    LOG_DBG("DLTDoA[%d].anchor_location_length              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].anchor_location_length);

                    LOG_MAU8_D("pRangingData->range_meas.anchor_location        :",
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].anchor_location,
                        MAX_ANCHOR_LOCATIONS_V2);

                    LOG_DBG("DLTDoA[%d].supercluster_id              : 0x%x\n",
                        i,
                        pRangingData->ranging_meas.range_meas_dltdoa_v2[i].supercluster_id);
                }
            }
            LOG_DBG("pRangingData->wifiCoExStatusCode                    : %d ", pRangingData->wifiCoExStatusCode);
            LOG_DBG("pRangingData->antenna_pairInfo                    : %" PRIu32 " ", pRangingData->antenna_pairInfo);
        }
#endif //UWBFTR_DL_TDoA_Tag
#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
        /**
         * Below fields are applicable for Observer side .
        */
        if (pRangingData->ranging_measure_type == MEASUREMENT_TYPE_OWR_WITH_AOA) {
            for (int i = 0; i < pRangingData->no_of_measurements; i++) {
                LOG_HEXDUMP_DBG(pRangingData->ranging_meas.range_meas_owr_aoa[i].mac_addr, (pRangingData->mac_addr_mode_indicator == SHORT_MAC_ADDRESS_MODE ? SHORT_MAC_ADDR_LEN : UWB_EXTENDED_MAC_ADDRESS_LEN), "OWR.mac_addr                          ");

                LOG_DBG("OWR[%d].status                            : 0x%x\n", i, pRangingData->ranging_meas.range_meas_owr_aoa[i].status);
                LOG_DBG("OWR[%d].nLos                              : 0x%x\n", i, pRangingData->ranging_meas.range_meas_owr_aoa[i].nLos);
                LOG_DBG("OWR[%d].frame_seq_num                     : 0x%x\n", i, pRangingData->ranging_meas.range_meas_owr_aoa[i].frame_seq_num);
                LOG_DBG("OWR[%d].block_index                       : %d\n", i, pRangingData->ranging_meas.range_meas_owr_aoa[i].block_index);
                LOG_DBG("OWR[%d].aoa_azimuth                       : %d.%d\n", i, TO_Q_9_7(pRangingData->ranging_meas.range_meas_owr_aoa[i].aoa_azimuth));
                LOG_DBG("OWR[%d].aoa_azimuth_FOM                   : 0x%x\n", i, pRangingData->ranging_meas.range_meas_owr_aoa[i].aoa_azimuth_FOM);
                LOG_DBG("OWR[%d].aoa_elevation                     : %d.%d\n", i, TO_Q_9_7(pRangingData->ranging_meas.range_meas_owr_aoa[i].aoa_elevation));
                LOG_DBG("OWR[%d].aoa_elevation_FOM                 : 0x%x\n", i, pRangingData->ranging_meas.range_meas_owr_aoa[i].aoa_elevation_FOM);
            }
            if (pRangingData->vs_length != FALSE) {
                LOG_DBG("OWR.vs_length                             : %d \n", pRangingData->vs_length);
                LOG_DBG("OWR.vs_data_type                          : %d \n", pRangingData->vs_data_type);
                LOG_DBG("OWR.rxMode                                : %d \n", pRangingData->vs_data.owr_aoa.rxInfoMesr_owr.rxMode);
                LOG_DBG("OWR.num_of_rx_antennaRxInfo               : %d \n", pRangingData->vs_data.owr_aoa.rxInfoMesr_owr.num_of_rx_antennaRxInfo);
                for (int i = 0; i < pRangingData->no_of_measurements; i++) {
                    if (pRangingData->vs_data.owr_aoa.rxInfoMesr_owr.num_of_rx_antennaRxInfo != FALSE) {
                        for (int m = 0; m < pRangingData->vs_data.owr_aoa.rxInfoMesr_owr.num_of_rx_antennaRxInfo; m++) {
                            LOG_DBG("OWR[%d].rxantennaIdRxInfo[%d]             : %d \n", i, m, pRangingData->vs_data.owr_aoa.rxInfoMesr_owr.rx_antennaIdRxInfo[m]);
                            LOG_DBG("OWR[%d].angleOfArrival[%d]                : %d.%d \n", i, m, TO_Q_9_7(pRangingData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[m].angleOfArrival));
                            LOG_DBG("OWR[%d].pdoa[%d]                          : %d.%d \n", i, m, TO_Q_9_7(pRangingData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[m].pdoa));
                            LOG_DBG("OWR[%d].pdoaIndex[%d]                     : %d \n", i, m, pRangingData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[m].pdoaIndex);
#if UWBIOT_UWBD_SR150
                            if(pRangingData->vs_data_type == FOV_SPECIFIC_DATA_TYPE)
                            {
                                LOG_DBG("OWR[%d].aoaFovFlag[%d]                    : %d ", i, m, pRangingData->vs_data.owr_aoa.vsMesr[i].aoaPdoaMesr_owr[m].aoaFovFlag);
                            }
#endif // UWBIOT_UWBD_SR150
                        }
                    }
                    LOG_DBG("OWR[%d].rssi                              : %d.%d \n", i, TO_Q_8_8(pRangingData->vs_data.owr_aoa.vsMesr[i].rssi));
                }
            }
        }
#endif //(UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
#if !(UWBIOT_UWBD_SR04X)
    LOG_DBG("pRangingData->authInfoPrsen      : %d\n ", pRangingData->authInfoPrsen);
        if (pRangingData->authInfoPrsen != FALSE) {
                    LOG_HEXDUMP_DBG(pRangingData->authenticationTag, AUTH_TAG_IN_16BYTES, "pRangingData->authenticationTag   : ");
        }
#endif //!(UWBIOT_UWBD_SR04X)
    }
    else {
        LOG_DBG("pRangingData is NULL");
    }
}
/* clang-format on */

#if UWBFTR_DataTransfer
EXTERNC void printTransmitStatus(const phUwbDataTransmit_t *pTransmitNtfContext)
{
    if (pTransmitNtfContext != NULL) {
        LOG_INF("pTransmitNtfContext->transmitNtf_connectionId       : 0%x\n",
            pTransmitNtfContext->transmitNtf_connectionId);
        LOG_INF("pTransmitNtfContext->transmitNtf_sequence_number     : %d\n",
            pTransmitNtfContext->transmitNtf_sequence_number);
        LOG_INF(
            "pTransmitNtfContext->transmitNtf_status              : %d\n", pTransmitNtfContext->transmitNtf_status);
#if UWBIOT_UWBD_SR1XXT_SR2XXT
        LOG_INF(
            "pTransmitNtfContext->transmitNtf_txcount             : %d\n", pTransmitNtfContext->transmitNtf_txcount);
#endif /* (UWBIOT_UWBD_SR04X) */
    }
    else {
        LOG_ERR("pTransmitNtfContext is NULL");
    }
}
#endif // UWBFTR_DataTransfer

#if UWBFTR_Radar

EXTERNC void printRadarRecvNtf(const phUwbRadarNtf_t *pRcvRadaNtfPkt)
{
    if (pRcvRadaNtfPkt != NULL) {
        LOG_DBG("pRcvRadaNtfPkt->sessionHandle          : 0x%x\n", pRcvRadaNtfPkt->sessionHandle);
        LOG_DBG("pRcvRadaNtfPkt->radar_status          : 0x%x\n", pRcvRadaNtfPkt->radar_status);
        LOG_DBG("pRcvRadaNtfPkt->radar_type          : 0x%x\n", pRcvRadaNtfPkt->radar_type);
        LOG_DBG("pRcvRadaNtfPkt->num_cirs          : 0x%x\n", pRcvRadaNtfPkt->radar_ntf.radr_cir.num_cirs);
        LOG_DBG("pRcvRadaNtfPkt->cir_taps          : 0x%x\n", pRcvRadaNtfPkt->radar_ntf.radr_cir.cir_taps);
        LOG_DBG("pRcvRadaNtfPkt->rfu          : 0x%x\n", pRcvRadaNtfPkt->radar_ntf.radr_cir.rfu);
        LOG_DBG("pRcvRadaNtfPkt->len          : 0x%x\n", pRcvRadaNtfPkt->radar_ntf.radr_cir.cir_len);
        LOG_HEXDUMP_DBG(pRcvRadaNtfPkt->radar_ntf.radr_cir.cirdata,
            pRcvRadaNtfPkt->radar_ntf.radr_cir.cir_len, "pRcvRadaNtfPkt->CIRDATA");
    }
    else {
        LOG_ERR("pRcvRadaNtfPkt is NULL");
    }
}

EXTERNC void printRadarTestIsoNtf(const phUwbRadarNtf_t *pRcvRadaTstNtfPkt)
{
    if (pRcvRadaTstNtfPkt != NULL) {
        LOG_INF("sessionHandle          : 0x%x\n", pRcvRadaTstNtfPkt->sessionHandle);
        LOG_INF("radar_status        : 0x%x\n", pRcvRadaTstNtfPkt->radar_status);
        LOG_INF("radar_type          : 0x%x\n", pRcvRadaTstNtfPkt->radar_type);
        LOG_INF("antenna_tx          : 0x%x\n", pRcvRadaTstNtfPkt->radar_ntf.radar_tst_ntf.antenna_tx);
        LOG_INF("antenna_rx          : 0x%x\n", pRcvRadaTstNtfPkt->radar_ntf.radar_tst_ntf.antenna_rx);
        LOG_INF("anteena_isolation   : 0x%x\n", pRcvRadaTstNtfPkt->radar_ntf.radar_tst_ntf.anteena_isolation);
    }
    else {
        LOG_ERR("pRcvRadaNtfPkt is NULL");
    }
}

EXTERNC void printRadarPresenceDetctionNtf(const phUwbRadarNtf_t *pRcvRadarPresenceNtfPkt)
{
    if (pRcvRadarPresenceNtfPkt != NULL) {
        LOG_INF("sessionHandle           : 0x%x\n", pRcvRadarPresenceNtfPkt->sessionHandle);
        LOG_INF("radar_status            : 0x%x\n", pRcvRadarPresenceNtfPkt->radar_status);
        LOG_INF("radar_type              : 0x%x\n", pRcvRadarPresenceNtfPkt->radar_type);
        LOG_INF("presence_detected: %s:%d\n",
            ((pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.presence_detected) & 0x01) ? "Yes" : "No",
            pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.presence_detected);
        LOG_INF("presence_detection_mode : 0x%x\n",
            pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.presence_detection_mode);
        LOG_INF("number_of_detections : 0x%x\n",
            pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.number_of_detections);
        for (uint8_t i = 0; i < pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.number_of_detections;
             i++) {
            LOG_INF("Target[%d]:detection_distance      : %d cm\n",
                i,
                pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.detection_distance[i]);
            LOG_INF("Target[%d]:detection_aoa           : %d degrees\n",
                i,
                pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.detection_aoa[i]);
            LOG_INF("Target[%d]:detection_track_id      : 0x%x\n",
                i,
                pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.detection_track_id[i]);
            LOG_INF("Target[%d]:detection_value         : 0x%x\n",
                i,
                pRcvRadarPresenceNtfPkt->radar_ntf.radar_presence_detect_ntf.detection_value[i]);
        }
    }
    else {
        LOG_ERR("pRcvRadaNtfPkt is NULL\n");
    }
}

#endif // UWBFTR_Radar

#if UWBFTR_CCC && !(UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
EXTERNC void printCccRangingData(const phCccRangingData_t *pCccRangingData)
{
    if (pCccRangingData != NULL) {
        LOG_DBG("------------------Received Ccc Range Data------------------");
        LOG_DBG("CCC.sessionHandle                             : 0x%x ", pCccRangingData->sessionHandle);
        LOG_DBG("CCC.rangingStatus                             : 0x%.2X", pCccRangingData->rangingStatus);
        LOG_DBG("CCC.stsIndex                                  : %" PRIu32 "", pCccRangingData->stsIndex);
        LOG_DBG("CCC.rangingRoundIndex                         : %" PRIu16 "", pCccRangingData->rangingRoundIndex);
        LOG_INF("CCC.distance                                  : %" PRIu16 "", pCccRangingData->distance);
        LOG_DBG("CCC.uncertanityAnchorFom                      : %hu", pCccRangingData->uncertanityAnchorFom);
        LOG_DBG("CCC.uncertanityInitiatorFom                   : %hu", pCccRangingData->uncertanityInitiatorFom);
        LOG_HEXDUMP_DBG(pCccRangingData->ccmTag, MAX_CCM_TAG_SIZE, "CCC.ccmTag                                    ");
        LOG_DBG("CCC.aoa_azimuth                               : %d.%d", TO_Q_9_7(pCccRangingData->aoa_azimuth));
        LOG_DBG("CCC.aoa_azimuth_fom                           : %d", pCccRangingData->aoa_azimuth_FOM);
        LOG_DBG("CCC.aoa_elevation                             : %d.%d", TO_Q_9_7(pCccRangingData->aoa_elevation));
        LOG_DBG("CCC.aoa_elevation_fom                         : %d", pCccRangingData->aoa_elevation_FOM);

        LOG_DBG(
            "CCC.antenna_pair_info.configMode              : %d", pCccRangingData->antenna_pair_info.configMode);
        LOG_DBG(
            "CCC.antenna_pair_info.antPairId1              : %d", pCccRangingData->antenna_pair_info.antPairId1);
        LOG_DBG(
            "CCC.antenna_pair_info.antPairId2              : %d", pCccRangingData->antenna_pair_info.antPairId2);

        LOG_DBG("CCC.noOfPdoaMeasures                          : %d", pCccRangingData->noOfPdoaMeasures);
        for (size_t i = 0; i < pCccRangingData->noOfPdoaMeasures; i++) {
            LOG_DBG("CCC.pdoaMeasurements[%d].pdoa                     : %d.%d",
                i,
                TO_Q_9_7(pCccRangingData->pdoaMeasurements[i].pdoa));
            LOG_DBG("CCC.pdoaMeasurements[%d].pdoaIndex                : %d",
                i,
                pCccRangingData->pdoaMeasurements[i].pdoaIndex);
        }
        LOG_DBG("CCC.noOfRssiMeasurements                      : %d", pCccRangingData->noOfRssiMeasurements);
        for (size_t i = 0; i < pCccRangingData->noOfRssiMeasurements; i++) {
            LOG_DBG("CCC.rssiMeasurements[%d].rssi_rx1              : %d.%d",
                i,
                TO_Q_8_8(pCccRangingData->rssiMeasurements[i].rssi_rx1));

            LOG_DBG("CCC.rssiMeasurements[%d].rssi_rx2              : %d.%d",
                i,
                TO_Q_8_8(pCccRangingData->rssiMeasurements[i].rssi_rx2));
        }
        LOG_DBG("CCC.snrMeasurements                        : %d", pCccRangingData->noOfSnrMeasurements);
        for (size_t i = 0; i < pCccRangingData->noOfSnrMeasurements; i++) {
            LOG_DBG("CCC.snrMeasurements[%d].slotIndexAndAntennaMap    : %hu",
                i,
                pCccRangingData->snrMeasurements[i].slotIndexAndAntennaMap);
            LOG_DBG("CCC.snrMeasurements[%d].snrMainPath               : %hu",
                i,
                pCccRangingData->snrMeasurements[i].snrMainPath);
            LOG_DBG("CCC.snrMeasurements[%d].snrFirstPath              : %hu",
                i,
                pCccRangingData->snrMeasurements[i].snrFirstPath);
            LOG_DBG("CCC.snrMeasurements[%d].snrTotal                  : %d.%d",
                i,
                TO_Q_8_8(pCccRangingData->snrMeasurements[i].snrTotal));
        }
    }
}

#endif // UWBFTR_CCC && !(UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

#if UWBFTR_CSA

EXTERNC void printCsaRangingData(const phCsaRangingData_t *pCsaRangingData)
{
    if (pCsaRangingData != NULL) {
        LOG_DBG("------------------Received Ccc Range Data------------------");
        LOG_DBG("CSA.sessionHandle                             : 0x%x ", pCsaRangingData->sessionHandle);
        LOG_DBG("CSA.rangingStatus                             : 0x%.2X", pCsaRangingData->rangingStatus);
        LOG_DBG("CSA.stsIndex                                  : %" PRIu32 "", pCsaRangingData->stsIndex);
        LOG_DBG("CSA.rangingRoundIndex                         : %" PRIu16 "", pCsaRangingData->rangingRoundIndex);
        LOG_DBG("CSA.blockIndex                                : %" PRIu16 "", pCsaRangingData->blockIndex);
        LOG_INF("CSA.distance                                  : %" PRIu16 "", pCsaRangingData->distance);
        LOG_DBG("CSA.uncertanityAnchorFom                      : %hu", pCsaRangingData->uncertanityAnchorFom);
        LOG_DBG("CSA.uncertanityInitiatorFom                   : %hu", pCsaRangingData->uncertanityInitiatorFom);
        LOG_HEXDUMP_DBG(pCsaRangingData->ccmTag, MAX_CCM_TAG_SIZE, "CSA.ccmTag                                    ");
        LOG_DBG("CSA.aoa_azimuth                               : %d.%d", TO_Q_9_7(pCsaRangingData->aoa_azimuth));
        LOG_DBG("CSA.aoa_azimuth_fom                           : %d", pCsaRangingData->aoa_azimuth_FOM);
        LOG_DBG("CSA.aoa_elevation                             : %d.%d", TO_Q_9_7(pCsaRangingData->aoa_elevation));
        LOG_DBG("CSA.aoa_elevation_fom                         : %d", pCsaRangingData->aoa_elevation_FOM);

        LOG_DBG(
            "CSA.antenna_pair_info.configMode              : %d", pCsaRangingData->antenna_pair_info.configMode);
        LOG_DBG(
            "CSA.antenna_pair_info.antPairId1              : %d", pCsaRangingData->antenna_pair_info.antPairId1);
        LOG_DBG(
            "CSA.antenna_pair_info.antPairId2              : %d", pCsaRangingData->antenna_pair_info.antPairId2);

        LOG_DBG("CSA.noOfPdoaMeasures                          : %d", pCsaRangingData->noOfPdoaMeasures);
        for (size_t i = 0; i < pCsaRangingData->noOfPdoaMeasures; i++) {
            LOG_DBG("CSA.pdoaMeasurements[%d].pdoa                     : %d.%d",
                i,
                TO_Q_9_7(pCsaRangingData->pdoaMeasurements[i].pdoa));
            LOG_DBG("CSA.pdoaMeasurements[%d].pdoaIndex                : %d",
                i,
                pCsaRangingData->pdoaMeasurements[i].pdoaIndex);
        }
        LOG_DBG("CSA.noOfRssiMeasurements                      : %d", pCsaRangingData->noOfRssiMeasurements);
        for (size_t i = 0; i < pCsaRangingData->noOfRssiMeasurements; i++) {
            LOG_DBG("CSA.rssiMeasurements[%d].rssi_rx1              : %d.%d",
                i,
                TO_Q_8_8(pCsaRangingData->rssiMeasurements[i].rssi_rx1));

            LOG_DBG("CSA.rssiMeasurements[%d].rssi_rx2              : %d.%d",
                i,
                TO_Q_8_8(pCsaRangingData->rssiMeasurements[i].rssi_rx2));
#if UWBIOT_UWBD_SR250
            LOG_DBG("CSA.rssiMeasurements[%d].rssi_rx3              : %d.%d",
                i,
                TO_Q_8_8(pCsaRangingData->rssiMeasurements[i].rssi_rx3));
#endif //UWBIOT_UWBD_SR250
        }
        LOG_DBG("CSA.snrMeasurements                        : %d", pCsaRangingData->noOfSnrMeasurements);
        for (size_t i = 0; i < pCsaRangingData->noOfSnrMeasurements; i++) {
            LOG_DBG("CSA.snrMeasurements[%d].slotIndexAndAntennaMap    : %hu",
                i,
                pCsaRangingData->snrMeasurements[i].slotIndexAndAntennaMap);
            LOG_DBG("CSA.snrMeasurements[%d].snrMainPath               : %hu",
                i,
                pCsaRangingData->snrMeasurements[i].snrMainPath);
            LOG_DBG("CSA.snrMeasurements[%d].snrFirstPath              : %hu",
                i,
                pCsaRangingData->snrMeasurements[i].snrFirstPath);
            LOG_DBG("CSA.snrMeasurements[%d].snrTotal                  : %d.%d",
                i,
                TO_Q_8_8(pCsaRangingData->snrMeasurements[i].snrTotal));
        }
    }
}

#endif // UWBFTR_CSA

#if UWBFTR_DataTransfer

EXTERNC void printGetLogicalLinkParams(const phLogicalLinkGetParamsRsp_t *pLogicalLinkGetParamsRsp)
{
    if (pLogicalLinkGetParamsRsp != NULL) {
        LOG_INF("pLogicalLinkGetParamsRsp->status                : 0x%X", pLogicalLinkGetParamsRsp->status);
        LOG_INF("pLogicalLinkGetParamsRsp->control_field         : 0x%X", pLogicalLinkGetParamsRsp->control_field);
        LOG_INF("pLogicalLinkGetParamsRsp->ll_sdu_size           : 0x%X", pLogicalLinkGetParamsRsp->ll_sdu_size);
        LOG_INF("pLogicalLinkGetParamsRsp->ll_pdu_size           : 0x%X", pLogicalLinkGetParamsRsp->ll_pdu_size);
        LOG_INF(
            "pLogicalLinkGetParamsRsp->Tx_window_size        : 0x%X", pLogicalLinkGetParamsRsp->Tx_window_size);
        LOG_INF(
            "pLogicalLinkGetParamsRsp->Rx_window_size        : 0x%X", pLogicalLinkGetParamsRsp->Rx_window_size);
        LOG_INF(
            "pLogicalLinkGetParamsRsp->repetition_count      : 0x%X", pLogicalLinkGetParamsRsp->repetition_count);
        LOG_INF("pLogicalLinkGetParamsRsp->link_to               : 0x%X", pLogicalLinkGetParamsRsp->link_to);
        LOG_INF("pLogicalLinkGetParamsRsp->port                  : 0x%X", pLogicalLinkGetParamsRsp->port);
    }
    else {
        LOG_ERR("pLogicalLinkGetParamsRsp is NULL");
    }
}
#endif // UWBFTR_DataTransfer
