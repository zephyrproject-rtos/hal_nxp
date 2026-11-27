/*
 *
 * Copyright 2021-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __UCI_PROP_DEFS_H__
#define __UCI_PROP_DEFS_H__

#include "zephyr/uwb/uci.h"

#define SESSION_ID_LEN           0x04

/**
 * Ranging Mesaurement type
 */
/** Measurement Type Oneway */
#define MEASUREMENT_TYPE_ONEWAY       0x00
/** Measurement Type Twoway */
#define MEASUREMENT_TYPE_TWOWAY       0x01
/** Measurement Type Dltdoa V1 */
#define MEASUREMENT_TYPE_DLTDOA_V1    0x02
/** Measurement Type Owr With Aoa */
#define MEASUREMENT_TYPE_OWR_WITH_AOA 0x03
/** Measurement Type Dltdoa V2 */
#define MEASUREMENT_TYPE_DLTDOA_V2    0x06

#define MAX_NUM_OF_TDOA_MEASURES 22
#define MAX_NUM_OWR_AOA_MEASURES 1
#define MAX_NUM_CONTROLLEES                                                                        \
	8 /* max bumber of controlees for  time schedules rangng (multicast)                       \
	   */

#define UCI_GID_PROP_RADAR_CONTROL   0x09 /* 1001b Data Control */
#define UCI_GID_PROPRIETARY          0x0A /* 1010b IOT Proprietary Group */
#define UCI_GID_TEST                 0x0D /* 1101b RF Test Gropup */
#define UCI_GID_PROPRIETARY_CUSTOM_1 0x0E /* 1110b Customer Proprietary Group 1*/
#define UCI_GID_PROPRIETARY_CUSTOM_2 0x0F /* 1111b Customer Proprietary Group 2 */
#define UCI_GID_INTERNAL             0x1F /* 11111b MW Internal DM group */

/* builds byte0 of UCI Command and Notification packet */
#define UCI_MSG_BLD_HDR0(p, mt, gid, index)                       \
    {                                                             \
        (p)[(index)] = (uint8_t)(((mt) << UCI_MT_SHIFT) | (gid)); \
        (index)      = ((index) + (sizeof(uint8_t)));             \
    }

/* builds byte1 of UCI Command and Notification packet */
#define UCI_MSG_BLD_HDR1(p, oid, index)                     \
    {                                                       \
        (p)[(index)] = (uint8_t)(((oid) << UCI_OID_SHIFT)); \
        (index)      = ((index) + (sizeof(uint8_t)));       \
    }

#if (UWBIOT_UWBD_SR04X)
/** FIXME: Redefining these macros for SR040.
 *  Implement these functionalities again using new macros
 */
// #define UCI_MSG_DATA_CREDIT_NTF          0x0B
// #define UCI_MSG_DATA_TRANSMIT_STATUS_NTF 0x0C
#else
#endif /* UWBIOT_UWBD_SR04X */


#if !(UWBIOT_UWBD_SR04X)
#define EXT_UCI_MSG_GET_TRNG 0x02
#endif /* !(UWBIOT_UWBD_SR04X) */

#if (UWBFTR_BlobParser && !(UWBIOT_UWBD_SR04X))
#define EXT_UCI_MSG_SET_PROFILE 0x05
#endif /* (UWBFTR_BlobParser && !(UWBIOT_UWBD_SR04X)) */

#define UCI_PARAM_ID_UCI_WIFI_COEX_FEATURE 0xF0


/**
 * UCI Parameter IDs : Application Configurations
 */
