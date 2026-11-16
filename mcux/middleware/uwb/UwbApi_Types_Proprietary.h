/*
 * Copyright 2018-2020,2022-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UWBAPI_TYPES_PROPRIETARY_SRXXX_H
#define UWBAPI_TYPES_PROPRIETARY_SRXXX_H

#include "UwbApi_Types.h"
#include "zephyr/uwb/types.h"

/** \addtogroup uwb_apis_srxxx
 *
 * APIs for SR100 and SR150
 *
 * @{ */

/**  UWBS response timeout*/
#define UWB_MAX_DEV_MGMT_RSP_TIMEOUT (2000 + 500)
/* DPD Timeout Range */
/**  Minimum timeout Supported by UWBS */
#define UWBD_DPD_TIMEOUT_MIN 100
/**  Maximum timeout Supported by UWBS */
#define UWBD_DPD_TIMEOUT_MAX 5000
/**  Maximum length of version Supported by UWBS */
#define UWBD_VERSION_LENGTH_MAX 0x3
/* UWB Generate Tag command related length fields */
#define UWB_TAG_CMAC_LENGTH 0x10U
/**  UWBS MAX UCI packet size */
#define UWBS_MAX_UCI_PACKET_SIZE 2048
/**  HOST MAX UCI packet size */
#define HOST_MAX_UCI_PACKET_SIZE 2048
/**  MIN DEVICE packet size */
#define MIN_DEVICE_PACKET_SIZE 255
/**  EXTENDED PARAM ID MASK */
#define EXTENDED_PARAM_ID_MASK 0xF0
/** CCC PARAM ID */
#define CCC_INFO_ID 0xA0
/** MAX UCI CCC Version Length */
#define MAX_UCI_CCC_VERSION_LEN 2
/** MAX CCC Version Length */
#define MAX_CCC_VERSION_LEN 8
/** MAX Aliro Spec Version */
#define MAX_ALIRO_SPEC_VERSION_LEN 8
/**  MODULE MAKER ID MAX SIZE */
#define MODULE_MAKER_ID_MAX_SIZE    2
#define MODULE_MAKER_ID_MAX_SIZE_FW 8
/** MAX SESSION ID LIST */
#define MAX_SESSION_ID_LIST 0x08

/** MAX UWB CHID ID Length */
#define MAX_UWB_CHIP_ID_LEN 16
/** MAX UWBS PPM VALUE Length */
#define MAX_PPM_VALUE_LEN 1
/** MAX TX Power Lenght*/
#define MAX_TX_POWER_LEN 2
/** MAX FW BOOT Length*/
#define FW_BOOT_MODE_LEN 1

/** MAX CAL Mode Length */
#define MAX_CAL_MODE_LEN 4
/** FW GIT Hash Length*/
#define FW_GIT_HASH_LEN 17

/* Session ID (4 octets) || Random (12 octets) || Wrapped RDS from SE (Maximum 40 octets) */
#define RANDOM_KEY_LEN  12
#define SESSION_KEY_LEN 40
#define WRAPPED_RDS_LEN (SESSION_ID_LEN + RANDOM_KEY_LEN + SESSION_KEY_LEN)
/** Max RDS List Size */
#define MAX_RDS_LIST_SIZE 5
#define MAX_SCHED_NTF_REPORTS 25

#define CHIP_CALIBRATION_POS          0x0001
#define TX_POWER_POS                  0x0002
#define XTAL_CAP_VALUES_POS           0x0004
#define RSSI_CONSTANT1_POS            0x0008
#define RSSI_CONSTANT2_POS            0x0010
#define TX_POWER_PARAMS_POS           0x0040
#define PAPPPA_CALIB_CTRL_POS         0x0100
#define TX_TEMP_COMP_POS              0x0200
#define DELAY_CALIB_POS               0x0B00
#define PDOA_MFG_OFFSET_POS           0x1000
#define PDOA_AOA_ANT_MULTIPOINT_CALIB 0x2000

/**
 * @brief antenna selection gpio bit mask
 *
 */

/** Antenna selection gpio bit mask for EF1 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_EF1_MASK 1
/** Antenna selection gpio bit mask for EF2 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_EF2_MASK 2
/** Antenna selection gpio bit mask for GPIO6 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_GPIO6_MASK 4
/** Antenna selection gpio bit mask for GPIO7 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_GPIO7_MASK 8
/** Antenna selection gpio bit mask for GPIO9 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_GPIO9_MASK 16
/** Antenna selection gpio bit mask for GPIO10 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_GPIO10_MASK 32
/** Antenna selection gpio bit mask for GPIO11 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_GPIO11_MASK 64
/** Antenna selection gpio bit mask for GPIO14 */
#define UWB_ANTENNA_SELECTION_GPIO_BIT_GPIO14_MASK 128

#if UWBIOT_UWBD_SR1XXT
/** MAX RFRAME Measurements */
#define MAX_RFRAME_MEAS 2
#elif UWBIOT_UWBD_SR2XXT
/** MAX RFRAME Measurements */
#define MAX_RFRAME_MEAS 3
#endif // UWBIOT_UWBD_SR2XXT

#if UWBFTR_UWBS_DEBUG_Dump
/**  MAX RFRAME packet size */
#define MAX_RFRAME_PACKET_SIZE (sizeof(phUwbRframeLogNtf_t) * MAX_RFRAME_MEAS * MAX_NUM_RESPONDERS)
#endif // UWBFTR_UWBS_DEBUG_Dump

#if UWBIOT_UWBD_SR150
#define MODELID_BOARD_TYPE kBoardType_Shield
#define MODELID_CHIP_TYPE  kChipType_SR150
#elif UWBIOT_UWBD_SR250
#define MODELID_BOARD_TYPE kBoardType_Virgo
#define MODELID_CHIP_TYPE  kChipType_SR250
#endif // UWBIOT_UWBD_SR150

/* Deprecated. Following Set app parmas specific defines are changed,
 * use above defines, defined here for backward compatibility
 */
#define kAPPPARAMS_Type_Unknown kUWB_APPPARAMS_Type_Unknown
#define kAPPPARAMS_Type_u32     kUWB_APPPARAMS_Type_u32
#define kAPPPARAMS_Type_au8     kUWB_APPPARAMS_Type_au8
// Backward compatibility macro for CSA Mac Mode
#define CSA_MAC_MODE ALIRO_MAC_MODE
#if (UWBFTR_DL_TDoA_Anchor || UWBFTR_DL_TDoA_Tag)
typedef struct phActiveRoundsConfig
{
    /** Active Round Index */
    uint8_t roundIndex;
    /** Device role within the given round index. See \ref UWB_DeviceRole_t */
    uint8_t rangingRole;
    /** Number M of Responder MAC Addresses, Possible values are between 1 to 8.*/
    uint8_t noofResponders;
    /** Responder MAC Address List for the specified ranging round as Initiator DT-Anchor.*/
    uint8_t *responderMacAddressList;
    /** Responder slot presence
     * - Possible values are:
     *  - 0x00: implicit scheduling, i.e., responder slots are not present;
     *  - 0x01: responder slots are present; therefore, M octets shall follow, specifying the assigned slot for each
     * Responder DT-Anchor. 0x02-0xFF: RFU
     */
    uint8_t responderSlotScheduling;
    /** Responder slot index assigned for responder transmissions */
    uint8_t *responderSlots;

} phActiveRoundsConfig_t;

typedef struct {
    /** No of index */
    uint8_t noOfIndex;
    /** Index list */
    uint8_t indexList[MAX_NO_OF_ACTIVE_RANGING_ROUND];
} phNotActivatedRounds_t;
#endif //(UWBFTR_DL_TDoA_Anchor || UWBFTR_DL_TDoA_Tag)
/* End of deprecated defines */

/**
 * Enumerated values for Secured Element Binding Status
 */
typedef enum phBindingStatus
{
    /** Binding status*/
    /** 0x00: Not Bound,*/
    BindingStatus_NotBound = 0x00,
    /** 0x01: Bound Unlocked,*/
    BindingStatus_BoundUnlocked = 0x01,
    /** 0x02: Bound Locked,*/
    BindingStatus_BoundLocked = 0x02,
    /** 0x03: Unknown ( if any error occurred during getting binding state from SE) */
    BindingStatus_Unknown = 0x03,
    /** (0x04-0xFF : RFU)*/
} ephBindingStatus;

/**
 *  @brief OTP Read Write Options.
 */
typedef enum otpRWOption
{
    /* bit 0 set to 1b : Calibration Parameter */
    CALIB_PARAM = 0x01,
#if 0
    /* bit 1 set to 1b : Calibration Parameter bit mask value */
    BIT_MASK_VALUE = 0x02,
    /* bit 2 set to 1b : CMAC Tag */
    CMAC_TAG = 0x04
#endif
    /* Bit 2 - 7 : RFU */
} otpRWOption;

/**
 *  @brief Calib params payload.
 */
typedef struct phCalibPayload
{
    /** CHIP CALIBRATION code **/
    uint16_t CHIP_CALIBRATION;
    /** Tx power Id **/
    uint8_t TX_POWER_ID[4];
    /** XTAL cap values. It Can be set only once.
     * Channel independent and remains same for each channel.
     * - Octet [0]: 38.4 MHz XTAL CAP1
     * - Octet [1]: 38.4 MHz XTAL CAP2
     * - Octet [2]: 38.4 MHz XTAL GM CURRNT CONTROL
     *
     * - Values : [0x00-0xFF] for Octet[1:0]
     * - Values : [0x00-0x3F] for Octet[2]
     **/
    uint8_t XTAL_CAP_VALUES[3];
    /** RSSI CONSTANT1(4*2). this parameter is channel and antenna pair dependent.
     * - Channel number to be provide in calibration commands to set this parameter.
     * - 4 antenna pairs with 2 RX each
     * - 2 RX: RX1 and RX2
     **/
    uint8_t RSSI_CONSTANT1[8];
    /** RSSI CONSTANT2(4*2). this parameter is channel and antenna pair dependent.
     * - Channel number to be provide in calibration commands to set this parameter.
     * - 4 antenna pairs with 2 RX each
     * - 2 RX: RX1 and RX2
     **/
    uint8_t RSSI_CONSTANT2[8];
    /** Tx power parameters (4*4)
     * 4 Antenna pairs
     * 4 parameters for each antenna pairs
     * - Octet[0]: PA_GAIN
     * - Octet[1]: PA_DRIVE_GAIN
     * - Octet[2]: DIG_GAIN
     * - Octet[3]: TX_DAC_GAIN
     **/
    uint8_t TX_POWER_PARAMS[16];
#if UWBIOT_UWBD_SR1XXT
    /** PA output capacitor control **/
    uint16_t PA_PPA_CALIB_CTRL;
#endif // UWBIOT_UWBD_SR1XXT
    /** Tx tempreature comp. This parameter is dependent on the chosen channel and Tx antenna. (2*4*2):
     * - 2 bytes value description
     *  - Octet [0]:TX_POWER_TEMP_UPPER_BOUND
     *  - Octet [1]:TX_POWER_GAIN_INDEX
     * - 4 bytes: 2 Octets repeated 4 times to allow up to 4 different temperature ranges
     *  - Octet[1-0]: Temperature range 1 and gain index
     *  - Octet[3-2]: Temperature range 2  and gain index
     *  - Octet[5-4]: Temperature range 3 and gain index
     *  - Octet[7-6]: Temperature range 4 and gain index
     * - 2 bytes: Number of Tx antenna selection options
     **/
    uint8_t TX_TEMP_COMP[16];
    /** Delay calibration. It Can be set only once. Same value will be applied for all channels **/
    uint16_t DELAY_CALIB_VALUE;
    /* First 2 byte corresponds to RX Antenna pair
       ID 1 and next 2 bytes corresponds to RX
       Antenna pair ID 2.*/
    uint8_t PDOA_MFG_0_OFFSET_CALIB[4];
    /* ( Each multipoint size
        is 4b and 2 points are supported per pair
        = 4b each mulipoint vlaue * 2 points *2 RX
        antenna pairs = 16)
        Nomenclature to be followed by host to store
        and retreive is
        First 8 bytes ( 4b multipoint-1 + 4b multipoi
        nt-2) corresponds RX Antenna pair ID 1 and
        next 8 bytes ( 4b multipoint-1 + 4b multipoi
        nt-2) corresponds to RX Antenna pair ID 2*/
    uint8_t AOA_ANT_MULTIPOINT_CALIB[16];

} phCalibPayload_t;

/**
 *  @brief SetApp Configuration parameters supported in UWB API layer.
 */
