/*
 *
 * Copyright 2019-2020,2022-2024,2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 *
 *  This file contains the definition from UCI specification
 *
 */

#ifndef UWB_UCI_EXT_DEFS_H
#define UWB_UCI_EXT_DEFS_H

#include "uci_prop_defs.h"
#include <stdint.h>

#define UCI_GID_INTERNAL_GROUP       0x0B /* 1011b NXP Internal Group */

/**********************************************************
 * UCI Extention Parameter IDs : Device Information
 */
#define UCI_EXT_PARAM_ID_DEVICE_NAME              0x00
#define UCI_EXT_PARAM_ID_FW_VERSION               0x01
#define UCI_EXT_PARAM_ID_VENDOR_UCI_VER           0x02
#define UCI_EXT_PARAM_ID_UWB_CHIP_ID              0x03
#define UCI_EXT_PARAM_ID_UWBS_MAX_PPM_VALUE       0x04
#define UCI_EXT_PARAM_ID_TX_POWER                 0x05
#define UCI_EXT_PARAM_UWBS_CAL_MODE               0x06
#define UCI_EXT_PARAM_ID_FIRA_EXT_UCI_GENERIC_VER 0x60
#define UCI_EXT_PARAM_ID_FIRA_EXT_TEST_VER        0x61
#define UCI_EXT_PARAM_ID_UWB_FW_GIT_HASH          0x62
#define UCI_EXT_PARAM_ID_FW_BOOT_MODE             0x63

#define UCI_EXT_PARAM_ID_UCI_CCC_VERSION    0XA0
#define UCI_EXT_PARAM_ID_CCC_VERSION        0XA1
#define UCI_EXT_PARAM_ID_ALIRO_SPEC_VERSION 0xA2

#define UCI_EXT_PARAM_ID_UWBS_MAX_UCI_PAYLOAD_LENGTH        0xB1
#define UCI_EXT_PARAM_ID_UWBS_INBAND_DATA_BUFFER_BLOCK_SIZE 0xB2
#define UCI_EXT_PARAM_ID_UWBS_INBAND_DATA_MAX_BLOCKS        0xB3
/**
 * UCI Extension Parameter IDs : Capability Information
 */
#define EXTENDED_CAP_INFO_ID 0xE3

/**
 * UCI Extension Parameter IDs : Device Configurations
 */
#define EXTENDED_DEVICE_CONFIG_ID 0xE4

#define UCI_EXT_PARAM_ID_DPD_WAKEUP_SRC                    0x02
#define UCI_EXT_PARAM_ID_WTX_COUNT                         0x03
#define UCI_EXT_PARAM_ID_DPD_ENTRY_TIMEOUT                 0x04
#define UCI_EXT_PARAM_ID_GPIO_SELECTION_FOR_DUAL_AOA       0x06
#define UCI_EXT_PARAM_ID_TX_BASE_BAND_CONFIG               0x26
#define UCI_EXT_PARAM_ID_DDFS_TONE_CONFIG                  0x27
#define UCI_EXT_PARAM_ID_TX_PULSE_SHAPE_CONFIG             0x28
#define UCI_EXT_PARAM_ID_HOST_MAX_UCI_PAYLOAD_LENGTH       0x31
#define UCI_EXT_PARAM_ID_NXP_EXTENDED_NTF_CONFIG           0x33
#define UCI_EXT_PARAM_ID_CLOCK_PRESENT_WAITING_TIME        0x34
#define UCI_EXT_PARAM_ID_INITIAL_RX_ON_OFFSET_ABS          0x35
#define UCI_EXT_PARAM_ID_INITIAL_RX_ON_OFFSET_REL          0x36
#define UCI_EXT_PARAM_ID_FREQ_OF_UWB_REQ_WLAN_CHANNEL_INFO 0x39
#define UCI_EXT_PARAM_ID_CLK_CONFIG_CTRL                   0x3A
#define UCI_EXT_PARAM_ID_DDFS_CONFIG_PER_PULSE_SHAPE       0x3B
#define UCI_EXT_PARAM_ID_AOA_MODE                          0x3C
#define UCI_EXT_PARAM_ID_PDOA_CALIB_TABLE_DEFINE           0x46
#define UCI_EXT_PARAM_ID_ANTENNA_RX_IDX_DEFINE             0x60
#define UCI_EXT_PARAM_ID_ANTENNAE_RX_PAIR_DEFINE           0x62
#define UCI_EXT_PARAM_ID_ANTENNA_TX_IDX_DEFINE             0x63
#define UCI_EXT_PARAM_ID_WIFI_COEX_FEATURE_ALL_CH          0x67

