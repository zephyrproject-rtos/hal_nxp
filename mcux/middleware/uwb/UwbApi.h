/*
 *
 * Copyright 2018-2020,2022-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UWBAPI_H
#define UWBAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <uwb_board.h>
#include "phUwbTypes.h"
#include "zephyr/uwb/uwb_types.h"
#include "UwbApi_Types.h"
#include "uci_prop_defs.h"
#include <UwbApi_Types_Proprietary.h>
#include "UwbApi_Internal.h"
#include "UwbApi_Proprietary.h"
#include "zephyr/kernel.h"
#include "zephyr/uwb/types.h"

#ifndef UWB_BOARD_ENABLE_FW_DOWNLOAD_ON_UWBINIT
#error UWB_BOARD_ENABLE_FW_DOWNLOAD_ON_UWBINIT must be defined in uwb_board.h
#endif

#ifndef UWB_BOARD_ENABLE_EXT_FLASH_BASED_FW_DOWNLOAD
#error UWB_BOARD_ENABLE_EXT_FLASH_BASED_FW_DOWNLOAD must be defined in ``uwb_board.h``
#endif

#if UWB_BOARD_ENABLE_EXT_FLASH_BASED_FW_DOWNLOAD
/* FW Download is from an external flash. Only supported for RV4 */
#define UWB_BLD_CFG_FW_DNLD_DIRECTLY_FROM_HOST 0
#else
/* FW Download is directly from host, and SR1XX FW Image is compiled in as a
 * a part of the host application.
 *
 * This is default implementation for almost every system. */
#define UWB_BLD_CFG_FW_DNLD_DIRECTLY_FROM_HOST 1
#endif

/*
 * UwbApi_GetStackCapabilities() is going to deprecated...
 * Instead of UwbApi_GetStackCapabilities(), use UwbApi_GetDeviceInfo()
 *
 * To maintain backward compatibilty of API used #define here
 */
#define UwbApi_GetStackCapabilities UwbApi_GetDeviceInfo

/** NOTE: UwbApi_Init_New is planned for deprecation soon.
      Use UwbApi_Initialize() directly in new code.
      To maintain backward compatibilty of API used #define here
*/
#define UwbApi_Init_New UwbApi_Initialize

#if UWB_BOARD_ENABLE_FW_DOWNLOAD_ON_UWBINIT || UWB_BLD_CFG_FW_DNLD_DIRECTLY_FROM_HOST
EXTERNC const uint8_t heliosEncryptedMainlineFwImage[];
EXTERNC const uint32_t heliosEncryptedMainlineFwImageLen;
#if UWBIOT_UWBD_SR2XXT
EXTERNC const uint8_t heliosEncryptedMainlineFwImagePatchVer;
#endif // UWBIOT_UWBD_SR2XXT
#endif

/**
 * @brief APIs exposed to application to access UWB Functionality.
 */

/** \addtogroup uwb_apis
 *
 * @{ */

/**
 * @brief Initialize the UWB Device stack in the required mode. Operating mode
 *        will be set as per the Callback functions. Operating Modes supported include
 *        Standalone mode [default mode] and MCTT mode.
 *        Atleast one of the call backs shall not be NULL.
 *        When all the callbacks are set then "Standalone" mode will take precedence.
 *
 * \param[in] pAppCtx   Pointer to \ref phUwbappContext_t structure
 *
 * \retval #UWBAPI_STATUS_OK             on success
 * \retval #UWBAPI_STATUS_TIMEOUT        if command is timeout
 * \retval #UWBAPI_STATUS_FAILED         otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_Initialize(phUwbappContext_t *pAppCtx);

/**
 * @brief Get the registered application callback function
 *
 * \param[out] pAppCtx   Pointer to registered application callback function
 *
 * \retval #UWBAPI_STATUS_OK             on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED UWB library is not initialized
 * \retval #UWBAPI_STATUS_FAILED         otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetRegisteredAppCallback(uwb_uci_callback_t **const pAppCallback);

/**
 * @brief Update the registered application callback function
 *
 * \param[in] pAppCtx   Pointer to application callback function to be registered
 *
 * \retval #UWBAPI_STATUS_OK             on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED UWB library is not initialized
 * \retval #UWBAPI_STATUS_FAILED         otherwise
 */
EXTERNC tUWBAPI_STATUS UwbApi_RegisterAppCallback(uwb_uci_callback_t *pAppCallback);

/**
 * @brief To switch the Operating mode to MCTT
 *
 * \param[in] pAppCtx   Pointer to \ref phUwbappContext_t strucutre
 *
 * \retval #UWBAPI_STATUS_OK             on success
 * \retval #UWBAPI_STATUS_FAILED         otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SwitchToMCTTMode(uwb_uci_callback_t *pMcttCb);

/**
 * @brief De-initializes the UWB Middleware stack
 *        Sequence of task deinitialization must be maintained
 *         -> Deinit client thread
 *         -> Deinit reader thread
 *         -> Deinit uwb_task thread
 *
 * \retval #UWBAPI_STATUS_OK      on success
 * \retval #UWBAPI_STATUS_FAILED  otherwise
 * \retval #UWBAPI_STATUS_TIMEOUT if command is timeout
 */
