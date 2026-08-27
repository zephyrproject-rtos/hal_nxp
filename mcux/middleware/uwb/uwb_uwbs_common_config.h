/*
 * Copyright 2022,2025 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __DEMO_COMMON_CONFIG__
#define __DEMO_COMMON_CONFIG__

#include "UwbApi.h"

#if (UWBIOT_SESN_SNXXX)
#define LEN_OFFSET              4
#define PAYLOAD_OFFSET          5
#define ROOT_SESSION_KEY_TAG_ID 0XC0
#define ROOT_SESSION_KEY_OFFSET 7
#define SESSION_ID_TAG_ID       0xCF
#endif // UWBIOT_SESN_SNXXX

#if UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S
#define MAX_CALIB_VALUE             16
#define RF_CLK_ACCURACY_CALIB_LEN   0x07

/**
 * 1B noOfEntries
 * 5B calibrationValue
 * LEN =( noOfEntries + (numberofEntries * calibrationValue))
 */
#define TX_POWER_PER_ANT_LEN(entries) (1 + (entries * 5))
#define CHANNEL_5                     0x05
#define CHANNEL_9                     0x09
#endif //UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S

#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S)
tUWBAPI_STATUS demo_configure_otp_calibration(uint8_t channel);
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S)

#endif // __DEMO_COMMON_CONFIG__