#define UCI_EXT_PARAM_ID_DPD_WAKEUP_SRC_LEN              0x01
#define UCI_EXT_PARAM_ID_WTX_COUNT_LEN                   0x01
#define UCI_EXT_PARAM_ID_WIFI_COEX_FEATURE_CH5_LEN       0x04
#define UCI_EXT_PARAM_ID_DPD_ENTRY_TIMEOUT_LEN           0x02
#define UCI_EXT_PARAM_ID_TX_BASE_BAND_CONFIG_LEN         0x01
#define UCI_EXT_PARAM_ID_DDFS_TONE_CONFIG_LEN            0x48
#define UCI_EXT_PARAM_ID_TX_PULSE_SHAPE_CONFIG_LEN       0x04
#define UCI_EXT_PARAM_ID_HOST_MAX_UCI_PAYLOAD_LENGTH_LEN 0x02
#define UCI_EXT_PARAM_ID_NXP_EXTENDED_NTF_CONFIG_LEN     0x01
#define UCI_EXT_PARAM_ID_INITIAL_RX_ON_OFFSET_ABS_LEN    0x02
#define UCI_EXT_PARAM_ID_INITIAL_RX_ON_OFFSET_REL_LEN    0x02
#define UCI_EXT_PARAM_ID_WIFI_COEX_FEATURE_ALL_CH_LEN    UCI_EXT_PARAM_ID_WIFI_COEX_FEATURE_CH5_LEN


/**
 * UCI Extension Parameter IDs : Debug Device Configurations
 */
#define EXTENDED_DBG_DEVICE_CONFIG_ID                      0xE5

/**
 * UCI Vendor Config Parameter IDs : Application Configurations
 */