EXTERNC tUWBAPI_STATUS UwbApi_ShutDown();

#if !(UWBIOT_UWBD_SR04X)
/**
 * @brief API to recover from crash, cmd timeout.
 *
 * \retval #UWBAPI_STATUS_OK       on success
 * \retval #UWBAPI_STATUS_FAILED   otherwise
 * \retval #UWBAPI_STATUS_TIMEOUT  if command is timeout
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_RecoverUWBS();
#endif //!(UWBIOT_UWBD_SR04X)

/**
 * @brief Resets UWBD device to Ready State
 *
 * \param[in] resetConfig   Supported Value: UWBD_RESET
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_UwbdReset(uint8_t resetConfig);

/**
 * @brief Gets UWB Device State
 *
 * \param[out] pDeviceState   pointer to uint8_t to get Device State. Valid only
 * if API status is success.
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if parameter is invalid
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetUwbDevState(uint8_t *pDeviceState);

/**
 * @brief Initializes session for a Type(Ranging/Data/Per)
 *
 * \param[in]   sessionId           Session ID.
 * \param[in]   sessionType         Type of Session(Ranging/Data/Per).
 * \param[out]  sessionHandle       Session Handle.
 *
 *
 * \retval #UWBAPI_STATUS_OK                     on success
 *
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED        if UWB stack is not initialized
 *
 * \retval #UWBAPI_STATUS_MAX_SESSIONS_EXCEEDED  if more than 5 sessions are
 *                                                exceeded
 *
 * \retval #UWBAPI_STATUS_TIMEOUT                if command is timeout
 *
 * \retval #UWBAPI_STATUS_FAILED                 otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SessionInit(uint32_t sessionId, uwb_session_type_t sessionType, uint32_t *sessionHandle);

/**
 * @brief De-initialize based on Session Handle
 *
 * \param[in] sessionHandle   Initialized Session Handle
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                           sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SessionDeinit(uint32_t sessionHandle);

/**
 * @brief API to configure notification timeout value for session related operations.
 *
 * @param timeoutMs Timeout value in milliseconds for notification events
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if timeoutMs is having invalid value
 *
 * \note This timeout value affects all subsequent session operations and should be set
 *       before starting any ranging sessions.
 *       In case of multisession scenario, this timeout value will be applied to all sessions.
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_ConfigureNtfTimeout(uint32_t timeoutMs);
/**
 * @brief Returns UCI, FW and MW version
 *
 * \param[out] pdevInfo Pointer to \ref phUwbDevInfo_t
 *
 * \retval UWBAPI_STATUS_OK              if successful
 * \retval UWBAPI_STATUS_NOT_INITIALIZED if UCI stack is not initialized
 * \retval UWBAPI_STATUS_INVALID_PARAM   if invalid parameters are passed
 * \retval UWBAPI_STATUS_FAILED          otherwise
 * \retval UWBAPI_STATUS_TIMEOUT         if command is timeout
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetDeviceInfo(phUwbDevInfo_t *pdevInfo);

/**
 * @brief Set session specific ranging parameters.
 *
 * For contention based ranging DST_MAC_ADDRESS and NO_OF_CONTROLEES parameter is not required both should be set to
 * zero.
 *
 * Example: For time based and contention based configuration given below.
 * @code
 * // Time based Ranging :
 *
 * phRangingParams_t inRangingParams = {0};
 * inRangingParams.noOfControlees = 1;
 * inRangingParams.dstMacAddr[] = {0x11,0x22};
 *
 * // Contention based Ranging :
 *
 * phRangingParams_t inRangingParams = {0};
 * inRangingParams.noOfControlees = 0;
 * inRangingParams.dstMacAddr[] = {0x00,0x00};
 *
 * @endcode
 *
 * \param[in] sessionHandle       Initialized Session Handle
 * \param[in] pRangingParam   Pointer to \ref phRangingParams_t
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                           sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetRangingParams(uint32_t sessionHandle, const phRangingParams_t *pRangingParam);

/**
 * @brief Get session specific ranging parameters

 * \param[in] sessionHandle         Initialized Session Handle
 * \param[out] pRangingParams   Pointer to \ref phRangingParams_t .Valid only if
 *                              API status is success
 *
 * \retval #UWBAPI_STATUS_OK on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                           sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetRangingParams(uint32_t sessionHandle, phRangingParams_t *pRangingParams);

#if UWBFTR_CCC
/**
 * @brief Set CCC Mandatory Application configuration parameters.
 *
 * \param[in] sessionHandle             Initialized Session Handle
 * \param[in] pCccRangingParam          Pointer to \p pCccRangingParam
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetCccRangingParams(uint32_t sessionHandle, const phCccRangingParams_t *pCccRangingParam);
#endif // UWBFTR_CCC

/**
 * @brief Set session specific app config parameters.
 *
 * \param[in] sessionHandle       Initialized Session Handle
 * \param[in] param_id   App Config Parameter Id
 * \param[in] param_value   Param value for App config param id
 *
 * \warning For setting STATIC_STS_IV and UWB_INITIATION_TIME, use UwbApi_SetAppConfigMultipleParams API.
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                           sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 * \note FOR SR1XXT and SR2XXT this API can only be used to set FIRA-specific AppCfgs.
 * \note RANGING_ROUND_USAGE and SCHEDULE_MODE parameters are mandated to set only in SESSION_STATE_INIT state.
 *
 */

