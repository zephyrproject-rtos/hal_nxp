/** @file wls_subspace_processing.c
  *
  * @brief This file contains source code to calculate fine timing using sub-space methods (ESPRIT)
  *
  * Copyright 2023-2024 NXP
  *
  * SPDX-License-Identifier: BSD-3-Clause
  *
  */

/************************************************************************
* DFW Source code to calculate fine timing using sub-space methods (ESPRIT)
************************************************************************/

#include <osa.h>
#if CONFIG_WLS_CSI_PROC

// Standard includes.
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <math.h>
// 4 sqrtf, 1 atan2f, 1 atanf, 2 floorf
#ifdef ARM_DS5
#include <arm_neon.h>
#endif

// Specific includes.
#include "wls_subspace_processing.h"
#include "wls_param_defines.h"
#include "wls_QR_algorithm.h"
#include "wls_radix4Fft.h"

#define FFT_INPUT_SIZE_MAX 32
#define FFT_INPUT_SIZE_SHORT_WINDOW 16
#define FFT_INPUT_SIZE_LONG_WINDOW 32

#ifdef STA_20_ONLY
#define BUFFER_OFFSET (12*MAX_FFT_SIZE/2)
#else
#define BUFFER_OFFSET (3*MAX_FFT_SIZE/2)
#endif
#define SUBSP_DIM_L_MAX MAX_MAT_SIZE
//needs to be floor(0.75*SUB_DIM_L)
#define SIG_SUBSP_DIM_MAX 7 // 15

#define MUSIC_THRESH_REL_5GHz 0.01f
#define MUSIC_THRESH_REL_2GHz 0.1f
#define MUSIC_THRESH_MIN 0.02f
#define MUSIC_THRESH_MAX 0.10f

#define SUB_DET_THRESH_5G_80MHZ 0.1f
#define SUB_DET_THRESH_5G_40MHZ 0.08f
#define SUB_DET_THRESH_5G_20MHZ 0.04f // 0.1f
#define SUB_DET_THRESH_20MHZ 0.253f
#define SUB_DET_THRESH_Legacy 0.38f
#define SUB_DET_THRESH_REL_5G_80MHZ 0.01f
#define SUB_DET_THRESH_REL_5G_40MHZ 0.025f
#define SUB_DET_THRESH_REL_5G_20MHZ 0.005f
#define SUB_DET_THRESH_REL_2G 0.015f
#define SUB_DET_THRESH_REL_Legacy 0.25f

#define SUB_DIM_L_6 6
#define SUB_DIM_L_10 10
#define SUB_DIM_L_12 12
#define SUB_DIM_L_16 16
#define SUB_DIM_L_20 20
#define SUB_DIM_L_22 22

#define USE_TLS
#define FFT_TD_OSF_SHIFT 1
#define FFT_FD_EDGE 0

