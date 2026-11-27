/*
 * Copyright 2012-2020,2022-2024 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PHUWBTYPES_H
#define PHUWBTYPES_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifdef UWBIOT_USE_FTR_FILE
#include "uwb_iot_ftr.h"
#else
#include "uwb_iot_ftr_default.h"
#endif

#ifdef __SES_ARM
/* does not have memory.h */
#else
#include <memory.h>
#endif

typedef unsigned char BOOLEAN;

#define EXTERNC extern

#define ENABLED  1
#define DISABLED 0

#ifndef TRUE
#define TRUE (true) /* Logical True Value */
#endif

#ifndef FALSE
#define FALSE (false) /* Logical False Value */
#endif

typedef uint8_t bool_t;     /* boolean data type */

/**
* Platform Specific Buffer Length:
*    - Macro: `#define UCI_CMD_INDEX (1)`
*    - Description: Represents the length of the platform-specific buffer. This byte is used to handle commands
                    and manage platform-related information within the communication buffer.
* Bidirectional Specific Buffer Length:
*   - Macro: `#define DIRECTION_BYTE_OFFSET (UCI_CMD_INDEX - 1)`
*   - Description: Refers to the bidirectional buffer length. This byte is primarily used for bidirectional read/write
*                  operations, particularly at the first index of the buffer.
* UCI Payload:
*   - Macro: `#define ACTUAL_PACKET_START (UCI_CMD_INDEX + N)`
*   - Description: Refers to the section of the buffer where the actual UCI (UWB Command Interface) data will be stored,
*                  starting after the platform-specific and bidirectional bytes.
*
* -Platform-Specific Buffer Usage:
*   1. Command Storage:
*   - For both SR1xx and SR2xx platforms, the platform-specific byte(s) are used to copy the UCI command, but the starting
*       index differs:
*           - SR1xx: The UCI command starts directly from the platform-specific index (index 0).
*               -Example : For SR1xx, the UCI command is directly sent from the platform-specific byte at index 0, so the same packet would look like
*                           - 21000005 44332211 00
*           - SR2xx: The zeroth index is filled by the driver with a bidirectional byte, and the UCI command starts from the first index (index 1)
*               -Example : The "zeroth index" (index 0) will be filled by the driver with the bidirectional byte, and the UCI command starts from the first index
*                           -[00]21000005 44332211 00
*
*  2. UCI Type and Extended Payload Check:
*     - During read operations, this byte is also used for checking the UCI type and for any extended payload and Data transfer checking.
*   3. Middleware (MW) and Plug-and-Play (PnP) Usage:
*     - This byte is utilized for both MW and PnP systems for managing platform-specific interactions during read and write operations.
*- Bidirectional Byte Usage:
*  1. Bidirectional Data Transmission:
*    - The bidirectional byte (located at the Zeorth index) is used for handling bidirectional read/write operations.
        It enables communication in both directions (e.g., sending commands and receiving responses).
*   - UCI Payload:
*  - The UCI payload represents the actual UCI data, including its header and payload. After processing the platform byte
 *   and updating the buffer index, the data pointer will point to the UCI payload.
 *      -  Example:
 *          - After receiving and reading the complete UCI packet:
 *              -   "FF60010001 FF01"
 *          - By applying the following macro: SHIFT_AND_OVERRIDE_HEADER The packet is transformed to:
 *              -   "FF606001000101"
 *          - The UCI payload starts from this point. This macro manipulates the buffer so that the actual UCI data is
 *            positioned after adjusting for platform-specific and bidirectional bytes.
 *
 */
#if UWBIOT_UWBD_SR2XXT && UWBIOT_TML_SPI
#define UCI_CMD_INDEX         (1)
#define DIRECTION_BYTE_OFFSET 0
#define ACTUAL_PACKET_START   (UCI_CMD_INDEX + 1)
#else
#define UCI_CMD_INDEX    (0)
#define DIRECTION_BYTE_OFFSET 0
#define ACTUAL_PACKET_START   (0)
#endif // UWBIOT_UWBD_SR2XXT && UWBIOT_TML_SPI
/* Message type Mask */
#define HDR_MT_MASK 0xE0
/* Message Type for DPF */
#define HDR_MT_DPF 0x00
/* Data Packet Format Mask */
#define HDR_DPF_MASK 0x0F
/* Data Packet Format for send/receive data with message type 0 */
#define UCI_DPF_SND    0x01 /* DATA_MESSAGE_SND: Host sends Application Data to UWBS using Bypass LL Mode */
#define UCI_DPF_RCV    0x02 /* DATA_MESSAGE_RCV: Host receives Application Data from UWBS using Bypass LL Mode */
#define UCI_DPF_LL_SND 0x03 /* LL_DATA_MESSAGE_SND: Host sends Application Data to UWBS using Logical Link Mode*/
#define UCI_DPF_LL_RCV 0x04 /* LL_DATA_MESSAGE_RCV: Host receives Application Data from UWBS using Logical Link Mode*/
#define UCI_LENGTH_OFFSET 0x03