EXTERNC tUWBAPI_STATUS UwbApi_SetAppConfig(uint32_t sessionHandle, eAppConfig param_id, uint32_t param_value);

/**
 * @brief Host shall use this API to set multiple application configuration parameters.
 * Number of Parameters also needs to be indicated.
 *
 * To easily set the AppParams list, following macros have been defined.
 *
 * UWB_SET_APP_PARAM_VALUE(Parameter, Value): This macro sets the value of the
 * corresponding parameter with the given Value.This shall be used to set
 * all types of values of 8 or 16 or 32 bit wide.For more than 32-bit values,
 * following macro shall be used.
 *
 * UWB_SET_APP_PARAM_ARRAY(Parameter, ArrayValue, Length): This macro sets the value
 * of the corresponding parameter as an array of 8bit. Length parameter contains the total
 * length of the array.
 *
 * Example: To set SFD Id to zero and static sts iv, macro shall be invoked as given below.
 *
 * @code
 * UWB_AppParams_List_t SetAppParamsList[] = {UWB_SET_APP_PARAM_VALUE(SFD_ID, 0)};
 * uint8_t static_sts_iv[] = {1,2,3,4,5,6};
 * UWB_AppParams_List_t SetAppParamsList[] = {UWB_SET_APP_PARAM_ARRAY(STATIC_STS_IV, static_sts_iv,
 * sizeof(static_sts_iv))};
 * @endcode
 *
 * \param[in] sessionHandle        Initialized Session Handle
 * \param[in] noOfparams       Number of App Config Parameters
 * \param[in] AppParams_List   Application parameters values in tlv format
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                            sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 * \note FOR SR1XXT and SR2XXT this API can only be used to set FIRA-specific AppCfgs.
 * \note RANGING_ROUND_USAGE and SCHEDULE_MODE parameters are mandated to set only in SESSION_STATE_INIT state.
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetAppConfigMultipleParams(
    uint32_t sessionHandle, uint8_t noOfparams, const UWB_AppParams_List_t *AppParams_List);

/** Helper macro to limit the parameters and avoid error case */
#define UWBAPI_SETAPPCONFIGMULTIPLEPARAMS(SESSION_HANDLE, PARMS_LIST) \
    UwbApi_SetAppConfigMultipleParams((SESSION_HANDLE), sizeof(PARMS_LIST) / sizeof(PARMS_LIST[0]), &PARMS_LIST[0])

