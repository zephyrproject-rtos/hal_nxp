/*
 * Copyright 2026 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _UWB_DEVICECALIB_VALUES_H_
#define _UWB_DEVICECALIB_VALUES_H_

#ifdef UWBIOT_USE_FTR_FILE
#include "uwb_iot_ftr.h"
#else
#include "uwb_iot_ftr_default.h"
#endif

#include <stdint.h>
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
       /* Pan  -84,        -72,        -60,        -48,        -36,        -24,        -12,          0,        +12,        +24,        +36,        +48,        +60,        +72        +84, */
    0x8C,0x4A,0xB9,0x4E,0xD4,0xE6,0x52,0x34,0xC0,0x19,0x05,0x1A,0xFB,0x0D,0x4C,0xB9,0xD1,0xF8,0xB2,0xD7,0x9C,0xBC,0x95,0xBB,0x5B,0xB8,0xD3,
    0xB0,0x03,0xB8,0xB8,0x4B,0x97,0x43,0xF8,0x2B,0x06,0x31,0x72,0x29,0xAC,0x24,0xDA,0x0C,0x05,0xF1,0xB6,0xFE,0x43,0xD7,0x83,0xC8,0x4D,0xBD,0x25,0xBB,0xBE,
    0xBD,0xF5,0xB5,0x9B,0x48,0x95,0x3A,0x52,0x41,0xFC,0x39,0xF9,0x2C,0x13,0x26,0xD8,0x0C,0x71,0xF9,0x7A,0xF8,0x75,0xD8,0xAD,0xC6,0xB9,0xBC,0xB4,0xB8,0xB7,
    0xB1,0x7D,0xB4,0x40,0x47,0x45,0x43,0xC7,0x46,0x1A,0x40,0xB9,0x2E,0x67,0x22,0x2E,0x0E,0xD9,0xFE,0xEA,0xF6,0x9E,0xD8,0xA1,0xC2,0xB2,0xBA,0x7E,0xB6,0x58,
    0xB0,0x07,0xB7,0x43,0x4A,0x4A,0x4C,0x6D,0x48,0x68,0x42,0x0E,0x34,0xFE,0x1C,0x58,0x0C,0xE1,0x01,0xAA,0xF5,0xAE,0xD5,0xD4,0xBF,0xE8,0xB8,0xC2,0xB4,0xA5,
    0xB0,0xC9,0xB8,0x17,0x4A,0x43,0x4D,0x45,0x49,0xA8,0x43,0x3C,0x38,0x85,0x1E,0x4F,0x08,0xE8,0xFC,0x0F,0xF4,0xBB,0xD6,0xC7,0xBD,0xA3,0xB7,0x3F,0xB4,0xBE,
    0xB0,0x16,0xB2,0x6E,0x49,0xCD,0x4A,0x7B,0x48,0xFD,0x43,0xF6,0x3A,0x4A,0x23,0xB7,0x0A,0x38,0xFB,0x0B,0xF3,0x09,0xD9,0xF6,0xBF,0x83,0xB8,0x8D,0xB4,0x15,
    0xB1,0x0D,0xAF,0xFE,0x4C,0xD9,0x49,0x42,0x47,0xF2,0x41,0x74,0x39,0x13,0x26,0xD5,0x0F,0x94,0xFE,0x2A,0xF5,0x0B,0xDD,0xEA,0xC3,0x86,0xBA,0x94,0xB5,0x91,
    0xB1,0xB0,0xAE,0xC6,0x4F,0xF3,0x49,0x57,0x46,0x1B,0x3F,0x47,0x35,0x3A,0x24,0x2F,0x14,0xFF,0x06,0xA9,0xFB,0xBC,0xE1,0x6B,0xCA,0x4E,0xBE,0x5C,0xB7,0x6F,
    0xB2,0xFF,0xAE,0x74,0x4F,0xBC,0x49,0xB9,0x45,0xF9,0x3D,0xCD,0x32,0x13,0x22,0x3F,0x16,0x6C,0x0C,0x17,0xFF,0x61,0xE4,0xE9,0xCC,0x7B,0xC1,0x27,0xB9,0x83,
    0xB3,0x6B,0xB0,0x5C,0x4F,0x76,0x49,0x37,0x45,0x98,0x3C,0x73,0x2F,0x7B,0x1F,0x70,0x17,0x73,0x0F,0xF1,0x00,0x95,0xE4,0x56,0xD0,0x2B,0xC4,0x2A,0xBA,0xA5,
    0xB4,0xA8,0xB0,0x03,0x4F,0xC3,0x48,0x33,0x44,0x16,0x3B,0x9F,0x2E,0x45,0x20,0xC7,0x19,0x16,0x10,0x31,0x00,0xDA,0xE3,0x1C,0xD0,0x97,0xC5,0xB2,0xBA,0x03,
    0xB6,0x09,0xB0,0xA6,0x4F,0x79,0x48,0x1E,0x44,0x03,0x3A,0xDA,0x2D,0x54,0x21,0x82,0x1B,0xD5,0x10,0xEF,0xFE,0x03,0xE2,0xDF,0xCF,0x02,0xC6,0x4A,0xBB,0xF4,
    0xB6,0x34,0xAF,0xC9,0x50,0x97,0x49,0x1D,0x44,0x04,0x39,0xAA,0x2A,0x5E,0x20,0x73,0x1C,0x09,0x13,0x01,0xFD,0x1C,0xE0,0xCF,0xCF,0xF9,0xC4,0x7D,0xBB,0xD4,
    0xB6,0x52,0xAE,0x35,0x52,0x3D,0x4B,0xAB,0x44,0x5A,0x39,0x10,0x28,0xE3,0x1E,0x08,0x1C,0x43,0x14,0xCD,0xFA,0xD7,0xDF,0x5B,0xD0,0x08,0xC4,0xCD,0xBA,0xA6,
    0xB5,0xCB,0xAD
};

