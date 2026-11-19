/*
 *
 * Copyright 2018-2020, 2022, 2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "PrintUtility_RfTest.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_print_util_rftest, LOG_LEVEL_INF);

EXTERNC void printPerParams(const phRfTestParams_t *pRfTestParams)
{
    if (pRfTestParams != NULL) {
        LOG_INF("TestRF : numOfPckts : %" PRIu32, pRfTestParams->numOfPckts);
        LOG_INF("TestRF : tGap : %" PRIu32, pRfTestParams->tGap);
        LOG_INF("TestRF : tStart : %" PRIu32, pRfTestParams->tStart);
        LOG_INF("TestRF : tWin : %" PRIu32, pRfTestParams->tWin);
        LOG_INF("TestRF : randomizedSize : %hu", pRfTestParams->randomizedSize);
        LOG_INF("TestRF : phrRangingBit : %" PRIu16, pRfTestParams->phrRangingBit);
        LOG_INF("TestRF : rmarkerRxStart : %" PRIu32, pRfTestParams->rmarkerRxStart);
        LOG_INF("TestRF : rmarkerTxStart : %" PRIu32, pRfTestParams->rmarkerTxStart);
        LOG_INF("TestRF : stsIndexAutoIncr : %hu", pRfTestParams->stsIndexAutoIncr);
        LOG_INF("TestRF : sts_detect_bitmap_en : %hu", pRfTestParams->sts_detect_bitmap_en);
    }
    else {
        LOG_INF("pRfTestParams is NULL");
    }
}

EXTERNC void printLoopbackRecvData(const phTest_Loopback_Ntf_t *pRfTestRecvData)
{
    if (pRfTestRecvData != NULL) {
        LOG_INF("Loopback : status : %hu", pRfTestRecvData->status);
        LOG_INF(
            "Loopback : tx_ts : %" PRIu32 ".%" PRIu16, pRfTestRecvData->tx_ts_int, pRfTestRecvData->tx_ts_frac);
        LOG_INF(
            "Loopback : rx_ts : %" PRIu32 ".%" PRIu16, pRfTestRecvData->rx_ts_int, pRfTestRecvData->rx_ts_frac);
        LOG_INF("Loopback : aoa_azimuth :  %d.%d", TO_Q_9_7(pRfTestRecvData->aoa_azimuth));
        LOG_INF("Loopback : aoa_elevation : %d.%d", TO_Q_9_7(pRfTestRecvData->aoa_elevation));
        LOG_INF("Loopback : phr : %" PRIu16, pRfTestRecvData->phr);
        if (pRfTestRecvData->vs_data_len > 0) {
            LOG_INF("PER : vs_data_len : %hu", pRfTestRecvData->vs_data_len);
            LOG_INF("PER : vs_data_type : %hu", pRfTestRecvData->vs_data_type);
            LOG_INF("PER : rx_mode : %hu", pRfTestRecvData->vs_data.rx_mode);
            LOG_INF("PER : no_of_rx_antenna : %hu", pRfTestRecvData->vs_data.no_of_rx_antenna);
            for (int i = 0; i < pRfTestRecvData->vs_data.no_of_rx_antenna; i++) {
                LOG_INF("PER : rx_antenna_id : %hu", pRfTestRecvData->vs_data.rx_antenna_id[i]);
            }
            for (int j = 0; j < pRfTestRecvData->vs_data.no_of_rx_antenna; j++) {
                LOG_INF("PER : rssi_rx : %d.%d", TO_Q_8_8(pRfTestRecvData->vs_data.rssi_rx[j]));
            }
            for (int k = 0; k < pRfTestRecvData->vs_data.no_of_rx_antenna; k++) {
                LOG_INF("PER : snr_rx : %d.%d", TO_Q_8_8(pRfTestRecvData->vs_data.snr_rx[k]));
            }
            LOG_INF("PER : rx_cfo_est : %d.%d", TO_Q_5_11(pRfTestRecvData->rx_cfo_est));
        }
    }
    else {
        LOG_INF("TestRecvData is NULL");
    }
}

EXTERNC void printTestSrRecvData(const phTest_Test_Sr_Ntf_t *pRfTestSrRecvData)
{
    if (pRfTestSrRecvData != NULL) {
        LOG_INF("PER : status : %hu", pRfTestSrRecvData->Test_Sr_Ntf_status);
        LOG_INF("PER : Test_Sr_Ntf_attempts : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_attempts);
        LOG_INF("PER : Test_Sr_Ntf_acq_Detect : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_acq_Detect);
        LOG_INF("PER : Test_Sr_Ntf_acq_Reject : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_acq_Reject);
        LOG_INF("PER : Test_Sr_Ntf_rxfail : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_rxfail);
        LOG_INF("PER : Test_Sr_Ntf_sync_cir_ready : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_sync_cir_ready);
        LOG_INF("PER : Test_Sr_Ntf_sfd_fail : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_sfd_fail);
        LOG_INF("PER : Test_Sr_Ntf_sfd_found : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_sfd_found);
        LOG_INF("PER : Test_Sr_Ntf_sts_found : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_sts_found);
        LOG_INF("PER : Test_Sr_Ntf_eof : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_eof);
        LOG_INF("PER : Test_Sr_Ntf_bitmap_len : %" PRIu32, pRfTestSrRecvData->Test_Sr_Ntf_bitmap_len);
        if (pRfTestSrRecvData->Test_Sr_Ntf_bitmap_len !=0){
            LOG_HEXDUMP_INF(
                pRfTestSrRecvData->Test_Sr_Ntf_bitmap, pRfTestSrRecvData->Test_Sr_Ntf_bitmap_len, "Test_Sr_Ntf_bitmap");
        }
    }
    else {
        LOG_INF("TestRecvData is NULL");
    }
}

EXTERNC void printPerRecvData(const phTestPer_Rx_Ntf_t *pRfTestRecvData)
{
    if (pRfTestRecvData != NULL) {
        LOG_INF("PER : status : %hu", pRfTestRecvData->status);
        LOG_INF("PER : attempts : %" PRIu32, pRfTestRecvData->attempts);
        LOG_INF("PER : acq_Detect : %" PRIu32, pRfTestRecvData->acq_Detect);
        LOG_INF("PER : acq_Reject : %" PRIu32, pRfTestRecvData->acq_Reject);
        LOG_INF("PER : rxfail : %" PRIu32, pRfTestRecvData->rxfail);
        LOG_INF("PER : sync_cir_ready : %" PRIu32, pRfTestRecvData->sync_cir_ready);
        LOG_INF("PER : sfd_fail : %" PRIu32, pRfTestRecvData->sfd_fail);
        LOG_INF("PER : sfd_found : %" PRIu32, pRfTestRecvData->sfd_found);
        LOG_INF("PER : phr_dec_error : %" PRIu32, pRfTestRecvData->phr_dec_error);
        LOG_INF("PER : phr_bit_error : %" PRIu32, pRfTestRecvData->phr_bit_error);
        LOG_INF("PER : psdu_dec_error : %" PRIu32, pRfTestRecvData->psdu_dec_error);
        LOG_INF("PER : psdu_bit_error : %" PRIu32, pRfTestRecvData->psdu_bit_error);
        LOG_INF("PER : sts_found : %" PRIu32, pRfTestRecvData->sts_found);
        LOG_INF("PER : eof : %" PRIu32, pRfTestRecvData->eof);
        if (pRfTestRecvData->vs_data_len > 0) {
            LOG_INF("PER : vs_data_len : %hu", pRfTestRecvData->vs_data_len);
            LOG_INF("PER : vs_data_type : %hu", pRfTestRecvData->vs_data_type);
            LOG_INF("PER : rx_mode : %hu", pRfTestRecvData->vs_data.rx_mode);
            LOG_INF("PER : no_of_rx_antenna : %hu", pRfTestRecvData->vs_data.no_of_rx_antenna);
            for (int i = 0; i < pRfTestRecvData->vs_data.no_of_rx_antenna; i++) {
                LOG_INF("PER : rx_antenna_id : %hu", pRfTestRecvData->vs_data.rx_antenna_id[i]);
            }
            for (int j = 0; j < pRfTestRecvData->vs_data.no_of_rx_antenna; j++) {
                LOG_INF("PER : rssi_rx : %d.%d", TO_Q_8_8(pRfTestRecvData->vs_data.rssi_rx[j]));
            }
            for (int k = 0; k < pRfTestRecvData->vs_data.no_of_rx_antenna; k++) {
                LOG_INF("PER : snr_rx : %d.%d", TO_Q_8_8(pRfTestRecvData->vs_data.snr_rx[k]));
            }
            LOG_INF("PER : rx_cfo_est : %d.%d", TO_Q_5_11(pRfTestRecvData->rx_cfo_est));
        }
    }
    else {
        LOG_INF("TestRecvData is NULL");
    }
}

EXTERNC void printrxRecvData(const phTest_Rx_Ntf_t *pRfTestRecvData)
{
    if (pRfTestRecvData != NULL) {
        LOG_INF("TestRX : status : %hu", pRfTestRecvData->status);
        LOG_INF("TestRX : rx_done_ts_int : %" PRIu32 ".%" PRIu16,
            pRfTestRecvData->rx_done_ts_int,
            pRfTestRecvData->rx_done_ts_frac);
        LOG_INF("TestRX : aoa_azimuth : %d.%d", TO_Q_9_7(pRfTestRecvData->aoa_azimuth));
        LOG_INF("TestRX : aoa_elevation : %d.%d", TO_Q_9_7(pRfTestRecvData->aoa_elevation));
        LOG_INF("TestRX : toa_gap : %hu", pRfTestRecvData->toa_gap);
        LOG_INF("TestRX : phr : %" PRIu16, pRfTestRecvData->phr);
        if (pRfTestRecvData->vs_data_len > 0) {
            LOG_INF("PER : vs_data_len : %hu", pRfTestRecvData->vs_data_len);
            LOG_INF("PER : vs_data_type : %hu", pRfTestRecvData->vs_data_type);
            LOG_INF("PER : rx_mode : %hu", pRfTestRecvData->vs_data.rx_mode);
            LOG_INF("PER : no_of_rx_antenna : %hu", pRfTestRecvData->vs_data.no_of_rx_antenna);
            for (int i = 0; i < pRfTestRecvData->vs_data.no_of_rx_antenna; i++) {
                LOG_INF("PER : rx_antenna_id : %hu", pRfTestRecvData->vs_data.rx_antenna_id[i]);
            }
            for (int j = 0; j < pRfTestRecvData->vs_data.no_of_rx_antenna; j++) {
                LOG_INF("PER : rssi_rx : %d.%d", TO_Q_8_8(pRfTestRecvData->vs_data.rssi_rx[j]));
            }
            for (int k = 0; k < pRfTestRecvData->vs_data.no_of_rx_antenna; k++) {
                LOG_INF("PER : snr_rx : %d.%d", TO_Q_8_8(pRfTestRecvData->vs_data.snr_rx[k]));
            }
        }
    }
    else {
        LOG_INF("TestRecvData is NULL");
    }
}
