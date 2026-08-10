/* Copyright 2022,2023 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/** @file uwb_board_values.h
 *
 * Values used by uwb_board.h */

#ifndef UWB_BAORD_VALUES_H
#define UWB_BAORD_VALUES_H

#pragma once

#ifdef UWBIOT_USE_FTR_FILE
#include "uwb_iot_ftr.h"
#else
#include "uwb_iot_ftr_default.h"
#endif

/** Board Variants
 *
 * @{ */

// Board Variants are defined below:
#define BOARD_VERSION_NXPREF 0x00

#define BOARD_VARIANT_CUSTREF1 0x2A

#define BOARD_VARIANT_CUSTREF2 0x2B

#define BOARD_VARIANT_RHODES 0x73

#define BOARD_VARIANT_P71 0x02

#define UWB_BOARD__BOARD_VARIANT_NXPREF 0

#define UWB_BOARD_RHODES_V4 4

#define UWB_BOARD_RHODES_P71 0x02

/* Select Board Variant here */
#if UWBIOT_UWBD_SR1XXT
#if UWBIOT_SESN_P71
#define UWBS_BOARD_VARIANT BOARD_VARIANT_P71
#define UWBS_BOARD_VERSION UWB_BOARD_RHODES_P71
#else
#define UWBS_BOARD_VARIANT BOARD_VARIANT_RHODES
#define UWBS_BOARD_VERSION UWB_BOARD_RHODES_V4
#endif // UWBIOT_SESN_P71
#endif // UWBIOT_UWBD_SR1XXT
#if UWBIOT_UWBD_SR2XXT
#define UWBS_BOARD_VARIANT UWB_BOARD__BOARD_VARIANT_NXPREF
#define UWBS_BOARD_VERSION BOARD_VERSION_NXPREF
#endif // UWBIOT_UWBD_SR1XXT

#define BOARD_VARIANT     UWBS_BOARD_VARIANT
#define UWB_BOARD_VERSION UWBS_BOARD_VERSION

/** @} */

/* Used by uwb_board.h to select what is the mode of RX for the Session.
 *
 * See as well @ref kUWBAntCfgRxMode_t
 *
 * @{
 */

/** Single antenna mode */
#define UWB_BOARD_RX_ANTENNA_CONFIG_MODE_TOF 1

/** 2D AoA mode */
#define UWB_BOARD_RX_ANTENNA_CONFIG_MODE_2DAOA 2

/** 3D AoA Mode. Only for V3 Demonstrator */
#define UWB_BOARD_RX_ANTENNA_CONFIG_MODE_3DAOA 3

/** @} */

#endif // UWB_BAORD_VALUES_H