const uint8_t rx_pair_2_ch_9_pdoa_calib[] = {
   AD_N_PAIR_ENTRIES(1), /* N Entries */
    AD_AP_ID(2), /* RX Pair */
       /* Tilt  -84,        -72,        -60,        -48,        -36,        -24,        -12,          0,        +12,        +24,        +36,        +48,        +60,        +72,        +84, */
    0x53,0x0E,0x29,0x05,0xF4,0x1C,0x93,0x1E,0x8A,0x16,0xCE,0x0E,0x45,0x07,0xCC,0xFC,0xCE,0xF2,0x2A,0xEA,0x91,0xE2,0x3E,0xDE,
    0xD7,0xDB,0x11,0xDD,0xEF,0xDD, 0x8C,0x34,0x0F,0x3F,0xEF,0x39,0xD7,0x20,0xED,0x10,0xAE,0x0B,0xBC,0x07,0x7E,0x03,0xAE,0xFF,0x2B,0xFD,0x64,0xFA,0x92,
    0xF5,0x54,0xEE,0xF6,0xE6,0xDE,0xEB,0x98,0x4A,0x3B,0x2E,0xAF,0x19,0x45,0x13,0xC8,0x0D,0x6B,0x09,0xAB,0x04,0x47,0xFF,0xF2,0xF8,0x62,0xF2,0xF1,0xEB,0xD3,
    0xE6,0xAE,0xE2,0x34,0xE1,0xED,0xE3,0x46,0x27,0x95,0x23,0x8B,0x1A,0xF4,0x18,0x01,0x15,0xCB,0x0E,0x49,0x07,0x7C,0x00,0x16,0xF9,0xC3,0xEF,0x1E,0xE7,0xAB,
    0xDF,0xEF,0xD8,0xF8,0xD2,0xAE,0xCC,0x1F,0x3B,0x55,0x36,0x0D,0x2D,0x10,0x22,0x35,0x15,0x0C,0x0D,0x90,0x03,0x4C,0xFD,0x17,0xF6,0xDE,0xEA,0x99,0xDE,0xFD,
    0xD0,0xF1,0xC5,0xB8,0xC1,0x49,0xC2,0x1B,0x19,0xD5,0x4C,0x81,0x3D,0x66,0x33,0x6C,0x28,0x7E,0x19,0xCF,0x08,0x51,0xFB,0x58,0xF2,0x19,0xE8,0x43,0xDD,0xD7,
    0xCF,0xEB,0xC2,0x42,0xBA,0xE1,0xB5,0x8C,0xAE,0xDF,0x52,0x74,0x4C,0x2B,0x42,0xB4,0x36,0x3E,0x26,0xA3,0x12,0x12,0xFF,0x1F,0xF0,0xD3,0xE3,0xA6,0xD7,0x74,
    0xCB,0x68,0xC1,0x48,0xBA,0x1E,0xB5,0x2A,0x4D,0x93,0x46,0x3F,0x46,0x70,0x3A,0xBB,0x32,0xD3,0x25,0xA7,0x13,0x00,0x00,0x36,0xED,0x5A,0xDF,0x1F,0xD2,0xA2,
    0xC5,0x94,0xB8,0xA1,0xAB,0xCA,0x54,0xD6,0x37,0xCB,0x30,0x51,0x34,0x60,0x2A,0xFC,0x22,0x88,0x19,0x3A,0x0D,0x64,0xFD,0xEE,0xEB,0x8E,0xDC,0xCE,0xCD,0x82,
    0xC0,0x33,0xB6,0xD1,0xAD,0xD3,0xA8,0x58,0x4C,0x42,0x4E,0x00,0x49,0x28,0x3B,0x4E,0x31,0xAF,0x22,0xA6,0x13,0x80,0x01,0x3C,0xF0,0xD0,0xE0,0xF3,0xD3,0x80,
    0xC8,0xB9,0xBF,0xD8,0xBA,0xF5,0xB9,0x61,0x56,0xB3,0x4B,0xA1,0x49,0x11,0x44,0x1F,0x39,0x72,0x2B,0x8D,0x1C,0x0D,0x09,0x9A,0xF6,0xFA,0xE8,0xA6,0xDC,0x76,
    0xD5,0xAF,0xCF,0xD1,0xC8,0x7E,0xC0,0x5D,0x25,0x2A,0x31,0x90,0x33,0x16,0x32,0x30,0x2C,0x44,0x22,0x7E,0x16,0x72,0x08,0xD6,0xF9,0xBB,0xED,0x6B,0xE2,0x0B,
    0xD8,0xC8,0xCF,0xFF,0xC8,0x30,0xC3,0xFF,0x00,0xDE,0x10,0x17,0x1B,0x30,0x1E,0x5D,0x1A,0xFD,0x12,0x38,0x0C,0xD5,0x04,0x56,0xFB,0x4A,0xF2,0x90,0xEA,0x68,
    0xE2,0x00,0xDB,0x61,0xD5,0x53,0xD0,0x30,0xB4,0xE0,0x1C,0xDD,0x04,0xBB,0x03,0xBE,0x02,0x5B,0x02,0x25,0x02,0x8B,0xFF,0xE3,0xFB,0x6A,0xF8,0x81,0xF4,0x49,
    0xEE,0x91,0xE3,0xB1,0xD6,0x2C,0xCF,0x22,0xE5,0x4E,0xF3,0xFE,0x05,0x2C,0x1E,0x84,0x16,0xC9,0x0A,0x93,0x04,0x2C,0x03,0x89,0xFF,0x21,0xF8,0x9D,0xEB,0x7B,
    0xE1,0xF3,0xDD,0x99,0xDE,0x34,0xE0
};