void calcCorMatrix(hal_pktinfo_t *pktinfo, unsigned int *fftOutBuffer, unsigned int *totalpower, int firstPathDelay, float *realCorrMatrix,
	unsigned int *scratchMemory, int subsp_dim_L, int fft_input_size, int FD_downsample, int* numObsPtr)
{

	int ii, jj, kk, ll, rowIdx, colIdx, qq;
	int loadOffset;
	float *fftTempBuffer = (float*)scratchMemory; //[2*(FFT_INPUT_SIZE_MAX<<FFT_TD_OSF_SHIFT)];
	float *strPtr, *strPtrTr, *ldPtr, *ldPtrTr;
	//float debugBuffer[FFT_INPUT_SIZE_MAX];
	float *corrMatrix = (float*)scratchMemory +2* (FFT_INPUT_SIZE_MAX << FFT_TD_OSF_SHIFT); // size: [SUBSP_DIM_L_MAX*2*SUBSP_DIM_L_MAX];
	unsigned int *loadPtr;
	unsigned int tempVal, loadOffsetU32, loadOffsetMask;
	short tempI, tempQ;
	float valI, valQ, valTempI, valTempQ, scale;
	float corrI, corrQ, sumI, sumQ;
	float *tempBuffer = (float*)scratchMemory + 2 * (FFT_INPUT_SIZE_MAX << FFT_TD_OSF_SHIFT) + 2 * SUBSP_DIM_L_MAX *  SUBSP_DIM_L_MAX; // [2*FFT_INPUT_SIZE_MAX];
	int storeIdx, loadIdx;

	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);

	int firstPathIndex = (firstPathDelay+(1<<(TOA_FPATH_BIPT-1)))>>TOA_FPATH_BIPT;
	int windowStart = firstPathIndex-(fft_input_size <<(IFFT_OSF_SHIFT-1)); // center window middle on first-path

	int stepsize = 1<<(IFFT_OSF_SHIFT - FFT_TD_OSF_SHIFT);
	int numObs = fft_input_size - subsp_dim_L - 2*FFT_FD_EDGE;

	memset((void*)corrMatrix, 0, 2*SUBSP_DIM_L_MAX*SUBSP_DIM_L_MAX*sizeof(float));
	loadOffsetMask = ifftSizeOsf*NUM_PARALLEL - 1;

	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj+=NUM_PARALLEL){

			for (qq = 0;qq < NUM_PARALLEL; qq++) {
				loadPtr = fftOutBuffer + (jj + ii*nRx)*ifftSizeOsf + qq;
				loadOffset = windowStart*NUM_PARALLEL;
				scale = SQRTF(1.0f*nTx*nRx*totalpower[(jj + qq) + ii*nRx] / (1 << 15)) / (1 << (8 + FFT_TD_OSF_SHIFT)); // 32.31 format
				strPtr = fftTempBuffer;
				for (kk = 0;kk < (fft_input_size << FFT_TD_OSF_SHIFT) * FD_downsample;kk++) {
					loadOffsetU32 = loadOffset &loadOffsetMask;
					tempVal = loadPtr[loadOffsetU32];
					loadOffset += stepsize*NUM_PARALLEL;
					tempI = tempVal & 0xffff;
					tempQ = (tempVal >> 16) & 0xffff;

					valI = tempI*scale;
					*strPtr++ = valI;
					valQ = tempQ*scale;
					*strPtr++ = valQ;
				}
				radix2FftFlt(fftTempBuffer, (fft_input_size << FFT_TD_OSF_SHIFT) * FD_downsample, twiddleTableFlt, MAX_FFT_FLT);
				if (FD_downsample == 4) {
					for (ll = 1;ll < fft_input_size;ll++) {
						fftTempBuffer[2 * ll] = fftTempBuffer[2 * FD_downsample * ll];
						fftTempBuffer[2 * ll + 1] = fftTempBuffer[2 * FD_downsample * ll + 1];
					}
				}
				// diagonal
				// rowIdx = 0
				ldPtr = fftTempBuffer + 2*(FFT_FD_EDGE+1); // skip 0
				strPtr = corrMatrix;
				sumI = 0;
				storeIdx = 0;
				for (kk = 0;kk < numObs;kk++) {
					valI = *ldPtr++; // fftTempBuffer[2 * kk];
					valQ = *ldPtr++; // fftTempBuffer[2 * kk + 1];
					corrI = valI*valI + valQ*valQ;
					sumI += corrI;
					tempBuffer[storeIdx++] = corrI;
				}
				*strPtr += sumI; //corrMatrix[0]
				strPtr += 2 * (SUBSP_DIM_L_MAX + 1);
				loadIdx = 0;
				for (rowIdx = 1;rowIdx < subsp_dim_L;rowIdx++) {
					sumI -= tempBuffer[loadIdx++];
					valI = *ldPtr++; // fftTempBuffer[2 * (rowIdx-1 + kk)];
					valQ = *ldPtr++; // fftTempBuffer[2 * (rowIdx-1 + kk) + 1];
					corrI = valI*valI + valQ*valQ;
					sumI += corrI;
					tempBuffer[storeIdx++] = corrI;
					*strPtr += sumI; //corrMatrix[rowIdx * 2 * (SUBSP_DIM_L_MAX+1)] += sumI;
					strPtr += 2 * (SUBSP_DIM_L_MAX + 1);
				}
				// off-diagonals
				for (colIdx = 1; colIdx < subsp_dim_L; colIdx++) {
					// rowIdx = 0
					ldPtr = fftTempBuffer + 2 * (FFT_FD_EDGE + 1);
					ldPtrTr = fftTempBuffer + 2 * (FFT_FD_EDGE + 1) + 2 * colIdx;
					strPtr = corrMatrix + 2 * colIdx * SUBSP_DIM_L_MAX;
					sumI = 0;
					sumQ = 0;
					storeIdx = 0;
					for (kk = 0;kk < numObs;kk++) {

						valI = *ldPtrTr++; //fftTempBuffer[2 * (colIdx + kk)];
						valQ = *ldPtrTr++; //fftTempBuffer[2 * (colIdx + kk) + 1];

						valTempI = *ldPtr++; //fftTempBuffer[2 * kk];
						valTempQ = *ldPtr++; //fftTempBuffer[2 * kk + 1];

						corrI = valI*valTempI + valQ*valTempQ;
						corrQ = valQ*valTempI - valI*valTempQ;

						sumI += corrI;
						sumQ += corrQ;

						tempBuffer[storeIdx++] = corrI;
						tempBuffer[storeIdx++] = corrQ;
					}
					*strPtr++ += sumI; //corrMatrix[2 * colIdx * SUBSP_DIM_L_MAX]
					*strPtr++  -= sumQ; //corrMatrix[2 * colIdx * SUBSP_DIM_L_MAX + 1]
					strPtr += 2 * SUBSP_DIM_L_MAX;
					loadIdx = 0;
					for (rowIdx = 1;rowIdx < subsp_dim_L - colIdx;rowIdx++) {
						sumI -= tempBuffer[loadIdx++];
						sumQ -= tempBuffer[loadIdx++];

						valI = *ldPtrTr++; //fftTempBuffer[2 * (rowIdx - 1 + colIdx + kk)];
						valQ = *ldPtrTr++; //fftTempBuffer[2 * (rowIdx - 1 + colIdx + kk) + 1];

						valTempI = *ldPtr++; //fftTempBuffer[2 * (rowIdx - 1 + kk)];
						valTempQ = *ldPtr++; //fftTempBuffer[2 * (rowIdx - 1 + kk) + 1];

						corrI = valI*valTempI + valQ*valTempQ;
						corrQ = valQ*valTempI - valI*valTempQ;

						sumI += corrI;
						sumQ += corrQ;

						tempBuffer[storeIdx++] = corrI;
						tempBuffer[storeIdx++] = corrQ;

						*strPtr++ += sumI; //corrMatrix[(rowIdx + colIdx) * 2 * SUBSP_DIM_L_MAX + 2 * rowIdx]
						*strPtr++ -= sumQ; //corrMatrix[(rowIdx + colIdx) * 2 * SUBSP_DIM_L_MAX + 2 * rowIdx + 1]
						strPtr += 2 * SUBSP_DIM_L_MAX;
					}
				}
			}
		}
	}
	for (rowIdx = 0;rowIdx < subsp_dim_L;rowIdx++) {
		ldPtr = corrMatrix + (rowIdx * 2 * SUBSP_DIM_L_MAX);
		strPtrTr = corrMatrix +(2 * rowIdx);
		for (colIdx = 0;colIdx < rowIdx;colIdx++) {

			corrI = *ldPtr++; // use symmetry
			corrQ = *ldPtr++;

			*strPtrTr++ = corrI;
			*strPtrTr = -corrQ; strPtrTr += 2* SUBSP_DIM_L_MAX -1;
		}
	}

	// create real matrix
	for(rowIdx=0;rowIdx<subsp_dim_L/2;rowIdx++){
		ldPtr = corrMatrix +(rowIdx * 2 * SUBSP_DIM_L_MAX);
		ldPtrTr = corrMatrix + (((subsp_dim_L - 1) - rowIdx) * 2 * SUBSP_DIM_L_MAX + 2 * (subsp_dim_L - 1) + 1);
		strPtr = realCorrMatrix + (rowIdx*SUBSP_DIM_L_MAX);
		strPtrTr = realCorrMatrix + (rowIdx + subsp_dim_L / 2)*SUBSP_DIM_L_MAX;
		for(colIdx=0;colIdx<subsp_dim_L/2;colIdx++){
			valI = *ldPtr++; // R00
			valQ = *ldPtr++;

			corrQ = *ldPtrTr--;
			corrI = *ldPtrTr--; // JR11J
			valTempI = valI + corrI;
			valTempQ = valQ - corrQ;

		    // Ax = real(myR00+conj(myJR11J));
			// Bx = imag(myR00+conj(myJR11J));
			strPtr[subsp_dim_L / 2] = valTempQ; // Bx
			*strPtr++ = valTempI; // Ax
			strPtrTr[subsp_dim_L / 2] = valTempI; // Ax
			*strPtrTr++ = -valTempQ; // -Bx
		}
	}
	for(rowIdx=0;rowIdx<subsp_dim_L/2;rowIdx++){
		ldPtr = corrMatrix + (((subsp_dim_L - 1) - rowIdx) * 2 * SUBSP_DIM_L_MAX);
		ldPtrTr = corrMatrix + ((subsp_dim_L - 1) * 2 * SUBSP_DIM_L_MAX + 2 * rowIdx);
		strPtr = realCorrMatrix+ (rowIdx*SUBSP_DIM_L_MAX);
		strPtrTr = realCorrMatrix + (rowIdx + subsp_dim_L / 2)*SUBSP_DIM_L_MAX;
		for(colIdx=0;colIdx<subsp_dim_L/2;colIdx++){
			valI = *ldPtrTr++; // R01J
			valQ = *ldPtrTr; ldPtrTr -= 2 * SUBSP_DIM_L_MAX +1;

			corrI = *ldPtr++; // R01J.'
			corrQ = *ldPtr++;
			valTempI = valI + corrI;
			valTempQ = valQ + corrQ;
			// Cx = real(myR01J+conj(myR01J'));
			// Dx = imag(myR01J+conj(myR01J'));
			strPtr[subsp_dim_L / 2] += valTempQ; // Dx
			*strPtr++ += valTempI; // Cx
			strPtrTr[subsp_dim_L/2] -= valTempI; // -Cx
			*strPtrTr++ += valTempQ; // Dx
		}
	}
	*numObsPtr = numObs;

	// scale input by 1/((fft_input_size-SUBSP_DIM_L+1)*nRx*nTx) - no
}