#define UCI_VENDOR_PARAM_ID_MAC_PAYLOAD_ENCRYPTION         0x00
#define UCI_VENDOR_PARAM_ID_ANTENNAE_CONFIGURATION_TX      0x02
#define UCI_VENDOR_PARAM_ID_ANTENNAE_CONFIGURATION_RX      0x03
#define UCI_VENDOR_PARAM_ID_RAN_MULTIPLIER                 0x20
#define UCI_VENDOR_PARAM_ID_CIR_LOG_NTF                    0x30
#define UCI_VENDOR_PARAM_ID_PSDU_LOG_NTF                   0x31
#define UCI_VENDOR_PARAM_ID_RSSI_AVG_FILT_CNT              0x40
#define UCI_VENDOR_PARAM_ID_CIR_CAPTURE_MODE               0x60
#define UCI_VENDOR_PARAM_ID_SESSION_SYNC_ATTEMPTS          0x62
#define UCI_VENDOR_PARAM_ID_SESSION_SCHED_ATTEMPTS         0x63
#define UCI_VENDOR_PARAM_ID_SCHED_STATUS_NTF               0x64
#define UCI_VENDOR_PARAM_ID_TX_POWER_DELTA_FCC             0x65
#define UCI_VENDOR_PARAM_ID_TEST_KDF_FEATURE               0x66
#define UCI_VENDOR_PARAM_ID_TX_POWER_TEMP_COMPENSATION     0x67
#define UCI_VENDOR_PARAM_ID_WIFI_COEX_MAX_TOLERANCE_COUNT  0x68
#define UCI_VENDOR_PARAM_ID_ADAPTIVE_HOPPING_THRESHOLD     0x69
#if UWBFTR_TransitProp
#define UCI_VENDOR_PARAM_ID_CONTENTION_PHASE_UPDATE_LENGTH 0x6D
#endif // UWBFTR_TransitProp
#define UCI_VENDOR_PARAM_ID_AUTHENTICITY_TAG               0x6E
#define UCI_VENDOR_PARAM_ID_RX_NBIC_CONFIG                 0x6F
#define UCI_VENDOR_PARAM_ID_MAC_CFG                        0x70
#define UCI_VENDOR_PARAM_ID_SESSION_INBAND_DATA_TX_BLOCKS  0x71
#define UCI_VENDOR_PARAM_ID_SESSION_INBAND_DATA_RX_BLOCKS  0x72
#define UCI_VENDOR_PARAM_ID_DATA_TRANSFER_TX_STATUS_CONFIG 0x75
#if (UWBFTR_UL_TDoA_Tag)
#define UCI_VENDOR_PARAM_ID_ULTDOA_MAC_FRAME_FORMAT 0x76
#endif // #if (UWBFTR_UL_TDoA_Tag)
#define UCI_VENDOR_PARAM_ID_WRAPPED_RDS               0x79
#define UCI_VENDOR_PARAM_ID_RFRAME_LOG_NTF            0x7B
#define UCI_VENDOR_PARAM_ID_TX_ADAPTIVE_PAYLOAD_POWER 0x7F
#if (UWBFTR_AoA_FoV && UWBIOT_UWBD_SR150)
#define UCI_VENDOR_PARAM_ID_SWAP_ANTENNA_PAIR_3D_AOA 0x80
#endif //(UWBFTR_AoA_FoV && UWBIOT_UWBD_SR150)
#define UCI_VENDOR_PARAM_ID_RML_PROXIMITY_CONFIG 0x81
#define UCI_VENDOR_PARAM_ID_RESYNC_ENABLE        0x83
#if (UWBFTR_AoA_FoV)
#define UCI_VENDOR_PARAM_ID_FOV_ENABLE            0x84
#define UCI_VENDOR_PARAM_ID_AZIMUTH_FIELD_OF_VIEW 0x85
#endif // UWBFTR_AoA_FoV
#define UCI_VENDOR_PARAM_ID_SESSION_INFO_NTF_FILTER_NUM 0x86
#if UWBIOT_UWBD_SR150
#define UCI_VENDOR_PARAM_ID_ALIRO_CONTROLEE_EXTENSIONS 0x8A
#endif //UWBIOT_UWBD_SR150
#if UWBFTR_CSA
#define UCI_VENDOR_PARAM_ID_CSA_FINAL_DATA2_CONFIG        0x90
#define UCI_VENDOR_PARAM_ID_INITIAL_SYNC_RX_WINDOW_CONFIG 0xC2
#endif // UWBFTR_CSA
#define UCI_VENDOR_PARAM_ID_ENABLE_FOM               0x91
#define UCI_VENDOR_PARAM_ID_RADAR_MODE               0xA0
#define UCI_VENDOR_PARAM_ID_RRADAR_RX_GAIN           0xA4
#define UCI_VENDOR_PARAM_ID_RADAR_SINGLE_FRAME_NTF   0xA5
#define UCI_VENDOR_PARAM_ID_RADAR_CIR_NUM_SAMPLES    0xA7
#define UCI_VENDOR_PARAM_ID_RADAR_CIR_START_OFFSET   0xA8
#define UCI_VENDOR_PARAM_ID_RADAR_RFRI               0xA9
#define UCI_VENDOR_PARAM_ID_RADAR_PRESENCE_DET_CFG   0xAA
#define UCI_VENDOR_PARAM_ID_RADAR_FCC_TEST_MODE      0xAC
#define UCI_VENDOR_PARAM_ID_RADAR_DC_FREEZE          0xAD
#define UCI_VENDOR_PARAM_ID_RADAR_PULSE_SHAPE        0xAE
#define UCI_VENDOR_PARAM_ID_RADAR_DRIFT_COMPENSATION 0xB2
#define UCI_VENDOR_PARAM_ID_RADAR_CFG                0xB3
#if UWBFTR_TransitProp
#define UCI_VENDOR_PARAM_ID_CM3_PADDING              0x9D
#define UCI_VENDOR_PARAM_ID_EPOCH_TIME               0x9E
#endif // UWBFTR_TransitProp
#define UCI_VENDOR_PARAM_ID_SET_USECASE_ID           0x9F

/***********************************************************
 * UCI Extention Parameter IDs : Debug Configurations
 */
#define UCI_EXT_PARAM_ID_DATA_LOGGER_NTF                 0x7A
#define UCI_EXT_PARAM_ID_TEST_CONTENTION_RANGING_FEATURE 0x7C
#define UCI_EXT_PARAM_ID_CIR_WINDOW                      0x7D
#define UCI_EXT_PARAM_ID_RANGING_TIMESTAMP_NTF           0x7E

/**
 * UCI Extention Test Parameter IDs : Test Configurations
 */
#define EXTENDED_TEST_CONFIG_ID 0xE5

#define UCI_EXT_TEST_PARAM_ID_RSSI_CALIBRATION_OPTION 0x01
#define UCI_EXT_TEST_PARAM_ID_AGC_GAIN_VAL_RX         0x02
#define UCI_EXT_TEST_SESSION_STS_KEY_OPTION           0x03

/**
 * UCI Extension Parameter IDs : Radar Configurations
 */
#define EXTENDED_RADAR_CONFIG_ID      0xE5
#define EXTENDED_RADAR_TEST_CONFIG_ID 0xE4