#if !(UWBIOT_UWBD_SR04X)
/**
 * @brief Host shall use this API to set multiple Vendor specific application configuration parameters.
 * Number of Parameters also needs to be indicated.
 *
 * To easily set the AppParams list, following macros have been defined.
 *
 * UWB_SET_VENDOR_APP_PARAM_VALUE(Parameter, Value): This macro sets the value of the
 * corresponding parameter with the given Value.This shall be used to set
 * all types of values of 8 or 16 or 32 bit wide.For more than 32-bit values,
 * following macro shall be used.
 *
 * UWB_SET_VENDOR_APP_PARAM_ARRAY(Parameter, ArrayValue, Length): This macro sets the value
 * of the corresponding parameter as an array of 8bit. Length parameter contains the total
 * length of the array.
 *
 * Example: To set MAC Payload encryption Id to zero and antenna config tx, macro shall be invoked as given below.
 *
 * @code
 * UWB_VendorAppParams_List_t SetAppParamsList[] = {UWB_SET_VENDOR_APP_PARAM_VALUE(MAC_PAYLOAD_ENCRYPTION, 0)};
 * uint8_t antennas_configuration_tx[] = {1,2,3,4,5,6};
 * UWB_VendorAppParams_List_t SetAppParamsList[] = {UWB_SET_VENDOR_APP_PARAM_ARRAY(ANTENNAS_CONFIGURATION_TX,
 * antennas_configuration_tx, sizeof(antennas_configuration_tx))};
 * @endcode
 *
 * \param[in] sessionHandle             Initialized Session Handle
 * \param[in] noOfparams            Number of App Config Parameters
 * \param[in] vendorAppParams_List  vendor specific Application parameters values in tlv format
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                            sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetVendorAppConfigs(
    uint32_t sessionHandle, uint8_t noOfparams, const UWB_VendorAppParams_List_t *vendorAppParams_List);

#endif // !(UWBIOT_UWBD_SR04X)
/**
 * @brief Get session specific app config parameters.
 *
 * \param[in] sessionHandle       Initialized Session Handle
 * \param[in] param_id   App Config Parameter Id
 * \param[out] param_value   Param value for App config param id
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                           sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 * \note FOR SR1XXT and SR2XXT this API can only be used to get FIRA-specific AppCfgs.
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetAppConfig(uint32_t sessionHandle, eAppConfig param_id, uint32_t *param_value);

/**
 * @brief Host shall use this API to get multiple application configuration parameters.
 * Number of Parameters also needs to be indicated.
 *
 * Following macros can be used, to easily set the AppParams list
 *
 * UWB_SET_GETAPP_PARAM(Parameter): This macro sets parameter, in UWB_AppParams_List_t structure.
 * This shall be used to get all types of values of 8 or 16 or 32 bit wide.
 * For more than 32-bit values, following macro shall be used.
 *
 * UWB_SET_APP_PARAM_ARRAY(Parameter, ArrayValue, Length): This macro sets parameter and array of 8bit
 * to store the configuration, in UWB_AppParams_List_t structure Length parameter contains the total
 * length of the array.
 *
 * Example: To get SFD Id and static sts iv, macro shall be invoked as given below.
 *
 * @code
 * uint8_t static_sts_iv[6];
 * UWB_AppParams_List_t SetAppParamsList[] = {UWB_SET_GETAPP_PARAM_VALUE(SFD_ID),
 *                                       UWB_SET_APP_PARAM_ARRAY(STATIC_STS_IV, static_sts_iv, sizeof(static_sts_iv)),};
 * @endcode
 *
 * \param[in] sessionHandle        Initialized Session Handle
 * \param[in] noOfparams       Number of App Config Parameters
 * \param[in] AppParams_List   Application parameters
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                            sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 * \note FOR SR1XXT and SR2XXT this API can only be used to get FIRA-specific AppCfgs.
 *
 */

EXTERNC tUWBAPI_STATUS UwbApi_GetAppConfigMultipleParams(
    uint32_t sessionHandle, uint8_t noOfparams, UWB_AppParams_List_t *AppParams_List);

#if !(UWBIOT_UWBD_SR04X)
/**
 * @brief Host shall use this API to get multiple vendor application configuration parameters.
 * Number of Parameters also needs to be indicated.
 *
 * Following macros can be used, to easily set the AppParams list
 *
 * UWB_SET_GETVENDOR_APP_PARAM_VALUE(Parameter): This macro sets parameter, in UWB_VendorAppParams_List_t structure.
 * This shall be used to get all types of values of 8 or 16 or 32 bit wide.
 * For more than 32-bit values, following macro shall be used.
 *
 * UWB_VENDOR_SET_APP_PARAM_ARRAY(Parameter, ArrayValue, Length): This macro sets parameter and array of 8bit
 * to store the configuration, in UWB_VendorAppParams_List_t structure Length parameter contains the total
 * length of the array.
 *
 * Example: To get MAC Payload encryption Id and antenna config tx, macro shall be invoked as given below.
 *
 * @code
 * uint8_t antennas_configuration_tx[6];
 * UWB_VendorAppParams_List_t SetAppParamsList[] = {UWB_SET_GETVENDOR_APP_PARAM_VALUE(MAC_PAYLOAD_ENCRYPTION),
 *                                       UWB_VENDOR_SET_APP_PARAM_ARRAY(ANTENNAS_CONFIGURATION_TX,
 * antennas_configuration_tx, sizeof(antennas_configuration_tx)),};
 * @endcode
 *
 * \param[in] sessionHandle        Initialized Session Handle
 * \param[in] noOfparams       Number of App Config Parameters
 * \param[in] vendorAppParams_List   Vendor Application parameters
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                            sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */

EXTERNC tUWBAPI_STATUS UwbApi_GetVendorAppConfigs(
    uint32_t sessionHandle, uint8_t noOfparams, UWB_VendorAppParams_List_t *vendorAppParams_List);

