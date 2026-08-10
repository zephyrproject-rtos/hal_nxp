/*
 *
 * Copyright 2018-2020,2022-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UWBAPI_TYPES_H
#define UWBAPI_TYPES_H

#include "phUwbTypes.h"
#include "zephyr/uwb/uci.h"
#include <uwb_board.h>
#include "zephyr/uwb/uwb_core.h"
#include "zephyr/uwb/types.h"
#include "zephyr/uwb/uwb.h"

#ifdef UWBIOT_USE_FTR_FILE
#include "uwb_iot_ftr.h"
#else
#include "uwb_iot_ftr_default.h"
#endif

/**
 *  @brief Constants used by UWBD
 */

/** \addtogroup Uwb_Constants
 * @{ */

#if defined(UWBIOT_TIMING_RSTU) && (UWBIOT_TIMING_RSTU == 1)
/* Convert micro seconds to RSTU if Needed */
#define UWBIOT_USEC_TIMING(V) ((V)*6 / 5)
#define UWBIOT_RSTU_TIMING(V) (V)
#else
/* KEEP USEC to USEC */
#define UWBIOT_USEC_TIMING(V) (V)
#define UWBIOT_RSTU_TIMING(V) ((V)*5 / 6)
#endif

/**
 *  @brief Constants used by UWB API layer
 */

/**  MAX UCI header size */
#define MAX_UCI_HEADER_SIZE 4
/**  MAX UCI packet size */
#define MAX_UCI_PACKET_SIZE 255
/**  MAX API transfer packet size
 *  Needed 768 bytes for set and get calibration
 */
#define MAX_API_PACKET_SIZE 768
/** MAX Number of Responders, for Contention based Ranging it can go upto 12 */
#define MAX_NUM_RESPONDERS 12
/**  max app data size */
#define MAX_APP_DATA_SIZE 116
/**  Max psdu data size
 * MAX 128 for BPRF
 * MAX 4096 for HPRF
 */
#if UWBFTR_ChainedUCI
#define MAX_PSDU_DATA_SIZE 4096
#else
#define MAX_PSDU_DATA_SIZE 128
#endif // UWBFTR_ChainedUCI

/** Max debug ntf size */
#define MAX_DEBUG_NTF_SIZE 4100
/** MAX Profile Blob Size v1.0*/
#define TOTAL_PROFILE_BLOB_SIZE_v1_0 28
/** MAX Profile Blob Size v1.1*/
#define TOTAL_PROFILE_BLOB_SIZE_v1_1 30
/** Number of channels */
#define NO_OF_CHANNELS 4
/** Number of blocks */
#define NO_OF_BLOCKS 4
/**  AOA Phase difference length */
#define AOA_PHASE_DIFF_LEN 4
/**  AOA UCI Field length */
#define AOA_LEN 4
/**  Single AOA length */
#define SINGLE_AOA_LEN 4
/** sub session Handle length */
#define SUBSESSION_HANDLE_LEN 4
/** add a controllee to multicast addr list */
#define MULTICAST_LIST_ADD_CONTROLEE 0
/** delete a controlee from multicast addr list */
#define MULTICAST_LIST_DEL_CONTROLEE 1
#define DEFAULT_EVENT_TYPE           0xFF
/**  UWB command time out 2 Sec */
#define UWB_CMD_TIMEOUT 2000
/**  UWB transmission status timeout */
#define UWBD_LOCK_TIMEOUT 2000
/**  UWB device bind lock timeout 2 sec */
#define UWBD_TRANSMIT_NTF_TIMEOUT 10000
/**  timeout for SE APIs */
#define UWBD_SE_TIMEOUT 10000
/**  timeout for SE Ranging APIs */
#define UWBD_SE_RANGING_TIMEOUT 40000
/**  Time out value for calibration notification */
#define UWBD_CALIB_NTF_TIMEOUT 2000
/**  Time out value for do calibration notification */
#define UWBD_DO_CALIB_NTF_TIMEOUT 2000
/** Time out value for Binding Status Notification */
#define UWBD_BINDING_STATUS_NTF_TIMEOUT 2000
/**  Key Fetch Error Retry Count */
#define UWB_KEY_FETCH_ERROR_RETRY_COUNT 0x01
/**  Time out value for Generate Tag notification */
#define UWBD_GENERATE_TAG_NTF_TIMEOUT 2000
#if UWBIOT_UWBD_SR04X
/**  Error OTS TX During Status value */
#define STATUS_ERROR_OTS_TX_DURING_RANGING 0x50
#else
/**  Binding Success Status value */
#define STATUS_BINDING_SUCCESS 0x50
#endif

/** MAX Number of Anchor Locations */
#define MAX_ANCHOR_LOCATIONS 12
/** MAX Number of Anchor Locations V2 */
#define MAX_ANCHOR_LOCATIONS_V2 19
/** Max RX-TX Timestamp */
#define MAX_RX_TX_TIMESTAMP 8
/** MAX Active Ranging Rounds */
#define MAX_ACTIVE_RR 0xF
/** MAX Active Ranging Rounds V2 */
#define MAX_ACTIVE_RR_V2 0xFF
/** TX timestamp type */
#define TX_TIMESTAMP_TYPE 1
/** TX timestamp length */
#define TX_TIMESTAMP_LEN 2
/** RX timestamp length */
#define RX_TIMESTAMP_LEN 8
/**WGS-84 Coordinates system for DT-Anchor location */
#define ANCHOR_LOCATION_WGS84 32
/** Relative Coordinate system for DT-Anchor location */
#define ANCHOR_LOCATION_REL 64
/** Number of Active Ranging Rounds */
#define ACTIVE_RR_OFSET 7
/** Maximum number of sessions **/
#if UWBIOT_UWBD_SR2XXT
#define MAXIMUM_SESSION_COUNT 8
#else
#define MAXIMUM_SESSION_COUNT 5
#endif // UWBIOT_UWBD_SR2XXT
/** Max UWBD binding Count */
#define MAX_UWBD_BINDING_CNT 3
/** UWBD binding Status */
#define UWBD_NOT_BOUND 0
/** Failed to create thread */
#define THREAD_CREATION_FAILED 0
/** Maximun number of phases, 1 octet */
#define MAX_PHASE_COUNT 6
/** Max Destination Address List Size */
#define MAX_DST_ADDR_LIST_SIZE 5
/** Max allowed range slots */
#define MAX_ALLOWED_SLOT_INDEX 32768
/** Maximum slot bitmap size */
#define MAX_SLOT_BITMAP_SIZE 32
/** Session Handle offset in response */
#define SESSION_HANDLE_OFFSET 1
/** Session Handle offset length, 1-octet status + 4-octets SessionHandle */
#define SESSION_HANDLE_OFFSET_LEN (1 + 4)
/** MAX CCM TAG SIZE */
#define MAX_CCM_TAG_SIZE 8
/** Max Spec Version Length */
#define MAX_SPEC_VER_LEN 2
/* Max sharable data header length for Android  */
#define SHAREABLE_DATA_HEADER_LENGTH_ANDROID 14
/* Max sharable data header length for Android  */
#define RANGING_CAP_RESPONSE_LENGTH_ANDROID         18
#define RANGING_CAP_HEADER_LENGTH_ANDROID           16
#define RANGING_CONFIG_RESPONSE_LENGTH_ANDROID      14
#define RANGING_SESSION_KEY_LEN_16                  16
#define RANGING_SESSION_KEY_LEN_32                  32
#define RANGING_CAP_PAYLOAD_LEN_WITH_SESSION_KEY_16 35
#define RANGING_CAP_PAYLOAD_LEN_WITH_SESSION_KEY_32 51
#define RANGING_CAP_PAYLOAD_LEN_STATIC_STS          27
#define RANGING_TECHNOLOGY_UWB                      0
/** Max send data header length
 * 4(Session Handle) + 8(mac address) + 1(dst endpoint) + 1(seq no) + 2(data size)
 */
#define SEND_DATA_HEADER_LEN 16
/* Logical Link Control Field MAsk */
#define LL_CONTROL_FIELD_MASK 0x00FF
/** Max RF Channels */
#define MAX_CHANNELS 2
/** Last PHY STS Index size */
#define MAX_LAST_PHY_STS_INDEX_SZ 4

/** Skip MAC Address mode offset [b0] */
#define SKIP_MAC_ADDR_OFFSET 1
/** Ranging Slot Offset [b1-b3] */
#define RANGING_SLOT_OFFSET 1
/** Get Ranging Slots for slot bitmap */
#define GET_RANGING_SLOTS(x) (RANGING_SLOT_OFFSET << (x >> SKIP_MAC_ADDR_OFFSET))

/** Logical Link Mode defines */
/* CMD/RES Link Class Id */
#define Link_CLASS_ID0 0x00
/* Basic Data Transfer Link Class Id */
#define LINK_CLASS_ID1 0x01
/* Encoding for MAX TX SDU size */
#define MAX_TX_SDU_SZ(val) ((val & 0x0F))
/* Encoding for MAX RX SDU size */
#define MAX_RX_SDU_SZ(val) ((val & 0xF0) >> 4)

#define MAX_NUMBER_OF_PRESENCE_DETECTIONS 5

/* Default notification timeout in milliseconds */
#define DEFAULT_NTF_TIMEOUT_MS 2000

/**
 * @brief Enumeration lists out the possible MAC address lengths.
 */
typedef enum
{
    /**  Short MAC Mode Address length */
    SHORT_MAC_ADDR_LEN = 0x02,
    /**  Extended MAC Mode Address length */
    EXT_MAC_ADDR_LEN = 0x08,

} eMacAddrLen_t;

/** Deprecated */
#define eMacAddrModes_t uwb_mac_addr_mode_t
#define SHORT_MAC_ADDRESS_MODE kUWB_MacAddressMode_2bytes
#define EXTENDED_MAC_ADDRESS_MODE kUWB_MacAddressMode_8bytes
#define EXTENDED_MAC_ADDRESS_MODE_WITH_HEADER kUWB_MacAddressMode_8bytesWithHeader
#define Link_Layer_Mode_Bypass kUwb_LinkLayerMode_Bypass
#define Link_Layer_Mode_LogicalLink kUwb_LinkLayerMode_LogicalLink
#define eSessionType uwb_session_type_t
#define UWB_MacAddressMode_t uwb_mac_addr_mode_t
#define tUwbApi_AppDataCallback tUwbApi_TMLDataCallback
#define eMulticastControllerActions_t uwb_multicast_controller_actions_t
#define phDataTxPhaseMngList_t uwb_data_tx_phase_mng_list_t
#define kUwb_ConnectionLessNonSecure kUwb_LinkLayerMode_ConnectionLessNS
#define kUwb_ConnectionLessSecure kUwb_LinkLayerMode_ConnectionLessS
#define kUwb_ConnectionOrientedNonSecure kUwb_LinkLayerMode_ConnectionOrientedNS
#define kUwb_ConnectionOrientedSecure kUwb_LinkLayerMode_ConnectionOrientedS
#define kUwb_ConnectionLessUWBS kUwb_LinkLayerMode_ConnectionLessUWBS
#define kUwb_ConnectionOrientedUWBS kUwb_LinkLayerMode_ConnectionOrientedUWBS
#define eLinkLayerModes size_t

#define UWBD_RANGING_SESSION kUwb_SessionType_Ranging
#define UWBD_RANGING_WITH_INBAND_DATA_TRANSFER kUwb_SessionType_RangingDataTransfer
#define UWBD_DATA_TRANSFER kUwb_SessionType_DataTransfer
#define UWBD_RANGING_ONLY_PHASE kUwb_SessionType_SecondaryRanging
#define UWBD_INBAND_DATA_PHASE kUwb_SessionType_SecondaryDataTransfer
#define UWBD_RANGING_WITH_DATA_PHASE kUwb_SessionType_SecondaryRangingWithDataTransfer
#define UWBD_HUS_SESSION kUwb_SessionType_PrimaryHUS
#define UWBD_CCC_SESSION kUwb_SessionType_CCC
#define UWBD_CSA_SESSION kUwb_SessionType_CSA
#define UWBD_RFTEST kUwb_SessionType_DeviceTest
#define UWBD_RADAR_TRANSFER 0xF0

#define kUWB_StsConfig_DynamicSts_Ctrlee_key kUwb_StsConfig_DynamicSts_ResponderKey
#define kUWB_StsConfig_ProvisionSts kUwb_StsConfig_ProvisionedSts
#define kUWB_StsConfig_ProvisionSts_Ctrlee_key kUwb_StsConfig_ProvisionedSts_ResponderKey

/**
 * @brief Structure List out Controlee info.
 */
typedef struct phControleeList
{
    /** Short address*/
    uint16_t short_address;
    /** Sub Session Handle */
    uint32_t subsession_id;
    /**Controlee specific Sub-session Key 16/32 Bytes*/
    uint8_t subsession_key[MAX_SUB_SESSION_KEY_LEN];

} phControleeList_t;

/**
 * @brief Structure for storing Multicast Controlee List Context.
 */
typedef struct phMulticastControleeListContext
{
    uint32_t sessionHandle;
    /** Action */
    uint8_t action;
    /** Controlee Count */
    uint8_t no_of_controlees;
    /** Controlee List */
    phControleeList_t controlee_list[UWB_MAX_NUM_PHYSICAL_ACCESS_CONTROLEES];

} phMulticastControleeListContext_t;

/**
 * @brief Structure for storing Multicast Controlee Status List Context.
 */
typedef struct phMulticastControleeStatusList
{
#if UWBIOT_UWBD_SR1XXT_SR2XXT
    uint16_t controlee_mac_address;
#endif
    uint8_t status;
} phMulticastControleeStatusList_t;

/**
 * @brief Structure for storing Multicast Controlee List Ntf Context.
 */
typedef struct phMulticastControleeListRspContext
{
    uint8_t status;
    uint8_t no_of_controlees;
    phMulticastControleeStatusList_t controleeStatusList[UWB_MAX_NUM_PHYSICAL_ACCESS_CONTROLEES];
} phMulticastControleeListRspContext_t;

#define phMulticastControleeListNtfContext_t uwb_session_update_controller_multicast_list_notification_t

#if !(UWBIOT_UWBD_SR04X)
typedef struct {
    /** In-param to fetch the Connection ID
     * If the msb of MSB is 0b1, then the connectionId indicates a sessionHandle
     * If the msb of MSB is 0b0, then the connectionId indicates a LL_Connect_Id.
     */
    uint32_t connectionId;
    /* out param to catch Max Data Size in a single ranging round received in response */
    uint16_t dataSize;
} phUwbQueryDataSize_t;
#endif // !(UWBIOT_UWBD_SR04X)

typedef struct {
    /** Secondary Session Handle */
    uint32_t phase_sessionHandle;
    /** Start Slot Index */
    uint16_t start_slot_index;
    /** End Slot Index */
    uint16_t end_slot_index;
    /** b0 : MAC addressing mode of the Controller of the Phase
     *  b0=0 for short MAC address
     *  b0=1 for extended MAC address
     *  b1 : Phase type
     *  b1=0 for CFP
     *  b1=1 for CAP */
    uint8_t control;
    /** MAC address of the participating device in the current phase */
    uint8_t mac_addr[UWB_EXTENDED_MAC_ADDRESS_LEN];

} phCtlrPhaseList_t;

/**
 * @brief Structure for storing Controller HUS Session Configurations.
 */
typedef struct phControllerHusSessionConfig
{
    /** Primary Session Handle */
    uint32_t sessionHandle;

    /** Number of Phases */
    uint8_t phase_count;

    /** Phase List
     *  It shall have memory allocation for phase_count number of counts.
     */
    phCtlrPhaseList_t *phase_list;

} phControllerHusSessionConfig_t;

/**
 * @brief Structure for storing List of Phases of Controlee.
 */
typedef struct uwb_clee_phase_list
{
    /** Secondary Session Handle */
    uint32_t phase_sessionHandle;

} phCleePhaseList_t;

/**
 * @brief Structure for storing Controlee HUS Session Configurations.
 */