int findSigSpace(float *inputBuff, float *eMatrix, float thresh, int matSizeN, hal_pktinfo_t *pktinfo, float sub_det_thresh_rel)
{
	int ii, jj;
	float *eigVals = inputBuff;
	float *Qmat = inputBuff+SUBSP_DIM_L_MAX;
	float *tempMatSum; // tempMatSum[SUBSP_DIM_L*SUBSP_DIM_L];
	float *tempMatDiff; // tempMatDiff[SUBSP_DIM_L*SUBSP_DIM_L];
	float max;
	int maxIdx;
	int sigSpaceDim = 0;

	// find max for thresh
	max = 0;
	for (jj = 0; jj<matSizeN; jj++){
		if (eigVals[jj]>max){
			max = eigVals[jj];
		}
	}

	if (sub_det_thresh_rel*max > thresh)
		thresh = sub_det_thresh_rel*max;

	for(ii=0;ii<SIG_SUBSP_DIM_MAX;ii++){
		// sort
		max = 0;
		maxIdx = -1;
		for(jj=0;jj<matSizeN;jj++){
			if(eigVals[jj]>max){
				max = eigVals[jj];
				maxIdx = jj;
			}
		}
		if(max>thresh){
			eigVals[maxIdx] = 0;
			// copy eigVec
			for(jj=0;jj<matSizeN;jj++){
				eMatrix[jj+sigSpaceDim*matSizeN] = Qmat[jj+maxIdx*SUBSP_DIM_L_MAX];
			}
			sigSpaceDim++;
		}
	}

	//if (sigSpaceDim > 1){
	tempMatSum = (float*) inputBuff; // tempMatSum[SUBSP_DIM_L*SUBSP_DIM_L];
	//tempMatDiff = (float*) inputBuff+SUBSP_DIM_L*SUBSP_DIM_L; // tempMatDiff[SUBSP_DIM_L*SUBSP_DIM_L]
	tempMatDiff = (float*) inputBuff+ SUBSP_DIM_L_MAX*SUBSP_DIM_L_MAX; // tempMatDiff[SUBSP_DIM_L*SUBSP_DIM_L]
	for (ii = 0; ii<sigSpaceDim; ii++){
		for(jj=1;jj<matSizeN;jj++){
			tempMatSum[jj-1+ii*matSizeN] = eMatrix[jj-1+ii*matSizeN]+eMatrix[jj+ii*matSizeN];
			tempMatDiff[jj-1+ii*matSizeN] = eMatrix[jj-1+ii*matSizeN]-eMatrix[jj+ii*matSizeN];
		}
		tempMatSum[jj-1+ii*matSizeN] = SQRTF(2)*eMatrix[matSizeN/2-1+ii*matSizeN];
		tempMatDiff[jj-1+ii*matSizeN] = -SQRTF(2)*eMatrix[matSizeN-1+ii*matSizeN];
	}

	for(ii=0;ii<sigSpaceDim;ii++){
		for(jj=0;jj<matSizeN/2-1;jj++){
			// E_lower
			eMatrix[jj+ii*SUBSP_DIM_L_MAX] = tempMatSum[jj+ii*matSizeN];
			// E_upper
			eMatrix[jj+(ii+sigSpaceDim)*SUBSP_DIM_L_MAX] = -tempMatDiff[(jj+matSizeN/2)+ii*matSizeN];
		}
		// E_lower
		eMatrix[jj+ii*SUBSP_DIM_L_MAX] = tempMatSum[matSizeN-1+ii*matSizeN];
		// E_upper
		eMatrix[jj+(ii+sigSpaceDim)*SUBSP_DIM_L_MAX] = tempMatDiff[matSizeN-1+ii*matSizeN];

		for(jj++;jj<matSizeN-1;jj++){
			// E_lower
			eMatrix[jj+ii*SUBSP_DIM_L_MAX] = tempMatSum[jj+ii*matSizeN];
			// E_upper
			eMatrix[jj+(ii+sigSpaceDim)*SUBSP_DIM_L_MAX] = tempMatDiff[(jj-matSizeN/2)+ii*matSizeN];
		}
		for (;jj < SUBSP_DIM_L_MAX;jj++) {
			eMatrix[jj + ii*SUBSP_DIM_L_MAX] = 0;
			eMatrix[jj + (ii + sigSpaceDim)*SUBSP_DIM_L_MAX] = 0;
		}
	}
	return sigSpaceDim;
}