#endif // !(UWBIOT_UWBD_SR04X)
/**
 * @brief Sets session specific app config parameters Vendor ID and Static STS
 * IV.
 *
 * \param[in] sessionHandle       Initialized Session Handle
 * \param[in] vendorId        App Config Parameter Vendor Id
 * \param[in] staticStsIv     Param value for App config param static Sts Iv
 *                            It is the responsibility of the caller that
 *                            STS IV is exactly UCI_PARAM_LEN_STATIC_STS_IV
 *                            bytes long.
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                           sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetStaticSts(uint32_t sessionHandle, uint16_t vendorId, uint8_t const *const staticStsIv);

/**
 * @brief Start Ranging for a session. Before Invoking Start ranging its
 * mandatory to set all the ranging configurations.
 *
 * \param[in] sessionHandle   Initialized Session Handle
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST  if session is not initialized with
 *                                           sessionHandle
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_StartRangingSession(uint32_t sessionHandle);

/**
 * @brief Sets device configuration
 *
 * \param[in] param_id        device configuration param id
 * \param[in] param_len       Parameter length
 * \param[in] param_value     Param value
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetDeviceConfig(
    eDeviceConfig param_id, uint8_t param_len, phDeviceConfigData_t *param_value);

/**
 * @brief Get device config parameters.
 *
 * \param[in] param_id      Device Config Parameter Id
 * \param[in,out] param_value   Param value structure for device config param id
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetDeviceConfig(eDeviceConfig param_id, phDeviceConfigData_t *param_value);

/**
 * @brief Stop Ranging for a session
 *
 * \param[in] sessionHandle   Initialized Session Handle
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_StopRangingSession(uint32_t sessionHandle);

/**
 * @brief Enable Ranging Data Notifications different options.

 * \param[in] sessionHandle              Initialized Session Handle
 * \param[in] enableRangingDataNtf   Enable Ranging data notification  0/1/2.
 option 2 is not allowed when ranging is ongoing.
 * \param[in] proximityNear          Proximity Near value valid if
 enableRangingDataNtf sets to 2
 * \param[in] proximityFar           Proximity far value valid if
 enableRangingDataNtf sets to 2
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_EnableRangingDataNtf(
    uint32_t sessionHandle, uint8_t enableRangingDataNtf, uint16_t proximityNear, uint16_t proximityFar);

/**
 * @brief Get Session State
 *
 * \param[in] sessionHandle      Initialized Session Handle
 * \param[out] sessionState   Session Status
 *
 * \retval #UWBAPI_STATUS_OK                on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED   if UCI stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM     if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT           if command is timeout
 * \retval #UWBAPI_STATUS_FAILED            otherwise
 *
 * - If API returns #UWBAPI_STATUS_OK, Session State would be one of the below values
 *  - #UWBAPI_SESSION_INIT_SUCCESS     - Session is Initialized
 *  - #UWBAPI_SESSION_DEINIT_SUCCESS   - Session is De-initialized
 *  - #UWBAPI_SESSION_ACTIVATED        - Session is Busy
 *  - #UWBAPI_SESSION_IDLE             - Session is Idle
 *  - #UWBAPI_SESSION_ERROR            - Session Not Found
 *
 * - If API doesn't return #UWBAPI_STATUS_OK, Session State is set to
 *  - #UWBAPI_SESSION_ERROR            - Error in getting the session state.
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetSessionState(uint32_t sessionHandle, uint8_t *sessionState);

/**
 * @brief Send UCI RAW command.
 *
 * \param[in] data       UCI Command to be sent
 * \param[in] data_len   Length of the UCI Command
 * \param[out] pResp      Response Received
 * \param[out] pRespLen   Response length
 *
 * \retval #UWBAPI_STATUS_OK               if successful
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UCI stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if wrong parameter is passed
 * \retval #UWBAPI_STATUS_BUFFER_OVERFLOW  if response buffer is not sufficient
 *                                          to hold the response
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SendRawCommand(uint8_t data[], uint16_t data_len, uint8_t *pResp, uint16_t *pRespLen);
/**
 * @brief Update Controller Multicast List.
 *
 * \param[in]  pControleeContext         Controlee in Context of type phMulticastControleeListContext_t
 * \param[out] pControleeListRspContext  Controlee Out Context of type phMulticastControleeListRspContext_t
 *
 * \note The out param, pControleeListRspContext is updated only if response status is UWBAPI_STATUS_FAILED.
 *
 * \retval #UWBAPI_STATUS_OK                        On success
 * \retval #UWBAPI_STATUS_REJECTED                  If command is called in SESSION_STATE_INIT
 * \retval #UWBAPI_STATUS_ERROR_MULTICAST_LIST_FULL If the multicast list is full, while adding controlee to list
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED           If UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM             If invalid parameters are passed
 * \retval #UWBAPI_STATUS_FAILED                    Otherwise, please refer specification for the appropriate Status.
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_UpdateControllerMulticastList(phMulticastControleeListContext_t *pControleeContext,
    phMulticastControleeListRspContext_t *pControleeListRspContext);
/**
 * @brief Get TRNG api.
 *
 * \param[in] trng_size   Size of ptrng buffer and number of bytes expected
 * \param[out] ptrng   : the size of this buffer shall be equal to trng size.
 *
 * \warning On SR040, maximum 4 bytes can be drawn during an active ranging session
 *
 * \retval #UWBAPI_STATUS_OK                 on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED    if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM      if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT            if command is timeout
 * \retval #UWBAPI_STATUS_FAILED             otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetTrng(uint8_t trng_size, uint8_t *ptrng);

#if (UWBFTR_BlobParser)
/**
 * @brief Setting up Profile blob.
 *
 * \param[in]      pProfileBlob : Profile Blob which contain all information.
 * \param[in]      blobSize     : Size of Blob
 * \param[in,out]  pProfileInfo : contains profile information.
 *
 * \retval #UWBAPI_STATUS_OK                on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED   if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM     if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT           if command is timeout
 * \retval #UWBAPI_STATUS_FAILED            otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetProfileParams(
    uint8_t *pProfileBlob, uint16_t blobSize, phUwbProfileInfo_t *pProfileInfo);

/**
 * @brief Fill Accessory UWB related configuration data.
 * \param device_role                -[in] device role
 * \param uwb_data_content           -[Out] Pointer to structure of AccessoryUwbConfigDataContent_t
 *
 * \retval #UWBAPI_STATUS_OK                - on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED   - if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM     - if invalid parameters are passed
 * \retval #UWBAPI_STATUS_FAILED            - otherwise
 *
 */