#define UCI_EXT_RADAR_PARAM_ID_RADAR_MODE                       0x00
#define UCI_EXT_RADAR_PARAM_ID_RADAR_PRF_CFG                    0x01
#define UCI_EXT_RADAR_PARAM_ID_RADAR_RX_DELAY                   0x02
#define UCI_EXT_RADAR_PARAM_ID_RADAR_RX_GAIN                    0x04
#define UCI_EXT_RADAR_PARAM_ID_RADAR_SINGLE_FRAME_NTF           0x05
#define UCI_EXT_RADAR_PARAM_ID_RADAR_CIR_START_INDEX            0x06
#define UCI_EXT_RADAR_PARAM_ID_RADAR_CIR_NUM_SAMPLES            0x07
#define UCI_EXT_RADAR_PARAM_ID_RADAR_CIR_START_OFFSET           0x08
#define UCI_EXT_RADAR_PARAM_ID_RADAR_CALIBRATION_SUPPORT        0x09
#define UCI_EXT_RADAR_PARAM_ID_RADAR_CALIBRATION_NUM_SAMPLES    0x0A
#define UCI_EXT_RADAR_PARAM_ID_RADAR_RADAR_CALIBRATION_INTERVAL 0x0B
#define UCI_EXT_RADAR_PARAM_ID_RADAR_TEST_FCC_TESTMODE          0x80

/**
 * UCI Parameter IDs : SR150 specific Configurations
 */
#define UCI_EXT_MSG_SE_BIND_GET_INIT_DATA      0x08
#define UCI_EXT_MSG_SE_BIND_SET_SE_DATA        0x09
#define UCI_EXT_MSG_SE_BIND_COMMIT_BDI         0x0A
#define UCI_EXT_MSG_SE_GET_HOST_CHALLENGE_APDU 0x0B
#define UCI_EXT_MSG_SE_GET_EXTERNAL_AUTH_APDU  0x0C
#define UCI_EXT_MSG_SE_DO_ENC_APDU             0x0D
#define UCI_EXT_MSG_SE_RESP_APDU_VALIDATE_REQ  0x0E

/** UCI Extention calibration Param */
#define UCI_EXT_PARAM_ID_AOA_ANTENNAS_PDOA_CALIB 0x00

/* Binary log levels*/
#define DBG_LOG_LEVEL_DISABLE 0x0000
#define DBG_LOG_LEVEL_ERROR   0x0001
#define DBG_LOG_LEVEL_WARNG   0x0002
#define DBG_LOG_LEVEL_TMSTAMP 0x0004
#define DBG_LOG_LEVEL_SEQNUM  0x0008
#define DBG_LOG_LEVEL_INFO1   0x0010
#define DBG_LOG_LEVEL_INFO2   0x0020
#define DBG_LOG_LEVEL_INFO3   0x0040

/* UWB proprietary status codes */
#define UCI_STATUS_BINDING_SUCCESS                     0x50
#define UCI_STATUS_BINDING_FAILURE                     0x51
#define UCI_STATUS_BINDING_LIMIT_REACHED               0x52
#define UCI_STATUS_CALIBRATION_IN_PROGRESS             0x53
#define UCI_STATUS_DEVICE_TEMP_REACHED_THERMAL_RUNAWAY 0x54
#define UCI_STATUS_NO_ESE                              0x70
#define UCI_STATUS_ESE_RSP_TIMEOUT                     0x71
#define UCI_STATUS_ESE_RECOVERY_FAILURE                0x72
#define UCI_STATUS_ESE_RECOVERY_SUCCESS                0x73
#define UCI_STATUS_SE_APDU_CMD_FAIL                    0x74
#define UCI_STATUS_SE_AUTH_FAIL                        0x75

/* UWB proprietary calibration parameter codes */
#define UCI_CALIB_CHIP_CALIBRATION           0x00
#define UCI_CALIB_TX_POWER_ID                0x01
#define UCI_CALIB_XTAL_CAP_38_4_MHZ          0x02
#define UCI_CALIB_RSSI_CALIB_CONSTANT1       0x03
#define UCI_CALIB_RSSI_CALIB_CONSTANT2       0x04
#define UCI_CALIB_SNR_CALIB_CONSTANT         0x05
#define UCI_CALIB_MANUAL_TX_POW_CTRL         0x06
#define UCI_CALIB_PARAM_PDOA_OFFSET1         0x07
#define UCI_CALIB_PAPPPA_CALIB_CTRL          0x08
#define UCI_CALIB_TX_TEMPARATURE_COMP        0x09
#define UCI_CALIB_PARAM_PDOA_OFFSET2         0x0A
#define UCI_CALIB_PARAM_AOA_MULTIPOINT_CALIB 0x0B

/**
 * UWB RADAR CONTROL Group Opcode - 0x09 : Opcodes
 */
#define EXT_UCI_MSG_RADAR_NTF 0x0A

