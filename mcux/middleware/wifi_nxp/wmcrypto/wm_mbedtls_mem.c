/** @file wm_mbedtls_mem.c
 *
 *  @brief This file provides wrappers for dynamic memory management functions
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "wm_mbedtls_mem.h"

#include <mbedtls/platform.h>

#include <osa.h>

static void *wmos_wrap_calloc(size_t block_count, size_t block_size)
{
    return OSA_MemoryAllocate(block_count * block_size);
}

static void wmos_wrap_free(void *ptr)
{
    OSA_MemoryFree(ptr);
}

int wm_mbedtls_set_mem_alloc()
{
    return mbedtls_platform_set_calloc_free(wmos_wrap_calloc, wmos_wrap_free);
}
