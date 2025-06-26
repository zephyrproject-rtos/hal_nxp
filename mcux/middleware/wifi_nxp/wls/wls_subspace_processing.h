#if CONFIG_WLS_CSI_PROC
/** @file  wls_subspace_processing.h
 *
 * @brief This file contains header file for sub-space based fine timing calculation
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * Header file for sub-space based fine timing calculation
 ************************************************************************/

#ifndef WLS_SUBSPACE_PROCESSING
#define WLS_SUBSPACE_PROCESSING

#include "wls_structure_defs.h"

int calcSubspaceFineTiming(hal_pktinfo_t *pktinfo,               // structure with CSI buffer parameters
                           unsigned int *fftOutBuffer,           // buffer holding time-domain CSI
                           unsigned int *totalpower,             // array holding power per rx/tx channel
                           int firstPathDelay,                   // existing first path estimate
                           int *fineTimingRes,                   // result of algorithm
                           unsigned int *procBuffer,             // buffer for processing - needs about 2k bytes
                           hal_wls_packet_params_t *packetparams // passing packetinfo to determin 2.4/5G
);

#endif

#endif /* CONFIG_WLS_CSI_PROC */
