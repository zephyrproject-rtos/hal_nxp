/*
 * Copyright 2022,2023,2025-2026 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#include "uci_prop_defs.h"
#include "uwb_uwbs_common_config.h"
#include "uwb_board.h"
#include "UwbApi_Types.h"
#include <zephyr/logging/log.h>

#if UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S
LOG_MODULE_REGISTER(nxp_uwb_common_config, LOG_LEVEL_INF);

tUWBAPI_STATUS demo_configure_otp_calibration(uint8_t channel)
{
    LOG_INF(" demo_configure_otp_calibration applying for channel %d\n", channel);
    tUWBAPI_STATUS status;
    uint16_t bitMask;
    phCalibPayload_t readCalibData = {0x00};

    uint8_t calibValues[MAX_CALIB_VALUE] = {0x00};
    uint8_t *pSetCalibValue;
    uint32_t index = 0;
    bitMask        = (CHIP_CALIBRATION_POS | PAPPPA_CALIB_CTRL_POS | TX_POWER_POS | XTAL_CAP_VALUES_POS);
    status         = UwbApi_ReadOtpCalibDataCmd(channel, bitMask, &readCalibData);
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("UwbApi_ReadOtpCalibDataCmd Failed");
        return UWBAPI_STATUS_FAILED;
    }

    if (readCalibData.CHIP_CALIBRATION != 0) {
        pSetCalibValue = calibValues;
        UWB_UINT16_TO_STREAM(pSetCalibValue, readCalibData.CHIP_CALIBRATION, index);
        status = UwbApi_SetCalibration(channel, CHIP_CALIBRATION, calibValues, sizeof(readCalibData.CHIP_CALIBRATION));
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("Set Calib param CHIP_CALIBRATION Failed");
            return UWBAPI_STATUS_FAILED;
        }
    }

    if (readCalibData.PA_PPA_CALIB_CTRL != 0) {
        pSetCalibValue = calibValues;
        index          = 0;
        UWB_UINT16_TO_STREAM(pSetCalibValue, readCalibData.PA_PPA_CALIB_CTRL, index);
        status =
            UwbApi_SetCalibration(channel, PA_PPA_CALIB_CTRL, calibValues, sizeof(readCalibData.PA_PPA_CALIB_CTRL));
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("Set Calib param PA_PPA_CALIB_CTRL Failed");
            return UWBAPI_STATUS_FAILED;
        }
    }
    else {
        PRINTF("Set Calib param for PA_PPA_CALIB_CTRL SKIPPED due to no data from the OTP\n");
    }

    if (readCalibData.XTAL_CAP_VALUES[0] != 0) {
        memset(calibValues, 0x00, sizeof(calibValues));

        calibValues[0] = 0x03; // Number of registers(must be 0x03)
        calibValues[1] = readCalibData.XTAL_CAP_VALUES[0];
        calibValues[3] = readCalibData.XTAL_CAP_VALUES[1];
        calibValues[5] = readCalibData.XTAL_CAP_VALUES[2];
        status         = UwbApi_SetCalibration(channel, RF_CLK_ACCURACY_CALIB, calibValues, RF_CLK_ACCURACY_CALIB_LEN);
        if (status != UWBAPI_STATUS_OK) {
            LOG_ERR("Set Calib param RF_CLK_ACCURACY_CALIB Failed");
            return UWBAPI_STATUS_FAILED;
        }
    }
    else {
        PRINTF("Set Calib param for RF_CLK_ACCURACY_CALIB SKIPPED due to no data from the OTP\n");
    }
    // Temp commented the  TX_POWER_ID to update from the APP evey time
    //   if (readCalibData.TX_POWER_ID[0] != 0) {
    PRINTF("Set Calib param for TX_POWER_PER_ANTENNA SET\n");
    memset(calibValues, 0x00, sizeof(calibValues));
    uint8_t noOfEntries = 0x01;

    calibValues[0] = noOfEntries; // No. of Entries
    calibValues[1] = 0x01;        // Antenna Id 1
    calibValues[2] = 0x17;        // Tx Power Delta Peak
    calibValues[4] = 0x00;        // Tx Power Id RMS
    calibValues[6] = 0x02;        // Antenna Id 2
    calibValues[7] = 0X00;        // Tx Power Delta Peak
    calibValues[9] = 0X00;        // Tx Power Id RMS

    status = UwbApi_SetCalibration(channel, TX_POWER_PER_ANTENNA, calibValues, TX_POWER_PER_ANT_LEN(noOfEntries));
    if (status != UWBAPI_STATUS_OK) {
        LOG_ERR("Set Calib param TX_POWER_PER_ANTENNA Failed");
        return UWBAPI_STATUS_FAILED;
    }
    //}
    return UWBAPI_STATUS_OK;
}
#endif // UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S
