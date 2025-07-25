#if CONFIG_WLS_CSI_PROC
/** @file wls_radix4Fft.h
 *
 * @brief This file contains header file for fixed-point FFT functions
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * DFW header file for fixed-point FFT functions
 ************************************************************************/

#ifndef WLS_RADIX4_FFT
#define WLS_RADIX4_FFT

#include "wls_param_defines.h"

#define INT8  signed char
#define INT16 short
#define INT32 int
#ifdef STA_20_ONLY
#define MAX_FFT_SIZE_256
#define MAX_FFT_SIZE 256
#else
#define MAX_FFT_SIZE_2048
#define MAX_FFT_SIZE 2048
#endif
// #define TWIDDLE_HALF_SIZE
#define TWIDDLE_BIPT 15
// #define BIASED_ROUNDING

// call separate stages
void radix4FftStageOne(INT16 *pSrc, INT16 *pDst, int Nfft);
void radix4FftMainStages(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);
void radix4FftLastStage(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);

void radix4IfftStageOne(INT16 *pSrc, INT16 *pDst, int Nfft);
void radix4IfftMainStages(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);
void radix4IfftLastStage(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);

// auxiliary function
unsigned int reverse(register unsigned int x);
#ifndef ARM_DS5
unsigned int __clz(uint32_t x);
#endif

void radix4Fft(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);
void radix4Fft4in64(unsigned int *loadPtr, unsigned int *fftOutBfr, const INT16 *pCoeff, int lenCoeff);

void radix4Ifft(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);
void radix4IfftParallel(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);
void radix4IfftStride(INT16 *pSrc, INT16 *pDst, int Nfft, const INT16 *pCoeff, int lenCoeff);

void radix2Ifft(INT16 *pSrc, int Nfft, const INT16 *pCoeff, int lenCoeff);
void radix2IfftParallel(INT16 *pSrc, int Nfft, const INT16 *pCoeff, int lenCoeff);
void radix2IfftStride(INT16 *pSrc, int Nfft, const INT16 *pCoeff, int lenCoeff);

void radix2FftFlt(float *pBfr, int Nfft, const float *pCoeff, int lenCoeff);
void radix2IfftFlt(float *pBfr, int Nfft, const float *pCoeff, int lenCoeff);

#define MAX_FFT_FLT 64
extern const float twiddleTableFlt[2 * MAX_FFT_FLT];

#ifdef TWIDDLE_HALF_SIZE
extern const INT16 radix4FftTwiddleArr[MAX_FFT_SIZE];
#else
extern const INT16 radix4FftTwiddleArr[2 * MAX_FFT_SIZE];
#endif

#endif

#endif /* CONFIG_WLS_CSI_PROC */