void calcDimOnePhase(float *eMatrix, float *omega_hat_sort, int matSizeN){

	int ii;
	float sumI, sumQ, omega_hat_pos;
	//float* tempVecReal = eMatrix + SUBSP_DIM_L; // tempVecReal[SUBSP_DIM_L];
	//float* tempVecImag = eMatrix + 2*SUBSP_DIM_L; // tempVecImag[SUBSP_DIM_L];
	float* tempVecReal = eMatrix + SUBSP_DIM_L_MAX; // tempVecReal[SUBSP_DIM_L];
	float* tempVecImag = eMatrix + 2*SUBSP_DIM_L_MAX; // tempVecImag[SUBSP_DIM_L];
	float *V1_real, *V2_Real, *V1_imag, *V2_imag;

	// copy real eigen vectors
	for (ii = 0; ii < matSizeN/2; ii++){
		tempVecReal[ii] = eMatrix[ii];
		tempVecReal[ii + matSizeN / 2] = eMatrix[matSizeN / 2 - 1 - ii];
		tempVecImag[ii] = eMatrix[ii + matSizeN / 2];
		tempVecImag[ii + matSizeN / 2] = -eMatrix[matSizeN -1 - ii];
	}

	V1_real = tempVecReal;
	V2_Real = tempVecReal +1;
	V1_imag = tempVecImag;
	V2_imag = tempVecImag +1;

	sumI = 0.0f;
	sumQ = 0.0f;
	for (ii = 0; ii < matSizeN-1; ii++){
		sumI += V1_real[ii] * V2_Real[ii] + V1_imag[ii] * V2_imag[ii];
		sumQ += V1_real[ii] * V2_imag[ii] - V1_imag[ii] * V2_Real[ii];
	}

	omega_hat_pos = -1 * atan2f(sumQ, sumI);
	omega_hat_sort[0] = (omega_hat_pos>0) ? omega_hat_pos : (omega_hat_pos + 2 * PI);
}

void calc_QpTimesE(float *eMatrix, float *qMatrix, float *qPeMatrix, int matSizeN, int matSizeM){

	int ii, jj, kk;
	float sum;

	for(ii=0;ii<matSizeM;ii++){
		for(jj=0;jj<matSizeN;jj++){
			sum = 0;
			for(kk=0;kk<matSizeN;kk++){
				sum += qMatrix[kk+jj*SUBSP_DIM_L_MAX]*eMatrix[kk+ii*SUBSP_DIM_L_MAX];
			}
			qPeMatrix[jj+ii*SUBSP_DIM_L_MAX] = sum;
		}
	}
}

void constructVmatrix(float *eigValPlusVec, float *vMatrix, int sigSpaceDim, int matSizeN){

	int ii, jj;
	float *eigVals = eigValPlusVec;
	float *Qmat = eigValPlusVec+SUBSP_DIM_L_MAX;

	float min;
	int minIdx;

	for(ii=0;ii<sigSpaceDim;ii++){
		// sort
		min = 1e3f;
		minIdx = -1;
		for(jj=0;jj<matSizeN;jj++){
			if(eigVals[jj]<min){
				min = eigVals[jj];
				minIdx = jj;
			}
		}
		eigVals[minIdx] = 1e3f;
		// copy eigVec
		for(jj=0;jj<sigSpaceDim;jj++){
			// V upper
			vMatrix[ii+jj*SUBSP_DIM_L_MAX] = -Qmat[jj+minIdx*SUBSP_DIM_L_MAX];
		}
		for(;jj<matSizeN;jj++){
			// V lower
			vMatrix[ii+jj*SUBSP_DIM_L_MAX] = Qmat[jj+minIdx*SUBSP_DIM_L_MAX];
		}
	}
}

