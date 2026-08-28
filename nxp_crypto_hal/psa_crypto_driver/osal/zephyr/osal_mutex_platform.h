/*
 * Copyright 2023 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef OSAL_MUTEX_PLATFORM_H
#define OSAL_MUTEX_PLATFORM_H

#if defined(PSA_CRYPTO_DRIVER_THREAD_EN)
/** \file osal_mutex_platform.h
 *
 * This file contains the definition for mcux_mutex_t
 *
 */

#include <zephyr/kernel.h>

typedef struct k_mutex mcux_mutex_t;
#endif /* PSA_CRYPTO_DRIVER_THREAD_EN */
#endif /* OSAL_MUTEX_PLATFORM_H */
