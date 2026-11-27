/*
 * Copyright 2026 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _UWB_DEVICECONFIG_VIRGO_H_
#define _UWB_DEVICECONFIG_VIRGO_H_

#include <stdint.h>
#include <uwb_board.h>
#include <phNxpUwbConfig.h>
#include <nxAntennaDefine.h>
#include "UwbApi_Types_Proprietary.h"

/*******************************CONFIG_DEFINES*************************************/
#define UWB_DEFAULT_CORE_CONFIGS        default_core_configs
#define UWB_DEFAULT_ANTENNA_CONFIGS     default_core_antenna_defines
/**********************************************************************************/

/* Set to 0 in case you are using Casing/Type2HQ Murata Board,
 *
 * else set to 1 */
#define USE_BARE_BOARD 0

#if (USE_BARE_BOARD)
#define TX_ANTENNA_ENTRIES 0x02
#define RX_ANTENNA_ENTRIES 0x02
#define RX_PAIR_ENTRIES    0x01
#else
#define TX_ANTENNA_ENTRIES 0x02
#define RX_ANTENNA_ENTRIES 0x04
#define RX_PAIR_ENTRIES    0x02
#endif


/************************************************************DEFAULT_CORE_DEVICE_CONFIGS************************************************************/


/**
* Default Core Device Configurations for SR2XXT
*
* This array contains essential device initialization parameters that are applied during
* UWB initialization.
*
*
* HELPER MACROS:
*   - SET_DEVICE_CONFIGS(): Wraps parameter configuration in proper structure
*   - ARR(): Creates inline array from comma-separated values
*     Example: ARR(0x01, 0x02) → {0x01, 0x02}
*   - AD_U16_TO_AU8_LE(value): Converts 16-bit value to little-endian byte array
*     Example: AD_U16_TO_AU8_LE(500) → {0xF4, 0x01} (500 in LE format)
*
* USAGE:
*   1. Modify existing configurations by changing parameter values
*   2. Add new configurations using SET_DEVICE_CONFIGS() macro
*   3. The array is automatically applied during initialization via
*      phNxpUciHal_FormDefaultCoreConfigCmd()
*
* IMPORTANT:
*   - The macro UWB_DEFAULT_CORE_CONFIGS must be defined to reference this array
*     (see line 24: #define UWB_DEFAULT_CORE_CONFIGS default_core_configs)
*   - This allows build scripts and conditional compilation to find the correct config array
*
* EXAMPLE: - Adding a new configuration:
*   SET_DEVICE_CONFIGS(TX_POWER_CONFIG, 0x02, ARR(0x0A, 0x14)),
*
*/
static const phUwbCoreDevConfig_t default_core_configs[] = {
   SET_DEVICE_CONFIGS(DPD_WAKEUP_SRC, 0x01, ARR(0x00)),
   SET_DEVICE_CONFIGS(DPD_ENTRY_TIMEOUT, 0x02, ARR(AD_U16_TO_AU8_LE(500))),
   SET_DEVICE_CONFIGS(CLK_CONFIG_CTRL, 0x05, ARR(0x00, 0xE8, 0x03, 0xE8, 0x03)),
   SET_DEVICE_CONFIGS(LOW_POWER_MODE, 0x01, ARR(0x01)),
};

/**************************************************************************************************************************************************/


/********************************************************ANTENNA_DEFINES_CORE_DEVICE_CONFIGS*******************************************************/

static const uint8_t phNxpUciHal_core_rx_index_def[] = {
    AD_N_RX_ENTRIES(RX_ANTENNA_ENTRIES),
#if (USE_BARE_BOARD)
    // Azimuth on the Naked Virgo/Tyep2HQ Murata board
    // Used for PCTT as well. EF1 Low.
    AD_RX_ID(1), AD_DEF_RX_PORT(SR2XX_RXC_PORT), AD_DEF_MASK(kAD_GPIO_EF1), AD_DEF_VAL(0x0000),
    /* On chip Antenna TX/RXA2  */
    AD_RX_ID(2), AD_DEF_RX_PORT(SR2XX_RXA2_PORT), AD_DEF_MASK(kAD_GPIO_EF1), AD_DEF_VAL(0x0000),
#else
   // H AoA for Front Patch Array on Casing board
    AD_RX_ID(1), AD_DEF_RX_PORT(SR2XX_RXC_PORT), AD_DEF_MASK(kAD_GPIO_EF1|kAD_GPIO_EF2), AD_DEF_VAL(kAD_GPIO_EF1|kAD_GPIO_EF2),
    // V AoA for Front Patch Array on Casing board.
    // NA for Naked Virgo/Tyep2HQ Murata board
    AD_RX_ID(2), AD_DEF_RX_PORT(SR2XX_RXB_PORT), AD_DEF_MASK(kAD_GPIO_EF1|kAD_GPIO_EF2), AD_DEF_VAL(kAD_GPIO_EF1|kAD_GPIO_EF2),
    /* Common RX Pin for both H and V. Goes to TX/RXA2 port of Front Patch Antenna Array  */
    AD_RX_ID(3), AD_DEF_RX_PORT(SR2XX_RXA2_PORT), AD_DEF_MASK(kAD_GPIO_EF1|kAD_GPIO_EF2), AD_DEF_VAL(kAD_GPIO_EF1|kAD_GPIO_EF2),
    /* TX/RXA1 port */
    AD_RX_ID(4), AD_DEF_RX_PORT(SR2XX_RXA1_PORT), AD_DEF_MASK(0), AD_DEF_VAL(0),
#endif // (USE_BARE_BOARD)
};

