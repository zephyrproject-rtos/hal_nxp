/*
 *
 * Copyright 2019-2020,2023 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */
/**
 *
 *  This file contains the definition from UCI specification
 *
 */

#ifndef UWB_UCI_TEST_DEFS_H
#define UWB_UCI_TEST_DEFS_H

#include <stdint.h>
#include "zephyr/uwb/uci.h"
#include "uci_prop_defs.h"

/**
 **GID: UCI test group - 0x0D : Opcodes
 */
#define UCI_MSG_TEST_SET_CONFIG  0
#define UCI_MSG_TEST_GET_CONFIG  1
#define UCI_MSG_TEST_PERIODIC_TX 2
#define UCI_MSG_TEST_PER_RX      3
/** RFU 4 */
#define UCI_MSG_TEST_RX           5
#define UCI_MSG_TEST_LOOPBACK     6
#define UCI_MSG_TEST_STOP_SESSION 7
#define UCI_MSG_TEST_SR_RX        9

#define UCI_MSG_TEST_PERIODIC_TX_CMD_SIZE  0
#define UCI_MSG_TEST_PER_RX_CMD_SIZE       0
#define UCI_MSG_TEST_STOP_SESSION_CMD_SIZE 0
#define UCI_MSG_TEST_RX_CMD_SIZE           0

/**
 * UCI test Parameter IDs : RF Test Configurations
 */
#define UCI_TEST_PARAM_ID_NUM_PACKETS          0x00
#define UCI_TEST_PARAM_ID_T_GAP                0x01
#define UCI_TEST_PARAM_ID_T_START              0x02
#define UCI_TEST_PARAM_ID_T_WIN                0x03
#define UCI_TEST_PARAM_ID_RANDOMIZE_PSDU       0x04
#define UCI_TEST_PARAM_ID_PHR_RANGING_BIT      0x05
#define UCI_TEST_PARAM_ID_RMARKER_TX_START     0x06
#define UCI_TEST_PARAM_ID_RMARKER_RX_START     0x07
#define UCI_TEST_PARAM_ID_STS_INDEX_AUTO_INCR  0x08
#define UCI_TEST_PARAM_ID_STS_DETECT_BITMAP_EN 0x09
#endif

/** Helper Macro to fetch Particular GID and OID for Test Group  - (0x0D) */
#define GET_TEST_GROUP_GID_OID(TEST_OID) ((UCI_GID_TEST << UCI_GID_GROUP_SHIFT) | (TEST_OID))

enum
{
    /* Test Group - (0x0D)*/
    kGidOid_TestSetConfig   = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_SET_CONFIG),
    kGidOid_TestGetConfig   = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_GET_CONFIG),
    kGidOid_TestPeriodicTx  = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_PERIODIC_TX),
    kGidOid_TestPerRx       = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_PER_RX),
    kGidOid_TestRx          = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_RX),
    kGidOid_TestSrRx        = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_SR_RX),
    kGidOid_TestUwbLoopback = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_LOOPBACK),
    kGidOid_TestStopSession = GET_TEST_GROUP_GID_OID(UCI_MSG_TEST_STOP_SESSION),
};
