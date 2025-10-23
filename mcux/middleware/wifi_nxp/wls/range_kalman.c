/** @file range_kalman.c
 *
 * @brief This file contains Kalman filter for WLS range measurements
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <osa.h>
#if CONFIG_WLS_CSI_PROC
#include "range_kalman.h"
#include <stdio.h>
#include <math.h>

#ifdef RANGE_RUN_FLT
int range_kalman(range_kalman_state *in)
{
    float range_hat, range_rate_hat;
    float nu, S1;
    float R1_11, R1_12, R1_22, W1_1, W1_2;
    float delta_T  = (float)(in->time - in->last_time) / 1000; // now seconds
    float delta_T2 = delta_T * delta_T;
    float delta_T3 = delta_T2 * delta_T;

    // state propagation
    // A = | 1 T |
    //     | 0 1 |
    range_hat      = in->last_range + delta_T * in->last_range_rate;
    range_rate_hat = in->last_range_rate;
    // residual
    nu = in->range_measurement - range_hat; // H = [1; 0]

    // propagated cov = A*R11*A' + Q
    R1_11 = in->R0_11 + delta_T * 2 * in->R0_12 + delta_T2 * in->R0_22;
    R1_12 = in->R0_12 + delta_T * in->R0_22;
    R1_22 = in->R0_22;
    // Q = | T^3/3 T^2/2 | *  drive_var
    //     | T^2/2 T     |
    R1_11 += in->drive_var * delta_T3 / 3;
    R1_12 += in->drive_var * delta_T2 / 2;
    R1_22 += in->drive_var * delta_T;

    // inovation cov S1 = y_err + H*R1*H'
    S1 = in->measurement_var + R1_11;
    // filter gain W1 = (R1*H')/S1
    W1_1 = R1_11 / S1;
    W1_2 = R1_12 / S1;

    // updated covariance R11 = R1 - W1*S1*W1'
    R1_11 -= W1_1 * S1 * W1_1;
    in->R0_11 = (R1_11 > 0) ? R1_11 : 0;
    R1_12 -= W1_1 * S1 * W1_2;
    in->R0_12 = R1_12;
    R1_22 -= W1_2 * S1 * W1_2;
    in->R0_22 = (R1_22 > 0) ? R1_22 : 0;
    // updated state
    range_hat += W1_1 * nu;
    in->last_range = (range_hat > 0) ? range_hat : 0;
    range_rate_hat += W1_2 * nu;
    in->last_range_rate = range_rate_hat;
    in->last_time       = in->time;

    PRINTF("Kalman update R mat: %f m, %f m/s; d-time: %d ms; range rate %f m/s\r\n", (double)sqrtf(in->R0_11),
           (double)sqrtf(in->R0_22), (int)(delta_T * 1000), (double)in->last_range_rate);
    return 0; // no errors
}

void range_kalman_init(range_kalman_state *in,
                       float range,
                       unsigned long long time,
                       float range_drive_var,
                       float range_measurement_var,
                       float range_rate_init)
{
    // initialize state
    in->last_range      = range;
    in->last_range_rate = 0;
    in->last_time       = time;

    in->R0_11 = range_measurement_var;
    in->R0_12 = 0;
    in->R0_22 = range_rate_init;

    // initialize parameters
    in->drive_var       = range_drive_var;
    in->measurement_var = range_measurement_var;
}

#else
int range_kalman(range_kalman_state *in)
{
    int range_hat, range_rate_hat;
    int nu, S1;
    int R1_11, R1_12, R1_22, W1_1, W1_2;
    unsigned int delta_T  = in->time - in->last_time; // format ??
    unsigned int delta_T2 = delta_T * delta_T;
    unsigned int delta_T3 = delta_T2 * delta_T;

    // state propagation
    // A = | 1 T |
    //     | 0 1 |
    range_hat      = in->last_range + delta_T * in->last_range_rate;
    range_rate_hat = in->last_range_rate;
    // residual
    nu = in->range_measurement - range_hat; // H = [1; 0]

    // propagated cov = A*R11*A' + Q
    R1_11 = in->R0_11 + delta_T * 2 * in->R0_12 + delta_T2 * in->R0_22;
    R1_12 = in->R0_12 + delta_T * in->R0_22;
    R1_22 = in->R0_22;
    // Q = | T^3/3 T^2/2 | *  drive_var
    //     | T^2/2 T     |
    R1_11 += in->drive_var * delta_T3 / 3;
    R1_12 += in->drive_var * delta_T2 / 2;
    R1_22 += in->drive_var * delta_T;

    // inovation cov S1 = y_err + H*R1*H'
    S1 = in->measurement_var + R1_11;
    // filter gain W1 = (R1*H')/S1
    W1_1 = R1_11 / S1;
    W1_2 = R1_12 / S1;

    // updated covariance R11 = R1 - W1*S1*W1'
    R1_11 -= W1_1 * S1 * W1_1;
    in->R0_11 = (R1_11 > 0) ? (unsigned short)R1_11 : 0;
    R1_12 -= W1_1 * S1 * W1_2;
    in->R0_12 = R1_12;
    R1_22 -= W1_2 * S1 * W1_2;
    in->R0_22 = (R1_22 > 0) ? (unsigned short)R1_22 : 0;
    // updated state
    range_hat += W1_1 * nu;
    in->last_range = (range_hat > 0) ? (unsigned short)range_hat : 0;
    range_rate_hat += W1_2 * nu;
    in->last_range_rate = (signed short)range_rate_hat;
    in->last_time       = in->time;

    return 0; // no errors
}
#endif

#endif /* CONFIG_WLS_CSI_PROC */