typedef struct uwb_controlee_hus_session_config
{
    /** Primary Session Handle */
    uint32_t sessionHandle;

    /** Number of Phases */
    uint8_t phase_count;

    /** Phase List
     *  It shall have memory allocation for phase_count number of counts.
     */
    phCleePhaseList_t *phase_list;

} phControleeHusSessionConfig_t;

typedef struct {
    /** Session Handle to which Data Transfer phase to be configured */
    uint32_t dtpcm_SessionHandle;
    /** Data Transfer Phase Control Message Repetition */
    uint8_t dtpcm_Repetition;
    /** Data Transfer Control */
    uint8_t dataTransferCtrl;
    /** Data Transfer Phase Management List Size */
    uint8_t dtpml_size;
    /** Data Transfer Phase Management List */
    phDataTxPhaseMngList_t *dtpml;
} phDataTxPhaseConfig_t;

typedef struct {
    /** Session Handle to the Data Transfer session or phase for which this Logical Link is created */
    uint32_t session_handle;
    /** Link Layer Mode Selector - one of the value from eSelectLogicalLinkModes_t*/
    uint8_t llm_selector;
    /** Logical destination address of the Controlee of the logical link.
     * \note In case of SHORT_ADDR mode is used, then each Octet from octets 2 - 7 shall be set to 0x00.
     */
    uint8_t dst_address[UWB_EXTENDED_MAC_ADDRESS_LEN];
    /** Logical Link Class length
     * 0x00: no Logical Link Class field present
     **/
    uint8_t ll_class_length;
    /** MAX SDU SIZE Value field length
    * 0x00: 0 Octets, not present
    * 0x01: 1 Octet
    * 0x02 – 0xFF: RFU
    **/
    uint8_t ll_max_sdu_size_length;
    /** Maximum transmit and receive SDU Size
    * Bits 0-3: encode maximum transmit SDU size
    * Bits 4-7: encode maximum receive SDU size
    * Encoding for bits 0-3 and bits 4-7, respectively, is as follows:
    * 0: 64 Bytes
    * 1: 128 Bytes
    * 2: 192 Bytes
    * 3: 256 Bytes
    * 4: 384 Bytes
    * 5. 512 Bytes
    * 6: 760 Bytes
    * 7: 1024 Bytes
    * 8: 1536 Bytes
    * 9: 2048 Bytes
    * 10: 4096 Bytes
    * 11: 8192 Bytes
    * 12: 16384 Bytes
    * 13: 32768 Bytes
    * 14-15: RFU
    * Host request to UWBS to manage its internal memory such that at least 1 SDU with maximum transmit and receive SDU size for this logical link can be handled.
    **/
    uint8_t ll_max_sdu_size_value;
} phLogicalLinkCreateCmd_t;

typedef struct {
    /** Status code */
    uint8_t status;
    /** Control Field */
    uint16_t control_field;
    /** Maximum LL SDU size */
    uint16_t ll_sdu_size;
    /** Maximum LL PDU size */
    uint16_t ll_pdu_size;
    /** Transmit Window Size, TxW */
    uint8_t Tx_window_size;
    /** Receive Window Size, RxW */
    uint8_t Rx_window_size;
    /** Repetition count Max */
    uint8_t repetition_count;
    /** Link TO */
    uint8_t link_to;
    /** PORT */
    uint8_t port;
} phLogicalLinkGetParamsRsp_t;

/**
 * \brief Enemeration Lists out the Logical Link get param Control field values
 */
typedef enum
{
    /** Maximum LL SDU size */
    LL_GET_PARAM_CF_SDU_SIZE = 0x01,
    /** Maximum LL PDU size */
    LL_GET_PARAM_CF_PDU_SIZE = 0x02,
    /** Transmit Window Size, TxW */
    LL_GET_PARAM_CF_TxW = 0x04,
    /** Receive Window Size, RxW */
    LL_GET_PARAM_CF_RxW = 0x08,
    /** Repetition count Max */
    LL_GET_PARAM_CF_REP_CNT_MAX = 0x10,
    /** Link TO */
    LL_GET_PARAM_CF_LINK_TO = 0x20,
    /** PORT */
    LL_GET_PARAM_CF_PORT = 0x40,
} rLlGetParam_controlField_t;

#if UWBFTR_DataTransfer

typedef struct phUwbDataPkt
{
    /** Session Handle */
    uint32_t sessionHandle;
    /** MAC Address
     * \note In case short address is used, only the two least significant Octets are considered, and the upper 6 Octets shall be set with the value zero.
     */
    uint8_t mac_address[UWB_EXTENDED_MAC_ADDRESS_LEN];
    /** Sequence Number */
    uint16_t sequence_number;
    /** Data Size */
    uint16_t data_size;
    /** Application Data */
    uint8_t *data;
} phUwbDataPkt_t;

#define phUwbRcvDataPkt_t uwb_data_receive_notification_t
#endif // UWBFTR_DataTransfer

/** End of deprecated values */

/* Device Capability Lengths */
#define DEVICE_CAPABILITY_LEN_1 1
#define DEVICE_CAPABILITY_LEN_2 2
#define DEVICE_CAPABILITY_LEN_3 3
#define DEVICE_CAPABILITY_LEN_4 4
#define DEVICE_CAPABILITY_LEN_5 5
#define DEVICE_CAPABILITY_LEN_6 6
#define DEVICE_CAPABILITY_LEN_9 9

#define NUM_SUPPORTED_PROTOCOL_VERSIONS 2
#define NUM_SUPPORTED_UWB_CONFIG_ID     2
#define NUM_SUPPORTED_ALIRO_PROTOCOL_VERSIONS 2
/** Extented Calibration Param Id*/
#define EXTENTED_CALIB_PARAM_ID 0xE0

/*Device Info Parameters*/
#if (UWBIOT_UWBD_SR040)
#define FIRA_PHY_VERSION_RANGE_ID       0x00
#define FIRA_MAC_VERSION_RANGE_ID       0x01
#define DEVICE_ROLES_ID                 0x02
#define RANGING_METHOD_ID               0x03
#define STS_CONFIG_ID                   0x04
#define MULTI_NODE_MODE_ID              0x05
#define RANGING_TIME_STRUCT_ID          0x06
#define SCHEDULED_MODE_ID               0x07
#define HOPPING_MODE_ID                 0x08
#define BLOCK_STRIDING_ID               0x09
#define UWB_INITIATION_TIME_ID          0x0A
#define CHANNELS_ID                     0x0B
#define RFRAME_CONFIG_ID                0x0C
#define CC_CONSTRAINT_LENGTH_ID         0x0D
#define BPRF_PARAMETER_SETS_ID          0x0E
#define HPRF_PARAMETER_SETS_ID          0x0F
#define AOA_SUPPORT_ID                  0x10
#define EXTENDED_MAC_ADDR_ID            0x11
#define MAX_MESSAGE_SIZE_ID             0x12
#define MAX_DATA_PACKET_PAYLOAD_SIZE_ID 0x13

#else // !(UWBIOT_UWBD_SR040)
/* SR048 Follows the FiRa 2.0 */
#define MAX_MESSAGE_SIZE_ID             kUwb_Capability_MaxDataMessageSize
#define MAX_DATA_PACKET_PAYLOAD_SIZE_ID kUwb_Capability_MaxDataPacketPayloadSize
#define FIRA_PHY_VERSION_RANGE_ID       kUwb_Capability_FiraPhyVersionRange
#define FIRA_MAC_VERSION_RANGE_ID       kUwb_Capability_FiraMacVersionRange
#define DEVICE_TYPE_ID                  kUwb_Capability_DeviceType
#define DEVICE_ROLES_ID                 kUwb_Capability_DeviceRoles
#define RANGING_METHOD_ID               kUwb_Capability_RangingMethod
#define STS_CONFIG_ID                   kUwb_Capability_StsConfig
#define MULTI_NODE_MODE_ID              kUwb_Capability_MultiNodeMode
#define RANGING_TIME_STRUCT_ID          kUwb_Capability_RangingTimeStruct
#define SCHEDULED_MODE_ID               kUwb_Capability_ScheduleMode
#define HOPPING_MODE_ID                 kUwb_Capability_HoppingMode
#define BLOCK_STRIDING_ID               kUwb_Capability_BlockStriding
#define UWB_INITIATION_TIME_ID          kUwb_Capability_UwbInitiationTime
#define CHANNELS_ID                     kUwb_Capability_Channels
#define RFRAME_CONFIG_ID                kUwb_Capability_RframeConfig
#define CC_CONSTRAINT_LENGTH_ID         kUwb_Capability_CcConstraintLength
#define BPRF_PARAMETER_SETS_ID          kUwb_Capability_BprfParameterSets
#define HPRF_PARAMETER_SETS_ID          kUwb_Capability_HprfParameterSets
#define AOA_SUPPORT_ID                  kUwb_Capability_AoaSupport
#define EXTENDED_MAC_ADDR_ID            kUwb_Capability_ExtendedMacAddress
/** FIXME: To be remove SUSPEND_RANGING_ID*/
#define SUSPEND_RANGING_ID              0x15
#define SESSION_KEY_LEN_ID              kUwb_Capability_SessionKeyLength
#define DT_ANCHOR_MAX_ACTIVE_RR_ID      kUwb_Capability_DtAnchorMaxActiveRr
#define DT_TAG_MAX_ACTIVE_RR_ID         kUwb_Capability_DtTagMaxActiveRr
#define DT_TAG_BLOCK_SKIPPING_ID        kUwb_Capability_DtTagBlockSkipping
#define PSDU_LENGTH_SUPPORT_ID          kUwb_Capability_PsduLengthSupport
#define LL_CAPABILITY_PARAM             kUwb_Capability_LlCapabilityParam
#define BYPASS_MODE_SUPPORT             kUwb_Capability_BypassModeSupport
#define MIN_SLOT_DURATION_SUPPORT       kUwb_Capability_MinSlotDurationSupport
#define FIRA_LL_VERSION                 kUwb_Capability_FiraLLVersion

#endif /* (UWBIOT_UWBD_SR04X) */

#if UWBFTR_CCC
#define SLOT_BITMASK               0xA0
#define SYNC_CODE_INDEX_BITMASK    0xA1
#define HOPPING_CONFIG_BITMASK     0xA2
#define CHANNEL_BITMASK            0xA3
#define SUPPORTED_PROTOCOL_VERSION 0xA4
#define SUPPORTED_UWB_CONFIG_ID    0xA5
#define SUPPORTED_PULSESHAPE_COMBO 0xA6
#define CCC_MINIMUM_RAN_MULTIPLIER 0XA7
#endif /* UWBFTR_CCC */
#if UWBFTR_CSA
#define ALIRO_SUPPORTED_MAC_MODES        0xAC
#define ALIRO_SUPPORTED_PROTOCOL_VERSION 0xAD
#endif /* UWBFTR_CSA */

/**  EXTENDED PARAM ID MASK */
#define EXTENDED_PARAM_ID_MASK 0xF0
/** CCC PARAM ID */
#define CCC_INFO_ID 0xA0
/*CCC EXT PARAM ID*/
#define CCC_EXT_PARAM_ID 0xE0
/** Maximum number of PDoA Measurements */
#define MAX_NO_OF_PDOA_MEASUREMENTS 255
/** Maximum number of ccc RSSI Measurements */
#define MAX_NO_OF_CCC_RSSI_MEASUREMENTS 2U
/** Maximum number of csa RSSI Measurements */
#define MAX_NO_OF_CSA_RSSI_MEASUREMENTS MAX_NO_OF_CCC_RSSI_MEASUREMENTS
/** Maximum number of ccc SNR Measurements
 * for H1:
 *  - poll rx1
 *  - poll rx2
 *  - final rx1
 *  - final rx2
 * */
#if UWBIOT_UWBD_SR250
#define MAX_NO_OF_CCC_SNR_MEASUREMENTS 6U
#else
#define MAX_NO_OF_CCC_SNR_MEASUREMENTS 4U
#endif // UWBIOT_UWBD_SR250

/** Maximum number of csa SNR Measurements
 * for H1:
 *  - poll rx1
 *  - poll rx2
 *  - final rx1
 *  - final rx2
 * */
#define MAX_NO_OF_CSA_SNR_MEASUREMENTS MAX_NO_OF_CCC_SNR_MEASUREMENTS

/**Number of aoa fine calib ctrl pairs, per ch, per pol per ant, 8**/
#define NO_OF_CALIB_PAIRS 4
/**Number of ang sweeps for aoa fine calib**/
#define AOA_FINE_CALIB_HOR_SWEEPS 11
#define AOA_FINE_CALIB_VER_SWEEPS 11

#define UWB_IOS_SPEC_VERSION_MAJOR \
    {                              \
        0x01, 0x00                 \
    }
#define UWB_IOS_SPEC_VERSION_MINOR \
    {                              \
        0x01, 0x00                 \
    }

#define UWB_ANDROID_SPEC_VERSION_MAJOR \
    {                                  \
        0x01, 0x00                     \
    }
#define UWB_ANDROID_SPEC_VERSION_MINOR \
    {                                  \
        0x00, 0x00                     \
    }

#define MANUFACTURER_ID        \
    {                          \
        0x32, 0x11, 0x10, 0x00 \
    } // NXP Manufacturer ID

/** Static STS for Android */
#define UWB_ANDROID_STATIC_STS             \
    {                                      \
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06 \
    }

/** Vendor Id for Android */
#define UWB_ANDROID_VENDOR_ID \
    {                         \
        0x08, 0x07            \
    }

/** Definitions for the UWB configuration IDs */
#define UWB_CONFIG_ID_1_MASK (uint32_t)(1 << 1)
#define UWB_CONFIG_ID_2_MASK (uint32_t)(1 << 2)
#define UWB_CONFIG_ID_3_MASK (uint32_t)(1 << 3)
#define UWB_CONFIG_ID_4_MASK (uint32_t)(1 << 4)
#define UWB_CONFIG_ID_5_MASK (uint32_t)(1 << 5)
#define UWB_CONFIG_ID_6_MASK (uint32_t)(1 << 6)
/** Definitions for the UWB configuration IDs */
#define UWB_CONFIG_ID_1 0x01U
#define UWB_CONFIG_ID_2 0x02U
#define UWB_CONFIG_ID_3 0x03U
#define UWB_CONFIG_ID_4 0x04U
#define UWB_CONFIG_ID_5 0x05U
#define UWB_CONFIG_ID_6 0x06U

/* Max number of confgis */
#if (UWBIOT_UWBD_SR04X)
#define MAX_CONFIG_ID_NUM_CONFIGS 11
#else
#define MAX_CONFIG_ID_NUM_CONFIGS 10
#endif
/** Defines supported UWB configuration IDs by the device */
#define UWB_SUPPORTED_CONFIG_IDS (uint32_t)(UWB_CONFIG_ID_1_MASK | UWB_CONFIG_ID_2_MASK | UWB_CONFIG_ID_3_MASK)
#define UWB_SUPPORTED_CONFIG_IDS_FIND_HUB                                                                  \
    (uint32_t)(UWB_CONFIG_ID_1_MASK | UWB_CONFIG_ID_2_MASK | UWB_CONFIG_ID_3_MASK | UWB_CONFIG_ID_4_MASK | \
               UWB_CONFIG_ID_5_MASK | UWB_CONFIG_ID_6_MASK)
// Macro to set the supported channel bit
#define SET_SUPPORTED_CHANNEL(value) (1U << (value))
// Macro to set the preamble index bit (1-based index)
#define SET_PREAMBLE_INDEX(value) (1U << ((value)-1))
/** Definitions for the supported UWB roles */
/** UWB device supports Controller device type and Initiator device role */
#define UWB_DEVICE_CONTROLLER (uint8_t)(1 << 0)
/** UWB device supports Controlee device type and Responder device role */
#define UWB_DEVICE_CONTROLEE (uint8_t)(1 << 1)