#define UCI_PARAM_ID_DEVICE_TYPE                       0x00
#define UCI_PARAM_ID_RANGING_ROUND_USAGE               0x01
#define UCI_PARAM_ID_STS_CONFIG                        0x02
#define UCI_PARAM_ID_MULTI_NODE_MODE                   0x03
#define UCI_PARAM_ID_CHANNEL_NUMBER                    0x04
#define UCI_PARAM_ID_NO_OF_CONTROLEES                  0x05
#define UCI_PARAM_ID_DEVICE_MAC_ADDRESS                0x06
#define UCI_PARAM_ID_DST_MAC_ADDRESS                   0x07
#define UCI_PARAM_ID_SLOT_DURATION                     0x08
#define UCI_PARAM_ID_RANGING_DURATION                  0x09
#define UCI_PARAM_ID_STS_INDEX                         0x0A
#define UCI_PARAM_ID_MAC_FCS_TYPE                      0x0B
#define UCI_PARAM_ID_RANGING_ROUND_CONTROL             0x0C
#define UCI_PARAM_ID_AOA_RESULT_REQ                    0x0D
#define UCI_PARAM_ID_SESSION_INFO_NTF                  0x0E
#define UCI_PARAM_ID_NEAR_PROXIMITY_CONFIG             0x0F
#define UCI_PARAM_ID_FAR_PROXIMITY_CONFIG              0x10
#define UCI_PARAM_ID_DEVICE_ROLE                       0x11
#define UCI_PARAM_ID_RFRAME_CONFIG                     0x12
#define UCI_PARAM_ID_RSSI_REPORTING                    0x13
#define UCI_PARAM_ID_PREAMBLE_CODE_INDEX               0x14
#define UCI_PARAM_ID_SFD_ID                            0x15
#define UCI_PARAM_ID_PSDU_DATA_RATE                    0x16
#define UCI_PARAM_ID_PREAMBLE_DURATION                 0x17
#define UCI_PARAM_ID_LINK_LAYER_MODE                   0x18
#define UCI_PARAM_ID_DATA_REPETITION_COUNT             0x19
#define UCI_PARAM_ID_RANGING_TIME_STRUCT               0x1A
#define UCI_PARAM_ID_SLOTS_PER_RR                      0x1B
#define UCI_PARAM_ID_TX_ADAPTIVE_PAYLOAD_POWER         0x1C
#define UCI_PARAM_ID_AOA_BOUND_CONFIG                  0x1D
#define UCI_PARAM_ID_PRF_MODE                          0x1F
#define UCI_PARAM_ID_CAP_SIZE_RANGE                    0x20
#define UCI_PARAM_ID_SCHEDULED_MODE                    0x22
#define UCI_PARAM_ID_KEY_ROTATION                      0x23
#define UCI_PARAM_ID_KEY_ROTATION_RATE                 0x24
#define UCI_PARAM_ID_SESSION_PRIORITY                  0x25
#define UCI_PARAM_ID_MAC_ADDRESS_MODE                  0x26
#define UCI_PARAM_ID_VENDOR_ID                         0x27
#define UCI_PARAM_ID_STATIC_STS_IV                     0x28
#define UCI_PARAM_ID_NUMBER_OF_STS_SEGMENTS            0x29
#define UCI_PARAM_ID_MAX_RR_RETRY                      0x2A
#define UCI_PARAM_ID_UWB_INITIATION_TIME               0x2B
#define UCI_PARAM_ID_HOPPING_MODE                      0x2C
#define UCI_PARAM_ID_BLOCK_STRIDING                    0x2D
#define UCI_PARAM_ID_RESULT_REPORT_CONFIG              0x2E
#define UCI_PARAM_ID_IN_BAND_TERMINATION_ATTEMPT_COUNT 0x2F
#define UCI_PARAM_ID_SUB_SESSION_ID                    0x30
#define UCI_PARAM_ID_BPRF_PHR_DATA_RATE                0X31
#define UCI_PARAM_ID_MAX_NUMBER_OF_MEASUREMENTS        0x32
#define UCI_PARAM_ID_UL_TDOA_TX_INTERVAL               0X33
#define UCI_PARAM_ID_UL_TDOA_RANDOM_WINDOW             0x34
#define UCI_PARAM_ID_STS_LENGTH                        0x35
#define UCI_PARAM_ID_SUSPEND_RANGING_ROUNDS            0x36
#define UCI_PARAM_ID_UL_TDOA_NTF_REPORT_CONFIG         0x37
#define UCI_PARAM_ID_UL_TDOA_DEVICE_ID                 0x38
#define UCI_PARAM_ID_UL_TDOA_TX_TIMESTAMP              0x39
#define UCI_PARAM_ID_MIN_FRAMES_PER_RR                 0x3A
#define UCI_PARAM_ID_MTU_SIZE                          0x3B
#define UCI_PARAM_ID_INTER_FRAME_INTERVAL              0x3C
#define UCI_PARAM_ID_DLTDOA_RANGING_METHOD             0x3D
#define UCI_PARAM_ID_DLTDOA_TX_TIMESTAMP_CONF          0x3E
#define UCI_PARAM_ID_DLTDOA_INTER_CLUSTER_SYNC_PERIOD  0x3F
#define UCI_PARAM_ID_DLTDOA_ANCHOR_CFO                 0x40
#define UCI_PARAM_ID_DLTDOA_ANCHOR_LOCATION            0x41
#define UCI_PARAM_ID_DLTDOA_TX_ACTIVE_RANGING_ROUNDS   0x42
#define UCI_PARAM_ID_DL_TDOA_BLOCK_SKIPPING            0x43
#define UCI_PARAM_ID_DLTDOA_TIME_REF_ANCHOR            0x44
#define UCI_PARAM_ID_SESSION_KEY                       0x45
#define UCI_PARAM_ID_SUB_SESSION_KEY                   0x46
#define UCI_PARAM_ID_DATA_TRANSFER_STATUS_NTF_CONFIG   0x47
#define UCI_PARAM_ID_SESSION_TIME_BASE                 0x48
#define UCI_PARAM_ID_DL_TDOA_RESPONDER_TOF             0x49
#define UCI_PARAM_ID_DL_TDOA_SUPERCLUSTER_ID           0x51
#define UCI_PARAM_ID_SECURE_RANGING_NEFA_LEVEL         0x4A
#define UCI_PARAM_ID_SECURE_RANGING_CSW_LENGTH         0x4B
#define UCI_PARAM_ID_APPLICATION_DATA_ENDPOINT         0x4C
#define UCI_PARAM_ID_DLTDOA_ANCHOR_LOCATION_V2         0x4E
#define UCI_PARAM_ID_DLTDOA_MEASUREMENT_NTF_V2         0x4F
#define UCI_PARAM_ID_HOP_MODE_KEY                      0xA0
#define UCI_PARAM_ID_RESPONDER_SLOT_INDEX              0xA2
#define UCI_PARAM_ID_RANGING_PROTOCOL_VER              0xA3
#define UCI_PARAM_ID_UWB_CONFIG_ID                     0xA4
#define UCI_PARAM_ID_PULSESHAPE_COMBO                  0xA5
#define UCI_PARAM_ID_URSK_TTL                          0xA6
#define UCI_PARAM_ID_RESPONDER_LISTEN_ONLY             0xA7
#define UCI_PARAM_ID_LAST_STS_INDEX_USED               0xA8
#define UCI_PARAM_ID_ALIRO_MAC_MODE                    0xA9

