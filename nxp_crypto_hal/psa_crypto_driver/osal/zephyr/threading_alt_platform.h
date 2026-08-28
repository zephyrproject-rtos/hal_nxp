/*
 * Copyright 2024-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*!
 * @file threading_alt_platform.h
 * @brief Zephyr-specific mutex declarations for MbedTLS threading_alt.
 */

#ifndef __THREADING_ALT_PLATFORM_H__
#define __THREADING_ALT_PLATFORM_H__

#include <zephyr/kernel.h>
#include <zephyr/kernel/thread.h>

/**
 * @brief Mutex struct used to synchronize mbed TLS operations.
 *
 */
typedef struct
{
    struct k_mutex mutex; /**< Zephyr kernel mutex. */
    char is_valid; /**< Flag used by mbedTLS to track wether a mutex is valid. */
} mbedtls_threading_mutex_t;

#endif /* ifndef __THREADING_ALT_PLATFORM_H__ */