/** Defines the set of UWB Ranging role configurations supported by the UWB device */
#if (UWBIOT_UWBD_SR04X)
#define UWB_SUPPORTED_DEVICE_RANGING_ROLES (uint8_t)(UWB_DEVICE_CONTROLLER)
#else
#define UWB_SUPPORTED_DEVICE_RANGING_ROLES (uint8_t)(UWB_DEVICE_CONTROLLER | UWB_DEVICE_CONTROLEE)
#endif /* (UWBIOT_UWBD_SR04X) */

#define PRESENCE_DETECTED       1
#define PRESENCE_DETECTED_VALUE 0x10

/** @} */ /* @addtogroup uwb_const */

/** \addtogroup uwb_status
 * @{ */
/**
 * @brief Status Codes, as per UCI.
 */
/*********************************************************
 *              Generic Status Codes
 *********************************************************/
/**  Command succeeded */
#define UWBAPI_STATUS_OK 0x00
/**  Request is rejected */
#define UWBAPI_STATUS_REJECTED 0x01
/**  Command Failed */
#define UWBAPI_STATUS_FAILED 0x02
/**  API called without UCI being initialized */
#define UWBAPI_STATUS_NOT_INITIALIZED 0x03
/**  Invalid parameter provided */
#define UWBAPI_STATUS_INVALID_PARAM 0x04
/** Invalid value range provided */
#define UWBAPI_STATUS_INVALID_RANGE 0x05
/* UCI packet structure is not per spec */
#define UWBAPI_STATUS_SYNTAX_ERROR 0x06
/**********************************************************
 *         UWB Session Specific Status Codes
 *********************************************************/
/** Session wrt SESSION Handle Does not exist */
#define UWBAPI_STATUS_SESSION_NOT_EXIST 0x11
/**  Session active */
#define UWBAPI_STATUS_SESSION_ACTIVE 0x13
/**  MAX Sessions exceeded */
#define UWBAPI_STATUS_MAX_SESSIONS_EXCEEDED 0x14
/**  Operation is started with out configuring required parameters for Session */
#define UWBAPI_STATUS_SESSION_NOT_CONFIGURED 0x15
/**  Sessions ongoing */
#define UWBAPI_STATUS_SESSIONS_ONGOING 0X16
/**  Indicates when multicast list is full during one to many ranging */
#define UWBAPI_STATUS_MULTICAST_LIST_FULL 0x17
/** Slot allocation for phases is not correct */
#define UWBAPI_STATUS_ERROR_SESSION_INVALID_SLOT_ALLOCAION 0x18
/** Slot duration of the secondary is not integer multiple of the slot duration of primary session */
#define UWBAPI_STATUS_ERROR_SESSION_INVALID_SLOT_DURATION 0x19

/** Negative distance was reported */
#define UWBAPI_STATUS_OK_NEGATIVE_DISTANCE_REPORT 0x1B
/**********************************************************
 *      UWB Ranging Session Specific Status Codes
 *********************************************************/
/**  ESE Rest happened during command processing. */
#define UWBAPI_STATUS_ESE_RESET 0x71
/** Unrecoverable data transfer error */
#define UWBAPI_STATUS_DATA_TRANSFER_ERROR 0x30
/** Credit not available for Data Packet */
#define UWBAPI_STATUS_NO_CREDIT_AVAILABLE 0x31
/** Given round index couldn't be activated */
#define UWBAPI_STATUS_ERROR_ROUND_INDEX_NOT_ACTIVATED 0x28
/** Given round exceeds the possible number of ranging rounds */
#define UWBAPI_STATUS_ERROR_NUMBER_OF_ACTIVE_RANGING_ROUNDS_EXCEEDED 0x29
/** The role for the configured ranging round index is not Initiator and therefore RDM list cannot be set */
#define UWBAPI_STATUS_ERROR_ROUND_INDEX_NOT_SET_AS_INITIATOR 0x2A
/** If there is a conflict in the role configuration of a UWBS (configured as Initiator DT-Anchor in more than one ranging round)*/
#define UWBAPI_STATUS_ROLE_ERROR 0x2B
/** Device address not matching */
#define UWBAPI_STATUS_DLTDOA_DEVICE_ADDRESS_NOT_MATCHING_IN_REPLY_TIMELIST 0x30
/**  Buffer overflow */
#define UWBAPI_STATUS_BUFFER_OVERFLOW 0xFA
/**  Status PBF=1 CMD SENT */
#define UWBAPI_STATUS_PBF_PKT_SENT 0xFB
/**  Device is woken up from HPD */
#define UWBAPI_STATUS_HPD_WAKEUP 0xFC
/**  Command failed with time out */
#define UWBAPI_STATUS_TIMEOUT 0xFD
/**  SE Error */
#define UWBAPI_STATUS_ESE_ERROR 0xFF
/**  Ranging suspended */
#define UWBAPI_STATUS_SUSPEND 0x8B
/** Ranging interval/slot duration incorrect */
#define UWBAPI_STATUS_SESSION_RSN_RADAR_RFRI_INVALID 0xB4
/** It is not known whether the intended operation was failed or successful. */
#define UWBAPI_STATUS_UNKNOWN 0x0B
/**********************************************************
 *      UWB Ranging Session Specific Status Codes
 *********************************************************/
/** Responder slot index is invalid in the requested configuration */
#define UWBAPI_STATUS_INVALID_RESPONDER_SLOT_INDEX 0xA0
/** Slot length is not supported in the requested configuration */
#define UWBAPI_STATUS_SLOT_LEN_NOT_SUPPORTED 0xA1
/** Number of slots is invalid in the requested configuration */
#define UWBAPI_STATUS_INVALID_SLOT_PER_RR 0xA2
/** STS index is not valid. */
#define UWBAPI_STATUS_INVALID_STS_IDX 0xA3
/** Responder is in the listen only mode. Responder does not send a range frame */
#define UWBAPI_STATUS_RESPONDER_NOT_PARTICIPATING_IN_MEASUREMENT 0xA4
/**
 * @brief Device Status codes, as per UCI.
 */
/** Device State - INIT */
#define UWBAPI_UCI_DEV_INIT 0x00
/**  Device State - READY */
#define UWBAPI_UCI_DEV_READY 0x01
/**  Device State - ACTIVE */
#define UWBAPI_UCI_DEV_ACTIVE 0x02
/** Device State - ERROR */
#define UWBAPI_UCI_DEV_ERROR 0xFF

/**
 * @brief Session State codes, as per UCI.
 */
/**  Session State - Session Init Success */
#define UWBAPI_SESSION_INIT_SUCCESS 0x00
/**  Session State - Session DeInit Success */
#define UWBAPI_SESSION_DEINIT_SUCCESS 0x01
/**  Session State - Session Activated */
#define UWBAPI_SESSION_ACTIVATED 0x02
/**  Session State - Session Idle */
#define UWBAPI_SESSION_IDLE 0x03
/**  Session State - Error */
#define UWBAPI_SESSION_ERROR 0xFF

/**
 * @brief Multicast update status codes, as per UCI.
 */
/**  The multicast list is updated (Add/Delete) successfully for the given Controlee. */
#define UWBAPI_STATUS_OK_MULTICAST_LIST_UPDATE (0x00)
/**  The multicast is full */
#define UWBAPI_STATUS_ERROR_MULTICAST_LIST_FULL (0x01)
/**  Session Key fetch from Secure Component is failed */
#define UWBAPI_STATUS_ERROR_KEY_FETCH_FAIL (0x02)
/**  Sub-Session ID is not found in Secure Component */
#define UWBAPI_STATUS_ERROR_SUB_SESSION_ID_NOT_FOUND (0x03)
/**  Sub-Session Key is not found in Secure Component */
#define UWBAPI_STATUS_ERROR_SUB_SESSION_KEY_NOT_FOUND (0x04)
/**  Sub-Session Key is configured with STS config is other than 0x04
 *  (Provisioned STS for Responder specific Sub-session Key) */
#define UWBAPI_STATUS_ERROR_SUB_SESSION_KEY_NOT_APPLICABLE (0x05)
/**  Sub-Session Key is configured but SESSION_KEY App configuration parameter is not programmed */
#define UWBAPI_STATUS_ERROR_SESSION_KEY_NOT_FOUND (0x06)
/**  its short address is not found while deleting its entry from multicast list */
#define UWBAPI_STATUS_ERROR_ADDRESS_NOT_FOUND (0x07)
/**  its short address is already present in the multicast list */
#define UWBAPI_STATUS_ERROR_ADDRESS_ALREADY_PRESENT (0x08)

/**
 * @brief Data Transfer related status codes.
 */
/** Data transmission is ongoing.*/
#define UWBAPI_DATA_TRANSFER_STATUS_REPETITION_OK 0x00
/** Data transmission is completed.*/
#define UWBAPI_DATA_TRANSFER_STATUS_OK 0x01
/** Application Data could not be sent due to an unrecoverable error*/
#define UWBAPI_DATA_TRANSFER_STATUS_ERROR 0x02
/** DATA_MESSAGE_SND is not accepted as no credit is available */
#define UWBAPI_DATA_TRANSFER_STATUS_NO_CREDIT_AVAILABLE 0x03
/** DATA_MESSAGE_SND packet sent in wrong state or Application Data Size exceeds the maximum size that can be sent in
 * one Ranging Round.*/
#define UWBAPI_DATA_TRANSFER_STATUS_REJECTED 0x04
/** Data transfer is not supported for given session type.*/
#define UWBAPI_DATA_TRANSFER_STATUS_TYPE_NOT_SUPPORTED 0x05
/** Application Data is being transmitted and the number of configured DATA_REPETITION_COUNT transmissions is not yet
 * completed */
#define UWBAPI_DATA_TRANSFER_DATA_TRANSFER_IS_ONGOING 0x06
/** The format of the command DATA_MESSAGE_SND associated with this notification is incorrect (e.g, a parameter is
 * missing, a parameter value is invalid).*/
#define UWBAPI_DATA_TRANSFER_STATUS_INVALID_FORMAT 0x07
/** Reported when the given LL_CONNECT_ID in LL_DATA_MESSAGE_SND is not valid */
#define STATUS_INVALID_LL_CONNECT_ID 0x08
/** Maximum SDU size exceeded in DATA_MESSAGE_SND or LL_DATA_MESSAGE_SND */
#define STATUS_SDU_SIZE_ERROR 0x09

#if (UWBIOT_UWBD_SR04X)
#define UWB_DATA_TRANSFER_STATUS UWBAPI_STATUS_OK
#else
#define UWB_DATA_TRANSFER_STATUS UWBAPI_DATA_TRANSFER_STATUS_OK
#endif  /* UWBIOT_UWB_SR04X */
/**
 * @brief UL-TDoA related definitions.
 */
/**  UL-TDoA Message Control Mask */
#define ULTDOA_MESSAGE_CONTROL_MASK (0x3F)
/** 16-bit UL-TDoA Device ID */
#define ULTDOA_DEVICE_ID_16BIT_VALUE (0x01)
/** 32-bit UL-TDoA Device ID */
#define ULTDOA_DEVICE_ID_32BIT_VALUE (0x02)
/** 64-bit UL-TDoA Device ID */
#define ULTDOA_DEVICE_ID_64BIT_VALUE (0x03)
/** MASK for above values. */
#define ULTDOA_DEVICE_ID_MASK (0x03)

/** 40-bit TX timestamp */
#define ULTDOA_40BIT_TX_TIMESTAMP_MASK (0x04)
/** 64-bit TX timestamp */
#define ULTDOA_64BIT_TX_TIMESTAMP_MASK (0x08)

/** 64-bit RX timestamp */
#define ULTDOA_64BIT_RX_TIMESTAMP_MASK (0x10)

/** Length in bytes for 16-bits */
#define ULTDOA_16BIT_IN_BYTES (0x02)

/** Length in bytes for 32-bits */
#define ULTDOA_32BIT_IN_BYTES (0x04)

/** Length in bytes for 40-bits */
#define ULTDOA_40BIT_IN_BYTES (0x05)

/** Length in bytes for 64-bits */
#define ULTDOA_64BIT_IN_BYTES (0x08)

/** Length in Bytes for 128-bits*/
#define AUTH_TAG_IN_16BYTES (0x10)

/**  Session State - Session Init Success */
#define UWBAPI_SESSION_INIT_SUCCESS 0x00

/** Max number of supported rx antenna ID/pair*/
#define MAX_NUM_ANTENNA_PAIR 8

/** FoV specific Vendor Data type*/
#define FOV_SPECIFIC_DATA_TYPE 0xA0

/**  NXP Specific Data with Message Control Vendor Data type*/
#define NXP_SPECIFIC_DATA_TYPE_WITH_MSG_CNTRL 0xA1

/** Cryptograpic tag length */
#define CRYPTO_TAG_LEN (16U)

/** Active Ranging Rounds prescence */
#define ACTIVE_RANGING_ROUNDS_MASK (0x02)

/** Active Location prescence */
#define ACTIVE_LOCATION_MASK (0x04)

/** supercluster prescence */
#define SUPERCLUSTER_MASK (0x08)

/** Macro to get the Array size */
#define GET_ARRAY_SIZE(arr) \
    ((sizeof(arr) == 0) ? 0 : \
     (sizeof((arr)[0]) == 0) ? 0 : \
     (sizeof(arr) / sizeof((arr)[0])))

#define IS_CSA_SESSION(sessionHandle) (((uint8_t *)(sessionHandle))[3] == UWBD_CSA_SESSION)

#define IS_CCC_SESSION(sessionHandle) (((uint8_t *)(sessionHandle))[3] == UWBD_CCC_SESSION)

/** @} */ /* @addtogroup uwb_status */

#define UWBD_RAW_154_SESSION 0xC0

/** \addtogroup uwb_types
 * @{ */

/**
 *  @brief Types used by Uwb APIs
 */

/**
 * @brief  Status used by UWB APIs.
 */
typedef uint32_t tUWBAPI_STATUS;

/**
 * \note   Notification specific return codes.
 */
/**
 * @brief  Data Transfer Phase configuration notification status codes.
 *
 * These error codes to be returned by the UWBS when the DTPML configuration
 * provided by the Host are applied.
 */
typedef enum DataTxPhaseCfg_NftCode_t
{
    /** Reported when DTPCM is configured for given MAC Address */
    DTPCM_STATUS_OK_DTPCM_CONFIG_SUCCESS = 0x00,
    /** Reported when configured slot assignments is inconsistent, i.e., one slot is
     * assigned to more than one FiRA device */
    DTPCM_STATUS_ERROR_DUPLICATE_SLOT_ASSIGMENT = 0x01,
    /** Reported when configured slot assignments cannot fit within one DTPCM. */
    DTPCM_STATUS_ERROR_DTPML_OVERSIZE = 0x02,
    /** Reported when DTPCM Repetition is set to 0x01 but the last assigned slot is not
     * assigned to the Controller. UWBS proceeds as if Repetition is 0x00. */
    DTPCM_STATUS_OK_DTPML_REPETITION_DISABLED = 0x03,
} eDataTxPhaseCfg_NftCode;

/**
 * @brief       RESET Modes.
 */
typedef enum resetType
{
    /** UWB Device Reset */
    UWBD_RESET = 0,
    /** RFU */
    RFU
} eDevResetMode;

/**
 * @brief Structure for storing  Session Data.
 */
typedef struct phUwbSessionData
{
    /** Session Handle */
    uint32_t sessionHandle;
    /** Session Type */
    uint8_t session_type;
    /** Session State */
    uint8_t session_state;
} phUwbSessionData_t;

/**
 * @brief Structure for storing  Session Context.
 */
typedef struct phUwbSessionsContext
{
    /** Status */
    uint8_t status;
    /** [Input/Output] Session Count */
    uint8_t sessioncnt;
    /** Pointer to Session Data */
    phUwbSessionData_t *pUwbSessionData;
} phUwbSessionsContext_t;

/**
 * @brief  UWBD notification Type.
 */
