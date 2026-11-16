/*
 *
 * Copyright 2018-2020,2022-2024 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UWBAPI_RF_TEST_SRXXX_H
#define UWBAPI_RF_TEST_SRXXX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "UwbApi_Types.h"
#include "UwbApi_Types_RfTest.h"

/**
 *  @brief APIs exposed to access Uwb Rf Test related Functionalities
 */

/**
 *  \name RF start test supported in UWB API layer.
 */
/* @{ */
typedef enum startRfParam
{
    /**  PER Tx start */
    RF_START_PER_TX = 0x0,
    /** PER Rx start */
    RF_START_PER_RX,
    /**  RF Loopback test */
    RF_LOOPBACK_TEST,
    /**  Single Rx RF TEST */
    RF_TEST_RX,
    /**  To start the Security level test */
    RF_TEST_SR_RX,
    } eStartRfParam;
/* @} */

/**
 * @brief START PER TX Data
 */
/* @{ */
typedef struct
{
    /** tx data */
    uint8_t *txData;

    /** tx data length */
    uint16_t txDataLength;

} phStartPerTxData_t;
/* @} */

/**
 * @brief START PER RX Data
 */
/* @{ */
typedef struct
{
    /** rx data */
    uint8_t *rxData;

    /** rx data length */
    uint16_t rxDataLength;

} phStartPerRxData_t;
/* @} */

/**
 * @brief LOOPBACK Data
 */
/* @{ */
typedef struct
{
    /** loopback data */
    uint8_t *loopbackData;

    /** loopback data length */
    uint16_t loopbackDataLength;

} phLoopbackTestData_t;
/* @} */

/**
 * @brief Rf Start Data
 */
/* @{ */
typedef union {
    /** START PER TX Data */
    phStartPerTxData_t startPerTxData;
    /** START PER RX Data */
    phStartPerRxData_t startPerRxData;
    /** LOOPBACK TEST Data */
    phLoopbackTestData_t loopbackTestData;
} phRfStartData_t;
/* @} */

/** \addtogroup Uwb_RfTest_Apis
 *
 * @{ */

/**
 * @brief Set session specific PER parameters

 * \param[in] sessionHandle   Initialized Session Handle
 * \param[in] perParams   Pointer to \ref phRfTestParams_t
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetRfTestParams(uint32_t sessionHandle, const phRfTestParams_t *pRfTestParams);

/**
 * @brief Get session specific PER parameters
 *
 * \param[in] sessionHandle    Initialized Session Handle
 * \param[out] pPerParams   Pointer to \ref phRfTestParams_t . Valid only if API
 * status is success.
 *
 * \retval #UWBAPI_STATUS_OK               if successful
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UCI stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetRfTestParams(uint32_t sessionHandle, phRfTestParams_t *pRfTestParams);

/**
 * @brief Set Test specific config parameters.
 *
 * \param[in] sessionHandle    Initialized Session Handle
 * \param[in] param_id   Test Config Parameter Id
 * \param[in] param_value   Param value for Test config param id
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                            sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UCI_STATUS_RANGING_PHY_RX_PROCESSING_TIME_ERROR if the processing
 * time required is not sufficient to process current packet and schedule (prepare RX)
 * for next packet for a given APP_CONFIG, PSDU_LENGTH and TEST_CONFIG
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetTestConfig(uint32_t sessionHandle, eTestConfig param_id, uint32_t param_value);

/**
 * @brief Get Test specific config parameters.
 *
 * \param[in] sessionHandle    Initialized Session Handle
 * \param[in] param_id         Test Config Parameter Id
 * \param[in] param_value      Param value for Test config param id
 * \param[out] param_value     Param value for Test config param id
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                            sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetTestConfig(uint32_t sessionHandle, eTestConfig param_id, uint32_t *param_value);

/**
 * @brief RF Start test
 *
 * \param[in] paramId        Param ID
 * \param[in] pStartData     Start data
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if input data in null
 * \retval #UWBAPI_STATUS_REJECTED         if rf parameters are not set
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_StartRfTest(eStartRfParam paramId, phRfStartData_t *pStartData);

/**
 * @brief RF Test stop
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_REJECTED         if per parameters are not set
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_Stop_RfTest(void);
/** @} */ /* @addtogroup Uwb_RfTest_Apis */

#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif // UWBAPI_RF_TEST_SRXXX_H