tUWBAPI_STATUS UwbApi_GetUwbConfigData_iOS(
    UWB_DeviceRole_t device_role, AccessoryUwbConfigDataContent_t *uwb_data_content);

/**
 * \brief Populates the accessory UWB configuration data structure for Android.
 *
 * This API fills the provided \p UwbDeviceConfigData_t structure with UWB-related
 * configuration parameters required for accessory operation.
 *
 * \param[in,out] uwb_data_content Pointer to a \p UwbDeviceConfigData_t structure that will be populated.
 *
 * \note To enable Findhub-specific configuration, the caller must set
 *       \p uwb_data_content->isFindhubEnabled = true before invoking this API.
 *       When this flag is enabled, the following fields in \p UwbDeviceConfigData_t
 *       will be populated with Findhub-specific values:
 *       - supported_config_ids
 *       - ranging_role
 *       - device_mac_addr
 *       - ranging_technology_role
 *       - payload_size
 *       - supported_channels
 *       - preamble_index
 *       - ranging_interval
 *       - slot_duration
 *
 * \retval UWBAPI_STATUS_OK               On success.
 * \retval UWBAPI_STATUS_NOT_INITIALIZED If the UWB stack is not initialized.
 * \retval UWBAPI_STATUS_INVALID_PARAM   If invalid parameters are passed.
 * \retval UWBAPI_STATUS_FAILED          On general failure.
 */
tUWBAPI_STATUS UwbApi_GetUwbConfigData_Android(UwbDeviceConfigData_t *uwb_data_content);

#endif // (UWBFTR_BlobParser)

/**
 * @brief Frames the device capabilities in TLV format.
 *
 * \param pDevCap    - [Out] Pointer to structure of device capability data
 *
 * \retval #UWBAPI_STATUS_OK                - on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED   - if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM     - if invalid parameters are passed
 * \retval #UWBAPI_STATUS_FAILED            - otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetDeviceCapability(phUwbCapInfo_t *pDevCap);

#if UWBFTR_DataTransfer
/**
 * @brief Host shall use this API to send data over UWB interface.
 * - If SESSION_DATA_TRANSFER_STATUS_NTF is disabled, then the UWBS shall not send SESSION_DATA_TRANSFER_STATUS_NTF for
 * every Application Data transmission except for last.
 *
 * @warning There is a possibility of UwbApi_SendData API returning Timeout (UWBAPI_STATUS_FAILED status) in the
 * following sceanrio. Although API status is failed but the outcome of testing scenario to be treated as SUCCESS only.
 *
 * Example: SESSION_DATA_TRANSFER_STATUS_NTF=0(Disable) and DATA_REPETITION_COUNT=5 and RANGING_ROUND_USAGE=200 ms
 *
 * UWA_DM_DATA_TRANSMIT_STATUS_EVT will receive after 1,000 ms (DATA_REPETITION_COUNT * RANGING_ROUND_USAGE )
 *
 * - Limitation:
 *
 *  - Notification Read Timeout : Reading UWA_DM_DATA_TRANSMIT_STATUS_EVT Notification from the UWB will result in a
 * read timeout if UWB Notification time exceeds the define limit.
 *  - Example: if DATA_REPETITION_COUNT=60 and SESSION_DATA_TRANSFER_STATUS_NTF=0 and RANGING_ROUND_USAGE=200 ms then
 * UWA_DM_DATA_TRANSMIT_STATUS_EVT will receive after ~12 secs (DATA_REPETITION_COUNT * RANGING_ROUND_USAGE) by that
 * time UwbApi_SendData API time out will happen .
 *
 * \param[in] pSendData   Send Data Content
 *
 * \retval #UWBAPI_STATUS_OK                   on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED      if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM        if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT              if command is timeout
 * \retval #UWBAPI_STATUS_REJECTED             if session is not established when data packet sent
 * \retval #UWBAPI_STATUS_NO_CREDIT_AVAILABLE  if buffer is not available to accept data
 * \retval #UWBAPI_STATUS_DATA_TRANSFER_ERROR  if data is not sent due to an unrecoverable error
 * \retval #UWBAPI_STATUS_FAILED               otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SendData(phUwbDataPkt_t *pSendData);
#endif // UWBFTR_DataTransfer
#if !(UWBIOT_UWBD_SR04X)
/**
 * @brief API to get max data size that can be transferred during a single ranging round.
 *
 * \param[inout] pQueryDataSize               Pointer to structure of Query Data Size
 *
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 * \retval #UWBAPI_STATUS_UNKNOWN          Unknown error
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 *
 * \note This API must be called in session active state.
 */