void calcEtimesE(float *eMatrix, float *ePeMatrix, int matSizeN, int matSizeM){
	int ii, jj, kk;
#ifdef ARM_DS5
	float32x2_t resVec0, resVec1, resVec2, resVec3, strVec0, strVec1;
	float32x2_t rowVec0, rowVec1, colVec0, colVec1;
	float32x2x2_t tempVec0; //, tempVec1;

	for(ii=0;ii<matSizeM;ii+=2){
		for(jj=0;jj<=ii;jj+=2){
			resVec0 =  vdup_n_f32(0.0f);
			resVec1 =  vdup_n_f32(0.0f);
			resVec2 =  vdup_n_f32(0.0f);
			resVec3 =  vdup_n_f32(0.0f);
			for(kk=0;kk<matSizeN;kk+=2){
				rowVec0  = vld1_f32((float32_t const *) (eMatrix+(kk+jj*SUBSP_DIM_L_MAX)));
				rowVec1  = vld1_f32((float32_t const *) (eMatrix+(kk+(jj+1)*SUBSP_DIM_L_MAX)));

				colVec0  = vld1_f32((float32_t const *) (eMatrix+(kk+ii*SUBSP_DIM_L_MAX)));
				colVec1  = vld1_f32((float32_t const *) (eMatrix+(kk+(ii+1)*SUBSP_DIM_L_MAX)));

				resVec0 = vmla_f32(resVec0, rowVec0, colVec0);
				resVec1 = vmla_f32(resVec1, rowVec1, colVec0);
				resVec2 = vmla_f32(resVec2, rowVec0, colVec1);
				resVec3 = vmla_f32(resVec3, rowVec1, colVec1);
			}
			strVec0 = vpadd_f32(resVec0, resVec1);
			strVec1 = vpadd_f32(resVec2, resVec3);

			vst1_f32((float32_t *) (ePeMatrix + jj+ii*SUBSP_DIM_L_MAX), strVec0); // VST1.32 {d0}, [r0]
			vst1_f32((float32_t *) (ePeMatrix + jj + (ii + 1)*SUBSP_DIM_L_MAX), strVec1);
			// use symmetry
			tempVec0 = vzip_f32(strVec0, strVec1); // VZIP.32 d0,d0
			vst1_f32((float32_t *) (ePeMatrix + ii +jj*SUBSP_DIM_L_MAX), tempVec0.val[0]); // VST1.32 {d0}, [r0]
			vst1_f32((float32_t *) (ePeMatrix + ii + (jj + 1)*SUBSP_DIM_L_MAX), tempVec0.val[1]);
		}
	}
#else
	float sum, sum1, sum2,sum3;

	for(ii=0;ii<matSizeM;ii+=2){
		for(jj=0;jj<matSizeM;jj+=2){
			sum = 0;
			sum1 = 0;
			sum2 = 0;
			sum3 = 0;
			for(kk=0;kk<matSizeN;kk+=2){
				sum += eMatrix[kk+jj*SUBSP_DIM_L_MAX]*eMatrix[kk+ii*SUBSP_DIM_L_MAX];
				sum1 += eMatrix[kk + (jj+1)*SUBSP_DIM_L_MAX] * eMatrix[kk + ii*SUBSP_DIM_L_MAX];
				sum2 += eMatrix[kk + jj*SUBSP_DIM_L_MAX] * eMatrix[kk + (ii + 1)*SUBSP_DIM_L_MAX];
				sum3 += eMatrix[kk + (jj + 1)*SUBSP_DIM_L_MAX] * eMatrix[kk + (ii + 1)*SUBSP_DIM_L_MAX];
				sum += eMatrix[(kk+1) + jj*SUBSP_DIM_L_MAX] * eMatrix[(kk + 1) + ii*SUBSP_DIM_L_MAX];
				sum1 += eMatrix[(kk + 1) + (jj + 1)*SUBSP_DIM_L_MAX] * eMatrix[(kk + 1) + ii*SUBSP_DIM_L_MAX];
				sum2 += eMatrix[(kk + 1) + jj*SUBSP_DIM_L_MAX] * eMatrix[(kk + 1) + (ii + 1)*SUBSP_DIM_L_MAX];
				sum3 += eMatrix[(kk + 1) + (jj + 1)*SUBSP_DIM_L_MAX] * eMatrix[(kk + 1) + (ii + 1)*SUBSP_DIM_L_MAX];
			}
			//if (kk < matSizeN) { // odd matSizeN case
			//	sum += eMatrix[kk + jj*SUBSP_DIM_L_MAX] * eMatrix[kk + ii*SUBSP_DIM_L_MAX];
			//	sum1 += eMatrix[kk + (jj + 1)*SUBSP_DIM_L_MAX] * eMatrix[kk + ii*SUBSP_DIM_L_MAX];
			//	sum2 += eMatrix[kk + jj*SUBSP_DIM_L_MAX] * eMatrix[kk + (ii + 1)*SUBSP_DIM_L_MAX];
			//	sum3 += eMatrix[kk + (jj + 1)*SUBSP_DIM_L_MAX] * eMatrix[kk + (ii + 1)*SUBSP_DIM_L_MAX];
			//}
			ePeMatrix[jj+ii*SUBSP_DIM_L_MAX] = sum;
			ePeMatrix[jj+1 + ii*SUBSP_DIM_L_MAX] = sum1;
			ePeMatrix[jj + (ii + 1)*SUBSP_DIM_L_MAX] = sum2;
			ePeMatrix[(jj + 1) + (ii + 1)*SUBSP_DIM_L_MAX] = sum3;
		}
	}
#endif
}

int calcPhase(float *psiHatMatrix, int sigSpaceDim, float *omega_hat_sort){

	int ii, jj;
	//float omega_hat[SUBSP_DIM_L];
	float omega_hat[SUBSP_DIM_L_MAX];
	float tempStr;

	for(ii=0;ii<sigSpaceDim;ii++){
		omega_hat[ii] = -2*atanf(psiHatMatrix[ii]);
	}
	// sort
	for(ii=0;ii<sigSpaceDim;ii++){
		omega_hat_sort[ii] = (omega_hat[ii]>0)?omega_hat[ii]:(omega_hat[ii]+2*PI);
		for(jj=ii;jj>0;jj--){
			if(omega_hat_sort[jj]<omega_hat_sort[jj-1]){
				tempStr = omega_hat_sort[jj-1];
				omega_hat_sort[jj-1] = omega_hat_sort[jj];
				omega_hat_sort[jj] = tempStr;
			}
		}
	}
	// remove double eigen values (from complex conjugate pairs)
	jj = 0;
	for(ii=1;ii<sigSpaceDim;ii++){
		if(omega_hat_sort[ii]-omega_hat_sort[jj]>1e-2f){
			jj++;
			tempStr = omega_hat_sort[ii];
			omega_hat_sort[jj] = tempStr;
		}
	}
	sigSpaceDim -= (ii-1-jj);

	return sigSpaceDim;
}

