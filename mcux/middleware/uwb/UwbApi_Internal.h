/*
 *
 * Copyright 2018-2020,2022-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UWBAPI_INTERNAL_H
#define UWBAPI_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "phUwbStatus.h"
#include "phUwbTypes.h"
#include "UwbApi_Types.h"
#if !(UWBIOT_UWBD_SR04X)
#include "UwbApi_Types_RfTest.h"
#endif // !(UWBIOT_UWBD_SR04X)
#include <UwbApi_Types_Proprietary.h>
#include "zephyr/uwb/uwb_types.h"
#include "zephyr/uwb/uwb_core.h"
#include "uci_prop_defs.h"

#define SES_ID_AND_NO_OF_PARAMS_OFFSET 0x05

#define TIMESTAMP_LEN     8
#define RFU_SHORT_MAC_ADD 11
#define RFU_EXT_MAC_ADD   5
#define RESERVED_LEN      4
/*these offset are used for tracing rcv data ntf length*/
#define MAC_ADDR_OFFSET 25
/** Range Data Notification Offset for TWR
 * For Short Addressing Mode : MacAddr(2B) + OtherFields(18B) + RFU(11B)
 * For Ext Addressing Mode : MacAddr(8B) + OtherFields(18B) + RFU(5B)
 * In both Addrressing Modes the length sums out to be 31B
 */
#define MAX_TWR_RNG_DATA_NTF_OFFSET 31
#define ONEWAY_RFU_BYTE_OFFSET      (12)
#define TLV_BUFFER_OFFSET           2

/* Session ID RF Test */
/**  Session ID used for RF TEST Mode */
#define SESSION_ID_RFTEST 0x00000000

/* UWA_DM callback events */
#define UWA_DM_RSP_EVENT     0x00
#define UWA_DM_NTF_EVENT     0xA0
#define UWA_DM_EXT_NTF_EVENT 0xD0

/* 4Bytes(sessionHandle) + 1Byte(radarstatus) + 1Byte(radar_type) + 2Bytes(num_cirs) + 1Byte(cir_taps) + 1Byte(RFU)*/
#define RADAR_CIR_NTF_HEADER 0x0A

/* 4Bytes(sessionHandle) + 1Byte(radarstatus) + 1Byte(radar_type)*/
#define RADAR_RX_NTF_HEADER 0x06

#define RADAR_NTF_RADAR_TYPE_OFFSET 5