typedef enum notification_type
{
    /** Ranging Data Notification */
    UWBD_RANGING_DATA,
    /** Data Transmit Notification */
    UWBD_DATA_TRANSMIT_NTF,
    /** PER Packet Sent Notification */
    UWBD_PER_SEND,
    /** PER receive operation completed notification */
    UWBD_PER_RCV,
    /** TEST_SR_RX_NTF receive operation completed notification */
    UWBD_SR_RX_RCV,
    /** Generic Error Notification */
    UWBD_GENERIC_ERROR_NTF,
    /** Upon Receiving Device Reset, Application needs to
     * clear all session context and re-initiate all the
     * sessions */
    UWBD_DEVICE_RESET,
    /** RFRAME Data Notification */
    UWBD_RFRAME_DATA,
    /** DPD timings profiling notification */
    UWBD_DBG_DPD_INFO_NTF,
    /** CIR Pull Data notification */
    UWBD_CIR_PULL_DATA_NTF,
    /** Upon receiving Recovery Notification, Application has
     * to invoke Recovery API non main/application thread
     * context. */
    UWBD_RECOVERY_NTF,
    /** UWBS shall send SCHED_STATUS_NTF notification
     * when scheduler meets either
     * SESSION_SCHEDULER_ATTEMPTS or
     * SESSION_SYNC_ATTEMPTS configuration criteria. */
    UWBD_SCHEDULER_STATUS_NTF,
    /** Session Data Notification */
    UWBD_SESSION_DATA,
    /** Multicast list notification */
    UWBD_MULTICAST_LIST_NTF,
    /** Over Temperature reached notification */
    UWBD_OVER_TEMP_REACHED,
    /** Blink data tx notification */
    UWBD_BLINK_DATA_TX_NTF,
    /** Data Tx Phase Configuration Notification */
    UWBD_DATA_TRANSFER_PHASE_CONFIG_NTF,
    /** TEST RX notification */
    /** Perform Application Clean Up & Restart upon receiving this notification */
    UWBD_ACTION_APP_CLEANUP,
    /** Loopback Status Data */
    UWBD_TEST_MODE_LOOP_BACK_NTF,
    /** PHY LOG NTF */
    UWB_TEST_PHY_LOG_NTF,
    /** EXT PSDU LOG NTF */
    UWB_TEST_EXT_PSDU_LOG_NTF,
    /** TEST RX notification */
    UWBD_TEST_RX_RCV,
    /** Data receive */
    UWBD_DATA_RECV_NTF,
    /** CIR notification data */
    UWBD_CIR_DATA_NTF,
    /** Data logger ntf */
    UWBD_DATA_LOGGER_NTF,
    /** PSDU log ntf */
    UWBD_PSDU_DATA_NTF,
    /** RANGING timestamp ntf*/
    UWBD_RANGING_TIMESTAMP_NTF,
    /** COMMAND timestamp ntf*/
    UWBD_COMMAND_TIMESTAMP_NTF,
#if UWBFTR_DataTransfer
    /** Data receive notification */
    UWBD_DATA_RCV_NTF,
    /** Data Credit Notification */
    UWBD_CREDIT_RCV_NTF,
#endif // UWBFTR_DataTransfer
#if UWBFTR_Radar
    /** Radar rcv ntf */
    UWBD_RADAR_RCV_NTF,
    /** Test radar Isolation ntf */
    UWBD_TEST_RADAR_ISO_NTF,
    /** Presence detection ntf */
    UWBD_PRESENCE_DETECTION_NTF,
#endif // UWBFTR_Radar
    UWBD_WIFI_WLAN_IND_NTF,
    /** Max Active Grant Duration Exceeded Warning NTF */
    UWB_WLAN_COEX_MAX_GRANT_DURATION_EXCEEDED_WRN_NTF,
    /** WiFi CoEx IND Error Notification */
    WLAN_UWB_IND_NTF,
#if UWBFTR_CCC
    /** Ranging CCC/CSA Data Notification */
    UWBD_RANGING_CCC_DATA,
#endif // UWBFTR_CCC
    /** Event for Binding Status Notification */
    UWBD_BINDING_STATUS_NTF,
#if UWBFTR_TransitProp
    /** Notification Event for Session Set RDS Param */
    UWBD_SESSION_SET_RDS_PARAM_NTF,
#endif // UWBFTR_TransitProp
#if UWBFTR_DataTransfer
    /** Event for Logical Link Create Notification */
    UWBD_LL_CREATE_NTF,
    /** Event for Logical Link Close Notification */
    UWBD_LL_UWBS_CLOSE_NTF,
    /** Event for Logical Link create UWBS Notification */
    UWBD_LL_UWBS_CREATE_NTF,
    /** Logical Link Data receive notification */
    UWBD_LOGICAL_LINK_DATA_RCV_NTF,
#endif // UWBFTR_DataTransfer
    UWBD_SESSION_ROLE_CHANGE_RCV_NTF,
    /** Error Scenario TIMEOUT ntf*/
    UWBD_SESSION_ERROR_TIMEOUT_NTF,
#if UWBIOT_UWBD_SR048M
    UWBD_RAW_154_RNG_SYN_REF_TS_NTF,
    /** Event for raw 15.4 TX confirmation */
    UWBD_RAW_154_TX_NTF,
    /** Event for reception of a raw 15.4 frame */
    UWBD_RAW_154_RX_NTF,
#endif // UWBIOT_UWBD_SR048M
    /** Invalid notification event */
    UWBD_INVALID_NTF_EVT = 0xFF,
} eNotificationType;

/**
 * @brief  Structure lists out the ranging measurement information.
 *         Ranging measurements array for TWR
 */
typedef struct phRangingMesr
{
    /** Mac address of the participating device, addr can be
     * of short 2 byte or extended 8 byte modes */
    uint8_t mac_addr[UWB_EXTENDED_MAC_ADDRESS_LEN];
    /** Status */
    uint8_t status;
    /** Indicates if the ranging measurement was in Line of sight or
     * non-line of sight */
    uint8_t nLos;
    /** AOA Azimuth FOM */
    uint8_t aoa_azimuth_FOM;
    /** AOA elevation FOM */
    uint8_t aoa_elevation_FOM;
    /** AOA destination azimuth FOM */
    uint8_t aoa_dest_azimuth_FOM;
    /** AOA destination elevation FOM */
    uint8_t aoa_dest_elevation_FOM;
    /** Status to the slot number within the ranging round
     *  In time schedule mode, in case of a failure, this field indicates the slot number
     *  within the ranging round where the failure has occurred
     *  In contention-based ranging mode, this field can be used to indicate
     *  the slot selected by the controlee device.
     *  If the Slot Index field is not used, then it shall be set to 0. */
    uint8_t slot_index;
    /** Rssi  */
    uint8_t rssi;
    /** Distance in centimeters */
    uint16_t distance;
    /** AOA Azimuth */
    int16_t aoa_azimuth;
    /** AOA Elevation */
    int16_t aoa_elevation;
    /** AOA destination azimuth */
    int16_t aoa_dest_azimuth;
    /** AOA destination elevation */
    int16_t aoa_dest_elevation;
} phRangingMesr_t;

#if !(UWBIOT_UWBD_SR04X)
/**
 * @brief  Structure lists out the Vendor speicifc Rx Antenna Info for AoA Measurements
 */
typedef struct phRxInfoMesr
{
    /** RX mode */
    uint8_t rxMode;
    /** Number of RX antenna to follow */
    uint8_t num_of_rx_antennaRxInfo;
    /** RX antenna pair */
    uint8_t rx_antennaIdRxInfo[MAX_NUM_ANTENNA_PAIR];
} phRxInfoMesr_t;

/**
 * @brief  Structure lists out the Vendor speicifc Rx Antenna Info For Debug Notifications
 */
typedef struct phRxInfoDebugNtf
{
    union {
        /** If message control with b1 of octet[2] = 0 */
        /* RX mode */
        uint8_t rxModeDebugNtf;
        /** If message control with b1 of octet[2] = 1 */
        /* Number of Rframes for which the RX antenna info is reported*/
        uint8_t numOfRframes;
    };
    /** Number of RX antenna to follow */
    uint8_t num_of_rx_antennaDebugNtf;
    /** RX antenna pair */
    uint8_t rx_antennaIdDebugNtf[MAX_NUM_ANTENNA_PAIR];
} phRxInfoDebugNtf_t;

/**
 * @brief  Structure lists out the Vendor speicifc information for AoA / PDoA measurements per RX
 */
typedef struct phAoaPdoaMesr
{
    /** Angle of arrival */
    int16_t angleOfArrival;
    /** Phase difference of arrival */
    int16_t pdoa;
    /** Phase difference of arrival index in the whole CIR */
    uint16_t pdoaIndex;
#if UWBFTR_AoA_FoV
    /** This parameter indicates the presence or absence
     * of the peer device in FoV for user configured
     * Horizontal Rx Antenna Pair as defined in 'AZIMUTH_FIELD_OF_VIEW'
     * 0x00: Peer device is not present in FoV
     * 0x01: Peer device is present in FoV
     * This field would be displayed only when NXP Specific Data Type is 0xA0
     */
    uint8_t aoaFovFlag;
#endif // UWBFTR_AoA_FoV
} phAoaPdoaMesr_t;

/**
 * @brief  Structure lists out the Vendor speicifc Rx Antenna information SNRFirst / SNRMain /FirstIndex :
 *  Main Index measurements per RX entry
 */
typedef struct phSnrPathIndexMesr
{
    /** Signal-to-Noise (SNR) of the First Path in dB*/
    uint8_t rxSnrFirstPath;
    /** Signal-to-Noise (SNR) of the Main Path in dB */
    uint8_t rxSnrMainPath;
    /** First path index in the whole CIR */
    int16_t rx_FirstPathIndex;
    /** Main path index in the whole CIR */
    int16_t rx_MainPathIndex;
    /** SNR Total of configured RX in Q8.8 dB */
    int16_t snrTotal;
    /** Received Signal Strength Indicator of RX in dB */
    int16_t rssi;
} phSnrPathIndexMesr_t;

/**
 * @brief  Structure lists out the TWR Vendor speicifc measurements for each responder
 */
typedef struct phTwoWayRangingVsMesr
{
    /** AoA / PDoA measurements per RX */
    phAoaPdoaMesr_t aoaPdoaMesr_twr[MAX_NUM_ANTENNA_PAIR];
    /** SNRFirst / SNRMain / FirstIndex / Main Index measurements per RX */
    phSnrPathIndexMesr_t snrPathIndexMesr_twr[MAX_NUM_ANTENNA_PAIR];
    /** Range or distance between the device and target
     *  Set to 0 for Initiator: distance-2 is reported using the RFM
     *  pair on responder only in AOA_RFM mode */
    uint16_t distance_2;
    /** Distance between the device and target (resolution of 0.01 cm) */
    uint32_t distance_mm;
} phTwoWayRangingVsMesr_t;

/**
 * @brief  Structure lists out the Vendor speicifc information for TWR
 */
typedef struct phTwoWayRangingVsData
{
    /** Vendor Specific Data*/
    /** WiFi co-existence status*/
    uint8_t wifiCoExStatus;
    /** Tx Antenna Info */
    /** @note This field shall be shared only when TX_ANT_INFO_EN is enabled*/
    uint8_t txAntennaInfo;
    /** Rx Antenna Info for AoA Measurements*/
    phRxInfoMesr_t rxInfoMesr_twr;
    /** Rx Antenna Info For Debug Notifications*/
    phRxInfoDebugNtf_t rxInfoDebugNtf_twr;
    /** twr vs measurement for each responders  */
    phTwoWayRangingVsMesr_t vsMesr[MAX_NUM_RESPONDERS];
    /** Check if TX antenna info is present in message_control */
    bool isTxAntInfoPreset;
    /** Check if Distance_mm is present in message_control */
    bool isDistanceMmPresent;
    /** Check if Rx antenna Debug Info reported for all RFrames */
    bool isRxAntDebugInfoPresent;
} phTwoWayRangingVsData_t;

/**
 * @brief  Structure lists out the OWR Vendor speicifc measurements for each responder
 */
typedef struct phOneWayRangingVsMesr
{
    /** AoA / PDoA measurements per RX */
    phAoaPdoaMesr_t aoaPdoaMesr_owr[MAX_NUM_ANTENNA_PAIR];
    /** RSSI in dB **/
    int16_t rssi;
} phOneWayRangingVsMesr_t;

/**
 * @brief  Structure lists out the Vendor speicifc information for OWR
 */
typedef struct phOneWayRangingVsData
{
    /** Vendor Specific Data*/
    /** Rx Antenna Info for AoA Measurements*/
    phRxInfoMesr_t rxInfoMesr_owr;
    /** OWR vs measurment for each responders  */
    phOneWayRangingVsMesr_t vsMesr[MAX_NUM_OF_TDOA_MEASURES];
} phOneWayRangingVsData_t;

#endif // !(UWBIOT_UWBD_SR04X)

#if UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)
/**
 * @brief  Structure lists out the TDoA ranging measurement information for one way ranging.
 */
typedef struct phRangingMesrTdoa
{
    /** Mac address of the participating device,  addr can be
     * of short 2 byte or extended 8 byte modes */
    uint8_t mac_addr[UWB_EXTENDED_MAC_ADDRESS_LEN];
    /** Status */
    uint8_t status;
    /** This signifies the presence of Device ID, Rx and Tx timestamps */
    uint8_t message_control;
    /** Type of frame */
    uint8_t frame_type;
    /** Indicates if the ranging measurement was in Line of sight or
     * non-line of sight */
    uint8_t nLos;
    /** AOA Azimuth */
    int16_t aoa_azimuth;
    /** AOA Azimuth FOM */
    uint8_t aoa_azimuth_FOM;
    /** AOA elevation */
    int16_t aoa_elevation;
    /** AOA elevation FOM */
    uint8_t aoa_elevation_FOM;
    /** Number received in the Payload of the blink UTM from the UT-Tag
     *   or UTM from the UT-Synchronization Anchor. */
    uint32_t frame_number;
    /** Local RX timestamp of the received UWB RFRAME as measured by
     *  the device that is sending this SESSION_INFO_NTF. The unit is
     *  2^(-7) of the 499.2 MHz chipping period, which is
     *  approximately 15.65ps.  */
    uint8_t rx_timestamp[ULTDOA_64BIT_IN_BYTES];
    /** UL-TDoA Device ID of the sender of the received UTM as listed
     *  in the Blink UTM from the UT-Tag or the Synchronization UTM
     *  from the UT-Synchronization Anchor. */
    uint8_t ul_tdoa_device_id[ULTDOA_64BIT_IN_BYTES];
    /** TX timestamp of the UWB RFRAME as listed in the Blink UTM
     *  from the UT-Tag or the Synchronization UTM from UT-Synchronization
     *  Anchor. The unit is 2^(-7) of the 499.2 MHz chipping period,
     *   which is approximately 15.65ps. */
    uint8_t tx_timestamp[ULTDOA_64BIT_IN_BYTES];
} phRangingMesrTdoa_t;

/**
 * \brief  Structure lists out the Vendor speicifc information for tdoa
 */
typedef struct phTdoaRangingVsData
{
    /** Vendor Specific Data*/
    /** Vendor extension length for TDOA Measurements*/
    uint8_t vendorExtLength;
    /** RSSI RX1 */
    int16_t rssi_rx1;
    /** RSSI RX2 */
    int16_t rssi_rx2;
    /** No of pdoA measurement */
    uint8_t noOfPdoaMeasures;
    /** Estimation of phase difference for antenna pair N */
    int16_t pdoa[MAX_NUM_ANTENNA_PAIR];
    /** CIR Index estimate at which pdoa has been detected */
    uint16_t pdoaIndex[MAX_NUM_ANTENNA_PAIR];
#if UWBIOT_UWBD_SR2XXT
    /** Msg Control bitfiled for specific extensions
     *  If bit0 is 1 then it will be RX3 extensions, others RFU
     */
    uint16_t message_control_extension;
    /** Number of bytes for RX3 related extensions */
    uint8_t rx3_ext_info_len;
    /** RSSI RX3 */
    int16_t rssi_rx3;
#endif // UWBIOT_UWBD_SR2XXT
} phTdoaRangingVsData_t;
#endif // UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)