void calcDelayAmplitude(hal_pktinfo_t *pktinfo,
						unsigned int *fftOutBuffer,
						unsigned int *totalpower,
						int firstPathDelay,
						int sigSpaceDim,
						float *omega_hat_sort,
						float *tau_hat,
						float *aMatrix,
						int fft_input_size)
{
	int ii, jj, kk, qq;
	int index;
	unsigned int *loadPtr;
	unsigned int tempLoad;
	short tempI, tempQ;
	float tempVal, scale, delta;
	float leftI, leftQ, rightI, rightQ;
	float leftSqr, rightSqr, valSqr;
	//float fracIndex[SUBSP_DIM_L];
	float fracIndex[SUBSP_DIM_L_MAX];

	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	int signalBandwidth = 20<<(pktinfo->sigBw);
	int stepsize = 1<<IFFT_OSF_SHIFT;

	int firstPathIndex = (firstPathDelay+(1<<(TOA_FPATH_BIPT-1)))>>TOA_FPATH_BIPT;
	int windowStart = firstPathIndex-(fft_input_size <<(IFFT_OSF_SHIFT-1)); // center window middle on first-path

	unsigned int bitMask = NUM_PARALLEL *ifftSizeOsf - 1;

	// map phase to delay
	for(kk=0;kk<sigSpaceDim;kk++){
		tempVal = omega_hat_sort[kk]/(2*PI);
		fracIndex[kk] = tempVal*(fft_input_size*stepsize);
		tempVal *= fft_input_size /(1.0f*signalBandwidth);
		//windowStart = (windowStart+2)&0xfffffffc;
		tempVal += windowStart /(1.0f*stepsize*signalBandwidth); // windowstat in oversampled samples
		tau_hat[kk] = tempVal;
	}

	// project delays onto time domain data to estimate path amplitude
	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj+= NUM_PARALLEL){
			for (qq = 0;qq < NUM_PARALLEL;qq++) {
				loadPtr = fftOutBuffer + (jj + ii*nRx)*ifftSizeOsf + qq;
				scale = SQRTF(1.0f*nTx*nRx*totalpower[(jj + qq) + ii*nRx] / (1 << 15)) / (1 << 8); // 32.31 format
				//scale = SQRTF(1.0f/fixedpower[jj+ii*nRx]/(1<<15))/(1<<8); // 32.31 format
				//scale = SQRTF(1.0f/fixedpower[jj+ii*nRx]/(1<<0))/(1<<3); // 32.31 format
				//scale = 1;
				for (kk = 0;kk < sigSpaceDim;kk++) {
					index = (int)floorf(fracIndex[kk]);
					delta = fracIndex[kk] - index;
					index += windowStart;

					// treatment for negative windowStart??
					// if(index<0) ...

					tempLoad = loadPtr[(NUM_PARALLEL*index) &bitMask];
					tempI = tempLoad & 0xffff;
					tempQ = (tempLoad >> 16) & 0xffff;
					leftI = tempI*scale;
					leftQ = tempQ*scale;
					leftSqr = leftI*leftI + leftQ*leftQ;

					tempLoad = loadPtr[(NUM_PARALLEL*(index + 1)) &bitMask];
					tempI = tempLoad & 0xffff;
					tempQ = (tempLoad >> 16) & 0xffff;
					rightI = tempI*scale;
					rightQ = tempQ*scale;
					rightSqr = rightI*rightI + rightQ*rightQ;

					valSqr = (rightSqr - leftSqr)*delta + leftSqr;

					aMatrix[kk + (jj + qq)*sigSpaceDim + ii*nRx*sigSpaceDim] = valSqr;
				}
			}
		}
	}
}

int determineFirstPath(hal_pktinfo_t *pktinfo,
					   float *tau_hat,
					   float *aMatrix,
					   int sigSpaceDim,
					   float music_thresh_rel)
{
	int ii, jj, kk;
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int firstPathIdx;
	int maxIdx = -1;
	int firstPathDelay = 0;

	float detThresh;
	float maxVal = 0;

	//float sumPower[SUBSP_DIM_L];
	float sumPower[SUBSP_DIM_L_MAX];

	int signalBandwidth = 20<<(pktinfo->sigBw);
	int stepsize = 1<<IFFT_OSF_SHIFT;

	for(kk=0;kk<sigSpaceDim;kk++){
		sumPower[kk]=0;
	}

	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj++){
			for(kk=0;kk<sigSpaceDim;kk++){
				sumPower[kk]+= aMatrix[kk +jj*sigSpaceDim +ii*nRx*sigSpaceDim];
			}
		}
	}

	// find max
	for(kk=0;kk<sigSpaceDim;kk++){
		sumPower[kk] /= (nTx*nRx);
		if(sumPower[kk]>maxVal){
			maxVal = sumPower[kk];
			maxIdx = kk;
		}
	}

	detThresh = maxVal*music_thresh_rel;
	if(detThresh>MUSIC_THRESH_MAX){
		detThresh=MUSIC_THRESH_MAX;
	}
	else if(detThresh<MUSIC_THRESH_MIN){
		detThresh=MUSIC_THRESH_MIN;
	}
	//detThresh = maxVal/4;
	firstPathIdx = maxIdx;
	for(kk=maxIdx-1;kk>=0;kk--){
		if(sumPower[kk]>detThresh){
			firstPathIdx = kk;
		}
	}
	firstPathDelay = (int) floorf((tau_hat[firstPathIdx]*signalBandwidth*stepsize*(1<<TOA_FPATH_BIPT))+0.5f);

	return firstPathDelay;
}