typedef enum Response_Rsp_Event
{
    /* Result of UWA_Enable             */
    UWA_DM_ENABLE_EVT = UWA_DM_RSP_EVENT,
    /* Result of UWA_Disable            */
    UWA_DM_DISABLE_EVT,
    /* Result of UWA Register Ext Callback */
    UWA_DM_REGISTER_EXT_CB_EVT,
    /* Result of command response timeout */
    UWA_DM_UWBD_RESP_TIMEOUT_EVT,
    /* Result of get device info */
    UWA_DM_CORE_GET_DEVICE_INFO_RSP_EVT,
    /* Result of UWA_SetCoreConfig          */
    UWA_DM_CORE_SET_CONFIG_RSP_EVT,
    /* Result of get core config          */
    UWA_DM_CORE_GET_CONFIG_RSP_EVT,
    /* Result of Core Dev Reset */
    UWA_DM_DEVICE_RESET_RSP_EVT,
    /* Result of session Init cmd */
    UWA_DM_SESSION_INIT_RSP_EVT,
    /* Result of session Deinit cmd */
    UWA_DM_SESSION_DEINIT_RSP_EVT,
    /* Result of set app config */
    UWA_DM_SESSION_SET_CONFIG_RSP_EVT,
    /* Result of get app config */
    UWA_DM_SESSION_GET_CONFIG_RSP_EVT,
    /* Result of get session count */
    UWA_DM_SESSION_GET_COUNT_RSP_EVT,
    /* Result of get session count */
    UWA_DM_SESSION_GET_STATE_RSP_EVT,
    /* Result of range start cmd */
    UWA_DM_RANGE_START_RSP_EVT,
    /* Result of range stop cmd */
    UWA_DM_RANGE_STOP_RSP_EVT,
    /* Result of get core device capability  */
    UWA_DM_GET_CORE_DEVICE_CAP_RSP_EVT = 17, /* changed as it would clash with OID SE comm error */
    /* Session Update Multicast List resp event*/
    UWA_DM_SESSION_MC_LIST_UPDATE_RSP_EVT,
    /* Blink Data Tx event*/
    UWA_DM_SEND_BLINK_DATA_RSP_EVT = 20, /* changed as it would clash with OID SE bind error */
    /* Result of update active rounds anchor rsp event */
    UWA_DM_SESSION_UPDATE_DT_ANCHOR_RANGING_ROUNDS_RSP_EVT,
    /* Result of update active rounds receiver rsp event */
    UWA_DM_SESSION_UPDATE_DT_TAG_RANGING_ROUNDS_RSP_EVT,
#if UWBFTR_TransitProp
    /** Reseult of Set RDS Param rsp event */
    UWA_DM_SESSION_SET_RDS_PARAM_RSP_EVT,
#endif // UWBFTR_TransitProp
#if !(UWBIOT_UWBD_SR04X)
    /* Result of Get Data Size in Ranging */
    UWA_DM_SESSION_QUERY_DATA_SIZE_IN_RANGING_RSP_EVT,
#endif // !(UWBIOT_UWBD_SR04X)
    /* Result of test set config event */
    UWA_DM_TEST_SET_CONFIG_RSP_EVT,
    /* Result of test get config event */
    UWA_DM_TEST_GET_CONFIG_RSP_EVT,
    /* Result of test stop session response event */
    UWA_DM_TEST_STOP_SESSION_RSP_EVT,
    /* Result of test periodic tx response event */
    UWA_DM_TEST_PERIODIC_TX_RSP_EVT,
    /* Result of test per rx response event */
    UWA_DM_TEST_PER_RX_RSP_EVT,
    /* Result of test Loop Back response event */
    UWA_DM_TEST_LOOPBACK_RSP_EVT,
    /* Result of test RX Test resp event*/
    UWA_DM_TEST_RX_RSP_EVT,
    /* To start the Security level test*/
    UWA_DM_TEST_SR_RX_RSP_EVT,
    /* Result of Calibration Integrity Protection Resp event */
    UWA_DM_PROP_CALIB_INTEGRITY_PROTECTION_RESP_EVT,
    /* Result of Generate Tag Resp event */
    UWA_DM_PROP_GENERATE_TAG_RESP_EVT,
    /* Result of Verify Calib Data Resp event */
    UWA_DM_PROP_VERIFY_CALIB_DATA_RESP_EVT,
    /* Result of Do Bind Resp event */
    UWA_DM_PROP_DO_BIND_RESP_EVT,
    /* Result of Get Binding Count Resp event */
    UWA_DM_PROP_GET_BINDING_COUNT_RESP_EVT,
    /* Result of Test Connectivity Resp event */
    UWA_DM_PROP_TEST_CONNECTIVITY_RESP_EVT,
    /* Result of SE Test Loop Resp event */
    UWA_DM_PROP_SE_TEST_LOOP_RESP_EVT,
    /* Result of Get Binding Status Resp event */
    UWA_DM_PROP_GET_BINDING_STATUS_RESP_EVT,
    /* Result of Query Temperature Resp event */
    UWA_DM_PROP_QUERY_TEMPERATURE_RESP_EVT,
    /* Result of Configure Auth Tag Options Resp event */
    UWA_DM_PROP_CONFIGURE_AUTH_TAG_OPTION_RESP_EVT,
    /* Result of Configure Auth Tag Version Resp event */
    UWA_DM_PROP_CONFIGURE_AUTH_TAG_VERSION_RESP_EVT,
    /* Result of URSK Deletion Request Resp event */
    UWA_DM_PROP_URSK_DELETION_REQUEST_RESP_EVT,
    /* Result of Query UWB Timestamp Resp event */
    UWA_DM_PROP_QUERY_TIMESTAMP_RESP_EVT,
    /* Result of get all uwb sessions rsp event */
    UWA_DM_VENDOR_GET_ALL_UWB_SESSION_RSP_EVT,
    /* Result of write otp calib data rsp event */
    UWA_DM_PROP_WRITE_OTP_CALIB_DATA_RSP_EVT,
    /* Result of read otp calib data rsp event */
    UWA_DM_PROP_READ_OTP_CALIB_DATA_RSP_EVT,
    /* Result of Data Transfer Phase Configuration Resp event */
    UWA_DM_SESSION_DATA_TRANSFER_PHASE_CONFIG_RSP_EVT,
    /* Result of get session */
    UWA_DM_SESSION_SET_HUS_CONTROLLER_CONFIG_RSP_EVT,
    /* Result of get session */
    UWA_DM_SESSION_SET_HUS_CONTROLEE_CONFIG_RSP_EVT,
    /* Result of Vendor set app config */
    UWA_DM_SESSION_SET_VENDOR_CONFIG_RSP_EVT,
    /* Result of vendor get app config */
    UWA_DM_SESSION_GET_VENDOR_CONFIG_RSP_EVT,
#if !(UWBIOT_UWBD_SR04X)
    /* Result of do Calibration Resp event */
    UWA_DM_VENDOR_DO_CHIP_CALIBRATION_RESP_EVT,
    /* Result of Set Device Calibration Resp event */
    UWA_DM_VENDOR_SET_DEVICE_CALIBRATION_RESP_EVT,
    /* Result of Set Calibration Resp event */
    UWA_DM_VENDOR_GET_DEVICE_CALIBRATION_RESP_EVT,
#endif // !(UWBIOT_UWBD_SR04X)
    /* Result of TRNG  rsp event */
    UWA_DM_PROP_TRNG_RESP_EVENT,
#if (UWBIOT_UWBD_SR04X)
    /* Result of suspend device rsp event */
    UWA_DM_PROP_SUSPEND_DEVICE_RSP_ENVT,
    /* Result of NVM payload rsp event */
    UWA_DM_SESSION_NVM_PAYLOAD_RSP_EVENT,
    /* Result of start test mode rsp event */
    UWA_DM_START_TEST_MODE_RSP_EVENT,
    /* Result of stop test mode rsp event */
    UWA_DM_STOP_TEST_MODE_RSP_EVENT,
    /* Result of set calibration rsp event */
    UWA_DM_SET_CALIB_TRIM_RSP_EVENT,
    /* Result of get calibration rsp event */
    UWA_DM_GET_CALIB_TRIM_RSP_EVENT,
    /* Result of get calibration rsp event */
    UWA_DM_GET_BYPASS_CURRENT_LIMITER,
#endif
#if (UWBFTR_BlobParser)
    /* Result of profile blob rsp event */
    UWA_DM_PROP_PROFILE_BLOB_RSP_EVENT,
#endif // (UWBFTR_BlobParser)
#if UWBFTR_DataTransfer
    /* Result of Create Logical Link Resp event */
    UWA_DM_SESSION_CREATE_LOGICAL_LINK_RSP_EVT,
    /* Result of Logical Link Close Resp event */
    UWA_DM_SESSION_LOGICAL_LINK_CLOSE_RSP_EVT,
    /* Result of Logical Link Get Param Resp event */
    UWA_DM_SESSION_LOGICAL_LINK_GET_PARAM_RSP_EVT,
#endif // UWBFTR_DataTransfer

#if UWBIOT_UWBD_SR2XXT
    UWA_DM_VENDOR_SET_SECURE_CALIB_RSP_EVT,
#endif // UWBIOT_UWBD_SR2XXT
#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    /* Result of Write module maker Resp event */
    UWA_DM_WRITE_MODULE_MAKER_RSP_EVT,
    /* Result of Read module maker Resp event */
    UWA_DM_READ_MODULE_MAKER_RSP_EVT,
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    /* results of SESSION_SET_LOCALIZATION_ZONE_CMD rsp event  */
    UWA_DM_SESSION_SET_LOCALIZATION_ZONE_RSP_EVENT,
    /* results of GET_ESE_SESSION_ID_LIST_CMD resp event */
    UWA_DM_PROP_GET_ESE_SESSION_ID_LIST_RSP_EVT,
    /* Result of invalid rsp event*/
    UWA_DM_INVALID_RSP_EVT = 0xFF
} eResponse_Rsp_Event;

