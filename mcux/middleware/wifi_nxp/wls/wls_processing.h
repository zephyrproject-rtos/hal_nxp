#if CONFIG_WLS_CSI_PROC
/** @file wls_processing.h
 *
 * @brief This file contains header file for CSI processing functions
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * DFW header file for CSI processing functions
 ************************************************************************/

#ifdef DFW_CSI_PROC
#include "dsp_cmd.h"
#endif
#include "wls_structure_defs.h"

#ifndef WLS_PROCESSING_H
#define WLS_PROCESSING_H

int myAtan2(int valI, int valQ);

int myAsin(int x);

unsigned int mySqrt(int x);

unsigned int mySqrtLut(int x);

void readHexDataDemodulateProcess(hal_pktinfo_t *pktinfo,
                                  hal_wls_processing_input_params_t *inputVals,
                                  unsigned int *dataPtr,
                                  int csiDataSize,
                                  unsigned int *fftInBuffer,
                                  unsigned int *powerPerSubband,
                                  int *phaseRollPtr,
                                  int chNum);
void readHexDataDemodulateProcessParallel(hal_pktinfo_t *pktinfo,
                                          hal_wls_processing_input_params_t *inputVals,
                                          unsigned int *dataPtr,
                                          int csiDataSize,
                                          unsigned int *fftInBfr,
                                          unsigned int *powerPerSubband,
                                          int *phaseRollPtr,
                                          int chNum);

void readHexDataDemodulateProcessVhtHeNg1(hal_pktinfo_t *pktinfo,
                                          hal_wls_processing_input_params_t *inputVals,
                                          unsigned int *dataPtr,
                                          int csiDataSize,
                                          unsigned int *fftInBuffer,
                                          unsigned int *powerPerSubband,
                                          int *phaseRollPtr,
                                          int chNum);
void readHexDataDemodulateProcessVhtHeNg1Parallel(hal_pktinfo_t *pktinfo,
                                                  hal_wls_processing_input_params_t *inputVals,
                                                  unsigned int *dataPtr,
                                                  int csiDataSize,
                                                  unsigned int *fftInBuffer,
                                                  unsigned int *powerPerSubband,
                                                  int *phaseRollPtr,
                                                  int chNum);

void detectPhaseJump(hal_pktinfo_t *pktinfo,
                     hal_wls_processing_input_params_t *inputVals,
                     unsigned int *fftInBfr,
                     int *phaseRollPtr);

void calculateTotalPower(hal_pktinfo_t *pktinfo, unsigned int *powerPerSubband, unsigned int *totalpower);

void processLegacyPackets(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int bufferspacing, int *phaseRollPtr);

void interpolatePilots(
    hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int bufferspacing, int *phaseRollPtr, unsigned int *totalpower);
void interpolatePilotsParallel(
    hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int bufferspacing, int *phaseRollPtr, unsigned int *totalpower);

void ifftProcessing(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, unsigned int *fftOutBuffer, int bufferspacing);

void interpolateBandEdges20(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int phaseRollNg);
void interpolateBandEdges20Parallel(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int *phaseRollPtr);

void interpolateBandEdges40(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int phaseRollNg);
void interpolateBandEdges40Parallel(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int *phaseRollPtr);

void interpolateBandEdges(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int phaseRollNg);
void interpolateBandEdgesParallel(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int *phaseRollPtr);

void interpolatePairValue(unsigned int *valLeft, unsigned int *valRight, int phaseRollNg);
void interpolatePairValueParallel(unsigned int *valLeft, unsigned int *valRight, int *phaseRollPtr);

void findActiveSubbands(
    hal_pktinfo_t *pktinfo, unsigned int *powerPerSubband, unsigned int *totalpower, int chNum, int ftmSignalBW);

void zeroOutTones(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int bufferspacing);

void removeToneRotation(hal_pktinfo_t *pktinfo, unsigned int *fftInBfr, int bufferspacing);
void removeToneRotationParallel(hal_pktinfo_t *pktinfo, unsigned int *fftInBfr, int bufferspacing);

void calcPdpAndFirstPathMin(hal_pktinfo_t *pktinfo,
                            unsigned int *fftOutBuffer,
                            unsigned int *pdpOutBuffer,
                            unsigned int *totalpower,
                            int *idxRes,
                            unsigned int *valRes,
                            int *firstPathDelay);

void calcPdpAndMax(hal_pktinfo_t *pktinfo,
                   unsigned int *fftOutBuffer,
                   unsigned int *pdpOutBuffer,
                   unsigned int *totalpower,
                   int *idxRes,
                   unsigned int *valRes);
void calcPdpAndMaxParallel(hal_pktinfo_t *pktinfo,
                           unsigned int *fftOutBuffer,
                           unsigned int *pdpOutBuffer,
                           unsigned int *totalpower,
                           int *idxRes,
                           unsigned int *valRes);

int findFirstPath(hal_pktinfo_t *pktinfo, unsigned int *pdpOutBuffer, int maxIdx, unsigned int maxVal, int stride);

void dumpRawComplex(hal_pktinfo_t *pktinfo, unsigned int *fftBuffer, int peakIdx, unsigned int *destArray);

#endif

#endif /* CONFIG_WLS_CSI_PROC */
