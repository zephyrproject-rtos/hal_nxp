#if CONFIG_WLS_CSI_PROC
/** @file wls_api.h
 *
 * @brief This file contains header file for WLS processing fixed-point version API
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * Header file for WLS processing fixed-point version API
 ************************************************************************/
#ifndef WLS_API_H
#define WLS_API_H

#include "wls_structure_defs.h"
#ifdef DFW_CSI_PROC
#include "dsp_cmd.h"
#endif

int wls_process_csi(unsigned int *bufferMemory,
                    unsigned int *fftInBuffer,
                    hal_wls_packet_params_t *packetparams,
                    hal_wls_processing_input_params_t *inputVals,
                    unsigned int *resArray);

#endif

#endif /* CONFIG_WLS_CSI_PROC */