#if UWBFTR_DL_TDoA_Tag
/**
 * @brief  Structure lists out the TDoA ranging measurement information.
 */
typedef struct phRangingMesrDlTdoa
{
    /** MAC address */
    uint8_t mac_addr[UWB_EXTENDED_MAC_ADDRESS_LEN];
    /** Status */
    uint8_t status;
    /** Message type */
    uint8_t message_type;
    /** Message Control */
    uint16_t message_control;
    /** Block index */
    uint16_t block_index;
    /** Round index */
    uint8_t round_index;
    /** Nlos */
    uint8_t nLoS;
    /** AoA Azimuth */
    int16_t aoa_azimuth;
    /** AoA Azimuth FOM */
    uint8_t aoa_azimuth_fom;
    /** AoA Elevation */
    int16_t aoa_elevation;
    /** AoA Elevation FOM*/
    uint8_t aoa_elevation_fom;
    /** RSSI measured by DT-tag **/
    uint8_t rssi;
    /** Tx Timestamp */
    uint8_t tx_timestamp[MAX_RX_TX_TIMESTAMP];
    /**Rx Timestamp */
    uint8_t rx_timestamp[MAX_RX_TX_TIMESTAMP];
    /** CFO Anchor */
    int16_t cfo_anchor;
    /** Clock frequency offset */
    int16_t cfo;
    /** Reply time of initiator */
    uint32_t reply_time_initiator;
    /** Reply time of responder */
    uint32_t reply_time_responder;
    /** Initiator-Responder TOF */
    uint16_t initiator_responder_tof;
    /** Anchor Location */
    uint8_t anchor_location[MAX_ANCHOR_LOCATIONS];
    /** Active Ranging Rounds */
    uint8_t active_ranging_rounds[MAX_ACTIVE_RR];

} phRangingMesrDlTdoa_t;

/**
 * @brief  Structure lists out the TDoA ranging measurement information for V2.
 */
typedef struct phRangingMesrDlTdoaV2
{
    /**Measurement size */
    uint16_t measurement_size;
    /** MAC address */
    uint8_t mac_addr[EXT_MAC_ADDR_LEN];
    /** Status */
    uint8_t status;
    /** Message type */
    uint8_t message_type;
    /** Block index */
    uint16_t block_index;
    /** Round index */
    uint8_t round_index;
    /** Nlos */
    uint8_t nLoS;
    /** AoA Azimuth */
    int16_t aoa_azimuth;
    /** AoA Azimuth FOM */
    uint8_t aoa_azimuth_fom;
    /** AoA Elevation */
    int16_t aoa_elevation;
    /** AoA Elevation FOM*/
    uint8_t aoa_elevation_fom;
    /** RSSI measured by DT-tag **/
    uint8_t rssi;
    /** CFO Anchor */
    int16_t cfo_anchor;
    /** Clock frequency offset */
    int16_t cfo;
    /** Reply time of initiator */
    uint32_t reply_time_initiator;
    /** Reply time of responder */
    uint32_t reply_time_responder;
    /** Initiator-Responder TOF */
    uint16_t initiator_responder_tof;
    /** RX Timestamp Length */
    uint8_t rx_timestamp_length;
    /**Rx Timestamp */
    uint8_t rx_timestamp[MAX_RX_TX_TIMESTAMP];
    /** Message Control V2*/
    uint32_t message_control;
    /** TX Timestamp Length */
    uint8_t tx_timestamp_length;
    /** Tx Timestamp */
    uint8_t tx_timestamp[MAX_RX_TX_TIMESTAMP];
    /** Active Ranging Rounds Length */
    uint8_t active_ranging_rounds_length;
    /** Active Ranging Rounds V2*/
    uint8_t active_ranging_rounds[MAX_ACTIVE_RR_V2];
    /** Anchor Location Length */
    uint8_t anchor_location_length;
    /** Anchor Location V2*/
    uint8_t anchor_location[MAX_ANCHOR_LOCATIONS_V2];
    /** supercluster id */
    uint8_t supercluster_id;
} phRangingMesrDlTdoav2_t;

#endif // UWBFTR_DL_TDoA_Tag

#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
/**
 * @brief  Structure lists out the OWR with AoA ranging measurement information.
 */
typedef struct
{
    /** Mac address of the participating device,  addr can be
     * of short 2 byte or extended 8 byte modes */
    uint8_t mac_addr[8];
    /** Status */
    uint8_t status;
    /** Indicates if the ranging measurement was in Line of sight or
     * non-line of sight */
    uint8_t nLos;
    /** frame sequence number */
    uint8_t frame_seq_num;
    /** block index */
    uint16_t block_index;
    /** AOA Azimuth */
    int16_t aoa_azimuth;
    /** AOA Azimuth FOM */
    uint8_t aoa_azimuth_FOM;
    /** AOA Elevation */
    int16_t aoa_elevation;
    /** AOA elevation FOM */
    uint8_t aoa_elevation_FOM;
} phRangingMesrOwrAoa_t;
#endif //(UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
/**
 * @brief  Union for TWR ranging and TDoA ranging measurement information.
 */
typedef union {
    /** Ranging measurements array */
#if UWBFTR_TWR
    phRangingMesr_t range_meas_twr[MAX_NUM_RESPONDERS];
#endif // UWBFTR_TWR
#if UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)
    /** Ranging measurements TDoA array */
    /** One Way Ranging Ntf*/
    phRangingMesrTdoa_t range_meas_tdoa[MAX_NUM_OF_TDOA_MEASURES];
#endif // UWBFTR_UL_TDoA_Anchor && !(UWBIOT_UWBD_SR04X)
#if UWBFTR_DL_TDoA_Tag
    /** Ranging measurements DLTDoA array for V1 */
    phRangingMesrDlTdoa_t range_meas_dltdoa[MAX_NUM_OF_TDOA_MEASURES];
    /** Ranging measurements DLTDoA array for V2 */
    phRangingMesrDlTdoav2_t range_meas_dltdoa_v2[MAX_NUM_OF_TDOA_MEASURES];
#endif // UWBFTR_DL_TDoA_Tag
#if (UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
    /** Ranging measurements OWR with AoA */
    phRangingMesrOwrAoa_t range_meas_owr_aoa[MAX_NUM_OWR_AOA_MEASURES];
#endif //(UWBIOT_UWBD_SR100T || UWBIOT_UWBD_SR200T)
} RANGING_MEAS;

#if !(UWBIOT_UWBD_SR04X)
/**
 * @brief  Union for vendor specific information of TWR ranging and TDoA ranging.
 */
typedef union {
    /** Ranging measurements array */
#if UWBFTR_TWR
    phTwoWayRangingVsData_t twr;
#endif // UWBFTR_TWR
#if !(UWBIOT_UWBD_SR04X)
    /** One Way Ranging Ntf*/
    phOneWayRangingVsData_t owr_aoa;
#endif // !(UWBIOT_UWBD_SR04X)
#if UWBFTR_UL_TDoA_Anchor
    /** One Way Ranging TDoA Ntf*/
    phTdoaRangingVsData_t tdoa;
#endif // UWBFTR_UL_TDoA_Anchor
} VENDORSPECIFIC_MEAS;
#endif // !(UWBIOT_UWBD_SR04X)

/**
 * @brief  Structure lists out the ranging notification information.
 */
typedef struct phRangingData
{
    /** RCR Indication */
    uint8_t rcr_indication;
    /** Ranging Measurement Type
     * - 0x00 = One-Way Ranging Measurement (OWR)
     * - 0x01 = Two-Way Ranging Measurement (SS-TWR, DS-TWR)
     * - 0x02 = DL-TDoA Ranging Measurement v1 (OWR DL-TDOA)
     * - 0x03 = OWR for AoA Measurement
     * - 0x04 = Reserved for CCC
     * - 0x05 = Reserved for CCC
     * - 0x06 = DL-TDoA Ranging Measurement_ Vv2 (OWR DL-TDoA)
     * - 0x07-0xFF = RFU
     * \note OWR for AoA Measurement is allowed when RANGING_ROUND_USAGE is set to “OWR for AoA Measurement” and DEVICE_ROLE is set to “Observer”
     */
    uint8_t ranging_measure_type;
    /** Mac addr mode indicator,
     *
     * - 0: short 2 byte,
     * - 1: extended 8 byte mode */
    uint8_t mac_addr_mode_indicator;
    /** Number of ranging measurements */
    uint8_t no_of_measurements;
#if UWBIOT_UWBD_SR04X
    /**vendor length */
    uint16_t vs_length;
    /* Antenna Configuration information in current ranging round */
    uint8_t antenna_info;
    /** Rssi */
    uint8_t rssi;
#endif // UWBIOT_UWBD_SR04X
    /** keep track of the notifications */
    uint32_t seq_ctr;
    /** Session Handle of the ranging round */
    uint32_t sessionHandle;
    /** Current ranging interval setting in milli seconds */
    uint32_t curr_range_interval;
    /** Session Handle of Primary Session  */
    uint32_t sessionHandle_of_primary_session;
    /** Ranging measures array */
    RANGING_MEAS ranging_meas;
#if (!(UWBIOT_UWBD_SR04X))
    /** Vendor specific data type */
    uint8_t vs_data_type;
    /** Vendor specific data Length*/
    uint16_t vs_length;
    /** Vendor specific data*/
    VENDORSPECIFIC_MEAS vs_data;
    /** Message control */
    /* Octet [1-0] Indicates the fields in the fixed part
    *   - 0b0 - Parameter TX_ANTENNA_INFO not present
    *   - 0b1 - Parameter TX_ANTENNA_INFO present
    *   - b15-b1: RFU
    *
    *   Octet [3-2] Indicates the fields in the variable part
    *   - b0: Millimeter Distance Report
    *       - 0b0 - Parameter Distance_mm not present
    *       - 0b1 - Parameter Distance_mm present
    *       Based on NXP_UWB_FEATURE_CONFIG Bit[0]
    *   - b1: Rx Antenna Debug Info reported for all RFrames
    *       - 0b0 - Rx Antenna Debug Info Not reported for all Rframes
    *       - 0b1 - Rx Antenna Debug Info reported for all Rframes(if ALIRO_CONTROLEE_EXTENSIONS = 0x01 (Enable)) or Aliro Session Type
    *   - b15-b2: RFU
    **/
    uint32_t message_control;
#endif // (!(UWBIOT_UWBD_SR04X))
#if ((UWBFTR_UL_TDoA_Anchor || UWBFTR_DL_TDoA_Tag) && !(UWBIOT_UWBD_SR04X))
    /** Status code for WLAN during ranging RR*/
    uint8_t wifiCoExStatusCode;
    /** Antenna Rx Configuration information used in current ranging round*/
    uint32_t antenna_pairInfo;
#endif //((UWBFTR_UL_TDoA_Anchor || UWBFTR_DL_TDoA_Tag) && !(UWBIOT_UWBD_SR04X))
#if (!(UWBIOT_UWBD_SR04X))
    /** Indicator for presence of Authentication Tag*/
    uint8_t authInfoPrsen;
    /**Authentication Tag*/
    uint8_t authenticationTag[AUTH_TAG_IN_16BYTES];
#endif //(!(UWBIOT_UWBD_SR04X))
} phRangingData_t;

#define phNewRoleChangeNtf_t uwb_session_role_change_ntf_t

#if UWBFTR_CCC || UWBFTR_CSA

/**
 * @brief  Structure lists out the PDoA Measurements for CCC/CSA Range Data Ntf .
 */
typedef struct phCccPdoaMeasurements
{
    /** Estimation of phase difference in degrees from antenna pair [1…N] */
    int16_t pdoa;
    /** CIR index estimate at which PDoA [1…N] has been detected */
    uint16_t pdoaIndex;
} phCccPdoaMeasurements_t, phCsaPdoaMeasurements_t;

/**
 * @brief  Structure lists out the Antenna Pair Info for CCC/CSA Range Data Ntf .
 */
typedef struct antenna_pair_info
{
    /** Antenna Rx Configuration information used in current ranging round */

    /** Configuration Mode as per ANTENNAS_CONFIGURATION_RX
     *  supported configuration modes are 0 ,1, 5 and 6
     *  0 : Configuration Mode 0: ToF Only Mode
     *  1 : Configuration Mode 1: Configuration Mode for 3D/2D AoA, test/loopback session and implicit ToA mode usecase
     *  5 : Configuration Mode 5: Configuration Mode for CSA ToA mode use case
     *  6 : Configuration Mode 6: Configuration Mode for CSA AoA mode use case
     *
     */
    uint8_t configMode;
    /**
     * Config mode(s) 0:
     *    Antenna ID 1 as per ANTENNA_RX_IDX_DEFINE
     * Config mode(s) 1:
     *    Antenna Pair ID as per ANTENNAS_RX_PAIR_DEFINE
     * Config mode(s) 5:
     *    Antenna ID as per ANTENNA_RX_IDX_DEFINE mapped to current active RR
     * Config mode(s) 6:
     *    Antenna Pair ID as per ANTENNAS_RX_PAIR_DEFINE mapped to current active RR
     */
    uint8_t antPairId1;
    /**
     * Config mode(s) 0:
     *    Antenna ID 2 as per ANTENNA_RX_IDX_DEFINE
     * Config mode(s) 1:
     *    Antenna Pair ID as per ANTENNAS_RX_PAIR_DEFINE
     * Config mode(s) 5:
     *    Antenna ID as per ANTENNA_RX_IDX_DEFINE mapped to current active RR
     * Config mode(s) 6:
     *    Antenna Pair ID as per ANTENNAS_RX_PAIR_DEFINE mapped to current active RR
     */
    uint8_t antPairId2;
    /** RFU */
    uint8_t rfu;

} phCccAntennaPairInfo_t, phCsaAntennaPairInfo_t;

/**
 * @brief  Structure lists out the RSSI Measurements for CCC/CSA Range Data Ntf .
 ** Helios1 (N=2 and M=2):
    * {
    * RSSI_RX1 -2 Octets
    * RSSI_RX2 -2 Octets
    * } Repeat the same for FINAL frame
    *
    * Helios2 (N=2 and M=3):
    * {
    * RSSI_RX1 -2 Octets
    * RSSI_RX2 -2 Octets
    * RSSI_RX3 -2 Octets
    * } – Repeat the same for FINAL frame
    *
 */
typedef struct rssiMeasurements
{
    /** RSSI Measurement from RX1
     * It is signed value expressed in Q8.8 format
     */
    int16_t rssi_rx1;
    /** RSSI Measurement from RX2
     * It is signed value expressed in Q8.8 format
     */
    int16_t rssi_rx2;
#if UWBIOT_UWBD_SR250
    /** RSSI Measurement from RX3
     * It is signed value expressed in Q8.8 format
     */
    int16_t rssi_rx3;
#endif //UWBIOT_UWBD_SR250
} phCccRssiMeasurements_t, phCsaRssiMeasurements_t;

/**
 * \brief  Structure lists out the SNR Measurements for CCC/CSA Range Data Ntf .
 */
typedef struct snrMeasurements
{
    /** Slot index and Antenna mapping details
     *  bits[5:0] - RFRAME slot index
     *  bits[7:6] for H1
     *  bit[6] - RFU
     *  bit[7] - 0: RX1, 1: RX2 for H1
     *  bits[7:6] : For H2
     *  - 0b00: RXC
     *  - 0b01: RXB
     *  - 0b10: RFU
     *  - 0b11: RXA
     */
    uint8_t slotIndexAndAntennaMap;
    /** Signal-to-Noise Ratio (SNR) of the First path and it is reported as unsigned value in dB*/
    uint8_t snrFirstPath;
    /** Signal-to-Noise Ratio (SNR) of the main path and it is reported as unsigned value in dB*/
    uint8_t snrMainPath;
    /** Signal-to-Noise Ratio (SNR) of configured RX*/
    uint16_t snrTotal;
} phCccSnrMeasurements_t, phCsaSnrMeasurements_t;