/* UCI Parameter ID Length */
#define UCI_PARAM_LEN_DEVICE_ROLE                0x01
#define UCI_PARAM_LEN_RANGING_METHOD             0x01
#define UCI_PARAM_LEN_STS_CONFIG                 0x01
#define UCI_PARAM_LEN_MULTI_NODE_MODE            0x01
#define UCI_PARAM_LEN_CHANNEL_NUMBER             0x01
#define UCI_PARAM_LEN_NO_OF_CONTROLEES           0x01
#define UCI_PARAM_LEN_DEVICE_MAC_ADDRESS         0x02
#define UCI_PARAM_LEN_DEST_MAC_ADDRESS           0x02
#define UCI_PARAM_LEN_SLOT_DURATION              0x02
#define UCI_PARAM_LEN_RANGING_DURATION           0x04
#define UCI_PARAM_LEN_STS_INDEX                  0x04
#define UCI_PARAM_LEN_MAC_FCS_TYPE               0x01
#define UCI_PARAM_LEN_MEASUREMENT_REPORT_REQ     0x01
#define UCI_PARAM_LEN_AOA_RESULT_REQ             0x01
#define UCI_PARAM_LEN_SESSION_INFO_NTF           0x01
#define UCI_PARAM_LEN_NEAR_PROXIMITY_CONFIG      0x02
#define UCI_PARAM_LEN_FAR_PROXIMITY_CONFIG       0x02
#define UCI_PARAM_LEN_DEVICE_TYPE                0x01
#define UCI_PARAM_LEN_RFRAME_CONFIG              0x01
#define UCI_PARAM_LEN_PREAMBLE_CODE_INDEX        0x01
#define UCI_PARAM_LEN_SFD_ID                     0x01
#define UCI_PARAM_LEN_PSDU_DATA_RATE             0x01
#define UCI_PARAM_LEN_PREAMBLE_DURATION          0x01
#define UCI_PARAM_LEN_RANGING_TIME_STRUCT        0x01
#define UCI_PARAM_LEN_AOA_BOUND_CONFIG           0x08
#define UCI_PARAM_LEN_SLOTS_PER_RR               0x01
#define UCI_PARAM_LEN_TX_POWER_ID                0x01
#define UCI_PARAM_LEN_TX_ADAPTIVE_PAYLOAD_POWER  0x01
#define UCI_PARAM_LEN_VENDOR_ID                  0x02
#define UCI_PARAM_LEN_STATIC_STS_IV              0x06
#define UCI_PARAM_LEN_NUMBER_OF_STS_SEGMENTS     0x01
#define UCI_PARAM_LEN_MAX_RR_RETRY               0x02
#define UCI_PARAM_LEN_UWB_INITIATION_TIME        0x04
#define UCI_PARAM_LEN_RANGING_ROUND_HOPPING      0x01
#define UCI_PARAM_LEN_MAX_NUMBER_OF_MEASUREMENTS 0X02
#define UCI_PARAM_LEN_UL_TDOA_TX_INTERVAL        0X04