typedef enum appConfig
{
    /** Devce Type
     * - 0x00 = Controlee
     * - 0x01 = Controller
     */
    /* UWB Prefix added to avoid potential redefinition with platform macros. */
    UWB_DEVICE_TYPE = 0x00,
    /** Ranging Round Usage
     * - 0x00 = One Way Ranging UL-TDoA
     * - 0x01 = SS-TWR with Deferred Mode
     * - 0x02 = DS-TWR with Deferred Mode
     * - 0x03 = SS-TWR with Non-deferred Mode
     * - 0x04 = DS-TWR with Non-deferred Mode
     * - 0x05 = One Way Ranging DL-TDOA
     * - 0x06 = OWR for AoA Measurement
     * - 0x07 = eSS-TWR with Non-deferred Mode for Contention-based ranging
     * - 0x08 = aDS-TWR for Contention-based ranging
     * - 0x09 = Data Transfer Mode
     */
    RANGING_ROUND_USAGE = 0x01,
    /** STS Config
     * - 0x00:Static STS
     * - 0x01:Dynamic STS
     * - 0x02:Dynamic STS for controlee individual key
     * - 0x03:Provisioned STS
     * - 0x04:Provisioned STS for Responder specific Sub-session Key
     * - 0xA0:To be set at Anchor and User device to distinguish the transition from Static STS to Dynamic STS
     * - 0x05 to 0xFF except 0xA0 : RFU
     */
    STS_CONFIG,
    /** Multi Node Mode
     * - 0x00 = O2O (One to one)
     * - 0x01 = O2M (One to many)
     * Values 0x02 to 0xFF = RFU
     */
    MULTI_NODE_MODE = 0x03,
    /** Possible values are {5, 6, 8, 9, 10, 12, 13, 14}
     * (default = 9)
     */
    CHANNEL_NUMBER = 0x04,
    /** Number of Controlees
     * To be configured by Host when MULTI_NODE_MODE is set other than 0x00.
     * Number of Controlees(N)
     * 1<=N<=8
     * (Default is 1)
     */
    NO_OF_CONTROLEES = 0x05,
    /** Device MAC Address
     * MAC Address of the UWBS itself participating in UWB session.
     * Size of this config is based on the MAC_ADDRESS_MODE.
     *
     * @note In case of Extended MAC Addr mode, this config is to be set through UwbApi_SetAppConfigMultipleParams.
     */
    DEV_MAC_ADDRESS = 0x06,
    /** Destination MAC Addr
     * MAC Address of the UWBS itself participating in UWB session.
     * Size of this config is based on the MAC_ADDRESS_MODE.
     *
     * @note In case of Extended MAC Addr mode, this config is to be set through UwbApi_SetAppConfigMultipleParams.
     */
    DST_MAC_ADDRESS = 0x07,
    /**
     * Unsigned integer that specifies duration of a ranging slot in the unit of RSTU (Ranging/Radar Standard Time Unit)
     * (default = 2400)
     */
    SLOT_DURATION = 0x08,
    /** Ranging Duration in ms
     * Ranging duration in the unit of 1200 RSTU which is 1 ms.
     * (default = 200)
     */
    RANGING_DURATION,
    /** STS index init value */
    STS_INDEX,
    /** MAC FCS TYPE
     * - 0x00 = CRC 16 (default)
     * - 0x01 = CRC 32
     */
    MAC_FCS_TYPE,
    /** 1:Enable, 0:Disable
     * - Below bits are applicable when SCHEDULED_MODE is set to 0x01(Time scheduled ranging)
     *  - b0 - Measurement Report Phase
     *  - b1 - Control Phase
     *  - b2 - Configuration of RCP in Non-deferred Mode TWR
     *  - b3 : b5 - RFU
     *  - b6 - Measurement Report Phase (MRP) [UWBS shall ignore this bit]
     *  - b7 - Measurement Report Message (MRM)
     * (default = 0x03)
     * - Below bits are applicable when SCHEDULED_MODE is set to 0x00(Contention-based ranging)
     *  - b0 - Ranging Result Report Message (RRRM) UWBS shall ignore this bit
     *  - b1 - 1 (Controller shall send a CM in-band and a Controlee shall expect a CM in-band)
     *  - b2 - 1 (RCP is excluded in Ranging Round)
     *  - b5 : b3 = RFU
     *  - b6 - Measurement Report Phase (MRP) ; If set to 0, MRP is not present (default) ; If set to 1, MRP is present
     *  - b7 - Measurement Report Message (MRM) UWBS shall ignore this bit.
     * (default = 0x06)
     */
    RANGING_ROUND_CONTROL,
    /** AOA RESULT REQ
     * - 0x00 = AoA results are disabled.
     * - 0x01 = AoA results are enabled(default), return all the AOA type supported by the device
     * - 0x02 = Only AoA Azimuth is enabled
     * - 0x03 = Only AOA Elevation is enabled
     */
    AOA_RESULT_REQ,
    /** SESSION_INFO_NTF
     * - 0x00 = Disable range data SESSION_INFO_NTF
     * - 0x01 = Enable range data SESSION_INFO_NTF (default)
     * - 0x02 = Enable range data SESSION_INFO_NTF while inside proximity range
     * - 0x03 = Enable range data SESSION_INFO_NTF while inside AoA (upper and lower) bounds
     * - 0x04 = Enable range data SESSION_INFO_NTF while inside AoA bounds as well as inside proximity range
     * - 0x05 = Enable range data SESSION_INFO_NTF only when entering and leaving proximity range.
     * - 0x06 = Enable range data SESSION_INFO_NTF only when entering and leaving AoA (upper and lower) bound
     * - 0x07 = Enable range data SESSION_INFO_NTF only when entering and leaving AoA bounds as well as entering and
     * leaving proximity range.
     */
    SESSION_INFO_NTF,
    /** Proximity near in cm
     * (default = 0)
     */
    NEAR_PROXIMITY_CONFIG,
    /** Proximity far in cm
     * (default = 20000)
     */
    FAR_PROXIMITY_CONFIG,
    /** Device Role
     * - 0x00 = Responder
     * - 0x01 = Initiator
     * - 0x02 = Assigned
     * - 0x03 = Assigned
     * - 0x04 = Assigned
     * - 0x05 = Advertiser
     * - 0x06 = Observer
     * - 0x07 = DT-Anchor
     * - 0x08 = DT-Tag
     */
    DEVICE_ROLE,
    /** Activate or deactivate RSSI reporting
     * - 0x00 = SP0 (Reserved value for test purpose)
     * - 0x01 = SP1
     * - 0x02 = RFU
     * - 0x03 = SP3
     * Values 0x04 to 0xFF = RFU
     * (default = 0x03)
     */
    RFRAME_CONFIG = 0x12,
    /** Activate or deactivate RSSI reporting
     * - 0x00 : Disable(default)
     * - 0x01 : Enable
     * - 0x02-0xFF :RFU
     */
    RSSI_REPORTING = 0x13,
    /** Preamble Code Index
     * - [9-12]   - BPRF,
     * - [25-32]  - HPRF, used for RADAR_MODE 1, 2 and 3
     * - [95-102] - LPRF used for RADAR_MODE 5 and 6
     * (default = 10)
     */
    PREAMBLE_CODE_INDEX = 0x14,
    /** [0,2]:BPRF, [1,2,3,4]:HPRF (default = 2) */
    SFD_ID,
    /** PSDU DATA RATE
     * - 0x00 = 6.81 Mbps (default)
     * - 0x01 = 7.80 Mbps
     * - 0x02 = 27.2 Mbps
     * - 0x03 = 31.2 Mbps
     * - 0x04 = 850 Kbps
     * Values 0x00, 0x02, 0x04 map to K=3 and 0x01, 0x03 map to K=7.
     */
    PSDU_DATA_RATE,
    /** Preamble Duration
     * - 0:32 symbols
     * - 1:64 symbols
     * - 0xA0:1024 symbols
     */
    PREAMBLE_DURATION,
    /** Link Layer Mode
     * - 0x00 - Bypass Mode (Default),
     * - 0x01 - Logical link data transfer
     */
    LINK_LAYER_MODE,
    /** Data Repetition Count
     * - 0x00 - No repetition (Default),
     * - 0xFF - Repeat infinite number of times
     */
    DATA_REPETITION_COUNT,
    /**  1:Block based (default) & 0:[2-255]:RFU */
    RANGING_TIME_STRUCT,
    /** Number of slots for per ranging round (default = 25) */
    SLOTS_PER_RR,
    /** AOA_BOUND_CONFIG
     * - [1:0] AOA_BOUND_CONFIG_LOWER_BOUND_AOA_AZIMUTH range -180 (default) to 180
     * - [3:2] AOA_BOUND_CONFIG_UPPER_BOUND_AOA_AZIMUTH range -180 to 180 (default)
     * - [5:4] AOA_BOUND_CONFIG_LOWER_BOUND_AOA_ELEVATION -90 (default) to 90
     * - [7:6] AOA_BOUND_CONFIG_UPPER_BOUND_AOA_ELEVATION -90 to 90 (default)
     */
    AOA_BOUND_CONFIG = 0x1D,
    /** PRF MODE
     * - 0x00 = 62.4 MHz PRF. BPRF mode (default)
     * - 0x01 = 124.8 MHz PRF. HPRF mode.
     * - 0x02 = 249.6 MHz PRF. HPRF mode with data rate 27.2 and 31.2 Mbps
     */
    PRF_MODE = 0x1F,
    /** Configuration parameter sets the minimum and maximum CAP size to be used by the
     * Controller/Initiator in the Contention-based ranging session, in the units of Ranging Slots.
     *
     * - Octet [0] - represents the maximum CAP size. Default = SLOTS_PER_RR-1.
     * - Octet [1] - represents the minimum CAP size. Default = 5.
     */
    CAP_SIZE_RANGE = 0x20,
    /** Parameter is used to set the multi-node Ranging Type.
     * - 0x00 = Contention-based ranging
     * - 0x01 = Time scheduled ranging (default)
     * - 0x02 = Hybrid-based ranging
     * Values 0x03 to 0xFF = RFU
     */
    SCHEDULED_MODE = 0x22,
    /** Key Rotation
     * - 1: Enable,
     * - 0:Disable [Default]
     */
    KEY_ROTATION,
    /** Key Rotation rate 2^n where 0<=n<=15 */
    KEY_ROTATION_RATE,
    /** Session Priority 1-100, default : 50 */
    SESSION_PRIORITY,
    /** MAC address mode Default 0 [SHORT] */
    MAC_ADDRESS_MODE,
    /** Unique vendor Id*/
    VENDOR_ID,
    /** Vendor defined static sts*/
    STATIC_STS_IV,
    /** Number of STS segments in the frame. 0x00:No STS
     * Segments(if PPDU_COFIG is 0). If PPDU Config is
     * set to 1 or 3 then 0x01:1 STS Segment(default),
     * 0x02:2 STS Segments */
    NUMBER_OF_STS_SEGMENTS,
    /** Number of Failed Ranging Round attempts before terminating
     * the session. Default : 0 */
    MAX_RR_RETRY,
    /** Indicates when ranging operation shall start after
     * ranging start request is issued from AP. Default : 0
     * @note UWB_INITIATION_TIME in past is accepted for Aliro Session Type
     * or if ALIRO_CONTROLEE_EXTENSIONS = 0x01 (Enable)*/
    UWB_INITIATION_TIME,
    /** Modes for the hopping.
     * - 0x00: No hopping
     * - 0x02: Adaptive hopping using MODULO
     * - 0x03: continuous hopping using MODULO
     * - 0x04: adaptive hopping using AES
     * - 0x05: continuous hopping using AES
     * Default : 0
     *
     * @ref eCCC_HopModes_t
     */
    HOPPING_MODE,
    /** Block Stride Length. 0x00:Default, [0x01-0xFF]:Application use case specific value **/
    BLOCK_STRIDE_LENGTH,
    /** Config to enable result report, 0: Disable, This is applicable only RANGING_ROUND_CONTROL enabled */
    RESULT_REPORT_CONFIG,
    /** Indicates how many times in-band termination signal needs to be sent by controller/initiator to a controlee
       device. Default : 1 */
    IN_BAND_TERMINATION_ATTEMPT_COUNT,
    /** Sub-Session Handle for the controlee device.
     * This config is mandatory and it is applicable if STS_CONFIG is set to 2 for controlee device */
    SUB_SESSION_ID,
    /** PHR coding rate:
     * - 0x00 = 850 kbps (default)
     * - 0x01 = 6.81 Mbps
     */
    BPRF_PHR_DATA_RATE,
    /**Maximum Number of ranging blocks to executed in a session  Default : 0
     *
     * In case of RANGING_ROUND_USAGE is set to 0x05 (OWR DL-TDoA), then this parameter indicates max number of ranging
     * blocks to be executed in a session.
     */
    MAX_NUMBER_OF_MEASUREMENTS,
    /** This parameter specifies the average transmission interval of Blink UTMs from
     *  UT-Tags and/or Synchronization UTMs from UT-Synchronization Anchors, as defined
     *  by the UL-TDoA TX Interval MAC configuration parameter.
     *
     *  By default, UL_TDOA_TX_INTERVAL = 2000ms.
     */
    UL_TDOA_TX_INTERVAL = 0x33,
    /** Length of the randomization window within which Blink and Synchronization UTMs may be transmitted. */
    UL_TDOA_RANDOM_WINDOW = 0x34,
    /** STS length
     * - 0: 32 symbols ,
     * - 1: 64 symbols(Default),
     * - 2: 128 symbols
     */
    STS_LENGTH = 0x35,
    /** configuration allows the Ranging Rounds to be suspended */
    SUSPEND_RANGING_ROUNDS = 0x36,
    /** UT-Anchor configuration to specify if UL-TDoA related SESSION_INFO_NTF */
    UL_TDOA_NTF_REPORT_CONFIG = 0x37,
    /** This value shall be used to specify the length and presence of the UL-TDoA Device ID in UTMs. */
    UL_TDOA_DEVICE_ID = 0x38,
    /** Presence and length of TX timestamps in UTMs. */
    UL_TDOA_TX_TIMESTAMP = 0x39,

    /** Minimum number of frames to be transmitted in a ranging round.(default = 4) */
    MIN_FRAMES_PER_RR = 0x3A,
    /** Maximum Transfer Unit (MTU) Size represents the maximum size of allowed payload size to be transmitted in a
       frame */
    MTU_SIZE = 0x3B,
    /** The configuration in units of 1200 RSTU to configure the interval between the RFRAMES transmitted in the “OWR
       for AoA Measurement” ranging round.(default = 1) */
    INTER_FRAME_INTERVAL = 0x3C,
    /** DL-TdoA ranging round
     * - 0: SS-TWR
     * - 1: DS-TWR (default)
     */
    DLTDOA_RANGING_METHOD = 0x3D,
    /** DL-TdoA Tx timestamp conf
     * - b0: TX timestamp type
     * - b1-2: TX timestamp length
     * Default: 00000011
     */
    DLTDOA_TX_TIMESTAMP_CONF,
    /** controls cluster sync field 1: inter cluster sync filed in every poll DTM */
    DL_TDOA_HOP_COUNT,
    /** DL-TdoA anchor CFO
     * - 0: not included,
     * - 1:Anchor CFO included (default)
     */
    DLTDOA_ANCHOR_CFO,
    /** DL-TdoA anchor location */
    DLTDOA_ANCHOR_LOCATION,
    /** DL-TdoA tx active ranging rounds
     * - 0: not present (default)
     * - 1: present
     */
    DLTDOA_TX_ACTIVE_RANGING_ROUNDS,
    /** To configure number of blocks that shall be skipped by a DT-Tag between two active ranging blocks,
     * 0x00      : No blocks striding(default)
     * 0x01-0xFF : no. of blocks to be skipped by DT-Tag*/
    DL_TDOA_BLOCK_SKIPPING = 0x43,
    /** global time rference of dl-tdoa network 0: Disable 1: Set global metric time */
    DLTDOA_TIME_REF_ANCHOR = 0x44,
    /** Session Key provided for Provisioned STS mode (STS_CONFIG equal to 0x03 or 0x04)
     * - If the Session Key is not provided by the Host in Provisioned STS mode, the UWBS shall fetch the Session Key
     * from the Secure Component. This parameter is valid only in Provisioned STS mode and shall be ignored otherwise.
     */
    SESSION_KEY = 0x45,
    /** Sub-session Key provided for Provisioned STS for Responder specific Key mode (STS_CONFIG equal to 0x04).
     * - If the Sub-session Key is provided by the Host, the Host shall also provide the SESSION_KEY.
     * - If the Sub-session Key is not provided by the Host for Provisioned STS for Responder specific Key mode, the
     * UWBS shall fetch the Sub-session Key from the Secure Component. This parameter is valid only in Provisioned STS
     * for Responder specific Key mode and shall be ignored otherwise.
     */
    SUB_SESSION_KEY = 0x46,
    /**This parameter is used to configure the SESSION_DATA_TRANSFER_STATUS_NTF.
     * - 0x00 = Disable SESSION_DATA_TRANSFER_STATUS_NTF (Default).
     * - 0x01 = Enable SESSION_DATA_TRANSFER_STATUS_NTF.
     * If SESSION_DATA_TRANSFER_STATUS_NTF is disabled, then the UWBS shall not send SESSION_DATA_TRANSFER_STATUS_NTF
     * for every Application Data transmission except for last transmission.
     */
    SESSION_DATA_TRANSFER_STATUS_NTF_CONFIG = 0x47,
    /** Configures a reference time base for the given session.
     * - Octet 0:
     *  - b0: Reference time base feature
     *      - 0b0 = Disable (default)
     *      - 0b1 = Enable
     *  - b1: continue/stop the session(s) when reference session is not in SESSION_STATE_ACTIVE Session State
     *      - 0b0 = stop (default)
     *      - 0b1 = continue
     *  - b2: Resync time grid in case the reference session will become active again after it has been inactive.
     *      - 0b0 = No resync (default)
     *      - 0b1 = Resync
     * - Octet 1-5: Session Handle of the reference session
     * - Octet 5-8: Session offset time in microseconds
     */
    SESSION_TIME_BASE = 0x48,
    /**This parameter specifies whether a DT-Anchor with the Responder role in a given ranging round
     * shall include the estimated Responder ToF Result in a Response DTM.
     * - 0x00: Responder ToF Result shall not be added to Response DTMs (default).
     * - 0x01: Responder ToF Result shall be added to Response DTMs.
     */
    DL_TDOA_RESPONDER_TOF = 0x49,
    /**This parameter is used to assign an Initiator DT anchor to a supercluster
     * When TX timestamp common time base type field is set to 0b1
     * the Initiator DT anchor shall perform cross-cluster synchronization using this Supercluster ID with
     * other Initiator DT anchors using the same Supercluster ID.
     */
    DL_TDOA_SUPERCLUSTER_ID = 0x51,
    /**This parameter specifies the round index in a range block if a DT-Anchor is configuration as Initiator
     * This parameter is not applicable to Responder DT-Anchor and DT-Tag.
     * A Responder DT-Anchor or DT-Tag receiving this parameter shall ignore it
     */
    INITIATOR_DT_ANCHOR_ROUND_INDEX = 0x52,
    /**
     * This parameter is required for PHY-layer security level in the form of an upper limit.
     * Normalized effective false acceptance rate (NEFA) as defined in spec, during secure ranging operation.
     *  - 0x00 = default, NEFA <= 1.0
     *  - 0x01 = Low, NEFA <= 2-10
     *  - 0x02 = Medium, NEFA <= 2-20
     *  - 0x03 = High, NEFA <= 2-48
     *  - 0x04-0xFF = RFU
     *
     * @note This parameter is only used for secure ranging with Provisioned STS or Test mode. A given implementation of
     *       UWBS might achieve a better level of PHY-layer security performance than the permissible upper limit set by
     *       the NEFA Level.
     */
    SECURE_RANGING_NEFA_LEVEL = 0x4A,
    /**
     *
     * The length of the PHY-layer critical search window (CSW) as defined in spec.
     * In the course of secure ranging operation. The unit of this parameter is 0.25 meter.
     * For example, a value of “8” corresponds to a distance of 2 meters. If not present its value shall be set to 0x04, a distance of 1 meter
     *
     * @note Only used for secure ranging with Provisioned STS or Test mode.
     */
    SECURE_RANGING_CSW_LENGTH = 0x4B,
    /**Local endpoint configuration of the session
     * It defines which endpoint is used by the UWBS for Application data exchange using the non-secure or secure
     * message connection. When using the Bypass mode, all data shall be exchanged using the Non-secure endpoint Values
     * - b3-b0: Non-secure end point configuration
     *  - 0x0 : Host  (default)
     *  - 0x1: Secure Component
     * 0xF- 0x2 :  RFU
     * - b7-b4: Secure end point configuration
     *  - 0x0 : Host (default)
     *  - 0x1: Secure Component
     * 0xF- 0x2 :  RFU
     */
    APPLICATION_DATA_ENDPOINT = 0x4C,
    /** DL-TdoA anchor location V2
    * Presence of DT-Anchor Location in DTM messages and location configuration
    */
    DLTDOA_ANCHOR_LOCATION_V2 = 0x4E,
    /**
    * Configuration to report type of DL-TDoA Ranging Mmeasurement Result v1 or v2
    * 0x00: Report DL-TDoA Ranging Measurement_V1 v1 (default)
    * 0x01: Report DL-TDoA Ranging Measurement_V2 v2
     */
    DLTDOA_MEASUREMENT_NTF_V2 = 0x4F,
#if UWBFTR_CCC
    /** Key to generate hopping sequence.
     * This value is used for both AES and MODULO hopping formula.
     * For MODULO hopping, only first 4 bytes are used as converted to 4byte integer.
     * (default key for AES hopping formula = 0x4c,0x57,0x72,0xbc)
     * (default key for MODULO hopping formula = 0xbc72574c)
     * */
    HOP_MODE_KEY = 0xA0,
    /**  1: responder1,...,N: responder N */
    RESPONDER_SLOT_INDEX = 0xA2,
    /** Version of the ranging protocol (defined by CCC)
     * [0x0000 – 0xFFFF]
     * (default = 0x0100)
     */
    RANGING_PROTOCOL_VER = 0xA3,
    /** UWB Configuration ID
     * [0x0000 – 0xFFFF]
     * (default = 0x0001)
     */
    UWB_CONFIG_ID = 0xA4,
    /** Pulse Shape Combinations.
     * Possible combinations are written in format:
     * Pulse shape combo value - Initiator transmit pulse shape - Responder transmit pulse shape
     * - 0x00 - 0x0 - 0x0
     * - 0x01 - 0x0 - 0x1
     * - 0x02 - 0x0 - 0x2
     * - 0x10 - 0x1 - 0x0
     * - 0x11 - 0x1 - 0x1
     * - 0x12 - 0x1 - 0x2
     * - 0x20 - 0x2 - 0x0
     * - 0x21 - 0x2 - 0x1
     * - 0x22 - 0x2 - 0x2
     * Support for value 0x00 is mandatory.
     * (default = 0x00)
     */
    PULSESHAPE_COMBO = 0xA5,
    /** URSK expiration time, in minutes (max 12 hours).
     * After this time from setting URSK, the session will go to idle.
     * [0x001 - 0x2D0]
     * (default = 0x2D0)
     */
    URSK_TTL = 0xA6,
    /** Responder is in listen only mode.
     * If it is enabled then the responder will not send range frame. In this mode, the responder will report 0xD
     * (responder is in listen only mode) as higher nibble of ranging status in RANGE_CCC_DATA_NTF 0x00: Responder is in
     * normal mode. 0x01: Responder is in listen only mode (default = 0x00)
     */
    RESPONDER_LISTEN_ONLY = 0xA7,
    /** Parameter used to get the STS index of the UWB session.
     * When SESSION_GET_APP_CONFIG_CMD issued for this config during SESSION_STATE_ACTIVE the UWBS shall return the last
     * STS Index of the latest completed ranging block.
     */
    LAST_STS_INDEX_USED = 0xA8,
#endif // UWBFTR_CCC
#if UWBFTR_CSA
    /**
     * This configuration is used to configure:
     * 1. The number of active ranging rounds in a RANGING_DURATION.
     * 2. Offset between two active ranging rounds in a RANGING_DURATION.
     *
     * - [b7-b6]: Number of active ranging round(s)
     *  - 0 = One active ranging round (default).
     *  - 1 = Two active ranging rounds (CSA use case).
     *  - 2 and 3 = RFU.
     * - [b5-b0]: Offset between two active ranging rounds.
     *  - 1 to (Nround - 1)
     *
     * @note
     * - Bits [b5, b0] SHALL be set if [b7, b6] set to decimal value 1. Otherwise, bits [b5, b0] will be ignored.
     * - Nround is calculated based on RANGING_DURATION, SLOTS_PER_RR and SLOT_DURATION.
     *
     */
    ALIRO_MAC_MODE = 0xA9,
#endif // UWBFTR_CSA

    /** End of App Configs*/
    END_OF_SUPPORTED_APP_CONFIGS,
} eAppConfig;

/**
 *  @brief Set Get Vendor App Configuration parameters supported in UWB API layer.
 */
typedef enum vendorAppConfig
{
    /** This parameter shall enable disable encryption of Payload data
     * - 0x00 - Plain Text
     * - 0x01 - Encrypted(default)
     */
    MAC_PAYLOAD_ENCRYPTION = 0x00,
    /**
     * The antenna used for TX.
     * If Octet[0] of ANTENNAE_CONFIGURATION_TX is 0 and Octet[1] of ANTENNAE_CONFIGURATION_RX is
     * 0, FW automatically enters Scan Phase.
     * - Octet[0] - Define number of TX Antennas to follow (default value is 1).
     * - Octet[1] - Tx Antennas ID as defined by ANTENNA_TX_DEFINE (default value is 1).
     *  So we transmit by default with Antennas ID 1 (As a pre requisite: an antenna with ID 1 using
     * ANTENNA_TX_IDX_DEFINE must be explicitly pre-defined).
     * - Octet[2] - Tx Antennas ID as defined by ANTENNA_TX_DEFINE Must be 0 for SR100T, SR150
     */
    ANTENNAE_CONFIGURATION_TX = 0x02,
    /**
     * The session specific antenna configuration for Rx.
     * If Octet[0] of ANTENNAE_CONFIGURATION_TX is 0, and Octet[0] of ANTENNAE_CONFIGURATION_RX
     * is 0, FW automatically enters Scan Phase.
     * - Octet [0] : Mode of RX operation
     *  - 0 : Configuration ToA Mode
     *      - ToF Only Mode
     *      - Recommended for TEST_PER, TEST_RX, TEST_SSTWR test modes, Optionally
     *        TEST_LOOPBACK test modes (AoA may not be reported) (for HELIOS-2)
     *  - 1 : Configuration AoA Mode
     *      - Dual / Single AoA usecase
     *      - ToA Mode with implicit Rx mode as per ANTENNAS_RX_PAIR_DEFINE (for HELIOS-1)
     *      - Recommended for TEST_LOOPBACK test mode, Optionally TEST_PER, TEST_RX,
     *        TEST_SSTWR test modes
     *  - 2 : Configuration Mode 2: Radar Mode
     *      - Default 0x01 (SR100S only)
     *  - 3 : Configuration Mode 3: ToA usecase using different Rx antenna pair for RFM
     *  - 4 : Configuration Mode 4: AoA usecase using different Rx antenna pair for RFM
     * - Octet [1] : Number of Antennas or Antenna pairs to follow
     *
     * Default Value:
     *  - For all Sessions
     *      - Octet[0] : 0x00 = ToA Mode
     *      - Octet[1] : 0x01 = Number fo RX Antenna
     *
     * @note Please refer the spec for more details on each configuration mode.
     */
    ANTENNAE_CONFIGURATION_RX = 0x03,
    /**
     * Return the possible RAN multiplier value for a new session
     */
    RAN_MULTIPLIER = 0x20,
    /**
     * - 0x00: Disable (default)
     * - 0x01: Enable
     */
    CIR_LOG_NTF = 0x30,
    /**
     * - 0x00: Disable (default)
     * - 0x01: Enable
     */
    PSDU_LOG_NTF = 0x31,
    /** This parameter is used to filter out the outliers in RSSI measurements in PER RX Test.
     * If the RSSI filtering count is set to N and total packet count is set to M then UWBS shall report the average of
     * (M-2N) RSSI values in TEST_PER_RX_NTF excluding(N) maximum and (N) minimum RSSI values.
     * @note M is the total packet count to be received in PER Rx test
     * (default = 0)
     */
    RSSI_AVG_FILT_CNT = 0x40,
    /**
     * CIR sampling position for incoming UWB packet
     * - bits[7:4] - CIR1 capture mode
     * - bits[3:0] - CIR0 capture mode
     *
     * CIR capture modes:
     *  - 0x0 - Pre SYNC RX1
     *  - 0x1 - Pre SYNC RX2
     *  - 0x2 - Pre STS RX1
     *  - 0x3 - Pre STS RX2
     *  - 0x4 - Post SYNC RX1
     *  - 0x5 - Post SYNC RX2
     *  - 0x6 - Post STS RX1
     *  - 0x7 - Post STS RX2
     *  - 0x8 - 0xF - RFU
     * (default = 0x76)
     *
     */
    CIR_CAPTURE_MODE = 0x60,
    /**
     * Number of times scheduler shall attempt to sync in controlee session before reporting error notification. This
     * config is applicable for controlee session only.
     * Range: [3 : 255] (Default: 3)
     *
     */
    SESSION_SYNC_ATTEMPTS = 0x62,
    /**
     * Number of times scheduler shall attempt to schedule ranging round before reporting error notification
     * Range: [1 : 255] (Default: 3)
     *
     */
    SESSION_SCHED_ATTEMPTS = 0x63,
    /**
     * Enable/disable SCHEDULER_STATUS_NTF
     * - 0x00 - Disable (default)
     * - 0x01 - Enable for including all the sessions information in notification
     * - 0x02 - Enable for include only failure sessions information in notification
     * - 0x03-0xFF: RFU
     */
    SCHED_STATUS_NTF = 0x64,
    /**
     * Session specific Tx power ID offset applied on top of Tx POWER calibration parameter. configured via SET_
     * DEVICE_CALIBRATION_CMD.
     * - 0:No offset (default)
     * - 1 to 127: Attenuation (0.25 dB per steps)
     * - 128 to 255: RFU
     *
     */
    TX_POWER_DELTA_FCC = 0x65,
    /**
     * This parameter is used to enable/disable KDF notification generation.
     * - 0x00: Disable (default)
     * - 0x01: Enable
     *
     */
    TEST_KDF_FEATURE = 0x66,
    /**
     * This parameter is used to enable/disable Tx power temperature compensation
     * - 0x00: Disable (Default)
     * - 0x01: Enable
     *
     */
    TX_POWER_TEMP_COMPENSATION = 0x67,
    /**
     * WiFi-CoEx maximum tolerance count, after the expiry of the number of count the UWBS shall make the
     * "Medium Grant Request" with priority field set to "Critical".
     * This parameter can be modified when session is in SESSION_STATE_ACTIVE Session State.
     * Range: [1 : 25] (Default: 3)
     *
     */
    WIFI_COEX_MAX_TOLERANCE_COUNT = 0x68,
    /**
     * This parameter can be used to configure the required number of successful responses(T) from Responders to
     * conclude a successful ranging round.
     * If numbers of responses is less than this given threshold(T) when Initiator device acting as Controller then
     * initiator device triggers a hop to a different round index within the next block.
     * Range: [0<T<= NUMBER_OF_CONTROLEES] (Default: NUMBER_OF_CONTROLEES)
     * @note This parameter is applicable when HOPPING_MODE = 0xA0 (NXP Adaptive Hopping mode is Enabled)
     */
    ADAPTIVE_HOPPING_THRESHOLD = 0x69,
#if UWBFTR_TransitProp
    /**
     * This parameter is used to set contention phase update value in number of slots.
     * Contention Phase is increased / decreased with integer multiple of this parameter.
     * Minimum Contention Phase is 2 X CONTENTION_PHASE_UPDATE_LENGTH
     * (Default: 5)
     *
     */
    CONTENTION_PHASE_UPDATE_LENGTH = 0x6D,
#endif // UWBFTR_TransitProp
    /**
     * Config to enable/disable authenticity tag in RANGE_DATA_NTF. This config is applicable when STS_CONFIG
     * is set to Dynamic STS.
     * - 0x00 = Disable (Default)
     * - 0x01 = Enable
     *
     */
    AUTHENTICITY_TAG = 0x6E,
    /**
     * - Octet [0] : Used to configure NBIC settings
     *  - b[0]: Enable / Disable NBIC.
     *   - 0 = Disable (default)
     *   - 1 = Enable
     *  - b[1:2]: Content of register MA_FILTER_BW_SET. Filter bandwidth setting (default: 0x3)
     *  - b[3:4]: Content of register MA_FILTER_BW_START_SET. Starting filter bandwidth setting for estimation (default:
     * 0x3)
     *  - b[5:7]: RFU
     * - Octet [1]: Content of register PSD_WEIGHT_SET (Default: 0x14 )
     *  (Default: 0x40 only applicable when NBIC is enabled )
     *
     */
    RX_NBIC_CONFIG = 0x6F,
    /**
     * Config is used to configure the MAC Header and MAC Footer
     * - b[0]: MAC Header present
     * - b[1]: MAC Footer present
     * - b[7:2]: RFU
     *   (Default value: 0x03 for FIRA Session)
     *   (Default value: 0x00 for Test Mode Session)
     *
     */
    MAC_CFG = 0x70,
    /**
     * Amount of blocks which should be reserved for the given session for inband data transfer for transmitting
     * data. If set to 0, transmitting inband data is not allowed for this session.
     * @note The sum of this value for all active session must not exceed UWBS_INBAND_DATA_MAX_BLOCKS
     * and will prevent the first session which is causing to exceed the limit to get started.
     * Default Value:
     *   0 for Ranging Session
     *   UWBS_INBAND_DATA_BUFFER_BLOCK_SIZE for Data Session with DEVICE_TYPE set to Controlee
     *   0 for Data Session with DEVICE_TYPE set to Controller
     *
     */
    SESSION_INBAND_DATA_TX_BLOCKS = 0x71,
    /**
     * Amount of blocks which should be reserved for the given session for inband data transfer for receiving data. If
     * set to 0, receiving inband data is not allowed for this session.
     * @note The sum of this value for all active session must not exceed UWBS_INBAND_DATA_MAX_BLOCKS
     * and will prevent the first session which is causing to exceed the limit to get started.
     * Default Value:
     *   0 for Ranging Session
     *   UWBS_INBAND_DATA_BUFFER_BLOCK_SIZE for Data Session with DEVICE_TYPE set to Controller
     *   0 for Data Session with DEVICE_TYPE set to Controlee
     *
     */
    SESSION_INBAND_DATA_RX_BLOCKS = 0x72,
    /**
     * This configuration shall be used to configure DATA_TRANSMISSION_STATUS_NTF indication
     * - 0x00 : Always ON
     * - 0x01 : Always OFF
     * - 0x02 : Notify when error
     * (Default: 0x00)
     *
     * @note The UWBS shall always send DATA_TRANSMISSION_STATUS_NTF whenever it receives DATA_MESSAGE_SND, the
     * subsequent DATA_TRANSFER_TX_STATUS_NTF on RF transmit shall be sent based on DATA_TRANSFER_TX_STATUS_CONFIG
     * configuration
     *
     */
    DATA_TRANSFER_TX_STATUS_CONFIG = 0x75,
#if (UWBFTR_UL_TDoA_Tag)
    /**
     * Parameter to select MAC frame format for UL-TDOA Tag device
     * - 0x00: FIRA (Default)
     * - 0x01: Vendor-specific MAC format
     * @note This parameter is only applicable when RANGING_ROUND_USAGE = 0x00 (One Way Ranging UL-TDoA) and DEVICE_ROLE
     * = 0x04 (UT-Tag)
     *
     */
    ULTDOA_MAC_FRAME_FORMAT = 0x76,
#endif // (UWBFTR_UL_TDoA_Tag)
#if (UWBFTR_SE_SE051W)
    /**
     * Session ID (4 octets) || Random (12 octets) || Wrapped RDS from SE (Maximum 40 octets)
     *
     */
    WRAPPED_RDS = 0x79,
#endif
    /**
     * This configuration is used to enable/disable RFRAME LOG NTF.
     * - 0x00 = Disable (default)
     * - 0x01 = Enable
     * Values 0x02 to 0xFF = RFU
     */
    RFRAME_LOG_NTF = 0x7B,
    /**
     * This configuration is used to enable/disable adaptive payload power for TX.
     * - 0x00 = Disable
     * - 0x01 = Enable (default)
     * Values 0x02 to 0xFF = RFU
     */
    TX_ADAPTIVE_PAYLOAD_POWER = 0x7F,
#if (UWBFTR_AoA_FoV && UWBIOT_UWBD_SR150)
    /** Session specific configuration parameter is used to swap the antenna pair for RFM reception.
     *
     * - 0x00 =  not swap ( Same pairs are used for all message reception) (Default)
     * - 0x01 = Pair1 and Pair 2 are swapped for RFM reception
     *
     * When SWAP_ANTENNA_PAIR_3D_AOA is set to 0x01 then RSSI measurements shall be report for all pairs in the
     * RANGE_DATA_NTF. Applicable only for Responder.
     * This feature can be enabled only for Aliro Session Type or if ALIRO_CONTROLEE_EXTENSIONS = 0x01 (Enable)
     *
     * \note This parameter is only supported on SR150 devices and enables
     * antenna pair swapping for 3D Angle of Arrival (AoA) measurements.
     */

    SWAP_ANTENNA_PAIR_3D_AOA = 0x80,
#endif // (UWBFTR_AoA_FoV && UWBIOT_UWBD_SR150)
    /**
     * - Octet 0: RML_NEAR_PROXIMITY (default = 0)
     *  This parameter sets the lower bound in meters where the discovered devices are added into the RML list. Should
     * be less than or equal to  RML_FAR_ _CONFIG value.
     *
     * - Octet 1: RML_FAR_PROXIMITY (default = 5)
     *  This parameter sets the upper bound in meters above which the RML list is not added with the discovered devices.
     * Should be greater than or equal to  RML_NEAR_CONFIG value.
     *
     */
    RML_PROXIMITY_CONFIG = 0x81,
#if UWBFTR_CSA
    /**
     * This configuration is used to Enable/Disable sync with controller
     * - 0x00 : Re-sync is disabled
     * - 0x01 : Re-sync is enabled (Default)
     *
     * RCM Re-sync enable:
     *  - If the device misses 5 RCM messages and it is assumed that sync is lost(probably the controller isn’t sending them), it will respond by increasing its listening time. Specifically, it will open its Rx window to twice the Ranging Duration(RANGING_DURATION).
     *  - This extended listening continues until the device successfully re-establishes sync.
     *
     * RCM Re-sync disable:
     *  - Once it is assumed that sync is lost, Controlee will not open its RCM Rx window to twice the Ranging Duration(RANGING_DURATION).
     *
     * \note
     *  - The vendor-specific application parameter is applicable for Aliro sessions or if ALIRO_CONTROLEE_EXTENSIONS = 0x01 (Enable).
     *  - If this parameter is set for any other session type, FW will return an INVALID_PARAM.
     *  - If the resynchronization logic is disabled, the controlee may or may not re-sync again. In this case host has to restart the session in order to resync
     */
    RESYNC_ENABLE = 0x83,
#endif // UWBFTR_CSA
#if UWBFTR_AoA_FoV
    /** 2D AoA FoV Processing Enable/Disable
     * This parameter decides whether to enable or disable 2D AoA FoV Processing.
     * - 0x00 : 2D AoA FoV Processing Disabled (Default)
     * - 0x01 : 2D AoA FoV Processing Enabled
     */
    FOV_ENABLE = 0x84,
    /** Field of View for Horizontal Antenna Pair.
     * This parameter indicates if the peer device is in the configured FoV of the device or not.
     * - Octet[0] : Horizontal RX Antenna Pair ID as defined in 'ANTENNAS_RX_PAIR_DEFINE UCI parameter'.
     * Value 0 shall be rejected.
     * - Octet[1] : FoV Coverage in degrees.
     */
    AZIMUTH_FIELD_OF_VIEW = 0x85,
#endif // UWBFTR_AoA_FoV
#if UWBIOT_UWBD_SR150
    /** Session specific configuration parameter enables or disables proprietary Aliro optimization mechanisms
    *
    * for enhanced ranging performance.
    *
    * - 0x00 : Aliro Controlee Optimizations Disabled (Default)
    * - 0x01 = Aliro Controlee Optimizations Enabled
    *
    * Applicable on controlee for FiRa Session Type, with
    * RANGING_ROUND_USAGE = 0x02 (DS-TWR with Deferred Mode )
    *
    * Ignored for rest of the Session Types and RANGING_ROUND_USAGE values
    */
    ALIRO_CONTROLEE_EXTENSIONS = 0x8A,
#endif //UWBIOT_UWBD_SR150
#if UWBFTR_CSA
    /**
     * Configuration to enable/disable transmission of Final Data 2 from Responder to Initiator.
     * - 0x00 = Responder shall not transmit Final Data 2 message (default).
     * - 0x01 = Responder shall transmit the Final Data 2 message
     */
    CSA_FINAL_DATA2_CONFIG = 0x90,
#endif // UWBFTR_CSA

    /** Enable / Disable FoM processing.
     * - Bit[0] : 3D AoA FoM: Enable/Disable 3D AoA FoM Default is 0.
     * - Bit[7:1] : RFU
     * @note For ENABLE_FOM = 1, SLOT_DURATION should be greater than or equal to 2ms (2400 RSTU).
     */
    ENABLE_FOM = 0x91,

#if UWBFTR_TransitProp
    /**
     * Octet [0-7]: Padding to be used in HUS CM Type 3 message
     */
    CM3_PADDING = 0x9D,
    /**
     * Octet [0-3] Epoch time for Transit authentication
     */
    EPOCH_TIME = 0x9E,
#endif // UWBFTR_TransitProp

    /**
     * - Octet [0]: Use Case
     *  - 0x00 = None (default)
     *  - 0x01 = Secure payment
     *  - 0x02 = NXP Static STS ranging
     *  - 0x03 = Mifare Static STS ranging
     *  - 0xFF-0x04 = RFU
     * - Octet [1-2]: Feature bitmask specific to Use case (Octet [0])
     *      The below bitmask applies for Use Case set to 0x01
     *  - b0 = APDU Aggregation
     *      - 1: Enable (default)
     *      - 0: Disable
     *  - b1 = in-band static STS to dynamic STS switch
     *      - 1: Enable (default)
     *      - 0: Disable
     *  - b15-b2 = RFU
     *
     *  \note Octet [1-2] shall be ignore by UWBS when Octet [0] is set to 0x02
     */
    SET_USECASE_ID = 0x9F,

    /**
     * Represents a single byte number:
     * - 1~255 (default: 1)
     * - 0 = Invalid Range
     * - 1 = No filtering applied.
     * Host is notified immediately with SESSION_INFO_NTF upon PROXIMITY criteria being met
     * - 2~255 = The number of consecutive Ranging Rounds which must meet the PROXIMITY criteria before a Notification is sent to the Host
     * This can be applied to either an Initiator device or Responder device
     *
     * \note Applicable for SESSION_INFO_NTF = 0x02, 0x05.
     */
    SESSION_INFO_NTF_FILTER_NUM = 0x86,

#if UWBFTR_Radar
    /**
     * RADAR mode .
     * - 0x01: Medium distance, e.g. used for vital sign detection .
     * - 0x02: Close distance, e.g. used for hand gesture recognition .
     * - 0x03: Far distance, e.g. used for presence detection .
     * - 0x04: RFU .
     * - 0x05: Medium distance, e.g. used for static object support .
     * - 0x06: Far distance, e.g. used for static object support .
     * (Default value: 0x01) .
     */
    RADAR_MODE = 0xA0,
    /**
     * - bits[31:28]: reduced calculated RX gain index by this value
     * - bits[27:26]
     *  – 0: 3 iterations for SW AGC
     *  – 1: 5 iterations for SW AGC
     *  – 2: 7 iterations for SW AGC
     *  – 3: 10 iterations for SW AGC
     * - bits[25:24]
     *  - 0: Enable AGC
     *  - 1: Force gain index values
     *  - 2: Force AGC to be re-executed
     * - bits[23:16]: Gain index for RXA
     * - bits[15:8] : Gain index for RXB
     * - bits[7:0] : Gain index for RXC
     *Default: 0x00000000
     */
    RADAR_RX_GAIN = 0xA4,
    /**
     * Defines the mode used to transmit CIR samples.
     * - 0x00: use a buffer to transmit the CIR samples if the buffer is .
     * full or session switch will be performed.
     * - 0x01: transmit every single CIR sample .
     * (Default: 0) .
     */
    RADAR_SINGLE_FRAME_NTF = 0xA5,
    /**
     * Number of TAPs to be captured .
     *(Default = 128, MIN = 16, MAX = 128) .
     */
    RADAR_CIR_NUM_SAMPLES = 0xA7,
    /**
     * Defines the start index of the CIR in case of Radar modes
     * using HPRF:
     * - Octet[0]: Length in Words
     * (Default:3)
     *  - Word[1] start index for RXC for antenna pair 0
     *  - Word[2] start index for RXB for antenna pair 0
     *  - Word[3] start index for RXA for antenna pair 0
     *  - Word[4] start index for RXC for antenna pair 1
     *  - Word[5] start index for RXB for antenna pair 1
     *  - Word[6] start index for RXA for antenna pair 1
     *  (Default: 0)
     * If length is set to 3, octet 4 / 5 / 6 shall not be present. All other
     * values except 3 and 6 for length are invalid.
     * Start index of 0 triggers the automatic calculation of the start
     * index; Any other value sets the start index (HPRF range is[1:727])
     */
    RADAR_CIR_START_OFFSET = 0xA8,
    /**
     * RFRI (Radar Frame Repetition Interval):
     *
     * - Octet[3:0]: RANGING_INTERVAL
     *   - Duration between the start of two, consecutive Radar rounds in ms
     * - Octet[5:4]: SLOT_DURATION
     *   - Duration between the start times of two consecutive Radar frames in RSTU.
     * - Octet[6]: SLOTS_PER_RR
     *   - Number of Radar frames within the Radar round
     */
    RADAR_RFRI = 0xA9,
    /**
     * This UCI parameter shall check the following if Presence Detection Mode is Enabled:
     * - RADAR_MODE with value set as 1
     * - RADAR_CIR_NUM_SAMPLES with value must be greater than (MaxDistance in cm/15cm)
     *
     * - Octet[0]: Presence Detection Mode
     *   - Default: Disabled
     *   - Bit 0:   Presence detection enabled
     *   - Bit 1:    Distance and AoA reporting enabled
     *   - Bit 2:    Report all the targets
     *   - Bit 3:   CIR Injection used
     *   - Bit 4:   Detection trigger value reporting
     *   - If Bit 4 is set, also Bit 1 has to be set.
     *
     * - Octet[1]: Periodic data reporting
     *   - Default:0
     *   - Bit 0: sending raw CIRs to the host
     *   - Bit 2-1:
     *      - 00: no periodic presence reporting
            - 01:  presence reporting every 50ms
            - 10: presence reporting every 400ms
            - 11: presence reporting every 1600ms
     * - Octet[2] - Presence Detection Sensitivity in Q4.4 Format (4 bits for Fractional, 4 bits for integer)
     *   - Default: 3.75
     *   - Min: 1, Max 7
     * - Octet[3] - Set to enable GPIO to notify presence
     *  - Bit 3-0: GPIO line to be used, 0 disabled
     *  - 1 : GPIO1       - 9 : GPIO9
     *  - 2 : GPIO2       -10 : GPIO10
     *  - 3 : GPIO3       -11 : GPIO11
     *  - 4 : GPIO4       -12 : GPIO12
     *  - 5 : GPIO5       -13 : GPIO13
     *  - 6 : GPIO6       -14 : GPIO14
     *  - 7 : GPIO7       -15 : GPIO15
     *  - 8 : GPIO8
     *  - Bit 6-4: RFU
     *  - Bit 7: 1 to disable RADAR_RX_NTF(Presence Detection)
     *  - (Default:0)
     *  - @note: Both GPIO and PD notification should not be disabled at one time. FW will return invalid range error.
     * - Octet[4-5]: Presence Detection Distance Min in cm
     *   - Default: 30
     *   - Min: 30, Max - 800
     * - Octet[6-7]: Presence Detection Distance Max in cm
     *   - Default: 800
     *   - Min: 50, Max - 800
     * - Octet[8-9]: Presence Detection Hold Delay : delay until presence is reported as lost in ms
     *   - Default: 1600
     *   - Min: 400, Max:5000
     * - Octet[10]: Set Minimum Angle
     *    - Default: -90, range -90, +90, int8_t format, default means that no minimum angle is used
     * - Octet[11]: Set Maximum Angle
     *    - Default: 90, range -90, +90, int8_t format, needs to be greater than minimum angle, default means that no
            maximum angle is used
     */
    RADAR_PRESENCE_DET_CFG = 0xAA,
    /**
     * Parameter to test FCC 10 second rule
     * - 0: Test mode OFF (default)
     * - 1: Test mode ON
     */
    RADAR_FCC_TEST_MODE = 0xAC,
    /**
     * Enable DC Freeze
     * - 0: DC Freeze Disabled
     * - 1: DC Freeze Enabled (default)
     */
    RADAR_DC_FREEZE = 0xAD,
    /*
    * TX PULSE SHAPE to be used for Radar.
    * - Allowed pulse shape IDs are 41, 50 and 65.
    * - All other Pulse shape IDs will be rejected.
    *   Default Pulse Shape :
    *    - PS 50 for Radar Modes 1, 2, 3 and 4
    *    - PS 41 for Radar Modes 5 - 6
    */
    RADAR_PULSE_SHAPE = 0xAE,
    /** bit[15:0] : Alpha in Q1.15 format
     * (Default: 0x00)
     * @note Value 0 denotes that Drift compensation is disabled
     */
    RADAR_DRIFT_COMPENSATION = 0xB2,
    /**
     * 1 byte - Number of Radar Session Configs(N) (0-2)
     *
     *  - RADAR_CFG[0]:
     * 	  - Octet[0]: RADAR_MODE
     * 	  - Octet[1]: PREAMBLE_CODE_INDEX
     * 	  - Octet[2]: TX_ANT_ID
     * 	  - Octet[3-4]: Start Index for RX1
     * 	  - Octet[5-6]: Start Index for RX2
     * 	  - Octet[7-8]: Start Index for RX3
     * 	  - Octet[9]: ANT CFG for RX1
     * 	  - Octet[10]: ANT CFG for RX2
     * 	  - Octet[11]: ANT CFG for RX3
     * 	  - Octet[12]: Gain index for RX1
     * 	  - Octet[13]: Gain index for RX2
     * 	  - Octet[14]: Gain Index for RX3
     * 	  - Octet[15]:
     *      - bits[1:0]
     * 	  	 - 0: Enable AGC
     * 	  	 - 1: Force gain index values
     * 	  	 - 2: Force AGC to be re-executed
     *      - bits[2:3]
     *        - 0: 3 iterations for SW AGC
     *        - 1: 5 iterations for SW AGC
     *        - 2: 7 iterations for SW AGC
     *        - 3: 10 iterations for SW AGC
     *      - bits[7:4] : reduce calculated RX gain index by this value
     * 	  	- Default: 0x0
     * 	  - Octet[16]: TX Pulse Shape
     * 	  	- Default: 0x00
     */
    RADAR_CFG = 0xB3,
#endif // UWBFTR_Radar
#if (UWBFTR_CSA)
    /**
     * This parameter allows user to set the RX window for the initial UWB sync, with a dynamic increase in the window size after certain retry counts.
     *
     * - Octet [3:0] - RX_WINDOW_DURATION
     *  - This parameter is used to configure the UWB listening window size duration in the unit of RSTU
     *  - (Default: 0 (This implies the feature is not applicable))
     *
     * Non-Zero value range:
     * ```
     *  1200 <= RX_WINDOW_DURATION  <=  (25% of RANGING_DURATION)
     * ```
     * If the value is set ‘0’, then below fields are not applicable.
     *
     * - Octet [5:4] – RX_WINDOW_STEP_SIZE
     *  - Rx window step size duration added at each RETRY_RX_COUNT in the unit of RSTU.
     *  - (Default : 0)
     *
     * - Octet [6] – RETRY_RX_COUNT
     *  - Number of ranging timeout before increasing the RX_WINDOW_DURATION
     *  - (Default : 1)
     *  - Min RETRY_RX_COUNT : 1
     *
     * For first ranging block,
     * ```
     * RX window =  INITIATION_TIME +/- RX_WINDOW_DURATION.
     * ```
     * For subsequent blocks,
     * ```
     * RX window =  RANGING_DURATION +/- (RX_WINDOW_DURATION + RX_WINDOW_STEP)
     * ```
     *
     * \note
     *  - This parameter is only applicable if UWB_INITIATION_TIME is set to a Non-Zero value.
     *  - For optimal power saving, all the sessions which are using UWB_INITIATION_TIME should set the non-zero value for RX_WINDOW_DURATION
     * \note
     *  - This parameter is only applicable for controlee device type.
     *  - This param is applicable for only Aliro session type(0xA2).
     *  - The RX_WINDOW opening will be done once per ranging block even if 2 ranging rounds are configured per block in ALIRO_MAC_MODE.
     *  - This param is applicable in FiRa session on Controlee device if ALIRO_CONTROLEE_EXTENSIONS = 0x01 (Enable)
     *  - In case of Aliro Session Type, the RX Window opening will be done once per Ranging Block ,
     *  - even if 2 Ranging rounds are configured per Block in ALIRO_MAC_MODE
     * \note
     * `SESSION_STATUS_NTF` will throw an error with the following reason codes:
     * - `ERROR_INVALID_INITIAL_SYNC_RX_WINDOW_CONFIG_CONFIGURED`
     *   This occurs if:
     *   ```
     *   RX_WINDOW_DURATION is configured > 25% of RANGING_DURATION
     *   ```
     * - `ERROR_INITIAL_SYNC_RX_WINDOW_INITIATION_TIME_NOT_CONFIGURED`
     *   This occurs if:
     *   ```
     *   RX_WINDOW_DURATION is configured without configuring UWB_INITIATION_TIME
     *   ```
    */
    INITIAL_SYNC_RX_WINDOW_CONFIG = 0xC2,
#endif // (UWBFTR_CSA)
} eVendorAppConfig;

/**
 *  @brief Debug Configuration parameters supported in UWB API layer.
 */
typedef enum UWB_DBG_CFG
{
#if UWBIOT_UWBD_SR2XXT
    /* Only Applicable to H2 and Yukon */
    kUWB_DBG_CFG_DATA_LOGGER_NTF = 0x7A,
#endif // UWBIOT_UWBD_SR2XXT
    kUWB_DBG_CFG_TEST_CONTENTION_RANGING_FEATURE = 0x7C,
    kUWB_DBG_CFG_CIR_CAPTURE_WINDOW              = 0x7D,
    kUWB_DBG_CFG_RANGING_TIMESTAMP_NTF           = 0x7E,
    /** End of Ext Debug Configs*/
    END_OF_SUPPORTED_EXT_DEBUG_CONFIGS,
} UWB_DBG_CFG_t;

typedef enum UWB_SR2XX_DBG_DATALOGTRG_CFG
{
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_INIT = 0x00,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_ACQ_SEARCH,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_ACQ_FOUND,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_SFD_SEARCH,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_SFD_FOUND,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_SIG_REJECTED,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS1_GUARD1,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS1,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS1_INTERNAL_GUARD,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS1_END,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS1_GUARD2,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_PHR,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_PHR_END,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_PSDU,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_PSDU_END,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS2_GUARD1,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS2,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS2_INTERNAL_GUARD,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS2_END,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_STS2_GUARD2,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_EOF,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_OFF,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_HW_NOISE_EST,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_BINNING_ONLY,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_ADC_REC,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_SIDELOBE_SUPPR,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_FIRSTPATH_SEARCH,
    kUWB_SR2XX_DBG_DATALOGTRG_CFG_RX_STATE_FAIL,
} UWB_SR2XX_DBG_DATALOGTRG_CFG_t;

/**
 *  @brief Set/Get App Configuration parameters type supported in UWB API layer.
 */
typedef enum UWB_AppParams_type
{
    /** We don't know the type */
    kUWB_APPPARAMS_Type_Unknown = 0,
    /** It's a 32 bit value */
    kUWB_APPPARAMS_Type_u32 = 4,
    /** It's an array of 8 bit values*/
    kUWB_APPPARAMS_Type_au8 = 5,
} UWB_AppParams_type_t;

/**
 *  @brief Set/Get Debug Configuration parameters type supported in UWB API layer.
 */
typedef enum UWB_DebugParams_type
{
    /** It's a 8 bit value */
    kUWB_DEBUGPARAMS_Type_u8 = 1,
    /** It's a 16 bit value */
    kUWB_DEBUGPARAMS_Type_u16 = 2,
    /** It's a 32 bit value */
    kUWB_DEBUGPARAMS_Type_u32 = 4,
    /** It's an array of 8 bit values */
    kUWB_DEBUGPARAMS_Type_au8 = 5,

} UWB_DebugParams_type_t;

/**
 *  @brief Set/Get App Configuration parameters value type supported in UWB API layer.
 */
typedef struct UWB_AppParams_value_au8
{
    uint8_t *param_value;
    uint16_t param_len; // Just to  handle parameter of any length
} UWB_AppParams_value_au8_t;

/**
 *  @brief Set/Get App Configuration parameters value structure supported in UWB API layer.
 */
typedef union UWB_AppParams_value {
    uint32_t vu32; // All values u8, u16 and u32 are processed here
    UWB_AppParams_value_au8_t au8;
} UWB_AppParams_value_t;

/**
 *  @brief Set/Get Debug Configuration parameters value type supported in UWB API layer.
 */
typedef struct UWB_Debug_Params_value
{
    uint8_t *param_value;
    uint16_t param_len; // Just to  handle parameter of any length
} UWB_Debug_Params_value_t;
/**
 *  @brief Set/Get Debug Configuration parameters value structure supported in UWB API layer.
 */
typedef union UWB_DebugParams_value {
    uint8_t vu8;   // values u8 are processed here
    uint16_t vu16; // values u16 are processed here
    uint32_t vu32; // values u32 are processed here
    UWB_Debug_Params_value_t param;
} UWB_DebugParams_value_t;

/**
 *  @brief Set/Get App Configuration parameters list supported in UWB API layer.
 */
typedef struct UWB_AppParams_List
{
    /** Input: search this tag */
    eAppConfig param_id;
    /** Filled Implicitly: Expected type. */
    UWB_AppParams_type_t param_type;
    /** Input: Parameter Value */
    UWB_AppParams_value_t param_value;
} UWB_AppParams_List_t;

/**
 *  @brief Set/Get Vendor App Configuration parameters list supported in UWB API layer.
 */
typedef struct UWB_VendorAppParams_List
{
    /** Input: search this tag */
    eVendorAppConfig param_id;
    /** Filled Implicitly: Expected type. */
    UWB_AppParams_type_t param_type;
    /** Input: Parameter Value */
    UWB_AppParams_value_t param_value;
} UWB_VendorAppParams_List_t;

#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

/**
 * @brief Structure lists doen the Multi channel WiFi Coex Features
 */
typedef struct UWB_WiFiCoEx_Ftr_List
{
    /** Channel Id, for which the WiFiCoEx feature is configured */
    uint8_t UWB_WiFiCoEx_channel_Id;
    /* Minimum gap in milliseconds between the end of previous active grant duration and next medium access request */
    uint8_t UWB_WiFiCoEx_MinGuardDuration;
    /* Minimum gap in milliseconds between the end of previous active grant duration and next medium access request */
    uint8_t UWB_WiFiCoEx_MaxGrantDuration;
    /* Maximum duration for which the UWB can request for medium access */
    uint8_t UWB_WiFiCoEx_AdvacnedGrantDuration;
} UWB_WiFiCoEx_Ftr_List_t;

/**
 * @brief  This configuration is used to configure the WiFi CoEx feature.
 */
typedef struct UWB_WiFiCoEx_Ftr
{
    /* Enable/Disable CoEx functionality with appropriate interface and verbose */
    uint8_t UWB_WiFiCoEx_Enable;
    /** Number of channels */
    uint8_t UWB_WiFiCoEx_noOfChannels;
    /** List of WiFi CoEx Feature Configs */
    UWB_WiFiCoEx_Ftr_List_t wifiCoexFtrList[MAX_CHANNELS];
} UWB_WiFiCoEx_Ftr_t;

#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

/**
 *  @brief Macro to set SetApp Configuration parameters value supported in UWB API layer.
 */
#define UWB_SET_APP_PARAM_VALUE(PARAM, VALUE)                                                      \
    {                                                                                              \
        .param_id = (PARAM), .param_type = (kUWB_APPPARAMS_Type_u32), .param_value.vu32 = (VALUE), \
    }

/**
 *  @brief Macro to set GetApp Configuration parameters value supported in UWB API layer.
 */
#define UWB_SET_GETAPP_PARAM(PARAM)                                   \
    {                                                                 \
        .param_id = (PARAM), .param_type = (kUWB_APPPARAMS_Type_u32), \
    }

/**
 *  @brief Macro to set SetApp/GetApp Configuration parameters array value supported in UWB API layer.
 */
#define UWB_SET_APP_PARAM_ARRAY(PARAM, ARRAY, LENGTH)                                                        \
    {                                                                                                        \
        .param_id = (PARAM), .param_type = (kUWB_APPPARAMS_Type_au8), .param_value.au8.param_len = (LENGTH), \
        .param_value.au8.param_value = (uint8_t *)(ARRAY)                                                    \
    }

#define UWB_SET_VENDOR_APP_PARAM_VALUE UWB_SET_APP_PARAM_VALUE
#define UWB_SET_GETVENDOR_APP_PARAM    UWB_SET_GETAPP_PARAM
#define UWB_SET_VENDOR_APP_PARAM_ARRAY UWB_SET_APP_PARAM_ARRAY

/**
 *  @brief Set/Get App Configuration parameters list supported in UWB API layer.
 */
typedef struct UWB_DebugParams_List
{
    /** Input: search this tag */
    UWB_DBG_CFG_t param_id;
    /** Filled Implicitly: Expected type. */
    UWB_DebugParams_type_t param_type;
    /** Input: Parameter Value */
    UWB_DebugParams_value_t param_value;
} UWB_DebugParams_List_t;

/**
 *  @brief Macro to set Set Debug Configuration parameters value supported in UWB API layer.
 */
#define UWB_SET_DEBUG_PARAM_VALUE_u8(PARAM, VALUE)                                                 \
    {                                                                                              \
        .param_id = (PARAM), .param_type = (kUWB_DEBUGPARAMS_Type_u8), .param_value.vu8 = (VALUE), \
    }

#define UWB_SET_DEBUG_PARAM_VALUE_u16(PARAM, VALUE)                                                  \
    {                                                                                                \
        .param_id = (PARAM), .param_type = (kUWB_DEBUGPARAMS_Type_u16), .param_value.vu16 = (VALUE), \
    }

#define UWB_SET_DEBUG_PARAM_VALUE_u32(PARAM, VALUE)                                                  \
    {                                                                                                \
        .param_id = (PARAM), .param_type = (kUWB_DEBUGPARAMS_Type_u32), .param_value.vu32 = (VALUE), \
    }
/**
 *  @brief Macro to set Get Debug Configuration parameters value supported in UWB API layer.
 */
#define UWB_SET_GETDEBUG_PARAM_u8(PARAM)                               \
    {                                                                  \
        .param_id = (PARAM), .param_type = (kUWB_DEBUGPARAMS_Type_u8), \
    }
#define UWB_SET_GETDEBUG_PARAM_u16(PARAM)                               \
    {                                                                   \
        .param_id = (PARAM), .param_type = (kUWB_DEBUGPARAMS_Type_u16), \
    }
#define UWB_SET_GETDEBUG_PARAM_u32(PARAM)                               \
    {                                                                   \
        .param_id = (PARAM), .param_type = (kUWB_DEBUGPARAMS_Type_u32), \
    }
#define UWB_SET_DEBUG_PARAM_ARRAY(PARAM, ARRAY, LENGTH)                                                          \
    {                                                                                                            \
        .param_id = (PARAM), .param_type = (kUWB_DEBUGPARAMS_Type_au8), .param_value.param.param_len = (LENGTH), \
        .param_value.param.param_value = (uint8_t *)(ARRAY)                                                      \
    }
/**
 *   Device Configuration parameters supported in UWB API layer.
 */
typedef enum deviceConfig
{
    /** 0:DISABLE, 1:ENABLE */
    LOW_POWER_MODE = 0X01,
#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    /** This configuration is used to configure the wifi co-ex feature.
     *
     * - Octet[0]: Enable/Disable wifi co-ex feature
     *  - 0x00 : To Disable(default)
     *  - b3-b0: Enable/Disable functionality CoEx:
     *      - 0x2: Enable CoEx Interface with Debug Verbose only
     *      - 0x3: Enable CoEx Interface with Warnings Verbose only
     *      - 0x4: Enable CoEx Interface with both Debug and Warning Verbose
     *  - b4: CoEx Interface (GPIO/UART/One Wire) selection:
     *      - 0x0: GPIO Interface
     *      - Rest of the values are Reserved
     * - Octet[1]: Number of channels N Shall be more than or equal 1 (0 will be rejected by UWBS)
     *             N*4 octets to follow
     * - Octet[2]: Channel ID
     * - Octet[3]: MIN_GUARD_DURATION: Minimum gap in milliseconds between the end of previous active grant duration and next medium access request
     * - Octet[4]: MAX_GRANT_DURATION: Maximum duration for which the UWB can request for medium access
     * - Octet[5]: ADVANCED_GRANT_DURATION: Minimum preparation time in milliseconds required by the WLAN subsystem to
     *             relinquish the CoEx Medium for UWB subsystem usage.
     *             It shall be set to at least 6ms for GPIO based CoEx Interface.
     *             Ranging interval value in ms should be greater or equal to following expression:
     *             (ADVANCED GRANT DURATION + ROUND DURATION + MIN_GUARD_DURATION)
     *
     */
    WIFI_COEX_FEATURE = 0xF0,
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)

#if UWBFTR_AoA_FoV
    /** AOA calibration(4*8*4)
     * - 4 bytes value description:
     *  - bit31-AoA phase flip enable (default = 0),
     *  - bits [30:16]-Antenna spacing(default = 20mm),
     *  - bits [15:0]-PDoA offset 8 antenna pairs: 4 byte value repeated 8 times for each antenna pair 4 channels: 4*8
     * bytes repeated for 4 channels
     */
    AOA_CALIBRATION_CTRL = 0xE401,
#endif // UWBFTR_AoA_FoV
    /** DPD wakeup source
     * bit1: GPIO1, bit3: GPIO3 */
    DPD_WAKEUP_SRC = 0xE402,
#if !(UWBIOT_UWBD_SR2XXT)
    /** WTX count, wtx count should be greater than or equal to 20 and less than or equal to 120 */
    WTX_COUNT_CONFIG = 0xE403,
#endif //!(UWBIOT_UWBD_SR2XXT)

    /** DPD entry timeout in ms (default = 500ms)*/
    DPD_ENTRY_TIMEOUT = 0xE404,
#if UWBFTR_AoA_FoV
    /** This configuration is used to indicate whether the RX Antenna selection should take place w.r.t EF2 or GPIO14
     * (for Antenna switching)
     * - 0 : EF2 based Antenna selection (Default)
     * - 1 : GPIO14 based Antenna selection */
    GPIO_SELECTION_FOR_DUAL_AOA = 0xE406,
#endif // UWBFTR_AoA_FoV
    /** 0:DISABLE, 1:ENABLE */
    TX_BASE_BAND_CONFIG = 0xE426,
    /** DDFS tone config (4*8 bytes repeated for 4 channels)
     * - 18 bytes value description:
     *  - Octet[0]: channel number
     *  - Octet[1]: Tx antenna selection. Possible values are 1 or 2.
     *  - Octet[5:2]: Content of register TX_DDFS_TONE_0
     *  - Octet[9:6]: Content of register TX_DDFS_TONE_1
     *  - Octet[13:10]: Duration of the spur, in 124.8 MHz resolution (~ 8 ns)
     *  - Octet[14]: Content of register GAINVAL_SET
     *  - Octet[15]: Content of register DDFSGAINBYPASS_ENBL
     *  - Octet[17:16]: Periodicity of spur in terms of gap interval in the PER command.
     * - 4 Blocks: 18 Octets  repeated for each block
     *  - Octets[17:0] correspond to Block1
     *  - Octets[35:18] correspond to Block2
     *  - Octets[53:36] correspond to Block3
     *  - Octets[71:54] correspond to Block4 */
    DDFS_TONE_CONFIG = 0xE427,
    /** Preamble pulse shape setting
     * - Octet[0]: Preamble pulse shape id
     * - Octet[1]: Payload Tx pulse shape id
     * - Octet[2]: STS Tx pulse shape ID
     * - Octet[3]: DAC Stage Config
     *
     * Values:
     *  - Octet[0-2] =  [2(default), 30, 34, 36 and 37]
     *  - Octet[3] = Value is defined as below
     *      - bit0: To set the DAC gain
     *          - 0: Unchanged( UWBS Keeps previous assigned value)  .
     *          - 1: UWBS set to 0x24
     *      - bit1:  To set LPF( Tx DAC C)
     *          - 0: UWBS shall set to 0
     *          - 1: UWBS shall set to 0x5F
     *      - bit7-bit2: RFU
     * */
    TX_PULSE_SHAPE_CONFIG = 0xE428,
#if UWBIOT_UWBD_SR1XXT
    /**
     * - Octet[0]: Clock source option
     *  - b[0]: RF Clock option
     *      - [0]: Use on board crystal (default)
     *      - [1]: Use external Clock
     *  - b[1]: Slow clock option
     *      - [0]: Use on board crystal
     *      - [1]: Use external 32.768 KHz Clock
     *  - b[2:7]: RFU
     * - Octet[1]: Crystal Option for RF clock
     *  - b[0]: Crystal Option
     *      - [0]: Use 38.4MHz crystal (default)
     *      - [1]: Use 26 MHz crystal
     *  - b[1:7]: RFU
     */
    CLK_CONFIG_CTRL = 0xE430,
#endif //UWBIOT_UWBD_SR1XXT
    /** Parameter is used to set host capability of handling max UCI payload.
     *  FW shall use this parameter to send the UCI responses/notification to host.
     *  FW shall use PBF bit if UCI payload goes more than HOST_MAX_UCI_PAYLOAD_LENGTH size.
     *  255<= HOST_MAX_UCI_PAYLOAD_LENGTH<= UWBS_MAX_UCI_PAYLOAD_LENGTH(capability parameter)
     *  (Default = 255) */
    HOST_MAX_UCI_PAYLOAD_LENGTH = 0xE431,
    /**
     * - 0x00 = FIRA generic Response/Notification (Default)
     * - 0x01 = Vendor extended Response/Notification
     */
    NXP_EXTENDED_NTF_CONFIG = 0xE433,
#if UWBIOT_UWBD_SR1XXT
    /** Maximum waiting time until clock is present. The value is given in microseconds and
     *  defaults to 1000us.
     *  If Octet [0] of CLK_CONFIG_CTRL is set to 0 (on board crystal), this time is indicating
     *  the maximum waiting time until XTAL oscillator becomes stable.
     *  If Octet [0] of CLK_CONFIG_CTRL is set to 1 (external clock), this time is indicating
     *  the guard time between clock request GPIO (GPIO1) going high until the platform has
     *  to provide a stable clock.
     */
    CLOCK_PRESENT_WAITING_TIME = 0xE434,
#endif// UWBIOT_UWBD_SR1XXT
    /** Negative offset when Rx should be enabled to receive the first message
    of a ranging round on Controlee compared to expected reception time. Default = 100 us */
    INITIAL_RX_ON_OFFSET_ABS = 0xE435,
    /** Negative offset when Rx should be enabled to receive the first message
    of a ranging round on Controlee compared to expected reception time. Default = 100 ppm */
    INITIAL_RX_ON_OFFSET_REL = 0xE436,
#if UWBIOT_UWBD_SR2XXT
    /**
     * - Octet[0] : INPUT_CLK_CTRL
     *  - bit[0]: 32kHz clock source
     *      - 0: Use on board crystal (default)
     *      - 1: Use external 32k clock
     *  - bit[2:1]: External 32k clock waveform
     *      - 0b00: Sinus (default)
     *      - 0b01: 1.8V square
     *      - 0b10: 1.2V square
     *  - bit[3]: RF clock source
     *      - 0: Use on board crystal (default)
     *      - 1: Use external clock
     *  - bit[5:4]: RF clock frequency
     *      - 0b00: Use 38.4MHz
     *      - 0b01: Use 26MHz
     *      - 0b10: Use 19.2MHz
     *  - bit[6]: External clock waveform
     *      - 0: Sinus (default)
     *      - 1: Square
     *  - bit[7]: RFU
     * - Octet[2:1] : SLOW_CLK_WAITING_TIME Maximum waiting time in us until 32.768 kHz clock is present. Default:
     * 1000us.
     * - Octet[4:3] : RF_CLK_WAITING_TIME Maximum waiting time in us until RF clock is present. Default: 1000us.
     */
    CLK_CONFIG_CTRL = 0xE43A,
    /**
     * Allow to override the TX_BASEBAND_CONFIG parameter for specific pulse shapes.
     * - Octet[0]: DDFS config for FiRa PS
     * - Octet[1]: DDFS config for CCC0 PS
     * - Octet[2]: DDFS config for CCC1 PS
     * - Octet[3]: DDFS config for CCC2 PS
     *  (Default: 0x00 00 00 00 for Octet[0:3])
     *
     * - Content of each byte:
     *  - bit[0]: override DDFS config
     *   - 0: No override
     *   - 1: TX_BASEBAND_CONFIG is overridden for this pulse shape (DDFS config will depends on bit[4:1]
     *  - bit[1]: DDFS config for SP0 frame
     *   - 0: Disabled
     *   - 1: Enabled
     *  - bit[2]: DDFS config for SP1 frame
     *   - 0: Disabled
     *   - 1: Enabled
     *  - bit[3]: RFU
     *  - bit[4]: DDFS config for SP3 frame
     *   - 0: Disabled
     *   - 1: Enabled
     *  - bit[7:5] RFU
     */
    DDFS_CONFIG_PER_PULSE_SHAPE = 0xE43B,
#endif // UWBIOT_UWBD_SR2XXT
#if UWBFTR_AoA_FoV
    /** PDoA average of vertical sweeps for all the horizontal angles and for all the IDs from 0xE4 0x40 to E4 0x43, in
     * that order. All are signed PDoA values in Q9.7 (2 bytes, little-endian) format.
     * - Octet[1:0]: Avg. of PDoAs in octet[21:0] of 0xE4 0x40
     * - Octet[3:2]: Avg. of PDoAs in octet[43:22] of 0xE4 0x40
     * - Octet[5:4]: Avg. of PDoAs in octet[65:44] of 0xE4 0x40
     * - Octet[7:6]: Avg. of PDoAs in octet[87:66] of 0xE4 0x40
     * - Octet[9:8]: Avg. of PDoAs in octet[109:88] of 0xE4 0x40
     * - Octet[11:10]: Avg. of PDoAs in octet[131:110] of 0xE4 0x40
     * - Octet[13:12]: Avg. of PDoAs in octet[153:132] of 0xE4 0x40
     * - Octet[15:14]: Avg. of PDoAs in octet[175:154] of 0xE4 0x40
     * - Octet[17:16]: Avg. of PDoAs in octet[197:176] of 0xE4 0x40
     * - Octet[19:18]: Avg. of PDoAs in octet[219:198] of 0xE4 0x40
     * - Octet[21:20]: Avg. of PDoAs in octet[241:220] of 0xE4 0x40 Similarly,
     * - Octet[43:22]: for 0xE4 0x41 Octet[65:44]: for 0xE4 0x42
     * - Octet[175:154]: for 0xE4 0x43 */
    AOA_CALIB_CTRL_AVG_PDOA = 0xE444,
    /*  PDoA threshold values for all the IDs from 0xE4 0x40 to E4 0x47, in that order.
     *  All are signed PDoA values in Q9.7 (2 bytes, little-endian) format.
     **/
    AOA_CALIB_CTRL_THRESHOLD_PDOA,
    /** PdoA Calibration Table Definition :
     *  - Octet[0] - Calibration Step Size : The calibration table step size in degrees which indicates the step size
     * between two consecutive points.
     *      - Allowed Range : 10° to 15° (default = 12°)
     *      - Example : For maximum span of 60°, with step size 12° then the calibration table would look like[-60°,
     * -48°, -36° , ..., 0°, ..., 36°, 48°, 60°].
     *  - Octet [1] - Number of Steps: The number of calibration steps needs to be an odd number.
     *      - Allowed Range : 3<=M<=21(to include 0°)(default = 11)
     *      - Example : With number of step size as 10° and number of steps as 13, the achieved calibration span is -60,
     * -50, -40, ...,  -10, 0, 10, ..., 40, 50, 60
     *
     * @note
     *  - Total Calibration Span = ((Number of Steps - 1) * Step Size). Example :
     *      - If steps are 11 and step size is 12° then total span is 120°(-60° to 60° including 0°).
     *      - If steps are 13 and step size is 15° then total span is 180°(-90° to 90° including 0°).
     */
    PDOA_CALIB_TABLE_DEFINE = 0xE446,
#endif // UWBFTR_AoA_FoV
    /**
     * To define/create antenna identifier for RX
     * - Octet[0] : Number of Entries. (N). This must be equal to "MAX_N".
     *
     * Array of entries:
     * - Octet[X + 0] : RX Antennae ID.
     *  - Index of the Antennae.
     *  - Value 0 shall be Invalid.
     *  - Value shall from 1 to MAX_N
     *
     * - Octet[X + 2, X + 1]: GPIO Filter Mask
     *  - This mask defines which GPIOs shall be changed during the state transition, if a GPIO bit is set to 0 the GPIO
     * shall not change its state.
     *  - It's a 2 byte value in Little Endian format.
     *
     * - Octet[X + 4, X + 3]: GPIO State / Value
     *  - This mask defines the GPIO state, if the corresponding GPIO bit is 0 in the GPIO Filter mask, the state shall
     * be ignored and not changed It's a 2 byte value in Little Endian format.
     *
     */
    ANTENNA_RX_IDX_DEFINE = 0xE460,

#if UWBIOT_UWBD_SR1XXT
    /**
     * To define/create antenna identifier for TX
     *
     * - Octet[0] : N Entries.
     *
     * Array of entries:
     * - In case, same Antenna is used for Tx/Rx Use the same ID.
     * - In case few GPIOs have to be switched for toggling,
     * - Octet[1] and Octet[2] would be different when TX/RX antennae are defined.
     *
     * - Octet[0] : Antennae ID.
     *  - Index of the Antennae.
     *  - Value 0 shall be Invalid.
     *  - Value shall from 1 to N.
     *
     * - Octet[1]: GPIO Filter Mask
     *  - This mask defines which GPIOs shall be changed during the state transition, if a GPIO bit is set to 0 the GPIO
     * shall not change its state.
     *
     * - Octet[2]: GPIO State / Value
     *  - This mask defines the GPIO state, if the corresponding GPIO bit is 0 in the GPIO Filter mask, the state shall
     * be ignored and not changed
     *
     * - Octet[6:3] Group Delay
     *
     * Max number of entries per product variant for max value of N is same as ANTENNA_RX_IDX_DEFINE
     * For Calibration of TX Power, use TX_POWER from Calibration Parameters
     * */
    ANTENNA_TX_IDX_DEFINE = 0xE461,
#endif /* UWBIOT_UWBD_SR1XXT */

    /** To define/create antenna identifier for RX Pair
     *
     * - Octet[0] : N Entries.
     *
     * Array of entries:
     * - This may be an H or V Combination. Repeat of [
     * - Octet[0] : Antennae PAIR ID
     *  - This IDx is used along with ANTENNAE_CONFIGURATION(Session Config) and for reporting.
     *  - ID 0 shall not be used.
     *  - For non-scanning mode/for backward compatibility, Default ID for Horizontal has to be 1.
     *  - And ID for Vertical has to be 2.
     *  - Use Odd Values for Horizonal Pair And Even Values for Vertical Paris.
     *  - So, FW can decide to move to lower or higher Pair ID.
     *  - FW can also use IDs X, X+1 to identify which ID is making a group for 3D Configuration.
     *
     * - Octet[1] : RX1 Antennae ID as defined by ANTENNAE_RX_IDX_DEFINE
     *
     * - Octet[2] : RX2 Antennae ID as defined by ANTENNAE_RX_IDX_DEFINE.
     *
     * - Octet[4:3]: PDOA Zero Offset
     *  - 2 bytes PDOA1_OFFSET, PDOA2_OFFSET
     *
     * - Octet[6:5] : Relative Angle of View / Field of View.
     *  - Assuming we have 4 Antennae pairs symmetrically placed on a UWB System.
     *  - For a given selected Antennae pair, the peer object may be at 0°, but reported AoA has to be either 0°, 90°,
     * 180° or 270° depending on this relative Angle of View.
     *
     * When this is set to 0, then Host has to use RX Antennae info and derive the relative angle.
     * When this is set to 0, the FW has no IDEA which antennae group to switch to in case of antennae moves out of some
     * configuration.
     *
     * Max number of entries per product variant for max value of N is same as ANTENNA_RX_IDX_DEFINE
     * */
    ANTENNAE_RX_PAIR_DEFINE = 0xE462,

#if UWBIOT_UWBD_SR2XXT
    /** Define TX antenna Identifiers
    *
    * - Octet[0] : Number of Entries (N)
    *   Must be between 1 and "MAX_N".
    * [
    *   - Octet[X+0] : TX Antenna ID
    *       - Must start from 1
    *   - Octet[X+1] : TX Antenna port
    *       – 0x1: TRA1 (Not supported on SR200S and SR200D)
    *       – 0x2: TRA2
    *   - Octet[X+3:X+2] : GPIO Filter Mask
    *       - If a bit is set to 1, it enables the associated GPIO (2 byte value in Little Endian format)
    *   - Octet[X+5:X+4] : GPIO Value
    *       - If corresponding bit in filter mask is set, it defines the GPIO state.
    *       - If corresponding bit in filter mask is not set, it’s ignored (2 byte value in Little Endian format).
    * ] (for each antenna TX ID)
    *
    * \see ANTENNAS_SELECTION_GPIO_BIT_MASK for bit masks and values.
    **/
    ANTENNA_TX_IDX_DEFINE = 0xE463,
#endif /* UWBIOT_UWBD_SR2XXT */

    /** End of device Configs*/
    END_OF_SUPPORTED_DEVICE_CONFIGS,
} eDeviceConfig;

/** Antenna Configuration and slection mode */
typedef enum
{
    /* For Time Of Arrival */
    kUWBAntCfgRxMode_ToA_Mode = 0,
    /* For Angle Of Arrival */
    kUWBAntCfgRxMode_AoA_Mode = 1,
    /** For Rx RADAR */
    kUWBAntCfgRxMode_Radar_Mode,
    /**For Rx TOA RFM*/
    kUWBAntCfgRxMode_ToA_Rfm_Mode,
    /**For Rx AOA RFM*/
    kUWBAntCfgRxMode_AoA_Rfm_Mode,
    /** ToA mode for CSA */
    kUWBAntCfgRxMode_CSA_ToA_Mode,
    /** AoA mode for CSA */
    kUWBAntCfgRxMode_CSA_AoA_Mode,

} kUWBAntCfgRxMode_t;

/**
 * @brief  Structure lists out the UWB Device Info Parameters.
 */
typedef struct phUwbDevInfo
{
    /** Mac Major version */
    uint8_t macMajorVersion;
    /** Mac Minor version */
    uint8_t macMinorMaintenanceVersion;
    /** Phy Major version */
    uint8_t phyMajorVersion;
    /** Phy Minor version */
    uint8_t phyMinorMaintenanceVersion;
    /** Device Name length*/
    uint8_t devNameLen;
    /** Device Name */
    uint8_t devName[48];
    /** Fw Major Version */
    uint8_t fwMajor;
    /** Fw Minor Version */
    uint8_t fwMinor;
    /** Fw Rc Version */
    uint8_t fwRc;
    /** Vendor UCI Major Version */
    uint8_t vendorUciMajor;
    /** Vendor UCI Minor Version */
    uint8_t vendorUciMinor;
    /** Vendor UCI Patch Version */
    uint8_t vendorUciPatch;
    /** UWB Chip Id */
    uint8_t uwbChipId[MAX_UWB_CHIP_ID_LEN];
    /** Max PPM Value*/
    uint8_t maxPpmValue;
    /** TX Power Value*/
    int16_t txPowerValue;
    /** Parameter to indicate the lifecycle of device.*/
    uint32_t lifecycle;
    /** MW Major Version */
    uint8_t mwMajor;
    /** MW Minor Version */
    uint8_t mwMinor;
    /** Mw Rc Version */
    uint8_t mwRc;
    /** Vendor FIRA UCI generic major version */
    uint8_t uciGenericMajor;
    /** Vendor FIRA UCI generic minor version */
    uint8_t uciGenericMinorMaintenanceVersion;
    /** Vendor FIRA UCI generic patch version */
    uint8_t uciGenericPatch;
    /** Vendor FIRA UCI test major version */
    uint8_t uciTestMajor;
    /** Vendor FIRA UCI test minor version */
    uint8_t uciTestMinor;
    /** Vendor FIRA UCI test patch version */
    uint8_t uciTestPatch;
    /** Parameter to indicate git hash .
     *    - Octet[15-0] = Git hash (coded in ASCII)
     *    - Octet[16] = working tree state
     *      - 'z': dirty;
     *      - '-': clean;
     */
    uint8_t fwGitHash[FW_GIT_HASH_LEN];
    /** Fw Boot Mode */
    uint8_t fwBootMode;
#if UWBFTR_CCC
    /** UCI CCC VERSION */
    uint8_t uciCccVersion[MAX_UCI_CCC_VERSION_LEN];
    /** CCC VERSION */
    uint8_t cccVersion[MAX_CCC_VERSION_LEN];
#endif // UWBFTR_CCC
#if UWBFTR_CSA
    /** Aliro Spec VERSION */
    uint8_t aliroSpecVersion[MAX_ALIRO_SPEC_VERSION_LEN];
#endif // UWBFTR_CSA
} phUwbDevInfo_t;

/**
 * @brief Enumeration for device calibration states
 *
 * This enumeration defines the possible calibration states of a UWB device.
 * It is used to indicate whether the device has been properly calibrated or not.
 *
 * @see CHIP_CALIBRATION_STATE
 */
typedef enum
{
    eCalibState_DEVICE_NOT_CALIBRATED = 0x00, ///< If DO_CHIP_CALIBRATION_CMD was not processed by UWBS
    eCalibState_DEVICE_CALIBRATED     = 0x01, ///< If DO_CHIP_CALIBRATION_CMD was processed by UWBS
} eCalibStates_t;

/**
 *  @brief Calibrations Configuration parameters supported in UWB API layer.
 */
typedef enum calibParam
{
    /** Chip calibration
     *  Do_Chip_Calibration_Cmd triggers a write operation on SRnxx’s Flash memory
     *
     *  Value determined during calibration process and this parameter is channel dependent.
     *  Channel number to be provide in calibration commands to set this parameter.
     *
     *   - bits[0-14] : Calibration code
     *   - bit[15]    : Calibration status as below
     *                  - 0: Calibration failure
     *                  - 1: Calibration success
     *
     *  Return the calibration outcome per channel. This parameter is channel dependent.
     *   - bit[8:0]    : Calibration code
     *   - bit[13:9]   : RFU
     *   - bit[15:14]  : Calibration status as below
     *                  - 0b10 : Calibration is valid
     *                  - Other: Calibration is invalid
     **/
    CHIP_CALIBRATION = 0x00,

    /** Channel independent and remains same for each channel and channel number in calibration command shall be ignored by UWBS.
     *
     *  @note HELIOS-1
     *  For Board Variant: [0x2A, 0x03]
     *      - Octet [0]  : Number of registers (must be 0x03)
     *      - Octet [2-1]: 38.4 MHz XTAL CAP1 (Default: 0x13)
     *      - Octet [4-3]: 38.4 MHz XTAL CAP2 (Default: 0x13)
     *      - Octet [6-5]: 38.4 MHz XTAL GM CURRENT CONTROL (Default: 0x30)
     *
     *  Rest all variants (Except [0x2A, 0x03])
     *      - Octet [0]  : Number of registers (must be 0x03)
     *      - Octet [2-1]: 38.4 MHz XTAL CAP1 (Default: 0x0F)
     *      - Octet [4-3]: 38.4 MHz XTAL CAP2 (Default: 0x0F)
     *      - Octet [6-5]: 38.4 MHz XTAL GM CURRENT CONTROL (Default: 0x21)
     *
     *  Values : [0x00-0xFF] for 38.4 MHz XTAL CAP
     *  Values : [0x00-0x3F] for 38.4 MHz XTAL GM
     *
     * @note Stored in SR2XX’s Flash
     *
     * Defines the capacitors values applied to 38.4MHz XTAL. Channel independent and remains same for each channel.
     *      - Octet [0]  : Number of registers (must be 0x03)
     *      - Octet [2-1]: 38.4 MHz XTAL CAP1
     *      - Octet [4-3]: 38.4 MHz XTAL CAP2
     *      - Octet [6-5]: 38.4 MHz XTAL GM CURRENT CTRL
     *
     *  Values : [0x00-0xFF] for 38.4 MHz XTAL CAP
     *  Values : [0x00-0x3F] for 38.4 MHz XTAL GM
     **/
    RF_CLK_ACCURACY_CALIB = 0x01,

    /** Delay Calibration for each RX Antenna. This parameter is channel dependent. Total of 1 + (N*3) Octets.
     *  @note *** Stored in SR2XX’s Flash ***
     *
     *  - Octet[0]: Number of Entries (Must be greater than 0)
     *
     *  iteration - Start
     *      - Octet[1]   : RX Antennas IDs as defined by ANTENNA_RX_IDX_DEFINE
     *      - Octet[3-2] : Octets each: RX Delay (unsigned Q14.2)
     *
     *  iteration - End
     *
     * (Default: 0x0000 for all RX antenna IDs)
     *
     *  @note: Delay calib is used and effective only for the Rx antenna, that is part of Rx Antenna Pair
     *  that is used for receiving the STS Segment. As of now, only vertical pair is used and it can change in future.
     *  Function revisions may choose to use multiple antennaes for multiple STS Segments.
     *
     **/
    RX_ANT_DELAY_CALIB = 0x02,

#if UWBFTR_AoA_FoV
    /** PDOA Offset Calibration - This parameter is channel dependent. Total of 1 + N*(1+2) Octets.
     *  @note Channel_ID 5 setting is applied to channels 5 and 8. Channel_ID 9 setting is applied to channels 6 and 9.
     *
     *   - Octet[0]: Number of Entries (Must be greater than 0) (Depends on available RAM)
     *
     *  Next octets would be read as set of 3 octets for number of entries reported in octet[0] above.
     *
     *  iteration - Start
     *      - Octet[1]   : RX Antennas PAIR IDs as defind by ANTENNAS_RX_PAIR_DEFINE
     *      - Octet[3-2] : PDoA Offsets. (signed value in Q9.7 format)
     *
     *  iteration - End
     *
     * (Default: 0x0000 for all RX)
     *
     */
    PDOA_OFFSET_CALIB = 0x03,
#endif // UWBFTR_AoA_FoV

    /** TX POWER - This parameter is channel dependent. Total of 1 + (N*5) Octets.
     *
     *  - Octet[0] : Number of Entries (Must be greater than 0).
     *
     *  Next octets would be read as set of 3 octets for number of entries reported in octet[0] above.
     *
     *  iteration - Start
     *      - Octet[1]   : TX Antenna IDs as defind by ANTENNAS_TX_IDX_DEFINE
     *      - Octet[3-2] : TX_POWER_DELTA_PEAK
     *                  - If TX_ADAPTIVE_PAYLOAD_POWER is enabled, this value represents the delta peak
     *                    ie : PEAK_ID - RMS_ID. This value is a delta and comes from calibration process,
     *                    It ranges from 0 (max power) to 127 (min power) with steps of 0.25.
     *                  - If TX_ADAPTIVE_PAYLOAD_POWER is not enabled, this value has no specific use.
     *      - Octet[5-4] : TX_POWER_ID_RMS
     *                  - If TX_ADAPTIVE_PAYLOAD_POWER is enabled, this value come from RMS calibration as RMS_ID
     *                  - If TX_ADAPTIVE_PAYLOAD_POWER is not enabled, this value serves as a gain index for TX power
     *                    control. It ranges from 0 (max power) to 127 (min power) with steps of 0.25.
     *
     *  iteration - End (Default value for all: 0x00)
     *
     * @note: TEST_LOOPBACK_CMD is rejected if TX_POWER_ID_RMS is below than 80
     **/
    TX_POWER_PER_ANTENNA = 0x04,

    /** Antenna phase flip and spacing. This parameter is channel dependent. Total of 1+(N*3) Octets.
     *
     *  - Octet[0]: Number of Entries (Must be greater than 0)
     *
     *  Next octets would be read as set of 3 octets for number of entries reported in octet[0] above.
     *
     *  iteration - Start
     *      - Octet[1]   : RX Antenna Pair ID
     *      - Octet[3-2] :
     *                  - Bit 15 Phase flip (1 bit)
     *                  - Bit 14:0 Antenna spacing (15 bits in Q6.9 format)
     *
     *  iteration - End (Default: 0x0028 for all RX antenna pair IDs)
     *
     **/
    AOA_PHASEFLIP_ANTSPACING = 0x05,

    /** Channel independent (same value is applied for each channel):
     *      - Octet[0] : 32 kHz XTAL CAP CRTL
     *                 - Default: 0x03(HELIOS-2)
     *                 - Default: 0x02(YUKON)
     *                 - Value Range: [0x00 : 0x1F]
     *      - Octet[1] : 32 kHz XTAL GM CURRENT CTRL
     *                 - Default: 0x00
     *                 - Value Range: [0x00 : 0x07]
     **/
    SYSTEM_CLK_ACCURACY_CALIB = 0x06,

    /**
     * Octet[1] Number of entries N
     * Octet[2+n*4] TX antenna ID as defined by ANTENNA_TX_IDX_DEFINE
     * Octet[3+n*4]: RX antennas ID as defined by ANTENNA_RX_IDX_DEFINE
     * Octet[4+n*4]: delay calibration data
     * Octet[5+n*4]: width calibration data
     **/
    RADAR_LO_GATING = 0x08,

    /** 16-bytes string defining the platform name - Channel independent
     *  @note *** Stored in SR2XX’s and Flash ***
     **/
    PLATFORM_ID = 0x5C,

    /** Version number of the secure parameters - Channel independent
     *  @note *** Stored in SR2XX’s and Flash ***
     **/
    CONFIG_VERSION = 0x5D,

    /** Channel independent.
     *  1 byte config to enable/disable the SE_COMM_DATA_NTF.
     *      - 0x00: Disable
     *      - 0x01: Enable
     *
     * @note: Allowed in all lifecycles.
     **/
    DBG_SE_DUMP = 0x5E,

    /** MANUAL_TX_POW_CTRL - Refer Tx Power Control parameter for details
     *  For Helios 1
     *      - Octet [0]: PA_GAIN (default: 0x00)
     *      - Octet [1]: PA_DRIVE_GAIN (default: 0x00)
     *      - Octet [2]: DIG_GAIN (default: 0x00)
     *      - Octet [3]: TX_DAC_GAIN (default: 0x38)
     *      - Octet [4]: RFU
     *
     *  For Helios 2
     *      - Octet[0] : TX_PA_GAIN
     *      - Octet[1] : TX_PPA_GAIN
     *      - Octet[2] : TX_DIG_GAIN
     *      - Octet[3] : DAC_GAIN
     *      - Octet[4] : TX_MIX_GAIN
     *
     **/
    MANUAL_TX_POW_CTRL = 0x60,

#if UWBIOT_UWBD_SR1XXT
    /** TX PA and PPA setting
     *  - Octet[0]: PA Output capacitor control
     *  - Octet[1]: TX PA Driver Output capacitor control
     *
     *  Allowed range of values is 0x00 to 0x1F
     *
     *  Default value of this parameter W.R.T channels:
     *      - Channel 5: 0x0814
     *      - Channel 6: 0x010C
     *      - Channel 8: 0x0004
     *      - Channel 9: 0x0000
     *
     **/
    PA_PPA_CALIB_CTRL = 0x61,
#endif // UWBIOT_UWBD_SR1XXT
#if UWBFTR_AoA_FoV

    /** PDOA Calibration tables - Added for 360 FoV. This is of 1 + N*(1 + S*S*2) Octets.
     *
     *  - Octet[0] : No of entries, it shall be set to 1 for Set Calibration Cmd. (Refer to a) of Note for this
     *  limitation.) Next octets would be read as set of (1 + S*S*2) octets for number of entries reported in octet[0]
     *  above.
     *
     *  iteration - Start
     *      Octet[1]   : RX Pair Antennas ID as defined earlier by ANTENNAS_RX_PAIR_DEFINE
     *      Octet[2-M] : PDoA calibration table for specified RX Pair Antennas ID.
     *
     *  iteration - End
     *
     *  For details on the format refer AOA_CALIB_CTRL_RX_ANT_PAIR_1_CH5.
     *  The older entries would get overwritten, if more than supported data is uploaded to the UWBS.
     *  Refer specification for max supported calibration tables per channel per antennas pair.
     *  So, for SRnxx, 2 Channels X 2 Pairs X (S*S*2) is pre-allocated.
     *
     *  S is number of steps is Octet[1] of PDOA_CALIB_TABLE_DEFINE.
     *  Allowed Range: 3<= S<= 17 (to include 0o(default : 11)
     *  Allowed Range: 3<= S <= 11 (to include 0o(default : 11)
     *
     *  N = 1 Always
     *
     *  @note:
     *      a) In order to support Hosts that can not send more than 255 + 4 bytes, this UCI interface can
     *         only be used to set PDoA calibration table for one RX Pair Antennas ID at a time.
     *
     *      b) The Get Calibration Cmd response for this ID returns the total number of "RX Pair Antennas IDs"
     *         for which PDOA calibration table is set in Octet[0].
     **/
    AOA_ANTENNAS_PDOA_CALIB = 0x62,

#if UWBIOT_UWBD_SR1XXT
    /** Multi point ('N') PDoA manufacturing offset calibration - Added for 360 FoV. Supersedes AOA_MULTIPOINT_CALIB
     *  This is of 1 + M(1 + *N*4)) Octets.
     *
     *  Multi point ('N') PDoA manufacturing offset calibration command for each of 'M' Rx Antenna Pairs IDs.
     *  Each of the N points PDoA manufacturing value corrects the PDoA calibration value for specified coordinate
     *  in the PDoA calibration table. Each point is of 4 octet value and the description for the format of each point
     *  is specified below. The max size of N is limited by max Rx Antenna Pairs that is configured and
     *  the max possible command length for this command.
     *
     *  - Octet[0]: Number of Entries of Rx Antenna Pair IDs ('M')
     *
     *  iteration - Start
     *      - Octet[1] : RX Antennas IDs as defined earlier by ANTENNAS_RX_PAIR_DEFINE
     *      N PDoA Manufacturing Calibration Points Repeated N * 4 octets per Rx Antenna Pair
     *
     *      iteration - Start
     *          - Octet[0]  Azimuth co-ordinate
     *
     *                        The azimuth coordinate of the additional calibration point -128° offset
     *                        (for getting negative and positive calibration points), the unit is ° (LSB is one °).
     *                        The point needs to have the position of one calibration point within the table.
     *
     *          - Octet[1]  Eelevation Co-Oridnate.
     *
     *                        The elevation coordinate of the additional calibration point -128° offset (for getting
     *                        negative and positive calibration points), the unit is ° (LSB is one °). The point needs
     *                        to have the position of one calibration point within the table.
     *
     *          - Octets[3,2] PDoA measurement
     *
     *                        The PDoA measurement at this point in Q9.7 Format. (In Little Endian Format)
     *
     *      iteration - End - Repeat of same 4 octets for the remaining points.
     *
     *  iteration - End
     *
     *  @note Only Set Calib is supported, Get Calibration is not supported for this parameter.
     */
    AOA_ANTENNAS_MULTIPOINT_CALIB = 0x63,
#endif // UWBIOT_UWBD_SR1XXT
#endif // UWBFTR_AoA_FoV
    /** Delay Calibration of TX Part of Antenna. Thsi is of 1 + (N*3) Octets.
     *
     *  - Octet[0]: Number of Entries (Must be greater than 0)
     *
     *  iteration - Start
     *      - Octet[1] : TX Antennas IDs as defined by ANTENNA_TX_IDX_DEFINE
     *      - Octets[3-2] : TX Delay offset (signed Q14.2)
     *
     *  iteration - End (Repeat)
     *
     **/
    TX_ANT_DELAY_CALIB = 0x64,

#if UWBFTR_AoA_FoV
    /** Zero offset Manufacturing PDOA Calibration. This is of 1 + (N*1) + (N*2) Octets
     *
     *  - Octet[0]: Number of Entries (Must be greater than 0) (Depends on available RAM)
     *
     *  iteration - Start
     *      - Octet[1]   : RX Antennas PAIR IDs as defind by ANTENNAS_RX_PAIR_DEFINE
     *      - Octet[3-2] : Manufacture PDOA1 Offset
     *
     *  iteration - End (Repeat)
     *
     *  @note Supersedes Antenna Spacing enable in "AOA_CALIBRATION_CTRL". This value (PDOA_MANUFACT_ZERO_OFFSET_CALIB)
     *  will have higher precedence as compared to this PDOA_OFFSET_CALIB.
     **/
    PDOA_MANUFACT_ZERO_OFFSET_CALIB = 0x65,

    /** AoA Threshold PDOA. This is of 1 + (N*1) + (N*2) Octets.
     *
     *  - Octet[0]: Number of Entries (Must be greater than 0)
     *
     *  iteration - Start
     *      - Octet[1]    : RX Antennas PAIR IDs as defind by ANTENNAS_RX_PAIR_DEFINE
     *      - Octets[3-2] : Threshold Values
     *
     *  iteration - End (Repeat)
     *
     *  @note Supersedes Threshold PDoA in "AOA_CALIB_CTRL_THRESHOLD_PDOA"
     **/
    AOA_THRESHOLD_PDOA = 0x66,

#endif // UWBFTR_AoA_FoV
    /** TX temperature compensation per antenna. This parameter is channel dependent. This is of 1 + N*(1+8) Octets
     *
     *  - Octet[0]: Number of Entries (Must be greater than 0)
     *
     *  iteration - Start
     *      - Octet[1] : TX Antenna IDs as defind by ANTENNAS_TX_IDX_DEFINE
     *      - Octet[2] : RANGE1_TX_POWER_UPPER_BOUND
     *      - Octet[3] : RANGE1_TX_POWER_GAIN_OFFSET
     *      - Octet[4] : RANGE2_TX_POWER_UPPER_BOUND
     *      - Octet[5] : RANGE2_TX_POWER_GAIN_OFFSET
     *      - Octet[6] : RANGE3_TX_POWER_UPPER_BOUND
     *      - Octet[7] : RANGE3_TX_POWER_GAIN_OFFSET
     *      - Octet[8] : RANGE4_TX_POWER_UPPER_BOUND
     *      - Octet[9] : RANGE4_TX_POWER_GAIN_OFFSET
     *
     *  iteration - End (Repeat)
     *
     *  @note
     *      TX_POWER_UPPER_BOUND:Upper bound for the temperature value. It is a signed number to allow the configuration
     * of negative temperature Default value: 0x80(Disable) TX_POWER_GAIN_OFFSET: Offset to be applied on the Tx power
     * gain table for a specific temperature range. it's a signed number. Default value : 0x00
     *
     *  Associated offset from TX_POWER_GAIN_OFFSET will be applied if measured temperature is below the associated
     * TX_POWER_UPPER_BOUND.
     */
    TX_TEMPERATURE_COMP_PER_ANTENNA = 0x67,

    /** RSSI Offset per RX Antenna for High Power - Channel dependent. This is of 1 + (N*1) Octets.
     *
     *  - Octet[0]: Number of Entries (Must be greater than 0)
     *
     *  iteration - Start
     *      - Octet[1] : RX Antenna IDs as defind by ANTENNAS_RX_IDX_DEFINE
     *      - Octet[2] : RSSI Calib (value in dB)
     *
     *  iteration - End (Repeat)
     *
     * Default value for all: 0x00
     *
     * It is an unsigned value which will be substracted to the RSSI value computed by the FW
     **/
    RSSI_CALIB_CONSTANT_PER_ANTENNA = 0x69,

    /** Calibration parameter for reducing the TX Loft
     *  - Octet[0] : TX_DAC_OFFSET_I_SET (2’s complement coded on 8 bits)
     *  - Octet[1] : TX_DAC_OFFSET_Q_SET (2’s complement coded on 8 bits)
     *  - Octet[2] : TX_DC_OFFSET_RE (2’s complement coded on 8 bits)
     *  - Octet[3] : TX_DC_OFFSET_IM (2’s complement coded on 8 bits)
     *
     **/
    TRA2_LOFT_CALIB = 0x80,
    TRA1_LOFT_CALIB = 0x81,
    /** On Get calib, Indicates if device is calibrated via DO_CHIP_CALIBRATION_CMD.
     *
     * @par Possible Values:
     * - 0x00 = DEVICE_NOT_CALIBRATED
     * - 0x01 = DEVICE_CALIBRATED
     *
     * @see eCalibStates_t
     * @note This is a read-only parameter
     */
    CHIP_CALIBRATION_STATE = 0x82,
    /** Determine the FoM Cutoff Angle
     *  - Octet [0] : Number of Entries (N)
     * iteration - Start
     *  - Octet [1] : Rx Antenna Pair ID as defined in ANTENNAS_RX_PAIR_DEFINE
     *  - Octet [2] : Lower Cutoff Angle in degrees.(Default : -55deg which is 0xC9).
     *  - Octet [3] : Higher Cutoff Angle in degrees.(Default : +55deg which is 0x37).
     * iteration - End (Repeat)
     */
    FOM_ANGLE_CUTOFF = 0x83,
#if UWBFTR_AoA_FoV
    /** This parameter is used to set the PDoA Calibration Table for 90 Fov*/
    AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT = 0xE000,
#endif // UWBFTR_AoA_FoV
} eCalibParam;

/**
 *  @brief Calibrations Configuration parameters supported in UWB API layer.
 */
typedef enum otpCalibParam
{
    /** CHIP CALIBRATIONL Calibration, channel dependent */
    OTP_CALIB_CHIP_CALIBRATION = 0x00,
    /** TX POWER Calibration, channel and antenna dependent */
    OTP_CALIB_TX_POWER = 0x01,
    /** 38.4MHz XTAL, channel and antenna Independent */
    OTP_CALIB_RF_XTAL_CAP = 0x02,
    /** RSSI Calibration, channel and antenna dependent */
    OTP_CALIB_RSSI_CALIB_CONST1 = 0x03,
    /** RSSI Calibration, channel and antenna dependent */
    OTP_CALIB_RSSI_CALIB_CONST2 = 0x04,
    /** rfu */
    OTP_CALIB_RFU1 = 0x05,
    /** power control parameters */
    OTP_CALIB_MANUAL_TX_POW_CTRL = 0x06,
    /** rfu */
    OTP_CALIB_RFU2 = 0x07,
    /** PA_PPA Calibration control */
    OTP_CALIB_PAPPPA_CALIB_CTRL = 0x08,
    /** Tx Temperature Compensation */
    OTP_CALIB_TX_TEMPARATURE_COMP = 0x09,
    /** rfu */
    OTP_CALIB_RFU3 = 0x0A,
    /** Delay calibration value to adjust the distance measurement from ranging*/
    OTP_CALIB_DELAY_CALIB = 0x0B,
    /** PDOA mfg zero offset calibration*/
    OTP_PDOA_MFG_ZERO_OFFSET_CALIB = 0x0C,
    /** Point calibration entries*/
    OTP_AOA_ANT_MULTIPOINT_CALIB = 0x0D,
} eOtpCalibParam;

/**
 * Calibration integrity protection tag options.
 */

typedef enum calibTagOption
{
    /** Device Specific tag option */
    DEVICE_SPECIFIC = 0x0,
    /** Model Specific tag option */
    MODEL_SPECIFIC
} eCalibTagOption;

/**
 * @brief  Calibration Parameter States
 */
typedef struct phGetCalibInputParams
{
    /** Channel ID */
    uint8_t channel;
    /** Calibration Parameter ID
     * @ref eCalibParam
     */
    eCalibParam paramId;
#if UWBFTR_AoA_FoV
    /** Calibration antenna pair only for aoa antennae pdoa calib*/
    uint8_t rxAntennaPairID;
#endif // UWBFTR_AoA_FoV
#if UWBFTR_Radar
/** Calibration antenna pair only for aoa antennae pdoa calib*/
    uint8_t radarMode;
#endif // UWBFTR_Radar
} phGetCalibInputParams_t;

/**
 * @brief  Calibration Parameter States
 */
typedef enum
{
    /** Calibration parameter carries default value by UWBS */
    DEFAULT = 0x00,
    /** Calibration parameter is not integrity protected either by a
     *  Device specific or Model specific authentication tag. The parameter
     *  is applied in UWBS for usage.
     */
    CUSTOM_NOT_INTEGRITY_PROTECTED = 0x01,
    /** Calibration parameter integrity check is pending either by a Device
     *  specific or Model specific tag. Mainline FW: Until the tag verification
     *  finishes, the parameter will not be applied
     */
    CUSTOM_AUTH_PENDING = 0x02,
    /** Calibration parameter integrity check is verified successfully by a
     *  Device specific tag.
     */
    CUSTOM_DEVICE_SPECIFIC_TAG_AUTHENTICATED = 0x03,
    /** Calibration parameter integrity check is verified successfully by a
     *  Model specific tag
     */
    CUSTOM_MODEL_SPECIFIC_TAG_AUTHENTICATED = 0x04,

    /** Calibration data is either not set or its integrity can’t be verified.
     *  SR250 uses default value.
     */
    INVALID_STATE = 0x08,
} eCalibState;

/**
 * @brief  Structure lists out the calibration command response/notification.
 */
typedef struct phCalibRespStatus
{
    /** Status */
    uint8_t status;
    /** Calibration State in case of get_calib command
     *  and not used in case of do_calib command
     *  @ref eCalibState
     **/
    uint8_t calibState;
    /** Calibration Parameter ID
     * @ref eCalibParam
     */
    eCalibParam paramId;
    /** Calibration value length. In parameter. It is assumed
     *  calibrationValuelength bytes allocated for pCalibrationValue
     *  pointer. To be verified in the Calibration response that the
     *  received length matches with this
     **/
    uint16_t calibrationValuelength;
    /** Calibration value out
     *  Here is the base address and can be accessed till the length of calibrationValuelength.
     *
     * \note memory to hold the caliberation value to be allocated and buffer address to be set by calling application.
     */
    uint8_t *pCalibrationValue;
} phCalibRespStatus_t;

/**
 * @brief  Structure lists out the calibration (DO_CHIP_CALIBRATION_NTF) notification.
 */
typedef struct phDoCalibNtfStatus
{
    /** Status values returned in notification from UWBS for DO_CHIP_CALIBRATION_CMD
     * Below fields are valid if status is STATUS_OK
     **/
    uint8_t calibNtfStatus;
    /** Calibration value
     *
     * For Helios 1 (SR150)
     *  bit[8:0]  : Calibration code
     *  bit[14:9] : RFU
     *  bit[15]   : Calibration status as below
     *              - 0b1: Calibration is valid
     *              - 0b0: Calibration is invalid
     *
     * For Helios 2 (SR250) - Return the calibration outcome per channel.
     * bit[8:0]   : Calibration code
     * bit[13:9]  : RFU
     * bit[15:14] : Calibration status as below
     *              - 0b10: Calibration is valid
     *              - Other: Calibration is invalid
     **/
    uint16_t calibNtfValue;
} phDoCalibNtfStatus_t;

/**
 * @brief  Structure lists out the Generate Tag command response/notification.
 */

typedef struct phGenerateTagRespStatus
{
    /** Status */
    uint8_t status;
    /** CMAC Tag */
    uint8_t cmactag[UWB_TAG_CMAC_LENGTH];
} phGenerateTagRespStatus_t;

/**
 * @brief  Structure lists out the blink command response/notification.
 */
typedef struct phBlinkRespStatus
{
    /** repetition count status */
    uint8_t repetition_count_status;
} phBlinkRespStatus_t;

#if (UWBIOT_SESN_SNXXX)
/**
 * @brief UWBD Type for SE_DO_BIND Notification.
 */
typedef struct phSeDoBindStatus
{
    /** Binding status
     * - 0x00: Not Bound,
     * - 0x01: Bound Unlocked,
     * - 0x02: Bound Locked,
     * - 0x03: Unknown ( if any error occurred during getting binding state from SE)
    */
    uint8_t status;
    /** Remaining Binding Count */
    uint8_t count_remaining;
    /** Binding state */
    uint8_t binding_state;
    /** command for which SE communication is failed (Itshall indicate last APDU while binding procedure) */
    uint16_t se_instruction_code;
    /** status codes (SW1 SW2) */
    uint16_t se_error_status;
} phSeDoBindStatus_t;

/**
 * @brief UWBD Type for SE_GET_BINDING_STATUS Notification.
 */
typedef struct phSeGetBindingStatus
{
    /** Binding status
     * - 0x00: Not Bound,
     * - 0x01: Bound Unlocked,
     * - 0x02: Bound Locked,
     * - 0x03: Unknown ( if any error occurred during getting binding state from SE)
    */
    uint8_t status;
    /** Remaining binding count in SE */
    uint8_t se_binding_count;
    /** Remaining binding count in uwb device */
    uint8_t uwbd_binding_count;
    /** command for which SE communication is failed (Itshall indicate last APDU while binding procedure) */
    uint16_t se_instruction_code;
    /** status codes (SW1 SW2) */
    uint16_t se_error_status;
} phSeGetBindingStatus_t;

/**
 * @brief UWBD Type for UWB_ESE_CONNECTIVITY_CMD.
 */
typedef struct SeConnectivityStatus
{
    /**
     * - 0x00 : Success
     * - 0x01 : SE Error
     * - 0x02 : Time-out
     * - 0x03 : I2C interface error between UWB and eSE
     * - 0x04 : No Applet in eSE
     * - 0x74 : APDU command is rejected by eSE
     * - 0x75 : Authentication to eSE failed
     * - 0x76 : I2C write fail
     * - 0x77 : I2C Read fail with IRQ low
     * - 0x78 : I2C Read fail with IRQ high
     * - 0x79 : I2C timeout
     * - 0x7A : I2C write time out with IRQ high
     */
    uint8_t status;
    /** command for which SE communication is failed (Itshall indicate last APDU while binding procedure) */
    uint16_t se_instruction_code;
    /** status codes (SW1 SW2) */
    uint16_t se_error_status;
} SeConnectivityStatus_t;

#endif // (UWBIOT_SESN_SNXXX)
/**
 * @brief UWBD Type for URSK_DELETION_REQ Notification.
 */

typedef struct
{
    /** Session Id */
    uint32_t sessionId;
    /** Status */
    uint8_t status;
} phSessionIdList_t;

/**
 * @brief UWBD Type for URSK_DELETION_REQ Notification.
 */
typedef struct
{
    /** Status */
    uint8_t status;
    /** No of Session Ids */
    uint8_t noOfSessionIds;
    /** Session Id list */
    phSessionIdList_t sessionIdList[MAX_SESSION_ID_LIST];
} phUrskDeletionRequestStatus_t;

/**
 * @brief UWBD Type for SE_GET_BINDING_COUNT_RSP.
 */
typedef struct hSeGetBindingCount
{
    /** Binding Status */
    uint8_t bindingStatus;
    /** Remaining binding count in uwb device */
    uint8_t uwbdBindingCount;
    /** Remaining binding count in SE.
     *
     * @warning for SR150, this field has to be 0.
     */
    uint8_t seBindingCount;
} phSeGetBindingCount_t;

/**
 * @brief  Structure lists out the SE test loop information.
 */
typedef struct phSeTestLoopData
{
    /** Status */
    uint8_t status;
    /** No of times loop was run */
    uint16_t loop_cnt;
    /** No of times loop successfully completed */
    uint16_t loop_pass_count;
} phTestLoopData_t;

/**
 * @brief  Structure lists out the SE Comm Error notification.
 */
typedef struct phSeCommError
{
    /** Status */
    uint8_t status;
    /** T=1 command for which SE communication is failed. */
    uint16_t cla_ins;
    /** T=1 status codes(SW1SW2) */
    uint16_t t_eq_1_status;
} phSeCommError_t;