/**
 **GID: UCI  Proprietary SE Group - 0x0A : Opcodes
 */
#define EXT_UCI_MSG_WRITE_CALIB_DATA_CMD 0x00
#define EXT_UCI_MSG_READ_CALIB_DATA_CMD  0x01

#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
#define EXT_UCI_MSG_WRITE_MODULE_MAKER_ID 0x03
#define EXT_UCI_MSG_READ_MODULE_MAKER_ID  0x04
#endif //(UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S || UWBIOT_UWBD_SR250)
#define EXT_UCI_MSG_GET_HIF_I2C_CFG       0x10
#define EXT_UCI_MSG_SET_HIF_I2C_CFG       0x11
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR100S || UWBIOT_UWBD_SR250)
#if UWBFTR_CSA
#define EXT_UCI_MSG_SESSION_SET_LOCALIZATION_ZONE_CMD 0x12
#endif // UWBFTR_CSA

/**
**GID: 1110(Ox0E) Proprietary group OIDS
*/
#define EXT_UCI_MSG_CORE_DEVICE_INIT                 0x00
#define EXT_UCI_MSG_DBG_DATA_LOGGER_NTF              0x01
#define EXT_UCI_MSG_DBG_GET_ERROR_LOG                0x02
#define EXT_UCI_MSG_SE_GET_BINDING_COUNT             0x03
#define EXT_UCI_MSG_SE_DO_TEST_LOOP                  0x04
#define EXT_UCI_MSG_SE_COMM_ERROR_NTF                0x05
#define EXT_UCI_MSG_SE_GET_BINDING_STATUS            0x06
#define EXT_UCI_MSG_UWB_SESSION_KDF_NTF              0x08
#define EXT_UCI_MSG_UWB_WIFI_COEX_IND_NTF            0x09
#define EXT_UCI_MSG_WLAN_UWB_IND_ERR_NTF             0x0A
#define EXT_UCI_MSG_QUERY_TEMPERATURE                0x0B
#define EXT_UCI_MSG_GENERATE_TAG                     0x0E
#define EXT_UCI_MSG_VERIFY_CALIB_DATA                0x0F
#define EXT_UCI_MSG_CONFIGURE_AUTH_TAG_OPTIONS_CMD   0x10
#define EXT_UCI_MSG_CONFIGURE_AUTH_TAG_VERSION_CMD   0x11
#define EXT_UCI_MSG_CALIBRATION_INTEGRITY_PROTECTION 0x12
#define EXT_UCI_MSG_UWB_WLAN_COEX_NTF                0x13
#define EXT_UCI_MSG_ESE_GET_SESSION_ID_LIST          0X1E

#if UWBFTR_TransitProp
#define EXT_UCI_PARAM_ID_SESSION_SET_RDS_PARAM_CMD_NTF 0x2B
#endif // UWBFTR_TransitProp

/**
 * GID: 1011(Ox0B) UCI NXP Internal group : Opcodes and size of commands
 */
#define VENDOR_UCI_MSG_RANGING_TIMESTAMP_NTF 0x03
#define VENDOR_UCI_MSG_CMD_TIMESTAMP_NTF     0x04
#define VENDOR_UCI_MSG_DBG_RFRAME_LOG_NTF    0x22
#define VENDOR_UCI_MSG_CIR_PULL_DATA_NTF     0x24
#define VENDOR_UCI_MSG_DBG_DPD_INFO_NTF      0x33

/**
**GID: 1111(Ox0F) Vendor group OIDS
*/
#define VENDOR_UCI_MSG_SET_VENDOR_APP_CONFIG_CMD                          0x00
#define VENDOR_UCI_MSG_URSK_DELETION_REQ                                  0x01
#define VENDOR_UCI_MSG_GET_ALL_UWB_SESSIONS                               0x02
#define VENDOR_UCI_MSG_GET_VENDOR_APP_CONFIG_CMD                          0x03
#define VENDOR_UCI_MSG_ENABLE_SESSION_SCHEDULING_INFO_NTF_REQ_CMD         0x04
#define VENDOR_UCI_MSG_DO_CHIP_CALIBRATION                                0x20
#define VENDOR_UCI_MSG_SET_DEVICE_CALIBRATION                             0x21
#define VENDOR_UCI_MSG_GET_DEVICE_CALIBRATION                             0x22
#define VENDOR_UCI_MSG_SET_SECURE_CALIBRATION                             0x23
#define VENDOR_UCI_MSG_SE_DO_TEST_CONNECTIVITY                            0x30
#define VENDOR_UCI_MSG_SE_DO_BIND                                         0x31
#define VENDOR_UCI_MSG_ESE_BINDING_CHECK_CMD                              0x32
#define VENDOR_UCI_MSG_PSDU_LOG_NTF                                       0x33
#define VENDOR_UCI_MSG_CIR_LOG_NTF                                        0x34
#define VENDOR_UCI_MSG_SCHEDULE_NTF                                       0x38
#define VENDOR_UCI_MSG_UWB_WLAN_IND_STATUS_NTF                            0x39
#define VENDOR_UCI_MSG_WLAN_UWB_IND_STATUS_NTF                            0x3A
#define VENDOR_UCI_MSG_UWB_WLAN_COEX_MAX_GRANT_DURATION_EXCEEDED_WARN_NTF 0x3B