/**
 * \brief  Structure lists out the CCC ranging notification information.
 */
typedef struct phCccRangingData
{
    /** Session Handle of the CCC ranging round */
    uint32_t sessionHandle;
    /** Ranging Status of the CCC Session, refer eCccRangingStatus */
    uint8_t rangingStatus;
    /** STS Index */
    uint32_t stsIndex;
    /** Ranging Round Index */
    uint16_t rangingRoundIndex;
    /** Distance between Initiator and Anchor in cm */
    uint16_t distance;
    /** Ranging timestamp uncertainty of controllee */
    uint8_t uncertanityAnchorFom;
    /** Ranging timestamp uncertainty of controller */
    uint8_t uncertanityInitiatorFom;
    /** CCM Tag  */
    uint8_t ccmTag[MAX_CCM_TAG_SIZE];
    /** AOA Azimuth */
    int16_t aoa_azimuth;
    /** AOA Azimuth FOM */
    uint8_t aoa_azimuth_FOM;
    /** AOA Elevation */
    int16_t aoa_elevation;
    /** AOA elevation FOM */
    uint8_t aoa_elevation_FOM;
    /** Antenna Pair Info */
    phCccAntennaPairInfo_t antenna_pair_info;
    /** Number of PDoA Measurements */
    uint8_t noOfPdoaMeasures;
    /** PDoA Measurements */
    phCccPdoaMeasurements_t pdoaMeasurements[MAX_NO_OF_PDOA_MEASUREMENTS];
    /** Number of RFrames used for RSSI measurements
     * This field shall be set 0 when SWAP_ANTENNA_PAIR_3D_AOA parameter is set to 0x00
     */
    uint8_t noOfRssiMeasurements;
    /** RSSI Measurements */
    phCccRssiMeasurements_t rssiMeasurements[MAX_NO_OF_CCC_RSSI_MEASUREMENTS];
    /** Number of SNR Measurements
     * This field shall be set 0 and SNR Measurement field will not be present.
     */
    uint8_t noOfSnrMeasurements;
    /** SNR Measurements */
    phCccSnrMeasurements_t snrMeasurements[MAX_NO_OF_CCC_SNR_MEASUREMENTS];
} phCccRangingData_t;

/**
 * \brief  Structure lists out the CSA ranging notification information.
 */
typedef struct phCsaRangingData
{
    /** Session Handle of the CSA ranging round */
    uint32_t sessionHandle;
    /** Ranging Status of the CSA Session, refer eCccRangingStatus */
    uint8_t rangingStatus;
    /** STS Index */
    uint32_t stsIndex;
    /** Ranging Round Index */
    uint16_t rangingRoundIndex;
    /** Index of the Ranging block for which the following measurement result applies */
    uint16_t blockIndex;
    /** Distance between Initiator and Anchor in cm */
    uint16_t distance;
    /** Ranging timestamp uncertainty of controlee */
    uint8_t uncertanityAnchorFom;
    /** Ranging timestamp uncertainty of controller */
    uint8_t uncertanityInitiatorFom;
    /** CCM Tag  */
    uint8_t ccmTag[MAX_CCM_TAG_SIZE];
    /** AOA Azimuth */
    int16_t aoa_azimuth;
    /** AOA Azimuth FOM */
    uint8_t aoa_azimuth_FOM;
    /** AOA Elevation */
    int16_t aoa_elevation;
    /** AOA elevation FOM */
    uint8_t aoa_elevation_FOM;
    /** Antenna Pair Info */
    phCsaAntennaPairInfo_t antenna_pair_info;
    /** Number of PDoA Measurements */
    uint8_t noOfPdoaMeasures;
    /** PDoA Measurements */
    phCsaPdoaMeasurements_t pdoaMeasurements[MAX_NO_OF_PDOA_MEASUREMENTS];
    /** Number of RFrames used for RSSI measurements
     * This field shall be set 0 when SWAP_ANTENNA_PAIR_3D_AOA parameter is set to 0x00
     */
    uint8_t noOfRssiMeasurements;
    /** RSSI Measurements */
    /* Received Signal Strength Indicator (RSSI) is 2 Octet value in dB.
    * It is signed value expressed in Q8.8 format.
    * Where N is the number RSSI measurements.
    * Each measurement is reported in the sequence according to antenna pair in Antenna Pair Info field.
    * Where M is the number receivers used to receive Rframes (POLL and FINAL).
    *
    * HELIOS1:
    * For example:
    * With SWAP_ANTENNA_PAIR_3D_AOA enabled
    * RSSI-RX1| RSSI-RX2 for Pair 1 for POLL
    * RSSI-RX1| RSSI-RX2 for Pair 2 for FINAL
    * With SWAP_ANTENNA_PAIR_3D_AOA disabled
    *
    * For RX Pair RSSI-RX1| RSSI-RX2 for Pair 1 for POLL
    * RSSI-RX1| RSSI-RX2 for Pair 1 for FINAL
    * For single RX RSSI-RX1 for RX1, RSSI-RX2 will be 0, for POLL and
    * FINAL.
    * RSSI-RX2 for RX2, RSSI-RX1 will be 0, for POLL and
    * FINAL
*
    * HELIOS2:
    * Example:
    * RSSI_RX1|RSSI_RX2|RSSI_RX3 for POLL
    * RSSI_RX1|RSSI_RX2|RSSI_RX3 for FINAL

    */
    phCsaRssiMeasurements_t rssiMeasurements[MAX_NO_OF_CSA_RSSI_MEASUREMENTS];
    /** Number of SNR Measurements
     * This field shall be set 0 and SNR Measurement field will not be present.
     */
    uint8_t noOfSnrMeasurements;
    /** SNR Measurements */
    phCsaSnrMeasurements_t snrMeasurements[MAX_NO_OF_CSA_SNR_MEASUREMENTS];
} phCsaRangingData_t;

/**
 * @brief  enum lists out the CCC ranging notification information status.
 * For the CCC session, the lower nibble represents the ranging status of the controller and the higher nibble
 * represents the ranging status of the controlee. For other sessions, this contains only the status of the controllee.
 */
typedef enum cccRangingStatus
{
    CCC_STATUS_SUCCESS          = 0x0, /* Success */
    CCC_STATUS_TRANSACTION_OVFL = 0x1, /* Transaction overflow */
    CCC_STATUS_TRANSACTION_EXPD = 0x2, /* Transaction expired */
    CCC_STATUS_INCORRECT_FRAME  = 0x3, /* Incorrect frame */
    CCC_STATUS_RESP_LISTEN      = 0xD, /* Responder is in listen only mode (Not available for the controller) */
    CCC_STATUS_CTRL_MSG_LOST    = 0xF, /* Ranging Control Message lost (Not available for the controller) */

} eCccRangingStatus;

/**
 * @brief  Enumerator lists out the Hop modes for CCC Controller.
 *
 * @note This config is applicable only for Controller and ignored in case of Controlee.
 */
typedef enum
{
    /* No Hopping */
    kUWB_CCC_HopMode_Disable = 0x00,
    /* Continuous Hopping mode with AES-based hopping sequence */
    kUWB_CCC_HopMode_Cont_AES = 0xA0,
    /* Continuous hopping mode with default hopping sequence */
    kUWB_CCC_HopMode_Cont_def = 0xA1,
    /* Adaptive hopping mode with AES based hopping sequence. */
    kUWB_CCC_HopMode_Adapt_AES = 0xA2,
    /* Adaptive Hopping mode with default hopping sequence. */
    kUWB_CCC_HopMode_Adapt_def = 0xA3,
    /* NXP Adaptive Hopping mode. */
    kUWB_NXP_HopMode_Adapt = 0xA4,
} eCCC_HopModes_t;

/**
 * @brief Structure lists out the CCC Mandatory App Configs.
 */
typedef struct
{
    /** Device Type, 0x00: Controlee, 0x01: Controller, 0x02: Advertiser, 0x03: Observer */
    uint8_t deviceType;
    /** Number of Controlees(N), 1<=N<=8
     * (Default is 1)
     */
    uint8_t noOfControlees;
    /** This parameter is used to choose responder index in two way ranging.
     * @note It is not applicable to controller.
     */
    uint8_t responderSlotIndex;
    /** Unsigned integer that specifies duration of a ranging slot in the unit of RSTU  */
    uint16_t slotDuration;
    /** This parameter is used to enable/disable the hopping.
     * @ref eCCC_HopModes_t
     */
    uint8_t hoppingMode;
} phCccRangingParams_t;
#endif // UWBFTR_CCC

/**
 * @brief  Structure lists out the mandatory configurations to be set for
 * ranging.
 */
typedef struct phRangingParams
{
    /** Device Role
     *
     * - kUWB_DeviceRole_Responder      = 0,
     * - kUWB_DeviceRole_Initiator      = 1,
     * - kUWB_DeviceRole_UT_Sync_Anchor = 2,
     * - kUWB_DeviceRole_UT_Anchor      = 3,
     * - kUWB_DeviceRole_UT_Tag         = 4,
     * - kUWB_DeviceRole_Advertiser     = 5,
     * - kUWB_DeviceRole_Observer       = 6,
     * - kUWB_DeviceRole_DlTDoA_Anchor  = 7,
     * - kUWB_DeviceRole_DlTDoA_Tag     = 8,
     */
    uint8_t deviceRole;
    /** Multi Node Mode,
     *
     * - 0x00: O2O(One to one),
     * - 0x01: O2M(One to Many),
     * - 0x02 - 0xFF: Reserved */
    uint8_t multiNodeMode;
    /** Device Mac Address mode 0:2 bytes,1:8 bytes mac addr with
     * 2 bytes in header, 2: 8 bytes in mac addr and header */
    uint8_t macAddrMode;
    /** Device Mac Address, 2 bytes or 8 bytes
     * addr is supported. */
    uint8_t deviceMacAddr[UWB_EXTENDED_MAC_ADDRESS_LEN];
    /** Device Type
     *
     * - 0x00: Controlee
     * - 0x01: Controller
     * - 0x02: Advertiser
     * - 0x03: Observer
     */
    uint8_t deviceType;
    /** Ranging Round Usage */
    uint8_t rangingRoundUsage;
    /** Scheduled Mode */
    uint8_t scheduledMode;
} phRangingParams_t;

/**
 * @brief  Structure lists out the preamble pulse shape config
 */
typedef struct phTxTelecConfig
{
    /** Preamble pulse shape id */
    uint8_t shape_id;
    /** Payload tx pulse shape id */
    uint8_t payload_tx_shape_id;
    /** STS Tx pulse shape id */
    uint8_t sts_shape_id;
    /** DAC Stage config */
    uint8_t dac_stage_cofig;
} phTxPulseShapeConfig_t;

#if (UWBFTR_BlobParser)
/**
 * @brief  Structure lists out the configurations to be get from
 *  Accessory Config Data.
 */
typedef struct AccessoryConfigDataContent
{
    /** Total length */
    uint8_t length;
    /** Specification Major version */
    uint8_t uwb_spec_ver_major[MAX_SPEC_VER_LEN];
    /** Specification Minor version */
    uint8_t uwb_spec_ver_minor[MAX_SPEC_VER_LEN];
    /** Manufacture id for device specific*/
    uint8_t manufacturer_id[4];
    /** Model id for device specific*/
    uint8_t model_id[4];
    /** MW  version*/
    uint8_t mw_version[4];
    /** Device Role */
    uint8_t ranging_role;
    /** Source mac address*/
    uint8_t device_mac_addr[SHORT_MAC_ADDR_LEN];
    /** CLock frequency drift value */
    uint8_t clock_drift[2];
} AccessoryUwbConfigDataContent_t;

/**
 * @brief Structure lists our the configurations
 * to be loaded on the device sent from the phone counterpart
 */
typedef struct UwbPhoneConfigData
{
    uint8_t spec_ver_major[MAX_SPEC_VER_LEN];
    uint8_t spec_ver_minor[MAX_SPEC_VER_LEN];
    uint32_t session_id;
    uint8_t preamble_id;
    uint8_t channel_number;
    uint8_t config_id;
    uint8_t device_ranging_role;
    uint8_t phone_mac_address[SHORT_MAC_ADDR_LEN];
#if (UWBIOT_UWBD_SR04X)
    uint8_t ranging_tech;
    uint8_t payload_size;
    uint16_t ranging_interval;
    uint8_t slot_duration;
    uint8_t session_key_len;
    uint8_t session_key[RANGING_SESSION_KEY_LEN_32];
    uint8_t country_code[SHORT_MAC_ADDR_LEN];
    uint8_t device_mode;
    bool isFindhubEnabled;
#endif //UWBIOT_UWBD_SR04X
} UwbPhoneConfigData_t;

/**
 * @brief  Structure lists out the configurations to be get from
 *  Accessory Config Data.
 */
typedef struct UwbDeviceConfigData
{
    /** Specification Major version */
    uint8_t spec_ver_major[2];
    /** Specification Minor version */
    uint8_t spec_ver_minor[2];
    /** UWB Chip identifier */
    uint8_t chip_id[2];
    /** UWB Chip firmware version */
    uint8_t chip_fw_version[2];
    /** MW  version*/
    uint8_t mw_version[3];
    /** Range of supported profiles by the device */
    uint32_t supported_config_ids;
    /** Device Role */
    uint8_t ranging_role;
    /** Source mac address*/
    uint8_t device_mac_addr[SHORT_MAC_ADDR_LEN];
#if (UWBIOT_UWBD_SR04X)
    /** Ranging Technology */
    uint8_t ranging_technology_role;
    /** Payload size */
    uint8_t payload_size;
    /** supported channels */
    uint32_t supported_channels;
    /** preamble index */
    uint32_t preamble_index;
    /** ranging_interval */
    uint16_t ranging_interval;
    /** slot_duration */
    uint8_t slot_duration;
    /** input param to identify findhub flow or legacy flow */
    bool isFindhubEnabled;
#endif /* (UWBIOT_UWBD_SR04X) */
} UwbDeviceConfigData_t;

/**
 * @brief  Structure lists out the mandatory configurations to be set for
 *  User Accessory Config Data.
 */
typedef struct UserAccessoryConfigData_iOS
{
    uint8_t customerSpecMajorVer[2];
    uint8_t customerSpecMinorVer[2];
    uint8_t preferedUpdateRate;
    uint8_t RFU[10];
    AccessoryUwbConfigDataContent_t UwbConfigData;
} UserAccessoryConfigData_iOS_t;

/**
 * @brief  Enumeration lists out the Vendor specific Profile ID
 */
typedef enum UWB_ProfileID
{
    kUWB_Profile_1 = 0x0B,

} eUWB_ProfileID_t;

/**
 * @brief Structure lists out Profile information.
 */
typedef struct phUwbProfileInfo
{
    /** Session Handle is out param */
    uint32_t sessionHandle;
    /** Source mac address*/
    uint8_t mac_addr[SHORT_MAC_ADDR_LEN];
    /** Profile ID */
    eUWB_ProfileID_t profileId;
    /** Device Role
     *
     * - 0x00: Responder
     * - 0x01: Initiator
     * - 0x02: Master Anchor */
    uint8_t deviceRole;
    /** Device Type, 0x00: Controlee, 0x01: Controller */
    uint8_t deviceType;

} phUwbProfileInfo_t;

#endif // UWBFTR_BlobParser

#if UWBFTR_DataTransfer
/**
 * @brief  Structure lists out the data control transmit notification.
 */
typedef struct phDataTransmit
{
    /** Connection ID
     * If the msb of MSB is 0b1, then the connectionId indicates a sessionHandle
     * If the msb of MSB is 0b0, then the connectionId indicates a LL_Connect_Id.
     */
    uint32_t transmitNtf_connectionId;
    /** Sequence number */
#if (UWBIOT_UWBD_SR04X)
    uint8_t transmitNtf_sequence_number;
#else
    uint16_t transmitNtf_sequence_number;
#endif /* (UWBIOT_UWBD_SR04X) */
    /** Status */
    uint8_t transmitNtf_status;
#if UWBIOT_UWBD_SR1XXT_SR2XXT
    /** Tx count*/
    uint8_t transmitNtf_txcount;
#endif // UWBIOT_UWBD_SR1XXT_SR2XXT
} phUwbDataTransmit_t;

