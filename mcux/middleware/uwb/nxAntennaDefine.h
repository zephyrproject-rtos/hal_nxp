/* Copyright 2021-2022, 2026 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Define antennas
 *
 * Everything in this file starts with
 *
 *  AD : Antenna Define
 */

#ifndef NX_ANTENNA_DEFINE_H
#define NX_ANTENNA_DEFINE_H

#pragma once

/** Little endian, U16 to U8
 *
 * (Helper macro)
 */
#define AD_U16_TO_AU8_LE(X) (0xFFu & (X)), (0xFFu & ((X) >> 8u))

#define AD_U32_TO_AU8_LE(X) (0xFFu & (X)), (0xFFu & ((X) >> 8u)), (0xFFu & ((X) >> 16u)), (0xFFu & ((X) >> 24u))

/** How many RX GPIO Define entries are there */
#define AD_N_RX_ENTRIES(X) ((X))

/** How many TX GPIO Define entries are there */
#define AD_N_TX_ENTRIES(X) ((X))

/** How many Pairs are defined */
#define AD_N_PAIR_ENTRIES(X) ((X))

/** How many number of registers */
#define AD_N_REGISTERS(X)   ((X))

/** Number of entries */
#define AD_N_ENTRIES(X)     ((X))

/** Define RX Antennae */
#define AD_ANTENNA_RX_IDX_DEFINE_GPIO 0xE4, 0x60

#if (UWBIOT_UWBD_SR2XXT)
/** Define TX Antennae  */
#define AD_ANTENNA_TX_IDX_DEFINE 0xE4, 0x63
#else
/** Define TX Antennae  */
#define AD_ANTENNA_TX_IDX_DEFINE   0xE4, 0x61
#endif

/** Define Antennae Pair */
#define AD_ANTENNAS_RX_PAIR_DEFINE 0xE4, 0x62

/** Define ID for RX GPIO */
#define AD_RX_ID(X) ((X))
/** Define ID for TX GPIO and Entry */
#define AD_TX_ID(X) ((X))
/** Define ID for RX Atenna Pair */
#define AD_AP_ID(X) ((X))
/** Pin for RX1 for Antenna Pair */
#define AD_AP_RX1(X) ((X))
/** Pin for RX2 for Antenna Pair */
#define AD_AP_RX2(X) ((X))
/** Pin for RX3 for Antenna Pair */
#define AD_AP_RX3(X) ((X))
/** Pin for RXC for Antenna Pair */
#define AD_AP_RXC(X) AD_AP_RX1(X)
/** Pin for RXB for Antenna Pair */
#define AD_AP_RXB(X) AD_AP_RX2(X)
/** Pin for RXA for Antenna Pair */
#define AD_AP_RXA(X) AD_AP_RX3(X)

#if defined(UWBIOT_UWBD_SR100S) && UWBIOT_UWBD_SR100S
/* In case we are compiling for Single Antenna/ToF Variant, just undef all Antenna Pair Macros */
#undef AD_AP_ID
#undef AD_AP_RX1
#undef AD_AP_RX2
#undef AD_AP_RX3
#endif

/** Channel Number for Antenna Define */
#define AD_CALIB_CN(X) ((X))

/** UCI Command for Calibration params */
#if !(UWBIOT_UWBD_SR04X)
#define AD_CALIB_CMD_GD                 0x02
#define AD_CALIB_CMD_PDOA_CALIB         0x62
#define AD_CALIB_CMD_PDOA_OFFSET        0x03
#define AD_CALIB_CMD_AOA_THRESHOLD_PDOA (0x66)
#else
#define AD_CALIB_CMD_GD                 0x0F
#define AD_CALIB_CMD_PDOA_CALIB         0x0C
#define AD_CALIB_CMD_PDOA_OFFSET        0x10
#define AD_CALIB_CMD_AOA_THRESHOLD_PDOA (0x12)
#endif // !(UWBIOT_UWBD_SR04X)
/**
 * Below Macro will decide the PDOA Calibration Step Size 11 or 9
 * Step size 9 is enabled Now .
 */