/***********************************************AOA_THRESHOLD_PDOA***********************************************/
/**
 * AoA Threshold PDOA
 * - Octet[0]: Number of Entries (Must be greater than 0)
 *  [
 *    – Array of 1 Octet each: RX Antennas PAIR IDs as defined by ANTENNAS_RX_PAIR_DEFINE
 *    – Array of 2 Octets each: Threshold Values
 *  ] (Repeat)
 * Example to Set Threshold for Antenna Pair ID=0x01, 0x02, 0x03 for Channel 5 and 9
 * SET_DEVICE_CALIBRATION_CMD (ch Id=5, Calib Param=0x15 = Threshold PDoA, No Of Entries=3, Ant ID=0x01,Threshold PDoA Value1, 0x02,Threshold PDoA Value2, 0x03,Threshold PDoA Value3)
 * Repeat the same command for Channel 9.
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
        .paramId = AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT,                        \
        .channelId = CH_9,                                                          \
        .pCalibValue = rx_pair_1_ch_9_pdoa_calib,                                   \
        .calibLen = GET_ARRAY_SIZE(rx_pair_1_ch_9_pdoa_calib),                      \
    }                                                                               \

#define HOST_AOA_ANTENNAS_PDOA_CALIB_AP2_CH9                                        \
    {                                                                               \
        .paramName = GET_PARAM_STR(HOST_AOA_ANTENNAS_PDOA_CALIB_AP2_CH9),           \
        .paramId = AOA_ANTENNAS_PDOA_CALIB_EXTENDED_SUPPORT,                        \
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