#define phUwbDataCredit_t uwb_data_credit_notification_t
#endif // UWBFTR_DataTransfer

#if UWBFTR_Radar
/**
 * @brief  Structure lists out the Radar Cir notification.
 */
typedef struct phUwbRadarcirNtf
{
    /** Num of Cirs  */
    uint16_t num_cirs;
    /** Cir Taps  */
    uint8_t cir_taps;
    /** Rfu */
    uint8_t rfu;
    /** Length of the Cir */
    uint16_t cir_len;
    /** Cir data */
    uint8_t *cirdata;
} phUwbRadarcirNtf_t;

/**
 * @brief  Structure lists out the Test Radar Antenna Isolation.
 */
typedef struct phUwbRadarTestIsoNtf
{
    /** Tx Antenna select */
    uint8_t antenna_tx;
    /** Rx Antenna select */
    uint8_t antenna_rx;
    /** Radar type */
    uint16_t anteena_isolation;
} phUwbRadarTestIsoNtf_t;

/**
 * @brief  Structure lists out the Test Radar Presence detection.
 */
typedef struct phUwbRadarPresenceDetectNtf
{
    /**A boolean value indicating whether a presence has been detected */
    bool presence_detected;
    /** Representing the presence detection mode. */
    uint8_t presence_detection_mode;
    /** Representing the number of detections N (max. 5). */
    uint8_t number_of_detections;
    /** Distance of detection in cm, else set to 0xFFFF */
    uint16_t detection_distance[MAX_NUMBER_OF_PRESENCE_DETECTIONS]; // TAP[1]
    /** AoA of detection as signed degree (int8_t format) if a second receiver is configured, else set to 0xFF */
    int8_t detection_aoa[MAX_NUMBER_OF_PRESENCE_DETECTIONS]; // TAP[1]
    /** Track ID for each target (previously RFU) */
    uint8_t detection_track_id[MAX_NUMBER_OF_PRESENCE_DETECTIONS]; // TAP[1]
    /** value (threshold), set to 0xFFFFFFFF if not set */
    uint32_t detection_value[MAX_NUMBER_OF_PRESENCE_DETECTIONS]; // TAP[2]
} phUwbRadarPresenceDetectNtf_t;

/**
 * @brief  Union for Radar and Anteena isolation measurement information.
 */
typedef union {
    /** Radar CIR notification Structure */
    phUwbRadarcirNtf_t radr_cir;
    /** Radar CIR Antenna test isolation Structure */
    phUwbRadarTestIsoNtf_t radar_tst_ntf;
    /** Radar Presence detection notificaiton Structure */
    phUwbRadarPresenceDetectNtf_t radar_presence_detect_ntf;
} RADAR_MEAS;

/**
 * @brief  Structure lists out the Radar notificaiton.
 */
typedef struct phUwbRadarNtf
{
    /** Session Handle */
    uint32_t sessionHandle;
    /** Status of the radar*/
    uint8_t radar_status;
    /** Radar type */
    uint8_t radar_type;
    /** Radar measures */
    RADAR_MEAS radar_ntf;
} phUwbRadarNtf_t;

#endif // UWBFTR_Radar

/**
 * @brief  Enumeration lists out the chip specific type used.
 */
typedef enum
{
    kChipType_NA    = 0x00,
    kChipType_SR150 = 0x01,
    kChipType_SR040 = 0x02,
    kChipType_SR250 = 0x03
    /* TODO: SR048 Needs an update? */
} demo_chip_type_t;

/**
 * @brief  Enumeration lists out the board specific type used.
 */
typedef enum
{
    kBoardType_NA       = 0x00,
    kBoardType_Shield   = 0x01,
    kBoardType_FinderV3 = 0x02,
    kBoardType_Virgo    = 0x03
} demo_board_type_t;

/**
 * @brief  Enumeration lists out the Preferred specific rate type used.
 */
typedef enum
{
    kUpdateRate_Automatic       = 0,
    kUpdateRate_Infrequent      = 10,
    kUpdateRate_UserInteractive = 20
} PreferedUpdateRate_t;

#define MODELID_RFU 0x00 // RFU
#define CLOCK_DRIFT 100

/**
 * @brief  Enumeration lists out the channel numbers used.
 */
typedef enum UWB_ChannelNumber
{
    kUWB_ChannelNumber_5 = 5,
    kUWB_ChannelNumber_6 = 6,
    kUWB_ChannelNumber_8 = 8,
    kUWB_ChannelNumber_9 = 9,
} UWB_ChannelNumber_t;

/**
 * @brief  Enumeration lists out the MAC FCS type used.
 */
typedef enum UWB_MacFcsType
{
    kUWB_MacFcsType_CRC16 = 0,
    kUWB_MacFcsType_CRC32 = 1,
} UWB_MacFcsType_t;

/**
 * @brief  Enumeration lists out the SFD ID's used.
 */
typedef enum UWB_SfdId
{
    kUWB_SfdId_BPRF_0 = 0, // BPRF
    kUWB_SfdId_BPRF_2 = 2, // BPRF
    kUWB_SfdId_HPRF_1 = 1, // HPRF
    kUWB_SfdId_HPRF_2 = 2, // HPRF
    kUWB_SfdId_HPRF_3 = 3, // HPRF
} UWB_SfdId_t;

/**
 * @brief  Enumeration lists out the Preamble Index codes used.
 */
typedef enum UWB_PreambleIndxCode
{
    kUWB_PreambleIndxCode_BPRF_09 = 9, // [9.. 12] BPRF
    kUWB_PreambleIndxCode_BPRF_10 = 10,
    kUWB_PreambleIndxCode_BPRF_11 = 11,
    kUWB_PreambleIndxCode_BPRF_12 = 12,
    kUWB_PreambleIndxCode_HPRF_25 = 25, // [25.. 32] HPRF
    kUWB_PreambleIndxCode_HPRF_26 = 26,
    kUWB_PreambleIndxCode_HPRF_27 = 27,
    kUWB_PreambleIndxCode_HPRF_28 = 28,
    kUWB_PreambleIndxCode_HPRF_29 = 29,
    kUWB_PreambleIndxCode_HPRF_30 = 30,
    kUWB_PreambleIndxCode_HPRF_31 = 31,
    kUWB_PreambleIndxCode_HPRF_32 = 32,
} UWB_PreambleIndxCode_t;

/**
 * @brief  Enumeration lists out the Preamble duration used.
 */
typedef enum UWB_PreambleDuration
{
    kUWB_PreambleDuration_32Symbols = 0, // Both BPRF and HPRF
    kUWB_PreambleDuration_64Symbols = 1, // BPRF Only
} UWB_PreambleDuration_t;

/**
 * @brief  Enumeration lists out the Ranging Data Notifications used.
 */
typedef enum UWB_Session_InfoNtf
{
    kUWB_DisableSession_Info_Ntf                           = 0x00,
    kUWB_EnableSession_Info_Ntf                            = 0x01,
    kUWB_SessionInfo_Ntf_Proximity                         = 0x02,
    kUWB_SessionInfo_Ntf_AOABounds                         = 0x03,
    kUWB_SessionInfo_Ntf_AOABounds_n_Proximity             = 0x04,
    kUWB_SessionInfo_Ntf_Enter_Leave_Proximity             = 0x05,
    kUWB_SessionInfo_Ntf_Enter_Leave_AOABounds             = 0x06,
    kUWB_SessionInfo_Ntf_Enter_Leave_AOABounds_n_Proximity = 0x07,

} UWB_Session_InfoNtf_t;

/**
 * @brief  Enumeration lists out the PRF modes used.
 */
typedef enum UWB_PrfMode
{
    /** BPRF */
    kUWB_PrfMode_62_4MHz = 0,
    /** HPRF */
    kUWB_PrfMode_124_8MHz = 1,
    /** HPRF mode with data rate 27.2 and 31.2 Mbps */
    kUWB_PrfMode_249_6MHz = 2
} UWB_PrfMode_t;

/**
 * @brief  Enumeration lists out the PSDU data rates used.
 */
typedef enum UWB_PsduDataRate
{
    kUWB_PsduDataRate_6_81Mbps = 0,
    kUWB_PsduDataRate_7_80Mbps = 1,
    kUWB_PsduDataRate_27_2Mbps = 2,
    kUWB_PsduDataRate_31_2Mbps = 3,
    kUWB_PsduDataRate_850Kbps  = 4
} UWB_PsduDataRate_t;

/**
 * @brief  Enumeration lists out the RFrame Config sts values.
 */
typedef enum UWB_RfFrameConfig
{
    kUWB_RfFrameConfig_No_Sts               = 0,
    kUWB_RfFrameConfig_SP0                  = kUWB_RfFrameConfig_No_Sts,
    kUWB_RfFrameConfig_Sfd_Sts              = 1,
    kUWB_RfFrameConfig_SP1                  = kUWB_RfFrameConfig_Sfd_Sts,
    kUWB_RfFrameConfig_Psdu_Sts             = 2,
    kUWB_RfFrameConfig_Sfd_Sts_NoPhr_NoPsdu = 3,
    kUWB_RfFrameConfig_SP3                  = kUWB_RfFrameConfig_Sfd_Sts_NoPhr_NoPsdu,
} UWB_RfFrameConfig_t;

/**
 * @brief  Enumeration lists out the Device role values.
 */
typedef enum
{
    kUWB_DeviceRole_Responder      = kUwb_DeviceRole_Responder,
    kUWB_DeviceRole_Initiator      = kUwb_DeviceRole_Initiator,
    kUWB_DeviceRole_UT_Sync_Anchor = kUwb_DeviceRole_UT_Sync_Anchor,
    kUWB_DeviceRole_UT_Anchor      = kUwb_DeviceRole_UT_Anchor,
    kUWB_DeviceRole_UT_Tag         = kUwb_DeviceRole_UT_Tag,
    kUWB_DeviceRole_Advertiser     = kUwb_DeviceRole_Advertiser,
    kUWB_DeviceRole_Observer       = kUwb_DeviceRole_Observer,
    kUWB_DeviceRole_DlTDoA_Anchor  = kUwb_DeviceRole_DlTDoA_Anchor,
    kUWB_DeviceRole_DlTDoA_Tag     = kUwb_DeviceRole_DlTDoA_Tag,
} UWB_DeviceRole_t;

/**
 * @brief  Enumeration lists out the Multicast mode values.
 */
typedef enum UWB_MultiNodeMode
{
    kUWB_MultiNodeMode_UniCast    = kUwb_MultiNodeMode_UniCast,
    kUWB_MultiNodeMode_OnetoMany  = kUwb_MultiNodeMode_OnetoMany,
    kUWB_MultiNodeMode_ManytoMany = kUwb_MultiNodeMode_ManytoMany,
} UWB_MultiNodeMode_t;

/**
 * @brief  Enumeration lists out the Device type values.
 */
typedef enum UWB_DeviceType
{
    kUWB_DeviceType_Controlee      = 0x00,
    kUWB_DeviceType_Controller     = 0x01,
    kUWB_DeviceType_CCC_Controller = 0xA0, /* CCC Controller(Device) */
    kUWB_DeviceType_CCC_Controlee  = 0xA1, /* CCC Controlee(Vehicle) */
} UWB_DeviceType_t;

/**
 * @brief  Enumeration lists out the Ranging Round Usage values.
 */
typedef enum UWB_RangingRoundUsage
{
    /* One Way Ranging UL-TDoA */
    kUWB_RangingRoundUsage_TDoA = 0,
    /* SS-TWR with Deferred Mode */
    kUWB_RangingRoundUsage_SS_TWR = 1,
    /* DS-TWR with Deferred Mode */
    kUWB_RangingRoundUsage_DS_TWR = 2,
    /* SS-TWR with Non-deferred Mode*/
    kUWB_RangingRoundUsage_SS_TWR_nd = 3,
    /* Double Sided TWR Non Deferred*/
    kUWB_RangingRoundUsage_DS_TWR_nd = 4,
    /* One Way Ranging DL-TDOA*/
    kUWB_RangingRoundUsage_DL_TDOA = 5,
    /* OWR for AoA Measurement*/
    kUWB_RangingRoundUsage_OWR_AOA = 6,
    /* eSS-TWR with Non-deferred Mode for Contention-based ranging*/
    kUWB_RangingRoundUsage_eSS_TWR = 7,
    /* aDS-TWR for Contention-based ranging*/
    kUWB_RangingRoundUsage_aDS_TWR = 8,
    /* Data transfer mode*/
    kUWB_RangingRoundUsage_DTx = 9,
    /* Hybrid Ranging mode*/
    kUWB_RangingRoundUsage_HUS = 10,

} UWB_RangingRoundUsage_t;

/**
 * @brief  Enumeration lists out the Radar TX Pulse Shape IDs.
 *
 * Valid pulse shapes are restricted by firmware.
 * Any value outside this enum will be rejected.
 */
typedef enum UWB_Radar_PulseShape
{
    kUWB_Radar_PulseShape_41 = 41U,  /*!< Pulse Shape 41 */
    kUWB_Radar_PulseShape_50 = 50U,  /*!< Pulse Shape 50 */
    kUWB_Radar_PulseShape_65 = 65U,  /*!< Pulse Shape 65 */
} UWB_Radar_PulseShape_t;

typedef UWB_RangingRoundUsage_t UWB_RangingMethod_t;

#define kUWB_RangingMethod_TDoA      kUWB_RangingRoundUsage_TDoA
#define kUWB_RangingMethod_SS_TWR    kUWB_RangingRoundUsage_SS_TWR
#define kUWB_RangingMethod_DS_TWR    kUWB_RangingRoundUsage_DS_TWR
#define kUWB_RangingMethod_SS_TWR_ND kUWB_RangingRoundUsage_SS_TWR_nd
#define kUWB_RangingMethod_DS_TWR_ND kUWB_RangingRoundUsage_DS_TWR_nd
#define kUWB_RangingMethod_HUS       kUWB_RangingRoundUsage_HUS

/**
 *  @brief Enumeration lists out the AOA_RESULT_REQ values.
 */
typedef enum UWB_AOA_Result_Req
{
    kUWB_AOA_Result_Req_Disable   = 0,
    kUWB_AOA_Result_Req_Enable    = 1,
    kUWB_AOA_Result_Req_Azimuth   = 2,
    kUWB_AOA_Result_Req_Elevation = 3,

} UWB_AOA_Result_Req_t;

/**
 * @brief  Enumeration lists out the scheduled Mode values.
 */
typedef enum UWB_ScheduledMode
{
    /** Contention based Ranging Scheduling */
    kUWB_ScheduledMode_ContentionBased = kUwb_ScheduledMode_ContentionBased,
    /** Time based Ranging Scheduling */
    kUWB_ScheduledMode_TimeScheduled = kUwb_ScheduledMode_TimeScheduled,
    /** Hybrid based Scheduling */
    kUWB_ScheduledMode_HybridBased = kUwb_ScheduledMode_HybridBased,
} UWB_ScheduledMode_t;

/**
 * @brief  Enumeration lists out the Radar Mode values.
 *
 * - 0x01: Medium distance, e.g. used for vital sign detection;
 * - 0x02: Close distance, e.g. used for hand gesture recognition
 * - 0x03: Far distance, e.g. used for presence detection
 * - 0x04 - RFU
 * - 0x05: Medium distance,   e.g. used for static object support
 * - 0x06: Far distance, e.g. used for static object support
 */
typedef enum UWB_RadarMode
{
    kUWB_RadarMode_Medium_Distance        = 1,
    kUWB_RadarMode_Close_Distance         = 2,
    kUWB_RadarMode_Far_Distance           = 3,
    kUWB_RadarMode_Static_Medium_Distance = 5,
    kUWB_RadarMode_Static_Far_Distance    = 6,
    kUWB_RadarMode_Test_Isolation         = 0x20
} UWB_RadarMode_t;