/** Check if the Message type is Data RCV Packet */
#define IS_DATA_RCV_PACKET(HDR0)            \
    (((HDR0)&HDR_MT_MASK) == HDR_MT_DPF) && \
        ((((HDR0)&HDR_DPF_MASK) == UCI_DPF_RCV) || (((HDR0)&HDR_DPF_MASK) == UCI_DPF_LL_RCV))

/** Check if the Message type is Send Data Packet */
#define IS_DATA_SEND_PACKET(HDR0)           \
    (((HDR0)&HDR_MT_MASK) == HDR_MT_DPF) && \
        ((((HDR0)&HDR_DPF_MASK) == UCI_DPF_SND) || (((HDR0)&HDR_DPF_MASK) == UCI_DPF_LL_SND))

#define PHUWB_UNUSED(X) (void)(X);

/**
 * Deferred message. This message type will be posted to the client application
 * thread
 * to notify that a deferred call must be invoked.
 */
#define PH_LIBUWB_DEFERREDCALL_MSG (0x311)

/**
 * @brief  UWBD  Firmware Modes.
 */
typedef enum sdkMode
{
    /** Factory Firmware */
    FACTORY_FW,
    /** Mainline Firmware */
    MAINLINE_FW
} eFirmwareMode;
/**
 * @brief  Structure lists out the Firmware Image Context
 */
typedef struct phUwbFWImageContext
{
    /** pointer to the FW image to be used*/
    const uint8_t *fwImage;
    /** size of fw image */
    uint32_t fwImgSize;
    /** fw type */
    eFirmwareMode fwMode;
#if UWBIOT_UWBD_SR2XXT
    /** force firmware type */
    bool forceFwUpdate;
    /* FW Image  Patch version */
    uint8_t patchVerion;
#endif // UWBIOT_UWBD_SR2XXT
} phUwbFWImageContext_t;

/**
 * Definitions for supported protocol
 */

#ifdef __GNUC__
#define UWB_API_DEPCREATED __attribute__((deprecated))
#else
#define UWB_API_DEPCREATED
#endif

/**
 * @brief  Core Device Configuration Structure
 *
 * @note This structure can be filled with the help of SET_DEVICE_CONFIGS macro
 * @see SET_DEVICE_CONFIGS
 *
 * @example
 * uint8_t configs_array[] = {0x04, 0x05, 0x06};
 *
 * phUwbCoreDevConfig_t config[] = { SET_DEVICE_CONFIGS(0x1001, 1, ARR(0x01)),
 *                                   SET_DEVICE_CONFIGS(0x1002, 2, ARR(0x02, 0x03)),
 *                                   SET_DEVICE_CONFIGS(0x1003, 3, configs_array),
 * };
 *
 */
typedef struct phUwbCoreDevConfig
{
      /* Configuration Parameter ID */
      uint16_t param_id;
      /* Configuration Parameter Length */
      uint8_t param_len;
      /* Configuration Parameter Value */
      const uint8_t *pParam_value;
} phUwbCoreDevConfig_t;


/**
 * @brief Initializer macro for phUwbCoreDevConfig_t structure
 *
 * This macro provides a convenient way to initialize phUwbCoreDevConfig_t
 * structure members with device configuration parameters.
 *
 * @param p_id Configuration parameter ID (uint16_t)
 * @param p_len Length of the configuration parameter value (uint8_t)
 * @param p_vals Pointer to the configuration parameter value array (const uint8_t*)
 *
 * @see phUwbCoreDevConfig_t
 * @see ARR
 */
#define SET_DEVICE_CONFIGS(p_id, p_len, p_vals) \
      {.param_id = (uint16_t)(p_id), .param_len = (p_len), .pParam_value = p_vals}

/**
 * @brief  Calibration Configuration Structure
 *
 * @note This structure can be filled with the help of SET_CALIB_CONFIGS macro
 * @see SET_CALIB_CONFIGS
 *
 * @example
 *
 * uint8_t calib_array[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
 *
 * phUwbCalibConfig_t calib[] = { SET_CALIB_CONFIGS(0x2001, CH_5, 4, ARR(0x01, 0x02, 0x03, 0x04)),
 *                                SET_CALIB_CONFIGS(0x2002, CH_9, 10, calib_array),
 * };
 *
 */
typedef struct phUwbCalibConfig
{
    /* Calibration param_id */
    uint16_t calib_id;
    /* Calibration channel */
    uint8_t channel_id;
    /* Calibration length */
    uint16_t calib_len;
    /* Calibration Value */
    const uint8_t *pCalib_value;
} phUwbCalibConfig_t;

/**
 * @brief Initializer macro for phUwbCalibConfig_t structure
 *
 * This macro provides a convenient way to initialize phUwbCalibConfig_t
 * structure members with calibration configuration parameters.
 *
 * @param p_id Calibration parameter ID (uint16_t)
 * @param ch_id Calibration channel ID (uint8_t)
 * @param p_len Length of the calibration parameter value (uint16_t)
 * @param p_vals Pointer to the calibration parameter value array (const uint8_t*)
 *
 * @see phUwbCalibConfig_t
 */
#define SET_CALIB_CONFIGS(p_id, ch_id, p_len, p_vals) \
      {.calib_id = (uint16_t)(p_id), .channel_id = (ch_id), .calib_len = (p_len), .pCalib_value = p_vals}


#endif /* PHUWBTYPES_H */
