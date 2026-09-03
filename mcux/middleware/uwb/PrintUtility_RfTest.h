/*
 *
 * Copyright 2018-2020 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PRINT_UTILITY_RF_TEST_H
#define _PRINT_UTILITY_RF_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "PrintUtility.h"
#include "UwbApi_Types_RfTest.h"

EXTERNC void printPerParams(const phRfTestParams_t *pRfTestParams);
EXTERNC void printPerRecvData(const phTestPer_Rx_Ntf_t *pRfTestRecvData);
EXTERNC void printrxRecvData(const phTest_Rx_Ntf_t *pRfTestRecvData);
EXTERNC void printLoopbackRecvData(const phTest_Loopback_Ntf_t *pRfTestRecvData);
EXTERNC void printTestSrRecvData(const phTest_Test_Sr_Ntf_t *pRfTestSrRecvData);

#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif
