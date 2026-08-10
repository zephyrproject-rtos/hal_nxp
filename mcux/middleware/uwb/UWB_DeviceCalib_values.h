/*
 * Copyright 2026 NXP
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef _UWB_DEVICECALIB_VALUES_H_
#define _UWB_DEVICECALIB_VALUES_H_

#ifdef UWBIOT_USE_FTR_FILE
#include "uwb_iot_ftr.h"
#else
#include "uwb_iot_ftr_default.h"
#endif

#include <stdint.h>
#include "uwb_board.h"
#include "nxAntennaDefine.h"

/* clang-format off */

typedef struct hostDeviceCalib
{
    /* Calibration ParamId */
    eCalibParam paramId;
    /* ParamId name */
    char *paramName;
    /* Calibration channel */
    uint8_t channelId;
    /* Calibration length */
    uint16_t calibLen;
    /* Calibration Value */
    const uint8_t *pCalibValue;
} hostDeviceCalib_t;

/**
 * @brief Channel-specific calibration configuration structure
 */
typedef struct {
    uint8_t channel;
    const hostDeviceCalib_t *calibArray;
    size_t arraySize;
    const char *channelName;
} channelCalibConfig_t;



#define HOST_N_ENTRIES_OFFSET (0x00)
#define HOST_RX_PAIR_OFFSET   (0x01)
#define HOST_CALIBVAL_OFFSET  (0x02)

/** Max calib value size
 * max size for AOA_ANTENNAS_PDOA_CALIB : S*S*2
 * 3 <= S <= 17 (default 11)
 */
#define HOST_CALIB_VALUE_SZ (17 * 17 * 2)

/* Helper macro to convert into string */
#define GET_PARAM_STR(paramName) #paramName

/****************************************RF_CLK_ACCURACY_CALIB****************************************/
/**
 * Defines the capacitors values applied to 38.4MHz XTAL.
 * Channel independent and remains same for each channel.
 * - Octet [0]: Number of registers (must be 0x03)
 * - Octet [2-1]: 38.4 MHz XTAL CAP1
 * - Octet [4-3]: 38.4 MHz XTAL CAP2
 * - Octet [6-5]: 38.4 MHz XTAL GM CURRENT CTRL
 * Values : [0x00-0xFF] for 38.4 MHz XTAL CAP
 * Values : [0x00-0x3F] for 38.4 MHz XTAL GM
 */
const uint8_t rf_clk_accu_calib[] = {
   AD_N_REGISTERS(3), /* must be 3 */
      0x24, 0x00, /* 38.4 MHz XTAL CAP1 */
      0x24, 0x00, /* 38.4 MHz XTAL CAP2 */
      0x04, 0x00, /* 38.4 MHz XTAL GM CURRENT CTRL */
};

/*****************************************RX_ANT_DELAY_CALIB*****************************************/
/**
 * Delay Calibration for each RX Antenna
 * This parameter is channel dependent
 * Channel IDs
 * - Octet[0]: Number of Entries (Must be greater than 0)
 * - [
 *    – 1 Octet: RX Antennas IDs as defined by ANTENNA_RX_IDX_DEFINE
 *    – 2 Octets each: RX Delay (unsigned Q14.2).
 * ] (Repeat)
 * (Default: 0x0000 for all RX antenna IDs)
 * Example to Set RX Delay Calib for Antenna ID =0x01,0x02,0x03 for Channel 5 and 9
 *    - Protected lifecycle:
 *       SET_DEVICE_CALIBRATION_SEC_CMD
 *       – channel Id=5, Calibration Param=0x02
 *       – Number Of entries = 2
 *       – Ant ID : 0x01, Delay Value1
 *       – Ant ID : 0x02, Delay Value2
 *       – ConfigVersion = 0x01
 *       – Cryptotag = 0xXX…0xXX
 *    - Other lifecycle:
 *       SET_DEVICE_CALIBRATION_CMD
 *       – channel Id=5, Calibration Param=0x02 = Rx Ant Delay calib
 *       – Number Of entries = 3
 *       – Ant ID : 0x01, Delay Value1
 *       – Ant ID : 0x02, Delay Value2
 *    RX_ANT_DELAY_CALIB unit is cm and step size is 0.25 cm
 *    i.e value 1 =0.25 cm
 */

const uint8_t rx_antennae_delay_calib_channel9[] = {
   AD_N_RX_ENTRIES(4), /* N Entries */
      AD_RX_ID(1), /* RX Pair */
         AD_U16_TO_AU8_LE(0x481D), /* RX Delay */
      AD_RX_ID(2), /* RX Pair */
         AD_U16_TO_AU8_LE(0x481C), /* RX Delay */
      AD_RX_ID(3), /* RX Pair */
         AD_U16_TO_AU8_LE(0x4824), /* RX Delay */
	  AD_RX_ID(4), /* RX Pair */
	     AD_U16_TO_AU8_LE(0x482A), /* RX Delay */
};

/*****************************************PDOA_OFFSET_CALIB*****************************************/
/**
 * PDOA Offset Calibration
 * This parameter is channel dependent
 * Channel IDs
 * - Octet[0]: Number of Entries (Must be greater than 0) (Depends on available RAM)
 *   [
 *    – 1 Octet each: RX Antennas PAIR IDs as defind by ANTENNAS_RX_PAIR_DEFINE
 *    – 2 Octets each: PDoA Offsets. (signed value in Q9.7 format)
 *   ] (Repeat)
 * (Default: 0x0000 for all RX antenna pair ID)
 * Example to Set PDoA Offset Calib for Antenna Pair ID=0x01, 0x02, 0x03 for Channel 5 and 9
 *    SET_DEVICE_CALIBRATION_CMD(ch Id=5, Calib Param=0x10 = PDoA1, No Of Entries=3,
 *    Ant ID=0x01,PDOA Value1, 0x02,PDOA Value2, 0x03,PDOA Value3)
 *    Repeat the same command for Channel 9
 *    GET_DEVICE_CALIBRATION_CMD is a cyclic fetch logic as explained below
 *    First Invocation GET_DEVICE_CALIBRATION_CMD (ch Id=5, Calib Param=0x10) will report the data for PAIR1
 *    Second Invocation GET_DEVICE_CALIBRATION_CMD (ch Id=5, Calib Param=0x10) will report the data for PAIR2
 *    Repeats until MAX_N of ANTENNAS_RX_PAIR_DEFINE
 * Note: Refer Recommendation while using
 */

const uint8_t pdoa_offset_calib_ch_9[] = {
   AD_N_PAIR_ENTRIES(2), /* N Entries */
      AD_AP_ID(1), /* Antenna Pair Id */
         AD_U16_TO_AU8_LE(0x12E9), /* PDoA Offset */
      AD_AP_ID(2), /* Antenna Pair Id */
         AD_U16_TO_AU8_LE(0xBCAB), /* PDoA Offset */
};

/****************************************TX_POWER_PER_ANTENNA****************************************/
/**
 * TX POWER
 * This parameter is channel dependent
 * channel_ID :
 * Channel IDs
 * - Octet[0]: Number of Entries (Must be greater than 0)
 *  [
 *    – 1 Octet : TX Antenna IDs as defind by ANTENNAS_TX_IDX_DEFINE
 *    – 2 Octets : TX_POWER_DELTA_PEAK
 *       - If TX_ADAPTIVE_PAYLOAD_POWER is enabled, this value represents the delta peak
 *          ie : PEAK_ID - RMS_ID. This value is a delta and comes from calibration process, It ranges from 0 (max power) to 127 (min power) with steps of 0.25.
 *       - If TX_ADAPTIVE_PAYLOAD_POWER is not enabled, this value has no specific use.
 *    – 2 Octets : TX_POWER_ID_RMS
 *       - If TX_ADAPTIVE_PAYLOAD_POWER is enabled, this value come from RMS calibration as RMS_ID
 *       - If TX_ADAPTIVE_PAYLOAD_POWER is not enabled, this value serves as a gain index for TX power control. It ranges from 0 (max power) to 127 (min power) with steps of 0.25.
 *  ] (Repeat)
 * Default value for all: 0x00
 * Note: TEST_LOOPBACK_CMD is rejected if TX_POWER_ID_RMS is below than 80
 */
const uint8_t tx_pow_per_antennae_channel9[] = {
   AD_N_TX_ENTRIES(2), /* N Entries */
      AD_AP_ID(1), /* Antenna Pair Id */
         0x00, 0x00, /* Tx Power Delta Peak */
         0x2F, 0x00, /* Tx Power Id RMS */
      AD_AP_ID(2), /* Antenna Pair Id */
         0x00, 0x00, /* Tx Power Delta Peak */
         0x39, 0x00, /* Tx Power Id RMS */
};

/***********************************************************************AOA_ANTENNAS_PDOA_CALIB***********************************************************************/
/**
 * PDOA Calibration tables
 *    - Octet[0] : No of entries, it shall be set to 1 for Set Calibration Cmd. (Refer to a) of Note for this limitation.)
 *    - Octet[1] : RX Pair Antennas ID as defined earlier by ANTENNAS_RX_PAIR_DEFINE
 *    - Octet[2 - M]: PDoA calibration table for specified RX Pair Antennas ID.
 * The older entries would get overwritten, if more than supported data is uploaded to the UWBS.
 * Allowed Range: 3<=M<=17(to include 0°)(default : 11)
 * Note:
 *    - In order to support Hosts that can not send more than 255 + 4 bytes, this UCI interface can only be used to set PDoA calibration table for one RX Pair Antennas ID at a time.
 *    - The Get Calibration Cmd response for this ID returns the total number of "RX Pair Antennas IDs" for which PDOA calibration table is set in Octet[0].
 */
const uint8_t rx_pair_1_ch_9_pdoa_calib[] = {
   AD_N_PAIR_ENTRIES(1), /* N Entries */
      AD_AP_ID(1), /* RX Pair */
       /* Pan   -60,        -48,        -36,        -24,        -12,          0,        +12,        +24,        +36,        +48,        +60, */
         0x90, 0x42, 0x3B, 0x3B, 0x37, 0x2E, 0x51, 0x27, 0x16, 0x0E, 0xAF, 0xFA, 0xB9, 0xF9, 0xB3, 0xD9, 0xEB, 0xC7, 0xF8, 0xBD, 0xF2, 0xB9, /* Tilt: -60 */
         0x05, 0x48, 0x58, 0x41, 0xF7, 0x2F, 0xA5, 0x23, 0x6C, 0x0F, 0x16, 0x00, 0x28, 0xF8, 0xDC, 0xD9, 0xDF, 0xC3, 0xF0, 0xBB, 0xBC, 0xB7, /* Tilt: -48 */
         0xAB, 0x49, 0xA7, 0x43, 0x4C, 0x35, 0x3C, 0x1E, 0x96, 0x0D, 0x1F, 0x03, 0xE9, 0xF6, 0xEC, 0xD6, 0x12, 0xC1, 0x26, 0xBA, 0x00, 0xB6, /* Tilt: -36 */
         0x83, 0x4A, 0xE6, 0x44, 0x7A, 0x39, 0xC3, 0x1F, 0x8D, 0x09, 0x26, 0xFE, 0x4D, 0xF5, 0xFA, 0xD7, 0x05, 0xBF, 0xE1, 0xB8, 0x7D, 0xB5, /* Tilt: -24 */
         0xB9, 0x49, 0x3B, 0x45, 0x34, 0x3C, 0x88, 0x24, 0xF5, 0x0B, 0x76, 0xFC, 0x49, 0xF4, 0x47, 0xDA, 0x34, 0xC1, 0xC1, 0xB9, 0xCB, 0xB5, /* Tilt: -12 */
         0x80, 0x48, 0x30, 0x43, 0xB2, 0x3A, 0x51, 0x27, 0x13, 0x11, 0xD2, 0xFF, 0x68, 0xF6, 0x49, 0xDE, 0x28, 0xC5, 0xC5, 0xBB, 0xD2, 0xB6, /* Tilt: 0 */
         0x95, 0x47, 0x5A, 0x40, 0x85, 0x36, 0x78, 0x25, 0x6E, 0x15, 0x3D, 0x08, 0xE8, 0xFC, 0xFB, 0xE2, 0xA9, 0xCB, 0x8C, 0xBF, 0x9A, 0xB8, /* Tilt: 12 */
         0xF7, 0x46, 0x37, 0x3F, 0x0B, 0x34, 0x52, 0x23, 0x7D, 0x17, 0xAA, 0x0D, 0x54, 0x00, 0x9F, 0xE5, 0x27, 0xCE, 0xBA, 0xC2, 0x65, 0xBA, /* Tilt: 24 */
         0x75, 0x46, 0xD7, 0x3D, 0xB1, 0x30, 0xB9, 0x20, 0xAE, 0x18, 0xB2, 0x10, 0x2F, 0x02, 0xD3, 0xE5, 0x95, 0xD1, 0x6A, 0xC5, 0x68, 0xBB, /* Tilt: 36 */
         0x72, 0x45, 0x54, 0x3C, 0xDD, 0x2F, 0x83, 0x21, 0x06, 0x1B, 0x54, 0x11, 0x70, 0x01, 0x18, 0xE5, 0x5A, 0xD1, 0xD5, 0xC6, 0xF0, 0xBB, /* Tilt: 48 */
         0x5C, 0x45, 0x42, 0x3B, 0x18, 0x2F, 0x92, 0x22, 0xC0, 0x1C, 0x14, 0x12, 0x2C, 0x00, 0x41, 0xE3, 0x1D, 0xD1, 0x40, 0xC7, 0x88, 0xBC  /* Tilt: 60 */
};

const uint8_t rx_pair_2_ch_9_pdoa_calib[] = {
   AD_N_PAIR_ENTRIES(1), /* N Entries */
      AD_AP_ID(2), /* RX Pair */
       /* Tilt   -60,        -48,        -36,        -24,        -12,          0,        +12,        +24,        +36,        +48,        +60, */
          0x5B, 0x18, 0xF1, 0x11, 0x74, 0x0C, 0x17, 0x08, 0x57, 0x03, 0xF3, 0xFD, 0x9E, 0xF7, 0x0E, 0xF1, 0x9E, 0xEA, 0x80, 0xE5, 0x5A, 0xE1, /* Pan: -60 */
          0x38, 0x19, 0xA0, 0x17, 0xAD, 0x13, 0x78, 0x0D, 0xF5, 0x05, 0x29, 0xFF, 0xC2, 0xF7, 0x70, 0xEE, 0xCB, 0xE5, 0x57, 0xDE, 0x9C, 0xD7, /* Pan: -48 */
          0xBA, 0x2B, 0xBC, 0x20, 0xE1, 0x13, 0xB8, 0x0B, 0x3D, 0x02, 0xF8, 0xFB, 0xC4, 0xF4, 0x8B, 0xE9, 0x45, 0xDD, 0xAA, 0xCF, 0x9D, 0xC4, /* Pan: -36 */
          0x2D, 0x3C, 0x12, 0x32, 0x18, 0x27, 0x2B, 0x18, 0x7B, 0x07, 0xFD, 0xF9, 0x04, 0xF1, 0xC5, 0xE6, 0xEF, 0xDB, 0x83, 0xCE, 0x97, 0xC1, /* Pan: -24 */
          0x20, 0x4B, 0xD8, 0x40, 0x60, 0x35, 0xEA, 0x24, 0x4F, 0x11, 0xBF, 0xFD, 0xCB, 0xEE, 0x7F, 0xE2, 0x52, 0xD6, 0x21, 0xCA, 0x14, 0xC0, /* Pan: -12 */
          0xEB, 0x44, 0x1C, 0x39, 0x68, 0x31, 0x7F, 0x24, 0x54, 0x12, 0xAD, 0xFE, 0xE2, 0xEB, 0x06, 0xDE, 0xCB, 0xD0, 0x4E, 0xC4, 0x40, 0xB7, /* Pan: 0 */
          0xFE, 0x32, 0x0C, 0x29, 0xA9, 0x21, 0x35, 0x18, 0xE6, 0x0B, 0x10, 0xFC, 0x9B, 0xEA, 0x3A, 0xDB, 0x7A, 0xCC, 0x2E, 0xBF, 0xE0, 0xB4, /* Pan: 12 */
          0xAC, 0x47, 0xD4, 0x39, 0xFB, 0x2F, 0x5B, 0x21, 0x52, 0x12, 0x2C, 0x00, 0xE9, 0xEE, 0x7C, 0xDF, 0x9F, 0xD2, 0x2C, 0xC7, 0x65, 0xBE, /* Pan: 24 */
          0x4D, 0x48, 0xBD, 0x42, 0xCB, 0x37, 0x1E, 0x2A, 0x3A, 0x1B, 0xB9, 0x07, 0x47, 0xF5, 0xA7, 0xE7, 0x52, 0xDB, 0x22, 0xD4, 0x5B, 0xCE, /* Pan: 36 */
          0x3C, 0x32, 0xC2, 0x30, 0xDC, 0x2A, 0xF0, 0x20, 0x2B, 0x15, 0x1E, 0x07, 0x82, 0xF8, 0x67, 0xEC, 0x18, 0xE1, 0xB7, 0xD6, 0x74, 0xCE, /* Pan: 48 */
          0xC4, 0x19, 0xDC, 0x1C, 0x09, 0x19, 0xA9, 0x11, 0xE4, 0x0A, 0x82, 0x03, 0x03, 0xFA, 0xF7, 0xF0, 0x3C, 0xE9, 0x14, 0xE1, 0xAD, 0xD9  /* Pan: 60 */
};


/***********************************************AOA_THRESHOLD_PDOA***********************************************/
/**
 * AoA Threshold PDOA
 * - Octet[0]: Number of Entries (Must be greater than 0)
 *  [
 *    – Array of 1 Octet each: RX Antennas PAIR IDs as defind by ANTENNAS_RX_PAIR_DEFINE
 *    – Array of 2 Octets each: Threshold Values
 *  ] (Repeat)
 * Example to Set Threshold for Antenna Pair ID=0x01, 0x02, 0x03 for Channel 5 and 9
 * SET_DEVICE_CALIBRATION_CMD (ch Id=5, Calib Param=0x15 = Threshold PDoA, No Of Entries=3, Ant ID=0x01,Threshold PDoA Value1, 0x02,Threshold PDoA Value2, 0x03,Threshold PDoA Value3)
 * Repat the same command for Channel 9.
 */

const uint8_t aoa_threshold_pdoa_calib_ch_9[] = {
   AD_N_PAIR_ENTRIES(2), /* N Entries */
      AD_AP_ID(1), /* Antenna Pair Id */
         AD_CALIB_THRESHOLD_PDOA(0xB8EA), /* Threshold Values */
      AD_AP_ID(2), /* Antenna Pair Id */
         AD_CALIB_THRESHOLD_PDOA(0x16AA), /* Threshold Values */
};

/********************************RF_CLK_ACCURACY_CALIB*******************************/
#define HOST_RF_CLK_ACCURACY_CALIB                                                  \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_RF_CLK_ACCURACY_CALIB),                     \
        .paramId = RF_CLK_ACCURACY_CALIB,                                           \
        .channelId = 0,                                                             \
        .pCalibValue = rf_clk_accu_calib,                                           \
        .calibLen = GET_ARRAY_SIZE(rf_clk_accu_calib),                              \
    }                                                                               \

/*********************************RX_ANT_DELAY_CALIB*********************************/
#define HOST_RX_ANT_DELAY_CALIB_CH9                                                 \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_RX_ANT_DELAY_CALIB_CH9),                    \
        .paramId = RX_ANT_DELAY_CALIB,                                              \
        .channelId = CH_9,                                                          \
        .pCalibValue = rx_antennae_delay_calib_channel9,                            \
        .calibLen = GET_ARRAY_SIZE(rx_antennae_delay_calib_channel9),               \
    }                                                                               \

#if UWBFTR_AoA_FoV
/*********************************PDOA_OFFSET_CALIB**********************************/
#define HOST_PDOA_OFFSET_CALIB_CH9                                                  \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_PDOA_OFFSET_CALIB_CH9),                     \
        .paramId = PDOA_OFFSET_CALIB,                                               \
        .channelId = CH_9,                                                          \
        .pCalibValue = pdoa_offset_calib_ch_9,                                      \
        .calibLen = GET_ARRAY_SIZE(pdoa_offset_calib_ch_9),                         \
    }                                                                               \

/*******************************AOA_ANTENNAS_PDOA_CALIB******************************/
#define HOST_AOA_ANTENNAS_PDOA_CALIB_AP1_CH9                                        \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_AOA_ANTENNAS_PDOA_CALIB_AP1_CH9),           \
        .paramId = AOA_ANTENNAS_PDOA_CALIB,                                         \
        .channelId = CH_9,                                                          \
        .pCalibValue = rx_pair_1_ch_9_pdoa_calib,                                   \
        .calibLen = GET_ARRAY_SIZE(rx_pair_1_ch_9_pdoa_calib),                      \
    }                                                                               \

#define HOST_AOA_ANTENNAS_PDOA_CALIB_AP2_CH9                                        \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_AOA_ANTENNAS_PDOA_CALIB_AP2_CH9),           \
        .paramId = AOA_ANTENNAS_PDOA_CALIB,                                         \
        .channelId = CH_9,                                                          \
        .pCalibValue = rx_pair_2_ch_9_pdoa_calib,                                   \
        .calibLen = GET_ARRAY_SIZE(rx_pair_2_ch_9_pdoa_calib),                      \
    }                                                                               \

/*********************************AOA_THRESHOLD_PDOA*********************************/

#define HOST_AOA_THRESHOLD_PDOA_CH9                                                 \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_AOA_THRESHOLD_PDOA_CH9),                    \
        .paramId = AOA_THRESHOLD_PDOA,                                              \
        .channelId = CH_9,                                                          \
        .pCalibValue = aoa_threshold_pdoa_calib_ch_9,                               \
        .calibLen = GET_ARRAY_SIZE(aoa_threshold_pdoa_calib_ch_9),                  \
    }                                                                               \

#endif // UWBFTR_AoA_FoV

/********************************TX_POWER_PER_ANTENNA********************************/
#define HOST_TX_POWER_PER_ANTENNA_CH9                                               \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_TX_POWER_PER_ANTENNA_CH9),                  \
        .paramId = TX_POWER_PER_ANTENNA,                                            \
        .channelId = CH_9,                                                          \
        .pCalibValue = tx_pow_per_antennae_channel9,                                \
        .calibLen = GET_ARRAY_SIZE(tx_pow_per_antennae_channel9),                   \
    }                                                                               \

/*********************** Channel 9 Calibration Configurations ***********************/

/************************************************************************************/
static hostDeviceCalib_t setDeviceCalib_channel9[] = {
    /***************************RF_CLK_ACCURACY_CALIB****************************/
    HOST_RF_CLK_ACCURACY_CALIB,
    /****************************RX_ANT_DELAY_CALIB******************************/
    HOST_RX_ANT_DELAY_CALIB_CH9,
#if UWBFTR_AoA_FoV
    /****************************PDOA_OFFSET_CALIB*******************************/
    HOST_PDOA_OFFSET_CALIB_CH9,
#endif // UWBFTR_AoA_FoV
    /***************************TX_POWER_PER_ANTENNA*****************************/
    HOST_TX_POWER_PER_ANTENNA_CH9,
#if UWBFTR_AoA_FoV
    /***************************AOA_ANTENNAS_PDOA_CALIB**************************/
    HOST_AOA_ANTENNAS_PDOA_CALIB_AP1_CH9,
    HOST_AOA_ANTENNAS_PDOA_CALIB_AP2_CH9,
    /*******************************AOA_THRESHOLD_PDOA***************************/
    HOST_AOA_THRESHOLD_PDOA_CH9,
#endif // UWBFTR_AoA_FoV
};


/****************************************CHANNEL CONFIGURATION MACRO****************************************/
/**
 * Channel Configuration Macro
 * This macro expands to the channel calibration configuration array
 * Customize this macro per board to include only required channels
 */
#define GET_CHANNEL_CONFIGS \
    { \
        .channel        = CH_9, \
        .calibArray     = setDeviceCalib_channel9, \
        .arraySize      = GET_ARRAY_SIZE(setDeviceCalib_channel9), \
        .channelName    = "Channel 9" \
    }

/* clang-format on */

#endif //_UWB_DEVICECALIB_VALUES_H_
