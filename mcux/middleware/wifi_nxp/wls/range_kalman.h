#if CONFIG_WLS_CSI_PROC
/** @file range_kalman.h
 *
 * @brief This file contains Kalman filter for WLS range measurements
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef RANGE_KALMAN
#define RANGE_KALMAN

#define RANGE_RUN_FLT
#ifdef RANGE_RUN_FLT
// range is in meters, range_rate in meters/second
// time is in seconds
typedef struct
{
    // input
    unsigned long long time;
    float range_measurement;
    // state
    float last_range; // also output <--
    float last_range_rate;
    float R0_11, R0_22, R0_12;
    unsigned long long last_time;
    // model parameters
    float measurement_var;
    float drive_var;
} range_kalman_state;

void range_kalman_init(range_kalman_state *in,
                       float range,
                       unsigned long long time,
                       float range_drive_var,
                       float range_measurement_var,
                       float range_rate_init);
#else
// range format u16.8 in meters
// time format is u64.0 in milliseconds
typedef struct
{
    // input
    unsigned long long time;
    unsigned int range_measurement;
    // state
    unsigned short last_range; // also output <--
    signed short last_range_rate;
    unsigned long long last_time;
    unsigned short R0_11, R0_22;
    signed int R0_12;
    // model parameters
    unsigned int measurement_var;
    unsigned int drive_var;
} range_kalman_state;
#endif

int range_kalman(range_kalman_state *in);

#endif

#endif /* CONFIG_WLS_CSI_PROC */