/* UWA_DM callback events for UWB RF events */
typedef enum Response_Ntf_Event
{
    /* Result of device status ntf */
    UWA_DM_DEVICE_STATUS_NTF_EVT = UWA_DM_NTF_EVENT,
    /* Result of core generic error status */
    UWA_DM_CORE_GEN_ERR_STATUS_EVT,
    /* Result of session NTF  */
    UWA_DM_SESSION_STATUS_NTF_EVT,
    /* Result of session info ntf */
    UWA_DM_SESSION_INFO_NTF_EVT,
    /* Result of data credit notification*/
    UWA_DM_DATA_CREDIT_STATUS_EVT,
    /* Result of data transmit status notification*/
    UWA_DM_DATA_TRANSMIT_STATUS_EVT,
    /* Session Update Multicast List ntf event*/
    UWA_DM_SESSION_MC_LIST_UPDATE_NTF_EVT,
    /* Blink Data Tx ntf event*/
    UWA_DM_SEND_BLINK_DATA_NTF_EVT,
    /* Data Transfer Phase Configuration NTF event */
    UWA_DM_SESSION_DATA_TRANSFER_PHASE_CONFIG_NTF_EVT,
    /* Result of test periodic tx NTF event */
    UWA_DM_TEST_PERIODIC_TX_NTF_EVT,
    /* Result of test per rx NTF event */
    UWA_DM_TEST_PER_RX_NTF_EVT,
    /* Result of test TEST_SR_RX_NTF event */
    UWA_DM_TEST_TEST_SR_RX_NTF_EVT,
    /* Result of test Loop Back NTF event */
    UWA_DM_TEST_LOOPBACK_NTF_EVT,
    /* Result of test RX Test NTF event*/
    UWA_DM_TEST_RX_NTF_EVT,
#if UWBFTR_DataTransfer
    /* Result of test RX Test NTF event*/
    UWA_DM_DATA_RCV_NTF_EVT,
    /* Result of Logical Data RX NTF event*/
    UWA_DM_LOGICAL_DATA_RCV_NTF_EVT,
#endif // UWBFTR_DataTransfer
#if UWBFTR_CCC
    /* Result of range CCC data ntf */
    UWA_DM_RANGE_CCC_DATA_NTF_EVT,
#endif // UWBFTR_CCC
#if UWBFTR_DataTransfer
    /* Result of Logical Link Create Notification */
    UWA_DM_SESSION_LOGICAL_LINK_CREATE_NTF_EVT,
    /* Result of Logical Link Close with UWBS Notification */
    UWA_DM_SESSION_LOGICAL_LINK_UWBS_CLOSE_NTF_EVT,
    /* Result of Logical Link Create with UWBS Notification */
    UWA_DM_SESSION_LOGICAL_LINK_UWBS_CREATE_NTF_EVT,
#endif // UWBFTR_DataTransfer
    /* Result of new session role change ntf */
    UWA_DM_SESSION_ROLE_CHANGE_NTF_EVT,
    /* Result of invalid ntf event*/
    UWA_DM_INVALID_NTF_EVT = 0xFF
} eResponse_Ntf_Event;

/* UWA_DM callback events for UWB EXT NTF events */
typedef enum Response_Ext_Ntf_Event
{
    /* Result of SE Test Loop ntf event */
    UWA_DM_PROP_SE_TEST_LOOP_NTF_EVT = UWA_DM_EXT_NTF_EVENT,
    /* Result of Generate Tag ntf event */
    UWA_DM_PROP_GENERATE_TAG_NTF_EVT,
    /* Result of SE COM ERROR ntf event */
    UWA_DM_PROP_SE_COM_ERROR_NTF_EVT,
    /* Result of binding status ntf event */
    UWA_DM_PROP_BINDING_STATUS_NTF_EVT,
#if UWBFTR_UWBS_DEBUG_Dump
    /* Data Logger ntf event*/
    UWA_DM_PROP_DBG_DATA_LOGGER_NTF_EVT,
#endif // UWBFTR_UWBS_DEBUG_Dump
    /* Wlan Ind ntf event*/
    UWA_DM_PROP_UWB_WLAN_IND_NTF_EVT,
    /* To notify the WLAN_UWB_IND GPIO status during ranging round */
    UWA_DM_PROP_WLAN_UWB_IND_ERR_NTF_EVT,
    /* WiFi CoEx Maximum active grant duration excced warning ntf event*/
    UWA_DM_PROP_UWB_WLAN_COEX_MAX_GRANT_DURATION_EXCEEDED_WARN_NTF,
#if UWBFTR_UWBS_DEBUG_Dump
    /* Vendor CIR Log nt event*/
    UWA_DM_VENDOR_CIR_LOG_NTF_EVT,
    /* Vendor PSDU Log nt event*/
    UWA_DM_VENDOR_PSDU_LOG_NTF_EVT,
#endif // UWBFTR_UWBS_DEBUG_Dump
#if (UWBIOT_SESN_SNXXX)
    /* Vendor se binding ntf event*/
    UWA_DM_VENDOR_SE_DO_BIND_NTF_EVT,
    /* Vendor se test connectivity ntf event*/
    UWA_DM_VENDOR_SE_DO_TEST_CONNECTIVITY_NTF_EVT,
    /* Vendor ese binding check ntf event*/
    UWA_DM_VENDOR_ESE_BINDING_CHECK_NTF_EVT,
    /* Vendor ursk deletion req ntf event*/
    UWA_DM_VENDOR_URSK_DELETION_REQ_NTF_EVT,
#endif //(UWBIOT_SESN_SNXXX)
    /* Vendor Do Calibration ntf event*/
    UWA_DM_PROP_DO_CHIP_CALIBRATION_NTF_EVT,
    /* Internal Ranging Timestamp Log ntf event*/
    UWA_DM_INTERNAL_RANGING_TIMESTAMP_NTF_EVT,
    /* Internal Command Timestamp Log ntf event*/
    UWA_DM_INTERNAL_CMD_TIMESTAMP_NTF_EVT,
    /* Internal rframe log ntf event*/
    UWA_DM_INTERNAL_DBG_RFRAME_LOG_NTF_EVT,
    /* DPD timings profiling notification event*/
    UWA_DM_INTERNAL_DBG_DPD_INFO_NTF_EVT,
    /* CIR PULL Data Notification event*/
    UWA_DM_INTERNAL_CIR_PULL_DATA_NTF_EVT,
    /* Write calibration data ntf event*/
    UWA_DM_PROP_SE_WRITE_CALIB_DATA_NTF_EVT,
    /* Read calibration data ntf event*/
    UWA_DM_PROP_SE_READ_CALIB_DATA_NTF_EVT,
#if UWBFTR_TransitProp
    /* Set RDS Param Notification Event */
    UWA_DM_PROP_SET_RDS_PARAM_NTF_EVT,
#endif // UWBFTR_TransitProp

    /* Ese Get Session ID List Ntf Event  */
    UWA_DM_PROP_GET_ESE_SESSION_ID_LIST_NTF_EVT,
    /* Result of invalid ntf event*/
    UWA_EXT_DM_INVALID_NTF_EVT = 0xFF
} eResponse_Ext_Ntf_Event;

