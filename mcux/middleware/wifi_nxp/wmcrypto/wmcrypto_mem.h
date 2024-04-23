/* @file wmcrypto_mem.h
 *
 *  @brief This file provides crypto  memory routine interface
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <wmtypes.h>

/** Malloc memory
 */
void *crypto_mem_malloc(size_t size);

/** Free previously allocated memory
 */
void crypto_mem_free(void *ptr);

/** Calloc memory
 */
void *crypto_mem_calloc(size_t nmemb, size_t size);
