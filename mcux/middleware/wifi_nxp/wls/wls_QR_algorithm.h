#if CONFIG_WLS_CSI_PROC
/** @file wls_QR_algorithm.h
 *
 * @brief This file contains header for QR math functions
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * DFW header for QR math functions
 ************************************************************************/

#ifndef WLS_QR_ALGORITHM_H
#define WLS_QR_ALGORITHM_H

// MAX_MAT_SIZE needs to be >=2*SIG_SUBSP_DIM_MAX
#define MAX_MAT_SIZE 16

#ifdef ARM_DS5
#define SQRTF(x) __sqrt(x)
#define FABSF(x) __fabsf(x)
#else
#define SQRTF(x) sqrtf(x)
#define FABSF(x) fabsf(x)
#endif

// eigen(Shur) decomposition for symmetric matrix, returns eigen vectors in Q
int QR_algorithm(float *inMatArr, float *resD, int matSizeN, int low_accuracy);

// eigen(Shur) decomposition for unsymmetric matrix, no Q
int unsym_QR_algorithm(float *inMatArr, float *resD, int matSizeN);

// solves LS using QR
void QR_decomposition(float *inMatArr, float *resD, int matSizeN, int matSizeM);

void myBackSub(float *Q_MATR, float *R_MATR, float *MAT_OUT, int matSizeN, int matSizeM);

#endif

#endif /* CONFIG_WLS_CSI_PROC */