/**
 * @brief  Enumeration lists out the control values of PhaseList.
 *
 * b0 : MAC addressing mode of the Controller of the Phase
 * b1 : Phase type
 */
typedef enum UWB_MacAddPhaseTypeCtrl
{
    kUWB_CtrlShortMacAdressAndPhaseCfp = 0x00,
    kUWB_CtrlExtMacAdressAndPhaseCfp   = 0x01,
    kUWB_CtrlShortMacAdressAndPhaseCap = 0x02,
    kUWB_CtrlExtMacAdressAndPhaseCap   = 0x03,
} UWB_MacAddPhaseTypeCtrl_t;

/** @brief Enumeration to Set the Slot Bitmap
 *
 * - [b3-b1]
 *  - 0 = 8 ranging slots
 *  - 1 = 16 ranging slots
 *  - 2 = 32 ranging slots
 *  - 3 = 64 ranging slots
 *  - 4 = 128 ranging slots
 *  - 5 = 256 ranging slots
 *  - 6-7 = RFU
 */
typedef enum phSlotBitmap
{
    ranging_slots_8   = 0x00,
    ranging_slots_16  = 0x02,
    ranging_slots_32  = 0x04,
    ranging_slots_64  = 0x06,
    ranging_slots_128 = 0x08,
    ranging_slots_256 = 0x0A,
    /* RFU */
} phSlotBitmap_t;

#define phDataTxPhaseCfgNtf_t uwb_data_transfer_phase_config_ntf_t

/**
 * @brief  Generic callback function registered by Application to receive data
 * from middleware. This is a common callback for All session types
 *             1. Ranging
 *             2. App Data Transfer
 *             3. PER Exchange
 *             4. Generic Error Notification
 *             5. Device Reset Notification
 *             6. RFrame Data Notification
 *             7. Recovery Notification
 *             8. Scheduler status Notification
 *
 *             This data is provided by the stack, to the user.  The user should
 *             implement this callback if user wants to receive the NTF
 *             information.
 *
 *             - If the callback function pointer
 *             is NULL, the user will not receive the notifications.
 *
 * \param opType  Type of Notification
 * \param pData   Data received
 * \param len     Data length
 */
typedef void(tUwbApi_AppCallback)(eNotificationType opType, void *pData, size_t len);

/**
 * @brief TML callback function registered by Application to receive data packet from UWB
 * If the callback function pointer is NULL, the user will not receive the data packet from TML.
 *
 * \param recvData       pointer to received data
 * \param recvDataLen    len of data received
 */
typedef void(tUwbApi_TMLDataCallback)(const uint8_t *const packet, const uint32_t packet_len);

/**
 * @brief  Structure lists out the UWB-IoT init context
 */
typedef struct phUwbappContext
{
    /** Standalone mode callback function */
    uwb_uci_callback_t *pCallback;
    /** Application specific callback function*/
    tUwbApi_TMLDataCallback *pTmlCallback;
    /** FW Image context */
    phUwbFWImageContext_t fwImageCtx;
} phUwbappContext_t;

/**
 * @brief  Structure lists out the Generic Error notification
 */
typedef struct phGenericError
{
    /** Status */
    uint8_t status;
} phGenericError_t;

#define phUwbSessionInfo_t uwb_session_status_notification_t

/**
 * \brief Structure for storing Blink Data Tx Ntf Context.
 */
typedef struct phBlinkDataTxNtfContext
{
    /** Repetition Count Status */
    uint8_t repetition_count_status;
} phBlinkDataTxNtfContext_t;

/**
 * @brief Structure for storing Data Control Transmit Ntf Context.
 */
typedef struct phDataControlTransmitNtfContext
{
    /** Session Handle */
    uint32_t sessionHandle;
    /** Status */
    uint8_t status;

} phDataControlTransmitNtfContext_t;

#if UWBFTR_DataTransfer


/**
 * \brief Enumerator lists out the types of Logical Link Modes
*/
typedef enum
{
    kUwb_ProprietarySecure = 0xB0,
    kUwb_ProprietarySecureUWBS = 0xB1,
} eSelectLogicalLinkModes_t;

/** Connection Oriented Modes */
#define IS_DATA_TRANSFER_CONNECTION_ORIENTED(llmSelector)                                                   \
    ((llmSelector == kUwb_ConnectionOrientedNonSecure) || (llmSelector == kUwb_ConnectionOrientedSecure) || \
        (llmSelector == kUwb_ConnectionOrientedUWBS))

/** Connection Less Modes */
#define IS_DATA_TRANSFER_CONNECTION_LESS(llmSelector)                                               \
    ((llmSelector == kUwb_ConnectionLessNonSecure) || (llmSelector == kUwb_ConnectionLessSecure) || \
        (llmSelector == kUwb_ConnectionLessUWBS))

#define phLogicalLinkCreateNtf_t uwb_logical_link_create_ntf_t

#define phLogicalLinkUwbsCreateNtf_t uwb_logical_link_uwbs_create_ntf_t

#define phLogicalLinkUwbsCloseNtf_t uwb_logical_link_uwbs_close_ntf_t

#define phLogicalLinkDataPkt_t uwb_ll_data_receive_notification_t

/**
 * @brief Enumeration Lists out the Logical Link create status codes
 */
typedef enum
{
    /* Link with specified parameters accepted. */
    LOGICAL_LINK_ACCEPTED = 0X00,
    /* Link could not be established for given parameters. */
    LOGICAL_LINK_REJECTED = 0X01,
    /* CO Link with remote device established successfully. */
    LOGICAL_CO_LINK_CONNECTED = 0X02,
    /* link creation with remote device unsuccessful. */
    LOGICAL_LINK_ERROR = 0X03,
} eLlCreate_StatusCodes_t;

/**
 * @brief Enumeration Lists out the Logical Link Close Status Codes.
 */
typedef enum
{
    /* Remote device terminated logical link (CO logical Link only). */
    kUWB_LlRemoteTerm = 0x00,
    /* Logical link was inactive longer then link time out. */
    kUWB_LlTimeOut = 0x01,
    /* Logical link termination because of unrecoverable errors. */
    kUWB_LlTransmissionError = 0x02,
    /* Logical link termination by Secure component. */
    kUWB_LlTermSE = 0x03,
    /* Logical Link termination due to unknown reason */
    kUWB_LlTermUnknown = 0x04,
    /* Logical Link Teminated by Host */
    kUWB_LlHostTerm = 0x05,
    /** Received SDU exceeds LL Unit max SDU capabilities. */
    kUWB_LlRxSduTooLarge = 0x06,

} eLlClose_statusCodes_t;
#endif // UWBFTR_DataTransfer

/**
 * @brief Enumeration lists out the capability device type values.
 */
typedef enum
{
    /** FiRa Controller */
    kUWB_CapsDeviceType_Controller = 0x01,
    /** FiRa Controlee */
    kUWB_CapsDeviceType_Controlee = 0x02,
    /** CCC Controller */
    kUWB_CapsDeviceType_CCC_Controller = 0x04,
    /** CCC Controlee */
    kUWB_CapsDeviceType_CCC_Controlee = 0x08,
    /** Aliro User */
    kUWB_CapsDeviceType_Aliro_User = 0x10,
    /** Aliro Reader */
    kUWB_CapsDeviceType_Aliro_Reader = 0x20,
} eUwb_CapsDeviceType_t;

/**
 * @brief  Structure lists out the UWB Device Info Parameters.
 *
 */
typedef struct phUwbCapInfo
{
    /** FIRA phy lower range major version */
    uint8_t firaPhyLowerRangeMajorVersion;
    /** FIRA phy lower range minor maintenance version */
    uint8_t firaPhyLowerRangeMinorMaintenanceVersion;
    /** FIRA phy higher range major version */
    uint8_t firaPhyHigherRangeMajorVersion;
    /** FIRA phy higher range minor maintenance version */
    uint8_t firaPhyHigherRangeMinorMaintenanceVersion;
    /** FIRA mac lower range major version */
    uint8_t firaMacLowerRangeMajorVersion;
    /** FIRA mac lower range minor maintenance version */
    uint8_t firaMacLowerRangeMinorMaintenanceVersion;
    /** FIRA mac higher range major version */
    uint8_t firaMacHigherRangeMajorVersion;
    /** FIRA mac higher range minor maintenance version */
    uint8_t firaMacHigherRangeMinorMaintenanceVersion;
    /** Device types
     * - b0 = FiRa Controller
     * - b1 = FiRa Controlee
     * - b2 = CCC Controller
     * - b3 = CCC Controlee
     * - b4 = Aliro User Device
     * - b5 = Aliro Reader
     * - b6-b7 = RFU
     * \ref eUwb_CapsDeviceType_t
    */
    uint8_t deviceTypes;
    /** Device roles */
    uint16_t deviceRoles;
    /** Ranging Method
     *
     * - b0: TDoA
     * - b1: SS-TWR with Deferred Mode
     * - b2: DS-TWR with Deferred Mode
     * - b3: SS-TWR with Non-Deferred Mode
     * - b4: DS-TWR with Non-Deferred Mode
     * - b5: OWR DL-TDoA
     * - b6: OWR for AoA Measurement
     * - b7: eSS-TWR with non-deferred mode for contention-based ranging.
     * - b8: aDS-TWR for contention-based ranging.
     * - b9: Data transfer mode.
     * - b10: Reserved for CCC
     * - b11: Aliro deferred DS-TWR.
     * - b15-b24: RFU
     */
    uint16_t rangingMethod;
    /** STS config */
    uint8_t stsConfig;
    /** Multinode mode */
    uint8_t multiNodeMode;
    /** Ranging time struct */
    uint8_t rangingTimeStruct;
    /** Scheduled mode */
    uint8_t scheduledMode;
    /** Hopping mode */
    uint8_t hoppingMode;
    /** Block striding */
    uint8_t blockStriding;
    /** UWB initiation time */
    uint8_t uwbInitiationTime;
    /** FIRA phy ver range */
    uint8_t channels;
    /** RFRAME config */
    uint8_t rframeConfig;
    /** CC constraint length */
    uint8_t ccConstraintLength;
    /** BPRF parameter sets */
    uint8_t bprfParameterSets;
    /** HPRF parameter sets */
    uint8_t hprfParameterSets[DEVICE_CAPABILITY_LEN_5];
    /** AOA support */
    uint8_t aoaSupport;
    /** Extended mac address */
    uint8_t extendedMacAddress;
    /* Suspend Ranging */
    uint8_t suspendRanging;
    /* Session Key Len */
    uint8_t sessionKeyLen;
    /* Achor Max Active RR */
    uint8_t ancorMaxRrActive;
    /* TAG Max Active RR */
    uint8_t tagMaxRrActive;
    /** Max message size */
    uint16_t maxMessageSize;
    /** Max data packet payload size */
    uint16_t maxDataPacketPayloadSize;
#if !(UWBIOT_UWBD_SR04X)
    /** Slot bitmask */
    uint8_t slotBitmask;
    /** Sync code index bitmask */
    uint32_t syncCodeIndexBitmask;
    /** Hopping config bitmask */
    uint8_t hoppingConfigBitmask;
    /** Channel bitmask */
    uint8_t channelBitmask;
    /**Num of Protocol version supported */
    uint8_t numSupportedProtocolVersions;
    /** Supported protocol version */
    uint16_t supportedProtocolVersions[NUM_SUPPORTED_PROTOCOL_VERSIONS];
    /**Num of supported UWB config Ids */
    uint8_t numSupportedUWBConfigIDs;
    /** Supported UWB config ID */
    uint16_t supportedUWBConfigIDs[NUM_SUPPORTED_UWB_CONFIG_ID];
    /** Supported pulse shape combo */
    uint8_t supportedPulseShapeCombo[DEVICE_CAPABILITY_LEN_9];
    /** Minimum RAN multiplier supported */
    uint8_t minRanMultiplier;
    /** Maximum UCI payload size that can handle by UWBS */
    uint16_t maxUciPayloadLength;
    /** Data buffer block size in bytes which the UWBS manages
     *  for the overall in-band data transfer memory pool.
     */
    uint8_t inbandDataBlockSize;
    /** Parameter to indicate the number of blocks available
     *  in the overall in-band data transfer memory pool.
     */
    uint8_t inbandDataMaxBlock;
#endif // !(UWBIOT_UWBD_SR04X)
#if !(UWBIOT_UWBD_SR040)
    /* Indicates the block skipping capability for DT-Tag */
    uint8_t tagBlockSkipping;
    /* Indicates the supported PSDU Length */
    uint8_t psduLengthSupport;
#endif /* UWBIOT_UWBD_SR040 */

    /** Logical Link Capability Param.
     * b0 = LL feature support
     *      0: Not supported
     *      1: Supported
     * Below bits shall be ignored if LL feature support is set to 0.
     * b1 = LL Aggregated Frame support
     * b2 = Secure Endpoint support
     * b3 = Non-Secure Endpoint support
     * b7-b4 = RFU
     *      0: Not supported
     *      1: Supported
     * b11-b8: Maximum number of Logical Links supported in UWBS.
     * b15-b12:  Maximum number of Logical Links support per session
     *
     */
    uint16_t llCapabilityParam;
    /** Bypass Mode support
     * 0x00 = Bypass mode not supported
     * 0x01 = Bypass mode supported
     */
    uint8_t bypassModeSupport;
    /** FiRa Link Layer version supported by the UWBS.
    * Bits 4-7: encodes Major version
    * Bits 0-3: encodes Minor version
    */
    uint8_t firaLlVersion;
    /** Min slot duration supported by the UWBS
     * Unsigned integer in the unit of RSTU
     */
    uint16_t minSlotDurationSupport;
#if UWBFTR_CSA
    /** Support of MAC modes
      * - b0 = 1 active Ranging Round in Ranging Block
      * - b1 = 2 active Ranging Rounds in Ranging Block
      * - b7-b2 = RFU
     */
    uint8_t aliroSupportedMacMode;
    /**Num of Aliro Protocol version supported */
    uint8_t numAliroSupportedProtocolVersions;
    /** lists a supported protocol version where the fields of the protocol versions are 2 bytes long.
     * Protocol version as defined in the Aliro specification is 0x0100.
     * If another future protocol version 0x0101 would be supported, response has to be: 0x0100, 0x0101.
     * Aliro Specification Version 1.0 is coded as 0x0100
     */
    uint16_t aliroSupportedProtocolVersion[NUM_SUPPORTED_ALIRO_PROTOCOL_VERSIONS];
#endif /* UWBFTR_CSA */
} phUwbCapInfo_t;

#if UWBFTR_UWBS_DEBUG_Dump
/**
 * @brief  Structure lists out the RFRAME Log Notification Parameters.
 *
 */
typedef struct phUwbRframeLogNtf
{
    uint8_t mapping;
    uint8_t decodeStatus;
    uint8_t nLos;
    uint16_t firstPathIndex;
    uint16_t mainpathIndex;
    uint8_t snrMainPath;
    uint8_t snrFirstPath;
    uint16_t snrTotal;
    uint16_t rssi;
    uint32_t cirMainPwr;
    uint32_t cirFirstPathPwr;
    uint16_t noiseVariance;
    uint16_t cfo;
    uint16_t aoaPhase;
    uint8_t cirSamples[64];

} phUwbRframeLogNtf_t;
#endif // UWBFTR_UWBS_DEBUG_Dump

/** @} */ /* @addtogroup Uwb_Types */

#ifndef UWB_BOARD_ENABLE_FW_DOWNLOAD_ON_UWBINIT
#error UWB_BOARD_ENABLE_FW_DOWNLOAD_ON_UWBINIT must be defined by uwb_board.h
#endif // UWB_BOARD_ENABLE_FW_DOWNLOAD_ON_UWBINIT

/* TODO: status code for Duplicate session no longer exists, adding to support backward compatibility */
#define UWBAPI_STATUS_SESSION_DUPLICATE 0x12

/* TODO: End of Backward Compatibility */

#endif // UWBAPI_TYPES_H