/**
 * UCI Vendor app config
 */
#define UCI_MSG_SESSION_VENDOR_SET_APP_CONFIG 0x00
#define UCI_MSG_SESSION_VENDOR_GET_APP_CONFIG 0x03


#define UCI_BINDING_STATUS_LEN 0x01

/* UWB Generate Tag command related length fields */
#define UCI_TAG_CMAC_LENGTH 0x10U

/* UWB Query Timestamp command related length fields */
#define UCI_QUERY_TIMESTAMP_LENGTH 0x08U

/* Session State codes, as per UCI*/
/**  Session State - Session status notification with no rng data error */
#define UCI_SESSION_FAILED_WITH_NO_RNGDATA_IN_SE 0x80
/**  Session State - Session status notification with key fetch error */
#define UCI_SESSION_FAILED_WITH_KEY_FETCH_ERROR 0x81
/**  Session State - Session status notification with dynamic sts not supported error */
#define UCI_SESSION_FAILED_DYNAMIC_STS_NOT_SUPPORTED 0x82

/* Session reason codes, as per UCI*/
/**  Session State - Session status notification with slot length not supported */
#define UCI_SESSION_FAILED_WITH_SLOT_LEN_NOT_SUPPORTED 0x20
/**  Session State - Session status notification with slot per ranging round insufficient */
#define UCI_SESSION_FAILED_WITH_SLOT_RR_INSUFFICIENT 0x21
/** Session State - Session state notification with key rotation enabled during Dynamic STS ranging */
#define UCI_SESSION_FAILED_WITH_KEY_ROTATION_INVALID_STS_CONFIG 0x4B


/** Helper Macro to fetch Particular GID and OID for Proprietary SE Group  - (0x0A) */
#define GET_PROPRIETARY_SE_GROUP_GID_OID(PROPRIETARY_SE_OID) \
    ((UCI_GID_PROPRIETARY << UCI_GID_GROUP_SHIFT) | (PROPRIETARY_SE_OID))

/** Helper Macro to fetch Particular GID and OID for NXP Internal Group  - (0x0B) */
#define GET_INTERNAL_GROUP_GID_OID(INTERNAL_OID) ((UCI_GID_INTERNAL_GROUP << UCI_GID_GROUP_SHIFT) | (INTERNAL_OID))

/** Helper Macro to fetch Particular GID and OID for Proprietary Group  - (0x0E)*/
#define GET_PROP_GROUP_GID_OID(PROP_OID) ((UCI_GID_PROPRIETARY_CUSTOM_1 << UCI_GID_GROUP_SHIFT) | (PROP_OID))

/** Helper Macro to fetch Particular GID and OID for Vendor Group - (0x0F)*/
#define GET_VENDOR_GROUP_GID_OID(VENDOR_OID) ((UCI_GID_PROPRIETARY_CUSTOM_2 << UCI_GID_GROUP_SHIFT) | (VENDOR_OID))

/** Helper Macro to fetch Particular GID and OID for MW Internal DM Group - (0x1F)*/
#define GET_INTERNAL_DM_GROUP_GID_OID(INTERNAL_DM_OID) ((UCI_GID_INTERNAL << UCI_GID_GROUP_SHIFT) | (INTERNAL_DM_OID))

/** Helper Macro to fetch Particular GID and OID for Session Control Group - (0x02)  */
#define GET_PROPRIETARY_CUSTOM_2_GROUP_GID_OID(PROPRIETARY_CUSTOM_2_OID) \
    ((UCI_GID_PROPRIETARY_CUSTOM_2 << UCI_GID_GROUP_SHIFT) | (PROPRIETARY_CUSTOM_2_OID))

#define GET_PROP_RADAR_CONTROL_GROUP_GID_OID(PROP_OID) \
    ((UCI_GID_PROP_RADAR_CONTROL << UCI_GID_GROUP_SHIFT) | (PROP_OID))