/**
 * @brief Structure for storing  UWB API Context.
 */
typedef struct phUwbApiContext
{
    /** Data to be send to device. This includes both UCI Header and UCI Payload */
#if UWBFTR_DataTransfer
    uint8_t snd_data[MAX_UCI_HEADER_SIZE + MAX_CMD_BUFFER_DATA_TRANSFER];
#else
    /*  This is needed for Set calibration.
     *  Max set calibration buffer needed is 19*19*2 + 2 */
    uint8_t snd_data[MAX_UCI_HEADER_SIZE + MAX_API_PACKET_SIZE];
#endif // UWBFTR_DataTransfer
    /** Common response buffer to store *
     * response/ntfn received. This includes both UCI Header and UCI Payload */
    uint8_t rsp_data[MAX_UCI_HEADER_SIZE + MAX_API_PACKET_SIZE];
    /** Current device state *
     * UCI_DEV_IDLE/UCI_DEV_READY/UCI_DEV_BUSY/UCI_DEV_ERROR */
    uint8_t dev_state;
    /** Current UWBD Firmware Mode */
    BOOLEAN fwMode;
    /** Holds status of the current ongoing operations */
    tUWBAPI_STATUS wstatus;
    /** This is set after UWB stack is initialized */
    BOOLEAN isUfaEnabled;
    /** Current Event on which UWB API  is waiting for
     * response/ntfn */
    uint16_t currentEventId;
    uint16_t receivedEventId;
    /** Length of the response received */
    uint16_t rsp_len;
    /** Semaphore used for making UWB APIs synchronous, it will *
     * be signaled when UCI response/notification  is received */
    struct k_sem devMgmtSem;
    /** Generic callback registered by Application */
    uwb_uci_callback_t *pAppCallback;
    /** Session data */
    uwb_session_status_notification_t sessionInfo;
    /** Notification timeout value for session related operations */
    uint32_t ntfTimeout;

#if (UWBIOT_UWBD_SR04X)
    /** Calibration status notification data */
    phCalibrationStatus_t calibrationStatus;
#endif /* (UWBIOT_UWBD_SR04X) */

#if UWBFTR_DataTransfer
    uint16_t maxDataPacketPayloadSize;
    uint16_t maxMessageSize;
    uwb_data_credit_notification_t dataCredit;
    phUwbDataTransmit_t dataTransmit;
    uwb_logical_link_create_ntf_t logicalLinkCreate;
#endif //UWBFTR_DataTransfer

#if UWBIOT_SESN_SNXXX
    /* Waiting Semaphore for BINDING_STATUS_NTF */
    struct k_sem uwb_binding_status_ntf_wait;
#endif // UWBIOT_SESN_SNXXX
} phUwbApiContext_t;

EXTERNC phUwbApiContext_t uwbContext;

/**
 **
 ** Function:        uwb_vendor_deinitialize
 **
 ** Description:     CleanUp all the Semaphores and Timers
 **
 ** Returns:         None
 **
 */
EXTERNC void uwb_vendor_deinitialize();
#define cleanUp uwb_vendor_deinitialize

/**
 **
 ** Function:        uwb_vendor_initialize
 **
 ** Description:     Perform UwbInit with the callback
 **
 ** Returns:         Status
 **
 */
EXTERNC int uwb_vendor_initialize(void);
#define uwbInit uwb_vendor_initialize

/**
 **
 ** Function:        getDeviceInfo
 **
 ** Description:     Gets Device Info from FW and sets in to context
 **
 ** Returns:         None
 **
 */
EXTERNC tUWBAPI_STATUS getDeviceInfo(phUwbDevInfo_t *pdevInfo);

/**
 **
 ** Function:        getCapsInfo
 **
 ** Description:     Gets capability Info from FW and sets in to context
 **
 ** Returns:         status
 **
 */
EXTERNC tUWBAPI_STATUS getCapsInfo(phUwbCapInfo_t *pDevCapabilities);

/**
 **
 ** Function:        sendRawUci2
 **
 ** Description:     Internal function to Send Raw Command
 **
 ** Returns:         Status
 **
 */
EXTERNC tUWBAPI_STATUS sendRawUci2(uint8_t *p_cmd_params, uint16_t cmd_params_len, uint8_t *response, uint32_t *response_len);

/**
 **
 ** Function:        getAppConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for Application related configs.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getAppConfigTLVBuffer(uint8_t paramId, uint8_t paramLen, void *paramValue, uint8_t *tlvBuffer);

/**
 **
 ** Function:        getCoreDeviceConfigTLVBuffer
 **
 ** Description:     Convert one TLV Application Configuration Structure to Byte
 **                  Array for Core Device configs.
 **
 ** Returns:         Length of the data
 **
 */
EXTERNC uint8_t getCoreDeviceConfigTLVBuffer(uint8_t paramId, uint8_t paramLen, void *paramValue, uint8_t *tlvBuffer);

/**
 **
 ** Function:        parseCoreGetDeviceConfigResponse
 **
 ** Description:     Convert received UCI response to deviceConfig object
 **
 ** Returns:         None
 **
 */
EXTERNC void parseCoreGetDeviceConfigResponse(uint8_t *tlvBuffer, phDeviceConfigData_t *devConfig);

/**
 **
 ** Function:        parseRangingParams
 **
 ** Description:     Extracts Ranging Params from the given byte array and updates the structure
 **
 ** Returns:         None
 **
 */
EXTERNC void parseRangingParams(uint8_t *rspPtr, uint8_t noOfParams, phRangingParams_t *pRangingParams);

/**
 **
 ** Function:        ufaDeviceManagementRspCallback
 **
 ** Description:     Receive device management response events from stack.
 **                  dmEvent: Device-management event ID.
 **                  eventData: Data associated with event ID.
 **
 ** Returns:         None
 **
 */
EXTERNC void ufaDeviceManagementRspCallback(uint8_t gid, uint8_t oid, uint16_t len, const uint8_t *const eventData);

#if UWBFTR_DataTransfer

/**
 **
 ** Function:        ufaDeviceManagementDataCallback
 **
 ** Description:     Receive device management response events from stack.
 **                  dmEvent: Device-management event ID.
 **                  eventData: Data associated with event ID.
 **
 ** Returns:         None
 **
 */
EXTERNC void ufaDeviceManagementDataCallback(uint8_t dpf, uint16_t len, const uint8_t *const eventData);
#endif // UWBFTR_DataTransfer

/**
 * @brief API to get all uwb sessions.
 * \retval #UWBAPI_STATUS_OK               on success
 * \retval #UWBAPI_STATUS_NOT_INITIALIZED  if UWB stack is not initialized
 * \retval #UWBAPI_STATUS_INVALID_PARAM    if invalid parameters are passed
 * \retval #UWBAPI_STATUS_FAILED           otherwise
 * \retval #UWBAPI_STATUS_TIMEOUT          if command is timeout
 */
EXTERNC tUWBAPI_STATUS UwbApi_GetAllUwbSessions(phUwbSessionsContext_t *pUwbSessionsContext);

/**
 **
 ** Function:        parseUwbSessionParams
 **
 ** Description:     Extracts All Sessions Data Parameters and updates the
 *structure
 **
 ** Returns:         status
 **
 */
EXTERNC tUWBAPI_STATUS parseUwbSessionParams(uint8_t *rspPtr, phUwbSessionsContext_t *pUwbSessionsContext);

/**
 ** Function:        getStatusString
 **
 ** Description:     It identifies status when an api is called
 **
 ** Returns:         status string
 */
const char *getStatusString(uint8_t status);

/**
 * @brief Generic callback handler for UCI packets from uwb_core layer
 *
 * Receives all UCI packets and routes them to appropriate handlers.
 * Forwards notifications and data packets to application callback.
 *
 * @param pData Complete UCI packet (4-byte header + payload)
 * @param length Total packet size in bytes
 */
EXTERNC void uwb_generic_callback_handler(uint8_t *pData, uint32_t length);

#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif // UWBAPI_INTERNAL_H
