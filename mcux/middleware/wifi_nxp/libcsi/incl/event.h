/*
 *  Copyright 2025 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*! \file event.h
 * \brief This file provides essential macro definitions and data structures for processing CSI event data.
 */

#ifndef _LIB_CSI_EVENT_H_
#define _LIB_CSI_EVENT_H_

#include    <ctype.h>
#include    <stdlib.h>
#include    "wls_structure_defs.h"

#define PI_ALPHA_FACTOR 0.1f
#define KALMAN_N0  0.2f
#define KALMAN_P0 0.5f
#define KALMAN_ALPHA 0.005f

typedef enum {
    AMI_FILTER_NOT_SET = 0,     // Filter not set
    AMI_FILTER_SET,             // Filter manually set via configuration
    AMI_FILTER_AUTO_SET,        // Filter auto set from the first packet
} ami_filter_set_status_t;

typedef enum {
	AMI_REF_UNINIT = 0,        // AMI reference not initialized
	AMI_REF_INITIALIZED        // AMI reference initialized
} ami_reference_status_t;

typedef enum {
    AMI_STOP = 0,   // AMI calculation stopped
    AMI_START       // AMI calculation started
} ami_start_status_t;

/** Structure for CSI config data*/
typedef struct wls_csi_cfg
 {
	 /** Channel number for FTM session*/
	 t_u8 channel;
	 /** Indicate whether CSI filter has been set */
	 ami_filter_set_status_t csiFilterSet;
     /** Indicate whether start to caculate Ambient Motion Index.
     * AMI_STOP - stop. AMI_START - start */
	 ami_start_status_t start;
	 /** Indicates whether AMI reference has been initialized  */
	 ami_reference_status_t ami_reference_init;
	 /**CSI processing config*/
	 hal_wls_processing_input_params_t wls_processing_input;
	 /**CSI filter parameters*/
	 csi_filter_param_t gcsi_filter_param;
 } wls_csi_cfg_t, ami_cfg_t;

#endif /* _LIB_CSI_EVENT_H */