enum
{
    kGidOid_SessionCccDataNtf        = GET_SESSION_CONTROL_GROUP_GID_OID(UCI_MSG_RANGE_CCC_DATA_NTF),

#if !(UWBIOT_UWBD_SR04X)
    /* Proprietary SE Group*/
    kGidOid_WriteOtpCalibData = GET_PROPRIETARY_SE_GROUP_GID_OID(EXT_UCI_MSG_WRITE_CALIB_DATA_CMD),
    kGidOid_ReadOtpCalibData  = GET_PROPRIETARY_SE_GROUP_GID_OID(EXT_UCI_MSG_READ_CALIB_DATA_CMD),
#if UWBFTR_CSA
    kGidOid_SetLocZone = GET_PROPRIETARY_SE_GROUP_GID_OID(EXT_UCI_MSG_SESSION_SET_LOCALIZATION_ZONE_CMD),
#endif // UWBFTR_CSA
    kGidOid_RangingTimestampNtf = GET_INTERNAL_GROUP_GID_OID(VENDOR_UCI_MSG_RANGING_TIMESTAMP_NTF),
    kGidOid_CmdTimestampNtf        = GET_INTERNAL_GROUP_GID_OID(VENDOR_UCI_MSG_CMD_TIMESTAMP_NTF),
    kGidOid_RframeLogNtf        = GET_INTERNAL_GROUP_GID_OID(VENDOR_UCI_MSG_DBG_RFRAME_LOG_NTF),
    kGidOid_CirPullDataNtf        = GET_INTERNAL_GROUP_GID_OID(VENDOR_UCI_MSG_CIR_PULL_DATA_NTF),
    kGidOid_DbgDpdInfoNtf        = GET_INTERNAL_GROUP_GID_OID(VENDOR_UCI_MSG_DBG_DPD_INFO_NTF),
#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    kGidOid_WriteModuleMaker = GET_PROPRIETARY_SE_GROUP_GID_OID(EXT_UCI_MSG_WRITE_MODULE_MAKER_ID),
    kGidOid_ReadModuleMaker  = GET_PROPRIETARY_SE_GROUP_GID_OID(EXT_UCI_MSG_READ_MODULE_MAKER_ID),
#endif //(UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

    /* Proprietary Specific Group */
    kGidOid_PropCoreDeviceInit                 = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_CORE_DEVICE_INIT),
    kGidOid_PropDbgDataLoggerNtf               = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_DBG_DATA_LOGGER_NTF),
    kGidOid_PropDbgGetErrorLog                 = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_DBG_GET_ERROR_LOG),
    kGidOid_PropGetBindingCount                = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_SE_GET_BINDING_COUNT),
    kGidOid_PropTestSeLoop                     = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_SE_DO_TEST_LOOP),
    kGidOid_PropSeCommErrorNtf                 = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_SE_COMM_ERROR_NTF),
    kGidOid_PropSeGetBindingStatus             = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_SE_GET_BINDING_STATUS),
    kGidOid_PropUwbSessionKdfNtf               = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_UWB_SESSION_KDF_NTF),
    kGidOid_PropUwbWifiCoexIndNtf              = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_UWB_WIFI_COEX_IND_NTF),
    kGidOid_PropWlanUwbIndErrNtf               = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_WLAN_UWB_IND_ERR_NTF),
    kGidOid_PropQueryTemp                      = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_QUERY_TEMPERATURE),
    kGidOid_PropGenerateTag                    = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_GENERATE_TAG),
    kGidOid_PropVerifyCalibData                = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_VERIFY_CALIB_DATA),
    kGidOid_PropCalibIntegrityProtection       = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_CALIBRATION_INTEGRITY_PROTECTION),
    kGidOid_PropUwbWlanCoexNtf                 = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_UWB_WLAN_COEX_NTF),
    kGidOid_PropEseGetSessionIdList            = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_ESE_GET_SESSION_ID_LIST),

#if UWBFTR_TransitProp
    kGidOid_PropSetRdsParamNtf = GET_PROP_GROUP_GID_OID(EXT_UCI_PARAM_ID_SESSION_SET_RDS_PARAM_CMD_NTF),
#endif // UWBFTR_TransitProp
    kGidOid_EseGetSessionIdList          = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_ESE_GET_SESSION_ID_LIST),
    /* Vendor Specific Group */
    kGidOid_VendorSetVendorAppConfig   = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_SET_VENDOR_APP_CONFIG_CMD),
    kGidOid_VendorGetAllUwbSessions    = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_GET_ALL_UWB_SESSIONS),
    kGidOid_VendorGetVendorAppConfig   = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_GET_VENDOR_APP_CONFIG_CMD),
    kGidOid_VendorEnableScheduleNtfCmd = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_ENABLE_SESSION_SCHEDULING_INFO_NTF_REQ_CMD),
    kGidOid_VendorScheduleNtf          = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_SCHEDULE_NTF),
    kGidOid_VendorDoChipCalibration    = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_DO_CHIP_CALIBRATION),
    kGidOid_VendorSetDeviceCalibration = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_SET_DEVICE_CALIBRATION),
    kGidOid_VendorGetDeviceCalibration = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_GET_DEVICE_CALIBRATION),