#if (defined(UWBIOT_UWBD_SR04X) && (UWBIOT_UWBD_SR04X != 0))
#if defined MAX_NUM_OF_TDOA_MEASURES
#undef MAX_NUM_OF_TDOA_MEASURES
#endif
#define MAX_NUM_OF_TDOA_MEASURES 1
#else
#endif

/* max no of responders N 10 for dltdoa
 * N + 2 ==> 12 * 37(dltdoa ntf size) = 444 + 28 --> 472
 */
#define MAX_RADAR_LEN                4200 // Max data read by user space driver fron kernel driver queue is 4200
#define MAX_RESPONSE_DATA_DEBUG_NTF \
    4200 // For CIR, PSDU debug Notification, Max data read by user space driver fron kernel driver queue is 4200

/* UCI command buffer */
#define MAX_CMD_BUFFER_DATA_TRANSFER 2048 // For Data transfer

/** UCI,Data,VCom headers */
#define UCI_HEADAER              0x04
#define VCOM_SE_GID_HEARDER      0x80
#define DATA_PAYLOD_LENGTH_INDEX 0x02
#define UCI_PAYLOAD_LENGTH_INDEX 0x03
#define GID_INDEX                0x00
#define SELECT_ADF_CLA           0x80
#define SELECT_ADF_INS           0xA5
#define PUT_DATA_CLA             0x00
#define PUT_DATA_INS             0xDB
#define SELECT_APPLET_CLA        0x00
#define SELECT_APPLET_INS        0xA4
#define SELECT_SESSION_ID_CLA    0x81
#define SELECT_SESSION_ID_INS    0x04

#define UWBD_STATUS_HDP_WAKEUP  0xFC, /* UWBD Wakeup error*/
#define UWBD_STATUS_UNKNOWN  0xFE, /* device is unknown */
#define UWBD_STATUS_ERROR  0xFF  /* error occured in UWBD*/

