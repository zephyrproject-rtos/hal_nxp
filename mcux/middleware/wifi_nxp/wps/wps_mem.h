/** @file wps_mem.h
 *
 *  @brief WPS Mempru Allocators
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

void *wps_mem_malloc(int size);

void *wps_mem_calloc(size_t nmemb, size_t size);

void *wps_mem_realloc(void *ptr, size_t size);

/** Duplicate the string
 */
char *wps_mem_strdup(char *s);

void wps_mem_free(void *ptr);