#if UWBIOT_UWBD_SR2XXT
    kGidOid_VendorSetSecureCalibration = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_SET_SECURE_CALIBRATION),
#endif // UWBIOT_UWBD_SR2XXT
    kGidOid_VendorTestConnectivity = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_SE_DO_TEST_CONNECTIVITY),
    kGidOid_VendorDoBind           = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_SE_DO_BIND),
    kGidOid_VendorGetBindingStatus = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_ESE_BINDING_CHECK_CMD),
    kGidOid_VendorPsduLogNtf       = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_PSDU_LOG_NTF),
    kGidOid_VendorCirLogNtf        = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_CIR_LOG_NTF),
#endif //!(UWBIOT_UWBD_SR04X)
    /* Proprietary Specific Group */
#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR100S)
    kGidOid_VendorUrskDeletionRequest = GET_VENDOR_GROUP_GID_OID(VENDOR_UCI_MSG_URSK_DELETION_REQ),
    kGidOid_PropConfigAuthTagOptions  = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_CONFIGURE_AUTH_TAG_OPTIONS_CMD),
    kGidOid_PropConfigAuthTagVersions = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_CONFIGURE_AUTH_TAG_VERSION_CMD),
#endif // (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR100S)
#if (UWBIOT_UWBD_SR04X)
    kGidOid_GetStartTestMode        = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_TEST_START),
    kGidOid_GetStopTestMode         = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_TEST_STOP),
    kGidOid_GetSuspendDevice        = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_DEVICE_SUSPEND),
    kGidOid_SetCalibTrimMode        = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_SET_TRIM_VALUES),
    kGidOid_VendorGetAllUwbSessions = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_GET_ALL_UWB_SESSIONS),
    kGidOid_GetCalibTrimMode        = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_GET_TRIM_VALUES),
    kGidOid_GetSessionNvm           = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_SESSION_NVM_MANAGE),
    kGidOid_GetTrng                 = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_GEN_TRUE_RANDOM_NUM),
    kGidOid_BypassCurrentLimiter    = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_BYPASS_CURRENT_LIMITER),
#endif /* (UWBIOT_UWBD_SR04X) */

#if !(UWBIOT_UWBD_SR04X)
    kGidOid_GetTrng = GET_PROPRIETARY_SE_GROUP_GID_OID(EXT_UCI_MSG_GET_TRNG),
#endif // !(UWBIOT_UWBD_SR04X)

#if UWBFTR_BlobParser
#if (UWBIOT_UWBD_SR04X)
    kGidOid_ProfileParamMode = GET_PROP_GROUP_GID_OID(EXT_UCI_MSG_SET_PROFILE),
#elif (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250 || UWBIOT_UWBD_SR100S || UWBIOT_UWBD_SR200S)
    kGidOid_ProfileParamMode =
        GET_PROPRIETARY_SE_GROUP_GID_OID(EXT_UCI_MSG_SET_PROFILE), /*Todo : Check with FW once available*/
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250 || UWBIOT_UWBD_SR100S || UWBIOT_UWBD_SR200S)
#endif // UWBFTR_BlobParser
    /* MW Internal DM group */
    kGidOid_UwbWlanIndication                   = GET_PROPRIETARY_CUSTOM_2_GROUP_GID_OID(VENDOR_UCI_MSG_UWB_WLAN_IND_STATUS_NTF),
    kGidOid_WlanUwbIndication                   = GET_PROPRIETARY_CUSTOM_2_GROUP_GID_OID(VENDOR_UCI_MSG_WLAN_UWB_IND_STATUS_NTF),
    kGidOid_Wlan_Coex_Max_Grant_Duration        = GET_PROPRIETARY_CUSTOM_2_GROUP_GID_OID(VENDOR_UCI_MSG_UWB_WLAN_COEX_MAX_GRANT_DURATION_EXCEEDED_WARN_NTF),
    kGidOid_UwbdRadarNtf                        = GET_PROP_RADAR_CONTROL_GROUP_GID_OID(EXT_UCI_MSG_RADAR_NTF),
    kGidOid_InvalidGidOid                       = 0xFFFF,
};

#endif /* UWB_UCI_EXT_DEFS_H */