#define ENABLE_PDOA_CALIB_STEP_SIZE_9        (0x01)
#define PDOA_STEP_SIZE                       (0x0C)

#if ENABLE_PDOA_CALIB_STEP_SIZE_9
#define AD_CALIB_LEN_PDOA_CALIB              (9 * 9 * 2)
#define ENABLE_PDOA_CALIB_STEP_SIZE_11       (0)
#define PDOA_NUM_STEPS                       (0x09)
#else
#define AD_CALIB_LEN_PDOA_CALIB              (11 * 11 * 2)
#define ENABLE_PDOA_CALIB_STEP_SIZE_11       (0x01)
#define PDOA_NUM_STEPS                       (11)
#endif // ENABLE_PDOA_CALIB_STEP_SIZE_9

/* Calibration values */
#define AD_CALIB_GD(X)             AD_U16_TO_AU8_LE((X))
#define AD_CALIB_PDOA_OFFSET(X)    AD_U16_TO_AU8_LE((X))
#define AD_CALIB_THRESHOLD_PDOA(X) AD_U16_TO_AU8_LE((X))

/* RX Receiver port used */
#define AD_DEF_RX_PORT(X) ((X))
#define AD_DEF_TX_PORT(X) ((X))
#define AD_DEF_MASK(X)    AD_U16_TO_AU8_LE((X))
#define AD_DEF_VAL(X)     AD_U16_TO_AU8_LE((X))
#define AD_AP_FOV(X)      AD_U16_TO_AU8_LE((X))

/* SR1XX Specific RX port */
#define SR1XX_RX1_PORT (0x01)
#define SR1XX_RX2_PORT (0x02)
/* Invalid port only used for skipped defines add new value when required */
#define SR1XX_RX_INVALID_PORT (0x00)

/* SR2XX Specific TX RX port */
#define SR2XX_TRA1_PORT  (0x01)
#define SR2XX_TRA2_PORT  (0x02)
/* Invalid port only used for skipped defines add new value when required */
#define SR2XX_TX_INVALID_PORT (0x00)

#define SR2XX_RXC_PORT  SR1XX_RX1_PORT
#define SR2XX_RXB_PORT  SR1XX_RX2_PORT
#define SR2XX_RXA2_PORT (0x03)
#define SR2XX_RXA1_PORT (0x04)
/* Invalid port only used for skipped defines add new value when required */
#define SR2XX_RX_INVALID_PORT SR1XX_RX_INVALID_PORT

#if (UWBIOT_UWBD_SR2XXT)
/** GPIO Masks and values */
enum AD_GPIO_Configs
{
    kAD_GPIO_EF1 = 1u << 0u,
    kAD_GPIO_EF2 = 1u << 1u,
    kAD_GPIO_0   = 1u << 2u,
    kAD_GPIO_1   = 1u << 3u,
    kAD_GPIO_2   = 1u << 4u,
    kAD_GPIO_3   = 1u << 5u,
    kAD_GPIO_4   = 1u << 6u,
    kAD_RFU      = 1u << 7u,
};
#else //UWBIOT_UWBD_SR1XXT
/** GPIO Masks and values */
enum AD_GPIO_Configs
{
    kAD_GPIO_EF1 = 1u << 0u,
    kAD_GPIO_EF2 = 1u << 1u,
    kAD_GPIO_6   = 1u << 2u,
    kAD_GPIO_7   = 1u << 3u,
    kAD_GPIO_9   = 1u << 4u,
    kAD_GPIO_10  = 1u << 5u,
    kAD_GPIO_11  = 1u << 6u,
    kAD_GPIO_12  = 1u << 7u,
    kAD_GPIO_14  = 1u << 8u,
};
#endif
#endif /* NX_ANTENNA_DEFINE_H */