int calcSubspaceFineTiming(hal_pktinfo_t *pktinfo,		// structure with CSI buffer parameters
	unsigned int *fftOutBuffer,	// buffer holding time-domain CSI
	unsigned int *totalpower,	// array holding power per rx/tx channel
	int firstPathDelay,			// existing first path estimate
	int *fineTimingRes,			// result of algorithm
	unsigned int *procBuffer, 	// buffer for processing, size 2*BUFFER_OFFSET DW
	hal_wls_packet_params_t *packetparams // passing packetinfo
	)
{
	int nRx = pktinfo->nRx + 1;
	int nTx = pktinfo->nTx + 1;
	int subsp_dim_L = SUB_DIM_L_20;
	float sub_det_thresh, sub_det_thresh_rel, music_thresh_rel;
	int fft_input_size = FFT_INPUT_SIZE_LONG_WINDOW;
	float *realCorrMatrix = (float*)procBuffer; // realCorrMatrix[SUBSP_DIM_L*SUBSP_DIM_L]
	float *eigValPlusVec = (float*)procBuffer + BUFFER_OFFSET; // eigValPlusVec[MAX_MAT_SIZE+MAX_MAT_SIZE*MAX_MAT_SIZE]
	float *eMatrix = (float*)procBuffer; // eMatrix[2*SUBSP_DIM_L*SUBSP_DIM_L]
#ifdef USE_TLS
	float *ePeMatrix = (float*)procBuffer + BUFFER_OFFSET; //ePeMatrix[4*(SIG_SUBSP_DIM_MAX-2)*(SIG_SUBSP_DIM_MAX-2)]
	float *eigValPlusVecEE = (float*)procBuffer; // eigValPlusVec[MAX_MAT_SIZE+MAX_MAT_SIZE*MAX_MAT_SIZE]
	float *vMatrix = (float*)procBuffer + BUFFER_OFFSET; // vMatrix[4*(SUBSP_DIM_L-2)*(SUBSP_DIM_L-2)]
	float *qMatrix = (float*)procBuffer; // qMatrix[MAX_MAT_SIZE*MAX_MAT_SIZE]
	float *qPvMatrix = (float*)procBuffer + BUFFER_OFFSET / 2; // qPvMatrix[SUBSP_DIM_L*SUBSP_DIM_L]
	float *psiHatMatrix = (float*)procBuffer; // psiHatMatrix[SUBSP_DIM_L*SUBSP_DIM_L]
#else
	float *qMatrix = (float*) procBuffer+BUFFER_OFFSET; // qMatrix[MAX_MAT_SIZE*MAX_MAT_SIZE]
	float *qPeMatrix = (float*) procBuffer+BUFFER_OFFSET*3/2; // qPeMatrix[SUBSP_DIM_L*SUBSP_DIM_L]
	float *psiHatMatrix = (float*) procBuffer+BUFFER_OFFSET; // psiHatMatrix[SUBSP_DIM_L*SUBSP_DIM_L]
#endif
	float *eigPsiHat = (float*)procBuffer + BUFFER_OFFSET / 2; // eigPsiHat[SUBSP_DIM_L]
	float *omega_hat_sort = (float*)procBuffer; // omega_hat_sort[SUBSP_DIM_L]
	float *tau_hat = (float*)procBuffer + BUFFER_OFFSET / 4; // tau_hat[SUBSP_DIM_L]
	float *aMatrix = (float*)procBuffer + BUFFER_OFFSET / 2; // aMatrix[MAX_TX*MAX_RX*2*SUBSP_DIM_L]

	int numObs, sigSpaceDim, FD_downsample=1;

	if ((pktinfo->packetType == 0) && (pktinfo->sigBw == 0) && (pktinfo->rxDevBw == 2)) {         //process legacy pkt
		subsp_dim_L = SUB_DIM_L_6;
		sub_det_thresh = SUB_DET_THRESH_Legacy;
		sub_det_thresh_rel = SUB_DET_THRESH_REL_Legacy;
	}
	else if (packetparams->chNum >= 36) {  //5G band
		if (pktinfo->sigBw == 2) {
			sub_det_thresh = SUB_DET_THRESH_5G_80MHZ;
			sub_det_thresh_rel = SUB_DET_THRESH_REL_5G_80MHZ;
		}
		else if (pktinfo->sigBw == 1) {
			sub_det_thresh = SUB_DET_THRESH_5G_40MHZ;
			sub_det_thresh_rel = SUB_DET_THRESH_REL_5G_40MHZ;
		}
		else if (pktinfo->sigBw == 0) {
#if 0 //larger auto-correlation matrix size
			sub_det_thresh = SUB_DET_THRESH_5G_20MHZ;
			sub_det_thresh_rel = SUB_DET_THRESH_REL_5G_20MHZ;
#else
			fft_input_size = FFT_INPUT_SIZE_SHORT_WINDOW;
			subsp_dim_L = SUB_DIM_L_10;
			sub_det_thresh = SUB_DET_THRESH_5G_20MHZ;
			sub_det_thresh_rel = SUB_DET_THRESH_REL_5G_20MHZ;
#endif
		}
		else if (pktinfo->packetType < 2) {
			subsp_dim_L = SUB_DIM_L_16;
			fft_input_size = FFT_INPUT_SIZE_LONG_WINDOW;
			sub_det_thresh = SUB_DET_THRESH_20MHZ;
			sub_det_thresh_rel = SUB_DET_THRESH_REL_5G_20MHZ;
		}
		else {
			FD_downsample = 4;
			subsp_dim_L = SUB_DIM_L_10;
			sub_det_thresh = SUB_DET_THRESH_Legacy;
			sub_det_thresh_rel = 0.035f;
		}
	}
	else {								//2.4G band
		if (pktinfo->sigBw == 1) {
			subsp_dim_L = SUB_DIM_L_16;
		}
		else {
			subsp_dim_L = SUB_DIM_L_12;
		}
		sub_det_thresh = SUB_DET_THRESH_20MHZ;
		sub_det_thresh_rel = SUB_DET_THRESH_REL_2G;
		fft_input_size = FFT_INPUT_SIZE_LONG_WINDOW;
	}

	// determine firstpath power threshold according to frequency, and pass to "determineFirstPath"
	music_thresh_rel = (packetparams->chNum < 36) ? MUSIC_THRESH_REL_2GHz : MUSIC_THRESH_REL_5GHz;

	// in:	fftOutBuffer[], totalpower[]
	// out:	realCorrMatrix[SUBSP_DIM_L*SUBSP_DIM_L] {100 DW}
	calcCorMatrix(pktinfo, fftOutBuffer, totalpower, firstPathDelay, realCorrMatrix, procBuffer + BUFFER_OFFSET, subsp_dim_L, fft_input_size, FD_downsample, &numObs);
	//numObs = (fft_input_size - subsp_dim_L + 1) * 2 * nRx*nTx;
	sub_det_thresh *= (numObs * 2 * nRx*nTx); // account for CorMatrix scaling

	// eigen(Shur) decomposition
	// in:	realCorrMatrix[]
	// out:	eigValPlusVec[]; [D:MAX_MAT_SIZE (eigen values)| Q:SUBSP_DIM_L*SUBSP_DIM_L (eigen vectors)] {10+100 DW +30DW scratch}
	QR_algorithm(realCorrMatrix, eigValPlusVec, subsp_dim_L, 0);

	// find signal space Eig Vals and construct E matrix for ESPRIT
	// in:	eigValPlusVec[] - used also as scratch memory
	// out:	eMatrix[]; [E_lower: (SUBSP_DIM_L-1)*SIG_SUBSP_DIM_MAX| E_upper: (SUBSP_DIM_L-1)*SIG_SUBSP_DIM_MAX] {200 DW}
	sigSpaceDim = findSigSpace(eigValPlusVec, eMatrix, sub_det_thresh, subsp_dim_L, pktinfo, sub_det_thresh_rel);

	if (sigSpaceDim < 2){
		if (sigSpaceDim == 0){ // error, no signal over threshold
			return -1;
		}
		//else{ // (sigSpaceDim == 1)
		//	// for single eigen value, use simpler code
		//	// in: eMatrix[]
		//	// out: omega_hat_sort[]
		//	calcDimOnePhase(eMatrix, omega_hat_sort, SUBSP_DIM_L);

		//	// determine delays and amplitudes
		//	// in : fftOutBuffer[], totalpower[], omega_hat_sort[]
		//	// out: tau_hat[], aMatrix[]  {10+80 DW}
		//	calcDelayAmplitude(pktinfo, fftOutBuffer, totalpower, firstPathDelay, sigSpaceDim, omega_hat_sort, tau_hat, aMatrix);

		//	// determine first path
		//	// in: tau_hat[], aMatrix[]
		//	// out: fineTimingRes
		//	*fineTimingRes = determineFirstPath(pktinfo, tau_hat, aMatrix, sigSpaceDim);

		//	return 0;
		//}
	}
#ifdef USE_TLS // QR of E
	// calc E'*E
	// in: eMatrix[]
	// out: ePeMatrix[] {256 DW}
	calcEtimesE(eMatrix, ePeMatrix,(subsp_dim_L -1), 2*sigSpaceDim);
	// eigen(Shur) decomposition
	// in:	ePeMatrix[]
	// out:	eigValPlusVec[]; [D:2*SIG_SUBSP_DIM_MAX (eigen values)| Q:4*SIG_SUBSP_DIM_MAX^2 (eigen vectors)] {12+144 DW +30DW scratch}
	QR_algorithm(ePeMatrix, eigValPlusVecEE, 2*sigSpaceDim, 1);

	// in: eigValPlusVec[]
	// out: vMatrix[]; [V_upper: SIG_SUBSP_DIM_MAX*SIG_SUBSP_DIM_MAX| V_lower: SIG_SUBSP_DIM_MAX*SIG_SUBSP_DIM_MAX] {256 DW}
	constructVmatrix(eigValPlusVecEE, vMatrix, sigSpaceDim, 2*sigSpaceDim);

	//  Psi_hat = V_lower\V_upper;
	// V_lower = Q*R
	// in: vMatrix[] V_lower (updated)
	// out: qMatrix[SIG_SUBSP_DIM_MAX*SIG_SUBSP_DIM_MAX] {100 DW }
	QR_decomposition(vMatrix+sigSpaceDim*SUBSP_DIM_L_MAX, qMatrix, sigSpaceDim, sigSpaceDim);
	// calc Q'*V_upper
	// in: vMatrix[] V_upper, qMatrix[]
	// out: qPvMatrix[] {100 DW +30 DW scratch}
	calc_QpTimesE(vMatrix, qMatrix, qPvMatrix, sigSpaceDim, sigSpaceDim);
	// Psi_hat = (R^-1)(Q'*E_upper) solve with back substitution
	// in: qPvMatrix[], vMatrix[] V_lower (updated)
	// out: Psi_hat[]: (sigSpaceDim*sigSpaceDim) {100 DW}
	myBackSub(qPvMatrix, vMatrix+sigSpaceDim*SUBSP_DIM_L_MAX, psiHatMatrix, sigSpaceDim, sigSpaceDim);

#else
	// LS Psi_hat = E_lower\E_upper;
	// E_lower = Q*R
	// in: eMatrix[] E_lower (updated)
	// out: qMatrix[] {100 DW}
	QR_decomposition(eMatrix, qMatrix, (subsp_dim_L -1), sigSpaceDim);
	// calc Q'*E_upper
	// in: eMatrix[] E_upper, qMatrix[]
	// out: qPeMatrix[] {100 DW}
	calc_QpTimesE(eMatrix+ SUBSP_DIM_L_MAX*sigSpaceDim, qMatrix, qPeMatrix, (subsp_dim_L -1), sigSpaceDim);
	// Psi_hat = (R^-1)(Q'*E_upper) solve with back substitution
	// in: qPeMatrix[], eMatrix[] E_lower (updated)
	// out: Psi_hat[]: (sigSpaceDim*sigSpaceDim) {100 DW}
	myBackSub(qPeMatrix, eMatrix, psiHatMatrix, (subsp_dim_L -1), sigSpaceDim);

#endif
	// omega_hat = atan(real(eig(Psi_hat)))
	// in: psiHatMatrix[]
	// out: eigPsiHat[]  {10 DW  +30 DW scratch}
	unsym_QR_algorithm(psiHatMatrix, eigPsiHat, sigSpaceDim);

	// determine phase
	// in: eigPsiHat[], sigSpaceDim
	// out: omega_hat_sort[], sigSpaceDim  {10 DW}
	sigSpaceDim = calcPhase(eigPsiHat, sigSpaceDim, omega_hat_sort);

	// determine delays and amplitudes
	// in : fftOutBuffer[], totalpower[], omega_hat_sort[]
	// out: tau_hat[], aMatrix[]  {10+80 DW}
	calcDelayAmplitude(pktinfo, fftOutBuffer, totalpower, firstPathDelay, sigSpaceDim, omega_hat_sort, tau_hat, aMatrix, fft_input_size);

	// determine first path
	// in: tau_hat[], aMatrix[]
	// out: fineTimingRes
	*fineTimingRes = determineFirstPath(pktinfo, tau_hat, aMatrix, sigSpaceDim, music_thresh_rel);

	return 0;
}
#endif /* CONFIG_WLS_CSI_PROC */