static const uint8_t phNxpUciHal_core_tx_index_def[] = {
    AD_N_TX_ENTRIES(TX_ANTENNA_ENTRIES),
    /* TRA1 Radar ant*/
    AD_TX_ID(1), AD_DEF_TX_PORT(SR2XX_TRA1_PORT), AD_DEF_MASK(0), AD_DEF_VAL(0),
#if (USE_BARE_BOARD)
    /* TRA2 On chip antenna */
    AD_TX_ID(2), AD_DEF_TX_PORT(SR2XX_TRA2_PORT), AD_DEF_MASK(kAD_GPIO_EF1), AD_DEF_VAL(0x0000),
#else
    /* TRA2 Front Patch Array*/
    AD_TX_ID(2), AD_DEF_TX_PORT(SR2XX_TRA2_PORT), AD_DEF_MASK(kAD_GPIO_EF1|kAD_GPIO_EF2), AD_DEF_VAL(kAD_GPIO_EF1|kAD_GPIO_EF2),
#endif // (USE_BARE_BOARD)
};

static const uint8_t phNxpUciHal_core_rx_pair_def[] = {
    AD_N_PAIR_ENTRIES(RX_PAIR_ENTRIES),

/* 2D-AoA */
#if (USE_BARE_BOARD)
    /* RX Pair: H Naked */
    AD_AP_ID(1), AD_AP_RXC(1), AD_AP_RXB(0), AD_AP_RXA(2), AD_AP_FOV(0x0000),
#else
    /* RX Pair: H Virgo/Tyep2HQ Murata Front Patch Array */
    AD_AP_ID(1), AD_AP_RXC(1), AD_AP_RXB(2), AD_AP_RXA(0), AD_AP_FOV(0x0000),
    /* RX Pair: V Virgo/Tyep2HQ Murata Front Patch Array */
    AD_AP_ID(2), AD_AP_RXC(0), AD_AP_RXB(2), AD_AP_RXA(3), AD_AP_FOV(0x0000),
#endif // (USE_BARE_BOARD)
};


/**
* Default Antenna Configuration Definitions
*
* This array configures the antenna subsystem including RX/TX antenna port mappings,
*
* HELPER MACROS:
*   - SET_DEVICE_CONFIGS(param_id, array_size, array_reference): Macro to set device configuration
*     Example: SET_DEVICE_CONFIGS(ANTENNA_RX_IDX_DEFINE, GET_ARRAY_SIZE(phNxpUciHal_core_rx_index_def), phNxpUciHal_core_rx_index_def)
*   - GET_ARRAY_SIZE(array): Calculates number of elements in an array
*     Example: GET_ARRAY_SIZE(phNxpUciHal_core_rx_index_def)
*
*
* USAGE:
*   1. The array is automatically applied during initialization via phNxpUciHal_FormDefaultAntennaCoreConfigCmd()
*
* IMPORTANT:
*   - The macro UWB_DEFAULT_ANTENNA_CONFIGS must be defined to reference this array
*     (see line 25: #define UWB_DEFAULT_ANTENNA_CONFIGS default_core_antenna_defines)
*   - This allows build scripts and conditional compilation to find the correct antenna config
*
*/
static const phUwbCoreDevConfig_t default_core_antenna_defines[] = {
   SET_DEVICE_CONFIGS(ANTENNA_RX_IDX_DEFINE, GET_ARRAY_SIZE(phNxpUciHal_core_rx_index_def), phNxpUciHal_core_rx_index_def),
   SET_DEVICE_CONFIGS(ANTENNA_TX_IDX_DEFINE, GET_ARRAY_SIZE(phNxpUciHal_core_tx_index_def), phNxpUciHal_core_tx_index_def),
   SET_DEVICE_CONFIGS(ANTENNAE_RX_PAIR_DEFINE, GET_ARRAY_SIZE(phNxpUciHal_core_rx_pair_def), phNxpUciHal_core_rx_pair_def),
};

/**************************************************************************************************************************************************/



/**************************************************************SET_DEVICE_CALIBRATION**************************************************************/

