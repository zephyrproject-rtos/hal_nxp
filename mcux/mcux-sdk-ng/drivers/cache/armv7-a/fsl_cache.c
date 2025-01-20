/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_cache.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.cache_armv7_a"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Invalidates instruction cache by range.
 *
 * Cortex-a L1 instruction cache line length is 32-byte.
 *
 * param address The physical address.
 * param size_byte size of the memory to be invalidated.
 * note Address and size should be aligned to cache line size
 *  32-Byte due to the cache operation unit is one cache line. The startAddr here will be forced
 * to align to the cache line size if startAddr is not aligned. For the size_byte, application should
 * make sure the alignment or make sure the right operation order if the size_byte is not aligned.
 */
void ICACHE_InvalidateByRange(uint32_t address, uint32_t size_byte)
{
    L1CACHE_InvalidateICacheByRange(address, size_byte);
}

/*!
 * brief Invalidates data cache by range.
 *
 * Cortex-a L1 data cache line length is 64-byte.
 *
 * param address The physical address.
 * param size_byte size of the memory to be invalidated.
 * note Address and size should be aligned to cache line size
 *  64-byte due to the cache operation unit is one cache line. The startAddr here will be forced
 * to align to the cache line size if startAddr is not aligned. For the size_byte, application should
 * make sure the alignment or make sure the right operation order if the size_byte is not aligned.
 */
void DCACHE_InvalidateByRange(uint32_t address, uint32_t size_byte)
{
    L1CACHE_InvalidateDCacheByRange(address, size_byte);
}

/*!
 * brief Cleans data cache by range.
 *
 * Cortex-a L1 data cache line length is 64-byte.
 *
 * param address The physical address.
 * param size_byte size of the memory to be cleaned.
 * note Address and size should be aligned to cache line size
 *  64-byte due to the cache operation unit is one cache line. The startAddr here will be forced
 * to align to the cache line size if startAddr is not aligned. For the size_byte, application should
 * make sure the alignment or make sure the right operation order if the size_byte is not aligned.
 */
void DCACHE_CleanByRange(uint32_t address, uint32_t size_byte)
{
    L1CACHE_CleanDCacheByRange(address, size_byte);
}

/*!
 * brief Cleans and Invalidates data cache by range.
 *
 * Cortex-a L1 data cache line length is 64-byte.
 *
 * param address The physical address.
 * param size_byte size of the memory to be cleaned and invalidated.
 * note Address and size should be aligned to cache line size
 *  64-byte due to the cache operation unit is one cache line. The startAddr here will be forced
 * to align to the cache line size if startAddr is not aligned. For the size_byte, application should
 * make sure the alignment or make sure the right operation order if the size_byte is not aligned.
 */
void DCACHE_CleanInvalidateByRange(uint32_t address, uint32_t size_byte)
{
    L1CACHE_CleanInvalidateDCacheByRange(address, size_byte);
}