tUWBAPI_STATUS UwbApi_SessionQueryDataSize(phUwbQueryDataSize_t *pQueryDataSize);
#endif // !(UWBIOT_UWBD_SR04X)

#if !(UWBIOT_UWBD_SR04X)
/**
 * @brief Frames the HUS session config in TLV format for Controller.
 *
 * \param[in]   pHusSessionCfg              : Pointer to structure of device HUS Controller session config data.
 *
 * \retval #UWBAPI_STATUS_OK                                        on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED                           if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST                         if Session is not existing or not created.
 * \retval #UWBAPI_STATUS_SESSION_NOT_CONFIGURED                    if Session is not configured with required app configurations.
 * \retval #UWBAPI_STATUS_ERROR_SESSION_INVALID_SLOT_DURATION       if Slot duration of the secondary session is not integer multiple of the slot duration of primary session.
 * \retval #UWBAPI_STATUS_ERROR_SESSION_INVALID_SLOT_ALLOCAION      if Slot allocation for phases is not correct.
 * \retval #UWBAPI_STATUS_TIMEOUT                                   if command is timeout
 * \retval #UWBAPI_STATUS_FAILED                                    otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetControllerHusSession(phControllerHusSessionConfig_t *pHusSessionCfg);

/**
 * @brief Frames the HUS session config in TLV format for Controlee.
 *
 * \param[in]   pHusSessionCfg              : Pointer to structure of device HUS Controlee session config data.
 *
 * \retval #UWBAPI_STATUS_OK                                        on success
 * \retval #UWBAPI_STATUS_REJECTED                                  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST                         if Session is not existing or not created.
 * \retval #UWBAPI_STATUS_ERROR_SESSION_INVALID_SLOT_DURATION       if Slot duration of the secondary session is not integer multiple of the slot duration of primary session.
 * \retval #UWBAPI_STATUS_SESSION_NOT_CONFIGURED                    if command is timed out
 * \retval #UWBAPI_STATUS_ERROR_SESSION_INVALID_SLOT_ALLOCAION      if Slot allocation for phases is not correct.
 * \retval #UWBAPI_STATUS_FAILED                                    otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_SetControleeHusSession(phControleeHusSessionConfig_t *pHusSessionCfg);

/**
 * @brief Frames the Data Transfer Phase Control Message in TLV format.
 *
 * \param phDataTxPhaseCfg    - Pointer to structure of Data Transfer Phase Configuration.
 *
 * \retval #UWBAPI_STATUS_OK                            - If DTPCM is configured for given MAC Address.
 * \retval #DTPCM_STATUS_ERROR_DUPLICATE_SLOT_ASSIGMENT - Reported when configured slot assignments is inconsistent, i.e., one slot is
 *                                                         assigned to more than one FiRA device
 * \retval #DTPCM_STATUS_ERROR_DTPML_OVERSIZE           - Reported when configured slot assignments cannot fit within one DTPCM.
 * \retval #DTPCM_STATUS_OK_DTPML_REPETITION_DISABLED   - Reported when DTPCM Repetition is set to 0x01 but the last assigned slot is not
 *                                                         assigned to the Controller. UWBS proceeds as if Repetition is 0x00.
 * \retval #UWBAPI_STATUS_TIMEOUT                       - If command is timed out
 * \retval #UWBAPI_STATUS_INVALID_PARAM                 - If given MAC address is not found.
 * \retval #UWBAPI_STATUS_FAILED                        - otherwise
 *
 * @note If application gets the notification UWBD_DATA_TRANSFER_PHASE_CONFIG_NTF, refer @ref eDataTxPhaseCfg_NftCode for status codes.
 */
EXTERNC tUWBAPI_STATUS UwbApi_SessionDtpcmConfig(phDataTxPhaseConfig_t *phDataTxPhaseCfg);

