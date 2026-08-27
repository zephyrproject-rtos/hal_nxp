/* Copyright 2026 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __UWB_BOARD_H__
#define __UWB_BOARD_H__

#include <stdio.h>
#include <string.h>
#include <uwb_board_values.h>

#define UWB_BOARD_ENABLE_EXT_FLASH_BASED_FW_DOWNLOAD 1

#define UWB_BOARD_ENABLE_FW_DOWNLOAD_ON_UWBINIT 1

#if UWBIOT_UWBD_SR200S
#define UWB_BOARD_RX_ANTENNA_CONFIG_MODE_VAL UWB_BOARD_RX_ANTENNA_CONFIG_MODE_TOF
#else
#define UWB_BOARD_RX_ANTENNA_CONFIG_MODE_VAL UWB_BOARD_RX_ANTENNA_CONFIG_MODE_3DAOA
#endif

#define PRINTF(...) printf(__VA_ARGS__)

#endif // __UWB_BOARD_H__