#define UWB_SESSION_ERROR_INVALID_ANTENNA_CFG 0x80
#define UWB_SESSION_ERROR_INVALID_RX_MODE 0x81
#define UWB_SESSION_ERROR_FAIL_DYNAMIC_STS_NOT_ALLOWED 0x82
#define UWB_SESSION_ERROR_FEATURE_NOT_SUPPORTED_FOR_MODEL 0x83
#define UWB_SESSION_ERROR_RX_TOA_MODE_MISMATCH 0x84
#define UWB_SESSION_ERROR_INSUFFICIANT_MEMORY_FOR_INBAND_DATA 0x85
#define UWB_SESSION_ERROR_INVALID_DATA_TRANSFER_MODE 0x86
#define UWB_SESSION_ERROR_INVALID_MAC_CFG 0x87
#define UWB_SESSION_ERROR_ANTENNA_DEFINES_NOT_CONFIGURED 0x88
#define UWB_SESSION_ERROR_INVALID_MAX_TDOA_SESSION_COUNT_REACHED 0x89
#define UWB_SESSION_ERROR_LOOPBACK_TX_POWER_TOO_HIGH 0x8A
#define UWB_SESSION_ERROR_WRONG_SESSION_TYPE_FOR_INBAND_DATA 0x8B
#define UWB_SESSION_ERROR_AOA_NOT_SUPPORTED_IN_SINGLE_RX 0x8C
#define UWB_SESSION_ERROR_DUPLICATE_DST_MAC_ADDRESS_DETECTED 0x8D
#define UWB_SESSION_ERROR_INVALID_ADAPTIVE_HOPPING_THRESHOLD 0x8E
#define UWB_SESSION_ERROR_UNSUPPORTED_RANGING_LIMIT 0x8F
#define UWB_SESSION_ERROR_RNG_INVALID_DEVICE_ROLE 0x91
#define UWB_SESSION_ERROR_KEY_ROTATION_NOT_SUPPORTED 0x92
#define UWB_SESSION_ERROR_TEST_KDF_NOT_SUPPORTED 0x93
#define UWB_SESSION_ERROR_INVALID_ANTENNA_PAIR_SWAP_CONFIGURATION 0x94
#define UWB_SESSION_ERROR_INVALID_CHANNEL_ID 0x98
#define UWB_SESSION_STOPPED_DUE_TO_QOS_DECISION 0x9F
#define UCI_STATUS_RANGING_PHY_RX_PROCESSING_TIME_ERROR 0x8B
#define UCI_STATUS_RANGING_PHY_RX_PHR_SIGNAL_LOST_ERROR  0x8C
#define UCI_STATUS_RANGING_PHY_RX_PSDU_SIGNAL_LOST_ERROR 0x8D
#define UWB_SESSION_URSK_EXPIRED 0xA0 /**< Vendor specific: URSK expired */
#define UWB_SESSION_ERROR_RADAR_CIR_MAX_TAP_IDX_EXCEEDED                                           \
	0xB0 /**< Vendor specific: Radar CIR max tap index exceeded */
#define UWB_SESSION_ERROR_RADAR_ANTENNA_CONFIG_RX_NOT_OK                                           \
	0xB1 /**< Vendor specific: Radar antenna config RX not OK */
#define UWB_SESSION_ERROR_RADAR_PRESENCE_DETECTION_RANGE_EXCEEDED                                  \
	0xB2 /**< Vendor specific: Radar presence detection range exceeded */
#define UWB_SESSION_ERROR_RADAR_RX_GAIN_INDEX_NOT_OK                                               \
	0xB3 /**< Vendor specific: Radar RX gain index not OK */
#define UWB_SESSION_ERROR_RADAR_DRIFTCOMP_ANTENNA_CONFIG_NOT_OK                                    \
	0xB4 /**< Vendor specific: Radar drift compensation antenna config not OK */
#define UWB_SESSION_ERROR_DATA_NOT_PRESENT  0xB5 /**< Vendor specific: Data not present */
#define UWB_SESSION_RADAR_FCC_LIMIT_REACHED 0xB7 /**< Vendor specific: Radar FCC limit reached */
#define UWB_SESSION_ERROR_TEST_MMS_FRAME_NOT_SUPPORTED                                             \
	0xB8 /**< Vendor specific: Test MMS frame not supported */
#define UWB_SESSION_ERROR_RADAR_INVALID_INTERLEAVE_MODE                                            \
	0xB9 /**< Vendor specific: Radar invalid interleave mode */
#define UWB_SESSION_ERROR_CSA_INVALID_CFG 0xC0 /**< Vendor specific: CSA invalid configuration */
#define UWB_SESSION_ERROR_INVALID_RESPONDER_SLOT_INDEX_CONFIGURED                                  \
	0xC1 /**< Vendor specific: Invalid responder slot index configured */
#define UWB_SESSION_ERROR_INVALID_INITIAL_SYNC_RX_WINDOW_CONFIG_CONFIGURED                         \
	0xC9 /**< Vendor specific: Invalid initial sync RX window config */
#define UWB_SESSION_ERROR_INITIAL_SYNC_RX_WINDOW_INITIATION_TIME_NOT_CONFIGURED                    \
	0xCA /**< Vendor specific: Initial sync RX window initiation time not configured */

#endif /*  __UCI_PROP_DEFS_H__ */
