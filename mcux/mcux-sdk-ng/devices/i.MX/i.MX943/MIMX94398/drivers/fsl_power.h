/*
 * Copyright 2024,2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_POWER_H
#define FSL_POWER_H

/*!
 * @addtogroup PWR_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_common.h"

#define POWER_NUM_MIX_SLICE               19U

#define POWER_MIX_SLICE_IDX_ANA           0U
#define POWER_MIX_SLICE_IDX_AON           1U
#define POWER_MIX_SLICE_IDX_BBSM          2U
#define POWER_MIX_SLICE_IDX_M7_1          3U
#define POWER_MIX_SLICE_IDX_CCMSRCGPC     4U
#define POWER_MIX_SLICE_IDX_A55C0         5U
#define POWER_MIX_SLICE_IDX_A55C1         6U
#define POWER_MIX_SLICE_IDX_A55C2         7U
#define POWER_MIX_SLICE_IDX_A55C3         8U
#define POWER_MIX_SLICE_IDX_A55P          9U
#define POWER_MIX_SLICE_IDX_DDR           10U
#define POWER_MIX_SLICE_IDX_DISPLAY       11U
#define POWER_MIX_SLICE_IDX_M7_0          12U
#define POWER_MIX_SLICE_IDX_HSIO_TOP      13U
#define POWER_MIX_SLICE_IDX_HSIO_WAON     14U
#define POWER_MIX_SLICE_IDX_NETC          15U
#define POWER_MIX_SLICE_IDX_NOC           16U
#define POWER_MIX_SLICE_IDX_NPU           17U
#define POWER_MIX_SLICE_IDX_WAKEUP        18U

#define POWER_MEM_SLICE_IDX_AON           0U
#define POWER_MEM_SLICE_IDX_M7_1          1U
#define POWER_MEM_SLICE_IDX_A55C0         2U
#define POWER_MEM_SLICE_IDX_A55C1         3U
#define POWER_MEM_SLICE_IDX_A55C2         4U
#define POWER_MEM_SLICE_IDX_A55C3         5U
#define POWER_MEM_SLICE_IDX_A55P          6U
#define POWER_MEM_SLICE_IDX_A55L3         7U
#define POWER_MEM_SLICE_IDX_DDR           8U
#define POWER_MEM_SLICE_IDX_DISPLAY       9U
#define POWER_MEM_SLICE_IDX_M7_0          10U
#define POWER_MEM_SLICE_IDX_HSIO          11U
#define POWER_MEM_SLICE_IDX_NETC          12U
#define POWER_MEM_SLICE_IDX_NOC1          13U
#define POWER_MEM_SLICE_IDX_NOC2          14U
#define POWER_MEM_SLICE_IDX_NPU           15U
#define POWER_MEM_SLICE_IDX_WAKEUP        16U

#define POWER_MIX_SLICE_IDX_A55C_LAST     POWER_MIX_SLICE_IDX_A55C3

typedef struct _pwr_s
{
    uint32_t did;
    uint32_t st;
} pwr_s_t;

int32_t POWER_SetState(pwr_s_t *pwr_st);
uint32_t POWER_GetState(pwr_s_t *pwr_st);

#endif /* FSL_POWER_H */

/** @} */
