/*! *********************************************************************************
 * Copyright 2019 -2020, 2022 NXP
 * All rights reserved.
 *
 * \file
 *
 * This is the internal header file for the Memory Manager.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */

#ifndef MEM_MANAGER_INTERNAL_H
#define MEM_MANAGER_INTERNAL_H

/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */

#include "fsl_common.h"

#if defined(__IAR_SYSTEMS_ICC__)
#include "iccarm_builtin.h"
#endif /* (__IAR_SYSTEMS_ICC__) */

/*! *********************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
********************************************************************************** */

#ifdef MEM_MANAGER_BENCH

/* if benchmarking is activated, statistics are needed */
#ifndef MEM_STATISTICS_INTERNAL
#define MEM_STATISTICS_INTERNAL
#endif

#ifndef MEM_STATISTICS
#define MEM_STATISTICS
#endif
#undef MEM_MANAGER_ENABLE_TRACE
#define MEM_MANAGER_ENABLE_TRACE 1U

#if TM_ENABLE_TIME_STAMP == 0
#error "TM_ENABLE_TIME_STAMP is required for MEM_MANAGER_BENCH"
#endif

#endif /* MEM_MANAGER_BENCH */

#ifdef MEM_STATISTICS_INTERNAL
/* if internal statistics are enabled, default statistics are needed */
#define MEM_STATISTICS
#endif

#ifdef MEM_STATISTICS

#if !defined(gMemManagerLight) || (gMemManagerLight == 0)

/* if using legacy mem manager, MEM_TRACKING is needed */
#ifndef MEM_TRACKING
#define MEM_TRACKING
#endif

#endif /* gMemManagerLight */

#endif /* MEM_STATISTICS */

#ifdef MEM_STATISTICS_INTERNAL

#define UPDATE_PEAK(__current, __old) \
    if ((__current) > (__old))        \
    {                                 \
        (__old) = (__current);        \
    }                                 \
    else                              \
    {                                 \
        ;                             \
    }
#define SMALL_BUFFER_SIZE  50U
#define LARGE_BUFFER_SIZE  150U
#define MAX_SUPPORTED_POOL 3U

#ifndef NB_ALLOC_REPORT_THRESHOLD
#define NB_ALLOC_REPORT_THRESHOLD 0xFFFFFFFFU
#endif

#endif /* MEM_STATISTICS_INTERNAL */

/*! *********************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
********************************************************************************** */

#ifdef MEM_STATISTICS_INTERNAL

/* Generic statistics used for both Legacy and Light Mem Managers */
typedef struct mem_statis_s
{
    uint32_t nb_alloc;
    uint32_t peak_upper_addr;
#ifdef MEM_MANAGER_BENCH
    uint32_t total_alloc_time;
    uint16_t average_alloc_time;
    uint16_t peak_alloc_time;
    uint16_t last_alloc_time;
    uint16_t last_alloc_block_size;
    uint16_t last_alloc_buff_size;
#endif /* MEM_MANAGER_BENCH */
    uint16_t ram_lost_per_pool[MAX_SUPPORTED_POOL];
    uint16_t ram_lost;
    uint16_t peak_ram_lost;
    uint16_t nb_small_buffer;
    uint16_t peak_small_buffer;
    uint16_t nb_medium_buffer;
    uint16_t peak_medium_buffer;
    uint16_t nb_large_buffer;
    uint16_t peak_large_buffer;
    uint16_t ram_allocated;
    uint16_t peak_ram_allocated;
} mem_statis_t;

#endif /* MEM_STATISTICS_INTERNAL */

/*! *********************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************
********************************************************************************** */

#endif /* MEM_MANAGER_INTERNAL_H */
