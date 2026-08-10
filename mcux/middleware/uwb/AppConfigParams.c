/*
 *
 * Copyright 2018-2020,2022 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "UwbApi.h"
#include "zephyr/uwb/uci.h"
#include "uci_prop_defs.h"
#include "uci_ext_defs.h"
#include "uci_test_defs.h"

const uint8_t uciRfTest_TestParamIds[] = {
    /* RF Test Parameters */
    UCI_TEST_PARAM_ID_NUM_PACKETS,         /*NUM_OF_PACKETS         */
    UCI_TEST_PARAM_ID_T_GAP,               /*T_GAP                  */
    UCI_TEST_PARAM_ID_T_START,             /*T_START                */
    UCI_TEST_PARAM_ID_T_WIN,               /*T_WIN                  */
    UCI_TEST_PARAM_ID_RANDOMIZE_PSDU,      /*RANDOMIZE_PSDU         */
    UCI_TEST_PARAM_ID_PHR_RANGING_BIT,     /*PHR_RANGING_BIT        */
    UCI_TEST_PARAM_ID_RMARKER_RX_START,    /*RX START               */
    UCI_TEST_PARAM_ID_RMARKER_TX_START,    /*TX_START               */
    UCI_TEST_PARAM_ID_STS_INDEX_AUTO_INCR, /*STS INDEX AUTO INCR    */
};
const uint8_t uciRfTest_TestParamIds_len = sizeof(uciRfTest_TestParamIds);

const uint8_t uciRangingParamIds[] = {
    /* Application Configuration Parameters */
    UCI_PARAM_ID_DEVICE_ROLE,         /* DEVICE_ROLE                  */
    UCI_PARAM_ID_MULTI_NODE_MODE,     /* MULTI_NODE_MODE              */
    UCI_PARAM_ID_MAC_ADDRESS_MODE,    /* MAC_ADDR_MODE                */
    UCI_PARAM_ID_SCHEDULED_MODE,      /* SCHEDULED_MODE               */
    UCI_PARAM_ID_RANGING_ROUND_USAGE, /* RANGING_ROUND_USAGE          */
    UCI_PARAM_ID_DEVICE_MAC_ADDRESS,  /* DEVICE_MAC_ADDRESS           */
    UCI_PARAM_ID_DEVICE_TYPE,         /* DEVICE_TYPE                  */
};
const uint8_t uciRangingParamIds_len = sizeof(uciRangingParamIds);