/**
* Default Calibration Configurations
*
* This array contains device-specific calibration parameters that fine-tune RF performance.
* These calibrations are applied during UWB device initialization to ensure accurate ranging measurements.
*
* STRUCTURE:
*   phUwbCalibConfig_t
*
*   - calib_id: Id of calibration (RX_ANT_DELAY_CALIB, TX_POWER_PER_ANTENNA, etc.)
*   - channel_id: Channel for calibration (CH_5, CH_9 ...)
*   - calib_len: Size in bytes of the calibration data array (use sizeof())
*   - pCalib_value: Pointer to the calibration data array
*
* HELPER MACROS:
*   - SET_DEVICE_CALIBRATION(calib_id, channel_id, calib_len, calib_data): Macro to set calibration configuration
*     Example: SET_DEVICE_CALIBRATION(RX_ANT_DELAY_CALIB, CH_5, sizeof(phNxpUciHal_rx_antennae_delay_calib_channel5), phNxpUciHal_rx_antennae_delay_calib_channel5)
*   - GET_ARRAY_SIZE(array): Calculates number of elements in an array
*
* USAGE:
*   1. Define calibration data arrays with appropriate values for your hardware
*   2. Add calibration configs to this array using SET_CALIB_CONFIGS() macro
*   3. Calibrations are automatically applied Sequentially during initialization via phNxpUciHal_FormDefaultCalibConfigsCmd()
*   4. The function iterates through all entries and sends each to the UWB device
*
* IMPORTANT:
*   - The macro UWB_DEFAULT_CALIBRATION_CONFIGS must be defined to reference this array
*   - This allows build scripts and conditional compilation to find the correct calibration config
*
* EXAMPLE - Adding a new calibration:
*   // 1. Define calibration data array
*   const uint8_t my_custom_calib[] = {
*       AD_N_RX_ENTRIES(2),
*       AD_RX_ID(1), AD_CALIB_GD(15100),
*       AD_RX_ID(2), AD_CALIB_GD(15110),
*   };
*
*   // 2. Add to default_calib_configs array
*   static const phUwbCalibConfig_t default_calib_configs[] = {
*       SET_DEVICE_CALIBRATION(RX_ANT_DELAY_CALIB, CH_5, sizeof(my_custom_calib), my_custom_calib),
*   };
*
*/
#if 0

static const phUwbCalibConfig_t default_calib_configs[] = {
};

#endif

/**************************************************************************************************************************************************/

/* clang-format on */

/**
 * Vendor-Specific NXP Configuration Blocks
 *
 * This array allows sending raw UCI commands to the UWB device during initialization.
 * You can define up to 10 configuration blocks (UWB_NXP_CORE_CONFIG_BLOCK_1 through
 * UWB_NXP_CORE_CONFIG_BLOCK_10) to send custom vendor commands.
 *
 * HOW TO ADD RAW COMMANDS:
 *
 * 1. Define your raw command buffer with the following format:
 *    - First byte: Total length of the command (including this length byte)
 *    - Remaining bytes: UCI command in TLV (Type-Length-Value) format
 *
 * 2. Example - Sending a vendor-specific device configuration:
 *
 *    static const uint8_t uwb_core_config_block_1[] = {
 *        0x07,                    // Total length: 7 bytes
 *        0x2F, 0x21,              // GID=0x0F (Vendor), OID=0x21
 *        0x00,                    // Extended Length byte (if needed - 0x00 otherwize)
 *        0x03,                    // Payload length
 *        0x01, 0x02, 0x03,        // Payload data (example values)
 *    };
 *
 * 3. Add the block to phNxpUciHal_NXPConfig array:
 *
 *    const NxpParam_t phNxpUciHal_NXPConfig[] = {
 *        {UWB_NXP_CORE_CONFIG_BLOCK_1, TYPE_DATA, uwb_core_config_block_1},n
 *        {UWB_NXP_CORE_CONFIG_BLOCK_2, TYPE_DATA, uwb_core_config_block_2},
 *        // ... add more blocks as needed (up to BLOCK_10)
 *
 *        // IMPORTANT: Update the count to match number of blocks defined above
 *        {UWB_NXP_CORE_CONFIG_BLOCK_COUNT, TYPE_VAL, CONFIG_VAL 2}  // Changed from 0 to 2
 *    };
 *
 * 4. Update UWB_NXP_CORE_CONFIG_BLOCK_COUNT to reflect the number of blocks you've added
 *
 * NOTES:
 * - Blocks are sent sequentially during UWB device initialization in setVendorConfigs()
 * - Each block is sent as a raw UCI command via sendRawUci()
 * - Maximum 10 blocks are supported (BLOCK_1 through BLOCK_10)
 * - Setting COUNT to 0 means no vendor configs will be sent (current default for SR2XXT)
 *
 */
static const NxpParam_t phNxpUciHal_NXPConfig[] = {
    /* Example (commented out):
     * {UWB_NXP_CORE_CONFIG_BLOCK_1, TYPE_DATA, uwb_core_config_block_1},
     * {UWB_NXP_CORE_CONFIG_BLOCK_2, TYPE_DATA, uwb_core_config_block_2},
     */

    /* Number of UWB_NXP_CORE_CONFIG_BLOCKS available in the config file */
    {UWB_NXP_CORE_CONFIG_BLOCK_COUNT, TYPE_VAL, CONFIG_VAL 0}};

#endif //_UWB_DEVICECONFIG_VIRGO_H_