#if UWBFTR_DataTransfer
/**
 * \brief Creates Logical Link for Data Transfer.
 *
 * \param[in]    phLogicalLinkCreateCmd - Pointer to structure that contains params to create Logical Link.
 * \param[out]   pLogicalLinkConnectId  - Pointer to uint32 that return the Logical Link connect ID.
 *
 *
 * \retval #UWBAPI_STATUS_OK                                        on success
 * \retval #UWBAPI_STATUS_REJECTED                                  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST                         if Session is not existing or not created.
 * \retval #UWBAPI_STATUS_TIMEOUT                                   if command is timeout
 * \retval #UWBAPI_STATUS_INVALID_PARAM                             if invalid parameters are passed
 * \retval #UWBAPI_STATUS_FAILED                                    otherwise
 *
 * \note : The logical Link can be created in either in UWBAPI_SESSION_IDLE or UWBAPI_STATUS_SESSION_ACTIVE,
 *         In case of Connection Oriented mode if it is called in UWBAPI_SESSION_IDLE the application has to take care
 *         of the synchronization of UwbApi_LogicalLinkSendData till the LOGICAL_LINK_CREATE_NTF with LOGICAL_CO_LINK_CONNECTED is received.
 *
 * \note In case of SHORT_ADDR mode is used, then each Octet from octets 2 - 7 shall be set to 0x00.
 */
EXTERNC tUWBAPI_STATUS UwbApi_CreateLogicalLink(
    phLogicalLinkCreateCmd_t *phLogicalLinkCreateCmd, uint32_t *pLogicalLinkConnectId);

/**
 * \brief Closes Logical Link for Data Transfer, that was established before.
 *
 * \param[in] LogicalLinkConnectId   - Session Handle value for which Logical Link would be created.
 *
 * \retval #UWBAPI_STATUS_OK                                        on success
 * \retval #UWBAPI_STATUS_REJECTED                                  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST                         if Session is not existing or not created.
 * \retval #UWBAPI_STATUS_TIMEOUT                                   if command is timeout
 * \retval #UWBAPI_STATUS_INVALID_PARAM                             if invalid parameters are passed
 * \retval #UWBAPI_STATUS_FAILED                                    otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_CloseLogicalLink(uint32_t LogicalLinkConnectId);

/**
 * @brief Host shall use this API to send data over Logical Link.
 *
 * \param[in] pllSendData   Send Data Content
 *
 *
 * \retval #UWBAPI_STATUS_OK                   on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED      if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM        if invalid parameters are passed
 * \retval #UWBAPI_STATUS_TIMEOUT              if command is timeout
 * \retval #UWBAPI_STATUS_REJECTED             if session is not established when data packet sent
 * \retval #UWBAPI_STATUS_NO_CREDIT_AVAILABLE  if buffer is not available to accept data
 * \retval #UWBAPI_STATUS_DATA_TRANSFER_ERROR  if data is not sent due to an unrecoverable error
 * \retval #UWBAPI_STATUS_FAILED               otherwise
 *
 */
EXTERNC tUWBAPI_STATUS UwbApi_LogicalLinkSendData(uwb_ll_data_receive_notification_t *pllSendData);

/**
 * \brief Gets the Logical Link parameters for the given connect ID. The API can be called to get
 * the Logical Link parameters used for the logical link associated to the LL_CONNECT_ID or the Session
 * Handle associated to the session.
 *
 * \param[in] ConnectionIdentifier       - This can be either the CONNECT_ID or the Session Handle. Identifies the link
 *                                         or the data transfer session/phase params.
 * \param[out] phLogicalLinkGetParamsRsp - Pointer to structure that contains
 * params for Logical Link.
 *
 * \retval #UWBAPI_STATUS_OK                    On success
 * \retval #UWBAPI_STATUS_REJECTED              If UWB stack is not initialized
 * \retval #UWBAPI_STATUS_SESSION_NOT_EXIST     If Session is not existing or not created.
 * \retval #UWBAPI_STATUS_TIMEOUT               If command is timeout
 * \retval #UWBAPI_STATUS_INVALID_PARAM         If invalid parameters are passed
 * \retval #UWBAPI_STATUS_FAILED                Otherwise
 *
 * \note To get the Link parameters of the Link created, this API needs to be called in UWBAPI_STATUS_SESSION_ACTIVE
 * with the LL_CONNECT_ID. To get the default Link Params for the session, this API is to be called in either
 * in UWBAPI_STATUS_SESSION_ACTIVE or UWBAPI_STATUS_SESSION_IDLE with session handle of the session.
 */
EXTERNC tUWBAPI_STATUS UwbApi_LogicalLinkGetParams(
    uint32_t ConnectionIdentifier, phLogicalLinkGetParamsRsp_t *phLogicalLinkGetParamsRsp);

#endif // UWBFTR_DataTransfer

#endif // !(UWBIOT_UWBD_SR04X)

#ifdef __cplusplus
} // closing brace for extern "C"
#endif

/** @}  */ /* @addtogroup Uwb_Apis */
#endif     // UWBAPI_H