/**
 * channel for aoa fine calibration, supported parameters
 */
typedef enum phChannel
{
    /** channel 5*/
    CH_5 = 5,
    /**channel 9*/
    CH_9 = 9
} ephChannel;

/**
 * Antenna pair for aoa fine calibration, supported parameters
 */
typedef enum antPair
{
    ANT_1 = 1,
    ANT_2 = 2
} eAntPair;

#if UWBFTR_AoA_FoV
/**
 * \brief  Structure lists out the pdoa table define config.
 */
typedef struct phPdoaTableDef
{
    /** The calibration table step size in degrees which indicates the step size between two consecutive points */
    uint8_t calibStepSize;
    /* The number of calibration steps needs to be an odd number. */
    uint8_t noSteps;
} phPdoaTableDef_t;

/**
 * @brief  Structure lists out the aoa Calibration average threshold.
 */
typedef struct phAoACalibCtrlAvgThreshPdoa
{
    /** avg threshold pdoa for all angle sweeps */
    uint16_t avg_thresh_pdoa[NO_OF_CALIB_PAIRS];
} phAoACalibCtrlAvgThreashPdoa_t;
#endif // UWBFTR_AoA_FoV

typedef struct phAoACalibCtrlAvgPdoa
{
    /** avg pdoa for all angle sweeps */
    uint16_t avg_pdoa[AOA_FINE_CALIB_HOR_SWEEPS];
} phAoACalibCtrlAvgPdoa_t;

/**
 * @brief  Structure lists out the aoa calibration config.
 */
typedef struct phAoaCalib
{
    /** aoa calibration antenna1 */
    uint32_t aoa_calib_antenna1;
    /** aoa calibration antenna2 */
    uint32_t aoa_calib_antenna2;
    /** aoa calibration antenna3 */
    uint32_t aoa_calib_antenna3;
    /** aoa calibration antenna4 */
    uint32_t aoa_calib_antenna4;
    /** aoa calibration antenna5 */
    uint32_t aoa_calib_antenna5;
    /** aoa calibration antenna6 */
    uint32_t aoa_calib_antenna6;
    /** aoa calibration antenna7 */
    uint32_t aoa_calib_antenna7;
    /** aoa calibration antenna8 */
    uint32_t aoa_calib_antenna8;
} phAoaCalib_t;

/**
 * \brief Clock config parameters
 */
typedef struct clkConfigSrc
{
    /** Clock source option */
    uint8_t clk_src_opt;
#if UWBIOT_UWBD_SR1XXT
    /** Crystal option for RF clock */
    uint8_t xtal_opt;
#elif UWBIOT_UWBD_SR2XXT
    /** Slow clock waiting time
     *  Maximum waiting time in us until 32.768 kHz clock is present
     */
    uint16_t slow_clk_wait;
    /** RF clock waiting time
     *  Maximum waiting time in us until RF clock is present
     */
    uint16_t rf_clk_wait;
#else
#error "No specific UWBD"
#endif // UWBIOT_UWBD_SR1XXT
} phClkConfigSrc_t;

/**
 * @brief  Structure lists out the ddfs tone config.
 */
typedef struct phDdfsToneConfig
{
    /** channel no */
    uint8_t channel_no;
    /** Tx antenna selection */
    uint8_t tx_antenna_selection;
    /** content of TX_DDFS_TONE_0 */
    uint32_t tx_ddfs_tone_0;
    /** content of TX_DDFS_TONE_1 */
    uint32_t tx_ddfs_tone_1;
    /** spur duration */
    uint32_t spur_duration;
    /** value of GAINVAL_SET */
    uint8_t gainval_set;
    /** content of DDFSGAINBYPASS_ENBL */
    uint8_t ddfsgainbypass_enbl;
    /** periodicity */
    uint16_t periodicity;
} phDdfsToneConfig_t;

/**
 * @brief  Structure for antenna Identifier defines
 */
typedef struct phAntennaDefines
{
    /* Buffer should includes the number of entries */
    uint8_t *antennaDefs;
    uint8_t antennaDefsLen;
} phAntennaDefines_t;

/**
 * @brief Device config data
 */
typedef union phDeviceConfig {
    /** low power mode */
    uint8_t lowPowerMode;
    /** DPD wakeup src */
    uint8_t dpdWakeupSrc;
    /** WTX count config */
    uint8_t wtxCountConfig;
    /** DPD entry timeout */
    uint16_t dpdEntryTimeout;
    /** DDFS tone config enable */
    uint8_t txBaseBandConfig;
#if UWBFTR_AoA_FoV
    /** Anttena selection Config*/
    uint8_t rxAntennaSelectionConfig;
#endif // UWBFTR_AoA_FoV
    /** nxp extended ntf config */
    uint8_t nxpExtendedNtfConfig;
#if (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    /** WiFi CoEx Feature */
    UWB_WiFiCoEx_Ftr_t wifiCoExFtr;
#endif // (UWBIOT_UWBD_SR150 || UWBIOT_UWBD_SR250)
    /** DDFS Tone confg */
    phDdfsToneConfig_t ddfsToneConfig[NO_OF_CHANNELS];
    /** Tx Telec config */
    phTxPulseShapeConfig_t txPulseShapeConfig;
    /** Host Max UCI Payload Len */
    uint16_t hostMaxUCIPayloadLen;
#if UWBFTR_AoA_FoV
    /* PdoA Calibration Table Definition */
    phPdoaTableDef_t pdoaCalibTableDef;
    /** PDoA threshold values for all the calib pairs*/
    phAoACalibCtrlAvgThreashPdoa_t aoaCalibThresholdPdoa;
#endif // UWBFTR_AoA_FoV
    /** Negative offset when Rx should be enabled to receive the first message
    of a ranging round on Controlee compared to expected reception time. Default = 100 us */
    uint16_t initialRxOnOffsetAbs;
    /** Negative offset when Rx should be enabled to receive the first message
    of a ranging round on Controlee compared to expected reception time. Default = 100 ppm */
    uint16_t initialRxOnOffsetRel;
    /** To Define/Create all antenna Identifier for RX/TX/RX Pair */
    phAntennaDefines_t antennaDefines;
    /** Clock config parameters */
    phClkConfigSrc_t clockConfigCtrl;
    /** This configuration is used to configure the frequency of UWB Requests to WLAN for
     * getting WLAN Channel Information. */
    uint8_t wlanChannelINfo;
    /** Maximum waiting time until clock is present */
    uint16_t clockPresentWaitingTime;
#if UWBIOT_UWBD_SR2XXT
    /** DDFS config PER pulse shape */
    uint32_t ddfsCfgPerPulseShape;
#endif // UWBIOT_UWBD_SR2XXT
#if UWBFTR_AoA_FoV
    /** Used to define the type of computation to be considered by UWBS for obtaining AoA */
    uint8_t aoaMode;
    /** AOA calibration control */
    phAoaCalib_t aoaCalib[NO_OF_CHANNELS];
    /** PDoA average of vertical sweeps for all the horizontal angles and for all the IDs*/
    phAoACalibCtrlAvgPdoa_t aoaCalibAvgPdoa[NO_OF_CALIB_PAIRS];
#endif // UWBFTR_AoA_FoV
} phDeviceConfigData_t;

/**
 * @brief Structure for storing Firmware Crash Info, allocate pLog buffer with max response
 *
 * length value and update the logLen filed
 */
typedef struct phFwCrashLogInfo
{
    uint8_t *pLog;
    uint32_t logLen;
} phFwCrashLogInfo_t;

/**
 * \brief Enumeration lists out the CoEx Interface to be selected.
 */
typedef enum UWB_CoEx_InterfaceSelection
{
    /** UWB_WiFiCoEx_AdvGrantDuration */
    kUWB_CoEx_Gpio_Interface = 0x00,
    /** Set CoEx Interface as Uart Interface */
    kUWB_CoEx_Uart_Interface = 0x10,
    /** Set CoEx Interface as One Wire Interface. */
    kUWB_CoEx_OneWire_Interface = 0x20,

} UWB_CoEx_InterfaceSelection_t;

/**
 * \brief Enumeration lists out the configurations for the WiFi CoEx feature Notifications.
 */
typedef enum UWB_CoEx_NtfSelection
{
    /** Disable Wifi CoEx Feature (default) */
    kUWB_CoEx_Disable = 0x00,
    /** Enable CoEx Interface without Debug and without Warning Verbose. */
    kUWB_CoEx_En_WoDebug_WoWarning = 0x01,
    /** Enable CoEx Interface with Debug Verbose only */
    kUWB_CoEx_En_Debug = 0x02,
    /** Enable CoEx Interface with Warnings Verbose only */
    kUWB_CoEx_En_Warning = 0x03,
    /** Enable CoEx Interface with both Debug and Warning Verbose */
    kUWB_CoEx_En_Debug_Warning = 0x04,

} UWB_CoEx_NtfSelection_t;

/**
 * \brief Enumeration lists out the configurations for the WiFi CoEx feature.
 */
typedef enum UWB_CoEx_ChannelCfg
{
    /** Enable Wifi CoEx on Channel 5 */
    kUWB_CoEx_CH5 = 0x01,
    /** Enable Wifi CoEx on Channel 6 */
    kUWB_CoEx_CH6 = 0x02,
    /** Enable Wifi CoEx on Channel 8 */
    kUWB_CoEx_CH8 = 0x04,
    /** Enable Wifi CoEx on Channel 9 */
    kUWB_CoEx_CH9 = 0x08,
    /** Enable Wifi CoEx for all channels i.e ch5,ch6,ch8 and ch9 */
    kUWB_CoEx_AllCH = 0x0F,

} UWB_CoEx_ChannelCfg_t;
/**
 * \brief Structure for storing WiFiCoEx IND Ntf Context.
 */
typedef struct UWB_Wlan_IndNtf
{
    /** UWB_WLAN_IND Status */
    uint8_t UWB_Wlan_IndNtf_status;
    /** Time Index where the GPIO change occured */
    uint32_t UWB_Wlan_IndNtf_time_index;
    /** Session Handle to which UWB_WIFI_COEX_IND_NTF belongs */
    uint32_t UWB_Wlan_IndNtf_sessionHandle;

} UWB_Wlan_IndNtf_t;
/**
 * \brief Structure for storing WiFiCoEx Ind Error Notification.
 *
 * \note This notification shall be sent when WIFI_COEX_FEATURE_CH5 config is set to 0x02 (Enable with Debug Verbose)
 */
typedef struct Wlan_Uwb_IndNtf
{
    /** WLAN_UWB_IND_ERR Status
     * - 0x01: WLAN_UWB_IND_HIGH_AT_RR_START
     * WLAN_UWB_IND GPIO is high at the start of the ranging round and ranging round shall be attempted.
     * - 0x02: WLAN_UWB_IND_HIGH_DURING_RR
     * WLAN_UWB_IND GPIO changed to high during Ranging round
     */
    uint8_t Wlan_Uwb_IndNtf_status;
    /** Time Index where the GPIO change occured */
    uint32_t Wlan_Uwb_IndNtf_time_index;
} Wlan_Uwb_IndNtf_t;

#if UWBFTR_TransitProp

/**
 * \brief Structure for forming Wrapped RDS Param list .
 */
typedef struct phSetRdsParamList
{
    /** Session Handle to which the RDS parameters belongs. */
    uint32_t sessionHandle;
    /** 16-bit MAC address to which secure ranginging or data transfer to be performed. */
    uint8_t macAddr[SHORT_MAC_ADDR_LEN];
    uint8_t rdsLength;
    /** Session ID (4 octets) || Random (12 octets) || Wrapped RDS from SE (Maximum 40 octets) */
    uint8_t rangingDataSet[WRAPPED_RDS_LEN];
    /** To be set as 0xFFFFFFFF if the RDS was not set previously for the User.
     * Or to be initialized with the phyStsIndex of the Last RDS provided.
     */
    uint32_t lastPhyStsIndex;
} phSetRdsParamList_t;

/**
 * \brief Structure for storing Wrapped RDS Param list .
 */
typedef struct phSetRdsPramCmd
{
    uint8_t rdsParamListSize;
    phSetRdsParamList_t rdsParamList[MAX_RDS_LIST_SIZE];
} phSetRdsPramCmd_t;

/**
 * \brief Structure for storing the set RDS param ntf fields.
 */
typedef struct phSetRdsParamNtf
{
    /** Session ID for which RDS parameter is set */
    uint32_t secureSessionId;
    /** Status of the Set RDS parameter */
    uint8_t status;
} phSetRdsParamNtf_t;

#endif // UWBFTR_TransitProp

#if UWBIOT_UWBD_SR2XXT

/**
 *  @brief Secure Calibration Configuration parameters supported in UWB API layer.
 */
typedef enum calibParamSecure

{
    /** RF_CLK_ACCURACY_CALIB - Channel independent */
    RF_CLK_ACCURACY_CALIB_SECURE    = 0x02,
    /** Delay Calibration of TX Part of Antenna */
    TX_ANT_DELAY_CALIB_SECURE       = 0x0E,
    /** Delay Calibration of rX Part of Antenna */
    RX_ANT_DELAY_CALIB_SECURE       = 0x0F,
    /** 16-bytes string defining the platform name - Channel independent */
    PLATFORM_ID_SECURE              = 0x5C,
    /** Version number of the secure parameters - Channel independent */
    CONFIG_VERSION_SECURE           = 0x5D,
    /** Config to enable/disable the SE_COMM_DATA_NTF.
     * 0x00: Disable
     * 0x01: Enable
     * Note: Allowed in all lifecycles.
     **/
    DBG_SE_DUMP_SECURE              = 0x5E,
} eCalibParamSecure;

/**
 * @brief  Structure lists out the Secure calibration command sturcture.
 */
typedef struct phSecureCalibRespStatus

{
    /** Channel ID Indicator */
    uint8_t     channelId;
    /** Secure Calibration Param ID */
    uint8_t     calibParamId;
    /** Secure Calibration Param Length */
    uint16_t    length;
    /** Secure Calibration Param Value */
    uint8_t    *calibrationValue;
    /** Config Version value to be included */
    uint32_t    configVersion;
    /** Crypto tag value for CMAC verification */
    uint8_t    cryptoTag[CRYPTO_TAG_LEN];
} phSecureCalibParams_t;

#endif // UWBIOT_UWBD_SR2XXT

#if UWBFTR_CSA
/**
 * \brief Enumurator lists out the possible values of Localization Zones
 */
typedef enum localizationZone
{
    eLocZone_Undefined = 0x00,
    eLocZone_Frontside = 0x01,
    eLocZone_Backside  = 0x02,
} eLocalizationZone_t;

/**
 * \brief Structure for storing fields of Session Set Localization Zone Command.
 */
typedef struct phSessionSetLocZone
{
    /** Session Handle of the Session for which localization zone is estimated. */
    uint32_t setLocZone_SessionHandle;
    /** Ranging Block Index for which localization zone is estimated. */
    uint16_t setLocZone_RangingBlockIndex;
    /** The estimated localization zone. */
    eLocalizationZone_t setLocZone_LocZone;
} phSessionSetLocZone_t;

#endif // UWBFTR_CSA

/**
 * \brief Structure lists out the fields for the PDAoA Configurations.
 */
typedef struct
{
    /** Key used to find the values against it
     * \ref NxpUwbConfig
     */
    uint8_t key;
    /**
     * Value for the key
     */
    const uint8_t *pValue;
} sAoACoreConfigs_t;

/** @}  */ // uwb_apis_srxxx

#if UWBIOT_SESN_SNXXX
/**
 * \brief Structure lists out the fields for the ESE_GET_SESSION_ID_LIST Cmd/Rsp/Ntf
 */
typedef struct SeGetSessionIdList
{
    /* Status will be indicated via API status */
    /* Number of Session Ids */
    uint8_t numberOfSessionIds;
    /* List of Session Ids */
    uint32_t SessionIdList[MAX_SESSION_ID_LIST];
} pSeGetSessionIdList_t;
#endif // UWBIOT_SESN_SNXXX

/**
 * @brief Parameters to enable/disable SESSION_SCHEDULING_INFO_NTF.
 *        Used with UwbApi_EnableSessionSchedulingInfoNtf().
 */
typedef struct uwb_session_scheduling_info_ntf
{
    /** 0x00 = Disable
     *  0x01 = Enable SESSION_SCHEDULING_INFO_NTF sent always
     *  0x02 = Enable SESSION_SCHEDULING_INFO_NTF sent only on collisions */
    uint8_t uwb_enable_session_scheduling_info_ntf;
} uwb_session_scheduling_info_ntf_t;

/**
 * @brief Per-report fields in SESSION_SCHEDULING_INFO_NTF (Table 258).
 *        One entry per session report in the NTF.
 */
typedef struct uwb_session_scheduling_info_ntf_report
{
    /** Session Handle identifying which session this report belongs to. */
    uint32_t uwb_session_handle;
    /** Sequence number: starts at 0 on range start,
     *  pauses on range stop, resumes on range start. */
    uint32_t uwb_sequence_number;
    /**
     * Absolute UWBS time (microseconds) of the first slot start in the
     * current ranging phase for this ranging round.
     * Range: 1 to (2^64-1); default 0 uses UWB_INITIATION_TIME domain.
     * If sessions clash, UWBS calculates based on previous Ranging Round.
     */
    uint8_t uwb_first_slot_start_time[8];
    /**
     * Absolute UWBS time (microseconds) of the last slot end in the
     * current ranging phase for this ranging round.
     * Range: 1 to (2^64-1); default 0 uses UWB_INITIATION_TIME domain.
     * If sessions clash, UWBS calculates based on previous Ranging Round.
     */
    uint8_t uwb_last_slot_end_time[8];
    /**
     * Occupancy status: whether the session actually participated in the
     * ranging round. 0 = did not participate (due to session priority).
     */
    uint8_t uwb_occupancy_status;
} uwb_session_scheduling_info_ntf_report_t;

/**
 * @brief Payload of SESSION_SCHEDULING_INFO_NTF (Table 258).
 *        Delivered to the application via pAppCallback(UWBD_SESSION_SCHEDULING_INFO_NTF).
 *        Cast the void *pData argument of the callback to uwb_session_scheduling_info_ntf_data_t*.
 */
typedef struct uwb_session_scheduling_info_ntf_data
{
    /** Number of session reports (N) in this NTF. */
    uint8_t uwb_number_of_reports;
    /** Per-report data, one entry per session. */
    uwb_session_scheduling_info_ntf_report_t reports[MAX_SCHED_NTF_REPORTS];
} uwb_session_scheduling_info_ntf_data_t;

#endif // UWBAPI_TYPES_PROPRIETARY_SRXXX_H
