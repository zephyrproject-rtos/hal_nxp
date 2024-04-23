/* @file wmcrypto_mem.c
 *
 *  @brief This file provides crypto  memory routines
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <wm_os.h>

#include "wmcrypto.h"
#include "wmcrypto_mem.h"

void *crypto_mem_malloc(size_t size)
{
    if (size == 0)
        return NULL;

    void *buffer_ptr = os_mem_alloc(size);
    if (!buffer_ptr)
    {
        crypto_e("Failed to allocate mem: Size: %d", size);
        return NULL;
    }

    return buffer_ptr;
}

void crypto_mem_free(void *buffer)
{
    os_mem_free(buffer);
}

void *crypto_mem_calloc(size_t nmemb, size_t size)
{
    return crypto_mem_malloc(nmemb * size);
}
